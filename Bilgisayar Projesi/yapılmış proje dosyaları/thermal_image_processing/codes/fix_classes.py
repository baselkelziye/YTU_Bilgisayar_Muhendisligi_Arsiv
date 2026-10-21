#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os

def filter_and_remap(labels_dir, start_idx=56000, end_idx=59999):
    """
    labels_dir içindeki start_idx–end_idx arasındaki N.txt dosyalarını işle:
      - class != 2 satırları kaldır
      - geriye kalan class 2 satırlarının başındaki '2' yi '0' olarak değiştir
      - dosya boş da kalsa, yine de üzerine yaz
    """
    for idx in range(start_idx, end_idx + 1):
        fname = f"{idx}.txt"
        path = os.path.join(labels_dir, fname)
        if not os.path.isfile(path):
            # Dosya yoksa atla
            continue

        kept = []
        with open(path, "r") as f:
            for line in f:
                line = line.strip()
                if not line:
                    continue
                parts = line.split()
                try:
                    cls = int(parts[0])
                except ValueError:
                    # parse edilemeyen satırları da atla
                    continue
                if cls == 2:
                    # cls=2 ise, etiket kısmını '0' ile değiştir
                    parts[0] = "0"
                    kept.append(" ".join(parts))

        # Sonuçları tekrar dosyaya yaz (boş da olabilir)
        with open(path, "w") as f:
            if kept:
                f.write("\n".join(kept) + "\n")

if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(
        description="56000–59999 arası .txt dosyalarında class≠2 satırları sil, class=2 olanları 0 yap."
    )
    parser.add_argument("labels_dir", help="Label dosyalarının klasörü (images değil, labels)")
    parser.add_argument("--start", type=int, default=56000, help="Başlangıç index (inclusive)")
    parser.add_argument("--end",   type=int, default=59999, help="Bitiş index (inclusive)")
    args = parser.parse_args()

    filter_and_remap(args.labels_dir, args.start, args.end)
    print("Tamamlandı.")

