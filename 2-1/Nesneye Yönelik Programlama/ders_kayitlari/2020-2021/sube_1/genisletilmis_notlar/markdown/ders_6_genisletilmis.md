# Ders 6 Genişletilmiş Notu: İlkel Tipler, Sarmalayıcı Sınıflar ve Temel Java Sınıfları (String, Math, Random, Scanner)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. İlkel Veri Tipleri
- 3. İlkel Tiplerle İşlemler
- 4. Bitsel İşlemler
- 5. Sarmalayıcı Sınıflar
- 6. Kutulama ve Kutudan Çıkarma
- 7. String Sınıfı
- 8. Math Sınıfı ve Static Metotlar
- 9. Random Sınıfı
- 10. Scanner ile Konsol Girişi
- 11. Eclipse'te Örneklerin Çalıştırılması
- 12. Car Sınıfı: Plakayı Kullanıcıdan Almak
- 13. Scanner Neden Kapatılır
- 14. Kod Yazma Pratiği Üzerine
- Örnek Sorular

## 1. Dersin Planı

Ders, bir önceki derste ilkel ve sarmalayıcı veri tiplerine kadar gelinen yerden, slayt 37'den devam etti. Hoca bu dersin planını şöyle açıkladı: ilkel sarmalayıcılar (primitive wrappers), metot parametreleri (bir metodun değerle ya da referansın değeriyle çağrılması), Java programına girdi almayı ve konsola çıktı yazmayı sağlayan bazı özel sınıflar, ardından nesne ve sınıf iş birlikleri ve ilişkileri. Ders sonunda metot parametreleri ve nesne ilişkileri sonraki derse kaldı; bu derste ilkel tipler, sarmalayıcılar, `String`, `Math`, `Random` ve `Scanner` sınıfları işlendi.

## 2. İlkel Veri Tipleri

### 2.1 Tanımlar

Slayttaki tanımlara göre ilkel tip (primitive type) tek birim bilgidir ve bir sınıf değildir. Sarmalayıcı (wrapper) ise tek bir ilkel üye alanı ve bu üyeyle ilgili bazı yararlı metotları olan bir sınıftır (ekrandan, 00:10:00).

Her programlama dilinde ilkel veri tipleri vardır. Java'da sekiz ilkel tip bulunur: `int`, `long`, `short`, `byte`, `double`, `float`, `char` ve `boolean`.

### 2.2 Tam sayılar

Kesirli kısmı olmayan sayılar için slayttaki tablo (ekrandan, 00:10:00):

| İlkel tip | Anlamı | Aralık | Sarmalayıcı |
|---|---|---|---|
| `int` | Tam sayı (4 bayt) | Alt: $-2.147.483.648$, üst: $+2.147.483.647$ | `Integer` |
| `long` | Büyük tam sayı (8 bayt) | $\pm 9{,}22 \times 10^{18}$; örnek: `long natID = 12345678900L;` | `Long` |
| `short` | Küçük tam sayı (2 bayt) | Alt: $-32.768$, üst: $+32.767$ | `Short` |
| `byte` | Bir bayt | Alt: $-128$, üst: $+127$ | `Byte` |

Hoca aralığın bayt sayısından nasıl çıktığını anlattı. `int` bellekte 4 bayt yer tutar; bir bayt 8 bit olduğuna göre `int` $8 \times 4 = 32$ bittir. Bu aralıkta negatif ve pozitif yönde değerler bulunur ve alt ile üst sınır arasındaki her tam sayı `int` ile tutulabilir. Daha büyük bir tam sayı gerekirse `long` kullanılır: 8 bayt, yani 64 bit. Daha küçük sayılar için `short` 2 bayt, yani 16 bit kullanır. `byte` ise bir bayttır.

> **Ders sonrası not:** Hoca `int` için "$2^{32}$" değerini andı. 32 bit $2^{32}$ farklı değer tutar, ama işaretli olduğu için aralık slayttaki gibi $-2^{31}$ ile $2^{31}-1$ arasıdır. Aynı şekilde `short` aralığı $-2^{15}$ ile $2^{15}-1$, `long` aralığı $-2^{63}$ ile $2^{63}-1$ arasıdır.

### 2.3 Gerçel sayılar ve diğer ilkel tipler

Slayttaki ikinci tablo (ekrandan, 00:20:00):

| İlkel tip | Anlamı | Aralık | Sarmalayıcı |
|---|---|---|---|
| `double` | Büyük gerçel sayı (8 bayt) | $\pm 1{,}79 \times 10^{308}$ | `Double` |
| `float` | Küçük gerçel sayı (4 bayt) | $\pm 3{,}4 \times 10^{38}$ | `Float` |
| `char` | Karakter (2 bayt) | `'A'-'Z'`, `'a'-'z'` vb. (UTF-16 kodlaması) | `Character` |
| `boolean` | Mantıksal (1 bit) | `false` – `true` | `Boolean` |

Slaytın altında ilkel olmayan tip `String` hakkında yakında daha fazla ayrıntı verileceği yazıyordu.

### 2.4 İlkel olmayan tipler

İlkel tiplere ek olarak ilkel olmayan (non-primitive) veri tipleri de vardır. Hoca sınıf konusunu hatırlattı: Java'da sınıf aynı zamanda bir tiptir. Nesneler sınıflardan oluşturulduğu için o sınıf nesnenin tipi olur. Sık kullanılacak ilkel olmayan tiplerden biri `String`'dir.

### 2.5 Soru-cevap: boyutlar sabit mi

**Soru:** Bu boyutlar sabit ve evrensel mi? C öğrenirken bu boyutların işlemciden işlemciye değişebildiği söylenmişti. Java sanal bir veri tipi mi oluşturuyor, yoksa boyutlar değişiyor mu?

