# Ders 12 Çalışma Özeti

## Genel Konular

- Galeri örneğinde `removeCar` ve `searchCar` metotlarına dönüş
  - Dizi kullanıldığı için silinecek aracın kaçıncı gözde olduğunu bulmak gerekir. Silinen elemanın sağındaki elemanlar bir sola kaydırılır.
  - Aracın dizideki yerini döndüren bir metot kullanıcıya açılmamalıdır. Bu bilgi yalnız galeri sınıfını ilgilendirir; gerekiyorsa `private` olur.
  - `private int searchCar(String plate)` ile `public Car searchCar(String plate)` birlikte tanımlanamaz (ekrandan, 00:10:00). Metot imzası yalnız metodun adı ve parametrelerinden oluşur. Görünürlük ve dönüş tipi imzaya girmez.
  - Bu yüzden `removeCar` içinde arama döngüsü yeniden yazılır. Aynı mantık iki kez kodlanmış olur. Bağlı liste gibi yapılarda bu sorun ortadan kalkar.
- Kalıtım (inheritance) ilişkisi
  - Mevcut bir sınıftan yeni ve daha özelleşmiş sınıflar oluşturma mekanizmasıdır. Kalıtım sınıf düzeyinde bir ilişkidir (ekrandan, 00:15:00).
  - Çocuk ebeveynden genetik özellikleri alır ve bunları reddedemez. Alt sınıf da üst sınıftaki hiçbir üyeyi reddedemez. Private üyeler de aktarılır, ama alt sınıf onlara doğrudan erişemez.
  - Hoca "miras" yerine "kalıtım" der: mirası reddetmek mümkündür, kalıtımı reddetmek mümkün değildir.
  - UML'de ok yeni sınıftan (B) mevcut sınıfa (A) çizilir, ucu içi boş kapalı üçgendir. Okun yönü bağımlılığın yönüdür: B, A'yı bilir. A, kendisinden türetilen sınıfları bilmez, bilmemelidir de.
  - Terimler: A için parent class, super class, base class (ebeveyn sınıf, üst sınıf); B için child class, sub class, derived class (çocuk sınıf, alt sınıf).
- Kalıtımın kuralları (ekrandan, 00:20:00)
  - Alt sınıf üst sınıftan gelen metotların gövdesini değiştirebilir. Buna overriding (metodu yeniden tanımlama) denir.
  - `final` metotlar alt sınıfta yeniden tanımlanamaz. Üst sınıf alt sınıflarına başka bir kısıt koyamaz.
  - Alt sınıfa yeni üye alan ve metotlar eklenebilir. Bir alt sınıf başka sınıfların üst sınıfı olabilir. Böylece kalıtım hiyerarşisi (kalıtım ağacı) oluşur. Ortak atadan türeyen sınıflara kardeş sınıf (sister class) denir.
  - Örnek ağaç: `Person` altında `Student`, `Employee`, `Retired`; `Employee` altında `Director` ve `PartTime`.
- Kırılgan üst sınıf (fragile base class) problemi
  - Ağaç derinleştikçe kökteki bir değişikliğin alt sınıflarda hata (bug) çıkarma olasılığı artar.
  - Hoca en fazla 5 düzey önerir. 6-7 düzeye çıkılıyorsa tasarım gözden geçirilmelidir.
- Genelleşme-özelleşme ilişkisi ve yerine geçebilirlik
  - Alt sınıf üst sınıfın daha yetenekli ve özelleşmiş hâlidir. Üst sınıf daha genel ve daha az yeteneklidir.
  - Yerine geçebilirlik ilkesi: üst sınıftan bir nesnenin beklendiği her yerde alt sınıftan bir nesne kullanılabilir. Bu yüzden kalıtıma "is-a" ilişkisi de denir. Her cip bir arabadır; her mürekkep püskürtmeli yazıcı bir yazıcıdır.
