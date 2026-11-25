# Ders 17 Çalışma Özeti

## Genel Konular

- Enum türleri (primitive enum)
  - Bir değişkenin yalnız sınırlı bir değer kümesini alması gerektiğinde enum kullanılır. Örnekler: haftanın günleri, tişört ya da pizza boyları.
  - Boyları 1, 2, 3, 4 gibi tamsayılarla ya da S, M, L, X gibi karakterlerle kodlamak hataya açıktır; değişkene yanlışlıkla 0 ya da m gibi geçersiz bir değer atanabilir (ekrandan, 00:15:00).
  - Tanım: `public enum Size { SMALL, MEDIUM, LARGE, EXTRA_LARGE; }`. Kullanım: `Size s = Size.MEDIUM;` (ekrandan, 00:15:00).
  - Aslında `Size` adında bir sınıf tanımlanmış ve bu sınıftan yalnız dört statik örnek oluşturulabilmesi zorlanmış olur. `Size.Medium`, `MEDIUM` ya da `M` yazılamaz.
  - Değer atanırken enum türünün adı, nokta ve izin verilen değerlerden biri yazılır.
- Enum sınıfları (enum class)
  - Her sabit tek bir değer değil bir nesneyse enum, alanları, kurucusu ve getter metotları olan bir sınıf gibi yazılır. Her sabit, kurucuya argüman verilerek oluşturulan adlı bir nesnedir.
  - Enum sınıfında kurucu private olmalıdır; alanlar da kurala uygun olarak private tanımlanır.
  - UML gösterimi: sınıf adının üstüne `«enum»` yazılır; alanlar bölümünde önce sabitler, sonra alanlar gösterilir. Örnek `Tariff` enum'u (ekrandan, 00:25:00):
    - Sabitler: `NETFREE(0,4,60), NET4(4,8,30), NET6(6,8,40);`
    - Alanlar: `quota, speed, fee : int`
    - Metotlar: `- Tariff( quota, speed, fee : int )`, `+ getQuota( ) : int`, `+ getSpeed( ) : int`, `+ getFee( ) : int`
    - İlişkiler: `Subscription` 1 — 1 `Tariff` (her aboneliğin bir tarifesi var), `Person` 1 — 1 `Subscription` (her kişinin bir aboneliği var).
  - Kullanım: `Tariff tariff4 = Tariff.NET4;` ile yerel değişkene bir enum nesnesi atanır; `subscribeTo(Tariff.NETFREE)` gibi doğrudan da kullanılabilir (ekrandan, 00:45:00).
- Enum örnekleri (Eclipse)
  - `Craps` (zar oyunu): `private enum Status { CONTINUE, WON, LOST };` gibi bir primitive enum ve `Status gameStatus;` yerel değişkeni. `switch` ile ilk atışın toplamına göre `gameStatus = Status.WON`, `Status.LOST` ya da `Status.CONTINUE` atanır (ekrandan, 00:30:00).
  - `Book` enum sınıfı: altı kitap sabiti, her biri başlık ve telif yılı ile; `private final String title`, `private final String copyrightYear`, iki parametreli kurucu, `getTitle()` ve `getCopyrightYear()` (ekrandan, 00:35:00).
  - `EnumTest`: `Book.values()` ile bütün sabitler for-each döngüsüyle gezilir; `java.util.EnumSet.range(Book.JHTP6, Book.CPPHTP4)` ile yalnız ilk dört sabit gezilir (ekrandan, 00:40:00).
- Generic sınıflar
  - Önce `Object` türünde alan tutan `Box2` sınıfı: aynı nesneye önce `10`, sonra `"some string"` konabilir (ekrandan, 00:50:00).
  - Java bunu sözdizimiyle kolaylaştırır: sınıf bir tür parametresiyle parametrelenir. `public class Box<T> { private T t; public void set(T t) {...} public T get() {...} }` (ekrandan, 00:55:00).
  - Tür parametresi için büyük bir harf seçilir (örnekte `T`).
  - Kullanım: `Box<Integer> b1 = new Box<Integer>();`, `Box<String> b2 = new Box<String>();`, `Box<Object> b3 = new Box<Object>();`. `Box<Object>` içine önce string, sonra tamsayı konabilir (ekrandan, 01:00:00).
  - Birden fazla tür parametresi: `public interface Pair<K, V>` ve `public class OrderedPair<K, V> implements Pair<K, V>`; kullanım `Pair<String, Integer> p1 = new OrderedPair<String, Integer>("Even", 8);` (ekrandan, 01:05:00).
  - Arayüzler de generic tanımlanabilir.
