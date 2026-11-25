# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin konu akışı
  - Dersin ilk bölümü: Java programlama diline genel bakış, nesneler ve sınıflar, UML sınıf şemaları, nesne durumu, davranışı ve metotları, ilkel tipler ve sarmalayıcı (wrapper) sınıflar, metot parametrelerinin inceliği (call-by-value-of-references), nesne ve sınıf ilişkileri, UML etkileşim (sequence) diyagramları, kalıtım ve soyut sınıflar, arayüzler ve çoklu kalıtım, çok biçimlilik (overriding ve overloading), enum sınıfları (ekrandan, 00:45:00).
  - Dersin ikinci bölümü: temel veri yapılarıyla (List ve Map) generic sınıflara giriş, istisna yönetimi (exception handling), tip dönüşümü (typecasting), dosyalar ve akışlarla çalışma (serileştirme), iç sınıflar (inner classes) ve çoklu iş parçacığına (multithreading) giriş. Zaman kalırsa Swing ile grafik kullanıcı arayüzü.
  - Önerilen kaynaklar: Deitel & Deitel "Java How to Program", Horstmann ve Cornell "Core Java 2" (Cilt I ve II), UML için Martin Fowler "UML Distilled" (ekrandan, 00:05:00).
- Java sürümleri (editions)
  - Standard Edition (SE): mobil cihazlar dışındaki her tür uygulama için. Derste bu sürüm kullanılır.
  - Micro Edition (ME): mobil cihazlarda çalışacak uygulamalar için.
  - Enterprise Edition (EE): uygulama sunucularında çalışacak uygulamalar için.
  - Özünde hepsi aynı dildir; ME ve EE yalnızca ek yetenekler sunar. SE öğrenilirse diğerlerine geçmek zor değildir.
- Java çalışma ortamı: derlenen ve yorumlanan diller
  - Slayttaki akış: kaynak kod (`.java`) → derleyici (`javac.exe`) → derlenmiş kod (`.class`) → yorumlayıcı (JVM) → çalıştırma. Derlenen dillerde ise derlenmiş kod bağlayıcı (linker) ile çalıştırılabilir koda dönüşür ve işletim sistemi tarafından doğrudan çalıştırılır (ekrandan, 00:50:00).
  - Java yorumlanan (interpreted) bir dil olarak anlatıldı: derlenmiş `.class` kodu doğrudan işlemcide çalışmaz; JVM (Java Virtual Machine) program çalışırken bu kodu makine koduna çevirir.
  - JVM, `java.exe` (komut satırı uygulamaları) ve `javaw.exe` (GUI uygulamaları) olarak gelir ve JRE (Java Runtime Environment) içindedir.
  - C derlenen dile örnektir: kaynak kod doğrudan makine koduna derlenir, arada yorumlayıcı yoktur. Hoca Python'u da Java gibi derleme ve yorumlama kısımları olan bir dil olarak andı.
  - JDK (Java Development Kit) derleyiciyi (`javac.exe`) ve kaynak kod yazmak için gereken kütüphaneleri içerir; IDE'yi içermeyebilir. JDK geliştiriciler, JRE son kullanıcılar içindir; JDK, JRE'yi kapsar (ekrandan, 00:50:00).
- Sürüm adları ve geliştirme araçları
  - Slayttaki sürüm örnekleri: `JDK 1.8.0_241` = Java 8.0, güncelleme 241; `JDK 1.11.0.9`. Güncellemeler küçük hata düzeltmeleri ve güvenlik iyileştirmeleri içerir, yılda birkaç kez çıkar. Ders notları JDK 1.5'e göre hazırlanmıştır (ekrandan, 00:55:00).
  - JDK indirilirken donanıma uygun sürüm (x86/i586 ya da x64) seçilir.
  - IDE (Integrated Development Environment) olarak Eclipse önerildi; NetBeans ve IntelliJ de kullanılabilir. Eclipse'te UML çizimi için eUML2 gibi bir eklenti, GUI için ayrı bir eklenti gerekir; kurulum için yönetici yetkisi gerekmez. NetBeans'in yerleşik GUI düzenleyicisi vardır, kurulumu yönetici yetkisi ister (ekrandan, 01:00:00).
  - UML modelleme aracı olarak Violet UML (hafif, bu ders için yeterli) ve Argo UML anıldı.
