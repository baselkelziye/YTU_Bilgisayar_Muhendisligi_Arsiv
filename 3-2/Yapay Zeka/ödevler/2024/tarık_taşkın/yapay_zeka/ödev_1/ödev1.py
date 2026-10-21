import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import matplotlib.patches as patches
from matplotlib.colors import ListedColormap
import random
from PIL import Image
from matplotlib.widgets import Button

# PARAMETRELER
GENERATIONS = 60            # Toplam nesil sayısı
POPULATION_SIZE = 30        # Popülasyon büyüklüğü
MUTATION_RATE = 0.20        # Mutasyon olasılığı
CROSSOVER_RATE = 0.45       # Çaprazlama olasılığı
NUM_PATTERNS = 7            # Her bireydeki 3x3 patern sayısı

# GLOBAL DEĞİŞKENLER
global current_generation, generation_history, ims, axes
current_generation = 0      # Mevcut nesil takibi
generation_history = []     # Tüm nesillerin patern geçmişi

# Görüntüyü yükleyip numpy array'e çevirir
def load_image(fileName): 
    image = mpimg.imread(fileName)
    return np.array(image, dtype="int8")

# Rastgele 3x3 siyah-beyaz patern oluşturur (0: beyaz, 1: siyah)
def random_pattern():
    return np.random.randint(low=0, high=2, size=(3, 3))

# Rastgele paternlerden oluşan başlangıç popülasyonu oluşturur
def initialize_population(population_size):
    return [np.array([random_pattern() for _ in range(NUM_PATTERNS)]) for _ in range(population_size)]

# Turnuva seçimi ile en iyi bireyleri seçer
def selection(population, fitness_values, tournament_size=3):
    selected = []
    for _ in range(POPULATION_SIZE):
        # Rastgele tournament_size kadar birey seç
        tournament = random.sample(list(zip(population, fitness_values)), tournament_size)
        # En düşük fitness değerine sahip bireyi kazanan yap
        winner = min(tournament, key=lambda x: x[1])[0]
        selected.append(winner)
    return selected

# Her bireyin uygunluk değerini hesaplar (Ne kadar az hata o kadar iyi)
def fitness_function(images, population):
    fitness_values = [0] * len(population)
    
    for image in images:
        # Görüntüyü 3x3 bloklara böl       
        for i in range(0, 24, 3):
            for j in range(0, 24, 3):
                best_loss = float('inf')
                best_pattern_idx = None
                block = image[i:i+3, j:j+3]
                # Her birey için en iyi paternin hatasını bul
                for idx, individual in enumerate(population):
                    best_loss = float('inf')
                    for pattern in individual:
                        loss = np.sum(block != pattern)
                        best_loss = min(best_loss, loss)
                    fitness_values[idx] += best_loss
    
    return fitness_values

# Bireyin paternlerinde rastgele piksel değiştirerek mutasyon uygular
def mutate(individual, mutation_rate=MUTATION_RATE):
    for pattern in individual:
        if random.random() < mutation_rate:
            x = random.randint(0, 2)
            y = random.randint(0, 2)
            pattern[x, y] = 1 - pattern[x, y]
    return individual

# İki ebeveynin patern setlerini çaprazlayarak yeni çocuklar oluşturur
def crossover(parent1, parent2, crossover_rate=CROSSOVER_RATE):
    if random.random() < crossover_rate:
        point = random.randint(1, NUM_PATTERNS - 1) # Çaprazlama noktası
        child1 = np.vstack((parent1[:point], parent2[point:]))
        child2 = np.vstack((parent2[:point], parent1[point:]))
        return child1, child2
    return parent1.copy(), parent2.copy()

# Orijinal ve optimize edilmiş görüntü arasındaki benzerlik oranını hesaplar
def calculate_similarity(original_image, optimized_image):
    correct_pixels = np.sum(original_image == optimized_image)
    total_pixels = original_image.size
    return correct_pixels / total_pixels

# Paternleri görselleştirip dosyaya kaydeder
def save_patterns(patterns, filename):
    fig, axes = plt.subplots(1, NUM_PATTERNS, figsize=(NUM_PATTERNS*2, 2))
    cmap = ListedColormap(['white', 'black'])
    
    for i, ax in enumerate(axes):
        ax.imshow(patterns[i], cmap=cmap, vmin=0, vmax=1)
        ax.set_title(f'Pattern {i+1}')
        # Kırmızı sınır ekle
        rect = patches.Rectangle((-0.5, -0.5), 3, 3, 
                                linewidth=1, edgecolor='red', facecolor='none')
        ax.add_patch(rect)
        ax.axis('off')
    
    plt.tight_layout()
    plt.savefig(filename)
    plt.close()

