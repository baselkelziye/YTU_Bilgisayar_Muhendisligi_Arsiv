# 🔬 Feature Selection (Özellik Seçimi)

Bu klasör, Online News Popularity veri kümesi için üç farklı özellik seçimi yöntemini içermektedir.

## 📁 Dosya Yapısı

```
feature_selection/
├── README.md                           # Bu dosya
│
├── dataset_helper.py                   # Veri kümesi yükleme/kaydetme işlemleri
├── file_helper.py                      # Dosya okuma/yazma işlemleri
├── report_helper.py                    # Rapor oluşturma fonksiyonları
│
├── filter_method.ipynb                 # Filtreleme Yöntemi (Pearson)
├── wrapper_method.ipynb                # Sarmalayıcı Yöntem (RFE)
├── embedded_method.ipynb               # Gömülü Yöntem (Random Forest)
│
├── filter_analysis_report.md           # Filtreleme analiz raporu
├── wrapper_analysis_report.md          # Sarmalayıcı analiz raporu
├── embedded_analysis_report.md         # Gömülü analiz raporu
└── general_analysis.md                 # Genel karşılaştırma analizi
```

## 🔬 Yöntemler

### 1. Filtreleme Yöntemi (Filter Method)
- **Dosya:** `filter_method.ipynb`
- **Yöntem:** Pearson Korelasyonu
- **Açıklama:** Her özellik ile hedef değişken arasındaki doğrusal korelasyonu hesaplar

### 2. Sarmalayıcı Yöntem (Wrapper Method)
- **Dosya:** `wrapper_method.ipynb`
- **Yöntem:** RFE (Recursive Feature Elimination) + Lojistik Regresyon
- **Açıklama:** İteratif olarak en az önemli özellikleri eler

### 3. Gömülü Yöntem (Embedded Method)
- **Dosya:** `embedded_method.ipynb`
- **Yöntem:** Random Forest Feature Importance
- **Açıklama:** Ağaç tabanlı model kullanarak özellik önemlerini hesaplar

## 🚀 Kullanım

Her notebook'u sırasıyla çalıştırın:

1. `filter_method.ipynb` → `filter_analysis_report.md` + `filter_method_selected_dataset.csv`
2. `wrapper_method.ipynb` → `wrapper_analysis_report.md` + `wrapper_method_selected_dataset.csv`
3. `embedded_method.ipynb` → `embedded_analysis_report.md` + `embedded_method_selected_dataset.csv`

## 📊 Çıktılar

Her yöntem için:
- **Analiz Raporu:** Özellik sıralaması ve değerlendirme
- **Seçilmiş Veri Kümesi:** En iyi 15 özellik + hedef değişken (is_popular)

Seçilmiş veri kümeleri `dataset_files/` klasörüne kaydedilir.
