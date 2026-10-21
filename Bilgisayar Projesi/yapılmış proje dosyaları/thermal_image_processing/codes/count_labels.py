#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import glob

def main(labels_dir):
    """
    labels_dir içindeki .txt dosyalarını dolaş ve sadece 0 dışı class içerenleri yazdır.
    """
    pattern = os.path.join(labels_dir, "*.txt")
    files = sorted(glob.glob(pattern))
    if not files:
        print(f"Hiç .txt dosyası bulunamadı: {labels_dir}")
        return

    for path in files:
        classes = set()
        with open(path, 'r') as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                parts = line.split()
                try:
                    cls = int(parts[0])
                except:
                    continue
                classes.add(cls)

        # 0 dışında herhangi bir class var mı?
        others = sorted(c for c in classes if c != 0)
        if others:
            cls_list = ", ".join(str(c) for c in others)
            print(f"{os.path.basename(path)} -> other classes: {cls_list}")

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(
        description="Sadece içinde 0 dışı class bulunan label dosyalarını listeler.")
    parser.add_argument("labels_dir", type=str,
                        help="Label dosyalarının bulunduğu klasör (örn: processed/train/labels)")
    args = parser.parse_args()
    main(args.labels_dir)
