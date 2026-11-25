# Ders 6 Çalışma Özeti

## Genel Konular

- İlkel (primitive) veri tipleri ve sarmalayıcıları (wrappers)
  - İlkel tip tek birim bilgi tutar ve sınıf değildir. Sarmalayıcı, tek bir ilkel üye alanı ve bu alanla ilgili yararlı metotları olan bir sınıftır (ekrandan, 00:10:00).
  - Java'da sekiz ilkel tip vardır. Slayttaki tam sayı tablosu (ekrandan, 00:10:00):
    - `int`: 4 bayt, $-2.147.483.648$ ile $+2.147.483.647$ arası, sarmalayıcısı `Integer`.
    - `long`: 8 bayt, yaklaşık $\pm 9{,}22 \times 10^{18}$, sarmalayıcısı `Long`; örnek `long natID = 12345678900L;`.
    - `short`: 2 bayt, $-32.768$ ile $+32.767$ arası, sarmalayıcısı `Short`.
    - `byte`: 1 bayt, $-128$ ile $+127$ arası, sarmalayıcısı `Byte`.
  - Gerçel sayılar ve diğer ilkel tipler (ekrandan, 00:20:00):
    - `double`: 8 bayt, yaklaşık $\pm 1{,}79 \times 10^{308}$, `Double`; `float`: 4 bayt, yaklaşık $\pm 3{,}4 \times 10^{38}$, `Float`.
    - `char`: 2 bayt, UTF-16 kodlamasıyla karakter, `Character`; `boolean`: mantıksal değer (`false`/`true`), `Boolean`.
  - Bayt sayısı aralığı belirler: 1 bayt 8 bittir, `int` $4 \times 8 = 32$ bit, `long` 64 bit, `short` 16 bittir.
  - İlkel olmayan tipler de vardır: sınıf da bir tiptir, nesne kendi sınıfının tipindedir. En sık kullanılan ilkel olmayan tip `String`'dir.
- İlkel tiplerle işlemler (ekrandan, 00:25:00)
  - Aritmetik işleçler: `+ - * / %`. Matematikteki işlem önceliği geçerlidir: `*`, `/`, `%` toplama ve çıkarmadan önce yapılır.
  - Kısaltmalar: `++`, `--` ve `+=`, `-=`, `*=`, `/=`, `%=`. Örneğin `a += number` ifadesi `a = a + number` demektir; `i++` ve `++i` ikisi de `i = i + 1` yapar.
  - `i++` ile `++i` farkı: işleç sağdaysa önce değer o satırda kullanılır, sonra artırılır; soldaysa önce artırılır, sonra kullanılır.
  - Bitsel (binary) işleçler: `&` (and), `|` (or), `~` (not), `^` (xor); kaydırma: `<<`, `>>`.
  - `round`, `abs`, `sqrt`, `pow` gibi ek işlemler dilin işleçleri değil, `java.lang.Math` sınıfının static metotlarıdır.
- Sarmalayıcı sınıflar ve `Integer`
  - Sarmalayıcı, sardığı ilkel değeri veri bölümünde tutan ve yararlı metotlar sunan bir nesnedir. Sarmalayıcılar `java.lang` paketindedir (ekrandan, 00:40:00).
  - `Integer` metotlarından örnekler: `int compareTo(Integer anotherInteger)`, `int intValue()`, `static int parseInt(String s)`, `String toString()`, `static String toString(int i)`, `static Integer valueOf(String s)`.
  - Sarmalayıcılar yararlı metotları için ve ilkel tipin kullanılamadığı yerlerde (ileride görülecek serileştirme ve map indeksleri gibi) kullanılır.
  - Sekiz ilkel tipin her birinin sarmalayıcısı vardır: `Boolean`, `Character`, `Float`, `Double`, `Byte`, `Short`, `Long`, `Integer`.
- Kutulama (boxing) ve kutudan çıkarma (unboxing)
  - Sarmalayıcı tipte bir değişkene ilkel değer atanınca (`Integer sarma1 = 1;`) JVM bunu kendisi bir `Integer` nesnesine çevirir. Buna kutulama denir.
  - Sarmalayıcı nesne ilkel bir değişkene atanınca JVM nesnenin `intValue()` metodunu çağırıp ilkel değeri alır. Buna kutudan çıkarma denir.
