# Ders 22 Genişletilmiş Notu: Thread Havuzları, Yarış Koşulu ve synchronized, JUnit ile Birim Sınama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kalıcılıkta nesne referanslarının korunması
- 2. Thread havuzları
- 3. Havuzla taraftar örneği ve süre ölçümü
- 4. run() içinde istisna
- 5. Yarış koşulu (race condition)
- 6. synchronized ile yarışın önlenmesi
- 7. Ek havuz ve thread örnekleri
- 8. JUnit ile birim sınama
- 9. Film kiralama örneği üzerinde JUnit
- 10. Tasarım, refactoring ve tasarım kalıpları
- Örnek Sorular
- Dersin Toparlaması

## 1. Kalıcılıkta nesne referanslarının korunması

Dersin başında hoca, daha önce işlenen stream'ler ve serileştirme konusuna küçük bir ipucu ekledi. Bir sistemde birbiriyle ilişkili pek çok sınıftan pek çok nesne bulunur. Örneğin bir müşteri (`ExistingCustomer`) bir abonelik (`Subscription`) nesnesine sahip olabilir, abonelik de ters yönde müşteriyi gösterebilir.

Bu nesneler ayrı stream'lerle ayrı dosyalara kaydedilirse sorun çıkar. Diyelim ki müşteri nesneleri A dosyasına, abonelik nesneleri B dosyasına yazıldı. Müşteri yazılırken onun üyesi olan abonelik de A dosyasına girer. Abonelik B dosyasına yazılırken onun gösterdiği müşteri de B dosyasına girer. Geri yüklemede müşterinin içindeki abonelik ile B dosyasından okunan abonelik `==` ile karşılaştırılırsa `false` çıkar. Durum bilgileri aynıdır, ama bellekte farklı yerlerde duran farklı nesnelerdir. Yani nesne referansları kırılmıştır.

> **Hocanın vurgusu:** Kalıcılık (persistence) için stream kullanılacaksa ilişkili nesnelerin hepsi aynı stream'e kaydedilmelidir.

## 2. Thread havuzları

### 2.1 Neden havuz?

Önceki dersteki çok thread'li (multithreading) örnekte thread'ler sırayla başlatılmıştı. Ondan sonra ne tek tek thread'ler ne de bütünü üzerinde bir denetim vardı. Tek denetim, Eclipse konsolundaki kırmızı durdurma düğmesiyle bütün programı durdurmaktı. Hoca, `ThreadGroup` diye bir konu da olduğunu ama ders kapsamında işlenmeyeceğini söyledi. Bunun yerine thread havuzları (thread pool) anlatıldı.

Havuz iki şey sağlar. Birincisi, uygulamanın kendi thread'lerinin bitip bitmediğini sorgulamak ve hepsine "artık kapanın" sinyali göndermek. İkincisi, kaynakları ölçülü kullanmak. Slayttaki maddeler şunlardır (ekrandan, 00:20:00):

- Az sayıda görevi ayrı thread'lerde çalıştırmak kabul edilebilir.
- Ama tipik bir işlemcide gerçek işlem birimi sayısı oldukça azdır ve thread oluşturmanın da bir işlem maliyeti vardır.
- Bu yüzden çok sayıda görev çalıştırılacaksa thread havuzu kullanılmalıdır.

Hoca bunu sayılarla açıkladı. Java'nın amaçlarından biri farklı ortamlarda çalışabilmektir. Her bilgisayar dört çekirdekli, her çekirdeğinde iki donanım thread'i olan, yani sekiz sanal işlem birimi sunan bir işlemciye sahip değildir. Sekiz işlem birimli bir makinede aynı anda gerçekten sekiz thread çalışabilir. Dokuzuncu thread eklendiğinde orantılı bir hız artışı alınmaz. İşlemcinin içindeki farklı yürütme birimleri sayesinde biraz kazanç olur, ama yüksek değildir. Bir thread'den ötekine geçiş de ek yük getirir. 32 thread'i dört çekirdekte çalıştırmak bu yüzden pek verim sağlamaz.

Havuz bu yan etkiyi hafifletir. Örneğin havuza 4 thread'lik kapasite verilir ve içine 8 görev konur. Scheduler 4 görevi etkin tutar. Biri beklemeye geçince hazır bekleyen görevlerden birini alıp çalıştırır ve kaynakları onlar arasında paylaştırır.

### 2.2 java.util.concurrent sınıfları

Slayttaki UML şeması (ekrandan, 00:20:00):

```text
java.util.concurrent
  <<interface>> Executor
    + execute( object : Runnable )
        ^ (kalıtım)
  <<interface>> ExecutorService
    + shutdown() : void
    + shutdownNow() : List<Runnable>
    + isShutdown() : boolean
    + isTerminated() : boolean
  Executors   (static methods)
    + newFixedThreadPool( nThreads : int ) : ExecutorService
    + newCachedThreadPool() : ExecutorService
```

`ExecutorService`, `Executor`'dan kalıtımla türediği için doğrudan `ExecutorService` kullanmak yeterlidir. Havuz, `Executors` sınıfının iki statik metodundan biri çağrılarak elde edilir.

- `newFixedThreadPool(n)`: istenen sabit kapasitede bir havuz verir. Parametre 4 ise aynı anda en çok 4 thread etkin çalışır. Sekiz işlem birimli bir makinede bu, kaynakların kabaca yarısını kendi thread'lerine ayırmak demektir. Tek thread'li çift çekirdekli bir işlemcide ise 4 verilse de aynı anda gerçekte 2 thread çalışır ve öbürleri sırayla zaman alır.
- `newCachedThreadPool()`: sabit sayı verilmez. Havuzun genişliğini Java sanal makinesi sistemin yüküne bakarak ayarlar. Hoca arka plandaki algoritmayı bilmediğini ve önemli olmadığını söyledi. Sanal makine thread'leri mümkün olduğunca paralel çalıştırmaya çalışır.

### 2.3 Görev çalıştırma ve havuzu kapatma

`Runnable` arayüzünü gerçekleyen nesneler, eskiden olduğu gibi `Thread.start()` ile değil, havuzun `execute()` metoduyla çalıştırılır.

Havuzdaki thread'ler işini bitirince havuz kendiliğinden kapanmaz. Yeni thread kabul etmek için bellekte, etkin olarak bekler. `main` metodunda yalnız görevler havuza verilip başka bir şey yapılmazsa program bitmiş gibi görünse de havuz yaşamaya devam eder. Bu yüzden görevler verildikten sonra kapatma metodu çağrılır:

- `shutdown()`: "bu görevler bitince başka görev eklemeyeceğim, kendini kapat" sinyalidir. Havuz hemen kapanmaz, içindeki görevlerin bitmesini bekler, yeni görev kabul etmez. Güvenli bitiş için bu kullanılır.
- `shutdownNow()`: acil kapatmadır. Açık görevlerin bitmesini beklemeden havuzu kapatır. Tamamlanmamış `Runnable` nesnelerini `List<Runnable>` olarak döndürür. Bu görevler istenirse başka bir havuzda çalıştırılabilir.
- `isShutdown()`: `true` dönerse kapanma sinyali verilmiştir, ama havuz henüz tamamen kapanmamış olabilir.
- `isTerminated()`: `true` dönerse havuz tamamen kapanmıştır.

Havuzdaki bütün işler bittikten sonra tek thread'le başka işler yapılacaksa boş gövdeli bir döngü kullanılır:

```java
while (!pool.isTerminated());
```

> **Ders sonrası not:** Hoca `shutdownNow()` için "bitmemiş görevlerin listesini döndürür" dedi. Java belgelerine göre büyük olasılıkla döndürülen liste yalnız henüz çalışmaya başlamamış, sırada bekleyen görevleri içerir. O anda çalışan görevler listeye girmez, onlara kesme (interrupt) gönderilerek durdurulmaya çalışılır.

