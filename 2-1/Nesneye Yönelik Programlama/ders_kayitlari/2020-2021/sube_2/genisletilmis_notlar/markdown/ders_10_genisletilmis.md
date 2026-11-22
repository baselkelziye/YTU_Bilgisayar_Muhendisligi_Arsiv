# Ders 10 Genişletilmiş Notu: Çift Yönlü İlişkiler, Aggregation ve Composition, Dizilerle Bire-Çok İlişki

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tek Yönlüden Çift Yönlü Sahiplik İlişkisine
- 2. Çift Yönlü İlişkinin Kodu ve İlk Deneme
- 3. Setter'ların Birbirini Çağırması ve Sonsuz Özyineleme
- 4. Kurucu, Satış ve Çapraz Atama Durumları
- 5. Çift Yönlü İlişkiden Çıkarılan Ders
- 6. Parça-Bütün İlişkileri: Aggregation
- 7. Composition
- 8. Dizilerle Bire-Çok İlişki: Gallery Sınıfının Tasarımı
- 9. Gallery Sınıfının Kodu
- 10. Gallery Sınıfının Testi
- Örnek Sorular

## 1. Tek Yönlüden Çift Yönlü Sahiplik İlişkisine

Önceki derste kişi ile araba arasındaki sahiplik ilişkisi tek yönlüydü. Bir kişi (`Person`) arabası olduğunu biliyordu, ama araba (`Car`) sahibini bilmiyordu. Bu derste aynı ilişki çift yönlü yapıldı.

Hoca, gerçek bir arabanın bilinçli bir varlık olmadığını, dolayısıyla sahibini "bilmeyeceğini" kabul etti. Yine de ters yönde ilişkiye ihtiyaç duyulan senaryolar düşünülebilir. Örneğin bir taşıt bilgi sistemi, araç kaydından yola çıkıp aracın sahibini sorgulamak isteyebilir. Belki ileride sahibini parmak izinden tanıyan araçlar da olur. Bu fütüristik örnekler bir yana, bir bilgi sisteminde elde bir araba nesnesi varken onun sahibini sorgulamak gerekiyorsa araba tarafından kişiye giden ilişki de gerekir.

Slayttaki ifade: "If we need to be able to find out the owner of a car, as well as being able to assign a car to a person, a two-way association must be constructed." (ekrandan, 00:05:00)

### 1.1 UML şeması

`nyp03` paketinin şemasında `Person` ile `Car` arasında iki uçlu bir ok vardır; iki uçta da `0..1` yazar (ekrandan, 00:05:00):

```text
Person                                Car
- name : String                       - plate : String
- car : Car                           - owner : Person
+ Person( name : String )      0..1   0..1  + Car( String )
+ getName( ) : String        <--------->    + Car( plateNo : String, Person )
+ getCar( ) : Car                           + getOwner( ) : Person
+ setCar( Car )                             + setOwner( Person )
+ introduceSelf( ) : String                 + getPlate( ) : String
                                            + setPlate( String )
                                            + introduceSelf( ) : String
MainProgram03: + main( String[] )   (iki sınıfa da bağımlılık okuyla bağlı)
```

`Person` sınıfı bir önceki haftaya göre hiç değişmez. Araba artık sahibini bileceği için `Car`'dan `Person`'a doğru da bir ok ucu konur. `Person` tarafına `0..1` yazılır, çünkü bir araba oluşturulduğu anda bir kişiye verilmek zorunda değildir.

`Car` sınıfında iki kurucu vardır. Biri yalnız plakayı, diğeri plakayı ve sahibi alır. İlk kurucu çağrılırsa araba sahipsiz oluşturulur. Yani bir araba nesnesi belli bir anda hiçbir kişiyle ilişkili olmayabilir. Bu nedenle `Person.introduceSelf()` nasıl "arabam varsa plakasını da söyle" diye yazıldıysa, `Car` sınıfında da benzer bir kontrol gerekir.

Okun `Car`'dan `Person`'a giden yönünü kodlayabilmek için `Car` sınıfında `Person` türünden bir üye alan gerekir; adı `owner`'dır. Arabanın sahibi değişebileceği için `owner` için getter ve setter vardır. Plaka için de getter ve setter vardır.

### 1.2 introduceSelf metodunun yeni çalışma biçimi

`introduceSelf()` metotları ilk zamanlarda bilgiyi ekrana yazıyordu. Artık bilgiyi içeren bir `String` oluşturup geri döndürürler. Metot nereden çağrıldıysa, çağıran taraf bu metni ister ekrana yazar, ister bir iletişim kutusunda gösterir, ister veri tabanına ya da dosyaya kaydeder. Dersin geri kalanında `introduceSelf()` hep böyle çalışır. Denemeler için `main` metodunu içeren ayrı bir sınıf yazılır.

## 2. Çift Yönlü İlişkinin Kodu ve İlk Deneme

### 2.1 Car sınıfı

`Car` sınıfına eklenenler `owner` üye alanı, iki kurucu, getter/setter metotları ve `introduceSelf()` metodudur. Bir sahiplik ilişkisi olup olmadığı `owner` alanının `null` olup olmamasından anlaşılır. Hocanın derste açtığı kod (ekrandan, 00:30:00):

```java
package nyp03a;
public class Car {
    private String plate;
    private Person owner;

    public Car( String plate ) { this.plate = plate; }
    public Car( String plate, Person owner ) {
        this.plate = plate;
        this.owner = owner;
    }
    public void setOwner( Person owner ) {
        this.owner = owner;
        if( owner.getCar() != this )
            owner.setCar(this);
    }
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

Bu karede `setOwner` metodu 3. bölümde anlatılan kontrolü de içerir. İlk sürümde `setOwner` yalnız `this.owner = owner;` satırından oluşuyordu. `introduceSelf()` içinde önce `intro` tanımlanır ve içine "plakam şudur" bilgisi yazılır. Sahip varsa "sahibimin adı şudur" bilgisi eklenir. En sonunda metin döndürülür.

### 2.2 null kontrolü neden gerekli?

**Soru:** Bu `null` kontrolünü unutmamak için ilk kurucuyu kaldırsak mı? Böylece her aracın mutlaka bir sahibi olur ve kontrol gereksizleşir.

**Cevap:** Hocaya göre bu yaklaşım doğru değildir. Yalnız iki parametreli kurucu kalsa bile biri kodda araba oluştururken ikinci parametre olarak elle `null` yazabilir. Bu kod derlenir, ama ortada atanmış bir kişi yoktur. Bu yüzden `null` kontrolü her zaman yapılmalıdır.

### 2.3 Test programı

Test programı iki kişi ve iki araba oluşturur, ilişkiyi iki yönden de elle kurar (ekrandan, 00:10:00):

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
        Car honda = new Car("47 AS 1946");
        aziz.setCar(honda);
        honda.setOwner(aziz);
        System.out.println( aziz.introduceSelf() );
        System.out.println( honda.introduceSelf() );
    }
}
```

İlişki iki yönlü olduğu için iki yönü de kurmak gerekir: kişiye arabası verilir, arabaya da sahibi verilir. Program sorunsuz çalışır (ekrandan, 00:10:00):

```text
[PERSON] My name is Oktay Sinanoğlu and the plate of my car is 06 OS 1934
[CAR] My license plate is 06 OS 1934 and my owner is Oktay Sinanoğlu
[PERSON] My name is Aziz Sancar and the plate of my car is 47 AS 1946
[CAR] My license plate is 47 AS 1946 and my owner is Aziz Sancar
```

Aziz'e araba hiç verilmeseydi de sorun çıkmazdı. `null` kontrolü yapıldığı için kişi yalnız adını, araba yalnız plakasını söyler.

### 2.4 Tutarsızlık hatası

