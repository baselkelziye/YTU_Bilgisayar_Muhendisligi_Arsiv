"""Run phase 0 data pipeline end-to-end."""

from __future__ import annotations

import json
import logging
import sys
from collections import Counter, defaultdict
from pathlib import Path

import yaml

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s %(levelname)s %(name)s :: %(message)s",
)

PROJECT_ROOT = Path(__file__).resolve().parents[1]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from src.data.clean_text import clean_text, reject_reason_for_text
from src.data.gutenberg_downloader import fetch_books_parallel, load_book_sources
from src.data.manifest import write_manifest
from src.data.split_books import assert_no_leakage, split_book_ids


RAW_FIELDS = [
    "book_id",
    "title",
    "author",
    "language",
    "source_url",
    "download_timestamp",
    "raw_path",
]
PROCESSED_FIELDS = [
    "book_id",
    "title",
    "author",
    "language",
    "source_url",
    "clean_path",
    "quality_status",
    "reject_reason",
]
SPLIT_FIELDS = ["book_id", "split", "seed"]


def load_split_config(path: Path) -> dict:
    config = yaml.safe_load(path.read_text(encoding="utf-8")) or {}
    ratios = config.get("split_ratios", {})
    return {
        "train_ratio": float(ratios.get("train", 0.70)),
        "val_ratio": float(ratios.get("validation", 0.15)),
        "test_ratio": float(ratios.get("test", 0.15)),
        "seed": int(config.get("random_seed", 42)),
    }


def main() -> int:
    project_root = PROJECT_ROOT
    data_root = project_root / "data"
    raw_books_dir = data_root / "raw" / "books"
    processed_books_dir = data_root / "processed" / "books"
    artifacts_dir = project_root / "artifacts" / "phase0"

    books = load_book_sources(project_root / "config" / "data_sources.yaml")
    raw_rows = fetch_books_parallel(books, raw_books_dir, max_workers=6)
    write_manifest(data_root / "raw" / "manifest_raw.csv", raw_rows, RAW_FIELDS)

    clean_rows: list[dict[str, str]] = []
    accepted_book_ids: list[str] = []
    rejection_counter: Counter[str] = Counter()
    raw_bytes_total = 0
    clean_bytes_total = 0

    processed_books_dir.mkdir(parents=True, exist_ok=True)
    for row in raw_rows:
        raw_path = Path(row["raw_path"])
        raw_text = raw_path.read_text(encoding="utf-8")
        raw_bytes_total += len(raw_text.encode("utf-8"))

        cleaned = clean_text(raw_text)
        reject_reason = reject_reason_for_text(cleaned)

        clean_path = processed_books_dir / f"{row['book_id']}.txt"
        quality_status = "rejected"
        if reject_reason is None:
            clean_path.write_text(cleaned, encoding="utf-8")
            clean_bytes_total += len(cleaned.encode("utf-8"))
            quality_status = "accepted"
            accepted_book_ids.append(row["book_id"])
        else:
            rejection_counter[reject_reason] += 1

        clean_rows.append(
            {
                "book_id": row["book_id"],
                "title": row["title"],
                "author": row["author"],
                "language": row["language"],
                "source_url": row["source_url"],
                "clean_path": str(clean_path),
                "quality_status": quality_status,
                "reject_reason": reject_reason or "",
            }
        )

    write_manifest(data_root / "processed" / "manifest_clean.csv", clean_rows, PROCESSED_FIELDS)

    split_cfg = load_split_config(project_root / "config" / "splits.yaml")
    split_dict = split_book_ids(
        accepted_book_ids,
        train_ratio=split_cfg["train_ratio"],
        val_ratio=split_cfg["val_ratio"],
        test_ratio=split_cfg["test_ratio"],
        seed=split_cfg["seed"],
    )
    assert_no_leakage(split_dict)

    split_rows: list[dict[str, str]] = []
    split_bytes: dict[str, int] = defaultdict(int)
    for split_name, ids in split_dict.items():
        for book_id in ids:
            split_rows.append({"book_id": book_id, "split": split_name, "seed": str(split_cfg["seed"])})
            clean_file = processed_books_dir / f"{book_id}.txt"
            if clean_file.exists():
                split_bytes[split_name] += len(clean_file.read_bytes())
    write_manifest(data_root / "processed" / "book_splits.csv", split_rows, SPLIT_FIELDS)

    artifacts_dir.mkdir(parents=True, exist_ok=True)
    data_quality_report = {
        "generated": True,
        "raw_books": len(raw_rows),
        "accepted_books": len(accepted_book_ids),
        "rejected_books": len(raw_rows) - len(accepted_book_ids),
        "reject_reasons": dict(rejection_counter),
        "raw_total_bytes": raw_bytes_total,
        "clean_total_bytes": clean_bytes_total,
    }
    split_summary = {
        "generated": True,
        "seed": split_cfg["seed"],
        "ratios": {
            "train": split_cfg["train_ratio"],
            "validation": split_cfg["val_ratio"],
            "test": split_cfg["test_ratio"],
        },
        "book_counts": {key: len(value) for key, value in split_dict.items()},
        "byte_distribution": {
            "train": split_bytes.get("train", 0),
            "validation": split_bytes.get("validation", 0),
            "test": split_bytes.get("test", 0),
        },
        "leakage_check": "passed",
    }
    (artifacts_dir / "data_quality_report.json").write_text(
        json.dumps(data_quality_report, indent=2), encoding="utf-8"
    )
    (artifacts_dir / "split_summary.json").write_text(json.dumps(split_summary, indent=2), encoding="utf-8")

    print(json.dumps({"status": "ok", "raw_books": len(raw_rows), "accepted_books": len(accepted_book_ids)}, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
