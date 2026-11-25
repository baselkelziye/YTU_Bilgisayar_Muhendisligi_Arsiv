# Ders 2 Genişletilmiş Notu: Derse Giriş, Java'nın Genel Yapısı ve Nesne Yöneliminin Temelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynaklar
- 2. Java Sürümleri (Editions)
- 3. Java Çalışma Ortamı: Derlenen ve Yorumlanan Diller
- 4. JDK, Sürüm Adları ve Geliştirme Araçları
- 5. Nesne ve Kapsülleme
- 6. Sınıf ve Nesne
- 7. Nesne Özellikleri: İlkel ve İlkel Olmayan Tipler
- 8. Terminoloji ve UML Gösterimi
- 9. Her Nesne Ayrı Bir Bireydir
- 10. Nesnelere Mesaj Göndermek ve Üye Erişimi
- 11. Paketler
- Örnek Sorular

## 1. Dersin Kapsamı ve Kaynaklar

Nesne yönelimli programlama (Object Oriented Programming) bu derste Java ile öğretilir. Hoca dersin bir bilgisayar mühendisi için olmazsa olmaz olduğunu söyledi: meslek hayatında nesne yönelimli program yazmak ve başkasının yazdığı programı okuyabilmek sürekli gerekir.

### 1.1 Konu akışı

Hoca konuları iki bölüm halinde gösterdi (ekrandan, 00:45:00). İlk bölüm yaklaşık bir buçuk ayda bitirilmek istenen temel konulardır:

- Java programlama diline genel bakış
- Nesneler ve sınıflar
- UML sınıf şemaları
- Nesne durumu, davranışı ve metotları
- İlkel tipler ve sarmalayıcılar (wrappers), metot parametrelerinin incelikleri (call-by-value-of-references)
- Nesne ve sınıf iş birlikleri ve ilişkileri
- UML etkileşim (sequence) diyagramları
- Kalıtım ve soyut sınıflar
- Arayüzler ve çoklu kalıtım
- Çok biçimlilik, metot ezme (overriding) ve aşırı yükleme (overloading)
- Enum sınıfları

İkinci bölüm şunlardır:

- Temel veri yapılarıyla (List ve Map) generic sınıflara giriş
- İstisna yönetimi (exception handling)
- Tip dönüşümü (typecasting): bir nesne tipini başka bir nesne tipine çevirmek
- Dosyalar ve akışlarla çalışma (serileştirme)
- İç sınıflar (inner classes)
- Çoklu iş parçacığına (multithreading) giriş

Hoca bu konuları anlatırken şu bağlantıları kurdu. Nesne yönelimli programlamada programlama birimi nesnedir ve her iş nesnelerle yapılır. Bu birimler bir işlevi yerine getirmek için birbirleriyle iş birliği yapar, dolayısıyla nesneler arasında ilişkiler vardır. UML yalnızca programın kendisini değil, program birimleri arasındaki etkileşimleri de gösterir. Program çalışırken bir sorunla karşılaşırsa bununla nasıl başa çıkıldığı istisna yönetimidir. Yazılan programlar girdi alıp çıktı üretecek ve bunları işletim sisteminin dosya sistemine koyacak, bu yüzden dosyalar ve akışlarla çalışmak öğrenilecek. Zaman kalırsa dersin sonunda Swing ile grafik kullanıcı arayüzleri de işlenecek.

### 1.2 UML neden gerekli

Bir program yazılırken programın bir mantıksal akışı (logic flow) vardır. Programın içinde bileşenler bulunur ve bu bileşenler birbiriyle konuşarak programın yapması gereken işi yapar. Nesne yönelimli bir programın bileşenlerini ve aralarındaki ilişkileri tanımlamak için grafiksel bir dil kullanılır: UML.

### 1.3 Önerilen kitaplar

Slayttaki önerilen kitaplar (ekrandan, 00:05:00):

- Java Programming:
  - Java How to Program, Harvey M. Deitel & Paul J. Deitel, Prentice-Hall (7. baskı ya da daha yeni, "early objects" sürümü). Hoca bunu oldukça kapsamlı ve zengin bir kitap olarak tanıttı.
  - Core Java 2 Volume I & II, C. S. Horstmann ve G. Cornell, Prentice-Hall (7. baskı ya da daha yeni).
- UML:
  - UML Distilled, 3. baskı (2003), Martin Fowler, Addison-Wesley.

## 2. Java Sürümleri (Editions)

Java'nın farklı sürümleri (editions) vardır ve her birinin kullanım amacı farklıdır:

