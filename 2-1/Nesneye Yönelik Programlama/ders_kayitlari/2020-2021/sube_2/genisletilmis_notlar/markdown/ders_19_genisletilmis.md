# Ders 19 Genişletilmiş Notu: Tip Dönüşümü (Typecasting), Dosya İşlemleri ve Serileştirme, İç Sınıflar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tip dönüşümü (typecasting) kavramı
- 2. MarketShelf örneği: instanceof ve dönüşüm
- 3. Calendar ve Date sınıfları
- 4. Food sınıfı ve örneğin çalıştırılması
- 5. Typecasting eleştirisi ve typecasting'siz tasarım
- 6. Dosyalarla çalışma: ilgili istisnalar ve iki işlem grubu
- 7. Dosya yönetimi: java.io.File sınıfı
- 8. Akışlarla (stream) G/Ç işlemleri
- 9. Serileştirme (serialization)
- 10. serialVersionUID ve sürümleme
- 11. İletişim listesi örneği: nesneleri tek tek yazmak
- 12. Deserileştirme: nesneleri geri okumak
- 13. Dosya sonu sorunu ve veri yapısını serileştirmek
- 14. Eclipse'te çalıştırma, autoboxing ve çoklu catch
- 15. Metin dosyaları
- 16. İç sınıflar (inner classes)
- 17. İç sınıf örnekleri: private, public, dış sınıf üzerinden erişim, Person.this
- Örnek Sorular
- Dersin Toparlaması

## 1. Tip dönüşümü (typecasting) kavramı

"Type" tür ya da sınıf, "cast" dönüşüm demektir. Kalıtım konusundan hatırlanacağı gibi, alt sınıftan bir nesne üst sınıfın beklendiği her bağlamda kullanılabilir; ama bu durumda yalnız üst sınıfın arayüzüyle (metotlarıyla) kullanılır. Bu dönüşüm otomatiktir ve tür açısından güvenlidir (type safe): daha özelleşmiş bir şey daha genel bir şeye veri kaybı olmadan dönüştürülebilir.

Ters yöndeki dönüşüm ise risklidir. Bu yüzden elle, ek bir kodla yazılması gerekir. Dahası, dönüşümün yapılıp yapılamayacağı önce kontrol edilmeli, yapılabiliyorsa öyle dönüştürülmelidir. Java terminolojisinde bu işleme typecasting denir.

Ne zaman gerekir? Örneğin bir nesne bir arayüzü gerçekliyor ve o nesnenin işaretçisi arayüz türünden bir işaretçiye atanmış olsun. Daha sonra bu arayüz türündeki işaretçiden nesnenin kendi türüne geri dönmek mümkündür. Aynı şey üst sınıftan alt sınıfa doğru dönüşüm için de geçerlidir. Her iki durumda kural aynıdır: önce kontrol, sonra dönüştürme.

> **Hocanın vurgusu:** Typecasting "gerekli bir kötülüktür" (necessary evil). Tercih etmediğimiz bir şeydir ama bilmemiz gerekir.

## 2. MarketShelf örneği: instanceof ve dönüşüm

### 2.1 Tasarım

Bir markette satılan ürünler `Item` adlı bir arayüzle temsil edilir. Market gıda satar; gıdaların son kullanma tarihi (`expireDate`) vardır. Bu tarih constructor'da alınır, bir getter metoduyla okunur, `isExpired()` metodu da süre geçmiş mi diye bakar. Market elektronik eşya da satar; elektronik eşyanın süresi dolmaz ama o da `Item` arayüzünü gerçekler (ekrandan, 00:15:00):

```text
MarketShelf                         <<interface>> Item
- items : LinkedList<Item>   1 ---> *   (son kullanma işlemleri hariç bazı metotlar)
+ addItem( Item ) : boolean                 ^            ^
+ doesExist( Item ) : boolean               |            |
+ printExpiredItems( )                    Food        Electronics  ("electronics do not expire")
                                - expireDate : Date
                                + Food( expireDate : Date )
                                + getExpireDate( ) : Date
                                + isExpired( ) : boolean
```

Hoca tasarımı anlatırken önce arayüzde süreyle ilgili metotların olduğunu söyledi, sonra düzeltti: UML notunda "excluding" yazıyor, yani `Item` arayüzünde son kullanma tarihiyle ilgili hiçbir metot yoktur. Bu metotlar arayüzde olsaydı `Electronics` onları gerçeklemek zorunda kalırdı; ama bunun bir sakıncası yoktu, `isExpired()` doğrudan `return false` yazabilirdi. Böyle bir tasarımda typecasting'e hiç gerek kalmazdı ve hoca da aslında o tasarımı tercih eder. Konuyu anlatabilmek için bilerek typecasting gerektiren tasarım seçilmiştir.

`MarketShelf` sınıfının geri kalanı önceki derslerdeki bire-çok sahiplik ilişkisinin aynısıdır: generic bir liste, belli bir öğenin listede olup olmadığına bakan `doesExist`, öğe eklemeden önce yinelenen öğe kontrolü yapan `addItem` (ekrandan, 00:35:00).

### 2.2 printExpiredItems metodu

Rafta hem `Food` hem `Electronics` nesneleri olabilir. Her öğe arayüz türünden bir işaretçiyle tutulur; ama o işaretçiye atanmış nesne bir `Food` mu, `Electronics` mı, başka bir şey mi? `Food` ise süresi geçmiş mi diye bakılır (ekrandan, 00:20:00):

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

Tür kontrolünde kullanılan operatörün adı `instanceof`'tur ve tamamı küçük harfle yazılır. Hoca, İngilizce'de edatların başlıklarda bile küçük harfle yazıldığını, bu yüzden "Of"un büyük yazılmamasının mantıklı olduğunu söyledi. Operatörün solunda bir işaretçi, sağında bir tür adı bulunur. Bu tür bir sınıf, bir arayüz, hatta bir enum olabilir (enum da ilkel olmayan bir türdür). Soldaki işaretçinin gösterdiği nesne sağdaki türdense operatör `true` döndürür.

Kontrol olumluysa öğe `Food`'a çevrilebilir. Dönüşüm biraz fazla parantezlidir: önce tür adı parantez içine yazılır (`(Food)`), sonra bu ikisi birlikte yeniden paranteze alınır (`((Food)item)`). Ancak o zaman nokta konup dönüştürülen türün bütün metotlarına erişilebilir.

Bayrak değişkeni (`hasExpiredItem`), hiç süresi geçmiş öğe yoksa başlığın altının boş kalmaması ve "All items are fresh!" mesajının yazılabilmesi için kullanılmıştır.

## 3. Calendar ve Date sınıfları

### 3.1 Calendar ve factory metot

`java.util` paketindeki `Calendar` sınıfı çok yeteneklidir: geçmişteki ve bugünkü takvim sistemlerinin neredeyse hepsini destekler (Maya, Hicri, İran-Pers, Miladi vb.). Bu kadar geniş destek beraberinde biraz karmaşıklık getirir ama kullanımı zor değildir.

`Calendar`'ın statik bir `getInstance()` metodu vardır. Kendi türünden bir nesne üreten bu tür metotlara factory (fabrika) metot denir. Bir nesneyi üretme sorumluluğu doğrudan constructor çağrılarak değil, başka bir nesnenin normal bir metodu ya da bir sınıfın statik bir metodu üzerinden yerine getiriliyorsa o metoda factory metot denir.

Elde edilen takvim nesnesinin alanları (gün, ay, yıl) ayarlanabilir ya da herhangi bir bileşenine ekleme/çıkarma yapılabilir. `getInstance()` ile alınan nesne metodun çalıştırıldığı anı (gün ve saat) gösterir.

### 3.2 main metodundaki tarih işlemleri

Örneğin `main` metodu (ekrandan, 00:25:00):

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

`cal.add(Calendar.DAY_OF_MONTH, 1)` ayın gününe 1 ekler. Ders 20 Mayıs'ta yapıldığından takvim 21 Mayıs'ı, yani tam 24 saat sonrasını gösterir. Ders 31 Mayıs'ta yapılsaydı "32 Mayıs" gibi saçma bir tarih oluşmaz, takvim otomatik olarak 1 Haziran'a geçerdi.

Takvim ayarlandıktan sonra `getTime()` ile bir `Date` nesnesi alınır. `Date` belirli bir gün ve saati içeren, üzerinde başka işlemler de yapılabilen bir türdür. Java'da tarihlerle çalışacaksak hem `Calendar` hem `Date` kullanımını bilmemiz gerekir.

