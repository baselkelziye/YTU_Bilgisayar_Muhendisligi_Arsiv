# Ders 5 Genişletilmiş Notu: Uygulama 1: Kitaplık Örneğiyle Sınıflar, UML ve Kapsülleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulamanın konusu ve örnek sistem
- 2. UML sınıf diyagramı
- 3. Sınıflar arası ilişkiler
- 4. Eclipse'te proje, sınıf ve paket
- 5. Kitap sınıfı: nitelikler, kapsülleme, constructor, final ve static
- 6. Getter, setter ve toString
- 7. Kitaplık ve Raf sınıfları: nesne dizileri
- 8. Kitap ekleme ve rafı gösterme
- 9. Kitap silme
- 10. Geliştirilmiş for döngüsü
- 11. Kitap arama ve compareTo
- 12. Statik değişkene sınıf adıyla erişim
- 13. Bütün rafları gösterme ve setter örneği
- 14. Programın tamamı ve çıktısı
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulamanın konusu ve örnek sistem

Bu kayıt, teorik dersin yanında yürütülen uygulama derslerinin ilkidir ve bir asistan tarafından anlatılır. Amaç, Java'nın temel kavramlarını hiç Java bilinmiyormuş gibi sıfırdan, tek bir örnek üzerinden kodlayarak göstermektir.

Örnek sistem bir kitaplıktır. Bir kitaplık nesnesi oluşturulurken kaç rafı olacağı söylenir. Her rafa istenen kadar kitap eklenebilir. Sistem kitap ekleme, kitap silme, kitap arama, bir rafı gösterme ve bütün rafları gösterme işlerini yapar. Asistan fiziksel bir kitaplık benzetmesi kullanır: odanızdaki kitaplığa bakın, her rafta bir kitap dizisi vardır, kitaplık da raflardan oluşan bir dizidir. Program da tam olarak bu iç içe yapıyı kurar.

## 2. UML sınıf diyagramı

Kodlamaya geçmeden önce sistemin UML sınıf diyagramı gösterilir. UML, gerçekleştirilecek bir tasarımın genel iskeletini önceden ortaya koymayı sağlar ve bu derste sık kullanılacaktır.

Diyagramda her sınıf üç bölmeli bir kutudur. En üstte sınıfın adı yazar. Ortadaki bölmede nitelikler `ad: tip` biçiminde listelenir. Bu bölüme attribute, field ya da sınıf değişkeni anlamında instance variable denir; bunlar o sınıftan oluşturulan her nesnenin sahip olacağı özelliklerdir. En alttaki bölmede o nesne üzerinden çağrılabilecek metotlar vardır: `nesneAdı.metot()` yazıldığında çalışacak olanlar.

Nitelik ve metotların başındaki işaretler rastgele değildir, erişim belirteçlerini gösterir. `-` private demektir: o üye yalnız sınıfın içinden kullanılabilir. `+` public demektir: her yerden erişilebilir.

Ekrandaki diyagram şöyledir (ekrandan, 00:20:00):

```text
Test
  + main(String[]): void

Kitaplik
  - raf: Raf[]
  + Kitaplik(int)
  + kitapEkle(Kitap,int): void
  + kitapSilSıraNo(int,int): void
  + kitapSil(int,Kitap): void
  + kitapAra(String): Kitap
  + gosterRaf(int): void
  + tumRaflariGoster(): void

Raf
  - kitaplar: Kitap[]
  + Raf()
  + KitapEkle(Kitap): void
  + kitapSilSıraNo(int)
  + kitapSil(Kitap)
  + RafGoster(): void
  + getKitaplar(): Kitap[]

Kitap
  - ad: String
  - yazar: String
  - ISBN: String
  - kitapSayisi: <static> int
  + Kitap(String,String,String)
  + getAd(): String
  + getYazar(): String
  + getISBN(): String
  + getKitapSayisi(): int
  + setAd(String): void
  + setYazar(String): void
  + toString(): void

İlişkiler:
  Kitaplik (dolu elmas) ------ Raf     : composition
  Raf      (boş elmas)  ------ Kitap   : aggregation
  Test - - - -> Kitaplik, Test - - - -> Kitap : dependency (kesikli ok)
```

> **Ders sonrası not:** Diyagramda `toString(): void` yazıyor. `toString` her zaman `String` döndürür; doğrusu `toString(): String`. Derste üretilen kod da `String` döndürür. Ayrıca kodda diyagramdaki `gosterRaf` yerine `rafGoster`, `KitapEkle` yerine `kitapEkle` adları kullanıldı; `kitapSilSıraNo` metotları derste yazılmadı.

Diyagram okunurken şuna dikkat çekilir: `Kitap` sınıfında nitelikler basit tiplerdir (`ad` bir String). `Raf` sınıfında ise nitelik `Kitap` tipinde bir dizidir. Normalde `int` dizisinde 3, 5, 10 gibi sayılar, `String` dizisinde metinler durur. `Kitap[]` dizisinde ise kitap nesneleri durur; her biri kendi adı, yazarı ve ISBN'i olan nesnelerdir. Aynı şekilde bir kitaplık nesnesinin rafları, her rafın da kitapları olacaktır.

## 3. Sınıflar arası ilişkiler

Diyagramdaki çizgilerden biri içi dolu, diğeri içi boş elmasla biter. Bunu açıklamak için ders slaytındaki "relationships between classes" (sınıflar arası ilişkiler) bölümü açılır. Nesnelerin tutulduğu sınıflar arasında association denen ilişkiler kurulur ve bunlar güçlü ve zayıf diye ikiye ayrılır.

### 3.1 Güçlü ilişki: composition