- `String` sınıfı
  - `String` bir ilkel tipin sarmalayıcısı değildir, ama çok kullanılan bir sınıf tipidir. Uzunluk bulma, karşılaştırma, büyük ya da küçük harfe çevirme, başka bir dizgiyi içerip içermediğini sınama gibi metotları vardır.
  - `compareTo` sözlük sırasına göre karşılaştırır: ikinci dizgi sırada sonra geliyorsa negatif bir sayı, önce geliyorsa pozitif bir sayı, eşitse 0 döner.
  - `contains`, `toUpperCase`, `toLowerCase` örneklerle gösterildi.
- `Math` sınıfı (`java.lang`)
  - Bütün metotları static'tir; nesne oluşturmadan `Math.metot(...)` diye çağrılır.
  - `Math.random()`: 0,0'a eşit ya da büyük, 1,0'dan küçük pozitif bir `double` döndürür (ekrandan, 00:55:00).
  - `abs`, `max`, `min` her ilkel tip için sürümlere sahiptir; örneğin `public static double Math.max(double a, double b)` (ekrandan, 01:15:00).
  - `ceil` yukarı, `floor` aşağı yuvarlar; `round` doğru yuvarlar (3,5 → 4); `sqrt` pozitif karekökü verir.
- `Random` sınıfı (`java.util`)
  - Bilgisayarlar sözde rastgele (pseudo-random) sayı üreteçleri kullanır; bu `java.util.Random` sınıfıyla modellenir. `Math.random()` doğrudan kullanılınca JRE bir `Random` nesnesi oluşturur ve JVM'nin ömrü boyunca onu kullanır (ekrandan, 01:20:00).
  - `Random`'ın metotları static değildir; önce `new Random()` ile nesne oluşturulur.
  - Metotlar: `nextBoolean()`, `nextDouble()`, `nextFloat()`, `nextInt()`, `nextInt(int bound)` (`[0, bound)`), `nextLong()`.
- `Scanner` sınıfı ile konsol girişi (`java.util`)
  - Konsola yazmak için `System.out` nesnesinin `print`, `println`, `printf` metotları kullanılır.
  - Girdi için `Scanner in = new Scanner(System.in);` yazılır. `System.in`, `java.io.InputStream` tipinde public static bir üyedir. JDK 5.0'dan beri vardır (ekrandan, 01:30:00).
  - Girdi metotları: `String nextLine()`, `int nextInt()`, `float nextFloat()` vb. Her çağrı bir öğe okur ve kullanıcı girene kadar bekler.
  - İş bitince `close()` çağrılır.
- `Car` sınıfında plakanın kullanıcıdan alınması (ekrandan, 01:50:00)
  - Tek private alan (`plate`), getter/setter, tek parametreli kurucu ve `introduceSelf()` metodu olan sınıfın `main` metodu, plakayı `Scanner` ile okuyup kurucuya verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Static ve static olmayan metot çağrısı
  - Static metot sınıf adıyla doğrudan çağrılır (`Math.random()`). Static olmayan metodu çağırmak için önce `new` ile nesne oluşturulur, sonra nesne referansı üzerinden çağrılır (`generator.nextInt()`). Hoca bunun unutulmaması gerektiğini Türkçe de tekrarladı.
- `i++` ile `++i` farkı
  - Hoca `int i = 3; int a = i++; int b = ++a;` örneğini adım adım izledi: `a = 3, i = 4`, sonra `b = 4, a = 4`.
- `nextInt()` sonrasında `nextLine()` tuzağı
  - Önce `String`, sonra ilkel değer okunursa sorun yoktur. Önce ilkel değer (`nextInt()`) okunursa, ardından gelen `nextLine()` dizgiyi almadan geçer. Çözüm: araya atama yapılmayan fazladan bir `nextLine()` koymak.
- `Scanner` kapatılmalı
  - Dış dünyadan veri alan ya da veren bir kanal (input/output stream) açıldığında mutlaka `close()` ile kapatılmalıdır. Kapatılmazsa bu iş JVM'ye bırakılır ve dışarıdan veri bekleyen bir nesne boşuna tutulur.
