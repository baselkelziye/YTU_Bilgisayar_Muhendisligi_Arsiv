# Ders 20 Çalışma Özeti

## Genel Konular

- Tür dönüşümü (typecasting)
  - Kalıtımda alt sınıfın nesnesi, üst sınıfın beklendiği her yerde kullanılabilir; alt sınıf nesnesi üst tür (sınıf, soyut sınıf ya da arayüz) referansıyla takip edilebilir. Typecasting bunun tersidir: üst tür referansıyla takip edilen nesneyi alt türe çevirmek.
  - Örnek `MarketShelf` UML'i (ekrandan, 00:20:00):
    - `MarketShelf`: `- items : LinkedList<Item>`, `+ addItem( Item ) : boolean`, `+ doesExist( Item ) : boolean`, `+ printExpiredItems( )`.
    - `MarketShelf` 1 — * `«interface» Item` (birleşim ilişkisi). `Item` arayüzünde metot yoktur.
    - `Food` ve `Electronics` `Item`'ı gerçekler. `Food`: `- expireDate : Date`, `+ Food( expireDate : Date )`, `+ getExpireDate( ) : Date`, `+ isExpired( ) : boolean`. Slayttaki notlar: "electronics do not expire", "some methods excluding expiration operations".
  - `doesExist`, listede for-each ile gezip aynı nesne varsa `true` döndürür. `addItem` önce `doesExist`'i çağırır: nesne zaten varsa `false` döndürür, yoksa ekleyip `true` döndürür (altyazıdan; kodun slaytı kareye girmedi).
  - `printExpiredItems` (ekrandan, 00:25:00):

    ```java
    public void printExpiredItems( ) {
        boolean hasExpiredItem = false;
        System.out.println("Expired item(s): ");
        for( Item item : items ) {
            if( item instanceof Food )
                if( ((Food)item).isExpired() ) {
                    hasExpiredItem = true;
                    System.out.println(item);
                }
        }
        if( hasExpiredItem == false )
            System.out.println("All items are fresh!");
    }
    ```

  - `instanceof` anahtar sözcüğü: solunda bellekteki nesne, sağında sınıf adı bulunur; nesne o sınıfın örneğiyse `true` döndürür. Tür dönüşümü, sınıf adı parantez içinde referansın önüne yazılarak yapılır: `(Food)item`.
  - Dönüşümden sonra elde `Food` türünde bir referans vardır ve `isExpired()` çağrılabilir. `Electronics` nesnesinde bu metot olmadığı için `instanceof` kontrolü yapılmadan çağrı yapılamaz.
- `Calendar` ve `Date` sınıfları
  - `Math`, `Scanner`, `Random`, `Arrays`, `Collections` gibi, `Calendar` ve `Date` de sık kullanılan metotları bilinmesi gereken sınıflardır.
  - Test programı (ekrandan, 00:35:00):

    ```java
    public static void main( String[] args ) {
        MarketShelf shelf = new MarketShelf();
        Calendar cal = Calendar.getInstance();
        cal.add(Calendar.DAY_OF_MONTH,1);
        Date future = cal.getTime();
        cal.set(Calendar.YEAR, 2010);
        cal.set(Calendar.MONTH, 0); //0: January
        cal.set(Calendar.DATE, 13);
        Date past = cal.getTime();
        shelf.addItem( new Food(past) );
        shelf.addItem( new Food(future) );
        shelf.addItem( new Electronics() );
        shelf.checkForExpiration();
    }
    ```

  - `Calendar.getInstance()` bugünün tarihini taşıyan bir `Calendar` nesnesi verir. `add(Calendar.DAY_OF_MONTH, 1)` ayın gününü bir artırır (yarın). `getTime()` takvimdeki anı `Date` nesnesi olarak döndürür. `set` ile yıl, ay ve gün ayrı ayrı ayarlanır; ay 0'dan başlar (0 = Ocak).
  - `Food` sınıfı (ekrandan, 00:45:00): `isExpired()` içinde `Date today = new Date();` bugünün tarihini taşır; `expireDate.before(today)` doğruysa ürünün süresi geçmiştir. `toString()` `"A food expiring at " + expireDate` döndürür.
  - Ders sonrası not: hoca geçmiş tarihin gününü 30 diye okudu; slaytta `cal.set(Calendar.DATE, 13);` yazar. Ayrıca slayttaki `shelf.checkForExpiration();` metodu `MarketShelf`'te yoktur (hoca da belirtti); bu haliyle kod derlenmez. Yerine `printExpiredItems()` çağrılabilir. Ajan bu düzeltmeyle `java` ile çalıştırdı: yalnız 2010 tarihli `Food` "Expired item(s)" altında yazıldı.
