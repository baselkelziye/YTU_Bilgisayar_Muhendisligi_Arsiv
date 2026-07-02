"""BWT (Burrows-Wheeler Transform) + MTF (Move-To-Front) + secondary coder.

The secondary coder can be either Order-0 Huffman or Order-0 Arithmetic,
selected via the ``secondary`` parameter.  Provides a common ``CodecResult``
interface.
"""

from __future__ import annotations

import time
from dataclasses import dataclass
from typing import ClassVar, Literal

from src.codecs import huffman_codec
from src.codecs import arithmetic_codec


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
# BWT internals
# ---------------------------------------------------------------------------


def _bwt_encode(data: bytes) -> tuple[bytes, int]:
    """Burrows-Wheeler Transform.

    Returns (transformed_data, primary_index).
    The primary index is the row index of the original string in the
    sorted rotation matrix.
    """
    if not data:
        return b"", 0

    # Build all rotations
    n = len(data)
    rotations = [(data[i:] + data[:i], i) for i in range(n)]
    rotations.sort(key=lambda x: x[0])

    transformed = bytearray()
    primary_index = 0
    for idx, (rotated, original_idx) in enumerate(rotations):
        transformed.append(rotated[-1])
        if original_idx == 0:
            primary_index = idx

    return bytes(transformed), primary_index


def _bwt_decode(transformed: bytes, primary_index: int) -> bytes:
    """Inverse Burrows-Wheeler Transform."""
    if not transformed:
        return b""

    n = len(transformed)

    # Build the "next" array using counting sort (LF mapping)
    # Count occurrences of each byte
    counts: list[int] = [0] * 256
    for byte in transformed:
        counts[byte] += 1

    # Compute cumulative counts (starting positions)
    cumul: list[int] = [0] * 256
    running = 0
    for i in range(256):
        cumul[i] = running
        running += counts[i]

    # Build occurrence tracker
    occ: list[int] = [0] * 256
    next_pos: list[int] = [0] * n
    for i, byte in enumerate(transformed):
        next_pos[i] = cumul[byte] + occ[byte]
        occ[byte] += 1

    # Reconstruct original string
    output = bytearray()
    idx = primary_index
    for _ in range(n):
        output.append(transformed[idx])
        idx = next_pos[idx]

    # Reverse because we reconstructed backwards
    output.reverse()
    return bytes(output)


# ---------------------------------------------------------------------------
# MTF internals
# ---------------------------------------------------------------------------


def _mtf_encode(data: bytes) -> bytes:
    """Move-To-Front transform.

    Returns a bytearray where each byte is the rank (0..255) of the
    original byte in the MTF list.
    """
    mtf_list = list(range(256))
    output = bytearray()
    for byte in data:
        rank = mtf_list.index(byte)
        output.append(rank)
        # Move to front
        mtf_list.pop(rank)
        mtf_list.insert(0, byte)
    return bytes(output)


def _mtf_decode(data: bytes) -> bytes:
    """Inverse Move-To-Front transform."""
    mtf_list = list(range(256))
    output = bytearray()
    for rank in data:
        byte = mtf_list[rank]
        output.append(byte)
        # Move to front
        mtf_list.pop(rank)
        mtf_list.insert(0, byte)
    return bytes(output)


# ---------------------------------------------------------------------------
# Full BWT+MTF pipeline
# ---------------------------------------------------------------------------


def _compress_bwt_mtf(
    data: bytes,
    secondary: Literal["huffman", "arithmetic"] = "huffman",
    block_size: int = 0,
) -> bytes:
    """BWT + MTF + secondary coder compress.

    Header format:
      - 4 bytes: original size (LE)
      - 4 bytes: primary index (LE)
      - 1 byte: secondary coder ID (0=huffman, 1=arithmetic)
      - secondary compressed payload
    """
    if not data:
        return b""

    original_size = len(data)

    # Optional block-splitting (if block_size > 0)
    if block_size > 0 and original_size > block_size:
        return _compress_bwt_mtf_blocked(data, secondary, block_size)

    # BWT
    bwt_data, primary_index = _bwt_encode(data)

    # MTF
    mtf_data = _mtf_encode(bwt_data)

    # Secondary coder
    if secondary == "huffman":
        sec_result = huffman_codec.compress(mtf_data, order=0)
    else:
        sec_result = arithmetic_codec.compress(mtf_data, order=0)

    if not sec_result.valid:
        raise RuntimeError(f"Secondary coder failed: {sec_result.error}")

    # Build header
    header = bytearray()
    header.extend(original_size.to_bytes(4, "little"))
    header.extend(primary_index.to_bytes(4, "little"))
    header.append(0 if secondary == "huffman" else 1)

    return bytes(header) + sec_result.compressed


