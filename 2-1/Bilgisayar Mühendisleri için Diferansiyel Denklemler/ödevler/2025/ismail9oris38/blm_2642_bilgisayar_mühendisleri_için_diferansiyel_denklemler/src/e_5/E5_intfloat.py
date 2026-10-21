import torch
import numpy as np
from sentence_transformers import SentenceTransformer

# --- Fonksiyonlar ---

def get_detailed_instruct(task_description: str, query: str) -> str:
    # E5 model ailesi (ytu-ce-cosmos ve intfloat modelleri dahil)
    # genellikle daha iyi performans için bu "Instruct" formatını kullanır.
    return f'Instruct: {task_description}\nQuery: {query}'

task = 'Given a Turkish search query, retrieve relevant passages written in Turkish that best answer the query'

def load_data():
    queries = []
    good_answers = []
    bad_answers = []

    # UTF-8 hatası almamak için encoding belirtiyoruz
    with open("../Data/test.txt", "r", encoding="utf-8") as f:
        lines = f.readlines()
        for line in lines:
            parts = line.strip().split(",")
            if len(parts) >= 3:
                queries.append(get_detailed_instruct(task, parts[0].strip()))
                good_answers.append(parts[1].strip())  # Doğru cevap
                bad_answers.append(parts[2].strip())  # Yanlış cevap

    return queries, good_answers, bad_answers

# --- Veri Yükleme ---

queries, good_answers, bad_answers = load_data()

# Sadece tensörleri tutacak listeyi kullanıyoruz
soru_cevap_tensorleri = []

# intfloat/multilingual-e5-large.
model = SentenceTransformer('intfloat/multilingual-e5-large')

# --- Gömülmelerin Hesaplama ve Birleştirme (Concatenation) ---

# Tüm gömülmelerin hesaplanması
embeddings_queries = model.encode(queries, convert_to_tensor=True, normalize_embeddings=True)
embeddings_good_answers = model.encode(good_answers, convert_to_tensor=True, normalize_embeddings=True)
embeddings_bad_answers = model.encode(bad_answers, convert_to_tensor=True, normalize_embeddings=True)

# Gömülme boyutunu kontrol edelim (Beklenen: 768)
print(f"Sorgu gömülme boyutu: {len(embeddings_queries[0])}")
print(f"Cevap gömülme boyutu: {len(embeddings_good_answers[0])}")


# Gömülmeleri yan yana birleştirme (Concatenation) ve listeye ekleme
for i in range(len(queries)):
    # 1. Doğru Cevap Örneği (Query + Good Answer)
    # 768 + 768 = 1536 boyutlu bir tensör oluşur.
    combined_positive = torch.cat((embeddings_queries[i], embeddings_good_answers[i]), dim=0)
    soru_cevap_tensorleri.append(combined_positive)

    # 2. Yanlış Cevap Örneği (Query + Bad Answer)
    combined_negative = torch.cat((embeddings_queries[i], embeddings_bad_answers[i]), dim=0)
    soru_cevap_tensorleri.append(combined_negative)

# 3. Listeyi Tek Bir Büyük Tensöre Yığma (Stacking)
# Tensör şekli: (Toplam Örnek Sayısı, 1536)
all_embeddings_tensor = torch.stack(soru_cevap_tensorleri)

# --- Kayıt İşlemi ---

# 4. Tensörü NumPy Dizisine Çevirme ve Kaydetme (Giriş Verisi)
all_embeddings_numpy = all_embeddings_tensor.cpu().numpy()
np.save("../Vektör/test_vektor_intfloat.npy", all_embeddings_numpy)

print("\n--- Çıktı Kontrolü ---")
print(f"✅ Gömülmeler başarıyla birleştirildi ve kaydedildi.")
# Toplam örnek sayısı = 2 * len(queries), Gömülme boyutu = 2 * 768 = 1536
print(f"Oluşturulan girdi verisinin şekli: {all_embeddings_numpy.shape}")