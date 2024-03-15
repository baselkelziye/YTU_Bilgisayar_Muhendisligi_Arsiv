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

    def test_determinant_of_a_matrix(self):
        print("Test determinant_of_a_matrix() function starting...")

        a = [[3, 5], [4, 6]]
        det_a = np.linalg.det(a)

        self.assertEqual(-2.0, det_a)

        b = [[3, 4], [5, 6]]
        det_b = np.linalg.det(b)

        self.assertAlmostEqual(-2.0, det_b, places=6)
        
        print("Test determinant_of_a_matrix() function finished successfully!")

    def test_multivariate_gaussian(self):
        print("Test multivariate_gaussian() function starting...")
        mean_mu_list_1 = [2, 1]
        mean_mu_list_2 = [2, -1]

        rng = np.random.default_rng()
        # covariance_matrix_list_1_2 = [[2, -1], [-1, 1]]
        covariance_matrix_list_1_2 = [[2, -1], [-1, 1]]

        n_samples = 5000

        data_gaussian_dist = rng.multivariate_normal(mean_mu_list_1, covariance_matrix_list_1_2, size=n_samples, check_valid='raise', tol=1e-8)
        # This values must be so close to each other
        print("Expected mean: ", mean_mu_list_1)
        print("Generated data mean: ", data_gaussian_dist.mean(axis=0))

        # This values must be so close to each other
        print("Expected covariance matrix: ", covariance_matrix_list_1_2)
        print("Generated data covariance matrix: ", np.cov(data_gaussian_dist.T))

        
        print("Test multivariate_gaussian() function finished successfully!")

if __name__ == '__main__':
    unittest.main()
    # Run only specific test method
    # unittest.main(argv=[''],
    #               defaultTest='TestUtils.test_determinant_of_a_matrix')
