# Ders 12 Çalışma Özeti

## Genel Konular

- Soyut sınıflar (abstract classes)
  - Kalıtım ilişkisi iki yolla kurulabilir: normal (regular, concrete) sınıflarla ya da soyut sınıflarla. Bu derste soyut sınıflar, ardından arayüzler (interfaces) işlendi (ekrandan, 00:15:00; slayt 113).
  - Soyut sınıf `public abstract class SinifAdi { ... }` biçiminde tanımlanır. Normal sınıf gibi üye alanları ve normal (somut) metotları olabilir; ek olarak bazı metotları `abstract` tanımlanabilir.
  - Soyut sınıfın nesnesi `new` ile oluşturulamaz. Soyut sınıf, ondan türeyen alt sınıflar için bir şablondur (template).
  - Soyut metodun yalnız tanımı (imzası) vardır, gövdesi yoktur: `public abstract void print( Document doc );`.
  - Soyut sınıftan türeyen sınıf, kalıtımla aldığı bütün soyut metotların gövdesini yazmak zorundadır; yazmazsa kendisi de soyut tanımlanmalıdır. Soyut bir sınıftan yine soyut bir sınıf türeyebilir, ama nesnesi kullanılacak olan en alttaki sınıf normal sınıf olmalıdır.
- Soyut sınıf ne zaman gerekir? (ekrandan, 00:20:00; slayt 114)
  - Sınıf hiyerarşisinde yukarı çıkıldıkça sınıflar genelleşir. Bir noktada üst sınıf o kadar genel olur ki nesnesine gerek kalmaz; bu durumda soyut sınıf tercih edilir.
  - Belirli bir metodun bütün alt sınıflarda bulunması isteniyor ama üst sınıfta gövdesi yazılamıyorsa ya da yazmak anlamsızsa bu metot soyut tanımlanır.
  - UML'de soyut sınıf adının üstüne `<<Abstract>>` stereotipi yazılır ya da ad italik yazılır. Soyut metot UML'de `{abstract}` ile işaretlenir. `<<...>>` gösterimine stereotip denir.
- `PrintDriver` örneği (ekrandan, 00:25:00; slayt 116)
  - `PrintDriver` soyut sınıftır; `initSpooler()` normal metottur ve gövdesi vardır, `print(Document doc)` soyut metottur.
  - `PCL6Driver extends PrintDriver` alt sınıfı `print` metodunun gövdesini yazar. `initSpooler` metodunu kalıtımla kendi metodu gibi kullanır.
  - Her yazıcının yazdırma işlemi farklı olduğu için `print` genel sınıfta yazılamaz, her sürücü kendi uygulamasını yazar.
- Çoklu kalıtım ve elmas problemi
  - `extends` anahtar sözcüğünden sonra yalnız bir sınıf adı gelir: bir alt sınıfın tek bir üst sınıfı olabilir. Normal ve soyut sınıflarla çoklu kalıtım yapılamaz.
  - Neden: `Person` üst sınıfından `Student` ve `Employee` türesin, ikisi de `introduceSelf()` metoduna sahip olsun. Hem `Student` hem `Employee` sınıfını genişleten bir `AssistantStudent` sınıfında `introduceSelf()` çağrıldığında hangi üst sınıfın metodunun kullanılacağı belirsiz kalır. Şekli elmasa benzediği için buna elmas kalıtım problemi (diamond inheritance problem) denir.
  - Birden fazla üst sınıfın yeteneğine ihtiyaç duyulduğunda arayüzler kullanılır.
