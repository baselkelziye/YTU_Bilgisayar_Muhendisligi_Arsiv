# Ders 14 Genişletilmiş Notu: Arayüzler (Interface) ve Enum Sınıfları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arayüz kavramı neden ortaya çıktı
- 2. Arayüzün tanımı ve UML gösterimi
- 3. Arayüzün Java'da yazılması
- 4. Arayüz kuralları
- 5. Taşıt vergi sistemi örneği
- 6. Car ve Bus sınıfları
- 7. Araç kayıt sistemi tasarımı
- 8. Arayüzler arasında kalıtım
- 9. Eclipse'te arayüz kurallarının gösterimi
- 10. VehicleRegistrationSystem kodunun incelenmesi
- 11. Üst arayüzlü sürüm (nyp07b)
- 12. Hem kalıtım alan hem arayüz gerçekleyen sınıf
- 13. UML'de override gösterimi
- 14. Basit (primitive) enum
- 15. Enum sınıfları
- 16. Tariff, Subscription, Person örneğinin çalıştırılması
- Örnek Sorular
- Dersin Toparlaması

## 1. Arayüz kavramı neden ortaya çıktı

Önceki derste kalıtımla ilgili iki noktanın altı çizilmişti. Birincisi, kalıtım güçlü bir araçtır ama doğru kullanılması gerekir; yanlış kullanılma riski vardır. İkincisi, çoklu kalıtım haklı nedenlerle desteklenmez. Bu iki nokta göz önüne alınınca hem akademide hem sektörde şu iki soru sorulmuştur: kalıtım gibi ağır bir ilişkinin yerine kullanılabilecek daha hafif bir şey var mı, ve çoklu kalıtımın sakıncalarını taşımadan onun sağlayabileceği avantajlar nasıl elde edilir? Bu soruların cevabı arayüz (interface) kavramıdır. Modern nesneye yönelik diller arayüzü desteklemeye başlamıştır.

## 2. Arayüzün tanımı ve UML gösterimi

Hoca arayüzü en kolay şöyle tanımlar: bir arayüzü bir soyut sınıf gibi düşünün, ama bunun bir kısıtlaması vardır. Arayüze normal üye alan eklenemez. Eklenebilecek tek üye alan türü aynı anda `public`, `final` ve `static` olan, yani sabit niteliğindeki alanlardır. Örneğin `private` bir üye alan arayüze konamaz.

Bunun nedeni arayüzün kullanım amacıdır. Arayüz bir varlığın sorumluluklarının bir alt kümesini içerir; başka bir deyişle bir varlık için bir rol tanımlar. Arayüzde metot tanımları yer alır ve bunlar soyut metotlar topluluğu gibi düşünülebilir. Bu anlamda arayüz, isimlendirilmiş bir metot imzaları kümesidir. Bu imzalar bir arada bir varlığa bir rol ya da bir bakış açısı kazandırır.

Gerçek hayatta bir varlığın birden fazla rolü olabildiği gibi, bir sınıf da birden fazla arayüzü gerçekleyebilir. Buradaki anahtar kelime "gerçeklemek"tir (İngilizcesi implementation). Arayüz sınıfa göre daha hafif bir yapı olduğu için birden fazla arayüz gerçeklemek sorun çıkarmaz. Çoklu kalıtımda konuşulan elmas (diamond) kalıtım sorunları burada ortaya çıkmaz, çünkü arayüzdeki bütün metotlar yalnız imza olarak tanımlıdır.

### 2.1 UML'de arayüz

Slayttaki örnekte üç arayüz vardır (ekrandan, 00:10:00):

```text
«interface» Customer     «interface» Supplier     «interface» Friend
+ buy(Good, int)         + sell(Good, int)        + keep(Secret)
        ^                        ^                        ^
        :........................:........................:
                                 :
                              Person
```

UML'de arayüz, sınıf kutusunun ad bölmesine `«interface»` stereotipi ve arayüzün adı yazılarak gösterilir. Arayüzde üye alan olmadığı hâlde kullanılan araca göre üç bölme çizilmeye devam edebilir; bu durumda üye alan bölmesi boş bırakılır. Violet UML'de arayüz eklerken yalnız iki giriş alanı çıkar: arayüzün adı ve metotları. Metotlar için ek bir gösterim yoktur, ama arayüzdeki metotların yalnız imza olarak tanımlandığı bilinmelidir.

`Customer` arayüzündeki `buy(Good, int)` metodu bir müşterinin bir üründen belirli sayıda satın alabileceğini anlatır. `Supplier` (tedarikçi ya da satıcı) arayüzünde belirli sayıda ürünü satmaya yönelik `sell` metodu vardır. `Friend` arayüzündeki `keep(Secret)` metodu ise arkadaşların sır saklamasına karşılık gelir. Bir insan hem müşteri, hem satıcı, hem de arkadaş olabilir; bu nedenle `Person` sınıfı bu üç rolü oynar, yani bu üç arayüzü gerçekler.

Bir sınıfın bir arayüzü gerçeklemesi, kalıtım okuna benzeyen (içi boş üçgen uçlu) ama kesikli çizgili bir okla gösterilir. Hoca bunu güzel bir düşünce olarak niteler: arayüz gerçekleme kalıtımdan daha hafif bir ilişkidir ve bu hafiflik kalıtımın düz çizgisi yerine kesikli çizgiyle anlatılmıştır.

## 3. Arayüzün Java'da yazılması

Slayttaki kod şöyledir (ekrandan, 00:10:00):

```java
public interface Customer {
    public void buy( Good aGood, int quantity );
}
public interface Supplier {
    public void sell( Good aGood, int quantity );
}
public interface Friend {
    public void keep( Secret aSecret );
}
public class Person implements Customer,
                    Supplier, Friend {
    public void buy( Good aGood, int quantity ) {
        //related code
    }
    public void sell (Good aGood, int quantity ) {
        // related code
    }
    public void keep( Secret aSecret ) {
        // related code
    }
}
```

Sınıf tanımlarken `class` yazılırken arayüz tanımlarken `interface` yazılır. Arayüz `public` tanımlanır; `private` tanımlamanın pratikte hiçbir anlamı yoktur, çünkü arayüz nesneye bir bakış açısı sağlar ve bu bakış açısı başka nesnelerin o nesneye bu açıdan erişebilmesi içindir. Arayüz gövdesindeki metotlar normal metot gibi yazılır, ama `abstract` gibi bir kelime kullanılmaz; imzadan sonra noktalı virgül konup bırakılır.

`Person` sınıfı yazılırken `implements` kelimesinden sonra gerçeklenen arayüzler virgülle ayrılarak yazılır. Tek arayüz gerçekleniyorsa virgül olmaz. `Person` üç arayüzü gerçeklediği için bu üç arayüzdeki metotların hepsini gövdeleriyle birlikte kodlamak zorundadır. Bir sınıf gerçeklediği bir arayüzdeki metodu yazmıyorsa o sınıf mutlaka soyut (abstract) yapılmalıdır.

Arayüz ne işe yarar sorusunun cevabı şöyle toparlanır: varlıkların sorumluluklarını gruplar, bir varlığa birden fazla bakış açısı kazandırır (bir sınıf kaç arayüz gerçekliyorsa o kadar bakış açısı vardır), kalıtımın ve çoklu kalıtımın yerine kullanılabilir. Bu ihtiyaçlardan biri ya da birkaçı varsa arayüz en uygun seçimdir.