Güçlü ilişkide bir sınıf diğeriyle sıkı bir sahiplik ilişkisindedir. Slayttaki örnek bir kişi ile beynidir. Böyle bir ilişki kurulduysa parça büyük olasılıkla bütün üzerinden kullanılır; bütün ortadan kaldırılırsa parçaya artık erişilemez, nesnelerine ulaşılamaz, metotları çağrılamaz. Bu ilişkiye composition denir ve UML'de içi dolu elmasla gösterilir.

### 3.2 Zayıf ilişki: aggregation

Zayıf ilişkide de bütün-parça ilişkisi vardır, ama parçalar ayrı ayrı tanımlanır ve oluşturulur. Slayttaki örnekte yolcular bir arabanın parçasıdır; araba ortadan kaldırılsa da yolcu nesneleri var olmaya devam eder. Bu ilişkiye aggregation denir ve içi boş elmasla gösterilir.

### 3.3 Örnekteki ilişkiler

Kitaplık ile raf arasında composition vardır: kitaplık nesnesi ortadan kalkarsa raflarına da erişilemez. Raf ile kitap arasındaki ilişki bir tık daha zayıftır: kitaplar ayrı ayrı oluşturulacağı için raf nesnesine ulaşılamasa da kitaplara ulaşılmaya devam edilir.

`Test` sınıfı ile diğerleri arasındaki kesikli çizgi dependency (bağımlılık) ilişkisidir. Burada hiyerarşi ya da sahiplik yoktur; `Test` o anlık diğer sınıfların nesnelerini kullanır ve onların metotlarını çağırır. İçinde `main` metodu bulunan bu sınıfa genelde main class ya da test class denir.

## 4. Eclipse'te proje, sınıf ve paket

Uygulamalarda Eclipse kullanılır. İlk adım yeni bir Java projesi oluşturmaktır (File > New > Java Project, ad verilir, Finish). Proje açılınca bir `src` klasörü görünür; eklenen sınıflar onun altında listelenir. İkinci adım sınıfları oluşturmaktır: `Test`, `Kitaplık`, `Raf` ve `Kitap`.

Sınıf oluşturulurken paket adı verilmezse Eclipse sınıfı varsayılan pakete (default package) koyar ve bir uyarı verir. Paketlerin amacı, çok sayıda sınıfın olduğu bir projede benzer işleri yapan sınıfları bir arada toplayıp düzeni ve erişimi kolaylaştırmaktır. Bir sınıf bir pakete aitse dosyanın en başına `package paketAdı;` yazılır. Bu örnekte tek paket kullanıldığı için buna gerek yoktur.

**Soru:** Eclipse'in MacBook için sürümü var mı? Kurulumda sorun çıktı. **Cevap:** Var. Sorun büyük olasılıkla işletim sistemi sürümüyle ilgilidir; güncel değilse Eclipse'in eski sürümlerine bakmak gerekebilir.

`main` metodu `public static void main(String[] args)` biçiminde yazılır. Eclipse'te `main` yazıp Ctrl+Space'e basınca metot hazır gelir; `sysout` yazıp Ctrl+Space'e basınca `System.out.println()` gelir. C'deki `main` fonksiyonu gibi program `main` metodunun içinden okunarak başlar. C'deki fonksiyonun Java'daki karşılığı metottur.

## 5. Kitap sınıfı: nitelikler, kapsülleme, constructor, final ve static

### 5.1 Nitelikler ve kapsülleme

Kitap sınıfının nitelikleri UML'den alınarak yazılır (ekrandan, 00:40:00):

```java
public class Kitap {

    private String ad;
    private String yazar;
    private final String ISBN;
    private static int kitapSayisi;
```

Nitelikler public de yapılabilirdi, ama nesneye yönelik programlamanın mantığı buna karşıdır. Sınıfın nesnelerinin aldığı değerlere dışarıdaki biri doğrudan ulaşmamalı, metotlar üzerinden ulaşmalıdır. Veri metotlarla sarıldığı için buna encapsulation (kapsülleme) denir. Örneğin dışarıdan biri kitabın adına `kitap.ad` diye ulaşamaz, ancak public `getAd()` metodunu çağırabilir. Sınıf, bu metodun içini istediği gibi doldurur: isterse adın tamamını değil yalnız ilk iki harfini gösterir. Böylece dışarıdaki kod ancak sınıfın verdiği erişim izni kadarını görür. Bu yüzden sınıf değişkenleri genelde private yapılır.

### 5.2 Nesne oluşturma ve constructor

`Test` sınıfında bir nesne şöyle oluşturulur: önce sınıfın adı, sonra nesnenin adı, eşittir, `new` ve yine sınıfın adı. `new Kitap(...)` yazımında sanki bir metot çağrılıyormuş gibi parantez vardır. Gerçekten de her nesne oluşturulurken o sınıfın yapılandırıcı metodu, yani constructor'ı çalışır. Constructor, sınıfla aynı adı taşıyan bir metot gibi düşünülebilir.

Constructor yazılmadan bırakılırsa nesne hiçbir niteliği doldurulmamış, boş bir nesne olarak oluşur; sonra her niteliğe tek tek değer atamak gerekir. Bu kalabalıktan kurtulmak için constructor, nesne ilk oluşurken gerekli değerleri parametre olarak alacak biçimde yazılır. Kitap için ad, yazar ve ISBN alınır.

> **Ders sonrası not:** Asistan, constructor yazılmasa da Java'nın onu zaten kendisi oluşturduğunu söyledi. Bu yalnız sınıfta hiç constructor yazılmamışsa doğrudur (parametresiz varsayılan constructor). `Kitap(String, String, String)` yazıldıktan sonra `new Kitap()` derlenmez.

### 5.3 this anahtar sözcüğü

