# Ders 8 Genişletilmiş Notu: Metot Parametreleri, Kontrol Akışı ve Nesneler Arası İlişkiler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nerede Kalmıştık
- 2. Java'da Metot Çağrısı: Değerle ve Referansın Değeriyle
- 3. MethodParametersTest1: Metot İçinde Değiştirme Denemeleri
- 4. MethodParametersTest2: Aynı Metot İçinde Takas
- 5. MethodParametersTest3: Dizinin Metoda Geçirilmesi
- 6. Kontrol Akışını Değiştiren Yapılar
- 7. Nesneler Arası İlişkilere Giriş
- 8. Association (Sahiplik) ve Gösterimi
- 9. Gizli Bilgi ve Dependency (Bağımlılık)
- 10. Tek Yönlü Association'ın Kodlanması
- 11. Sıralama Diyagramları
- 12. Diyagramdan Kodu Okumak
- 13. Klavyeden Girdiyle Tek Yönlü Örnek
- 14. İki Yönlü Association
- 15. Aggregation ve Composition
- Örnek Sorular

## 1. Nerede Kalmıştık

Ders, ders notlarının 55. slaytından, "Method Parameters and Control Flow" bölümünden başladı (ekrandan, 00:15:00). Hoca şimdiye kadar işlenenleri şöyle özetledi: nesnenin ne olduğu, bir sınıftan nesnenin nasıl oluşturulduğu, Java SDK ile gelen temel sınıflar ve sık kullanılan metotları, ilkel (primitive) türler ve bunların sarmalayıcı (wrapper) sınıfları, temel UML sınıf diyagramları ve bu diyagramlardan sıralama diyagramı (sequence diagram) oluşturma. Bu derste önce Java'da metot çağrısının nasıl çalıştığı ve kontrol akışı, sonra nesneler arasındaki ilişkiler ve bu ilişkilerle nesne yönelimli program yazmak ele alındı.

## 2. Java'da Metot Çağrısı: Değerle ve Referansın Değeriyle

Java metot çağrısında "call by value" kullanır. Hoca bunu "call by value of references", yani referansların değeriyle çağırma diye de adlandırdı.

- Metodun argümanı ilkel türdeyse (`int`, `double` gibi) metoda o değişkenin değeri geçer.
- Argüman ilkel olmayan bir türdeyse (bir nesne ya da dizi) metoda nesnenin kendisi değil, o nesnenin referansının değeri geçer. Nesne JVM'in bellekte ayırdığı alanda durur; metot, o nesneye giden adresin bir kopyasını alır.

Hoca bunun C'deki işaretçiyle (pointer) çağırmadan farklı olduğunu belirtti ve konuyu örnek kod üzerinde göstereceğini söyledi. Örnekler Eclipse'te `nyp01e` paketindeydi; hoca kodu satır satır izlerken belleği tahtaya çizdi.

> **Ek bilgi (derste anlatılmadı):** Java'da parametreye metot içinde yeni bir değer ya da yeni bir nesne atamak çağıranın değişkenini değiştirmez, çünkü parametre yalnız bir kopyadır. Ama parametrenin gösterdiği nesnenin içi (bir alanı, bir dizi elemanı) değiştirilirse çağıran da aynı nesneyi gördüğü için değişikliği görür. Aşağıdaki örneklerin hepsi bu iki durumdan birine girer.

## 3. MethodParametersTest1: Metot İçinde Değiştirme Denemeleri

### 3.1 Sınıfın kodu

Ekrandaki sınıf şudur (ekrandan, 00:20:00, 00:35:00 ve 00:40:00):

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
    public static void main(String[] args) {
        MethodParametersTest1 test = new MethodParametersTest1();
        test.tryMe();
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

        System.out.println("Before : " + wrap1 + ", " + wrap2 );
        this.sarmalayiciDegistirAlt(wrap1, wrap2);
        // ... (devamı karelerde görünmüyor)
    }
}
```

<!-- BELİRSİZ: tryMe metodunun 56. satırdan sonraki kısmı (sarmalayiciDegistirAlt sonrası çıktı ve swapForReal çağrısı) hiçbir karede görünmüyor. Altyazıya göre wrapI ve wrapJ'ye 3 ve 5 değerleri verilip swapForReal çağrılıyor. -->

Sınıfta `private Integer wrapI, wrapJ;` biçiminde iki üye alan ve altı metot vardır. `main` metodu sınıfın bir nesnesini oluşturur ve bu nesne üzerinden `tryMe()` metodunu çağırır. Asıl denemeler `tryMe()` içindedir.

### 3.2 İlkel değeri metot içinde artırmak

`int count = 3;` ile bellekte `count` için bir yer açılır ve 3 yazılır. `this.ilkelDuzenle(count)` çağrısında `count` ilkel türde olduğu için metoda değeri, yani 3 geçer. `ilkelDuzenle(int x)` içinde `x` için bellekte ayrı bir yer açılır ve `x = 3` olur. `x++` ile `x` 4 olur. Metot bittikten sonra `count` yazdırılır: değer hâlâ 3'tür, hiçbir şey değişmemiştir.

### 3.3 Sarmalayıcı nesneyi metot içinde artırmak

`Integer wrap = 5;` satırında bir `int` değeri bir `Integer` değişkenine atanıyor. Hoca önceki derste söylediğini hatırlattı: Java bunu görünce 5 değerli bir `Integer` nesnesi oluşturmak istendiğini anlar ve bunu otomatik yapar. Buna boxing (kutulama) denir. Hoca bunu göstermek için satırı geçici olarak `Integer wrap = new Integer(5);` diye yazdı (ekrandan, 00:25:00); iki yazım aynı işi yapar. Sonuçta bellekte değeri 5 olan bir nesne oluşur ve `wrap` değişkeni bu nesneyi gösterir.

`this.sarmalayiciDuzenle(wrap)` çağrısında `sarmalayiciDuzenle(Integer x)` metodunun parametresi de bir `Integer`'dır. `wrap` ilkel olmadığı için metoda referansın değeri geçer. Hoca bunu bir adresle anlattı: nesne bellekte "xyz" konumundaysa metoda "xyz" geçer ve `x` de aynı nesneyi gösterir.

Metot içinde `x++` yazılmıştır. Bir değeri bir artırmak yalnız ilkel türde yapılabildiği için Java `Integer` nesnesini ilkel `int`'e çevirir (5), artırır (6) ve sonucu bir `Integer` nesnesine geri koyar. Hoca burada kendini düzeltti: bu işlem yeni bir nesne oluşturur ve `x` artık 6 değerli bu yeni nesneyi gösterir. `wrap` ise hâlâ 5 değerli eski nesneyi gösterir. Bu yüzden metottan sonra `wrap` yazdırıldığında yine 5 çıkar.

### 3.4 İki ilkel değeri metot içinde takas etmek

`int count1 = 1, count2 = 2;` ile iki değişken oluşturulur ve `this.ilkelDegistir(count1, count2)` çağrılır. İkisi de ilkel türde olduğu için metoda 1 ve 2 değerleri geçer; `ilkelDegistir(int x, int y)` içinde `x = 1`, `y = 2` olur.

Metot içinde bir `temp` değişkeni oluşturulur: `temp = x` (1), `x = y` (2), `y = temp` (1). Metodun içinde `x` ve `y` yer değiştirmiştir, ama `count1` ve `count2` değişmemiştir. Yazdırıldıklarında yine `1, 2` çıkar.

### 3.5 İki sarmalayıcı nesneyi metot içinde takas etmek

`Integer wrap1 = 1;` ve `Integer wrap2 = 2;` ile bellekte 1 ve 2 değerli iki `Integer` nesnesi oluşur; `wrap1` birincisini, `wrap2` ikincisini gösterir. `this.sarmalayiciDegistir(wrap1, wrap2)` çağrısında `x` ve `y` aynı nesnelerin adreslerini alır.

Metot içinde `temp = x; x = y; y = temp;` yazılır. Bu satırlar yalnız metodun yerel değişkenleri olan `x`, `y` ve `temp`'in gösterdiği adresleri değiştirir. Metottan dönüldüğünde `wrap1` ve `wrap2` hâlâ 1 ve 2 değerli nesneleri gösterir; çıktı değişmez.

### 3.6 sarmalayiciDegistirAlt: kutulamayı açıkça yazmak

`sarmalayiciDegistirAlt` metodu öncekinin aynısıdır; tek fark kutulamanın JVM'e bırakılmayıp `new Integer(...)` ile açıkça yazılmasıdır. Hoca Türkçe olarak da belirtti: birinde boxing işlemini JVM yapar, ötekinde biz açıkça nesneyi oluşturup içine değeri koyarız; iki metot arasında sonuç bakımından fark yoktur. Çağıranın değişkenleri yine değişmez.

### 3.7 swapForReal: üye alanları takas etmek

Son denemede sınıfın üye alanları `wrapI` ve `wrapJ` kullanılır. Altyazıya göre başlangıçta `wrapI` 3, `wrapJ` 5 değerli bir nesneyi gösterir. `swapForReal()` parametre almaz:

- `Integer temp = wrapI;` ile `temp` de `wrapI`'nin gösterdiği nesneyi (adres "xyz") gösterir.
- `wrapI = wrapJ;` ile `wrapI`'ye `wrapJ`'nin adresi ("abc") yazılır.
- `wrapJ = temp;` ile `wrapJ`'ye "xyz" yazılır.

Artık `wrapI` 5 değerli, `wrapJ` 3 değerli nesneyi gösterir. Bu değişiklik kalıcıdır, çünkü değiştirilen değişkenler metodun yerel kopyaları değil, nesnenin kendi alanlarıdır.

**Soru:** `swapForReal`'a hiçbir şey geçirmiyoruz. `tryMe` kapsamındaki değişkenlere parametre geçmeden nasıl erişebiliyoruz? Çağrıldığımız fonksiyonun değişkenlerine erişebilir miyiz? **Cevap:** `wrapI` ve `wrapJ` üye alanlardır (hoca "global member fields" diyor). Bir nesne verisini ve metotlarını içerir; nesnenin verisine o nesnenin bütün üye metotları erişebilir. `swapForReal` de bu nesnenin bir metodu olduğu için bu alanlara erişip onları güncelleyebilir.

**Soru:** Sınıfta global değişken tanımlamadan, bir değişkeni fonksiyona geçirip içinde takas etmek hiç mümkün değil mi? **Cevap:** Mümkün; hoca bunu birazdan göstereceğini söyledi (Bölüm 5'teki dizi örneği).

> **Ek bilgi (derste anlatılmadı):** Ajan sınıfı, görünmeyen kısmı altyazıdaki değerlerle (3 ve 5) tamamlayarak `java` ile çalıştırdı. İlk dört denemede "After" satırları "Before" satırlarıyla aynı çıktı (3; 5; 1, 2; 1, 2), `swapForReal` denemesinde ise `3, 5` → `5, 3` oldu. Güncel JDK'larda `new Integer(...)` yapıcısı kullanımdan kaldırılmak üzere işaretlidir ve derlemede uyarı verir; yerine `Integer.valueOf(...)` ya da otomatik kutulama kullanılır.

## 4. MethodParametersTest2: Aynı Metot İçinde Takas

İkinci sınıfta takas işlemi metoda gönderilmeden, aynı metodun içinde yapılır (ekrandan, 00:45:00 ve 00:50:00):

```java
package nyp01e;

