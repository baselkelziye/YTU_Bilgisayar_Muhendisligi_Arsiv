from matplotlib import pyplot as plt
import numpy as np
import pandas as pd
from itertools import combinations

################################# A Kısmı #################################

def create_sample(sample_id):
    # 25x25 sıfırlardan oluşan matris
    matrix = np.zeros((25, 25), dtype=int)

    # 2 farklı rastgele nokta seç
    coords = np.random.choice(625, size=2, replace=False)
    p1 = divmod(coords[0], 25)
    p2 = divmod(coords[1], 25)

    # Noktaları matrise işaretle
    matrix[p1] = 1
    matrix[p2] = 1

    # Flatten edilmiş dizi
    flat = matrix.flatten()

    # Öklid mesafesi
    distance = np.linalg.norm(np.array(p1) - np.array(p2))

    row = {
        "id": sample_id,
        **{f"px_{i}": flat[i] for i in range(625)},
        "distance": distance
    }
    return row

# Örnekleri oluştur
samples = [create_sample(i) for i in range(1000)]

# DataFrame oluştur
df = pd.DataFrame(samples)

# DataFrame'i csv olarak kaydet
df.to_csv("dataset_A.csv", index=False)
print("--> dataset_A.csv oluşturuldu!")

################################# B ve C Kısmı #################################

def create_sample(sample_id):
    # 25x25 sıfırlardan oluşan matris
    matrix = np.zeros((25, 25), dtype=int)

    # 3 ila 10 arasında rastgele bir sayı belirle
    num_points = np.random.randint(3, 11)

    # Rastgele benzersiz konumlar seç
    coords = np.random.choice(625, size=num_points, replace=False)
    points = [divmod(c, 25) for c in coords]

    # Noktaları matrise yerleştir
    for p in points:
        matrix[p] = 1

     # Tüm çiftler için mesafeleri hesapla
    distances = [
        np.linalg.norm(np.array(p1) - np.array(p2))
        for p1, p2 in combinations(points, 2)
    ]

    distance_min = min(distances)
    distance_max = max(distances)

    # Flatten edilmiş matris
    flat = matrix.flatten()

    row = {
        "id": sample_id,
        **{f"px_{i}": flat[i] for i in range(625)},
        "distance_min": distance_min,
        "distance_max": distance_max
    }
    return row

# 1000 örnek oluştur
samples = [create_sample(i) for i in range(1000)]

# DataFrame oluştur
df = pd.DataFrame(samples)

# DataFrame'i csv olarak kaydet
df.to_csv("dataset_BC.csv", index=False)
print("--> dataset_BC.csv oluşturuldu!")

################################# D Kısmı #################################

def create_sample(sample_id):
    # 25x25 sıfırlardan oluşan matris
    matrix = np.zeros((25, 25), dtype=int)

    # 3 ila 10 arasında rastgele bir sayı belirle
    num_points = np.random.randint(1, 11)

    # Rastgele benzersiz konumlar seç
    coords = np.random.choice(625, size=num_points, replace=False)
    points = [divmod(c, 25) for c in coords]

    # Noktaları matrise yerleştir
    for p in points:
        matrix[p] = 1

    # Flatten edilmiş matris
    flat = matrix.flatten()

    row = {
        "id": sample_id,
        **{f"px_{i}": flat[i] for i in range(625)},
        "num_points": num_points,
    }
    return row

# 1000 örnek oluştur
samples = [create_sample(i) for i in range(1000)]

# DataFrame oluştur
df = pd.DataFrame(samples)

# DataFrame'i csv olarak kaydet
df.to_csv("dataset_D.csv", index=False)
print("--> dataset_D.csv oluşturuldu!")

################################# E Kısmı #################################

def create_sample(sample_id):
    # Boş 25x25 matris
    matrix = np.zeros((25, 25), dtype=int)

    # Kare sayısını rastgele seç (1 ile 10 arası)
    num_squares = np.random.randint(1, 11)
    placed_squares = 0
    
    while placed_squares < num_squares:
        # Kare kenar uzunluğu (örneğin 2 ile 6 arasında)
        size = np.random.randint(2, 11)

        # Kareyi matrise yerleştirmek için x, y koordinatlarının sınırlandırılması
        x = np.random.randint(0, 25 - size + 1)
        y = np.random.randint(0, 25 - size + 1)

        if np.all(matrix[y:y+size, x:x+size] == 0):
            matrix[y:y+size, x:x+size] = 1
            placed_squares += 1
    #         if sample_id % 100 == 0:
    #             print(x, y)
    
    # if sample_id % 100 == 0:
    #     print(placed_squares, "\n\n")
    #     fig, ax = plt.subplots()
    #     ax.imshow(matrix, cmap="gray_r", origin="upper")
    #     plt.show()
        
    
    # Flatten edilmiş dizi
    flat = matrix.flatten()

    row = {
        "id": sample_id,
        **{f"px_{i}": flat[i] for i in range(625)},
        "num_squares": placed_squares
    }
    return row

# 1000 örnek üret
samples = [create_sample(i) for i in range(1000)]

# DataFrame oluştur
df = pd.DataFrame(samples)

# DataFrame'i csv olarak kaydet
df.to_csv("dataset_E.csv", index=False)
print("--> dataset_E.csv oluşturuldu!")

print("Tüm datasetler oluşturuldu!")