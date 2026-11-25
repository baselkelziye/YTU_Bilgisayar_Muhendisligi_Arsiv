# Ders 4 Genişletilmiş Notu: Görünürlük Kuralları, static ve final, Kurucular ve Kontrol Akışı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı
- 2. Kapsülleme ve Bilgi Gizleme
- 3. Erişim Belirleyiciler ve UML Gösterimi
- 4. Getter ve Setter Metotları
- 5. Static Üyeler
- 6. Eclipse Üzerinde Örnek Kod
- 7. Final Üyeler
- 8. Kurucular ve Sonlandırıcılar
- 9. Kontrol Akışı ve main Metodu
- 10. UML Ardışık Diyagramı
- 11. Hocanın Ara Toparlaması
- 12. İkinci Car Sınıfı, this ve Getter/Setter Gerekçesi
- 13. Doğru ve Yanlış Kurucu
- Örnek Sorular

## 1. Önceki Dersin Tekrarı

Ders, önceki derste anlatılan kavramların kısa bir tekrarıyla başladı. Sınıf (class) bir şablon gibi düşünülebilir; nesne (object) bu şablondan oluşturulan gerçek varlıktır. Her nesnenin içinde veri ve metotlar bulunur. Verilere üye alanlar (member fields), metotlara üye metotlar (member methods) denir.

Aynı sınıftan oluşturulan nesnelerin türü aynıdır, ama durumları (state) farklıdır. Durum, nesnenin özniteliklerinin o andaki değerleridir. Durum farklı olduğu için nesneler aynı mesaja farklı davranır. Hoca bunu önceki dersteki araba örneğiyle hatırlattı: iki `Car` nesnesinin metotları aynıdır, ama birinin deposu dolu, öbürününki boştur. İkisinin de `start` metodu çağrıldığında biri çalışır, öbürü çalışmaz.

Nesneye yönelik bir programda bir iş yaptırmak için nesneler kullanılır ve nesneler birbirini çağırır. Bir nesnenin başka bir nesnenin metodunu çağırması, o nesneye mesaj göndermesi demektir. Slayta göre mesaj iki amaçla gönderilir: nesneye bir iş yaptırmak ve nesnenin bir üyesine erişmek (ekrandan, 00:15:00).

Slayttaki "Member Access" bölümü şöyledir (ekrandan, 00:15:00):

- Bir nesnenin üye alanına, değerini değiştirmek (setting) ya da okumak (getting) için erişilir.
- Bir nesnenin üye metoduna, metodu (isteğe bağlı olarak parametrelerle) çalıştırmak için erişilir. Metot çağırmak C'de fonksiyon çağırmaya benzer.
- Ancak aksi belirtilmedikçe bir nesnenin metodu o nesnenin üyeleriyle çalışır. "Aksi" durumların ne olduğu, nesneler arasındaki ilişki türleri öğrenilince anlaşılacaktır.

Private alanların değerine erişmek için setter ve getter metotları kullanılır. Hoca UML'de iki nesnenin gösterimini de hatırlattı: bir istemci (client) nesnesi bir `Car` nesnesine mesaj gönderir ve karşılığında mesajın sonucunu alır.

Java'da sınıflar paketlerle (package) düzenlenir. Bir paketin altında başka bir paket ve sınıflar olabilir. Her paket aslında bir klasördür; böylece sınıflar birbiriyle çakışmaz. Bir sınıfı kodda kullanmak için `import` deyimi yazılır:

```java
import paket1.ClassA;   // paket1'deki ClassA sınıfını kullan
import paket1.*;        // paket1'deki bütün sınıfları kullan
```

<!-- BELİRSİZ: Paket örneğinin slaytındaki paket ve sınıf adları karelerde görünmüyor; adlar altyazıdan genel olarak alındı. -->

## 2. Kapsülleme ve Bilgi Gizleme

Önceki ders kapsülleme (encapsulation) kavramında bırakılmıştı. Hoca konuyu iki nesneyle açıkladı: bir kişi (`Person`) nesnesi ve bir televizyon (`TV`) nesnesi. Kişi nesnesi `Person` sınıfından, televizyon nesnesi `TV` sınıfından oluşturulmuştur. Kişi televizyonu açmak için televizyonun açma metodunu çağırır; bu metot kişi nesnesine görünür olduğu için çağrılabilir.

Televizyonun başka işlevleri de vardır, ama bunlar iç işleyişle ilgilidir: ekranın LCD mi plazma mı olduğu, içinde akıllı TV kartı bulunup bulunmadığı gibi. Kişiyi ilgilendiren yalnız televizyonu açmak ve kapatmaktır. Bu yüzden televizyon nesnesinin bu iç metotları kişi nesnesine göstermesine gerek yoktur.

Buradan çıkan sonuç şudur: farklı sınıflara ait nesneler birbirleriyle konuşurken bazı işlevlerini gizleyebilir, bazılarını açığa çıkarabilir. Bu, programcıların işini kolaylaştırır.

Slayttaki ilkeler şöyledir (ekrandan, 00:20:00):

- Bir nesne kendi üyelerinin hepsine ve **aynı sınıftan (türden)** başka nesnelerin bütün üyelerine erişebilir.
- Ancak bir nesnenin bazı üyeleri, farklı türdeki nesnelerden erişilemeyecek biçimde gizlenebilir.
- Bilgi gizleme ilkesi: nesnenin iç işleyişiyle ilgili üyeler farklı türdeki nesnelerden gizlenir. Böylece bir nesnenin başka bir nesneyi kullanmak için onun iç ayrıntılarını bilmesi gerekmez.

Hoca iki günlük hayat örneği verdi:

- **Televizyon kumandası:** Televizyon izlemek için kumandadaki güç, ses ve kanal tuşlarının evrensel işaretlerini bilmek yeterlidir. Televizyonun içinde katot tüp denen bir aygıt olduğunu bilmek gerekmez. Üstelik kullanıcılar LCD, plazma gibi yeni teknolojilerle yapılmış televizyonları kullanmak için yeniden eğitilmek zorunda kalmaz.
- **Borç isteyen arkadaş:** Bir arkadaşınız sizden borç para isterse ya cüzdanınızı açıp parayı verirsiniz ya da vermezsiniz. Ona maaşınızı ya da banka kartınızın PIN numarasını söylemeniz gerekmez; bunlar onun için gereksiz bilgilerdir.

