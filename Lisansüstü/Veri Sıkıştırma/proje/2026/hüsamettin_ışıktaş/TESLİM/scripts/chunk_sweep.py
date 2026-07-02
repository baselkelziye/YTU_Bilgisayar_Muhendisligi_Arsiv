"""Chunk size sweep: test 4 sizes on 2000 chunks, compare adaptive vs bwt_mtf."""

import pickle, sys, time, math
from pathlib import Path
import numpy as np
from collections import Counter, defaultdict

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from src.codecs import arithmetic_codec, bwt_codec, huffman_codec, lzw_codec, rle_codec
from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.model_selection import train_test_split
import torch
import torch.nn as nn
from torch.utils.data import DataLoader, TensorDataset

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v3_final"

ALGORITHMS = ["huffman", "lzw", "arithmetic", "bwt_mtf", "rle_huffman"]
ALGO_PARAMS = {
    "huffman": {"order": 1}, "lzw": {"max_bits": 14},
    "arithmetic": {"order": 0}, "bwt_mtf": {"secondary": "huffman", "block_size": 0},
    "rle_huffman": {"min_run": 4},
}
_CODECS = {
    "huffman": huffman_codec, "lzw": lzw_codec,
    "arithmetic": arithmetic_codec, "bwt_mtf": bwt_codec, "rle_huffman": rle_codec,
}
HEADER_BITS = math.ceil(math.log2(len(ALGORITHMS)))

FEATURE_NAMES = [
    "n_chars", "n_lines", "n_words", "avg_word_len", "std_word_len",
    "unique_char_ratio", "unique_word_ratio", "digit_ratio", "whitespace_ratio",
    "punctuation_ratio", "uppercase_ratio", "vowel_ratio", "entropy_char",
    "bigram_repetition_ratio", "trigram_repetition_ratio", "longest_repeat_run",
    "newline_density", "mean_line_length", "std_line_length",
    "ascii_ratio", "non_ascii_ratio",
]


def extract_features(text: str) -> dict:
    import re
    from collections import Counter
    if not text:
        return {f: 0.0 for f in FEATURE_NAMES}
    chars = list(text); n = len(chars)
    words = re.findall(r"\b\w+\b", text); n_words = len(words)
    word_lens = [len(w) for w in words] if words else [0]
    avg_wl = np.mean(word_lens); std_wl = np.std(word_lens) if len(word_lens) > 1 else 0.0
    ucr = len(set(chars)) / n
    dr = sum(1 for c in chars if c.isdigit()) / n
    wsr = sum(1 for c in chars if c.isspace()) / n
    import string; punct = set(string.punctuation)
    pr = sum(1 for c in chars if c in punct) / n
    upr = sum(1 for c in chars if c.isupper()) / n
    vowels = set("aeiouAEIOU"); vr = sum(1 for c in chars if c in vowels) / n
    cc = Counter(chars); ent = -sum((c/n)*math.log2(c/n) for c in cc.values())
    bigrams = [text[i:i+2] for i in range(n-1)]
    bg_rep = 1.0 - len(set(bigrams))/len(bigrams) if bigrams else 0.0
    trigrams = [text[i:i+3] for i in range(n-2)]
    tg_rep = 1.0 - len(set(trigrams))/len(trigrams) if trigrams else 0.0
    ac = sum(1 for c in chars if 32 <= ord(c) <= 126 or ord(c) in (9,10,13))
    ar = ac/n; nar = 1.0-ar
    nl = text.count("\n")+1; nd = (nl-1)/n
    lines = text.split("\n"); lls = [len(ln) for ln in lines]
    mll = np.mean(lls) if lls else 0; sll = np.std(lls) if len(lls)>1 else 0
    uwr = len(set(words))/n_words if n_words else 0
    lr = 0
    if n >= 2:
        seen = set()
        for length in range(min(50,n), 1, -1):
            seen.clear(); found=False
            for i in range(n-length+1):
                sub = text[i:i+length]
                if sub in seen: lr=length; found=True; break
                seen.add(sub)
            if found: break
    return {"n_chars":n,"n_lines":nl,"n_words":n_words,"avg_word_len":avg_wl,
            "std_word_len":std_wl,"unique_char_ratio":ucr,"unique_word_ratio":uwr,
            "digit_ratio":dr,"whitespace_ratio":wsr,"punctuation_ratio":pr,
            "uppercase_ratio":upr,"vowel_ratio":vr,"entropy_char":ent,
            "bigram_repetition_ratio":bg_rep,"trigram_repetition_ratio":tg_rep,
            "longest_repeat_run":lr,"newline_density":nd,
            "mean_line_length":mll,"std_line_length":sll,
            "ascii_ratio":ar,"non_ascii_ratio":nar}


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