**Cevap:** Hoca boyutların aynı olduğunu söyledi. Java kendi sanal alanını oluşturur ve bu alanda oluşturulan bütün nesneleri yönetir. Sonuçta Java nesnelerin metotlarını makine koduna, yani işlemcinin çalıştırabileceği 32 ya da 64 bitlik komutlara çevirir. İşlemcilerin üreticileri farklı olsa da bu veri tiplerinin evrensel olduğunu belirtti.

> **Ders sonrası not:** Hoca bu boyutların C, C++, C# ve Python'da da aynı olduğunu söyledi. Doğrusu: Java'da ilkel tiplerin boyları dil belirtimiyle sabittir ve platforma göre değişmez; öğrencinin sorusunun cevabı Java için "evet, sabit"tir. Ancak C ve C++'ta `int` ve `long` gibi tiplerin boyları derleyiciye ve platforma bağlıdır (örneğin `long` bazı sistemlerde 4, bazılarında 8 bayttır). Python'un tam sayıları ise sabit boylu değildir.

## 3. İlkel Tiplerle İşlemler

### 3.1 Aritmetik işleçler ve öncelik

Slaytta ilkel tiplerle yapılan işlemler listelenir (ekrandan, 00:25:00): aritmetik işleçler `+ - * / %`. Bu işleçlerin önceliği matematikteki gibidir: çarpma, bölme ve kalan (`%`) toplama ve çıkarmadan önce yapılır. Bu kural programlama dillerinde de aynıdır.

### 3.2 Kısaltmalar (shorthands)

Her programlama dilinde aritmetik işlemleri kısa yazmanın yolları vardır. Slayttaki kısaltmalar: `++`, `--` ve `+=`, `-=`, `*=`, `/=`, `%=`.

Bir değişkenin yanına iki artı işareti konursa (`i++` ya da `++i`), değişkenin değeri bir artırılır; ikisi de `i = i + 1` anlamına gelir. `--` aynı işi çıkarmayla yapar: `i = i - 1`.

Bir değişkene bir sayı eklemek için `a = a + number` açıkça yazılabilir: `a` değerine sayı eklenir ve toplam yine `a`'ya atanır. Bunun yerine `a += number` yazılabilir: değişken `+=` işaretinin soluna, eklenecek sayı sağına konur. Aynı fikir `-=`, `*=`, `/=` ve `%=` için de geçerlidir.

### 3.3 `i++` ile `++i` farkı

İki yazım da değişkeni bir artırır, ama işlecin değişkenin sağında ya da solunda olması sırayı değiştirir. Slayttaki örnek (ekrandan, 00:25:00):

```java
int i = 3;
int a = i++; // a = 3, i = 4
int b = ++a; // b = 4, a = 4
```

Adım adım:

- İlk satırda `i`'ye 3 atanır.
- İkinci satırda `++` değişkenin sağındadır. Bu, önce o satırda yapılacak işin (burada atamanın) yapılması, sonra değişkenin artırılması demektir. `i` o anda 3 olduğu için önce `a = 3` olur, sonra `i` artırılıp 4 olur.
- Üçüncü satırda `a` 3'tür ve `++` bu kez solundadır. Bu, değişkenle herhangi bir şey yapılmadan önce artırılması demektir. `a` 4 olur, sonra atama yapılır ve `b = 4` olur.

Kod `java` ile çalıştırıldı ve `i=4, a=4, b=4` sonucunu verdi.

Slaytta ayrıca `++i` ile `i++` farkının `y * ++z` ve `y * z++` ifadelerinde de ortaya çıktığı yazıyordu; bu ifadeler derste ayrıca çözülmedi.

### 3.4 `Math` sınıfının static metotları

İşleçlere ek olarak yuvarlama (`round`), mutlak değer (`abs`), karekök (`sqrt`) ve üs alma (`pow`) gibi işlemler de vardır. Slaytta "`java.lang.Math` sınıfının static metotlarına bakın: `pow`, `abs`, `round`, …" yazıyordu. Hoca farkı şöyle açıkladı: `+`, `-` gibi işleçler Java dilinin parçasıdır ve doğrudan kullanılır; üs alma, yuvarlama, mutlak değer gibi ek matematik işlemleri ise `Math` adlı bir sınıfın içinde uygulanmış metotlardır.

## 4. Bitsel İşlemler

### 4.1 Bitsel işleçler

Aritmetik işlemlerin yanında Java'da ikili (binary) işlemler de yapılabilir. Slayttaki liste (ekrandan, 00:25:00): Boole cebri işleçleri `&` (and), `|` (or), `~` (not), `^` (xor); kaydırma işleçleri `<<` ve `>>`. Slaytta örnek olarak bir `n` sayısının sağdan 4. bitinin `(n&8)/8` ya da `(n&(1<<3))>>3` ile bulunabileceği de yazıyordu; bu örnek derste ayrıca açıklanmadı.

### 4.2 OR örneği

İki tam sayı ele alınır: 12 ve 25. Aralarında OR işlemi yapılmak istenir. OR bitsel bir işlemdir; Java önce iki sayıyı ikilik sisteme çevirir:

- $12 = 00001100_2$
- $25 = 00011001_2$

En sağdaki bitten başlanarak bitler tek tek OR'lanır: 0 ile 1 → 1, 0 ile 0 → 0, 1 ile 0 → 1, … Sonuç ikilik sayı yeniden onluk sisteme çevrilir:

$$00001100_2 \;|\; 00011001_2 = 00011101_2 = 16 + 8 + 4 + 1 = 29$$

<!-- BELİRSİZ: OR slaytının karesi yok; ikilik gösterim AND slaytındaki aynı sayılardan, sonuç (29) altyazıdan alındı ve java ile doğrulandı. -->

Hoca ardından bu işlemin kodunu gösterdi: bir sınıfın içinde `main` metodu, `int` tipinde `number1` (12) ve `number2` (25) değişkenleri ile değer atanmamış bir `result` değişkeni. `result = number1 | number2;` satırı iki değeri bitsel OR'lar, 29 sonucunu `result`'a atar ve konsola yazar.

### 4.3 AND örneği

