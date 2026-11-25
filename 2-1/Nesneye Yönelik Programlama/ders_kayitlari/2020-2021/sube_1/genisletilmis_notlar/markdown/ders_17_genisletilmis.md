# Ders 17 Genişletilmiş Notu: Enum Türleri, Generic Sınıflar, Bağlı Liste ve Java Koleksiyonları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri Türlerinin Tekrarı ve Enum İhtiyacı
- 2. Primitive Enum
- 3. Enum Sınıfları ve UML Gösterimi
- 4. Eclipse'te Enum Örnekleri: Craps, Book ve EnumTest
- 5. Enum Nesnelerine Erişim Üzerine Soru-Cevap
- 6. Generic Sınıflar
- 7. Birden Fazla Tür Parametresi: Pair ve OrderedPair
- 8. Veri Yapılarına Giriş
- 9. Bağlı Liste ve Kendi Gerçeklemesi
- 10. Bağlı Listeye Ekleme: insertAtFront ve insertAtBack
- 11. Java Koleksiyon Hiyerarşisi
- 12. Bağlı Liste ile Dizinin Karşılaştırılması
- 13. java.util.LinkedList Kullanımı: LinkedListTest
- 14. Arrays ve Collections Yardımcı Sınıfları
- 15. Ders Sonu Soru-Cevaplar
- Örnek Sorular

## 1. Veri Türlerinin Tekrarı ve Enum İhtiyacı

Hoca konuya, şimdiye kadar görülen veri türlerini hatırlatarak başladı. Java'da sekiz ilkel (primitive) veri türü vardır: `int`, `double`, `float`, `char` ve diğerleri. Bunların yanında karmaşık (complex) türler öğrenilmişti: her sınıf bir nesnenin türü olabilir. `String` gibi özel karmaşık türler ve her ilkel tür için bir sarmalayıcı (wrapper) sınıf olduğu da görülmüştü; sarmalayıcılar ilkel türlerin karmaşık tür karşılığı olarak kullanılır.

Bu derste yeni bir tür öğrenilir: enum. Enum, bir değişkenin yalnız sınırlı bir değer kümesinden değer alması gerektiğinde kullanılır. Hocanın örnekleri:

- Haftanın günleri: pazartesiden pazara yalnız yedi değer olabilir.
- Tişört boyları: small, medium, large, extra large gibi sınırlı değerler.

Böyle bir durumda enum türü kullanılır. Enum iki biçimde yazılabilir: yalnız değerlerin sıralandığı primitive enum ya da alanları, kurucusu ve metotları olan enum sınıfı.

## 2. Primitive Enum

Slaytta enum'un neden gerektiği bir pizza örneğiyle açıklanır (ekrandan, 00:15:00):

- Bazen bir değişken yalnız sınırlı bir değer kümesini tutmalıdır.
- Örneğin pizza dört boyda satılabilir: small, medium, large, extra large.
- Bu boylar elbette 1, 2, 3, 4 tamsayılarıyla ya da S, M, L, X karakterleriyle kodlanabilir.
- Ama bu hataya açık bir düzendir; değişkenin yanlış bir değer (0 ya da m gibi) tutması çok kolaydır.

Örnek tanım (`Size.java` içinde):

```java
public enum Size {
    SMALL, MEDIUM, LARGE, EXTRA_LARGE;
}
```

Kodda kullanım:

```java
Size s = Size.MEDIUM;
```

Tanımda `enum` anahtar sözcüğü türü belirtir; türün adı (`Size`) büyük harfle başlar. Süslü parantez içinde bu türe atanabilecek bütün değerler yazılır. Böylece bu tür yalnız bu değerleri alabilir.

Kullanımda `Size` artık bir türdür ve `s` gibi bir değişken bu türle tanımlanır. Değer atarken enum türünün adı yazılır, nokta konur ve izin verilen değerlerden biri seçilir.

Slayttaki açıklamaya göre bu tanımla aslında `Size` adında bir sınıf tanımlanmış ve bu sınıftan yalnız dört statik örnek oluşturulabilmesi zorlanmış olur. `Size s = Size.Medium`, `MEDIUM` ya da `M` yazılamaz (ekrandan, 00:15:00).

Hoca, bu tanımın da aslında bir sınıf tanımının en basit hâli olduğunu söyledi: içinde yalnız değerler vardır; kurucu, getter ya da setter yoktur. Yalnız değerleri sıraladığı için hoca buna primitive enum dedi.

## 3. Enum Sınıfları ve UML Gösterimi

Enum'un her değeri tek bir boyut (tek bir ad) değil de birden çok bilgi taşıyan bir nesne olacaksa, enum bir sınıf olarak yazılır; hoca buna enum sınıfı (enum class) dedi. Bu durumda süslü parantez içine yalnız değerler değil, sınıfın geri kalan kodu da yazılır.

- Her değer adı verilmiş bir nesnedir. Nesnelerin adlarının yanında parantez içinde kurucuya gönderilecek değerler yazılır.
- Her nesne için kurucu çağrılacağından, örneğin üç değer veriliyorsa üç parametreli bir kurucu bulunmalıdır.
- Enum sınıfında, şimdiye kadar görülen sınıflardan farklı olarak, kurucu private olmalıdır.
- Üye alanlar, kurala uygun olarak private tanımlanır; kurucu bu alanları başlatır, getter metotları değerlerini döndürür.

> **Ek bilgi (derste anlatılmadı):** Enum kurucusunun önüne erişim belirleyici yazılmasa da kurucu örtük olarak private'tır; `public` ya da `protected` yazılırsa derleyici hata verir (ajan `java` ile denedi). Bu yüzden enum sabitleri dışında `new` ile yeni bir enum nesnesi oluşturulamaz.

<!-- BELİRSİZ: Tariff enum sınıfının kodunu içeren slayt (133) kareye girmedi; kodun ayrıntıları yalnız UML diyagramından ve altyazıdan aktarıldı. -->

### 3.1 UML'de Enum Sınıfı

Slayttaki örnek bir internet tarifesi enum'udur (ekrandan, 00:25:00). UML sınıf diyagramındaki üç bölüm şöyledir:

| Bölüm | İçerik |
|---|---|
| Ad | `«enum»` etiketi ve `Tariff` |
| Alanlar | `NETFREE(0,4,60), NET4(4,8,30), NET6(6,8,40);` ve `quota, speed, fee : int` |
| Metotlar | `- Tariff( quota, speed, fee : int )`, `+ getQuota( ) : int`, `+ getSpeed( ) : int`, `+ getFee( ) : int` |

- Sınıf adının üst bölümüne, enum sınıfı olduğunu ayırt etmek için `«enum»` gösterimi yazılır.
- Diğer sınıflar gibi üye alanlar gösterilir; farkı, enum'un alabileceği sınırlı değerlerin (burada üç nesne) de alanlar bölümüne konmasıdır.
- Kurucunun önündeki `-` işareti onun private olduğunu gösterir.

Diyagramdaki ilişkiler:

- `Subscription` ile `Tariff` arasında association vardır; her aboneliğin bir (`1`) tarifesi vardır.
- `Person` ile `Subscription` arasında association vardır; her kişinin bir aboneliği vardır (iki uçta da `1`).

### 3.2 Enum Nesnesinin Kullanımı

Slayttaki `Test` sınıfı enum nesnesinin oluşturulup kullanılmasını gösterir (ekrandan, 00:45:00). Slayttaki kişi adları burada genel adlarla değiştirildi:

```java
public class Test {
   public static void main(String[] args) {
      Tariff tariff4 = Tariff.NET4;
      Person person1 = new Person("Kişi 1");
      person1.subscribeTo(tariff4);
      Person person2 = new Person("Kişi 2");
      person2.subscribeTo(Tariff.NETFREE);
      System.out.println(person1);
      System.out.println(person2);
   }
}
```

