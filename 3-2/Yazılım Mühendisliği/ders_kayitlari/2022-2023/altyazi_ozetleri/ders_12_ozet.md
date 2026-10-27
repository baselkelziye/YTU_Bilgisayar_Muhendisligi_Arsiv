# Ders 12 Çalışma Özeti

## Genel Konular

- Kayıt 17 Mayıs 2023 Çarşamba günü online yapılan uygulama dersine ait, yaklaşık 56 dakika sürüyor.
- Hoca dersi açıyor ve uygulamayı bir araştırma görevlisine bırakıyor. Uygulamayı asistan anlatıyor.
- Tek bir senaryo üzerinden dört UML diyagramı çiziliyor: sınıf diyagramı (class diagram), sıralama diyagramı (sequence diagram), etkinlik diyagramı (activity diagram) ve durum diyagramı (state diagram).
- Senaryo: otobüs bileti satış sistemi. Yolcu sefer, otobüs ve koltuk seçer, rezervasyon yapar, ödeme yapar.
- Diyagramlar Violet UML Editor ile çiziliyor.

## Hocanın Özellikle Vurguladığı Kısımlar

- Diyagramlar birbirine **tutarlı** olmalı. Sıralama diyagramındaki mesajlar, sınıf diyagramındaki metotlardan seçilir.
- Sınıf diyagramında nitelikler (attributes) genellikle private (`-`), onlara erişen metotlar public (`+`) gösterilir.
- Otobüs ile koltuk arasındaki ilişki güçlü olduğu için **bileşim (composition)** seçildi. Koltuk otobüsten bağımsız var olamaz.
- Sıralama diyagramında nesneler yatay eksende, zaman dikey eksende ilerler. Her nesnenin bir yaşam çizgisi (lifeline) ve etkinlik çubukları (activation bar) vardır.
- Etkinlik diyagramı adımları yukarıdan aşağı sırayla verir. Sistemin karar vermesi gereken yerler karar düğümüyle (decision) gösterilir.
- Durum diyagramı tek bir nesnenin durumlarını ve durumlar arasındaki geçiş kurallarını anlatır. Bu soruda nesne **koltuk**tur.

## Kısa Tekrar Notları

- **Senaryo özeti:**
  - Birinci aktör: yolcu. Diğer ilgili: bilet satış sistemi.
  - Ön koşul: tüm sefer bilgileri sisteme girilmiş. Son koşul: yolcu biletini satın almış.
  - Ana akış: seyahat bilgilerini gir, seferleri gör, otobüs seç, koltuk seç (sistem uygunluğu kontrol eder), rezervasyon bilgilerini gir (koltuk rezerve olur), ödeme yap (koltuk biletlenir).
  - Alternatif 1: yolcu uygun olmayan (ör. dolu) bir koltuk seçerse sistem izin vermez ve yeni koltuk ister.
  - Alternatif 2: yolcu sefere 12 saat kalana kadar ödeme yapmazsa rezervasyon iptal edilir ve koltuk yeniden boş işaretlenir.
- **Sınıflar (7 adet):** Yolcu, RezervasyonEkranı, Sefer, Rezervasyon, Ödeme, Otobüs, Koltuk.
- **İlişkiler:** Yolcu → RezervasyonEkranı → Rezervasyon → Ödeme; RezervasyonEkranı → Sefer → Otobüs; Otobüs ◆— Koltuk (bileşim).
- **Koltuğun durumları:** Boş → Rezervasyon → Biletli.

## Detaylı Açıklamalar

### 1. UML sınıf diyagramı

- Ekrandaki diyagram (kareden alındı):

```
Yolcu
  - ad: String
  - soyad: String
  - tcNo: String
  + getAd(): String
  + getSoyad(): String
  + getTcNo(): String

RezervasyonEkranı
  - seferler: Sefer()
  + seferAra(gidis: String, varis: String, gun: Date): boolean
  + gosterSeferBilgileri(sefer: Sefer): void
  + otobüsSec(busX: Otobüs): void
  + koltukSec(koltukY: Koltuk): void

Sefer
  - cıkısYeri: String
  - varısYeri: String
  - tarih: Date
  - otobüs: Otobüs
  + Sefer(cıkıs: String, varıs: String, tarih: Date, ...)
  + seferBilgileriniAl(): Sefer

Rezervasyon
  - rezervasyonNo: int
  - odeme: Odeme
  + rezervasyonYap(yolcu: Yolcu, sefer: Sefer, koltuk: Koltuk): void
  + odemeYap(rezervasyonNo: int): void

Ödeme
  - odemeTarihi: Date
  - odemeTutarı: double
  odemeAl(): void

Otobüs
  - plaka: String
  - koltuklar: Koltuk()
  + getPlaka(): String

Koltuk
  - koltukNo: int
  - koltukTipi: String      (tekli, çiftli)
  - boslukDurumu: boolean
```

