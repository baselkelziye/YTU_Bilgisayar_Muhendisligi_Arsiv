# Feature Selection Analiz Raporu

**Yöntem:** Filtreleme Yöntemi - Pearson Korelasyonu
**Veri Kümesi:** processed_dataset.csv
**Boyut:** (39644, 59)
**Kaynak:** UCI Online News Popularity
**Tarih:** 2025-12-28 14:52:12

---

## 📊 Genel Değerlendirme


Filtreleme yöntemi olarak **Pearson Korelasyonu** kullanılmıştır. Bu yöntem, her bir özellik ile 
hedef değişken (`is_popular`) arasındaki doğrusal ilişkiyi ölçer.

### Yöntem Detayları:
- Pearson korelasyon katsayısı -1 ile +1 arasında değer alır
- +1: Mükemmel pozitif korelasyon
- -1: Mükemmel negatif korelasyon  
- 0: Korelasyon yok

### Avantajları:
- Hesaplama açısından verimli
- Model bağımsız (filter method)
- Yorumlaması kolay

### Dezavantajları:
- Sadece doğrusal ilişkileri yakalar
- Özellikler arası etkileşimleri dikkate almaz


**Seçilen Özellik Sayısı:** 15

---

## Özellik Sıralaması

| Sıra | Özellik | Normalize Skor | Yorum |
|------|---------|----------------|-------|
| 1 | LDA_02 | 1.0000 | 🥇 En önemli özelliklerden |
| 2 | kw_avg_avg | 0.9868 | 🥇 En önemli özelliklerden |
| 3 | data_channel_is_world | 0.9643 | 🥇 En önemli özelliklerden |
| 4 | is_weekend | 0.8807 | 🥈 Çok yüksek önem |
| 5 | data_channel_is_entertainment | 0.7134 | 🥈 Çok yüksek önem |
| 6 | data_channel_is_socmed | 0.7002 | 🥉 Yüksek önem |
| 7 | weekday_is_saturday | 0.6807 | 🥉 Yüksek önem |
| 8 | data_channel_is_tech | 0.6424 | 🥉 Yüksek önem |
| 9 | LDA_04 | 0.5926 | 🥉 Yüksek önem |
| 10 | kw_min_avg | 0.5665 | 🥉 Yüksek önem |
| 11 | num_hrefs | 0.5635 | Orta-yüksek önem |
| 12 | weekday_is_sunday | 0.5237 | Orta-yüksek önem |
| 13 | LDA_01 | 0.4923 | Orta önem |
| 14 | global_sentiment_polarity | 0.4590 | Orta önem |
| 15 | num_keywords | 0.4561 | Orta önem |

---

## 📋 Seçilen Özellikler Listesi

Seçilen en iyi 15 özellik:

1. `LDA_02`
2. `kw_avg_avg`
3. `data_channel_is_world`
4. `is_weekend`
5. `data_channel_is_entertainment`
6. `data_channel_is_socmed`
7. `weekday_is_saturday`
8. `data_channel_is_tech`
9. `LDA_04`
10. `kw_min_avg`
11. `num_hrefs`
12. `weekday_is_sunday`
13. `LDA_01`
14. `global_sentiment_polarity`
15. `num_keywords`

---

## 📝 Ek Notlar


Bu analiz sonucunda, haberin popülerliği ile en yüksek korelasyona sahip özellikler genellikle:
- Anahtar kelime (keyword) ile ilgili metrikler
- Referans paylaşım sayıları
- LDA konu modeli özellikleri

gibi kategorilerden gelmektedir.


---

## 📈 Skor İstatistikleri

| Metrik | Değer |
|--------|-------|
| Maksimum Normalize Skor | 1.0000 |
| Minimum Normalize Skor (Top 15) | 0.4561 |
| Ortalama Normalize Skor (Top 15) | 0.6815 |
