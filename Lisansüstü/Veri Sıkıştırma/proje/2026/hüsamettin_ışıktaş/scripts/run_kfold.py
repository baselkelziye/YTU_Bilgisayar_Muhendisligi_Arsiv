"""K-Fold Cross-Validation with book-level split + multiple seeds.

Prevents data leakage: all chunks from the same book stay together.
5-fold CV × 3 seeds = 15 evaluations.
Reports mean ± std for BPB, accuracy, F1, and statistical test.
"""

import csv, json, math, pickle, sys, time
from collections import Counter, defaultdict
from pathlib import Path

import numpy as np
from scipy import stats
from sklearn.preprocessing import LabelEncoder, StandardScaler
import torch
import torch.nn as nn
from torch.utils.data import DataLoader, TensorDataset

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from src.codecs import arithmetic_codec, bwt_codec, huffman_codec, lzw_codec, rle_codec

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v4_kfold"
PLOTS_DIR = ARTIFACTS_DIR / "plots"
CHUNK_SIZE = 1024
HEADER_BITS = 3
N_FOLDS = 5
SEEDS = [42, 123, 456]
N_CHUNKS = 8000

ALGORITHMS = ["huffman", "lzw", "arithmetic", "bwt_mtf", "rle_huffman"]
ALGO_PARAMS = {
    "huffman": {"order": 1}, "lzw": {"max_bits": 14},
    "arithmetic": {"order": 0}, "bwt_mtf": {"secondary": "huffman", "block_size": 0},
    "rle_huffman": {"min_run": 4},
}
_CODECS = {"huffman": huffman_codec, "lzw": lzw_codec, "arithmetic": arithmetic_codec,
           "bwt_mtf": bwt_codec, "rle_huffman": rle_codec}

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
    if not text: return {f: 0.0 for f in FEATURE_NAMES}
    chars = list(text); n = len(chars)
    words = re.findall(r"\b\w+\b", text); n_words = len(words)
    wl = [len(w) for w in words] if words else [0]
    ucr = len(set(chars))/n; dr = sum(1 for c in chars if c.isdigit())/n
    wsr = sum(1 for c in chars if c.isspace())/n
    import string; punct = set(string.punctuation)
    pr = sum(1 for c in chars if c in punct)/n
    upr = sum(1 for c in chars if c.isupper())/n
    vowels = set("aeiouAEIOU"); vr = sum(1 for c in chars if c in vowels)/n
    cc = Counter(chars); ent = -sum((c/n)*math.log2(c/n) for c in cc.values())
    bg = [text[i:i+2] for i in range(n-1)]
    bg_rep = 1-len(set(bg))/len(bg) if bg else 0
    tg = [text[i:i+3] for i in range(n-2)]
    tg_rep = 1-len(set(tg))/len(tg) if tg else 0
    ac = sum(1 for c in chars if 32<=ord(c)<=126 or ord(c) in (9,10,13))
    ar = ac/n; nar = 1-ar; nl = text.count("\n")+1; nd = (nl-1)/n
    lines = text.split("\n"); lls = [len(ln) for ln in lines]
    mll = np.mean(lls) if lls else 0; sll = np.std(lls) if len(lls)>1 else 0
    uwr = len(set(words))/n_words if n_words else 0; lr = 0
    if n>=2:
        seen=set()
        for length in range(min(50,n),1,-1):
            seen.clear(); found=False
            for i in range(n-length+1):
                sub=text[i:i+length]
                if sub in seen: lr=length; found=True; break
                seen.add(sub)
            if found: break
    return {"n_chars":n,"n_lines":nl,"n_words":n_words,"avg_word_len":np.mean(wl),
            "std_word_len":np.std(wl) if len(wl)>1 else 0,"unique_char_ratio":ucr,
            "unique_word_ratio":uwr,"digit_ratio":dr,"whitespace_ratio":wsr,
            "punctuation_ratio":pr,"uppercase_ratio":upr,"vowel_ratio":vr,
            "entropy_char":ent,"bigram_repetition_ratio":bg_rep,
            "trigram_repetition_ratio":tg_rep,"longest_repeat_run":lr,
            "newline_density":nd,"mean_line_length":mll,"std_line_length":sll,
            "ascii_ratio":ar,"non_ascii_ratio":nar}


class MLP(nn.Module):
    def __init__(self, in_dim, hidden, n_classes):
        super().__init__()
        layers = []; prev = in_dim
        for h in hidden:
            layers.extend([nn.Linear(prev,h), nn.ReLU(), nn.BatchNorm1d(h), nn.Dropout(0.2)])
            prev = h
        layers.append(nn.Linear(prev, n_classes))
        self.net = nn.Sequential(*layers)
    def forward(self, x): return self.net(x)


