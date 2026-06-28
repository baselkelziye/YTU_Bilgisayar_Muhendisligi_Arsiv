# Dizin ve Dosya Adlandırma Standardı

Bu belge, repo içindeki dizin ve dosya isimlendirme kurallarını tanımlar.
Tüm yeni eklemeler ve değişiklikler bu standartlara uymalıdır.

---

## 1. Genel Kurallar

### 1.1 Türkçe Karakterler
- Tüm Türkçe karakterler kullanılmalıdır: **ç, ğ, ı, ö, ş, ü, Ç, Ğ, İ, Ö, Ş, Ü**
- İngilizce karşılıkları kullanılmaz (örn: `odevler` yerine `ödevler`, `cikmis` yerine `çıkmış`)

### 1.2 İsimlendirme İki Seviyelidir

| Seviye | Kural | Örnek |
|--------|-------|-------|
| **Ders dizinleri** | PascalCase + boşluk, bağlaçlar küçük | `Bilgisayar Mühendisleri için Sinyaller ve Sistemler` |
| **Alt dizinler** | küçük harf + `_` ayracı | `ödevler`, `slaytlar_notlar`, `harf_notları` |
| **Dosya adları** | küçük harf + `_` ayracı | `ödev_1.pdf`, `ders_notu.pdf` |

### 1.3 Kısaltmalar
- Kısaltma yapılmaz, tam yazılır
  - ✅ `Bilgisayar Mühendisleri için`
  - ❌ `Bilgisayar Müh için`

---

## 2. Ders Dizini Adlandırma (PascalCase + Boşluk)

Ders dizinleri **2. veya 3. seviyede** bulunur:

```
1-1/Bilgisayar Bilimlerine Giriş/          ← 2. seviye
1-2/Devre Teorisi ve Elektronik Devreler/  ← 2. seviye
1-2/Devre Teorisi ve Elektronik Devreler/Elektronik Devreler/  ← 3. seviye (alt konu)
```

### 2.1 Kurallar
- Her kelimenin ilk harfi **büyük** yazılır
- Bağlaçlar **küçük** yazılır: `ve`, `için`, `ile`, `veya`, `ya da`
- Kelimeler arasında **tek boşluk** kullanılır
- Türkçe karakterler korunur
- `_` veya `-` kullanılmaz

  - ✅ `Bilgisayar Mühendisleri için Sinyaller ve Sistemler`
  - ✅ `Veri Yapıları ve Algoritmalar`
  - ✅ `Nesneye Yönelik Programlama`
  - ❌ `bilgisayar_mühendisleri_için_sinyaller_ve_sistemler` (küçük harf + `_`)
  - ❌ `Bilgisayar Mühendisleri İçin Sinyaller Ve Sistemler` (bağlaç büyük)
  - ❌ `Bilgisayar Müh için Sinyaller` (kısaltma)

### 2.2 Alt Ders / Konu Dizinleri
Bazı dersler alt konulara ayrılır. Bunlar da ders dizini kurallarına uyar:

  - ✅ `Devre Teorisi ve Elektronik Devreler/Elektronik Devreler/`
  - ✅ `Mikroişlemci Sistemleri ve Assembly Dili/Mikroişlemci Sistemleri/`

---

## 3. Alt Dizin Adlandırma (küçük harf + `_`)

Ders dizini **içindeki** tüm alt klasörler bu kurala uyar:
- Tümü **küçük harf**
- Kelimeler arasında **`_`** kullanılır
- **Boşluk** ve **tire** (`-`) kullanılmaz
- Sayı ile kelime arasında **`_`** kullanılır

### 3.1 Standart Alt Dizin Türleri

