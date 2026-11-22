# Ders 22 Çalışma Özeti

## Genel Konular

- Kalıcılık (persistence) ve stream'lerde nesne referansları
  - Birbiriyle ilişkili nesneler (örneğin bir müşteri ve onun abonelik nesnesi) ayrı ayrı stream'lere, ayrı dosyalara serileştirilirse geri yüklemede referanslar kopar. Müşterinin içindeki abonelik ile ayrı dosyadan okunan abonelik `==` ile karşılaştırılınca `false` çıkar. Durum bilgileri aynıdır ama bunlar bellekte farklı nesnelerdir.
  - Çözüm: ilişkili bütün nesneler aynı stream'e kaydedilir.
- Thread havuzları (thread pool)
  - Az sayıda görevi ayrı thread'lerde çalıştırmak sorun değildir. Ama tipik bir işlemcide gerçek işlem birimi sayısı azdır ve thread oluşturmanın da bir maliyeti vardır. Çok sayıda görev varsa thread havuzu kullanılır (ekrandan, 00:20:00).
  - Örnek: 4 çekirdekli, her çekirdekte 2 donanım thread'i olan bir işlemcide aynı anda en çok 8 thread gerçekten paralel çalışır. 32 thread açmak orantılı hız kazandırmaz, thread'ler arası geçiş de ek yük getirir.
  - Sınıflar `java.util.concurrent` paketindedir (ekrandan, 00:20:00):
    - `Executor` arayüzü: `execute(object : Runnable)`.
    - `ExecutorService` arayüzü, `Executor`'dan kalıtımla türer: `shutdown() : void`, `shutdownNow() : List<Runnable>`, `isShutdown() : boolean`, `isTerminated() : boolean`.
    - `Executors` sınıfının statik metotları havuz verir: `newFixedThreadPool(nThreads : int)` ve `newCachedThreadPool()`, ikisi de `ExecutorService` döndürür.
  - `newFixedThreadPool(n)`: aynı anda en çok `n` thread çalışır. `newCachedThreadPool()`: havuzun genişliğini Java sanal makinesi sistemin yüküne göre kendisi ayarlar.
  - Görev `Thread.start()` yerine `pool.execute(runnable)` ile çalıştırılır.
  - Havuz, içindeki işler bitince kendiliğinden kapanmaz. `shutdown()` çağrılmazsa program bitmiş gibi görünse de havuz arka planda yaşar ve program sonlanmaz.
  - `shutdown()`: yeni görev kabul etmez, içerideki görevlerin bitmesini bekler, sonra kapanır. `shutdownNow()`: beklemeden kapatır ve bitmemiş görevleri `List<Runnable>` olarak döndürür. `isShutdown()`: kapanma sinyali verilmiş mi; `isTerminated()`: havuz tamamen kapandı mı.
  - Bütün görevlerin bitmesini beklemek için boş gövdeli döngü kullanılır: `while (!pool.isTerminated());`.
- Havuzla taraftar (SoccerFan) örneği ve süre ölçümü
  - `SoccerFan` sınıfı hiç değişmez; yalnız çalıştırma mekanizması değişir. İş mantığı ile çalıştırma sorumluluğunun ayrılması iyi bir nesneye yönelik tasarımdır.
  - Süre `System.currentTimeMillis()` ile ölçülür. Bu metot 1 Ocak 1970'ten beri geçen milisaniyeyi `long` olarak döndürür. Bitiş anı, `isTerminated()` döngüsünden sonra alınmalıdır (ekrandan, 00:40:00).
  - Her taraftar 10 kez, aralarda 0-1000 ms rastgele bekleyerek tezahürat yapar. Bir taraftar ortalama 5000 ms sürer. 4 taraftar paralel çalışınca toplam süre de yaklaşık 5 saniyedir (ekranda bir çalıştırmada `6627` ms).
  - `newFixedThreadPool(4)` ile yine yaklaşık 5 saniye, `newFixedThreadPool(2)` ile yaklaşık 10-12 saniye ölçüldü. Havuz 6 yapılınca süre 4'tekinden farklı olmaz.
- `run()` içinde istisna
  - `run()` metodu denetlenen (checked) bir istisnayı `throws` ile dışarı atamaz. Denetlenen istisna `run()` içinde `try-catch` ile işlenir. Dışarı istisna fırlatılması isteniyorsa `RuntimeException`'dan türeyen denetlenmeyen (unchecked) bir istisna kullanılır.