## 3. Havuzla taraftar örneği ve süre ölçümü

### 3.1 Sınıf değişmeden havuza geçiş

Önceki dersteki taraftar (`SoccerFan`) örneği bu kez havuzla çalıştırıldı. Slayttaki maddeler (ekrandan, 00:30:00): "Önceki örneği havuzda çalışacak biçimde değiştirelim. `SoccerFan` sınıfı değişmeyecek. Farklı boyutlarda sabit havuz deneyin."

> **Hocanın vurgusu:** `SoccerFan` sınıfının değişmemesi iyi bir şeydir. Çok thread'li çalışacak nesnelerin iç mantığı ile bunların normal thread'de mi havuzda mı çalıştırılacağı sorumluluğu birbirinden ayrılmıştır. Değişen yalnız çalıştırma mekanizmasıysa yalnız o değişmelidir; iş mantığını oluşturan nesnelerin değişmesi iyi tasarım olmaz.

Slayttaki ilk sürüm (ekrandan, 00:30:00):

```java
package nyp14a;
import java.util.concurrent.*;
public class MatchWithPool {
    public static void main(String[] args) {
        ExecutorService pool = Executors.newCachedThreadPool( );
        pool.execute( new SoccerFan("G.S.", "Rulez!") );
        pool.execute( new SoccerFan("G.S.", "is the champ!") );
        pool.execute( new SoccerFan("F.B.", "is no.1!") );
        pool.execute( new SoccerFan("F.B.", "is the best!") );
        pool.shutdown( );
    }
}
```

Görevler havuza eklenir eklenmez çalıştırılabilir (runnable) duruma gelir, ilk fırsatta çalışmaya (running) geçer. Çalıştırınca taraftarlar tezahüratlarını yaptı ve program bitti; Eclipse'teki sonlandırma düğmesi etkisiz (disabled) hale geldi. Hoca sonra `shutdown()` satırını kaldırarak denedi: son tezahürat yapıldığı halde program etkin kaldı, çünkü havuz hâlâ açıktı. `main` metodunun son komutu çalıştığı için havuza bir şey eklenemiyordu ama program da bitmiyordu; kırmızı düğmeyle durdurmak gerekti.

> **Hocanın vurgusu:** Havuza verilen thread'ler kendi kendine sonlanabiliyorsa havuzu kapatma komutunu vermeyi unutmayın.

### 3.2 Geçen süreyi ölçmek

Farklı havuz genişliklerinin etkisini görmek için hoca süre ölçtü. `System.currentTimeMillis()` metodu sabit bir tarihten, 1 Ocak 1970'ten, o ana kadar geçen milisaniye sayısını döndürür. Sayı büyük olduğu için `long` bir değişkene atanır. Programın başında `begin`, işler bitince `end` alınır, fark yazdırılır.

Burada bir tuzak var: `shutdown()` hemen döner ve bir sonraki satıra geçilir. Bitiş zamanı orada alınırsa thread'lerin işini bitirdiği an ölçülmez. Bu yüzden önce havuzun tamamen kapanması beklenir. `isTerminated()` havuz kapanmamışken `false` döner, `!` ile döngü koşulu `true` olur ve döngü bekler. Havuz kapanınca koşul `false` olur ve döngüden çıkılır. Son kod (ekrandan, 00:40:00):

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

Karede 7. satır yazılırken yarım görünüyor (`Executors.`). Hemen sonra `newFixedThreadPool(4)` yazıldı (00:40:00 civarı anlatım). Karedeki konsolda önceki, önbellekli (cached) havuzlu çalıştırmanın sonucu `Shutdown complete` ve `6627` olarak görünüyor.

### 3.3 Beklenen süre

Her taraftar 10 kez tezahürat yapar ve her tezahürattan önce 0 ile 1000 ms arasında rastgele bekler. Ortalama bekleme 500 ms'dir:

$$10 \times 500\ \text{ms} = 5000\ \text{ms}$$

Taraftarlar paralel çalıştığı ve birbirini beklemediği için toplam süre de ortalama yaklaşık 5000 ms olmalıdır. Ölçümlerde 5-6 saniyelik değerler (örneğin 6,6 saniye) görüldü; bu da dört taraftarın gerçekten eş zamanlı çalıştığını gösterir.

### 3.4 Sabit havuz genişliğinin etkisi

- `newFixedThreadPool(4)`: 4 taraftar aynı anda çalışabildiği için yine yaklaşık 5 saniye (4,8 ve 6,8 saniye ölçüldü).
- `newFixedThreadPool(2)`: aynı anda yalnız 2 thread çalışır. Süre yaklaşık iki katına çıkmalıdır, yani yaklaşık 10 saniye. Ölçümde yaklaşık 12 saniye çıktı.
- `newFixedThreadPool(6)`: 4'tekinden farkı yoktur, yine yaklaşık 5 saniye.

Hoca bunu yol benzetmesiyle anlattı. Dört şeritli yolda dört araç yan yana akabilir. Yol iki şeride düşen bir köprüye girince araçlar sıraya girmek zorunda kalır, aynı anda yalnız iki araç geçer. Altı şeritli yol ise dört araca dört şeritli yoldan daha fazla hız kazandırmaz.

Konsol sırası hakkında bir not: bir çalıştırmada "Shutdown initiated" yazısı dördüncü görevin eklenmesinden önce yazılmış gibi göründü. Hoca, konsola çıktıyı Eclipse'in de kendi thread'leriyle yazdığını, scheduler'ın etkisiyle çıktı sırasının olayların gerçek neden-sonuç sırasından farklı görünebileceğini söyledi. Gerçekte önce dördüncü görev eklenir, sonra `shutdown()` çalışır.

## 4. run() içinde istisna

Çok thread'li çalışacak bir sınıf `Runnable`'ı gerçekler ve uygulama mantığı `public void run()` içinde yer alır. `run()` içinde bir istisna oluşabiliyorsa ne yapılacağı önemli bir sorudur.

- Denetlenen (checked) bir istisna `run()` içinde oluşabiliyorsa, dışarıda işlenmesi için `run()` imzasına `throws ...` eklenemez. Bu istisna `run()` içinde, `InterruptedException` için yapıldığı gibi `try-catch` ile işlenmek zorundadır.
- `run()`'ın dışarı istisna fırlatabilmesi isteniyorsa bu istisna `RuntimeException`'dan türeyen denetlenmeyen (unchecked) bir istisna olmalıdır.
- Biraz daha uğraşılarak istisnayı fırlatan metot `throws` ile işaretlenir ve `run()` içinde onu çağıran yerde `try-catch` yapılır.

> **Ek bilgi (derste anlatılmadı):** `run()` metodu `Runnable` arayüzünde `throws` olmadan tanımlıdır. Geçersiz kılan (override) bir metot, üst tanımda olmayan denetlenen istisnaları bildiremez. Kısıtın kaynağı budur.

## 5. Yarış koşulu (race condition)

### 5.1 Tanım

Pratikte işe yarayan çok thread'li uygulamaların çoğunda iki ya da daha çok thread'in aynı veriye erişmesi gerekir. Slayttaki sorular (ekrandan, 01:00:00): İki thread aynı nesneye erişir ve her biri nesnenin durumunu değiştiren bir metodu çağırırsa ne olur? Tahmin edileceği gibi thread'ler birbirinin ayağına basabilir. Verilere erişim sırasına göre bozuk nesneler oluşabilir. Bu duruma genellikle yarış koşulu (race condition) denir.

