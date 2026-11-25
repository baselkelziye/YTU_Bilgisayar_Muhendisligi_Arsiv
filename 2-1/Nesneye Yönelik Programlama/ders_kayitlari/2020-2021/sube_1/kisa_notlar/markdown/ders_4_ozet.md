# Ders 4 Çalışma Özeti

## Genel Konular

- Önceki dersin tekrarı: sınıf, nesne, durum ve mesaj
  - Sınıf bir şablondur; nesne bu şablondan oluşturulan gerçek varlıktır. Nesnenin verileri üye alanlar (member fields), davranışları üye metotlardır (member methods).
  - Aynı sınıftan oluşturulan nesnelerin durumu (üye alanlarının değerleri) farklıdır; bu yüzden aynı mesaja farklı tepki verirler. Örnek: deposu dolu ve boş iki `Car` nesnesinin `start` metodu çağrılınca biri çalışır, öbürü çalışmaz.
  - Bir nesnenin başka bir nesnenin metodunu çağırması, o nesneye mesaj göndermesidir. Mesaj, nesneye bir iş yaptırmak ya da bir üyesine erişmek için gönderilir (ekrandan, 00:15:00).
  - Üye alana erişim ya değerini değiştirmek (setting) ya da okumak (getting) içindir. Üye metoda erişim, metodu (gerekirse parametreyle) çalıştırmak içindir; C'de fonksiyon çağırmaya benzer (ekrandan, 00:15:00).
  - Sınıflar Java'da paketlerle (package) düzenlenir. Her paket bir klasördür, paketler iç içe olabilir. `import paket1.ClassA;` tek bir sınıfı, `import paket1.*;` paketteki bütün sınıfları kullanıma açar.
- Görünürlük kuralları ve bilgi gizleme (information hiding)
  - Bir nesne kendi üyelerinin hepsine ve aynı sınıftan (türden) başka nesnelerin bütün üyelerine erişebilir. Farklı türden nesnelerden ise bazı üyeler gizlenebilir (ekrandan, 00:20:00).
  - Bilgi gizleme ilkesi: nesnenin iç işleyişiyle ilgili üyeler farklı türdeki nesnelerden gizlenir; böylece bir nesneyi kullanmak için onun iç ayrıntılarını bilmek gerekmez.
  - Örnekler: kişi televizyonu açmak için yalnız açma/kapama metodunu görür; LCD mi plazma mı olduğu, katot tüp ya da akıllı TV kartı içerip içermediği onu ilgilendirmez. Kumandada güç, ses ve kanal tuşlarını bilmek yeterlidir. Arkadaşınıza borç verirken cüzdanınızdan para verirsiniz; maaşınızı ya da PIN numaranızı söylemezsiniz (ekrandan, 00:20:00).
- Erişim belirleyiciler (access modifiers)
  - `public`: erişim kısıtı yoktur; başka türden nesneler de üyeye doğrudan erişir. UML'de `+` ile gösterilir.
  - `private`: farklı türden nesneler birbirinin private üyelerine erişemez; yalnız aynı sınıfın nesneleri erişir. UML'de `-` ile gösterilir.
  - `protected` (`#`): kalıtımla ilgilidir; slayta göre pakete ve alt sınıflara görünür (ekrandan, 00:35:00). İleride ayrıntılı işlenecek.
  - Package (`~`): yalnız aynı paketteki sınıflara görünür; Java'da varsayılan kuraldır (ekrandan, 00:35:00).
  - Erişim belirleyiciler hem üye alanlara hem üye metotlara uygulanır.
- UML sınıf diyagramı gösterimi
  - Üç bölmelidir: sınıf adı, üye alanlar, üye metotlar.
  - Alan: `- ad : Tür`. Metot: `+ ad( param : Tür ) : DönüşTürü`. Dönüş değeri olmayan (void) metotta iki nokta ve tür yazılmaz (ekrandan, 00:35:00).
- Getter ve setter metotları
  - Üye alanlar private tanımlanır; başka sınıfların bu alanlara erişmesi için public getter (okuma) ve setter (değiştirme) metotları yazılır.
- Static üyeler
  - Aynı türdeki bütün nesnelerin ortak paylaşması gereken alan `static` ile tanımlanır. Erişim nesne üzerinden değil, `ClassName.memberName` biçiminde sınıf adıyla yapılır. Örnek: her otomobilin 4 tekerleği vardır (ekrandan, 00:40:00).
  - Bütün nesnelerin ortak davranışı olan metot `static` tanımlanır ve `ClassName.aMethod()` ile çağrılır. Static bir metodun içinde yalnız static üyeler kullanılabilir (ekrandan, 00:40:00).
