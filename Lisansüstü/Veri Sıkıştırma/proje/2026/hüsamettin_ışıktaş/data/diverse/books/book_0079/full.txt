"""Neural Compressor — character-level LSTM + arithmetic coding.

Implements the "prediction = compression" principle:
  1. Train a small LSTM to predict next-character probabilities
  2. Use arithmetic coding driven by those probabilities
  3. The better the prediction, the better the compression

This is a self-contained compressor — it needs to train on the corpus first.
"""

from __future__ import annotations

import json
import math
import pickle
import time
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Optional

import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader, TensorDataset


# ---------------------------------------------------------------------------
# Character-level tokenizer
# ---------------------------------------------------------------------------

class CharTokenizer:
    """Maps characters <-> integer indices. Fixed vocab of 256 byte values."""

    VOCAB_SIZE = 256

    def encode(self, text: str) -> list[int]:
        return [min(ord(c), 255) for c in text]

    def decode(self, ids: list[int]) -> str:
        return "".join(chr(i) for i in ids)


# ---------------------------------------------------------------------------
# LSTM Model
# ---------------------------------------------------------------------------

class CharLSTM(nn.Module):
    """Character-level LSTM language model.

    Args:
        vocab_size: Number of unique characters (256 for byte-level)
        embed_dim: Embedding dimension
        hidden_dim: LSTM hidden dimension
        n_layers: Number of LSTM layers
        dropout: Dropout rate
    """

    def __init__(
        self,
        vocab_size: int = 256,
        embed_dim: int = 64,
        hidden_dim: int = 128,
        n_layers: int = 2,
        dropout: float = 0.1,
    ):
        super().__init__()
        self.vocab_size = vocab_size
        self.hidden_dim = hidden_dim
        self.n_layers = n_layers

        self.embedding = nn.Embedding(vocab_size, embed_dim)
        self.lstm = nn.LSTM(
            embed_dim, hidden_dim, n_layers,
            batch_first=True, dropout=dropout if n_layers > 1 else 0,
        )
        self.dropout = nn.Dropout(dropout)
        self.fc = nn.Linear(hidden_dim, vocab_size)

    def forward(self, x: torch.Tensor, hidden=None):
        """x: (batch, seq_len) → logits: (batch, seq_len, vocab_size)"""
        emb = self.embedding(x)  # (B, S, E)
        lstm_out, hidden = self.lstm(emb, hidden)  # (B, S, H)
        lstm_out = self.dropout(lstm_out)
        logits = self.fc(lstm_out)  # (B, S, V)
        return logits, hidden

    def get_probs(self, x: torch.Tensor) -> torch.Tensor:
        """Get probability distribution for next character given context.
        
        x: (1, seq_len) — single sequence
        Returns: (1, vocab_size) — probabilities for next char
        """
        with torch.no_grad():
            logits, _ = self.forward(x.unsqueeze(0))
            # Only need the last position's prediction
            last_logits = logits[0, -1, :]  # (vocab_size,)
            probs = F.softmax(last_logits, dim=-1)
        return probs


# ---------------------------------------------------------------------------
# Training
# ---------------------------------------------------------------------------