- IDE ile pratik yapmak
  - Eclipse, NetBeans ya da IntelliJ kurulmalı, derste gösterilen kodlar indirilip çalıştırılmalı ve değiştirilmeli. Sınavda verilen problem, açıklama ya da sınıf diyagramından kod yazılması beklenir; metot bildirimi, erişim belirleyicileri ve `main` yazımı gibi ayrıntıların alışkanlık hâline gelmiş olması gerekir.

## Kısa Tekrar Notları

- 8 ilkel tip: `int`, `long`, `short`, `byte`, `double`, `float`, `char`, `boolean`; her birinin sarmalayıcı sınıfı vardır.
- `int` 4 bayt ($-2^{31}$ … $2^{31}-1$), `long` 8 bayt, `short` 2 bayt, `byte` 1 bayt.
- `a += n` ≡ `a = a + n`; `x++` önce kullan sonra artır, `++x` önce artır sonra kullan.
- `12 | 25 = 29`, `12 & 25 = 8`.
- Kutulama: `Integer x = 4;` (ilkel → nesne); kutudan çıkarma: `int y = x;` (nesne → ilkel, `intValue()`).
- `Integer.compareTo`: küçükse −1, eşitse 0, büyükse +1. `String.compareTo`: sözlük sırasına göre negatif, 0 ya da pozitif.
- `String` değişmezdir: `strB.toUpperCase();` tek başına `strB`'yi değiştirmez, sonuç atanmalıdır (`strB = strB.toUpperCase();`).
- `Math` metotları static (`Math.random()`, `abs`, `max`, `min`, `ceil`, `floor`, `round`, `sqrt`); `Random` metotları static değil (`new Random()`).
- `nextInt(11)` 0 ile 10 arasında (0 dahil, 11 hariç) bir tam sayı verir.
- `Scanner in = new Scanner(System.in);` … `in.close();`. `nextInt()` sonrası dizgi okunacaksa araya bir `nextLine()` konur.

## Detaylı Açıklamalar

- İlkel tipler ve bellek
  - Bir ilkel değişken için bellekte tipinin boyu kadar yer ayrılır (örneğin `int` için 4 bayt). Hoca tahtada bunu, aynı değeri tutan bir `Integer` nesnesiyle karşılaştırdı: nesne bellekte veri bölümünde değeri, ayrıca `compareTo`, `toString`, `valueOf` gibi metotları taşır. İlkel değerle yalnız aritmetik ve bitsel işlemler yapılabilirken sarmalayıcı nesneyle bu hazır metotlar da kullanılabilir. <!-- BELİRSİZ: Hocanın kamera/tahta çizimi karelerde görünmüyor (kayıtta o sırada slayt ekranı var); anlatım yalnız altyazıdan. -->
  - Bir öğrenci bu boyutların işlemciye göre değişip değişmediğini sordu. Hoca, Java'nın kendi sanal ortamında çalıştığını ve bu tiplerin evrensel olduğunu söyledi.
  - **Ders sonrası not:** Hoca boyutların C, C++, C# ve Python'da da aynı olduğunu söyledi; doğrusu, Java'da boyutlar dil belirtimiyle sabittir ve işlemciye göre değişmez, ama C ve C++'ta `int`, `long` gibi tiplerin boyu derleyiciye ve platforma bağlıdır. Ayrıca hoca `int` aralığını "$2^{32}$" diye andı; 32 bitlik işaretli tam sayının aralığı slayttaki gibi $-2^{31}$ ile $2^{31}-1$ arasıdır ($-2.147.483.648$ … $2.147.483.647$). `short` için de aralık $-2^{15}$ ile $2^{15}-1$ arasıdır.
- Artırma işleçleri örneği (ekrandan, 00:25:00)

  ```java
  int i = 3;
  int a = i++; // a = 3, i = 4
  int b = ++a; // b = 4, a = 4
  ```

  - İkinci satırda `++` sağda olduğu için önce atama (`a = 3`), sonra artırma (`i = 4`) yapılır. Üçüncü satırda `++` solda olduğu için önce `a` 4 olur, sonra `b`'ye atanır. Kod `java` ile çalıştırıldı: sonuç `i=4, a=4, b=4`.
  - Slaytta ayrıca `y * ++z` ile `y * z++` ifadelerinin farklı sonuç verdiği ve bir sayının sağdan 4. bitinin `(n&8)/8` ya da `(n&(1<<3))>>3` ile bulunabileceği yazıyordu; bunlar derste ayrıca açıklanmadı.