- Yarış koşulu (race condition)
  - İki ya da daha çok thread aynı nesneye erişip onun durumunu değiştiren metotları çağırırsa birbirlerinin işini bozabilir. Sonuç verilere erişim sırasına bağlıdır, bozuk nesneler oluşabilir (ekrandan, 01:00:00).
  - Banka örneği: `Account`, `AccountDepositer` (yatıran) ve `AccountWithdrawer` (çeken). Yatıran ve çeken `Runnable` görevleri aynı `Account` nesnesine bağlıdır.
  - `BankSimulation`: bakiye 0, 100 görev 1'er lira yatırır, 50 görev 1'er lira çeker. Beklenen sonuç 50'dir, ekranda `After: 5.0` çıktı (ekrandan, 01:10:00).
  - `BankSimulationV2`: bakiye 1000, bir görev 100, bir görev 50 çeker. Beklenen 850, çıkan 950.
  - Nedeni: her thread'in yerel değişkenleri kendi yığıtındadır, üye alanlar ise paylaşılır. İki thread de bakiyeyi 1000 olarak okur, biri 900 yazar, öbürü kendi kopyasıyla 950 yazar ve 900 kaybolur.
- `synchronized` ile önleme
  - Yarışa yol açabilecek metotlar `synchronized` anahtar kelimesiyle işaretlenir. Bir `synchronized` metodu aynı anda yalnız bir thread çalıştırabilir, öbürleri bekler (ekrandan, 01:15:00).
  - Paylaşılan alana okuma ya da yazma amacıyla erişen bütün metotlar işaretlenmelidir (`withdraw` ve `deposit`).
  - Düzeltmeden sonra `BankSimulation` 50, `BankSimulationV2` 850 verdi (ekrandan, 01:20:00). Çalışma biraz yavaşladı ama sonuç doğru oldu.
  - Thread-safe veri yapıları aslında `synchronized` yapılardır: liste için `Vector`, map için `Hashtable`.
- Ek havuz ve thread örnekleri
  - `new Thread(new SoccerFan(...)).start();` biçiminde nesneyi bir değişkene atamadan da thread başlatılabilir.
  - `SoccerFan`'dan türeyen hakem (`Refree`) sınıfı takım tutmaz, tezahüratların arasında uyarı verir.
  - `start()` yerine `run()` çağrılırsa görevler paralel değil, sırayla çalışır.
  - Her görev için ayrı bir `Thread` değişkeni kullanmanın bir avantajı yoktur, tek bir referans değişkeni yeter.
  - Ayrıntılı (verbose) sürümde adım numaraları yazdırılır. Konsol çıktısının sırası scheduler ve Eclipse'in konsol thread'i yüzünden değişebilir. `shutdown()`'dan sonra da tezahüratlar sürer.
  - Abartılı gecikme kaldırılıp yalın `balance -= amt;` ve `balance += amt;` yazılsa da 150 işlemli simülasyon `synchronized` olmadan 53, 54, 51 gibi yanlış sonuçlar verdi. Ara sıra 50 çıkması da hatayı bulmayı zorlaştırır.
- JUnit ile birim sınama (unit testing)
  - Elle test (sonucu `if-else` ile kontrol edip ekrana yazdırmak, listeleri gözle okumak) verimsizdir ve binlerce satırlık kodda uygulanamaz. Sınama otomatikleştirilmelidir.
  - Nesneye yönelik programlamada en küçük test birimi sınıftır. Sınıfın metotlarını sınayan testlere birim testi denir.
  - JUnit 3.x (ekrandan, 01:50:00): her sınıf için ayrı bir test sınıfı yazılır (`AppClass1` için `TestAppClass1`). Test sınıfı `junit.framework.TestCase`'ten türer. Test metotları `testXXX()` diye adlandırılır.
  - `setUp()` (slaytta `# setup()`, korumalı) her `testXXX()` metodundan önce bir kez çalışır ve başlangıç nesnelerini kurar.
  - `Assert` sınıfının statik metotları: `assertEquals(beklenen, sonuc)`, `assertNotEquals`, `assertTrue`, `assertFalse`, `assertNull`, `assertNotNull`. Bütün `assert` metotlarının, başarısızlıkta gösterilecek bir açıklama metni alan aşırı yüklenmiş sürümleri de vardır.
  - Test sınıfları statik `suite()` metoduyla bir test grubunda (test suite, örnekte `TestAll`) toplanabilir.
  - JUnit 4.x: ad zorunluluğu kalkar, yerine annotation kullanılır. Hazırlık metodu `@Before`, test metotları `@Test` ile işaretlenir. Bir istisnanın fırlatılması `@Test(expected = BirException.class)` ile sınanır.
