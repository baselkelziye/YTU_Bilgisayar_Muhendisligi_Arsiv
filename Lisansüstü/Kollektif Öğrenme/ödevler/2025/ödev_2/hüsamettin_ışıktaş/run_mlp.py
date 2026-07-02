"""
PyTorch tabanlı MLP Model Eğitim ve Değerlendirme Scripti

Bu script:
1. 3 farklı embedding verisetini yükler (başlık, özet, birleştirilmiş)
2. Verileri normalize eder ve PyTorch DataLoader'larına dönüştürür
3. GPU destekli MLP modeli ile eğitim yapar (varsa GPU)
4. Test setinde performansı değerlendirir ve sonuçları/grafikleri artifacts/ dizinine kaydeder
"""

import argparse
import os
import json
from dataclasses import dataclass
from datetime import datetime
from typing import Optional, Sequence, Tuple

import joblib
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import torch
from torch.nn.utils import clip_grad_norm_
from sklearn.metrics import (
    accuracy_score,
    classification_report,
    confusion_matrix,
    f1_score,
    precision_score,
    recall_score,
)
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder, StandardScaler
from torch import nn
from torch.utils.data import DataLoader, TensorDataset

# Türkçe karakter desteği için
plt.rcParams["font.family"] = "DejaVu Sans"

# Sabit parametreler
RANDOM_SEED = 42
MODEL_NAME = "PyTorch MLP"
DATASET_DIR = "dataset"
ARTIFACTS_DIR = "artifacts"
VAL_SPLIT = 0.1

# PyTorch MLP hiperparametreleri
HIDDEN_LAYERS = (768, 384, 192)
DROPOUT = 0.35
EPOCHS = 120
BATCH_SIZE = 128
LEARNING_RATE = 7e-4
WEIGHT_DECAY = 1e-4
PATIENCE = 15

DEVICE = torch.device("cuda" if torch.cuda.is_available() else "cpu")

DATASET_PALETTE = {"title": "#2e8b57", "abstract": "#1f77b4", "concat": "#8e44ad"}


def infer_embed_size_from_path(dataset_dir: str) -> Optional[int]:
    """dataset/128 gibi yollardan embed boyutunu çıkarır."""
    base = os.path.basename(os.path.normpath(dataset_dir))
    digits = "".join(ch for ch in base if ch.isdigit())
    return int(digits) if digits else None


@dataclass
class TrainingConfig:
    """Komut satırından okunacak eğitim ayarları."""

    dataset_dir: str
    embed_size: Optional[int]
    hidden_layers: Tuple[int, ...]
    dropout: float
    epochs: int
    batch_size: int
    learning_rate: float
    weight_decay: float
    patience: int
    val_split: float
    label_smoothing: float
    grad_clip_norm: Optional[float]
    scheduler: str
    plateau_factor: float
    plateau_patience: int
    min_lr: float


