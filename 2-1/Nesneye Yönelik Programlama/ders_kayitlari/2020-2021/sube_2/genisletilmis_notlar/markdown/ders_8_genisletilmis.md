# Ders 8 Genişletilmiş Notu: Metot Parametre Aktarımı ve Nesneler Arası İlişkiler: Association, Dependency, Tek Yönlü Sahiplik ve Sıralama Şeması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Java'da Metot Parametre Aktarımı
- 2. İlkeller, Sarmalayıcılar ve Takas: MethodParametersTest1
- 3. Yerel Değişken Kapsamı ve static Metotlar
- 4. Dizilerin Aktarımı: MethodParametersTest3
- 5. Araba Nesneleriyle Aktarım: Durum Değişikliği ve Referans Değişikliği
- 6. Yapısal Programlama Tekrarı
- 7. Nesneler Arası İlişkilere Giriş
- 8. Association (Sahiplik)
- 9. Dependency (Bağımlılık) ve Gizli Bilgi
- 10. Tek Yönlü Association: Person ve Car
- 11. Sıralama Şeması (Sequence Diagram)
- 12. Sahip Olunan Nesneye İş Yaptırmak: changeCarPlate
- Örnek Sorular
- Dersin Toparlaması

## 1. Java'da Metot Parametre Aktarımı

Ders, bir önceki derste değinilen metot parametreleri konusunun asıl kısmıyla açıldı: metoda ilkel bir değer ya da bir nesne verildiğinde ne olur? Hoca önce C'den ve programlama dilleri dersinden bilinen iki temel mekanizmayı hatırlattı.

- **Değerle çağırma (call by value):** Parametre fonksiyona aktarıldığında fonksiyonun içinde değerine yapılan değişiklik, fonksiyon bitip geri dönüldükten sonra kalıcı olmaz. Aktarılan değişken eski değerini korur.
- **Referansla çağırma (call by reference):** C'de işaretçi (pointer) üzerinden aktarılırsa fonksiyonun içinde yapılan değişiklik kalıcı olur. Fonksiyon bitince parametrenin son değeri, eşleştirilen değişkende kalır.

Java bu ikisinin bir birleşimini kullanır ve buna **call by value of references** (referansların değerle aktarımı) denir. Pratikte kural şöyledir:

- İlkel türler (`int`, `double` vb.) için Java'da her zaman değerle çağırma geçerlidir. Çağrılan metotta parametreye ne yapılırsa yapılsın, metot bitince çağıran taraftaki değişken eski değerine döner.
- İlkel olmayan (non-primitive) bir nesne metoda verildiğinde çoğu zaman referansla çağırma gibi çalışır: çağrılan metotta nesnenin durumunda yapılan değişikliklerin hepsi kalıcıdır.
- İstisna: çağrılan metodun içinde parametreyi `new` ile yeniden ilklendiremezsiniz ya da başka bir nesneyi göstermesini sağlayamazsınız. Böyle bir değişiklik çağıran tarafa yansımaz.

Kısacası nesnelerde yapılan durum değişikliği kalıcıdır, ama mekanizma referansın başka bir yere yönlendirilmesini engeller. Çünkü metoda referansın kendisi değil, değeri (kopyası) aktarılır.

## 2. İlkeller, Sarmalayıcılar ve Takas: MethodParametersTest1

### 2.1 Sınıfın yapısı

Hoca bu kuralları sınamak için `nyp01e` paketindeki `MethodParametersTest1` sınıfını gösterdi (ekrandan, 00:10:00). Sınıfın iki `Integer` sarmalayıcı (wrapper) üye alanı vardır; sarmalayıcılar bir önceki derste görülmüştü. Burada ilkellerin yanında nesnelere de ihtiyaç olduğu için kullanılırlar.

- `ilkelDuzenle(int x)`: ilkel bir `int` alır ve bir artırır.
- `sarmalayiciDuzenle(Integer x)`: bir `Integer` nesnesi alır ve bir artırır.
- `ilkelDegistir(int x, int y)`: iki ilkeli takas etmeye (swap) çalışır.
- `sarmalayiciDegistir(Integer x, Integer y)`: aynı takası iki nesneyle dener.
- `sarmalayiciDegistirAlt(Integer x, Integer y)`: takası doğrudan atama yerine `new Integer(...)` ile, yani ilklendirerek dener.
- `swapForReal()`: parametre almaz, nesnenin kendi `wrapI` ve `wrapJ` üye alanlarını takas eder. Hoca bu metodu, parametre aktarımı dışında bir nesnenin kendi üye alanları üzerinde istediği her tasarrufu yapabileceğini göstermek için koyduğunu söyledi.
- `main`: bir nesne oluşturup `tryMe()` metodunu çağırır. `tryMe` her metodu çağırmadan önce ve sonra değerleri yazdırır.

Aşağıdaki kod karelerdeki sınıf ile `tryMe` metodunun birleşimidir. `tryMe` gövdesinin ilk kısmı ekrandan alınmıştır (ekrandan, 00:25:00); son iki takasın yer aldığı kısım karelerde görünmediği için çıktıya ve anlatıma göre tamamlandı (ara adım eklendi). Kod Java 25 ile `java MethodParametersTest1.java` biçiminde çalıştırıldı ve ekrandaki çıktının aynısını verdi.

```java
package nyp01e;

@SuppressWarnings("all")
public class MethodParametersTest1 {
    private Integer wrapI, wrapJ;
    public void ilkelDuzenle( int x ) { x++; }
    public void sarmalayiciDuzenle( Integer x ) { x++; }
    public void ilkelDegistir( int x, int y ) {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }
    public void sarmalayiciDegistir( Integer x, Integer y ) {
        Integer temp; temp = x; x = y; y = temp;
    }
    public void sarmalayiciDegistirAlt(Integer x, Integer y) {
        Integer temp;
        temp = new Integer(x);
        x = new Integer(y);
        y = new Integer(temp);
    }
    public void swapForReal( ) {
        Integer temp = wrapI;
        wrapI = wrapJ;
        wrapJ = temp;
    }
    public void tryMe() {
        int count = 3;
        System.out.println("Before : " + count );
        this.ilkelDuzenle(count);
        System.out.println("After: " + count );

        Integer wrap = 5;
        System.out.println("Before : " + wrap );
        this.sarmalayiciDuzenle(wrap);
        System.out.println("After: " + wrap );

        int count1 = 1, count2 = 2;
        System.out.println("Before : " + count1 + ", " + count2 );
        this.ilkelDegistir(count1, count2);
        System.out.println("After: " + count1 + ", " + count2 );

        Integer wrap1 = 1;
        Integer wrap2 = 2;
        System.out.println("Before : " + wrap1 + ", " + wrap2 );
        this.sarmalayiciDegistir(wrap1, wrap2);
        System.out.println("After: " + wrap1 + ", " + wrap2 );
        // Bu noktadan sonrası çıktıya göre tamamlandı
        System.out.println("Before : " + wrap1 + ", " + wrap2 );
        this.sarmalayiciDegistirAlt(wrap1, wrap2);
        System.out.println("After: " + wrap1 + ", " + wrap2 );

        wrapI = 3; wrapJ = 5;
        System.out.println("Before : " + wrapI + ", " + wrapJ );
        this.swapForReal();
        System.out.println("After: " + wrapI + ", " + wrapJ );
    }
    public static void main(String[] args) {
        MethodParametersTest1 test = new MethodParametersTest1();
        test.tryMe();
    }
}
```