def train_model(
    texts: list[str],
    model_dir: Path,
    seq_len: int = 128,
    batch_size: int = 64,
    epochs: int = 20,
    lr: float = 1e-3,
    embed_dim: int = 64,
    hidden_dim: int = 128,
    n_layers: int = 2,
) -> tuple[CharLSTM, dict]:
    """Train character-level LSTM on corpus.

    Returns trained model and training metrics.
    """
    tokenizer = CharTokenizer()
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    # Encode all text
    print(f"  Encoding {len(texts):,} texts...")
    all_ids = []
    for text in texts:
        all_ids.extend(tokenizer.encode(text))

    # Create training sequences
    print(f"  Creating training sequences (seq_len={seq_len})...")
    data = torch.tensor(all_ids[:5_000_000], dtype=torch.long)  # Cap at 5M tokens

    # Create input/target pairs
    n_sequences = len(data) - seq_len
    indices = np.random.choice(n_sequences, min(100_000, n_sequences), replace=False)
    
    inputs = []
    targets = []
    for idx in indices:
        inputs.append(data[idx:idx + seq_len])
        targets.append(data[idx + 1:idx + seq_len + 1])

    X = torch.stack(inputs)
    y = torch.stack(targets)

    # Split
    n_train = int(len(X) * 0.9)
    train_dataset = TensorDataset(X[:n_train], y[:n_train])
    val_dataset = TensorDataset(X[n_train:], y[n_train:])
    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    val_loader = DataLoader(val_dataset, batch_size=batch_size)

    # Model
    model = CharLSTM(
        vocab_size=256,
        embed_dim=embed_dim,
        hidden_dim=hidden_dim,
        n_layers=n_layers,
        dropout=0.1,
    ).to(device)

    optimizer = torch.optim.AdamW(model.parameters(), lr=lr, weight_decay=1e-5)
    scheduler = torch.optim.lr_scheduler.CosineAnnealingLR(optimizer, epochs)
    criterion = nn.CrossEntropyLoss()

    history = {"train_loss": [], "val_loss": [], "val_bpb": []}

    print(f"  Training on {device} ({sum(p.numel() for p in model.parameters()):,} params)...")
    best_val_loss = float("inf")

    for epoch in range(epochs):
        # Train
        model.train()
        total_loss = 0.0
        for batch_x, batch_y in train_loader:
            batch_x, batch_y = batch_x.to(device), batch_y.to(device)
            optimizer.zero_grad()
            logits, _ = model(batch_x)  # (B, S, V)
            loss = criterion(logits.reshape(-1, 256), batch_y.reshape(-1))
            loss.backward()
            torch.nn.utils.clip_grad_norm_(model.parameters(), 1.0)
            optimizer.step()
            total_loss += loss.item()

        avg_train_loss = total_loss / len(train_loader)
        history["train_loss"].append(avg_train_loss)

        # Validate
        model.eval()
        total_val_loss = 0.0
        with torch.no_grad():
            for batch_x, batch_y in val_loader:
                batch_x, batch_y = batch_x.to(device), batch_y.to(device)
                logits, _ = model(batch_x)
                loss = criterion(logits.reshape(-1, 256), batch_y.reshape(-1))
                total_val_loss += loss.item()

        avg_val_loss = total_val_loss / len(val_loader)
        history["val_loss"].append(avg_val_loss)
        # BPB = cross-entropy loss in nats → convert to bits (log2(e))
        bpb = avg_val_loss / math.log(2)
        history["val_bpb"].append(bpb)

        scheduler.step()

        if avg_val_loss < best_val_loss:
            best_val_loss = avg_val_loss
            torch.save(model.state_dict(), model_dir / "best_model.pt")

        if (epoch + 1) % 5 == 0 or epoch == 0:
            print(f"    Epoch {epoch+1:3d}/{epochs} | "
                  f"Train loss: {avg_train_loss:.4f} | "
                  f"Val loss: {avg_val_loss:.4f} | "
                  f"Val BPB: {bpb:.4f}")

    # Load best
    model.load_state_dict(torch.load(model_dir / "best_model.pt", weights_only=True))
    best_bpb = min(history["val_bpb"])

    print(f"  ✅ Training complete. Best val BPB: {best_bpb:.4f}")

    return model, {"history": history, "best_bpb": best_bpb, "params": sum(p.numel() for p in model.parameters())}


# ---------------------------------------------------------------------------
# Arithmetic coder driven by neural probabilities
# ---------------------------------------------------------------------------

