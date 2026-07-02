"""Evaluation utilities for ProfileMLP classifier."""

from __future__ import annotations

import json
import logging
import time
from typing import Any

import numpy as np
import pandas as pd
import torch
from sklearn.metrics import (
    accuracy_score,
    classification_report,
    f1_score,
    top_k_accuracy_score,
)

from src.models.profile_mlp import ProfileMLP

logger = logging.getLogger(__name__)


def evaluate_model(
    model: ProfileMLP,
    X: np.ndarray,
    y: np.ndarray,
    label_map: dict[int, str],
    device: str = "cpu",
    n_warmup: int = 50,
    n_measure: int = 500,
) -> dict[str, Any]:
    """Compute accuracy, F1, top-3 accuracy, confusion matrix, and inference time."""

    model.eval()
    model.to(device)

    # Predictions (batched for large datasets)
    batch_size = 1024
    all_preds: list[int] = []
    with torch.no_grad():
        for start in range(0, len(X), batch_size):
            xb = torch.from_numpy(X[start : start + batch_size]).to(device)
            logits = model(xb)
            preds = logits.argmax(dim=1).cpu().numpy().tolist()
            all_preds.extend(preds)

    preds = np.array(all_preds, dtype=np.int64)
    y_true = np.asarray(y, dtype=np.int64)

    # Metrics
    accuracy = float(accuracy_score(y_true, preds))
    macro_f1 = float(f1_score(y_true, preds, average="macro"))

    # Top-k: need probs
    all_probs: list[np.ndarray] = []
    with torch.no_grad():
        for start in range(0, len(X), batch_size):
            xb = torch.from_numpy(X[start : start + batch_size]).to(device)
            logits = model(xb)
            probs = torch.softmax(logits, dim=1).cpu().numpy()
            all_probs.append(probs)
    probs = np.concatenate(all_probs, axis=0)

    top3 = float(top_k_accuracy_score(y_true, probs, k=min(3, probs.shape[1]), labels=np.arange(probs.shape[1])))

    # Per-class metrics
    profile_names = [label_map[i] for i in range(len(label_map))]
    cls_report = classification_report(y_true, preds, target_names=profile_names, output_dict=True, zero_division=0)

    # Confusion matrix
    from sklearn.metrics import confusion_matrix
    cm = confusion_matrix(y_true, preds)
    cm_df = pd.DataFrame(cm, index=profile_names, columns=profile_names)

    # Inference time
    device = next(model.parameters()).device
    sample = torch.from_numpy(X[:1]).to(device)
    model.train()  # temporarily disable eval() overhead in measurements

    # Warmup
    for _ in range(n_warmup):
        _ = model(sample)

    times_ms: list[float] = []
    for _ in range(n_measure):
        t0 = time.perf_counter()
        _ = model(sample)
        times_ms.append((time.perf_counter() - t0) * 1000)

    model.eval()

    return {
        "accuracy": accuracy,
        "macro_f1": macro_f1,
        "top3_accuracy": top3,
        "num_classes": len(label_map),
        "num_samples": int(len(X)),
        "inference_mean_ms": float(np.mean(times_ms)),
        "inference_std_ms": float(np.std(times_ms)),
        "inference_p99_ms": float(np.percentile(times_ms, 99)),
        "per_class": cls_report,
        "confusion_matrix": cm_df.to_dict(),
    }


def save_metrics_json(metrics: dict[str, Any], path: str) -> None:
    """Write metrics dict to JSON, handling numpy types."""
    def _convert(obj: Any) -> Any:
        if isinstance(obj, (np.floating,)):
            return float(obj)
        if isinstance(obj, (np.integer,)):
            return int(obj)
        if isinstance(obj, dict):
            return {k: _convert(v) for k, v in obj.items()}
        return obj

    with open(path, "w", encoding="utf-8") as f:
        json.dump(_convert(metrics), f, indent=2, ensure_ascii=False)
    logger.info("Metrics written to %s", path)
