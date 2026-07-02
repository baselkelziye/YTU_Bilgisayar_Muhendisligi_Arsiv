"""Chunk size selection logic for phase 1."""

from __future__ import annotations

import math
from pathlib import Path

import pandas as pd


def choose_chunk_size(experiments: pd.DataFrame) -> tuple[int | None, pd.DataFrame]:
    """Select best chunk size from experiment matrix using weighted score."""
    if experiments.empty:
        return None, experiments.copy()

    work = experiments.copy()
    max_chunks = max(float(work["num_chunks"].max()), 1.0)

    work["silhouette_score"] = work["best_silhouette"].clip(lower=0.0)
    work["coverage_score"] = work["num_chunks"] / max_chunks
    work["entropy_balance_score"] = work["mean_entropy"].apply(
        lambda value: max(0.0, 1.0 - (abs(float(value) - 4.0) / 4.0))
    )
    work["final_score"] = (
        0.60 * work["silhouette_score"] + 0.25 * work["coverage_score"] + 0.15 * work["entropy_balance_score"]
    )

    best_row = work.sort_values("final_score", ascending=False).iloc[0]
    chunk_value = best_row["chunk_size"]
    selected = None if chunk_value == "no_chunk" else int(chunk_value)
    return selected, work.sort_values("final_score", ascending=False).reset_index(drop=True)


def write_chunk_decision_report(
    output_path: Path,
    selected_chunk_size: int | None,
    scored_experiments: pd.DataFrame,
) -> None:
    """Write markdown decision report for selected chunk size."""
    selected_text = "no_chunk (whole-book)" if selected_chunk_size is None else f"{selected_chunk_size} chars"
    lines = [
        "# Phase 1 Chunk Size Decision",
        "",
        f"Selected chunk size: **{selected_text}**",
        "",
        "## Scoring formula",
        "",
        "`final_score = 0.60 * silhouette + 0.25 * coverage + 0.15 * entropy_balance`",
        "",
        "## Ranked candidates",
        "",
        "| chunk_size | num_chunks | best_k | silhouette | final_score |",
        "|---|---:|---:|---:|---:|",
    ]

    for _, row in scored_experiments.iterrows():
        lines.append(
            "| {chunk} | {chunks} | {k} | {silh:.4f} | {score:.4f} |".format(
                chunk=row["chunk_size"],
                chunks=int(row["num_chunks"]),
                k=int(row["best_k"]),
                silh=float(row["best_silhouette"]),
                score=float(row["final_score"]),
            )
        )

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text("\n".join(lines) + "\n", encoding="utf-8")

