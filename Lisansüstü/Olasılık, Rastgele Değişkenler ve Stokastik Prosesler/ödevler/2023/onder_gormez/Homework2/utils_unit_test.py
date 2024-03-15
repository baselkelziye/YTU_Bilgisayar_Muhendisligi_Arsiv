#!/usr/bin/python3

import unittest
import pandas as pd
import numpy as np

from scipy.spatial import distance
import pandas as pd
from scipy.spatial.distance import pdist, squareform

import utils

class TestUtils(unittest.TestCase):

    @classmethod
    def setUpClass(cls):
        print("setUpClass method called!")

    @classmethod
    def tearDownClass(cls):
        print("tearDownClass method called!")

    def setUp(self):
        print('setUp method called!')

    def tearDown(cls):
        print("tearDown method called!")

    def test_mean_vector(self):
        print("Test mean_vector() function starting...")

        # Input : mat[][] = {{1,  2,  3,  4},
        #                    {5,  6,  7,  8},
        #                    {9, 10, 11, 12}}
        # Output : Mean Vector is [5 6 7 8]
        # Mean of column 1 is (1 + 5 + 9) / 3 = 5
        # Mean of column 2 is (2 + 6 + 10) / 3 = 6
        # Mean of column 3 is (3 + 7 + 11) / 3 = 7
        # Mean of column 4 is (4 + 8 + 12) / 3 = 8

        data = [[1, 2, 3, 4], [5, 6, 7, 8], [9,10,11,12]]
        data_frame=pd.DataFrame(data, columns=['sepal.length', 'sepal.width', 'petal.length', 'petal.width'])

        
        self.assertEqual(utils.mean_vector(data_frame), [5.0, 6.0, 7.0, 8.0])

        
        print("Test mean_vector() function finished successfully!")

    def test_covariance_matrix(self):
        print("Test covariance_matrix() function starting...")

        # Input : mat[][] = {{1,  2,  3,  4},
        #                    {5,  6,  7,  8},
        #                    {9, 10, 11, 12}}
        # Output : Covariance Matrix is [[5 6 7 8]
        #                                [5 6 7 8]
        #                                [5 6 7 8]
        #                                [5 6 7 8]]
        # Covariance of column 1 and 1 is (1 + 5 + 9) / 3 = 5
        # Covariance of column 1 and 2 is (1 + 5 + 9) / 3 = 5
        # Covariance of column 1 and 3 is (1 + 5 + 9) / 3 = 5
        # Covariance of column 1 and 4 is (1 + 5 + 9) / 3 = 5
        # Covariance of column 2 and 1 is (2 + 6 + 10) / 3 = 6
        # Covariance of column 2 and 2 is (2 + 6 + 10) / 3 = 6
        # Covariance of column 2 and 3 is (2 + 6 + 10) / 3 = 6
        # Covariance of column 2 and 4 is (2 + 6 + 10) / 3 = 6
        # Covariance of column 3 and 1 is (3 + 7 + 11) / 3 = 7
        # Covariance of column 3 and 2 is (3 + 7 + 11) / 3 = 7
        # Covariance of column 3 and 3 is (3 + 7 + 11) / 3 = 7
        # Covariance of column 3 and 4 is (3 + 7 + 11) / 3 = 7
        # Covariance of column 4 and 1 is (4 + 8 + 12) / 3 = 8
        # Covariance of column 4 and 2 is (4 +  8 + 12) / 3 = 8

        data = {
            'A': [1,   2,  3],
            'B': [4,   5,  6],
            'C': [14, 16, 18],
        }

        data_frame = pd.DataFrame(data)

        cov_matrix = pd.DataFrame.cov(data_frame)
        print(cov_matrix)

        # Mean of colum A is (1 + 2 + 3) / 3 = 2
        # Mean of colum B is (4 + 5 + 6) / 3 = 5
        # Mean of colum C is (14 + 16 + 18) / 3 = 16
        # print(utils.mean_vector(data_frame))

        print(utils.covariance_matrix(data_frame))

        # Covariance of column A and C is: (x - mean(x)) * (y - mean(y)) / (n - 1)
        # n: number of rows
        #   (1 - 2) * (14 - 16) / (3 - 1) + (2 - 2) * (16 - 16) / (3 - 1) + (3 - 2) * (18 - 16) / (3 - 1) = 2

        # data = [[1, 2, 3, 4], [5, 6, 7, 8], [9,10,11,12]]

        print("Test covariance_matrix() function finished successfully!")

    def test_mahanalobis_distance(self):
        print("Test mahanalobis_distance() function starting...")

        # Input : mat[][] = {{1,  2,  3,  4},
        #                    {5,  6,  7,  8},
        #                    {9, 10, 11, 12}}
        # Output : Mahanalobis Distance is [5 6 7 8]
        # Mean of column 1 is (1 + 5 + 9) / 3 = 5
        # Mean of column 2 is (2 + 6 + 10) / 3 = 6
        # Mean of column 3 is (3 + 7 + 11) / 3 = 7
        # Mean of column 4 is (4 + 8 + 12) / 3 = 8

        data = {
            'A': [1,   2,  3],
            'B': [4,   5,  6],
            'C': [14, 16, 18],
        }

        data_frame = pd.DataFrame(data)

        #     A    B    C
        # A  1.0  1.0  2.0
        # B  1.0  1.0  2.0
        # C  2.0  2.0  4.0
        cov_matrix = pd.DataFrame.cov(data_frame)
        print(cov_matrix)

        # data = [[1, 2, 3, 4], [5, 6, 7, 8], [9,10,11,12]]
        # data_frame=pd.DataFrame(data, columns=['sepal.length', 'sepal.width', 'petal.length', 'petal.width'])

        # [2.0, 5.0, 16.0]
        mean_vector = utils.mean_vector(data_frame)
        print(mean_vector)
        
        # covariance_matrix = utils.covariance_matrix(data_frame)

        # print(mean_vector)
        # print(covariance_matrix)

        # vector = np.array([1, 2, 3, 4])

        # print(utils.mahanalobis_distance(mean_vector, covariance_matrix, vector))

        # self.assertEqual(utils.mahanalobis_distance(mean_vector, cov_matrix, data), 0.0)

        # Sample data
        data = np.array([[1,   2,  3], [4, 5, 6], [14, 16, 18]])

        # Mean and covariance matrix
        mean_vector = np.mean(data, axis=0)
        cov_matrix = np.cov(data, rowvar=False)

        # Point to calculate Mahalanobis distance for
        point = np.array([2, 4, 6])

        # Calculate Mahalanobis distance
        mahalanobis_distance = distance.mahalanobis(point, mean_vector, np.linalg.inv(cov_matrix))

        print("Mahalanobis Distance:", mahalanobis_distance)

        print("Test mahanalobis_distance() function finished successfully!")

    def test_euclidean_distance(self):
        print("Test euclidean_distance() function starting...")

        # Create a sample DataFrame
        data = {'X': [1, 2, 3, 4],
                'Y': [5, 6, 7, 8],
                'Z': [9, 10, 11, 12]}
        df = pd.DataFrame(data)

        # Calculate Euclidean distance
        distances = pdist(df.values, metric='euclidean')

        # Convert the condensed distance matrix to a square matrix
        distance_matrix = squareform(distances)

        # Create a DataFrame from the distance matrix
        distance_df = pd.DataFrame(distance_matrix, index=df.index, columns=df.index)

        # Display the resulting distance DataFrame
        print(distance_df)

        mean_vector = utils.mean_vector(df)
        my_euclidean_distance = utils.euclidean_distance(df, mean_vector)
        print(my_euclidean_distance)

        # self.assertEqual(utils.mahanalobis_distance(mean_vector, cov_matrix,

if __name__ == '__main__':
    # unittest.main()
    # Run only specific test method
    unittest.main(argv=[''],
                  defaultTest='TestUtils.test_euclidean_distance')
