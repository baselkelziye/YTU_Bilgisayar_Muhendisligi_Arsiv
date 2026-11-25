# Ders 18 Genişletilmiş Notu: ArrayList, HashMap ve İstisna Yönetimi (Exception Handling)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı ve java.util Veri Yapıları
- 2. ArrayList Sınıfı ve Jenerik Tanım
- 3. ArrayList Metotları
- 4. Jenerik Tür Parametresi Üzerine Soru-Cevap
- 5. ArrayListTest Örneği
- 6. Course ve Student Örneği: ArrayList ile
- 7. Vector ve İş Parçacığı Güvenliği
- 8. Map Yapıları: HashMap ve Hashtable
- 9. Course ve Student Örneği: HashMap ile
- 10. Veri Yapılarının Karşılaştırılması
- 11. MapTest: Tür Parametresiz HashMap
- 12. İstisna Yönetimine Giriş ve İstisna Sınıf Ağacı
- 13. try-catch, throws, Çoklu catch ve finally
- 14. ExceptionExample01: IOException ve finally
- 15. Kendi İstisna Sınıfını Yazmak: ImpossibleInfo
- 16. DivideByZeroWithExceptionHandling
- 17. Zincirleme İstisnalar: UsingChainedExceptions
- 18. UsingExceptions1: Yeniden Fırlatma ve finally
- Örnek Sorular

## 1. Dersin Planı ve java.util Veri Yapıları

Bir önceki derste bağlı liste (`LinkedList`) veri yapısı ve örnekleri işlenmişti. Bu derste sırasıyla `ArrayList`, ardından `HashMap` ve zaman kalırsa istisna yönetimi (exception handling) işlendi. Tür dönüştürme (typecasting) konusuna bu derste geçilmedi.

Hoca `java.util` paketinin sağladığı veri yapılarının kalıtım ağacını gösterdi. `LinkedList`, `List` adlı bir arayüzü (interface) gerçekler. `List` arayüzünü gerçekleyen başka sıradan (regular) sınıflar da vardır: `ArrayList` ve `Vector`. Önceki derste bağlı listenin metotları slaytlarda değil, kodlar üzerinde gösterilmişti. Bu derste kullanılacak `ArrayList` ise bir listeyi bir diziymiş gibi kullanmayı sağlayan metotlar sunar.

<!-- BELİRSİZ: 00:17:38 - 00:18:06 arası altyazı Whisper tekrarıdır; bu aralıktaki anlatım çıkarılamadı. -->

## 2. ArrayList Sınıfı ve Jenerik Tanım

Dizi (array) veri yapısında bir nesneyi diziye koyarken hücrenin indisini veririz: nesnenin dizinin ilk ya da son konumuna, ya da istenen bir konuma konacağını söyleyebiliriz. `ArrayList` de listeyi böyle, konum (indis) vererek kullanmayı sağlar.

Slayt 147'deki tanım şöyledir (ekrandan, 00:20:00):

- Java'da örnek bir liste gerçeklemesi: `java.util.ArrayList` sınıfı. Dizilere dayalıdır (based on arrays), tek bağlıdır (single-linked), thread-unsafe'tir.
- İlk değer verme: `ArrayList myList = new ArrayList();`
- Böyle bir tanımda düğümler `Object` örnekleridir. Bu yüzden düğüm nesnelerini kullanmak için tür dönüştürme (typecasting) zorunlu olur. Neyse ki "jenerik programlama" desteği JSE 5.0 ile geldi.
- Jenerik programlama, birçok farklı türdeki nesne için yeniden kullanılabilen kod yazmaktır. Örneğin `String` ve `File` nesnelerini toplamak için ayrı sınıflar yazmak ya da kullanmak istemezsiniz, buna gerek de yoktur. Tek bir `ArrayList` sınıfı her sınıftan nesneyi toplayabilir; bu, jenerik programlamanın bir örneğidir.
- `Person` örneklerini tutacak bir `ArrayList` oluşturma:

```java
ArrayList<Person> liste = new ArrayList<Person>();
```

Burada `liste` adlı bir `ArrayList` değişkeni tanımlanır, `new` ile bir `ArrayList` nesnesi oluşturulur ve nesnenin referansı bu değişkene atanır. Önemli olan, oluştururken bu listede `Person` türünden nesneler tutulacağının belirtilmesidir. `Person` belirtilmeseydi, yani nesne doğrudan `ArrayList` olarak oluşturulsaydı, içinde birden fazla farklı türde nesne tutulabilirdi. `Person` yazılınca bu listede yalnız `Person` türünde nesne tutulacağı söylenmiş olur.

> **Ders sonrası not:** Hoca `ArrayList`'in (ve `Vector`'ün) arka planda bağlı liste ile gerçeklendiğini, "bağlı listeyi diziymiş gibi kullanmayı" sağladığını söyledi. Doğrusu: `ArrayList` ve `Vector` arka planda bir dizi kullanır; slayttaki "Based on arrays" ifadesi de bunu söyler. `List` arayüzünü gerçeklemek bağlı liste kullanmak demek değildir. `ArrayList`'te rastgele erişimin hızlı, araya ekleme ve silmenin yavaş olması da (bkz. bölüm 10) dizi tabanlı olmasından gelir.

## 3. ArrayList Metotları

Slayt 148'de `ArrayList` sınıfının temel metotları listelenir (ekrandan, 00:25:00):

- `add( <T> object )`: listenin sonuna bir eleman (T türünden bir nesne) ekler.
- `<T> get( int i )`: i. elemanı döndürür. Hoca, listeyi bir diziymiş gibi kullanmayı sağlayan metodun bu olduğunu vurguladı.
- `int size( )`: listedeki eleman sayısını döndürür.
- Listenin tamamı for-each döngüsüyle kolayca gezilebilir.

Diğer metotlardan bir seçki:

- `ensureCapacity( int size )`: gerekirse bu `ArrayList` örneğinin kapasitesini artırır. `ArrayList` oluşturulurken kaç eleman tutulacağı söylenmez. `ensureCapacity` çağrılırsa listeye "şu kadar nesne tutacağım, bunlar için bellekte yer ayır" denmiş olur. Dizi oluştururken de baştan kaç nesne tutulacağı söylenir; burada bu metotla aynısı yapılabilir. Hoca `LinkedList`'te bu metodun olmadığını belirtti.
- `trimToSize( )`: kapasiteyi listenin o anki boyutuna indirir. Örneğin başta `ensureCapacity` ile 30 denmiş ama listede yalnız 10 nesne varsa, `trimToSize` kapasiteyi 10'a indirir.
- `set( int i, <T> element )`: belirtilen konumdaki elemanı verilen elemanla değiştirir. Listedeki bir elemanı güncellemek için indis verilir.
- `remove( int i )`: i. elemanı listeden siler.
- Geçerli boyut i'den küçükse `IndexOutOfBoundsException` fırlatılır (unchecked). Bu, dizide olmayan bir indise erişmeye çalışınca alınan hataya benzer; istisnalarla nasıl başa çıkılacağı dersin sonunda işlendi.

Böylece dizi, bağlı liste ve `ArrayList` üç farklı veri yapısı olarak görülmüş oldu.

## 4. Jenerik Tür Parametresi Üzerine Soru-Cevap

Hoca kodlara geçerken bir öğrenci soru sordu.

**Soru:** Az önceki slaytta bazı yerlerde "element", bazı yerlerde "object" yazıyordu. "Element" ilkel (primitive) türleri mi anlatıyor?

**Cevap:** `ArrayList` metotlarındaki "element" jenerik türdür; bir önceki derste konuşulduğu gibi, `ArrayList`'te herhangi bir nesne tutulabilir. `ArrayList` iki türlü kullanılabilir: içinde tutulacak türü baştan söylemek (ör. `Person` ya da `String`) ya da jenerik bırakmak.

Hoca bunu önceki derste kullanılan `Box` örneği üzerinde gösterdi ve öğrenciden `Box` yerine `ArrayList` düşünmesini istedi (ekrandan, 00:30:00):

```java
package oop02a2;

public class Box<T> {
    // T stands for "Type"
    private T t;

    public void set(T t) { this.t = t; }
    public T get() { return t; }

    public static void main(String []args){
        //When you create instance of this Box class you will
        //need to tell the compiler for what data type this will
        //be working on.

        Box<Integer> b1 = new Box<Integer>();
        b1.set(10);
        System.out.println("generic objects value = " + b1.get());

        Box<String> b2 = new Box<String>();
        b2.set("some string");
        System.out.println("generic objects value = " + b2.get());

        Box<Object> b3 = new Box<Object>();
        b3.set("some other string");
        System.out.println("generic objects value = " + b3.get());
        b3.set(20);
        System.out.println("generic objects value = " + b3.get());
    }
}
```

