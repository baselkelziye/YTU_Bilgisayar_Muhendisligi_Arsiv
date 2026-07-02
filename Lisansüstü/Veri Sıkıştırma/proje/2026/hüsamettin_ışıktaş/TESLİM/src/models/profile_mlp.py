"""Lightweight 2-layer MLP for profile classification.

Architecture: Linear(in_dim -> 32) -> ReLU -> Dropout(0.1) -> Linear(32 -> num_classes)

Designed for fast inference (< 2ms per chunk) with Set B fast features.
"""

from __future__ import annotations

import torch
import torch.nn as nn


class ProfileMLP(nn.Module):
    """2-layer MLP profile classifier."""

    def __init__(self, input_dim: int, num_classes: int, hidden_dim: int = 32, dropout: float = 0.1) -> None:
        super().__init__()
        self.input_dim = input_dim
        self.num_classes = num_classes
        self.hidden_dim = hidden_dim

        self.net = nn.Sequential(
            nn.Linear(input_dim, hidden_dim),
            nn.ReLU(),
            nn.Dropout(dropout),
            nn.Linear(hidden_dim, num_classes),
        )

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        """Return logits of shape (batch, num_classes)."""
        return self.net(x)

    def predict(self, x: torch.Tensor) -> torch.Tensor:
        """Return class indices of shape (batch,)."""
        self.eval()
        with torch.no_grad():
            logits = self.forward(x)
            return logits.argmax(dim=-1)
