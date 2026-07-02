"""Adaptive decompression pipeline — reverse of AdaptiveCompressor.

Reads the bitstream, parses 4-byte headers, selects the correct codec
and parameters, and reconstructs the original text losslessly.
"""

from __future__ import annotations

import logging
from pathlib import Path
from typing import Any

from src.codecs import huffman_codec, lzw_codec, arithmetic_codec, bwt_codec, rle_codec
from src.compression.block_header import HEADER_SIZE_BYTES, decode_header, header_is_raw
from src.compression.profile_lookup import INDEX_TO_ALGORITHM

logger = logging.getLogger(__name__)

CODEC_DISPATCH: dict[int, Any] = {
    0: huffman_codec,
    1: lzw_codec,
    2: arithmetic_codec,
    3: bwt_codec,
    4: rle_codec,
}


class AdaptiveDecompressor:
    """Decompress a bitstream produced by AdaptiveCompressor.

    Requires the same Phase 2 mapping to resolve parameter sets.
    """

    def __init__(self, mapping_path: Path | None = None) -> None:
        self._mapping_path = mapping_path
        self._lookup: Any = None
        if mapping_path is not None:
            from src.compression.profile_lookup import ProfileLookup
            self._lookup = ProfileLookup(mapping_path)

    def decompress(self, stream: bytes) -> str:
        """Decompress entire stream, returning original text."""
        parts: list[str] = []
        offset = 0

        while offset < len(stream):
            if offset + HEADER_SIZE_BYTES > len(stream):
                raise ValueError(
                    f"Incomplete header at offset {offset}: "
                    f"need {HEADER_SIZE_BYTES} bytes, have {len(stream) - offset}"
                )

            header = stream[offset:offset + HEADER_SIZE_BYTES]
            offset += HEADER_SIZE_BYTES

            fields = decode_header(header)

            if self._is_raw_block(fields):
                # Raw block: profile_id=0, algorithm_id=0, param_id=0,
                # compressed_size=len(raw_data). Read raw data directly.
                raw_size = fields["compressed_size"]
                if offset + raw_size > len(stream):
                    remaining = len(stream) - offset
                    raw_data = stream[offset:]
                    offset = len(stream)
                else:
                    raw_data = stream[offset:offset + raw_size]
                    offset += raw_size
                parts.append(raw_data.decode("utf-8", errors="replace"))
                continue

            compressed_size = fields["compressed_size"]

            if offset + compressed_size > len(stream):
                raise ValueError(
                    f"Block at offset {offset} claims {compressed_size} compressed bytes, "
                    f"but stream has only {len(stream) - offset} remaining"
                )

            compressed_data = stream[offset:offset + compressed_size]
            offset += compressed_size

            # Decompress — use params from lookup if available
            algorithm_id = fields["algorithm_id"]
            param_id = fields["parameter_set_id"]
            codec = CODEC_DISPATCH.get(algorithm_id)
            if codec is None:
                raise ValueError(f"Unknown algorithm_id {algorithm_id} at offset {offset}")

            if self._lookup is not None:
                codec_kwargs = self._lookup.lookup_params_by_index(algorithm_id, param_id)
            else:
                codec_kwargs = {}

            result = codec.decompress(compressed_data, **codec_kwargs)
            if not result.valid:
                raise ValueError(
                    f"Decompression failed at offset {offset}: {result.error}"
                )

            parts.append(result.compressed.decode("utf-8"))

        return "".join(parts)

    @staticmethod
    def _is_raw_block(fields: dict[str, int]) -> bool:
        from src.compression.profile_lookup import RAW_ALGORITHM_ID
        return fields["algorithm_id"] == RAW_ALGORITHM_ID

    def has_mapping(self) -> bool:
        return self._mapping_path is not None
