# Ders 7 Çalışma Özeti

## Genel Konular

- Oturumun niteliği
  - Bu kayıt bir laboratuvar uygulaması oturumudur. Kayıtta konu anlatımı yoktur; asistan lab sorusunu ve UML sınıf diyagramını kısaca açıklar, soruları cevaplar, sonra oturumdan çıkar.
  - Soru, bir önceki uygulamadaki kitaplık örneğiyle aynı yapıdadır: birbiriyle ilişkili üç sınıf, benzer ilişkiler ve aynı mantıkta ekleme/çıkarma metotları.
- Lab sorusunun sistemi: çevrim içi market (ekrandan, 00:15:00)
  - Müşteriler sipariş verir, her siparişte ürünler bulunur. Yani bir müşterinin altında siparişler, siparişlerin içinde de ürünler vardır.
  - Sınıflar: `Musteri` (`ad: String`, `soyad: String`, `siparisler: Siparis[]`), `Siparis` (`urunler: Urun[]`), `Urun` (`ID`, `ad`, `fiyat`, `zamSayisi <static>`).
  - `Musteri` ile `Siparis` arasında içi dolu elmas (composition), `Siparis` ile `Urun` arasında içi boş elmas (aggregation) vardır.
- Sınıfların metotları (ekrandan, 00:15:00)
  - `Musteri`: `Musteri(String ad, String soyad)`, `siparisVer(int siparisNo, Urun urun)`, `siparisBilgisi(int siparisNo)`, `tumSiparisler()`, `kacSiparis(String urunAdi)`, `tumSiparislerdenUrunCikar(Urun urun)`, `urunCikar(int siparisNo, Urun urun)`, `getSiparisTutari(int siparisNo): double`.
  - `Siparis`: `Siparis()`, `getUrunler(): Urun[]`, `urunEkle(Urun urun)`, `urunleriGoster()`, `urunCikar(Urun urun)`, `getToplamTutar(): double`.
  - `Urun`: `Urun(int ID, String ad, double fiyat)`, `getAd(): String`, `getID(): int`, `getFiyat(): double`, `setAd(String ad)`, `zamYap(double zamOrani)`, `getZamSayisi(): int`, `toString(): String`.
- Sorunun kuralları (ekrandan, 00:15:00)
  - Her müşteri için 3 sipariş, her sipariş için 5 ürün tutulur. Önceki uygulamada raf sayısı constructor'a parametre olarak verilirken burada boyutlar sabittir; constructor'ın bu sayılar için parametre almasına gerek yoktur.
  - `siparisBilgisi` verilen sipariş numarasındaki ürünlerin bilgilerini, `tumSiparisler` müşterinin bütün siparişlerindeki ürünleri sırayla yazdırır.
  - `kacSiparis`, adı String olarak verilen ürünün kaç siparişte ve toplam kaç kez sipariş edildiğini yazdırır. Ürün her siparişte olmayabilir, bir siparişte birden fazla kez de bulunabilir.
  - `urunCikar` verilen sipariş numarasından, `tumSiparislerdenUrunCikar` bütün siparişlerden ürünü çıkarır.
  - `getSiparisTutari` verilen siparişteki ürünlerin fiyatlarını toplar ve `double` döndürür.
  - `zamSayisi` tek bir ürün için değil, bütün ürünler için toplam kaç kez zam yapıldığını tutar. `toString`, `Urun` sınıfında override edilip ürün bilgilerini içeren bir String döndürür.
