# Ders 11 Genişletilmiş Notu: Kalıtım, Soyut Sınıflar ve Aşırı Yükleme: Kitaplık Uygulaması 2

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Uygulamanın Tekrarı ve Genişletilmiş UML Diyagramı
- 2. UML'de Kalıtım ve Soyut Metot
- 3. Getter ve Setter Ne Zaman Yazılır
- 4. Önceki Kodun Tekrarı: Kitaplık, Raf ve Kitap
- 5. KitaplıkYonetim Sınıfı
- 6. Kalıtımın Java Karşılığı: extends ve super
- 7. Erişim Belirleyiciler ve Kalıtım
- 8. toString, Override ve super.toString
- 9. Yapıcı Fonksiyon Zorunlu mu
- 10. Kitap Satışı: kitapSat, kitapAra ve odemeYap
- 11. Fonksiyon Aşırı Yükleme
- Örnek Sorular

## 1. Önceki Uygulamanın Tekrarı ve Genişletilmiş UML Diyagramı

Bu oturum, önceki uygulamada kurulan kitaplık projesinin devamıdır. Önceki uygulamada `Kitap`, `Raf` ve `Kitaplik` olmak üzere üç sınıf vardı. Bu kez projeye kart sistemi ve kitap satışı eklenir; konu olarak kalıtım, soyut (abstract) sınıflar, override ve fonksiyon aşırı yükleme işlenir.

### 1.1 Diyagram

Ekranda gösterilen diyagram şöyledir (ekrandan, 00:05:00):

```text
<<abstract>> Kart                       KitaplıkYonetim
- id: int                               - Kitaplık: kitaplık
- Sahip: String                         + kitapSat(kitap, kart): boolean
- Bakiye: double                        + KitaplıkYonetim(Kitaplık)
+ getId(): int
+ getSahip(): String
+ getBakiye(): double
+ setBakiye(double)
+ toString(): String
+ odemeYap(double): <<abstract>>boolean

YetiskinKartı                           OgrenciKartı
(nitelik yok)                           - bonus: double
+ YetiskinKartı(int,String,double)      + OgrenciKartı(int,String,double)
+ odemeYap(double): boolean             + odemeYap(double): boolean

Kitaplik                     Raf                        Kitap
-raf: Raf [ ]                - kitaplar: Kitap[ ]       - ad: String
+ Kitaplik(int)              + Raf()                    - yazar: String
+ kitapEkle(Kitap,int):void  + KitapEkle(Kitap):void    - ISBN: String
+ kitapSil(int,int):void     + kitapSil(int)            - fiyat: double
+ kitapSil(int,Kitap):void   + kitapSil(Kitap)          - kitapSayisi: <static> int
+ kitapAra(String):int       + RafGoster():void         + Kitap(String,String,String)
+ gosterRaf(int):void        + getKitaplar(): Kitap[ ]  + getAd(): String
+ tumRaflariGoster():void                               + getYazar(): String
+ kitapSat(kitap, kart): boolean                        + getISBN(): String
                                                        + getKitapSayisi(): int
                                                        + getFiyat(): double
                                                        + setAd(String): void
                                                        + setYazar(String): void
                                                        + toString(): void
```

Bağlantılar:

| Bağlantı | Çizim | Anlamı |
|---|---|---|
| YetiskinKartı → Kart | ucu içi boş üçgen olan ok | kalıtım |
| OgrenciKartı → Kart | ucu içi boş üçgen olan ok | kalıtım |
| KitaplıkYonetim → Kart | kesikli ok | bağımlılık (yalnız kullanma) |
| KitaplıkYonetim → Kitaplik | düz çizgi, oklu | ilişki (nitelik olarak tutma) |
| Kitaplik — Raf | Kitaplik tarafında içi dolu elmas | composition |
| Raf — Kitap | Raf tarafında içi boş elmas | aggregation |

### 1.2 Önceki diyagramdan hatırlatmalar

Diyagramda `-` private, `+` public anlamına gelir. Niteliklerin adından sonra veri türü yazılır. Metotlarda parantez içine aldıkları parametrelerin türleri yazılır; parametre almıyorsa parantez boş bırakılır. İki noktadan sonra dönüş türü gelir.

`Kitaplik` ile `Raf` arasındaki çizginin ucu koyu (içi dolu elmas) çizilmiştir. Bu, kitaplık nesnesi silinirse raflarının da bundan etkileneceği anlamına gelir; koddaki karşılığı, rafların `Kitaplik` sınıfının yapıcı fonksiyonu içinde oluşturulmasıdır. `Raf` ile `Kitap` arasındaki içi boş elmas ise kitapların raf sınıfının içinde değil başka bir yerde tanımlandığını gösterir. Raf ile kitap arasında yalnız mantıksal bir ilişki vardır.

