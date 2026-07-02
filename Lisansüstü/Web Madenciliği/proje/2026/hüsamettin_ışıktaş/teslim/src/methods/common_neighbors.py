"""Common Neighbors baseline for link prediction."""

from collections.abc import Iterable, Mapping
from dataclasses import dataclass
import logging
from typing import Any

from src.evaluation.metrics import DEFAULT_DATASET_NAME, DEFAULT_HITS_KS
from src.evaluation.metrics import evaluate_link_prediction
from src.evaluation.runtime import get_memory_usage_mb, track_resources
from src.experiments.progress import progress_bar


logger = logging.getLogger(__name__)


Adjacency = dict[int, set[int]]
Edge = tuple[int, int]


@dataclass(slots=True)
class CommonNeighborsModel:
    """Fitted Common Neighbors baseline state."""

    adjacency: Adjacency


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
    """Yield `(source, target)` pairs from common tensor, array, or list formats."""
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


def fit_common_neighbors(
    train_edges: Any,
    make_undirected: bool = True,
) -> CommonNeighborsModel:
    """Build an adjacency map from training edges."""
    adjacency: Adjacency = {}

    for source, target in progress_bar(iter_edge_pairs(train_edges), desc="CN fit"):
        adjacency.setdefault(source, set()).add(target)
        if make_undirected:
            adjacency.setdefault(target, set()).add(source)

    return CommonNeighborsModel(adjacency=adjacency)


def _common_neighbor_count(adjacency: Adjacency, source: int, target: int) -> int:
    source_neighbors = adjacency.get(source, set())
    target_neighbors = adjacency.get(target, set())

    if len(source_neighbors) > len(target_neighbors):
        source_neighbors, target_neighbors = target_neighbors, source_neighbors

    return sum(1 for neighbor in source_neighbors if neighbor in target_neighbors)


def _tie_breaker(source: int, target: int) -> float:
    stable_hash = (source * 1_000_003 + target * 97) % 1_000_000
    return stable_hash / 1_000_000_000_000_000


def score_edges_common_neighbors(
    model: CommonNeighborsModel,
    edges: Any,
    add_tie_breaker: bool = True,
    description: str = "CN scoring",
) -> list[float]:
    """Score candidate edges by their number of shared neighbors."""
    scores: list[float] = []

    for source, target in progress_bar(iter_edge_pairs(edges), desc=description):
        score = float(_common_neighbor_count(model.adjacency, source, target))
        if add_tie_breaker:
            score += _tie_breaker(source, target)
        scores.append(score)

    return scores


def _get_edges(split_edge: Mapping[str, Mapping[str, Any]], split: str, key: str) -> Any:
    return split_edge.get(split, {}).get(key)


def run_common_neighbors(
    split_edge: Mapping[str, Mapping[str, Any]],
    ks: Iterable[int] = DEFAULT_HITS_KS,
    dataset_name: str = DEFAULT_DATASET_NAME,
    make_undirected: bool = True,
    add_tie_breaker: bool = True,
) -> dict[str, Any]:
    """Fit and evaluate Common Neighbors using OGB-style edge splits."""
    start_memory_mb = get_memory_usage_mb()
    logger.info("Starting Common Neighbors")

    with track_resources() as usage:
        train_edges = _get_edges(split_edge, "train", "edge")
        if train_edges is None:
            raise ValueError("split_edge must contain train edge data.")

        model = fit_common_neighbors(
            train_edges=train_edges,
            make_undirected=make_undirected,
        )

        positive_scores: dict[str, list[float]] = {}
        negative_scores: dict[str, list[float]] = {}

        for split in ("valid", "test"):
            positive_edges = _get_edges(split_edge, split, "edge")
            negative_edges = _get_edges(split_edge, split, "edge_neg")

            if positive_edges is None or negative_edges is None:
                continue

            positive_scores[split] = score_edges_common_neighbors(
                model=model,
                edges=positive_edges,
                add_tie_breaker=add_tie_breaker,
                description=f"CN {split} positive",
            )
            negative_scores[split] = score_edges_common_neighbors(
                model=model,
                edges=negative_edges,
                add_tie_breaker=add_tie_breaker,
                description=f"CN {split} negative",
            )

        metrics = evaluate_link_prediction(
            positive_scores=positive_scores,
            negative_scores=negative_scores,
            ks=ks,
            dataset_name=dataset_name,
        )
        logger.info("Completed Common Neighbors metrics=%s", metrics)

    return {
        "method_name": "common_neighbors",
        "dataset_name": dataset_name,
        "metrics": metrics,
        "runtime_seconds": usage.runtime_seconds,
        "memory_mb": usage.end_memory_mb,
        "memory_delta_mb": usage.end_memory_mb - start_memory_mb,
        "config": {
            "make_undirected": make_undirected,
            "add_tie_breaker": add_tie_breaker,
            "ks": list(ks),
        },
        "status": "completed",
    }
