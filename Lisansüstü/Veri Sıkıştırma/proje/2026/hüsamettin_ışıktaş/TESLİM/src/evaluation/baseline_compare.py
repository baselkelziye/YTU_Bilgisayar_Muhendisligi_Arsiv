"""Baseline comparison against standard compressors (gzip, bzip2, lzma, zlib).

Computes per-profile metrics for each baseline and compares against the
winner algorithm selected by the grid search.
"""

from __future__ import annotations

import bz2
import gzip
import lzma
import logging
import time
import zlib
from pathlib import Path
from typing import Any

import numpy as np
import pandas as pd
from tqdm import tqdm

logger = logging.getLogger(__name__)


def _compress_baseline(data: bytes, codec: str) -> dict[str, float]:
    """Compress *data* with a standard library codec and return metrics.

    Parameters
    ----------
    data : bytes
        Raw input.
    codec : {"gzip", "bz2", "lzma", "zlib"}
        Compressor name.

    Returns
    -------
    dict with keys: compressed_size_bits, bpb, compression_ratio, elapsed_ms, ms_per_kb
    """
    start = time.perf_counter()
    original_size = len(data)

    try:
        if codec == "gzip":
            compressed = gzip.compress(data)
        elif codec == "bz2":
            compressed = bz2.compress(data)
        elif codec == "lzma":
            compressed = lzma.compress(data)
        elif codec == "zlib":
            compressed = zlib.compress(data)
        else:
            raise ValueError(f"Unknown baseline codec: {codec}")
    except Exception as exc:
        logger.warning("Baseline %s failed: %s", codec, exc)
        return {
            "compressed_size_bits": 0,
            "bpb": float("nan"),
            "compression_ratio": float("nan"),
            "elapsed_ms": (time.perf_counter() - start) * 1000,
            "ms_per_kb": float("nan"),
            "valid": False,
        }

    elapsed = (time.perf_counter() - start) * 1000
    compressed_size_bits = len(compressed) * 8
    bpb = compressed_size_bits / original_size if original_size > 0 else 0.0

    return {
        "compressed_size_bits": compressed_size_bits,
        "bpb": bpb,
        "compression_ratio": compressed_size_bits / 8 / original_size if original_size > 0 else 1.0,
        "elapsed_ms": elapsed,
        "ms_per_kb": elapsed / (original_size / 1024) if original_size > 0 else 0.0,
        "valid": True,
    }


