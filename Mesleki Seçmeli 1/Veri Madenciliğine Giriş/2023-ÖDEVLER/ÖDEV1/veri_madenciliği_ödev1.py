import numpy as np
from scipy.spatial import distance
from scipy.spatial.distance import mahalanobis
from numpy.linalg import inv

ranges = [(0, 1), (1, 10), (10, 100), (100, 1000), (1000, 10000)]

data_matrix = np.zeros((10, 5))
for i in range(5):
    low, high = ranges[i]
    data_matrix[:, i] = np.random.uniform(low, high, 10)


print("Data Matrix:")
for row in data_matrix:
    for element in row:
        print(element, end=" ")
    print()

for i in range(data_matrix.shape[1]):
    feature = data_matrix[:, i]
    mean = np.mean(feature)
    std_dev = np.std(feature)
    variance = np.var(feature)
    print(f"Öznitelik {i+1}: Ortalama = {mean}, Standart Sapma = {std_dev}, Varyans = {variance}")

cov_matrix = np.cov(data_matrix, rowvar=False)
print("Ko-varyans Matrisi:")
print(cov_matrix)

cov_matrix_inv = inv(np.cov(data_matrix.T))

pairs = [(0, 1), (1, 2), (2, 3)]

for pair in pairs:
    sample1, sample2 = data_matrix[pair[0]], data_matrix[pair[1]]
    
    # Euclidean Uzaklığı
    euclidean_dist = distance.euclidean(sample1, sample2)
    
    # Cosine Uzaklığı
    cosine_dist = distance.cosine(sample1, sample2)
    
    # Manhattan Uzaklığı
    manhattan_dist = distance.cityblock(sample1, sample2)
    
    # Mahalanobis Uzaklığı
    mahalanobis_dist = mahalanobis(sample1, sample2, cov_matrix_inv)
    
    print(f"Örnek Çifti {pair}:")
    print(f"  Euclidean Uzaklık: {euclidean_dist}")
    print(f"  Cosine Uzaklık: {cosine_dist}")
    print(f"  Manhattan Uzaklık: {manhattan_dist}")
    print(f"  Mahalanobis Uzaklık: {mahalanobis_dist}\n")