- Final üyeler
  - Değeri sabit kalması gereken alan `final` tanımlanır; değer yalnız bir kez, genellikle nesne oluşturulurken atanır. Örnek: fabrikada kasaya kazınan şasi numarası sonradan değişmez (ekrandan, 00:50:00).
  - `final` metot alt sınıflarda geçersiz kılınamaz (override); `final` sınıftan kalıtım yapılamaz (ekrandan, 00:55:00). Bunlar ileride işlenecek.
  - Bir üye aynı anda hem `final` hem `static` olabilir. Final "yalnız bir kez", static "ortak kullanım" demektir. UML'de `aMember : Type {final,static}` biçiminde gösterilir (ekrandan, 00:50:00).
- Kurucular (constructors) ve sonlandırıcılar (finalizers)
  - Kurucu, nesne oluşturulurken programcı tarafından açıkça çalıştırılan ve üye alanlara ilk değer atayan özel metottur. Public tanımlanır, adı sınıfın adıyla aynıdır, dönüş türü yoktur, `new` ile çağrılır (ekrandan, 01:10:00).
  - Sonlandırıcı (`finalize`) bir nesne yok edilirken JVM tarafından örtük olarak çağrılır; parametre almaz, bir şey döndürmez. Java'da bellek yönetimini çoğunlukla JVM yaptığı için derste ayrıntısına girilmeyecek (ekrandan, 01:10:00).
  - Parametresiz kurucu varsayılan kurucudur (default constructor). Bir sınıfta hiç kurucu yazılmazsa derleyici boş bir varsayılan kurucu ekler (ekrandan, 01:20:00).
  - Bir sınıfta imzaları farklı olmak koşuluyla birden çok kurucu olabilir; buna aşırı yükleme (overloading) denir. Sıradan metotlar da aynı şekilde aşırı yüklenebilir.
  - Kurucular `this(...)` ile birbirini çağırabilir (ekrandan, 01:15:00).
- Kontrol akışı ve `main` metodu
  - Kontrol akışı program kodlarının yürütülme sırasıdır. Kodun yazılış sırası ile yürütülme sırası aynı olmak zorunda değildir; nesneye yönelik programlarda çoğu zaman farklıdır. Akışın başlangıç noktasını belirlemek ise kolaydır (ekrandan, 01:35:00).
  - JVM programı `public static void main(String[] args)` metodundan başlatır; `main` içindeki deyimler yazıldıkları sırayla yürütülür. `args` dizisi komut satırından parametre geçirmek içindir.
  - `main` metodu olmayan sınıf tek başına çalıştırılamaz; onu test etmek için `main` içeren başka bir sınıf gerekir (ekrandan, 01:55:00).
- UML ardışık diyagramı (sequence diagram)
  - Bir metodun içindeki çağrıların sırasını gösterir. `main` örneğinde JVM `main`'i çağırır, `main` `new Car(...)` ile kurucuyu çağırır ve nesnenin referansını alır, sonra `aCar.introduceSelf()` çağrılır; `introduceSelf` aynı nesnenin `getPlate()` metodunu çağırır.
  - Void bir metodun dönüşü üzerinde değer yazılmayan kesikli okla gösterilir.
- `this` anahtar sözcüğü
  - `this` nesnenin kendisini belirtir. Parametre adı üye alanın adıyla aynıysa üye alanı ayırt etmek için `this.alan` yazılır; adlar farklıysa gerek yoktur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Üye alanlar her zaman private tanımlanacak
  - Özel bir gerekçe olmadıkça bütün üye alanlar private olacak; bu kural sınavlarda da beklenecek.
- Her üye alan için getter ve setter yazılacak
  - Birden çok alan varsa her biri için ayrı getter ve setter yazılır. Sınavda yazılmazsa puan kaybedilir; hoca bunu kolay puan olarak niteledi.
- static ve final'ın ne zaman kullanılacağı
  - Sorularda "static kullanın" denmeyecek; "bu değer hiç değişmeyecek" denirse `final`, "bu değer bütün nesneler için aynı olacak" denirse `static` kullanılacağı bilinmeli.
- Kurucular çok önemli
  - Varsayılan, tek parametreli ve iki parametreli kurucuların kullanımı bilinmeli. İlk değerler kurucu içinde atanmalı.
  - Kurucu, nesne için gerekli bütün alanları ilk değerle doldurmalıdır. Arabanın hem plakası hem şasi numarası olmalıdır; bu yüzden ikisi aynı kurucuda atanır.
- Ders sonrası kodla çalışma
  - Eclipse (ya da IntelliJ, NetBeans) kurulup ders sayfasındaki kodlar bir projeye dönüştürülmeli, her dersin örnekleri editörde çalıştırılıp değiştirilmeli.

## Kısa Tekrar Notları

