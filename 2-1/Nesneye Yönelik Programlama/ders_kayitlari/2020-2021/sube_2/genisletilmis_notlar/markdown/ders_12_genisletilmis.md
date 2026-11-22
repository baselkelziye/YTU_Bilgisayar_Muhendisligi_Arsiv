# Ders 12 Genişletilmiş Notu: Kalıtım, Çok Biçimlilik ve Soyut Sınıflar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Galeri Örneğine Dönüş: removeCar, searchCar ve Metot İmzası
- 2. Kalıtım İlişkisi
- 3. Kalıtımın Kuralları ve Kalıtım Hiyerarşisi
- 4. Genelleşme-Özelleşme ve Yerine Geçebilirlik
- 5. Kalıtımın Yanlış Kullanımı ve Değerlendirilmesi
- 6. Çok Biçimlilik (Polymorphism) ve super
- 7. Person - Employee - Manager Örneğinin Kodlanması
- 8. Üst Sınıf Türünden Dizi ve Overloaded Constructor
- 9. Object Sınıfı ve toString
- 10. Company.main İçin Sıralama Şeması
- 11. Private Metotların Yeniden Tanımlanması ve final Sınıflar
- 12. Kalıtımın Doğru Kurulması: Hasta ve Doktor
- 13. Soyut Sınıflar ve Soyut Metotlar
- 14. Çoklu Kalıtım ve Elmas Problemi
- 15. Soyut Sınıf Tasarımı ve Kodlaması: Anaokulu Malzemeleri
- 16. Soyut Sınıf Olmadan Aynı Tasarım ve Birim Sınaması
- Örnek Sorular
- Dersin Toparlaması

## 1. Galeri Örneğine Dönüş: removeCar, searchCar ve Metot İmzası

Ders, önceki derste kodlanan `Gallery` sınıfının `removeCar` metoduna dönülerek açıldı. Galeri arka planda araçları bir dizide tuttuğu için bir aracı silerken önce aracın hangi indiste olduğunu bulmak gerekir. Dizide bir eleman silinince onun sağındaki bütün elemanların bir sola kaydırılması (ötelenmesi) gerekir. Hoca, ileride görülecek generic listelerde ise listeye "bu nesneyi sil" demenin yeteceğini hatırlattı.

Sınıfta iki `searchCar` metodu zaten vardı: biri `Car` alıp `boolean` döndüren, diğeri plaka alıp `Car` (yoksa `null`) döndüren. Hoca, aracın dizideki indisini döndüren üçüncü bir metot eklemeyi bilerek seçmediğini anlattı. Sahiplik altyapısı dizi yerine liste ya da başka bir veri yapısıyla da kurulabilir. Onların hiçbirinde aracın kaçıncı sırada olduğunu bilmeye ihtiyaç yoktur. Hoca, veri yapısından bağımsız, onun etkisini dışarıya hissettirmeyen bir arayüz vermek istediğini söyledi.

Ayrıca bir aracın dizinin kaçıncı gözünde olduğu normal bir kullanıcıyı ilgilendirmez; yalnız galeri sınıfını ilgilendirir. Bu yüzden böyle bir metot yazılacaksa `private` olması yeterlidir. Hoca bunu denedi (ekrandan, 00:10:00):

```java
public boolean searchCar( Car aCar ) {
    for( Car car : cars )
        if( car == aCar )
            return true;
    return false;
}
private int searchCar( String plate ) {
    return 0;
}
public Car searchCar( String plate ) {
    for( int i = 0; i < carCount; i++ )
        if( cars[i].getPlate().compareTo(plate) == 0 )
            return cars[i];
    return null;
}
```

Eclipse burada hata verdi: overload işlemi geçerli değildir. Metot imzaları karşılaştırılırken görünürlük (`public`/`private`) ve dönüş tipine bakılmaz. Metot imzası yalnız metodun adı ve parametrelerinden oluşur. `private int searchCar(String)` ile `public Car searchCar(String)` aynı imzaya sahiptir.

Plakadan aracın kendisine erişmek daha önemli bir ihtiyaç olduğu için `Car` döndüren metot korunur. Sonuçta en makul çözüm, `removeCar` içinde aracın yerini yeniden aramaktır. Aynı arama mantığı iki kez kodlanmış olur, ama dizi kullanıldığı için buna mecburuz. Hoca, bu sakıncaların bağlı liste (linked list) gibi veri yapıları kullanıldığında ortadan kalkacağını söyledi.

## 2. Kalıtım İlişkisi

Ardından kalıtım konusuna geçildi. Hoca, işin pratik kısmının laboratuvarda görüldüğünü, teorik kısmın bu derste pekiştirileceğini belirtti.

Kalıtım, mevcut bir sınıftan yeni ve daha özelleşmiş sınıflar oluşturmanın mekanizmasıdır (ekrandan, 00:15:00). Gerçek dünyada bir çocuk ebeveynlerinden genetik özelliklerini alır. Nesneye yönelik programlamada da benzer bir şey geçerlidir. Slaytta kalıtımın aslında sınıf düzeyinde bir ilişki olduğu vurgulanır.

Hoca "miras" yerine "kalıtım" (inheritance relationship) demeyi tercih ettiğini söyledi. Mirası reddetmek mümkündür, kalıtımı reddetmek mümkün değildir. Kişi gözünü kalıtımla almıştır ve "bu gözü almıyorum" diyemez. Ama isterse renkli bir lens takabilir; bu, göz rengini bir bakıma yeniden tanımlamak (override) olur. Benzer şekilde alt sınıf, üst sınıftan "şu üyeleri almıyorum" diyemez. Hepsini alır, private üyeler dahil. Fakat private üyelere doğrudan erişemez.

Gösterim: mevcut bir A sınıfından kalıtımla B sınıfı türetildiğinde ok, yeni sınıftan (B) mevcut sınıfa (A) doğru çizilir ve içi boş, kapalı bir üçgen ok ucu konur. Slaytta okun yönüne dikkat edilmesi uyarısı yer alır.

Bir sınıf, kendisinden kalıtımla türetilen sınıfların neler olduğunu bilmez, bilmemelidir de. A'dan B'ye ayrıca bir sahiplik ya da kullanma ilişkisi tanımlamak yanlış olur. Okun yönü aynı zamanda bağımlılığın yönüdür: B, A'nın bütün üye alanlarını ve metotlarını aldığı için A'yı bilir; A ise B'yi bilmez.

Terimler (ekrandan, 00:15:00):

- A: parent class (ebeveyn sınıf), super class (üst sınıf), base class.
- B: child class (çocuk sınıf), sub class (alt sınıf), derived class.

Hoca İngilizcede genelde super class / sub class, Türkçede üst sınıf / alt sınıf demeyi tercih ettiğini söyledi.

Slaytta kalıtımın işleyişi de özetlenir: üst sınıfın bütün üye alanları ve metotları çocuğa aktarılır, ama çocuk kalıtımla gelen private üyelere erişemez. `protected` üyelere çocuklar erişebilir, diğer sınıflar erişemez.

## 3. Kalıtımın Kuralları ve Kalıtım Hiyerarşisi

Slayttaki kurallar (ekrandan, 00:20:00):

- Alt sınıflar üst sınıftan gelen bir üyeyi reddedemez.
- Ancak kalıtımla gelen metotların gövdesi değiştirilebilir. Buna **overriding** denir.
- Dikkat: `final` metotlar yeniden tanımlanamaz.
- Alt sınıflara yeni üyeler eklenebilir.
- Bir alt sınıf başka sınıfların üst sınıfı olabilir. Böyle oluşan ağaç yapısına kalıtım hiyerarşisi ya da kalıtım ağacı denir.

Hoca override için daha teknik bir benzetme de verdi: bir ebeveynin koltukta oturma biçimini beğenmeyen çocuk, kendi oturma davranışını değiştirebilir. Göz rengi bir nitelik (üye alan) olduğundan, metot için oturma davranışı daha doğru bir örnektir. Override'ın Türkçesi için "metodu yeniden tanımlama" demeyi tercih ettiğini, "ezmek" kelimesini pek sevmediğini söyledi.

`final` anahtar kelimesi: `final` üye alanlar bir kez değer alır ve sonra değiştirilemez. `final` metotlar ise alt sınıflarda gövdesi yeniden tanımlanamayacak metotlardır. Üst sınıf, kendisinden hangi alt sınıfların türetileceğini bilmez ve "benden şöyle bir alt sınıf türetilmesin" diye bir engel koyamaz. Koyabileceği tek engel, kritik bir metodunu `final` yaparak "bu metot alt sınıflarda değiştirilmemeli" demektir.

Slayttaki örnek ağaç: `Person` sınıfından `Student`, `Employee` ve `Retired` türetilmiştir. Bu üç sınıf ortak atadan türedikleri için kardeş sınıflardır (İngilizcede sister class). `Employee`'den de `Director` ve `PartTime` türetilmiştir. `Employee` hem alt sınıf hem üst sınıf özelliği taşır.

