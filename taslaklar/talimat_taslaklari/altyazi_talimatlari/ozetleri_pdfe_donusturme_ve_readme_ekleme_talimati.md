# Özetleri PDF'e Dönüştürme ve README Ekleme Talimatı

Aşağıdaki talimat, bir ders kaydı klasöründeki mevcut markdown çalışma özetlerini PDF formatına dönüştürmek ve ilgili klasör için standart bir `README.md` dizini oluşturmak amacıyla kullanılabilir.

## Talimat

Sana bir dersin/dönemin ders kayıtları dizini verilecek. Bu dizin içindeki mevcut çalışma özetlerini PDF'e dönüştür ve dizinin kök dizinine dersin genel bilgilerini ve özetlerini içeren standart bir `README.md` belgesi ekle.

Bu işlemleri gerçekleştirirken aşağıdaki kurallara kesinlikle uy:

### 1. PDF Dönüştürme Kuralları
- `altyazi_ozetleri/` klasörü altındaki her bir `.md` özet dosyasını (örneğin `ders_1_ozet.md`), kök dizinde aynı isimde bir `.pdf` dosyasına (örneğin `ders_1_ozet.pdf`) dönüştür.
- Dönüştürme işlemi için projede hazır bulunan `taslaklar/talimat_taslaklari/ozetleri_pdfe_donustur.py` betiğini kullan.
- Komut, proje kök dizininden şu formatta çalıştırılmalıdır:

```bash
python3 taslaklar/talimat_taslaklari/ozetleri_pdfe_donustur.py "[Hedef Dizin]"
```

- PDF dosyalarını güncel olsalar bile yeniden üretmek gerekiyorsa `--force` bayrağı eklenmelidir:

```bash
python3 taslaklar/talimat_taslaklari/ozetleri_pdfe_donustur.py "[Hedef Dizin]" --force
```

- Betik arka planda `pandoc` kullanır; bu nedenle PDF üretimi öncesinde sistemde `pandoc` bulunduğunu kontrol et. Betik başarısız olursa hata çıktısını incele ve PDF üretimini tamamlamadan README güncellemesine geçme.

### 2. README.md Oluşturma ve Yapısal Kurallar
- Kök dizine eklenecek `README.md` dosyası, ders ve dönemin genel bilgilerini, müfredatı ve her bir dersin detaylı özetlerini/kazanımlarını içermelidir.
- Dosya yapısı ve şablon referansı olarak aşağıdaki dizin yapısını kullan:

```
2022-2023/
├── altyazilar/                 # Ham altyazı dosyaları (.srt)
│   ├── README.md
│   ├── ders_1.srt
│   └── ...
├── altyazi_ozetleri/           # Markdown formatındaki çalışma özetleri (.md)
│   ├── ders_1_ozet.md
│   └── ...
├── ders_1_ozet.pdf             # Derlenmiş PDF çalışma dosyaları
├── ...
└── README.md                   # Dersin genel indeksi ve özetleri içeren ana README
```

- `README.md` içeriğinde şu bölümler yer almalıdır:
  1. **Başlık**: `# [Ders Adı] Ders Kayıtları & Çalışma Özetleri`
  2. **NotebookLM Önemli Notu**: Başlığın hemen altına dikkat çekici bir şekilde şu not eklenmelidir:
     > **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
  3. **Genel Bilgiler**: Ders adı, hoca adı, dönem ve akademik yıl.
     - 🔍 **Hoca Bilgisinin Okunması:** Hoca adını, `altyazilar/README.md` dosyası içindeki `* **Dersi Veren Akademisyen:** [Hoca Adı]` veya `* **Hoca:** [Hoca Adı]` alanından otomatik olarak oku. Eğer bu dosyadan hoca adı okunamıyorsa kullanıcıya sor.
  4. **Müfredat ve Belge Dizini Tablosu**: Ders no, ders içeriği/konu başlığı, markdown kaynak notu linki ve PDF indirme linkini içeren tablo.
  5. **Detaylı Özetler**: Her ders için genel konular (iç içe listeler/nested bullet points halinde detaylı açıklamalı), hocanın özellikle vurguladığı kısımlar (iç içe listeler halinde detaylı açıklamalı), daha uzun/detaylı açıklamalar ve NotebookLM kullanım notu.

### 3. README Güncelleme Scriptini Çalıştırma Kuralları
- Dersin `README.md` dosyası oluşturulduktan/güncellendikten ve `dersler.json` dosyası güncellendikten sonra, projedeki tüm dönem ve ana README dosyalarını otomatik olarak senkronize etmek için `readme_olustur/` dizini altındaki `readme_olustur.py` betiği çalıştırılmalıdır.
- Çalıştırma komutu: `python3 readme_olustur.py` (Çalışma dizini olarak `readme_olustur` klasörü seçilmelidir).

### 4. Commit Atma Kuralları
- PDF üretimi, kök `README.md`, `dersler.json` ve `readme_olustur.py` çıktıları tamamlandıktan sonra `git status` ile değişiklikleri kontrol et.
- Sadece bu işlemle ilgili dosyaları stage et; kullanıcının başka değişikliklerini commit'e dahil etme.
- Standart commit mesajı olarak şu kalıbı kullan:

```bash
git commit -m "özellik: [ders adı] özetleri pdfe dönüştürüldü"
```

## Kullanım

Hedef dizinin yolunu aşağıdaki formatta belirterek bu talimatı modele iletin:

```text
Hedef Dizin: [Buraya hedef dizinin mutlak yolu gelecek, örn: .../3-2/Yapay Zeka/ders_kayitlari/2022-2023]
```