- Nesne (object)
  - Nesne, nesne yönelimli programlamanın ana programlama birimidir. Özellikler (attributes, veri) ve görevler (tasks, metotlar) içerir. Gerçek dünyadaki bir varlığa benzer (ekrandan, 01:20:00).
  - Araba örneği: marka (Ford), model (Mustang), renk, yıl, yakıt tipi (benzin/elektrik) özelliklerdir; çalıştırma, durdurma, hızlanma metotlardır.
- Kapsülleme (encapsulation)
  - Bir nesnenin verisi ve metotları birbirinden ayrılamaz. Veriye metotlar üzerinden erişilir (ekrandan, 01:20:00).
  - Bir özelliğin değeri getter (`getColor` gibi) ile okunur, setter (`setSize` gibi) ile değiştirilir.
- Sınıf (class)
  - Sınıf, nesneyi tanımlayan şablondur. Nesne ise bu şablondan üretilen gerçek dünya varlığıdır. Programı sınıflar olarak yazarız; program çalışınca asıl işi sınıflardan oluşturulan nesneler yapar.
  - Benzetmeler: fabrikada kâğıt üzerindeki araba tasarımı (sınıf) ve bu tasarımdan üretilen arabalar (nesne); kurabiye kalıbı (sınıf) ve kurabiyeler (nesne).
  - Ekrandaki örnekte `Car` sınıfından Audi, Nissan ve Volvo nesneleri; ikinci örnekte Red/Ford/Mustang, Blue/Toyota/Prius ve Green/Volkswagen/Golf değerlerine sahip üç araba nesnesi vardı (ekrandan, 01:25:00 ve 01:40:00).
  - Bir sınıftan istenen sayıda nesne oluşturulabilir.
- Nesne özellikleri: ilkel ve ilkel olmayan
  - İlkel (primitive) özellikler tek birim bilgi tutar: tam sayı, gerçel sayı, mantıksal değer gibi. Java'da sekiz ilkel veri tipi vardır.
  - İlkel olmayan (non-primitive) özellikler herhangi bir sınıftan nesnelerdir; yani bir sınıf da veri tipi olarak kullanılabilir (ekrandan, 01:35:00).
- Terimler (NYP terminolojisi, ekrandan, 01:45:00)
  - Data = member field = field = attribute.
  - State (durum): bir nesnenin bütün özelliklerinin değerlerinin kümesi.
  - Task = action = function = method = member method.
  - Members (üyeler) = metotlar + alanlar.
  - Class = type. `o`, `C` sınıfının bir nesnesiyse `o`, `C`'nin bir örneğidir (instance of `C`).
- UML gösterimi
  - Sınıf diyagramında sınıf, içinde sınıf adı yazan bir dikdörtgendir (`Car`).
  - Sıra (sequence) diyagramında nesne, `nesneAdı : SınıfAdı` biçiminde altı çizili yazılır (`kitt : Car`) (ekrandan, 01:45:00).
  - Nesneler arası etkileşimler sequence ya da collaboration diyagramlarıyla gösterilebilir; derste sequence diyagramları kullanılacak.
- Her nesne ayrı bir bireydir
  - Aynı tipteki iki nesnenin özellik tipleri aynıdır ama değerleri, yani durumları farklıdır. Durumları aynı olsa bile bellekte farklı yerlerde tutulurlar (ekrandan, 01:50:00).
  - JVM her nesneye benzersiz bir tanımlayıcı atar; bu ve diğer bellek yönetimi işlemleri programcıya saydamdır.
  - Durumları farklı olduğu için aynı sınıftan iki nesne aynı metot çağrısına farklı yanıt verebilir (yakıtı farklı iki arabanın "hızlan" çağrısına farklı davranması).
