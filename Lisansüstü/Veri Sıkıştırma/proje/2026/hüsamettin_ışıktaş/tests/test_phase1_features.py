from src.analysis.chunk_size_decision import choose_chunk_size
from src.features.compression_features import FEATURE_SET_A_COLUMNS, extract_set_a_features
from src.features.fast_features import FEATURE_SET_B_COLUMNS, extract_set_b_features
from src.features.feature_pipeline import chunk_text


def test_set_a_feature_schema_matches_output():
    features = extract_set_a_features("Hello hello world!\n123\n")
    assert set(features.keys()) == set(FEATURE_SET_A_COLUMNS)


def test_set_b_feature_schema_matches_output():
    features = extract_set_b_features("Quick test text 42.")
    assert set(features.keys()) == set(FEATURE_SET_B_COLUMNS)


def test_chunk_text_splits_predictably():
    chunks = chunk_text("abcdefghij", chunk_size=4)
    assert chunks == ["abcd", "efgh", "ij"]


def test_choose_chunk_size_prefers_better_score():
    import pandas as pd

    df = pd.DataFrame(
        [
            {"chunk_size": 10240, "num_chunks": 20, "mean_entropy": 4.1, "best_k": 5, "best_silhouette": 0.41, "best_inertia": 1.0},
            {"chunk_size": 20480, "num_chunks": 12, "mean_entropy": 3.9, "best_k": 5, "best_silhouette": 0.22, "best_inertia": 1.0},
        ]
    )
    selected, scored = choose_chunk_size(df)
    assert selected == 10240
    assert float(scored.iloc[0]["final_score"]) >= float(scored.iloc[1]["final_score"])

