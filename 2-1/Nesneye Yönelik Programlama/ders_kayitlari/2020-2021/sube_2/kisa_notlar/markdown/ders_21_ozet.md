# Ders 21 Çalışma Özeti

## Genel Konular

- Multitasking, multithreading, process ve thread
  - Multitasking: bir bilgisayarda aynı anda birden fazla programın çalışmasıdır. Tek çekirdekte bile görevler sırayla, kısa sürelerle çalıştırılarak yapılabilir; hızlı geçiş yüzünden paralelmiş gibi görünür.
  - Multithreading: bir program akışında birden fazla iş parçacığı (thread) ile aynı anda birden fazla iş yapmaktır. Birden fazla çekirdek varsa görevler gerçekten paralel çalışır.
  - Bu kavramlar işletim sistemi düzeyinde tanımlanır; programlama dilleri işletim sisteminin bu yeteneklerini kullanır.
  - Örnek: bir web sayfası açılırken betiklerin çalışması ve resimlerin indirilip çizilmesi aynı anda yapılırsa sayfa daha çabuk tamamlanır.
  - Derleyici ve mikroişlemci, birbirine bağımlı olmayan komutları (örneğin `x = x + 2` ile `y = y / 3`) kendiliğinden sıra dışı ya da paralel yürütebilir. Algoritmayı bilinçli olarak paralel görevlere ayırmak ise kesin bir performans kazancı getirir.
- Paralel programlamanın temel sorunu ve hızlanma sınırı
  - Ortak paylaşılan kaynaklara eş zamanlı erişimde tutarlılık sorunları çıkar. Literatürde bunun için monitör ve semafor gibi yapılar vardır; bu derste yalnız Java'nın desteklediği nesne kilidi mantığına kadar gidilecek.
  - İşi 4 paralel parçaya ayırmak 4 kat hızlanma getirmez: thread açma ve başlatmanın ek yükü vardır, hızlı biten thread'ler yavaş olanı beklemek zorunda kalabilir. Hızlanma çarpanı thread sayısından küçüktür.
- Thread'in yaşam döngüsü (ekrandan, 00:15:00; slayt 211)
  - `new` ile oluşturulan thread "new" durumundadır, hemen çalışmaz.
  - `start` ile "runnable" (çalışabilir) durumuna geçer ve işletim sisteminin zamanlayıcısını (scheduler) bekler.
  - Scheduler seçince "running" durumuna geçer. Time slice (zaman dilimi) dolunca ya da thread `yield` ile gönüllü olarak bırakınca tekrar runnable olur.
  - G/Ç işlemi, `sleep`, `wait` ya da `join` beklerken "blocked" durumuna geçer. `notify`/`notifyAll`, G/Ç'nin tamamlanması, uyku süresinin bitmesi ya da join'in tamamlanmasıyla doğrudan running'e değil, runnable'a döner.
  - İşi bitince sonlanır ("dead"); sistem kaynakları temizlenir.
- Thread nasıl beklemeli (ekrandan, 00:25:00; slayt 212)
  - Busy waiting (boş döngüde sayaç artırmak, sürekli "bitti mi" diye bakmak) yapılmamalıdır; sistemin genel yanıt verebilirliğini düşürür ve kaynakları boşa harcar.
  - Bunun yerine `sleep` ile thread blocked durumuna alınır; uyuyan thread sistem kaynağı tüketmez.
  - Uyuyan thread'in uyanamama riski vardır. Bu yüzden checked bir istisna olan `java.lang.InterruptedException` yakalanmalıdır.
- Bir görevi ayrı thread'de çalıştırmanın dört adımı (ekrandan, 00:30:00; slayt 213)
  - 1: Görevin kodu, `Runnable` arayüzünü gerçekleyen bir sınıfın `public void run()` metoduna yazılır (`java.lang` paketinde, import gerekmez).
  - 2: Bu sınıftan bir nesne oluşturulur.
  - 3: Bu nesne parametre verilerek bir `Thread` nesnesi oluşturulur.
  - 4: Thread, `Thread.start` ile başlatılır. `run` doğrudan çağrılmaz; çağrılırsa kod paralel değil sıralı çalışır.
  - `run` parametre almaz; göreve bilgi constructor ya da setter ile aktarılır. Setter'lar dördüncü adımdan önce çağrılmalıdır.
