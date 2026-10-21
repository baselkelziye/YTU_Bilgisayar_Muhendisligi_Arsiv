import pandas as pd
from bs4 import BeautifulSoup
import re
from sklearn.model_selection import train_test_split
import warnings
warnings.filterwarnings("ignore")

def Naive_Bayes():
    data = pd.read_csv('kaggle/Reviews.csv')
    # We will not consider reviews with 'Score' 3, so we are dropping all the rows with 'Score' feature equals 3 
    data = data[data['Score'] != 3]  
    # Give reviews with Score>3 will be considered as having a positive rating, and reviews with a score<3 as a negative rating.
    def partition(x):  # Given x, it returns 1 if x>3 else returns 0
        if x < 3:
            return 0
        return 1
    # Changing reviews with a score less than 3 to be negative(0) and greater than 3 to be positive(1) 
    actual_score = data['Score']  
    positive_negative = actual_score.map(partition)  
    data['Score'] = positive_negative
    # Sorting data according to ProductId in ascending order
    sorted_data = data.sort_values('ProductId', axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')

    # Dropping Deduplication of entries
    final = sorted_data.drop_duplicates(subset={"UserId", "ProfileName", "Time", "Text"}, keep='first', inplace=False)

    def decontracted(phrase):  # This function expands English language contractions such as (that's) to ('that is')
        # Specific
        phrase = re.sub(r"won't", "will not", phrase)
        phrase = re.sub(r"can\'t", "can not", phrase)

        # General
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
    # We are removing the words from the stop words list: 'no', 'nor', 'not'
    stopwords = set(['br', 'the', 'i', 'me', 'my', 'myself', 'we', 'our', 'ours', 'ourselves', 'you', "you're", "you've",\
                     "you'll", "you'd", 'your', 'yours', 'yourself', 'yourselves', 'he', 'him', 'his', 'himself', \
                     'she', "she's", 'her', 'hers', 'herself', 'it', "it's", 'its', 'itself', 'they', 'them', 'their',\
                     'theirs', 'themselves', 'what', 'which', 'who', 'whom', 'this', 'that', "that'll", 'these', 'those', \
                     'am', 'is', 'are', 'was', 'were', 'be', 'been', 'being', 'have', 'has', 'had', 'having', 'do', 'does', \
                     'did', 'doing', 'a', 'an', 'the', 'and', 'but', 'if', 'or', 'because', 'as', 'until', 'while', 'of', \
                     'at', 'by', 'for', 'with', 'about', 'against', 'between', 'into', 'through', 'during', 'before', 'after',\
                     'above', 'below', 'to', 'from', 'up', 'down', 'in', 'out', 'over', 'under', 'again', 'further',\
                     'then', 'once', 'here', 'there', 'when', 'where', 'why', 'how', 'all', 'any', 'both', 'each', 'few', 'more',\
                     'most', 'other', 'some', 'such', 'only', 'own', 'same', 'so', 'than', 'too', 'very', \
                     's', 't', 'can', 'will', 'just', 'don', "don't", 'should', "should've", 'now', 'd', 'll', 'm', 'o', 're', \
                     've', 'y', 'ain', 'aren', "aren't", 'couldn', "couldn't", 'didn', "didn't", 'doesn', "doesn't", 'hadn',\
                     "hadn't", 'hasn', "hasn't", 'haven', "haven't", 'isn', "isn't", 'ma', 'mightn', "mightn't", 'mustn',\
                     "mustn't", 'needn', "needn't", 'shan', "shan't", 'shouldn', "shouldn't", 'wasn', "wasn't", 'weren', "weren't", \
                     'won', "won't", 'wouldn', "wouldn't"])

    preprocessed_reviews = []    
    for sentence in final['Text'].values:  
        sentence = re.sub(r"http\S+", "", sentence)
        sentence = BeautifulSoup(sentence, 'lxml').get_text()
        sentence = decontracted(sentence)
        sentence = re.sub("\S*\d\S*", "", sentence).strip()
        sentence = re.sub('[^A-Za-z]+', ' ', sentence)
        # https://gist.github.com/sebleier/554280
        sentence = ' '.join(e.lower() for e in sentence.split() if e.lower() not in stopwords)
        preprocessed_reviews.append(sentence.strip())

    preprocessed_Summary = []
    # tqdm is for printing the status bar
    for sentence in final['Summary'].values:
        sentence = re.sub(r"http\S+", "", str(sentence))
        sentence = BeautifulSoup(sentence, 'lxml').get_text()
        sentence = decontracted(sentence)
        sentence = re.sub("\S*\d\S*", "", sentence).strip()
        sentence = re.sub('[^A-Za-z]+', ' ', sentence)
        # https://gist.github.com/sebleier/554280
        sentence = ' '.join(e.lower() for e in sentence.split() if e.lower() not in stopwords)
        preprocessed_Summary.append(sentence.strip())

    # Let's replace the 'Summary' and 'Text' column with the preprocessed data.  
    final["Summary"] = preprocessed_Summary
    final['Text'] = preprocessed_reviews
    final.drop(['UserId', 'ProfileName'], axis=1, inplace=True)  # Not considering these columns for classification.

    final.reset_index(inplace=True)
    final.drop(['index'], axis=1, inplace=True)
    
    y = final['Score'].values
    X = final.drop(['Score'], axis=1)

    # Splitting the data and class labels into the train set and test set  
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, stratify=y)

    print('Train data shape', X_train.shape)
    print('Train data labels shape ', y_train.shape)
    print('Test data shape', X_test.shape)
    print('Test data labels shape', y_test.shape)
    from sklearn.feature_extraction.text import TfidfVectorizer
    from sklearn.naive_bayes import MultinomialNB
    from sklearn.metrics import accuracy_score, classification_report

    # Assuming X_train, X_test, y_train, y_test are available from the previous code

    # Text Vectorization using TF-IDF
    tfidf_vectorizer = TfidfVectorizer(max_features=5000)  # You can adjust max_features
    X_train_tfidf = tfidf_vectorizer.fit_transform(X_train['Text'])
    X_test_tfidf = tfidf_vectorizer.transform(X_test['Text'])

    # Model Training
    naive_bayes_model = MultinomialNB()
    naive_bayes_model.fit(X_train_tfidf, y_train)

    # Model Prediction
    y_pred = naive_bayes_model.predict(X_test_tfidf)

    # Model Evaluation
    accuracy = accuracy_score(y_test, y_pred)
    print(f"Accuracy: {accuracy:.2f}")

    # Display classification report
    print("\nClassification Report:")
    print(classification_report(y_test, y_pred))

    print(y_pred)

    for user, product_id, actual, predicted in zip(X_test['Id'].head(5), X_test['ProductId'].head(5), y_test[:5], y_pred[:5]):
        print(f"User: {user}, ProductId: {product_id}, Actual: {actual}, Predicted: {predicted}")

    return X_test, y_test, y_pred

