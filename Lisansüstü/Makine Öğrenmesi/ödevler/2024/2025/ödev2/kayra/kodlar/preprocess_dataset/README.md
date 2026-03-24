# 🔧 Veri Kümesi Ön İşleme

Bu klasör, Online News Popularity veri kümesi için ön işleme adımlarını içermektedir.

## 📁 Klasör Yapısı

```
preprocess_dataset/
├── README.md                    # Bu dosya
└── data_preprocessing.ipynb     # Ana ön işleme notebook'u
```

## 📋 Ön İşleme Adımları

`data_preprocessing.ipynb` notebook'u aşağıdaki işlemleri gerçekleştirir:

### 1. Veri Yükleme
- `dataset_files/dataset.csv` dosyası okunur

### 2. Gereksiz Sütunların Kaldırılması
- `url` - Ayırt edici bilgi içermez
- `timedelta` - Analiz için gerekli değil

### 3. Hedef Değişken Dönüşümü
- `shares` sütunu ikili hedef değişkene dönüştürülür:
  - **1** → `shares >= 1400`
  - **0** → `shares < 1400`
- Yeni sütun adı: `is_popular`
- Original `shares` sütunu kaldırılır

### 4. Veri Kaydetme
- İşlenmiş veri `dataset_files/processed_dataset.csv` olarak kaydedilir

## 🚀 Kullanım

```bash
cd preprocess_dataset
jupyter notebook data_preprocessing.ipynb
```

Notebook'u açtıktan sonra tüm hücreleri sırayla çalıştırın (Kernel → Restart & Run All).

## 📊 Girdi/Çıktı

| Tür | Dosya | Açıklama |
|-----|-------|----------|
| Girdi | `dataset_files/dataset.csv` | Ham veri kümesi (61 sütun) |
| Çıktı | `dataset_files/processed_dataset.csv` | İşlenmiş veri (59 sütun + hedef) |