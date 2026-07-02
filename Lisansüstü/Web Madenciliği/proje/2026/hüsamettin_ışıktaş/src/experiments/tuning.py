"""Small grid-search helpers for MLP and GCN hyperparameter tuning."""

from __future__ import annotations

from collections.abc import Iterable
import csv
from itertools import product
import logging
from pathlib import Path
from typing import Any

from src.experiments.configs import ExperimentConfig, get_method_config
from src.experiments.paths import RAW_RESULTS_DIR, ensure_result_dirs
from src.experiments.progress import progress_bar
from src.experiments.results import save_result, utc_timestamp
from src.experiments.runner import run_experiment


logger = logging.getLogger(__name__)

TUNABLE_METHODS = ("mlp", "gcn")
DEFAULT_TUNING_METRIC = "hits_at_50"
DEFAULT_TUNING_SPLIT = "valid"


def _parse_values(raw_values: str, value_type: type = float) -> list[Any]:
    return [value_type(value.strip()) for value in raw_values.split(",") if value.strip()]


def parse_tuning_grid(method_name: str, preset: str = "quick") -> dict[str, list[Any]]:
    """Return a conservative default grid for one learned method."""
    if method_name not in TUNABLE_METHODS:
        raise ValueError(f"Tuning is supported only for: {TUNABLE_METHODS}")

    if preset not in {"quick", "full"}:
        raise ValueError("preset must be 'quick' or 'full'.")

    if method_name == "mlp":
        if preset == "quick":
            return {
                "learning_rate": [0.005, 0.01],
                "dropout": [0.0, 0.2],
                "hidden_channels": [256],
                "num_layers": [3],
            }
        return {
            "learning_rate": [0.001, 0.005, 0.01],
            "dropout": [0.0, 0.2, 0.5],
            "hidden_channels": [128, 256],
            "num_layers": [2, 3],
        }

    if preset == "quick":
        return {
            "learning_rate": [0.0005, 0.001],
            "dropout": [0.0, 0.1],
            "hidden_channels": [256],
            "num_layers": [3],
        }
    return {
        "learning_rate": [0.0005, 0.001, 0.005],
        "dropout": [0.0, 0.1, 0.2],
        "hidden_channels": [128, 256, 512],
        "num_layers": [2, 3, 4],
    }


def override_grid_values(
    grid: dict[str, list[Any]],
    learning_rates: str | None = None,
    dropouts: str | None = None,
    hidden_channels: str | None = None,
    num_layers: str | None = None,
) -> dict[str, list[Any]]:
    """Apply optional CLI comma-separated grid overrides."""
    grid = {key: list(values) for key, values in grid.items()}
    if learning_rates:
        grid["learning_rate"] = _parse_values(learning_rates, float)
    if dropouts:
        grid["dropout"] = _parse_values(dropouts, float)
    if hidden_channels:
        grid["hidden_channels"] = _parse_values(hidden_channels, int)
    if num_layers:
        grid["num_layers"] = _parse_values(num_layers, int)
    return grid


def iter_grid_configs(
    method_name: str,
    grid: dict[str, list[Any]],
    dataset_scale: float,
    seed: int,
    device: str,
    epochs: int | None = None,
    batch_size: int | None = None,
    max_runs: int | None = None,
) -> list[ExperimentConfig]:
    """Build one experiment config per grid combination."""
    keys = sorted(grid)
    configs: list[ExperimentConfig] = []

    for values in product(*(grid[key] for key in keys)):
        hyperparameters = get_method_config(method_name)
        hyperparameters.update(dict(zip(keys, values, strict=True)))
        if epochs is not None:
            hyperparameters["epochs"] = epochs
        if batch_size is not None:
            hyperparameters["batch_size"] = batch_size

        configs.append(
            ExperimentConfig(
                method_name=method_name,
                dataset_scale=dataset_scale,
                seed=seed,
                device=device,
                save_result=False,
                hyperparameters=hyperparameters,
            )
        )

        if max_runs is not None and len(configs) >= max_runs:
            break

    return configs


def metric_value(
    result: dict[str, Any],
    split: str = DEFAULT_TUNING_SPLIT,
    metric: str = DEFAULT_TUNING_METRIC,
) -> float:
    """Extract the validation metric used for tuning."""
    return float(result.get("metrics", {}).get(split, {}).get(metric, float("-inf")))