`main` metodunda türü `Tariff` enum sınıfı olan `tariff4` yerel değişkeni tanımlanır. Enum yalnız sınırlı değerler alabildiği için değer, sınıf adı ve nokta yazılarak atanır; burada üç değerden biri olan `NET4` seçilir. Birinci kişi bu değişken üzerinden `NET4`'e, ikinci kişi doğrudan `Tariff.NETFREE` ile başka bir tarifeye abone edilir. Sonra iki kişi ekrana yazdırılır.

## 4. Eclipse'te Enum Örnekleri: Craps, Book ve EnumTest

### 4.1 Craps: Primitive Enum Kullanımı

`Craps` (zar oyunu) sınıfının üye alanları arasında bir primitive enum tanımlanır. Hoca, sınıf tanımının geri kalanı yazılmadığı için bunun primitive enum olduğunu belirtti. Türün adı `Status`, değerleri `CONTINUE`, `WON`, `LOST`'tur.

<!-- BELİRSİZ: Status enum tanımının satırı karede görünmüyor; değerler altyazıdan ve karedeki "can contain CONTINUE, WON or LOST" yorumundan alındı. -->

Karede görünen kod (ekrandan, 00:30:00):

```java
// constants that represent common rolls of the dice
private final static int SNAKE_EYES = 2;
private final static int TREY = 3;
private final static int SEVEN = 7;
private final static int YO_LEVEN = 11;
private final static int BOX_CARS = 12;

// plays one game of craps
public static void main(String[] args)
{
   int myPoint = 0; // point if no win or loss on first roll
   Status gameStatus; // can contain CONTINUE, WON or LOST

   int sumOfDice = rollDice(); // first roll of the dice

   // determine game status and point based on first roll
   switch ( sumOfDice )
   {
      case SEVEN: // win with 7 on first roll
      case YO_LEVEN: // win with 11 on first roll
         gameStatus = Status.WON;
         break;
      case SNAKE_EYES: // lose with 2 on first roll
      case TREY: // lose with 3 on first roll
      case BOX_CARS: // lose with 12 on first roll
         gameStatus = Status.LOST;
         break;
      default: // did not win or lose, so remember point
         gameStatus = Status.CONTINUE; // game is not over
         myPoint = sumOfDice; // remember the point
         System.out.printf( "Point is %d\n", myPoint );
         break; // optional at end of switch
   } // end switch

   // while game is not complete
   while ( gameStatus == Status.CONTINUE ) // not WON or LOST
   {
      sumOfDice = rollDice(); // roll dice again

      // determine game status
      if ( sumOfDice == myPoint ) // win by making point
         gameStatus = Status.WON;
      ...
```

Hoca kodu şöyle anlattı. `gameStatus` türü `Status` enum'u olan bir yerel değişkendir. `rollDice` metodu zarı atıp bir tamsayı döndürür. Sonra bir `switch` gelir: Java'daki akış denetim yapılarından (if-else ve switch-case) biridir. `switch`'e verilen değişkenin değerine göre uygun `case` bölümü çalışır; hiçbiri uymazsa `default` bölümü çalışır. Bu, bir if-else zincirine benzer.

Örneğin ilk atışta 7 ya da 11 gelirse `gameStatus`'a değer atanır. Bu değişkenin türü `Status` olduğu için ona yalnız `CONTINUE`, `WON` ya da `LOST` atanabilir; burada `Status.WON` atanır. 2, 3 ya da 12 gelirse `Status.LOST` atanır. `default` bölümünde de yine enum değerlerinden biri (`Status.CONTINUE`) atanır. Enum türü kodun geri kalanında da (örneğin `while` koşulunda) kullanılır.

### 4.2 Book: Enum Sınıfı

İkinci örnekte enum bir sınıf olarak tanımlanır (ekrandan, 00:35:00):

```java
// Declaring an enum type with constructor and explicit instance fields
// and accessors for these fields

public enum Book
{
   // declare constants of enum type
   JHTP6( "Java How to Program 6e", "2005" ),
   CHTP4( "C How to Program 4e", "2004" ),
   IW3HTP3( "Internet & World Wide Web How to Program 3e", "2004" ),
   CPPHTP4( "C++ How to Program 4e", "2003" ),
   VBHTP2( "Visual Basic .NET How to Program 2e", "2002" ),
   CSHARPHTP( "C# How to Program", "2002" );

   // instance fields
   private final String title; // book title
   private final String copyrightYear; // copyright year

   // enum constructor
   Book( String bookTitle, String year )
   {
      title = bookTitle;
      copyrightYear = year;
   } // end enum Book constructor

   // accessor for field title
   public String getTitle()
   {
      return title;
   } // end method getTitle

   // accessor for field copyrightYear
   public String getCopyrightYear()
   {
      return copyrightYear;
   } // end method getCopyrightYear
} // end enum Book
```

Bu enum'a atanabilecek sabit değerlerin her birinin iki boyutu vardır (başlık ve telif yılı). Hoca, enum'un bu yüzden sınıf olarak tanımlandığını söyledi. Her nesneye bir ad verilir (`JHTP6`, `CHTP4` ...). Sınıfın `title` ve `copyrightYear` üye alanları, bu alanlara değer atayan iki parametreli bir kurucusu ve getter metotları vardır.

### 4.3 EnumTest: values() ve EnumSet.range()

`EnumTest` sınıfı `Book` enum'unu kullanır (ekrandan, 00:40:00):

```java
import java.util.EnumSet;

public class EnumTest
{
   public static void main( String args[] )
   {
      System.out.println( "All books:\n" );

      // print all books in enum Book
      for ( Book book : Book.values() )
         System.out.println( "\n" + book + " " + book.getTitle() + " " + book.getCopyrightYear() );

      System.out.println( "\nDisplay a range of enum constants:\n" );

      // print first four books
      for ( Book book : EnumSet.range( Book.JHTP6, Book.CPPHTP4 ) )
         System.out.println( "\n" + book + " " + book.getTitle() + " " + book.getCopyrightYear() );
   } // end main
} // end class EnumTest
```

<!-- BELİRSİZ: println satırlarının sağ ucu karede kesik; getCopyrightYear() çağrısı ekran çıktısından (başlıktan sonra yıl yazılması) çıkarıldı. -->

Hoca for-each döngüsünü hatırlattı: iki noktadan sonraki kısımda bir veri yapısı olmalıdır. Bu bir dizi, bu derste öğrenilecek veri yapılarından biri ya da enum değerleri olabilir.

- İlk döngüde `Book.values()` enum'un altı nesnesinin hepsini verir. Her biri sırayla türü yine `Book` olan `book` yerel değişkenine atanır ve ayrıntıları yazdırılır.
- İkinci döngüde `java.util` altındaki `EnumSet` sınıfının statik `range` metodu kullanılır. Statik olduğu için nesne oluşturmaya gerek yoktur. `range` iki enum değeri alır ve aradaki bütün değerleri bir küme olarak döndürür. Burada birinci (`JHTP6`) ile dördüncü (`CPPHTP4`) arasındaki değerler alınır.

Program çalıştırıldığında önce altı kitabın hepsi, sonra yalnız ilk dördü yazdırılır (ekrandan, 00:40:00). Ajan tarafından `java` ile çalıştırıldı; ikinci bölümde `JHTP6`, `CHTP4`, `IW3HTP3` ve `CPPHTP4` satırları yazdırıldı, yani `range` iki ucu da kapsar.

## 5. Enum Nesnelerine Erişim Üzerine Soru-Cevap

**Soru:** `Test` örneğinde `tariff4` diye bir değişken oluşturulmuş. `Tariff.NET4` ile başka bir değişken daha oluşturursak ikisi aynı yeri mi gösterir, yoksa ayrı nesneler mi oluşur? Aşağıda da doğrudan `Tariff.NETFREE` yazılmış, nesne oluşturulmadan.

