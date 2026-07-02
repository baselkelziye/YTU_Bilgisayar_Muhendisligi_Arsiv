"""Train neural compressor and benchmark — Track B.

Trains character-LSTM on diverse corpus, then benchmarks:
  - Neural compressor (LSTM + arithmetic coding)
  - Best raw codec (bwt_mtf)
  - Best supervised adaptive (from v2 experiment)

Compares all three on held-out test texts.
"""

from __future__ import annotations

import json
import sys
import time
from pathlib import Path
from typing import Any

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import torch

matplotlib.use("Agg")

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from src.models.neural_compressor import NeuralCompressor
from src.codecs import bwt_codec, huffman_codec


ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v2_neural"
PLOTS_DIR = ARTIFACTS_DIR / "plots"


def load_corpus_texts(max_chars: int = 2_000_000) -> list[str]:
    """Load diverse corpus texts for training."""
    diverse_dir = PROJECT_ROOT / "data" / "diverse"
    manifest_path = diverse_dir / "manifest.csv"
    
    texts = []
    if manifest_path.exists():
        import csv
        with open(manifest_path, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                path = PROJECT_ROOT / row["path"]
                if path.exists():
                    text = path.read_text(encoding="utf-8", errors="replace")
                    texts.append(text[:50000])
    else:
        # Fallback to Gutenberg
        processed = PROJECT_ROOT / "data" / "processed" / "books"
        if processed.exists():
            for f in sorted(processed.glob("*.txt"))[:30]:
                texts.append(f.read_text(encoding="utf-8", errors="replace")[:30000])
    
    # Cap total chars
    total = 0
    capped = []
    for t in texts:
        if total + len(t) > max_chars:
            capped.append(t[:max_chars - total])
            break
        capped.append(t)
        total += len(t)
    
    return capped


def benchmark_compressor(name: str, compress_fn, decompress_fn, test_texts: list[str]) -> dict:
    """Benchmark a compressor on test texts. Returns aggregate stats."""
    bpbs = []
    times = []
    all_valid = True
    
    for text in test_texts:
        data = text.encode("utf-8")
        try:
            result = compress_fn(data)
            if result.valid:
                bpbs.append(result.bpb)
                times.append(result.elapsed_ms)
                # Verify roundtrip
                decomp = decompress_fn(result.compressed)
                if decomp.valid and decomp.compressed != data:
                    all_valid = False
            else:
                all_valid = False
        except Exception:
            all_valid = False
    
    return {
        "name": name,
        "mean_bpb": float(np.mean(bpbs)) if bpbs else 999.0,
        "median_bpb": float(np.median(bpbs)) if bpbs else 999.0,
        "std_bpb": float(np.std(bpbs)) if bpbs else 0,
        "mean_ms": float(np.mean(times)) if times else 0,
        "n_samples": len(bpbs),
        "roundtrip_valid": all_valid,
    }


def plot_training_curves(history: dict, path: Path):
    """Plot training history."""
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    
    epochs = range(1, len(history["train_loss"]) + 1)
    
    ax1.plot(epochs, history["train_loss"], "b-", label="Train")
    ax1.plot(epochs, history["val_loss"], "r-", label="Val")
    ax1.set_xlabel("Epoch")
    ax1.set_ylabel("Cross-Entropy Loss")
    ax1.set_title("Neural Compressor Training")
    ax1.legend()
    ax1.grid(alpha=0.3)
    
    ax2.plot(epochs, history["val_bpb"], "g-", linewidth=2)
    ax2.axhline(y=3.42, color="red", linestyle="--", alpha=0.5, label="bwt_mtf baseline (3.42)")
    ax2.set_xlabel("Epoch")
    ax2.set_ylabel("Bits Per Byte (BPB)")
    ax2.set_title("Validation BPB (lower is better)")
    ax2.legend()
    ax2.grid(alpha=0.3)
    
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


def plot_comparison(results: list[dict], path: Path):
    """Bar chart comparing all compressors."""
    fig, ax = plt.subplots(figsize=(10, 6))
    
    results_sorted = sorted(results, key=lambda x: x["mean_bpb"])
    names = [r["name"] for r in results_sorted]
    values = [r["mean_bpb"] for r in results_sorted]
    
    colors = []
    for name in names:
        if "Neural" in name:
            colors.append("#e74c3c")
        elif "bwt" in name.lower():
            colors.append("#3498db")
        else:
            colors.append("#2ecc71")
    
    bars = ax.barh(names, values, color=colors, edgecolor="white")
    best = values[0]
    
    for bar, val, name in zip(bars, values, names):
        delta = val - best
        suffix = f"  (+{delta:.2f})" if delta > 0.01 else "  ★ BEST"
        ax.text(bar.get_width() + 0.05, bar.get_y() + bar.get_height() / 2,
                f"{val:.3f}{suffix}", va="center", fontsize=10)
    
    ax.set_xlabel("Bits Per Byte (BPB) — lower is better")
    ax.set_title("Compression Performance Comparison")
    ax.grid(axis="x", alpha=0.3)
    plt.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)


