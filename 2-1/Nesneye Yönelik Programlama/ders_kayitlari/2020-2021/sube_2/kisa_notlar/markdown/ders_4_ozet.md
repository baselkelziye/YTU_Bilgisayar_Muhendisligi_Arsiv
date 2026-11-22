# Ders 4 Çalışma Özeti

## Genel Konular

- Nesne kavramı ve kapsülleme (encapsulation)
  - Nesne yönelimli programlamanın temel programlama elemanı nesnedir. Nesne nitelikler (attributes) ve bu nitelikler üzerinde çalışan eylemler (tasks, yani metotlar) içerir.
  - Gerçek dünyadaki problem alanında yer alan her varlık, kodda bir nesne olarak karşılık bulur.
  - Nesne bir değişkene benzetilebilir, ama bu eksik bir benzetmedir: nesne kendi verisi ve o veri üzerinde çalışan metotlarıyla ayrılmaz bir bütündür. Bu bütünlüğe kapsülleme denir.
  - Slayttaki şekilde ortada veri (Data), çevresinde dört metot (Method) bulunan bir daire vardır; veriye ulaşmanın her yolu bir metottan geçer (ekrandan, 00:10:00). Şekil UML gösterimi değildir, yalnız kavramı anlatmak içindir.
  - Yapısal programlamada `struct` ile veri bir tarafta, fonksiyonlar başka tarafta tanımlanıyordu; nesne yönelimde veri ve metot birlikte tanımlanır.
- Sınıf kavramı
  - Sınıf, nesneleri tanımlamak için yazılan bir şablondur (program kodu). Benzetme: nesneler kurabiye, sınıf kurabiye kalıbıdır.
  - Kod olarak sınıf yazılır, ama her zaman nesneler cinsinden düşünülmelidir.
  - Java'da sınıf `class` anahtar kelimesiyle, bir ad verilerek ve kıvrık parantezli bir blok içinde yazılır. Kodlama standardına göre yalnız sınıf adları büyük harfle başlar.
- Örnek: araba nesnesi ve otomobil sınıfı
  - Nitelikler: renk, marka, model, plaka numarası. Yalnız çözülecek problemle ilgili nitelikler koda alınır (otopark sisteminde renk gereksiz, araç tescil sisteminde gereklidir).
  - Plaka numarası tekil tanımlayıcıdır (unique identifier): aynı türden varlıklar arasında belirli bir varlığı ayırt eder. Her nesnenin bir tekil tanımlayıcısı olmasına dikkat edilir.
  - Eylemler de probleme göre seçilir: yarış simülasyonunda "çalıştır", tescil sisteminde "sat", otopark sisteminde "otoparka gir/çık".
  - Tekil tanımlayıcıyı döndüren metot basit bir `return` içerir ama çok önemli bir metottur.
- Üye alan türleri
  - İlkel (primitive) üyeler tek bir birim bilgi içerir: tam sayı (model yılı), gerçek sayı (motor hacmi), mantıksal değer (true/false), tek karakter.
  - İlkel olmayan (non-primitive) üyeler herhangi bir sınıftan bir nesnedir.
- Nesne yönelimli terminoloji (ekrandan, 00:20:00)
  - Veri = member field (üye alan) = field = attribute. Derste tercih edilen terim member field'dır.
  - Görev = action = function = method = member method (üye metot).
  - State (durum): bir nesnenin tüm üye alan değerlerinin kümesi.
  - Members (üyeler) = metotlar + üye alanlar.
  - Class = type (tür, tip).
  - o nesnesi C sınıfındansa "o is an instance of C" (o bir C örneğidir) denir.
- UML'de sınıf ve nesne gösterimi
  - Sınıf şemasında sınıf bir dikdörtgen içinde adıyla gösterilir.
  - Nesneler sıralama şemalarında (sequence diagram) `nesneAdı : SınıfAdı` biçiminde ve altı çizili gösterilir (`kitt : Car`).
  - Yalnız tür önemliyse `: Car`, addan tür anlaşılıyorsa yalnız `myCar` yazılabilir; üç gösterimin ortak noktası alt çizgidir.
  - Etkileşim şemaları (interaction diagram) iki çeşittir: sequence diagram ve collaboration diagram. Derste yalnız sequence diagram işlenir; collaboration diagramda çağrı sırasını çizmek ve izlemek daha zordur.
