#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 24 14:21:34 2018

@author: egehangunduz
"""

import numpy as np
import pandas as pd
import itertools
import matplotlib.pyplot as plt
import pickle


from sklearn import metrics
from sklearn import preprocessing
from sklearn.model_selection import cross_val_predict

from sklearn.svm import SVC
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.linear_model import LogisticRegression
from sklearn.neighbors import KNeighborsClassifier
from sklearn.neural_network import MLPClassifier



#read file from dcurrent irectory
def read_csv():
    return pd.read_csv("UCI_Credit_Card.csv")

#remove first column which indicated the user id
#get 23 feature as X
#get result column as Y
def split_dataset(data):
    return data.iloc[:,1:24], data.iloc[:,24]

#create model as a list
def create_models():
    models = []
    models.append(('Logistic Regression', LogisticRegression(solver="lbfgs")))
    models.append(('SVM', SVC(gamma="auto")))
    models.append(('MLP', MLPClassifier(activation="logistic",alpha=1e-4,solver="lbfgs",hidden_layer_sizes=(100,))))
    models.append(('K-NN', KNeighborsClassifier()))
    models.append(('LDA', LinearDiscriminantAnalysis()))
    return models

#get average and standard deviation of payment times
def add_pay_statistics(X):
    X["avg_pay"] = X.iloc[:,5:11].mean(axis=1)
    X["std_pay"] = X.iloc[:,5:11].std(axis=1)
    return X

#get average and standard deviation of bills
def add_bill_statistics(X):
    X["avg_bill"] = X.iloc[:,12:18].mean(axis=1)
    X["std_bill"] = X.iloc[:,12:18].std(axis=1)
    return X

#get average and standard deviation of payments
def add_payment_statistics(X):
    X["avg_payment"] = X.iloc[:,18:24].mean(axis=1)
    X["std_payment"] = X.iloc[:,18:24].std(axis=1)
    return X

#plot confusion matrix
#it takes the confusion matrix and plot it regarding to parameters
def plot_confusion_matrix(cm, classes,
                          name,
                          normalize=False,
                          title='Confusion matrix',
                          cmap=plt.cm.Blues):
    """
    This function prints and plots the confusion matrix.
    Normalization can be applied by setting `normalize=True`.
    """
    if normalize:
        cm = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
        #print("Normalized confusion matrix")
    else:
        print()

    plt.imshow(cm, interpolation='nearest', cmap=cmap, aspect='auto')
    plt.title(title)
    plt.colorbar()
    tick_marks = np.arange(len(classes))
    plt.xticks(tick_marks, classes, rotation=45)
    plt.yticks(tick_marks, classes)

    fmt = '.2f' if normalize else 'd'
    thresh = cm.max() / 2.
    for i, j in itertools.product(range(cm.shape[0]), range(cm.shape[1])):
        plt.text(j, i, format(cm[i, j], fmt) , fontsize = 20,
                 horizontalalignment="center",
                 color="white" if cm[i, j] > thresh else "black")

    plt.tight_layout()
    plt.ylabel('True label')
    plt.xlabel('Predicted label')
    plt.savefig(name,bbox_inches="tight",pad_inches=0.5)
    plt.clf()

#return trained model
def train_model(model,X,Y):
    model.fit(X,Y)
    return model


data = read_csv()
X, Y = split_dataset(data)
X = add_pay_statistics(X)
X = add_bill_statistics(X)
X = add_payment_statistics(X)

#in order to use standard scaler, values have to be converted to float type
X = X.astype('float64')
scaler = preprocessing.StandardScaler()
X = pd.DataFrame(scaler.fit_transform(X),columns = X.columns)


models = create_models()

class_names=["Not Paid","Paid"]
for name, model in models:
    print("Working for", name)
    model2 = train_model(model,X,Y)

    #model name, cm image name and metrics txt file name defined below respectively
    model_filename = name + ".sav"
    confusion_matrix_filename = name+"_cm.png"
    cm_values_name = name +"_value_cm.txt"

    #this list used for metrics
    cm_values = []

    #write trained model to file
    pickle.dump(model2, open(model_filename, 'wb'))

    #use cross validation
    tahminler = cross_val_predict(model,X,Y,cv=10)

    #get metrics with position label 0(not paid)
    confusion_matrix = metrics.confusion_matrix(Y,tahminler)
    accuracy=metrics.accuracy_score(Y,tahminler)
    precision=metrics.precision_score(Y,tahminler,pos_label=0)
    recall=metrics.recall_score(Y,tahminler,pos_label=0)
    fskor=metrics.f1_score(Y,tahminler,pos_label=0)
    cm_values.extend([accuracy,precision,recall,fskor])

    #write metrics to file and image(with plot_confusion_matrix function)
    pickle.dump(cm_values,open(cm_values_name, "wb"))
    plot_confusion_matrix(confusion_matrix,class_names,confusion_matrix_filename,normalize=True)

    print(name)
    print("Accuracy:" + str(accuracy))
    print("Precision:" + str(precision))
    print("Recall:" + str(recall))
    print("fskor:" + str(fskor))
    print ("-------------------------------------------------\n-------------------------------------------------")