def load_corpus_with_book_ids(max_chunks=N_CHUNKS):
    """Load corpus, track which book each chunk belongs to."""
    rng = np.random.RandomState(42)
    book_chunks = defaultdict(list)  # book_id -> [(chunk_text, domain)]
    book_id = 0

    # Gutenberg
    processed = PROJECT_ROOT / "data" / "processed" / "books"
    if processed.exists():
        for f in sorted(processed.glob("*.txt")):
            text = f.read_text(encoding="utf-8", errors="replace")[:30000]
            chunks = [text[i:i+CHUNK_SIZE] for i in range(0, len(text), CHUNK_SIZE)]
            chunks = [c for c in chunks if len(c) >= 100]
            if chunks:
                book_chunks[f"gutenberg_{book_id}"] = [("gutenberg", c) for c in chunks]
                book_id += 1

    # Diverse
    manifest = PROJECT_ROOT / "data" / "diverse" / "manifest.csv"
    if manifest.exists():
        with open(manifest, encoding="utf-8") as f:
            for row in csv.DictReader(f):
                p = PROJECT_ROOT / row["path"]
                if p.exists():
                    text = p.read_text(encoding="utf-8", errors="replace")
                    chunks = [text[i:i+CHUNK_SIZE] for i in range(0, len(text), CHUNK_SIZE)]
                    chunks = [c for c in chunks if len(c) >= 100]
                    if chunks:
                        domain = row.get("domain", "diverse")
                        book_chunks[f"diverse_{book_id}"] = [(domain, c) for c in chunks]
                        book_id += 1

    # Flatten: list of (book_id, domain, chunk)
    all_items = []
    for bid, chunks in book_chunks.items():
        for domain, chunk in chunks:
            all_items.append((bid, domain, chunk))

    # Cap
    if len(all_items) > max_chunks:
        indices = rng.choice(len(all_items), max_chunks, replace=False)
        all_items = [all_items[i] for i in indices]

    return all_items


def run_grid_search(items):
    """Run all algorithms on all chunks."""
    results = []
    for book_id, domain, chunk in items:
        data = chunk.encode("utf-8")
        bpbs = {}; times = {}
        for algo in ALGORITHMS:
            params = ALGO_PARAMS[algo]; codec = _CODECS[algo]
            try:
                t0 = time.perf_counter()
                r = codec.compress(data, **{k:v for k,v in params.items() if k!="label"})
                elapsed = (time.perf_counter()-t0)*1000
                bpbs[algo] = r.bpb if r.valid else 999; times[algo] = elapsed
            except Exception:
                bpbs[algo] = 999; times[algo] = 0
        best = min(bpbs, key=bpbs.get)
        results.append({"book_id": book_id, "domain": domain, "best_algo": best,
                        "best_bpb": bpbs[best], "all_bpbs": bpbs, "all_times": times,
                        "features": extract_features(chunk), "chunk": chunk})
    return results


def book_level_kfold(book_ids, n_folds=N_FOLDS, seed=42):
    """Split book IDs into n_folds, return train/test book ID sets for each fold."""
    unique_books = list(set(book_ids))
    rng = np.random.RandomState(seed)
    rng.shuffle(unique_books)
    fold_size = len(unique_books) // n_folds
    folds = []
    for i in range(n_folds):
        start = i * fold_size
        end = start + fold_size if i < n_folds - 1 else len(unique_books)
        test_books = set(unique_books[start:end])
        train_books = set(unique_books) - test_books
        folds.append((train_books, test_books))
    return folds


