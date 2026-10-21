import pandas as pd
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
import xgboost 
from sklearn import model_selection, preprocessing, linear_model, naive_bayes, metrics, svm
from sklearn import decomposition, ensemble

"""**BU PROGRAMDA KARAKTER TABANLI 1-GRAM COUNT VECTORIZER ICIN KLASİK YÖNTEMLERİN BAŞARI SONUÇLARI ELDE EDİLMİŞTİR**"""

train=pd.read_excel("clean_tweet_train.xlsx")
test=pd.read_excel("clean_tweet_test.xlsx")
train.head()

Train = train.append(test, ignore_index=True).fillna(' ')

train.dropna(inplace=True)
train.reset_index(drop=True,inplace=True)
train.info()

test.dropna(inplace=True)
test.reset_index(drop=True,inplace=True)
test.info()

x_train=train.text.tolist()
y_train=train.sentiment.tolist()
x_test=test.text.tolist()
y_test=test.sentiment.tolist()

count = CountVectorizer(analyzer='char',ngram_range=(1,1))
count.fit(Train['text'])
xtrain_count =  count.transform(x_train)
xtest_count =  count.transform(x_test)

def model_training(classifier, vector_train, y_train, vector_test):
    classifier.fit(vector_train, y_train)
    predictions = classifier.predict(vector_test)
   
    
    return metrics.accuracy_score(predictions, y_test)

# Naive Bayes 
accuracy = model_training(naive_bayes.MultinomialNB(),xtrain_count, y_train,xtest_count  )
print ("NB, karakter tabanlı count-vectorizer:% ", accuracy*100)

# Logistic Regression
accuracy = model_training(linear_model.LogisticRegression(solver='newton-cg',multi_class='multinomial'), xtrain_count,  y_train, xtest_count)
print ("LR, karakter tabanlı count-vectorizer:%", accuracy*100)

# SVM 
accuracy =  model_training(svm.SVC(kernel='linear'), xtrain_count, y_train,  xtest_count)
print ("SVM,  karakter tabanlı count-vectorizer::%", accuracy*100)

# Random forest
accuracy =   model_training(ensemble.RandomForestClassifier(n_estimators=100), xtrain_count, y_train, xtest_count)
print ("RF,karakter tabanlı count-vectorizer:% ", accuracy*100)

# Extereme Gradient Boosting 
accuracy = model_training(xgboost.XGBClassifier(booster='gblinear'), xtrain_count.tocsc(), y_train, xtest_count.tocsc())
print ("Xgb, karakter tabanlı count-vectorizer:% ", accuracy*100)