Hoca nedenini şöyle açıkladı. Bir thread herhangi bir anda kesilip yerine başka bir thread çalıştırılabilir. Basit bir atama ya da çarpma bile işlemcide birkaç alt adıma dönüşebilir. Bir thread bir veriye bakar, bir değer görür, değiştirmeye başlar, birkaç alt adımı işletir. Ama değiştirme bitmeden bekleme kuyruğuna alınır. Başka bir thread gelir, yarım kalmış veriyi görür, ona göre işlem yapar, belki o da değiştirir. İlk thread geri döndüğünde orada bambaşka bir şey bulur. Tutarlılık sorunları böyle ortaya çıkar. Önlenmezse doğru çalışan çok thread'li programlar yazılamaz.

### 5.2 Banka hesabı senaryosu

Bir banka hesabına para yatırmak için `AccountDepositer`, para çekmek için `AccountWithdrawer` nesneleri kullanılır. Hoca, normalde böyle bir tasarım pek yapılmasa da bankaların bilgi sistemlerinde her iş için ayrı sistemler bulunduğunu (havale, yatırım fonu işlemleri vb.) ve senaryonun abartılı olmadığını söyledi.

Hem yatıran hem çeken nesne bir `Account` nesnesiyle birebir ilişkilidir ve hepsi aynı `Account` nesnesine bağlanır. Böylece farklı nesneler aynı ortak veriye erişir. Yatıran, `run()` içinde hesabın `deposit` metodunu; çeken, `withdraw` metodunu çağırır.

Yatıran sınıfın slaytı (ekrandan, 01:05:00) animasyonla geldiği için yalnız kısmen okunuyor: `package nyp14b;`, `private Account a...`, `private double am...`, kurucuda `this.account = ...`, `run()` içinde `account.depos...`. Anlatıma göre ilişkili hesap ve her seferinde yatırılacak miktar ayrı üye alanlarda tutulur, kurucu ikisini de atar ve `run()` yalnız bir kez para yatırır. Çeken sınıf aynı yapıdadır, yalnız `withdraw` çağırır.

`Account` sınıfının kodu karelerde görünmüyor. Anlatıma göre bakiye `balance` üyesinde tutulur, kurucu onu ilk değerle atar, `getBalance()` getter metodu vardır. Normalde `withdraw` yalnız `balance -= amt;` olurdu. Hoca yarışı kolaylaştırmak için metodu uzattı: önce `getBalance()` ile mevcut bakiye bir yerel değişkene (`currentBalance`) alınır, sonra rastgele kısa bir süre beklenir (`possibleDelay`), en son `balance = currentBalance - amt;` yazılır. Bekleme, thread'in tam bu arada beklemeye geçme olasılığını artırmak içindir. `deposit` de aynı biçimde kurulmuştur. Tek thread'le çalışıldığında hiçbir sorun yoktur. <!-- BELİRSİZ: Account kodu karelerde yok; yapı anlatımdan kuruldu. Altyazıda bekleme "5000 saniye" diye geçiyor; büyük olasılıkla birkaç milisaniyelik rastgele bir beklemedir. -->

### 5.3 Simülasyon ve beklenmeyen sonuç

Ana program (ekrandan, 01:35:00):

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

Bu kare sonraki `nyp14d` paketinden alındı; `main` metodu `nyp14b`'dekiyle aynıdır. Önbellekli ya da sabit havuz seçmenin burada farkı yoktur: 150 görevin hepsine yetecek kadar paralel yürütme birimi yoktur, çoğu illa beklemede kalır.

Hesap: 100 lira yatırılır, 50 lira çekilir, 50 lira kalmalıdır. Ama çalıştırınca `Before: 0.0`, `After: 5.0` çıktı (ekrandan, 01:10:00). Tekrar tekrar çalıştırılınca da 50 çıkmadı. Görevler çok thread'li olmasaydı 50 çıkacaktı.

İkinci sürüm `BankSimulationV2` (ekrandan, 01:10:00):

```java
package nyp14b;
import java.util.concurrent.*;
public class BankSimulationV2 {
    public static void main(String[] args) {
        Account anAccount = new Account(1000);
        System.out.println("Before: "+anAccount.getBalance());
        ExecutorService executor = Executors.newCachedThreadPool( );
        AccountWithdrawer task=new AccountWithdrawer(anAccount,100);
        executor.execute(task);
        AccountWithdrawer task2=new AccountWithdrawer(anAccount,50);
        executor.execute(task2);
        executor.shutdown();
        while( !executor.isTerminated() );
        System.out.println("After: "+anAccount.getBalance());
    }
}
```

Bin liralık ortak hesaptan bir kişinin thread'i 100, diğerinin thread'i 50 lira çeker. $1000 - 150 = 850$ beklenir, ama 950 çıktı. Sanki çekimlerden biri hiç işlenmemişti.

### 5.4 Arka planda ne oluyor?

Hoca durumu, her thread'in bir solucan gibi kod üzerinde yavaş yavaş ilerlediği bir animasyonla anlattı. İki görev nesnesi oluşturulur ve havuza eklenir; ikisi de çalıştırılabilir duruma gelir. Havuz olduğu için aynı anda çalışabilirler. Ama banka hesabı tek bir nesnedir, orada paralellik yoktur; biri `withdraw`'a önce girer.

> **Hocanın vurgusu:** Yarış koşulunu doğuran en önemli sebeplerden biri şudur: her thread'in kendi yerel değişken kopyaları vardır, ama üye alanlar thread'ler arasında paylaşılır.

Adım adım (bakiye 1000):

- Birinci thread `withdraw`'a girer, `getBalance()` ile 1000 okur ve kendi yerel `currentBalance` değişkenine yazar.
- İkinci thread de girer, o da 1000 okur. Onun `currentBalance` kopyası bellekte ayrı bir yerde, kendi metot çağrısının yığıtındadır.
- Birinci thread beklemeden sonra `balance = 1000 - 100` yazar. Üye alan `balance` artık 900'dür. Birinci thread'in işi biter.
- İkinci thread kaldığı yerden devam eder. Onun `currentBalance` değeri hâlâ 1000'dir. `balance = 1000 - 50 = 950` yazar.
- 900 değeri kaybolur, en son 950 saklanır. Sonuç 850 değil 950'dir.

## 6. synchronized ile yarışın önlenmesi

### 6.1 Kural

Slayttaki maddeler (ekrandan, 01:15:00): Yarışa yol açabilecek metotlar belirlenir ve `synchronized` anahtar kelimesiyle işaretlenir. Bir `synchronized` metodu aynı anda yalnız bir thread çalıştırabilir, öbürleri bekler. Bu, Java'da yarışı önlemenin en basit yoludur.

Önceki örnekte iki thread de `withdraw`'a girmek istediğinde metot ikisini birden kabul etmez. Önce giren thread'e öbürü "dur, bekle" denir. İlk thread atamaları doğru biçimde yapıp çıkınca ikincisi her şey tutarlıyken çalışır ve güncel değeri yazar. İşler sırayla yürür.

Hoca burada bir soruyu kendisi sordu: o halde çok thread'li çalışmanın anlamı ne kaldı? Bir thread'in yaptığı her iş yarışa yol açmaz, yalnız belirli işler açar. Geri kalan işler yine paralel yürür ve bir performans kazancı olur. Bu kazanç tam iki kat olmaz; yarış durumlarının yoğunluğuna göre örneğin 1,5 ya da 1,8 kat olabilir.

> **Hocanın vurgusu:** Burada asıl önemli olan performans değil, hesaplamaların doğru yapılmasıdır. Aksi halde yazılımda bir hata (bug) vardır ve hatalı bir yazılım kullanılmamalıdır.

### 6.2 Hangi metotlar işaretlenir?

Yapılacak tek şey yarışa yol açabilecek metotları bulmaktır. Bunun için ortak kullanılan veri alanlarının atandığı ve okunduğu her metot aranır ve başına `synchronized` konur. `Account` sınıfında `withdraw` ve `deposit` ortak veriye erişir; ikisi de işaretlenmelidir.