**Cevap:** Enum kullanılırken bu türe atanabilecek değerler baştan belirlenir. Tek boyutlu değerler (tişört boyu, haftanın günü) yalnız adlarıyla yazılır. Enum'a nesne atanacaksa nesneler de adlarıyla belirtilir. Normalde nesne `new` ile oluşturulur; burada ise sözdizimi nesnelere ad verir ve kurucu değerleri parantez içinde verilir. Bu nesneler kod çalıştırıldığında bellekte oluşturulur. `Tariff tariff4 = Tariff.NET4;` satırında `tariff4` yerel değişkenine bellekteki `NET4` nesnesinin adresi atanır; değişken bu nesneyi gösterir. Aynı nesneye `Tariff.NET4` yazılarak doğrudan da ulaşılabilir; ikisi de aynı nesneyi gösterir. `Tariff.NETFREE` de doğrudan o nesneye ulaşır. `Tariff`'in her zaman yalnız bu üç nesnesi vardır; dördüncüsü, beşincisi olmaz.

**Soru:** Aynı nesneyi başka bir yerel değişkenle de gösterebilir miyiz, yoksa hata mı verir?

**Cevap:** Gösterebilirsin. İstenildiği kadar yerel değişken aynı nesneyi gösterebilir; yeter ki her birine o nesnenin referansı atansın.

> **Ek bilgi (derste anlatılmadı):** Enum sabitleri tekil olduğu için `Tariff.NET4 == tariff4` karşılaştırması `true` verir (ajan `java` ile denedi). Bu yüzden enum değerleri `==` ile güvenle karşılaştırılabilir; `Craps` örneğindeki `gameStatus == Status.CONTINUE` koşulu da bunu kullanır.

## 6. Generic Sınıflar

Hoca, generic sınıfların Java'daki veri yapılarında kullanıldığını ve bu yüzden çok önemli bir konu olduğunu söyledi.

### 6.1 Object Türünde Alan Tutan Sınıf: Box2

Önce şimdiye kadar görülen yöntemle yazılmış bir sınıf gösterildi (ekrandan, 00:50:00):

```java
public class Box2{

   private Object obj;

   public void setObj(Object object){
      this.obj=object;
   }

   public Object getObj(){
      return obj;
   }

   public static void main(String []args){

         Box2 b = new Box2();
         b.setObj(10);
         System.out.println("generic objects value = " + b.getObj());

         b.setObj("some string");
         System.out.println("generic objects value = " + b.getObj());
   }
}
```

Üye alanın türü `Object`'tir. Hoca, `java.lang.Object`'in Java geliştirme kitiyle gelen ve sınıf hiyerarşisinin kökünde bulunan sınıf olduğunu, oluşturulan her nesnenin aslında `Object` sınıfının da bir nesnesi olduğunu hatırlattı. `main` metodunda `b` nesnesine önce bir tamsayı konup yazdırılır, sonra bir string konup yazdırılır.

Alan için `int`, `String`, `double` gibi bilinen bir tür ya da sarmalayıcı seçilmemiştir; `Object` seçilmiştir, çünkü nesnenin içine farklı türde şeyler konmak istenir. Sınıf yazılırken nesnenin ne tutacağı bilinmiyorsa tür `Object` yapılır ve önce tamsayı, sonra string koymak gibi işler yapılabilir.

### 6.2 Tür Parametresiyle Generic Sınıf: Box<T>

Java ve diğer üst düzey nesneye yönelik diller bu kullanımı sözdizimiyle kolaylaştırır. Metotların parametreleri olduğu gibi sınıf da parametrelenir. Sınıf adının sonuna köşeli parantez içinde bir tür parametresi yazılır; bu, sınıfın generic bir tür parametresi alacağını gösterir. Tür parametresi için büyük harflerden biri seçilir; bu örnekte `T` seçilmiştir, ama herhangi bir harf olabilir (ekrandan, 00:55:00):

```java
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

Üye alan `T` türündendir. Setter `T` türünde girdi alır, getter `T` türünde değer döndürür.

`main` metodundaki üç kullanım:

- `b1`: sınıfa tür parametresi olarak `Integer` sınıfı verilir; bu kutu tamsayı tutacaktır. Değişken bu şekilde tanımlandığı için nesne oluşturulurken de aynı parametre yazılmalıdır: `new Box<Integer>()`. Sınıfta kurucu yazılmadığından Java sanal makinesi varsayılan kurucuyu sağlar; bu yüzden böyle yazmak geçerlidir. Sonra `set` ile tamsayı konur, `get` ile alınıp konsola yazılır.
- `b2`: bu kez kutuda string tutulmak istenir, tür parametresi olarak `String` yazılır, nesne aynı parametreyle oluşturulur ve bir string konup okunur.
- `b3`: belirli bir sarmalayıcı yerin her şeyin konabilmesi istenir; tür parametresi `java.lang.Object`'tir. Önce bir string, sonra bir tamsayı konabilir.

Ajan tarafından `java` ile çalıştırıldı; dört satırda sırasıyla `10`, `some string`, `some other string` ve `20` yazdırıldı.

Hoca Türkçe olarak özetledi: şimdiye kadarki sınıflarda üye alanların hangi türden olacağı baştan söyleniyordu. Ama nesnenin içine ne konacağına sonradan karar verilecekse, string de integer da konabilecekse, üye alanların türü generic tür ile belirtilir. Generic sınıflar, bir sınıfın içinde farklı türde veriler tutulmak istendiğinde kullanılır.

> **Ders sonrası not:** Hoca aradan sonra, bir generic sınıf nesnesinde önce tamsayı, sonra string, sonra double tutulabileceğini söyledi. Bu yalnız tür parametresi `Object` olan nesneler (`Box<Object>`) için doğrudur. Tür parametresi `Integer` olan `b1`'e string konursa derleme hatası alınır; generic sınıfın kazancı, hangi türün tutulacağının nesne oluşturulurken bir kez seçilmesi ve derleyicinin bunu denetlemesidir.

## 7. Birden Fazla Tür Parametresi: Pair ve OrderedPair

Bir sınıf parametrelenebiliyorsa birden fazla parametresi de olabilir. Slayttaki `OrderedPair` sınıfı iki farklı değer tutar ve ikisi de generic türdedir, çünkü nesnenin ne tutacağı baştan bilinmez; belki string, belki integer konacaktır (ekrandan, 01:05:00):

```java
public interface Pair<K, V> {
    public K getKey();
    public V getValue();
}

public class OrderedPair<K, V> implements Pair<K, V> {

    private K key;
    private V value;

