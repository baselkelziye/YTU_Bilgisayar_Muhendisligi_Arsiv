"""Benchmark helpers for final report assets."""

from __future__ import annotations

import csv
from pathlib import Path
from typing import Any

from src.experiments.configs import ExperimentConfig, SUPPORTED_SCALES
from src.experiments.configs import get_default_config
from src.experiments.paths import RAW_RESULTS_DIR, ensure_result_dirs
from src.experiments.results import aggregate_results, load_results
from src.experiments.runner import run_full_benchmark
from src.vis.plots import save_all_plots


DEFAULT_BENCHMARK_METHODS = ("common_neighbors", "mlp", "gcn")


def build_benchmark_configs(
    methods: tuple[str, ...] = DEFAULT_BENCHMARK_METHODS,
    scales: tuple[float, ...] = SUPPORTED_SCALES,
    seed: int = 42,
    device: str = "cpu",
) -> list[ExperimentConfig]:
    """Create explicit configs for the full method-by-scale benchmark grid."""
    return [
        get_default_config(
            method_name=method_name,
            dataset_scale=dataset_scale,
            seed=seed,
            device=device,
        )
        for method_name in methods
        for dataset_scale in scales
    ]


def write_summary_csv(
    results: list[dict[str, Any]],
    output_path: Path | str = RAW_RESULTS_DIR / "summary.csv",
) -> Path:
    """Write flattened experiment result rows to a CSV file."""
    ensure_result_dirs()
    rows = aggregate_results(results)
    path = Path(output_path)
    path.parent.mkdir(parents=True, exist_ok=True)

    if not rows:
        path.write_text("", encoding="utf-8")
        return path

    fieldnames = sorted({key for row in rows for key in row})
    with path.open("w", newline="", encoding="utf-8") as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)

    return path


def generate_report_assets(
    results_dir: Path | str = RAW_RESULTS_DIR,
) -> dict[str, Any]:
    """Generate summary CSV and plots from saved raw result JSON files."""
    results = load_results(results_dir)
    summary_path = write_summary_csv(results)
    plot_paths = save_all_plots(results) if results else {}

    return {
        "summary_csv": summary_path,
        "plots": plot_paths,
        "result_count": len(results),
    }


def run_final_benchmark(
    methods: tuple[str, ...] = DEFAULT_BENCHMARK_METHODS,
    scales: tuple[float, ...] = SUPPORTED_SCALES,
    seed: int = 42,
    device: str = "cpu",
) -> list[dict[str, Any]]:
    """Run the full benchmark grid from explicit configs."""
    configs = build_benchmark_configs(
        methods=methods,
        scales=scales,
        seed=seed,
        device=device,
    )
    return run_full_benchmark(configs)
