# Ders 12 Genişletilmiş Notu: Soyut Sınıflar ve Arayüzler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nerede Kalmıştık
- 2. Soyut Sınıf Kavramı
- 3. Soyut Sınıf Ne Zaman Gerekir?
- 4. PrintDriver Örneği
- 5. Override ve Overload Hatırlatması
- 6. Çoklu Kalıtım ve Elmas Problemi
- 7. Soyut Sınıf Tasarımı: Çocuklar İçin Eşyalar
- 8. Item, Clothing ve Toy Sınıflarının Kodu
- 9. Child ve Kindergarten Sınıfları
- 10. Ana Programın Metinden Yazılması
- 11. Normal Sınıflarla Kalıtım Tekrarı: Point ve Circle
- 12. Arayüzler (Interfaces)
- 13. Arayüz Tasarımı: Taşıt Vergileri
- 14. İki Arayüzde Aynı Adlı Metot ve Arayüzler Arası Kalıtım
- 15. Arayüz mü Soyut Sınıf mı?
- 16. Arayüzle Kalıtım Örneği: Shape, Point, Circle, Cylinder
- 17. Normal Sınıflarla Kalıtım Örneği: acc ve accBusiness
- 18. Hangisini Nasıl Seçeriz? Öğrenci Sorusu
- 19. Taşıt Kayıt Sistemi ve Alıştırma
- Örnek Sorular

## 1. Nerede Kalmıştık

Önceki derste nesneler arasındaki ilişkiler konuşulurken kalıtıma (inheritance) girilmişti. Kalıtımla bir nesne, başka bir nesnenin sahip olduğu özellikleri alabiliyordu ve bu ilişki normal (regular) sınıflarla kurulmuştu. Şimdiye kadar görülen bütün sınıflar normal sınıflardı: `public class SinifAdi` yazılır, süslü parantezler içinde üye alanlar (data member fields) ve üye metotlar tanımlanırdı. Bu derste kalıtım ilişkisi bu kez soyut sınıflarla (abstract classes), ardından arayüzlerle (interfaces) kuruldu. Ders, ders notlarının 113. slaytındaki "Special Topics in OOP / Abstract Classes" başlığından başladı (ekrandan, 00:15:00) ve 131. slaytta bitti (ekrandan, 01:50:00).

## 2. Soyut Sınıf Kavramı

Bir sınıf `abstract` anahtar sözcüğüyle soyut olarak tanımlanır: `public abstract class SinifAdi { ... }`. Soyut sınıfın da normal sınıflar gibi üye alanları ve üye metotları vardır. Farkı iki noktadadır: bazı metotlar soyut (abstract) tanımlanabilir ve soyut sınıfın nesnesi oluşturulamaz.

Bugüne kadar bir sınıfa iş yaptırmak için önce `new` ile nesnesini oluşturup sonra metotlarını çağırıyorduk. Soyut sınıfın nesnesi oluşturulamadığına göre neden kullanılır? Soyut sınıf kalıtım ilişkisinde üst sınıf (parent, base class) olarak kullanılır ve kendisinden türeyecek alt sınıflar için bir şablon (template) oluşturur. Soyut sınıfta soyut tanımlanmış metotlar alt sınıflarda mutlaka bulunmalı ve gövdeleri (method body) alt sınıflarda mutlaka yazılmalıdır.

Slayttaki tanımlar şunlardır (ekrandan, 00:15:00):

- Soyut sınıf, temel sınıf olarak kullanılan ve normal alt sınıfları için bir şablon temsil eden sınıftır. Şimdiye kadar yazılan normal sınıflara somut (concrete) sınıf da denir.
- Soyut sınıfın örneğini (instance) oluşturmak yasaktır; somut alt sınıflarının örnekleri oluşturulabilir.
- Soyut sınıfların, somut sınıflar gibi üye alanları olabilir.
- Soyut sınıfların hem somut hem soyut üye metotları olabilir. Soyut metodun `abstract` sözcüğüyle birlikte yalnız tanımı vardır, gövdesi yoktur.
- Kalıtımla alınan soyut metotların gövdeleri somut alt sınıflarda yazılmalıdır. Yazılmazsa o alt sınıflar da soyut tanımlanmalıdır.

Soyut bir sınıftan türeyen sınıf yine soyut olabilir; ondan türeyen bir başka sınıf da soyut olabilir. Ama sonunda nesnesi oluşturulacak sınıf normal bir sınıf olmalıdır: yukarıdaki soyut sınıfların soyut metotlarını yazan en alttaki normal sınıfın nesnesi oluşturulur ve metotlar onun üzerinden çağrılır.

## 3. Soyut Sınıf Ne Zaman Gerekir?

Kalıtım iki yolla kurulabilir. Birincisi önceki derste görüldüğü gibi normal sınıflarla: bir normal sınıf üst, bir normal sınıf alt sınıf olur ve alt sınıf `extends` ile üst sınıfı genişletir. İkincisi soyut sınıflarla: üst sınıf soyut, alt sınıf normal olur. Peki normal sınıflar varken neden soyut sınıfla kalıtıma ihtiyaç duyulur?

Kalıtım kurarken bir kalıtım ağacı (inheritance tree) oluşturulur: üst sınıf, alt sınıf, onun alt sınıfı ve böyle devam eder. Kalıtım bir genelleştirme-özelleştirme (generalization-specialization) ilişkisidir: üst sınıf genelde genel, alt sınıf daha özel bir sınıftır. Ağaç iki, üç, dört seviyeye çıktığında en üstteki sınıf o kadar genel hale gelebilir ki nesnesini oluşturmaya hiç gerek kalmaz. Bu durumda üst sınıf soyut sınıf olarak yazılır.

Slayttaki açıklama da aynıdır (ekrandan, 00:20:00): sınıf hiyerarşisinde yukarı çıktıkça sınıflar genelleşir ve bir noktada örneklenmelerine gerek kalmaz. Soyut sınıf şablon olarak da kullanılabilir: belirli bir sınıfın belirli metotlara mutlaka sahip olması isteniyorsa bu metotlar soyut bir üst sınıfta tanımlanır ve sınıflar arasında kalıtım ilişkisi kurulur.

UML sınıf şemalarında soyut sınıf, adı italik yazılarak ya da `<<Abstract>>` stereotipi eklenerek işaretlenir. `<<...>>` gösterimine stereotip denir; UML şemalarında bir sembol olağan anlamı dışında kullanıldığında eklenir. Normal sınıfta sınıf adının üstünde böyle bir gösterim yoktur. Soyut bir metot ise UML'de metot satırının sonuna iki nokta ve süslü parantez içinde `{abstract}` yazılarak gösterilir.

## 4. PrintDriver Örneği

Hocanın gösterdiği UML diyagramında üst sınıf `PrintDriver` soyut tanımlanmıştı, alt sınıf ise `PCL6Driver`'dı. Yazıcı sürücüsü genel bir sınıftır: her sürücünün bir `print` metodu olması gerektiği bilinir, ama genel bir sürücü için yazdırmanın nasıl yapılacağı bilinmez. `PCL6Driver` ise `PrintDriver`'ı genişleten özel bir sürücüdür ve onun için yazdırmanın nasıl yapılacağı bilinir. Bu yüzden `print` üst sınıfta soyut tanımlanır, gövdesi alt sınıfta yazılır.

Hoca bunu Türkçe olarak da özetledi: kalıtım ilişkisinde üst sınıf genel bir sınıfsa ve bu sınıfın bazı metotları üst sınıfta yazılamıyorsa ya da yazmak anlamsızsa, bu metotlar soyut tanımlanır ve alt sınıflarda yazılması sağlanır. Normal sınıfla kalıtımda `print` metodunun üst sınıfta da yazılması gerekirdi, çünkü normal metottur. Soyut metotta ise yalnız metodun tanımı yazılır, gövdesi yazılmaz.

Örneğin kaynak kodu (ekrandan, 00:25:00):

```java
public abstract class PrintDriver {
    public void initSpooler( ) {
       /* necessary codes*/
    }
    public abstract void print( Document doc );
}

public class PCL6Driver extends PrintDriver {
    public void print(Document doc) {
       //necessary code is inserted here
    }
}
```

`abstract` sözcüğü `class` sözcüğünden önce gelir. `initSpooler` normal bir metottur; bu yüzden gövdesi vardır. `print` soyut metottur; dönüş türünden (`void`) hemen önce `abstract` yazılır ve gövdesi yoktur, satır noktalı virgülle biter.

Alt sınıfın tanımı normal sınıflarla kalıtımdakiyle tamamen aynıdır: `extends` kullanılır. `print` üst sınıfta soyut olduğu için `PCL6Driver`'da bulunmak ve gövdesi yazılmak zorundadır. `initSpooler` metodunu ise `PCL6Driver` kalıtımla alır ve kendi metodu gibi kullanır.

## 5. Override ve Overload Hatırlatması

Bu noktada bir öğrenci, alt sınıfta `print` metodunu yazarken override etmek için bir şey yazmak gerekip gerekmediğini sordu.

**Soru:** Alt sınıfta `print` metodunu yazarken bir override anahtar sözcüğü yazmamız gerekmiyor mu? **Cevap:** Hayır. Override ve overload, `abstract` ya da `extends` gibi Java sözdiziminde bulunan anahtar sözcükler değildir; kavram olarak öğrenildi. Bir alt sınıftaki metot üst sınıftaki metotla aynı imzaya (signature) sahipse, yani onu yeniden yazıyorsa, o metot üstteki metodu override ediyor denir; bunun için bir anahtar sözcük kullanılmaz. Overload ise aynı sınıf içinde adı aynı, imzası farklı iki metot bulunmasıdır.

