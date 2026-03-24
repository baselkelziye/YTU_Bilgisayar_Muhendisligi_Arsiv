# 🎓 Makine Öğrenmesi - Özellik Seçimi Projesi

Bu proje, **2025-2026 Güz Yarıyılı Makine Öğrenmesi Dersi (BLM5110)** kapsamında hazırlanmıştır. Proje, Online News Popularity veri kümesi üzerinde özellik seçimi yöntemlerinin karşılaştırmalı analizini içermektedir.

## 📋 Proje Özeti

Projenin amacı, bir haberin popüler olup olmayacağını tahmin eden ikili sınıflandırma modeli geliştirmek ve farklı özellik seçimi yöntemlerinin model performansına etkisini değerlendirmektir.

### Kullanılan Veri Kümesi
- **Kaynak**: [UCI Online News Popularity Dataset](https://www.kaggle.com/datasets/thehapyone/uci-online-news-popularity-data-set)
- **Örnek Sayısı**: 39.644 haber makalesi
- **Özellik Sayısı**: 61 (işleme sonrası 59)
- **Hedef Değişken**: `is_popular` (shares >= 1400 → 1, değilse → 0)

## 📁 Proje Yapısı

```
kodlar/
├── README.md                    # Bu dosya
├── requirenments.txt            # Gerekli Python kütüphaneleri
├── tanım.md                     # Ödev tanımı ve gereksinimleri
│
├── dataset_files/               # Veri kümeleri
│   ├── dataset.csv              # Ham veri kümesi
│   ├── processed_dataset.csv    # Ön işlenmiş veri kümesi
│   ├── filter_method_selected_dataset.csv    # Filtreleme yöntemi seçimi
│   ├── wrapper_method_selected_dataset.csv   # Sarmalayıcı yöntem seçimi
│   └── embedded_method_selected_dataset.csv  # Gömülü yöntem seçimi
│
├── preprocess_dataset/          # Veri ön işleme
│   ├── README.md
│   └── data_preprocessing.ipynb # Ön işleme notebook'u
│
├── feature_selection/           # Özellik seçimi yöntemleri
│   ├── README.md
│   ├── helpers/                 # Yardımcı modüller
│   ├── filter_method.ipynb      # Pearson Korelasyonu
│   ├── wrapper_method.ipynb     # RFE + Lojistik Regresyon
│   ├── embedded_method.ipynb    # Random Forest Importance
│   └── *_analysis_report.md     # Analiz raporları
│
└── evaluate_performance/        # Performans değerlendirmesi
    ├── README.md
    ├── helpers/                 # Yardımcı modüller
    ├── logistic_regression_evaluation.ipynb
    └── results/                 # Sonuç dosyaları
```

## 🚀 Kurulum ve Çalıştırma

### Gereksinimler

```bash
pip install -r requirenments.txt
```

### Adım Adım Çalıştırma

#### 1️⃣ Veri Ön İşleme
```bash
cd preprocess_dataset
jupyter notebook data_preprocessing.ipynb
```
- `url` ve `timedelta` sütunlarını kaldırır
- `shares` değerini ikili hedef değişkene (`is_popular`) dönüştürür
- İşlenmiş veriyi kaydeder

#### 2️⃣ Özellik Seçimi
```bash
cd feature_selection
```

Aşağıdaki notebook'ları sırasıyla çalıştırın:

| Notebook | Yöntem | Açıklama |
|----------|--------|----------|
| `filter_method.ipynb` | Pearson Korelasyonu | Filtreleme yöntemi |
| `wrapper_method.ipynb` | RFE + Lojistik Reg. | Sarmalayıcı yöntem |
| `embedded_method.ipynb` | Random Forest | Gömülü yöntem |

#### 3️⃣ Performans Değerlendirmesi
```bash
cd evaluate_performance
jupyter notebook logistic_regression_evaluation.ipynb
```
- 5-Fold Cross Validation ile model eğitimi
- Tüm yöntemlerin karşılaştırmalı analizi
- Performans metrikleri ve görselleştirmeler

## 📊 Özellik Seçimi Yöntemleri

| Yöntem | Teknik | Seçilen Özellik Sayısı |
|--------|--------|------------------------|
| Filtreleme | Pearson Korelasyonu | 15 |
| Sarmalayıcı | RFE + Lojistik Regresyon | 15 |
| Gömülü | Random Forest Feature Importance | 15 |

## 📈 Performans Metrikleri

Model performansı aşağıdaki metriklerle değerlendirilmektedir:
- **Accuracy** (Doğruluk)
- **F1-Score**
- **Precision** (Kesinlik)
- **Recall** (Duyarlılık)
- **Eğitim Süresi**

## 📦 Bağımlılıklar

```
pandas
numpy
matplotlib
scipy
scikit-learn
seaborn
```

## 📝 Çıktılar

### Özellik Seçimi Çıktıları
- `{method}_analysis_report.md` - Detaylı analiz raporu
- `{method}_selected_dataset.csv` - Seçilmiş özelliklerle veri kümesi

### Performans Değerlendirmesi Çıktıları
- `logistic_regression_results.csv` - Sonuç tablosu
- `evaluation_report.md` - Detaylı değerlendirme raporu
- `*_confusion_matrix.png` - Karışıklık matrisleri
- `method_comparison.png` - Yöntem karşılaştırma grafiği
