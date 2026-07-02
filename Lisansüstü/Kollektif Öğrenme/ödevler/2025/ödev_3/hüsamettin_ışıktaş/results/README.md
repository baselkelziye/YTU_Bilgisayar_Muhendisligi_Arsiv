# 📁 Results Klasör Yapısı

Bu klasör, GRPO eğitim deneylerinin tüm sonuçlarını düzenli bir şekilde içerir.

## 📂 Klasör Yapısı

```
results/
├── baseline/                    # Eğitimsiz model sonuçları
│   ├── baseline_results.csv     # Detaylı sonuçlar (CSV)
│   ├── baseline_results.json    # Detaylı sonuçlar (JSON)
│   └── baseline_summary.json    # Özet istatistikler
│
├── experiments/                 # Her reward fonksiyonu için ayrı klasör
│   ├── short/
│   │   ├── training_metrics.csv # Eğitim metrikleri (loss, reward)
│   │   ├── sample_completions.txt
│   │   ├── results.csv          # Test sonuçları
│   │   ├── results.json
│   │   └── comparison.json      # Baseline karşılaştırması
│   ├── long/
│   ├── turkish/
│   ├── connectives/
│   └── simple/
│
├── merged_models/               # Birleştirilmiş model sonuçları
│   ├── trained_model_results_merged_simple_long.*
│   └── trained_model_results_merged_connectives_turkish.*
│
└── summary/                     # Final özet raporlar
    ├── FINAL_LEADERBOARD.csv
    └── FINAL_LEADERBOARD.md
```

## 📊 Dosya Açıklamaları

### Baseline Klasörü
- **baseline_summary.json**: Accuracy, format compliance özeti
- **baseline_results.csv/json**: Her test örneği için detaylı sonuçlar

### Experiment Klasörleri (short, long, turkish, connectives, simple)
- **training_metrics.csv**: Step bazında loss, reward_mean, reward_std
- **results.csv/json**: 500 test örneği üzerinde model tahminleri
- **comparison.json**: Baseline'a göre iyileşme/düşüş oranları

### Summary Klasörü
- **FINAL_LEADERBOARD.csv/md**: Tüm modellerin sıralı karşılaştırması

## 🔗 İlişkili Klasörler

- `logs/`: Eğitim çıktı logları (training_output_*.txt)
- `plots/`: Görselleştirmeler
- `models/`: Kayıtlı model checkpoint'ları