> **Ders sonrası not:** Slayttaki `main` metodunda `MethodParameters test = new MethodParameters();` yazıyor (ekrandan, 00:10:00). Eclipse'teki çalışan kodda doğru sınıf adı `MethodParametersTest1` kullanılmıştır (ekrandan, 00:25:00).

### 2.2 Çıktının yorumu

Çıktı slayttakiyle aynıdır (ekrandan, 00:30:00):

```text
Before : 3
After: 3
Before : 5
After: 5
Before : 1, 2
After: 1, 2
Before : 1, 2
After: 1, 2
Before : 1, 2
After: 1, 2
Before : 3, 5
After: 5, 3
```

Hoca satırları tek tek yorumladı:

- **3 → 3:** `ilkelDuzenle` değeri bir artırır. Metodun içinde değer yazdırılsaydı 4 görülürdü, ama değişiklik yalnız metot içinde geçerlidir. Değerle çağırma yüzünden `tryMe`'ye dönüldüğünde değer yine 3'tür.
- **5 → 5:** Sarmalayıcılar nesne olmasına rağmen bu tür basit işleçlerle yapılan işlemde değişiklik kalıcı olmaz. Sarmalayıcı yerine başka bir nesne verilip durumu değiştirilseydi değişiklik kalıcı olurdu (bu, 5. bölümdeki araba örneğinde gösterildi).
- **1, 2 → 1, 2 (üç kez):** İlkellerle takas, sarmalayıcılarla takas ve `new Integer(...)` ile ilklendirerek takas denemelerinin hiçbiri kalıcı olmaz.
- **3, 5 → 5, 3:** Yalnız nesnenin kendi üye alanları olan `wrapI` ve `wrapJ` gerçekten takas edilir. Bir nesne kendi üyeleri üzerinde her türlü değişikliği yapabilir.

> **Ek bilgi (derste anlatılmadı):** `Integer` değişmez (immutable) bir sınıftır. `x++` yazıldığında mevcut nesne değişmez; otomatik kutu açma ve kutulama (unboxing/autoboxing) ile yeni bir `Integer` oluşturulup yerel parametre değişkenine atanır. Bu da aslında parametrenin başka bir nesneyi göstermesidir ve bu yüzden çağıran tarafa yansımaz.

> **Ders sonrası not:** Hoca çalıştırmadan önce (00:12:16) `sarmalayiciDuzenle` değişikliğinin kalıcı olacağını söyledi, çalıştırınca çıktının 5 → 5 olduğunu görüp sarmalayıcıların bu durumda ilkel gibi davrandığını belirtti. Doğrusu çıktıda görülen davranıştır.

### 2.3 Eskimiş (deprecated) metotlar

Eclipse'te 19, 20 ve 21. satırlardaki `Integer` kurucuları üstü çizili görünür (ekrandan, 00:15:00). Bu, sarmalayıcıya kurucuyla değer atamanın **deprecated** (eskimiş) olduğunu gösterir. Düzgün çalışma ya da performans sorunları nedeniyle artık kullanılması önerilmeyen ve yerine başka mekanizmalar verilmiş metotlar böyle işaretlenir. Bu sürümde hâlâ çalışırlar, ama JDK'nın sonraki bir sürümünde hiç olmayabilirler; o zaman bu satırlar derleme hatası verir. Bu yüzden bu metotlardan yavaş yavaş vazgeçmek gerekir.

> **Ders sonrası not:** Hoca JDK 17'de bu kurucuların kaldırılabileceğini örnek olarak söyledi. Not hazırlanırken kod Java 25 ile çalıştırıldı; `new Integer(int)` hâlâ derleniyor, yalnız deprecation uyarısı veriyor.

## 3. Yerel Değişken Kapsamı ve static Metotlar

### 3.1 MethodParametersTest2: metodun kendi içinde değişiklik

`MethodParametersTest2`'de aynı işlemler parametre aktarmadan, `tryMe` metodunun içinde tanımlanan yerel değişkenler üzerinde yapılır (`x` 1, `y` 2 vb.). Bu durumda değişiklikler gerçekten geçerlidir: çıktı `Before : 1, 2`, `After: 2, 1`, `Before : 3, 5`, `After: 5, 3` olur (ekrandan, 00:25:00). Hem ilkellerde hem sarmalayıcılarda, metodun kendi içinde yapılan değişiklikler yürür.

Ama bu `x` ve `y` yalnız `tryMe` içinde geçerlidir. Hoca aynı sınıfa `public void test()` diye bir metot ekleyip içine `x++` yazınca Eclipse böyle bir değişkenin tanımlı olmadığını söyledi. Bir metodun içinde tanımlanan değişkenin kapsamı (scope, etki alanı, görülebilirliği) o metotla sınırlıdır. Başka metotta aynı adla yeniden tanımlanırsa iki ayrı değişken olur.

Hoca, 1. ve 2. örnekleri birlikte değerlendirerek şunu vurguladı: değişiklikler yalnız çağrılan metotla sınırlı kalır. Çağrılan metot sona erince parametre olarak gelen ilkel ya da nesnelerle ilgili bütün değişiklikler buharlaşır, her şey eski haline döner.

### 3.2 static metotlar ve üye alanlara erişim

Hoca, bu geçicilik davranışının metotların normal ya da `static` olmasıyla ilgisi olmadığını göstermek için `tryMe` içeriğini `main` metoduna taşıdığı bir `MethodParametersTest1b` sürümü hazırladı. Bunun için diğer metotları da `static` yapmak gerekti. Bu sırada bir derleme hatası çıktı: `static` bir metot içinden normal bir üye alana erişilmeye çalışılıyordu.

Hatanın nedeni şöyle açıklandı. `static` metotlar nesneden bağımsız olarak, sınıf üzerinden erişilen metotlardır. `static` bir metodun içinden `wrapI` gibi normal bir üye alana erişmeye çalışınca hangi nesnenin üye alanına erişildiği belli değildir. Metot bir nesne üzerinden çağrılmadığı için `this` de yazılamaz; `static` metot içinde `this` işaretçisi anlamsızdır. Bu yüzden:

- `static` metot içinde doğrudan erişilebilen üyeler de `static` olmalıdır,
- ya da `static` metot içinde o sınıf türünden bir nesne oluşturulup o nesnenin normal üyelerine erişilir (`main` içinde `new MethodParametersTest1()` yapılması gibi).

Hoca sonunda `wrapI` ve `wrapJ` üye alanlarını da `static` yaptı ve `static` metotları sınıf adı üzerinden çağırdı. Çıktı değişmedi (ekrandan, 00:30:00): yine yalnız üye alanlar üzerindeki takas kalıcı oldu.

## 4. Dizilerin Aktarımı: MethodParametersTest3

Hoca ardından dizilerin durumunu gösterdi (ekrandan, 00:35:00):

```java
package nyp01e;

public class MethodParametersTest3 {
    public static void main(String[] args) {
        int[] dizi = { 1, 2, 3, 4, 5 };
        LowHighSwap.doIt( dizi );
        for( int j = 0; j < dizi.length; j++ )
            System.out.print( dizi[j] + " " );
    }

}

class LowHighSwap {
    static void doIt( int[] z ) {
        int temp = z[ z.length - 1 ];
        z[ z.length - 1 ] = z[ 0 ];
        z[ 0 ] = temp;
    }
}
```