- Typecasting'in eleştirisi (ekrandan, 00:50:00)
  - Typecasting "gerekli bir kötülüktür"; az kullanılmalıdır. Generic sınıflardan önce sık gerekirdi; bugün yalnız deserialization'da (dosyadan nesne okuma) gerekir.
  - Tasarım her zaman typecasting'siz yapılabilir: `getExpireDate( ) : Date` ve `isExpired( ) : boolean` `Item` arayüzüne taşınır. Bu durumda `Food` ve `Electronics` ikisini de gerçeklemek zorundadır ve `Item` referansıyla doğrudan `isExpired()` çağrılabilir. Slayttaki nota göre `Item` soyut sınıf da olabilir.
  - Diğer durumlarda soyut sınıflar ve çok biçimlilik kullanılmalı, alt sınıflarla doğrudan ilişki kurulmamalıdır.
- Dosya işlemleri ve ilgili istisnalar (ekrandan, 00:55:00 ve 01:05:00)
  - `java.io.IOException`: genel G/Ç istisnası. `java.io.EOFException extends IOException`: dosya ya da akışın sonuna beklenmedik biçimde ulaşıldı. `java.io.FileNotFoundException extends IOException`: dosya verilen yolda bulunamadı. `java.lang.SecurityException extends java.lang.RuntimeException`: işlem güvenlik kısıtları yüzünden yapılamıyor.
  - G/Ç istisnaları checked istisnalardır: derleyici try-catch zorunlu kılar, yoksa kod derlenmez. Unchecked istisnalarda derleyici zorlamaz, ama yakalanmazsa çalışma sırasında sorun çıkar.
  - Java'da dosya işlemleri iki gruptur: dosya yönetimi (dosya ve klasör oluşturma, adlandırma, silme) ve G/Ç işlemleri (dosyaya yazma, dosyadan okuma). G/Ç yalnız dosyalarla değil TCP soketleri gibi kaynaklarla da yapılır; bu yüzden dosya işlemlerinden ayrılmış ve bütün kaynaklar için aynı biçimde kodlanmıştır.
