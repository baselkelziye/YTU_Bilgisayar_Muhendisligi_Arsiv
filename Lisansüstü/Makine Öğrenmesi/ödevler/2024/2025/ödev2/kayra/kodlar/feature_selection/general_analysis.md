# 🔬 Feature Selection Genel Analiz Raporu

**Tarih:** 2025-12-28
**Veri Kümesi:** Online News Popularity (UCI)
**Veri Boyutu:** 39,644 örnek × 59 özellik
**Hedef Değişken:** `is_popular` (binary)

---

## 📋 Kullanılan Yöntemler

| Yöntem Türü | Algoritma | Açıklama |
|-------------|-----------|----------|
| **Filtreleme** | Pearson Korelasyonu | Özellik-hedef arasındaki doğrusal ilişkiyi ölçer |
| **Sarmalayıcı** | RFE + Lojistik Regresyon | Özellik eliminasyonu ile en iyi alt kümeyi bulur |
| **Gömülü** | Random Forest Feature Importance | Ağaç tabanlı önem skorlarını kullanır |

---

## 📊 Normalize Skor İstatistikleri

| Yöntem | Min Skor | Max Skor | Ortalama Skor |
|--------|----------|----------|---------------|
| Filtreleme (Pearson) | 0.4561 | 1.0000 | 0.6815 |
| Sarmalayıcı (RFE) | 0.0334 | 1.0000 | 0.1986 |
| Gömülü (Random Forest) | 0.5852 | 1.0000 | 0.6801 |

> [!NOTE]
> Normalize skorlar 0-1 arasında ölçeklendirilmiştir. Her yöntem kendi skorlama mekanizmasına sahip olduğundan, yöntemler arası doğrudan karşılaştırma yapılmamalıdır.

---

## 🏆 Yöntemlere Göre Seçilen Özellikler

### Filtreleme Yöntemi (Pearson Korelasyonu)

| Sıra | Özellik | Normalize Skor |
|------|---------|----------------|
| 1 | LDA_02 | 1.0000 |
| 2 | kw_avg_avg | 0.9868 |
| 3 | data_channel_is_world | 0.9643 |
| 4 | is_weekend | 0.8807 |
| 5 | data_channel_is_entertainment | 0.7134 |
| 6 | data_channel_is_socmed | 0.7002 |
| 7 | weekday_is_saturday | 0.6807 |
| 8 | data_channel_is_tech | 0.6424 |
| 9 | LDA_04 | 0.5926 |
| 10 | kw_min_avg | 0.5665 |
| 11 | num_hrefs | 0.5635 |
| 12 | weekday_is_sunday | 0.5237 |
| 13 | LDA_01 | 0.4923 |
| 14 | global_sentiment_polarity | 0.4590 |
| 15 | num_keywords | 0.4561 |

---

### Sarmalayıcı Yöntem (RFE + Lojistik Regresyon)

| Sıra | Özellik | Normalize Skor |
|------|---------|----------------|
| 1 | n_non_stop_words | 1.0000 |
| 2 | n_non_stop_unique_tokens | 0.5507 |
| 3 | n_unique_tokens | 0.4451 |
| 4 | kw_avg_avg | 0.2902 |
| 5 | kw_max_avg | 0.1633 |
| 6 | data_channel_is_tech | 0.0900 |
| 7 | is_weekend | 0.0771 |
| 8 | LDA_00 | 0.0625 |
| 9 | data_channel_is_socmed | 0.0576 |
| 10 | kw_min_min | 0.0447 |
| 11 | kw_avg_max | 0.0438 |
| 12 | kw_min_avg | 0.0428 |
| 13 | kw_avg_min | 0.0415 |
| 14 | self_reference_avg_sharess | 0.0361 |
| 15 | kw_max_min | 0.0334 |

---

### Gömülü Yöntem (Random Forest)

