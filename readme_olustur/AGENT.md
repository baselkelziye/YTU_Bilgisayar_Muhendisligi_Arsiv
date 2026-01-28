# Üniversite Ders Notları README Oluşturucu - Ajan Kılavuzu

Bu belge, projenin yapısını ve işleyişini anlamak isteyen AI ajanları için hazırlanmıştır.

## Proje Özeti

Bu proje, üniversite ders notları arşivi için otomatik README.md dosyaları oluşturan bir araç setidir. Temel olarak iki ana bileşenden oluşur:

1. **PyQt6 GUI Arayüzü** - Kullanıcıların ders, hoca, dönem ve diğer bilgileri yönetmesini sağlar
2. **README Oluşturma Motoru** - JSON verilerinden Markdown README dosyaları üretir

## Dizin Yapısı

```
ytu_arsiv_readme_olusturma/
├── readme_guncelleme_arayuzu_python/   # PyQt6 GUI uygulaması
│   ├── main.py                          # Ana uygulama giriş noktası
│   ├── degiskenler.py                   # Tüm sabitler, yollar ve konfigürasyon
│   ├── *_window.py                      # Pencere/dialog sınıfları
│   ├── git_helper.py                    # Git işlemleri yardımcısı
│   ├── threadler.py                     # Arka plan işlemleri için QThread sınıfları
│   ├── helpers/                         # Yardımcı modüller
│   └── stil.qss                         # Qt stil dosyası
├── google_forum_islemleri/             # Google Form entegrasyonu
│   ├── google_form_rutin_kontrol.py    # Otomatik form güncelleme kontrolü
│   ├── ders_icerikleri_guncelle.py     # Ders verilerini formdan çekme
│   └── hoca_icerikleri_guncelle.py     # Hoca verilerini formdan çekme
├── readme_olustur.py                   # README.md oluşturma motoru
├── konfigurasyon.json                  # Proje ayarları (gitignore'da)
├── json_depo_bilgileri.txt             # JSON dosyalarının yolunu belirtir
├── arayuz.bat / arayuz.sh              # Platformlara göre başlatma scriptleri
└── gereksinimler.txt                   # Python bağımlılıkları
```

## Temel Modüller

### 1. `readme_olustur.py` - README Oluşturma Motoru

Ana README.md oluşturma mantığını içerir. JSON dosyalarından veri okur ve Markdown formatında README dosyaları üretir.

**Önemli Fonksiyonlar:**
- `hocalari_readme_ye_ekle()` - Hoca bilgilerini README'ye ekler
- `dersleri_readme_ye_ekle()` - Ders bilgilerini README'ye ekler
- `readme_ye_giris_ekle()` - Giriş bölümünü oluşturur
- `readme_ye_repo_kullanimi_ekle()` - Repo kullanım talimatlarını ekler
- `yerel_yoldan_github_linkine()` - Yerel yolları GitHub URL'lerine dönüştürür
- `en_iyi_eslesen_klasor_yolu_bul()` - Ders klasörlerini fuzzy matching ile bulur
- `detay_etiketleri_olustur()` - HTML `<details>` etiketleri oluşturur
- `puanlari_yildiza_cevir()` - Sayısal puanları yıldız emojilerine dönüştürür

### 2. `degiskenler.py` - Merkezi Konfigürasyon

**Tüm sabitler ve yollar bu dosyada tanımlanır.** Yeni sabit eklerken mutlaka bu dosya kontrol edilmelidir.

**İçerikler:**
- JSON anahtar sabitleri (`DERSLER`, `HOCALAR`, `BOLUM_ADI` vb.)
- Varsayılan değerler (`VARSAYILAN_HOCA_BOLUM_ADI` vb.)
- Dosya yolları (`DERSLER_JSON_PATH`, `HOCALAR_JSON_PATH` vb.)
- Stil sabitleri (`EKLE_BUTONU_STILI`, `SIL_BUTONU_STILI` vb.)
- İkon yolları (`SELCUKLU_ICO_PATH`, `SAVE_ICO_PATH` vb.)
- Seçenek dizileri (`DERS_TURLERI`, `DONEM_YILLARI` vb.)

