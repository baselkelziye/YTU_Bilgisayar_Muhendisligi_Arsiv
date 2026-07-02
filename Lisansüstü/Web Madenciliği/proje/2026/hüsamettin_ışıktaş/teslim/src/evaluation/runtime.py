"""Runtime and memory measurement helpers for experiments."""

from collections.abc import Callable, Iterator
from contextlib import contextmanager
from dataclasses import dataclass
import os
import resource
import time
from typing import Any, TypeVar


T = TypeVar("T")


@dataclass(slots=True)
class ResourceUsage:
    """Resource usage values captured around an experiment block."""

    runtime_seconds: float = 0.0
    start_memory_mb: float = 0.0
    end_memory_mb: float = 0.0

    @property
    def memory_delta_mb(self) -> float:
        """Return the memory difference between the end and start snapshots."""
        return self.end_memory_mb - self.start_memory_mb


def get_memory_usage_mb() -> float:
    """Return the current process resident memory usage in megabytes."""
    try:
        import psutil

        process = psutil.Process(os.getpid())
        return process.memory_info().rss / (1024 * 1024)
    except ImportError:
        usage_kb = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
        return usage_kb / 1024


def measure_runtime(
    function: Callable[..., T],
    *args: Any,
    **kwargs: Any,
) -> tuple[T, float]:
    """Run a function and return its result with elapsed wall-clock seconds."""
    start_time = time.perf_counter()
    result = function(*args, **kwargs)
    runtime_seconds = time.perf_counter() - start_time
    return result, runtime_seconds


@contextmanager
def track_resources() -> Iterator[ResourceUsage]:
    """Track runtime and memory for a block of experiment code."""
    usage = ResourceUsage(start_memory_mb=get_memory_usage_mb())
    start_time = time.perf_counter()
    try:
        yield usage
    finally:
        usage.runtime_seconds = time.perf_counter() - start_time
        usage.end_memory_mb = get_memory_usage_mb()
