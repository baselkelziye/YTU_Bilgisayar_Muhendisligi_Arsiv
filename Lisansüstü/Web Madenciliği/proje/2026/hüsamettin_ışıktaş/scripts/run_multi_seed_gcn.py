"""Multi-seed GCN experiment runner — runs GCN at all scales with multiple seeds.

Usage:
    python scripts/run_multi_seed_gcn.py
    python scripts/run_multi_seed_gcn.py --seeds 42 123 456
    python scripts/run_multi_seed_gcn.py --scales 0.1 0.5 1.0 --device cpu
    python scripts/run_multi_seed_gcn.py --tune-first  # tune hyperparams first, then run best
"""

from __future__ import annotations

import argparse
import json
import logging
import sys
from datetime import datetime, timezone
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from src.experiments.configs import ExperimentConfig, get_default_config, get_method_config
from src.experiments.paths import PLOTS_DIR, RAW_RESULTS_DIR, ensure_result_dirs
from src.experiments.progress import progress_bar
from src.experiments.results import save_result, utc_timestamp
from src.experiments.runner import run_experiment
from src.vis.plots import save_all_plots
from src.vis.tables import make_best_results_table, make_summary_table

logger = logging.getLogger(__name__)


def _now_str() -> str:
    return utc_timestamp()


def run_multi_seed(
    method: str = "gcn",
    scales: tuple[float, ...] = (0.1, 0.5, 1.0),
    seeds: tuple[int, ...] = (42, 123, 456),
    device: str = "cpu",
    extra_hp: dict | None = None,
) -> dict:
    """Run one method at all scales × seeds and return aggregate results."""
    results: list[dict] = []
    runs_dir = RAW_RESULTS_DIR / "multi_seed" / f"{_now_str()}_{method}"
    runs_dir.mkdir(parents=True, exist_ok=True)

    total_runs = len(scales) * len(seeds)
    logger.info("Starting multi-seed benchmark: method=%s runs=%s", method, total_runs)

    for scale in scales:
        for seed in seeds:
            config = get_default_config(
                method_name=method,
                dataset_scale=scale,
                seed=seed,
                device=device,
            )
            if extra_hp:
                config.hyperparameters.update(extra_hp)

            logger.info(
                "Running %s scale=%s seed=%s hp=%s",
                method, scale, seed,
                {k: v for k, v in config.hyperparameters.items() if k in ("epochs", "lr", "hidden")},
            )
            result = run_experiment(config)
            result["result_path"] = str(save_result(result, output_dir=runs_dir))
            results.append(result)

            # Log key metrics
            test_metrics = result.get("metrics", {}).get("test", {})
            logger.info(
                "  → %s scale=%.1f seed=%s hits@50=%.4f time=%.1fs",
                method, scale, seed,
                test_metrics.get("hits_at_50", 0),
                result.get("runtime_seconds", 0),
            )

    # Generate all plots
    logger.info("Generating report plots...")
    plot_paths = save_all_plots(results, split="test")
    for name, path in plot_paths.items():
        if isinstance(path, list):
            logger.info("  %s: %d plots", name, len(path))
        else:
            logger.info("  %s: %s", name, path)

    # Save epoch-level validation metrics
    epoch_rows = []
    for result in results:
        val_metrics = result.get("val_metrics", [])
        method = result.get("method_name", "?")
        scale = result.get("dataset_scale", "?")
        seed = result.get("seed", "?")
        for vm in val_metrics:
            epoch_rows.append({
                "method": method,
                "scale": scale,
                "seed": seed,
                "epoch": vm.get("epoch", 0),
                "valid_hits_at_50": vm.get("valid_hits_at_50", 0),
                "lr": vm.get("lr", 0),
                "loss": result.get("losses", [None])[min(vm.get("epoch", 1) - 1, len(result.get("losses", [])) - 1)] if result.get("losses") else None,
            })
    if epoch_rows:
        epoch_csv_path = runs_dir / "epoch_metrics.csv"
        import csv
        fieldnames = ["method", "scale", "seed", "epoch", "valid_hits_at_50", "lr", "loss"]
        with epoch_csv_path.open("w", newline="", encoding="utf-8") as f:
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(epoch_rows)
        logger.info("  Epoch metrics saved to %s (%d rows)", epoch_csv_path, len(epoch_rows))

    # Build summary
    summary_rows = make_summary_table(results)
    best_rows = make_best_results_table(results, split="test")

    summary_path = runs_dir / "summary.csv"
    import csv
    if summary_rows:
        fieldnames = sorted({k for row in summary_rows for k in row})
        with summary_path.open("w", newline="", encoding="utf-8") as f:
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(summary_rows)

    meta_path = runs_dir / "meta.json"
    meta = {
        "method": method,
        "scales": list(scales),
        "seeds": list(seeds),
        "device": device,
        "total_runs": total_runs,
        "plots": {k: str(v) for k, v in plot_paths.items() if not isinstance(v, list)},
        "best_rows": best_rows,
    }
    with meta_path.open("w", encoding="utf-8") as f:
        json.dump(meta, f, indent=2, ensure_ascii=False)

    return {
        "runs_dir": str(runs_dir),
        "results": results,
        "summary_rows": summary_rows,
        "best_rows": best_rows,
        "plots": plot_paths,
        "meta": meta,
    }


def main() -> None:
    parser = argparse.ArgumentParser(description="Multi-seed GCN benchmark")
    parser.add_argument("--method", default="gcn", choices=["gcn", "mlp", "common_neighbors"])
    parser.add_argument("--scales", nargs="+", type=float, default=[0.1, 0.5, 1.0])
    parser.add_argument("--seeds", nargs="+", type=int, default=[42, 123, 456])
    parser.add_argument("--device", default="cpu")
    parser.add_argument("--epochs", type=int, default=None, help="Override epochs")
    parser.add_argument("--lr", type=float, default=None, help="Override learning rate")
    parser.add_argument("--hidden", type=int, default=None, help="Override hidden channels")
    parser.add_argument("--dropout", type=float, default=None, help="Override dropout")
    parser.add_argument("--num-layers", type=int, default=None, help="Override num_layers")
    args = parser.parse_args()

    logging.basicConfig(
        level=logging.INFO,
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
    )

    extra_hp: dict = {}
    if args.epochs is not None:
        extra_hp["epochs"] = args.epochs
    if args.lr is not None:
        extra_hp["learning_rate"] = args.lr
    if args.hidden is not None:
        extra_hp["hidden_channels"] = args.hidden
    if args.dropout is not None:
        extra_hp["dropout"] = args.dropout
    if args.num_layers is not None:
        extra_hp["num_layers"] = args.num_layers

    meta = run_multi_seed(
        method=args.method,
        scales=tuple(args.scales),
        seeds=tuple(args.seeds),
        device=args.device,
        extra_hp=extra_hp if extra_hp else None,
    )

    # Print summary
    print("\n" + "=" * 60)
    print("BEST RESULTS (test split)")
    print("=" * 60)
    for row in meta["best_rows"]:
        print(
            f"  {row.get('method_name', '?'):20s} scale={row.get('dataset_scale', '?'):.1f}  "
            f"Hits@50={row.get('hits_at_50', 0):.4f}  "
            f"time={row.get('runtime_seconds', 0):.0f}s"
        )
    print(f"\nResults saved to: {meta['runs_dir']}")
    print(f"Summary CSV: {meta['runs_dir']}/summary.csv")


if __name__ == "__main__":
    main()