`doIt` dizinin son elemanıyla ilk elemanının yerini değiştirir. Çıktı `5 2 3 4 1` olur (ekrandan, 00:40:00; kod Java 25 ile çalıştırılıp doğrulandı). Yani dizide yapılan değişiklik kalıcıdır, çünkü **Java'da dizilere nesne gibi davranılır**. Dizinin durumunu değiştiren işlemler bu yüzden geçerli kalır. Hoca bunun her zaman böyle olduğunu göstermek için işi başka bir sınıfta yaptırdığını, aynı `doIt` metodunu `MethodParametersTest3`'ün içine kopyalayıp kendi metodunu çağırdığında da sonucun değişmediğini gösterdi. Eclipse'teki renklendirmeden hangi `doIt` metodunun çağrıldığı anlaşılabilir.

Hoca diziler için de aynı sınırı hatırlattı: call by value of references kuralı gereği, işaretçi değiştirme ya da referans değiştirme yapılmadığı sürece işlem kalıcıdır.

### 4.1 Aynı dosyada birden fazla sınıf

`LowHighSwap` sınıfı `MethodParametersTest3.java` dosyasında, ikinci bir sınıf olarak tanımlanmıştır. Normalde bir Java dosyasında yalnız onunla aynı adlı sınıf tanımlanır, ama istenirse bir dosyada başka sınıflar da tanımlanabilir. Hoca önce bu sınıfların yalnız o dosyanın içinden kullanılabileceğini söyledi, sonra bir `ClassAccessTest` sınıfı oluşturup `LowHighSwap` türünden nesne tanımlamayı denedi. Sınıf aynı paketten görülebildi; hoca bunun nedenini, başına bir görünürlük belirteci yazılmamış sınıfın "package" görünürlüğünde olmasıyla açıkladı. Sınıfı `public` yapmayı denediğinde derleme hatasını beklediği gibi hemen göremedi ve konuyu kapattı. Her sınıfı kendi Java dosyasında tanımlamak en doğrusudur. İç sınıflar (inner class) ise ileride ayrıca görülecektir.

> **Ders sonrası not:** Hocanın ilk söylediği ("yalnız o dosyanın içinden kullanılabilir") doğru değildir; denemesinde görüldüğü gibi `public` olmayan üst düzey bir sınıf paket görünürlüğündedir ve aynı paketteki bütün sınıflardan kullanılabilir. Bir dosyada en fazla bir `public` üst düzey sınıf olabilir ve bu sınıfın adı dosya adıyla aynı olmalıdır; aksi halde derleme hatası alınır.

## 5. Araba Nesneleriyle Aktarım: Durum Değişikliği ve Referans Değişikliği

### 5.1 Plaka değiştirme: modifyPlate

Sarmalayıcı yerine gerçek bir nesne verildiğinde ne olduğunu göstermek için hoca `nyp01a` paketindeki `Car` sınıfını kullandı. Bu sınıfın plaka üye alanı, kurucusu, getter ve setter metotları vardı. `MethodParametersTest4` sınıfında `import nyp01a.*;` yazıldı ve iki araba oluşturuldu (ekrandan, 00:40:00):

```java
package nyp01e;
import nyp01a.*;
public class MethodParametersTest4 {
    public static void modifyPlate( Car aCar ) {
        aCar.setPlate("34 İS 34");
    }

    public static void main(String[] args) {
        Car car1 = new Car("01 AD 01");
        Car car2 = new Car("02 AN 02");

    }
}
```

Sonra iki arabanın plakalarını takas eden bir metot yazıldı. Hoca metodu önce `modifyPlate` adıyla aşırı yükledi (overload), sonra amacını net anlatan bir ad olsun diye `swapPlate` olarak değiştirdi; adların amacı açıkça anlatması kod okunurluğu için daha iyidir.

```java
public static void swapPlate( Car carA, Car carB ) {
    String tmp = carA.getPlate();
    carA.setPlate(carB.getPlate());
    carB.setPlate(tmp);
}
```

(ekrandan, 00:45:00)

`main` içinde önce `car1` için `modifyPlate` çağrıldı (plakası `34 İS 34` oldu), sonra `swapPlate(car1, car2)` çağrıldı. Çıktı `02 AN 02` ve `34 İS 34` oldu (ekrandan, 00:45:00). Her iki işlem de çalıştı, çünkü metot parametre olarak bir `Car` nesnesi aldı ve o nesnenin kendi setter'ını, yani durumunu değiştiren metodunu çağırdı. Nesneye erişip durum bilgisini değiştirmek mümkündür, ama nesnenin varlığını, yani parametrenin hangi nesneyi gösterdiğini değiştirmek mümkün değildir.

### 5.2 Nesne kimliği: println(car1)

Hoca nesne kimliklerini göstermek için `MethodParametersTest5` sınıfında doğrudan `System.out.println(car1)` ve `System.out.println(car2)` yazdı. Çıktı şöyle oldu (ekrandan, 00:50:00):

```text
nyp01a.Car@4926097b
nyp01a.Car@39ed3c8d
```

Çıktının ilk kısmı nesnenin `nyp01a` paketindeki `Car` sınıfından olduğunu, `@` işaretinden sonraki kısım ise on altılık bir sayıyı gösterir. Farklı nesneler için bu değer farklıdır; aynı nesne tekrar yazdırılınca aynı değer çıkar, bir tür kimlik numarası gibidir.

> **Ders sonrası not:** Hoca bu sayının Java sanal makinesinin her nesneye verdiği evrensel tekil tanımlayıcının (UUID) bir hash fonksiyonundan geçirilmiş hali olduğunu söyledi. Doğrusu: `Object.toString()` sınıf adını, `@` işaretini ve nesnenin `hashCode()` değerinin on altılık gösterimini yazar. Varsayılan `hashCode()` bir UUID'den değil, JVM'nin nesneye atadığı kimlik hash değerinden (identity hash) gelir ve büyük olasılıkla çoğu zaman farklıdır, ama iki farklı nesne için aynı çıkmayacağının garantisi yoktur.

Ardından `main` içinde yazdırmalardan önce `car1 = car2;` ataması yapıldı. Bu satır `car2`'nin bellekteki işaretçisini `car1`'e atar. Artık `car1` ve `car2` bellekteki aynı nesneyi gösteren iki referanstır; iki `println` de aynı değeri verir ve `getPlate()` ikisinde de `02` plakalı arabanın plakasını döndürür. Hoca, sayıların aynı olmasından yalnız aynı nesneyi gösterdiklerini, plakaya bakınca da bunun ikinci araba olduğunu anladığını belirtti. Bu işaretçi değişikliği `main` içinde çalıştı; ama aynı değişiklik başka bir metot üzerinden yapılamaz.

### 5.3 Referansları takas etmek: swapCars

Bunu göstermek için `swapCars` yazıldı (ekrandan, 00:50:00):

```java
public static void swapCars( Car carA, Car carB ) {
    Car tmp = carA;
    carA = carB;
    carB = tmp;
}
```

`main` içinde `car1 = car2;` satırı yoruma alındı ve `swapCars(car1, car2)` çağrıldı. Sonuç: `car1` yine `01` plakalı, `car2` yine `02` plakalı arabayı gösterdi; değişiklik olmadı. `main` içinde yapılan takasın aynısı başka metot içinde işe yaramadı, çünkü metoda referansın kendisi değil değeri aktarıldı.

