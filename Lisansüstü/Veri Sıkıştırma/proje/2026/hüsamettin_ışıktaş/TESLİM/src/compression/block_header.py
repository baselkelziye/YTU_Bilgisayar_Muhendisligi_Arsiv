"""4-byte block header encode/decode utilities.

Header format (32 bits, big-endian):
  Bits 0-7   : profile_id (0-255)
  Bits 8-11  : algorithm_id (0-15)
  Bits 12-15 : parameter_set_id (0-15)
  Bits 16-31 : compressed_block_size (0-65535 bytes, 0 = raw/uncompressed)

``algorithm_id`` and ``parameter_set_id`` are indices into lookup tables,
not the raw string IDs.
"""

from __future__ import annotations

import struct

HEADER_SIZE_BYTES = 4


def encode_header(
    profile_id: int,
    algorithm_id: int,
    parameter_set_id: int,
    compressed_size: int,
) -> bytes:
    """Pack 32-bit header into 4 bytes."""
    packed = (
        (profile_id & 0xFF) << 24
        | (algorithm_id & 0x0F) << 20
        | (parameter_set_id & 0x0F) << 16
        | (compressed_size & 0xFFFF)
    )
    return packed.to_bytes(4, byteorder="big")


def decode_header(header: bytes) -> dict[str, int]:
    """Unpack 4-byte header into component fields.

    Raises ValueError if header is not exactly 4 bytes.
    """
    if len(header) != HEADER_SIZE_BYTES:
        raise ValueError(f"Header must be {HEADER_SIZE_BYTES} bytes, got {len(header)}")
    packed = int.from_bytes(header, byteorder="big")
    return {
        "profile_id": (packed >> 24) & 0xFF,
        "algorithm_id": (packed >> 20) & 0x0F,
        "parameter_set_id": (packed >> 16) & 0x0F,
        "compressed_size": packed & 0xFFFF,
    }


def header_is_raw(compressed_size: int) -> bool:
    """Return True if the block was stored as raw (uncompressed) data."""
    return compressed_size == 0


def set_raw_header_field() -> int:
    """Return 0 for compressed_size to mark a raw/uncompressed block."""
    return 0


def max_compressed_size() -> int:
    """Maximum block size representable in header (64 KiB - 1)."""
    return 0xFFFF
