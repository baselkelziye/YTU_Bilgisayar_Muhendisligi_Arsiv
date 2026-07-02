"""Feature extraction orchestration for phase 1."""

from __future__ import annotations

import csv
import logging
from pathlib import Path

import pandas as pd

from src.features.compression_features import extract_set_a_features
from src.features.fast_features import extract_set_b_features

logger = logging.getLogger(__name__)


def _read_csv(path: Path) -> list[dict[str, str]]:
    with path.open("r", encoding="utf-8", newline="") as handle:
        return list(csv.DictReader(handle))


def _resolve_clean_path(project_root: Path, row: dict[str, str]) -> Path:
    candidate = Path(row["clean_path"])
    if candidate.exists():
        return candidate
    fallback = project_root / "data" / "processed" / "books" / f"{row['book_id']}.txt"
    return fallback


def chunk_text(text: str, chunk_size: int | None) -> list[str]:
    """Split text into fixed-size character chunks."""
    if chunk_size is None or chunk_size <= 0 or len(text) <= chunk_size:
        return [text]
    return [text[idx : idx + chunk_size] for idx in range(0, len(text), chunk_size)]


def build_feature_tables(
    project_root: Path,
    manifest_clean_path: Path,
    split_path: Path,
    chunk_size: int | None,
    include_set_a: bool = True,
    include_set_b: bool = True,
    progress_every: int = 100,
) -> tuple[pd.DataFrame, pd.DataFrame]:
    """Build Set A and/or Set B feature tables for accepted books.

    Set A (compression-aware: zlib/bz2/lzma) is the expensive set. When only
    a clustering signal is needed (e.g. chunk-size sweep) callers can pass
    ``include_set_a=False`` to skip it.
    """
    manifest_rows = _read_csv(manifest_clean_path)
    split_rows = _read_csv(split_path)
    split_map = {row["book_id"]: row["split"] for row in split_rows}

    rows_a: list[dict[str, float | str | int]] = []
    rows_b: list[dict[str, float | str | int]] = []

    processed_books = 0
    total_chunks = 0
    for row in manifest_rows:
        if row.get("quality_status") != "accepted":
            continue
        book_id = row["book_id"]
        split = split_map.get(book_id)
        if not split:
            continue

        clean_path = _resolve_clean_path(project_root, row)
        if not clean_path.exists():
            continue
        text = clean_path.read_text(encoding="utf-8")
        chunks = chunk_text(text, chunk_size=chunk_size)

        for chunk_idx, chunk in enumerate(chunks):
            if not chunk.strip():
                continue
            base = {
                "book_id": book_id,
                "chunk_id": f"{book_id}_{chunk_idx}",
                "chunk_index": chunk_idx,
                "split": split,
                "chunk_size_chars": len(chunk),
                "source_text_length": len(text),
            }
            if include_set_a:
                rows_a.append(base | extract_set_a_features(chunk))
            if include_set_b:
                rows_b.append(base | extract_set_b_features(chunk))
            total_chunks += 1

        processed_books += 1
        if progress_every and processed_books % progress_every == 0:
            logger.info(
                "feature_pipeline books=%s chunks=%s chunk_size=%s set_a=%s",
                processed_books,
                total_chunks,
                chunk_size,
                include_set_a,
            )

    logger.info(
        "feature_pipeline_done books=%s chunks=%s chunk_size=%s set_a=%s set_b=%s",
        processed_books,
        total_chunks,
        chunk_size,
        include_set_a,
        include_set_b,
    )
    return pd.DataFrame(rows_a), pd.DataFrame(rows_b)

