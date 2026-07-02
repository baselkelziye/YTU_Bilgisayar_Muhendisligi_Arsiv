"""Progress bar helpers with a lightweight fallback."""

from collections.abc import Iterable
from typing import Any, TypeVar


T = TypeVar("T")


def progress_bar(iterable: Iterable[T], **kwargs: Any) -> Iterable[T]:
    """Return a tqdm progress bar when available, otherwise the original iterable."""
    try:
        from tqdm.auto import tqdm

        return tqdm(iterable, **kwargs)
    except ImportError:
        return iterable
