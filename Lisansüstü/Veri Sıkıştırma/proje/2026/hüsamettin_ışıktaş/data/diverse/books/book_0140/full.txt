# FAZ 0 - Proje Kurulumu ve Veri Hazirlama

Bu fazin amaci, Faz 1'e gecmeden once ortami, veriyi ve izlenebilirlik artefaktlarini tek standarda baglayip tekrar edilebilir bir temel olusturmaktir.

## Faz Hedefleri

1. Python calisma ortamini tekrar edilebilir sekilde kurmak.
2. Gutenberg metinlerini indirip temizlenmis veri havuzu olusturmak.
3. Leakage-proof kitap seviyesinde `%70/%15/%15` split uretmek.
4. Faz 1'in zorunlu girdilerini tek kaynakli manifestler ile teslim etmek.
5. Ortam + veri + split dogrulama raporlarini uretmek.

## Operasyon Checklist

### A) Ortam ve Dizin Standardi

- [ ] `src/`, `data/`, `config/`, `scripts/`, `tests/`, `notebooks/`, `artifacts/` dizinlerini standartlastir.
- [ ] Python surumunu `3.10+` olarak sabitle.
- [ ] `venv` olusturma ve aktivasyon adimlarini dokumante et.
- [ ] `requirements.txt` ve `requirements-dev.txt` dosyalarini ayir.
- [ ] `scripts/check_env.py` ile surum/import/path kontrollerini raporla.

### B) Veri Toplama

- [ ] Gutenberg kaynaklarindan hedef kitap listesini indir.
- [ ] Minimum metadata kolonlarini kaydet: `book_id`, `title`, `author`, `language`, `source_url`, `download_timestamp`.
- [ ] Ham indirimi `data/raw/manifest_raw.csv` ile izlenebilir hale getir.

### C) Temizleme ve Kalite

- [ ] UTF-8 normalizasyonu uygula.
- [ ] Gutenberg header/footer bloklarini temizle.
- [ ] Whitespace ve satir sonu standardizasyonu uygula.
- [ ] Bos/asiri kisa/bozuk encoding kayitlarini `reject_reason` ile ayikla.
- [ ] Temiz ciktilari `data/processed/manifest_clean.csv` ile kaydet.

### D) Split ve Leakage Engeli

- [ ] Kitap seviyesinde `%70/%15/%15` split uygula.
- [ ] Ayni `book_id`'nin birden fazla split'te olmasini engelle.
- [ ] Seed kontrollu split kullan (`config/splits.yaml`).
- [ ] Split tablosunu `data/processed/book_splits.csv` olarak kaydet.
- [ ] Split ozeti icin kitap sayisi + byte dagilimini raporla.

### E) Test ve Dogrulama

- [ ] `tests/test_data_pipeline.py` ile temizlik ve split kurallarini test et.
- [ ] `check_env` sonucunu json rapor olarak sakla.
- [ ] Veri kalite ve split dogrulama raporlarini artefakt klasorune yaz.

## Olusturulmasi Gereken Kod ve Konfig Dosyalari

- `src/data/gutenberg_downloader.py`: ham kitap indirme ve metadata toplama.
- `src/data/clean_text.py`: UTF-8 normalizasyonu + header/footer temizligi.
- `src/data/split_books.py`: kitap seviyesinde deterministic split.
- `src/data/manifest.py`: ham/temiz/split manifest uretimi.
- `config/data_sources.yaml`: kaynak listesi, filtre kurallari, hedef kitap adedi.
- `config/splits.yaml`: split oranlari ve random seed ayarlari.
- `scripts/check_env.py`: ortam kontrol scripti.
- `tests/test_data_pipeline.py`: veri kalite ve split testleri.
- `README.md` veya `docs/setup.md`: kurulum ve ilk calistirma adimlari.

## Resmi Artefakt Sozlesmesi (Must-Have)

### Veri Manifestleri
- `data/raw/manifest_raw.csv`
- `data/processed/manifest_clean.csv`
- `data/processed/book_splits.csv`

### Faz 0 Raporlari
- `artifacts/phase0/data_quality_report.json`
- `artifacts/phase0/split_summary.json`
- `artifacts/phase0/env_check_report.json`

## Kalite Kontrol Matrisi

| Kontrol | Hata Kriteri | Aksiyon |
|---------|---------------|---------|
| Dosya varligi | Dosya okunamiyor | `reject` + log |
| Icerik uzunlugu | Esik alti | `reject_reason=too_short` |
| Encoding | UTF-8 parse hatasi | normalize dene, olmazsa reject |
| Duplicate kimlik | Ayni `book_id` tekrarli | tekillestir + log |
| Split sizintisi | Ayni kitap birden cok splitte | split tablosunu yeniden uret |

## Faz Giris/Kabul Kriterleri (Definition of Done)

- Temizlenmis kitap sayisi hedef aralikta (500-1000).
- Python ortami dokumandaki adimlarla tekrar kurulabilir.
- `scripts/check_env.py` basarili ve raporlanmis.
- `book_splits.csv` sizinti kontrolunden gecmis.
- Tum resmi manifestler uretilmis ve birbiriyle satir bazinda tutarli.
- `tests/test_data_pipeline.py` kritik kontrollerde basarili.
- Faz 1'in ihtiyac duydugu girisler (`clean manifest + split manifest + kalite raporu`) hazir.

## Faz Ciktilari

- Kurulumu dogrulanmis Python gelistirme ortami
- Temizlenmis ve split edilmis kitap koleksiyonu
- Veri pipeline kodu + konfig dosyalari
- Faz 1 icin resmi manifest ve kalite raporlari
