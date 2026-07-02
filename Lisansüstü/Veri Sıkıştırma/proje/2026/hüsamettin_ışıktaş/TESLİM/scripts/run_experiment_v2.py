"""Supervised algorithm selection experiment — v2.

KEY INSIGHT: Instead of unsupervised K-Means clustering → profile assignment,
we directly learn the mapping from fast features to the best compression
algorithm using actual compression outcomes as ground truth.

Pipeline:
  1. Load diverse corpus (Gutenberg + code + HTML + JSON + ...)
  2. Chunk each document at fixed chunk_size
  3. For each chunk, run ALL algorithms → best algorithm = ground truth label
  4. Extract Set B (fast) features for each chunk
  5. Train XGBoost classifier: features → best_algorithm
  6. Evaluate on held-out test data
  7. Benchmark adaptive vs raw codecs

This is supervised "algorithm selection" — no clustering, no profiles.
The ML model directly predicts which codec will compress best.
"""

from __future__ import annotations

import csv
import json
import logging
import os
import sys
import time
from collections import Counter
from pathlib import Path
from typing import Any

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.metrics import (
    accuracy_score,
    classification_report,
    confusion_matrix,
    f1_score,
)
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, StandardScaler
from tqdm import tqdm

matplotlib.use("Agg")

PROJECT_ROOT = Path(__file__).resolve().parent.parent
DATA_DIR = PROJECT_ROOT / "data"
ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v2_supervised"
PLOTS_DIR = ARTIFACTS_DIR / "plots"

CHUNK_SIZE = 1024  # bytes — sweet spot for algorithm diversity

# All candidate codecs (classical only — zstd is benchmarked separately as modern baseline)
ALGORITHMS = ["huffman", "lzw", "arithmetic", "bwt_mtf", "rle_huffman"]

# Parameter sets — one representative config per algorithm
# (we test the best-known config for each, not full grid)
ALGO_PARAMS = {
    "huffman": {"order": 1},
    "lzw": {"max_bits": 14},
    "arithmetic": {"order": 1},
    "bwt_mtf": {"secondary": "huffman", "block_size": 0},
    "rle_huffman": {"min_run": 4},
}

# Codec dispatch
_CODEC_DISPATCH: dict[str, Any] = {}

logger = logging.getLogger(__name__)


# ---------------------------------------------------------------------------
# Imports
# ---------------------------------------------------------------------------

def _import_codecs():
    """Lazy import codec modules."""
    global _CODEC_DISPATCH
    from src.codecs import (
        arithmetic_codec,
        bwt_codec,
        huffman_codec,
        lzw_codec,
        rle_codec,
    )

    _CODEC_DISPATCH = {
        "huffman": huffman_codec,
        "lzw": lzw_codec,
        "arithmetic": arithmetic_codec,
        "bwt_mtf": bwt_codec,
        "rle_huffman": rle_codec,
    }


# ---------------------------------------------------------------------------
# Fast feature extraction (Set B — what the classifier sees at inference)
# ---------------------------------------------------------------------------