- Veri yapılarına giriş
  - Veri yapısı, verinin bilgisayar belleğinde düzenlenme biçimidir. Verinin düzenlenme biçimi programın performansını etkiler; doğru veri yapısı ve algoritma seçimi saniyelerle günler arasındaki farkı yaratabilir (ekrandan, 01:10:00).
  - Java'daki veri yapıları generic sınıflar üzerine kuruludur.
- Bağlı liste (linked list) ve kendi gerçeklemesi
  - Bağlı liste düğümlerden (list node) oluşur. Her düğüm bir nesnedir ve iki alanı vardır: veri ve sonraki düğüme referans.
  - Liste nesnesi yalnız ilk ve son düğümü (`firstNode`, `lastNode`) bilir; diğer düğümlere ilk düğümden başlayarak sırayla ulaşılır.
  - `ListNode<T>`: `T data;`, `ListNode<T> nextNode;`, bir ve iki parametreli kurucu, `getData()`, `getNext()`. `List<T>`: `firstNode`, `lastNode`, `name` alanları; ekleme, çıkarma, boşluk kontrolü ve yazdırma metotları (ekrandan, 01:25:00).
  - `ListTest`: `insertAtFront(-1)`, `insertAtFront(0)`, `insertAtBack(1)`, `insertAtBack(5)`; her adımdan sonra `print()` (ekrandan, 01:30:00).
  - `insertAtFront`: yeni düğüm oluşturulur, sonraki referansı `firstNode`'un gösterdiği düğüme bağlanır, sonra `firstNode` yeni düğümü gösterir (ekrandan, 01:35:00).
  - `insertAtBack`: yeni düğüm oluşturulur, `lastNode`'un gösterdiği düğümün sonraki referansı yeni düğüme bağlanır, sonra `lastNode` yeni düğümü gösterir.
- Bağlı liste ile dizi karşılaştırması (ekrandan, 01:45:00)
  - Bağlı listenin üstünlükleri: büyütmek maliyetsizdir (yalnız referans güncellenir); herhangi bir konuma ekleme ve çıkarma daha hızlıdır; slayta göre sıralama algoritmaları bağlı listede daha hızlı çalışır.
  - Dizinin üstünlüğü: i. elemana doğrudan erişilir; bağlı listede baştan sırayla gidilir.
  - Tek bağlı liste yalnız bir yönde, çift bağlı liste iki yönde gezilebilir; çift bağlı listede her düğümde veri, sonraki ve önceki referansı vardır.
  - Dairesel listede son düğüm ilk düğümü gösterir.
- Java koleksiyon hiyerarşisi (ekrandan, 01:40:00)
  - `Collection` kök arayüzdür; `List` ve `Set` ondan türer. `ArrayList` ve `LinkedList` `List`'i, `HashSet` ve `TreeSet` `Set`'i gerçekler.
  - `Map` ayrı bir arayüzdür; `HashMap`, `TreeMap`, `WeakHashMap` onu gerçekler. `Collection` bir `Iterator`, `List` bir `ListIterator` üretir.
  - `Vector` de bir listedir ve derste kullanılacaktır. Bu sınıflar `java.util` paketindedir; derste yazılmaz, kullanılır.
- `java.util.LinkedList` kullanımı: `LinkedListTest` (ekrandan, 01:50:00 - 02:25:00)
  - `add` sona ekler; `addAll` bir listenin bütün elemanlarını başka listenin sonuna ekler.
  - `listIterator()` ilk düğümden başlayan bir `ListIterator` verir; `hasNext()`, `next()` ve `set()` ile her eleman büyük harfe çevrilir.
  - `subList(start, end).clear()` aradaki elemanları toplu olarak siler.
  - `listIterator(list.size())` sondan başlayan bir iterator verir; `hasPrevious()` ve `previous()` ile liste tersten yazdırılır.
  - For-each döngüsünde iki noktadan sonra dizi, bağlı liste ya da başka bir koleksiyon gelebilir.
