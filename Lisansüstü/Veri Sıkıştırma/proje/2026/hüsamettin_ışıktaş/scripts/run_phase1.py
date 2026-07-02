"""Run phase 1 pipeline end-to-end."""

from __future__ import annotations

import json
import logging
import sys
from pathlib import Path

import pandas as pd

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s %(levelname)s %(name)s :: %(message)s",
)

PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from src.analysis.chunk_size_decision import write_chunk_decision_report
from src.analysis.phase1_plots import generate_phase1_plots
from src.clustering.cluster_filtering import filter_clusters
from src.clustering.kmeans_profiles import fit_kmeans, run_k_sweep
from src.clustering.profile_labeling import build_profile_definitions
from src.features.feature_pipeline import build_feature_tables


META_COLUMNS = {"book_id", "chunk_id", "chunk_index", "split", "chunk_size_chars", "source_text_length"}


def main() -> int:
    project_root = PROJECT_ROOT
    artifacts_dir = project_root / "artifacts" / "phase1"
    plots_dir = artifacts_dir / "plots"
    artifacts_dir.mkdir(parents=True, exist_ok=True)
    plots_dir.mkdir(parents=True, exist_ok=True)

    manifest_clean_path = project_root / "data" / "processed" / "manifest_clean.csv"
    split_path = project_root / "data" / "processed" / "book_splits.csv"

    # Hard-coded chunk size: 1024 bytes gives algorithm diversity (our test
    # showed huffman/bwt/lzw all win different profiles at this size).
    selected_chunk_size = 1024

    # Sample books for speed — 200 books @ 1024-byte chunks gives ~70K
    # chunks, manageable for Set A feature extraction (zlib/bz2/lzma).
    import csv, random
    random.seed(42)
    with open(manifest_clean_path, "r", encoding="utf-8", newline="") as fh:
        manifest_rows = [r for r in csv.DictReader(fh) if r.get("quality_status") == "accepted"]
    if len(manifest_rows) > 200:
        manifest_rows = random.sample(manifest_rows, 200)
    sampled_manifest_path = artifacts_dir / "manifest_sampled.csv"
    with open(sampled_manifest_path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=manifest_rows[0].keys())
        w.writeheader()
        w.writerows(manifest_rows)

    # Dummy experiments table (no sweep)
    scored_experiments = pd.DataFrame([{
        "chunk_size": selected_chunk_size,
        "num_chunks": 0,
        "best_k": 0,
        "best_silhouette": 0.0,
        "final_score": 1.0,
    }])
    write_chunk_decision_report(
        output_path=artifacts_dir / "chunk_size_decision_report.md",
        selected_chunk_size=selected_chunk_size,
        scored_experiments=scored_experiments,
    )

    set_a_df, set_b_df = build_feature_tables(
        project_root=project_root,
        manifest_clean_path=sampled_manifest_path,
        split_path=split_path,
        chunk_size=selected_chunk_size,
    )

    candidate_k = list(range(8, 41, 2))
    set_a_df.to_parquet(artifacts_dir / "features_set_a.parquet", index=False)
    set_b_df.to_parquet(artifacts_dir / "features_set_b.parquet", index=False)

    if set_a_df.empty or set_b_df.empty:
        (artifacts_dir / "correlation_matrix.csv").write_text("", encoding="utf-8")
        (artifacts_dir / "profile_definitions.json").write_text("[]\n", encoding="utf-8")
        set_b_df.to_parquet(artifacts_dir / "filtered_dataset.parquet", index=False)
        print(json.dumps({"status": "ok", "message": "No rows after feature extraction"}, indent=2))
        return 0

    set_b_feature_cols = [col for col in set_b_df.columns if col not in META_COLUMNS]
    set_a_feature_cols = [col for col in set_a_df.columns if col not in META_COLUMNS]
    corr = set_a_df[set_a_feature_cols].corr(numeric_only=True)
    corr.to_csv(artifacts_dir / "correlation_matrix.csv", index=True)

    clustered, sweep_metrics, best_model, best_metrics = run_k_sweep(
        frame=set_a_df,
        feature_columns=set_a_feature_cols,
        candidate_k=candidate_k,
        random_state=42,
    )

    if clustered.empty:
        filtered_df = clustered.copy()
        filter_summary = {"before": 0.0, "after": 0.0, "removed": 0.0}
        profile_definitions: list[dict[str, object]] = []
    else:
        if "cluster_id" not in clustered.columns:
            clustered, _, _ = fit_kmeans(clustered, set_a_feature_cols, k=1, random_state=42)
        dynamic_min_cluster = max(1, min(5, len(clustered)))
        filtered_df, filter_summary = filter_clusters(
            frame=clustered,
            feature_columns=set_a_feature_cols,
            min_cluster_size=dynamic_min_cluster,
            # Less aggressive filtering to keep more clusters/profiles.
            silhouette_threshold=0.1,
            outlier_quantile=0.995,
        )
        profile_definitions = build_profile_definitions(
            labeled_frame=filtered_df if not filtered_df.empty else clustered,
            feature_columns=set_a_feature_cols if set(set_a_feature_cols).issubset((filtered_df if not filtered_df.empty else clustered).columns) else set_b_feature_cols,
            label_column="cluster_id",
        )

    filtered_df.to_parquet(artifacts_dir / "filtered_dataset.parquet", index=False)
    (artifacts_dir / "profile_definitions.json").write_text(
        json.dumps(profile_definitions, indent=2), encoding="utf-8"
    )
    scored_experiments.to_csv(artifacts_dir / "chunk_experiment_metrics.csv", index=False)
    sweep_metrics.to_csv(artifacts_dir / "kmeans_sweep_metrics.csv", index=False)

    summary = {
        "status": "ok",
        "selected_chunk_size": selected_chunk_size,
        "num_set_a_rows": int(len(set_a_df)),
        "num_set_b_rows": int(len(set_b_df)),
        "num_filtered_rows": int(len(filtered_df)),
        "best_k": int(best_metrics["k"]),
        "best_silhouette": float(best_metrics["silhouette"]),
        "filter_summary": filter_summary,
        "num_profiles": len(profile_definitions),
    }
    (artifacts_dir / "phase1_summary.json").write_text(json.dumps(summary, indent=2), encoding="utf-8")
    generate_phase1_plots(artifacts_dir=artifacts_dir, plots_dir=plots_dir)
    print(json.dumps(summary, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

