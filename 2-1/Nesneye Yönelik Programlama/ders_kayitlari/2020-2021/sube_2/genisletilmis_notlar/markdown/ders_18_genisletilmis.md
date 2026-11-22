# Ders 18 Genişletilmiş Notu: Jenerik Sınıflar, Java Veri Yapıları ve Aykırı Durum İşlemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri yapısı kavramı ve dersin amacı
- 2. Bağlı listeler ve dizilerle karşılaştırma
- 3. Jenerik programlama ve ArrayList
- 4. Java koleksiyon hiyerarşisi
- 5. Örnek: ders, öğrenci ve USIS (ArrayList ile)
- 6. Dizili sürümle karşılaştırma
- 7. Map yapıları ve HashMap
- 8. Örneğin HashMap ile yeniden yazılması
- 9. Anahtar olarak ilkel tür ve otomatik sarmalama
- 10. Veri yapılarının özeti
- 11. Aykırı durum işleme: neden ve hiyerarşi
- 12. try, catch ve finally
- 13. Kendi exception sınıfını yazmak ve fırlatmak
- 14. Uygulama: ImpossibleInfo ve Person
- Örnek Sorular

## 1. Veri yapısı kavramı ve dersin amacı

Ders, jenerik sınıflar ve veri yapılarının jenerik sınıflarla kullanımı konusuyla başladı. Hoca jenerik programlamayı, farklı türden nesneler için ortak olarak kullanılabilecek, tekrar kullanılabilir kod yazmanın yolu diye tanımladı. Java ve C# gibi güncel diller jenerik yapıyı doğrudan destekler. Daha eski dillerde benzer bir altyapı, örneğin template sınıflar, bulunur ama jeneriklerin bütün yetenekleri yoktur.

Hoca dersin odağını açıkça sınırladı. Amaç veri yapılarının özelliklerini ve iç yapısını anlatmak değildir; bunlar Veri Yapıları dersinde görülür. Kendi jenerik sınıfını yazmak da ders kapsamı dışında bırakıldı; isteyen güncel bir Java kitabından öğrenebilir. Bu derste öğretilen, `java.util` paketindeki hazır jenerik veri yapılarını kullanmaktır.

Veri yapısı, bilgisayar belleğindeki verinin düzenlenmesi için kullanılan bir yöntemdir. Geniş anlamda bir `int` türünün 4 baytla nasıl temsil edildiği bile bir veri yapısıdır. Örneğin en anlamlı bit en solda ya da en sağda olabilir. Ama "veri yapısı" denince genellikle aynı türden ve birbiriyle ilişkili verilerin bir koleksiyonunun bellekte nasıl bir arada tutulduğu kastedilir.

Bu konu işin tam merkezindedir. Verinin nasıl düzenlendiği, onu kullanan programın farklı görevlerdeki başarısını belirler. Problem uygun biçimde düzenlenmezse onu çözmek için yazılan kod çok daha verimsiz olur. Hoca, probleme ve eldeki kaynaklara uygun veri yapısını seçmenin "mektepliyi alaylıdan ayıran" bir yetenek olduğunu söyledi. Sistem kaynakları artık bol olsa da doğru veri yapısını kullanıp kullanmamak çalışma süresinde ciddi farklar yaratır. Dizi de bir veri yapısıdır, hatta en temel ve en basit olanıdır, ama önemli dezavantajları vardır. Bu derste listeler ve map yapıları görülecektir.

## 2. Bağlı listeler ve dizilerle karşılaştırma

### 2.1 Bağlı liste

Bağlı liste (linked list), düğümlerden oluşan ve düğümlerin birbirini işaret ettiği doğrusal bir nesne koleksiyonudur. Her listenin bir ilk düğümü (head node) ve bir son düğümü (tail node) vardır. Java'daki hazır yapılarda bu düğümlere doğrudan ulaştıran metotlar da bulunur. Hazır sınıf kullanıldığında araya düğüm eklerken ya da aradan düğüm çıkarırken bağlantıları elle sökmek ve yeniden kurmak gerekmez. Yalnız "listeden şu elemanı çıkar" diye tek bir metot çağrılır.

Listenin bütün elemanlarını gezmek için veri yapısından bir iterator nesnesi istenir. Iterator'ın varsayılan bir gezme biçimi vardır, ama onunla farklı biçimlerde gezen kod da yazılabilir. Bütün listeyi baştan sona gezmek için iterator istemek bile gerekmez; for-each döngüsü bu işi yapar.

Slayttaki örnekte düğümlerde tamsayı veriler vardır. Her düğüm bir sonrakini gösteren bir işaretçiye sahiptir ve son düğümün işaretçisi `null`dır.

- Son düğüm `null` yerine yeniden ilk düğümü gösteriyorsa liste döngüsel (circular linked list) olur. Slaytta bu, tespihe benzetildi (ekrandan, 00:15:00).
- Her düğümde bir önceki düğümü gösteren bir bağlantı da varsa liste çift bağlıdır (doubly-linked list). Bu durumda baş düğümün "önceki" işaretçisi `null` olur.
- Tek bağlı liste yalnız bir yönde, çift bağlı liste iki yönde gezilebilir.

### 2.2 Listenin dizilere göre üstünlükleri

Slayttaki karşılaştırma şöyledir (ekrandan, 00:15:00):

- Listeyi büyütmek neredeyse hiçbir şeye mal olmaz.
- Herhangi bir konuma eleman eklemek ya da oradan eleman silmek daha hızlıdır.
- Bazı sıralama algoritmaları bağlı listelerde daha hızlı çalışır.

Diziyi büyütmek için daha geniş yeni bir dizi oluşturulur. Eski dizideki bütün elemanlar yeni diziye aktarılır. Sonra `eskiDizi = yeniDizi` atamasıyla artık yeni dizinin referans edilmesi sağlanır. Bağlı listede ise, sona ya da araya eklemek fark etmez, yalnız yeni eleman için bir düğüm yapısı ayrılır ve en fazla iki işaretçi değiştirilir. Aradan eleman çıkarmak da basittir. Örneğin 15 değerli düğüm silinecekse, ondan önceki 49 değerli düğümün `next` işaretçisi silinen düğümün `next` işaretçisinin gösterdiği yere yönlendirilir.

### 2.3 Dizilerin tek üstünlüğü

Dizinin tek üstünlüğü, herhangi bir i. elemana doğrudan erişebilmesidir. Bağlı listede aradaki bir elemana ulaşmak için listenin başından başlayıp o elemana kadar ilerlemek gerekir. Belirli bir elemana anahtarla doğrudan erişmek isteniyorsa başka bir veri yapısı, map yapısı vardır. Hoca bu nedenle "dizilere güle güle diyebiliriz" dedi.

## 3. Jenerik programlama ve ArrayList

### 3.1 Jenerik öncesi durum

Slayttaki ilk liste örneği `java.util.ArrayList` sınıfıdır (ekrandan, 00:20:00). Slaytta bu sınıf "dizilere dayalı, tek bağlı, thread-unsafe" diye tanıtılır. Bütün veri yapısı sınıfları `java.util` paketindedir.

> **Ders sonrası not:** Slayt `ArrayList` için "single-linked" ifadesini kullanıyor. `ArrayList` düğüm ve işaretçi kullanmaz, elemanları arka plandaki bir dizide tutar. Bu ifade büyük olasılıkla yalnız tek yönde gezildiğini anlatmak için yazılmıştır.

Hoca thread-safe kavramını kısaca açıkladı. Çok iş parçacıklı (multithreaded) programda kod aynı anda birden fazla işi paralel yürütür. Paralel çalışan kod ortak bir veriye erişiyorsa o veride tutarlılık sorunları çıkabilir. Bunu önlemek için thread-safe veri yapıları kullanmak gerekir. Bu yüzden her veri yapısının thread-safe olup olmadığı ayrıca belirtilecektir. `ArrayList` thread-unsafe'tir. Çok iş parçacıklı programlama dersin son konusudur.

Jenerik olmayan ilklendirme şöyledir (ekrandan, 00:20:00):

```java
ArrayList myList = new ArrayList();
```

Bu tanımda listenin düğümlerindeki varlıkların türü `Object` olur. `Object`, Java'nın "kozmik üst sınıfıdır"; hiçbir şey yazılmasa bile her sınıf aslında `extends Object` biçiminde tanımlanır. Bunun yararı, bir veri yapısına her türden elemanın konabilmesidir. Ama dizi örneklerinden hatırlandığı gibi, bir değişken hangi türden tanımlandıysa yalnız o türün metotları çağrılabilir. `Object`'te işe yarayan metotlar `toString` ve `hashCode` gibi birkaç metottur. Kendi sınıfımızın metotlarını çağırmak için tür dönüşümü (typecasting) yapmak gerekiyordu.

### 3.2 Jenerik tanım

Jenerik programlama desteği Java'ya JSE 5.0 ile geldi (ekrandan, 00:20:00). Slayttaki tanıma göre jenerik programlama, birçok farklı türdeki nesne için tekrar kullanılabilecek kod yazmaktır. Örneğin `String` ve `File` nesnelerini toplamak için ayrı sınıflar yazmak ya da kullanmak gerekmez. Tek bir `ArrayList` sınıfı her sınıftan nesneyi toplayabilir.

Liste oluşturulurken içinde hep belirli bir türden, örneğin `Person` nesneleri bulunacağı söylenir. Böylece nesneleri dönüştürmeye gerek kalmaz. For-each ya da iterator ile gezilirken eleman doğrudan o türde gelir. Tanım şöyledir (ekrandan, 00:20:00):

```java
ArrayList<Person> liste = new ArrayList<Person>();
```

Önce `ArrayList`, sonra açılı parantez içinde barındırılacak nesnelerin türü, sonra listenin adı yazılır. Eşittir işaretinden sonra `new ArrayList`, yine açılı parantez içinde tür, varsayılan kurucuyu çağırmak için açılıp kapanan parantez ve noktalı virgül gelir.

