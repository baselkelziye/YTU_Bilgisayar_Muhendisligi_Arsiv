"""Zstandard codec following the project's CodecResult interface."""

from __future__ import annotations

import time
from dataclasses import dataclass

import zstandard as zstd


@dataclass
class CodecResult:
    compressed: bytes
    compressed_size_bits: int
    original_size_bytes: int
    elapsed_ms: float
    valid: bool = True
    error: str | None = None

    @property
    def bpb(self) -> float:
        if self.original_size_bytes == 0:
            return 0.0
        return self.compressed_size_bits / self.original_size_bytes

    @property
    def compression_ratio(self) -> float:
        if self.original_size_bytes == 0:
            return 1.0
        return self.compressed_size_bits / 8 / self.original_size_bytes


# Pre-create compressor/decompressor contexts at different levels
_COMPRESSORS: dict[int, zstd.ZstdCompressor] = {}
_DECOMPRESSOR = zstd.ZstdDecompressor()


def _get_compressor(level: int) -> zstd.ZstdCompressor:
    if level not in _COMPRESSORS:
        _COMPRESSORS[level] = zstd.ZstdCompressor(level=level)
    return _COMPRESSORS[level]


def compress(data: bytes, level: int = 3) -> CodecResult:
    """Compress data with Zstandard at the given compression level (1-22)."""
    start = time.perf_counter()
    original_size = len(data)

    try:
        cctx = _get_compressor(level)
        compressed = cctx.compress(data)
    except Exception as exc:
        return CodecResult(
            compressed=b"",
            compressed_size_bits=0,
            original_size_bytes=original_size,
            elapsed_ms=(time.perf_counter() - start) * 1000,
            valid=False,
            error=str(exc),
        )

    elapsed = (time.perf_counter() - start) * 1000
    return CodecResult(
        compressed=compressed,
        compressed_size_bits=len(compressed) * 8,
        original_size_bytes=original_size,
        elapsed_ms=elapsed,
        valid=True,
    )


def decompress(data: bytes, level: int = 3) -> CodecResult:
    """Decompress Zstandard-compressed data."""
    start = time.perf_counter()

    try:
        decompressed = _DECOMPRESSOR.decompress(data)
    except Exception as exc:
        return CodecResult(
            compressed=b"",
            compressed_size_bits=0,
            original_size_bytes=0,
            elapsed_ms=(time.perf_counter() - start) * 1000,
            valid=False,
            error=str(exc),
        )

    elapsed = (time.perf_counter() - start) * 1000
    return CodecResult(
        compressed=decompressed,
        compressed_size_bits=len(decompressed) * 8,
        original_size_bytes=len(data),
        elapsed_ms=elapsed,
        valid=True,
    )