### 3.1 Kırılgan üst sınıf problemi

Hoca kalıtım ağacını çok derin tutmamayı önerdi. Üst sınıftaki bütün üyeler alt sınıflara aktarıldığı için, ağaç derinse hiyerarşinin kökündeki bir metotta yapılan değişiklik alt sınıflara aktarılırken onların kodunda bir hata (bug) açığa çıkarabilir. Bu bir derleme hatası değildir, ama ağaç derinleştikçe değişikliğin dalga dalga yan etkilerinin yayılma olasılığı artar. Buna kırılgan üst sınıf problemi denir.

Kaç düzey olmalı sorusunun kolay bir yanıtı yoktur. Hoca en fazla beş düzey önerdi. Kendimizi altı-yedi düzeylik bir kalıtım ilişkisi kurarken görürsek daha iyi bir tasarım yapıp yapamayacağımızı düşünmemiz gerekir.

## 4. Genelleşme-Özelleşme ve Yerine Geçebilirlik

Kalıtıma genelleşme-özelleşme ilişkisi de denir. Alt sınıf, üst sınıfın daha yetenekli, daha özelleşmiş, daha fazla üye içeren bir sürümüdür. Üst sınıf ise alt sınıfın daha genel, daha az yetenekli bir sürümüdür, çünkü alt sınıfta tanımlanan yeni metotlar onda yoktur.

Buna bağlı olarak **yerine geçebilirlik ilkesi** vardır: alt sınıfta üst sınıfın bütün üyeleri ve daha fazlası bulunduğundan, üst sınıftan bir nesnenin beklendiği her bağlamda alt sınıftan bir nesne kullanılabilir. Bu yüzden kalıtıma özellikle akademik kaynaklarda **is-a** ilişkisi de denir.

Hocanın örneği: bir `Araba` sınıfımız bizi bir yerden bir yere götürür. Gideceğimiz yer engebeliyse dört çeker bir cipe, en hızlı şekilde gitmek istiyorsak bir yarış arabasına, kalabalık bir aileyle tatile çıkıyorsak çok yük taşıyan bir station wagon araca ihtiyacımız olur. Her cip, her yarış arabası, her station wagon aynı zamanda bir arabadır: "a jeep is a car". Benzer şekilde bir yazıcı sınıfından nokta vuruşlu, lazer ve mürekkep püskürtmeli yazıcılar türetilebilir. Sürekli form basılıyorsa nokta vuruşlu yazıcı gerekir. Her mürekkep püskürtmeli yazıcı aynı zamanda bir yazıcıdır.

## 5. Kalıtımın Yanlış Kullanımı ve Değerlendirilmesi

Kalıtım güçlü bir ilişkidir ama yalnız gerçekten gerektiğinde kullanılmalıdır, çünkü ağır sıklet bir ilişkidir. Sahiplik ya da parça-bütün ilişkisinde iki nesne arasındaki ilişki istenildiği gibi başka nesnelere aktarılabilir. Galeri örneğinde bir kişinin arabası alınıp başka bir kişiye verilmişti. Kalıtımda ise ilişki kodlama düzeyinde kurulur ve derleme aşamasında karara bağlanır. Kalıtım sınıf düzeyinde, diğer ilişkiler nesne düzeyindedir.

### 5.1 Düğme rengi örneği

Hoca şu örneği verdi (ekrandan, 00:25:00). Etiketi olan, tıklanınca içeri gömülüp bırakılınca geri çıkan, tıklandığında belirli bir metodu çalıştıran güzel bir GUI düğmesi sınıfı yazdınız. Müşteri, bütün düğmelerin gri olduğundan yakınıp kendi kurumsal renklerinde düğmeler istedi. `GUI Button` sınıfından kalıtımla `Red`, `Yellow`, `Purple`, `Blue` gibi sınıflar türetmek akla gelebilir. Bu yanlıştır, çünkü renklerin sonu gelmez: 16,7 milyon renk vardır. En azından 256 renklik bir palet istense 256'dan fazla sınıf kodlamak gerekir.

Doğru modelleme şöyledir: bir `RGB` sınıfı oluşturulur (`- red, green, blue : int`). Bütün renkler kırmızı, yeşil ve mavinin 0-255 arasındaki yoğunluklarının birleşimiyle elde edilir. `GUI Button` sınıfına `- color : RGB` alanı, yani bir sahiplik ilişkisi konur. Düğmenin `paint` metodunda önce o renkte bir fırça alınır ve düğme o renge boyanır.

```text
Yanlış (incorrect use of inheritance):     Doğru (correct modeling):
            GUI Button                       GUI Button
          /     |      \                     - color : RGB
       Red   Yellow   Purple                     | 1
                                                 v 1
                                               RGB
                                               - red, green, blue : int
```

### 5.2 Kalıtım ilişkisinin değerlendirilmesi

Slayttaki değerlendirme (ekrandan, 00:30:00):

- Kalıtım, çalışma anında değiştirilemeyen sınıf düzeyinde bir ilişkidir.
- Deneyimli nesneye yönelik modelleyiciler kalıtımı yalnız açık bir genelleşme-özelleşme ilişkisi varsa seçer. Aksi hâlde association, composition ya da aggregation (nesne düzeyindeki ilişkiler) kullanılır.
- Alternatif olarak arayüz gerçekleştirme (interface implementation) kullanılabilir. Bu konu daha sonra işlenecek. Arayüzler bazı yerlerde daha fazla, bazı yerlerde daha az yetenek sunar; modelleme bunlara uygunsa kalıtım yerine arayüz tercih edilebilir.
- Kalıtımın doğru kullanımı her tasarım kalıbının (design pattern) önemli bir parçasıdır. Tasarım kalıpları, sık karşılaşılan modelleme problemlerine düzgün, doğru ve esnek çözümler sunar. Hoca, yazılım alanında çalışacak herkese nesne yönelimini iyice oturttuktan sonra bu konuda uzmanlaşmayı önerdi ve konunun klasik kaynağı olarak "Dörtlü Çete" (Gang of Four) kitabını andı.

## 6. Çok Biçimlilik (Polymorphism) ve super

Çok biçimlilik, kalıtımdaki override mekanizmasının bir sonucudur. Hoca iki bilgiyi hatırlattı: kalıtımla gelen metodun gövdesi değiştirilebilir (`final` metotlar hariç) ve alt sınıftan bir nesne, üst sınıftan bir nesnenin beklendiği her yerde kullanılabilir (ekrandan, 00:35:00).

Örnek: `Person` sınıfının `+ introduceSelf() : String` metodu var. Kişi kendini "benim adım şudur" diye tanıtır. `Student`, `Employee` ve `Retired` sınıfları bu metodu override eder. Öğrenci adını söyler, çünkü her öğrenci bir insandır; ek olarak hangi okulda, hangi sınıfta okuduğunu da söyler. Çalışan, hangi şirkette ne kadar süredir hangi pozisyonda çalıştığını; emekli ise nerede ne kadar çalıştıktan sonra emekli olduğunu da ekler.

Şimdi `Person` türünden bir dizi oluşturalım. Bu dizinin elemanları `Person`, `Student`, `Employee` ya da `Retired` nesnelerinin herhangi bir karışımı olabilir. Dizinin üzerinde dolaşıp hepsinin `introduceSelf` metodunu çağırırsak ne olur? Dizinin türü `Person` olduğu için hepsi `Person` gibi mi davranır, yoksa her biri en özelleşmiş hâliyle mi?

Doğrusu ve birçok dilde gerçekleşen, nesnelerin kendi özelleşmiş hâlleriyle davranmasıdır. Dizide bir `Student` nesnesi varsa kendini öğrenci olarak tanıtır. Çalışma anında metodun doğru sürümünün çalıştırılmasına **çok biçimlilik** (polymorphism) denir.

Hoca, bu mekanizmanın bildiği nesneye yönelik dillerin hepsinde varsayılan olarak açık olduğunu, yalnız C#'ta varsayılan olarak kapalı geldiğini söyledi. Eclipse'te bir alt sınıfta üst sınıf metodu yazıldığında başına otomatik olarak `@Override` satırı eklenir. `@` ile başlayan satırlara **annotation** denir. Bunlar derleyiciye ya da kimi durumda Java sanal makinesine bir işarettir. Annotation'ları işleyerek çeşitli işler yapan kodlar da yazılabilir; birim sınama araçları bunlardan biridir. Java'da çok biçimlilik zaten varsayılan olarak açıktır ve `@Override` satırını yazmak zorunlu değildir.

> **Ders sonrası not:** Hoca, `@Override` yazılınca çok biçimliliğin açık olduğunu, C#'ta bu işaret yazılmazsa kapalı olduğunu anlattı. Java'da `@Override` çok biçimliliği etkilemez; yalnız derleyiciye metodun gerçekten bir üst sınıf metodunu yeniden tanımladığını denetletir (imza yanlış yazılırsa derleme hatası verir). C#'ta `override` bir annotation değil, anahtar kelimedir ve üst sınıftaki metodun `virtual` olarak işaretlenmesi gerekir.

