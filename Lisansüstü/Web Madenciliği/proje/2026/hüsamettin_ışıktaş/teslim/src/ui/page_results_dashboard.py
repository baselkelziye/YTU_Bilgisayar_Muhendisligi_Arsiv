"""Results dashboard page with interactive Plotly charts."""

from __future__ import annotations

from collections import Counter

import plotly.express as px
import plotly.graph_objects as go

from src.experiments.paths import PLOTS_DIR, RAW_RESULTS_DIR
from src.experiments.results import load_results
from src.experiments.tracking import get_benchmark_status
from src.ui.common import require_streamlit
from src.vis.tables import make_best_results_table, make_summary_table


def _build_hits_bar_chart(rows: list[dict]) -> go.Figure:
    """Grouped bar chart: Hits@50 by method × split."""
    labels, methods, splits, hits = [], [], [], []
    for row in rows:
        m = row.get("method_name", "?")
        s = row.get("split", "?")
        h = row.get("hits_at_50")
        if h is not None:
            labels.append(f"{m} ({s})")
            methods.append(m)
            splits.append(s)
            hits.append(float(h))
    if not hits:
        return go.Figure()

    fig = px.bar(
        x=labels, y=hits, color=methods,
        text=[f"{h:.3f}" for h in hits],
        labels={"x": "", "y": "Hits@50"},
        title="Method Performance by Split",
        color_discrete_sequence=px.colors.qualitative.Set2,
    )
    fig.update_traces(textposition="outside", textfont_size=10)
    fig.update_layout(
        height=400, margin=dict(l=10, r=10, t=40, b=80),
        xaxis_tickangle=-30, showlegend=True,
    )
    return fig


def _build_scale_trend_chart(rows: list[dict]) -> go.Figure:
    """Line chart: Hits@50 vs scale, one line per method."""
    import pandas as pd

    df = pd.DataFrame(rows)
    if df.empty or "hits_at_50" not in df.columns:
        return go.Figure()

    test_df = df[df["split"] == "test"].copy()
    if test_df.empty:
        test_df = df[df["split"] == "valid"].copy()
    if test_df.empty:
        return go.Figure()

    test_df["hits_at_50"] = pd.to_numeric(test_df["hits_at_50"], errors="coerce")
    test_df["dataset_scale"] = pd.to_numeric(test_df["dataset_scale"], errors="coerce")
    test_df = test_df.dropna(subset=["hits_at_50", "dataset_scale"])

    fig = px.line(
        test_df, x="dataset_scale", y="hits_at_50", color="method_name",
        markers=True, text="hits_at_50",
        labels={"dataset_scale": "Dataset Scale", "hits_at_50": "Hits@50"},
        title="Hits@50 vs Dataset Scale (Test Split)",
        color_discrete_sequence=px.colors.qualitative.Set2,
    )
    fig.update_traces(texttemplate="%{text:.3f}", textposition="top center")
    fig.update_layout(
        height=400, margin=dict(l=10, r=10, t=40, b=20),
        xaxis=dict(tickmode="array", tickvals=sorted(test_df["dataset_scale"].unique())),
    )
    return fig


def _build_runtime_chart(rows: list[dict]) -> go.Figure:
    """Bar chart: runtime by method × scale."""
    records = []
    seen = set()
    for row in rows:
        key = (row.get("method_name", "?"), row.get("dataset_scale"))
        if key not in seen and row.get("runtime_seconds") is not None:
            seen.add(key)
            records.append(row)
    if not records:
        return go.Figure()

    labels = [f"{r.get('method_name','?')} (scale={r.get('dataset_scale')})" for r in records]
    runtimes = [float(r["runtime_seconds"]) for r in records]
    colors = [r.get("method_name", "?") for r in records]

    fig = px.bar(
        x=labels, y=runtimes, color=colors,
        text=[f"{t:.1f}s" for t in runtimes],
        labels={"x": "", "y": "Runtime (s)"},
        title="Runtime by Method",
        color_discrete_sequence=px.colors.qualitative.Set2,
    )
    fig.update_traces(textposition="outside", textfont_size=9)
    fig.update_layout(
        height=380, margin=dict(l=10, r=10, t=40, b=80),
        xaxis_tickangle=-30, showlegend=False,
    )
    return fig


def _build_loss_plot(selected_result: dict) -> go.Figure:
    """Interactive loss curve for one run."""
    losses = [float(v) for v in selected_result.get("losses", [])]
    if not losses:
        return go.Figure()

    fig = go.Figure()
    fig.add_trace(go.Scatter(
        x=list(range(1, len(losses) + 1)),
        y=losses,
        mode="lines",
        name="Training Loss",
        line=dict(color="#4e79a7", width=2),
    ))
    # Mark validation checkpoints
    val_metrics = selected_result.get("val_metrics", [])
    if val_metrics:
        val_epochs = [v.get("epoch", 0) for v in val_metrics if v.get("epoch")]
        val_hits = [v.get("valid_hits_at_50", 0) for v in val_metrics if v.get("valid_hits_at_50") is not None]
        if val_epochs and val_hits:
            fig.add_trace(go.Scatter(
                x=val_epochs, y=[losses[min(e-1, len(losses)-1)] for e in val_epochs],
                mode="markers+text",
                name="Val. Checkpoint",
                text=[f"hits@50={h:.3f}" for h in val_hits],
                textposition="top center",
                textfont=dict(size=9),
                marker=dict(color="#e15759", size=8, symbol="diamond"),
            ))

    fig.update_layout(
        title="Training Loss Curve",
        xaxis_title="Epoch",
        yaxis_title="Loss",
        height=380,
        margin=dict(l=10, r=10, t=40, b=20),
        hovermode="x unified",
    )
    return fig