Jenerik desteği olmasaydı ve liste elle kodlansaydı, `int` tutan liste için bir kod yazılır, `char` tutan liste için aynı kod kopyalanıp `int` yazan yerler `char` yapılırdı. Her veri türü için ayrı kod yazmak gerekirdi. Java'da kendi jenerik sınıflarını yazmak da mümkündür, ama bu ders kapsamı dışında bırakıldı.

### 3.3 ArrayList'in temel metotları

Slayttaki temel metotlar şunlardır (ekrandan, 00:25:00). Burada `T`, listenin hangi türden nesne tutacağı tanımlandıysa o türdür. Önceki örnekte `T` yerine `Person` gelir.

- `add(<T> object)`: `T` türündeki nesneyi listenin sonuna ekler.
- `<T> get(int i)`: i. elemanı döndürür. `ArrayList`'in altyapısında dizi olduğu için hızlı çalışır; doğrudan erişim tek metotla yapılır.
- `int size()`: listedeki eleman sayısını döndürür.
- Bütün liste for-each döngüsüyle kolayca gezilir.

`size()` ile dizinin `length` özelliği arasında temel bir fark vardır. Dizide `length` kapasiteyi söyler, içindeki eleman sayısını söylemez. Bu yüzden dizide eleman sayısını her zaman ayrı bir sayaçla tutmak gerekir. Listede `size()` o anki eleman sayısını verir.

Diğer metotlardan bir seçki:

- `ensureCapacity(int size)`: `ArrayList`'in en az bu kadar eleman alabilmesini sağlamak için gerekirse arka plandaki diziyi genişletir.
- `trimToSize()`: kapasiteyi o anki eleman sayısına indirir.
- `set(int i, <T> element)`: i. konumdaki elemanı verilen elemanla değiştirir.
- `remove(int i)`: i. elemanı listeden siler.
- O anki eleman sayısı i'den azsa `IndexOutOfBoundsException` fırlatılır (unchecked).

Hoca `ensureCapacity` metodunun mantığını şöyle açıkladı. `ArrayList`'e yeni eleman eklenirken arka plandaki dizide yer kalmamışsa dizi genişletilir. Ne kadar genişletildiğini hoca araştırmadığını söyledi ve varsayımsal olarak her seferinde %10 artırıldığını düşündü. On bin eleman bir döngüyle hızlıca eklenirse dizi defalarca genişletilir. Genişletme tek seferde yapılsaydı kod daha hızlı çalışırdı. Bu yüzden çok sayıda eleman eklemeden önce `ensureCapacity(mevcut eleman sayısı + eklenecek eleman sayısı)` çağrılabilir. Bu metoda dizi üzerine kurulmamış başka listelerde gerek yoktur.

> **Ek bilgi (derste anlatılmadı):** Güncel OpenJDK sürümlerinde `ArrayList`, dolu dizisini yaklaşık 1,5 katına çıkararak genişletir. Bu yüzden eleman başına ortalama ekleme maliyeti sabit kalır. `ensureCapacity` yine de çok büyük toplu eklemelerde gereksiz ara kopyaları önler.

`trimToSize()` de dizi tabanlı yapıya özgüdür. Arka plandaki dizide her an bazı boş gözler kalmış olabilir. Bellek tasarrufu gerekiyorsa, örneğin eklenecek bütün elemanlar eklendiyse ya da uzun süre eleman eklenmeyecekse, `trimToSize()` çağrılarak fazladan gözler bırakılır.

`remove(int i)` ve `set(int i, ...)` metotlarında konum geçersizse, örneğin listede 50 eleman varken 90. konuma erişilirse, `IndexOutOfBoundsException` oluşur. Checked ve unchecked exception'lar ileride görülecektir. Aynı exception, dizinin olmayan bir elemanına erişince de alınır.

## 4. Java koleksiyon hiyerarşisi

Hoca bu hiyerarşiyi göstermenin asıl nedeninin, hangi veri yapısında hangi metotların kullanılabileceğini bilmek olduğunu söyledi. Slayttaki UML şeması şöyledir (ekrandan, 00:35:00):

```text
java.lang:
  <<interface>> Iterable<E>        (for-each döngüsünü mümkün kılar)

java.util:
  AbstractCollection<E>  --gerçekler-->  Iterable<E>, <<interface>> Collection<E>
  AbstractList<E>        extends AbstractCollection<E>, gerçekler <<interface>> List<E>
  Vector<E>              extends AbstractList<E>
  ArrayList<E>           extends AbstractList<E>
  AbstractSequentialList<E> extends AbstractList<E>
  LinkedList<E>          extends AbstractSequentialList<E>
  <<interface>> List<E>  extends Collection<E>
```

Notta "E, koleksiyondaki elemanların türüdür" yazar.

### 4.1 Iterable ve Collection

`java.lang` paketindeki `Iterable` arayüzü, eleman içeren ve bu elemanlar üzerinde gezilebilen bir yapı sunar. Arayüzlerde de jenerik yapı kullanılabilir. Bir sınıf `Iterable` arayüzünü gerçekliyorsa o koleksiyon for-each döngüsüyle gezilebilir.

`AbstractCollection<E>` bu arayüzü gerçekleyen soyut sınıftır. Buradan itibaren yapılar `java.util` paketindedir. Bütün veri yapıları bu sınıfın alt sınıfıdır. Bu sınıf ayrıca `Collection<E>` arayüzünü de gerçekler. `ArrayList`, `AbstractList`'in, o da `AbstractCollection`'ın alt sınıfı olduğu için `Collection` arayüzündeki metotların hepsi `ArrayList`'te tanımlı ve gerçeklenmiştir.

`Collection<E>` metotları (ekrandan, 00:35:00):

- `add(e : E) : boolean`: elemanı koleksiyona ekler. Ekleyebildiyse `true`, ekleyemediyse `false` döndürür.
- `clear()`: koleksiyonun içini tamamen boşaltır.
- `contains(o : Object) : boolean`: nesne koleksiyonda varsa `true`, yoksa `false` döndürür.
- `isEmpty() : boolean`: koleksiyon boşsa `true` döndürür.
- `iterator() : Iterator<E>`: koleksiyonda gezecek bir iterator verir. Bununla örneğin aradaki bir düğümden başlayarak ya da çift bağlı listede sondan başa doğru gezilebilir. Bunun örneği derste gösterilmedi.
- `remove(o : Object) : boolean`: verilen nesneyi koleksiyondan siler. Silebildiyse `true` döndürür. Silemediyse büyük ihtimalle nesne koleksiyonda yoktur.
- `size() : int`: eleman sayısını döndürür.

### 4.2 List arayüzü ve AbstractList

`Collection`'ın alt arayüzü `List<E>` iki metot ekler:

- `get(index : int) : E`: verilen konumdaki elemanı, koleksiyonun eleman türünde döndürür.
- `indexOf(o : Object) : int`: nesne koleksiyonda varsa konumunu döndürür. Yoksa -1 döndürür, çünkü 0 ilk konumdur.

Bu arayüzü bütün listeler destekler. Yani her liste yapısında herhangi bir konumdaki elemana ulaşılabilir. `ArrayList`'te bu iş daha hızlı, diğerlerinde daha yavaştır, ama metot hepsinde vardır.

`AbstractList<E>` bu arayüzü gerçekleyen soyut sınıftır. Hoca, adında "Abstract" geçen sınıfların zaten soyut olduğunu, bu yüzden şemada ayrıca soyut stereotipi yazmadığını söyledi. `AbstractList` metotları:

- `indexOf(e : E) : int`: bu sefer listenin eleman türünde parametre alır. Her sınıf `Object`'in alt sınıfı olduğu için iki `indexOf` aynı kapıya çıkar.
- `get(index : int) : E`: konumdaki elemanı döndürür.
- `set(index : int, e : E) : E`: konuma yeni elemanı yazar. O konumda daha önce bir eleman varsa onu döndürür.
- `remove(index : int) : E`: konumdaki elemanı siler ve silinen elemanı döndürür.

Hoca `set` ve `remove` metotlarının eski elemanı döndürmesini "son bir şans" diye açıkladı. Döndürülen eleman başka bir değişkene atanmazsa artık gereksizdir ve çöp toplayıcı (garbage collector) tarafından toplanmak üzere işaretlenir. İstenirse başka bir listeye konabilir ya da başka bir işlemde kullanılabilir.

### 4.3 Vector ve LinkedList

`ArrayList`'in yanında `Vector<E>` sınıfı vardır. Hoca `Vector`'ün thread-safe olduğunu ve ek yetenekleri bulunduğunu söyledi. Bu metotların bazıları yalnız kolaylık sağlayan sarmalayıcılardır:

- `elementAt(index : int) : E`: konumdaki elemanı döndürür. Aslında üst sınıftaki `get` metodunu çağırır; `Vector`'de de `get` kullanılabilir.
- `firstElement() : E` ve `lastElement() : E`: ilk ve son elemanı tek adımda verir. `ArrayList`'te bunlar yoktur; son eleman `get(size() - 1)` biçiminde alınır (ara adım eklendi).

`AbstractList`'in bir soyut alt sınıfı da `AbstractSequentialList<E>`'dir. Onun somut alt sınıfı `LinkedList<E>` dört ek metot sunar:

- `addFirst(e : E)`: listenin başına ekler.
- `addLast(e : E)`: listenin sonuna ekler.
- `getFirst() : E`: baştaki elemanı alır.
- `getLast() : E`: sondaki elemanı alır.

### 4.4 Bunların hepsi nasıl hatırlanır

IDE'de yazarken Ctrl+Space ile kod tamamlama metotları gösterir. Hoca kağıt üzerinde bir sınav için `Collection` arayüzündeki 7 metot ile `List` arayüzündeki `get` ve `indexOf` metotlarının, yani toplam dokuz metodun bilinmesinin yeterli olacağını söyledi. Bu şema bütün yapı değildir, yalnız derste kullanılacak `ArrayList`, `Vector` ve `LinkedList` sınıflarını içerir. Hoca Java'daki jenerik veri yapılarını konu alan başlı başına kitaplar olduğunu, derste ise bir iki haftada temellerin verildiğini söyledi.

