"""Algorithm runner page — supports single or all-methods comparison."""

from __future__ import annotations

from typing import Any

from src.experiments.configs import (
    SUPPORTED_METHODS,
    SUPPORTED_SCALES,
    ExperimentConfig,
    get_method_config,
)
from src.experiments.runner import run_experiment
from src.experiments.runtime_config import configure_logging, suppress_known_warnings
from src.ui.common import RUNNER_PRESETS, require_streamlit


def _command_for_runner(
    method_name: str,
    dataset_scale: float,
    seed: int,
    device: str,
    hyperparameters: dict[str, Any],
    save_result: bool,
) -> str:
    parts = [
        "python src/train.py",
        f"--method {method_name}",
        f"--scale {dataset_scale}",
        f"--seed {seed}",
        f"--device {device}",
    ]
    if method_name == "common_neighbors":
        if not hyperparameters.get("add_tie_breaker", True):
            parts.append("--disable-tie-breaker")
        if not hyperparameters.get("make_undirected", True):
            parts.append("--directed")
    else:
        parts.extend(
            [
                f"--epochs {hyperparameters['epochs']}",
                f"--batch-size {hyperparameters['batch_size']}",
                f"--hidden-channels {hyperparameters['hidden_channels']}",
                f"--num-layers {hyperparameters['num_layers']}",
                f"--dropout {hyperparameters['dropout']}",
                f"--learning-rate {hyperparameters['learning_rate']}",
            ]
        )
    if not save_result:
        parts.append("--no-save")
    return " ".join(parts)


def _run_single_experiment(
    method_name: str,
    dataset_scale: float,
    seed: int,
    device: str,
    save_result: bool,
    hyperparameters: dict[str, Any],
) -> dict[str, Any] | None:
    """Run a single experiment and return the result."""
    config = ExperimentConfig(
        method_name=method_name,
        dataset_scale=dataset_scale,
        seed=seed,
        device=device,
        save_result=save_result,
        hyperparameters=dict(hyperparameters),
    )
    configure_logging()
    suppress_known_warnings()
    try:
        return run_experiment(config)
    except Exception as error:
        return {"method_name": method_name, "status": f"failed: {error}"}