public class MethodParametersTest2 {
    public void tryMe( ) {
        int x = 1, y = 2;
        System.out.println("Before : " + x + ", " + y );
        int temp;
        temp = x;
        x = y;
        y = temp;
        System.out.println("After: " + x + ", " + y );

        Integer sarma1 = 3;
        Integer sarma2 = 5;
        System.out.println("Before : " + sarma1 + ", " + sarma2 );
        Integer gecici = sarma1;
        sarma1 = sarma2;
        sarma2 = gecici;
        System.out.println("After: " + sarma1 + ", " + sarma2 );
    }
    public static void main(String[] args) {
        MethodParametersTest2 test = new MethodParametersTest2();
        test.tryMe();
    }
}
```

İlk kısımda `x` ve `y` yerel ilkel değişkenlerdir. `temp = x` ile `temp` 1, `x = y` ile `x` 2, `y = temp` ile `y` 1 olur. Çıktı önce `1, 2`, sonra `2, 1`'dir.

İkinci kısımda `sarma1` 3, `sarma2` 5 değerli bir `Integer` nesnesini gösterir. Hoca burada da `Integer sarma1 = 3;` satırının kutulama olduğunu, `new Integer(3)` yazmakla aynı olduğunu gösterdi. Ardından tahtaya üç değişken çizdi:

- `sarma1` → adres "xyz" (3 değerli nesne)
- `sarma2` → adres "abc" (5 değerli nesne)
- `gecici = sarma1` → `gecici`'ye "xyz" yazılır.
- `sarma1 = sarma2` → `sarma1`'e "abc" yazılır.
- `sarma2 = gecici` → `sarma2`'ye "xyz" yazılır.

Sonuçta `sarma1` 5 değerli, `sarma2` 3 değerli nesneyi gösterir. Nesnelerin içindeki değerler değişmemiş, değişkenlerin tuttuğu adresler yer değiştirmiştir. Hoca programı çalıştırdı: iki örnekte de değerler değişti. Bunun nedeni takasın parametre kopyalarında değil, metodun kendi değişkenlerinde yapılmasıdır. Ajan da kodu `java` ile çalıştırdı; çıktı `Before : 1, 2` / `After: 2, 1` / `Before : 3, 5` / `After: 5, 3` oldu.

**Soru:** Önceki kodda `main`'in içinde sınıfın nesnesini oluşturmak zorunda mıyız? **Cevap:** Evet. Nesne yönelimli programlamada her şey nesnelerle yapılır; aynı sınıfın metodunu kullanmak için bile önce sınıfın bir nesnesi oluşturulur ve metot o nesne üzerinden çağrılır. Nesne oluşturmadan çağırmanın tek yolu metodun `static` tanımlanmasıdır. `tryMe` `public static void tryMe()` diye tanımlansaydı `MethodParametersTest2.tryMe()` diye çağrılabilirdi. `main`'in o sınıfın içinde olup olmaması bu durumu değiştirmez.

> **Ders sonrası not:** Hocanın "aynı sınıfın metodunu kullanmak için bile nesne oluşturmak gerekir" sözü, sorulan durum olan static `main` içinden çağırma için doğrudur. Static olmayan bir metodun içinden aynı sınıfın başka bir static olmayan metodu nesne oluşturmadan, doğrudan ya da `this.` ile çağrılabilir; `tryMe()` içindeki `this.ilkelDuzenle(count)` çağrıları da böyledir, çünkü orada zaten bir nesne (`this`) vardır.

## 5. MethodParametersTest3: Dizinin Metoda Geçirilmesi

### 5.1 Kod

Üçüncü örnek (ekrandan, 00:55:00):

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
/* Using static has nothing to do with the
 * "call-by-value-of-references" issue. */
```

### 5.2 Bir dosyada iki sınıf

Bu dosyada iki sınıf vardır: `MethodParametersTest3` ve `LowHighSwap`. Hoca bunun mümkün olduğunu, ama bir `.java` dosyasında yalnız bir sınıfın `public` olabileceğini ve dosya adının bu public sınıfın adından geldiğini söyledi.

### 5.3 Dizi de bir referanstır

`int[] dizi = {1, 2, 3, 4, 5};` satırı bir nesne tanımlamaya benzer. Bellekte `dizi` adında bir değişken oluşur; bu değişken beş elemanlı dizinin bulunduğu adresi (hocanın örneğinde "abc") tutar. Nesne oluştururken nasıl asıl nesnenin yerini gösteren bir değişken oluşuyorsa, dizide de durum aynıdır.

