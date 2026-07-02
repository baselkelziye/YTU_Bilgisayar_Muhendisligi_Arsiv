import os
from typing import Dict, List, Optional

import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn.metrics import accuracy_score

# Ortak görselleştirme ayarları
plt.rcParams["font.family"] = "DejaVu Sans"


def plot_confusion_matrix(metrics: Dict, title: str, output_path: str) -> None:
    """Confusion matrix grafiği oluşturur."""
    cm = metrics["confusion_matrix"]
    labels = sorted(list(set(metrics["y_true"])))

    plt.figure(figsize=(16, 14))
    cm_normalized = cm.astype(float) / cm.sum(axis=1)[:, np.newaxis]

    sns.heatmap(
        cm_normalized,
        annot=False,
        fmt=".2f",
        cmap="Blues",
        xticklabels=labels,
        yticklabels=labels,
    )

    plt.title(f"{title}\nNormalize Edilmiş Confusion Matrix", fontsize=14)
    plt.xlabel("Tahmin Edilen Yıl", fontsize=12)
    plt.ylabel("Gerçek Yıl", fontsize=12)
    plt.xticks(rotation=45, ha="right")
    plt.yticks(rotation=0)
    plt.tight_layout()

    plt.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close()


def plot_year_accuracy(metrics: Dict, title: str, output_path: str) -> None:
    """Yıllara göre doğruluk grafiği oluşturur."""
    y_true = metrics["y_true"]
    y_pred = metrics["y_pred"]

    years = sorted(list(set(y_true)))
    accuracies = []

    for year in years:
        mask = y_true == year
        accuracies.append(accuracy_score(y_true[mask], y_pred[mask]) if mask.sum() else 0)

    plt.figure(figsize=(14, 6))
    plt.bar(years, accuracies, color="forestgreen", edgecolor="darkgreen")

    avg_acc = np.mean(accuracies)
    plt.axhline(y=avg_acc, color="red", linestyle="--", label=f"Ortalama: {avg_acc:.3f}")

    plt.title(f"{title}\nYıllara Göre Doğruluk", fontsize=14)
    plt.xlabel("Yıl", fontsize=12)
    plt.ylabel("Doğruluk", fontsize=12)
    plt.xticks(years, rotation=45, ha="right")
    plt.ylim(0, 1)
    plt.legend()
    plt.grid(axis="y", alpha=0.3)
    plt.tight_layout()

    plt.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close()


def plot_prediction_distribution(metrics: Dict, title: str, output_path: str) -> None:
    """Tahmin dağılımı grafiği oluşturur."""
    y_true = metrics["y_true"]
    y_pred = metrics["y_pred"]
    errors = y_pred - y_true

    fig, axes = plt.subplots(1, 2, figsize=(14, 5))

    axes[0].hist(errors, bins=50, color="forestgreen", edgecolor="darkgreen", alpha=0.7)
    axes[0].axvline(x=0, color="red", linestyle="--", linewidth=2)
    axes[0].set_title("Tahmin Hatası Dağılımı", fontsize=12)
    axes[0].set_xlabel("Hata (Tahmin - Gerçek)", fontsize=10)
    axes[0].set_ylabel("Frekans", fontsize=10)
    axes[0].grid(axis="y", alpha=0.3)

    mae = np.mean(np.abs(errors))
    rmse = np.sqrt(np.mean(errors**2))
    axes[0].text(
        0.95,
        0.95,
        f"MAE: {mae:.2f}\nRMSE: {rmse:.2f}",
        transform=axes[0].transAxes,
        fontsize=10,
        verticalalignment="top",
        horizontalalignment="right",
        bbox=dict(boxstyle="round", facecolor="wheat", alpha=0.5),
    )

    axes[1].scatter(y_true, y_pred, alpha=0.3, s=10, c="forestgreen")
    min_val, max_val = y_true.min(), y_true.max()
    axes[1].plot([min_val, max_val], [min_val, max_val], "r--", linewidth=2, label="İdeal")
    axes[1].set_title("Gerçek vs Tahmin", fontsize=12)
    axes[1].set_xlabel("Gerçek Yıl", fontsize=10)
    axes[1].set_ylabel("Tahmin Edilen Yıl", fontsize=10)
    axes[1].legend()
    axes[1].grid(alpha=0.3)

    plt.suptitle(title, fontsize=14, y=1.02)
    plt.tight_layout()

    plt.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close()


