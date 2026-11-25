# Ders 11 Çalışma Özeti

## Genel Konular

- Kitaplık uygulamasının genişletilmiş UML sınıf diyagramı
  - Ekrandaki diyagramda önceki uygulamadaki `Kitaplik`, `Raf`, `Kitap` sınıflarına ek olarak `Kart` (soyut), `YetiskinKartı`, `OgrenciKartı` ve `KitaplıkYonetim` sınıfları vardır (ekrandan, 00:05:00).
  - `Kart`: `- id: int`, `- Sahip: String`, `- Bakiye: double`; `+ getId(): int`, `+ getSahip(): String`, `+ getBakiye(): double`, `+ setBakiye(double)`, `+ toString(): String`, `+ odemeYap(double): <<abstract>>boolean`. Kutunun başlığında `<<abstract>>` yazar.
  - `YetiskinKartı`: ek nitelik yok; `+ YetiskinKartı(int,String,double)`, `+ odemeYap(double): boolean`.
  - `OgrenciKartı`: `- bonus: double`; `+ OgrenciKartı(int,String,double)`, `+ odemeYap(double): boolean`.
  - `KitaplıkYonetim`: `- Kitaplık: kitaplık`; `+ kitapSat(kitap, kart): boolean`, `+ KitaplıkYonetim(Kitaplık)`.
  - `Kitaplik` sınıfına `+ kitapSat(kitap, kart): boolean` eklenmiştir (ekrandan, 00:05:00).
- Diyagramdaki bağlantılar
  - Ucu içi boş üçgen olan ok kalıtımı gösterir: `YetiskinKartı` ve `OgrenciKartı`, `Kart` sınıfından kalıtım alır.
  - İçi dolu elmas (`Kitaplik` — `Raf`): composition. Kitaplık nesnesi silinirse raflar da etkilenir; raflar kitaplığın yapıcısı içinde oluşturulur.
  - İçi boş elmas (`Raf` — `Kitap`): aggregation. Kitaplar rafın içinde değil, başka yerde (test sınıfında) oluşturulur; aralarında yalnız mantıksal bir ilişki vardır.
  - Düz oklu çizgi (`KitaplıkYonetim` → `Kitaplik`): ilişki. `KitaplıkYonetim` sınıfının `Kitaplik` türünde bir niteliği vardır.
  - Kesikli ok (`KitaplıkYonetim` → `Kart`): bağımlılık. `KitaplıkYonetim` kart türünde bir nitelik tutmaz, kartı yalnız kullanır (metot parametresi olarak alır).
- Kalıtım (inheritance)
  - Alt sınıf, üst sınıfın niteliklerine ve metotlarına sahip olur. Ortak nitelikler (`id`, `Sahip`, `Bakiye`) yalnız `Kart` içinde bir kez tanımlanır, her kart türünde tekrar yazılmaz.
  - Değişiklik tek yerden yapılır; kodun geliştirilmesi ve bakımı kolaylaşır.
  - Java'da `class YetiskinKartı extends Kart` biçiminde `extends` anahtar kelimesiyle yazılır (ekrandan, 00:35:00).
  - Alt sınıf kendine özgü nitelik ekleyebilir: `OgrenciKartı`'ndaki `bonus`.
- `super` anahtar kelimesi
  - `super(id, Sahip, Bakiye);` üst sınıfın yapıcı fonksiyonunu çağırır ve parametreleri ona gönderir (ekrandan, 00:35:00).
  - Atamalar `Kart` sınıfının içinde yapılır; bu yüzden private nitelikler alt sınıftan doğrudan erişilmeden doldurulur.
  - `super.toString()` üst sınıfın `toString` metodunu çalıştırır.
- Soyut (abstract) sınıf ve soyut metot
  - `public abstract boolean odemeYap(double fiyat);` yalnız prototiptir, gövdesi yoktur (ekrandan, 00:30:00).
  - Soyut sınıftan kalıtım alan her somut alt sınıf bu metodu kendi içinde override etmek, yani gövdesini yazmak zorundadır. Böylece her kart türü kendi ödeme biçimini tanımlar.
  - Soyut sınıftan nesne oluşturulamaz: `new OgrenciKartı(...)` yazılabilir, `new Kart(...)` yazılamaz.
