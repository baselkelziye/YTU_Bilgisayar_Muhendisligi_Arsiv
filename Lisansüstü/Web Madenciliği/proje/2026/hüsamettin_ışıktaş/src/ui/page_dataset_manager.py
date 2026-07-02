"""Dataset manager page."""

from __future__ import annotations

from src.ui.common import load_bundle, require_streamlit, safe_len, split_count_rows


def render_dataset_manager() -> None:
    """Render dataset metadata and project split information."""
    st = require_streamlit()

    st.header("Dataset Manager")
    st.write("Dataset: `ogbl-collab`")
    st.write("Task: link prediction on academic collaboration edges")
    st.write("Primary metric: `Hits@50`")
    st.write("Supported dataset scales: `10%`, `50%`, `100%`")
    st.info(
        "Dataset loading is performed through the installed `ogb` package. "
        "The local `ogb/` source tree is not imported by the project code."
    )

    bundle = load_bundle()
    feature_dim = 0
    if hasattr(bundle.data, "x") and getattr(bundle.data, "x") is not None:
        feature_dim = int(bundle.data.x.shape[1])

    overview_columns = st.columns(4)
    overview_columns[0].metric("Nodes", int(getattr(bundle.data, "num_nodes", 0)))
    overview_columns[1].metric("Feature Dim", feature_dim)
    overview_columns[2].metric("Train Edges", safe_len(bundle.split_edge["train"]["edge"]))
    overview_columns[3].metric("Valid Edges", safe_len(bundle.split_edge["valid"]["edge"]))

    st.subheader("Split Inventory")
    st.dataframe(split_count_rows(bundle.split_edge), width="stretch")
