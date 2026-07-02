"""Order-0 and Order-1 Huffman encoder/decoder.

Provides a common ``CodecResult`` interface so the grid-search orchestrator
can treat every codec uniformly.
"""

from __future__ import annotations

import heapq
import math
import time
from collections import Counter, defaultdict
from dataclasses import dataclass
from typing import ClassVar


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
        """Bits per byte."""
        if self.original_size_bytes == 0:
            return 0.0
        return self.compressed_size_bits / self.original_size_bytes

    @property
    def compression_ratio(self) -> float:
        """Compressed size / original size (lower is better)."""
        if self.original_size_bytes == 0:
            return 1.0
        return self.compressed_size_bits / 8 / self.original_size_bytes

    @property
    def ms_per_kb(self) -> float:
        """Milliseconds per kilobyte of original data."""
        if self.original_size_bytes == 0:
            return 0.0
        return self.elapsed_ms / (self.original_size_bytes / 1024)


# ---------------------------------------------------------------------------
# Internal helpers
# ---------------------------------------------------------------------------


def _build_freq_table(data: bytes) -> list[int]:
    """Return a 256-element list of symbol frequencies."""
    freqs: list[int] = [0] * 256
    for byte in data:
        freqs[byte] += 1
    return freqs


def _build_context_freq_tables(data: bytes) -> list[list[int]]:
    """Return 256 context-frequency tables for Order-1 modelling.

    ``ctx_freq[prev_byte][next_byte]`` = count.
    """
    ctx_freq: list[list[int]] = [[0] * 256 for _ in range(256)]
    prev = 0  # virtual EOF / start-of-stream context
    for byte in data:
        ctx_freq[prev][byte] += 1
        prev = byte
    return ctx_freq


# ---------------------------------------------------------------------------
# Huffman tree
# ---------------------------------------------------------------------------


class _HuffmanNode:
    """Node in a Huffman tree (used only during tree construction)."""

    __slots__ = ("freq", "symbol", "left", "right")

    def __init__(
        self,
        freq: int,
        symbol: int | None = None,
        left: _HuffmanNode | None = None,
        right: _HuffmanNode | None = None,
    ):
        self.freq = freq
        self.symbol = symbol
        self.left = left
        self.right = right

    def __lt__(self, other: _HuffmanNode) -> bool:
        return self.freq < other.freq


def _build_tree(freqs: list[int]) -> _HuffmanNode | None:
    """Build a Huffman tree from a 256-element frequency list."""
    heap: list[_HuffmanNode] = []
    for sym, f in enumerate(freqs):
        if f > 0:
            heapq.heappush(heap, _HuffmanNode(f, symbol=sym))

    if not heap:
        return None
    if len(heap) == 1:
        # Single symbol: create a dummy parent so codes work
        node = heapq.heappop(heap)
        dummy = _HuffmanNode(0)
        return _HuffmanNode(node.freq, left=node, right=dummy)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        heapq.heappush(heap, _HuffmanNode(left.freq + right.freq, left=left, right=right))

    return heap[0]


def _build_code_table(tree: _HuffmanNode | None) -> list[str]:
    """Return a 256-element list of canonical Huffman code strings."""
    codes: list[str] = [""] * 256

    def _walk(node: _HuffmanNode | None, prefix: str) -> None:
        if node is None:
            return
        if node.symbol is not None:
            codes[node.symbol] = prefix or "0"  # single-symbol case
            return
        _walk(node.left, prefix + "0")
        _walk(node.right, prefix + "1")

    _walk(tree, "")
    return codes


def _canonical_sort(freqs: list[int]) -> list[tuple[int, int]]:
    """Return list of (symbol, freq) sorted by freq asc, symbol asc."""
    return sorted([(s, f) for s, f in enumerate(freqs) if f > 0], key=lambda x: (x[1], x[0]))


