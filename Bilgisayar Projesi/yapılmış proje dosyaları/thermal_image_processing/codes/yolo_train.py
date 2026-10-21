#!/usr/bin/env python3
# coding: utf-8
"""
train_yolo.py

Ultralytics YOLOv11 ile:
  • train/val/test klasörlerindeki images/ & labels/ alt yapısını kullanır
  • train içinden 8000–9999 ve 12000–13999 ID’li (1920×480, PNG) frameleri otomatik atlar
  • MONET kümesindeki 60000–61999 ID’li (800×600, PNG) frameleri dahil eder
  • eksik görüntü/etiket kontrolü yapar (sadece .jpg/.jpeg/.png uzantılarına bakar)
  • parametreleri CLI’dan alır

Kullanım:
  python train_yolo.py \
    --data_root /path/to/yolo_dataset \
    --model yolov11n.pt \
    --epochs 50 \
    --batch 16 \
    --imgsz 640 \
    --device 0
"""
import sys
import argparse
from pathlib import Path
from ultralytics import YOLO

# TRAIN split’ten hariç tutmak istediğiniz ID aralıkları (1920×480, PNG frameler)
EXCLUDE_RANGES = [(8000, 9999), (12000, 13999)]

# Geçerli resim uzantıları
VALID_EXTS = {".jpg", ".jpeg", ".png"}

def parse_args():
    p = argparse.ArgumentParser(description="YOLOv11 Eğitim Scripti")
    p.add_argument("--data_root", required=True,
                   help="Kök dizin (içinde train/, val/, test/ alt dizinleri olmalı)")
    p.add_argument("--model", default="yolov11n.pt",
                   help="Başlangıç ağırlıkları (.pt). Örn: yolov11n.pt")
    p.add_argument("--epochs", type=int, default=50, help="Epoch sayısı")
    p.add_argument("--batch", type=int, default=16, help="Batch boyutu")
    p.add_argument("--imgsz", type=int, default=640, help="Girdi imaj boyutu (piksel)")
    p.add_argument("--device", default="0", help="GPU aygıtı (örn '0' veya 'cpu')")
    return p.parse_args()

def is_excluded(idx: int) -> bool:
    """Eğitime dahil edilmeyecek ID aralıkları."""
    return any(start <= idx <= end for start, end in EXCLUDE_RANGES)

def sanity_check_and_clean(data_root: Path):
    """
    1) train/val/test altında images/ & labels/ var mı kontrol et
    2) train/images içinden EXCLUDE_RANGES’e giren ID’li dosyaları sil (jpg/png)
    3) sadece geçerli uzantılı dosyalar için görüntü-etiket eşleşmesini test et
    """
    for split in ("train", "val", "test"):
        img_dir = data_root / split / "images"
        lbl_dir = data_root / split / "labels"
        if not img_dir.is_dir() or not lbl_dir.is_dir():
            print(f"[ERROR] Eksik klasör: {img_dir} veya {lbl_dir}", file=sys.stderr)
            sys.exit(1)

        # Sadece TRAIN içinden is_excluded olanları sil
        if split == "train":
            for img_path in img_dir.iterdir():
                if not img_path.is_file() or img_path.suffix.lower() not in VALID_EXTS:
                    continue
                stem = img_path.stem
                if stem.isdigit() and is_excluded(int(stem)):
                    img_path.unlink()
                    lbl_file = lbl_dir / f"{stem}.txt"
                    if lbl_file.exists():
                        lbl_file.unlink()

        # Eşleşme kontrolü (sadece VALID_EXTS dosyaları)
        imgs = {p.stem for p in img_dir.iterdir() if p.is_file() and p.suffix.lower() in VALID_EXTS}
        lbls = {p.stem for p in lbl_dir.glob("*.txt")}
        missing_lbl = imgs - lbls
        missing_img = lbls - imgs
        if missing_lbl or missing_img:
            print(f"[ERROR] {split}: Eksik etiket: {list(missing_lbl)[:5]}, "
                  f"Eksik görüntü: {list(missing_img)[:5]}", file=sys.stderr)
            sys.exit(1)

    print("[OK] Sanity-check ve temizleme tamam.")

def write_data_yaml(data_root: Path, out_path="data.yaml"):
    """
    Ultralitycs’un istediği formatta data.yaml oluşturur.
    Yalnızca 2 sınıf: person, vehicle
    """
    content = f"""
path: {data_root}
train: train/images
val:   val/images
test:  test/images

# Sınıf isimleri
names:
  0: person
  1: vehicle
"""
    with open(out_path, "w") as f:
        f.write(content.strip())
    print(f"[OK] data.yaml oluşturuldu: {out_path}")

def main():
    args = parse_args()
    root = Path(args.data_root)

    # 1) ön kontroller ve temizleme
    sanity_check_and_clean(root)

    # 2) data.yaml oluştur
    write_data_yaml(root)

    # 3) model tanımı ve eğitim
    model = YOLO(args.model)
    model.train(
        data="data.yaml",
        epochs=args.epochs,
        batch=args.batch,
        imgsz=args.imgsz,
        device=args.device,
        multi_scale=True,
        patience=10,
        augment=True,
        lr0=0.02,
        momentum=0.937,
        weight_decay=0.0005,
    )

    # 4) sonuçları test et
    print("\n[INFO] Test seti üzerinde değerlendirme:")
    model.val(data="data.yaml", batch=args.batch, imgsz=args.imgsz)

if __name__ == "__main__":
    main()