### 5.4 Kurucuyla yeniden oluşturarak takas

Son olarak hoca takası kurucularla, yeni nesneler oluşturarak denedi (ekrandaki kod karede görünmüyor; anlatımdan kuruldu):

```java
public static void swapCarsV2( Car carA, Car carB ) {
    Car tmp = new Car( carA.getPlate() );
    carA = new Car( carB.getPlate() );
    carB = new Car( tmp.getPlate() );
}
```

Bu da işe yaramadı: birinci arabanın plakası hâlâ `01`, ikincininki `02` kaldı. `new` ifadesiyle oluşturulan nesne bellekte yeni bir alanda oluşturulur. Parametre olarak gelen `carA`'ya bunu atamak, ondan bellekte başka bir yeri göstermesini istemekten farksızdır. Yani hem `carA = carB` hem `carA = new Car(...)` komutu nesne referansının gösterdiği yeri değiştirmeye çalışır ve call by value of references kuralı yüzünden ikisi de çağıran tarafa yansımaz. Hoca bir kopya kurucu (copy constructor) yazılsaydı da sonucun değişmeyeceğini ekledi. `swapPlate`, `swapCars` ve `swapCarsV2` bu not hazırlanırken Java 25 ile çalıştırıldı; sonuçlar derste görülenle aynıdır.

## 6. Yapısal Programlama Tekrarı

Aradan sonra hoca yapısal programlama konusunu kısaca geçti (ekrandan, 01:10:00). Birinci sınıfın ilk döneminde algoritma mantığı akış şemaları üzerinden, sonraki derslerde de yapısal programlama mantığı oturtulduğu için bu konularda büyük bir eksiklik olmadığı varsayılır. Temeli zayıf olanlara, her konudan sonra en az 50 çözümlü problemi birkaç farklı dilde (Basic, Pascal, C, Java vb.) çözen ve ardından 150-200 çözümsüz problem veren bir kitap önerildi: Fahri Vatansever'in "Algoritma Geliştirme ve Programlamaya Giriş" kitabı. Örnek üzerinden öğrenmeyi seven için soru bankası gibi kullanılabilir; olabildiğince güncel baskısı tercih edilmelidir.

Slayttaki özet şudur: C'den bilinen yapılar Java'da benzer söz dizimiyle vardır.

- Karar verme: `if (koşul) {...} else if (koşul) {...} ... else {...}`
- Karşılaştırma işleçleri: `<`, `>`, `<=`, `>=`, `==` (eşit mi), `!=` (eşit değil)
- Mantıksal işlemlerde çift işleç kullanılır: `&&` ve `||`
- Döngüler: `for( başlangıç; koşul; artırma ) {...}`, `while( koşul ) {...}`, `do {...} while( koşul );`, `switch / case`
- Aritmetik işleçler ve kısaltmalar: `+`, `-`, `*`, `/`, `++`, `--`, `*=` vb.

Hoca bit düzeyi `&` ile mantıksal `&&` arasındaki farkı hatırlattı: tek ampersand iki sayısal değerin bitlerini birbiriyle VE işlemine sokar ve istenmeyen sonuçlar doğurabilir. `if` koşulundaki karşılaştırmalar boolean karşılaştırmalar olduğundan çift işleç kullanılır.

> **Ek bilgi (derste anlatılmadı):** Java'da `&` ve `|` işleçleri `boolean` işlenenlerle de kullanılabilir; bu durumda bit düzeyi değil mantıksal işlem yaparlar, ama kısa devre (short-circuit) yapmazlar, yani sol taraf sonucu belirlese bile sağ taraf da değerlendirilir. `if( car != null && car.getPlate() ... )` gibi bir koşulda `&` yazılırsa `car` `null` iken bile sağ taraf çalışır ve `NullPointerException` oluşur. Bu yüzden koşullarda `&&` ve `||` tercih edilir.

## 7. Nesneler Arası İlişkilere Giriş

Bir nesneye yönelik program, nesnelerin birbirinin metotlarını çağırmasıyla yürür. Bir nesnenin diğerinin metodunu çağırabilmesi için bu iki nesne arasında bir ilişki olması gerekir. Bu ilişkilerin adları, UML sınıf şemalarında çizimleri ve kodlanışları sırayla görülecektir:

- **Association:** sahiplik ilişkisi.
- **Dependency:** bağımlılık. Sahiplik olmadan, metot parametresi olarak kullanma ya da bir metodun içinde geçici olarak tanımlama.
- **Aggregation ve composition:** parça-bütün ilişkileri. Bir bütün birden fazla parça içerir. İlişkinin kurallarının gevşekliğine ya da sıkılığına göre aggregation ya da composition denir.
- **Inheritance:** kalıtım.

İlk dördü kodlanırken de üzerinde düşünülürken de nesneler üzerinden düşünülen ilişkilerdir. Kalıtım ise diğerlerinden farklı olarak sınıf düzeyinde bir ilişkidir ve sınıf düzeyinde düşünülmelidir.

## 8. Association (Sahiplik)

### 8.1 Customer ve Order

Association'ın özü sahipliktir (ownership): mesaj gönderebilen nesne, mesajın alıcısını üye alan olarak taşır (ekrandan, 01:15:00). Slayttaki örnek bir müşteri ve siparişleridir:

```text
+----------+  1     gives     *  +-------+
| Customer |-------------------->| Order |
+----------+                     +-------+
```

Bir `Customer` n adet sipariş verebilir. Bunun anlamı, `Customer` sınıfının içinde üye alan olarak `Order` türünden nesneler tanımlanmış olmasıdır. Bu yüzden ilişki `Customer`'dan `Order`'a giden düz bir çizgi ve ucu açık bir okla gösterilir.

- **Nitelik:** İlişkinin türü (sahiplik) çizginin ve okun biçimiyle gösterilir. İşin özünde üye alan taşımak vardır.
- **Nicelik:** İlişkinin sayısal boyutu, ilgili sınıfa yakın uca yazılan işaretlerle anlatılır. Burada bir `Customer` nesnesi sıfır ya da daha fazla `Order` nesnesine sahiptir.
- **Mantıksal ad:** İş mantığı açısından "bir müşteri sıfır ya da daha fazla sipariş verir" denebilir; okun üstüne bu yüzden "gives" yazılabilir. Ama programlama açısından bu bir sahiplik ilişkisidir.

### 8.2 Okun yönü

Okun yönü, bir `Customer` nesnesinin üye alan olarak sahip olduğu `Order` nesnelerinin metotlarını çağırabileceğini gösterir; ok yönü metot çağırabilme yönüdür. Aynı zamanda bir nesnenin diğerinden haberdar olma durumunu da gösterir: `Customer` siparişlerini bilir. Ama bir `Order`, kendisini hangi müşterinin verdiğini bilmez, çünkü çizginin öbür ucunda ok yoktur.

Eğer ok yoksa ve yalnız çizgi varsa, bu tasarımın henüz netleştirilmediği, ilişkinin hangi yönlü olduğunun düşünülmediği anlamına gelir; iki yönlü de olabilir. Bu bir belirsizliktir.

> **Hocanın vurgusu:** Sınavlarda verilen şemalarda da, sınavda ya da projede sizden çizmeniz istenen şemalarda da ilişkinin yönü mutlaka gösterilmelidir: A'dan B'ye mi, B'den A'ya mı, yoksa çift yönlü mü. Tek yönlü ve çift yönlü ilişkilerin özellikleri ve yan etkileri pratik örneklerle görülecektir.