AND için kod aynıdır; yalnız OR yerine AND yapılır (ekrandan, 00:35:00):

```text
12 = 00001100 (In Binary)
25 = 00011001 (In Binary)

Bit Operation of 12 and 25
  00001100
& 00011001
  ________
  00001000 = 8 (In decimal)
```

```java
class BitwiseAND {
     public static void main(String[] args) {

        int number1 = 12, number2 = 25, result;

        result = number1 & number2;
        System.out.println(result);
     }
}
```

Bitler yine sağdan tek tek işlenir: 0 ve 1 → 0, 0 ve 0 → 0, 1 ve 0 → 0, 1 ve 1 → 1, … Sonuç $00001000_2 = 8$'dir ve program 8 yazar.

Koddaki bir ayrıntıya da dikkat çekildi: `int number1 = 12, number2 = 25, result;` satırında aralarında virgül olduğu için üç değişkenin de tipi `int`'tir. İlk ikisine başlangıç değeri atanmış, `result` ise yalnız bildirilmiştir.

## 5. Sarmalayıcı Sınıflar

### 5.1 Sarmalayıcı nedir

Nesne yönelimli programlama dillerinde ilkel veri tipleri için sarmalayıcı sınıflar (wrapper classes) da vardır. Sarmalayıcı sınıftan oluşturulan nesne, ilkel değer üzerinde işlem yapmak için yararlı ya da gerekli metotları içerir.

Örnek olarak `int` ilkel tipi ve `Integer` sınıfı alındı. `Integer` sınıfının metotlarından biri `compareTo`'dur: bir tam sayıyı başka biriyle karşılaştırır. İkinci değer birinciden büyükse −1, eşitlerse 0, birinci ikinciden büyükse +1 döner. Bir başka metot `intValue()`'dur: nesnenin verisini `int` olarak verir.

### 5.2 Bellekte ilkel değer ve sarmalayıcı nesne

Hoca bunu kamerası üzerinden tahtaya çizerek anlattı. <!-- BELİRSİZ: Tahta çizimi karelerde görünmüyor (kayıtta o sırada slayt ekranı var); anlatım yalnız altyazıdan. -->

- İlkel bir değişken (örneğin değeri 3 olan `x`) için fiziksel bellekte tipin boyu kadar, örneğin 4 baytlık yer ayrılır.
- Aynı değeri sarmalayıcıyla tutmak için `Integer` sınıfından `new` ile bir nesne oluşturulur (örneğin `y`). Bellekte bir nesne oluşur. Nesne konusunda söylendiği gibi nesnenin verisi ve metotları vardır: değer (3) veri bölümündedir; metotlar arasında `compareTo`, tam sayıyı dizgiye çeviren `toString` ve `valueOf` bulunur.
- Bu metotları çağırmak için nesnenin adı (nesnenin referansı) yazılır, ardından nokta ve metot adı gelir; örneğin `y.compareTo(...)` ile bu nesnenin değeri başka bir tam sayıyla karşılaştırılır.

İlkel değerle yalnız aritmetik ve bitsel işlemler yapılabilir. Sarmalayıcı sınıf kullanılınca bunlara ek olarak sınıfta hazır uygulanmış bütün yararlı metotlar da kullanılabilir. Her ilkel tipin (`double`, `float` vb.) bir sarmalayıcısı vardır ve hepsi benzer metotlar sunar.

### 5.3 Slayttaki ayrıntılar

Slayttaki maddeler (ekrandan, 00:40:00):