- Bitsel işlem örnekleri
  - OR: $12 = 00001100_2$, $25 = 00011001_2$. Bitler sağdan sola tek tek OR'lanır ve $00011101_2 = 29$ bulunur. <!-- BELİRSİZ: OR slaytının karesi yok; ikilik gösterim AND slaytından, sonuç (29) altyazıdan ve python/java ile doğrulandı. -->
  - AND örneği (ekrandan, 00:35:00):

  ```java
  class BitwiseAND {
       public static void main(String[] args) {
          int number1 = 12, number2 = 25, result;
          result = number1 & number2;
          System.out.println(result);
       }
  }
  ```

  - $00001100 \,\&\, 00011001 = 00001000 = 8$. Tek satırda virgülle birden fazla değişken bildirilebilir; `result` yalnız bildirilmiş, değer atanmamıştır.
- `Integer` ile karşılaştırma (ekrandan, 00:40:00)

  ```java
  Integer sarma1 = 1, sarma2 = 7;
  //could use sarma1 = new Integer( 1 ); but that constructor is deprecated,
  //i.e it will be removed from the language in a future version
  System.out.println("Sonuç1:"+sarma1.compareTo(sarma2)); //-1
  ```

  - `sarma1`'e 1 atanırken kutulama yapılır. `sarma2` (7) `sarma1`'den (1) büyük olduğu için sonuç −1'dir; çalıştırıldığında `Sonuç1:-1` yazdı.
- `String` örneği (ekrandan, 00:55:00)

  ```java
  package nyp01c;
  public class StringOps02 {
     public static void main( String args[] ) {
        String strA = "İstanbul", strB = "Yıldız";
        System.out.println(strA.contains(strB));
        strB = "tan";
        System.out.println(strA.contains(strB));
        strB.toUpperCase();
        System.out.println(strB);
        System.out.println(strA.contains(strB));
        strB = strB.toUpperCase();
        System.out.println(strB);
        System.out.println(strA.contains(strB));
     }
  }
  ```

  - Çıktı (`java` ile çalıştırıldı): `false`, `true`, `tan`, `true`, `TAN`, `false`.
  - Hoca slaytı ilk anlatırken `toUpperCase()` çağrısından sonra `contains` sonucunun `false` olacağını söyledi. Eclipse'te çalıştırırken bir öğrenci, atama yapılmayan satırda `strB`'nin küçük harfli kaldığını sordu; hoca haklı olduğunu kabul etti: `toUpperCase()` yeni bir dizgi döndürür, atanmazsa `strB` değişmez. Ancak `strB = strB.toUpperCase();` satırından sonra `"TAN"` artık `"İstanbul"` içinde bulunmaz.
- `Math` ve `Random`
  - `Math.random()` örneği: `double value = Math.random();` ve `System.out.println("The generated random value is: " + value);` (ekrandan, 00:55:00).
  - `ceil(3.1)` → 4,0; `floor(3.1)` → 3,0; `round(3.5)` → 4; `round(3.1)` → 3.
  - **Ders sonrası not:** Hoca `round(3.1)` için "3.0" dedi; `Math.round(double)` bir `long` döndürür, sonuç `3`'tür. `ceil` ve `floor` ise `double` döndürür (`4.0`, `3.0`).
  - `RandomOps` örneği (ekrandan, 01:40:00):

  ```java
  package nyp01c;

  import java.util.*;

  public class RandomOps {
  	public static void main(String[] args) {
  		Random generator = new Random();
  		int intVal = generator.nextInt();
  		System.out.println("I have got " + Math.abs(intVal) + " pebbles.");
  		int bounded = generator.nextInt(11);
  		System.out.println("I have painted my " + bounded + " fingers.");
  	}
  }
  ```

  - `import java.util.*;` `java.util` paketindeki bütün sınıfları (`Random` dahil) içe aktarır. `nextInt()` herhangi bir `int`, `Math.abs` onun mutlak değerini, `nextInt(11)` ise 0 ile 10 arasında bir sayı verir. Derste çalıştırılınca sınırlı değer 3 çıktı.
  - **Ders sonrası not:** Hoca ve slayt `nextInt()` aralığını $(-2^{32}, 2^{32})$ diye verdi; doğrusu bütün `int` değerleri, yani $-2^{31}$ ile $2^{31}-1$ arasıdır. Slayttaki `nextLong()` için verilen $[0, 2^{48})$ aralığı da büyük olasılıkla yanlıştır: `nextLong()` negatifler dahil `long` değerleri döndürür (48 bitlik tohum yüzünden bütün `long` değerlerini üretemez).
  - Derste ayrıca `nextInt(11)` sonucuna göre `if`/`else` ile farklı mesaj yazan ikinci bir sınıf çalıştırıldı (sonuç 3 olduğu için üçüncü dal çalıştı). <!-- BELİRSİZ: Bu sınıfın kodu karelerde yok. -->