- Soyut sınıf tasarımı: çocuklar için eşyalar (`nyp06` paketi) (ekrandan, 00:35:00; slayt 118)
  - Her eşya her çocuğa uygun değildir: oyuncakların yıl olarak alt yaş sınırı, giysilerin ay olarak alt ve üst sınırı vardır.
  - UML: `<<Abstract>> Item` (`- barcode, description : String`; `+ Item( barcode, description : String )`, `+ getBarcode( ) : String`, `+ getDescription( ) : String`, `+ isSuitable( aChild: Child ) : boolean {abstract}`). `Toy` (`- minAgeLimit : int`) ve `Clothing` (`- minMonthLimit, maxMonthLimit : int`) `Item`'dan türer.
  - `Item` ile `Child` (`- name : final String`, `- ageInMonths : int`) arasında kesikli ok vardır: `Child` yalnız `isSuitable` metodunun parametresinde geçtiği için bu bir bağımlılıktır (dependency).
  - `KinderGarten 1 → * Child`: bir anaokulunda sıfır ya da daha çok çocuk olur, bir çocuk yalnız bir anaokuluna aittir; hoca bunu composition gibi yorumladı. `KinderGarten` metotları: `+ addChild( Child ) : boolean`, `+ findOldestChild( ) : Child`.
  - `Item`'ın alanları `private` tutulur; alt sınıflar bunlara üst sınıfın metotları üzerinden erişir.
- Somut alt sınıflar (ekrandan, 00:45:00 ve 00:50:00; slayt 120-121)
  - `Clothing` yapıcısı dört parametre alır: ilk ikisini `super(barcode, description)` ile üst sınıfın yapıcısına verir, kalan ikisini kendi alanlarına atar. `isSuitable`, çocuğun ay olarak yaşı `minMonthLimit` ile `maxMonthLimit` arasındaysa (sınırlar dahil) `true` döndürür.
  - `Toy` yapıcısı üç parametre alır, yine `super(...)` kullanır. `isSuitable`, `aChild.getAgeInMonths()/12` (yıl olarak yaş) `minAgeLimit` değerinden büyük ya da eşitse `true` döndürür.
- `Kindergarten` sınıfının kodu (ekrandan, 01:05:00 ve 01:10:00)
  - Alanlar: `private Child[] children;` ve `private int childCount;`. Yapıcı `children = new Child[maxChild];` ile diziyi oluşturur; dizinin bütün hücreleri başta `null`'dır, henüz hiç `Child` nesnesi yoktur.
  - `findChild(String name)`: `childCount`'a kadar dolaşır, adı `equalsIgnoreCase` ile eşleşen çocuğu döndürür, bulamazsa `null` döndürür.
  - `addChild(Child aChild)`: dizi doluysa (`childCount == children.length`), gelen referans `null` ise ya da aynı adda çocuk zaten varsa `false` döndürür; yoksa çocuğu `children[childCount]` hücresine koyar, `childCount`'u artırır.
  - `findOldestChild()`: `findChild` ile aynı mantıkla dolaşır, yaşı en büyük çocuğu döndürür.
  - `getCapacity()` dizinin uzunluğunu döndürür. `setCapacity(int capacity)`: yeni kapasite daha büyükse yeni bir dizi oluşturur, eski elemanları `for` döngüsüyle kopyalar ve `children` değişkenini yeni diziye yöneltir.
  - `removeChild(String name)`: çocuğu bulur, referansını geçici bir değişkende tutar, sonraki elemanları birer sola kaydırır ve çıkarılan çocuğu döndürür.
  - `Main` sınıfı bu metotları "Deneme 1 ... Deneme 7" çıktılarıyla sınar (ekrandan, 01:15:00).
- Normal sınıflarla kalıtım tekrarı: `Point` ve `Circle` (`oop_fig94` paketi) (ekrandan, 01:20:00)
  - `Point` normal sınıftır, `x` ve `y` alanları `protected` tanımlanmıştır; böylece alt sınıfların metotları bu alanlara doğrudan erişebilir.
  - `Circle extends Point` kendi `radius` alanını ekler. Üç parametreli yapıcı `super( a, b )` ile üst sınıfın yapıcısını çağırır, `setRadius( r )` ile yarıçapı atar.
  - `setRadius` yarıçapı doğrudan atamak yerine `radius = ( r >= 0.0 ? r : 0.0 );` denetimini yapar; atamanın bir metotla yapılması bu tür denetimlere olanak verir.
