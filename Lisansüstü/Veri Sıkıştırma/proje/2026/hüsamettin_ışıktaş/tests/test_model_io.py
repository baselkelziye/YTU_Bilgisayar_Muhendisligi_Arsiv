"""Tests for model artifact save/load consistency."""

import json
import pickle
import tempfile
from pathlib import Path

import numpy as np
import torch
from sklearn.preprocessing import StandardScaler

from src.models.model_io import load_model_artifacts, save_model_artifacts
from src.models.profile_mlp import ProfileMLP


class TestModelIO:
    def test_save_and_load_state_dict(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            out_dir = Path(tmp)

            model = ProfileMLP(input_dim=10, num_classes=8)
            scaler = StandardScaler()
            scaler.fit(np.random.randn(100, 10).astype(np.float32))
            label_map = {i: f"profile_{i}" for i in range(8)}

            # Save
            save_model_artifacts(model, scaler, label_map, out_dir)

            # Check files exist
            assert (out_dir / "model.pt").exists()
            assert (out_dir / "scaler.pkl").exists()
            assert (out_dir / "label_map.json").exists()

            # Load
            loaded_model, loaded_scaler, loaded_label_map = load_model_artifacts(
                out_dir, input_dim=10, num_classes=8
            )

            # Check label map
            assert loaded_label_map == label_map

            # Check scaler
            assert loaded_scaler.n_features_in_ == 10
            assert np.allclose(loaded_scaler.mean_, scaler.mean_)

            # Check model params match
            for (n1, p1), (n2, p2) in zip(model.named_parameters(), loaded_model.named_parameters()):
                assert n1 == n2
                assert torch.allclose(p1, p2)

    def test_save_and_load_torchscript(self) -> None:
        with tempfile.TemporaryDirectory() as tmp:
            out_dir = Path(tmp)

            model = ProfileMLP(input_dim=10, num_classes=4)
            scaler = StandardScaler()
            scaler.fit(np.random.randn(50, 10).astype(np.float32))
            label_map = {i: f"p{i}" for i in range(4)}

            save_model_artifacts(model, scaler, label_map, out_dir)

            # TorchScript model should exist
            assert (out_dir / "model_scripted.pt").exists()

            # Load (should prefer scripted)
            loaded_model, _, _ = load_model_artifacts(out_dir)
            assert isinstance(loaded_model, torch.jit.ScriptModule)

            # Same output
            x = torch.randn(2, 10)
            model.eval()
            with torch.no_grad():
                expected = model(x)
                got = loaded_model(x)
            assert torch.allclose(expected, got, atol=1e-6)

    def test_infer_dimensions(self) -> None:
        """Load without input_dim/num_classes should infer from saved artifacts."""
        with tempfile.TemporaryDirectory() as tmp:
            out_dir = Path(tmp)

            model = ProfileMLP(input_dim=10, num_classes=6)
            scaler = StandardScaler()
            scaler.fit(np.random.randn(50, 10).astype(np.float32))
            label_map = {i: f"p{i}" for i in range(6)}

            save_model_artifacts(model, scaler, label_map, out_dir)

            # Load without explicit dims
            loaded_model, loaded_scaler, loaded_lm = load_model_artifacts(out_dir)
            # TorchScript doesn't preserve input_dim as attribute
            # but should still produce correct output shape
            x = torch.randn(2, 10)
            out = loaded_model(x)
            assert out.shape == (2, 6)
            assert len(loaded_lm) == 6
