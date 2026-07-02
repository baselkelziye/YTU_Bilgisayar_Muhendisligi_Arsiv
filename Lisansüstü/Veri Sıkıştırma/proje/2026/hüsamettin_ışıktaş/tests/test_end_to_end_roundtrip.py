"""End-to-end roundtrip tests: compress → decompress → identical."""

import tempfile
from pathlib import Path

import pytest

from src.compression.adaptive_compressor import AdaptiveCompressor
from src.compression.adaptive_decompressor import AdaptiveDecompressor


@pytest.fixture(scope="module")
def project_root() -> Path:
    return Path(__file__).resolve().parents[1]


@pytest.fixture(scope="module")
def phase3_dir(project_root: Path) -> Path:
    return project_root / "artifacts" / "phase3"


@pytest.fixture(scope="module")
def mapping_path(project_root: Path) -> Path:
    return project_root / "artifacts" / "phase2" / "profile_algorithm_mapping.json"


@pytest.fixture(scope="module")
def compressor(phase3_dir: Path, mapping_path: Path) -> AdaptiveCompressor:
    return AdaptiveCompressor(phase3_dir=phase3_dir, mapping_path=mapping_path, chunk_size=512)


@pytest.fixture(scope="module")
def decompressor(mapping_path: Path) -> AdaptiveDecompressor:
    return AdaptiveDecompressor(mapping_path=mapping_path)


class TestEndToEndRoundtrip:
    def test_short_text_roundtrip(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        text = "Hello, world! This is a test of the adaptive compression system."
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text, f"Roundtrip failed!\n  Original: {text}\n  Got:      {decompressed}"

    def test_longer_text_roundtrip(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        text = "The quick brown fox jumps over the lazy dog. " * 50
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text

    def test_lorem_ipsum_roundtrip(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        text = (
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. " * 100
        )
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text

    def test_multiple_blocks_roundtrip(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        """Text longer than chunk_size, spanning multiple blocks."""
        text = "ABCDEFGHIJ" * 1000  # ~10K characters
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text

    def test_empty_text_roundtrip(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        text = ""
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text

    def test_special_characters(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        text = "Hello 世界! ñoño \n\t\r\n 42% of $100 is $42. *** EOF ***"
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text

    def test_highly_repetitive_text(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        text = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" * 100
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text

    def test_lossless_on_gutenberg_sample(self, compressor: AdaptiveCompressor, decompressor: AdaptiveDecompressor) -> None:
        """Use a small chunk from the actual processed books."""
        import pandas as pd

        project_root = compressor.classifier.model._parameters  # ugly but works to get project root info
        # Just use a direct path
        books_dir = Path(__file__).resolve().parents[1] / "data" / "processed" / "books"
        book_files = sorted(books_dir.glob("*.txt"))
        if not book_files:
            pytest.skip("No processed book files found")

        text = book_files[0].read_text(encoding="utf-8")[:20000]
        compressed = compressor.compress(text)
        decompressed = decompressor.decompress(compressed)
        assert decompressed == text, (
            f"Roundtrip failed on {book_files[0].name}!\n"
            f"  Original length: {len(text)}\n"
            f"  Decompressed: {len(decompressed)}\n"
            f"  First diff at char: {next((i for i, (a, b) in enumerate(zip(text, decompressed)) if a != b), -1)}"
        )