## 2. UML'de Kalıtım ve Soyut Metot

### 2.1 Kalıtım oku

Bir sınıftan diğerine ucu üçgen şeklinde bir ok çizildiğinde, okun çıktığı sınıfın okun gösterdiği sınıftan kalıtım aldığı anlaşılır. Diyagramda `YetiskinKartı` ve `OgrenciKartı`, `Kart` sınıfından kalıtım alır. Kalıtım alınan sınıfın soyut olması zorunlu değildir; bu örnekte `Kart` ayrıca soyuttur.

`YetiskinKartı` yalnız `Kart`'taki özelliklere sahiptir, ek bir niteliği yoktur. `OgrenciKartı` ise bunlara ek olarak bir `bonus` niteliğine sahiptir.

### 2.2 Kalıtım ne işe yarar

Kalıtım kullanılmasaydı `id`, `Sahip`, `Bakiye` niteliklerinin her iki kart sınıfında ayrı ayrı tanımlanması gerekirdi. Hocanın verdiği örnekle, bu tür on sınıf olsaydı aynı üç niteliğin on sınıfta tek tek tanımlanması gerekecekti. Bunun yerine bir `Kart` sınıfı tanımlanır ve diğerleri ondan kalıtım alır; nitelikler tek bir yerde tanımlanır ama hepsinde tanımlanmış gibi olur.

Kalıtım almak, alt sınıfın üst sınıftaki bütün nitelik ve fonksiyonlara sahip olması demektir. `YetiskinKartı` sınıfının içinde `getSahip` yazılmamış olsa bile, bir yetişkin kartı nesnesi için `getSahip()` çağrıldığında hata alınmaz, bir değer döner. Bunların dışında her kart sınıfının kendi yapıcı fonksiyonu ve kendi `odemeYap` fonksiyonu vardır.

### 2.3 Soyut metot

`Kart` kutusundaki `odemeYap(double): <<abstract>>boolean` bir soyut fonksiyondur. Soyut fonksiyonun gövdesi `Kart` sınıfında yazılmaz, yalnız tanımı (prototipi) yapılır. Bu tanım şunu ister: `Kart` sınıfından kim kalıtım alıyorsa kendi içinde `odemeYap` adında bir fonksiyon oluştursun, onu override etsin ve kendi ödeme biçimini yazsın. Soyut metot, alt sınıfları buna mecbur bırakır. Bu yüzden diyagramda iki kart sınıfında da ayrı ayrı `odemeYap` vardır.

**Soru:** Abstract fonksiyonu tekrar anlatabilir misiniz?
**Cevap:** Sınıfın içinde `abstract` anahtar kelimesiyle bir fonksiyon tanımlanır, ama gövdesi yazılmaz, yalnız prototipi yazılır. Yetişkin kartı ve öğrenci kartı bu karttan kalıtım aldığı için `Kart` sınıfı onlara şunu zorunlu tutar: "Benden kalıtım alacaksan `odemeYap` diye bir fonksiyon oluşturman, onu override etmen, gövdesini kendi sınıfının içinde yazman lazım."

Ek olarak, soyut sınıflardan nesne üretilmez; soyut sınıf yalnız kalıtım almayı sağlar. Öğrenci kartı nesnesi üretilebilir, ama kart nesnesi üretilemez.

### 2.4 KitaplıkYonetim bağlantıları

Diyagramda bir de `KitaplıkYonetim` sınıfı vardır. Bu sınıfta hem `Kart` hem `Kitaplik` sınıflarından türetilen nesneler kullanılır. Ancak iki bağlantının çizimi farklıdır. `Kitaplik`'e giden çizgi düzdür: `KitaplıkYonetim` sınıfının `Kitaplık` adında bir niteliği vardır, dolayısıyla aralarında mantıksal bir ilişki kurulur. `Kart`'a giden çizgi kesiklidir: `KitaplıkYonetim` içinde kart sınıfından bir nitelik yoktur; sınıf kartı yalnız kullanır.

> **Ek bilgi (derste anlatılmadı):** UML'de kesikli ok genellikle bağımlılık (dependency), düz çizgi ise ilişki (association) olarak adlandırılır. Bağımlılıkta bir sınıf diğerini örneğin metot parametresi olarak kullanır ama onu kalıcı bir nitelik olarak saklamaz.

## 3. Getter ve Setter Ne Zaman Yazılır

