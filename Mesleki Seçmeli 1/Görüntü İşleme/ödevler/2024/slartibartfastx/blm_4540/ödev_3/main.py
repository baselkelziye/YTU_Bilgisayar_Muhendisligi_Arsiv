import cv2
import numpy as np
import pandas as pd
from pathlib import Path
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, accuracy_score


# initialize_centroids fonksiyonu numpy kütüphanesindeki random özelliğini kullanarak veri
# kümesinden random k adet centroid seçer.
def initialize_centroids(features, k):
    indices = np.random.choice(len(features), k, replace=False)
    centroids = features[indices]
    print(f"Selected indices for centroids: {indices}")
    return centroids, indices


# assign_clusters fonksiyonu seçilmiş kümelerin içine resimleri doldurma işlemi yapar.
def assign_clusters(features, centroids, indices):
    clusters = {}
    for idx, centroid in enumerate(centroids):
        clusters[idx] = [indices[idx]]
    mean_red_centroids = []
    mean_green_centroids = []
    mean_blue_centroids = []
    # kodun bu kısmında daha önce hesapladığımız histogram değerlerini 3 ayrı arraya bölüyoruz
    # ilk array red ikinci blue ve 3. green olmak üzere 3 ayrı normalize edilmiş histogram elde ediyoruz.
    for idx, centroid in enumerate(centroids):
        red_centroid = centroid[:256].T
        green_centroid = centroid[256:512].T
        blue_centroid = centroid[512:].T
        # Calculate the mean values of red, green, and blue centroids
        # elde ettiğimiz histogramların mean değerlerini alıyoruz bu sayede
        # Euclidean distanceile hesaplama yapabileceğiz.
        # histogramların mean valuelarını bulmak için weighted sum yöntemi kullanıyoruz.
        mean_red_centroid = np.sum(red_centroid * np.arange(1, 257))/1
        mean_green_centroid = np.sum(green_centroid * np.arange(1, 257))/1
        mean_blue_centroid = np.sum(blue_centroid * np.arange(1, 257))/1

        mean_red_centroids.append(mean_red_centroid)
        mean_green_centroids.append(mean_green_centroid)
        mean_blue_centroids.append(mean_blue_centroid)

    for i, x in enumerate(features):
        xtranspose = x.T
        red_x = xtranspose[:, :256]
        green_x = xtranspose[:, 256:512]
        blue_x = xtranspose[:, 512:]
# aynı mean bulma yöntemini her bir resim için yapıyoruz.
        mean_red_x = np.sum(red_x * np.arange(1, 257))/1
        mean_green_x = np.sum(green_x * np.arange(1, 257))/1
        mean_blue_x = np.sum(blue_x * np.arange(1, 257))/1
# bulduğumuz değerleri Euclidean distance fonksyionumuza sokuyoruz ve centroidler ile resimleri karşılaştırıyoruz.
        distances = np.sqrt(
            np.square(mean_red_x - mean_red_centroids) +
            np.square(mean_green_x - mean_green_centroids) +
            np.square(mean_blue_x - mean_blue_centroids)
        )
# karşılaştırmalar sonucu en yakın değeri buluyoruz ve resmi en yakın clusterın içine yerleştiriyoruz.
        closest = np.argmin(distances)
        if i != indices[closest]:
            clusters[closest].append(i)
# clusterları yazdırma kısmı
    for cluster_idx, feature_indices in clusters.items():
        print(f"Cluster {cluster_idx} assigned to Features: {feature_indices}")

    return clusters
def kmeans(features, k):
    # hem centroid belirleme hem de clusterları düzenlemeyi aynı anda gerçekleştiren bir fonksiyon.
    centroids, indices = initialize_centroids(features, k)
    clusters = assign_clusters(features, centroids, indices)
    return clusters, centroids


# csv dosyasından okuma fonksiyonu kolaylık saglaması için.
def read_csv(csv_path):
    return pd.read_csv(csv_path)


def calculate_normalized_histogram(image):
    # her bir resmin RGB histogramlarını cv2 sayesinde hesaplama fonksiyonu cv2 her 3 fonksiyonu da tek bir array
    # içinde tutmayı tercih ediyor ancak biz cluster hesaplama işlemimizde bu 3 arrayı ayırarak 3 ayrı histogram
    # elde ediyoruz.
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    channels = cv2.split(image_rgb)
    hists = []

    plt.figure(figsize=(12, 6))

    total_pixels = image.size

    for i, chan in enumerate(channels, 1):
        hist = cv2.calcHist([chan], [0], None, [256], [0, 256])
        hist_normalized = hist / total_pixels
        hists.append(hist_normalized)

    return np.concatenate(hists)

