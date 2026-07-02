"""Shared link prediction metrics built around the official OGB evaluator."""

from collections.abc import Iterable, Mapping
from typing import Any


DEFAULT_DATASET_NAME = "ogbl-collab"
DEFAULT_HITS_KS = (10, 50, 100)


def metric_key_for_hits(k: int) -> str:
    """Return the project-standard key for a Hits@K value."""
    return f"hits_at_{k}"


def _as_evaluator_array(scores: Any) -> Any:
    """Convert plain Python score sequences into an evaluator-compatible array."""
    if hasattr(scores, "detach"):
        return scores
    if hasattr(scores, "ndim"):
        return scores

    import numpy as np

    return np.asarray(scores, dtype=float)


def compute_hits_at_k(
    y_pred_pos: Any,
    y_pred_neg: Any,
    k: int,
    dataset_name: str = DEFAULT_DATASET_NAME,
) -> float:
    """Compute official OGB Hits@K for positive and negative edge scores."""
    from ogb.linkproppred import Evaluator

    evaluator = Evaluator(name=dataset_name)
    evaluator.K = k
    result = evaluator.eval(
        {
            "y_pred_pos": _as_evaluator_array(y_pred_pos),
            "y_pred_neg": _as_evaluator_array(y_pred_neg),
        }
    )
    return float(result[f"hits@{k}"])


def compute_hits_at_50(
    y_pred_pos: Any,
    y_pred_neg: Any,
    dataset_name: str = DEFAULT_DATASET_NAME,
) -> float:
    """Compute the primary project metric, official OGB Hits@50."""
    return compute_hits_at_k(
        y_pred_pos=y_pred_pos,
        y_pred_neg=y_pred_neg,
        k=50,
        dataset_name=dataset_name,
    )


def evaluate_link_prediction(
    positive_scores: Mapping[str, Any],
    negative_scores: Mapping[str, Any],
    ks: Iterable[int] = DEFAULT_HITS_KS,
    dataset_name: str = DEFAULT_DATASET_NAME,
) -> dict[str, dict[str, float]]:
    """Evaluate link prediction scores for every split present in both maps."""
    metrics: dict[str, dict[str, float]] = {}

    for split_name, split_positive_scores in positive_scores.items():
        if split_name not in negative_scores:
            continue

        split_negative_scores = negative_scores[split_name]
        metrics[split_name] = {
            metric_key_for_hits(k): compute_hits_at_k(
                y_pred_pos=split_positive_scores,
                y_pred_neg=split_negative_scores,
                k=k,
                dataset_name=dataset_name,
            )
            for k in ks
        }

    return metrics