Önceki uygulamaya eklenen küçük bir not: `Kitap` sınıfında private niteliklerin hepsinin hem `get` hem `set` metodu yoktur. Örneğin `getFiyat` vardır ama `setFiyat` yoktur. Bazı öğrenciler her private nitelik için kesinlikle hem get hem set yazar. Böyle yapılırsa niteliği private yapmanın anlamı kalmaz; "o zaman public yap gitsin" denebilir. Değiştirilmesi istenmeyen bir nitelik için yalnız `get` yazılır; değiştirilmesi de isteniyorsa `set` yazılır.

## 4. Önceki Kodun Tekrarı: Kitaplık, Raf ve Kitap

Eclipse'teki projede (`uyg2`, paket `javaapplication6`) `Kart`, `Kitap`, `Kitaplık`, `KitaplıkYonetim`, `OgrenciKartı`, `Raf`, `Test` ve `YetiskinKartı` dosyaları vardır (ekrandan, 00:20:00).

Kitaplık beş raftan oluşur. `Kitaplik` sınıfında bir `raf` dizisi tanımlanır; yapıcı fonksiyonda önce bellekte dizi için yer ayrılır. Bu noktada dizinin her elemanı `null`'ı gösterir. Ardından her dizi elemanına `new Raf()` ile bir raf nesnesi için yer ayrılır.

`Raf` sınıfında ise durum farklıdır (ekrandan, 00:20:00):

```java
public class Raf {
    private Kitap[] kitaplar;

    public Raf() {
        this.kitaplar = new Kitap[10];
    }
    ...
    public void kitapSil(Kitap k){
        int i = 0;
        while(i < kitaplar.length && kitaplar[i] != k)
            i++;
        if (i != kitaplar.length)
            kitaplar[i] = null;
    }
```

Raf yapıcısı on elemanlı bir `Kitap` dizisi oluşturur ama bir döngü açıp her elemana `new Kitap(...)` atamaz; elemanlar `null`'ı göstermeye devam eder. Kitaplığın yapıcısında rafların oluşturulması UML'deki dolu elmasa, rafın yapıcısında kitapların oluşturulmaması da boş elmasa karşılık gelir.

Kitaplar test sınıfında oluşturulur ve `kitaplık.kitapEkle(kitap3, 0)` gibi çağrılarla raflara konur: ilk parametre kitap, ikincisi rafın numarasıdır. `Kitaplik.kitapEkle`, ilgili rafın `kitapEkle` metodunu çağırır. Raftaki `kitapEkle` dizide boş (`null`) olan ilk yeri arar ve kitabı oraya yazar. Böylece dizinin ilk elemanı artık `null`'ı değil bir kitabı gösterir. Testte kitap 1, 2, 3 sıfırıncı rafa; kitap 4 ve 5 birinci rafa; kitap 6 ikinci rafa eklenir (ekrandan, 00:25:00).

`tumRaflariGoster` bütün rafları dolaşır ve her raf için `rafGoster(i)` çağırır (ekrandan, 00:40:00):

```java
public void tumRaflariGoster(){
    for (int i = 0; i < raf.length; i++){
        System.out.println(i + ". Raftaki Kitaplar");
        rafGoster(i);
    }
}
```

Her raf on kitaplık olduğu için raf gösterme döngüsü on kez döner: sıfırıncı rafta üç kitap yazılır, kalan yedi yer `null` olarak görünür (ekrandan, 00:20:00).

## 5. KitaplıkYonetim Sınıfı

Bu uygulamada yeni bir `KitaplıkYonetim` sınıfı oluşturulmuştur. Testte `KitaplıkYonetim kitaplıkYonetim = new KitaplıkYonetim(kitaplık);` yazılır, yani kitaplık nesnesi yapıcıya parametre olarak gönderilir (ekrandan, 00:25:00). Sınıfın `Kitaplık` adında bir niteliği vardır; yapıcı fonksiyon parametre olarak gelen kitaplığı bu niteliğe eşitler. Bu nitelik yüzünden `KitaplıkYonetim` ile `Kitaplik` arasında mantıksal bir ilişki kurulmuş olur ve diyagramda bu bağlantı kesikli değil düz çizgiyle gösterilir.

## 6. Kalıtımın Java Karşılığı: extends ve super

### 6.1 Üst sınıf türünde değişken

Bir `X` sınıfından nesne oluşturulduğunda nesne normalde `X` türünde bir değişkenle tutulur. Kalıtım olduğu için şu da söylenebilir: öğrenci kartı aynı zamanda bir karttır. Bu yüzden bir öğrenci kartı nesnesi `Kart` türünde bir değişkenle de tutulabilir. Testteki kod şöyledir (ekrandan, 00:25:00):