## 5. Örnek: ders, öğrenci ve USIS (ArrayList ile)

### 5.1 Tasarım

Örnekte bir `Student` sınıfı ve bir `Course` sınıfı vardır (ekrandan, 00:45:00). Dersi alan öğrenciler arasında bir-çok sahiplik ilişkisi vardır: bir `Course` çok sayıda `Student` tutar. Jenerik sınıflar bilinmeseydi bu çokluk dizilerle kurulurdu. Burada `ArrayList` kullanılır. Denemeler `USIS` adlı bir sınıfın `main` metodunda yapılır.

```text
Course
  - code, name : String
  - students : ArrayList<Student>
  - capacity : int
  + Course( code, name : String, capacity : int )
  + getCode( ) : String
  + getName( ) : String
  + getCapacity( ) : int
  + getStudentCount( ) : int
  + addStudent( Student ) : boolean
  + increaseCapacity( newCapacity : int )
  + findStudent( number : String ) : Student
  + showClassList( )

Student
  - number, name : String
  + Student( number, name : String )
  + getNumber( ) : String
  + getName( ) : String

USIS
  + main( String[ ] ) {static}

Course 1 ---> * Student ;  USIS ...> Course ;  USIS ...> Student
```

`capacity` üye alanı yalnız iş mantığını modellemek içindir. Listenin kapasitesiyle, araya eleman eklerken kapasiteyi ikiyle çarpmak gibi işlerle hiçbir ilgisi yoktur. Bir ders belli bir kapasiteyle açılır; kapasite dolunca yeni öğrenci kabul edilmez. Talep artarsa bölüm yönetimi ek kapasite verebilir; o zaman birkaç kişi daha dersi alabilir. Dizi kullanılsaydı bu alan dizinin boyutunu da belirlerdi.

Metotlar: kod, ad ve kapasiteyi alan kurucu; bu alanların getter metotları; o anda derse kaç öğrenci kayıtlı olduğunu döndüren `getStudentCount`; derse öğrenci ekleyen ve başarıya göre `true` ya da `false` döndüren `addStudent`; yeni kapasiteyi alan `increaseCapacity`; öğrenci numarasını alıp o öğrenci dersi alıyorsa nesnesini, almıyorsa `null` döndüren `findStudent`; dersi alan öğrencileri listeleyen `showClassList`.

### 5.2 Course sınıfının kodu

Hoca önce slayttan gitti, çünkü yeni öğrenilen kısımlar slaytta koyu ve altı çizili vurgulanmıştı (ekrandan, 01:00:00 ve 01:05:00):

```java
package nyp09a;
import java.util.*;

public class Course {
    private String code; private String name; private int capacity;
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
        for( Student aStudent : students )
            System.out.println(aStudent.getNumber()+
                "  " + aStudent.getName());
    }
}
```

Kodun önemli noktaları:

- `java.util` paketi mutlaka içe aktarılmalıdır.
- Liste mutlaka ilklendirilmelidir. Sınıfta varsayılan olmayan bir kurucu olduğu için hoca ilklendirmeyi kurucuda yapmayı tercih ediyor. İstenirse alanın tanımlandığı satırda `= new ArrayList<Student>()` ile de yapılabilir; fark yoktur.
- Hoca kurucuda yapmanın küçük bir yararını da tartıştı. Kurucu kapasite bilgisini alıyor. Örneğin kapasitenin %10 fazlası kadar `ensureCapacity` çağrısı kurucunun son satırına eklenebilirdi, çünkü 50 kişilik bir dersin kapasitesi bazen 70'e çıkabiliyor. Bu, alan tanımındaki ilklendirmede yapılamaz. Ama çok önemli değildir, çünkü liste gerekli genişletmeyi zaten arka planda yapar.
- Derse kayıtlı öğrenci sayısını tutan bir sayaç yoktur. `getStudentCount`, `students.size()` değerini döndürür.
- `addStudent` önce kapasitenin dolup dolmadığına bakar. Bu, arka plandaki veri yapısıyla değil, iş mantığıyla ilgilidir. Sonra öğrencinin numarasıyla `findStudent` çağrılır. Dönen nesne `null` değilse öğrenci zaten kayıtlıdır. Bu iki durumdan birinde `false` döndürülür. Aksi hâlde `students.add(aStudent)` öğrenciyi listenin sonuna ekler ve `true` döndürülür. `add` metoduna, polimorfizm gereği, `Student`'ın alt sınıfından bir nesne de verilebilir.
- `findStudent` listeyi for-each ile gezer. Döngü, `students` bir dizi olsaydı nasıl kurulacaksa tamamen öyle kurulur. `aStudent` geçici işaretçisi her yinelemede listenin sıradaki elemanını gösterir. Numaralar `compareTo` ile karşılaştırılır ve sonuç 0 ise öğrenci döndürülür; `equals` de kullanılabilirdi.
- `increaseCapacity` yalnız iş mantığıyla uğraşır. Yeni kapasite eski kapasiteden büyük değilse işlem yapılmaz. Arka plandaki yapıyı genişletmek ya da daraltmak gerekmez.
- `showClassList` basit bir tablo başlığı yazar, sonra listeyi for-each ile gezip her öğrencinin numarasını ve adını yazar.

Slayttaki not, bu kodun dizilerle yazılabilecek kodla karşılaştırılmasını ve kodun ne kadar temizleştiğinin görülmesini ister. Ayrıca bu örnekte `capacity` üyesinin yalnız iş mantığı için var olduğunu, dizi işlemleri için olmadığını hatırlatır (ekrandan, 01:05:00).

### 5.3 USIS sınıfı ve test

`main` metodu bir `Course` nesnesi oluşturur ve kapasitesini 3 yapar. Testin mantığı şudur: her adımda beklenen sonuç alınmazsa ekrana bir "Problem #n" mesajı yazılır. Bu notta hocanın örnek nesnelerine verdiği adlar ve numaralar genel değerlerle değiştirilmiştir (ekrandan, 01:15:00):

```java
Course oop = new Course("0112562", "Obj. Or. Prog.", 3);
Student ogr1 = new Student("1001", "Ogrenci Bir");
boolean result = oop.addStudent(ogr1);
if( result == false )
    System.out.println("Problem #1");
result = oop.addStudent(ogr1);
if( result == true )
    System.out.println("Problem #2");
Student ogr2 = new Student("1002", "Ogrenci Iki");
oop.addStudent(ogr2);
Student ogr3 = new Student("1003", "Ogrenci Uc");
oop.addStudent(ogr3);
Student ogr4 = new Student("1004", "Ogrenci Dort");
if( oop.addStudent(ogr4) )
    System.out.println("Problem #3");
if( oop.findStudent("1003") != ogr3 )
    System.out.println("Problem #4");
if( oop.findStudent(ogr3.getNumber()) == null )
    System.out.println("Problem #5");
System.out.println("End of test\n");
oop.showClassList();
```

Adımlar:

1. İlk öğrenci eklenir. Henüz kimse yok ve kapasite müsait, bu yüzden `true` dönmelidir. `false` dönerse "Problem #1" yazılır.
2. Aynı öğrenci bilerek yeniden eklenir. `false` dönmelidir. `true` dönerse "Problem #2" yazılır.
3. İkinci ve üçüncü öğrenciler eklenir. Hoca bunları tek tek denetlemedi; sınıf listesinde görünmezlerse hata anlaşılır.
4. Dördüncü öğrenci kapasite nedeniyle eklenememelidir. Eklenirse "Problem #3" yazılır.
5. Üçüncü öğrencinin numarası elle yazılarak aranır. Dönen nesne, elde tutulan işaretçiyle aynı olmalıdır. Değilse "Problem #4" yazılır.
6. Bu sefer numara nesnenin kendisinden alınarak aranır. Sonuç `null` olmamalıdır. `null` ise "Problem #5" yazılır.

Program hiçbir problem mesajı vermeden "End of test" yazdı. Sınıf listesinde dersi ilk alan üç öğrenci göründü. Ardından hoca `USISv2` sürümünde kapasiteyi artırıp dördüncü öğrenciyi yeniden eklemeyi denedi. Eklenemezse "Problem #6" yazılacaktı. Problem çıkmadı, dördüncü öğrenci kapasite artırıldıktan sonra eklenebildi.

Bu kod ajan tarafından genel ad ve numaralarla `java USIS.java` komutuyla çalıştırıldı. Çıktıda problem mesajı yoktu. Önce ilk üç öğrenci, `increaseCapacity(4)` sonrasında dört öğrenci listelendi.

## 6. Dizili sürümle karşılaştırma

Hoca aynı örneği dizilerle de kodlamıştı (paket `nyp09x`). Eclipse'in iki dosyayı karşılaştırma aracıyla `nyp09a/Course.java` ile `nyp09x/Course.java` yan yana açıldı (ekrandan, 01:10:00). `main` metodu iki sürümde aynıdır, çünkü arka planda ne kullanıldığından bağımsız olarak dışarıya aynı hizmet verilmelidir.

Dizili sürümdeki farklar:

- Dizide o anda kaç eleman bulunduğunu tutmak için bir `studentCount` sayacı gerekir. Liste `ArrayList<Student>`, dizi `Student[]` türündedir.
- Kurucuda dizi kapasite kadar açılır ve sayaca 0 atanır.
- `getStudentCount` listede `size()` döndürür, dizide hazır tutulan sayacı döndürür.
- Ekleme listede doğrudan `add` ile yapılır. Dizide öğrenci ilgili konuma atanır ve sayaç bir artırılır.
- Arama dizide for-each ile yapılamaz:

```java
public Student findStudent( String number ) {
    for( int i = 0; i < studentCount; i++ )
        if( students[i].getNumber().compareTo(number) == 0 )
            return students[i];
    return null;
}
```

