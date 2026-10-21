import re
from multiprocessing import Pool, freeze_support

import pandas as pd
from nltk.corpus import stopwords
from zemberek import (TurkishSentenceNormalizer, TurkishMorphology, TurkishTokenizer)

# Load data from file
with open('raw/data-5k.txt', 'r', encoding='utf-8') as file:
    lines = file.readlines()

# Split lines into tweets and occupations
tweets = []
occupations = []
for line in lines:
    parts = line.strip().split('\t')
    if len(parts) == 2:
        tweet, occupation = parts
        tweets.append(tweet)
        occupations.append(occupation)
    else:
        print(f"Ignoring line: {line}")

# Create DataFrame
data = pd.DataFrame({'text': tweets, 'occupation': occupations})

# Turkish stopwords
stop_words = set(stopwords.words('turkish'))

# Initialize Zemberek Morphology and Tokenizer
morphology = TurkishMorphology.create_with_defaults()
tokenizer = TurkishTokenizer.DEFAULT
normalizer = TurkishSentenceNormalizer(morphology)

normalized_text_cache = {}


def preprocess_text(text):
    # Check if normalized text is already cached
    if text in normalized_text_cache:
        return normalized_text_cache[text]

    # Remove URLs and non-alphanumeric characters, normalize Turkish text, and convert to lowercase
    text = re.sub(r'http\S+|[^a-zA-ZğüşıöçĞÜŞİÖÇ\s]', '', text)

    # Check if text is not empty
    if text.strip():
        text = normalizer.normalize(text).lower()

    # Cache the normalized text
    normalized_text_cache[text] = text

    return text


def process_batch(batch):
    normalized_batches = []
    for text, occupation in zip(batch['text'], batch['occupation']):
        normalized_tokens = []
        text = preprocess_text(text)
        # Tokenize
        tokens = tokenizer.tokenize(text)
        # Remove stopwords and find root forms
        for token in tokens:
            if token.type_.name == "Word" and token.content not in stop_words:
                analysis = morphology.analyze_and_disambiguate(token.content)
                if analysis and len(analysis) > 0:
                    root = analysis[0].best_analysis.get_stem()
                    normalized_tokens.append(root)
                else:
                    normalized_tokens.append(token.content)
        normalized_tokens.append('\t')
        normalized_tokens.append(occupation)
        normalized_tokens.append('\n')
        normalized_batches.append(normalized_tokens)
    return normalized_batches


if __name__ == '__main__':
    freeze_support()

    # Batch processing with parallelization
    batch_size = 5000
    with Pool() as pool:
        processed_batches = pool.map(process_batch, [data[i:i + batch_size] for i in range(0, len(data), batch_size)])

    # Flatten the list of batches
    processed_tweets = [item for sublist in processed_batches for item in sublist]

    # Save preprocessed data
    with open('processed/zemberek-5k.txt', 'w', encoding='utf-8') as result_file:
        for tokens in processed_tweets:
            result_file.write(' '.join(tokens))
