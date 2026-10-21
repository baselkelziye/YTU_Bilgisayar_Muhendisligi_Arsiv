#!/usr/bin/env python3
"""
split_extra_train.py

From train/images & train/labels, take all files with stem >= START_IDX,
then:
  1) move the last VAL_RATIO% into val/images & val/labels
  2) of the remainder, move the last TEST_RATIO% into test/images & test/labels

Usage:
    python split_70ks_to_val_and_test.py \
      --processed_dir ./processed \
      --start_idx 70000 \
      --val_ratio 0.1 \
      --test_ratio 0.1
"""
import argparse
import math
import shutil
from pathlib import Path

def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument("--processed_dir", required=True,
                   help="Root of processed dataset (with train/, val/, test/ subdirs)")
    p.add_argument("--start_idx", type=int, default=70000,
                   help="Minimum numeric stem to consider as 'extra'")
    p.add_argument("--val_ratio", type=float, default=0.1,
                   help="Fraction of extra to move into validation")
    p.add_argument("--test_ratio", type=float, default=0.1,
                   help="Fraction of (extra minus val) to move into test")
    return p.parse_args()

def move_subset(files, src_imgs, src_lbls, dst_imgs, dst_lbls):
    for img in files:
        lbl = src_lbls / f"{img.stem}.txt"
        shutil.move(str(img), str(dst_imgs / img.name))
        if lbl.exists():
            shutil.move(str(lbl), str(dst_lbls / f"{img.stem}.txt"))

def main():
    args = parse_args()
    proc = Path(args.processed_dir)
    train_imgs = proc / "train" / "images"
    train_lbls = proc / "train" / "labels"
    val_imgs   = proc / "val"   / "images"
    val_lbls   = proc / "val"   / "labels"
    test_imgs  = proc / "test"  / "images"
    test_lbls  = proc / "test"  / "labels"

    # gather extra images with numeric stem >= start_idx
    all_imgs = sorted(
        [p for p in train_imgs.iterdir() if p.suffix.lower() in (".jpg",".jpeg",".png")],
        key=lambda p: int(p.stem) if p.stem.isdigit() else -1
    )
    extra = [p for p in all_imgs if p.stem.isdigit() and int(p.stem) >= args.start_idx]
    n_extra = len(extra)
    if n_extra == 0:
        print(f"No images >= {args.start_idx} found in train/images")
        return

    # compute how many to val
    n_val = math.ceil(n_extra * args.val_ratio)
    val_files = extra[-n_val:]
    print(f"Moving {n_val} -> val (indices {val_files[0].stem}–{val_files[-1].stem})")
    move_subset(val_files, train_imgs, train_lbls, val_imgs, val_lbls)

    # remaining extras
    rem = extra[:-n_val]
    n_rem = len(rem)
    n_test = math.ceil(n_rem * args.test_ratio)
    test_files = rem[-n_test:]
    print(f"Moving {n_test} -> test (indices {test_files[0].stem}–{test_files[-1].stem})")
    move_subset(test_files, train_imgs, train_lbls, test_imgs, test_lbls)

    print("Done.")

if __name__ == "__main__":
    main()
