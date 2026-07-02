"""Check which lzw param set each profile maps to."""
import json
from src.matching.parameter_spaces import CODEC_PARAM_SPACES, ALGORITHM_IDS
from src.matching.grid_search import _parameter_set_id

# All lzw param sets
lzw_params = CODEC_PARAM_SPACES["lzw"]
for p in lzw_params:
    h = _parameter_set_id("lzw", p)
    print(f"  {p['label']:15s} -> {h}  (max_bits={p.get('max_bits')})")

print()

# Load mapping
with open("artifacts/phase2/profile_algorithm_mapping.json") as f:
    mapping = json.load(f)

for pid, info in mapping.items():
    if info["algorithm_id"] == "lzw":
        print(f"  {pid} -> {info['parameter_set_id']}")
