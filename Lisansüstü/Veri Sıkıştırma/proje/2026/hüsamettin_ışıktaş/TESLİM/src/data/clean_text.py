"""Text normalization and Gutenberg cleanup helpers."""

from __future__ import annotations

import re


START_RE = re.compile(r"\*\*\*\s*START OF (THE|THIS) PROJECT GUTENBERG EBOOK.*?\*\*\*", re.IGNORECASE)
END_RE = re.compile(r"\*\*\*\s*END OF (THE|THIS) PROJECT GUTENBERG EBOOK.*?\*\*\*", re.IGNORECASE)


def normalize_utf8(text: str) -> str:
    """Normalize text by replacing invalid code points."""
    return text.encode("utf-8", errors="replace").decode("utf-8", errors="replace")


def strip_gutenberg_boilerplate(text: str) -> str:
    """Remove common Gutenberg header/footer blocks if present."""
    start_match = START_RE.search(text)
    end_match = END_RE.search(text)

    start_index = start_match.end() if start_match else 0
    end_index = end_match.start() if end_match else len(text)

    return text[start_index:end_index].strip()


def normalize_whitespace(text: str) -> str:
    """Standardize line endings and trim noisy trailing spaces."""
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    text = "\n".join(line.rstrip() for line in text.split("\n"))
    return text.strip() + "\n"


def clean_text(text: str) -> str:
    """Apply full cleaning pipeline for raw Gutenberg text."""
    normalized = normalize_utf8(text)
    without_boilerplate = strip_gutenberg_boilerplate(normalized)
    return normalize_whitespace(without_boilerplate)


def reject_reason_for_text(text: str, min_chars: int = 1000) -> str | None:
    """Return rejection reason for unusable texts, otherwise None."""
    if not text.strip():
        return "empty_text"
    if len(text) < min_chars:
        return "too_short"
    return None