### 6.1 super işaretçisi

Bazen yeniden tanımlanan metodun içinde üst sınıftaki sürümü de kullanmak isteriz. Öğrenci kendini bir insan gibi tanıtıp ek olarak okulunu ve sınıfını söyleyecekse, `Person`'daki tanıtım beş-altı üye alanı içeriyorsa, öğrencide bu alanların hepsini yeniden yazmak gerekmez. Metot alt sınıfta override edilse de override edilmemiş hâline hâlâ erişilebilir. Bunun için `super` işaretçisi vardır. `super`, `this`'ten sonra Java'daki ikinci özel işaretçidir. Slaytta da bu soru sorulur: override edilmiş bir metodun üst sınıftaki önceki sürümüne nasıl erişiriz? Yanıt: `super` işaretçisiyle.

## 7. Person - Employee - Manager Örneğinin Kodlanması

Slayttaki UML sınıf şeması (ekrandan, 00:40:00):

```text
Person
  - name : String
  + Person( String )
  + getName( ) : String
      ^ (kalıtım)
Employee                                   Company
  - salary : int                             + main( String[] )
  + Employee( name: String, salary: int )    (Employee ve Manager'a
  + getSalary( ) : int                        kesikli okla bağlı)
  + setSalary( int )
      ^ (kalıtım)
Manager
  - bonus : int
  + Manager( name: String, salary: int )
  + setBonus( int )
  + getSalary( ) : int
```

Tasarım kararları şöyle anlatıldı:

- `Person` sınıfına `setName` metodu bilerek konmadı. Hoca, insanların adını değiştirmenin ancak bir mahkeme süreciyle mümkün olduğunu düşünerek bunu tercih ettiğini söyledi.
- Bir çalışan aynı zamanda bir insandır, adı olmalıdır. Maaşsız çalışan da olmaz. Bu yüzden `Employee` constructor'ı hem ad hem maaş alır. Maaş için getter ve (zam olabileceği için) setter vardır.
- `Manager`, `Employee`'den türer. Aylık maaşa ek olarak aylık bonusu olabilir; bu sıfır da olabilir. Constructor'a ad ve maaş verilir, bonus için setter konur. Alternatif olarak iki constructor ya da tek bir üç parametreli constructor da tanımlanabilirdi; üç seçenek de geçerlidir.
- Yöneticinin `getSalary()` metodu, çalışan olarak maaşı ile bonusunun toplamını döndürmelidir.
- `Company` sınıfının `main` metodu `Employee` türünden bir dizi oluşturup içine `Employee` ve `Manager` nesnelerini karışık olarak koyar ve ad ile maaşlarını yazdırır.

### 7.1 extends ve constructor kuralı

Kalıtım `extends` anahtar kelimesiyle kurulur: `public class Employee extends Person`. Bunu yazar yazmaz Eclipse bir hata gösterdi. Hoca kuralı şöyle verdi:

> **Hocanın vurgusu:** Üst sınıfta varsayılan olmayan bir constructor varsa alt sınıfta da mutlaka varsayılan olmayan bir constructor olmalıdır ve bu constructor içinde ilk iş olarak üst sınıfın constructor'ı çağrılmalıdır.

`Person`'da `setName` yoktur, ama constructor vardır. Bu yüzden `Employee` constructor'ında yapılan ilk şey, üst sınıfın constructor'ını çağırıp gelen `name` bilgisini onun üzerinden aktarmaktır. Bundan sonra `Employee`'nin diğer üyeleri atanabilir. Derste yazılan kod (ekrandan, 00:50:00):

```java
public class Employee extends Person {
    private int salary;   // derste bir ara protected yapıldı, sonra private'a dönüldü

    public Employee( String name, int salary ) {
        super( name );
        this.salary = salary;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }
}
```

Hoca `super( name );` satırını aşağı taşıyınca derleme hatası aldığını gösterdi. Gerekçe olarak her constructor çağrısının bellekte yeni bir nesne oluşturulması anlamına geldiğini söyledi. Önce `salary` atanıp sonra `super` çalıştırılsaydı, nesnenin `Person` kısmı bellekte oluşturulurken atanan maaş boşa gidecekti.

> **Ders sonrası not:** Derste kullanılan Java sürümünde (Eclipse, Java 15) `super(...)` ilk komut olmak zorundaydı. Java 25'te (JEP 513, esnek constructor gövdeleri) `this` nesnesini kullanmayan komutlar ve alan atamaları `super(...)`'dan önce yazılabilir. Bu notu hazırlarken `this.s = s; super(n);` biçimindeki bir constructor Java 25 ile derlendi. `super(...)` yine yalnız bir kez çağrılabilir.

`Manager` sınıfı Eclipse'in yeni sınıf penceresinde üst sınıf alanına `Employee` yazılıp "üst sınıftan gelen constructor'ları ekle" seçilerek oluşturuldu. Eclipse, `name` ve `salary` alan constructor'ı ilk komutu `super(name, salary)` olacak biçimde üretti ve yapılacakları hatırlatan bir yorum ekledi. Hoca bu yorumu sildi ve bonus için setter ekledi.

### 7.2 getSalary: özyineleme tuzağı ve super.getSalary()

`Manager`'da `public int getSalary()` yazılırken bonus ile maaşın toplanması gerekiyordu:

- `return bonus + salary;` derleme hatası verir. `salary` kalıtımla gelmiş olsa da private olduğu için `Manager` onu göremez.
- `return bonus + getSalary();` derleme hatası vermez, ama istemeden bir özyineleme (recursion) yapılmış olur. `Manager`'ın `getSalary` metodu sürekli kendi kendisini çağırır ve sonsuz bir döngü ortaya çıkar.
- Gereken, `Employee` sınıfındaki `getSalary` metoduna ulaşmaktır. Metot override edildiği için override edilmemiş hâline `super.getSalary()` ile erişilir. Hoca "işin en doğrusu bu" dedi.

```java
public int getSalary() {
    return bonus + super.getSalary();
}
```

Hoca bir de geçici bir çözüm (workaround) gösterdi: `Employee`'de `salary` alanı `protected` yapılırsa `Manager`'da `bonus + salary` yazmak derleme hatası vermez. Hocaya göre `protected` üye alanlar, kalıtımda diğer sınıflar için private, alt sınıflar için public gibi davranır. Ama bu tek çözüm değildir ve hoca alanı yeniden private yapıp `super.getSalary()` yolunu tercih etti.

> **Ders sonrası not:** Java'da `protected` üyelere alt sınıfların yanında aynı paketteki bütün sınıflar da erişebilir. Hocanın "diğer sınıflar için private" ifadesi yalnız başka paketlerdeki alt sınıf olmayan sınıflar için doğrudur.

**Soru:** Burada `protected` kullanmanın bir sakıncası var mı, yoksa `super` yöntemi bir tercih mi? **Cevap:** Tercih. Kalıtımın temel ilkesi, kendisinden türetilen alt sınıfların üst sınıfı ilgilendirmemesidir; üst sınıf yalnız bir köken oluşturur. `protected` mekanizması, üst sınıfı kodlarken kendisinden türetilecek alt sınıfların çalışma biçimini bir ölçüde bilmeyi gerektirir. Gerçek bir projede bütün tasarımı aynı ekip yapsa bile bunun sonu gelmez: bütün alanları kalıtımda kullanılır diye `protected` mı yapacağız? Gerekirse yalnız gerekli üye alanlar `protected` yapılabilir, ama hoca üst sınıfların alt sınıflar hakkında bir şey bilme ihtiyacı olmamasını tercih ettiği için `super` üzerinden erişir.

### 7.3 super kullanımıyla ilgili iki hata

Hoca kâğıt üstünde kod yazarken görülen bir hatayı anlattı: `Manager` constructor'ında `super(name, salary)` yerine `super(name); super(salary);` gibi iki ayrı çağrı yazmak. Birincisi, üst sınıfta böyle iki constructor yoktur. İkincisi, olsaydı bile bu yazım derleme hatası verirdi. `super(...)` constructor içinde yalnız bir kez ve ilk komut olarak kullanılabilir.

Ayrıca override edilmiş metotların edilmemiş hâline ulaşmak için `super` kullanılırken kalıtım hiyerarşisinde yalnız bir adım yukarı çıkılabilir. `Person`'ın da bir `getSalary` metodu olsaydı, `Manager`'dan iki düzey yukarıdaki bu metoda `super.super.getSalary()` diye erişilemezdi.

### 7.4 Company sınıfı ve çalıştırma

`Company` sınıfının ilk hâli (ekrandan, 00:55:00; derste örnek nesnelere kişi adları verildi, burada genel adlarla değiştirildi):