> **Hocanın vurgusu:** Yalnız birini `synchronized` yapmak yetmez. Paylaşılan alana (`balance`) okuma ya da yazma amacıyla erişen bütün metotlar işaretlenmelidir. Görev sınıflarının koduna başka hiçbir şey yapılmaz.

Hoca Eclipse'te iki metodun imzasına `synchronized` ekledi ve iki simülasyonu yeniden çalıştırdı:

- `BankSimulation`: önce 0, sonra 50. Doğru sonuç. Ama çalışma hissedilir biçimde biraz uzun sürdü. Önceki sürümde 150 thread serbestçe girip değişiklik yapıyordu, daha hızlı bitiyordu ama yanlış sonuç üretiyordu.
- `BankSimulationV2`: `Before: 1000.0`, `After: 850.0` (ekrandan, 01:20:00). Burada süre farkı hissedilmedi, çünkü yalnız iki işlem vardı.

### 6.3 Thread-safe veri yapıları

Hoca daha önce veri yapıları konusunda bazı yapıların thread-safe olduğundan söz ettiğini hatırlattı. Thread-safe yapılar aslında `synchronized` yapılardır: liste yapıları için `Vector`, tablo (map) yapıları için `Hashtable`. Çok thread'li programlarda doğru sonuç almak için bunların kullanılması gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** `Vector` ve `Hashtable`'ın tek tek metotları senkronizedir, ama "önce kontrol et, sonra ekle" gibi birden çok çağrıdan oluşan bileşik işlemler yine dışarıdan senkronize edilmelidir. Daha yeni kodda `Collections.synchronizedList(...)` ya da `java.util.concurrent` paketindeki `ConcurrentHashMap` gibi sınıflar da kullanılır.

## 7. Ek havuz ve thread örnekleri

Normal ders içeriği iki ders saatinden önce bitince hoca `nyp14a` ve sonraki paketlerde atlanan örneklere döndü.

### 7.1 Atanmamış thread nesnesi

`MatchV2` sınıfında (ekrandan, 01:25:00) tek bir geçici `Thread` değişkeni kullanılır, her seferinde doğrudan bir `Runnable` nesnesiyle kurulur:

```java
package nyp14a;

public class MatchV2 {
    public static void main(String[] args) {
        Thread aThread;
        aThread = new Thread( new SoccerFan("G.S.", "Rulez!") );
        aThread.run();
        aThread = new Thread( new SoccerFan("G.S.", "is the champ!") );
        aThread.run( );
        aThread = new Thread( new SoccerFan("F.B.", "is no.1!") );
        aThread.run( );
        aThread = new Thread( new SoccerFan("F.B.", "is the best!") );
        aThread.run( );
/*      aThread = new Thread( new Refree("calm down") );
        aThread.start();*/
    }
}
```

Bu sürümde `run()` çağrıldığı için görevler paralel değil, sırayla çalışır. Hoca bunun yanlış kullanım olduğunu ve önceki derste konuşulduğunu hatırlattı. Gösterimden sonra `start()` kullanılarak paralel çalışma sağlandı, sonra yanlış örnek olarak görülmesi için kod yine `run()` haline döndürüldü.

Hoca ayrıca thread nesnesinin bir değişkene atanması bile gerekmediğini gösterdi: `new Thread(new SoccerFan(...)).start();` biçiminde nesne oluşturulur oluşturulmaz `start()` çağrılabilir. Bu şart değildir, ama aynı işi yapan ilginç bir gösterimdir. Çalıştırınca tezahüratlar yaklaşık 5 saniyede tamamlandı.

### 7.2 Hakem sınıfı

Taraftarların arasına başka sınıftan ama yine bir görev olan bir nesne konabilir mi? Bunun için `Refree` (hakem) sınıfı yazılmıştı. Sıfırdan değil, `SoccerFan`'ın alt sınıfı olarak oluşturulmuştur. Hakem bir takım tutmaz, takım için tezahürat yapmaz, verdiği uyarıyı (örneğin "calm down", "Play nicely!") yazar. O da 10 kez, aralarda bekleyerek işini yapar. `start()` ile çalıştırınca tezahüratların arasına hakemin "sakin olun" uyarısı da girdi ve iş yaklaşık 6 saniyede bitti.

### 7.3 Her görev için ayrı Thread değişkeni

**Soru (hocanın sorusu):** Her taraftar için ayrı bir `Thread` değişkeni oluşturulursa bir sakıncası ya da avantajı olur mu?

**Cevap:** Bir avantajı olmaz. Belki çok küçük, hissedilmeyecek bir dezavantajı olabilir. Ölçümde yine 4,5-5 saniye sürdü. Referans çalıştırma kuyruğuna verildikten sonra değişken başka bir nesneyi gösterecek biçimde değiştirilebilir, bu bir soruna yol açmaz. Hoca geçici değişkenleri yalnız gerçekten gerekiyorsa kullandığını, burada tek bir `Thread` değişkeninin yeterli olduğunu söyledi.

### 7.4 Ayrıntılı (verbose) sürüm

"Verbose", bir işin yürütülme adımları hakkında çok fazla bilgi vermek demektir; bir tür hata ayıklama (debug) kipi gibi düşünülebilir. Bir şeylerin ters gittiğinden şüphelenildiğinde ya da adımların sırası incelenmek istendiğinde kullanılır.

`MatchWithPoolVerbose` sınıfında her adımdan sonra bir numara yazdırılır (ekrandan, 01:30:00):

```java
public static void main(String[] args) {
    System.out.println("1");
    long begin = System.currentTimeMillis();
    System.out.println("2");
    ExecutorService pool = Executors.newCachedThreadPool();
    System.out.println("3");
    pool.execute( new SoccerFan("G.S.", "Rulez!") );
    System.out.println("4");
    pool.execute( new SoccerFan("G.S.", "is the champ!") );
    System.out.println("5");
    pool.execute( new SoccerFan("F.B.", "is no.1!") );
    System.out.println("6");
    pool.execute( new SoccerFan("F.B.", "is the best!") );
    System.out.println("7");
    //pool.execute( new Refree("Play nicely!"));
    System.out.println("8");
    pool.shutdown( );
    System.out.println("9");
    System.out.println("Shutdown initiated");
    System.out.println("10");
    ...
```

Kodun devamı karede görünmüyor; anlatıma göre `isTerminated()` döngüsünden sonra 11 yazdırılır, bitiş zamanı alınır ve geçen süre yazdırılır. <!-- BELİRSİZ: 24. satırdan sonrası karede yok, anlatımdan özetlendi. -->

Konsolda önce 1-5, sonra ilk tezahüratlar ("G.S. is the champ!", "G.S. Rulez!"), sonra 6 göründü. Hoca bunun mantıklı olduğunu söyledi: havuz oluşturulup görevler verildikten sonra, yani en azından 3 yazıldıktan sonra ilk tezahüratlar başlayabilir. Konsol yazma işini Eclipse ayrı bir thread'le yaptığı için sıra çalıştırmadan çalıştırmaya değişebilir. "Shutdown initiated" ve 10 yazıldıktan sonra da tezahüratlar bir süre devam etti, çünkü `shutdownNow()` değil `shutdown()` çağrılmıştı ve havuz işlerin bitmesini bekliyordu. 10'un 11'den önce görülmesi ise kesindir. Bir çalıştırma 5,8 saniye sürdü.

### 7.5 Gecikme olmadan da yarış olur mu?

`nyp14b` ile `nyp14c` paketlerinin farkı, `synchronized` olmayan (yanlış çalışan) ve `synchronized` olan (doğru çalışan) sürümlerdi. Hoca yeni bir `nyp14d` paketi açıp şunu sordu: yarış için "kaşındık", gecikmelerle durumu abarttık. Daha doğal kodlayıp `synchronized` kullanmadan yarıştan kaçınılabilir miydi?

