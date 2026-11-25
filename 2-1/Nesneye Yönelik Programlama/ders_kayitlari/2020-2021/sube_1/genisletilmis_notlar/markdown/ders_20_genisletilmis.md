# Ders 20 Genişletilmiş Notu: Tür Dönüşümü, Dosya İşlemleri ve Serileştirme, İç Sınıflar ve Çoklu İş Parçacığı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tür Dönüşümü (Typecasting) ve MarketShelf Örneği
- 2. Calendar ve Date Sınıfları
- 3. Typecasting'in Eleştirisi ve Tasarımla Önlenmesi
- 4. Dosyalarla Çalışma: İstisnalar ve İki Kategori
- 5. Dosya Yönetimi: java.io.File
- 6. G/Ç İşlemleri: İkili ve Metin Dosyaları, Akışlar
- 7. Akışları Zincirleme: Nesne Okuma ve Yazma
- 8. Serileştirme ve Serializable Arayüzü
- 9. Annotation'lar ve @SuppressWarnings
- 10. Arkadas Örneği: Diziyle Yazma ve Okuma
- 11. Dosya Sonu Sorunu ve Veri Yapısını Yazma
- 12. Akışlar ve Annotation'lar Üzerine Soru-Cevap
- 13. İç Sınıflar (Inner Classes)
- 14. Contact Örneği ve Veri Yapısı Seçimi
- 15. Çoklu İş Parçacığına Giriş: Süreç, Çekirdek ve Durumlar
- 16. Runnable, Thread ve SoccerFan Örneği
- 17. Executors ve ExecutorService
- 18. Yarış Durumu ve synchronized
- Örnek Sorular

## 1. Tür Dönüşümü (Typecasting) ve MarketShelf Örneği

Hoca derse kalıtım konusunu hatırlatarak başladı. Bir sınıfın nesnesi, üst sınıfın beklendiği her yerde kullanılabilir: alt sınıfın nesnesi oluşturulur ve bu nesne üst sınıf türünde bir referansla takip edilir. Bu, kalıtım ilişkisi düz sınıflarla, soyut sınıflarla ya da arayüz kalıtımıyla kurulmuş olsun, her durumda geçerlidir.

Bu derste tersi işlendi: üst tür referansıyla takip edilen bir nesneyi alt sınıf nesnesine çevirmek. Buna tür dönüşümü (typecasting) denir.

### 1.1 UML Diyagramı

Slayttaki örnek bir market rafıdır (ekrandan, 00:20:00):

| Sınıf | Alanlar | Metotlar |
|---|---|---|
| `MarketShelf` | `- items : LinkedList<Item>` | `+ addItem( Item ) : boolean`, `+ doesExist( Item ) : boolean`, `+ printExpiredItems( )` |
| `«interface» Item` | yok | yok |
| `Food` | `- expireDate : Date` | `+ Food( expireDate : Date )`, `+ getExpireDate( ) : Date`, `+ isExpired( ) : boolean` |
| `Electronics` | yok | yok |

İlişkiler:

- `MarketShelf` 1 — * `Item`: rafın `Item` nesneleriyle bire-çok birleşim (composition) ilişkisi vardır.
- `Food` ve `Electronics`, `Item` arayüzünü gerçekler (kesikli çizgi ve içi boş üçgen).
- Slayttaki notlar: `MarketShelf` için "some methods excluding expiration operations", `Electronics` için "electronics do not expire".

`Food` için son kullanma tarihini almak ve süresinin geçip geçmediğini sormak anlamlıdır. Elektronik bir ürün için bu iki metodun anlamı yoktur; bu yüzden `Electronics`'te bulunmazlar.

### 1.2 doesExist ve addItem

`MarketShelf`'in global alanı `private` tanımlı ve `Item` türünde nesneler tutan bir `LinkedList`'tir. Bağlı liste generic bir sınıf olduğu için tür parametresi olarak `Item` yazılır. Kurucu bu listenin örneğini oluşturur.

`doesExist` bir `Item` alır ve liste üzerinde for-each döngüsü kurar. Hoca, for-each döngüsünün her veri yapısında kullanılabildiğini, döngünün veri yapısındaki her elemanı sırayla geçici bir yerel değişkene atadığını hatırlattı. Döngüdeki eleman girdiyle aynıysa `true`, değilse sonunda `false` döner.

`addItem`, bir veri yapısına ekleme yapmadan önce elemanın zaten orada olup olmadığına bakılması gerektiği için önce `doesExist`'i çağırır. Hoca, aynı kontrolü yeniden yazmak yerine sınıfta zaten bulunan metodun kullanılmasını önerdi. Eleman varsa `false` döner; yoksa eleman eklenir ve `true` döner.

<!-- BELİRSİZ: doesExist ve addItem kodunun bulunduğu slayt kareye girmedi; açıklama altyazıdan aktarıldı. -->

### 1.3 printExpiredItems: instanceof ve Tür Dönüşümü

Typecasting'in kullanıldığı metot `printExpiredItems`'tır (ekrandan, 00:25:00):

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

Hoca metodu adım adım anlattı:

- Önce `hasExpiredItem` yerel değişkeni `false` olarak tanımlanır.
- Liste üzerinde for-each döngüsü kurulur. Listedeki her eleman `Item` türünde bir referansla gelir; listede hem `Food` hem `Electronics` nesneleri olabilir, çünkü ikisinin de üst türü `Item`'dır. Döngüde gelen nesnenin hangisi olduğu bilinmez.
- Süresi geçen ürünleri yazdırmak için `Food`'un `isExpired()` metodu çağrılmalıdır. Bu metot `Food`'da vardır, `Electronics`'te yoktur. `Electronics` nesnesinde çağrılırsa sorun çıkar. Bu yüzden önce nesnenin `Food` olduğundan emin olunmalıdır.
- Java'nın bunun için `super` gibi bir anahtar sözcüğü vardır: `instanceof`. Solunda bellekteki nesne, sağında sınıf adı bulunur; nesne o sınıfın örneğiyse `true`, değilse `false` döner.
- `true` ise if bloğuna girilir. Nesne `Food` türündedir, ama şu an `Item` referansıyla takip edilmektedir. Sınıf adı parantez içinde referansın önüne yazılarak (`(Food)item`) tür üst türden alt türe çevrilir. Artık elde aynı nesneyi gösteren `Food` türünde bir referans vardır ve `isExpired()` çağrılabilir.
- `isExpired()` `true` dönerse `hasExpiredItem = true` yapılır ve ürün yazdırılır; sonra sıradaki elemana geçilir.
- Döngü bittiğinde `hasExpiredItem` hâlâ `false` ise hiçbir üründe süre geçmemiştir ve "All items are fresh!" yazdırılır.

Hoca özetle şunu söyledi: alt sınıfın örneği üst sınıfın beklendiği her yerde kullanılabilir; bu, özel bir nesneyi bilgi kaybetmeden daha genel bir türe çevirmektir. Typecasting ile bir tür başka bir türe çevrilebilir: bu örnekte olduğu gibi arayüzden sınıfa, ya da üst sınıftan alt sınıfa.

## 2. Calendar ve Date Sınıfları

Hoca, daha önce `Math`, `Scanner`, `Random`, `Arrays` ve `Collections` gibi, statik metotları programların akışını kurmakta çok kullanılan sınıfları anlattığını hatırlattı. `Calendar` ve `Date` sınıfları da bu kategoridedir.

> **Hocanın vurgusu:** `Calendar` ve `Date` sınıflarının bütün metotları değil, ama sık kullanılan metotları bilinmelidir. Sınavda bu metotların bilindiği varsayılır.

### 2.1 Test Programı

`MarketShelf`'i test eden `main` metodu (ekrandan, 00:35:00):

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

Hoca satırları şöyle açıkladı:

- `Calendar.getInstance()` `Calendar` türünde bir nesne verir; bu nesnede tarih bugünün tarihidir (ders günü için yıl 2021, ay mayıs, gün 27). Nesne `cal` değişkeniyle takip edilir.
- `cal.add(Calendar.DAY_OF_MONTH, 1)` ayın gününü bir artırır; bugünün tarihi yarının tarihine döner (27 → 28; perşembe ise cuma olur).
- `getTime()` takvimdeki tarihi `Date` türünde bir nesne olarak döndürür. Bu nesne `future` ile takip edilir; yılı ve ayı aynı, günü bir sonraki gündür.
- Aynı `cal` nesnesiyle `set` metodu çağrılır: yıl, ay ve gün istenen değerlere ayarlanır; yani takvim geçmiş bir tarihe güncellenir. Ay 0'dan başlar; 0 ocaktır.
- Yeniden `getTime()` çağrılınca geçmiş tarihi taşıyan ikinci bir `Date` nesnesi (`past`) elde edilir. Bu noktada bellekte iki `Date` nesnesi vardır: yarını taşıyan `future` ve 2010'dan bir tarihi taşıyan `past`.
- `Food`'un kurucusu bir `Date` aldığı için rafa önce geçmiş tarihli, sonra gelecek tarihli bir `Food` ve bir `Electronics` eklenir.

> **Ders sonrası not:** Hoca geçmiş tarihin gününü 30 olarak okudu; slaytta `cal.set(Calendar.DATE, 13);` yazar, yani tarih 13 Ocak 2010'dur.