def compute_baseline_metrics(
    grid_results: pd.DataFrame,
    filtered_dataset_path: Path,
    baseline_codecs: list[str] | None = None,
    max_chunks_per_profile: int = 300,
    sample_seed: int = 42,
) -> pd.DataFrame:
    """Compute baseline metrics per profile and compare with winner algorithm.

    Parameters
    ----------
    grid_results : pd.DataFrame
        Grid search results (needs profile_id, chunk_id, algorithm_id,
        parameter_set_id, bpb columns).
    filtered_dataset_path : Path
        Path to ``filtered_dataset.parquet`` from Phase 1.
    baseline_codecs : list[str] or None
        Which baselines to run. Default: ["gzip", "bz2", "lzma", "zlib"].
    max_chunks_per_profile : int
        Limit chunks per profile.
    sample_seed : int
        RNG seed.

    Returns
    -------
    pd.DataFrame
        One row per profile with columns:
        profile_id, winner_algorithm_id, winner_parameter_set_id, winner_mean_bpb,
        {baseline}_mean_bpb, improve_vs_{baseline}_pct
    """
    if baseline_codecs is None:
        baseline_codecs = ["gzip", "bz2", "lzma", "zlib"]

    # Load filtered dataset for chunk text
    df = pd.read_parquet(filtered_dataset_path)

    text_col = None
    for candidate in ["text", "chunk_text", "content"]:
        if candidate in df.columns:
            text_col = candidate
            break
    project_root = filtered_dataset_path.resolve().parents[2]
    books_dir = project_root / "data" / "processed" / "books"
    book_cache: dict[str, str] = {}

    def _get_chunk_text(row: pd.Series) -> str:
        nonlocal text_col
        if text_col is not None:
            return str(row[text_col])
        book_id = str(row["book_id"])
        chunk_index = int(row["chunk_index"])
        chunk_size = int(row.get("chunk_size_chars", 0) or 0)
        if chunk_size <= 0:
            chunk_size = 10240

        if book_id not in book_cache:
            book_path = books_dir / f"{book_id}.txt"
            if not book_path.exists():
                raise FileNotFoundError(f"Missing processed book: {book_path}")
            book_cache[book_id] = book_path.read_text(encoding="utf-8")

        text = book_cache[book_id]
        start = chunk_index * chunk_size
        end = start + chunk_size
        return text[start:end]

    # Get winner per profile from grid results
    valid_results = grid_results[grid_results["valid"] == True].copy()  # noqa: E712
    if valid_results.empty:
        raise ValueError("No valid results in grid search output")

    winners = (
        valid_results.groupby(["profile_id", "algorithm_id", "parameter_set_id"])
        .agg(mean_bpb=("bpb", "mean"), n_samples=("bpb", "count"))
        .reset_index()
        .sort_values(["profile_id", "mean_bpb"])
        .groupby("profile_id")
        .first()
        .reset_index()
    )

    # Sample chunks per profile
    rng = np.random.default_rng(sample_seed)
    profile_groups = df.groupby("profile_id")

    rows: list[dict[str, Any]] = []
    pbar = tqdm(total=len(winners), desc="Baseline comparison", unit="profile")
    for _, winner in winners.iterrows():
        profile_id = winner["profile_id"]
        group = profile_groups.get_group(profile_id)
        if text_col is not None:
            group = group.dropna(subset=[text_col])

        if len(group) > max_chunks_per_profile:
            indices = rng.choice(len(group), size=max_chunks_per_profile, replace=False)
            group = group.iloc[indices]

        # Compute baseline metrics for each chunk
        baseline_bpbs: dict[str, list[float]] = {bc: [] for bc in baseline_codecs}

        for _, row in group.iterrows():
            chunk_text = _get_chunk_text(row)
            if not chunk_text or not str(chunk_text).strip():
                continue
            chunk_bytes = chunk_text.encode("utf-8")
            for bc in baseline_codecs:
                result = _compress_baseline(chunk_bytes, bc)
                if result["valid"]:
                    baseline_bpbs[bc].append(result["bpb"])

        row_data: dict[str, Any] = {
            "profile_id": profile_id,
            "winner_algorithm_id": winner["algorithm_id"],
            "winner_parameter_set_id": winner["parameter_set_id"],
            "winner_mean_bpb": winner["mean_bpb"],
        }

        for bc in baseline_codecs:
            vals = baseline_bpbs[bc]
            mean_bpb = sum(vals) / len(vals) if vals else float("nan")
            row_data[f"{bc}_mean_bpb"] = mean_bpb

            # Improvement percentage
            winner_bpb = winner["mean_bpb"]
            if mean_bpb and mean_bpb > 0 and not pd.isna(mean_bpb):
                improvement = ((mean_bpb - winner_bpb) / mean_bpb) * 100
                row_data[f"improve_vs_{bc}_pct"] = improvement
            else:
                row_data[f"improve_vs_{bc}_pct"] = float("nan")

        rows.append(row_data)
        pbar.update(1)
    pbar.close()
    result_df = pd.DataFrame(rows)
    logger.info(
        "Baseline comparison complete: %d profiles x %d baselines",
        len(result_df),
        len(baseline_codecs),
    )
    return result_df


def write_baseline_comparison(
    comparison_df: pd.DataFrame,
    output_path: Path,
) -> None:
    """Write baseline comparison CSV."""
    output_path.parent.mkdir(parents=True, exist_ok=True)
    comparison_df.to_csv(output_path, index=False)
    logger.info("Baseline comparison written to %s", output_path)