- `Scanner` örneği (ekrandan, 01:30:00 ve 01:35:00)

  ```java
  package nyp01c;
  import java.util.Scanner;
  public class ConsoleIOv1 {
     public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("What is your name? ");
        String name = in.nextLine();
        System.out.print("How old are you? ");
        int age = in.nextInt();
        System.out.println("Hello, " + name +
        ". Next year, you'll be " + (age + 1) + ".");
        in.close();
     }
  }
  ```

  - `java` ile bir ad ve yaş girilerek çalıştırıldı; çıktı `Hello, <ad>. Next year, you'll be <yaş+1>.` biçimindedir.
  - Sıra ters olursa (önce `nextInt()`, sonra `nextLine()`), `nextInt()` satır sonunu okumadan bıraktığı için ilk `nextLine()` boş dizgi döndürür. Bu yüzden araya fazladan bir `nextLine()` konur (deneme ile doğrulandı). <!-- BELİRSİZ: Hocanın Eclipse'te gösterdiği ters sıralı sınıfın kodu karelerde yok. -->
- `Car` sınıfı ve kullanıcıdan plaka alma (ekrandan, 01:50:00)
  - UML sınıf kutusu:

  | Bölme | İçerik |
  |---|---|
  | Sınıf adı | `Car` |
  | Nitelik | `- plate : String` |
  | Metotlar | `+ Car( plateNr : String )`, `+ getPlate( ) : String`, `+ setPlate( String )`, `+ introduceSelf( )`, `+ main( String[ ] )` |

  ```java
  package nyp01d;
  import java.util.*;
  public class Car {
     private String plate;
     public String getPlate() {
        return plate;
     }
     public void setPlate(String plate) {
        this.plate = plate;
     }
     public Car( String plateNr ) {
        plate = plateNr;
     }
     public void introduceSelf( ) {
        System.out.println( "My plate: " + getPlate() );
     }
     public static void main( String[] args ) {
        Car aCar;
        Scanner input = new Scanner( System.in );
        System.out.print("Enter a license plate: ");
        aCar = new Car( input.nextLine() );
        aCar.introduceSelf( );
        input.close();
     }
  }
  ```

  - Kullanıcının girdiği dizgi doğrudan kurucuya verilir, oluşan nesnenin referansı `aCar`'a atanır, `introduceSelf()` plakayı `getPlate()` ile alıp yazar. Kod `java` ile çalıştırıldı ve beklenen çıktıyı verdi.
- `Scanner` neden kapatılır (öğrenci sorusu)
  - Bir öğrenci, C'de `malloc` ile alınan bellek serbest bırakılmazsa bellek dolduğunu hatırlatıp `Scanner`'ı kapatmamanın zararını sordu. Hoca şöyle anlattı: program komutları fiziksel belleğe yüklenir ve işlemci tarafından çalıştırılır; klavye ya da disk gibi aygıtlardan belleğe veri getirmek için bir kanal (stream) açmak gerekir. `Scanner` içinde bir `InputStream` nesnesi (`System.in`) tutar. Açılan her girdi/çıktı kanalı programcı tarafından kapatılmalıdır; kapatılmazsa iş JVM'ye kalır ve dışarıdan veri bekleyen bir nesne boşuna tutulur.
  - **Ders sonrası not:** Hoca `out` nesnesinin `println` gibi "static üye alanları" olduğunu söyledi; büyük olasılıkla kastedilen şudur: `out`, `System` sınıfının static bir alanıdır (bu yüzden `System.out` diye erişilir), `println` ise `out` nesnesinin (bir `PrintStream`) static olmayan bir metodudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