- Sınıf şablondur, nesne o şablonun örneğidir; nesnenin durumu alan değerlerinin bütünüdür.
- Metot çağırmak = nesneye mesaj göndermek.
- Bilgi gizleme: iç işleyiş gizlenir, yalnız gereken metotlar public yapılır.
- `public` `+`, `private` `-`, `protected` `#`, package `~`.
- Alanlar private, erişim public getter/setter ile.
- `static`: bütün nesnelerde ortak; `ClassName.member` ile erişilir; static metotta yalnız static üyeler kullanılır.
- `final` alan: bir kez atanır; `final` metot override edilemez; `final` sınıftan kalıtım yapılamaz.
- Bir alan hem `final` hem `static` olabilir; UML'de `{final,static}`.
- Kurucu: public, sınıfla aynı ad, dönüş türü yok, `new` ile çağrılır.
- Kurucu yoksa derleyici varsayılan kurucu ekler.
- Aynı imzalı iki kurucu derleme hatasıdır; farklı imzalı kurucular aşırı yüklemedir.
- Program `main` metodundan başlar; `main` yoksa sınıf tek başına çalışmaz.
- `this.alan`, parametre ile alan adı aynı olduğunda üye alanı belirtir.

## Detaylı Açıklamalar

- Bilgi gizleme neden gerekli?
  - Nesneler birbirine mesaj göndererek çalışır. Farklı sınıflardan nesneler bazı işlevlerini açığa çıkarır, bazılarını gizler. Bu, sınıfı kullanan programcının işini basitleştirir: televizyon kullanıcısı yeni bir teknolojiye (LCD, plazma) geçince yeniden eğitilmek zorunda kalmaz. Kodda da yalnız gerekli metotlar public yapılır.
- Alanları public yapmak yerine neden getter/setter? (derste sorulan soru)
  - Bir öğrenci, alanı public yapıp `car.plate` biçiminde doğrudan erişmenin getter/setter yazmaktan farkını sordu. Hoca iki gerekçe verdi:
    - Sınıfın mantığını korumak: sınıfı yazan, alana hangi değerlerin girebileceğini setter içinde denetleyebilir. Örneğin `setPlate` içinde plakanın il kodu, harf ve rakam kuralına uyup uymadığı denetlenip ancak ondan sonra atama yapılabilir. Alan public olursa başka bir sınıf denetimsiz yanlış değer atar ve kodun öbür metotları beklendiği gibi çalışmaz.
    - Güvenlik: aynı JVM'de çalışan kötü niyetli başka bir kod, public alanların değerini değiştirerek programın davranışını bozmaya çalışabilir.
- `this` ne zaman gerekir? (derste sorulan soru)
  - `nyp01b` paketindeki `Car` kurucusunda `plate = plateNr;` satırında `this` yok, `this.chassisNR = chassisNR;` satırında var (ekrandan, 00:45:00). İlk satırda parametre adı (`plateNr`) ile alan adı (`plate`) farklı olduğu için karışıklık yoktur. İkinci satırda parametre ile alanın adı aynıdır; derleyici ikisini ayırt etsin diye üye alanın önüne `this.` yazılır. `setPlate(String plate)` içindeki `this.plate = plate;` da aynı nedenle yazılmıştır.
  - Aynı sınıfın static olmayan bütün metotları üye alanlara (private olsalar bile) doğrudan erişebilir. Static `main` ise yalnız static alanlara doğrudan erişebilir.
- Kurucu zinciri örneği (ekrandan, 01:15:00)

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

  - `new MyClass()` varsayılan kurucuyu çağırır; o tek parametreli kurucuyu, o da iki parametreli kurucuyu çağırır ve iki alan atanır. Örnek, bir sınıfta birden çok kurucu olabileceğini göstermek için verildi. Slaytta `name` ve `age` alanlarının bildirimi `....` ile atlanmıştır; alanlar eklenerek denendiğinde `name` alanı `BeginnersBook.com`, `age` alanı `6` olur (ajan tarafından `java` ile çalıştırıldı).
- İlk tam sınıf: `nyp01a.Car` (ekrandan, 01:30:00)

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

  - Bu kod ajan tarafından `java` ile çalıştırıldı (javac kurulu değildi, tek dosyalık kaynak başlatıcı kullanıldı). Çıktı: `My plate: 34 RA 440`, `My plate: 06 ANK 06`, `My plate: 06 ANK 06`, `The End`.
  - Slayttaki UML karşılığı: `Car` | `- plate : String` | `+ Car( plateNr : String )`, `+ getPlate( ) : String`, `+ setPlate( String )`, `+ introduceSelf( )`, `+ main( String[] )` (ekrandan, 01:45:00). Önce sınıf şeması çizilir, sonra şema koda dönüştürülür.
- Doğru ve yanlış kurucu (ekrandan, 02:05:00)
  - Doğru sürümde tek bir `Car(String plateNr, String chassisNR)` kurucusu iki alanı birlikte atar. Yanlış sürümde `Car(String plateNr)` ve `Car(String chassisNR)` diye iki kurucu vardır. İkisinin imzası aynıdır (tek `String` parametre), bu yüzden kod derlenmez. Derlenseydi bile mantığı yanlış olurdu: hangi kurucu çağrılırsa çağrılsın nesnenin gerekli alanlarından biri boş kalırdı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
