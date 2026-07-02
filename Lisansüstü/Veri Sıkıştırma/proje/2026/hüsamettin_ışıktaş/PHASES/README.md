# PHASES - Fazlar Arasi Bagimlilik ve Akis

Bu dosya, proje fazlarinin birbiriyle nasil baglandigini tek sayfada gostermek icin hazirlanmistir.

## Faz Dosyalari

- `FAZ-0.md`: Kurulum, veri toplama, temizleme, split
- `FAZ-1.md`: EDA, feature extraction, clustering, profil tanimlama
- `FAZ-2.md`: Profil -> en iyi algoritma/parametre eslestirme
- `FAZ-3.md`: Fast feature tabanli hafif MLP profil siniflandirici
- `FAZ-4.md`: Uctan uca sikistirma/dekompresyon + final degerlendirme
- `FAZ-5.md`: Ham codec benchmark ve adaptif sistemle adil karsilastirma

## Ust Seviye Akis

```text
FAZ 0
  Temizlenmis ve split edilmis kitaplar
        |
        v
FAZ 1
  Feature dataset + profile definitions + filtered dataset + final chunk size
        |
        +--------------------------+
        |                          |
        v                          v
FAZ 2                       FAZ 3
Profile->Algorithm map      Egitilmis MLP + scaler + label_map
        |                          |
        +-------------+------------+
                      |
                      v
                    FAZ 4
   Uctan uca adaptif sikistirma/dekompresyon + test raporlari
                      |
                      v
                    FAZ 5
   Ham codec benchmark + en iyi tek algoritma analizi + final karsilastirma
```

## Faz Bazli Girdi/Cikti Baglantilari

### 1) FAZ 0 -> FAZ 1

- **Faz 0 ciktilari**
  - `data/processed/manifest_clean.csv`
  - `data/processed/book_splits.csv`
  - `artifacts/phase0/data_quality_report.json`
  - `artifacts/phase0/split_summary.json`
  - `artifacts/phase0/env_check_report.json`
- **Faz 1 girdileri**
  - Temizlenmis kitap metinleri
  - Resmi split tablosu
  - Faz 0 kalite ve split raporlari

### 2) FAZ 1 -> FAZ 2

- **Faz 1 ciktilari**
  - `artifacts/phase1/profile_definitions.json`
  - `artifacts/phase1/filtered_dataset.parquet`
  - Final chunk size karari
- **Faz 2 girdileri**
  - Profil tanimlari
  - Profil bazli chunk veri setleri
  - Final chunk size

### 3) FAZ 1 -> FAZ 3

- **Faz 1 ciktilari**
  - `artifacts/phase1/filtered_dataset.parquet`
  - Set B (fast feature) kolonlari
  - `profile_id` etiketleri
- **Faz 3 girdileri**
  - Etiketli ve filtrelenmis egitim verisi

### 4) FAZ 2 + FAZ 3 -> FAZ 4

- **Faz 2 ciktilari**
  - `artifacts/phase2/profile_algorithm_mapping.json`
- **Faz 3 ciktilari**
  - `artifacts/phase3/model.pt`
  - `artifacts/phase3/scaler.pkl`
  - `artifacts/phase3/label_map.json`
- **Faz 4 girdileri**
  - Profil tahmin modeli + mapping tablosu + final chunk size

## Kritik Bagimliliklar (Must-Have)

- Faz 1 tamamlanmadan Faz 2 ve Faz 3 guvenilir sekilde baslatilmamali.
- Faz 2 mapping dosyasi olmadan Faz 4 codec secimi tamamlanamaz.
- Faz 3 model artefaktlari olmadan Faz 4 profile tahmini yapamaz.
- Final chunk size tek kaynak olarak Faz 1 kararindan alinmali; tum fazlar ayni degeri kullanmali.
- Faz 5 benchmark'i Faz 4 ile ayni test seti ve ayni kosullarda kosulmadan adil karsilastirma uretmez.

### 5) FAZ 4 -> FAZ 5

- **Faz 4 ciktilari**
  - `artifacts/phase4/test_results_per_book.csv`
  - `artifacts/phase4/baseline_comparison_summary.csv`
- **Faz 5 girdileri**
  - Faz 4 test sonuclari ve ayni test kitaplari

## Kisa Uygulama Sirasi

1. `FAZ-0.md` tamamla
2. `FAZ-1.md` tamamla
3. `FAZ-2.md` ve `FAZ-3.md` (paralel ilerleyebilir)
4. `FAZ-4.md` entegrasyon ve test degerlendirmesi
5. `FAZ-5.md` ham algoritma benchmark + nihai karsilastirma