- Üst sınıf türünde değişkenle alt sınıf nesnesi tutmak
  - `Kart hesap1 = new OgrenciKartı(0,"Ali",50);` ve `Kart hesap2 = new YetiskinKartı(1,"Ayse",50);` (ekrandan, 00:25:00).
  - Öğrenci kartı aynı zamanda bir karttır; bu yüzden `Kart` türünde bir değişkenle tutulabilir. `OgrenciKartı hesap1 = ...` yazmak da aynı sonucu verir.
  - Aralarında kalıtım olmayan türler arasında atama yapılamaz: `OgrenciKartı` türünde değişkene `YetiskinKartı` nesnesi atanamaz.
- Erişim belirleyiciler ve kalıtım
  - Alt sınıf üst sınıfın public metotlarını kendi metoduymuş gibi çağırır: `OgrenciKartı` içinde `getBakiye()` yazılmamıştır ama çağrılabilir.
  - Private nitelik alt sınıftan doğrudan kullanılamaz: alt sınıfta `id = 5;` yazılınca Eclipse "The field Kart.id is not visible" hatası verir (derste denendi, 00:31:57).
  - Protected üye alt sınıflardan erişilebilir.
  - Ders sonrası not: Derste protected üyeye `Test` sınıfından erişilemeyeceği söylendi. Java'da protected üyeye aynı paketteki her sınıftan da erişilir; bu projede `Test` ve `Kart` aynı pakette (`javaapplication6`) olduğundan erişim mümkündür. Erişimi yalnız alt sınıflarla sınırlamak, farklı paketteki sınıflar için geçerlidir. Ajan aynı paketteki bir sınıftan protected alana erişimi `java` ile denedi, hata çıkmadı.
- `toString` override'ı ve kalıtım
  - `YetiskinKartı` `toString`'i override etmez; yine de `System.out.println(hesap2)` `Kart` sınıfındaki override edilmiş `toString`'i kullanır: `Hesap{id=1, Sahip=Ayse, Bakiye=50.0}` (ekrandan, 00:25:00).
  - `OgrenciKartı` `toString`'i yeniden override eder: `super.toString()` sonucuna `" bonus="` ve bonus değerini ekler: `Hesap{id=0, Sahip=Ali, Bakiye=50.0} bonus=0.0` (ekrandan, 00:25:00).
- Kitap satışı akışı (`KitaplıkYonetim.kitapSat`)
  - Kitabın adı `getAd()` ile alınır, `kitaplık.kitapAra(ad)` ile kitabın bulunduğu raf numarası bulunur; kitap yoksa `false` döner.
  - `kitapAra` bütün rafları ve raflardaki kitapları dolaşır; `kitap != null && kitap.getAd().equals(KitapAdı)` ise "i. Rafta Kitap var." yazıp raf numarasını, bulamazsa "Kitap Yok" yazıp `-1` döndürür (ekrandan, 00:40:00).
  - Kitap varsa fiyatı `getFiyat()` ile alınır ve kartın `odemeYap(fiyat)` metodu çağrılır. Nesne öğrenci kartı olduğu için `OgrenciKartı`'nın metodu çalışır.
  - Ödeme gerçekleşirse "Satış Gerçekleşti." yazılır ve kitap `kitapSil(rafNo, kitap)` ile raftan kaldırılır (raftaki eleman `null` yapılır); gerçekleşmezse "Bakiye Yetersiz." yazılır.
- Ödeme biçimleri
  - `YetiskinKartı.odemeYap`: bakiye fiyata yetiyorsa `setBakiye(getBakiye() - fiyat)` ve `true`, yoksa `false` (ekrandan, 00:35:00).
  - `OgrenciKartı.odemeYap` (anlatımdan): bakiye yetiyorsa bakiyeden düşer ve fiyatın %20'si kadar bonus kazanılır; bakiye yetmiyorsa bonus fiyata yetiyorsa ödeme bonustan yapılır; ikisi de yetmiyorsa `false`. <!-- BELİRSİZ: OgrenciKartı kodu karelerde görünmüyor; ayrıntı yalnız anlatımdan. -->
