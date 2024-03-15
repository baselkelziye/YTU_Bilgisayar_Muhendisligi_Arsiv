import numpy as np
import pandas as pd

def mean_vector(dataframe):
    mean_vector = []
    for column in dataframe:
        column_mean = 0
        for row in dataframe[column]:
            column_mean += row
        column_mean /= len(dataframe[column])
        print("Mean of column", column, "is", column_mean)
        mean_vector.append(column_mean)
        
    return mean_vector


# TODO: Implement covariance_matrix() function
# def covariance_matrix(dataframe):
#     covariance_matrix = []
#     for column in dataframe:
#         covariance_vector = []
#         print("Mean of column", column, "is", mean_vector(dataframe[column]))
#         for column2 in dataframe:
#             covariance = 0
#             for row in dataframe[column]:
#                 covariance += row
#             covariance /= len(dataframe[column])
#             covariance_vector.append(covariance)
#         covariance_matrix.append(covariance_vector)
#         
#     return covariance_matrix

def covariance_matrix(dataframe):
    return dataframe.cov()

def mahanalobis_distance(mean_vector, covariance_matrix, vector):
    return np.sqrt((vector - mean_vector).T.dot(np.linalg.inv(covariance_matrix)).dot(vector - mean_vector))

def euclidean_distance(vector1, vector2):
    return np.sqrt(np.sum((vector1 - vector2)**2))

def euclidean_distance_df(dataframe, vector):
    euclidean_distance_vector = []
    for column in dataframe:
        euclidean_distance_vector.append(euclidean_distance(dataframe[column], vector))
        
    return euclidean_distance_vector