def extract_fast_features(text: str) -> dict[str, float]:
    """Extract Set B (fast, O(n)) features from a text chunk.
    
    These are the features the classifier uses at inference time.
    No compression calls — pure statistics.
    """
    from collections import Counter
    import math
    import re

    if not text:
        return {f: 0.0 for f in _fast_feature_names()}

    chars = list(text)
    n = len(chars)
    n_lines = text.count("\n") + 1

    # Word stats
    words = re.findall(r"\b\w+\b", text)
    n_words = len(words)
    word_lens = [len(w) for w in words] if words else [0]
    avg_word_len = np.mean(word_lens)
    std_word_len = np.std(word_lens) if len(word_lens) > 1 else 0.0

    # Character diversity
    unique_chars = len(set(chars))
    unique_char_ratio = unique_chars / n if n else 0

    # Digit/whitespace/punctuation ratios
    digit_ratio = sum(1 for c in chars if c.isdigit()) / n if n else 0
    whitespace_ratio = sum(1 for c in chars if c.isspace()) / n if n else 0
    import string
    punct = set(string.punctuation)
    punctuation_ratio = sum(1 for c in chars if c in punct) / n if n else 0

    # Uppercase ratio
    uppercase_ratio = sum(1 for c in chars if c.isupper()) / n if n else 0

    # Vowel/consonant ratio
    vowels = set("aeiouAEIOU")
    vowel_ratio = sum(1 for c in chars if c in vowels) / n if n else 0

    # Character entropy
    char_counts = Counter(chars)
    entropy_char = 0.0
    for count in char_counts.values():
        prob = count / n
        entropy_char -= prob * math.log2(prob)

    # Bigram repetition
    bigrams = [text[i:i+2] for i in range(n - 1)]
    unique_bigrams = len(set(bigrams))
    bigram_rep_ratio = 1.0 - (unique_bigrams / len(bigrams)) if bigrams else 0.0

    # Trigram repetition
    trigrams = [text[i:i+3] for i in range(n - 2)]
    unique_trigrams = len(set(trigrams))
    trigram_rep_ratio = 1.0 - (unique_trigrams / len(trigrams)) if trigrams else 0.0

    # ASCII ratio
    ascii_count = sum(1 for c in chars if 32 <= ord(c) <= 126 or ord(c) in (9, 10, 13))
    ascii_ratio = ascii_count / n if n else 0

    # Newline density
    newline_density = (n_lines - 1) / n if n else 0

    # Line length stats
    lines = text.split("\n")
    line_lengths = [len(line) for line in lines]
    mean_line_length = np.mean(line_lengths) if line_lengths else 0
    std_line_length = np.std(line_lengths) if len(line_lengths) > 1 else 0

    # Unique word ratio
    unique_words = len(set(words))
    unique_word_ratio = unique_words / n_words if n_words else 0

    # Longest repeated substring approximation
    longest_repeat = _approx_longest_repeat(text)

    # Non-ASCII density
    non_ascii_ratio = 1.0 - ascii_ratio

    return {
        "n_chars": n,
        "n_lines": n_lines,
        "n_words": n_words,
        "avg_word_len": avg_word_len,
        "std_word_len": std_word_len,
        "unique_char_ratio": unique_char_ratio,
        "unique_word_ratio": unique_word_ratio,
        "digit_ratio": digit_ratio,
        "whitespace_ratio": whitespace_ratio,
        "punctuation_ratio": punctuation_ratio,
        "uppercase_ratio": uppercase_ratio,
        "vowel_ratio": vowel_ratio,
        "entropy_char": entropy_char,
        "bigram_repetition_ratio": bigram_rep_ratio,
        "trigram_repetition_ratio": trigram_rep_ratio,
        "longest_repeat_run": longest_repeat,
        "newline_density": newline_density,
        "mean_line_length": mean_line_length,
        "std_line_length": std_line_length,
        "ascii_ratio": ascii_ratio,
        "non_ascii_ratio": non_ascii_ratio,
    }


def _fast_feature_names() -> list[str]:
    return [
        "n_chars", "n_lines", "n_words",
        "avg_word_len", "std_word_len",
        "unique_char_ratio", "unique_word_ratio",
        "digit_ratio", "whitespace_ratio", "punctuation_ratio",
        "uppercase_ratio", "vowel_ratio",
        "entropy_char",
        "bigram_repetition_ratio", "trigram_repetition_ratio",
        "longest_repeat_run",
        "newline_density",
        "mean_line_length", "std_line_length",
        "ascii_ratio", "non_ascii_ratio",
    ]


def _approx_longest_repeat(text: str, max_len: int = 50) -> int:
    """Approximate longest repeated substring using rolling hash."""
    if len(text) < 2:
        return 0
    seen = set()
    for length in range(min(max_len, len(text)), 1, -1):
        seen.clear()
        for i in range(len(text) - length + 1):
            sub = text[i:i + length]
            if sub in seen:
                return length
            seen.add(sub)
    return 1


# ---------------------------------------------------------------------------
# Chunking
# ---------------------------------------------------------------------------

def chunk_text(text: str, chunk_size: int = CHUNK_SIZE) -> list[str]:
    """Split text into fixed-size chunks (non-overlapping)."""
    return [text[i:i + chunk_size] for i in range(0, len(text), chunk_size) if len(text[i:i + chunk_size]) >= 100]


# ---------------------------------------------------------------------------
# Ground truth: find best algorithm for each chunk
# ---------------------------------------------------------------------------

