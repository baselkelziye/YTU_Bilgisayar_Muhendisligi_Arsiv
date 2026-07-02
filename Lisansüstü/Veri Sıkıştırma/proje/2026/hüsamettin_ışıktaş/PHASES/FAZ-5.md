# FAZ 5 - Ham Algoritma Performans Olcumu (Raw Benchmark)

Bu fazin amaci, projede kullandigimiz tum sikistirma algoritmalarinin ham halleriyle (profil secimi ve MLP olmadan) performansini olcmek ve Faz 4 adaptif sistemin gercek katkisini adil sekilde gostermektir.

## Faz Kapsami

- Huffman, LZW, Arithmetic, BWT+MTF, RLE+Huffman codec'lerinin ham benchmark'i
- Faz 4 adaptif sistem ile ayni test setinde birebir karsilastirma
- bpb, oran, hiz, dagilim ve kaynak kullanim metrikleri
- En iyi tek algoritma (best single codec) analizi

## Yapilacaklar

- Faz 4 ile ayni test kitaplarini benchmark seti olarak sabitle.
- Tum codec'leri profil/mapping kullanmadan tek tek calistir.
- Her kitap ve her algoritma icin su metrikleri kaydet:
  - bpb
  - compression ratio
  - compression time (ms/KB)
  - decompression time (ms/KB)
  - memory usage (mumkunse)
- Dagilim metriklerini hesapla: mean, median, p95, std.
- "En iyi tek algoritma"yi genel ortalama ve worst-case'e gore belirle.
- Faz 4 ciktilari ile ham benchmark sonuclarini yan yana karsilastir.
- Hangi tur/kitaplarda adaptif sistemin daha cok avantaj sagladigini raporla.

## Olusturulmasi Gereken Dosyalar

- `src/benchmark/run_raw_codecs.py`
  - Tum ham codec benchmark kosularini yurutur.
- `src/benchmark/collect_metrics.py`
  - Kitap bazli metrikleri standart formatta toplar.
- `src/benchmark/compare_with_adaptive.py`
  - Ham codec sonuclarini Faz 4 adaptif sonuclarla karsilastirir.
- `src/benchmark/select_best_single_codec.py`
  - En iyi tek algoritmayi secme mantigini uygular.
- `tests/test_benchmark_pipeline.py`
  - Benchmark pipeline'inin veri formati ve hesaplama dogrulugunu test eder.
- `artifacts/phase5/raw_codec_results.csv`
  - Her kitap x her codec detay metrikleri.
- `artifacts/phase5/raw_codec_results.parquet`
  - Analiz icin ayni verinin kolonlu/verimli formati.
- `artifacts/phase5/best_single_codec_summary.csv`
  - En iyi tek codec ozet tablosu.
- `artifacts/phase5/adaptive_vs_raw_comparison.csv`
  - Faz 4 adaptif sistem ile ham codec karsilastirmasi.
- `artifacts/phase5/raw_benchmark_report.md`
  - Teknik yorumlar ve nihai degerlendirme.

## Dosyalarin Amaclari

- `run_raw_codecs.py`: Ham algoritmalarin tarafsiz ve tekrar edilebilir kosumunu saglar.
- `collect_metrics.py`: Tum sonuclari tek formatta birlestirip analiz kolayligi sunar.
- `compare_with_adaptive.py`: Projenin adaptif yaklasimla ne kadar ek deger urettigini olcer.
- `best_single_codec_summary.csv`: "Adaptif sistem olmasa en iyi alternatif neydi?" sorusuna net cevap verir.
- `raw_benchmark_report.md`: Final rapor bolumlerine direkt tasinabilecek sonuc hikayesini olusturur.

## Faz Giris/Kabul Kriterleri

- Tum ham codec'ler ayni test setinde basariyla calistirilmis olmali.
- Sonuclar kitap bazli ve algoritma bazli detayda kaydedilmis olmali.
- En iyi tek codec secimi acik bir metodolojiyle yapilmis olmali.
- Faz 4'e karsi karsilastirma tablosu ve yorumlari tamamlanmis olmali.

## Faz Ciktilari

- Ham algoritmalarin performans tablolari
- En iyi tek algoritma analizi
- Adaptif sistemin net kazancini gosteren nihai benchmark raporu
