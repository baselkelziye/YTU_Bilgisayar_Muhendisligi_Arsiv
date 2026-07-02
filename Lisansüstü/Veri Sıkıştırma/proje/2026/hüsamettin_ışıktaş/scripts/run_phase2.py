#!/usr/bin/env python3
"""Phase 2 pipeline runner: Algorithm-to-Profile Matching.

Usage
-----
    python scripts/run_phase2.py [--project-root PATH] [--max-chunks N]

This script:
  1. Loads the filtered dataset from Phase 1.
  2. Runs grid search over all ``(algorithm_id, parameter_set)`` combos.
  3. Selects the best combination per profile.
  4. Computes baseline comparison (gzip/bzip2/lzma/zlib).
  5. Writes all Phase 2 artifacts.
"""

from __future__ import annotations

import argparse
import logging
import sys
import time
from pathlib import Path

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
logger = logging.getLogger("run_phase2")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Phase 2: Algorithm-to-Profile Matching")
    parser.add_argument(
        "--project-root",
        type=str,
        default=".",
        help="Project root directory (default: current dir)",
    )
    parser.add_argument(
        "--max-chunks",
        type=int,
        default=300,
        help="Max chunks per profile for grid search (default: 300)",
    )
    parser.add_argument(
        "--sample-seed",
        type=int,
        default=42,
        help="RNG seed for deterministic sub-sampling (default: 42)",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    project_root = Path(args.project_root).resolve()
    logger.info("Phase 2 starting — project root: %s", project_root)

    # Make `src/` importable when running as a script (no editable install needed).
    if str(project_root) not in sys.path:
        sys.path.insert(0, str(project_root))

    # ------------------------------------------------------------------
    # Paths
    # ------------------------------------------------------------------
    artifacts_dir = project_root / "artifacts" / "phase2"
    artifacts_dir.mkdir(parents=True, exist_ok=True)

    filtered_dataset_path = project_root / "artifacts" / "phase1" / "filtered_dataset.parquet"
    if not filtered_dataset_path.exists():
        logger.error("Filtered dataset not found at %s", filtered_dataset_path)
        logger.error("Run Phase 1 first: python scripts/run_phase1.py")
        return 1

    grid_results_path = artifacts_dir / "grid_results.parquet"
    mapping_json_path = artifacts_dir / "profile_algorithm_mapping.json"
    mapping_csv_path = artifacts_dir / "profile_algorithm_mapping.csv"
    baseline_path = artifacts_dir / "baseline_comparison.csv"
    report_path = artifacts_dir / "algorithm_selection_report.md"
    summary_path = artifacts_dir / "phase2_summary.json"

    # ------------------------------------------------------------------
    # 1. Grid search
    # ------------------------------------------------------------------
    from src.matching.grid_search import run_grid_search, load_grid_results
    import pandas as pd

    if grid_results_path.exists():
        logger.info("Loading existing grid results from %s", grid_results_path)
        grid_results = load_grid_results(grid_results_path)
        # Backward-compat: older grid results may miss required columns, or may
        # have been computed from a different Phase 1 profile set.
        phase1_df = pd.read_parquet(filtered_dataset_path, columns=["profile_id"])
        phase1_profiles = set(phase1_df["profile_id"].dropna().unique().tolist())
        grid_profiles = set(grid_results["profile_id"].dropna().unique().tolist()) if "profile_id" in grid_results.columns else set()

        need_recompute = False
        if "valid" not in grid_results.columns:
            need_recompute = True
            reason = "missing required columns"
        elif grid_profiles and phase1_profiles and grid_profiles != phase1_profiles:
            need_recompute = True
            reason = f"profile set changed ({len(grid_profiles)} -> {len(phase1_profiles)})"
        else:
            reason = ""

        if need_recompute:
            logger.warning(
                "Recomputing grid search (%s): %s",
                reason,
                grid_results_path,
            )
            grid_results_path.unlink(missing_ok=True)
            grid_results = run_grid_search(
                filtered_dataset_path=filtered_dataset_path,
                output_path=grid_results_path,
                max_chunks_per_profile=args.max_chunks,
                sample_seed=args.sample_seed,
            )
    else:
        logger.info("Running grid search...")
        t0 = time.time()
        grid_results = run_grid_search(
            filtered_dataset_path=filtered_dataset_path,
            output_path=grid_results_path,
            max_chunks_per_profile=args.max_chunks,
            sample_seed=args.sample_seed,
        )
        logger.info("Grid search finished in %.1fs (%d rows)", time.time() - t0, len(grid_results))

    # ------------------------------------------------------------------
    # 2. Select best per profile
    # ------------------------------------------------------------------
    from src.matching.profile_mapping import (
        select_best_per_profile,
        write_mapping_json,
        write_mapping_csv,
        write_selection_report,
    )

    logger.info("Selecting best algorithm per profile...")
    best_df = select_best_per_profile(grid_results)

    if best_df.empty:
        logger.error("No valid selection could be made. Check grid results.")
        return 1

    logger.info("Selected mappings for %d profiles", len(best_df))

    # Write mapping artifacts
    write_mapping_json(best_df, mapping_json_path)
    write_mapping_csv(best_df, mapping_csv_path)
    write_selection_report(best_df, grid_results, report_path)

    # ------------------------------------------------------------------
    # 3. Baseline comparison
    # ------------------------------------------------------------------
    from src.evaluation.baseline_compare import (
        compute_baseline_metrics,
        write_baseline_comparison,
    )

    logger.info("Computing baseline comparison...")
    t0 = time.time()
    baseline_df = compute_baseline_metrics(
        grid_results=grid_results,
        filtered_dataset_path=filtered_dataset_path,
        max_chunks_per_profile=args.max_chunks,
        sample_seed=args.sample_seed,
    )
    write_baseline_comparison(baseline_df, baseline_path)
    logger.info("Baseline comparison finished in %.1fs", time.time() - t0)

    # ------------------------------------------------------------------
    # 4. Summary
    # ------------------------------------------------------------------
    import json

    summary = {
        "status": "ok",
        "num_profiles": len(best_df),
        "num_codec_specs": sum(len(grid_results["algorithm_id"].unique()) for _ in [1]),
        "grid_rows": len(grid_results),
        "artifacts": {
            "grid_results": str(grid_results_path),
            "mapping_json": str(mapping_json_path),
            "mapping_csv": str(mapping_csv_path),
            "selection_report": str(report_path),
            "baseline_comparison": str(baseline_path),
        },
    }
    summary_path.write_text(json.dumps(summary, indent=2, ensure_ascii=False), encoding="utf-8")

    logger.info("=" * 60)
    logger.info("Phase 2 complete!")
    logger.info("  Profiles mapped: %d", len(best_df))
    logger.info("  Grid rows:       %d", len(grid_results))
    logger.info("  Artifacts:       %s", artifacts_dir)
    logger.info("=" * 60)

    return 0


if __name__ == "__main__":
    sys.exit(main())
