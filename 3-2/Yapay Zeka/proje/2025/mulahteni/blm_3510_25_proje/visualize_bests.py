import numpy as np
import matplotlib.pyplot as plt
import torch
from pathlib import Path
import re
from train_utils import get_model

# === Ayarlar ===
input_size = 25 * 25
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

for task_id in range(1, 6):
    # Dosya yolları
    test_path = Path(f"testing/task_{task_id}/data.npz")
    result_dir = Path(f"testing/task_{task_id}/result")
    result_dir.mkdir(parents=True, exist_ok=True)

    # Model dosyasını bul ve türünü belirle
    model_candidates = list(Path("best_models").glob(f"best_model_task{task_id}_*.pt"))
    if not model_candidates:
        print(f"⚠️  Görev {task_id} için model bulunamadı.")
        continue

    model_path = model_candidates[0]
    if "mlp" in model_path.stem:
        model_type = "mlp"
        input_shape = input_size
    elif "cnn" in model_path.stem:
        model_type = "cnn"
        input_shape = None
    else:
        print(f"⚠️  Model türü anlaşılamadı: {model_path.name}")
        continue

    # Veriyi yükle
    data = np.load(test_path)
    X = data["X"]
    y_true = data["y"]

    # Modeli oluştur ve yükle
    model = get_model(model_type, input_shape, dropout=0.0).to(device)
    model.load_state_dict(torch.load(model_path, map_location=device))
    model.eval()

    # Girdi formatı
    X_input = X.reshape(len(X), -1) if model_type == "mlp" else X[:, None, :, :]
    X_tensor = torch.tensor(X_input, dtype=torch.float32).to(device)

    # Tahmin üret
    with torch.no_grad():
        preds = model(X_tensor).cpu().squeeze().numpy()

    # Görselleştir
    for i in range(len(X)):
        fig, ax = plt.subplots()
        ax.imshow(X[i], cmap="gray")
        ax.set_title(f"Gerçek: {y_true[i]:.2f} | Tahmin: {preds[i]:.2f}")
        ax.axis("off")
        plt.tight_layout()
        plt.savefig(result_dir / f"sample_{i+1}.png")
        plt.close()

    print(f"✅ Görev {task_id}: Görseller kaydedildi → {result_dir}")