> **Ders sonrası not:** Slaytın son satırındaki `checkForExpiration()` metodu `MarketShelf`'te tanımlı değildir; hoca da bunu belirtti ve bu metodun `printExpiredItems`'tan yararlanarak alıştırma olarak yazılabileceğini söyledi. Bu haliyle kod derlenmez. Ajan son satırı `shelf.printExpiredItems();` yaparak `java` ile çalıştırdı: "Expired item(s):" başlığının altında yalnız 2010 tarihli `Food` yazıldı; gelecek tarihli `Food` ve `Electronics` yazılmadı.

### 2.2 Food Sınıfı

`Food` sınıfı (ekrandan, 00:45:00):

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

`Food`, `Item` arayüzünü gerçekler. Tek global alanı `Date` türündeki `expireDate`'tir; kurucu bu alanı başlatır ve bir getter metodu vardır.

`isExpired()` içinde önce `new Date()` ile bir `Date` nesnesi oluşturulur. Hoca, `Date` nesnesi bu şekilde oluşturulduğunda bugünün tarihini taşıdığını, yıl, ay ve günün ayrıca ayarlanmasına gerek olmadığını vurguladı. Sonra `expireDate.before(today)` ile son kullanma tarihinin bugünden önce olup olmadığına bakılır; önceyse ürünün süresi geçmiştir ve `true`, değilse `false` döner. Hoca, yalnız sınıfların değil `Date` nesnesinin `before` gibi metotlarının da öğrenilmesi gerektiğini söyledi. `toString()` ürünün son kullanma tarihini yazdırır.

## 3. Typecasting'in Eleştirisi ve Tasarımla Önlenmesi

Hoca, typecasting kullanırken hata yapmanın kolay olduğunu, üst türdeki bir nesneyi alt türe çevirmenin kodda izlenmesinin zor olduğunu söyledi. Bu yüzden typecasting yalnız zorunlu olduğunda kullanılır; zorunlu olduğu başlıca yer G/Ç (dosyadan nesne okuma) işlemleridir.

Slayttaki eleştiri (ekrandan, 00:50:00):

- Typecasting "gerekli bir kötülüktür" (necessary evil); az kullanılmalıdır.
  - Java'da generic sınıfların olmadığı dönemde sık sık typecasting yapmak gerekirdi.
  - Bugün yalnız deserialization yaparken gerekir.
- Tasarımlar her zaman typecasting'siz yapılabilir.
- Diğer durumlarda soyut sınıflar ve çok biçimlilikten iyi yararlanılmalı ve alt sınıflarla herhangi bir ilişki kurmaktan kaçınılmalıdır.

Güncellenmiş tasarım:

| Sınıf | Alanlar | Metotlar |
|---|---|---|
| `MarketShelf` | `- items : LinkedList<Item>` | `+ addItem( Item ) : boolean`, `+ doesExist( Item ) : boolean`, `+ printExpiredItems( )` |
| `«interface» Item` | yok | `+ getExpireDate( ) : Date`, `+ isExpired( ) : boolean` |
| `Food` | `- expireDate : Date` | `+ Food( expireDate : Date )` |
| `Electronics` | yok | yok (arayüz metotlarını gerçekler) |

Slayttaki nota göre `Item` bir soyut sınıf da olabilir.

Önceki tasarımda typecasting'in nedeni, `isExpired`'ın yalnız `Food`'a ait olmasıydı; nesne `Food` değilse hata alınırdı. Yeni tasarımda bu iki metot üst türe, yani `Item` arayüzüne taşınmıştır. Arayüzü gerçekleyen her sınıf onun metotlarını gerçeklemek zorunda olduğundan hem `Food` hem `Electronics` `isExpired`'ı içerir. Bu durumda nesne `Item` referansıyla takip edilse bile `isExpired()` doğrudan çağrılabilir. Bazı metotları üst sınıfa taşıyarak typecasting'den kaçınılabilir.

## 4. Dosyalarla Çalışma: İstisnalar ve İki Kategori

Dosyalarla çalışırken bazı istisnalar oluşabilir. `java.io` bunları gerçeklemiştir (ekrandan, 00:55:00):

| İstisna | Anlamı |
|---|---|
| `java.io.IOException` | Genel G/Ç istisnası. |
| `java.io.EOFException extends IOException` | Dosya ya da akışın sonuna beklenmedik biçimde ulaşıldı. |
| `java.io.FileNotFoundException extends IOException` | İstenen dosya verilen yolda bulunamadı. |
| `java.lang.SecurityException extends java.lang.RuntimeException` | İstenen işlem güvenlik kısıtları yüzünden yapılamıyor. |

Hoca checked ve unchecked istisna farkını hatırlattı: Checked istisna fırlatabilen sınıflar ya da metotlar kullanılıyorsa Java derleyicisi bunların try-catch bloğuna konmasını zorunlu kılar; aksi halde kod derlenmez. Unchecked istisnada derleyici sorun çıkarmaz, kod derlenir; ama try-catch konmazsa çalışma sırasında sorunlarla karşılaşılabilir. G/Ç istisnaları checked istisnalardır.

Dosya işlemleri hakkında genel bilgi (ekrandan, 01:05:00):

- Java'da dosya işlemleri iki ana gruba ayrılır:
  - Dosya yönetimi: dosya ve klasör oluşturma, yeniden adlandırma, silme gibi işlemler.
  - G/Ç işlemleri: dosyaya yazma ve dosyadan okuma.
- G/Ç işlemleri yalnız dosyalarla değil, TCP soketleri gibi farklı kaynaklarla da yapılır. Bu yüzden G/Ç işlemleri dosya işlemlerinden ayrılmış ve bütün bu kaynaklar için aynı biçimde kodlanmıştır.
- Bu yaklaşım nesneye yönelik paradigmanın doğasıyla uyumludur; ama yan etki olarak karmaşıklık artmıştır.

Hoca, dosya sisteminde iki tür dosya olduğunu açıkladı: dosyaların konduğu klasör (dosya yönetimi açısından türü klasör olan bir dosya) ve kullanılan bütün dosyalar. Bu iki türü yönetmek için `java.io` paketindeki dosya yönetimi sınıfları kullanılır.

## 5. Dosya Yönetimi: java.io.File

Dosya yönetimi `java.io.File` sınıfıyla kodlanır (ekrandan, 01:00:00):

- `File` sınıfı sabit diskteki hem dosyaları hem klasörleri temsil eder.
- `File` nesnesi oluşturmak gerçek bir dosya ya da klasör oluşturmak demek değildir.
- `File` nesnesi `File( String fileName )` kurucusuyla oluşturulur.
  - `fileName` hem yolu hem dosya ya da klasörün adını içermelidir.
  - Tam yol ile göreli yol: tam yol kullanmak taşınabilirliği azaltır; göreli yol da zordur, çünkü IDE'ler kaynak ve class dosyalarını farklı klasörlerde tutabilir.
  - Yol ayırıcı: Windows `\` kullanır (string içinde `\\` olarak yazılmalıdır), Unix `/` kullanır.
- `File( String path, String name )` kurucusu: `path` parametresiyle verilen klasördeki, verilen adlı dosya ya da klasörü temsil eder. Yol ve ad ayrı verilir.

Hocanın anlattığı metotlar (altyazıdan; slayt kareye girmedi):

- `exists`: dosya var mı?
- `isFile`: nesne bir dosya mı, yoksa klasör mü?
- `getParentFile`: dosya ya da klasörün bulunduğu üst klasörü bir `File` nesnesi olarak döndürür.
- `getCanonicalPath`: dosya ya da klasörün tam yolunu döndürür.
- `canRead`, `canWrite`: dosyadan okunabilir mi, dosyaya yazılabilir mi? `true` ya da `false` döner.
- `createNewFile`: `File` nesnesinin temsil ettiği dosyayı dosya sisteminde gerçekten oluşturur.
- `mkdir`: nesne için bir klasör oluşturur.
- `mkdirs`: nesnenin yolundaki bütün klasör hiyerarşisini oluşturur. Hocanın örneği: masaüstünün altında bir ders klasörü, onun altında bir dosya yönetimi klasörü ve onun altında bir klasör içeren bir yol verilip `mkdirs` çağrılırsa yoldaki her klasör sırayla oluşturulur.
- `renameTo`: var olan bir dosyanın adını değiştirir.
- `delete`: dosya sistemindeki bir dosyayı siler.

Hoca bu metotların ders sayfasında paylaşılan kodlardaki dosya örneğiyle çalışılmasını istedi; derste ağırlık, daha önemli olduğu için G/Ç kategorisine verildi.

## 6. G/Ç İşlemleri: İkili ve Metin Dosyaları, Akışlar

Dosya sisteminde iki dış veri biçimi vardır:

- İkili (binary) dosyalar ham baytlar içerir. Not Defteri gibi metin tabanlı bir uygulamayla açıldığında içerik okunamaz.
- Metin dosyalarının ASCII, UTF-8, UTF-16 gibi farklı kodlamaları vardır.

`java.io` paketi hem metin hem ikili dosyaları okuyup yazabilen sınıflar sağlar. Bu dış biçim, dosya sisteminde görülen biçimdir. Java programının içindeki iç biçim ise ilkel veri türleridir; metin için karakter türü kullanılabilir. Hoca, bir karakterin 16 bit, bir baytın 8 bit olduğunu söyledi.

Derste ikili dosyalara odaklanıldı ve bayt akışı tabanlı G/Ç sınıfları işlendi: `InputStream` ve `OutputStream` sınıfları. Slayttaki çizimde (ekrandan, 01:10:00) üstte bir kaynaktan (source) programa doğru, altta programdan bir hedefe (sink) doğru, üzerinde 0 ve 1 bitleri taşıyan birer akış (stream) gösterilir.

Hoca şöyle anlattı: dosya sistemindeki bir dosyadan veri bayt bayt okunur ve bir nesne oluşturmak için gereken bütün baytlar gelince programda bu nesne oluşturulur. Tersine, bir nesne dosyaya yazılırken nesne baytlara çevrilir ve bu baytlar dosyaya aktarılır. `InputStream` sınıfları dosyadan okumak, `OutputStream` sınıfları dosyaya yazmak içindir. Nesne okuma ve yazma için her kategoriden ikişer sınıf kullanılır: okumak için `ObjectInputStream` ve `FileInputStream`, yazmak için `FileOutputStream` ve `ObjectOutputStream`.

## 7. Akışları Zincirleme: Nesne Okuma ve Yazma

Bir nesneyi dosyaya yazmak ya da dosyadan okumak için bu sınıflar birbirine zincirlenerek kullanılır (ekrandan, 01:25:00). Slayttaki çizimde diskteki dosyadan `FileInputStream` ile bayt bayt, `ObjectInputStream` ile bayt blokları (buffer) hâlinde Java programına doğru akış gösterilir.

```java
ObjectInputStream reader = new ObjectInputStream(
                           new FileInputStream( fileName ) );