Asıl sorun, iki yönden biri unutulduğunda ortaya çıkar. Örneğin Oktay'a Rover verilir ama Rover'a "senin sahibin Oktay" denmez. Ya da Aziz'e araba verilmez ama Honda'ya "senin sahibin Aziz" denir. Derleme hatası çıkmaz, ama sonuç mantıksızdır. Oktay "06 plakalı aracım var" der, 06 plakalı araç bundan habersizdir. Aziz arabası olduğunu söylemez, ama 47 plakalı aracın sahibi sorulduğunda "Aziz" cevabı gelir. Bu bir tutarsızlık problemidir, yani bir hatadır (bug).

## 3. Setter'ların Birbirini Çağırması ve Sonsuz Özyineleme

### 3.1 Fikir

Tutarsızlık önemli bir hata olduğuna göre, bu hataya düşmeyi zorlaştırmak için şöyle bir yol düşünülebilir: Oktay'a araç verildiğinde araç da sahibinin Oktay olduğunu kendiliğinden öğrensin. Bir araca sahip atandığında da o kişinin aracı artık bu araç olsun. Yani 7. satırdaki `rover.setOwner(oktay)` işini kişinin `setCar` metodu, kişiye araba atama işini de arabanın `setOwner` metodu yapsın.

### 3.2 Acemice ilk deneme

Hoca, nerede takılındığını görmek için önce bilerek "acemice" bir sürüm yazdı. Paket `nyp03a` adıyla kopyalandı. Kişi tarafında araç üye alanına parametre atandıktan sonra `car.setOwner(this)` çağrıldı. `this`, `setCar` metodu hangi `Person` nesnesinde çağrıldıysa o nesnedir. Araba tarafında da `owner.setCar(this)` eklendi:

```java
// Person
public void setCar( Car car ) {
    this.car = car;
    car.setOwner(this);
}
// Car
public void setOwner( Person owner ) {
    this.owner = owner;
    owner.setCar(this);
}
```

`main` metodunda bu kez `rover.setOwner(oktay)` ve `aziz.setCar(honda)` satırları yorum satırı yapıldı. Program önce bir süre bekledi, sonra `StackOverflowError` verdi. Konsolda şu satırlar art arda tekrarlanıyordu (ekrandan, 00:15:00):

```text
at nyp03a.Car.setOwner(Car.java:13)
at nyp03a.Person.setCar(Person.java:14)
at nyp03a.Car.setOwner(Car.java:13)
at nyp03a.Person.setCar(Person.java:14)
...
```

### 3.3 Akışın adım adım izlenmesi

Hoca iki sınıfı iki Not Defteri penceresinde yan yana açtı ve akışı ekran üzerinde renkli kalemle işaretleyerek izledi:

- `oktay.setCar(rover)` çağrılır. `oktay` bir `Person` olduğu için akış `Person.setCar`'a gelir. Parametre `car` şu an `rover`'dır. `oktay`'ın `car` üye alanı başlangıçta `null`'dır.
- `this.car = car;` ile `oktay.car` artık `rover` olur.
- `car.setOwner(this)` ile `rover.setOwner(oktay)` çağrılır. `rover.owner` başlangıçta `null`'dır, atamadan sonra `oktay` olur.
- `owner.setCar(this)` ile yine `oktay.setCar(rover)` çağrılır. `rover` yeniden `oktay.car`'a atanır, sonra yine `rover.setOwner(oktay)` çağrılır...

Bu gidip gelme hiç bitmez. Her metot çağrısında belleğin yığın bölgesinde yeni bir çerçeve açılır ve o çağrının bilgileri oraya yazılır. Çağrı bitince en üstteki çerçeve atılır ve geri dönülen yerdeki durumdan devam edilir. Çağrılar hiç bitmediği için yığın bir noktada taşar ve `StackOverflowError` ile döngü kırılır. Hoca yığın mantığının veri yapıları dersinde görüldüğünü hatırlattı.

> **Ders sonrası not:** Hoca bu bölgeyi anlatırken "hip memori, yığın bellek alanı" dedi; büyük olasılıkla çağrı yığınını kastetti. Metot çağrı çerçeveleri heap bölgesinde değil, her iş parçacığının çağrı yığınında (stack) tutulur. Taşan da bu yığındır, hatanın adı buradan gelir. Heap, `new` ile oluşturulan nesnelerin bulunduğu bölgedir.

### 3.4 El sıkışma benzetmesi ve çözüm

Hoca durumu şöyle anlattı: Sınıfta olsaydık bir arkadaşınızın yanına gidip "merhaba, benim adım X" derdim. Arkadaşım elini uzatıp kendi adını söylerdi. Ben yine "merhaba, benim adım X" desem o da şaşırıp yine adını söylerdi. Böyle el sıkışmaya devam edersek birbirimizi sürekli tanıtırız ama hiç durmayız. Bir noktada "tamam, ben seni tanıdım, sen de beni tanıdın" deyip kesmek gerekir.

Kodda da aynısı yapılır. Bir insana bir araba verildiğinde insan arabayı sahiplenir, ama araca haber verme işini yalnız aracın sahibi zaten kendisi değilse yapar. Aracın sahibi zaten bensem tekrar "yeni sahibin benim" demenin anlamı yoktur. Araba tarafı da simetrik yazılır (ekrandan, 00:30:00):

```java
// Person
public void setCar( Car car ) {
    this.car = car;
    if( car.getOwner() != this )
        car.setOwner(this);
}
// Car
public void setOwner( Person owner ) {
    this.owner = owner;
    if( owner.getCar() != this )
        owner.setCar(this);
}
```

### 3.5 Düzeltilmiş akışın izlenmesi

- `oktay.setCar(rover)` çağrılır. `this.car = rover` atanır.
- `car.getOwner()`, yani `rover.getOwner()`, henüz atama yapılmadığı için `null` döndürür. Parametre olan `car` `null` değildir, ama onun sahibi `null`'dır.
- `null != this` doğrudur, çünkü `this` Oktay'dır. Koşul sağlanır ve `rover.setOwner(oktay)` çağrılır.
- `rover.setOwner` içinde `this.owner = oktay` atanır.
- `owner.getCar()`, yani `oktay.getCar()`, artık `rover` döndürür. `this` de `rover`'dır. "`rover != rover`" ifadesi yanlıştır, dolayısıyla `oktay.setCar` yeniden çağrılmaz.
- `setOwner` biter, akış `Person.setCar`'a döner. Orada yapılacak başka iş kalmadığı için o da biter. İlişki sorunsuz kurulmuş olur.

Bu sürümle `MainProgram02`, bir örnekte arabanın `setOwner` çağrısı, diğerinde kişinin `setCar` çağrısı yorum satırı yapılmış olsa da doğru çıktıyı verdi: Oktay 06 plakalı aracı olduğunu, araç da sahibinin Oktay olduğunu söyledi; Aziz ile 47 plakalı araç için de aynısı oldu. Yorum satırları geri açılıp iki yön de açıkça çağrıldığında da sorun çıkmadı. Rover'ın sahibi zaten Oktay olduğu için Rover, Oktay'ın `setCar` metodunu yeniden çağırmaz.

## 4. Kurucu, Satış ve Çapraz Atama Durumları

### 4.1 Kurucuda sahip verilmesi

`Car` sınıfının ikinci kurucusu da bir sahip atar. `new Car("06 OS 1934", oktay)` yazılıp başka hiçbir setter çağrılmazsa kurucudaki düz atama yalnız arabaya sahibini öğretir; Oktay'ın arabadan haberi olmaz. Çözüm, kurucudaki atama satırını setter çağrısıyla değiştirmektir (ekrandan, 00:50:00):

```java
public Car( String plate, Person owner ) {
    this.plate = plate;
    this.setOwner(owner);
}
```