- Maç seyreden taraftarlar örneği (`SoccerFan` ve `Match`)
  - Her taraftar tuttuğu takım için tezahürat yapar, 0-1000 ms arasında rastgele bir süre bekler, 10 tezahürattan sonra susar.
  - `SoccerFan implements Runnable`; takım adı ve tezahürat metni constructor ile verilir; `run` içinde `for` döngüsü, `System.out.println`, `Thread.sleep(random.nextInt(...))` ve `InterruptedException` için `try-catch` vardır.
  - `Match.main` dört `SoccerFan` nesnesini dört `Thread` ile başlatır (ekrandan, 00:35:00; slayt 215).
  - Çalıştırınca ilk tezahüratların sırası bile oluşturma sırasına uymaz ve her çalıştırmada değişir.
- JUnit ile birim sınama (unit testing)
  - Unit testing, en küçük programlama biriminin sınanmasıdır. Nesneye yönelik programlamada bu birim sınıf ve nesnedir.
  - Önceki örneklerde boolean dönen metotlarla elle yapılan sınamalar, xUnit ailesi çatılarıyla otomatikleştirilir (Java için JUnit, C# için CSUnit).
  - JUnit 3.x (ekrandan, 01:05:00; slayt 230): her iş sınıfı için ayrı test sınıfı (`TestAppClass1` gibi) yazılır, adı `test` ile başlar ve `junit.framework.TestCase` sınıfından türetilir. Test vakaları adı `test` ile başlayan metotlardır. `setUp` her test metodundan önce otomatik çalışır. Test sınıfları statik `TestAll.suite()` metoduyla bir suite altında birleştirilebilir.
  - `Assert` metotları: `assertEquals(beklenen, sonuc)`, `assertNotEquals`, `assertTrue`, `assertFalse`, `assertNull`, `assertNotNull`. Hepsinin başına hata açıklaması string'i alan aşırı yüklenmiş (overloaded) sürümleri vardır.
  - JUnit 4.x: 3.x ile geriye uyumludur. `TestCase`'ten türetme ve `test` ile başlayan ad zorunluluğu kalkar; test metotları `@Test`, hazırlık metodu `@Before` ile işaretlenir. `@Test(expected = XException.class)` ile bir istisnanın fırlatılması sınanabilir; bu metotta assert gerekmez.
- Video kiralama örneği (Martin Fowler, *Refactoring* kitabından; ekrandan, 01:15:00; slayt 232)
  - `Customer` 1 — * `Rental` 1 — 1 `Movie`. `Customer.statement()` makbuz string'i oluşturur; `getTotalCharge()` ve `getTotalBonus()` yardımcı metotlardır.
  - `Rental` kira gün sayısını tutar; `getCharge()`, `getBonus()` ve `getMovieTitle()` işi ilgili `Movie`'ye gün sayısını vererek yaptırır.
  - `Movie` fiyat kodunu (`REGULAR = 0`, `NEW_RELEASE = 1`, `CHILDRENS = 2`) tutar; `getCharge(daysRented)` ve `getBonus(daysRented)` hesaplar.
  - Ücret kuralları (ekrandan, 01:40:00): normal film 2 lira, 2 günü aşan her gün +1,5; yeni film günü 3 lira; çocuk filmi 1,5 lira, 3 günü aşan her gün +1,5.
  - Bonus kuralı: her kiralama 1 puan; yeni film 1 günden fazla kiralanmışsa 1 puan daha.
- Test sınıfları
  - `TestMovie`: üç farklı türde film oluşturup fiyat kodlarının birbirinden farklı olduğunu `assertTrue`/`assertFalse` ile sınar (ekrandan, 01:45:00).
  - `TestCustomer`: `setUp`'ta müşteri ve filmler oluşturulur; `testGetName`, `testStatementWhenEmpty`, `testStatementWithMoviesLongRent`, `testStatementWithMoviesShortRent`, `testNewReleaseRentalBonus` metotları `assertEquals` ile beklenen makbuzu elde edilenle karşılaştırır (ekrandan, 01:50:00).
  - `TestAll.suite()`: `TestSuite` oluşturup `addTestSuite(TestCustomer.class)` ve `addTestSuite(TestMovie.class)` ile iki sınıfı birleştirir; toplam 6 test vakası çalışır (ekrandan, 01:55:00).
  - Eclipse'te JUnit kütüphanesi Build Path > Configure Build Path > Libraries > Add Library ile projeye eklenir; test "Run As > JUnit Test" ile çalıştırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Thread'ler üzerinde denetimimiz yoktur
  - Thread sürekli çalışmaz, aralarda bekler.
  - Ne zaman çalışacağı tamamen scheduler'ın elindedir.
  - Birden fazla thread'in hangi sırada başlayıp biteceğinin hiçbir garantisi yoktur; algoritma bu varsayım olmadan tasarlanmalıdır.
- `start` yerine `run` çağırmayın
  - `run` doğrudan çağrılırsa her nesne işini sırayla bitirir, paralellik olmaz. Derste `run` ile başlatılan iki nesne 10'ar tezahüratını sırayla yaptı, sonra `start` ile başlatılanlar karışık sırayla çalıştı.
- `Thread` sınıfından kalıtımla türetmeyin
  - Java'da tek kalıtım hakkı vardır; bu hak altyapı için değil iş mantığı için kullanılmalıdır. `Runnable` gerçeklemek yeterlidir.
- İş mantığı ile çalıştırma altyapısı ayrı sınıflarda olmalı
  - `SoccerFan` (iş mantığı) ve `Match` (çalıştırma) iki ayrı görev olduğu için ayrı yazıldı; nesneye yönelim en yüksek uyumlu parçalara bölmeyi ister.
- Düşük bağlaşım, yüksek uyum
  - Sequence diyagramında `Customer` yalnız `Rental`'ı, `Rental` yalnız `Movie`'yi çağırır; katmanlı bir yapı oluşur. `getMovieTitle()` sayesinde `Customer` ile `Movie` arasında gereksiz bir ilişki kurulmaz.
  - Tersine (Movie'den Rental'a) ilişki gerekmedikçe kurulmaz; çift yönlü ilişkilerin tutarlılığını korumak zordur.
- if-else-if zinciri ya da switch-case bir tasarım kokusudur
  - Böyle bir kod yazıyorsanız tasarımı kalıtım ve çok biçimlilikle iyileştirmeniz gerekir. Doğru tasarımda `Movie` soyut olur, `Regular`, `NewRelease`, `Childrens` somut alt sınıflar olur ve `getCharge`/`getBonus` alt sınıflarda gerçeklenir. En azından fiyat kodları için `enum` kullanılmalıydı.
- Test metotlarına açıklayıcı ad verin
  - JUnit 4'te zorunlu olmasa da hoca test metotlarını yine `test` ile başlatmayı ve neyi sınadığını anlatan uzun adlar vermeyi tercih ediyor.
  - Normalde her test metodunda tek bir assert tercih edilir.

## Kısa Tekrar Notları

- Multitasking: aynı anda birden fazla program; multithreading: bir programda birden fazla paralel akış.
- Thread durumları: new → (start) runnable → (scheduler) running → (terminate) dead; running → (G/Ç, sleep, wait, join) blocked → runnable.
- Busy waiting yerine `Thread.sleep(ms)`; `InterruptedException` (checked) yakalanmalı.
- Dört adım: `Runnable` gerçekle + `run` yaz, nesne oluştur, `new Thread(nesne)`, `thread.start()`.
- `run` parametresizdir; veri constructor/setter ile, `start`'tan önce verilir.
- `Thread`'den türetme: tek kalıtım hakkını harcar, önerilmez.
- Paralel hızlanma thread sayısı kadar olmaz (thread açma yükü, bekleşme).
- JUnit 3.x: `extends TestCase`, `testXxx()` metotları, `setUp()`, `TestAll.suite()`.
- JUnit 4.x: `@Test`, `@Before`, `@Test(expected = X.class)`.
- Assert'ler: `assertEquals`, `assertNotEquals`, `assertTrue`, `assertFalse`, `assertNull`, `assertNotNull`; ilk parametre isteğe bağlı hata mesajı.
- Kara kutu sınaması: iç kodu bilmeden, girdi-çıktı ile. Beyaz kutu sınaması: kodu bilerek, her dala en az bir kez girecek test vakaları.
- Başarısız `assertEquals` için JUnit beklenen ve elde edilen string'lerin farklı kısmını köşeli parantezle gösterir.

## Detaylı Açıklamalar

- **Neden thread?** Bugün telefonlar bile 4-8 çekirdekli işlemci taşır. İşletim sisteminin sürekli çalışan kısımları bazı çekirdeklere atanır, kalan kaynaklarda kullanıcı uygulamaları çalışır. Bir uygulama işini paralel görevlere bölerse bu kaynakları birlikte kullanıp daha hızlı biter. Ancak Java taşınabilir bir dil olduğu için kodun çok çekirdekli bir makinede çalışacağı varsayılamaz; eski işletim sistemleri multithreading'i desteklemiyordu. Bu yüzden thread'in yaşam döngüsünde scheduler belirleyicidir.

- **Yaşam döngüsünün ayrıntısı.** Thread bir nesnedir. Constructor ile oluşturulunca "new" durumundadır. `start` çağrılınca runnable olur ve scheduler'ın "sıra sende" demesini bekler. Running durumundaki thread kodunu baştan sona kesintisiz yürütmez; scheduler ona bir zaman dilimi (time slice) verir, süre dolunca thread runnable'a geri döner. Thread bir şey beklemek zorundaysa (komut satırından girdi, ağ akışından byte, diske yazma; disk işlemleri bellek işlemlerine göre yavaştır) blocked kuyruğuna alınır. Hoca başta "runnable konumunda bekler" deyip hemen düzeltti: bekleme yeri ayrı bir blok kuyruğudur. Beklenen olay gerçekleşince thread doğrudan running'e değil runnable'a döner ve yine scheduler'ı bekler. `wait`/`join` ile thread'ler birbirini bekleyebilir, `notify`/`notifyAll` bekleyenleri haberdar eder; bu derste bunlar ayrıntılı işlenmez, yalnız `sleep` kullanılır.

- **Busy waiting benzetmesi.** Araba yolculuğunda yanınızdakinin sürekli "geldik mi, geldik mi" diye sorması gibi, thread'in sürekli "işlem bitti mi" diye bakması ya da boş döngüde sayaç artırması sistemin tamamının akıcılığını düşürür. Ağdan veri beklenen bir durumda sürekli yoklamak yerine örneğin 3 saniyede bir yoklayıp arada uyumak doğrudur.

- **SoccerFan örneğinin kodu.** Sabit tezahürat sayısı (10) ve en uzun bekleme süresi (1000 ms) `public static final int` sabitlerdir; takım adı ve tezahürat metni her nesnede farklı olduğu için normal üye alanlardır ve constructor ile verilir. Rastgele sayı için `java.util.Random` nesnesi oluşturulup `nextInt` kullanılır. Rastgele bekleme, scheduler'ın zaten getirdiği belirsizliği artırmak için kullanılır; sonraki derslerde senkronizasyon sorunlarını ortaya çıkarmaya yarayacak. Bu örnekte ortak kaynak yoktur, her taraftar ekrana yalnız bir satır yazar, bu yüzden senkronizasyon sorunu yoktur.
  <!-- BELİRSİZ: SoccerFan sınıfının slaytı (214) karelerde yok; aşağıdaki kod altyazıdaki anlatımdan kurulmuştur, alan ve sabit adları ekrandakinden farklı olabilir. -->

```java
import java.util.Random;

class SoccerFan implements Runnable {
    public static final int STEPS = 10;   // ad tahmini
    public static final int DELAY = 1000; // ad tahmini
    private String team;
    private String shout;

    public SoccerFan(String team, String shout) {
        this.team = team;
        this.shout = shout;
    }

    public void run() {
        Random random = new Random();
        try {
            for (int i = 0; i < STEPS; i++) {
                System.out.println(team + " " + shout);
                Thread.sleep(random.nextInt(DELAY));
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
```

- **Match sınıfı (ekrandan, 00:35:00).** `Thread aThread;` tanımlanır; ardından dört kez `aThread = new Thread(new SoccerFan(...)); aThread.start();` yazılır ("G.S." "Rulez!", "G.S." "is the champ!", "F.B." "is no.1!", "F.B." "is the best!"). `SoccerFan` için ayrı bir geçici değişken tanımlanmadı, nesne doğrudan `Thread` constructor'ına verildi. Hocanın bilgisayarında ilk tezahüratlar bir çalıştırmada 2-3-1-4 sırasıyla geldi; dördüncü nesne birkaç çalıştırmada hep dördüncü sırada çıktı, ama bu önceden bilinemez ve başka donanım, işletim sistemi ya da JDK'da farklı olabilir. (Kod `SoccerFan` ile birlikte `java Match.java` ile çalıştırıldı; 40 satır çıktı, sıra her çalıştırmada farklı.)

- **`run` ile `start` farkı (ekrandan, 00:45:00).** `SoccerFan` nesnesinin `start` metodu yoktur, yalnız `run` metodu vardır. Hoca önce iki `SoccerFan` nesnesinin `run` metodunu doğrudan çağırdı: ilki 10 tezahüratını bitirdi, sonra ikincisi 10 tezahüratını yaptı, ancak bundan sonra `start` ile başlatılan dört thread karışık sırayla çalıştı. Sonra `Match` içindeki `start` çağrılarını `run` yaptı; program her şeyi sırayla yaptığı için çok daha uzun sürdü.

- **Birim sınama neden otomatik olmalı?** Önceki haftalarda parça-bütün ve sahiplik ilişkilerinde (aynı öğrencinin bir derse iki kez eklenmemesi, kapasite aşılınca ekleme yapılmaması gibi) boolean dönen metotlar çağrılıp sonuçlar elle yorumlanıyordu. Yazılım geliştirmek zor olduğu için sınaması da zordur; bu altyapıyı her sınama kodunda tekrar yazmak yerine hazır bir çatı (framework) kullanıp test tasarımına odaklanmak gerekir.

- **Video kiralama örneğindeki tasarım.** Bu örnek kitabın kötü bir tasarımı adım adım iyileştirdiği 12 kadar adımın ortalarındaki (yaklaşık 9.) bir halidir; yine de oldukça derli topludur. `Customer.statement()` bir `Enumeration` alıp kira kayıtlarında dolaşır, her kayıt için film adını ve ücreti, sonda toplam borcu ve toplam bonusu ekler (ekrandan, 02:15:00). Kayıtlar `Vector<Rental>` içinde tutulur. Aynı filmin iki kez eklenmesi engellenmez; müşteri aynı kasetten iki tane kiralamak isteyebilir. Yeni bir filmin fiyat kodu bir süre sonra normal filme çevrilebileceği için `setPriceCode` vardır.

- **Üye alanların alt çizgiyle adlandırılması.** `_name`, `_rentals`, `_priceCode` gibi adlar, renk vurgusu olmadan (siyah-beyaz basılmış kitap, fotokopi, renksiz e-kitap okuyucu, kâğıt üzerinde kod) üye alanı yerel değişken ve parametreden ayırt etmek içindir. IDE'de bu ayrım renkle yapılır (Eclipse'te üye alan mavi).