Kod yazarken de yalnız gerekli metotlar public yapılır.

## 3. Erişim Belirleyiciler ve UML Gösterimi

Görünürlük kuralları, yani bilgi gizleme, erişim belirleyicilerle (access modifiers) uygulanır. Dört erişim belirleyici vardır: `public`, `private`, `protected` ve package.

### 3.1 public ve private

Slayttaki tanımlar şöyledir (ekrandan, 00:35:00):

- **public:** Public üyelere erişimde hiçbir kısıt yoktur. Başka sınıflardan nesnelerin bir üye alanın değerine doğrudan erişmesi isteniyorsa alan public tanımlanır.
- **private:** Farklı türdeki nesneler birbirinin private üyelerine erişemez. Yalnız aynı sınıfın nesneleri private üyelere doğrudan erişebilir.

Hoca bir `Car` sınıf gösteriminde bütün üye alanların private olduğunu gösterdi: bu alanlara yalnız `Car` sınıfının nesneleri doğrudan erişebilir. Örneğin bir `Person` sınıfı olsaydı, onun nesneleri bu alanların değerine doğrudan erişemezdi. Alanlar için en sık kullanılacak iki belirleyici `public` ve `private`'tır.

### 3.2 UML sınıf gösterimi

UML'de bir sınıf üç bölmeli bir kutuyla gösterilir: en üstte sınıfın adı, ortada üye alanlar, altta üye metotlar. Slayttaki genel gösterim şöyledir (ekrandan, 00:35:00):

```text
+------------------------------------------------------------+
|                         ClassName                          |
+------------------------------------------------------------+
| - aPrivateField : TypeOfField                              |
+------------------------------------------------------------+
| + aPublicVoidMethod( )                                     |
| + aPublicMethod( ) : ReturnType                            |
| + aMethodWithOneParameter( param1 : Param1Type )           |
| + manyParameteredMethod( param1 : P1Type, param2 : P2Type )|
+------------------------------------------------------------+
```

- Alanın önündeki `-` alanın private, `+` public olduğunu gösterir.
- Alan adından sonra iki nokta üst üste ve alanın türü yazılır. Tür `int` ise `ad : int` (hoca "integer" dedi), bir `Car` nesnesiyse `ad : Car` yazılır.
- Metotlarda da önlerindeki `+` metodun public olduğunu, yani başka sınıfların nesnelerine görünür olduğunu ve onlar tarafından çağrılabileceğini gösterir.
- Dönüş türü olan metotta parantezden sonra iki nokta ve dönüş türü yazılır. Dönüş türü olmayan (void) metotta bu kısım yazılmaz.

Erişim belirleyiciler yalnız üye alanlarda değil, metotlarda da kullanılır.

### 3.3 protected ve package

Hoca bu ikisini yalnız tanıttı; ayrıntılarının büyük olasılıkla ilk ara sınavdan sonra işleneceğini söyledi. Slayta göre (ekrandan, 00:35:00):

- **protected (`#`):** Kalıtımla ilgilidir; pakete ve alt sınıflara görünür. Hoca bunu "yalnız alt sınıfların (child class) nesneleri protected alanın değerine erişebilir" diye anlattı.
- **package (`~`):** Yalnız aynı paketteki sınıfların nesneleri erişebilir. Java'da varsayılan kuraldır.

> **Ders sonrası not:** Hoca protected için "yalnız alt sınıfların nesneleri erişebilir" dedi; slayttaki tanıma göre protected üyeler aynı paketteki sınıflara da görünür ("visible to package and subclasses").

> **Ek bilgi (derste anlatılmadı):** "Varsayılan kural" ifadesi, bir üyenin önüne hiçbir erişim belirleyici yazılmazsa üyenin package erişimli olacağı anlamına gelir. Java'da `package` diye bir anahtar sözcük belirleyici olarak yazılmaz; bu düzeye "package-private" da denir.

## 4. Getter ve Setter Metotları

Hoca dersin bundan sonrasında uyulacak ilkeyi açıkladı: üye alanlar private tanımlanacak. Public tanımlamak için özel bir gerekçe yoksa istisna yapılmayacak; bu ilke sınavlarda da beklenecek.

Alanlar private olunca başka sınıfların nesneleri bu alanlara doğrudan erişemez. Bu yüzden iki tür metot yazılır:

- **Getter metodu:** private alanın değerini okumak için kullanılır.
- **Setter metodu:** private alanın değerini değiştirmek için kullanılır.

Slayttaki UML örneğinde `Car` nesnesinin tek bir üye alanı vardır: türü `String` olan, private tanımlanmış `plate` alanı. Alan private olduğu için başka sınıfların nesneleri ona doğrudan erişemez; bu yüzden sınıfta getter ve setter metotları bulunur.

**Soru:** Birden fazla öznitelik varsa her biri için ayrı ayrı getter ve setter yazmak gerekir mi? **Cevap:** Evet. Bütün private alanlar için getter ve setter yazılır.

> **Hocanın vurgusu:** Sınavlarda bütün üye alanlar için getter ve setter yazmanız istenecek; yazılmazsa puan kaybedilir. Getter ve setter yazmak sınavda kolay puan almanın yoludur, bu alışkanlığı edinin. Üye alanlar her zaman private tanımlanır.

## 5. Static Üyeler

### 5.1 Static üye alanlar

Her nesnenin durumu, oluşturulduktan sonra farklıdır. Ama bazı durumlarda bir özniteliğin değeri bütün nesneler için aynı kalmalıdır. Hoca bunu bir şekille gösterdi: solda bir sınıf gösterimi, sağda bu sınıftan oluşturulmuş adları farklı iki nesne vardır. Sınıftaki iki değişkenden biri, bu sınıftan oluşturulan bütün nesneler için aynı değeri taşımalıdır. Bu durumda değişkenin önüne `static` anahtar sözcüğü yazılır. `static`, özniteliğin değerinin o sınıftan oluşturulan bütün nesneler için ortak olmasını sağlar.