    public OrderedPair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey()   { return key; }
    public V getValue() { return value; }
}
```

Slayttaki açıklama: aşağıdaki deyimler `OrderedPair` sınıfının iki örneğini oluşturur:

```java
Pair<String, Integer> p1 = new OrderedPair<String, Integer>("Even", 8);
Pair<String, String>  p2 = new OrderedPair<String, String>("hello", "world");
```

Hoca şunları vurguladı:

- Üye alan sayısı kadar generic tür parametresi tanımlanmıştır; burada iki alan ve iki parametre vardır. İki alanı başlatan iki parametreli bir kurucu ve getter'lar bulunur.
- Bu sınıf bir arayüzü gerçekler. Hoca, arayüzün de bir sınıf gibi düşünülebileceğini, bu yüzden arayüzlerin de generic tanımlanabileceğini söyledi. Arayüzde yalnız metot tanımları (gövdesiz) vardır; onu gerçekleyen her sınıf bu iki metodu yazmak zorundadır.
- `p1` tanımında iki parametre geçilir: `String` ve `Integer`. Bu sınıftan oluşan nesne string ve tamsayı değerler tutacaktır. Nesne oluşturulurken aynı gösterim korunmalı ve iki parametreli kurucu iki argümanla çağrılmalıdır.
- `p2`'de iki parametre de `String`'tir; nesnenin iki alanı da string tutar.

Ajan tarafından `java` ile çalıştırıldı; `p1` için `Even 8`, `p2` için `hello world` değerleri okundu.

> **Ek bilgi (derste anlatılmadı):** Java'da arayüz teknik olarak bir sınıf değil, ayrı bir tür bildirimidir (`interface`); ama sınıflar gibi bir tür adı tanımladığı ve generic parametre alabildiği için hocanın benzetmesi kullanım açısından yerindedir.

## 8. Veri Yapılarına Giriş

Aradan sonra hoca, generic sınıflarla ilgili soru olup olmadığını sordu ve anlaşılmayan yerde durdurulmasını istedi.

> **Hocanın vurgusu:** Bundan sonra konuşulacak bütün veri yapıları generic sınıflar üzerine kurulmuştur; bu konu anlaşılmadan ilerlenmemelidir.

Şimdiye kadar veri yapısı olarak diziler öğrenilmişti. Dizi, verileri fiziksel bellekte düzenli biçimde tutmanın bir yoludur. Bağlı liste (linked list), `ArrayList`, `HashMap` gibi başka veri yapıları da vardır ve bu derste öğrenilecektir. Program yazarken veriyi bellekte tutmak için farklı veri yapıları seçilir; seçime göre program daha hızlı ya da daha yavaş çalışabilir.

Slayttaki tanımlar (ekrandan, 01:10:00):

- Veri yapısı, verinin bilgisayar belleğinde düzenlenmesi için bir şemadır.
- Genel anlamda her veri gösterimi bir veri yapısıdır; örneğin bir tamsayı.
- Daha tipik olarak veri yapısı, bir veri öğeleri topluluğu için bir düzenlemedir.
- Verinin düzenlenme biçimi programın farklı işlerdeki performansını etkiler.
- Veri yapısı ve algoritma seçimi, bir programın birkaç saniyede ya da günlerce çalışması arasındaki farkı yaratabilir.
- Sık kullanılan veri yapıları: diziler, listeler, yığınlar (stack), kuyruklar (queue), yığın ağaçları (heap), ağaçlar ve graflar.

## 9. Bağlı Liste ve Kendi Gerçeklemesi

### 9.1 Yapı

Bağlı liste, liste düğümlerinden (list node) oluşur. Her düğüm bir nesnedir ve iki üye alanı vardır:

- verinin kendisi,
- başka bir liste düğümüne referans.

Slayttaki örnekte beş düğüm nesnesi ve bir bağlı liste nesnesi vardır. Bağlı liste nesnesinin iki alanı vardır: ilk düğümü gösteren baş (head, first) referansı ve son düğümü gösteren kuyruk (tail, last) referansı.

<!-- BELİRSİZ: Beş düğümlü bağlı liste çiziminin olduğu slayt kareye girmedi; düğümlerdeki değerler bilinmiyor. -->

Hoca Türkçe olarak şöyle özetledi: bağlı liste nesnesi bütün düğümleri bilmek zorunda değildir; birinciyi ve sonuncuyu bilmesi yeterlidir. Birinci düğüm hem tutması gereken veriyi tutar, hem de bellekteki bir sonraki düğüme referans verir. İkinci düğüm de aynı şekilde. Listede hangi değerlerin tutulduğu, baş düğümden başlayıp düğümler üzerinde sırayla ilerleyerek bulunur.

### 9.2 ListNode ve List Sınıfları

Java'nın kendi `LinkedList` gerçeklemesi vardır ve derste o kullanılacaktır. Ama bağlı listenin nasıl gerçeklendiğini anlamak için iki sınıflık bir örnek gösterildi; bu örnekte bütün listenin sınıfının adı `List`'tir (ekrandan, 01:25:00):

```java
// class to represent one node in a list
class ListNode< T >
{
   // package access members; List can access these directly
   T data; // data for this node
   ListNode< T > nextNode; // reference to the next node in the list

   // constructor creates a ListNode that refers to object
   ListNode( T object )
   {
      this( object, null );
   } // end ListNode one-argument constructor

   // constructor creates ListNode that refers to the specified
   // object and to the next ListNode
   ListNode( T object, ListNode< T > node )
   {
      data = object;
      nextNode = node;
   } // end ListNode two-argument constructor

   // return reference to data in node
   T getData()
   {
      return data; // return item in this node
   } // end method getData

   // return reference to next node in list
   ListNode< T > getNext()
   {
      return nextNode; // get next node
   } // end method getNext
} // end class ListNode< T >