- Arayüzler (interfaces) (ekrandan, 01:25:00; slayt 122)
  - Arayüz, üyesi olmayan ve hiçbir metodunun gövdesi olmayan bir soyut sınıf gibi düşünülebilir; adlandırılmış bir metot topluluğudur.
  - `public interface Customer { ... }` biçiminde tanımlanır: `class` ve `abstract` sözcükleri kullanılmaz. UML'de sınıf adının üstüne `<<interface>>` yazılır.
  - Arayüzdeki metotların yalnız imzası vardır; hepsi zaten soyut olduğu için `abstract` yazılmaz.
  - Arayüzde normal üye alan tanımlanamaz; yalnız `public final static` alan eklenebilir. Arayüzde yalnız `public` metotlar bulunur, yapıcı (constructor) yoktur.
  - Bir sınıf arayüzü `implements` ile uygular ve birden fazla arayüzü virgülle ayırarak uygulayabilir: `public class Person implements Customer, Supplier, Friend`. `Person`, `buy`, `sell` ve `keep` metotlarının hepsini yazmak zorundadır.
  - Arayüzler sorumlulukları gruplamak ve bir nesneye birden çok görünüm (multiple views) vermek için kullanılır: bir kişi alan müşteri, satan tedarikçi ve sır tutan arkadaş olabilir.
  - Kod geleneği olarak arayüz adları büyük `I` harfiyle başlatılabilir; zorunlu değildir.
- Arayüz tasarımı: taşıt vergileri (`nyp07` paketi) (ekrandan, 01:35:00; slayt 125)
  - Gereksinim: ticari ve kişisel taşıtların vergisi farklıdır; motosiklet, otomobil ve otobüs ticari taşıt olarak kaydedilebilir; yalnız motosiklet ve otomobil kişisel taşıt olabilir; yalnız ticari taşıt vergisi amortize edilebilir (indirimli olabilir).
  - `<<interface>> CommercialVehicle`: `+ getPlate( ) : String`, `+ calculateAmortizedTax( baseTax : double, currentYear : int ) : double`. `<<interface>> PersonalVehicle`: `+ getPlate( ) : String`, `+ calculateTax( baseTax : double ) : double`.
  - `Motorcycle`, `Car` ve `Bus` `CommercialVehicle`'ı; `Motorcycle` ve `Car` ayrıca `PersonalVehicle`'ı uygular.
  - Slayttaki ipucu: vergi hesabı taşıtlar için benzer (parametreyle ayarlanabilir) olsaydı arayüz yerine tek bir soyut üst sınıf daha iyi bir seçim olurdu.
- `Car` ve `Bus` sınıfları (ekrandan, 01:40:00 ve 01:45:00; slayt 127-128)
  - `Car implements CommercialVehicle, PersonalVehicle`: alanlar `plate`, `modelYear`, `engineVolume`. `calculateTax` `baseTax * engineVolume` döndürür. `calculateAmortizedTax` her yıl için %10 indirim yapar: yaş 10'dan küçükse `baseTax * engineVolume * (1-age*0.10)`, değilse `baseTax * engineVolume * 0.10`.
  - `Bus implements CommercialVehicle`: alanlar `plate`, `modelYear`, `tonnage`. Yalnız `calculateAmortizedTax` ve `getPlate` arayüzden gelir. Tonaj oranı `< 1.0` için 1.0, `< 5.0` için 1.2, `< 10.0` için 1.4, diğerlerinde 1.6'dır; yaş oranı `(currentYear - modelYear) * 0.05`'tir ve 2.0'ı geçemez; sonuç `baseTax * ratioTonnage * ratioAge`'dir.
  - `VehicleRegistrationSystem`, `CommercialVehicle` ve `PersonalVehicle` türünde diziler tutar; arama ve kayıt metotları vardır, kod tamamlanmamıştır (ekrandan, 02:15:00).
