# Ders 23 Çalışma Özeti

## Genel Konular

- Oturumun niteliği
  - Bu kayıt kısa bir uygulama sınavı oturumudur. Konu anlatımı yoktur; sorunun mantığı ve hazır verilen test sınıfı ekranda açıklanır, sonra öğrenciler soruyu çözmeye bırakılır.
  - Soru tamamen dosyaya yazma ve okuma üzerine kuruludur: nesneler serileştirme (serialization) ile dosyaya kaydedilir, ters serileştirme (deserialization) ile dosyadan geri okunur.
- Sorunun sistemi: otel rezervasyonu (ekrandan, 00:10:00)
  - `Room` nesneleri iki parametreyle oluşturulur: oda numarası ve odanın gecelik ücreti. Örnek: `new Room(101,300)`, `new Room(201,1000)`.
  - `Customer` nesneleri dört parametreyle oluşturulur: kimlik numarası gibi müşteriye özel bir numara, müşterinin adı, kaç gün kalacağı ve hangi odada kalacağı (`Room` nesnesi). Örnek: `new Customer(345,"Frank Zone", 7, r3)`.
  - Müşteriler bir `LinkedList<Customer>` içine eklenir. Test kodunda dört müşteri oluşturulur, ama listeye yalnız ilk üçü (`c1`, `c2`, `c3`) eklenir.
  - İşlemler bir `Management` sınıfı üzerinden yürür: `new Management("Big Five Hotel")`.
- `Management` metotları (ekrandan, 00:05:00)
  - `saveBookings(list)`: müşteri listesini serileştirerek dosyaya kaydeder.
  - `customerInfo(Customer)`: dosyayı okur, ters serileştirir ve müşterinin bilgilerini ekrana basar. Bilgi kaydedilen dosyadan okunmalıdır.
  - `changeBooking(Customer, int)`: müşterinin kalacağı gün sayısını yeni değerle değiştirir ve bu değişikliği dosyaya yansıtır.
- Beklenen çıktı
  - Listede olmayan müşteri (`c4`) için müşterinin bulunamadığı yazılır.
  - Listede olan müşteri için ad, oda numarası, kalınacak gün sayısı ve toplam ücret (Total Cost) yazılır. Toplam ücret = gün sayısı × odanın gecelik ücreti.
  - `c3` için önce 7 gün × 1000 = 7000, `changeBooking(c3, 10)` sonrası 10 gün × 1000 = 10000 görünür. Ekrandaki çıktının sonunda `Total Cost: 10000.0` satırı vardır (ekrandan, 00:15:00).
  <!-- BELİRSİZ: Soru PDF'indeki beklenen çıktının tamamı (etiket metinleri ve "bulunamadı" mesajı) karelerde görünmüyor; yalnız son "Total Cost: 10000.0" satırı okunuyor. -->

## Hocanın Özellikle Vurguladığı Kısımlar

- Parametrelerin anlamı
  - Açıklama PDF'inde `Room` ve `Customer` parametrelerinin anlamı yazılmadığı için ayrıca söylendi: `Room(oda numarası, gecelik ücret)`, `Customer(numara, ad, gün sayısı, oda)`. Müşteri numarasının soruda pek bir işlevi yoktur.
- Bilgiler dosyadan okunmalı
  - `customerInfo` bilgiyi bellekteki nesneden değil, `saveBookings` ile kaydedilen dosyadan ters serileştirerek almalıdır.
- `changeBooking` aynı dosyayı yeniden yazar
  - Değişiklikten sonra dosya baştan, komple yeniden yazılabilir. Yeni bir dosya açılmaz; aynı dosyadaki veri değiştirilir. Sonra `customerInfo` çağrılınca değişmiş bilgi gelmelidir.
- Listede olmayan müşteri
  - `c4` bilerek listeye eklenmemiştir; dosyada bulunmadığı için "böyle bir müşteri yok" çıktısı beklenir.

## Kısa Tekrar Notları

- Serileştirilecek sınıflar (`Customer` ve içindeki `Room`) `Serializable` olmalıdır.
- Kaydetme: `ObjectOutputStream` + `writeObject(list)`. Okuma: `ObjectInputStream` + `readObject()` ve `LinkedList<Customer>` tipine dönüşüm.
- Toplam ücret = gün sayısı × gecelik ücret.
- Gün değişikliğinde: dosyayı oku, müşteriyi bul, gün sayısını değiştir, listeyi aynı dosyaya yeniden yaz.
- Dosyadan okunan nesneler yeni nesnelerdir; aranan müşteri referansla (`==`) değil, numarası gibi bir alanla bulunmalıdır (ajan notu, derste söylenmedi).

## Detaylı Açıklamalar

- Test sınıfı (ekrandan, 00:05:00 ve 00:10:00)

```java
import java.util.LinkedList;

public class Test {
    public static void main(String[] args) {
        Room r1 = new Room(101,300);
        Room r2 = new Room(102,500);
        Room r3 = new Room(201,1000);
        Room r4 = new Room(202,2000);

        Customer c1 = new Customer(123, "Joe Deen", 5, r1);
        Customer c2 = new Customer(234,"Zoey Cripp", 3, r2);
        Customer c3 = new Customer(345,"Frank Zone", 7, r3);
        Customer c4 = new Customer(456, "Alan Stanley", 10, r4);

        LinkedList <Customer> list = new LinkedList<>();
        list.add(c1);
        list.add(c2);
        list.add(c3);

        Management mng = new Management("Big Five Hotel");
        mng.saveBookings(list);

        mng.customerInfo(c4);

        System.out.println("**************************");
        mng.customerInfo(c3);

        System.out.println("**************************");
        mng.changeBooking(c3, 10);
        mng.customerInfo(c3);
        System.out.println("**************************");
    }
}
```

- Akış
  - Önce dört oda ve dört müşteri oluşturulur, ilk üç müşteri listeye konur ve liste `saveBookings` ile dosyaya serileştirilir.
  - `customerInfo(c4)` dosyayı okur; `c4` dosyada olmadığı için bulunamadı mesajı basılır.
  - `customerInfo(c3)` dosyadan okunan müşterinin adını, 201 numaralı odayı, 7 günü ve 7 × 1000 = 7000 toplam ücreti basar.
  - `changeBooking(c3, 10)` gün sayısını 10 yapar ve dosyayı yeniden yazar. Ardından `customerInfo(c3)` aynı dosyadan okuduğu için 10 günü ve 10 × 1000 = 10000 toplam ücreti basar.
- Çözüm derste verilmedi. Ajanın yazdığı ve `java Test.java` ile denenen bir çözüm, beklenen değerleri (bulunamadı, 7000.0, 10000.0) üretmiştir; kod genişletilmiş notta yer alır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
