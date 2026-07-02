Uv is installed in the system. Use uv and .venv python for any compile or lint test

# Architecture Guide

This document defines the project architecture and coding conventions for the
`ogbl-collab` link prediction project.

The project should remain independent from the local `ogb/` GitHub source tree.
We may use it as a reference while designing the implementation, but project
code must not directly import from local example scripts or copy their structure
as-is. Runtime code should use the installed `ogb` package APIs where needed.

## Project Goal

The project compares three link prediction approaches on the `ogbl-collab`
dataset:

- Common Neighbors as a structural baseline.
- MLP as a feature-only learned baseline.
- GCN as a graph neural network using both node features and graph structure.

All methods should be evaluated with the official OGB evaluation protocol,
with `Hits@50` as the primary metric. Runtime and memory usage should also be
tracked for dataset scales such as 10%, 50%, and 100%.

## Directory Layout

```text
.
├── main.py
├── ARC.md
├── src/
│   ├── train.py
│   ├── dash.py
│   ├── data/
│   ├── methods/
│   ├── evaluation/
│   ├── experiments/
│   ├── ui/
│   └── vis/
└── results/
    ├── raw/
    └── plots/
```

## Entry Points

### `main.py`

The root `main.py` is the top-level project entry point. It should stay thin and
delegate real work to modules under `src/`.

Recommended responsibilities:

- Parse a high-level command or mode.
- Call training, evaluation, or dashboard entry points.
- Avoid containing model, dataset, metric, or plotting logic directly.

### `src/train.py`

`src/train.py` is the command-line training entry point.

Recommended responsibilities:

- Parse experiment arguments.
- Select method, dataset scale, device, and hyperparameters.
- Call the experiment runner.
- Save structured outputs under `results/raw/`.

### `src/dash.py`

`src/dash.py` can remain as a short compatibility entry point for launching the
Streamlit dashboard. The main dashboard implementation should live under
`src/ui/`.

## Source Modules

### `src/data/`

Dataset loading and preprocessing code belongs here.

Recommended files:

- `loader.py`: load `ogbl-collab`, obtain train/validation/test splits, and
  expose a stable project-level dataset interface.
- `preprocessing.py`: build adjacency structures, prepare node features, and
  create scaled subsets for 10%, 50%, and 100% experiments.

Rules:

- OGB dataset APIs should be isolated here as much as possible.
- Other modules should not need to know the internal format returned by OGB.

### `src/methods/`

Algorithm implementations belong here.

Recommended files:

- `common_neighbors.py`
- `mlp.py`
- `gcn.py`

Rules:

- Each method should expose a consistent interface for training and scoring
  edges.
- Method modules should return prediction scores, not compute final report
  tables or dashboard charts.
- Do not copy OGB example scripts directly. Use them only as behavioral
  references.

### `src/evaluation/`

Metric and measurement code belongs here.

Recommended files:

- `metrics.py`: wrap the official OGB `Evaluator` and compute `Hits@50`.
- `runtime.py`: measure runtime and memory usage for each experiment.

Rules:

- The official OGB evaluator should be used for final metric reporting.
- Evaluation logic should be shared by all methods.

### `src/experiments/`

Experiment orchestration belongs here.

Recommended files:

- `configs.py`: define method defaults, dataset scales, and hyperparameter
  presets.
- `runner.py`: run one experiment from a config.
- `results.py`: save and load structured experiment outputs.

Rules:

- This layer coordinates data, methods, and evaluation.
- Results should be serialized in a stable format such as JSON or CSV.
- Experiment outputs should include config, metrics, runtime, memory, and status.

### `src/ui/`

Streamlit application code belongs here.

Recommended files:

- `app.py`: main Streamlit app.
- `pages.py`: dashboard screens such as Dataset Manager, Algorithm Runner, and
  Results Dashboard.

Rules:

- UI code should read results from `results/raw/` and plots from
  `results/plots/`.
- UI code should not duplicate training or evaluation logic.

### `src/vis/`

Visualization code belongs here.

Recommended files:

- `plots.py`: reusable chart creation functions.
- `tables.py`: formatting helpers for result summaries.

Rules:

- `src/vis/` contains code that creates visualizations.
- Generated image files must not be stored in `src/vis/`.
- Plot outputs should be written to `results/plots/`.

## Results Layout

### `results/raw/`

Raw experiment outputs belong here.

Examples:

- Per-run JSON files.
- Aggregated CSV files.
- Training histories.
- Runtime and memory logs.

### `results/plots/`

Generated visual outputs belong here.

Examples:

- Method comparison charts.
- Dataset scale comparison charts.
- Runtime and memory usage charts.

## Naming Conventions

Use `snake_case` everywhere unless a library requires another style.

Examples:

- Files: `common_neighbors.py`, `experiment_runner.py`
- Functions: `load_collab_dataset()`, `run_experiment()`
- Variables: `hidden_channels`, `dataset_scale`
- Result keys: `hits_at_50`, `runtime_seconds`, `memory_mb`

Avoid:

- `camelCase`
- `PascalCase` for functions or variables
- Mixed naming styles in result files

Exception:

- Classes should use `PascalCase`, such as `ExperimentConfig` or
  `LinkPredictor`.

## Coding Rules

- Keep modules small and focused on one responsibility.
- Prefer explicit configuration objects or dictionaries over hidden globals.
- Keep entry points thin; put reusable logic inside modules.
- Use type hints for public functions where practical.
- Use docstrings for non-trivial public functions and classes.
- Avoid hard-coded paths outside a small shared path/config utility.
- Do not store generated outputs inside `src/`.
- Do not import from the local `ogb/` source tree.
- Do not depend on copied OGB example scripts.
- Prefer reproducible experiments: store seed, method name, dataset scale,
  hyperparameters, metric values, runtime, and memory with each result.

## Dependency Direction

The preferred dependency flow is:

```text
main.py / src/train.py / src/dash.py
        ↓
src/experiments/
        ↓
src/data/ + src/methods/ + src/evaluation/
        ↓
src/vis/ and results/
```

The dashboard may read saved results and call experiment runners, but it should
not own core training, metric, or preprocessing logic.