def _build_canonical_codes(freqs: list[int]) -> list[str]:
    """Build canonical Huffman codes (length-limited compatible)."""
    tree = _build_tree(freqs)
    if tree is None:
        return [""] * 256
    raw_codes = _build_code_table(tree)
    # Compute code lengths
    lengths: list[int] = [0] * 256
    for sym, code in enumerate(raw_codes):
        if code:
            lengths[sym] = len(code)

    # Sort symbols by (length, symbol)
    sorted_syms = sorted([s for s in range(256) if lengths[s] > 0], key=lambda s: (lengths[s], s))

    # Assign canonical codes
    code = 0
    prev_len = 0
    canonical: list[str] = [""] * 256
    for sym in sorted_syms:
        while prev_len < lengths[sym]:
            code <<= 1
            prev_len += 1
        canonical[sym] = f"{code:0{lengths[sym]}b}"
        code += 1

    return canonical


def _serialise_code_table(codes: list[str]) -> bytes:
    """Serialise canonical code lengths for storage in the compressed header.

    Format: for each symbol with non-zero frequency, emit (byte, bit_length).
    Terminated with a zero-length marker.
    """
    payload = bytearray()
    for sym in range(256):
        length = len(codes[sym])
        if length > 0:
            payload.append(sym)
            payload.append(length)
    payload.append(0)  # terminator
    payload.append(0)
    return bytes(payload)


def _deserialise_code_table(data: bytes, offset: int) -> tuple[list[str], int]:
    """Reconstruct canonical code table from serialised header.

    Returns (codes, new_offset).
    """
    sym_lengths: list[tuple[int, int]] = []
    pos = offset
    while pos + 1 < len(data):
        sym = data[pos]
        length = data[pos + 1]
        if length == 0:
            pos += 2
            break
        sym_lengths.append((sym, length))
        pos += 2

    # Rebuild canonical codes
    sym_lengths.sort(key=lambda x: (x[1], x[0]))
    codes: list[str] = [""] * 256
    code = 0
    prev_len = 0
    for sym, length in sym_lengths:
        while prev_len < length:
            code <<= 1
            prev_len += 1
        codes[sym] = f"{code:0{length}b}"
        code += 1

    return codes, pos


# ---------------------------------------------------------------------------
# Order-0 Huffman
# ---------------------------------------------------------------------------


def _compress_order0(data: bytes) -> bytes:
    """Order-0 Huffman compress. Returns header + bitstream."""
    if not data:
        return b""

    freqs = _build_freq_table(data)
    codes = _build_canonical_codes(freqs)
    header = _serialise_code_table(codes)

    # Build bitstream
    bit_buffer: list[str] = []
    for byte in data:
        bit_buffer.append(codes[byte])

    bitstream = "".join(bit_buffer)
    # Pad to byte boundary
    padding = (8 - len(bitstream) % 8) % 8
    bitstream += "0" * padding

    # Convert to bytes
    stream_bytes = bytearray()
    for i in range(0, len(bitstream), 8):
        stream_bytes.append(int(bitstream[i : i + 8], 2))

    # Store padding count in the last byte of header (before terminator)
    # We'll use a simple scheme: header already has terminator (0,0),
    # then we write padding byte, then stream.
    result = bytearray(header)
    result.append(padding)
    result.extend(stream_bytes)
    return bytes(result)


def _decompress_order0(data: bytes) -> bytes:
    """Order-0 Huffman decompress."""
    if not data:
        return b""

    codes, offset = _deserialise_code_table(data, 0)
    if offset >= len(data):
        return b""

    padding = data[offset]
    offset += 1
    bitstream = "".join(f"{byte:08b}" for byte in data[offset:])

    if padding:
        bitstream = bitstream[:-padding] if padding < len(bitstream) else ""

    # Build reverse lookup: code -> symbol
    reverse: dict[str, int] = {}
    for sym, code in enumerate(codes):
        if code:
            reverse[code] = sym

    # Decode
    output = bytearray()
    buffer = ""
    for bit in bitstream:
        buffer += bit
        if buffer in reverse:
            output.append(reverse[buffer])
            buffer = ""

    return bytes(output)


# ---------------------------------------------------------------------------
# Order-1 Huffman (context-based)
# ---------------------------------------------------------------------------