Hoca `this.` yazılsa da yazılmasa da olacağını söyledi. Bu değişiklikten sonra `main` içinde `setCar`/`setOwner` satırları yorum satırı olduğu halde Oktay 06 plakalı aracı olduğunu, araç da sahibinin Oktay olduğunu söyledi (ekrandan, 00:35:00).

### 4.2 Satış senaryosu: eski sahip hâlâ arabayı sahipleniyor

Hoca `introduceSelf` çıktılarını programın sonuna taşıdı ve şunu denedi: Oktay'a Rover verildi (`oktay.setCar(rover)`). Sonra Oktay'ın aracını Aziz'e sattığı düşünüldü ve `aziz.setCar(rover)` çağrıldı. Çıktı şöyleydi (ekrandan, 00:40:00):

```text
[PERSON] My name is Oktay Sinanoğlu and the plate of my car is 06 OS 1934
[CAR] My license plate is 06 OS 1934 and my owner is Aziz Sancar
[PERSON] My name is Aziz Sancar and the plate of my car is 06 OS 1934
[CAR] My license plate is 47 AS 1946
```

Son üç satır mantıklıdır. Ama Oktay'ın hâlâ "06 plakalı arabam var" demesi artık doğru değildir. Arabayı alan kişi, arabanın daha önce bir sahibi varsa o kişinin arabasını `null` yapmalıdır. Bunu çift yönlü ilişkiyi bozmadan yapmak gerekir.

### 4.3 Üç olasılık ve prevOwner

Aracı üstümüze almadan önce, yani `setOwner` çağrılmadan önce, aracın bir sahibi olup olmadığına bakılır. Bu sahip için üç olasılık vardır:

- `null`'dır: arabanın henüz bir sahibi yoktur.
- `this`'tir: sahibi zaten bu kişidir.
- Başka bir insandır: o zaman o insanın artık arabası olmadığı belirtilmeli, onun arabası `null` yapılmalıdır.

Bir insanın arabası `null` yapıldığında da yeni bir tehlike doğar. `setCar` metoduna `null` parametre gelirse `car.getOwner()` çağrısı `NullPointerException` verir. Hoca "bu kodu çok verimli yazamayabilirim, daha az satırla da ifade edilebilir, ama ilk hedefim bu işten alnımın akıyla çıkmak" diyerek adım adım yazdı. Ekranda görülen ara hâli (ekrandan, 00:45:00):

```java
public void setCar( Car car ) {
    this.car = car;
    Person prevOwner = car.getOwner();
    if( prevOwner == null || prevOwner != this )
        car.setOwner(this);
    if( prevOwner != null && prevOwner != this )
        prevOwner.setCar(null);
}
```

İkinci `if` bilerek `else` yapılmadı. Arabayı kendi kendine yeniden atama durumu (Oktay'a Rover'ı tekrar vermek) da düşünüldü: bu durumda kişi kendi arabasını düşürmemelidir. Bu yüzden ikinci koşula `prevOwner != this` de eklendi. Sonra `null` parametre tehlikesi için bütün çağrılar bir `if( car != null )` bloğunun içine alındı. Araba `null` ise sahibini atamaya çalışmanın zaten anlamı yoktur.

`Car.setOwner` metoduna da benzer mantık simetrik olarak kodlandı (ekrandan, 00:55:00):

```java
public void setOwner( Person owner ) {
    this.owner = owner;
    if( owner != null ) {
        Car prevCar = owner.getCar();
        if( prevCar == null || owner.getCar() != this )
            owner.setCar(this);
        if( prevCar != null && owner.getCar() != this )
            prevCar.setOwner(null);
    }
}
```

Bu sürümle `NullPointerException` alınmadı ve satış senaryosu doğru çalıştı: Oktay yalnız adını söyledi, 06 plakalı araç sahibinin Aziz olduğunu söyledi, Aziz 06 plakalı aracı olduğunu söyledi, 47 plakalı araç hiçbir sahipten bahsetmedi.

### 4.4 Kişinin kendi eski arabası

Sonra şu denendi: Aziz'in önceden Honda'sı olsun, sonra Honda yerine Rover'ı sahiplensin (`aziz.setCar(honda); oktay.setCar(rover); aziz.setCar(rover);`) (ekrandan, 01:10:00). Çıktıda 47 plakalı araç hâlâ sahibinin Aziz olduğunu sanıyordu.

Demek ki kişiye yeni bir araç atanacağı zaman, kişinin mevcut aracı `null` değilse o araca "artık senin sahibin yok" denmelidir. Bu iş, yeni araba atanmadan önce ve bir `if( this.car != null )` kontrolüyle yapılmalıdır, çünkü kişinin henüz hiç arabası olmayabilir. Hoca burada parametre `car` ile üye alan `this.car`'ı karıştırmamak gerektiğini özellikle belirtti. İlk denemede bu işi `this.car.setOwner(null)` ile, simetriğini `Car.setOwner` içinde `this.owner.setCar(null)` ile yaptı. Program yine sonsuz döngüye girdi ve bu noktada derse ara verildi.

### 4.5 Ara sonrası çözüm: removeOwner ve removeCar

Aradan sonra hoca bu durumu `setOwner` üzerinden değil, ayrı bir metotla çözdü. `Car` sınıfına `removeOwner` metodu eklendi. `Person` çağırabilsin diye metot `public` olmak zorundadır. Ama herhangi biri herhangi bir arabanın sahibini kafasına göre silememelidir. Sahibi doğrudan `null` yapmanın tek koşulu, parametre olarak gelen kişinin arabanın mevcut sahibi olmasıdır. Simetrik olarak `Person` sınıfına da `removeCar` eklendi.

<!-- BELİRSİZ: removeOwner/removeCar metotlarının ve çağrıldıkları satırların ekranda okunur bir karesi yok; aşağıdaki kod altyazıdaki dikte edilen satırlardan kuruldu. -->

```java
// Car sınıfına eklenen metot
public void removeOwner( Person previousOwner ) {
    if( previousOwner == owner )
        owner = null;
}
// Person sınıfına eklenen metot
public void removeCar( Car previousCar ) {
    if( previousCar == car )
        car = null;
}
// Person.setCar başında:   if( this.car != null ) this.car.removeOwner(this);
// Car.setOwner başında:    if( this.owner != null ) this.owner.removeCar(this);
```

`Person.setCar` içine `this.car.removeOwner(this)` eklendikten sonra program bu senaryoda da doğru çalıştı: Oktay arabasından söz etmedi, 06 plakalı araç sahibinin Aziz olduğunu söyledi, Aziz 06 plakalı aracı olduğunu söyledi, 47 plakalı araç sahipsiz kaldı. Simetri sayesinde aynı işler kişiler yerine arabalar üzerinden (`rover.setOwner(...)` gibi) yapıldığında da çözüm geçerlidir.

> **Ders sonrası not:** Yukarıdaki parçalar birleştirilip son hâl Java 25 ile çalıştırıldı (birleştirme ajan tarafından yapıldı; birleşik kod derste tek parça hâlinde gösterilmedi). Denenen senaryolar şunlardır: tek yönden atama, kurucuda sahip verme, `oktay.setCar(rover); aziz.setCar(rover);`, `aziz.setCar(honda); oktay.setCar(rover); aziz.setCar(rover);`, `oktay.setCar(rover); rover.setOwner(aziz);`, aynı atamanın tekrarı ve `setCar(null)` / `setOwner(null)`. Hepsi tutarlı sonuç verdi. Birleşik `Person.setCar` şöyledir:
>
> ```java
> public void setCar( Car car ) {
>     if( this.car != null ) this.car.removeOwner(this);
>     this.car = car;
>     if( car != null ) {
>         Person prevOwner = car.getOwner();
>         if( prevOwner == null || prevOwner != this ) car.setOwner(this);
>         if( prevOwner != null && prevOwner != this ) prevOwner.setCar(null);
>     }
> }
> ```

