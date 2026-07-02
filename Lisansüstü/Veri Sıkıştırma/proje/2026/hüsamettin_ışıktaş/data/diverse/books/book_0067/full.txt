"""Profile -> algorithm/parameter lookup from Phase 2 mapping."""

from __future__ import annotations

import json
from pathlib import Path
from typing import Any

# Algorithm enum for header encoding
ALGORITHM_INDEX: dict[str, int] = {
    "huffman": 0,
    "lzw": 1,
    "arithmetic": 2,
    "bwt_mtf": 3,
    "rle_huffman": 4,
}

INDEX_TO_ALGORITHM: dict[int, str] = {v: k for k, v in ALGORITHM_INDEX.items()}

# Raw block marker — use algorithm_id=15 (1111 binary) which never maps
# to a real algorithm (max is rle_huffman=4).  profile_id=0, algorithm_id=15,
# compressed_size=len(data).
RAW_ALGORITHM_ID = 15

# Default profile: fallback when no match
DEFAULT_PROFILE = "profile_0"


class ProfileLookup:
    """Mapping from profile_id -> (algorithm_id, parameter_set_id, params)."""

    def __init__(self, mapping_path: Path) -> None:
        with open(mapping_path) as f:
            raw: dict[str, dict[str, Any]] = json.load(f)
        self._mapping: dict[str, tuple[str, str, int, int, dict[str, Any]]] = {}
        # (algo, param_set_id, algo_idx, param_idx, param_kwargs)

        from src.matching.parameter_spaces import CODEC_PARAM_SPACES

        for profile_id, info in raw.items():
            algo = info["algorithm_id"]
            param_set_id = info["parameter_set_id"]
            algo_idx = ALGORITHM_INDEX.get(algo, 0)

            # Find which parameter set this profile won by matching
            # the parameter_set_id hash with each candidate's hash.
            labels = self._all_labels_for_algo(algo)
            param_idx = 0
            param_kwargs: dict[str, Any] = {}

            from src.matching.grid_search import _parameter_set_id

            for i, label in enumerate(labels):
                params = self._params_for_label(algo, label)
                candidate_hash = _parameter_set_id(algo, params)
                if candidate_hash == param_set_id:
                    param_idx = i
                    param_kwargs = {k: v for k, v in params.items() if k != "label"}
                    break

            self._mapping[profile_id] = (algo, param_set_id, algo_idx, param_idx, param_kwargs)

    @staticmethod
    def _all_labels_for_algo(algo: str) -> list[str]:
        from src.matching.parameter_spaces import CODEC_PARAM_SPACES
        return [p.get("label", "") for p in CODEC_PARAM_SPACES.get(algo, [])]

    @staticmethod
    def _params_for_label(algo: str, label: str) -> dict[str, Any]:
        from src.matching.parameter_spaces import CODEC_PARAM_SPACES
        for p in CODEC_PARAM_SPACES.get(algo, []):
            if p.get("label") == label:
                return p
        return {}

    def lookup(self, profile_id: str) -> tuple[str, str]:
        """Return (algorithm_id, parameter_set_id) for a profile."""
        if profile_id in self._mapping:
            return self._mapping[profile_id][0], self._mapping[profile_id][1]
        # Fallback to default profile
        return self._mapping.get(DEFAULT_PROFILE, ("lzw", "lzw_bits12"))[:2]

    def lookup_params(self, profile_id: str) -> dict[str, Any]:
        """Return the parameter kwargs dict for encoding."""
        if profile_id in self._mapping:
            return self._mapping[profile_id][4]
        default = self._mapping.get(DEFAULT_PROFILE, None)
        return default[4] if default else {}

    def lookup_indices(self, profile_id: str) -> tuple[int, int]:
        """Return (algorithm_index, parameter_index) for header encoding."""
        if profile_id in self._mapping:
            return self._mapping[profile_id][2], self._mapping[profile_id][3]
        default = self._mapping.get(DEFAULT_PROFILE, ("lzw", "", 0, 0, {}))
        return default[2], default[3]

    def num_profiles(self) -> int:
        return len(self._mapping)

    def available_algorithm_indices(self) -> set[int]:
        return {v[2] for v in self._mapping.values()}

    def lookup_params_by_index(self, algo_idx: int, param_idx: int) -> dict[str, Any]:
        """Reverse-lookup parameter kwargs from (algo_idx, param_idx).

        Used by decompressor to reconstruct the correct decompression params.
        """
        from src.matching.parameter_spaces import CODEC_PARAM_SPACES, ALGORITHM_IDS

        algo_id = INDEX_TO_ALGORITHM.get(algo_idx)
        if algo_id is None:
            return {}
        space = CODEC_PARAM_SPACES.get(algo_id, [])
        if param_idx < len(space):
            return {k: v for k, v in space[param_idx].items() if k != "label"}
        return {}

    def lookup_params_for_algo(self, algorithm_id: str) -> dict[str, object]:
        """Get the default parameter dict for encoding."""
        from src.matching.parameter_spaces import CODEC_PARAM_SPACES
        space = CODEC_PARAM_SPACES.get(algorithm_id, [])
        if not space:
            return {}
        # Return first as default
        return {k: v for k, v in space[0].items() if k != "label"}