Constructor'da parametrenin adı nitelikle aynı olunca `ad = ad;` yazmak derleyici açısından anlamsızdır: hangi `ad`? Ekranda Eclipse bu satır için "The assignment to variable ad has no effect" uyarısı verir (ekrandan, 00:40:00). Bunu çözmek için nitelik `this.ad` diye belirtilir: "bu sınıfın `ad` niteliği, gönderdiğim `ad` parametresine eşit olsun." Yazar için de aynısı yapılır. `ISBN` niteliği ile `isbn` parametresi ise büyük-küçük harf farkından dolayı Java için farklı adlardır, orada `this` gerekmez:

```java
    public Kitap(String ad, String yazar, String isbn) {
        this.ad = ad;
        this.yazar = yazar;
        ISBN = isbn;
        kitapSayisi++;
    }
```

Son satır, ekrandaki karelerde görünmüyor; asistanın anlatımından ve programın sonunda sayacın 4 yazdırmasından kuruldu.

### 5.4 final

`final` bir değişkenin sabit kalacağını söyler. Constructor çalışıp `ISBN`'e bir değer verildikten sonra bu değer bir daha değiştirilemez. Kitabın adı ve yazarı ise final olmadığı için sonradan değiştirilebilir.

### 5.5 static

`static` nitelik bir nesneye değil, sınıfa ait bir değişkendir. `kitapSayisi` 5 yapılırsa bütün nesneler için 5'tir; bir nesnenin metodu onu 6 yaparsa bütün nesneler için 6 olur. Ad ve yazar ise her nesnede, o nesne oluşturulurken verilen değere göre farklıdır.

> **Ders sonrası not:** Asistan bir yerde kitap sayısının "hiçbir şekilde değişmeyecek" olduğunu söyledi. Kastedilen, değerin bütün nesneler için ortak olmasıdır. Değerin kendisi değişebilir; aşağıdaki sayaç örneği de buna dayanır.

Statik değişkenler örneğin bir sınıftan kaç nesne oluşturulduğunu saymak için kullanılır. Her constructor çalıştığında sayaç bir artırılır: 1, 2, 3, ... Programın sonunda sayacın değerine bakılınca kaç nesne oluşturulduğu görülür.

## 6. Getter, setter ve toString

### 6.1 Getter ve setter üretmek

Nitelikler private olduğu için dışarıdan okunup değiştirilebilmeleri için get ve set metotları yazılır. Eclipse'te sağ tık > Source > Generate Getters and Setters seçilince bütün nitelikler listelenir. `ISBN` için yalnız getter sunulur, çünkü final bir niteliği set etmek mümkün değildir. `kitapSayisi` için de dışarıdan okunabilsin diye getter alınır. Üretilen metotlar (ekrandan, 00:45:00):

```java
    public String getAd() {
        return ad;
    }

    public void setAd(String ad) {
        this.ad = ad;
    }

    public String getYazar() {
        return yazar;
    }

    public void setYazar(String yazar) {
        this.yazar = yazar;
    }

    public static int getKitapSayisi() {
        return kitapSayisi;
    }
```

`getISBN()` da benzer biçimde üretilir. Asistan, metotların imlecin bulunduğu yere eklendiğini, bu yüzden Source menüsü açılmadan önce imlecin nereye tıklandığının önemli olduğunu belirtir; constructor'ın yukarıda kalması için kod yeniden düzenlenir.

`getAd`, `setAd` adları değişken adından otomatik türetilir. Başka ad da verilebilir, ama bu adlandırma okuyana metodun ne yaptığını söyler: `get` ile nesnenin içi okunur, `set` ile içine yeni bir değer yazılır.

### 6.2 Kitapları oluşturmak ve yazdırmak

`Test` sınıfında dört kitap oluşturulur ve ilk kitabın yazarı ile kendisi yazdırılır (ekrandan, 00:50:00):

```java
        Kitap kitap1 = new Kitap("Kitap1", "Yazar1", "1234");
        Kitap kitap2 = new Kitap("Kitap2","Yazar2","7345");
        Kitap kitap3 = new Kitap("Kitap3","Yazar3","5345");
        Kitap kitap4 = new Kitap("Kitap4","Yazar4","2345");

        System.out.println(kitap1.getYazar());
        System.out.println(kitap1);
```

Nesne adından sonra nokta konunca Eclipse o nesne üzerinden çağrılabilecek metotları listeler. `kitap1.getYazar()` bir String döndürdüğü için ekrana `Yazar1` yazılır. `kitap1` doğrudan yazdırılınca ise ekranda `Kitap@7852e922` gibi tuhaf bir değer çıkar (ekrandan, 00:50:00). Bunun nedeni, Java'ya bu nesnenin nasıl okunacağının söylenmemiş olmasıdır.

> **Ek bilgi (derste anlatılmadı):** Bu değer `Object` sınıfındaki varsayılan `toString` metodunun çıktısıdır: sınıf adı, `@` ve nesnenin hash kodunun onaltılık yazımı. Değer çalıştırmadan çalıştırmaya değişebilir.

### 6.3 toString metodunu override etmek

Nesnenin içeriğini okumak için `toString` metodu kullanılır. Bu metot Java'da önceden tanımlıdır. Java'daki bütün sınıflar `Object` sınıfının alt sınıfları gibi düşünülebilir; üst sınıfta tanımlı bir metot alt sınıfta override edilerek içi istendiği gibi doldurulabilir. Kalıtım bir sonraki uygulamanın konusu olacaktır.

