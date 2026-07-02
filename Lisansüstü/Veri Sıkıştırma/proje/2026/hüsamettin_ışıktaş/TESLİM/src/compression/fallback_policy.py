"""Fallback policies for low-confidence and edge-case blocks.

When profile classifier confidence is below a threshold, or when
compression doesn't reduce size, these policies define safe defaults.
"""

from __future__ import annotations

CONFIDENCE_THRESHOLD = 0.6


def should_use_prediction(confidence: float) -> bool:
    """Return False if confidence is below the usable threshold."""
    return confidence >= CONFIDENCE_THRESHOLD


def get_fallback_profile() -> str:
    """Default profile when classifier is uncertain."""
    # profile_0 is usually the largest cluster (normal English text)
    return "profile_0"


def get_raw_store_threshold() -> float:
    """If compression ratio > this, store raw instead.

    1.0 means compressed data is larger than original — store raw.
    """
    return 1.0


def get_max_chunk_size_bytes() -> int:
    """Maximum chunk size supported by the 4-byte header (64 KiB)."""
    return 0x10000 - 1


def is_block_size_valid(compressed_size: int, uncompressed_size: int) -> bool:
    """Check if compressed data fits within header limits.

    If compressed_size > 65535 bytes, we cannot encode it in the header.
    In that case, fall back to storing raw.
    """
    return compressed_size <= 0xFFFF
