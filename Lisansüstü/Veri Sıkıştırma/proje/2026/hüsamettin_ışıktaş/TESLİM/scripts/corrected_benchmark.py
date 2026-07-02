"""Corrected benchmark v2 — no text chunks needed.
Uses pre-computed all_bpbs and all_times from grid search.
Only computes MLP inference time fresh."""

import json, pickle, sys, time, math
from pathlib import Path
import numpy as np

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.model_selection import train_test_split
import torch
import torch.nn as nn
from torch.utils.data import DataLoader, TensorDataset

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v3_final"
CHUNK_SIZE = 1024

FEATURE_NAMES = [
    "n_chars", "n_lines", "n_words", "avg_word_len", "std_word_len",
    "unique_char_ratio", "unique_word_ratio", "digit_ratio", "whitespace_ratio",
    "punctuation_ratio", "uppercase_ratio", "vowel_ratio", "entropy_char",
    "bigram_repetition_ratio", "trigram_repetition_ratio", "longest_repeat_run",
    "newline_density", "mean_line_length", "std_line_length",
    "ascii_ratio", "non_ascii_ratio",
]

ALGORITHMS = ["huffman", "lzw", "arithmetic", "bwt_mtf", "rle_huffman"]
HEADER_BITS = math.ceil(math.log2(len(ALGORITHMS)))  # 3 bits


class SimpleMLP(nn.Module):
    def __init__(self, in_dim, hidden, n_classes):
        super().__init__()
        layers = []
        prev = in_dim
        for h in hidden:
            layers.extend([nn.Linear(prev, h), nn.ReLU(), nn.BatchNorm1d(h), nn.Dropout(0.2)])
            prev = h
        layers.append(nn.Linear(prev, n_classes))
        self.net = nn.Sequential(*layers)
    def forward(self, x): return self.net(x)