Slayttaki ifadeler şöyledir (ekrandan, 00:40:00):

- Aynı sınıftan olsalar bile her nesnenin durumu farklıdır.
- Ancak bazı durumlarda belli bir türün **bütün** nesnelerinin ortak bir üye alanı **paylaşması** gerekebilir.
- Bu durumda üye alan `static` anahtar sözcüğüyle tanımlanır.
- Static üyelere nesneler üzerinden değil, `ClassName.memberName` biçiminde sınıf adıyla erişilir.
- Örnek: her otomobilin 4 tekerleği vardır.

Hoca farkı şöyle açıkladı: normal bir alanın değerine erişmek için o nesnenin metodu kullanılır. Static bir alana ise doğrudan sınıf adı, nokta ve alan adı yazılarak erişilir.

### 5.2 Static üye metotlar

Static anahtar sözcüğü metotlarda da kullanılır. Slayta göre (ekrandan, 00:40:00):

- Aynı türden iki nesne aynı mesaja farklı cevap verir.
- Ancak bazı durumlarda bir türün **bütün** nesnelerinin ortak bir davranışı **paylaşması** gerekebilir.
- Bu durumda metot `static` anahtar sözcüğüyle tanımlanır.
- Bir nesnenin static metodu içinde yalnız o nesnenin static üyeleri kullanılabilir.
- Static metotlara sınıf adıyla erişilir: `ClassName.aMethod()`.

Hoca, static bir metodun içinde bir üye alan kullanılacaksa o alanın da static tanımlanması gerektiğini vurguladı ve bunun ileride daha iyi anlaşılacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Static bir alan nesneye değil sınıfa aittir; bellekte tek bir kopyası vardır. Bir nesne üzerinden değiştirilse bile değişiklik bütün nesnelerden görülür. Static metot belirli bir nesne olmadan çağrılabildiği için içinde `this` yoktur; bu yüzden static olmayan alanlara doğrudan erişemez.

## 6. Eclipse Üzerinde Örnek Kod

Hoca önceki derslerde bir Java editörü (Eclipse önerilmişti; NetBeans ya da IntelliJ de olur) kurulmasını ve ders sayfasındaki kodların indirilip bir proje oluşturulmasını istemişti. Her dersten sonra bu projedeki örnek sınıflarla oynanmasını istedi.

Eclipse'te `OOCProjects` projesinde `nyp01a`, `nyp01b`, `nyp02` gibi paketler bulunur. Hoca `nyp01b` paketindeki `Car` sınıfını gösterdi (ekrandan, 00:45:00):

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

Hoca sınıftaki iki alanın private, türlerinin `String` olduğunu (String veri türü ileride işlenecek) ve alanlara erişmek için getter/setter metotları bulunduğunu gösterdi. Sınıftaki metotlar public olduğu için başka sınıfların nesnelerine görünür.

Dosyanın başındaki `package` deyimi, Java derleyicisine bu sınıfın hangi paketin altında olduğunu söyler. Sınıf başka sınıfları kullanacaksa onlar `import` deyimiyle içeri alınır.

Hoca başka bir sınıfta metotlardan birinin static tanımlandığını da gösterdi ve static metodun o sınıftan oluşturulan bütün nesneler için aynı davranacağını, içinde kullanılan alanların da static olması gerektiğini tekrarladı.

<!-- BELİRSİZ: Static metot içeren sınıfın kodu karelerde görünmüyor; hangi metodun static olduğu belirlenemedi. -->

## 7. Final Üyeler

### 7.1 Final üye alanlar

`static` gibi `final` anahtar sözcüğü de hem üye alanlarda hem üye metotlarda kullanılır. Bir değerin nesnenin ömrü boyunca aynı kalması gerekiyorsa alan `final` tanımlanır. Final tanımlanan alanın değeri değişmez.

Slayttaki ifadeler şöyledir (ekrandan, 00:50:00):

- Bir üye alanın değerinin sabit kalması gerekebilir.
- Bu durumda alan `final` anahtar sözcüğüyle tanımlanır.
- Bir nesnenin final üyesine yalnız bir kez değer atanabilir. Bu atama genellikle nesne oluşturulurken yapılır.
- Örnek: bir arabanın şasi numarası fabrikada üretilirken kasaya kazınır ve sonradan değiştirilemez.

Hoca bir örnek kodla final kullanımını gösterdi: `Example` adlı bir sınıfta iki üye alan ve bir metot vardır; iki alan da `final` tanımlanmıştır. Metodun içinde alanlardan birine önce bir değer atanır; final alana ilk atama yapılabildiği için bu satır sorunsuzdur. Üçüncü satırda aynı alana yeniden değer atanmaya çalışılır ve bu satır hata verir, çünkü final alana yalnız bir kez değer atanabilir.

<!-- BELİRSİZ: Final örneğinin kodu karelerde görünmüyor; alan adları ve değerler aktarılamadı. -->

Hoca final için gerçek hayattan örnekler verdi: bir arabanın plakası ve şasi numarası değişmez, bu yüzden final tanımlanabilir.

> **Ders sonrası not:** Hoca şasi numarası örneğinde bir yerde "static olarak tanımlayabilirsiniz" dedi; bağlam ve slayt, kastedilenin `final` olduğunu gösteriyor. Şasi numarası her arabada farklıdır ama değişmez; bu `final` kullanımıdır, `static` değildir.

### 7.2 Final metotlar ve final sınıflar

Hoca bir şekille `final` anahtar sözcüğünün üç kullanımını gösterdi (ekrandan, 00:55:00):

| Kullanım | Etkisi |
|---|---|
| Final Variable | Değerin değişmesini engeller (stop value change) |
| Final Method | Metodun geçersiz kılınmasını engeller (prevent method overriding) |
| Final Class | Kalıtımı engeller (prevent inheritance) |

Final metot, alt sınıfların (child class) üst sınıftaki metodu geçersiz kılmasını (override) engeller. Final sınıftan kalıtım yapılamaz. Bunlar kalıtım konusunda işlenecek; şimdilik bilinmesi gereken, final alanın değerinin değişmediğidir.

