"""Debug profile_lookup lzw parameter resolution."""
import sys, json
sys.path.insert(0, '.')
from src.compression.profile_lookup import ProfileLookup
from pathlib import Path

lookup = ProfileLookup(Path("artifacts/phase2/profile_algorithm_mapping.json"))

for pid in ["profile_3", "profile_5", "profile_7"]:
    algo, param_set = lookup.lookup(pid)
    params = lookup.lookup_params(pid)
    print(f"{pid}: algo={algo}, param_set={param_set}, params={params}")
