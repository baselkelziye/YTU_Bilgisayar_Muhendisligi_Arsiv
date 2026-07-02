"""Generate plots from saved grid results + BPB results."""

import json, pickle, sys
from pathlib import Path
import numpy as np
from collections import Counter, defaultdict

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v3_final"
PLOTS_DIR = ARTIFACTS_DIR / "plots"
PLOTS_DIR.mkdir(parents=True, exist_ok=True)

ALGO_COLORS = {
    "huffman": "#e74c3c", "lzw": "#3498db", "arithmetic": "#9b59b6",
    "bwt_mtf": "#2ecc71", "rle_huffman": "#f39c12",
}

# Load data
with open(ARTIFACTS_DIR / "grid_results.pkl", "rb") as f:
    results = pickle.load(f)
with open(ARTIFACTS_DIR / "bpb_results.json") as f:
    bpb_data = json.load(f)

print(f"Loaded {len(results)} chunks, {len(bpb_data['model_bpbs'])} models")

# ---------- Plot 1: Algorithm BPB boxplot ----------
print("Plot 1: Algorithm BPB...")
algo_bpbs = defaultdict(list)
for r in results:
    for a, b in r["all_bpbs"].items():
        if b < 100:
            algo_bpbs[a].append(b)
fig, ax = plt.subplots(figsize=(10, 6))
order = sorted(algo_bpbs.keys(), key=lambda a: np.median(algo_bpbs[a]))
data = [algo_bpbs[a] for a in order]
bp = ax.boxplot(data, tick_labels=order, patch_artist=True)
for patch, a in zip(bp["boxes"], order):
    patch.set_facecolor(ALGO_COLORS.get(a, "#gray"))
ax.set_ylabel("Bits Per Byte (BPB)")
ax.set_title(f"Compression Performance by Algorithm ({len(results):,} chunks)")
ax.grid(axis="y", alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "algo_bpb_boxplot.png", dpi=150); plt.close(fig)

# ---------- Plot 2: Algorithm speed boxplot ----------
print("Plot 2: Algorithm Speed...")
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
ax.set_title(f"Compression Speed by Algorithm (per 1KB chunk, {len(results):,} chunks)")
ax.grid(axis="y", alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "algo_speed_boxplot.png", dpi=150); plt.close(fig)

# ---------- Plot 3: BPB vs Speed scatter ----------
print("Plot 3: BPB vs Speed...")
fig, ax = plt.subplots(figsize=(10, 7))
algo_medians = {}
for algo in ["huffman", "lzw", "arithmetic", "bwt_mtf", "rle_huffman"]:
    bpbs = [r["all_bpbs"][algo] for r in results if r["all_bpbs"].get(algo, 999) < 100]
    times = [r["all_times"][algo] for r in results]
    med_bpb = np.median(bpbs)
    med_time = np.median(times)
    algo_medians[algo] = (med_bpb, med_time)
    ax.scatter(med_bpb, med_time, s=200, c=ALGO_COLORS[algo],
               label=f"{algo}\n({med_bpb:.2f} BPB, {med_time:.2f} ms)",
               edgecolors="black", linewidth=1, zorder=5)
ax.set_xlabel("Median BPB (lower is better)")
ax.set_ylabel("Median Time per chunk (ms)")
ax.set_title("BPB vs Speed Tradeoff")
ax.legend(fontsize=8, loc="upper left")
ax.grid(alpha=0.3)
ax.invert_xaxis()
plt.tight_layout(); fig.savefig(PLOTS_DIR / "bpb_vs_speed.png", dpi=150); plt.close(fig)

# ---------- Plot 4: Model comparison bar chart ----------
print("Plot 4: Model comparison...")
all_bpbs = {**bpb_data["raw_bpbs"], **bpb_data["model_bpbs"]}
items = sorted(all_bpbs.items(), key=lambda x: x[1])
fig, ax = plt.subplots(figsize=(11, 7))
labels = [x[0] for x in items]
values = [x[1] for x in items]
colors = [ALGO_COLORS.get(l, "#1abc9c" if ("MLP" in l or "XGB" in l or "Ensemble" in l) else "#95a5a6") for l in labels]
bars = ax.barh(labels, values, color=colors, edgecolor="white")
best = values[0]
for bar, val in zip(bars, values):
    delta = val - best
    suffix = f"  +{delta:.3f}" if delta > 0.001 else "  ★ BEST"
    ax.text(bar.get_width() + 0.03, bar.get_y() + bar.get_height()/2,
            f"{val:.4f}{suffix}", va="center", fontsize=9)
ax.set_xlabel("Mean BPB (lower is better)")
ts = bpb_data.get("improvement", 0)
ax.set_title(f"Model Comparison: Adaptive vs Raw Codecs ({len(results):,} chunks, improved by {ts:.2f}%)")
ax.grid(axis="x", alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "model_comparison.png", dpi=150); plt.close(fig)

