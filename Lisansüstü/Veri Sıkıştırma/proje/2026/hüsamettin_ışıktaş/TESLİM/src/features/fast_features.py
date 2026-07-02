"""Set B fast features for lightweight profile inference."""

from __future__ import annotations

import math
import re
import string
from collections import Counter


WORD_RE = re.compile(r"\b\w+\b", re.UNICODE)
PRINTABLE_ASCII = set(chr(i) for i in range(32, 127)) | {"\n", "\t", "\r"}

FEATURE_SET_B_COLUMNS = [
    "n_chars",
    "n_words",
    "avg_word_len",
    "digit_ratio",
    "whitespace_ratio",
    "punctuation_ratio",
    "uppercase_ratio",
    "newline_density",
    "entropy_char",
    "ascii_ratio",
]


def _safe_ratio(num: float, den: float) -> float:
    return float(num / den) if den else 0.0


def _entropy(counter: Counter[str], total: int) -> float:
    if total == 0:
        return 0.0
    value = 0.0
    for count in counter.values():
        prob = count / total
        value -= prob * math.log2(prob)
    return float(value)


def extract_set_b_features(text: str) -> dict[str, float]:
    """Extract fast single-pass features from a text chunk."""
    n_chars = len(text)
    words = WORD_RE.findall(text)
    total_word_len = sum(len(w) for w in words)
    counts = Counter(text)

    return {
        "n_chars": float(n_chars),
        "n_words": float(len(words)),
        "avg_word_len": _safe_ratio(total_word_len, len(words)),
        "digit_ratio": _safe_ratio(sum(c.isdigit() for c in text), n_chars),
        "whitespace_ratio": _safe_ratio(sum(c.isspace() for c in text), n_chars),
        "punctuation_ratio": _safe_ratio(sum(c in string.punctuation for c in text), n_chars),
        "uppercase_ratio": _safe_ratio(sum(c.isupper() for c in text), n_chars),
        "newline_density": _safe_ratio(text.count("\n"), n_chars),
        "entropy_char": _entropy(counts, n_chars),
        "ascii_ratio": _safe_ratio(sum(c in PRINTABLE_ASCII for c in text), n_chars),
    }