> **Ders sonrası not:** Hoca overload için imza farkının "ya dönüş türünde ya da argümanın türünde" olabileceğini söyledi. Doğrusu: Java'da yalnız dönüş türü farklı olan iki metot overload sayılmaz; `int f(int x)` ve `double f(int x)` aynı sınıfta derleme hatası verir (ajan tarafından denendi). Overload için parametre listesi (sayı, tür ya da sıra) farklı olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Java'da `override` bir anahtar sözcük değildir, ama büyük olasılıkla bu derste henüz anılmayan, isteğe bağlı bir `@Override` ek açıklaması (annotation) vardır. Metodun üstüne yazıldığında derleyici, metodun gerçekten bir üst sınıf ya da arayüz metodunu yeniden tanımladığını denetler; imza yanlış yazılmışsa hata verir. Kullanmak zorunlu değildir.

## 6. Çoklu Kalıtım ve Elmas Problemi

Şimdiye kadarki bütün örneklerde `extends` anahtar sözcüğünden sonra yalnız bir üst sınıf adı vardı: bir alt sınıf yalnız bir üst sınıfı genişletebilir. Peki iki üst sınıfı olan bir alt sınıf yazılabilir mi? Hocanın gösterdiği diyagramda bir sınıfın iki üst sınıfı vardı: öğrenci (`Student`) ve çalışan (`Employee`). Nesne yönelimli diller bu çoklu kalıtım (multiple inheritance) yeteneğine izin vermez.

Nedeni şu senaryoyla açıklandı. Üst sınıf `Person`'dan iki alt sınıf türemiş olsun: `Student` ve `Employee`. `Person`'da bir `introduceSelf` metodu olsun; bu metot soyut da olabilir, o durumda hem `Student` hem `Employee` kendi `introduceSelf` metodunu yazmak zorundadır. Şimdi hem `Student` hem `Employee` sınıfını genişleten bir asistan öğrenci sınıfı düşünülsün. Bu sınıfta `introduceSelf` çağrıldığında Java sanal makinesi, bunun `Student`'taki mi yoksa `Employee`'deki mi `introduceSelf` olduğunu anlayamaz. Şekli elmasa benzediği için buna elmas kalıtım problemi (diamond inheritance problem) denir: torun sınıf hangi ebeveynin metodunu kullanacağını bilemez.

Bu yüzden normal sınıflarla da soyut sınıflarla da çoklu kalıtım yapılmaz: `extends`'ten sonra her zaman yalnız bir sınıf adı gelir. Çoklu kalıtımı desteklemek için ileride arayüzler öğrenilecektir (bu derste 12. bölümde işlendi).

Bu sırada hoca birinin el kaldırdığını gördü, ama soru gelmedi.

## 7. Soyut Sınıf Tasarımı: Çocuklar İçin Eşyalar

Soyut sınıfla kalıtım örneği bir anaokulundaki çocuklara verilecek eşyalar üzerinedir. Eşyalar oyuncak ya da giysi olabilir. Her eşya her çocuğa uygun değildir: oyuncakların bir yaş sınırı, giysilerin en küçük ve en büyük ay sınırı vardır. Program, eşyayı doğru çocuğa vermelidir.

Slayttaki gereksinim (ekrandan, 00:35:00):

- Çocuklar için eşyalar düşünülsün. Her eşya her çocuğa uygun değildir.
  - Oyuncakların genelde yıl olarak ölçülen bir alt yaş sınırı vardır.
  - Giysilerin genelde ay olarak ölçülen hem alt hem üst yaş sınırı vardır.
- Bu durum nasıl modellenmelidir?

UML sınıf diyagramı (ekrandan, 00:35:00 ve 00:40:00):

| Sınıf | Alanlar | Metotlar |
|---|---|---|
| `<<Abstract>> Item` | `- barcode, description : String` | `+ Item( barcode, description : String )`, `+ getBarcode( ) : String`, `+ getDescription( ) : String`, `+ isSuitable( aChild: Child ) : boolean {abstract}` |
| `Toy` | `- minAgeLimit : int` | (gösterilmemiş) |
| `Clothing` | `- minMonthLimit, maxMonthLimit : int` | (gösterilmemiş) |
| `Child` | `- name : final String`, `- ageInMonths : int` | (gösterilmemiş) |
| `KinderGarten` | (gösterilmemiş) | `+ addChild( Child ) : boolean`, `+ findOldestChild( ) : Child` |

İlişkiler:

- `Toy` ve `Clothing`, içi boş üçgen uçlu okla `Item`'a bağlıdır: ikisi de `Item`'dan türer.
- `Item`'dan `Child`'a kesikli ok vardır: bağımlılık (dependency).
- `KinderGarten` (1) ile `Child` (`*`) arasında `Child`'a doğru oklu düz çizgi vardır.

`Item` soyut sınıftır; bunu adının üstündeki `<<Abstract>>` gösterir. İki üye alanı (`barcode` ve `description`, ikisi de `String`) ve dört metodu vardır. Yapıcı iki parametre alır; ayrıca barkod ve açıklama için iki `get` metodu vardır. Bu üç metot soyut sınıfta bulunsalar da normal metotlardır; bu yüzden gövdeleri yazılır. Dördüncü metot `isSuitable` soyut tanımlanmıştır; `Item`'da gövdesi yoktur. `Toy` ve `Clothing` `Item`'ı genişlettiği için ikisi de kendi `isSuitable` metodunu yazmak zorundadır.

Slaytta `Toy` ve `Clothing` sınıflarının yalnız adı ve üye alanları gösterilmiş, metotları gizlenmişti.

> **Hocanın vurgusu:** Bir UML diyagramı çizmeniz istendiğinde sınıfların üye metotlarını da göstermeniz gerekir.

`Item`'ın metotlarından `isSuitable`, `Child` sınıfını bir parametre türü olarak kullanır. `Item`'da `Child` türünde bir üye alan olsaydı bu bir association olurdu. Böyle bir alan olmadığı ve `Child` yalnız `Item`'ın metodunda kullanıldığı için ilişki bağımlılıktır: `Item`, `Child`'a bağımlıdır.

`Child` ile anaokulu arasındaki ilişki yine association'dır: bir anaokulunda sıfır ya da daha çok çocuk olur. Association'ın iki güçlü biçimi olan aggregation ve composition'dan bu, composition'a benzer, çünkü bir çocuk yalnız bir anaokuluna ait olabilir ve bir anaokulunda sıfır ya da daha çok çocuk bulunabilir. `Child` sınıfının iki üye alanı vardır: `final` tanımlanmış `name` ve `ageInMonths`. Anaokulu sınıfında `addChild` ve `findOldestChild` metotları vardır.

## 8. Item, Clothing ve Toy Sınıflarının Kodu

### 8.1 Item

`Item` sınıfında sınıf tanımının önüne `abstract` sözcüğü eklenir; soyut sınıf tanımındaki tek fark budur. Üye alanlar UML'de gösterildiği gibi iki `String` alandır ve her zamanki gibi `private` tanımlanır. Hoca bunları `protected` da tanımlayabileceğini söyledi: o durumda alanların değerine alt sınıflardan doğrudan erişilebilirdi. Ama bu değerlere üst sınıfın metotları üzerinden erişilmesi istendiği için `private` seçildi. Ardından iki parametreli bir yapıcı alanları başlatır, iki `get` metodu barkodu ve açıklamayı döndürür. Dördüncü metot `isSuitable`'dır; tanımına `abstract` eklenmiştir ve gövdesi yoktur, çünkü gövdesinin alt sınıflarda yazılması istenir. Bir metot soyut tanımlanmışsa bu üst sınıfı genişleten bütün alt sınıflar o metodu yazmak zorundadır.
<!-- BELİRSİZ: Item sınıfının kaynak kodunun yer aldığı slayt (119) karelerde görünmüyor; kod burada altyazıdaki anlatıma ve UML diyagramına göre sözle aktarıldı. -->

### 8.2 Clothing

`Clothing` sınıfının UML'deki iki üye alanı `minMonthLimit` ve `maxMonthLimit`'tir, ikisi de `int` türündedir. Kodu (ekrandan, 00:45:00):

```java
package nyp06;
public class Clothing extends Item {
    private int minMonthLimit, maxMonthLimit;

    public Clothing(String barcode, String description,
                int minMonthLimit, int maxMonthLimit ) {
        super(barcode, description);
        this.minMonthLimit = minMonthLimit;
        this.maxMonthLimit = maxMonthLimit;
    }
    public boolean isSuitable(Child aChild) {
        if( aChild.getAgeInMonths() >= minMonthLimit
                && aChild.getAgeInMonths() <= maxMonthLimit )
            return true;
        return false;
    }
}
```

Alt sınıfın yazımı normal sınıflarla kalıtımdakiyle aynıdır. Yapıcı dört parametre alır. `Clothing` yalnız iki alan tanımlasa da `Item`'ın iki alanını da kalıtımla almıştır; yani aslında dört alanı vardır. Ancak `barcode` ve `description` üst sınıfta `private` olduğu için değerleri üst sınıfın yapıcısıyla atanmalıdır: `super(barcode, description)` üst sınıfın yapıcısını çağırır. Ardından `Clothing`'in kendi iki alanı başlatılır.

`Item` soyut olduğu ve `isSuitable` orada soyut tanımlandığı için `Clothing` bu metodu gövdesiyle birlikte yazmak zorundadır. Metot bir `Child` nesnesinin referansını alır, onun `getAgeInMonths()` metodunu çağırır ve çocuğun ay olarak yaşının `minMonthLimit` ile `maxMonthLimit` arasında olup olmadığına bakar. Aralıktaysa giysi uygundur ve `true` döner, değilse `false` döner.

### 8.3 Toy

`Toy` de `Item`'ı genişletir. Tek alanı `minAgeLimit`'tir (`int`). Kodu (ekrandan, 00:50:00):

```java
package nyp06;
public class Toy extends Item {
    private int minAgeLimit;

    public Toy(String barcode, String description, int minAgeLimit) {
        super(barcode, description);
        this.minAgeLimit = minAgeLimit;
    }
    public boolean isSuitable(Child aChild) {
        if( aChild.getAgeInMonths()/12 >= minAgeLimit )
            return true;
        return false;
    }
}
```

