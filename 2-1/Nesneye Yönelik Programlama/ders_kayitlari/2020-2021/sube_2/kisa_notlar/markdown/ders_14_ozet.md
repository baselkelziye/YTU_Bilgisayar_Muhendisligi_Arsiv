# Ders 14 Çalışma Özeti

## Genel Konular

- Arayüz (interface) kavramı ve neden ortaya çıktığı
  - Kalıtım güçlü ama ağır bir ilişkidir ve yanlış kullanılabilir; Java çoklu kalıtımı haklı nedenlerle desteklemez. Arayüz, kalıtımdan daha hafif bir ilişki kurmak ve çoklu kalıtımın sakıncaları olmadan bazı avantajlarını sağlamak için kullanılır.
  - Arayüz, üye alanı olmayan bir soyut sınıf gibi düşünülebilir. Bir isimlendirilmiş metot imzaları kümesidir; bir varlığın sorumluluklarının bir alt kümesini, yani bir rolünü ya da bakış açısını tanımlar.
  - Bir sınıf bir arayüzü gerçekler (implementation). Bir sınıf birden fazla arayüzü gerçekleyebilir; arayüzlerde yalnız imza olduğu için elmas (diamond) kalıtım sorunları doğmaz.
- UML'de arayüz gösterimi
  - Sınıf kutusunun ad bölmesine `«interface»` stereotipi ve arayüzün adı yazılır. Üye alan bölmesi boş bırakılır (Violet UML'de arayüz için yalnız ad ve metot alanı girilir).
  - Arayüz gerçekleme, ucu içi boş üçgen olan kesikli çizgili okla gösterilir. Kesikli çizgi, ilişkinin kalıtımdan (düz çizgi) daha hafif olduğunu anlatır.
  - Örnek (ekrandan, 00:10:00): `Customer`, `Supplier` ve `Friend` arayüzlerini gerçekleyen bir `Person` sınıfı.
- Java'da arayüz yazımı
  - `public interface Customer { public void buy(Good aGood, int quantity); }` biçiminde tanımlanır; metot imzasından sonra noktalı virgül konur, gövde yazılmaz, `abstract` kelimesi yazılmaz (ekrandan, 00:10:00).
  - Sınıf `public class Person implements Customer, Supplier, Friend { ... }` diye bildirilir; birden fazla arayüz virgülle ayrılır.
- Arayüz kuralları
  - Gerçekleyen sınıf, arayüzlerdeki bütün metotların gövdesini yazmak zorundadır; yazmıyorsa soyut (abstract) yapılmalıdır.
  - Arayüze normal üye alan eklenemez; yalnız `public final static` (sabit) alanlar eklenebilir.
  - Arayüzde yalnız public metotlar bulunur; constructor tanımlanamaz.
  - Arayüzden nesne oluşturulamaz, ama arayüzü gerçekleyen sınıfın nesnesi arayüz türünden bir değişkene atanabilir.
  - Adlandırma alışkanlığı: arayüz adları büyük `I` harfiyle başlatılır (örneğin `ICustomer`).
- Taşıt vergi sistemi örneği (iki kırılımlı modelleme)
  - Araç türü (motosiklet, araba, otobüs) ve kullanım biçimi (ticari ya da şahsi) olmak üzere iki ayrı kırılım vardır. Otobüs şahsi araç olamaz; yalnız ticari araçların vergisi amortismanlı hesaplanabilir; vergi hesabı araç türüne göre çok farklıdır.
  - Çözüm: `CommercialVehicle` (`getPlate()`, `calculateAmortizedTax(baseTax, currentYear)`) ve `PersonalVehicle` (`getPlate()`, `calculateTax(baseTax)`) arayüzleri. `Car` ikisini, `Bus` yalnız `CommercialVehicle` arayüzünü gerçekler (ekrandan, 00:20:00).
  - Hesaplar farklı olmasaydı, yani tek bir çarpanla parametrize edilebilseydi, bir soyut üst sınıf ve bir boolean "ticari mi" alanı daha iyi bir seçim olurdu (ekrandan, 00:25:00).
- `Car` ve `Bus` sınıflarının vergi hesabı
  - `Car.calculateTax`: temel vergi × motor hacmi. `Car.calculateAmortizedTax`: yaş 10'dan küçükse temel vergi × motor hacmi × (1 − yaş × 0,10), değilse temel vergi × motor hacmi × 0,10.
  - `Bus.calculateAmortizedTax`: tonaj aralığına göre oran (1 tondan az 1,0; 5'ten az 1,2; 10'dan az 1,4; diğer 1,6), yaş oranı (mevcut yıl − model yılı) × 0,05, en çok 2,0; sonuç temel vergi × tonaj oranı × yaş oranı (ekrandan, 00:30:00).
  - Ders sonrası not: Hoca "yaş arttıkça vergi azalır" dedi, ama slayttaki kodda yaş oranı yaşla birlikte büyüyor (yeni bir otobüste 0, eski otobüste 2,0'a kadar); yani kod yazıldığı hâliyle vergiyi yaşla artırıyor. Anlatılan amaç büyük olasılıkla $1 - \text{yaş} \times 0{,}05$ gibi azalan bir orandı.
- Araç kayıt sistemi (`VehicleRegistrationSystem`)
  - Ticari ve şahsi araçlar iki ayrı dizide tutulur. Metotlar: `registerCommercialVehicle`, `registerPersonalVehicle`, `searchCommercialVehicle(plate)`, `searchPersonalVehicle(plate)`, `unregisterCommercialVehicle(plate)`, `unregisterPersonalVehicle(plate)` (ekrandan, 00:35:00).
  - Bir araç aynı anda hem ticari hem şahsi kayıtlı olamaz; kayıt sırasında plaka iki dizide de aranır, dizi doluysa da `false` döner.
- Arayüzler arasında kalıtım
  - Ortak `getPlate()` metodu bir `Vehicle` arayüzüne konup `CommercialVehicle extends Vehicle` ve `PersonalVehicle extends Vehicle` yazılabilir. Gerçekleyen sınıf üst arayüzün metodunu da yazmak zorundadır.
  - Ders sonrası not: Bir öğrencinin sorusu üzerine hoca bir arayüzün birden fazla arayüzü extend edemeyeceğini söyledi. Java'da bu mümkündür: `interface PersonalVehicle extends Vehicle, Taxable { }` derlenir ve çalışır (ders sonrası `java` ile denendi). Çoklu kalıtım yasağı yalnız sınıflar içindir.
- Bir sınıfın hem kalıtım alıp hem arayüz gerçeklemesi
  - `public class ASubClass extends ABaseClass implements AnInterface` (ekrandan, 01:30:00); alt sınıf `super(...)` ile üst sınıf constructor'ını çağırmalı ve arayüz metodunu gerçeklemelidir.
- UML'de override gösterimi
  - Alt sınıfta üst sınıftaki bir metot yeniden yazılmışsa (örneğin `Manager` içinde `getSalary()`), bu metodun override edildiği anlamına gelir. Yazılmamışsa metot olduğu gibi kalıtılmış demektir (ekrandan, 01:35:00).
- Enum (sayım) türleri
  - Basit (primitive) enum: bir değişkenin yalnız belirli bir değer kümesinden değer almasını sağlar. Örnek: `public enum Size { SMALL, MEDIUM, LARGE, EXTRA_LARGE; }`, kullanım `Size s = Size.MEDIUM;` (ekrandan, 01:40:00).
  - Enum sınıfları: Java'da enum aslında bir sınıf tanımıdır; her değer o sınıfın bir nesnesidir. Üye alan, metot ve constructor içerebilir; constructor private olmalıdır; değerlerin tanımı gövdenin ilk satırında olmalıdır.
  - Örnek: `Tariff` enum'u `NETFREE(0,4,60), NET4(4,8,30), NET6(6,8,40)`; alanlar kota, hız, ücret (ekrandan, 01:45:00). UML'de ad bölmesine `«enum»`, alan bölmesinin ilk satırına değerler yazılır.
  - `Person` – `Subscription` – `Tariff` tasarımı: kişi doğrudan tarifeye değil, başlangıç tarihi tutan bir aboneliğe bağlıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir sınıf bir arayüzün bütün metotlarını yazsa bile `implements` ile bildirmedikçe o arayüz türünden bir değişkene atanamaz
  - Hoca bunu Eclipse'te gösterdi: `Car` sınıfından `implements PersonalVehicle` silinince `PersonalVehicle pv = new Car(...)` satırı derleme hatası verdi. Metotları yazmak yetmez, sınıf o arayüz üzerinden erişime açık olduğunu açıkça beyan etmelidir.
- Bir nesneye hangi arayüz türünden bakılıyorsa yalnız o arayüzün metotları çağrılabilir
  - Aynı `Car` nesnesi hem `PersonalVehicle` hem `CommercialVehicle` türünden değişkenlere atanabilir; `PersonalVehicle` üzerinden `calculateAmortizedTax` çağrılamaz.
- Arayüzlerin asıl gerekçesi iki ayrı kırılımın modellenmesi
  - Vergi hesapları basit bir çarpanla parametrize edilemeyecek kadar farklı olduğundan tek bir soyut üst sınıf yetmez; arayüz çözümü daha hafif ve tercih edilen çözümdür.
- Ortak üst arayüz yalnız tek satırlık ortaklık için gereksiz olabilir
  - `Vehicle` üst arayüzü yalnız `getPlate()` satırını tekrar etmemeyi sağlıyor; hoca bunu "değmez" diye değerlendirdi. Daha fazla ortak metot olsaydı düşünülebilirdi. Ortak `Vehicle` dizisi kurulsa bile vergi metotlarına erişmek için tip dönüşümü gerekir, bu da tercih edilmez.
- Dizi üzerinde for-each ile arama yaparken boş (null) hücrelere dikkat
  - Örnek kodda `searchCommercialVehicle` for-each ile bütün diziyi dolaştığı için null elemanda `getPlate()` çağrıldı ve `NullPointerException` oluştu. Döngü dolu eleman sayısına kadar indeksli `for` ile yazılmalıdır.
- Enum constructor'ı private olmalı ve değerler ilk satırda tanımlanmalı
  - Constructor dışarıdan çağrılabilseydi enum'un sabit değer kümesi dışında nesne oluşturulabilirdi.

## Kısa Tekrar Notları

- Arayüz = üye alanı olmayan soyut sınıf gibi; metot imzaları kümesi; bir rol/bakış açısı.
- Tanım: `public interface Ad { dönüşTipi metot(parametreler); }`; gerçekleme: `class X implements A, B`.
- Gerçekleyen sınıf bütün metotları yazmalı, yoksa abstract olmalı.
- Arayüzde yalnız `public final static` alan, yalnız public metot, constructor yok.
- Arayüzden nesne oluşturulmaz; gerçekleyen sınıfın nesnesi arayüz türünden değişkene atanır.
- UML: `«interface»` stereotipi, kesikli çizgili, içi boş üçgen uçlu ok.
- Arayüz adlarını `I` ile başlatmak yaygın bir alışkanlıktır.
- Arayüzler `extends` ile birbirinden kalıtım alabilir; bir sınıf aynı anda `extends` ve `implements` kullanabilir.
- `implements` bildirimi olmadan, metotlar yazılmış olsa bile arayüz türüne atama yapılamaz.
- Diziyi for-each ile ararken null hücreler `NullPointerException` doğurur; eleman sayısına kadar dön.
- Enum: sabit değer kümesi; Java'da sınıftır, her değer bir nesnedir; alan, metot ve private constructor içerebilir; değerler ilk satırda.
- Enum değerine atama `Size.MEDIUM` biçimindedir; `Size.Medium`, `MEDIUM` ya da başka bir değer yazılamaz.

## Detaylı Açıklamalar

- **Arayüzün yeri.** Hoca arayüzü kalıtımın iki sorununa karşı geliştirilmiş bir araç olarak tanıttı: kalıtımın ağır ve kötüye kullanılabilir bir ilişki olması ve çoklu kalıtımın desteklenmemesi. Arayüzde yalnız metot imzaları olduğundan bir sınıf birçok arayüzü gerçekleyebilir; aynı imza iki arayüzde bulunsa bile tek bir gövde yazıldığı için elmas kalıtımdaki belirsizlik doğmaz. Gerçek hayatta bir insanın hem müşteri, hem satıcı, hem arkadaş olabilmesi gibi bir `Person` nesnesi `Customer`, `Supplier`, `Friend` rollerini aynı anda üstlenir (ekrandan, 00:10:00).

- **Taşıt vergi sistemi.** Gereksinimler slaytta şöyle verilir: ticari ve şahsi araçların vergilendirmesi farklıdır; motosiklet, araba ve otobüs ticari araç olarak kaydedilebilir; yalnız motosiklet ve araba şahsi araç olabilir; yalnız ticari araçların vergisi amortismanlı hesaplanabilir; araç türleri arasında hesap çok farklıdır (ekrandan, 00:20:00). İki kırılım 3 × 2 = 6 durum verir, otobüs şahsi olamadığı için 5 durum kalır. `Car` sınıfı:

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

  Kod gövdesi ekrandan alınmıştır (ekrandan, 01:25:00); `getPlate`, `getModelYear`, `getEngineVolume` satırları hocanın anlatımına göre tamamlanmıştır.

- **Eclipse denemesi.** `Car aCar = new Car("34 A 4321", 2015, 1.8);` için `aCar.calculateTax(1000)` sonucu $1000 \times 1{,}8 = 1800$; `aCar.calculateAmortizedTax(1000, 2017)` sonucu yaş 2 olduğundan $1000 \times 1{,}8 \times (1 - 0{,}2) = 1440$ çıktı (ekrandan, 00:45:00). `CommercialVehicle myCar = new Car("34 B 123", 2014, 1.6);` için amortismanlı vergi $1000 \times 1{,}6 \times 0{,}7 = 1120$ oldu (ekrandan, 01:10:00). Bu değerler ders sonrası `java` ile yeniden çalıştırılarak doğrulandı.
  - Ders sonrası not: `PersonalVehicle pv = new Car("34 PV 34", 2016, 1.6);` satırından sonra `pv.calculateTax(2017)` çağrıldı ve ekranda 3227,2 çıktı (ekrandan, 01:05:00). Burada temel vergi yerine yıl verilmiştir; hoca da bunu fark edip "bu base tax, yıl değil aslında" dedi. 1000 verilseydi sonuç 1600 olurdu.

- **Kayıt sistemi ve for-each hatası.** `registerCommercialVehicle` metodu şu koşullardan biri doğruysa `false` döner: plaka ticari dizide var, plaka şahsi dizide var ya da dizi dolu. Hoca dizi doluluk kontrolünü ders sırasında ekledi; `maxCapacity` yerine `commercialVehicles.length` kullanmayı tercih etti, çünkü kapasite ileride artırılabilir. Arama metodu ilk hâlinde for-each kullandığı için boş dizideki null elemanda `NullPointerException` verdi (ekrandan, 01:20:00). İndeksli döngüyle düzeltilmiş hâli:

```java
public CommercialVehicle searchCommercialVehicle( String plate ) {
    for( int i = 0; i < commercialVehicleCount; i++ )
        if( commercialVehicles[i].getPlate().equalsIgnoreCase(plate) )
            return commercialVehicles[i];
    return null;
}
```

  Düzeltmeden sonra aynı aracın önce ticari kaydı başarılı (Test 1 OK), sonra şahsi kaydı reddedildi (Test 2 OK) (ekrandan, 01:25:00). Hoca, bağlı liste kullanılsaydı listenin sonu belli olacağı için bu sorunun yaşanmayacağını ekledi.

- **Enum sınıfları.** `Tariff` enum'unda ilk satırdaki `NETFREE(0,4,60)` gibi ifadeler aslında constructor çağrılarıdır: kota 0 (kota yok), hız 4, ücret 60. Ders kodunda `setFee` ve `toString` de eklenmiştir. Bir enum değeri hangi değişkene atanırsa atansın bellekte aynı nesneyi gösterir; bu yüzden `tariff4.setFee(35)` ya da `Tariff.NET4.setFee(40)` ile ücret değiştirilince NET4'e abone olan bütün kişilerin ücreti değişti, NETFREE abonesininki değişmedi (ekrandan, 02:00:00).
  - Ders sonrası not: Bir öğrenci enum'da kaç değer tanımlı olduğunu programdan öğrenmenin yolunu sordu; hoca doğrudan bir yol olmadığını, Java Reflection API ile yapılabileceğini söyledi. Aslında her enum için derleyicinin ürettiği `values()` metodu vardır; `Tariff.values().length` 3 döndürür (ders sonrası `java` ile denendi).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