def find_best_algorithm(text: str) -> tuple[str, float, dict[str, float]]:
    """Try all algorithms on this chunk, return the best one + all BPBs."""
    data = text.encode("utf-8")
    results: dict[str, float] = {}
    
    for algo, params in ALGO_PARAMS.items():
        codec = _CODEC_DISPATCH[algo]
        try:
            result = codec.compress(data, **{k: v for k, v in params.items() if k != "label"})
            if result.valid:
                results[algo] = result.bpb
            else:
                results[algo] = 999.0
        except Exception:
            results[algo] = 999.0

    best_algo = min(results, key=results.get)
    best_bpb = results[best_algo]
    return best_algo, best_bpb, results


# ---------------------------------------------------------------------------
# Classifier training
# ---------------------------------------------------------------------------

def train_classifier(
    X_train: np.ndarray,
    y_train: np.ndarray,
    X_val: np.ndarray,
    y_val: np.ndarray,
    label_encoder: LabelEncoder,
) -> tuple[Any, dict]:
    """Train XGBoost classifier with early stopping."""
    import xgboost as xgb

    n_classes = len(label_encoder.classes_)
    
    model = xgb.XGBClassifier(
        n_estimators=200,
        max_depth=6,
        learning_rate=0.1,
        subsample=0.8,
        colsample_bytree=0.8,
        objective="multi:softprob",
        eval_metric="mlogloss",
        early_stopping_rounds=20,
        random_state=42,
        n_jobs=-1,
    )

    model.fit(
        X_train, y_train,
        eval_set=[(X_val, y_val)],
        verbose=False,
    )

    # Evaluate
    y_pred = model.predict(X_val)
    acc = accuracy_score(y_val, y_pred)
    macro_f1 = f1_score(y_val, y_pred, average="macro")

    report = classification_report(
        y_val, y_pred,
        target_names=label_encoder.classes_,
        output_dict=True,
        zero_division=0,
    )

    metrics = {
        "accuracy": float(acc),
        "macro_f1": float(macro_f1),
        "n_classes": n_classes,
        "n_train": len(X_train),
        "n_val": len(X_val),
        "best_iteration": model.best_iteration,
        "per_class": report,
    }

    return model, metrics


# ---------------------------------------------------------------------------
# Plotting
# ---------------------------------------------------------------------------

def plot_confusion_matrix(y_true, y_pred, label_names, path: Path):
    cm = confusion_matrix(y_true, y_pred, normalize="true")
    fig, ax = plt.subplots(figsize=(10, 8))
    im = ax.imshow(cm, cmap="Blues", aspect="auto")
    plt.colorbar(im, ax=ax, label="Fraction")
    ax.set_xticks(range(len(label_names)))
    ax.set_yticks(range(len(label_names)))
    ax.set_xticklabels(label_names, rotation=45, ha="right", fontsize=9)
    ax.set_yticklabels(label_names, fontsize=9)
    ax.set_xlabel("Predicted")
    ax.set_ylabel("True")
    ax.set_title("Normalized Confusion Matrix — Algorithm Classifier")
    for i in range(len(label_names)):
        for j in range(len(label_names)):
            ax.text(j, i, f"{cm[i,j]:.2f}" if cm[i,j] > 0 else "", ha="center", va="center", fontsize=7)
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


def plot_algorithm_distribution(labels: list[str], title: str, path: Path):
    counts = Counter(labels)
    fig, ax = plt.subplots(figsize=(8, 5))
    algos = sorted(counts.keys())
    values = [counts[a] for a in algos]
    colors = plt.cm.Set2(range(len(algos)))
    bars = ax.bar(algos, values, color=colors, edgecolor="white")
    for bar, val in zip(bars, values):
        ax.text(bar.get_x() + bar.get_width() / 2, bar.get_height() + 1,
                str(val), ha="center", fontsize=10)
    ax.set_ylabel("Number of chunks")
    ax.set_title(title)
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


def plot_bpb_by_algo(all_results: list[dict], path: Path):
    """Box plot of BPB per algorithm across all chunks."""
    algo_bpbs: dict[str, list[float]] = {}
    for r in all_results:
        for algo, bpb in r["all_bpbs"].items():
            algo_bpbs.setdefault(algo, []).append(bpb)

    fig, ax = plt.subplots(figsize=(10, 6))
    algos_sorted = sorted(algo_bpbs.keys(), key=lambda a: np.median(algo_bpbs[a]))
    data = [algo_bpbs[a] for a in algos_sorted]
    bp = ax.boxplot(data, labels=algos_sorted, patch_artist=True)
    for patch, color in zip(bp["boxes"], plt.cm.Set3(range(len(algos_sorted)))):
        patch.set_facecolor(color)
    ax.set_ylabel("Bits Per Byte (BPB)")
    ax.set_title("Compression Performance by Algorithm (all chunks)")
    ax.grid(axis="y", alpha=0.3)
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