### 4.6 Çapraz atama

Bir öğrencinin sorusu üzerine hoca "çapraz atama" durumunu da denedi. Normalde Oktay–Rover ve Aziz–Honda çiftleri karşılıklı atanır. Çapraz atamada ise örneğin Oktay'a Rover verilir, sonra Rover'a sahip olarak Aziz verilir (`oktay.setCar(rover); rover.setOwner(aziz);`) (ekrandan, 01:15:00). Beklenen, en son yapılan işlemin geçerli olmasıdır: Rover sahibinin Aziz olduğunu, Aziz arabasının Rover olduğunu söylemeli, Oktay ise yalnız adını söylemelidir. Sonuç beklendiği gibi çıktı. Bu durum aslında bir önceki satış durumuna benzer ve geliştirilmiş setter'lar onu da çözer.

### 4.7 Test bakış açısı

Hoca öğrencilere, programı yanlış davrandıracak ya da `NullPointerException` gibi bir hatayla çökertecek bir senaryo önermelerini istedi. Yazılım sınamasında programa hata yaptırmaya çalışan ilginç test durumları düşünmek gerekir. Derste öneri gelmedi.

## 5. Çift Yönlü İlişkiden Çıkarılan Ders

Hoca bütün bu uğraştan bir yazılım geliştirme dersi çıkardı:

- Çift yönlü ilişki tek yönlüye göre çok daha esnektir. Önceden elde kişi kaydı varken araba kaydına ulaşmak kolaydı, ama araba kaydından sahibi sorgulanamıyordu. Artık iki yönde de sorgulanabiliyor.
- Basit setter'larla kurulduğunda, tutarlılık için öbür yöndeki atamayı da yapmayı unutmamak gerekir.
- İki yönden birini unuttuğumuzda öbürünün kendiliğinden kurulmasını sağlamaya çalışmak, görüldüğü gibi çok uzun sürdü.
- Kısacası çift yönlü ilişki daha esnek ve daha güçlüdür, kurulması kolaydır, ama tutarlılığını sağlamak kolay değildir. Ek çaba gerektirir, daha masraflıdır.

> **Hocanın vurgusu:** Gerçek bir yazılım projesinde "bu ilişki şimdi tek yönlü ama ileride çift yönlü istenirse diye şimdiden çift yönlü kodlayayım" fikrini hemen kenara atın. Projeler hemen her zaman zaman açısından sıkışıktır. Müşterinin istemediği, belki hiç istemeyeceği bir şeye ekstra çaba harcamanın anlamı yoktur. Müşterinin şu an istediklerini, elinizdeki tasarımı kodlayın; istek değişirse o zaman değiştirirsiniz.

## 6. Parça-Bütün İlişkileri: Aggregation

Derste iki yeni ilişki türüne geçildi: aggregation ve composition. İkisi de parça-bütün (whole-part) ilişkisidir. Aggregation daha zayıf, composition daha kuvvetli bir parça-bütün ilişkisidir.

### 6.1 Gösterim ve gizli anlamlar

Slayttaki tanım: "Represents a weak whole-part relationship." (ekrandan, 01:20:00). Gösterimde `A` ile `B` arasındaki çizginin `A` ucunda içi boş bir elmas vardır. Elmasın bulunduğu taraf bütünü, diğer taraf parçaları simgeler: "A instances has multiple B instances. A: Whole, B: Part."

UML şemalarındaki gizli bilgiler gibi, şemada çizilmese bile aggregation şunları ima eder (ekrandan, 01:20:00):

- Elmas ucunda `1` vardır: tek bir bütün.
- Diğer uçta `*` çokluğu ve bir ok vardır. Bütün, parçalarının neler olduğunu her zaman bilir.
- Elmas da sanki `B`'den `A`'ya bir ok gibi davranır, yani elmas biçiminde bir ok başıdır. Parça da hangi bütüne ait olduğunu bilir.

Parça tarafındaki `*` sıfır ya da daha fazla demektir. İstenirse bir alt sınır, bir üst sınır ya da ikisi birden verilebilir.

### 6.2 Futbol takımı örneği

Hoca futbol takımı ile oyuncu arasındaki ilişkiyi örnek aldı ve futboldan pek anlamadığını söyleyerek kuralları öğrencilere sordu. Öğrencilerin verdiği bilgilerle derste şu kullanıldı: sahada 11 oyuncu ve en fazla 7 yedek bulunur, bir takımın kadrosunda en fazla 25 oyuncu olabilir. Bu durumda slayta `FootTeam` ile `Player` arasına çizilen ilişkinin parça tarafına `18..25` yazıldı (ekrandan, 01:25:00).

Böyle bir alt ve üst sınır varsa, bütüne parça eklemek için mutlaka ekleme metotları konmalıdır. Bu metotlar problem alanının kurallarını uygulamak (enforce etmek) zorundadır. Bu örnekte 26. oyuncu da eklenememeli, 17 oyuncuyla da kalınmamalıdır. Hoca, ilk laboratuvar oturumundaki kitaplığa kitap ekleme örneğinin de aslında bu işi yaptığını hatırlattı.

### 6.3 Otobüs hattı örneği

Slaytta "Aggregation is stronger than association, but only conceptually." yazar. Yani bu ilişkinin normal bir association'dan daha güçlü kuralları olduğu ima edilir. Örnek: "a bus route consists of at least 2 stops and there are rules for adding a new stop to a route." Şemada `Bus Route` ucunda boş elmas ve `1`, `Stop` ucunda ok ve `2..*` vardır (ekrandan, 01:20:00).

Bir otobüs hattı en az iki durak içermelidir: bir başlangıç ve bir bitiş. Üst sınır yoktur, ama durakları kafaya göre eklemek de mümkün değildir. Hoca örnek olarak "bir hat başka bir hattın tamamen üst kümesi olamaz" gibi bir kural uydurdu. Bir durağın tek başına bir anlamı olmadığı, mutlaka bir hattın parçası olması gerektiği gibi kurallar da düşünülebilir.

İlişki düz association çizgisiyle de çizilebilirdi. İki durumda da `BusRoute` tarafında `Stop` nesnelerini tutan bir dizi ya da başka bir veri yapısı bulunur. İlerleyen haftalarda generic yapılar, bağlı listeler ve map gibi yapılar görülecek. Durak ekleme ve çıkarmanın ayrıntıları müşterinin söylediği kurallara göre kodlanır. Tasarımda elmas çizmek ya da düz çizgi çizmek koda çok fark yaratmaz, ama bu bir parça-bütün ilişkisi olduğu için elmasla göstermek daha doğrudur.

## 7. Composition

Slayttaki tanım: "Similar to aggregation, but represents a stronger whole-part relation." Gösterimde bütün ucundaki elmasın içi doludur. "The strength of composition over aggregation is that in composition, the part can only belong to one whole at the same time." Örnek: `Team` ucunda dolu elmas ve `1`, `Player` ucunda ok ve `*` (ekrandan, 01:30:00).

Burada takım genel bir takım olarak düşünülür, futbol takımı olması gerekmez. Elmasın içi doluysa ilişki şu yorumu kazanır: bir parça aynı anda yalnız tek bir bütüne dahil olabilir. Otobüs örneğinde bir durak birden fazla hattın parçası olabilir, bunda hiçbir sakınca yoktur. Ama bir oyuncu belli bir anda yalnız tek bir takımın parçasıdır. Bu yüzden takım-oyuncu ilişkisini içi dolu elmasla göstermek daha doğrudur.

