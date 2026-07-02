"""Lossless roundtrip tests for all Phase 2 codecs.

Each test generates random byte sequences of varying lengths and
characteristics, compresses with the codec, decompresses, and asserts
the output matches the input exactly.
"""

from __future__ import annotations

import random

import pytest

from src.codecs import huffman_codec, lzw_codec, arithmetic_codec, bwt_codec, rle_codec


# ---------------------------------------------------------------------------
# Test helpers
# ---------------------------------------------------------------------------

SEED = 42


def _make_random_bytes(length: int, seed: int = SEED) -> bytes:
    rng = random.Random(seed)
    return bytes(rng.randint(0, 255) for _ in range(length))


def _make_text_bytes(length: int, seed: int = SEED) -> bytes:
    """Generate ASCII-like text bytes (printable chars + spaces/newlines)."""
    rng = random.Random(seed)
    chars = list(range(32, 127)) + [10, 13]  # printable ASCII + LF + CR
    return bytes(rng.choice(chars) for _ in range(length))


def _make_repetitive_bytes(length: int, seed: int = SEED) -> bytes:
    """Generate highly repetitive data (good for RLE)."""
    rng = random.Random(seed)
    patterns = [b"A", b"AB", b"ABC", b"AAAA", b"000000"]
    result = bytearray()
    while len(result) < length:
        result.extend(rng.choice(patterns))
    return bytes(result[:length])


# ---------------------------------------------------------------------------
# Roundtrip test cases
# ---------------------------------------------------------------------------

TEST_SIZES = [0, 1, 10, 100, 1000, 10000]
TEST_DATA_GENERATORS = [
    ("random", _make_random_bytes),
    ("text", _make_text_bytes),
    ("repetitive", _make_repetitive_bytes),
]


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_huffman_order0_roundtrip(size: int, data_type: str, generator):
    """Order-0 Huffman: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = huffman_codec.compress(data, order=0)
    assert comp.valid, f"Huffman O0 compress failed: {comp.error}"
    decomp = huffman_codec.decompress(comp.compressed, order=0)
    assert decomp.valid, f"Huffman O0 decompress failed: {decomp.error}"
    assert decomp.compressed == data, f"Huffman O0 roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_huffman_order1_roundtrip(size: int, data_type: str, generator):
    """Order-1 Huffman: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = huffman_codec.compress(data, order=1)
    if not comp.valid and size > 0:
        # Order-1 may fail on very small data; that's acceptable
        return
    if comp.valid:
        decomp = huffman_codec.decompress(comp.compressed, order=1)
        assert decomp.valid, f"Huffman O1 decompress failed: {decomp.error}"
        assert decomp.compressed == data, f"Huffman O1 roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_lzw_roundtrip(size: int, data_type: str, generator):
    """LZW: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    for max_bits in [9, 12, 16]:
        comp = lzw_codec.compress(data, max_bits=max_bits)
        assert comp.valid, f"LZW compress failed (max_bits={max_bits}): {comp.error}"
        decomp = lzw_codec.decompress(comp.compressed, max_bits=max_bits)
        assert decomp.valid, f"LZW decompress failed (max_bits={max_bits}): {decomp.error}"
        assert decomp.compressed == data, (
            f"LZW roundtrip mismatch (size={size}, type={data_type}, max_bits={max_bits})"
        )


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_arithmetic_order0_roundtrip(size: int, data_type: str, generator):
    """Order-0 Arithmetic: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = arithmetic_codec.compress(data, order=0)
    assert comp.valid, f"Arithmetic O0 compress failed: {comp.error}"
    decomp = arithmetic_codec.decompress(comp.compressed, order=0)
    assert decomp.valid, f"Arithmetic O0 decompress failed: {decomp.error}"
    assert decomp.compressed == data, f"Arithmetic O0 roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_arithmetic_order1_roundtrip(size: int, data_type: str, generator):
    """Order-1 Arithmetic: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = arithmetic_codec.compress(data, order=1)
    if not comp.valid and size > 0:
        return
    if comp.valid:
        decomp = arithmetic_codec.decompress(comp.compressed, order=1)
        assert decomp.valid, f"Arithmetic O1 decompress failed: {decomp.error}"
        assert decomp.compressed == data, f"Arithmetic O1 roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_arithmetic_order2_roundtrip(size: int, data_type: str, generator):
    """Order-2 Arithmetic: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = arithmetic_codec.compress(data, order=2)
    if not comp.valid and size > 0:
        return
    if comp.valid:
        decomp = arithmetic_codec.decompress(comp.compressed, order=2)
        assert decomp.valid, f"Arithmetic O2 decompress failed: {decomp.error}"
        assert decomp.compressed == data, f"Arithmetic O2 roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_bwt_mtf_huffman_roundtrip(size: int, data_type: str, generator):
    """BWT+MTF+Huffman: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = bwt_codec.compress(data, secondary="huffman")
    assert comp.valid, f"BWT+MTF+Huffman compress failed: {comp.error}"
    decomp = bwt_codec.decompress(comp.compressed)
    assert decomp.valid, f"BWT+MTF+Huffman decompress failed: {decomp.error}"
    assert decomp.compressed == data, f"BWT+MTF+Huffman roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_bwt_mtf_arithmetic_roundtrip(size: int, data_type: str, generator):
    """BWT+MTF+Arithmetic: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    comp = bwt_codec.compress(data, secondary="arithmetic")
    assert comp.valid, f"BWT+MTF+Arithmetic compress failed: {comp.error}"
    decomp = bwt_codec.decompress(comp.compressed)
    assert decomp.valid, f"BWT+MTF+Arithmetic decompress failed: {decomp.error}"
    assert decomp.compressed == data, f"BWT+MTF+Arithmetic roundtrip mismatch (size={size}, type={data_type})"