`toString` elle de yazılabilir, ama Source > Generate toString() ile Eclipse'e de ürettirilebilir. Üretilen metot bir `String` döndürür; `return` ile tırnak içindeki sabit metinler ve araya eklenen nitelik değerleri birleştirilir. İçi istenirse değiştirilir, örneğin yalnız ad gösterilebilir. `Test` tarafında hiçbir değişiklik yapmadan program yeniden çalıştırılınca aynı `println(kitap1)` satırı artık şunu yazar (ekrandan, 00:55:00):

```text
Yazar1
Kitap [ad=Kitap1, yazar=Yazar1, ISBN=1234]
```

```java
    @Override
    public String toString() {
        return "Kitap [ad=" + ad + ", yazar=" + yazar + ", ISBN=" + ISBN + "]";
    }
```

Metodun gövdesi ekrandaki çıktının biçiminden kuruldu; karelerde metnin kendisi görünmüyor.

> **Ders sonrası not:** Asistan elle yazımı "public void string" diye söyledi. Doğru imza `public String toString()`'dir; dönüş tipi `void` olamaz.

## 7. Kitaplık ve Raf sınıfları: nesne dizileri

### 7.1 Kitaplık constructor'ı

`main` içinde `Kitaplık kitaplık = new Kitaplık(5);` yazılır: beş raflı bir kitaplık. Böyle bir constructor henüz olmadığı için Eclipse hata verir ve "Create constructor" önerisiyle constructor oluşturulur.

Composition ilişkisini sağlamak için kitaplık oluşur oluşmaz rafları da constructor içinde oluşturulmalıdır. UML'e göre kitaplığın niteliği `Raf` tipinde nesneleri tutan private bir dizidir: `private Raf[] raf;` (ekrandan, 00:55:00). Constructor iki iş yapar. Önce `raf = new Raf[n];` ile n elemanlı bir dizi oluşturulur. Sonra bu dizinin her elemanının bir `Raf` nesnesi olması gerekir; bunun için raf sınıfının constructor'ı çalıştırılarak her göze yeni bir nesne konur. `raf[0] = new Raf();`, `raf[1] = new Raf();` ... diye tek tek yazmak yerine bir `for` döngüsü kullanılır. Ekrandaki döngü (ekrandan, 01:05:00):

```java
    public Kitaplık(int n) {
        raf = new Raf[n];
        for(int i=0;i<n;i++){
            raf[i]=new Raf();
        }
    }
```

Bu karede `raf = new Raf[n];` satırı yoktur. Asistan bu satırı daha önce yazıp yanlışlıkla silmişti; program çalıştırılınca `Kitaplık` sınıfının 9. satırında hata alındı (01:12:30) ve satır geri eklenerek düzeltildi (01:13:16). Asistanın açıklaması şudur: `new Raf[n]` dizinin tanımıdır, döngüdeki satır ise dizinin her elemanının bir `Raf` nesnesi olduğunun tanımıdır; ikisi ayrı adımlardır.

> **Ek bilgi (derste anlatılmadı):** Dizi oluşturulmadan `raf[i] = ...` yazılırsa `raf` hâlâ `null` olduğu için `NullPointerException` fırlatılır. Ajan bu durumu denedi; Java "this.raf is null" iletisiyle bu istisnayı veriyor.

### 7.2 Raf sınıfı

Her raf nesnesi de kendi içinde bir dizi tutar: dizi içinde dizi. UML'e göre bu dizi private ve `Kitap` tipindedir (ekrandan, 01:00:00):

```java
public class Raf {

    private Kitap [] kitaplar ;

    public Raf(){
        kitaplar = new Kitap[10];
    }
```

Nitelik satırı yalnız başlangıç tanımıdır; dizi henüz bellekte yer kaplamaz. Constructor çalışınca dizi oluşturulur. Başlangıçta sabit bir değer verilir: her rafta 10 kitaplık yer ayrılır. Constructor satırı karede boş görünür; `new Kitap[10]` ataması anlatımdan alındı ve programın çıktısındaki 10 satırlık raf listesiyle doğrulanır.

Özetle: kitaplık oluşturulurken bir raf sayısı verilir; bu sayı kadar elemanlı bir raf dizisi oluşur; dizinin her elemanı bir raf nesnesidir ve her raf nesnesi de 10 elemanlı bir kitap dizisi tutar.

## 8. Kitap ekleme ve rafı gösterme

### 8.1 Kitaplık tarafında kitapEkle

Kitap eklemek için `kitaplık.kitapEkle(kitap1, 0);` gibi bir çağrı istenir. Metot public olacak, bir şey döndürmeyecek (`void`), iki parametre alacaktır: eklenecek `Kitap` nesnesi (kısaca `ktp`) ve hangi rafa ekleneceğini gösteren tamsayı `rafNo`. İlk raf 0 numaralıdır.

Ekleme iki aşamalı tasarlanır. Kitaplık sınıfının üyesi raf dizisidir; kitaplık, dizinin `rafNo` numaralı elemanına gidip o rafın `kitapEkle` metodunu çağırır. Raf sınıfında böyle bir metot olmadığı için Eclipse hata verir ve "Create method" ile metot raf sınıfında public olarak oluşturulur:

```java
    public void kitapEkle(Kitap ktp, int rafNo){
        raf[rafNo].kitapEkle(ktp);
    }
```

### 8.2 Raf tarafında kitapEkle

Artık doğru raftayız, yani `kitaplar` dizisindeyiz. Mantık şudur: dizi gezilir, ilk boş bulunan yere kitap eklenir. Döngü dizinin uzunluğu (`kitaplar.length`) kadar döner. Bir göz `null` ise kitap oraya yerleştirilir.