- "Her nesne farklı bir bireydir"
  - Aynı sınıftan iki nesnenin üye türleri aynıdır, ama üye değerleri (durumları) farklıdır.
  - Durumları tamamen aynı olsa bile iki nesne bellekte farklı yerlerde tutulur. JVM her nesneye programcının müdahale edemediği bir evrensel tekil tanımlayıcı (universal unique identifier) verir.
  - Programcının tanımladığı tekil tanımlayıcının (plaka gibi) tekilliğini JVM denetlemez; bunu programcının kodu sağlamalıdır.
  - Aynı türden iki farklı nesneye aynı mesaj gönderildiğinde farklı yanıtlar alınabilir, çünkü durumları farklıdır.
- Mesaj gönderme ve üye erişimi (ekrandan, 00:40:00)
  - Bir nesneye mesaj göndermek, onun bir metodunu çağırmakla aynı şeydir.
  - Mesaj iki amaçla gönderilir: nesneye bir şey yaptırmak ya da bir üyesine erişmek.
  - Üye alana erişim iki türlüdür: değerini değiştirmek (setting, setter metot) ve değerini okumak (getting, getter metot).
  - Aksi belirtilmedikçe bir nesnenin metodu o nesnenin kendi üyeleriyle çalışır. Başka nesnelerle çalışma, ilerideki haftalarda işlenecek nesneler arası ilişkilerle olur.
- Sıralama şemasında metot çağrısı (ekrandan, 00:45:00)
  - Çağrı düz çizgi ve dolu (kapalı) ok ucuyla, üstüne metot adı yazılarak gösterilir: `getPlate( )`.
  - Dönüş kesikli çizgi ve açık ok ucuyla gösterilir; dönen değer okun üstüne yazılır (`plate`).
  - Nesnenin metodu çalıştığı süre ince uzun bir dikdörtgenle (activation bar) gösterilir. Y ekseninde aşağı inildikçe zamanda ileri gidilir.
  - Kod karşılığı: `kitt.getPlate();`. Metot parametre almasa da parantezler yazılır.
  - Çağıran (client) her zaman aktif olduğu için çizgisi bölünmez; çağrılan nesne yalnız metodu çalışırken aktiftir, bu yüzden onun activation bar'ı her çağrıda ayrı parça olur (ekrandan, 00:55:00).
  - Sıralama şemasında yalnız problem alanındaki nesneler arasındaki metot çağrıları gösterilir; atamalar, aritmetik işlemler ve `System.out.println` çağrıları gösterilmez.
- Adlandırma: camel casing
  - Metot adları küçük harfle başlar; birden fazla kelimeden oluşan adlarda ikinci kelimeden itibaren her kelimenin ilk harfi büyük yazılır (`getPlate`, `getModelYear`).
- Paketler (ekrandan, 01:10:00)
  - Aynı amaca yönelik sınıflar paket adı verilen soyut kapsayıcılarda toplanır. Bir paket diskte bir klasöre karşılık gelir: `com.fileWizard.File -> com\fileWizard\File.java`.
  - UML'de paket etiketli bir klasör dikdörtgeni olarak çizilir; paket içinde paket olabilir (`package1` içinde `ClassA`, `ClassB` ve `package2`; `package2` içinde `ClassC`).
  - `import package1.ClassA;` tek sınıfı, `import package1.*;` paketteki tüm sınıfları dahil eder. Yıldız alt paketleri kapsamaz; `ClassC` için `import package1.package2.*;` gerekir.
  - Kullanılmayan sınıfların import edilmesinin ek yükü yoktur.
  - Farklı paketlerdeki aynı adlı sınıflar çakışmaz (`java.io.File` ve `com.fileWizard.File`). İkisi aynı dosyada kullanılırsa her seferinde tam ad (fully qualified name) yazılmalıdır.
