# Feature Selection Analiz Raporu

**Yöntem:** Gömülü Yöntem - Random Forest Feature Importance
**Veri Kümesi:** processed_dataset.csv
**Boyut:** (39644, 59)
**Kaynak:** UCI Online News Popularity
**Tarih:** 2025-12-28 14:54:04

---

## 📊 Genel Değerlendirme


Gömülü yöntem olarak **Random Forest (Rastgele Orman)** kullanılmıştır. 
Bu yöntem, ağaç tabanlı topluluk öğrenme algoritmasının özellik önem skorlarını kullanır.

### Yöntem Detayları:
- Random Forest, birden fazla karar ağacı eğitir
- Her özelliğin önemi, ağaçlardaki bölünmelere katkısına göre hesaplanır
- Gini impurity veya entropi azalması kullanılır
- Önem skorları 0-1 arasında normalize edilmiştir

### Model Parametreleri:
- **n_estimators:** 100 ağaç
- **max_depth:** Sınırsız
- **min_samples_split:** 2
- **min_samples_leaf:** 1

### Avantajları:
- Doğrusal olmayan ilişkileri yakalar
- Özellikler arası etkileşimleri dikkate alır
- Overfitting'e karşı dirençli
- Hızlı ve verimli

### Dezavantajları:
- Yorumlanabilirlik nispeten düşük
- Yüksek kardinaliteli kategorik değişkenler için yanlılık olabilir

### İstatistikler:
- İlk 15 özellik toplam önemin **%45.72**'sini oluşturmaktadır.


**Seçilen Özellik Sayısı:** 15

---

## Özellik Sıralaması

| Sıra | Özellik | Normalize Skor | Yorum |
|------|---------|----------------|-------|
| 1 | kw_avg_avg | 1.0000 | 🥇 En önemli özelliklerden |
| 2 | kw_max_avg | 0.9050 | 🥇 En önemli özelliklerden |
| 3 | LDA_02 | 0.7148 | 🥇 En önemli özelliklerden |
| 4 | self_reference_min_shares | 0.6990 | 🥈 Çok yüksek önem |
| 5 | kw_avg_min | 0.6577 | 🥈 Çok yüksek önem |
| 6 | kw_avg_max | 0.6545 | 🥉 Yüksek önem |
| 7 | LDA_01 | 0.6512 | 🥉 Yüksek önem |
| 8 | self_reference_avg_sharess | 0.6458 | 🥉 Yüksek önem |
| 9 | LDA_04 | 0.6436 | 🥉 Yüksek önem |
| 10 | LDA_00 | 0.6349 | 🥉 Yüksek önem |
| 11 | n_unique_tokens | 0.6079 | Orta-yüksek önem |
| 12 | global_subjectivity | 0.6057 | Orta-yüksek önem |
| 13 | n_non_stop_unique_tokens | 0.6015 | Orta-yüksek önem |
| 14 | average_token_length | 0.5954 | Orta-yüksek önem |
| 15 | LDA_03 | 0.5852 | Orta-yüksek önem |

---

## 📋 Seçilen Özellikler Listesi

Seçilen en iyi 15 özellik:

1. `kw_avg_avg`
2. `kw_max_avg`
3. `LDA_02`
4. `self_reference_min_shares`
5. `kw_avg_min`
6. `kw_avg_max`
7. `LDA_01`
8. `self_reference_avg_sharess`
9. `LDA_04`
10. `LDA_00`
11. `n_unique_tokens`
12. `global_subjectivity`
13. `n_non_stop_unique_tokens`
14. `average_token_length`
15. `LDA_03`

---

## 📝 Ek Notlar


Random Forest özellik önemi, her özelliğin karar ağaçlarındaki bölünmelere ne kadar 
katkı sağladığını gösterir. Bu yöntem, özellikle doğrusal olmayan ilişkileri ve 
özellikler arası etkileşimleri yakalamada etkilidir.

**Not:** Random Forest, ensemble (topluluk) öğrenme yöntemi olduğu için, özellik 
önemleri birden fazla modelin ortalamasıdır ve bu nedenle daha güvenilirdir.


---

## 📈 Skor İstatistikleri

| Metrik | Değer |
|--------|-------|
| Maksimum Normalize Skor | 1.0000 |
| Minimum Normalize Skor (Top 15) | 0.5852 |
| Ortalama Normalize Skor (Top 15) | 0.6801 |