Yapıcı üç parametre alır; kalıtımla gelen `barcode` ve `description` yine `super(...)` ile başlatılır, sonra `minAgeLimit` atanır. `isSuitable` metodunda çocuğun yaşı ay olarak verildiği için 12'ye bölünerek yıla çevrilir ve oyuncağın alt yaş sınırından büyük ya da eşit olup olmadığına bakılır.

Slaytın altında iki alıştırma önerisi vardı: `Kindergarten` sınıfını verilen metotlarla ve daha fazlasıyla yazmak; bir uçta `Item` örnekleri, diğer uçta `Kindergarten`/`Child` olan farklı ilişkiler kurmak (ekrandan, 00:50:00).

Bu noktada on dakikalık ara verildi.

## 9. Child ve Kindergarten Sınıfları

### 9.1 Child

Aradan sonra hoca kodları Eclipse'te `nyp06` paketinde tekrar gösterdi. `Child` normal bir sınıftır ve iki üye alanı vardır; biri (`name`) `final` tanımlanmıştır. Bir alan `final` tanımlandığında ilk kez değeri atandıktan sonra bir daha değiştirilmez; bu yüzden onun için `set` metodu yazılmaz, değeri yapıcıda bir kez atanır. Diğer alan ay olarak yaştır (`ageInMonths`). Sınıfta iki değer alan bir yapıcı, `name` için bir `get` metodu ve `ageInMonths` için `get` ve `set` metotları vardır.

### 9.2 Kindergarten

Anaokulu ile çocuk arasında composition ilişkisi vardır: bir anaokulu içinde sıfır ya da daha çok çocuk bulundurabilir. Böyle bir ilişkide birinci nesnenin üye alanlarında bir veri yapısı bulunur. Şimdiye kadar öğrenilen tek veri yapısı dizidir (array); diğer veri yapıları dersin ilerleyen haftalarında öğrenilecektir.

Kodun ilk kısmı (ekrandan, 01:05:00 ve 01:10:00):

```java
package nyp06;

public class Kindergarten {

    private Child[] children;
    private int childCount;

    public Kindergarten( int maxChild ) {
        children = new Child[maxChild];
        childCount = 0;
    }

    public Child findChild( String name ) {
        for( int i=0; i<childCount; i++ )
            if( children[i].getName().equalsIgnoreCase(name) )
                return children[i];
        return null;
    }

    public boolean addChild( Child aChild ) {
        if( childCount == children.length || aChild == null ||
                findChild(aChild.getName()) != null )
            return false;
        children[childCount]=aChild;
        childCount++;
        return true;
    }

    public Child findOldestChild( ) {
        Child oldest = children[0];
        for( int i=1; i<childCount; i++ )
            if( children[i].getAgeInMonths() > oldest.getAgeInMonths() )
                oldest = children[i];
        return oldest;
    }

    public int getCapacity() {
        return children.length;
    }

    public void setCapacity(int capacity) {
        if( capacity > children.length ) {
            Child newChildren[] = new Child[capacity];
            for( int i=0; i<childCount; i++ )
                newChildren[i] = children[i];
            children = newChildren;
        }
    }
    // removeChild( String name ) ... (aşağıda anlatıldı)
}
```

`Child` türünde bir dizi alan olarak yalnız tanımlanmıştır, başlatılmamıştır. Dizideki çocukları izlemek için `childCount` tamsayı alanı vardır. Yapıcıya anaokuluna katılabilecek en fazla çocuk sayısı verilir ve dizi bu uzunlukta oluşturulur. Bu satır çalıştığında dizide hiç `Child` nesnesi yoktur: yalnız `Child` nesnelerinin referanslarını tutacak `maxChild` uzunlukta bir dizi oluşur ve başta her hücresinde `null` vardır. `childCount` başta sıfırdır.

`findChild` metodu daha önce galeri örneğinde gösterilen araba arama metoduna benzer; orada araba hem adıyla hem nesne referansıyla aranmıştı. Burada çocuk adıyla aranır: döngü bütün nesneleri dolaşır, aynı ada sahip bir çocuk varsa onun referansını döndürür.

`addChild` da galerideki araba ekleme metodu gibidir. `if` deyiminde üç koşul vardır ve bunlardan biri doğruysa çocuk eklenmez, metot `false` döndürür:

- Dizide yer kalmamıştır: `childCount`, `children.length`'e ulaşmıştır.
- Gönderilen referans `null`'dır, yani bir nesneyi göstermez.
- Aynı adda bir çocuk dizide zaten vardır: `findChild` `null`'dan farklı bir değer döndürür.

Bu durumların hiçbiri yoksa çocuk eklenebilir. `childCount` dizideki ilk boş (`null`) hücreyi gösterir; sıfırıncı indisten başlayarak nesneler sırayla yerleştirilir. Yeni çocuğun referansı bu hücreye atanır ve `childCount` bir artırılır.

`findOldestChild` metodunun mantığı `findChild` ile aynıdır; ad yerine yaşlar karşılaştırılır ve en büyük çocuğun referansı döndürülür. `getCapacity` dizinin uzunluğunu verir.

`setCapacity`, anaokulundaki çocuk sayısı zamanla artırılmak istendiğinde kullanılır. Dizinin boyutu yapıcıda belirlenmişti. Yeni kapasite mevcut kapasiteden büyükse yeni bir dizi oluşturulur, mevcut dizideki her nesne bir döngüyle yeni diziye sırayla atanır. Son olarak başta oluşturulan diziyi gösteren `children` değişkenine yeni dizinin adresi atanır. Yani yeni bir dizi yaratılır, nesneler eski diziden yeni diziye taşınır ve diziyi izleyen değişken yeni diziye yöneltilir.

`removeChild` metodu galeri örneğindeki araba çıkarma metoduyla aynıdır. Dizi üzerinde döngüyle dolaşılır ve her çocuğun adı çıkarılmak istenen adla karşılaştırılır. Eşleşen bulunursa çocuğun referansı geçici bir değişkene atanır, o indisten sonraki bütün referanslar birer yana (sola) kaydırılır ve geçici değişkendeki referans döndürülür.
<!-- BELİRSİZ: removeChild metodunun kodu karelerde yalnız imza satırının bir kısmıyla görünüyor; metot altyazıdaki anlatıma göre sözle aktarıldı. -->

**Soru:** Kaydırmadan sonra dizinin en sonundaki hücreyi `null` yapmamız gerekmiyor mu? **Cevap:** Hoca öğrencinin haklı olduğunu söyledi: sonda eski bir çocuk referansı kalır. Ayrıca `childCount` da azaltılarak güncellenmelidir. Kaç nesne olduğu `childCount` üzerinden izlendiği için `childCount`'tan sonraki hücrenin `null` olup olmaması programı çok etkilemez, ama `null` yapmak iyi olur.

> **Hocanın vurgusu:** Composition ilişkisi içeren bir soruda dizi içinde nesne eklemek, bir nesneyi bulmak, bir nesneyi çıkarmak ya da dizinin kapasitesini artırmak istenirse bunların kodunu yazabiliyor olmanız gerekir.

## 10. Ana Programın Metinden Yazılması

`Main` sınıfı bu metotları dener (ekrandan, 01:15:00):

```java
package nyp06;

public class Main {

    public static void main(String[] args) {
        Child ahmet = new Child("Ahmet Küçük",5); //5 aylık
        Toy lego = new Toy("123456","Lego Star Wars",4); //4 yaş
        Clothing pinny = new Clothing("86978945","mama önlüğü",0,24); //0-24 ay
        if( lego.isSuitable(ahmet) )
            System.out.println("Deneme 1 hatalı");
        else
            System.out.println("Deneme 1 tamam");
        if( pinny.isSuitable(ahmet) )
            System.out.println("Deneme 2 tamam");
        else
            System.out.println("Deneme 2 hatalı");
        Kindergarten yuva = new Kindergarten(2);
        if( yuva.addChild(ahmet) )
            System.out.println("Deneme 3 tamam");
        else
            System.out.println("Deneme 3 hatalı");
        if( yuva.findChild("AHMET KÜÇÜK") == ahmet )
            System.out.println("Deneme 4 tamam");
        else
            System.out.println("Deneme 4 hatalı");
        if( yuva.findChild("Yunus Selçuk") == null )
            System.out.println("Deneme 5 tamam");
        else
            System.out.println("Deneme 5 hatalı");
        yuva.addChild( new Child("Ayşe Minik",24) );
        if( yuva.addChild( new Child("Zeki Çalışkan",28) ) )
            System.out.println("Deneme 7 hatalı");
        else
            System.out.println("Deneme 7 tamam");
        yuva.setCapacity(5);
        if( yuva.findChild("AHMET KÜÇÜK") == ahmet )
            System.out.println("Deneme 6 tamam");
        else
            System.out.println("Deneme 6 hatalı");
    }
}
```

Ekrandaki kaynak dosyada Türkçe karakterler kodlama sorunu nedeniyle bozuk görünüyordu (örneğin "aylýk"); burada doğru karakterlerle yazıldı. Program önce bir çocuk, bir oyuncak ve bir giysi nesnesi oluşturur ve oyuncak ile giysi için `isSuitable` metodunu çalıştırır. Ardından iki kişilik bir anaokulu oluşturur, çocukları ekler, `findChild` metodunu dener, dolu anaokuluna üçüncü çocuğu eklemeyi dener ve en sonda `setCapacity` metodunu dener.

Ajan bu programı derste gösterilen sınıflarla (`Item`, `Child` ve `removeChild` dışındaki `Kindergarten` metotları altyazıdaki anlatıma göre yazılarak) `java` ile çalıştırdı; her denemede "tamam" çıktısı alındı. 5 aylık çocuk için yıl olarak yaş $5/12 = 0$ olduğundan 4 yaş sınırlı oyuncak uygun değildir ("Deneme 1 tamam"); 0-24 ay aralığındaki önlük uygundur ("Deneme 2 tamam"). `equalsIgnoreCase` büyük-küçük harf farkını gözetmediği için "AHMET KÜÇÜK" araması eklenen çocuğu bulur. Kapasitesi 2 olan anaokuluna üçüncü çocuk eklenemez ("Deneme 7 tamam"), kapasite 5'e çıkarıldıktan sonra çocuk yine bulunur ("Deneme 6 tamam").