- İki arayüzde aynı adlı metot
  - `getPlate` iki arayüzde de vardır; `Car` bunu bir kez yazar ve sorun çıkmaz. Arayüz yalnız "bu ad ve dönüş türüyle bir metodun olacak" der, gövdeye karışmaz.
  - İki metodun farklı işler yapması isteniyorsa adları (ya da imzaları) farklı olmalıdır.
  - Ortak metot bir üst arayüze taşınabilir: `Vehicle` arayüzü `getPlate`'i tutar, `PersonalVehicle` ve `CommercialVehicle` `extends Vehicle` ile ondan türer.
- Arayüz mü soyut sınıf mı? (ekrandan, 01:50:00; slayt 131)
  - Java sınıf düzeyinde çoklu kalıtımı desteklemez, ama bir sınıf birden çok arayüzü uygulayabilir; bu yüzden birden çok görünüm gerektiğinde arayüz uygundur.
  - Alt sınıfların ortak kullandığı çok sayıda metot varsa soyut sınıf daha yararlıdır: ortak metotların gövdesi bir kez üst sınıfta yazılır, yalnız farklılaşan metotlar soyut bırakılır.
  - Arayüzde yapılan en küçük değişiklik (yeni metot, dönüş türü değişikliği) onu uygulayan bütün sınıfları etkiler. Soyut sınıfa ise gövdesi olan yeni bir metot eklenebilir, alt sınıfları değiştirmek gerekmez.
  - "A bir B'dir" (is-a) denebiliyorsa soyut sınıf ve kalıtım, "A şunu yapabilir" (is capable of) denebiliyorsa arayüz kullanılır.
- Arayüzle kalıtım örneği: `Shape`, `Point`, `Circle`, `Cylinder` (`interfaceExample` paketi) (ekrandan, 00:55:00, 02:00:00, 02:05:00)
  - `Shape` arayüzünde `area`, `volume` ve `getName` metotları vardır. `Point implements Shape` üçünü de yazar (`area` ve `volume` 0.0 döndürür).
  - `Circle extends Point`, `area` ve `getName` metotlarını yeniden tanımlar (override); `volume` metodunu `Point`'ten kalıtımla alır. `Cylinder extends Circle`, `area`, `volume` ve `getName` metotlarını yeniden tanımlar.
  - `Cylinder` yapıcısı `x`, `y` ve `radius` alanlarına doğrudan atama yapar; bu alanlar `protected` olduğu için mümkündür.
  - `Test` sınıfında `Shape arrayOfShapes[] = new Shape[3];` dizisine `Point`, `Circle` ve `Cylinder` nesneleri konur ve döngüde her nesnenin `getName`, `area` ve `volume` metotları çağrılır. Arayüz de bir değişkenin ya da dizinin türü olabilir.
- Normal sınıfla kalıtım örneği: `acc` ve `accBusiness` (ekrandan, 02:10:00)
  - `acc` sınıfının `protected` `name` ve `balance` alanları, yapıcısı, `getBalance`, `withdraw` ve `deposit` metotları vardır. `accBusiness` bunları yeniden tanımlamadan kullanır, yapıcısında `super(...)` çağırır ve yalnız kendine özgü faiz metodunu ekler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arayüz tanımlarken yapılan hatalar puan kaybettirir
  - `interface class Shape` yazılmaz; yalnız `interface` sözcüğü kullanılır.
  - Arayüzdeki metotlara `abstract` yazılmaz, çünkü hepsi zaten soyuttur.
  - Arayüzdeki metotlara gövde yazmak arayüz kavramının anlaşılmadığını gösterir.
  - Bir sınıf arayüzü `extends` ile değil `implements` ile uygular.
- Dizi oluşturmak nesne oluşturmak değildir
  - `new Shape[3]` ya da `new Child[maxChild]` yalnız referansları tutacak hücreleri oluşturur; hücreler `null`'dır. Nesneler ayrıca `new` ile oluşturulup hücrelere atanmalıdır.