- Kalıtımın yanlış kullanımı (ekrandan, 00:25:00)
  - Kalıtım ağır sıklet bir ilişkidir. Derleme anında belirlenir, çalışma anında değiştirilemez. Sahiplik ve parça-bütün gibi ilişkiler nesne düzeyindedir, çalışma anında değiştirilebilir.
  - Yanlış: `GUI Button` sınıfından `Red`, `Yellow`, `Purple` alt sınıfları türetmek. Renklerin sonu gelmez.
  - Doğru: `GUI Button` içinde `- color : RGB` alanı. `RGB` sınıfında `- red, green, blue : int` vardır. Düğme çizilirken bu renkle boyanır.
  - Deneyimli modelleyiciler kalıtımı yalnız açık bir genelleşme-özelleşme ilişkisi varsa seçer. Diğer durumlarda association, composition ya da aggregation kullanılır. Arayüz gerçekleştirme de bir seçenektir (ekrandan, 00:30:00).
  - Kalıtımın doğru kullanımı tasarım kalıplarının (design patterns) önemli bir temelidir.
- Çok biçimlilik (polymorphism) (ekrandan, 00:35:00)
  - `Person` türünden bir dizide `Student`, `Employee`, `Retired` nesneleri karışık bulunabilir. Her elemanın `introduceSelf()` metodu çağrılınca her nesne kendi en özelleşmiş sürümüyle davranır. Buna çok biçimlilik denir.
  - Java'da çok biçimlilik varsayılan olarak açıktır. Eclipse'in eklediği `@Override` satırı bir annotation'dır, yazmak zorunlu değildir.
  - Yeniden tanımlanmış bir metodun üst sınıftaki hâline `super` işaretçisiyle erişilir. `super`, `this`'ten sonra Java'daki ikinci özel işaretçidir.
- `Person` - `Employee` - `Manager` - `Company` örneği (ekrandan, 00:40:00)
  - `Person`: `- name : String`, `+ Person(String)`, `+ getName() : String`. Ad değişmeyeceği için `setName` yoktur.
  - `Employee`: `- salary : int`, `+ Employee(name, salary)`, `getSalary`, `setSalary`.
  - `Manager`: `- bonus : int`, `+ Manager(name, salary)`, `setBonus`, `getSalary`. Yöneticinin maaşı, çalışan maaşı ile bonusun toplamıdır.
  - `Company` sınıfının `main` metodu `Employee` türünden bir diziye `Manager` ve `Employee` nesneleri koyar ve ad ile maaşlarını yazdırır.
- Alt sınıf constructor kuralı ve `super(...)`
  - Kalıtım `extends` anahtar kelimesiyle kurulur.
  - Üst sınıfta varsayılan olmayan bir constructor varsa alt sınıfta da varsayılan olmayan bir constructor bulunmalıdır. Bu constructor ilk komut olarak üst sınıfın constructor'ını `super(...)` ile çağırmalıdır (ekrandan, 00:50:00).
  - `super(...)` constructor içinde yalnız bir kez kullanılır. `super(name); super(salary);` gibi iki çağrı yazılamaz.
- `Manager.getSalary()` ve `super.getSalary()`
  - `salary` private olduğu için `Manager` içinde doğrudan kullanılamaz.
  - `return bonus + getSalary();` yazmak, metodun kendisini sürekli çağırmasına (sonsuz özyineleme) yol açar.
  - Doğru çözüm: `return bonus + super.getSalary();`.
  - `salary` alanını `protected` yapmak da çalışır, ama hoca bunu tercih etmez. Üst sınıf, alt sınıflarının ihtiyacını bilmek zorunda kalmamalıdır.
  - `super.super.getSalary()` yazılamaz. `super` hiyerarşide yalnız bir adım yukarı çıkar.
