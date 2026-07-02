"""Shared helpers for Streamlit UI pages."""

from __future__ import annotations

from functools import lru_cache
from typing import Any

from src.data.loader import load_collab_data_bundle


RUNNER_PRESETS: dict[str, dict[str, Any]] = {
    "smoke": {"epochs": 1, "batch_size": 4096},
    "default": {},
    "full": {"epochs": 200, "batch_size": 65536},
}


def require_streamlit() -> Any:
    import streamlit as st

    return st


@lru_cache(maxsize=1)
def load_bundle() -> Any:
    return load_collab_data_bundle()


def safe_len(values: Any) -> int:
    if hasattr(values, "shape") and len(getattr(values, "shape", [])) > 0:
        return int(values.shape[0])
    return int(len(values))


def split_count_rows(split_edge: dict[str, dict[str, Any]]) -> list[dict[str, Any]]:
    rows: list[dict[str, Any]] = []
    for split_name, split_values in split_edge.items():
        pos_edges = split_values.get("edge")
        neg_edges = split_values.get("edge_neg")
        rows.append(
            {
                "split": split_name,
                "positive_edges": safe_len(pos_edges) if pos_edges is not None else 0,
                "negative_edges": safe_len(neg_edges) if neg_edges is not None else 0,
            }
        )
    return rows