- `Arrays` ve `Collections` yardımcı sınıfları (ekrandan, 02:15:00)
  - İkisi de `java.util` altında, yalnız statik metot içeren sınıflardır. `Arrays` nesne dizileri üzerinde (`sort`, `binarySearch`, `toArray`, `asList`), `Collections` listeler üzerinde (`sort`, `binarySearch`, `shuffle`, `reverse`, `rotate`, `min`, `max`) çalışır.
  - `Collection` (tekil) kök arayüzdür; `Collections` (çoğul) statik metotlu yardımcı sınıftır.
  - `UsingToArray`: `new LinkedList<String>(Arrays.asList(colors))` ile diziden bağlı liste oluşturulur; `addLast`, `add`, `add(3, ...)`, `addFirst` ile eleman eklenir, `toArray` ile tekrar diziye çevrilir (ekrandan, 02:10:00).
  - `Collections.sort` stringleri sözlük sırasına, sayıları değerlerine göre sıralar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Generic tür parametresi tanımda ve oluşturmada aynı olmalı
  - `LinkedList<String> list1 = new LinkedList<String>();` gibi, değişken tanımında hangi tür parametresi yazıldıysa `new` ile oluştururken de aynısı yazılmalıdır. Hoca bunu sınavlarda unutulup puan kaybına yol açan bir hata olarak gösterdi.
- Generic sınıflar sonraki konuların temelidir
  - Bütün veri yapıları generic sınıflar üzerine kurulu olduğu için bu konu anlaşılmadan ilerlenmemelidir.
- `LinkedList` metotlarını iyi öğrenmek
  - `add`, `addAll`, `listIterator`, `subList`, `hasNext`/`hasPrevious` gibi metotlar ileride verilecek problemlerde kullanılacaktır. Ders kodları üzerinde bağlı listeyi, `Arrays` ve `Collections` statik metotlarını kullanarak alıştırma yapılması önerildi.
- Arayüz ile soyut sınıf seçimi
  - Arayüz, yetenekleri gruplamak için kullanılır. Bazı metotları üst sınıfta gerçekleyip alt sınıflardaki tekrarı azaltmak gerekiyorsa soyut sınıf tercih edilir. Java'nın arayüzlere default metot eklemesi bu tasarım yaklaşımını değiştirmez.
- Bir nesneyi birden çok değişken gösterebilir
  - `Tariff.NET4` nesnesi bir yerel değişkene atanabilir ya da doğrudan `Tariff.NET4` diye kullanılabilir; ikisi de aynı nesneyi gösterir. Enum'un sabitleri dışında yeni nesnesi olmaz.

## Kısa Tekrar Notları

- Sınırlı değer kümesi gerekiyorsa enum: `public enum Size { SMALL, MEDIUM, LARGE, EXTRA_LARGE; }`, `Size s = Size.MEDIUM;`.
- Enum sınıfı: sabitler kurucu argümanlarıyla yazılır; alanlar, private kurucu ve getter'lar bulunur.
- UML'de `«enum»` etiketi; sabitler alanlar bölümünde.
- `Enum.values()` bütün sabitleri, `EnumSet.range(a, b)` a ile b arasındaki sabitleri (ikisi dahil) verir.
- Generic sınıf: `class Box<T>`; birden çok parametre: `class OrderedPair<K, V>`.
- `Box<Object>` her türü tutabilir; `Box<Integer>` yalnız `Integer` tutar.
- Bağlı liste: düğüm = veri + sonraki referansı; liste = `firstNode` + `lastNode`.
- `insertAtFront`: yeni düğüm → eski ilk düğüm, `firstNode` → yeni düğüm.
- `insertAtBack`: eski son düğüm → yeni düğüm, `lastNode` → yeni düğüm.
- Bağlı liste: büyütme ve ekleme/çıkarma ucuz; dizi: doğrudan erişim.
- Çift bağlı liste: veri + sonraki + önceki; iki yönde gezilebilir, ek bellek tutar.
- `Collection` → `List` → `ArrayList`, `LinkedList`; `Collection` → `Set` → `HashSet`, `TreeSet`; `Map` → `HashMap`, `TreeMap`.
- `ListIterator`: `hasNext`/`next`/`set`; `listIterator(size)` ile `hasPrevious`/`previous`.
- `subList(start, end).clear()` aralığı siler; `end` dahil değildir.
- `Arrays.asList(dizi)` bir `List` döndürür; `LinkedList` kurucusuna verilerek bağlı liste yapılır.
- `Collections.sort(liste)`: stringlerde sözlük sırası.