```java
public class Company {
    public static void main(String[] args) {
        Employee[] staff = new Employee[3];
        Manager boss = new Manager( "Ali Yilmaz", 8000 );
        boss.setBonus( 2500 );
        staff[0] = boss;
        staff[1] = new Employee( "Ayse Demir", 7500 );
        staff[2] = new Employee( "Can Kaya", 7000 );
        for( Employee author : staff )
            System.out.println( author.getName() + " " + author.getSalary( ) );
    }
}
```

Üç elemanlık bir `Employee` dizisi (`staff`) oluşturulur. Birinci eleman, 8000 maaşla başlayan ve 2500 bonus verilen yöneticidir. İkinci ve üçüncü elemanlar oluşturulur oluşturulmaz diziye atanan çalışanlardır (7500 ve 7000). Ardından for-each döngüsüyle dizide dolaşılır; döngü değişkeni `Employee` türündedir.

Çıktı (ekrandan, 01:10:00):

```text
<yönetici adı> 10500
<çalışan adı> 7500
<çalışan adı> 7000
```

Yöneticinin maaşı $8000 + 2500 = 10500$ olarak yazıldı. Hoca burada çok biçimliliğin devreye girdiğini vurguladı: dizi `Employee` türünden tanımlanmış olsa da içindeki `Manager` nesnesi `Employee` gibi değil, kendi en özelleşmiş hâli olan `Manager` gibi davrandı.

## 8. Üst Sınıf Türünden Dizi ve Overloaded Constructor

Aradan sonra hoca şunu sordu: iki çalışanı oluşturur oluşturmaz diziye aktardık. Aynısını yönetici için yapamaz mıyız? Yapabiliriz, ama bir sorun var. `Manager` nesnesini oluşturup doğrudan `staff[0]`'a atarsak bonusunu nasıl atayacağız?

Çok biçimlilik, metodun en özelleşmiş hâline erişimi sağlar. Ama `staff` dizisi `Employee` türünden tanımlandığı için `staff` işaretçisi üzerinden yalnız `Employee` sınıfında tanımlanmış metotlara erişilebilir. `Manager`'da tanımlı `setBonus` metoduna burada erişilemez. Yani bir yönetici oluşturup diziye atadıktan sonra elimizde ayrıca `Manager` türünde bir işaretçi yoksa alt sınıftaki özelleşmiş metotları doğrudan çağıramayız. Hoca, ileriki haftalarda görülecek tür dönüşümü (typecasting) ile bunun yapılabileceğini, ama bunun çok tercih edilen bir işlem olmadığını söyledi.

Başka bir çözüm, `Manager`'a bonusu da alan bir constructor eklemektir. Slayttaki örnek (ekrandan, 01:40:00):

```java
public Manager( String name, int salary, int bonus ) {
    super( name, salary );
    this.bonus = bonus;
}
```

Bununla `main` şöyle yazılabildi ve aynı çıktı alındı (ekrandan, 01:10:00):

```java
staff[0] = new Manager( "Ali Yilmaz", 8000, 2500 );
staff[1] = new Employee( "Ayse Demir", 7500 );
staff[2] = new Employee( "Can Kaya", 7000 );
```

### 8.1 Overloading ile overriding farkı

Slayttaki ayrım (ekrandan, 01:40:00):

- **Override:** kalıtımla gelen metodun gövdesini değiştirmek. Overriding kalıtımla yakından ilgilidir. Örnek: `Manager` sınıfındaki `getSalary` metodu.
- **Overload:** aynı adda ama farklı parametreli birden çok metot. Overloading kalıtımla ilgili değildir. Örnek: yukarıdaki üç parametreli constructor eklenince `Manager` sınıfının iki constructor'ı olur.

## 9. Object Sınıfı ve toString

Java'da tanımlanacak her sınıfın üst sınıfı olan bir sınıf vardır: `java.lang` paketindeki `Object` sınıfı. `java.lang`, import edilmesi gerekmeyen tek pakettir. Üst sınıfı olmadığını düşündüğünüz bir sınıf yazsanız bile o sınıf otomatik olarak `extends Object` olur (ekrandan, 01:20:00).

Hoca bu sınıfın neden gerektiğini şöyle açıkladı: Java sanal makinesi bellek yönetimiyle ilgili birçok işi programcının üzerinden alır. Hangi sınıftan olursa olsun nesneler için ortak işler yapmak zorundadır; örneğin `new` ile ilklendirilen nesneye gereken kadar yer ayırmak. Bu ortak işlerin, sınıfların adından bağımsız olarak modellenip kodlanabilmesi için Java'nın tasarımcıları böyle bir "kozmik üst sınıf" oluşturmuştur. `Object`'in bazı metotları override edilerek kendi amacımıza göre kullanılabilir.

Bundan sonra derste `introduceSelf` yerine `toString` metodu override edilecek. Bir nesnenin metin hâli istendiğinde Java sanal makinesi o nesnenin `toString` metodunu çağırır. Override edilmemiş `toString`, hocanın anlatımına göre nesnenin bellekteki adresinin bir hash fonksiyonundan geçirilmesiyle elde edilen onaltılık bir sayı içerir. Aynı türden iki farklı nesne farklı adreslerde bulunduğundan farklı sonuçlar üretir; bu, iki işaretçinin aynı nesneyi gösterip göstermediğini anlamak için de kullanılabilir. `Object`'in `toString`'i kendi içinde `hashCode` metodunu çağırır. `toString` override edilse bile bu koda `nesne.hashCode()` ile erişilebilir.

Gösterim: döngüde `System.out.println(author)` yazıldı. Çıktı (ekrandan, 01:15:00):

```text
nyp05.Manager@5d22bbb7
nyp05.Employee@123772c4
nyp05.Employee@2d363fb3
```

Üç farklı nesne olduğu için üç farklı kod görüldü. Ardından `boss` işaretçisi de yazdırıldı. İlk satırla son satırın kodu aynı çıktı, çünkü ikisi aynı nesnedir.

> **Ek bilgi (derste anlatılmadı):** `Object.toString()` biçimi `sınıfAdı@` ardından `hashCode()` değerinin onaltılık yazımıdır; çıktıdaki `nyp05.Manager` paket ve sınıf adıdır. `hashCode()` değerinin bellekteki adresten türetilmesi Java belirtiminde zorunlu değildir; sanal makine bunu farklı biçimlerde üretebilir. Aynı nesne için her zaman aynı değeri verir.

### 9.1 toString'in override edilmesi

Hoca `toString` metodunu üç sınıfa da ekledi. Altyazıdaki anlatıma göre `Person` ad ile birlikte "Person" yazıyor, `Employee` "Employee" ile ad ve maaşı, `Manager` "Manager" ile ad ve maaşı döndürüyordu:

```java
// Employee
public String toString() {
    return "Employee " + getName() + " " + getSalary();
}
// Manager
public String toString() {
    return "Manager " + getName() + " " + getSalary();
}
```

`Manager`'da `super.toString()` kullanılamadı, çünkü `Employee`'nin `toString`'i başa "Employee" yazıyordu; bu mantıklı bir sonuç vermezdi. Döngüde ve sonda `boss` yazdırılınca çıktı biçimi "Manager <ad> 10500", "Employee <ad> 7500", "Employee <ad> 7000", "Manager <ad> 10500" oldu.

Hoca sınıf adları yazılmasaydı başka bir yol da gösterdi: `Person.toString()` yalnız adı döndürür, `Employee.toString()` ise `super.toString() + " " + getSalary()` döndürür. Bu durumda `Manager`'da `toString`'i override etmek bile gerekmez. `Manager`, `Employee`'nin `toString`'ini kullanır, ama içindeki `getSalary()` çağrısında yine çok biçimlilik devreye girer ve yöneticinin maaşı bonusla birlikte 10500 olarak yazılır.

## 10. Company.main İçin Sıralama Şeması

Ardından `Company` sınıfının `main` metodunun sıralama şeması (sequence diagram) Violet UML ile çizildi. Violet ucu boş ok çizemediği için `main` çağrısı hocanın alıştığı biçimde gösterildi.

Adımlar:

- `staff` dizisinin oluşturulması tam bir constructor çağrısı değildir; yalnız üç çalışan içerebilecek bir diziye yer ayrılır. Bu yüzden gösterilmeyebilir. Gösterilmek istenirse, ne de olsa `new` kullanıldığı için, `staff : Employee[]` yaşam çizgisine `new Employee[3]` mesajıyla gösterilir. Hoca köşeli parantezin tür adının yanında yazılmasının daha doğru olduğunu düşündüğünü, ama fark etmediğini söyledi. Ders notunda okun üstüne yalnız `new` yazılmıştır.
- `boss : Manager` nesnesi `new("…", 8000)` ile oluşturulur, sonra `setBonus(2500)` çağrılır. Ok `main` metodunun aktivasyon çubuğunun içinden çizilmelidir.
- `boss`'un diziye eklenmesi bir metot çağrısı değildir; ne `Employee`'de ne dizide `add` diye bir metot vardır. Hoca bunu UML stereotip işaretleri arasında `«add boss»` olarak gösterdi. Stereotip, bir UML bileşeni asıl anlamı dışında kullanıldığında yeni anlamını belirten etikettir.
- Adı olmayan çalışan nesneleri `new("…", 7500)` ve `new("…", 7000)` ile oluşturulur. Nesne işaretçisi olmadığı için dönüş okuna geçici doğasını belirten `tmp` yazılır ve diziye ekleme `«add tmp»` diye gösterilir. Hoca iki ayrı parametreyle iki ayrı çalışan oluşturulduğu için yıldız kullanmadı, iki ayrı `Employee` yaşam çizgisi açtı. Ders notunda tek yaşam çizgisi kullanılmıştı; ikisi de olur.
- Döngüdeki çağrılar dizideki her nesne için yapıldığından başlarına yıldız konur: `*getName()`, `*getSalary()`. Yıldız çokluk anlamındadır, sıralama şemasında döngüyü belirtir.
- `main` bitince dönüş oku çizilir.