- Dizi tabanlı ekleme, arama, çıkarma ve kapasite artırma
  - Composition içeren bir soruda dizide nesne ekleme, bulma, çıkarma ve dizinin kapasitesini artırma metotlarının yazılabilmesi gerekir. Taşıt kayıt sistemindeki eksik metotların (ekleme, çıkarma) ve bir `main` programının yazılması alıştırma olarak önerildi.
- Ana programı metinden yazabilmek
  - Yalnız UML diyagramından sınıfları kodlamak yetmez; adım adım metin olarak verilen bir akışa (anaokulu oluştur, iki çocuk ekle, uygunluğu sına, kapasiteyi değiştir, bir çocuğu çıkar gibi) göre `main` programı da yazılabilmelidir.
- UML diyagramında metotların gösterilmesi
  - Slayttaki diyagramda `Toy` ve `Clothing` metotları gizlenmişti; hoca bir UML diyagramı çizilmesi istendiğinde sınıfların metotlarının da gösterilmesini istedi.
- Üst sınıfın çocuk nesne yerine kullanılması
  - "Üst sınıf beklenen her yerde çocuk sınıfın nesnesi kullanılabilir." Arayüzün nesnesi olmaz, ama arayüz türündeki değişken ya da dizi hücresi onu uygulayan sınıfların nesnelerini gösterebilir.

## Kısa Tekrar Notları

- `abstract class`: nesnesi oluşturulamaz, alanları ve normal metotları olabilir, soyut metotların gövdesi yoktur.
- Soyut sınıftan türeyen normal sınıf bütün soyut metotları yazmak zorundadır.
- Alt sınıfın yapıcısı üst sınıfın `private` alanlarını `super(...)` ile başlatır.
- `extends` sonrasında tek sınıf adı: Java'da sınıflarla çoklu kalıtım yoktur (elmas problemi).
- `interface`: yalnız metot imzaları, `public final static` dışında alan yok, yapıcı yok, metotlar `public`.
- `implements A, B, C`: bir sınıf birden çok arayüzü uygulayabilir ve bütün metotlarını yazmak zorundadır.
- Bir arayüz başka bir arayüzü `extends` ile genişletebilir.
  - Ders sonrası not: Hoca bir arayüzün yalnız tek bir arayüzü genişletebileceğini söyledi; doğrusu, Java'da bir arayüz birden çok arayüzü genişletebilir (`interface PV extends Vehicle, Taxable`; ajan tarafından derlenip çalıştırıldı). Tek üst sınıf kuralı sınıflar içindir.
- Override: alt sınıfta üst sınıfla aynı imzalı metodu yazmak. Overload: aynı sınıfta aynı adlı, farklı parametreli metotlar. Bunlar kavramdır; `abstract`'ın yerine geçmez.
  - Ders sonrası not: Hoca overload için "ya dönüş türü farklıdır ya da argüman türü" dedi; doğrusu, Java'da yalnız dönüş türü farklı olan iki metot overload sayılmaz ve derleme hatası verir (ajan tarafından denendi). Parametre listesi farklı olmalıdır.
- `protected` alanlara alt sınıflar doğrudan erişir; kalıtım ağacı dışındaki sınıflar erişemez, `public` metotları kullanır.
- Ortak kod çoksa soyut sınıf, birden çok yetenek gerekiyorsa arayüz.
- "is-a" ise soyut sınıf, "is capable of" ise arayüz.

## Detaylı Açıklamalar

- Soyut sınıf, kalıtım ağacının tepesindeki genel sınıf için kullanılır. Bu sınıfın kendi başına bir nesnesine ihtiyaç yoktur, ama altındaki bütün sınıfların belirli metotlara sahip olması istenir. `PrintDriver` örneğinde her yazıcı sürücüsünün `print` metodu olmalıdır, fakat genel bir sürücü için yazdırmanın nasıl yapılacağı bilinmez. Bu yüzden `print` soyut tanımlanır ve gövdesi `PCL6Driver` gibi somut sınıflarda yazılır. Buna karşılık `initSpooler` gibi bütün sürücülerde aynı çalışan bir metot soyut sınıfta bir kez yazılır ve alt sınıflar onu kalıtımla kullanır.

