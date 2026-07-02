# Implementation Plan

This document defines the phased implementation plan for the `ogbl-collab` link
prediction project. It should be followed together with `ARC.md`.

The main principle is to build the project from a small working pipeline toward
the full proposal scope. Each phase should leave the repository in a runnable
state.

## Phase 0: Project Skeleton and Conventions

Goal: make the repository structure explicit and prepare the basic files before
implementing model logic.

Code to write:

- Create package marker files where needed:
  - `src/__init__.py`
  - `src/data/__init__.py`
  - `src/methods/__init__.py`
  - `src/evaluation/__init__.py`
  - `src/experiments/__init__.py`
  - `src/ui/__init__.py`
  - `src/vis/__init__.py`
- Create result folders:
  - `results/raw/`
  - `results/plots/`
- Add a dependency file:
  - `requirements.txt`
- Add project path constants:
  - `src/experiments/paths.py`

Expected outcome:

- The project has a clean importable Python package structure.
- All generated outputs have a documented target location.
- The codebase follows `snake_case` naming from the first implementation step.

## Phase 1: Dataset Loading and Preprocessing

Goal: isolate all `ogbl-collab` loading and preprocessing behind a stable
project interface.

Code to write:

- `src/data/loader.py`
  - `load_collab_dataset()`
  - `load_edge_split()`
  - `load_collab_data_bundle()`
- `src/data/preprocessing.py`
  - `make_undirected_edge_index()`
  - `build_adjacency()`
  - `sample_edges_by_scale()`
  - `make_scaled_split()`

Design notes:

- Use the installed `ogb` package, not the local `ogb/` source tree.
- Return a project-level data object or dictionary so the rest of the project
  does not depend directly on raw OGB internals.
- Support dataset scales: `0.1`, `0.5`, and `1.0`.
- Keep validation and test negative edges compatible with the official OGB
  evaluator.

Expected outcome:

- A small script can load `ogbl-collab`, print node/edge counts, and produce
  scaled train splits.
- Dataset loading is reusable by all methods.

## Phase 2: Evaluation and Measurement Utilities

Goal: create shared evaluation and measurement utilities before implementing
multiple algorithms.

Code to write:

- `src/evaluation/metrics.py`
  - `compute_hits_at_k()`
  - `compute_hits_at_50()`
  - `evaluate_link_prediction()`
- `src/evaluation/runtime.py`
  - `measure_runtime()`
  - `get_memory_usage_mb()`
  - optional context manager for timed experiment blocks

Design notes:

- Wrap the official OGB `Evaluator` in one place.
- Standardize metric keys:
  - `hits_at_10`
  - `hits_at_50`
  - `hits_at_100`
- Runtime values should use seconds.
- Memory values should use megabytes.

Expected outcome:

- Any method can provide positive and negative edge scores and receive a shared
  metric dictionary.
- Runtime and memory fields can be added to every result.

## Phase 3: Common Neighbors Baseline

Goal: implement the classical structural baseline first because it has no model
training dependency.

Code to write:

- `src/methods/common_neighbors.py`
  - `fit_common_neighbors()`
  - `score_edges_common_neighbors()`
  - `run_common_neighbors()`

Design notes:

- Use graph topology only.
- Do not use node features.
- Build scores from the train graph adjacency.
- Score validation and test positive/negative edges with the same function.
- Add deterministic tie handling if needed, because ranking metrics are
  sensitive to equal scores.

Expected outcome:

- Common Neighbors can run on at least the 10% scale.
- It produces official `Hits@50`, runtime, and memory values.
- It establishes the result format for later methods.

## Phase 4: MLP Baseline

Goal: implement the feature-only learned baseline using node features and no
message passing.

Code to write:

- `src/methods/mlp.py`
  - `MlpLinkPredictor`
  - `train_mlp_epoch()`
  - `score_edges_mlp()`
  - `run_mlp()`

Design notes:

- Use node features from `ogbl-collab`.
- Combine edge endpoint features with element-wise multiplication.
- Train with positive train edges and sampled negative edges.
- Keep hyperparameters configurable:
  - `hidden_channels`
  - `num_layers`
  - `dropout`
  - `learning_rate`
  - `batch_size`
  - `epochs`

Expected outcome:

- MLP can run end-to-end on 10% scale.
- MLP produces the same result schema as Common Neighbors.
- Validation score can be used to select the best epoch.

## Phase 5: GCN Model

Goal: implement the graph neural network method using graph structure and node
features.

Code to write:

- `src/methods/gcn.py`
  - `GcnEncoder`
  - `GcnLinkPredictor`
  - `train_gcn_epoch()`
  - `score_edges_gcn()`
  - `run_gcn()`

Design notes:

- Use PyTorch Geometric layers such as `GCNConv`.
- Keep the implementation independent from copied OGB example scripts.
- Use the training graph for message passing.
- Decide explicitly whether validation edges are included at test inference
  time; document the choice in the result config.
- Keep GPU/CPU device handling centralized and explicit.

