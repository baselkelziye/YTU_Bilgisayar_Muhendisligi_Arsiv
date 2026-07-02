"""Tests for grid search selection logic and parameter spaces.

Uses synthetic data to verify that:
- ``select_best_per_profile`` picks the lowest-BPB combination.
- Tie-breaking favours lower ms_per_kb.
- Parameter spaces are correctly enumerated.
"""

from __future__ import annotations

import pandas as pd
import pytest

from src.matching.parameter_spaces import (
    ALGORITHM_IDS,
    CODEC_PARAM_SPACES,
    get_parameter_spec,
    iter_all_combinations,
    total_combinations,
)
from src.matching.profile_mapping import select_best_per_profile


# ---------------------------------------------------------------------------
# Parameter space tests
# ---------------------------------------------------------------------------


def test_all_algorithm_ids_have_spaces():
    """Every algorithm ID must have a non-empty parameter space."""
    for algo_id in ALGORITHM_IDS:
        assert algo_id in CODEC_PARAM_SPACES, f"Missing param space for {algo_id}"
        assert len(CODEC_PARAM_SPACES[algo_id]) > 0, f"Empty param space for {algo_id}"


def test_each_param_set_has_label():
    """Every parameter set must have a unique label."""
    for algo_id, params_list in CODEC_PARAM_SPACES.items():
        labels = [p.get("label") for p in params_list]
        assert all(labels), f"Missing label in {algo_id}"
        assert len(labels) == len(set(labels)), f"Duplicate labels in {algo_id}"


def test_get_parameter_spec_found():
    """get_parameter_spec returns correct params for known label."""
    spec = get_parameter_spec("huffman", "huffman_order0")
    assert spec is not None
    assert spec["order"] == 0


def test_get_parameter_spec_not_found():
    """get_parameter_spec returns None for unknown label."""
    spec = get_parameter_spec("huffman", "nonexistent")
    assert spec is None


def test_get_parameter_spec_unknown_algorithm():
    """get_parameter_spec returns None for unknown algorithm."""
    spec = get_parameter_spec("unknown_algo", "some_label")
    assert spec is None


def test_total_combinations():
    """total_combinations matches sum of all param space lengths."""
    expected = sum(len(params) for params in CODEC_PARAM_SPACES.values())
    assert total_combinations() == expected


def test_iter_all_combinations():
    """iter_all_combinations yields correct number of items."""
    combos = list(iter_all_combinations())
    assert len(combos) == total_combinations()
    for algo_id, params in combos:
        assert algo_id in ALGORITHM_IDS
        assert "label" in params


# ---------------------------------------------------------------------------
# Selection logic tests
# ---------------------------------------------------------------------------


def _make_grid_results(
    profile_ids: list[str],
    algorithms: list[str],
    param_sets: list[str],
    bpbs: list[list[float]],
    ms_per_kbs: list[list[float]],
) -> pd.DataFrame:
    """Build a synthetic grid results DataFrame."""
    rows: list[dict] = []
    for pid in profile_ids:
        for algo, ps, bpb_list, ms_list in zip(algorithms, param_sets, bpbs, ms_per_kbs):
            for bpb, ms in zip(bpb_list, ms_list):
                rows.append({
                    "profile_id": pid,
                    "algorithm_id": algo,
                    "parameter_set_id": ps,
                    "label": f"{algo}:{ps}",
                    "bpb": bpb,
                    "ms_per_kb": ms,
                    "valid": True,
                })
    return pd.DataFrame(rows)


def test_select_best_picks_lowest_bpb():
    """Selection must pick the combination with lowest mean BPB."""
    df = _make_grid_results(
        profile_ids=["profile_1"],
        algorithms=["algo_a", "algo_b"],
        param_sets=["ps1", "ps1"],
        bpbs=[[5.0, 6.0], [3.0, 4.0]],  # algo_b has lower BPB
        ms_per_kbs=[[10.0, 12.0], [15.0, 16.0]],
    )
    best = select_best_per_profile(df)
    assert len(best) == 1
    assert best.iloc[0]["algorithm_id"] == "algo_b"
    assert best.iloc[0]["mean_bpb"] == pytest.approx(3.5)


def test_select_best_tie_break():
    """Tie in BPB must be broken by lower ms_per_kb."""
    df = _make_grid_results(
        profile_ids=["profile_1"],
        algorithms=["algo_a", "algo_b"],
        param_sets=["ps1", "ps1"],
        bpbs=[[4.0, 4.0], [4.0, 4.0]],  # same BPB
        ms_per_kbs=[[20.0, 22.0], [10.0, 12.0]],  # algo_b faster
    )
    best = select_best_per_profile(df)
    assert len(best) == 1
    assert best.iloc[0]["algorithm_id"] == "algo_b"


def test_select_best_multiple_profiles():
    """Selection must work independently per profile."""
    df = _make_grid_results(
        profile_ids=["profile_1", "profile_2"],
        algorithms=["algo_a", "algo_b"],
        param_sets=["ps1", "ps1"],
        bpbs=[[5.0, 6.0], [3.0, 4.0]],  # profile_1: algo_a, profile_2: algo_b
        ms_per_kbs=[[10.0, 12.0], [15.0, 16.0]],
    )
    best = select_best_per_profile(df)
    assert len(best) == 2
    p1 = best[best["profile_id"] == "profile_1"].iloc[0]
    p2 = best[best["profile_id"] == "profile_2"].iloc[0]
    assert p1["algorithm_id"] == "algo_a"
    assert p2["algorithm_id"] == "algo_b"


def test_select_best_filters_invalid():
    """Invalid rows must be excluded from selection."""
    df = pd.DataFrame([
        {"profile_id": "p1", "algorithm_id": "a", "parameter_set_id": "p1",
         "label": "a:p1", "bpb": 5.0, "ms_per_kb": 10.0, "valid": False},
        {"profile_id": "p1", "algorithm_id": "b", "parameter_set_id": "p1",
         "label": "b:p1", "bpb": 3.0, "ms_per_kb": 15.0, "valid": True},
    ])
    best = select_best_per_profile(df)
    assert len(best) == 1
    assert best.iloc[0]["algorithm_id"] == "b"


def test_select_best_empty_returns_empty():
    """Empty or all-invalid input must return empty DataFrame."""
    df = pd.DataFrame(columns=["profile_id", "algorithm_id", "parameter_set_id",
                                "label", "bpb", "ms_per_kb", "valid"])
    best = select_best_per_profile(df)
    assert len(best) == 0


def test_select_best_valid_rate_filter():
    """Parameter sets below min_valid_rate must be excluded."""
    df = pd.DataFrame([
        {"profile_id": "p1", "algorithm_id": "a", "parameter_set_id": "p1",
         "label": "a:p1", "bpb": 5.0, "ms_per_kb": 10.0, "valid": True},
        {"profile_id": "p1", "algorithm_id": "a", "parameter_set_id": "p1",
         "label": "a:p1", "bpb": 5.0, "ms_per_kb": 10.0, "valid": False},
        {"profile_id": "p1", "algorithm_id": "b", "parameter_set_id": "p1",
         "label": "b:p1", "bpb": 6.0, "ms_per_kb": 5.0, "valid": True},
        {"profile_id": "p1", "algorithm_id": "b", "parameter_set_id": "p1",
         "label": "b:p1", "bpb": 6.0, "ms_per_kb": 5.0, "valid": True},
    ])
    # algo_a has valid_rate=0.5, algo_b has valid_rate=1.0
    best = select_best_per_profile(df, min_valid_rate=0.8)
    assert len(best) == 1
    assert best.iloc[0]["algorithm_id"] == "b"
