# FAZ 2 - Algoritma Eslestirme (Algorithm-to-Profile Matching)

Bu fazin amaci, her profil icin en uygun codec + parametre setini grid search ile secmek ve Faz 4'te O(1) lookup yapilabilecek bir mapping tablosu uretmektir.

## Faz Kapsami

- Aday codec implementasyonlari (Huffman, LZW, Arithmetic, BWT+MTF, RLE+Huffman)
- Profil bazli grid search
- bpb, oran ve hiz metrikleri ile secim
- Baseline (gzip/bzip2/lzma/zlib) karsilastirmasi
- Kalici profile mapping artefakti

## Yapilacaklar

- Faz 1'den gelen her profilin chunk setini yukle.
- Aday codec'ler icin parametre grid'lerini tanimla.
- Her `(profile, algorithm, parameter_set)` kombinasyonunu calistir.
- Ortalama bpb, medyan, p95 ve std degerlerini kaydet.
- Runtime metriklerini (ms/KB) kaydet.
- Her profil icin en iyi kombinasyonu sec:
  - Ana hedef minimum ortalama bpb
  - Esitlik durumunda daha hizli runtime lehine karar
- Baseline codec'lere karsi iyilesme yuzdelerini hesapla.
- Sonucu `profile_id -> (algorithm_id, parameter_set_id)` tablosu olarak disariya yaz.

## Olusturulmasi Gereken Dosyalar

- `src/codecs/huffman_codec.py`
  - Order-0/1 Huffman encoder/decoder.
- `src/codecs/lzw_codec.py`
  - Degisken sozluk boyutlu LZW encoder/decoder.
- `src/codecs/arithmetic_codec.py`
  - Order-0/1/2 arithmetic coder.
- `src/codecs/bwt_codec.py`
  - BWT + MTF + ikincil coder pipeline.
- `src/codecs/rle_codec.py`
  - RLE + Huffman hibrid codec.
- `src/matching/grid_search.py`
  - Profil bazli grid search orkestrasyonu.
- `src/matching/parameter_spaces.py`
  - Her codec icin parametre kombinasyonlari.
- `src/matching/profile_mapping.py`
  - En iyi kombinasyon secimi ve mapping tablo uretimi.
- `src/evaluation/baseline_compare.py`
  - gzip/bzip2/lzma/zlib karsilastirma metrikleri.
- `tests/test_codecs_roundtrip.py`
  - Tum codec'lerde lossless roundtrip testleri.
- `tests/test_grid_search.py`
  - Grid search secim mantigi ve stabilite testleri.
- `artifacts/phase2/grid_results.parquet`
  - Tum kombinasyonlarin detay metrik tablosu.
- `artifacts/phase2/profile_algorithm_mapping.json`
  - Faz 4 lookup tablosu (ana artefakt).
- `artifacts/phase2/profile_algorithm_mapping.csv`
  - Inceleme ve raporlama icin tablo formu.
- `artifacts/phase2/baseline_comparison.csv`
  - Profil bazli baseline iyilesme analizi.
- `artifacts/phase2/algorithm_selection_report.md`
  - Profil bazli secimlerin teknik gerekcesi.

## Dosyalarin Amaclari

- `src/codecs/*`: Projede kullanilacak klasik algoritmalarin kontrol edilebilir implementasyonu.
- `grid_search.py`: Tum kombinasyonlari sistematik ve tekrar edilebilir sekilde dener.
- `profile_algorithm_mapping.json`: Inference'ta profile gore codec seciminin tek kaynak dosyasidir.
- `baseline_compare.py`: Sonuclarin sadece kendi icinde degil, sektor standardlarina gore de degerlendirilmesini saglar.

## Faz Giris/Kabul Kriterleri

- Tum codec'ler roundtrip olarak kayipsiz calismali.
- Her profil icin secilen bir `(algorithm_id, parameter_set_id)` olmali.
- Mapping dosyasi Faz 4 tarafinda dogrudan kullanilabilir formatta olmali.
- Baseline karsilastirma sonuclari raporlanmis olmali.

## Faz Ciktilari

- Codec implementasyonlari
- Profil bazli en iyi algoritma/parametre tablosu
- Baseline karsilastirma raporu