def _get_top_confusions(metrics: Dict, top_n: int = 8) -> List[Dict]:
    """En sık karıştırılan yıl çiftlerini döndürür."""
    cm = metrics["confusion_matrix"].astype(float)
    labels = sorted(list(set(metrics["y_true"])))
    mis_cm = cm.copy()
    np.fill_diagonal(mis_cm, 0)

    flat_indices = np.argsort(mis_cm, axis=None)[::-1]
    top_pairs = []

    for idx in flat_indices:
        if len(top_pairs) >= top_n:
            break
        i, j = divmod(idx, mis_cm.shape[1])
        count = mis_cm[i, j]
        if count <= 0:
            break
        top_pairs.append({"actual": labels[i], "predicted": labels[j], "count": int(cm[i, j])})
    return top_pairs


def plot_error_summary(metrics: Dict, title: str, output_path: str, color: str) -> None:
    """Her veri seti için hata dağılımı ve karışıklıkları gösterir."""
    y_true = metrics["y_true"]
    errors = metrics["errors"]
    abs_errors = metrics["abs_errors"]
    years = sorted(list(set(y_true)))

    year_mae = []
    for year in years:
        mask = y_true == year
        year_mae.append(np.mean(np.abs(errors[mask])) if mask.sum() else 0)

    sorted_abs = np.sort(abs_errors)
    cum_ratio = np.linspace(0, 1, len(sorted_abs))
    top_confusions = _get_top_confusions(metrics, top_n=6)

    fig, axes = plt.subplots(2, 2, figsize=(15, 10))

    axes[0, 0].plot(years, year_mae, color=color, marker="o")
    axes[0, 0].fill_between(years, year_mae, color=color, alpha=0.15)
    axes[0, 0].set_title("Yıllara Göre Ortalama Mutlak Hata (MAE)")
    axes[0, 0].set_xlabel("Yıl")
    axes[0, 0].set_ylabel("MAE")
    axes[0, 0].set_xticks(years[::2])
    axes[0, 0].grid(alpha=0.3)

    bins = np.arange(0, max(10, int(abs_errors.max()) + 2))
    axes[0, 1].hist(abs_errors, bins=bins, color=color, edgecolor="black", alpha=0.75)
    axes[0, 1].set_title("Mutlak Hata Dağılımı")
    axes[0, 1].set_xlabel("|Tahmin - Gerçek|")
    axes[0, 1].set_ylabel("Frekans")
    axes[0, 1].grid(axis="y", alpha=0.3)

    axes[1, 0].plot(sorted_abs, cum_ratio, color=color, linewidth=2)
    axes[1, 0].set_title("Kümülatif Mutlak Hata Eğrisi")
    axes[1, 0].set_xlabel("|Hata|")
    axes[1, 0].set_ylabel("Kümülatif Oran")
    axes[1, 0].grid(alpha=0.3)

    if top_confusions:
        pairs = [f"{item['actual']} → {item['predicted']}" for item in top_confusions]
        counts = [item["count"] for item in top_confusions]
        axes[1, 1].barh(pairs[::-1], counts[::-1], color=color, alpha=0.85)
        axes[1, 1].set_title("En Çok Karıştırılan Yıl Çiftleri")
        axes[1, 1].set_xlabel("Adet")
        axes[1, 1].grid(axis="x", alpha=0.2)
    else:
        axes[1, 1].text(0.5, 0.5, "Önemli karışıklık yok", ha="center", va="center")
        axes[1, 1].set_axis_off()

    plt.suptitle(title, fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close()


def plot_dataset_error_overview(
    all_results: Dict,
    output_dir: str,
    embed_names: Dict[str, str],
    dataset_palette: Dict[str, str],
) -> None:
    """Veri setleri arasında hata dağılımını karşılaştırır."""
    datasets = list(all_results.keys())
    mae_values = [all_results[ds]["metrics"]["mae"] for ds in datasets]
    abs_error_lists = [all_results[ds]["metrics"]["abs_errors"] for ds in datasets]

    fig, axes = plt.subplots(1, 2, figsize=(14, 6))
    colors = [dataset_palette.get(ds, "#34495e") for ds in datasets]

    axes[0].bar(
        [embed_names.get(ds, ds.title()) for ds in datasets],
        mae_values,
        color=colors,
        edgecolor="black",
        alpha=0.85,
    )
    axes[0].set_title("Verisetlerine Göre MAE")
    axes[0].set_ylabel("MAE")
    axes[0].grid(axis="y", alpha=0.3)

    parts = axes[1].violinplot(abs_error_lists, showmeans=True, showmedians=True)
    for idx, body in enumerate(parts["bodies"]):
        body.set_facecolor(colors[idx])
        body.set_edgecolor("black")
        body.set_alpha(0.6)
    axes[1].set_xticks(np.arange(1, len(datasets) + 1))
    axes[1].set_xticklabels([embed_names.get(ds, ds.title()) for ds in datasets])
    axes[1].set_title("Mutlak Hata Dağılımı (Violin)")
    axes[1].set_ylabel("|Tahmin - Gerçek|")
    axes[1].grid(axis="y", alpha=0.3)

    plt.suptitle("Verisetleri Hata Özeti", fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "dataset_error_overview.png"), dpi=150, bbox_inches="tight")
    plt.close()


