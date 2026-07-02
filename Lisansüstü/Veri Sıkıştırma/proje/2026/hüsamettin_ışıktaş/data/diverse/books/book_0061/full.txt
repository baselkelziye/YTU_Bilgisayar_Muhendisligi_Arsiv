"""Training loop for ProfileMLP with early stopping and checkpointing."""

from __future__ import annotations

import logging
from pathlib import Path
from typing import Any

import numpy as np
import pandas as pd
import torch
import torch.nn as nn
from torch.utils.data import DataLoader, TensorDataset

from src.models.profile_mlp import ProfileMLP

logger = logging.getLogger(__name__)


def train_profile_mlp(
    X_train: np.ndarray,
    y_train: np.ndarray,
    X_val: np.ndarray,
    y_val: np.ndarray,
    num_classes: int,
    batch_size: int = 256,
    lr: float = 1e-3,
    weight_decay: float = 1e-4,
    max_epochs: int = 100,
    patience: int = 7,
    device: str = "cpu",
    seed: int = 42,
) -> tuple[ProfileMLP, pd.DataFrame]:
    """Train ProfileMLP with early stopping on validation loss.

    Returns the best model (lowest val loss) and epoch-by-epoch history.
    """

    torch.manual_seed(seed)

    input_dim = X_train.shape[1]
    model = ProfileMLP(input_dim=input_dim, num_classes=num_classes).to(device)

    # DataLoaders
    train_ds = TensorDataset(torch.from_numpy(X_train), torch.from_numpy(y_train))
    val_ds = TensorDataset(torch.from_numpy(X_val), torch.from_numpy(y_val))
    train_loader = DataLoader(train_ds, batch_size=batch_size, shuffle=True, drop_last=False)
    val_loader = DataLoader(val_ds, batch_size=batch_size * 2, shuffle=False)

    criterion = nn.CrossEntropyLoss()
    optimizer = torch.optim.AdamW(model.parameters(), lr=lr, weight_decay=weight_decay)

    best_val_loss = float("inf")
    best_epoch = 0
    best_state = {k: v.cpu().clone() for k, v in model.state_dict().items()}
    patience_counter = 0

    history: list[dict[str, float]] = []

    logger.info("Training started — input_dim=%d num_classes=%d epochs=%d patience=%d", input_dim, num_classes, max_epochs, patience)

    for epoch in range(1, max_epochs + 1):
        # ---- Train ----
        model.train()
        train_loss = 0.0
        train_correct = 0
        train_total = 0

        for xb, yb in train_loader:
            xb, yb = xb.to(device), yb.to(device)
            optimizer.zero_grad()
            logits = model(xb)
            loss = criterion(logits, yb)
            loss.backward()
            optimizer.step()

            train_loss += loss.item() * len(xb)
            train_correct += (logits.argmax(dim=1) == yb).sum().item()
            train_total += len(xb)

        train_loss /= train_total
        train_acc = train_correct / train_total

        # ---- Validate ----
        model.eval()
        val_loss = 0.0
        val_correct = 0
        val_total = 0

        with torch.no_grad():
            for xb, yb in val_loader:
                xb, yb = xb.to(device), yb.to(device)
                logits = model(xb)
                loss = criterion(logits, yb)
                val_loss += loss.item() * len(xb)
                val_correct += (logits.argmax(dim=1) == yb).sum().item()
                val_total += len(xb)

        val_loss /= val_total
        val_acc = val_correct / val_total

        history.append({"epoch": epoch, "train_loss": train_loss, "train_acc": train_acc, "val_loss": val_loss, "val_acc": val_acc})

        # ---- Early stopping ----
        if val_loss < best_val_loss:
            best_val_loss = val_loss
            best_epoch = epoch
            best_state = {k: v.cpu().clone() for k, v in model.state_dict().items()}
            patience_counter = 0
            improved = "*"
        else:
            patience_counter += 1
            improved = ""

        logger.info(
            "Epoch %3d/%d  train_loss=%.4f  train_acc=%.4f  val_loss=%.4f  val_acc=%.4f %s",
            epoch, max_epochs, train_loss, train_acc, val_loss, val_acc, improved,
        )

        if patience_counter >= patience:
            logger.info("Early stopping at epoch %d (best val_loss=%.4f at epoch %d)", epoch, best_val_loss, best_epoch)
            break

    # Load best weights
    model.load_state_dict(best_state)
    model.eval()

    history_df = pd.DataFrame(history)
    logger.info("Training finished — best epoch=%d val_loss=%.4f", best_epoch, best_val_loss)

    return model, history_df