`withdraw` ve `deposit` gövdeleri yalın biçimde yazıldı:

```java
balance -= amount;   // withdraw
balance += amount;   // deposit
```

`BankSimulation` yine yanlış sonuç verdi: 53, sonra 54, 51; arada bir 50. Hoca 5 kez yanlış yapıp bir kez doğru yapmanın düzgün bir çalışma olmadığını söyledi.

> **Hocanın vurgusu:** Bir program bazen doğru, bazen yanlış çalışıyorsa hatanın sebebini bulmak çok daha zordur. Bu durum her seferinde yanlış çalışmaktan bile kötüdür.

Tek bir çekme ve tek bir yatırma işlemi olan `BankSimulationV2` ise 850 verdi. Metodun başına ve sonuna yeniden gecikme konunca da doğru sonuç alındı. Hoca sonra kodda bir `synchronized` kaldığını fark edip kaldırdı; sonuç yine 850 oldu. <!-- BELİRSİZ: Altyazıda bu denemenin sonucu önce "800" diye geçiyor, ama hoca hemen ardından "doğru sonuçlar alıyoruz" diyor; büyük olasılıkla 850'nin yanlış yazımıdır. --> İşlem sayısı çok az olduğu için arka planda biriken bir çakışma olmuyordu. Ama hoca bunun bir güvence olmadığını, aynı kodun eski bir masaüstü bilgisayarda 900 ya da 950 verebileceğini söyledi. Gerçek bir banka bilgi sisteminde on binlerce kişi aynı anda farklı hesaplara para yatırıp çekeceği için özenle yazılmış kodda bile yarış koşulları kaçınılmaz olarak ortaya çıkar. 150 işlemli simülasyonda ise yeniden 44, 40, 45 gibi sonuçlar görüldü; on çalıştırmada ancak bir kez doğru sonuç alındı.

> **Ek bilgi (derste anlatılmadı):** `balance -= amount;` tek satır olsa da makine düzeyinde "oku, çıkar, yaz" adımlarından oluşur ve atomik değildir. Bu yüzden gecikme olmadan da araya başka bir thread girebilir. Tek bir sayaç için `java.util.concurrent.atomic` paketindeki `AtomicInteger` gibi sınıflar da kullanılabilir.

## 8. JUnit ile birim sınama

### 8.1 Neden otomatik sınama?

Hoca bu konuyu önceki derslerde işleyip işlemediğinden emin olmadığı için, soru soran bir öğrenci için kısaca üstünden geçti.

Dönem boyunca yazılan kodlar şöyle denenmişti: nesneler oluşturulup ilişkiler kurulur, metotlar çağrılır. Bazı metotlar işlemin başarılı olup olmadığını `true`/`false` döndürür; dönen değer beklenen değer mi diye `if-else` ile bakılır ve "kaçıncı test başarısız" diye ekrana yazdırılır. Bazen de, örneğin araba galerisi örneğinde, listelenen arabalar gözle satır satır okunup eksik ya da fazla satır var mı diye kontrol edilir.

Bu işler test verimliliğini düşürür ve otomatikleştirilmelidir. Sahada 3-4 sınıflı, 20-30 satırlık projeler değil, binlerce satırlık kodlar geliştirilecektir. Böyle büyük bir kodu elle sınamak çok verimsizdir.

Birim (unit), kullanılan programlama yaklaşımındaki temel işlem birimidir. Nesneye yönelik yaklaşımda bu nesnedir, ama kodun doğruluğu sınıflara yazılan metotların doğru çalışıp çalışmadığı sınanarak test edilir. Sınıf düzeyinde tasarlanan testler en küçük test düzeyidir ve bunlara birim testi (unit test) denir. Hoca, sınama türlerinin yazılım mühendisliği dersinde ayrıca işleneceğini ve yazılım kalitesi ile testin başlı başına bir konu olduğunu söyledi.

JUnit, birim testleri tasarlamak, çalıştırmak ve bir yanlışlık olduğunda hatayı analiz etmek için kullanılan bir araç/kütüphane/çerçevedir (framework). Bilinmesi gereken iki önemli sürüm 3.x ve 4.x'tir; her biri yeni ve önemli bir yetenek getirir. Hoca daha yeni sürümlerin (5, belki 6) çıktığını ama getirdiklerine şu an ihtiyaç olmadığını söyledi. Her sürüm geriye doğru uyumludur, eski sürüme göre yazılmış test durumlarını sorunsuz çalıştırır.

### 8.2 JUnit 3.x

Slayttaki maddeler ve UML şeması (ekrandan, 01:50:00):

- Her sınıfın birim sınaması için test durumları ayrı sınıflarda, `testXXX()` gibi metotlarda hazırlanır.
- İstenirse test durumları bir test grubunda (test suite) birleştirilir; bunun için statik `TestAll.suite()` metodu kullanılır.
- `TestCase.setup` metodu her `testXXX()` metodu çalışmadan önce çalışır.

```text
junit.framework                     myPackage
  TestCase                            AppClass1  <---  TestAppClass1 (+ testXXX())
    # setup()                         AppClass2  <---  TestAppClass2 (+ testYYY())
  Assert                              TestAll (+ suite() : Test) --> TestAppClass1, TestAppClass2
    + assertEquals( beklenen, sonuc : Object )
    + assertNotEquals( Object, Object )
    + assertTrue( boolean )
    + assertFalse( boolean )
    + assertNull( Object )
    + assertNotNull( Object )
  (TestAppClass1 ve TestAppClass2, TestCase'ten türer)
```

Kurallar şöyledir:

- Uygulama sınıfları `AppClass1`, `AppClass2` olsun ve `myPackage` paketinde yer alsın. Test edilmek istenen her sınıf için adı `Test` ile başlayan, devamı test edilen sınıfın adı olan bir sınıf yazılır: `TestAppClass1`, `TestAppClass2`.
- Test sınıfları `junit.framework` paketindeki `TestCase` sınıfından kalıtımla türetilmek zorundadır.
- Test metotlarının adı `test` ile başlar. Örneğin `TestAppClass1.testXXX()`, `AppClass1`'in sorumluluklarından birini sınar.
- `TestCase`'teki korumalı (protected) `setUp` metodu geçersiz kılınarak "sahne hazırlanır": testlere başlamadan önce gereken nesneler oluşturulur. JUnit, `testA`, `testB`, `testC` metotları için sırasıyla `setUp, testA, setUp, testB, setUp, testC` biçiminde çalıştırır.
- Test metotlarında `Assert` sınıfının statik `assertXXX` metotları kullanılır.

Sınamanın temel mantığı: metot çalıştırıldıktan sonra elde edilen sonuç beklenen değere eşitse test başarılıdır.

- `assertEquals(beklenen, sonuc)`: iki parametre eşitse test başarılı, değilse başarısız işaretlenir.
- `assertNotEquals`: ters mantık; testin geçmesi için iki nesnenin eşit olmaması gerekir.
- `assertTrue(boolean)`: testin geçmesi için bir mantıksal ifadenin `true` olması gerekir. Tersi `assertFalse`.
- `assertNull(Object)`: testin geçmesi için nesnenin `null` olması gerekir. Tersi `assertNotNull`.

Hoca `assertNull` için galeri örneğini hatırlattı: galeriye bir araba eklenir, sonra satılır ve galeriden silinir. Plakayla o araba istenince `null` dönmesi beklenir; bunun için `assertNull` uygundur. İstenirse `assertTrue(donen == null)` da yazılabilir. JUnit belirli bir yolu zorlamaz, çeşitli seçenekler sunar.