def parse_args() -> TrainingConfig:
    """Komut satırı argümanlarını okuyup TrainingConfig döndürür."""
    parser = argparse.ArgumentParser(
        description="PyTorch MLP ile tez yılı tahmini - eğitim scripti"
    )
    parser.add_argument(
        "--hidden-dims",
        nargs="+",
        type=int,
        default=list(HIDDEN_LAYERS),
        help="MLP gizli katman boyutları (varsayılan: %(default)s)",
    )
    parser.add_argument(
        "--dropout", type=float, default=DROPOUT, help="Dropout oranı (varsayılan: %(default)s)"
    )
    parser.add_argument(
        "--epochs", type=int, default=EPOCHS, help="Epoch sayısı (varsayılan: %(default)s)"
    )
    parser.add_argument(
        "--batch-size", type=int, default=BATCH_SIZE, help="Batch size (varsayılan: %(default)s)"
    )
    parser.add_argument(
        "--learning-rate",
        type=float,
        default=LEARNING_RATE,
        help="Öğrenme oranı (varsayılan: %(default)s)",
    )
    parser.add_argument(
        "--weight-decay",
        type=float,
        default=WEIGHT_DECAY,
        help="Weight decay katsayısı (varsayılan: %(default)s)",
    )
    parser.add_argument(
        "--patience", type=int, default=PATIENCE, help="Erken durdurma sabrı (varsayılan: %(default)s)"
    )
    parser.add_argument(
        "--val-split",
        type=float,
        default=VAL_SPLIT,
        help="Validation oranı (varsayılan: %(default)s)",
    )
    parser.add_argument(
        "--label-smoothing",
        type=float,
        default=0.03,
        help="CrossEntropy için label smoothing değeri (0 devre dışı)",
    )
    parser.add_argument(
        "--grad-clip-norm",
        type=float,
        default=1.0,
        help="Gradient clipping (<=0 ise devre dışı)",
    )
    parser.add_argument(
        "--scheduler",
        choices=["none", "plateau"],
        default="plateau",
        help="Öğrenme oranı planlayıcısı",
    )
    parser.add_argument(
        "--plateau-factor",
        type=float,
        default=0.5,
        help="ReduceLROnPlateau faktörü",
    )
    parser.add_argument(
        "--plateau-patience",
        type=int,
        default=2,
        help="ReduceLROnPlateau sabrı",
    )
    parser.add_argument(
        "--min-lr",
        type=float,
        default=1e-5,
        help="Scheduler için minimum öğrenme oranı",
    )
    parser.add_argument(
        "--embed-size",
        type=int,
        default=None,
        help="Kullanılan embed boyutu (dataset yolundan türetilecekse boş bırakılabilir).",
    )
    parser.add_argument(
        "--dataset",
        default=DATASET_DIR,
        help="`train_*.npz` ve `test_*.npz` dosyalarının bulunduğu dizin (varsayılan: dataset).",
    )

    args = parser.parse_args()
    grad_clip = None if args.grad_clip_norm <= 0 else args.grad_clip_norm
    inferred_embed = args.embed_size
    if inferred_embed is None:
        inferred_embed = infer_embed_size_from_path(args.dataset)

    return TrainingConfig(
        dataset_dir=args.dataset,
        embed_size=inferred_embed,
        hidden_layers=tuple(args.hidden_dims),
        dropout=args.dropout,
        epochs=args.epochs,
        batch_size=args.batch_size,
        learning_rate=args.learning_rate,
        weight_decay=args.weight_decay,
        patience=args.patience,
        val_split=args.val_split,
        label_smoothing=max(args.label_smoothing, 0.0),
        grad_clip_norm=grad_clip,
        scheduler=args.scheduler,
        plateau_factor=args.plateau_factor,
        plateau_patience=args.plateau_patience,
        min_lr=args.min_lr,
    )


def seed_everything(seed: int = RANDOM_SEED):
    """Tüm rastgelelik kaynaklarını sabitler."""
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False


class ThesisMLP(nn.Module):
    """Basit çok katmanlı MLP sınıflandırıcı."""

    def __init__(self, input_dim: int, num_classes: int, hidden_layers: Sequence[int], dropout: float):
        super().__init__()
        layers = []
        prev_dim = input_dim
        for hidden_dim in hidden_layers:
            layers.extend(
                [
                    nn.Linear(prev_dim, hidden_dim),
                    nn.BatchNorm1d(hidden_dim),
                    nn.ReLU(),
                    nn.Dropout(dropout),
                ]
            )
            prev_dim = hidden_dim
        layers.append(nn.Linear(prev_dim, num_classes))
        self.network = nn.Sequential(*layers)

    def forward(self, x):
        return self.network(x)


def load_embedding_data(embed_type, dataset_dir):
    """Embedding verisetini yükler."""
    train_file = os.path.join(dataset_dir, f"train_{embed_type}_embeddings.npz")
    test_file = os.path.join(dataset_dir, f"test_{embed_type}_embeddings.npz")

    train_data = np.load(train_file)
    test_data = np.load(test_file)

    return (
        train_data["embeddings"],
        train_data["years"],
        test_data["embeddings"],
        test_data["years"],
    )


