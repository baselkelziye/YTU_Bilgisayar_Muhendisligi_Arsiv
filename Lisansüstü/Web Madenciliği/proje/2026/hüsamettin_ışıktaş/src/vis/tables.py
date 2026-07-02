"""Tabular summaries for experiment result dictionaries."""

from collections.abc import Iterable
from typing import Any

from src.experiments.results import aggregate_results


def make_summary_table(results: Iterable[dict[str, Any]]) -> list[dict[str, Any]]:
    """Return one flattened row per result split."""
    return aggregate_results(results)


def make_best_results_table(
    results: Iterable[dict[str, Any]],
    metric_key: str = "hits_at_50",
    split: str = "test",
) -> list[dict[str, Any]]:
    """Return the best row per method and dataset scale for a selected metric."""
    best_rows: dict[tuple[str, float], dict[str, Any]] = {}

    for row in make_summary_table(results):
        if row.get("split") != split:
            continue

        method_name = row.get("method_name")
        dataset_scale = row.get("dataset_scale")
        metric_value = row.get(metric_key)

        if method_name is None or dataset_scale is None or metric_value is None:
            continue

        key = (str(method_name), float(dataset_scale))
        current_best = best_rows.get(key)
        if current_best is None or float(metric_value) > float(current_best[metric_key]):
            best_rows[key] = row

    return list(best_rows.values())
