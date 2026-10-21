import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import sklearn
import csv

dataset = pd.read_csv('CompleteDataset1.csv')

#Data Cleaning
dataset["Value"] = dataset.Value.str.replace('[^\x00-\x7F]','')
dataset["Wage"] =  dataset.Wage.str.replace('[^\x00-\x7F]','')
dataset.loc[dataset.Value.str.contains('M') == True, "Value"] = pd.to_numeric(dataset.loc[dataset.Value.str.contains('M') == True, "Value"].str.replace('M',''), errors='ignore')*1000000
dataset.loc[dataset.Value.str.contains('K') == True, "Value"] = pd.to_numeric(dataset.loc[dataset.Value.str.contains('K') == True, "Value"].str.replace('K',''), errors='ignore')*1000
dataset.loc[dataset.Wage.str.contains('K') == True, "Wage"] = pd.to_numeric(dataset.loc[dataset.Wage.str.contains('K') == True, "Wage"].str.replace('K',''), errors='ignore')*1000

#Save Cleaned Data
dataset.to_csv('CompleteDataset_updated.csv')


X = dataset.iloc[:, [6]].values
y = pd.to_numeric(dataset.loc[:, 'Value'].values)

# Splitting the dataset into the Training set and Test set
from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.4, random_state = 0) #Test Kümesi 0.4 seçildi.

# Fitting Multiple SVM Regression to the Training set
from sklearn import svm
from sklearn.svm import SVR
regressor = SVR()
regressor.fit(X_train, y_train)

# Predicting the Test set results
#y_pred = regressor.predict(X_test)

# Fit regression model
svr_lin = SVR(kernel='linear')
svr_poly = SVR(kernel='poly', degree=2)
y_lin = svr_lin.fit(X, y).predict(X)
y_poly = svr_poly.fit(X, y).predict(X)

# Look at the results
lw = 2
plt.scatter(X, y, color='darkorange', label='data')
plt.plot(X, y_lin, color='c', lw=lw, label='Linear model')
plt.plot(X, y_poly, color='cornflowerblue', lw=lw, label='Polynomial model')
plt.xlabel('Overall')
plt.ylabel('Value')
plt.title('Overall vs Value (SVM)')
plt.legend()
plt.show()

print(regressor.predict(94))