def prepare_dataloaders(
    X_train,
    y_train,
    X_test,
    y_test,
    batch_size: int,
    val_split: float,
):
    """Verileri ölçeklendirip PyTorch DataLoader'larına dönüştürür."""
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)

    X_tr, X_val, y_tr, y_val = train_test_split(
        X_train_scaled,
        y_train,
        test_size=val_split,
        stratify=y_train,
        random_state=RANDOM_SEED,
    )

    X_tr_tensor = torch.from_numpy(X_tr).float()
    y_tr_tensor = torch.from_numpy(y_tr).long()
    X_val_tensor = torch.from_numpy(X_val).float()
    y_val_tensor = torch.from_numpy(y_val).long()
    X_test_tensor = torch.from_numpy(X_test_scaled).float()
    y_test_tensor = torch.from_numpy(y_test).long()

    train_loader = DataLoader(
        TensorDataset(X_tr_tensor, y_tr_tensor),
        batch_size=batch_size,
        shuffle=True,
        drop_last=False,
    )
    val_loader = DataLoader(
        TensorDataset(X_val_tensor, y_val_tensor),
        batch_size=batch_size,
        shuffle=False,
    )
    test_loader = DataLoader(
        TensorDataset(X_test_tensor, y_test_tensor),
        batch_size=batch_size,
        shuffle=False,
    )

    return train_loader, val_loader, test_loader, scaler


def encode_labels(y_train, y_test):
    """Yıl etiketlerini 0-index sınıf id'lerine dönüştürür."""
    encoder = LabelEncoder()
    encoder.fit(np.concatenate([y_train, y_test]))
    return encoder.transform(y_train), encoder.transform(y_test), encoder


def train_model(train_loader, val_loader, input_dim, num_classes, config: TrainingConfig):
    """PyTorch MLP eğitim döngüsü."""
    model = ThesisMLP(input_dim, num_classes, config.hidden_layers, config.dropout).to(DEVICE)
    criterion = nn.CrossEntropyLoss(label_smoothing=config.label_smoothing)
    optimizer = torch.optim.AdamW(
        model.parameters(), lr=config.learning_rate, weight_decay=config.weight_decay
    )
    scheduler = None
    if config.scheduler == "plateau":
        scheduler = torch.optim.lr_scheduler.ReduceLROnPlateau(
            optimizer,
            mode="min",
            factor=config.plateau_factor,
            patience=config.plateau_patience,
            min_lr=config.min_lr,
        )
    best_state = None
    best_val_loss = float("inf")
    patience_counter = 0

    for epoch in range(config.epochs):
        model.train()
        train_loss = 0.0
        for xb, yb in train_loader:
            xb = xb.to(DEVICE)
            yb = yb.to(DEVICE)

            optimizer.zero_grad()
            logits = model(xb)
            loss = criterion(logits, yb)
            loss.backward()
            if config.grad_clip_norm is not None:
                clip_grad_norm_(model.parameters(), config.grad_clip_norm)
            optimizer.step()

            train_loss += loss.item() * xb.size(0)

        train_loss /= len(train_loader.dataset)

        model.eval()
        val_loss = 0.0
        with torch.no_grad():
            for xb, yb in val_loader:
                xb = xb.to(DEVICE)
                yb = yb.to(DEVICE)
                logits = model(xb)
                loss = criterion(logits, yb)
                val_loss += loss.item() * xb.size(0)
        val_loss /= len(val_loader.dataset)

        current_lr = optimizer.param_groups[0]["lr"]
        print(
            f"   Epoch {epoch+1:02d}/{config.epochs} - "
            f"Train Loss: {train_loss:.4f} | Val Loss: {val_loss:.4f} | LR: {current_lr:.2e}"
        )

        if scheduler is not None:
            scheduler.step(val_loss)

        if val_loss < best_val_loss - 1e-4:
            best_val_loss = val_loss
            best_state = model.state_dict()
            patience_counter = 0
        else:
            patience_counter += 1
            if patience_counter >= config.patience:
                print("   Erken durdurma tetiklendi.")
                break

    if best_state is not None:
        model.load_state_dict(best_state)

    return model


def get_predictions(model, data_loader):
    """Modelden tahminleri döndürür."""
    model.eval()
    preds = []
    trues = []

    with torch.no_grad():
        for xb, yb in data_loader:
            xb = xb.to(DEVICE)
            logits = model(xb)
            pred = torch.argmax(logits, dim=1).cpu().numpy()
            preds.append(pred)
            trues.append(yb.numpy())

    return np.concatenate(trues), np.concatenate(preds)


