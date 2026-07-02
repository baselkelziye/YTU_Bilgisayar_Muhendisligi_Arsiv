"""Automatic profile naming from cluster centroids."""

from __future__ import annotations

import pandas as pd


def _label_from_centroid(row: pd.Series) -> str:
    entropy = float(row.get("entropy_char", 0.0))
    punctuation = float(row.get("punctuation_ratio", 0.0))
    digits = float(row.get("digit_ratio", 0.0))
    whitespace = float(row.get("whitespace_ratio", 0.0))
    zlib_ratio = float(row.get("zlib_compression_ratio", 1.0))

    tags: list[str] = []
    if entropy >= 4.5:
        tags.append("high_entropy")
    elif entropy <= 3.5:
        tags.append("low_entropy")
    else:
        tags.append("mid_entropy")

    if zlib_ratio < 0.55:
        tags.append("compressible")
    elif zlib_ratio > 0.80:
        tags.append("hard_to_compress")

    if digits > 0.08:
        tags.append("digit_heavy")
    if punctuation > 0.09:
        tags.append("punctuation_heavy")
    if whitespace > 0.22:
        tags.append("spaced_text")

    return "_".join(tags) if tags else "generic_text"


def build_profile_definitions(
    labeled_frame: pd.DataFrame,
    feature_columns: list[str],
    label_column: str = "cluster_id",
) -> list[dict[str, object]]:
    """Create profile definition objects from labeled data."""
    if labeled_frame.empty:
        return []

    centers = labeled_frame.groupby(label_column)[feature_columns].mean()
    sizes = labeled_frame[label_column].value_counts().to_dict()
    definitions: list[dict[str, object]] = []

    for cluster_id, row in centers.iterrows():
        profile_id = f"profile_{int(cluster_id)}"
        auto_label = _label_from_centroid(row)
        definitions.append(
            {
                "profile_id": profile_id,
                "cluster_id": int(cluster_id),
                "label": auto_label,
                "size": int(sizes.get(cluster_id, 0)),
                "center_vector": {col: float(row[col]) for col in feature_columns},
            }
        )
    return sorted(definitions, key=lambda item: item["cluster_id"])

