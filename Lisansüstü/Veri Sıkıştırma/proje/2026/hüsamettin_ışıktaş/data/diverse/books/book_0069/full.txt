"""Save/load helpers for Phase 3 model artifacts.

Produces:
  - model.pt          : torch.jit.script (or state_dict)
  - scaler.pkl        : sklearn StandardScaler
  - label_map.json    : {class_index: profile_id}
"""

from __future__ import annotations

import json
import logging
import pickle
from pathlib import Path
from typing import Any

import torch
from sklearn.preprocessing import StandardScaler

from src.models.profile_mlp import ProfileMLP

logger = logging.getLogger(__name__)


def save_model_artifacts(
    model: ProfileMLP,
    scaler: StandardScaler,
    label_map: dict[int, str],
    output_dir: Path,
) -> None:
    """Save all Phase 3 artifacts to output_dir."""
    output_dir.mkdir(parents=True, exist_ok=True)

    # Model weights (state_dict — portable across Python versions)
    model_path = output_dir / "model.pt"
    torch.save(model.state_dict(), model_path)
    logger.info("Model saved to %s", model_path)

    # Optional: TorchScript for deployment
    try:
        script_path = output_dir / "model_scripted.pt"
        model.eval()
        example = torch.randn(1, model.input_dim)
        scripted = torch.jit.trace(model, example)
        torch.jit.save(scripted, script_path)
        logger.info("Scripted model saved to %s", script_path)
    except Exception as exc:
        logger.warning("TorchScript export skipped: %s", exc)

    # Scaler
    scaler_path = output_dir / "scaler.pkl"
    with open(scaler_path, "wb") as f:
        pickle.dump(scaler, f)
    logger.info("Scaler saved to %s", scaler_path)

    # Label map
    label_path = output_dir / "label_map.json"
    with open(label_path, "w", encoding="utf-8") as f:
        json.dump(label_map, f, indent=2, ensure_ascii=False)
    logger.info("Label map saved to %s", label_path)


def load_model_artifacts(
    input_dir: Path,
    input_dim: int | None = None,
    num_classes: int | None = None,
    device: str = "cpu",
) -> tuple[ProfileMLP, StandardScaler, dict[int, str]]:
    """Load Phase 3 artifacts from input_dir.

    If input_dim/num_classes are provided the model is instantiated and
    state_dict is loaded.  If not provided, tries to infer from the saved
    artifacts.
    """
    # Label map
    label_path = input_dir / "label_map.json"
    with open(label_path, "r", encoding="utf-8") as f:
        label_map_raw = json.load(f)
    # JSON keys are strings — convert to int
    label_map = {int(k): v for k, v in label_map_raw.items()}

    # Scaler
    scaler_path = input_dir / "scaler.pkl"
    with open(scaler_path, "rb") as f:
        scaler = pickle.load(f)

    # Model
    model_path = input_dir / "model.pt"

    # Try scripted first
    scripted_path = input_dir / "model_scripted.pt"
    if scripted_path.exists():
        model = torch.jit.load(str(scripted_path), map_location=device)
        logger.info("Loaded TorchScript model from %s", scripted_path)
    else:
        if input_dim is None or num_classes is None:
            # Infer from label map and scaler
            num_classes = max(label_map.keys()) + 1
            input_dim = scaler.n_features_in_
        model = ProfileMLP(input_dim=input_dim, num_classes=num_classes).to(device)
        state = torch.load(model_path, map_location=device, weights_only=True)
        model.load_state_dict(state)
        model.eval()
        logger.info("Loaded state_dict model from %s", model_path)

    return model, scaler, label_map
