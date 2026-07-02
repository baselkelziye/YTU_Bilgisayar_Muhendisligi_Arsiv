"""Compatibility exports for Streamlit page renderers."""

from src.ui.page_algorithm_runner import render_algorithm_runner
from src.ui.page_dataset_explorer import render_dataset_explorer
from src.ui.page_dataset_manager import render_dataset_manager
from src.ui.page_graph_explorer import render_graph_explorer
from src.ui.page_results_dashboard import render_results_dashboard

__all__ = [
    "render_algorithm_runner",
    "render_dataset_explorer",
    "render_dataset_manager",
    "render_graph_explorer",
    "render_results_dashboard",
]