- Görünürlük kuralları ve bilgi gizleme (ekrandan, 01:25:00)
  - Bir nesne kendi sınıfından olan diğer nesnelerin tüm üyelerine her zaman erişebilir; bu kısıtlanamaz. Kısıtlama yalnız farklı türden nesnelere uygulanır.
  - Bilgi gizleme ilkesi (information hiding): iç çalışma ayrıntılarıyla ilgili üyeler gizlenir, nesne bir kara kutu gibi yalnız dışarıya açtığı metotlarla kullanılır.
  - `public`: erişim kısıtlaması yoktur. UML'de `+`.
  - `private`: farklı türden nesneler erişemez. UML'de `-`.
  - `protected` (UML'de `#`) kalıtımla ilgilidir; `package` (UML'de `~`) aynı paketteki sınıflara açıktır ve Java'da varsayılan kuraldır. Derste bu ikisi kullanılmaz.
  - Kural: üye alanlar her zaman `private`; metotlar genelde `public`. Dışarıdan keyfi sırada çağrılırsa nesnenin iç düzenini bozabilecek kritik metotlar `private` yapılır.
- UML sınıf şeması (ekrandan, 01:25:00 ve 01:35:00)
  - Dikdörtgen üç bölmelidir: üstte sınıf adı (ortalanmış), ortada üye alanlar, altta üye metotlar. Her üyenin altına çizgi çekilmez.
  - Üye alan: `- ad : Tür`. Metot: `+ ad( param1 : Tür1, param2 : Tür2 ) : DönüşTürü`. Dönüş yoksa tür yazılmaz.
  - Örnek `Car` sınıfı: `- plate : String`, `+ getPlate( ) : String`, `+ setPlate( String )`. UML'de parametre adı yazılmayabilir; türü yeterlidir.
- Üyelerin özel durumları: static ve final (ekrandan, 01:45:00 ve 01:50:00)
  - `static` = ortak kullanım (shared). Statik üye alan o sınıfın tüm nesnelerince paylaşılır ve `SınıfAdı.üyeAdı` ile erişilir. Örnek: her otomobilin 4 tekerleği vardır; bu değer her nesnede ayrı ayrı tutulursa bellek israf edilir ve yanlış değer atanabilir.
  - Statik metot tüm nesneler için aynı davranır ve `SınıfAdı.metot()` ile çağrılır. Statik metot içinde yalnız statik üyeler kullanılabilir (ekrandan, 01:45:00).
  - `main` metodu statiktir, çünkü program başlarken henüz hiçbir nesne yoktur; sınıfın bytecode'u yüklenmiştir ve metoda sınıf adı üzerinden erişilir.
  - `final` üye alana yalnız bir kez değer atanır, sonra değiştirilemez. Bu atama genelde nesne oluşturulurken yapılır. Örnekler: kimlik numarası, şasi numarası.
  - `final` metot alt sınıflarda yeniden tanımlanamaz (override edilemez); kalıtımla birlikte işlenecek.
  - Bir üye hem `final` hem `static` olabilir. Böyle bir üye alan evrensel sabittir (pi sayısı gibi) ve `public` tanımlanabilir.
  - UML gösterimi: `aMember : Type {final,static}`. Buradaki kıvrık parantez metot gövdesi değildir.
- Kurucu (constructor) ve sonlandırıcı (finalizer) metotlar (ekrandan, 02:05:00)
  - Kurucu, nesne oluşturulurken programcının açıkça çağırdığı metottur; üye alanlara ilk değer atamak için en uygun yerdir.
  - Sonlandırıcı (`finalize`), nesne bellekten kaldırılırken JVM'nin örtük olarak çağırdığı metottur; parametre almaz, değer döndürmez, sınıfta bir tane olur. Derste kullanılmayacak.
  - Kullanılmayan nesneler arka planda çalışan çöp toplayıcı (garbage collector) tarafından silinebilir olarak işaretlenir; asıl silme bellek azaldığında yapılır.