Şemadaki mesaj sırası (ekrandan, 01:35:00):

```text
main -> staff        : new Employee[3]
main -> boss:Manager : new("…", 8000)
main -> boss         : setBonus(2500)
main -> staff        : «add boss»
main -> Employee     : new("…", 7500)    dönüş: tmp
main -> staff        : «add tmp»
main -> Employee     : new("…", 7000)    dönüş: tmp
main -> staff        : «add tmp»
main -> staff        : *getName()
main -> staff        : *getSalary()
```

Hoca, aynı döngüdeki iki çağrının bir arada çalıştığını göstermek için Zoom'un çizim aracıyla bu iki çağrının çevresine bir dikdörtgen çizdi. Dikdörtgenin sol üst köşesine "tek kulağı kesik" bir etiket kutusu konur ve oraya `*` yazılır; böylece metotların başındaki yıldızlar silinebilir. Tek bir yıldız için bu angarya gibi gelse de karmaşık koşullu bir `while` döngüsünde ya da karmaşık bir `if` koşuluna bağlı çağrılarda koşulu her metodun başına köşeli parantezle yazmak yerine bir kez yazmak tercih edilebilir. Bu UML standardının seçeneklerinden biridir, Violet UML desteklemez. Hoca şemanın resim olarak kaydedilip bir resim düzenleyicide bu çizimin eklenebileceğini söyledi.

### 10.1 println ve toString ile şema

Kod `System.out.println(author)` biçiminde olsaydı şema değişirdi. `println` kendi içinde `toString`'i çağırır. Metot içinden yapılan çağrılar da gösterilmelidir: her eleman için `*toString()` çağrılır, `toString` de nesnenin kendi içinde `getName()` ve `getSalary()` çağrılarını yapar; bunlar nesnenin kendi yaşam çizgisine dönen oklarla gösterilir.

Hoca, `super.toString()` gibi bir çağrının nasıl gösterileceği sorusuna yine bu şekilde göstermeyi tercih edeceğini, o kadar didiklemeye gerek olmadığını söyledi. Çok biçimli davranışı, `super` erişimlerini ve constructor erişimlerini sıralama şemasında ayrıca göstermek zorunlu değildir. Döngünün hangi turunda `Manager`'ın, hangisinde `Employee`'nin metodunun çağrıldığını göstermek şemayı aşırı karmaşıklaştırır.

## 11. Private Metotların Yeniden Tanımlanması ve final Sınıflar

Override mekanizması normalde public metotlar için kullanılır ve anlam taşır. Ama üst sınıfın private metotları da alt sınıfta override edilebilir. Bu çetrefilli bir iştir: alt sınıfta override edilen private metot üzerinden üst sınıftaki orijinal hâline ulaşılamaz (slayt: "However, the child class cannot access to the original version of the method in any way, such as by using the super keyword", ekrandan, 01:40:00).

Hoca bunun nedenini bir "hack" girişimiyle açıkladı: mevcut bir sınıfın private metoduna erişemeyen biri, ondan kalıtımla yeni bir sınıf türetip o metodu override edip içinden `super` ile çağırarak engeli aşmayı düşünebilir. Buna izin verilmez. Görünürlüğü public'e çekmek de derleme hatası verir. Hocanın tavsiyesi: private metotlar private kalsın, onları override etmeye uğraşmak mantıklı değildir.

Son olarak bir sınıf da `final` olarak işaretlenebilir. Bir sınıftan kalıtımla yeni sınıflar türetilmesi istenmiyorsa, yani sınıfın üst sınıf olarak kullanılması istenmiyorsa başına `final` yazılır. Hoca `Person` sınıfını `final class Person` yaptığında beş derleme hatası çıktı. Kök neden `Employee`'deki hataydı: final bir sınıftan kalıtımla yeni bir sınıf oluşturulamaz. `final` silinince hatalar kayboldu.

## 12. Kalıtımın Doğru Kurulması: Hasta ve Doktor

Düğme örneği basitti. Hoca daha karmaşık bir örnekle kalıtımın doğru kurulmasını gösterdi. Gerçek hayatta yazılım projeleri doğal dilde yazılmış bir gereksinim belgesiyle başlar; bu belge çeşitli yöntemlerle teknik bir tasarıma dönüştürülür. Slayttaki gereksinim (ekrandan, 01:45:00): hastaların adları, TC kimlik numaraları, doğum tarihleri ve cep telefonu numaraları saklanmalıdır. Bu bilgiler doktorlar için de saklanmalıdır. Ek olarak, yasa gereği doktorların diploma numaraları da saklanmalıdır. Bir hastaya uygulanan tedavilerin kaydı da tutulmalıdır.

Okurken modellemeye başlarsak:

- `Patient` sınıfı: `- name, TCID, cellNr : String`, `- birth : Date`. Cep telefonu için ayrı bir sınıf konabilirdi, ama sonuçta bir metindir. `Date`, `java.util` paketinde hem tarih hem saat tutan bir sınıftır ve ileride işlenecektir.
- "Bu bilgiler doktorlar için de tutulmalıdır" cümlesi okununca `Doctor` sınıfını `Patient`'tan kalıtımla türetmek akla gelir. Gereksinim karşılanmış görünür.
- Doktora `- diplomaNr : String` eklenir. Sıfırla başlayan numaralar olabileceği için metin seçildi.
- "Hastaya uygulanan tedavilerin kaydı tutulmalıdır" cümlesi bir `Treatment` sınıfı ve `Patient`'tan `Treatment`'a 1-* sahiplik (`- treatments : Treatment[]`) gerektirir.

Bu sahiplik eklenir eklenmez tedavi kayıtları kalıtım yüzünden otomatik olarak doktor sınıfına da aktarılır. Ama doktor hasta değildir. Hasta olan bir doktor da doktor olarak faaliyet gösteremez, önce iyileşmesi gerekir. Hastaya özel bir üye alanın, hiçbir anlamı ve gereği yokken doktora geçmesi tasarımın yanlış olduğunu gösterir.

Doğru tasarım: doktorda ve hastada ortak olan bilgiler (ad, TC kimlik no, cep telefonu, doğum tarihi) bir sınıfta toplanır. Hoca bu sınıfa `Person` adını verdi. Gereksinim belgesinde böyle bir varlık geçmese de tasarımcı onu kendisi oluşturur. `Doctor` ve `Patient` bu sınıftan kalıtımla türetilir ve 1-* ilişki yalnız `Patient` ile `Treatment` arasında kurulur.

```text
Yanlış modelleme:                    Doğru modelleme:
Patient --1-----*--> Treatment       Person                         Treatment
  - name, TCID, cellNr : String        - name, TCID, cellNr : String     ^ *
  - birth : Date                       - birth : Date                    |
  - treatments : Treatment[]          /             \                    |
     ^                             Doctor          Patient --1-----------+
  Doctor                           - diplomaNr     - treatments : Treatment[]
  - diplomaNr : String
```

## 13. Soyut Sınıflar ve Soyut Metotlar

İkinci aradan sonra soyut sınıflara (abstract classes) geçildi. Kalıtım hiyerarşisinde aşağı indikçe daha özelleşmiş, yukarı çıktıkça daha genelleşmiş sınıflar yer alır. Öyle yukarı çıkılabilir ki sınıflar artık gerçek varlıklara değil, kavramlara denk düşer.

Hasta-doktor örneğindeki `Person` sınıfı buna iyi bir örnektir. Gereksinim belgesinde hiçbir yerde "kişi" geçmez; hasta, doktor, hasta yakını, hemşire gibi kişi türleri geçer. Bu tasarımda `Person` sınıfından bir nesne oluşturmaya ve kullanmaya hiçbir ihtiyaç yoktur. Sınıf yalnız alt sınıflarına üye alan ve metot aktarmak, bir temel oluşturmak için vardır. Böyle bir sınıf **abstract** (soyut) olarak işaretlenir. UML sınıf şemasında sınıf adının üstüne stereotip işaretleri arasında `«abstract»` yazılır.