`LowHighSwap` sınıfının `doIt` metodu `static` olduğu için nesne oluşturmaya gerek yoktur; metot doğrudan `LowHighSwap.doIt(dizi)` diye sınıf adıyla çağrılır. Metot bir `int` dizisi alır; çağrıda dizinin referansı ("abc") `z` parametresine kopyalanır. Artık `z` de aynı diziyi gösterir.

### 5.4 Adım adım

- `z.length` dizinin uzunluğunu, yani 5'i verir. `z.length - 1` = 4'tür. İndisler C'de olduğu gibi 0'dan başlar (0, 1, 2, 3, 4).
- `int temp = z[z.length - 1];` → 4 numaralı hücredeki 5 değeri `temp`'e atanır.
- `z[z.length - 1] = z[0];` → 0 numaralı hücredeki 1 değeri 4 numaralı hücreye yazılır; o hücre 5 iken 1 olur.
- `z[0] = temp;` → `temp`'teki 5, 0 numaralı hücreye yazılır; o hücre 1 iken 5 olur.

`z` ile `dizi` aynı bellek konumunu gösterdiği için bu değişiklikler `main`'deki diziye de yansır. Döngü `5 2 3 4 1` yazar: en düşük ve en yüksek indisteki değerler yer değiştirmiş, diğerleri değişmemiştir. Ajan da kodu `java` ile çalıştırdı ve aynı çıktıyı aldı.

Dosyanın sonundaki yorum, `doIt`'in `static` olmasının referansın değeriyle çağırma konusuyla bir ilgisi olmadığını belirtir. Hoca son olarak kodla anlattıklarının slaytlardakiyle aynı olduğunu söyledi.

## 6. Kontrol Akışını Değiştiren Yapılar

Slayt 63 (ekrandan, 01:00:00), Bilgisayar Bilimlerine Giriş derslerinden bilinen yapıların Java'da da benzer sözdizimiyle bulunduğunu söyler:

```text
DECISION MAKING - THE IF STATEMENT
if (condition) {...} else if (condition) {...} ... else (condition) {...}

  - Comparison: <  >  <=  >=  ==  !=
  - Double operator is used in logical operations: &&  ||

LOOPS
for( initialStatement; conditionStatement; incrementStatement ) { ... }
while( condition ) { ... }
do { ... } while( condition );
switch / case ...
```

`if` yapısı kontrol akışını farklı koşullara göre değiştirir. Koşullardan hangisi sağlanırsa yalnız onun kod bloğu çalışır, diğer bloklar çalışmaz. Koşullarda karşılaştırma işleçleri ve mantıksal "ve" (`&&`), "veya" (`||`) kullanılır. `switch / case` yapısında da bir koşul ve bu koşulun alabileceği farklı değerler için `case`'ler vardır; yine yalnız biri çalışır. Hoca `switch / case`'in derste ileride de kullanılacağını söyledi.

Döngülerde `for` bloğu, başlangıç ifadesinden başlayarak koşul doğru olduğu sürece çalışır; her turda artırma/azaltma ifadesi uygulanır. `while` döngüsü de koşul doğru olduğu sürece bloğu çalıştırır. `do-while` farklıdır: blok önce koşula bakılmadan bir kez çalışır, sonra koşul denetlenir; koşul doğruysa yeniden çalışır, değilse döngüden çıkılır. Bu yüzden `do-while` bloğu en az bir kez çalışır.

> **Ders sonrası not:** Slayttaki şablonda son kısım `else (condition) {...}` biçiminde yazılmış. Java'da son `else` koşul almaz; doğrusu `... else {...}`'dir. Koşullu bir dal gerekiyorsa `else if (condition) {...}` yazılır.

## 7. Nesneler Arası İlişkilere Giriş

Aradan sonra nesneler arası ilişkilere geçildi. Nesne yönelimli programlamada her nesnenin verisi ve metotları vardır; program, nesnelerin birbirinin metotlarını çağırmasıyla işini yapar.

Hoca ilişki türlerini şöyle sıraladı:

- Association (ilişkilendirme)
- Dependency (bağımlılık)
- Association'ın daha güçlü biçimleri: aggregation, ondan da güçlü composition
- Inheritance (kalıtım)

İki nesne arasında bir ilişki varsa biri diğerine mesaj gönderebilir. Mesaj göndermek, diğer nesnenin bir metodunu çağırmak demektir.

## 8. Association (Sahiplik) ve Gösterimi

### 8.1 Sahiplik

Slayt 67'ye göre association'ın özü sahipliktir (ownership): mesaj gönderebilen nesne, mesajı alan nesneyi bir üye alanı olarak tutar (ekrandan, 01:20:00). Örnek bir müşteri ve siparişleridir:

```text
+----------+  1     gives     *  +-------+
| Customer |-------------------->| Order |
+----------+                     +-------+
```

Müşteri nesnesi sipariş nesnelerine sahiptir, sipariş verir. Sahip olan (burada `Customer`), sahip olunan nesneye (burada `Order`) mesaj gönderebilir. Diyagramda ilişkinin mantıksal adı (`gives`) ve çoklukları da gösterilir.

### 8.2 Oklar

Slayt 68'deki gösterimler (ekrandan, 01:25:00):

| Çizim | Anlamı |
|---|---|
| `A ——name—— B` (oksuz düz çizgi) | Association; ilişkinin adı çizginin üstüne yazılabilir |
| `A ——> B` | A, B'ye sahiptir: A'nın örnekleri B'nin örneklerine mesaj gönderebilir |
| `A <——> B` | A, B'ye ve B, A'ya sahiptir: iki yönlü bağlantı |

Okun yönü önemlidir; kimin kime mesaj gönderebileceğini belirler. Hiç ok çizilmemişse ya iki yönlü bir bağlantı vardır ya da tasarımcı yönü henüz düşünmemiştir. Hoca "bir sınıfın örneği" (instance) ifadesinin nesne demek olduğunu hatırlattı.

İki yönlü ilişkiye hocanın örneği kişi ve arabadır: kişi bir arabaya sahip olabilir (bir tek yönlü ilişki), arabanın da sahibi olan bir kişi vardır (öbür tek yönlü ilişki). İkisi birbirinin nesnesini tuttuğu için ilişki iki yönlüdür.

### 8.3 Çokluk (cardinality)

İlişki çizgisinin uçlarında sayılar olabilir; bunlar o uçtaki nesne sayısını gösterir:

| Uçtaki işaret | Anlamı |
|---|---|
| `*` | 0 ya da daha çok |
| `1..*` | 1 ya da daha çok |
| `1` | yalnız 1 |
| `1..11` | 1'den 11'e kadar |

Hocanın örneği: bir kişi sıfır ya da daha çok arabaya sahip olabilir; bu durumda araba ucuna `*`, kişi ucuna `1` yazılır. `Customer 1 → * Order` diyagramı da bir müşterinin sıfır ya da daha çok sipariş verebileceğini söyler.

## 9. Gizli Bilgi ve Dependency (Bağımlılık)

### 9.1 Gizli bilgi

Slayt 69'a göre bir ilişki çizgi ve okla gösterilmişse sınıfın içindeki ayrıntılar yazılmayabilir; aşağıdaki iki diyagram aynıdır (ekrandan, 01:30:00):

```text
+----------+ 1   gives   * +-------+      +-------------------+ 1        * +-------+
| Customer |-------------->| Order |      | Customer          |------------>| Order |
+----------+               +-------+      +-------------------+             +-------+
                                          | - orders[] : Order|
                                          +-------------------+
```