- Film kiralama örneği (Martin Fowler, *Refactoring*)
  - `Customer` 1 - * `Rental` * - 1 `Movie`. `Customer.statement()` makbuz metnini bir `String` olarak döndürür. Metnin ekrana basılmaması test etmeyi kolaylaştırır (ekrandan, 02:00:00).
  - `Movie.getCharge(daysRented)` (ekrandan, 02:10:00): normal film 2 lira, 2 günü aşan her gün için 1,5 lira daha; yeni film gün başına 3 lira; çocuk filmi 1,5 lira, 3 günü aşan her gün için 1,5 lira daha.
  - Bonus: her kiralama 1 puan, yeni film 1 günden uzun kiralanırsa 1 puan daha.
  - Uzun kiralama testinde beklenen makbuz: The Matrix 3.5, Monsters, Inc. 3.0, Surrogates 6.0, toplam 12.5 (ekrandan, 02:20:00).
  - Normal film için 1,5 yerine bilerek 1,0 yazılınca test kırmızı çubuk verdi (6 testte 1 başarısızlık). JUnit beklenen ile gerçek metnin ayrıldığı yeri köşeli parantezle gösterdi: `3.[5` ve `3.[0`.
- Tasarım üzerine
  - `switch-case` ya da uzun `if-else if` zincirleriyle tür ayrımı yapılıyorsa tasarımda büyük olasılıkla eksik vardır. `Movie` soyut yapılıp `getCharge()` alt sınıflarda geçersiz kılınmalıdır (kalıtım ve çok biçimlilik).
  - Refactoring, dışarıya verilen hizmetleri değiştirmeden iç yapıyı küçük adımlarla iyileştirmektir. Her adımdan önce test durumları çalıştırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Havuzu kapatmayı unutmamak
  - `shutdown()` çağrılmazsa havuz yeni görev beklemeye devam eder ve program sonlanmaz. Bu durum Eclipse'te kırmızı durdurma düğmesinin etkin kalmasından anlaşılır.
- Süre ölçümü için havuzun bitmesini beklemek
  - `shutdown()` hemen döner. Bitiş zamanı, `while (!pool.isTerminated());` döngüsünden sonra alınmazsa yanlış ölçülür.
- Paylaşılan veriye erişen bütün metotlar `synchronized` olmalı
  - Yalnız biri işaretlenirse yetmez. Okuyan ve yazan bütün metotlar işaretlenir.
  - Asıl amaç performans değil doğruluktur. Yanlış hesaplayan yazılım kullanılamaz. Paralel kalan kısımlar yine hız kazandırır.
- Bazen doğru, bazen yanlış çalışan program daha kötüdür
  - Hata rastgele ortaya çıktığı için sebebini bulmak çok daha zordur.
- İlişkili nesneler aynı stream'e kaydedilmeli
  - Ayrı stream'ler nesne referanslarını koparır.
- Sorumlulukların ayrılması
  - `SoccerFan` sınıfı havuza geçişte değişmedi. Çalıştırma mekanizması değişince iş mantığı sınıflarının değişmemesi iyi tasarımdır.
- Test metnini dönen metotlar
  - `statement()` sonucu doğrudan yazdırmak yerine `String` döndürür. Böylece beklenen ve gerçek metin karşılaştırılabilir.
- Tasarım kalıpları ve refactoring
  - Doğru tasarımı öğrenmek kadar yanlış tasarımın nasıl düzeltileceğini bilmek de önemlidir. Tasarım kalıpları (design patterns), kod kusurları (code smells) ve refactoring kendi kendine çalışmaya uygun konulardır.

## Kısa Tekrar Notları

