from functools import lru_cache
from pathlib import Path
from typing import List

from pydantic import BaseConfig

from modcom.models import MLModel


class AppConfig(BaseConfig):
    model_dir: Path = Path(__file__).parent.joinpath("../models").resolve()
    model_ext: str = "ml"
    vectorizer: str = "vectorizer"

    available_models: List[MLModel] = [
        MLModel(
            name="simple_logistic",
            type="sklearn",
            display_name="Logistic Regression CLF",
        ),
        MLModel(
            name="spacy_ensemble",
            type="spacy",
            display_name="Spacy - BOW + CNN",
        ),
        MLModel(
            name="spacy_simple_cnn",
            type="spacy",
            display_name="Spacy - Simple CNN",
        ),
        MLModel(name="random_forest", type="sklearn", display_name="Random Forest CLF"),
        MLModel(name="spacy_bow", type="spacy", display_name="Spacy - BOW"),
        MLModel(
            name="nb_svc",
            type="sklearn",
            display_name="NaiveBayes SVM",
            # https://www.aclweb.org/anthology/P12-2018/, https://nlp.stanford.edu/pubs/sidaw12_simple_sentiment.pdf
        ),
    ]


API_CONFIG = AppConfig()


@lru_cache
def get_app_settings() -> AppConfig:
    return API_CONFIG