Hoca sınıf gösterimini hatırlattı: en üst bölme sınıfın adı, ikinci bölme üye alanlar, üçüncü bölme üye metotlardır. Soldaki diyagramda yalnız sınıf adları ve ilişki vardır; sağdakinde `Customer` sınıfının üye alanı da yazılmıştır (metotlar yazılmamıştır). Okun ucundaki `*`, birinci nesnenin ikinci sınıfın sıfır ya da daha çok nesnesini tutabilecek bir veri yapısına sahip olduğu anlamına gelir; burada bu veri yapısı bir dizidir. UML diyagramlarında bilgi gizlenebilir, ama `*` görüldüğünde birinci sınıfta böyle bir veri yapısı olduğu hemen anlaşılmalıdır.

### 9.2 Dependency

Association'da ikinci nesne, birinci nesnenin üye alanlarında geçmek zorundadır. Dependency'de ise ikinci sınıf yalnız birinci sınıfın bir metodunun içinde geçer. Slayt 69'a göre bağımlılığın özü ya bir metodun parametresi olmak ya da sahiplik olmadan geçici kullanımdır (ekrandan, 01:30:00):

```text
+----------------------+
| A                    |
+----------------------+            +---+
|                      | - - - - - >| B |
+----------------------+            +---+
| + aMethod( b : B )   |
+----------------------+
```

A, B'ye bağımlıdır: A'nın örnekleri `aMethod` gövdesinde B'nin örneklerine mesaj gönderebilir. Gösterimde düz değil kesikli ok kullanılır. B'nin nesneleri A'nın üye alanlarında geçseydi ilişki association olurdu.

## 10. Tek Yönlü Association'ın Kodlanması

### 10.1 Diyagram

Slayt 70'teki örnekte her kişinin bir arabası olabileceği bir alan modeli (domain model) ve bu modeli kullanan bir program vardır. Program çalıştırılabilmesi için bir `main` metoduna sahip olmalıdır; slayt, modelin ve programın ayrı paketlerde olması gerektiğini de söyler (ekrandan, 01:35:00).

```text
paket nyp02

+-----------------------------+
| Person                      |
+-----------------------------+  1   owns
| - name : String             |------------------+
| - car : Car                 |                  |
+-----------------------------+                  v  0..1
| + Person( name : String )   |           +------------------------+
| + getName( ) : String       |           | Car                    |
| + getCar( ) : Car           |           +------------------------+
| + setCar( Car )             |           | - plate : String       |
| + introduceSelf( ) : String |           +------------------------+
+-----------------------------+           | + Car( String )        |
              ^                           | + getPlate( ) : String |
              : (kesikli)                 +------------------------+
+------------------------+                          ^
| MainProgram01          |- - - - - - - - - - - - - +
+------------------------+       (kesikli)
| + main( String[ ] )    |
+------------------------+
```

`Person` sınıfının iki private üye alanı vardır: `String` türünde `name` ve `Car` türünde `car`. Hoca, bir sınıfın üye alanlarında başka bir sınıfın nesnesi görüldüğünde orada bir association, yani sahiplik ilişkisi olduğunun hemen anlaşılması gerektiğini söyledi. Metotlar: tek parametreli bir yapıcı, `name` için getter, `car` için getter ve setter, ayrıca `introduceSelf()`. `Car` sınıfında yalnız `String` türünde `plate` alanı, tek parametreli yapıcı ve `plate` için getter vardır.

`MainProgram01` sınıfında `Person` ve `Car` sınıfları üye alanlarda ya da parametrelerde değil, `main` metodunun gövdesinde geçer. Bu yüzden `MainProgram01` bu iki sınıfa bağımlıdır (kesikli oklar).

### 10.2 Neden 0..1?

Slayt "Neden association'da 0..1 var? Gizli bilgi: `Car` sınıfının yapıcısına bakın" diye sorar. Hoca önce "sıfır ya da daha çok" diye başladı, sonra açıkladı: `Person` içinde araba dizisi değil tek bir `car` alanı vardır; dizi olsaydı uca `*` yazılırdı. Program yazılırken bir kişinin yalnız bir arabası olabileceği düşünülmüştür. Ayrıca `Person` yapıcısı bir `Car` nesnesi istemez; kişi nesnesi oluşturulduğunda arabası olmak zorunda değildir. Sonuç olarak bir kişinin sıfır ya da bir arabası olabilir.

### 10.3 Person sınıfının kodu

Slayt 72 (ekrandan, 01:40:00):

```java
package nyp02;
public class Person {
   private String name;
   private Car car;

   public Person( String name ) {
         this.name = name;
   }
   public String getName( ) { return name; }
   public Car getCar( ) { return car; }
   public void setCar( Car car ) { this.car = car; }

   public String introduceSelf( ) {
         String intro;
         intro = "Hello, my name is " + getName();
         if( car != null )
             intro += "and I have a car with license plate "
             + car.getPlate()+ ".";
         return intro;
   }
}
```

Üye alanların başındaki `-` işareti diyagramda private demektir; kodda da alanlar `private` tanımlanmıştır. Hoca kodu sınıf diyagramına bakarak yazdığını söyledi. `Car` sınıfı da basittir: bir üye alan, tek parametreli yapıcı ve bir getter; önceki derslerde görülen en basit sınıf yapısıdır.

`introduceSelf()` metodu yerel bir `intro` değişkenine bir metin atar, sonra `if` ile `car` nesnesinin oluşturulup oluşturulmadığını (başlatılıp başlatılmadığını) denetler. Kişi oluşturulduğunda arabası olmayabileceği için bu denetim gereklidir. Araba yoksa onun bir metodu çağrılamaz; çağrılırsa `NullPointerException` hatası alınır. Araba varsa `car.getPlate()` ile plaka alınır, `intro`'ya eklenir ve `intro` döndürülür.

> **Hocanın vurgusu:** Association ilişkisini kullanırken ikinci nesnenin bir metodunu çağırıyorsanız, bu nesnenin oluşturulup oluşturulmadığını mutlaka denetlemeniz gerekir. Hoca bu denetimin kodda görülmemesi durumunda sınavda puan kıracağını söyledi.

Hoca hatanın türünü de açıkladı: bu bir çalışma zamanı hatasıdır. Nesne kodun bir yerinde oluşturulmuşsa ve sonra `getPlate` çağrılırsa hata çıkmaz; ama nesne oluşturulmadan `getPlate` çağrılırsa program çalışırken `NullPointerException` verir.

### 10.4 null denetimi nasıl okunur?

Nesnenin oluşturulup oluşturulmadığı `null` ile karşılaştırılarak anlaşılır:

| Durum | `nesne == null` | `nesne != null` |
|---|---|---|
| Nesne kodda daha önce oluşturulmuş | yanlış | doğru |
| Nesne oluşturulmamış | doğru | yanlış |

`introduceSelf()` içinde metodu çağırabilmek için `car != null` koşulunun doğru olması istenir.

> **Ders sonrası not:** Slayttaki kodda `"Hello, my name is " + getName()` ile `"and I have a car with license plate "` metinleri arasında boşluk yoktur. Ajan kodu çalıştırdığında çıktı `Hello, my name is Oktay Sinanoğluand I have a car with license plate 06 OS 1934.` gibi bitişik çıktı. Okunaklı çıktı için ikinci metin `" and I have a car ..."` diye boşlukla başlamalıdır.

### 10.5 MainProgram01

`MainProgram01`'in kodu karelerde görünmüyor; aşağıdaki akış hocanın anlatımından kurulmuştur.

<!-- BELİRSİZ: MainProgram01'in tam kodu (slayt 73) hiçbir karede görünmüyor; değişken adları ve değerler altyazıdan ve sonraki slaytlardaki benzer koddan çıkarıldı. -->

