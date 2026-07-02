## Lightweight MLP Based Content-Aware Profile-Based Text Compression System

**Version:** 1.0  
**Date:** 2026-05-02  
**Status:** Draft  

---

## 1. Executive Summary

### 1.1 Problem Statement

Klasik metin sıkıştırma algoritmaları (Huffman, LZW, Aritmetik Kodlama, BWT) tüm metin türlerine **tek bir yaklaşımla** uygulanır. Ancak farklı metin türlerinin istatistiksel yapıları dramatik şekilde farklılık gösterir:

- **Teknik dokümanlar:** Yüksek tekrar oranı, standart terminoloji → LZW-benzeri algoritmalar verimli
- **Edebi betimlemeler:** Yüksek entropi, geniş kelime haznesi → Entropy coder'lar (Huffman, Aritmetik) verimli
- **Diyalog metinleri:** Kısa cümleler, tekrar eden kalıplar → Dictionary-based yöntemler verimli
- **Şiirsel metinler:** Ritmik tekrar, düşük kelime çeşitliliği → Özel modeller gerektirir

**Tek bir algoritma, tüm bu yapıları optimal şekilde sıkıştıramaz.** Bu durum, genel amaçlı sıkıştırıcıların (gzip, bzip2) potansiyelinin altında kalmasına neden olur.

### 1.2 Proposed Solution

Bu proje, metinlerin **sıkıştırma karakteristiklerine göre profillenmesini** ve her profile **en uygun klasik sıkıştırma algoritmasının** atanmasını hedefler. Sistem beş fazdan oluşur:

1. **Veri Keşfi ve Profil Belirleme:** Gutenberg korpusundaki metinler, sıkıştırma-odaklı özelliklerle analiz edilerek K-Means ile profillere ayrılır.
2. **Algoritma Eşleştirme:** Her profil için en verimli sıkıştırma algoritması ve parametreleri belirlenir.
3. **Hafif Profil Sınıflandırıcı Eğitimi:** K-Means profil etiketlerini tahmin eden 2-layer MLP, hızlı çıkarılabilen inference özellikleriyle eğitilir.
4. **Uçtan Uca Sıkıştırma:** Test metinleri, hızlı özellik çıkarımı + MLP ile profillendirilir ve ilgili algoritma-parametre çiftiyle blok bazında sıkıştırılır.
5. **Ham Algoritma Performans Fazı:** Tüm klasik codec'ler profil/mapping olmadan ham halleriyle çalıştırılır ve sistemin gerçek katkısı adil biçimde ölçülür.

### 1.3 Key Differentiators

| Özellik | Geleneksel Yaklaşım | Bu Proje |
|---------|-------------------|----------|
| Karar Kriteri | Dosya uzantısı / tek algoritma | İçerik-odaklı profil analizi |
| Kümeleme Uzayı | Anlamsal (e5, BERT) | Sıkıştırma-odaklı özellikler |
| Algoritma Seçimi | Statik | Profil bazlı dinamik |
| Öğrenme | Kural tabanlı | 2-layer MLP ile hızlı profil tahmini |
| Blok Seviyesi | Tek algoritma tüm dosya | Blok bazlı algoritma değişimi |

---

## 2. System Architecture

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         TRAINING PIPELINE                                   │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│   ┌─────────────┐    ┌──────────────────┐    ┌─────────────────────────┐    │
│   │  Gutenberg  │───▶│  Chunk (EDA'da  │───▶│  Compression-Aware     │    │
│   │  Corpus     │    │  seçilen boyut)  │    │  Feature Extraction     │    │
│   └─────────────┘    └──────────────────┘    └─────────────────────────┘    │
│                                                        │                    │
│                                                        ▼                    │
│                                              ┌──────────────────┐           │
│                                              │  K-Means Cluster │           │
│                                              │  (15-25 Profiles)│           │
│                                              └──────────────────┘           │
│                                                        │                    │
│                           ┌────────────────────────────┘                    │
│                           ▼                                                 │
│   ┌─────────────────────────────────────────────────────────────────────┐   │
│   │                    FAZ 2: ALGORITMA EŞLEŞTİRME                      │   │
│   │  Her profil için: Huffman, LZW, Aritmetik, BWT+MTF grid search      │   │
│   │  Sonuç: Profile → (Algorithm, Parameter Set) mapping tablosu        │   │
│   └─────────────────────────────────────────────────────────────────────┘   │
│                           │                                                 │
│                           ▼                                                 │
│   ┌─────────────────────────────────────────────────────────────────────┐   │
│   │                    FAZ 3: HAFİF MLP EĞİTİMİ                         │   │
│   │  Input: Fast inference features (~10 scalar feature)                │   │
│   │  Model: Linear(~10 → 32) + ReLU + Linear(32 → num_profiles)         │   │
│   │  Loss: Cross-Entropy (K-Means profile ID)                           │   │
│   └─────────────────────────────────────────────────────────────────────┘   │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘

┌─────────────────────────────────────────────────────────────────────────────┐
│                         INFERENCE PIPELINE                                  │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│   [Input Text]                                                              │
│       │                                                                     │
│       ▼                                                                     │
│   ┌─────────────────┐                                                       │
│   │ Final Chunk     │                                                       │
│   │ Size ile Bölme  │                                                       │
│   └─────────────────┘                                                       │
│       │                                                                     │
│       ▼                                                                     │
│   ┌─────────────────────────┐    ┌─────────────────────────────────────┐    │
│   │ Fast Feature Extractor  │───▶│  2-Layer MLP Classifier            │    │
│   │ (single pass over block)│    │  Profile ID + Confidence Score      │    │
│   └─────────────────────────┘    └─────────────────────────────────────┘    │
│       │                                                                     │
│       ▼                                                                     │
│   ┌─────────────────────────────────────────────────────────────────────┐   │
│   │  Algoritma Seçimi: Profile ID → (Algorithm, Parameter Set) Mapping  │   │
│   └─────────────────────────────────────────────────────────────────────┘   │
│       │                                                                     │
│       ▼                                                                     │
│   ┌─────────────────────────────────────────────────────────────────────┐   │
│   │  Blok Sıkıştırma + 4-Byte Header (Profile ID + Algo ID + Params)    │   │
│   └─────────────────────────────────────────────────────────────────────┘   │
│       │                                                                     │
│       ▼                                                                     │
│   [Output Bitstream]                                                        │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

---

## 3. Dataset Specification

### 3.1 Data Source

