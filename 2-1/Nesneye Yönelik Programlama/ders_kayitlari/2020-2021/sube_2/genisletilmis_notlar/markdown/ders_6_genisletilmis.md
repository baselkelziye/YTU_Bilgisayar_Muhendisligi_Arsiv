# Ders 6 Genişletilmiş Notu: Adaş Constructor'lar, İlkel Türler ve Sarmalayıcılar, String, Math, Random ve Scanner

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersten kalan yer: Car sınıfı ve sıralama şeması
- 2. İkinci alan: şasi numarası ve constructor tasarımı
- 3. Kod üzerinde deneme: adaş constructor'lar ve final alanlar
- 4. Soru-cevap: birden çok constructor ne zaman mantıklı?
- 5. İlkel türler ve sarmalayıcılar
- 6. İlkellerle işlemler: aritmetik ve bit işlemleri
- 7. Sarmalayıcılara daha yakından bakış: Integer sınıfı
- 8. String sınıfının metotları
- 9. Math sınıfı
- 10. Rastgele sayılar ve Random sınıfı
- 11. Komut satırından girdi ve çıktı: Scanner
- 12. Kullanıcıdan bilgi alarak Car nesnesi oluşturmak
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki dersten kalan yer: Car sınıfı ve sıralama şeması

Önceki derste bir `Car` sınıfı tasarlanmış, constructor'ı ve metotları denenmiş, ders `main` metodunun sıralama şemasıyla (sequence diagram) bitmişti. Slayttaki şemada `main`, önce `:Car` sınıfına `new("34 RA 440")` mesajını gönderir ve `aCar:Car` nesnesi oluşur. Sonra bu nesneye `introduceSelf()` mesajı gider. Nesne de kendi `getPlate()` metodunu çağırır (kendine dönen ok). Slayttaki uyarı, okların sırasına ve hizasına çok dikkat edilmesidir (ekrandan, 00:05:00).

Bu derste örnek bir üye alan daha eklenerek genişletilir. Bu yolla constructor aşırı yükleme (constructor overloading) ve constructor yazarken dikkat edilecek noktalar gösterilir.

## 2. İkinci alan: şasi numarası ve constructor tasarımı

### 2.1 Tanımlayıcı alanlar constructor'a girer

`Car` sınıfına `plate` alanının yanına `chassisNR` (şasi numarası) adlı ikinci bir `private` alan eklendi. Hocanın ilkesi şudur: bir nesneyi tanımlayan, mutlaka anlamlı bir değeri olması gereken alanlar constructor'da ilklendirilir. Bu yüzden constructor iki parametre alır.

Slayttaki "Another version of the class Car" kodu (ekrandan, 00:40:00):

```java
package nyp01b;
public class Car {
   private String plate;
   private String chassisNR;
   public Car( String plateNr, String chassisNR ) {
      plate = plateNr;
      this.chassisNR = chassisNR;
   }
   public String getPlate() {
      return plate;
   }
   public void setPlate(String plate) {
      this.plate = plate;
   }
   public String getChassisNR( ) {
      return chassisNR;
   }
}
```

UML sınıf şemasında alanlar `- plate : String` ve `- chassisNR : String`, metotlar `+ Car( String, String )`, `+ getPlate( ) : String`, `+ setPlate( String )`, `+ getChassisNR( ) : String` olarak gösterilir. Bu sınıfta `main` metodu yoktur. Bu yüzden tek başına çalıştırılamaz; denemek için `main` metodu olan başka bir sınıf yazmak gerekir.

### 2.2 UML'de constructor parametreleri

Hoca burada kendi şeklinde "kolaya kaçtığını" söyledi. Kodda birinci parametrenin plaka, ikincinin şasi numarası olduğu açıkça görülür. Ama UML şemasında yalnız `Car(String, String)` yazınca hangi parametrenin hangi alanı ilklendirdiği belli olmaz, çünkü iki alan da `String`'dir. Daha doğrusu `Car(plateNr : String, chassisNR : String)` biçiminde parametre adlarını da yazmaktır.

> **Hocanın vurgusu:** UML şemasında constructor parametrelerinin adlarını da yazmaya özen gösterin.

### 2.3 Her alana ayrı constructor yazılabilir mi?

Hoca şu soruyu sordu: iki alan için ayrı ayrı constructor tanımlasak olur mu? Kısa cevabı: olmaz. Slaytta solda doğru, sağda yanlış kod yan yana verildi (ekrandan, 00:10:00):

```java
// Doğru (solda)
public class Car {
   private String plate;
   private String chassisNR;
   public Car( String plateNr,
               String chassisNR ) {
      plate = plateNr;
      this.chassisNR = chassisNR;
   }
   /* Rest of the code */
}

// Yanlış (sağda)
public class Car {
   private String plate;
   private String chassisNR;
   public Car( String plateNr ) {
      plate = plateNr;
   }
   public Car(String chassisNR ) {
      this.chassisNR = chassisNR;
   }
   /* Rest of the code */
}
```

Sağdaki kod iki nedenle yanlıştır:

- **İş mantığı.** Gerçek dünyada her aracın hem plakası hem şasi numarası olmalıdır. Bunu yalnız soldaki yapı sağlar. Sağdakinde hangi constructor çağrılırsa öteki alan atanmamış kalır. "Eksik alanı sonra setter ile atarım" denebilir. Ama bu atama unutulabilir ya da kasıtlı olarak yapılmayabilir. Setter'ı olmayan, yalnız constructor ile ilklendirilen bir sınıfta ise ikinci constructor'ı çağırmak ilk nesneyi güncellemez. Bellekte yepyeni bir nesne oluşur, ilk nesne kaybolur.
- **Derleme.** İki constructor'ın adı aynıdır ve ikisi de tek bir `String` parametre alır. Bir yerde tek `String` ile constructor çağrıldığında derleyici hangisini kastettiğini anlayamaz. Bu yüzden kod derlenmez.

Slayttaki "Compile error vs. bug" maddesi bunu özetler: sağdaki kod derlenmez; derlenseydi mantığı yine yanlış (buggy) olurdu. Şasi numarası parametresi `int` olsaydı derleme hatası kalkardı, ama mantık hatası sürerdi. Slayttaki son madde de şunu söyler: gerçek dünyada şasi numarası değişmez, bu yüzden o alanın setter'ı yazılmadı; yazılsaydı başka bir bug eklenmiş olurdu (`final` alanlara birazdan değinilecek).

> **Hocanın vurgusu:** Bir nesnenin mutlaka anlamlı değere sahip olması gereken bütün üye alanlarının yer aldığı bir constructor tanımlanmalıdır.

## 3. Kod üzerinde deneme: adaş constructor'lar ve final alanlar

### 3.1 Aynı imzalı iki constructor: derleme hatası

Hoca Eclipse'te iki tek parametreli constructor yazdı. Biri `plateNr`, öteki `chassisNR` alıyordu ve ikisi de `String`'di. Eclipse hemen derleme hatası gösterdi: "Duplicate method Car(String) in type Car" (ekrandan, 00:15:00). Java 25 ile aynı kod denendiğinde de hata `constructor Car(String) is already defined in class Car` olarak alındı.

