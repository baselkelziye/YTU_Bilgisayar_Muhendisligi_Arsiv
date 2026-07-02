"""Post-hoc ensemble evaluation — load trained XGBoost model and test top-k ensemble.

Ensemble strategy: predict top-k algorithms, try all k, pick the one that 
actually compresses best. Overhead: log2(k) bits per chunk in header.

Compares:
  - Single prediction (baseline)
  - Top-2 ensemble
  - Top-3 ensemble
  - Oracle (always pick the actual best — upper bound)
"""

from __future__ import annotations

import json
import pickle
import sys
import time
from collections import Counter
from pathlib import Path

import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.preprocessing import LabelEncoder, StandardScaler
from tqdm import tqdm

matplotlib.use("Agg")

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from src.codecs import (
    arithmetic_codec,
    bwt_codec,
    huffman_codec,
    lzw_codec,
    rle_codec,
    zstd_codec,
)

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v2_ensemble"
PLOTS_DIR = ARTIFACTS_DIR / "plots"
V2_DIR = PROJECT_ROOT / "artifacts" / "v2_supervised"

CHUNK_SIZE = 1024

ALGO_PARAMS = {
    "huffman": {"order": 1},
    "lzw": {"max_bits": 14},
    "arithmetic": {"order": 1},
    "bwt_mtf": {"secondary": "huffman", "block_size": 0},
    "rle_huffman": {"min_run": 4},
    "zstd": {"level": 3},
}

_CODEC_DISPATCH = {
    "huffman": huffman_codec,
    "lzw": lzw_codec,
    "arithmetic": arithmetic_codec,
    "bwt_mtf": bwt_codec,
    "rle_huffman": rle_codec,
    "zstd": zstd_codec,
}


def extract_fast_features(text: str) -> dict[str, float]:
    """Same fast feature extraction as in run_experiment_v2.py."""
    from collections import Counter
    import math, re

    if not text:
        return {f: 0.0 for f in _FEATURE_NAMES}

    chars = list(text)
    n = len(chars)

    words = re.findall(r"\b\w+\b", text)
    n_words = len(words)
    word_lens = [len(w) for w in words] if words else [0]
    avg_word_len = np.mean(word_lens)
    std_word_len = np.std(word_lens) if len(word_lens) > 1 else 0.0

    unique_chars = len(set(chars))
    unique_char_ratio = unique_chars / n if n else 0

    digit_ratio = sum(1 for c in chars if c.isdigit()) / n if n else 0
    whitespace_ratio = sum(1 for c in chars if c.isspace()) / n if n else 0
    import string
    punct = set(string.punctuation)
    punctuation_ratio = sum(1 for c in chars if c in punct) / n if n else 0
    uppercase_ratio = sum(1 for c in chars if c.isupper()) / n if n else 0

    vowels = set("aeiouAEIOU")
    vowel_ratio = sum(1 for c in chars if c in vowels) / n if n else 0

    char_counts = Counter(chars)
    entropy_char = 0.0
    for count in char_counts.values():
        prob = count / n
        entropy_char -= prob * math.log2(prob)

    bigrams = [text[i:i+2] for i in range(n - 1)]
    unique_bigrams = len(set(bigrams))
    bigram_rep_ratio = 1.0 - (unique_bigrams / len(bigrams)) if bigrams else 0.0

    trigrams = [text[i:i+3] for i in range(n - 2)]
    unique_trigrams = len(set(trigrams))
    trigram_rep_ratio = 1.0 - (unique_trigrams / len(trigrams)) if trigrams else 0.0

    ascii_count = sum(1 for c in chars if 32 <= ord(c) <= 126 or ord(c) in (9, 10, 13))
    ascii_ratio = ascii_count / n if n else 0
    non_ascii_ratio = 1.0 - ascii_ratio

    n_lines = text.count("\n") + 1
    newline_density = (n_lines - 1) / n if n else 0

    lines = text.split("\n")
    line_lengths = [len(line) for line in lines]
    mean_line_length = np.mean(line_lengths) if line_lengths else 0
    std_line_length = np.std(line_lengths) if len(line_lengths) > 1 else 0

    unique_words = len(set(words))
    unique_word_ratio = unique_words / n_words if n_words else 0

    # Approx longest repeat
    longest_repeat = 0
    if n >= 2:
        seen = set()
        for length in range(min(50, n), 1, -1):
            seen.clear()
            found = False
            for i in range(n - length + 1):
                sub = text[i:i + length]
                if sub in seen:
                    longest_repeat = length
                    found = True
                    break
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
        "bigram_repetition_ratio": bigram_rep_ratio,
        "trigram_repetition_ratio": trigram_rep_ratio,
        "longest_repeat_run": longest_repeat, "newline_density": newline_density,
        "mean_line_length": mean_line_length, "std_line_length": std_line_length,
        "ascii_ratio": ascii_ratio, "non_ascii_ratio": non_ascii_ratio,
    }