## Detaylı Açıklamalar

- Primitive enum ve `Craps` örneği
  - `Craps` sınıfında zar toplamları sabit olarak tanımlanır (ekrandan, 00:30:00):

    ```java
    private final static int SNAKE_EYES = 2;
    private final static int TREY = 3;
    private final static int SEVEN = 7;
    private final static int YO_LEVEN = 11;
    private final static int BOX_CARS = 12;
    ```

  - Oyun durumu `Status` enum türündeki `gameStatus` değişkeninde tutulur. İlk atışta 7 ya da 11 gelirse `Status.WON`, 2, 3 ya da 12 gelirse `Status.LOST`, başka bir değer gelirse `Status.CONTINUE` atanır ve toplam "point" olarak saklanır. Bu atamalar `switch ( sumOfDice )` içindeki `case` ve `default` bölümlerinde yapılır. Değişkene enum'un tanımlı sabitlerinden başka bir şey atanamaz.
  <!-- BELİRSİZ: Status enum tanımının yapıldığı satır karede görünmüyor; altyazıya göre üye alanlar arasında CONTINUE, WON, LOST değerleriyle tanımlı. -->
- `Book` enum sınıfı ve `EnumTest`
  - Her kitap sabitinin iki boyutu (başlık ve yıl) olduğu için enum bir sınıf olarak yazılır (ekrandan, 00:35:00):

    ```java
    public enum Book
    {
       JHTP6( "Java How to Program 6e", "2005" ),
       CHTP4( "C How to Program 4e", "2004" ),
       IW3HTP3( "Internet & World Wide Web How to Program 3e", "2004" ),
       CPPHTP4( "C++ How to Program 4e", "2003" ),
       VBHTP2( "Visual Basic .NET How to Program 2e", "2002" ),
       CSHARPHTP( "C# How to Program", "2002" );

       private final String title; // book title
       private final String copyrightYear; // copyright year

       Book( String bookTitle, String year )
       {
          title = bookTitle;
          copyrightYear = year;
       }
       public String getTitle() { return title; }
       public String getCopyrightYear() { return copyrightYear; }
    }
    ```

  - `EnumTest` önce `for ( Book book : Book.values() )` ile altı kitabın hepsini, sonra `for ( Book book : EnumSet.range( Book.JHTP6, Book.CPPHTP4 ) )` ile ilk dördünü yazdırır (ekrandan, 00:40:00). Bu iki sınıf ajan tarafından `java` ile çalıştırıldı; ikinci döngü `JHTP6`, `CHTP4`, `IW3HTP3`, `CPPHTP4` sabitlerini yazdırdı.
  - Ders sonrası not: hoca enum sınıfında kurucunun private olması gerektiğini söyledi. `Book` örneğinde kurucunun önünde erişim belirleyici yoktur; enum kurucusu belirleyici yazılmasa da örtük olarak private'tır. Kurucuya `public` yazılırsa derleyici hata verir (ajan tarafından `java` ile denendi).
