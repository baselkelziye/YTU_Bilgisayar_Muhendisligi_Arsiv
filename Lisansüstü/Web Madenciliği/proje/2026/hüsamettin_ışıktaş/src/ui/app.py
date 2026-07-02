"""Streamlit sunum uygulamasi — ogbl-collab Link Prediction."""

from __future__ import annotations

from src.ui.pages import (
    render_algorithm_runner,
    render_dataset_explorer,
    render_graph_explorer,
    render_results_dashboard,
)


def _inject_css() -> None:
    """Minimal CSS for clean presentation."""
    import streamlit as st

    st.markdown(
        """<style>
        /* Streamlit header'i gizle */
        header[data-testid="stHeader"] {
            display: none !important;
        }
        .block-container {
            padding-top: 1rem !important;
        }

        /* Baslik tab bar'in solunda, ayni hizada */
        .stTabs [data-baseweb="tab-list"] {
            padding-left: 110px !important;
        }
        .stTabs [data-baseweb="tab-list"]::before {
            content: "ogbl-collab";
            position: absolute;
            left: 12px;
            top: 50%;
            transform: translateY(-50%);
            font-size: 0.9rem;
            font-weight: 700;
            color: #1a1a2e;
        }

        /* Metric kartlari */
        [data-testid="stMetricValue"] {
            font-size: 1.5rem !important;
            font-weight: 700 !important;
            color: #16213e;
        }
        /* Compact tabs */
        .stTabs [data-baseweb="tab-list"] {
            gap: 1px;
            background: #f0f0f0;
            border-radius: 8px;
            padding: 3px;
        }
        .stTabs [data-baseweb="tab"] {
            border-radius: 6px;
            padding: 5px 14px;
            font-size: 0.82rem;
            font-weight: 500;
        }
        .stTabs [aria-selected="true"] {
            background: #4e79a7 !important;
            color: white !important;
        }
        </style>""",
        unsafe_allow_html=True,
    )


def main() -> None:
    """Run the Streamlit presentation app."""
    import streamlit as st

    st.set_page_config(
        page_title="ogbl-collab | Sunum",
        page_icon="🔗",
        layout="wide",
        initial_sidebar_state="collapsed",
    )

    _inject_css()

    tab1, tab2, tab3 = st.tabs([
        "Veri Seti Keşfi",
        "Algoritma Çalıştırıcı",
        "Sonuçlar",
    ])

    with tab1:
        render_dataset_explorer()
        st.divider()
        render_graph_explorer()

    with tab2:
        render_algorithm_runner()

    with tab3:
        render_results_dashboard()


if __name__ == "__main__":
    main()