def run_chunk_sweep(chunk_sizes: list[int], n_chunks: int = 2000):
    print("=" * 70)
    print(f"CHUNK SIZE SWEEP: {chunk_sizes}")
    print("=" * 70)

    # Load corpus texts
    import csv
    texts: list[str] = []
    processed = PROJECT_ROOT / "data" / "processed" / "books"
    if processed.exists():
        for f in sorted(processed.glob("*.txt"))[:300]:
            texts.append(f.read_text(encoding="utf-8", errors="replace")[:50000])
    manifest = PROJECT_ROOT / "data" / "diverse" / "manifest.csv"
    if manifest.exists():
        with open(manifest, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                p = PROJECT_ROOT / row["path"]
                if p.exists():
                    texts.append(p.read_text(encoding="utf-8", errors="replace"))
    print(f"Loaded {len(texts)} texts, {sum(len(t) for t in texts):,} chars")

    results_by_size = {}

    for cs in chunk_sizes:
        print(f"\n{'='*60}")
        print(f"Chunk size: {cs} bytes")
        print(f"{'='*60}")

        # Chunk
        rng = np.random.RandomState(42)
        all_chunks = []
        for text in texts:
            for i in range(0, len(text), cs):
                chunk = text[i:i+cs]
                if len(chunk) >= cs // 4:
                    all_chunks.append(chunk)
        indices = rng.choice(len(all_chunks), min(n_chunks, len(all_chunks)), replace=False)
        chunks = [all_chunks[i] for i in indices]
        print(f"  {len(chunks)} chunks")

        # Grid search
        grid_results = []
        for chunk in chunks:
            data = chunk.encode("utf-8")
            bpbs = {}; times = {}
            for algo in ALGORITHMS:
                params = ALGO_PARAMS[algo]
                codec = _CODECS[algo]
                try:
                    t0 = time.perf_counter()
                    result = codec.compress(data, **{k:v for k,v in params.items() if k!="label"})
                    elapsed = (time.perf_counter() - t0) * 1000
                    bpbs[algo] = result.bpb if result.valid else 999
                    times[algo] = elapsed
                except Exception:
                    bpbs[algo] = 999; times[algo] = 0
            best = min(bpbs, key=bpbs.get)
            feats = extract_features(chunk)
            grid_results.append({"best_algo":best,"best_bpb":bpbs[best],
                                 "all_bpbs":bpbs,"all_times":times,"features":feats})

        # Train/test split
        X = np.array([[r["features"][f] for f in FEATURE_NAMES] for r in grid_results])
        y_str = np.array([r["best_algo"] for r in grid_results])
        le = LabelEncoder(); y = le.fit_transform(y_str)
        scaler = StandardScaler(); X = scaler.fit_transform(X)

        all_idx = np.arange(len(X))
        X_temp, X_test, y_temp, y_test, idx_temp, idx_test = train_test_split(
            X, y, all_idx, test_size=0.2, random_state=42, stratify=y)
        X_train, X_val, y_train, y_val = train_test_split(
            X_temp, y_temp, test_size=0.2, random_state=42, stratify=y_temp)
        test_res = [grid_results[i] for i in idx_test]

        # Train MLP
        mlp = SimpleMLP(21, [128, 64, 32], len(le.classes_))
        opt = torch.optim.AdamW(mlp.parameters(), lr=1e-3, weight_decay=1e-4)
        sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, 50)
        crit = nn.CrossEntropyLoss()
        Xt = torch.tensor(X_train, dtype=torch.float32)
        yt = torch.tensor(y_train, dtype=torch.long)
        Xv = torch.tensor(X_val, dtype=torch.float32)
        yv = torch.tensor(y_val, dtype=torch.long)
        ds = TensorDataset(Xt, yt); dl = DataLoader(ds, batch_size=128, shuffle=True)
        best_loss = float("inf"); best_state = None
        for epoch in range(50):
            mlp.train()
            for bx, by in dl:
                opt.zero_grad(); loss = crit(mlp(bx), by); loss.backward(); opt.step()
            sched.step()
            mlp.eval()
            with torch.no_grad(): vl = crit(mlp(Xv), yv).item()
            if vl < best_loss: best_loss = vl; best_state = {k:v.clone() for k,v in mlp.state_dict().items()}
        mlp.load_state_dict(best_state); mlp.eval()

        # Evaluate
        X_test_t = torch.tensor(X_test, dtype=torch.float32)
        adaptive_bpbs = []; adaptive_times = []; bwt_bpbs = []; bwt_times = []
        mlp_times = []; selected_times = []
        wins = Counter(r["best_algo"] for r in grid_results)
        pred_counts = Counter()

        for i, r in enumerate(test_res):
            t0 = time.perf_counter()
            with torch.no_grad():
                pred = mlp(X_test_t[i:i+1]).argmax(dim=1).item()
            mt = (time.perf_counter() - t0) * 1000
            mlp_times.append(mt)
            sel = le.classes_[pred]
            pred_counts[sel] += 1
            at = r["all_times"][sel]
            selected_times.append(at)
            adaptive_times.append(mt + at)
            bpb = r["all_bpbs"][sel] + HEADER_BITS / cs
            adaptive_bpbs.append(bpb)
            bwt_bpbs.append(r["all_bpbs"]["bwt_mtf"])
            bwt_times.append(r["all_times"]["bwt_mtf"])

        abpb = float(np.mean(adaptive_bpbs))
        bbpb = float(np.mean(bwt_bpbs))
        atime = float(np.mean(adaptive_times))
        btime = float(np.mean(bwt_times))
        imp = (bbpb - abpb) / bbpb * 100

        print(f"  Ground truth wins: {dict(wins.most_common(3))}")
        print(f"  MLP selects:        {dict(pred_counts.most_common())}")
        print(f"  Adaptive BPB:       {abpb:.4f} (with header)")
        print(f"  bwt_mtf BPB:        {bbpb:.4f}")
        print(f"  Improvement:        {imp:+.2f}%")
        print(f"  Adaptive time:      {atime:.3f} ms (MLP: {np.mean(mlp_times):.4f})")
        print(f"  bwt_mtf time:       {btime:.3f} ms")
        print(f"  Time ratio:         {atime/btime:.2f}x")

        results_by_size[cs] = {
            "chunk_size": cs, "n_chunks": len(chunks), "n_test": len(test_res),
            "adaptive_bpb": abpb, "bwt_bpb": bbpb, "improvement_pct": imp,
            "adaptive_time_ms": atime, "bwt_time_ms": btime,
            "time_ratio": float(atime/btime),
            "mlp_time_ms": float(np.mean(mlp_times)),
            "ground_truth": dict(wins.most_common()),
            "mlp_selections": dict(pred_counts.most_common()),
        }

    # Summary
    print(f"\n{'='*70}")
    print("SUMMARY")
    print(f"{'='*70}")
    print(f"{'Size':>6s} | {'Adap BPB':>9s} | {'BWT BPB':>8s} | {'Impr':>6s} | {'Adap ms':>8s} | {'BWT ms':>7s} | {'Ratio':>6s}")
    print("-" * 70)
    for cs in chunk_sizes:
        r = results_by_size[cs]
        print(f"{cs:>6d} | {r['adaptive_bpb']:>9.4f} | {r['bwt_bpb']:>8.4f} | "
              f"{r['improvement_pct']:>+5.1f}% | {r['adaptive_time_ms']:>8.3f} | "
              f"{r['bwt_time_ms']:>7.3f} | {r['time_ratio']:>5.2f}x")

    # Save
    with open(ARTIFACTS_DIR / "chunk_sweep.json", "w") as f:
        import json
        json.dump(results_by_size, f, indent=2, default=str)
    print(f"\nSaved to chunk_sweep.json")


if __name__ == "__main__":
    run_chunk_sweep([1024, 2048, 4096, 8192], n_chunks=2000)
