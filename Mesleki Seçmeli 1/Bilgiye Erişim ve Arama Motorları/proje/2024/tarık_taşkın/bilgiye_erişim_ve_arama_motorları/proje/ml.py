# ml.py
from __future__ import annotations

import re
from dataclasses import dataclass
from typing import Dict, List, Tuple

import numpy as np
import pandas as pd

from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics import (
    accuracy_score,
    confusion_matrix,
    precision_recall_fscore_support,
)
from sklearn.linear_model import LogisticRegression
from sklearn.svm import LinearSVC
from sklearn.ensemble import RandomForestClassifier


# -----------------------------
# Text cleaning 
# -----------------------------
def clean_text(text: str) -> str:
    """
    Clean raw product description text.
    The goal is to remove noise while preserving semantic meaning
    for TF-IDF based text classification.
    """
    if text is None:
        return ""
    
    text = str(text)                                   # Ensure the input is a string
    text = text.lower()                                # Convert to lower case
    text = re.sub(r'\n+', ' ', text)                   # Replace newlines with a single space
    text = re.sub(r'https?://\S+|www\.\S+', " ", text) # Remove URLs (http, https, www)
    text = re.sub(r'(?<=\w)-(?=\w)', '', text)         # Remove hyphen between word chars: "wi-fi" -> "wifi"
    text = re.sub(r'\[.*?\]', '', text)                # Remove content inside square brackets
    text = re.sub(r'\b\d+(\.\d+)?\b', ' ', text)       # Remove number-only tokens (integers and decimals)
    text = text.replace("_", " ")                      # Replace underscores with a space
    text = re.sub(r'[^\w\s]', ' ', text)               # Remove remaining punctuation/symbols (keep only words and spaces)
    text = text.encode("ascii", "ignore").decode()     # Remove non-ASCII chars (emoji, non-English letters)
    text = re.sub(r'\b[a-z]\b', ' ', text)             # Remove single-letter tokens (e.g. "a", "s", "x")
    text = re.sub(r"\s+", " ", text).strip()           # Collapse multiple spaces and strip leading/trailing spaces
    return text


def word_count(s: str) -> int:
    """Return number of words in a text string."""
    s = "" if s is None else str(s)
    return 0 if not s.strip() else len(s.split())


def char_count(s: str) -> int:
    """Return number of characters in a text string."""
    s = "" if s is None else str(s)
    return len(s)


# -----------------------------
# Dataset Loading & Cleaning
# -----------------------------
def load_raw_dataset(csv_path: str) -> pd.DataFrame:
    """
    Load dataset from CSV.
    The file is expected to be headerless in the format:
    category, description
    """
    df = pd.read_csv(csv_path, names=["category", "description"])
    
    # Reorder columns
    df = df[["description", "category"]]
    return df


@dataclass
class DatasetSummary:
    """
    Lightweight container to store dataset statistics
    used in the Dataset Overview page of the UI.
    """
    raw_rows: int
    rows_after_dropna: int
    rows_after_dropna_dedup: int
    missing_rows: int
    duplicate_rows: int


def clean_dataset(df_raw: pd.DataFrame) -> Tuple[pd.DataFrame, DatasetSummary]:
    """
    Full dataset cleaning pipeline:
    - Remove missing values
    - Remove duplicate rows
    - Apply text cleaning
    - Produce summary statistics
    """
    raw_rows = len(df_raw)

    # Drop rows with missing values
    df_dropna = df_raw.dropna()
    rows_after_dropna = len(df_dropna)
    missing_rows = raw_rows - rows_after_dropna

    # Remove duplicate samples
    df_clean_base = df_dropna.drop_duplicates()
    rows_after_dropna_dedup = len(df_clean_base)
    duplicate_rows = rows_after_dropna - rows_after_dropna_dedup

    # Apply text cleaning to descriptions
    df_clean = df_clean_base.copy()
    df_clean["clean_text"] = df_clean["description"].astype(str).apply(clean_text)

    # Store dataset-level statistics
    summary = DatasetSummary(
        raw_rows=raw_rows,
        rows_after_dropna=rows_after_dropna,
        rows_after_dropna_dedup=rows_after_dropna_dedup,
        missing_rows=missing_rows,
        duplicate_rows=duplicate_rows,
    )
    return df_clean, summary