def plot_feature_importance(model, feature_names: list[str], path: Path):
    importances = model.feature_importances_
    idx = np.argsort(importances)[-20:]  # top 20
    fig, ax = plt.subplots(figsize=(8, 7))
    ax.barh([feature_names[i] for i in idx], importances[idx], color="steelblue")
    ax.set_xlabel("Importance")
    ax.set_title("Top 20 Feature Importances (XGBoost)")
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


def plot_benchmark_comparison(raw_bpbs: dict, adaptive_bpb: float, path: Path):
    """Bar chart comparing adaptive vs raw codecs."""
    fig, ax = plt.subplots(figsize=(10, 6))
    items = list(raw_bpbs.items()) + [("★ ADAPTIVE (ours)", adaptive_bpb)]
    items.sort(key=lambda x: x[1])
    labels = [x[0] for x in items]
    values = [x[1] for x in items]
    colors = ["#2ecc71" if "ADAPTIVE" in l else "#3498db" for l in labels]

    bars = ax.barh(labels, values, color=colors, edgecolor="white")
    best = min(values)
    for bar, val in zip(bars, values):
        delta = val - best
        suffix = f"  (+{delta:.2f})" if delta > 0.01 else "  ★ BEST"
        ax.text(bar.get_width() + 0.05, bar.get_y() + bar.get_height() / 2,
                f"{val:.2f}{suffix}", va="center", fontsize=10)

    ax.set_xlabel("Bits Per Byte (BPB) — lower is better")
    ax.set_title("Compression Benchmark: Adaptive vs Raw Codecs")
    ax.grid(axis="x", alpha=0.3)
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


# ---------------------------------------------------------------------------
# Main pipeline
# ---------------------------------------------------------------------------

