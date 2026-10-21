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
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.4, random_state = 0)

# Fitting Multiple Linear Regression to the Training set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X_train, y_train)

# Predicting the Test set results
y_pred = regressor.predict(X_test)

# Visualising the Test set results
plt.scatter(X_test, y_test, color = 'red')
plt.plot(X_train, regressor.predict(X_train), color = 'blue')
plt.title('Overall vs Value (Linear Regression)')
plt.xlabel('Overall')
plt.ylabel('Value')
plt.show()

# Predicting a new result with Linear Regression
print(regressor.predict(94))

from sklearn.model_selection import cross_val_score
scores = cross_val_score(regressor, X_test, y_test, scoring='r2', cv=5)
print("Accuracy: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))

# Fitting Polynomial Regression to the dataset
from sklearn.preprocessing import PolynomialFeatures
poly_reg = PolynomialFeatures(degree = 4)
X_poly = poly_reg.fit_transform(X)
poly_reg.fit(X_poly, y)
lin_reg_2 = LinearRegression()
lin_reg_2.fit(X_poly, y)

# Visualising the Polynomial Regression results (for higher resolution and smoother curve)
X_grid = np.arange(min(X), max(X), 0.1)
X_grid = X_grid.reshape((len(X_grid), 1))
plt.scatter(X, y, color = 'red')
plt.plot(X_grid, lin_reg_2.predict(poly_reg.fit_transform(X_grid)), color = 'blue')
plt.title('Truth or Bluff (Polynomial Regression)')
plt.xlabel('Overall')
plt.ylabel('Value')
plt.show()

# Predicting a new result with Polynomial Regression
print(lin_reg_2.predict(poly_reg.fit_transform(94)))

from sklearn.pipeline import Pipeline
pipeline = Pipeline([("polynomial_features", poly_reg),("linear_regression", lin_reg_2)])
pipeline.fit(X_poly, y)

scores = cross_val_score(pipeline, X_test, y_test, scoring='r2', cv=5)
print("Accuracy: %0.2f (+/- %0.2f)" % (scores.mean(), scores.std() * 2))