- `Box<Integer>` ile tanımlanan nesneye konacak bütün değerler `Integer` olmalıdır.
- `Box<String>` ile tanımlanana hep `String` konmalıdır.
- `Box<Object>` ile tanımlanana önce bir `String`, sonra bir `Integer` konabilir.
- Sınıf tanımındaki `T` yerine `E` ya da başka herhangi bir büyük harf de jenerik tür adı olarak kullanılabilir.

Bir veri yapısında birden fazla türde nesne kullanılmak isteniyorsa veri yapısı arka planda böyle, jenerik sınıf olarak tanımlanır. `LinkedList` ve `ArrayList` de böyle tanımlanmıştır. İstenirse hangi tür parametresinin geçirileceği açıkça söylenir, istenirse jenerik bırakılıp içine farklı türler konur.

## 5. ArrayListTest Örneği

Hoca `oop02a.ch20.fig20_02` paketindeki `ArrayListTest` sınıfını açtı (ekrandan, 00:35:00 ve 00:40:00). Kod şöyledir:

```java
public class ArrayListTest
{
   public static void main( String[] args )
   {
      // add elements in colors array to list
      String[] colors = { "MAGENTA", "RED", "WHITE", "BLUE", "CYAN" };
      ArrayList< String > list = new ArrayList< String >();

      for ( String color : colors )
         list.add( color ); // adds color to end of list

      // add elements in removeColors array to removeList
      String[] removeColors = { "RED", "WHITE", "BLUE" };
      ArrayList< String > removeList = new ArrayList< String >(); //default constructor

      for ( String color : removeColors )
         removeList.add( color );

      // output list contents
      System.out.println( "ArrayList: " );

      for ( int count = 0; count < list.size(); count++ )
         System.out.printf( "%s ", list.get( count ) );

      // remove from list the colors contained in removeList
      removeColors( list, removeList );

      // output list contents
      System.out.println( "\n\nArrayList after calling removeColors: " );

      for ( String color : list )
         System.out.printf( "%s ", color );
   } // end main

   // remove colors specified in collection2 from collection1
   private static void removeColors( List< String > list1,
      List< String > list2 )
   {
      // get iterator
      Iterator< String > iterator = list1.iterator();

      // loop while collection has items
      while ( iterator.hasNext() )
      {
         if ( list2.contains( iterator.next() ) )
            iterator.remove(); // remove current Color
      } // end while
   } // end method removeColors
} // end class CollectionTest
```

Hoca kodu adım adım anlattı:

- `colors` dizisi tek satırda oluşturulur ve değerleri atanır. Aynısı `new String[5]` deyip 0'dan 4'e kadar hücrelere tek tek atama yaparak da yapılabilirdi. Tek satırlık yazımda JVM, 5 elemanlı bir `String` dizisi oluşturup hücrelere bu değerleri atamak istendiğini anlar.
- `ArrayList<String>` oluşturulurken türün `String` olduğu baştan söylenir. Hoca, listenin tür parametresiz (`new ArrayList()`) de oluşturulabileceğini göstermek için 17. satırı anlık olarak değiştirdi (ekrandan, 00:35:00), sonra tür parametreli biçime döndü.
- `colors` üzerinde for-each döngüsüyle her eleman `add` ile listeye eklenir; `add` her seferinde listenin sonuna ekler: önce `MAGENTA`, sonra `RED`, sonra `WHITE` ve diğerleri.
- `removeColors` dizisi için ikinci bir `ArrayList` (`removeList`) oluşturulur ve aynı şekilde doldurulur.
- Klasik `for` döngüsünde `list.get(count)` ile, yani indis vererek liste gezilir. Hoca, `LinkedList`'te böyle bir erişim yapılmadığını, bağlı listede gezinmek için önceki derste `ListIterator` sınıfının kullanıldığını hatırlattı.
- `removeColors` metodunun iki parametresi `List<String>` türündedir. Metoda aslında `ArrayList` nesneleri geçirilir. Bu yapılabilir, çünkü bir sıradan sınıfın nesnesi ebeveyninin türüyle izlenebilir: `ArrayList`, `LinkedList` ve `Vector` hep `List` arayüzünü gerçekler, `List` bunların ebeveynidir. Hoca bunun zorunlu olmadığını, yalnız yapılabileceğini göstermek için örnekte böyle yazıldığını söyledi.
- `removeColors` içinde listeden bir `Iterator` alınır ve `hasNext()` ile liste gezilir. Birinci listedeki (beş elemanlı) her eleman ikinci listede (üç elemanlı) varsa birinci listeden çıkarılır: `RED`, `WHITE` ve `BLUE` çıkarılır.
- Sonra liste yeniden yazdırılır.

Ajan kodu `java` ile çalıştırdı; çıktı şöyledir:

```text
ArrayList: 
MAGENTA RED WHITE BLUE CYAN 

ArrayList after calling removeColors: 
MAGENTA CYAN 
```

> **Ek bilgi (derste anlatılmadı):** `removeColors` döngüsünde silme işlemi `list1.remove(...)` ile değil `iterator.remove()` ile yapılır. Bir koleksiyon for-each ya da iterator ile gezilirken koleksiyonun kendi `remove` metodu çağrılırsa büyük olasılıkla `ConcurrentModificationException` alınır; iterator'ın `remove` metodu ise bu durumda güvenli silme yoludur.

## 6. Course ve Student Örneği: ArrayList ile

Hoca, daha önce composition ilişkisiyle (bir dersin birden çok öğrencisi olabilir) modellenen `Course` ve `Student` örneğinin bu kez `ArrayList` ile yazılmış hâlini gösterdi (`oop02a` paketi).

### 6.1 Student Sınıfı

`Student`, `Course` içinde tutulacak nesnelerdir. İki üye alanı (`number` ve `name`), iki parametreli bir kurucusu ve getter metotları olan basit bir sınıftır (ekrandan, 01:35:00, `oop02b` paketindeki aynı sınıf):

```java
public class Student {
    private String number;
    private String name;

    public Student(String no, String name) {
        this.number = no;
        this.name = name;
    }
    public String getNumber() {
        return number;
    }
    public String getName() {
        return name;
    }
}
```

### 6.2 Course Sınıfı

`Course` sınıfının kodu şöyledir (ekrandan, 00:45:00 ve 00:50:00):

```java
package oop02a;
import java.util.*;

public class Course {
    private String code;
    private String name;
    private int capacity;

    private ArrayList<Student> students;

    public Course(String code, String name, int capacity) {
        this.code = code; this.name = name; this.capacity = capacity;
        students = new ArrayList<Student>();
    }

    public String getCode() { return code; }
    public String getName() { return name; }
    public int getCapacity() { return capacity; }

    public int getStudentCount() {
        return students.size();
    }

    public boolean addStudent( Student aStudent ) {
        if( getStudentCount() == capacity ||
                findStudent(aStudent.getNumber()) != null )
            return false;
        students.add(aStudent);
        return true;
    }

    public Student findStudent( String number ) {
        for( Student aStudent : students )
            if( aStudent.getNumber().compareTo(number) == 0 )
                return aStudent;
        return null;
    }

    public void increaseCapacity( int newCapacity ) {
        if( newCapacity <= capacity )
            return;
        capacity = newCapacity;
    }

    public void showClassList( ) {
        System.out.println("Class List of "+code+" "+name);
        System.out.println("Student#  Name, Surname");
        System.out.println("--------  ----------------------------");
        // for( Student aStudent : students ) ... (devamı karede görünmüyor)
    }
}
```

<!-- BELİRSİZ: showClassList metodunun for-each döngüsü gövdesi karede görünmüyor; altyazıya göre her öğrencinin numarası ve adı yazdırılır. -->

Hoca metotları tek tek anlattı:

- **Alanlar:** dersin kodu, adı ve kapasitesi; ayrıca `ArrayList<Student>`. Listede `Student` nesneleri tutulacağı baştan söylenir.
- **Kurucu:** üç parametrelidir. Kurucunun görevi her zaman üye alanlara ilk değer vermektir; `ArrayList` de burada başlatılır.

> **Hocanın vurgusu:** `ArrayList` alanı doğru tanımlandığı hâlde kurucuda doğru tür parametresiyle başlatılmazsa sınavda puan kırılıyor. Tanım `ArrayList<Student>` ise başlatma da `new ArrayList<Student>()` olmalıdır.

