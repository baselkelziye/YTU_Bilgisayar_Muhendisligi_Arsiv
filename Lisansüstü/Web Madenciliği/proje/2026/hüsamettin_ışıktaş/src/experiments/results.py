"""Persistence helpers for experiment results."""

from __future__ import annotations

from collections.abc import Iterable
from datetime import datetime, timezone
import json
from pathlib import Path
from typing import Any

from src.experiments.paths import RAW_RESULTS_DIR, ensure_result_dirs


def utc_timestamp() -> str:
    """Return a compact UTC timestamp for result filenames."""
    return datetime.now(timezone.utc).strftime("%Y%m%d_%H%M%S")


def _to_serializable(value: Any) -> Any:
    if isinstance(value, Path):
        return str(value)
    if isinstance(value, dict):
        return {str(key): _to_serializable(item) for key, item in value.items()}
    if isinstance(value, (list, tuple)):
        return [_to_serializable(item) for item in value]
    if hasattr(value, "item"):
        return value.item()
    return value


def result_filename(result: dict[str, Any]) -> str:
    """Build a stable result filename from result metadata."""
    method_name = result.get("method_name", "unknown_method")
    dataset_scale = str(result.get("dataset_scale", "unknown_scale")).replace(".", "_")
    seed = result.get("seed", "unknown_seed")
    timestamp = result.get("timestamp", utc_timestamp())
    return f"{timestamp}_{method_name}_scale_{dataset_scale}_seed_{seed}.json"


def save_result(
    result: dict[str, Any],
    output_dir: Path | str = RAW_RESULTS_DIR,
) -> Path:
    """Save one experiment result as JSON and return the written path."""
    ensure_result_dirs()
    output_path = Path(output_dir)
    output_path.mkdir(parents=True, exist_ok=True)

    result = dict(result)
    result.setdefault("timestamp", utc_timestamp())
    path = output_path / result_filename(result)

    with path.open("w", encoding="utf-8") as file:
        json.dump(_to_serializable(result), file, indent=2, sort_keys=True)
        file.write("\n")

    return path


def load_result(path: Path | str) -> dict[str, Any]:
    """Load one JSON result file."""
    with Path(path).open("r", encoding="utf-8") as file:
        return json.load(file)


def load_results(results_dir: Path | str = RAW_RESULTS_DIR, max_results: int = 0) -> list[dict[str, Any]]:
    """Load JSON result files, newest first. If max_results > 0, return only the latest N."""
    directory = Path(results_dir)
    if not directory.exists():
        return []

    files = sorted(directory.glob("*.json"), reverse=True)
    if max_results > 0:
        files = files[:max_results]

    return [load_result(path) for path in files]


def aggregate_results(results: Iterable[dict[str, Any]]) -> list[dict[str, Any]]:
    """Flatten nested metric dictionaries into summary rows."""
    rows: list[dict[str, Any]] = []

    for result in results:
        base_row = {
            "method_name": result.get("method_name"),
            "dataset_name": result.get("dataset_name"),
            "dataset_scale": result.get("dataset_scale"),
            "seed": result.get("seed"),
            "runtime_seconds": result.get("runtime_seconds"),
            "memory_mb": result.get("memory_mb"),
            "memory_delta_mb": result.get("memory_delta_mb"),
            "status": result.get("status"),
            "timestamp": result.get("timestamp"),
        }

        for split_name, split_metrics in result.get("metrics", {}).items():
            row = dict(base_row)
            row["split"] = split_name
            row.update(split_metrics)
            rows.append(row)

    return rows