def write_tuning_summary(
    results: Iterable[dict[str, Any]],
    output_path: Path | str,
    split: str = DEFAULT_TUNING_SPLIT,
    metric: str = DEFAULT_TUNING_METRIC,
) -> Path:
    """Write a compact CSV summary of tuning runs."""
    ensure_result_dirs()
    path = Path(output_path)
    path.parent.mkdir(parents=True, exist_ok=True)

    rows = []
    for result in results:
        row = {
            "tuning_score": metric_value(result, split=split, metric=metric),
            "method_name": result.get("method_name"),
            "dataset_scale": result.get("dataset_scale"),
            "seed": result.get("seed"),
            "runtime_seconds": result.get("runtime_seconds"),
            "status": result.get("status"),
            "result_path": result.get("result_path"),
        }
        row.update(result.get("config", {}))
        rows.append(row)

    rows.sort(key=lambda row: row["tuning_score"], reverse=True)
    if not rows:
        path.write_text("", encoding="utf-8")
        return path

    fieldnames = sorted({key for row in rows for key in row})
    with path.open("w", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)

    return path


def tune_method(
    method_name: str,
    dataset_scale: float = 1.0,
    seed: int = 42,
    device: str = "cpu",
    preset: str = "quick",
    epochs: int | None = None,
    batch_size: int | None = None,
    max_runs: int | None = None,
    learning_rates: str | None = None,
    dropouts: str | None = None,
    hidden_channels: str | None = None,
    num_layers: str | None = None,
    split: str = DEFAULT_TUNING_SPLIT,
    metric: str = DEFAULT_TUNING_METRIC,
) -> dict[str, Any]:
    """Run grid-search tuning for one learned method and return the best result."""
    grid = parse_tuning_grid(method_name, preset=preset)
    grid = override_grid_values(
        grid,
        learning_rates=learning_rates,
        dropouts=dropouts,
        hidden_channels=hidden_channels,
        num_layers=num_layers,
    )
    configs = iter_grid_configs(
        method_name=method_name,
        grid=grid,
        dataset_scale=dataset_scale,
        seed=seed,
        device=device,
        epochs=epochs,
        batch_size=batch_size,
        max_runs=max_runs,
    )

    tuning_id = f"{utc_timestamp()}_{method_name}_scale_{str(dataset_scale).replace('.', '_')}"
    output_dir = RAW_RESULTS_DIR / "tuning" / tuning_id
    logger.info("Starting tuning method=%s runs=%s grid=%s", method_name, len(configs), grid)

    results: list[dict[str, Any]] = []
    for index, config in enumerate(progress_bar(configs, desc=f"Tuning {method_name}"), start=1):
        logger.info("Tuning run %s/%s config=%s", index, len(configs), config.hyperparameters)
        result = run_experiment(config)
        score = metric_value(result, split=split, metric=metric)
        result["tuning"] = {
            "tuning_id": tuning_id,
            "run_index": index,
            "preset": preset,
            "grid": grid,
            "selection_split": split,
            "selection_metric": metric,
            "selection_score": score,
        }
        result["timestamp"] = f"{tuning_id}_run_{index:03d}"
        result["result_path"] = str(save_result(result, output_dir=output_dir))
        results.append(result)
        logger.info("Tuning run %s/%s score=%.6f", index, len(configs), score)

    best_result = max(results, key=lambda item: metric_value(item, split=split, metric=metric))
    summary_path = write_tuning_summary(
        results,
        output_path=output_dir / "tuning_summary.csv",
        split=split,
        metric=metric,
    )
    logger.info(
        "Best %s config score=%.6f config=%s",
        method_name,
        metric_value(best_result, split=split, metric=metric),
        best_result.get("config", {}),
    )

    return {
        "method_name": method_name,
        "tuning_id": tuning_id,
        "run_count": len(results),
        "summary_csv": summary_path,
        "best_score": metric_value(best_result, split=split, metric=metric),
        "best_result_path": best_result.get("result_path"),
        "best_config": best_result.get("config", {}),
        "results": results,
    }