def run_pipeline():
    _import_codecs()
    random_state = np.random.RandomState(42)

    print("=" * 70)
    print("SUPERVISED ALGORITHM SELECTION — EXPERIMENT V2")
    print("=" * 70)

    # -----------------------------------------------------------------------
    # Step 1: Load diverse corpus
    # -----------------------------------------------------------------------
    print("\n[1/7] Loading diverse corpus...")
    diverse_dir = DATA_DIR / "diverse"
    manifest_path = diverse_dir / "manifest.csv"

    if not manifest_path.exists():
        print("  ❌ Manifest not found! Run scripts/build_diverse_corpus.py first.")
        print("  Falling back to Gutenberg-only data...")
        # Use existing processed books
        processed = DATA_DIR / "processed" / "books"
        books = sorted(processed.glob("*.txt")) if processed.exists() else []
        texts = []
        for f in books[:60]:
            texts.append(f.read_text(encoding="utf-8", errors="replace")[:30000])
    else:
        with open(manifest_path, encoding="utf-8") as f:
            reader = csv.DictReader(f)
            rows = list(reader)
        texts = []
        for row in rows:
            path = PROJECT_ROOT / row["path"]
            if path.exists():
                texts.append(path.read_text(encoding="utf-8", errors="replace"))
        print(f"  Loaded {len(texts)} documents from {len(set(r['domain'] for r in rows))} domains")

    if not texts:
        print("  ❌ No texts found!")
        return

    # -----------------------------------------------------------------------
    # Step 2: Chunk all documents
    # -----------------------------------------------------------------------
    print(f"\n[2/7] Chunking at {CHUNK_SIZE} bytes...")
    all_chunks: list[str] = []
    for text in tqdm(texts, desc="  Chunking"):
        all_chunks.extend(chunk_text(text, CHUNK_SIZE))

    # Limit to manageable size for grid search
    max_chunks = 5000
    if len(all_chunks) > max_chunks:
        indices = random_state.choice(len(all_chunks), max_chunks, replace=False)
        all_chunks = [all_chunks[i] for i in indices]

    print(f"  {len(all_chunks)} chunks total")

    # -----------------------------------------------------------------------
    # Step 3: Find ground truth (best algorithm per chunk)
    # -----------------------------------------------------------------------
    print(f"\n[3/7] Finding best algorithm per chunk ({len(ALGORITHMS)} algorithms)...")
    print(f"  Algorithms: {', '.join(ALGORITHMS)}")

    ground_truth: list[dict] = []
    algo_win_counts: Counter = Counter()

    for idx, chunk in enumerate(tqdm(all_chunks, desc="  Grid search")):
        best_algo, best_bpb, all_bpbs = find_best_algorithm(chunk)
        ground_truth.append({
            "chunk_idx": idx,
            "text": chunk,
            "best_algorithm": best_algo,
            "best_bpb": best_bpb,
            "all_bpbs": all_bpbs,
        })
        algo_win_counts[best_algo] += 1

    print("\n  Algorithm win distribution:")
    for algo, count in algo_win_counts.most_common():
        pct = count / len(ground_truth) * 100
        print(f"    {algo}: {count} chunks ({pct:.1f}%)")

    # -----------------------------------------------------------------------
    # Step 4: Extract fast features
    # -----------------------------------------------------------------------
    print(f"\n[4/7] Extracting fast features...")
    feature_rows = []
    for item in tqdm(ground_truth, desc="  Features"):
        features = extract_fast_features(item["text"])
        features["best_algorithm"] = item["best_algorithm"]
        features["best_bpb"] = item["best_bpb"]
        feature_rows.append(features)

    df = pd.DataFrame(feature_rows)
    print(f"  Feature matrix: {df.shape}")

    # -----------------------------------------------------------------------
    # Step 5: Train classifier
    # -----------------------------------------------------------------------
    print(f"\n[5/7] Training XGBoost classifier...")

    feature_names = _fast_feature_names()
    X = df[feature_names].values
    y_str = df["best_algorithm"].values

    label_encoder = LabelEncoder()
    y = label_encoder.fit_transform(y_str)

    # Standardize
    scaler = StandardScaler()
    X = scaler.fit_transform(X)

    # Split: 70/15/15
    X_temp, X_test, y_temp, y_test = train_test_split(
        X, y, test_size=0.15, random_state=42, stratify=y
    )
    X_train, X_val, y_train, y_val = train_test_split(
        X_temp, y_temp, test_size=0.1765, random_state=42, stratify=y_temp
    )  # 0.1765 * 0.85 ≈ 0.15

    model, metrics = train_classifier(X_train, y_train, X_val, y_val, label_encoder)

    print(f"\n  📊 Validation metrics:")
    print(f"    Accuracy:  {metrics['accuracy']:.4f}")
    print(f"    Macro F1:  {metrics['macro_f1']:.4f}")
    print(f"    Best iter: {metrics['best_iteration']}")

    # Test set
    y_pred_test = model.predict(X_test)
    test_acc = accuracy_score(y_test, y_pred_test)
    test_f1 = f1_score(y_test, y_pred_test, average="macro")
    print(f"\n  📊 Test metrics:")
    print(f"    Accuracy:  {test_acc:.4f}")
    print(f"    Macro F1:  {test_f1:.4f}")

    metrics["test_accuracy"] = float(test_acc)
    metrics["test_f1"] = float(test_f1)

    # -----------------------------------------------------------------------
    # Step 6: Benchmark — adaptive vs raw codecs on test chunks
    # -----------------------------------------------------------------------
    print(f"\n[6/7] Benchmarking adaptive compressor vs raw codecs...")

    # Get test set chunk indices
    test_indices = set()
    # We need to track which original chunks are in the test set
    # Use the feature-based split: find which rows are test
    test_mask = np.zeros(len(df), dtype=bool)
    # Reconstruct the split
    _, X_t2, _, y_t2 = train_test_split(
        np.arange(len(df)), y, test_size=0.15, random_state=42, stratify=y
    )
    test_indices = set(X_t2.tolist())

    test_chunks_data = [ground_truth[i] for i in test_indices]

    # Raw codec benchmarks on test chunks
    raw_results: dict[str, list[float]] = {algo: [] for algo in ALGORITHMS}
    adaptive_bpbs: list[float] = []

    # Compute feature matrix for test chunks
    test_feature_rows = []
    for item in test_chunks_data:
        feats = extract_fast_features(item["text"])
        test_feature_rows.append(feats)
    test_df = pd.DataFrame(test_feature_rows)
    X_test_feats = scaler.transform(test_df[feature_names].values)

    for i, item in enumerate(tqdm(test_chunks_data, desc="  Benchmarking")):
        # Raw codec BPBs
        for algo in ALGORITHMS:
            raw_results[algo].append(item["all_bpbs"].get(algo, 999.0))

        # Adaptive: use classifier to predict best algorithm
        pred_idx = model.predict(X_test_feats[i:i+1])[0]
        pred_algo = label_encoder.inverse_transform([pred_idx])[0]
        # Use that algorithm's actual BPB for this chunk
        adaptive_bpbs.append(item["all_bpbs"].get(pred_algo, 999.0))

    raw_bpbs = {algo: float(np.mean(bpbs)) for algo, bpbs in raw_results.items()}
    adaptive_mean_bpb = float(np.mean(adaptive_bpbs))
    best_raw = min(raw_bpbs, key=raw_bpbs.get)
    best_raw_bpb = raw_bpbs[best_raw]

    print(f"\n  📊 Benchmark results (on {len(test_chunks_data)} test chunks):")
    for algo in sorted(raw_bpbs, key=raw_bpbs.get):
        marker = " ★" if algo == best_raw else ""
        print(f"    {algo:15s}: {raw_bpbs[algo]:.4f} BPB{marker}")
    print(f"    {'ADAPTIVE (ours)':15s}: {adaptive_mean_bpb:.4f} BPB")

    improvement = (best_raw_bpb - adaptive_mean_bpb) / best_raw_bpb * 100
    if adaptive_mean_bpb < best_raw_bpb:
        print(f"\n  🎉 ADAPTIVE WINS! {improvement:.2f}% better than best raw ({best_raw})")
    else:
        print(f"\n  ⚠ Adaptive is {abs(improvement):.2f}% worse than best raw ({best_raw})")

    # -----------------------------------------------------------------------
    # Step 7: Save artifacts and generate report
    # -----------------------------------------------------------------------
    print(f"\n[7/7] Saving artifacts...")
    ARTIFACTS_DIR.mkdir(parents=True, exist_ok=True)
    PLOTS_DIR.mkdir(parents=True, exist_ok=True)

    # Plots
    plot_algorithm_distribution(
        [item["best_algorithm"] for item in ground_truth],
        "Ground Truth: Best Algorithm per Chunk",
        PLOTS_DIR / "ground_truth_distribution.png",
    )
    plot_bpb_by_algo(ground_truth, PLOTS_DIR / "bpb_by_algorithm.png")
    plot_confusion_matrix(
        y_test, y_pred_test,
        label_encoder.classes_.tolist(),
        PLOTS_DIR / "confusion_matrix.png",
    )
    plot_feature_importance(model, feature_names, PLOTS_DIR / "feature_importance.png")
    plot_benchmark_comparison(raw_bpbs, adaptive_mean_bpb, PLOTS_DIR / "benchmark_comparison.png")

    # Metrics JSON
    results = {
        "config": {
            "chunk_size": CHUNK_SIZE,
            "algorithms": ALGORITHMS,
            "n_chunks_total": len(all_chunks),
            "n_test_chunks": len(test_chunks_data),
            "classifier": "XGBoost",
        },
        "ground_truth": {
            "algorithm_wins": dict(algo_win_counts.most_common()),
        },
        "classifier_metrics": metrics,
        "benchmark": {
            "raw_codecs": raw_bpbs,
            "adaptive": adaptive_mean_bpb,
            "best_raw": {"algorithm": best_raw, "bpb": best_raw_bpb},
            "adaptive_vs_best_raw_pct": improvement,
            "n_test_chunks": len(test_chunks_data),
        },
    }

    with open(ARTIFACTS_DIR / "results.json", "w") as f:
        json.dump(results, f, indent=2)

    # Save the model
    import pickle
    model.save_model(str(ARTIFACTS_DIR / "xgboost_model.json"))
    with open(ARTIFACTS_DIR / "label_encoder.pkl", "wb") as f:
        pickle.dump(label_encoder, f)
    with open(ARTIFACTS_DIR / "scaler.pkl", "wb") as f:
        pickle.dump(scaler, f)

    # Generate markdown report
    _generate_report(results, PLOTS_DIR)

    print(f"\n✅ All artifacts saved to {ARTIFACTS_DIR}/")
    print(f"   Plots: {PLOTS_DIR}/")
    return results


