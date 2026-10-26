# Ders 8 Çalışma Özeti

## Genel Konular

- Dersin tarihi 31 Mart 2021 Çarşamba. Bu kayıt günün ikinci oturumudur: **Laboratuvar 1** açılış oturumu. Kayıt yaklaşık 13 dakikadır. Konu anlatılmadı.
  - Oturumu dersin hocası açtı. Asistan Toprak Hoca da katıldı. Toprak Hoca Zoom'a hocanın adıyla ("Ahmet Elbir") bağlanmıştı; hoca "iki tane Ahmet Elbir var" diye şaka yaptı.
- Laboratuvar 1 sorusu Online Yıldız'da "Laboratuvar 1" başlığıyla açıldı (`Lab1.rar`). Soru: Müşteri-Sipariş-Ürün uygulaması.
- Soru formatı
  - Bir UML diyagramı verildi. Get/set dışındaki metotlar açıklandı.
  - `Test` sınıfı (`main` metodu) ve beklenen çıktılar hazır verildi.
  - Öğrenci diğer üç sınıfı yazıp aynı çıktıyı üretmeye çalışır.
- Teslim kuralları ve süre

## Hocanın Özellikle Vurguladığı Kısımlar

- **`main` metodunu kendiniz yazmayın.** Dosyadakini kopyalayıp yapıştırın ve verilen çıktıyı elde edin.
- **Teslim:** Bütün projeyi export edin. Dosya adı öğrenci numaranız olsun (`numara.zip` veya `.rar`).
  - Export olmazsa `.java` kaynak dosyalarını sıkıştırıp yükleyin.
  - Yalnız `src` değil, bütün proje gönderilir.
- **Süre uzatılmıyor.** Bu kural bütün gruplar için geçerli, istisna yok.
  - Get/set, constructor ve `toString` için IDE'nin otomatik üretme özelliğini kullanarak zaman kazanın.
  - Süre bitmek üzereyken eksik de olsa elinizdekini yükleyin. Yalnız bir sınıf yazmış olsanız bile not alabilirsiniz.
- **Laboratuvardan muaf olanlar:** Göndermeleri durumunda değerlendirilmeyecek ve puan girilmeyecek. Karışıklık olmaması için göndermemeleri önerildi. Kendilerini test etmek için soruyu çözebilirler.
- Soruda en çok mantık gerektiren bir metot var (`kacSiparis`: bir ürün aynı siparişte birden fazla kez olabilir). Onu stratejinize göre önce veya sonra yazabilirsiniz.
- Kısıtlara ve söylenenlere dikkat ederseniz soru basittir. Uygulamada yapılan Kitap-Raf-Kitaplık örneğine çok benzer.
- Sorusu olmayanlar Zoom'dan çıkabilir. Sorun olursa Telegram'dan ulaşabilirsiniz.

## Kısa Tekrar Notları

- Laboratuvar: UML + açıklamalar + hazır `Test` sınıfı + beklenen çıktı.
- Görev: Kalan sınıfları yazıp aynı çıktıyı üretmek.
- Teslim: Projeyi export et, `öğrencinumarası.zip/rar` olarak Online Yıldız'a yükle.
- Süre uzatılmaz. Kısmi çözüm de yüklenmeli.
- Muaf öğrencilerin gönderimi notlandırılmaz.

## Detaylı Açıklamalar

### Laboratuvar 1 sorusu (NYP LAB-1, 31.03.2021)

Soru dosyası (`nyp.lab1-2021.pdf`) kayıtta yaklaşık 00:02:30'da ekranda gösterildi. Aşağıdaki bilgiler ekran karesinden alındı.