- **`getStudentCount`:** UML diyagramında verilen bu metot, `ArrayList`'in içindeki nesne sayısını döndüren `size()` ile yazılır.
- **`addStudent`:** Veri yapısına yeni veri eklenen her `add` metodunda iki denetim yapılmalıdır: (1) yapının kapasitesi en çok değere ulaşmış mı, (2) eklenecek nesne yapıda zaten var mı. Kapasite, `getStudentCount()` değerinin `capacity`'ye eşit olup olmadığıyla denetlenir. Varlık, UML diyagramındaki `findStudent` metoduyla denetlenir: öğrencinin numarası (`String`) verilir, dönen nesne `null`'dan farklıysa öğrenci zaten vardır. İki koşuldan biri doğruysa `false` döner. Değilse öğrenci `students.add(aStudent)` ile eklenir ve `true` döner.

> **Hocanın vurgusu:** Ekleme metotlarında bu girdi denetimi (hem kapasite hem varlık) yapılmazsa puan kaybediliyor.

- **`findStudent`:** For-each döngüsünde sağ tarafa veri yapısının değişken adı, sol tarafa yapıdaki nesnelerin türü ve bir yerel değişken adı yazılır. Her turda yapıdan bir nesne alınır, yerel değişkene atanır ve döngü gövdesinde kullanılır. Her öğrencinin `getNumber()` değeri parametredeki numarayla `compareTo` ile karşılaştırılır; eşitse `compareTo` 0 döndürür ve o nesnenin referansı döndürülür. Döngü hiçbir şey bulmadan biterse `null` döner.
- **`increaseCapacity`:** Bu örnekte sınıfın büyüklüğü `capacity` adlı bir tamsayı alanıyla izlenir. Başta 30 kişilik bir ders tanımlandıysa, dolup dolmadığı bu değerle denetlenir. Kapasite artırılmak istenirse bu metot çağrılır: yeni değer mevcut kapasiteden küçük ya da eşitse hiçbir şey yapmadan döner, büyükse kapasite güncellenir.
- **`showClassList`:** For-each ile listedeki bütün öğrencilerin numarası ve adı yazdırılır.

### 6.3 main Metodu

`main` içinde üç parametreli kurucuyla bir ders nesnesi oluşturulur ve referansı bir değişkene atanır. Bir öğrenci nesnesi oluşturulup derse eklenir. `addStudent` `true` ya da `false` döndürür; kod `if( !...addStudent(...) )` biçiminde yazıldığı için ekleme başarılıysa koşul yanlış olur ve uyarı yazdırılmaz, başarısızsa uyarı yazdırılır. Aynı öğrenci ikinci kez eklenmeye çalışılınca öğrenci zaten var olduğu için ekleme yapılmaz. Ardından ikinci, üçüncü ve dördüncü öğrenciler oluşturulup eklenir. Sonra belirli numaralı bir öğrenci aranır; öğrenci var olduğu için dönen nesne `null` değildir. Son olarak `showClassList` çağrılır.

<!-- BELİRSİZ: main metodunun kodu (öğrenci numaraları, kapasite ve dördüncü eklemenin sonucu) karelerde görünmüyor; hocanın dördüncü ekleme için söylediği sonuç altyazıdan net çıkmıyor. -->

Aynı örneğin dizi ile yazılmış bir sürümü de vardır. Hoca onu anlatmadı; dizilerin veri yapısı olarak kullanımı daha önce işlenmişti. İki sürüm karşılaştırılınca `ArrayList` kullanmanın kodu ne kadar sadeleştirdiği görülür.

## 7. Vector ve İş Parçacığı Güvenliği

Ara sonrası hoca `HashMap`'e geçmeden önce `Vector` sınıfından söz etti. `Vector`, `ArrayList` gibidir ve bütün metotları aynıdır. Tek fark, `Vector`'ün thread-safe, `ArrayList`'in ise thread-unsafe olmasıdır.

Thread-safe kavramını hoca şöyle bir örnekle açıkladı: iki program veri yapısındaki aynı nesneye erişip içindeki değeri güncellemek istesin. Değişkenin değeri 5 olsun. İkisi de değeri 5 olarak okur. Biri 1 artırıp 6 yapar, diğeri de 1 artırıp 6 yapar ve ikincisi değeri 6 ile değiştirir. Oysa ikincisinin birincinin güncellemesini beklemesi, böylece değeri 7 yapması gerekirdi. Yani iki süreç ya da program bir veri yapısındaki değeri güncellemek için ona aynı anda erişiyorsa senkronizasyon gerekir. `Vector` bu senkronizasyonu sağlar, `ArrayList` sağlamaz.

Aynı ayrım map yapılarında da vardır: `HashMap` thread-unsafe, `Hashtable` thread-safe'tir. İkisi de aynı `Map` arayüzünü gerçeklediği için metotları aynıdır.

## 8. Map Yapıları: HashMap ve Hashtable

Şimdiye kadar liste tabanlı yapılar (bağlı liste, `ArrayList`, `Vector`) görüldü. Map tabanlı yapılarda veri yapısında nesne çiftleri tutulur: birincisine anahtar (key), ikincisine değer (value) denir ve değerler anahtar nesneleri kullanılarak izlenir.

Slayt 156'daki içerik şöyledir (ekrandan, 01:15:00):

- Map veri yapısı, var olan bir elemana tekil tanımlayıcısıyla kolayca ulaşmayı sağlar. Bu işlem map yapılarında dizi ve liste yapılarına göre çok daha hızlıdır.
- Eleman = value, tekil tanımlayıcı = key.

Slayttaki `java.util` diyagramı:

| Sınıf / arayüz | İlişki | Not |
|---|---|---|
| `AbstractMap<K,V>` | `Map<K,V>` arayüzünü gerçekler (kesikli ok) | |
| `HashMap<K,V>` | `AbstractMap<K,V>`'den türer (kalıtım oku) | thread-unsafe |
| `Hashtable<K,V>` | `Map<K,V>` arayüzünü gerçekler (kesikli ok) | thread-safe; çoklu iş parçacığı ileride işlenecek |

`«interface» Map<K,V>` metotları:

- `+ get( key : Object ) : V`
- `+ put( key : K, value : V ) : V`
- `+ remove ( key : Object ) : V`
- `+ values( ) : Collection<V>` (for-each döngüsünü mümkün kılar)
- `+ isEmpty( ) : boolean`
- `+ size( ) : int`
- `+ containsKey( k : Object ) : boolean`
- `+ containsValue( v : Object ) : boolean`

Hoca metotları şöyle açıkladı. `HashMap` de jenerik bir sınıftır: içinde tutulacak nesnelerin türü baştan belirlenebilir ya da açık bırakılıp farklı türde nesneler konabilir. `K` anahtarı, `V` değeri gösterir. Map bir tablo gibidir: ilk sütun anahtarlar (indisler), ikinci sütun tutulmak istenen değerlerdir.

- `put` ile tabloya anahtar-değer çifti konur. Anahtar, değer için bir indis numarası gibi kullanılır.
- `get` ile anahtar verilir, karşılık gelen değer döner.
- `remove` ile anahtar verilir, o girdi tablodan silinir.
- `values` tablodaki bütün değerleri `Collection` türünde bir nesne olarak döndürür. Bunun üzerinde liste gibi gezinilebilir.
- `isEmpty` yapının boş olup olmadığını denetler; `size` tablodaki girdi sayısını döndürür.
- `containsKey` ile anahtar verilir ve orada bir değer olup olmadığı söylenir; `containsValue` ile değerin kendisi verilir, tablodaki bütün değerlere bakılır ve `true` ya da `false` döner.

> **Ders sonrası not:** Hoca `put` metodunun "eklediği değeri" döndürdüğünü söyledi. Doğrusu: `put`, o anahtarla daha önce tutulan değeri döndürür; anahtar ilk kez ekleniyorsa `null` döndürür. Ajan bunu `java` ile denedi: aynı anahtara ikinci `put` eski değeri döndürdü.

> **Ders sonrası not:** Hoca `Collection` arayüzünün liste tipi nesnelerle birlikte map tipi nesnelerin de ebeveyni olduğunu, `Map` arayüzünün `Collection`'dan türediğini söyledi. Doğrusu: `Map`, `Collection`'dan türemez (ajan `java` ile denedi: `HashMap` bir `Collection` değildir, `ArrayList` ise öyledir). `Map` ile `Collection` arasındaki bağ, `values()` metodunun bir `Collection<V>` döndürmesidir.