def _generate_report(results: dict, plots_dir: Path):
    """Generate a comprehensive markdown report."""
    cfg = results["config"]
    gt = results["ground_truth"]
    clf = results["classifier_metrics"]
    bench = results["benchmark"]

    report = f"""# Supervised Algorithm Selection — Experiment Report

## Overview

**Approach**: Instead of unsupervised K-Means clustering, we directly learn the
mapping from fast text features to the best compression algorithm using
**supervised learning** (XGBoost).

**Config**:
- Chunk size: {cfg['chunk_size']} bytes
- Algorithms: {', '.join(cfg['algorithms'])}
- Total chunks: {cfg['n_chunks_total']}
- Test chunks: {cfg['n_test_chunks']}
- Classifier: XGBoost

## Ground Truth Distribution

Which algorithm wins on each chunk (actual compression outcome):

| Algorithm | Wins | % |
|-----------|------|---|
"""
    total = sum(gt["algorithm_wins"].values())
    for algo, count in sorted(gt["algorithm_wins"].items(), key=lambda x: -x[1]):
        report += f"| {algo} | {count} | {count/total*100:.1f}% |\n"

    report += f"""
![Ground Truth Distribution](plots/ground_truth_distribution.png)

![BPB by Algorithm](plots/bpb_by_algorithm.png)

## Classifier Performance

| Metric | Value |
|--------|-------|
| Accuracy (val) | {clf['accuracy']:.4f} |
| Macro F1 (val) | {clf['macro_f1']:.4f} |
| Accuracy (test) | {clf['test_accuracy']:.4f} |
| Macro F1 (test) | {clf['test_f1']:.4f} |
| N classes | {clf['n_classes']} |
| Training samples | {clf['n_train']} |
| Best iteration | {clf['best_iteration']} |

![Confusion Matrix](plots/confusion_matrix.png)

![Feature Importance](plots/feature_importance.png)

## Benchmark Results

**Can our adaptive compressor beat the best single codec?**

| Compressor | BPB | vs Best |
|------------|-----|---------|
"""
    best_bpb = bench["best_raw"]["bpb"]
    for algo, bpb in sorted(bench["raw_codecs"].items(), key=lambda x: x[1]):
        delta = bpb - best_bpb
        marker = " ★ BEST" if algo == bench["best_raw"]["algorithm"] else ""
        report += f"| {algo} | {bpb:.4f} | +{delta:.4f}{marker} |\n"

    adaptive_delta = bench["adaptive"] - best_bpb
    win_marker = " 🎉 WINNER!" if bench["adaptive"] < best_bpb else ""
    report += f"| **ADAPTIVE (ours)** | **{bench['adaptive']:.4f}** | **{adaptive_delta:+.4f}{win_marker}** |\n"

    report += f"""
![Benchmark Comparison](plots/benchmark_comparison.png)

## Conclusion

"""
    if bench["adaptive"] < best_bpb:
        report += f"""**SUCCESS!** The supervised adaptive compressor achieves
{bench['adaptive']:.4f} BPB, which is **{abs(bench['adaptive_vs_best_raw_pct']):.2f}% better**
than the best single codec ({bench['best_raw']['algorithm']} at {best_bpb:.4f} BPB).

The key insight is that on diverse, heterogeneous text data, different
algorithms genuinely excel on different types of content (code, HTML, prose,
structured data), and the XGBoost classifier successfully learns to predict
which algorithm will work best from fast, statistical text features.
"""
    else:
        report += f"""The adaptive compressor achieved {bench['adaptive']:.4f} BPB,
which is {abs(bench['adaptive_vs_best_raw_pct']):.2f}% worse than the best single
codec ({bench['best_raw']['algorithm']} at {best_bpb:.4f} BPB).

This suggests that even with supervised learning and diverse data, the
feature set may not capture enough signal to consistently beat the strongest
algorithm. Consider:
- Adding more features (algorithm-specific BPB proxies)
- Ensemble approach (try top-2 predicted algorithms)
- Larger and more diverse training corpus
"""
    report += f"""
---
Generated: {time.strftime('%Y-%m-%d %H:%M:%S')}
"""

    report_path = ARTIFACTS_DIR / "report.md"
    report_path.write_text(report, encoding="utf-8")
    print(f"  Report: {report_path}")


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

if __name__ == "__main__":
    # Ensure src is importable
    sys.path.insert(0, str(PROJECT_ROOT))
    run_pipeline()
