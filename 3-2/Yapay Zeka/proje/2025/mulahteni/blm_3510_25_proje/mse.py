import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import re

# === Klasör Ayarları ===
csv_dir = Path("outputs")
csv_files = list(csv_dir.glob("*_preds.csv"))
csv_dir.mkdir(parents=True, exist_ok=True)

records = []

# === CSV Dosyalarını İncele ===
for file in csv_files:
    match = re.match(
        r"task(\d+)_(\w+)_(\d+)pct_d([0-9.]+)_wd([0-9.e-]+)_lr([0-9.e-]+)_preds\.csv",
        file.name
    )
    if not match:
        print(f"❌ Dosya atlandı (regex eşleşmedi): {file.name}")
        continue

    task, model, portion, dropout, wd, lr = match.groups()
    df = pd.read_csv(file)
    y_true = df["Gerçek"]
    y_pred = df["Tahmin"]
    mse = ((y_pred - y_true) ** 2).mean()

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

# === Hepsini DataFrame'e al
results_df = pd.DataFrame(records)
results_df = results_df.sort_values(by=["task", "mse"])
results_df.to_csv(csv_dir / "all_model_results.csv", index=False)
print("✅ Tüm model sonuçları kaydedildi: all_model_results.csv")

# === Her görev için ayrı tablo ve grafikler
for task_id in sorted(results_df["task"].unique()):
    task_df = results_df[results_df["task"] == task_id]

    # Kombinasyon etiketleri
    labels = task_df.apply(
        lambda row: f"{row['model']}_p{row['portion']}_d{row['dropout']}_wd{row['weight_decay']}_lr{row['lr']}",
        axis=1
    )

    # MSE Grafiği
    plt.figure(figsize=(12, 6))
    plt.plot(labels, task_df["mse"], marker='o', label="MSE")
    plt.xticks(rotation=45, ha='right')
    plt.xlabel("Hiperparametre Kombinasyonu")
    plt.ylabel("Test MSE")
    plt.title(f"Görev {task_id} - MSE Değerleri")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(csv_dir / f"task{task_id}_mse_plot.png")
    plt.close()

print("🎉 Tüm görevler için metrikler analiz edildi ve görseller oluşturuldu.")
