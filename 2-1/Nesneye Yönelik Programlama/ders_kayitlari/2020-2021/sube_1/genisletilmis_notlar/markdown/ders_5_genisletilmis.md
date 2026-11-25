# Ders 5 Genişletilmiş Notu: UML Sınıf Diyagramı ve Java Karşılığı: Kitaplık Uygulaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. UML Sınıf Diyagramına Giriş
- 2. Sınıflar Arası Bağlantılar
- 3. Nesne Yönelimli Programlamanın Temel Kavramları
- 4. Kodun İncelenmesi: Kitap Sınıfı ve main Metodu
- 5. toString ve Override
- 6. Public ile Static Arasındaki Fark
- 7. Kitaplık ve Raf Sınıfları
- 8. Kitap Arama ve Silme
- 9. Static Sayaç: getKitapSayısı
- 10. Composition ve Aggregation'ın Koddaki Karşılığı
- Örnek Sorular

## 1. UML Sınıf Diyagramına Giriş

Bu oturumda bir UML sınıf diyagramı ve onun Java ile yazılmış kodu birlikte incelendi. Diyagram Violet UML Editor 2.1.0 ile çizilmiş ve HTML olarak dışa aktarılmıştı; kod Eclipse'te `uyg1.pkg2` paketindeydi.

### 1.1 Diyagram

Ekrandaki diyagramda dört sınıf vardır (ekrandan, 00:05:00):

```text
+------------------------+
| Test                   |
+------------------------+
|                        |
+------------------------+
| +main(String[ ]): void |
+------------------------+

Kitaplik                         Raf                          Kitap
-raf: Raf [ ]                    - kitaplar: Kitap[ ]         - ad: String
                                                              - yazar: String
                                                              - ISBN: String
                                                              - kitapSayisi: <static> int
+ Kitaplik(int)                  + Raf()                      + Kitap(String,String,String)
+ kitapEkle(Kitap,int):void      + KitapEkle(Kitap):void      + getAd(): String
+ kitapSilSiraNo(int,int):void   + kitapSilSiraNo(int)        + getYazar(): String
+ kitapSil(int,Kitap):void       + kitapSil(Kitap)            + getISBN(): String
+ kitapAra(String):Kitap         + RafGoster():void           + getKitapSayisi(): int
+ gosterRaf(int):void            + getKitaplar(): Kitap[ ]    + setAd(String): void
+ tumRaflariGoster():void                                     + setYazar(String): void
                                                              + toString(): void
```

Bağlantılar:

| Bağlantı | Çizim | Anlamı |
|---|---|---|
| Kitaplik — Raf | Kitaplik tarafında içi dolu elmas | composition (güçlü bağlantı) |
| Raf — Kitap | Raf tarafında içi boş elmas | aggregation (zayıf bağlantı) |
| Test → Kitaplik | kesikli ok | bağımlılık |
| Test → Kitap | kesikli ok | bağımlılık |

Diyagramdaki her kutu Java'da bir sınıfa (class) karşılık gelir. Bu diyagramda `Test`, `Kitap`, `Raf` ve `Kitaplik` olmak üzere dört sınıf vardır.

### 1.2 Bir sınıf kutusunun okunması

Bir sınıf kutusu üç bölmeye ayrılır: en üstte sınıfın adı, ortada nitelikleri, en altta fonksiyonları (metotları).

`Test` kutusundaki `+main(String[ ]): void` satırı şöyle okunur. Baştaki `+` metodun public olduğunu gösterir. Ardından metodun adı gelir. Parantez içinde parametrelerin veri türleri yazar; burada tek tür vardır, dolayısıyla metot tek parametre alır ve bu parametre bir `String` dizisidir. İki noktadan sonraki `void`, metodun bir değer döndürmediğini belirtir.

`Kitap` kutusunda niteliklerin başındaki `-` işaretleri bu niteliklerin private olduğunu gösterir. `ad`, `yazar`, `ISBN`, `kitapSayisi` niteliklerin adlarıdır; iki noktadan sonra veri türleri yazar. `kitapSayisi` için ayrıca `<static>` yazılmıştır; bu da niteliğin static olduğunu gösterir. Bir nitelik sabit, yani `final` olsaydı bu da aynı yere yazılabilirdi.

`Kitap(String,String,String)` sınıfla aynı adı taşır ve dönüş türü yoktur; bu bir yapıcı fonksiyondur (constructor). Üç parametre alır, üçü de `String` türündedir. `getAd(): String` bir `String` döndürür; `setAd(String): void` bir `String` alır ve değer döndürmez. Başlarındaki `+` bu metotların public olduğunu gösterir.

Aynı okuma diğer sınıflara da uygulanır. `Kitaplik` sınıfında `-raf: Raf [ ]` niteliği private'tır, adı `raf`, türü `Raf` dizisidir; `Raf` burada bizim tanımladığımız bir sınıftır. `+ kitapEkle(Kitap,int):void` public'tir, `Kitap` ve `int` türünde iki parametre alır, değer döndürmez. `Raf` sınıfında `- kitaplar: Kitap[ ]` private bir `Kitap` dizisidir, `Raf()` ise yapıcıdır.