// class List definition
public class List< T >
{
   private ListNode< T > firstNode;
   private ListNode< T > lastNode;
   private String name; // string like "list" used in printing
   ...
```

`ListNode`'un iki alanı vardır. Birincisi verinin kendisidir; generic sınıflarda farklı türde şeyler tutulmak istendiği için türü `T`'dir. İkincisi başka bir düğüme referanstır; türü sınıfın kendi türüyle (`ListNode<T>`) aynıdır, çünkü başka bir düğüm nesnesini göstermek için kullanılır. Bir ve iki parametreli kurucular ile veri ve sonraki düğüm için getter'lar vardır.

`List` sınıfının üç alanı vardır: listeye verilen bir ad ve asıl önemli olan iki referans, yani ilk düğümü gösteren `firstNode` ve son düğümü gösteren `lastNode`. Varsayılan kurucu ve listeye ad veren bir parametreli kurucu vardır. Başa ve sona düğüm ekleyen, baştan ve sondan düğüm çıkaran, listenin boş olup olmadığını denetleyen ve içeriğini yazdıran metotlar bulunur. Java'nın `LinkedList` gerçeklemesi de aynı mantıktadır.

### 9.3 ListTest

`ListTest` sınıfı bu listeyi dener (ekrandan, 01:30:00):

```java
List< Integer > list = new List< Integer >(); // create a List

// insert integers in list
list.insertAtFront( -1 );
list.print();
list.insertAtFront( 0 );
list.print();
list.insertAtBack( 1 );
list.print();
list.insertAtBack( 5 );
list.print();
```

Listede tamsayı tutulacağı bilindiği için generic sınıfa `Integer` geçilir. Önce `insertAtFront(-1)` ile `-1` eklenip liste konsola yazdırılır. Sonra `0` yine başa eklenir; liste `0 -1` olur. Sonra `1` sona eklenir (`0 -1 1`), sonra `5` sona eklenir (`0 -1 1 5`). Hoca anlatırken bir an "sıfır ve bir" dedi, hemen ardından ikinci değerin `-1` olması gerektiğini söyledi. Karede görünen kodda çıkarma işlemlerini (`removeFromFront`, `removeFromBack`) ve `EmptyListException` yakalamayı içeren bölüm yorum satırı yapılmıştır.

## 10. Bağlı Listeye Ekleme: insertAtFront ve insertAtBack

### 10.1 insertAtFront

Slayttaki çizim (ekrandan, 01:35:00):

```text
(a) firstNode -> [7 | o]--> [11 | /]
    new ListNode -> [12 | /]

(b) firstNode - - - - - - - -> [12 | o]
                                    |
                                    +- - -> [7 | o]--> [11 | /]
```

Başlangıçta listede iki düğüm (`7` ve `11`) vardır ve listenin `firstNode` alanı ilk düğümü gösterir. Başa `12` değeri eklenmek istenir:

- Önce `new` ile yeni bir düğüm nesnesi oluşturulur. Bu nesnenin bir alanı verinin kendisi, öbürü sonraki düğüme referanstır.
- Yeni düğümün referans alanı, listenin ilk düğümünü gösterecek biçimde güncellenir. İlk düğümün adresi listenin `firstNode` alanından alınır. Artık yeni düğüm eski ilk düğümü görür.
- İş bitmedi: sonra listenin `firstNode` değişkenine yeni düğümün adresi atanır. Bu adres, yeni düğüm oluşturulurken onu takip etmek için kullanılan referanstan alınır.

### 10.2 insertAtBack

Listede `12`, `7`, `11` olmak üzere üç düğüm vardır; `firstNode` ilk düğümü, `lastNode` son düğümü gösterir. Sona yeni bir düğüm eklemek için:

- `new` ile yeni düğüm oluşturulur.
- Son düğümün yeri `lastNode` referansıyla bilinir; o düğüme gidilir ve onun referans alanına yeni düğümün referansı atanır. Böylece eski son düğüm yeni düğümü gösterir.
- İş bitmedi: sonra `lastNode` yeni düğümü gösterecek biçimde güncellenir; yeni düğümün referansı `lastNode`'a atanır.

<!-- BELİRSİZ: insertAtBack çiziminin olduğu slayt kareye girmedi; sona eklenen değer bilinmiyor. -->

Bağlı listenin başka metotları da vardır: baştan ve sondan çıkarma (`removeFromFront`, `removeFromBack`), yazdırma ve diğerleri. Hoca bunların kodun içinde incelenebileceğini söyledi.

## 11. Java Koleksiyon Hiyerarşisi

Bağlı liste, `java.util` paketinin sağladığı veri yapılarından biridir. Derste veri yapısı sınıfları yazılmayacak, `java.util` altındaki hazır sınıflar kullanılacaktır. Bu sınıflar `Collection` adlı bir arayüzden türer.

Slayttaki "Collection Interfaces and Classes" diyagramı (ekrandan, 01:40:00):

| Üst tür (arayüz) | Alt türler |
|---|---|
| `Collection` | `List`, `Set` |
| `List` | `ArrayList`, `LinkedList` |
| `Set` | `HashSet`, `TreeSet` |
| `Map` | `HashMap`, `TreeMap`, `WeakHashMap` |
| `Iterator` | `ListIterator` |

Diyagramda ayrıca şu ilişkiler vardır:

- `Collection` bir `Iterator` üretir (produces); `List` bir `ListIterator` üretir; `Map` bir `Collection` üretir.
- `Comparable` ile `Comparator` arasında çift yönlü bir ok vardır.
- "Utilities" kutusunda `Collections` ve `Arrays` yardımcı sınıfları bulunur.

Hoca, derste `LinkedList` ve `ArrayList`'in, `Map` arayüzünden de `HashMap`'in öğrenileceğini söyledi. Diyagramda yer almayan `Vector` sınıfı da bir listedir ve o da öğrenilecektir. `Collections` ve `Arrays` sınıflarının veri yapıları üzerinde işlem yapmaya yarayan statik metotları vardır.

## 12. Bağlı Liste ile Dizinin Karşılaştırılması

Slayttaki karşılaştırma (ekrandan, 01:45:00):

- Bağlı listenin dizilere göre üstünlükleri:
  - Bir listeyi büyütmenin maliyeti yoktur.
  - Herhangi bir konuma eleman ekleme ve çıkarma daha hızlıdır.
  - Sıralama algoritmaları bağlı listelerde daha hızlı çalışır.
- Dizinin bağlı listeye göre üstünlüğü:
  - Listeler sırayla gezilir; dizinin ise herhangi bir i. elemanına doğrudan erişilebilir.
- Bağlı liste türleri:
  - Tek bağlı liste (single-linked list): yalnız bir yönde gezilir.
  - Çift bağlı liste (doubly-linked list): ileri ve geri iki yönde gezilebilir.
- Bir liste dairesel de olabilir: son düğümdeki işaretçi ilk düğümü gösterir (slayttaki benzetmeyle tespih taneleri gibi).

Hoca bunları şöyle açıkladı. Bağlı liste büyütülürken yalnız referanslar güncellenir; yeni bir nesne eklemek için yapılan tek şey budur. Dizide ise kapasiteyi artırmak için daha büyük yeni bir dizi oluşturulur ve bütün nesneler eski diziden yenisine taşınır. Bağlı listeden bir eleman çıkarmak için de yalnız referans güncellenir: bir düğümü listeden çıkarmak için önceki düğümün referansı, çıkarılan düğümden sonraki düğümü gösterecek biçimde güncellenir.

Dizinin üstünlüğü doğrudan erişimdir: örneğin dizinin beşinci elemanına doğrudan ulaşılır. Bağlı listede üçüncü elemana ulaşmak için birinciden başlanır, ikinciye, sonra üçüncüye gidilir.

Çift bağlı listede her düğümde üç üye alan vardır: veri, sonraki düğüme referans ve önceki düğüme referans.

> **Ders sonrası not:** Slayttaki "sıralama algoritmaları bağlı listelerde daha hızlı çalışır" ifadesi genel olarak doğru değildir. Birleştirme sıralaması (merge sort) bağlı listeye iyi uyar; ama hızlı sıralama (quicksort) gibi doğrudan erişime dayanan algoritmalar dizide daha hızlıdır. Java'da `Collections.sort` bir listeyi büyük olasılıkla önce diziye kopyalayıp orada sıralar.

## 13. java.util.LinkedList Kullanımı: LinkedListTest

### 13.1 İki Listeyi Doldurmak ve Birleştirmek

Önceki kod Java'nın bağlı listesinin nasıl gerçeklendiğini gösteriyordu; bu örnek `LinkedList` sınıfının nasıl kullanıldığını gösterir. `java.util`'den `List`, `LinkedList` ve `ListIterator` içe aktarılır. Hoca, her `LinkedList`'in aynı zamanda bir `List` olduğunu belirtti (ekrandan, 01:50:00):

```java
import java.util.List;
import java.util.LinkedList;
import java.util.ListIterator;

public class LinkedListTest
{
   public static void main( String[] args )
   {
      // add colors elements to list1
      String[] colors =
         { "black", "yellow", "green", "blue", "violet", "silver" };

      LinkedList< String > list1 = new LinkedList< String >();

      for ( String color : colors )
         list1.add( color ); // add to the end

      // add colors2 elements to list2
      String[] colors2 =
         { "gold", "white", "brown", "blue", "gray", "silver" };
      LinkedList< String > list2 = new LinkedList< String >();

      for ( String color : colors2 )
         list2.add( color ); // add to the end

      list1.addAll( list2 ); // concatenate lists
      list2 = null; // release resources
      printList( list1 ); // print list1 elements

      convertToUppercaseStrings( list1 ); // convert to uppercase string
      printList( list1 ); // print list1 elements

      System.out.print( "\nDeleting elements 4 to 6..." );
      removeItems( list1, 4, 7 ); // remove items 4-6 from list
      printList( list1 ); // print list1 elements
      printReversedList( list1 ); // print list in reverse order
   } // end main
```

Akış şöyledir:

- Önce altı elemanlı bir `String` dizisi oluşturulur.
- Sonra bir bağlı liste tanımlanır; içinde string tutulacağı bilindiği için tür parametresi `String`'tir. Nesne oluşturulurken aynı gösterim kullanılır ve kuruculardan biri (burada varsayılan kurucu) çağrılır.
- Dizi üzerinde for-each döngüsü kurulur ve her eleman `add` ile listeye eklenir. `add` değeri listenin sonuna ekler. Bağlı listenin başa ekleme, sona ekleme, baştan çıkarma, sondan çıkarma gibi başka metotları da vardır.
- İkinci dizi ve ikinci liste (`list2`) için aynısı yapılır. Elemanlar sona eklendiğinden liste önce `gold`, sonra `gold white`, sonra `gold white brown` diye büyür.
- `addAll` iki listeyi birleştirir: `list2`'nin bütün değerleri `list1`'in sonuna eklenir.
- `list2` referansına `null` atanır. Hoca, `list2` nesnesinin hâlâ bellekte olduğunu ama bu noktadan sonra kodda ona ulaşılamayacağını, Java sanal makinesi silene kadar bellekte kalacağını söyledi.

> **Hocanın vurgusu:** Generic bir sınıfın değişkeni hangi tür parametresiyle tanımlandıysa, `new` ile nesnesi oluşturulurken de aynı parametre yazılmalıdır. Hoca, geçmiş yılların sınavlarında bunun yapılmadığını ve puan kırılmasına yol açtığını söyledi.

> **Hocanın vurgusu:** `addAll` ve bağlı listenin diğer metotları iyi öğrenilmeli ve bunlarla örnekler yapılmalıdır.

Hoca, `addAll`'un birleştirmeyi yalnız referansları güncelleyerek yaptığını anlattı: `list1`'in son düğümünün sonraki referansı `list2`'nin ilk düğümünü gösterecek, `list1`'in `lastNode` referansı da `list2`'nin son düğümünü gösterecek biçimde güncellenir.

> **Ders sonrası not:** Hocanın anlattığı referans güncellemeli birleştirme, kendi yazılan bir bağlı listede yapılabilecek bir yöntemdir. `java.util.LinkedList.addAll` ise eklenen her eleman için yeni düğüm oluşturur; `list2`'nin düğümleri `list1`'e taşınmaz ve `list2` olduğu gibi kalır. Ajan `java` ile denedi: `addAll`'dan ve `list1` üzerindeki bütün değişikliklerden sonra `list2`'nin eski bir referansı hâlâ `[gold, white, brown, blue, gray, silver]` içeriğini gösteriyordu.

### 13.2 printList ve For-Each

Kod (ekrandan, 01:55:00):

```java
// output List contents
private static void printList( LinkedList< String > list )
{
   System.out.println( "\nlist: " );

   for ( String color : list )
      System.out.printf( "%s ", color );

   System.out.println();
} // end method printList
```

`printList`'e `list1`'i gösteren referans gönderilir. For-each döngüsü listenin bütün elemanlarını tek tek alıp bir string değişkene atar ve yazdırır. Hoca for-each'i hatırlattı: iki noktadan sonra bir veri yapısı gelir; bu bir dizi, bir bağlı liste ya da başka bir koleksiyon olabilir. Her iterasyonda veri yapısındaki bir nesne soldaki değişkene atanır.

### 13.3 convertToUppercaseStrings ve ListIterator

Kod (ekrandan, 01:55:00):

```java
// locate String objects and convert to uppercase
private static void convertToUppercaseStrings( LinkedList< String > list )
{
   ListIterator< String > iterator = list.listIterator();

   while ( iterator.hasNext() )
   {
      String color = iterator.next(); // get item
      iterator.set( color.toUpperCase() ); // convert to upper case
   } // end while
} // end method convertToUppercaseStrings
```

Metot, birleştirilmiş listeye (iki dizinin bütün değerleri) referans alır. Bağlı liste üzerinde ilk elemandan son elemana adım adım ilerlemek için `java.util`'in sağladığı `ListIterator` sınıfı kullanılır. Dizilerde for döngüsüyle yapılan gezinti, bağlı listede bir `while` döngüsü ve iterator nesnesiyle yapılır.

- `list.listIterator()` çağrıldığında bir `ListIterator` nesnesi döner. Bu nesne bir işaretçi (referans) gibidir ve `firstNode` gibi listenin ilk düğümünü gösterir.
- Her turda `hasNext()` ile gösterilen yerde bir düğüm olup olmadığı sorulur.
- Varsa `next()` ile o düğümün değeri alınıp geçici bir değişkene atanır, büyük harfe çevrilir ve `set()` ile aynı düğüme geri yazılır.
- Döngü başına dönüldüğünde iterator artık bir sonraki düğümü gösterir; sonraki düğüm yoksa döngüden çıkılır.

Sonuçta listedeki bütün stringler büyük harfli olur ve liste yeniden yazdırılır.

### 13.4 removeItems ve subList

Kod (ekrandan, 01:55:00):

```java
// obtain sublist and use clear method to delete sublist items
private static void removeItems( LinkedList< String > list,
   int start, int end )
{
   list.subList( start, end ).clear(); // remove items
} // end method removeItems
```

Listenin belirli konumlarındaki düğümleri toplu olarak çıkarmak için bağlı listenin `subList` metodu kullanılır. `subList` iki tamsayı alır: başlangıç ve bitiş. Listenin ilk elemanı 0 indislidir. `subList` küçük bir alt liste nesnesi döndürür; bu nesnenin `clear` metodu çağrıldığında o aralıktaki değerler ana listeden çıkarılır.

`main`'deki çağrı `removeItems( list1, 4, 7 )`'dir; yorumda "remove items 4-6" yazar. Bitiş indisi dahil değildir, yani 4, 5 ve 6 indisli elemanlar silinir.

### 13.5 printReversedList ve hasPrevious

Kod (ekrandan, 01:55:00):

```java
// print reversed list
private static void printReversedList( LinkedList< String > list )
{
   ListIterator< String > iterator = list.listIterator( list.size() );

   System.out.println( "\nReversed List:" );

   // print list in reverse order
   while ( iterator.hasPrevious() )
      System.out.printf( "%s ", iterator.previous() );
   ...
```

<!-- BELİRSİZ: printReversedList metodunun son satırları karede kesik; kapanış satırları ders kodundan görülemedi. -->

`list.size()` listedeki eleman sayısını verir. `listIterator( list.size() )` ile listenin en sonunu gösteren bir iterator istenir; bu iterator artık ilk düğümü değil son düğümü gösterir. Bu kez `hasNext` yerine `hasPrevious` kullanılır; `true` ya da `false` döndürür. Gösterilen yerde bir eleman varsa döngüye girilir, `previous()` ile değeri alınıp yazdırılır ve iterator bir öncekine döner. Böylece iterator ile bir liste `hasNext` kullanılarak baştan, `hasPrevious` kullanılarak sondan yazdırılabilir.

### 13.6 Programın Çıktısı

Ajan programı `java` ile çalıştırdı (ara adım eklendi):

| Adım | Liste |
|---|---|
| `addAll` sonrası | `black yellow green blue violet silver gold white brown blue gray silver` |
| büyük harf sonrası | `BLACK YELLOW GREEN BLUE VIOLET SILVER GOLD WHITE BROWN BLUE GRAY SILVER` |
| `removeItems(list1, 4, 7)` sonrası | `BLACK YELLOW GREEN BLUE WHITE BROWN BLUE GRAY SILVER` |
| ters sırada | `SILVER GRAY BLUE BROWN WHITE BLUE GREEN YELLOW BLACK` |

Silinen elemanlar 4, 5 ve 6 indisli `VIOLET`, `SILVER` ve `GOLD`'dur.

Hoca bu bölümü şöyle toparladı: `java.util` altında sağlanan `LinkedList` veri yapısından şu ana kadar `add`, `addAll`, liste üzerinde baştan ilerlemek için `listIterator` ve `subList` metotları ile iterator'ın `hasNext` ve `hasPrevious` metotları öğrenildi. Hem bağlı listenin arka plandaki gerçeklemesi (`ListNode` ve `List`), hem de Java'nın kütüphane olarak sağladığı `LinkedList` sınıfının metotları görüldü.

## 14. Arrays ve Collections Yardımcı Sınıfları

### 14.1 Genel Bakış

`Arrays` ve `Collections`, `java.util` altında bulunan ve yalnız statik metot içeren yardımcı (utility) sınıflardır. Bu metotlar veri yapıları üzerinde sıralama, ikili arama, karıştırma, ters çevirme gibi işlemler yapar. `Arrays` bu işleri dizi veri yapısı üzerinde, `Collections` ise `Collection` hiyerarşisinden türeyen her sınıf üzerinde yapar.

Slayttaki diyagram (ekrandan, 02:15:00):

- `Collection`: koleksiyon hiyerarşisindeki kök arayüz.
- `Collections`: yalnız koleksiyonlar üzerinde işlem yapan ya da koleksiyon döndüren statik metotlardan oluşan sınıf.
- `Arrays` ve `Collections` ikisi de `Object`'ten türer.

| `java.util.Arrays` (nesne dizileri üzerinde) | `java.util.Collections` (listeler üzerinde) |
|---|---|
| `sort()` | `sort()`: merge sort, $n \log n$ |
| `binarySearch()` | `binarySearch()`: sıralı dizi gerektirir |
| `toArray(List list)` | `shuffle()`: sırayı bozar |
| `asList(Array array)` | `reverse()`: sıralı dizi gerektirir |
| | `rotate()`: verilen bir uzaklık kadar döndürür |
| | `min()`, `max()`: bir koleksiyonda en küçük ve en büyük |

<!-- BELİRSİZ: Slaytta reverse() için "requires ordered sequence" yazıyor; reverse sıralı girdi gerektirmez, büyük olasılıkla slayttaki bir kayma. -->

### 14.2 UsingToArray: Diziden Bağlı Listeye

Kod (ekrandan, 02:10:00):

```java
import java.util.LinkedList;
import java.util.Arrays;

public class UsingToArray
{
   // creates a LinkedList, adds elements and converts to array
   public static void main( String[] args )
   {
      String[] colors = { "black", "blue", "yellow" };


      LinkedList< String > links =
         new LinkedList< String >( Arrays.asList( colors ) );

      links.addLast( "red" ); // add as last item
      links.add( "pink" ); // add to the end
      links.add( 3, "green" ); // add at 3rd index
      links.addFirst( "cyan" ); // add as first item

      // get LinkedList elements as an array
      colors = links.toArray( new String[ links.size() ] );

      System.out.println( "colors: " );

      for ( String color : colors )
         System.out.println( color );
   } // end main
} // end class UsingToArray
```

Önce üç değerli bir string dizisi oluşturulur; bu satırdan sonra bellekte içinde üç string nesnesi olan bir dizi vardır. Bu dizi bağlı listeye çevrilmek istenir. Java'nın `LinkedList` sınıfının kurucularından biri `List` türünde bir girdi alır ve onu bağlı listeye çevirir. `Arrays` sınıfının `asList` metodu bir diziyi girdi olarak alıp `List` türünde bir nesne döndürür. Hoca, `List`'in `LinkedList`'in gerçeklediği arayüz, yani kalıtım ağacında bir üst tür olduğunu hatırlattı. Bu nesne `LinkedList` kurucusuna verildiğinde bir bağlı liste oluşur; sonra standart metotlarla bu üç elemanlı listeye yeni elemanlar eklenebilir.

Ajan tarafından `java` ile çalıştırıldı (ara adım eklendi):

| İşlem | Liste |
|---|---|
| `new LinkedList<String>(Arrays.asList(colors))` | `black, blue, yellow` |
| `addLast("red")` | `black, blue, yellow, red` |
| `add("pink")` | `black, blue, yellow, red, pink` |
| `add(3, "green")` | `black, blue, yellow, green, red, pink` |
| `addFirst("cyan")` | `cyan, black, blue, yellow, green, red, pink` |

`toArray` ile liste yeniden diziye çevrilir ve yedi renk alt alta yazdırılır.

### 14.3 Collections ile Sıralama

Hoca, `ArrayList` bir sonraki derste anlatılacağı için `Collections` örneğini bağlı listeyle gösterdi. Altı elemanlı bir string dizisi `Arrays.asList` ile `List`'e çevrilir, bu da `LinkedList` kurucusuna verilerek bir bağlı liste nesnesi oluşturulur ve bir yerel değişkenle takip edilir. Bu veri yapısı üzerinde işlem yapmak için `Collections` sınıfı kullanılır. Onun statik metotlarından biri `sort`'tur: içine bağlı liste gibi bir veri yapısı aldığında elemanlarını sıralar. Elemanlar string ise sözlük (lexicographical) sırasına, tamsayı ise tamsayı değerlerine, double ise double değerlerine göre sıralar.

<!-- BELİRSİZ: Collections örneğinin kodu kareye girmedi; dizinin elemanları ve çıktı bilinmiyor. -->

Hoca, `Arrays`'in statik metotlarının nesne içeren diziler üzerinde, `Collections`'ın statik metotlarının ise koleksiyon veri yapıları üzerinde çalıştığını tekrarladı. Bir sonraki derste `ArrayList` anlatılacaktır.

> **Ders sonrası not:** Hoca `ArrayList`'i, bağlı listenin dizi biçiminde gerçeklenmiş hâli olarak tanıttı ve arka planda bağlı liste kullandığını söyledi; ders sonundaki bir soruda da `ArrayList`'in tek bağlı liste kullandığını söyledi. Doğrusu: `ArrayList` arka planda doldukça daha büyüğüyle değiştirilen bir dizi kullanır, düğüm ya da bağlantı kullanmaz. Bu yüzden indisle doğrudan erişim sağlar. `LinkedList` ise hocanın dediği gibi çift bağlı listedir.

## 15. Ders Sonu Soru-Cevaplar

**Soru:** Bağlı listede sıralama algoritmalarının daha hızlı olduğunu söylediniz; bunun sebebi tam olarak nedir?

**Cevap:** Örneğin hızlı sıralamada (quicksort) veri yapısındaki değerlerin yerleri sürekli değiştirilir; sürekli bir kopyalama ve yer değiştirme işlemi vardır. Bu iş yalnız referanslar değiştirilerek yapılırsa daha hızlı olur: nesnelerin kendisi değil referansları güncellenir. Dizilerde takip edilmesi ve güncellenmesi gereken değer sayısı bağlı listelere göre daha fazladır.

(Bu cevabın sınırı için 12. bölümdeki ders sonrası nota bakın.)

**Soru:** Geçen derste, gövdeli metot kullanılacaksa arayüz yerine soyut sınıf tercih edilmesini söylemiştiniz. Arayüzlerde de gövdeli default metot olduğunu gördük. Bu durumda soyut sınıfın arayüze karşı bir üstünlüğü kalıyor mu?

**Cevap:** Arayüzü tercih etmenin sebebi geleneksel olarak (by convention) şudur: arayüz, yetenekleri gruplamak için kullanılan bir yapıdır. Soyut sınıf kullanıldığında yeteneklerin bir kısmı genelleştirilir (üst sınıfta yazılır), bir kısmı için de alt sınıflara "bunları yazmak zorundasınız" denir. Zamanla Java ve diğer diller arayüze yeni yetenekler eklemiş olabilir, ama arayüzü kullanma yaklaşımı her zaman yetenekleri gruplamaktır. Metotların bir kısmını üst sınıfta gerçekleyip alt sınıflarda tekrarı azaltmak isteniyorsa soyut sınıf kullanılır; yalnız yetenekleri gruplamak gerekiyorsa ve üst sınıfta metot gerçekleme ihtiyacı yoksa arayüz tercih edilir.

Bu sırada ekranda önceki derslerden araç vergisi örneği açıktı; ayrıntısı Örnek Sorular bölümündedir.

**Soru:** `hasPrevious` ile geriye de gidebiliyoruz; Java'daki bağlı liste çift yönlü mü?

**Cevap:** Çift bağlı listede her düğümde veri alanının yanında iki referans vardır: biri sonrakini, biri öncekini gösterir. Üstünlüğü şudur: tek bağlı listede bir düğüm silinirken, silinen düğümden önceki düğümün referansı silinen düğümden sonraki düğüme atanmalıdır; bunun için önceki düğüm `remove` metodunda ayrı bir değişkenle takip edilir. Çift bağlı listede ise istenen anda önceki düğüme geri dönülüp onun "sonraki" referansı güncellenebilir. Liste hem ileri hem geri gezilebilir; bedeli, her düğüm için bellekte ek bir referans yeri tutulmasıdır. Java'nın `LinkedList` sınıfının çift bağlı liste kullanması gerekir; liste oluşturulurken ayrıca çift bağlı liste seçilmez.

**Soru:** `while` içinde kullandığımız `hasNext` bir sonraki eleman var mı diye mi bakıyor, yoksa bir sonraki elemana mı geçiyor?

**Cevap:** Hoca koda dönerek anlattı. Önce liste üzerinde gezinecek iterator nesnesi alınır; bu nesne de `firstNode` ve `lastNode` gibi düğümleri gösteren bir nesnedir ve başta ilk düğümü gösterir. `hasNext` yalnız o anda gösterilen yerde bir düğüm olup olmadığını `boolean` olarak döndürür, ilerlemez. `true` dönerse `next` çağrılır; `next` gösterilen düğümün değerini alır ve iterator'ı bir sonraki düğümü gösterecek biçimde günceller. Döngü başına dönüldüğünde iterator artık ikinci düğümü gösterir ve yine `hasNext` ile ilerde düğüm olup olmadığına bakılır; yoksa döngüden çıkılır.

> **Hocanın vurgusu:** İleriki derslerde bağlı liste ve `ArrayList` örneklerine bakılacak; bir problem verilip bir veri yapısıyla çözülmesi istenecek. Bunun içinde ekleme ve çıkarma metotları olacağı için bağlı listenin metotları bilinmelidir. Ders kodları üzerinde özellikle bağlı listenin kullanımını, `Arrays` ve `Collections` sınıflarıyla bağlı liste üzerinde statik metotlar çalıştırmayı ve liste üzerinde gezinmeyi çalışmak önerildi.

## Örnek Sorular

**1. (derste sözlü, 00:42:10)** `Tariff tariff4 = Tariff.NET4;` yazıldıktan sonra `Tariff.NET4` başka bir değişkene de atanırsa iki değişken aynı nesneyi mi gösterir, yoksa yeni bir nesne mi oluşur?

> **Cevap (derste verildi):** Aynı nesneyi gösterir. Enum sabitleri kod çalıştırıldığında bir kez oluşturulur; `Tariff`'in yalnız `NETFREE`, `NET4` ve `NET6` nesneleri vardır. İstenildiği kadar yerel değişken aynı nesneyi gösterebilir; `Tariff.NET4` doğrudan da kullanılabilir. Ajan `java` ile denedi: `Tariff.NET4` iki ayrı değişkene atandığında `==` karşılaştırması `true` verdi.

**2. (ekrandan, 00:40:00)** `EnumTest` programında `EnumSet.range( Book.JHTP6, Book.CPPHTP4 )` ile kurulan döngü hangi kitapları yazdırır?

> **Cevap (derste verildi):** Birinci ile dördüncü sabit arasındaki (ikisi dahil) dört kitabı yazdırır: `JHTP6 Java How to Program 6e 2005`, `CHTP4 C How to Program 4e 2004`, `IW3HTP3 Internet & World Wide Web How to Program 3e 2004`, `CPPHTP4 C++ How to Program 4e 2003`. Ekrandaki konsol çıktısında da bu dört satır görünür; ajan `java` ile çalıştırarak doğruladı.

**3. (ekrandan, 01:30:00)** `ListTest`'te `insertAtFront(-1)`, `insertAtFront(0)`, `insertAtBack(1)`, `insertAtBack(5)` çağrılarından sonra liste ne olur?

> **Cevap (derste kısmen verildi):** Hoca ilk iki adımdan sonra listenin `0 -1` olduğunu, sonra `1`'in sona eklendiğini anlattı. Adım adım: `-1` → `0 -1` → `0 -1 1` → `0 -1 1 5`.

**4. (derste sözlü, 02:17:08)** Sıralama algoritmaları bağlı listede neden daha hızlı olsun?

> **Cevap (derste verildi):** Hoca, sıralamada sürekli yapılan yer değiştirmelerin bağlı listede yalnız referans güncellemesiyle yapılabildiğini, dizide ise daha çok değerin kopyalanıp güncellenmesi gerektiğini söyledi.
>
> **Ders sonrası not:** Bu genel bir kural değildir. Doğrudan erişime dayanan algoritmalar (hızlı sıralama, ikili arama) dizide daha hızlıdır; bağlı listeye iyi uyan algoritma birleştirme sıralamasıdır. Java'da `Collections.sort` büyük olasılıkla listeyi önce diziye kopyalar.

**5. (derste sözlü, 02:18:40)** Arayüzlerde gövdeli default metot yazılabiliyorsa soyut sınıfın arayüze karşı bir üstünlüğü kalır mı?

> **Cevap (derste verildi):** Arayüz yetenekleri gruplamak için kullanılır. Bazı metotları üst sınıfta gerçekleyip alt sınıflardaki tekrarı azaltmak gerekiyorsa soyut sınıf seçilir; yalnız yetenek gruplamak gerekiyorsa arayüz seçilir.
>
> **Ek bilgi (derste anlatılmadı):** Soyut sınıfın arayüzden farklı olarak örnek alanları (durum) ve kurucuları olabilir; arayüzde yalnız sabitler tanımlanabilir. Buna karşılık bir sınıf yalnız bir sınıftan türeyebilir ama birden çok arayüzü gerçekleyebilir.

**6. (derste sözlü, 02:23:45)** `hasNext` bir sonraki elemana geçer mi, yoksa yalnız bir sonraki eleman var mı diye mi bakar?

> **Cevap (derste verildi):** Yalnız bakar ve `boolean` döndürür. Değeri alıp iterator'ı ilerleten `next` metodudur.

**7. (ekrandan, 02:20:00)** Araçların vergisinin hesaplanmasıyla ilgili şu gereksinim nasıl modellenir? Ticari ve kişisel araçların vergilendirmesi farklıdır. Motosikletler, arabalar ve otobüsler ticari araç olarak kaydedilebilir. Yalnız motosiklet ve arabalar kişisel araç olarak kaydedilebilir. Yalnız ticari araçların vergisi amortize edilebilir. Ticari olsun olmasın, farklı araçların (araba, otobüs vb.) vergi hesabı çok farklıdır.

> **Cevap (ekranda verildi):** Slayttaki model iki arayüz kullanır:
>
> - `«interface» CommercialVehicle`: `+ getPlate( ) : String`, `+ calculateAmortizedTax( baseTax : double, currentYear : int ) : double`
> - `«interface» PersonalVehicle`: `+ getPlate( ) : String`, `+ calculateTax( baseTax : double ) : double`
> - `Motorcycle`, `Car` ve `Bus` `CommercialVehicle`'ı gerçekler; `Motorcycle` ve `Car` ayrıca `PersonalVehicle`'ı gerçekler.
>
> Slayttaki ipucu: farklı araçların vergi hesabı benzer (parametrelenmiş) olsaydı, arayüzler yerine tek bir soyut taban sınıf kullanmak daha iyi bir seçim olurdu.

## Dersin Toparlaması

Ders, sınırlı bir değer kümesi alması gereken değişkenler için enum türüyle başladı. Yalnız değerleri sıralayan primitive enum (`Size`, `Craps` örneğindeki `Status`) ile alanları, private kurucusu ve getter'ları olan enum sınıfı (`Tariff`, `Book`) ayrıldı; enum sınıfının UML'de `«enum»` etiketiyle nasıl çizildiği, `values()` ve `EnumSet.range()` ile enum sabitleri üzerinde nasıl gezinildiği gösterildi. Ardından generic sınıflara geçildi: `Object` türünde alan tutan bir sınıftan tür parametreli `Box<T>`'ye, oradan iki parametreli `Pair<K, V>` arayüzüne ve `OrderedPair<K, V>` sınıfına gidildi. Tür parametresinin değişken tanımında ve `new` ile oluştururken aynı yazılması gerektiği vurgulandı.

Dersin ikinci yarısı veri yapılarına ayrıldı. Bağlı listenin düğüm yapısı, `ListNode` ve `List` sınıflarıyla kendi gerçeklemesi, `insertAtFront` ve `insertAtBack` işlemleri, dizi ile karşılaştırması ve tek, çift ve dairesel bağlı liste türleri işlendi. Java koleksiyon hiyerarşisi tanıtıldı ve `java.util.LinkedList`'in `add`, `addAll`, `listIterator`, `subList` metotları ile `ListIterator`'ın `hasNext`, `next`, `set`, `hasPrevious` ve `previous` metotları bir örnek üzerinde gösterildi. Son olarak `Arrays` ve `Collections` yardımcı sınıflarının statik metotları (`asList`, `toArray`, `sort` vb.) anlatıldı. Bir sonraki derste `ArrayList` işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
