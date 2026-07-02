"""Best-combination selection and mapping-table generation.

Reads the grid-search results, selects the winning ``(algorithm_id,
parameter_set_id)`` per profile, and writes the mapping table consumed
by Phase 4.
"""

from __future__ import annotations

import json
import logging
from pathlib import Path
from typing import Any

import pandas as pd

logger = logging.getLogger(__name__)


def select_best_per_profile(
    grid_results: pd.DataFrame,
    primary_metric: str = "bpb",
    tie_break_metric: str = "ms_per_kb",
    min_valid_rate: float = 0.5,
) -> pd.DataFrame:
    """Select the best ``(algorithm_id, parameter_set_id)`` per profile.

    Selection logic:
      1. Filter to rows where ``valid == True``.
      2. Group by ``(profile_id, algorithm_id, parameter_set_id)``.
      3. Compute aggregate metrics for each group.
      4. Drop groups with ``valid_rate < min_valid_rate``.
      5. For each profile, pick the parameter set with lowest mean_bpb
         (tie-break: lowest mean_ms_per_kb).

    This is a simple oracle — no algorithm-spread enforcement. If bwt_mtf
    dominates most profiles, that means the data genuinely has one best
    compression algorithm for those profiles.

    Parameters
    ----------
    grid_results : pd.DataFrame
        Output of ``grid_search.run_grid_search()``.
    primary_metric : str
        Column name for primary selection (default ``bpb``).
    tie_break_metric : str
        Column name for tie-breaking (default ``ms_per_kb``).
    min_valid_rate : float
        Minimum fraction of valid compressions to consider a parameter set.

    Returns
    -------
    pd.DataFrame
        One row per profile with columns:
        profile_id, algorithm_id, parameter_set_id, label,
        mean_bpb, median_bpb, p95_bpb, std_bpb,
        mean_ms_per_kb, median_ms_per_kb,
        n_samples, valid_rate
    """
    required = {"profile_id", "algorithm_id", "parameter_set_id", "valid"}
    missing = required - set(grid_results.columns)
    if missing:
        raise ValueError(f"Grid results missing columns: {missing}")

    valid_df = grid_results[grid_results["valid"] == True].copy()  # noqa: E712

    if valid_df.empty:
        logger.error("No valid results in grid search output")
        return pd.DataFrame()

    # Group by (profile_id, algorithm_id, parameter_set_id)
    group_cols = ["profile_id", "algorithm_id", "parameter_set_id", "label"]
    if "label" not in valid_df.columns:
        group_cols.remove("label")

    agg = valid_df.groupby(group_cols, dropna=False).agg(
        mean_bpb=(primary_metric, "mean"),
        median_bpb=(primary_metric, "median"),
        p95_bpb=(primary_metric, lambda x: x.quantile(0.95)),
        std_bpb=(primary_metric, "std"),
        mean_ms_per_kb=(tie_break_metric, "mean"),
        median_ms_per_kb=(tie_break_metric, "median"),
        n_samples=(primary_metric, "count"),
        valid_rate=("valid", "mean"),
    ).reset_index()

    # Filter by valid_rate
    agg = agg[agg["valid_rate"] >= min_valid_rate].copy()

    if agg.empty:
        logger.error("No parameter sets pass the valid_rate threshold of %.2f", min_valid_rate)
        return pd.DataFrame()

    # ---------------------------------------------------------------
    # Simple best-per-profile selection (no algorithm diversity enforcement)
    # ---------------------------------------------------------------
    # Pick the parameter set with lowest mean_bpb per profile.
    # Tie-break: lowest mean_ms_per_kb.
    best = (
        agg.sort_values(["mean_bpb", "mean_ms_per_kb"])
        .groupby("profile_id", sort=False)
        .first()
        .reset_index()
    )

    used_algos = set(best["algorithm_id"].unique())
    logger.info(
        "Selected best-per-profile for %d profiles (used algos: %s)",
        len(best), sorted(used_algos),
    )
    return best