Asistan burada önemli bir noktaya dikkat çeker: kod bu hâlde bırakılırsa döngü devam eder ve sonraki boş gözlere de aynı kitabı koyar; bütün raf aynı kitapla dolar. Bu yüzden ekleme yapılınca `break` ile döngüden çıkılır. Başka satır olmadığı için metot da biter. Metot `void` değil de örneğin `int` dönüşlü olsaydı `return 0;` ile de çıkılabilirdi.

```java
    public void kitapEkle(Kitap ktp) {
        for (int i = 0; i < kitaplar.length; i++) {
            if (kitaplar[i] == null) {
                kitaplar[i] = ktp;
                break;
            }
        }
    }
```

Raf tarafındaki bu metotların gövdeleri karelerde görünmüyor; anlatımdan kuruldu ve ekrandaki çıktılarla aynı sonucu verdiği denendi.

### 8.3 rafGoster

Eklenen kitapları görmek için `kitaplık.rafGoster(0);` çağrısı istenir: sıfırıncı rafı göster. Yine iki aşamalıdır. Kitaplık tarafı rafın numarasını alıp o rafın `rafGoster` metodunu çağırır (ekrandan, 01:20:00):

```java
    public void rafGoster(int rafNo) {
        raf[rafNo].rafGoster();
    }
```

Raf tarafında `kitaplar` dizisi bir `for` döngüsüyle gezilir ve her eleman yazdırılır. `main` içinde üç kitap 0. rafa eklenir. Ekrandaki kodda bir an `kitapEkle(kitap1, 0)` iki kez yazılmıştı (ekrandan, 01:10:00); sonra üçüncü çağrı `kitap3` olarak düzeltildi. Çıktıda Kitap1'in iki kez görünmesi asistanı bir an şaşırtır: ilk satırın daha önceki `println(kitap1)` satırından geldiği anlaşılır ve bölümler birbirinden ayrılsın diye araya `System.out.println(" ---------------------- ");` satırları konur. Sonuç (ekrandan, 01:15:00):

```text
Yazar1
Kitap [ad=Kitap1, yazar=Yazar1, ISBN=1234]
 ----------------------
Kitap [ad=Kitap1, yazar=Yazar1, ISBN=1234]
Kitap [ad=Kitap2, yazar=Yazar2, ISBN=7345]
Kitap [ad=Kitap3, yazar=Yazar3, ISBN=5345]
null
null
null
null
null
null
null
```

Rafın 10 gözünden üçü dolu, kalan yedisi boştur. Boş gözler `null` olarak yazılır.

## 9. Kitap silme

Silme, eklemenin tam tersidir. Eklemede boş bulunan yere ekleniyordu; silmede verilen kitabın bulunduğu yer bulunur ve orası `null` yapılır. Çağrı `kitaplık.kitapSil(0, kitap1);` biçimindedir: hangi raf ve hangi kitap. Kitap burada kitabın adı (`"Kitap1"`) olarak değil, nesnenin kendisi olarak gönderilir.

Kitaplık tarafı yine işi ilgili rafa devreder (ekrandan, 01:20:00):

```java
    public void kitapSil(int rafNo, Kitap ktp) {
        raf[rafNo].kitapSil(ktp);
    }
```

Raf tarafında dizi, aranan kitap bulunana kadar gezilir. `kitaplar[i]` gönderilen kitap nesnesiyle aynıysa o göz `null` yapılır. Silme yapıldıktan sonra döngüyü sürdürmeye gerek olmadığından `break` ile çıkılır:

```java
    public void kitapSil(Kitap ktp) {
        for (int i = 0; i < kitaplar.length; i++) {
            if (kitaplar[i] == ktp) {
                kitaplar[i] = null;
                break;
            }
        }
    }
```

<!-- BELİRSİZ: Karşılaştırmanın ekranda == ile mi yoksa equals ile mi yazıldığı karelerde görünmüyor; altyazıda yalnız "eşitse" deniyor. Aynı nesne gönderildiği için iki yazım da bu örnekte aynı sonucu verir. -->

Asistan ilk denemede yanlış metot adı çağırdığını ve dosyayı kaydetmediğini fark eder; düzeltip yeniden çalıştırınca ilk göz boşalmıştır (ekrandan, 01:20:00):

```text
null
Kitap [ad=Kitap2, yazar=Yazar2, ISBN=7345]
Kitap [ad=Kitap3, yazar=Yazar3, ISBN=5345]
null
...
```

## 10. Geliştirilmiş for döngüsü

Diziler hep bir iterasyonla gezildiği için Java'da daha toparlanmış, basitleştirilmiş bir döngü yazımı vardır: enhanced for (geliştirilmiş for). Raf gösterme döngüsü bununla şöyle yazılır:

```java
    public void rafGoster() {
        for (Kitap iter : kitaplar)
            System.out.println(iter);
    }
```

Okunuşu şudur: `Kitap` tipinde nesnelerin bulunduğu `kitaplar` dizisi `iter` adlı bir yineleyiciyle gezilecek; her adımda karşıya bir kitap nesnesi gelir ve o yazdırılır. Asistan, burada nesnenin tamamının yazdırıldığını; istenirse `iter.getAd()` ile yalnız adın alınabileceğini de belirtir.

> **Ek bilgi (derste anlatılmadı):** Derste döngü değişkenine "iterator" deniyor, ama bu yazımda `iter` sıradan bir `Kitap` değişkenidir. Java'da ayrıca `java.util.Iterator` diye bir arayüz vardır; geliştirilmiş for, koleksiyonlarda arka planda onu kullanır.

## 11. Kitap arama ve compareTo

### 11.1 Aramanın mantığı

`kitaplık.kitapAra("Kitap2");` çağrısı, verilen ada sahip kitap varsa nerede olduğunu yazmalı, yoksa bulunamadığını söylemelidir. Burada gönderilen, nesne adı değil kitabın ad niteliğidir.

