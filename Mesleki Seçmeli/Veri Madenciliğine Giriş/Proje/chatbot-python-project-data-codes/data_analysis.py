import json
from collections import Counter
import matplotlib.pyplot as plt
from nltk.corpus import stopwords
import string

# Veri okuma
with open('intents.json', encoding='utf-8') as file:
    data = json.load(file)

intents = data['intents']

# Get all patterns and responses
all_patterns = []
all_responses = []

for intent in intents:
    for pattern in intent['patterns']:
        all_patterns += pattern.lower().split()

    for response in intent['responses']:
        all_responses += response.lower().split()

# Remove stopwords
stopwords = set(stopwords.words('english'))

patterns = [word.translate(str.maketrans("", "", string.punctuation)) for word in all_patterns if word not in stopwords ]
responses = [word.translate(str.maketrans("", "", string.punctuation)) for word in all_responses if word not in stopwords ]


# Get most common and least common words
most_common_patterns = Counter(patterns).most_common(25)
least_common_patterns = [word for word, count in Counter(patterns).items() if count > 4 and count < 20][:25]

most_common_responses = Counter(responses).most_common(25)
least_common_responses = [word for word, count in Counter(responses).items() if count > 4 and count < 20][:25]



# Visualize results for patterns and responses
fig, axs = plt.subplots(2, 2, figsize=(15, 10))

axs[0, 0].barh([word for word, count in most_common_patterns], [count for word, count in most_common_patterns])
axs[0, 0].set_title('Most common patterns')



least_common_patterns = sorted(least_common_patterns, key=lambda x: Counter(patterns)[x], reverse=True)
axs[0, 1].set_xticks(range(0,31))
axs[0, 1].barh(least_common_patterns, [Counter(patterns)[word] for word in least_common_patterns])
axs[0, 1].set_title('Least common patterns (occur 5 to 19 times)')


axs[1, 0].barh([word for word, count in most_common_responses], [count for word, count in most_common_responses])
axs[1, 0].set_title('Most common responses')


least_common_responses = sorted(least_common_responses, key=lambda x: Counter(responses)[x], reverse=True)
axs[1, 1].set_xticks(range(0,31))
axs[1, 1].barh(least_common_responses, [Counter(responses)[word] for word in least_common_responses])
axs[1, 1].set_title('Least common responses (occur 5 to 19 times)')

plt.tight_layout()
plt.show()