Integer recordNumber = (Integer)reader.readObject();

ObjectOutputStream writer = new ObjectOutputStream(
                           new FileOutputStream( filename) );
writer.writeObject( recordNumber );
```

### 7.1 Okuma

- Önce `FileInputStream` nesnesi oluşturulur ve dosya adı verilir. Ad bir yol içerebilir; aynı klasördeki bir dosya okunacaksa yalnız dosya adı yeterlidir. Yol verilmezse Java sanal makinesi dosyayı aynı klasörde arar; başka bir klasördeki dosya için ad yolla birlikte verilmelidir.
- Bu nesne `ObjectInputStream`'in kurucusuna girdi olarak verilir; iki nesne böylece zincirlenir.
- Elde edilen `ObjectInputStream` (`reader`) ile dosyadaki nesneler alınır. Bu sınıfın en önemli metodu `readObject`'tir.

Zincirlemenin nedeni: `FileInputStream` dosyadan baytları hangi nesneyi oluşturduğunu bilmeden bayt bayt okuyup programa gönderir. `ObjectInputStream` gelen baytları bekletir ve bir nesneyi oluşturacak kadar bayt gelince nesneyi oluşturup programa verir.

`readObject` `java.lang.Object` türünde bir nesne döndürür. Hoca, `Object` sınıfının bütün Java sınıflarının kök üst sınıfı olduğunu hatırlattı. Dönen nesnenin, okunan nesne hangi türdeyse o türe dönüştürülmesi gerekir. Dosyayı yazan da okuyan da aynı programcı olduğu için ne yazıldığı bilinir; örneğin bir `Integer` yazıldıysa `Integer` sarmalayıcı sınıfına dönüştürülür ve artık programda kullanılabilir.

### 7.2 Yazma

- Önce bir `FileOutputStream` nesnesi oluşturulur, sonra `ObjectOutputStream`'in kurucusuna girdi olarak verilir; elde edilen nesne `writer` ile takip edilir.
- `ObjectOutputStream`'in `writeObject` metoduna dosyaya yazılacak nesne verilir.
- Bu kez okuma çiziminin tersi gerçekleşir: `ObjectOutputStream` nesneyi baytlara dönüştürür, `FileOutputStream` bu baytları bayt bayt diske yazar.

## 8. Serileştirme ve Serializable Arayüzü

Bir nesne dosyaya yazılırken baytlara dönüştürülür; bütün nesnelerin dosyaya yazılmasına serileştirme (serialization) denir. Slayttaki maddeler (ekrandan, 01:30:00):

- Bütün nesneler diskteki bir dosyaya yazılacak.
- Serileştirilecek nesnelerin sınıfları `java.io.Serializable` arayüzünü gerçeklemelidir.
- `java.io.Serializable` arayüzünün hiç metodu olmadığı için başka bir şey yapmak gerekmez.
- Serileştirme için `ObjectOutputStream` ve `FileOutputStream` nesneleri zincirlenir.
- Aynı akışa birden çok nesne gönderilebilir ve gönderilmelidir.

> **Hocanın vurgusu:** Bir nesnenin dosyaya yazılacağı bilindiği anda o nesnenin sınıfının `Serializable` arayüzünü gerçeklemesi gerektiği düşünülmelidir. Sınav sorusunda yalnız nesnenin dosyaya yazılacağı belirtilir ve sınıfın kaynak kodu istenir; `Serializable` ayrıca söylenmez, bunun bilinmesi beklenir. Bu, sınavda genelde yapılan bir hatadır.

`Serializable` gerçeklendiğinde kodda bir `serialVersionUID` tanımlanmalıdır; tanımlanmazsa Java derleyicisi uyarı verir. Bunun nedeni, kullanılan sınıfların zamanla farklı sürümlerinin oluşabilmesidir: sınıfa yeni bir alan ya da metot eklenebilir. Dosyaya yazılan nesnelerin hangi sınıf sürümünün nesnesi olduğunu izlemek için `private static final long serialVersionUID` global alanlar arasında tanımlanır.

> **Ek bilgi (derste anlatılmadı):** `serialVersionUID` tanımlanmazsa JVM sınıfın yapısından bir değer hesaplar. Sınıf değiştirildikten sonra eski bir dosya okunmaya çalışılırsa bu değer büyük olasılıkla tutmaz ve `InvalidClassException` oluşur. Değer elle sabitlenirse uyumlu değişikliklerden sonra eski dosyalar okunmaya devam edebilir.

Örnekteki `Arkadas` sınıfı `Serializable`'ı gerçekler; bu, `Arkadas` nesnelerinin dosyaya yazılabileceği anlamına gelir. Sınıfta hepsi `String` türünde üç global alan (ad, telefon, e-posta), bir kurucu, bütün alanlar için getter metotları, telefon ve e-posta için setter metotları ve bir `toString` metodu vardır. Ad kurucuda verildiği için onun setter'ı yazılmamıştır.

<!-- BELİRSİZ: Arkadas sınıfının kodunu içeren slayt kareye girmedi; alan ve metot listesi altyazıdan aktarıldı. -->

## 9. Annotation'lar ve @SuppressWarnings

Hoca, metotların bir satır üstüne yazılan annotation'ları hatırlattı. Kodun uyarı vereceği bilinerek bilinçli olarak öyle yazılıyorsa bu uyarıları göstermemek ya da kodla ilgili bilgi eklemek için `@` ile başlayan annotation'lar kullanılır.

Slayttaki açıklama (ekrandan, 01:35:00):

- `@` ile başlayan satırlar "annotation" denen özel komutlardır.
- "Meta" düzeyde çalışırlar, yani "bilgi hakkında bilgi" içerirler.
- IDE'ye, derleyiciye, başka bir programa vb. bu program hakkında bilgi verirler.
- Annotation mekanizması uyarıları kaldırmak için kullanılmıştır.
- Aslında uyarılar dikkate alınmalıdır. Önceki örneklerde bu uyarılar annotation'larla kapatılmıştır.
- Yukarıdaki örnekte, uyarı doğrudan konuyla ilgili olduğu için annotation kullanılmamıştır.

Bir örnek `@SuppressWarnings`'tir: parantez içine hangi durum için uyarı verilmemesi isteniyorsa o yazılır. `serialVersionUID` satırı yazılmadığında uyarı alınacağı bilinir; bu uyarıyı almamak için sınıfın üstüne `@SuppressWarnings("serial")` yazılır.

> **Hocanın vurgusu:** Annotation kullanımıyla da sınavda karşılaşılabilir.

## 10. Arkadas Örneği: Diziyle Yazma ve Okuma

### 10.1 ArkadasOlustur: Verilerin Alınması

`ArkadasOlustur` sınıfının `main` metodunda:

- `Integer` sarmalayıcı türünde bir arkadaş sayısı ve `Arkadas` türünde bir dizi (`arkadaslar`) tanımlanır.
- `Scanner` ile kullanıcıdan kaç arkadaş bilgisi gireceği alınır ve bu sayı arkadaş sayısına atanır.
- Bu boyutta bir `Arkadas` dizisi oluşturulur.
- Bir for döngüsünde her kişi için bilgiler kullanıcıdan alınır: ad kurucuya verilerek yeni bir `Arkadas` oluşturulur ve dizinin ilgili hücresine atanır; sonra bu hücredeki referans kullanılarak `setTelefon` ve `setEposta` çağrılır.

Böylece dizi, kullanıcıdan alınan verilerle oluşturulmuş bütün `Arkadas` nesnelerini içerir.

<!-- BELİRSİZ: ArkadasOlustur'un veri alma bölümünü içeren slayt kareye girmedi; akış altyazıdan aktarıldı. -->

### 10.2 Dosyaya Yazma (Serileştirme)

Yazma bölümü (ekrandan, 01:40:00):

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

- Önce dosya adı bir `String` değişkene atanır.
- `FileOutputStream` dosya adıyla oluşturulur ve `ObjectOutputStream`'in kurucusuna verilir; sonuç `yazici` ile takip edilir.
- Dosyaya konan ilk nesne, kaç arkadaş yazılacağını tutan `Integer` nesnesidir.
- Sonra for-each döngüsüyle dizideki her arkadaş `writeObject` ile yazılır. Döngü bitince dosyanın ilk nesnesi bir `Integer`, sonraki bütün nesneler `Arkadas` olur.
- Dosyayla iş bitince akış mutlaka `close()` ile kapatılır.
- Bu işlemler checked istisna fırlattığı için try-catch içinde olmalıdır; aksi halde derleyici kodu derlemez. `IOException` oluşursa catch bloğu çalışır ve kayıt sırasında hata oluştuğu yazdırılır.

### 10.3 Dosyadan Okuma (Deserialization)

Okuma `ArkadasGoster` sınıfıyla yapılır (ekrandan, 01:45:00):

```java
import java.io.*;

