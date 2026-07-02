"""Runtime profile classifier wrapping Phase 3 model artifacts."""

from __future__ import annotations

import json
import pickle
from pathlib import Path
from typing import Any

import numpy as np
import torch

from src.features.fast_features import FEATURE_SET_B_COLUMNS, extract_set_b_features
from src.models.profile_mlp import ProfileMLP
from src.models.model_io import load_model_artifacts


class ProfileClassifier:
    """Fast profile inference from text chunk using Phase 3 model.

    Usage:
        classifier = ProfileClassifier(phase3_dir)
        profile_id, confidence = classifier.classify("some text chunk...")
    """

    def __init__(self, phase3_dir: Path, device: str = "cpu") -> None:
        self.model, self.scaler, self.label_map = load_model_artifacts(
            phase3_dir, device=device,
        )
        self.model.eval()
        self.device = device
        # Build reverse map: class_index -> profile_id
        self.idx_to_profile: dict[int, str] = {
            int(k): v for k, v in self.label_map.items()
        }
        self.num_classes = len(self.idx_to_profile)
        self._feat_cols = FEATURE_SET_B_COLUMNS
        self._n_features = len(self._feat_cols)

    def features(self, text: str) -> np.ndarray:
        """Extract and scale Set B features for a text chunk.

        Returns (1, n_features) numpy array ready for model input.
        """
        raw = extract_set_b_features(text)
        vec = np.array([raw[col] for col in self._feat_cols], dtype=np.float32).reshape(1, -1)
        return self.scaler.transform(vec)

    def classify(self, text: str) -> tuple[str, float]:
        """Return (profile_id, confidence) for a text chunk."""
        x = self.features(text)
        x_t = torch.from_numpy(x).to(self.device)

        with torch.no_grad():
            logits = self.model(x_t)
            probs = torch.softmax(logits, dim=1)
            confidence, pred_idx = probs.max(dim=1)

        profile_id = self.idx_to_profile[int(pred_idx.item())]
        return profile_id, float(confidence.item())

    def classify_batch(self, texts: list[str]) -> list[tuple[str, float]]:
        """Classify multiple chunks at once (more efficient)."""
        vecs = np.vstack([self.features(t) for t in texts])
        x_t = torch.from_numpy(vecs).to(self.device)

        with torch.no_grad():
            logits = self.model(x_t)
            probs = torch.softmax(logits, dim=1)
            confidences, pred_indices = probs.max(dim=1)

        results = []
        for i in range(len(texts)):
            pid = self.idx_to_profile[int(pred_indices[i].item())]
            results.append((pid, float(confidences[i].item())))
        return results

    def classify_with_logits(self, text: str) -> tuple[dict[str, float], np.ndarray]:
        """Return {profile_id: confidence} dict and raw logits for analysis."""
        x = self.features(text)
        x_t = torch.from_numpy(x).to(self.device)

        with torch.no_grad():
            logits = self.model(x_t)
            probs = torch.softmax(logits, dim=1).cpu().numpy()[0]

        confidences = {
            self.idx_to_profile[i]: float(probs[i])
            for i in range(self.num_classes)
        }
        return confidences, logits.cpu().numpy()[0]
