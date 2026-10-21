#!/usr/bin/env python3
# coding: utf-8
"""
clean_val_excluded.py

Val klasöründeki 8000–9999 ve 12000–13999 ID’li dosyaları siler.
Kullanım:
    python clean_val_excluded.py /path/to/yolo_dataset/val
"""
import sys
from pathlib import Path

# VAL’den silinecek ID aralıkları
EXCLUDE_RANGES = [(8000, 9999), (12000, 13999)]

def is_excluded(idx: int) -> bool:
    return any(start <= idx <= end for start, end in EXCLUDE_RANGES)

def main(val_dir: Path):
    img_dir = val_dir / "images"
    lbl_dir = val_dir / "labels"
    if not img_dir.is_dir() or not lbl_dir.is_dir():
        print(f"[ERROR] Klasör bulunamadı: {img_dir} veya {lbl_dir}")
        sys.exit(1)

    removed = 0
    for img_path in img_dir.glob("*"):
        stem = img_path.stem
        if stem.isdigit() and is_excluded(int(stem)):
            # resim dosyasını sil
            img_path.unlink()
            # karşılık gelen label dosyasını sil
            lbl_file = lbl_dir / f"{stem}.txt"
            if lbl_file.exists():
                lbl_file.unlink()
            removed += 1

    print(f"[OK] Val içinden {removed} dosya silindi ({EXCLUDE_RANGES}).")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Kullanım: python clean_val_excluded.py /path/to/yolo_dataset/val")
        sys.exit(1)
    main(Path(sys.argv[1]))

