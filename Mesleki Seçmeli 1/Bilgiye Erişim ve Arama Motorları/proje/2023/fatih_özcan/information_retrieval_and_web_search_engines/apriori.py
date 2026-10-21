import pandas as pd
import numpy as np

import datetime 
import time

import matplotlib.pyplot as plt 
import seaborn as sns

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn import metrics
from mlxtend.frequent_patterns import apriori
from mlxtend.frequent_patterns import association_rules
food_rating_df = pd.read_csv('kaggle/Reviews.csv')

# Drop unnecessary columns, remove duplicates, and handle missing values
food_rating_df = food_rating_df.drop(['Id', 'ProfileName', 'Time', 'HelpfulnessNumerator', 'HelpfulnessDenominator', 'Text', 'Summary'], axis=1)
food_rating_df = food_rating_df.drop_duplicates(['UserId', 'ProductId'])
food_rating_df = food_rating_df.dropna(subset=['UserId', 'ProductId', 'Score'])
food_rating_df = food_rating_df.reset_index(drop=True)

# Check for negative values in the 'Score' column
negative_scores = food_rating_df[food_rating_df['Score'] < 0]
#print("Negative Scores:", negative_scores)

# Print summary statistics of the 'Score' column
#print(food_rating_df['Score'].describe())

# Split the data into training and testing sets
train_data, test_data = train_test_split(food_rating_df.sample(frac=0.1), test_size=0.3, random_state=0)


# Create the pivot table
main_df = train_data.pivot_table(index='UserId', columns='ProductId', values='Score', fill_value=0)
#main_df = food_rating_df.pivot_table(index='UserId',columns='ProductId',values='Score')
#main_df.fillna(0,inplace=True)
print(main_df)

food_list = []
for i in range(0,3286):
    food_list.append([str(main_df.columns[j]) for j in range(0,7736) if main_df.values[i,j] != 0 ])

rules = apriori(food_list,min_support=0.05)
results = list(rules)

def data_extractor(data):
    m1 = np.array([tuple(i[2][0][0] for i in data)]).T
    m1 = pd.DataFrame(m1,columns=['Movie_Watched'])
    m2 = np.array([tuple(i[2][0][1] for i in data)]).T
    m2 = pd.DataFrame(m2,columns=['Also_Watched'])
    support = pd.DataFrame([i[1] for i in data],columns=['Support'])
    confidence = pd.DataFrame([i[2][0][2] for i in data],columns=['Confidence'])
    lift = pd.DataFrame([i[2][0][3] for i in data],columns=['Lift'])
    result = pd.concat([m1,m2,support,confidence,lift],axis=1)
    return result
result_df = data_extractor(results)

result_df.sort_values(by='Lift',ascending=False)