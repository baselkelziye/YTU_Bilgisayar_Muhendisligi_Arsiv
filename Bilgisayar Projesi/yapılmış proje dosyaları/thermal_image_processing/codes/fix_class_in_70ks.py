#!/usr/bin/env python3
"""
filter_and_relabel.py

For all YOLO-format .txt label files in a train/labels directory whose stem ≥ START_ID:
  1) Remove any lines whose class ≠ INPUT_CLASS
  2) Remap the remaining lines’ class from INPUT_CLASS → OUTPUT_CLASS
  3) If a file ends up empty, delete it

Usage:
    python filter_and_relabel.py \
      --labels-dir /path/to/processed/train/labels \
      --start-id 70000 \
      --input-class 2 \
      --output-class 0
"""

import argparse
from pathlib import Path

def process_labels(labels_dir: Path, start_id: int, input_class: str, output_class: str):
    if not labels_dir.is_dir():
        print(f"[ERROR] labels-dir not found: {labels_dir}")
        return
    for txt in sorted(labels_dir.iterdir()):
        if txt.suffix.lower() != ".txt":
            continue
        try:
            idx = int(txt.stem)
        except ValueError:
            # skip non-numeric filenames
            continue
        if idx < start_id:
            continue

        # Read existing lines
        lines = txt.read_text().splitlines()
        new_lines = []
        for line in lines:
            parts = line.strip().split()
            if not parts:
                continue
            cls = parts[0]
            if cls != input_class:
                # Drop any line not matching the desired class
                continue
            # Replace class index
            parts[0] = output_class
            new_lines.append(" ".join(parts))

        # Write back (always), leaving file empty if no lines
        txt.write_text("\n".join(new_lines))
        print(f"Processed {txt.name}: {len(new_lines)} lines kept")


def parse_args():
    p = argparse.ArgumentParser(description="Normalize YOLO classes in labels directory, keeping empty files.")
    p.add_argument("--labels-dir", "-l", required=True,
                   help="Path to labels directory containing .txt files")
    p.add_argument("--start-id", "-s", type=int, default=0,
                   help="Only process files with numeric stem >= this ID")
    p.add_argument("--input-class", "-i", required=True,
                   help="Original class index to keep and replace")
    p.add_argument("--output-class", "-o", required=True,
                   help="New class index to set for kept labels")
    return p.parse_args()


def main():
    args = parse_args()
    process_labels(Path(args.labels_dir), args.start_id, args.input_class, args.output_class)

if __name__ == "__main__":
    main()