def render_algorithm_runner() -> None:
    """Render a command builder for experiment runs with single and all-methods mode."""
    st = require_streamlit()

    st.header("Algorithm Runner & Comparator")

    run_mode = st.radio(
        "Run Mode",
        ["Single Method", "All Three Methods (Comparison)"],
        horizontal=True,
    )

    with st.form("algorithm_runner_form"):
        col1, col2, col3 = st.columns(3)
        if run_mode == "Single Method":
            method_name = col1.selectbox("Method", SUPPORTED_METHODS)
        else:
            method_name = col1.selectbox(
                "Method (for hyperparameter preview)",
                SUPPORTED_METHODS,
                index=2,
                help="Select a method to see its default hyperparameters below. All three will be run.",
            )
        dataset_scale = float(col2.selectbox("Dataset scale", SUPPORTED_SCALES))
        preset = col3.selectbox("Preset", tuple(RUNNER_PRESETS))

        col4, col5 = st.columns(2)
        seed = int(col4.number_input("Seed", min_value=0, value=42, step=1))
        device = col5.selectbox("Device", ("cpu", "cuda", "cuda:0"))
        save_result = st.checkbox("Save result JSON under results/raw/", value=True)

        # Show hyperparameters for the selected method
        hyperparameters = get_method_config(method_name)
        hyperparameters.update(RUNNER_PRESETS[preset])

        if method_name == "common_neighbors":
            tie_breaker = st.checkbox(
                "Use deterministic tie breaker",
                value=bool(hyperparameters.get("add_tie_breaker", True)),
            )
            undirected = st.checkbox(
                "Treat graph as undirected",
                value=bool(hyperparameters.get("make_undirected", True)),
            )
            hyperparameters["add_tie_breaker"] = tie_breaker
            hyperparameters["make_undirected"] = undirected
        else:
            pcol1, pcol2, pcol3 = st.columns(3)
            hyperparameters["epochs"] = int(
                pcol1.number_input(
                    "Epochs",
                    min_value=1,
                    value=int(hyperparameters["epochs"]),
                    step=1,
                )
            )
            hyperparameters["batch_size"] = int(
                pcol2.number_input(
                    "Batch size",
                    min_value=32,
                    value=int(hyperparameters["batch_size"]),
                    step=32,
                )
            )
            hyperparameters["hidden_channels"] = int(
                pcol3.number_input(
                    "Hidden channels",
                    min_value=16,
                    value=int(hyperparameters["hidden_channels"]),
                    step=16,
                )
            )

            pcol4, pcol5, pcol6 = st.columns(3)
            hyperparameters["num_layers"] = int(
                pcol4.number_input(
                    "Num layers",
                    min_value=1,
                    value=int(hyperparameters["num_layers"]),
                    step=1,
                )
            )
            hyperparameters["dropout"] = float(
                pcol5.number_input(
                    "Dropout",
                    min_value=0.0,
                    max_value=0.9,
                    value=float(hyperparameters["dropout"]),
                    step=0.05,
                    format="%.2f",
                )
            )
            hyperparameters["learning_rate"] = float(
                pcol6.number_input(
                    "Learning rate",
                    min_value=0.00001,
                    max_value=1.0,
                    value=float(hyperparameters["learning_rate"]),
                    step=0.0005,
                    format="%.5f",
                )
            )

        if run_mode == "Single Method":
            run_requested = st.form_submit_button("Run Experiment", type="primary")
        else:
            run_requested = st.form_submit_button(
                "Run All Three Methods", type="primary"
            )

    # ── Single method mode ────────────────────────────────────────────────
    if run_mode == "Single Method" and run_requested:
        config = ExperimentConfig(
            method_name=method_name,
            dataset_scale=dataset_scale,
            seed=seed,
            device=device,
            save_result=save_result,
            hyperparameters=hyperparameters,
        )
        configure_logging()
        suppress_known_warnings()

        with st.spinner("Experiment çalışıyor... Bu işlem methoda göre zaman alabilir."):
            try:
                result = run_experiment(config)
            except Exception as error:
                st.error(f"Run başarısız: {error}")
                st.exception(error)
                return

        st.success("Run tamamlandı.")
        status_col1, status_col2, status_col3, status_col4 = st.columns(4)
        status_col1.metric("Method", str(result.get("method_name", "-")))
        status_col2.metric("Scale", str(result.get("dataset_scale", "-")))
        status_col3.metric("Status", str(result.get("status", "-")))
        runtime_value = result.get("runtime_seconds")
        status_col4.metric(
            "Runtime (s)",
            f"{float(runtime_value):.2f}" if runtime_value is not None else "-",
        )

        if result.get("metrics"):
            st.subheader("Run Metrics")
            st.json(result["metrics"])

        if result.get("result_path"):
            st.caption(f"Saved result: {result['result_path']}")

    # ── All three methods mode ────────────────────────────────────────────
    if run_mode == "All Three Methods (Comparison)" and run_requested:
        configure_logging()
        suppress_known_warnings()
        st.info(
            "Running Common Neighbors, MLP, and GCN sequentially "
            f"at scale={dataset_scale}, seed={seed}, device={device}. "
            "This may take a while depending on the scale and device."
        )

        all_results: list[dict[str, Any]] = []
        progress_bar = st.progress(0, text="Başlıyor...")

        for idx, method in enumerate(SUPPORTED_METHODS):
            method_hparams = get_method_config(method)
            # Apply shared settings (epochs, batch_size) from UI for MLP/GCN
            if method != "common_neighbors":
                if "epochs" in hyperparameters:
                    method_hparams["epochs"] = hyperparameters["epochs"]
                if "batch_size" in hyperparameters:
                    method_hparams["batch_size"] = hyperparameters["batch_size"]
                if "hidden_channels" in hyperparameters:
                    method_hparams["hidden_channels"] = hyperparameters["hidden_channels"]
                if "num_layers" in hyperparameters:
                    method_hparams["num_layers"] = hyperparameters["num_layers"]
                if "dropout" in hyperparameters:
                    method_hparams["dropout"] = hyperparameters["dropout"]
                if "learning_rate" in hyperparameters:
                    method_hparams["learning_rate"] = hyperparameters["learning_rate"]
            else:
                method_hparams["add_tie_breaker"] = hyperparameters.get(
                    "add_tie_breaker", True
                )
                method_hparams["make_undirected"] = hyperparameters.get(
                    "make_undirected", True
                )

            progress_bar.progress(
                (idx) / len(SUPPORTED_METHODS),
                text=f"{method} çalışıyor... ({idx + 1}/{len(SUPPORTED_METHODS)})",
            )

            result = _run_single_experiment(
                method_name=method,
                dataset_scale=dataset_scale,
                seed=seed,
                device=device,
                save_result=save_result,
                hyperparameters=method_hparams,
            )
            all_results.append(result)

        progress_bar.progress(1.0, text="Tamamlandı!")

        st.success("Tüm methodlar tamamlandı.")
        st.subheader("Karşılaştırma Tablosu")

        comparison_data = []
        for result in all_results:
            if result is None:
                continue
            metrics = result.get("metrics", {})
            test_metrics = metrics.get("test", {}) if isinstance(metrics, dict) else {}
            valid_metrics = metrics.get("valid", {}) if isinstance(metrics, dict) else {}

            comparison_data.append(
                {
                    "Method": str(result.get("method_name", "-")),
                    "Status": str(result.get("status", "-")),
                    "Hits@50 (test)": f"{test_metrics.get('hits_at_50', 0):.4f}",
                    "Hits@100 (test)": f"{test_metrics.get('hits_at_100', 0):.4f}",
                    "Hits@50 (valid)": f"{valid_metrics.get('hits_at_50', 0):.4f}",
                    "Runtime (s)": f"{result.get('runtime_seconds', 0):.2f}",
                    "Memory (MB)": f"{result.get('memory_mb', 0):.0f}",
                }
            )

        if comparison_data:
            st.dataframe(comparison_data, use_container_width=True, hide_index=True)

        # Detailed results expander
        for result in all_results:
            if result is None:
                continue
            method = result.get("method_name", "?")
            with st.expander(f"{method} — Detaylı Sonuç", expanded=False):
                st.json(result.get("metrics", {}))
                if result.get("result_path"):
                    st.caption(f"Kaydedilen dosya: {result['result_path']}")

    # ── CLI commands display ──────────────────────────────────────────────
    if run_mode == "Single Method":
        train_command = _command_for_runner(
            method_name=method_name,
            dataset_scale=dataset_scale,
            seed=seed,
            device=device,
            hyperparameters=hyperparameters,
            save_result=save_result,
        )
        root_command = train_command.replace(
            "python src/train.py", "python main.py train", 1
        )

        with st.expander("CLI commands", expanded=False):
            st.subheader("CLI command")
            st.code(train_command, language="bash")
            st.caption("Direct training entry point.")

            st.subheader("Root CLI equivalent")
            st.code(root_command, language="bash")
            st.caption(
                "Convenient when you prefer single top-level entrypoint commands."
            )