Hoca bu örneği öğrencilerin sıfırdan kendilerinin yazmasını istedi. Soru metin olarak verilseydi şöyle olabilirdi: UML diyagramında verilen soyut sınıfı yazın, sonra ondan bir alt sınıf (örneğin `Toy`) yazın. Ardından `main` metodunu içeren ayrı bir sınıf yazın: bir anaokulu oluşturun, içine iki çocuk koyun, oyuncağın bu çocuklara uygun olup olmadığına bakın, kapasiteyi değiştirin, bir çocuğu çıkarın.

> **Hocanın vurgusu:** Yalnız UML diyagramına bakıp sınıfları yazmak yetmez. Programı sınayan ana programın mantık akışı (logic flow) adım adım metin olarak verildiğinde, o metinden yola çıkarak kodu yazabiliyor olmanız gerekir.

## 11. Normal Sınıflarla Kalıtım Tekrarı: Point ve Circle

Hoca bu örneği daha önce gösterip göstermediğini hatırlamadığı için normal sınıflarla kalıtımı bir kez daha gösterdi (`oop_fig94` paketi). Üst sınıf `Point` normal bir sınıftır. İki üye alanı vardır ve bunlar `protected` tanımlanmıştır. `protected`'ın avantajı, bu sınıftan türeyecek alt sınıfların metotlarının bu iki alana doğrudan erişebilmesidir. Sınıfta sıfır parametreli bir yapıcı (noktayı (0, 0)'dan başlatır) ve iki parametreli bir yapıcı (noktayı kullanıcı verir), bir `set` metodu ve `x` ile `y` değerleri için iki `get` metodu vardır.

Alt sınıf `Circle`'ın kodu (ekrandan, 01:20:00):

```java
package oop_fig94;
// Fig. 9.4: Circle.java
// Definition of class Circle

public class Circle extends Point {  // inherits from Point

   protected double radius;

   // No-argument constructor
   public Circle()
   {
      // implicit call to superclass constructor occurs here
      setRadius( 0 );
   }

   // Constructor
   public Circle( double r, int a, int b )
   {
      super( a, b );  // call to superclass constructor
      setRadius( r );
   }

   // Set radius of Circle
   public void setRadius( double r )
      { radius = ( r >= 0.0 ? r : 0.0 ); }

   // Get radius of Circle
   public double getRadius() { return radius; }

   // Calculate area of Circle
   public double area() { return Math.PI * radius * radius; }

   // convert the Circle to a String
   public String toString()
   {
      return "Center = " + "[" + x + ", " + y + "]" +
             "; Radius = " + radius;
   }
}
```

Burada normal bir sınıf normal bir sınıfı genişletir. `Circle`'ın kendine ait bir alanı (`radius`) vardır, ama `Point`'ten iki alanı da kalıtımla alır. Bu yüzden `Circle`'ın yapıcısında üç alanın hepsi başlatılmalıdır. `a` ve `b` için `super` ile üst sınıfın yapıcısı çağrılır, `radius` için `setRadius` kullanılır.

Hoca alanların değerlerini doğrudan atamak yerine metot kullanmayı tercih ettiğini vurguladı. `radius = r` de yazılabilirdi, ama değer atanırken yapılması gereken bir denetim varsa metot kullanılır. Burada böyle bir denetim vardır: `setRadius` yalnız 0.0'dan büyük ya da eşit değerleri kabul eder, değilse 0.0 atar. Aynı şekilde `Point`'te de `x` ve `y` doğrudan atanabilirdi, ama `setPoint` metodu kullanılmıştı; örneğin değerlerin belli bir aralıkta olması gibi bir koşul olabilirdi. Böyle bir koşul olmasa da metot kullanmak tercih edilmişti. Alan $\pi r^2$ formülüyle hesaplanır; ayrıca `toString` metodu vardır. Aynı paketteki bir test sınıfı bu kalıtım örneğini dener.

## 12. Arayüzler (Interfaces)

### 12.1 Neden arayüz?

Kalıtımın iki yolu konuşuldu: normal sınıflarla ve soyut sınıflarla. İkisinde de `extends` kullanıldı ve bir alt sınıf yalnız bir üst sınıfı genişletebildi; yani çoklu kalıtım desteklenmedi. Ama bazen bir sınıfın birden çok üst sınıfın özelliklerini taşıması gerekir. Bunun için arayüz kullanarak kalıtım yapılır.

Arayüz, içinde metot gövdesi olmayan, yalnız metot tanımları bulunan bir soyut sınıf gibi düşünülebilir. Arayüz tanımında `abstract class` yerine doğrudan `interface` sözcüğü kullanılır: `public interface Customer`. Yani normal sınıf için `class`, soyut sınıf için `abstract class`, arayüz için `interface` yazılır. UML'de arayüz, adının üstüne `<<interface>>` yazılarak gösterilir.

Bir alt sınıfın birden çok sınıfın yeteneğine sahip olması isteniyorsa, örneğin bir kişinin hem alım (`buy`), hem satım (`sell`), hem saklama (`keep`) yapabilmesi isteniyorsa arayüz kullanılır. Arayüzde yetenekler (capabilities) gruplara ayrılır ve birden çok yeteneğe sahip olmak isteyen alt sınıf bu arayüzleri uygular. Soyut sınıfta ise alt sınıf üst sınıfın bütün özelliklerini alır; üst sınıfta alt sınıfların ortak bazı özellikleri yazılabilir ve soyut sınıfın veri alanları olabilir. Arayüzde böyle bir şey yoktur: hiçbir metodun uygulaması yoktur. Bir sınıf birden çok arayüzü uyguluyorsa, her arayüzün sağladığı yetenekleri, yani metotları kendi içinde bulundurmalıdır.

### 12.2 Customer, Supplier, Friend örneği

Slayttaki tanım ve örnek (ekrandan, 01:25:00 ve 01:30:00):

- Arayüzler, üyesi olmayan soyut sınıflar gibi düşünülebilir. İstenirse yalnız `public final static` üye alanlar eklenebilir.
- Arayüz, adlandırılmış bir metot topluluğudur.

UML'de `<<interface>> Customer` (`+ buy( Good, int )`), `<<interface>> Supplier` (`+ sell( Good, int )`) ve `<<interface>> Friend` (`+ keep( Secret )`) kutuları vardır; `Person` sınıfı üçüne de kesikli çizgi ve içi boş üçgen uçla bağlanır.

```java
public interface Customer {
   public void buy( Good aGood, int quantity );
}
public interface Supplier {
   public void sell( Good aGood, int quantity );
}
public interface Friend {
   public void keep( Secret aSecret );
}
public class Person implements Customer,
            Supplier, Friend {
   public void buy( Good aGood, int quantity ) {
            //related code
   }
   public void sell (Good aGood, int quantity ) {
            // related code
   }
   public void keep( Secret aSecret ) {
            // related code
   }
}
```

Burada üç arayüz, yani üç üst tür vardır ve her birinin tanımında `interface` yazar. Gövdelerinde metotların yalnız tanımları vardır, gövdeleri yoktur; metotlarda `abstract` sözcüğü de kullanılmaz. Çünkü arayüzdeki bütün metotların alt sınıflarca yazılması gerektiği zaten bilinir. Soyut sınıfta ise yalnız `abstract` tanımlanmış metotların alt sınıfta yazılması gerekiyordu.

Alt sınıf tarafında `extends` yerine `implements` kullanılır ve ardından uygulanacak arayüzlerin adları virgülle yazılır. `Person` sınıfı üç arayüzü uygular; bu yüzden `buy`, `sell` ve `keep` metotlarının üçünü de yazmak zorundadır. Arayüzler, varlıkların sorumluluklarını gruplamak ve nesnelere birden çok görünüm (multiple views) vermek için kullanılır: `Person` nesnesi alan bir müşteri, satan bir tedarikçi ve sır tutan bir arkadaş olabilir.

### 12.3 Arayüz kuralları

Hoca arayüzlerle ilgili kuralları şöyle sıraladı:

- Arayüzdeki bütün metotların gövdeleri, arayüzü uygulayan alt sınıfta yazılmalıdır.
- Arayüzde normal üye alan tanımlanamaz; yalnız `public final static` alanlar olabilir (değişmeyen, sınıfa ait ve herkese açık).
- Arayüzde yalnız `public` metotlar tanımlanabilir; `private` ya da `protected` metot kullanılmaz.
- Arayüzlerin yapıcısı (constructor) yoktur.
- Bir sınıf birden çok arayüzü uygulayabilir.
- Kod geleneği olarak arayüz adı büyük `I` harfiyle başlatılabilir; zorunlu değildir.

> **Ek bilgi (derste anlatılmadı):** Derste anlatılan kurallar büyük olasılıkla arayüzlerin klasik (Java 7 ve öncesi) biçimidir. Java 8'den itibaren arayüzlerde gövdesi olan `default` ve `static` metotlar, Java 9'dan itibaren de `private` yardımcı metotlar yazılabilir. Arayüzde yazılan alanlar ise belirtilmese de her zaman `public static final` sayılır, metot tanımları da varsayılan olarak `public abstract`'tır.

## 13. Arayüz Tasarımı: Taşıt Vergileri

### 13.1 Gereksinim ve diyagram

Örnekte kişisel ve ticari olmak üzere iki tür taşıt vardır ve ikisi için farklı vergi ödenir. Slayttaki gereksinim (ekrandan, 01:35:00):

