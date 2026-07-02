"""Order-0, Order-1, and Order-2 Arithmetic encoder/decoder.

Implements integer-based arithmetic coding using a cumulative frequency
table with adaptive scaling.  Provides a common ``CodecResult`` interface.
"""

from __future__ import annotations

import time
from collections import defaultdict
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
# Arithmetic coding internals (integer implementation)
# ---------------------------------------------------------------------------

# Precision: 32-bit integer arithmetic
PRECISION = 32
HALF = 1 << (PRECISION - 1)
QUARTER = 1 << (PRECISION - 2)
THREE_QUARTERS = 3 * QUARTER
MAX_FREQ = (1 << (PRECISION - 4)) - 1  # max cumulative frequency
EOF_SYMBOL = 256  # special end-of-stream marker
TOTAL_SYMBOLS = 257  # 256 bytes + EOF


class _FreqTable:
    """Cumulative frequency table for arithmetic coding."""

    __slots__ = ("freq", "cumul", "total")

    def __init__(self, freqs: list[int] | None = None):
        self.freq: list[int] = [1] * TOTAL_SYMBOLS  # initial 1 to avoid zero
        self.cumul: list[int] = [0] * (TOTAL_SYMBOLS + 1)
        self.total: int = TOTAL_SYMBOLS
        if freqs is not None:
            for sym, f in enumerate(freqs):
                if sym < 256:
                    self.freq[sym] = f + 1  # +1 for the initial 1
            # EOF symbol gets freq 1
        self._rebuild_cumul()

    def _rebuild_cumul(self) -> None:
        running = 0
        for i in range(TOTAL_SYMBOLS):
            self.cumul[i] = running
            running += self.freq[i]
        self.cumul[TOTAL_SYMBOLS] = running
        self.total = running

    def update(self, sym: int) -> None:
        """Increment frequency for *sym* and rescale if needed."""
        if self.freq[sym] < MAX_FREQ:
            self.freq[sym] += 1
            self.total += 1
            if self.total >= MAX_FREQ:
                self._rescale()

    def _rescale(self) -> None:
        """Halve all frequencies to keep total within bounds."""
        for i in range(TOTAL_SYMBOLS):
            self.freq[i] = max(1, self.freq[i] // 2)
        self._rebuild_cumul()


def _compress_arithmetic(data: bytes, order: int = 0) -> bytes:
    """Arithmetic compress with given model order.

    Header format:
      - 1 byte: order (0, 1, or 2)
      - 4 bytes: original size (little-endian)
      - For order 0: serialised frequency table (256 * 2 bytes LE)
      - For order 1/2: context tables
      - bitstream
    """
    if not data:
        return b""

    original_size = len(data)

    if order == 0:
        return _compress_order0(data, original_size)
    elif order == 1:
        return _compress_order1(data, original_size)
    elif order == 2:
        return _compress_order2(data, original_size)
    else:
        raise ValueError(f"Unsupported arithmetic order: {order}")


def _serialise_freqs(freqs: list[int]) -> bytes:
    """Serialise 256 frequency values as 2-byte LE each."""
    result = bytearray()
    for f in freqs[:256]:
        result.append(f & 0xFF)
        result.append((f >> 8) & 0xFF)
    return bytes(result)


def _deserialise_freqs(data: bytes, offset: int) -> tuple[list[int], int]:
    """Deserialise 256 frequency values from 2-byte LE each."""
    freqs = [1] * TOTAL_SYMBOLS
    for i in range(256):
        if offset + 1 < len(data):
            freqs[i] = data[offset] | (data[offset + 1] << 8)
            offset += 2
    return freqs, offset


def _encode_bitstream(data: bytes, ft: _FreqTable) -> bytes:
    """Encode *data* bytes + EOF using arithmetic coding."""
    low = 0
    high = FULL = (1 << PRECISION) - 1
    underflow = 0
    output: list[int] = []

    def _emit_bit(bit: int) -> None:
        output.append(bit)

    def _flush_underflow(bit: int) -> None:
        """Emit *bit* followed by *underflow* opposite bits, then reset."""
        nonlocal underflow
        _emit_bit(bit)
        for _ in range(underflow):
            _emit_bit(1 - bit)
        underflow = 0

    for byte in data:
        sym = byte
        range_size = high - low + 1
        high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
        low = low + (range_size * ft.cumul[sym]) // ft.total

        while True:
            if high < HALF:
                _flush_underflow(0)
            elif low >= HALF:
                _flush_underflow(1)
                low -= HALF
                high -= HALF
            elif low >= QUARTER and high < THREE_QUARTERS:
                underflow += 1
                low -= QUARTER
                high -= QUARTER
            else:
                break
            low <<= 1
            high = (high << 1) | 1

        ft.update(sym)

    # Encode EOF symbol
    sym = EOF_SYMBOL
    range_size = high - low + 1
    high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
    low = low + (range_size * ft.cumul[sym]) // ft.total

    while True:
        if high < HALF:
            _flush_underflow(0)
        elif low >= HALF:
            _flush_underflow(1)
            low -= HALF
            high -= HALF
        elif low >= QUARTER and high < THREE_QUARTERS:
            underflow += 1
            low -= QUARTER
            high -= QUARTER
        else:
            break
        low <<= 1
        high = (high << 1) | 1

    # Final bits
    underflow += 1
    if low < QUARTER:
        _flush_underflow(0)
    else:
        _flush_underflow(1)

    # Pack bits to bytes
    bitstream = "".join(str(b) for b in output)
    padding = (8 - len(bitstream) % 8) % 8
    bitstream += "0" * padding

    result = bytearray()
    for i in range(0, len(bitstream), 8):
        result.append(int(bitstream[i : i + 8], 2))
    return bytes(result)


def _decode_bitstream(compressed: bytes, ft: _FreqTable, num_symbols: int) -> bytes:
    """Decode *num_symbols* bytes from arithmetic-coded *compressed*."""
    # Read bits
    bitstream = "".join(f"{byte:08b}" for byte in compressed)
    pos = 0

    def _read_bit() -> int:
        nonlocal pos
        if pos >= len(bitstream):
            return 0
        bit = 1 if bitstream[pos] == "1" else 0
        pos += 1
        return bit

    low = 0
    high = FULL = (1 << PRECISION) - 1
    value = 0
    for _ in range(PRECISION):
        value = (value << 1) | _read_bit()

    output = bytearray()
    decoded = 0

    while decoded < num_symbols:
        range_size = high - low + 1
        cum = ((value - low + 1) * ft.total - 1) // range_size

        # Find symbol
        sym = 0
        while ft.cumul[sym + 1] <= cum:
            sym += 1

        if sym == EOF_SYMBOL:
            break

        output.append(sym)
        decoded += 1

        high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
        low = low + (range_size * ft.cumul[sym]) // ft.total

        while True:
            if high < HALF:
                pass
            elif low >= HALF:
                value -= HALF
                low -= HALF
                high -= HALF
            elif low >= QUARTER and high < THREE_QUARTERS:
                value -= QUARTER
                low -= QUARTER
                high -= QUARTER
            else:
                break
            low <<= 1
            high = (high << 1) | 1
            value = (value << 1) | _read_bit()

        ft.update(sym)

    return bytes(output)


def _compress_order0(data: bytes, original_size: int) -> bytes:
    """Order-0 arithmetic compress."""
    # Build initial frequency table from data
    freqs = [1] * TOTAL_SYMBOLS
    for byte in data:
        freqs[byte] += 1
    # Cap at MAX_FREQ
    for i in range(256):
        freqs[i] = min(freqs[i], MAX_FREQ)

    ft = _FreqTable(freqs)
    encoded = _encode_bitstream(data, ft)

    # Build header: order(1) + size(4) + freqs(512)
    header = bytearray()
    header.append(0)  # order
    header.extend(original_size.to_bytes(4, "little"))
    header.extend(_serialise_freqs(freqs))

    return bytes(header) + encoded


def _decompress_order0(data: bytes) -> bytes:
    """Order-0 arithmetic decompress."""
    if len(data) < 7:
        return b""

    order = data[0]
    original_size = int.from_bytes(data[1:5], "little")
    freqs, offset = _deserialise_freqs(data, 5)

    ft = _FreqTable(freqs)
    return _decode_bitstream(data[offset:], ft, original_size)


def _compress_order1(data: bytes, original_size: int) -> bytes:
    """Order-1 arithmetic compress using 256 context tables."""
    # Build context frequency tables
    ctx_freqs: list[list[int]] = [[1] * TOTAL_SYMBOLS for _ in range(256)]
    prev = 0
    for byte in data:
        ctx_freqs[prev][byte] = min(ctx_freqs[prev][byte] + 1, MAX_FREQ)
        prev = byte

    # Encode with context switching
    ctx_tables: list[_FreqTable] = [_FreqTable(freqs) for freqs in ctx_freqs]
    prev = 0

    low = 0
    high = FULL = (1 << PRECISION) - 1
    underflow = 0
    output: list[int] = []

    def _emit_bit(bit: int) -> None:
        output.append(bit)

    def _flush_underflow(bit: int) -> None:
        nonlocal underflow
        _emit_bit(bit)
        for _ in range(underflow):
            _emit_bit(1 - bit)
        underflow = 0

    for byte in data:
        ft = ctx_tables[prev]
        sym = byte
        range_size = high - low + 1
        high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
        low = low + (range_size * ft.cumul[sym]) // ft.total

        while True:
            if high < HALF:
                _flush_underflow(0)
            elif low >= HALF:
                _flush_underflow(1)
                low -= HALF
                high -= HALF
            elif low >= QUARTER and high < THREE_QUARTERS:
                underflow += 1
                low -= QUARTER
                high -= QUARTER
            else:
                break
            low <<= 1
            high = (high << 1) | 1

        ft.update(sym)
        prev = byte

    # EOF
    ft = ctx_tables[prev]
    sym = EOF_SYMBOL
    range_size = high - low + 1
    high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
    low = low + (range_size * ft.cumul[sym]) // ft.total

    while True:
        if high < HALF:
            _flush_underflow(0)
        elif low >= HALF:
            _flush_underflow(1)
            low -= HALF
            high -= HALF
        elif low >= QUARTER and high < THREE_QUARTERS:
            underflow += 1
            low -= QUARTER
            high -= QUARTER
        else:
            break
        low <<= 1
        high = (high << 1) | 1

    underflow += 1
    if low < QUARTER:
        _flush_underflow(0)
    else:
        _flush_underflow(1)

    bitstream = "".join(str(b) for b in output)
    padding = (8 - len(bitstream) % 8) % 8
    bitstream += "0" * padding

    result = bytearray()
    for i in range(0, len(bitstream), 8):
        result.append(int(bitstream[i : i + 8], 2))
    encoded = bytes(result)

    # Build header: order(1) + size(4) + n_ctx(2) + sparse context tables
    header = bytearray()
    header.append(1)  # order
    header.extend(original_size.to_bytes(4, "little"))
    
    # Only serialize non-empty contexts
    non_empty = [(ctx, freqs) for ctx, freqs in enumerate(ctx_freqs) if sum(freqs) > TOTAL_SYMBOLS]
    header.extend(len(non_empty).to_bytes(2, "little"))
    for ctx, freqs in non_empty:
        header.append(ctx)
        header.extend(_serialise_freqs(freqs))

    return bytes(header) + encoded


def _decompress_order1(data: bytes) -> bytes:
    """Order-1 arithmetic decompress."""
    if len(data) < 7:
        return b""

    order = data[0]
    original_size = int.from_bytes(data[1:5], "little")
    n_ctx = int.from_bytes(data[5:7], "little")
    offset = 7

    ctx_freqs: list[list[int]] = [[1] * TOTAL_SYMBOLS for _ in range(256)]  # default uniform
    for _ in range(n_ctx):
        ctx = data[offset]
        offset += 1
        freqs, offset = _deserialise_freqs(data, offset)
        ctx_freqs[ctx] = freqs

    ctx_tables: list[_FreqTable] = [_FreqTable(freqs) for freqs in ctx_freqs]

    # Decode
    bitstream = "".join(f"{byte:08b}" for byte in data[offset:])
    pos = 0

    def _read_bit() -> int:
        nonlocal pos
        if pos >= len(bitstream):
            return 0
        bit = 1 if bitstream[pos] == "1" else 0
        pos += 1
        return bit

    low = 0
    high = FULL = (1 << PRECISION) - 1
    value = 0
    for _ in range(PRECISION):
        value = (value << 1) | _read_bit()

    output = bytearray()
    decoded = 0
    prev = 0

    while decoded < original_size:
        ft = ctx_tables[prev]
        range_size = high - low + 1
        cum = ((value - low + 1) * ft.total - 1) // range_size

        sym = 0
        while ft.cumul[sym + 1] <= cum:
            sym += 1

        if sym == EOF_SYMBOL:
            break

        output.append(sym)
        decoded += 1

        high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
        low = low + (range_size * ft.cumul[sym]) // ft.total

        while True:
            if high < HALF:
                pass
            elif low >= HALF:
                value -= HALF
                low -= HALF
                high -= HALF
            elif low >= QUARTER and high < THREE_QUARTERS:
                value -= QUARTER
                low -= QUARTER
                high -= QUARTER
            else:
                break
            low <<= 1
            high = (high << 1) | 1
            value = (value << 1) | _read_bit()

        ft.update(sym)
        prev = sym

    return bytes(output)


def _compress_order2(data: bytes, original_size: int) -> bytes:
    """Order-2 arithmetic compress using 65536 context tables."""
    ctx_freqs: dict[int, list[int]] = {}
    prev2 = 0
    prev1 = 0
    for byte in data:
        ctx = (prev2 << 8) | prev1
        if ctx not in ctx_freqs:
            ctx_freqs[ctx] = [1] * TOTAL_SYMBOLS
        ctx_freqs[ctx][byte] = min(ctx_freqs[ctx][byte] + 1, MAX_FREQ)
        prev2 = prev1
        prev1 = byte

    # Build context tables on demand
    ctx_tables: dict[int, _FreqTable] = {}
    for ctx, freqs in ctx_freqs.items():
        ctx_tables[ctx] = _FreqTable(freqs)

    prev2 = 0
    prev1 = 0

    low = 0
    high = FULL = (1 << PRECISION) - 1
    underflow = 0
    output: list[int] = []

    def _emit_bit(bit: int) -> None:
        output.append(bit)

    def _flush_underflow(bit: int) -> None:
        nonlocal underflow
        _emit_bit(bit)
        for _ in range(underflow):
            _emit_bit(1 - bit)
        underflow = 0

    for byte in data:
        ctx = (prev2 << 8) | prev1
        if ctx not in ctx_tables:
            ctx_tables[ctx] = _FreqTable()
        ft = ctx_tables[ctx]
        sym = byte
        range_size = high - low + 1
        high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
        low = low + (range_size * ft.cumul[sym]) // ft.total

        while True:
            if high < HALF:
                _flush_underflow(0)
            elif low >= HALF:
                _flush_underflow(1)
                low -= HALF
                high -= HALF
            elif low >= QUARTER and high < THREE_QUARTERS:
                underflow += 1
                low -= QUARTER
                high -= QUARTER
            else:
                break
            low <<= 1
            high = (high << 1) | 1

        ft.update(sym)
        prev2 = prev1
        prev1 = byte

    # EOF
    ctx = (prev2 << 8) | prev1
    if ctx not in ctx_tables:
        ctx_tables[ctx] = _FreqTable()
    ft = ctx_tables[ctx]
    sym = EOF_SYMBOL
    range_size = high - low + 1
    high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
    low = low + (range_size * ft.cumul[sym]) // ft.total

    while True:
        if high < HALF:
            _flush_underflow(0)
        elif low >= HALF:
            _flush_underflow(1)
            low -= HALF
            high -= HALF
        elif low >= QUARTER and high < THREE_QUARTERS:
            underflow += 1
            low -= QUARTER
            high -= QUARTER
        else:
            break
        low <<= 1
        high = (high << 1) | 1

    underflow += 1
    if low < QUARTER:
        _flush_underflow(0)
    else:
        _flush_underflow(1)

    bitstream = "".join(str(b) for b in output)
    padding = (8 - len(bitstream) % 8) % 8
    bitstream += "0" * padding

    result = bytearray()
    for i in range(0, len(bitstream), 8):
        result.append(int(bitstream[i : i + 8], 2))
    encoded = bytes(result)

    # Header: order(1) + size(4) + num_contexts(4) + {ctx_id(4) + freqs(512)}*
    header = bytearray()
    header.append(2)  # order
    header.extend(original_size.to_bytes(4, "little"))
    header.extend(len(ctx_freqs).to_bytes(4, "little"))
    for ctx, freqs in sorted(ctx_freqs.items()):
        header.extend(ctx.to_bytes(4, "little"))
        header.extend(_serialise_freqs(freqs))

    return bytes(header) + encoded


def _decompress_order2(data: bytes) -> bytes:
    """Order-2 arithmetic decompress."""
    if len(data) < 11:
        return b""

    order = data[0]
    original_size = int.from_bytes(data[1:5], "little")
    num_contexts = int.from_bytes(data[5:9], "little")
    offset = 9

    ctx_freqs: dict[int, list[int]] = {}
    for _ in range(num_contexts):
        ctx = int.from_bytes(data[offset : offset + 4], "little")
        offset += 4
        freqs, offset = _deserialise_freqs(data, offset)
        ctx_freqs[ctx] = freqs

    ctx_tables: dict[int, _FreqTable] = {}
    for ctx, freqs in ctx_freqs.items():
        ctx_tables[ctx] = _FreqTable(freqs)

    bitstream = "".join(f"{byte:08b}" for byte in data[offset:])
    pos = 0

    def _read_bit() -> int:
        nonlocal pos
        if pos >= len(bitstream):
            return 0
        bit = 1 if bitstream[pos] == "1" else 0
        pos += 1
        return bit

    low = 0
    high = FULL = (1 << PRECISION) - 1
    value = 0
    for _ in range(PRECISION):
        value = (value << 1) | _read_bit()

    output = bytearray()
    decoded = 0
    prev2 = 0
    prev1 = 0

    while decoded < original_size:
        ctx = (prev2 << 8) | prev1
        if ctx not in ctx_tables:
            ctx_tables[ctx] = _FreqTable()
        ft = ctx_tables[ctx]
        range_size = high - low + 1
        cum = ((value - low + 1) * ft.total - 1) // range_size

        sym = 0
        while ft.cumul[sym + 1] <= cum:
            sym += 1

        if sym == EOF_SYMBOL:
            break

        output.append(sym)
        decoded += 1

        high = low + (range_size * ft.cumul[sym + 1]) // ft.total - 1
        low = low + (range_size * ft.cumul[sym]) // ft.total

        while True:
            if high < HALF:
                pass
            elif low >= HALF:
                value -= HALF
                low -= HALF
                high -= HALF
            elif low >= QUARTER and high < THREE_QUARTERS:
                value -= QUARTER
                low -= QUARTER
                high -= QUARTER
            else:
                break
            low <<= 1
            high = (high << 1) | 1
            value = (value << 1) | _read_bit()

        ft.update(sym)
        prev2 = prev1
        prev1 = sym

    return bytes(output)


# ---------------------------------------------------------------------------
# Public API
# ---------------------------------------------------------------------------


def compress(data: bytes, order: int = 0) -> CodecResult:
    """Compress *data* with Order-*order* arithmetic coding.

    Parameters
    ----------
    data : bytes
        Raw input.
    order : {0, 1, 2}
        Model order.

    Returns
    -------
    CodecResult
    """
    start = time.perf_counter()
    original_size = len(data)

    try:
        compressed = _compress_arithmetic(data, order=order)
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
    order : {0, 1, 2}
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
        elif order == 2:
            decompressed = _decompress_order2(data)
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
# Parameter space
# ---------------------------------------------------------------------------

PARAM_SPACE: list[dict] = [
    {"order": 0, "label": "arithmetic_order0"},
    {"order": 1, "label": "arithmetic_order1"},
    {"order": 2, "label": "arithmetic_order2"},
]