- İlişkiler:
  - Yolcu ile RezervasyonEkranı arasında ilişki (association).
  - RezervasyonEkranı ile Rezervasyon ve Sefer arasında ilişki.
  - Rezervasyon ile Ödeme arasında ilişki. Ödeme ayrı sınıf, çünkü 12 saatlik ödeme kuralının takibi gerekiyor.
  - Sefer ile Otobüs arasında ilişki.
  - Otobüs ile Koltuk arasında bileşim. Elmas Otobüs tarafında.

### 2. UML sıralama diyagramı

- Nesneler üstte yatay dizilir: `yolcu:Yolcu`, `:RezervasyonEkranı`, `Sefer`, `busX:Otobüs`, `koltukY:Koltuk`, `:Rezervasyon`.
- Mesajlar sınıf diyagramındaki metotlarla eşleşir:

```
yolcu -> RezervasyonEkranı : seferAra(parametreler)
RezervasyonEkranı --> yolcu : true
RezervasyonEkranı -> Sefer : seferBilgileriniAl()
Sefer --> RezervasyonEkranı : sefer
RezervasyonEkranı -> RezervasyonEkranı : gosterSeferBilgileri(sefer)   (kendine mesaj)
yolcu -> RezervasyonEkranı : otobüsSec(busX)
RezervasyonEkranı -> busX : bosKoltuklarıListele()
busX -> koltukY : getBoslukDurumu()
koltukY --> busX : boslukbilgisi
busX --> RezervasyonEkranı : koltukBilgileri
yolcu -> RezervasyonEkranı : koltukSec(koltukY)
RezervasyonEkranı -> Rezervasyon : rezervasyonYap(yolcu, sefer, koltukY)
Rezervasyon --> RezervasyonEkranı : rezervasyonOnayı
```

- Bir nesnenin kendi içinde yaptığı iş (ör. sefer bilgilerini göstermek) kendine dönen bir mesajla ve iç içe bir etkinlik çubuğuyla gösterilir.
- Çağrı mesajı düz çizgi ve dolu okla, dönüş mesajı (return message) kesikli çizgiyle çizilir.

### 3. Etkinlik diyagramı

- Akış:

```
(başla)
-> Yolcu sisteme girer
-> Yolcu sefer bilgilerini girer
-> Sistem sefer bilgisini kontrol eder
-> <karar> sefer var mı?
     hayır -> Sefer bilgisi yok, geri dön
     evet  -> Sefer bilgisi gösterilir
-> Yolcu seferleri görür ve otobüs seçer
-> Boş koltuk bilgileri kullanıcıya verilir
-> Kullanıcı koltuğunu seçer
-> İletişim bilgileri girilir
-> Rezervasyon yapılır
-> Kullanıcı rezervasyonu onaylar
(bitir)
```

### 4. Durum diyagramı (koltuk)

- Ekrandaki diyagram (kareden alındı):

```
(başla) --[yolcu otobüsü seçer ve boş koltuk bilgilerini görüntüler]--> Boş
Boş --[yolcu iletişim ve koltuk bilgilerini girer]--> Rezervasyon
Rezervasyon --[sefer başlangıcına 12 saat kalana kadar ödeme gerçekleştirmedi]--> Boş
Rezervasyon --[yolcu ödeme yaptı]--> Biletli
Biletli --[koltuk dolu, başkasına verilemez]--> (bitir)
```

- 12 saat kuralı, sefere 12 saat kalana kadar ödeme yapılması gerektiği anlamına gelir. Asistan derste bunu "12 saat içinde" diye söyleyip düzeltti.

### Ders sonrası notlar

- Sınıf diyagramında `seferler: Sefer()` ve `koltuklar: Koltuk()` yazımı UML'de doğru değil. Çoklu nitelik `seferler: Sefer[*]` veya `koltuklar: List<Koltuk>` gibi gösterilir.
- `seferAra(...)` metodunun dönüş tipi `boolean` olarak yazılmış. Senaryoda bu metodun seferleri listelemesi beklendiği için `List<Sefer>` gibi bir dönüş tipi daha uygun olur.
- Rezervasyon sınıfında yolcu, sefer ve koltuk yalnızca `rezervasyonYap` parametresi olarak var. Rezervasyonun kime ve hangi koltuğa ait olduğunu saklayabilmesi için bunların nitelik ya da ilişki olarak tutulması gerekir. 12 saat kuralı için rezervasyon zamanı da saklanmalıdır.
- `odemeAl()` metodunun önünde görünürlük işareti eksik; diğerleri gibi `+` olmalı.
- Sefer sınıfında hem `otobüs: Otobüs` niteliği hem de Otobüs'e çizilmiş bir ilişki var. UML'de ikisinden biri yeterlidir; ilişki çizildiyse aynı bilgi ayrıca nitelik olarak yazılmaz.
- Sıralama diyagramında ödeme adımı (`odemeYap`, `odemeAl`) ve iki alternatif akış gösterilmedi. Alternatifler `alt` çerçevesiyle (combined fragment) eklenebilir.
- Etkinlik diyagramında da dolu koltuk seçme ve 12 saat içinde ödememe alternatifleri ile ödeme adımı yer almıyor. Senaryonun tamamı için bunların karar düğümleriyle eklenmesi gerekir.
- Altyazıdaki "UMS sınıf şeması" UML, "plussac/klas" class demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
