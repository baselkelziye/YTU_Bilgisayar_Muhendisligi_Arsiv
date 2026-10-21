import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt
import csv
from sklearn.model_selection import train_test_split

def Data_Preparation():
    # Read the CSV file 
    dataset = "kaggle/Reviews.csv"
    df = pd.read_csv(dataset)

    # Dropping the columns
    df = df.drop(['Id', 'ProfileName','Time','HelpfulnessNumerator','HelpfulnessDenominator','Text','Summary'], axis = 1)

    # Extracting the subset of dataset. Taking the users who has given 50 or more number of ratings
    counts = df['UserId'].value_counts()
    df_final = df[df['UserId'].isin(counts[counts >= 50].index)]
    print(df_final.head(10))

    #Split the training and test data in the ratio 70:30
    train_data, test_data = train_test_split(df_final, test_size = 0.3, random_state=0)






    return train_data, test_data