## 4. Arayüz kuralları

Hoca kuralları şöyle sıralar:

- Bir sınıf gerçeklediği arayüzlerde tanımlı bütün metotların gövdesini kodlamak zorundadır.
- Arayüzlerde normal üye alan tanımlanamaz; yalnız `public`, `final` ve `static` üçü birden olan alanlar tanımlanabilir. Bir sabit (constant) tanımlanacaksa arayüzde tanımlanabilir.
- Arayüze yalnız `public` metotlar eklenir.
- Arayüzlerde constructor tanımlanmaz, zaten olamaz.
- Bir sınıf birden fazla arayüzü gerçekleyebilir.
- Adlandırma alışkanlığı olarak arayüz adları büyük `I` harfiyle başlatılır; örneğin `Customer` yerine `ICustomer`. Hocanın ders notlarında bu alışkanlık kullanılmamıştır, ama sektörde yaygındır.

> **Ek bilgi (derste anlatılmadı):** Java 8'den itibaren arayüzlere gövdeli `default` ve `static` metotlar, Java 9'dan itibaren de `private` yardımcı metotlar eklenebilir. Derste anlatılan "yalnız imza" kuralı arayüzün klasik ve hâlâ en yaygın kullanımını anlatır. Arayüz alanları ise belirtilmese bile kendiliğinden `public static final` sayılır.

## 5. Taşıt vergi sistemi örneği

Hoca arayüzlerin kurallarını ve avantajlarını göstermek için bir motorlu araç vergi sistemi düşünür. Kuralların gerçeği yansıtmadığını, arayüzü bütün yönleriyle anlatmak için uydurulduğunu belirtir. Slayttaki gereksinimler şunlardır (ekrandan, 00:20:00):

- Ticari ve şahsi araçların vergilendirilmesi farklıdır.
- Motosiklet, araba ve otobüs ticari araç olarak kaydedilebilir.
- Yalnız motosiklet ve araba şahsi araç olarak kaydedilebilir.
- Yalnız ticari araçların vergisi amortismanlı hesaplanabilir.
- Ticari olsun olmasın, farklı araçların (araba, otobüs vb.) vergi hesabı çok farklıdır.

Burada iki kırılım vardır: araç türü (üç çeşit) ve kullanım biçimi (ticari ya da şahsi, iki çeşit). En çok $3 \times 2 = 6$ farklı kural olabilirdi, ama otobüs şahsi araç olamadığından 5 durum kalır.

Ticari araçlarda amortisman (amortizing) devreye girer: araçların bir yıpranma payı vardır ve ticari bir aracın vergisi her yıl belli bir yıpranma oranı kadar düşer.

Tek kırılım olsaydı bir `Vehicle` soyut sınıfı ve altında `Motorcycle`, `Car`, `Bus` somut alt sınıfları yeterdi. İki kırılım olduğu için modelleme ancak arayüzlerle düzgün yapılabilir. Slayttaki tasarım şöyledir (ekrandan, 00:20:00):

```text
«interface» CommercialVehicle
+ getPlate() : String
+ calculateAmortizedTax( baseTax : double, currentYear : int ) : double
        ^ (Motorcycle, Car, Bus gerçekler)

«interface» PersonalVehicle
+ getPlate() : String
+ calculateTax( baseTax : double ) : double
        ^ (Motorcycle, Car gerçekler)
```

Bilgi sisteminde iki dizi olacaktır: biri ticari araçları, diğeri şahsi araçları tutar. Arayüzden nesne oluşturulamaz (soyut sınıftan oluşturulamadığı gibi), ama arayüzü gerçekleyen sınıflardan oluşturulan nesneler o arayüz türünün beklendiği her yere gönderilebilir. Her iki arayüzde de plakayı veren `getPlate()` vardır. `calculateAmortizedTax` iki parametre alır: temel olarak ödenmesi gereken vergi ve mevcut yıl. Aracın model yılından bu yana geçen süre kadar amortisman uygulanıp ödenecek vergi döndürülür. `calculateTax` ise yalnız temel vergiyi alır ve motor hacmi gibi ölçütlere göre amortismansız vergiyi döndürür.

Slayttaki ipucu şöyledir (ekrandan, 00:25:00): farklı araçların vergi hesabı benzer olsaydı, yani parametrize edilebilseydi, arayüzler yerine tek bir soyut üst sınıf kullanmak daha iyi bir seçim olurdu. Hoca bunu şöyle açar: vergiler arasında yalnız küçük bir çarpan farkı olsaydı bir soyut üst sınıf, altında motosiklet, araba, otobüs ve üst sınıfta "ticari mi" diye bir boolean alan iyi bir model olurdu. Ama hesapların parametreleri de mantığı da çok farklı olduğu için tek çözüm arayüzlerdir.

Arayüz kodları şöyledir (hocanın anlatımı ve slayttaki diyagrama göre):

```java
public interface CommercialVehicle {
    public String getPlate();
    public double calculateAmortizedTax( double baseTax, int currentYear );
}

public interface PersonalVehicle {
    public String getPlate();
    public double calculateTax( double baseTax );
}
```

Hoca burada tekrar uyarır: imzadan sonra noktalı virgül konup bırakılır; süslü parantez açıp kapamak sözdizimi hatasına, bu da derleme hatasına yol açar.

## 6. Car ve Bus sınıfları

### 6.1 Car

Araba hem ticari hem şahsi araç olabileceği için `implements CommercialVehicle, PersonalVehicle` bildirilir. Arabanın plakası, model yılı ve motor hacmi vardır; constructor üçünü de atar. Kod şöyledir (ekrandan, 01:25:00; sınıf başlığı ve getter satırları anlatımdan tamamlandı):

```java
public class Car implements CommercialVehicle, PersonalVehicle {
    private String plate;
    private int modelYear;
    private double engineVolume;

    public Car(String plate, int modelYear, double engineVolume) {
        this.plate = plate;
        this.modelYear = modelYear;
        this.engineVolume = engineVolume;
    }
    public double calculateTax( double baseTax ) {
        return baseTax * engineVolume;
    }
    public double calculateAmortizedTax( double baseTax, int currentYear ) {
        //Tax can be reduced %10 for each year as amortization
        int age = currentYear - modelYear;
        if( age < 10 )
            return baseTax * engineVolume * (1-age*0.10);
        return baseTax * engineVolume * 0.10;
    }
    public String getPlate() { return plate; }
    public int getModelYear() { return modelYear; }
    public double getEngineVolume() { return engineVolume; }
}
```

`calculateTax`'te kural, temel vergiyi motor hacmiyle çarpmaktır. `Car`, `PersonalVehicle` arayüzünü gerçeklediğini bildirdiği için bu metodu yazmak zorundadır; `CommercialVehicle` arayüzünü de gerçeklediği için `calculateAmortizedTax` gövdesini de yazmalıdır.