def evaluate_model(model, test_loader, label_encoder):
    """Model performansını değerlendirir."""
    y_true_idx, y_pred_idx = get_predictions(model, test_loader)
    y_true = label_encoder.inverse_transform(y_true_idx)
    y_pred = label_encoder.inverse_transform(y_pred_idx)
    errors = y_pred - y_true
    abs_errors = np.abs(errors)

    metrics = {
        "accuracy": accuracy_score(y_true, y_pred),
        "f1_macro": f1_score(y_true, y_pred, average="macro"),
        "f1_weighted": f1_score(y_true, y_pred, average="weighted"),
        "precision_macro": precision_score(y_true, y_pred, average="macro"),
        "recall_macro": recall_score(y_true, y_pred, average="macro"),
        "mae": float(np.mean(abs_errors)),
        "rmse": float(np.sqrt(np.mean(errors**2))),
        "classification_report": classification_report(y_true, y_pred),
        "confusion_matrix": confusion_matrix(y_true, y_pred),
        "y_true": y_true,
        "y_pred": y_pred,
        "errors": errors,
        "abs_errors": abs_errors,
    }

    return metrics


def plot_confusion_matrix(metrics, title, output_path):
    """Confusion matrix grafiği oluşturur."""
    cm = metrics["confusion_matrix"]
    labels = sorted(list(set(metrics["y_true"])))

    plt.figure(figsize=(16, 14))
    cm_normalized = cm.astype("float") / cm.sum(axis=1)[:, np.newaxis]

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


def plot_year_accuracy(metrics, title, output_path):
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


def plot_prediction_distribution(metrics, title, output_path):
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
    axes[1].plot(
        [y_true.min(), y_true.max()],
        [y_true.min(), y_true.max()],
        "r--",
        linewidth=2,
        label="İdeal",
    )
    axes[1].set_title("Gerçek vs Tahmin", fontsize=12)
    axes[1].set_xlabel("Gerçek Yıl", fontsize=10)
    axes[1].set_ylabel("Tahmin Edilen Yıl", fontsize=10)
    axes[1].legend()
    axes[1].grid(alpha=0.3)

    plt.suptitle(title, fontsize=14, y=1.02)
    plt.tight_layout()

    plt.savefig(output_path, dpi=150, bbox_inches="tight")
    plt.close()


def get_top_confusions(metrics, top_n=8):
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


def plot_error_summary(metrics, title, output_path, color):
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
    top_confusions = get_top_confusions(metrics, top_n=6)

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


def plot_dataset_error_overview(all_results, output_dir, embed_names):
    """Veri setleri arasında hata dağılımını karşılaştırır."""
    datasets = list(all_results.keys())
    mae_values = [all_results[ds]["metrics"]["mae"] for ds in datasets]
    abs_error_lists = [all_results[ds]["metrics"]["abs_errors"] for ds in datasets]

    fig, axes = plt.subplots(1, 2, figsize=(14, 6))
    colors = [DATASET_PALETTE[ds] for ds in datasets]

    axes[0].bar(
        [embed_names[ds] for ds in datasets],
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
    axes[1].set_xticklabels([embed_names[ds] for ds in datasets])
    axes[1].set_title("Mutlak Hata Dağılımı (Violin)")
    axes[1].set_ylabel("|Tahmin - Gerçek|")
    axes[1].grid(axis="y", alpha=0.3)

    plt.suptitle("Verisetleri Hata Özeti", fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "dataset_error_overview.png"), dpi=150, bbox_inches="tight")
    plt.close()


