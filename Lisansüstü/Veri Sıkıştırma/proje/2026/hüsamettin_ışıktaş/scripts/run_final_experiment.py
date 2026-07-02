"""FINAL COMPREHENSIVE EXPERIMENT — All requested features.

Data: 1000 Gutenberg + 148 diverse documents
Models: XGBoost + MLP-small/medium/large + MLP Ensemble
Metrics: BPB + speed (ms) per algorithm, per model
Plots: Algorithm comparison, model comparison, speed/BPB tradeoff,
       confusion matrices, training curves, per-domain breakdown
"""

from __future__ import annotations

import csv
import json
import math
import pickle
import re
import sys
import time
from collections import Counter, defaultdict
from pathlib import Path
from typing import Any

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix, f1_score
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, StandardScaler
from tqdm import tqdm

matplotlib.use("Agg")

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from src.codecs import arithmetic_codec, bwt_codec, huffman_codec, lzw_codec, rle_codec

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v3_final"
PLOTS_DIR = ARTIFACTS_DIR / "plots"

CHUNK_SIZE = 1024
MAX_CHUNKS = 15_000
RANDOM_SEED = 42

ALGORITHMS = ["huffman", "lzw", "arithmetic", "bwt_mtf", "rle_huffman"]
ALGO_PARAMS = {
    "huffman": {"order": 1},
    "lzw": {"max_bits": 14},
    "arithmetic": {"order": 0},  # order-0 to avoid huge headers on small chunks
    "bwt_mtf": {"secondary": "huffman", "block_size": 0},
    "rle_huffman": {"min_run": 4},
}
ALGO_COLORS = {
    "huffman": "#e74c3c", "lzw": "#3498db", "arithmetic": "#9b59b6",
    "bwt_mtf": "#2ecc71", "rle_huffman": "#f39c12",
    "ADAPTIVE": "#1abc9c", "XGBoost": "#e67e22",
}

_CODECS = {
    "huffman": huffman_codec, "lzw": lzw_codec,
    "arithmetic": arithmetic_codec, "bwt_mtf": bwt_codec,
    "rle_huffman": rle_codec,
}

# ---------------------------------------------------------------------------
# Features (21 fast features)
# ---------------------------------------------------------------------------

FEATURE_NAMES = [
    "n_chars", "n_lines", "n_words", "avg_word_len", "std_word_len",
    "unique_char_ratio", "unique_word_ratio", "digit_ratio", "whitespace_ratio",
    "punctuation_ratio", "uppercase_ratio", "vowel_ratio", "entropy_char",
    "bigram_repetition_ratio", "trigram_repetition_ratio", "longest_repeat_run",
    "newline_density", "mean_line_length", "std_line_length",
    "ascii_ratio", "non_ascii_ratio",
]


