"""Experiment runner that coordinates data, methods, and persistence."""

import logging
from typing import Any

from src.data.loader import load_collab_data_bundle
from src.data.preprocessing import make_scaled_split
from src.experiments.configs import ExperimentConfig, validate_config
from src.experiments.progress import progress_bar
from src.experiments.results import save_result


logger = logging.getLogger(__name__)


def _run_method(
    config: ExperimentConfig,
    split_edge: dict[str, dict[str, Any]],
    data: Any,
) -> dict[str, Any]:
    if config.method_name == "common_neighbors":
        from src.methods.common_neighbors import run_common_neighbors

        return run_common_neighbors(
            split_edge=split_edge,
            ks=config.ks,
            dataset_name=config.dataset_name,
            make_undirected=config.hyperparameters.get("make_undirected", True),
            add_tie_breaker=config.hyperparameters.get("add_tie_breaker", True),
        )

    if config.method_name == "mlp":
        from src.methods.mlp import run_mlp

        return run_mlp(
            data=data,
            split_edge=split_edge,
            config=config,
            dataset_name=config.dataset_name,
            ks=config.ks,
        )

    if config.method_name == "gcn":
        from src.methods.gcn import run_gcn

        return run_gcn(
            data=data,
            split_edge=split_edge,
            config=config,
            dataset_name=config.dataset_name,
            ks=config.ks,
        )

    raise ValueError(f"Unsupported method_name: {config.method_name}")


def run_experiment(config: ExperimentConfig) -> dict[str, Any]:
    """Run one configured experiment and optionally persist its result."""
    validate_config(config)
    logger.info(
        "Preparing experiment method=%s scale=%s seed=%s device=%s",
        config.method_name,
        config.dataset_scale,
        config.seed,
        config.device,
    )

    logger.info("Loading dataset %s", config.dataset_name)
    bundle = load_collab_data_bundle(dataset_name=config.dataset_name)
    logger.info("Creating scaled train split scale=%s", config.dataset_scale)
    split_edge = make_scaled_split(
        split_edge=bundle.split_edge,
        scale=config.dataset_scale,
        seed=config.seed,
    )

    logger.info("Running method=%s", config.method_name)
    result = _run_method(config=config, split_edge=split_edge, data=bundle.data)
    result.update(
        {
            "dataset_name": config.dataset_name,
            "dataset_scale": config.dataset_scale,
            "seed": config.seed,
            "device": config.device,
            "experiment_config": config.to_dict(),
        }
    )

    if config.save_result:
        result["result_path"] = str(save_result(result))
        logger.info("Saved result to %s", result["result_path"])

    logger.info("Finished experiment method=%s scale=%s", config.method_name, config.dataset_scale)

    return result


def run_all_methods_for_scale(
    configs: list[ExperimentConfig],
) -> list[dict[str, Any]]:
    """Run multiple method configs for the same or different dataset scales."""
    return [
        run_experiment(config)
        for config in progress_bar(configs, desc="Benchmark experiments")
    ]


def run_full_benchmark(configs: list[ExperimentConfig]) -> list[dict[str, Any]]:
    """Run a benchmark from an explicit list of experiment configs."""
    return run_all_methods_for_scale(configs)