### 3.2 Farklı parametre türü: adaş metotlar

Sonra şasi numarasının türü geçici olarak `int` yapıldı. Artık iki constructor'ın imzası farklıydı (biri `String`, öteki `int` alıyor), bu yüzden derleme hatası kalktı. `introduceSelf()` metodu da şasi numarasını yazacak biçimde genişletildi.

Aynı adlı ama farklı parametre listesine sahip metotlara **adaş metotlar** (overloaded methods), bu işe de **aşırı yükleme** (overloading) denir. Bu yalnız constructor'larla sınırlı değildir; her metot aşırı yüklenebilir.

Hoca Eclipse'te bir alanın üstünde sağ tıklayıp Source → Generate Getters and Setters ile getter ve setter'ların kendiliğinden üretilebileceğini de hatırlattı.

### 3.3 İki constructor'ı arka arkaya çağırmak

Eclipse'in proje klasörüyle ilgili bir sorunu nedeniyle kodlar başka bir çalışma klasörüne kopyalandı. Sonra `MainProgram` sınıfında şu kod çalıştırıldı (ekrandan, 00:25:00):

```java
package nyp01b;

public class MainProgram {

    public static void main(String[] args) {
        Car aCar = new Car("34 RA 440");
        aCar = new Car(3434);
        aCar.introduceSelf();
    }

}
```

Çıktı:

```text
My plate is null and my chassis nr is 3434
```

6. satırda oluşturulan nesne, 7. satırda yerine yeni bir nesne atanınca kaybolur. 8. satırdaki nesnenin yalnız şasi numarası vardır. Plaka `null` görünür, çünkü ilklendirilmemiş nesne başvuruları `null` değerine sahiptir. Constructor'ların sırası değiştirilse bu kez plaka kalır, şasi numarası kaybolur. (Kod Java 25 ile denendi, aynı çıktıyı verdi.)

### 3.4 final alanlarla tek parametreli constructor'lar

Hoca setter'ları silip iki alanı da `final` yaptı. `final` alana yalnız bir kez değer atanabilir ve bu atama constructor bitmeden yapılmalıdır. Tek parametreli iki constructor'da her seferinde öteki alan açıkta kalır. Derleyici ilkinde "şasi numarası ilklendirilmemiş olabilir", ikincisinde "plaka ilklendirilmemiş olabilir" der. (Java 25 ile denendi: `variable chassisNR might not have been initialized` ve `variable plate might not have been initialized`.)

Sonuç olarak doğru çözüm en baştan söylendiği gibi iki parametreyi aynı constructor'da almaktır. Hoca bunu Eclipse'in Source → Generate Constructor using Fields seçeneğiyle üretti. Üretilen kodda görülen `super()` çağrısı kalıtımla ilgilidir ve sonra anlatılacak. Şasi numarası yeniden `String` yapıldı (gerçekte şasi numaralarında harf de bulunur). `main` de buna göre düzeltildi. Çalıştırılınca çıktı şöyle oldu (ekrandan, 00:30:00):

```text
My plate is 34 RA 440 and my chassis nr is ASX3434
```

`main` metodu başka bir sınıfta, `Car` başka bir sınıftadır. Yine de `Car`'ın constructor'ı ve `public` metotları üzerinden nesne oluşturulup kullanılabilir.

## 4. Soru-cevap: birden çok constructor ne zaman mantıklı?

**Soru:** Tek bir constructor yazmak daha kolay görünüyor. Biri neden iki constructor yazmak istesin; işe yaradığı bir durum var mı?

**Cevap:** Hoca bir senaryo önerdi. Şasi numarası fabrikada mutlaka yazılır ve hiç değişmez, bu yüzden `final` kalır. Plaka ise sonradan atanabilir ve değişebilir. Bazen araç fabrikadan yalnız şasi numarasıyla çıkar. Bazen de bayi müşterinin siparişini önceden almış, plaka işlerini halletmiştir; araç fabrika çıkışında plakası takılarak gelir. İki senaryo da mantıklıdır. Bu durumda iki constructor birlikte tanımlanır: plaka ve şasi numarası alan `Car(String plate, String chassisNR)` ile yalnız şasi numarası alan `Car(String chassisNR)`. Plaka sonradan atanabileceği için `setPlate` metodu da mutlaka eklenmelidir.

Karede bu sürüm görülür: `private final String chassisNR;`, iki parametreli constructor ve tek parametreli `Car(String chassisNR)` (ekrandan, 00:30:00). O anda tek parametreli constructor'da yanlışlıkla kalan `this.plate = plate;` satırı için Eclipse "The assignment to variable plate has no effect" uyarısını veriyor. Bu satır silinmelidir.

```java
public class Car {
    private String plate;
    private final String chassisNR;
    public Car(String plate, String chassisNR) {
        this.plate = plate;
        this.chassisNR = chassisNR;
    }
    public Car(String chassisNR) {
        this.chassisNR = chassisNR;
    }
    public void setPlate(String plate) { this.plate = plate; }
    // getPlate, getChassisNR, introduceSelf ...
}
```

(Bu sürüm Java 25 ile denendi: `new Car("ASX3434")` önce `My plate is null and my chassis nr is ASX3434` yazar, `setPlate("34 RA 440")` sonrasında plaka da görünür.)

## 5. İlkel türler ve sarmalayıcılar

### 5.1 Tanımlar

Java'da **ilkel türler** (primitives) yalnız tek bir bilgi içeren, sınıf olmayan türlerdir. Sınıflar ise Java'nın kendisinden gelen ya da bizim tanımladığımız türlerdir; bunlara non-primitive de denebilir.

**Sarmalayıcı** (wrapper) sınıf, ilgili ilkel türden tek bir üye alan ve o türle ilgili yararlı metotlar içeren sınıftır. Her ilkelin bir sarmalayıcısı vardır. İleride ilkellerin kullanılamadığı konular görülecek; o durumlarda ilkelin yerine sarmalayıcısı kullanılacak (ekrandan, 00:35:00).

### 5.2 Tam sayı türleri

Slayttaki tablo (ekrandan, 00:35:00):

| İlkel | Anlam | Aralık | Sarmalayıcı |
|---|---|---|---|
| `int` | Tam sayı (4 bayt) | −2.147.483.648 … +2.147.483.647 | `Integer` |
| `long` | Büyük tam sayı (8 bayt) | ± 9,22 × 10^18; `long natID = 12345678900L;` | `Long` |
| `short` | Küçük tam sayı (2 bayt) | −32.768 … +32.767 | `Short` |
| `byte` | Bir bayt | −128 … +127 | `Byte` |

`int` yaklaşık ±2 milyarlık bir aralığı kapsar. Bu, örneğin 11 haneli T.C. kimlik numaralarını tutmaya yetmez. Bunun için `long` kullanılabilir. Bir sayı sabitini `long` olarak yazarken `int` ile karışmaması için sonuna büyük `L` harfi konur. Bellekten tasarruf etmek için daha küçük aralıklarda `short` ya da `byte` seçilebilir.

