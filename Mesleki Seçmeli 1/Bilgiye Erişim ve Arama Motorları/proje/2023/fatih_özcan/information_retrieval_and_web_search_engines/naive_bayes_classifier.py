import warnings
warnings.filterwarnings("ignore")
import pandas as pd
import numpy as np
import nltk
import string
import matplotlib.pyplot as plt
import seaborn as sns
from tqdm import tqdm   # tqdm is for printing the status bar
from bs4 import BeautifulSoup

# library for splitting the dataset
from sklearn.model_selection import train_test_split

# libraries for featurization  
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.preprocessing import Normalizer

# library for modeling 
from sklearn.naive_bayes import MultinomialNB

#  library for hyperparameter tuning
from sklearn.model_selection import GridSearchCV

# evaluation of model 
from sklearn.metrics import confusion_matrix
from sklearn import metrics
from sklearn.metrics import roc_curve, auc
import re
from tqdm import tqdm_notebook
def NBC():

    def preprocess_new_data(text):
        # Apply the same preprocessing steps as before
        text = re.sub(r"http\S+", "", text)
        text = BeautifulSoup(text, 'lxml').get_text()
        text = decontracted(text)
        text = re.sub("\S*\d\S*", "", text).strip()
        text = re.sub('[^A-Za-z]+', ' ', text)
        text = ' '.join(e.lower() for e in text.split() if e.lower() not in stopwords)
        return text.strip()

    data = pd.read_csv('kaggle/Reviews.csv')
    data=data[data['Score']!=3]

    def partition(x):  # given x it returns 1 if x>3 else returns 0
        if x < 3:
            return 0
        return 1
    actual_score = data['Score']  
    positive_negative = actual_score.map(partition)  
    data['Score'] = positive_negative
    sorted_data = data.sort_values('ProductId', axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')
    final=sorted_data.drop_duplicates(subset={"UserId","ProfileName","Time","Text"}, keep='first', inplace=False)
    final, test_data = train_test_split(final.sample(frac=0.1), test_size=0.3, random_state=0)

    def decontracted(phrase):  # this function expands english language contraction such as (that's) to ('that is')
        # specific
        phrase = re.sub(r"won't", "will not", phrase)
        phrase = re.sub(r"can\'t", "can not", phrase)

        # general
        phrase = re.sub(r"n\'t", " not", phrase)
        phrase = re.sub(r"\'re", " are", phrase)
        phrase = re.sub(r"\'s", " is", phrase)
        phrase = re.sub(r"\'d", " would", phrase)
        phrase = re.sub(r"\'ll", " will", phrase)
        phrase = re.sub(r"\'t", " not", phrase)
        phrase = re.sub(r"\'ve", " have", phrase)
        phrase = re.sub(r"\'m", " am", phrase)
        return phrase


    # https://gist.github.com/sebleier/554280
    # we are removing the words from the stop words list: 'no', 'nor', 'not'
    stopwords= set(['br', 'the', 'i', 'me', 'my', 'myself', 'we', 'our', 'ours', 'ourselves', 'you', "you're", "you've",\
                "you'll", "you'd", 'your', 'yours', 'yourself', 'yourselves', 'he', 'him', 'his', 'himself', \
                'she', "she's", 'her', 'hers', 'herself', 'it', "it's", 'its', 'itself', 'they', 'them', 'their',\
                'theirs', 'themselves', 'what', 'which', 'who', 'whom', 'this', 'that', "that'll", 'these', 'those', \
                'am', 'is', 'are', 'was', 'were', 'be', 'been', 'being', 'have', 'has', 'had', 'having', 'do', 'does', \
                'did', 'doing', 'a', 'an', 'the', 'and', 'but', 'if', 'or', 'because', 'as', 'until', 'while', 'of', \
                'at', 'by', 'for', 'with', 'about', 'against', 'between', 'into', 'through', 'during', 'before', 'after',\
                'above', 'below', 'to', 'from', 'up', 'down', 'in', 'out', 'on', 'off', 'over', 'under', 'again', 'further',\
                'then', 'once', 'here', 'there', 'when', 'where', 'why', 'how', 'all', 'any', 'both', 'each', 'few', 'more',\
                'most', 'other', 'some', 'such', 'only', 'own', 'same', 'so', 'than', 'too', 'very', \
                's', 't', 'can', 'will', 'just', 'don', "don't", 'should', "should've", 'now', 'd', 'll', 'm', 'o', 're', \
                've', 'y', 'ain', 'aren', "aren't", 'couldn', "couldn't", 'didn', "didn't", 'doesn', "doesn't", 'hadn',\
                "hadn't", 'hasn', "hasn't", 'haven', "haven't", 'isn', "isn't", 'ma', 'mightn', "mightn't", 'mustn',\
                "mustn't", 'needn', "needn't", 'shan', "shan't", 'shouldn', "shouldn't", 'wasn', "wasn't", 'weren', "weren't", \
                'won', "won't", 'wouldn', "wouldn't"])

    preprocessed_reviews = []    
    for sentance in final['Text'].values:
        sentance = re.sub(r"http\S+", "", sentance)
        sentance = BeautifulSoup(sentance, 'lxml').get_text()
        sentance = decontracted(sentance)
        sentance = re.sub("\S*\d\S*", "", sentance).strip()
        sentance = re.sub('[^A-Za-z]+', ' ', sentance)
        sentance = ' '.join(e.lower() for e in sentance.split() if e.lower() not in stopwords)
        preprocessed_reviews.append(sentance.strip())

    preprocessed_Summary = []
    # tqdm is for printing the status bar
    for sentance in final['Summary'].values:
        sentance = re.sub(r"http\S+", "", str(sentance))
        sentance = BeautifulSoup(sentance, 'lxml').get_text()
        sentance = decontracted(sentance)
        sentance = re.sub("\S*\d\S*", "", sentance).strip()
        sentance = re.sub('[^A-Za-z]+', ' ', sentance)
        # https://gist.github.com/sebleier/554280
        sentance = ' '.join(e.lower() for e in sentance.split() if e.lower() not in stopwords)
        preprocessed_Summary.append(sentance.strip())

    final["Summary"] = preprocessed_Summary
    final['Text'] = preprocessed_reviews
    final.drop(['Id', 'ProductId', 'UserId', 'ProfileName'], axis = 1, inplace=True)
    final.reset_index(inplace=True)
    final.drop(['index'], axis=1, inplace=True)

    y = final['Score'].values
    X = final.drop(['Score'], axis=1)

    # splitting the data and class labels in to train set and test set  
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, stratify=y)

    # Using TF-IDF Vectorizer
    tfidf_vectorizer = TfidfVectorizer(ngram_range=(1, 2), min_df=10, max_features=5000)
    X_train_tfidf = tfidf_vectorizer.fit_transform(X_train['Text'])
    X_test_tfidf = tfidf_vectorizer.transform(X_test['Text'])

    # Initialize the Multinomial Naive Bayes classifier
    nb_classifier = MultinomialNB()

    # Train the classifier
    nb_classifier.fit(X_train_tfidf, y_train)

    # Predictions on the test set
    y_pred = nb_classifier.predict(X_test_tfidf)

    # Confusion Matrix
    conf_matrix = confusion_matrix(y_test, y_pred)
    print("Confusion Matrix:\n", conf_matrix)

    # Classification Report
    print("\nClassification Report:\n", metrics.classification_report(y_test, y_pred))

    # ROC-AUC Score
    fpr, tpr, thresholds = roc_curve(y_test, y_pred)
    roc_auc = auc(fpr, tpr)
    print("\nROC-AUC Score:", roc_auc)

    # Define the hyperparameters to tune
    param_grid = {'alpha': [0.001, 0.01, 0.1, 1, 10, 100]}

    # Initialize GridSearchCV
    grid_search = GridSearchCV(MultinomialNB(), param_grid, cv=5, scoring='accuracy')

    # Fit the grid search to the data
    grid_search.fit(X_train_tfidf, y_train)

    # Get the best hyperparameters
    best_alpha = grid_search.best_params_['alpha']

    # Train the classifier with the best hyperparameters
    best_nb_classifier = MultinomialNB(alpha=best_alpha)
    best_nb_classifier.fit(X_train_tfidf, y_train)

    # Example for making a recommendation with the new data
    new_text = preprocess_new_data("Your new text data here")
    new_text_tfidf = tfidf_vectorizer.transform([new_text])
    recommendation = best_nb_classifier.predict(new_text_tfidf)
    print("Recommendation:", recommendation)


    # Randomly select an index
    random_index = np.random.randint(0, len(X_test))

    # Retrieve a user's information
    random_user_info = X_test.iloc[random_index]

    # Preprocess the user's data
    random_user_text = random_user_info['Text']
    random_user_summary = random_user_info['Summary']

    # Apply preprocessing to the text and summary using the correct function (preprocess_text)
    preprocessed_user_text = preprocess_new_data(random_user_text)
    preprocessed_user_summary = preprocess_new_data(random_user_summary)

    # Vectorize the user's data
    user_data_tfidf = tfidf_vectorizer.transform([preprocessed_user_text])

    # Make a recommendation
    user_recommendation = best_nb_classifier.predict(user_data_tfidf)[0]

    # Print the user index as the user identifier
    print("User ID (Index):", random_user_info.name)
    print("Text:", random_user_info['Text'])
    print("Summary:", random_user_info['Summary'])
    # Print the length of y_test
    print("Length of y_test:", len(y_test))

    # Check if the index is within the valid range
    if random_user_info.name < len(y_test):
        print("Actual Score:", y_test[random_user_info.name])
    else:
        print("Invalid index for y_test.")

    print("Model Recommendation:", user_recommendation)


    """
    # Preprocess the user's data
    random_user_text = random_user_info['Text']
    random_user_summary = random_user_info['Summary']

    # Apply preprocessing to the text and summary
    preprocessed_user_text = preprocess_new_data(random_user_text)
    preprocessed_user_summary = preprocess_new_data(random_user_summary)

    # Vectorize the user's data
    user_data_tfidf = tfidf_vectorizer.transform([preprocessed_user_text])

    # Make a recommendation
    user_recommendation = best_nb_classifier.predict(user_data_tfidf)[0]

    print("User ID:", random_user_info['UserId'])
    print("Text:", random_user_info['Text'])
    print("Summary:", random_user_info['Summary'])
    print("Actual Score:", y_test[random_index])
    print("Model Recommendation:", user_recommendation)
    """

    return user_recommendation, user_data_tfidf, random_user_info