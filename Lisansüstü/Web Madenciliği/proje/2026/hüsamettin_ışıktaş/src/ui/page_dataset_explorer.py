"""Kapsamlı veri seti keşif sayfası — sunum odaklı."""

from __future__ import annotations

import gzip
import csv
from collections import Counter
from functools import lru_cache
from pathlib import Path
from typing import Any

import matplotlib.pyplot as plt
import numpy as np
import plotly.express as px
import plotly.graph_objects as go

from src.data.loader import load_collab_data_bundle
from src.data.preprocessing import build_adjacency, iter_edge_pairs
from src.experiments.paths import DATASET_DIR
from src.ui.common import require_streamlit, safe_len, split_count_rows


RAW_DIR = Path(DATASET_DIR) / "ogbl_collab" / "raw"


@lru_cache(maxsize=1)
def _read_raw_csv(filename: str) -> list[list[str]]:
    """Read a gzipped CSV from the raw dataset directory."""
    with gzip.open(RAW_DIR / filename, "rt") as f:
        return list(csv.reader(f))


@lru_cache(maxsize=1)
def _edge_years() -> list[int]:
    return [int(r[0]) for r in _read_raw_csv("edge_year.csv.gz")]


@lru_cache(maxsize=1)
def _edge_weights() -> list[int]:
    return [int(r[0]) for r in _read_raw_csv("edge_weight.csv.gz")]


@lru_cache(maxsize=1)
def _node_features() -> np.ndarray:
    feats = [[float(v) for v in r] for r in _read_raw_csv("node-feat.csv.gz")]
    return np.array(feats, dtype=np.float32)


@lru_cache(maxsize=1)
def _degree_distribution() -> tuple[list[int], list[int]]:
    """Return sorted (node_id, degree) from training edges."""
    bundle = load_collab_data_bundle()
    train_edges = bundle.split_edge["train"]["edge"]
    adjacency = build_adjacency(train_edges, make_undirected=True)
    degrees = [(nid, len(neighbors)) for nid, neighbors in adjacency.items()]
    degrees.sort(key=lambda x: x[1], reverse=True)
    node_ids = [d[0] for d in degrees]
    degree_vals = [d[1] for d in degrees]
    return node_ids, degree_vals


def _plot_degree_distribution(degrees: list[int]) -> Any:
    """Log-log degree distribution histogram."""
    if not degrees:
        return None
    deg_counter = Counter(degrees)
    sorted_degs = sorted(deg_counter)
    counts = [deg_counter[d] for d in sorted_degs]

    fig = go.Figure()
    fig.add_trace(go.Scatter(
        x=sorted_degs, y=counts, mode="markers+lines",
        marker=dict(size=5, color="#4e79a7"),
        line=dict(width=1.5, color="#4e79a7"),
        name="Derece dağılımı",
    ))
    fig.update_layout(
        title="Derece Dağılımı (Log-Log)",
        xaxis_title="Derece (komşu sayısı)",
        yaxis_title="Node sayısı",
        xaxis_type="log",
        yaxis_type="log",
        template="plotly_white",
        height=450,
        margin=dict(l=40, r=20, t=50, b=40),
    )
    return fig


def _plot_weight_distribution(weights: list[int]) -> Any:
    """Edge weight (ortak makale sayisi) dagilimi."""
    wc = Counter(weights)
    sorted_w = sorted(wc)

    fig = go.Figure()
    fig.add_trace(go.Bar(
        x=sorted_w, y=[wc[w] for w in sorted_w],
        marker_color="#59a14f", name="Edge sayisi",
        text=[wc[w] for w in sorted_w], textposition="outside",
    ))
    fig.update_layout(
        title="Edge Ağırlık Dağılımı (Ortak Makale Sayısı)",
        xaxis_title="Ağırlık (birlikte yazılan makale sayısı)",
        yaxis_title="Edge sayısı",
        template="plotly_white",
        height=400,
        margin=dict(l=40, r=20, t=50, b=40),
    )
    return fig


def _plot_year_trend(years: list[int]) -> Any:
    """Yıllara göre işbirliği trendi."""
    yc = Counter(years)
    sorted_y = sorted(yc)

    fig = go.Figure()
    fig.add_trace(go.Scatter(
        x=sorted_y, y=[yc[y] for y in sorted_y],
        mode="lines+markers",
        fill="tozeroy",
        fillcolor="rgba(78,121,167,0.15)",
        line=dict(color="#4e79a7", width=2),
        marker=dict(size=4),
        name="İşbirliği sayısı",
    ))
    fig.update_layout(
        title="Yıllara Göre İşbirliği Trendi (1963-2017)",
        xaxis_title="Yıl",
        yaxis_title="Yeni işbirliği sayısı",
        template="plotly_white",
        height=400,
        margin=dict(l=40, r=20, t=50, b=40),
    )
    return fig