**Yol Çözümleme Mantığı:**
- `json_depo_bilgileri.txt` dosyasından JSON deposu yolu okunur
- Tüm diğer yollar bu depoya göre çözümlenir
- `../` ön eki ile üst dizine referans verilir

### 3. `main.py` - Ana Uygulama

`App` sınıfı ana pencereyi oluşturur. Her buton bir `*Window` sınıfı açar:

| Buton | Açılan Pencere Sınıfı | Dosya |
|-------|----------------------|-------|
| Giriş Güncelle | `GirisEkleGuncelleWindow` | `giris_ekle_guncelle_window.py` |
| Repo Kullanımı | `RepoKullanimiDialog` | `repo_kullanimi_window.py` |
| Ders Ekle/Güncelle | `DersEkleGuncelleWindow` | `ders_ekle_guncelle_window.py` |
| Hoca Ekle/Güncelle | `HocaEkleGuncelleWindow` | `hoca_ekle_guncelle_window.py` |
| Yazarın Notları | `YazarinNotlariWindow` | `yazarin_notlari_duzenle_window.py` |
| Katkıda Bulunanlar | `KatkidaBulunanGuncelleWindow` | `katkida_bulunanlari_duzenle_window.py` |
| Dönem Ekle/Güncelle | `DonemEkleGuncelleWindow` | `donem_ekle_guncelle_window.py` |
| Konfigürasyon | `KonfigurasyonDialog` | `konfigurasyon_window.py` |
| Git İşlemleri | `GitIslemleriWindow` | `git_islemleri_window.py` |

### 4. `git_helper.py` - Git İşlemleri

**GitHelper Sınıfı (Statik Metodlar):**
- `git_status()` - Değişiklikleri listele
- `git_add()` / `git_add_all()` - Değişiklikleri stage'e ekle
- `git_reset()` / `git_reset_all()` - Stage'den çıkar
- `git_commit()` - Commit oluştur
- `git_push()` - Değişiklikleri uzak repoya gönder
- `git_restore()` - Dosyayı eski haline getir
- `git_diff()` - Değişiklikleri göster

**GitDialog Sınıfı:** Değişiklikleri push etmek için GUI penceresi.

### 5. `threadler.py` - Arka Plan İşlemleri

PyQt6 QThread sınıflarını içerir:
- `HocaKaydetThread` - Hoca kaydetme işlemi
- `KatkiEkleThread` - Katkıda bulunan ekleme
- `CMDScriptRunnerThread` - Shell komutlarını çalıştırma

## Veri Akışı

```
JSON Dosyaları                    GUI Penceresi
     ↓                                 ↓
dersler.json  ←─────────────→  DersEkleGuncelleWindow
hocalar.json  ←─────────────→  HocaEkleGuncelleWindow
donemler.json ←─────────────→  DonemEkleGuncelleWindow
giris.json    ←─────────────→  GirisEkleGuncelleWindow
     ↓
readme_olustur.py
     ↓
README.md dosyaları
```

## JSON Dosya Yapıları

### `dersler.json`
```json
{
  "bolum_adi": "Dersler",
  "bolum_aciklamasi": "...",
  "dersler": [
    {
      "ad": "Nesneye Dayalı Programlama",
      "yil": "2",
      "donem": "Güz",
      "tip": "Zorunlu",
      "guncel_mi": true,
      "hocalar": ["Prof. Dr. X", "Doç. Dr. Y"],
      "oneriler": [{"oneri": "...", "oneri_sahibi": "..."}],
      "kaynaklar": [{"baslik": "...", "link": "..."}]
    }
  ]
}
```

### `hocalar.json`
```json
{
  "bolum_adi": "Hocalar",
  "bolum_aciklamasi": "...",
  "hocalar": [
    {
      "ad": "Prof. Dr. Ahmet Yılmaz",
      "ofis": "EEB-305",
      "link": "https://avesis.yildiz.edu.tr/...",
      "hoca_aktif_gorevde_mi": true,
      "erkek_mi": true,
      "dpiersler": ["Ders 1", "Ders 2"]
    }
  ]
}
```