def main():
    print("=" * 70)
    print("CORRECTED BENCHMARK: MLP inference + algo time + header overhead")
    print("=" * 70)

    # Load grid results
    with open(ARTIFACTS_DIR / "grid_results.pkl", "rb") as f:
        results = pickle.load(f)
    print(f"Loaded {len(results)} grid results")

    # Features + labels
    X = np.array([[r["features"][f] for f in FEATURE_NAMES] for r in results])
    y_str = np.array([r["best_algo"] for r in results])
    le = LabelEncoder(); y = le.fit_transform(y_str)
    scaler = StandardScaler(); X = scaler.fit_transform(X)

    # Split
    all_idx = np.arange(len(X))
    X_temp, X_test, y_temp, y_test, idx_temp, idx_test = train_test_split(
        X, y, all_idx, test_size=0.15, random_state=42, stratify=y)
    X_train, X_val, y_train, y_val = train_test_split(
        X_temp, y_temp, test_size=0.1765, random_state=42, stratify=y_temp)
    test_results = [results[i] for i in idx_test]
    print(f"Split: train={len(X_train)}, val={len(X_val)}, test={len(test_results)}")

    # Train MLP-Large
    print("Training MLP-Large...")
    mlp = SimpleMLP(21, [128, 64, 32], len(le.classes_))
    opt = torch.optim.AdamW(mlp.parameters(), lr=1e-3, weight_decay=1e-4)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, 80)
    crit = nn.CrossEntropyLoss()
    Xt = torch.tensor(X_train, dtype=torch.float32)
    yt = torch.tensor(y_train, dtype=torch.long)
    Xv = torch.tensor(X_val, dtype=torch.float32)
    yv = torch.tensor(y_val, dtype=torch.long)
    ds = TensorDataset(Xt, yt)
    dl = DataLoader(ds, batch_size=128, shuffle=True)

    best_loss = float("inf"); best_state = None
    for epoch in range(80):
        mlp.train()
        for bx, by in dl:
            opt.zero_grad(); loss = crit(mlp(bx), by); loss.backward(); opt.step()
        sched.step()
        mlp.eval()
        with torch.no_grad(): val_loss = crit(mlp(Xv), yv).item()
        if val_loss < best_loss: best_loss = val_loss; best_state = {k: v.clone() for k, v in mlp.state_dict().items()}
    mlp.load_state_dict(best_state)
    mlp.eval()

    # Benchmark: for each test chunk
    print("\n" + "=" * 70)
    print("PER-CHUNK BENCHMARK (using pre-computed algorithm times)")
    print("=" * 70)

    adaptive_total_times = []
    adaptive_total_bpbs = []
    bwt_times = []
    bwt_bpbs = []
    mlp_inference_times = []
    selected_algo_times = []

    X_test_t = torch.tensor(X_test, dtype=torch.float32)

    for i, r in enumerate(test_results):
        # MLP inference
        t0 = time.perf_counter()
        with torch.no_grad():
            logits = mlp(X_test_t[i:i+1])
            pred = logits.argmax(dim=1).item()
        mlp_time = (time.perf_counter() - t0) * 1000
        mlp_inference_times.append(mlp_time)

        selected_algo = le.classes_[pred]
        algo_time = r["all_times"][selected_algo]
        selected_algo_times.append(algo_time)

        total_time = mlp_time + algo_time
        adaptive_total_times.append(total_time)

        # BPB with header overhead
        algo_bpb = r["all_bpbs"][selected_algo]
        header_overhead_bpb = HEADER_BITS / CHUNK_SIZE  # bits per byte
        total_bpb = algo_bpb + header_overhead_bpb
        adaptive_total_bpbs.append(total_bpb)

        # bwt_mtf
        bwt_times.append(r["all_times"]["bwt_mtf"])
        bwt_bpbs.append(r["all_bpbs"]["bwt_mtf"])

    # Summary
    n = len(test_results)
    adaptive_mean_time = float(np.mean(adaptive_total_times))
    bwt_mean_time = float(np.mean(bwt_times))
    adaptive_mean_bpb = float(np.mean(adaptive_total_bpbs))
    bwt_mean_bpb = float(np.mean(bwt_bpbs))
    mlp_mean_time = float(np.mean(mlp_inference_times))
    algo_mean_time = float(np.mean(selected_algo_times))
    improvement = (bwt_mean_bpb - adaptive_mean_bpb) / bwt_mean_bpb * 100
    time_ratio = adaptive_mean_time / bwt_mean_time if bwt_mean_time > 0 else 0

    print(f"\n{'='*55}")
    print(f"RESULTS ({n} test chunks)")
    print(f"{'='*55}")

    print(f"\n📦 BPB (with {HEADER_BITS}-bit header per chunk):")
    print(f"  Adaptive (MLP+algo+header): {adaptive_mean_bpb:.4f} BPB")
    print(f"  bwt_mtf (single codec):      {bwt_mean_bpb:.4f} BPB")
    print(f"  Header overhead:             {HEADER_BITS} bits/chunk = {HEADER_BITS/(CHUNK_SIZE*8)*100:.4f}%")
    if improvement > 0:
        print(f"  🎉 ADAPTIVE WINS by {improvement:.2f}%")
    else:
        print(f"  ❌ Adaptive is {abs(improvement):.2f}% worse")

    print(f"\n⏱️  Time per chunk:")
    print(f"  Adaptive (MLP+algo): {adaptive_mean_time:.4f} ms")
    print(f"    ├─ MLP inference:   {mlp_mean_time:.4f} ms ({mlp_mean_time/adaptive_mean_time*100:.1f}%)")
    print(f"    └─ Algo compress:   {algo_mean_time:.4f} ms ({algo_mean_time/adaptive_mean_time*100:.1f}%)")
    print(f"  bwt_mtf (single):    {bwt_mean_time:.4f} ms")
    print(f"  Time ratio:          {time_ratio:.2f}x {'slower' if time_ratio > 1 else 'faster'}")

    print(f"\n💾 Storage overhead:")
    total_header_bytes = n * math.ceil(HEADER_BITS / 8)
    total_data_bytes = n * CHUNK_SIZE
    print(f"  Total chunks:        {n}")
    print(f"  Header bytes:        {total_header_bytes} ({total_header_bytes/1024:.1f} KB)")
    print(f"  Total data:          {total_data_bytes/1024:.1f} KB")
    print(f"  Header/data ratio:   {total_header_bytes/total_data_bytes*100:.4f}%")

    # Per-algorithm breakdown
    print(f"\n📊 Algorithm selection breakdown:")
    preds = []
    with torch.no_grad():
        for i in range(len(X_test)):
            logits = mlp(X_test_t[i:i+1])
            preds.append(logits.argmax(dim=1).item())
    from collections import Counter
    pred_counts = Counter(le.classes_[p] for p in preds)
    for algo, count in pred_counts.most_common():
        avg_time = float(np.mean([test_results[i]["all_times"][algo] 
                                   for i, p in enumerate(preds) if le.classes_[p] == algo]))
        avg_bpb = float(np.mean([test_results[i]["all_bpbs"][algo]
                                  for i, p in enumerate(preds) if le.classes_[p] == algo]))
        print(f"  {algo:15s}: {count:4d} chunks ({count/n*100:5.1f}%) | "
              f"avg time={avg_time:.3f}ms | avg BPB={avg_bpb:.3f}")

    # Save
    output = {
        "adaptive_bpb_with_header": adaptive_mean_bpb,
        "bwt_bpb": bwt_mean_bpb,
        "improvement_pct": float(improvement),
        "adaptive_time_ms": adaptive_mean_time,
        "bwt_time_ms": bwt_mean_time,
        "time_ratio": float(time_ratio),
        "mlp_inference_ms": mlp_mean_time,
        "selected_algo_ms": algo_mean_time,
        "header_bits_per_chunk": HEADER_BITS,
        "header_overhead_pct": float(HEADER_BITS / (CHUNK_SIZE * 8) * 100),
        "n_test_chunks": n,
        "algorithm_breakdown": {algo: count for algo, count in pred_counts.most_common()},
    }
    with open(ARTIFACTS_DIR / "corrected_benchmark.json", "w") as f:
        json.dump(output, f, indent=2)
    print(f"\n✅ Saved to corrected_benchmark.json")


if __name__ == "__main__":
    main()