- Fonksiyon aşırı yükleme (overloading)
  - Aynı adla, farklı sayıda ya da farklı türde parametre alan birden çok metot yazılabilir.
  - Yalnız dönüş türü farklı olan iki metot aşırı yükleme sayılmaz; derleyici "metot zaten tanımlı" hatası verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kalıtım çok önemlidir
  - Ortak nitelik ve metotların tek bir üst sınıfta toplanması, on sınıfta aynı şeyi tekrar yazmaktan kurtarır ve değişikliği tek yerden yapmayı sağlar.
- Soyut metot alt sınıfa bir zorunluluk getirir
  - "Benden kalıtım alacaksan `odemeYap` diye bir fonksiyon oluşturup override etmen lazım."
- Soyut sınıf kullanmanın amacı
  - `abstract` yazılmasa da kalıtım alınabilirdi. `abstract`, başkasının kullanacağı bir kütüphanede "bu sınıftan nesne oluşturulmaz" kuralını açıkça koymak içindir.
- Her niteliğe otomatik getter ve setter yazmak
  - Her private niteliğe hem `get` hem `set` yazılırsa nitelik public yapılmış gibi olur. Değiştirilmesi istenmeyen nitelik için yalnız `get` yazılır (örneğin `Kitap` sınıfında `getFiyat` var, `setFiyat` yok).
- UML ile kod tutarlı olmalı
  - Yapıcı fonksiyon zorunlu değildir; ama UML diyagramında bir yapıcı gösterilmişse kodda da yazılmalıdır.

## Kısa Tekrar Notları

- UML'de kalıtım: alt sınıftan üst sınıfa ucu içi boş üçgen ok.
- `<<abstract>>` sınıf: nesnesi oluşturulamaz, yalnız kalıtım için.
- Soyut metot: gövdesiz prototip; somut alt sınıf override etmek zorunda.
- `extends`: kalıtım; `super(...)`: üst sınıfın yapıcısı; `super.metot()`: üst sınıfın metodu.
- `Kart k = new OgrenciKartı(...)` geçerlidir; birbirinden kalıtım almayan kardeş sınıflar arasında atama yapılamaz.
- Private nitelik alt sınıftan görünmez; public ve protected üyeler alt sınıfta kullanılabilir.
- Override edilmemiş metot üst sınıftan miras alınır (`YetiskinKartı` ve `toString`).
- `println(nesne)` gizlice `toString()` çağırır.
- Aşırı yükleme: aynı ad, farklı parametre sayısı ya da türü; yalnız dönüş türünü değiştirmek yetmez.
- Kesikli ok bağımlılık (yalnız kullanma), düz ok ilişki (nitelik olarak tutma), dolu elmas composition, boş elmas aggregation.

## Detaylı Açıklamalar

- Bu oturum, önceki uygulamada kurulan kitaplık projesinin devamıdır. Önce önceki uygulamanın kodu kısaca tekrar edildi: `Kitaplik` yapıcısı `Raf` dizisini oluşturup her elemana `new Raf()` atar; `Raf` yapıcısı ise yalnız `new Kitap[10]` ile on elemanlı boş bir dizi oluşturur, elemanlara kitap atamaz (ekrandan, 00:20:00). Bu fark UML'deki dolu elmasa (composition) ve boş elmasa (aggregation) karşılık gelir. Kitaplar test sınıfında oluşturulup `kitaplık.kitapEkle(kitap, rafNo)` ile raflara konur; `Raf.kitapEkle` dizide ilk `null` elemanı arar ve kitabı oraya yazar. `tumRaflariGoster` her raf için "i. Raftaki Kitaplar" başlığını ve `rafGoster(i)` çıktısını yazar; boş yerler `null` olarak görünür.
- Yeni uygulamada kart sistemi eklendi. `Kart` soyut sınıfı ortak üç niteliği (`id`, `Sahip`, `Bakiye`), yapıcıyı, getter'ları, `setBakiye`'yi ve soyut `odemeYap` metodunu içerir (ekrandan, 00:30:00):

  ```java
  public abstract class Kart {

      private int id;
      private String Sahip;
      private double Bakiye;

      public Kart(int id, String Sahip, double Bakiye) {
          this.id = id;
          this.Sahip = Sahip;
          this.Bakiye = Bakiye;
      }

      public int getId() {
          return id;
      }

      public String getSahip() {
          return Sahip;
      }

      public double getBakiye() {
          return Bakiye;
      }

      public void setBakiye(double Bakiye) {
          this.Bakiye = Bakiye;
      }

      public abstract boolean odemeYap(double fiyat);
      // ... (toString karede görünmüyor)
  }
  ```