# Genetik algoritmanın ana işleyişini yönetir
def genetic_algorithm():
    # Başlangıç popülasyonunu ve görüntüleri yükle
    population = initialize_population(POPULATION_SIZE)
    images = [load_image(f"input1/image{i}.png") for i in range(1, 6)]
    
    # İlk paternleri kaydet
    initial_patterns = population[np.argmin(fitness_function(images, population))]
    save_patterns(initial_patterns, 'output/first_patterns.png')
    
    # fitness kayıtlarını tut
    fitness_log = []
    best_fitness_log = []
    
    
    # Görselleştirme için ayarlar
    plt.ioff()  
    fig, axes = plt.subplots(1, NUM_PATTERNS, figsize=(NUM_PATTERNS*2, 2.5))  # Yüksekliği artırdık
    plt.subplots_adjust(bottom=0.25)  
    cmap = ListedColormap(['white', 'black'])

    # Butonları oluştur
    ax_prev = plt.axes([0.3, 0.1, 0.15, 0.075])  # [left, bottom, width, height]
    ax_next = plt.axes([0.55, 0.1, 0.15, 0.075])
    btn_prev = Button(ax_prev, '← Önceki')
    btn_next = Button(ax_next, 'Sonraki →')

    # İlk görüntüleri ve dikdörtgenleri hazırla
    ims = []
    for i, ax in enumerate(axes):
        im = ax.imshow(np.zeros((3,3)), cmap=cmap, vmin=0, vmax=1)
        ims.append(im)
        ax.set_title(f'Pattern {i+1}\nGen: 0')  # Nesil bilgisi eklendi
        rect = patches.Rectangle((-0.5, -0.5), 3, 3, linewidth=1, edgecolor='red', facecolor='none')
        ax.add_patch(rect)
        ax.axis('off')

    generation_history = []
    current_generation = 0

    # Görselleştirme güncelleme fonksiyonları
    
    # Paternleri belirtilen nesil indeksine göre günceller
    def update_plot(gen_idx):
        if not generation_history:
            return
        for i, im in enumerate(ims):
            im.set_data(generation_history[gen_idx][i])
            axes[i].set_title(f'Pattern {i+1}\nGen: {gen_idx}')
        fig.canvas.draw_idle()

    # Klavye ile nesil geçişi
    def on_key(event):
        global current_generation
        if event.key == 'left':
            prev_gen(None)
        elif event.key == 'right':
            next_gen(None)

    # Önceki nesile git
    def prev_gen(event):
        global current_generation
        current_generation = max(0, current_generation - 1)
        update_plot(current_generation)

    # Sonraki nesile git
    def next_gen(event):
        global current_generation
        current_generation = min(len(generation_history) - 1, current_generation + 1)
        update_plot(current_generation)

    # Buton ve tuş dinleyicileri
    btn_prev.on_clicked(prev_gen)
    btn_next.on_clicked(next_gen)
    fig.canvas.mpl_connect('key_press_event', on_key)

    plt.ion()

    # Ana genetik algoritma döngüsü
    for gen in range(GENERATIONS):    
        # Uygunluk hesaplama    
        fitness_values = fitness_function(images, population)
        fitness_log.append(np.mean(fitness_values))
        best_fitness_log.append(np.min(fitness_values))
        # En iyi bireyi kaydet
        best_individual = population[np.argmin(fitness_values)]
        
        # Güncelleme
        generation_history.append(best_individual.copy())
        current_generation = len(generation_history) - 1
        update_plot(current_generation)
        plt.pause(0.1)
        
        print(f"Generation:{gen}, Average Fitness:{np.mean(fitness_values)}, Best Fitness:{min(fitness_values)}")
        
        # Yeni nesil oluşturma
        population = selection(population, fitness_values)
        next_population = []
        
        # Çaprazlama ve mutasyon
        for i in range(0, len(population)-1, 2):
            parent1 = population[i]
            parent2 = population[i + 1]
            child1, child2 = crossover(parent1, parent2)
            next_population.append(mutate(child1))
            next_population.append(mutate(child2))
        
        population += next_population

    plt.show(block=True)  # block=True yaparak ana döngüyü koru
    plt.ioff()
    plt.close()
    
    # Sonuçları kaydet ve raporla
    best_individual = population[np.argmin(fitness_values)]
    print("Best Patterns:\n", best_individual)
    save_patterns(best_individual, 'output/best_patterns.png')
    
    # Fitness grafiği
    plt.figure()
    plt.plot(fitness_log, label='Average Fitness')
    plt.plot(best_fitness_log, label='Best Fitness')
    plt.xlabel('Generation')
    plt.ylabel('Loss')
    plt.title('Fitness Progress')
    plt.legend()
    plt.savefig('output/fitness_progress.png')
    plt.close()
    
    # Benzerlik hesaplamaları
    total_accuracy = 0
    for idx, image in enumerate(images):
        optimized_image = np.zeros_like(image)
        
        # En iyi paternlerle görüntüyü yeniden oluştur
        for i in range(0, 24, 3):
            for j in range(0, 24, 3):
                best_loss = float('inf')
                best_pattern = None
                block = image[i:i+3, j:j+3]
                for pattern in best_individual:                    
                    loss = np.sum(block != pattern)
                    if loss < best_loss:
                        best_loss = loss
                        best_pattern = pattern
                optimized_image[i:i+3, j:j+3] = best_pattern
        
        # Görsel karşılaştırma
        fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(8, 4))
        ax1.imshow(image, cmap='gray')
        ax1.set_title(f'Orjinal Resim {idx+1}')
        ax1.axis('off')
        
        ax2.imshow(optimized_image, cmap='gray')
        ax2.set_title(f'Çizilen Resim {idx+1}')
        ax2.axis('off')
        
        plt.tight_layout()
        plt.savefig(f'output/output{idx+1}.png')
        plt.close()
        
        # Benzerlik yüzdesi
        similarity = calculate_similarity(image, optimized_image)
        total_accuracy += similarity
        print(f"Similarity between original and optimized image {idx+1}: {similarity * 100:.2f}%")
    
    print(f"Avarage Similarity: {total_accuracy / 5 * 100:.2f}%")
    
    return best_individual