| Sıra | Özellik | Normalize Skor |
|------|---------|----------------|
| 1 | kw_avg_avg | 1.0000 |
| 2 | kw_max_avg | 0.9050 |
| 3 | LDA_02 | 0.7148 |
| 4 | self_reference_min_shares | 0.6990 |
| 5 | kw_avg_min | 0.6577 |
| 6 | kw_avg_max | 0.6545 |
| 7 | LDA_01 | 0.6512 |
| 8 | self_reference_avg_sharess | 0.6458 |
| 9 | LDA_04 | 0.6436 |
| 10 | LDA_00 | 0.6349 |
| 11 | n_unique_tokens | 0.6079 |
| 12 | global_subjectivity | 0.6057 |
| 13 | n_non_stop_unique_tokens | 0.6015 |
| 14 | average_token_length | 0.5954 |
| 15 | LDA_03 | 0.5852 |

---

## 🔄 Yöntemler Arası Karşılaştırma

### Özellik Kesişim Analizi

```
                    Filtreleme    Sarmalayıcı    Gömülü
kw_avg_avg              ✅            ✅           ✅
is_weekend              ✅            ✅           ❌
data_channel_is_socmed  ✅            ✅           ❌
data_channel_is_tech    ✅            ✅           ❌
kw_min_avg              ✅            ✅           ❌
LDA_02                  ✅            ❌           ✅
LDA_04                  ✅            ❌           ✅
LDA_01                  ✅            ❌           ✅
n_unique_tokens         ❌            ✅           ✅
n_non_stop_unique_tokens❌            ✅           ✅
kw_max_avg              ❌            ✅           ✅
kw_avg_max              ❌            ✅           ✅
self_reference_avg_sharess ❌         ✅           ✅
LDA_00                  ❌            ✅           ✅
```

### Ortak Özellik Sayıları

| Karşılaştırma | Ortak Özellik Sayısı |
|---------------|---------------------|
| Filtreleme ∩ Sarmalayıcı | 5 |
| Filtreleme ∩ Gömülü | 5 |
| Sarmalayıcı ∩ Gömülü | 8 |
| **Üçü Ortak** | **1** (`kw_avg_avg`) |

---

## 🎯 En Önemli Özellikler

### Tüm Yöntemlerde Ortak Bulunan

| Özellik | Açıklama |
|---------|----------|
| **kw_avg_avg** | Anahtar kelimelerin ortalama paylaşım sayısı - **En tutarlı özellik** |

### İki Yöntemde Ortak Bulunan (Yüksek Güvenilirlik)

| Özellik | Yöntemler | Kategori |
|---------|-----------|----------|
| `LDA_02` | Filter, Embedded | Konu Modeli |
| `LDA_04` | Filter, Embedded | Konu Modeli |
| `LDA_01` | Filter, Embedded | Konu Modeli |
| `LDA_00` | Wrapper, Embedded | Konu Modeli |
| `is_weekend` | Filter, Wrapper | Zaman |
| `data_channel_is_tech` | Filter, Wrapper | Kanal |
| `data_channel_is_socmed` | Filter, Wrapper | Kanal |
| `kw_min_avg` | Filter, Wrapper | Anahtar Kelime |
| `kw_max_avg` | Wrapper, Embedded | Anahtar Kelime |
| `n_unique_tokens` | Wrapper, Embedded | Metin |
| `n_non_stop_unique_tokens` | Wrapper, Embedded | Metin |

---

## 📈 Özellik Kategorileri Analizi

### Kategori Dağılımı

| Kategori | Filtreleme | Sarmalayıcı | Gömülü | Toplam Görülme |
|----------|------------|-------------|--------|----------------|
| Anahtar Kelime (`kw_*`) | 2 | 7 | 4 | 13 |
| LDA Konu Modeli | 3 | 1 | 5 | 9 |
| Data Channel | 4 | 2 | 0 | 6 |
| Metin/Token | 0 | 3 | 4 | 7 |
| Zaman | 3 | 1 | 0 | 4 |
| Self Reference | 0 | 1 | 2 | 3 |
| Sentiment | 1 | 0 | 1 | 2 |
| Diğer | 2 | 0 | 1 | 3 |