| Dizin Türü | Standart Ad | Örnek |
|-----------|------------|-------|
| Slayt/not | `slaytlar_notlar` | `slaytlar_notlar/2024/` |
| Ödevler | `ödevler` | `ödevler/2024/` |
| Ödev alt dizini | `ödev_X` | `ödev_1/`, `ödev_2/` |
| Makale sunum (ödev altında) | `ödevler/YYYY/makale_sunum/` | `ödevler/2024/makale_sunum/` |
| Proje | `proje` | `proje/2024/` |
| Ders kayıtları | `ders_kayıtları` | `ders_kayıtları/2023-2024/` |
| Çıkmış sorular | `çıkmış_sorular` | `çıkmış_sorular/2024/` |
| Harf notları | `harf_notları` | `harf_notları/2024/` |
| Kitaplar | `kitaplar` | `kitaplar/` |
| Lablar | `lablar` | `lablar/` |
| Lab + kod (birleşik) | `lablar_kodlar` | `lablar_kodlar/` |
| Lab + quiz (birleşik) | `lablar_quizler` | `lablar_quizler/` |
| Kodlar | `kodlar` | `kodlar/` |
| Quizler | `quizler` | `quizler/` |
| Sınavlar | `sınavlar` | `sınavlar/` |
| Uygulamalar | `uygulamalar` | `uygulamalar/` |
| Çalışma soruları | `çalışma_soruları` | `çalışma_soruları/` |
| Algoritmalar | `algoritmalar` | `algoritmalar/` |
| Altyazılar | `altyazılar` | `altyazılar/` |
| Örnekler | `örnekler` | `örnekler/` |

### 3.2 Birleşik Dizin Kuralları

- `lablar_kodlar`: Hem lab hem kod içeren derslerde tek dizin. Ayrı ayrı `lablar/` ve `kodlar/` yerine tercih edilir.
- `lablar_quizler`: Hem lab hem quiz içeren derslerde tek dizin (örn: `lablar_quizler/2024/`).
- Sadece lab varsa `lablar/`, sadece kod varsa `kodlar/`, sadece quiz varsa `quizler/` kullanılır.
- `kodlar_lablar` veya `lablar-quizler` gibi sıralama/ayraç varyasyonları **yasaktır**.

### 3.3 Yıl Dizinleri
- Dört haneli yıl: `2024`, `2023`
- Dönem bazlı ise: `2023-2024`
- Yaz dönemi: `YYYY_yaz` (örn: `2024_yaz`)

---

## 4. Dosya Adlandırma

- Tümü **küçük harf**
- Boşluk yerine **`_`**
- Türkçe karakterler korunur

  - ✅ `ödev_1.pdf`
  - ✅ `ders_notu.pdf`
  - ✅ `final_soruları.pdf`
  - ❌ `ödev 1.pdf` (boşluk)
  - ❌ `Ödev_1.pdf` (büyük harf)
  - ❌ `odev-1.pdf` (tire, türkçe karakter eksik)

---

## 5. Dizin Yapısı Hiyerarşisi

```
repo/
├── X-Y/                                          # Dönem dizini (1-1, 1-2, ...)
│   ├── Ders Adı/                                 # Ders dizini (PascalCase + boşluk)
│   │   ├── README.md                             # Zorunlu
│   │   ├── slaytlar_notlar/                      # Alt dizin (küçük + _)
│   │   │   └── YYYY/
│   │   │       └── dosya_adi.pdf
│   │   ├── ödevler/                              # Alt dizin
│   │   │   └── YYYY/
│   │   │       ├── ödev_X/                       # Ödev alt dizini
│   │   │       └── makale_sunum/                 # Makale sunum (Lisansüstü)
│   │   ├── proje/                                # Alt dizin
│   │   │   └── YYYY/
│   │   ├── ders_kayıtları/                       # Alt dizin
│   │   │   └── YYYY-YYYY/
│   │   ├── çıkmış_sorular/                       # Alt dizin
│   │   │   └── YYYY/
│   │   ├── harf_notları/                         # Alt dizin
│   │   │   └── YYYY/
│   │   ├── kitaplar/                             # Alt dizin
│   │   ├── lablar_kodlar/                        # Alt dizin (birleşik)
│   │   │   └── YYYY/
│   │   ├── lablar_quizler/                       # Alt dizin (birleşik)
│   │   │   └── YYYY/
│   │   ├── quizler/                              # Alt dizin
│   │   ├── sınavlar/                             # Alt dizin
│   │   └── Ders Adı/                             # Alt konu (3. seviye ders)
│   │       ├── README.md
│   │       ├── slaytlar_notlar/
│   │       └── lablar/
│   └── README.md                                 # Dönem README'si
├── Mesleki Seçmeli 1/                            # Ders grubu (PascalCase + boşluk)
│   ├── Ders Adı/                                 # Ders dizini
│   └── README.md
├── Sosyal Seçmeli 1/
├── Üniversite Mesleki Seçmeli/
├── Üniversite Sosyal Seçmeli/
├── Lisansüstü/
├── Bilgisayar Projesi/
├── Bitirme Çalışması/
├── Çok Disiplinli Tasarım Projesi/
├── Ders Programları/
├── mülakat_tecrübeleri/                          # Alt dizin formatı
├── readme_olustur/                               # Araç
├── taslaklar/                                    # Taslak
└── README.md                                     # Ana README
```