public class ArkadasGoster {
  public static void main( String[] args ) {
    String dosyaAdi = "arkadaslar.dat";
    try {
        ObjectInputStream okuyucu = new ObjectInputStream(
                        new FileInputStream( dosyaAdi ) );
        Integer kayitSayisi = (Integer)okuyucu.readObject();
        for( int i = 0; i < kayitSayisi; i++ ) {
            Arkadas arkadas = (Arkadas) okuyucu.readObject();
            System.out.println(arkadas);
        }
        okuyucu.close();
    }
```

Catch blokları (ekrandan, 01:55:00):

```java
    catch( IOException e ) {
        System.out.println("Dosya okuma işlemleri sırasında" +
                " bir hata oluştu.");
        e.printStackTrace();
    }
    catch( ClassNotFoundException e ) {
        System.out.println("Okunan kayıtları işlerken " +
                "bir hata oluştu.");
        e.printStackTrace();
    }
  }
}
```

- Okunacak dosyanın adı bir yerel değişkene konur; `FileInputStream` ve `ObjectInputStream` zincirlenir ve sonuç `okuyucu` ile takip edilir.
- `readObject` `Object` döndürdüğü için dönüşüm gerekir. Dosyayı aynı programcı yazdığı için ilk nesnenin `Integer` olduğu bilinir; ona dönüştürülür ve dosyanın geri kalanındaki nesne sayısı (`kayitSayisi`) elde edilir.
- 0'dan başlayıp bu sayı kadar dönen bir for döngüsünde nesneler teker teker okunur; geri kalanların `Arkadas` olduğu bilindiği için `Arkadas`'a dönüştürülür ve yazdırılır.
- Okuma bitince `ObjectInputStream` kapatılır. Hoca, giriş ya da çıkış fark etmeksizin akış sınıflarıyla iş bitince mutlaka `close()` çağrılması gerektiğini vurguladı.

Okumada iki tür hata oluşabilir: dosyayı okuma sırasında oluşan ve `IOException` ile yakalanan hata, ve okunan baytların beklenen sınıfa dönüştürülmesi sırasında oluşan hata. Hoca ikincisi için `ClassNotFoundException`'ı gösterdi: dönüştürülmek istenen sınıf bulunamazsa, yani okunan kayıt beklenen kayıt değilse bu istisna oluşur.

> **Hocanın vurgusu:** Okumada iki farklı istisna oluşabilir ve ikisi de catch bloklarında doğru biçimde yakalanmalıdır. Bu da sınavda karşılaşılabilecek bir soru tipidir; durum metin olarak verilebilir.

> **Ders sonrası not:** `ClassNotFoundException`, `readObject` sırasında dosyadaki nesnenin sınıfı JVM'de bulunamadığında fırlatılır ve checked olduğu için yakalanmak zorundadır. Okunan nesnenin sınıfı bulunup da beklenenden farklı bir türe dönüştürülmeye çalışılırsa unchecked `ClassCastException` oluşur.

Ajan, `Arkadas` sınıfının küçük bir sürümüyle dizi sürümünü `java` ile çalıştırdı: önce sayı, sonra nesneler yazıldı ve aynı sırayla geri okundu.

## 11. Dosya Sonu Sorunu ve Veri Yapısını Yazma

`ObjectInputStream`'in `readObject` metodu nesne okur, ama dosyanın sonuna gelindiğini izlemeyi sağlayan, `hasNext` gibi bir metot yoktur. Slayttaki açıklama (ekrandan, 01:50:00):

- `int ObjectInputStream.available()` diye bir metot vardır, ama biraz hatalıdır (slaytta bir forum bağlantısı verilir).
- Üstelik `readObject()` dosya sonunda `null` döndürmez.
- İstisnanın oluşmasına izin verip döngüyü catch bloğunda bitirerek bir çözüm yazılabilir.
  - Ama istisna yönetimi program akışını değiştirmek için icat edilmemiştir.
- Veri nesnelerinin sayısını önceden yazmaya daha iyi bir seçenek, bütün veri nesnelerine referans tutan tek bir kap (container) nesnesi kullanmaktır.
  - Bu kap nesnesi liste ya da map gibi bir veri yapısı olur.
    - Ancak kaptaki nesneler `java.io.Serializable` arayüzünü gerçeklemelidir.
  - A→B ilişkisi varsa hem A hem B `java.io.Serializable` arayüzünü gerçeklemelidir.

Hoca iki yöntemi özetledi: dosyanın başına kaç nesne konduğunu belirten bir `Integer` yazmak ya da bağlı listedeki her elemanı ayrı nesne olarak yazmak yerine bağlı listenin tamamını tek nesne olarak yazmak.

### 11.1 Bağlı Liste Sürümü

Aynı `ArkadasOlustur` örneği bu kez dizi yerine bir veri yapısıyla, önceden sayı yazmadan yapılır:

- Önce bir bağlı liste oluşturulur. `Arkadas` nesneleri tutacağı için tür parametresi olarak `Arkadas` belirtilmelidir.
- Önceki örnekteki gibi `Scanner` ile kaç arkadaş oluşturulacağı alınır; for döngüsünde her arkadaşın bilgileri alınır, nesne oluşturulur ve listenin `add` metoduyla eklenir.
- Bir dosya adı tanımlanır, `FileOutputStream` ile `ObjectOutputStream` zincirlenir ve `yazici` ile takip edilir.
- `writeObject`'e listenin tamamı verilir. Java sanal makinesi listeyi ve içindeki bütün nesneleri dosyaya yazar. Sonra akış kapatılır; oluşabilecek `IOException` catch bloğunda yakalanır.

> **Hocanın vurgusu:** Sık yapılan bir hata: bağlı listenin nesnesi oluşturulurken tür parametresi olarak `Arkadas` yazılıp bu nesneyi takip eden değişkenin tanımında yazılmaması. Tanımda ve oluşturmada aynısı kullanılmalıdır; aksi puan kaybettirir.

Okumada:

- Okunacak dosyanın adı verilir, `FileInputStream` ile `ObjectInputStream` zincirlenir.
- Tek bir `readObject` ile dosyadaki nesne okunur. Bu nesne, içinde `Arkadas` nesneleri tutan bir bağlı listedir; dönüştürülüp yerel `LinkedList` değişkenine atanır.
- For-each ile liste gezilir ve bütün arkadaşlar yazdırılır.
- Bu yöntemde kaç nesne olduğunu önceden yazmaya gerek yoktur, çünkü veri yapısının tamamı yazılır. Tek koşul, yapıda tutulan nesnelerin sınıfının `Serializable`'ı gerçeklemesidir.
- Okumada yine iki hata türüyle karşılaşılabilir: dosyadan okuma için `IOException` ve okunan baytları bağlı liste nesnesine dönüştürürken oluşabilecek hata için `ClassNotFoundException`. Yazmada yalnız `IOException` kullanılmıştı; okumada ayrıca baytlar bir Java sınıfına dönüştürüldüğü için iki istisna vardır.

Ajan bu sürümü de küçük bir örnekle `java` ile çalıştırdı: iki elemanlı bir `LinkedList<Arkadas>` tek `writeObject` ile yazıldı ve tek `readObject` ile aynı sırayla geri okundu.

> **Ek bilgi (derste anlatılmadı):** `(LinkedList<Arkadas>) okuyucu.readObject()` dönüşümünde derleyici, tür parametresini çalışma zamanında denetleyemediği için bir "unchecked" uyarısı verir. Bu uyarı büyük olasılıkla `@SuppressWarnings("unchecked")` ile bastırılır.

## 12. Akışlar ve Annotation'lar Üzerine Soru-Cevap

**Soru:** Akışların en sonda kapatılması gerektiği söylendi. Ama `FileInputStream` ya da `FileOutputStream` kurucuya argüman olarak verildi ve elde onun bir değişkeni yok. Onu kapatabiliyor muyuz, otomatik mi kapanıyor?

**Cevap:** İki akış birbirine zincirlendiği için dıştaki, kapsayıcı akış kapatıldığında içteki de kapanır. Kapsayıcı nesne `ObjectInputStream`'dir; içindeki `FileInputStream`'in açılıp kapanmasını o yönetir. Programda yalnız `ObjectInputStream`'e `close()` çağrılır; o da kapanmadan önce kendisine bağlı olarak oluşturulmuş `FileInputStream`'i kapatır. Aynısı `ObjectOutputStream` ve `FileOutputStream` için de geçerlidir.

**Soru:** `@SuppressWarnings` için `resource`, `serial`, `unchecked` gibi değerler görüldü. Bunların hepsi tek tek bilinmeli mi, ne zaman hangisi kullanılır?

**Cevap:** Ders kapsamında görülen değerleri bilmek yeterlidir; yaygın kullanılanlar da bunlardır. `serial` seri numarası (serialVersionUID) satırı için kullanılır. `unused` da vardır: bir sınıfta yazılan metotlar `main`'de hiç çağrılmamışsa derleyici kullanılmayan metot uyarısı verebilir; bu uyarı istenmiyorsa üstüne `@SuppressWarnings("unused")` yazılır. Sınav için üç dört farklı değeri bilmek yeterlidir; zamanla kod yazdıkça başka uyarılarla da karşılaşılacaktır.

> **Ders sonrası not:** Hoca `unchecked` değerinin istisna yönetimi için kullanıldığını söyledi. `unchecked`, unchecked istisnalarla değil, derleyicinin denetleyemediği generic tür dönüşümleri ve ham tür (raw type) kullanımıyla ilgili uyarıları bastırır.

## 13. İç Sınıflar (Inner Classes)

Şimdiye kadar sınıfların adları vardı ve programın mantık akışının gerektirdiği işler, bu sınıflardan oluşturulan nesneler ve aralarındaki ilişkiler kullanılarak yapılıyordu. Normalde bir sınıfın çok sayıda nesnesi oluşturulur. Ama bazı durumlarda bir sınıfın nesnesine yalnız bir kez ihtiyaç duyulur ve sınıf bir daha kullanılmaz. Bu tür durumlarda iç sınıf kullanılır.

İç sınıf, bir dış sınıfın (outer class) içinde tanımlanan sınıftır. Normalde `public class` ile sınıf süslü parantezler arasında tanımlanırdı; bu kez böyle tanımlanmış bir sınıfın içinde bir alt sınıf tanımlanır. İç sınıfın bütün metotları dış sınıfın metotlarına ve alanlarına erişebilir.

### 13.1 main Dış Sınıfın İçinde

Slayttaki örnek (ekrandan, 02:15:00):

```java
package oop05b;
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
        kisi = new Person("Person-1");
        staff[0] = kisi.new Employee( 10000 );
        kisi = new Person("Person-2");
        staff[1] = kisi.new Employee( 7500 );
        kisi = new Person("Person-3");
        staff[2] = kisi.new Employee( 6000 );
        for( Employee eleman: staff )
            System.out.println( eleman );
    }
}
```

- Dış sınıf `Person`, iç sınıf `Employee`'dir. `Employee` `private` tanımlanmıştır; `public` de tanımlanabilirdi.
- `Employee`'nin `toString()` metodu dış sınıfın `name` alanını kullanır.
- `main` metodu dış sınıfın bir metodu olduğu için iç sınıfı görebilir; bu yüzden `Employee` türünde değişken ve dizi oluşturabilir.
- `Employee[] staff = new Employee[3];` satırı henüz `Employee` nesnesi oluşturmaz; yalnız üç `Employee` nesnesi tutacak bir dizi oluşturur.
- Sonra `Person` türünde bir yerel değişken tanımlanır, bir `Person` nesnesi oluşturulup ona atanır.
- `kisi.new Employee( 10000 )`: iç sınıfın nesnesi dış sınıfın nesnesi üzerinden oluşturulur. İç sınıf dış sınıfın içinde olduğu için ona ulaşmak için önce dış sınıfın bir nesnesi gerekir.
- Aynısı ikinci ve üçüncü kişi için yapılır; sonra for-each döngüsüyle bütün elemanlar yazdırılır.

Ajan bu kodu `java` ile çalıştırdı; çıktı:

```text
Person-1 10000
Person-2 7500
Person-3 6000
```

### 13.2 main Başka Bir Sınıfta: public İç Sınıf ve import

Sonra hoca aynı kodu, `main` metodu dış sınıftan çıkarılıp ayrı bir sınıfa (`TestInnerClassDirectly`) konmuş haliyle gösterdi (ekrandan, 02:20:00). Bu sürümde (`nyp13b` paketi) `Employee` iç sınıfı `public class Employee` olarak tanımlanmıştır.

- Test sınıfı aynı paket altında olsa bile `Person`'ın altında `Employee` adında bir iç sınıf bulunduğu `import` ifadesiyle belirtilmelidir. Bu belirtilmezse kodda `Employee` yazıldığında derleyici onun hangi sınıf olduğunu tanıyamaz; çünkü iç sınıf `Person`'ın bir parçasıdır.
- İç sınıf `public` olduğu için başka bir sınıftan `Person`'ın altındaki `Employee` görülebilir; `import` verilmişse bu türde nesne ve dizi oluşturulabilir.
- İç sınıf `private` olsaydı `import` konmuş olsa bile başka bir sınıf `Person`'ın içinde `Employee` olup olmadığını göremezdi; `import` ifadesi bile hata verirdi. Hoca, `private` bir üyeyi yalnız aynı sınıftaki metotların görebildiğini, sınıf dışındakilerin onun varlığından habersiz olduğunu hatırlattı; iç sınıf için de aynısı geçerlidir.

### 13.3 private İç Sınıf ve Dış Sınıfın public Metodu

İç sınıf `private` iken başka bir sınıftan onun nesnesini oluşturmak için dış sınıfın `public` metotları kullanılır (`TestInnerClassViaOuterClass` örneği):

- `Person`'a erişim belirleyicisi `public` olan bir `enlist` metodu eklenir. `public` metotlar `Person` dışındaki sınıflarca da görülebilir.
- `enlist` içinde bir `Employee` nesnesi oluşturulur ve kurucusuna maaş gönderilir. Yani `enlist`'i çağıran aslında bir `Employee` nesnesi oluşturmuş olur.
- Test sınıfında artık `Employee` türünde dizi oluşturulamaz, çünkü böyle bir iç sınıfın varlığı bilinmez. Bunun yerine `Person` türünde bir dizi oluşturulur; her yeni `Person` nesnesi için `enlist` çağrılır ve her birinin içinde bir `Employee` nesnesi oluşur. Sonra `Person` nesneleri yazdırılır.

<!-- BELİRSİZ: enlist metodunu ve TestInnerClassViaOuterClass sınıfını gösteren kod kareye girmedi; ayrıntılar altyazıdan aktarıldı. -->

Hoca üç durumu şöyle özetledi:

- İlk örnekte `Employee` `private` idi, ama `main` aynı sınıfta olduğu için `Employee` türü görülebildi ve dizisi oluşturulabildi.
- İkinci örnekte `main` dışarı çıkarıldı ve `Employee` `public` yapıldı; `Employee` `Person`'ın altında görülebiliyordu, ama bunun için `import` ifadesi gerekti.
- Üçüncü örnekte `Employee` `private` yapıldı; `Person` dışında başka bir sınıfın onu görmesi imkansızdı. Nesneleri `Person`'a eklenen `public` bir metotla oluşturuldu.

### 13.4 @SuppressWarnings("unused")

Örnekte `private` iç sınıfın üstüne `@SuppressWarnings("unused")` konur. İç sınıf `private` tanımlandığı için dış sınıfın dışındaki hiçbir sınıf onu göremez; derleyici, içinde kullanılmadığını düşündüğü bu sınıf için kullanılmıyor uyarısı verir. Programcı onu bilinçli olarak böyle gerçeklemiş ve kullanacağını biliyorsa bu uyarıyı bastırır.

### 13.5 Soru-Cevap

**Soru:** Bu yapılan aslında `Person` sınıfını alt sınıflara parçalamak gibi bir şey değil mi? `Employee` özelliklerini başka bir sınıfta tutuyor gibi.

**Cevap:** Bu örnekte iç sınıfın bütün alanları dış sınıfa konabilirdi ya da bir kalıtım ilişkisi kurulabilirdi; daha önce `Person`'dan `Employee`, `Employee`'den de bir yönetici sınıfı türetilmişti. İç sınıf kullanmanın mantığı şudur: bir sınıfın nesnesi çok yerde değil, tek bir amaçla oluşturulacaksa iç sınıf kullanılır. Kişinin maaşı ve adı gibi bilgiler tutulacaksa bu iç sınıf olmadan da yapılabilirdi. Parçalara bölmek isteniyorsa hocanın önerisi kalıtım yapısıdır. Bu örnek, tercih edilecek bir tasarım olduğu için değil, iç sınıf kullanımına örnek vermek için böyle kurulmuştur. İç sınıf `private` ise onu yalnız aynı sınıfın diğer metotları görür; başka bir sınıfın görmesi isteniyorsa `public` tanımlanmalıdır.

## 14. Contact Örneği ve Veri Yapısı Seçimi

İç sınıflardan sonra hoca, G/Ç akışlarıyla ilgili Eclipse'teki bir örneği daha gösterdi. Paket listesinde `Contact.java`, `CreateContacts.java` ve `ShowContacts.java` dosyaları iki pakette yer alır (ekrandan, 02:20:00).

- `Contact` sınıfı, `Arkadas` sınıfına benzer. Nesneleri dosyaya yazılacağı için `Serializable` arayüzünü gerçekler ve `static final long` bir `serialVersionUID` belirtir. Üç global alanı (ad, telefon, e-posta), getter'ları, setter'ları ve bir `toString`'i vardır.
- `CreateContacts`'ın `main`'i kullanıcıdan kaç kişi oluşturulacağını alır, o boyutta bir `Contact` dizisi oluşturur ve döngüde her kişinin verilerini alarak nesneleri dizinin hücrelerine yerleştirir.
- Bir dosya adı tanımlanır, `FileOutputStream` ile `ObjectOutputStream` zincirlenir. İlk olarak kişi sayısı `Integer` sarmalayıcı nesnesi olarak, sonra for-each ile bütün kişiler `writeObject` ile yazılır ve akış kapatılır. Çıkış akışı olduğu için yalnız `IOException` yakalanır.
- Okumada dosya adı tanımlanır, akışlar zincirlenir, ilk `readObject` sonucu `Integer`'a dönüştürülerek kişi sayısı bulunur. Bu sayı kadar dönen döngüde her `readObject` sonucu `Contact`'a dönüştürülür ve yazdırılır; sonra akış kapatılır. Giriş akışı olduğu için iki hata yakalanır: veriyi okurken `IOException`, dönüşüm sırasında oluşabilecek hata.
- İkinci sürüm aynı örneği bağlı listeyle yapar: bütün veri listeye konur, sayıyı önceden yazmak yerine listenin tamamı tek nesne olarak yazılır ve okunurken liste olduğu gibi alınıp içindeki nesneler teker teker yazdırılır.

Böylece bir dizi sürümü ve bir veri yapısı sürümü görülmüş olur.

> **Hocanın vurgusu:** Sınavda bağlı liste yerine örneğin `HashMap` ya da `ArrayList` kullanılıp yapıdaki bütün nesnelerin dosyaya yazılması istenebilir. Hangi veri yapısı kullanılırsa kullanılsın, içine konacak nesnelerin sınıfı `Serializable` arayüzünü gerçeklemelidir; bu unutulursa puan gider.

## 15. Çoklu İş Parçacığına Giriş: Süreç, Çekirdek ve Durumlar

Bugün çalışılan makinelerin, hatta telefonların neredeyse tamamında birden çok işlemci, her işlemcide de birden çok çekirdek (core) vardır. Bu çok çekirdekli makineler eş zamanlı olarak birden çok süreç (process) çalıştırmaya olanak verir.

Bir program çalıştırıldığında bellekte süreç adını alır; işletim sistemi artık ona program değil süreç der. Bir sürecin CPU üzerinde çalışabilmesi için işletim sistemi önce sürecin komutlarını, kullandığı global alanları ve ihtiyaç duyduğu bellek alanını fiziksel bellekte ayırır ve süreci yaşam döngüsü boyunca takip eder.

Süreç ilk oluşturulduğunda tek iş parçacıklıdır (single-threaded); yalnız bir çekirdek üzerinde çalışır. Örneğin makinede dört çekirdek, yani komutları çalıştırabilen dört hesaplama birimi varsa, program tek iş parçacıklıysa dört çekirdek olmasına rağmen işletim sistemi onu yalnız birinde çalıştırır. Program içinde birden çok iş parçacığı (thread) oluşturulursa program çok iş parçacıklı (multi-threaded) olur. Örneğin programın kendisine ek olarak üç iş parçacığı daha oluşturulursa süreçte dört iş parçacığı olur; dört çekirdek varsa her çekirdekte bir iş parçacığı çalışabilir. Programa çok iş yaptırılmak ve çok çekirdekli donanımdan yararlanılmak isteniyorsa kod çok iş parçacıklı yazılır. Java bunun için paketler sağlar.

### 15.1 Durumlar

Hoca bir sürecin ve iş parçacığının durumlarını şöyle anlattı:

```text
new        : Masaüstündeki çalıştırılabilir bir uygulamaya çift tıklanınca,
             işletim sistemi onu süreç haline getirmek için gereken işlemleri yapar.
