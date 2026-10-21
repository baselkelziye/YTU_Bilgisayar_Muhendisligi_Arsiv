import html
import re
from abc import ABC, abstractmethod
from functools import lru_cache
from pathlib import Path
from typing import List, Optional, Union

import joblib
import numpy as np
import spacy
from scipy.sparse.coo import coo_matrix
from scipy.sparse.csr import csr_matrix
from sklearn.base import TransformerMixin
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.svm import LinearSVC
from spacy.lang.en import STOP_WORDS
from spacy.language import Doc, Language
from spacy.tokens.token import Token

from modcom.config import AppConfig, get_app_settings
from modcom.models import ClassificationResponse, MLModel

try:
    import en_core_web_sm
except ImportError:
    import spacy.cli as spacy_cli

    print("Gotta download the model")
    spacy_cli.download("en_core_web_sm")

nlp: Language = spacy.load("en_core_web_sm", disable=["parser", "tagger", "ner"])


# Saved along with Tf-Idf vectorizer. Required to load the serialized vectorizer
def placeholder(x):
    return x


class SpacyTokenTransformer(TransformerMixin):
    __symbols = set("!$%^&*()_+|~-=`{}[]:\";'<>?,./-")

    def transform(self, X: np.ndarray, **kwargs) -> np.ndarray:
        f = np.vectorize(SpacyTokenTransformer.transform_to_tokens, otypes=[np.object])
        X_tokenized = f(X)

        return X_tokenized

    def fit(self, X, y=None, **fit_params):
        return self

    @staticmethod
    def transform_to_tokens(text: np.str) -> List[str]:
        str_text = str(text)
        doc: Doc = nlp(str_text)
        tokens: List[str] = []
        tok: Token
        for tok in doc:
            clean_token: str
            if tok.like_url:
                clean_token = "URL"
            else:
                clean_token = (
                    tok.lemma_.strip().lower()
                )  # if tok.lemma_ != '-PRON-' else tok.lower_
                if (
                    len(clean_token) < 1
                    or clean_token in SpacyTokenTransformer.__symbols
                    or clean_token in STOP_WORDS
                ):
                    continue

            tokens.append(clean_token)

        return tokens


class CleanTextTransformer(TransformerMixin):
    __uplus_pattern = re.compile("\<[uU]\+(?P<digit>[a-zA-Z0-9]+)\>")
    __markup_link_pattern = re.compile("\[(.*)\]\((.*)\)")

    def transform(self, X: np.ndarray, **kwargs) -> np.ndarray:
        f = np.vectorize(CleanTextTransformer.transform_clean_text)
        X_clean = f(X)

        return X_clean

    def fit(self, X, y=None, **fit_params):
        return self

    @staticmethod
    def transform_clean_text(raw_text: str):
        try:
            decoded = raw_text.encode("ISO-8859-1").decode("utf-8")
        except:
            decoded = raw_text.encode("ISO-8859-1").decode("cp1252")

        html_unescaped = html.escape(decoded)
        html_unescaped = re.sub(r"\r\n", " ", html_unescaped)
        html_unescaped = re.sub(r"\r\r\n", " ", html_unescaped)
        html_unescaped = re.sub(r"\r", " ", html_unescaped)
        html_unescaped = html_unescaped.replace("&gt;", " > ")
        html_unescaped = html_unescaped.replace("&lt;", " < ")
        html_unescaped = html_unescaped.replace("--", " - ")
        html_unescaped = CleanTextTransformer.__uplus_pattern.sub(
            " U\g<digit>", html_unescaped
        )
        html_unescaped = CleanTextTransformer.__markup_link_pattern.sub(
            " \1 \2", html_unescaped
        )
        html_unescaped = html_unescaped.replace("\\", "")

        return html_unescaped


class TextPreprocessor:
    __slots__ = "_html_cleaner", "_tokenizer"

    def __init__(self):
        self._html_cleaner = CleanTextTransformer()
        self._tokenizer = SpacyTokenTransformer()

    def clean_and_tokenize(self, txt: Union[str, List[str], np.ndarray]) -> np.ndarray:
        if isinstance(txt, str):
            txt = [txt]

        if isinstance(txt, list):
            txt = np.array(txt, dtype=np.object)

        if not (isinstance(txt, np.ndarray) and txt.dtype == np.object):
            raise ValueError(
                "Input `txt` must be a string, list of strings, or numpy array of type object"
            )

        txt_processed = self._html_cleaner.transform(txt)
        txt_processed = self._tokenizer.transform(txt_processed)

        return txt_processed

    def clean_single(self, txt: str) -> str:
        return self._html_cleaner.transform_clean_text(txt)

    def tokenize_single(self, clean_text: str) -> List[str]:
        return self._tokenizer.transform_to_tokens(clean_text)

    def clean_and_tokenize_single(self, txt: str) -> List[str]:
        txt_proc = self.clean_single(txt)
        txt_proc = self.tokenize_single(txt)

        return txt_proc