Slayttaki kurallar (ekrandan, 02:05:00):

- Soyut sınıf, temel sınıf olarak kullanılan ve normal alt sınıfları için bir şablon temsil eden sınıftır.
- Şimdiye kadar kodlanan normal sınıflara somut (concrete) sınıf denebilir. Bir sınıf soyutsa `abstract` anahtar kelimesiyle işaretlenir.
- Soyut sınıftan nesne oluşturmak yasaktır.
- Soyut bir sınıfın somut alt sınıflarından nesne oluşturulabilir.
- Soyut sınıfların, somut sınıflar gibi üye alanları olabilir.
- Soyut sınıfların hem somut hem soyut üye metotları olabilir. Soyut metodun yalnız `abstract` anahtar kelimesiyle birlikte bir tanımı vardır, gövdesi yoktur.
- Kalıtımla gelen soyut metotların gövdeleri somut alt sınıflarda tanımlanmalıdır. Aksi hâlde o alt sınıflar da soyut olarak tanımlanmalıdır.

Hoca "concrete class" için Türkçe bir karşılık aramadı ("çimento sınıf" olmadı); ek bir etikete gerek olmadığını, soyut denmeyen sınıfın normal sınıf olduğunu söyledi. Soyut sınıflara constructor kodlanabilir, ama soyut sınıflardan nesne oluşturulamaz.

Soyut metodun anlamı şudur: yapılacak bir iş vardır ve metodun adı ile parametreleri bellidir. Ama işin nasıl yapılacağı alt sınıflarda farklılık gösterir. Bütün kardeş sınıflarda gövdesi farklı olacak bir metodun üst sınıfta gövdesini tanımlamaya gerek yoktur. Bu metot soyut olarak işaretlenir, gövdeler somut alt sınıflarda tanımlanır ve oradaki tanımda artık `abstract` kelimesi bulunmaz. Bir soyut sınıfın alt sınıfı da soyut olacaksa onda hâlâ soyut metotlar kalabilir. Ama somut bir sınıfın hiçbir metodu soyut olamaz. Bir sınıfın tek bir metodu bile soyut tanımlanacaksa sınıfın kendisi de soyut yapılmalıdır.

Bazı standartlarda soyut sınıflar ve metotlar UML'de italik yazılarak gösterilir. Hoca bunu tercih etmediğini söyledi: elle çizerken italik yazmak anlamsızdır. Daha net bir gösterim olan `«abstract»` stereotipi ve metodun sonuna kıvrık parantez içinde `{abstract}` yazmak varken italik gösterime gerek yoktur.

### 13.1 Yazıcı sürücüsü örneği

Slayttaki örnek (ekrandan, 02:10:00):

```text
            «abstract»
            PrintDriver
  + initSpooler()
  + print( Document ) : {abstract}
        /                 \
  PCL6Driver            PSDriver
  + print( Document )   + print( Document )
```

Bir yazıcı üreticisi olduğumuzu düşünelim. Yazıcıya gönderilen belgeyi tanımlamak için iki standarttan biri kullanılır: PS (PostScript) ve PCL (Printer Control Language; altyazıda "Page Control Language" diye geçiyor). PCL'nin 5, 6 gibi sürümleri vardır. Yazıcımız iki dili de anlayan donanım ve firmware içeriyor; sürücü (device driver) kodlarında ortak ve farklı işlemler olacak.

Örneğin işletim sistemindeki yazdırma biriktirici (spooler) süreci ilklendirilmemişse sürücü tarafından ilklendirilmelidir. Bunun yazıcının belge basma yetenekleriyle ilgisi yoktur; PCL için de PS için de aynı şekilde kodlanır. Belirli bir belgenin yazdırılması ise iki standartta bambaşka kodlanır. Bu yüzden ortak işler soyut `PrintDriver` sınıfında somut metotlar olarak kodlanır. Alt sınıflarda hiçbir ortak noktası olmayan `print` metodunun yalnız imzası yazılır ve metot soyut olarak işaretlenir.

Hoca, UML'de soyut metot için neden stereotip değil de kıvrık parantez seçildiğini bilmediğini, belki metot gövdesiyle karışmasın diye böyle yapıldığını söyledi. Bir metodun yanında `{abstract}` görülürse bunun metot gövdesiyle ilgisi yoktur, metodun soyut olduğunu belirtir.

Bu tasarım sayesinde aynı bilgisayara PCL6, PS ve gelecekteki türlerden birden çok sürücü kurulabilir. Hepsine `PrintDriver` sınıfının temsil ettiği tek tip bir yolla erişilir; hangi yazıcıya gönderilirse onun `print` metodu çağrılır ve çok biçimlilik gereği doğru sürüm çalışır. Üst sınıfta soyut `print` metodu tanımlanmasaydı, PCL6 ve PS sürücülerini aynı dizide ya da koleksiyonda tutup "şu belgeyi yazdır" diyemezdik: derleyici `PrintDriver` sınıfında böyle bir metot olmadığını söylerdi. Bu, `Employee` türündeki dizide `Manager` metotlarına erişememeye benzer.

Kodda yazılışı: `public abstract class PrintDriver`. `initSpooler` normal kodlanır. `print` metodu `public abstract` ile başlar, imzanın geri kalanı yazılır ve noktalı virgülle bitirilir.

> **Hocanın vurgusu:** Soyut metotta kıvrık parantez açılıp kapatılmaz; imza noktalı virgülle bitirilir.

`PCL6Driver extends PrintDriver` ile kalıtım kurulur ve soyut `print` metodu yeniden tanımlanır. PS için de benzer bir kod yazılır.

## 14. Çoklu Kalıtım ve Elmas Problemi

Hoca, arayüzlere bir giriş olması için şu soruyu sordu: bir sınıfın neden yalnız bir üst sınıfı olsun? Dil bir sınıfın birden fazla üst sınıfı olmasını destekliyorsa buna **çoklu kalıtım** (multiple inheritance) denir (ekrandan, 02:15:00).

Örnek: bir üniversite bilgi sistemi yazıyoruz. `Student` ve `Employee` sınıfları var (çalışanların altında akademik ve idari personel türleri olabilir). Yeni bir gereksinim geliyor: bazı öğrenciler yarı zamanlı ya da asistan öğrenci olarak saat ücretli çalıştırılabilir. Asistan öğrenci hem çalışan hem öğrencidir; ikisinin de bazı yeteneklerini alır. Bu yüzden `AssistantStudent` sınıfını hem `Student` hem `Employee`'den türetmek akla gelebilir.

Ama mevcut `Student` ve `Employee` sınıflarının büyük olasılıkla `Person` gibi ortak bir üst sınıfı olacaktır (hasta-doktor örneğindeki gibi). O zaman şema, sınıfların orta noktaları birleştirildiğinde bir elmas biçimini alır. Buna **elmas kalıtımı** (diamond inheritance) denir.

```text
          Person
         /      \
    Student    Employee
         \      /
      AssistantStudent
```

Sorun şudur: en üstteki `Person`'da tanımlı bir metot (slayttaki örnekte `toString`) hem `Student` hem `Employee`'de override edilmiş olsun. Bu metot alt sınıfa hangi ebeveynden geçecek? Bu bir belirsizliktir. Belirsizliği çözmek için çeşitli kurallar konabilir:

- İlk önce kimden kalıtım alınmışsa (`extends Student, Employee` yazımında ilk yazılan) onunki aktarılsın.
- En son kimden kalıtım alınmışsa onunki aktarılsın.
- Böyle bir durumda metot en alt sınıfta mutlaka override edilsin.

Buna kırılgan üst sınıf problemi de eklenince elmas kalıtımı çok çetrefilli durumlara yol açabilir. Kalıtımın diğer ilişkilere göre ağır sıklet olması da hesaba katılınca, Java ve C# dahil modern nesneye yönelik diller çoklu kalıtımı desteklemez. Onun yerine daha hafif sıklet bir ilişki olan arayüz gerçekleştirme (interface implementation) ilişkisini koyarlar. Daha eski dillerden C++ çoklu kalıtımı destekler ve elmas problemini metodun en alt sınıfta override edilmesi gerektiği kuralıyla çözer. Özetle Java'da çoklu kalıtım yapılmaz; yerine arayüzler kullanılır ve bu konu sonra işlenecek.

> **Ek bilgi (derste anlatılmadı):** C++'ta elmas durumunda en üst sınıfın iki kopyasının oluşmaması için `virtual` kalıtım kullanılır. İki ara sınıf aynı metodu override etmişse ve en alt sınıf bu metodu yeniden tanımlamazsa çağrı belirsiz sayılır ve derleme hatası verir. Hocanın "en alt sınıfta override edilmeli" kuralı bu durumu anlatır.

## 15. Soyut Sınıf Tasarımı ve Kodlaması: Anaokulu Malzemeleri

### 15.1 Problem

