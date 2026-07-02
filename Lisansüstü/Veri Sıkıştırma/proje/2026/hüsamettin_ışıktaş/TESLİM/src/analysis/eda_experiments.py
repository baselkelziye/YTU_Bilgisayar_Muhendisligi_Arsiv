"""Chunk-size experiment runner for phase 1."""

from __future__ import annotations

import logging
from pathlib import Path

import pandas as pd

from src.clustering.kmeans_profiles import run_k_sweep
from src.features.feature_pipeline import build_feature_tables

logger = logging.getLogger(__name__)


META_COLUMNS = {
    "book_id",
    "chunk_id",
    "chunk_index",
    "split",
    "chunk_size_chars",
    "source_text_length",
}


def run_chunk_size_experiments(
    project_root: Path,
    manifest_clean_path: Path,
    split_path: Path,
    chunk_sizes: list[int | None],
    candidate_k: list[int],
) -> pd.DataFrame:
    """Run experiment matrix across chunk sizes and return metrics table.

    Only Set B features are computed here. Set A (which includes the slow
    bz2/lzma compressors) is reserved for the final feature dump after the
    chunk size has been chosen.
    """
    rows: list[dict[str, float | int | str]] = []

    for chunk_size in chunk_sizes:
        chunk_label = "no_chunk" if chunk_size is None else int(chunk_size)
        logger.info("chunk_experiment_start chunk_size=%s", chunk_label)

        _, set_b_df = build_feature_tables(
            project_root=project_root,
            manifest_clean_path=manifest_clean_path,
            split_path=split_path,
            chunk_size=chunk_size,
            include_set_a=False,
            include_set_b=True,
        )

        if set_b_df.empty:
            rows.append(
                {
                    "chunk_size": chunk_label,
                    "num_chunks": 0,
                    "mean_entropy": 0.0,
                    "mean_zlib_ratio": 0.0,
                    "best_k": 1,
                    "best_silhouette": 0.0,
                    "best_inertia": 0.0,
                }
            )
            continue

        feature_cols = [col for col in set_b_df.columns if col not in META_COLUMNS]
        _, _, _, best_metrics = run_k_sweep(set_b_df, feature_cols, candidate_k)

        rows.append(
            {
                "chunk_size": chunk_label,
                "num_chunks": int(len(set_b_df)),
                "mean_entropy": float(set_b_df["entropy_char"].mean()),
                "mean_zlib_ratio": 0.0,
                "best_k": int(best_metrics["k"]),
                "best_silhouette": float(best_metrics["silhouette"]),
                "best_inertia": float(best_metrics["inertia"]),
            }
        )
        logger.info(
            "chunk_experiment_done chunk_size=%s chunks=%s best_k=%s silhouette=%.4f",
            chunk_label,
            int(len(set_b_df)),
            int(best_metrics["k"]),
            float(best_metrics["silhouette"]),
        )

    return pd.DataFrame(rows)

