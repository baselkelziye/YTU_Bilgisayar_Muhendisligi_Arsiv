import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt
import csv
from sklearn.model_selection import train_test_split

# Read the CSV file 
dataset = "kaggle/Reviews.csv"
df = pd.read_csv(dataset)

# print the first 10 rows
#print(df.head(10))

# Dropping the columns
df = df.drop(['Id', 'ProfileName','Time','HelpfulnessNumerator','HelpfulnessDenominator','Text','Summary'], axis = 1) 
"""
# print the first 10 rows
print(df.head(10))

# Check the number of rows and columns
rows, columns = df.shape
print("No of rows: ", rows) 
print("No of columns: ", columns) 

# check for any null values
print(df.isnull().sum()) 

# check for any repeated values
print(df[df.duplicated()].any()) 

# Score distributions
print(df.describe()['Score'])

#rating scale
print("Puanlar:",df.Score.unique())

# Ürünlerin aldıkları ortalama puanlar
ratings = pd.DataFrame(df.groupby('ProductId')['Score'].mean())
ratings['puanlanma sayisi'] = pd.DataFrame(df.groupby('ProductId')['Score'].count())
ratings['ortalama'] = pd.DataFrame(df.groupby('ProductId')['Score'].mean())
print(ratings.head(10))

plt.figure(figsize=(10,4))
ratings['Score'].hist(bins=70)
#plt.show()

# Check the distribution of ratings 
with sns.axes_style('white'):
    g = sns.catplot(x="Score", data=df, aspect=2.0, kind='count')
    g.set_ylabels("Total number of ratings")
    #plt.show()

ratings_per_user = df.groupby('UserId')['Score'].count()
ratings_per_product = df.groupby('ProductId')['Score'].count()

# Number of unique user id and product id in the data
print('Number of unique USERS in Raw data = ', df['UserId'].nunique())
print('Number of unique ITEMS in Raw data = ', df['ProductId'].nunique())

# Top 10 users based on rating
most_rated = df.groupby('UserId').size().sort_values(ascending=False)[:10]
print(most_rated)
"""
# Extracting the subset of dataset. Taking the users who has given 50 or more number of ratings
counts = df['UserId'].value_counts()
df_final = df[df['UserId'].isin(counts[counts >= 50].index)]
print(df_final.head(10))

print('Number of users who have rated 50 or more items =', len(df_final))
print('Number of unique USERS in final data = ', df_final['UserId'].nunique())
print('Number of unique ITEMS in final data = ', df_final['ProductId'].nunique())


final_ratings_matrix = pd.pivot_table(df_final,index=['UserId'], columns = 'ProductId', values = "Score")
final_ratings_matrix.fillna(0,inplace=True)
print('Shape of final_ratings_matrix: ', final_ratings_matrix.shape)
given_num_of_ratings = np.count_nonzero(final_ratings_matrix)
print('given_num_of_ratings = ', given_num_of_ratings)
possible_num_of_ratings = final_ratings_matrix.shape[0] * final_ratings_matrix.shape[1]
print('possible_num_of_ratings = ', possible_num_of_ratings)
density = (given_num_of_ratings/possible_num_of_ratings)
density *= 100
print ('density: {:4.2f}%'.format(density))

#print(final_ratings_matrix.tail(10))

# Matrix with one row per 'Product' and one column per 'user' for Item-based CF
final_ratings_matrix_T = final_ratings_matrix.transpose()
print(final_ratings_matrix_T.head())

#Split the training and test data in the ratio 70:30
train_data, test_data = train_test_split(df_final, test_size = 0.3, random_state=0)

print(train_data.head(5))

print("Test data shape: ", test_data.shape)
print("Train data shape: ", train_data.shape)


"""
#remove products that do not receive high ratings
ratings_per_product_df =pd.DataFrame(ratings_per_product)
filtered_ratings_per_products_df = ratings_per_product_df[ratings_per_product_df.Score>=200]
popular_product = filtered_ratings_per_products_df.index.tolist()
print(filtered_ratings_per_products_df)

#çok fazla yorum yapmamış kullanıcıları çıkartıyoruz 
ratings_per_user_df = pd.DataFrame(ratings_per_user)
filtered_ratings_per_user_df = ratings_per_user_df[ratings_per_user_df.Score>= 70]
pro_users = filtered_ratings_per_user_df.index.tolist()
print(filtered_ratings_per_user_df)
"""
#filterlıyoruz
#filtered_ratings = df[df.ProductId.isin(popular_product)]
#filtered_ratings = df[df.userId.isin(pro_users)]

#len(filtered_ratings)