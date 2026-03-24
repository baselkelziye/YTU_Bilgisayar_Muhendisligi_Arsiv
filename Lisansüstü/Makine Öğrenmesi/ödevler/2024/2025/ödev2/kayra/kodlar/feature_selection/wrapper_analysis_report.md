# Feature Selection Analiz Raporu

**Yöntem:** Sarmalayıcı Yöntem - RFE + Lojistik Regresyon
**Veri Kümesi:** processed_dataset.csv
**Boyut:** (39644, 59)
**Kaynak:** UCI Online News Popularity
**Tarih:** 2025-12-28 15:06:35

---

## 📊 Genel Değerlendirme


Sarmalayıcı yöntem olarak **Recursive Feature Elimination (RFE)** kullanılmıştır. 
Bu yöntem, **Lojistik Regresyon** algoritması ile birlikte uygulanmıştır.

### Yöntem Detayları:
- RFE, başlangıçta tüm özelliklerle başlar
- Her iterasyonda model eğitilir ve en az önemli özellik(ler) elenir
- Bu işlem istenilen özellik sayısına ulaşılana kadar devam eder
- Lojistik Regresyon katsayıları özellik önemini belirler

### Model Parametreleri:
- **Estimator:** LogisticRegression
- **Solver:** lbfgs
- **Max Iterations:** 1000
- **Step:** 1 (her adımda 1 özellik ele)

### Skorlama Yöntemi:
- Seçilen özellikler için **Lojistik Regresyon katsayılarının mutlak değerleri** kullanılmıştır
- Bu sayede özellikler arasında anlamlı bir önem sıralaması elde edilmiştir

### Avantajları:
- Model performansını doğrudan optimize eder
- Özellikler arası etkileşimleri dikkate alır
- Sıralı özellik seçimi sağlar

### Dezavantajları:
- Hesaplama maliyeti yüksek olabilir
- Seçilen modele bağımlı


**Seçilen Özellik Sayısı:** 15

---

## Özellik Sıralaması

| Sıra | Özellik | Normalize Skor | Yorum |
|------|---------|----------------|-------|
| 1 | n_non_stop_words | 1.0000 | 🥇 En önemli özelliklerden |
| 2 | n_non_stop_unique_tokens | 0.5507 | 🥇 En önemli özelliklerden |
| 3 | n_unique_tokens | 0.4451 | 🥇 En önemli özelliklerden |
| 4 | kw_avg_avg | 0.2902 | 🥈 Çok yüksek önem |
| 5 | kw_max_avg | 0.1633 | 🥈 Çok yüksek önem |
| 6 | data_channel_is_tech | 0.0900 | 🥉 Yüksek önem |
| 7 | is_weekend | 0.0771 | 🥉 Yüksek önem |
| 8 | LDA_00 | 0.0625 | 🥉 Yüksek önem |
| 9 | data_channel_is_socmed | 0.0576 | 🥉 Yüksek önem |
| 10 | kw_min_min | 0.0447 | 🥉 Yüksek önem |
| 11 | kw_avg_max | 0.0438 | Düşük-orta önem |
| 12 | kw_min_avg | 0.0428 | Düşük-orta önem |
| 13 | kw_avg_min | 0.0415 | Düşük-orta önem |
| 14 | self_reference_avg_sharess | 0.0361 | Düşük-orta önem |
| 15 | kw_max_min | 0.0334 | Düşük-orta önem |

---

## 📋 Seçilen Özellikler Listesi

Seçilen en iyi 15 özellik:

1. `n_non_stop_words`
2. `n_non_stop_unique_tokens`
3. `n_unique_tokens`
4. `kw_avg_avg`
5. `kw_max_avg`
6. `data_channel_is_tech`
7. `is_weekend`
8. `LDA_00`
9. `data_channel_is_socmed`
10. `kw_min_min`
11. `kw_avg_max`
12. `kw_min_avg`
13. `kw_avg_min`
14. `self_reference_avg_sharess`
15. `kw_max_min`

---

## 📝 Ek Notlar


RFE yöntemi, Lojistik Regresyon modelinin katsayılarını kullanarak özellik önemini belirler.
Bu nedenle, seçilen özellikler Lojistik Regresyon için en ayırt edici olanlardır.

**Not:** Veriler StandardScaler ile ölçeklendirilmiştir, bu Lojistik Regresyon için önemlidir.

**Düzeltme:** Bu rapor, Lojistik Regresyon katsayılarının mutlak değerleri kullanılarak oluşturulmuştur.
Önceki versiyonda tüm seçilen özellikler için RFE ranking=1 olduğundan normalize skorlar yanlışlıkla 1.0 çıkıyordu.


---

## 📈 Skor İstatistikleri

| Metrik | Değer |
|--------|-------|
| Maksimum Normalize Skor | 1.0000 |
| Minimum Normalize Skor (Top 15) | 0.0334 |
| Ortalama Normalize Skor (Top 15) | 0.1986 |