class NeuralArithmeticCoder:
    """Arithmetic coding that uses LSTM probability predictions."""

    def __init__(self, model: CharLSTM, seq_len: int = 256):
        self.model = model
        self.seq_len = seq_len
        self.device = next(model.parameters()).device
        self.model.eval()

    def _get_prob_table(self, context: torch.Tensor) -> torch.Tensor:
        """Get probability distribution for next 256 symbols given context.

        context: (1, context_len) on device
        Returns: (256,) float tensor of probabilities
        """
        with torch.no_grad():
            logits, _ = self.model(context.unsqueeze(0))
            last_logits = logits[0, -1, :]
            probs = F.softmax(last_logits, dim=-1)
        return probs

    def compress(self, text: str) -> bytes:
        """Compress text using neural arithmetic coding."""
        tokenizer = CharTokenizer()
        ids = tokenizer.encode(text)
        
        if not ids:
            return b""
        
        n = len(ids)
        # Initialize context with zeros
        context = torch.zeros(min(self.seq_len, n + self.seq_len), dtype=torch.long, device=self.device)
        start_pos = min(self.seq_len, n)

        # For the first character, use uniform prior
        # We'll use the model starting from position seq_len
        context_pos = 0
        
        # Simple adaptive arithmetic coding
        # For efficiency, we use a simple range coder approach
        low = 0
        high = 0xFFFFFFFF
        range_size = 0x100000000
        
        output = bytearray()
        pending_bits = 0
        
        for i, symbol in enumerate(ids):
            if i < self.seq_len:
                # Fill initial context
                context[self.seq_len - 1 - i] = symbol if i < self.seq_len else 0
            
            # Get probs
            if i >= self.seq_len:
                ctx = context[i - self.seq_len:i]
                probs = self._get_prob_table(ctx)
            else:
                # Uniform for first seq_len chars
                probs = torch.ones(256, device=self.device) / 256
            
            # Cumulative distribution
            cum_prob = torch.cumsum(probs, dim=0)
            total = cum_prob[-1].item()
            
            if symbol == 0:
                sym_low = 0.0
            else:
                sym_low = cum_prob[symbol - 1].item()
            sym_high = cum_prob[symbol].item()
            
            # Rescale
            range_width = high - low + 1
            high = low + int(range_width * sym_high / total) - 1
            low = low + int(range_width * sym_low / total)
            
            # Renormalize
            while True:
                if high < 0x80000000:
                    output.append(0)
                    for _ in range(pending_bits):
                        output.append(0xFF)
                    pending_bits = 0
                    low = low * 2
                    high = high * 2 + 1
                elif low >= 0x80000000:
                    output.append(0xFF)
                    for _ in range(pending_bits):
                        output.append(0)
                    pending_bits = 0
                    low = (low - 0x80000000) * 2
                    high = (high - 0x80000000) * 2 + 1
                elif low >= 0x40000000 and high < 0xC0000000:
                    pending_bits += 1
                    low = (low - 0x40000000) * 2
                    high = (high - 0x40000000) * 2 + 1
                else:
                    break
            
            # Update context
            if i < len(context):
                context[i] = symbol
        
        # Flush
        pending_bits += 1
        if low < 0x40000000:
            output.append(0)
            for _ in range(pending_bits):
                output.append(0xFF)
        else:
            output.append(0xFF)
            for _ in range(pending_bits - 1):
                output.append(0)
        
        # Prepend original length
        header = len(text).to_bytes(4, "big")
        return header + bytes(output)

    def decompress(self, compressed: bytes) -> str:
        """Decompress neural arithmetic coded data."""
        if len(compressed) < 4:
            return ""
        
        original_len = int.from_bytes(compressed[:4], "big")
        data = compressed[4:]
        
        if original_len == 0:
            return ""
        
        context = torch.zeros(self.seq_len + original_len, dtype=torch.long, device=self.device)
        
        low = 0
        high = 0xFFFFFFFF
        
        # Read initial 4 bytes
        pos = 0
        value = 0
        for i in range(min(4, len(data))):
            value = (value << 8) | data[i]
            pos += 1
        
        output_ids = []
        
        for i in range(original_len):
            # Get probs
            if i >= self.seq_len:
                ctx = context[i - self.seq_len:i]
                probs = self._get_prob_table(ctx)
            else:
                probs = torch.ones(256, device=self.device) / 256
            
            cum_prob = torch.cumsum(probs, dim=0)
            total = cum_prob[-1].item()
            
            # Find symbol
            range_width = high - low + 1
            
            # Scale value to [0, total)
            scaled_value = int((value - low) * total / range_width)
            
            # Binary search for symbol
            symbol = 0
            for s in range(256):
                if scaled_value < cum_prob[s].item():
                    symbol = s
                    break
            
            output_ids.append(symbol)
            
            # Update ranges
            if symbol == 0:
                sym_low = 0.0
            else:
                sym_low = cum_prob[symbol - 1].item()
            sym_high = cum_prob[symbol].item()
            
            high = low + int(range_width * sym_high / total) - 1
            low = low + int(range_width * sym_low / total)
            
            # Renormalize
            while True:
                if high < 0x80000000:
                    pass
                elif low >= 0x80000000:
                    value -= 0x80000000
                    low -= 0x80000000
                    high -= 0x80000000
                elif low >= 0x40000000 and high < 0xC0000000:
                    value -= 0x40000000
                    low -= 0x40000000
                    high -= 0x40000000
                else:
                    break
                
                low *= 2
                high = high * 2 + 1
                if pos < len(data):
                    value = (value * 2) | ((data[pos] >> 7) & 1)
                    data_list = list(data)
                    data_list[pos] = (data_list[pos] << 1) & 0xFF
                    data = bytes(data_list)
                    # Check if byte exhausted
                    if data[pos] == 0:
                        pos += 1
            
            # Update context
            if i < len(context):
                context[i] = symbol
        
        tokenizer = CharTokenizer()
        return tokenizer.decode(output_ids)


