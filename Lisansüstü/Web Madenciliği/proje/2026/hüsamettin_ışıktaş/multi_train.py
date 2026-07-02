"""Run all experiments: CN, MLP, GCN × all scales × all seeds."""

from __future__ import annotations

import logging
import sys
import time
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[1] if __file__.endswith(".py") else Path.cwd()
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from src.experiments.configs import ExperimentConfig, get_method_config
from src.experiments.runner import run_experiment

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    datefmt="%H:%M:%S",
)

METHODS = ["common_neighbors", "mlp", "gcn"]
SCALES = [0.1, 0.5, 1.0]
SEEDS = [42, 123, 456]
DEVICE = "cuda"
EPOCHS = 200  # override GCN default (400→200, matches working baseline)

total = len(METHODS) * len(SCALES) * len(SEEDS)
print(f"Starting {total} experiments ({len(METHODS)} methods × {len(SCALES)} scales × {len(SEEDS)} seeds)")
print(f"Device: {DEVICE}, Epochs: {EPOCHS}")
print("=" * 60)

t0 = time.monotonic()
completed = 0

for method in METHODS:
    hp = get_method_config(method)
    if method != "common_neighbors":
        hp["epochs"] = EPOCHS

    for scale in SCALES:
        for seed in SEEDS:
            config = ExperimentConfig(
                method_name=method,
                dataset_scale=scale,
                seed=seed,
                device=DEVICE,
                hyperparameters=hp,
            )
            result = run_experiment(config)
            test = result.get("metrics", {}).get("test", {})
            runtime = result.get("runtime_seconds", 0)
            completed += 1

            print(
                f"[{completed}/{total}] {method:20s} scale={scale:.1f} seed={seed:3d}  "
                f"hits@50={test.get('hits_at_50', 0):.4f}  hits@100={test.get('hits_at_100', 0):.4f}  "
                f"time={runtime:.0f}s"
            )

elapsed = time.monotonic() - t0
print("=" * 60)
print(f"Done! {completed}/{total} experiments in {elapsed:.0f}s ({elapsed/60:.1f} min)")
