from sentence_transformers import SentenceTransformer

# ------------------------------------------------------------
# Görevi ve sorguyu tek bir formatta birleştiren yardımcı fonksiyon.
# Bu fonksiyon, modelin sorguyu daha iyi anlaması için:
# "Instruct: ...\nQuery: ..." şeklinde bir format oluşturuyor.
# ------------------------------------------------------------
def get_detailed_instruct(task_description: str, query: str) -> str:
    return f'Instruct: {task_description}\nQuery: {query}'

# ------------------------------------------------------------
# MODELİN GÖREV TANIMI:
# Türkçe bir arama sorgusu verildiğinde,
# bu sorguyla en ilgili Türkçe pasajları bulma görevi.
# ------------------------------------------------------------
task = 'Given a Turkish search query, retrieve relevant passages written in Turkish that best answer the query'

# ------------------------------------------------------------
# 2 adet sorgu oluşturuluyor.
# Her biri görev + soru formatında birleştiriliyor.
# ------------------------------------------------------------
queries = [
    get_detailed_instruct(task, "Türkiye'nin başkenti neresidir?"),
    get_detailed_instruct(task, "Python hangi amaçla kullanılır?")
]

# ------------------------------------------------------------
# Belge havuzu.
# Bu belgeler arasından sorgulara en uygun olanı bulunacak.
# ------------------------------------------------------------
documents = [
    "Türkiye'nin başkenti Ankara'dır",
    "Mars gezegeni kırmızı renktir",
    "Programlama dili olarak",
    "Müzik çalar",
    ]

# ------------------------------------------------------------
# Sorgular (2 adet) + Belgeler (3 adet) → Toplam 5 adet metin
# Embedding modeli hepsini tek seferde encode ediyor.
# ------------------------------------------------------------


# ------------------------------------------------------------
# Türkçe arama ve semantik eşleştirme için eğitilmiş e5 modelini yüklüyoruz.
# normalize_embeddings=True → tüm vektörleri birim uzunluğa getiriyor.
# Bu sayede cosine similarity hesabı çok daha kolay ve doğru oluyor.
# ------------------------------------------------------------
model = SentenceTransformer('ytu-ce-cosmos/turkish-e5-large')

embeddings_documents = model.encode(
    documents,
    convert_to_tensor=True,
    normalize_embeddings=True
)

embeddings_queries = model.encode(
    queries,
    convert_to_tensor=True,
    normalize_embeddings=True
)


# ------------------------------------------------------------
# İlk 2 embedding → sorgular.
# Son 3 embedding → belgeler.
# Sorgular ile belgeler arasında cosine similarity hesaplanıyor.
# @ işleci = matris çarpımı → normalize vektörlerde cosine similarity demektir.
# *100 → puanları daha okunur hale getiriyor.
# ------------------------------------------------------------
scores = (embeddings_queries @ embeddings_documents.T) * 100

# ------------------------------------------------------------
# Her sorgu için tüm belgeleri tek tek yazdırıyoruz.
# Skor ne kadar yüksekse, belgenin sorguya o kadar benzer olduğu anlamına gelir.
# ------------------------------------------------------------
for i, query in enumerate(queries):
    print(f"\nSorgu: {query.split('Query: ')[-1]}")  # sadece gerçek soruyu yazdırmak için

    for j, doc in enumerate(documents):
        print(f"   → Belge {j+1} Skoru: {scores[i][j]:.2f}")
        print(f"     İçerik: {doc[:80]}...")

"""
Sorgu: Kolay bir kahvaltı tarifi nedir?
   → Belge 1 Skoru: 67.36
     İçerik: Güne enerjik başlamak için yulaf ezmesi, süt ve meyveyle hazırlanan basit bir ka...
   → Belge 2 Skoru: 31.68
     İçerik: Sabah saatleri, özellikle 07:00 ile 10:00 arası, açık havada yürüyüş yapmak için...
   → Belge 3 Skoru: 7.06
     İçerik: Türkiye'nin en uzun nehri Kızılırmak'tır. Sivas'tan doğar, Karadeniz'e dökülür v...

Sorgu: Dış mekan yürüyüşü için en iyi saat hangisidir?
   → Belge 1 Skoru: 28.14
     İçerik: Güne enerjik başlamak için yulaf ezmesi, süt ve meyveyle hazırlanan basit bir ka...
   → Belge 2 Skoru: 78.02
     İçerik: Sabah saatleri, özellikle 07:00 ile 10:00 arası, açık havada yürüyüş yapmak için...
   → Belge 3 Skoru: 18.70
     İçerik: Türkiye'nin en uzun nehri Kızılırmak'tır. Sivas'tan doğar, Karadeniz'e dökülür v...
"""
