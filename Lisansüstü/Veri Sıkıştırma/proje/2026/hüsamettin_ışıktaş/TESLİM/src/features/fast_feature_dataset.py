"""Prepare Set B feature dataset for MLP profile classifier training.

Loads filtered_dataset.parquet from Phase 1, extracts fast (Set B)
features and profile_id labels, splits train/val/test (80/10/10),
and fits a StandardScaler on training data only.
"""

from __future__ import annotations

import logging
from pathlib import Path

import numpy as np
import pandas as pd
from sklearn.preprocessing import StandardScaler

from src.features.fast_features import FEATURE_SET_B_COLUMNS

logger = logging.getLogger(__name__)

META_COLUMNS = {
    "book_id", "chunk_id", "chunk_index", "split",
    "chunk_size_chars", "source_text_length", "profile_id",
}


class ProfileDataset:
    """Holds train/val/test splits with scaled Set B features."""

    def __init__(
        self,
        X_train: np.ndarray,
        y_train: np.ndarray,
        X_val: np.ndarray,
        y_val: np.ndarray,
        X_test: np.ndarray,
        y_test: np.ndarray,
        scaler: StandardScaler,
        label_map: dict[int, str],
        profile_order: list[str],
    ) -> None:
        self.X_train = X_train
        self.y_train = y_train
        self.X_val = X_val
        self.y_val = y_val
        self.X_test = X_test
        self.y_test = y_test
        self.scaler = scaler
        self.label_map = label_map          # class_index (int) -> profile_id (str)
        self.profile_order = profile_order  # ordered profile_ids

    @property
    def input_dim(self) -> int:
        return self.X_train.shape[1]

    @property
    def num_classes(self) -> int:
        return len(self.profile_order)


def build_profile_dataset(
    filtered_dataset_path: Path,
    random_state: int = 42,
) -> ProfileDataset:
    """Load Phase 1 data, split, scale, and return a ProfileDataset."""

    logger.info("Loading filtered dataset from %s", filtered_dataset_path)
    df = pd.read_parquet(filtered_dataset_path)

    if "profile_id" not in df.columns:
        raise ValueError("filtered_dataset.parquet must contain 'profile_id'")

    # --- Feature columns (Set B only) ---
    feature_cols = [c for c in FEATURE_SET_B_COLUMNS if c in df.columns]
    logger.info("Set B features: %d columns", len(feature_cols))

    # --- Train / Val / Test split ---
    train_df = df[df["split"] == "train"].copy()
    val_df = df[df["split"] == "val"].copy()
    test_df = df[df["split"] == "test"].copy()

    # If no explicit val/test splits exist, create them from train
    if val_df.empty or test_df.empty:
        logger.info("No explicit val/test split — creating 80/10/10 from full data")
        from sklearn.model_selection import train_test_split

        all_idx = np.arange(len(df))
        train_idx, rest_idx = train_test_split(all_idx, test_size=0.2, random_state=random_state, stratify=df["profile_id"])
        val_idx, test_idx = train_test_split(rest_idx, test_size=0.5, random_state=random_state, stratify=df.iloc[rest_idx]["profile_id"])

        train_df = df.iloc[train_idx].copy()
        val_df = df.iloc[val_idx].copy()
        test_df = df.iloc[test_idx].copy()

    logger.info("Split sizes — train: %d  val: %d  test: %d", len(train_df), len(val_df), len(test_df))

    # --- Encode labels ---
    profile_order = sorted(df["profile_id"].unique().tolist())
    label_to_idx = {pid: i for i, pid in enumerate(profile_order)}
    label_map = {i: pid for pid, i in label_to_idx.items()}

    logger.info("Profiles: %s", profile_order)

    def _encode(frame: pd.DataFrame) -> tuple[np.ndarray, np.ndarray]:
        X = frame[feature_cols].to_numpy(dtype=np.float32)
        y = np.array([label_to_idx[pid] for pid in frame["profile_id"]], dtype=np.int64)
        return X, y

    X_train_raw, y_train = _encode(train_df)
    X_val_raw, y_val = _encode(val_df)
    X_test_raw, y_test = _encode(test_df)

    # --- Scale (fit only on training data) ---
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train_raw).astype(np.float32)
    X_val = scaler.transform(X_val_raw).astype(np.float32)
    X_test = scaler.transform(X_test_raw).astype(np.float32)

    logger.info("Feature matrix shapes — train: %s  val: %s  test: %s", X_train.shape, X_val.shape, X_test.shape)

    return ProfileDataset(
        X_train=X_train,
        y_train=y_train,
        X_val=X_val,
        y_val=y_val,
        X_test=X_test,
        y_test=y_test,
        scaler=scaler,
        label_map=label_map,
        profile_order=profile_order,
    )
