"""Adaptive compression pipeline — end-to-end compress.

Flow per chunk:
  1. Split input into fixed-size blocks (final_chunk_size).
  2. Extract Set B fast features.
  3. MLP predicts profile_id + confidence.
  4. Look up (algorithm_id, parameter_set_id) from Phase 2 mapping.
  5. If confidence too low → use fallback profile.
  6. Encode with selected codec.
  7. If compression doesn't reduce size → store raw.
  8. Pack 4-byte header + compressed (or raw) data into bitstream.
"""

from __future__ import annotations

import logging
from pathlib import Path
from typing import Any

from src.codecs import huffman_codec, lzw_codec, arithmetic_codec, bwt_codec, rle_codec
from src.compression.block_header import encode_header
from src.compression.fallback_policy import (
    get_fallback_profile,
    get_raw_store_threshold,
    should_use_prediction,
)
from src.compression.profile_classifier import ProfileClassifier
from src.compression.profile_lookup import ProfileLookup
from src.matching.parameter_spaces import get_parameter_spec

logger = logging.getLogger(__name__)

CODEC_DISPATCH: dict[str, Any] = {
    "huffman": huffman_codec,
    "lzw": lzw_codec,
    "arithmetic": arithmetic_codec,
    "bwt_mtf": bwt_codec,
    "rle_huffman": rle_codec,
}


class AdaptiveCompressor:
    """End-to-end adaptive text compressor.

    Args:
        phase3_dir: Directory containing Phase 3 artifacts (model.pt, scaler.pkl, ...).
        mapping_path: Path to Phase 2 ``profile_algorithm_mapping.json``.
        chunk_size: Fixed block size in characters (must match what Phase 1/3 used).
    """

    def __init__(
        self,
        phase3_dir: Path,
        mapping_path: Path,
        chunk_size: int = 512,
    ) -> None:
        self.chunk_size = chunk_size
        self.classifier = ProfileClassifier(phase3_dir)
        self.lookup = ProfileLookup(mapping_path)

        logger.info(
            "AdaptiveCompressor initialized — chunk_size=%d profiles=%d",
            chunk_size,
            self.lookup.num_profiles(),
        )

    def compress(self, text: str) -> bytes:
        """Compress text with adaptive profile-based encoding.

        Returns raw bitstream bytes (non-decodable without the matching
        Phase 2 + Phase 3 artifacts).
        """
        blocks = self._split_into_blocks(text)
        stream_parts: list[bytes] = []

        # Batch classify all blocks first for efficiency
        texts = [
            text[start:start + self.chunk_size]
            for start in range(0, len(text), self.chunk_size)
        ]

        if not texts:
            return b""

        predictions = self.classifier.classify_batch(texts)

        for block_text, (predicted_profile, confidence) in zip(texts, predictions):
            block_bytes = block_text.encode("utf-8")
            block_stream = self._compress_block(block_bytes, predicted_profile, confidence)
            stream_parts.append(block_stream)

        return b"".join(stream_parts)

    def _split_into_blocks(self, text: str) -> list[str]:
        """Split text into fixed-size non-overlapping blocks."""
        return [
            text[i: i + self.chunk_size]
            for i in range(0, len(text), self.chunk_size)
        ]

    def _compress_block(
        self,
        block_bytes: bytes,
        predicted_profile: str,
        confidence: float,
    ) -> bytes:
        """Compress a single block: classify → lookup → codec → header.

        Returns header(4) + compressed_data bytes.

        Raw marker encoding: profile_id=0, algorithm_id=0, param_id=0,
        compressed_size=len(raw_data). We use algorithm_id=0 as the raw
        sentinel (huffman is index 0, but it never produces a 0-size block,
        so we differentiate by checking if the algorithm index is 0 while
        the profile_id is also 0 — or simpler: just use compressed_size=0
        as the raw sentinel and store the actual raw size in the next 2
        bytes after the header).
        """
        # Decide profile
        if not should_use_prediction(confidence):
            profile_id = get_fallback_profile()
            logger.debug("Low confidence (%.3f) — using fallback profile %s", confidence, profile_id)
        else:
            profile_id = predicted_profile

        # Look up algorithm
        algorithm_id, parameter_set_id = self.lookup.lookup(profile_id)
        algo_idx, param_idx = self.lookup.lookup_indices(profile_id)

        # Get codec module
        codec = CODEC_DISPATCH.get(algorithm_id)
        if codec is None:
            logger.error("Unknown algorithm %s — storing raw", algorithm_id)
            return self._raw_block(block_bytes)

        # Get parameter dict from profile lookup (correct param_set match)
        codec_kwargs = self.lookup.lookup_params(profile_id)

        # Compress
        result = codec.compress(block_bytes, **codec_kwargs)

        # Decide: store raw if compression doesn't help
        if not result.valid or result.compression_ratio >= get_raw_store_threshold():
            return self._raw_block(block_bytes)

        header = encode_header(
            profile_id=int(profile_id.split("_")[1]),
            algorithm_id=algo_idx,
            parameter_set_id=param_idx,
            compressed_size=len(result.compressed),  # bytes
        )

        return header + result.compressed

    def _raw_block(self, data: bytes) -> bytes:
        """Encode a raw (uncompressed) block.

        Profile=0, algorithm=RAW_ALGORITHM_ID (15), param=0,
        compressed_size=len(data).
        Decompressor checks algorithm_id == RAW_ALGORITHM_ID for raw marker.
        """
        from src.compression.profile_lookup import RAW_ALGORITHM_ID
        header = encode_header(
            profile_id=0,
            algorithm_id=RAW_ALGORITHM_ID,
            parameter_set_id=0,
            compressed_size=len(data),
        )
        return header + data

    def compress_and_report(self, text: str) -> dict[str, Any]:
        """Compress and return detailed stats for evaluation."""
        original_size = len(text.encode("utf-8"))
        compressed = self.compress(text)
        compressed_size = len(compressed)

        return {
            "original_size": original_size,
            "compressed_size": compressed_size,
            "bpb": compressed_size * 8 / original_size if original_size else 0,
            "compression_ratio": compressed_size / original_size if original_size else 1.0,
            "num_blocks": (len(text) + self.chunk_size - 1) // self.chunk_size,
            "compressed_data": compressed,
        }