- Standard Edition (SE): mobil cihazlar dışındaki her tür uygulama için uygundur. Derste bu sürüm kullanılır.
- Micro Edition (ME): mobil cihazlarda çalışacak uygulamalar içindir.
- Enterprise Edition (EE): uygulama sunucularında (application server) çalışacak uygulamalar geliştirmek içindir.

Hoca özünde hepsinin aynı olduğunu vurguladı. ME ve EE, uygulamanın sunucuda ya da mobil cihazda çalışabilmesi için SE'ye göre ek yetenekler sağlar. Standard Edition öğrenilirse diğer sürümleri öğrenmekte zorluk çekilmez.

## 3. Java Çalışma Ortamı: Derlenen ve Yorumlanan Diller

Programlama dilleri iki kategoriye ayrılır: derlenen (compiled) diller ve yorumlanan (interpreted) diller. Slaytta Java "interpreted language" olarak tanımlanıyordu ve şu akış çiziliydi (ekrandan, 00:50:00):

```text
Source code --Compiler/compilation--> Compiled code --Linker/linking--> Executable code --OS--> Execution
   (.java)        (javac.exe)            (.class)
                                          |
                                          +------- Interpretation (Interpreter) -------> Execution

JDK: Java Development Kit            Java Virtual Machine (JVM)
  - Includes javac.exe                 - java.exe/javaw.exe: for command line/GUI apps
  - Optionally excludes IDE            - is included in JRE (Java Runtime Environment)

JDK is for developers and JRE is for end-users
  - JDK includes JRE
```

### 3.1 Yorumlanan dil olarak Java

Java'da önce kaynak kod yazılır; bu, bir problemi çözmek için programlama diliyle yazılmış koddur ve uzantısı `.java`'dır. Sonra dilin derleyicisi kaynak kodu derlenmiş koda dönüştürür. Derlenmiş kodun uzantısı `.class`'tır.

Derlenmiş kod henüz işlemcide (CPU) çalışmaya hazır değildir. Burada dilin ikinci bileşeni devreye girer: yorumlayıcı. Java'da yorumlayıcı `java.exe` ya da `javaw.exe` olarak gelir. Bu çalıştırılabilir dosyalar, program çalışırken derlenmiş kodu makine koduna çevirmekten sorumludur. Makine kodu oluşunca işlemcide çalıştırılabilir. Java'nın yorumlayıcı bileşenine Java Sanal Makinesi (Java Virtual Machine, JVM) denir.

Böylece Java iki bileşen olarak düşünülebilir:

- Derleyici: kaynak kodu alır, `.class` uzantılı derlenmiş koda dönüştürür.
- Yorumlayıcı (JVM): derlenmiş kodu alır, işlemcide çalışabilecek makine koduna dönüştürür.

> **Ders sonrası not:** Hoca derleyiciyi anlatırken "java.exe" dedi. Slaytta da yazdığı gibi derleyici `javac.exe`'dir; `java.exe` (ve `javaw.exe`) JVM'yi başlatan yorumlayıcıdır.

### 3.2 Derlenen diller

Derlenen bir dilde yorumlayıcı yoktur. Kaynak kod derlendiğinde ortaya çıkan kod zaten makine kodudur, dolayısıyla derlenmiş kod ile çalıştırma arasında bir yorumlayıcıya gerek kalmaz; kaynak kod doğrudan işlemcide çalışabilecek makine koduna derlenir. Derlenen dile örnek C'dir, yorumlanan dile örnek Java'dır. Hoca Python'un da Java'ya benzer şekilde hem derleme hem yorumlama kısmı olan bir dil olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Java'nın `.class` dosyalarındaki ara koda "bytecode" denir. Günümüz JVM'leri bytecode'u yalnız satır satır yorumlamaz; sık çalışan kısımları çalışma sırasında makine koduna derler (JIT, just-in-time derleme). Bu yüzden Java hem derlenen hem yorumlanan bir dil olarak da anılır.

## 4. JDK, Sürüm Adları ve Geliştirme Araçları

### 4.1 JDK

Java'da program yazmak için Java Geliştirme Kiti (Java Development Kit, JDK) kullanılır. JDK derleyiciyi ve kaynak kod yazmak için gereken bütün kütüphaneleri içerir. Slayta göre JDK bir IDE içermeyebilir; JDK geliştiriciler, JRE son kullanıcılar içindir ve JDK, JRE'yi kapsar (ekrandan, 00:50:00).

### 4.2 Sürüm adları

Java topluluğu yıllar içinde dilin farklı sürümlerini çıkardı. Hoca her zaman en son sürümün kullanılmasının tercih edildiğini söyledi. Slayttaki sürüm ayrıntıları (ekrandan, 00:55:00):

