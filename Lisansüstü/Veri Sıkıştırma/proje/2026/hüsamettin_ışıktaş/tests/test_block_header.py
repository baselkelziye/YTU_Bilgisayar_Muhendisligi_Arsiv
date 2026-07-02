"""Tests for 4-byte block header encode/decode."""

import pytest

from src.compression.block_header import (
    HEADER_SIZE_BYTES,
    decode_header,
    encode_header,
    header_is_raw,
    max_compressed_size,
)


class TestBlockHeader:
    def test_encode_decode_roundtrip(self) -> None:
        fields = {"profile_id": 5, "algorithm_id": 2, "parameter_set_id": 1, "compressed_size": 1024}
        header = encode_header(**fields)
        assert len(header) == HEADER_SIZE_BYTES
        decoded = decode_header(header)
        assert decoded == fields

    def test_max_values(self) -> None:
        fields = {"profile_id": 255, "algorithm_id": 15, "parameter_set_id": 15, "compressed_size": 65535}
        header = encode_header(**fields)
        decoded = decode_header(header)
        assert decoded == fields

    def test_zero_values(self) -> None:
        fields = {"profile_id": 0, "algorithm_id": 0, "parameter_set_id": 0, "compressed_size": 0}
        header = encode_header(**fields)
        decoded = decode_header(header)
        assert decoded == fields
        # Zero compressed_size = raw marker
        assert header_is_raw(decoded["compressed_size"])

    def test_raw_marker(self) -> None:
        assert header_is_raw(0) is True
        assert header_is_raw(1) is False
        assert header_is_raw(65535) is False

    def test_invalid_header_length(self) -> None:
        with pytest.raises(ValueError, match="Header must be 4 bytes"):
            decode_header(b"\x00\x00\x00")
        with pytest.raises(ValueError, match="Header must be 4 bytes"):
            decode_header(b"\x00" * 5)

    def test_max_compressed_size(self) -> None:
        assert max_compressed_size() == 65535

    def test_specific_bit_pattern(self) -> None:
        """profile_id=1, algorithm_id=0, param_id=0, size=100"""
        header = encode_header(1, 0, 0, 100)
        # 1 << 24 = 0x01000000, OR with 100 = 0x01000064
        assert header == b"\x01\x00\x00\x64"
        decoded = decode_header(header)
        assert decoded["profile_id"] == 1
        assert decoded["algorithm_id"] == 0
        assert decoded["compressed_size"] == 100