- Kurucu kuralları
  - Ders kuralı olarak `public` tanımlanır. Adı sınıf adıyla aynıdır (`Car`). Dönüş türü yoktur, `void` bile yazılmaz.
  - `new` anahtar kelimesiyle çağrılır: `kitt = new Car();`.
  - Parametresiz kurucuya varsayılan kurucu (default constructor) denir. Hiç kurucu yazılmazsa otomatik eklenir: nesneye bellekte yer açar, evrensel tekil tanımlayıcıyı oluşturur, sayısal alanlara 0, mantıksal alanlara false, nesne alanlarına null atar.
  - Programcı parametreli tek bir kurucu bile yazarsa varsayılan kurucu eklenmez. İş mantığı genelde parametreli kurucu gerektirir, çünkü tekil tanımlayıcıya ilk değer verilmelidir.
  - Bir sınıfta parametre listeleri (türleri ve sayıları) farklı birden fazla kurucu olabilir: constructor overloading. Sıradan metotlar da aşırı yüklenebilir (overloaded method).
  - Nesneyi tanımlamak yetmez, kurucusu çağrılarak örneklendirilmelidir (instantiate). Sıralama şemasında bu, nesneye giden ve üstünde `new` yazan bir okla gösterilir.
- Üye alan olarak nesne ve geçici nesne (ekrandan, 02:10:00)
  - `AClass` içinde `private Car kitt;` bir üye alandır; nesne yaşadıkça erişilebilir.
  - `AnotherClass` içinde bir metotta `Car kitt = new Car();` geçici nesnedir; metot bitince silinmek üzere işaretlenir. Görünürlük kuralları yalnız üyelere uygulandığı için geçici nesneye `public`/`private` yazılmaz.
- Denetim akışı ve main
  - Java programında denetim akışı `public static void main` metodunda başlar.
  - Bir metodu yazmak onun mutlaka çağrılacağı anlamına gelmez. Birden çok sınıflı projede her sınıfın `main` metodu o sınıfı ayrı test etmek için kullanılabilir.
- Uygulama: `Car` sınıfı Eclipse'te (ekrandan, 02:40:00 ve 02:45:00)
  - Kurucu `Car( String plateNr )`, getter `getPlate()`, setter `setPlate( String plate )`, `introduceSelf()` ve `main` yazıldı; çıktı `My license plate is 34 RA 440`.
  - Setter'da parametre adı üye alanla aynı olduğu için `this.plate = plate;` yazmak zorunludur.
  - Bu kodun sıralama şeması Violet UML Editor'de çizildi (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Nesne gösteriminde alt çizgi
  - Sıralama şemasında nesne kutusundaki ad altı çizili yazılmalıdır; nesneyi sınıftan ayıran budur. Kâğıt üzerinde çizerken alt çizgi ve iki nokta üst üste sık unutulur.
  - Notasyondaki her işaretin bir anlamı vardır ve bilindiği şemada gösterilmelidir.
- Üye alanlar her zaman private
  - Nesnenin en iç ayrıntısı üye alanlarıdır, bu yüzden hep `private` tanımlanır. Tek istisna hem `final` hem `static` olan sabitlerdir.
  - `package` kuralı Java'da varsayılandır, ama bilgi gizlemeye uymaz. Mühürlenmemiş (sealed olmayan) bir pakete dışarıdan sınıf eklenip bu üyelere erişilebilir. Bu yüzden her üyede `public` ya da `private` açıkça yazılmalıdır.
- static ve final karıştırılmamalı
  - Türkçe karşılıklarıyla değil, anlamlarıyla akılda tutulmalı: `final` = yalnız bir kez değer atama, `static` = ortak kullanım.
- Kurucuların önemi
  - Şemada kurucu gösterilmemiş olsa bile sınıfın kaynak kodu istendiğinde kurucu da yazılmalıdır.
  - Plaka gibi tekil tanımlayıcılar ve nesnenin doğru çalışması için gereken alanlar kurucuya parametre olarak verilmelidir.
- Sıralama şemasında zaman sırası
  - `main` içindeki çağrılar `main` okunun başlangıcıyla dönüşü arasında iç içe (nested) yer alır.
  - Elle çizerken iç çağrının oku dış çağrının okuyla aynı hizadan başlamamalı, biraz aşağıdan başlamalıdır. Daha yukarıdan başlamak zamanda geri gitmek anlamına gelir ve yanlıştır.
- UML ve Java'da sıra farkı
  - UML'de `ad : Tür`, Java'da `Tür ad` yazılır. Dönüş türü UML'de sonda, Java'da başta yer alır. Biri diğerine yanlış sırada aktarılmamalı.