- Çalıştırma ve çok biçimlilik
  - Çıktıda yöneticinin maaşı 8000 + 2500 = 10500 olarak, diğer çalışanlarınki 7500 ve 7000 olarak yazılır (ekrandan, 01:10:00). Dizinin türü `Employee` olsa da `Manager` nesnesi kendi `getSalary()` metoduyla davranır.
  - `Employee` türündeki bir işaretçiyle yalnız `Employee` sınıfında tanımlı metotlara erişilir. Diziye konduktan sonra `setBonus` çağrılamaz. Bonusu önce `Manager` türündeki bir işaretçiyle atamak ya da üç parametreli bir constructor eklemek gerekir.
- Overloading ile overriding farkı (ekrandan, 01:40:00)
  - Override: kalıtımla gelen metodun gövdesini değiştirmek. Kalıtımla yakından ilgilidir. Örnek: `Manager.getSalary()`.
  - Overload: aynı adda, farklı parametreli birden çok metot. Kalıtımla ilgili değildir. Örnek: `Manager(String name, int salary, int bonus)` constructor'ı eklenince `Manager` sınıfının iki constructor'ı olur.
- `Object` sınıfı ve `toString()`
  - Java'daki bütün sınıfların üst sınıfı `java.lang.Object`'tir. Üst sınıfı yazılmayan bir sınıf otomatik olarak `Object`'ten türer.
  - Override edilmemiş `toString()`, sınıf adını ve onaltılık bir hash kodunu verir (ör. `nyp05.Manager@5d22bbb7`) (ekrandan, 01:15:00). Aynı nesneye ait iki işaretçi aynı kodu verir.
  - Bundan sonra `introduceSelf` yerine `toString()` override edilir. `System.out.println(nesne)` bu metodu kendisi çağırır.
- `Company.main` için sıralama şeması (ekrandan, 01:35:00)
  - Dizinin oluşturulması `new Employee[3]` mesajıyla gösterilebilir.
  - Diziye ekleme bir metot çağrısı olmadığı için stereotip işaretleriyle gösterilir: `«add boss»`, `«add tmp»`. Adı olmayan geçici nesnenin dönüş okuna `tmp` yazılır.
  - Döngüdeki çağrılar `*getName()`, `*getSalary()` diye yıldızla işaretlenir. UML ayrıca bu çağrıların bir dikdörtgen (çerçeve) içine alınıp ortak koşulun çerçevenin etiketine bir kez yazılmasına izin verir. Violet UML bunu desteklemez.
- Private metotlar ve final sınıflar
  - Üst sınıfın private metotları alt sınıfta yeniden tanımlanabilir. Ama alt sınıf `super` ile bile orijinal sürüme erişemez. Hoca bunu önermez.
  - `final` olarak tanımlanan bir sınıf üst sınıf olarak kullanılamaz. `final class Person` yazılınca `Employee extends Person` derleme hatası verir.
- Kalıtımın doğru kurulması: hasta-doktor örneği (ekrandan, 01:45:00)
  - Gereksinim: hastaların adı, TC kimlik no, doğum tarihi ve cep telefonu tutulmalıdır; aynı bilgiler doktorlar için de tutulmalıdır; doktorların diploma numarası da saklanmalıdır; hastaya uygulanan tedaviler kaydedilmelidir.
  - Yanlış model: `Doctor`'u `Patient`'tan türetmek. `Patient`'a eklenen `treatments : Treatment[]` alanı doktora da geçer.
  - Doğru model: ortak bilgiler (`name, TCID, cellNr : String`, `birth : Date`) gereksinimde geçmeyen bir `Person` sınıfına konur. `Doctor` ve `Patient` bu sınıftan türer. Yalnız `Patient` ile `Treatment` arasında 1-* sahiplik kurulur.