**Soru (asistanın sorusu):** Aradığınız kitabın kitaplıkta olup olmadığını nasıl bulursunuz? **Cevap:** Odadaki kitaplıkta bir kitabı ararken raflara sırayla bakarız: birinci rafı tararız, sonra alt rafa geçeriz. Programda da iç içe iki döngü kurulur. Dıştaki döngü rafları gezer; içteki döngü o raftaki kitapları tek tek okur.

### 11.2 Private diziye erişim: getKitaplar

İç döngüde `kitaplar` dizisi doğrudan yazılamaz, çünkü bu dizi `Raf` sınıfının private üyesidir. Erişim için `Raf` sınıfına bir getter eklenir (yalnız get, set gerekmez). Asistan getter ve setter'ları baştan almanın en mantıklısı olduğunu söyler. Artık `raf[i].getKitaplar()` yazılınca o rafın kitap dizisi elde edilir.

```java
    public Kitap[] getKitaplar() {
        return kitaplar;
    }
```

### 11.3 compareTo ile karşılaştırma

Kitabın adı da private olduğu için `iter.ad` yazılamaz; `iter.getAd()` kullanılır. Ad, String'lerde tanımlı `compareTo` metoduyla gönderilen String (`str`) ile karşılaştırılır. Asistanın anlatımıyla `compareTo` iki String'e birer sayısal değer verip birbirinden çıkarır gibi çalışır: sonuç 0 ise iki String aynıdır; -5 ya da 10 gibi sıfırdan farklı bir değer çıkarsa farklıdır.

> **Ek bilgi (derste anlatılmadı):** `compareTo` sözlük sırasına göre karşılaştırır: ilk farklı karakterlerin kod farkını, biri ötekinin başıysa uzunluk farkını döndürür. Yalnız eşitlik sorulacaksa `equals` metodu daha yaygın kullanılır. `==` ise iki String değişkeninin aynı nesneyi gösterip göstermediğine bakar, içeriği karşılaştırmaz.

Boş gözlerde `getAd()` çağrılırsa hata çıkacağı için önce `iter != null` kontrol edilir.

### 11.4 Dönüş tipi ve bulunamama durumu

Kitap bulununca `printf` ile rafın numarası yazılır. `%d` yerine sayısal bir değer, burada raf sayacı `i` gelir. Bulunduktan sonra metodun bitmesi istenir; bunun için `return` kullanılır. Ancak metot `void` tanımlandığı için bir şey döndüremez. Bu yüzden dönüş tipi `Kitap` yapılır ve bulunan nesne `iter` döndürülür.

Bu kez Eclipse, döngüden istenen sonuç çıkmazsa ne döneceğini sorar. Döngülerin sonuna "aranan kitap bulunamadı" yazdıran bir satır ve `return null;` eklenir. `printf` alt satıra geçmediği için çıktıya ayrıca satır sonu eklenmesi gerekir. Ekrandaki kod (ekrandan, 01:30:00):

```java
    public Kitap kitapAra(String str) {
        for(int i=0; i<raf.length;i++)
            for(Kitap iter:raf[i].getKitaplar())
                if(iter!=null)
                    if(iter.getAd().compareTo(str)==0){
                        System.out.printf("aranan kitap %d. rafta bulunuyor.", i);
                        return iter;
                    }
        System.out.println("aranan kitap bulunamadı");
        return null;
    }
```

Karede `return` satırı yazılmakta, son iki satır henüz yoktur; onlar anlatımdan alındı. Satır sonunun nasıl eklendiği karede görünmüyor; çıktıda iki ileti ayrı satırlarda olduğu için ajanın denediği sürümde biçim metninin sonuna `\n` eklendi.

### 11.5 Arama, silme, yeniden arama

`main` içinde Kitap2 aranır, sonra 0. raftan silinir ve yeniden aranır. İlk aramada kitap bulunur, ikincisinde bulunamaz (ekrandan, 01:35:00):

```text
aranan kitap 0. rafta bulunuyor.
aranan kitap bulunamadı
```

## 12. Statik değişkene sınıf adıyla erişim

Kaç kitap nesnesi oluşturulduğunu görmek için statik sayaç kullanılır. Ad ve yazar gibi nitelikler nesnenin özellikleri olduğu için nesne üzerinden erişilir. Statik değişken ise belli bir nesneye ait olmadığından nesne oluşturmaya gerek kalmadan sınıfın adıyla erişilir. `kitapSayisi` private olduğu için doğrudan değil, statik getter ile okunur:

```java
        System.out.println(Kitap.getKitapSayisi());
```

Ekranda `4` yazar (ekrandan, 01:35:00). Constructor her nesne oluştuğunda sayacı artırmıştır. Asistan, sayaca başlangıç değeri verilmediğinde ilk değerinin 0 olduğunu belirtir.

## 13. Bütün rafları gösterme ve setter örneği

### 13.1 tumRaflariGoster

Parametresiz `tumRaflariGoster()` metodu çağrılınca bütün kitaplığın raflarını listelemelidir. Kitaplık sınıfında raf dizisi bir `for` döngüsüyle `raf.length` kadar gezilir. Her rafta önce "i. Raftaki Kitaplar:" başlığı yazılır, sonra aynı sınıftaki `rafGoster(i)` metodu çağrılır. Aynı sınıfın içinde olunduğu için metodun önüne bir nesne adı yazmak gerekmez.

```java
    public void tumRaflariGoster() {
        for (int i = 0; i < raf.length; i++) {
            System.out.println(i + ". Raftaki Kitaplar:");
            rafGoster(i);
        }
    }
```

Ekranda 0. rafta yalnız Kitap3 kalmıştır; diğer raflar tamamen boştur (ekrandan, 01:40:00):