- `Person` türünde bir değişken tanımlanır, `new` ile bir kişi nesnesi oluşturulur ve referansı bu değişkene atanır.
- `new` ile bir `Car` nesnesi oluşturulur (plakası yapıcıya verilir) ve referansı `Car` türündeki `rover` değişkenine atanır.
- Kişi nesnesinin `setCar` metoduyla `rover`'ın referansı kişinin `car` alanına yazılır. Artık birinci nesne (kişi), ikinci nesneyi (araba) gösterir.
- Kişinin `introduceSelf()` metodu çağrılır. `intro`'ya "Hello, my name is" ve kişinin adı atanır; `car` başlatılmış olduğu için `if` bloğu da çalışır ve plaka bilgisi eklenir.
- İkinci bir kişi nesnesi oluşturulur, ama bu kez `setCar` çağrılmaz. Bu kişinin `introduceSelf()` metodu çağrıldığında `car` alanı başlatılmamış olduğu için koşul yanlış olur, `if` bloğu çalışmaz ve yalnız "Hello, my name is ..." ile ad döndürülür.

Hoca programı Eclipse'te çalıştırdı: birinci kişi için plaka bilgisi de yazıldı, ikinci kişi için yalnız kişinin kendi bilgisi yazıldı.

## 11. Sıralama Diyagramları

<!-- BELİRSİZ: Slayt 74-75'teki sıralama diyagramları hiçbir karede görünmüyor; aşağıdaki anlatım yalnız altyazıdan kurulmuştur. -->

### 11.1 introduceSelf'in sıralama diyagramı

Diyagramda bir kişi nesnesi ve bir araba nesnesi vardır; kişi nesnesinin metodu `MainProgram`'ın `main` metodundan çağrılır (o da bir nesne olarak gösterilir). Akış şöyledir:

- `main` kişi nesnesinin `introduceSelf()` metodunu çağırır.
- Kişi nesnesi kendi `getName()` metodunu çağırır. Bu aynı nesnenin metodu olduğu için diyagramda kişi nesnesinin kod bloğunun üstünde, kendine dönen bir çağrı olarak gösterilir.
- Kod ne diyorsa o yapılır: `if` içinde araba nesnesinin `getPlate()` metodu çağrılır ve bir `String` döner. Bu değer `intro`'ya eklenir ve `intro` çıktı olarak döndürülür.
- Diyagramda koşul da yazılır: arabanın var olup olmadığı denetlenir, koşul `car != null`'dır; `null` değilse `getPlate` çağrılabilir. Hoca, kodda böyle bir koşul varsa UML diyagramında da gösterilmesi gerektiğini söyledi.

### 11.2 main metodunun sıralama diyagramı

`main` metodunu kimin çağırdığını hatırlatmak için hoca ders notlarının başındaki Java çalışma ortamı slaytına döndü (ekrandan, 01:50:00):

```text
Source code --Compiler/compilation--> Compiled code --Linker/linking--> Executable code --OS--> Execution
   (.java)        (javac.exe)            (.class)
Compiled code --Interpretation (Interpreter)--> Execution

JDK: Java Development Kit            Java Virtual Machine (JVM)
  - Includes javac.exe                 - java.exe/javaw.exe: for command line/GUI apps
  - Optionally excludes IDE            - is included in JRE (Java Runtime Environment)

JDK is for developers and JRE is for end-users. JDK includes JRE.
```

Java kodu `javac.exe` derleyicisiyle `.class` dosyasına çevrilir, sonra JVM (`java.exe`) bu `.class` dosyasını çalıştırır. `java.exe` bir `.class` dosyasını çalıştırdığında o sınıftaki `main` metodunu çalıştırır. Yani `main`'i JVM çağırır.

`main`'in sıralama diyagramı kod satır satır okunarak çizilir:

- `main` önce bir kişi nesnesi oluşturur. Bu nesne ayrı bir sütun olarak gösterilir. Nesne oluşturmak yapıcıyı çağırmaktır; bu `new` anahtar sözcüğüyle yapılır. Nesne oluşur ve kontrol `main`'e döner.
- Ardından araba nesnesi `rover` oluşturulur; o da ayrı bir sütundur. Yapıcı `new` ile çağrılırken plaka numarası verilir.
- `main`, kişi nesnesinin `setCar` metodunu çağırır; parametre olarak `rover` gönderilir ve araba nesnesinin referansı kişi nesnesine yazılır.
- `main`, kişinin `introduceSelf()` metodunu çağırır. Bütün çağrılar `main` metodundan yapılır, çünkü `main` `MainProgram` sınıfının içindedir.
- İkinci kişi nesnesi oluşturulur; bu nesne birincisinden farklı olduğu için adıyla ayrı bir sütunda gösterilir. Yapıcı `new` ile çağrılır, sonra `introduceSelf()` çağrılır.
- `main` bitince çalışma tamamlanır ve kontrol JVM'e döner.

> **Hocanın vurgusu:** Sınavda "bu metot için UML sıralama diyagramını çizin" diye sorulduğunda böyle yapılmalıdır: kod satır satır okunur, okundukça nesneler arasındaki metot çağrıları çizilir. Metot gövdesi bittiğinde sıralama diyagramı da bitmiş olur.

## 12. Diyagramdan Kodu Okumak

Slayt 78, bazı gerçekleştirme ayrıntılarının sınıf diyagramlarında gizlenebileceğini ve üç grupta üstteki çiftin alttaki çifti ima ettiğini söyler (ekrandan, 01:55:00). Slayttaki not da (Türkçe) üstteki ilişkilerin kapalı/gizli, alttakilerin açık gösterildiğini belirtir.

| Grup | Üstteki (gizli) çizim | Alttaki (açık) çizim |
|---|---|---|
| 1 | `A 1 ——> 2 B` | `A` içinde `- b1, b2 : B`, aynı ok |
| 2 | `A 1 - - -> 1 B` (kesikli) | `A` içinde `+ metot( b: B )`, aynı kesikli ok |
| 3 | A tarafında boş elmas, B tarafında `*`: `A ◇—— * B` | `A` içinde `- b[ ] : B`, aynı çizgi |

- Birinci grupta A, B'ye sahiptir ve bir A nesnesi iki B nesnesine sahiptir. Ayrıntı verilmek istenirse A'nın üye alanlarında B türünde iki değişken olduğu yazılır. İki gösterim de doğrudur; hoca bazen sade bir diyagram için üsttekini, bazen ayrıntılı diyagram için alttakini tercih ettiğini söyledi.
- İkinci grupta kesikli ok bağımlılıktır: B, A'nın bir metodunun argüman kısmında geçer. Bu yüzden A'nın nesneleri B'nin nesnelerine bağımlıdır.
- Üçüncü grupta da bir association vardır, ama A tarafında `1` yerine elmas işareti kullanılmıştır. Hoca bazı kitap ve kaynakların `1` yerine elmas kullandığını, bunun da doğru olduğunu söyledi. Ayrıntılı gösterimde A'nın üye alanlarında B türünde bir dizi olduğu yazılır; yani A'nın nesneleri B'nin sıfır ya da daha çok nesnesini tutabilir.

**Soru:** Üstteki diyagram daha koyu, alttaki daha açık görünüyor; aralarında bir fark var mı? **Cevap:** Hiçbir fark yok. İki çizim arasındaki tek fark, alttakinde ilişkinin açıkça gösterilmesidir. Hoca bunu göstermese bile öğrencinin anlaması gerektiğini söyledi: birinci gruptaki ilişki görülünce A'nın üye alanlarında B'nin geçtiği ve iki tane olduğu için B türünde iki değişken bulunduğu anlaşılmalıdır. Kesikli çizgi görülünce B'nin üye alanlarda değil metotlarda, metodun argümanlarında ya da gövdesindeki kod bloğunda geçtiği anlaşılmalıdır. Üçüncü gruptaki çizim görülünce A'nın üye alanlarında sıfır ya da çok sayıda B nesnesi tutabilecek bir veri yapısı olduğu anlaşılmalıdır. Şimdilik bu veri yapısı dizidir; ileride başka veri yapıları da öğrenilecektir.

## 13. Klavyeden Girdiyle Tek Yönlü Örnek