Diziyi örneğin 50 kapasiteyle açıp 30 öğrenci kaydettiğimizi düşünelim. 0-29 indisleri sorunsuzdur, ama 30. indisteki göz boştur ve ona erişince `NullPointerException` alınır. Bu yüzden döngü koşulu `i < students.length` değil, `i < studentCount` olmalıdır. For-each bütün gözleri gezmeye çalışacağı için dizide kullanılamaz.

**Soru:** Bir öğrenci, `ensureCapacity` ile `ArrayList`'e baştan bir kapasite verildiğinde for-each ile gezerken boş alanlarda yine `NullPointerException` alınıp alınmayacağını sordu. **Cevap:** Arka plandaki iterator boş alanlara gitmez. `ensureCapacity` yalnız o kadar eleman alacak bellek yerini ayırır. Bağlı liste yapısında da son elemanın `next` işaretçisi `null` olduğu için gezme oraya gitmez.

`increaseCapacity` iki sürüm arasındaki en büyük farktır. Listede yalnız iş mantığı kodu yazılır. Dizide yeni kapasite kadar geçici bir dizi açılır, eski dizideki her eleman yeni diziye aktarılır, `students` artık geçici diziyi gösterir ve kapasite güncellenir.

`showClassList` dizide for-each ile yazılmak istenirse boş gözler için `null` denetimi eklemek gerekir. Hoca bunu canlı gösterdi: dizili sürümde `null` denetimini yorum satırı yaptı, kapasiteyi 10'a çıkardı ve listeyi yazdırdı. Dördüncü göze gelince `NullPointerException` oluştu. Denetim geri konunca sorun kalmadı. Ajanın denemesinde de üç dolu ve yedi boş gözü olan dizi for-each ile gezilip elemanın metodu çağrılınca dördüncü gözde `NullPointerException` alındı.

Sonuç olarak liste yapısı birçok noktada diziye göre avantajlıdır.

## 7. Map yapıları ve HashMap

### 7.1 Map'in mantığı

Map yapısı, bir koleksiyondaki belirli bir elemana o elemanın tekil tanımlayıcısıyla (unique identifier, anahtar alan) kolayca erişmeyi sağlar. Aynı iş listeyle yapılsaydı bütün elemanları baştan sırayla, aranan bulunana kadar tek tek gezmek gerekirdi. Slayta göre bu işlem map ile dizi ve listeden çok daha hızlıdır (ekrandan, 01:20:00). Koleksiyondaki nesnelere value (element), tekil tanımlayıcıya key denir. Koddaki `K` ve `V` kısaltmaları buradan gelir.

### 7.2 Map hiyerarşisi

`java.util` paketinde bir `Map<K,V>` arayüzü vardır. Listeler için `List` arayüzü nasıl varsa map yapıları için de `Map` arayüzü vardır. Açılı parantez içinde artık iki tür yazılır ve virgülle ayrılır: `K` anahtar alanın türü, `V` koleksiyondaki nesnelerin türüdür.

Arayüzün metotları (ekrandan, 01:20:00):

- `get(key : Object) : V`: parametre `K` türünden olmak zorunda değildir. O anahtara sahip bir değer varsa döndürür.
- `put(key : K, value : V) : V`: nesneyi verilen anahtarla yapıya ekler. Aynı anahtara sahip başka nesne varsa yenisi üzerine yazılır ve silinen eski nesne döndürülür.
- `remove(key : Object) : V`: anahtara sahip nesneyi siler ve onu döndürür.
- `values() : Collection<V>`: koleksiyondaki bütün değerleri döndürür; for-each bunun üzerinde kurulur.
- `isEmpty() : boolean`, `size() : int`, `containsKey(k : Object) : boolean`, `containsValue(v : Object) : boolean`.

Map'teki değerler doğrudan for-each döngüsüne konamaz. Önce `values()` ile değerlerin bir koleksiyonu alınır. Bu dönen tür, listeler şemasındaki `Collection` arayüzüdür. Böylece iki şema birbirine bağlanır.

`AbstractMap<K,V>` bu arayüzü gerçekleyen soyut sınıftır. Alt sınıfı `HashMap<K,V>` thread-unsafe'tir. `Hashtable<K,V>` ise `Map` arayüzünü doğrudan gerçekler ve thread-safe'tir. Slayttaki notta çok iş parçacıklı programlamanın ileride görüleceği yazar.

### 7.3 Hashtable'daki küçük t

`Hashtable` adındaki "t" küçüktür. Normal camel casing uygulansaydı büyük olmalıydı; `HashMap`'te "M" büyüktür. Hoca bunun nedenini bilmediğini, belki tek bir birleşik kelime gibi düşünüldüğünü ya da unutulduğunu söyledi. Sınıfın jenerik olmayan sürümü Java 1.0'dan beri vardır ve ad öyle kalmıştır.

### 7.4 Thread-safe yapıların bedeli

Thread-safe bir yapı, gerekli senkronizasyonu sağlayan ek işlevlere sahiptir. Bu yüzden ekleme, silme ve arama metotları thread-unsafe sürüme göre biraz daha yavaştır. Çok iş parçacıklı kod yazılmıyorsa thread-unsafe yapıları seçmek daha doğrudur. Çok iş parçacıklı programlamada ise hatalarla karşılaşmamak için thread-safe yapılar kullanılmalıdır. Ders kapsamında her iki map'e de `Map` arayüzü üzerinden erişilecektir.

### 7.5 Liste ile map metotlarının karşılaştırılması

Hoca bir an duraksayıp düzelterek şunu özetledi: liste yapılarında ekleme `add`, erişim `get` ile yapılır. Map yapılarında ise `put` ve `get` kullanılır. Map'teki bütün nesneleri gezmek için doğrudan for-each yazılamaz, `.values()` ile gezilir.

Slayttaki ayrıntı (ekrandan, 01:30:00): `java.util.HashMap<K,V>` sınıfında `K` key, `V` value'dur. `put` için, anahtarı değerin kendisinden, tekil tanımlayıcıya erişen getter metoduyla almak önerilir. `values()` için şu an jenerik `Collection` arayüzünün ayrıntılarını bilmek gerekmez.

## 8. Örneğin HashMap ile yeniden yazılması

Map kullanmanın temel amacı belirli bir anahtara sahip nesneye doğrudan ulaşmaktır. Öğrencilerin anahtar alanı öğrenci numarasıdır. Bir dersteki öğrenci sayısı 50-120 arasında olduğu için günümüz bilgisayarlarında kazanç küçük olur. Ama bütün üniversitenin öğrencileri ya da bir ülkenin nüfus kayıtları arasında arama yapılıyorsa avantaj kendini gösterir. Örnek, metotlar farklı olduğu için gösterildi. Sınıf şeması neredeyse aynıdır; yalnız `students` artık bir map'tir.

Değişen satırlar `nyp09a` ile `nyp09b` paketlerinin karşılaştırmasında görülür (ekrandan, 01:35:00):

```java
private HashMap<String, Student> students;
...
students = new HashMap<String,Student>();
...
public int getStudentCount() {
    return students.size();            // değişmedi
}
public boolean addStudent( Student aStudent ) {
    if( getStudentCount() == capacity ||
            findStudent(aStudent.getNumber()) != null )
        return false;
    students.put(aStudent.getNumber(), aStudent);
    return true;
}
public Student findStudent( String number ) {
    return students.get(number);
}
...
for( Student aStudent : students.values() )
    System.out.println(aStudent.getNumber()+ "  " + aStudent.getName());
```

- Öğrenci numarası `String` olduğu için anahtar türü `String`, değer türü `Student`'tır.
- `getStudentCount` yine `students.size()` döndürür.
- `addStudent` içindeki `if` koşulu aynıdır. Ekleme `put` ile yapılır. İlk parametre anahtardır ve nesnenin kendi `getNumber()` metoduyla alınır; ikinci parametre nesnenin kendisidir.
- `findStudent` tek satıra iner: `students.get(number)`. Bulursa nesneyi, bulamazsa `null` döndürür. Liste sürümünde her eleman tek tek denetleniyordu; iş hem basitleşti hem arka planda hızlandı.
- `increaseCapacity` aynıdır. `showClassList` yalnız gezme satırında farklıdır: `students` yerine `students.values()`.

### 8.1 Testte çıkan beklenmedik "Problem #3"

`nyp09b` çalıştırıldığında beklenmedik biçimde "Problem #3" yazıldı. Hoca bunun nedenini araştırdı: önceki bir denemeden kalma olarak kapasite 30 yazılmıştı. Kapasite 30 iken dördüncü öğrenci eklenebildiği için test "problem" dedi. Kapasite yeniden 3 yapılınca problem kalmadı. Hoca ayrıca iki paketteki `if (oop.addStudent(...))` satırının tutarlı olduğunu denetledi; birinde önceden kalan bir olumsuzlama (`!`) silindi. Sonuçta alttaki veri yapısı sorunsuzca değiştirildi. Kazanç, belirli numaralı öğrenciye daha kolay ve doğrudan erişmek oldu; diğer avantajlar değişmedi.

### 8.2 Aynı anahtarla iki öğrenci

Hoca bir önceki yılın dersinde denenmiş ek bir test gösterdi (ekrandan, 01:40:00). Aynı öğrenci numarasına sahip iki farklı öğrenci olamaz. Bunun doğruluğundan, her öğrenciye farklı numara veren öğrenci işleri sorumludur. Ama numara yanlışlıkla aynı yazılmış olabilir. Bir nesnenin tekil tanımlayıcısının öğrenci numarası olması iş mantığıdır ve buna aykırı kod yazmayı engellemez; dikkatli olmak programcının işidir. Hocanın örnekteki adları burada genel adlarla değiştirilmiştir:

```java
Student std = new Student("011011007", "Ornek Ogrenci A");
oop.addStudent(std);
Student nur = new Student("011011007", "Ornek Ogrenci B");
oop.addStudent(nur); //bunu yapabilmemiz bir sorun olacaktır!
if( oop.findStudent("011011007") == nur )
    System.out.println("Problem #5");
if( oop.findStudent("011011007") != std )
    System.out.println("Problem #6");
oop.showClassList();
```