Hocaya göre bu ayrımı şemada unutmak çok büyük bir sorun değildir, yeter ki gereksinim kaynak kodda kodlanmayı unutulmasın. Kaynak kod, elmas içi dolu da olsa, boş da olsa, hiç olmasa da aynıdır. Ama içi dolu elmas, tasarım aşamasında bu önemli bilgiyi verir. Fark edilmişse içinin doldurulması istenir. Gelecek yıl yazılım mühendisliği dersinde görülecek kullanım senaryosu metinlerinde de bu kurallar açıkça yazılır.

### 7.1 Diğer bir yorum

Hoca daha az karşılaştığı bir yorumu da anlattı: Bazıları içi boş elmasın parçaların tek başına da bir anlamı olduğunu, içi dolu elmasın ise parçaların bütün olmadan anlamı olmadığını gösterdiğini söyler. Bu yorum kullanılırsa takım-oyuncu ilişkisi dolu elmasla gösterilmemelidir. Çünkü bir oyuncu bir takımın parçası olmasa da profesyonel ya da amatör lisanslı bir oyuncudur. Bu derste ise şu kural kullanılır: bir parça bir anda yalnız tek bir bütüne dahil olabiliyorsa içi dolu elmasla gösterilir.

### 7.2 Çokluğun kodlanması

İlişki ister association, ister aggregation, ister composition olsun, `*` tarafını kodlamak için mutlaka bir dizi, liste, yığın, kuyruk, heap, ağaç ya da graf gibi bir veri yapısı gerekir. Örnekte önce dizi kullanılacak. Dizilere araya eleman ekleme ve eleman silme işlemlerinin verimsiz olduğu bilinir. Liste gibi bir yapıda bu işler daha rahat ve verimlidir. Kodlaması zor olsa da bir kez yazılıp test edildikten sonra rahatça kullanılır. Java gibi birçok dil de hazır veri yapılarıyla gelir.

Yapısal programlama derslerinde diziler ilkel türden elemanlar içeriyordu. Java'da bir dizi ister ilkel elemanlar, ister herhangi bir sınıftan nesneler içerecek şekilde tanımlanabilir ve kullanım açısından fark yoktur.

## 8. Dizilerle Bire-Çok İlişki: Gallery Sınıfının Tasarımı

### 8.1 Şema

Örnek için bir galeri sınıfı oluşturuldu. Galeride satılmak üzere bekleyen birden fazla araba yer alır ve `Car` sınıfı yeniden kullanılır. Ayrıca dizilerin kullanımı, klasik `for` döngüsü ve onun yeni biçimi olan for-each döngüsü de örneklenir. `nyp04` şeması (ekrandan, 01:35:00):

```text
Person (1) <------> (1) Car                [Person, Car önceki gibi]
Gallery --(1)----(1)--> Person             [galleryOwner]
Gallery --(1)----(*)--> Car                [cars]

Gallery
- galleryName : String
- cars : Car[]
- carCount : int
- galleryOwner : Person
+ Gallery( name : String, owner : Person )
+ getGalleryName( ) : String
+ setGalleryName( galleryName : String )
+ addCar( car : Car ) : boolean
+ searchCar( aCar : Car ) : boolean
+ searchCar( plate : String ) : Car
+ removeCar( plate : String ) : Car
+ sellCar( plate : String, newOwner : Person ) : boolean
+ introduceSelf( ) : String

MainProgram04: + main( String[] )   (Gallery ve Car'a bağımlı)
```

`Person`–`Car` arasındaki çift yönlü bire-bir ilişki değişmez, iki sınıfın kodu da değişmez. Galeri ile araba arasındaki `1 — *` ilişkisi düz sahiplik olarak çizildi. Hocaya göre bir galeri arabaların toplamından oluşmaz, yalnız satılacak arabaları içerir. Galeri arabayı yasal işlemlerle alıp üstlenmiştir; ister galeride, ister kapalı bir otoparkta tutar. Aşırı bir kural da olmadığı için parça-bütün yerine düz çizgi seçildi.

Galerideki arabaların sahibi kim olacak? İki seçenek de kabul edilebilir: araba galeriye eklendiğinde sahibi galeri sahibi yapılır ya da sahibi `null` bırakılır. Hoca ikincisinin belki daha doğru olduğunu söyledi.

### 8.2 Üye alanlar

Her galerinin bir adı vardır. Şemada `1 — *` yazıp diziyi ayrıca göstermeseniz bile bir dizinin bulunması gerektiği anlaşılır. Dizi ancak sabit kapasiteyle oluşturulabilir, örneğin 50 araçlık. Ama bu, belli bir anda bütün kapasitenin dolu olduğu anlamına gelmez. Bu yüzden galeride o an kaç araba olduğu ayrıca tutulmalıdır. Yeni araba geldiğinde dizinin hangi gözüne yazılacağını tutmak için de bir indis gerekir. `carCount` bu iki amaca birden hizmet eder: iş mantığı için ("galeride kaç araba var?") ve dizi indisi olarak.

Her galerinin bir de sahibi vardır (`galleryOwner`, bire-bir). Sahipsiz ya da isimsiz galeri olamaz. Bu yüzden kurucu galerinin adını ve sahibini parametre olarak alır. Galeri adı değişebileceği için getter ve setter vardır.

### 8.3 addCar neden başarısız olabilir?

`addCar` eklenecek araba nesnesini parametre olarak alır ve `boolean` döndürür: işlem başarılıysa `true`, başarısızsa `false`. Hoca, çoklu sahiplik ilişkilerinde söylenmese bile dikkat edilmesi gereken iki temel durum olduğunu vurguladı:

- Dizi kullanılıyorsa dizide yer kalmamış olabilir.
- Bir parça aynı bütüne yalnız bir kez eklenebilir. Aynı arabayı bir galeriye iki kez eklemek doğru değildir; bu durumda da işlem başarısız olmalı ve `false` döndürmelidir.

Java'da dizinin kapasitesi de aşılabilir. Daha geniş kapasiteli yeni bir dizi oluşturulur, eski dizideki bütün elemanlar yeni diziye kopyalanır, sonra yeni dizi üye alana atanır. Dizi bu şekilde genişletilirse `addCar`'ın `false` döndürdüğü tek durum aynı aracın yeniden eklenmeye çalışılması olur. Bir de plaka sahtekârlığı vardır: iki farklı araba nesnesi aynı plakayı taşıyor olabilir; bu durumda da eklenmemelidir.

### 8.4 Nesne kimliği ve tekil tanımlayıcı

Burada nesne kimliği (object identity) ile tekil tanımlayıcı (unique identifier) ayrımı devreye girer. Yalnız plaka üzerinden kontrol edilirse, aynı plakalı iki farklı nesne de yakalanır. Nesne kimliğiyle kontrol edildiğinde ise bellekte aynı adreste bulunan aynı araba nesnesi mi diye bakılır.

Kişi-araba atamalarında karşılaştırma nesne kimliğiyle yapıldı: kişinin adı ya da kimlik numarası karşılaştırılmadı, "şu anki sahip, eski sahiple aynı nesne mi" diye bakıldı. Galeri örneğinde ise tekil tanımlayıcı üzerinden kontrol daha geniş kapsamlıdır, çünkü plaka sahtekârlığı gibi durumları da yakalar.

> **Hocanın vurgusu:** Bir sınavda nesnenin kendisi üzerinden mi, tekil tanımlayıcı üzerinden mi kontrol yapacağınız konusunda ikilemde kalırsanız ve aksi belirtilmemişse, tekil tanımlayıcı üzerinden kontrol yapmak her zaman daha doğrudur. Kişi-araba çapraz atama gibi durumlarda ise nesnenin bizzat kendisi üzerinden kontrol yapılır.

### 8.5 Diğer metotlar