Sonra geçmiş bir tarih ayarlanır: yıl 2010, ay Ocak, gün 13. Burada bir tuzak vardır: `Calendar` ayları 0'dan saymaya başlar, ama günleri 1'den sayar. Hoca bunun nedenini bilmediğini, ama bilinmesi gerektiğini söyledi. 13 Ocak 2010 için `YEAR 2010`, `MONTH 0`, `DATE 13` verilmelidir.

> **Hocanın vurgusu:** Ayları saymaya sıfırdan, günleri saymaya birden başlıyor; bunu bilmemiz gerekiyor.

İlk `Food` geçmiş tarihle, ikincisi gelecekteki tarihle oluşturulup listeye eklenir; son olarak bir `Electronics` eklenir. Gerçekte bu ürünlerin barkodu, fiyatı vb. de olurdu ama önceki haftalarda bu konulara yeterince girildiği için burada atlanmıştır.

> **Ders sonrası not:** Slayttaki `main`, `shelf.checkForExpiration()` çağırıyor; oysa sınıftaki metodun adı `printExpiredItems()`'tır (UML'de ve Eclipse'teki kodda da böyle). Eclipse'teki çalışan kodda `printExpiredItems()` ve ek olarak `printAllItems()` çağrılmıştır (ekrandan, 00:35:00).

### 3.3 Neden constructor yerine factory metot?

Bir öğrenci, `Calendar`'da constructor yerine factory metodun neden tercih edildiğini sordu. Hoca kesin nedenini bilmediğini, ama eğitimli tahminini söyleyebileceğini belirtti. `Date` eski bir sınıftır, Java 1.0'dan beri vardır ve bir gün sonra, bir ay sonra gibi işlemleri de yapabiliyordu. Ancak bu sınıfı kodlamak için kullanılan kütüphanelerde sorunlar vardı; bu yüzden Java belgelerinde `Date`'in, bugün `Calendar` ile yaptığımız işlemlere benzeyen metotlarının hepsi deprecated (artık desteklenmiyor) olarak görünür. Bunun yerine `Calendar` getirildi: takvim belli bir anı gösterecek şekilde ayarlanır, sonra ondan bir `Date` alınır.

Arka plandaki yapı karmaşıklaştıkça factory metotların kullanılması genel olarak tercih edilir. Hoca, farklı takvim türleri için arka planda çeşitli sınıfların kodlanmış olabileceğini düşündüğünü söyledi. Programcı bu sınıfların adlarını ve kendine özgü metotlarını bilmek zorunda kalmadan, kara kutu yaklaşımıyla "fabrikadan" bir takvim ister ve `add`, `set`, `get` gibi birkaç metotla kullanır. Bu, programcıyı arka plandaki karmaşadan soyutlar.

**Soru:** Bunun için bir arayüz verilemez miydi? **Cevap:** Verilebilirdi, ama iş karmaşıklaştıkça factory'ler üzerinden çalışmak genelde tercih edilir. Tasarım kalıpları (design patterns) çalışıldığında bu görülecektir.

## 4. Food sınıfı ve örneğin çalıştırılması

### 4.1 Food sınıfı

`Date` sınıfı `java.util` paketinde olduğu için import edilir (ekrandan, 00:30:00):

```java
package nyp11;
import java.util.Date;
public class Food implements Item {
    private Date expireDate;

    public Food(Date expireDate) {
        this.expireDate = expireDate;
    }
    public Date getExpireDate() { return expireDate; }
    public boolean isExpired( ) {
        Date today = new Date();
        if( expireDate.before(today) )
            return true;
        else return false;
    }
    public String toString() {
        return "A food expiring at " + expireDate;
    }
}
```

İki tarih `Date`'in `before` ve `after` metotlarıyla karşılaştırılır; `String`'in `compareTo`'su gibi düşünülebilir. Yalnız şu anki an isteniyorsa `Calendar`'a gerek yoktur: `Date`'in varsayılan constructor'ı hâlâ kullanılır ve şu anki zamanı verir. Birkaç gün, saat ya da ay ileri/geri gitmek gerektiğinde ise `Calendar` gerekir.

`expireDate.before(today)` doğruysa süre geçmiştir. Aynı koşul `today.after(expireDate)` olarak da yazılabilirdi.

### 4.2 Çalıştırma

Eclipse'te `Item` arayüzü şu an boştur; barkod ya da fiyat gibi önemli alanlar olsaydı onların getter metotları buraya konurdu. `Electronics` sınıfı da yalnız kendini "An electronic item" diye tanıtır.

Program çalıştırıldığında çıktı şöyledir (ekrandan, 00:35:00):

```text
Expired item(s):
A food expiring at Wed Jan 13 09:34:26 TRT 2010
All item(s):
A food expiring at Wed Jan 13 09:34:26 TRT 2010
A food expiring at Fri May 21 09:34:26 TRT 2021
An electronic item
```

Saat kısmı programın çalıştırıldığı andan gelir, çünkü `Calendar` nesnesi o anı gösteriyordu ve yalnız yıl, ay ve gün değiştirildi. "TRT" burada Türkiye saat dilimi (Turkey Time) anlamındadır.

Kod Java 25 ile (`java MarketShelf.java`) denenmiş, aynı mantıkta çıktı vermiştir (2010 tarihli gıda süresi geçmiş olarak listelenir).

### 4.3 Eclipse'teki ilginç durum

Hoca Eclipse'te `instanceof` kontrolünden sonra, dönüşüm yazmadan `item.` dediğinde kod tamamlama listesinde `isExpired` metodunun çıktığını gösterdi. Kontrolün dışında aynı şeyi denediğinde yalnız `Object` sınıfının metotları (`equals`, `hashCode`, `toString` vb.) listelendi (ekrandan, 00:35:00). Hoca bunun Eclipse'in mi yoksa yeni JDK sürümünün mü bir özelliği olduğundan emin olmadığını söyledi. Geriye uyumluluk (backwards compatibility) istiyorsak dönüşümü mutlaka uzun biçimde yazmamızı, hızlı bir prototipte kısaltmanın kullanılabileceğini belirtti.

> **Ders sonrası not:** Java'da `instanceof` kontrolünden sonra da `item.isExpired()` doğrudan derlenmez: Java 25 ile denendiğinde "cannot find symbol" hatası alındı. Eclipse'te görülen öneri büyük olasılıkla Eclipse'in seçildiğinde cast'i kendisi ekleyen kod tamamlama özelliğidir. Java 16'dan beri bunun dil düzeyindeki karşılığı desen eşlemedir: `if (item instanceof Food f && f.isExpired()) ...`.

Hoca ayrıca Java ile çalışacaksak, yalnız Eclipse içinden değil jar dosyalarını Eclipse olmadan da çalıştırabilmek için JDK kurmanın her zaman yararlı olduğunu söyledi.

## 5. Typecasting eleştirisi ve typecasting'siz tasarım

Slaytta typecasting'in eleştirisi şöyle özetlenir (ekrandan, 00:40:00):

- Typecasting "gerekli bir kötülüktür", az kullanılmalıdır.
- Java'da generic sınıflar yokken typecasting sık sık yapılmak zorundaydı.
- Bugün yalnız deserialization yaparken typecasting'e ihtiyaç vardır.
- Typecasting olmadan da her zaman tasarım yapılabilir.

Kendinizi sık sık typecasting yapmak zorunda görüyorsanız tasarımınızda belki bir hata değil ama bir eksiklik vardır; daha iyisini yapabilirsiniz. Generic yapılar gelmeden önce, örneğin bir `LinkedList` yalnız `Object` türünde nesne tutabiliyordu. Bu yüzden veri yapısından alınan her şey kullanılmadan önce önce kontrol edilip sonra dönüştürülmek zorundaydı; bu bir sürü angaryaydı. Bugün typecasting'in mecbur olduğu tek yer deserialization'dır: nesneleri baytlara çevirip bir disk dosyasına ya da bir IP bağlantısı üzerinden göndermekle ilgili işlemin geri okuma tarafı.

Typecasting'siz tasarımda `getExpireDate()` ve `isExpired()` metotları `Item` arayüzüne konur (slayttaki nota göre `Item` soyut bir sınıf da olabilir):

- `Food` bunları dolu gövdelerle gerçekler.
- `Electronics`, `isExpired()` için tek satırlık `return false` yazar; bunun bir sakıncası yoktur.
- `Electronics`'in `getExpireDate()`'i ne döndürmeli? Hiç dolmayacağı için örneğin her zaman bir yıl sonrasını döndürebilir ya da `null` döndürebilir. `null` döndürülürse tüm öğeler listelenirken bu tarih kullanılmaya çalışılırsa `NullPointerException` alınır; ama `Electronics`'in `toString()`'i tarihi kullanmayacak şekilde düzgün yazılırsa sorun olmaz.
- Barkod, fiyat gibi ortak alanlar söz konusu olsaydı arayüz yerine soyut bir üst sınıf yapılır, bu alanlar ve getter/setter'ları oraya taşınırdı. En iyi tasarım budur.

