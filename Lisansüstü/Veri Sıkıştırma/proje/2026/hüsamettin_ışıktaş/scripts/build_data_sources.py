"""Build config/data_sources.yaml from Project Gutenberg catalog.

Filters: Type == 'Text', Language == 'en'.
Selection: deterministic random sample (seed=42) of `target_count`.
"""

from __future__ import annotations

import csv
import random
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1]
CATALOG_PATH = Path("/tmp/gutenberg/pg_catalog.csv")
OUTPUT_PATH = PROJECT_ROOT / "config" / "data_sources.yaml"

TARGET_COUNT = 1000
SEED = 42


def yaml_escape(value: str) -> str:
    safe = value.replace("\\", "\\\\").replace('"', '\\"')
    return f'"{safe}"'


def main() -> int:
    if not CATALOG_PATH.exists():
        print(f"ERROR: catalog not found at {CATALOG_PATH}", file=sys.stderr)
        return 1

    candidates: list[dict[str, str]] = []
    with CATALOG_PATH.open("r", encoding="utf-8", newline="") as fh:
        reader = csv.DictReader(fh)
        for row in reader:
            if row.get("Type", "").strip() != "Text":
                continue
            if row.get("Language", "").strip() != "en":
                continue
            book_id = row.get("Text#", "").strip()
            title = row.get("Title", "").strip()
            authors = row.get("Authors", "").strip()
            if not book_id or not title:
                continue
            candidates.append(
                {
                    "book_id": book_id,
                    "title": title,
                    "author": authors or "Unknown",
                    "language": "en",
                }
            )

    print(f"candidates: {len(candidates)} en/Text books in catalog")
    if len(candidates) < TARGET_COUNT:
        print("ERROR: fewer candidates than target", file=sys.stderr)
        return 2

    rng = random.Random(SEED)
    selection = rng.sample(candidates, TARGET_COUNT)
    selection.sort(key=lambda r: int(r["book_id"]))

    lines: list[str] = []
    lines.append("project_gutenberg:")
    lines.append("  enabled: true")
    lines.append("  request_timeout_seconds: 30")
    lines.append("  max_books: 1000")
    lines.append("  min_books: 500")
    lines.append("  selection:")
    lines.append("    method: random_sample")
    lines.append(f"    seed: {SEED}")
    lines.append(f"    target_count: {TARGET_COUNT}")
    lines.append("    catalog_source: https://www.gutenberg.org/cache/epub/feeds/pg_catalog.csv")
    lines.append("    filters:")
    lines.append("      type: Text")
    lines.append("      language: en")
    lines.append("")
    lines.append("books:")
    for record in selection:
        bid = record["book_id"]
        url = f"https://www.gutenberg.org/cache/epub/{bid}/pg{bid}.txt"
        lines.append(f'  - book_id: "{bid}"')
        lines.append(f"    title: {yaml_escape(record['title'])}")
        lines.append(f"    author: {yaml_escape(record['author'])}")
        lines.append("    language: en")
        lines.append(f"    source_url: {yaml_escape(url)}")
    lines.append("")

    OUTPUT_PATH.write_text("\n".join(lines), encoding="utf-8")
    print(f"wrote {OUTPUT_PATH} with {len(selection)} books")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