### `konfigurasyon.json`
```json
{
  "github_url": "https://github.com/.../...",
  "hoca_yorumlama": "https://forms.gle/...",
  "hoca_oylama": "https://forms.gle/...",
  "ders_yorumlama": "https://forms.gle/...",
  "ders_oylama": "https://forms.gle/...",
  "ders_oylama_csv": "https://docs.google.com/spreadsheets/.../pub?output=csv",
  "ders_yorumlama_csv": "...",
  "hoca_oylama_csv": "...",
  "hoca_yorumlama_csv": "...",
  "dokumanlar_repo_yolu": "..",
  "cikmislar": "https://drive.google.com/..."
}
```

## Pencere Sınıfı Desenleri

Her pencere sınıfı benzer bir yapı izler:

```python
class XxxWindow(QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setModal(True)
        self.is_programmatic_close = False  # closeEvent için flag
        self.data = self.jsonDosyasiniYukle()
        self.initUI()
        
    def initUI(self):
        # Layout ve widgetları oluştur
        
    def jsonDosyasiniYukle(self):
        # JSON dosyasını oku
        
    def jsonKaydet(self):
        # JSON dosyasına yaz
        
    def keyPressEvent(self, event):
        # Escape tuşuyla kapatmayı engelle
        if event.key() == Qt.Key.Key_Escape:
            return
```

## Google Form Entegrasyonu

`google_forum_islemleri/` dizini anket verilerini işler:

1. **CSV Dosyaları:** Google Sheets'ten CSV olarak çekilen anket sonuçları
2. **`hoca_icerikleri_guncelle.py`:** Hoca yorumları ve puanlarını işler
3. **`ders_icerikleri_guncelle.py`:** Ders yorumları ve puanlarını işler
4. **`google_form_rutin_kontrol.py`:** Periyodik olarak formları kontrol eder ve değişiklikleri uygular

## Çalıştırma

### Geliştirme
```bash
cd readme_guncelleme_arayuzu_python
python3 main.py
```

### README Oluşturma
```bash
python3 readme_olustur.py
```

### Rutin Kontrol (Arka Plan)
```bash
cd google_forum_islemleri
python3 google_form_rutin_kontrol.py
```

## Önemli Notlar Geliştiriciler İçin

1. **Yol Yönetimi:** Tüm yollar `degiskenler.py` üzerinden yönetilir. Yeni dosya/yol eklerken bu dosyayı güncelleyin.

2. **JSON Encoding:** Tüm JSON okuma/yazma işlemlerinde `encoding="utf-8"` kullanılmalıdır.

3. **Thread Kullanımı:** UI'ı dondurmamak için uzun işlemler `threadler.py`'deki QThread sınıfları ile yapılmalıdır.

4. **Modal Diyaloglar:** Tüm pencereler `self.setModal(True)` ile modal açılır.

5. **closeEvent:** Pencere kapanırken veri kaybını önlemek için `closeEventHandler` kullanılır.

6. **Stil:** Qt stilleri `stil.qss` dosyasında tanımlanır, buton renkleri kod içinde ayrıca ayarlanır.

7. **Ünvan Formatı:** Hoca isimleri ünvanla birlikte saklanır: `"Prof. Dr. Ad Soyad"`. `hoca_kisaltma_olustur.py` kısaltma oluşturur.

8. **Türkçe Karakter:** `unicodedata.normalize("NFKD", text)` ile Türkçe karakterler normalize edilir.

## Bağımlılıklar

```
PyQt6         # GUI framework
requests      # HTTP istekleri (Google Sheets CSV çekme)
```

## İlişkili Proje

Bu araç, ana ders notları arşivi reposuyla (`YTU_BILGISAYAR_MUHENDISLIGI_ARSIV`) birlikte çalışır. JSON dosyaları o repoda `json_dosyalari/` dizininde saklanır, README.md dosyaları ise ders klasörlerinde oluşturulur.