```text
0. Raftaki Kitaplar:
null
null
Kitap [ad=Kitap3, yazar=Yazar3, ISBN=5345]
...
```

### 13.2 Setter örneği

Toparlama sırasında setter'ın kullanımı da gösterilir. ISBN final olduğu için set edilemez, ama kitabın adı değiştirilebilir. Elde silinmemiş kalan Kitap3'ün adı değiştirilip kitap yeniden yazdırılır:

```java
        kitap3.setAd("Suç ve Ceza");
        System.out.println(kitap3);
```

Çıktının son satırında kitabın adı "Suç ve Ceza" olarak görünür. Setter ve getter'ların amacı budur: nesnenin verisine doğrudan değil, yalnız metotlar üzerinden erişilir.

## 14. Programın tamamı ve çıktısı

Aşağıdaki kod, karelerdeki parçaların ve anlatımın birleştirilmesiyle ajan tarafından kuruldu. Sistemde `javac` bulunmadığı için Java 25'in tek dosya kaynak çalıştırıcısıyla (`java Test.java`) derlenip çalıştırıldı; çıktılar ekranda görünen bütün çıktılarla aynıdır. Dört sınıf tek dosyada olduğu için yalnız `Test` public bırakıldı; derste her sınıf kendi dosyasındadır.

```java
public class Test {
    public static void main(String[] args) {
        Kitap kitap1 = new Kitap("Kitap1", "Yazar1", "1234");
        Kitap kitap2 = new Kitap("Kitap2", "Yazar2", "7345");
        Kitap kitap3 = new Kitap("Kitap3", "Yazar3", "5345");
        Kitap kitap4 = new Kitap("Kitap4", "Yazar4", "2345");

        System.out.println(kitap1.getYazar());
        System.out.println(kitap1);
        System.out.println(" ---------------------- ");
        Kitaplık kitaplık = new Kitaplık(5);
        kitaplık.kitapEkle(kitap1, 0);
        kitaplık.kitapEkle(kitap2, 0);
        kitaplık.kitapEkle(kitap3, 0);
        kitaplık.rafGoster(0);
        System.out.println(" ---------------------- ");
        kitaplık.kitapSil(0, kitap1);
        kitaplık.rafGoster(0);
        System.out.println(" ---------------------- ");
        kitaplık.kitapAra("Kitap2");
        kitaplık.kitapSil(0, kitap2);
        kitaplık.kitapAra("Kitap2");
        System.out.println(" ---------------------- ");
        System.out.println(Kitap.getKitapSayisi());
        System.out.println(" ---------------------- ");
        kitaplık.tumRaflariGoster();
        System.out.println(" ---------------------- ");
        kitap3.setAd("Suç ve Ceza");
        System.out.println(kitap3);
    }
}

class Kitap {
    private String ad;
    private String yazar;
    private final String ISBN;
    private static int kitapSayisi;

    public Kitap(String ad, String yazar, String isbn) {
        this.ad = ad;
        this.yazar = yazar;
        ISBN = isbn;
        kitapSayisi++;
    }
    public String getAd() { return ad; }
    public void setAd(String ad) { this.ad = ad; }
    public String getYazar() { return yazar; }
    public void setYazar(String yazar) { this.yazar = yazar; }
    public String getISBN() { return ISBN; }
    public static int getKitapSayisi() { return kitapSayisi; }
    @Override
    public String toString() {
        return "Kitap [ad=" + ad + ", yazar=" + yazar + ", ISBN=" + ISBN + "]";
    }
}

class Raf {
    private Kitap[] kitaplar;
    public Raf() { kitaplar = new Kitap[10]; }
    public void kitapEkle(Kitap ktp) {
        for (int i = 0; i < kitaplar.length; i++) {
            if (kitaplar[i] == null) { kitaplar[i] = ktp; break; }
        }
    }
    public void rafGoster() {
        for (Kitap iter : kitaplar) System.out.println(iter);
    }
    public void kitapSil(Kitap ktp) {
        for (int i = 0; i < kitaplar.length; i++) {
            if (kitaplar[i] == ktp) { kitaplar[i] = null; break; }
        }
    }
    public Kitap[] getKitaplar() { return kitaplar; }
}

class Kitaplık {
    private Raf[] raf;
    public Kitaplık(int n) {
        raf = new Raf[n];
        for (int i = 0; i < n; i++) raf[i] = new Raf();
    }
    public void kitapEkle(Kitap ktp, int rafNo) { raf[rafNo].kitapEkle(ktp); }
    public void rafGoster(int rafNo) { raf[rafNo].rafGoster(); }
    public void kitapSil(int rafNo, Kitap ktp) { raf[rafNo].kitapSil(ktp); }
    public Kitap kitapAra(String str) {
        for (int i = 0; i < raf.length; i++)
            for (Kitap iter : raf[i].getKitaplar())
                if (iter != null)
                    if (iter.getAd().compareTo(str) == 0) {
                        System.out.printf("aranan kitap %d. rafta bulunuyor.\n", i);
                        return iter;
                    }
        System.out.println("aranan kitap bulunamadı");
        return null;
    }
    public void tumRaflariGoster() {
        for (int i = 0; i < raf.length; i++) {
            System.out.println(i + ". Raftaki Kitaplar:");
            rafGoster(i);
        }
    }
}
```

Programın çıktısının başı ve sonu (aradaki 1-4 numaralı rafların on `null` satırı kısaltıldı):