def _compress_bwt_mtf_blocked(
    data: bytes,
    secondary: Literal["huffman", "arithmetic"],
    block_size: int,
) -> bytes:
    """BWT+MTF compress with block splitting for large data.

    Each block is compressed independently and concatenated.
    """
    blocks = [data[i : i + block_size] for i in range(0, len(data), block_size)]
    block_results: list[bytes] = []

    for block in blocks:
        bwt_data, primary_index = _bwt_encode(block)
        mtf_data = _mtf_encode(bwt_data)

        if secondary == "huffman":
            sec_result = huffman_codec.compress(mtf_data, order=0)
        else:
            sec_result = arithmetic_codec.compress(mtf_data, order=0)

        if not sec_result.valid:
            raise RuntimeError(f"Secondary coder failed: {sec_result.error}")

        # Per-block header: original_size(4) + primary_index(4) + sec_size(4)
        block_header = bytearray()
        block_header.extend(len(block).to_bytes(4, "little"))
        block_header.extend(primary_index.to_bytes(4, "little"))
        block_header.extend(len(sec_result.compressed).to_bytes(4, "little"))
        block_results.append(bytes(block_header) + sec_result.compressed)

    # Global header: secondary_id(1) + num_blocks(4)
    global_header = bytearray()
    global_header.append(0 if secondary == "huffman" else 1)
    global_header.extend(len(block_results).to_bytes(4, "little"))

    return bytes(global_header) + b"".join(block_results)


def _decompress_bwt_mtf(data: bytes) -> bytes:
    """BWT + MTF + secondary coder decompress."""
    if not data:
        return b""

    # Check if blocked format (first byte determines format)
    # Blocked format starts with secondary_id + num_blocks
    # Simple format starts with original_size (4 bytes)
    # We detect by checking if the first 4 bytes could be a reasonable size

    if len(data) < 9:
        return b""

    # Try simple format first
    original_size = int.from_bytes(data[0:4], "little")
    primary_index = int.from_bytes(data[4:8], "little")
    secondary_id = data[8]

    # Sanity check: primary_index should be < original_size
    if primary_index < original_size or original_size == 0:
        return _decompress_bwt_mtf_simple(data, original_size, primary_index, secondary_id)
    else:
        return _decompress_bwt_mtf_blocked(data)


def _decompress_bwt_mtf_simple(data: bytes, original_size: int, primary_index: int, secondary_id: int) -> bytes:
    """Decompress simple (non-blocked) BWT+MTF format."""
    secondary = "huffman" if secondary_id == 0 else "arithmetic"
    sec_payload = data[9:]

    if secondary == "huffman":
        sec_result = huffman_codec.decompress(sec_payload, order=0)
    else:
        sec_result = arithmetic_codec.decompress(sec_payload, order=0)

    if not sec_result.valid:
        raise RuntimeError(f"Secondary decoder failed: {sec_result.error}")

    mtf_data = sec_result.compressed
    bwt_data = _mtf_decode(mtf_data)
    original = _bwt_decode(bwt_data, primary_index)

    return original


def _decompress_bwt_mtf_blocked(data: bytes) -> bytes:
    """Decompress blocked BWT+MTF format."""
    secondary_id = data[0]
    num_blocks = int.from_bytes(data[1:5], "little")
    secondary = "huffman" if secondary_id == 0 else "arithmetic"

    offset = 5
    output = bytearray()

    for _ in range(num_blocks):
        if offset + 12 > len(data):
            break
        block_size = int.from_bytes(data[offset : offset + 4], "little")
        primary_index = int.from_bytes(data[offset + 4 : offset + 8], "little")
        sec_size = int.from_bytes(data[offset + 8 : offset + 12], "little")
        offset += 12

        sec_payload = data[offset : offset + sec_size]
        offset += sec_size

        if secondary == "huffman":
            sec_result = huffman_codec.decompress(sec_payload, order=0)
        else:
            sec_result = arithmetic_codec.decompress(sec_payload, order=0)

        if not sec_result.valid:
            raise RuntimeError(f"Secondary decoder failed: {sec_result.error}")

        mtf_data = sec_result.compressed
        bwt_data = _mtf_decode(mtf_data)
        original = _bwt_decode(bwt_data, primary_index)
        output.extend(original)

    return bytes(output)


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------


def compress(
    data: bytes,
    secondary: Literal["huffman", "arithmetic"] = "huffman",
    block_size: int = 0,
) -> CodecResult:
    """Compress *data* with BWT + MTF + secondary coder.

    Parameters
    ----------
    data : bytes
        Raw input.
    secondary : {"huffman", "arithmetic"}
        Secondary entropy coder.
    block_size : int
        If > 0, split data into blocks of this size before BWT.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()
    original_size = len(data)

    try:
        compressed = _compress_bwt_mtf(data, secondary=secondary, block_size=block_size)
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
        decompressed = _decompress_bwt_mtf(data)
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
    {"secondary": "huffman", "block_size": 0, "label": "bwt_mtf_huffman"},
    {"secondary": "arithmetic", "block_size": 0, "label": "bwt_mtf_arithmetic"},
    {"secondary": "huffman", "block_size": 10240, "label": "bwt_mtf_huffman_b10k"},
    {"secondary": "arithmetic", "block_size": 10240, "label": "bwt_mtf_arithmetic_b10k"},
]