Sarmalayıcıların adı genelde ilkelin adının ilk harfi büyütülerek elde edilir, çünkü sınıf adları büyük harfle başlar: `long` → `Long`, `short` → `Short`, `byte` → `Byte`. İstisna `int`'tir; sarmalayıcısının adı uzun biçimiyle `Integer`'dır.

> **Ders sonrası not:** Hoca, `int`, `short`, `byte` gibi sayısal ilkellerin başına `unsigned` yazılarak işaretsiz yapılabileceğini söyledi (örneğin `unsigned int` için 0 ile 4 milyar arası) ve slayta "These numerical primitives can also be marked as unsigned" cümlesini ekledi. Doğrusu: Java'da `unsigned` anahtar sözcüğü yoktur, `byte`, `short`, `int` ve `long` her zaman işaretlidir. Java'da işaretsiz olan tek ilkel 16 bitlik `char`'dır. Java 8'den beri `Integer.toUnsignedString`, `Integer.divideUnsigned` gibi metotlarla bir `int` işaretsiz olarak yorumlanabilir.

### 5.3 Ondalıklı sayılar, karakter ve mantıksal tür

Ondalıklı sayılar için iki seçenek vardır ve avantajları birbirinin tam tersidir:

- **`double`:** Daha geniş aralık (yaklaşık ±10^308) ve daha yüksek bilimsel duyarlık sağlar. Karşılığında bellekte daha çok yer kaplar ve işlemleri daha yavaştır.
- **`float`:** Daha dar aralıktadır (yaklaşık ±3,4 × 10^38), daha az bayt kaplar ve işlemleri daha hızlıdır.

Bilimsel yazılım gibi hassas hesap gereken yerde `double` seçilir. Bu ders kapsamında hassas hesap yapılmayacağı için ikisinden biri kullanılabilir; hoca alışkanlıkla `double` kullanıyor. Hoca, Bilgisayar Bilimlerine Giriş dersinde anlatılan bir noktayı da hatırlattı: bilgisayar ikili sayı düzeninde çalıştığı için onlu ondalıklı sayıları tam göstermek zordur. Bu yüzden bilimsel hesaplarda duyarlık sorunu bilinmelidir.

`char` tek bir karakteri tutar: büyük A'dan büyük Z'ye, küçük a'dan küçük z'ye, uluslararası simgeler ve bazı matematik karakterleri. UTF-16 kodlaması kullanıldığı için Çince ve Japonca karakterleri de destekler. Sarmalayıcısı `Character`'dır. Doğru/yanlış değeri için `boolean` vardır, sarmalayıcısı `Boolean`'dır.

<!-- BELİRSİZ: double, float, char ve boolean'ın bulunduğu tablo (slayt 38) okunabilir bir karede görünmüyor; aralıklar altyazıdan alındı ve Java'nın Double.MAX_VALUE ile Float.MAX_VALUE değerleriyle doğrulandı. -->

## 6. İlkellerle işlemler: aritmetik ve bit işlemleri

### 6.1 Aritmetik işlemler

Slayttaki özet (ekrandan, 00:45:00):

- Aritmetik: `+ - * / %` (`%` mod alma).
- Operatör önceliğini unutmayın: `*`, `/` ve `%`, `+` ile `-`'den önce gelir. Parantez yoksa önce yüksek öncelikliler, sonra eşit öncelikliler soldan sağa değerlendirilir.
- `++`, `--`.
- `++i` ile `i++` farklıdır: `y * ++z` önce `z`'yi bir artırır, sonra `y` ile çarpar. `y * z++` önce `y * z`'yi hesaplar, sonra `z`'yi artırır.
- Kısaltmalar: `+= -= *= /= %=`.
- `java.lang.Math`'in statik metotlarına bakın: `pow`, `abs`, `round` … `java.lang` paketi import edilmeden kullanılabilir.

(Ara adım eklendi: `y = 2, z = 3` için `y * ++z` = 8; `y * z++` = 6 ve işlemden sonra `z` = 4. Java ile doğrulandı.)

### 6.2 Bit işlemleri

İkili işlemler: Boole cebri için `&` (and), `|` (or), `~` (not), `^` (xor); kaydırma için `<<` (sola) ve `>>` (sağa). Slayttaki örnek: n'nin sağdan 4. biti `(n&8)/8` ya da `(n&(1<<3))>>3` ile bulunur (ekrandan, 00:45:00).

Hoca bunu Excel'de gösterdi (ekrandan, 00:50:00). Basamaklar sağdan sıfırdan başlayarak numaralandırıldığı için sağdan 4. bit 2^3 = 8'in basamağıdır. Örnek sayı olarak 1 0 1 1 0 1 0 1 bitleri yazıldı.

- **Birinci yol:** `n & 8`. 8'in ikili gösterimi 00001000'dır. AND işleminde sonucun 1 olması için iki bitin de 1 olması gerektiğinden, sonuç ilgilenilen bit 1 ise 8, 0 ise 0 olur. Bunu 8'e bölünce 8/8 = 1 ya da 0/8 = 0, yani bitin kendisi bulunur.
- **İkinci yol:** Maskeyi 8 yazmadan üretmek. 1 sayısı (00000001) 3 bit sola kaydırılır; boşalan basamaklar 0 ile dolar ve maske 00001000 olur. Bu maske sayıyla AND'lenir. Sonuç 3 bit sağa kaydırılınca ilgilenilen bit en sağa gelir ve 0 ya da 1 olarak okunur.

Örnekteki sayıda 4. bit 0'dır, iki yol da 0 verir. Hoca ardından bitin 1 olduğu durumu da renklendirerek gösterdi; o durumda iki yol da 1 verir. (Java ile denendi: `n = 0b10110101` için `(n&8)/8` ve `(n&(1<<3))>>3` ikisi de 0.)

Hoca bu konuların önceki derslerde işlendiğini, nesneye yönelik programlamanın odak noktası olmadığını, yalnız hatırlatma amacıyla anlatıldığını söyledi.

## 7. Sarmalayıcılara daha yakından bakış: Integer sınıfı

### 7.1 Neden sarmalayıcı?

Bir sarmalayıcı, sarmaladığı (bazı kaynaklarda "kutuladığı", box) ilkel türden tek bir üye alanı olan bir sınıf gibi düşünülebilir (ekrandan, 01:10:00). Sarmalayıcıları iki amaçla kullanırız:

- Yararlı metotları için.
- İlkellerin kullanılamadığı durumlar için. Slayttaki örnekler serileştirme (nesneleri bütün durumlarıyla diske yazma ya da ağ üzerinden gönderme) ve map yapılarındaki anahtarlardır. İkisi de sonraki haftalarda görülecek.

Sarmalayıcılar `java.lang` paketindedir.

### 7.2 Integer'ın bazı metotları

Slayttaki liste (ekrandan, 01:10:00):

- `int compareTo(Integer anotherInteger)`
- `int intValue()`
- `static int parseInt(String s)`
- `String toString()`
- `static String toString(int i)`
- `static Integer valueOf(String s)`