- Nesnelere mesaj göndermek
  - Bir nesnenin metodunu çağırmak, o nesneye mesaj göndermek demektir. Nesne yönelimli bir program, nesneler arasında mesaj geçerek çalışır.
  - Mesaj, nesneye bir iş yaptırmak ya da bir üyesine erişmek için gönderilir. Üye alana değerini değiştirmek (setting) ya da okumak (getting) için erişilir; üye metoda, isteğe bağlı parametrelerle çalıştırmak için erişilir (ekrandan, 01:55:00).
  - Kodda çağrı `nesneAdı.metotAdı()` biçimindedir (örnekte bir nesnenin `getPlate` metodu çağrılıp plaka `String` olarak döndürülüyordu). <!-- BELİRSİZ: getPlate sıra diyagramı ve kodunu içeren slayt karelerde yok; ayrıntılar yalnız altyazıdan. -->
- Paketler (packages)
  - Belli bir ortak amaçla kullanılan sınıflar paket adı verilen soyut kaplarda gruplanır. Paket, `.java` dosyalarının konduğu bir klasör gibi düşünülebilir; bir paket başka bir paketin içinde olabilir (ekrandan, 02:00:00).
  - Sınıfları kullanmak için dosyanın başına `import` deyimleri yazılır: `import package1.ClassA;`, `import package1.*;`, `import package1.package2.*;`. `package1` içe aktarıldığında `package2`'nin sınıfları dahil edilmez.
  - Farklı paketlerdeki sınıflar aynı adı taşıyabilir ve çakışma olmaz (`java.io.File`, `com.fileWizard.File`). Dosya yolu hiyerarşisi paket hiyerarşisini yansıtmalıdır: `com.fileWizard.File` → `com\fileWizard\File.java`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Nesne yönelimli programlama bir bilgisayar mühendisi için olmazsa olmaz bir derstir
  - Meslek hayatında nesne yönelimli program yazmak ve yazılmış bir programı okuyabilmek sürekli gerekir. Derste anlatılanların IDE'de denenmesi istendi.
- Sınıf ve nesne ayrımı
  - Sınıf şablondur (tip), nesne o şablondan üretilmiş gerçek varlıktır (örnek). "Nesnenin tipi sınıfıdır" ve "nesne sınıfın bir örneğidir" ifadelerinin ikisi de doğrudur.
- İki nesnenin bütün özellikleri aynı olamaz
  - Gerçek dünyada en az bir özellik (şasi numarası, plaka) farklıdır. Slayttaki ifadeyle bir özellik genellikle mantıksal benzersiz tanımlayıcı (UID) olarak belirlenir (ekrandan, 01:30:00).
- Terminolojiye dikkat
  - Hoca derste ve slaytlarda attribute, field, member field; method, function, action, task; class, type gibi eş anlamlı terimleri karışık kullanacağını, bunların aynı şey olduğunun bilinmesini istedi.

## Kısa Tekrar Notları

- Java kaynak dosyası `.java`, derlenmiş dosya `.class` uzantılıdır. Derleyici `javac`, yorumlayıcı JVM'dir (`java`/`javaw`).
- JDK = derleyici + kütüphaneler (+ JRE); JRE = JVM + çalışma ortamı.
- Java SE / ME / EE: genel amaçlı / mobil / uygulama sunucusu.
- Nesne = veri (özellikler) + metotlar; kapsülleme bunların ayrılmazlığıdır; veriye metotlarla erişilir.
- Sınıf = şablon = tip; nesne = örnek (instance).
- Durum (state) = bütün özellik değerleri; durumu farklı nesneler aynı metoda farklı davranır.
- Üyeler = alanlar + metotlar.
- Metot çağırmak = mesaj göndermek.
- UML: sınıf `Car` dikdörtgeni; nesne `kitt : Car` (altı çizili).
- İlkel tip sayısı 8; sınıflar ilkel olmayan tiptir.
- Paket = sınıfları gruplayan klasör; `import paket.*` alt paketleri kapsamaz.