---

## 6. Özel Dizinler (Bilgisayar Projesi / Bitirme Çalışması)

Bu dizinlerin içindeki alt klasörler alt dizin kurallarına uyar:

## 7. Yasak İsimlendirmeler

| Yasak | Doğru | Sebep |
|-------|-------|-------|
| `odev1` | `ödev_1` | türkçe karakter + ayraç eksik |
| `ödev 1` | `ödev_1` | boşluk yasak (alt dizinde) |
| `ödev-1` | `ödev_1` | tire yasak |
| `Ödev1` | `ödev_1` | büyük harf + ayraç eksik |
| `Ödev_1` | `ödev_1` | büyük harf |
| `lab1` | `lab_1` | ayraç eksik |
| `lab 1` | `lab_1` | boşluk yasak (alt dizinde) |
| `Lab1` | `lab_1` | büyük harf + ayraç eksik |
| `bilgisayar_müh_için` | `Bilgisayar Mühendisleri için` | kısaltma + yanlış format (ders dizini PascalCase olmalı) |
| `Slides` | `slaytlar_notlar` | ingilizce yasak |
| `Slides-Nodes` | `slaytlar_notlar` | ingilizce + tire yasak |
| `HMW1` | `ödev_1` | ingilizce yasak |
| `Yonelik` | `Yönelik` | türkçe karakter eksik |
| `Displinli` | `Disiplinli` | yazım hatası |
| `lablar-quizler` | `lablar_quizler` | tire yasak (alt dizinde) |
| `quizler_lablar` | `lablar_quizler` | sıralama: lab önce gelir |
| `kodlar_lablar` | `lablar_kodlar` | sıralama: lab önce gelir |
| `proje-ödev` | `ödevler` (ya da `proje`) | birleşik isim yasak |
| `çalışma soruları` | `çalışma_soruları` | boşluk yasak (alt dizinde) |
| `makale sunum` | `ödevler/YYYY/makale_sunum/` | boşluk yasak + yeri `ödevler` altı |
| `ödev` (tekil) | `ödevler` | çoğul kullanılır |

---

## 8. Kontrol Listesi

Yeni ders dizini eklerken:
- [ ] PascalCase + boşluk formatında mı?
- [ ] Bağlaçlar küçük harf mi? (`ve`, `için`, `ile`)
- [ ] Türkçe karakterler doğru mu?
- [ ] Kısaltma yapılmış mı?
- [ ] README.md var mı?

Yeni alt dizin eklerken:
- [ ] Tümü küçük harf mi?
- [ ] Ayraç olarak `_` kullanılmış mı? (boşluk/tire yok)
- [ ] Sayı ile kelime arasında `_` var mı?
- [ ] Türkçe karakterler doğru mu?

Dosya eklerken:
- [ ] Tümü küçük harf mi?
- [ ] Boşluk yerine `_` kullanılmış mı?
- [ ] Türkçe karakterler doğru mu?