`addStudent` önce `findStudent` ile aynı numaralı öğrenci var mı diye bakar. Varsa `false` döndürür ve ekleme baştan engellenir. Bu yüzden ikinci öğrenci derse eklenmemelidir. Aranan numarayla ilk öğrenci (`std`) dönmeli, ikinci öğrenci (`nur`) dönmemelidir. Aksi hâlde "Problem #5" ya da "Problem #6" yazılır. Testi yapabilmek için kapasite 30'a çıkarıldı. Bu yüzden dördüncü öğrenci eklenebildi ve bilinen "Problem #3" mesajı çıktı. Ama "Problem #5" ve "Problem #6" görülmedi ve listeye yalnız ilk öğrenci eklendi. Hoca sonra numaranın başındaki fazladan sıfırı düzeltti.

Ekrandaki çıktıda öğrenciler ekleme sırasıyla listelenmedi (ekrandan, 01:40:00 ve 01:45:00). Ajanın `HashMap<Integer, Student>` ile yaptığı denemede de aynı durum görüldü.

> **Ek bilgi (derste anlatılmadı):** `HashMap` elemanları anahtarların hash değerine göre yerleştirir. `values()` ile gezme sırası ekleme sırası değildir ve garanti edilmez. Ekleme sırası korunmak istenirse `LinkedHashMap`, anahtara göre sıralı gezme istenirse `TreeMap` kullanılır.

## 9. Anahtar olarak ilkel tür ve otomatik sarmalama

Hoca slayta yazmayı unuttuğu bir kuralı ekledi: key ve value ilkel tür olamaz. Bu durumda sarmalayıcı sınıflar devreye girer. Öğrenci numarası `int` olarak saklansaydı anahtar `int` olurdu. Ama jenerik map yapılarında anahtar ilkel olamaz. Bu yüzden `int` yerine sarmalayıcısı `Integer` kullanılır. Bilinmesi gereken tek şey budur.

`nyp09c` paketinde öğrenci numarası `int` olarak tanımlandı (ekrandan, 01:45:00):

```java
public class Student {
    private int number;
    private String name;

    public Student(int no, String name) {
        this.number = no;
        this.name = name;
    }
    public int getNumber() {
        return number;
    }
    public String getName() {
        return name;
    }
}
```

`Course` içinde map türüne `int` yazılınca Eclipse sözdizimi hatası verir. Hata açıklayıcı değildir, ama nedeni anahtar olarak ilkel türün kullanılmasıdır; ilgili sarmalayıcı yazılmalıdır: `HashMap<Integer, Student>`.

Peki `Student` sınıfında da numarayı `Integer` yapmak gerekir mi? Hoca eski Java sürümlerinde `getNumber` metodunun ilkeli değil, `new Integer(number)` ile oluşturulmuş bir sarmalayıcı döndürmesi gerektiğini gösterdi. Bu kurucu sonradan kullanımdan kaldırıldı (deprecated). Otomatik sarmalama (autoboxing) özelliği sayesinde artık gerekmez. "Boxing" burada kutuya koyma, sarmalama anlamındadır. `Integer` beklenen yere `int`, `Character` beklenen yere `char` verildiğinde gerekli dönüşüm otomatik yapılır; sarmalayıcıdan ilkele dönüşüm de öyledir.

> **Ders sonrası not:** Hoca otomatik sarmalamanın Java 6.0 ile geldiğini söyledi. Otomatik sarmalama ve kutudan çıkarma (unboxing), jeneriklerle birlikte Java 5.0'da (JDK 1.5) geldi.

Bir otomatik sarmalama örneği de `findStudent` metodudur. Parametre `int number` ilkeldir. Map'in `get` metoduna doğrudan bu ilkel verilir, çünkü Java gerekli dönüşümü kendisi yapar. Sonuç: anahtar tanımlanırken ilkel değil sarmalayıcı yazılır; ama nesnelerdeki ilkel alanları kaynak kodda sarmalayıcıya çevirmek gerekmez.

Ajanın denemesinde `HashMap<Integer, Student>`, `int` numaralı `Student` ve `students.get(number)` / `students.put(aStudent.getNumber(), aStudent)` satırları ek dönüşüm yazmadan `java USISMap.java` ile derlenip çalıştı.

Hoca `nyp09c` içindeki `PreTypeCasting.java` dosyasını da kısaca açtı (ekrandan, 01:50:00). Bu dosyada jenerik olmayan bir listeye bir `Course` ve birkaç `Student` nesnesi eklenmiş, sonra `for (Object iter : list)` döngüsünde `instanceof` ile tür denetlenip `(Course)iter` ya da `(Student)iter` dönüşümleri yapılmıştır. Hoca, jenerikler desteklenmeden önce koleksiyonların yalnız `Object` tutabildiğini ve tür dönüşümü yapmak gerektiğini hatırlattı; ayrıntısına girmedi.

## 10. Veri yapılarının özeti

Hoca örneklerin `ArrayList` ve `HashMap` üzerinde yapıldığını, ama liste örneğinin `LinkedList` ya da `Vector` ile de yapılabileceğini söyledi. İş mantığı `ArrayList`'e özgü hiçbir şeye dayanmıyordu. Bunu göstermek için `nyp09a` paketini `nyp09d` olarak kopyaladı ve `Course` içinde `ArrayList` yerine `LinkedList` yazdı. Başka hiçbir şeyi değiştirmeden `USIS` yeniden çalıştırıldı ve hiçbir problem mesajı çıkmadı. Önemli olan, ihtiyaca uygun veri yapısını kullanmaktır.

Slayttaki özet (ekrandan, 02:05:00):

- `java.util.LinkedList<E> implements List<E>`
  - Ekleme ve silme daha hızlı.
  - Rastgele erişim daha yavaş, çünkü elemana baştan ilerleyerek ulaşılır.
  - Çift bağlı. Bir `ListIterator` alınarak geriye doğru da gezilebilir; bu derste anlatılmadı.
- `java.util.ArrayList<E> implements List<E>`
  - Ekleme ve silme daha yavaş.
  - Rastgele erişim daha hızlı, çünkü arka planda dizi kullanır.
- `java.util.Vector<E> implements List<E>`
  - `ArrayList`'e benzer.
  - Senkronize, yani thread-safe.
  - Çok iş parçacıklı kullanım için uygun, tek iş parçacığında daha yavaş.
- `java.util.HashMap<K,V> implements Map<K,V>`
  - Anahtara göre hızlı arama için kullanılır (indekslenmiş).
- `java.util.Hashtable<K,V> implements Map<K,V>`
  - `HashMap`'e benzer ama senkronize; çok iş parçacıklı kullanım için uygun, tek iş parçacığında daha yavaş.
  - Dikkat: sınıf adındaki "t" küçüktür.

`ArrayList` ile `LinkedList` birbirinin tam tersi özelliklere sahiptir. İkisi de thread-unsafe'tir. Çok iş parçacıklı bir programda liste gerekiyorsa `Vector` kullanılır. `Vector` de `List` arayüzünü gerçekler ve diğerleri gibi kullanılır. Hoca, `Vector`'ün tek iş parçacığındaki yavaşlığının 50-200, hatta 1000-2000 nesnede hissedilmeyeceğini, ama çok fazla kayıt içeren büyük sistemlerde bilinmesi gerektiğini söyledi.

## 11. Aykırı durum işleme: neden ve hiyerarşi

### 11.1 Neler ters gidebilir

Hoca "exception handling" için "aykırı durum işleme" çevirisini kullanıyor; "istisna yönetimi" diye çevirenler de var. Konuya Murphy kanunuyla girdi: bir şeyin yanlış gitme olasılığı varsa mutlaka yanlış gider. Kod yazarken ters gidebilecek şeyler şunlardır:

- Programcının hatası: örneğin az önce görülen, olmayan bir elemana erişince alınan `NullPointerException`. Bu, koddaki bir hatadan (bug) kaynaklanır.
- Java sanal makinesindeki hatalar: sanal makinede de hatalar vardır, güncellemeler bunları gidermek için gelir. Ama günlük kullanımda genelde etkilemez; çok büyük, karmaşık ve eski tümleşik sistemlerde nadiren sorun çıkarabilir.
- Kullanıcının yanlış girdisi: sayı beklenirken harf girmek ya da ondalıklı sayıda nokta ve virgülü karıştırmak gibi.
- Programcının denetleyemediği dış etkenler: bir IP adresinden diğerine paket gönderirken ağda aksaklık olabilir. Bir dosya bir bilgisayarda yazılabilirken başka bir kullanıcının bilgisayarında o dizine yazma hakkı olmayabilir.

Bu durumlara her zaman müdahale edilemez. Ama farkında olup üstesinden gelmeye çalışmak, gelinemiyorsa sorunu bildirip çözülmesini sağlamak programcının sorumluluğudur.

Hatalarla uğraşmanın birden fazla yolu vardır. Şimdiye kadar başarıya göre `true` ya da `false` döndüren metotlar yazıldı. Bir başka yol, örneğin yalnız sayı kabul eden ve geçersiz girdide varsayılan değer kullanan bir metin alanı tanımlamaktır; bu derste görülmeyecek. Üçüncü yol olan exception handling, ortaya çıkan hatayı yakalamaya dayalı bir çalışma biçimidir ve bu dersin konusudur.

### 11.2 Exception hiyerarşisi

`null` bir nesneye erişmek, sıfıra bölmek, erişim hakkı olmayan bir dosyaya erişmek gibi farklı aykırı durumlar farklı sınıflarla modellenir. Bu sınıflar bir hiyerarşi oluşturur. Slayttaki şema şöyledir (ekrandan, 02:15:00):

```text
Throwable
├── Error                 (unchecked)
└── Exception
    ├── IOException       (checked)
    └── RuntimeException  (unchecked)
```

`IOException` dışındakilerin hepsi `java.lang` paketindedir; `IOException` ise `java.io` paketindedir.