### 7.3 final ile static'i karıştırmamak

Final, bir değişkenin tek bir değeri olacak ve bu değer baştan atanıp hep aynı kalacaksa kullanılır. Static ise değişkenin değeri bütün nesneler tarafından paylaşılacaksa kullanılır. Bunlar farklı şeylerdir; bu yüzden bir alan aynı anda hem final hem static olabilir.

Slayttaki "Points to Consider" bölümü (ekrandan, 00:50:00):

- Bir üye aynı anda hem final hem static olabilir.
- final ile static birbiriyle karıştırılmamalıdır:
  - Final: yalnız bir kez (only once)
  - Static: ortak kullanım (shared usage)
- UML sınıf şemalarında şöyle gösterilir: `aMember : Type {final,static}`

UML'de önce `+` ya da `-` işareti, sonra alanın adı, iki nokta, türü ve süslü parantez içinde `final`, `static` ya da ikisi birden yazılır. Alan final ya da static değilse süslü parantez yazılmaz.

> **Ek bilgi (derste anlatılmadı):** Hem `static` hem `final` olan alanlar Java'da genellikle sabitler için kullanılır (örneğin `static final int TIRE_COUNT = 4;`). Bu tür sabitlerin adları geleneksel olarak büyük harfle ve alt çizgiyle yazılır.

## 8. Kurucular ve Sonlandırıcılar

Aradan sonra hoca kurucular (constructors) ve sonlandırıcılar (finalizers) konusuna geçti.

### 8.1 Tanımlar

Slayttaki tanımlar şöyledir (ekrandan, 01:10:00):

- **Kurucu metot (constructor):**
  - Bir nesne oluşturulacağı zaman programcı tarafından açıkça (explicitly) çalıştırılır.
  - Kurucular, nesnenin üye alanlarına ilk değer atamak için kullanılır.
  - Derste kuruculara özel önem verilecektir.
- **Sonlandırıcı metot (finalizing method):**
  - Bir nesne yok edileceği zaman JVM tarafından örtük olarak (implicitly) çalıştırılır.
  - Metodun adı `finalize`'dır; parametre almaz ve bir şey döndürmez.
  - C/C++'tan farklı olarak Java programcıları çoğunlukla bellek yönetimiyle uğraşmak zorunda değildir.
  - Bu yüzden derste sonlandırıcı metotlar bundan sonra işlenmeyecek.

> **Ders sonrası not:** Hoca sonlandırıcının "program kapanırken, program JVM tarafından sonlandırıldığında" çalıştığını söyledi. Slayttaki tanıma göre sonlandırıcı bir **nesne** yok edileceği zaman (çöp toplayıcı nesneyi toplarken) çağrılır; programın kapanmasına bağlı değildir.

### 8.2 Kurucunun kuralları

- Kurucular public tanımlanır.
- Kurucunun adı sınıfın adıyla aynıdır.
- Kurucunun dönüş türü yoktur.
- Kurucu `new` anahtar sözcüğüyle çağrılır. Nesne oluşturmak için `new` kullanılır.

Parametresi olmayan kurucuya varsayılan kurucu (default constructor) denir. Bir ya da daha çok parametre alan kurucular da olabilir.

### 8.3 Birden çok kurucu ve kurucu zinciri

Hoca bir sınıfta üç kurucu olan bir örnek gösterdi (ekrandan, 01:15:00):

```java
public class MyClass{
   ....
   MyClass( ) {
      this("BeginnersBook.com");
   }
   MyClass(String s) {
      this(s, 6);
   }
   MyClass(String s, int age) {
      this.name =s;
      this.age = age;
   }
   public static void main(String args[]) {
      MyClass obj = new MyClass();
      ....
   }
}
```

İlk kurucu parametresiz, ikincisi tek parametreli, üçüncüsü iki parametrelidir. Bir sınıfta birden çok kurucu olabilir, ama imzaları farklı olmalıdır. Bir metodun imzası, metodun adı ve ondan sonra parantez içinde gelen parametrelerdir (parametrelerin türleri; birden fazla parametre virgülle ayrılır). Varsayılan kurucunun parametresi yoktur, ikinci kurucunun bir `String` parametresi, üçüncüsünün iki parametresi vardır; imzalar farklı olduğu için üç kurucu bir arada bulunabilir.

Dördüncü metot static tanımlanmış `main` metodudur. Hoca, `main`'in neredeyse bütün programlarda görüleceğini ve yürütmenin başlangıç noktası olduğunu söyledi.

Akış şöyledir:

1. `main` içindeki atama deyiminde sağ tarafta `new MyClass()` ile nesne oluşturulur. Java'da `=` atama işlecidir.
2. `new MyClass()` varsayılan kurucuyu çağırır. Varsayılan kurucu `this("BeginnersBook.com")` ile tek parametreli kurucuyu çağırır. Hoca `this` anahtar sözcüğünü ileride öğreteceğini, burada aynı nesnenin kurucusunu çağırdığını söyledi.
3. Tek parametreli kurucu `this(s, 6)` ile iki parametreli kurucuyu çağırır.
4. İki parametreli kurucu iki değişkene değer atar.

Hoca bu örneğin yalnız bir sınıfta bir, iki ya da daha çok parametreli kurucular olabileceğini göstermek için verildiğini belirtti.

> **Ders sonrası not:** Slaytta `name` ve `age` alanlarının bildirimi `....` ile atlanmıştır. Alanlar (`String name; int age;`) eklenip kod ajan tarafından `java` ile çalıştırıldığında `obj` nesnesinin `name` alanı `BeginnersBook.com`, `age` alanı `6` olur.

### 8.4 Hiç kurucu yazılmazsa: derleyicinin eklediği varsayılan kurucu

Hoca kurucusu olmayan bir sınıfın derlenmesini gösterdi (ekrandan, 01:20:00):

```text
MyClass.java                          MyClass.class
public class MyClass                  public class MyClass
{                                     {
  public static void main(...)          MyClass(){
  {                     -> COMPILER ->  }
    MyClass obj = new MyClass();        public static void main(String args[])
  }                                     {
  ...                                     MyClass obj = new MyClass();
}                                       }
                                        ...
                                      }
```

