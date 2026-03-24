# 📊 Lojistik Regresyon Performans Değerlendirme Raporu

**Tarih:** 2025-12-28 16:51:35
**Yöntem:** Lojistik Regresyon + K-Fold Cross Validation (K=5)
**Test Oranı:** %20

---

## 📈 Sonuç Tablosu

| Yöntem | Özellik Sayısı | Doğruluk (Accuracy) | F1-Skoru | Eğitim Süresi (s) |
|--------|----------------|---------------------|----------|-------------------|
| Tüm Özellikler | 58 | 0.6552 | 0.6544 | 0.4291 |
| Filtreleme (Pearson) | 15 | 0.6431 | 0.6413 | 0.0481 |
| Sarmalayıcı (RFE) ⭐ | 15 | 0.6510 | 0.6502 | 0.0992 |
| Gömülü (Random Forest) | 15 | 0.6278 | 0.6253 | 0.0546 |
| RFE Optimal (22 özellik) | 22 | 0.6563 | 0.6553 | 0.0000 |

> [!NOTE]
> En başarılı yöntem: **Sarmalayıcı (RFE)** (Accuracy: 0.6510, F1: 0.6502)

---

## 🎯 En Başarılı Yöntem Detayları

**Yöntem:** Sarmalayıcı (RFE)
**Özellik Sayısı:** 15
**Doğruluk:** 0.6510 (65.10%)
**F1-Skoru:** 0.6502

---

## ⚠️ Aşırı Öğrenme Analizi

- **Tüm Özellikler:** ✅ Tespit Edilmedi (Fark: 0.0023)
- **Filtreleme (Pearson):** ✅ Tespit Edilmedi (Fark: -0.0000)
- **Sarmalayıcı (RFE):** ✅ Tespit Edilmedi (Fark: 0.0006)
- **Gömülü (Random Forest):** ✅ Tespit Edilmedi (Fark: 0.0014)

---

## 📋 Karışıklık Matrisi (Sarmalayıcı (RFE))

|  | Tahmin: 0 | Tahmin: 1 |
|--|-----------|-----------|
| **Gerçek: 0** | 2217 (TN) | 1481 (FP) |
| **Gerçek: 1** | 1286 (FN) | 2945 (TP) |

**Açıklama:**
- TN (True Negative): Doğru tahmin edilen negatif örnekler
- FP (False Positive): Yanlış pozitif tahminler
- FN (False Negative): Yanlış negatif tahminler
- TP (True Positive): Doğru tahmin edilen pozitif örnekler
