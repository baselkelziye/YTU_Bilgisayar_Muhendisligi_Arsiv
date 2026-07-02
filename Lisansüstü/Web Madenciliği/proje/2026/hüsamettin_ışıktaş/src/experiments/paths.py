"""Shared filesystem paths for experiments and generated outputs."""

from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[2]
SRC_DIR = PROJECT_ROOT / "src"
RESULTS_DIR = PROJECT_ROOT / "results"
RAW_RESULTS_DIR = RESULTS_DIR / "raw"
PLOTS_DIR = RESULTS_DIR / "plots"
DATASET_DIR = PROJECT_ROOT / "dataset"


def ensure_result_dirs() -> None:
    """Create result output directories if they do not already exist."""
    RAW_RESULTS_DIR.mkdir(parents=True, exist_ok=True)
    PLOTS_DIR.mkdir(parents=True, exist_ok=True)