`MyClass.java` dosyasında yalnız `main` metodu vardır. `main` içinde `MyClass` türünde `obj` adlı yerel bir değişken tanımlanır, `new MyClass()` ile bir nesne oluşturulup bu değişkene atanır. Derleyici dosyayı derleyip bayt kod olan `MyClass.class` dosyasını üretirken boş bir varsayılan kurucu ekler. Kurucu yazılmamış olsa bile derleyici bir kurucu olması gerektiğini bilir, onu ekler ve bütün sınıfı derler.

> **Ek bilgi (derste anlatılmadı):** Derleyici varsayılan kurucuyu yalnız sınıfta hiç kurucu yazılmamışsa ekler. Sınıfa parametreli bir kurucu yazılırsa derleyici artık parametresiz kurucu eklemez; bu durumda `new MyClass()` yazmak derleme hatası verir.

### 8.5 Başka sınıfta nesne oluşturma ve UML gösterimi

Hoca iki örnek sınıf daha gösterdi. Birincisinde private tanımlı bir üye alan ve bir metot vardır. Metodun içindeki atama deyiminin sağ tarafında `new` ile `Car` kurucusu çağrılarak bir `Car` nesnesi oluşturulur ve nesnenin referansı bu değişkene atanır. İkinci örnekte üye alan yoktur, yalnız bir metot vardır; metodun içinde yine bir `Car` nesnesi oluşturulup referansı türü `Car` olan yerel bir değişkene atanır.

UML'de nesne oluşturma şöyle gösterilir: dikdörtgenin içine nesnenin adı, iki nokta ve sınıfın adı yazılır. Varsayılan kurucu `new` ile çağrılır. Kurucunun dönüş türü olmadığı için okun üzerine bir tür yazılmaz; kurucu yalnız oluşturulan nesnenin referansını döndürür.

<!-- BELİRSİZ: Bu iki örnek sınıfın ve UML nesne oluşturma şemasının kodu/çizimi karelerde görünmüyor. -->

### 8.6 nyp01a.Car sınıfında kurucu

Hoca Eclipse'te `nyp01a` paketindeki `Car` sınıfına döndü (ekrandan, 01:30:00):

```java
package nyp01a;

public class Car {
    private String plate;

    public Car( String plateNr ) {
        plate = plateNr;
    }

    public String getPlate() {
        return plate;
    }
    public void setPlate(String plate) {
        this.plate = plate;
    }

    public void introduceSelf( ) {
        System.out.println( "My plate: " + getPlate() );
    }

    public static void main( String[] args ) {
        Car aCar;
        aCar = new Car( "34 RA 440" );
        aCar.introduceSelf( );
        Car anotherCar = new Car("06 ANK 06");
        anotherCar.introduceSelf();
        aCar.setPlate( anotherCar.getPlate() );
        aCar.introduceSelf();
        System.out.println("The End");
    }
}
```

Sınıfta bir üye alan ve bir kurucu vardır. Kurucu public'tir, dönüş türü yoktur ve adı sınıfla aynıdır. Kurucunun amacı üye alanlara ilk değer atamaktır; burada tek alan olduğu için kurucu bir parametre alır ve bunu alana atar. Getter ve setter metotları alanın değerini okumak ve değiştirmek içindir. Bunlara ek olarak `introduceSelf` adlı bir metot vardır.

`main` metodunda önce `Car` türünde `aCar` adlı yerel değişken tanımlanır. Altındaki atama deyiminde tek parametreli kurucu `new` ile çağrılır; JVM bir nesne oluşturur ve referansını `aCar` değişkenine atar. Ardından yine `new` ile ikinci bir nesne oluşturulup başka bir değişkene atanır.

Bu kod ajan tarafından çalıştırıldı (javac kurulu değildi; `java` tek dosyalık kaynak başlatıcısıyla). Çıktı:

```text
My plate: 34 RA 440
My plate: 06 ANK 06
My plate: 06 ANK 06
The End
```

Üçüncü satırda `aCar`'ın plakası `anotherCar`'ın plakasıyla değiştirildiği için `aCar` da `06 ANK 06` yazar.

Hoca ayrıca iki kurucusu olan bir `Car` sürümü gösterdi: ikisi de public, dönüş türü yok, adları `Car`; ama biri tek, öbürü iki parametreli olduğu için imzaları farklı. Nesne oluşturmak için bunlardan biri çağrılabilir.

### 8.7 Aşırı yükleme (overloading)

Bir sınıfta imzaları farklı birden çok kurucu bulunmasına Java'da aşırı yükleme (overloading) denir. Kurucular gibi sıradan metotlar da aşırı yüklenebilir: aynı adlı, farklı imzalı birden çok metot yazılabilir.

## 9. Kontrol Akışı ve main Metodu

Erişim belirleyiciler, `static`, `final` ve kuruculardan sonra ilk Java sınıfını yazmak için JVM'nin programı nereden başlattığını bilmek gerekir.

### 9.1 Kontrol akışı

Her programın bir kontrol akışı, yani bir yürütme sırası vardır. Slayttaki ifadeler şöyledir (ekrandan, 01:35:00):

- Kontrol akışı, program kodlarının yürütülme sırasıdır.
- En alt düzeyde bir bilgisayar programı belli bir sırayla yürütülen çeşitli komutlardan oluşur.
- Komutların yazıldığı sıra ile yürütüldüğü sıra aynı olmak zorunda değildir.
  - Özellikle nesneye yönelik programlamada bu iki sıra neredeyse her zaman birbirinden oldukça farklıdır.
- Neyse ki bu kontrol akışının başlangıç noktasını belirlemek daha kolaydır.

Hoca, C, C++, C#, Java ya da Python'da yazılan bir programın derleyici tarafından sıfır ve birlerden oluşan makine koduna çevrildiğini anlattı. Bu komutlar CPU'ya verildiğinde belli bir sırayla yürütülür; ama başarımı artırmak için donanım komutları programdaki sıradan farklı bir sırayla yürütebilir.

