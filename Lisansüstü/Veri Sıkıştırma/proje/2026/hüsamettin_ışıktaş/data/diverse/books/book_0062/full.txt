"""Set A feature extractor for compression-aware analysis."""

from __future__ import annotations

import bz2
import lzma
import math
import re
import string
import zlib
from collections import Counter
from statistics import mean, pstdev


WORD_RE = re.compile(r"\b\w+\b", re.UNICODE)
VOWELS = set("aeiouAEIOU")
PRINTABLE_ASCII = set(chr(i) for i in range(32, 127)) | {"\n", "\t", "\r"}

FEATURE_SET_A_COLUMNS = [
    "n_chars",
    "n_lines",
    "n_words",
    "avg_word_len",
    "std_word_len",
    "unique_char_ratio",
    "unique_word_ratio",
    "digit_ratio",
    "whitespace_ratio",
    "punctuation_ratio",
    "uppercase_ratio",
    "vowel_ratio",
    "entropy_char",
    "bigram_repetition_ratio",
    "trigram_repetition_ratio",
    "longest_repeat_run",
    "newline_density",
    "mean_line_length",
    "std_line_length",
    "ascii_ratio",
    "zlib_compression_ratio",
    "bz2_compression_ratio",
    "lzma_compression_ratio",
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


def _ngram_repetition_ratio(text: str, n: int) -> float:
    if len(text) < n:
        return 0.0
    ngrams = [text[i : i + n] for i in range(len(text) - n + 1)]
    total = len(ngrams)
    counts = Counter(ngrams)
    repeated = sum(1 for v in counts.values() if v > 1)
    return _safe_ratio(repeated, total)


def _longest_repeat_run(text: str) -> int:
    if not text:
        return 0
    best = 1
    current = 1
    for idx in range(1, len(text)):
        if text[idx] == text[idx - 1]:
            current += 1
            best = max(best, current)
        else:
            current = 1
    return best


def extract_set_a_features(text: str) -> dict[str, float]:
    """Extract 23 compression-aware features from a text chunk."""
    n_chars = len(text)
    words = WORD_RE.findall(text)
    word_lengths = [len(w) for w in words]
    lines = text.splitlines() or [text]
    line_lengths = [len(line) for line in lines]

    char_counter = Counter(text)
    word_counter = Counter(words)

    n_digits = sum(ch.isdigit() for ch in text)
    n_space = sum(ch.isspace() for ch in text)
    n_punct = sum(ch in string.punctuation for ch in text)
    n_upper = sum(ch.isupper() for ch in text)
    n_vowels = sum(ch in VOWELS for ch in text)
    n_ascii = sum(ch in PRINTABLE_ASCII for ch in text)

    payload = text.encode("utf-8", errors="ignore")
    raw_size = len(payload)
    zlib_size = len(zlib.compress(payload)) if raw_size else 0
    bz2_size = len(bz2.compress(payload)) if raw_size else 0
    lzma_size = len(lzma.compress(payload)) if raw_size else 0

    return {
        "n_chars": float(n_chars),
        "n_lines": float(len(lines)),
        "n_words": float(len(words)),
        "avg_word_len": float(mean(word_lengths)) if word_lengths else 0.0,
        "std_word_len": float(pstdev(word_lengths)) if len(word_lengths) > 1 else 0.0,
        "unique_char_ratio": _safe_ratio(len(char_counter), n_chars),
        "unique_word_ratio": _safe_ratio(len(word_counter), len(words)),
        "digit_ratio": _safe_ratio(n_digits, n_chars),
        "whitespace_ratio": _safe_ratio(n_space, n_chars),
        "punctuation_ratio": _safe_ratio(n_punct, n_chars),
        "uppercase_ratio": _safe_ratio(n_upper, n_chars),
        "vowel_ratio": _safe_ratio(n_vowels, n_chars),
        "entropy_char": _entropy(char_counter, n_chars),
        "bigram_repetition_ratio": _ngram_repetition_ratio(text, n=2),
        "trigram_repetition_ratio": _ngram_repetition_ratio(text, n=3),
        "longest_repeat_run": float(_longest_repeat_run(text)),
        "newline_density": _safe_ratio(text.count("\n"), n_chars),
        "mean_line_length": float(mean(line_lengths)) if line_lengths else 0.0,
        "std_line_length": float(pstdev(line_lengths)) if len(line_lengths) > 1 else 0.0,
        "ascii_ratio": _safe_ratio(n_ascii, n_chars),
        "zlib_compression_ratio": _safe_ratio(zlib_size, raw_size),
        "bz2_compression_ratio": _safe_ratio(bz2_size, raw_size),
        "lzma_compression_ratio": _safe_ratio(lzma_size, raw_size),
    }