## 9. Course ve Student Örneği: HashMap ile

Hoca aynı UML problemine döndü: bir ders, dersteki öğrenciler ve öğrencileri derse ekleyen bir ana sınıf. İlk sürüm `ArrayList` ile yazılmıştı; şimdi aynı gerçekleme `HashMap` ile yapılır. `Student` sınıfı aynı kalır, yalnız `Course` değişir.

Slayt 158'deki kod (ekrandan, 01:20:00):

```java
package nyp09b;
import java.util.*;

public class Course {
    private String code; private String name; private int capacity;
    private HashMap<String,Student> students;

    public Course(String code, String name, int capacity) {
        this.code = code; this.name = name; this.capacity = capacity;
        students = new HashMap<String,Student>();
    }
    public String getCode() { return code; }
    public String getName() { return name; }
    public int getCapacity() { return capacity; }
    public int getStudentCount() {
        return students.size();
    }
    public boolean addStudent( Student aStudent ) {
        if( getStudentCount() == capacity ||
                    findStudent(aStudent.getNumber()) != null )
                return false;
        students.put(aStudent.getNumber(), aStudent);
        return true;
    }
```

- **Alan:** `HashMap` private bir değişkendir. Jenerik sınıfın iki tür argümanı vardır: anahtar için `String`, değer için `Student`.
- **Kurucu:** ilk satırda üye alanlara ilk değer verilir; ikinci satırda `HashMap` nesnesi oluşturulur ve adresi tanımlanmış alana atanır.

> **Hocanın vurgusu:** `HashMap`'i başlatırken tür kısmı (`<String,Student>`) yazılmıyor ve puan kaybediliyor. `HashMap` nasıl tanımlandıysa nesnesi de aynı biçimde oluşturulmalıdır.

- **`getStudentCount`:** `ArrayList` gibi `HashMap`'in de `size` metodu vardır; tablodaki girdi sayısını döndürür.
- **`addStudent`:** Bu bir ekleme metodu olduğu için girdi denetimi gerekir: önce kapasiteye ulaşılıp ulaşılmadığı (`getStudentCount() == capacity`), sonra öğrencinin derste zaten olup olmadığı denetlenir. Biri doğruysa `false` döner. Değilse `put` çağrılır: anahtar olarak öğrenci numarası (`String`), değer olarak öğrenci nesnesinin kendisi verilir.
- **`findStudent`:** Anahtar olarak öğrenci numarası kullanıldığı için öğrenci, numarası verilerek doğrudan `get` ile alınır; döngü gerekmez.
- **`increaseCapacity`:** `ArrayList` örneğindekiyle tamamen aynıdır.
- **`showClassList`:** Bütün veri yapılarında for-each kullanılabilir. Ancak `students` bir `HashMap`'tir ve her girdide iki nesne (anahtar ve değer) tutar. `values()` çağrılınca tablodaki bütün değerler `Collection` türünde bir veri yapısı olarak döner ve for-each bu koleksiyon üzerinde yapılır.

Hoca bunu Türkçe de açıkladı: for-each tek boyutlu bir veri yapısı üzerinde kullanılır; `ArrayList`, `LinkedList` ya da dizi olsaydı doğrudan yapılabilirdi. `students` ise "iki boyutlu"dur, çünkü nesneleri izlemek için anahtar nesnesi kullanılır. Bu yüzden `values()` ile ikinci elemanlardan (`Student` nesnelerinden) oluşan tek boyutlu bir koleksiyon çekilir ve bütün öğrenciler onun üzerinde for-each ile yazdırılır.

`main` metodu önceki örnektekiyle tamamen aynıdır. Ajan `HashMap`'li `Course` sınıfını küçük bir `main` ile `java` üzerinden çalıştırdı: aynı öğrencinin ikinci kez eklenmesi ve kapasite dolduktan sonraki ekleme `false` döndü, `values()` üzerinde for-each ile bütün öğrenciler yazdırıldı.

## 10. Veri Yapılarının Karşılaştırılması

Hoca bir veri yapısı seçerken hangisinin tercih edileceğini slayt 161 üzerinden anlattı (ekrandan, 01:25:00):

| Sınıf | Gerçeklediği arayüz | Özellikler |
|---|---|---|
| `java.util.LinkedList<E>` | `List<E>` | Ekleme ve silme hızlı; rastgele erişim yavaş; çift bağlı (bir `ListIterator` örneği alınarak geriye doğru gezilebilir) |
| `java.util.ArrayList<E>` | `List<E>` | Ekleme ve silme yavaş; rastgele erişim hızlı |
| `java.util.Vector<E>` | `List<E>` | `ArrayList`'e benzer; synchronized; çok iş parçacıklı kullanıma uygun, tek iş parçacıklı kullanımda daha yavaş |
| `java.util.HashMap<K,V>` | `Map<K,V>` | Bir anahtarla (indeksli) hızlı arama için kullanılır |
| `java.util.Hashtable<K,V>` | `Map<K,V>` | `HashMap`'e benzer ama synchronized; çok iş parçacıklı kullanıma uygun, tek iş parçacıklı kullanımda daha yavaş |

Slaytın son satırı: "Dikkat: `Hashtable` sınıf adında küçük t".

Hocanın açıklamaları:

- **`LinkedList`:** ekleme ya da silmede yalnız referanslar güncellenir. Örneğin başa yeni bir düğüm eklemek için baş (head) düğüm yeni düğümü gösterecek biçimde güncellenir, yeni düğümün referans kısmı da listenin ilk düğümünü gösterir. Bu yüzden ekleme ve silme hızlıdır. Ama belirli bir elemana erişmek için ilk elemandan başlayıp doğru düğüme kadar listeyi gezmek gerekir; bunun için `ListIterator` nesnesi kullanılır. Bu yüzden rastgele erişim yavaştır.
- **`ArrayList`:** veri yapısının belirli indislerine çok daha hızlı erişilir, ama ekleme ve silme bağlı listeye göre daha yavaştır.
- **`Vector`:** `ArrayList` ile aynı avantaj ve dezavantajlara sahiptir; tek farkı senkronize olmasıdır.
- **`HashMap`:** bağlı liste ve `ArrayList`'e göre aramada çok daha hızlıdır, çünkü değerler anahtara karşılık gelecek biçimde konur ve değere anahtarla doğrudan erişilir.
- **`Hashtable`:** `HashMap` ile tamamen aynıdır; tek farkı thread-safe olması, yani senkronizasyona izin vermesidir.

> **Hocanın vurgusu:** `ArrayList`'in "List"i, `HashMap`'in "Map"i gibi diğer adlarda ikinci kelime büyük harfle başlar; yalnız `Hashtable`'da ikinci kelime küçük `t` ile başlar. Sınavda kesinlikle yanlış yazılmamalı.

## 11. MapTest: Tür Parametresiz HashMap

Hoca `oop02b` paketindeki `MapTest` adlı basit bir sınıfı gösterdi. Önce bir `HashMap` nesnesi oluşturulur ve referansı, türü `HashMap`'in ebeveyni olan bir değişkene atanır. Bu yapılabilir: çocuk nesne nerede oluşturulursa oluşturulsun, ebeveyn tür kullanılabilir.

Burada `HashMap`'te tutulacak türler belirtilmemiştir. Bu durumda ilk girdide anahtar ve değer olarak istenen türler, ikinci girdide başka türler tutulabilir. Tür baştan belirtilseydi (ör. `<String,Student>`), bütün anahtarlar `String`, bütün değerler `Student` olmak zorunda olurdu.

Örnekte:

- İlk `put` çağrısında anahtar `String`, değer de `String`'dir.
- İkinci `put` çağrısında anahtar `String`, değer ise `Integer`'dır. Bu, tür belirtilmediği için yapılabilir.
- Üçüncü `put` çağrısında ikisi de yine `String`'dir.
- Sonra birinci anahtarla `get` yapılınca en son konan `String` değer döner.

<!-- BELİRSİZ: MapTest kodu karelerde görünmüyor; kullanılan anahtar ve değerler ile üçüncü put'un birinci anahtarı yeniden kullanıp kullanmadığı altyazıdan kesin çıkmıyor. -->

Hoca bu örnekle şunu göstermek istedi: jenerik bir sınıf başlatılırken tür vermek zorunlu değildir.

> **Hocanın vurgusu:** Soruda veri yapısında hangi türden nesnelerin tutulacağı özellikle söyleniyorsa, `HashMap` hem tanımlanırken hem başlatılırken o türlerle yazılmalıdır.