### 8.3 Nicelik gösterimi

- `*`: sıfır ya da daha fazla.
- `1..*`: bir ya da daha fazla. `..` bir aralık (range) ifadesidir: alt sınır 1, üst sınır yok.
- `1`: sadece ve mutlaka bir. İki de olmaz, sıfır da olmaz.
- `0..1`: bir tane olabilir ya da hiç olmayabilir.
- `1..11`: bir ile on bir arasında herhangi bir sayı.

Nicelik iki ya da üç gibi küçük bir sayıysa o kadar sayıda üye alan tanımlanabilir. Daha fazlası için dizi kullanmak gerekir.

## 9. Dependency (Bağımlılık) ve Gizli Bilgi

### 9.1 Gizli bilgi (hidden information)

Bir ilişki çizgi ve oklarla gösterildiyse, sınıfın içindeki ayrıntılar yazılmayabilir (ekrandan, 01:20:00). Aşağıdaki iki şema aynıdır:

```text
Customer  1 ----gives---> *  Order

+-------------------+
|     Customer      |
+-------------------+  1           *
| - orders[]: Order |-------------->  Order
+-------------------+
```

`Customer`'dan `Order`'a bire-yıldız sahiplik ilişkisi varsa bunun koda dökülebilmesi için `Customer` sınıfında `Order` türünden, adı `orders` olan bir dizi bulunmalıdır; böylece bir müşteri n adet siparişle ilişkili olabilir. Köşeli parantezler, yapısal programlamada olduğu gibi dizi işaretidir.

> **Hocanın vurgusu:** Soldaki şema çizildiğinde sağdakini de anlamak zorundasınız. Sınavlarda tasarım verilip bu tasarıma göre kod yazmanız istenecek ve verilen tasarımda gizli bilgiler gösterilmeyebilir; soruların başında "şemada gizli bilgiler olabilir, kodunuzu ona göre yazınız" denir. Ayrıntılı sınıf şemasında `Order` türünden dizi yazılmamış olsa bile çizginin ucunda `*` görünüyorsa, okun çıktığı sınıfta okun baktığı türden bir dizi olmak zorundadır.

Dersin sonuna doğru hoca bunu genelleştirdi (ekrandan, slayt 76 küçük resmi): A'dan B'ye düz çizgi ve ucu açık ok varsa, A tarafında 1 ve B tarafında 2 yazıyorsa, bir A nesnesi iki B nesnesiyle ilişkilidir ve bunun için A sınıfında B türünden iki üye alan olmalıdır. Şemada bu üye alanlar gösterilmemiş olsa bile kod buna göre yazılmalıdır. Composition ve aggregation da aynı mantıkla okunur: bütün tarafında içi boş ya da içi dolu bir elmas, parça tarafında ok bulunur (ok çizilmemişse de var sayılır). Parça tarafında `*` yazıyorsa bütün tarafındaki sınıfta parça türünden bir dizi vardır. <!-- BELİRSİZ: slayt 76'daki şemalar karede yalnız küçük resim olarak görünüyor; ayrıntılar anlatımdan alındı. -->

### 9.2 Dependency

İkinci ilişki türü dependency, yani geçici olarak kullanmadır. A'dan B'ye kesikli çizgi ve ucu açık bir okla gösterilir (ekrandan, 01:20:00):

```text
+--------------------+
|         A          |
+--------------------+          +---+
|                    |- - - - ->| B |
+--------------------+          +---+
| + aMethod( b : B ) |
+--------------------+
```

Slayttaki açıklama: "A, B'ye bağımlıdır = A'nın örnekleri `aMethod` gövdesinde B'nin örneklerine mesaj gönderebilir." A sınıfında B türünden hiçbir üye alan yoktur; olsaydı ilişki association olur ve düz çizgiyle gösterilirdi. Ama A'nın bir metodu B türünden bir parametre alır. Başka bir olasılık da A'nın hiçbir metodunun B parametresi almaması, ama bir metodun gövdesinde B türünden bir nesne oluşturup kullanmasıdır.

Önceki derslerde `Car` sınıfı ve `main` metodu olan ayrı bir sınıf oluşturulmuş, `main` içinde `Car` nesneleri yaratılmıştı. İşte bu, `main` metodunu içeren sınıftan `Car` sınıfına doğru kesikli çizgi ve okla gösterilen bir dependency ilişkisidir.

Hem dependency hem association bir kod bağımlılığı ortaya çıkarır. A'nın kodu tek başına alınıp kullanılamaz; bir metodu B parametresi gerektirdiği için A nerede kullanılıyorsa B de oraya eklenmeli, import edilmelidir. Benzer şekilde `Customer` sınıfı da `Order` olmadan kullanılamaz.

## 10. Tek Yönlü Association: Person ve Car

### 10.1 Alan modeli

Kod yazmadan önce problemle ilgili varlıklar ve aralarındaki ilişkiler koda aktarılacak bir alan modeli (domain model) olarak düşünülür. Problem: her insan bir araba sahibi olabilir. "Olur" değil "olabilir" denmektedir; bir insanın bir arabası olabilir ya da hiç olmayabilir. Slayttaki tasarım şöyledir (ekrandan, 01:25:00):

```text
paket nyp02

+------------------------------+
|            Person            |
+------------------------------+
| - name : String              |
| - car : Car                  |  1   owns     0..1  +-----------------------+
+------------------------------+-------------------->|          Car          |
| + Person( name : String )    |                     +-----------------------+
| + getName( ) : String        |                     | - plate : String      |
| + getCar( ) : Car            |                     +-----------------------+
| + setCar( Car )              |                     | + Car( String )       |
| + introduceSelf( ) : String  |                     | + getPlate( ) : String|
+------------------------------+                     +-----------------------+
        ^                                                       ^
        :  (dependency)                                         :  (dependency)
+----------------------+                                        :
|    MainProgram01     |- - - - - - - - - - - - - - - - - - - - +
+----------------------+
| + main( String[] )   |
+----------------------+
```

Slayttaki diğer maddeler: alan modelini kullanan ve çalıştırılabilmesi için `main` metodu olan bir program da yazılacaktır; alan modeli ve program farklı paketlerde durmalıdır.

`Person` tarafında `1`, `Car` tarafında `0..1` yazar. Tasarım bir kişinin iki arabası olmasına zaten izin vermez: `Person` sınıfında bir `name` üye alanı ve `Car` türünden, küçük harfle başlayan `car` adlı tek bir üye alan vardır. İki araba olabilseydi belki `car1` ve `car2` denebilirdi; daha fazlası için dizi kullanmak en mantıklısıdır.

`Person`'ın kurucusu yalnız ismi parametre olarak alır, arabayı almaz. Araba da parametre olarak verilseydi ve başka kurucu olmasaydı, her insan oluşturulurken ona bir araba vermek gerekirdi; o zaman sınıf şemasında `Car` tarafında `0..1` değil, sadece `1` yazardı. Arabanın yerine kurucuya doğrudan `null` verilebilirdi, ama hoca bunu sevmediğini söyledi: üye alana `null` atanır ve sonra o üye alana erişilmeye çalışılınca `NullPointerException` ile karşılaşılır. İlklendirilmemiş bir nesnenin metodunu çağırınca bu hata oluşur ve program akışı o anda kesilir.

