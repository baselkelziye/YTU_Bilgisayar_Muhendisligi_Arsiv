# app.py
# To run: streamlit run app.py
from __future__ import annotations

import streamlit as st
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from ml import (
    load_raw_dataset,
    clean_dataset,
    text_stats_by_category,
    category_counts,
    train_all_models,
    predict_all,
    TrainingArtifacts,
)

# Default dataset file name
DEFAULT_CSV = "ecommerceDataset.csv"

# Streamlit page settings
st.set_page_config(page_title="E-Commerce Product Category Classification", layout="wide")


# -----------------------------
# Helpers
# -----------------------------
def init_state():
    """
    Initialize Streamlit session_state keys.
    Store training artifacts in session_state so models persist
    when user navigates between pages inside the same session.
    """
    if "trained" not in st.session_state:
        st.session_state.trained = False
    if "artifacts" not in st.session_state:
        st.session_state.artifacts = None  # type: ignore


@st.cache_data(show_spinner=False)
def cached_load_and_clean(csv_path: str):
    """
    Cache dataset operations so don't re-load or re-clean on every rerun.
    This is important because Streamlit reruns the script frequently.
    """
    df_raw = load_raw_dataset(csv_path)
    df_clean, summary = clean_dataset(df_raw)
    
    # Pre-compute stats used in Dataset Overview page
    stats = text_stats_by_category(df_clean)
    counts = category_counts(df_clean)
    return df_raw, df_clean, summary, stats, counts


def plot_before_after_bar(
    stats_df: pd.DataFrame,
    value_before_col: str,
    value_after_col: str,
    title: str,
    xlabel: str,
):
    """
    Plot side-by-side bars (Before vs After cleaning) for each category.
    Used for both word count and char count graphs.
    """
    categories = stats_df["category"].tolist()
    before_vals = stats_df[value_before_col].to_numpy()
    after_vals = stats_df[value_after_col].to_numpy()

    x = np.arange(len(categories))
    width = 0.38

    fig, ax = plt.subplots(figsize=(7, 4.2))
    ax.bar(x - width / 2, before_vals, width, label="Before cleaning")
    ax.bar(x + width / 2, after_vals, width, label="After cleaning")

    ax.set_title(title)
    ax.set_xlabel(xlabel)
    ax.set_ylabel("Mean value")
    ax.set_xticks(x)
    ax.set_xticklabels(categories, rotation=20, ha="right")
    ax.legend()
    fig.tight_layout()
    return fig


def plot_confusion_matrix(cm: np.ndarray, labels: list[str], title: str):
    """
    Plot a normalized confusion matrix (each row sums to 1.0).
    This makes it easier to compare performance across classes.
    """
    fig, ax = plt.subplots(figsize=(5.4, 4.8))
    im = ax.imshow(cm)

    ax.set_title(title)
    ax.set_xlabel("Predicted label")
    ax.set_ylabel("True label")
    ax.set_xticks(range(len(labels)))
    ax.set_yticks(range(len(labels)))
    ax.set_xticklabels(labels, rotation=30, ha="right")
    ax.set_yticklabels(labels)

    # Write each normalized value into the corresponding cell
    for i in range(cm.shape[0]):
        for j in range(cm.shape[1]):
            ax.text(j, i, f"{cm[i, j]:.2f}", ha="center", va="center", fontsize=9)

    fig.colorbar(im, ax=ax, fraction=0.046, pad=0.04)
    fig.tight_layout()
    return fig


# -----------------------------
# App
# -----------------------------
init_state()

st.title("E-Commerce Product Category Classification")

# Sidebar for navigation and dataset path input
with st.sidebar:
    st.header("Navigation")
    
    # Simple multi-page navigation with a radio selector
    page = st.radio(
        "Pages",
        ["Dataset Overview", "Model Training", "Prediction"],
        index=0,
    )
    st.divider()
    
    # Allow user to change the dataset file path without editing code
    csv_path = st.text_input("Dataset Path", value=DEFAULT_CSV)


# -----------------------------
# Load Data
# -----------------------------
try:
    df_raw, df_clean, summary, stats_df, counts = cached_load_and_clean(csv_path)
except FileNotFoundError:
    st.error(f"Dataset file not found: {csv_path}")
    st.stop()
except Exception as e:
    st.error(f"Failed to load dataset: {e}")
    st.stop()


