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
import re
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.preprocessing import Normalizer
# library for splitting the dataset
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import Normalizer
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
from sklearn.feature_extraction.text import TfidfVectorizer

def Naive_Bayes():
    data = pd.read_csv('kaggle/Reviews.csv')
    #  we will not consider reviews with 'Score' 3, so we are droping all the rows with 'Score' feature equals 3 
    data=data[data['Score']!=3]  
    # Give reviews with Score>3 will be considered as having positive rating, and reviews with a score<3 as negative rating.
    def partition(x):  # given x it returns 1 if x>3 else returns 0
        if x < 3:
            return 0
        return 1

    #changing reviews with score less than 3 to be negative(0) and greater the 3 to be positive(1) 
    actual_score = data['Score']  
    positive_negative = actual_score.map(partition)  
    data['Score'] = positive_negative
    '''


    labels = 'Positive Reviews', 'Negative Reviews'
    sizes = [443777, 82037]
    fig1, ax1 = plt.subplots()
    ax1.pie(sizes, labels=labels, autopct='%1.1f%%',
            shadow=True, startangle=90)
    ax1.axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.

    plt.show()
    '''

    # Sorting data according to ProductId in ascending order
    sorted_data = data.sort_values('ProductId', axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')

    # Droping Deduplication of entries
    final=sorted_data.drop_duplicates(subset={"UserId","ProfileName","Time","Text"}, keep='first', inplace=False)

    # https://stackoverflow.com/a/47091490/4084039
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
    for sentance in tqdm(final['Text'].values):  
        sentance = re.sub(r"http\S+", "", sentance)
        sentance = BeautifulSoup(sentance, 'lxml').get_text()
        sentance = decontracted(sentance)
        sentance = re.sub("\S*\d\S*", "", sentance).strip()
        sentance = re.sub('[^A-Za-z]+', ' ', sentance)
        # https://gist.github.com/sebleier/554280
        sentance = ' '.join(e.lower() for e in sentance.split() if e.lower() not in stopwords)
        preprocessed_reviews.append(sentance.strip())

    preprocessed_Summary = []
    # tqdm is for printing the status bar
    for sentance in tqdm(final['Summary'].values):
        sentance = re.sub(r"http\S+", "", str(sentance))
        sentance = BeautifulSoup(sentance, 'lxml').get_text()
        sentance = decontracted(sentance)
        sentance = re.sub("\S*\d\S*", "", sentance).strip()
        sentance = re.sub('[^A-Za-z]+', ' ', sentance)
        # https://gist.github.com/sebleier/554280
        sentance = ' '.join(e.lower() for e in sentance.split() if e.lower() not in stopwords)
        preprocessed_Summary.append(sentance.strip())


    # let's replace the 'Summary' and 'Text' column with the preprocessed data.  
    final["Summary"] = preprocessed_Summary
    final['Text'] = preprocessed_reviews
    final.drop(['Id', 'ProductId', 'UserId', 'ProfileName'], axis = 1, inplace=True)  # not considering these columns for classification.

    final.reset_index(inplace=True)
    final.drop(['index'], axis=1, inplace=True)
    final.head()  # this is our final dataset

    # seperating the class column from the dataset
    y = final['Score'].values
    X = final.drop(['Score'], axis=1)

    # splitting the data and class labels in to train set and test set  
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, stratify=y)

    print('train data shape', X_train.shape)
    print('train data labels shape ', y_train.shape)
    print('test data shape', X_test.shape)
    print('test data labels shape', y_test.shape)

    ### Text feature 
    # calling the CountVectorizer class with three parameters 
    vectorizer = CountVectorizer(min_df=10, ngram_range=(1,4), max_features=5000)
    vectorizer.fit(X_train['Text'].values) # fitting the model with train data

    # we use the fitted CountVectorizer to convert the text to vector
    X_train_text = vectorizer.transform(X_train['Text'].values)
    X_test_text = vectorizer.transform(X_test['Text'].values)

    # getting the features 
    features_text = vectorizer.get_feature_names_out()  # we will be using this afterwords 

    print("After vectorizations using BOW")
    print(X_train_text.shape, y_train.shape)
    print(X_test_text.shape, y_test.shape)

    # calling the CountVectorizer class with three parameters 
    vectorizer = CountVectorizer(min_df=10, ngram_range=(1,4), max_features=5000)
    vectorizer.fit(X_train['Summary'].values) # fitting the model with train data

    # we use the fitted CountVectorizer to convert the text to vector
    X_train_summary = vectorizer.transform(X_train['Summary'].values)
    X_test_summary = vectorizer.transform(X_test['Summary'].values)

    # getting the features of bow vectorization 
    features_summary = vectorizer.get_feature_names_out() # we will be using this afterwords 

    print("After vectorizations using BOW")
    print(X_train_summary.shape, y_train.shape)
    print(X_test_summary.shape, y_test.shape)
    """
    # "HelpfulnessNumerator" feature
    normalizer = Normalizer() # normalizing numerical features such that all numerical features are in same range. 

    normalizer.fit(X_train['HelpfulnessNumerator'].values.reshape(-1,1))

    X_train_help_num_norm = normalizer.transform(X_train['HelpfulnessNumerator'].values.reshape(1,-1)).reshape(-1,1)
    X_test_help_num_norm = normalizer.transform(X_test['HelpfulnessNumerator'].values.reshape(1,-1)).reshape(-1,1)


    print("After normalization of price feature")
    print(X_train_help_num_norm.shape, y_train.shape)
    print(X_test_help_num_norm.shape, y_test.shape)
    print("="*100)
    """



    # Reshape the input data for normalization
    helpfulness_train = X_train['HelpfulnessNumerator'].values.reshape(-1, 1)
    helpfulness_test = X_test['HelpfulnessNumerator'].values.reshape(-1, 1)

    # Create and fit the normalizer
    normalizer = Normalizer()
    normalizer.fit(helpfulness_train)

    # Transform the training and testing data
    X_train_help_num_norm = normalizer.transform(helpfulness_train)
    X_test_help_num_norm = normalizer.transform(helpfulness_test)

    print("After normalization of HelpfulnessNumerator feature")
    print(X_train_help_num_norm.shape, y_train.shape)
    print(X_test_help_num_norm.shape, y_test.shape)
    print("=" * 100)

    """
    # "HelpfulnessDenominator" feature
    normalizer = Normalizer()

    normalizer.fit(X_train['HelpfulnessDenominator'].values.reshape(-1,1))

    X_train_help_den_norm = normalizer.transform(X_train['HelpfulnessDenominator'].values.reshape(1,-1)).reshape(-1,1)
    X_test_help_den_norm = normalizer.transform(X_test['HelpfulnessDenominator'].values.reshape(1,-1)).reshape(-1,1)


    print("After normalization of price feature")
    print(X_train_help_den_norm.shape, y_train.shape)
    print(X_test_help_den_norm.shape, y_test.shape)
    print("="*100)
    """


    # Reshape the input data for normalization
    helpfulness_den_train = X_train['HelpfulnessDenominator'].values.reshape(-1, 1)
    helpfulness_den_test = X_test['HelpfulnessDenominator'].values.reshape(-1, 1)

    # Create and fit the normalizer
    normalizer = Normalizer()
    normalizer.fit(helpfulness_den_train)

    # Transform the training and testing data
    X_train_help_den_norm = normalizer.transform(helpfulness_den_train)
    X_test_help_den_norm = normalizer.transform(helpfulness_den_test)

    print("After normalization of HelpfulnessDenominator feature")
    print(X_train_help_den_norm.shape, y_train.shape)
    print(X_test_help_den_norm.shape, y_test.shape)
    print("=" * 100)

    """
    # "Time" feature
    normalizer = Normalizer()

    normalizer.fit(X_train['Time'].values.reshape(-1,1))

    X_train_time_norm = normalizer.transform(X_train['Time'].values.reshape(1,-1)).reshape(-1,1)
    X_test_time_norm = normalizer.transform(X_test['Time'].values.reshape(1,-1)).reshape(-1,1)


    print("After normalization of price feature")
    print(X_train_time_norm.shape, y_train.shape)
    print(X_test_time_norm.shape, y_test.shape)
    print("="*100)
    """



    # Reshape the input data for normalization
    time_train = X_train['Time'].values.reshape(-1, 1)
    time_test = X_test['Time'].values.reshape(-1, 1)

    # Create and fit the normalizer
    normalizer = Normalizer()
    normalizer.fit(time_train)

    # Transform the training and testing data
    X_train_time_norm = normalizer.transform(time_train)
    X_test_time_norm = normalizer.transform(time_test)

    print("After normalization of Time feature")
    print(X_train_time_norm.shape, y_train.shape)
    print(X_test_time_norm.shape, y_test.shape)
    print("=" * 100)

    # reference : merge two sparse matrices: https://stackoverflow.com/a/19710648/4084039
    from scipy.sparse import hstack

    X_tr = hstack((X_train_text, X_train_summary, X_train_help_num_norm,  # train data after BOW representation for 'Text' and 'Summary' feature.
                    X_train_help_den_norm, X_train_time_norm)).tocsr()

    X_te = hstack((X_test_text, X_test_summary, X_test_help_num_norm,  # test data after BOW representation for 'Text' and 'Summary' feature.
                    X_test_help_den_norm, X_test_time_norm)).tocsr()


    print("Final Data matrix with BOW representation for essay")
    print(X_tr.shape, y_train.shape)
    print(X_te.shape, y_test.shape)
    print("="*100)

    # https://scikit-learn.org/stable/modules/generated/sklearn.model_selection.GridSearchCV.html

    # using grid search for finding the best alpha for laplace smoothing/additive smoothing 
    from sklearn.model_selection import GridSearchCV

    NB_classifier = MultinomialNB(class_prior=[0.5, 0.5]) 
    
    parameters = {'alpha': [0.001, 0.05, 0.01, 0.1, 0.2, 0.3, 0.4, 0.5, 1, 2, 3, 4, 5, 10, 20, 25, 30, 50, 70, 100]}  # various values of alhap's to choose from.
    clf = GridSearchCV(NB_classifier, parameters, cv=5, scoring='roc_auc', return_train_score=True)  # gridsearchCV with 5 fold cross validation .
    clf.fit(X_tr, y_train)

    results = pd.DataFrame.from_dict(clf.cv_results_) 
    results = results.sort_values(['param_alpha'])

    cv_auc = results['mean_test_score']      # mean test scores for every 'alpha'
    train_auc = results['mean_train_score']  # mean train scores for every 'alpha

    alpha =  list(results['param_alpha']) 
    alpha=np.log(alpha)   # taking log of alphas so to make the plot more readable

    plt.plot(alpha, train_auc, label='Train AUC')
    plt.plot(alpha, cv_auc, label='CV AUC')

    plt.scatter(alpha, train_auc, label='Train AUC points')
    plt.scatter(alpha, cv_auc, label='CV AUC points')


    plt.legend()
    plt.xlabel("log(alpha): hyperparameters")
    plt.ylabel("AUC")
    plt.title("Hyper parameters Vs AUC plot")
    plt.grid()
    plt.show()

    clf.best_estimator_ # using this estimator lets predict the labels of test dataset

    NBclassifier = MultinomialNB(alpha=0.2, class_prior=[0.5, 0.5], fit_prior=True)
    NBclassifier.fit(X_tr, y_train)
    # roc_auc_score(y_true, y_score) the 2nd parameter should be probability estimates of the positive class
    # not the predicted outputs

    y_train_pred = NBclassifier.predict_proba(X_tr)[:,1]     # predicted probabilities of train datapoints belonging to positive class
    y_test_pred = NBclassifier.predict_proba(X_te)[:,1]      # predicted probabilities of test datapoints belonging to positive class

    train_fpr, train_tpr, tr_thresholds = roc_curve(y_train, y_train_pred)   # fpr and tpr for train data
    test_fpr, test_tpr, te_thresholds = roc_curve(y_test, y_test_pred)       # fpr and tpr for test data

    plt.plot(train_fpr, train_tpr, label="train AUC ="+str(auc(train_fpr, train_tpr)))
    plt.plot(test_fpr, test_tpr, label="test AUC ="+str(auc(test_fpr, test_tpr)))
    plt.legend()
    plt.xlabel("fpr")
    plt.ylabel("tpr")
    plt.title("ROC curve")
    plt.grid()
    plt.show()

    # reference : Applied AI course lectures
    # we are writing our own function for predict, with defined thresould
    # we will pick a threshold that will give the least fpr
    def find_best_threshold(threshould, fpr, tpr):
        t = threshould[np.argmax(tpr*(1-fpr))]
        # (tpr*(1-fpr)) will be maximum if your fpr is very low and tpr is very high
        print("the maximum value of tpr*(1-fpr)", max(tpr*(1-fpr)), "for threshold", np.round(t,3))
        return t

    def predict_with_best_t(proba, threshould):
        predictions = []
        for i in proba:
            if i>=threshould:
                predictions.append(1)
            else:
                predictions.append(0)
        return predictions

    from sklearn.metrics import confusion_matrix

    best_t = find_best_threshold(tr_thresholds, train_fpr, train_tpr)  # getting the best threshold for separating the positive classes form negative 

    test_confusion_matrix = confusion_matrix(y_test, predict_with_best_t(y_test_pred, best_t))  # calculates the confusion matrix

    # below code is taken from  https://medium.com/@dtuk81/confusion-matrix-visualization-fc31e3f30fea

    group_names = ['True Neg','False Pos','False Neg','True Pos']

    group_counts = ['{0:0.0f}'.format(value) for value in
                    test_confusion_matrix.flatten()]

    labels = [f'{v1}\n{v2}' for v1, v2 in
            zip(group_names,group_counts)]
    labels = np.asarray(labels).reshape(2,2)

    print("Test confusion matrix")
    sns.heatmap(test_confusion_matrix, annot=labels, fmt='', cmap='Oranges',cbar=False, xticklabels=['Prediction:Negative', 'Prediction:Positive'], yticklabels=['Actal:Negative', 'Actual:Positive'])

    list_of_features = features_text + features_summary + ['HelpfulnessNumerator', 'HelpfulnessDenominator', 'Time']


    # Top 20 features form negative class
    features = np.argsort(NBclassifier.feature_log_prob_[0]) # sorting the features log probability for negtive class
                                                                #  form low probability to high probability and getting its indice 

    features = features[::-1]  # reversing it form high probability to low probability indice

    for i in features[:20]:  # printing top 20 features from negative calss
        print(list_of_features[i])


    # Top 20 features form negative class
    features = np.argsort(NBclassifier.feature_log_prob_[1]) # sorting the features log probability for negtive class
                                                                #  form low probability to high probability and getting its indice 

    features = features[::-1]  # reversing it form high probability to low probability indice

    for i in features[:20]:  # printing top 20 features from negative calss
        print(list_of_features[i])

    # Sample user data (replace this with the actual data for the user)
    user_data = {
        'Text': 'This is a sample review text for the user.',
        'Summary': 'Sample summary',
        'HelpfulnessNumerator': 5,
        'HelpfulnessDenominator': 10,
        'Time': 1609459200  # Replace with the user's timestamp
    }

    # Create a DataFrame with the user's data
    user_df = pd.DataFrame([user_data])

    # Preprocess the user's data
    user_df['Text'] = user_df['Text'].apply(lambda x: BeautifulSoup(x, 'lxml').get_text())
    user_df['Text'] = user_df['Text'].apply(lambda x: decontracted(x))  # Assuming 'decontracted' is defined
    user_df['Summary'] = user_df['Summary'].apply(lambda x: BeautifulSoup(x, 'lxml').get_text())
    user_df['Summary'] = user_df['Summary'].apply(lambda x: decontracted(x))

    # Vectorize the user's text and summary features
    user_text_vectorized = vectorizer.transform(user_df['Text'].values)
    user_summary_vectorized = vectorizer.transform(user_df['Summary'].values)

    # Normalize numerical features for the user
    user_help_num_norm = normalizer.transform(user_df['HelpfulnessNumerator'].values.reshape(-1, 1))
    user_help_den_norm = normalizer.transform(user_df['HelpfulnessDenominator'].values.reshape(-1, 1))
    user_time_norm = normalizer.transform(user_df['Time'].values.reshape(-1, 1))

    # Concatenate the vectorized features with normalized numerical features
    user_features = hstack((user_text_vectorized, user_summary_vectorized, user_help_num_norm,
                            user_help_den_norm, user_time_norm)).tocsr()

    # Predict the class for the user's data
    user_predictions = NBclassifier.predict(user_features)

    # Print the prediction
    if user_predictions[0] == 1:
        print("Positive Recommendation")
    else:
        print("Negative Recommendation")

    return 0



