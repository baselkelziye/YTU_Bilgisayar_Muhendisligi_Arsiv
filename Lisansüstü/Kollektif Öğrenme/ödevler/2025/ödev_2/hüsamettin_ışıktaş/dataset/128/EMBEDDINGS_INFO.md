# Embedding Bilgileri

## Model Bilgisi

- **Model**: [ytu-ce-cosmos/turkish-e5-large](https://huggingface.co/ytu-ce-cosmos/turkish-e5-large)
- **Embedding Varyantı**: pca_128
- **Başlık/Özet Embedding Boyutu**: 128
- **Birleştirilmiş Embedding Boyutu**: 256

## Oluşturulan Verisetleri

| Dosya | Açıklama | Boyut |
|-------|----------|-------|
| train_title_embeddings.npz | Eğitim - Başlık embeddinglari | (6250, 128) |
| train_abstract_embeddings.npz | Eğitim - Özet embeddinglari | (6250, 128) |
| train_concat_embeddings.npz | Eğitim - Birleştirilmiş embeddingler | (6250, 256) |
| test_title_embeddings.npz | Test - Başlık embeddinglari | (6250, 128) |
| test_abstract_embeddings.npz | Test - Özet embeddinglari | (6250, 128) |
| test_concat_embeddings.npz | Test - Birleştirilmiş embeddingler | (6250, 256) |

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

- **Orijinal Embedding Boyutu**: 1024 (turkish-e5-large model çıktısı)
- **PCA ile Düşürülmüş Boyut**: 128
- **Concat Embedding Boyutu**: 256 (Başlık + Özet)
- PCA modelleri `title_pca_model.joblib` ve `abstract_pca_model.joblib` olarak kaydedilmiştir.

## Notlar

- Tüm embeddingler L2 normalize edilmiştir.
- E5 modeli için "query: " prefix'i kullanılmıştır.
- Boş başlık/özet durumunda boş string için embedding oluşturulmuştur.
- Türkçe metin yoksa İngilizce metin kullanılmıştır.
- PCA modelleri sadece PCA varyantı için train verisi üzerinden eğitilmiş, hem train hem test verisine uygulanmıştır.