def render_results_dashboard() -> None:
    """Render saved metrics with interactive Plotly charts."""
    st = require_streamlit()

    # ── Live benchmark status ────────────────────────────────────────────
    try:
        bm_status = get_benchmark_status()
        if bm_status.get("running_benchmarks"):
            st.info(
                f"▶ **Canlı benchmark çalışıyor** "
                f"({len(bm_status['running_benchmarks'])} process)"
            )
            summary = bm_status.get("summary", {})
            if summary:
                prog_data = []
                for key, val in summary.items():
                    if val["runs"] > 0:
                        prog_data.append({
                            "Yöntem": val["method"],
                            "Scale": val["scale"],
                            "Tamamlanan": val["runs"],
                            "Ort. Hits@50": val["avg_hits@50"],
                            "En İyi Hits@50": val["max_hits@50"],
                        })
                if prog_data:
                    st.dataframe(prog_data, use_container_width=True, hide_index=True)
    except Exception:
        pass

    results = load_results(RAW_RESULTS_DIR, max_results=27)
    if not results:
        st.warning("Henüz kaydedilmiş sonuç bulunamadı.")
        return

    all_rows = make_summary_table(results)
    methods = sorted({str(r.get("method_name")) for r in results if r.get("method_name")})
    scales = sorted({float(r.get("dataset_scale")) for r in results if r.get("dataset_scale") is not None})
    statuses = sorted({str(r.get("status")) for r in results if r.get("status")})
    splits = sorted({str(r.get("split")) for r in all_rows if r.get("split")})
    seeds = sorted({int(r.get("seed")) for r in results if r.get("seed") is not None})

    # --- Filters ---
    with st.expander("Filtreler", expanded=False):
        fc1, fc2, fc3 = st.columns(3)
        selected_methods = fc1.multiselect("Yöntem", methods, default=methods)
        selected_splits = fc2.multiselect("Split", splits, default=splits)
        selected_statuses = fc3.multiselect("Durum", statuses, default=statuses)

        fc4, fc5 = st.columns(2)
        selected_scales = fc4.multiselect("Scale", scales, default=scales)
        selected_seeds = fc5.multiselect("Seed", seeds, default=seeds)

    filtered = [
        r for r in results
        if r.get("method_name") in selected_methods
        and r.get("status") in selected_statuses
        and float(r.get("dataset_scale")) in selected_scales
        and int(r.get("seed")) in selected_seeds
    ]
    filtered_rows = [
        row for row in make_summary_table(filtered)
        if row.get("split") in selected_splits
    ]

    if not filtered_rows:
        st.warning("Filtrelere uygun sonuç bulunamadı.")
        return

    # --- KPI cards ---
    test_rows = [r for r in filtered_rows if r.get("split") == "test"]
    kpi_rows = test_rows if test_rows else filtered_rows
    best_hits = max(
        (float(r["hits_at_50"]) for r in kpi_rows if r.get("hits_at_50") is not None),
        default=0.0,
    )
    fastest = min(
        (float(r["runtime_seconds"]) for r in filtered if r.get("runtime_seconds") is not None),
        default=0.0,
    )
    min_mem = min(
        (float(r["memory_mb"]) for r in filtered if r.get("memory_mb") is not None),
        default=0.0,
    )

    mc = st.columns(4)
    mc[0].metric("En İyi Hits@50", f"{best_hits:.4f}")
    mc[1].metric("En Hızlı (sn)", f"{fastest:.2f}")
    mc[2].metric("En Düşük Bellek (MB)", f"{min_mem:.2f}")
    mc[3].metric("Görüntülenen Satır", len(filtered_rows))

    # --- Charts row ---
    chart_col1, chart_col2 = st.columns(2)
    with chart_col1:
        hit_fig = _build_hits_bar_chart(filtered_rows)
        st.plotly_chart(hit_fig, use_container_width=True)

    with chart_col2:
        scale_fig = _build_scale_trend_chart(filtered_rows)
        st.plotly_chart(scale_fig, use_container_width=True)

    runtime_fig = _build_runtime_chart(filtered_rows)
    st.plotly_chart(runtime_fig, use_container_width=True)

    # --- Results table ---
    st.subheader("Sonuç Tablosu")
    st.dataframe(filtered_rows, use_container_width=True, hide_index=True)

    # --- Best rows ---
    st.subheader("En İyi Sonuçlar (Yöntem × Scale)")
    preferred_split = selected_splits[0] if selected_splits else "test"
    best_rows = make_best_results_table(filtered, split=preferred_split)
    st.dataframe(best_rows, use_container_width=True, hide_index=True)

    # --- Loss curve ---
    runs_with_losses = [r for r in filtered if r.get("losses")]
    if runs_with_losses:
        st.subheader("Loss Eğrisi")
        labels = [
            f"{r.get('method_name')} | scale={r.get('dataset_scale')} | seed={r.get('seed')} | {r.get('timestamp','')}"
            for r in runs_with_losses
        ]
        selected_label = st.selectbox("Çalıştırma Seç", labels, label_visibility="collapsed")
        selected_result = runs_with_losses[labels.index(selected_label)]
        loss_fig = _build_loss_plot(selected_result)
        st.plotly_chart(loss_fig, use_container_width=True)

    # --- Static plots fallback ---
    static_plots = sorted(PLOTS_DIR.glob("*.png"))
    if static_plots:
        st.subheader("Kaydedilmis Grafikler")
        for plot_path in static_plots:
            st.image(str(plot_path), caption=plot_path.name)