Dönüş türlerinin yalnız `int` ya da `void` olması gerekmez. `kitapAra(String):Kitap` bizim tanımladığımız `Kitap` türünden bir nesne, `getKitaplar(): Kitap[ ]` bir `Kitap` dizisi döndürür.

> **Ders sonrası not:** Diyagramda `toString(): void` yazıyor. Koddaki `toString()` ise bir `String` döndürür (Eclipse'in Outline panelinde `toString() : String`, ekrandan 00:50:00). Diyagramda doğrusu `+ toString(): String` olmalıdır.

## 2. Sınıflar Arası Bağlantılar

Diyagramdaki çizgiler sınıflar arasındaki ilişkileri gösterir. Kitap rafın bir parçasıdır, raf da kitaplığın bir parçasıdır.

`Kitaplik` ile `Raf` arasındaki çizginin `Kitaplik` ucundaki elmasın içi doludur (karalanmıştır). `Raf` ile `Kitap` arasındakinin içi boştur. Bu fark şu anlama gelir: kitaplık nesnesi silinirse o kitaplığın rafları da bundan etkilenir. Ama bir raf silindiğinde kitaplar etkilenmez; aradaki bağlantı daha zayıftır.

- İçi dolu elmas: **composition**, güçlü bağlantı. Kitaplığı silince raflar da gider.
- İçi boş elmas: **aggregation**, zayıf bağlantı. Rafa bir şey olsa da kitaplar zarar görmez.

Kesikli çizgiler bağımlılık anlamına gelir. `Test` sınıfının içinde `Kitaplik` sınıfı ve `Kitap` sınıfı kullanılır. `Test`, bu sınıflara sahip değildir; yalnız onları kullanır.

## 3. Nesne Yönelimli Programlamanın Temel Kavramları

Nesne yönelimli yaklaşımda dört temel kavram vardır: sınıf (class), nesne (object), nitelik ve fonksiyon.

Nitelikler, bir sınıfa ait nesnelerin özelliklerini; fonksiyonlar ise o nesnelerin neler yapabileceğini ifade eder. `Kitap` sınıfında `ad`, `yazar`, `ISBN`, `kitapSayisi` niteliklerdir; `getAd`, `setAd` gibi metotlar fonksiyonlardır.

Sınıf bir şablon olarak düşünülebilir. "Kitap" denildiğinde şunu söylemiş oluruz: bir kitabın adı, yazarı, ISBN'i olur; kitap `getAd` ile adını getirir, `setAd` ile adını değiştirir. Ama bu tanım yapıldığında ortada henüz hiç kitap yoktur. Nesne, bu şablondan oluşturulan somut kitaptır. Tek bir şablondan bir, on ya da bin kitap oluşturulabilir.

## 4. Kodun İncelenmesi: Kitap Sınıfı ve main Metodu

Bir program çalıştırıldığında ilk çalışan komutlar `public static void main` fonksiyonunun içindekilerdir. İnceleme buradan başladı.

### 4.1 main metodunun başı

Eclipse'teki `Main.java` dosyasının ilgili kısmı (ekrandan, 00:20:00 ve 01:00:00):

```java
public static void main(String[] args) {
    // TODO code application logic here

    System.out.println(Kitap.isbnNedir());          // Static Method Obje oluşturmadan Sınıf üzerinden çağırılabilir.
//  System.out.println(Kitap.getAd());              // Static olmayan methodlar kullanılamaz.

    Kitap kitap1 = new Kitap("Dönüşüm","Kafka","1234");
    Kitap kitap2 = new Kitap("Söylevler","Epiktetos","1235");
    Kitap kitap3 = new Kitap("Introduction to Algorithms","Ron Rivest","1236");

    System.out.println(kitap1.isbnNedir());
    System.out.println(kitap1.getAd());
    kitap1.setAd("Dönüşüm 2. Baskı");
    System.out.println(kitap1.getAd());

    System.out.println(kitap1);

    Kitap kitap4 = new Kitap("Clean Code","Robert C. Martin","1237");
    Kitap kitap5 = new Kitap("The Pragmatic Programmer","Andy Hunt","1238");
    Kitap kitap6 = new Kitap("Designing Data-Intensive Applications","Martin Kleppmann","1239");
```

<!-- BELİRSİZ: kitap6'nın adındaki tire karede bozuk bir karakter olarak görünüyor; "Data-Intensive" olarak yazıldı -->

### 4.2 Static metodu sınıf adıyla çağırmak

İlk satır `Kitap.isbnNedir()` çağrısını yazdırır. `Kitap` bir sınıftır. Bir sınıftan doğrudan bir nitelik ya da metoda erişilemez; ancak o üye `public static` ise sınıf adı, nokta ve üyenin adı yazılarak erişilebilir. `isbnNedir` böyle bir metottur (ekrandan, 00:50:00):

```java
public static String isbnNedir(){
    String s = "ISBN; 1972 yılında Uluslararası Standartlar Organizasyonu tarafından hazırlanan kitap numaralama sistemidir.";
    return s;
}
```

Metot bir `String` değişken oluşturur, ona bu açıklamayı atar ve döndürür. `main` içindeki `println` döndürülen metni ekrana yazar. Bu, programın ilk çıktı satırıdır.

Yorum satırına alınmış `Kitap.getAd()` çağrısı ise çalışmaz, çünkü `getAd` static değildir; koddaki yorum da bunu söyler.

### 4.3 Nesne oluşturma ve yapıcı

`Kitap kitap1 = new Kitap("Dönüşüm","Kafka","1234");` satırında `Kitap` şablonundan `kitap1` adında bir nesne oluşturulur. `new` anahtar kelimesi kullanılarak `Kitap` yapıcı fonksiyonu çağrılır ve parametre olarak üç `String` değer gönderilir: "Dönüşüm", "Kafka", "1234".

Yapıcının içinde bu değerler sınıfın niteliklerine atanır. Bundan sonra `kitap1` nesnesinin ad niteliğinin durumu (state) "Dönüşüm" olur; aynı atama yazar ve ISBN için de yapılır. Ardından static `kitapSayısı` niteliği bir artırılır. Böylece bir kitap oluşturulunca kitap sayısı 1 olur; `kitap2` ve `kitap3` ile birlikte üç kitap oluşur.

<!-- BELİRSİZ: Kitap yapıcısının gövdesi karede görünmüyor; atamalar ve kitapSayısı artışı anlatımdan aktarıldı -->

`kitapSayısı` niteliği `private static int` olarak tanımlanmıştır. Private olması, ona yalnız `Kitap` sınıfının içinden erişilebileceği anlamına gelir.

> **Ders sonrası not:** Anlatımda static olmanın "her yerden erişilebilir" anlamına geldiği söylendi (00:18:39). Erişimi `private`/`public` belirler. `static` ise niteliğin her nesnede ayrı ayrı değil, sınıf düzeyinde tek bir kopya olarak tutulduğunu belirtir; `kitapSayısı` private olduğu için sınıf dışından doğrudan erişilemez.

**Soru:** Sayaç ilk tanımlandığında sıfır olarak mı gelir? Doğrudan artırdık.
**Cevap:** Evet. Tür `int` olduğu için varsayılan değeri 0'dır. `String` olsaydı varsayılan değer `null` olurdu.

> **Ek bilgi (derste anlatılmadı):** Bu varsayılan değerler yalnız sınıfın niteliklerine (alanlarına) verilir. Bir metodun içindeki yerel değişkenlere değer atanmadan kullanılırsa Java derleme hatası verir.

### 4.4 Static metodu nesne üzerinden çağırmak

`kitap1.isbnNedir()` satırı da aynı açıklamayı yazdırır. `isbnNedir` sonuçta `Kitap` sınıfının bir fonksiyonudur, bu yüzden nesne üzerinden de erişilebilir. Ama static olduğu için Eclipse bu satırda uyarı verir (satır başında uyarı işareti, ekrandan 00:20:00). Böyle bir kullanım doğru bir alışkanlık değildir; yalnız göstermek amacıyla yazılmıştır.

### 4.5 getAd, setAd ve this

`kitap1.getAd()` ad niteliğini döndürür; `kitap1`'in adı "Dönüşüm" olduğu için ekrana "Dönüşüm" yazılır.

Adı değiştirmek için `setAd` kullanılır ve parametre olarak yeni bir ad gönderilir. Metodun içinde `this.Ad = Ad;` yazılır. Metot içinde yalın `Ad` yazıldığında, en yakın küme parantezleri içindeki tanım, yani fonksiyonun parametresi anlaşılır. `this` ise içinde bulunulan nesneyi temsil eder; `this.Ad` nesnenin ad niteliğidir. Böylece nesnenin adı parametre olarak gönderilen değere değiştirilir ve durumu artık "Dönüşüm 2. Baskı" olur. Tekrar `getAd()` çağrıldığında ekrana "Dönüşüm 2. Baskı" yazılır.

Aynı yapı `setYazar` metodunda da görülür (ekrandan, 00:50:00):

```java
public void setYazar(String Yazar) {
    this.Yazar = Yazar;
}

public String getISBN() {
    return ISBN;
}
```

Bu bölümün konsol çıktısı (ekrandan, 00:20:00):

```text
ISBN; 1972 yılında Uluslararası Standartlar Organizasyonu tarafından hazırlanan kitap numaralama sistemidir.
ISBN; 1972 yılında Uluslararası Standartlar Organizasyonu tarafından hazırlanan kitap numaralama sistemidir.
Dönüşüm
Dönüşüm 2. Baskı
Kitap{Ad=Dönüşüm 2. Baskı, Yazar=Kafka, ISBN=1234}
```

## 5. toString ve Override

`System.out.println(kitap1);` satırı nesnenin kendisini yazdırır ve çıktıda `Kitap{Ad=Dönüşüm 2. Baskı, Yazar=Kafka, ISBN=1234}` görülür.

Normalde bir nesne yazdırıldığında böyle bir metin çıkmaz. Çıkan şey nesnenin türü (paket ve sınıf adı) ile `@` işaretinden sonra gelen adresidir. Burada farklı bir metin çıkmasının sebebi, `toString` fonksiyonunun override edilmiş olmasıdır. Her sınıf, kendi yazdığımız sınıflar da dahil, sonuçta bir `Object`'tir ve varsayılan olarak tanımlanmış bir `toString` fonksiyonuna sahiptir.

Kodda `kitap1.toString()` yazılmamıştır. `System.out.println` bir nesne aldığında onu `String`'e dönüştürmek için `toString` fonksiyonunu otomatik çağırır; sanki orada gizli bir `toString` varmış gibi düşünülebilir. `Kitap` sınıfında bu fonksiyon override edildiği için varsayılan fonksiyon değil, sınıfta yazılan fonksiyon çalışır.

Override etmek için değiştirilecek fonksiyon aynı imzayla, yani aynı adla ve aynı dönüş türüyle sınıfta yeniden yazılır (üstüne `@Override` işareti konur). Gövdeye, fonksiyon çağrıldığında ne yapılması isteniyorsa o yazılır. Burada istenen şey `Kitap{Ad=..., Yazar=..., ISBN=...}` biçiminde bir metin üretmektir.

<!-- BELİRSİZ: Kitap.toString() gövdesi karede görünmüyor; biçim konsol çıktısından alındı -->

### 5.1 Override edilmemiş toString

**Soru:** Override'ı tam olarak anlayamadım.
**Cevap:** Bu soru üzerine toString'i override edilmemiş bir sınıfla gösterim yapıldı. `main` içinde `Kitaplık` türünden bir nesne oluşturuldu (parametre 5) ve yazdırıldı. Çıktı şuydu (ekrandan, 00:30:00):

```text
uyg1.pkg2.Kitaplık@34c45dca
```

`Kitaplık` sınıfında `toString` diye bir fonksiyon tanımlanmadı, ama her sınıf bir `Object` olduğu için bu fonksiyon vardır ve paket adı, sınıf adı ve `@` ile adresi yazar. Nesneden sonra `.toString()` yazılsa da yazılmasa da aynı çıktı alınır. `Kitap` sınıfında ise "bir kitap nesnesinin toString'i çağrılırsa bu varsayılan cevabı istemiyorum" denmiş ve fonksiyon değiştirilmiştir.

`@` işaretinden sonraki `34c45dca` nesnenin bellekteki adresini belirtir.

> **Ek bilgi (derste anlatılmadı):** `Object.toString()` aslında `@` işaretinden sonra nesnenin `hashCode()` değerini on altılık tabanda yazar. Bu değer çoğu JVM'de belleğe bağlı üretilir ama Java dili bunun gerçek bir bellek adresi olduğunu garanti etmez.

## 6. Public ile Static Arasındaki Fark

**Soru:** Public ile public static'in farkı ne? Static, fonksiyonun main içinden çağrılabilmesini mi sağlıyor?
**Cevap:** İkisi farklı kavramlardır. Bir üye `private static`, `public static`, static olmayan `public` ya da static olmayan `private` olabilir.

`public` erişimi belirler. `Kitap` sınıfındaki `getAd` public'tir; `main` içinde `kitap1.` yazınca `getAd`'e nokta ile erişilebilir. Ama `Ad` niteliği private'tır. `kitap1.` yazıldığında bu nitelik listede çıkmaz. `Kitap` sınıfının içinde ise `Ad` kullanılabilir. Private üyeler yalnız kendi sınıflarının içinde kullanılır, farklı sınıflarda kullanılamaz.

`static` ise nesne oluşturmadan sınıf üzerinden erişmeyi sağlar. `public static int getKitapSayısı()` metoduna `Kitap` sınıfının adıyla (büyük harfle başlayan sınıf adı) `Kitap.getKitapSayısı()` diye erişilebilir. Nesne oluşturmadan doğrudan sınıf aracılığıyla erişilebilmesinin sebebi static olmasıdır. `main` içinden bu metodun görülebilmesinin sebebi ise public olmasıdır; private olsaydı görülemezdi. Nitekim `kitapSayısı` niteliği private olduğu için `main` içinde görülmez, `Kitap` sınıfının içinde görülür.

`getKitapSayısı` static yapıldığı için içinde kullandığı `kitapSayısı` niteliği de static olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Static bir metot belirli bir nesneye bağlı olmadan çalıştığı için içinde `this` yoktur. Bu yüzden static olmayan bir niteliğe ya da metoda, bir nesne referansı üzerinden gitmeden doğrudan erişemez.

## 7. Kitaplık ve Raf Sınıfları

### 7.1 Kitaplık nesnesinin oluşturulması

`main` içinde şimdi bir kitaplık nesnesi oluşturulur ve parametre olarak 5 gönderilir (ekrandan, 01:00:00):

```java
Kitaplık kitaplık = new Kitaplık(5);
```

Buradaki 5 raf sayısıdır: kitaplıkta 5 raf bulunur. Sınıflar bir veri türü gibi düşünülebilir. `Kitaplık` türünde `kitaplık` adında bir değişken vardır; `new` ile `Kitaplık` yapıcı fonksiyonu çağrılarak bellekte ona yer açılır.

`Kitaplık` sınıfının kodu (ekrandan, 00:55:00):

```java
public class Kitaplık {
    private Raf[] raf;

    public Kitaplık(int n) {
        this.raf = new Raf[n];
        for (int i = 0; i < n; i++){
            raf[i] = new Raf();
        }
    }

    public void kitapEkle(Kitap kitap, int rafNo)
    {
        raf[rafNo].kitapEkle(kitap);
    }

    public void kitapSilSıraNo(int rafNo, int n)
    {
        raf[rafNo].kitapSilSıraNo(n);
    }

    public void kitapSil(int rafNo, Kitap k)
    {
        raf[rafNo].kitapSil(k);
    }

    public void rafGoster(int n){
        raf[n].rafGoster();
    }

    public void tumRaflariGoster(){
        int n = raf.length;
        for(int i = 0; i < n; i++){
        // devamı karede görünmüyor
```

`raf` niteliği private bir `Raf` dizisidir; ona `Kitaplık` sınıfının dışından erişilemez. Yapıcıya `n` olarak 5 geldi. `this.raf = new Raf[n];` ile 5 elemanlı bir `Raf` dizisi oluşturulur; burada `this.raf` nesnenin `raf` niteliğidir.

Dizi oluşturulmuştur, ama dizideki her eleman aslında `null`'ı gösterir. Bu yüzden döngüyle dizinin her elemanına `new Raf()` ile bir raf nesnesi atanır. Sonuçta 5 raflı bir kitaplık oluşmuş olur.

### 7.2 Raf yapıcısı

Her rafın private bir `kitaplar` niteliği vardır; türü `Kitap` dizisidir. `new Raf()` çağrıldığında `Raf` yapıcısına gidilir. Yapıcıda bu dizi 10 elemanlı oluşturulur, yani her rafa en çok 10 kitap konabilir.

<!-- BELİRSİZ: Raf yapıcısının kodu karede görünmüyor; 10 elemanlı dizi anlatımdan aktarıldı -->

### 7.3 Kitap ekleme

Kitaplara raf ataması şöyledir (ekrandan, 00:40:00):

```java
kitaplık.kitapEkle(kitap1, 0);                  // 0. Rafa kitap1 i ekle
kitaplık.kitapEkle(kitap2, 0);
kitaplık.kitapEkle(kitap3, 0);

kitaplık.kitapEkle(kitap4, 1);
kitaplık.kitapEkle(kitap5, 1);
kitaplık.kitapEkle(kitap6, 2);
```

`kitaplık.kitapEkle(kitap1, 0)` çağrısında `kitap1` ("Dönüşüm" adlı kitap) ve raf numarası 0 gönderilir. `Kitaplık.kitapEkle` içinde `raf[rafNo]`, yani 0. raf seçilir ve o rafın `kitapEkle` metodu kitapla çağrılır. Böylece `Raf` sınıfına geçilir.

`Raf.kitapEkle` anlatıma göre şöyle çalışır: bir `i` değişkeni 0'dan başlatılır. `i < kitaplar.length` (10) olduğu ve `kitaplar[i]` `null` olmadığı sürece `i` artırılır. Kitaplık yeni kurulduğunda raflar boştur; her rafta 10 kitaplık yer ayrılmış ama hiç kitap konmamıştır. Bu yüzden `kitaplar[0]` `null`'dır ve döngüye girilmez. Ardından `i` dizinin boyuna eşit değilse (0, 10'a eşit değil) `kitaplar[i]`'ye gelen kitap atanır. Böylece 0. rafın ilk kitabı "Dönüşüm" olur.

<!-- BELİRSİZ: Raf.kitapEkle gövdesi karede görünmüyor; anlatımdan aktarıldı -->

Bu çağrılardan sonra kitaplıkta 5 raf vardır. 0. rafta 3 kitap, 1. rafta 2 kitap, 2. rafta 1 kitap bulunur; diğer raflar boştur.

### 7.4 Rafı gösterme

`kitaplık.rafGoster(0)` çağrısında `kitaplık` nesnesi üzerinden `Kitaplık` sınıfındaki `rafGoster` metodu kullanılır. Metot public olduğu için erişilebilir; static olmadığı için de önce nesnenin oluşturulmuş olması gerekir. Parametre 0 olduğundan 0. rafın `rafGoster` metodu çalışır.

`Raf.rafGoster` `kitaplar` dizisinin 10 elemanını sırayla dolaşıp yazdırır (döngü başı `for (int i = 0; i < kitaplar.length; i++)`, ekrandan 00:45:00). 0. rafa 3 kitap eklenmişti: "Dönüşüm 2. Baskı", "Söylevler", "Introduction to Algorithms". Kalan 7 eleman `null`'dır. Çıktı:

```text
Kitap{Ad=Dönüşüm 2. Baskı, Yazar=Kafka, ISBN=1234}
Kitap{Ad=Söylevler, Yazar=Epiktetos, ISBN=1235}
Kitap{Ad=Introduction to Algorithms, Yazar=Ron Rivest, ISBN=1236}
null
null
null
null
null
null
null
```

## 8. Kitap Arama ve Silme

`main` içindeki ilgili satırlar (ekrandan, 00:40:00):

```java
System.out.println("----------------------------");

kitaplık.rafGoster(0);

System.out.println("----------------------------");

System.out.println(kitaplık.kitapAra("Clean Code"));

System.out.println("----------------------------");

kitaplık.kitapSil(1, kitap4);

System.out.println(kitaplık.kitapAra("Clean Code"));

System.out.println("----------------------------");

kitaplık.rafGoster(0);

System.out.println("----------------------------");
```

### 8.1 kitapAra

`kitapAra("Clean Code")` ile "Clean Code" adlı kitap aranır. Anlatıma göre `Kitaplık.kitapAra` şöyle çalışır. `n = raf.length`, yani 5'tir. Dıştaki `for` döngüsüyle her raf dolaşılır. Her `i` için o rafın kitapları (`getKitaplar()`) bir `Kitap` dizisi olarak gelir. Bu dizi, `Kitap` türünde bir `kitap` değişkeniyle tek tek dolaşılır; gelen dizi `Kitap` türünde olduğu için döngü değişkeni de `Kitap` türünde olmalıdır (dış döngüde `int i` kullanılmasının sebebi `n`'nin de `int` olmasıdır).

Her kitap için, kitap `null` değilse adı aranan adla karşılaştırılır:

- `i = 0` (0. raf): "Dönüşüm 2. Baskı", "Söylevler", "Introduction to Algorithms" sırayla denenir; hiçbiri "Clean Code" değildir. Kalan elemanlar `null`'dır.
- `i = 1` (1. raf): bu rafta `kitap4` ve `kitap5` ("Clean Code" ve "The Pragmatic Programmer") vardır. İlk kitabın adı "Clean Code"dur ve aranan adla eşittir. Bu durumda `"Kitap " + i + ". Rafta var."` yazdırılır ve kitap döndürülür.

`main`'deki `println`, dönen `kitap4` nesnesini yazdırırken yine override edilmiş `toString` çalışır. Çıktı (ekrandan, 00:40:00 ve 00:45:00):

```text
Kitap 1. Rafta var.
Kitap{Ad=Clean Code, Yazar=Robert C. Martin, ISBN=1237}
```

Kitap hiçbir rafta bulunamazsa bütün raflar dolaşıldıktan sonra "Kitap yok." yazdırılır ve `null` döndürülür.

<!-- BELİRSİZ: kitapAra gövdesi karede görünmüyor; ad karşılaştırmasının equals ile mi yapıldığı görülemedi -->

> **Ek bilgi (derste anlatılmadı):** Java'da iki `String`'in içeriğini karşılaştırmak için `equals` kullanılır. `==` iki referansın aynı nesneyi gösterip göstermediğine bakar; içerik aynı olsa bile farklı nesneler için `false` verebilir.

### 8.2 kitapSil: nesneyle silme

`kitaplık.kitapSil(1, kitap4)` ile "Clean Code" kitabı kitaplıktan silinir. Raf numarası 1'dir; `Kitaplık.kitapSil` 1. rafın `kitapSil` metodunu çağırır ve kitabı ona gönderir. `Raf.kitapSil` (ekrandan, 00:45:00):

```java
public void kitapSil(Kitap k) {
    int i = 0;
    while(i < kitaplar.length && kitaplar[i] != k)
    {
        i++;
    }
    if (i < kitaplar.length)
    {
        kitaplar[i] = null;
    }
}
```

Adım adım: `i = 0`. `kitaplar.length` 10'dur ve `0 < 10` doğrudur. 1. raftaki ilk kitap "Clean Code"dur, yani `kitaplar[0]` silinmek istenen `k` ile aynıdır; `kitaplar[0] != k` yanlış olur. Ve bağlacıyla (`&&`) bağlı koşullardan biri yanlış olduğu için döngüye girilmez. Sonra `if` koşuluna bakılır: `i` 0'dır ve 10'dan küçüktür. İçeri girildiğine göre bu, silinmek istenen kitaptır; `kitaplar[0] = null` yapılır.

Burada "silmek" kitabı yok etmek anlamına gelmez. Kitap yırtılmaz, yakılmaz; yalnız raftan kaldırılıp bir kenara konur. `kitap4` nesnesi `main` içinde var olmaya devam eder.

Silmeden sonra `kitapAra("Clean Code")` tekrar çağrılır. Bütün raflar dolaşılır ama kitap bulunamaz; "Kitap yok." yazılır ve `null` döner. Ardından `rafGoster(0)` yine 3 kitabı ve 7 `null`'ı gösterir. Çıktı (ekrandan, 00:45:00):

```text
Kitap yok.
null
----------------------------
Kitap{Ad=Dönüşüm 2. Baskı, Yazar=Kafka, ISBN=1234}
...
```

### 8.3 kitapSilSıraNo: sıra numarasıyla silme

`kitapSil` metoduna raf ve kitap verilir. `kitapSilSıraNo` metoduna ise raf numarası ve raftaki sıra numarası verilir; örneğin "0. rafın 0. kitabını sil". `Kitaplık.kitapSilSıraNo` 0. rafın `kitapSilSıraNo` metodunu çağırır ve 0'ı gönderir. `Raf.kitapSilSıraNo` (ekrandan, 00:45:00):

```java
public void kitapSilSıraNo(int n) {
    if (n < kitaplar.length)
        kitaplar[n] = null;
}
```

0, `kitaplar.length` (10) değerinden küçük olduğu için `kitaplar[0]` `null` yapılır. 3 verilseydi 3 de 10'dan küçük olduğu için 3. kitap silinirdi.

Bundan sonra `rafGoster(0)` çağrıldığında ilk satır `null` olur, çünkü 0. rafın 0. kitabı silinmiştir. 1. ve 2. sıradaki kitaplar ("Söylevler" ve "Introduction to Algorithms") durur; kalan 7 eleman zaten `null`'dır.

## 9. Static Sayaç: getKitapSayısı

Son olarak `Kitap.getKitapSayısı()` çağrılır. Toplam 6 kitap oluşturulmuştur ve çıktı 6'dır (ekrandan, 00:50:00). Raftan kaldırılan kitaplar sayacı azaltmaz, çünkü sayaç yalnız yapıcıda artırılır.

```java
public static int getKitapSayısı() {
    return kitapSayısı;
}
```

Metot static olduğu için nesne üretmeden doğrudan sınıf adıyla çağrılabilir. Döndürdüğü `kitapSayısı` da static olmak zorundadır. Gösterim için `kitapSayısı`'nın tanımından `static` kaldırıldı ve Eclipse hata verdi; önerdiği düzeltme "change kitapSayısı to static" oldu (00:50:06).

Nitelik static olmasaydı bu sayıya sınıf adıyla erişilemezdi. Önce bir nesne oluşturmak ve `kitap1.getKitapSayısı()` gibi nesne üzerinden çağırmak gerekirdi.

## 10. Composition ve Aggregation'ın Koddaki Karşılığı

**Soru:** UML diyagramında bir elmas karalanmış, biri açık bırakılmıştı. Bunun koddaki karşılığını gösterebilir misiniz?
**Cevap:** Önce raf ile kitaba bakıldı. `main` içinde 6 kitap oluşturuldu, sonra bu kitaplar raflara yerleştirildi. 0. raf nesnesi silinse bu kitaplar yok olmaz, çünkü kitaplar `main` içinde tanımlanmıştır. Raf kaldırılsa kitaplar başka bir rafa konabilir ya da hiçbir rafa konmadan nesne olarak durabilir. İçi boş elmas bunu anlatır: rafla kitap arasında bir ilişki vardır, raf kitaplar diye bir nitelik tutar, ama raf silinince kitaplara zarar gelmez.

Kodda bunun görüldüğü yer `Raf` yapıcısıdır. Yapıcıda kitaplar oluşturulmaz; yalnız 10 elemanlı bir `Kitap` dizisi oluşturulur. Kitaplar başka yerde, `new Kitap(...)` ile oluşturulmuş ve sonradan bu diziye konmuştur.

Kitaplıkta ise durum farklıdır. `Kitaplık` yapıcısında `new Raf()` ile raf nesneleri yapıcının içinde oluşturulur. Bu yüzden kitaplık silinirse raflar da gider. Yani kitaplığa bir şey olması rafları etkiler, ama rafa bir şey olması kitapları etkilemez. İçi dolu elmasta iki taraf o kadar sıkı bağlıdır ki biri öbürü olmadan olamaz gibidir; içi boş elmasta bir bağlantı vardır, ama biri olmasa öbürüne bir şey olmaz.

**Soru:** Kısaca, nesne sınıfın dışında oluşturuluyorsa içi boş, sınıfın içinde oluşturuluyorsa içi dolu diyebilir miyiz?
**Cevap:** Bu şekilde anlaşılabilir, ama iki sınıf arasında bir ilişki bulunmalıdır. İlişki vardır ama nesne o sınıfın yapıcısında oluşturulmuyorsa içi boş olur. Yapıcıda oluşturuluyorsa, örneğin kitaplık nesnesi silindiğinde yapıcıda oluşturulan raflar da gider.

**Soru:** Raf kitaplıkla birlikte oluştuğuna göre `Raf` sınıfı `Kitaplık` sınıfının içinde tanımlanamaz mıydı?
**Cevap:** Tanımlanabilir. Bu örnek için çok bir farkı olmaz: `Raf` zaten yalnız `Kitaplık` içinde kullanılmaktadır. Hangisinin seçileceği programlama tasarımına, programcının inisiyatifine ve problem çözme yöntemine bağlıdır.

**Soru:** UML diyagramında kesikli çizgiyle düz çizgi arasında ne fark var?
**Cevap:** Kesikli çizgi bağımlılıktır. `Test` sınıfının `main` metodunda `Kitaplık` ve `Kitap` sınıfları kullanılır: `Kitaplık`'tan bir nesne oluşturulur (bu sırada raf nesneleri de oluşur), kitaplar oluşturulup raflara, yani kitaplığa yerleştirilir. Ama bu, rafın kitaplıkta olması gibi bir aitlik değildir; `Test` sınıfı bu sınıfları yalnız kullanır. Düz çizgiler ve elmaslar ise aitlik bildirir: raf kitaplığa, kitap rafa aittir. Raf ile kitap arasındaki elmasın içi boş olduğu için rafa zarar verilse kitaba bir şey olmaz. Kitaplık ile raf arasındakinin içi dolu olduğu için kitaplığa zarar verilirse raf da zarar görür. Siyah (dolu) olan güçlü bağlantı, beyaz (boş) olan zayıf bağlantıdır.

> **Ders sonrası not:** Cevabın sonunda hangisine aggregation, hangisine composition denildiği hatırlanamadı (00:59:21). Dersin başında söylendiği gibi doğrusu şudur: içi dolu elmas composition (güçlü), içi boş elmas aggregation (zayıf) bağlantıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:23): Static `int kitapSayısı` niteliği ilk değer verilmeden doğrudan artırılıyor. İlk değeri nedir?