Test sınıfları çoksa her birini ayrı ayrı çalıştırmak yerine istenen kadar test sınıfı bir test grubunda toplanabilir. Bunun için `suite()` metodu yazılır (bkz. 9.4).

3.x'in tek eksiği bir istisnanın fırlatılmasını sınayamamaktır. Denetlenen ya da denetlenmeyen bir istisna oluşunca bütün program akışı durur. Oysa "bu istisnanın oluşması gerekiyor; oluştuysa sorun yok, sonraki teste geç; oluşmadıysa bu testten kaldım de, yine de öbür testleri yürüt" gibi bir çalışma istenebilir. Bunun için 4.x sürümü gerekir.

> **Ders sonrası not:** Hoca `assertEquals` için "iki parametre aynı nesneyse `true` döndürür" dedi. Büyük olasılıkla doğrusu şudur: `assertEquals` karşılaştırmayı `equals()` ile yapar, yani aynı nesne olmak değil eşit değerde olmak yeterlidir; aynı nesne olma `assertSame` ile sınanır. Ayrıca `assert` metotları değer döndürmez, başarısızlıkta bir hata (`AssertionFailedError`) fırlatır ve JUnit testi başarısız işaretler.

### 8.3 JUnit 4.x

4.x sürümü sınıf ve metot adlarının `test` ile başlama zorunluluğunu kaldırır. Hoca bunu aslında kısıtlayıcı bulmadığını söyledi: dönem boyunca sınıf ve metot adlarının anlaşılır olmasına özen gösterildi; adı `test` ile başlayan bir sınıfın ya da metodun test için olduğu zaten kolayca anlaşılır. Ama 4.x'te bu zorunlu değil, seçimliktir.

Ad yerine annotation kullanılır. Annotation'lar `@` ile başlayan satırlardır. Hoca bunları daha önce, kod üzerinde işlem yapan başka uygulamalara bilgi aktarmak için kullanılan satırlar olarak anlattığını hatırlattı; örneğin `@SuppressWarnings` ile bazı uyarılar gizlenebiliyordu. JUnit 4 kendi annotation'larını tanımlar:

- Hazırlık işlemlerini yapan metodun adı `setUp` olmak zorunda değildir; başına `@Before` yazılması yeterlidir.
- Test metotlarının adı `test` ile başlamak zorunda değildir; başına `@Test` yazılması yeterlidir.
- Bir istisnanın oluşup oluşmadığına göre test kurmak için `@Test` annotation'ına, metot çağırır gibi parantez içinde parametre verilir: `@Test(expected = BirException.class)`. Bu durumda `assert` kullanılmaz. Test kodu içinde o istisna fırlatılırsa test başarılı, fırlatılmazsa başarısızdır.
- İstisna denetlenen bir istisnaysa Java dil kuralı gereği ya `try-catch` içine alınmalı ya da `throws` ile bildirilmelidir. Burada istisnanın çıkması istendiği için `try-catch` yapılmaz, test metoduna `throws` eklenir.

<!-- BELİRSİZ: JUnit 4.x slaytı karelerde yok; bu bölüm anlatımdan yazıldı. -->

## 9. Film kiralama örneği üzerinde JUnit

### 9.1 Örneğin kaynağı ve tasarımı

Hoca kullanımı göstermek için basit bir film kiralama uygulaması kullandı. Slaytta kaynak olarak Martin Fowler'ın *Refactoring: Improving the Design of Existing Code* (Addison-Wesley, 1999) kitabı yazıyor (ekrandan, 02:00:00). Senaryo: müşteriler video kasetinde filmler kiralar.

Müşteri ile film arasında ilişki doğrudan kurulmaz, çünkü bir kiralama işlemi vardır ve belirli bir gün sürer. Bu yüzden bir `Rental` (kira kaydı) sınıfı vardır. Slayttaki sınıf şeması (ekrandan, 02:00:00):

```text
Customer                          (1) ---- (*) Rental
  + statement()                   Rental
  + getTotalCharge() : double       - _daysRented : int
  + getTotalBonus() : int           + getCharge() : double
                                    + getBonus() : int
                                    + getMovieTitle() : String
Rental (*) ---- (1) Movie
Movie
  - _priceCode : int
  + getCharge( daysRented : int ) : double
  + getBonus( daysRented : int ) : int
```

Sıralama şemasına göre kullanıcı `statement()` çağırır. Müşteri her kira kaydı için `getMovieTitle()` (o da filmin `getTitle()` metodunu çağırır) ve `getCharge()` (o da `getCharge(_daysRented)` çağırır) ile makbuz satırlarını oluşturur. Sonra `getTotalCharge()` bütün kira kayıtlarında `getCharge()`, `getTotalBonus()` da bütün kira kayıtlarında `getBonus()` çağırarak toplamları hesaplar ve makbuz tamamlanır.

Filmlerin üç fiyat kodu vardır: normal filmler (`REGULAR`), yeni çıkan filmler (`NEW_RELEASE`) ve çocuk filmleri (`CHILDRENS`). `statement()` metodu işlem dökümünü verir: hangi filmi kaç gün kiraladığınız, her biri için borcunuz, toplam borcunuz ve kazandığınız puan.

### 9.2 Sınıfların kodu

`Customer`: üye alanların adı alt çizgiyle başlar. Hoca bunun nedenini şöyle açıkladı: kitapta refactoring öncesi ve sonrası karşılaştırılırken siyah-beyaz baskıda hangi adın üye alan, hangisinin parametre ya da geçici değişken olduğu renkle ayırt edilemez. Bu yüzden yazar üye alanları alt çizgiyle adlandırmış; hoca da örnekte bunu sürdürmüş. Müşterinin bir adı ve kira kayıtları vardır. Bire-çok ilişki `Vector` ile tutulur. Kurucu adı alır; listeye kira kaydı ekleyen bir metot, ad için getter metodu vardır. Silme ya da aynı kiralamanın tekrarını kontrol eden metot yoktur, çünkü örneğin amacı refactoring ve test durumlarını anlatmaktır.

Testlerin odağı `statement()` metodudur. Makbuzu doğrudan ekrana yazdırmaz, bir `String` içinde biriktirip döndürür. Böylece bu metin komut satırına, bir GUI penceresine ya da bir HTML sayfasına yazılabilir. Testler de beklenen ve elde edilen metni karşılaştırarak kolayca yapılır. Toplam bedel ve toplam bonus için ayrı metotlar vardır.

`Rental`: bir müşteriyle ve bir filmle ilişkilidir, kaç gün kiralandığını tutar. Kurucu ikisini alır, getter metotları vardır. Kiralamanın bedelini hesaplamak için gereken bilgi kira kaydı ile film arasında dağılmıştır: fiyat kodu ve gün sayısına göre bedel hesaplayan kod filmde, gün sayısı kira kaydındadır. Bu yüzden kira kaydı filme "bu kadar gün kiralandın, ne kadar ödenmesi gerekiyorsa bildir" der. Bonus da benzer biçimdedir.

`Movie`: üç fiyat kodu `public final int` sabitleri olarak tanımlıdır. Filmin adı ve fiyat kodu vardır; kurucu ikisini alır. Fiyat kodu için getter ve setter vardır, çünkü çocuk filmi hep çocuk filmi kalır ama yeni çıkan bir film bir süre sonra işletme sahibi tarafından normal filme düşürülebilir. Ad için getter metodu da vardır. `getCharge` metodu (ekrandan, 02:10:00 ve 02:20:00):

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

Kurallar şunlardır:

- Normal film: her kiralama 2 lira, bu ücretle kaset 2 gün tutulabilir; 2 günü aşan her gün için 1,5 lira daha.
- Yeni film: kiralanan gün başına 3 lira.
- Çocuk filmi: 1,5 lira ile 3 günlük kiralama; 3 günü aşan her gün için 1,5 lira daha.

