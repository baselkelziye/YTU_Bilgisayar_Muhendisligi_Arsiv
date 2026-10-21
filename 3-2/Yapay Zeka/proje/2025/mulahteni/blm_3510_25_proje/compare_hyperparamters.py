import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path
import re
import shutil

# === CSV klasörü ===
csv_dir = Path("outputs")
csv_files = list(csv_dir.glob("*_preds.csv"))

# === Kayıtları topla ===
records = []
for file in csv_files:
    match = re.match(
        r"task(\d+)_(\w+)_(\d+)pct_d([0-9.]+)_wd([0-9.e-]+)_lr([0-9.e-]+)_preds\.csv",
        file.name
    )
    if not match:
        print(f"Dosya atlandı (regex eşleşmedi): {file.name}")
        continue

    task, model, portion, dropout, wd, lr = match.groups()
    df = pd.read_csv(file)
    mse = ((df["Tahmin"] - df["Gerçek"]) ** 2).mean()

    records.append({
        "task": int(task),
        "model": model,
        "portion": int(portion),
        "dropout": float(dropout),
        "weight_decay": float(wd),
        "lr": float(lr),
        "mse": mse,
        "file": file.name
    })

results_df = pd.DataFrame(records)

# === Best model klasörünü oluştur
best_dir = Path("best_models")
best_dir.mkdir(parents=True, exist_ok=True)

# === Her görev için: plot + en iyi modeli kopyala
for task_id in sorted(results_df["task"].unique()):
    task_df = results_df[results_df["task"] == task_id]
    plt.figure(figsize=(12, 6))

    for model in task_df["model"].unique():
        model_df = task_df[task_df["model"] == model]
        labels = model_df.apply(
            lambda row: f"p{row['portion']}_d{row['dropout']}_wd{row['weight_decay']}_lr{row['lr']}",
            axis=1
        )
        plt.plot(labels, model_df["mse"], marker='o', label=f"{model.upper()}")

    plt.title(f"Görev {task_id} - MSE Karşılaştırması")
    plt.xlabel("Hiperparametre Kombinasyonu")
    plt.ylabel("Test MSE")
    plt.xticks(rotation=45, ha='right')
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig(f"outputs/task{task_id}_mse_comparison.png")
    plt.close()

    # En iyi modeli bul ve kopyala
    best_row = task_df.loc[task_df["mse"].idxmin()]
    model_type = best_row["model"]
    original_model_name = best_row["file"].replace("_preds.csv", "_model.pt")
    original_model_path = csv_dir / original_model_name
    best_model_path = best_dir / f"best_model_task{task_id}_{model_type}.pt"

    if original_model_path.exists():
        shutil.copy(original_model_path, best_model_path)
        print(f"✅ Görev {task_id}: En iyi model kopyalandı → {best_model_path.name}")
    else:
        print(f"⚠️  Model dosyası bulunamadı: {original_model_path.name}")

print("🎉 Tüm görevler için karşılaştırmalar ve en iyi model kopyalama tamamlandı.")
