"""Recovery: compute BPB from saved grid results and trained models.
Loads results from v3_final/ grid search pickle, retrains models, computes BPB."""

import pickle, json, sys, time
from pathlib import Path
import numpy as np
from collections import defaultdict

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from scripts.run_final_experiment import (
    extract_features, FEATURE_NAMES, ALGORITHMS, ALGO_PARAMS, _CODECS,
    ALGO_COLORS, CHUNK_SIZE, RANDOM_SEED,
    train_mlp, evaluate_model, MLPClassifier,
)
from sklearn.preprocessing import LabelEncoder, StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, f1_score, classification_report
import torch
import torch.nn.functional as F

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v3_final"

def main():
    # Load grid search results
    with open(ARTIFACTS_DIR / "grid_results.pkl", "rb") as f:
        results = pickle.load(f)
    print(f"Loaded {len(results)} grid results")

    # Features + labels
    X = np.array([[r["features"][f] for f in FEATURE_NAMES] for r in results])
    y_str = np.array([r["best_algo"] for r in results])
    le = LabelEncoder()
    y = le.fit_transform(y_str)
    
    scaler = StandardScaler()
    X = scaler.fit_transform(X)

    # Split with indices
    all_idx = np.arange(len(X))
    X_temp, X_test, y_temp, y_test, idx_temp, idx_test = train_test_split(
        X, y, all_idx, test_size=0.15, random_state=RANDOM_SEED, stratify=y)
    X_train, X_val, y_train, y_val, idx_train, idx_val = train_test_split(
        X_temp, y_temp, idx_temp, test_size=0.1765, random_state=RANDOM_SEED, stratify=y_temp)
    print(f"Train: {len(X_train)}, Val: {len(X_val)}, Test: {len(X_test)}")

    device = torch.device("cpu")
    
    print("\nTraining models...")
    
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
    print(f"XGBoost: acc={xgb_eval['accuracy']:.2%}, f1={xgb_eval['macro_f1']:.2%}")

    # MLP variants
    mlp_configs = {
        "MLP-Small": [32, 16],
        "MLP-Medium": [64, 32, 16],
        "MLP-Large": [128, 64, 32],
    }
    mlp_models = {}
    mlp_evals = {}
    
    for name, hidden in mlp_configs.items():
        print(f"Training {name}...")
        model, hist = train_mlp(X_train, y_train, X_val, y_val, hidden, len(le.classes_), name=name)
        ev = evaluate_model(model, X_test, y_test, le)
        mlp_models[name] = model
        mlp_evals[name] = ev
        print(f"  {name}: acc={ev['accuracy']:.2%}, f1={ev['macro_f1']:.2%}")

    # MLP Ensemble
    print("MLP Ensemble...")
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
    print(f"MLP-Ensemble: acc={ensemble_acc:.2%}, f1={ensemble_f1:.2%}")

    # ---------- BPB computation ----------
    print("\nComputing adaptive BPB...")
    test_results = [results[i] for i in idx_test]

    raw_bpbs = {}
    for algo in ALGORITHMS:
        bpbs = [r["all_bpbs"][algo] for r in test_results]
        raw_bpbs[algo] = float(np.mean([b for b in bpbs if b < 100]))

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

    # Ensemble
    ens_bpb = np.mean([test_results[i]["all_bpbs"].get(le.classes_[p], 999)
                       for i, p in enumerate(ensemble_preds)])
    model_bpbs["MLP-Ensemble"] = float(ens_bpb)

    # Timing
    timing_results = {}
    t0 = time.perf_counter()
    for _ in range(100): xgb_model.predict(X_test[:10])
    timing_results["XGBoost"] = float((time.perf_counter() - t0) / 1000 * 1000)
    for name, model in mlp_models.items():
        model.eval()
        with torch.no_grad():
            t0 = time.perf_counter()
            for _ in range(100): model(torch.tensor(X_test[:10], dtype=torch.float32))
            timing_results[name] = float((time.perf_counter() - t0) / 1000 * 1000)
    for algo in ALGORITHMS:
        timing_results[algo] = float(np.median([r["all_times"][algo] for r in results]))

    # Print
    best_raw = min(raw_bpbs, key=raw_bpbs.get)
    all_bpbs = {**raw_bpbs, **model_bpbs}
    print("\nFinal BPB comparison:")
    for name in sorted(all_bpbs, key=all_bpbs.get):
        marker = " ★ RAW" if name == best_raw else ""
        ours = "★ " if name in model_bpbs else "  "
        print(f"  {ours}{name:20s}: {all_bpbs[name]:.4f} BPB{marker}")

    improvement = (all_bpbs[best_raw] - min(model_bpbs.values())) / all_bpbs[best_raw] * 100
    best_model = min(model_bpbs, key=model_bpbs.get)
    print(f"\nBest model: {best_model} ({model_bpbs[best_model]:.4f} BPB)")
    print(f"Improvement over best raw: {improvement:+.2f}%")

    # Save
    output = {"raw_bpbs": raw_bpbs, "model_bpbs": model_bpbs, "timing": timing_results,
              "best_model": best_model, "improvement": improvement}
    with open(ARTIFACTS_DIR / "bpb_results.json", "w") as f:
        json.dump(output, f, indent=2)
    print(f"\nSaved to {ARTIFACTS_DIR}/bpb_results.json")

if __name__ == "__main__":
    main()
