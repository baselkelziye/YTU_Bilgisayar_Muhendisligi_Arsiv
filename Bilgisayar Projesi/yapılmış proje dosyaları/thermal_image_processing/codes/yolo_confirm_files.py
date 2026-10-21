#!/usr/bin/env python3
# coding: utf-8
import os
import sys
import argparse
from glob import glob
from collections import Counter
from PIL import Image

EXCLUDE_RANGES = [(8000, 9999), (12000, 13999)]  # Bu ID aralıkları train'den atılacak

def parse_args():
    p = argparse.ArgumentParser(
        description="YOLO veri seti ön-check: klasör, eşleşme, çözünürlük, ID filtreleri"
    )
    p.add_argument("root", help="Veri seti kök dizini (içinde train/, val/, test/ bulunacak)")
    return p.parse_args()

def is_excluded(img_id):
    return any(start <= img_id <= end for start, end in EXCLUDE_RANGES)

def scan_split(root, split):
    img_dir = os.path.join(root, split, "images")
    lbl_dir = os.path.join(root, split, "labels")
    if not os.path.isdir(img_dir) or not os.path.isdir(lbl_dir):
        print(f"[ERROR] {split}: eksik folder: {img_dir} veya {lbl_dir}", file=sys.stderr)
        sys.exit(1)

    img_files = glob(os.path.join(img_dir, "*"))
    lbl_files = glob(os.path.join(lbl_dir, "*.txt"))

    # id → path
    imgs = {}
    for p in img_files:
        name = os.path.splitext(os.path.basename(p))[0]
        if not name.isdigit(): continue
        imgs[int(name)] = p

    lbls = {int(os.path.splitext(os.path.basename(p))[0]): p for p in lbl_files if os.path.splitext(os.path.basename(p))[0].isdigit()}

    excluded = []
    missing_labels = []
    missing_images = []
    res_counter = Counter()

    for img_id, img_path in sorted(imgs.items()):
        if split == "train" and is_excluded(img_id):
            excluded.append(img_id)
            continue

        # resolution
        try:
            w,h = Image.open(img_path).size
            res_counter[f"{w}x{h}"] += 1
        except Exception as e:
            print(f"[WARN] {split} {img_path}: çözünürlük okunamadı: {e}", file=sys.stderr)

        # etiketi kontrol et
        if img_id not in lbls:
            missing_labels.append(img_id)

    # etiket dosyalarında ama görüntü eksik
    for lbl_id in lbls:
        if split == "train" and is_excluded(lbl_id):
            continue
        if lbl_id not in imgs:
            missing_images.append(lbl_id)

    kept = len(imgs) - len(excluded)
    print(f"\n=== SPLIT: {split.upper()} ===")
    print(f"  toplam görüntü dosyası     : {len(imgs)}")
    if split=="train":
        print(f"  hariç tutulan ID aralığı   : {len(excluded)} ({EXCLUDE_RANGES})")
    print(f"  kullanımda görüntü sayısı   : {kept}")
    print(f"  eksik etiket sayısı        : {len(missing_labels)}", 
          f"{missing_labels[:10]}{'...' if len(missing_labels)>10 else ''}")
    print(f"  etiketsiz görüntü sayısı    : {len(missing_labels)}")
    print(f"  görüntüsüz etiket sayısı    : {len(missing_images)}", 
          f"{missing_images[:10]}{'...' if len(missing_images)>10 else ''}")
    print("  çözünürlük dağılımı         :")
    for res, cnt in res_counter.most_common():
        print(f"    {res:10s} → {cnt}")

    # kritik hata varsa çık
    if missing_labels or missing_images:
        print(f"[FAIL] {split}: eksik dosyalar tespit edildi.", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    args = parse_args()
    root = args.root

    for split in ("train", "val", "test"):
        scan_split(root, split)

    print("\n[OK] Tüm pre-check’ler başarıyla tamamlandı.")
    sys.exit(0)