- Soyut sınıflar (abstract classes) (ekrandan, 02:05:00)
  - Yalnız alt sınıflarına temel oluşturmak için var olan, kendisinden nesne oluşturulmayan sınıflardır. `abstract` anahtar kelimesiyle işaretlenir. UML'de sınıf adının üstüne `«abstract»` yazılır.
  - Soyut sınıftan nesne oluşturulamaz; somut alt sınıflarından oluşturulabilir. Soyut olmayan sınıflara normal ya da somut sınıf (concrete class) denir.
  - Soyut sınıfın üye alanları, constructor'ı, somut ve soyut metotları olabilir. Constructor alt sınıflardan `super(...)` ile çağrılmak içindir.
  - Soyut metodun gövdesi yoktur: `public abstract boolean isSuitable(Child aChild);`. UML'de metodun sonuna `{abstract}` yazılır.
  - Somut alt sınıflar soyut metotların gövdesini tanımlamalıdır. Tanımlamazlarsa onlar da soyut olmalıdır. Bir sınıfın tek bir soyut metodu bile varsa sınıf da soyut olmalıdır.
- Soyut sınıf örneği: yazıcı sürücüsü (ekrandan, 02:10:00)
  - `«abstract» PrintDriver`: `+ initSpooler()` (somut) ve `+ print(Document) : {abstract}`. `PCL6Driver` ve `PSDriver` `print`'i yeniden tanımlar.
  - Spooler'ın ilklendirilmesi her sürücüde aynıdır. Belge basma işlemi PCL ve PostScript standartlarına göre bambaşkadır.
  - Farklı sürücüler aynı dizi ya da koleksiyonda `PrintDriver` olarak tutulup çok biçimli biçimde `print` ile kullanılabilir.
- Çoklu kalıtım (multiple inheritance) ve elmas problemi (ekrandan, 02:15:00)
  - `AssistantStudent` sınıfını hem `Student` hem `Employee`'den türetmek ilk bakışta uygun görünür.
  - İkisi de `Person`'dan türüyorsa şema elmas biçimini alır (diamond inheritance). `Person`'daki bir metot (ör. `toString`) iki ara sınıfta da override edilmişse hangi sürümün geçeceği belirsizdir.
  - Java ve C# çoklu kalıtımı desteklemez, yerine arayüz (interface) gerçekleştirmeyi sunar. C++ destekler; bu durumda metodun en alt sınıfta override edilmesini şart koşar.
- Soyut sınıf tasarımı: anaokulu malzemeleri (ekrandan, 02:20:00)
  - `«Abstract» Item`: `- barcode, description : String`, constructor, `getBarcode`, `getDescription`, `+ isSuitable(aChild : Child) : boolean {abstract}`.
  - `Toy`: `- minAgeLimit : int` (yıl). `Clothing`: `- minMonthLimit, maxMonthLimit : int` (ay).
  - `Child`: `- name : final String`, `- ageInMonths : int`. `Item`'dan `Child`'a kesikli ok (bağımlılık) vardır, çünkü çocuk yalnız parametre olarak aktarılır. `KinderGarten` ile `Child` arasında 1-* ilişki vardır.
  - `Clothing.isSuitable`: çocuğun aylık yaşı alt ve üst sınırlar arasındaysa `true` döner (ekrandan, 02:30:00). `Toy.isSuitable`: aylık yaş 12'ye bölünür ve en küçük yaş sınırıyla karşılaştırılır.
  - Deneme: 5 aylık çocuk için 4 yaş sınırlı Lego uygun değildir, 0-24 aylık mama önlüğü uygundur. Çıktı `Deneme 1 tamam`, `Deneme 2 tamam` olur (ekrandan, 02:35:00).
  - `new Item(...)` derleme hatası verir. Ama `Item anItem = new Toy(...)` geçerlidir.
- Soyut sınıf olmadan aynı tasarım
  - `Item` normal sınıf yapılırsa `isSuitable` için bir gövde yazmak gerekir. Boş gövde ya da `return true;` yalnız derleme hatasını giderir.
  - Alt sınıfta override unutulursa her çocuğa `true` döner ve uygun olmayan bir oyuncak çocuğa verilebilir. Soyut metot ise bu unutmayı derleme anında yakalar.