def main():
    print("=" * 70)
    print("NEURAL COMPRESSOR — TRACK B")
    print("=" * 70)
    
    ARTIFACTS_DIR.mkdir(parents=True, exist_ok=True)
    PLOTS_DIR.mkdir(parents=True, exist_ok=True)
    
    # -----------------------------------------------------------------------
    # Step 1: Load corpus
    # -----------------------------------------------------------------------
    print("\n[1/5] Loading training corpus...")
    train_texts = load_corpus_texts(max_chars=1_000_000)
    print(f"  Loaded {len(train_texts)} texts, "
          f"{sum(len(t) for t in train_texts):,} total chars")
    
    # -----------------------------------------------------------------------
    # Step 2: Train neural compressor
    # -----------------------------------------------------------------------
    print("\n[2/5] Training neural compressor...")
    compressor = NeuralCompressor()
    
    model_dir = ARTIFACTS_DIR / "model"
    model_dir.mkdir(exist_ok=True)
    
    metrics = compressor.train(
        train_texts,
        model_dir,
        seq_len=128,
        batch_size=64,
        epochs=15,
        lr=1e-3,
        embed_dim=64,
        hidden_dim=128,
        n_layers=2,
    )
    
    print(f"  Best validation BPB: {metrics['best_bpb']:.4f}")
    print(f"  Model params: {metrics['params']:,}")
    
    # -----------------------------------------------------------------------
    # Step 3: Prepare test set
    # -----------------------------------------------------------------------
    print("\n[3/5] Preparing test set...")
    all_texts = load_corpus_texts(max_chars=3_000_000)
    # Use last 20% for testing
    split = int(len(all_texts) * 0.8)
    test_texts = all_texts[split:split + 20]
    print(f"  {len(test_texts)} test texts, "
          f"{sum(len(t) for t in test_texts):,} chars")
    
    # -----------------------------------------------------------------------
    # Step 4: Benchmark
    # -----------------------------------------------------------------------
    print("\n[4/5] Benchmarking...")
    
    results = []
    
    # Neural compressor
    print("  Testing neural compressor...")
    neural_result = benchmark_compressor(
        "Neural (LSTM+Arith)",
        compressor.compress,
        compressor.decompress,
        test_texts,
    )
    results.append(neural_result)
    print(f"    Mean BPB: {neural_result['mean_bpb']:.4f}, "
          f"Roundtrip: {'✓' if neural_result['roundtrip_valid'] else '✗'}")
    
    # bwt_mtf (best raw codec)
    print("  Testing bwt_mtf...")
    def bwt_compress(data):
        return bwt_codec.compress(data, secondary="huffman", block_size=0)
    def bwt_decompress(data):
        return bwt_codec.decompress(data, secondary="huffman", block_size=0)
    
    bwt_result = benchmark_compressor(
        "bwt_mtf (best raw)",
        bwt_compress,
        bwt_decompress,
        test_texts,
    )
    results.append(bwt_result)
    print(f"    Mean BPB: {bwt_result['mean_bpb']:.4f}, "
          f"Roundtrip: {'✓' if bwt_result['roundtrip_valid'] else '✗'}")
    
    # huffman order1
    print("  Testing huffman...")
    def huff_compress(data):
        return huffman_codec.compress(data, order=1)
    def huff_decompress(data):
        return huffman_codec.decompress(data, order=1)
    
    huff_result = benchmark_compressor(
        "huffman (order-1)",
        huff_compress,
        huff_decompress,
        test_texts,
    )
    results.append(huff_result)
    print(f"    Mean BPB: {huff_result['mean_bpb']:.4f}")
    
    # -----------------------------------------------------------------------
    # Step 5: Generate report
    # -----------------------------------------------------------------------
    print("\n[5/5] Generating report...")
    
    results_sorted = sorted(results, key=lambda x: x["mean_bpb"])
    best = results_sorted[0]
    
    print(f"\n  🏆 Best compressor: {best['name']} at {best['mean_bpb']:.4f} BPB")
    
    # Plots
    plot_training_curves(metrics["history"], PLOTS_DIR / "training_curves.png")
    plot_comparison(results, PLOTS_DIR / "comparison.png")
    
    # Save results
    output = {
        "neural_compressor": {
            "best_val_bpb": metrics["best_bpb"],
            "params": metrics["params"],
            "architecture": {
                "embed_dim": 64,
                "hidden_dim": 128,
                "n_layers": 2,
                "seq_len": 128,
            },
        },
        "benchmark": {r["name"]: r for r in results},
        "best": best["name"],
    }
    
    with open(ARTIFACTS_DIR / "results.json", "w") as f:
        json.dump(output, f, indent=2)
    
    # Markdown report
    report = f"""# Neural Compressor — Track B Report

## Approach

**Prediction = Compression**: A character-level LSTM predicts next-character
probabilities, and arithmetic coding uses those probabilities for compression.
Better predictions → better compression.

## Architecture

| Component | Value |
|-----------|-------|
| Type | Character-level LSTM |
| Embedding dim | 64 |
| Hidden dim | 128 |
| Layers | 2 |
| Sequence length | 128 |
| Parameters | {metrics['params']:,} |
| Training tokens | ~1M |

## Training

![Training Curves](plots/training_curves.png)

- Best validation BPB: **{metrics['best_bpb']:.4f}**
- bwt_mtf baseline: 3.42 BPB

## Benchmark Results

| Compressor | Mean BPB | vs Best |
|------------|----------|---------|
"""
    best_bpb = best["mean_bpb"]
    for r in results_sorted:
        delta = r["mean_bpb"] - best_bpb
        marker = " ★ BEST" if r["name"] == best["name"] else ""
        report += f"| {r['name']} | {r['mean_bpb']:.4f} | +{delta:.4f}{marker} |\n"
    
    report += f"""
![Comparison](plots/comparison.png)

## Conclusion

"""
    if "Neural" in best["name"]:
        report += f"""**SUCCESS!** The neural compressor achieves {best['mean_bpb']:.4f} BPB,
beating bwt_mtf and establishing that "prediction = compression" works even
with a small LSTM.
"""
    else:
        report += f"""The neural compressor achieved {neural_result['mean_bpb']:.4f} BPB,
which is {'better' if neural_result['mean_bpb'] < bwt_result['mean_bpb'] else 'worse'}
than bwt_mtf ({bwt_result['mean_bpb']:.4f} BPB).

To improve:
- Larger model (more hidden dims, more layers)
- More training data (>10M tokens)
- Longer training
- Better arithmetic coder implementation
"""
    report += f"""
---
Generated: {time.strftime('%Y-%m-%d %H:%M:%S')}
"""
    
    report_path = ARTIFACTS_DIR / "report.md"
    report_path.write_text(report, encoding="utf-8")
    print(f"  Report: {report_path}")
    print(f"\n✅ All artifacts saved to {ARTIFACTS_DIR}/")


if __name__ == "__main__":
    main()