> **Cevap (derste verildi):** `int` türündeki bir nitelik varsayılan olarak 0 ile başlar; `String` olsaydı `null` olurdu. Bu yüzden ilk kitap oluşturulduğunda sayaç 1 olur.

**Soru 2** (derste sözlü, 00:28:05): `public` ile `public static` arasındaki fark nedir?

> **Cevap (derste verildi):** `public`/`private` erişimi belirler; `static` üyenin nesneye değil sınıfa ait olduğunu ve sınıf adıyla çağrılabileceğini belirtir. İkisi bağımsızdır; dört birleşim de mümkündür.

**Soru 3** (ekrandan, 00:30:00): `toString()` override edilmemiş `Kitaplık` sınıfının bir nesnesi `System.out.println` ile yazdırılırsa ne çıkar?

> **Cevap (derste verildi):** `Object` sınıfından gelen `toString()` çalışır ve `paket.SınıfAdı@...` biçiminde bir metin yazılır; derste `uyg1.pkg2.Kitaplık@34c45dca` çıktı.

**Soru 4** (ekrandan, 00:40:00): Yukarıdaki `main` akışında kitaplar raflara eklendikten sonra `kitapAra("Clean Code")`, ardından `kitapSil(1, kitap4)` ve tekrar `kitapAra("Clean Code")` çağrılırsa ekrana ne yazılır?