## Kısa Tekrar Notları

- Nesne = veri + metotlar; ikisinin ayrılmazlığı kapsüllemedir. Veriye yalnız metotlarla erişilir.
- Sınıf, nesne üretmek için şablondur; sınıf adı büyük harfle başlar, metot ve alan adları camel casing ile küçük harfle.
- State = tüm üye alan değerlerinin kümesi. Her nesne farklı bir bireydir; JVM her nesneye müdahale edilemeyen bir evrensel tekil tanımlayıcı verir.
- Mesaj göndermek = metot çağırmak. Amaçlar: bir şey yaptırmak ya da bir üyeye erişmek (get/set).
- Sıralama şeması: altı çizili `ad : Sınıf`, dolu oklu düz çizgi çağrı, açık oklu kesikli çizgi dönüş, activation bar aktiflik süresi, aşağı = zaman.
- Kendi metodunu çağırma: aynı activation bar'ın üstüne ek bir dikdörtgen ve kanca biçimli ok; dönüş için kesikli çizgi gerekmez.
- `import paket.*;` alt paketleri kapsamaz; aynı adlı iki sınıf aynı dosyada kullanılırsa tam ad yazılır.
- UML: `+` public, `-` private, `#` protected, `~` package. Sınıf kutusu üç bölmeli.
- Alanlar `private`, metotlar genelde `public`.
- `static` = paylaşılan, `SınıfAdı.üye` ile erişilir; `final` = tek atama. İkisi birden ise `public` sabit olabilir. UML'de `{final,static}`.
- Kurucu: sınıf adıyla aynı, dönüş türü yok, `new` ile çağrılır; hiç kurucu yazılmazsa varsayılan kurucu eklenir, parametreli bir kurucu yazılınca eklenmez.
- Aynı adlı farklı parametre listeli metot/kurucu: overloading.
- Metot içindeki geçici nesneye görünürlük kuralı yazılmaz; metot bitince silinmek üzere işaretlenir.
- Parametre üye alanı gölgeliyorsa üye alana `this.` ile erişilir.
- Bir sınıfta yalnız bir `main` olabilir; farklı sınıfların ayrı `main` metotları sorun çıkarmaz.

## Detaylı Açıklamalar

- **Kapsülleme ve bilgi gizleme neden önemli?** Ders iki benzetmeyle anlatıldı. Televizyonu kullanmak için kumandadaki birkaç evrensel düğmeyi bilmek yeter; tüplü televizyonun katot tüpüyle satır satır tarama yaptığını ya da LCD ekranın renkli sıvı kristallerden oluştuğunu bilmek gerekmez. İç yapıyı bilmek gerekseydi her yeni televizyon türü için yeniden öğrenmek gerekirdi. İkinci benzetmede borç para isteyen birine kredi kartı ve şifre verilmez, istenen miktar doğrudan verilir: karşı taraf "borç iste" metodunu çağırır, sahibi "borç ver" metoduyla parayı döndürür. Hoca bu örneğin teknik olarak tam doğru olmadığını belirtti, çünkü aynı türden nesneler birbirinin tüm üyelerine erişebilir; insanlar aynı sınıftan nesneler olsaydı her şeyleri birbirine açık olurdu. Bilgi gizlemenin bir yararı daha vardır: bir sınıf kullandığı sınıfa bağımlıdır. Kullanılan sınıfın içi değiştiğinde onu kullanan sınıflarda hata çıkabilir. Nesne kara kutu gibi kullanılırsa iç değişikliklerin başka yerde hataya yol açma olasılığı düşer.

- **Sıralama şemasında client ve activation bar.** Slayttaki şemada `client` adlı bir nesne `kitt : Car` nesnesinin `getPlate( )` metodunu çağırır, `kitt` de `plate` değerini döndürür (ekrandan, 00:45:00). `client`'ın türü önemsizdir. Public bir metot çağrıldığında nesne, çağıranın kim olduğuna bakmadan metodu yürütüp sonucu döndürmekle yükümlüdür; çağıranı bilmesinin tek yolu, çağıranın kendisini parametre olarak vermesidir. Violet UML Editor'de bir ok boşluktan başlatılamadığı için şemaya `client` eklenmiştir. Ardından `getModelYear( )` çağrısı da eklendi: `client`'ın activation bar'ı bölünmez, çünkü iki çağrı arasında da başka komutlar çalıştırır; `kitt`'in activation bar'ı ise her çağrı için ayrı bir parçadır (ekrandan, 00:55:00).