- **Kara kutu ve beyaz kutu sınaması.** Gereksinimler (film türleri, ücret ve bonus kuralları) bilinerek, kaynak koda bakmadan girdi verip çıktıyı sınamak kara kutu (black box) sınamasıdır. Kaynak kodu bilerek her metodun her `if`/`else`/`case` dalından en az bir kez geçecek test vakaları hazırlamak beyaz kutu (white box) sınamasıdır.

- **Hata ayıklama örnekleri.** Hoca `Movie.getCharge` içindeki `REGULAR` durumunu yorum satırına alınca `TestMovie` kırmızı çubukla başarısız oldu ve açıklama string'i ("Bunlar farklı tür filmlerdir") ile yığın izi gösterildi. Sonra `REGULAR` için günlük 1,5 yerine 1,0 yazınca `testStatementWithMoviesLongRent` başarısız oldu. JUnit `ComparisonFailure` ile beklenen "The Matrix 3.5 ... Amount owed is 12.5" ile elde edilen "The Matrix 3.0 ... Amount owed is 12.0" string'lerinin farklı kısmını köşeli parantezle işaretledi (ekrandan, 02:00:00). Bu nokta atışı ipucu hatayı hızlıca bulmayı sağlar. (Ücret hesapları ekrandaki kurallarla yeniden kurulan kodla `java` ile doğrulandı: 3,5 + 3,0 + 6,0 = 12,5 lira, 4 puan.)

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