def plot_comparison(
    all_results: Dict,
    output_dir: str,
    embed_names: Dict[str, str],
    model_label: str,
    metric_colors: Optional[List[str]] = None,
) -> None:
    """Tüm modellerin karşılaştırma grafiğini oluşturur."""
    embed_types = list(all_results.keys())
    metrics_names = ["accuracy", "f1_macro", "f1_weighted", "precision_macro", "recall_macro"]
    metrics_labels = ["Accuracy", "F1 (Macro)", "F1 (Weighted)", "Precision", "Recall"]

    x = np.arange(len(embed_types))
    width = 0.15
    fig, ax = plt.subplots(figsize=(12, 6))

    colors = metric_colors or ["#2ecc71", "#3498db", "#9b59b6", "#e74c3c", "#f39c12"]

    for i, (metric_name, metric_label, color) in enumerate(zip(metrics_names, metrics_labels, colors)):
        values = [all_results[et]["metrics"][metric_name] for et in embed_types]
        bars = ax.bar(x + i * width, values, width, label=metric_label, color=color)

        for bar, val in zip(bars, values):
            ax.text(
                bar.get_x() + bar.get_width() / 2,
                bar.get_height() + 0.01,
                f"{val:.3f}",
                ha="center",
                va="bottom",
                fontsize=8,
                rotation=90,
            )

    ax.set_xlabel("Veriseti", fontsize=12)
    ax.set_ylabel("Skor", fontsize=12)
    ax.set_title(f"{model_label} - Veriseti Karşılaştırması", fontsize=14)
    ax.set_xticks(x + width * 2)
    ax.set_xticklabels([embed_names.get(et, et.title()) for et in embed_types])
    ax.legend(loc="upper left", bbox_to_anchor=(1, 1))
    ax.set_ylim(0, 1.15)
    ax.grid(axis="y", alpha=0.3)

    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "comparison.png"), dpi=150, bbox_inches="tight")
    plt.close()