- `ExecutorService pool = Executors.newCachedThreadPool();` ya da `Executors.newFixedThreadPool(n);`
- `pool.execute(runnable);` → `pool.shutdown();` → `while (!pool.isTerminated());`
- `shutdownNow()` hemen kapatır, bitmemiş görevleri `List<Runnable>` olarak verir.
- `isShutdown()` kapanma sinyalini, `isTerminated()` tam kapanmayı bildirir.
- Sabit havuz genişliği görev sayısından küçükse süre uzar (4 görev, havuz 2 → yaklaşık 2 kat).
- `System.currentTimeMillis()` 1 Ocak 1970'ten beri geçen milisaniyeyi `long` olarak verir.
- `run()` denetlenen istisna fırlatamaz; ya içeride `try-catch` ya da unchecked istisna kullanılır.
- Yarış koşulu: paylaşılan üye alanı okuma-değiştirme-yazma adımları arasında thread değişimi.
- Çözüm: paylaşılan veriye erişen bütün metotlara `synchronized`.
- Thread-safe koleksiyonlar: `Vector`, `Hashtable`.
- JUnit 3: `extends TestCase`, `setUp()`, `testXXX()`, `assertXXX(...)`, `suite()`.
- JUnit 4: `@Before`, `@Test`, `@Test(expected = X.class)`.
- Yeşil çubuk: bütün testler geçti. Kırmızı çubuk: en az bir test başarısız.
- `switch` ile tür ayrımı → kalıtım ve çok biçimlilik ile yeniden tasarla.

## Detaylı Açıklamalar

- Thread havuzunun mantığı şudur: donanımın gerçekten aynı anda çalıştırabileceği thread sayısı sınırlıdır. Bu sayının çok üstünde thread açmak hız kazandırmaz, thread geçişlerinin yükü yüzünden zarar bile verebilir. Havuza örneğin 4 thread'lik bir kapasite verip 8 görev konursa scheduler 4'ünü etkin tutar. Biri beklemeye geçince bekleyen görevlerden birini alıp çalıştırır. Hoca bunu yol benzetmesiyle anlattı: dört şeritli yolda dört araç yan yana gider. Yol iki şeritli bir köprüye girince araçlar sıraya girmek zorunda kalır. Altı şeritli yol ise dört araca dört şeritliden fazla hız kazandırmaz.

- Havuzlu taraftar örneğinin kodu (ekrandan, 00:40:00):

```java
package nyp14a;
import java.util.concurrent.*;
public class MatchWithPool {
    public static void main(String[] args) {
        long begin = System.currentTimeMillis();
        //ExecutorService pool = Executors.newCachedThreadPool();
        ExecutorService pool = Executors.newFixedThreadPool(4);
        pool.execute( new SoccerFan("G.S.", "Rulez!") );
        pool.execute( new SoccerFan("G.S.", "is the champ!") );
        pool.execute( new SoccerFan("F.B.", "is no.1!") );
        pool.execute( new SoccerFan("F.B.", "is the best!") );
        pool.shutdown( );
        System.out.println("Shutdown initiated");
        while(!pool.isTerminated());
        System.out.println("Shutdown complete");
        long end = System.currentTimeMillis();
        System.out.println(end-begin);
    }
}
```

  - Karede 7. satır yazılırken görülüyor (`Executors.` yarım). Ders akışında hemen sonra `newFixedThreadPool(4)` yazıldı. `SoccerFan` sınıfı önceki dersten gelir.

- Banka simülasyonu (ekrandan, 01:35:00):

```java
package nyp14d;
import java.util.concurrent.*;
public class BankSimulation {
    public static void main(String[] args) {
        Account anAccount = new Account(0);
        System.out.println("Before: "+anAccount.getBalance());
        ExecutorService executor = Executors.newCachedThreadPool( );
        for( int i = 0; i < 100; i++ ) {
            AccountDepositer task=new AccountDepositer(anAccount,1);
            executor.execute(task);
        }
        for( int i = 0; i < 50; i++ ) {
            AccountWithdrawer task=new AccountWithdrawer(anAccount,1);
            executor.execute(task);
        }
        executor.shutdown();
        while( !executor.isTerminated() );
        System.out.println("After: "+anAccount.getBalance());
    }
}
```