Kişinin arabası için getter ve setter metotları vardır. Setter olmasa kişiye araba atanamazdı. `Car` sınıfında değişiklik yoktur: tek üye alanı `String` türünde `plate`'tir. Slayttaki "gizli bilgi: `Car` sınıfının kurucusunu inceleyin" maddesi buna işaret eder: kurucu tek bir `String` parametre alır ve bu plakadır. Setter olmadığı için plaka kurucuda atandıktan sonra bir daha değiştirilemez.

### 10.2 introduceSelf artık bir String döndürür

`introduceSelf` metodu bundan sonra farklı kullanılacaktır. Önceden nesne kendisi hakkındaki bilgiyi kendisi komut satırına yazdırıyordu. Artık kendi durum bilgisini içeren bir `String` döndürecektir. Bu metodu çağıran taraf dönen metinle ne isterse onu yapar: ekrana yazdırır, yazıcıdan çıkarır, bir ağ bağlantısı üzerinden başka bir yere gönderir, bir pencere açıp iletişim kutusunda gösterir ya da diske kaydeder.

Böylece iş mantığı ile sunum katmanı, yani veri girdi-çıktı katmanı birbirinden ayrılmış olur. `introduceSelf` yalnız ekrana yazsaydı nesnenin durumu ancak o ekrandan bakılarak değerlendirilebilir, başka bir yere yönlendirilemezdi.

### 10.3 Derste birlikte yazılan kod

Hoca `week04` adında yeni bir paket açıp `Car` sınıfını Eclipse'in otomatik üretim araçlarıyla (Source > Generate Constructor using Fields, Source > Generate Getters and Setters) iki tıklamayla oluşturdu. Ardından `Person` sınıfını öğrencilerle birlikte yazdı. İlk hali şuydu (ekrandan, 01:35:00):

```java
package week04;

public class Person {
    private String name;
    private Car car;

    public Person( String name ) {
        this.name = name;
    }
    public String getName() { return name; }
    public Car getCar() { return car; };
    public void setCar( Car aCar ) { this.car = aCar; }
    public String introduceSelf( ) {
        String info = "My name is " + name;
        info += " and I have a car with plate " + car.getPlate();
        return info;
    }

}
```

Hoca burada durup bir şeyden şüphelenen olup olmadığını sordu (bkz. Örnek Sorular). Şemaya göre bir insan sıfır ya da bir arabayla ilişkili olabilir. Arabası olmayan kişi "şu plakalı bir arabam var" demeye kalkarsa `car` `null` olduğundan `null` bir nesnenin metodu çağrılmış olur ve `NullPointerException` aykırı durumu (exception) ortaya çıkar, akış orada durur.

Bunu göstermek için `MainProgram01` sınıfında arabası olmayan bir kişi oluşturulup `introduceSelf` sonucu yazdırıldı. Konsolda `Exception in thread "main" java.lang.NullPointerException` hatası, hatanın `introduceSelf` metodunda çıktığı ve onu `main` metodunun çağırdığı görüldü.

Bir setter metodu yazılmış olması onun çağrılacağının garantisini vermez; bir kişi oluşturulup `setCar` hiç çağrılmayabilir. Ancak kurucularla ilgili bir garanti verilebilir. Bu yüzden plaka bilgisinin eklendiği satırdan önce bir `null` kontrolü gerekir (ekrandan, 01:50:00):

```java
public String introduceSelf( ) {
    String info = "My name is " + name;
    if( car != null )
        info += " and I have a car with plate "
                + car.getPlate();
    return info;
}
```

Aracın, yani `car` üye alanının değeri `null` değilse kişinin bir arabası vardır ve plaka eklenir. Kontrolden sonra program hatasız çalıştı: arabası olmayan kişi yalnız adını söyledi, `setCar` ile araba verilen kişi adını ve arabasının plakasını söyledi.

> **Hocanın vurgusu:** Bu `null` kontrolü arabası olmayan kişinin durumuyla ilgilidir ve mutlaka yapılmalıdır.

Hoca slayttaki sürümde cümlenin sonuna nokta koyma satırının `if`'in içinde kaldığını, arabası olmayan kişinin cümlesinin noktasız kalacağını, bu satırın `if`'in dışına yazılmasının daha iyi olacağını da belirtti.

Arabayı ayrıca bir değişkende tutmadan doğrudan `setCar(new Car(...))` biçiminde de vermek mümkündür. Bu durumda arabaya doğrudan bir referans yoktur, ama istenen bir anda kişinin `getCar()` metodu çağrılıp dönen referans bir `Car` değişkenine atanarak aracın durumu sorgulanabilir ve değiştirilebilir.

### 10.4 Nesnenin ilklendirilip ilklendirilmediğini sınamak

Slayttaki dört olası varyasyon şunlardır:

| İfade | Sonuç | Anlamı |
|---|---|---|
| `obj1 != null` | `true` | ilklendirilmiş (değer atanmış) |
| `obj1 == null` | `false` | ilklendirilmiş |
| `obj1 == null` | `true` | ilklendirilmemiş |
| `obj1 != null` | `false` | ilklendirilmemiş |

## 11. Sıralama Şeması (Sequence Diagram)

### 11.1 introduceSelf metodunun şeması

Hoca şemaları Violet UML ile çizdi. Violet UML'de bir yerden çıkan, ucu boşta bir ok çizilemediği için en solda boş bir nesne yaşam çizgisi (lifeline) çizmek gerekir. Tahtada çizerken bu kısım çizilmez; o boş kutu yok sayılmalıdır.

Şemada yalnız metot çağrıları gösterilir; kurucular da metot olduğu için bunlara dahildir. `introduceSelf` içinde geçici bir `String` tanımlanıp değer atanması çizilmez. Hoca şemayı daha ayrıntılı çizebilmek için metodu `name` yerine `getName()` çağıracak şekilde değiştirdi (ekrandan, 02:35:00):

```java
public String introduceSelf( ) {
    String info = "My name is " + getName();
    if( car != null )
        info += " and I have a car with plate "
                + car.getPlate();
    return info;
}
```

Şemanın yapısı şöyledir (ekrandan, 01:45:00 ve 02:15:00):

```text
 (çağıran)            :Person                 car : Car
    |                    |                        |
    |--introduceSelf()-->|                        |
    |                    |--getName()--+          |
    |                    |<------------+          |
    |                    |                        |
    |                    |--[car != null] getPlate()-->|
    |                    |<- - - - - plate - - - - - - |
    |<- - - info - - - - |                        |
```

- Üstte `:Person` yazılır: bir `Person` nesnesidir, ama hangisi olduğu belli değildir. Metodun genel çalışma biçimi çizildiği için nesne adı yoktur.
- `getName()` nesnenin kendi metodudur; nesneden yine kendisine bir ok çizilir. İnsan nesnesinin mutlaka bir isim üye alanı olduğu için her koşulda çağrılır.
- `getPlate()` nesnenin kendisinin değil, `car` üye alanının metodudur. Bu yüzden ayrı bir yaşam çizgisi konur: `car : Car`. Önce küçük harfle üye alan adı, iki noktadan sonra büyük harfle sınıf (tür) adı yazılır. Hangi `Person` nesnesi olursa olsun üye alanın adı `car`'dır.
- `getPlate()` her zaman çağrılmaz; `car` `null` değilse çağrılır. Koşula bağlı bir çağrı, çağrı okunun önüne köşeli parantez içinde koşul yazılarak gösterilir: `[car != null] getPlate()`. Köşeli parantez burada `if` anlamına gelir.
- Dönüş okları kesikli çizilir: `getPlate` `plate` döndürür, `introduceSelf` de biriktirdiği `info` metnini döndürür.