- Dosya yönetimi: `java.io.File` (ekrandan, 01:00:00)
  - `File` sınıfı hem dosyaları hem klasörleri temsil eder. `File` nesnesi oluşturmak, diskte gerçek bir dosya ya da klasör oluşturmak demek değildir.
  - `File( String fileName )`: ad hem yolu hem dosya/klasör adını içerir. Tam yol taşınabilirliği azaltır; göreli yol da zordur, çünkü IDE'ler kaynak ve class dosyalarını farklı klasörlerde tutabilir. Yol ayırıcı: Windows'ta `\` (string içinde `\\`), Unix'te `/`.
  - `File( String path, String name )`: yol ve ad ayrı verilir.
  - Metotlar (altyazıdan): `exists`, `isFile`, `getParentFile` (bulunduğu klasörü `File` olarak döndürür), `getCanonicalPath` (tam yol), `canRead`, `canWrite`, `createNewFile` (dosyayı diskte oluşturur), `mkdir` (klasör oluşturur), `mkdirs` (yoldaki bütün klasör hiyerarşisini oluşturur), `renameTo`, `delete`.
- G/Ç işlemleri: akışlar
  - Dosya sisteminde iki dış veri biçimi vardır: ikili (binary) dosyalar, metin düzenleyiciyle okunamayan ham baytlar içerir; metin dosyaları ASCII, UTF-8, UTF-16 gibi kodlamalarla yazılır. Java içinde `char` 16 bit, `byte` 8 bittir.
  - Derste bayt akışı tabanlı sınıflar işlendi: okumak için `InputStream`, yazmak için `OutputStream` sınıfları. Slayttaki çizim: kaynaktan programa ve programdan hedefe (sink) bitlerin bir akış (stream) boyunca aktığı gösterilir (ekrandan, 01:10:00).
  - Nesne okuma ve yazma için akışlar zincirlenir (ekrandan, 01:25:00): `FileInputStream` diskten bayt bayt okur; `ObjectInputStream` gelen baytları biriktirir (buffer) ve bir nesneyi oluşturacak kadar bayt gelince nesneyi programa verir.

    ```java
    ObjectInputStream reader = new ObjectInputStream(
                               new FileInputStream( fileName ) );
    Integer recordNumber = (Integer)reader.readObject();

    ObjectOutputStream writer = new ObjectOutputStream(
                               new FileOutputStream( filename) );
    writer.writeObject( recordNumber );
    ```

  - `readObject()` `java.lang.Object` döndürür; okunan nesnenin gerçek türüne dönüştürülmesi gerekir. Dosyayı yazan da okuyan da aynı programcı olduğu için hangi türün beklendiği bilinir.
- Serialization (ekrandan, 01:30:00)
  - Bütün nesnelerin baytlara çevrilip diske yazılmasına serialization denir. Serileştirilecek nesnenin sınıfı `java.io.Serializable` arayüzünü gerçeklemelidir. Bu arayüzün metodu yoktur.
  - Serileştirme için `ObjectOutputStream` ve `FileOutputStream` zincirlenir. Aynı akışa birden çok nesne gönderilebilir ve gönderilmelidir.
  - `Serializable` gerçeklenince `private static final long serialVersionUID` tanımlanmalıdır; tanımlanmazsa derleyici uyarı verir. Sınıfın zamanla farklı sürümleri olabileceği için yazılan nesnelerin hangi sınıf sürümüne ait olduğu bu alanla izlenir.
- Annotation'lar (ekrandan, 01:35:00)
  - `@` ile başlayan satırlar annotation'dır; "bilgi hakkında bilgi" içerir ve IDE'ye, derleyiciye ya da başka programlara bilgi verir. Metodun (ya da sınıfın) bir üst satırına yazılır.
  - `@SuppressWarnings("serial")`, `serialVersionUID` yazılmadığında çıkan uyarıyı bastırır. Slayttaki uyarı: uyarılar aslında dikkate alınmalıdır.
- `Arkadas` örneği: diziyle yazma ve okuma
  - `Arkadas` sınıfı `Serializable`'ı gerçekler; üç `String` alanı (ad, telefon, e-posta), kurucusu, getter'ları, telefon ve e-posta için setter'ları ve `toString`'i vardır (altyazıdan).
  - `ArkadasOlustur`: kullanıcıdan kaç arkadaş girileceği `Scanner` ile alınır, o boyutta bir `Arkadas` dizisi oluşturulur ve döngüde her arkadaş oluşturulup telefon ve e-postası set edilir.
  - Yazma bölümü (ekrandan, 01:40:00): önce `Integer` türündeki arkadaş sayısı, sonra her arkadaş `writeObject` ile yazılır; akış `close()` ile kapatılır. `IOException` yakalanır.

    ```java
    try {
        String dosyaAdi = "arkadaslar.dat";
        ObjectOutputStream yazici = new ObjectOutputStream(
                    new FileOutputStream( dosyaAdi ) );
        yazici.writeObject( arkadasSayisi );
        for( Arkadas arkadas : arkadaslar )
            yazici.writeObject( arkadas );
        yazici.close();
        System.out.println("Girilen bilgiler " + dosyaAdi +
                " adlı dosyaya başarıyla kaydedildi.");
    }
    catch( IOException e ) {
        System.out.println("Dosyaya kayıt işlemi sırasında"+
                " bir hata oluştu.");
        e.printStackTrace();
    }
    ```

  - Okuma (deserialization) `ArkadasGoster` ile yapılır (ekrandan, 01:45:00): önce `Integer kayitSayisi = (Integer)okuyucu.readObject();`, sonra `kayitSayisi` kez `Arkadas arkadas = (Arkadas) okuyucu.readObject();` ve yazdırma; sonunda `okuyucu.close();`.
  - Okumada iki istisna yakalanır (ekrandan, 01:55:00): `IOException` ("Dosya okuma işlemleri sırasında bir hata oluştu.") ve `ClassNotFoundException` ("Okunan kayıtları işlerken bir hata oluştu."). Yazmada yalnız `IOException` gerekir.
- Dosya sonunun anlaşılması (ekrandan, 01:50:00)
  - `ObjectInputStream`'de `hasNext` gibi bir metot yoktur. `int available()` vardır ama hatalı çalışır; `readObject()` dosya sonunda `null` döndürmez. İstisnayı oluşturup döngüyü catch bloğunda bitirmek mümkündür, ama istisna yönetimi program akışını değiştirmek için icat edilmemiştir.
  - İki çözüm: dosyanın başına nesne sayısını yazmak ya da bütün nesneleri tutan tek bir kap nesnesini (liste ya da map gibi bir veri yapısı) yazmak. Kaptaki nesneler de `Serializable` olmalıdır; A→B ilişkisi varsa A da B de `Serializable`'ı gerçeklemelidir.
  - Veri yapısı sürümünde `LinkedList<Arkadas>` oluşturulur, arkadaşlar `add` ile eklenir ve `writeObject` ile listenin tamamı yazılır. Okurken tek `readObject` ile liste alınır, `LinkedList`'e dönüştürülür ve for-each ile yazdırılır; sayı önceden yazılmaz.
- `Contact` örneği (Eclipse)
  - `Contact` sınıfı `Serializable`'ı gerçekler ve `serialVersionUID` tanımlar; ad, telefon ve e-posta alanları vardır. `CreateContacts` ve `ShowContacts` aynı akışı diziyle, ikinci sürüm bağlı listeyle uygular.
- İç sınıflar (inner classes)
  - Bir sınıfın nesnesine yalnız bir amaç için bir kez ihtiyaç duyulacaksa iç sınıf kullanılır. İç sınıf, dış sınıfın içinde tanımlanan sınıftır; metotları dış sınıfın alanlarına ve metotlarına erişebilir.
  - Örnek (ekrandan, 02:15:00): `Person` dış sınıfının içinde `@SuppressWarnings("unused")` ile işaretli `private class Employee` vardır. `Employee`'nin `toString()`'i dış sınıfın `name` alanını kullanır. `main` `Person` içindedir; `Employee[] staff = new Employee[3];` dizisi oluşturulur ve her eleman `kisi.new Employee( 10000 )` biçiminde, dış sınıfın bir nesnesi üzerinden oluşturulur.
  - `main` başka bir sınıfa taşınırsa iç sınıf `public` olmalı ve aynı pakette olsa bile `import` ile belirtilmelidir (`TestInnerClassDirectly`, ekrandan, 02:20:00).
  - İç sınıf `private` ise dışarıdan görünmez, `import` bile hata verir. Bu durumda dış sınıfa `public` bir metot (`enlist`) eklenir; bu metot içeride `Employee` nesnesini maaşla oluşturur (`TestInnerClassViaOuterClass`).
  - `@SuppressWarnings("unused")`: private iç sınıf kendi dış sınıfında kullanılmıyor görünürse derleyicinin vereceği "kullanılmıyor" uyarısını bastırır.
- Çoklu iş parçacığı (multithreading)
  - Bugünkü bilgisayar ve telefonlarda birden çok işlemci ve her işlemcide birden çok çekirdek vardır. Çalışan programa işletim sistemi süreç (process) der. Yeni süreç tek iş parçacıklıdır (single-threaded) ve tek çekirdekte çalışır; program içinde ek iş parçacıkları oluşturulursa her biri ayrı çekirdekte çalışabilir.
  - Durumlar: new (oluşturuluyor) → runnable (çalışmaya hazır, kuyrukta) → zamanlayıcı (scheduler) çekirdeğe verir → zaman dilimi bitince yeniden runnable kuyruğuna döner (round robin). `sleep`, `wait`, `join` ile blocked durumuna alınır; `notify`, `notifyAll` ile yeniden runnable kuyruğuna döner. İşi biten iş parçacığı dead olur ve kaynakları bırakılır.
  - İş parçacığı olacak sınıf `Runnable` arayüzünü gerçekler ve parametresiz, `void` döndüren `run()` metodunu yazmak zorundadır.
  - `SoccerFan` (ekrandan, 02:50:00): `public final static int STEPS = 10;`, `DELAY = 1000;`, `teamName` ve `shoutPhrase` alanları. `run()` içinde `Random` ile 10 kez tezahürat yazdırılır ve her adımdan sonra `Thread.sleep( generator.nextInt(DELAY) );` ile rastgele bir süre beklenir. `sleep` checked `InterruptedException` fırlatır ve yakalanmalıdır.
  - `Thread` ile çalıştırma: `new Thread( new SoccerFan(...) )` oluşturulur ve `start()` çağrılır; `start()` nesnenin `run()` metodunu ayrı bir iş parçacığında başlatır ve hemen döner. Dört `SoccerFan` ile ana program birlikte beş iş parçacığı olur.
- `java.util.concurrent`: `Executors` ve `ExecutorService`
  - `ExecutorService` metotları (ekrandan, 02:55:00): `shutdown()` yeni görev kabul etmez, havuzdaki görevlerin bitmesine izin verir; `shutdownNow()` hemen kapatır, bitmemiş görevleri liste olarak döndürür; `isShutdown()` havuz kapatılmışsa `true`; `isTerminated()` bütün görevler bittiyse `true` döndürür ve `main`'de iş parçacıklarını beklemek için kullanılabilir. `execute(Runnable)` metodu `Executor` arayüzünden gelir.
  - `Executors` havuzu oluşturur; sabit sayıda ya da gerektikçe iş parçacığı açılabilir. `MatchWithPool` (ekrandan, 03:00:00): `ExecutorService pool = Executors.newCachedThreadPool( );`, dört kez `pool.execute( new SoccerFan(...) );`, sonra `pool.shutdown( );`. `SoccerFan` değişmez.
- Yarış durumu (race condition) ve `synchronized`
  - İş parçacıkları ortak bir alanı aynı anda güncellerse yarış durumu oluşur. Slayttaki örnek (ekrandan, 03:05:00): bakiye 1000 iken iki istemci iş parçacığı aynı anda `withdraw` çağırır; ikisi de `curBal = 1000` okur, biri `1000 - 100 = 900`, öteki `1000 - 50 = 950` yazar ve sonuç 950 olur. Her iş parçacığının yerel değişken ve parametreleri kendine aittir, ama alanlar paylaşılır.
  - Çözüm: ortak alanı güncelleyen bütün metotlara (`withdraw`, `deposit`) dönüş türünden önce `synchronized` eklenir. Bir iş parçacığı metottayken öteki metodun başında bekler ve güncellenmiş bakiyeyi okur.
  - Banka simülasyonu: `Account` (bakiye `double`, getter, `withdraw`, `deposit`, `possibleDelay`) `Runnable` değildir; `AccountDepositer` ve `AccountWithdrawer` `Runnable`'dır ve `run()` içinde `account.deposit(amount)` ya da `withdraw` çağırır (ekrandan, 03:10:00). `main` 0 bakiyeli hesap açar, `newCachedThreadPool` ile 100 adet 1 TL yatıran ve 50 adet 1 TL çeken iş parçacığı çalıştırır, `shutdown` ve `isTerminated` döngüsünden sonra bakiyeyi yazar. `synchronized` yoksa sonuç her çalıştırmada farklıdır; varsa her zaman 50'dir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dosyaya yazılacak nesnenin sınıfı `Serializable` olmalı
  - Soruda yalnız nesnenin dosyaya yazılacağı söylenir; `Serializable`'ın gerçeklenmesi ayrıca belirtilmez ve bilinmesi beklenir. Bu sık yapılan ve puan kaybettiren bir hatadır. Veri yapısı (bağlı liste, `HashMap`, `ArrayList`) yazılıyorsa içindeki nesnelerin sınıfı da `Serializable` olmalıdır.
- Okumada iki ayrı istisna
  - Akıştan okumada hem `IOException` hem `ClassNotFoundException` catch bloklarında yakalanmalıdır; yazmada yalnız `IOException` yeterlidir. Bu bir soru tipidir.
- Akışlar mutlaka kapatılmalı
  - Okuma ya da yazma bitince akışa `close()` çağrılmalıdır.
- Generic tür tanımda ve oluşturmada aynı yazılmalı
  - `LinkedList<Arkadas>` oluşturulurken tür parametresi yazılıp değişken tanımında atlanması puan kaybettirir.
- `Runnable` ve `run()` imzası
  - İş parçacığı olacak sınıf `implements Runnable` yazmazsa ya da `run()` metodunu içermezse puan kaybedilir. `run()` parametre almaz ve değer döndürmez; imzası değiştirilmez.
- Bekletmek için `Thread.sleep`
  - Bir iş parçacığını bekletmek için döngüde CPU harcamak yerine `Thread.sleep` kullanılmalıdır.
- `Calendar`, `Date`, `Random` gibi sınıfların sık kullanılan metotları bilinmeli
  - `getInstance`, `add`, `set`, `getTime`, `before` gibi metotlar sınavda bilindiği varsayılarak kullanılabilir.
- Typecasting yalnız gerektiğinde
  - Kodu izlemeyi zorlaştırdığı için yalnız zorunluysa (özellikle dosyadan nesne okurken) kullanılmalıdır; tasarımla önlenebilir.
- Bilinmesi gereken `@SuppressWarnings` değerleri
  - Ders kapsamında görülen üç dört değer (`serial`, `unused`, `unchecked` gibi) yeterlidir.

## Kısa Tekrar Notları

- Typecasting: üst tür referansındaki nesneyi alt türe çevirmek, `(Food)item`. Öncesinde `item instanceof Food` ile kontrol edilir.
- Metotları üst türe (arayüz ya da soyut sınıf) taşımak typecasting ihtiyacını ortadan kaldırır.
- `Calendar.getInstance()`, `add(Calendar.DAY_OF_MONTH, 1)`, `set(Calendar.YEAR, 2010)`, `getTime()`; ay 0'dan başlar. `new Date()` bugünü taşır; `d1.before(d2)`.
- G/Ç istisnaları checked'dır: `IOException`, `EOFException`, `FileNotFoundException`. `SecurityException` bir `RuntimeException`'dır.
- `java.io.File`: nesne oluşturmak dosya oluşturmak değildir; `createNewFile`, `mkdir`, `mkdirs`, `renameTo`, `delete`.
- Nesne yazma: `new ObjectOutputStream(new FileOutputStream(ad))`, `writeObject`. Nesne okuma: `new ObjectInputStream(new FileInputStream(ad))`, `readObject` ve tür dönüşümü.
- Serileştirilecek sınıf: `implements Serializable` ve `private static final long serialVersionUID`.
- Dosya sonu için `hasNext` yok: önce sayıyı yaz ya da bütün veri yapısını tek nesne olarak yaz.
- Dış akışı kapatmak zincirdeki iç akışı da kapatır.
- İç sınıf nesnesi dış sınıf nesnesi üzerinden oluşturulur: `kisi.new Employee(10000)`. Private iç sınıfa dışarıdan ancak dış sınıfın public metoduyla ulaşılır.
- `Runnable` + `run()`; `new Thread(r).start()` ya da `Executors.newCachedThreadPool()` + `execute(r)` + `shutdown()`.
- `isTerminated()` bütün görevler bitince `true` olur.
- Ortak alanı güncelleyen metotlara `synchronized` eklenir; yoksa yarış durumu oluşur.

## Detaylı Açıklamalar

- Typecasting örneğinde `MarketShelf`, `Item` türünde nesneler tutan bir `LinkedList` alanına sahiptir. `Item` bir arayüzdür ve `Food` ile `Electronics` onu gerçekler; bu yüzden listede iki türden nesne bulunabilir. Son kullanma tarihi kavramı yalnız gıdalar için anlamlı olduğundan `isExpired()` yalnız `Food`'da tanımlıdır. `printExpiredItems` her elemanın gerçekten `Food` olup olmadığını `instanceof` ile sınar, öyleyse `(Food)item` ile `Food` referansına çevirip `isExpired()`'ı çağırır. Hiçbir ürünün süresi geçmemişse döngü sonunda `hasExpiredItem` hâlâ `false`'tur ve "All items are fresh!" yazılır. Aynı sorun tasarımla da çözülebilir: `getExpireDate` ve `isExpired` `Item` arayüzüne taşınırsa `Electronics` de onları gerçeklemek zorunda kalır ve listeden alınan her elemana dönüşüm yapmadan `isExpired()` çağrılabilir.
- Dosya işlemlerinde iki kategori vardır. `java.io.File` dosya sistemindeki dosya ve klasörleri yönetir: `File` nesnesi yalnız bir yol temsil eder; diskte dosya oluşturmak için `createNewFile`, klasör için `mkdir`, yoldaki bütün klasörler için `mkdirs` çağrılır. İkinci kategori okuma ve yazmadır. Derste ikili dosyalara bayt akışlarıyla nesne yazma ve okuma işlendi; metin dosyaları için slayt Core Java 8. baskı 2. cildini ya da başka bir kitabı önerir (ekrandan, 01:55:00).
- Nesne yazmada `FileOutputStream` diske bayt yazar; `ObjectOutputStream` nesneyi baytlara çevirir. İkisi zincirlenir: `FileOutputStream` nesnesi `ObjectOutputStream` kurucusuna verilir. Okumada tersi olur: `FileInputStream` diskten bayt bayt okur, `ObjectInputStream` bir nesneyi oluşturacak kadar bayt biriktirip nesneyi verir. `readObject` her zaman `Object` döndürür; bu yüzden typecasting'in bugün en çok gerektiği yer deserialization'dır.
- `ObjectInputStream`'de dosya sonunu soran bir metot olmadığı için okuyan program kaç nesne okuyacağını bilmelidir. `Arkadas` örneğinin dizi sürümünde dosyanın ilk nesnesi bir `Integer` sayıdır; okuyucu önce onu okuyup döngü sınırı olarak kullanır. Veri yapısı sürümünde bütün `LinkedList` tek nesne olarak yazılır ve tek `readObject` ile geri alınır; JVM listeyi ve içindeki bütün nesneleri birlikte yazar. Ajan iki sürümü de küçük bir örnekle `java` ile çalıştırdı; nesneler yazıldığı sırayla geri okundu.
- Bir öğrenci, zincirde `FileInputStream`'in ayrı bir değişkeni olmadığı için nasıl kapatılacağını sordu. Hoca, kapsayıcı `ObjectInputStream` kapatıldığında kendi gerçeklemesi içinde bağlı `FileInputStream`'i de kapattığını, aynısının `ObjectOutputStream` ve `FileOutputStream` için de geçerli olduğunu anlattı.
- İç sınıf, dış sınıfın içinde tanımlanır ve dış sınıfın alanlarını kullanabilir; `Employee.toString()` dış sınıfın `name` alanını yazdırır. İç sınıfın nesnesi bir dış sınıf nesnesine bağlıdır; bu yüzden `kisi.new Employee(10000)` biçiminde oluşturulur. Ajan slayttaki `Person`/`Employee` örneğini `java` ile çalıştırdı; çıktı `Person-1 10000`, `Person-2 7500`, `Person-3 6000` oldu. Bir öğrencinin, bunun `Person`'ı parçalara bölmek gibi olup olmadığı sorusuna hoca, bölmek isteniyorsa kalıtım kullanılmasını (`Person`'dan `Employee`, ondan bir yönetici sınıfı türetmek gibi) önerdi; iç sınıf yalnız bir kez ve tek amaçla nesnesi gereken sınıflar içindir ve örnek yalnız iç sınıf kullanımını göstermek için böyle kurulmuştur.
- Çoklu iş parçacığında `start()` çağrısı `run()` bitene kadar beklemez; iş parçacığını başlatır ve ana program bir sonraki satırla devam eder. Bir öğrencinin bu konudaki sorusuna hoca, `start`'ın iş parçacığına "sen başla" deyip yol verdiğini, iş parçacığının bundan sonra bağımsız çalıştığını söyledi. `Executors` ile her iş parçacığı için ayrı `Thread` nesnesi yazılmaz; havuz bunu üstlenir ve takip için ek metotlar sağlar.
- Yarış durumunda iki iş parçacığı aynı bakiyeyi okur, kendi kopyalarında hesap yapar ve birbirinin güncellemesinden habersiz yazar; son yazan kazanır. `synchronized` metoda aynı anda yalnız bir iş parçacığının girmesini sağlar. Ajan banka simülasyonunu kendi yazdığı küçük bir `Account` sınıfıyla `java` ile çalıştırdı (slayttaki `Account` kodu kareye girmediği için gövdeler ajan tarafından yazıldı): `synchronized` olmadan 100 yatırma ve 50 çekmeden sonra bakiye 50 yerine 4 çıktı; `synchronized` ile 50 çıktı.
- Ders sonrası not: hoca `readObject` ile okunan baytlar beklenen sınıfa dönüştürülemezse `ClassNotFoundException` oluştuğunu söyledi. Doğrusu: `ClassNotFoundException`, `readObject` sırasında dosyadaki nesnenin sınıfı JVM'de bulunamazsa fırlatılır; okunan nesne başka türdeyse dönüşümde unchecked `ClassCastException` oluşur.
- Ders sonrası not: hoca `@SuppressWarnings("unchecked")`'ın istisnalar için kullanıldığını söyledi. Doğrusu: `unchecked`, denetlenmemiş generic dönüşüm uyarılarını bastırır; örneğin `(LinkedList<Arkadas>) okuyucu.readObject()` dönüşümünde bu uyarı büyük olasılıkla çıkar.
- Ders sonrası not: hoca `isShutdown()` `true` dönerse havuzdaki iş parçacıklarının çalışmaya devam ettiğini söyledi. Slayta göre `isShutdown()` havuz kapatıldıysa `true` döner; görevlerin bitip bitmediğini `isTerminated()` söyler. Ayrıca `shutdown()` çağıran iş parçacığını bekletmez; bu yüzden örnekte `isTerminated()` döngüsüyle beklenir.
- Ders sonrası not: hoca `wait`, `notify` ve `notifyAll`'u `Thread` sınıfının metotları olarak andı. Bu üç metot `java.lang.Object` sınıfında tanımlıdır; `sleep` ve `join` ise `Thread`'dedir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
