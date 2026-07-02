"""Profile-based grid search orchestration for Phase 2.

Loads the filtered dataset from Phase 1, groups chunks by profile,
and runs every ``(algorithm_id, parameter_set)`` combination on each
chunk.  Results are aggregated into a DataFrame and persisted.
"""

from __future__ import annotations

import hashlib
import logging
import time
from pathlib import Path
from typing import Any

import numpy as np
import pandas as pd
from tqdm import tqdm

from src.codecs import huffman_codec, lzw_codec, arithmetic_codec, bwt_codec, rle_codec
from src.matching.parameter_spaces import (
    CODEC_PARAM_SPACES,
    ALGORITHM_IDS,
    iter_all_combinations,
    total_combinations,
)

logger = logging.getLogger(__name__)

# ---------------------------------------------------------------------------
# Codec dispatch table
# ---------------------------------------------------------------------------

_CODEC_DISPATCH: dict[str, Any] = {
    "huffman": huffman_codec,
    "lzw": lzw_codec,
    "arithmetic": arithmetic_codec,
    "bwt_mtf": bwt_codec,
    "rle_huffman": rle_codec,
}


def _parameter_set_id(algorithm_id: str, params: dict[str, Any]) -> str:
    """Generate a deterministic parameter-set ID from algorithm + params.

    Format: ``{algorithm_id}:{short_hash}``
    """
    raw = f"{algorithm_id}:{sorted(params.items())}"
    h = hashlib.sha256(raw.encode()).hexdigest()[:8]
    return f"{algorithm_id}:{h}"


def _run_single_chunk(
    chunk_bytes: bytes,
    algorithm_id: str,
    params: dict[str, Any],
) -> dict[str, Any]:
    """Run a single ``(algorithm_id, params)`` on one chunk.

    Returns a dict of metrics.
    """
    codec_module = _CODEC_DISPATCH[algorithm_id]
    param_set_id = _parameter_set_id(algorithm_id, params)

    # Filter params to only what the codec's compress() accepts
    # (exclude 'label' which is metadata)
    codec_kwargs = {k: v for k, v in params.items() if k != "label"}

    result = codec_module.compress(chunk_bytes, **codec_kwargs)

    if not result.valid:
        return {
            "algorithm_id": algorithm_id,
            "parameter_set_id": param_set_id,
            "label": params.get("label", ""),
            "valid": False,
            "error": result.error or "unknown",
            "compressed_size_bits": 0,
            "bpb": float("nan"),
            "compression_ratio": float("nan"),
            "elapsed_ms": result.elapsed_ms,
            "ms_per_kb": float("nan"),
            "original_size_bytes": len(chunk_bytes),
        }

    return {
        "algorithm_id": algorithm_id,
        "parameter_set_id": param_set_id,
        "label": params.get("label", ""),
        "valid": True,
        "error": None,
        "compressed_size_bits": result.compressed_size_bits,
        "bpb": result.bpb,
        "compression_ratio": result.compression_ratio,
        "elapsed_ms": result.elapsed_ms,
        "ms_per_kb": result.ms_per_kb,
        "original_size_bytes": len(chunk_bytes),
    }


def run_grid_search(
    filtered_dataset_path: Path,
    output_path: Path,
    max_chunks_per_profile: int = 300,
    sample_seed: int = 42,
    progress_every: int = 50,
) -> pd.DataFrame:
    """Run grid search over all ``(algorithm, params)`` per profile.

    Parameters
    ----------
    filtered_dataset_path : Path
        Path to ``filtered_dataset.parquet`` from Phase 1.
    output_path : Path
        Where to write ``grid_results.parquet``.
    max_chunks_per_profile : int
        Limit chunks per profile to keep runtime bounded.
    sample_seed : int
        RNG seed for deterministic sub-sampling.
    progress_every : int
        Log progress every N combinations.

    Returns
    -------
    pd.DataFrame
        Full grid results with columns:
        profile_id, chunk_id, algorithm_id, parameter_set_id, label,
        valid, error, bpb, compression_ratio, elapsed_ms, ms_per_kb,
        original_size_bytes, compressed_size_bits
    """
    logger.info("Loading filtered dataset from %s", filtered_dataset_path)
    df = pd.read_parquet(filtered_dataset_path)

    required_cols = {"profile_id", "chunk_id", "split"}
    missing = required_cols - set(df.columns)
    if missing:
        raise ValueError(f"Filtered dataset missing columns: {missing}")

    # Determine text column
    text_col = None
    for candidate in ["text", "chunk_text", "content"]:
        if candidate in df.columns:
            text_col = candidate
            break

    # If the Phase 1 dataset doesn't embed chunk text, reconstruct it from
    # `data/processed/books/{book_id}.txt` using chunk_index and chunk_size_chars.
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

    # Only use training split for grid search
    train_df = df[df["split"] == "train"].copy()
    if train_df.empty:
        logger.warning("No training samples found; using all data")
        train_df = df.copy()

    logger.info("Training samples: %d", len(train_df))

    # Group by profile and sub-sample
    profile_groups = train_df.groupby("profile_id")
    sampled_chunks: list[dict[str, Any]] = []

    rng = np.random.default_rng(sample_seed)

    for profile_id, group in profile_groups:
        if text_col is not None:
            group = group.dropna(subset=[text_col])
        if len(group) > max_chunks_per_profile:
            indices = rng.choice(len(group), size=max_chunks_per_profile, replace=False)
            group = group.iloc[indices]
        for _, row in group.iterrows():
            chunk_text = _get_chunk_text(row)
            if not chunk_text or not str(chunk_text).strip():
                continue
            sampled_chunks.append({
                "profile_id": profile_id,
                "chunk_id": row["chunk_id"],
                "text": chunk_text,
            })

    logger.info(
        "Sampled %d chunks across %d profiles",
        len(sampled_chunks),
        len(profile_groups),
    )

    # Run grid search
    total_combos = total_combinations()
    total_tasks = len(sampled_chunks) * total_combos
    logger.info(
        "Starting grid search: %d chunks x %d combos = %d tasks",
        len(sampled_chunks),
        total_combos,
        total_tasks,
    )

    results: list[dict[str, Any]] = []
    task_count = 0
    start_wall = time.time()

    pbar = tqdm(total=total_tasks, desc="Grid search", unit="task")

    for chunk_info in sampled_chunks:
        profile_id = chunk_info["profile_id"]
        chunk_id = chunk_info["chunk_id"]
        chunk_bytes = chunk_info["text"].encode("utf-8")

        for algorithm_id, params in iter_all_combinations():
            row_result = _run_single_chunk(chunk_bytes, algorithm_id, params)
            row_result["profile_id"] = profile_id
            row_result["chunk_id"] = chunk_id
            results.append(row_result)

            task_count += 1
            pbar.update(1)

    pbar.close()

    result_df = pd.DataFrame(results)
    total_wall = time.time() - start_wall
    logger.info(
        "Grid search complete: %d rows in %.1fs (%.1f tasks/s)",
        len(result_df),
        total_wall,
        task_count / total_wall if total_wall > 0 else 0,
    )

    # Write output
    output_path.parent.mkdir(parents=True, exist_ok=True)
    result_df.to_parquet(output_path, index=False)
    logger.info("Grid results written to %s", output_path)

    return result_df


def load_grid_results(path: Path) -> pd.DataFrame:
    """Load previously saved grid results."""
    return pd.read_parquet(path)