def extract_features(text: str) -> dict[str, float]:
    if not text:
        return {f: 0.0 for f in FEATURE_NAMES}
    chars = list(text)
    n = len(chars)
    import string as _string
    from collections import Counter as _Counter

    words = re.findall(r"\b\w+\b", text)
    n_words = len(words)
    word_lens = [len(w) for w in words] if words else [0]
    avg_word_len = np.mean(word_lens)
    std_word_len = np.std(word_lens) if len(word_lens) > 1 else 0.0
    unique_char_ratio = len(set(chars)) / n
    digit_ratio = sum(1 for c in chars if c.isdigit()) / n
    whitespace_ratio = sum(1 for c in chars if c.isspace()) / n
    punct = set(_string.punctuation)
    punctuation_ratio = sum(1 for c in chars if c in punct) / n
    uppercase_ratio = sum(1 for c in chars if c.isupper()) / n
    vowels = set("aeiouAEIOU")
    vowel_ratio = sum(1 for c in chars if c in vowels) / n
    cc = _Counter(chars)
    entropy_char = -sum((c / n) * math.log2(c / n) for c in cc.values())
    bigrams = [text[i:i+2] for i in range(n - 1)]
    bigram_rep = 1.0 - len(set(bigrams)) / len(bigrams) if bigrams else 0.0
    trigrams = [text[i:i+3] for i in range(n - 2)]
    trigram_rep = 1.0 - len(set(trigrams)) / len(trigrams) if trigrams else 0.0
    ascii_count = sum(1 for c in chars if 32 <= ord(c) <= 126 or ord(c) in (9, 10, 13))
    ascii_ratio = ascii_count / n
    non_ascii_ratio = 1.0 - ascii_ratio
    n_lines = text.count("\n") + 1
    newline_density = (n_lines - 1) / n
    lines = text.split("\n")
    line_lengths = [len(ln) for ln in lines]
    mean_line_length = np.mean(line_lengths) if line_lengths else 0
    std_line_length = np.std(line_lengths) if len(line_lengths) > 1 else 0
    unique_word_ratio = len(set(words)) / n_words if n_words else 0
    longest_repeat = 0
    if n >= 2:
        seen = set()
        for length in range(min(50, n), 1, -1):
            seen.clear()
            found = False
            for i in range(n - length + 1):
                sub = text[i:i+length]
                if sub in seen:
                    longest_repeat = length; found = True; break
                seen.add(sub)
            if found:
                break

    return {
        "n_chars": n, "n_lines": n_lines, "n_words": n_words,
        "avg_word_len": avg_word_len, "std_word_len": std_word_len,
        "unique_char_ratio": unique_char_ratio, "unique_word_ratio": unique_word_ratio,
        "digit_ratio": digit_ratio, "whitespace_ratio": whitespace_ratio,
        "punctuation_ratio": punctuation_ratio, "uppercase_ratio": uppercase_ratio,
        "vowel_ratio": vowel_ratio, "entropy_char": entropy_char,
        "bigram_repetition_ratio": bigram_rep, "trigram_repetition_ratio": trigram_rep,
        "longest_repeat_run": longest_repeat, "newline_density": newline_density,
        "mean_line_length": mean_line_length, "std_line_length": std_line_length,
        "ascii_ratio": ascii_ratio, "non_ascii_ratio": non_ascii_ratio,
    }


# ---------------------------------------------------------------------------
# Data loading
# ---------------------------------------------------------------------------