Amortisman kuralı şöyledir: her yıl aracın bedelinin %10'u kadar indirim yapılır. Ama 10 yıl sonra araç bedavaya gelmez; 10 yaş ve üstü için verginin sabit %10'u ödenir, daha aşağı inmez. Önce yaş, mevcut yıldan model yılı çıkarılarak bulunur. Yaş 10'dan küçükse çarpan $1{,}0 - \text{yaş} \times 0{,}10$ olur ve temel vergi × motor hacmi ile çarpılır. Yaş 10 ya da üstüyse temel vergi × motor hacmi × 0,10 döndürülür; yani şahsi araç olsaydı ödenecek verginin yalnız %10'u ödenir. Hoca, kodun zor olmadığını, zor olanın karmaşık problemi nasıl modelleyeceğini bilmek olduğunu vurgular.

### 6.2 Bus

Otobüs yalnız ticari araç olabilir; bu yüzden `implements CommercialVehicle` yazılır. Slayttaki kod (ekrandan, 00:30:00):

```java
package nyp07;
public class Bus implements CommercialVehicle {
    private String plate;
    private int modelYear;
    private double tonnage;
    public Bus(String plate, int modelYear, double tonnage) {
        this.plate = plate; this.modelYear = modelYear; this.tonnage = tonnage;
    }
    public double calculateAmortizedTax( double baseTax, int currentYear ) {
        double ratioTonnage, ratioAge;
        if( tonnage < 1.0 )
            ratioTonnage = 1.0;
        else if( tonnage < 5.0 )
            ratioTonnage = 1.2;
        else if( tonnage < 10.0 )
            ratioTonnage = 1.4;
        else
            ratioTonnage = 1.6;
        ratioAge = (currentYear - modelYear) * 0.05;
        if( ratioAge > 2.0 )
            ratioAge = 2.0;
        return baseTax * ratioTonnage * ratioAge;
    }
    public String getPlate() { return plate; }
    public int getModelYear() { return modelYear; }
    public double getEngineVolume() { return tonnage; }
}
```

Otobüste vergi motor hacmine değil tonaja göredir. Ayrıca doğrusal bir ilişki yoktur; kanunla belirli tonaj aralıkları için katsayı tanımlanmıştır: 1 tondan azsa 1,0; 1 ile 5 ton arası (5 hariç) 1,2; 5 ile 10 ton arası 1,4; daha ağırsa 1,6. Otobüslerde amortisman her yıl için %5'tir: yaş oranı (mevcut yıl − model yılı) × 0,05 olarak hesaplanır ve bir üst sınırla kırpılır. Sonuç temel vergi × tonaj oranı × yaş oranıdır. Hoca bunu "tonaj arttıkça vergi artıyor, yaş arttıkça vergi azalıyor" diye özetler.