## 12. İstisna Yönetimine Giriş ve İstisna Sınıf Ağacı

Kod çalışırken hatalar ya da sorunlar çıkabilir. Bunlar kullanıcının verdiği girdiyle, yazılan kodla ya da programın çalışması sırasında rastgele olan durumlarla ilgili olabilir. Program hata olsa bile çalışmaya devam etmelidir. Bunun için programa, hata çıktığında onu yakalayan ve programın sürmesini sağlayan ek denetimler eklenir. Bu denetimler istisna yönetiminin konusudur: kod istisna yönetimi sözdizimi içine konur ve hata olduğunda bu yapı hatayı yakalar.

Java, istisna yönetimi için bazı sınıflar sağlar. Slayt 165'teki kalıtım ağacı (ekrandan, 01:40:00):

```text
Throwable
├── Error                (unchecked)
└── Exception
    ├── IOException      (checked)
    └── RuntimeException (unchecked)
```

- En üstte `Throwable` sınıfı vardır. `Error` ve `Exception` aileleri özelliklerini bu ebeveynden alır.
- **`Error` ailesi (unchecked):** JVM, fiziksel bellek ya da işletim sistemiyle ilgili ciddi sorunları gösterir; programın çalışmasıyla ilgili değildir. Bu derste bu aileyle ilgilenilmez; yapılan istisna yönetimi tamamen yazılan kodla ilgilidir.
- **`RuntimeException` (unchecked):** kodun yazılış biçimiyle ilgilidir. Örnekler:
  - Bölmede paydaya sıfır konursa aritmetik işlem hatası (`ArithmeticException`) çıkar.
  - Dizinin boyutundan büyük bir indise erişilmeye çalışılırsa `IndexOutOfBoundsException` çıkar.
  - Bellekte olmayan bir nesneye erişilmeye çalışılırsa `NullPointerException` çıkar.
  - Derleyici bu kodların istisna yönetimine konmasını zorlamaz. Ama bunlar çalışma sırasında çıkarsa programı durduracağı için yine try-catch içine alınmak istenir.
- **`IOException` (checked):** derleyici, bu tür hataları çıkarabilecek kodun istisna yönetimi sözdizimi içine konmasını zorlar; aksi hâlde kod derlenmez.

> **Ders sonrası not:** Hoca 01:42:06 civarında `Error` ailesini anlatırken bir an "exception handling sınıfları" dedi; kastettiği `Error` sınıflarıdır.

## 13. try-catch, throws, Çoklu catch ve finally

### 13.1 try-catch

Slayt 167'deki sözdizimi (ekrandan, 01:45:00):

```java
try {
    /* error-prone methods */;
}
catch( AnException e ) {
    /* Dealing with error */
}
```

Hata çıkarabilecek kod `try` bloğuna yazılır. Hata olduğunda JVM onu yakalar ve `catch` bloğundaki kodu çalıştırır; `catch` bir argümanı (istisna nesnesi) girdi olarak alır.

Hocanın Türkçe örneği: bir bölme işleminde kullanıcı paydaya sıfır yazabilir. Bu durumda programın hata verip durması değil, kullanıcıya paydaya sıfır yazmaması gerektiğini söyleyen bir yazı çıkması istenir. Bölme `try` içine, `System.out.println("Paydaya sıfır koymayın")` gibi bir uyarı `catch` içine konur. try-catch kullanılmasaydı program hata vererek dururdu. Hatalar kullanıcının girdisinden ya da programın dosya sisteminde okuyacağı veya sileceği bir dosyayı bulamamasından kaynaklanabilir; bu durumlarda programın ne yapacağı `catch` bloklarına yazılır.

### 13.2 throws

Slaytın ikinci kısmı:

```java
aMethod(…) throws AnException {
    /* error-prone methods */
}
```