- Ticari ve kişisel taşıtların vergilendirilmesi farklıdır.
- Motosiklet, otomobil ve otobüs ticari taşıt olarak kaydedilebilir.
- Yalnız motosiklet ve otomobil kişisel taşıt olarak kaydedilebilir.
- Yalnız ticari taşıtların vergisi amortize edilebilir (indirimli olabilir).
- Ticari olsun ya da olmasın, farklı taşıtların (otomobil, otobüs vb.) vergi hesabı birbirinden çok farklıdır.
- Bu gereksinim nasıl modellenir?

UML diyagramı:

| Arayüz | Metotlar | Uygulayan sınıflar |
|---|---|---|
| `<<interface>> CommercialVehicle` | `+ getPlate( ) : String`, `+ calculateAmortizedTax( baseTax : double, currentYear : int ) : double` | `Motorcycle`, `Car`, `Bus` |
| `<<interface>> PersonalVehicle` | `+ getPlate( ) : String`, `+ calculateTax( baseTax : double ) : double` | `Motorcycle`, `Car` |

Slayttaki ipucu: Farklı taşıtlar için vergi hesabı benzer (yani parametreyle ayarlanabilir) olsaydı, arayüzler yerine tek bir soyut temel sınıf kullanmak daha iyi bir seçim olurdu.

Burada iki tür yetenek vardır: `CommercialVehicle`'ın sağladığı indirimli vergi hesabı (`calculateAmortizedTax`) ve `PersonalVehicle`'ın sağladığı vergi hesabı (`calculateTax`). `Car` ve `Motorcycle` iki arayüzü de uyguladığı için `calculateAmortizedTax` ve `calculateTax` metotlarını yazmak zorundadır; `getPlate` iki arayüzde de vardır, onu da yazarlar. `Bus` yalnız `CommercialVehicle`'ı uyguladığı için yalnız o arayüzün iki metodunu yazar.

### 13.2 Car sınıfı

`Car` iki arayüzü uyguladığı için içinde `getPlate`, `calculateTax` ve `calculateAmortizedTax` bulunmalıdır; bulunur, yani arayüzlerden gelen zorunluluk sağlanmıştır. Normal bir sınıf olduğu için başka metotları da vardır. Kodu (ekrandan, 01:40:00):

```java
package nyp07;
public class Car implements CommercialVehicle, PersonalVehicle {
    private String plate;
    private int modelYear;
    private double engineVolume;
    public Car(String plate, int modelYear, double engineVolume) {
          this.plate = plate; this.modelYear = modelYear;
          this.engineVolume = engineVolume;
    }
    public double calculateTax( double baseTax ) {
          return baseTax * engineVolume;
    }
    public double calculateAmortizedTax( double baseTax, int currentYear ) {
          //Tax can be reduced %10 for each year as amortization
          int age = currentYear - modelYear;
          if( age < 10 )
              return baseTax * engineVolume * (1-age*0.10);
          return baseTax * engineVolume * 0.10;
    }
    public String getPlate() { return plate; }
    public int getModelYear() { return modelYear; }
    public double getEngineVolume() { return engineVolume; }
}
```

Sınıfın üç üye alanı vardır: plaka, model yılı ve motor hacmi. Yapıcı bu üç değeri parametre olarak alıp alanları başlatır. Arayüzlerden gelen üç metodun dışında model yılı ve motor hacmi için iki `get` metodu yazılmıştır.

`calculateTax`, `PersonalVehicle` için yazılması gereken metottur ve vergiyi motor hacmine göre hesaplar: temel vergi çarpı motor hacmi. `calculateAmortizedTax` ise `CommercialVehicle` arayüzünden gelir ve indirimli vergiyi hesaplar: vergi her yıl için %10 azaltılabilir. Önce içinde bulunulan yıldan arabanın fabrikadan çıktığı yıl çıkarılarak yaşı bulunur. Yaş 10'dan küçükse yaşın her yılı için %10 düşülür ($\text{temel vergi} \times \text{motor hacmi} \times (1 - 0.10 \cdot \text{yaş})$). Yaş 10 ya da daha büyükse doğrudan tam verginin %10'u döndürülür.

Bir öğrencinin iki arayüzde aynı adlı metot olmasıyla ilgili sorusu bu noktada geldi; 14. bölümde anlatıldı.

### 13.3 Bus sınıfı

`Bus` UML diyagramında yalnız bir arayüzü uygular; içinde o arayüzden gelen iki metodu bulundurmalıdır: `calculateAmortizedTax` ve `getPlate`. İkisi de vardır, yani arayüzü uygulamaktan dolayı bir sorun yaşamaz. Bunların dışında kendi yapıcısı, kendi alanları ve iki alan için `get` metotları vardır. Kodu (ekrandan, 01:45:00):

```java
package nyp07;
public class Bus implements CommercialVehicle {
    private String plate;
    private int modelYear;
    private double tonnage;
    public Bus(String plate, int modelYear, double tonnage) {
          this.plate = plate; this.modelYear = modelYear; this.tonnage = tonnage;
    }
    public double calculateAmortizedTax( double baseTax, int currentYear ) {
          double ratioTonnage, ratioAge;
          if( tonnage < 1.0 )
              ratioTonnage = 1.0;
          else if( tonnage < 5.0 )
              ratioTonnage = 1.2;
          else if( tonnage < 10.0 )
              ratioTonnage = 1.4;
          else
              ratioTonnage = 1.6;
          ratioAge = (currentYear - modelYear) * 0.05;
          if( ratioAge > 2.0 )
              ratioAge = 2.0;
          return baseTax * ratioTonnage * ratioAge;
    }
    public String getPlate() { return plate; }
    public int getModelYear() { return modelYear; }
    public double getEngineVolume() { return tonnage; }
}
```

İndirimli vergide önce tonaj oranı bulunur: tonaj 1'in altındaysa 1.0, 1 ile 5 arasında 1.2, 5 ile 10 arasında 1.4, 10 ve üzerindeyse 1.6. Yaş oranı, otobüsün yaşı 0.05 ile çarpılarak bulunur ve 2'yi geçerse 2 alınır. İndirimli vergi temel vergi, tonaj oranı ve yaş oranının çarpımıdır; yani hem tonaj hem yaş dikkate alınır.

Hoca formüllerin ayrıntısına takılmamayı söyledi: sınavda böyle bir soru sorulursa `calculateAmortizedTax` metodunun nasıl hesaplanacağı metinle açıklanır. Burada önemli olan, arayüzden gelen `calculateAmortizedTax` metodunun alt sınıfta yazıldığını görmektir. `Car`'da iki farklı arayüzden gelen metotlar vardı; bu yüzden hem `calculateTax` hem `calculateAmortizedTax` yazıldı. `Bus`'ta yalnız `calculateAmortizedTax` yazıldı.

Slayttaki `Bus` sınıfında tonajı döndüren `get` metodunun adı `getEngineVolume` olarak kalmıştır; hoca buna değinmedi.

## 14. İki Arayüzde Aynı Adlı Metot ve Arayüzler Arası Kalıtım

**Soru:** İki farklı arayüzde aynı adlı metotlar olursa, bunları alt sınıfta yazarken hata alır mıyız? **Cevap:** Hayır. Örnekte `getPlate` iki arayüzde de vardır ve `Car`'da bir kez yazılması bir sorun çıkarmamıştır. Arayüz alt sınıfa "içine ne yazacağın benim için fark etmez, ama şu adlı ve şu dönüş türlü bir metodun mutlaka olacak" der. İki arayüzde aynı adlı metot olması, "benden aldığında `getPlate`'i şöyle, diğerinden aldığında başka türlü yaz" anlamına gelmez; yalnız böyle bir metodun olmasını ister. İki metodun farklı biçimde yazılması isteniyorsa arayüzlerdeki adları farklı olmalıdır ki alt sınıfı yazan kişi bunlara farklı uygulamalar yazabilsin.

İki arayüzde aynı metot tutulmak istenmezse bir arayüz başka bir arayüzden kalıtım alabilir. Bu durumda arayüzlerde ortak bulunan metot bir üst arayüze çıkarılabilir. Derste gösterilen kodda `getPlate` bir `Vehicle` arayüzüne taşınmıştı; bu arayüzün tek metodu vardır ve `PersonalVehicle` ile `CommercialVehicle` onu `extends` ile genişletir. Bir arayüz başka bir arayüzü genişletirken, soyut sınıflardaki gibi `extends` sözcüğü kullanılır. Ardından `Bus`, `CommercialVehicle`'ı; `Car`, hem `CommercialVehicle` hem `PersonalVehicle`'ı uygular.

> **Ders sonrası not:** Hoca bir arayüzün yalnız bir arayüzü genişletebileceğini ve `extends`'ten sonra tek bir ad gelmesi gerektiğini söyledi. Doğrusu: tek üst sınıf kuralı sınıflar içindir; Java'da bir arayüz birden çok arayüzü genişletebilir, örneğin `interface PV extends Vehicle, Taxable { }` geçerlidir (ajan tarafından derlenip çalıştırıldı).

## 15. Arayüz mü Soyut Sınıf mı?

Hoca arayüz ile soyut sınıf arasındaki farkları tekrarladı. Java ve diğer nesne yönelimli diller sınıf düzeyinde çoklu kalıtımı desteklemez; nedeni elmas kalıtım problemidir. Ama bir sınıf birden çok farklı sınıfın yeteneğine sahip olmak istiyorsa arayüz kullanılır. Arayüz kullanıldığında üstteki türün metotları arayüzde kesinlikle yazılmaz. Arayüzün bütün metotları soyut metot olarak gelir, ama `abstract` sözcüğü kullanılmaz.

Soyut sınıf ise alt sınıfların kullandığı ortak metotlar varsa anlamlıdır: bu metotlar soyut üst sınıfta normal metot olarak gövdeleriyle yazılır, alt sınıflarda farklılık gösteren metotlar ise soyut tanımlanır. Yani soyut sınıfın hem normal hem soyut metotları vardır. Ama soyut sınıfla kurulan kalıtımda da alt sınıf birden çok sınıfın yeteneğini paylaşamaz, birden çok sınıfı genişletemez.