- `Account` sınıfının kodu karelerde görünmüyor. Hocanın anlatımına göre `withdraw` önce `getBalance()` ile bakiyeyi yerel bir değişkene alır, sonra rastgele kısa bir süre bekler, en son `balance = currentBalance - amt;` yazar. `deposit` de aynı yapıdadır. Bekleme, thread'in tam bu arada kesilme olasılığını artırmak için konmuştur. <!-- BELİRSİZ: Account kodu karelerde yok; anlatımdan kuruldu. Altyazıda gecikme "5000 saniye" diye geçiyor; büyük olasılıkla birkaç milisaniyelik rastgele bir beklemedir. -->

- Yarış koşulunun adım adım açıklaması (bakiye 1000; Alice 100, Bob 50 çekiyor): İkisi de `withdraw`'a girer ve yerel `currentBalance` değişkenine 1000 okur. Alice `balance = 1000 - 100 = 900` yazar ve çıkar. Bob'un kopyası hâlâ 1000'dir, `balance = 1000 - 50 = 950` yazar. Son değer 950 olur, 850 olması gerekirdi. Yerel değişkenler her thread'in yığıtında ayrı tutulur, üye alan `balance` ise ortaktır. `withdraw` ve `deposit` `synchronized` olunca ikinci thread birincinin çıkmasını bekler ve 850 elde edilir.

- Bu ders için yazılan tek dosyalık bir deneme (`java` tek dosya çalıştırıcısıyla, ajan tarafından yazıldı, derste yazılmadı) `Account` anlatımdaki gibi kurulduğunda senkronsuz sürümde 50'den çok farklı bir sonuç (bir çalıştırmada 1.0), `synchronized` sürümde 50.0 verdi. 500 ms süren 4 görev `newFixedThreadPool(4)` ile yaklaşık 507 ms, `newFixedThreadPool(2)` ile yaklaşık 1001 ms sürdü. Bu, derste görülen yaklaşık 2 katlık artışla tutarlıdır.

- JUnit örneğinin kurulumu (ekrandan, 02:15:00, müşteri adı genelleştirildi):

```java
public class TestCustomer extends TestCase {
    private Customer musteri;
    private Movie matrix, monster, surrogate, terminator;

    protected void setUp() {
        musteri = new Customer("Örnek Müşteri");
        matrix = new Movie("The Matrix",Movie.REGULAR);
        monster = new Movie("Monsters, Inc.",Movie.CHILDRENS);
        surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
        terminator = new Movie("Terminator Salvation",Movie.NEW_RELEASE);
    }

    public void testGetName( ) {
        String sonuc = musteri.getName( );
        assertEquals("Örnek Müşteri",sonuc);
    }
    ...
}
```

  - `testGetName` basit görünür, ama adda Türkçe karakter olduğu için sistemin Türkçe karakterleri doğru işleyip işlemediğini de sınar.
  - Öbür test metotları: `testStatementWhenEmpty`, `testStatementWithMoviesShortRent`, `testStatementWithMoviesLongRent`, `testNewReleaseRentalBonus`. Adlar amacı anlatacak biçimde, uzun olsa da camelCase ile verilmiştir.

- `getCharge` (ekrandan, 02:10:00 ve 02:20:00):

```java
public double getCharge( int daysRented ) {
    double result = 0;
    switch ( getPriceCode() ) {
    case Movie.REGULAR:
        result += 2;
        if (daysRented > 2)
            result += (daysRented - 2) * 1.5;
        break;
    case Movie.NEW_RELEASE:
        result += daysRented * 3;
        break;
    case Movie.CHILDRENS:
        result += 1.5;
        if (daysRented > 3)
            result += (daysRented - 3) * 1.5;
        break;
    }
    return result;
}
```

  - Uzun kiralama testinde makbuzdaki tutarlar şunlardır: The Matrix 3.5 (normal film, $2 + (3-2) \cdot 1{,}5$, yani 3 gün), Monsters, Inc. 3.0 (çocuk filmi, $1{,}5 + (4-3) \cdot 1{,}5$, yani 4 gün), Surrogates 6.0 (yeni film, $2 \cdot 3$, yani 2 gün). Toplam $3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$. Gün sayıları karedeki tutarlardan geri hesaplandı (ara adım eklendi). Bonus: 3 kiralama 3 puan, 1 günden uzun kiralanan yeni film 1 puan daha, toplam 4 puan.
  - Hatalı sürümde (`* 1.0`) The Matrix $2 + 1 \cdot 1{,}0 = 3{,}0$ ve toplam 12.0 olur. JUnit karşılaştırma hatasında bu fark görünür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