- Generic `Box<T>` sınıfı
  - Kod (ekrandan, 00:55:00):

    ```java
    public class Box<T> {
       // T stands for "Type"
       private T t;

       public void set(T t) { this.t = t; }
       public T get() { return t; }

       public static void main(String []args){
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

  - Sınıfta kurucu yazılmadığı için Java varsayılan kurucuyu sağlar; `new Box<Integer>()` bu yüzden geçerlidir. Ajan tarafından `java` ile çalıştırıldı; çıktı sırasıyla `10`, `some string`, `some other string`, `20` değerlerini gösterdi.
  - Ders sonrası not: hoca bir generic sınıf nesnesinde önce tamsayı, sonra string, sonra double tutulabileceğini söyledi (01:18). Bu yalnız tür parametresi `Object` olan `Box<Object>` gibi nesneler için doğrudur; `Box<Integer>` nesnesine string konursa derleme hatası alınır.
- Kendi bağlı liste gerçeklemesi
  - `ListNode<T>` sınıfı (ekrandan, 01:25:00):

    ```java
    class ListNode< T >
    {
       T data; // data for this node
       ListNode< T > nextNode; // reference to the next node in the list

       ListNode( T object ) { this( object, null ); }
       ListNode( T object, ListNode< T > node )
       {
          data = object;
          nextNode = node;
       }
       T getData() { return data; }
       ListNode< T > getNext() { return nextNode; }
    }
    ```

  - `List<T>` sınıfının alanları `private ListNode< T > firstNode;`, `private ListNode< T > lastNode;` ve `private String name;` alanlarıdır. `ListTest`'te `-1` ve `0` başa, `1` ve `5` sona eklenir; dört eklemeden sonra liste sırası `0 -1 1 5` olur (ekrandan, 01:30:00).
  - `insertAtFront` için slayttaki çizimde liste `7 → 11` iken `12` değerli yeni düğüm oluşturulur. Önce yeni düğümün sonraki referansı 7'li düğüme bağlanır, sonra `firstNode` yeni düğümü gösterir (ekrandan, 01:35:00). `insertAtBack`'te liste `12, 7, 11` iken yeni düğüm eklenir; önce 11'li düğümün sonraki referansı yeni düğüme, sonra `lastNode` yeni düğüme bağlanır.
- `LinkedListTest` (ekrandan, 01:50:00 - 02:25:00)
  - İki dizi (`black, yellow, green, blue, violet, silver` ve `gold, white, brown, blue, gray, silver`) iki `LinkedList<String>`'e `add` ile eklenir, `list1.addAll( list2 );` ile birleştirilir ve `list2 = null;` yapılır. Sonra `convertToUppercaseStrings`, `removeItems( list1, 4, 7 )` ve `printReversedList` çağrılır.

    ```java
    private static void convertToUppercaseStrings( LinkedList< String > list )
    {
       ListIterator< String > iterator = list.listIterator();
       while ( iterator.hasNext() )
       {
          String color = iterator.next(); // get item
          iterator.set( color.toUpperCase() ); // convert to upper case
       }
    }
    private static void removeItems( LinkedList< String > list, int start, int end )
    {
       list.subList( start, end ).clear(); // remove items
    }
    ```

  - Ajan tarafından `java` ile çalıştırıldı: silme sonrası liste `BLACK YELLOW GREEN BLUE WHITE BROWN BLUE GRAY SILVER`, ters liste `SILVER GRAY BLUE BROWN WHITE BLUE GREEN YELLOW BLACK` oldu. `subList(4, 7)` 4, 5 ve 6 indisli elemanları (`VIOLET`, `SILVER`, `GOLD`) siler.
  - Ders sonrası not: hoca `addAll`'un birleştirmeyi yalnız referansları güncelleyerek yaptığını anlattı. `java.util.LinkedList.addAll` eklenen her eleman için yeni düğüm oluşturur; `list2`'nin düğümleri `list1`'e taşınmaz ve `list2` olduğu gibi kalır (ajan tarafından `java` ile denendi). Referansla birleştirme kendi yazılan bir listede yapılabilecek bir yöntemdir.
  - Ders sonrası not: hoca `ArrayList`'in arka planda bağlı liste (tek bağlı liste) kullandığını söyledi. Doğrusu: `ArrayList` arka planda boyutu gerektikçe büyütülen bir dizi kullanır; `LinkedList` ise çift bağlı listedir (hocanın dediği gibi).
  - Ders sonrası not: slayttaki "sıralama algoritmaları bağlı listede daha hızlı çalışır" ifadesi genel olarak doğru değildir. Hızlı sıralama gibi doğrudan erişime dayanan algoritmalar dizide daha hızlıdır; Java'da `Collections.sort` bir listeyi büyük olasılıkla önce diziye kopyalayıp orada sıralar.
- Soru-cevaplar
  - Bağlı listede sıralamanın neden hızlı olduğu soruldu; hoca, sıralamada elemanların yer değiştirmesinin bağlı listede yalnız referans güncellemesiyle yapılabildiğini, dizide ise daha çok değerin kopyalanması gerektiğini söyledi.
  - `hasNext` metodunun bir sonraki elemana geçip geçmediği soruldu; hoca, `hasNext`'in yalnız sırada eleman olup olmadığını (`boolean`) döndürdüğünü, elemanı alıp iteratorü ilerleten metodun `next` olduğunu anlattı.
  - `java.util.LinkedList`'in çift bağlı olup olmadığı soruldu; hoca evet dedi. Çift bağlı listede bir düğüm silinirken önceki düğüm ayrı bir değişkenle takip edilmeden bulunabilir; karşılığı her düğümde ek bir referans için bellek harcanmasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