Hoca Eclipse'e dönüp tek yönlü örneği yeniden gösterdi: `Person`'da tek bir `car` alanı vardır, yapıcı arabayı parametre olarak almaz ve `introduceSelf()` araba nesnesinin metodunu çağırmadan önce nesnenin başlatılıp başlatılmadığını denetler. `Car` sınıfı değişmemiştir. Sonra aynı paketteki `MainProgram02`'yi açtı (ekrandan, 02:05:00):

```java
package nyp02;
import java.util.*;
public class MainProgram02 {

    public static void main(String[] args) {
        //System.out.println(args[0] + " " + args[1]);
        Scanner gir = new Scanner(System.in);
        Person oktay;
        System.out.print("Kisi ismi girin: ");
        String str = gir.nextLine();
        oktay = new Person( str );
        System.out.print("Kisinin arabasi var mi (e/h)");
        String secim = gir.nextLine();
        if( secim.contains("e") || secim.contains("E") ) {
            System.out.print("Aracin plakasini gir");
            Car rover = new Car( gir.nextLine() );
            oktay.setCar( rover );
        }
        System.out.println( oktay.introduceSelf() );
        gir.close();
    }

}
```

Önceki derslerden bilinen `Scanner` nesnesi klavyeden girdi almak için kullanılır; `System.in` girdi olarak verilerek oluşturulur ve adresi `Scanner` türündeki `gir` değişkenine atanır. Program önce kişinin adını ister ve bu adla bir `Person` nesnesi oluşturur. Sonra kişinin arabası olup olmadığını sorar. Cevap büyük ya da küçük `e` içeriyorsa plakayı ister, bu plakayla bir `Car` nesnesi oluşturur, `rover` değişkenine atar ve `setCar` ile kişiye bağlar. `if` bloğundan sonra `introduceSelf()` çağrılır, dönen metin konsola yazılır ve `Scanner` nesnesi kapatılır.

Hoca programı çalıştırdı: bir ad girdi, arabası var mı sorusuna küçük `e` ile cevap verdi ve bir plaka girdi. Program `if` bloğunu çalıştırdı, araba nesnesini oluşturup kişiye bağladı ve `introduceSelf()` çıktısında plakayı da yazdı.

## 14. İki Yönlü Association

### 14.1 Model

Bu örnekte kişi sınıfının nesneleri araba sınıfının nesnelerine, araba sınıfının nesneleri de kişi sınıfının nesnelerine sahiptir. Diyagramda ok iki uçta da vardır. Hoca önce "bir kişinin sıfır ya da çok arabası, bir arabanın sıfır ya da çok sahibi olabilir" dedi, sonra diyagramdaki çokluğun "sıfır ya da bir" olduğunu, yani bir nesnenin diğerinden sıfır ya da bir tane tutabileceğini söyledi. `MainProgram` iki sınıfa da bağımlıdır, çünkü ikisi de `main` gövdesinde geçer.

<!-- BELİRSİZ: İki yönlü association'ın sınıf diyagramı (slayt 79-80) hiçbir karede görünmüyor; çokluklar altyazıdan alındı. -->

### 14.2 Yeni Car sınıfı

`Person` sınıfı değişmez. `Car` sınıfına `Person` türünde bir `owner` alanı eklenir (ekrandan, 02:20:00):

```java
package nyp03;
public class Car {
   private String plate;
   private Person owner;

   public Car( String plate ) { this.plate = plate; }
   public Car( String plate, Person owner ) {
        this.plate = plate;
        this.owner = owner;
   }
   public void setOwner( Person owner ) { this.owner = owner; }
   public Person getOwner() { return owner; }
   public String getPlate( ) { return plate; }
   public void setPlate( String plate ) { this.plate = plate; }
   public String introduceSelf( ) {
        String intro;
        intro = "[CAR] My license plate is " + getPlate();
        if( owner != null )
             intro += " and my owner is " + owner.getName();
        return intro;
   }
}
```

Artık `Car` sınıfının iki yapıcısı vardır: biri yalnız plakayı, öbürü plakayı ve `Person` türündeki sahibi alır. Hoca neden tek yapıcı olmadığını sordu ve şöyle açıkladı: fabrikadan çıkan bir arabanın henüz sahibi olmayabilir; bu durumda tek parametreli yapıcı kullanılır. Bazen insanlar arabayı önceden satın aldığı için araba fabrikadan çıktığında sahibi bellidir; bu durumda iki parametreli yapıcı kullanılır.

`owner` ve `plate` alanlarının her biri için getter ve setter vardır.

> **Hocanın vurgusu:** Hoca sınavda bütün üye alanlar için getter ve setter metotlarının yazılmasını isteyeceğini, yazılmazsa puan kaybedileceğini söyledi.

`Car`'ın `introduceSelf()` metodu da önce kendi plakasını `intro`'ya yazar. Sahibin `getName()` metodunu çağırmadan önce `owner`'ın başlatılıp başlatılmadığını denetler; `null` değilse JVM'de bir sahip nesnesi vardır ve metodu çağrılabilir.

> **Hocanın vurgusu:** Kodunuzda association kullanıyorsanız ve diğer nesnenin metodunu çağırmadan önce bu denetimi yapmazsanız sınavda puan kaybedersiniz. Association'da bu denetim çok önemlidir.

### 14.3 İlk main metodu

Slayt 83'teki program (ekrandan, 02:25:00):

```java
package nyp03;
public class MainProgram02 {
public static void main(String[] args) {
        Person oktay = new Person("Oktay Sinanoğlu");
        Car rover = new Car("06 OS 1934");
        oktay.setCar(rover);
        rover.setOwner(oktay);
        System.out.println( oktay.introduceSelf() );
        System.out.println( rover.introduceSelf() );

        Person aziz = new Person("Aziz Sancar");
        Car honda = new Car("47 AZ 1946");
        aziz.setCar(honda);
        honda.setOwner(aziz);
        System.out.println( aziz.introduceSelf() );
        System.out.println( honda.introduceSelf() );
   }
}
```

Hoca sınıfın adının `MainProgram03` olması gerektiğini de söyledi. Kod bir kişi ve bir araba nesnesi oluşturur, `setCar` ile arabayı kişiye, `setOwner` ile kişiyi arabaya bağlar. Bellekte birbirini gösteren iki nesne olur. Kişinin `introduceSelf()` metodu yalnız kendini değil arabasını da tanıtır; arabanınki de yalnız kendini değil sahibini de tanıtır. Aynı işlem ikinci kişi ve ikinci araba için tekrarlanır.

Ajan sınıfları çalıştırdı; çıktının iki satırı şöyledir:

```text
Hello, my name is Oktay Sinanoğluand I have a car with license plate 06 OS 1934.
[CAR] My license plate is 06 OS 1934 and my owner is Oktay Sinanoğlu
```

### 14.4 Kodu iyileştirmek: set metotlarının birbirini çağırması

Hoca "bu kodu nasıl iyileştirebilirim?" diye sordu. 6. ve 7. satırlarda iki yönlü ilişkiyi kurmak için iki satır yazılmaktadır. Bunlardan biri unutulursa, iki yönlü ilişki istenmiş olsa bile yalnız tek yönlü bir ilişki kurulur. Amaç, tek bir satırla iki yönlü ilişkiyi kurmaktır.

Çözüm, kişideki `setCar` ve arabadaki `setOwner` metotlarını güncellemektir (ekrandan, 02:30:00):

```java
package nyp03b;
public class Person {
        /*the rest is the same*/
        public void setCar( Car car ) {
                this.car = car;
                if( car.getOwner() != this )
                        car.setOwner(this);
        }
}

package nyp03b;
public class Car {
        /*the rest is the same*/
        public void setOwner( Person owner ) {
                this.owner = owner;
                if( owner.getCar() != this )
                        owner.setCar(this);
        }
}
```

