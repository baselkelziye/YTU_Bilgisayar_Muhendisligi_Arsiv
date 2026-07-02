"""Command-line entry point for running link prediction experiments."""

from __future__ import annotations

import argparse
from pathlib import Path
import sys


PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from src.experiments.configs import SUPPORTED_METHODS, ExperimentConfig
from src.experiments.configs import get_method_config
from src.experiments.runner import run_experiment
from src.experiments.runtime_config import configure_logging, suppress_known_warnings


def build_parser() -> argparse.ArgumentParser:
    """Build the training CLI parser."""
    parser = argparse.ArgumentParser(description="Run ogbl-collab experiments.")
    parser.add_argument("--method", choices=SUPPORTED_METHODS, default="common_neighbors")
    parser.add_argument("--scale", type=float, default=0.1)
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--device", default="cpu")
    parser.add_argument(
        "--epochs",
        type=int,
        default=200,
        help="Training epochs for MLP/GCN (default: 200).",
    )
    parser.add_argument("--batch-size", type=int)
    parser.add_argument("--hidden-channels", type=int)
    parser.add_argument("--num-layers", type=int)
    parser.add_argument("--dropout", type=float)
    parser.add_argument("--learning-rate", type=float)
    parser.add_argument("--no-save", action="store_true")
    parser.add_argument("--disable-tie-breaker", action="store_true")
    parser.add_argument("--directed", action="store_true")
    return parser


def config_from_args(args: argparse.Namespace) -> ExperimentConfig:
    """Translate CLI args into an experiment config."""
    hyperparameters = get_method_config(args.method)

    if args.method == "common_neighbors":
        hyperparameters["add_tie_breaker"] = not args.disable_tie_breaker
        hyperparameters["make_undirected"] = not args.directed
    else:
        optional_values = {
            "epochs": args.epochs,
            "batch_size": args.batch_size,
            "hidden_channels": args.hidden_channels,
            "num_layers": args.num_layers,
            "dropout": args.dropout,
            "learning_rate": args.learning_rate,
        }
        hyperparameters.update(
            {
                key: value
                for key, value in optional_values.items()
                if value is not None
            }
        )

    return ExperimentConfig(
        method_name=args.method,
        dataset_scale=args.scale,
        seed=args.seed,
        device=args.device,
        save_result=not args.no_save,
        hyperparameters=hyperparameters,
    )


def main() -> None:
    """Run one experiment from CLI arguments."""
    configure_logging()
    suppress_known_warnings()

    parser = build_parser()
    args = parser.parse_args()
    config = config_from_args(args)
    result = run_experiment(config)

    print(f"method_name={result['method_name']}")
    print(f"dataset_scale={result['dataset_scale']}")
    print(f"status={result['status']}")
    if "result_path" in result:
        print(f"result_path={result['result_path']}")
    print(f"metrics={result.get('metrics', {})}")


if __name__ == "__main__":
    main()