Bir anaokulunda oyuncak ve kıyafet gibi malzemeler (item) vardır; anaokulunda çocuklar da vardır. Bir çocuğa bir malzeme verilirken ona uygun olması gerekir. Her malzemenin bir barkodu ve tanımı vardır, ama ayrıca bir çocuğa uygun olup olmadığı da belirlenebilmelidir. Bu genelde yaş üzerinden yapılır (ekrandan, 02:20:00):

- Oyuncaklarda bir alt yaş sınırı vardır, genelde yıl cinsinden ("3 yaş ve üzeri, küçük yutulabilecek parçalar içerir" gibi).
- Kıyafetlerde alt ve üst sınır vardır, genelde ay cinsinden ("8-12 ay için" gibi).

Hoca, birinin yıl, diğerinin ay cinsinden verilmesinin bir nedeninin de birim çevirisini unutmamamızı hatırlatmak olduğunu söyledi. Gerçek hayatta da küçük bebekler için ay, büyük çocuklar için yıl kullanılır. Asıl fark, oyuncakta tek bir alt sınır, kıyafette bir aralık olmasıdır: çocuğun yaşı en küçük değerden küçük, en büyük değerden büyük olmamalıdır.

### 15.2 Tasarım

Slayttaki şema (ekrandan, 02:20:00):

```text
«Abstract» Item                                  Child
  - barcode, description : String     - - - - >   - name : final String
  + Item( barcode, description : String )         - ageInMonths : int
  + getBarcode( ) : String                              ^ *
  + getDescription( ) : String                          |
  + isSuitable( aChild: Child ) : boolean {abstract}    | 1
        /                \                        KinderGarten
  Toy                  Clothing                     + addChild( Child ) : boolean
  - minAgeLimit : int  - minMonthLimit,             + findOldestChild( ) : Child
                         maxMonthLimit : int
```

Gerekçeler:

- Barkod ve tanım ortak olduğu için bir `Item` sınıfına konur. `Toy` ve `Clothing` ondan kalıtımla türetilir.
- Tek başına bir "item" problem alanında geçerli bir nesne değildir: oyuncak mı, kıyafet mi, defter mi, kalem mi belli değildir. Bu yüzden `Item` soyut olarak işaretlenir.
- Uygunluk denetimi farklı malzeme türlerinde farklı işlemlerle yapılır. `isSuitable` metodu çocuğu parametre olarak alır, uygunsa `true`, değilse `false` döndürür. Bu işlem çok farklılaşabileceğinden metot soyut kodlanır.
- `Item` ile `Child` arasında sahiplik yoktur; çocuk yalnız metoda parametre olarak aktarılır. Bu yüzden şemada kesikli çizgi ve ucu açık okla (bağımlılık) gösterilir.
- `Child` sınıfının adı ve aylık yaşı vardır. `KinderGarten` ile `Child` arasındaki 1-* ilişki ve `addChild`, `findOldestChild` gibi metotlar daha önce galeri örneğinde ve laboratuvarlarda yapıldığı için yeniden kodlanmadı.
- Hoca, `final` bir üye alanın UML'de doğru gösteriminin slaytın üstüne ayrıca yazdığı `- name : String {final}` olduğunu, şemadaki `- name : final String` gösteriminin henüz düzeltilmediğini söyledi.

Hoca "soyut sınıflara alerjim var" diyen birinin ne yapabileceğini de tartıştı. `isSuitable`'a varsayılan bir gövde konabilir, örneğin yalnız bir alt sınır varmış gibi. Ama o sınır metoda nasıl aktarılacak? İki parametre konup oyuncakta yalnız birincisine, kıyafette ikisine birden bakılırsa, işin bir kısmı üst sınıfa, bir kısmı alt sınıflara kodlanmış olur; iş daha da dağılır. Hoca "bir iş bir yerde, en uygun yerde yapılır" dedi. Alt sınıflarda çok farklı yapılacak bir işin varsayılan davranışını üst sınıfa kodlamak tercih edilmez. Bu durumda en uygun çözüm soyut sınıf ve soyut metottur.

### 15.3 Kod

`Item` sınıfı altyazıdaki anlatıma göre şöyledir: `public abstract class Item`; barkod ve tanım `String` alanlardır; ikisini alan bir constructor ve getter'lar vardır. `isSuitable` metodu `public abstract boolean isSuitable(Child aChild);` biçiminde tanımlanır.

`Clothing` sınıfı (ekrandan, 02:30:00):

```java
public class Clothing extends Item {
    private int minMonthLimit, maxMonthLimit;

    public Clothing(String barcode, String description,
            int minMonthLimit, int maxMonthLimit ) {
        super(barcode, description);
        this.minMonthLimit = minMonthLimit;
        this.maxMonthLimit = maxMonthLimit;
    }
    public boolean isSuitable(Child aChild) {
        if( aChild.getAgeInMonths() >= minMonthLimit
                && aChild.getAgeInMonths() <= maxMonthLimit )
            return true;
        return false;
    }
}
```

Constructor iki alanı da ilklendirir, ama öncesinde barkod ve tanımı aktarmak için soyut üst sınıfın constructor'ını çağırır. Hoca, sınıf soyut olsa bile ona constructor kodlanabileceğini hatırlattı. Bu constructor `Item` nesnesi oluşturmak için değil, alt sınıflardan `super` ile erişmek içindir.

`Toy` sınıfı altyazıdaki anlatıma göre: `public class Toy extends Item`, `- minAgeLimit : int`. Constructor barkod ve tanımı üst sınıfa aktarıp alt yaş sınırını atar. `isSuitable` çocuğun aylık yaşını alır, yıl cinsinden karşılaştırma yapılacağı için 12'ye böler. Sonuç en küçük yaştan büyük ya da eşitse `true`, değilse `false` döndürür.

Deneme için bir `Main` sınıfı kullanıldı (ekrandan, 02:35:00 ve 02:40:00):

```java
public class Main {
    public static void main(String[] args) {
        Item anItem = new Toy("Işın kılıcı","123445",10);
        System.out.println(anItem.getDescription());
        Child ahmet = new Child("Ahmet",5); //5 aylık
        Toy lego = new Toy("123456","Lego Star Wars",4); //4 yaş
        Clothing pinny = new Clothing("86978945","mama önlüğü",0,24); //0-24 ay
        if( lego.isSuitable(ahmet) )
            System.out.println("Deneme 1 hatalı");
        else
            System.out.println("Deneme 1 tamam");
        if( pinny.isSuitable(ahmet) )
            System.out.println("Deneme 2 tamam");
        else
            System.out.println("Deneme 2 hatalı");
    }
}
```

İlk satırda `Item` türünde bir işaretçi tanımlanıp ona bir `Toy` nesnesi atanıyor. Bu, kalıtımın yerine geçebilirlik ilkesi sayesinde mümkündür ve soyut-somut sınıflar arasında da geçerlidir.

Denemelerin mantığı adım adım:

- Çocuk 5 aylıktır.
- Lego 4 yaş içindir. `Toy.isSuitable`: $5 / 12 = 0$ (tam sayı bölmesi), $0 \ge 4$ yanlış, sonuç `false`. Uygun olmayan oyuncak uygun olmayan çocuğa verilmemelidir. `if` gövdesine girilmez ve "Deneme 1 tamam" yazılır. Birim çevirisi unutulsaydı $5 \ge 4$ doğru çıkar ve Lego yanlışlıkla uygun sayılırdı.
- Mama önlüğü 0-24 ay içindir: $0 \le 5 \le 24$ doğru, sonuç `true`. "Deneme 2 tamam" yazılır.

Çıktı (ekrandan, 02:35:00): `123445`, `Deneme 1 tamam`, `Deneme 2 tamam`. Hoca denemelerin artırılabileceğini, örneğin ışın kılıcının da denenebileceğini söyledi. Ardından `main` içinde `Item none = new Item(...)` yazınca soyut sınıftan nesne oluşturulamayacağına dair derleme hatası alındı. Ama somut sınıftan bir nesne oluşturup soyut sınıf türündeki işaretçiye atamak mümkündür.

> **Ders sonrası not:** `Toy` constructor'ının parametre sırası `(barcode, description, minAgeLimit)` olduğu hâlde derste `new Toy("Işın kılıcı","123445",10)` yazıldı; barkod ve tanım ters verildiği için `getDescription()` çıktısı `123445` oldu. Doğrusu `new Toy("123445","Işın kılıcı",10)` olur. Bu notu hazırlarken sınıflar karedeki ve altyazıdaki tanımlarla yeniden yazılıp `java Main.java` ile çalıştırıldı; çıktı derstekiyle aynı çıktı (`123445`, `Deneme 1 tamam`, `Deneme 2 tamam`).

## 16. Soyut Sınıf Olmadan Aynı Tasarım ve Birim Sınaması

### 16.1 Elle sınamanın sınırları

