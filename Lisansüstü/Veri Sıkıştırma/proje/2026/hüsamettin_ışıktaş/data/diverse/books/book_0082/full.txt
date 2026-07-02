"""Phase 3 — lightweight MLP profile classifier training.

Usage:
    python scripts/run_phase3.py [--project-root PATH]

Output: artifacts/phase3/{model.pt, scaler.pkl, label_map.json, ...}
"""

from __future__ import annotations

import json
import logging
import sys
from pathlib import Path

import pandas as pd

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
logger = logging.getLogger("run_phase3")


def main() -> int:
    project_root = Path(__file__).resolve().parents[1]
    if str(project_root) not in sys.path:
        sys.path.insert(0, str(project_root))

    artifacts_dir = project_root / "artifacts" / "phase3"
    artifacts_dir.mkdir(parents=True, exist_ok=True)

    filtered_dataset_path = project_root / "artifacts" / "phase1" / "filtered_dataset.parquet"
    if not filtered_dataset_path.exists():
        logger.error("Phase 1 data not found at %s", filtered_dataset_path)
        return 1

    # ------------------------------------------------------------------
    # 1. Build dataset
    # ------------------------------------------------------------------
    from src.features.fast_feature_dataset import build_profile_dataset

    logger.info("Building profile dataset...")
    ds = build_profile_dataset(filtered_dataset_path=filtered_dataset_path, random_state=42)
    logger.info("Dataset: input_dim=%d num_classes=%d", ds.input_dim, ds.num_classes)

    # ------------------------------------------------------------------
    # 2. Train
    # ------------------------------------------------------------------
    from src.models.train_profile_mlp import train_profile_mlp

    logger.info("Training ProfileMLP...")
    model, history = train_profile_mlp(
        X_train=ds.X_train,
        y_train=ds.y_train,
        X_val=ds.X_val,
        y_val=ds.y_val,
        num_classes=ds.num_classes,
        batch_size=256,
        lr=1e-3,
        weight_decay=1e-4,
        max_epochs=100,
        patience=7,
        device="cpu",
        seed=42,
    )

    history.to_csv(artifacts_dir / "train_history.csv", index=False)
    logger.info("Training history saved to train_history.csv")

    # ------------------------------------------------------------------
    # 3. Evaluate
    # ------------------------------------------------------------------
    from src.models.evaluate_profile_mlp import evaluate_model, save_metrics_json

    logger.info("Evaluating on test set...")
    metrics = evaluate_model(
        model=model,
        X=ds.X_test,
        y=ds.y_test,
        label_map=ds.label_map,
        device="cpu",
    )
    save_metrics_json(metrics, str(artifacts_dir / "metrics.json"))

    logger.info("Validation metrics: accuracy=%.4f macro_f1=%.4f top3=%.4f",
                 metrics["accuracy"], metrics["macro_f1"], metrics["top3_accuracy"])

    # Write confusion matrix CSV
    cm_df = pd.DataFrame.from_dict(metrics["confusion_matrix"])
    cm_df.to_csv(artifacts_dir / "confusion_matrix.csv", index=True)
    logger.info("Confusion matrix saved to confusion_matrix.csv")

    # ------------------------------------------------------------------
    # 4. Save artifacts
    # ------------------------------------------------------------------
    from src.models.model_io import save_model_artifacts

    save_model_artifacts(
        model=model,
        scaler=ds.scaler,
        label_map={i: ds.profile_order[i] for i in range(len(ds.profile_order))},
        output_dir=artifacts_dir,
    )

    # ------------------------------------------------------------------
    # 5. Summary
    # ------------------------------------------------------------------
    summary = {
        "status": "ok",
        "input_dim": ds.input_dim,
        "num_classes": ds.num_classes,
        "train_samples": int(len(ds.X_train)),
        "val_samples": int(len(ds.X_val)),
        "test_samples": int(len(ds.X_test)),
        "accuracy": metrics["accuracy"],
        "macro_f1": metrics["macro_f1"],
        "top3_accuracy": metrics["top3_accuracy"],
        "inference_mean_ms": metrics["inference_mean_ms"],
        "artifacts": {
            "model": str(artifacts_dir / "model.pt"),
            "scaler": str(artifacts_dir / "scaler.pkl"),
            "label_map": str(artifacts_dir / "label_map.json"),
            "train_history": str(artifacts_dir / "train_history.csv"),
            "metrics": str(artifacts_dir / "metrics.json"),
        },
    }
    (artifacts_dir / "phase3_summary.json").write_text(
        json.dumps(summary, indent=2, ensure_ascii=False), encoding="utf-8"
    )

    logger.info("=" * 60)
    logger.info("Phase 3 complete!")
    logger.info("  Accuracy:    %.4f", metrics["accuracy"])
    logger.info("  Macro F1:    %.4f", metrics["macro_f1"])
    logger.info("  Top-3 Acc:   %.4f", metrics["top3_accuracy"])
    logger.info("  Inference:   %.3f ms", metrics["inference_mean_ms"])
    logger.info("  Artifacts:   %s", artifacts_dir)
    logger.info("=" * 60)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