```java
Kart hesap1 = new OgrenciKartı(0,"Ali",50);
//    OgrenciKartı hesap1 = new OgrenciKartı(0,"Ali",50);

Kart hesap2 = new YetiskinKartı(1,"Ayse",50);
//    YetiskinKartı hesap2 = new YetiskinKartı(1,"Ayse",50);
```

Yorum satırındaki biçim ile üstteki biçim aynı sonucu verir. `Kart` türündeki bir değişkene hem öğrenci kartı hem yetişkin kartı nesnesi atanabilir. Ancak `OgrenciKartı` türünde bir değişkene `YetiskinKartı` nesnesi atanamaz, çünkü bu iki sınıf arasında kalıtım yoktur; ikisi de yalnız `Kart`'tan kalıtım alır.

**Soru:** `Kart hesap1 = ...` satırı ile yorumdaki `OgrenciKartı hesap1 = ...` satırı birebir aynı değil mi?
**Cevap:** Aynı sonucu verir. Buradaki amaç, nesnenin kart türünde bir değişkenle de tutulabildiğini göstermektir. Kalıtım zaten sınıf tanımında `extends Kart` yazılarak alınır; bu satırda yalnız bir değişkene atama yapılır. Ama yetişkin kartı nesnesi oluşturup türü `OgrenciKartı` yazılırsa bu hatalı olur ve program hata verir.

### 6.2 extends ve super

Kalıtım, sınıf tanımlanırken `extends` anahtar kelimesi ve kalıtım alınacak sınıfın adı yazılarak alınır. Alt sınıfın yapıcısında `super(...)` yazılır. `super`, kalıtım alınan sınıfı ifade eder; hemen ardından parantez açıldığı için bu, üst sınıfın yapıcı fonksiyonuna git ve bu değerleri parametre olarak gönder demektir. `YetiskinKartı` sınıfı (ekrandan, 00:35:00):

```java
public class YetiskinKartı extends Kart{

    public YetiskinKartı(int id, String Sahip, double Bakiye) {
        super(id, Sahip, Bakiye);
    }

    @Override
    public boolean odemeYap(double fiyat) {
        if (getBakiye() >= fiyat){
            setBakiye(getBakiye() - fiyat);
            return true;
        }
        else{
            return false;
        }
    }

}
```

`Kart` sınıfının yapıcısı bu üç değeri alır ve kendi niteliklerine atar (ekrandan, 00:30:00):

```java
public abstract class Kart {

    private int id;
    private String Sahip;
    private double Bakiye;

    public Kart(int id, String Sahip, double Bakiye) {
        this.id = id;
        this.Sahip = Sahip;
        this.Bakiye = Bakiye;
    }

    public int getId() {
        return id;
    }

    public String getSahip() {
        return Sahip;
    }

    public double getBakiye() {
        return Bakiye;
    }

    public void setBakiye(double Bakiye) {
        this.Bakiye = Bakiye;
    }

    public abstract boolean odemeYap(double fiyat);
```

Atama `Kart` sınıfında tanımlanmış değişkenlere yapılır, ama oluşturulan nesne sonuçta bir öğrenci kartıdır. Öğrenci kartı üzerinden `Kart`'taki niteliklere (getter'lar aracılığıyla) erişilir. Faydası: üç dört değişken hem öğrenci kartında hem yetişkin kartında tekrar tekrar yazılmaz, tek yerde yazılır. Bir şey değiştirilmek istendiğinde tek yerden değiştirmek yeter; on yerden değiştirmek zorunda kalmak sıkıntılı bir iştir.

`OgrenciKartı`'nın yapıcısı da üç değeri `super` ile `Kart`'a gönderir; ayrıca öğrenci kartına özgü `bonus` niteliği burada ele alınır. `YetiskinKartı`'nda böyle bir nitelik olmadığı için yapıcı yalnız `super` çağrısından oluşur. <!-- BELİRSİZ: OgrenciKartı'nın kodu karelerde görünmüyor; bonus niteliğinin yapıcıda nasıl başlatıldığı altyazıdan net değil. -->

Ajan `Kart` ve `YetiskinKartı` sınıflarını (paket satırı çıkarılmış, küçük bir `main` eklenmiş) tek dosyada `java` ile çalıştırdı. Ortamda `javac` olmadığı için Java'nın tek dosya kipi (`java Dosya.java`) kullanıldı. 50 bakiyeli yetişkin kartıyla 30'luk ilk ödeme `true` döndü ve bakiye 20.0 oldu; ikinci 30'luk ödeme `false` döndü ve bakiye 20.0'da kaldı. `new Kart(...)` yazmak da beklendiği gibi "Kart is abstract; cannot be instantiated" derleme hatası verdi.