Bonus kuralı: her kiralama için 1 puan, yeni film 1 günden uzun kiralanmışsa 1 puan daha.

### 9.3 Test sınıfları

İlk test sınıfı `TestMovie`'dir. Adı `Test` ile başlar ve `TestCase`'ten türer. İçinde tek bir test metodu vardır: üç ayrı türden üç film oluşturulur ve fiyat kodları karşılaştırılır. Farklı tür iki filmin fiyat kodu eşit olmamalıdır; bu `assertTrue` ile "eşit değil" ifadesi üzerinden, öbür durumda `assertFalse` ile "eşit" ifadesi üzerinden sınanır. Hoca, normalde hazırlığın `setUp` içinde yapılacağını, test basit olduğu için her şeyin tek metoda yığıldığını ve bunun çok güzel olmadığını söyledi.

Bu testte bir `assert` çağrısına ilk parametre olarak bir açıklama metni verilmiştir. Bütün `assert` metotları aşırı yüklenmiştir (overloaded); ilk parametre olarak verilen metin, test başarısız olursa gösterilecek açıklamadır. Hoca istisnalarda mutlaka açıklama verilmesini önerdiğini, ama test durumlarında kendi açıklamamızı vermenin tercih edilmeyebileceğini söyledi, çünkü JUnit zaten çok iyi bir açıklama verir.