# ---------------------------------------------------------------------------
# Compressor wrapper with CodecResult interface
# ---------------------------------------------------------------------------

@dataclass
class NeuralCodecResult:
    compressed: bytes
    compressed_size_bits: int
    original_size_bytes: int
    elapsed_ms: float
    valid: bool = True
    error: str | None = None

    @property
    def bpb(self) -> float:
        if self.original_size_bytes == 0:
            return 0.0
        return self.compressed_size_bits / self.original_size_bytes


class NeuralCompressor:
    """Full neural compressor: train LSTM → compress/decompress with arithmetic coding."""

    def __init__(self, model_path: Optional[Path] = None):
        self.model: Optional[CharLSTM] = None
        self.coder: Optional[NeuralArithmeticCoder] = None
        self.device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        
        if model_path and model_path.exists():
            self.load(model_path)

    def train(self, texts: list[str], model_dir: Path, **kwargs) -> dict:
        """Train the LSTM model on a corpus."""
        model_dir.mkdir(parents=True, exist_ok=True)
        self.model, metrics = train_model(texts, model_dir, **kwargs)
        self.model.to(self.device)
        self.model.eval()
        self.coder = NeuralArithmeticCoder(self.model)
        return metrics

    def load(self, model_path: Path):
        """Load a trained model."""
        state_dict = torch.load(model_path, map_location=self.device, weights_only=True)
        
        # Infer architecture from state dict
        embed_dim = state_dict["embedding.weight"].shape[1]
        hidden_dim = state_dict["lstm.weight_ih_l0"].shape[0] // 4
        
        # Count LSTM layers
        n_layers = 0
        for key in state_dict:
            if key.startswith("lstm.weight_ih_l"):
                n_layers = max(n_layers, int(key.split("_l")[1].split("_")[0]) + 1)

        self.model = CharLSTM(
            vocab_size=256,
            embed_dim=embed_dim,
            hidden_dim=hidden_dim,
            n_layers=n_layers,
        ).to(self.device)
        self.model.load_state_dict(state_dict)
        self.model.eval()
        self.coder = NeuralArithmeticCoder(self.model)

    def compress(self, data: bytes) -> NeuralCodecResult:
        """Compress bytes using neural arithmetic coding."""
        start = time.perf_counter()
        original_size = len(data)

        if self.coder is None:
            return NeuralCodecResult(
                compressed=b"", compressed_size_bits=0,
                original_size_bytes=original_size, elapsed_ms=0,
                valid=False, error="Model not loaded",
            )

        try:
            text = data.decode("utf-8", errors="replace")
            compressed = self.coder.compress(text)
        except Exception as exc:
            return NeuralCodecResult(
                compressed=b"", compressed_size_bits=0,
                original_size_bytes=original_size,
                elapsed_ms=(time.perf_counter() - start) * 1000,
                valid=False, error=str(exc),
            )

        elapsed = (time.perf_counter() - start) * 1000
        return NeuralCodecResult(
            compressed=compressed,
            compressed_size_bits=len(compressed) * 8,
            original_size_bytes=original_size,
            elapsed_ms=elapsed,
            valid=True,
        )

    def decompress(self, data: bytes) -> NeuralCodecResult:
        """Decompress neural arithmetic coded data."""
        start = time.perf_counter()

        if self.coder is None:
            return NeuralCodecResult(
                compressed=b"", compressed_size_bits=0,
                original_size_bytes=0, elapsed_ms=0,
                valid=False, error="Model not loaded",
            )

        try:
            text = self.coder.decompress(data)
            decompressed = text.encode("utf-8", errors="replace")
        except Exception as exc:
            return NeuralCodecResult(
                compressed=b"", compressed_size_bits=0,
                original_size_bytes=0,
                elapsed_ms=(time.perf_counter() - start) * 1000,
                valid=False, error=str(exc),
            )

        elapsed = (time.perf_counter() - start) * 1000
        return NeuralCodecResult(
            compressed=decompressed,
            compressed_size_bits=len(decompressed) * 8,
            original_size_bytes=len(data),
            elapsed_ms=elapsed,
            valid=True,
        )