class NBTransformer(TransformerMixin):
    def __init__(self, r: np.ndarray, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.r = r

    def transform(self, X: csr_matrix) -> coo_matrix:
        return X.multiply(self.r)

    def fit(self, X, y=None, **fit_params):
        return self


CLASSIFIER = Union[LogisticRegression, LinearSVC]
VECTORIZER = Union[TfidfVectorizer, CountVectorizer]


class Model(ABC):
    __slots__ = "_preproc"

    def __init__(self, preproc: TextPreprocessor = None):
        self._preproc = preproc if preproc is not None else TextPreprocessor()

    @abstractmethod
    def predict(self, clean_comment: str) -> List[float]:
        pass


class ScikitModel(Model):
    __slots__ = "_clf", "_vectorizer"

    def __init__(
        self,
        clf_path: Union[str, Path],
        *,
        vectorizer: VECTORIZER,
        preproc: TextPreprocessor = None,
    ):
        super(ScikitModel, self).__init__(preproc)
        self._clf: CLASSIFIER = joblib.load(clf_path)
        self._vectorizer = vectorizer

    def predict(self, comment: str) -> List[float]:
        vec = self._preproc.clean_and_tokenize_single(comment)
        vec = self._vectorizer.transform([vec])
        prob = self._clf.predict_proba(vec)

        return list(prob[0])


class SpacyModel(Model):
    POSITVE = "REMOVED"
    NEGATIVE = "NOTREMOVED"

    __slots__ = "_nlp"

    def __init__(self, path: Union[str, Path], *, preproc: TextPreprocessor = None):
        super(SpacyModel, self).__init__(preproc)
        self._nlp = spacy.load(path)

    def predict(self, comment: str) -> List[float]:
        clean_comment = self._preproc.clean_single(comment)
        doc: spacy.language.Doc = self._nlp(clean_comment)

        categories = doc.cats
        probs = [categories[self.NEGATIVE], categories[self.POSITVE]]

        return probs


class ModelLoader:
    __slots__ = "_settings", "_models", "_vec", "_preproc"

    def __init__(self, settings: AppConfig):
        self._settings = settings
        self._models = {}

        self._vec = None
        self._preproc = TextPreprocessor()

    def load_model(self, model: MLModel):
        pth = self.get_full_path(model.name)

        print(f"Loading {model.name}...")
        preproc = self._preproc
        if model.type == "spacy":
            m = SpacyModel(pth, preproc=preproc)
        elif model.type == "sklearn":
            m = ScikitModel(pth, vectorizer=self._vec, preproc=preproc)
        else:
            raise ValueError(f"Unrecognized model: {model}")

        self._models[model.name] = m

    def __load_available_models(self):
        total = len(self._settings.available_models)
        print(f"Loading {total} models")
        for model in self._settings.available_models:
            self.load_model(model)

    @property
    def vectorizer(self):
        return self._vec

    def get_full_path(self, name: str):
        return self._settings.model_dir.joinpath(f"{name}.{self._settings.model_ext}")

    def get_model(self, model: str) -> Optional[Model]:
        return self._models.get(model, None)

    def load_models(self):
        if self._vec is None:
            print("Loading vectorizer...")
            pth = self.get_full_path(self._settings.vectorizer)
            self._vec = joblib.load(pth)

        self.__load_available_models()


MODEL_LOADER = ModelLoader(get_app_settings())


@lru_cache(maxsize=1)
def get_model_loader():
    return MODEL_LOADER


def predict_comment(comment: str, model_key: str) -> ClassificationResponse:
    if len(comment) < 10:
        return ClassificationResponse(success=False, msg="Comment is too short")

    clf = MODEL_LOADER.get_model(model_key)

    if clf is None:
        return ClassificationResponse(
            success=False, msg=f"No such classifier: {model_key}"
        )

    pred = clf.predict(comment)
    not_remove_prob, remove_prob = pred

    will_remove = remove_prob > not_remove_prob
    if will_remove:
        msg = "Comment will be removed"
    else:
        msg = "Comment will not be removed"

    return ClassificationResponse(
        success=True,
        msg=msg,
        prob_remove=remove_prob,
        prob_not_remove=not_remove_prob,
        will_remove=will_remove,
    )
