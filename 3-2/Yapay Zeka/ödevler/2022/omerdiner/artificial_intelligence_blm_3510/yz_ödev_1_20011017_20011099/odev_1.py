import numpy as np
import random
import cv2
import matplotlib.pyplot as plt
import time

# Rastgele bir şekil oluşturma fonksiyonu
def generate_random_shape(num_points, image_width, image_height):
    return [(random.randint(0, image_width - 1), random.randint(0, image_height - 1)) for _ in range(num_points)]

# Fitness fonksiyonu
def fitness_fn(individual, target_image):
    # Çizilecek çizgiyi belirlemek için
    drawn_image = np.zeros_like(target_image, dtype=np.uint8)
    for i in range(len(individual)):
        p1 = individual[i]
        p2 = individual[(i + 1) % len(individual)]
        cv2.line(drawn_image, p1, p2, 255, 1)

    # Hedef resimle olan benzerliği hesaplamak için
    fitness = np.sum(np.abs(drawn_image - target_image))
    return fitness

# Sıralama seçimi
def rank_selection(population, fitness_fn):
    ranked_population = sorted(population, key=lambda x: fitness_fn(x, target_image))
    return ranked_population

# Üreme
def reproduce(parent1, parent2):
    crossover_point = random.randint(1, len(parent1) - 1)
    child = parent1[:crossover_point] + parent2[crossover_point:]
    return child

# Mutasyon
def mutate(child, mutation_rate, image_width, image_height):
    for i in range(len(child)):
        if random.random() < mutation_rate:
            child[i] = (random.randint(0, image_width - 1), random.randint(0, image_height - 1))
    return child

# Genetik algoritma
def genetic_algorithm(population, target_image, fitness_fn, mutation_rate, num_generations):

    # Resmin boyutları
    image_height, image_width = target_image.shape

    for generation in range(num_generations):
        ranked_population = rank_selection(population, fitness_fn)
        new_population = []

        for _ in range(len(population)):
            x = random.choice(ranked_population)
            y = random.choice(ranked_population)
            child = reproduce(x, y)
            child = mutate(child, mutation_rate, image_width, image_height)
            new_population.append(child)

        population = new_population

        # En iyi bireyi bul
        best_individual = min(population, key=lambda individual: fitness_fn(individual, target_image))

        # Eğer yeterince iyi bir birey bulunduysa veya maksimum nesil sayısına ulaşıldıysa döngüyü sonlandırmak için
        if fitness_fn(best_individual, target_image) == 0 or generation == num_generations - 1:
            return best_individual

def draw_lines(population_size, mutation_rate, img):

    start_time = time.time()

    # Resmin boyutları
    image_height, image_width = img.shape

    # toplam jenerasyon sayısı
    num_generations = 100

    # Başlangıç populasyonunu oluşturmak için
    population = [generate_random_shape(random.randint(3, 18), image_width, image_height) for _ in range(population_size)]

    # Genetik algoritmayı çalıştırmak için
    best_individual = genetic_algorithm(population, img, fitness_fn, mutation_rate, num_generations)

    # Fitness değerini hesaplamak için
    best_fitness = fitness_fn(best_individual, img)

    # En iyi yolun takip edilerek bir resim çizmek için
    best_image = np.zeros_like(img, dtype=np.uint8)
    for i in range(len(best_individual)):
        p1 = best_individual[i]
        p2 = best_individual[(i + 1) % len(best_individual)]
        cv2.line(best_image, p1, p2, (255, 0, 0), 1)

    # Sonucu göstermek için
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.imshow(img, cmap='gray')
    plt.title('Original Image')
    plt.axis('off')

    plt.subplot(1, 2, 2)
    plt.imshow(cv2.bitwise_not(best_image), cmap='gray')
    plt.title('Best Solution')
    plt.axis('off')

    plt.show()

    end_time = time.time()
    print(f"Yukarıdaki İşlemin Gerçekleşme Süresi: {end_time-start_time:.2f} saniye\nPopülasyon Boyutu: {population_size}\nMutasyon Oranı: {mutation_rate}\nFitness Değeri: {best_fitness}\n") 

target_image = cv2.imread('star.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=2000, mutation_rate= 0.25, img= target_image)

target_image = cv2.imread('kalp.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=500, mutation_rate= 0.05, img= target_image)

target_image = cv2.imread('yıldırım.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=2000, mutation_rate= 0.07, img= target_image)

target_image = cv2.imread('beşgen.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=2000, mutation_rate= 0.25, img= target_image)

target_image = cv2.imread('altıgen.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=5000, mutation_rate= 0.02, img= target_image)

target_image = cv2.imread('mcdonalds.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=1000, mutation_rate= 0.1, img= target_image)

target_image = cv2.imread('pi.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=500, mutation_rate= 0.05, img= target_image)

target_image = cv2.imread('chrome.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=2000, mutation_rate= 0.07, img= target_image)

target_image = cv2.imread('c.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=500, mutation_rate= 0.02, img= target_image)

target_image = cv2.imread('apple.png', cv2.IMREAD_GRAYSCALE)
draw_lines(population_size=200, mutation_rate= 0.01, img= target_image)