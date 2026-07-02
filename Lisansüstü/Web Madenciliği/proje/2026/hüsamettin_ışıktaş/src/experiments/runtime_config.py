"""Runtime configuration for CLI logging and known dependency warnings."""

from __future__ import annotations

import logging
import warnings


def configure_logging(level: int = logging.INFO) -> None:
    """Configure concise CLI logging once."""
    logging.basicConfig(
        level=level,
        format="[%(levelname)s] %(message)s",
        force=False,
    )


def suppress_known_warnings() -> None:
    """Hide noisy third-party warnings that do not affect experiment results."""
    warnings.filterwarnings(
        "ignore",
        message=r"pkg_resources is deprecated as an API.*",
        category=UserWarning,
    )
    warnings.filterwarnings(
        "ignore",
        message=r"Environment variable TORCH_FORCE_NO_WEIGHTS_ONLY_LOAD detected.*",
        category=UserWarning,
    )
    warnings.filterwarnings(
        "ignore",
        message=r"dtype\(\): align should be passed as Python or NumPy boolean.*",
        category=Warning,
    )
    warnings.filterwarnings(
        "ignore",
        message=r"CUDA initialization: Unexpected error from cudaGetDeviceCount.*",
        category=UserWarning,
    )