runnable   : Süreç çekirdekte çalıştırılmaya hazır olunca bu etiketi alır ve
             bir kuyruğa konur. Zamanlayıcı (scheduler) öndekini alıp boş bir
             çekirdeğe verir.
blocked    : sleep, wait ya da join çağrılınca iş parçacığı CPU'dan alınır ve
             ayrı bir kuyruğa konur. notify / notifyAll ile yeniden runnable
             kuyruğuna döner.
dead       : İş parçacığının yapması gereken her şey bitince işletim sistemi
             etiketini değiştirir, onu yok eder ve ayırdığı kaynakları bırakır.
```

- Program çok iş parçacıklı yazılmışsa ve süreçte dört iş parçacığı varsa her biri runnable kuyruğunda ayrı bir iş (iş parçacığı) olarak yer alır; zamanlayıcı her birini boşta duran bir çekirdeğe atar. Dört çekirdek ve dört iş parçacığı varsa her biri ayrı çekirdekte çalışır.
- İşletim sistemi iş parçacıklarına belirli bir zaman dilimi (time slice) verir; örneğin 5 milisaniye. Bir iş parçacığı çekirdeğe atanır, 5 milisaniye çalışır ve yeniden runnable kuyruğuna döner. Bütün süreçler round robin sırasıyla, toplamda çalışmaları gereken süre kadar çalıştırılır.
- Program mantığı iş parçacığını bir süre bekletmeyi gerektiriyorsa onu bir for döngüsünde sürekli CPU harcatmak yerine `sleep`, `wait` ya da `join` gibi metotlarla blocked durumuna almak gerekir.

> **Ders sonrası not:** Hoca `wait`, `notify` ve `notifyAll`'u `Thread` sınıfının sağladığı metotlar olarak andı. Bu üç metot aslında `java.lang.Object` sınıfında tanımlıdır ve her nesnede bulunur; `sleep` ve `join` ise `Thread` sınıfının metotlarıdır.

## 16. Runnable, Thread ve SoccerFan Örneği

Bir kodu çok iş parçacıklı hale getirmek için o kodu içeren sınıfa `Runnable` arayüzü gerçekletilir. `Runnable`, Java'nın çoklu iş parçacığı kütüphanesinin sağladığı bir arayüzdür. Arayüzdeki bütün metotlar onu gerçekleyen sınıfta bulunmak zorunda olduğundan sınıf `run()` metodunu gerçeklemek zorundadır.

`run()` çalıştırmak için `Thread` sınıfı kullanılır:

- `Thread` türünde bir değişken tanımlanır.
- `Thread` nesnesi oluşturulurken kurucuya, iş parçacığına dönüştürülmek istenen sınıfın (örnekte `SoccerFan`) nesnesi verilir.
- `start()` çağrılınca `Thread` içine gömülü `Runnable` nesnesinin `run()` metodu çalıştırılır.

Hoca, `run()`'ın bir `main` metodu gibi düşünülebileceğini söyledi: `main` komut satırından Java sanal makinesi komutuyla dışarıdan çalıştırılır; `run()` ise dışarıdan `start()` ile çalıştırılır.

### 16.1 SoccerFan Sınıfı

`SoccerFan` bir futbol taraftarını temsil eder: 10 kez, her adım arasında 0 ile 1000 milisaniye arasında rastgele bir süre bekleyerek tezahürat yapar (ekrandan, 02:50:00):

```java
package oop06a;
import java.util.Random;