- `YetiskinKartı` yalnız yapıcıyı ve `odemeYap`'ı yazar (ekrandan, 00:35:00):

  ```java
  public class YetiskinKartı extends Kart{

      public YetiskinKartı(int id, String Sahip, double Bakiye) {
          super(id, Sahip, Bakiye);
      }

      @Override
      public boolean odemeYap(double fiyat) {
          if (getBakiye() >= fiyat){
              setBakiye(getBakiye() - fiyat);
              return true;
          }
          else{
              return false;
          }
      }

  }
  ```

  Ajan bu iki sınıfı (paket satırı çıkarılarak, küçük bir `main` ile) tek dosyada `java` ile çalıştırdı; 50 bakiyeli kartla 30'luk ilk ödeme `true` ve bakiye 20.0, ikinci ödeme `false` sonucunu verdi. Ayrıca `new Kart()` yazmanın "Kart is abstract; cannot be instantiated" hatası verdiği doğrulandı. (Ortamda `javac` yok; `java Dosya.java` tek dosya kipi kullanıldı.)
- Test sınıfında iki hesap oluşturulur: `Kart hesap1 = new OgrenciKartı(0,"Ali",50);` ve `Kart hesap2 = new YetiskinKartı(1,"Ayse",50);`. Yorum satırına alınmış alternatifler `OgrenciKartı hesap1 = ...` ve `YetiskinKartı hesap2 = ...` biçimindedir; ikisi de aynı nesneyi oluşturur (ekrandan, 00:25:00). Sonra `kitaplıkYonetim.kitapSat(kitap1, hesap1)` ... `kitapSat(kitap5, hesap1)`, `println(hesap1)`, `kitapSat(kitap6, hesap1)`, `println(hesap1)` çağrılır; aynı dizi `hesap2` için tekrarlanır (ekrandan, 00:45:00).
- Anlatıma göre öğrenci kartında başta bakiye 50, bonus 0 iken beş kitap satışından sonra bakiye 0, bonus 10 olur; bu, harcanan 50'nin %20'sidir. Ardından kitap 6 bonusla ödenir ve bonus 0'a iner. Yetişkin kartında bakiye 50'den 0'a düşer (`Hesap{id=1, Sahip=Ayse, Bakiye=0.0}`) ve son satış "Bakiye Yetersiz." ile sonuçlanır (ekrandan, 00:50:00). <!-- BELİRSİZ: Kitap fiyatları karelerde görünmüyor; öğrenci kartı ara sonuçları anlatımdan alındı. -->
- Aşırı yükleme Eclipse'te küçük bir örnekle gösterildi: parametresiz aynı imzalı iki static metot yazılınca "iki kere tanımlandı" hatası çıktı; birine `String s` parametresi verilince hata kalktı. Yalnız dönüş türünü `String`'den `int`'e çevirmek hatayı gidermedi. Sonra parametresiz, `(String s, String y)` ve `(int s, int y)` alan aynı adlı metotlar birlikte yazılabildi. <!-- BELİRSİZ: Metotların adı ve gövdesi altyazıdan çıkmıyor, karesi yok. --> Ajan aynı durumu tek dosyalık bir Java programıyla denedi: üç aşırı yüklenmiş metot derlenip çalıştı, yalnız dönüş türü farklı ikinci metot "method f() is already defined" hatası verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