- Belli bir plakaya sahip aracın galeride olup olmadığını sorgulamak hem genel olarak hem de `addCar` içinde gerekir. Bu yüzden iş `addCar` içine gömülmez, ayrı bir metot yapılır. Plakayı verip araba nesnesine ulaşmak kendi başına anlamlı bir iştir.
- `searchCar` iki sürümlüdür. `searchCar(Car)` o nesnenin bizzat kendisi arabalar arasında varsa `true`, yoksa `false` döndürür. `searchCar(String)` o plakaya sahip araba nesnesi varsa onu, yoksa `null` döndürür.
- `removeCar(String)` verilen plakadaki aracı galeriden çıkarır ve geriye `Car` döndürür. Araba diziden silinse de nesneye hâlâ ihtiyaç olabilir. Örneğin hurdaya çıkarılacak bir aracın bir taşıt bilgi sisteminden de silinmesi gerekebilir. Metot "bu aracı kendimden çıkardım, al, ne yapacaksan yap" der.
- `sellCar` bir aracı yeni bir kişiye satar ve başarılıysa `true` döndürür. Araç ancak galeride varsa satılabilir.
- `introduceSelf` galerinin adını, sahibini ve galeride kaç araç bulunduğunu söyler.

**Soru (hocanın kendi sorusu):** `removeCar` `Car` yerine `boolean` döndürebilir mi, iki sürüm birlikte yazılabilir mi?

**Cevap:** Silme başarılıysa `true`, değilse `false` döndüren bir sürüm de düşünülebilir; örneğin o plakada araba yoksa silme başarısız olur. Ama iki sürüm birlikte yazılamaz. Parametreleri aynı olup yalnız geri dönüş türü farklı olan aynı adlı iki metot derleme hatası verir, yani bu doğru bir aşırı yükleme (overload) değildir. Böyle bir seçimde nesnenin kendisini döndürmek daha mantıklıdır. `boolean` yalnız "vardı, sildim" der. `Car` döndürülürse araba yoksa `null`, varsa nesnenin tamamı döner ve çok daha farklı işler için kullanılabilir.

### 8.6 Kapasite sınırı nasıl modellenir?

Dizinin bir maksimum kapasitesi olduğu, ama istenirse genişletilebileceği söylenmişti. Kapasite sınırının kaynağına göre tasarım değişir:

- Bir galeride belli bir anda en fazla 50 araç satışta olabilir gibi yasal bir sınır varsa ve bu sınır hangi galeri olursa olsun geçerliyse, `public final static` bir sabit kullanılabilir.
- Sınır galerinin fiziksel alanından geliyorsa (galerinin içi ve arkasındaki otopark en fazla bu kadar araç alıyorsa) normal bir `private` üye alan olarak galeri kapasitesi eklenir. Bu durumda kapasite dolduğunda dizi genişletilmez; `addCar` basitçe `false` döndürür.

Hangisinin kullanılacağını müşteri gereksinimlerde söyler.

## 9. Gallery Sınıfının Kodu

### 9.1 Dizinin length üyesi

Java'da bir dizinin kaç elemanlık yeri olduğu, yani kapasitesi, `diziAdı.length` ile öğrenilir. Sonunda parantez yoktur, bu bir üye alan erişimidir. Arka planda Java'da diziler de birer nesnedir; nesneler içeren kendisi de bir nesnedir.

Normalde üye alanlara getter metotlarla erişildiği, bunun bilgi gizleme ilkesi olduğu söylenmişti. Java dilinin tasarımcıları burada `getLength()` gibi bir metot yerine doğrudan `.length` erişimini uygun görmüş. Hoca bunun dilin çekirdeğindeki bildiği tek istisna olduğunu, programcının kendi kodunda böyle yapmaması gerektiğini söyledi.

Bir üye alan hem `public` hem `final` hem `static` ise `public` tanımlanabileceği söylenmişti. `length` `static` olamaz. Olsaydı, hangi türden kaç farklı dizi oluşturulursa oluşturulsun hepsinin kapasitesi aynı olurdu. `final` olması ise sorun değildir. Dizi "yeniden boyutlandırıldığında" aslında yepyeni bir dizi nesnesi oluşturulur ve onun kapasitesi ilk anda belirlenir. Sonradan `length = 50` gibi bir atamaya derleyici izin vermez.

> **Ders sonrası not:** Hoca `length`'in "final belki olabilir" dedi; burada büyük olasılıkla kesin bir bilgi vermek istemedi. Java dil belirtiminde dizilerin `length` alanı `public final` olarak tanımlıdır. Bir dizinin kapasitesi hiçbir zaman değişmez; "genişletme" her zaman yeni bir dizi oluşturup referansı ona yöneltmek demektir.

### 9.2 Üye alanlar, kurucu ve introduceSelf

Slayttaki kod (ekrandan, 02:05:00):

```java
package nyp04;
public class Gallery {
    private String galleryName;
    private Car[] cars;
    private int carCount;
    private Person galleryOwner;

    public Gallery( String galleryName, Person galleryOwner ) {
        this.galleryName = galleryName; this.galleryOwner = galleryOwner;
        carCount = 0;
        cars = new Car[30];
    }
    public String getGalleryName() { return galleryName; }
    public void setGalleryName(String galleryName) {
        this.galleryName = galleryName;
    }
    public String introduceSelf( ) {
        String intro = "This is a car gallery named "+ galleryName;
        intro += ",  owned by " + galleryOwner.getName();
        intro += ". There are currently " + carCount + " cars to sell.";
        return intro;
    }
```

Slayttaki not: "No constructor is run here, this is just a memory allocation for the array". `cars = new Car[30];` satırı hiçbir `Car` kurucusunu çalıştırmaz, yalnız 30 referanslık yer ayırır.

Sayısal ilkellerin varsayılan değeri zaten 0'dır. Yine de `carCount` bir indis değişkeni olduğu ve tutarlılığı önemli olduğu için hoca kurucuda açıkça `carCount = 0;` yazmayı tercih etti. Diziye ise mutlaka yer ayrılmalıdır: dizinin adı, `=`, `new`, içereceği nesnelerin sınıf adı ve köşeli parantez içinde kapasite.

Kapasitenin sabit 30 yazılması tartışıldı. "Neden 40 ya da 25 değil, `private int galleryCapacity = 30` gibi bir üye alan daha doğru olmaz mıydı?" sorusu sorulabilir. Hocaya göre Java'da bunun sakıncası azdır. Kapasiteye her zaman `cars.length` ile ulaşılabilir ve 30 sayısı kodda yalnız bir yerde geçer. Dizideki elemanları işleyen döngüler de kapasite kadar değil, araba sayısı kadar döner. Kapasitenin kurucuya üçüncü parametre olarak verilmesi belki daha şık olurdu.

### 9.3 addCar

Slayttaki kod (ekrandan, 02:10:00):

```java
public boolean addCar( Car aCar ) {
    if(!searchCar(aCar) && carCount < cars.length ){
        cars[ carCount ] = aCar;
        carCount++;
        return true;
    }
    return false;
}//end addCar
```

Slayttaki açıklama: "You can learn the size of the array this way, but not the element count of the array. Therefore we don't need a variable such as maxCar, but we need a variable such as carCount." Notta alternatif olarak `public final static int maxCar = 30;` ve `private int carCount;` verilir.

İki yazım biçimi de mümkündür. Her şey yolundaysa ekleyip `true`, değilse `false` döndürülebilir. Ya da önce olumsuz koşullar denetlenip `false`, sonra ekleme yapılıp `true` döndürülebilir. Sıra önemli değildir, yeter ki doğru sonuca ulaşılsın. Burada araba zaten yoksa ve dizide yer varsa eklenir. Araba sayısı dizinin kapasitesinden küçükse yer var demektir. Araba, dizinin `carCount` indisindeki gözüne yazılır, sayaç bir artırılır ve `true` döndürülür.