def train_and_evaluate(train_results, test_results, seed):
    """Train MLP on train set, evaluate on test set. Returns metrics dict."""
    X_train = np.array([[r["features"][f] for f in FEATURE_NAMES] for r in train_results])
    y_train_str = np.array([r["best_algo"] for r in train_results])
    X_test = np.array([[r["features"][f] for f in FEATURE_NAMES] for r in test_results])
    y_test_str = np.array([r["best_algo"] for r in test_results])

    le = LabelEncoder()
    y_train = le.fit_transform(y_train_str)
    y_test = le.transform(y_test_str)

    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    # Validation split from train
    n_val = int(len(X_train) * 0.15)
    idx = np.random.RandomState(seed).permutation(len(X_train))
    X_val, y_val = X_train[idx[:n_val]], y_train[idx[:n_val]]
    X_tr, y_tr = X_train[idx[n_val:]], y_train[idx[n_val:]]

    # Train MLP
    mlp = MLP(21, [128, 64, 32], len(le.classes_))
    opt = torch.optim.AdamW(mlp.parameters(), lr=1e-3, weight_decay=1e-4)
    sched = torch.optim.lr_scheduler.CosineAnnealingLR(opt, 60)
    crit = nn.CrossEntropyLoss()
    Xt = torch.tensor(X_tr, dtype=torch.float32); yt = torch.tensor(y_tr, dtype=torch.long)
    Xv = torch.tensor(X_val, dtype=torch.float32); yv = torch.tensor(y_val, dtype=torch.long)
    ds = TensorDataset(Xt, yt); dl = DataLoader(ds, batch_size=128, shuffle=True)
    best_loss = float("inf"); best_state = None
    for _ in range(60):
        mlp.train()
        for bx, by in dl: opt.zero_grad(); loss = crit(mlp(bx), by); loss.backward(); opt.step()
        sched.step()
        mlp.eval()
        with torch.no_grad(): vl = crit(mlp(Xv), yv).item()
        if vl < best_loss: best_loss = vl; best_state = {k:v.clone() for k,v in mlp.state_dict().items()}
    mlp.load_state_dict(best_state); mlp.eval()

    # Evaluate
    X_test_t = torch.tensor(X_test, dtype=torch.float32)
    with torch.no_grad():
        logits = mlp(X_test_t)
        preds = logits.argmax(dim=1).numpy()

    acc = float((preds == y_test).mean())
    from sklearn.metrics import f1_score
    f1 = float(f1_score(y_test, preds, average="macro"))

    # BPB + timing
    adaptive_bpbs = []; adaptive_times = []; bwt_bpbs = []; bwt_times = []
    mlp_times = []; algo_times = []
    for i, r in enumerate(test_results):
        t0 = time.perf_counter()
        with torch.no_grad(): _ = mlp(X_test_t[i:i+1])
        mt = (time.perf_counter()-t0)*1000
        mlp_times.append(mt)
        sel = le.classes_[preds[i]]
        at = r["all_times"][sel]
        algo_times.append(at); adaptive_times.append(mt+at)
        bpb = r["all_bpbs"][sel] + HEADER_BITS/CHUNK_SIZE
        adaptive_bpbs.append(bpb)
        bwt_bpbs.append(r["all_bpbs"]["bwt_mtf"])
        bwt_times.append(r["all_times"]["bwt_mtf"])

    return {
        "accuracy": acc, "macro_f1": f1,
        "adaptive_bpb": float(np.mean(adaptive_bpbs)),
        "bwt_bpb": float(np.mean(bwt_bpbs)),
        "adaptive_time_ms": float(np.mean(adaptive_times)),
        "bwt_time_ms": float(np.mean(bwt_times)),
        "mlp_time_ms": float(np.mean(mlp_times)),
        "n_train": len(train_results), "n_test": len(test_results),
    }