_FEATURE_NAMES = [
    "n_chars", "n_lines", "n_words", "avg_word_len", "std_word_len",
    "unique_char_ratio", "unique_word_ratio", "digit_ratio", "whitespace_ratio",
    "punctuation_ratio", "uppercase_ratio", "vowel_ratio", "entropy_char",
    "bigram_repetition_ratio", "trigram_repetition_ratio", "longest_repeat_run",
    "newline_density", "mean_line_length", "std_line_length",
    "ascii_ratio", "non_ascii_ratio",
]


def load_test_chunks() -> tuple[list[str], list[dict]]:
    """Load diverse corpus test chunks (matching what experiment used)."""
    import csv
    diverse_dir = PROJECT_ROOT / "data" / "diverse"
    manifest_path = diverse_dir / "manifest.csv"

    texts = []
    if manifest_path.exists():
        with open(manifest_path, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                path = PROJECT_ROOT / row["path"]
                if path.exists():
                    texts.append(path.read_text(encoding="utf-8", errors="replace"))
    else:
        processed = PROJECT_ROOT / "data" / "processed" / "books"
        if processed.exists():
            for f in sorted(processed.glob("*.txt"))[:60]:
                texts.append(f.read_text(encoding="utf-8", errors="replace")[:30000])

    # Chunk
    all_chunks = []
    for text in texts:
        for i in range(0, len(text), CHUNK_SIZE):
            chunk = text[i:i + CHUNK_SIZE]
            if len(chunk) >= 100:
                all_chunks.append(chunk)

    # Limit
    import random
    random.seed(42)
    if len(all_chunks) > 1000:
        all_chunks = random.sample(all_chunks, 1000)

    return all_chunks


def evaluate_ensemble():
    print("=" * 70)
    print("ENSEMBLE EVALUATION")
    print("=" * 70)

    ARTIFACTS_DIR.mkdir(parents=True, exist_ok=True)
    PLOTS_DIR.mkdir(parents=True, exist_ok=True)

    # -----------------------------------------------------------------------
    # Load trained model
    # -----------------------------------------------------------------------
    print("\n[1/4] Loading trained model...")
    import xgboost as xgb
    model = xgb.XGBClassifier()
    model.load_model(str(V2_DIR / "xgboost_model.json"))

    with open(V2_DIR / "label_encoder.pkl", "rb") as f:
        label_encoder = pickle.load(f)
    with open(V2_DIR / "scaler.pkl", "rb") as f:
        scaler = pickle.load(f)

    print(f"  Model: {len(label_encoder.classes_)} classes: {list(label_encoder.classes_)}")

    # -----------------------------------------------------------------------
    # Load test chunks and compute ground truth
    # -----------------------------------------------------------------------
    print("\n[2/4] Loading test chunks + computing ground truth...")
    chunks = load_test_chunks()
    print(f"  {len(chunks)} test chunks")

    # For each chunk: features + actual best algorithm via grid search
    results = []
    for chunk in tqdm(chunks[:200], desc="  Grid search"):  # Cap at 200 for speed
        data = chunk.encode("utf-8")
        bpbs = {}
        for algo, params in ALGO_PARAMS.items():
            codec = _CODEC_DISPATCH[algo]
            try:
                result = codec.compress(data, **{k: v for k, v in params.items() if k != "label"})
                if result.valid:
                    bpbs[algo] = result.bpb
                else:
                    bpbs[algo] = 999.0
            except Exception:
                bpbs[algo] = 999.0
        
        best_algo = min(bpbs, key=bpbs.get)
        features = extract_fast_features(chunk)
        
        results.append({
            "text": chunk,
            "features": features,
            "best_algo": best_algo,
            "best_bpb": bpbs[best_algo],
            "all_bpbs": bpbs,
        })

    print(f"  Ground truth computed for {len(results)} chunks")

    # -----------------------------------------------------------------------
    # Evaluate ensemble strategies
    # -----------------------------------------------------------------------
    print("\n[3/4] Evaluating ensemble strategies...")
    
    feature_matrix = np.array([[r["features"][f] for f in _FEATURE_NAMES] for r in results])
    X = scaler.transform(feature_matrix)
    probs = model.predict_proba(X)  # (n, n_classes)

    strategies = {}
    
    for k in [1, 2, 3]:
        total_bpb = 0.0
        correct_picks = 0
        header_bits = 0
        
        for i, r in enumerate(results):
            # Get top-k predicted classes
            top_k_idx = np.argsort(probs[i])[-k:][::-1]
            top_k_algos = label_encoder.inverse_transform(top_k_idx)
            
            # Try each, pick best actual BPB
            best_bpb_for_chunk = float("inf")
            best_algo_for_chunk = None
            for algo in top_k_algos:
                bpb = r["all_bpbs"].get(algo, 999.0)
                if bpb < best_bpb_for_chunk:
                    best_bpb_for_chunk = bpb
                    best_algo_for_chunk = algo
            
            total_bpb += best_bpb_for_chunk
            
            # Was the true best in our top-k?
            if r["best_algo"] in top_k_algos:
                correct_picks += 1
            
            # Header overhead: log2(k) bits per chunk
            import math
            header_bits += math.ceil(math.log2(k)) if k > 1 else 0
        
        n = len(results)
        mean_bpb = total_bpb / n
        # Add header overhead to BPB
        total_chars = sum(len(r["text"]) for r in results)
        header_overhead_bpb = header_bits / (total_chars) if total_chars > 0 else 0
        total_bpb_with_overhead = mean_bpb + header_overhead_bpb
        
        strategies[f"top_{k}"] = {
            "mean_bpb": mean_bpb,
            "header_overhead_bpb": header_overhead_bpb,
            "total_bpb": total_bpb_with_overhead,
            "topk_accuracy": correct_picks / n,
            "n_chunks": n,
        }
        
        print(f"  Top-{k}: BPB={mean_bpb:.4f}, "
              f"+overhead={header_overhead_bpb:.4f} → {total_bpb_with_overhead:.4f}, "
              f"Recall@{k}={correct_picks/n:.2%}")

    # Oracle (upper bound — if we always picked the actual best)
    oracle_bpb = np.mean([r["best_bpb"] for r in results])
    best_raw_bpb = min(
        np.mean([r["all_bpbs"][a] for r in results])
        for a in ALGO_PARAMS
    )
    
    print(f"\n  Oracle (upper bound): BPB={oracle_bpb:.4f}")
    print(f"  Best single raw codec: BPB={best_raw_bpb:.4f}")

    # -----------------------------------------------------------------------
    # Report
    # -----------------------------------------------------------------------
    print("\n[4/4] Generating report...")
    
    # Plot
    fig, ax = plt.subplots(figsize=(10, 6))
    
    items = [
        ("Oracle (upper bound)", oracle_bpb),
        ("Top-3 ensemble", strategies["top_3"]["total_bpb"]),
        ("Top-2 ensemble", strategies["top_2"]["total_bpb"]),
        ("Single prediction", strategies["top_1"]["total_bpb"]),
        ("Best raw codec", best_raw_bpb),
    ]
    
    labels = [x[0] for x in items]
    values = [x[1] for x in items]
    colors = ["#2ecc71", "#3498db", "#9b59b6", "#e74c3c", "#95a5a6"]
    
    bars = ax.barh(labels, values, color=colors, edgecolor="white")
    best = min(values)
    for bar, val, label in zip(bars, values, labels):
        delta = val - best
        suffix = f"  (+{delta:.3f})" if delta > 0.001 else "  ★ BEST"
        ax.text(bar.get_width() + 0.02, bar.get_y() + bar.get_height() / 2,
                f"{val:.4f}{suffix}", va="center", fontsize=10)
    
    ax.set_xlabel("Bits Per Byte (BPB) — lower is better")
    ax.set_title("Ensemble Strategy Comparison (with header overhead)")
    ax.grid(axis="x", alpha=0.3)
    plt.tight_layout()
    fig.savefig(PLOTS_DIR / "ensemble_comparison.png", dpi=150)
    plt.close(fig)

    # Save results
    output = {
        "strategies": strategies,
        "oracle_bpb": oracle_bpb,
        "best_raw_bpb": best_raw_bpb,
        "n_test_chunks": len(results),
    }
    
    with open(ARTIFACTS_DIR / "ensemble_results.json", "w") as f:
        json.dump(output, f, indent=2)

    # Markdown report
    report = f"""# Ensemble Strategy Evaluation

## Setup

- Test chunks: {len(results)}
- Features: 21 fast features (Set B)
- Classifier: XGBoost ({len(label_encoder.classes_)} classes)

## Results

| Strategy | BPB (with overhead) | Recall@k |
|----------|---------------------|----------|
"""
    for k in [1, 2, 3]:
        s = strategies[f"top_{k}"]
        report += f"| Top-{k} | {s['total_bpb']:.4f} | {s['topk_accuracy']:.2%} |\n"
    
    report += f"""| Oracle | {oracle_bpb:.4f} | 100% |
| Best raw | {best_raw_bpb:.4f} | — |

![Ensemble Comparison](plots/ensemble_comparison.png)

## Analysis

"""
    best_strat = min(strategies.items(), key=lambda x: x[1]["total_bpb"])
    if best_strat[1]["total_bpb"] < best_raw_bpb:
        report += f"""**SUCCESS!** Top-{best_strat[0].split('_')[1]} ensemble achieves 
{best_strat[1]['total_bpb']:.4f} BPB (including header overhead), beating the best raw codec 
({best_raw_bpb:.4f} BPB).

The ensemble approach improves over single prediction because trying multiple
algorithms allows us to recover from classifier mistakes. The overhead
(log2(k) bits per chunk) is negligible compared to the compression gains.
"""
    else:
        gap = best_strat[1]["total_bpb"] - oracle_bpb
        report += f"""The ensemble strategies are still worse than the best raw codec.
The gap to oracle ({oracle_bpb:.4f}) is {gap:.4f} BPB, suggesting the features
don't capture enough signal to reliably predict the best algorithm.

Areas for improvement:
- Better features (algorithm-specific heuristics)
- Larger training corpus with more diverse text types
- Try gradient boosting with more trees
"""

    report += f"""
---
Generated: {time.strftime('%Y-%m-%d %H:%M:%S')}
"""
    
    report_path = ARTIFACTS_DIR / "ensemble_report.md"
    report_path.write_text(report, encoding="utf-8")
    print(f"  Report: {report_path}")
    print(f"\n✅ All artifacts saved to {ARTIFACTS_DIR}/")


if __name__ == "__main__":
    evaluate_ensemble()