- **static örnekleri.** Tekerlek sayısı yarış oyununda her araba için 4'tür; normal üye alan olsaydı her nesnede ayrı yer tutardı (hoca bir tam sayının 4 bayt yer tuttuğunu söyledi) ve yeni araba için 4 atamayı unutmak mümkün olurdu. Statik tanımlanınca tüm nesneler bellekte aynı yeri kullanır. Lastik patlaması modellenecekse statik yapmak doğru olmaz. Statik metot için hoca eski bir Türk filmindeki sahneyi anlattı: zindanda gardiyan "Kara Murat kim?" diye sorunca bütün mahkumlar "Kara Murat benim" der. Yani her mahkum nesnesinin `getName` metodu kendi adından bağımsız olarak aynı yanıtı verir.

- **Kurucu yazılmazsa ne olur?** Derste kurucunun adı değiştirilip (`public void mar(...)`) normal bir metoda dönüştürüldü. Böylece sınıfta hiç kurucu kalmadı, varsayılan kurucu devreye girdi ve `new Car()` derlendi. `setPlate` çağrısı da yorum satırı yapılınca program `My license plate is null` yazdı: plaka hiç atanmamış bir araba nesnesi oluştu. Doğrusu plakayı parametreli kurucuyla vermektir; böylece plakayı atamayı unutmak ya da kasten atamamak mümkün olmaz.

- **Derste yazılan kod** (ekrandan, 02:40:00 ve 02:45:00; ajan tarafından Java 25 kaynak başlatıcısıyla `java Car.java` biçiminde çalıştırıldı, sistemde `javac` yok):

```java
package hafta02;

public class Car {
    private String plate;

    public Car( String plateNr ) {
        plate = plateNr;
    }
    public String getPlate() {
        return plate;
    }
    public void setPlate( String plate ) {
        this.plate = plate;
    }
    public void introduceSelf( ) {
        System.out.println("My license plate is " + getPlate() );
    }
    public static void main( String[] args ) {
        Car aCar;
        aCar = new Car("34 RA 440");
        //aCar.setPlate("35 İZ 35");
        aCar.introduceSelf();
    }
}
```

  - Çıktı: `My license plate is 34 RA 440`. Yorum satırı açılınca çıktı `My license plate is 35 İZ 35` olur.
  - `introduceSelf` içinde `getPlate()` yerine `plate`, `this.plate` ya da `this.getPlate()` yazmak da aynı sonucu verir. Hoca `getPlate()` yazdı, çünkü bir nesnenin kendi metodunu çağırmasının sıralama şemasında nasıl gösterildiğini anlatmak istiyordu.
  - `+` işlecinin iki yanı da sayıysa toplama yapar; bir yanı `String` ise öbür yanı da metne çevrilip iki metin birleştirilir.
  - Setter'da `this` yazılmazsa `plate = plate;` parametreyi kendine atar ve üye alan değişmez. Ajan bu durumu denedi: yorum satırı açık olsa bile çıktı `34 RA 440` kalır.

- **Bu kodun sıralama şeması** (ekrandan, 02:50:00): `:JVM`, `Car` (statik `main` çağrıldığı için sınıf) ve `aCar : Car` kutuları vardır. `:JVM`'den `Car`'a `main( ... )`; `Car`'dan `aCar`'a `new("34 RA 440")` ve kesikli dönüş; ardından `introduceSelf( )`. Bu çağrının activation bar'ı üstünde `getPlate( )` için kanca biçimli bir okla ek bir dikdörtgen çizilir. Ek dikdörtgenin alt kenarı kendi kendine çağrının bitişidir, kesikli dönüş oku gerekmez. Son olarak `introduceSelf` ve `main` dönüşleri çizilir. JVM kutusu yalnız aracın okun boştan başlamasına izin vermemesi yüzünden eklenmiştir; elle çizerken gerekmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