def _compress_order1(data: bytes) -> bytes:
    """Order-1 Huffman compress using 256 independent context tables.

    Header format:
      - 4 bytes: original size (little-endian)
      - For each context (0..255) that has any symbols:
          * context byte
          * serialised code table for that context (with its own terminator)
      - Global terminator: 0xFF 0x00 0x00  (context=255 with zero-length table)
      - padding byte
      - bitstream
    """
    if not data:
        return b""

    ctx_freq = _build_context_freq_tables(data)
    ctx_codes: list[list[str]] = [_build_canonical_codes(freqs) for freqs in ctx_freq]

    # Serialise header
    header = bytearray()
    header.extend(len(data).to_bytes(4, "little"))
    for ctx in range(256):
        if sum(ctx_freq[ctx]) > 0:
            header.append(ctx)
            header.extend(_serialise_code_table(ctx_codes[ctx]))
    # Global terminator: context 255 with zero-length table marker
    header.append(0xFF)
    header.append(0)
    header.append(0)

    # Build bitstream
    bit_buffer: list[str] = []
    prev = 0
    for byte in data:
        bit_buffer.append(ctx_codes[prev][byte])
        prev = byte

    bitstream = "".join(bit_buffer)
    padding = (8 - len(bitstream) % 8) % 8
    bitstream += "0" * padding

    stream_bytes = bytearray()
    for i in range(0, len(bitstream), 8):
        stream_bytes.append(int(bitstream[i : i + 8], 2))

    result = bytearray(header)
    result.append(padding)
    result.extend(stream_bytes)
    return bytes(result)


def _decompress_order1(data: bytes) -> bytes:
    """Order-1 Huffman decompress."""
    if not data:
        return b""

    if len(data) < 4:
        return b""

    original_size = int.from_bytes(data[0:4], "little")
    pos = 4

    # Read header: context tables
    ctx_codes: list[list[str]] = [[""] * 256 for _ in range(256)]
    while pos < len(data):
        ctx = data[pos]
        if ctx == 0xFF and pos + 2 < len(data) and data[pos + 1] == 0 and data[pos + 2] == 0:
            pos += 3
            break
        codes, pos = _deserialise_code_table(data, pos + 1)
        ctx_codes[ctx] = codes

    if pos >= len(data):
        return b""

    padding = data[pos]
    pos += 1
    bitstream = "".join(f"{byte:08b}" for byte in data[pos:])

    if padding:
        bitstream = bitstream[:-padding] if padding < len(bitstream) else ""

    # Build reverse lookups
    reverse: list[dict[str, int]] = [{} for _ in range(256)]
    for ctx in range(256):
        for sym, code in enumerate(ctx_codes[ctx]):
            if code:
                reverse[ctx][code] = sym

    # Decode up to original_size symbols
    output = bytearray()
    buffer = ""
    prev = 0
    for bit in bitstream:
        if len(output) >= original_size:
            break
        buffer += bit
        if buffer in reverse[prev]:
            sym = reverse[prev][buffer]
            output.append(sym)
            prev = sym
            buffer = ""

    return bytes(output)


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------


def compress(data: bytes, order: int = 0) -> CodecResult:
    """Compress *data* with Order-*order* Huffman coding.

    Parameters
    ----------
    data : bytes
        Raw input.
    order : {0, 1}
        Model order.  Order-1 uses 256 independent context tables.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()
    original_size = len(data)

    try:
        if order == 0:
            compressed = _compress_order0(data)
        elif order == 1:
            compressed = _compress_order1(data)
        else:
            return CodecResult(
                compressed=b"",
                compressed_size_bits=0,
                original_size_bytes=original_size,
                elapsed_ms=0.0,
                valid=False,
                error=f"Unsupported order: {order}",
            )
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


def decompress(data: bytes, order: int = 0) -> CodecResult:
    """Decompress *data* previously compressed with :func:`compress`.

    Parameters
    ----------
    data : bytes
        Compressed payload.
    order : {0, 1}
        Must match the order used during compression.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()

    try:
        if order == 0:
            decompressed = _decompress_order0(data)
        elif order == 1:
            decompressed = _decompress_order1(data)
        else:
            return CodecResult(
                compressed=b"",
                compressed_size_bits=0,
                original_size_bytes=0,
                elapsed_ms=0.0,
                valid=False,
                error=f"Unsupported order: {order}",
            )
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
# Parameter space definition (consumed by parameter_spaces.py)
# ---------------------------------------------------------------------------

PARAM_SPACE: list[dict] = [
    {"order": 0, "label": "huffman_order0"},
    {"order": 1, "label": "huffman_order1"},
]
