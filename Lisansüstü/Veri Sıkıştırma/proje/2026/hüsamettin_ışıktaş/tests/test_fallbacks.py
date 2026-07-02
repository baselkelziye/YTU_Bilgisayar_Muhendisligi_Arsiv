"""Tests for fallback policies and edge-case handling."""
import pytest
from src.compression.fallback_policy import (
    CONFIDENCE_THRESHOLD,
    get_fallback_profile,
    get_raw_store_threshold,
    is_block_size_valid,
    should_use_prediction,
)


class TestFallbackPolicy:
    def test_high_confidence_uses_prediction(self) -> None:
        assert should_use_prediction(0.95) is True
        assert should_use_prediction(CONFIDENCE_THRESHOLD) is True
        assert should_use_prediction(CONFIDENCE_THRESHOLD + 0.01) is True

    def test_low_confidence_uses_fallback(self) -> None:
        assert should_use_prediction(0.0) is False
        assert should_use_prediction(CONFIDENCE_THRESHOLD - 0.01) is False
        assert should_use_prediction(0.5) is False

    def test_fallback_profile_is_defined(self) -> None:
        profile = get_fallback_profile()
        assert isinstance(profile, str)
        assert profile.startswith("profile_")

    def test_raw_store_threshold(self) -> None:
        threshold = get_raw_store_threshold()
        assert threshold == 1.0

    def test_is_block_size_valid(self) -> None:
        assert is_block_size_valid(100, 1000) is True
        assert is_block_size_valid(65535, 1000) is True
        assert is_block_size_valid(65536, 1000) is False
        assert is_block_size_valid(0, 100) is True  # raw marker edge case
