"""Plot generation helpers for phase 1 artifacts."""

from __future__ import annotations

import json
from pathlib import Path

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns


def _finish_figure(output_path: Path) -> Path:
    output_path.parent.mkdir(parents=True, exist_ok=True)
    plt.tight_layout()
    plt.savefig(output_path, dpi=160, bbox_inches="tight")
    plt.close()
    return output_path


def _chunk_labels(frame: pd.DataFrame) -> list[str]:
    return [str(value) for value in frame["chunk_size"].tolist()]


def _plot_chunk_scores(frame: pd.DataFrame, plots_dir: Path) -> Path:
    labels = _chunk_labels(frame)
    x_positions = range(len(labels))

    plt.figure(figsize=(10, 5))
    plt.bar(x_positions, frame["final_score"], label="final_score", alpha=0.75)
    plt.plot(x_positions, frame["best_silhouette"], marker="o", color="tab:orange", label="best_silhouette")
    plt.xticks(list(x_positions), labels, rotation=35, ha="right")
    plt.xlabel("chunk_size")
    plt.ylabel("score")
    plt.title("Chunk Size Score Comparison")
    plt.legend()
    return _finish_figure(plots_dir / "chunk_size_scores.png")


def _plot_chunk_counts(frame: pd.DataFrame, plots_dir: Path) -> Path:
    labels = _chunk_labels(frame)

    plt.figure(figsize=(10, 5))
    sns.barplot(x=labels, y=frame["num_chunks"].astype(float), color="tab:blue")
    plt.xticks(rotation=35, ha="right")
    plt.xlabel("chunk_size")
    plt.ylabel("num_chunks")
    plt.title("Chunk Count by Candidate Size")
    return _finish_figure(plots_dir / "chunk_counts.png")


def _plot_entropy(frame: pd.DataFrame, plots_dir: Path) -> Path:
    labels = _chunk_labels(frame)

    plt.figure(figsize=(10, 5))
    sns.lineplot(x=labels, y=frame["mean_entropy"].astype(float), marker="o")
    plt.xticks(rotation=35, ha="right")
    plt.xlabel("chunk_size")
    plt.ylabel("mean_entropy")
    plt.title("Mean Character Entropy by Chunk Size")
    return _finish_figure(plots_dir / "chunk_entropy.png")


def _plot_zlib_if_available(frame: pd.DataFrame, plots_dir: Path) -> Path | None:
    if "mean_zlib_ratio" not in frame.columns:
        return None

    zlib_values = pd.to_numeric(frame["mean_zlib_ratio"], errors="coerce")
    if zlib_values.dropna().empty or (zlib_values.fillna(0.0) == 0.0).all():
        return None

    labels = _chunk_labels(frame)
    plt.figure(figsize=(10, 5))
    sns.lineplot(x=labels, y=zlib_values, marker="o")
    plt.xticks(rotation=35, ha="right")
    plt.xlabel("chunk_size")
    plt.ylabel("mean_zlib_ratio")
    plt.title("Mean Zlib Compression Ratio by Chunk Size")
    return _finish_figure(plots_dir / "chunk_zlib_ratio.png")


def _plot_kmeans_sweep(frame: pd.DataFrame, plots_dir: Path) -> Path:
    work = frame.sort_values("k")

    fig, ax1 = plt.subplots(figsize=(9, 5))
    ax1.plot(work["k"], work["silhouette"], marker="o", color="tab:blue", label="silhouette")
    ax1.set_xlabel("k")
    ax1.set_ylabel("silhouette", color="tab:blue")
    ax1.tick_params(axis="y", labelcolor="tab:blue")

    ax2 = ax1.twinx()
    ax2.plot(work["k"], work["inertia"], marker="s", color="tab:orange", label="inertia")
    ax2.set_ylabel("inertia", color="tab:orange")
    ax2.tick_params(axis="y", labelcolor="tab:orange")

    plt.title("K-Means Sweep Metrics")
    return _finish_figure(plots_dir / "kmeans_sweep.png")


def _plot_correlation_matrix(frame: pd.DataFrame, plots_dir: Path) -> Path:
    plt.figure(figsize=(max(8, len(frame.columns) * 0.45), max(6, len(frame.index) * 0.45)))
    sns.heatmap(frame, cmap="coolwarm", center=0.0, square=True, linewidths=0.2)
    plt.title("Set A Feature Correlation Matrix")
    return _finish_figure(plots_dir / "correlation_heatmap.png")


def _plot_profile_sizes(profile_definitions: list[dict[str, object]], plots_dir: Path) -> Path | None:
    rows = [
        {"profile_id": str(profile["profile_id"]), "size": float(profile["size"])}
        for profile in profile_definitions
        if "profile_id" in profile and "size" in profile
    ]
    if not rows:
        return None

    frame = pd.DataFrame(rows).sort_values("size", ascending=False)
    plt.figure(figsize=(9, 5))
    sns.barplot(data=frame, x="profile_id", y="size", color="tab:green")
    plt.xticks(rotation=25, ha="right")
    plt.xlabel("profile_id")
    plt.ylabel("filtered rows")
    plt.title("High-Confidence Profile Sizes")
    return _finish_figure(plots_dir / "profile_sizes.png")


def generate_phase1_plots(artifacts_dir: Path, plots_dir: Path | None = None) -> list[Path]:
    """Generate phase 1 diagnostic plots from existing artifact tables."""
    plots_dir = plots_dir or artifacts_dir / "plots"
    plots_dir.mkdir(parents=True, exist_ok=True)
    created: list[Path] = []

    chunk_metrics_path = artifacts_dir / "chunk_experiment_metrics.csv"
    if chunk_metrics_path.exists():
        chunk_metrics = pd.read_csv(chunk_metrics_path)
        if not chunk_metrics.empty:
            if {"chunk_size", "final_score", "best_silhouette"}.issubset(chunk_metrics.columns):
                created.append(_plot_chunk_scores(chunk_metrics, plots_dir))
            if {"chunk_size", "num_chunks"}.issubset(chunk_metrics.columns):
                created.append(_plot_chunk_counts(chunk_metrics, plots_dir))
            if {"chunk_size", "mean_entropy"}.issubset(chunk_metrics.columns):
                created.append(_plot_entropy(chunk_metrics, plots_dir))
            zlib_plot = _plot_zlib_if_available(chunk_metrics, plots_dir)
            if zlib_plot is not None:
                created.append(zlib_plot)

    sweep_metrics_path = artifacts_dir / "kmeans_sweep_metrics.csv"
    if sweep_metrics_path.exists():
        sweep_metrics = pd.read_csv(sweep_metrics_path)
        if not sweep_metrics.empty and {"k", "silhouette", "inertia"}.issubset(sweep_metrics.columns):
            created.append(_plot_kmeans_sweep(sweep_metrics, plots_dir))

    correlation_path = artifacts_dir / "correlation_matrix.csv"
    if correlation_path.exists() and correlation_path.stat().st_size > 0:
        correlation = pd.read_csv(correlation_path, index_col=0)
        if not correlation.empty:
            created.append(_plot_correlation_matrix(correlation, plots_dir))

    profile_path = artifacts_dir / "profile_definitions.json"
    if profile_path.exists():
        profile_definitions = json.loads(profile_path.read_text(encoding="utf-8"))
        if isinstance(profile_definitions, list):
            profile_plot = _plot_profile_sizes(profile_definitions, plots_dir)
            if profile_plot is not None:
                created.append(profile_plot)

    return created