- Sarmalayıcı, sardığı (kutuladığı) ilkel tipten tek bir üye alanı olan bir sınıf gibi düşünülebilir.
- Sarmalayıcılar yararlı metotları için ve ilkel tiplerin kullanılamadığı durumlarda kullanılır. Serileştirme ve map indeksleri, ileriki haftalarda görülecek bu tür durumlara örnektir.
- Sarmalayıcılar `java.lang` paketindedir.
- `Integer` sınıfının bazı yararlı metotları (diğerleri için Java API'ye bakılır):
  - `int compareTo(Integer anotherInteger)`
  - `int intValue()`
  - `static int parseInt(String s)`
  - `String toString()`
  - `static String toString(int i)`
  - `static Integer valueOf(String s)`

Sarmalayıcı sınıflar bütün ilkel tipler için vardır: `Boolean`, `Character`, `Float`, `Double`, `Byte`, `Short`, `Long`, `Integer`.

## 6. Kutulama ve Kutudan Çıkarma

### 6.1 Kutulama (boxing)

Hoca slayttaki örneğe geçmeden önce Java'nın arka planda yaptığı bir işi anlattı. `Integer` tipinde bir sarmalayıcı değişken bildirilip ona sıradan bir `int` değeri (örneğin 4) atanırsa Java, bu tipte bir nesne oluşturup değişkene atamak istendiğini anlar. Normalde yapılması gereken, `Integer` sınıfından bir nesne oluşturmak, kurucusuna 4 değerini vermek ve bu nesnenin referansını sarmalayıcı değişkene atamaktır. Bu atama yazıldığında Java Sanal Makinesi bu işi programcı adına kendiliğinden yapar. Buna kutulama (boxing) denir.

### 6.2 Kutudan çıkarma (unboxing)

Tersi de yapılabilir. `Integer m = new Integer(6);` gibi bir sarmalayıcı nesne ilkel bir `int` değişkenine atanırsa Java, sarmalayıcı nesnenin değerinin alınıp ilkel değişkene atanmak istendiğini anlar ve nesnenin `intValue()` metodunu çağırıp sonucu atar. Buna kutudan çıkarma (unboxing) denir.

> **Ek bilgi (derste anlatılmadı):** Java'da bu otomatik dönüşümlere autoboxing ve auto-unboxing denir. Derleyici `Integer x = 4;` satırını kurucu yerine `Integer.valueOf(4)` çağrısına çevirir; `int y = x;` satırını ise `x.intValue()` çağrısına çevirir. Sarmalayıcı değişken `null` ise kutudan çıkarma sırasında `NullPointerException` oluşur.

### 6.3 Slayttaki örnek

Slayttaki kod (ekrandan, 00:40:00):

```java
Integer sarma1 = 1, sarma2 = 7;
//could use sarma1 = new Integer( 1 ); but that constructor is deprecated,
//i.e it will be removed from the language in a future version
System.out.println("Sonuç1:"+sarma1.compareTo(sarma2)); //-1
```

- `Integer sarma1 = 1;` satırında bir `int` değeri sarmalayıcı nesneye atandığı için kutulama yapılır. Java bunu `new Integer(1)` gibi bir nesne oluşturup `sarma1`'e atayarak yapar. Slayttaki yoruma göre bu kurucu artık önerilmiyor (deprecated), yani dilin ileriki bir sürümünde kaldırılacak.
- `sarma2` için de aynısı yapılır: kurucusu 7 alan bir nesne oluşur ve `sarma2`'ye atanır.
- Artık iki nesne vardır. `sarma1.compareTo(sarma2)` çağrısında parametre olarak `sarma2` verilir. İkinci değer birinciden büyükse sonuç −1, küçükse +1, eşitse 0'dır.
- `sarma2` (7) `sarma1`'den (1) büyük olduğu için sonuç −1'dir. Kod `java` ile çalıştırıldı ve `Sonuç1:-1` yazdı.

## 7. String Sınıfı

### 7.1 Genel

`String` sınıfı bir ilkel tipin sarmalayıcısı değildir; program yazarken sık kullanılacak, kendisi de bir tip olan başka bir sınıftır. Hoca bunu "bir ilkel tipin sarmalayıcısı değil ama sık kullanacağımız bir veri tipi" diye özetledi.

`String` sınıfının da çok yararlı metotları vardır: dizginin uzunluğunu almak, bir dizgiyi başka biriyle karşılaştırmak, karakterleri büyük ya da küçük harfe çevirmek, bir dizginin başka bir dizgiyi içerip içermediğini sınamak.

### 7.2 `compareTo` ile sözlük sırası

Slayttaki ilk `String` örneğinde `main` içinde `String` tipinde iki değişken bildirilir, sonra ikisine de dizgi değerleri atanır. Böylece iki `String` nesnesi oluşur ve metotları çağrılabilir. `strA.compareTo(...)` metodu parametre olarak başka bir `String` nesnesi alır ve sözlük sırasına (lexicographical order) göre karşılaştırır:

- İkinci dizgi sözlük sırasında birinciden sonra geliyorsa sonuç negatif bir sayıdır. Hoca önce "−1" dedi, sonra "negatif bir sayı" diye düzeltti.
- Birinci dizgi sözlük sırasında sonra geliyorsa sonuç pozitif bir sayıdır.
- İkisi eşitse sonuç 0'dır.

<!-- BELİRSİZ: Bu slaytın karesi yok; örnekteki dizgi değerleri okunamadı. Altyazıda yalnız "t, a'dan büyük" geçiyor. -->

### 7.3 `contains`, `toUpperCase` örneği

Slayttaki ikinci örnek (ekrandan, 00:55:00):

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

Hoca kodu satır satır izledi:

- İlk satırda `String` tipinde `strA` bildirilip değer atanır; virgül konduğu için `strB`'nin tipi de `String`'dir ve ona da aynı satırda değer atanır. Java ve çoğu dil bu yazıma izin verir; kod satırları kısalır.
- `System.out.println(...)`: `out`, `System` sınıfının altındaki bir nesnedir ve `println` metodu vardır. Parantez içine verilen girdiyi konsola yazar.
- `strA.contains(strB)` `true` ya da `false` döndürür. `"Yıldız"` dizgisi `"İstanbul"` içinde olmadığı için sonuç `false`'tur.
- `strB`'ye `"tan"` atanır. `"tan"` `"İstanbul"` içinde geçtiği için sonuç `true`'dur.
- `toUpperCase()` küçük harfleri büyük harfe çevirir.
- Son iki satırda `strB` artık `"TAN"`'dır ve `"İstanbul"` içinde büyük harfli `"TAN"` geçmediği için sonuç `false`'tur.

Kod `java` ile çalıştırıldı; çıktı sırasıyla `false`, `true`, `tan`, `true`, `TAN`, `false` oldu.

Hoca slaytı ilk anlatırken, atamasız `strB.toUpperCase();` satırından sonraki `contains` sonucunun da `false` olacağını söylemişti. Kodu Eclipse'te çalıştırırken bir öğrenci bu noktayı sordu (Bölüm 11.4).

> **Ek bilgi (derste anlatılmadı):** `String` nesneleri değişmezdir (immutable): `toUpperCase()`, `toLowerCase()` gibi metotlar mevcut nesneyi değiştirmez, yeni bir `String` döndürür. Bu yüzden sonucun bir değişkene atanması gerekir.

## 8. Math Sınıfı ve Static Metotlar

On dakikalık aradan sonra ders `Math` sınıfıyla devam etti.

### 8.1 `Math` sınıfı ve `random`

Aritmetik işlemler anlatılırken ilkel tiplere uygulanabilecek başka matematiksel işlemlerin de olduğu söylenmişti. Bu işlemler `java.lang` paketindeki `Math` sınıfında uygulanmıştır. Slayta göre bu sınıf yaygın matematik fonksiyonları için static metotlar içerir (ekrandan, 00:55:00 ve 01:10:00).

İlk metot `public static double Math.random()`'dur: bir rastgele sayı üretecidir. Slayta göre 0,0'a eşit ya da büyük, 1,0'dan küçük, pozitif işaretli bir `double` değer döndürür. Programda rastgele bir sayı gerekiyorsa bu metot çağrılır. Slayttaki örnek kod:

```java
package nyp01c;
public class MathOps01 {
    public static void main(String[] args) {
        double value = Math.random();
        System.out.println("The generated random value is: " + value);
    }
}
```

### 8.2 Static metot nasıl çağrılır

> **Hocanın vurgusu:** Bir sınıfın metodu sınıf adıyla doğrudan çağrılıyorsa o metot static olmalıdır. Static değilse önce o sınıftan bir nesne oluşturmak gerekir. Bu asla unutulmamalı.

`random` metodu `Math` içinde static tanımlandığı için `Math.random()` diye sınıf adı, nokta ve metot adı yazılarak çağrılır ve 0 ile 1 arasında bir `double` verir. Static olmasaydı önce `Math` sınıfından bir nesne oluşturmak, sonra o nesnenin metodunu çağırmak gerekirdi. Hoca bunu Türkçe de tekrarladı: static metot için sınıf adı yazılıp metot çağrılır; static değilse önce `new` anahtar sözcüğüyle nesne oluşturulur, sonra nesnenin referansının yanına nokta konup metodun adı yazılır.

`Math` sınıfının bütün metotları static'tir; hepsi sınıf adıyla doğrudan çağrılır.

### 8.3 `abs`, `max`, `min`

Slayttaki maddeler (ekrandan, 01:15:00):

- `public static <primitive> Math.abs(<primitive> a)` çeşitleri: `a` parametresinin mutlak değerini döndürür; `<primitive>` herhangi bir ilkel tiptir, örneğin `public static double Math.abs(double a)`. Girdi pozitif ya da negatif olsun, mutlak değeri ilkel tipte döner.
- `public static <primitive> Math.max(<primitive> a, b)` çeşitleri: iki parametreden büyük olanın değerini döndürür; örneğin `public static double Math.max(double a, double b)`.
- `public static <primitive> Math.min(<primitive> a, b)` çeşitleri: iki parametreden küçük olanın değerini döndürür; örneğin `public static double Math.min(double a, double b)`.

### 8.4 `ceil`, `floor`, `round`, `sqrt`

- `ceil`: verilen `double` sayıyı yukarı yuvarlar; 3,1 için 4 döner.
- `floor`: aşağı yuvarlar; 3,1 için 3 döner.
- `round`: doğru yuvarlar; 3,5 için 4, 3,1 için 3 döner.
- `sqrt`: girdinin pozitif karekökünü döndürür.

<!-- BELİRSİZ: ceil/floor/round/sqrt slaytının karesi yok; örnek değerler altyazıdan. floor örneği altyazıda "30.1" diye geçiyor, bağlama göre 3,1 alındı. -->

> **Ders sonrası not:** Hoca `round(3.1)` için "3.0" dedi. `Math.round(double)` bir `long` döndürür, sonuç `3`'tür. `ceil` ve `floor` ise `double` döndürür: `Math.ceil(3.1)` → `4.0`, `Math.floor(3.1)` → `3.0`. Değerler `java` ile denendi.

Hoca bu metotların ilerideki problemlerde kullanılacağını, zamanla hepsinin öğrenilmesi gerektiğini söyledi. Kullanımı basittir: sınıf adı, nokta, metot. Metot sıfır, bir ya da iki parametre alabilir; kaç parametre aldığına ve ne döndürdüğüne dikkat etmek gerekir.

## 9. Random Sınıfı

### 9.1 `Random` sınıfı ve paketler

Rastgele sayı üretmenin bir yolu `Math.random()`'dur; başka bir yol `Random` sınıfıdır. `Random` sınıfı `java.util` paketindedir, `Math` sınıfı ise `java.lang` paketindedir. Sarmalayıcılar, `Random`, `Math` ve `String` sınıflarının hepsi Java yazılım geliştirme kitiyle (JDK) gelir; JDK indirildiğinde bu paketler varsayılan olarak gelir ve kodda doğrudan kullanılabilir.

Slayttaki maddeler (ekrandan, 01:20:00):

- Bütün bilgisayar sistemleri sözde rastgele (pseudo-random) sayı üreteçlerine dayanır. Bu, `java.util.Random` sınıfıyla modellenir.
- `Math.random()` doğrudan kullanılırsa JRE kendiliğinden bir `Random` nesnesi oluşturur ve onu JVM'nin bütün ömrü boyunca kullanır.
- `Random` sınıfının istenen ilkel tiplerde rastgele değer almak için yararlı, static olmayan metotları vardır.

### 9.2 Static olmayan metotlar

`Math.random()` static olduğu için doğrudan çağrılabiliyordu. `Random` sınıfının metotları ise static değildir; bu yüzden metotlarını çağırmadan önce `Random` sınıfından bir nesne oluşturmak gerekir.

Slayttaki metotlar (ekrandan, 01:20:00):

| Metot | Döndürdüğü |
|---|---|
| `public boolean nextBoolean()` | $[false, true]$ |
| `public double nextDouble()` | $[0.0, 1.0)$ |
| `public float nextFloat()` | $[0.0, 1.0)$ |
| `public int nextInt()` | $(-2^{32}, 2^{32})$ |
| `public int nextInt(int bound)` | $[0, bound)$ |
| `public long nextLong()` | $[0, 2^{48})$ |

`nextBoolean` rastgele `true` ya da `false`, `nextDouble` `Math.random()` gibi 0 ile 1 arasında bir sayı, `nextFloat` aynısını `float` için verir. Her ilkel tip için rastgele üretilmiş bir değer veren bir metot vardır.

> **Ders sonrası not:** Hoca ve slayt `nextInt()` aralığını $(-2^{32}, 2^{32})$ diye verdi. Doğrusu: `nextInt()` bütün `int` değerlerinden birini döndürür, yani $-2^{31}$ ile $2^{31}-1$ arasındadır. Slayttaki `nextLong()` aralığı ($[0, 2^{48})$) da büyük olasılıkla yanlıştır: `nextLong()` negatifler dahil `long` değerleri döndürür; sınıfın tohumu yalnız 48 bit olduğu için bütün `long` değerlerini üretemez.

### 9.3 `RandomOps` örneği

Eclipse'te gösterilen kod (ekrandan, 01:40:00):

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

- `import java.util.*;` satırı `java.util` paketinin altındaki bütün sınıfları, dolayısıyla `Random`'ı da içe aktarır. Bu satır olmadan `Random` bu sınıfta kullanılamaz.
- `new Random()` ile bir nesne oluşturulur ve referansı tipi `Random` olan `generator` değişkenine atanır. `generator` artık bu yeni nesneyi gösterir.
- `generator.nextInt()` bir `int` döndürür. Pozitif değer görmek için `Math.abs` çağrılır: değer negatifse pozitifini, pozitifse kendisini verir.
- `generator.nextInt(11)` bu kez parametre alır: "0 ile 11 arasında rastgele bir pozitif tam sayı ver" demektir. Belli bir aralıkta rastgele değer isteniyorsa bu, metot çağrılırken belirtilir.

Slayttaki $[0, bound)$ gösterimine göre sınır dahil değildir; `nextInt(11)` 0 ile 10 arasında bir değer verir. Program derste çalıştırıldığında sınırlı değer 3 çıktı. Kod `java` ile tekrar çalıştırıldı ve derlenip çalıştı (değerler rastgele olduğu için her çalıştırmada farklıdır).

## 10. Scanner ile Konsol Girişi

### 10.1 Konsola yazma

Şimdiye kadar konsola değer yazmak için `System.out` kullanıldı. `out`, `System` sınıfının içindeki bir nesnedir ve `print`, `println`, `printf` gibi metotları vardır. Hoca `out`'un "static üye alanları" olduğu için `System.out.println(...)` diye doğrudan çağrılabildiğini, parantez arasına yazılan her şeyin konsola yazıldığını söyledi.

> **Ders sonrası not:** Büyük olasılıkla kastedilen şudur: `out`, `System` sınıfının static bir alanıdır (bu yüzden nesne oluşturmadan `System.out` diye erişilir); `println` ise `out` nesnesinin (bir `PrintStream`) static olmayan bir metodudur.

### 10.2 `Scanner` sınıfı

Kullanıcıdan, yani konsoldan girdi almak için `java.util` paketindeki `Scanner` sınıfı kullanılır. `Scanner`, `System.in`'i alır. `in`, tıpkı `out` gibi `System` sınıfının içinde bir nesnedir ve tipi `java.io.InputStream`'dir; bu ileride öğrenilecek.

Slayttaki maddeler (ekrandan, 01:30:00):

- `java.util.Scanner` sınıfıyla girdi işlemleri JDK 5.0 ve sonrasında vardır.
- Başlatma: `Scanner in = new Scanner(System.in);`
- `System.in`: `java.io.InputStream` tipinde public static bir üye.
- Girdi almak için metotlar (her seferinde bir öğe): `String nextLine()`, `int nextInt()`, `float nextFloat()`, …

### 10.3 `ConsoleIOv1` örneği

Slayttaki kod (ekrandan, 01:30:00):

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

Hoca kodu satır satır anlattı:

- İlk satırda `Scanner` sınıfının tek parametreli kurucusu çağrılarak bir nesne oluşturulur ve `System.in` verilir. `System.in`, klavyeden değer almayı sağlayan, `Scanner`'a verilmesi gereken varsayılan nesnedir. Nesnenin referansı tipi `Scanner` olan değişkene atanır.
- Kullanıcıdan bir şey girmesini istemek için ekrana bir mesaj yazılır; burada bir dizgi istenir.
- `nextLine()` çağrılınca program kullanıcı klavyeden bir şey girene kadar bekler; girilen değer alınır ve `name` değişkenine atanır.
- Ardından başka bir mesaj yazılır ve `nextInt()` çağrılır; bu kez bir tam sayı istenir ve girilen değer `age` değişkenine atanır.
- `name` ve `age` kullanıcıdan alındıktan sonra `System.out.println` ile ekrana yazılır.
- `Scanner` nesnesi her kullanıldığında sonunda `close()` metodu çağrılarak kapatılmalıdır.

Kod `java` ile bir ad ve yaş girilerek çalıştırıldı; çıktı `Hello, <ad>. Next year, you'll be <yaş+1>.` biçiminde oldu.

## 11. Eclipse'te Örneklerin Çalıştırılması

### 11.1 `ConsoleIOv1`

Hoca örnekleri Eclipse'te gösterdi (ekrandan, 01:35:00). Sınıfta `Scanner` kullanılacağı için `import java.util.Scanner;` satırı gerekir. Program çalıştırıldığında konsol 10. satırda (`nextLine()`) kullanıcının bir şey girmesini bekler. Hoca bir harf girip Enter'a bastı; değer `name` değişkenine atandı, ardından "How old are you?" yazıldı ve program bu kez bir tam sayı bekledi. Tam sayı girilince değer `age`'e atandı ve program adı ve `age + 1` değerini yazdı.

### 11.2 `nextInt()` sonrası `nextLine()` tuzağı

> **Hocanın vurgusu:** Önce bir dizgi, sonra ilkel bir değer alınıyorsa sorun yoktur. Ama önce ilkel bir değer alınıp sonra dizgi alınacaksa, program dizgiyi almadan bir sonraki satıra geçer. Bunu önlemek için ilkel değeri okuyan çağrıdan sonra atama yapılmadan bir `nextLine()` çağrılır, sonra dizgi için yeniden `nextLine()` çağrılır; yani araya fazladan bir `nextLine()` konur.

Hoca bunu ikinci bir sınıfla gösterdi: program önce yaşı, sonra adı sordu. Kodun 11. satırındaki fazladan `nextLine()` çağrısının tek amacı, kullanıcının sonra gireceği dizgi değerinin doğru yakalanmasıdır. <!-- BELİRSİZ: Bu sınıfın kodu karelerde yok; satır numarası altyazıdan. -->

Davranış `java` ile denendi: önce `nextInt()`, ardından `nextLine()` çağrıldığında ilk `nextLine()` boş dizgi döndürdü; ikinci `nextLine()` adı doğru okudu.

> **Ek bilgi (derste anlatılmadı):** `nextInt()` yalnız sayıyı okur, kullanıcının Enter ile girdiği satır sonu karakterini girdi akışında bırakır. Hemen ardından gelen `nextLine()` bu boş satırı okuyup hemen döner. Araya konan fazladan `nextLine()` bu satır sonunu tüketir.

### 11.3 `Math` ve `Random` örnekleri

- `Math.random()` örneği çalıştırıldı ve 0 ile 1 arasında bir `double` değer verdi.
- `round` örneğinde değer 3,5'ti ve 4'e yuvarlandı.
- `RandomOps` çalıştırıldı (Bölüm 9.3): `nextInt()` varsayılan aralıkta bir değer, `nextInt(11)` ise 3 verdi.
- Bir sonraki sınıf `RandomOps`'un aynısıydı, ama `nextInt(11)` sonucuna `if`/`else` uygulanıyordu: sonuç 0 ise bir mesaj, 1 ise başka bir mesaj, daha büyükse bir başka mesaj yazılıyordu. Sonuç 3 çıktığı için 0 ya da 1 olmadığından üçüncü dal çalıştı. <!-- BELİRSİZ: Bu sınıfın kodu ve mesajları karelerde yok. -->

### 11.4 `StringOps02` ve soru-cevap

Ardından `StringOps02` çalıştırıldı (Bölüm 7.3). İlk `contains` çağrısı `false` döndü çünkü `"İstanbul"` içinde `"Yıldız"` yoktur; `strB`'ye `"tan"` atanınca `true` döndü.

**Soru:** `toUpperCase` sonucunu `strB`'ye yeniden atamadığımız için mi küçük kalıyor, yoksa metodu çağırınca nesnenin harfleri büyük mü oluyor? Çıktıda `tan` küçük kalmış görünüyor; iki satır alttaki satırdan farkı yalnız atama.

**Cevap:** Hoca öğrencinin haklı olduğunu söyledi: o satırda atama yapılmamıştır. `toUpperCase()` büyük harfli bir değer döndürür, ama atanmadığı için `strB` hâlâ küçük harfle yazılır ve `"İstanbul"` içinde hâlâ bulunur (`true`). Alttaki satırda atama `strB`'ye yapılır; `strB` artık büyük harfli `"TAN"`'dır ve kontrol edilince bu kez `false` çıkar.

## 12. Car Sınıfı: Plakayı Kullanıcıdan Almak

Slaytta, `main` metodu plakayı kullanıcıdan alacak biçimde değiştirilmiş bir `Car` sınıfı vardı (ekrandan, 01:50:00).

UML sınıf kutusu:

| Bölme | İçerik |
|---|---|
| Sınıf adı | `Car` |
| Nitelik | `- plate : String` |
| Metotlar | `+ Car( plateNr : String )` |
| | `+ getPlate( ) : String` |
| | `+ setPlate( String )` |
| | `+ introduceSelf( )` |
| | `+ main( String[ ] )` |

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

Hoca kodu şöyle anlattı:

- Sınıfta private tanımlanmış tek bir global üye alanı (`plate`), tek parametreli bir kurucu ve getter/setter metotları vardır. Gelenek olarak bütün global üye alanlar private tanımlanır ve her private alan için getter ve setter yazılır.
- `introduceSelf()` bir şey döndürmediği için `void`'dir.
- `main` içinde `Car` tipinde `aCar` değişkeni bildirilir. Sonra bir `Scanner` nesnesi oluşturulur; `Scanner` varsayılan olarak `System.in` alır. Nesnenin referansı tipi `Scanner` olan `input` değişkenine atanır.
- Kullanıcının değer girmesi için konsola bir mesaj yazılır. `input.nextLine()` çağrılınca imleç konsolda kullanıcının bir şey girmesini bekler.
- Kullanıcının girdiği dizgi doğrudan `Car` kurucusuna girdi olarak verilir. `new` anahtar sözcüğüyle nesne oluşturulur ve referansı `aCar`'a atanır.
- `aCar.introduceSelf()` çağrılır. Bu metot bir mesaj yazar ve `getPlate()` ile, kullanıcının girdiği plakayla başlatılmış `plate` değerini alıp yazar.
- Sonunda `input.close()` çağrılır. `Scanner` her kullanıldığında kod bitmeden `close` çağrılmalıdır.

Kod `java` ile bir plaka girilerek çalıştırıldı; `My plate: <girilen plaka>` çıktısını verdi.

## 13. Scanner Neden Kapatılır

**Soru:** `Scanner`'ı kapatmamızın özel bir sebebi var mı? C'de `malloc` ile alınan yerler serbest bırakılmazsa bellek doluyordu. Burada kapatmamanın dezavantajı ne, neden kapatıyoruz?

**Cevap:** Hoca şöyle anlattı:

- Bilgisayarda fiziksel bellek vardır. Bunun dışında veri sağlayan fiziksel disk, klavye gibi aygıtlar vardır; bunlardan belleğe veri taşınır.
- Yazılan kodlar komutlara dönüşür ve fiziksel bellekte yerlerini alır. İşlemcinin bu komutları işleyebilmesi için komutlar işlemcinin yazmaçlarına getirilir ve satır satır çalıştırılır.
- Kullanıcının verdiği bir şeyi belleğe getirebilmek için bir boru hattı (pipeline), bir kanal açmak gerekir; yani veri aktarımını sağlayacak bir nesne oluşturmak gerekir.
- Bu nesne `Scanner` ile, aslında `Scanner`'ın içinde `System.in` ile oluşturuldu. `InputStream` diye bir sınıf vardır ve `in` onun bir nesnesidir; bu nesne `Scanner` nesnesinin içine global bir üye alanı olarak konmuştur. `Scanner` açılınca bu kanal açılır.
- Bir dosya sisteminde dosya açarken ya da kullanıcıdan veri alırken girdi/çıktı akışları (input stream, output stream) açıldığında bunlar kapatılmak zorundadır. Programcı bunu yapmazsa iş JVM'ye kalır: JVM dünyasında açık, referansı duran ve hâlâ bir aygıttan bir şey bekleyen bir nesne boşuna tutulur.
- Dış dünyadan veri bekleyen nesnelerin bu bekleme durumu mutlaka kapatılmalıdır. Kapatılmazsa program dışarıdan veri gelmesine açık bırakılmış olur.

> **Hocanın vurgusu:** Program ile girdi/çıktı aygıtları arasında veri alan ya da veren bir kanal açıldığında mutlaka `close` metodu çağrılmalıdır.

> **Ek bilgi (derste anlatılmadı):** `System.in` ile oluşturulmuş bir `Scanner` kapatılınca altındaki `System.in` akışı da kapanır. Bu yüzden aynı programda daha sonra yeni bir `Scanner(System.in)` ile okumaya çalışmak hata verir; programda tek bir `Scanner` oluşturup işi bitince kapatmak yaygın bir yaklaşımdır.

## 14. Kod Yazma Pratiği Üzerine

Hoca, Eclipse, NetBeans ya da IntelliJ'den hangisi tercih ediliyorsa bilgisayara kurulmasını istedi. Derste işlenen kodlar indirilip Eclipse'te gösterildiği gibi çalıştırılmalı, nasıl çalıştıklarına bakılmalı, kodlar değiştirilmeli ve yeni öğrenilen sınıfların metotları denenmelidir.

> **Hocanın vurgusu:** Kod yazarken bir metodun nasıl bildirildiği (private, public, protected), `main` metodunun nasıl yazıldığı, `static`'in `void`'den önce mi sonra mı geldiği gibi ayrıntılar alışkanlık hâline gelmiş olmalı. Bir problem, açıklama ya da sınıf diyagramı verilip "bunun kodunu yaz" dendiğinde odak bu ayrıntılarda değil, problemin çözümünde olmalı.

Bir sonraki derste metot parametreleri ve kontrol akışı, ardından nesne ilişkileri işlenecek.

## Örnek Sorular

**1. (ekrandan, 00:25:00)** Aşağıdaki kod çalıştıktan sonra `i`, `a` ve `b` kaçtır?

```java
int i = 3;
int a = i++;
int b = ++a;
```

> **Çözüm (derste verildi):** `a = i++` önce atar sonra artırır: `a = 3`, `i = 4`. `b = ++a` önce artırır sonra atar: `a = 4`, `b = 4`. Sonuç: `i = 4`, `a = 4`, `b = 4` (`java` ile doğrulandı).

**2. (ekrandan, 00:35:00; derste sözlü, 00:31:06)** `12 | 25` ve `12 & 25` kaçtır?

> **Çözüm (derste verildi):** $12 = 00001100_2$, $25 = 00011001_2$. OR: $00011101_2 = 29$. AND: $00001000_2 = 8$ (`java` ile doğrulandı).

**3. (ekrandan, 00:40:00)** `Integer sarma1 = 1, sarma2 = 7;` için `sarma1.compareTo(sarma2)` ne döndürür?

> **Çözüm (derste verildi):** İkinci değer (7) birinciden (1) büyük olduğu için −1. Program `Sonuç1:-1` yazar.

**4. (ekrandan, 00:55:00)** Bölüm 7.3'teki `StringOps02` programının çıktısı nedir?

> **Çözüm (derste verildi, öğrenci sorusuyla düzeltildi):** `false`, `true`, `tan`, `true`, `TAN`, `false`. Atamasız `strB.toUpperCase();` satırı `strB`'yi değiştirmez (`java` ile doğrulandı).

**5. (derste sözlü, 00:19:28)** Java'daki ilkel tiplerin boyutları işlemciden işlemciye değişir mi?

> **Çözüm:** Java'da değişmez; boyutlar dil belirtimiyle sabittir (Bölüm 2.5'teki ders sonrası nota bakın).