## Detaylı Açıklamalar

- Derleme ve yorumlama
  - Derlenen bir dilde (C gibi) derleyici kaynak kodu doğrudan işlemcinin anlayacağı makine koduna dönüştürür; çalıştırma sırasında aracı bir program yoktur. Java'da ise derleyici kaynak kodu `.class` uzantılı ara koda çevirir. Bu kod henüz işlemcide çalışmaya hazır değildir. JVM, program çalışırken bu kodu makine koduna dönüştürür ve işlemci çalıştırır. Bu yüzden Java iki bileşenli düşünülür: kaynak kodu `.class`'a çeviren derleyici ve `.class`'ı çalıştıran yorumlayıcı (JVM).
  - Ders sonrası not: Hoca derleyiciyi anlatırken "java.exe" dedi; slayttaki gibi derleyici `javac.exe`'dir, `java.exe` ise JVM'yi başlatan yorumlayıcıdır.
  - Ders sonrası not: Hoca güncel sürümü "1.15" diye andı. Java 9'dan sonra sürümler "1." öneki olmadan adlandırılır (JDK 15 gibi); ders tarihinde güncel sürüm büyük olasılıkla JDK 15 idi, JDK 16 o ay içinde yayımlandı.
- Kapsülleme ve erişim
  - Hoca nesneyi ortada veri, çevresinde metotlar olan bir daire şeklinde gösterdi (ekrandan, 01:20:00). Dışarıdan veriye doğrudan değil, nesnenin metotlarıyla ulaşılır. Bir öğrencinin "sınıfın struct'tan farkı yalnızca içine fonksiyon yazılabilmesi mi?" sorusuna hoca şöyle yanıt verdi: sınıfa hem veri hem metot yazılır, ayrıca bu veriye ve metotlara kimin erişebileceği de tanımlanır. Erişim herkese açık, yalnız sınıfın içinden, sınıf ve alt sınıflarından ya da yalnız aynı paketteki sınıflardan olacak şekilde ayarlanabilir. Bu ayarlar erişim belirleyicileri (access modifiers) ile yapılır ve sonraki derste işlenecektir.
- Sınıf şablon, nesne varlık
  - Slayttaki örnekte nesne "belirli bir araba"dır: özellikleri model, plaka numarası ve renktir; eylemleri arabaya plakasını sormak ya da arabayı satmaktır. Örnek sınıf "Automobile"dır: arabaların özelliklerini ve metotlarını tanımlayan program kodudur (ekrandan, 01:30:00).
  - Ders sonrası not: Slaytta "You can create any number of classes from any different classes" yazıyordu; hoca bunun "objects" olması gerektiğini söyledi: bir programda herhangi bir sınıftan istenen sayıda nesne oluşturulabilir.
- Her nesne ayrı birey
  - Slayttaki örnek: sokakta giden iki araba. Modelleri ve renkleri farklıdır; aynı sarı Anadol STC'leri görseniz bile plakaları farklıdır; sahte plaka yüzünden plakalar aynı olsa bile sürücüleri farklıdır (ekrandan, 01:50:00). Bellekte üç `Car` nesnesi oluşturulursa üçü belleğin farklı yerlerindedir ve farklı referanslarla erişilir; JVM bunları benzersiz bir tanımlayıcıyla izler, programcı nesnenin bellekteki yeriyle uğraşmaz.
- Paketler neden gerekir
  - Zamanla gerekli olarak aynı adlı sınıflar yazılır. Aynı adlı iki sınıf aynı pakette (klasörde) olamaz; farklı paketlere konunca içe aktarmada çakışma olmaz. Derste bu bölümden sonra görünürlük kuralları ve bilgi gizleme (information hiding) konusuna geçileceği söylendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
