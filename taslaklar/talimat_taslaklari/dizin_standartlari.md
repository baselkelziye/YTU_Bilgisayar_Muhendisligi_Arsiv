# Dizin ve Dosya Adlandırma Standardı

Bu belge, repo içindeki dizin ve dosya isimlendirme kurallarını tanımlar.
Tüm yeni eklemeler ve değişiklikler bu standartlara uymalıdır.

---

## 1. Genel Kurallar

### 1.1 Türkçe Karakterler
- Tüm Türkçe karakterler kullanılmalıdır: **ç, ğ, ı, İ, ö, ş, ü, Ü, Ö, Ş, Ç, Ğ**
- İngilizce karşılıkları kullanılmaz (örn: `c` → `ç`, `g` → `ğ`)

### 1.2 Büyük/Küçük Harf
- **Başlıklar:** İlk harf büyük, bağlaçlar küçük yazılır
  - ✅ `Bilgisayar Mühendisleri için Sinyaller ve Sistemler`
  - ❌ `Bilgisayar Mühendisleri İçin Sinyaller Ve Sistemler`
- **Bağlaçlar küçük yazılır:** `ve`, `için`, `ile`, `veya`, `ya da`
- **Özel isimler ve unvanlar büyük başlar:** `Bilgisayar`, `Mühendisleri`, `Analizi`

### 1.3 Kısaltmalar
- Kısaltma yapılmaz, tam yazılır
  - ✅ `Bilgisayar Mühendisleri için`
  - ❌ `Bilgisayar Müh için`

### 1.4 Boşluk
- Dizin adlarında tek boşluk kullanılır
- Ardışık boşluk olmaz
- Tire (-) veya alt çizgi (_) bağlaç olarak kullanılmaz

---

## 2. Dizin Yapısı Hiyerarşisi

```
repo/
├── X-Y/                          # Dönem dizini (1-1, 1-2, 2-1, ...)
│   ├── Ders Adı/                 # Ders dizini
│   │   ├── README.md             # Zorunlu
│   │   ├── slaytlar_notlar/      # Slayt ve not klasörü
│   │   │   └── YYYY/             # Yıl bazlı alt dizin
│   │   │       └── dosya_adi.pdf
│   │   ├── ödevler/              # Ödev klasörü
│   │   │   └── YYYY/
│   │   │       └── odev_X/       # Ödev adı (alt çizgi + numara)
│   │   ├── projeler/             # Proje klasörü
│   │   │   └── YYYY/
│   │   ├── ders_kayitlari/       # Ders kayıtları
│   │   │   └── YYYY-YYYY/
│   │   ├── cikmis_sorular/       # Çıkmış sorular
│   │   │   └── YYYY/
│   │   └── harf_notları/         # Harf notları
│   │       └── YYYY/
│   └── README.md                 # Dönem README'si
├── Mesleki Seçmeli 1/            # Seçmeli ders grubu
├── Sosyal Seçmeli 1/
├── Üniversite Mesleki Seçmeli/
├── Üniversite Sosyal Seçmeli/
├── Lisansüstü/
├── Bilgisayar Projesi/
├── Bitirme Çalışması/
├── Ders Programları/
├── mulakat_tecrubeleri/
├── readme_olustur/               # README oluşturucu
└── README.md                     # Ana README
```

---

## 3. Dizin Adlandırma Kuralları

### 3.1 Ders Dizinleri
- Ders adının tam hali yazılır
- Türkçe karakterler korunur
- Bağlaçlar küçük harf: `ve`, `için`, `ile`
  - ✅ `Bilgisayar Mühendisleri için Sinyaller ve Sistemler`
  - ✅ `Veri Yapıları ve Algoritmalar`
  - ✅ `Nesneye Yönelik Programlama`

### 3.2 Alt Dizin Adları

| Dizin | Format | Örnek |
|-------|--------|-------|
| Slayt/not klasörü | `slaytlar_notlar` | `slaytlar_notlar/2024/` |
| Ödev klasörü | `ödevler` | `ödevler/2024/` |
| Ödev adı | `odev_X` | `odev_1/`, `odev_2/` |
| Proje klasörü | `projeler` | `projeler/2024/` |
| Ders kayıtları | `ders_kayitlari` | `ders_kayitlari/2023-2024/` |
| Çıkmış sorular | `cikmis_sorular` | `cikmis_sorular/2024/` |
| Harf notları | `harf_notları` | `harf_notları/2024/` |
| Altyazılar | `altyazilar` | `altyazilar/` |
| Video klasörü | ` videolar` | `videolar/` |

### 3.3 Yıl Dizinleri
- Dört haneli yıl: `2024`, `2023`
- Dönem bazlı ise: `2023-2024`

### 3.4 Dosya Adları
- Boşluk yerine alt çizgi (`_`) kullanılır
  - ✅ `odev_1.pdf`
  - ❌ `odev 1.pdf`
- Türkçe karakterler korunur
  - ✅ `notlar.pdf`
  - ❌ `notlar.pdf`
- Büyük harf kullanımı tutarlı olmalı

---

## 4. README Standartları

readme_olustur klasöründen yürütülmektedir.

## 5. Yasak Alanlar

Aşağıdaki isimler kullanılmaz:
- `odev1` (boşluk/tire olmadan) → `odev_1` olmalı
- `ödev 1` (boşluklu) → `odev_1` olmalı
- `ödev-1` (tireli) → `odev_1` olmalı
- `lab1` → `lab_1`
- `Bilgisayar Müh` (kısaltma) → `Bilgisayar Mühendisleri`
- `Yonelik` (yazım hatası) → `Yönelik`
- `Displinli` (yazım hatası) → `Disiplinli`

---

## 6. Kontrol Listesi

Yeni dizin eklerken:
- [ ] Türkçe karakterler doğru mu?
- [ ] Bağlaçlar küçük harf mi? (`ve`, `için`, `ile`)
- [ ] Kısaltma yapılmış mı?
- [ ] Boşluk/tire/alt çizgi doğru mu?
- [ ] README.md var mı?
- [ ] Linkler doğru mu?