def load_images(filenames, base_path):
    #resim yükleme fonksiyonu
    images = {}
    for file_name in filenames:
        file_path = base_path / file_name
        image = cv2.imread(str(file_path))
        if image is not None:
            images[file_name] = image
    return images

def extract_true_labels(df, color_columns):
    #burada her bir resmin gerçek labelını alma işlemi yapıyoruz bunun sebebi confussion matrixi doğru hesaplamak
    true_labels = df[color_columns].idxmax(axis=1)
    label_to_num = {color: idx for idx, color in enumerate(color_columns)}
    numerical_labels = true_labels.map(label_to_num)
    return numerical_labels

def show_cluster_elements_grid(loaded_images, clusters, image_names, num_elements=25):
    #resimleri çıktı olarak alma fonksiyonu
    for cluster_id, indices in clusters.items():
        plt.figure(figsize=(20, 5))
        plt.suptitle(f'Cluster {cluster_id}', fontsize=20)
        for i, index in enumerate(indices[:num_elements]):
            plt.subplot(1, num_elements, i + 1)
            image_file = image_names[index]
            image = loaded_images.get(image_file)
            if image is not None:
                image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
                plt.imshow(image)
                plt.axis('off')
        plt.show()
        plt.pause(2)  # çok fazla plot çıkardığımız için htpp error yiyebiliyoruz bu yüzden pause koydum.

def evaluate_clusters(clusters, true_labels, class_names):
    predicted_labels = np.zeros_like(true_labels)

    # Her bir clusterın centroidini clusterın etiketi yani rengi olarak belirledim.
    for cluster_id, indices in clusters.items():
        centroid_label = true_labels[indices[0]]  # cluster hesaplama fonksiyonunda centroidi ilk eleman belirlemiştim.
        #bu sayede clusterın gerçek labelını elde edebiliyoruz bu confussion matrixin doğru olmasını sağlıyor.

        # clusterdaki her bir elemanın tahmin edilen label'ını centroid labelı olarak yazıyoruz.
        for i in indices:
            predicted_labels[i] = centroid_label # Assigning the centroid index as the predicted label

    # Bu sayede confussion matrix hesaplamasını gerçekleştirebiliyoruz. Bunun için sklearn kütüphanesi kullandım.
    cm = confusion_matrix(true_labels, predicted_labels)

    # elde ettiğim matrixi görselleştirdim.
    plt.figure(figsize=(10, 7))
    sns.heatmap(cm, annot=True, fmt="d", xticklabels=class_names, yticklabels=class_names)
    plt.title('Confusion Matrix')
    plt.xlabel('Predicted')
    plt.ylabel('True')
    plt.show()

    # bu kısımda başarı yüzdemi hesapladım.
    accuracy = accuracy_score(true_labels, predicted_labels)
    print(f"Accuracy: {accuracy * 100:.2f}%")

    return cm
def main(csv_file_name, images_directory, k, iterations):
    #main fonksiyonumda tüm belirlediğim fonksiyonları kullandım ve K-means algoritmasını gerçekleştirdim.
    df = read_csv(csv_file_name)
    df.columns = df.columns.str.strip()
    color_columns = ['red', 'blue', 'green', 'gray', 'white']
    class_names = ['0', '1', '2', '3', '4']

    selected_df = pd.DataFrame()

    # her bir label için ilk 20 resmi seçiyorum.
    for color in color_columns:
        color_samples = df[df[color] == 1].sample(20)
        selected_df = pd.concat([selected_df, color_samples])

    true_labels = extract_true_labels(selected_df, color_columns).to_numpy()
    image_names = selected_df['filename'].tolist()
    loaded_images = load_images(image_names, images_directory)

    # resimlerle rahat işlem yapabilmek için her bir resmi numpy array haline getiriyorum.
    image_features = np.array([calculate_normalized_histogram(loaded_images[img_name]) for img_name in image_names if
                               img_name in loaded_images])
    #10 adet iterasyon yapıyorum.
    for iteration in range(iterations):
        print(f"Iteration {iteration + 1}/{iterations}")
        clusters, centroids = kmeans(image_features, k)

        evaluate_clusters(clusters, true_labels, class_names)
        show_cluster_elements_grid(loaded_images, clusters, image_names)

if __name__ == "__main__":
    #bu kısımda da son olarak resim ve csv pathlarimi belirliyorum iterasyon sayımı ve k değerimi belirliyorum
    #belirlemelerden sonra main fonksiyonumu çalıştırıyorum.
    csv_file_path = Path(r'C:\Users\sefac\PycharmProjects\pythonProject4\color.v1-color_v7.multiclass\train\_classes.csv')
    images_directory = Path(r'C:\Users\sefac\PycharmProjects\pythonProject4\color.v1-color_v7.multiclass\train')
    k = 5
    iterations = 10
    main(csv_file_path, images_directory, k, iterations)