- `JDK 1.8.0_241`: Java sürüm 8.0, güncelleme 241.
- `JDK 1.11.0.9`: Güncelleme; küçük hata düzeltmeleri ve güvenlik iyileştirmeleri içerir, yılda birkaç kez çıkar.
- Ders notları JDK 1.5'e göre hazırlanmıştır.
- Nereden edinilir: oracle.com/java (site sık değişir). İndirirken doğru sürüm seçilir: x86 (i586) ya da x64. Belgeler de indirilip açılabilir.

> **Ders sonrası not:** Hoca güncel sürümü "1.15" diye andı. Java 9'dan sonra sürümler "1." öneki olmadan adlandırılır (JDK 15, JDK 16 gibi). Ders tarihinde güncel sürüm büyük olasılıkla JDK 15 idi; JDK 16 aynı ay içinde yayımlandı.

### 4.3 IDE ve UML araçları

Slayttaki ücretsiz Java geliştirme araçları (ekrandan, 01:00:00):

- IDE: Integrated Development Environment (tümleşik geliştirme ortamı), yani kod yazmak için bir düzenleyici.
- Eclipse (http://www.eclipse.org):
  - Ayrı indirilir.
  - UML şeması çizmek için eUML2 gibi bir eklenti kurmak gerekir.
  - GUI uygulamaları yazmak için bir eklenti kurmak gerekir.
  - Bilgisayarda yönetici yetkisi gerekmez, yalnız arşivden açmak yeterlidir.
- NetBeans:
  - Ayrı ya da isteğe bağlı olarak JSE ile birlikte indirilir.
  - UML şeması çizmek için eklenti gerekir.
  - Yerleşik GUI düzenleyicisi vardır.
  - Kurulum için yönetici yetkisi gerekir.

Hoca Eclipse kullanılmasını önerdi. IntelliJ ve NetBeans de kullanılabilir, ama Eclipse'in UML ile ve web uygulaması geliştirmeyle bütünleşmeleri olduğu için onunla başlamak avantaj sağlar.

Ücretsiz UML modelleme araçları olarak Violet UML (hafif, bu ders için yeterli, açık kaynak) ve Argo UML anıldı. Hoca öğrencilerden bir IDE ve bir UML aracı kurmalarını, ders kodlarını IDE'de bir projeye aktarıp üzerinde denemeler yapmalarını istedi; derste işlenen konuların bu ortamda denenmesinin önemli olduğunu söyledi.

## 5. Nesne ve Kapsülleme

### 5.1 Nesne nedir

Java'da, yani nesne yönelimli bir dilde her iş nesnelerle yapılır. Nesne ana programlama öğesidir, ana programlama birimidir. Slayttaki tanım (ekrandan, 01:20:00):

- Object: The main programming element.
  - Contains attributes and tasks.
  - Object ≈ a real-world entity. ("Similar to variables but Superman is similar to mere mortals, too!")
  - Attributes of an object ≈ Data about this entity.
  - Tasks ≈ actions ≈ methods. Fonksiyonlara benzer, ama her fonksiyon nesnenin herhangi bir özelliğine ve verilen herhangi bir parametreye erişebilir; bunun birçok kuralı vardır ve amaç bu kurallarda ustalaşmaktır.

Özellikler (attributes) bu nesneyle ilgili herhangi bir veri olabilir. Görevler (tasks) bu nesnenin yapabileceği herhangi bir metot olabilir.

Hoca bunu araba örneğiyle açıkladı. Ekrandaki araba nesnelerinin her biri diğerinden farklıdır ve her birinin özellikleri vardır. Örneğin bir arabanın markası Ford, modeli Mustang'dir; bir başka özellik arabanın benzinle mi elektrikle mi çalıştığıdır, bu örnekte benzinledir. Renk, model, yıl, yakıt tipi arabanın özellikleridir. Özelliklerin yanında nesnelerin metotları da vardır: bir araba çalışabilir (start), durabilir (stop) ya da hızlanabilir (accelerate). Bunlar bir araba nesnesinin yapabileceği görevlerdir.

### 5.2 Kapsülleme

Bir nesne verileri ve metotları birlikte içerir ve bunlar birbirinden ayrılamaz. Nesne yönelimli programlamada buna kapsülleme (encapsulation) denir. Slaytta nesne, ortada "Data" yazan bir çekirdeğin çevresinde dört "Method" diliminden oluşan bir daire olarak çizilmişti; yanında "Encapsulation: The data and the methods of an object cannot be separated. Data is accessed through methods." yazıyordu (ekrandan, 01:20:00).

Hoca ayrıca sürme (drive), durma (stop), hız ayarlama (set speed) gibi metotları ve model, hız, motor, hız sınırı gibi özellikleri kapsayan bir nesne çizimi gösterdi.

Nesne yönelimli programlamada veriye metotlar üzerinden erişilir. Örneğin renk, boyut, kapasite, ağırlık gibi bir veriye erişmek için nesnenin metotları kullanılır: rengin değerini almak için `getColor`, boyutun değerini değiştirmek için `setSize` çağrılır. Hoca o anki örnekte getter ve setter metotlarının görünmediğini, ama ileride bunların değer okuma ve değiştirme için kullanılacağını söyledi.

## 6. Sınıf ve Nesne

### 6.1 Sınıf bir şablondur

Sınıf (class), nesneyi tanımlayan bir şablondur. Ekrandaki çizimde solda kesikli çizgilerle çizilmiş bir `Car` sınıfı, sağda bu şablondan üretilmiş Audi, Nissan ve Volvo nesneleri vardı (ekrandan, 01:25:00). Şablon, nesnelerin nasıl oluşturulacağını tanımlar. Sınıf nesnelerin şablonu, nesneler ise gerçek dünya varlıklarıdır.

Hoca bunu Türkçe şöyle açıkladı: fabrikada bir arabanın tasarımının kâğıt üzerinde yapıldığını, fabrikada da bu tasarıma dayanarak araba nesnelerinin üretildiğini düşünün. İki kapılı mı dört kapılı mı olduğu, rengi, motorunun şasi numarası, içindeki koltuk sayısı artık o araba nesnesinin özellikleri haline gelir. Bu araba nesnelerini tanımlayan tasarım sınıftır. Biri şablon, diğeri gerçek dünya varlığıdır.

İkinci bir çizimde `Car Class`'tan üç araba nesnesi oluşturuluyordu: Red/Ford/Mustang, Blue/Toyota/Prius ve Green/Volkswagen/Golf (ekrandan, 01:40:00). Her nesnenin özellik değerleri diğerlerinden farklıdır.

Bir başka benzetme: sınıf kurabiye kalıbı, nesneler kurabiyelerdir. Kurabiye kalıbı kurabiyelerin şeklini oluşturur.

### 6.2 Programı sınıf olarak yazar, nesnelerle çalıştırırız

Java programları sınıflar olarak yazılır. Program çalıştırıldığında asıl işi nesneler yapar: kod sınıf olarak yazılır, program çalışınca bu sınıflardan nesneler oluşturulur. Programlama birimleri bu nesnelerdir ve programın yapması gereken işi gerçekten onlar yapar.

### 6.3 Slayttaki örnek nesne ve örnek sınıf

Slayttaki içerik (ekrandan, 01:30:00):

- Örnek nesne: belirli bir araba.
  - Özellikler: model, plaka numarası, renk vb.
    - Genellikle bir nesnenin özelliklerinden biri onun mantıksal benzersiz tanımlayıcısı (logical unique identifier, UID) olarak belirlenir. Örneğin bir arabanın plaka numarası.
  - Eylemler: bir arabaya plaka numarasını sormak, bu arabayı satmak vb.
- Örnek sınıf: Automobile. Arabaların özelliklerini ve metotlarını tanımlayan program kodu.
- Nesne yönelimli bir programda farklı sınıflardan istenen sayıda nesne oluşturulabilir.

Hoca eylemlere hızlanma, durma gibi işlemleri de ekledi; arabanın satılması ya da satın alınması da eylem sayılabilir.

> **Ders sonrası not:** Slaytta "You can create any number of classes from any different classes" yazıyordu. Hoca bunun "classes" değil "objects" olması gerektiğini söyledi: belirli bir sınıftan istenen sayıda nesne oluşturulabilir ve bu nesnelerin her biri ayrı bir varlıktır.

### 6.4 Bütün özellikleri aynı iki araba olabilir mi

Hoca şu soruyu sordu: iki araba nesnesinin bütün özellikleri aynı olursa ne olur? Bunun imkânsız olduğunu, arabalar arasında mutlaka farklı bir özellik olacağını söyledi. Örneğin motor şasi numarası: şasi numarası dışında bütün özellikler aynı olabilir. Fabrikadan çıkıp satıldığında plaka gelir ve plakalar da birbirinden farklı olur. Dolayısıyla araba nesneleri ayrı birer gerçek dünya varlığıdır, ama biz onları bir şablona dayanarak oluştururuz.

### 6.5 Soru-cevap: sınıf neyi tanımlar

**Soru:** (Zoom sohbetinden) Sınıf için "objenin oluşturulma kurallarını tanımlayan şey" diyebilir miyiz?
**Cevap:** Evet. Sınıf, bir nesnenin oluşturulmasında o nesnenin hangi özellikleri içereceğini ve hangi fonksiyonları içereceğini tanımlayan şeydir.

### 6.6 Soru-cevap: sınıfın struct'tan farkı

**Soru:** Buradaki sınıfların struct'lardan farkı yalnızca içine fonksiyon ya da metot yazılması mı?
**Cevap:** Hoca önce fonksiyon ile metodun aynı şey olduğunu belirtti. Sınıfın içine hem veri hem metot yazılır, ama asıl fark şudur: bu veriye ulaşmanın kuralları da tanımlanabilir. Nesnenin içine veri konur ve bu veriye hangi biçimde ulaşılabileceği belirlenir; örneğin bir veriye yalnız bu sınıfın metotları kullanılarak erişilebilir. Erişim şu biçimlerde ayarlanabilir:

- Herkes tarafından erişilebilir.
- Yalnız bu sınıfın içinden erişilebilir.
- Bu sınıf ve ondan türetilmiş alt sınıflar tarafından erişilebilir.
- Yalnız aynı paketteki sınıflar tarafından erişilebilir.

Aynısı metotlar için de geçerlidir. Örneğin bir sınıf, içinde çok sayıda başka sınıf bulunan bir kütüphanenin parçasıysa, sınıfın metotlarına hangi sınıfların ulaşabileceği belirtilebilir. Kütüphanelerde paketler (package) vardır, yani kategoriler; sınıflar bu paketlerde gruplanır. "Metoduma yalnız aynı paketteki sınıflar ulaşsın", "yalnız benim sınıfım ve ondan türetilmiş sınıflar ulaşsın" ya da "bütün sınıflar ulaşabilsin" denebilir. Bütün bunlar kapsüllemenin parçasıdır. Nesne yönelimli programlama bütün programlama işini birbirinden bağımsız nesne varlıklarına yaptırmak ister ve bu varlıkların içindeki veriye ve metotlara kimin, nasıl ulaşabileceğinin belirlenmesine olanak sağlar. Bu ayar sınıf yazılırken veri ve metotlarla birlikte yazılan erişim belirleyicileriyle (access modifiers) yapılır; konu ileride işlenecek.

## 7. Nesne Özellikleri: İlkel ve İlkel Olmayan Tipler

Bir nesnenin verisi (özellikleri) kavramsal olarak iki gruba ayrılır (ekrandan, 01:35:00):

- İlkel (primitives): tam sayı, gerçel sayı ve mantıksal değer gibi tek birim bilgi.
- İlkel olmayan (non-primitives): herhangi sayıda sınıftan herhangi sayıda nesne.

Hoca C dilinden bilinen ilkel tipleri hatırlattı: integer, double, float, boolean gibi. Java dili de sekiz farklı ilkel veri tipi tanımlar ve bunların hepsi kullanılabilir. İkinci kategori ilkel olmayan tiplerdir: Java'da sınıflar verinin tipi olarak kullanılabilir. Nesnenin şablonu olarak tanımlanan sınıf aynı zamanda bir veri tipi olabilir. Ayrıntılar ileride işlenecek.

> **Ek bilgi (derste anlatılmadı):** Java'nın sekiz ilkel tipi `byte`, `short`, `int`, `long`, `float`, `double`, `char` ve `boolean`'dır. Ders planındaki "sarmalayıcı (wrapper)" sınıflar bu tiplerin nesne karşılıklarıdır (`Integer`, `Double` gibi).

## 8. Terminoloji ve UML Gösterimi

### 8.1 Terimler

Hoca dersin geri kalanında ve slaytlarda farklı terimlerin eş anlamlı kullanılacağını, bunları ayırt etmenin önemli olduğunu söyledi. Deitel & Deitel kitabında da member field, data field ve attribute aynı şeydir. Slayttaki NYP terminolojisi (ekrandan, 01:45:00):

- Data = Member field = field = attribute
- State: Set of values of all attributes of an object
- Task = Action = function = Method = Member method
- Members of a class/object = Methods + fields
- Class = type
- If o is an object of class C, we can also say that o is an instance of C.

Durum (state) için örnek: bir arabanın rengi, markası, tipi, yılı ve plakası araba nesnesinin özellikleridir. Bunların hepsi bir araya geldiğinde, yani bütün özelliklerin değerleri birlikte, araba nesnesinin durumunu oluşturur. Üç araba örneğinde birinci nesnenin durumu kendi üç özellik değeridir, ikincinin durumu kendi üç değeridir.

Sınıf = tip ilişkisi şöyle açıklandı: üç araba nesnesi de aynı `Car` sınıfı şablonundan üretildiği için hepsi aynı tiptedir. Bu yüzden bir nesnenin tipi, onun oluşturulduğu sınıftır. İlkel olmayan veri tiplerinden söz edilirken kastedilen budur.

Bir nesneye iki açıdan bakılabilir ve iki ifade de doğrudur:

- Nesnenin tipi bir sınıftır.
- Nesne, o sınıfın bir örneğidir (instance).

### 8.2 UML'de sınıf ve nesne

Slayttaki UML gösterimi (ekrandan, 01:45:00):

| Çizim | Anlamı |
|---|---|
| İçinde `Car` yazan dikdörtgen | Sınıf diyagramında gösterilen bir sınıf |
| İçinde altı çizili `kitt : Car` yazan dikdörtgen, altında kesikli dikey çizgi | Sıra (sequence) diyagramında gösterilen bir nesne |

Nesne gösterilirken önce nesnenin adı, sonra iki nokta, sonra sınıf adı yazılır. Bu dikdörtgen `Car` sınıfının bir örneğidir, tipi `Car`'dır. Sınıf ise nesnenin şablonu, yani tipidir; bu yüzden gösterimleri farklıdır.

UML derste iki iş için kullanılacak: sınıfları ve nesneleri göstermek, ve sınıflar/nesneler arasındaki etkileşimleri göstermek. Etkileşimler sıra diyagramlarıyla ya da iş birliği (collaboration) diyagramlarıyla gösterilebilir; derste sıra diyagramları kullanılacak.

## 9. Her Nesne Ayrı Bir Bireydir

Bir araba fabrikada üretildiğinde fiziksel bir varlıktır ve daha önce üretilmiş herhangi bir arabadan farklıdır. Her nesne farklıdır, çünkü durumları farklıdır. İki nesne oluşturulduğunda özelliklerden yalnız biri bile farklıysa durumları farklıdır. İki fiziksel varlığın en az bir özelliği her zaman farklı olacaktır: renk, marka, tip, lastik sayısı aynı olsa bile şasi numarası farklıdır.

Slayttaki içerik (ekrandan, 01:50:00):

- Aynı tipte iki nesne düşünün:
  - İkisinin özellik tipleri aynı olsa da bu özelliklerin değerleri farklı olacaktır: bu nesnelerin durumları (states) farklıdır.
  - Aynı duruma sahip iki nesne oluşturulsa bile bu iki nesne belleğin farklı bölgelerinde tutulur.
    - Java'da JVM bu amaçla benzersiz bir tanımlayıcı oluşturur. Bu işlem, diğer bellek yönetimi işlemleri gibi, programcıya saydamdır; o kadar saydamdır ki programcı müdahale edemez.
- Örnek: sokakta giden herhangi iki araba.
  - Bazı özellikler: model, renk, plaka.
  - Bu arabaların modelleri ve renkleri farklı olacaktır.
  - Aynı sarı Anadol STC'leri görseniz bile plakaları farklı olacaktır.
    - Sahte plaka yüzünden plakaları aynı olsa bile sürücüleri farklı olacaktır.

Hoca bellek tarafını şöyle açıkladı: aynı sınıftan iki nesne oluşturulduğunda bellekte iki farklı varlık olur. `Car` sınıfından üç nesne oluşturulursa fiziksel bellekte, farklı yerlerde üç ayrı nesne bulunur ve bunlara farklı referans numaralarıyla erişilir. JVM, program çalıştığı sürece her nesneye benzersiz bir tanımlayıcı atar ve nesneleri izler. Programcı nesnelerin bellekte nerede durduğuyla uğraşmaz; JVM bunu onun yerine yapar.

### 9.1 Aynı metoda farklı yanıt

İki farklı nesne, metotları çağrıldığında farklı yanıtlar verebilir, çünkü durumları farklıdır. Hocanın örneği: rengi, lastik sayısı ve diğer bütün özellikleri aynı iki araba düşünün (şasi numarası ve plaka dışında). Bu arabaların depolarındaki yakıt miktarı da farklıdır, çünkü her birini başka biri kullanır. Bu arabalardan bir görev, örneğin "hızlan" (accelerate) istenirse farklı davranırlar, çünkü yakıt miktarları farklıdır. Nesneler aynı tipte olsa, yani aynı sınıftan oluşturulsa bile, durumları farklı olduğu için davranışları farklıdır. Her nesne ayrı bir bireydir.

## 10. Nesnelere Mesaj Göndermek ve Üye Erişimi

### 10.1 Mesaj göndermek

Nesneler programlama birimleridir ve nesne yönelimli programlamada her şey bu birimlerle yapılır. Bu birimler birbirleriyle mesaj göndererek etkileşir. Bir nesnenin metodunu çağırmak, o nesneye mesaj göndermek demektir. Her nesne, programın genel işlevini yürütmek için diğer nesnelerin metotlarını çağırır, yani onlara mesaj gönderir. Derste bundan sonra "mesaj göndermek" terimi de kullanılacak.

Slayttaki içerik (ekrandan, 01:55:00):

- Bir nesneye neden mesaj göndeririz?
  - Bu nesneye bir şey yaptırmak için.
  - Bu nesnenin bir üyesine erişmek için.

### 10.2 Üye erişimi

Slayttaki içerik (ekrandan, 01:55:00):

- Bir nesnenin üye alanına şunlar için erişiriz:
  - Değerini değiştirmek (setting).
  - Değerini okumak (getting).
- Bir nesnenin üye metoduna şunlar için erişiriz:
  - Bir metodu, isteğe bağlı olarak bazı parametrelerle çalıştırmak.
  - Metot çağırmak C'de fonksiyon çağırmaya benzer.
    - Ama unutmayın: aksi belirtilmedikçe bir nesnenin metodu o nesnenin üyeleriyle çalışır. Aksi nasıl olur? Nesneler arasındaki farklı ilişki türlerini öğrenene kadar bekleyin.

Hoca, neredeyse her nesne yönelimli dilde veri alanlarına getter ve setter metotlarıyla erişildiğini söyledi. Bunların dışında nesnenin işlevleriyle ilgili başka üye metotlar da vardır: hızlanma, durma, çalıştırma gibi.

### 10.3 Sıra diyagramında mesaj

Hoca bir sınıfın ve ondan oluşturulmuş bir nesnenin UML gösterimini ve bir sıra diyagramı parçasını gösterdi. Solda bir nesne, `Car` sınıfından oluşturulmuş `kitt` nesnesinin `getPlate` metodunu çağırıyordu; yani `kitt` nesnesine `getPlate` mesajını gönderiyordu. `getPlate` metodunun gövdesi de gösteriliyordu ve sonuç olarak plaka değeri `String` olarak döndürülüyordu. Koddaki karşılığı nesnenin adı, nokta ve metodun adıdır (`kitt.getPlate()` biçiminde). Sıra diyagramları ileride ayrıntılı işlenecek.

<!-- BELİRSİZ: getPlate sıra diyagramı ve kodunu içeren slayt karelerde yok; diyagramın ve kodun tam metni doğrulanamadı, yukarıdaki anlatım yalnız altyazıya dayanıyor. -->

Hoca, solda "sınıf" diye anlattığı kutunun da aslında bir nesne olduğunu belirtti: bir nesne, başka bir nesnenin metodunu çağırarak, yani ona mesaj göndererek onun bir üyesine erişir. Nesne yönelimli bir program, nesneler arasında mesaj geçerek çalışır: programın yürütülmesi, nesnelerin birbirine mesaj göndermesi ve bu mesajların ilgili nesnelerce yürütülmesiyle gerçekleşir.

## 11. Paketler

Java'da programı sadeleştirmek ve daha iyi bir programlama pratiği oluşturmak için paketler (packages) kullanılır: aynı amaca hizmet eden sınıflar aynı pakette toplanır. Paket, `.java` dosyalarının konduğu bir klasör gibi düşünülebilir. Bir programda birden fazla paket olabilir ve bir paket başka bir paketin içinde bulunabilir.

Slayttaki içerik (ekrandan, 02:00:00):

- Sınıflar paket adı verilen soyut kaplarda birlikte gruplanabilir.
- Amaç, belirli bir ortak amaç için kullanılabilecek sınıfları gruplamaktır.

Slayttaki şema:

```text
package1
├── ClassA
├── ClassB
└── package2
    └── ClassC
```

Bir paketteki sınıfları koda eklemek için sınıfın (Java dosyasının) başına `import` deyimleri yazılır:

```java
import package1.ClassA;
import package1.*;
import package1.package2.*;
```

- Birinci deyim: `package1` altındaki `ClassA` sınıfına erişilebilir.
- İkinci deyim: `package1` altındaki bütün sınıflara erişilebilir.
- Üçüncü deyim: `package1`'in altındaki `package2`'nin bütün sınıflarına erişilebilir.
- Slayttaki uyarı: `package1` içe aktarıldığında `package2`'nin sınıfları dahil edilmez.

### 11.1 Neden paket

Zamanla zorunlu olarak aynı adlı sınıflar yazılır. Aynı adlı sınıflar aynı pakette bulunamaz, bu yüzden farklı klasörlere konmaları gerekir. Slayttaki örnekte aynı adlı iki sınıf farklı paketlerdeydi ve içe aktarmada çakışma olmuyordu (ekrandan, 02:00:00):

```text
java.io.File
com.fileWizard.File
```

Dosya yolu hiyerarşisi paket hiyerarşisini yansıtmalıdır:

```text
com.fileWizard.File  ->  com\fileWizard\File.java
```

Bu kodlar derste yalnız `import` satırı olarak gösterildi; tam bir program olmadığı için derlenmedi.

Hoca bir sonraki konunun görünürlük kuralları ve bilgi gizleme (visibility rules and information hiding) olduğunu, yani daha önce bir soruya yanıt verirken andığı erişim belirleyicilerinin (access modifiers) üye alanlara ve metotlara erişimi nasıl düzenlediğinin işleneceğini söyledi. Bilgi gizleme, kapsüllemenin ilk ve temel faydasıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:28:25): Sınıf için "nesnenin oluşturulma kurallarını tanımlayan şey" denebilir mi?