def main():
    print("=" * 70)
    print(f"K-FOLD CV: {N_FOLDS} folds × {len(SEEDS)} seeds = {N_FOLDS*len(SEEDS)} runs")
    print("=" * 70)

    ARTIFACTS_DIR.mkdir(parents=True, exist_ok=True)
    PLOTS_DIR.mkdir(parents=True, exist_ok=True)

    # Load corpus with book tracking
    print("\n[1/3] Loading corpus...")
    items = load_corpus_with_book_ids(N_CHUNKS)
    book_ids = [bid for bid, _, _ in items]
    unique_books = len(set(book_ids))
    print(f"  {len(items)} chunks from {unique_books} books")

    # Grid search (expensive — do once)
    print(f"\n[2/3] Grid search ({len(ALGORITHMS)} algorithms × {len(items)} chunks)...")
    results = run_grid_search(items)
    
    wins = Counter(r["best_algo"] for r in results)
    print("  Algorithm wins:")
    for a, c in wins.most_common():
        print(f"    {a}: {c} ({c/len(results)*100:.1f}%)")

    # Save grid results
    with open(ARTIFACTS_DIR / "grid_results.pkl", "wb") as f:
        pickle.dump(results, f)

    # K-Fold CV with multiple seeds
    print(f"\n[3/3] {N_FOLDS}-fold CV × {len(SEEDS)} seeds...")
    all_metrics = []

    for seed in SEEDS:
        print(f"\n  Seed {seed}:")
        folds = book_level_kfold(book_ids, N_FOLDS, seed)
        for fold_i, (train_books, test_books) in enumerate(folds):
            train_res = [r for r in results if r["book_id"] in train_books]
            test_res = [r for r in results if r["book_id"] in test_books]
            m = train_and_evaluate(train_res, test_res, seed * 100 + fold_i)
            m["seed"] = seed; m["fold"] = fold_i
            all_metrics.append(m)
            imp = (m["bwt_bpb"] - m["adaptive_bpb"]) / m["bwt_bpb"] * 100
            print(f"    Fold {fold_i+1}: acc={m['accuracy']:.2%} f1={m['macro_f1']:.2%} "
                  f"adap={m['adaptive_bpb']:.4f} bwt={m['bwt_bpb']:.4f} "
                  f"Δ={imp:+.2f}% time={m['adaptive_time_ms']/m['bwt_time_ms']:.2f}x")

    # Aggregate
    adap_bpbs = [m["adaptive_bpb"] for m in all_metrics]
    bwt_bpbs = [m["bwt_bpb"] for m in all_metrics]
    adap_times = [m["adaptive_time_ms"] for m in all_metrics]
    bwt_times = [m["bwt_time_ms"] for m in all_metrics]
    accs = [m["accuracy"] for m in all_metrics]
    f1s = [m["macro_f1"] for m in all_metrics]

    improvements = [(b-a)/b*100 for a, b in zip(adap_bpbs, bwt_bpbs)]

    # T-test: paired, one-sided (adaptive < bwt)
    t_stat, p_value = stats.ttest_rel(bwt_bpbs, adap_bpbs, alternative="greater")

    print(f"\n{'='*70}")
    print(f"FINAL RESULTS ({len(all_metrics)} runs)")
    print(f"{'='*70}")
    print(f"\n  BPB:")
    print(f"    Adaptive:  {np.mean(adap_bpbs):.4f} ± {np.std(adap_bpbs):.4f}")
    print(f"    bwt_mtf:   {np.mean(bwt_bpbs):.4f} ± {np.std(bwt_bpbs):.4f}")
    print(f"    Improvement: {np.mean(improvements):.2f}% ± {np.std(improvements):.2f}%")
    print(f"\n  Statistical test (paired t-test, one-sided):")
    print(f"    t = {t_stat:.4f}, p = {p_value:.6f}")
    if p_value < 0.05:
        print(f"    ✅ Statistically significant (p < 0.05)")
    elif p_value < 0.01:
        print(f"    ✅✅ Highly significant (p < 0.01)")
    else:
        print(f"    ⚠️ Not significant (p = {p_value:.4f})")

    print(f"\n  Accuracy:  {np.mean(accs):.2%} ± {np.std(accs):.2%}")
    print(f"  Macro F1:  {np.mean(f1s):.2%} ± {np.std(f1s):.2%}")
    print(f"\n  Time:")
    print(f"    Adaptive:  {np.mean(adap_times):.4f} ± {np.std(adap_times):.4f} ms")
    print(f"    bwt_mtf:   {np.mean(bwt_times):.4f} ± {np.std(bwt_times):.4f} ms")
    ratios = [a/b for a, b in zip(adap_times, bwt_times)]
    print(f"    Ratio:     {np.mean(ratios):.2f}x ± {np.std(ratios):.2f}")

    # Per-fold summary
    print(f"\n  Per-fold breakdown:")
    for m in all_metrics:
        imp = (m["bwt_bpb"]-m["adaptive_bpb"])/m["bwt_bpb"]*100
        print(f"    s{m['seed']}f{m['fold']+1}: BPB adap={m['adaptive_bpb']:.4f} "
              f"bwt={m['bwt_bpb']:.4f} Δ={imp:+.2f}% acc={m['accuracy']:.2%}")

    # Save
    output = {
        "config": {"n_folds": N_FOLDS, "n_seeds": len(SEEDS), "n_chunks": len(items),
                   "n_books": unique_books, "chunk_size": CHUNK_SIZE},
        "aggregate": {
            "adaptive_bpb_mean": float(np.mean(adap_bpbs)),
            "adaptive_bpb_std": float(np.std(adap_bpbs)),
            "bwt_bpb_mean": float(np.mean(bwt_bpbs)),
            "bwt_bpb_std": float(np.std(bwt_bpbs)),
            "improvement_pct_mean": float(np.mean(improvements)),
            "improvement_pct_std": float(np.std(improvements)),
            "accuracy_mean": float(np.mean(accs)), "accuracy_std": float(np.std(accs)),
            "f1_mean": float(np.mean(f1s)), "f1_std": float(np.std(f1s)),
            "time_ratio_mean": float(np.mean(ratios)), "time_ratio_std": float(np.std(ratios)),
            "t_statistic": float(t_stat), "p_value": float(p_value),
            "significant": bool(p_value < 0.05),
        },
        "per_fold": all_metrics,
    }
    with open(ARTIFACTS_DIR / "kfold_results.json", "w") as f:
        json.dump(output, f, indent=2, default=str)
    print(f"\n✅ Saved to kfold_results.json")


if __name__ == "__main__":
    main()
