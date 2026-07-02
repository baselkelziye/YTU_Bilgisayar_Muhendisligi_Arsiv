"""CSV manifest read/write helpers for phase 0 pipelines."""

from __future__ import annotations

import csv
from pathlib import Path
from typing import Any


def write_manifest(path: str | Path, rows: list[dict[str, Any]], fieldnames: list[str]) -> None:
    target = Path(path)
    target.parent.mkdir(parents=True, exist_ok=True)
    with target.open("w", encoding="utf-8", newline="") as csv_file:
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def read_manifest(path: str | Path) -> list[dict[str, str]]:
    source = Path(path)
    if not source.exists():
        return []
    with source.open("r", encoding="utf-8", newline="") as csv_file:
        return list(csv.DictReader(csv_file))