Değişiklik açısından da fark vardır. Arayüzü uygulayan sınıf arayüzün bütün metotlarını yazmak zorunda olduğu için arayüzde yapılan en küçük değişiklik, örneğin bir metodun dönüş türünü değiştirmek, altındaki bütün sınıfların çalışmasını etkiler. Soyut sınıfta bir değişikliğe, örneğin yeni bir metoda ihtiyaç duyulursa soyut sınıfa bir normal metot eklenir; böylece alt sınıfların ilgili metotlarını değiştirmek gerekmez.

Slayttaki karşılaştırma (ekrandan, 01:50:00; slayt 131):

- Java sınıf düzeyinde çoklu kalıtımı desteklemez; her sınıf yalnız bir üst sınıfı genişletebilir, ama birden çok arayüzü uygulayabilir. Bu yüzden çoğu zaman arayüzler sınıf hiyerarşisinin temelini oluşturmak ve birden çok görünüm sağlamak için iyi bir seçimdir.
- Çok sayıda metot varsa soyut sınıf daha yararlıdır, çünkü bütün alt sınıflar için ortak olan metotlara varsayılan bir uygulama sağlanabilir. Ayrıca alt sınıfların belirli bir metodu yazması gerekmiyorsa yazmayabilirler; arayüzde ise kullanılmasa ve gövdesi boş bir blok olsa bile alt sınıf bütün metotları yazmak zorundadır.
- Temel sınıf sürekli değişiyorsa arayüzler sorun çıkarabilir, çünkü bütün uygulayan sınıfları değiştirmeden arayüze yeni metot eklenemez. Soyut sınıfta varsayılan bir uygulama verilip yalnız yeni metodu gerçekten kullanacak sınıflar değiştirilebilir.
- "A bir B'dir" (A is a B) denebiliyorsa soyut sınıf ve kalıtım, "A şunu yapabilir" (A is capable of [doing] as...) denebiliyorsa arayüz kullanılır.

**Soru:** `abstract` yerine overriding kullanılabilir mi? **Cevap:** Hoca bunun derse başında başka bir öğrencinin sorduğu soruya benzediğini söyledi. `abstract` ile override birbirinin yerine geçen şeyler değildir. Override, üst sınıftaki aynı metodu alt sınıfta yeniden yazmak demektir; üstteki metot normal de soyut da olabilir. Overload ise bir sınıf içindeki bir metodu aynı adla, farklı bir imzayla yazmaktır. Üstteki metot `abstract` sözcüğüyle tanımlanmışsa bunun anlamı, bu metodun aşağıda mutlaka override edilmesi gerektiğidir. Yani override `abstract`'ın yerine kullanılmaz.

**Soru:** Farklı arayüzlerde farklı işler yapan metotları farklı adlarla tanımlayabileceğimizi söylediniz. Parametrelerini farklı yaparak overloading gibi de yapabilir miyiz? **Cevap:** Evet; imzalar birbirinden farklı olduktan sonra yapılabilir.

Hoca seçimi şöyle bir düşünme biçimine bağladı: soyut sınıflar ve kalıtım kullanılıyorsa alt ve üst sınıf arasındaki ilişki "A bir B'dir" (is-a) ilişkisidir. Arayüz kullanılıyorsa "alt sınıf üstteki türün şu yeteneğini kullanıyor" diye düşünülür: `Bus` ya da `Car` sınıfı ticari taşıt ya da kişisel taşıt yeteneğini içerir. Soyut sınıfla yapıldığında ise üstteki türün yalnız yeteneği alınmaz, bütün özellikleri, veri alanları ve üye metotları da alınır; bu yüzden "is-a" diye düşünülür.

## 16. Arayüzle Kalıtım Örneği: Shape, Point, Circle, Cylinder

### 16.1 Shape ve Point

Hoca Eclipse'te `interfaceExample` paketindeki örneğe geçti. `Shape` arayüzünün üç metodu vardır: `area`, `volume` ve `getName`. Arayüzü tanımlarken dikkat edilmesi gereken nokta, `class` sözcüğünün kullanılmamasıdır. Arayüz bir tür sınıftır, ama Java onu yalnız `interface` sözcüğüyle tanımlar.

> **Hocanın vurgusu:** Sınavda `interface class Shape` gibi hatalar yapılıyor ve bunlar puan götürüyor. Arayüz tanımlanırken yalnız `interface` sözcüğü kullanılır. Arayüzdeki bütün metotlar zaten soyut olduğu için metotlara `abstract` eklenmez; geçen yıllarda yapılan bu hata da puan götürür. Arayüzdeki metotların kesinlikle gövdesi yoktur; arayüzün içinde metot gövdesi yazılırsa arayüz kavramı anlaşılmamış demektir ve bu da puan götürür.

Böylece üç tür kalıtım öğrenilmiş oldu: normal sınıflarla, soyut sınıflarla ve arayüzlerle.

`Point` sınıfı `Shape`'i uygular (ekrandan, 02:00:00):

```java
package interfaceExample;

public class Point implements Shape {

    protected int x, y;

    public Point() {
        // no code necessary
     }

    public Point(int x, int y){
        this.x = x;
        this.y = y;
      }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public double area() {
        return 0.0;
    }

    public double volume() {
        return 0.0;
    }

    public String getName() {
        return "Point";
    }
}
```

Burada `extends` sözcüğü yoktur, çünkü üstteki tür bir arayüzdür.

> **Hocanın vurgusu:** Bir arayüzü uygularken `extends` yazmak da puan kaybettirir; `implements` yazılmalıdır.

`Point` bir arayüzü uygulayan normal bir sınıftır. İki `protected` alanı, sıfır ve iki parametreli yapıcıları, `x` ve `y` için `set` ve `get` metotları ve arayüzden gelen `area`, `volume` ve `getName` metotları vardır.

### 16.2 Circle ve Cylinder

`Circle`, normal bir sınıf olan `Point`'i genişletir. Bir `protected` alanı daha (`radius`), varsayılan bir yapıcısı ve üç parametreli bir yapıcısı, `radius` için `get` ve `set` metotları, `area` ve `getName` metotları vardır. `Shape` kendisinden türeyen sınıfın üç metodu yazmasını ister; `Point` üçünü de yazmıştır. `Point`'i genişleten `Circle` ise `getName` ve `area` metotlarını override etmiş, `volume` metodunu yukarıdan, `Point`'ten almaya devam eder. `Circle` normal bir sınıfı genişleten normal bir sınıf olduğu için yalnız override etmesi gerekenleri override eder, diğerlerini üst sınıftan kullanır.
<!-- BELİRSİZ: interfaceExample paketindeki Circle sınıfının kodu karelerde görünmüyor; yalnız altyazıdaki anlatımla aktarıldı. -->

`Cylinder` ise `Circle`'ı genişletir; bu kalıtım ağacındaki üçüncü alt sınıftır. Kodu (ekrandan, 00:55:00):

```java
package interfaceExample;

public class Cylinder extends Circle {

    private double height;

    public Cylinder() {

    }

    public Cylinder(double h, double r, int x, int y) {
        this.height = h;
        this.radius = r;
        this.x = x;
        this.y = y;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double area() {
        return 2*super.area() + 2*Math.PI*radius*height;
    }

    public double volume() {
        return super.area()*height;
    }

    public String getName() {
        return "Cylinder";
    }
}
```

`Cylinder`'ın kendi alanı `height`'tır. Dört parametreli yapıcıda `height` kendi alanıdır, `radius` üst sınıfından (`Circle`), `x` ve `y` ise üst sınıfının üst sınıfından (`Point`) gelen alanlardır; hepsi burada başlatılır. `height` için `get` ve `set` metotları vardır ve `area` ile `volume` metotları override edilir. `Circle`'da doğrudan bir `volume` metodu yoktu; `Circle` onu `Point`'ten kalıtımla aldığı için `Circle`'da da bir `volume` metodu varmış gibi düşünülür. `Cylinder` ise `volume` metodunu yeniden tanımlar. Silindirin yüzey alanı iki taban alanı ile yan yüzey alanının toplamıdır ($2\pi r^2 + 2\pi r h$), hacmi taban alanı çarpı yüksekliktir ($\pi r^2 h$); `super.area()` `Circle`'ın daire alanını verir.

**Soru:** `Cylinder`'da `x` ve `y`'yi `super` kullanmadan doğrudan yazabilmemizin nedeni onları `protected` tanımlamamız mı? **Cevap:** Evet. `Point`'te bu alanlar `private` tanımlansaydı onlara yalnız bu sınıfın sağladığı metotlarla, yani `set` ve `get` ile ulaşılabilirdi. `protected` tanımlandığında hem bu sınıf hem de alt sınıfları üst sınıfın alanlarına doğrudan ulaşabilir; `protected`'ın tek avantajı budur. Kalıtım ağacının dışındaki sınıfların nesneleri bu alanlara doğrudan ulaşamaz; değerleri `Point`'in `public` metotlarıyla alıp değiştirmek zorundadırlar.

> **Ek bilgi (derste anlatılmadı):** Java'da `protected` üyeler alt sınıflara ek olarak aynı paketteki bütün sınıflardan da erişilebilir. Bu yüzden "kalıtım ağacı dışındaki sınıflar erişemez" kuralı tam olarak farklı paketteki sınıflar için geçerlidir; derste kullanılan sınıflar aynı paketteyse büyük olasılıkla doğrudan erişim de derlenir.

### 16.3 Test sınıfı

Test sınıfı bu kalıtım ağacındaki nesneleri kullanır (ekrandan, 02:05:00):

```java
package interfaceExample;

public class Test {

    public static void main(String[] args) {

        Point point = new Point(4, 5);

        Circle circle = new Circle(3.5, 4, 5);

        Cylinder cylinder = new Cylinder(5, 3.5, 4, 5);

        Shape arrayOfShapes [];

        arrayOfShapes = new Shape[3];

        arrayOfShapes[0] = point;
        arrayOfShapes[1] = circle;
        arrayOfShapes[2] = cylinder;

        String output = "";

        for (int i = 0; i < arrayOfShapes.length; i++) {
            output += "\n" + arrayOfShapes[i].getName() + " : " +
                        "\nArea" + " : " +
                        arrayOfShapes[i].area() +
                        "\nVolume" + " : " +
                        arrayOfShapes[i].volume();
        }

        System.out.println(output);

    }
}
```

