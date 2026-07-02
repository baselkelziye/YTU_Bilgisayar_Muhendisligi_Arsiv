"""Preprocessing helpers for OGB-style link prediction splits."""

from collections.abc import Iterable, Mapping
from copy import copy
from typing import Any


Edge = tuple[int, int]
Adjacency = dict[int, set[int]]


def _shape_of(edges: Any) -> tuple[int, ...] | None:
    shape = getattr(edges, "shape", None)
    if shape is None:
        return None
    return tuple(int(value) for value in shape)


def _to_python_edges(edges: Any) -> Any:
    if hasattr(edges, "detach"):
        edges = edges.detach().cpu()
    if hasattr(edges, "tolist"):
        return edges.tolist()
    return edges


def iter_edge_pairs(edges: Any) -> Iterable[Edge]:
    """Yield `(source, target)` pairs from tensor, array, or list edge formats."""
    shape = _shape_of(edges)
    python_edges = _to_python_edges(edges)

    if shape and len(shape) == 2 and shape[1] == 2:
        for source, target in python_edges:
            yield int(source), int(target)
        return

    if shape and len(shape) == 2 and shape[0] == 2:
        for source, target in zip(python_edges[0], python_edges[1], strict=False):
            yield int(source), int(target)
        return

    for source, target in python_edges:
        yield int(source), int(target)


def make_undirected_edge_index(edges: Any) -> list[Edge]:
    """Return a Python edge list containing both directions for every edge."""
    undirected_edges: list[Edge] = []
    for source, target in iter_edge_pairs(edges):
        undirected_edges.append((source, target))
        undirected_edges.append((target, source))
    return undirected_edges


def build_adjacency(edges: Any, make_undirected: bool = True) -> Adjacency:
    """Build an adjacency map from edge pairs."""
    adjacency: Adjacency = {}

    for source, target in iter_edge_pairs(edges):
        adjacency.setdefault(source, set()).add(target)
        if make_undirected:
            adjacency.setdefault(target, set()).add(source)

    return adjacency


def _sample_sequence(sequence: Any, indices: Any) -> Any:
    if hasattr(sequence, "index_select"):
        return sequence.index_select(0, indices)
    if hasattr(sequence, "iloc"):
        return sequence.iloc[indices]
    return [sequence[int(index)] for index in indices]


def sample_edges_by_scale(edges: Any, scale: float, seed: int = 42) -> Any:
    """Deterministically sample a prefix-sized fraction of an edge collection."""
    if not 0 < scale <= 1:
        raise ValueError("scale must be in the range (0, 1].")

    edge_count = len(edges)
    sample_count = max(1, int(edge_count * scale))
    if sample_count >= edge_count:
        return edges

    try:
        import torch

        generator = torch.Generator()
        generator.manual_seed(seed)
        indices = torch.randperm(edge_count, generator=generator)[:sample_count]
        return _sample_sequence(edges, indices)
    except ImportError:
        import random

        rng = random.Random(seed)
        indices = list(range(edge_count))
        rng.shuffle(indices)
        return _sample_sequence(edges, indices[:sample_count])


def make_scaled_split(
    split_edge: Mapping[str, Mapping[str, Any]],
    scale: float,
    seed: int = 42,
    splits_to_scale: tuple[str, ...] = ("train",),
) -> dict[str, dict[str, Any]]:
    """Return an OGB-style split with selected positive edge splits scaled."""
    scaled_split: dict[str, dict[str, Any]] = {}

    for split_name, split_values in split_edge.items():
        scaled_split[split_name] = dict(copy(split_values))
        if split_name in splits_to_scale and "edge" in split_values:
            scaled_split[split_name]["edge"] = sample_edges_by_scale(
                edges=split_values["edge"],
                scale=scale,
                seed=seed,
            )

    return scaled_split
