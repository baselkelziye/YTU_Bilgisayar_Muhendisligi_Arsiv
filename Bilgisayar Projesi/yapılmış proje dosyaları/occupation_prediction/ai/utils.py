import re

import numpy as np
from keras.preprocessing import sequence
from nltk.corpus import stopwords
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from zemberek import (TurkishSentenceNormalizer, TurkishMorphology, TurkishTokenizer)


def read_data(filename, is_raw):
    with open(filename, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    data, labels = [], []
    for line in lines:
        if is_raw:
            parts = line.split('\t')
        else:
            parts = re.split(r'\s+\t\s+', line.strip())
        if len(parts) == 2:
            text, label = parts
            if is_raw:
                label = label.replace('\n', '')
            data.append(text)
            labels.append(label)
        else:
            print(f"issue with line: {line.strip()}, skipping..")

    return data, labels


def group_data(data, labels, group_size):
    if group_size is None:
        raise ValueError("group_size cannot be None.")

    label_data_dict = {label: [] for label in list(dict.fromkeys(labels))}
    for label, datum in zip(labels, data):
        label_data_dict[label].append(datum)

    stacked_data, stacked_labels = [], []
    for key, value in label_data_dict.items():
        for i in range(0, len(value), group_size):
            stacked_data.append(' '.join(value[i:i + group_size]))
            stacked_labels.append(key)

    return stacked_data, stacked_labels


def extract_unique_data(data, labels):
    unique_data, unique_labels = [], []
    for i, current_data in enumerate(data):
        if current_data not in unique_data:
            unique_data.append(current_data)
            unique_labels.append(labels[i])
    return unique_data, unique_labels


def load_data(filename, group=False, group_size=None, unique=True, is_raw=False):
    data, labels = read_data(filename, is_raw=is_raw)
    print(f"Loaded {len(data)} samples.")
    print(f"Loaded {len(set(labels))} labels: {set(labels)}")

    # Group data
    if group:
        data, labels = group_data(data, labels, group_size=group_size)
        print(f"Sample size after grouping:", len(data))

    if unique:
        # Extract unique data
        data, labels = extract_unique_data(data, labels)
        print(f"Unique sample size:", len(set(data)))

    return data, labels


def convert_labels_to_numerical(labels, label_mapping):
    return np.array([label_mapping[label] for label in labels])


def create_bow_vector(vectorizer, data, input_length):
    if input_length is None:
        raise ValueError("input_length cannot be None.")

    # Create raw vector
    raw_vector = vectorizer.transform(data).toarray()

    # Create bag-of-words vectors for each data
    bow_vector = []
    for vector in raw_vector:
        bow_vector.append(np.where(vector != 0)[0])

    # Add padding to bow vectors
    padded_bow_vector = sequence.pad_sequences(bow_vector, input_length, padding='post')

    return padded_bow_vector


def get_prediction_results(model, test_data, test_labels, label_mapping, is_deep=True):
    predictions = model.predict(test_data)
    if is_deep:
        predictions = np.argmax(predictions, axis=1)

    accuracy = accuracy_score(test_labels, predictions)
    report = classification_report(test_labels, predictions, target_names=[key for key in label_mapping],
                                   zero_division=1)
    cm = confusion_matrix(test_labels, predictions)

    return accuracy, report, cm


def create_embedding_vectors(filename, emb_dim=None):
    if emb_dim is None:
        raise ValueError("emb_dim cannot be None.")

    embedding_vectors = {}
    with open(filename, 'r', encoding='utf-8') as file:
        for row in file:
            values = row.split(' ')
            word = values[0]
            weights = np.asarray([float(val) for val in values[1:]])
            if len(weights) == emb_dim:
                embedding_vectors[word] = weights
    print(f"vectorized vocabulary size: {len(embedding_vectors)}")
    return embedding_vectors


def create_embedding_matrix(vocabulary, embedding_vectors, random_init=False, emb_dim=None):
    if emb_dim is None:
        raise ValueError("emb_dim cannot be None.")

    oov_words = []
    vocab_size = len(set(vocabulary))
    embedding_matrix = np.zeros((vocab_size, emb_dim))

    for word, idx in vocabulary.items():
        if idx < vocab_size:
            embedding_vector = embedding_vectors.get(word)
            if embedding_vector is not None:
                embedding_matrix[idx] = embedding_vector
            else:
                oov_words.append(word)
                if random_init:
                    # Random initialization for out of vocabulary words
                    embedding_matrix[idx] = np.random.uniform(low=-1.0, high=1.0, size=emb_dim)

    # Print some of the out of vocabulary words
    print(f'out-of-vocabulary size: {len(oov_words)}')
    print(f'out-of-vocabulary words: {oov_words[0:5]}')

    return embedding_matrix


def predict_input(model, input_text, vectorizer, label_mapping, input_length=None, is_deep=True):
    # Turkish stopwords
    stop_words = set(stopwords.words('turkish'))

    # Initialize Zemberek Morphology and Tokenizer
    morphology = TurkishMorphology.create_with_defaults()
    tokenizer = TurkishTokenizer.DEFAULT
    normalizer = TurkishSentenceNormalizer(morphology)

    text = re.sub(r'http\S+|[^a-zA-ZğüşıöçĞÜŞİÖÇ\s]', '', input_text)
    text = normalizer.normalize(text).lower()
    normalized_tokens = []
    # Remove stopwords and find root forms
    for token in tokenizer.tokenize(text):
        if token.type_.name == "Word" and token.content not in stop_words:
            analysis = morphology.analyze_and_disambiguate(token.content)
            normalized_tokens.append(
                analysis[0].best_analysis.get_stem() if analysis and len(analysis) > 0 else token.content)

    print('Processed text:', " ".join(normalized_tokens))
    if is_deep:
        sample_vector = create_bow_vector(vectorizer, [text], input_length=input_length)
    else:
        sample_vector = vectorizer.transform([text]).toarray()
    predictions = model.predict(sample_vector)
    prediction = predictions[0]
    if is_deep:
        prediction = np.argmax(predictions, axis=1)
    predicted_label = [key for key, value in label_mapping.items() if value == prediction][0]
    return predicted_label