> **Ders sonrası not:** Hoca yaş arttıkça verginin azaldığını söyledi, ama slayttaki kodda `ratioAge` yaşla birlikte büyür (yeni bir otobüste 0, yaşlandıkça 2,0'a kadar) ve doğrudan çarpan olarak kullanılır. Yani kod yazıldığı hâliyle vergiyi yaşla artırır ve sıfır yaşındaki otobüse sıfır vergi çıkarır. Anlatılan amaç büyük olasılıkla $1 - \text{yaş} \times 0{,}05$ gibi azalan ve bir alt sınırla kırpılan bir orandı. Ayrıca son getter `getEngineVolume` adını taşıdığı hâlde tonajı döndürür.

## 7. Araç kayıt sistemi tasarımı

Bu sınıfların nesneleri araç tescil sisteminde iki ayrı dizide tutulacaktır: ticari araçlar `commercialVehicles`, şahsi araçlar `personalVehicles` dizisinde. Slayttaki sınıf (ekrandan, 00:35:00):

```text
VehicleRegistrationSystem
- commercialVehicles[] : CommercialVehicle
- personalVehicles[] : PersonalVehicle
+ registerCommercialVehicle( CommercialVehicle ) : boolean
+ registerPersonalVehicle( PersonalVehicle ) : boolean
+ searchCommercialVehicle( plate : String ) : CommercialVehicle
+ searchPersonalVehicle( plate : String ) : PersonalVehicle
+ unregisterCommercialVehicle( plate : String ) : boolean
+ unregisterPersonalVehicle( plate : String ) : boolean
```

Slayttaki soru "Mantık nasıl olmalı, nasıl gerçeklemeliyiz?" sorusudur. `registerCommercialVehicle` metodu ticari aracı parametre olarak alır ve eklenebildiyse `true` döndürür. Bir eleman eklenemiyorsa bunun iki bilinen nedeni vardır: dizide yer kalmamıştır (kapasite artırılabilir, o ayrı konu) ya da araç zaten dizidedir. Bu örnekte bir neden daha vardır: bir araç aynı anda hem ticari hem şahsi kayıtlı olamaz. Ticari kullanımdan şahsi kullanıma geçmek isteyen araç önce ticari kaydından düşürülür, sonra şahsi kaydı açılır; tersi de böyledir.

Bu yüzden ticari kayıt sırasında aracın şahsi araçlar arasında da aranması gerekir. Ortak ve tekil tanımlayıcı plakadır. `searchPersonalVehicle(plate)` aracı bulursa onu, bulamazsa `null` döndürür. Ticari kayıt sırasında bu metot `null` dışında bir değer döndürürse araç şahsi olarak kayıtlıdır ve `false` döndürülür; hocanın deyişiyle "önce sen onu bir düşür". Bunun için `unregisterPersonalVehicle(plate)` vardır: aracı bulursa diziden siler ve `true`, bulamazsa `false` döndürür. Şahsi kayıt tarafında simetrik metotlar (`registerPersonalVehicle`, `searchCommercialVehicle`, `unregisterCommercialVehicle`) bulunur.

## 8. Arayüzler arasında kalıtım

Hoca ek bilgi olarak arayüzler arasında kalıtım ilişkisi tanımlanabildiğini söyler. Önceki tasarımda `getPlate()` iki arayüzde de tanımlıdır. Bunun yerine bir `Vehicle` arayüzü tanımlanıp `getPlate()` ona konabilir ve `CommercialVehicle` ile `PersonalVehicle` arayüzleri `Vehicle` arayüzünü extend edebilir. Bu durumda `getPlate()` tanımı iki alt arayüze aktarılır. `Bus` sınıfı `CommercialVehicle` arayüzünü gerçeklediğinde nesneye hem `Vehicle` hem `CommercialVehicle` arayüzü üzerinden erişilebilir; bu yüzden `Bus` hem `getPlate` hem `calculateAmortizedTax` metodunu yazmak zorundadır.

**Soru:** Bir sınıfın birden fazla arayüzü gerçeklemesinin sınırı yoktu; bir arayüz birden fazla arayüzü extend edebilir mi? **Cevap:** Hoca bir arayüzün birden fazla arayüzü extend edemeyeceğini, çoklu kalıtımın burada da geçerli olmadığını, bir arayüzün tek bir üst arayüzü olabileceğini söyledi.

> **Ders sonrası not:** Hoca bir arayüzün birden fazla arayüzü extend edemeyeceğini söyledi; doğrusu, Java'da bir arayüz birden fazla arayüzü extend edebilir. `interface PersonalVehicle extends Vehicle, Taxable { }` derlenir ve çalışır (ders sonrası `java` ile denendi). Çoklu kalıtım yasağı sınıflar içindir; arayüzlerde yalnız imza bulunduğu için aynı gerekçe geçerli değildir.

Hoca isterseniz `CommercialVehicle` arayüzünün de alt arayüzleri oluşturulabileceğini, ama bunun ona pek mantıklı gelmediğini ekler. Çok derin tutulmadıkça arayüzler arasında kalıtım kurulabilir.

Tartışmayı ilerleterek şunu sorar: ortak bir `Vehicle` arayüzü olsaydı ne değişirdi? `Vehicle` türünden tek bir dizi tanımlanıp hem ticari hem şahsi araçlar oraya konabilirdi. Ama bu dizideki nesnelerin yalnız `getPlate()` metodu çağrılabilir, vergi metotları çağrılamaz. Tip dönüşümü (typecasting) ile yapılabilir, ama ileride görülecek bu yöntemin pek tercih edilmediği söylenecektir. Bu yüzden üst arayüz olsa bile iki dizi tutmaya devam edilirdi. Belki `searchCommercialVehicle` ve `searchPersonalVehicle` yerine tek bir `searchVehicle` metodu yazılabilirdi, ama bu çok kolaylık sağlamaz. Kanun bir aracın ya ticari ya şahsi olmasını istediğinden kayıt defterlerini, yani dizileri ayırmak en mantıklısıdır. Sonuçta ortak üst arayüzün tek yararı `public String getPlate();` satırını iki yerde tekrar etmemektir; hoca bunun için koca bir arayüz tanımlamayı "attığın taş ürküttüğün kurbağaya değmez" diye değerlendirir. Alt arayüzler arasında birden fazla metot ortak olsaydı bu düşünülebilirdi.

## 9. Eclipse'te arayüz kurallarının gösterimi

Hoca `nyp07` paketindeki kodu açar: `PersonalVehicle`, `CommercialVehicle`, `Bus`, `Car` slayttakilerle aynıdır; motosiklet eklenmemiştir. Bu pakette ortak `Vehicle` arayüzü yoktur.

### 9.1 Vergi hesaplama denemesi

`TaxCalculationExample` sınıfındaki ilk deneme şöyledir (ekrandan, 00:45:00):

```java
Car aCar = new Car("34 A 4321", 2015, 1.8);
System.out.println("Arabanın vergisi: " + aCar.calculateTax(1000));
System.out.println("Arabanın ticari vergisi: " + aCar.calculateAmortizedTax(1000,2017));
```

Araba iki arayüzü de gerçeklediği için iki metot da çağrılabilir. Temel vergi 1000, mevcut yıl 2017 kabul edilir:

- Normal vergi: $1000 \times 1{,}8 = 1800$.
- Amortismanlı vergi: yaş $2017 - 2015 = 2$; çarpan $1 - 2 \times 0{,}10 = 0{,}8$; sonuç $1000 \times 1{,}8 \times 0{,}8 = 1440$.

Ekrandaki çıktı 1800,0 ve 1440,0'dır; hoca iki yıllık amortisman nedeniyle %20 daha az vergi çıktığını gösterir.

### 9.2 Gerçeklenmeyen metot hatası

`Car` sınıfında `calculateTax` metodu yorum satırına alınınca Eclipse sınıf üzerinde hata verir. Hata mesajı "inherited abstract method" ifadesiyle, `Car` sınıfının `PersonalVehicle.calculateTax` metodunu gerçeklemesi gerektiğini söyler. Arka planda ne soyut sınıf ne kalıtım vardır, ama arayüz bir soyut sınıf gibi düşünülebildiği için mesaj bu dille yazılmıştır. Önerilen hızlı düzeltmeler (quick fix) iki tanedir: gerçeklenmemiş metotları eklemek ya da `Car` sınıfını soyut yapmak. Asıl yapılması gereken metodu kodlamaktır.

### 9.3 Arayüz türünden değişken

Bir nesne kendi sınıfı türünden değil, arayüz türünden bir değişkene atanabilir (ekrandan, 01:00:00):

```java
PersonalVehicle pv = new Car("34 PV 34", 2016, 1.6);
```

Kalıtımda alt sınıf nesnesinin üst sınıf türünden bir değişkene atanabilmesi gibi, `Car` `PersonalVehicle` arayüzünü gerçeklediğini bildirdiği için bu atama yapılabilir. Artık bu değişken üzerinden yalnız `PersonalVehicle` arayüzündeki metotlar (`calculateTax`, `getPlate`) çağrılabilir. İçindeki nesne bir `Car` olsa ve `CommercialVehicle` arayüzünü de gerçeklese bile `calculateAmortizedTax` bu değişken üzerinden çağrılamaz; araca yalnız şahsi araç bakış açısından bakılır.

> **Ders sonrası not:** Ekranda bu değişken için `pv.calculateTax(2017)` çağrıldı ve 3227,2 sonucu çıktı (ekrandan, 01:05:00). Burada temel vergi yerine yıl verilmiştir ($2017 \times 1{,}6 = 3227{,}2$); hoca da biraz sonra "bu base tax, yıl değil aslında" dedi. Temel vergi 1000 verilseydi sonuç $1000 \times 1{,}6 = 1600$ olurdu. Ekrandaki `3227.2000000000003` biçimi ise kayan nokta yuvarlamasından gelir.

### 9.4 implements bildirimi zorunludur

Hoca `Car` sınıfının başlığından `implements PersonalVehicle` kısmını siler. `Car` sınıfında `calculateTax` ve `getPlate` hâlâ vardır, yani arayüzün bütün metotlarını gerçekleme şartı sağlanmaktadır. Buna rağmen `PersonalVehicle pv = new Car(...)` satırı artık hata verir. Sınıfın, o arayüz üzerinden erişime açık olduğunu `implements` kelimesiyle açıkça bildirmesi gerekir; ilgili metotları tanımlamak yetmez. Hoca bu noktayı uygulamayla göstermeyi tercih ettiğini söyler. (Ders sonrası denemede de aynı durum `incompatible types: Car cannot be converted to PersonalVehicle` derleme hatası verdi.)

### 9.5 Aynı nesne, iki farklı arayüz

Kodun devamında `CommercialVehicle` türünden değişkenlere bir `Car` ve bir `Bus` nesnesi atanır (ekrandan, 01:05:00):

```java
CommercialVehicle myCar = new Car("34 B 123", 2014, 1.6);
CommercialVehicle another = new Bus("06 OT 123", 2013, 1.5);
CommercialVehicle cm = aCar;
```

`Car` sınıfı iki arayüzü de gerçeklediği için aynı `aCar` nesnesi hem `PersonalVehicle` türünden bir değişkene hem `CommercialVehicle` türünden bir değişkene atanabilir. Hoca ikisinin vergisini ayrı ayrı yazdırır. `CommercialVehicle` türündeki değişken için `calculateTax` hata verir; o değişken üzerinden yalnız `calculateAmortizedTax` çağrılabilir. Ekrandaki çıktılar şöyledir (ekrandan, 01:10:00):

- `CM vergisi: 1440.0` (`cm` = `aCar`, amortismanlı vergi, temel vergi 1000, yıl 2017)
- `PVV vergisi: 1800.0` (aynı `aCar`, şahsi araç değişkeni üzerinden normal vergi)
- `Arabanın vergisi: 1120.0` (`myCar`: yaş $2017 - 2014 = 3$, çarpan $0{,}7$, $1000 \times 1{,}6 \times 0{,}7 = 1120$)

Tanımlanıp kullanılmayan `another` değişkeni için Eclipse yalnız bir uyarı (warning) verir. Böyle karıştırmak herhangi bir çalışma zamanı hatasına yol açmaz.

Bu bölümdeki bütün çıktılar ders sonrası aynı sınıflar `java` ile çalıştırılarak doğrulandı.

## 10. VehicleRegistrationSystem kodunun incelenmesi

Hoca bir sonraki konunun generic sınıflar ve generic veri yapıları olacağını, yıldız (çoka) ilişkileri dizilerle tutmak yerine listeler ve tablolarla tutmanın çok rahatlık sağlayacağını belirtir. Bu yüzden dizi kodunu fazla didiklemez; yalnız arayüzlerin iş mantığını nasıl etkilediğini gösterir. Kodun başındaki yorum da bunu söyler: "Class code is incomplete. No need to dwell on arrays as we will move on to generic lists and maps." (ekrandan, 01:10:00).

```java
public class VehicleRegistrationSystem {
    private CommercialVehicle commercialVehicles[];
    private PersonalVehicle personalVehicles[];
    private int commercialVehicleCount, personalVehicleCount;
    private int maxCapacity = 30;

    public VehicleRegistrationSystem() {
        commercialVehicles = new CommercialVehicle[maxCapacity];
        personalVehicles = new PersonalVehicle[maxCapacity];
    }
    ...
}
```

Dizide kaç eleman olduğunu tutmak için sayaçlar vardır; en büyük kapasite 30'dur. Constructor'da dizilere yer ayırmayı unutmamak gerekir.

### 10.1 Arama ve kayıt metotları

İlk hâliyle `searchCommercialVehicle` for-each döngüsüyle bütün diziyi dolaşır, her elemanın plakasını büyük-küçük harf ayrımı yapmadan (`equalsIgnoreCase`) verilen plakayla karşılaştırır, eşitse aracı döndürür; döngü bitip bulunamazsa `null` döndürür (ekrandan, 01:15:00).

`registerCommercialVehicle` ise şöyledir (ekrandan, 01:20:00):

```java
public boolean registerCommercialVehicle( CommercialVehicle vehicle ) {
    if( searchCommercialVehicle(vehicle.getPlate()) != null
            || searchPersonalVehicle(vehicle.getPlate()) != null
            || commercialVehicleCount == commercialVehicles.length )
        return false;
    commercialVehicles[commercialVehicleCount] = vehicle;
    commercialVehicleCount++;
    return true;
}
```

Gelen aracın plakası ticari araçlar arasında aranır. `null` dışında bir şey dönerse, aynı plakadan iki araç olamayacağına göre bu araç zaten kayıtlıdır. `!= null` ifadesi `true` olur; koşullar "veya" ile bağlı olduğundan diğer bileşenlere bakılmaksızın `if` içine girilir ve `false` döndürülür. Araç ticari olarak kayıtlı değilse şahsi araçlar arasında aranır; orada bulunursa yine `false` döner. Hoca orijinal kodda dizi doluluk kontrolünün unutulduğunu fark edip üçüncü koşulu ders sırasında ekler. `maxCapacity` yerine `commercialVehicles.length` yazmayı tercih eder, çünkü ileride kapasite artırma söz konusu olabilir. Doluluk kontrolü şahsi araç kaydına da `personalVehicleCount == personalVehicles.length` olarak eklenir. Kayıt başarılıysa araç sayaç konumuna yerleştirilir ve sayaç bir artırılır.

### 10.2 Test ve NullPointerException

Hoca küçük bir test yazar: bir `VehicleRegistrationSystem` nesnesi oluşturulur, `aCar` önce ticari araç olarak kaydedilir (sonucun `true` olması beklenir, "Test 1"), sonra aynı araç şahsi araç olarak kaydedilmeye çalışılır (sonucun `false` olması beklenir, "Test 2").

Çalıştırınca `NullPointerException` oluşur. Hata, `searchCommercialVehicle` içinde `getPlate()` çağrılan satırdan gelir (ekrandan, 01:20:00). Hoca nedeni şöyle açıklar: for-each döngüsü dizinin bütün uzunluğu boyunca dolaşır. Sistemde henüz hiç ticari araç kayıtlı değilken bile döngü ilk hücreye bakar; hücre boştur (`null`) ve `null` üzerinde `getPlate()` çağrılınca hata oluşur. Burada for-each yerine dolu eleman sayısına kadar dönen normal `for` döngüsü kullanılmalıdır:

```java
public CommercialVehicle searchCommercialVehicle( String plate ) {
    for( int i = 0; i < commercialVehicleCount; i++ )
        if( commercialVehicles[i].getPlate().equalsIgnoreCase(plate) )
            return commercialVehicles[i];
    return null;
}
```

Aynı düzeltme `searchPersonalVehicle` için de `personalVehicleCount` ile yapılır. Hoca, dizi yerine örneğin bağlı liste (linked list) kullanılsaydı listenin sonu belli olacağı için böyle bir şeye gerek kalmayacağını, bunun hem listelerin bir avantajı hem de dizi kullanırken dikkat edilmesi gereken bir nokta olduğunu vurgular. Düzeltmeden sonra çıktı "Test 1 OK" ve "Test 2 OK" olur (ekrandan, 01:25:00): sorun yalnız dizide aramayla ilgiliydi, iş mantığı doğruydu.

> **Hocanın vurgusu:** Dizide for-each ile arama yaparken dizinin tamamı dolaşılır; dolu olmayan hücreler `null` olduğu için eleman sayısına kadar indeksli döngü kullanılmalıdır.

## 11. Üst arayüzlü sürüm (nyp07b)

`nyp07b` paketinde ortak `Vehicle` arayüzü tanımlanmıştır. `public interface CommercialVehicle extends Vehicle` arayüzünde yalnız `calculateAmortizedTax`, `public interface PersonalVehicle extends Vehicle` arayüzünde yalnız `calculateTax` kalmıştır; `getPlate()` `Vehicle` arayüzündedir.

`Car` sınıfı `CommercialVehicle` ve `PersonalVehicle` arayüzlerini gerçekler; arayüzler arasındaki kalıtım nedeniyle `Vehicle` arayüzünü de gerçeklemiş olur ve onun kuralına uymak zorundadır. Hoca `Car` içindeki `getPlate` metodunu yorum satırına alır (ekrandan, 01:25:00) ve sınıf üzerinde hata çıkar: `getPlate` mutlaka gerçeklenmelidir. Bu, `getPlate` tanımının üst arayüzden kalıtımla aktarıldığının kanıtıdır.

## 12. Hem kalıtım alan hem arayüz gerçekleyen sınıf

Bir sınıf hem bir sınıftan kalıtım alıp hem de bir arayüz gerçekleyebilir. Hoca bunu `nyp07c` paketinde soyut adlarla canlı yazar:

- `AnInterface` adlı bir arayüz, içinde `public void aMethod();`.
- `ABaseClass` adlı bir üst sınıf: bir `ID` üye alanı, onu alan bir constructor (Eclipse'in "Generate Constructor using Fields" seçeneğiyle) ve bir getter (Generate Getters and Setters).
- `ASubClass` adlı bir alt sınıf.

Alt sınıf başlığına `extends ABaseClass implements AnInterface` yazılınca Eclipse iki hata gösterir: üst sınıfın constructor'ı `super` ile çağrılmalıdır ve `aMethod` gerçeklenmelidir. İkisi de giderilince kod şöyledir (ekrandan, 01:30:00):

```java
package nyp07c;

public class ASubClass extends ABaseClass implements AnInterface {
    public ASubClass( int ID ) {
        super(ID);
    }
    public void aMethod() {
        System.out.println("aMethod of ASubClass");
    }
}
```

Metodun gövdesini boş bırakmak derleme hatasını gidermeye yeter, ama boş metodun pek anlamı olmadığı için bir yazdırma satırı eklenmiştir. Başka arayüzler de varsa `implements` kısmına virgülle eklenebilir.

Hoca aynı yapıyı Violet UML'de de çizer: `«interface» AnInterface` (yalnız iki giriş alanı olduğu hâlde üç bölme çizilir), `ABaseClass` (ID alanı, constructor, getter) ve `ASubClass` (int parametreli constructor, `aMethod`). Kalıtım oku ile gerçekleme okunun aynı kenardan çıkıp bir kısmı düz bir kısmı kesikli görünmesini beğenmez; gerçekleme okunu ayrı bir kenardan çıkarır ya da okun yönlenmesini önce yatay sonra dikey olacak şekilde ayarlar. Alt sınıfta arayüz metodunun ve üst sınıf constructor'ını çağıran constructor'ın diyagramda da gösterilmesi gerektiğini söyler, çünkü ikisi de kodda bulunmak zorundadır. Böylece hem koddan UML sınıf şemasına hem de şemadan koda geçiş gösterilmiş olur.

## 13. UML'de override gösterimi

Hoca kalıtım haftasında söylemeyi atladığı bir noktayı ekler ve `Person`, `Employee`, `Manager` örneğinin slaytına döner (ekrandan, 01:35:00):

```text
Person: - name : String; + Person(String); + getName() : String
   ^
Employee: - salary : int; + Employee(name, salary); + getSalary() : int; + setSalary(int)
   ^
Manager: - bonus : int; + Manager(name, salary); + setBonus(int); + getSalary() : int
```

`Employee` sınıfındaki `getSalary()` metodu `Manager` sınıfında override edilmiştir. `Manager` kutusunda `getSalary()` gösterilmeseydi, metodun üst sınıftan olduğu gibi kalıtıldığı, yani override edilmediği anlaşılırdı. Bir alt sınıfta üst sınıfta zaten olan bir metot açıkça yeniden yazılmışsa bu, o metodun override edildiği anlamına gelir. UML'de bu bir vurgulama aracıdır.

Hoca ayrıca bu kayıt örneğinde soyut sınıflarla bir tasarım denenebileceğini, ama metot gövdeleri çok farklı olduğu için mümkün olmadığını, mümkün olmayanı zorlamanın başarısız olacağını tekrarlar.

## 14. Basit (primitive) enum

Enum (İngilizce okunuşuyla "inam") kavramı Yapısal Programlama dersinden de bilinir. Bazen bir değişkenin yalnız belirli bir değer kümesinden değer almasını isteriz. Slayttaki örnek (ekrandan, 01:40:00): bir dükkân dört boyda pizza satıyor: küçük, orta, büyük, çok büyük; başka boy yoktur.

Pizza boyunu bellekte nasıl tutalım? Bir tamsayı alan konabilir (dört bayta gerek yok, `short` da olur): 1 small, 2 medium, 3 large, 4 extra large. Ya da uluslararası kısaltmalarla `char` türünden S, M, L, X kullanılabilir. Ama bu tasarım hataya açıktır: `int` türünde bir alana 5 ya da −3 atanabilir. Setter'da kontrol yapılabilir, ama yanlış değerde ne olacağına (mevcut değer mi korunacak, varsayılan 1'e mi çekilecek) karar vermek gerekir; bu ekstra kod ve ekstra tutarlılık kontrolü demektir. Bunun yerine birçok dilde enum yapıları vardır. Tek bir basit bilgi tutuluyorsa basit (primitive) enum kullanılır; Java'da enum aslında ilkel bir tür değildir, ayrıntısı birazdan görülecektir.

```java
public enum Size {
    SMALL, MEDIUM, LARGE, EXTRA_LARGE;
}
```

```java
Size s = Size.MEDIUM;
```

Alışkanlık olarak enum değerleri büyük harfle yazılır. `Size` türünden bir değişken yalnız bu dört değerden birini alabilir. `s = 5` gibi bir atama hata verir. Değerler büyük-küçük harfe duyarlıdır: `Size.Medium` yazılamaz; yalnız `MEDIUM` ya da yalnız `M` de yazılamaz; mutlaka `EnumAdı.DEĞER` biçimi kullanılır. Slaytın son maddesi şunu söyler: aslında `Size` adında bir sınıf tanımlanmış ve bu sınıftan yalnız dört statik nesne oluşturulabilmesi zorlanmıştır.

## 15. Enum sınıfları

Java'da enum'lar ilkel olmak zorunda değildir; enum aslında bir sınıf tanımıdır. Slayttaki maddeler (ekrandan, 01:45:00):

- Öğrenilen basit enum aslında bir sınıf tanımıdır.
- Enum'un her üyesi o sınıfın bir nesnesidir.
- Tanımlı olanlar dışında enum'un başka üyesi olamaz.
- Bir enum türü, diğer sınıflar gibi üye alan, metot ve constructor içerebilir.
- Enum sınıfının constructor'ı private olmalıdır.

Constructor'ın private olmasının nedeni enum'un mantığıdır: yalnız belirli bir değer kümesinden seçim yapılabilmelidir. Constructor serbestçe çağrılabilseydi kümenin dışında yeni bir nesne oluşturulabilirdi. Ek bir kural daha vardır: enum nesnelerinin değerleri gövdenin ilk satırında tanımlanmalıdır.

> **Ek bilgi (derste anlatılmadı):** Enum constructor'ı erişim belirteci yazılmadan da tanımlanabilir; bu durumda kendiliğinden private sayılır. `public` ya da `protected` yazmak ise derleme hatasıdır (ders sonrası denemede "modifier public not allowed here" hatası alındı).

### 15.1 Tariff örneği

Bir internet servis sağlayıcısının şubesi düşünülür. Sistemde üç paket vardır: NETFREE, NET4 ve NET6; başka paket yoktur. Abonelik yapılırken yalnız bu üç tarifeden biri seçilebilmeli, sisteme başka tarife girilememelidir. Slayttaki kod (ekrandan, 01:45:00):

```java
package nyp08;
public enum Tariff {
    NETFREE(0,4,60), NET4(4,8,30), NET6(6,8,40);
    private int quota, speed, fee;
    private Tariff( int quota, int speed, int fee ) {
        this.quota = quota; this.speed = speed; this.fee = fee;
    }
    public int getQuota() { return quota; }
    public int getSpeed() { return speed; }
    public int getFee() { return fee; }
}
```

`class` yerine `enum` yazılır. Gövdenin ilk işi, basit enum'da olduğu gibi, nesnelerin alacağı değerleri yazmaktır. Ama bunlar birer nesnedir ve ilk satırdaki parantezler aslında constructor çağrılarıdır: `NETFREE(0,4,60)` constructor'ın birinci parametresine 0, ikincisine 4, üçüncüsüne 60 ver demektir. NET4 için 4, 8, 30; NET6 için 6, 8, 40 verilir ve satır noktalı virgülle biter. Slaytta kırmızıyla "This must be the first line of code!" yazılıdır; bu satır daha aşağı alınamaz.

Ardından normal bir sınıftaki gibi üç üye alan gelir: `quota` (kota; kota yoksa 0), `speed` (megabit cinsinden hız) ve `fee` (ücret). Constructor private olmak zorundadır, üç parametreyi alıp alanlara atar. Üç getter metot vardır. Böylece `Tariff` sınıfından yalnız üç farklı nesne olabilir ve alanlarının değerleri bellidir.

### 15.2 Enum'un UML gösterimi

Enum sınıfı çizilirken ad bölmesine önce `«enum»` stereotipi, sonra enum'un adı yazılır. Koddaki ilk satır (değer tanımları) üye alan bölmesinin ilk satırına yazılır; diğer üye alanlar normal biçimde gelir. Constructor ve diğer metotlar UML'de normal çizildiği gibi çizilir; constructor private olmak zorunda olduğundan diyagramda da private gösterilir.

### 15.3 Person, Subscription, Tariff tasarımı

Kişiler abone edilecektir; bu yüzden bir `Person` sınıfı vardır. Ama kişi tarifeyle doğrudan ilişkilendirilmez, çünkü abonelik belirli bir tarih aralığında olabilir. Bu yüzden `Person` bir `Subscription` nesnesiyle, `Subscription` da bir `Tariff` ile ilişkilidir. Henüz tarife satılmamış aday müşterilerin ya da aboneliği bitmiş ama kaydı silinmek istenmeyen müşterilerin (borcunu ödememiş olabilir ya da ileride yeni tarifeler için aranabilir) kaydı da tutulacaksa `Person`'dan `Subscription`'a ilişkide `Subscription` tarafına `0..1` yazılabilirdi. Hoca konu enum olduğu için bu ayrıntıya girmez.

## 16. Tariff, Subscription, Person örneğinin çalıştırılması

Slayttaki kullanım örneği şöyledir (ekrandan, 01:50:00; kişilere verilen adlar burada genel adlarla değiştirilmiştir):

```java
public class Test {
    public static void main(String[] args) {
        Tariff tariff4 = Tariff.NET4;
        Person a = new Person("Kişi A");
        a.subscribeTo(tariff4);
        Person b = new Person("Kişi B");
        b.subscribeTo(Tariff.NETFREE);
        System.out.println(a);
        System.out.println(b);
    }
}
```

`tariff4` bir nesne işaretçisinin adıdır; ne konursa konsun alabileceği değer yalnız enum içinde tanımlı değerlerden biridir, burada `Tariff.NET4`. İkinci kişi abone edilirken geçici bir değişkene gerek görülmeden doğrudan `Tariff.NETFREE` verilmiştir.

### 16.1 Kodun ayrıntıları

Eclipse'teki `nyp08` paketinde `Tariff` biraz geliştirilmiştir: tarifeye zam gelebileceği için `fee` alanına bir setter eklenmiştir. Bu yeni bir nesne eklemek değildir, yalnız mevcut nesnenin `fee` alanı değişir; bu yüzden basit bir setter yeterlidir. Ayrıca `quota`, `speed` ve `fee` değerlerini yazan bir `toString` metodu eklenmiştir.

`Subscription` sınıfı bir tarifeyle ilişkilidir. Başlangıç zamanı için Java'nın `java.util` paketindeki `Date` sınıfı kullanılır; hoca bu sınıfın tarih ve saati birlikte modellediğini, farklı takvimleri desteklediğini ve ileride ayrıca ele alınacağını söyler. Constructor'da parametreyle gelen tarife üye alana atanır ve başlangıç olarak o anı gösteren bir `Date` nesnesi oluşturulur. `toString` önce tarifenin `toString`'ini, sonra başlangıç zamanını verir.

`Person` sınıfının kodu (ekrandan, 01:55:00):

```java
private String name;
private Subscription subscription;

public Person(String name) {
    this.name = name;
}

public String getName() {
    return name;
}

public String toString( ) {
    return name + ", " + subscription;
}

public void subscribeTo(Tariff aTariff) {
    subscription = new Subscription(aTariff);
}
```

`toString` içinde `subscription` bir string ile birleştirildiğinde sanal makine onun `toString` metodunu kendiliğinden çağırır; `.toString()` yazılsa da yazılmasa da aynıdır. `Subscription` da `toString`'i override ettiği için anlamlı bir metin gelir: kişinin adı, ardından aboneliği ve aboneliğin içinde tarifesi yazılır. `subscribeTo` metodu parametreyle gelen tarifeyle yeni bir `Subscription` oluşturur.

`Tariff` ve `Subscription` sınıflarının `toString` metotları karede görünmedi; ekran çıktısının biçimine göre şöyle kurulabilir (ders sonrası çıktıdan kuruldu ve `java` ile denendi):

```java
// Tariff içinde
public void setFee(int fee) { this.fee = fee; }
public String toString() {
    return "Tariff: Quota: " + quota + ", speed: " + speed + ", fee: " + fee;
}

// Subscription
public class Subscription {
    private Tariff tariff;
    private Date begin;
    public Subscription(Tariff aTariff) {
        tariff = aTariff;
        begin = new Date();
    }
    public String toString() { return tariff + ", begin: " + begin; }
}
```

### 16.2 Zam denemesi

İlk çalıştırmada NET4'e abone olan kişi için kota 4, hız 8, ücret 30; NETFREE abonesi için kota 0, hız 4, ücret 60 yazılır. Başlangıç zamanının yanında "TRT" ifadesi görünür; hoca bunun büyük olasılıkla Türkiye saat dilimi anlamına geldiğini söyler.

Hoca sonra zamın abonelere yansıdığını gösterir (ekrandan, 02:00:00). İki kişi `tariff4` değişkeni üzerinden NET4'e abone edilir. Zam iki yolla yapılabilir: `tariff4` işaretçisi üzerinden `tariff4.setFee(35);` ya da doğrudan enum değeri üzerinden `Tariff.NET4.setFee(40);`. Hoca birini yorum satırına alıp diğerini çalıştırır: birinci durumda iki NET4 abonesinin ücreti 35, ikinci durumda 40 görünür. Üçüncü kişi `Tariff tariff5 = Tariff.NETFREE;` üzerinden NETFREE'ye abone edilmiştir; NETFREE'de değişiklik yapılmadığı için onun ücreti 60 olarak kalır. Ekrandaki çıktı (kişi adları çıkarılmıştır):

```text
..., Tariff: Quota: 4, speed: 8, fee: 40, begin: Thu Apr 22 10:58:58 TRT 2021
..., Tariff: Quota: 4, speed: 8, fee: 40, begin: Thu Apr 22 10:58:58 TRT 2021
..., Tariff: Quota: 0, speed: 4, fee: 60, begin: Thu Apr 22 10:58:58 TRT 2021
```

Sonuçta enum da bir sınıf ve nesne tanımıdır. Enum içinde olası nesne değerleri tanımlanır; bu nesnelerin constructor'ı, getter ve setter metotları olur ve "her nesne bir bireydir" ilkesine göre davranmaya devam ederler. Tek fark, `Tariff` sınıfından yalnız tanımlı sayıda nesne olabilmesidir. Bu nesneler istendiği kadar farklı işaretçiye atanabilir, ama aynı değeri gösteren bütün işaretçiler bellekte aynı yeri gösterir.

**Soru:** Bu enum'da üç tarife tanımlı; program içinden kaç tarife olduğuna ulaşmanın bir yolu var mı? **Cevap:** Hoca doğrudan basit bir yol olmadığını, dizide `.length` ile uzunluk alındığı gibi bir yöntemin bulunmadığını, ama Java Reflection API ile yapılabileceğini söyledi. Reflection, bir nesnenin yalnız bytecode'undan (`.class` dosyasından) yola çıkarak hangi üye alanları ve metotları olduğunu, bir kalıtım ilişkisinde olup olmadığını incelemeye, metotlara işaretçi alıp onları belirli parametrelerle çalıştırmaya yarayan yeteneklerdir. Buna ek olarak üçüncü taraf, açık kaynaklı bytecode analiz kütüphaneleri de vardır. Hoca konuyu merak edenlere Core Java kitabının ciltlerini önerdi.

> **Ders sonrası not:** Reflection'a gerek yoktur. Derleyici her enum için statik bir `values()` metodu üretir ve bu metot bütün değerleri tanım sırasıyla bir dizi olarak döndürür. `Tariff.values().length` doğrudan 3 verir (ders sonrası `java` ile denendi).

## Örnek Sorular

### Soru 1: Vergi gereksinimini modellemek

(ekrandan, 00:20:00) Taşıtların vergi hesabıyla ilgili şu gereksinim veriliyor: ticari ve şahsi araçların vergilendirmesi farklıdır; motosiklet, araba ve otobüs ticari araç olarak kaydedilebilir; yalnız motosiklet ve araba şahsi araç olarak kaydedilebilir; yalnız ticari araçların vergisi amortismanlı hesaplanabilir; ticari olsun olmasın farklı araçların vergi hesabı çok farklıdır. Bu gereksinim nasıl modellenir?

> **Çözüm (derste verildi):** İki kırılım (araç türü ve kullanım biçimi) olduğu için iki arayüz tanımlanır: `CommercialVehicle` (`getPlate()`, `calculateAmortizedTax(baseTax, currentYear)`) ve `PersonalVehicle` (`getPlate()`, `calculateTax(baseTax)`). `Motorcycle` ve `Car` iki arayüzü, `Bus` yalnız `CommercialVehicle` arayüzünü gerçekler. Hesaplar tek bir çarpanla parametrize edilebilseydi tek bir soyut üst sınıf daha iyi olurdu (ekrandan, 00:25:00).

### Soru 2: Kayıt sisteminin mantığı

(ekrandan, 00:35:00) `VehicleRegistrationSystem` sınıfında ticari ve şahsi araçlar iki ayrı dizide tutuluyor. `register...`, `search...` ve `unregister...` metotlarının mantığı nasıl olmalı?

> **Çözüm (derste verildi):** Kayıt metodu şu durumlardan biri varsa `false` döndürür: plaka ticari dizide kayıtlı, plaka şahsi dizide kayıtlı, dizi dolu. Aksi hâlde araç sayaç konumuna eklenir, sayaç artırılır ve `true` döner. Arama metodu dolu eleman sayısına kadar dönen bir döngüyle plakayı `equalsIgnoreCase` ile karşılaştırır, bulamazsa `null` döndürür. Kullanım biçimi değişecek araç önce `unregister...` ile eski kaydından düşürülür. Kod 10. bölümdedir.

### Soru 3: Bir eleman neden eklenemeyebilir?

(derste sözlü, 00:32:37) Bir diziye eleman eklenmeye çalışıldığında ekleme neden başarısız olabilir?

> **Çözüm (derste verildi):** Bilinen iki neden vardır: dizide yer kalmamıştır ya da eleman zaten dizidedir. Bu örnekte bir üçüncü neden de vardır: araç öbür dizide (ticari ise şahsi, şahsi ise ticari) kayıtlıdır.

### Soru 4: Arayüzler birden fazla arayüzü extend edebilir mi?

(derste sözlü, 00:37:38) Bir sınıf birden fazla arayüzü gerçekleyebiliyor. Bir arayüz birden fazla arayüzü extend edebilir mi?

> **Çözüm:** Hoca derste "edemez" dedi. Doğrusu, Java'da edebilir: `interface PersonalVehicle extends Vehicle, Taxable { }` geçerlidir ve ders sonrası `java` ile derlenip çalıştırıldı. Bir sınıf ise yalnız tek bir sınıfı extend edebilir.

### Soru 5: Enum'daki değer sayısı

(derste sözlü, 02:00:59) `Tariff` enum'unda üç tarife tanımlı. Program içinden kaç tarife tanımlı olduğu öğrenilebilir mi?

> **Çözüm:** Hoca Reflection API ile yapılabileceğini söyledi. Daha basit yol, derleyicinin her enum için ürettiği `values()` metodudur: `Tariff.values().length` 3 döndürür (ders sonrası `java` ile denendi).

## Dersin Toparlaması

Bu derste arayüzün, kalıtımın ağırlığına ve çoklu kalıtımın yasak olmasına karşı geliştirilmiş daha hafif bir araç olduğu görüldü. Arayüz, üye alanı olmayan bir soyut sınıf gibi düşünülebilir: metot imzalarından oluşur ve bir varlığa bir rol ya da bakış açısı kazandırır. Gerçekleyen sınıf bütün metotları yazmak zorundadır, yoksa soyut olmalıdır. Taşıt vergi sistemi örneği, iki ayrı kırılımın ancak arayüzlerle düzgün modellenebildiğini gösterdi. Eclipse'te aynı nesneye farklı arayüz türlerinden bakıldığında yalnız o arayüzün metotlarına erişilebildiği ve `implements` bildirimi olmadan metotlar yazılmış olsa bile arayüz türüne atama yapılamadığı uygulamalı olarak gösterildi. Kayıt sistemi kodu üzerinden de dizide for-each ile aramanın null hücrelerde nasıl `NullPointerException` doğurduğu görüldü. Arayüzler arasında kalıtım, bir sınıfın aynı anda `extends` ve `implements` kullanması ve UML'de override gösterimi de ele alındı.

Dersin son bölümünde enum'lar işlendi: basit enum bir değişkeni sabit bir değer kümesine bağlar; Java'da enum aslında bir sınıftır, her değeri bir nesnedir, alan, metot ve private constructor içerebilir ve değerler gövdenin ilk satırında tanımlanır. Tariff örneğinde bir enum değerinin bütün işaretçilerden aynı nesne olarak görüldüğü, bu yüzden ücret değişikliğinin o tarifeye abone herkese yansıdığı gösterildi. Hoca bir sonraki konunun generic sınıflar ve generic veri yapıları (listeler, tablolar) olacağını, dizilerle yapılan yıldız ilişkisi kodlamasının bunlarla çok kolaylaşacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