# ---------- Plot 5: Model speed comparison ----------
print("Plot 5: Model speed...")
timing = bpb_data["timing"]
fig, ax = plt.subplots(figsize=(9, 5))
items = sorted(timing.items(), key=lambda x: -x[1])
labels = [x[0] for x in items]
values = [x[1] for x in items]
colors = ["#1abc9c" if ("MLP" in l or "XGB" in l) else "#3498db" for l in labels]
ax.barh(labels, values, color=colors, edgecolor="white")
for i, (label, val) in enumerate(items):
    unit = "ms"
    v = val
    if val < 0.01:
        v = val * 1000
        unit = "µs"
    ax.text(val + max(values) * 0.01, i, f"{v:.2f} {unit}", va="center", fontsize=9)
ax.set_xlabel("Time per chunk (ms, log scale)")
ax.set_xscale("log")
ax.set_title("Model & Algorithm Inference Speed (log scale)")
ax.grid(axis="x", alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "model_speed.png", dpi=150); plt.close(fig)

# ---------- Plot 6: Algorithm win distribution ----------
print("Plot 6: Algorithm wins...")
wins = Counter(r["best_algo"] for r in results)
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
labels = list(wins.keys())
sizes = list(wins.values())
colors_pie = [ALGO_COLORS.get(a, "gray") for a in labels]
wedges, texts, autotexts = ax1.pie(sizes, labels=labels, autopct="%1.1f%%", colors=colors_pie)
ax1.set_title(f"Ground Truth: Best Algorithm Distribution\n({len(results):,} chunks)")

first_algo = [r["best_algo"] for r in results[:200]]
algo_idx = {a: i for i, a in enumerate(sorted(set(first_algo)))}
y = [algo_idx[a] for a in first_algo]
ax2.scatter(range(len(y)), y, c=[ALGO_COLORS.get(a, "gray") for a in first_algo], s=5, alpha=0.6)
ax2.set_yticks(list(algo_idx.values()))
ax2.set_yticklabels(list(algo_idx.keys()))
ax2.set_xlabel("Chunk index"); ax2.set_title("Algorithm Wins — First 200 Chunks")
ax2.grid(alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "algorithm_wins.png", dpi=150); plt.close(fig)

# ---------- Plot 7: Per-domain BPB ----------
print("Plot 7: Per-domain...")
domain_bpbs = defaultdict(lambda: defaultdict(list))
for r in results:
    dom = r.get("domain", "unknown")
    best = r["best_algo"]
    domain_bpbs[dom][best].append(r["best_bpb"])

domains = sorted(domain_bpbs.keys(), key=lambda d: -sum(len(v) for v in domain_bpbs[d].values()))
n_domains = min(10, len(domains))
domains = domains[:n_domains]
all_algos = sorted(set(a for d in domains for a in domain_bpbs[d]))

fig, ax = plt.subplots(figsize=(max(8, n_domains * 1.5), 6))
x = np.arange(n_domains)
width = 0.8 / len(all_algos)

for i, algo in enumerate(all_algos):
    means = [np.mean(domain_bpbs[d].get(algo, [5])) for d in domains]
    ax.bar(x + i * width, means, width, label=algo, color=ALGO_COLORS.get(algo, "gray"))

ax.set_xticks(x + width * (len(all_algos) - 1) / 2)
ax.set_xticklabels(domains, rotation=30, ha="right", fontsize=8)
ax.set_ylabel("Mean BPB")
ax.set_title("Best Algorithm Distribution by Domain (top 10 domains)")
ax.legend(fontsize=7)
ax.grid(axis="y", alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "per_domain.png", dpi=150); plt.close(fig)

# ---------- Plot 8: BPB histogram ----------
print("Plot 8: BPB histogram...")
fig, ax = plt.subplots(figsize=(10, 6))
for algo in ["bwt_mtf", "lzw", "rle_huffman"]:
    bpbs = [r["all_bpbs"][algo] for r in results if r["all_bpbs"].get(algo, 999) < 100]
    ax.hist(bpbs, bins=50, alpha=0.5, label=f"{algo} (μ={np.mean(bpbs):.2f})", color=ALGO_COLORS[algo])
ax.set_xlabel("BPB"); ax.set_ylabel("Chunk Count")
ax.set_title("BPB Distribution by Algorithm")
ax.legend(); ax.grid(alpha=0.3)
plt.tight_layout(); fig.savefig(PLOTS_DIR / "bpb_histogram.png", dpi=150); plt.close(fig)

print(f"\n✅ All plots saved to {PLOTS_DIR}/")

# List plots
for p in sorted(PLOTS_DIR.glob("*.png")):
    print(f"  {p.name}")