> **Çözüm (derste verildi):** Evet. Sınıf, bir nesnenin hangi özellikleri (attributes) ve hangi fonksiyonları (metotları) içereceğini tanımlayan şablondur. Nesneler bu şablona göre oluşturulur.

**Soru 2** (derste sözlü, 01:30:29): Sınıfların C'deki struct'lardan farkı yalnızca içine fonksiyon ya da metot yazılabilmesi mi?

> **Çözüm (derste verildi):** Hayır, yalnız bu değil. Sınıfa veri ve metotlar birlikte yazılır, ayrıca bu veriye ve metotlara kimin erişebileceği tanımlanır: herkes, yalnız sınıfın kendisi, sınıf ve alt sınıfları ya da aynı paketteki sınıflar. Bu, kapsüllemenin bir parçasıdır ve erişim belirleyicileriyle (access modifiers) sağlanır.

**Soru 3** (ekrandan, 01:55:00): Bir nesneye neden mesaj göndeririz?

> **Çözüm (slaytta verildi):** Nesneye bir şey yaptırmak ya da nesnenin bir üyesine erişmek için. Üye alana değerini değiştirmek (setting) ya da okumak (getting) için, üye metoda ise onu (isteğe bağlı parametrelerle) çalıştırmak için erişilir.

**Soru 4** (derste sözlü, 01:25:35): Bir sınıftan üretilen iki araba nesnesinin bütün özellikleri aynı olabilir mi?