### 9.2 main metodu

Programın sırası `main` metoduyla belirlenir. `main` bir sınıfta tanımlanır ve sınıf JVM tarafından çalıştırılır. `main` içindeki deyimler yazıldıkları sırayla yürütülür.

`main` metodunun imzası `public static void main( String[] args )` biçimindedir ve bundan sonra yazılacak hemen her programda aynen görülecektir:

- **public:** Başka sınıfların nesnelerinden erişilebilmesi gerekir.
- **static:** Hoca bunu "main'in davranışı aynı sınıftan oluşturulan bütün nesneler için aynıdır" diye açıkladı.
- **void:** Bir şey döndürmez.
- **`String[] args`:** Tek bir argüman alır, bir `String` dizisi. Komut satırından başlangıç parametreleri geçirmek için kullanılır.

> **Ders sonrası not:** `main`'in static olmasının asıl nedeni, büyük olasılıkla JVM'nin programı başlatırken henüz hiçbir nesne oluşturulmadan bu metodu sınıf adı üzerinden çağırabilmesidir.

Java çalışma ortamı slaytında (ekrandan, 01:40:00) kaynak kod (`.java`) `javac.exe` ile derlenir ve bayt kod (`.class`) oluşur; bu bayt kodu JVM (`java.exe`/`javaw.exe`, komut satırı ve GUI uygulamaları için; JRE içinde) yorumlayarak çalıştırır. JDK geliştiriciler, JRE son kullanıcılar içindir; JDK, JRE'yi içerir. Bir sınıf komut satırından `java` komutu, sınıfın adı ve ardından geçirilecek parametreler yazılarak çalıştırılır. Bu parametreler `main` metodunun `args` dizisine gelir.

`nyp01a.Car` örneğinde JVM önce `Car aCar;` satırını, sonra nesne oluşturup referansını `aCar`'a atayan satırı, sonra `aCar.introduceSelf()` çağrısını yürütür. `introduceSelf` oluşturulan nesnenin üye metodudur.

### 9.3 Kod gövdesi

Hoca ders boyunca "kod gövdesi" (code body) ya da "kod bloğu" ifadesini kullanacağını söyledi. Bu, birden çok deyim içeren ve genellikle süslü parantezlerle gösterilen kod parçasıdır. Örneğin `main` metodunun kod gövdesi içindeki üç deyimdir; `introduceSelf`'in kod gövdesi tek bir deyimdir.

## 10. UML Ardışık Diyagramı

### 10.1 Sınıf diyagramı ve kod

Slayttaki "Creating Your Own Class and Objects" bölümünde solda UML sınıf diyagramı, sağda kaynak kod vardır (ekrandan, 01:45:00):

```text
+----------------------------+
|            Car             |
+----------------------------+
| - plate : String           |
+----------------------------+
| + Car( plateNr : String )  |
| + getPlate( ) : String     |
| + setPlate( String )       |
| + introduceSelf( )         |
| + main( String[] )         |
+----------------------------+
```

Slayttaki öneriler: önce sınıf şemasını çizin, sonra şemayı koda dönüştürün; kodu düzgün girintileyin (pretty printing) ve deve harfi (camel casing) adlandırmasına uyun.

Bu diyagramda bir kurucu vardır; kurucu olduğu, adının sınıfla aynı olmasından anlaşılır. Ayrıca private alana erişim için getter/setter, bir sıradan metot ve `main` metodu vardır.

### 10.2 Ardışık diyagram

Ardışık diyagram (sequence diagram) bir metodun içindeki yürütme sırasını gösterir. `main` metodunun ardışık diyagramında olanlar şöyledir:

1. Komut satırından `Car` sınıfı çalıştırıldığında JVM, `Car` sınıfının `main` metodunu çağırır. JVM ilk nesne olarak gösterilir.
2. `main`'in kod gövdesinde önce yerel bir değişken tanımlanır.
3. İkinci deyimde `new` ile `Car` kurucusu çağrılır. Oluşturulan nesne ayrı bir nesne olduğu için diyagramda ayrı gösterilir; adı `aCar`'dır. Kurucu oluşturulan nesnenin referansını döndürür.
4. Üçüncü deyimde `aCar` nesnesinin `introduceSelf` metodu çağrılır.
5. `introduceSelf` tek bir deyim içerir: `System.out.println(...)`. Bu, konsola yazı yazmak için kullanılır. `println` argüman olarak bir `String` alır; burada `"My plate: "` ile `getPlate()`'in döndürdüğü değer `+` ile birleştirilir.
6. `getPlate` aynı nesnenin metodu olduğu için kod gövdesi `introduceSelf`'in gövdesinin üzerinde gösterilir. `getPlate` çalışır ve değeri `introduceSelf`'e döndürür; değer metne eklenir.
7. `introduceSelf` void bir metot olduğu için dönüş oku kesikli çizilir ve okun üzerine bir şey yazılmaz.
8. `main`'in bütün deyimleri bitince `main` de bir şey döndürmediği için düz çizgi yerine kesikli okla bittiği gösterilir.

<!-- BELİRSİZ: Ardışık diyagramın kendisi karelerde görünmüyor; adımlar altyazıdaki anlatımdan kuruldu. -->

## 11. Hocanın Ara Toparlaması

Hoca bu noktada sorusu olup olmadığını sordu ve önemli noktaları Türkçe özetledi:

> **Hocanın vurgusu:** Public ve private erişim belirleyiciler, getter ve setter metotları çok önemlidir; sınavlarda karşınıza çıkacaktır. static ve final anahtar sözcüklerinin nerede kullanıldığı da önemlidir.

Sorularda "burada static ya da final kullanın" denmeyecektir. Bunun yerine problemin tarifi verilecektir:

- "Bir değişken var, bunun yalnız bir değeri olacak ve bu değer değişmeyecek" denirse o değişkeni tanımlarken `final` kullanmanız gerektiğini bileceksiniz.
- "Bir değer var, bu değer bütün nesneler için aynı olacak" denirse `static` kullanmanız gerektiğini hatırlayacaksınız.