> **Hocanın vurgusu:** Kalıtım çok önemlidir; anlaşılmayan bir yer varsa sorulmalıdır.

## 7. Erişim Belirleyiciler ve Kalıtım

**Soru:** Alt sınıflar (child class) üst sınıfın (super class) fonksiyonlarına doğrudan erişebilir mi?
**Cevap:** Public oldukları sürece erişebilir; buradaki metotların hepsi zaten public'tir. Private bir fonksiyon tanımlanırsa alt sınıflar ona erişemez.

**Soru:** Protected olursa?
**Cevap:** Erişebilir; protected'ın amacı budur. Protected üyeler kalıtım alan sınıfa aktarılır. Public üyelerin ise kalıtımla ilgisi yoktur: `Kart` soyut olmasaydı test sınıfında `Kart x = new Kart(...)` yazıp `x.getId()` ile erişilebilirdi. Derste, protected yapıldığında test sınıfından erişilemeyeceği ama öğrenci kartından erişilebileceği söylendi.

> **Ders sonrası not:** Derste protected bir üyeye test sınıfından erişilemeyeceği söylendi. Java'da protected üyeye alt sınıfların yanında aynı paketteki bütün sınıflardan da erişilebilir. Bu projede `Test` ile `Kart` aynı pakette (`javaapplication6`) olduğu için `Test` protected üyeye erişebilir; yalnız alt sınıflarla sınırlama farklı paketteki sınıflar için geçerlidir. Ajan aynı paketteki bir sınıftan protected bir alana erişimi `java` ile denedi, hata çıkmadı.

**Soru:** `Kart`'ı abstract yapmamızın sebebi `extends` ile kullanmak mı?
**Cevap:** Hayır, `abstract` yazılmasa da kalıtım alınabilirdi. Örneğin başkalarının kullanacağı bir kütüphane yazıldığında, yazan kişi `Kart`'tan nesne oluşturulmaması gerektiğini bilir; bunu `abstract` yazarak koda yansıtır ve kart nesnesi oluşturulmasına izin vermez. `abstract` yazılmasaydı nesne oluşturulmasına izin verilmiş olurdu; ihtiyaç olmadığı için yine oluşturulmazdı, ama bu bir kural olarak konmuş olmazdı.

**Soru:** Alt sınıflar private'a erişemez dendi, ama buradaki alt sınıflar private niteliklere değer atıyor gibi görünüyor?
**Cevap:** Bunu `super` ile yapar. `super(...)` ile aslında "benim yapıcı fonksiyonuma bu değerleri ata" denir: `Kart`'ın yapıcısı çağrılır ve atama işlemleri öğrenci kartı sınıfının içinde değil `Kart` sınıfının içinde yapılır. Alt sınıfta `getSahip()` çağrılabilir, çünkü bu metot `Kart`'ta tanımlı ve public'tir; alt sınıfta yazılmamış olsa da kalıtımla gelir. Ama alt sınıfın içinde doğrudan `id = 5;` yazıldığında Eclipse "The field Kart.id is not visible" hatası verir; yani alan görüntülenemez, ona ulaşılamaz (derste denendi, 00:31:57).

## 8. toString, Override ve super.toString

`System.out.println(hesap1)` yazıldığında, `hesap1` bir string değil bir nesne olduğu için normalde nesnenin içeriği yazılmaz. `println` kullanıldığında sanki `hesap1.toString()` gizlice çağrılıyormuş gibi olur; nesnenin nasıl yazılacağını `toString` belirler.

`YetiskinKartı` sınıfında `toString` override edilmemiştir. Yine de `println(hesap2)` bir sonuç verir: `Hesap{id=1, Sahip=Ayse, Bakiye=50.0}` (ekrandan, 00:25:00). Bunun nedeni kalıtımdır: `Kart` sınıfında public olarak tanımlanmış ve override edilmiş bir `toString` vardır; bu metot kalıtımla yetişkin kartı sınıfının da metodu olur ve çalışır.

`OgrenciKartı` sınıfında ise `toString` tekrar override edilir. Override "üstüne yazmak" demektir: `@Override public String toString()` yazmak, "kart sınıfındaki `toString`'i çalıştırma, onun yerine benim şimdi yazacağım `toString`'i çalıştır" demektir. Bu metodun içinde önce `super.toString()` çağrılır, yani kalıtım alınan sınıfın `toString`'i çalıştırılır; ardından `+` ile string birleştirme yapılarak bonus değeri eklenir. Çıktı: `Hesap{id=0, Sahip=Ali, Bakiye=50.0} bonus=0.0` (ekrandan, 00:25:00). Bonus başlangıçta sıfır olduğu için sıfır yazar.

