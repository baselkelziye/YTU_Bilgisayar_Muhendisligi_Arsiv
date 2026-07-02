"""Filtering utilities for low-confidence cluster assignments."""

from __future__ import annotations

import numpy as np
import pandas as pd
from sklearn.decomposition import PCA
from sklearn.metrics import silhouette_samples
from sklearn.preprocessing import StandardScaler


def _prepare_cluster_space(frame: pd.DataFrame, feature_columns: list[str]) -> np.ndarray:
    """Standardize + PCA-reduce to match the space KMeans was fit on.

    Must mirror kmeans_profiles._pca_reduce so silhouette and distance
    computations happen in the same reduced latent space.
    """
    raw = frame[feature_columns].to_numpy(dtype=float)
    scaled = StandardScaler().fit_transform(raw)
    n_comp = min(3, scaled.shape[1])
    if scaled.shape[1] <= n_comp:
        return scaled
    return PCA(n_components=n_comp, random_state=42).fit_transform(scaled)


def filter_clusters(
    frame: pd.DataFrame,
    feature_columns: list[str],
    label_column: str = "cluster_id",
    min_cluster_size: int = 5,
    silhouette_threshold: float = 0.3,
    outlier_quantile: float = 0.99,
) -> tuple[pd.DataFrame, dict[str, float]]:
    """Filter low-confidence rows based on silhouette and centroid distance."""
    if frame.empty:
        return frame.copy(), {"before": 0.0, "after": 0.0, "removed": 0.0}

    work = frame.copy()
    counts = work[label_column].value_counts()
    large_enough_clusters = set(counts[counts >= min_cluster_size].index)
    work["pass_min_cluster"] = work[label_column].isin(large_enough_clusters)

    # Use PCA-reduced space for silhouette and distance computations,
    # matching the space where KMeans was fit (see kmeans_profiles).
    cluster_space = _prepare_cluster_space(work, feature_columns)

    if len(counts) > 1 and len(work) > len(counts):
        work["silhouette"] = silhouette_samples(cluster_space, work[label_column])
    else:
        work["silhouette"] = 1.0
    work["pass_silhouette"] = work["silhouette"] >= silhouette_threshold

    # Centroids and distances in the same PCA-reduced space.
    n_dims = cluster_space.shape[1]
    pseudo_cols = [f"pc_{i}" for i in range(n_dims)]
    centroids = pd.DataFrame(cluster_space, columns=pseudo_cols).groupby(work[label_column]).mean()
    centers_for_rows = centroids.loc[work[label_column].to_numpy()].to_numpy(dtype=float)
    work["distance_to_centroid"] = np.linalg.norm(cluster_space - centers_for_rows, axis=1)
    cutoff = float(work["distance_to_centroid"].quantile(outlier_quantile))
    work["pass_outlier"] = work["distance_to_centroid"] <= cutoff

    work["is_high_confidence"] = work["pass_min_cluster"] & work["pass_silhouette"] & work["pass_outlier"]
    filtered = work[work["is_high_confidence"]].copy()

    summary = {
        "before": float(len(work)),
        "after": float(len(filtered)),
        "removed": float(len(work) - len(filtered)),
        "retention_ratio": float(len(filtered) / len(work)) if len(work) else 0.0,
        "distance_cutoff": cutoff,
        "silhouette_threshold": float(silhouette_threshold),
        "min_cluster_size": float(min_cluster_size),
    }
    return filtered, summary