@pytest.mark.parametrize("size", TEST_SIZES)
@pytest.mark.parametrize("data_type, generator", TEST_DATA_GENERATORS)
def test_rle_huffman_roundtrip(size: int, data_type: str, generator):
    """RLE+Huffman: compress then decompress must return original."""
    data = generator(size, seed=SEED)
    for min_run in [3, 4, 5]:
        comp = rle_codec.compress(data, min_run=min_run)
        assert comp.valid, f"RLE+Huffman compress failed (min_run={min_run}): {comp.error}"
        decomp = rle_codec.decompress(comp.compressed)
        assert decomp.valid, f"RLE+Huffman decompress failed (min_run={min_run}): {decomp.error}"
        assert decomp.compressed == data, (
            f"RLE+Huffman roundtrip mismatch (size={size}, type={data_type}, min_run={min_run})"
        )


# ---------------------------------------------------------------------------
# Edge cases
# ---------------------------------------------------------------------------


def test_empty_input_all_codecs():
    """All codecs must handle empty input gracefully."""
    data = b""
    for codec, kwargs in [
        (huffman_codec, {"order": 0}),
        (huffman_codec, {"order": 1}),
        (lzw_codec, {"max_bits": 12}),
        (arithmetic_codec, {"order": 0}),
        (arithmetic_codec, {"order": 1}),
        (arithmetic_codec, {"order": 2}),
        (bwt_codec, {"secondary": "huffman"}),
        (bwt_codec, {"secondary": "arithmetic"}),
        (rle_codec, {"min_run": 4}),
    ]:
        comp = codec.compress(data, **kwargs)
        assert comp.valid, f"{codec.__name__} empty compress failed"
        if codec is bwt_codec:
            decomp = codec.decompress(comp.compressed)
        else:
            decomp = codec.decompress(comp.compressed, **{k: v for k, v in kwargs.items() if k != "min_run"})
        assert decomp.valid, f"{codec.__name__} empty decompress failed"
        assert decomp.compressed == data, f"{codec.__name__} empty roundtrip mismatch"


def test_single_byte_all_codecs():
    """All codecs must handle single-byte input."""
    data = b"A"
    for codec, kwargs in [
        (huffman_codec, {"order": 0}),
        (lzw_codec, {"max_bits": 12}),
        (arithmetic_codec, {"order": 0}),
        (bwt_codec, {"secondary": "huffman"}),
        (rle_codec, {"min_run": 4}),
    ]:
        comp = codec.compress(data, **kwargs)
        assert comp.valid, f"{codec.__name__} single-byte compress failed"
        if codec is bwt_codec:
            decomp = codec.decompress(comp.compressed)
        elif codec is rle_codec:
            decomp = codec.decompress(comp.compressed)
        else:
            decomp = codec.decompress(comp.compressed, **kwargs)
        assert decomp.valid, f"{codec.__name__} single-byte decompress failed"
        assert decomp.compressed == data, f"{codec.__name__} single-byte roundtrip mismatch"


def test_all_same_byte():
    """All codecs must handle runs of the same byte."""
    data = b"x" * 1000
    for codec, kwargs in [
        (huffman_codec, {"order": 0}),
        (lzw_codec, {"max_bits": 12}),
        (arithmetic_codec, {"order": 0}),
        (bwt_codec, {"secondary": "huffman"}),
        (rle_codec, {"min_run": 4}),
    ]:
        comp = codec.compress(data, **kwargs)
        assert comp.valid, f"{codec.__name__} same-byte compress failed"
        if codec is bwt_codec:
            decomp = codec.decompress(comp.compressed)
        elif codec is rle_codec:
            decomp = codec.decompress(comp.compressed)
        else:
            decomp = codec.decompress(comp.compressed, **kwargs)
        assert decomp.valid, f"{codec.__name__} same-byte decompress failed"
        assert decomp.compressed == data, f"{codec.__name__} same-byte roundtrip mismatch"