> [!IMPORTANT]
> **Anahtar kelime özellikleri** tüm yöntemlerde en sık seçilen kategoridir. Bu, haberlerin popülerliğinde anahtar kelimelerin kritik öneme sahip olduğunu gösterir.

---

## 🔍 Yöntem Bazlı Değerlendirme

### Filtreleme Yöntemi (Pearson Korelasyonu)

**Güçlü Yanları:**
- Hesaplama açısından en verimli
- Model bağımsız
- Yorumlaması kolay

**Zayıf Yanları:**
- Sadece doğrusal ilişkileri yakalar
- Özellikler arası etkileşimleri dikkate almaz

**Öne Çıkan Kategoriler:** LDA, Data Channel, Zaman

---

### Sarmalayıcı Yöntem (RFE + Lojistik Regresyon)

**Güçlü Yanları:**
- Model performansını doğrudan optimize eder
- Özellik etkileşimlerini dikkate alır
- Sıralı eliminasyon

**Zayıf Yanları:**
- Hesaplama maliyeti yüksek
- Seçilen modele bağımlı

**Öne Çıkan Kategoriler:** Anahtar Kelime, Metin/Token

---

### Gömülü Yöntem (Random Forest)

**Güçlü Yanları:**
- Doğrusal olmayan ilişkileri yakalar
- Etkileşimleri dikkate alır
- Overfitting'e karşı dirençli

**Zayıf Yanları:**
- Yorumlanabilirlik düşük
- Kategorik değişkenlerde yanlılık olabilir

**Öne Çıkan Kategoriler:** Anahtar Kelime, LDA, Self Reference

---

## 📝 Sonuç ve Öneriler

### Genel Değerlendirme

1. **`kw_avg_avg` (Anahtar Kelime Ortalama Paylaşım)** üç yöntemde de seçilmiştir ve en güvenilir özellik olarak değerlendirilebilir.

2. **LDA konu modeli özellikleri** özellikle Filtreleme ve Gömülü yöntemlerde öne çıkmaktadır.

3. **Anahtar kelime ile ilgili özellikler** (`kw_*`) tüm yöntemlerde en çok seçilen kategoridir.

4. **Sarmalayıcı yöntem** daha farklı bir özellik kümesi seçmiştir; bu, Lojistik Regresyon'un doğrusal yapısından kaynaklanmaktadır.

### Model Seçimi Önerisi

| Kullanım Senaryosu | Önerilen Özellik Seti |
|--------------------|-----------------------|
| **Hızlı ve basit model** | Filtreleme yöntemi özellikleri |
| **Lojistik Regresyon kullanılacaksa** | Sarmalayıcı yöntemi özellikleri |
| **Ensemble modeller için** | Gömülü yöntemi özellikleri |
| **En güvenilir özellikler** | İki veya üç yöntemde ortak bulunanlar |

### Önerilen Evrensel Özellik Listesi

En az 2 yöntemde seçilen özelliklerden oluşan öneri listesi:

1. `kw_avg_avg` ⭐ (3/3)
2. `LDA_02` (2/3)
3. `LDA_04` (2/3)
4. `LDA_01` (2/3)
5. `LDA_00` (2/3)
6. `is_weekend` (2/3)
7. `data_channel_is_tech` (2/3)
8. `data_channel_is_socmed` (2/3)
9. `kw_min_avg` (2/3)
10. `kw_max_avg` (2/3)
11. `n_unique_tokens` (2/3)
12. `n_non_stop_unique_tokens` (2/3)


## 📁 İlgili Dosyalar

- [filter_analysis_report.md](./filter_analysis_report.md) - Filtreleme yöntemi detaylı raporu
- [wrapper_analysis_report.md](./wrapper_analysis_report.md) - Sarmalayıcı yöntemi detaylı raporu
- [embedded_analysis_report.md](./embedded_analysis_report.md) - Gömülü yöntemi detaylı raporu