Hoca metot imzalarının nasıl okunacağını da anlattı. Başta `static` yoksa metot statik değildir ve bir nesne üzerinden çağrılır. İlk yazılan geri dönüş türüdür; değer döndürmeyen metotlarda `void` yazılır. Sonra metodun adı ve parametreleri gelir. `final`, `static` gibi niteleyiciler en başa yazılır.

- **`compareTo`:** Statik değildir; bir `Integer` nesnesi üzerinden çağrılır. Nesne önce kendi ilkel değerine, sonra parametre olarak gelen `Integer`'ın değerine bakar. Kendisi küçükse negatif, büyükse pozitif, eşitse 0 döndürür. `String`'in `compareTo` metoduyla aynı mantıktadır.
- **`intValue`:** Nesnenin içindeki ilkel `int` değerini döndürür.
- **`parseInt`:** Statiktir. Metnin içinde bir tam sayı varsa onu döndürür. Yoksa exception fırlatır.
- **`toString()`:** Bir `Integer` nesnesinin değerini `String`'e çevirir. Statik `toString(int i)` ise bir ilkel tam sayıyı doğrudan `String`'e çevirir.
- **`valueOf(String s)`:** Statiktir. Metindeki sayının ilkel değil, sarmalayıcı (`Integer`) hâlini döndürür.

### 7.3 compareTo örneği ve deprecated üyeler

Slayttaki örnek (ekrandan, 01:10:00):

```java
Integer sarma1 = 1, sarma2 = 7;
//could use sarma1 = new Integer( 1 ); but that constructor is deprecated,
//i.e it will be removed from the language in a future version
System.out.println("Sonuç1:"+sarma1.compareTo(sarma2)); //-1
```

`sarma1` ve `sarma2`'ye sanki ilkelmiş gibi doğrudan değer atanmıştır. Derste çalıştırıldığında −1 alındı. Değerler yer değiştirince +1, ikisi eşit olunca 0 alındı (ekrandan, 01:20:00, konsolda `Sonuç1:0`).

**Deprecated** olarak işaretlenmiş bir constructor ya da metot artık kullanılmamalıdır. Bir mantık hatası ya da bazı özel durumlarda bug'a yol açan temel bir eksikliği vardır ve bu eksiklik düzeltilmeyecektir. Onun yerine başka metotlar, belki başka sınıfların metotları önerilir. Deprecated bir üye kullanılırsa derleyici uyarı (warning) verir ama derlemeye izin verir. Ancak bir JDK sürümünde deprecated ilan edilen üyelerin sonraki sürümde bulunacağının garantisi yoktur. Bugün uyarıyla derlenen kod sonraki sürümde hiç derlenmeyebilir. Bu kural üye alan, metot ve sınıf için geçerlidir. Eclipse deprecated üyelerin üstünü çizerek gösterir; `new Integer(1)` için "deprecated since version 9" uyarısı veriyor.

### 7.4 parseInt ve NumberFormatException

Hoca önce `parseInt`'i yanlışlıkla `Math` sınıfında aradı. Sohbetten gelen bir uyarı üzerine metodun `Integer` sınıfında olduğu düzeltildi. Kod (ekrandan, 01:20:00):

```java
package hafta03;

public class WrappersTests {

    public static void main(String[] args) {
        int sayi = Integer.parseInt("34");
        System.out.println(sayi);

    }

}
```

Bu kod 34 yazar. Metin `"A34"` yapılınca program şu exception ile durur:

```text
java.lang.NumberFormatException: For input string: "A34"
```

Sayı metnin başında ya da sonunda başka karakterlerle birlikte geçse de sonuç aynıdır. `parseInt` "içinden sayıyı ayıkla" diye çalışan bir metot değildir; metin gerçekten ve yalnız sayı içermelidir.

> **Hocanın vurgusu:** `parseInt`'in sayı olmayan metinde exception fırlattığını unutmayın.

Diğer ilkellerin sarmalayıcılarında da benzer metotlar vardır.

## 8. String sınıfının metotları

### 8.1 String bir sarmalayıcı değildir

`String`'i `char`'ın sarmalayıcısı gibi düşünmek doğru bir benzetme olmaz. `String`, başlı başına karakter katarlarını temsil eden bir sınıftır.

### 8.2 length, compareTo, compareToIgnoreCase ve yazdırma

Slayttaki metotlar (ekrandan, 01:15:00 ve 01:25:00):

