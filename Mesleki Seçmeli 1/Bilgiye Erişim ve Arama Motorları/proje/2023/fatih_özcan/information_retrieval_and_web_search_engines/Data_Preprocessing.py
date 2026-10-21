import pandas as pd
import numpy as np
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt


def data_clean(df, feature, m):
    count = df[feature].value_counts().iloc[:]
    df = df[df[feature].isin(count[count > m].index.values)]
    return df

def data_clean_sum(df, features, m):
    fil = df['ProductId'].value_counts()
    fil2 = df['UserId'].value_counts()
    df['#Products'] = df['ProductId'].apply(lambda x: fil[x])
    df['#Users'] = df['UserId'].apply(lambda x: fil2[x])
    
    while (df['ProductId'].value_counts(ascending=True).iloc[0]) < m or (df['UserId'].value_counts(ascending=True).iloc[0] < m):
        df = data_clean(df, features[0], m)
        df = data_clean(df, features[1], m)
    return df


def data():
    # Read the CSV file 
    dataset = "kaggle/Reviews.csv"
    df = pd.read_csv(dataset)

    df['datetime'] = pd.to_datetime(df.Time, unit='s')
    raw_data = data_clean_sum(df, ['ProductId', 'UserId'], 10)

    # find X,and y
    raw_data['uid'] = pd.factorize(raw_data['UserId'])[0]
    raw_data['pid'] = pd.factorize(raw_data['ProductId'])[0]
    sc = MinMaxScaler()
    
    # Sepreate the features into three groups
    X1 = raw_data.loc[:,['uid','pid']]
    y = raw_data.Score
    
    # train_test split
    X1_train,X1_test,y_train,y_test = train_test_split(X1,y,test_size=0.3,random_state=2017)
    train = np.array(X1_train.join(y_train))
    test = np.array(X1_test.join(y_test))
    
    # got the productId to pid index
    pid2PID = raw_data.ProductId.unique()

    data_mixed = X1.join(y)
    total_p = data_mixed['pid'].unique().shape[0]
    total_u = data_mixed['uid'].unique().shape[0]
    # make the user-item table
    table = np.zeros([total_u,total_p])
    z = np.array(data_mixed)
    
    #if some one score a single thing several times
    for line in z:
        u,p,s = line
        if table[u][p] < s:
            table[u][p] = s 
    print('the table\'s shape is:' )
    print(table.shape)
    
    return z, total_u,total_p,pid2PID,train,test,table,raw_data