- `Error`: Java sanal makinesinde ortaya çıkabilecek hataları modeller. Alt sınıflarından biri `UnsupportedClassVersionError`'dır. Hoca bunu yaşadığı bir örnekle anlattı: eski bir JDK sürümü için derlenmiş sınıf dosyaları, Eclipse'in daha yeni bir sürümüyle açılınca bu hata alındı. Eclipse kendi derleyicisini içerdiği için eski sürüm sınıf dosyalarıyla sorun yaşadı. Sınıf dosyaları silinip proje yeniden içe aktarılınca sorun çözüldü.
- `IOException`: girdi/çıktı işlemlerindeki aykırı durumlar içindir. Yalnız dosya okuma ve yazma değil, ağ üzerinden veri paketi göndermek ve almak, komut satırına yazmak ve oradan okumak da girdi/çıktı işlemidir.
- `RuntimeException`: kodlama sırasında değil, program çalışırken ortaya çıkabilecek durumlar içindir; örneğin sayı beklenirken harf girilmesi. Genelde programcının kendi hatalı kodundan kaynaklanır: `NullPointerException`, `IndexOutOfBoundsException`.

Ders kapsamında genelde hiyerarşinin en altındaki `IOException` ya da `RuntimeException` kullanılacaktır.

> **Ek bilgi (derste anlatılmadı):** `ArithmeticException` (sıfıra bölme), `NumberFormatException` ve `InputMismatchException` gibi sınıflar `RuntimeException`'ın, `FileNotFoundException` ise `IOException`'ın alt sınıflarıdır. Bu yüzden ilk üçünü yakalamak zorunlu değildir, sonuncusu için zorunludur.

### 11.3 Checked ve unchecked

Exception'lar sınıf hiyerarşisinden bağımsız olarak ikiye ayrılır:

- **Unchecked:** kodda işlenmesi zorunlu değildir. Örneğin sayı beklenirken harf girilmesi her seferinde denetlenmek zorunda değildir, çünkü her kullanıcı bu hatayı yapmaz. Yapılırsa exception oluşur ve program kesilebilir; kullanıcı bir dahaki sefer doğru girer. Ama bunun olmaması isteniyorsa exception yine de işlenebilir.
- **Checked:** girdi/çıktı işlemlerinde bir şeyin ters gitme olasılığı çok daha yüksektir. Bu yüzden bu exception'ların mutlaka ele alınması gerekir.

İş mantığında unchecked bir exception gerekiyorsa `RuntimeException`, checked bir exception gerekiyorsa `IOException` kullanılacaktır. Java'da bazı hazır metotlar checked exception oluşturur. Şimdiye kadar buna ihtiyaç olmadı, ama bundan sonraki konularda olacaktır.

## 12. try, catch ve finally

### 12.1 try-catch

Checked exception'ları işlemek bir try-catch bloğuyla yapılır (ekrandan, 02:20:00):

```java
try {
    /* error-prone methods */;
}
catch( AnException e ) {
    /* Dealing with error */
}
```

Exception oluşturabilecek metotlar `try` bloğuna alınır. Ardından bir `catch` bloğu açılır. `catch` bir fonksiyon imzası gibi düşünülebilir: parantez içine yakalanacak exception'ın türü ve bir nesne adı yazılır; `e` gibi tek harf yeterlidir. Oluşan exception nesnesi bu işaretçi üzerinden `catch` bloğuna gelir. `catch` bloğuna hatayı gidermek ya da bildirmek için gereken kod yazılır. Genelde bu, hatanın ne olduğunu yazdırmaktır, ama hassas sistem kaynaklarının bırakılması da gerekebilir.

Metotların oluşturabileceği exception'lar unchecked ise try-catch yazmak gerekmez. Checked ise mutlaka ele alınmalıdır.

### 12.2 throws ile çağırana bırakmak

Checked exception illa ki bulunduğu yerde try-catch içine alınmak zorunda değildir. Bu komutlar bir sınıfın bir metodu içindedir. Metodun imzasının sonuna `throws AnException` yazılarak "bu metot bu exception'ı oluşturabilir" diye bildirilir; o zaman metot içinde try-catch gerekmez. Ama bu sefer o metodu çağıran yerde try-catch yazmak zorunludur. Yani checked exception er ya da geç bir yerde try-catch ile ele alınır; bunun başka kaçışı yoktur.

### 12.3 Birden çok catch ve tek try

Metotlar farklı türde exception'lar oluşturabiliyorsa her biri için ayrı bir `catch` bloğu açılır, çünkü her biriyle farklı biçimde uğraşmak gerekebilir. Hepsiyle aynı biçimde uğraşılacaksa tek bir `catch` içinde birleştirilebilirler; hoca bunun ileride geleceğini söyledi.

Hoca burada bir noktayı özellikle vurguladı: exception oluşturabilecek her metot için ayrı `try` bloğu açılmaz. Hocaya göre her `try` bloğu çalışma zamanına ek yük getirir; "try aç, try kapa" biçiminde çalışmak programı yavaşlatır. Bu yüzden ilişkili metotlar, aralarında exception oluşturmayanlar olsa bile, tek bir `try` gövdesine alınır. Bir metotta bir `try` ve bir ya da daha fazla `catch` bulunur.

> **Ders sonrası not:** Güncel JVM'lerde exception oluşmadığı sürece bir `try` bloğuna girmenin çalışma zamanı maliyeti büyük olasılıkla ihmal edilebilir düzeydedir. Asıl maliyet exception nesnesinin oluşturulup fırlatılmasındadır. Yine de ilişkili işlemleri tek `try` içinde toplamak, kodun okunabilirliği ve hatanın bir bütün olarak ele alınması açısından iyi bir alışkanlıktır.

### 12.4 catch bloğunda ne yapılmalı

`catch` bloğunda kullanıcıya hata ve nedeni hakkında bilgi veren bir mesaj gösterilmeli ve exception nesnesinin `printStackTrace()` metodu çağrılmalıdır. Bu, en azından yapılması gerekendir. İstenirse kayıt ayrı bir log dosyasına yazılabilir, açık kaynak kayıt kütüphaneleri kullanılabilir ya da bir yere e-posta gönderilebilir. Ders kapsamında mesaj ve `e.printStackTrace()` yeterlidir.

### 12.5 finally

Hata çok ciddiyse ve o anda kritik sistem kaynakları ayrılmışsa, bu kaynakları sisteme geri vermek ve programdan temiz bir çıkış (clean exit) sağlamak gerekir. Bunun için en son `catch` bloğundan sonra bir `finally` bloğu yazılır. `finally`, `try` içinde exception olsa da olmasa da yürütülür. Hoca bu blokta `try` içinde tanımlanan geçici değişkenlere erişilebildiğini söyledi.

> **Ders sonrası not:** Hoca `finally` bloğunun `try` içinde tanımlanan değişkenlere erişebildiğini söyledi; doğrusu, `try` bloğunun içinde tanımlanan bir değişkenin kapsamı o blokla sınırlıdır ve `finally` içinden görülmez. `finally` içinde kullanılacak kaynak değişkeni (örneğin `graphics` ya da `in`) `try` bloğundan önce tanımlanmalıdır; dersteki iki örnekte de böyledir.

`finally` isteğe bağlıdır; ama hassas sistem kaynakları alınmışsa burada serbest bırakılmalıdır.

### 12.6 Hayali örnek: ExceptionExample01

Hoca bir hayali örnekle kullanımı gösterdi (ekrandan, 02:30:00). `MyScreenRenderer` türünden bir grafik nesnesi ekran kartının denetimini alır. Üç boyutlu nesnelerin bilgileri bir CAD dosyasından okunur ve grafik nesnesiyle ekrana çizilir.

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
                " while opening or reading from file "+fileName+":"
                + e.toString( ) );
            e.printStackTrace( );
            System.exit(1); //Multithreaded, allows finally to be run
        }
        finally {
            graphics.releaseSources();
        }
    }
}
```

Olası sorunlar: dosyaya erişilemeyebilir, ya da dosya açılır ama içindeki şekil bilgileri bozuk (corrupt) ya da tutarsız olabilir. Bu durumlarda grafik kaynağı geri bırakılmalıdır; yoksa sistem çökebilir.

- `catch (IOException e)` bloğu önce hangi dosyayı okurken `IOException` oluştuğunu yazar. `e.toString()` exception'ın adını, örneğin `java.io.IOException`, tam adıyla verir.
- `e.printStackTrace()` exception'a yol açan metot çağrıları zincirini gösterir.
- `System.exit(1)` programdan çıkar. Hata olduğunu belirtmek için parametre 0 değil 1'dir.
- `finally` içinde `graphics.releaseSources()` ile ayrılan kaynaklar bırakılır.
- `try` içindeki `drawFigures` ya da `MyScreenRenderer` oluşturmak `IOException` oluşturmaz. Ama bu satırlar birbiriyle ilişkili olduğu için hepsi tek `try` içine alınmıştır. `openFile`, `readFromFile` ve `close` için ayrı `try` blokları açılmamıştır.

Hoca `myFile.close()` ile `drawFigures` satırlarının yeri değiştirilebilir dedi; fark etmeyecektir.

> **Ders sonrası not:** Hoca ve slayttaki yorum, `System.exit(1)` çağrılsa bile sanal makinenin `finally` bloğunu yürüteceğini söylüyor. `System.exit` çağrısı geri dönmez ve `finally` blokları çalıştırılmaz; yalnız kayıtlı kapanış kancaları (shutdown hooks) çalışır. Ajanın `catch` içinde `System.exit(1)` çağıran küçük denemesinde `finally` içindeki yazı ekrana çıkmadı. Kaynağın kesin bırakılması isteniyorsa `releaseSources()` `System.exit`'ten önce çağrılmalıdır.

## 13. Kendi exception sınıfını yazmak ve fırlatmak

### 13.1 Neden kendi exception'ımız

Önceki örnekteki `drawFigures` metoduna verilen şekiller tutarsızsa ne olacak? Örneğin bir üçgen çizilmesi isteniyor ama yalnız iki noktası var. Üçgenin üç köşesi olur; dosyaya üçgen bilgisi hatalı yazılmıştır ve çizilemez. Exception handling ile bu duruma özgü bir exception tanımlamak gerekir.

### 13.2 Türetme kuralı

Önce exception'ın checked mı unchecked mı olacağına karar verilir. Slayttaki kural (ekrandan, 02:35:00):

- Checked exception isteniyorsa `IOException`'dan kalıtımla türetilir.
- Unchecked exception isteniyorsa `RuntimeException`'dan kalıtımla türetilir.

Hocanın slayttaki örneği `MyFileFormatException`'dır. Exception'ın checked olmasına karar verildiği için `IOException`'dan türetilmiştir. Bu sınıfın kodu görülen karelerde yoktur; aşağıdaki biçim hocanın anlatımından kurulmuştur:

```java
import java.io.IOException;