> **Çözüm (derste verildi):** Hayır. Gerçek dünyada en az bir özellik farklıdır: şasi numarası, satıldıktan sonra da plaka. Bellekte ise durumları aynı olsa bile iki nesne farklı yerlerde tutulur ve JVM her birine benzersiz bir tanımlayıcı atar.

## Dersin Toparlaması

Bu derste önce dersin konu akışı ve kaynakları tanıtıldı, ardından Java'nın genel yapısı anlatıldı: Java SE, ME ve EE sürümleri; kaynak kodun (`.java`) `javac` ile `.class` uzantılı derlenmiş koda çevrilmesi ve bu kodun JVM tarafından makine koduna dönüştürülüp çalıştırılması; JDK ile JRE farkı; sürüm adları; Eclipse, NetBeans gibi IDE'ler ve Violet UML gibi modelleme araçları. İkinci bölümde nesne yöneliminin temelleri işlendi: nesne veri ve metotlardan oluşan ana programlama birimidir, kapsülleme bu ikisinin ayrılmazlığıdır ve veriye metotlarla erişilir; sınıf nesnelerin şablonu ve tipidir, nesne sınıfın bir örneğidir; durum bütün özellik değerlerinin kümesidir ve her nesne ayrı bir bireydir. Metot çağırmak nesneye mesaj göndermek olarak adlandırıldı, UML'de sınıf ve nesne gösterimi tanıtıldı ve sınıfların paketlerle gruplanması anlatıldı.

Ders, erişim belirleyicileri, görünürlük kuralları ve bilgi gizleme konusunun başında durdu; sonraki derste bu konudan devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