Hoca, denemelerde "öyleyse tamam, değilse hatalı" gibi komutlar eklemek zorunda kaldığımızı belirtti. "Deneme 2 hatalı" çıktısı, neden hatalı olduğunu, ne beklenip ne bulunduğunu söylemez. Daha karmaşık bir örnekte çıktıları gözle inceleyip hatanın yerini bulmak çok yorucu olur ve sınamayla ilgili her şeyi kendimiz kodlamak zorunda kalırız. Birim sınaması (unit testing) yönteminde programlama dilindeki temel bileşen sınanır; burada sınıf düzeyinde sınama söz konusudur. Bunu kolaylaştıran araçlar vardır ve dersin son haftalarında örnekleri verilecektir.

> **Ek bilgi (derste anlatılmadı):** Java'da en yaygın birim sınama aracı JUnit'tir; Eclipse'in Package Explorer yanında görünen "JUnit" sekmesi bu araca aittir. JUnit'te beklenen ve bulunan değer `assertEquals(beklenen, bulunan)` gibi metotlarla karşılaştırılır. Başarısız bir sınamada iki değer de raporlanır.

### 16.2 Soyut sınıf olmadan

**Soru:** Soyut sınıfları kullanmadan da her işlemi gerçekleştirebiliriz, değil mi? Anladığım kadarıyla soyut sınıfların amacı kalıtımı biraz daha netleştirmek. **Cevap:** Evet, soyut sınıfların bir amacı kalıtımda alt sınıflara bir temel oluşturmaktır. Bu iş `Item` soyut yapılmadan da kodlanabilirdi. Hoca farkı göstermek için paketi kopyalayıp `Item`'ı normal sınıf yaptı.

- `Item` soyut olmayınca `isSuitable` metodunun soyutluğu kaldırılmalı ve bir gövde yazılmalıdır.
- Boş gövde `{ }` yazmak doğru değildir; dönüş tipi `void` olsaydı bile hiçbir şey yapmayan bir metot yalnız derleme hatasından kurtarır. Bu, tasarımın doğru olup olmadığını sorgulamamız gerektiğinin işaretidir.
- Dönüş tipi `boolean` olduğu için `return true;` yazıldı; derleme hatası gitti ve program aynı sonucu verdi.
- Ama bu sefer `Toy` ve `Clothing`'de `isSuitable` metodunu kodlamayı kesinlikle unutmamak gerekir. Unutulursa üst sınıftaki gövde her zaman `true` döndürür ve 10 yaşındaki bir çocuk için olan bir oyuncak bile bebeğe uygun sayılır. Hoca, bir tasarım hatasının can güvenliğine kadar gidebileceğini vurguladı.
- Soyut hâlinde ise alt sınıfta gövde tanımlanmazsa derleyici "bu sınıfı da soyut yap" der ve böylece hatalı sonuç üretebilecek bir oyuncak nesnesi oluşturulamaz.

Hocanın özeti: soyut sınıflar ve soyut metotlar, gerçek dünya probleminin kavramlarını ve ilişkilerini koda daha doğru biçimde yansıtmaya yarayan araçlardır.

## Örnek Sorular

**1. (ekrandan, 00:35:00)** `Person` türünden bir dizide `Person`, `Student`, `Employee` ve `Retired` nesneleri karışık olarak bulunuyor. Her sınıf `introduceSelf()` metodunu override ediyor. Dizideki bütün elemanların `introduceSelf` metodu çağrılırsa ne olur?

> **Çözüm (derste verildi):** Her nesnenin kendi sınıfındaki, en özelleşmiş `introduceSelf` sürümü çalışma anında çalıştırılır. Dizinin türünün `Person` olması nesnelerin `Person` gibi davranmasına yol açmaz. Bu mekanizmaya çok biçimlilik denir. Override edilmiş metodun üst sınıftaki sürümüne gerekirse `super` ile erişilir.

**2. (derste sözlü, 00:50:42)** `Manager.getSalary()` içinde maaşa erişmek için `salary` alanını `protected` yapmanın bir sakıncası var mı, yoksa `super.getSalary()` bir tercih mi?

> **Çözüm (derste verildi):** Tercihtir. `protected`, üst sınıfı yazarken alt sınıfların ihtiyacını önceden bilmeyi gerektirir. Kalıtımda üst sınıf alt sınıflarını bilmemelidir. Bu yüzden alan private bırakılır ve `return bonus + super.getSalary();` yazılır. Gerekirse yalnız gerekli alanlar `protected` yapılabilir.

**3. (ekrandan, 01:45:00)** Gereksinim: hastaların adı, TC kimlik numarası, doğum tarihi ve cep telefonu saklanmalıdır; bu bilgiler doktorlar için de saklanmalıdır; ayrıca doktorların diploma numaraları saklanmalıdır; hastaya uygulanan tedavilerin kaydı tutulmalıdır. Uygun sınıf şemasını tasarlayın.

> **Çözüm (derste verildi):** `Doctor`'u `Patient`'tan türetmek yanlıştır; `Patient`'ın `treatments : Treatment[]` alanı doktora da geçer. Doğrusu ortak alanları (`name, TCID, cellNr : String`, `birth : Date`) bir `Person` sınıfına koyup `Doctor` (`diplomaNr : String`) ve `Patient` sınıflarını ondan türetmek, 1-* ilişkiyi yalnız `Patient` ile `Treatment` arasında kurmaktır. Hoca ilerleyen bölümde bu `Person` sınıfının soyut sınıf için iyi bir aday olduğunu belirtti.

**4. (ekrandan, 02:15:00)** `AssistantStudent`, hem `Student` hem `Employee`'den türetiliyor; ikisi de `Person`'dan türüyor ve `toString` metodunu override ediyor. Yeni sınıf `toString`'in hangi sürümünü alır?

> **Çözüm (derste verildi):** Bu belirsizdir (elmas problemi). Bu durumda `toString` metodu yeni sınıfta mutlaka override edilmelidir. Bu tür karmaşıklıklar yüzünden Java ve C# çoklu kalıtımı desteklemez; yerine arayüzler kullanılır.

**5. (ekrandan, 02:20:00)** Çocuklara verilecek malzemeleri düşünün: her malzeme her çocuğa uygun değildir. Oyuncakların genelde yıl cinsinden alt yaş sınırı, kıyafetlerin ay cinsinden alt ve üst sınırı vardır. Bu durumu nasıl modellemeliyiz?

> **Çözüm (derste verildi):** Soyut bir `Item` sınıfı (`barcode, description`, constructor, getter'lar ve `isSuitable(aChild : Child) : boolean {abstract}`), ondan türeyen `Toy` (`minAgeLimit`) ve `Clothing` (`minMonthLimit, maxMonthLimit`) sınıfları kullanılır. `Toy.isSuitable` aylık yaşı 12'ye bölüp alt sınırla karşılaştırır; `Clothing.isSuitable` aylık yaşın iki sınır arasında olup olmadığına bakar. 5 aylık bir çocuk için 4 yaş sınırlı oyuncak `false`, 0-24 aylık mama önlüğü `true` döner.

**6. (derste sözlü, 02:39:19)** Soyut sınıfları kullanmadan da her işlemi yapabilir miyiz?

> **Çözüm (derste verildi):** Evet, ama üst sınıftaki metoda bir gövde yazmak gerekir (ör. `return true;`). Alt sınıfta override unutulursa yanlış sonuç sessizce üretilir. Soyut metot ise unutmayı derleme anında yakalatır.

## Dersin Toparlaması

Bu derste kalıtımın teorisi ve kodlaması bir arada işlendi. Kalıtım, mevcut bir sınıftan daha özelleşmiş sınıflar türetmenin yoludur. Alt sınıf üst sınıfın bütün üyelerini alır, private olanlara doğrudan erişemez, metotların gövdesini yeniden tanımlayabilir (`final` olanlar hariç). Kalıtım derleme anında sabitlenen, sınıf düzeyinde, ağır sıklet bir ilişkidir. Bu yüzden yalnız açık bir genelleşme-özelleşme ilişkisi varken kullanılmalı, ağaç derin tutulmamalıdır. Düğme rengi ve hasta-doktor örnekleri, yanlış kurulan kalıtımın nelere yol açtığını gösterdi. `Person` - `Employee` - `Manager` örneğinde `super(...)` ile constructor zinciri, `super.getSalary()` ile üst sınıf sürümüne erişim, üst sınıf türünden dizide çok biçimlilik, overload ile override farkı, `Object` sınıfı ve `toString` görüldü. Aynı `main` metodunun sıralama şeması da çizildi.

Dersin son bölümünde soyut sınıflar ve soyut metotlar ele alındı. Soyut sınıflar nesnesi oluşturulmayan, alt sınıflarına temel sağlayan sınıflardır. Soyut metotlar ise alt sınıflarda bambaşka biçimde yapılacak işlerin yalnız imzasını tanımlar. Çoklu kalıtımın elmas problemi yüzünden Java'da desteklenmediği ve yerine arayüzlerin kullanılacağı söylendi. Bir sonraki konu arayüzlerdir. Birim sınama araçları da dersin son haftalarında işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