Bu tasarımın tek kusuru şudur: bir `setExpireDate` metodu da gerekirse `Electronics`'te boş gövdeli bir metot olur, ki boş gövdeli metodun pek anlamı yoktur. Hoca iki seçeneği karşılaştırdı: typecasting'li ama `Electronics`'in daha anlamlı olduğu tasarım mı, typecasting'siz ama `Electronics`'te küçük bir pürüz olan tasarım mı? Hoca ikinci tasarımı tercih etmeye devam ettiğini söyledi.

> **Hocanın vurgusu:** Typecasting'i mümkün olduğu kadar az kullanmalıyız. Az önceki tasarım yalnızca typecasting'i öğretmek için kullanıldı.

## 6. Dosyalarla çalışma: ilgili istisnalar ve iki işlem grubu

### 6.1 İlgili istisnalar

Dosyalarla çalışırken pek çok şey ters gidebilir. Bu yüzden dikkat edilmesi gereken dört istisna vardır (ekrandan, 00:55:00):

- `java.io.IOException`: genel olarak G/Ç istisnalarını temsil eder; bütün G/Ç istisnalarının üst sınıfıdır.
- `java.io.EOFException extends IOException`: dosyanın ya da akışın sonuna beklenmedik biçimde gelindiğini gösterir.
- `java.io.FileNotFoundException extends IOException`: istenen dosyanın verilen yolda bulunamadığını gösterir.
- `java.lang.SecurityException extends java.lang.RuntimeException`: işlemin güvenlik kısıtları nedeniyle yapılamadığını gösterir. `RuntimeException`'dan türediği için unchecked'tir; kodu çalıştıran kullanıcının dosya üzerinde yetkisi yoksa ortaya çıkar.

İlk üçü checked istisnadır, mutlaka try-catch ile ele alınmalıdır. `EOFException` ve `FileNotFoundException`, `IOException`'ın alt sınıfları olduğundan yalnız `IOException`'ı yakalamak hepsini ele almaya yeter. Ama hangi istisnanın oluştuğunu kullanıcıya bildirip sorunu çözdürmek istiyorsanız alt sınıfları ayrıca yakalamanız gerekir: örneğin dosyanın beklenmedik biçimde sonuna gelindiğini bildirmek için önce `EOFException`, sonra geri kalanlar için `IOException` yakalanır. Bu yüzden ele alma sırası önemlidir. Bunlar checked olduğu için IDE de eksik ele almayı zaten bildirir.

### 6.2 Dosya işlemlerinin iki grubu

Java'da dosya işlemleri iki ana gruba ayrılır:

- Dosya yönetimi (file management): dosya ya da klasör oluşturma, adlandırma, silme (klasörse içindekileri silme), ad değiştirme gibi işlemler.
- G/Ç işlemleri: bir dosyaya bayt yazmak ya da ondan bayt okumak.

Bu iki grup Java'da farklı sınıflar üzerinden, biraz farklı yöntemlerle yapılır. G/Ç işlemleri yalnız disk ile bellek arasında düşünülmemelidir: TCP soketleri, web sayfaları, konsol gibi farklı kaynaklarla da yapılır. Bu nedenle G/Ç işlemleri dosya işlemlerinden ayrılmış ve bütün bu farklı kaynaklar için aynı biçimde kodlanmıştır.

C'de akış (stream) yapısı şeffaf olarak kullanılıyordu. Java'da ise akış yapısının çok daha ayrıntılı farkında olunur: farklı yeteneklere sahip girdi ve çıktı akışları vardır ve bunlar birbirine zincirlenerek kullanılır. Bu yaklaşım nesneye yönelimle uyumludur, çünkü nesneye yönelim mümkün olduğunca odaklanmış işler yapan ayrı sınıflar ister. Yan etkisi bir miktar karmaşıklıktır; ama hangi iş için hangi akışın kullanılacağını ve bunların nasıl zincirleneceğini bilmek yeterlidir.

## 7. Dosya yönetimi: java.io.File sınıfı

### 7.1 File nesnesinin iki özelliği

Dosya yönetimi `java.io.File` sınıfıyla yapılır. Dikkat edilecek iki nokta vardır (ekrandan, 01:00:00):

- Aynı sınıf hem dosya hem klasör için kullanılır. Bir `File` nesnesi bir dosyayı da bir klasörü de gösterebilir. Belli bir anda hangisini gösterdiği `isFile()` metoduyla öğrenilir: dosyaysa `true`, klasörse `false` döner.
- Bellekte bir `File` nesnesi oluşturmak, fiziksel ortamda böyle bir dosya ya da klasör olduğu anlamına gelmez. Önce nesne oluşturulur, sonra simgelediği dosya ya da klasörün gerçekten var olup olmadığı kontrol edilir, yoksa oluşturulabilir.

### 7.2 Constructor'lar, tam yol ve göreli yol

En temel constructor `File(String fileName)`'dir. `fileName` hem yolu hem dosya/klasör adını içerir; tam yol ya da göreli yol olabilir. Hoca kendi bilgisayarındaki ders notu dosyasının tam yolunu kopyalayıp bir `File` nesnesine vererek gösterdi.

Aynı klasörde olmayan bir dosya adıyla (ör. `ek.txt`) da nesne oluşturulabilir. Hoca bu nesne için `exists()`'in `false` döneceğini söyledi.

> **Ders sonrası not:** Hoca böyle bir nesne için `isFile()`'ın `true` döneceğini söyledi. Doğrusu, dosya diskte yoksa `isFile()` da `false` döner; `isFile()` "var olan ve normal dosya olan" yollar için `true` verir. Java 25 ile denendi: var olmayan `ek.txt` için `isFile()` ve `exists()` ikisi de `false`, `createNewFile()` sonrasında ikisi de `true` döndü.

Yol ayırıcı konusu (ekrandan, 01:00:00):