public class SoccerFan implements Runnable {
    public final static int STEPS = 10;
    public final static int DELAY = 1000;
    private String teamName, shoutPhrase;

    public SoccerFan( String teamName, String shoutPhrase ) {
        this.teamName = teamName;
        this.shoutPhrase = shoutPhrase;
    }

    public void run() {
        Random generator = new Random();
        try {
            for( int i = 0; i < STEPS; i++ ) {
                System.out.println( teamName + " " + shoutPhrase );
                Thread.sleep( generator.nextInt(DELAY) );
            }
        }
        catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
```

- `STEPS` ve `DELAY`, program boyunca değişmeyen iki değerdir; değişmezliği `final` garanti eder. Hoca, bunların bütün iş parçacıklarınca paylaşılmasını garanti etmek için `static`, ayrıca `public` tanımlandığını söyledi.
- İki global alan vardır: hangi takım için (`teamName`) ve ne bağırılacağı (`shoutPhrase`). Kurucu bu iki alanı başlatır.
- `run()` içinde bir `Random` nesnesi oluşturulur. Hoca, `Random`'ın da `Math`, `Calendar` ve `Date` gibi metotları bilinmesi gereken sınıflardan olduğunu hatırlattı.
- For döngüsü `STEPS` kez (10 kez) döner. Her seferinde takım adı ve tezahürat konsola yazdırılır; sonra `generator.nextInt(DELAY)` ile bir bekleme süresi üretilir ve `Thread.sleep`'e verilir. `sleep` milisaniye cinsinden bir değer alır ve iş parçacığını running durumundan alıp istenen süre kadar blocked durumuna koyar. Sonra döngü başa döner ve bir sonraki tezahürat yapılır.
- `sleep` checked bir istisna fırlattığı için try-catch içinde olmalıdır; `InterruptedException` ile yakalanır.

> **Hocanın vurgusu:** Bir sınıfın çok iş parçacıklı gerçeklenmesi istendiğinde `implements Runnable` yazılmazsa ya da `run()` metodu yazılmazsa puan kaybedilir. `run()` girdi parametresi almayan, değer döndürmeyen bir metottur; ona kendiliğinden bir dönüş değeri ya da argüman eklenirse de puan kaybedilir. Bu, `Runnable`'ın zorunlu kıldığı metottur ve değiştirilmez.

> **Hocanın vurgusu:** Bekletmekten söz ediliyorsa mutlaka `Thread.sleep` kullanılmalıdır.

### 16.2 Thread ile Çalıştırma

Dışarıdaki bir sınıfın `main` metodunda bir `Thread` nesnesi oluşturulur ve içine `SoccerFan` nesnesi verilir. `start()` çağrılınca `run()` çalışmaya başlar ve işi bitene kadar sürer; bu iş parçacığı artık bağımsız çalışır ve işletim sisteminde CPU'dan yer isteyen bir iş parçacığı olur. Aynısı üç kez daha yapılır: dört `SoccerFan` iş parçacığı ve ana programın kendisiyle birlikte beş iş parçacığı çalışır.

<!-- BELİRSİZ: Dört SoccerFan iş parçacığını Thread ile başlatan main sınıfının kodu kareye girmedi; akış altyazıdan aktarıldı. -->

**Soru:** `start` fonksiyonu bitmeden kod okunmaya devam mı ediyor? Bildiğimiz fonksiyon gibi çalışmıyor mu?

**Cevap:** Evet. `start` iş parçacığına yol verir: "sen başla, ne zaman bitersen" der. `run()` içine bir milyon adım yazılsa bile o artık bağımsız bir iş olarak düşünülür; `start` iş parçacığını başlatır ve ana program çalışmaya devam eder. Sonraki `start` da yeni bir iş parçacığını başlatır.

## 17. Executors ve ExecutorService

Önceki yöntemde dört iş parçacığı için oldukça çok kod yazılmış, her seferinde yeni bir `Thread` nesnesi oluşturulmuştu. İşi kolaylaştırmak için Java SDK ile gelen `java.util.concurrent` paketi `ExecutorService` ve `Executors` sınıflarını sağlar. Bu yöntemle yazılacak kod satırı azalır ve iş parçacıklarını takip etmek için ek metotlar sağlanır.

`ExecutorService` metotları (ekrandan, 02:55:00):

| Metot | Açıklama |
|---|---|
| `public void shutdown( )` | Yürütücüyü kapatır, ama havuzdaki görevlerin tamamlanmasına izin verir. Havuza yeni iş parçacığı kabul edilmez. |
| `public List<Runnable> shutdownNow( )` | Hemen kapatır, bitmemiş iş parçacıklarını durdurur ve onları bir liste olarak döndürür. |
| `public boolean isShutdown( )` | Yürütücü kapatıldıysa `true` döndürür. |
| `public boolean isTerminated( )` | Havuzdaki bütün görevler sonlandıysa `true` döndürür. `main` metodunda iş parçacıklarının bitmesini beklemek için kullanılabilir. |

`ExecutorService`, `Executor` arayüzünü genişletir; `Executor`'dan gelen `execute` metodu verilen bir görevi çalıştırır. `execute`'a, `Thread` sınıfına verildiği gibi, `Runnable`'ı gerçekleyen nesneler verilir. `Executors` sınıfı programcı adına bir iş parçacığı havuzu (thread pool) oluşturur: başta belirli sayıda iş parçacığı açılabilir ya da kaç tane gerektiği söylenmeden ihtiyaç kadar dinamik olarak oluşturulabilir.

> **Ders sonrası not:** Hoca `shutdown()`'ın havuzdaki bütün iş parçacıklarının bitmesini bekleyip sonra havuzu kapattığını söyledi; slayta göre `shutdown()` görevlerin bitmesine izin verir, ama çağıran iş parçacığını bekletmez. Hoca ayrıca `isShutdown()` `true` döndürürse havuzdaki iş parçacıklarının çalışmaya devam ettiğini söyledi; slayta göre `isShutdown()` yalnız havuzun kapatıldığını, `isTerminated()` ise bütün görevlerin bittiğini bildirir. Bu yüzden `main`'de bitişi beklemek için `isTerminated()` kullanılır.

Aynı örnek havuzla (ekrandan, 03:00:00):

```java
package oop06a;
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

Slayttaki notlar: önceki örnek bir havuzda çalışacak biçimde değiştirilir; `SoccerFan` sınıfı değişmez; farklı boyutlarda sabit bir havuz (fixed pool) kullanılması da denenmelidir.

- `Executors` sınıfından bir iş parçacığı havuzu istenir; havuz `ExecutorService` türünde döner.
- `execute`'a iş parçacığına dönüştürülecek bütün nesneler verilir; burada dört iş parçacığı oluşturulur. Önceki yöntemde her biri için yeni bir `Thread` oluşturulup `start` çağrılıyordu; burada yalnız `execute` çağrılır.
- En sonda `shutdown` ile havuza "içinde dört iş parçacığı oluşturdun, hepsinin çalışması tamamlandıktan sonra senin için oluşturduğun bu havuzu kapat" denir.

Böylece iki yöntem öğrenilmiş olur: `Thread` sınıfıyla her iş parçacığını tek tek oluşturup `start` ile çalıştırmak ve `Executors` ile `ExecutorService` kullanarak `Runnable`'ı gerçekleyen sınıfın iş parçacıklarını bir havuzda çalıştırmak.

> **Ek bilgi (derste anlatılmadı):** Sabit havuz `Executors.newFixedThreadPool(n)` ile oluşturulur. Havuzda en fazla `n` iş parçacığı aynı anda çalışır; fazladan verilen görevler kuyrukta bekler.

## 18. Yarış Durumu ve synchronized

Program çok iş parçacıklı yapılır ve iş parçacıkları programdaki aynı değere ulaşıp onu güncellemek isterse, yani aynı global alanı değiştirmeye çalışırsa yarış durumu (race condition) oluşur ve program olması gerektiği gibi davranmayabilir.

### 18.1 İki Çekme İşlemi Örneği

Slayttaki örnek (ekrandan, 03:05:00): bir banka hesabı nesnesinin bakiyesi 1000'dir. İki istemci (`AccountWithdrawer`, `Runnable`) aynı hesap nesnesini gösterir. Biri `acct.withdraw( 100 );`, öteki `acct.withdraw( 50 );` çağırır. Hesap sınıfındaki metot:

```java
public void withdraw( int amt )
{
    int curBal = getBalance();
    // possible delay
    balance = curBal - amt;
}
```

Slayttaki not: her iş parçacığının yerel değişken ve parametrelerinin kendi kopyası vardır, ama alanlar (fields) iş parçacıkları arasında paylaşılır.

Hocanın anlatımıyla olaylar:

- İki iş parçacığı da güncelleme amacıyla aynı nesneye ulaşır. Biri 100 TL, öteki 50 TL çekmek ister.
- Önce ikisi de bakiyeyi okur: birinci iş parçacığının `curBal` kopyası 1000, ikincininki de 1000'dir.
- Birinci 100 TL düşer: $1000 - 100 = 900$. Değişiklikten sonra hesapta 900 TL kalacağını düşünür.
- İkinci daha önce 1000 okumuştu; 50 TL düşer: $1000 - 50 = 950$ ve 950'yi yazar.
- Birinci, ikincinin yaptığından habersiz olduğu için bakiyenin 900, ikinci ise 950 olduğunu düşünür. Ortak nesnenin değeri konusunda bir çelişki oluşur. Slayttaki çizimde son bakiye 950'dir.

Ortak bir değişken kullanan iş parçacıkları onu güncellemek için geldiklerinde ilk değeri aynı anda okuyabilir, birbirinden bağımsız güncelleyebilir; güncellemeler birbirinden habersiz olduğu için her biri kendi güncellemesinin gerçekleştiğini sanır. Buna yarış durumu denir.

> **Ek bilgi (derste anlatılmadı):** Bu örnekte doğru sonuç $1000 - 100 - 50 = 850$ olmalıydı. Yarış durumunda son yazan iş parçacığının değeri kalır; bir çekme işlemi kaybolmuş olur.

### 18.2 synchronized Anahtar Sözcüğü

Bunu önlemek için Java'nın `synchronized` anahtar sözcüğü kullanılır. İş parçacıklarının değiştirmek istediği global alanı güncelleyen metodun tanımına, dönüş türünden önce `synchronized` eklenir (örneğin `public synchronized void withdraw(...)`). Örnekte ortak alanı güncelleyen iki metot vardır, `withdraw` ve `deposit`; ikisine de eklenmelidir.

Bu durumda birinci iş parçacığı metoda girdiği anda gelen ikinci iş parçacığı metodun başında bekler. Birinci okumasını yapar, biraz bekler, güncellemesini yapar ve çıkar. İkinci girdiğinde bakiyeyi, birincinin güncellemesinden sonraki değeriyle okur. Önceki sorunda ikisi de metoda girip bakiyeyi eş zamanlı okuyor, farklı süreler beklediği için her biri kendi bildiği gibi güncelliyordu; `synchronized` bunu engeller.

> **Hocanın vurgusu:** İş parçacıkları kullanılıyor ve ortak bir değişkeni güncelliyorsa, bu değişken üzerinde işlem yapan bütün metotlara dönüş türünden önce `synchronized` eklenir.

### 18.3 Banka Simülasyonu

Örnekte üç parça vardır: `AccountDepositer` ve `AccountWithdrawer` adlı iki iş parçacığı sınıfı, ikisinin ortak kullandığı `Account` sınıfı ve `main` metodunu içeren ayrı bir banka simülasyonu sınıfı.

- `Account` iş parçacığı oluşturan bir sınıf olmadığı için `Runnable`'ı gerçeklemez; yalnız iş parçacıklarının ortak kullanacağı nesnenin sınıfıdır. Global alan olarak bakiyeyi tutan bir `double`, bir kurucu, bir getter, iş parçacıklarının çalıştıracağı `withdraw` ve `deposit` metotları ve bir `possibleDelay` metodu vardır. Hoca, `Thread.sleep`'in doğrudan bu metotların içine de konabileceğini, ama ayrı bir metot yapılıp iki metottan da çağrıldığını söyledi. Bu sürümde `synchronized` yoktur; yani yarış durumu oluşacaktır.
- `AccountDepositer` (ekrandan, 03:10:00):

```java
package oop06b;
public class AccountDepositer implements Runnable {
    private Account account;
    private double amount;
    public AccountDepositer(Account account, double amount) {
        this.account = account; this.amount = amount;
    }
    public void run() {
        account.deposit(amount);
    }
}
```

- `AccountWithdrawer` aynı yapıdadır; `run()` içinde `account.withdraw(amount)` çağırır.
- Simülasyonun `main`'i önce bakiyesi 0 olan bir `Account` nesnesi oluşturur. Bu nesnenin referansı iş parçacıklarına verilir; böylece hepsi aynı nesnedeki bakiyeyi güncellemeye çalışır.
- Güncellemeden önceki bakiye yazdırılır.
- `Executors`'tan bir havuz alınır; başta kaç iş parçacığı olacağı belirtilmediği için `newCachedThreadPool` çağrılır.
- Bir for döngüsünde her biri hesaba 1 TL yatıran 100 `AccountDepositer` iş parçacığı oluşturulup `execute`'a verilir. Hoca, geçici değişken kullanmadan `new AccountDepositer(...)`'ın doğrudan `execute`'a da konabileceğini söyledi. Aynı biçimde her biri 1 TL çeken 50 `AccountWithdrawer` iş parçacığı oluşturulur.
- `shutdown` çağrılır: havuzdaki toplam 150 iş parçacığının hepsi bitince havuz kapanacaktır.
- Bir while döngüsünde havuzun sonlanıp sonlanmadığı (`isTerminated`) kontrol edilir; `true` olunca son bakiye yazdırılır.

<!-- BELİRSİZ: Account sınıfının ve banka simülasyonu main sınıfının kodlarını içeren slaytlar kareye girmedi; ayrıntılar altyazıdan aktarıldı. -->

`synchronized` kullanılmazsa 100 kez 1 TL yatırılıp 50 kez 1 TL çekildiği halde sonuç her çalıştırmada farklı çıkar. `synchronized` eklendiğinde 100 TL yatırılıp 50 TL çekildiği için sonuç her seferinde 50 TL olur.

Ajan bu senaryoyu, slayttaki `Account` kodu kareye girmediği için kendi yazdığı küçük bir `Account` sınıfıyla (okuma, 1 ms bekleme, yazma) `java` ile çalıştırdı: `synchronized` olmadan son bakiye 4, `synchronized` ile 50 çıktı. Kilitsiz sonuç çalıştırmadan çalıştırmaya değişir.

## Örnek Sorular

**1. (derste sözlü, 01:55:45)** `FileInputStream` nesnesi doğrudan `ObjectInputStream`'in kurucusuna verildiğinde elde onun bir değişkeni kalmaz. Bu iç akış nasıl kapatılır?

> **Cevap (derste verildi):** Yalnız dıştaki `ObjectInputStream`'e `close()` çağrılır; kapsayıcı akış kapanmadan önce kendisine bağlı `FileInputStream`'i de kapatır. `ObjectOutputStream` ve `FileOutputStream` için de aynısı geçerlidir.

**2. (derste sözlü, 01:58:00)** `@SuppressWarnings` için `resource`, `serial`, `unchecked` gibi değerlerin hepsi ezberlenmeli mi?

> **Cevap (derste verildi):** Ders kapsamında görülen üç dört değeri (`serial`, `unused` vb.) bilmek yeterlidir. `serial`, `serialVersionUID` tanımlanmadığında çıkan uyarıyı; `unused`, hiç kullanılmayan metot ya da sınıf uyarısını bastırır.

**3. (derste sözlü, 02:32:38)** `Person` içinde `Employee` iç sınıfı tanımlamak, `Person`'ı alt sınıflara parçalamak gibi bir şey değil mi?

> **Cevap (derste verildi):** İç sınıf, nesnesi yalnız bir kez ve tek amaçla gereken sınıflar için kullanılır. Bir sınıf parçalara bölünmek isteniyorsa kalıtım (`Person`'dan `Employee` türetmek gibi) tercih edilmelidir; örnek yalnız iç sınıf kullanımını göstermek için böyle kurulmuştur.

**4. (derste sözlü, 02:53:18)** `thread.start()` çağrıldıktan sonra ana program `run()` bitene kadar bekler mi?

> **Cevap (derste verildi):** Hayır. `start()` iş parçacığını başlatıp hemen döner; iş parçacığı bağımsız çalışır ve ana program bir sonraki satırla devam eder. Dört `SoccerFan` başlatılınca ana programla birlikte beş iş parçacığı çalışır.

**5. (ekrandan, 00:25:00)** `printExpiredItems` metodunda `Item` türündeki bir elemana `isExpired()` neden doğrudan çağrılamaz, ne yapılır?

> **Cevap (derste verildi):** `isExpired()` yalnız `Food`'da tanımlıdır; `Item` referansında bu metot yoktur ve eleman bir `Electronics` olabilir. Önce `item instanceof Food` ile tür kontrol edilir, sonra `((Food)item).isExpired()` biçiminde tür dönüşümü yapılır. Tasarımla çözüm: `getExpireDate()` ve `isExpired()` `Item` arayüzüne taşınır (ekrandan, 00:50:00).

**6. (ekrandan, 03:05:00 ve derste sözlü, 03:13:51)** Bakiyesi 0 olan bir hesaba, `synchronized` olmayan `deposit` ve `withdraw` metotlarıyla 100 iş parçacığı 1'er TL yatırır, 50 iş parçacığı 1'er TL çekerse son bakiye ne olur? `synchronized` eklenirse ne olur?

> **Cevap (derste verildi):** `synchronized` yoksa yarış durumu yüzünden sonuç her çalıştırmada farklı olabilir. `synchronized` eklenirse sonuç her zaman $100 - 50 = 50$ TL olur. Ajanın kendi yazdığı benzer bir `Account` sınıfıyla yaptığı denemede kilitsiz sürümde 4, kilitli sürümde 50 çıktı.

## Dersin Toparlaması

Ders, kalıtımda üst tür referansıyla takip edilen bir nesneyi alt türe çeviren typecasting ile başladı. `MarketShelf` örneğinde `instanceof` ile tür kontrolü yapıldı ve `(Food)item` dönüşümüyle yalnız gıdalara ait `isExpired()` çağrıldı; `Calendar` ve `Date` sınıflarının `getInstance`, `add`, `set`, `getTime` ve `before` metotları gösterildi. Typecasting'in "gerekli bir kötülük" olduğu, metotları üst türe taşıyan bir tasarımla önlenebileceği ve bugün yalnız deserialization'da zorunlu olduğu anlatıldı.

Ardından dosya işlemlerine geçildi: G/Ç istisnaları, `java.io.File` ile dosya yönetimi ve ikili dosyalara bayt akışlarıyla nesne yazma ve okuma. `FileOutputStream`/`ObjectOutputStream` ve `FileInputStream`/`ObjectInputStream` zincirleri, `Serializable` arayüzü, `serialVersionUID`, annotation'lar, okumadaki iki istisna ve dosya sonu sorununa iki çözüm (sayıyı önce yazmak ya da veri yapısının tamamını yazmak) `Arkadas` ve `Contact` örnekleriyle işlendi. Sonra iç sınıflar `Person`/`Employee` örneğiyle ve iç sınıfın görünürlüğüne göre üç kullanım biçimiyle anlatıldı. Son bölümde çoklu iş parçacığına giriş yapıldı: süreç ve iş parçacığı durumları, `Runnable` ve `run()`, `Thread.start()`, `Executors` ile iş parçacığı havuzu, yarış durumu ve `synchronized` anahtar sözcüğü. Hoca bu konuyla dönemin ders konularını tamamladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