Programcı checked bir istisnayı yerinde ele almamayı seçebilir, ama sonunda biri onu ele alacaktır; bu kişi `aMethod`'u çağıran yerdir. Hoca bunu şöyle anlattı: bir metodun içindeki kod try-catch'e konabilirdi. Ama metodun içinde hatayı yakalamak istenmiyorsa, metot nereden çağrılıyorsa (belki `main`'den, belki başka bir metottan) istisna oraya atılır ve try-catch orada yazılır. Bunun için metot tanımının ardından `throws` anahtar kelimesi ve olabilecek istisnanın türü yazılır.

### 13.3 Birden Çok catch

Slayt 168 (ekrandan, 01:50:00):

```java
try {
    /* error-prone methods */;
}
catch( AnException e ) {
    /* Dealing with error */
}
catch( AnotherException e ) {
    /* Dealing with error */
}
```

Kodda birden fazla türde hata olabilir: ör. `NullPointerException`, aritmetik hata ya da `IOException`. Bu durumda her hata türü için ayrı bir `catch` bloğu yazılır. İki farklı ya da iç içe try-catch blokları da kurulabilir. Slayttaki try blokları notu:

- Her yeni try bloğu çalışma zamanında ek yük getirir.
- Bu yüzden birden çok catch bloğuyla tek bir try bloğu açmak daha akıllıcadır.

### 13.4 finally

try-catch yapısına bir `finally` bölümü de eklenebilir (try-catch-finally). `finally` içindeki kod hata olsa da olmasa da çalışır:

- `try` bloğu hatasız çalışırsa hiçbir `catch` bloğu çalışmaz, ama `try`'dan hemen sonra JVM `finally` bloğunu çalıştırır.
- Hata olursa ve bir `catch` bloğu onu yakalarsa `catch` bloğu çalışır, ardından `finally` de çalışır.

`finally` genelde programdan çıkarken mutlaka yapılması gereken işler için kullanılır; ör. işi biten `Scanner` nesnesini kapatmak.

## 14. ExceptionExample01: IOException ve finally

Ara sonrası hoca slayt 170'teki örneği anlattı (ekrandan, 02:05:00):

```java
public class ExceptionExample01 {
    MyScreenRenderer graphics;
    MyCADfile myFile;
    //Other methods of this class are omitted
    public void parseMyCADfile( String fileName ) {
        try {
            graphics = new MyScreenRenderer();
            myFile = openFile( fileName );
            MyFigure figs[ ] = myFile.readFromFile( );
            drawFigures( figs );
            myFile.close();
        }
        catch( IOException e ) {
            System.out.println("An IO exception has occurred"+
                " while opening or reading from file:"+
                e.toString( ) );
            e.printStackTrace( );
            System.exit(1); //Multithreaded, allows finally to be run
        }
        finally {
            graphics.releaseSources();
        }
    }
}
```

- Sınıfın iki üye alanı vardır: türü `MyScreenRenderer` ve `MyCADfile` olan iki değişken. Bunlar bir takım sınıflardır.
- `try` bloğunda sorun çıkarabilecek kod vardır: önce üye alandaki sınıfın nesnesi oluşturulur; sonra burada gösterilmeyen ama var sayılan `openFile` metoduyla bir dosya açılır ve bir nesne referansı döner; bu referansla `readFromFile` çağrılır ve bir `MyFigure` dizisi döner; şekiller çizilir ve dosya kapatılır.
- Burada girdi-çıktı (dosya sisteminden okuma ya da yazma) işlemi yapıldığı için `IOException` sınıfı kullanılır. `catch` bloğunda bu türde bir hata olabileceği belirtilir; hata olursa ne olduğunu anlatan basit bir ileti yazdırılır ve istisna sınıfının `printStackTrace` metodu çağrılır. `printStackTrace`, `try` bloğunda ne tür bir hata olduğunun ayrıntısını verir.
- `System.exit` programdan çıkar.
- `finally` bölümü bu sınıf için bütün kaynakları serbest bırakır (sınıfın `releaseSources` metodu varmış gibi düşünülür). Programdan çıkmadan önce yapılması gereken son bir iş varsa `finally`'ye konur; yoksa `finally` kullanmak gerekmez.

**Soru (hocanın kendi sorduğu):** `catch` içinde programı JVM'e otomatik olarak sonlandırtan `System.exit` var. Bu durumda `finally` çalışır mı? **Hocanın cevabı:** Evet; JVM önce `finally`'yi çalıştırır, sonra çıkar.

> **Ders sonrası not:** Hoca `System.exit` çağrıldıktan sonra da `finally`'nin çalışacağını söyledi; slayttaki yorum da "allows finally to be run" der. Doğrusu: `System.exit` JVM'i durdurur, metottan normal ya da istisnayla dönülmediği için `finally` bloğu çalışmaz. Ajan bunu `java` ile denedi: catch içinde `System.exit(1)` çağrılınca yalnız catch iletisi yazıldı, finally iletisi yazılmadı. "finally her zaman çalışır" kuralı, metot `return` ya da istisnayla terk edildiğinde geçerlidir.

## 15. Kendi İstisna Sınıfını Yazmak: ImpossibleInfo

### 15.1 Checked mi, unchecked mi?

Bazen programın kendi özel istisna sınıfı olması istenir. Kalıtım ağacına dönülürse: `IOException` checked, `RuntimeException` unchecked'tir; `Error` ailesi kodun dışındaki (JVM ile ilgili) istisnalardır.

- Derleyicinin kodu try-catch içine koymaya zorlaması, yani checked bir istisna isteniyorsa `IOException` genişletilir.
- Unchecked bir istisna sınıfı isteniyorsa `RuntimeException` genişletilir.

> **Ek bilgi (derste anlatılmadı):** Derste checked istisna için `IOException` genişletildi. Java'da `RuntimeException` ve alt sınıfları dışında kalan bütün `Exception` alt sınıfları büyük olasılıkla checked sayılır; kendi checked istisnanızı doğrudan `Exception`'dan türetmek de yaygındır. Bölüm 17'deki örnekte de `throw new Exception(...)` kullanıldığı için metotlara `throws Exception` yazmak zorunludur.

### 15.2 Sözdizimi

Her istisna sınıfında bir kurucu olmalıdır. Java'nın eski sürümlerinde varsayılan kurucu da gerekirdi; yeni sürümlerde gerekmez, ama tek parametreli (`String`) bir kurucu mutlaka olmalıdır. Bu kurucunun gövdesinde `super` çağrılarak iletilmek istenen hata mesajı ebeveynin kurucusuna aktarılır.

Slayt 173 (ekrandan, 02:15:00):

```java
package nyp10;
import java.io.IOException;
/* @home: Check the needed additions
 * if we had extended this exception
 * from java.lang.RuntimeException
 */
@SuppressWarnings("serial")
public class ImpossibleInfo extends IOException {
    public ImpossibleInfo( String errorMessage ) {
        super(errorMessage);
    }
}
```

<!-- BELİRSİZ: Slaytta sınıfın sonunda bir kapanış parantezi fazla görünüyor; yukarıda derlenebilir biçim verildi. -->

Hoca istisna sınıflarında bir seri numarası da kullanıldığını söyledi; bu, ileride Java girdi-çıktı (I/O) paketi işlenirken öğrenilecek. Sınıfa seri numarası girilmezse derleyici uyarı verir; uyarı almamak için sınıf adının önüne `@SuppressWarnings("serial")` yazılır. Şimdilik bunun derleyiciye kod yazılırken uyarı yazmamasını söyleyen bir yapı olduğunu bilmek yeterlidir.

### 15.3 Person Sınıfı ve setAge

`Person` sınıfının iki üye alanı, tek parametreli bir kurucusu, getter metotları ve bir `toString` metodu vardır. Bir de `setAge` metodu vardır. Bu metodun gövdesinde hata çıkabileceği düşünüldüğü için tanımına `throws ImpossibleInfo` yazılır.

`setAge` içinde iki koşullu bir `if` vardır: yaş 0'dan küçükse ya da 150'den büyükse. İkisi de olanaksız durumlardır; kişi bu sınırların altında ya da üstünde bir yaş girerse `ImpossibleInfo` istisnası fırlatılır. Bu, programın mantığından gelir: bu koşulların olanaksız olduğu bilindiği için istisna programcı tarafından `throw` ile oluşturulur. Koşul oluşmazsa kişinin yaşı atanır.

<!-- BELİRSİZ: Person sınıfının kodu (slayt 174) karede görünmüyor; koşul altyazıdan "age < 0 || age > 150" olarak alındı, istisna iletisinin metni çıkarılamadı. -->

İki ayrı anahtar kelime vardır:

- `throws`: metot tanımının hemen ardından kullanılır; istisnayı metodun çağrıldığı yere bırakır.
- `throw`: yeni bir istisna nesnesi oluşturulup fırlatılırken kullanılır (`throw new ImpossibleInfo(...)`). Bu yalnız programın mantık akışında özel bir koşul olduğunda yapılır.

> **Hocanın vurgusu:** `throw` ile `throws` karıştırılıp yanlış yazılırsa sınavda puan kaybediliyor.

### 15.4 TestExceptions

Slayt 175 (ekrandan, 02:20:00):

```java
package nyp10;
import java.util.*;
public class TestExceptions {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter person's name: ");
        String name = in.nextLine();
        Person insan = new Person(name);
        try {
                System.out.print("Enter age: ");
                int age = in.nextInt();
                insan.setAge(age);
                System.out.println(insan);
        }
        catch (ImpossibleInfo e) {
                e.printStackTrace();
        }
        finally {
                in.close();
        }
    }
}
```

Slayttaki ek not: istisnaya yol açabilecek deyim ile kalan deyimler `try` bloğuna alınabilir ya da bütün deyimler `try` bloğuna konabilir.

- `main` başında bir `Scanner` nesnesi oluşturulur, kullanıcıdan kişinin adı istenir ve tek parametreli kurucuyla bir `Person` nesnesi oluşturulur.
- `setAge` metodu `ImpossibleInfo` fırlatır; `ImpossibleInfo` de checked bir istisna olan `IOException`'ı genişletir. Bu yüzden `setAge` çağrısı mutlaka try-catch içine konmalıdır, yoksa derleyici kodu derlemez. `catch` bloğunda `ImpossibleInfo` türünde nesne yakalanmalıdır.
- `try` içinde kullanıcıdan yaş istenir, geçici değişkene atanır, `setAge` çağrılır ve kişi yazdırılır. Kullanıcı sınırların dışında bir yaş girerse `setAge` istisna fırlatır, `catch` bloğu çalışır ve `printStackTrace` hatanın nerede oluştuğunu yazar.
- `finally` içinde baştaki `Scanner` nesnesi kapatılır. Programın sonunda yapılması gereken bir iş olduğu için `finally` kullanılır; `try` bloğunda hata olsa da olmasa da çalışır.

Hoca aynı kodların Türkçe sürümünü de (`OlanaksizBilgi`, `Kisi`, `TestKisi` sınıfları) gösterdi; bunlar paylaşılan kodlar arasındadır.

## 16. DivideByZeroWithExceptionHandling

Kitaptan alınan bir örnekte önce istisna yönetimi olmayan `DivideByZeroNoExceptionHandling` sınıfı anlatıldı: `quotient` metodu pay (numerator) ve payda (denominator) alır ve bölme yapar; `Scanner` ile kullanıcıdan iki tamsayı alınır ve metot çağrılır. İstisna yönetimi olmadığı için ör. pay 3, payda 0 girilirse program hata verip durur. Bunu önlemek için istisna yönetimi yapılır.

İstisna yönetimli sürüm (ekrandan, 02:25:00):

```java
import java.util.InputMismatchException;
import java.util.Scanner;

public class DivideByZeroWithExceptionHandling
{
   // demonstrates throwing an exception when a divide-by-zero occurs
   public static int quotient( int numerator, int denominator )
          throws ArithmeticException
          {
      return numerator / denominator; // possible division by zero
          } // end method quotient

   public static void main( String[] args )
   {
      Scanner scanner = new Scanner( System.in ); // scanner for input
      boolean continueLoop = true; // determines if more input is needed

      do
      {
         try // read two numbers and calculate quotient
         {
            System.out.print( "Please enter an integer numerator: " );
            int numerator = scanner.nextInt();
            System.out.print( "Please enter an integer denominator: " );
            int denominator = scanner.nextInt();

            int result = quotient( numerator, denominator );
            System.out.printf( "\nResult: %d / %d = %d\n", numerator,
               denominator, result );
            continueLoop = false; // input successful; end looping
         } // end try
         catch ( InputMismatchException inputMismatchException )
         {
            System.err.printf( "\nException: %s\n",
               inputMismatchException );
            scanner.nextLine(); // discard input so user can try again
            System.out.println(
               "You must enter integers. Please try again.\n" );
         } // end catch
         catch ( ArithmeticException arithmeticException )
         {
            System.err.printf( "\nException: %s\n", arithmeticException );
            System.out.println(
               "Zero is an invalid denominator. Please try again.\n" );
         } // end catch
      } while ( continueLoop ); // end do...while
   } // end main
}
```

<!-- BELİRSİZ: Karede 49. satırdan sonrası (do-while'ın kapanışı ve sınıfın sonu) görünmüyor; kapanış satırları altyazıdaki anlatıma göre tamamlandı. import satırlarından yalnız InputMismatchException karede okunuyor. -->

- Hata iki türlü yakalanabilir: `numerator / denominator` kodu metodun içinde try-catch'e konabilir ya da metot tanımının hemen ardından `throws` yazılabilir. Burada ikincisi yapılmış ve olabilecek istisna `ArithmeticException` olarak belirtilmiştir. `ArithmeticException`, `RuntimeException`'ı genişleten istisna sınıflarından biridir.
- `main`'de bir `do-while` döngüsü vardır. Döngü belli bir koşul sağlanana kadar sürsün diye `continueLoop` başta `true`'dur.
- `try` bloğunda pay ve payda kullanıcıdan alınır, metot çağrılır, sonuç pay ve paydayla birlikte yazdırılır, `continueLoop` `false` yapılır ve döngüden çıkılır. Yani işlem düzgün tamamlanırsa döngü bir kez çalışır; hata çıkar ve `catch` yakalarsa döngü sürer.
- İki tür hata olabileceği için iki ayrı `catch` bloğu vardır. `ArithmeticException` oluşunca istisna nesnesi ve hatanın ne olduğu ekrana yazdırılır.

Hoca kodu çalıştırdı: pay 7, payda 0 girilince istenen uyarı yazıldı ve program durmadı, yeniden veri istendi; pay 7, payda 7 girilince döngüden çıkıldı ve program bitti. Böylece istisna yönetimiyle program, kullanıcıdan gelen hatalar yüzünden durmadan çalışmaya devam etti.

Ajan kodu `java` ile aynı girdilerle çalıştırdı; çıktı şöyledir:

```text
Please enter an integer numerator: Please enter an integer denominator: 
Exception: java.lang.ArithmeticException: / by zero
Zero is an invalid denominator. Please try again.

Please enter an integer numerator: Please enter an integer denominator: 
Result: 7 / 7 = 1
```

Hoca bir dosya sistemi örneğinin dosya sistemi konusunda işleneceğini söyleyip geçti.

## 17. Zincirleme İstisnalar: UsingChainedExceptions

Hoca birbirini çağıran metotlarda istisna yönetimini gösterdi (ekrandan, 02:30:00):

```java
   public static void main( String[] args )
   {
      try
      {
         method1(); // call method1
      } // end try
      catch ( Exception exception ) // exceptions thrown from method1
      {
         exception.printStackTrace();
      } // end catch
   } // end main

   // call method2; throw exceptions back to main
   public static void method1() throws Exception
   {
      try
      {
         method2(); // call method2
      } // end try
      catch ( Exception exception ) // exception thrown from method2
      {
         throw new Exception( "Exception thrown in method1", exception );
      } // end catch
   } // end method method1

   // call method3; throw exceptions back to method1
   public static void method2() throws Exception
   {
      try
      {
         method3(); // call method3
      } // end try
      catch ( Exception exception ) // exception thrown from method3
      {
         throw new Exception( "Exception thrown in method2", exception );
      } // end catch
   } // end method method2

   // throw Exception back to method2
   public static void method3() throws Exception
   {
      throw new Exception( "Exception thrown in method3" );
   } // end method method3
} // end class UsingChainedExceptions
```

- `main`, `method1`'i çağırır ve bu çağrıyı try-catch içine koyar.
- `method1`'in gövdesi zaten try-catch içindedir; yani aslında istisna atmasına gerek yoktu. Ama `catch` bloğunun içine `throw new Exception(...)` konmuştur; `catch` içinden de istisna atıldığı için `method1` tanımına `throws Exception` yazmak zorunludur. `method1` istisna üreten bir metot olduğu için çağrıldığı yerde try-catch içine konmak zorundadır.
- `method2` de `method3`'ü try-catch içinde çağırır ve `catch` içinde yeni bir istisna atar; bu yüzden onun da tanımında `throws Exception` vardır.
- `method3`'ün gövdesinde doğrudan `throw new Exception(...)` vardır; bu yüzden bu metot mutlaka `throws Exception` bildirmek zorundadır.

Sıralama şöyledir:

```text
1. method3 bir istisna fırlatır.
2. method3'ü çağıran method2'de istisna oluşur, method2'nin catch bloğu yakalar
   ve yeni bir istisna fırlatır; yani method2 istisna fırlatmış olur.
3. method2'nin çağrıldığı method1'de istisna oluşur, method1'in catch bloğu
   yakalar ve yeni bir istisna fırlatır.
4. method1'in çağrıldığı main'de istisna oluşur, main'in catch bloğu yakalar
   ve printStackTrace() çağırır.
```

Hoca bu kodu iç içe, zincirleme (nested, chained) istisna yönetimi yapılabildiğini göstermek için açtı. Konsolda, en alttaki `method3` istisnası yüzünden yukarıdaki istisnaların oluştuğu adım adım izlenebilir.

Ajan kodu `java` ile çalıştırdı; `printStackTrace` çıktısının ana satırları şöyledir (yığın satırları kısaltıldı):

```text
java.lang.Exception: Exception thrown in method1
	at UsingChainedExceptions.method1(...)
	at UsingChainedExceptions.main(...)
Caused by: java.lang.Exception: Exception thrown in method2
	at UsingChainedExceptions.method2(...)
	at UsingChainedExceptions.method1(...)
Caused by: java.lang.Exception: Exception thrown in method3
	at UsingChainedExceptions.method3(...)
	at UsingChainedExceptions.method2(...)
```

> **Ek bilgi (derste anlatılmadı):** `new Exception("ileti", exception)` kurucusunun ikinci parametresi istisnanın nedenidir (cause). Zincirleme istisnanın amacı, üst düzeyde yeni bir ileti verirken alttaki asıl hatanın bilgisini kaybetmemektir; `printStackTrace` çıktısındaki `Caused by:` satırları bu nedenlerden gelir.

## 18. UsingExceptions1: Yeniden Fırlatma ve finally

Son örnekte `main` dışında iki metot vardır: `throwException` ve `doesNotThrowException` (ekrandan, 02:35:00):

```java
      try
      {
         throwException(); // call method throwException
      } // end try
      catch ( Exception exception ) // exception thrown by throwException
      {
         System.err.println( "Exception handled in main" );
      } // end catch

      doesNotThrowException();
   } // end main

   // demonstrate try...catch...finally
   public static void throwException() throws Exception
   {
      try // throw an exception and immediately catch it
      {
         System.out.println( "Method throwException" );
         throw new Exception(); // generate exception
      } // end try
      catch ( Exception exception ) // catch exception thrown in try
      {
         System.err.println(
            "\nException handled in method throwException" );
         throw exception; // rethrow for further processing

         // code here would not be reached; would cause compilation errors

      } // end catch
      finally // executes regardless of what occurs in try...catch
      {
         System.err.println( "Finally executed in throwException" );
      } // end finally

      // code here would not be reached; would cause compilation errors

   } // end method throwException

   // demonstrate finally when no exception occurs
   public static void doesNotThrowException()
   {
      try // try block does not throw an exception
      {
         System.out.println( "Method doesNotThrowException" );
         //System.exit(1);
```

<!-- BELİRSİZ: doesNotThrowException metodunun devamı (catch, finally ve finally sonrası yazdırılan satır) karede görünmüyor. -->

- `throwException` tanımında `throws Exception` vardır. Yani metot, içine bakılmadan, içinde bir istisna oluşabileceğini söyler. Tanımda bu yazdığı için `main`'de bu metodun çağrısı mutlaka try-catch içine konmalıdır.
- `doesNotThrowException`'da böyle bir bildirim yoktur; bu yüzden çağrısı try-catch'e konmaz.
- `throwException` neden `throws Exception` der? Gövdesinde iki satır vardır: bir `System.out.println` ve bir `throw new Exception()`. Fırlatılan istisna hemen alttaki `catch` bloğunda yakalanır; orada bir ileti yazdırılır ve yakalanan aynı istisna nesnesi yeniden fırlatılır. Burada yeni bir istisna nesnesi oluşturulmaz; girdi olarak alınan nesne tekrar fırlatılır. Bu yüzden metot tanımına `throws Exception` yazmak gerekir, o yüzden de çağrısı try-catch'e konmak zorunda kalınır.
- Metodun bir `finally` bölümü de vardır: istisna oluşsa da oluşmasa da çalışır, yani iletisini mutlaka yazdırır.
- `doesNotThrowException`'ın gövdesinde yalnız bir `System.out.println` vardır; istisna oluşmaz, bu yüzden `throws` yazılmamıştır. İstisna oluşsaydı `catch` bloğu çalışacaktı. Oluşsa da oluşmasa da `finally` bloğu çalışır. `finally`'den sonra, metot bitmeden önce bir satır daha yazdırılır.

Hoca bu kodun çalıştırılıp konuşulanların doğrulanmasını öğrencilere bıraktı. Ajan karede görünen kısmı (eksik kalan `doesNotThrowException` gövdesini basit bir catch ve finally ile tamamlayarak) `java` ile çalıştırdı; çıktı (standart çıktı ve hata akışı birlikte) şöyledir:

```text
Method throwException

Exception handled in method throwException
Finally executed in throwException
Exception handled in main
Method doesNotThrowException
Finally executed in doesNotThrowException
```

Sıra şunu gösterir: `catch` istisnayı yeniden fırlatsa bile `finally` metot terk edilmeden önce çalışır; `main`'deki `catch` ancak bundan sonra istisnayı yakalar.

> **Hocanın vurgusu:** Sınavda istisna yönetimi soruları kod verilmeden, metin olarak sorulacak: "böyle bir durumda kendi istisna sınıfınızı yaratın, bu istisna şu koşullarda oluşabilir" gibi. Olanaksız bilgi örneğindeki gibi kendi istisna sınıfını yazmak, o koşulda istisnayı `throw` ile fırlatmak ve istisnayı metotta değil metodun çağrıldığı yerde yakalamak için `throws` kullanmak beklenecek. Bu yüzden paylaşılan istisna örneklerinin (zincirleme istisna, metotta `throws` ile istisna bildirme, kendi istisnasını oluşturup yakalama) çalıştırılıp iyice anlaşılması istendi.

## Örnek Sorular

**1.** (derste sözlü, 00:27:21) Slaytta `ArrayList` metotlarında bazı yerlerde "element", bazı yerlerde "object" yazıyor. "Element" ilkel türleri mi gösterir?

> **Cevap (derste verildi):** Hayır. "Element" jenerik türdür (`T`, `E` gibi); `ArrayList`'te herhangi bir nesne tutulabilir. Tür baştan verilirse (`ArrayList<String>`) yalnız o türden nesne konur; `Object` ya da tür parametresi verilmeden kullanılırsa farklı türler (ör. önce `String`, sonra `Integer`) konabilir.

**2.** (derste sözlü, 00:33:53) `ArrayList` oluşturulurken bir kapasite değeri girmiyoruz. O hâlde `ensureCapacity` metodu neden kullanılır?

> **Cevap (derste verildi):** JVM fiziksel bellekte çalışır ve aynı anda başka programlar da bellek kullanır. Programın ömrü boyunca yapıda en çok kaç nesne (ör. 30) tutulacağı biliniyorsa, `ensureCapacity(30)` ile JVM'den bu kadar nesne için baştan yer ayırması istenir. Dizi oluştururken `new String[5]` demek de aynı türden bir bellek ayırma isteğidir.

**3.** (ekrandan, 00:35:00 ve 00:40:00) `ArrayListTest` programında `list` başta `{ "MAGENTA", "RED", "WHITE", "BLUE", "CYAN" }`, `removeList` ise `{ "RED", "WHITE", "BLUE" }` elemanlarını içerir. `removeColors( list, removeList )` çağrısından sonra liste ne yazdırır?

> **Cevap (derste verildi, ajan `java` ile doğruladı):** `removeList`'te bulunan elemanlar iterator ile `list`'ten silinir; sonuç `MAGENTA CYAN` olur.

**4.** (ekrandan, 02:25:00) `DivideByZeroWithExceptionHandling` programına önce pay 7 ve payda 0, sonra pay 7 ve payda 7 girilirse ne olur?

> **Cevap (derste verildi, ajan `java` ile doğruladı):** İlk denemede `quotient` `ArithmeticException` fırlatır, ikinci `catch` bloğu yakalar, `java.lang.ArithmeticException: / by zero` ve "Zero is an invalid denominator. Please try again." yazılır; `continueLoop` `true` kaldığı için yeniden girdi istenir. İkinci denemede `Result: 7 / 7 = 1` yazılır, `continueLoop` `false` olur ve döngü biter.

**5.** (ekrandan, 02:15:00) Slayttaki ev ödevi notu: "`ImpossibleInfo` istisnasını `java.lang.RuntimeException`'dan genişletseydik gereken eklemeleri/değişiklikleri kontrol edin."

> **Çözüm (derste verilmedi):** `RuntimeException`'dan türeyen istisna unchecked olur. Bu durumda:
> - Sınıf tanımı `public class ImpossibleInfo extends RuntimeException` olur; `import java.io.IOException;` satırına gerek kalmaz. Tek parametreli kurucu ve `super(errorMessage)` aynen kalır.
> - `setAge` metodundaki `throws ImpossibleInfo` bildirimi zorunlu olmaktan çıkar (yazılabilir ama derleyici istemez).
> - `TestExceptions`'taki `setAge` çağrısının try-catch içine alınması derleyici açısından zorunlu olmaz; ancak alınmazsa olanaksız yaş girildiğinde istisna `main`'den dışarı çıkar ve program durur. Programın durmaması için try-catch yine yazılmalıdır.
> - Ajan unchecked sürümü `java` ile çalıştırdı: `setAge(200)` çağrısı try-catch ile yakalandı; derleme için `throws` gerekmedi.

**6.** (ekrandan, 02:20:00) Slayttaki alıştırma: "Çok kısa adlar için de denetim ekleyin."

> **Çözüm (derste verilmedi):** Derste bir alt sınır verilmedi; burada örnek olarak 2 karakterden kısa ad olanaksız sayıldı. Denetim `Person` kurucusuna konabilir; `ImpossibleInfo` checked olduğu için kurucu da `throws ImpossibleInfo` bildirmeli ve `new Person(name)` satırı `try` bloğunun içine alınmalıdır:
>
> ```java
> public Person( String name ) throws ImpossibleInfo {
>     if( name == null || name.trim().length() < 2 )
>         throw new ImpossibleInfo("Name is too short: " + name);
>     this.name = name;
> }
> ```
>
> `TestExceptions`'ta `Person insan = new Person(name);` satırı `try` içine taşınır; kalan satırlar aynı kalır. Ajan bu denetimi (unchecked sürümle) `java` ile denedi: tek harfli ad istisnayla yakalandı, geçerli ad ve yaş için kişi yazdırıldı.

**7.** (derste sözlü, 02:07:44) `catch` bloğunda `System.exit(1)` çağrılırsa `finally` bloğu çalışır mı?

> **Cevap (derste verildi, düzeltildi):** Hoca "evet" dedi. Doğrusu: hayır. `System.exit` JVM'i durdurduğu için `finally` çalışmaz. Ajan `java` ile denedi: yalnız catch iletisi yazıldı (bkz. bölüm 14'teki ders sonrası not).

## Dersin Toparlaması

Bu derste Java'nın `java.util` paketindeki iki temel veri yapısı ve istisna yönetimi işlendi. `ArrayList`, `List` arayüzünü gerçekleyen, elemanlara indisle (`get`, `set`, `remove`) erişmeyi sağlayan jenerik bir sınıftır; `Vector` aynı metotlara sahip, senkronize bir karşılığıdır. `HashMap` ise anahtar-değer çiftlerini tutar ve anahtarla çok hızlı arama sağlar; `Hashtable` onun senkronize karşılığıdır. Aynı `Course`/`Student` problemi önce `ArrayList`, sonra `HashMap` ile yazılarak iki yapının kodu nasıl değiştirdiği gösterildi; her iki sürümde de ekleme metodunda kapasite ve varlık denetiminin ve alanın kurucuda doğru tür parametreleriyle başlatılmasının önemi vurgulandı.

Dersin ikinci yarısında istisna sınıf ağacı (`Throwable`, `Error`, `Exception`, `IOException`, `RuntimeException`), checked ve unchecked ayrımı, `try`-`catch`-`finally`, `throws` ile `throw` farkı, kendi istisna sınıfını yazma (`ImpossibleInfo`), `do-while` ile kullanıcıdan doğru girdi gelene kadar yeniden deneme, zincirleme istisnalar ve yakalanan istisnanın yeniden fırlatılması örneklerle görüldü. Bir sonraki derste tür dönüştürme (typecasting) konusuna geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