Hoca bunu ikinci kişi ve araba üzerinden anlattı. `aziz` nesnesine `honda` atanmak isteniyor ve `honda`'nın referansı `setCar`'a gönderiliyor. Metot önce `this.car = car` ile arabayı kişiye yazar. Sonra arabanın sahibine bakar: sahibi `this`'ten (yani `aziz`'den) farklıysa arabanın `setOwner` metodunu `this` ile çağırır ve arabaya "bundan sonra senin sahibin benim" der. Aynı mantık `Car`'ın `setOwner` metodunda da vardır: sahip yazıldıktan sonra sahibin arabası bu araba değilse sahibin `setCar` metodu bu arabayla çağrılır.

Böylece `oktay.setCar(rover)` çağrıldığında alttaki `rover.setOwner(oktay)` satırına gerek kalmaz; tek satır iki yönü de kurar.

**Soru:** Oradaki `if` denetimini yapmak şart mı? Olmasa da olur gibi. **Cevap:** Hoca önce denetim gerektiğini söyledi, sonra açıkladı: `honda`'nın sahibi zaten `aziz` ise denetim olmadan set metodu yeniden çağrılır ve aynı değer üzerine yazılır. Sahibi `aziz`'den farklıysa yeni sahip yazılır. Denetim olmadan her durumda atama yapıldığında da sonuç aynı çıkar; öğrenci bu konuda haklıdır. Denetimin kazancı, araba zaten bu kişiye aitse üzerine yeniden yazmamaktır.

> **Ek bilgi (derste anlatılmadı):** Bu iki metotta `if` denetimi ayrıca karşılıklı çağrının sonsuza gitmesini de durdurur. Denetim kaldırılıp iki metot da koşulsuz olarak karşı tarafın set metodunu çağırsaydı `setCar` → `setOwner` → `setCar` → ... zinciri hiç bitmez ve büyük olasılıkla `StackOverflowError` ile sonlanırdı. Ayrıca bu sürümde `setCar(null)` çağrılırsa `car.getOwner()` satırı `NullPointerException` verir; derste bu durum konuşulmadı.

### 14.5 İlişkiyi yapıcıda kurmak

Bir adım daha: `setOwner` çağrısı `Car`'ın iki parametreli yapıcısının içine konursa, sahibi olan bir araba nesnesi oluşturulduğu anda araba ile kişi arasında iki yönlü ilişki kendiliğinden kurulur. Benzer şekilde, kişi oluşturulurken araba da veriliyorsa `Person` yapıcısına `setCar` konabilir; bu örnekte böyle bir yapıcı yoktur. Hoca böylece önce iki satırı tek satıra indirdiğini, sonra o tek satırı da yapıcıya taşıyarak kaldırdığını söyledi. Sonuç slayt 87'deki programdır (ekrandan, 02:40:00):

```java
package nyp03c;
public class MainProgram03 {
      public static void main(String[] args) {
            Person oktay = new Person("Oktay Sinanoğlu");
            Car rover = new Car("06 OS 1934", oktay);
            System.out.println( oktay.introduceSelf() );
            System.out.println( rover.introduceSelf() );
      }
}
```

Araba nesnesinin yapıcısı çağrıldığı anda yapıcının içindeki `setOwner` sayesinde arabaya kişi, kişiye de araba tanıtılmış olur. Artık `oktay.introduceSelf()` hem kişiyi hem `rover`'ı, `rover.introduceSelf()` hem arabayı hem sahibini tanıtır.

<!-- BELİRSİZ: Yapıcının değiştirilmiş hâli (setOwner çağrısını içeren iki parametreli Car yapıcısı, slayt 86) karelerde görünmüyor; hocanın anlatımına göre yapıcıda setOwner(owner) çağrılıyor. -->

> **Ek bilgi (derste anlatılmadı):** Ajan, iki parametreli yapıcıyı `this.plate = plate; setOwner(owner);` biçiminde yazıp `nyp03b`'deki set metotlarıyla birlikte `java` ile çalıştırdı. İki `introduceSelf()` çıktısı da karşı nesnenin bilgisini içerdi; yani tek satırlık `new Car("06 OS 1934", oktay)` iki yönlü ilişkiyi kurdu.

### 14.6 Önce tek yönlü ilişkiyle başlayın

> **Hocanın vurgusu:** İki yönlü association'ı gerçekleştirmek biraz daha zordur, çünkü hatırlanması gereken şeyler vardır: set metodunda yalnız kendi alanını değil, karşı nesnenin alanını da set metoduyla ayarlamak; nesne oluşturulduğu anda ilişkinin kurulması için yapıcılardan birine set çağrısı koymak. Bunlar kod yazarken unutulabilir. Yapmak istediğiniz şey tek yönlü ilişkiyle yapılabiliyorsa önce tek yönlü ilişkiyle başlayın; gerçekten iki yönlü ilişkiye ihtiyaç olduğunu görürseniz ona geçin.

## 15. Aggregation ve Composition

### 15.1 Güç sırası

Aggregation ve composition da birer association'dır. Fark güçlerindedir: aggregation association'dan biraz daha güçlü, composition da aggregation'dan biraz daha güçlüdür. Hoca Türkçe olarak özetledi: association sahiplik ilişkisidir; aggregation onun bir tık daha güçlüsü, composition da onun bir tık daha güçlüsüdür.

### 15.2 Aggregation

Aggregation bir bütün-parça (whole-part) ilişkisidir. Hocanın örneği otobüs hattı ve duraktır. Bir otobüs hattı duraklardan oluşur; hiç durağı olmayan bir hattan söz edilemez. En basit hat bir başlangıç ve bir varış noktasından oluşur, bu yüzden bir hattın en az iki durağı olmalıdır; arada başka duraklar da olabilir.

Association'da böyle bir gereklilik yoktu: bir müşterinin hiç siparişi olmayabilir ya da çok siparişi olabilir. Aggregation'da da bir sahiplik vardır, ama ek bir gereklilik getirir: ikinci türdeki nesnelerin en az belli sayıda (bu örnekte iki) bulunması. Öte yandan bir otobüs durağı birden fazla otobüs hattının üzerinde olabilir; aggregation'da bu konuda bir kısıt yoktur.

<!-- BELİRSİZ: Aggregation slaytı (slayt 89) ve otobüs hattı-durak diyagramındaki çokluklar hiçbir karede görünmüyor; yukarıdaki anlatım altyazıdan alındı. -->

> **Ders sonrası not:** Hoca aggregation'ı association'dan ayıran şeyi "ikinci nesne için bir alt sınır gerekliliği" olarak anlattı. UML'de aggregation'ı ayıran şey büyük olasılıkla bütün-parça anlamıdır (diyagramda bütünün tarafında boş elmas); en az iki durak koşulu ise bu örnekte çizgiye yazılan çokluktan (örneğin `2..*`) gelir. Alt sınır her aggregation'da bulunmak zorunda değildir.

### 15.3 Composition

Composition aggregation'a bir kısıt daha ekler: ikinci türdeki bir nesne birinci türün yalnız bir nesnesine ait olabilir. Slayt 90 (ekrandan, 02:45:00):

```text
COMPOSITION
- Similar to aggregation, but represents a stronger whole-part relation.

   +---+          +---+
   | A |◆-------->| B |
   +---+          +---+
    Composition

- The strength of composition over aggregation is that in composition,
  the part can only belong to one whole at the same time.
- Example:

   +------+ 1          * +--------+
   | Team |◆------------>| Player |
   +------+              +--------+
```

