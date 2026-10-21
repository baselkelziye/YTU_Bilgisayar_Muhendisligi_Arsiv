from Data_Preprocessing import *
from SVD_Algo import *
import pandas as pd
import time
from Data_Preparation import *
from SVD import *
from NBC import *
from KNN import *
"""
# Data Preprocessing
start_time = time.time()
z, total_u, total_p, pid2PID, train, test, table, raw_data = data()
print("PreProc time : %s seconds" % (time.time() - start_time))

# SVD Algorithm
start_time = time.time()
result1 = SVD(table, factors = 150)
print("SVD time : %s seconds" % (time.time() - start_time))

"""
# Data Preprocessing
start_time = time.time()
train_data, test_data = Data_Preparation()
print("PreProc time : %s seconds" % (time.time() - start_time))

# SVD Algorithm
start_time = time.time()
SVD_RS()
print("SVD time : %s seconds" % (time.time() - start_time))

# Naive Bayes Algorithm
start_time = time.time()
result2 = Naive_Bayes(train_data, test_data)
print("Naive Bayes time : %s seconds" % (time.time() - start_time))

# KNN Algorithm
start_time = time.time()
result3 = K_Nearest_Neighbors(train_data, test_data)
print("KNN time : %s seconds" % (time.time() - start_time))