## 9. Yapıcı Fonksiyon Zorunlu mu

<!-- BELİRSİZ: Bu cevaba yol açan öğrenci sorusu altyazıda yok (00:36:31-00:36:41 arası); bağlamdan sorunun "yapıcı fonksiyon yazmak gerekli mi" olduğu anlaşılıyor. -->

Yapıcı fonksiyon yazmak gerekli değildir. Bir sınıftan nesne oluşturulurken bir şeyler olması isteniyorsa yapıcı yazılır; parametre alması isteniyorsa parametreleriyle yazılır. Nesne oluşturulurken bir şey olması istenmiyorsa yapıcı yazılmayabilir, hata vermez. Ancak UML diyagramında bir yapıcı gösterilmişse (örneğin `Kitap(...)`, `Raf()`), içi boş olsa bile kodda da yazılmalıdır; diyagramda yer alıyorsa kodda da yer alması gerekir.

> **Ek bilgi (derste anlatılmadı):** Bir sınıfa hiç yapıcı yazılmazsa Java parametresiz bir varsayılan yapıcı ekler. Ancak üst sınıfın yalnız parametreli yapıcısı varsa (buradaki `Kart` gibi), alt sınıfın yapıcısı `super(...)` ile o yapıcıyı açıkça çağırmak zorundadır; bu yüzden kart sınıflarında yapıcı yazmak gereklidir.

## 10. Kitap Satışı: kitapSat, kitapAra ve odemeYap

### 10.1 kitapSat akışı

`KitaplıkYonetim` sınıfındaki `kitapSat` fonksiyonu bir kitap ve bir kart alır. Örneğin `kitapSat(kitap1, hesap1)` çağrısıyla kitap 1, öğrenci kartı olan hesap 1 ile satılacaktır. Akış şöyledir:

- `k.getAd()` ile kitabın adı alınır (`k`, `Kitap` sınıfından bir nesnedir; `getAd` adı döndürür).
- Kitaplığın `kitapAra` fonksiyonu kitabın adıyla çağrılır ve kitabın hangi rafta olduğu (raf numarası) bulunur.
- Kitap hiçbir rafta yoksa `false` döner.
- Kitap varsa `getFiyat()` ile fiyatı alınır ve kartın `odemeYap(fiyat)` fonksiyonuna gönderilir.
- Ödeme gerçekleşirse ("Satış Gerçekleşti." yazılır) kitaplığın `kitapSil(rafNo, kitap)` fonksiyonu çağrılır. Bu, ilgili rafın `kitapSil(k)` fonksiyonunu çağırır; raf `k` bulunana kadar dolaşılır ve bulunan eleman `null` yapılır.
- Ödeme gerçekleşmezse (ne bakiye ne bonus yetiyorsa) "Bakiye Yetersiz." yazılır ve `false` döner.

<!-- BELİRSİZ: KitaplıkYonetim.kitapSat kodu karelerde görünmüyor; akış anlatımdan kuruldu. -->

### 10.2 kitapAra

`Kitaplik.kitapAra` kodu (ekrandan, 00:40:00):

```java
public int kitapAra(String KitapAdı){
    int n = raf.length;
    for (int i = 0; i < n; i++){
        for(Kitap kitap: raf[i].getKitaplar()){
            if(kitap != null && kitap.getAd().equals(KitapAdı))
            {
                System.out.println(i + ". Rafta Kitap var.");
                return i;
            }
        }
    }
    System.out.println("Kitap Yok");
    return -1;
}
```

Fonksiyon önce raf sayısını alır ve bütün rafları dolaşır. Her rafın `getKitaplar()` fonksiyonu (önceki uygulamadan; `return kitaplar;`) o raftaki kitap dizisini döndürür. İç döngüde `kitap` değişkeniyle dizinin elemanları tek tek tutulur; eleman `null` değilse ve adı aranan adla eşitse kitap bu raftadır ve rafın numarası `i` döndürülür. Hiçbir rafta bulunamazsa "Kitap Yok" yazılır ve `-1` döner.

Aynı karede `kitapSil`, `rafGoster` ve `tumRaflariGoster` de görünür (ekrandan, 00:40:00):

```java
public void kitapSil(int RafNo, Kitap k){
    raf[RafNo].kitapSil(k);
}
public void rafGoster(int n){
    raf[n].rafGoster();
}
```

### 10.3 odemeYap: dinamik bağlama