Hoca ilk çizimde `getPlate` okunu yanlışlıkla nesnenin kendisine çizdiğini, doğrusunun `car` nesnesine gitmesi olduğunu düzeltti. Slayttaki şemada koşul kısaltılmış biçimde yazılmış ve yanına "`[car != null]` de kullanılabilir" notu düşülmüştür (ekrandan, 01:45:00). Hoca kısaltma kullanmamayı, koşulun tam halini yazmayı önerdi; yalnız "not null" yazılırsa `this` mi kastediliyor, anlaşılmayabilir.

> **Hocanın vurgusu:** Sıralama şemaları dersin müfredatının parçasıdır. Bir soruda bir metodun sıralama şemasının çizilmesi ya da sıralama şeması verilip metodun buna göre kodlanması istenebilir.

### 11.2 MainProgram01 metodunun şeması

İkinci aradan sonra `main` metodunun şeması slayttaki kod üzerinden çizildi (ekrandan, 02:15:00):

```java
package week04;

public class MainProgram01 {

    public static void main(String[] args) {
        Person oktay;
        oktay = new Person( "Oktay Sinanoğlu" );
        Car rover = new Car( "34 OS 1934" );
        oktay.setCar( rover );
        System.out.println( oktay.introduceSelf() );
        Person aziz = new Person( "Aziz Sancar" );
        System.out.println( aziz.introduceSelf() );
    }

}
```

Sıralama şeması tamamen hangi metodun hangi sırada çağrıldığıyla ilgili olduğu için slayttaki sıra izlendi. Şemanın son hali şöyledir (ekrandan, 02:30:00):

```text
 (JVM)   :MainProgram01     oktay:Person     rover : Car     aziz:Person
   |            |                 |                |               |
   |--main(String[])-->|          |                |               |
   |            |--new("Oktay Sinanoğlu")-->|      |               |
   |            |<- - - - - - - - |                |               |
   |            |--new("34 OS 1934")-------------->|               |
   |            |<- - - - - - - - - - - - - - - - -|               |
   |            |--setCar(rover)->|                |               |
   |            |<- - - - - - - - |                |               |
   |            |--introduceSelf()->|              |               |
   |            |                 |--getName()-+   |               |
   |            |                 |<-----------+   |               |
   |            |                 |--[rover != null] getPlate()--->|
   |            |                 |<- - - - - - - -|               |
   |            |<- - - info - - -|                |               |
   |            |--new("Aziz Sancar")------------------------------>|
   |            |<- - - - - - - - - - - - - - - - - - - - - - - - - |
   |            |--introduceSelf()--------------------------------->|
   |            |                                  |   getName()-+ |
   |            |                                  |   <---------+ |
   |            |<- - - - - - - - - - - - - - - - - - - - - - - - - |
   |<- - - - - -|                 |                |               |
```

Adımlar şöyledir:

- `main` metodu çağrılır. Parametresi tek bir `String` dizisidir; istenirse `main(String[])` diye yazılabilir.
- `Person` türünden `oktay` adlı nesne işaretçisi tanımlanıp kurucusu çağrılarak ilklendirilir. Sıralama şemasında kurucu adını yazmak gerekmez, `new` yeterlidir; parametresi de gösterilebilir.
- `rover` adlı `Car` nesnesi `new("34 OS 1934")` ile oluşturulur. Hoca önce plakayı yanlış yazdı, kendisine plakanın `34` ile başladığı hatırlatılınca düzeltti.
- `oktay.setCar(rover)` çağrılır; metot atamayı yapıp döner.
- `oktay.introduceSelf()` çağrılır. Önce kendi `getName()` metodu çağrılır. Bu kez belirli bir `Person` nesnesinden ve onun belirli bir üye alanından söz edildiği için `getPlate()` çağrısı genel `car` yaşam çizgisine değil, `oktay`'ın arabası olan `rover` nesnesine yönlendirilir. Koşul da `[rover != null]` olarak yazılır. Sonunda `info` döner.
- `aziz` nesnesi oluşturulur ve `introduceSelf()` çağrılır. Arabası olmadığı için yönlendirilen bir `getPlate` mesajı olmaz; `getName()`'den sonra doğrudan dönüş oku çizilir.
- Kodda başka bir şey kalmadığı için `main` biter; bunu göstermek için en sona bir dönüş oku çizilir.

Hoca slayttaki şemanın eksik olduğunu, `introduceSelf` içindeki alt çağrıların (`getName` ve `getPlate`) orada gösterilmediğini, bunun ayrıntılandırılması gerektiğini belirtti. Bir önceki şemada çizildiği için tekrarlanmadı denebilir, ama asıl doğrusu alt metot çağrılarını da göstermektir.

### 11.3 Çağrılar arasındaki dikey boşluk

Hoca şema üzerinde işaretleyerek şu ayrıntıyı tekrarladı: `main` metodu başlar ve diğer bütün oklar onun içinde gider gelir. Bir metot çağrısının arka planda otomatik yapılan, çok kısa da sürse bir maliyeti vardır. Bu yüzden `main`'in başladığı hiza ile ilk komut olan `new` çağrısı arasında bir mesafe vardır.

> **Hocanın vurgusu:** Araçla çizerken bu mesafe otomatik konur, ama kağıt kalemle çizerken sık yapılan bir yanlış bu mesafeyi koymamaktır. Sıralama şemasında aşağı inildikçe zamanda da ileri gidilir. `new` okunu `main` ile aynı hizada çizmek doğru olmaz; daha yukarıdan başlatmak ise zamanda geriye gitmek gibidir.

Bu boşluklar sayesinde görsel olarak da şu anlaşılır: bütün bu çağrılar `main` metodunu izlemez, onun içinde yer alır. Öte yandan ilk `new` çağrısını ikinci `new` çağrısı izler: biri bittikten sonra öteki başlar, çünkü arada mesafe vardır ve daha aşağıdadır. İkisinin de `main` içinde olduğu da görülebilir.

> **Ders sonrası not:** Hoca, metot çağrısı için arka planda "heap" bellekte bir alan açıldığını söyledi. Doğrusu: bir metot çağrısının yerel değişkenleri ve parametreleri için yığında (stack) bir çerçeve (stack frame) açılır. `new` ile oluşturulan nesneler ise heap'te tutulur.

## 12. Sahip Olunan Nesneye İş Yaptırmak: changeCarPlate

Kişi ve araba örneğinde kişi arabasından yalnız getter çağırarak bilgi alıyordu. Ama bir nesne, üye alanlarına yalnız bilgi almak için ulaşmak zorunda değildir: onlara bir iş yaptırabilir, durumlarını değiştirebilir. Hoca kalan sürede yeni konuya girmek yerine bunun pratiğini yaptı ve `Person`'a kişinin arabasının plakasını değiştiren bir metot ekledi (ekrandan, 02:35:00).

Bunun için `Car`'da plakayı değiştiren bir metot gerekiyordu, ama `Car`'ın setter'ı yazılmamıştı. Önce `Car`'a eklendi:

```java
public void setPlate( String plate ) { this.plate = plate; }
```

Sonra `Person`'a `changeCarPlate` eklendi. Burada da `null` kontrolü gerekir: kişinin arabası olmayabilir. Arabası yoksa o plakalı bir arabası olsun gibi bir davranış kodlanabilir, ama bunun problemin gerektirip gerektirmediğine bakmak gerekir. Hoca arabası yoksa hata bildirmenin iki yolunu söyledi: ekrana bir mesaj yazdırmak ya da metodu `void` yerine `boolean` döndüren bir metot yapıp plakayı değiştirebildiyse `true`, araba olmadığı için değiştiremediyse `false` döndürmek. Derste ilki, daha basit olan yol kodlandı. Metot gövdesi karelerde görünmediği için anlatımdan kuruldu; hata mesajının metni de anlatımdan alınmıştır:

```java
public void changeCarPlate( String newPlate ) {
    if( car != null )
        car.setPlate( newPlate );
    else
        System.out.println("Invalid attempt to change the plate of a non-existent car");
}
```

<!-- BELİRSİZ: hata mesajının tam metni ekranda görülemedi; altyazıda "invalid attempt ... to change the plate of a non-existent car" geçiyor. -->

`main` içinde `oktay.setCar(rover)` satırından sonra `oktay.changeCarPlate("06 ANK 06")` çağrıldı. Kişi kendini tanıttığında arabasının plakası değiştirilmiş olarak çıktı. Plakayı kişi üzerinden değiştirmek, yalnız kişinin bileceği bir değişiklik değildir; `changeCarPlate` içinde `car` üye alanının setter'ı çağrıldığı için arabanın kendisi de yeni plakayı döndürür. Bunu göstermek için `rover.getPlate()` de yazdırıldı ve tutarsızlık olmadığı görüldü (ekrandan, 02:40:00):

```text
My name is Oktay Sinanoğlu and I have a car with plate 06 ANK 06
06 ANK 06
My name is Aziz Sancar
```

Son olarak arabası olmayan kişi için `aziz.changeCarPlate("35 İZ 35")` çağrıldı. Bu kez `NullPointerException` oluşmadı; ekrana yalnız geçersiz bir işlem yapılmaya çalışıldığını söyleyen mesaj geldi ve kişi kendini yine normal olarak tanıttı. Kod akışı herhangi bir yan etki olmadan sürdü. Bu sınıfların tamamı (`Person`, `Car`, `MainProgram01`) not hazırlanırken Java 25 ile tek dosyada çalıştırıldı ve çıktı yukarıdakiyle aynı çıktı.

## Örnek Sorular

**Soru 1** (ekrandan, 01:25:00): Slayttaki `Person 1 —owns→ 0..1 Car` şemasında association'ın `Car` ucunda neden `0..1` yazıyor?

> **Çözüm (derste verildi):** Problem alanında her insanın bir arabası olabilir ya da hiç olmayabilir, ama birden fazla arabası olamaz. Tasarım da buna uyar: `Person`'da tek bir `car` üye alanı vardır ve kurucu `Person(String name)` arabayı parametre olarak almaz; araba sonradan `setCar` ile verilir ya da hiç verilmez. Kurucu arabayı da zorunlu parametre olarak alsaydı uçta `1` yazardı.

**Soru 2** (ekrandan, 01:25:00): Slayttaki "Gizli bilgi: `Car` sınıfının kurucusunu inceleyin" maddesine göre `Car( String )` kurucusunun aldığı parametre nedir?

> **Çözüm (derste verildi):** `Car`'ın tek üye alanı `String` türündeki `plate` olduğu için kurucunun aldığı tek `String` parametre aracın plakasıdır. Şemada parametre adı yazılmamıştır; bu bir gizli bilgidir.

**Soru 3** (derste sözlü, 01:35:04): `introduceSelf` metodu `info += " and I have a car with plate " + car.getPlate();` biçiminde, kontrolsüz yazıldığında bir sorun var mıdır?

> **Cevap (derste bir öğrenci verdi, hoca onayladı):** Evet. Şemaya göre kişinin arabası olmayabilir; `setCar` hiç çağrılmamışsa `car` `null`'dır. `null` bir nesnenin metodu çağrılınca derleme hatası değil, çalışma zamanında `NullPointerException` oluşur ve akış durur. Çözüm, plaka satırını `if( car != null )` ile korumaktır.

**Soru 4** (derste sözlü, 00:44:16 ve 00:46:03): `System.out.println(car1)` ne yazar? `main` içinde `car1 = car2;` yapıldıktan sonra `car1` ve `car2` yazdırılınca ne görülür?

> **Çözüm (derste verildi):** `println(car1)` nesnenin sınıf adını, `@` işaretini ve on altılık bir sayıyı yazar (`nyp01a.Car@4926097b` gibi; ekrandan, 00:50:00). Farklı nesneler farklı sayı verir. `car1 = car2;` sonrasında iki referans aynı nesneyi gösterir; ikisi de aynı değeri yazar ve `getPlate()` ikisinde de `02 AN 02` döndürür.

**Soru 5** (derste sözlü, 00:48:23): `main` içinde çalışan referans takası `swapCars(Car carA, Car carB)` metodunun içine taşınırsa (`tmp = carA; carA = carB; carB = tmp;`) çağıran taraftaki `car1` ve `car2` değişir mi?

> **Çözüm (derste verildi):** Hayır. Java parametreleri "call by value of references" ile aktarır; metoda referansların kopyaları gelir. Kopyaları takas etmek çağıran taraftaki `car1` ve `car2`'yi etkilemez; çalıştırınca `car1` hâlâ `01 AD 01`, `car2` hâlâ `02 AN 02` plakalı arabayı gösterir. Buna karşılık `swapPlate` nesnelerin durumunu setter ile değiştirdiği için çalışır.

## Dersin Toparlaması

Dersin ilk yarısında Java'nın parametre aktarma kuralı ayrıntılı biçimde sınandı. İlkel türler değerle aktarılır; nesneler ve diziler için referansın değeri aktarılır. Bu yüzden çağrılan metot bir nesnenin ya da dizinin durumunu kalıcı olarak değiştirebilir, ama parametreyi başka bir nesneye yönlendirmek ya da `new` ile yeniden oluşturmak çağıran tarafa yansımaz. Sarmalayıcı sınıflar basit işleçlerle ilkel gibi davranır. Yol üstünde yerel değişken kapsamı, `static` metotlarda `this`'in ve normal üye alanların kullanılamaması, aynı dosyada birden fazla sınıf ve eskimiş (deprecated) metotlar da konuşuldu.

İkinci yarıda nesneler arası ilişkilere geçildi: association (üye alanla sahiplik, düz çizgi ve açık ok), dependency (parametre ya da geçici yerel nesne, kesikli çizgi), parça-bütün ilişkileri ve sınıf düzeyindeki kalıtım. Nicelik gösterimi ve gizli bilgi kavramıyla şemadan kodun nasıl çıkarılacağı anlatıldı. `Person 1 → 0..1 Car` tek yönlü association örneği kodlandı, isteğe bağlı ilişkilerde `null` kontrolünün zorunlu olduğu gösterildi ve `introduceSelf` ile `MainProgram01` için koşullu çağrı içeren sıralama şemaları çizildi. Bir sonraki adımda iki yönlü association, ardından composition ve kalıtım işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