Hocanın örneği takım ve oyuncudur. Bir takımda bir ya da daha çok oyuncu olabilir, ama bir oyuncu yalnız bir takıma ait olabilir; birden fazla takımda oynayamaz. Hoca association'da çokluğu gösterirken bazen `1`, bazen elmas, bazen ikisinin birlikte kullanıldığını hatırlattı. Composition'da ise içi dolu (koyu) elmas kullanılır; bu, ikinci nesnenin A türündeki nesnelerden yalnız birine ait olabileceğini gösterir. Dolu elmasın yanında `1` de yazılabilir. Otobüs örneğiyle karşılaştırınca: bir durak birden çok hatta bulunabildiği için hat-durak ilişkisi aggregation'dır; bir oyuncu yalnız bir takımda olabildiği için takım-oyuncu ilişkisi composition'dır.

### 15.4 Veri yapıları

Aggregation ve composition diyagramlarında genellikle `*` vardır. Bu, birinci sınıfta ikinci türden sıfır ya da daha çok, bir ya da daha çok ya da iki ya da daha çok nesne tutan bir veri yapısı olacağı anlamına gelir. Şimdiye kadar veri yapısı olarak dizi görüldü; ama bu yapı liste, yığın (stack), kuyruk (queue) vb. de olabilir. Bu veri yapıları dersin ikinci kısmında ayrıntılı işlenecektir.

### 15.5 Sıradaki örnek

Ders, composition'ın kodlanmasıyla ilgili slayt 92'de bitti (ekrandan, 02:50:00). Slayttaki örnek birden çok satılık araba tutan bir `Gallery` sınıfıdır:

- `Car` sınıfı yeniden kullanılacaktır. Yalnız plakayı parametre alan bir yapıcı eklemek istenebilir; slayt yazarı bunu yapmamayı seçmiş, galeriye geçici bir sahip olarak bir `Person` örneği atanabileceğini belirtmiştir.
- Galeri ile arabalar arasındaki ilişki composition ile gösterilmiştir; bu ilişki `1..*` association ile de gösterilebilir, fark etmez.
- Örnek ayrıca dizileri ve `for` döngüsünü de gösterir.

Hoca bir sonraki derste önce bu composition örneğinin çalışılacağını, sonra kodlarına bakılacağını söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 01:35:00): Tek yönlü `Person 1 owns → 0..1 Car` diyagramında association'ın `Car` ucunda neden `0..1` yazıyor? (İpucu: gizli bilgi, `Car` sınıfının yapıcısına bakın.)

> **Çözüm (derste verilen):** `Person` sınıfında araba dizisi değil tek bir `car` alanı vardır; dizi olsaydı `*` yazılırdı. Bu yüzden bir kişinin en çok bir arabası olabilir. `Person(String name)` yapıcısı araba istemez; kişi nesnesi arabasız oluşturulabilir. Bu yüzden alt sınır 0'dır. Sonuç `0..1`'dir. Bu nedenle `introduceSelf()` içinde `car != null` denetimi gerekir.

**Soru 2** (derste sözlü, 01:28:13): `Customer 1 → * Order` diyagramında `Customer` sınıfının içi gösterilmemişse, sınıfın üye alanları hakkında ne söylenebilir?

> **Çözüm (derste verilen):** `*` çokluğu, `Customer`'ın sıfır ya da daha çok `Order` nesnesini tutabilecek bir veri yapısına sahip olduğunu gösterir. Bu ayrıntı gizlenmiş olsa da anlaşılmalıdır; açık gösterimde `Customer` içinde `- orders[] : Order` gibi bir dizi alanı yazılır.

**Soru 3** (ekrandan, 01:55:00): Aşağıdaki üç gizli gösterimin her biri A sınıfının içi hakkında ne söyler? (a) `A 1 ——> 2 B`, (b) `A 1 - - -> 1 B` (kesikli), (c) A tarafında boş elmas, B tarafında `*` olan çizgi.

> **Çözüm (derste verilen):** (a) A'nın üye alanlarında B türünde iki değişken vardır: `- b1, b2 : B`. (b) B, A'nın üye alanlarında değil, bir metodunun argümanında ya da gövdesinde geçer: örneğin `+ metot( b: B )`. (c) A'nın üye alanlarında B nesnelerini tutan bir veri yapısı vardır: `- b[ ] : B`.

**Soru 4** (derste sözlü, 02:21:07): İki yönlü örnekteki `Car` sınıfında neden hem tek parametreli hem iki parametreli yapıcı var; tek yapıcı yetmez mi?

> **Çözüm (derste verilen):** Araba nesnesi oluşturulduğunda sahibi olabilir de olmayabilir de. Fabrikadan çıkan bir arabanın henüz sahibi yoksa yalnız plakayı alan yapıcı kullanılır. Araba önceden satılmışsa sahibi bellidir ve plaka ile sahibi alan iki parametreli yapıcı kullanılır.

**Soru 5** (derste sözlü, 02:27:15): Slayt 83'teki programda iki yönlü ilişki iki satırla (`oktay.setCar(rover);` ve `rover.setOwner(oktay);`) kuruluyor. Bu kod nasıl iyileştirilir ki tek satır yetsin?

> **Çözüm (derste verilen):** Satırlardan biri unutulursa ilişki tek yönlü kalır. `Person.setCar` içinde `if( car.getOwner() != this ) car.setOwner(this);`, `Car.setOwner` içinde `if( owner.getCar() != this ) owner.setCar(this);` yazılır. Böylece set metotlarından birini çağırmak iki yönü de kurar. Ayrıca iki parametreli `Car` yapıcısına `setOwner` çağrısı konursa `new Car("06 OS 1934", oktay)` tek başına iki yönlü ilişkiyi kurar.

**Soru 6** (ekrandan, 00:20:00 ve 00:55:00): `MethodParametersTest1` ve `MethodParametersTest3` programları çalıştırıldığında hangi değerler değişir, hangileri değişmez?

> **Çözüm (derste verilen, ajan çalıştırarak doğruladı):** `ilkelDuzenle`, `sarmalayiciDuzenle`, `ilkelDegistir`, `sarmalayiciDegistir` ve `sarmalayiciDegistirAlt` çağrılarından sonra çağıranın değişkenleri değişmez (3; 5; 1, 2; 1, 2), çünkü metotlar yalnız parametrelerin kopyalarını değiştirir. `swapForReal()` nesnenin üye alanlarını takas ettiği için `wrapI` ile `wrapJ` yer değiştirir (3, 5 → 5, 3). `MethodParametersTest3`'te `doIt` dizinin referansını aldığı için dizinin kendisi değişir ve `5 2 3 4 1` yazılır.

## Dersin Toparlaması

Bu derste önce Java'nın metot çağırma biçimi işlendi. Java her zaman değerle çağırır: ilkel türlerde değerin, nesne ve dizilerde referansın kopyası geçer. Bu yüzden metot içinde parametreye yeni bir değer ya da nesne atamak çağıranı etkilemez; `Integer`'da `x++` bile yeni bir nesne oluşturur. Buna karşılık nesnenin üye alanlarını değiştiren metotlar ve referans üzerinden dizinin içini değiştiren metotlar kalıcı değişiklik yapar. Ardından `if-else`, `switch-case`, `for`, `while` ve `do-while` kısaca hatırlatıldı.

Dersin ikinci yarısında nesneler arası ilişkilere geçildi. Association sahipliktir ve sahip olunan nesne üye alanda tutulur; dependency'de ikinci sınıf yalnız metot parametresinde ya da gövdesinde geçer. Çokluklar ve gizli bilgi sayesinde bir sınıf diyagramından sınıfın üye alanları okunabilir. Tek ve iki yönlü association `Person`-`Car` örneğiyle kodlandı; karşı nesnenin metodu çağrılmadan önce `null` denetiminin zorunlu olduğu, sıralama diyagramının kod satır satır okunarak çizildiği ve iki yönlü ilişkinin set metotlarıyla ve yapıcıyla tek satıra indirilebileceği gösterildi. Son olarak aggregation (bütün-parça, otobüs hattı-durak) ve composition (parça yalnız bir bütüne ait, takım-oyuncu) tanıtıldı. Sonraki derste composition örneği olarak birden çok araba tutan `Gallery` sınıfı ve kodu işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