def save_results(all_results, output_dir, config: TrainingConfig, dataset_dir: str, embed_size: Optional[int], timestamp: str):
    """Tüm sonuçları kaydeder."""
    resolved_dataset_dir = os.path.abspath(dataset_dir)
    summary = {
        "_meta": {
            "model": MODEL_NAME,
            "embed_size": embed_size,
            "dataset_dir": resolved_dataset_dir,
            "output_dir": os.path.abspath(output_dir),
            "timestamp": timestamp,
        }
    }
    for embed_type, results in all_results.items():
        summary[embed_type] = {
            "accuracy": results["metrics"]["accuracy"],
            "f1_macro": results["metrics"]["f1_macro"],
            "f1_weighted": results["metrics"]["f1_weighted"],
            "precision_macro": results["metrics"]["precision_macro"],
            "recall_macro": results["metrics"]["recall_macro"],
            "mae": results["metrics"]["mae"],
            "rmse": results["metrics"]["rmse"],
        }

    with open(os.path.join(output_dir, "metrics_summary.json"), "w") as f:
        json.dump(summary, f, indent=2)

    embed_size_text = embed_size if embed_size is not None else "unknown"
    comparison_text = """# PyTorch MLP Sonuçları

## Deney Bilgileri

| Bilgi | Değer |
|-------|-------|
| dataset_dir | {} |
| embed_size | {} |
| output_dir | {} |
| timestamp | {} |

## Model Parametreleri

| Parametre | Değer |
|-----------|-------|
| hidden_layers | {} |
| dropout | {} |
| epochs | {} |
| batch_size | {} |
| learning_rate | {} |
| weight_decay | {} |
| patience | {} |
| device | {} |
| random_state | {} |

## Performans Karşılaştırması

| Veriseti | Accuracy | F1 (Macro) | F1 (Weighted) | Precision | Recall | MAE | RMSE |
|----------|----------|------------|---------------|-----------|--------|-----|------|
""".format(
        resolved_dataset_dir,
        embed_size_text,
        os.path.abspath(output_dir),
        timestamp,
        config.hidden_layers,
        config.dropout,
        config.epochs,
        config.batch_size,
        config.learning_rate,
        config.weight_decay,
        config.patience,
        DEVICE,
        RANDOM_SEED,
    )

    for embed_type in all_results.keys():
        metrics = summary[embed_type]
        comparison_text += "| {} | {:.4f} | {:.4f} | {:.4f} | {:.4f} | {:.4f} | {:.2f} | {:.2f} |\n".format(
            embed_type,
            metrics["accuracy"],
            metrics["f1_macro"],
            metrics["f1_weighted"],
            metrics["precision_macro"],
            metrics["recall_macro"],
            metrics["mae"],
            metrics["rmse"],
        )

    for embed_type, results in all_results.items():
        comparison_text += f"\n## {embed_type.capitalize()} Veriseti Detaylı Rapor\n\n```\n"
        comparison_text += results["metrics"]["classification_report"]
        comparison_text += "\n```\n"

    with open(os.path.join(output_dir, "results_report.md"), "w", encoding="utf-8") as f:
        f.write(comparison_text)


def plot_comparison(all_results, output_dir):
    """Tüm modellerin karşılaştırma grafiğini oluşturur."""
    embed_types = list(all_results.keys())
    metrics_names = ["accuracy", "f1_macro", "f1_weighted", "precision_macro", "recall_macro"]
    metrics_labels = ["Accuracy", "F1 (Macro)", "F1 (Weighted)", "Precision", "Recall"]

    x = np.arange(len(embed_types))
    width = 0.15

    fig, ax = plt.subplots(figsize=(12, 6))
    colors = ["#2ecc71", "#3498db", "#9b59b6", "#e74c3c", "#f39c12"]

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
    ax.set_title("MLP - Veriseti Karşılaştırması", fontsize=14)
    ax.set_xticks(x + width * 2)
    ax.set_xticklabels(["Başlık", "Özet", "Birleştirilmiş"])
    ax.legend(loc="upper left", bbox_to_anchor=(1, 1))
    ax.set_ylim(0, 1.15)
    ax.grid(axis="y", alpha=0.3)

    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "comparison.png"), dpi=150, bbox_inches="tight")
    plt.close()