public class MyFileFormatException extends IOException {
    public MyFileFormatException(String message) {
        super(message);
    }
}
```

<!-- BELİRSİZ: MyFileFormatException slaytının tam metni görülen karelerde yok; kod anlatımdan kuruldu. -->

Dosyanın başına `import java.io.IOException;` yazılmalı ya da doğrudan `extends java.io.IOException` denmelidir. Hoca JDK 5'e kadar bir varsayılan kurucu yazıp `super()` ile üst sınıf kurucusunu çağırmak gerektiğini, artık gerekmediğini söyledi. Asıl yazılması gereken, hata açıklamasını `String` parametre olarak alan ve onu `super` ile üst sınıfın kurucusuna ileten kurucudur. Başka yapılacak iş varsa uygulama mantığına göre eklenir.

> **Hocanın vurgusu:** Açıklama metni alan kurucuyu yazmak dil açısından zorunlu değildir; yazılmasa da kod derlenir. Ama son kullanıcı `printStackTrace` ile yazılan olaylar zincirinden bir şey anlamaz; programın neden durduğuna anlamlı bir yanıt verilmelidir. Hoca bu kurucunun sınavlarda ve projelerde mutlaka yazılmasını istedi.

Bazı öğrenciler kendi exception sınıflarını doğrudan `Exception`'dan türetiyor. Hoca bu durumda exception'ın checked mı unchecked mı olacağının belli olmadığını, JDK sürümlerine göre farklılık olabileceğini söyledi. Garanti olan, checked için `IOException`, unchecked için `RuntimeException` kullanmaktır.

> **Ders sonrası not:** Java dil tanımına göre `RuntimeException` (ve `Error`) soyundan gelmeyen her `Exception` alt sınıfı checked'tir ve bu JDK sürümüne bağlı değildir. `extends Exception` ile türetilen sınıf da checked olur. Hocanın `IOException`/`RuntimeException` önerisi niyeti açık gösteren bir ders kuralı olarak düşünülebilir.

### 13.3 Exception fırlatmak (throw)

Exception oluşturmanın terimi "fırlatmak"tır (throw). Örneğin dosya işleyen bir metot içinde olmaması gereken bir durum `if` ile fark edilirse, kendi exception nesnemiz `new` ile oluşturulur ve başına `throw` konur:

```java
throw new MyFileFormatException("açıklayıcı hata metni");
```

<!-- BELİRSİZ: bu satırın slayttaki tam biçimi görülen karelerde yok; biçim anlatımdan kuruldu. -->

Kurucuya, hangi beklenmedik durumun gerçekleştiğini açıklayan metin verilir. Exception checked ise burada try-catch içine almak gerekir gibi görünür. Ama bunu fırlatan metotta yakalamak mantıksızdır: sorunu fark eden bu metottur, onu işleyecek olan çağırandır. Bu yüzden metodun imzasının sonuna `throws MyFileFormatException` eklenir. Metodu çağıran, try-catch ile exception'ı ele alır; sorunu çözebiliyorsa çözer, çözemiyorsa çözebilecek birine iletir. Örneğin hatalı dosyayı bu metot düzeltemez; yalnız sorunu ve kaynağını bildirir.

## 14. Uygulama: ImpossibleInfo ve Person

### 14.1 Senaryo

Genel bilgiyi pekiştirmek için hoca bir kişi örneği yaptı. Kişinin adı ve yaşı vardır. Yaş negatif olamaz ve 150'den büyük olamaz. Bu denetim `if-else` ile de yapılabilir, ama burada exception ile yapılacaktır. Aynı mantık başka olanaksız veriler için de geçerlidir; örneğin 300 cm ya da -150 cm boy. Olanaksız bir veri yakalanınca exception fırlatılarak uygulama mantığının tutarlılığı sağlanır.

Hoca exception'ın checked olmasını seçti. Unchecked olsaydı try-catch zorunlu olmayacaktı. Checked yapınca neyin nerede yapılması gerektiği daha iyi görülür.

### 14.2 ImpossibleInfo sınıfı

Slayttaki kod (ekrandan, 02:45:00):

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

Kurucu yalnız üst sınıfın açıklama metni alan kurucusunu çağırır; başka bir şey gerekmez. `IOException`'dan bir exception türetilince Java bir `serialVersionUID` tanımlanmadığına dair uyarı verir. Bu uyarı `@SuppressWarnings("serial")` ile kapatılır.

`@` ile başlayan satırlara annotation denir. Hoca bunların Java sanal makinesi tarafından işlenmediğini, bir yorum gibi ele alındığını söyledi. Bu annotation'ları işleyen yardımcı programlar vardır; örneğin Eclipse'in kendisi. Belirli bir konudaki uyarılar hiç gösterilmesin isteniyorsa `@SuppressWarnings` kullanılır. Kalıtım konusunda görülen `@Override` da bir annotation'dır. `serialVersionUID` ileride, akışlarla (stream) dosya erişimi konusunda anlatılacaktır.

> **Ek bilgi (derste anlatılmadı):** Annotation'ların hepsi yorum gibi yok sayılmaz. `@Override` ve `@SuppressWarnings` derleyici tarafından işlenir. Çalışma zamanında tutulacak biçimde tanımlanan annotation'lar ise programın kendisi tarafından yansıma (reflection) ile okunabilir.

### 14.3 Person sınıfı

`Person` sınıfının bir adı ve yaşı vardır. Kurucu adı alır. Ad ve yaş için getter metotları, yazdırmak için `toString` metodu vardır. Kişinin adı değiştirilemez, bu yüzden `setName` yoktur. Yaş değiştirilebilir, ama `setAge` doğrudan atama yapmaz, önce denetler:

```java
public void setAge(int age) throws ImpossibleInfo {
    if (age < 0 || age > 150)
        throw new ImpossibleInfo("Impossible age " + age);
    this.age = age;
}
```

<!-- BELİRSİZ: Person sınıfının slaytı görülen karelerde yok. setAge biçimi anlatımdan ve 450 denemesinde görülen "Impossible age 450" mesajından kuruldu. -->

Yaş 0'dan küçük ya da 150'den büyükse `throw new ImpossibleInfo(...)` ile "olanaksız yaş" açıklaması ve gelen yaş değeri bildirilir. Sorun yoksa atama yapılır. `ImpossibleInfo` checked olduğu için burada derleme hatası alınır. Ama burada try-catch yazılmaz: sorunu ele alması gereken, `setAge`'i saçma bir değerle çağırandır. Bu yüzden imzanın sonuna `throws ImpossibleInfo` eklenir.

### 14.4 TestExceptions sınıfı

Slayttaki kod (ekrandan, 02:50:00):

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

- `setAge` çağrısı exception oluşturabileceği için try-catch içine alınır. Ama `try`, `setAge`'ten hemen önce değil, yaşı soran satırdan başlar. Yaşı sormak, okumak, atamak ve sonucu yazdırmak birbiriyle ilişkili işlerdir ve birlikte `try` içindedir. Hoca `try`'ın en baştan da açılabileceğini, ama gerek olmadığını söyledi.
- `catch` bloğu `ImpossibleInfo` için açılır ve `e.printStackTrace()` çağrılır. `printStackTrace` ilk satırda kurucuya verilen "olanaksız yaş" açıklamasını da yazar; açıklama kurucusu yazılmazsa bu bilgi çıkmaz.
- `Scanner` exception olsa da olmasa da kapatılmalıdır. `in.close()` `try` içinde olsaydı, `setAge` exception fırlattığında aşağıdaki satırlara hiç geçilmezdi ve `Scanner` kapatılmadan çıkılırdı. Bu yüzden `finally` bloğuna yazılır.

Hoca çalışan kodda `catch` içine `System.out.println(e.toString());` satırını da ekledi (ekrandan, 02:55:00).

### 14.5 Çalıştırma

Hoca programı çalıştırıp bir ad girdi. Geçerli bir yaş girilince sorun çıkmadı ve kişinin adı ile yaşı yazıldı. Yaş 450 girilince `ImpossibleInfo` oluştu. `Person` içinde verilen "Impossible age" açıklaması ve yaş değeri ekranda göründü: `Impossible age 450`. Yığın izi sorunun `setAge` metodunda oluştuğunu, onu `TestExceptions` sınıfının `main` metodunun çağırdığını gösterdi. Hoca bunu kullanıcıya "450 olmaz, daha doğru bir değer gir" mesajı diye yorumladı.

`e.toString()` exception'ın adını ve kurucuya verilen açıklamayı yazar. Yığın izi istenmiyorsa yalnız `e.toString()` yazdırılabilir. Ama hoca yığın izinin yazdırılmasının her zaman yararlı olduğunu söyledi: `catch` içinde en azından `printStackTrace` yapılmalı, `Scanner` gibi kritik bir kaynak varsa `finally` unutulmamalıdır.

Ajan bu kodu eksik `Person` sınıfını anlatıma göre tamamlayarak `java TestExceptions.java` ile çalıştırdı. Ad olarak "Ali Ak" ve yaş olarak 30 girilince `Ali Ak 30`, 450 girilince önce `ImpossibleInfo: Impossible age 450`, ardından `at Person.setAge` ve `at TestExceptions.main` satırlarını içeren yığın izi yazıldı.

### 14.6 Özet kurallar

Hoca exception'larla ilgili hatırlanması gerekenleri şöyle sıraladı:

1. Önce exception'ın checked mı unchecked mı olacağına karar verilir.
2. Checked ise `java.io.IOException`'dan, unchecked ise `java.lang.RuntimeException`'dan kalıtımla türetilir.
3. Açıklama metni alan kurucu unutulmaz.
4. Exception oluşturabilecek metot, önündeki ve arkasındaki ilişkili birkaç metotla birlikte bir try-catch bloğuna alınır.
5. Unchecked exception için try-catch zorunlu değildir; checked exception için zorunludur.
6. `catch` içinde en azından `printStackTrace` yapılır.
7. `finally` bloğunun gerekip gerekmediği değerlendirilir; gerekiyorsa konur.

### 14.7 RuntimeException'dan türetince ne değişir

Hoca slayttaki "@home" sorusunu canlı denedi. `ImpossibleInfo`, `RuntimeException`'dan türetilince `IOException` içe aktarımına gerek kalmaz. `setAge` imzasındaki `throws` bildirimi kaldırılabilir ve hiçbir soruna yol açmaz. `TestExceptions` içinde de satırları try-catch içine almak gerekmez; hoca try-catch'i yorum satırı yaptı. Yine de hatalı bir yaş girilince exception oluştu ve Java sanal makinesinin varsayılan davranışıyla yığın izi yazıldı.

Peki checked exception ne kazandırır? Hoca, `Person` sınıfını kullanacak olana "burada böyle bir durum var, buna izin vermiyorum, bunu mutlaka try-catch ile ele almalısın" mesajını dikte etmek olduğunu söyledi. Bunu dikte etmek gerekmiyorsa `RuntimeException`'dan da türetilebilir.

Exception yeniden `IOException`'dan türetilince derleme hataları geri gelir. Önce `setAge` içinde exception'ın ele alınmadığı söylenir; çözüm imzaya yeniden `throws ImpossibleInfo` eklemektir. Bu sefer de `TestExceptions` içinde "handle edilmedi" hatası çıkar. Eclipse'in hızlı düzeltme (quick fix) önerilerinden biri `main` metoduna da `throws` eklemektir.

> **Hocanın vurgusu:** `main` metoduna `throws ImpossibleInfo` yazıp geçmeyin. Exception'ı o zaman kimse ele almaz. Örneğin bir web servisinde bu yapılırsa, exception olduğunda kullanıcının karşısına yalnız hata satırlarını içeren bozuk bir ekran çıkar ve program çöker. Exception'lar mutlaka işlenmelidir.

Diğer quick fix önerisi try-catch eklemektir. Ama Eclipse, hangi metotların iş mantığı açısından birbiriyle ilişkili olduğunu bilemez ve yalnız `setAge` satırını `try` içine alır. Hoca yaşı soran ve okuyan satırların da `try` içinde olmasını istediği için bu işi elle yaptı.

### 14.8 Açıklama kurucusu yazılmazsa

Son olarak hoca `ImpossibleInfo` içindeki açıklama kurucusunu yorum satırı yaptı. Java buna izin verir; derleme hatası olmaz. Yalnız `setAge` içindeki `throw new ImpossibleInfo("...")` satırı artık metin parametreli bir kurucu bulamaz. Bu yüzden o kısım da parametresiz biçime çevrildi ve otomatik oluşan varsayılan kurucu çağrıldı. Program yine çalıştı, ama `e.toString()` artık yalnız exception'ın paket adı ve sınıf adını yazdı; "Impossible age" bilgisi çıkmadı. Kullanıcıya "neden oluşturamıyorum" sorusunun yanıtını vermek için açıklama kurucusuna ihtiyaç vardır.

Hoca `catch` içindeki `System.out.println(e.toString())` satırının aslında gereksiz olduğunu da belirtti, çünkü `printStackTrace` ilk satırda zaten `toString()` çıktısını yazar. En iyisi yalnız `printStackTrace` yazmaktır.

## Örnek Sorular

### Soru 1: Çok kısa adların denetlenmesi (alıştırma)

(ekrandan, 02:50:00; derste sözlü, 02:49:47)

Slaytta "Exercise: Check for too short names" yazar. Hoca, bir kişinin adı çok kısa girildiğinde de `ImpossibleInfo` fırlatılmasını alıştırma olarak verdi. Türkçede en kısa ad-soyad örneği olarak önce "Ali Ak" verildi: Ali üç harf, boşluk bir karakter, Ak iki harf, toplam altı karakter. "AAA" gibi bir girdi exception oluşturmalıdır. Hoca kaynak kodda bulunan çözüm sürümünde daha kısa bir ad örneği (beş karakterli bir ad-soyad) de anıldığını gördü ve sınırın beş karakter olduğunu söyledi. Çözüm `Person2` sınıfındadır; derste açıklanmadı, öğrencilere önce kendilerinin denemesi söylendi.

<!-- BELİRSİZ: hocanın çözüm dosyasındaki tam sınır değeri ekranda görülmedi; anlatımda önce 6, sonra 5 karakter geçiyor. -->

> **Çözüm (derste verilmedi):** Adı denetleyen bir `setName` yazılır ve kurucu onu kullanır. Kurucu da exception fırlatabildiği için `Person2` nesnesi oluşturan satır `try` içine alınır. Aşağıdaki kod `java TestNames.java` ile denendi: "Su Ak" ve yaş 30 girilince `Su Ak 30`, "Ali" girilince `ImpossibleInfo: Too short name: Ali` ve yığın izi yazıldı.

```java
import java.util.*;
import java.io.IOException;