# -----------------------------
# Page 1: Dataset Overview
# -----------------------------
if page == "Dataset Overview":
    st.subheader("Dataset Overview")

    # Top row metrics: raw size, cleaned size, missing count, duplicate count
    c1, c2, c3, c4 = st.columns(4)
    c1.metric("Raw rows", f"{summary.raw_rows:,}")
    c2.metric("Rows after cleaning", f"{summary.rows_after_dropna_dedup:,}")
    c3.metric("Missing rows (dropped)", f"{summary.missing_rows:,}")
    c4.metric("Duplicate rows (dropped)", f"{summary.duplicate_rows:,}")

    st.divider()

    # Category distribution plot for cleaned dataset
    st.markdown("### Sample Count per Category (Cleaned Dataset)")
    st.bar_chart(counts)
    
    st.divider()
    
    # Side-by-side plots: mean word count and mean char count (before vs after)
    st.markdown("### Text Length Statistics (Before vs After Cleaning)")

    colA, colB = st.columns(2)

    with colA:
        fig_words = plot_before_after_bar(
            stats_df=stats_df,
            value_before_col="words_before",
            value_after_col="words_after",
            title="Mean Word Count by Category",
            xlabel="Category",
        )
        st.pyplot(fig_words)

    with colB:
        fig_chars = plot_before_after_bar(
            stats_df=stats_df,
            value_before_col="chars_before",
            value_after_col="chars_after",
            title="Mean Character Count by Category",
            xlabel="Category",
        )
        st.pyplot(fig_chars)


# -----------------------------
# Page 2: Model Training
# -----------------------------
elif page == "Model Training":
    st.subheader("Model Training")

    # If already trained in this session, just display results
    if st.session_state.trained and st.session_state.artifacts is not None:
        st.success("Models are already trained for this session.")

        artifacts: TrainingArtifacts = st.session_state.artifacts
        st.markdown("### Evaluation Metrics")
        st.dataframe(artifacts.metrics_df, use_container_width=True)

        st.markdown("### Confusion Matrices (Normalized)")
        cols = st.columns(3)
        names = list(artifacts.models.keys())

        # Display 3 confusion matrices side-by-side (one per model)
        for i, name in enumerate(names):
            with cols[i]:
                fig_cm = plot_confusion_matrix(
                    artifacts.confusion_matrices[name],
                    artifacts.labels,
                    title=name,
                )
                st.pyplot(fig_cm)

    else:
        # Training starts only when the button is clicked
        st.info("Click the button below to train the models. This can take a while.")

        train_btn = st.button("Train Models", type="primary")

        if train_btn:
            # Status block gives user feedback during the potentially long training step
            status = st.status("Training in progress...", expanded=True)
            status.write("Cleaning data (cached) and preparing TF-IDF features...")
            
            try:
                status.write("Training models: Logistic Regression, Linear SVM, Random Forest...")
                artifacts = train_all_models(df_clean)

                # Persist training artifacts so they survive page changes
                st.session_state.artifacts = artifacts
                st.session_state.trained = True

                status.update(label="Training completed!", state="complete", expanded=False)

                # Show metrics and confusion matrices after training finishes
                st.markdown("### Evaluation Metrics")
                st.dataframe(artifacts.metrics_df, use_container_width=True)

                st.markdown("### Confusion Matrices (Normalized)")
                cols = st.columns(3)
                names = list(artifacts.models.keys())

                for i, name in enumerate(names):
                    with cols[i]:
                        fig_cm = plot_confusion_matrix(
                            artifacts.confusion_matrices[name],
                            artifacts.labels,
                            title=name,
                        )
                        st.pyplot(fig_cm)

            except Exception as e:
                # If training fails, show an error state and message
                status.update(label="Training failed.", state="error", expanded=True)
                st.error(f"Training failed: {e}")


# -----------------------------
# Page 3: Prediction
# -----------------------------
else:
    st.subheader("Prediction")

    # Prediction requires trained models
    if not st.session_state.trained or st.session_state.artifacts is None:
        st.warning("Models are not trained yet. Please go to 'Model Training' and train the models first.")
        st.stop()

    artifacts: TrainingArtifacts = st.session_state.artifacts

    st.markdown("Enter a product description below and get predictions from all three models.")

    text = st.text_area(
        "Product description",
        height=160,
        placeholder="Type or paste a product description here..."
    )

    # Button is always enabled, validate input after click
    predict_btn = st.button("Predict", type="primary")

    if predict_btn:
        if not text.strip():
            st.warning("Please enter a product description.")
        else:
            outputs = predict_all(text, artifacts)

            st.markdown("### Predictions")
            st.dataframe(pd.DataFrame(outputs.items(), columns=["Model", "Predicted Category"]), use_container_width=True)