**Primary Source:** Project Gutenberg (https://www.gutenberg.org/)

| Özellik | Değer |
|---------|-------|
| Toplam Hedef Kitap | 500-1000 adet |
| Dil | İngilizce (UTF-8) |
| Dönem Aralığı | 1500-1920 (telif hakkı olmayan) |
| Tür Çeşitliliği | Roman, şiir, teknik, tarih, felsefe, drama |

**Yazar Seçimi Kriterleri:**
- Farklı dönemlerden (Rönesans, Viktorya, Modern)
- Farklı türlerden (edebiyat, bilim, tarih)
- Yeterli uzunlukta (minimum 200KB metin)
- Format: Düz metin (.txt), HTML tag'leri temizlenmiş

**Örnek Yazar Listesi:**
- William Shakespeare (Drama, Şiir)
- Charles Dickens (Roman)
- Jane Austen (Roman)
- Mark Twain (Roman, Hikaye)
- Isaac Newton (Teknik)
- Charles Darwin (Teknik)
- Edgar Allan Poe (Hikaye, Şiir)
- Oscar Wilde (Drama, Roman)
- Lewis Carroll (Çocuk Edebiyatı)
- Arthur Conan Doyle (Dedektif)

### 3.2 Train-Test-Validation Split Strategy

**Kritik Kural: Kitap Seviyesinde Bölme**

| Set | Oran | Bölme Kriteri |
|-----|------|---------------|
| **Training** | %70 | Rastgele seçilen 350-700 kitap |
| **Validation** | %15 | Training'den tamamen farklı kitaplar |
| **Test** | %15 | Training ve Validation'dan tamamen farklı kitaplar |

**Neden kitap seviyesinde?**
- Aynı kitabın farklı bölümleri benzer stilistik özelliklere sahiptir.
- Chunk seviyesinde rastgele bölme, "data leakage" (bilgi sızıntısı) yaratır.
- Modelin gerçekten **görmediği kitaplara** genelleme yapması test edilmelidir.

**Chunk Üretim Stratejisi:**
```
Kitap (örn. 500KB)
    │
    ├── Chunk 1: Byte 0-(N-1)
    ├── Chunk 2: Byte N-(2N-1)
    ├── Chunk 3: Byte 2N-(3N-1)
    └── ... (overlap yok, ardışık)
```

`N`, Faz 1 EDA'da seçilecek final chunk size'dır. İlk aday değer 40KB'dir.

### 3.3 Chunk Size Exploration Rationale

**Başlangıç Hipotezi: 40KB (40,960 bytes)**

Chunk size nihai olarak baştan sabitlenmeyecektir. 40KB, LZW/BWT/Huffman davranışları açısından makul başlangıç hipotezidir; ancak Faz 1 EDA'da farklı chunk size'lar ve hiç bölmeden sıkıştırma senaryosu sistematik olarak test edildikten sonra final değer seçilecektir.

| Alternatif | Beklenen Davranış | EDA Kararı |
|-----------|---------------|-------|
| 10KB | BWT için küçük olabilir, LZW sözlüğü dolmadan bitebilir | Test edilecek |
| 20KB | LZW için yeterli olabilir, BWT verimi sınırlı kalabilir | Test edilecek |
| **40KB** | LZW sözlüğü iyi dolabilir, BWT anlamlı sıralama yapabilir, Huffman frekans tablosu kararlı olabilir | Ana aday |
| 80KB / 100KB | Sıkıştırma oranı artabilir, BWT maliyeti ve adaptasyon gecikmesi büyüyebilir | Test edilecek |
| Tüm kitap / bölmeden | Header yok, global istatistik avantajı var; ancak blok bazlı adaptasyon yok | Baseline olarak test edilecek |

**40KB Hipotezinin Gerekçesi:**
1. **LZW:** 12-bit kodlarla 4096 girdilik sözlük, ~40KB veride optimal dolma oranına ulaşır.
2. **BWT:** Blok sıralaması için yeterli tekrar kalıbı yakalanır.
3. **Huffman:** Karakter frekans dağılımı istatistiksel olarak kararlı hale gelir.
4. **Header Overhead:** 4 byte header / 40KB blok = %0.0097 overhead (ihmal edilebilir).

**Nihai karar metriği:** Chunk size; ortalama bpb, compression time, decompression time, header overhead, profil tahmin stabilitesi ve algoritmalar arası ayrışma birlikte değerlendirilerek seçilecektir.

### 3.4 Phase 0: Eksiksiz Kurulum ve Veri Hazirlama (Master Spec)

Bu alt bölüm, Faz 0'in sonraki fazlara gecerken tek kaynak kabul edilen resmi kapsam tanimini verir.

#### 3.4.1 Faz 0 Hedefleri

1. Tekrarlanabilir Python gelistirme ortami kurmak.
2. Gutenberg kaynagindan ham metinleri standart sekilde indirmek.
3. Metinleri temizleyip kalite kontrollerinden gecirmek.
4. Kitap seviyesinde sizintisiz `%70/%15/%15` split uretmek.
5. Faz 1'in dogrudan tuketecegi resmi manifest ve rapor artefaktlarini cikarmak.

#### 3.4.2 Dizin ve Modul Standardi

| Alan | Zorunlu Icerik |
|------|-----------------|
| `src/data/` | `gutenberg_downloader.py`, `clean_text.py`, `split_books.py`, `manifest.py` |
| `config/` | `data_sources.yaml`, `splits.yaml` |
| `scripts/` | `check_env.py` |
| `data/raw/` | Ham metinler + `manifest_raw.csv` |
| `data/processed/` | Temiz metinler + `manifest_clean.csv` + `book_splits.csv` |
| `artifacts/phase0/` | Faz 0 kalite ve ortam raporlari |
| `tests/` | `test_data_pipeline.py` |

#### 3.4.3 Ortam Kurulum ve Dogrulama

- Python surumu: `3.10+` (tek kaynak referans).
- Sanal ortam: `venv`.
- Bagimlilik dosyalari:
  - `requirements.txt` (runtime)
  - `requirements-dev.txt` (test/lint/notebook)
- `scripts/check_env.py` su kontrolleri raporlamalidir:
  - Python surumu uyumu
  - zorunlu paket import testi
  - proje path/dizin ulasilabilirligi
  - sonuc ozeti (`pass`/`fail`) + hata listesi

#### 3.4.4 Veri Toplama ve Temizleme Kurallari

**Veri Toplama**
- Kaynak: Project Gutenberg (plain text odakli).
- Her kitap icin minimum metadata:
  - `book_id`
  - `title`
  - `author`
  - `language`
  - `source_url`
  - `download_timestamp`

**Temizleme**
- UTF-8 normalizasyonu uygula.
- Gutenberg header/footer bolumlerini temizle.
- Satir sonu/whitespace standardizasyonu uygula.
- Bos veya asiri kisa kitaplari ele.
- Bozuk encoding dosyalarini `reject_reason` ile kaydet.

#### 3.4.5 Split Politikasi (Leakage-Proof)

| Set | Oran | Kural |
|-----|------|-------|
| Train | %70 | Tam kitap bazli atama |
| Validation | %15 | Train kitaplariyla kesisim yasak |
| Test | %15 | Train/Validation ile kesisim yasak |

**Zorunlu kurallar:**
1. Ayni `book_id` birden fazla split'te olamaz.
2. Split atamasi seed kontrollu olmalidir (`config/splits.yaml`).
3. Split raporu kitap sayisi + byte dagilimini birlikte vermelidir.

#### 3.4.6 Manifest Sozlesmesi

**`data/raw/manifest_raw.csv`**
- Ham indirme durumunu ve kaynak metadatasini tutar.

**`data/processed/manifest_clean.csv`**
- Temizlikten gecen kitaplari, kalite bayraklarini ve temiz dosya yollarini tutar.

**`data/processed/book_splits.csv`**
- Resmi split tablosudur; Faz 1 bu dosyayi tek dogru kaynak olarak kullanir.

#### 3.4.7 Faz 0 Cikti Artefaktlari (Must-Have)

- `data/raw/manifest_raw.csv`
- `data/processed/manifest_clean.csv`
- `data/processed/book_splits.csv`
- `artifacts/phase0/data_quality_report.json`
- `artifacts/phase0/split_summary.json`
- `artifacts/phase0/env_check_report.json`

#### 3.4.8 Veri Kalite Kontrol Matrisi

| Kontrol | Hata Kriteri | Aksiyon |
|---------|---------------|---------|
| Dosya varligi | Dosya okunamiyor | `reject` + log |
| Icerik uzunlugu | Esik altinda | `reject` + manifest nedeni |
| Encoding | UTF-8 parse hatasi | normalize dene, olmazsa `reject` |
| Duplicate kimlik | Ayni `book_id` birden fazla kayit | birlestir/tekilleştir + log |
| Split sizintisi | Ayni kitap birden cok splitte | split tablosu yeniden olustur |

#### 3.4.9 Faz 0 Definition of Done (Gate to Phase 1)

- Hedef aralikta (500-1000) temizlenmis kitap mevcut.
- `check_env` raporu basarili.
- `book_splits.csv` sizinti testi basarili.
- Tum zorunlu manifest dosyalari uretildi ve satir sayilari tutarli.
- `tests/test_data_pipeline.py` tum kritik kontrollerde basarili.
- Faz 1 girisi icin gerekli dosyalar tek path sozlesmesiyle hazir.

---

## 4. Phase 1: Data Exploration & Profile Determination

### 4.1 Feature Extraction Strategy

Sistem iki ayrı feature set kullanacaktır. Amaç, offline analizde zengin ve pahalı özelliklerden yararlanırken inference aşamasında her blok için yalnızca tek taramada çıkarılabilen hızlı özellikleri kullanmaktır.

| Set | Adı | Özellikler | Kullanım Yeri |
|-----|-----|------------|---------------|
| **A** | Offline Clustering Features | 23 compression-aware feature'ın tamamı | Sadece Faz 1 K-Means clustering ve EDA |
| **B** | Fast Inference Features | ~10 hızlı scalar feature | Faz 3 MLP eğitimi ve Faz 4 blok bazlı inference |

**Kritik ayrım:** LZW/BWT/Huffman test bpb gibi compression signature özellikleri inference'da çalıştırılmayacaktır. Bu özellikler bloğu sıkıştırmadan önce tekrar sıkıştırma maliyeti doğuracağı için yalnızca offline profil keşfinde kullanılacaktır.

#### 4.1.1 Offline Clustering Features (Set A)

Her aday/final chunk için aşağıdaki 23 özellik çıkarılacaktır:

##### 4.1.1.1 Entropy Metrics (4 features)

| Özellik | Açıklama | Hesaplama |
|---------|----------|-----------|
| `char_entropy` | Karakter-level Shannon entropisi | H(X) = -Σ p(x) log₂ p(x) |
| `byte_entropy` | Byte-level entropisi (256 sembol) | H(X) = -Σ p(x) log₂ p(x) |
| `bigram_entropy` | Bigram koşullu entropisi | H(X₂\|X₁) = H(X₁,X₂) - H(X₁) |
| `trigram_entropy` | Trigram koşullu entropisi | H(X₃\|X₁,X₂) = H(X₁,X₂,X₃) - H(X₁,X₂) |

##### 4.1.1.2 Repetition Statistics (5 features)

| Özellik | Açıklama |
|---------|----------|
| `lz77_avg_match` | LZ77 sliding window ile ortalama eşleşme uzunluğu (pencere: 32KB) |
| `repeat_word_ratio` | Tekrar eden kelimelerin toplam kelime sayısına oranı |
| `top10_word_freq` | En sık 10 kelimenin toplam frekansı (%) |
| `avg_run_length` | Aynı karakterin ardışık tekrar ortalaması (RLE potansiyeli) |
| `unique_word_ratio` | Benzersiz kelime sayısı / toplam kelime sayısı |

##### 4.1.1.3 Structural Metrics (6 features)

| Özellik | Açıklama |
|---------|----------|
| `avg_word_length` | Ortalama kelime uzunluğu (karakter) |
| `avg_sentence_length` | Ortalama cümle uzunluğu (kelime) |
| `punctuation_ratio` | Noktalama işareti oranı |
| `uppercase_ratio` | Büyük harf oranı |
| `digit_ratio` | Rakam oranı |
| `newline_ratio` | Satır sonu karakteri oranı |

##### 4.1.1.4 Compression Signature (5 features, offline only)

| Özellik | Açıklama |
|---------|----------|
| `huffman_bpb` | Order-0 Huffman ile bit/byte oranı |
| `lzw_bpb` | LZW (dict=65536) ile bit/byte oranı |
| `arithmetic_bpb` | Order-0 Aritmetik kodlama ile bit/byte oranı |
| `bwt_bpb` | BWT + MTF + Aritmetik ile bit/byte oranı |
| `rle_effectiveness` | RLE ile sıkıştırma oranı (uzun tekrarlar varsa düşük) |

Bu metrikler EDA ve K-Means için çok değerlidir çünkü hangi profilin hangi algoritmaya yatkın olduğunu gösterir. Ancak inference pipeline'ında kullanılmaz; LZW/BWT testleri gerçek sıkıştırma işleminden önce fazladan sıkıştırma maliyeti yaratır.

##### 4.1.1.5 Spectral Features (3 features)

| Özellik | Açıklama |
|---------|----------|
| `char_freq_variance` | Karakter frekans dağılımının varyansı |
| `zipf_alpha` | Kelime frekanslarının Zipf dağılımı eğimi |
| `entropy_gradient` | Metin boyunca entropi değişimi (homojenlik göstergesi) |

**Set A Toplam Feature Vektör Boyutu: 23 features**

#### 4.1.2 Fast Inference Features (Set B)

Faz 3 ve Faz 4 için her bloktan tek `for` loop ile çıkarılacak hızlı özellikler:

| Özellik | Açıklama | Hesaplama Notu |
|---------|----------|----------------|
| `byte_entropy` | Byte-level Shannon entropisi | 256 sayaçlık byte histogramından |
| `byte_freq_variance` | Byte frekans dağılımı varyansı | Aynı histogramdan |
| `unique_byte_ratio` | Görülen byte sayısı / 256 | Aynı histogramdan |
| `newline_ratio` | `\n` karakter oranı | Tek taramada sayaç |
| `space_ratio` | Boşluk karakteri oranı | Tek taramada sayaç |
| `uppercase_ratio` | Büyük harf oranı | ASCII aralığı kontrolü |
| `digit_ratio` | Rakam oranı | ASCII aralığı kontrolü |
| `punctuation_ratio` | Noktalama oranı | ASCII punctuation kontrolü |
| `avg_word_length` | Ortalama kelime uzunluğu | Whitespace geçişleriyle |
| `avg_run_length` | Ardışık aynı byte tekrar ortalaması | Önceki byte takibiyle |

Byte histogramı entropy ve dağılım istatistikleri için ara sayaç olarak tutulur; MLP input'u normalize edilmiş yaklaşık 10 scalar feature'dan oluşur. Böylece profil tahmini, sıkıştırma algoritmalarını denemeden O(n) tek tarama + küçük MLP forward pass maliyetine iner.

### 4.2 Exploratory Data Analysis (EDA) Pipeline

#### 4.2.1 Dağılım Analizi

Her özellik için aşağıdaki görselleştirmeler üretilecektir:

1. **Histogramlar:** Her özelliğin corpus genelindeki dağılımı
2. **KDE (Kernel Density Estimate) Plotları:** Yazar bazında özellik dağılımları
3. **Box Plotları:** Tür bazında (roman, şiir, teknik) karşılaştırma
4. **Violin Plotları:** Chunk'ların özellik dağılım şekilleri

#### 4.2.2 Korelasyon Analizi

```
23×23 Korelasyon Matrisi (Pearson)
    │
    ├── Yüksek korelasyonlu çiftler (>0.9) belirlenir
    ├── Çok yüksek korelasyonlu özelliklerden biri çıkarılır
    └── Sonuç: ~18-20 bağımsız özellik
```

#### 4.2.3 Boyut İndirgeme ve Görselleştirme

| Teknik | Amaç |
|--------|------|
| PCA | Varyansın hangi bileşenlerde toplandığını görmek |
| t-SNE | 2D/3D görselleştirme, doğal kümeleri tespit |
| UMAP | Daha iyi yerel yapı koruma, kümeleri ayırt etme |

#### 4.2.4 EDA Experiment Matrix

EDA aşaması yalnızca görselleştirme üretmeyecek; sistemde değişken olan her önemli tasarım kararını küçük ölçekli deneylerle ölçecektir. Bu deneylerin amacı, Faz 2-4'e geçmeden önce chunk size, profil sayısı, feature set ve algoritma davranışları için veri destekli karar vermektir.

| Deney Grubu | Değişkenler | Ölçülecek Metrikler | Karar Sorusu |
|-------------|-------------|---------------------|--------------|
| **Chunk Size Sweep** | 10KB, 20KB, 40KB, 80KB, 100KB | bpb, ms/KB, header overhead, algoritma sıralaması | Blok boyutu büyüdükçe hangi algoritmalar güçleniyor/zayıflıyor? |
| **No-Chunk Baseline** | Tüm kitap tek blok, bölüm bazlı blok, 40KB blok | bpb, compression time, memory usage | Hiç bölmeseydik ne kadar iyi/kötü sıkıştırırdık? |
| **Algorithm Behavior by Size** | Huffman, LZW, Arithmetic, BWT+MTF, RLE+Huffman × chunk size | Algoritma başına bpb/time eğrileri | Algoritmalar hangi blok boyutlarında avantajlı? |
| **Parameter Sensitivity** | LZW dict size, arithmetic context order, BWT secondary coder, RLE threshold | bpb değişimi, runtime değişimi | Parametre değişimi gerçekten anlamlı fark yaratıyor mu? |
| **Feature Set Ablation** | Set A full, Set A minus compression signature, Set B fast-only | Silhouette, cluster purity, profile separability | Pahalı feature'lar clustering'e ne kadar katkı sağlıyor? |
| **Profile Count Sweep** | K = 5, 10, 15, 20, 25, 30 | Silhouette, Davies-Bouldin, profil başına en iyi algoritma farkı | Kaç profil hem anlamlı hem yeterince ayrıştırıcı? |
| **Split Strategy Check** | Kitap-level split, chunk-level split simülasyonu | validation/test farkı, leakage göstergesi | Kitap bazlı split'in etkisi ve leakage riski ne kadar? |
| **Genre/Author Robustness** | Tür, dönem, yazar grupları | bpb dağılımı, profil dağılımı | Profiller sadece yazar/tür ezberliyor mu? |
| **Fast Feature Predictiveness** | Set B feature'ları tek tek ve birlikte | MLP accuracy, macro F1, inference time | Hızlı feature'lar profil tahmini için yeterli mi? |

Her deneyde en azından `mean`, `median`, `p95`, `std` değerleri raporlanacaktır. EDA çıktılarında yalnızca en iyi ortalamaya değil, en kötü durum davranışına ve runtime maliyetine de bakılacaktır.

#### 4.2.5 Chunk Size Decision Protocol

```
Her aday chunk size için:
    │
    ├── Aynı train subset üzerinde chunk üret
    ├── Set A offline feature'ları çıkar
    ├── Aday algoritmaları ve parametreleri küçük grid ile çalıştır
    ├── bpb/time/header overhead değerlerini kaydet
    ├── K-Means profil kalitesini ölç
    └── Fast feature'larla profil tahmin edilebilirliğini test et

No-chunk baseline:
    │
    ├── Kitabı tek blok olarak sıkıştır
    ├── Bölüm bazlı veya büyük blok alternatifiyle karşılaştır
    └── Blok bazlı adaptasyonun getirisini/zararını ölç
```

**Final chunk size seçimi**, yalnızca en iyi compression ratio'ya göre değil, şu dengeye göre yapılacaktır:

1. Ortalama bpb ve gzip/bzip2/lzma baseline'larına göre iyileştirme
2. Compression/decompression speed
3. Header overhead
4. BWT gibi pahalı algoritmaların runtime maliyeti
5. Profil kümelerinin ayrışabilirliği
6. MLP'nin fast feature'larla profil tahmin doğruluğu

### 4.3 Profile (Cluster) Determination

#### 4.3.1 Clustering Methodology

**Algoritma:** K-Means (sklearn)

**Neden K-Means?**
- Hızlı ve ölçeklenebilir (10.000+ chunk için)
- Küme merkezleri anlamlı "profil prototipleri" olarak yorumlanabilir
- Yeni chunk'ların küme merkezlerine uzaklığı kolay hesaplanır

**K Değerinin Belirlenmesi:**

| Metrik | Amaç | Hedef |
|--------|------|-------|
| Elbow Method | WCSS (Within-Cluster Sum of Squares) grafiğinde dirsek noktası | K = 15-25 arası |
| Silhouette Score | Küme içi benzerlik / kümeler arası fark | Score > 0.5 |
| Davies-Bouldin Index | Kümeler arası uzaklık / içi yoğunluk | Düşük değer |
| Calinski-Harabasz Index | Varyans oranı | Yüksek değer |

**K Değeri Seçimi Süreci:**
```
K = 5, 10, 15, 20, 25, 30 için K-Means çalıştır
    │
    ├── Her K için Silhouette Score hesapla
    ├── Her K için Elbow Method grafiği çiz
    └── En iyi K'yı seç (genellikle 15-20 arası)
```

#### 4.3.2 Cluster Quality Filtering

**Sert Filtreleme Kriterleri:**

1. **Silhouette Score Filtresi:**
   - Her chunk'ın kendi kümesindeki silhouette score'u hesaplanır.
   - Score < 0.3 olan chunk'lar "belirsiz" olarak işaretlenir.
   - Belirsiz chunk'lar **hiçbir profile atanmaz** ve training setinden çıkarılır.

2. **Küme Boyutu Filtresi:**
   - Minimum küme boyutu: 50 chunk (istatistiksel güvenilirlik için)
   - 50'den az chunk içeren kümeler birleştirilir veya atılır.

3. **Küme Yoğunluğu Filtresi:**
   - Her kümenin ortalama merkeze uzaklığı hesaplanır.
   - Uzaklık > 2σ olan chunk'lar aykırı değer olarak işaretlenir.

**Sonuç:** Sadece **yüksek güvenle** atanan chunk'lar profile dahil edilir.

#### 4.3.3 Profile Labeling

Her küme, merkezindeki chunk'ların özelliklerine göre otomatik etiketlenir:

```python
# Örnek etiketleme mantığı
def label_profile(cluster_center):
    if cluster_center['lz77_avg_match'] > 10 and cluster_center['char_entropy'] < 4.5:
        return "HIGH_REPETITION"  # Teknik, diyalog
    elif cluster_center['char_entropy'] > 5.5 and cluster_center['unique_word_ratio'] > 0.4:
        return "HIGH_ENTROPY"  # Betimleyici edebiyat
    elif cluster_center['avg_run_length'] > 3:
        return "RLE_FRIENDLY"  # Tablo, liste
    elif cluster_center['punctuation_ratio'] > 0.15:
        return "DIALOG_HEAVY"  # Drama, diyalog
    else:
        return "BALANCED"
```

### 4.4 EDA Deliverables

| Çıktı | Format | İçerik |
|-------|--------|--------|
| Feature Distribution Report | Jupyter Notebook + PDF | Set A ve Set B özelliklerinin histogram, KDE, box plotları |
| Correlation Matrix | Heatmap (PNG) + CSV | 23×23 korelasyon matrisi |
| Cluster Analysis Report | Jupyter Notebook + PDF | Elbow, Silhouette, t-SNE/UMAP görselleştirmeleri |
| EDA Experiment Matrix Report | Jupyter Notebook + PDF | Chunk size, no-chunk baseline, algoritma davranışı, parametre hassasiyeti ve feature ablation sonuçları |
| Chunk Size Decision Report | PDF + CSV | Final chunk size seçimi ve gerekçesi |
| Profile Definitions | JSON | Her profilin ID, etiket, merkez vektörü, boyutu |
| Filtered Dataset | Parquet | Sadece yüksek güvenli chunk'lar ve profil etiketleri |
| Compression Signature Report | Jupyter Notebook + PDF | LZW/BWT/Huffman bpb plotları, yalnızca offline analiz olarak işaretlenmiş |

---

## 5. Phase 2: Algorithm-to-Profile Matching

### 5.1 Candidate Algorithms

Her profil için aşağıdaki algoritmalar ve parametre varyasyonları test edilecektir:

#### 5.1.1 Huffman Coding

| Parametre | Değerler |
|-----------|----------|
| Context Order | 0 (byte-level), 1 (1-byte context) |
| Block Size | Faz 1 EDA ile seçilen final chunk size |
| Adaptive | Statik (tek frekans tablosu) |

#### 5.1.2 LZW (Lempel-Ziv-Welch)

| Parametre | Değerler |
|-----------|----------|
| Dictionary Size | 4096 (12-bit), 16384 (14-bit), 65536 (16-bit) |
| Code Size | Fixed (sabit kod boyutu) |
| Reset Strategy | None (sözlük dolana kadar) |

#### 5.1.3 Arithmetic Coding

| Parametre | Değerler |
|-----------|----------|
| Context Order | 0, 1, 2 |
| Adaptation Rate | Fast, Slow |
| Model Type | Fixed, Adaptive |

#### 5.1.4 BWT + MTF + Arithmetic

| Parametre | Değerler |
|-----------|----------|
| Block Size | Faz 1 EDA ile seçilen final chunk size |
| MTF Variant | Standard MTF, Run-Length MTF |
| Secondary Coder | Arithmetic, Huffman |

#### 5.1.5 RLE + Huffman (Hibrit)

| Parametre | Değerler |
|-----------|----------|
| RLE Threshold | Min 3, Min 4 tekrar |
| Encoding | RLE sonrası Huffman |

### 5.2 Grid Search Strategy

```
Her Profil İçin:
    │
    ├── Profildeki tüm chunk'ları al (~50-500 chunk)
    │
    ├── Her algoritma-parametre kombinasyonu için:
    │   ├── Her chunk'ı sıkıştır
    │   ├── Bit/byte (bpb) oranını kaydet
    │   └── Sıkıştırma süresini kaydet
    │
    └── En düşük ortalama bpb veren algoritma-parametre kombinasyonunu seç
        └── Sonuç: Profile → (Algorithm, Parameters, Parameter_Set_ID, Expected_bpb)
```

Grid search çıktısı yalnızca "hangi algoritma?" sorusunu değil, "hangi algoritma + hangi parametre seti?" kararını da kalıcı olarak kaydeder. Faz 4'te MLP sadece `profile_id` tahmin eder; algoritma ve parametre seçimi `profile_id → (algorithm_id, parameter_set_id)` lookup table ile O(1) yapılır.

### 5.3 Performance Metrics

| Metrik | Tanım | Hedef |
|--------|-------|-------|
| **bpb (bits per byte)** | Sıkıştırılmış boyut (bit) / Orijinal boyut (byte) | Minimum |
| **Compression Ratio** | Orijinal / Sıkıştırılmış | Maksimum |
| **Space Saving** | (1 - Sıkıştırılmış/Orijinal) × 100 | Maksimum |
| **Compression Time** | ms/KB | Profil bazında kabul edilebilir |

### 5.4 Baseline Comparison

Her profil için seçilen algoritma, aşağıdaki baseline'larla karşılaştırılacaktır:

| Baseline | Açıklama |
|----------|----------|
| gzip -9 | Deflate (LZ77 + Huffman), seviye 9 |
| bzip2 -9 | BWT + MTF + Huffman |
| lzma -9 | LZMA (LZ77 + range coder) |
| zlib -6 | Deflate, default seviye |

### 5.5 Algorithm Mapping Table Output

```json
{
  "profile_mapping": {
    "P00_HIGH_REPETITION": {
      "algorithm": "LZW",
      "algorithm_id": 1,
      "parameters": {"dict_size": 65536, "code_size": 16},
      "parameter_set_id": 3,
      "expected_bpb": 3.15,
      "vs_gzip_improvement": "+12%"
    },
    "P01_HIGH_ENTROPY": {
      "algorithm": "ARITHMETIC",
      "algorithm_id": 2,
      "parameters": {"context_order": 2, "adaptation": "slow"},
      "parameter_set_id": 5,
      "expected_bpb": 4.82,
      "vs_gzip_improvement": "+8%"
    },
    "P02_RLE_FRIENDLY": {
      "algorithm": "RLE_HUFFMAN",
      "algorithm_id": 4,
      "parameters": {"rle_threshold": 3},
      "parameter_set_id": 1,
      "expected_bpb": 2.45,
      "vs_gzip_improvement": "+18%"
    }
  }
}
```

---

## 6. Phase 3: Lightweight MLP Profile Classifier

### 6.1 Design Rationale

**Neden 2-Layer MLP?**

1. **Inference maliyeti düşük:** Her blok zaten feature extraction için tek kez taranır. MLP yalnızca ~10 scalar feature üzerinde çalışır ve hedeflenen blok boyutlarında < 2ms profil tahmini hedefler.
2. **Compression signature maliyeti yok:** LZW/BWT test bpb gibi pahalı özellikler inference'da kullanılmaz; sistem sıkıştırmadan önce kendini sıkıştırmaz.
3. **Yeterli öğrenme kapasitesi:** 15-25 profil için `~10 → 32 → num_profiles` mimarisi, K-Means etiketlerini öğrenmek için yeterli ama over-engineering değildir.
4. **AI entegrasyonu korunur:** Profil tahmini kural tabanlı değil, offline clustering etiketleriyle eğitilmiş supervised bir neural classifier tarafından yapılır.

### 6.2 Input Representation

**Input Vektörü: ~10 boyut (Fast Inference Features / Set B)**

```
[0] byte_entropy
[1] byte_freq_variance
[2] unique_byte_ratio
[3] newline_ratio
[4] space_ratio
[5] uppercase_ratio
[6] digit_ratio
[7] punctuation_ratio
[8] avg_word_length
[9] avg_run_length
```

Bu özellikler tek blok taraması sırasında normalize edilerek çıkarılır. Byte histogramı model input'una 256 boyutlu ham vektör olarak verilmez; entropy, variance ve unique byte ratio gibi scalar özellikleri hesaplamak için ara sayaç olarak kullanılır.

### 6.3 Architecture Specification

```
Input: ~10-dim fast feature vector
    │
    ▼
┌─────────────────────────────────────────────────────────────┐
│                  2-LAYER MLP CLASSIFIER                      │
├─────────────────────────────────────────────────────────────┤
│  Linear(input_dim → 32) + ReLU + Dropout(0.1)                │
│  Linear(32 → NUM_PROFILES)                                  │
│  Softmax / Argmax → Profile ID                              │
└─────────────────────────────────────────────────────────────┘
```

**Model Parametre Sayısı:** Yaklaşık 1K parametre (`input_dim=10`, `num_profiles=25` için ~1,177 parametre). Bu boyut CPU inference için pratikte sıkıştırma algoritmalarının maliyetine göre ihmal edilebilir düzeydedir.

### 6.4 Loss Function

```python
L_total = CrossEntropyLoss(predicted_profile, true_profile)
```

K-Means tarafından yüksek güvenle atanmış profil ID'leri supervised hedef olarak kullanılır. Ek temsil öğrenme kaybı kullanılmaz; amaç doğrudan hızlı ve doğru profil sınıflandırmasıdır.

### 6.5 Training Configuration

| Parametre | Değer |
|-----------|-------|
| Optimizer | AdamW |
| Learning Rate | 1e-3 |
| Batch Size | 256 |
| Epochs | 30-50 (Early Stopping: patience=7) |
| Weight Decay | 1e-4 |
| Dropout | 0.1 |
| Validation Metric | F1-Score (macro) |

### 6.6 Training Data Preparation

```
Training Chunk'ları (Faz 1'den gelen filtrelenmiş veri)
    │
    ├── Her chunk için:
    │   ├── Fast inference feature vektörü çıkar (~10 dim)
    │   ├── K-Means profil etiketini al
    │   └── (fast_features, profile_id) çifti oluştur
    │
    └── Dataset:
        ├── Training: %80
        ├── Validation: %10
        └── Test: %10 (classifier testi, sıkıştırma testinden farklı)
```

Feature standardization parametreleri yalnızca training split üzerinde öğrenilir ve inference için model artifact'ı ile birlikte kaydedilir.

### 6.7 Model Evaluation

| Metrik | Hedef | Açıklama |
|--------|-------|----------|
| **Accuracy** | > %85 | Doğru profil tahmini oranı |
| **F1-Score (Macro)** | > %82 | Dengesiz profil dağılımına karşı robust |
| **Top-3 Accuracy** | > %95 | Doğru profil ilk 3 tahmin içinde |
| **Inference Time** | < 2ms/blok | Feature extraction + MLP tahmini dahil |
| **Compression Impact** | gzip'e göre > %10 ortalama iyileştirme | Profil tahmin hatalarının gerçek sıkıştırma etkisi |

---

## 7. Phase 4: End-to-End Compression Pipeline

### 7.1 Compression Process

```
Input: Ham Metin (herhangi bir boyut)
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 1. BLOKLAMA                                                      │
│    - Metni EDA'da seçilen final chunk size ile böl                │
│    - Bloklar ardışık ve overlap'sizdir                            │
│    - Son blok küçükse padding uygulama (orijinal boyut kaydet)   │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 2. PROFİL TAHMİNİ (Her Blok İçin)                                │
│    - Bloktan fast inference feature vektörü çıkar (~10 dim)      │
│    - 2-layer MLP classifier çalıştır                             │
│    - Profile ID + Confidence Score elde et                       │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 3. ALGORİTMA SEÇİMİ                                              │
│    - Profile ID → Algorithm Mapping Tablosu lookup               │
│    - (Algorithm ID, Parameter Set ID, Parameters) üçlüsünü al     │
│    - Confidence < 0.7 ise: "Güvenli Mod" (en iyi genel algoritma) │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 4. SIKIŞTIRMA                                                    │
│    - Seçilen algoritma ile bloğu sıkıştır                        │
│    - Sıkıştırılmış veriyi buffer'a ekle                          │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 5. HEADER EKLEME (Her Blok Başına)                               │
│    - 4 byte header yapısı (aşağıda detaylandırılmıştır)          │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
Output: Sıkıştırılmış Bitstream
```

### 7.2 Block Header Format

**Header Boyutu: 4 bytes (32 bits)**

```
Bit Layout:
[31:24]  → Profile ID (8 bits) → Maksimum 256 profil desteklenir
[23:20]  → Algorithm ID (4 bits) → Maksimum 16 algoritma
[19:16]  → Parameter Set ID (4 bits) → Her algoritma için 16 varyasyon
[15:0]   → Compressed Block Size (16 bits) → Maksimum 64KB blok

Byte Layout:
Byte 0: [Profile ID: 8 bits]
Byte 1: [Algorithm ID: 4 bits] + [Parameter Set ID: 4 bits]
Byte 2-3: [Compressed Block Size: 16 bits, big-endian]
```

**Header Overhead:**
- 4 bytes / 40KB blok = %0.0098 (~%0.01); final chunk size değişirse yeniden hesaplanır
- 1MB metin = ~25 blok = 100 byte header (ihmal edilebilir)

### 7.3 Decompression Process

```
Input: Sıkıştırılmış Bitstream
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 1. HEADER OKUMA (Her Blok Başından)                              │
│    - 4 byte header'ı parse et                                    │
│    - Profile ID, Algorithm ID, Parameter Set ID, Block Size      │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 2. ALGORİTMA SEÇİMİ                                              │
│    - Algorithm ID + Parameter Set ID → Decoder'ı başlat          │
│    - Block Size kadar veriyi oku                                 │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 3. GENİŞLETME (Decompression)                                    │
│    - Seçilen algoritma ile bloğu genişlet                        │
│    - Final chunk size uzunluğundaki orijinal bloğu elde et        │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
┌─────────────────────────────────────────────────────────────────┐
│ 4. BLOK BİRLEŞTİRME                                              │
│    - Tüm blokları sırayla birleştir                              │
│    - Son blok padding varsa kaldır                               │
└─────────────────────────────────────────────────────────────────┘
    │
    ▼
Output: Orijinal Metin (Lossless)
```

### 7.4 Edge Case Handling

| Senaryo | Çözüm |
|---------|-------|
| Son blok < final chunk size | Orijinal boyut header'da kaydedilir, padding uygulanmaz |
| MLP confidence < 0.7 | "DEFAULT" profile kullan (en iyi genel amaçlı algoritma) |
| Sıkıştırılmış boyut > Orijinal boyut | "Store raw" flag'i ile ham veriyi kaydet (negative compression) |
| Bozuk header | CRC veya checksum kontrolü, hata durumunda exception |
| Bilinmeyen Profile ID | DEFAULT profile'a fallback |

---

## 8. Phase 5: Raw Algorithm Performance Benchmarking

Bu fazin amaci, sistemde kullandigimiz tum klasik codec'lerin ham (profil secimi/MLP olmadan) performansini olcmek ve Faz 4 ile adil bir karsilastirma yapmaktir.

### 8.1 Scope

- Huffman, LZW, Arithmetic, BWT+MTF, RLE+Huffman codec'lerini tek basina benchmark et
- Faz 4 adaptif sistemi ayni test setinde referans olarak dahil et
- bpb, compression ratio, ms/KB, MB/s, memory gibi metrikleri birlikte kaydet
- "En iyi tek algoritma" ile "adaptif sistem" farkini netlestir

### 8.2 Benchmark Protocol

```
Test Verisi:
    ├── Faz 4 ile ayni gorulmemis kitap seti
    ├── Ayni chunk size ve ayni runtime ortami
    └── Tekrarlanabilirlik icin sabit seed + run_id

Her algoritma icin:
    ├── Tum test kitaplarini profil kullanmadan sikistir
    ├── bpb, ratio, compression/decompression time kaydet
    ├── p50/p95/std dagilimlarini hesapla
    └── Faz 4 adaptif sistemi ile yan yana raporla
```

### 8.3 Raw Benchmark Deliverables

| Cikti | Format | Icerik |
|-------|--------|--------|
| Raw Codec Benchmark Table | CSV + Parquet | Her kitap ve her codec icin bpb/time/ratio |
| Best Single Codec Report | Markdown + PDF | En iyi tek codec secimi ve gerekcesi |
| Adaptive vs Raw Comparison | Markdown + CSV | Faz 4 sistemi ile ham codec karsilastirmasi |
| Runtime Profiling Summary | CSV | Algoritma bazli hiz ve kaynak kullanim ozeti |

---

## 9. Implementation Stack

### 9.1 Programming Languages & Frameworks

| Bileşen | Teknoloji | Gerekçe |
|---------|-----------|---------|
| Veri İşleme | Python 3.10+ | Ekosistem, kütüphane zenginliği |
| ML Framework | PyTorch 2.0+ | 2-layer MLP eğitimi, CPU/GPU desteği |
| Scientific Computing | NumPy, SciPy | İstatistiksel hesaplamalar |
| Data Analysis | Pandas | Veri manipülasyonu |
| Visualization | Matplotlib, Seaborn, Plotly | EDA görselleştirmeleri |
| Clustering | scikit-learn | K-Means, metrikler |
| Serialization | Parquet (pyarrow) | Verimli veri depolama |

### 9.2 Custom Components

| Bileşen | Açıklama |
|---------|----------|
| `compression_features.py` | 23 offline compression-aware özellik çıkarımı |
| `fast_features.py` | Tek taramada çıkarılan inference feature'ları |
| `huffman_codec.py` | Order-0/1 Huffman encoder/decoder |
| `lzw_codec.py` | LZW encoder/decoder (değişken sözlük boyutu) |
| `arithmetic_codec.py` | Order-0/1/2 Arithmetic encoder/decoder |
| `bwt_codec.py` | BWT + MTF + Arithmetic/Huffman pipeline |
| `rle_codec.py` | RLE + Huffman hibrit |
| `profile_mlp.py` | PyTorch 2-layer MLP profil sınıflandırıcı |
| `profile_classifier.py` | Inference pipeline |
| `adaptive_compressor.py` | Uçtan uca sıkıştırma/dekompresyon |

### 9.3 Development Environment

```
Hardware:
- CPU: Multi-core (clustering ve grid search için)
- RAM: Minimum 16GB (BWT ve büyük korpus için)
- GPU: Optional (MLP eğitimi CPU'da da yeterince hızlıdır)

Software:
- OS: Linux (Ubuntu 22.04+) veya macOS
- Python Virtual Environment (venv / conda)
- Git versiyon kontrolü
```

---

## 10. Evaluation & Success Criteria

### 10.1 Primary Metrics

| Metrik | Tanım | Hedef |
|--------|-------|-------|
| **Average bpb Improvement** | Sistem bpb / gzip bpb (ortalama) | < 0.90 (%10+ iyileştirme) |
| **Worst-case bpb** | En kötü profildeki bpb | < 1.05 × gzip (hiçbir durumda çok kötü olmamalı) |
| **Profile Accuracy** | MLP'nin doğru profil tahmini | > %85 |
| **Compression Speed** | MB/s cinsinden | > 1 MB/s (kabul edilebilir) |
| **Decompression Speed** | MB/s cinsinden | > 5 MB/s |

### 10.2 Baseline Comparisons

Sistem aşağıdaki baseline'larla karşılaştırılacaktır:

| Baseline | Komut | Açıklama |
|----------|-------|----------|
| gzip -9 | `gzip -9 < input > output` | Deflate, max compression |
| gzip -6 | `gzip -6 < input > output` | Deflate, default |
| bzip2 -9 | `bzip2 -9 < input > output` | BWT + MTF + Huffman |
| lzma -9 | `xz -9 < input > output` | LZMA |
| zlib -6 | Python `zlib.compress(level=6)` | Deflate, Python default |

### 10.3 Test Protocol

```
Test Veriseti (Görülmemiş Kitaplar):
    │
    ├── 20-30 kitap, toplam ~50-100MB
    │
    ├── Her kitap için:
    │   ├── Sistem ile sıkıştır (profil bazlı)
    │   ├── gzip -9 ile sıkıştır
    │   ├── bzip2 -9 ile sıkıştır
    │   └── lzma -9 ile sıkıştır
    │
    └── Metrikler:
        ├── Her kitap için bpb karşılaştırması
        ├── Kitap türüne göre analiz (roman, şiir, teknik)
        ├── Blok başına profil dağılımı (hangi profil ne sıklıkla seçildi)
        └── Hata analizi (yanlış profil seçimlerinin etkisi)
```

---

## 11. Project Timeline

| Hafta | Faz | Görevler | Çıktılar |
|-------|-----|----------|----------|
| **1** | Faz 0 | Proje kurulumu, Gutenberg API/indirip temizleme, repo yapısı | Temizlenmiş kitap koleksiyonu |
| **2** | Faz 1 | Chunk size sweep, no-chunk baseline, feature extraction pipeline'ı | EDA deney matrisi, feature dataset (Parquet) |
| **3** | Faz 1 | EDA: algoritma davranışı, parametre hassasiyeti, histogramlar, korelasyon, t-SNE/UMAP | EDA raporu, final chunk size kararı |
| **4** | Faz 1 | K-Means clustering, K seçimi, feature ablation, filtreleme | Profil tanımları, etiketli dataset |
| **5** | Faz 2 | Klasik algoritma implementasyonları | 5 codec, unit test'ler |
| **6** | Faz 2 | Grid search: her profil için en iyi algoritma | Algorithm Mapping Tablosu |
| **7** | Faz 3 | Fast feature pipeline, 2-layer MLP eğitimi ve değerlendirme | Eğitilmiş classifier, metrikler |
| **8** | Faz 4 | Uçtan uca pipeline birleştirme | Tam sistem |
| **9** | Faz 4 | Test veriseti üzerinde değerlendirme | Karşılaştırma raporu |
| **10** | Faz 5 | Ham codec benchmark koşuları, en iyi tek algoritma analizi | Raw benchmark raporu |
| **11** | Faz 5 | Adaptif sistem vs ham algoritma nihai karşılaştırma ve final raporlama | Final deliverables |

---

## 12. Risk Analysis & Mitigation

| Risk | Olasılık | Etki | Önlem |
|------|----------|------|-------|
| K-Means profilleri anlamlı çıkmaz | Orta | Yüksek | HDBSCAN alternatifi, feature engineering derinleştirme |
| Algoritma farkları çok küçük olur | Orta | Orta | Daha fazla algoritma varyasyonu, parametre optimizasyonu |
| MLP profil ayrımını öğrenemez | Orta | Orta | Fast feature set'i genişletme, class weighting, gerekirse hidden size 64 denemesi |
| Test kitaplarında genelleme kötü | Orta | Yüksek | Kitap seviyesinde split, daha fazla training verisi |
| Sıkıştırma hızı çok yavaş | Düşük | Orta | Cython/Numba optimizasyonu, paralel blok işleme |
| Gutenberg metinleri homojen | Düşük | Yüksek | Farklı dönem/türden daha fazla kitap |

---

## 13. Deliverables

### 13.1 Code Deliverables

| Dosya/Modül | Açıklama |
|-------------|----------|
| `src/data/` | Veri indirme, temizleme, chunk'lama |
| `src/features/` | Offline compression-aware ve fast inference feature extraction |
| `src/clustering/` | K-Means, değerlendirme, filtreleme |
| `src/codecs/` | Huffman, LZW, Arithmetic, BWT, RLE implementasyonları |
| `src/models/` | 2-layer MLP profil sınıflandırıcı |
| `src/compression/` | Uçtan uca sıkıştırma/dekompresyon pipeline'ı |
| `src/benchmark/` | Ham codec benchmark runner ve karşılaştırma script'leri |
| `src/evaluation/` | Metrik hesaplama, baseline karşılaştırma |
| `notebooks/` | EDA, analiz, görselleştirme Jupyter notebook'ları |
| `tests/` | Unit test'ler |
| `config/` | YAML/JSON konfigürasyon dosyaları |

### 13.2 Documentation Deliverables

| Doküman | İçerik |
|---------|--------|
| **PRD** (Bu doküman) | Proje gereksinimleri ve mimarisi |
| **Technical Report** | Algoritmalar, formüller, karmaşıklık analizi |
| **EDA Report** | Veri keşfi sonuçları, görselleştirmeler |
| **Training Report** | MLP eğitim metrikleri, konfüzyon matrisi, inference süresi |
| **Evaluation Report** | Baseline karşılaştırmaları, istatistiksel analiz |
| **Raw Benchmark Report** | Ham codec sonuçları, en iyi tek algoritma ve adaptif sistem karşılaştırması |
| **User Guide** | Sistemin kullanımı, örnekler |

---

## 14. Appendix

### 14.1 Compression Algorithms Reference

#### Huffman Coding
- **Principle:** Karakter frekanslarına göre değişken uzunluklu kodlar.
- **Complexity:** O(n) encoding, O(n) decoding (n = input size).
- **Optimal for:** Karakter frekans dağılımı belirgin, düşük entropi metinler.

#### LZW (Lempel-Ziv-Welch)
- **Principle:** Tekrar eden kalıpları dinamik sözlüğe kaydet, indekslerle kodla.
- **Complexity:** O(n) encoding, O(n) decoding.
- **Optimal for:** Yüksek tekrar oranı, standart terminoloji, diyalog.

#### Arithmetic Coding
- **Principle:** Tüm mesajı [0,1) aralığındaki bir kesire eşle.
- **Complexity:** O(n) encoding, O(n) decoding.
- **Optimal for:** Yüksek entropi, bağlamsal bağımlılıklar (higher-order models).

#### BWT (Burrows-Wheeler Transform)
- **Principle:** Blok sıralaması ile karakterleri grupla, MTF + entropy coding.
- **Complexity:** O(n log n) encoding, O(n) decoding.
- **Optimal for:** Uzun bloklar, yüksek tekrar, büyük alfabe.

### 14.2 Feature Engineering Formulas

**Shannon Entropy:**
```
H(X) = -Σ p(x) * log₂(p(x))
```

**Conditional Entropy:**
```
H(Y|X) = H(X,Y) - H(X)
```

**Zipf Distribution:**
```
f(k) = C / k^α
where α ≈ 1 for natural language
```

**Compression Ratio:**
```
CR = UncompressedSize / CompressedSize
```

**Bits Per Byte:**
```
bpb = (CompressedSize * 8) / UncompressedSize
```

### 14.3 Glossary

| Terim | Tanım |
|-------|-------|
| **bpb** | Bits Per Byte: Sıkıştırma verimliliği metriği |
| **BWT** | Burrows-Wheeler Transform: Blok sıralama dönüşümü |
| **MTF** | Move-to-Front: BWT sonrası transformasyon |
| **RLE** | Run-Length Encoding: Ardışık tekrar kodlama |
| **Fast Inference Features** | Faz 3 ve Faz 4'te tek taramada çıkarılan hızlı profil tahmin özellikleri |
| **Compression Signature** | Sadece offline EDA/K-Means için kullanılan LZW/BWT/Huffman test bpb metrikleri |
| **Profile** | Benzer sıkıştırma karakteristiklerine sahip metin grubu |
| **Chunk** | EDA'da seçilen sabit boyutlu metin parçası; ilk aday 40KB |
| **Context Order** | Entropy coder'da kaç önceki sembolün koşullu dağılımda kullanıldığı |

---

*Document prepared for academic project submission.*  
*All algorithms implemented from scratch (no external compression libraries for core codecs).*
