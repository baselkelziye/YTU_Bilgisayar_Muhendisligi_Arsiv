"""Parameter grid definitions for each candidate codec.

Each entry in ``CODEC_PARAM_SPACES`` maps an ``algorithm_id`` to a list of
parameter dicts.  Every parameter dict must include a ``label`` field that
uniquely identifies the parameter set within that algorithm.

The grid-search orchestrator iterates over every ``(algorithm_id, params)``
pair for each profile chunk.
"""

from __future__ import annotations

from typing import Any

# ---------------------------------------------------------------------------
# Algorithm IDs (must match the keys in CODEC_PARAM_SPACES)
# ---------------------------------------------------------------------------

ALGORITHM_IDS = [
    "huffman",
    "lzw",
    "arithmetic",
    "bwt_mtf",
    "rle_huffman",
]

# ---------------------------------------------------------------------------
# Parameter spaces
# ---------------------------------------------------------------------------

CODEC_PARAM_SPACES: dict[str, list[dict[str, Any]]] = {
    "huffman": [
        {"order": 0, "label": "huffman_order0"},
        {"order": 1, "label": "huffman_order1"},
    ],
    "lzw": [
        {"max_bits": 9, "label": "lzw_bits9"},
        {"max_bits": 10, "label": "lzw_bits10"},
        {"max_bits": 11, "label": "lzw_bits11"},
        {"max_bits": 12, "label": "lzw_bits12"},
        {"max_bits": 13, "label": "lzw_bits13"},
        {"max_bits": 14, "label": "lzw_bits14"},
        {"max_bits": 15, "label": "lzw_bits15"},
        {"max_bits": 16, "label": "lzw_bits16"},
    ],
    "arithmetic": [
        {"order": 0, "label": "arithmetic_order0"},
        {"order": 1, "label": "arithmetic_order1"},
        {"order": 2, "label": "arithmetic_order2"},
    ],
    "bwt_mtf": [
        {"secondary": "huffman", "block_size": 0, "label": "bwt_mtf_huffman"},
        {"secondary": "arithmetic", "block_size": 0, "label": "bwt_mtf_arithmetic"},
        {"secondary": "huffman", "block_size": 10240, "label": "bwt_mtf_huffman_b10k"},
        {"secondary": "arithmetic", "block_size": 10240, "label": "bwt_mtf_arithmetic_b10k"},
    ],
    "rle_huffman": [
        {"min_run": 3, "label": "rle_huffman_run3"},
        {"min_run": 4, "label": "rle_huffman_run4"},
        {"min_run": 5, "label": "rle_huffman_run5"},
        {"min_run": 8, "label": "rle_huffman_run8"},
    ],
}


def get_parameter_spec(algorithm_id: str, label: str) -> dict[str, Any] | None:
    """Look up a specific parameter set by algorithm ID and label.

    Returns the parameter dict or ``None`` if not found.
    """
    space = CODEC_PARAM_SPACES.get(algorithm_id, [])
    for params in space:
        if params.get("label") == label:
            return params
    return None


def total_combinations() -> int:
    """Return the total number of ``(algorithm_id, parameter_set)`` pairs."""
    return sum(len(params) for params in CODEC_PARAM_SPACES.values())


def iter_all_combinations():
    """Yield ``(algorithm_id, params)`` tuples for every combination."""
    for algo_id in ALGORITHM_IDS:
        for params in CODEC_PARAM_SPACES.get(algo_id, []):
            yield algo_id, params