def main():
    """Ana fonksiyon - MLP deney sürecini yönetir."""
    config = parse_args()
    seed_everything()
    print("=" * 60)
    print("PyTorch MLP MODEL EĞİTİMİ VE DEĞERLENDİRMESİ")
    print("=" * 60)
    print(f"Kullanılan cihaz: {DEVICE}")
    print(
        f"\nEğitim ayarları -> epochs: {config.epochs}, batch_size: {config.batch_size}, "
        f"lr: {config.learning_rate}, hidden_layers: {config.hidden_layers}"
    )

    dataset_dir = config.dataset_dir
    resolved_dataset_dir = os.path.abspath(dataset_dir)
    embed_size = config.embed_size
    print(f"Kullanılan veri dizini: {resolved_dataset_dir}")
    print(f"Embed boyutu: {embed_size if embed_size is not None else 'unknown'}")

    timestamp = datetime.now().strftime("%Y-%m-%d_%H%M%S")
    output_dir = os.path.join(ARTIFACTS_DIR, f"{timestamp}_mlp")
    os.makedirs(output_dir, exist_ok=True)
    print(f"\nÇıktı dizini: {output_dir}")

    embed_types = ["title", "abstract", "concat"]
    embed_names = {"title": "Başlık", "abstract": "Özet", "concat": "Birleştirilmiş"}

    all_results = {}

    for embed_type in embed_types:
        print(f"\n{'='*60}")
        print(f"{embed_names[embed_type].upper()} VERİSETİ")
        print(f"{'='*60}")

        print("\n1. Veri yükleniyor...")
        X_train, y_train, X_test, y_test = load_embedding_data(embed_type, dataset_dir)
        print(f"   Train: {X_train.shape}, Test: {X_test.shape}")

        y_train_enc, y_test_enc, label_encoder = encode_labels(y_train, y_test)

        print("\n2. DataLoader hazırlanıyor...")
        train_loader, val_loader, test_loader, scaler = prepare_dataloaders(
            X_train,
            y_train_enc,
            X_test,
            y_test_enc,
            batch_size=config.batch_size,
            val_split=config.val_split,
        )
        input_dim = X_train.shape[1]
        num_classes = len(label_encoder.classes_)

        print("\n3. Model eğitiliyor...")
        model = train_model(train_loader, val_loader, input_dim, num_classes, config)

        print("\n4. Model değerlendiriliyor...")
        metrics = evaluate_model(model, test_loader, label_encoder)
        print(f"   Accuracy: {metrics['accuracy']:.4f}")
        print(f"   F1 (Macro): {metrics['f1_macro']:.4f}")
        print(f"   MAE: {metrics['mae']:.2f}")

        print("\n5. Grafikler oluşturuluyor...")
        plot_confusion_matrix(
            metrics,
            f"MLP - {embed_names[embed_type]}",
            os.path.join(output_dir, f"{embed_type}_confusion_matrix.png"),
        )
        plot_year_accuracy(
            metrics,
            f"MLP - {embed_names[embed_type]}",
            os.path.join(output_dir, f"{embed_type}_year_accuracy.png"),
        )
        plot_prediction_distribution(
            metrics,
            f"MLP - {embed_names[embed_type]}",
            os.path.join(output_dir, f"{embed_type}_prediction_dist.png"),
        )
        plot_error_summary(
            metrics,
            f"MLP - {embed_names[embed_type]} Detaylı Hata Profili",
            os.path.join(output_dir, f"{embed_type}_error_summary.png"),
            DATASET_PALETTE[embed_type],
        )

        model_path = os.path.join(output_dir, f"{embed_type}_model.pt")
        torch.save(
            {
                "state_dict": model.state_dict(),
                "input_dim": input_dim,
                "num_classes": num_classes,
                "hidden_layers": HIDDEN_LAYERS,
                "dropout": DROPOUT,
            },
            model_path,
        )

        scaler_path = os.path.join(output_dir, f"{embed_type}_scaler.joblib")
        joblib.dump(scaler, scaler_path)
        label_encoder_path = os.path.join(output_dir, f"{embed_type}_label_encoder.joblib")
        joblib.dump(label_encoder, label_encoder_path)
        print(f"   Model kaydedildi: {model_path}")
        print(f"   Ölçekleyici kaydedildi: {scaler_path}")
        print(f"   Label encoder kaydedildi: {label_encoder_path}")

        all_results[embed_type] = {
            "metrics": metrics,
            "model_path": model_path,
            "scaler_path": scaler_path,
            "label_encoder_path": label_encoder_path,
        }

    print(f"\n{'='*60}")
    print("SONUÇLAR KAYDEDİLİYOR")
    print(f"{'='*60}")

    save_results(all_results, output_dir, config, resolved_dataset_dir, embed_size, timestamp)
    plot_comparison(all_results, output_dir)
    plot_dataset_error_overview(all_results, output_dir, embed_names)

    print(f"\n✓ Tüm sonuçlar kaydedildi: {output_dir}/")

    print("\n" + "=" * 60)
    print("ÖZET")
    print("=" * 60)
    print("\n{:<15} {:>10} {:>10} {:>10} {:>8}".format("Veriseti", "Accuracy", "F1-Macro", "F1-Weight", "MAE"))
    print("-" * 60)
    for embed_type in embed_types:
        m = all_results[embed_type]["metrics"]
        print(
            "{:<15} {:>10.4f} {:>10.4f} {:>10.4f} {:>8.2f}".format(
                embed_names[embed_type],
                m["accuracy"],
                m["f1_macro"],
                m["f1_weighted"],
                m["mae"],
            )
        )


if __name__ == "__main__":
    main()