Daha düzgün yazılmış olan `TestCustomer` sınıfının başı (ekrandan, 02:15:00; müşteri adı ve değişken adı genelleştirildi):

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

    public void testStatementWhenEmpty( ) {
        String sonuc = musteri.statement();
        ...
```

Üye alan olarak bir müşteri ve dört film tanımlanmıştır; `setUp` hepsini ilk değerle kurar. `setUp` içinde kiralama yapılmaz, çünkü ilki dışındaki bütün testler farklı filmlerin farklı günlerle kiralanmasıyla ilgilidir. `setUp`'a yalnız bütün testlerde ortak olan hazırlık konur.

Test metotları şunlardır:

- `testGetName`: müşterinin adı doğru alınıyor mu? Hoca "bu da test edilir mi?" diye sorulabileceğini söyledi. Ama adda Türkçe karakter olduğu için bu test sistemin Türkçe karakterleri doğru işleyip işlemediğini de sınar.
- `testStatementWhenEmpty`: müşteri henüz hiç film kiralamadıysa borç ve puan sıfır olmalıdır. Sıfır bedelli boş makbuz metni elle oluşturulur ve `statement()` sonucuyla karşılaştırılır. Metot adı, uzun olsa da amacı anlatacak biçimde camelCase ile verilmiştir.
- `testStatementWithMoviesLongRent`: bazı filmler uzun süre kiralanır, makbuz beklenen makbuzla karşılaştırılır.
- `testStatementWithMoviesShortRent`: filmler kısa süre kiralanır.
- `testNewReleaseRentalBonus`: iki yeni film, biri uzun biri kısa süre kiralanır; toplam bonusun 3 olup olmadığına bakılır.

### 9.4 Test grubu (suite)

`TestMovie` ve `TestCustomer`'ı birleştirmek için `TestAll` sınıfında bir `suite()` metodu yazılır. Anlatıma göre bir `TestSuite` nesnesi kurucusuna bir ad verilerek oluşturulur, eklenecek test sınıfları sırayla parametre olarak verilerek eklenir ve en sonunda bu grup döndürülür. Metodun imzası `public static Test suite()` biçimindedir. Ders sırasında böyle bir kod büyük olasılıkla aşağıdakine benzer:

```java
public static Test suite() {
    TestSuite suite = new TestSuite("...");
    suite.addTestSuite(TestMovie.class);
    suite.addTestSuite(TestCustomer.class);
    return suite;
}
```

<!-- BELİRSİZ: TestAll kodu karelerde yok; yukarıdaki kod anlatımdan kuruldu, metot ve ad ayrıntıları doğrulanamadı. -->

`TestAll` üzerinde sağ tıklanıp JUnit testi olarak çalıştırılır. `main` metodu olmadığı için uygulama olarak değil, test olarak çalışır. `TestCustomer`'da 5, `TestMovie`'de 1 test durumu vardır. `TestMovie` içinde 3 `assert` olsa da bu tek bir test metodudur ve testin geçmesi için hepsinin başarılı olması gerekir. 6 testin hepsi geçti ve yeşil çubuk görüldü.

### 9.5 Hatanın testle bulunması

Hoca bilerek bir hata yaptı: müşteri normal filmler için 2 günü aşan her gün başına 1,5 lira istemişti, ama yanlış anlaşılıp 1 lira kodlandı:

```java
result += (daysRented - 2) * 1.0;
```

Bütün testler yeniden çalıştırılınca JUnit penceresinde `Runs: 6/6`, `Errors: 0`, `Failures: 1` ve kırmızı çubuk göründü (ekrandan, 02:20:00). Başarısız test `testStatementWithMoviesLongRent` idi. Hata izinde (Failure Trace) `junit.framework.ComparisonFailure` ile beklenen ve gerçek metin gösterildi:

```text
expected:<...
The Matrix 3.[5
Monsters, Inc. 3.0
Surrogates 6.0
Amount owed is 12.5]
You earned 4 freque...> but was:<...
The Matrix 3.[0
Monsters, Inc. 3.0
Surrogates 6.0
Amount owed is 12.0]
You earned 4 freque...>
```

JUnit iki metnin ayrılmaya başladığı yeri köşeli parantezle işaretler. Hocanın dediği gibi bu, bizim yazacağımız bir açıklamadan çok daha iyi bilgi verir.

Tutarların kontrolü (gün sayıları karedeki tutarlardan geri hesaplandı, ara adım eklendi):

- The Matrix (normal film, 3 gün): $2 + (3-2) \times 1{,}5 = 3{,}5$
- Monsters, Inc. (çocuk filmi, 4 gün): $1{,}5 + (4-3) \times 1{,}5 = 3{,}0$
- Surrogates (yeni film, 2 gün): $2 \times 3 = 6{,}0$
- Toplam: $3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$
- Bonus: 3 kiralama için 3 puan, 1 günden uzun kiralanan yeni film için 1 puan daha, toplam 4 puan.
- Hatalı kodla The Matrix: $2 + 1 \times 1{,}0 = 3{,}0$, toplam 12,0.

Hatanın yerini bulma akışı şöyleydi: ilk fark The Matrix'in kira bedelinde başlıyor. Test sınıfında The Matrix'in normal film olduğu görülüyor. Demek ki normal filmlerin hesabında bir hata var. `getCharge` metodunun `REGULAR` durumuna bakılıyor, 1,5 yerine 1 yazıldığı görülüp düzeltiliyor. Testler yeniden çalıştırılınca yeşil çubuk geliyor.

## 10. Tasarım, refactoring ve tasarım kalıpları

### 10.1 switch-case uyarısı

Hoca, normalde böyle fiyat kodlu bir tasarıma varmayacağını söyledi. `Movie` sınıfını soyut yapar, normal film, yeni film ve çocuk filmi için somut alt sınıflar oluşturur, `getCharge` metodunu soyut tanımlayıp her alt sınıfta geçersiz kılardı. En doğru tasarım budur.

> **Hocanın vurgusu:** Kendinizi bir yerde `switch-case` ya da `if - else if - else` zinciriyle tür ayrımı yaparken bulursanız büyük olasılıkla tasarımınızda bir eksik vardır. Bu, kalıtım ve çok biçimlilik üzerinden yürüyen bir kod yazmanız gerektiğinin en önemli sinyalidir.

### 10.2 Refactoring

Örnek neden böyle? Kitaptaki hikâye çok kötü bir tasarımla başlar ve kod birkaç refactoring adımından sonra bu hale gelir; sonra başka adımlar da gelir. Refactoring'in özü, dışarıya verilen hizmetleri değiştirmeden iç yapıyı değiştirmektir. Fiyat kodlu `Movie` ile başlanmış olduğu için soyut sınıf ve alt sınıflara geçmek daha önce yazılmış kodla uyumsuzluk yaratır. Bu aşamada daha iyi tasarımın avantajı yerine geriye doğru uyumluluğun avantajı tercih edilmiştir.

Yanlış kullanılan nesne yönelimi bir hata (bug) değildir, ama esnek olmayan bir tasarım üretir. Gereksinimler değiştikçe değişiklikler rahatça hayata geçirilemez. Bunu düzeltmek için kodu baştan yazmak yerine küçük adımlarla, refactoring eylemleriyle ilerlenir. Her refactoring adımından önce test durumları çalıştırılmalıdır, çünkü iyileştirme amacıyla yapılan değişiklik de hata oluşturabilir.

### 10.3 Tasarım kalıpları

Hoca, yazılım geliştirme alanında çalışmak isteyenlere nasıl doğru nesneye yönelik tasarım yapılacağı sorusuna yanıt veren tasarım kalıplarını (design patterns) çalışmalarını önerdi. Bir işin nasıl doğru yapılacağını bilmenin yanında nasıl yanlış yapılabileceğini ve yanlışın nasıl düzeltileceğini bilmek de önemlidir; bu da kod kusurları (code smells) ve refactoring konusudur. Bu konuların kendi kendine çalışmaya çok uygun olduğunu söyledi. Dönem boyunca hep doğru tasarımlar verilmeye çalışıldığı için bu konuda fark ettirmeden bir temel atıldığını, tasarım kalıpları üzerine çalışarak bu temelin sağlamlaştırılmasını tavsiye etti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:36:44): Dört taraftar havuzda paralel çalışıyor. Her taraftar 10 kez tezahürat yapıyor ve her tezahürattan önce 0 ile 1000 ms arasında rastgele bekliyor. Programın toplam süresi ortalama ne kadar olur?

> **Çözüm (derste verildi):** Ortalama bekleme 500 ms, bir taraftarın süresi $10 \times 500 = 5000$ ms'dir. Taraftarlar paralel çalışıp birbirini beklemediği için toplam süre de ortalama yaklaşık 5000 ms olur. Ölçümlerde 5-6 saniyelik değerler görüldü.

**Soru 2** (derste sözlü, 00:41:27): Aynı dört taraftar `newFixedThreadPool(2)` ile çalıştırılırsa süre ne olur? `newFixedThreadPool(6)` ile ne olur?

> **Çözüm (derste verildi):** Havuz 2 iken aynı anda yalnız iki thread çalışır, süre yaklaşık iki katına çıkar: yaklaşık 10 saniye (ölçümde yaklaşık 12 saniye). Havuz 6 iken dört görevin hepsi zaten aynı anda çalışabildiği için süre 4'teki gibi yaklaşık 5 saniyedir.

**Soru 3** (ekrandan, 01:10:00): Bakiyesi 0 olan hesaba 100 görev 1'er lira yatırıyor, 50 görev 1'er lira çekiyor. `synchronized` olmadan çalıştırınca `After: 5.0` çıktı. Bakiyesi 1000 olan hesaptan iki görev 100 ve 50 lira çekince de 850 yerine 950 çıktı. Neden?

> **Çözüm (derste verildi):** Yarış koşulu. `withdraw` ve `deposit` önce bakiyeyi thread'in kendi yığıtındaki yerel bir değişkene okur, sonra yeni değeri ortak üye alana yazar. İki thread de 1000 okur; biri 900 yazar, öbürü kendi kopyasıyla 950 yazar ve 900 kaybolur. Paylaşılan alana erişen bütün metotlar `synchronized` yapılınca sonuçlar 50 ve 850 oldu.

**Soru 4** (derste sözlü, 01:27:02): Her taraftar için ayrı bir `Thread` değişkeni oluşturmanın bir avantajı ya da sakıncası olur mu?

> **Çözüm (derste verildi):** Avantajı yoktur; olsa olsa hissedilmeyecek kadar küçük bir dezavantajı vardır. Ölçülen süre değişmedi (4,5-5 saniye). Görev çalıştırma kuyruğuna verildikten sonra referans değişkeni başka bir nesneye yönlendirilebilir; tek bir değişken yeter.

**Soru 5** (derste sözlü, 01:32:38): Gecikmeleri kaldırıp metotları yalın `balance -= amount;` ve `balance += amount;` biçiminde yazarsak `synchronized` kullanmadan yarıştan kaçınabilir miyiz?

> **Çözüm (derste verildi):** Hayır. 150 işlemli simülasyon 53, 54, 51 gibi yanlış sonuçlar verdi, arada bir 50 çıktı. Bazen doğru bazen yanlış çalışan bir programın hatasını bulmak daha da zordur. Çözüm yine paylaşılan alana erişen metotları `synchronized` yapmaktır.

**Soru 6** (ekrandan, 02:20:00): `Movie.getCharge` metodunda normal film için `(daysRented - 2) * 1.0` yazılınca `testStatementWithMoviesLongRent` başarısız oldu. JUnit beklenen metinde `The Matrix 3.[5` ve `Amount owed is 12.5`, gerçek metinde `The Matrix 3.[0` ve `Amount owed is 12.0` gösteriyor. Hata nerededir ve beklenen tutarlar nasıl çıkar?

> **Çözüm (derste verildi):** Fark The Matrix'in bedelinde başlıyor; bu film `REGULAR` türündedir, yani hata `getCharge` metodunun `REGULAR` durumundadır. 2 günü aşan her gün için 1,5 lira alınmalıdır, 1,0 yazılmış. 3 günlük kiralamada doğru bedel $2 + 1 \times 1{,}5 = 3{,}5$, hatalı bedel $2 + 1 \times 1{,}0 = 3{,}0$'dır. Toplam $3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$ olmalıdır. Katsayı 1,5 yapılınca bütün testler geçti.

## Dersin Toparlaması

Bu derste çok thread'li programlama konusu tamamlandı. Önce thread'leri tek tek başlatmak yerine `java.util.concurrent` paketindeki `ExecutorService` ve `Executors` ile thread havuzu kullanmak öğrenildi. Sabit (`newFixedThreadPool`) ve dinamik (`newCachedThreadPool`) havuzlar, havuzu `shutdown()`/`shutdownNow()` ile kapatmak ve `isTerminated()` ile bütün görevlerin bitmesini beklemek görüldü. Taraftar örneğinde havuz genişliğinin süreye etkisi ölçüldü. Ardından paylaşılan veriye eş zamanlı erişimden doğan yarış koşulu banka hesabı örneğiyle gösterildi. Paylaşılan alana erişen bütün metotların `synchronized` yapılmasıyla sonuçların düzeldiği, gecikmeler kaldırılsa da yarışın sürdüğü görüldü.

Dersin son bölümünde JUnit ile birim sınamaya geçildi. JUnit 3.x'te `TestCase`, `setUp()`, `testXXX()` metotları, `assertXXX` metotları ve `suite()`; 4.x'te `@Before`, `@Test` ve `@Test(expected = ...)` annotation'ları anlatıldı. Martin Fowler'ın film kiralama örneğinde testler yazıldı, bilerek eklenen bir hata kırmızı çubukla yakalanıp düzeltildi. Hoca, `switch-case` ile tür ayrımının kalıtım ve çok biçimlilikle yeniden tasarlanması gerektiğini hatırlattı ve dersin devamında kendi kendine çalışma konusu olarak tasarım kalıplarını, kod kusurlarını ve refactoring'i önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