> **Hocanın vurgusu:** Kurucular çok önemlidir: tek parametreli, iki parametreli ve varsayılan kurucuların kullanımı bilinmelidir. Değişkenlerin ilk değerleri kurucu içinde atanacaktır. Kod yazarken bütün üye alanlar için getter ve setter mutlaka yazılacak, üye alanlar mutlaka private tanımlanacaktır.

## 12. İkinci Car Sınıfı, this ve Getter/Setter Gerekçesi

### 12.1 nyp01b.Car

Hoca `Car` sınıfının başka bir sürümünü gösterdi (ekrandan, 01:55:00):

```text
+----------------------------+
|            Car             |
+----------------------------+
| - plate : String           |
| - chassisNR : String       |
+----------------------------+
| + Car( String, String )    |
| + getPlate( ) : String     |
| + setPlate( String )       |
| + getChassisNR( ) : String |
+----------------------------+
```

Kodu Bölüm 6'daki `nyp01b.Car` sınıfıdır. İki alan vardır: plaka ve şasi numarası. İki parametreli tek bir kurucu bu alanlara ilk değer atar. Plaka için getter ve setter, şasi numarası için yalnız getter vardır.

Hoca burada şasi numarası için setter yazmadığını, ama yazması gerektiğini ve öğrencilerden bütün alanlar için getter/setter beklediğini söyledi.

> **Ders sonrası not:** Slayttaki son madde (ekrandan, 02:05:00) bu konuda farklı bir gerekçe verir: gerçek dünyada bir arabanın şasi numarası hiç değişmez; bu yüzden o alanın değiştirici metodu bilerek yazılmamıştır, yazılsaydı başka bir hata (bug) eklenmiş olurdu. Slaytta bu metot için "getter" yazılmıştır, ama kodda `getChassisNR` bulunduğu için kastedilen büyük olasılıkla setter'dır. Slayt ayrıca bu alanın `final` tanımlanabileceğini anar.

Slayta göre bu ikinci sürümde `main` metodu yoktur; bu yüzden tek başına çalıştırılıp test edilemez. Bu amaçla `main` metodu olan başka bir sınıf yazmak gerekir (ileride gösterilecek).

### 12.2 this anahtar sözcüğü

**Soru:** Kurucunun içinde bir atamada `this` kullanılmış, üstteki atamada kullanılmamış. Farkı var mı?

**Cevap:** Bir sınıfın içindeki bütün metotlar o sınıfın üye alanlarına doğrudan ulaşabilir. Alan private ya da public olsun fark etmez, çünkü aynı sınıfın metotlarından söz ediliyor. Doğrudan ulaşamayan tek metot `main`'dir: `main` static tanımlandığı için içinde yalnız static üye alanlar doğrudan kullanılabilir. Bu örnekte başka static metot olmadığı için bütün metotlar alanlara doğrudan erişir.

Kurucunun parametrelerine bakıldığında: `plateNr` ile üye alan `plate`'in adları farklıdır. `plateNr` kurucunun yerel parametresi, `plate` ise üye alandır. Farklı adlı iki değişken arasında atama yapıldığı için sorun yoktur ve `this` gerekmez.

`chassisNR` için durum farklıdır: parametrenin adı ile üye alanın adı aynıdır. Parametre listesinde gelen girdinin türü belirtilmiştir; sınıfın üstünde de bütün kodun göreceği bir `chassisNR` alanı `String` olarak tanımlanmıştır. Derleyicinin bu ikisini karıştırmaması için atamada birinin önüne, bu nesnenin üye alanı olduğunu belirtmek üzere `this` konur. Demek ki `this` nesnenin kendisini belirtir. `this.setPlate(...)` yazılsaydı bu nesnenin `setPlate` metodu çağrılırdı.

`setPlate(String plate)` metodunda da aynı durum vardır: yerel parametrenin adı da alanın adı da `plate`'tir. Bu yüzden `this.plate = plate;` yazılarak soldaki `plate`'in üye alan olduğu belirtilir.

### 12.3 Alanı public yapmak yerine neden getter/setter?

**Soru:** Bilgiyi private tanımlayıp getter/setter ile okumak ve değiştirmek yerine alanı public yapıp `car.plate` biçiminde doğrudan erişmekten farkı ne? Neden metotlarla uğraşıyoruz?

**Cevap:** Bir program tek başına da bir geliştirme ekibi içinde de yazılabilir; yazdığımız sınıfı başkaları kendi sınıflarında kullanabilir. Kendi mantığımızda üye alanların belli bir kullanım amacı vardır: `plate` yalnız plaka numarası, `chassisNR` yalnız şasi numarası içindir. Bu yüzden bu değerlere yalnız bizim metotlarımız üzerinden gidilmesini isteriz.

Örneğin `setPlate` içine bir denetim yazılabilir: plaka önce il kodu olan iki rakam, ardından harfler, ardından rakamlar içermelidir. Plakanın uyması gereken kurallar denetlendikten sonra atama yapılır. Alanların değerine ne gireceğini sınıfı yazan belirler.

Alanlar public olsaydı, sınıfı kullanan biri nesneyi oluşturur, alanları görür, sınıf adı ve nokta yazarak denetimsiz değer atar, sonra sınıfın öbür metotlarını çağırmaya başlardı. Alanlara yanlış değerler atandığı için kod olması gerektiği gibi çalışmazdı. Alanı private yapmak şunu söyler: nesnenin alanlarını benim metotlarım üzerinden değiştirir ve okursan, kodumun öbür kısmı içerideki değerlerin ne olduğunu bildiği için davranışı bozulmaz.

Hoca iki gerekçe verdi:

1. Yazılan kodun çalışma mantığını başka bir sınıfın bozmaması.
2. Güvenlik: public tanımlanmış bütün değişkenler güvenlik açıklarına yol açar. Aynı JVM'de çalışan ve saldırı yapmak isteyen başka bir kod, bu public değişkenlerin değerini değiştirerek programın normal davranışını değiştirmeye çalışabilir.

Bu yüzden, public tanımlamak için çok önemli bir gereksinim yoksa üye alanlar private tanımlanır ve public getter/setter metotlarıyla erişilir.

