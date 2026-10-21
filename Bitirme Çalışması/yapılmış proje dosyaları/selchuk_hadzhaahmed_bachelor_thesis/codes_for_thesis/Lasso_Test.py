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

# Fitting Multiple Linear Regression to the Training set
from sklearn import linear_model
regressor = linear_model.Lasso(alpha = 0.1)
regressor.fit(X_train, y_train)

# Predicting the Test set results
y_pred = regressor.predict(X_test)


# Visualising the Test set results
plt.scatter(X_test, y_test, color = 'red')
plt.plot(X_train, regressor.predict(X_train), color = 'blue')
plt.title('Overall vs Value (LassoLars Regression)')
plt.xlabel('Overall')
plt.ylabel('Value')
plt.show()

# Predicting a new result with Lasso Regression
print(regressor.predict(94))