- Windows `\` kullanır; bu karakter Java string'inde kaçış karakteri olduğu için `\\` diye yazılmalıdır. Unix `/` kullanır.
- Windows ortamında Java kodunda `/` yazmak da çalışır.
- Taşınabilirlik için çalışılan platformun ayırıcısı `public static String File.separator` ve `public static char File.separatorChar` ile öğrenilebilir.
- Tam yol kullanmak taşınabilirliği bozar. Göreli yol da dikkat ister: IDE'ler kaynak ve class dosyalarını farklı klasörlerde tutabilir.

Göreli yol örneği: `new File("not.txt")` dosyayı o anki çalışma klasöründe arar ya da oluşturur. Eclipse'te bu, projenin bulunduğu klasördür (hoca projenin özelliklerinden konumu gösterdi; önceki yıllardan kalan `.dat` dosyası da oradaydı). Bir üst klasördeki `tmp` klasörünün altındaki bir dosya için `new File("../tmp/not.txt")` yazılır; `..` bir üst klasör demektir, komut satırıyla çalışanlar bunu bilir. NetBeans'in ve Eclipse'in göreli yolu farklı yerleri gösterebileceği için buna dikkat edilmelidir.

İkinci constructor ailesi `File(String path, String name)` ve `File(File path, String name)`'dir. Verilen `path` klasörü içinde verilen adla bir dosya/klasörü temsil eder. Örneğin bir çalışma klasörü string ya da `File` olarak tutulur, sonra `new File(calismaDizini, "not.txt")` gibi kullanılır; hangisi işinize geliyorsa.

### 7.3 Diğer metotlar

`java.io.File`'ın bazı metotları (ekrandan, 01:15:00):

- `boolean exists()`: dosya ya da klasör fiziksel ortamda var mı.
- `boolean isFile()`: bu nesne bir dosyayı temsil ediyorsa `true`, klasörü temsil ediyorsa `false`.
- `File getParentFile()`: dosya/klasörün bulunduğu klasörü `File` olarak döndürür (hocanın örneğinde ders notu dosyasının bulunduğu klasör).
- `String getCanonicalPath() throws IOException`: dosya adı dahil tam yolu döndürür. `IOException` fırlatabildiği için try-catch içinde çağrılmalıdır.
- `boolean canRead()`, `boolean canWrite()`: bu uygulama dosyadan okuyabilir/dosyaya yazabilir mi. Erişim hakkı yoksa ya da dosya yoksa `false` döner; önce `exists()` ile bakılabilir.
- `boolean createNewFile()`: dosyayı gerçekten oluşturur; yalnız dosyalar için.
- `boolean mkdir()`: klasörü gerçekten oluşturur; eksik üst klasörleri oluşturmaz.
- `boolean mkdirs()`: klasörü gerekli bütün üst klasörlerle birlikte oluşturur.
- `boolean renameTo(File newName)`: adını değiştirir.
- `boolean delete()`: siler.

Boolean dönen metotlar işlem başarılıysa `true` döndürür. Bunların hepsini ezberlemeye gerek yoktur; gerektiğinde API belgelerine bakılır.

## 8. Akışlarla (stream) G/Ç işlemleri

Java'da her türlü G/Ç kaynağı bir akış olarak ele alınır: dosyalar, bellek, komut satırı, ağ vb. (ekrandan, 01:20:00). Komut satırı da aslında bir akıştır: `Scanner` nesnesi oluşturulurken parametre olarak `System.in` verilir; `System.in` ve `System.out` akış olarak ele alınmıştır. Java'nın ilk sürümlerinde konsoldan bir şey okuyabilmek için bu derste görülecek akış işlemlerini yapmak gerekiyordu; programlamaya yeni başlayanların buna doğrudan dalması garip oluyordu. `Scanner` sınıfıyla bu sorun ortadan kalktı.

İkili ve metin biçimi (sistem programlama derslerinden de bilinir):

- İkili (binary) G/Ç hızlı ve verimlidir ama insanlar tarafından kolay okunamaz.
- Metin G/Ç bunun tersidir: insan gözüyle okunur ama daha yavaştır.

Sıralı ve rastgele erişim:

- Sıralı erişim: bir kayda ulaşmak için dosyanın başından itibaren okunur.
- Rastgele erişim: belli bir kayda doğrudan ulaşılır (ör. dosya başından belli bir ofset verip oradan okumak).
- Disk dosyaları rastgele erişilebilir, ama ağdan gelen veri akışları erişilemez. Bu derste sıralı erişim kullanılacaktır.

Java farklı çalışma biçimleri için akışları birbirine zincirler (chaining); pratikte hemen her işte birbirini tamamlayan akışlar zincirlenir. Java ile metin dosyaları, başka biçimlerde dosyalar, hatta zip dosyaları okunup yazılabilir; yalnız hangi akışların kullanılacağını bilmek yeterlidir. Bu derste farklı olarak bütün nesnelerin diske yazılması ve diskten okunması öğretilecektir; Java terminolojisinde buna serileştirme (serialization) denir.

## 9. Serileştirme (serialization)

Serileştirme, bellekteki bir nesneyi diske yazabilmek için bayt dizisine çevirme işlemidir. Deserileştirme bunun tersidir: okunan bayt dizisini bir nesneye çevirmek.

Ön koşul: diske serileştirilecek nesneler ve bunların ilkel olmayan bütün üye alanları `java.io` paketindeki `Serializable` arayüzünü gerçeklemelidir. Bu arayüzün hiçbir metodu yoktur; bu tür arayüzlere işaretleyici (marker) arayüz denir. Java sanal makinesine "bu türden nesneler diske serileştirilebilir" diye bir işaret koyar.

Serileştirme için:

- Dosyayı simgeleyen ve çıktı için kullanılan temel akış `FileOutputStream`'dir; ama yetenekleri çok azdır.
- Daha geniş yetenekli `ObjectOutputStream` kullanılır. Bunun constructor'ı bir `FileOutputStream` (genel olarak bir `OutputStream`) bekler; böylece iki akış zincirlenmiş olur.
- Aynı akışa birden fazla nesne gönderilebilir.

Bir nesneyi serileştirmek için bütün üye alanları serileştirilebilir olmalıdır. Bir üyeyi serileştirmek istemiyorsanız ya da onu serileştirilebilir yapamıyorsanız (ör. o sınıfın kaynak kodu elinizde olmadığı için `implements Serializable` yazamıyorsanız), o alan görünürlük ve türden sonra `transient` anahtar kelimesiyle işaretlenir. O zaman bu alan diske yazılmaz; deserileştirmede değeri `null` olur ya da varsa varsayılan değeri alır. Böylece kaynak kodu elde olmayan bir sınıf yüzünden önünüz tıkanmaz.

## 10. serialVersionUID ve sürümleme

### 10.1 Contact sınıfı

Uygulama, arkadaşların ad, telefon ve e-posta bilgisini tutan basit bir adres defteridir (ekrandan, 01:25:00):

```java
package nyp12a;
public class Contact implements java.io.Serializable {
    private static final long serialVersionUID = 1L;
    private String name, phone, eMail;
    public Contact( String name ) { this.name = name; }
    public String getName( ) { return name; }
    public String getPhone( ) { return phone; }
    public void setPhone( String telefon ) {
        this.phone = telefon;     }
    public String getEMail( ) { return eMail; }
    public void setEMail( String mail ) { eMail = mail; }
    public String toString( ) {
        return name + " - " + phone + " - " + eMail;
    }
}
```

Sınıf normalde oldukça düzdür. Serileştirilebilir yapmak için iki şey yapılmıştır: `java.io.Serializable` arayüzünü gerçeklediği belirtilmiş ve `private static final long serialVersionUID = 1L;` alanı eklenmiştir. Sondaki `L` sayının `long` olduğunu gösterir.

### 10.2 serialVersionUID ne demek?

Slayttaki açıklama (ekrandan, 01:30:00):

- `private static final long serialVersionUID = 1L;`
- 1 yerine belirli bir sürüm numarası verilebilir ya da IDE'ye benzersiz bir tanımlayıcı otomatik ürettirilebilir.
- Bu üye yazılmazsa ilgili uyarı `@SuppressWarnings("serial")` ile gizlenebilir.
- Nesneleri farklı kaynaklardan kaydeden ve yükleyen uygulamalar olacaktır. Zamanla bu nesnelerin sınıflarının kaynak kodu da, uygulamaların kaynak kodu da değişebilir. Bütün bu sınıfların farklı sürümleri bir arada bulunabilir; uyumsuzlukları önlemek için bir sürümleme mekanizması gerekir.
- Bu mekanizma sınıflara farklı (ve muhtemelen artan) seri numaraları verilip uygulamalarda bu numaranın kontrol edilmesiyle gerçekleştirilir.

Hoca bunu bir senaryoyla açıkladı. Uygulama 1.0 sürümüyle piyasaya çıkar, sonra 1.1, 1.2, belki 2.0 gelir. Yeni sürümlerde `Contact` gibi serileştirilen sınıfların kaynak kodu da değişebilir; örneğin bugün bir telefon ve bir e-posta varken birkaç ay sonra ikinci telefon ve ikinci e-posta eklenebilir. Adres defteri bir `contacts.dat` dosyasında saklanıyor olsun. Bu dosya başka bir bilgisayara kopyalandığında orada uygulamanın daha yeni sürümü olabilir. Yeni sürüm iki e-posta ve iki telefon bekler ama dosyada birer tane bulur; çeşitli istisnalar oluşur. Bunu önlemek için yeni sürümün kodu, dosyayı işlemeden önce sürüme bakmalıdır: eski sürümde `serialVersionUID` 1, yeni sürümde 3 ise, numara 3'ten küçükse kullanıcıya eski sürümle oluşturulmuş bir dosyayla çalıştığı bildirilmeli ve program çökmesin diye işlem yapılmamalıdır. Sahada gerçekten kullanılacak uygulamalarda buna dikkat edilmelidir; bu ders kapsamında farklı seri numaralarıyla uğraşılmayacak, yalnız altyapı anlatılmıştır.

`@` ile başlayan her şey annotation'dır. Kodun çalışmasına hiçbir etkisi yoktur; kodu inceleyen ve onunla işlem yapan programlara (derleyici, IDE) verilen sinyallerdir. `@SuppressWarnings("serial")`, derleyiciye "serialVersionUID eksikliğinin (aslında hata değil, uyarı) farkındayım, bana gösterme" demenin yoludur.

## 11. İletişim listesi örneği: nesneleri tek tek yazmak

### 11.1 CreateContacts

`Scanner` ile girdi alınacağı için `java.util`, dosya işlemleri için `java.io` paketi gerekir. `main` içinde kullanıcıya kaç kişi gireceği sorulur, o kadar kişilik bir dizi oluşturulur. Scanner'ın bilinen hatasından kurtulmak için sayı okunduktan sonra fazladan boş bir `nextLine()` çağrılır. Sonra her kişi için ad, telefon ve e-posta sorulur.
<!-- BELİRSİZ: CreateContacts'ın girdi alan ilk kısmı (slayt 190) karelerde görünmüyor; bu paragraf anlatımdan kurulmuştur. -->

Kodun dosyaya yazan kısmı (ekrandan, 01:35:00):

```java
try {
    String fileName = "contacts.dat";
    ObjectOutputStream writer = new ObjectOutputStream(
        new FileOutputStream( fileName )   );
    writer.writeObject( contactCount );
    for( Contact aContact : contacts )
        writer.writeObject( aContact );
    writer.close();
    System.out.println("The information you have entered has "
        + "been successfully saved in file " + fileName);
}
catch( IOException e ) {
    System.out.println("An exception has occured during "
        + "writing to file.");
    e.printStackTrace();
}
input.close();
}
}//HW: Do not use an array
```

Dosya işlemlerinde hiçbir şey ters gitmese bile `IOException` kontrol edilmek zorundadır; bu yüzden try bloğu açılır. `ObjectOutputStream` constructor'ında bir çıktı akışı ister; bu akış `FileOutputStream`'dir. `FileOutputStream` oluşturulup `ObjectOutputStream`'e verilir ve adı `writer` olan serileştirme akışı elde edilir. Önce kayıt sayısı, sonra for döngüsüyle dizideki bütün nesneler tek tek yazılır. Akışı kapatmak unutulmamalıdır. Hata olursa genel bir bilgilendirme yapılır ve `printStackTrace()` ile ayrıntı verilir.

Hoca, `input.close()`'un aslında bir `finally` bloğuna konmasının daha temiz olacağını söyledi. Dizi örnek basit olsun diye kullanılmıştır, normalde bir liste tercih edilir.

### 11.2 Neden kayıt sayısı önce yazılıyor?

Kullanıcının kaç kayıt gireceği önceden bilinemez, dolayısıyla dosyada kaç kayıt olacağı da bilinmez. `Contact`'ın üye alanları belli olduğu için bir kaydın kaç bayt tuttuğunun belli olduğu düşünülebilir; ama ad, telefon ve e-posta `String`'dir ve 10 karakter de olabilir, 500 karakter de. Kayıtların sabit bir genişliği yoktur; bu yüzden dosyanın boyutuna bakıp "bu dosyada şu kadar kayıt var" denemez.

"Dosya sonuna (EOF) kadar okuyup kayıtları sayalım, sonra geri dönüp o kadar okuyalım" önerisinin iki sorunu vardır: dosyanın üzerinden iki kez geçmeyi gerektirir ve "EOF'e kadar oku" yaklaşımı Java'da hatalıdır. En kolay, temiz ve verimli çözüm kayıt sayısını önceden dosyaya yazmaktır.

Serileştirme yalnız ilkel olmayan nesneler üzerinden yapılmalıdır. `int` ilkel olduğu için onun sarmalayıcısı `Integer` yazılır. Bu yüzden slaytta `contactCount` `Integer` olarak tanımlanmıştır; Scanner'dan ilkel `int` alınır ama otomatik sarmalama (autoboxing) sayesinde doğrudan sarmalayıcıya atanabilir.

> **Ders sonrası not:** Hoca autoboxing'in yanılmıyorsa Java 6.0 ile geldiğini söyledi; autoboxing büyük olasılıkla Java 5 (1.5) ile gelmiştir.

## 12. Deserileştirme: nesneleri geri okumak

### 12.1 Girdi ve çıktı terimleri

Odak noktası bellektir: dosyadan belleğe gelen veri girdi (input), bellekten dosyaya yazılan veri çıktıdır (output). Diske yazmak için serileştirme, diskten okumak için deserileştirme yapılır. Bu kelimelerin doğru kullanılması gerekir.

### 12.2 Deserileştirmenin kuralları

Slayttaki özet (ekrandan, 01:40:00):

- Diskteki bir dosyadan bütün nesneler okunacaktır.
- Deserileştirme için `ObjectInputStream` ve `FileInputStream` nesneleri zincirlenir. Temel akış `FileInputStream`'dir ama metotları bütün nesneleri okumaya yaramaz; bu işi `ObjectInputStream` yapar ve constructor'ında bir `FileInputStream` bekler.
- Akıştan okunan nesneler `Object` sınıfının örneği olarak geldiği için typecasting gerekir. `ObjectOutputStream`'in `writeObject` metodu parametre olarak `Object` bekler; `Object` kozmik üst sınıf olduğu için her türden nesne yazılabilir. Okurken de `Object` gelir. Dosyaya yalnız `Contact` yazdığımızı biliyoruz, ama Java kuvvetli tiplemeli bir dil olduğu için önce tür kontrolü, sonra dönüşüm yapılır.
- "Type safety: Unchecked cast" uyarısı `@SuppressWarnings("unchecked")` ile gizlenebilir. Bu, Java derleyicisinin dikkate aldığı bir annotation'dır; IDE ayarlarından da kapatılabilir ama kod IDE'den bağımsız anlatılmaktadır.
- Nesneler bir dizide saklanacaksa kaç nesne olacağını bilmek gerekir. `.length` dizinin kapasitesini verir ama dizi daha okunmamıştır; bu yüzden kayıt sayısı önce yazılmalıydı. Dinamik büyüyebilen veri yapılarında (liste, map) bu sorun yaşanmaz.

Hoca, deserileştirmede generic yapının (kendisi baktığında) kurulmamış olduğunu, yeni sürümlerde gelip gelmediğine bakacağını not aldı.

### 12.3 ShowContacts

Eclipse'teki kod (ekrandan, 02:10:00; kodun başı anlatımdan):

```java
String fileName = "contacts.dat";
try {
    ObjectInputStream reader = new ObjectInputStream(
        new FileInputStream( fileName ) );
    Integer contactCount = (Integer) reader.readObject();
    for( int i=0; i<contactCount; i++ ) {
        Contact aContact = (Contact)reader.readObject();
        System.out.println(aContact);
    }
    reader.close();
}
catch( IOException e ) {
    System.out.println("An exception has occured during file reading.");
    e.printStackTrace();
}
catch( ClassNotFoundException e ) {
    System.out.println("An exception has occured while processing read records.");
    e.printStackTrace();
}
}//Alternative: You could populate an array, too.
```

Akıştan nesne okuyan metot `readObject()`'tir. İlk çağrıda dönen nesne bir `Integer`'dır, çünkü önce `Integer` yazılmıştı. Hoca burada `instanceof` kontrolü yapmadan doğrudan dönüştürdüğünü, çünkü o değeri kendisinin yazdığını ve `Integer` olduğunu bildiğini söyledi. Sonra for döngüsünde kayıt sayısı kadar `readObject()` çağrılır, her biri `Contact`'a dönüştürülüp ekrana yazılır. `reader` kapatılır. (Slayttaki sürümde mesajlar biraz farklıdır: "A file reading exception has occured." ve "A class cast exception has occured."; ekrandan, 01:45:00.)

Deserileştirmede `IOException`'a ek olarak `ClassNotFoundException` da yakalanmak zorundadır. `ShowContacts` ve `Contact` aynı pakettedir, yani sınıfın bulunamaması pek mümkün görünmez; ama örneğin `Contact.class` dosyası kopyalanırken bozulmuş olabilir ve JVM onu okuyamayabilir. Bu olasılık her zaman vardır; bu yüzden Java bu istisnayı checked yapmıştır.

## 13. Dosya sonu sorunu ve veri yapısını serileştirmek

Hoca "EOF'e gelene kadar kayıt oku" türünden bir çalışmanın neden yapılamadığını açıkladı (ekrandan, 01:50:00):

- Hoca, böyle bir kontrol için bir `hasNext` metodunun JDK 7'ye kadar doğru çalışmadığını, JDK 8 ile tamamen kaldırıldığını söyledi. <!-- BELİRSİZ: hocanın söz ettiği hasNext metodunun hangi sınıfa ait olduğu altyazıdan anlaşılmıyor; ObjectInputStream'de böyle bir metot bulunmuyor. -->
- `int ObjectInputStream.available()` metodu kalan okunabilir bayt sayısını döndürür ama biraz hatalı çalışır (slaytta coderanch kaynağı verilmiştir).
- Ayrıca `readObject()` dosya sonunda `null` döndürmez; bu yüzden `null` kontrolü de yapılamaz (slaytta stackoverflow kaynağı verilmiştir).
- İstisnanın oluşmasına izin verip döngüyü catch bloğunda bitirmek de bir çözümdür; ama istisna yakalama program akışını değiştirmek için icat edilmemiştir. İstisna varsa program akışı durur, istisnanın nedeni çözülür, gerekiyorsa kaynak kod düzeltilir ve uygulama yeniden çalıştırılır. Bu yüzden bu üçüncü çözüm de pek tercih edilmez.
- Nesne sayısını önce yazmaktan daha iyi bir seçenek, bütün veri nesnelerine referans tutan tek bir kapsayıcı nesne kullanmaktır. Bu kapsayıcı bir veri yapısıdır (liste ya da map). Örneğin bütün `Contact` nesneleri bir `LinkedList` içine konur, liste tek seferde serileştirilir ve gerektiğinde tek seferde deserileştirilir. En uygun ve en rahat çözüm budur.
- Ancak kapsayıcıdaki nesneler de `java.io.Serializable` arayüzünü gerçeklemelidir; gerekiyorsa `transient` kullanılır.
- A→B gibi bir ilişki varsa (A nesneleri serileştirilecek ve A, B'ye referans tutuyorsa) hem A hem B `Serializable`'ı gerçeklemelidir.

> **Hocanın vurgusu:** Nesneleri bir veri yapısına koyup serileştirseniz bile o nesnelerin `Serializable` arayüzünü gerçeklemesi şarttır.

## 14. Eclipse'te çalıştırma, autoboxing ve çoklu catch

### 14.1 Dizi sürümünün çalıştırılması

Hoca `CreateContacts`'ı çalıştırıp üç kişi girdi, `contacts.dat` dosyasının proje klasöründe yeni oluşturulduğunu gösterdi. Bu ikili bir dosyadır; Not Defteri'nde açıldığında bazı şeyler seçilebilir ama her şey anlaşılmaz. Dosyada önce bir `java.lang.Integer` nesnesi (ve onun üst sınıfı `java.lang.Number`), sonra `nyp12a.Contact` sınıfından nesneler, `eMail`, `name`, `phone` alan adları ve `String` değerler görülebilir; kayıt sayısı olan 3 rakamı ise doğrudan görünmez (ekrandan, 02:15:00). Okunabilir olsun isteseydik metin dosyası yazardık. `ShowContacts` çalıştırıldığında girilen kayıtlar sorunsuzca ekrana yazdırıldı (ekrandan, 02:10:00).

### 14.2 Eclipse'in serialVersionUID önerileri

`serialVersionUID` yazılmazsa Eclipse uyarı verir. Hızlı düzeltme (Quick Fix) üç seçenek sunar: varsayılan bir değer ekle (`1L`), otomatik üretilmiş bir değer ekle (uzun, enteresan görünen bir `long` sayı) ya da `@SuppressWarnings` koy. Sürüm numarası olarak kendiniz de değer verebilirsiniz; ama "0.1" gibi noktalı sürüm numarası kullanılamadığı için her değişiklikte 1, 2, 3 diye sırayla artan numaralar vermek daha kullanışlıdır.

### 14.3 finally ve çoklu catch

Hoca `input.close()`'u `finally` bloğuna taşıyarak sorunsuz çalıştığını gösterdi; `finally` öğrenildiği için onu kullanmak en güzelidir.

`ShowContacts`'ta `IOException` ve `ClassNotFoundException` bloklarının yalnız açıklamaları farklıdır. Açıklama koymayıp yalnız `printStackTrace()` yapacaksak ya da istisna türünden bağımsız bir mesaj vereceksek, iki istisna tek bir catch bloğunda birleştirilebilir:

```java
catch( IOException | ClassNotFoundException e ) {
    e.printStackTrace();
}
```

Hoca kendisinin ayrı blokları tercih ettiğini söyledi.

> **Ders sonrası not:** Hoca çoklu catch'in yanılmıyorsa Java 6 ile geldiğini söyledi; bu özellik büyük olasılıkla Java 7 ile gelmiştir.

### 14.4 int ile autoboxing denemesi

Hoca kayıt sayısını `Integer` yerine `int` tanımlayıp yeniden denedi. Derleme hatası çıkmadı, `writeObject` sayıyı yazdı ve okuma tarafı da `(Integer)` dönüşümüyle sorunsuz çalıştı. Oluşan dosyalar Not Defteri'nde karşılaştırıldığında ikisinde de `java.lang.Integer` görüldü: ilkel değer kaydedilirken otomatik olarak sarmalayıcısına çevrilmiştir (ekrandan, 02:15:00). Bayt bayt tam karşılaştırma için bir hex editörü gerekir.

### 14.5 LinkedList sürümü (nyp12b)

Bu sürümde `Contact` sınıfı hiç değişmez. Hoca şunu vurguladı: verinin saklandığı yapıyı değiştirirken verinin kendi sınıfının kaynak kodunu da değiştirmemiz gerekseydi ya doğru bir şey yapmamışız ya da dil bu altyapıyı düzgün kuramamış demektir.

`CreateContacts` bir `LinkedList<Contact>` oluşturup ilklendirir (ilklendirmeyi unutmamak gerekir), kişileri listeye ekler ve tek bir `writeObject` ile listenin tamamını yazar. `ShowContacts` tek bir `readObject` ile okuduğu nesneyi `LinkedList<Contact>`'a dönüştürüp atar ve tüm elemanları yazdırır. Kayıt sayısını önce yazmaya gerek kalmaz. Bu sürümün dosyasında Not Defteri'nde `java.util.LinkedList` görülür; sonda koleksiyonun sonunu gösteren bir işaret olduğu tahmin edilir.

Bu sürümün tam kodu karelerde görünmediği için anlatıma göre kurulup Java 25 ile denenmiş hali şöyledir (bu kod derste bu biçimde gösterilmedi):

```java
// CreateContacts (LinkedList sürümü, yazma kısmı)
LinkedList<Contact> contacts = new LinkedList<Contact>();
// ... kullanıcıdan alınan her Contact için: contacts.add(c);
try {
    ObjectOutputStream writer = new ObjectOutputStream(
        new FileOutputStream("contacts3.dat"));
    writer.writeObject(contacts);
    writer.close();
} catch (IOException e) { e.printStackTrace(); }
finally { input.close(); }

