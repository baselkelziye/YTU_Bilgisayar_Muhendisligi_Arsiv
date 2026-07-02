"""LZW (Lempel-Ziv-Welch) encoder/decoder with variable dictionary size.

Provides a common ``CodecResult`` interface for the grid-search orchestrator.
"""

from __future__ import annotations

import time
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
# LZW internals
# ---------------------------------------------------------------------------

_MIN_DICT_BITS = 9   # 512 entries (256 singles + 256 initial phrases)
_MAX_DICT_BITS = 16  # 65536 entries


def _compress_lzw(data: bytes, max_bits: int = 12) -> bytes:
    """LZW compress with variable-width output codes.

    Parameters
    ----------
    data : bytes
        Raw input.
    max_bits : int
        Maximum code width (9..16).  Dictionary resets when full.

    Returns
    -------
    bytes
        Header-less compressed payload (code stream only).
    """
    if not data:
        return b""

    # Use standard LZW special codes independent of max_bits.
    # Dictionary starts with 0..255 single bytes; then:
    #   clear_code = 256, eoi_code = 257, next_code starts at 258.
    clear_code = 256
    eoi_code = 257

    # Initial dictionary: all single bytes
    dictionary: dict[bytes, int] = {bytes([i]): i for i in range(256)}
    next_code = 258

    output_codes: list[int] = []
    current = bytes([data[0]])

    for byte in data[1:]:
        extended = current + bytes([byte])
        if extended in dictionary:
            current = extended
        else:
            output_codes.append(dictionary[current])
            if next_code < (1 << max_bits):
                dictionary[extended] = next_code
                next_code += 1
            else:
                # Dictionary full: emit clear code and reset
                output_codes.append(clear_code)
                dictionary = {bytes([i]): i for i in range(256)}
                next_code = 258
            current = bytes([byte])

    # Flush last entry
    if current:
        output_codes.append(dictionary[current])

    output_codes.append(eoi_code)

    # Pack codes into bitstream using variable width
    return _pack_codes(output_codes, max_bits)


def _pack_codes(codes: list[int], max_bits: int) -> bytes:
    """Pack a list of integer codes into a variable-width bitstream.

    Code width starts at 9 bits and grows as needed up to *max_bits*.
    """
    if not codes:
        return b""

    bit_buffer: list[str] = []
    width = 9  # start with 9 bits
    next_code = 258
    clear_code = 256

    for code in codes:
        bit_buffer.append(f"{code:0{width}b}")

        # After clear code, reset width to 9
        if code == clear_code:
            width = 9
            next_code = 258
            continue

        # EOI doesn't grow the dictionary
        if code == 257:
            continue

        # Each normal code adds one dictionary entry during decode.
        next_code += 1
        if next_code >= (1 << width) and width < max_bits:
            width += 1

    bitstream = "".join(bit_buffer)
    padding = (8 - len(bitstream) % 8) % 8
    bitstream += "0" * padding

    result = bytearray()
    for i in range(0, len(bitstream), 8):
        result.append(int(bitstream[i : i + 8], 2))

    return bytes(result)


def _decompress_lzw(data: bytes, max_bits: int = 12) -> bytes:
    """LZW decompress."""
    if not data:
        return b""

    clear_code = 256
    eoi_code = 257

    # Unpack codes from bitstream
    codes = _unpack_codes(data, max_bits)

    if not codes:
        return b""

    # Initial dictionary
    dictionary: dict[int, bytes] = {i: bytes([i]) for i in range(256)}
    next_code = 258

    output = bytearray()
    prev_entry = dictionary.get(codes[0], b"")
    output.extend(prev_entry)
    after_clear = False

    for code in codes[1:]:
        if code == clear_code:
            dictionary = {i: bytes([i]) for i in range(256)}
            next_code = 258
            prev_entry = b""
            after_clear = True
            continue
        if code == eoi_code:
            break

        if after_clear:
            # After a CLEAR, the next code is a raw dictionary entry and does
            # not create a new phrase based on the previous stream state.
            entry = dictionary.get(code, b"")
            output.extend(entry)
            prev_entry = entry
            after_clear = False
            continue

        if code in dictionary:
            entry = dictionary[code]
        elif code == next_code:
            entry = prev_entry + bytes([prev_entry[0]])
        else:
            # Invalid code — stop
            break

        output.extend(entry)

        # Add new phrase to dictionary
        if next_code < (1 << max_bits):
            dictionary[next_code] = prev_entry + bytes([entry[0]])
            next_code += 1

        prev_entry = entry

    return bytes(output)


def _unpack_codes(data: bytes, max_bits: int) -> list[int]:
    """Unpack variable-width codes from a bitstream."""
    if not data:
        return []

    clear_code = 256
    eoi_code = 257

    bitstream = "".join(f"{byte:08b}" for byte in data)
    codes: list[int] = []
    pos = 0
    width = 9
    next_code = 258  # tracks the next dictionary entry to be assigned

    while pos + width <= len(bitstream):
        code = int(bitstream[pos : pos + width], 2)
        pos += width

        if code == eoi_code:
            codes.append(code)
            break

        codes.append(code)

        if code == clear_code:
            width = 9
            next_code = 258
        else:
            # Each normal code causes a new dictionary entry during decode
            next_code += 1
            if next_code >= (1 << width) and width < max_bits:
                width += 1

    return codes


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------


def compress(data: bytes, max_bits: int = 12) -> CodecResult:
    """Compress *data* with LZW coding.

    Parameters
    ----------
    data : bytes
        Raw input.
    max_bits : int
        Maximum code width (9..16).  Default 12.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()
    original_size = len(data)

    try:
        compressed = _compress_lzw(data, max_bits=max_bits)
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


def decompress(data: bytes, max_bits: int = 12) -> CodecResult:
    """Decompress *data* previously compressed with :func:`compress`.

    Parameters
    ----------
    data : bytes
        Compressed payload.
    max_bits : int
        Must match the value used during compression.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()

    try:
        decompressed = _decompress_lzw(data, max_bits=max_bits)
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
    {"max_bits": 9, "label": "lzw_bits9"},
    {"max_bits": 10, "label": "lzw_bits10"},
    {"max_bits": 11, "label": "lzw_bits11"},
    {"max_bits": 12, "label": "lzw_bits12"},
    {"max_bits": 13, "label": "lzw_bits13"},
    {"max_bits": 14, "label": "lzw_bits14"},
    {"max_bits": 15, "label": "lzw_bits15"},
    {"max_bits": 16, "label": "lzw_bits16"},
]
