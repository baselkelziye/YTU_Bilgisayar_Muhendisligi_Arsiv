import argparse
import os
import numpy as np
from pathlib import Path

def euclid_distance(x1, x2, y1, y2):
    return np.sqrt((x1 - x2)**2 + (y1 - y2)**2)

def task_1(num_samples=1000, size=25, save_path="tasks/task_1/data.npz"):
    matrices = []
    labels = []

    for _ in range(num_samples):
        matrix = np.zeros((size, size), dtype=np.uint8)

        # Rastgele 2 farklı nokta seç
        points = np.random.choice(size * size, 2, replace=False)
        coords = [(p // size, p % size) for p in points]

        for y, x in coords:
            matrix[y, x] = 1

        # Öklid mesafesini hesapla
        (y1, x1), (y2, x2) = coords
        distance = euclid_distance(x1, x2 ,y1, y2)

        matrices.append(matrix)
        labels.append(distance)

    matrices = np.array(matrices)  # (1000, 25, 25)
    labels = np.array(labels)      # (1000,)

    Path(os.path.dirname(save_path)).mkdir(parents=True, exist_ok=True)

    np.savez_compressed(save_path, X=matrices, y=labels)
    print(f"{num_samples} örnek '{save_path}' dosyasına kaydedildi.")

def task_2(num_samples=1000, size=25, save_path="tasks/task_2/data.npz"):
    matrices = []
    labels = []

    for _ in range(num_samples):
        matrix = np.zeros((size, size), dtype=np.uint8)

        # Nokta sayısı: 3 ile 10 arasında
        num_points = np.random.randint(3, 11)
        points = np.random.choice(size * size, num_points, replace=False)
        coords = [(p // size, p % size) for p in points]

        for y, x in coords:
            matrix[y, x] = 1

        # En yakın 2 nokta arasındaki mesafeyi bul
        min_dist = float('inf')
        for i in range(len(coords)):
            for j in range(i + 1, len(coords)):
                y1, x1 = coords[i]
                y2, x2 = coords[j]
                dist = euclid_distance(x1, x2 ,y1, y2)
                min_dist = min(min_dist, dist)

        matrices.append(matrix)
        labels.append(min_dist)

    matrices = np.array(matrices)  # (1000, 25, 25)
    labels = np.array(labels)      # (1000,)

    Path(os.path.dirname(save_path)).mkdir(parents=True, exist_ok=True)
    np.savez_compressed(save_path, X=matrices, y=labels)
    print(f"{num_samples} örnek '{save_path}' dosyasına kaydedildi.")


def task_3(num_samples=1000, size=25, save_path="tasks/task_3/data.npz"):
    matrices = []
    labels = []

    for _ in range(num_samples):
        matrix = np.zeros((size, size), dtype=np.uint8)

        # Nokta sayısı: 3 ile 10 arasında
        num_points = np.random.randint(3, 11)
        points = np.random.choice(size * size, num_points, replace=False)
        coords = [(p // size, p % size) for p in points]

        for y, x in coords:
            matrix[y, x] = 1

        # En uzak 2 nokta arasındaki mesafeyi bul
        max_dist = 0
        for i in range(len(coords)):
            for j in range(i + 1, len(coords)):
                y1, x1 = coords[i]
                y2, x2 = coords[j]
                dist = euclid_distance(x1, x2 ,y1, y2)
                max_dist = max(max_dist, dist)

        matrices.append(matrix)
        labels.append(max_dist)

    matrices = np.array(matrices)  # (1000, 25, 25)
    labels = np.array(labels)      # (1000,)

    Path(os.path.dirname(save_path)).mkdir(parents=True, exist_ok=True)
    np.savez_compressed(save_path, X=matrices, y=labels)
    print(f"{num_samples} örnek '{save_path}' dosyasına kaydedildi.")


def task_4(num_samples=1000, size=25, save_path="tasks/task_4/data.npz"):
    matrices = []
    labels = []

    for _ in range(num_samples):
        matrix = np.zeros((size, size), dtype=np.uint8)

        # Nokta sayısı: 1 ile 10 arasında
        num_points = np.random.randint(1, 11)
        points = np.random.choice(size * size, num_points, replace=False)
        coords = [(p // size, p % size) for p in points]

        for y, x in coords:
            matrix[y, x] = 1

        matrices.append(matrix)
        labels.append(num_points)

    matrices = np.array(matrices)  # (1000, 25, 25)
    labels = np.array(labels)      # (1000,)

    Path(os.path.dirname(save_path)).mkdir(parents=True, exist_ok=True)
    np.savez_compressed(save_path, X=matrices, y=labels)
    print(f"{num_samples} örnek '{save_path}' dosyasına kaydedildi.")


def task_5(num_samples=1000, size=25, save_path="tasks/task_5/data.npz"):
    matrices = []
    labels = []

    for _ in range(num_samples):
        matrix = np.zeros((size, size), dtype=np.uint8)

        # Kare sayısı: 1 ile 10 arasında
        num_squares = np.random.randint(1, 11)

        for _ in range(num_squares):
            square_size = np.random.randint(2, 7)  # 2x2 ile 6x6 arası
            max_start = size - square_size
            if max_start < 0:
                continue  # Çok büyükse atla
            top_left_y = np.random.randint(0, max_start + 1)
            top_left_x = np.random.randint(0, max_start + 1)

            # Kareyi matrise yerleştir
            matrix[top_left_y:top_left_y + square_size,
                   top_left_x:top_left_x + square_size] = 1

        matrices.append(matrix)
        labels.append(num_squares)

    matrices = np.array(matrices)  # (1000, 25, 25)
    labels = np.array(labels)      # (1000,)

    Path(os.path.dirname(save_path)).mkdir(parents=True, exist_ok=True)
    np.savez_compressed(save_path, X=matrices, y=labels)
    print(f"{num_samples} örnek '{save_path}' dosyasına kaydedildi.")


def main():
    parser = argparse.ArgumentParser(description="YSA Proje Görev Seçici")
    parser.add_argument('--task', type=int, choices=[1, 2, 3, 4, 5], required=True,
                        help='Çalıştırılacak görevi seçin: 1-5 arası')
    parser.add_argument('--num_samples', type=int, default=10000, help='Üretilecek örnek sayısı (varsayılan=1000)')
    parser.add_argument('--save_path', type=str, help='Kaydedilecek dosya yolu (sadece task 1 için geçerli)')

    args = parser.parse_args()

    task_funcs = {
        1: lambda: task_1(num_samples=args.num_samples,
                          save_path=args.save_path or "tasks/task_1/data.npz"),
        2: lambda: task_2(num_samples=args.num_samples,
                          save_path=args.save_path or "tasks/task_2/data.npz"),
        3: lambda: task_3(num_samples=args.num_samples,
                          save_path=args.save_path or "tasks/task_3/data.npz"),
        4: lambda: task_4(num_samples=args.num_samples,
                          save_path=args.save_path or "tasks/task_4/data.npz"),
        5: lambda: task_5(num_samples=args.num_samples,
                          save_path=args.save_path or "tasks/task_5/data.npz")
    }

    task_funcs[args.task]()

if __name__ == "__main__":
    main()