Hoca soru sormaktan çekinilmemesini, bu dersin nesneye yönelik programlamayı ilk kez öğrenmek olduğunu söyledi. Derslerden sonra Eclipse, IntelliJ ya da NetBeans kurulup ders sayfasındaki kodların ve Deitel & Deitel kitabının kodlarının bir projeye dönüştürülmesini, her dersin konusundaki sınıfların çalıştırılıp değiştirilmesini ve sonuçlarının gözlenmesini istedi.

## 13. Doğru ve Yanlış Kurucu

`main` metodu olmayan bir sınıf JVM tarafından doğrudan çalıştırılamaz; yalnız `main` metodu olan sınıflar doğrudan çalıştırılabilir. Bu yüzden ikinci `Car` sürümü için `main` içeren ek bir sınıf gerekir.

Son slaytta iki `Car` sınıfı karşılaştırılır (ekrandan, 02:05:00):

```java
// Soldaki (doğru) sürüm
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
```

```java
// Sağdaki (yanlış) sürüm
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

Slayttaki açıklama: gerçek dünyada her arabanın bir plakası **ve** bir şasi numarası olmalıdır. Bu yüzden iki alan, iki parametreli aynı kurucuda ilk değer almalıdır. Soldaki kod doğru, sağdaki yanlıştır.

Sağdaki sürümün iki kurucusunun da tek parametresi vardır ve parametre türü `String`'dir; imzaları aynıdır. Bir sınıfta aynı imzaya sahip iki metot bulunamaz, bu yüzden derleyici hata verir. Ajan bu sürümü `java` ile denediğinde derleyici şu hatayı verdi: `constructor Car(String) is already defined in class Car`.

Slayttaki "Compile error vs. bug" maddesi: sağdaki kod derlenmez; derlenseydi bile mantığı yanlış (hatalı, buggy) olurdu. Çünkü kuruculardan biri çağrıldığında oluşturulan nesnenin gerekli alanlarından biri değersiz kalırdı.

> **Hocanın vurgusu:** Bir sınıf için kurucu yazarken kurucunun o sınıf için gerekli bütün üye alanlara ilk değer atadığından emin olun. Bu örnekte gerekli alanlar plaka ve şasi numarasıdır.

Hoca dersi burada bitirdi. Sonraki dersin konusu ilkel veri türleri (primitive data types) ve bunların sarmalayıcıları (wrapper), yani Java'da ilkel türlerin nesne karşılıklarıdır.

## Örnek Sorular

**1. (derste sözlü, 00:48:33)** Bir sınıfta birden fazla private üye alan varsa her biri için ayrı getter ve setter yazmak gerekir mi?

> **Cevap (derste verildi):** Evet. Bütün private üye alanlar için ayrı getter ve setter metotları yazılır; sınavda da bütün alanlar için beklenir.

**2. (derste sözlü, 01:53:26)** `nyp01b.Car` kurucusunda `plate = plateNr;` satırında `this` yokken `this.chassisNR = chassisNR;` satırında var. Farkı nedir?

> **Cevap (derste verildi):** `plateNr` parametresi ile `plate` alanının adları farklı olduğu için `this` gerekmez. `chassisNR` parametresi ile `chassisNR` alanının adı aynı olduğu için, atamanın solundakinin nesnenin üye alanı olduğunu belirtmek üzere `this.` yazılır. `this` nesnenin kendisini belirtir.

**3. (derste sözlü, 01:57:44)** Alanı public yapıp doğrudan erişmek yerine neden private alan ve getter/setter kullanılır?

> **Cevap (derste verildi):** (1) Setter içinde değer denetlenebilir (örneğin plaka biçimi); böylece başka sınıflar alanlara yanlış değer atayıp sınıfın çalışma mantığını bozamaz. (2) Public alanlar güvenlik açığı doğurur; aynı JVM'deki kötü niyetli bir kod bu değerleri değiştirip programın davranışını bozabilir.

**4. (ekrandan, 02:05:00)** Aşağıdaki sınıf neden yanlıştır? Derlenir mi?

```java
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

> **Cevap (derste verildi):** Derlenmez, çünkü iki kurucunun imzası aynıdır (tek `String` parametre). Derlenseydi bile mantık hatası olurdu: her araba nesnesinin hem plakası hem şasi numarası olmalıdır, ama kuruculardan hangisi çağrılırsa çağrılsın alanlardan biri boş kalır. Doğrusu iki alanı birlikte atayan `Car(String plateNr, String chassisNR)` kurucusudur.

## Dersin Toparlaması

Bu derste kapsüllemenin Java'daki karşılığı olan görünürlük kuralları işlendi. Bilgi gizleme ilkesine göre bir nesnenin iç işleyişi başka türdeki nesnelerden gizlenir ve yalnız gereken metotlar public yapılır. Erişim belirleyiciler `public` (`+`), `private` (`-`), `protected` (`#`) ve package (`~`) olarak tanıtıldı; bu derste ve sınavlarda üye alanların private tanımlanması, erişimin public getter ve setter metotlarıyla yapılması kural olarak kondu. Ardından üyelerin iki özel durumu anlatıldı: bütün nesnelerin paylaştığı `static` üyeler ve yalnız bir kez değer alan `final` üyeler. İkisinin karıştırılmaması ve bir alanın aynı anda ikisi de olabileceği vurgulandı.

Dersin ikinci yarısında kurucular işlendi: kurucunun adı sınıfla aynıdır, dönüş türü yoktur, `new` ile çağrılır ve alanlara ilk değer atar. Hiç kurucu yazılmazsa derleyici varsayılan kurucu ekler; imzası farklı birden çok kurucu yazmak aşırı yüklemedir, aynı imzalı iki kurucu ise derleme hatasıdır. Programın `main` metodundan başladığı, `main` içindeki deyimlerin yazıldığı sırayla yürütüldüğü ve bu akışın UML ardışık diyagramıyla gösterildiği anlatıldı. `this` anahtar sözcüğü ve getter/setter kullanmanın gerekçesi öğrenci sorularıyla açıklandı. Sonraki derste ilkel veri türleri ve sarmalayıcı sınıflar işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