**6. (derste sözlü, 01:49:32)** `Scanner` nesnesini neden kapatmalıyız?

> **Çözüm (derste verildi):** `Scanner`, `System.in` üzerinden dış dünyadan veri alan bir kanal açar. Açılan girdi/çıktı kanalları programcı tarafından `close()` ile kapatılmalıdır; kapatılmazsa iş JVM'ye kalır ve veri bekleyen bir nesne boşuna tutulur (Bölüm 13).

## Dersin Toparlaması

Bu derste Java'daki sekiz ilkel veri tipi, bellekte kapladıkları yer ve aralıklarıyla birlikte ele alındı; ilkel tiplerle yapılan aritmetik ve bitsel işlemler, `++`/`--` ve `+=` gibi kısaltmalar örneklerle gösterildi. Her ilkel tipin bir sarmalayıcı sınıfı olduğu, sarmalayıcının değeri bir nesnenin içinde tutup `compareTo`, `intValue`, `parseInt` gibi yararlı metotlar sunduğu ve Java'nın ilkel değer ile sarmalayıcı nesne arasında kutulama ve kutudan çıkarmayı kendiliğinden yaptığı anlatıldı. Ardından sık kullanılan `String`, `Math`, `Random` ve `Scanner` sınıfları tanıtıldı. Bu sınıfların üzerinden static metotların sınıf adıyla, static olmayan metotların ise önce bir nesne oluşturularak çağrıldığı vurgulandı; `Scanner` ile kullanıcıdan girdi alma, `nextInt()` sonrası `nextLine()` tuzağı ve açılan akışların kapatılması örneklerle gösterildi.

Ders, plakası kullanıcıdan alınan `Car` sınıfı örneğiyle, yani daha önce görülen sınıf yapısının bu derste öğrenilen `Scanner` ile birleştirilmesiyle bitti. Bir sonraki derste metot parametreleri (değerle çağırma ve referansın değeriyle çağırma), kontrol akışı ve nesneler arası ilişkiler işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