`new` ile bir `Point` nesnesi oluşturulur ve referansı `Point` türündeki bir değişkene atanır; aynı biçimde `Circle` ve `Cylinder` nesneleri kendi türlerindeki değişkenlere atanır. Ardından `Shape` türünde bir dizi tanımlanır. Demek ki bir arayüz de, soyut sınıf ve normal sınıf gibi, bir değişkenin ya da dizinin türü olabilir. Dizi `new` ile bellekte oluşturulur.

> **Hocanın vurgusu:** `new Shape[3]` ile dizinin üç hücresi oluşur, ama hiçbiri henüz nesne içermez. Sınavda bu satırda nesnelerin de oluşturulduğu sanılıyor; hayır, bu yalnız `Shape` türündeki üç nesneyi tutmak için oluşturulmuş bir dizidir.

Dizinin ilk hücresine `point` atanır. `Point` `Shape`'i uyguladığı için `Shape`'in alt türüdür; dolayısıyla `Point` aynı zamanda `Shape` türündedir. Kalıtım konuşulurken söylendiği gibi: "A child object can be used whenever the parent is expected", yani üst tür beklenen her yerde alt sınıfın nesnesi kullanılabilir. Burada üst tür (bir arayüz) beklenmektedir; arayüzün nesnesi olmaz, ama onun alt sınıflarının nesneleri buraya atanabilir. Bellekte oluşturulan nesne alt sınıfın nesnesidir; ona istenirse kendi türündeki bir referansla, istenirse üst türündeki bir referansla ulaşılır. Önce alt sınıfların referanslarıyla nesnelere ulaşıldı, sonra bu nesnelerin referansları kalıtım ağacının en üstündeki türdeki dizi hücrelerine (0, 1 ve 2) atandı. Ardından döngüde üç nesnenin hepsinin sahip olduğu `getName`, `area` ve `volume` metotları çağrılır ve her nesnenin kendi metodunun sonucu gösterilir.

**Soru:** İlk satırda `Point point = new Point(4, 5);` yerine `Shape point = new Point(4, 5);` yazsak da olur muydu? `Shape` bir üst sınıf gibi davranır mı? **Cevap:** Hoca "hemen deneyelim" dedi ve aynı kuralı hatırlattı: üst tür beklenen her yerde alt sınıfın nesnesi kullanılabilir; oluşturulan nesneye alt sınıfın kendi türündeki ya da üst türdeki bir referansla ulaşılabilir. Yani bu yazım geçerlidir.

Ajan `Test` programını derste gösterilen sınıflarla çalıştırdı (`interfaceExample` paketindeki `Circle`'ın alanı $\pi r^2$ kabul edildi). Çıktı: `Point` için alan 0.0 ve hacim 0.0; `Circle` için alan yaklaşık 38.4845 ($\pi \cdot 3.5^2$) ve hacim 0.0 (`Point`'ten kalıtımla); `Cylinder` için alan yaklaşık 186.9248 ($2 \cdot 38.4845 + 2\pi \cdot 3.5 \cdot 5$) ve hacim yaklaşık 192.4226 ($38.4845 \cdot 5$). `Shape point = new Point(4, 5);` satırı da derlenip çalıştı.

## 17. Normal Sınıflarla Kalıtım Örneği: acc ve accBusiness

Hoca normal sınıflarla kalıtıma bir örnek daha gösterdi. `acc` normal bir sınıftır (ekrandan, 02:10:00):

```java
package temp;

public class acc
{
    protected String name;
    protected double balance = 0;

    public acc(String n, double depAcc)
    {
        name = n;
        balance = depAcc;
    }

    public double getBalance()
    {
        return balance;
    }

    public double withdraw(double wdAcc)
    {
        balance -= wdAcc;
        return balance;
    }

    public double deposit(double depAcc)
    {
         balance += depAcc;
         return balance;
    }

}
```

`acc` içinde iki `protected` alan, bir yapıcı, bir `get` metodu ve `withdraw` ile `deposit` metotları vardır. `accBusiness` sınıfı `acc`'yi genişletir. `getBalance`, `withdraw` ve `deposit` metotlarının hiçbirini override etmez; bunları üst sınıftan kullanır. Kendi yapıcısında üst sınıfın yapıcısını çağırır; üst sınıfın alanlarını başlatırken `super` kullanılır. Yalnız bu sınıfa özgü olan faiz hesabı metodunu kendisi yazar.
<!-- BELİRSİZ: accBusiness sınıfının kodu karelerde görünmüyor; faiz metodunun adı altyazıda "interest ball" diye geçiyor ve doğrulanamadı. -->

## 18. Hangisini Nasıl Seçeriz? Öğrenci Sorusu

**Soru:** Arayüz ve soyut sınıf dışarıdan bakınca aynı işi yapıyor gibi görünüyor. Yaptığımız örneklerde hangisini kullanacağımızı, arayüz kullanmamız gereken yeri nasıl anlarız? **Cevap:** Önce bir üst sınıf altında birbirine benzeyen sınıflar arasında kalıtım ilişkisi kurulacağı anlaşılır. Sonra üst sınıfa bakılır. Örneğin `Person`'dan `Patient` ve `Doctor` adlı iki alt sınıf üretilecek olsun. `Person` içinde, gövdesi hem doktor hem hasta için aynı olan metotlar varsa aynı kodu iki alt sınıfta yazmak yerine üst sınıfta yazmak tercih edilir. Böyle ortak uygulamalı metotların sayısı fazlaysa kalıtımda soyut sınıf kullanılır; yalnız alt sınıflarda farklılık gösteren ve alt sınıflarda mutlaka bulunması gereken metotlar soyut tanımlanır. Bu, soyut sınıf kullanmak için iyi bir karar ölçütüdür.

Arayüzde ise böyle bir durum yoktur: üstte ortak yazılacak metot sayısı azdır ya da hiç yoktur ve alt sınıfın birden çok farklı üst türün yeteneğini içermesi gerekir. Taşıt örneğinde olduğu gibi, kişisel taşıt ve ticari taşıt yeteneklerinin ikisini birden taşıması gereken sınıflar vardır.

Hoca kodlama yaparken bir sınıfın metotlarının birbiriyle ve sınıfın asıl amacıyla uyumlu olmasının istendiğini de ekledi. Bir ticari taşıt sınıfı yazılırken içine ticari taşıtla ilgisi olmayan, kişisel taşıta ait bir metot yazılmak istenmez. Bu yüzden yetenekler gruplara ayrılır ve farklı türler yaratılır; bir sınıfın birden çok gruba ait yeteneklere sahip olması gerekiyorsa arayüz tercih edilir. Soyut sınıfın arayüzden en büyük farkı ise şudur: üstteki tür bazı ortak metotlar içeriyorsa ve bunların uygulaması bir kez yazılarak toplam kod miktarı azaltılmak isteniyorsa soyut sınıf tercih edilir. Örneklerle çalıştıkça normal sınıf, soyut sınıf ya da arayüzle kalıtım seçimi daha rahat görülecektir.

## 19. Taşıt Kayıt Sistemi ve Alıştırma

Taşıt örneğinde `Car`, `Bus` ve `Motorcycle` vardı; `Car` ve `Bus`'ın kodları gösterildi. Derste gösterilen kodda `getPlate` yukarıda anlatıldığı gibi `Vehicle` arayüzüne taşınmıştı. Ayrıca bir `VehicleRegistrationSystem` sınıfı vardır. Galeri-araba ve anaokulu-çocuk örneklerine benzer biçimde taşıtları bir kayıt sisteminde tutar. Kodu (ekrandan, 02:15:00):

```java
package nyp07;

/* Class code is incomplete.
 * No need to dwell on arrays as we will move on to generic lists and maps. */
public class VehicleRegistrationSystem {
    private CommercialVehicle commercialVehicles[];
    private PersonalVehicle personalVehicles[];

    public CommercialVehicle searchCommercialVehicle( String plate ) {
        for( CommercialVehicle vehicle : commercialVehicles )
            if( vehicle.getPlate().equalsIgnoreCase(plate) )
                return vehicle;
        return null;
    }

    public boolean registerCommercialVehicle( CommercialVehicle vehicle ) {
        if( searchCommercialVehicle(vehicle.getPlate()) != null )
            return false;
        return true;
    }

}
```

Sınıfta `CommercialVehicle` ve `PersonalVehicle` türünde iki dizi vardır, yani bu dizilere arayüz türündeki nesneler eklenebilir. Bir arama ve bir kayıt metodu yazılmıştır. Dosyanın başındaki yorum, kodun tamamlanmadığını ve ileride genel (generic) listelere ve eşlemlere (maps) geçileceği için dizilerle fazla uğraşmaya gerek olmadığını söyler.

> **Ders sonrası not:** Hoca kişisel taşıtların bir `ArrayList`'te tutulduğunu söyledi; ekrandaki kodda iki alan da dizidir (`PersonalVehicle personalVehicles[]`). Ayrıca `registerCommercialVehicle` yalnız plakanın kayıtlı olup olmadığını denetler, taşıtı diziye eklemez; kodun tamamlanmadığı yorumda da belirtilmiştir.

Test için bir vergi hesaplama örneği sınıfı vardır. Orada yeni bir otobüs ve otomobil oluşturulur; örneğin bir `Car` nesnesi oluşturulup referansı `CommercialVehicle` türündeki bir değişkene atanır. Bu, az önce konuşulan kuralın uygulamasıdır: alt sınıfın nesnesine üst türdeki bir referansla ulaşılır.