def load_all_corpus(max_chunks: int = MAX_CHUNKS) -> list[tuple[str, str]]:
    """Load all available text: Gutenberg (1000) + diverse (148). 
    Returns list of (domain, text)."""
    rng = np.random.RandomState(RANDOM_SEED)
    texts: list[tuple[str, str]] = []

    # Gutenberg
    processed = PROJECT_ROOT / "data" / "processed" / "books"
    if processed.exists():
        gutenberg_files = sorted(processed.glob("*.txt"))
        for f in gutenberg_files:
            t = f.read_text(encoding="utf-8", errors="replace")[:30000]
            if len(t) > 500:
                texts.append(("gutenberg", t))

    # Diverse
    manifest = PROJECT_ROOT / "data" / "diverse" / "manifest.csv"
    if manifest.exists():
        with open(manifest, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                p = PROJECT_ROOT / row["path"]
                if p.exists():
                    t = p.read_text(encoding="utf-8", errors="replace")
                    domain = row.get("domain", "diverse")
                    texts.append((domain, t))

    # Chunk and cap
    all_chunks: list[tuple[str, str]] = []
    indices = rng.permutation(len(texts))
    for idx in indices:
        domain, text = texts[idx]
        for i in range(0, len(text), CHUNK_SIZE):
            chunk = text[i:i + CHUNK_SIZE]
            if len(chunk) >= 100:
                all_chunks.append((domain, chunk))
                if len(all_chunks) >= max_chunks:
                    break
        if len(all_chunks) >= max_chunks:
            break

    return all_chunks[:max_chunks]


# ---------------------------------------------------------------------------
# Grid search (ground truth)
# ---------------------------------------------------------------------------

def run_grid_search(chunks: list[str]) -> list[dict]:
    """Run all algorithms on all chunks, record BPB + timing."""
    results = []
    for chunk in tqdm(chunks, desc="Grid search"):
        data = chunk.encode("utf-8")
        bpbs = {}
        times = {}
        for algo in ALGORITHMS:
            params = ALGO_PARAMS[algo]
            codec = _CODECS[algo]
            try:
                t0 = time.perf_counter()
                result = codec.compress(data, **{k: v for k, v in params.items() if k != "label"})
                elapsed = (time.perf_counter() - t0) * 1000
                bpbs[algo] = result.bpb if result.valid else 999.0
                times[algo] = elapsed
            except Exception:
                bpbs[algo] = 999.0
                times[algo] = 0

        best = min(bpbs, key=bpbs.get)
        feats = extract_features(chunk)
        results.append({
            "best_algo": best, "best_bpb": bpbs[best],
            "all_bpbs": bpbs, "all_times": times,
            "features": feats,
        })
    return results


# ---------------------------------------------------------------------------
# MLP models (PyTorch)
# ---------------------------------------------------------------------------

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader, TensorDataset


class MLPClassifier(nn.Module):
    def __init__(self, input_dim: int, hidden_dims: list[int], n_classes: int, dropout: float = 0.2):
        super().__init__()
        layers = []
        prev = input_dim
        for h in hidden_dims:
            layers.extend([nn.Linear(prev, h), nn.ReLU(), nn.BatchNorm1d(h), nn.Dropout(dropout)])
            prev = h
        layers.append(nn.Linear(prev, n_classes))
        self.net = nn.Sequential(*layers)

    def forward(self, x):
        return self.net(x)


def train_mlp(
    X_train, y_train, X_val, y_val,
    hidden_dims: list[int], n_classes: int,
    epochs: int = 100, lr: float = 1e-3, batch_size: int = 128,
    patience: int = 15, name: str = "MLP",
) -> tuple[MLPClassifier, dict]:
    device = torch.device("cpu")
    model = MLPClassifier(X_train.shape[1], hidden_dims, n_classes).to(device)

    train_ds = TensorDataset(torch.tensor(X_train, dtype=torch.float32),
                             torch.tensor(y_train, dtype=torch.long))
    val_ds = TensorDataset(torch.tensor(X_val, dtype=torch.float32),
                           torch.tensor(y_val, dtype=torch.long))
    train_loader = DataLoader(train_ds, batch_size=batch_size, shuffle=True)
    val_loader = DataLoader(val_ds, batch_size=batch_size)

    optimizer = torch.optim.AdamW(model.parameters(), lr=lr, weight_decay=1e-4)
    scheduler = torch.optim.lr_scheduler.CosineAnnealingLR(optimizer, epochs)
    criterion = nn.CrossEntropyLoss()

    history = {"train_loss": [], "val_loss": [], "val_acc": []}
    best_val_loss = float("inf")
    best_state = None
    no_improve = 0

    for epoch in range(epochs):
        model.train()
        total_loss = 0.0
        for bx, by in train_loader:
            bx, by = bx.to(device), by.to(device)
            optimizer.zero_grad()
            loss = criterion(model(bx), by)
            loss.backward()
            optimizer.step()
            total_loss += loss.item()
        history["train_loss"].append(total_loss / len(train_loader))

        model.eval()
        val_loss = 0.0
        correct = 0
        total = 0
        with torch.no_grad():
            for bx, by in val_loader:
                bx, by = bx.to(device), by.to(device)
                logits = model(bx)
                val_loss += criterion(logits, by).item()
                preds = logits.argmax(dim=1)
                correct += (preds == by).sum().item()
                total += by.size(0)
        history["val_loss"].append(val_loss / len(val_loader))
        history["val_acc"].append(correct / total)

        scheduler.step()

        if val_loss < best_val_loss:
            best_val_loss = val_loss
            best_state = {k: v.cpu().clone() for k, v in model.state_dict().items()}
            no_improve = 0
        else:
            no_improve += 1

        if no_improve >= patience:
            break

    model.load_state_dict(best_state)
    return model, {"history": history, "best_epoch": epoch - patience + 1,
                   "best_val_acc": max(history["val_acc"]),
                   "params": sum(p.numel() for p in model.parameters())}


def evaluate_model(model, X: np.ndarray, y: np.ndarray, le: LabelEncoder, device="cpu") -> dict:
    """Compute accuracy, F1, per-class metrics."""
    if isinstance(model, MLPClassifier):
        model.eval()
        with torch.no_grad():
            t = torch.tensor(X, dtype=torch.float32).to(device)
            logits = model(t)
            y_pred = logits.argmax(dim=1).cpu().numpy()
    else:
        y_pred = model.predict(X)

    acc = accuracy_score(y, y_pred)
    f1 = f1_score(y, y_pred, average="macro")
    report = classification_report(y, y_pred, target_names=le.classes_, output_dict=True, zero_division=0)
    return {"accuracy": float(acc), "macro_f1": float(f1), "per_class": report, "predictions": y_pred.tolist()}


# ---------------------------------------------------------------------------
# Plotting
# ---------------------------------------------------------------------------

def plot_algo_bpb(results: list[dict], path: Path):
    """Box plot: BPB per algorithm."""
    algo_bpbs = defaultdict(list)
    for r in results:
        for a, b in r["all_bpbs"].items():
            if b < 100:  # filter broken
                algo_bpbs[a].append(b)
    fig, ax = plt.subplots(figsize=(10, 6))
    order = sorted(algo_bpbs.keys(), key=lambda a: np.median(algo_bpbs[a]))
    data = [algo_bpbs[a] for a in order]
    bp = ax.boxplot(data, tick_labels=order, patch_artist=True)
    for patch, a in zip(bp["boxes"], order):
        patch.set_facecolor(ALGO_COLORS.get(a, "#gray"))
    ax.set_ylabel("Bits Per Byte (BPB)")
    ax.set_title("Compression Performance by Algorithm")
    ax.grid(axis="y", alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_algo_speed(results: list[dict], path: Path):
    """Box plot: time per chunk per algorithm."""
    algo_times = defaultdict(list)
    for r in results:
        for a, t in r["all_times"].items():
            algo_times[a].append(t)
    fig, ax = plt.subplots(figsize=(10, 6))
    order = sorted(algo_times.keys(), key=lambda a: np.median(algo_times[a]))
    data = [algo_times[a] for a in order]
    bp = ax.boxplot(data, tick_labels=order, patch_artist=True)
    for patch, a in zip(bp["boxes"], order):
        patch.set_facecolor(ALGO_COLORS.get(a, "#gray"))
    ax.set_ylabel("Time (ms)")
    ax.set_title("Compression Speed by Algorithm (per 1KB chunk)")
    ax.grid(axis="y", alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_bpb_vs_speed(results: list[dict], path: Path):
    """Scatter: BPB vs Speed for each algorithm (median per algo)."""
    fig, ax = plt.subplots(figsize=(10, 7))
    for algo in ALGORITHMS:
        bpbs = [r["all_bpbs"][algo] for r in results if r["all_bpbs"].get(algo, 999) < 100]
        times = [r["all_times"][algo] for r in results]
        ax.scatter(np.median(bpbs), np.median(times), s=200, c=ALGO_COLORS[algo],
                   label=algo, edgecolors="black", linewidth=1, zorder=5)
    ax.set_xlabel("Median BPB (lower is better)")
    ax.set_ylabel("Median Time per chunk (ms)")
    ax.set_title("BPB vs Speed Tradeoff")
    ax.legend()
    ax.grid(alpha=0.3)
    ax.invert_xaxis()
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_model_comparison(model_results: dict, raw_bpbs: dict, path: Path):
    """Bar chart: all models vs raw codecs."""
    items = list(raw_bpbs.items()) + list(model_results.items())
    items.sort(key=lambda x: x[1])
    fig, ax = plt.subplots(figsize=(11, 7))
    labels = [x[0] for x in items]
    values = [x[1] for x in items]
    colors = [ALGO_COLORS.get(l, "#1abc9c" if "MLP" in l or "XGB" in l or "Ensemble" in l else "#95a5a6") for l in labels]
    bars = ax.barh(labels, values, color=colors, edgecolor="white")
    best = values[0]
    for bar, val in zip(bars, values):
        delta = val - best
        suffix = f"  +{delta:.3f}" if delta > 0.001 else "  ★ BEST"
        ax.text(bar.get_width() + 0.03, bar.get_y() + bar.get_height()/2,
                f"{val:.3f}{suffix}", va="center", fontsize=9)
    ax.set_xlabel("Mean BPB (lower is better)")
    ax.set_title("Model Comparison: Adaptive vs Raw Codecs")
    ax.grid(axis="x", alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_model_speed_comparison(timing_results: dict, path: Path):
    """Bar chart: inference time per model."""
    fig, ax = plt.subplots(figsize=(9, 5))
    items = sorted(timing_results.items(), key=lambda x: -x[1])
    labels = [x[0] for x in items]
    values = [x[1] for x in items]
    colors = ["#1abc9c" if "MLP" in l or "XGB" in l else "#3498db" for l in labels]
    ax.barh(labels, values, color=colors, edgecolor="white")
    for i, (label, val) in enumerate(items):
        ax.text(val + 0.001, i, f"{val:.3f} ms", va="center", fontsize=9)
    ax.set_xlabel("Inference time per chunk (ms)")
    ax.set_title("Model Inference Speed")
    ax.grid(axis="x", alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_confusion_matrices(all_evals: dict, le: LabelEncoder, path: Path):
    """Subplot of confusion matrices for all models."""
    n_models = len(all_evals)
    cols = min(3, n_models)
    rows = (n_models + cols - 1) // cols
    fig, axes = plt.subplots(rows, cols, figsize=(5*cols, 4*rows))
    if rows == 1 and cols == 1:
        axes = np.array([axes])
    axes = axes.flatten()

    for ax, (name, ev) in zip(axes, all_evals.items()):
        cm = confusion_matrix(ev["y_true"], ev["y_pred"], normalize="true")
        im = ax.imshow(cm, cmap="Blues", aspect="auto", vmin=0, vmax=1)
        ax.set_xticks(range(len(le.classes_)))
        ax.set_yticks(range(len(le.classes_)))
        ax.set_xticklabels(le.classes_, rotation=45, ha="right", fontsize=8)
        ax.set_yticklabels(le.classes_, fontsize=8)
        ax.set_title(f"{name}\nAcc={ev['accuracy']:.2%} F1={ev['macro_f1']:.2%}")
        for i in range(len(le.classes_)):
            for j in range(len(le.classes_)):
                ax.text(j, i, f"{cm[i,j]:.2f}" if cm[i,j] > 0 else "", ha="center", va="center", fontsize=7)

    for ax in axes[n_models:]:
        ax.axis("off")
    plt.tight_layout()
    fig.savefig(path, dpi=150); plt.close(fig)


def plot_training_curves(mlp_histories: dict, path: Path):
    """Training curves for all MLP variants."""
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))
    for name, hist in mlp_histories.items():
        h = hist["history"]
        ax1.plot(h["train_loss"], label=f"{name} train", alpha=0.7)
        ax1.plot(h["val_loss"], label=f"{name} val", linestyle="--", alpha=0.7)
        ax2.plot(h["val_acc"], label=f"{name} ({max(h['val_acc']):.2%})")
    ax1.set_xlabel("Epoch"); ax1.set_ylabel("Loss"); ax1.set_title("Training & Validation Loss")
    ax1.legend(fontsize=7); ax1.grid(alpha=0.3)
    ax2.set_xlabel("Epoch"); ax2.set_ylabel("Accuracy"); ax2.set_title("Validation Accuracy")
    ax2.legend(fontsize=7); ax2.grid(alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_per_domain(results: list[dict], path: Path):
    """BPB per domain if domain info available."""
    domain_bpbs = defaultdict(lambda: defaultdict(list))
    for r in results:
        dom = r.get("domain", "unknown")
        best = r["best_algo"]
        domain_bpbs[dom][best].append(r["best_bpb"])

    if not domain_bpbs or len(domain_bpbs) < 2:
        return

    domains = sorted(domain_bpbs.keys())
    n_domains = len(domains)
    all_algos = sorted(set(a for d in domains for a in domain_bpbs[d]))

    fig, ax = plt.subplots(figsize=(max(8, n_domains * 1.5), 6))
    x = np.arange(n_domains)
    width = 0.8 / len(all_algos)

    for i, algo in enumerate(all_algos):
        means = [np.mean(domain_bpbs[d].get(algo, [0])) for d in domains]
        ax.bar(x + i * width, means, width, label=algo, color=ALGO_COLORS.get(algo, "gray"))

    ax.set_xticks(x + width * (len(all_algos) - 1) / 2)
    ax.set_xticklabels(domains, rotation=30, ha="right")
    ax.set_ylabel("Mean BPB")
    ax.set_title("Best Algorithm Distribution by Domain")
    ax.legend(fontsize=8)
    ax.grid(axis="y", alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


def plot_algorithm_win_distribution(results: list[dict], path: Path):
    """Pie/bar: which algorithm wins most chunks."""
    wins = Counter(r["best_algo"] for r in results)
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    labels = list(wins.keys())
    sizes = list(wins.values())
    colors = [ALGO_COLORS.get(a, "gray") for a in labels]
    ax1.pie(sizes, labels=labels, autopct="%1.1f%%", colors=colors)
    ax1.set_title("Ground Truth: Best Algorithm Distribution")

    # Chunk-by-chunk (first 100 chunks)
    first_algo = [r["best_algo"] for r in results[:100]]
    algo_idx = {a: i for i, a in enumerate(sorted(set(first_algo)))}
    y = [algo_idx[a] for a in first_algo]
    ax2.scatter(range(len(y)), y, c=[ALGO_COLORS.get(a, "gray") for a in first_algo], s=5, alpha=0.6)
    ax2.set_yticks(list(algo_idx.values()))
    ax2.set_yticklabels(list(algo_idx.keys()))
    ax2.set_xlabel("Chunk index")
    ax2.set_title("Algorithm Wins — First 100 Chunks")
    ax2.grid(alpha=0.3)
    plt.tight_layout(); fig.savefig(path, dpi=150); plt.close(fig)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    print("=" * 70)
    print("FINAL COMPREHENSIVE EXPERIMENT")
    print("=" * 70)
    ARTIFACTS_DIR.mkdir(parents=True, exist_ok=True)
    PLOTS_DIR.mkdir(parents=True, exist_ok=True)
    rng = np.random.RandomState(RANDOM_SEED)

    # ---------- Step 1: Load data ----------
    print("\n[1/6] Loading corpus...")
    chunks_with_domain = load_all_corpus(MAX_CHUNKS)
    chunks = [c for _, c in chunks_with_domain]
    domains = [d for d, _ in chunks_with_domain]
    print(f"  {len(chunks)} chunks from {len(set(domains))} domains")

    # ---------- Step 2: Grid search ----------
    print(f"\n[2/6] Running grid search ({len(ALGORITHMS)} algorithms × {len(chunks)} chunks)...")
    results = run_grid_search(chunks)
    for i, r in enumerate(results):
        r["domain"] = domains[i] if i < len(domains) else "unknown"

    # Ground truth distribution
    wins = Counter(r["best_algo"] for r in results)
    print("  Algorithm wins:")
    for a, c in wins.most_common():
        print(f"    {a}: {c} ({c/len(results)*100:.1f}%)")

    # Save grid results (expensive!)
    import pickle as _pk
    with open(ARTIFACTS_DIR / "grid_results.pkl", "wb") as _f:
        _pk.dump(results, _f)
    print("  Grid results saved to grid_results.pkl")

    # ---------- Step 3: Features + Split ----------
    print("\n[3/6] Extracting features + train/test split...")
    X = np.array([[r["features"][f] for f in FEATURE_NAMES] for r in results])
    y_str = np.array([r["best_algo"] for r in results])

    le = LabelEncoder()
    y = le.fit_transform(y_str)
    n_classes = len(le.classes_)
    print(f"  Classes: {list(le.classes_)}")

    scaler = StandardScaler()
    X = scaler.fit_transform(X)

    X_temp, X_test, y_temp, y_test, idx_temp, idx_test = train_test_split(
        X, y, np.arange(len(X)), test_size=0.15, random_state=RANDOM_SEED, stratify=y)
    X_train, X_val, y_train, y_val, idx_train, idx_val = train_test_split(
        X_temp, y_temp, idx_temp, test_size=0.1765, random_state=RANDOM_SEED, stratify=y_temp)
    print(f"  Train: {len(X_train)}, Val: {len(X_val)}, Test: {len(X_test)}")

    # ---------- Step 4: Train models ----------
    print("\n[4/6] Training models...")

    # XGBoost
    import xgboost as xgb
    xgb_model = xgb.XGBClassifier(
        n_estimators=200, max_depth=6, learning_rate=0.1,
        subsample=0.8, colsample_bytree=0.8,
        objective="multi:softprob", eval_metric="mlogloss",
        early_stopping_rounds=20, random_state=RANDOM_SEED, n_jobs=-1,
    )
    xgb_model.fit(X_train, y_train, eval_set=[(X_val, y_val)], verbose=False)
    xgb_eval = evaluate_model(xgb_model, X_test, y_test, le)
    print(f"  XGBoost: acc={xgb_eval['accuracy']:.2%}, f1={xgb_eval['macro_f1']:.2%}")

    # MLP variants
    mlp_configs = {
        "MLP-Small": [32, 16],
        "MLP-Medium": [64, 32, 16],
        "MLP-Large": [128, 64, 32],
    }
    mlp_models = {}
    mlp_evals = {}
    mlp_histories = {}

    for name, hidden in mlp_configs.items():
        print(f"  Training {name} ({hidden})...")
        model, hist = train_mlp(X_train, y_train, X_val, y_val, hidden, n_classes, name=name)
        ev = evaluate_model(model, X_test, y_test, le)
        mlp_models[name] = model
        mlp_evals[name] = ev
        mlp_histories[name] = hist
        print(f"    {name}: acc={ev['accuracy']:.2%}, f1={ev['macro_f1']:.2%}, "
              f"params={hist['params']:,}")

    # MLP Ensemble (soft voting)
    print("  MLP Ensemble (soft voting)...")
    with torch.no_grad():
        X_test_t = torch.tensor(X_test, dtype=torch.float32)
        all_probs = []
        for name, model in mlp_models.items():
            model.eval()
            logits = model(X_test_t)
            probs = F.softmax(logits, dim=-1)
            all_probs.append(probs)
        ensemble_probs = torch.stack(all_probs).mean(dim=0)
        ensemble_preds = ensemble_probs.argmax(dim=1).numpy()

    ensemble_acc = accuracy_score(y_test, ensemble_preds)
    ensemble_f1 = f1_score(y_test, ensemble_preds, average="macro")
    ensemble_report = classification_report(y_test, ensemble_preds, target_names=le.classes_,
                                            output_dict=True, zero_division=0)
    mlp_evals["MLP-Ensemble"] = {
        "accuracy": float(ensemble_acc), "macro_f1": float(ensemble_f1),
        "per_class": ensemble_report, "predictions": ensemble_preds.tolist(),
    }
    print(f"    MLP-Ensemble: acc={ensemble_acc:.2%}, f1={ensemble_f1:.2%}")

    # ---------- Step 5: Timing benchmarks ----------
    print("\n[5/6] Benchmarking inference speed...")
    timing_results = {}

    # XGBoost timing
    t0 = time.perf_counter()
    for _ in range(100):
        xgb_model.predict(X_test[:10])
    xgb_time = (time.perf_counter() - t0) / 1000 * 1000  # ms per chunk
    timing_results["XGBoost"] = float(xgb_time)

    # MLP timing
    for name, model in mlp_models.items():
        model.eval()
        with torch.no_grad():
            t0 = time.perf_counter()
            for _ in range(100):
                model(torch.tensor(X_test[:10], dtype=torch.float32))
            mlp_time = (time.perf_counter() - t0) / 1000 * 1000
        timing_results[name] = float(mlp_time)

    # Raw algorithm timing (from grid search)
    for algo in ALGORITHMS:
        t = np.median([r["all_times"][algo] for r in results])
        timing_results[algo] = float(t)

    print("  Inference time per chunk (ms):")
    for name, t in sorted(timing_results.items(), key=lambda x: x[1]):
        print(f"    {name:20s}: {t:.4f} ms")

    # ---------- Step 6: Adaptive BPB benchmark ----------
    print("\n[6/6] Computing adaptive BPB...")

    # Raw codec BPBs on test set  
    test_results = [results[i] for i in idx_test]
    raw_bpbs = {}
    for algo in ALGORITHMS:
        bpbs = [r["all_bpbs"][algo] for r in test_results]
        raw_bpbs[algo] = float(np.mean([b for b in bpbs if b < 100]))

    # Adaptive BPB for each model
    model_bpbs = {}

    # XGBoost
    xgb_preds = xgb_model.predict(X_test)
    xgb_bpb = np.mean([test_results[i]["all_bpbs"].get(le.classes_[p], 999)
                       for i, p in enumerate(xgb_preds)])
    model_bpbs["XGBoost"] = float(xgb_bpb)

    # MLPs
    for name, model in mlp_models.items():
        model.eval()
        with torch.no_grad():
            preds = model(torch.tensor(X_test, dtype=torch.float32)).argmax(dim=1).numpy()
        bpb = np.mean([test_results[i]["all_bpbs"].get(le.classes_[p], 999)
                       for i, p in enumerate(preds)])
        model_bpbs[name] = float(bpb)

    # MLP Ensemble
    ens_bpb = np.mean([test_results[i]["all_bpbs"].get(le.classes_[p], 999)
                       for i, p in enumerate(ensemble_preds)])
    model_bpbs["MLP-Ensemble"] = float(ens_bpb)

    best_raw = min(raw_bpbs, key=raw_bpbs.get)
    print(f"\n  Final BPB comparison:")
    for name in sorted({**raw_bpbs, **model_bpbs}, key=lambda k: {**raw_bpbs, **model_bpbs}[k]):
        bpb = {**raw_bpbs, **model_bpbs}.get(name, 0)
        marker = " ★ RAW BEST" if name == best_raw else ""
        is_ours = name in model_bpbs
        prefix = "★ " if is_ours else "  "
        print(f"  {prefix}{name:20s}: {bpb:.4f} BPB{marker}")

    # ---------- Plots ----------
    print("\nGenerating plots...")

    plot_algo_bpb(results, PLOTS_DIR / "algo_bpb_boxplot.png")
    plot_algo_speed(results, PLOTS_DIR / "algo_speed_boxplot.png")
    plot_bpb_vs_speed(results, PLOTS_DIR / "bpb_vs_speed.png")
    plot_model_comparison(model_bpbs, raw_bpbs, PLOTS_DIR / "model_comparison.png")
    plot_model_speed_comparison(timing_results, PLOTS_DIR / "model_speed.png")
    plot_training_curves(mlp_histories, PLOTS_DIR / "training_curves.png")
    plot_algorithm_win_distribution(results, PLOTS_DIR / "algorithm_wins.png")

    # Confusion matrices
    all_evals = {
        "XGBoost": {"y_true": y_test.tolist(), "y_pred": xgb_eval["predictions"],
                    "accuracy": xgb_eval["accuracy"], "macro_f1": xgb_eval["macro_f1"]},
    }
    for name in mlp_evals:
        all_evals[name] = {"y_true": y_test.tolist(), "y_pred": mlp_evals[name]["predictions"],
                           "accuracy": mlp_evals[name]["accuracy"],
                           "macro_f1": mlp_evals[name]["macro_f1"]}
    plot_confusion_matrices(all_evals, le, PLOTS_DIR / "confusion_matrices.png")

    # Per-domain
    plot_per_domain(results, PLOTS_DIR / "per_domain.png")

    # ---------- Save ----------
    output = {
        "config": {"chunk_size": CHUNK_SIZE, "n_chunks": len(chunks), "algorithms": ALGORITHMS},
        "ground_truth": dict(wins.most_common()),
        "models": {
            "XGBoost": {"eval": {k: v for k, v in xgb_eval.items() if k != "predictions"},
                        "bpb": model_bpbs["XGBoost"]},
        },
        "raw_bpbs": raw_bpbs,
        "timing": timing_results,
    }
    for name in mlp_evals:
        output["models"][name] = {
            "eval": {k: v for k, v in mlp_evals[name].items() if k != "predictions"},
            "bpb": model_bpbs.get(name, 0),
            "params": mlp_histories.get(name, {}).get("params", 0),
            "best_val_acc": mlp_histories.get(name, {}).get("best_val_acc", 0),
        }

    with open(ARTIFACTS_DIR / "results.json", "w") as f:
        json.dump(output, f, indent=2)

    print(f"\n✅ Done! Artifacts: {ARTIFACTS_DIR}/")
    print(f"   Plots: {PLOTS_DIR}/")
    return output


if __name__ == "__main__":
    main()