- UML: Üç sınıf vardır.
  - `Musteri`: `- ad: String`, `- soyad: String`, `- siparisler: Siparis[]`. Metotlar: `Musteri(String ad, String soyad)`, `siparisVer(int siparisNo, Urun urun)`, `siparisBilgisi(int siparisNo)`, `tumSiparisler()`, `kacSiparis(String urunAdi)`, `tumSiparislerdenUrunCikar(Urun urun)`, `urunCikar(int siparisNo, Urun urun)`, `getSiparisTutari(int siparisNo): double`.
  - `Siparis`: `- urunler: Urun[]`. Metotlar: `Siparis()`, `getUrunler(): Urun[]`, `urunEkle(Urun urun)`, `urunleriGoster()`, `urunCikar(Urun urun)`, `getToplamTutar(): double`.
  - `Urun`: `- ID`, `- ad`, `- fiyat`, `- zamSayisi <static>`. Metotlar: `Urun(int ID, String ad, double fiyat)`, `getAdi(): String`, `getID(): int`, `getFiyat(): double`, `setAd(String ad)`, `zamYap(double zamOrani)`, `getZamSayisi(): int`, `toString(): String`.
  - İlişkiler: `Musteri` - `Siparis` dolu elmas (bileşim). `Siparis` - `Urun` boş elmas (birleştirme).
- Kurallar:
  - Her müşterinin 3 siparişi, her siparişin 5 ürünü olmalı.
  - `siparisBilgisi`: verilen sipariş numarasındaki bütün ürünlerin bilgilerini yazdırır.
  - `tumSiparisler`: müşterinin bütün siparişlerindeki ürünleri sırayla yazdırır.
  - `kacSiparis`: verilen ürün adının kaç siparişte ve toplam kaç kez sipariş edildiğini yazdırır. Ürün bir siparişte birden fazla kez olabilir; dikkat edilmeli.
  - `urunCikar`: verilen sipariş numarasından ürünü çıkarır. `tumSiparislerdenUrunCikar`: ürünü bütün siparişlerden çıkarır.
  - `getSiparisTutari`: siparişteki ürünlerin fiyatlarını toplar, `double` döndürür.
  - `zamSayisi`: tek bir ürün için değil, bütün ürünler için toplam zam sayısını tutar (statik alan).
  - `toString` `Urun` sınıfında override edilmeli ve ürün bilgilerini içeren bir `String` döndürmeli.
- `main` metodunu içeren `Test` sınıfı ve beklenen çıktılar dosyanın sonraki sayfalarında verildi.
- Yapı, uygulamadaki Kitap-Raf-Kitaplık örneğinin aynısıdır: `Kitaplik` -> `Musteri`, `Raf` -> `Siparis`, `Kitap` -> `Urun`.

### Laboratuvar oturumunun akışı

- 00:00-00:01: Hoca öğrencilerin Online Yıldız'da "Laboratuvar 1" ödevini görüp görmediğini sordu. Toprak Hoca'yı bekledi.
- 00:01-00:03: Toprak Hoca formatı anlattı: UML veriliyor, get/set dışındaki metotlar açıklanıyor. Test sınıfı ve çıktıları veriliyor.
- 00:03-00:05: Muafiyet ve teslim soruları cevaplandı.
- 00:06-00:08: Süre ve IDE kısayolları hatırlatıldı.
- 00:08-00:13: Öğrenciler çıktı. Hocalar sistemde bitiş tarihini değiştirme ekranı çıkması gibi teknik bir konuyu konuştu. Gelen dosyaların indirilip Google Drive'dan paylaşılacağı söylendi.

### Laboratuvara hazırlık için öneriler

- Önceki uygulama örneklerini (Kitap-Yazar-Kütüphane ve Kitap-Raf-Kitaplık) tekrar yazın.
- NetBeans'te Insert Code (Alt+Insert) ile constructor, getter/setter ve `toString` üretmeyi deneyin.
- UML'den kod yazmayı çalışın. `-` private, `+` public, `ad: Tip` alan, `metot(param): DönüşTipi` metot demektir.

### Ders sonrası notlar

- Kayıt yalnız laboratuvar açılışını içerir; çözüm yapılmadı. Soru metni ekran karesinden okundu. Küçük yazılı UML kısımlarında harf hatası olabilir; asıl dosyayı esas alın.
- UML'de `Urun` alanlarının tipleri yazılmamış (`ID`, `ad`, `fiyat`). Constructor'dan tipler anlaşılıyor: `int ID`, `String ad`, `double fiyat`, `static int zamSayisi`.
- Oturum ekran saatine göre yaklaşık 18:57'de başladı. Süre bitişi için kayıtta "sekizi beş geçe" örneği geçiyor. Kesin teslim saatini Online Yıldız'daki ödev sayfasından kontrol edin.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