def _plot_top_authors(node_ids: list[int], degrees: list[int], top_n: int = 20) -> Any:
    """En çok işbirliği yapan top-N yazar."""
    if not degrees:
        return None
    n = min(top_n, len(degrees))
    top_ids = node_ids[:n]
    top_degs = degrees[:n]

    fig = go.Figure()
    fig.add_trace(go.Bar(
        y=[f"Yazar #{nid}" for nid in reversed(top_ids)],
        x=list(reversed(top_degs)),
        orientation="h",
        marker_color="#f28e2b",
        text=list(reversed(top_degs)),
        textposition="outside",
    ))
    fig.update_layout(
        title=f"En Çok İşbirliği Yapan İlk {n} Yazar",
        xaxis_title="Derece (işbirliği sayısı)",
        template="plotly_white",
        height=500,
        margin=dict(l=100, r=40, t=50, b=40),
    )
    return fig


def _plot_feature_analysis(feats: np.ndarray) -> Any:
    """Node feature vektörlerinin büyüklük dağılımı."""
    magnitudes = np.sqrt(np.sum(feats ** 2, axis=1))

    fig = go.Figure()
    fig.add_trace(go.Histogram(
        x=magnitudes, nbinsx=60,
        marker_color="#b07aa1",
        name="Feature vektör büyüklüğü",
    ))
    mean_mag = float(np.mean(magnitudes))
    fig.add_vline(x=mean_mag, line_dash="dash", line_color="red",
                   annotation_text=f"Ortalama: {mean_mag:.2f}")

    fig.update_layout(
        title="Node Feature Vektör Büyüklük Dağılımı (L2 norm)",
        xaxis_title="||x||_2",
        yaxis_title="Node sayısı",
        template="plotly_white",
        height=380,
        margin=dict(l=40, r=20, t=50, b=40),
    )
    return fig


def _plot_split_composition(split_rows: list[dict[str, Any]]) -> Any:
    """Train/valid/test split dağılımı — sadece positive edge'ler."""
    if not split_rows:
        return None

    labels = []
    values = []
    for row in split_rows:
        labels.append(row.get("split", "?"))
        values.append(row.get("positive_edges", 0))

    fig = go.Figure()
    fig.add_trace(go.Pie(
        labels=labels, values=values,
        marker=dict(colors=["#4e79a7", "#f28e2b", "#e15759"]),
        textinfo="label+percent",
        hole=0.35,
    ))
    fig.update_layout(
        title="Train / Validation / Test Split Dağılımı (Pozitif Edge'ler)",
        template="plotly_white",
        height=380,
        margin=dict(l=20, r=20, t=50, b=20),
    )
    return fig


def render_dataset_explorer() -> None:
    """Render the comprehensive dataset exploration page."""
    st = require_streamlit()

    st.markdown("---")

    # --- Hero kartlar ---
    years = _edge_years()
    weights = _edge_weights()
    feats = _node_features()
    node_ids, degrees = _degree_distribution()
    bundle = load_collab_data_bundle()

    total_edges = len(years)
    total_nodes = feats.shape[0]
    feature_dim = feats.shape[1]
    year_min, year_max = min(years), max(years)

    col1, col2, col3, col4, col5 = st.columns(5)
    col1.metric("Toplam Node", f"{total_nodes:,}")
    col2.metric("Toplam Edge", f"{total_edges:,}")
    col3.metric("Feature Boyutu", str(feature_dim))
    col4.metric("Zaman Aralığı", f"{year_min}–{year_max}")
    col5.metric("Ort. Derece", f"{sum(degrees)/len(degrees):.1f}" if degrees else "N/A")

    st.markdown("---")

    # --- İki sutun: Split + Weight ---
    left, right = st.columns(2)
    with left:
        split_rows = split_count_rows(bundle.split_edge)
        fig_split = _plot_split_composition(split_rows)
        if fig_split:
            st.plotly_chart(fig_split, use_container_width=True)

    with right:
        fig_weight = _plot_weight_distribution(weights)
        if fig_weight:
            st.plotly_chart(fig_weight, use_container_width=True)

    # --- Tam genislik: Yil trendi ---
    st.markdown("---")
    fig_year = _plot_year_trend(years)
    if fig_year:
        st.plotly_chart(fig_year, use_container_width=True)

    # --- İki sutun: Degree + Top Authors ---
    st.markdown("---")
    left2, right2 = st.columns(2)
    with left2:
        fig_degree = _plot_degree_distribution(degrees)
        if fig_degree:
            st.plotly_chart(fig_degree, use_container_width=True)

    with right2:
        fig_top = _plot_top_authors(node_ids, degrees, top_n=20)
        if fig_top:
            st.plotly_chart(fig_top, use_container_width=True)

    # --- Feature analizi ---
    st.markdown("---")
    fig_feat = _plot_feature_analysis(feats)
    if fig_feat:
        st.plotly_chart(fig_feat, use_container_width=True)
