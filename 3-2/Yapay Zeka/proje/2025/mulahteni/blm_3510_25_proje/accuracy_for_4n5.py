import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import re

csv_dir = Path("outputs")
csv_files = list(csv_dir.glob("task[45]_*.csv"))

records = []

# Sadece Görev 4 ve 5
for file in csv_files:
    match = re.match(
        r"task(4|5)_(\w+)_(\d+)pct_d([0-9.]+)_wd([0-9.e-]+)_lr([0-9.e-]+)_preds\.csv",
        file.name
    )
    if not match:
        continue

    task, model, portion, dropout, wd, lr = match.groups()
    df = pd.read_csv(file)
    y_true = df["Gerçek"].astype(int)
    y_pred = df["Tahmin"].round().astype(int)

    acc = (y_true == y_pred).mean()

    records.append({
        "task": int(task),
        "model": model,
        "portion": int(portion),
        "dropout": float(dropout),
        "weight_decay": float(wd),
        "lr": float(lr),
        "accuracy": acc,
        "file": file.name
    })

results_df = pd.DataFrame(records)
results_df = results_df.sort_values(by=["task", "accuracy"], ascending=[True, False])

# Her görev için tablo ve grafik
for task_id in [4, 5]:
    task_df = results_df[results_df["task"] == task_id].copy()
    if task_df.empty:
        continue

    # CSV olarak kaydet
    table_path = csv_dir / f"task{task_id}_accuracy_table.csv"
    task_df.to_csv(table_path, index=False)

    # Grafik olarak kaydet
    plt.figure(figsize=(12, 6))
    labels = task_df.apply(
        lambda row: f"{row['model']}_p{row['portion']}_d{row['dropout']}_wd{row['weight_decay']}_lr{row['lr']}",
        axis=1
    )
    plt.plot(labels, task_df["accuracy"], marker='o', color='green')
    plt.xticks(rotation=45, ha='right')
    plt.xlabel("Hiperparametre Kombinasyonu")
    plt.ylabel("Accuracy")
    plt.title(f"Görev {task_id} - Accuracy Karşılaştırması")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(csv_dir / f"task{task_id}_accuracy_plot.png")
    plt.close()

    print(f"✅ Görev {task_id} için accuracy kaydedildi: {table_path.name}")

print("🎯 Görev 4 ve 5 için analiz tamamlandı.")
