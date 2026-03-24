# 📊 Lojistik Regresyon Performans Değerlendirmesi

Bu klasör, farklı özellik seçim yöntemleriyle oluşturulan veri kümeleri üzerinde Lojistik Regresyon modelinin performansını değerlendirir.

## 📁 Klasör Yapısı

```
evaluate_performance/
├── helpers/                          # Yardımcı modüller
│   ├── __init__.py                   # Paket başlatıcı
│   ├── data_loader.py                # Veri yükleme ve bölme
│   ├── model_trainer.py              # Model eğitimi ve CV
│   ├── evaluation_metrics.py         # Performans metrikleri
│   └── report_generator.py           # Rapor oluşturma
├── results/                          # Sonuç dosyaları (otomatik oluşur)
├── logistic_regression_evaluation.ipynb  # Ana notebook
└── README.md                         # Bu dosya
```

## 🚀 Kullanım

### Jupyter Notebook ile Çalıştırma

```bash
cd evaluate_performance
jupyter notebook logistic_regression_evaluation.ipynb
```

### Hücreleri Sırayla Çalıştırma

Notebook'u açtıktan sonra tüm hücreleri sırayla çalıştırın (Kernel → Restart & Run All).

## 📊 Değerlendirilen Veri Kümeleri

| Adı | Dosya | Özellik Sayısı |
|-----|-------|----------------|
| Tüm Özellikler | `processed_dataset.csv` | 59 |
| Filtreleme (Pearson) | `filter_method_selected_dataset.csv` | 15 |
| Sarmalayıcı (RFE) | `wrapper_method_selected_dataset.csv` | 15 |
| Gömülü (Random Forest) | `embedded_method_selected_dataset.csv` | 15 |

## 🔧 Özellikler

- **5-Fold Cross Validation**: Her veri kümesi için stratified k-fold
- **Aşırı Öğrenme Tespiti**: Eğitim-validasyon fark analizi
- **Regularization**: Aşırı öğrenme tespit edilirse otomatik C parametre ayarı
- **Performans Metrikleri**: Accuracy, F1-Score, Precision, Recall
- **Görselleştirmeler**: Karışıklık matrisleri ve karşılaştırma grafikleri
- **Markdown Rapor**: Detaylı sonuç raporu

## 📦 Gereksinimler

```
pandas
numpy
scikit-learn
matplotlib
seaborn
```

## 📝 Çıktılar

Notebook çalıştırıldığında `results/` klasöründe aşağıdaki dosyalar oluşur:

- `logistic_regression_results.csv` - Sonuç tablosu
- `evaluation_report.md` - Detaylı rapor
- `best_method_confusion_matrix.png` - En iyi yöntemin karışıklık matrisi
- `all_confusion_matrices.png` - Tüm yöntemlerin karışıklık matrisleri
- `method_comparison.png` - Yöntem karşılaştırma grafiği
