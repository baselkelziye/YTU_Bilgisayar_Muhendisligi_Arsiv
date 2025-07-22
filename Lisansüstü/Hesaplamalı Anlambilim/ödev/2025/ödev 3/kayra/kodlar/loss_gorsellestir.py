import json, glob
from pathlib import Path

import matplotlib.pyplot as plt
import seaborn as sns

JSON_GLOB = "sonuclar/gpt2_*.json"
files = sorted(glob.glob(JSON_GLOB))
if not files:
    raise SystemExit(f"Dosya bulunamadı: {JSON_GLOB}")

def clean_log(path: str):
    """
    • Sadece 'loss' alanı olan satırları döndürür
      (train_loss / train_runtime vb. özet satırları atılır)
    • Epoch-loss çiftini kronolojik sırada verir
    """
    epochs, losses = [], []
    with open(path, encoding="utf-8") as f:
        log = json.load(f)

    for rec in log:
        # Özet satırı: genelde 'train_runtime' ya da sadece 'train_loss' içerir
        if "loss" not in rec:        # -> atla
            continue
        epochs.append(float(rec["epoch"]))
        losses.append(float(rec["loss"]))
    return epochs, losses

data = {
    Path(fp).stem: clean_log(fp)
    for fp in files
}

# En az bir geçerli nokta içermeyen modelleri at
data = {m: (e, l) for m, (e, l) in data.items() if e}
if not data:
    raise SystemExit("Grafik için yeterli veri kalmadı.")

# -------------------------------------------------------------------
# Grafik
# -------------------------------------------------------------------
sns.set_theme(style="whitegrid")
palette = sns.color_palette("colorblind", len(data))

plt.figure(figsize=(12, 6))
for (model, (epochs, losses)), color in zip(data.items(), palette):
    plt.plot(
        epochs,
        losses,
        label=model,
        color=color,
        linewidth=2,
        marker="o",
        markersize=3,
    )

plt.xlabel("Döngü (epoch)", fontsize=12)
plt.ylabel("Kayıp (loss)",  fontsize=12)
plt.title("GPT-2 Modelleri: Döngüye (epoch) Göre Eğitim Kaybı", fontsize=14)
plt.legend(title="Model", fontsize=9)
plt.tight_layout()
plt.savefig("sonuclar/train_loss.png", dpi=1200)
plt.show()