def category_counts(df_clean: pd.DataFrame) -> pd.Series:
    """Return number of samples per category after cleaning."""
    return df_clean["category"].value_counts()


def text_stats_by_category(
    df_clean: pd.DataFrame,
) -> pd.DataFrame:
    """
    Compute average word and character counts per category
    before and after text cleaning.
    Used for Dataset Overview visualizations.
    """
    tmp = df_clean.copy()
    
    # Statistics before cleaning
    tmp["words_before"] = tmp["description"].astype(str).apply(word_count)
    tmp["chars_before"] = tmp["description"].astype(str).apply(char_count)
    
    # Statistics after cleaning
    tmp["words_after"] = tmp["clean_text"].astype(str).apply(word_count)
    tmp["chars_after"] = tmp["clean_text"].astype(str).apply(char_count)

    # Aggregate by category
    g = tmp.groupby("category", as_index=False).agg(
        words_before=("words_before", "mean"),
        chars_before=("chars_before", "mean"),
        words_after=("words_after", "mean"),
        chars_after=("chars_after", "mean"),
        n_samples=("category", "size"),
    )
    return g


# -----------------------------
# Model Training & Evaluation
# -----------------------------
@dataclass
class TrainingArtifacts:
    """
    Container for all objects produced during training.
    Stored in session_state to persist across pages.
    """
    models: Dict[str, object]
    vectorizer: TfidfVectorizer
    labels: List[str]
    metrics_df: pd.DataFrame
    confusion_matrices: Dict[str, np.ndarray]


def train_all_models(df_clean: pd.DataFrame) -> TrainingArtifacts:
    """Train three classical ML models using TF-IDF features."""
    X = df_clean["clean_text"]
    y = df_clean["category"]

    # Stratified split to preserve class distribution
    X_train, X_test, y_train, y_test = train_test_split(
        X, y,
        test_size=0.3,
        random_state=42,
        stratify=y
    )

    # TF-IDF vectorization
    vectorizer = TfidfVectorizer(
        min_df=5,
        ngram_range=(1, 2),
        stop_words="english"
    )
    X_train_vec = vectorizer.fit_transform(X_train)
    X_test_vec = vectorizer.transform(X_test)

    # Define models with notebook-equivalent hyperparameters
    models: Dict[str, object] = {
        "Logistic Regression": LogisticRegression(
            max_iter=1000,
            class_weight="balanced"
        ),
        "Linear SVM": LinearSVC(
            class_weight="balanced",
            dual="auto"
        ),
        "Random Forest": RandomForestClassifier(
            n_estimators=20,
            random_state=42
        ),
    }

   # Fixed label order for consistent confusion matrices
    labels = sorted(y_test.unique().tolist())

    rows = []
    cms: Dict[str, np.ndarray] = {}

    # Train and evaluate each model
    for name, model in models.items():
        model.fit(X_train_vec, y_train)
        preds = model.predict(X_test_vec)

        acc = accuracy_score(y_test, preds)
        p, r, f1, _ = precision_recall_fscore_support(
            y_test, preds, average="macro", zero_division=0
        )

        rows.append(
            {
                "Model": name,
                "Accuracy": acc,
                "Macro Precision": p,
                "Macro Recall": r,
                "Macro F1": f1,
            }
        )

        # Normalized confusion matrix
        cm = confusion_matrix(y_test, preds, labels=labels, normalize="true")
        cms[name] = cm

    metrics_df = pd.DataFrame(rows).sort_values("Macro F1", ascending=False).reset_index(drop=True)

    return TrainingArtifacts(
        models=models,
        vectorizer=vectorizer,
        labels=labels,
        metrics_df=metrics_df,
        confusion_matrices=cms
    )


def predict_all(text: str, artifacts: TrainingArtifacts) -> Dict[str, str]:
    """Predict category for a given text using all trained models."""
    cleaned = clean_text(text)
    vec = artifacts.vectorizer.transform([cleaned])
    outputs: Dict[str, str] = {}
    for name, model in artifacts.models.items():
        outputs[name] = str(model.predict(vec)[0])
    return outputs