> **Hocanın vurgusu:** `dizi.length` o anda dizideki eleman sayısını değil, dizinin kapasitesini döndürür.

Hoca, `addCar` içinde nesneyi alan `searchCar(aCar)` yerine plakayı alan sürümün çağrılmasının belki daha doğru olacağını söyledi. Bu, 8.4'teki tekil tanımlayıcı tartışmasıyla uyumludur. Derste çalıştırılan sürümde araba eklenmeden önce sahibi galeri sahibi yapılıyordu; slayta bunun için `//Sahip??` notu eklendi (ekrandan, 02:30:00).

> **Ek bilgi (derste anlatılmadı):** Plaka üzerinden denetleyen bir `addCar` koşulu `searchCar(aCar.getPlate()) == null && carCount < cars.length` biçiminde yazılabilir. Böylece aynı nesne de, aynı plakayı taşıyan farklı bir nesne de reddedilir.

### 9.4 searchCar ve for-each döngüsü

Slayttaki kod (ekrandan, 02:20:00):

```java
public boolean searchCar( Car aCar ) {
    for( Car car : cars )
        if( car == aCar )
            return true;
    return false;
}
public Car searchCar( String plate ) {
    for( int i = 0; i < carCount; i++ )
        if( cars[i].getPlate().compareTo(plate) == 0 )
            return cars[i];
    return null;
}
```

Slaytta "You can overload the searchCar method, too." yazar.

Alttaki sürüm bilinen klasik `for` döngüsünü kullanır: `i` 0'dan araba sayısına kadar birer artar. `cars[i]` bir `Car` nesnesi olduğu için nokta ile onun metodu çağrılabilir. Plakası alınır ve parametre olarak gelen plakayla karşılaştırılır. Eşitse o nesne döndürülür ve metot biter. Dizinin sonuna gelinip hiçbir şey döndürülmediyse `null` döndürülür.

Hoca bu karşılaştırmayla ilgili iki iyileştirme önerdi. `compareTo` yerine `equals` kullanılabilir. Ayrıca araç plakaları büyük harfle yazılır ama kullanıcı plakayı küçük harfle girmiş olabilir; bu yüzden `compareToIgnoreCase` ya da `equalsIgnoreCase` daha iyi olabilir.

Üstteki sürüm for-each döngüsünü kullanır. Parantez içinde bir indis değişkeni yerine, dizide dolaşmak için kullanılacak geçici bir nesne tanımlanır: `Car` sınıfından, adı küçük harfle `car`. İki nokta üst üste konur ve dizinin adı yazılır. Dizi bu geçici nesneyle aynı türden değilse derleme hatası çıkar. Döngünün her yinelemesinde `car`, 0. indisten başlayarak sıradaki elemanı gösterir. `car` parametre olarak gelen nesneyle aynı nesneyse `true` döner. Döngüden çıkılıp aynı araba bulunamadıysa `false` döner.

> **Ek bilgi (derste anlatılmadı):** For-each döngüsü dizinin bütün gözlerini, yani `carCount`'tan sonraki `null` gözleri de dolaşır. `car == aCar` karşılaştırması `null` ile sorunsuz çalıştığı için burada hata çıkmaz. Ama döngü içinde `car.getPlate()` gibi bir metot çağrılsaydı boş gözlerde `NullPointerException` alınırdı.

### 9.5 removeCar ve sellCar

Slayttaki kod (ekrandan, 02:25:00):

```java
public Car removeCar( String plate ) {
    for( int i = 0; i < carCount; i++ ) {
        if( cars[i].getPlate().compareTo(plate) == 0 ) {
            Car theCar = cars[i];
            for( int j = i; j < carCount; j++ )
                cars[j] = cars[j+1];
            cars[carCount-1] = null; carCount--;
            return theCar;
        }
    }
    return null;
}
public boolean sellCar( String plate, Person newOwner ) {
    Car soldCar = removeCar(plate);
    if( soldCar != null ) {
        soldCar.setOwner(newOwner);
        return true;
    }
    return false;
}
} //end class Gallery
```

`removeCar` yine klasik `for` döngüsüyle kaç araba varsa o kadar elemana bakar ve plakaları karşılaştırır. Diziden aradaki bir elemanı silmek zahmetlidir. Silinecek elemanın sağındaki her eleman bir sola kaydırılır (shift). Sonunda dizinin sonunda aynı arabadan iki tane kalmasın diye son eleman `null` yapılır. Galeriden bir araba eksildiğini göstermek için `carCount` bir azaltılır. Silinen eleman `theCar` adlı geçici değişkende saklanır ve metodun sonunda döndürülür. Döngüden çıkılıp araba bulunamadıysa `null` döndürülür.

> **Hocanın vurgusu:** `removeCar` içinde arama yeniden yapılıyor. Aynı işi iki kez kodlamak yerine burada `searchCar` kullanılmalıdır; öylesi daha mantıklıdır.

`sellCar` para işlerini hesaba katmaz. Önce `removeCar` ile araba diziden silinir. Dizide öyle bir araba yoksa silme başarısız olur ve `null` döner. Sonuç `null` değilse arabanın yeni sahibi atanır ve `true` döndürülür, aksi hâlde `false` döndürülür.

> **Ders sonrası not:** Slayttaki `removeCar` iç döngüsü `j < carCount` koşuluyla `cars[j+1]`'i okur. Dizi tam doluyken (`carCount == cars.length`, burada 30) son adımda `cars[30]` okunur ve `ArrayIndexOutOfBoundsException` oluşur. Bu durum 30 araba eklenip bir araba silinerek Java 25 ile denendi ve hata görüldü. Koşul `j < carCount - 1` yapıldığında sorun kalmaz, çünkü son göz zaten bir sonraki satırda `null` yapılır. Düzeltilmiş hâl de aynı testle doğrulandı.

### 9.6 Para işleri tasarıma katılırsa

Slayttaki alıştırma maddeleri (ekrandan, 02:30:00) satışın ve para işlerinin nasıl ele alınacağını sorar. Hoca ayrıntıları alıştırma olarak bıraktı, ama tasarım için ipuçları verdi (bkz. Örnek Sorular).

## 10. Gallery Sınıfının Testi

Testte `Car` ve `Person` sınıfları çift yönlü sahiplik ilişkisiyle olduğu gibi kullanıldı. Hoca, satış ve çapraz atamayı da çözen son sürümü değil, bir önceki daha sınırlı sürümü kullandığını söyledi.

`MainProgram04` sırasıyla şunları yapar:

- Bir galeri nesnesi sahibiyle birlikte oluşturulur.
- Sahipsiz iki araba (BMW ve Audi) oluşturulur.
- BMW galeriye eklenir. Kapasite 30 olduğu ve araba daha önce eklenmediği için işlem başarılı olmalıdır; sonuç "operation succeeded/failed" diye yazdırılır.
- Audi de eklenir.
- Galeri kendini tanıtır. Galeride satılacak iki araba olduğunu söylemelidir. Audi'nin eklenmesi başarısız olsaydı "1 car", hatalı bir kodda belki "3 cars" yazardı.
- BMW kendini tanıtır. Derste çalıştırılan `addCar` arabanın sahibini galeri sahibi yaptığı için BMW sahibinin galeri sahibi olduğunu söyledi. Hoca iki seçeneğin de kabul edilebilir olduğunu yineledi.
- BMW nesnenin kendisiyle aranır; bulunmalıdır.
- Audi plakasıyla galeriden silinir; silme başarılı olmalıdır.
- Audi yeniden aranır. Bu kez bulunamamalıdır. Arama `false` döndürürse "doğru biçimde başarısız oldu" yazdırılır, `true` döndürürse test başarısız sayılır.