- Birim sınaması (unit testing)
  - Elle yazılan "tamam/hatalı" denetimleri, karmaşık örneklerde hatanın nedenini göstermez. Sınıf düzeyinde sınamayı kolaylaştıran araçlar vardır. Dersin son haftalarında işlenecektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kalıtımı yalnız gerçekten gerektiğinde kullanın
  - Kalıtım ağır sıklet, derleme anında sabitlenen bir ilişkidir. Açık bir genelleşme-özelleşme ilişkisi yoksa sahiplik, parça-bütün ya da arayüz tercih edilir. Düğme rengi ve hasta-doktor örnekleri yanlış kalıtımın sonuçlarını gösterir.
- Kalıtım ağacını derin tutmayın
  - Kırılgan üst sınıf problemi yüzünden en fazla 5 düzey önerilir.
- `super(...)` alt sınıf constructor'ının ilk komutudur
  - Üst sınıfta varsayılan olmayan constructor varsa bu zorunludur. Kâğıt üstünde kod yazarken `super` iki kez çağrılmamalıdır.
- `protected` yerine `super` ile erişim
  - Hoca üst sınıfın alt sınıfları hakkında bir şey bilmek zorunda olmamasını ister. Bu yüzden `super.getSalary()` yolunu seçer.
- Metodun kendini çağırması tuzağı
  - `Manager.getSalary()` içinde `getSalary()` yazmak sonsuz özyinelemeye yol açar.
- Soyut metot ve güvenlik
  - Varsayılan bir gövde (`return true;`) yazmak, override unutulduğunda tehlikeli sonuçlar doğurabilir. Soyut metot bu hatayı derleme anında yakalatır.
- Birim dönüşümünü unutmayın
  - Oyuncakta sınır yıl, kıyafette ay cinsindendir. `Toy.isSuitable` içinde ay 12'ye bölünmelidir.

## Kısa Tekrar Notları

- Metot imzası = ad + parametreler. Dönüş tipi ve görünürlük imzaya girmez.
- Kalıtım: alt sınıf üst sınıfın tüm üyelerini alır, private üyelere doğrudan erişemez.
- UML kalıtım oku: alt sınıftan üst sınıfa, içi boş üçgen uç.
- Override = gövdeyi yeniden tanımlama; overload = aynı ad, farklı parametre.
- `final` metot override edilemez; `final` sınıftan kalıtım yapılamaz.
- Çok biçimlilik: üst sınıf türünden işaretçi, nesnenin en özelleşmiş metodunu çalıştırır.
- Üst sınıf türünden işaretçiyle yalnız üst sınıfta tanımlı metotlar çağrılabilir.
- `super(...)`: constructor'da ilk komut, bir kez. `super.metot()`: override edilmemiş sürüm, bir adım yukarı.
- `Object`: bütün sınıfların üst sınıfı; `toString()` override edilerek nesne metne çevrilir.
- Sıralama şemasında diziye ekleme `«add ...»`, geçici nesne `tmp`, döngü `*`.
- Soyut sınıf: `abstract`, nesnesi oluşturulamaz, constructor'ı olabilir; soyut metodun gövdesi yoktur.
- UML: `«abstract»` sınıf, `{abstract}` metot.
- Java ve C# çoklu kalıtımı desteklemez (elmas problemi); yerine arayüz kullanılır.

## Detaylı Açıklamalar

- Kalıtım, "is-a" ilişkisi olarak düşünülmelidir. Bir `Manager` bir `Employee`'dir, bir `Employee` bir `Person`'dır. Bu yüzden `Employee[] staff` dizisine `Manager` nesnesi konabilir. Dizi üzerinden `getSalary()` çağrıldığında Java çalışma anında nesnenin gerçek sınıfına bakar ve `Manager`'ın sürümünü çalıştırır. Bu, çok biçimliliktir. Buna karşın `setBonus` yalnız `Manager`'da tanımlı olduğundan `Employee` türündeki bir işaretçiyle çağrılamaz. Hoca bunun tür dönüşümü (typecasting) ile yapılabileceğini, ama tür dönüşümünün çok tercih edilmediğini ve ileride işleneceğini söyledi.
- Derste kodlanan sınıflar (ekrandan, 00:50:00, 00:55:00 ve 01:10:00; örnek adlar genel adlarla değiştirildi; `toString` gövdeleri altyazıdaki anlatımdan kuruldu). Kod `java Company.java` ile çalıştırıldı:

```java
class Person {
    private String name;
    public Person(String name) { this.name = name; }
    public String getName() { return name; }
}
class Employee extends Person {
    private int salary;
    public Employee(String name, int salary) {
        super(name);          // ilk komut olmalı
        this.salary = salary;
    }
    public int getSalary() { return salary; }
    public void setSalary(int salary) { this.salary = salary; }
    public String toString() { return "Employee " + getName() + " " + getSalary(); }
}
class Manager extends Employee {
    private int bonus;
    public Manager(String name, int salary) { super(name, salary); }
    public Manager(String name, int salary, int bonus) {   // overload
        super(name, salary);
        this.bonus = bonus;
    }
    public void setBonus(int bonus) { this.bonus = bonus; }
    public int getSalary() { return bonus + super.getSalary(); }  // override
    public String toString() { return "Manager " + getName() + " " + getSalary(); }
}
public class Company {
    public static void main(String[] args) {
        Employee[] staff = new Employee[3];
        Manager boss = new Manager("Ali Yilmaz", 8000);
        boss.setBonus(2500);
        staff[0] = boss;
        staff[1] = new Employee("Ayse Demir", 7500);
        staff[2] = new Employee("Can Kaya", 7000);
        for (Employee author : staff)
            System.out.println(author.getName() + " " + author.getSalary());
    }
}
```

  - Çıktı: `Ali Yilmaz 10500`, `Ayse Demir 7500`, `Can Kaya 7000`. `System.out.println(author)` kullanılırsa `Manager Ali Yilmaz 10500` gibi `toString()` çıktısı alınır.
- Soyut sınıf örneğinde `Item` sınıfı tek başına anlamlı bir nesne değildir: bir item oyuncak mı, kıyafet mi, defter mi belli değildir. Uygunluk denetimi de her türde farklıdır: oyuncakta tek alt sınır (yıl), kıyafette alt-üst sınır (ay). Bu yüzden `isSuitable` üst sınıfta soyut bırakılır. Hoca, varsayılan gövde yazıp iki parametreyle iki durumu birden üst sınıfta çözmeye çalışmanın işi dağıttığını söyledi: "Bir iş bir yerde, en uygun yerde yapılır."
- Ders sonrası notlar
  - Hoca `protected` alanların "diğer sınıflar için private, alt sınıflar için public gibi" davrandığını söyledi. Java'da `protected` üyelere aynı paketteki sınıflar da erişebilir.
  - Hoca, Java'da `@Override` yazılınca çok biçimliliğin açık olduğunu, C#'ta ise bu işaret yazılmazsa kapalı olduğunu anlattı. Java'da `@Override` yalnız derleyiciye "bu metot gerçekten bir üst sınıf metodunu yeniden tanımlıyor mu" denetimini yaptırır; çok biçimliliği etkilemez. C#'ta `override` bir annotation değil, anahtar kelimedir ve üst sınıf metodu `virtual` olarak işaretlenmelidir.
  - Derste `super(...)` satırını alt satıra taşımak derleme hatası verdi (Eclipse, Java 15). Java 25'te (JEP 513) `this` kullanmayan komutlar ve alan atamaları `super(...)`'dan önce yazılabilir; `this.salary = salary; super(name);` biçimi bu ajanın denemesinde Java 25 ile derlendi.
  - Derste `new Toy("Işın kılıcı", "123445", 10)` satırında barkod ve tanım argümanları ters verildiği için `getDescription()` çıktısı `123445` oldu (ekrandan, 02:35:00). Constructor sırası `(barcode, description, minAgeLimit)` olduğundan doğrusu `new Toy("123445", "Işın kılıcı", 10)` olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