- Çocuklar için eşya örneğinde `Item` soyut sınıfı barkod ve açıklamayı tutar ve `isSuitable(Child)` metodunu soyut bırakır. Oyuncak için uygunluk yıl olarak yaşa, giysi için ay olarak bir aralığa bakar; bu yüzden her alt sınıf kendi kuralını yazar. Alt sınıfların yapıcıları önce `super(barcode, description)` ile üst sınıfın `private` alanlarını başlatır, sonra kendi alanlarını atar. `Item` ile `Child` arasındaki ilişki bağımlılıktır, çünkü `Child` türü `Item`'ın hiçbir alanında değil, yalnız bir metodun parametresinde geçer. Association olsaydı `Item` içinde `Child` türünde bir üye alan olurdu.

- Anaokulu sınıfında dizi tabanlı veri yapısı yönetimi tekrar edildi. `childCount` dizideki ilk boş hücreyi gösterir. `addChild` üç durumda eklemeyi reddeder: dizi doludur, gelen referans `null`'dır ya da aynı adda çocuk zaten vardır. `setCapacity` daha büyük yeni bir dizi oluşturup elemanları kopyalar ve alan değişkenini yeni diziye yöneltir. `removeChild` çıkarılan elemandan sonrakileri birer sola kaydırır.
  - Bir öğrenci kaydırmadan sonra dizinin son dolu hücresinin `null` yapılması gerekip gerekmediğini sordu. Hoca haklı olduğunu, `childCount`'un da azaltılması gerektiğini söyledi. Eleman sayısı `childCount` ile izlendiği için sondaki eski referans çalışmayı bozmaz, ama `null` yapılması daha iyidir.

- Arayüz, bir sınıfın sahip olması gereken yetenekleri (capabilities) gruplar. `Person` sınıfı `Customer`, `Supplier` ve `Friend` arayüzlerini birlikte uygulayarak üç ayrı görünüme sahip olur. Soyut sınıftan farkı, arayüzde ortak bir uygulama ya da veri alanı bulunmamasıdır. Taşıt örneğinde `Car` hem ticari hem kişisel taşıt olabildiği için iki arayüzü uygular ve `getPlate`, `calculateTax`, `calculateAmortizedTax` metotlarının üçünü de yazar. `Bus` yalnız ticari taşıt olduğu için `calculateTax` yazmak zorunda değildir. Hoca vergi formüllerinin ayrıntılarına takılmamayı, sınavda böyle bir metodun nasıl hesaplanacağının metinle açıklanacağını söyledi; önemli olan arayüzden gelen metodun alt sınıfta yazılmasıdır.

- `Shape` örneği üç kalıtım türünü bir arada gösterir: `Point` bir arayüzü uygular, `Circle` normal sınıf `Point`'i genişletir, `Cylinder` de `Circle`'ı genişletir. `Circle` `volume` metodunu yazmadığı için `Point`'in 0.0 döndüren `volume` metodunu kullanır. `Test` programında üç nesne `Shape` türündeki bir diziye konur ve döngüde her nesnenin kendi metotları çağrılır. Program çalıştırıldığında (ajan tarafından, `Circle`'ın alanı $\pi r^2$ kabul edilerek) `Point` için alan ve hacim 0.0, `Circle(3.5, 4, 5)` için alan yaklaşık 38.48 ve hacim 0.0, `Cylinder(5, 3.5, 4, 5)` için alan yaklaşık 186.92 ve hacim yaklaşık 192.42 çıkar.
<!-- BELİRSİZ: interfaceExample paketindeki Circle sınıfının kodu karelerde görünmüyor; alanın Math.PI*radius*radius olduğu oop_fig94 paketindeki Circle sınıfından varsayıldı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
