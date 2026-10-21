"""
import warnings
warnings.filterwarnings("ignore")
import sqlite3
import pandas as pd
import numpy as np
import nltk
import string
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics import confusion_matrix
from sklearn import metrics
from sklearn.metrics import roc_curve, auc
from nltk.stem.porter import PorterStemmer
import re
# Tutorial about Python regular expressions: https://pymotw.com/2/re/
import string
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
from nltk.stem.wordnet import WordNetLemmatizer
from gensim.models import Word2Vec
from gensim.models import KeyedVectors
import pickle
from tqdm import tqdm
import os
from sklearn.metrics import accuracy_score
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from tqdm import tqdm
from bs4 import BeautifulSoup
import re

def K_Nearest_Neighbors():


    return 0

# using the SQLite Table to read data.
con = sqlite3.connect('kaggle/database.sqlite') 
#filtering only positive and negative reviews i.e. 
# not taking into consideration those reviews with Score=3
# SELECT * FROM Reviews WHERE Score != 3 LIMIT 500000, will give top 500000 data points
# you can change the number to any other number based on your computing power
"""
# filtered_data = pd.read_sql_query(""" SELECT * FROM Reviews WHERE Score != 3 LIMIT 500000""", con) 
# for tsne assignment you can take 5k data points

#filtered_data = pd.read_sql_query(""" SELECT * FROM Reviews WHERE Score != 3 LIMIT 5000""", con) 
"""
# Give reviews with Score>3 a positive rating, and reviews with a score<3 a negative rating.
def partition(x):
    if x < 3:
        return 0
    return 1

#changing reviews with score less than 3 to be positive and vice-versa
actualScore = filtered_data['Score']
positiveNegative = actualScore.map(partition)
filtered_data['Score'] = positiveNegative
print("Number of data points in our data", filtered_data.shape)
filtered_data.head(3)
#Sorting data according to ProductId in ascending order
sorted_data=filtered_data.sort_values('ProductId', axis=0, ascending=True, inplace=False, kind='quicksort', na_position='last')

#Deduplication of entries
final=sorted_data.drop_duplicates(subset={"UserId","ProfileName","Time","Text"}, keep='first', inplace=False)
final=final[final.HelpfulnessNumerator<=final.HelpfulnessDenominator]
#Before starting the next phase of preprocessing lets see the number of entries left
#How many positive and negative reviews are present in our dataset?
final['Score'].value_counts()


def decontracted(phrase):
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
# tqdm is for printing the status bar
for sentance in tqdm(final['Text'].values):
    sentance = re.sub(r"http\S+", "", sentance)
    sentance = BeautifulSoup(sentance, 'lxml').get_text()
    sentance = decontracted(sentance)
    sentance = re.sub("\S*\d\S*", "", sentance).strip()
    sentance = re.sub('[^A-Za-z]+', ' ', sentance)
    # https://gist.github.com/sebleier/554280
    sentance = ' '.join(e.lower() for e in sentance.split() if e.lower() not in stopwords)
    preprocessed_reviews.append(sentance.strip())
preprocessed_reviews[1500]
tf_idf_vect = TfidfVectorizer(ngram_range=(1,2), min_df=10)
tf_idf_vect.fit(preprocessed_reviews)
print("some sample features(unique words in the corpus)",tf_idf_vect.get_feature_names_out()[0:10])
print('='*50)

final_tf_idf = tf_idf_vect.transform(preprocessed_reviews)
print("the type of count vectorizer ",type(final_tf_idf))
print("the shape of out text TFIDF vectorizer ",final_tf_idf.get_shape())
print("the number of unique words including both unigrams and bigrams ", final_tf_idf.get_shape()[1])
from sklearn.manifold import TSNE   
tsne = TSNE(n_components=2, perplexity=30, learning_rate=200, init='random')

X_embedding = tsne.fit_transform(final_tf_idf)

for_tsne_df = pd.DataFrame(X_embedding, columns=['Dim_X','Dim_Y'])
for_tsne_df['Score'] = final['Score'].tolist()


colors = {0:'red',1:'blue',2:'green'}
plt.scatter(for_tsne_df['Dim_X'], for_tsne_df['Dim_Y'], c=for_tsne_df['Score'].apply(lambda x : colors[x]))
plt.show()



X_train,X_test, y_train, y_test = train_test_split(for_tsne_df[["Dim_X","Dim_Y"]], for_tsne_df["Score"], test_size=0.3, stratify=for_tsne_df["Score"], random_state = 42)
X_train,X_cv, y_train, y_cv = train_test_split(X_train[["Dim_X","Dim_Y"]], y_train, test_size=0.2, stratify=y_train, random_state = 42)

for i in range(1,30,2):
    knn = KNeighborsClassifier(n_neighbors=i)
    knn.fit(X_train,y_train)
    pred = knn.predict(X_cv)
    acc = accuracy_score(y_cv,pred, normalize=True)*100
    #print('\nCV accuracy for k = %d is %d%%' % (i, acc))
    
knn = KNeighborsClassifier(n_neighbors=9)
knn.fit(X_train,y_train)
predictions = knn.predict(X_test)
acc = accuracy_score(y_test,predictions, normalize=True)*100
#print('\nCV accuracy for k = %d is %d%%' % (9, acc))

X_train,X_test, y_train, y_test = train_test_split(for_tsne_df[["Dim_X","Dim_Y"]], for_tsne_df["Score"], test_size=0.3, stratify=for_tsne_df["Score"], random_state = 42)

myList = list(range(1,50))
neighbors = list(filter(lambda x : x%2 !=0,myList))
cv_score = []

for k in neighbors:
    knn = KNeighborsClassifier(n_neighbors=k)
    scores = cross_val_score(knn,X_train, y_train, cv=3,scoring='accuracy')
    cv_score.append(np.round(scores.mean()*100,2))
    
MSE = [100-x for x in cv_score]

# plot misclassification error vs k 
plt.figure(figsize=(15,10))
plt.plot(neighbors, MSE)

for xy in zip(neighbors, np.round(MSE,3)):
    plt.annotate('(%s, %s)' % xy, xy=xy, textcoords='data')

plt.xlabel('Number of Neighbors K')
plt.ylabel('Misclassification Error')

plt.show()

print("the misclassification error for each k value is : ", np.round(MSE,3))

knn = KNeighborsClassifier(n_neighbors=15)
knn.fit(X_train,y_train)
pred_train = knn.predict(X_train)
pred_test = knn.predict(X_test)


print("Train Recall : ",metrics.recall_score(y_train,pred_train))
print("Test Recall : ", metrics.recall_score(y_test,pred_test))
print("Train Precision : ",metrics.precision_score(y_train,pred_train))
print("Test Precision : ",metrics.precision_score(y_test,pred_test))
print("Train Accuracy :", metrics.f1_score(y_train,pred_train))
print("Test Accuracy :", metrics.f1_score(y_test,pred_test))



# Örnek bir kullanıcı için önceki değerlendirmeleri seçme
import random

# Rastgele bir kullanıcı seçme
random_user = random.choice(final['UserId'].unique())
print("Rastgele Secilen Kullanici:", random_user)

# Seçilen kullanıcının değerlendirmelerini seçme
user_reviews = final[final['UserId'] == random_user]

# Use the same TF-IDF vectorizer instance for the user's reviews
user_tfidf = tf_idf_vect.transform(user_reviews['Text'])

# Ensure that the number of features in user_tfidf matches the number used during training
#if user_tfidf.shape[1] != X_train.shape[1]:
    # Perform any necessary adjustments, such as adding missing features or reducing features
    # It's crucial to use the same vectorizer settings for both training and prediction
    # If the number of features is different, investigate why and adjust accordingly
    # You may need to retrain your model with the updated vectorizer
print("X_train shape:", X_train.shape)
print("user_tfidf shape:", user_tfidf.shape)

# K-NN modelini kullanarak önerilerde bulunma
user_recommendations = knn.kneighbors(user_tfidf, n_neighbors=5)

# Önerilen ürünleri görüntüleme
print("Seçilen Kullanıcı için Öneriler:")
for index in user_recommendations[1][0]:
    print("Önerilen Ürün:", final['Text'].iloc[index])


"""