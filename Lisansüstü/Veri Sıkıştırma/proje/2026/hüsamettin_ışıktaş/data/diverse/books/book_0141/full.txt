# FAZ 1 - Data Exploration ve Profil Belirleme

Bu fazin amaci, chunk size secimi, ozellik muhendisligi, clustering ve profil tanimlarini veri destekli olarak netlestirmektir.

## Faz Kapsami

- Set A (23 feature) ve Set B (~10 hizli feature) extraction
- EDA experiment matrix kosumu
- Chunk size karar protokolu
- K-Means ile profil olusturma ve filtreleme
- Faz 2-4 icin resmi profil artefaktlarinin uretimi

## Yapilacaklar

- Set A offline feature extractor'u uygula:
  - Entropy, repetition, structural, compression signature, spectral ozellikler.
- Set B fast feature extractor'u uygula:
  - Tek gecisli histogram/sayac tabanli hizli ozellikler.
- Aday chunk size'lar (10/20/40/80/100KB) ve no-chunk baseline deneylerini calistir.
- Algoritma davranisi ve parametre hassasiyeti mini grid deneyleri yap.
- Korelasyon analizi, PCA, t-SNE/UMAP gorsellestirmeleri uret.
- K deger sweep (5,10,15,20,25,30) ile K-Means kalite metriklerini hesapla.
- Dusuk guvenli chunk'lari filtrele:
  - silhouette < 0.3, kucuk kume, aykiri uzaklik kosullari.
- Profil etiketleme mantigini olustur ve profilleri adlandir.
- Final chunk size kararini metrik dengesine gore dokumante et.

## Olusturulmasi Gereken Dosyalar

- `src/features/compression_features.py`
  - Set A icin 23 compression-aware feature hesaplayici.
- `src/features/fast_features.py`
  - Set B icin tek taramada hizli feature hesaplayici.
- `src/features/feature_pipeline.py`
  - Chunk'tan feature dataset ureten orkestrasyon modulu.
- `src/clustering/kmeans_profiles.py`
  - K-Means egitimi, profile_id atamasi ve merkezlerin saklanmasi.
- `src/clustering/cluster_filtering.py`
  - Silhouette/outlier/min-size filtreleme kurallari.
- `src/clustering/profile_labeling.py`
  - Kume merkezinden otomatik profil etiketi turetimi.
- `src/analysis/eda_experiments.py`
  - Chunk sweep, no-chunk, parameter sensitivity, ablation deneyleri.
- `src/analysis/chunk_size_decision.py`
  - Final chunk size kararini metriklerle veren karar modulu.
- `notebooks/phase1_eda.ipynb`
  - Dagilim, korelasyon, boyut indirgeme, deney sonuclari.
- `notebooks/phase1_cluster_analysis.ipynb`
  - Elbow, silhouette, profil yorumlama.
- `artifacts/phase1/features_set_a.parquet`
  - Tum chunk'larin Set A feature tablosu.
- `artifacts/phase1/features_set_b.parquet`
  - Tum chunk'larin Set B feature tablosu.
- `artifacts/phase1/correlation_matrix.csv`
  - Ozellikler arasi korelasyon matrisi.
- `artifacts/phase1/profile_definitions.json`
  - Profil id, etiket, merkez vektor, profil boyutu.
- `artifacts/phase1/filtered_dataset.parquet`
  - Yuksek guvenli profil etiketli egitim verisi.
- `artifacts/phase1/chunk_size_decision_report.md`
  - Secilen chunk size ve teknik gerekce.
- `artifacts/phase1/plots/*.png`
  - Histogram/KDE/boxplot/UMAP gibi gorseller.

## Dosyalarin Amaclari

- `compression_features.py` ve `fast_features.py`: Offline zengin analiz ile hizli inference ozelliklerini ayristirir.
- `kmeans_profiles.py` + `cluster_filtering.py`: Profil tanimlarinin guvenilir olmasini saglar.
- `profile_definitions.json`: Faz 2'de profile-gore grid search ve Faz 4'te lookup temeli olur.
- `filtered_dataset.parquet`: Faz 3 MLP egitimi icin temiz etiketli ana veri kaynagidir.
- `chunk_size_decision_report.md`: Sistemde sabitlenecek final blok boyutunun resmi kaydidir.

## Faz Giris/Kabul Kriterleri

- Final chunk size veriyle gerekcelendirilmeli.
- K secimi (profil sayisi) kalite metrikleriyle desteklenmeli.
- Dusuk guvenli chunk'lar filtrelenmis olmali.
- Profil tanimlari JSON olarak kalici uretilmeli.
- Faz 3 icin etiketli ve filtreli dataset hazir olmali.

## Faz Ciktilari

- EDA raporlari ve gorseller
- Final chunk size karari
- Profil tanimlari ve filtrelenmis etiketli dataset