def write_mapping_json(
    best_df: pd.DataFrame,
    output_path: Path,
) -> None:
    """Write the profile→algorithm mapping as a JSON lookup table.

    Format (consumed by Phase 4):
    .. code-block:: json

        {
          "profile_2": {
            "algorithm_id": "bwt_mtf",
            "parameter_set_id": "bwt_mtf:cfbe9ed5",
            "expected_bpb": 4.317,
            "expected_ms_per_kb": 6.856,
            "n_samples": 300,
            "valid_rate": 1.0
          },
          ...
        }
    """
    mapping: dict[str, dict[str, Any]] = {}

    for _, row in best_df.iterrows():
        profile_id = row["profile_id"]
        mapping[profile_id] = {
            "algorithm_id": row["algorithm_id"],
            "parameter_set_id": row["parameter_set_id"],
            "expected_bpb": float(row["mean_bpb"]),
            "expected_ms_per_kb": float(row["mean_ms_per_kb"]),
            "n_samples": int(row["n_samples"]),
            "valid_rate": float(row["valid_rate"]),
        }

    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(
        json.dumps(mapping, indent=2, ensure_ascii=False),
        encoding="utf-8",
    )
    logger.info("Mapping JSON written to %s (%d profiles)", output_path, len(mapping))


def write_mapping_csv(
    best_df: pd.DataFrame,
    output_path: Path,
) -> None:
    """Write the mapping as a CSV for inspection."""
    output_path.parent.mkdir(parents=True, exist_ok=True)
    cols = [
        "profile_id",
        "algorithm_id",
        "parameter_set_id",
        "mean_bpb",
        "mean_ms_per_kb",
        "n_samples",
        "valid_rate",
    ]
    out_cols = [c for c in cols if c in best_df.columns]
    best_df[out_cols].to_csv(output_path, index=False)
    logger.info("Mapping CSV written to %s", output_path)


def write_selection_report(
    best_df: pd.DataFrame,
    grid_results: pd.DataFrame,
    output_path: Path,
) -> None:
    """Generate a Markdown report explaining the selection per profile."""
    output_path.parent.mkdir(parents=True, exist_ok=True)

    lines: list[str] = [
        "# Phase 2 Algorithm Selection Report",
        "",
        "Selected best `(algorithm_id, parameter_set_id)` per `profile_id` using:",
        "- primary: **min mean_bpb**",
        "- tie-break: **min mean_ms_per_kb**",
        "",
        "## Winners",
        "",
    ]

    for _, row in best_df.iterrows():
        lines.append(
            f"- **{row['profile_id']}**: "
            f"`{row['algorithm_id']}` / `{row['parameter_set_id']}` "
            f"(bpb={row['mean_bpb']:.4f}, "
            f"ms/KB={row['mean_ms_per_kb']:.4f}, "
            f"valid_rate={row['valid_rate']:.3f}, "
            f"n={int(row['n_samples'])})"
        )

    lines.extend(["", "## Per-Profile Detail", ""])

    for _, row in best_df.iterrows():
        profile_id = row["profile_id"]
        lines.append(f"### {profile_id}")
        lines.append("")
        lines.append(f"- **Winner**: `{row['algorithm_id']}` / `{row['parameter_set_id']}`")
        lines.append(f"- **Mean BPB**: {row['mean_bpb']:.4f}")
        lines.append(f"- **Median BPB**: {row['median_bpb']:.4f}")
        lines.append(f"- **P95 BPB**: {row['p95_bpb']:.4f}")
        lines.append(f"- **Std BPB**: {row['std_bpb']:.4f}")
        lines.append(f"- **Mean ms/KB**: {row['mean_ms_per_kb']:.4f}")
        lines.append(f"- **Median ms/KB**: {row['median_ms_per_kb']:.4f}")
        lines.append(f"- **Samples**: {int(row['n_samples'])}")
        lines.append(f"- **Valid Rate**: {row['valid_rate']:.3f}")
        lines.append("")

        # Show runner-up summary
        profile_results = grid_results[
            (grid_results["profile_id"] == profile_id) & (grid_results["valid"] == True)  # noqa: E712
        ]
        if not profile_results.empty:
            runner_ups = (
                profile_results.groupby(["algorithm_id", "parameter_set_id"])
                .agg(mean_bpb=("bpb", "mean"), n_samples=("bpb", "count"))
                .reset_index()
                .sort_values("mean_bpb")
            )
            lines.append("| Algorithm | Params | Mean BPB | Samples |")
            lines.append("|---|---|---|---|")
            for _, ru in runner_ups.iterrows():
                marker = "← **winner**" if ru["parameter_set_id"] == row["parameter_set_id"] else ""
                lines.append(
                    f"| {ru['algorithm_id']} | {ru['parameter_set_id']} | "
                    f"{ru['mean_bpb']:.4f} | {int(ru['n_samples'])} {marker} |"
                )
            lines.append("")

    output_path.write_text("\n".join(lines), encoding="utf-8")
    logger.info("Selection report written to %s", output_path)
