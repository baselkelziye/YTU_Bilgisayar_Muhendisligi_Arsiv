#!/usr/bin/env python3
"""
move_extra_to_train.py

Move all images & labels from processed/extra into processed/train, renaming them
to start at a given offset (70000 by default).

Usage:
    python move_extra_to_train.py \
        --processed_dir /content/processed \
        --start_idx 70000
"""
import argparse
import shutil
from pathlib import Path

def main():
    p = argparse.ArgumentParser()
    p.add_argument(
        "--processed_dir", required=True,
        help="Root of your processed dataset (with train/, val/, test/, extra/ subdirs)"
    )
    p.add_argument(
        "--start_idx", type=int, default=70000,
        help="First index to assign to the extra images"
    )
    args = p.parse_args()

    proc = Path(args.processed_dir)
    extra_imgs = sorted((proc / "extra" / "images").glob("*.*"), key=lambda p: int(p.stem))
    extra_lbls = proc / "extra" / "labels"

    train_imgs = proc / "train" / "images"
    train_lbls = proc / "train" / "labels"

    idx = args.start_idx
    moved = 0

    for img_path in extra_imgs:
        # build new names
        new_name = f"{idx}{img_path.suffix}"
        new_img = train_imgs / new_name

        # move image
        shutil.move(str(img_path), str(new_img))

        # move corresponding label
        old_lbl = extra_lbls / f"{img_path.stem}.txt"
        if old_lbl.exists():
            new_lbl = train_lbls / f"{idx}.txt"
            shutil.move(str(old_lbl), str(new_lbl))
        else:
            print(f"[WARN] no label for {img_path.name}")

        idx += 1
        moved += 1

    print(f"Done — moved {moved} extra image/label pairs into train starting at {args.start_idx}")

if __name__ == "__main__":
    main()
