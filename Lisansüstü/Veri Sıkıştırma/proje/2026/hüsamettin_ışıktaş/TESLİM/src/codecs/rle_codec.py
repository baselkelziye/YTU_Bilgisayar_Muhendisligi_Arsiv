"""RLE (Run-Length Encoding) + Huffman hybrid codec.

Strategy: apply RLE to runs of identical bytes (≥4 repeats), then Huffman
encode the resulting symbol stream.  Provides a common ``CodecResult``
interface.
"""

from __future__ import annotations

import time
from dataclasses import dataclass
from typing import ClassVar

from src.codecs import huffman_codec


@dataclass
class CodecResult:
    """Standardised return type for all Phase 2 codecs."""

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

    @property
    def ms_per_kb(self) -> float:
        if self.original_size_bytes == 0:
            return 0.0
        return self.elapsed_ms / (self.original_size_bytes / 1024)


# ---------------------------------------------------------------------------
# RLE internals
# ---------------------------------------------------------------------------

# RLE marker byte: 0x00.
#
# To avoid ambiguous sequences (where literal bytes could be mis-parsed as a run),
# we use a marker-first encoding:
# - Literal non-zero byte: [b]
# - Literal zero byte: [0x00, 0x00]
# - Run (len >= min_run): [0x00, run_length, run_byte]
#   where run_length is 1..255. Long runs are split.

RLE_MARKER = 0x00
RLE_MIN_RUN = 4


def _rle_encode(data: bytes, min_run: int = RLE_MIN_RUN) -> bytes:
    """Apply RLE transform to *data*.

    Returns a byte sequence where runs of identical bytes (≥ *min_run*)
    are replaced with ``[byte, marker, length]``.
    """
    if not data:
        return b""

    output = bytearray()
    i = 0
    n = len(data)

    while i < n:
        # Count run of identical bytes
        run_start = i
        while i < n and data[i] == data[run_start]:
            i += 1
        run_length = i - run_start
        run_byte = data[run_start]

        if run_length >= min_run:
            # Encode as marker-first run: [0, len, byte]
            remaining = run_length
            while remaining > 0:
                chunk = min(remaining, 255)
                output.append(RLE_MARKER)
                output.append(chunk)
                output.append(run_byte)
                remaining -= chunk
        else:
            # Literals: non-zero as-is; zero as [0,0]
            for j in range(run_start, i):
                b = data[j]
                if b == RLE_MARKER:
                    output.append(RLE_MARKER)
                    output.append(0)
                else:
                    output.append(b)

    return bytes(output)


def _rle_decode(data: bytes, min_run: int = RLE_MIN_RUN) -> bytes:
    """Reverse RLE transform."""
    if not data:
        return b""

    output = bytearray()
    i = 0
    n = len(data)

    while i < n:
        b = data[i]
        if b != RLE_MARKER:
            output.append(b)
            i += 1
            continue

        # Marker sequence
        if i + 1 >= n:
            break
        run_length = data[i + 1]
        if run_length == 0:
            # Escaped literal 0x00
            output.append(RLE_MARKER)
            i += 2
            continue

        if i + 2 >= n:
            break
        run_byte = data[i + 2]
        output.extend([run_byte] * run_length)
        i += 3

    return bytes(output)


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------


def compress(data: bytes, min_run: int = RLE_MIN_RUN) -> CodecResult:
    """Compress *data* with RLE + Huffman hybrid.

    Parameters
    ----------
    data : bytes
        Raw input.
    min_run : int
        Minimum run length to trigger RLE encoding (default 4).

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()
    original_size = len(data)

    try:
        # Apply RLE
        rle_data = _rle_encode(data, min_run=min_run)

        # Huffman encode the RLE output
        huff_result = huffman_codec.compress(rle_data, order=0)

        if not huff_result.valid:
            return CodecResult(
                compressed=b"",
                compressed_size_bits=0,
                original_size_bytes=original_size,
                elapsed_ms=(time.perf_counter() - start) * 1000,
                valid=False,
                error=f"Huffman failed: {huff_result.error}",
            )

        # Build header: min_run(1) + original_size(4) + huffman payload
        header = bytearray()
        header.append(min_run)
        header.extend(original_size.to_bytes(4, "little"))

        compressed = bytes(header) + huff_result.compressed

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


def decompress(data: bytes) -> CodecResult:
    """Decompress *data* previously compressed with :func:`compress`.

    Parameters
    ----------
    data : bytes
        Compressed payload.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()

    try:
        if len(data) < 5:
            return CodecResult(
                compressed=b"",
                compressed_size_bits=0,
                original_size_bytes=0,
                elapsed_ms=(time.perf_counter() - start) * 1000,
                valid=False,
                error="Data too short",
            )

        min_run = data[0]
        original_size = int.from_bytes(data[1:5], "little")

        # Huffman decode
        huff_result = huffman_codec.decompress(data[5:], order=0)

        if not huff_result.valid:
            return CodecResult(
                compressed=b"",
                compressed_size_bits=0,
                original_size_bytes=0,
                elapsed_ms=(time.perf_counter() - start) * 1000,
                valid=False,
                error=f"Huffman decode failed: {huff_result.error}",
            )

        # Reverse RLE
        decompressed = _rle_decode(huff_result.compressed, min_run=min_run)

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
        original_size_bytes=len(decompressed),
        elapsed_ms=elapsed,
        valid=True,
    )


# ---------------------------------------------------------------------------
# Parameter space
# ---------------------------------------------------------------------------

PARAM_SPACE: list[dict] = [
    {"min_run": 3, "label": "rle_huffman_run3"},
    {"min_run": 4, "label": "rle_huffman_run4"},
    {"min_run": 5, "label": "rle_huffman_run5"},
    {"min_run": 8, "label": "rle_huffman_run8"},
]