Çalıştırıldığında sonuçlar mantıklı çıktı: ekleme başarılı, galeride iki araç var, araç sahibi galeri sahibi, arama başarılı, silme başarılı, son işlem doğru biçimde başarısız. Hoca `searchCar`'ın iki sürümünü yazarak metodu "override etmiş, pardon overload etmiş" olduğunu söyleyip kendini düzeltti: aynı adlı metodun farklı parametrelerle yazılmasına aşırı yükleme (overload) denir.

> **Ders sonrası not:** Slayttaki `Gallery` kodu, son sürüm `Person`/`Car` sınıflarıyla birlikte Java 25 ile çalıştırıldı (test verisi ajan tarafından seçildi). İki araba eklendi, aynı araba tekrar eklenemedi, nesne ve plaka aramaları, silme, silinen arabanın bulunamaması, `sellCar` ile satış ve olmayan plakanın satılamaması beklendiği gibi çalıştı. 31 araba eklenmeye çalışıldığında 30'u eklendi.

## Örnek Sorular

**1. (derste sözlü, 00:06:10)** `Car` sınıfında `null` kontrolünü unutmamak için yalnız plaka alan kurucuyu silip her arabanın bir sahibi olmasını zorlamak doğru olur mu?

> **Çözüm:** Hayır. Yalnız iki parametreli kurucu kalsa bile biri ikinci parametreye elle `null` yazabilir. Kod derlenir ama atanmış bir sahip yoktur. Bu yüzden `introduceSelf` gibi metotlarda `null` kontrolü her zaman yapılmalıdır.

**2. (derste sözlü, 00:11:08)** Tutarsızlık hatalarını önlemek için, bir kişiye araba verildiğinde arabanın da sahibini kendiliğinden öğrenmesi ya da bir arabaya sahip atandığında kişinin de arabasını öğrenmesi sağlanabilir mi?

> **Çözüm:** Evet. `setCar` ve `setOwner` birbirini çağıracak şekilde yazılır. Ama çağrı koşulsuz olursa sonsuz özyineleme ve `StackOverflowError` oluşur. Koşul eklenmelidir: `if( car.getOwner() != this ) car.setOwner(this);` ve `if( owner.getCar() != this ) owner.setCar(this);`. Satış ve eski arabanın bırakılması gibi durumlar için ayrıca `prevOwner`/`prevCar` kontrolleri ve `removeOwner`/`removeCar` metotları gerekir (bkz. Bölüm 3 ve 4).

**3. (derste sözlü, 01:37:30)** Bir galeriye araba ekleme işlemi neden başarısız olabilir?

> **Çözüm:** İki nedenle: (1) dizi kullanılıyorsa dizide yer kalmamış olabilir; (2) aynı araba galeriye ikinci kez eklenmeye çalışılıyor olabilir. Dizi genişletilecek biçimde yazılırsa tek başarısızlık nedeni tekrar eklemedir. Aynı plakayı taşıyan farklı bir nesne (plaka sahtekârlığı) da reddedilmelidir.

**4. (derste sözlü, 01:44:56)** `removeCar` metodu silinen arabayı mı döndürmeli, yoksa başarılı/başarısız bilgisini `boolean` olarak mı? İki sürüm aynı adla birlikte yazılabilir mi?

> **Çözüm:** Nesnenin kendisini döndürmek daha kullanışlıdır: araba yoksa `null`, varsa nesnenin tamamı döner ve çağıran onu başka işlerde kullanabilir. İki sürüm birlikte yazılamaz. Parametreleri aynı olup yalnız geri dönüş türü farklı olan aynı adlı iki metot derleme hatası verir.

**5. (ekrandan, 02:30:00)** "Exercise/HW: How to sell a car? Implement the sellCar method."

> **Çözüm:** Derste slaytta verildi (ekrandan, 02:25:00). Önce `removeCar(plate)` ile araba galeriden çıkarılır. Sonuç `null` değilse `soldCar.setOwner(newOwner);` ile yeni sahip atanır ve `true` döndürülür, aksi hâlde `false` döndürülür. Kod Bölüm 9.5'tedir.

**6. (ekrandan, 02:30:00)** "Exercise/HW: What if you need to take the money issues into account?"

> **Çözüm:** Derste kod verilmedi, yalnız tasarım ipuçları verildi:
>
> - Her arabanın bir alış ve bir satış fiyatı olmalı, galerinin de bir bütçesi olmalıdır.
> - Galeriye araba eklemek aslında galerinin arabayı satın alması demektir. `addCar` yalnız galerinin bütçesi yetiyorsa eklemeli ve alış fiyatını bütçeden düşmelidir; bu, `addCar`'ın tutarlılık kontrollerine eklenen yeni bir koşuldur.
> - Satışta galerinin bütçesi satış fiyatı kadar artırılır.
> - İstenirse `Person` sınıfına da bir bütçe (`balance`, `funds` gibi) eklenir. Daha kapsamlı bir tasarımda `BankAccount` ya da `Wallet` gibi bir sınıf hem kişiye hem galeriye üye olarak verilebilir, ya da galeri sahibinin cüzdanı galerinin bütçesi sayılabilir.

**7. (derste sözlü, 01:13:51)** Şimdiye kadar yazılan kodu yanlış davrandıracak ya da bir istisnayla çökertecek bir test senaryosu önerin.

> **Çözüm (derste verilmedi):** Derste öğrencilerden öneri gelmedi. Ajanın bulduğu ve Java 25 ile denediği bir örnek: galeri tam doluyken (30 araba) herhangi bir araba `removeCar` ile silinmeye çalışılırsa slayttaki iç döngü `cars[30]`'u okur ve `ArrayIndexOutOfBoundsException` oluşur (bkz. Bölüm 9.5'teki ders sonrası not). Bir başka örnek: `searchCar((String) null)` çağrısında `compareTo(null)` `NullPointerException` verir. Plaka parametresi için de `null` kontrolü eklenmelidir.

## Dersin Toparlaması

Ders, önceki haftanın tek yönlü kişi-araba ilişkisini çift yönlü hâle getirerek başladı. İki yönü elle kurmak kolaydır ama unutulursa tutarsızlık hatası doğar. Bir yönden kurulan ilişkinin öbür yönü kendiliğinden kurmasını sağlamak için setter'lar birbirini çağıracak şekilde yazıldı. Önce sonsuz özyineleme ve `StackOverflowError` görüldü, sonra "zaten ilişkiliysem tekrar çağırma" koşuluyla zincir kesildi. Kurucu, satış ve çapraz atama durumları `prevOwner`/`prevCar` kontrolleri ve `removeOwner`/`removeCar` yardımcı metotlarıyla çözüldü. Bu uğraşın dersi şudur: çift yönlü ilişki güçlü ama masraflıdır, müşteri istemedikçe baştan kurulmamalıdır.

İkinci bölümde parça-bütün ilişkileri işlendi. Aggregation (içi boş elmas) parçayı bütüne eklemenin kuralları olduğunu ima eder. Composition (içi dolu elmas) bir parçanın aynı anda tek bir bütüne ait olabileceğini söyler. Son bölümde bire-çok ilişkinin dizilerle kodlanması `Gallery` sınıfıyla gösterildi: kapasite ile eleman sayısı ayrımı (`cars.length` ve `carCount`), tekrar eklemeyi engelleyen `addCar`, aşırı yüklenmiş `searchCar`, for-each döngüsü, kaydırmalı `removeCar` ve `sellCar`. Hoca bir sonraki konunun kalıtım (inheritance) ve soyut sınıflar olacağını, bu konuların önce laboratuvarda uygulamalı görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