`hesap1` `Kart` türünde bir değişkendir ama gösterdiği nesne bir öğrenci kartıdır. Bu yüzden `kart.odemeYap(fiyat)` çağrıldığında `OgrenciKartı` sınıfındaki `odemeYap` çalışır. Bu metot override edilmiştir; çünkü `Kart`'ta `public abstract boolean odemeYap(double fiyat);` olarak gövdesiz tanımlanmıştır ve kalıtım alan alt sınıflar onu kendi istedikleri biçimde doldurur.

> **Ek bilgi (derste anlatılmadı):** Üst sınıf türündeki bir değişken üzerinden çağrılan metodun, nesnenin gerçek türündeki sürümünün çalışmasına çok biçimlilik (polymorphism) ya da dinamik bağlama denir. Bu örnekte aynı `kitapSat` kodu, kart türüne göre farklı ödeme kurallarını çalıştırır.

### 10.4 Öğrenci kartında ödeme

`OgrenciKartı.odemeYap` anlatıma göre şöyle çalışır:

- `getBakiye()` çağrılır. Bu fonksiyon `OgrenciKartı`'nda yazılmamıştır; kalıtım alınan `Kart`'tadır.
- Bakiye fiyattan büyükse (kitabı alacak para varsa), bakiyeden fiyat çıkarılır ve sonuç `setBakiye` ile yeni bakiye yapılır. Hocanın örneği: 100 lira bakiyeyle 20 liralık kitap alınırsa 80 lira kalır ve bakiye 80 olarak güncellenir.
- Kitap alındığında fiyatın %20'si kadar bonus kazanılır ve `true` döner.
- Bakiye yetmiyorsa bonusa bakılır; bonus fiyatı karşılayabiliyorsa ödeme bonustan yapılır.
- İkisi de yetmiyorsa `false` döner.

<!-- BELİRSİZ: OgrenciKartı.odemeYap kodu karelerde görünmüyor. Altyazıda "fiyattan büyükse" denir; kodda büyük mü, büyük-eşit mi kullanıldığı görülemedi. -->

Sayısal akış (anlatımdan): `hesap1` başta 50 bakiye ve 0 bonusla yazdırılır. Kitap 1-5 satıldıktan sonra yeniden yazdırıldığında bakiye 0, bonus 10'dur. Bonus, bakiyeden harcanan toplamın %20'sidir: $50 \times 0{,}20 = 10$. Ardından kitap 6 da satılır ve bonus 0'a iner; yani kitap 6 bonusla ödenmiştir. <!-- BELİRSİZ: Kitap fiyatları karelerde görünmüyor; ara bakiyeler doğrulanamadı. -->

### 10.5 Yetişkin kartında ödeme

