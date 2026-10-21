import re
from multiprocessing import Pool, freeze_support

import pandas as pd
import zeyrek
from nltk.corpus import stopwords

# Load data from file
with open('raw/data-30k.txt', 'r', encoding='utf-8') as file:
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

# Initialize Zeyrek
analyzer = zeyrek.MorphAnalyzer()


def process_text(text):
    # Remove URLs
    text = re.sub(r'http\S+', '', text)
    # Convert to lowercase
    text = re.sub(r'[^a-zA-ZğüşıöçĞÜŞİÖÇ\s#]', ' ', text).lower()
    return text.strip()


def process_batch(batch):
    normalized_batches = []
    for text, occupation in zip(batch['text'], batch['occupation']):
        normalized_tokens = []
        hashtag_words = []
        # Check if the sentence includes a word with a hashtag
        if any('#' in word for word in text.split()):
            # Save the hashtag words without the '#' symbol
            hashtag_words = [word.replace('#', '') for word in text.split() if '#' in word]
            # Replace the words with a hashtag with placeholder
            text = re.sub(r'#\w+', r' # ', text)
        text = process_text(text)
        # Tokenize and analyze morphology
        analyses = analyzer.analyze(text)
        for parses in analyses:
            for parse in parses:
                # Check if the part of speech is not "Unk" and the lemma is not a stop word
                if parse.pos != "Unk" and parse.lemma not in normalized_tokens and parse.lemma not in stop_words:
                    normalized_tokens.append(parse.lemma)
                    break  # Break the loop after selecting the best parse
        # Replace the placeholder with the hashtag words without the '#' symbol
        normalized_tokens = [word if word != '#' else hashtag_words.pop(0) for word in normalized_tokens]
        normalized_tokens.append('\t')
        normalized_tokens.append(occupation)
        normalized_tokens.append('\n')
        normalized_batches.append(normalized_tokens)
    return normalized_batches


if __name__ == '__main__':
    freeze_support()
    # Batch processing with parallelization
    batch_size = 1000
    num_batches = len(data) // batch_size + 1
    with Pool() as pool:
        processed_batches = pool.map(process_batch, [data[i:i + batch_size] for i in range(0, len(data), batch_size)])

    # Flatten the list of batches
    processed_tweets = [item for sublist in processed_batches for item in sublist]

    # Save preprocessed data
    with open('processed/zeyrek-30k.txt', 'w', encoding='utf-8') as result_file:
        for tokens in processed_tweets:
            result_file.write(' '.join(tokens))
