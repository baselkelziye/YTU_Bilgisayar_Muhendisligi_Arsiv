"""Utilities for downloading Project Gutenberg text files."""

from __future__ import annotations

import logging
import threading
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
from typing import Iterable
from urllib.error import HTTPError, URLError
from urllib.parse import urlparse
from urllib.request import Request, urlopen

import yaml

logger = logging.getLogger(__name__)

USER_AGENT = "data-comp-project/0.1 (educational; Gutenberg text fetch)"


@dataclass(frozen=True)
class BookRecord:
    book_id: str
    title: str
    author: str
    language: str
    source_url: str


def load_book_sources(config_path: str | Path) -> list[BookRecord]:
    """Load book source entries from config/data_sources.yaml."""
    config_path = Path(config_path)
    data = yaml.safe_load(config_path.read_text(encoding="utf-8")) or {}
    books = data.get("books", [])
    return [
        BookRecord(
            book_id=str(item["book_id"]),
            title=str(item["title"]),
            author=str(item["author"]),
            language=str(item.get("language", "en")),
            source_url=str(item["source_url"]),
        )
        for item in books
    ]


def download_book_text(
    source_url: str,
    timeout_seconds: int = 30,
    retries: int = 2,
    backoff_seconds: float = 1.5,
) -> str:
    """Download raw text from URL or load from local path.

    Retries transient HTTP failures with exponential backoff. Raises the last
    exception if all attempts fail.
    """
    parsed = urlparse(source_url)
    if parsed.scheme in {"http", "https"}:
        last_exc: Exception | None = None
        for attempt in range(retries + 1):
            try:
                request = Request(source_url, headers={"User-Agent": USER_AGENT})
                with urlopen(request, timeout=timeout_seconds) as response:  # nosec B310
                    payload = response.read()
                return payload.decode("utf-8", errors="replace")
            except (HTTPError, URLError, TimeoutError) as exc:
                last_exc = exc
                if attempt < retries:
                    time.sleep(backoff_seconds * (2 ** attempt))
        assert last_exc is not None
        raise last_exc

    if parsed.scheme == "file":
        return Path(parsed.path).read_text(encoding="utf-8")

    return Path(source_url).read_text(encoding="utf-8")


def persist_raw_book(book: BookRecord, text: str, output_dir: str | Path) -> Path:
    """Save a raw book text under data/raw/books."""
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    file_path = output_dir / f"{book.book_id}.txt"
    file_path.write_text(text, encoding="utf-8")
    return file_path


def now_iso_utc() -> str:
    return datetime.now(timezone.utc).isoformat()


def iter_downloaded_rows(
    books: Iterable[BookRecord],
    output_dir: str | Path,
    skip_existing: bool = True,
    progress_every: int = 25,
):
    """Yield manifest-ready rows for downloaded books.

    Skips books that fail to download (logs the reason) so a single 404 or
    timeout does not abort the full corpus pull. If `skip_existing` is True,
    a previously persisted file is reused without re-downloading.
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    successes = 0
    failures = 0
    for index, book in enumerate(books, start=1):
        target_path = output_dir / f"{book.book_id}.txt"
        try:
            if skip_existing and target_path.exists() and target_path.stat().st_size > 0:
                file_path = target_path
            else:
                text = download_book_text(book.source_url)
                file_path = persist_raw_book(book, text, output_dir)
        except Exception as exc:  # noqa: BLE001 - resilient corpus pull
            failures += 1
            logger.warning("download_failed book_id=%s url=%s err=%s", book.book_id, book.source_url, exc)
            continue

        successes += 1
        if progress_every and (successes + failures) % progress_every == 0:
            logger.info(
                "progress index=%s ok=%s fail=%s last_id=%s",
                index,
                successes,
                failures,
                book.book_id,
            )

        yield {
            "book_id": book.book_id,
            "title": book.title,
            "author": book.author,
            "language": book.language,
            "source_url": book.source_url,
            "download_timestamp": now_iso_utc(),
            "raw_path": str(file_path),
        }

    logger.info("download_summary ok=%s fail=%s", successes, failures)


def fetch_books_parallel(
    books: Iterable[BookRecord],
    output_dir: str | Path,
    max_workers: int = 6,
    skip_existing: bool = True,
    progress_every: int = 50,
) -> list[dict[str, str]]:
    """Download books in parallel, preserving input order in the result.

    Failures are logged and skipped (no row in the output). Files already
    present on disk are reused when `skip_existing` is True.
    """
    output_dir = Path(output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    book_list = list(books)

    counters = {"ok": 0, "fail": 0, "done": 0}
    lock = threading.Lock()
    rows_by_index: dict[int, dict[str, str]] = {}

    def worker(index: int, book: BookRecord) -> None:
        target_path = output_dir / f"{book.book_id}.txt"
        try:
            if skip_existing and target_path.exists() and target_path.stat().st_size > 0:
                file_path = target_path
            else:
                text = download_book_text(book.source_url)
                file_path = persist_raw_book(book, text, output_dir)
        except Exception as exc:  # noqa: BLE001 - resilient corpus pull
            with lock:
                counters["fail"] += 1
                counters["done"] += 1
                done = counters["done"]
            logger.warning("download_failed book_id=%s url=%s err=%s", book.book_id, book.source_url, exc)
            if progress_every and done % progress_every == 0:
                logger.info("progress done=%s ok=%s fail=%s", done, counters["ok"], counters["fail"])
            return

        row = {
            "book_id": book.book_id,
            "title": book.title,
            "author": book.author,
            "language": book.language,
            "source_url": book.source_url,
            "download_timestamp": now_iso_utc(),
            "raw_path": str(file_path),
        }
        with lock:
            rows_by_index[index] = row
            counters["ok"] += 1
            counters["done"] += 1
            done = counters["done"]
        if progress_every and done % progress_every == 0:
            logger.info("progress done=%s ok=%s fail=%s", done, counters["ok"], counters["fail"])

    with ThreadPoolExecutor(max_workers=max_workers) as pool:
        futures = [pool.submit(worker, idx, book) for idx, book in enumerate(book_list)]
        for _ in as_completed(futures):
            pass

    logger.info("download_summary ok=%s fail=%s total=%s", counters["ok"], counters["fail"], len(book_list))
    return [rows_by_index[idx] for idx in sorted(rows_by_index)]
