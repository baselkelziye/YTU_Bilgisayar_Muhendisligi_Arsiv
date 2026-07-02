"""Tests for ProfileMLP model forward and shape contracts."""

import numpy as np
import torch
import pytest

from src.models.profile_mlp import ProfileMLP


class TestProfileMLP:
    def test_forward_output_shape(self) -> None:
        model = ProfileMLP(input_dim=10, num_classes=8)
        x = torch.randn(4, 10)
        out = model(x)
        assert out.shape == (4, 8), f"Expected (4, 8), got {out.shape}"

    def test_predict_output_shape(self) -> None:
        model = ProfileMLP(input_dim=10, num_classes=8)
        x = torch.randn(4, 10)
        preds = model.predict(x)
        assert preds.shape == (4,), f"Expected (4,), got {preds.shape}"
        assert preds.dtype == torch.int64

    def test_single_sample(self) -> None:
        model = ProfileMLP(input_dim=10, num_classes=8)
        x = torch.randn(1, 10)
        out = model(x)
        assert out.shape == (1, 8)

    def test_different_input_dim(self) -> None:
        model = ProfileMLP(input_dim=15, num_classes=5)
        x = torch.randn(2, 15)
        out = model(x)
        assert out.shape == (2, 5)

    def test_forward_is_deterministic(self) -> None:
        model = ProfileMLP(input_dim=10, num_classes=8)
        model.eval()
        x = torch.randn(4, 10)
        out1 = model(x)
        out2 = model(x)
        # Same model, same input, eval mode → identical output
        assert torch.allclose(out1, out2, atol=1e-6)

    def test_gradients_flow(self) -> None:
        model = ProfileMLP(input_dim=10, num_classes=8)
        x = torch.randn(4, 10, requires_grad=True)
        out = model(x)
        loss = out.sum()
        loss.backward()
        assert x.grad is not None
        assert x.grad.shape == (4, 10)
        # All parameters should have gradients
        for name, param in model.named_parameters():
            assert param.grad is not None, f"Parameter {name} has no gradient"