Expected outcome:

- GCN can run end-to-end on 10% scale.
- GCN produces the same result schema as Common Neighbors and MLP.
- The method can later be scaled to 50% and 100% after resource checks.

## Phase 6: Experiment Configuration and Runner

Goal: make experiments reproducible and runnable from a single interface.

Code to write:

- `src/experiments/configs.py`
  - `ExperimentConfig`
  - `get_default_config()`
  - `get_method_config()`
- `src/experiments/runner.py`
  - `run_experiment()`
  - `run_all_methods_for_scale()`
  - `run_full_benchmark()`
- `src/experiments/results.py`
  - `save_result()`
  - `load_results()`
  - `aggregate_results()`

Design notes:

- Every saved result should include:
  - method name
  - dataset name
  - dataset scale
  - seed
  - hyperparameters
  - metric values
  - runtime seconds
  - memory megabytes
  - device
  - timestamp
  - status
- Save raw results under `results/raw/`.
- Prefer JSON for per-run outputs and CSV for aggregate summaries.

Expected outcome:

- One function call can run a method at a selected dataset scale.
- A full benchmark can run all three methods across selected scales.
- Results can be loaded without rerunning experiments.

## Phase 7: Command-Line Entry Points

Goal: expose the experiment pipeline through clean command-line interfaces.

Code to write:

- `src/train.py`
  - argument parsing for method, scale, epochs, device, seed, and output path
  - call `run_experiment()`
- `main.py`
  - top-level routing for training and dashboard commands

Example commands to support:

```bash
python src/train.py --method common_neighbors --scale 0.1
python src/train.py --method mlp --scale 0.1 --epochs 20
python src/train.py --method gcn --scale 0.1 --epochs 20
python main.py train --method mlp --scale 0.5
```

Expected outcome:

- Experiments can be run without opening Streamlit.
- The CLI becomes the reliable backend for the dashboard.

## Phase 8: Visualization Code

Goal: generate reusable plots from saved experiment results.

Code to write:

- `src/vis/plots.py`
  - `plot_hits_comparison()`
  - `plot_runtime_comparison()`
  - `plot_memory_comparison()`
  - `save_all_plots()`
- `src/vis/tables.py`
  - `make_summary_table()`
  - `make_best_results_table()`

Design notes:

- Visualization code reads from `results/raw/`.
- Generated figures are saved to `results/plots/`.
- Plot filenames should use `snake_case`.
- Do not put generated images inside `src/vis/`.

Expected outcome:

- Method comparison plots can be generated from saved results.
- Runtime and memory trade-offs can be visualized for the final report.

## Phase 9: Streamlit Dashboard

Goal: build the interactive GUI promised in the proposal.

Code to write:

- `src/ui/app.py`
  - Streamlit app setup and page routing
- `src/ui/pages.py`
  - Dataset Manager page
  - Algorithm Runner page
  - Results Dashboard page
- `src/dash.py`
  - thin launcher for `src/ui/app.py`

Dashboard screens:

- Dataset Manager
  - show dataset statistics
  - show selected scale
  - show available splits
- Algorithm Runner
  - select method
  - select dataset scale
  - select basic hyperparameters
  - trigger a run or show the exact CLI command
- Results Dashboard
  - show metric table
  - show Hits@50 comparison
  - show runtime and memory plots

Expected outcome:

- The project can be demonstrated from a Streamlit interface.
- Dashboard logic stays separate from model and evaluation logic.

## Phase 10: Full Benchmark and Report Assets

Goal: run the final experiments and produce assets for the course report.

Code to run:

- Common Neighbors at 10%, 50%, and 100%.
- MLP at 10%, 50%, and 100%, if runtime allows.
- GCN at 10%, 50%, and 100%, if GPU memory allows.

Outputs to produce:

- `results/raw/summary.csv`
- `results/plots/hits_at_50_comparison.png`
- `results/plots/runtime_comparison.png`
- `results/plots/memory_comparison.png`

Report questions to answer:

- Does graph structure alone perform competitively?
- How much do node features help in the MLP baseline?
- How much does message passing improve over the feature-only MLP?
- What is the runtime and memory cost of each method?
- How do results change from 10% to 50% to 100% scale?

Expected outcome:

- Final benchmark results are reproducible.
- Report-ready tables and plots are available.

## Phase 11: Validation and Cleanup

Goal: make sure the implementation is stable, documented, and easy to run.

Code and documentation to finalize:

- `README.md` usage instructions.
- Installation instructions.
- Dataset download notes.
- Example CLI commands.
- Streamlit launch command.
- Known limitations.

Checks to perform:

- Import check for all modules.
- Run Common Neighbors on 10% scale.
- Run MLP smoke test with a very small epoch count.
- Run GCN smoke test with a very small epoch count.
- Confirm all generated outputs go under `results/`.
- Confirm no code imports from the local `ogb/` source tree.

Expected outcome:

- The project is ready for demonstration and report writing.
- The repository structure matches `ARC.md`.