// ShowContacts (LinkedList sürümü)
@SuppressWarnings("unchecked")
public static void main(String[] args) {
    try {
        ObjectInputStream reader = new ObjectInputStream(
            new FileInputStream("contacts3.dat"));
        LinkedList<Contact> contacts = (LinkedList<Contact>) reader.readObject();
        reader.close();
        for (Contact c : contacts) System.out.println(c);
    } catch (IOException | ClassNotFoundException e) { e.printStackTrace(); }
}
```

## 15. Metin dosyaları

Metin dosyaları ya da başka modlarda çalışmak için hatırlanması gereken en önemli şey hangi akışların zincirleneceğini bilmektir; arka plandaki mantık hemen hemen aynıdır. Metin dosyalarında girdi için `FileReader` ile `BufferedReader` eşleştirilir; `BufferedReader`'ın bu konudaki yetenekleri iyidir. Çıktı için doğrudan `FileWriter` kullanılabilir, ek bir zincire gerek yoktur. Farklı biçimlendirmelerle yazdırma gibi ihtiyaçlar için Core Java Volume 2 ya da başka bir Java kitabına bakılabilir. Hoca, metin modunda yazma örneğinin kodunun da örnek kodlar arasında bulunduğunu, incelenebileceğini söyledi.

## 16. İç sınıflar (inner classes)

### 16.1 Tanım ve yetenekler

Bir sınıfın içine üye alanlar ve metotlar kodlanabildiği gibi sınıf da kodlanabilir. İçteki sınıfa iç sınıf (inner class), onu kapsayan sınıfa dış sınıf (outer class) denir. Slayttaki özet (ekrandan, 02:25:00):

- İç sınıf dış sınıfın private olanlar dahil bütün üyelerine erişebilir.
- Private tanımlanırsa aynı paketteki diğer sınıflardan da gizlenir.
- Çok iş parçacıklı (multithreading) ve GUI programlamada anonim iç sınıflar biçiminde sık kullanılır. Anonim, adı olmayan demektir.
- İç sınıfta static metot tanımlanamaz.
- Örnek: `Person` ve `Employee` sınıfları.

İç sınıfın dış sınıfın private üyelerine erişebilmesi mantıksız değildir: bir sınıfın metodu da o sınıfın private üyelerine rahatça erişir. İç sınıf da nihayetinde dış sınıfın bir üyesi gibidir; verilen görünürlüğe göre nokta gösterimiyle erişilir.

Neden iç sınıfa ihtiyaç olsun? Normalde bir pakete yazılan bir sınıfı o paketteki bütün sınıflar görebilir ve public üyelerine erişebilir. Öyle kritik bir sınıfınız varsa ki ona yalnız tek bir sınıf üzerinden müdahale edilsin, başka hiçbir sınıf onun varlığından haberdar olmasın, o sınıfı private iç sınıf olarak kodlayabilirsiniz. Anonim iç sınıflar ileride GUI ve çok iş parçacıklı programlama konularında gösterilecektir.

Static metot konusunda hoca şu gerekçeyi verdi: iç sınıf doğrudan erişilen bir sınıf değildir, public de olsa private de olsa dış sınıf üzerinden erişilmesi gerekir; bu yüzden static metot tanımlanamaz. Static alanın da tanımlanamaması gerektiğini düşündüğünü, buna bakacağını söyledi.

> **Ders sonrası not:** Bu kısıt Java 15'e kadar geçerliydi (static sabitler hariç). Java 16'dan beri iç sınıflar static metot ve static alan tanımlayabilir; Java 25 ile private bir iç sınıfa `static int` alan ve `static void` metot eklenerek denendi, sorunsuz derlendi.

### 16.2 Örneğin amacı

Örnek, daha önce kalıtımda yapılan kişi ve çalışan sınıflarının iç sınıfla yeniden yazılmasıdır. Hoca bunun kesinlikle daha doğru olmadığını, normalde kalıtımın daha doğru çözüm olduğunu vurguladı. Ancak `Employee` sınıfına başka kimse müdahale etmesin istiyorsanız iç sınıf kullanılabilir; belirgin bir ihtiyaç yoksa normal sınıf yapılmalıdır. İç sınıfın UML'de nasıl gösterildiğine bakamadığı için hoca doğrudan kod üzerinden gitti.

## 17. İç sınıf örnekleri: private, public, dış sınıf üzerinden erişim, Person.this

### 17.1 Private iç sınıf (nyp13a)

Kod (ekrandan, 02:30:00; örnek kişi adları genel adlarla değiştirildi):

```java
package nyp13a;
public class Person {
    private String name;
    public Person( String name ) { this.name = name; }
    @SuppressWarnings("unused")
    private class Employee { //begin inner class
        private int salary;
        public Employee( int salary ) { this.salary = salary; }
        public int getSalary() { return salary; }
        public void setSalary(int salary) { this.salary = salary; }
        public String toString( ) { return name + " " + salary; }
    } //end inner class
    public static void main( String[] args ) {
        Employee[] staff = new Employee[3];
        Person kisi;
        kisi = new Person("Kişi A");
        staff[0] = kisi.new Employee( 10000 );
        kisi = new Person("Kişi B");
        staff[1] = kisi.new Employee( 7500 );
        kisi = new Person("Kişi C");
        staff[2] = kisi.new Employee( 6000 );
        for( Employee eleman: staff )
            System.out.println( eleman );
    }
}
```

`Person` sınıfının kapanış süslü parantezi kapanmadan içine `private class Employee` tanımlanmıştır. `Employee` kendi içinde normal nesneye yönelim mantığıyla çalışır: maaş alanı, maaşı alan constructor, getter, setter ve `toString`. `Employee`'nin `toString`'i `Person`'ın private `name` alanına rahatça erişir.

`main` içinde üç kişilik bir `Employee` dizisi oluşturulur. `Employee` nesnesi tek başına ilklendirilemez; mutlaka bir kişiye bağlanmalıdır, çünkü `Employee` aslında bir `Person`'ın üyesidir. Bu yüzden `kisi.new Employee(10000)` biçiminde, yani "dış nesne nokta new iç sınıf" şeklinde oluşturulur. Senaryoda her kişi işe alınmış kabul edilir; işe alma/çıkarma mantığı yoktur.

Çıktı (ekrandan, 02:45:00; adlar genel adlarla):

```text
Kişi A 10000
Kişi B 7500
Kişi C 6000
```

Hoca sonra birinci çalışana zam yaptı: `staff[0].setSalary( staff[0].getSalary() + 100 );`. Çıktıdaki maaş 10100 oldu (ekrandan, 02:35:00).

Bu `main` metodu yalnız `Person` sınıfının içinde çalışabilir, çünkü private iç sınıf türünden nesneler oluşturulmaktadır. Hoca kodu aynı paketteki yeni bir `Test` sınıfına kopyaladığında Eclipse `Person.Employee`'nin görünür olmadığını (not visible) bildiren derleme hataları verdi (ekrandan, 02:35:00). Eclipse'in hata açıklamasında da iç sınıf nesnesinin `x.new A()` biçiminde, bir dış sınıf örneğiyle ilklendirilmesi gerektiği yazar.

Kod Java 25 ile denendi; zam satırıyla birlikte `Kişi A 10100`, `Kişi B 7500`, `Kişi C 6000` çıktısı alındı.

### 17.2 Public iç sınıf (nyp13b)

Bu sürümde `Person` içinde `public class Employee` yazılır; geri kalan her şey aynıdır ve iç sınıf hâlâ dış sınıfın private üyesine erişir. Artık `main` metodu başka bir sınıfa (`TestInnerClassDirectly`) taşınabilir. Ancak import işi biraz çetrefillidir: `TestInnerClassDirectly` ile `Person` aynı pakette olsa bile `import nyp13b.Person.Employee;` komutu mutlaka verilmelidir. İç sınıf kullanılıyorsa aynı pakette bile "paket adı, dış sınıf adı, nokta, iç sınıf adı" biçiminde import gerekir. Hoca import'u yorum satırına aldığında Eclipse'in sınıfı tanımadığını gösterdi. Import yapmak yerine her yerde `Person.Employee` de yazılabilir; hoca bir kez import edip her yerde kısa adı kullanmayı tercih ettiğini söyledi. Eclipse'in "compare with" özelliğiyle iki sürüm karşılaştırıldığında farkın yalnız `public`, import ve `main`'in yeri olduğu görüldü. `println` zaten `toString`'i otomatik çağırdığı için `eleman.toString()` yazmak şart değildir.

### 17.3 Dış sınıf üzerinden erişim (nyp13c)

Slayttaki amaç (ekrandan, 02:40:00): private bir iç sınıfa başka herhangi bir sınıftan, dış sınıfın public bir metodu aracılığıyla erişmek; bu sırada iç nesneye dış nesneden ulaşmak.

Kod (ekrandan, 02:50:00):

```java
package nyp13c;
public class Person {
    private String name;
    private Employee employee;
    public Person(String name) { this.name = name; }
    public void enlist( int salary ) {
        employee = new Employee( salary ); }
    public String toString( ) {
        String mesaj = name;
        if( employee != null )
            mesaj += " " + employee.getSalary( );
        return mesaj;
    }
    private class Employee {
        private int salary;
        public Employee( int salary ) { this.salary = salary; }
        public int getSalary() { return salary; }
        @SuppressWarnings("unused")
        public void setSalary(int salary) { this.salary = salary; }
    }
}
```

İç sınıf yine `private`'tır, çünkü dışarıdan doğrudan erişilmeyecek, her zaman dış sınıf üzerinden erişilecektir. Dış sınıfta iç sınıf türünden normal bir üye alan (`employee`) tanımlanmıştır; böylece belirli bir dış sınıf nesnesiyle belirli bir iç sınıf nesnesi arasında sahiplik ilişkisi kurulur. Önceki sürümde bu ilişkilendirme `main`'de yapılıyordu.

`enlist` (işe almak) metodu, verilen maaşla `Employee`'yi ilklendirip `employee` alanına atar. Uygulama alanının diliyle kişi işe alınmış olur; teknik diliyle dış sınıf türünden bir nesneye iç sınıf türünden bir üye alan ilklendirilip atanmış olur. Bu ilklendirme dışarıdan yapılamaz, çünkü iç sınıf private'tır.

`toString` önce her durumda adı mesaja koyar. `employee` `null` değilse kişi işe alınmış demektir; o zaman mesaja maaş da eklenir.

Başka bir sınıftaki `main` (`TestInnerClassViaOuterClass`) farklıdır: artık `Employee` dizisi oluşturulamaz, çünkü private iç sınıf her yerden gizlidir. Bunun yerine `Person` dizisi oluşturulur; kişiler oluşturulup `enlist` ile işe alınır ve hepsi yazdırılır. Hoca sonra kişilerden birinin `enlist` satırını kaldırdı: o kişi yalnız adıyla, maaşsız yazıldı, yani yalnız bir `Person` olarak tanıtıldı (ekrandan, 02:50:00).

Anlatıma göre kurulup Java 25 ile denenen kullanım (iki kişi işe alınmış, biri alınmamış; derste bu biçimde gösterilmedi):

```text
Kişi A 10000
Kişi B
Kişi C 5000
```

İki `Person` sürümü karşılaştırıldığında yeni sürümde iç sınıf türünden üye alan ve `enlist` metodu eklenmiş, `toString` işe alınma durumuna göre farklılaşmıştır.

> **Hocanın vurgusu:** Bir iç sınıfı public mi private mi yapacağınız önemli bir karardır. Public yaparsanız normal dış sınıf tanımlamaktan pek farkı yoktur; private yaparsanız erişimi tamamen kapatıp yalnız dış sınıf üzerinden erişim sağlayarak kontrolü sıkılaştırabilirsiniz.

### 17.4 İç nesneden dış nesneye: Person.this (nyp13d)

Belirli bir `Employee` nesnesinin hangi `Person` nesnesiyle ilişkili olduğunu öğrenmek için iç sınıfın içinde `DisSinifAdi.this`, burada `Person.this` yazılır. Hoca bunu göstermek için `nyp13d` paketinde `Person`'ın `toString`'ini kaldırdı (böylece `Object`'in `toString`'i nesnenin sınıf adını ve hash kodunu yazar), `Person`'a `employee` alanı için bir getter ekledi ve `Employee`'nin `toString`'inde `Person.this` üzerinden bağlı kişinin `toString`'ini döndürdü. Test sınıfı (ekrandan, 02:55:00):

```java
package nyp13d;
public class TestInnerClassViaOuterClass {
    public static void main(String[] args) {
        Person kisi = new Person( "Kişi A" );
        kisi.enlist( 10000 );
        System.out.println( kisi );
        System.out.println( kisi.getEmployee() );
    }
}
```

<!-- BELİRSİZ: nyp13d'deki Employee.toString ve getEmployee kodu karelerde tam görünmüyor; anlatımdan "Person.this" üzerinden kişinin toString'inin döndürüldüğü anlaşılıyor. -->

Çıktıda iki satır da `nyp13d.Person@762efe5d` oldu (ekrandan, 02:55:00): kişinin hash kodu ile çalışanın bağlı olduğu kişinin hash kodu aynıdır, yani aynı nesnedir. Hoca, iç sınıftan dış sınıfın private üyelerine bile doğrudan erişilebildiği için buna pratikte pek ihtiyaç olmayacağını, ama yapılabildiğini göstermek istediğini söyledi.

Bu sırada hoca Eclipse'in kullanılmayan alanlar için verdiği uyarıları `@SuppressWarnings("unused")` ile kapattı ve annotation'ın sınıf düzeyine taşınınca o sınıftaki bütün ilgili uyarıları kapattığını gösterdi. `@SuppressWarnings("all")` ile bütün uyarıların kapatılabileceğini de gösterdi, ama bunu yapmamayı istedi.

> **Hocanın vurgusu:** Uyarılar sizin bir şeyi gözden kaçırdığınızın önemli bir işareti olabilir; bütün uyarıları kapatmayın. "Gösterdim ama yapmayın."

## Örnek Sorular

**Soru 1** (derste sözlü, 00:25:18): `Calendar` nesnesi neden constructor yerine bir factory metotla (`Calendar.getInstance()`) alınıyor?

> **Cevap (derste):** Hoca kesin nedeni bilmediğini, tahminini söyledi: `Date`'in tarih aritmetiği metotları sorunlu olduğu için deprecated edildi ve yerine çok sayıda takvim sistemini destekleyen `Calendar` getirildi. Arka plan karmaşıklaştıkça factory metot kullanmak tercih edilir; programcı farklı takvimler için yazılmış olası alt sınıfları bilmeden, kara kutu olarak bir takvim nesnesi alır ve `add`, `set`, `get` ile kullanır.

**Soru 2** (derste sözlü, 00:27:17): Aynı soyutlama için bir arayüz verilemez miydi?

> **Cevap (derste):** Verilebilirdi; ama iş karmaşıklaştıkça factory'ler üzerinden çalışmak genelde tercih edilir. Tasarım kalıpları çalışılınca bu görülecektir.

**Soru 3** (ekrandan, 00:40:00): MarketShelf örneğini typecasting kullanmadan nasıl tasarlarsınız?

> **Cevap (derste):** `getExpireDate(): Date` ve `isExpired(): boolean` metotları `Item` arayüzüne (ya da soyut bir `Item` sınıfına) konur. `Food` bunları gerçek gövdelerle yazar. `Electronics`, `isExpired()` için `return false` yazar; `getExpireDate()` için bir yıl sonrasını ya da `null` döndürebilir (`null` ise `toString` tarihi kullanmamalıdır). Böylece `printExpiredItems()` her öğede doğrudan `item.isExpired()` çağırabilir. Ortak alanlar (barkod, fiyat) varsa soyut üst sınıf daha iyidir.

**Soru 4** (derste sözlü, 01:34:42): Dosyadaki kayıt sayısını önceden yazmak yerine dosya sonuna kadar okuyup kayıtları sayamaz mıyız?

> **Cevap (derste):** Bu, dosyanın üzerinden iki kez geçmeyi gerektirir; ayrıca "EOF'e kadar oku" yaklaşımı Java'da güvenilir değildir: `available()` hatalı çalışabilir, `readObject()` dosya sonunda `null` döndürmez, istisnayla döngüyü bitirmek istisna mantığına aykırıdır. Temiz çözüm kayıt sayısını önce yazmak, daha iyisi bütün nesneleri tek bir koleksiyonda serileştirmektir.

**Soru 5** (ekrandan, 01:35:00): Slayttaki not: "HW: Do not use an array". `CreateContacts`/`ShowContacts` örneğini dizi kullanmadan yazın.

> **Cevap (derste):** Hoca derste `nyp12b` sürümünü gösterdi: kişiler bir `LinkedList<Contact>` içinde tutulur, liste tek bir `writeObject` ile yazılır ve tek bir `readObject` ile okunup `(LinkedList<Contact>)` dönüşümüyle atanır; kayıt sayısını önceden yazmaya gerek kalmaz. Anlatıma göre kurulan ve Java 25 ile denenen kod 14.5 bölümündedir.

**Soru 6** (derste sözlü, 01:45:40): Bir öğrenci, `input.close()` ve `finally` yerine Java 7 ile gelen try-with-resources yazımının kullanılıp kullanılamayacağını sordu.

> **Cevap (derste):** Hoca bunu bilmediğini, bakacağını, büyük ihtimalle kullanılabileceğini ve derleme hatası vermeyip doğru çalıştığı sürece sorun olmayacağını söyledi.

> **Çözüm (derste verilmedi):** Kullanılabilir. `ObjectInputStream`/`ObjectOutputStream` ve `Scanner`, `AutoCloseable` arayüzünü gerçeklediği için try parantezinde açılan kaynaklar blok bitince (istisna olsa da) otomatik kapatılır:
>
> ```java
> try (ObjectInputStream reader = new ObjectInputStream(
>          new FileInputStream("contacts.dat"))) {
>     Integer contactCount = (Integer) reader.readObject();
>     for (int i = 0; i < contactCount; i++)
>         System.out.println((Contact) reader.readObject());
> } catch (IOException | ClassNotFoundException e) {
>     e.printStackTrace();
> }
> ```
>
> Bu biçim Java 25 ile `ShowContacts` mantığında denendi ve kayıtları aynı şekilde okudu.

## Dersin Toparlaması

Ders üç konuyu işledi. İlk olarak typecasting: yukarı dönüşüm otomatik ve güvenliyken aşağı dönüşüm `instanceof` ile kontrol edilip `((Tür)ref)` biçiminde elle yapılır. MarketShelf örneğinde `Calendar` (factory metot, aylar 0'dan) ve `Date` (`new Date()`, `before`/`after`) kullanımı da görüldü. Hoca typecasting'in "gerekli bir kötülük" olduğunu, generics'ten sonra yalnız deserialization'da zorunlu kaldığını ve tasarımın her zaman typecasting'siz yapılabileceğini gösterdi.

İkinci konu dosyalarla çalışmaktı: `IOException` ailesi ve `SecurityException`, `File` sınıfıyla dosya yönetimi (dosya/klasör ayrımı, nesnenin gerçek dosya olmaması, tam ve göreli yol, yol ayırıcı), akışlar, ikili/metin ve sıralı/rastgele erişim. Ardından `Serializable`, `transient` ve `serialVersionUID` ile serileştirme, `ObjectOutputStream`/`FileOutputStream` ve `ObjectInputStream`/`FileInputStream` zincirleri, kayıt sayısı sorunu ve bunun en iyi çözümü olarak bir koleksiyonun tek seferde serileştirilmesi anlatıldı. Son olarak iç sınıflar işlendi: dış sınıfın private üyelerine erişim, `dis.new Ic(...)` ile oluşturma, public iç sınıf için import kuralı, private iç sınıfa dış sınıfın metotları üzerinden erişim ve `Person.this`. Hoca anonim iç sınıfların ileride GUI ve çok iş parçacıklı programlama konularında gösterileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