# Görselleştirme olmadan genetik algoritma çalıştırır.
def genetic_algorithm_wo_plot(population_size, generations, crossover_rate, mutation_rate):
    # Popülasyonu ve görüntüleri yükle
    population = initialize_population(population_size)
    images = [load_image(f"input1/image{i}.png") for i in range(1, 6)]

    # Genetik algoritma ana döngüsü
    for gen in range(generations):      
        # Uygunluk hesaplama ve en iyi bireyin seçimi
        fitness_values = fitness_function(images, population)
        best_individual = population[np.argmin(fitness_values)]
        
        # Yeni nesil oluşturma
        population = selection(population, fitness_values)
        next_population = []
        
        # Çaprazlama ve mutasyon
        for i in range(0, len(population)-1, 2):
            parent1 = population[i]
            parent2 = population[i + 1]
            child1, child2 = crossover(parent1, parent2, crossover_rate)
            next_population.append(mutate(child1, mutation_rate))
            next_population.append(mutate(child2, mutation_rate))
        
        population += next_population

    # Sonuçları kaydet
    best_individual = population[np.argmin(fitness_values)]
    
    # Benzerlik hesaplamaları
    total_accuracy = 0
    for idx, image in enumerate(images):
        optimized_image = np.zeros_like(image)
        
        # En iyi paternlerle görüntüyü yeniden oluştur
        for i in range(0, 24, 3):
            for j in range(0, 24, 3):
                best_loss = float('inf')
                best_pattern = None
                block = image[i:i+3, j:j+3]
                for pattern in best_individual:                    
                    loss = np.sum(block != pattern)
                    if loss < best_loss:
                        best_loss = loss
                        best_pattern = pattern
                optimized_image[i:i+3, j:j+3] = best_pattern
        
        similarity = calculate_similarity(image, optimized_image)
        total_accuracy += similarity
    
    print(f"Avarage Similarity: {total_accuracy / 5 * 100:.2f}%")
    
    return best_individual, total_accuracy / 5 * 100

# Mutasyon oranının performansa etkisini analiz eder.
def analyze_mutation_rate():
    similarities = []
    mutation_rates = []
    
    # Sabit parametreler
    generations = 15
    population_size = 15
    crossover_rate = 0.45
    
    # 0.0'dan 1.0'a kadar 0.1'lik adımlarla mutasyon oranlarını test et
    for rate in np.arange(0, 1.10, 0.1): 
        mutation_rates.append(rate)
        mutation_rate = rate
        total_similarity = 0
        
        # Her mutasyon oranı için 3 bağımsız deney
        for _ in range(0, 3):
            _, similarity = genetic_algorithm_wo_plot(population_size, generations, crossover_rate, mutation_rate)
            total_similarity += similarity
        similarities.append(total_similarity / 3) # Ortalama benzerlik
    
    # Sonuçları görselleştirme
    plt.figure()
    plt.plot(mutation_rates, similarities)
    plt.xlabel('Mutation Rates')
    plt.ylabel('Average Similarities')
    plt.title('Similarity vs Mutation Rate')
    plt.savefig('output/similarity_vs_mutationrate.png')
    plt.close()

# Popülasyon büyüklüğünün performansa etkisini analiz eder.
def analyze_population_size():
    similarities = []
    population_sizes = []
    
    # Sabit parametreler
    generations = 15
    mutation_rate = 0.15
    crossover_rate = 0.45
    
    # 5'ten 50'e kadar popülasyon boyutlarını test et
    for size in np.arange(5, 55, 5): 
        population_sizes.append(size)
        population_size = size
        total_similarity = 0
        
        # Her boyut için 3 bağımsız deney
        for _ in range(0, 3):
            _, similarity = genetic_algorithm_wo_plot(population_size, generations, crossover_rate, mutation_rate)
            total_similarity += similarity
        similarities.append(total_similarity / 3) # Ortalama benzerlik
    
    # Sonuçları görselleştirme
    plt.figure()
    plt.plot(population_sizes, similarities)
    plt.xlabel('Population Sizes')
    plt.ylabel('Average Similarities')
    plt.title('Similarity vs Population Size')
    plt.savefig('output/similarity_vs_populationsize.png')
    plt.close()        

if __name__ == '__main__':
    genetic_algorithm()
    
    # analyze_mutation_rate()
    # analyze_population_size()