public class TestNames {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        try {
            System.out.print("Enter person's name: ");
            String name = in.nextLine();
            Person2 insan = new Person2(name);
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

@SuppressWarnings("serial")
class ImpossibleInfo extends IOException {
    public ImpossibleInfo(String errorMessage) { super(errorMessage); }
}

class Person2 {
    private String name;
    private int age;
    public Person2(String name) throws ImpossibleInfo { setName(name); }
    public void setName(String name) throws ImpossibleInfo {
        if (name == null || name.trim().length() < 5)
            throw new ImpossibleInfo("Too short name: " + name);
        this.name = name;
    }
    public void setAge(int age) throws ImpossibleInfo {
        if (age < 0 || age > 150)
            throw new ImpossibleInfo("Impossible age " + age);
        this.age = age;
    }
    public String toString() { return name + " " + age; }
}
```

### Soru 2: Exception RuntimeException'dan türetilseydi neler gerekirdi?

(ekrandan, 02:45:00)

`ImpossibleInfo` slaytındaki yorum şunu sorar: "@home: Check the needed additions if we had extended this exception from java.lang.RuntimeException". Bu exception `IOException` yerine `RuntimeException`'dan türetilseydi kodda ne değişirdi?

> **Çözüm (derste canlı gösterildi, 02:58:09-03:00:13):** `RuntimeException` `java.lang` paketinde olduğu için `import java.io.IOException` gerekmez. Exception unchecked olur. `setAge` imzasındaki `throws ImpossibleInfo` bildirimi zorunlu olmaktan çıkar ve silinebilir. `TestExceptions` içinde try-catch yazmak da zorunlu değildir. Exception yakalanmazsa sanal makine yığın izini yazar ve program kesilir. Bir ekleme gerekmez, tersine zorunluluklar kalkar. Kaybedilen şey, sınıfı kullanana "bunu mutlaka ele al" mesajını derleyici aracılığıyla dikte edebilmektir.

### Soru 3: ensureCapacity sonrasında for-each boş alanlara gider mi?

(derste sözlü, 01:10:06)

Bir öğrenci şunu sordu: `ArrayList`'e `ensureCapacity` ile baştan bir kapasite verilirse, for-each ile gezerken boş alanlarda dizideki gibi `NullPointerException` alınır mı?

> **Cevap (derste verildi):** Hayır. `ensureCapacity` yalnız arka plandaki dizide o kadar eleman için yer ayırır, eleman sayısını (`size()`) değiştirmez. Listenin iterator'ı yalnız gerçekten eklenmiş elemanları gezer. Bağlı listede de son elemanın `next` işaretçisi `null` olduğu için gezme ötesine gitmez. Dizide ise for-each, `length` kadar bütün gözleri gezdiği için boş gözlerde `null` ile karşılaşılır.

## Dersin Toparlaması

Ders, dizilerin sınırlarından yola çıkarak Java'nın hazır jenerik veri yapılarını tanıttı. Jenerik tanım (`ArrayList<Student>`) sayesinde tür dönüşümü ortadan kalktı. `Collection` ve `List` arayüzlerinin metotları bütün listelerde ortak olduğu için `ArrayList`, `LinkedList` ve `Vector` iş mantığı değişmeden birbirinin yerine kullanılabildi. Ders ve öğrenci örneğinde liste, dizideki sayaç, kopyalama ve `null` denetimi yükünü kaldırdı. `HashMap` ile anahtar üzerinden doğrudan arama tek satıra indi. Map anahtarının ilkel olamayacağı ve otomatik sarmalamanın bu yükü nasıl hafiflettiği görüldü. Seçimde ekleme/silme ile rastgele erişim arasındaki denge ve thread-safe olma durumu belirleyicidir.

İkinci bölümde aykırı durum işlemeye giriş yapıldı. `Throwable` hiyerarşisi, checked ve unchecked ayrımı, `try-catch-finally` yapısı, `throws` ile sorumluluğu çağırana bırakma ve `throw` ile kendi exception'ını fırlatma, `ImpossibleInfo` ve `Person` örneğiyle uygulandı. Hoca açıklama metni alan kurucunun ve exception'ı gerçekten işlemenin önemini vurguladı. Hoca, jenerik öncesi tür dönüşümü örneğine ileride dönülebileceğini ve aykırı durum işleme konusuna sonraki derste devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
