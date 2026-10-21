import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

def plot_and_save(csv_file: Path):
    df = pd.read_csv(csv_file)
    plt.figure(figsize=(10, 6))
    plt.plot(df["Gerçek"], label="Gerçek", marker='o', linestyle='--')
    plt.plot(df["Tahmin"], label="Tahmin", marker='x', linestyle='-')
    plt.title(csv_file.stem.replace("_", " ").title())
    plt.xlabel("Örnek No")
    plt.ylabel("Değer")
    plt.legend()
    plt.grid(True)

    out_path = csv_file.with_name(csv_file.stem + "_plot.png")
    plt.savefig(out_path)
    print(f"✅ Kaydedildi: {out_path}")
    plt.close()

def main(folder="outputs"):
    folder = Path(folder)
    csv_files = folder.glob("*_preds.csv")

    for csv_file in csv_files:
        try:
            plot_and_save(csv_file)
        except Exception as e:
            print(f"⚠️  {csv_file} işlenemedi: {e}")

if __name__ == "__main__":
    main()