Yetişkin kartında da `odemeYap` override edilir, ama yalnız bakiyeye bakılır, çünkü yetişkin kartında bonus puanı yoktur. Bakiye yetiyorsa bakiyeden düşülür, yetmiyorsa `false` döner (kod Bölüm 6.2'de).

Testte `hesap2` için aynı satış dizisi uygulanır (ekrandan, 00:45:00):

```java
kitaplıkYonetim.kitapSat(kitap1, hesap2);
kitaplıkYonetim.kitapSat(kitap2, hesap2);
kitaplıkYonetim.kitapSat(kitap3, hesap2);
kitaplıkYonetim.kitapSat(kitap4, hesap2);
kitaplıkYonetim.kitapSat(kitap5, hesap2);
System.out.println(hesap2);
kitaplıkYonetim.kitapSat(kitap6, hesap2);
```

Konsol çıktısının sonu (ekrandan, 00:50:00):

```text
1. Rafta Kitap var.
Satış Gerçekleşti.
1. Rafta Kitap var.
Satış Gerçekleşti.
Hesap{id=1, Sahip=Ayse, Bakiye=0.0}
2. Rafta Kitap var.
Bakiye Yetersiz.
```

Yetişkin kartının bakiyesi 50'den 0'a düşmüştür. Bir kitap daha satın alınmak istendiğinde `odemeYap` `false` döndürür ve "Bakiye Yetersiz." yazılır.

## 11. Fonksiyon Aşırı Yükleme

Örnek projede yer almasa da fonksiyon aşırı yükleme (overloading) Eclipse'te küçük bir örnekle gösterildi. <!-- BELİRSİZ: Örnekteki metodun adı ve gövdesi altyazıdan net çıkmıyor (Whisper bozuk), bu ana ait kare yok. -->

- Aynı adla, parametresiz iki `public static String` metot yazıldığında derleyici aynı metodun iki kez yazıldığını söyleyip hata verdi.
- Metotlardan birine `String s` parametresi eklenince hata kalktı: aynı adla yeni bir fonksiyon oluşmuş oldu.
- Metotlardan birinin yalnız dönüş türü `String` yerine `int` yapıldığında hata kalkmadı: yalnız dönüş türünün farklı olması aşırı yükleme sağlamaz.
- Parametresiz, `(String s, String y)` ve `(int s, int y)` parametreli aynı adlı metotlar birlikte yazılabildi.

Tanım: Aynı adla, farklı sayıda ya da farklı türde parametre alan fonksiyonlar yazmaya fonksiyon aşırı yükleme denir.

Ajan bu durumu tek dosyalık bir Java programıyla denedi:

```java
public class Asiri {
  public static String f(){ return "0"; }
  public static String f(String s, String y){ return "2s"; }
  public static String f(int s, int y){ return "2i"; }
  public static void main(String[] a){ System.out.println(f()+f("a","b")+f(1,2)); }
}
```

Program `02s2i` yazdı. Aynı sınıfa `public static int f(){ return 0; }` eklenince "method f() is already defined" derleme hatası alındı. (Bu kod derste yazılmadı; ajan derste gösterilen kuralları denemek için yazdı.)

> **Ek bilgi (derste anlatılmadı):** Aşırı yükleme (overloading) ile override farklı kavramlardır. Aşırı yüklemede aynı sınıfta aynı adlı, farklı parametreli metotlar vardır ve hangisinin çağrılacağı derleme zamanında parametrelere göre seçilir. Override'da ise alt sınıf, üst sınıftaki aynı imzalı metodu yeniden yazar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:25): `Kart hesap1 = new OgrenciKartı(0,"Ali",50);` ile `OgrenciKartı hesap1 = new OgrenciKartı(0,"Ali",50);` arasında sonuç bakımından fark var mıdır?

> **Cevap (derste verildi):** Fark yoktur, ikisi de aynı nesneyi oluşturur. Kalıtım `class OgrenciKartı extends Kart` tanımında alınır; değişkenin türü yalnız nesneyi hangi türden bir değişkenle tuttuğumuzu belirler. Ama bir `YetiskinKartı` nesnesi `OgrenciKartı` türünde bir değişkene atanamaz.

**Soru 2** (derste sözlü, 00:28:38 ve 00:29:10): Alt sınıflar üst sınıfın public, private ve protected üyelerine doğrudan erişebilir mi?

> **Cevap (derste verildi):** Public ve protected üyelere erişebilir, private üyelere erişemez. (Protected için aynı paket kuralı Bölüm 7'deki ders sonrası notta.)

**Soru 3** (derste sözlü, 00:29:49): `Kart` sınıfını abstract yapmanın amacı nedir; abstract olmasa kalıtım alınamaz mı?

> **Cevap (derste verildi):** Abstract olmasa da kalıtım alınabilirdi. Abstract, bu sınıftan nesne oluşturulmasını yasaklamak, yani kullanıcıya "kart nesnesi oluşturulmaz" kuralını açıkça koymak içindir.

**Soru 4** (derste sözlü, 00:30:48): Private niteliklere alt sınıftan erişilemiyorsa, alt sınıfların yapıcıları bu niteliklere nasıl değer verir?

> **Cevap (derste verildi):** `super(id, Sahip, Bakiye)` ile üst sınıfın yapıcısı çağrılır ve atamalar `Kart` sınıfının içinde yapılır. Alt sınıfta doğrudan `id = 5;` yazmak "The field Kart.id is not visible" hatası verir.

## Dersin Toparlaması

Bu oturumda kitaplık uygulaması kart sistemi ve kitap satışıyla genişletildi. UML'de kalıtım okunun nasıl çizildiği, soyut sınıf ve soyut metodun anlamı, kesikli ok (yalnız kullanma) ile düz çizgi (nitelik olarak tutma) arasındaki fark diyagram üzerinde gösterildi. Java tarafında `extends` ile kalıtım, `super(...)` ile üst sınıf yapıcısını çağırma, `super.toString()` ile üst sınıf metodunu kullanma, override ve üst sınıf türündeki bir değişkenle alt sınıf nesnesi tutma kod üzerinde izlendi. Erişim belirleyicilerin kalıtımla ilişkisi (private görünmez, public ve protected kullanılabilir) öğrenci sorularıyla netleştirildi.

Kitap satışı örneğinde aynı `kitapSat` kodu, kartın gerçek türüne göre farklı ödeme kurallarını çalıştırdı: öğrenci kartı bonus kazanıp bonusla ödeyebilirken yetişkin kartı yalnız bakiyesini kullandı. Son olarak aynı adla farklı parametreli metotlar yazmak anlamına gelen fonksiyon aşırı yükleme gösterildi ve yalnız dönüş türünü değiştirmenin yetmediği vurgulandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
