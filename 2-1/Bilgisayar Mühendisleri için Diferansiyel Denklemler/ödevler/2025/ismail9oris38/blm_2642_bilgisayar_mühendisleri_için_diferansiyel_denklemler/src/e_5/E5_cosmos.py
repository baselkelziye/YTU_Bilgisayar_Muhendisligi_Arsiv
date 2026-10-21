import torch
import numpy as np
from sentence_transformers import SentenceTransformer

def get_detailed_instruct(task_description: str, query: str) -> str:
    return f'Instruct: {task_description}\nQuery: {query}'

task = 'Given a Turkish search query, retrieve relevant passages written in Turkish that best answer the query'

def load_data():
    queries = []
    good_answers = []
    bad_answers = []

    with open("../Data/train.txt", "r", encoding="utf-8") as f:
        lines = f.readlines()
        for line in lines:
            parts = line.strip().split(",")
            if len(parts) >= 3:
                queries.append(get_detailed_instruct(task, parts[0].strip()))
                good_answers.append(parts[1].strip())  # Doğru cevap
                bad_answers.append(parts[2].strip())  # Yanlış cevap

    return queries, good_answers, bad_answers


queries, good_answers, bad_answers = load_data()

# Sadece tensörleri tutacak listeyi kullanıyoruz
soru_cevap_tensorleri = []

model = SentenceTransformer('ytu-ce-cosmos/turkish-e5-large')


# Tüm gömülmelerin hesaplanması
embeddings_queries = model.encode(queries, convert_to_tensor=True, normalize_embeddings=True)
embeddings_good_answers = model.encode(good_answers, convert_to_tensor=True, normalize_embeddings=True)
embeddings_bad_answers = model.encode(bad_answers, convert_to_tensor=True, normalize_embeddings=True)
print(len(embeddings_queries[0]))
print(len(embeddings_good_answers[0]))

# ✅ Gömülmeleri yan yana birleştirme (Concatenation) ve listeye ekleme
for i in range(len(queries)):
    # 1. Doğru Cevap Örneği (Query + Good Answer)
    combined_positive = torch.cat((embeddings_queries[i], embeddings_good_answers[i]), dim=0)
    # Doğrudan PyTorch tensörünü listeye ekliyoruz
    soru_cevap_tensorleri.append(combined_positive)

    # 2. Yanlış Cevap Örneği (Query + Bad Answer)
    combined_negative = torch.cat((embeddings_queries[i], embeddings_bad_answers[i]), dim=0)
    soru_cevap_tensorleri.append(combined_negative)

# 3. Listeyi Tek Bir Büyük Tensöre Yığma (Stacking)
# Artık listede sadece aynı boyutlu tensörler olduğu için hata almayacağız
all_embeddings_tensor = torch.stack(soru_cevap_tensorleri)

# 4. Tensörü NumPy Dizisine Çevirme ve Kaydetme (Giriş Verisi)
all_embeddings_numpy = all_embeddings_tensor.cpu().numpy()
np.save("../Vektör/train_vektor.npy", all_embeddings_numpy)

print(f"✅ Gömülmeler başarıyla birleştirildi ve kaydedildi.")
print(f"Oluşturulan girdi verisinin şekli: {all_embeddings_numpy.shape}")  # Örn: (200, 1536)

# 5. Etiketleri Oluşturma ve Kaydetme (Hedef Verisi)
# Her soru için bir doğru (1) ve bir yanlış (0) etiketlenir
labels = np.array([1.0, -1.0] * len(queries), dtype=np.float32)
np.save("../Vektör/reranker_etiketleri.npy", labels)

print(f"✅ Etiketler 'reranker_etiketleri.npy' dosyasına kaydedildi.")