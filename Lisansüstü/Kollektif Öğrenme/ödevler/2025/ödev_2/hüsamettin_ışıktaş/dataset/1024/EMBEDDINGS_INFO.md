# Embedding Bilgileri

## Model Bilgisi

- **Model**: [ytu-ce-cosmos/turkish-e5-large](https://huggingface.co/ytu-ce-cosmos/turkish-e5-large)
- **Embedding Varyantı**: raw_1024
- **Başlık/Özet Embedding Boyutu**: 1024
- **Birleştirilmiş Embedding Boyutu**: 2048

## Oluşturulan Verisetleri

| Dosya | Açıklama | Boyut |
|-------|----------|-------|
| train_title_embeddings.npz | Eğitim - Başlık embeddinglari | (6250, 1024) |
| train_abstract_embeddings.npz | Eğitim - Özet embeddinglari | (6250, 1024) |
| train_concat_embeddings.npz | Eğitim - Birleştirilmiş embeddingler | (6250, 2048) |
| test_title_embeddings.npz | Test - Başlık embeddinglari | (6250, 1024) |
| test_abstract_embeddings.npz | Test - Özet embeddinglari | (6250, 1024) |
| test_concat_embeddings.npz | Test - Birleştirilmiş embeddingler | (6250, 2048) |

## Kullanım

```python
import numpy as np

# Veriyi yükle
data = np.load('dataset/train_title_embeddings.npz')
X_train = data['embeddings']  # Embedding matrisi
y_train = data['years']       # Yıl etiketleri

print(f"X shape: {X_train.shape}")
print(f"y shape: {y_train.shape}")
```

## PCA Bilgisi

- PCA uygulanmamıştır; modelden çıkan 1024 boyutlu embeddingler doğrudan kaydedilmiştir.
- Concat embedding boyutu 2048 olarak hesaplanmıştır.

## Notlar

- Tüm embeddingler L2 normalize edilmiştir.
- E5 modeli için "query: " prefix'i kullanılmıştır.
- Boş başlık/özet durumunda boş string için embedding oluşturulmuştur.
- Türkçe metin yoksa İngilizce metin kullanılmıştır.
- PCA modelleri sadece PCA varyantı için train verisi üzerinden eğitilmiş, hem train hem test verisine uygulanmıştır.