> **Hocanın vurgusu:** Temelde dizi veri yapısı üzerinde ekleme, arama ve çıkarma metotlarını sorunsuz yazabilmeniz gerekir; sınavda karşınıza çıkar. Kayıt sisteminde eksik kalan kısımları (yeni ticari ve kişisel taşıt ekleme, çıkarma, kayıt sistemini oluşturan ve içine otomobil, otobüs, motosiklet koyup arama, ekleme ve çıkarma yapan bir `main` programı) kendiniz yazın.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:52): Soyut bir üst sınıftaki `print` metodunu alt sınıfta yazarken bir override anahtar sözcüğü kullanmak gerekir mi?

> **Çözüm (derste verilen):** Hayır. Override ve overload Java'nın anahtar sözcükleri değil, kavramlardır. Alt sınıftaki metot üstteki metotla aynı imzaya sahipse onu override eder; bunun için ayrı bir sözcük yazılmaz. (İsteğe bağlı `@Override` ek açıklaması için 5. bölümdeki ek bilgiye bakın.)

**Soru 2** (derste sözlü, 01:12:43): `Kindergarten.removeChild` metodunda çıkarılan elemandan sonrakiler birer sola kaydırıldıktan sonra dizinin son hücresini `null` yapmak gerekir mi?

> **Çözüm (derste verilen):** Evet, yapılması iyi olur; sonda eski bir referans kalır. Ayrıca `childCount` bir azaltılmalıdır. Eleman sayısı `childCount` ile izlendiği için o hücre programın doğru çalışmasını bozmaz, ama `null` yapılması önerildi.

**Soru 3** (derste sözlü, 01:41:50): İki farklı arayüzde aynı adlı metotlar varsa, ikisini birden uygulayan sınıfta hata alınır mı?

> **Çözüm (derste verilen):** Hayır. `getPlate` hem `CommercialVehicle` hem `PersonalVehicle`'da vardır ve `Car`'da bir kez yazılması yeterlidir. Arayüz yalnız belirli ad ve dönüş türünde bir metodun bulunmasını ister. Farklı uygulamalar isteniyorsa metot adları ya da imzaları farklı olmalıdır; ortak metot bir üst arayüze (`Vehicle`) de taşınabilir.

**Soru 4** (derste sözlü, 01:51:43): Bir metodu `abstract` tanımlamak yerine alt sınıfta override etmek kullanılabilir mi?

> **Çözüm (derste verilen):** Hayır, ikisi birbirinin yerine geçmez. Override, üstteki (normal ya da soyut) metodu alt sınıfta yeniden yazmaktır. `abstract` ise o metodun alt sınıfta mutlaka override edilmesi gerektiğini söyler.

**Soru 5** (derste sözlü, 01:53:12): Farklı arayüzlerdeki, farklı işler yapacak metotlar ad değiştirmek yerine farklı parametrelerle (overloading gibi) ayrılabilir mi?

> **Çözüm (derste verilen):** Evet; imzaları birbirinden farklı olduğu sürece yapılabilir.

**Soru 6** (derste sözlü, 02:05:01): `Test` programında `Point point = new Point(4, 5);` yerine `Shape point = new Point(4, 5);` yazılabilir mi?

> **Çözüm (derste verilen, ajan çalıştırarak doğruladı):** Evet. Üst tür beklenen her yerde alt sınıfın nesnesi kullanılabilir; arayüzün nesnesi oluşturulamaz, ama arayüz türündeki bir değişken onu uygulayan sınıfın nesnesini gösterebilir. Ajanın denemesinde `Shape p2 = new Point(4, 5);` derlendi ve `p2.getName()` "Point" döndürdü.

**Soru 7** (derste sözlü, 02:08:12): `Cylinder` yapıcısında `x` ve `y`'ye `super` kullanmadan doğrudan değer atanabilmesinin nedeni bu alanların `protected` olması mıdır?

> **Çözüm (derste verilen):** Evet. `private` olsalardı yalnız `Point`'in `get`/`set` metotlarıyla erişilebilirdi. `protected` alanlara alt sınıflar doğrudan erişir; kalıtım ağacı dışındaki sınıflar ise `public` metotları kullanmak zorundadır.

**Soru 8** (derste sözlü, 02:11:30): Bir tasarımda arayüz mü soyut sınıf mı kullanılacağına nasıl karar verilir?

> **Çözüm (derste verilen):** Alt sınıfların ortak kullanacağı, gövdesi üstte bir kez yazılabilecek çok sayıda metot varsa soyut sınıf seçilir; yalnız farklılaşan metotlar soyut bırakılır (örneğin `Person` altında `Patient` ve `Doctor`). Ortak uygulama az ya da hiç yoksa ve bir sınıfın birden çok türün yeteneğini taşıması gerekiyorsa (örneğin hem ticari hem kişisel taşıt) arayüz seçilir. Kısaca "is-a" için soyut sınıf, "is capable of" için arayüz.

**Soru 9** (ekrandan, 02:15:00; derste alıştırma olarak verildi): `VehicleRegistrationSystem` sınıfını dizi kullanarak tamamlayın: ticari ve kişisel taşıt ekleme (aynı plaka iki kez eklenmesin), arama ve ticari taşıt çıkarma metotlarını yazın.

> **Çözüm (derste verilmedi):** Aşağıdaki çözüm ajan tarafından yazıldı ve derste gösterilen `Car` ve `Bus` sınıflarıyla (`getPlate` `Vehicle` arayüzünde) `java` ile çalıştırılarak denendi: iki taşıt eklendi, aynı otomobilin ikinci kez eklenmesi `false` döndürdü, küçük harfle yazılan plaka bulundu, çıkarılan otomobil sonra aramada `null` verdi.

```java
public class VehicleRegistrationSystem {
    private CommercialVehicle commercialVehicles[];
    private PersonalVehicle personalVehicles[];
    private int commercialCount, personalCount;

    public VehicleRegistrationSystem(int capacity) {
        commercialVehicles = new CommercialVehicle[capacity];
        personalVehicles = new PersonalVehicle[capacity];
    }
    public CommercialVehicle searchCommercialVehicle( String plate ) {
        for( int i = 0; i < commercialCount; i++ )
            if( commercialVehicles[i].getPlate().equalsIgnoreCase(plate) )
                return commercialVehicles[i];
        return null;
    }
    public boolean registerCommercialVehicle( CommercialVehicle vehicle ) {
        if( vehicle == null || commercialCount == commercialVehicles.length
                || searchCommercialVehicle(vehicle.getPlate()) != null )
            return false;
        commercialVehicles[commercialCount++] = vehicle;
        return true;
    }
    public CommercialVehicle unregisterCommercialVehicle( String plate ) {
        for( int i = 0; i < commercialCount; i++ ) {
            if( commercialVehicles[i].getPlate().equalsIgnoreCase(plate) ) {
                CommercialVehicle removed = commercialVehicles[i];
                for( int j = i; j < commercialCount - 1; j++ )
                    commercialVehicles[j] = commercialVehicles[j+1];
                commercialCount--;
                commercialVehicles[commercialCount] = null;
                return removed;
            }
        }
        return null;
    }
    public PersonalVehicle searchPersonalVehicle( String plate ) {
        for( int i = 0; i < personalCount; i++ )
            if( personalVehicles[i].getPlate().equalsIgnoreCase(plate) )
                return personalVehicles[i];
        return null;
    }
    public boolean registerPersonalVehicle( PersonalVehicle vehicle ) {
        if( vehicle == null || personalCount == personalVehicles.length
                || searchPersonalVehicle(vehicle.getPlate()) != null )
            return false;
        personalVehicles[personalCount++] = vehicle;
        return true;
    }
}
```

Derste gösterilen `searchCommercialVehicle` dizinin bütün hücrelerini for-each ile dolaşıyordu; dizi tam dolu değilse `null` hücrede `getPlate()` çağrısı `NullPointerException` verir. Bu yüzden çözümde döngü sayaçla (`commercialCount`) sınırlandı.

## Dersin Toparlaması

Bu derste kalıtımın normal sınıflar dışındaki iki yolu işlendi. Soyut sınıf, nesnesi oluşturulamayan ve alt sınıflar için şablon görevi gören genel bir üst sınıftır. Alanları ve gövdesi olan normal metotları bulunabilir; gövdesi üst sınıfta yazılamayan metotlar soyut tanımlanır ve somut alt sınıflarda yazılmak zorundadır. `PrintDriver` ve çocuk eşyaları (`Item`, `Toy`, `Clothing`) örnekleri bunu gösterdi; alt sınıfların yapıcıları üst sınıfın `private` alanlarını `super(...)` ile başlattı. `Kindergarten` sınıfı üzerinden dizi tabanlı ekleme, arama, en büyüğü bulma, kapasite artırma ve çıkarma metotları tekrar edildi. Ayrıca bir ana programın metin olarak verilen akıştan yazılması gerektiği vurgulandı.

Sınıflarla çoklu kalıtım elmas problemi yüzünden yapılamadığından, bir sınıfa birden çok yetenek kazandırmak için arayüzler kullanılır. Arayüzlerde yalnız `public` metot tanımları ve `public final static` alanlar bulunur; yapıcı yoktur. Sınıflar arayüzleri `implements` ile uygular ve bütün metotlarını yazar. Taşıt vergisi örneğinde `Car` iki arayüzü, `Bus` tek arayüzü uyguladı; ortak `getPlate` metodu bir üst arayüze taşınabildi. Arayüz ile soyut sınıf arasındaki seçim için ölçüt "is-a" ile "is capable of" ayrımı, ortak kod miktarı ve tasarımın değişkenliği olarak özetlendi. `Shape`-`Point`-`Circle`-`Cylinder` örneği üç kalıtım türünü bir arada gösterdi ve arayüz türündeki bir dizinin farklı alt sınıf nesnelerini tutabildiği görüldü. Böylece nesneler arası ilişkiler tamamlandı; sonraki haftalarda daha çok örnek üzerinde çalışılacak ve diziler dışındaki yeni veri yapılarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