- Hazır verilen test sınıfı (ekrandan, 00:10:00)
  - `main` içinde beş ürün ve bir müşteri oluşturulur, siparişler verilir, sipariş bilgileri yazdırılır, `kacSiparis("su")` çağrılır, iki ürüne zam yapılır, toplam zam sayısı `Urun.getZamSayisi()` ile yazdırılır, bir siparişten ürün çıkarılır.
  - Beklenen çıktılar soru PDF'inin ikinci ve üçüncü sayfalarında verilmiştir; yazılan metotlar bu çıktılarla karşılaştırılarak kontrol edilir.
  <!-- BELİRSİZ: Test sınıfının urunCikar satırından sonraki kısmı ve beklenen çıktı sayfaları karelerde okunmuyor. -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Ürün niteliklerinin tipleri test sınıfından çıkarılır
  - UML'de `Urun` niteliklerinin tipi yazılmamıştır. Test sınıfındaki `new Urun(91, "ekmek", 1.25)` çağrısından `ID`'nin `int`, `ad`'ın `String`, `fiyat`'ın `double` olduğu anlaşılır.
- `zamYap` ile `getZamSayisi` bağlantısı
  - `zamYap` her çalıştığında zam sayısı bir artırılır. Test sınıfının istediği şey `getZamSayisi` ile kaç kez zam yapıldığını görmektir.
- En zor metot `kacSiparis`
  - Ürün bütün siparişlerde olmayabilir; hem kaç siparişte geçtiği hem de toplam kaç kez sipariş edildiği sayılmalıdır. Bu metot en sona bırakılıp üzerinde ayrıca düşünülebilir.
- Test sınıfının adı serbesttir
  - Hazır verilen test sınıfının adı değiştirilebilir, önemli olan `main` çalıştırılınca istenen çıktıların üretilmesidir.

## Kısa Tekrar Notları

- Üç sınıf: `Musteri` → `Siparis[3]` (composition), `Siparis` → `Urun[5]` (aggregation).
- Dizi boyutları sabit; constructor içinde `new Siparis[3]`, `new Urun[5]` ve her sipariş nesnesi oluşturulur.
- `zamSayisi` static'tir, bütün ürünler için ortak sayaçtır; test onu sınıf adıyla (`Urun.getZamSayisi()`) çağırır, bu yüzden getter da static olmalıdır.
- `kacSiparis`: iki sayaç gerekir; sipariş sayısı ve toplam adet.
- `getSiparisTutari`: siparişteki `null` olmayan ürünlerin fiyat toplamı.
- `toString` override edilir.

## Detaylı Açıklamalar

- Bu lab sorusu, bir önceki uygulamadaki kitaplık-raf-kitap yapısının market-sipariş-ürün karşılığıdır. Orada raf sayısı kullanıcıdan alınıyordu; burada müşteri başına 3 sipariş ve sipariş başına 5 ürün sabittir. Bu yüzden `Musteri` constructor'ı yalnız ad ve soyadı alır, sipariş dizisini ve içindeki `Siparis` nesnelerini kendisi oluşturur. Bu, composition ilişkisinin anlamıyla örtüşür: siparişler müşteriyle birlikte doğar. Ürünler ise test sınıfında ayrı ayrı oluşturulup siparişlere eklenir, yani siparişten bağımsız yaşarlar (aggregation).
- `Urun` sınıfındaki `zamSayisi` static bir niteliktir. Asistanın açıkladığı gibi bu değer tek bir ürüne ait değildir; hangi ürün için `zamYap` çağrılırsa çağrılsın aynı sayaç bir artar. Test sınıfı `urun3.zamYap(0.05)` ve `urun5.zamYap(0.1)` çağrılarından sonra `Urun.getZamSayisi()` değerini "Toplam %d defa zam yapıldı." biçiminde yazdırır.
- `kacSiparis` metodunda müşterinin her siparişi gezilir, siparişin ürün dizisinde adı verilen ürünle aynı olanlar sayılır. Siparişte en az bir kez geçiyorsa sipariş sayacı bir artar, bütün geçişler toplam sayaca eklenir. Test sınıfındaki siparişlerle "su" ürünü 0 ve 1 numaralı siparişlerde, 1 numaralı siparişte iki kez olmak üzere toplam 3 kez geçer.
- Derste çözüm verilmemiştir. Genişletilmiş notta ajanın yazdığı ve `java Test.java` ile ekrandaki test girdileriyle çalıştırdığı bir çözüm yer alır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
