# -*- coding: utf-8 -*-
"""
Created on Tue Dec  8 22:04:44 2020

@author: asus
"""

#from wordcloud import WordCloud
#import matplotlib.pyplot as plt 
import pandas as pd # Dataframe
import seaborn as sns
import string
import nltk
import re
from nltk.corpus import stopwords
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import classification_report, confusion_matrix
import enchant 

nltk.download('stopwords')
dictionary = enchant.Dict("en_US")

#%%

tweets_df = pd.read_csv('C:/Users/asus/Desktop/Projects/NLP Project/Sentiment Analysis 5 (FINAL)/sentiment_tweets.csv', encoding = "ISO-8859-1", engine='python')

#%%
 
tweets_df.info()

tweets_df = tweets_df.drop(['tweeter'], axis = 1)
tweets_df = tweets_df.drop(['query'], axis = 1)
tweets_df = tweets_df.drop(['date'], axis = 1)
tweets_df = tweets_df.drop(['id'], axis = 1)

tweets_df.info()

#%%

sns.countplot(tweets_df['label'], label='count')

#%%

positive = tweets_df[tweets_df['label']==4]
negative = tweets_df[tweets_df['label']==0]

pst = positive['tweet'].to_numpy()
ngt = negative['tweet'].to_numpy()

optimizedTweets = []
optimizedLabels = []

for i in range (0,248576):
    optimizedTweets.append(pst[i])
    optimizedLabels.append(4)
    optimizedTweets.append(ngt[i])
    optimizedLabels.append(0)



#%%

stops = stopwords.words('english')
stops.append("user")
stops.append("amp") 
stops.append("amp") 
stops.append("quot") 

for i in range (len(optimizedTweets)):
    #print(i , " FROM: ", tweets_df['tweet'][i])
    mentions = re.findall('@([^\s]+)', optimizedTweets[i])
    for ment in mentions:
        ment = '@' + ment 
        optimizedTweets[i] = optimizedTweets[i].replace(ment, ' ')
        
    #hashtags = re.findall('#([^\s]+)', tweets_df['tweet'][i])
    #for ht in hashtags:
    #    ht = '#' + ht
    #    tweets_df['tweet'][i] = tweets_df['tweet'][i].replace(ht, ' ')
    
    txt = ""
    for ch in optimizedTweets[i]:
        if (ch not in string.punctuation):
            txt = txt + ch.lower()
        else:
            txt = txt + " "
    optimizedTweets[i] = txt
        
    txt = ""
    words = re.findall('\s?([a-zA-z]+)\s?', optimizedTweets[i])
    for word in words:
        if (word not in (stops)):# and (dictionary.check(word)):
            txt = txt + str(word) + " "
    optimizedTweets[i] = txt
    
    if len(optimizedTweets[i])==0:
        optimizedLabels[i] = 2
        
    #print("TO: ", tweets_df['tweet'][i], "\n")
    
#%%
# =============================================================================
# print("Wordcloud for all tweets")
# 
# sentences = optimizedTweets
# sentences_as_one = ' '.join(sentences)
# plt.figure(figsize=(10,10))
# wc_all = WordCloud().generate(sentences_as_one)
# plt.imshow(wc_all)
# wc_all.to_file("C:/Users/asus/Desktop/Projects/NLP Project/Sentiment Analysis 5 (FINAL)/word_cloud_all.png")
# =============================================================================

#%%

# =============================================================================
# print("Wordcloud for negative tweets")
# 
# negatives = ngt
# negatives_as_one = ' '.join(negatives)
# plt.figure(figsize=(10,10))
# wc_neg = WordCloud().generate(negatives_as_one)
# plt.imshow(wc_neg)
# wc_neg.to_file("C:/Users/asus/Desktop/Projects/NLP Project/Sentiment Analysis 5 (FINAL)/word_cloud_neg.png")
# =============================================================================

#%%

# =============================================================================
# print("Wordcloud for positive tweets")
# 
# positives = pst
# positives_as_one = ' '.join(positives)
# plt.figure(figsize=(10,10))
# wc_pos = WordCloud().generate(positives_as_one)
# plt.imshow(wc_pos)
# wc_pos.to_file("C:/Users/asus/Desktop/Projects/NLP Project/Sentiment Analysis 5 (FINAL)/word_cloud_pos.png")
# =============================================================================

#%%
    
vectorizer = CountVectorizer()
vectorizedTweets = vectorizer.fit_transform(optimizedTweets)

print(len(vectorizer.get_feature_names()), " unique words.")
#print(vectorizedTweets.shape)

#%%

x = vectorizedTweets
y = optimizedLabels

X_train, X_test, y_train, y_test = train_test_split(x, y, test_size = 0.1)

nb_classifier = MultinomialNB()
nb_classifier.fit(X_train, y_train)

#%%

y_predict_test = nb_classifier.predict(X_test)
conMtx = confusion_matrix(y_test, y_predict_test)
sns.heatmap(conMtx, annot= True)

#%%
print(classification_report(y_test, y_predict_test))

#%%

import pickle

f = open('my_classifier', 'wb')

pickle.dump(nb_classifier, f)

f.close()

#%%

shouldLoop = "y"

while (shouldLoop == "y"):
    print("Please enter tweet to classify...")
    exampleTweet = input()
    validTweet = True
    
    mentions = re.findall('@([^\s]+)', exampleTweet)
    for ment in mentions:
        ment = '@' + ment 
        exampleTweet = exampleTweet.replace(ment, ' ')
    
    txt = ""
    for ch in exampleTweet:
        if (ch not in string.punctuation):
            txt = txt + ch.lower()
        else:
            txt = txt + " "
    exampleTweet = txt
        
    txt = ""
    words = re.findall('\s?([a-zA-z]+)\s?', exampleTweet)
    for word in words:
        if (word not in (stops)) and (dictionary.check(word)):
            txt = txt + str(word) + " "
    exampleTweet = txt
    
    if len(exampleTweet)==0:
        validTweet = False
        
    #print("Tweet processed into: ", exampleTweet)
            
    if validTweet:      
        tweetsArray = []
        for twt in optimizedTweets:
            tweetsArray.append(twt)
        tweetsArray.append(exampleTweet)
        labelsArray = []
        for lbl in optimizedLabels:
            labelsArray.append(lbl)
        labelsArray.append(2)
        
        vectorizerTest = CountVectorizer()
        vectorizedTest = vectorizerTest.fit_transform(tweetsArray)
        
        x = vectorizedTest[:-1]
        y = labelsArray[:-1]
        
        X_train, X_test, y_train, y_test = train_test_split(x, y, test_size = 0.1)
        
        nb_classifier = MultinomialNB()
        nb_classifier.fit(X_train, y_train)
        
        y_predict_eg = nb_classifier.predict(vectorizedTest[-1])
        
        if y_predict_eg[-1] == 0:
            print(">>NEGATIVE")
        else:
            print(">>POSITIVE")
    else:
        print("Cannot be classified.")
        
    print("\n\nTry again? (y/n)")
    shouldLoop = input()


