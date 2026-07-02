"""Top-level project CLI."""

from __future__ import annotations

import argparse

from src.experiments.benchmark import build_benchmark_configs, generate_report_assets
from src.experiments.configs import SUPPORTED_METHODS, SUPPORTED_SCALES
from src.experiments.runner import run_full_benchmark
from src.experiments.runtime_config import configure_logging, suppress_known_warnings
from src.experiments.tuning import TUNABLE_METHODS, tune_method
from src.train import config_from_args as train_config_from_args
from src.train import run_experiment


def build_parser() -> argparse.ArgumentParser:
    """Build the root CLI parser."""
    parser = argparse.ArgumentParser(description="ogbl-collab project CLI")
    subparsers = parser.add_subparsers(dest="command", required=True)

    train_parser = subparsers.add_parser("train", help="Run an experiment")
    train_parser.add_argument("--method", choices=SUPPORTED_METHODS, default="common_neighbors")
    train_parser.add_argument("--scale", type=float, default=0.1)
    train_parser.add_argument("--seed", type=int, default=42)
    train_parser.add_argument("--device", default="cpu")
    train_parser.add_argument(
        "--epochs",
        type=int,
        default=200,
        help="Training epochs for MLP/GCN (default: 200).",
    )
    train_parser.add_argument("--batch-size", type=int)
    train_parser.add_argument("--hidden-channels", type=int)
    train_parser.add_argument("--num-layers", type=int)
    train_parser.add_argument("--dropout", type=float)
    train_parser.add_argument("--learning-rate", type=float)
    train_parser.add_argument("--no-save", action="store_true")
    train_parser.add_argument("--disable-tie-breaker", action="store_true")
    train_parser.add_argument("--directed", action="store_true")

    benchmark_parser = subparsers.add_parser("benchmark", help="Run multiple methods across scales")
    benchmark_parser.add_argument(
        "--methods",
        nargs="+",
        choices=SUPPORTED_METHODS,
        default=list(SUPPORTED_METHODS),
        help="Methods to run (default: all).",
    )
    benchmark_parser.add_argument(
        "--scales",
        nargs="+",
        type=float,
        default=list(SUPPORTED_SCALES),
        help="Dataset scales to run, e.g. --scales 0.1 0.5 1.0",
    )
    benchmark_parser.add_argument("--seed", type=int, default=42)
    benchmark_parser.add_argument("--device", default="cpu")
    benchmark_parser.add_argument(
        "--epochs",
        type=int,
        default=200,
        help="Epochs for MLP and GCN runs (default: 200).",
    )
    benchmark_parser.add_argument("--batch-size", type=int, help="Override batch size for MLP and GCN runs.")
    benchmark_parser.add_argument("--no-save", action="store_true")
    benchmark_parser.add_argument(
        "--assets",
        action="store_true",
        help="After running, generate summary CSV and plots from saved results.",
    )

    tune_parser = subparsers.add_parser("tune", help="Tune MLP/GCN hyperparameters")
    tune_parser.add_argument("--methods", nargs="+", choices=TUNABLE_METHODS, default=list(TUNABLE_METHODS))
    tune_parser.add_argument("--scale", type=float, default=1.0)
    tune_parser.add_argument("--seed", type=int, default=42)
    tune_parser.add_argument("--device", default="cpu")
    tune_parser.add_argument("--preset", choices=("quick", "full"), default="quick")
    tune_parser.add_argument("--epochs", type=int, help="Epochs per tuning run.")
    tune_parser.add_argument("--batch-size", type=int, help="Batch size per tuning run.")
    tune_parser.add_argument("--max-runs", type=int, help="Limit runs per method for quick checks.")
    tune_parser.add_argument("--learning-rates", help="Comma-separated override, e.g. 0.0005,0.001")
    tune_parser.add_argument("--dropouts", help="Comma-separated override, e.g. 0.0,0.2")
    tune_parser.add_argument("--hidden-channels", help="Comma-separated override, e.g. 128,256")
    tune_parser.add_argument("--num-layers", help="Comma-separated override, e.g. 2,3")

    subparsers.add_parser("assets", help="Generate summary CSV and plots from saved results")

    return parser


def main() -> None:
    """Dispatch top-level CLI commands."""
    configure_logging()
    suppress_known_warnings()

    parser = build_parser()
    args = parser.parse_args()

    if args.command == "train":
        config = train_config_from_args(args)
        result = run_experiment(config)
        print(f"method_name={result['method_name']}")
        print(f"dataset_scale={result['dataset_scale']}")
        print(f"status={result['status']}")
        if "result_path" in result:
            print(f"result_path={result['result_path']}")
        print(f"metrics={result.get('metrics', {})}")
    elif args.command == "benchmark":
        for scale in args.scales:
            if not 0 < scale <= 1:
                raise ValueError("Each scale must be in the range (0, 1].")

        configs = build_benchmark_configs(
            methods=tuple(args.methods),
            scales=tuple(args.scales),
            seed=args.seed,
            device=args.device,
        )
        if args.no_save:
            for config in configs:
                config.save_result = False
        for config in configs:
            if config.method_name in {"mlp", "gcn"}:
                if args.epochs is not None:
                    config.hyperparameters["epochs"] = args.epochs
                if args.batch_size is not None:
                    config.hyperparameters["batch_size"] = args.batch_size

        results = run_full_benchmark(configs)
        print(f"run_count={len(results)}")
        statuses = {result.get('status', 'unknown') for result in results}
        print(f"statuses={sorted(statuses)}")

        if args.assets:
            assets = generate_report_assets()
            print(f"result_count={assets['result_count']}")
            print(f"summary_csv={assets['summary_csv']}")
            print(f"plots={assets['plots']}")
    elif args.command == "tune":
        if not 0 < args.scale <= 1:
            raise ValueError("scale must be in the range (0, 1].")

        summaries = []
        for method_name in args.methods:
            summaries.append(
                tune_method(
                    method_name=method_name,
                    dataset_scale=args.scale,
                    seed=args.seed,
                    device=args.device,
                    preset=args.preset,
                    epochs=args.epochs,
                    batch_size=args.batch_size,
                    max_runs=args.max_runs,
                    learning_rates=args.learning_rates,
                    dropouts=args.dropouts,
                    hidden_channels=args.hidden_channels,
                    num_layers=args.num_layers,
                )
            )

        for summary in summaries:
            print(f"method_name={summary['method_name']}")
            print(f"tuning_id={summary['tuning_id']}")
            print(f"run_count={summary['run_count']}")
            print(f"best_score={summary['best_score']}")
            print(f"best_config={summary['best_config']}")
            print(f"best_result_path={summary['best_result_path']}")
            print(f"summary_csv={summary['summary_csv']}")
    elif args.command == "assets":
        assets = generate_report_assets()
        print(f"result_count={assets['result_count']}")
        print(f"summary_csv={assets['summary_csv']}")
        print(f"plots={assets['plots']}")


if __name__ == "__main__":
    main()