> **Cevap (derste verildi):** İlk arama `Kitap 1. Rafta var.` yazar, `println` dönen kitabı `Kitap{Ad=Clean Code, Yazar=Robert C. Martin, ISBN=1237}` olarak yazdırır. Silmeden sonra arama `Kitap yok.` yazar ve dönen `null` ekrana `null` olarak basılır.

**Soru 5** (derste sözlü, 00:52:01): UML'deki içi dolu ve içi boş elmasın kodda karşılığı nedir?

> **Cevap (derste verildi):** `Kitaplık` yapıcısı `Raf` nesnelerini kendi içinde `new Raf()` ile oluşturur; kitaplık giderse raflar da gider (composition, dolu elmas). `Raf` yapıcısı yalnız boş bir `Kitap` dizisi oluşturur; kitaplar dışarıda oluşturulup rafa konur, raf silinse de kitaplar kalır (aggregation, boş elmas).

> **Not:** Ajan, karede görünen kodu ve anlatılan ama karede görünmeyen metot gövdelerini (Raf yapıcısı, `Raf.kitapEkle`, `kitapAra`, `Kitap` yapıcısı ve `toString`) birleştirerek tek dosyalık bir Java programı yazdı ve `java` ile çalıştırdı (javac kurulu değil). Elde edilen çıktı, ekrandaki konsol çıktısıyla aynıdır; son satırda `6` yazılır.

## Dersin Toparlaması

Bu oturumda bir UML sınıf diyagramının nasıl okunduğu ve Java koduna nasıl karşılık geldiği bir kitaplık örneği üzerinden gösterildi. Sınıf kutusunun üç bölmesi, `+`/`-` erişim işaretleri, yapıcılar, dönüş türleri ve static nitelikler diyagramda okundu; ardından aynı yapı Eclipse'teki kodda adım adım izlendi. Sınıfın şablon, nesnenin o şablondan `new` ile üretilen örnek olduğu, `this` ile nitelik ve parametrenin ayrıldığı, `toString`'in override edilerek nesnenin yazdırılma biçiminin değiştirildiği görüldü.

Public ile static'in ayrı kavramlar olduğu, static metotların sınıf adıyla çağrıldığı ve static sayaçların bütün nesneler için ortak tutulduğu vurgulandı. Son olarak diyagramdaki üç bağlantı türünün kodda nasıl göründüğü açıklandı: yapıcıda parçalarını kendisi oluşturan kitaplık composition'a, dışarıda oluşturulmuş kitapları tutan raf aggregation'a, diğer sınıfları yalnız kullanan `Test` sınıfı bağımlılığa örnektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