- `int length()`: Metnin karakter sayısını döndürür.
- `int compareTo(String anotherString)`: Metodu çağrılan metni parametredeki metinle sözlük sıralamasına göre karşılaştırır. Sözlükte önce gelen küçük sayılır. Büyük/küçük harf farkı dikkate alınır.
- `int compareToIgnoreCase(String str)`: Aynı karşılaştırmayı büyük/küçük harf farkını gözetmeden yapar.
- `System.out.println(String)`; `print` ile `println` farkı: `println` yazdıktan sonra yeni satıra geçer, `print` geçmez.
- `printf` (C'deki gibi): C'deki biçim metinleriyle (format string) aynı şekilde kullanılır.

> **Ders sonrası not:** Hoca `printf`'in Java'ya "galiba altıncı sürümden itibaren" geldiğini söyledi. Büyük olasılıkla `printf` Java 5 (JDK 1.5) ile gelmiştir.

### 8.3 compareTo örneği: −19

Slayttaki örnek (ekrandan, 01:15:00):

```java
package nyp01c;
public class StringOps01 {
   public static void main( String args[] ) {
      String strA, strB;
      strA = "A string!";
      strB = "This is another one.";
      System.out.println(strA.compareTo(strB));
   }
}
```

Slayttaki cevap: "Output of the example: −19" (ekrandan, 01:25:00). `strA` önce kendi ilk karakterine, sonra `strB`'nin ilk karakterine bakar. Karşılaştırma ilk karakterden başlar. İlk karakterler zaten farklıdır ve 'A', 'T'den önce gelir. Bu yüzden `strA` küçüktür ve negatif bir sayı döner. Hoca −19'u, İngiliz alfabesinde A'dan T'ye 19 harf olmasıyla açıkladı. Derste çalıştırıldığında da −19 alındı.

(Ara adım eklendi: `compareTo` ilk farklı karakterlerin kod farkını döndürür: 'A' = 65, 'T' = 84, 65 − 84 = −19. Büyük harfler Unicode'da alfabe sırasıyla ardışık olduğu için bu örnekte harf farkı ile kod farkı aynıdır.)

Karşılaştırma İngiliz alfabesine, yani Unicode sırasına göre yapılır. Türkçe harfler bu sıranın çok ilerisindedir. Örneğin "ç" ile başlayan bir metin, "f" ile başlayan bir metinden büyük çıkar.

### 8.4 Büyük harf, küçük harf

Hoca, büyük/küçük harf farkını göstermek için örnekteki bir harfi küçük harf yaptı ve sonucun negatif çıktığını gördü. Buradan "küçük harfler önce geliyormuş" sonucunu çıkardı ve slayttaki `compareTo` satırının yanına "lowercase letters are smaller" notunu ekledi (ekrandan, 01:30:00).

> **Ders sonrası not:** Bu sonuç yanlıştır. Unicode ve onun öncülü ASCII'de büyük harfler küçük harflerden önce gelir: 'A' = 65, 'T' = 84, 'a' = 97, 't' = 116. Yani büyük harfler daha küçüktür. Örneğin `"A string!".compareTo("a string!")` = −32, `"a string!".compareTo("This is another one.")` = +13 olur (Java ile doğrulandı). Derste alınan negatif sonuç, büyük harfli metnin küçük harfli metinle karşılaştırılmasından kaynaklanmış olmalıdır. <!-- BELİRSİZ: Derste değiştirilen kodun tam hâli karelerde görünmüyor; hangi metnin hangi harfinin küçültüldüğü anlaşılamadı. -->

### 8.5 compareToIgnoreCase, equals ve equalsIgnoreCase

İçeriği aynı, yalnız büyük/küçük harfi farklı iki metin `compareToIgnoreCase` ile karşılaştırılınca 0 döner. Yalnız eşitlikle ilgileniliyorsa `compareTo` yapıp sonucun 0 olup olmadığına bakmak yerine `boolean equals(String anotherString)` ve `boolean equalsIgnoreCase(String anotherString)` metotları kullanılır. Derste büyük ve küçük "A" ile başlayan iki metin için `equalsIgnoreCase` `true`, `equals` ise `false` döndürdü.

### 8.6 Türkçe karakter sorunu

Türkçe sözlük sırasında "ç", "d"den önce gelir. Hoca `strA` = "çocuk", `strB` = "dede" yazıp `strA.compareTo(strB)` çağırdı. Türkçe düşünüldüğünde negatif sonuç beklenir ama 131 gibi pozitif bir sayı çıktı. Türkçede iki harf arasında bir harf fark varken Unicode sırasında arada 131 karakter vardır.

(Ara adım eklendi: 'ç' = 231, 'd' = 100, 231 − 100 = 131. Büyük harflerle 'Ç' = 199, 'D' = 68 için de fark 131'dir. Java ile doğrulandı.)

> **Ek bilgi (derste anlatılmadı):** Türkçe sözlük sırasına göre karşılaştırma için `java.text.Collator` sınıfı kullanılabilir: `Collator.getInstance(new Locale("tr", "TR")).compare(a, b)`. Bu sınıf karşılaştırmayı dilin kurallarına göre yapar.

### 8.7 contains, toUpperCase ve toLowerCase

`boolean contains(CharSequence s)`: Metodu çağrılan metin parametredeki metni içeriyorsa `true`, içermiyorsa `false` döndürür. Büyük/küçük harfe duyarlıdır. Hoca JDK 11 API belgelerinde `String` sınıfına baktı (ekrandan, 01:35:00). Belgede `contains` var ama `containsIgnoreCase` diye bir sürüm yok.

`toUpperCase()` ve `toLowerCase()` metotlarının önemli bir özelliği vardır: metodu çağrılan nesneyi gerçekten büyük ya da küçük harfe çevirmezler. Yalnız metnin çevrilmiş hâlini döndürürler. Daha teknik bir deyişle bu metotlar nesnenin durum bilgisini değiştirmez.

### 8.8 StringOps02 örneği

Hoca önce çıktıyı Not Defteri'nde tahmin etti, sonra programı çalıştırdı (ekrandan, 01:40:00):

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

Adım adım:

- "İstanbul", "Yıldız"ı içermez → `false`.
- `strB` = "tan" olur. "İstanbul" küçük harfli "tan"ı içerir → `true`.
- `strB.toUpperCase();` sonucu bir yere atanmadığı için `strB` değişmez. `strB` yazdırılınca `tan` çıkar.
- `strB` hâlâ "tan" olduğu için yine `true`.
- `strB = strB.toUpperCase();` ile dönen değer `strB`'ye atanır. Artık `strB` "TAN"dır ve yazdırılınca `TAN` çıkar.
- "İstanbul" büyük harfli "TAN"ı içermez → `false`.

Çıktı:

```text
false
true
tan
true
TAN
false
```

Tahmin edilen ve konsolda alınan çıktı aynıdır (Java 25 ile de aynı çıktı alındı).

### 8.9 Büyük/küçük harf duyarsız contains yazmak

`String` sınıfının kaynak kodu değiştirilemez. Kalıtımla `String`'den kendi sınıfımızı türetmek de bir yol olabilirdi, ama kalıtım henüz görülmedi. Bu yüzden `StringTests` adlı bir sınıfa statik bir metot yazıldı. Hoca `String` bir sarmalayıcı olmadığı için metodu `WrappersTests` sınıfına koymak istemedi. Fikir şudur: iki metin de aynı biçime (ikisi de büyük harf ya da ikisi de küçük harf) çevrilir, sonra `contains` çağrılır. Kod (ekrandan, 01:45:00):

```java
package hafta03;

public class StringTests {
    public static boolean containsIgnoreCase( String str1, String str2 ) {
        String str1Caps = str1.toUpperCase();
        String str2Caps = str2.toUpperCase();
        return str1Caps.contains(str2Caps);
    }
    public static boolean containsIgnoreCaseV2( String str1, String str2 ) {
        return str1.toUpperCase().contains(str2.toUpperCase());
    }
    ...
}
```

İlk sürüm ara değişkenlerle adım adım gider ve anlaşılırlığı yüksektir. İkinci sürüm işi tek satırda zincirleme çağrıyla yapar. Önce en içteki parantez değerlendirilir: `str2.toUpperCase()` yeni bir `String` döndürür. Sonra soldan sağa `str1.toUpperCase()` çalışır. Bu da bir `String` nesnesi döndürür ve o nesnenin `contains` metodu çağrılır. Hoca başlangıçta anlaşılırlığın önemli olduğunu söyledi: üç satır olması sorun değildir, zincirlemeye alıştıkça tek satır yazılabilir.

Derste `strA` = "İstanbul" ve `strB` = "TAN" ile iki metot da `true` döndürdü.

## 9. Math sınıfı

`Math` sınıfında yaygın matematik işlemleri için statik metotlar vardır (ekrandan, 01:50:00):

- **`public static double Math.random()`:** Parametre almaz. [0.0, 1.0) aralığında pozitif bir `double` döndürür: 0.0 dahil, 1.0 hariç. Daha karmaşık rastgele sayı işlemleri ve farklı aralıklar için hazır metotlar da vardır. Ama [0, 1) aralığındaki bir sayıyı istenen aralığa genişletmek kolaydır: aralık 0 ile n arasındaysa sonuç n ile çarpılır.
- **`public static <primitive> Math.abs(<primitive> a)`:** Mutlak değeri döndürür. `<primitive>` yerine her sayısal ilkel tür gelebilir, örneğin `public static double Math.abs(double a)`. Java kuvvetli tiplemeli bir dil olduğundan, parametre türleri farklı adaş metotlar yazılabilir. Her ilkel tür için aslında farklı bir `abs` metodu çağrılır.
- **`Math.max(<primitive> a, b)`** ve **`Math.min(<primitive> a, b)`:** Aynı türden iki değerden büyüğünü ya da küçüğünü döndürür.
- **`round`:** Bildiğimiz yuvarlama. Ondalık kısım 0,5 ve üstüyse yukarı, altındaysa aşağı yuvarlar.
- **`ceil`** (ceiling'in kısaltması): Ondalık kısım ne olursa olsun yukarı (tavana) yuvarlar.
- **`floor`:** Her zaman aşağı (tabana) yuvarlar; örneğin 3,9'u 3'e indirir.
- **`sqrt`:** Karekök alır.

Belgelerde daha birçok metot vardır.

(Java ile denendi: `Math.round(3.5)` = 4, `Math.round(3.4)` = 3, `Math.ceil(3.1)` = 4.0, `Math.floor(3.9)` = 3.0, `Math.sqrt(16)` = 4.0.)

## 10. Rastgele sayılar ve Random sınıfı

### 10.1 Sözde rastgele sayı üreteçleri

Slayttaki bilgi (ekrandan, 01:55:00):

- Bütün bilgisayar sistemleri sözde rastgele sayı üreteçlerine (pseudo-random number generators) dayanır. Java'da bu `java.util.Random` sınıfıyla modellenir.
- `Math.random()` doğrudan kullanılırsa JRE kendiliğinden bir `Random` nesnesi oluşturur ve JVM'nin bütün ömrü boyunca onu kullanır.
- `Random` sınıfının, istenen ilkel türde rastgele değer üreten statik olmayan yararlı metotları vardır.

Rastgele sayı üretmek için önce bir çekirdek (seed) değerle üreteç ilklendirilir. Aynı çekirdekten üretilen sayılar hep aynı sırada gelir. Bu bir sakınca değilse `Math.random()` yeterlidir. Ama örneğin kriptografi programlarında çekirdeğin farklı değerlerle yeniden ilklendirilmesi gerekebilir. O zaman birden çok `Random` nesnesi oluşturulup sayılar farklı nesnelerden istenebilir. `Math` sınıfı `java.lang`'tadır ve import gerektirmez. `Random` ise `java.util`'den import edilir.

### 10.2 Random'un metotları

Bu metotların hiçbiri statik değildir. Önce bir `Random` nesnesi oluşturulur, sonra çağrılar o nesneye yapılır (ekrandan, 01:55:00):

| Metot | Döndürdüğü |
|---|---|
| `public boolean nextBoolean( )` | [false, true] |
| `public double nextDouble( )` | [0.0, 1.0) |
| `public float nextFloat ( )` | [0.0, 1.0) |
| `public int nextInt( )` | slayta göre (−2^32, 2^32) |
| `public int nextInt( int bound )` | [0, bound) |
| `public long nextLong( )` | slayta göre [0, 2^48) |

`nextInt(int bound)`, üst sınırı parametre olarak alan adaş sürümdür ve üst sınır hariçtir.

> **Ders sonrası not:** Hoca slayttaki aralıkları okurken "32 bit" ve "2 bayt" dedi. `int` 4 bayt, yani 32 bittir. `nextInt()` bütün `int` aralığını kapsar: slayttaki (−2^32, 2^32) değil, [−2^31, 2^31 − 1], yani −2.147.483.648 … 2.147.483.647. `nextLong()` için slayttaki [0, 2^48) de doğru değildir: metot negatif değerler de döndürür (denemede 1000 çağrının yaklaşık yarısı negatif çıktı). Ancak `Random` 48 bitlik bir çekirdek kullandığı için bütün `long` değerlerini üretemez.

### 10.3 Çakıl taşı ve parmak örneği

Hoca `RandomOps` örneğini anlattı. Önce `java.util` paketi import edilir ve bir `Random` nesnesi oluşturulur. Üreteç, sistemin belirlediği bir çekirdekle ilklendirilir.

- **Çakıl taşı sayısı:** Kaç çakıl taşı toplandığı 0 da olabilir, herhangi bir n de. Bu yüzden üst sınırsız `nextInt()` kullanılır. Ama bu metot negatif sayı da döndürebileceği için sonucun mutlak değeri (`Math.abs`) alınır. Böylece "negatif sayıda taşım var" denmez. Derste 600 milyonu aşan bir sayı çıktı; bu `int` sınırının içindedir.
- **Boyanan parmak sayısı:** Sonuç 0 ile 10 arasında olmalıdır. Bu yüzden üst sınır alan `nextInt` sürümü kullanılır. Üst sınırın hariç olduğu unutulmamalıdır.

<!-- BELİRSİZ: Parmak örneğinde kullanılan üst sınır ve "on parmağımı boyadım" diye okunan çıktı karelerde görünmüyor. Üst sınır 10 ise nextInt(10) yalnız 0-9 arasında değer üretir (Java ile 1.000.000 denemede en büyük değer 9 çıktı); 10 da gerekiyorsa nextInt(11) kullanılmalıdır. -->

Hoca İngilizce dilbilgisine de değindi: "1 fingers" ya da "0 fingers" yazılmaz. Sınırlı rastgele sayıyı doğrudan kullanmadan önce bir if-else-if zinciriyle "0 ise hiçbirini boyamadım, 1 ise bir parmağımı boyadım, 2 ve üstüyse fingers, değilse finger" gibi bir ayrım yapılabilir (`RandomOps2` örneği).

> **Ek bilgi (derste anlatılmadı):** `Math.abs(Integer.MIN_VALUE)` yine `Integer.MIN_VALUE`, yani negatif bir sayı döner, çünkü +2.147.483.648 `int` aralığına sığmaz. `Math.abs(r.nextInt())` bu yüzden çok küçük bir olasılıkla negatif sonuç verebilir. Kesin negatif olmayan değer gerekiyorsa `r.nextInt(Integer.MAX_VALUE)` gibi sınırlı sürüm kullanılabilir.

## 11. Komut satırından girdi ve çıktı: Scanner

### 11.1 Çıktı: System.out

Slayttaki bilgi (ekrandan, 02:15:00):

- `System` sınıfının `out` üyesi `public` ve `static`'tir. Bu yüzden `out` nesnesi doğrudan (`System.out` diye) kullanılabilir.
- Komut satırı çıktısı için metotlar: `println`, `print` (bunlar görüldü) ve C programcılarının bildiği şekilde kullanılan `printf`.

### 11.2 Girdi: neden Scanner?

Şimdiye kadar değerler hep kodun içine elle yazıldı. Şimdi kullanıcıdan komut satırından nasıl bilgi alınacağı görülecek.

Java komut satırını, disk dosyasını ve ağ bağlantısını aynı şekilde, birer girdi/çıktı kaynağı olarak ele alır ve hepsini akışlar (stream) üzerinden kullandırır. Ama akışları kullanmak için akış mantığını ve exception handling'i bilmek gerekir. Girdi/çıktı işlemlerinde ters gidebilecek çok şey vardır. Yeni başlayan biri tek satır bilgi almak için bunları ezberlemek zorunda kalıyordu. JDK 5.0'dan itibaren `java.util` paketine eklenen `Scanner` sınıfı bu karmaşıklığı bizden soyutlar.

Slayttaki bilgi (ekrandan, 02:20:00):

- Girdi işlemleri `java.util.Scanner` sınıfıyla yapılır (JDK 5.0 ve sonrası).
- İlklendirme: `Scanner in = new Scanner(System.in);`
- `System.in`, `java.io.InputStream` türünden `public static` bir üyedir.
- Girdi metotları (her seferinde bir öğe): `String nextLine()`, `int nextInt()`, `float nextFloat()` … Bir ilkel için `next` + türün adı (camel case ile ilk harfi büyük) yazılır: `nextInt`, `nextFloat`, `nextDouble` gibi.

### 11.3 ConsoleIOv1 örneği

Slayttaki kod (ekrandan, 02:20:00):

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

Açıklamalar:

- `Scanner` kullanılacağı için `java.util.Scanner` import edilir.
- Scanner nesnesinin adının `in` olması şart değildir; `input` ya da `gir` de olabilir.
- Soru `println` ile değil `print` ile sorulur. `println` ile sorulsaydı cevap bir alt satıra yazılırdı. Konsolda (IDE'de de komut satırında da) satır sayısı kısıtlı, sütun sayısı geniştir. Bu yüzden hoca kullanıcıya soru sorarken her zaman `print` kullanıyor.
- Ad `nextLine()` ile `String` olarak, yaş `nextInt()` ile `int` olarak alınır.
- **`+` operatörü aşırı yüklüdür.** Metotlarda olduğu gibi operatörlerde de aşırı yükleme yapılabilir. `+` işlenenlerinden biri bile `String` ise iki metni yan yana yapıştırır (birleştirme). İki tarafı da sayısal değerse normal toplama yapar. Bu yüzden `(age + 1)` parantezi önemlidir. Parantez olmazsa önce yaş metne eklenir, sonra 1 metne eklenir ve toplama yapılmaz.
- Program sonunda Scanner nesnesi `close()` ile kapatılır. Kapatılmazsa Eclipse "Resource leak: 'in' is never closed" uyarısı verir. Kapatılmasa da JVM kapanınca kaynaklar güvenle bırakılır, hoca bu yüzden bir sorun yaşamadığını söyledi. Ama kural böyle konduğu için kapatma yapılmalıdır.

> **Hocanın vurgusu:** Scanner nesnesini `close()` ile kapatmayı unutmayın.

> **Ders sonrası not:** Hoca kapatılmayan Scanner uyarısının "JDK'nın altıncı sürümüyle" geldiğini söyledi. Bu uyarı büyük olasılıkla JDK'nın derleyicisinden (javac) değil, Eclipse'in kendi derleyicisinin kaynak sızıntısı denetiminden gelmektedir.

Çalıştırma (ekrandan, 02:25:00; girilen ad burada `<ad>` olarak gösterildi):

```text
What is your name? <ad>
How old are you? 45
Hello, <ad>. Next year, you'll be 46.
```

Parantez kaldırılsaydı çıktı "... Next year, you'll be 451." olurdu. (İki durum da Java 25 ile denendi: parantezli 46, parantezsiz 451.)

### 11.4 nextInt'ten sonra nextLine: boş satır sorunu

Hoca okuma sırasını değiştirdi: önce yaş (`nextInt`), sonra ad (`nextLine`) okundu. Yaş girilip Enter'a basılınca program adı sormadan bir sonraki komuta geçti. Ad boş alındı; `null` bile değildi, çıktıda "Hello," ile "." arasında hiçbir şey yazmadı.

Hoca bunu Scanner sınıfında JDK 5'ten beri düzeltilmemiş bir bug olarak anlattı. Sorun, ilkel değer okunduktan sonra `String` okunacağı zaman çıkar. İlkelleri arka arkaya okumakta sorun yoktur. Çözüm, `String` okumadan önce Scanner nesnesine fazladan, boş bir `nextLine()` komutu vermektir. Bu yapılınca ad da düzgün okundu. Hoca, düzeltilmemesinin nedeni olarak Scanner'ın kullandığı eski bir kod kitaplığını gösterdi: düzeltme başka yerlerde daha önemli hatalara yol açacakmış. Ayrıca artık uygulamalarda kullanıcıdan bilgi komut satırından değil, GUI bileşenlerinden ya da servisler üzerinden alınıyor.

> **Ders sonrası not:** Bu durum aslında bir bug değil, belgelenmiş bir davranıştır. `nextInt()` yalnız sayıyı okur, Enter'ın ürettiği satır sonu karakterini girdi tamponunda bırakır. Hemen ardından çağrılan `nextLine()` o satır sonuna kadar olan boş metni okur ve döner. Derste gösterilen çözüm (araya fazladan bir `nextLine()` koymak) doğrudur. Her satırı `nextLine()` ile okuyup `Integer.parseInt` ile çevirmek de bir yoldur.

(Java 25 ile denendi: girdi "45" ve bir ad için fazladan `nextLine()` yokken çıktı `Hello, . Next year, you'll be 46.`, varken `Hello, <ad>. Next year, you'll be 46.` oldu.)

## 12. Kullanıcıdan bilgi alarak Car nesnesi oluşturmak

### 12.1 Tek alanlı Car

Son örnekte UML şemasında şasi numarası olmayan `Car` sınıfı kullanıldı; `main` metodu sınıfın kendi içinde. Soru şudur: plaka kullanıcıdan istenerek bir `Car` nesnesi oluşturulsun. Slayttaki çözüm (ekrandan, 02:30:00):

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

UML şemasında: `- plate : String`, `+ Car( plateNr : String )`, `+ getPlate( ) : String`, `+ setPlate( String )`, `+ introduceSelf( )`, `+ main( String[] )`.

`java.util` paketi import edilir (`java.util.*`). Scanner nesnesinin adı burada `input`'tur. Plaka bir ara değişkene atanmadan doğrudan constructor'a verilir: `new Car( input.nextLine() )`. Constructor tek parametre aldığı için bu mümkündür. En sonda `input.close()` unutulmaz. Çalıştırma (ekrandan, 02:35:00):

```text
Enter a license plate: 34 RA 440
My plate: 34 RA 440
```

(Java 25 ile aynı girdiyle aynı çıktı alındı.)

### 12.2 İki parametreli Car ile sürüm

Constructor'ın şasi numarasını da istediği sürümde iki değer ayrı ayrı alınmalıdır. Önce "plaka numarasını girin" denir ve plaka bir `String` değişkene atanır. Sonra "şasi numarasını girin" denir ve o da başka bir `String` değişkene atanır. Sonra iki değişken constructor'a verilir: `new Car(plate, chassis)`. Hoca bunu `nyp01b` paketinde `MainProgramV2` adıyla yazdı. Önceki `main` kodu kopyalanınca Eclipse başka paketteki `Car` sınıfını import etmeye çalıştı; bu import satırı silindi.

Hoca bir Eclipse kısayolu da gösterdi: Ctrl tuşu basılıyken bir metodun (örneğin `introduceSelf`) üstüne tıklanırsa Eclipse o metodun tanımlandığı yeri açar. Bu yolla çağrının `nyp01b` paketindeki `Car` sınıfına gittiği doğrulandı. Bu sınıfın `introduceSelf` metodu (ekrandan, 02:35:00):

```java
public void introduceSelf( ) {
    System.out.print( "My plate is " + getPlate()
        + " and my chassis nr is " + getChassisNR() );
}
```

Program çalıştırılınca plaka ve şasi numarası girildi ve araç kendini her iki bilgiyle düzgün biçimde tanıttı. <!-- BELİRSİZ: Bu çalıştırmada girilen şasi numarası karelerde görünmüyor. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:08:18; slayt: ekrandan, 00:10:00): `Car` sınıfının `plate` ve `chassisNR` alanları için iki ayrı tek parametreli constructor (`Car(String plateNr)` ve `Car(String chassisNR)`) tanımlamak doğru olur mu?

> **Çözüm (derste verildi):** Hayır. Kod derlenmez, çünkü iki constructor'ın imzası aynıdır (`Car(String)`). Parametre türleri farklı olsaydı derlenirdi, ama mantık hatası sürerdi: hangi constructor çağrılırsa öteki alan boş kalır; ikinci constructor'ı çağırmak yeni bir nesne oluşturur, ilk nesne kaybolur. Doğrusu iki alanı da aynı constructor'da `Car(String plateNr, String chassisNR)` olarak almaktır.

**Soru 2** (derste sözlü, 00:28:13): Tek constructor daha kolaysa, birden çok constructor tanımlamanın işe yaradığı bir durum var mı?

> **Çözüm (derste verildi):** Şasi numarası fabrikada verilen ve değişmeyen (`final`) bir alan, plaka ise sonradan atanabilen bir alan olsun. Araç bazen yalnız şasi numarasıyla, bazen plakasıyla birlikte teslim edilir. Bu durumda `Car(String plate, String chassisNR)` ve `Car(String chassisNR)` birlikte mantıklıdır. Plaka için `setPlate` de eklenmelidir.

**Soru 3** (ekrandan, 00:45:00): Bir n tam sayısının sağdan 4. bitini nasıl bulursunuz?

> **Çözüm (derste verildi):** `(n & 8) / 8` ya da `(n & (1 << 3)) >> 3`. 8 = 2^3 = 00001000 maskesi, n'nin yalnız 4. bitini bırakır. Sonuç 8 ya da 0'dır; 8'e bölünür ya da 3 bit sağa kaydırılır ve 1 ya da 0 elde edilir. Derste n = 10110101 için sonuç 0'dır.

**Soru 4** (ekrandan, 01:15:00): `StringOps01` programının çıktısı nedir?

```java
String strA, strB;
strA = "A string!";
strB = "This is another one.";
System.out.println(strA.compareTo(strB));
```

> **Çözüm (derste verildi, ekrandan 01:25:00):** −19. İlk karakterler 'A' (65) ve 'T' (84) farklıdır; `compareTo` farkı döndürür: 65 − 84 = −19. `strA` sözlükte önce geldiği için sonuç negatiftir.

**Soru 5** (ekrandan, 01:36:48 civarı; kod: ekrandan, 01:40:00): `toUpperCase` ve `toLowerCase` nesnenin durumunu değiştirmez. Buna göre `StringOps02` programının çıktısı ne olur? (Kod 8.8'dedir.)

> **Çözüm (derste verildi):** `false`, `true`, `tan`, `true`, `TAN`, `false`. `strB.toUpperCase();` tek başına `strB`'yi değiştirmez. Değişiklik ancak `strB = strB.toUpperCase();` ataması ile olur; o zaman "İstanbul" "TAN"ı içermez.

**Soru 6** (derste sözlü, 01:36:04): `String` sınıfında `containsIgnoreCase` yoktur. Büyük/küçük harf duyarsız bir `contains` nasıl yazılır?

> **Çözüm (derste verildi, ekrandan 01:45:00):** İki metin de aynı biçime çevrilip `contains` çağrılır: `public static boolean containsIgnoreCase(String str1, String str2) { return str1.toUpperCase().contains(str2.toUpperCase()); }`. "İstanbul" ve "TAN" için `true` döner.

**Soru 7** (derste sözlü, 02:20:26; kod: ekrandan, 02:20:00): `ConsoleIOv1` programında `(age + 1)` ifadesindeki parantezler kaldırılırsa ve yaş olarak 45 girilirse çıktının son kısmı ne olur?

> **Çözüm (derste verildi):** "Next year, you'll be 451." `+` işlenenlerinden biri `String` olduğu için soldan sağa birleştirme yapılır: önce 45, sonra 1 metne eklenir. Parantezle önce `age + 1` = 46 hesaplanır.

**Soru 8** (ekrandan, 02:30:00): Plakası kullanıcıdan istenerek bir `Car` nesnesi oluşturan ve nesnenin kendini tanıtmasını sağlayan `main` metodunu yazın (UML: `- plate : String`, `+ Car(plateNr : String)`, `+ getPlate() : String`, `+ setPlate(String)`, `+ introduceSelf()`, `+ main(String[])`).

> **Çözüm (derste verildi):** Kod 12.1'dedir: `Scanner input = new Scanner(System.in); System.out.print("Enter a license plate: "); aCar = new Car(input.nextLine()); aCar.introduceSelf(); input.close();`. Girdi "34 RA 440" için çıktı `My plate: 34 RA 440` olur.

## Dersin Toparlaması

Bu derste önce constructor tasarımı üzerinde duruldu. Bir nesnenin mutlaka sahip olması gereken alanlar tek bir constructor'da ilklendirilmelidir. Alanları ayrı constructor'lara bölmek ya aynı imza yüzünden derleme hatası verir ya da gizli bir mantık hatası üretir: ikinci constructor çağrısı yeni bir nesne yaratır ve `final` alanlar ilklendirilmeden kalır. Aynı adlı, farklı parametreli metotlar adaş metotlardır (overloading). Birden çok constructor, her biri mantıklı bir senaryoya karşılık geliyorsa tanımlanır.

Ardından Java'nın ilkel türleri (`int`, `long`, `short`, `byte`, `double`, `float`, `char`, `boolean`), sarmalayıcıları ve ilkellerle yapılan aritmetik ve bit işlemleri hatırlatıldı. `Integer` (`compareTo`, `parseInt`, `valueOf` …), `String` (`compareTo`, `equals`, `contains`, `toUpperCase` …), `Math` ve `Random` sınıflarının yararlı metotları örneklerle denendi. `String` metotlarının nesnenin durumunu değiştirmediği, `parseInt`'in exception fırlatabildiği ve deprecated üyelerden kaçınılması gerektiği vurgulandı. Son olarak `Scanner` ile komut satırından girdi alma, `+` operatörünün aşırı yüklenmesi, `nextInt` sonrası `nextLine` sorunu ve Scanner'ı kapatma gösterildi. Bu bilgiler kullanıcıdan alınan plakayla `Car` nesnesi oluşturan bir programda birleştirildi. Hoca sonraki konuların denetim akışı, değerle/başvuruyla parametre aktarımı ve ardından nesneler arası ilişkiler, kalıtım ve çok biçimlilik olacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