```text
Yazar1
Kitap [ad=Kitap1, yazar=Yazar1, ISBN=1234]
 ----------------------
Kitap [ad=Kitap1, yazar=Yazar1, ISBN=1234]
Kitap [ad=Kitap2, yazar=Yazar2, ISBN=7345]
Kitap [ad=Kitap3, yazar=Yazar3, ISBN=5345]
null (7 satır)
 ----------------------
null
Kitap [ad=Kitap2, yazar=Yazar2, ISBN=7345]
Kitap [ad=Kitap3, yazar=Yazar3, ISBN=5345]
null (7 satır)
 ----------------------
aranan kitap 0. rafta bulunuyor.
aranan kitap bulunamadı
 ----------------------
4
 ----------------------
0. Raftaki Kitaplar:
null
null
Kitap [ad=Kitap3, yazar=Yazar3, ISBN=5345]
null (7 satır)
1. Raftaki Kitaplar:
null (10 satır)
...
4. Raftaki Kitaplar:
null (10 satır)
 ----------------------
Kitap [ad=Suç ve Ceza, yazar=Yazar3, ISBN=5345]
```

## Örnek Sorular

### Soru 1 (ekrandan, 00:20:00)

Ekrandaki UML sınıf diyagramına göre `Test`, `Kitaplik`, `Raf` ve `Kitap` sınıflarını Java'da yazın. `Kitaplik` ile `Raf` arasında composition, `Raf` ile `Kitap` arasında aggregation ilişkisi kurulsun; kitap ekleme, silme, arama, bir rafı ve bütün rafları gösterme metotları olsun.

**Çözüm:** Derste adım adım kodlandı; birleştirilmiş ve denenmiş hâli 14. bölümdedir. Composition, rafların `Kitaplık` constructor'ı içinde oluşturulmasıyla; aggregation, kitapların `main` içinde ayrı oluşturulup rafa sonradan eklenmesiyle sağlanır.

### Soru 2 (ekrandan, 00:20:00)

Diyagramdaki `Kitaplik.kitapSilSıraNo(int,int)` ve `Raf.kitapSilSıraNo(int)` metotlarını yazın.

> **Çözüm (derste verilmedi):** Metot derste yazılmadı. Parametrelerin anlamı diyagramdan kesin çıkmıyor; büyük olasılıkla ilki raf numarası, ikincisi kitabın raftaki sıra numarasıdır. Bu varsayımla kitaplık işi ilgili rafa devreder, raf da o sıradaki gözü boşaltır:
>
> ```java
> // Raf sınıfında
> public void kitapSilSıraNo(int siraNo) {
>     if (siraNo >= 0 && siraNo < kitaplar.length)
>         kitaplar[siraNo] = null;
> }
>
> // Kitaplık sınıfında
> public void kitapSilSıraNo(int rafNo, int siraNo) {
>     raf[rafNo].kitapSilSıraNo(siraNo);
> }
> ```
>
> Ajan bu metotları programa ekleyip `kitap4`'ü 1. rafa ekledi, `kitapSilSıraNo(1, 0)` çağırdı ve `rafGoster(1)` ile on gözün de `null` olduğunu gördü.

### Soru 3 (derste sözlü, 01:23:51)

Aradığınız bir kitabın kitaplıkta olup olmadığını programda nasıl bulursunuz?

**Çözüm:** Derste verildi (11. bölüm). Dış döngü rafları, iç döngü (geliştirilmiş for) o rafın `getKitaplar()` ile alınan dizisini gezer. Boş olmayan her kitabın `getAd()` değeri `compareTo` ile aranan adla karşılaştırılır; sonuç 0 ise raf numarası yazdırılıp kitap döndürülür. Döngüler biterse "aranan kitap bulunamadı" yazdırılıp `null` döndürülür.

### Soru 4 (ekrandan, 01:10:00 ve derste sözlü, 01:14:16)

Üç `kitapEkle` çağrısından sonra çıktıda Kitap1 neden iki kez görünüyor?

**Çözüm:** Derste verildi. İlk satır rafın içeriği değil, daha önce çalışan `System.out.println(kitap1);` satırının çıktısıdır. Ayrıca ekrandaki kodda üçüncü çağrı bir an `kitapEkle(kitap1, 0)` olarak yazılmıştı; o hâliyle Kitap1 rafa gerçekten iki kez eklenirdi, çünkü ekleme metodu aynı nesnenin rafta olup olmadığına bakmaz. Çağrı `kitap3` olarak düzeltildi ve çıktının bölümleri ayırıcı satırlarla ayrıldı.

## Dersin Toparlaması

Bu uygulamada kitaplık, raf ve kitap sınıflarından oluşan bir hiyerarşi kuruldu. Kitaplık oluşturulduğu anda rafları da constructor içinde oluşturulduğu için ikisi arasındaki ilişki güçlüdür (composition): kitaplık silinince raflara erişim kalmaz. Raf constructor'ı kitaplar için yalnız boş bir dizi açar; kitaplar `main` içinde ayrı ayrı oluşturulup sonradan eklendiği için kitaplık ya da raf ortadan kalksa da yaşamaya devam ederler (aggregation). Kitap sınıfında constructor, `this`, `final` ISBN, `static` sayaç, private nitelikler ve onlara erişen getter/setter metotları, nesnenin içeriğini okunur kılan `toString` görüldü. Kitap ekleme, silme ve rafı gösterme işlemleri kitaplıktan rafa iki aşamada devredildi; asistan bunların `getKitaplar()` ile tek aşamada da yazılabileceğini, iki aşamalı yazımın ilişkileri göstermek için seçildiğini belirtti. Arama iç içe döngülerle ve `compareTo` ile yapıldı, diziler klasik ve geliştirilmiş for ile gezildi.

Asistan, bir anda karışık görünse de örnek tekrar tekrar incelendikçe kavramların oturacağını söyledi. Kalıtım bir sonraki uygulamanın konusudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
