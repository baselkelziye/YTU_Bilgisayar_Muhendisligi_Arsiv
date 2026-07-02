"""Deterministic book-level split helpers."""

from __future__ import annotations

import random
from collections.abc import Sequence


def split_book_ids(
    book_ids: Sequence[str],
    train_ratio: float = 0.70,
    val_ratio: float = 0.15,
    test_ratio: float = 0.15,
    seed: int = 42,
) -> dict[str, list[str]]:
    """Split unique book ids into train/validation/test sets."""
    if abs((train_ratio + val_ratio + test_ratio) - 1.0) > 1e-9:
        raise ValueError("Split ratios must sum to 1.0")

    unique_ids = sorted(set(book_ids))
    rng = random.Random(seed)
    rng.shuffle(unique_ids)

    n_total = len(unique_ids)
    n_train = int(n_total * train_ratio)
    n_val = int(n_total * val_ratio)
    n_test = n_total - n_train - n_val

    train_ids = unique_ids[:n_train]
    val_ids = unique_ids[n_train : n_train + n_val]
    test_ids = unique_ids[n_train + n_val : n_train + n_val + n_test]

    return {"train": train_ids, "validation": val_ids, "test": test_ids}


def assert_no_leakage(split: dict[str, list[str]]) -> None:
    """Raise ValueError if any book id appears in multiple splits."""
    train = set(split.get("train", []))
    validation = set(split.get("validation", []))
    test = set(split.get("test", []))

    if train & validation:
        raise ValueError("Leakage between train and validation sets.")
    if train & test:
        raise ValueError("Leakage between train and test sets.")
    if validation & test:
        raise ValueError("Leakage between validation and test sets.")
