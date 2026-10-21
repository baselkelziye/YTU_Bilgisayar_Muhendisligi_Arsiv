import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.preprocessing import Normalizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import roc_curve, auc
import matplotlib.pyplot as plt
import seaborn as sns
from bs4 import BeautifulSoup
from tqdm import tqdm
import re
from sklearn.metrics import confusion_matrix
from scipy.sparse import hstack
import numpy as np
from nltk.corpus import stopwords
import nltk
nltk.download('stopwords')
def decontracted(phrase):
    # Expands English language contractions
    phrase = re.sub(r"won't", "will not", phrase)
    phrase = re.sub(r"can\'t", "can not", phrase)
    phrase = re.sub(r"n\'t", " not", phrase)
    phrase = re.sub(r"\'re", " are", phrase)
    phrase = re.sub(r"\'s", " is", phrase)
    phrase = re.sub(r"\'d", " would", phrase)
    phrase = re.sub(r"\'ll", " will", phrase)
    phrase = re.sub(r"\'t", " not", phrase)
    phrase = re.sub(r"\'ve", " have", phrase)
    phrase = re.sub(r"\'m", " am", phrase)
    return phrase

stopwords = set(stopwords.words('english'))

def preprocess_text(text):
    if isinstance(text, float):  # Eğer text float tipinde ise
        text = str(text)  # Float'ı stringe dönüştür
    text = re.sub(r"http\S+", "", text)
    text = BeautifulSoup(text, 'lxml').get_text()
    text = decontracted(text)
    text = re.sub("\S*\d\S*", "", text).strip()
    text = re.sub('[^A-Za-z]+', ' ', text)
    text = ' '.join(e.lower() for e in text.split() if e.lower() not in stopwords)
    return text.strip()

def process_data(data):
    data = data[data['Score'] != 3]
    data.loc[:, 'Score'] = data['Score'].map(lambda x: 1 if x > 3 else 0)
    sorted_data = data.sort_values('ProductId', axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')
    final = sorted_data.drop_duplicates(subset={"UserId", "ProfileName", "Time", "Text"}, keep='first', inplace=False)
    final.reset_index(inplace=True)
    final.drop(['index'], axis=1, inplace=True)
    final["Summary"] = final['Summary'].apply(preprocess_text)
    final['Text'] = final['Text'].apply(preprocess_text)
    final.drop(['Id', 'ProductId', 'UserId', 'ProfileName'], axis=1, inplace=True)
    return final

def normalize_feature(feature):
    feature_train = feature.values.reshape(-1, 1)
    #feature_train = feature['Train'].values.reshape(-1, 1)
    feature_test = feature['Test'].values.reshape(-1, 1)
    normalizer = Normalizer()
    normalizer.fit(feature_train)
    feature_train_norm = normalizer.transform(feature_train)
    feature_test_norm = normalizer.transform(feature_test)
    return feature_train_norm, feature_test_norm

def plot_roc_curve(train_fpr, train_tpr, test_fpr, test_tpr):
    plt.plot(train_fpr, train_tpr, label="train AUC ="+str(auc(train_fpr, train_tpr)))
    plt.plot(test_fpr, test_tpr, label="test AUC ="+str(auc(test_fpr, test_tpr)))
    plt.legend()
    plt.xlabel("fpr")
    plt.ylabel("tpr")
    plt.title("ROC curve")
    plt.grid()
    plt.show()

def find_best_threshold(thresholds, fpr, tpr):
    t = thresholds[np.argmax(tpr * (1 - fpr))]
    print("the maximum value of tpr*(1-fpr)", max(tpr * (1 - fpr)), "for threshold", np.round(t, 3))
    return t

def predict_with_best_t(proba, threshold):
    return [1 if i >= threshold else 0 for i in proba]

def get_top_features(features, classifier, label):
    top_features = np.argsort(classifier.feature_log_prob_[label])[::-1][:20]
    return [features[i] for i in top_features]

# Load data
data = pd.read_csv('kaggle/Reviews.csv')

# Process data
final = process_data(data)

# Separate class column
y = final['Score'].values
X = final.drop(['Score'], axis=1)

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, stratify=y)

# Text feature
vectorizer = CountVectorizer(min_df=10, ngram_range=(1, 4), max_features=5000)
vectorizer.fit(X_train['Text'].values)
X_train_text = vectorizer.transform(X_train['Text'].values)
X_test_text = vectorizer.transform(X_test['Text'].values)

# Summary feature
vectorizer.fit(X_train['Summary'].values)
X_train_summary = vectorizer.transform(X_train['Summary'].values)
X_test_summary = vectorizer.transform(X_test['Summary'].values)

# HelpfulnessNumerator feature
X_train_help_num_norm, X_test_help_num_norm = normalize_feature(X_train['HelpfulnessNumerator']), normalize_feature(X_test['HelpfulnessNumerator'])

# HelpfulnessDenominator feature
X_train_help_den_norm, X_test_help_den_norm = normalize_feature(X_train['HelpfulnessDenominator']), normalize_feature(X_test['HelpfulnessDenominator'])

# Time feature
X_train_time_norm, X_test_time_norm = normalize_feature(X_train['Time']), normalize_feature(X_test['Time'])

# Combine features
X_tr = hstack((X_train_text, X_train_summary, X_train_help_num_norm, X_train_help_den_norm, X_train_time_norm)).tocsr()
X_te = hstack((X_test_text, X_test_summary, X_test_help_num_norm, X_test_help_den_norm, X_test_time_norm)).tocsr()

# Train the model
NB_classifier = MultinomialNB(class_prior=[0.5, 0.5])
NB_classifier.fit(X_tr, y_train)

# Predict probabilities
y_train_pred = NB_classifier.predict_proba(X_tr)[:, 1]
y_test_pred = NB_classifier.predict_proba(X_te)[:, 1]

# ROC curve
train_fpr, train_tpr, tr_thresholds = roc_curve(y_train, y_train_pred)
test_fpr, test_tpr, te_thresholds = roc_curve(y_test, y_test_pred)
plot_roc_curve(train_fpr, train_tpr, test_fpr, test_tpr)

# Find best threshold
best_t = find_best_threshold(tr_thresholds, train_fpr, train_tpr)

# Confusion matrix
test_confusion_matrix = confusion_matrix(y_test, predict_with_best_t(y_test_pred, best_t))
sns.heatmap(test_confusion_matrix, annot=True, fmt='', cmap='Oranges', cbar=False, xticklabels=['Prediction:Negative', 'Prediction:Positive'], yticklabels=['Actal:Negative', 'Actual:Positive'])

# Get top features
list_of_features = vectorizer.get_feature_names_out() + ['HelpfulnessNumerator', 'HelpfulnessDenominator', 'Time']
negative_features = get_top_features(list_of_features, NB_classifier, 0)
positive_features = get_top_features(list_of_features, NB_classifier, 1)

print("Top 20 features from the negative class:")
print(negative_features)

print("\nTop 20 features from the positive class:")
print(positive_features)
