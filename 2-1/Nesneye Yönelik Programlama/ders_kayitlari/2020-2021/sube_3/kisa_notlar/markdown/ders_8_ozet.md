# Ders 8 Çalışma Özeti

## Genel Konular

- Bu kayıt **Laboratuvar 1** açılış oturumudur. Kayıt yaklaşık 13 dakikadır. Konu anlatılmadı.
- Soru: Müşteri-Sipariş-Ürün uygulaması.
- Soru formatı
  - Bir UML diyagramı verildi. Get/set dışındaki metotlar açıklandı.
  - `Test` sınıfı (`main` metodu) ve beklenen çıktılar hazır verildi.
  - Öğrenci diğer üç sınıfı yazıp aynı çıktıyı üretmeye çalışır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Get/set, constructor ve `toString` için IDE'nin otomatik üretme özelliğini kullanarak zaman kazanın.
- Soruda en çok mantık gerektiren bir metot var (`kacSiparis`: bir ürün aynı siparişte birden fazla kez olabilir). <!-- BELİRSİZ: Altyazıda hoca yalnız "şu metod" diyor; metodun `kacSiparis` olduğu önceki nottandır, ekran karesi bu işte yok. -->
- Kısıtlara ve söylenenlere dikkat ederseniz soru basittir. Uygulamada yapılan Kitap-Raf-Kitaplık örneğine çok benzer.

## Kısa Tekrar Notları

- Soru biçimi: UML + açıklamalar + hazır `Test` sınıfı + beklenen çıktı.
- Görev: Kalan sınıfları yazıp aynı çıktıyı üretmek.

## Detaylı Açıklamalar

### Laboratuvar 1 sorusu

Soru dosyası kayıtta yaklaşık 00:02:30'da ekranda gösterildi.

<!-- BELİRSİZ: Aşağıdaki UML ve kurallar altyazıda okunmuyor. Önceki notun ekran karesinden aktardığı biçimdedir; bu işte kare yok, yeniden doğrulanamadı. -->

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

### Laboratuvara hazırlık için öneriler

- Önceki uygulama örneklerini (Kitap-Yazar-Kütüphane ve Kitap-Raf-Kitaplık) tekrar yazın.
- IDE'nin otomatik üretme özelliğiyle (NetBeans'te Insert Code) constructor, getter/setter ve `toString` üretmeyi deneyin.
- UML'den kod yazmayı çalışın. `-` private, `+` public, `ad: Tip` alan, `metot(param): DönüşTipi` metot demektir.

### Ders sonrası notlar

- Kayıt yalnız laboratuvar açılışını içerir; çözüm yapılmadı. Soru metni ekran karesinden okundu. Küçük yazılı UML kısımlarında harf hatası olabilir; asıl dosyayı esas alın.
- UML'de `Urun` alanlarının tipleri yazılmamış (`ID`, `ad`, `fiyat`). Constructor'dan tipler anlaşılıyor: `int ID`, `String ad`, `double fiyat`, `static int zamSayisi`.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
