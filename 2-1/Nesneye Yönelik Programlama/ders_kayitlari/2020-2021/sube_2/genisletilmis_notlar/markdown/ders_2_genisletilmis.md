# Ders 2 Genişletilmiş Notu: Java Diline Genel Bakış ve Geliştirme Ortamının Kurulması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı, kaynakları ve içeriği
- 2. Java sürüm aileleri: JSE, JME, JEE
- 3. Java'nın çalışma modeli: derleme ve yorumlama
- 4. Java'nın tarihçesi ve sürüm adlandırması
- 5. 32 bit, 64 bit ve hangi JDK'nın kurulacağı
- 6. JDK'nın kurulması ve PATH ayarı
- 7. JDK API dokümantasyonu
- 8. IDE seçimi ve Eclipse'in kurulması
- 9. UML çizim aracı: Violet UML
- 10. Eclipse ile ilk proje ve "Merhaba dünya"
- 11. Soru-cevap: nesneye yönelik nedir, Java'da değer ve referans
- Örnek Sorular

## 1. Dersin amacı, kaynakları ve içeriği

### 1.1 Nesneye yönelim ve UML

Ders, Java dilini araç olarak kullanır ama bir "Java programlama" dersi değildir. Hoca bunu dersin adıyla açıklıyor: amaç Java öğretmek olsaydı dersin adı da öyle olurdu. Birinci amaç nesneye yönelimi öğretmek ve onu doğru biçimde kullanmayı içselleştirmektir. Nesneye yönelim, pratikte en yaygın kullanılan programlama yaklaşımıdır. Ders, nesneye yönelimin en yaygın kullanıldığı iki platform olan Java ve .NET'te ilerlemek için gereken altyapıyı vermeyi hedefler.

İkinci amaç UML modelleme diline giriş yapmaktır. Hoca bunu yapısal programlamanın öğretilişine benzetiyor. Algoritmalar ve yapısal programlama akış şemalarıyla görselleştirilerek öğretildi. Bunun tarihsel bir nedeni vardı: eskiden bilgisayara erişim zordu, delikli kartla yazılan bir programın çalışıp sonuç vermesi için günlerce sıra beklenirdi, bu yüzden "on kere düşünüp bir kere yapmak" gerekiyordu. Bugün bu zorunluluk kalmadı ama görerek ve görselleştirerek öğrenmek hâlâ öğrenmeyi kolaylaştırır.

Nesneye yönelik bir çözümde de önce modelleme ya da tasarım yapılır. Kod, gerçek dünyadaki bir problemi çözmek için yazılır. O yüzden problemdeki varlıklar koda eşleştirilmelidir. Önce varlıklar, varlıkların verileri, onlarla yapılabilecek eylemler ve aralarındaki ilişkiler yerine oturtulur, bir tasarım yapılır, sonra koda geçilir. Sektördeki yazılım geliştirme süreçleri de bu sırayla ilerler ve teknik belgelendirme bu süreçlerde önemlidir.

UML (Unified Modeling Language), sektörde yaygın kullanılan bir modelleme dili ailesidir. Yazılım yaşam döngüsünün her aşamasındaki etkinliği belgelemek için ayrı bir şema türü vardır. Bu derste UML sınıf şemaları ve UML sıralama (sequence) şemaları öğretilecek. UML bir hafta işlenip geçilecek bir konu değildir: her nesneye yönelik konu, enum ve generic sınıfların notasyonu dahil, UML karşılığıyla birlikte işlenecek. Kod yazmaya başlandığı andan itibaren sıralama şemaları da çizilecek.

### 1.2 Erken nesne ve geç nesne yaklaşımı

Programlama dilleri kronolojik olarak incelendiğinde yapısal programlama nesneye yönelikten önce ortaya çıkmıştır. Bu yüzden dünyada ve Türkiye'de bilgisayar mühendisliği müfredatlarının çoğu önce yapısal, sonra nesneye yönelik programlamayı öğretir. Doğrudan nesneye yönelikle başlayan ve başarılı olduğu eğitim bilimi çalışmalarıyla gösterilen programlar da vardır; bu çalışmalar lise düzeyinde bile yapılmıştır. Yine de genel eğilim önce yapısal programlamayı görmektir.

Bu nedenle bazı kitapların "early objects" (nesneler erken) ve "late objects" (nesneler geç) diye iki sürümü çıkmıştır. Ders notları doğrudan nesneye yönelimle başladığı için derse paralel giden sürüm early objects sürümüdür.

### 1.3 Önerilen kaynaklar

Slaytta önerilen kitaplar şunlardır (ekrandan, 00:05:00):

- Java How to Program, Harvey M. Deitel ve Paul J. Deitel, Prentice-Hall; 7. baskı ya da yenisi, early objects sürümü.
- Core Java 2 Volume I & II, C. S. Horstmann ve G. Cornell, Prentice-Hall; 7. baskı ya da yenisi.
- UML Distilled, 3. baskı (2003), Martin Fowler, Addison-Wesley.

Hoca Deitel kitabını pedagojik yönü güçlü, konuyu hem derinlemesine hem de pratikten kopmadan anlatan bir kaynak olarak öneriyor. Core Java iki ciltlidir ve Java platformunun neredeyse bütün özelliklerini oyuncak olmayan örneklerle anlatır. Derste ağırlıkla birinci cilt kullanılacak, ikinci ciltten de bir konu işlenecek. UML Distilled'ın adındaki "distilled" özü çıkarılmış anlamına gelir. Kitap her UML şema türünü anlatırken arkasındaki nesneye yönelik kavramları da anlatır: sınıf şemasıyla başlar, sınıf nedir, nesne nedir, aralarındaki ilişkiler nelerdir, hangi durumda nasıl modellenir diye ilerler. Ders notlarının anlatım tarzı da buna benzer. Nesneye yönelimi ve UML'yi birlikte öğreten tek bir kitap yoktur; bir dil kitabı ile bir UML kitabı ayrı ayrı çalışılır. Kitap almak zorunlu değildir; hocanın önceliği ders notlarının elde olmasıdır. Ders notlarındaki bütün örneklerin kaynak kodları da paylaşılmıştır.

### 1.4 Dersin içeriği

Slayttaki ders planı şöyledir (ekrandan, 00:30:00):

- Java programlama diline genel bakış
- Nesneler ve sınıflar
- UML sınıf şemaları
- Nesne durumu, davranışı ve metotlar
- İlkel türler ve sarmalayıcılar (wrappers), metot parametrelerinin incelikleri (call-by-value-of-references)
- Nesne ve sınıf iş birlikleri ve ilişkileri
- UML etkileşim (sıralama) şemaları
- Kalıtım ve soyut sınıflar
- Arayüzler ve çoklu kalıtım
- Çok biçimlilik, metot yeniden tanımlama (overriding) ve çoklu tanımlama (overloading)
- Enum sınıfları
- Temel veri yapıları (listeler ve map'ler) üzerinden generic sınıflara giriş
- Exception handling
- Tip dönüşümü (typecasting)
- Dosyalar ve akışlarla çalışma (serialization)
- İç sınıflar (inner classes)
- Çoklu iş parçacığına (multithreading) giriş

Hocanın açıklamalarına göre enum dahil ilk konular nesneye yönelimin temel kavramlarıdır. Generic yapılardan itibaren dile göre farklılaşan, Java'ya daha özgü ileri konulara geçilir. Generic sınıfların kullanımı liste ve map yapıları üzerinden görülecek, kendi generic sınıfımızı yazmak ders kapsamında olmayacak. C'de iki parametre aktarım biçimi vardı: call by value ve call by reference. Java'da tek biçim vardır: "call by value of references". Bu konu ayrıca işlenecek.

Exception handling'i hoca "aykırı durum yönetimi" diye çeviriyor. C alışkanlığında bir fonksiyon başarılıysa doğru, değilse yanlış ya da bir hata kodu döndürür. Exception handling bunun dışında ayrı bir denetim türüdür. Dosyalarla çalışmak için Java'ya özgü akış (stream) temelli serialization/deserialization yaklaşımı görülecek. Multithreading, aynı programı birden fazla paralel akış hâlinde çalıştırıp çok çekirdekli işlemcilerden yararlanmaktır. Bu, senkronizasyon problemlerini de getirir; derste bunların en temel çözüm yapıları görülecek.

Vakit kalırsa Swing ile grafik arayüz (GUI) kodlamaya başlanabilir. Hocaya göre iç sınıflar ve multithreading temeli alındıktan sonra GUI programı yazmak için gereken bütün altyapı edinilmiş olur ve Swing herhangi bir Java kitabından hızlıca çalışılabilir.

## 2. Java sürüm aileleri: JSE, JME, JEE

Java platformunun farklı ana sürüm aileleri vardır; bunlara "edition" denir. Slayttaki özet şöyledir (ekrandan, 00:40:00):

- **Standard Edition (JSE):** Mobil cihaz uygulamaları dışında her tür uygulamayı geliştirmeye uygundur. Derste temel alınan sürüm budur.
- **Micro Edition (JME):** Mobil cihazlar için uygulama geliştirmeye uygundur ve JSE kütüphanelerinin bir alt kümesini içerir.
- **Enterprise Edition (JEE):** JSE'yi ve bir uygulama sunucusu (application server) yazılımını içerir. Uygulama sunucusu JSE ile kodlanan uygulamalara çeşitli hizmetler verir. Çok katmanlı uygulamalar ve web servisleri gibi karmaşık uygulamalar bu hizmetlere ihtiyaç duyar; işlem (transaction) desteği bunlardan biridir. Temel uygulama sunucusunun adı "Sun Java System Application Server"dır. IBM WebSphere, BEA WebLogic ve Apache Tomcat gibi uyumlu başka sunucular da vardır.

Hoca JME'nin hedefini somutlaştırıyor: akıllı telefonlardan çok daha düşük donanımlı, 90'ların sonunda "Java uyumlu" diye satılan telefonlar ve set üstü uydu kutuları. Pratikte artık kullanılmıyor. Bugün akıllı telefonlar için daha geniş framework'ler var. JME'de yalnız `java.lang` paketi bulunduğu için gereken her şeyi sıfırdan kodlamak gerekir. Hoca normal mobil uygulama geliştirmede sekiz haftalık geliştirme çevrimlerinden söz edildiğini, aynı işin JME ile birkaç ay sürebileceğini söylüyor.

JEE'nin JSE'den tek farkı uygulama sunucusudur. Bu sunucu, uygulamaların bulutta ya da bir sunucuda çok kullanıcılı çalışması için kullanıcı hesapları, şifreleme ve güvenlik gibi hazır servisler sağlar. Firmalar bu sunucuyu temel alıp daha fazla yetenek sunan sürümler üretmiştir. Ders JSE üzerinde kalacak.

## 3. Java'nın çalışma modeli: derleme ve yorumlama

### 3.1 Kaynak koddan çalışmaya

Java'nın temel özelliklerinden biri yorumlanan bir dil olmasıdır. Slayttaki şema şu akışı gösterir (ekrandan, 00:45:00):

```text
Source code --(Compiler / compilation)--> Compiled code --(Linker / linking)--> Executable code --(OS)--> Execution
   .java            javac.exe                .class
                                   Compiled code --(Interpretion / Interpreter)--------------------> Execution
                                                         Java Virtual Machine (JVM)
```

Hangi dil kullanılırsa kullanılsın, önce insanın okuyup anlayabileceği bir kaynak kod yazılır. Java'da kaynak kod `.java` uzantılı dosyalarda tutulur. Sonra derleyici (compiler) devreye girer ve derlenmiş kod ortaya çıkar. Bu kod artık ikili (binary) biçimdedir, insanın okuyabileceği durumda değildir; Java'da byte kod seviyesindedir ve `.class` dosyalarında tutulur.

Bu noktadan sonra iki yol vardır. C gibi dillerde bir bağlayıcı (linker) program devreye girer. Programın kendi kodunu, işletim sisteminden hizmet alınması gereken kaynaklarla (Windows'taki DLL dosyaları gibi bağımlılıklarla) bir araya getirir ve işletim sisteminin doğrudan çalıştıracağı bir kod üretir. Java gibi yorumlanan dillerde bağlama yapılmaz. Yorumlayıcı denen bir program byte kodu okur ve işletim sistemine yönlendirir. Hoca bunu araya bir tercümanın girmesine benzetiyor.

### 3.2 Yorumlamanın maliyeti ve HotSpot

Araya tercüman girmesinin küçük de olsa bir ek yükü vardır. Eski sistemlerde ve Java'nın 1.2 sürümüne kadar bu yük hissedilir düzeydeydi. Sonraki sürümlerde yorumlayıcı akıllandırıldı: byte kodu komut komut sırayla çalıştırmak yerine önce bir kod iyileştirmesi (optimizasyon) yapılıp iyileştirilmiş kod çalıştırılmaya başlandı. Hoca, bir milyon elemanlı bir bağlı listede sıralama, araya eleman ekleme ve silme gibi işlemlerde doğrudan çalıştırılan dillerle başa baş noktaya gelindiğini söylüyor. `java -version` çıktısında görülen "HotSpot" bu çalıştırma öncesi iyileştirme sürecidir ve geçmişi 1.2 sürümüne dayanır.

> **Ek bilgi (derste anlatılmadı):** HotSpot gibi sanal makineler sık çalışan kod parçalarını çalışma sırasında makine koduna derler; bu tekniğe "just-in-time (JIT) derleme" denir. Böylece yorumlamanın ek yükü özellikle uzun süre çalışan programlarda büyük ölçüde ortadan kalkar.

### 3.3 Yorumlanan dillerin avantajları

Güncel programlama dilleri genelde yorumlama yolunu seçer, çünkü bu yolun iki önemli avantajı vardır.

Birincisi **taşınabilirliktir**. Yazılan kodu herhangi bir ortamda çalıştırmak için tek gereken o dilin yorumlayıcısıdır. Yorumlayıcı varsa kod bütün sistemlerde aynı biçimde çalışır. Bunun önemi arttıkça .NET dahil güncel ortamlar yorumlanan biçimde çalışmaya yönelmiştir.

İkincisi **güvenliktir**. Doğrudan çalıştırılan dillerde bilerek ya da bilmeyerek zararlı kod yazmak, basit bir hatayla bütün sistemi çökertmek çok daha kolaydır. Hoca örnek olarak işaretçi kullanan bir C kodunda bir yıldızı fazla ya da eksik yazmayı veriyor. Yorumlanan dillerde yorumlayıcı programa güvenli bir çerçeve sunar ve bu çerçeveyi aşmak zorlaşır. Bu hem güvenlik hem güvenilirlik avantajıdır.

Hoca performans kaygısına "zincir en zayıf halkası kadar güçlüdür" diyerek cevap veriyor. Artık büyük bilgi sistemleri yazılıyor. Bir kod parçasının 5 ms yerine 8 ms'de çalışması arasındaki 3 ms'lik fark, bu servislerin ağ üzerinde farklı sunuculardaki servislerden yararlanırken yaşadığı ağ gecikmesinin yanında büyük olasılıkla önemsiz kalır. İşlem gücü de her yıl artıyor. Bu nedenlerle taşınabilirliğe ve güvenliğe daha çok önem veriliyor.

### 3.4 JDK, JRE ve JVM

Java terminolojisinde derleyicinin adı `javac.exe`'dir. Yorumlayıcının adı Java Sanal Makinesi'dir (Java Virtual Machine, JVM). Slayttaki kutular şunları söyler (ekrandan, 00:45:00):

- **JDK (Java Development Kit):** `javac.exe`'yi içerir; IDE'yi isteğe bağlı olarak içermez.
- **JVM:** Komut satırı ve GUI uygulamaları için `java.exe`/`javaw.exe`; JRE (Java Runtime Environment) içinde yer alır.
- JDK geliştiriciler, JRE son kullanıcılar içindir. JDK, JRE'yi içerir.

Yani kod yazıp çalıştırmak için JDK gerekir. Yazılımı dağıtacağımız müşterilerin JDK'ya ihtiyacı yoktur; yalnız Java sanal makinesi (JRE) yeterlidir. Eskiden bazı JDK dağıtımları seçimlik olarak NetBeans ile birlikte dağıtılırdı.

> **Ders sonrası not:** Altyazıda derleyicinin adı "Java.exe" diye geçiyor; bu büyük olasılıkla Whisper hatasıdır. Slaytta da yazdığı gibi derleyici `javac.exe` ("Java compiler"), `java.exe` ise sanal makinedir.

## 4. Java'nın tarihçesi ve sürüm adlandırması

### 4.1 Sun Microsystems ve "Write Once, Run Anywhere"

Java'nın ilk sürümü 1.0, temel nesneye yönelik özellikleri karşılayan bir dil olarak dikkat çekti ve "umut verici" (promising) bir dil olarak değerlendirildi. Java ilk zamanlarında Sun Microsystems'ın ürünüydü. Sun, yüksek performanslı ve yüksek erişilebilirlikli (high availability) sunucular, iş istasyonları ve haberleşme donanımlarıyla bilinen bir firmaydı ve bunlarda kendine özgü bir Unix dağıtımı çalışıyordu.

Hoca, temel olarak donanımla bilinen bir firmanın neden bir programlama dili çıkardığını şöyle açıklıyor. Sun'ın donanım yelpazesi çok genişti: en üstte çok çekirdekli, çok işlemcili RISC sunucular, en altta ince istemciler (thin client), set üstü kutular ve o zamanın yeteneği az cep telefonları vardı. Bunlar ağ üzerinden sürekli haberleşiyordu. Sun bu yelpazenin tamamına hitap edecek bir dil isteyerek kendi ekosistemini kurup genişletmeyi amaçladı. Slogan da buna uygundu: "Write Once, Run Anywhere", bir kere yaz, her yerde çalıştır.

Sun dili kapalı bir dil olarak sunarsa destekçisinin az olacağının farkındaydı. Dil açık bir yapıyla geliştirildi: isteyen bireysel ya da kurumsal her katılımcı Java topluluğuna üye olup dilin ilerlemesinde söz sahibi olabilir. Bu yüzden Java hiçbir zaman tek bir firmanın dikte ve denetiminde olmadı. Hoca bunu .NET platformuyla karşılaştırıyor: .NET de Mono gibi projelerle Linux gibi farklı işletim sistemlerinde açık kaynak birlikte çalışabilirliği ilan etti, ama hocaya göre Microsoft desteği kesilirse iş yürümez. Java'da ise sahibi (önce Sun, sonra Oracle) desteği çekse bile tamamen açık kaynak olan OpenJDK kullanılmaya devam edilebilir. Java'nın hâlâ tercih edilmesinin bir nedeni de yazılım yaşam döngüsünün farklı adımlarında kullanılan araç ve IDE'lerin çoğunun açık kaynak olmasıdır.

**Soru:** Oracle, Java'yı kişisel kullanım dışında lisanslı bir ürüne çevirmedi mi?
**Cevap:** Java kodunun kendisi değil. Oracle uygulama sunucusuna bazı kısıtlamalar koymuş olabilir, ama o tek seçenek değildir; IBM ve Apache gibi, bazıları tamamen özgür yazılım olan alternatifler vardır. Hoca, büyük kurumsal kullanımda (ör. çok sayıda çekirdekli sistemlerde) bazı lisanslama konuları olabileceğini, bunun ayrıntısını bilmediğini ve bu ücretlerin genelde kamuya açık duyurulmadığını söyledi. Bunun dışında Java ticari projelere sorunsuz dahil edilebilir; örneğin mobil uygulama satışında ödenen pay uygulama mağazasınadır.

### 4.2 Sürümler ve iki adlandırma kanalı

Slayttaki eski ve yeni adlandırma tablosu şöyledir (ekrandan, 01:05:00):

| Geliştirici sürümü (eski yol) | Ürün sürümü (yeni yol) |
| --- | --- |
| Java 1.0, 1.1 | — |
| Java 1.2 | Java 2 Platform |
| Java 1.3 | Java 2 SE 3 (J2SE3) |
| Java 1.4, 1.5 | J2SE4, J2SE5 |
| Java 1.6 {Sun} | Java Platform Standard Edition, version 6 (Java SE6 / JSE6) |
| Java 1.7 {Oracle} | Java Platform Standard Edition, version 7 (Java SE7 / JSE7) |
| Java 1.8 | Java Platform Standard Edition, version 8 (Java SE8 / JSE8). Eski sistemler için LTS (Long Term Support); bu derste işlenmeyen yeni dil özellikleri getirir |
| Java 1.9-1.10, 1.12-1.14 | Kısa süreli sürümler (~6 ayda bir), desteği bitti |
| Java 1.11 | Java SE11. LTS; bu derste işlenmeyen dil özellikleri ve araçlar |
| Java 1.15 | Java SE15. Güncel sürüm |

Hoca tabloyu satır satır anlattı:

- **1.0 ve 1.1:** 1.0 henüz yetersizdi, bir kavram kanıtı (proof of concept) gibiydi. 1.1 dilin yeteneklerini ve sınıf kütüphanesini artırdı ama sektördeki ağır bilgi sistemleri için hâlâ yeterli değildi.
- **1.2 ve "Java 2":** 1.2 ile dil ve sınıf kütüphaneleri çok zenginleşti. Java artık yazılım sektöründe tercih edilebilecek bir ana dil ve platform hâline geldi. Hocanın tahminine göre pazarlama ekibi bunu fırsat bildi ve 1.2'yi "Java 2 Platform" diye sundu. Hoca bunu teknik olarak yanlış buluyor. Sürüm numarasında ilk basamak ana sürümü, ikinci basamak ara sürümü gösterir. "Java 2" adı 2.0 gibi bir ana sürüm geçişi izlenimi verir; oysa 1.1'den 1.2'ye geçiş bir ara sürüm geçişidir. Birçok kişi bundan hoşlanmadığı için Java'nın kendi sitesinde ve teknik belgelerde bile 1.2 adı kullanılmaya devam etti. Böylece iki adlandırma kanalı ortaya çıktı.
- **1.3, 1.4, 1.5:** "Java 3" demek iyice abartı olacağı için "Java 2, Standard Edition 3" (ya da Enterprise/Micro Edition 3) dendi; kısaltmaları J2SE3, J2EE3 gibiydi. Teknik ad 1.3 olarak sürdü. 1.4 ve 1.5'te aynı taktik uygulandı (J2SE4, J2SE5).
- **1.6:** "Java 2" ifadesi atıldı. Ad "Java Platform Standard Edition Version 6" oldu; kısaltması Java SE6 ya da JSE6, Enterprise Edition için JEE6.
- **1.7:** Bu arada Oracle, Sun Microsystems'ı satın almaya karar verdi. Oracle bir yazılım firmasıdır; veritabanı ve dördüncü kuşak uygulama geliştirme araçlarıyla bilinir ve böylece donanım sektörüne de girdi. Satın alma bir süreç içinde gerçekleşti. Tamamen Sun tarafından çıkarılan son sürüm 1.6 oldu; 1.7 tamamen Oracle denetiminde çıktı. Lisanslanma ya da kapalı kaynağa dönme endişeleri oldu, ama Oracle Java'nın açık yönetim yapısını sürdürdü ve adlandırma değişmedi (JSE7).
- **1.8:** Eski işletim sistemi ve donanımların (legacy systems) desteklendiği sürümdür ve uzun süreli destek (LTS) sürümlerinden biridir. Çıkalı yıllar olduğu hâlde güvenlik açıkları, performans sorunları ve hatalar bulundukça düzeltilip güncellemesi yayımlanır.
- **1.11:** Güncel, 64 bit işlemci ve işletim sistemine sahip bilgisayarlar için LTS sürümüdür.
- **Ara sürümler:** Güncel sürüm yaklaşık altı ayda bir, yani yılda iki kez yenilenir. Hoca, güncel sürüm o sırada 1.15 iken en geç altı ay içinde 1.16'nın çıkacağını, ama ona geçmeye hiç gerek olmadığını söyledi.

> **Ders sonrası not:** Slayt ve hoca Java 9 sonrası sürümleri "Java 1.11", "Java 1.15" diye adlandırıyor. Java 9'dan itibaren resmî sürüm numarası "1." önekini bırakmıştır; `java -version` çıktısı büyük olasılıkla "11.0.x" biçimindedir. Ders bağlamında 1.11 = Java 11, 1.15 = Java 15 diye okunmalıdır.

### 4.3 Java 1.5'in önemi

Hoca 1.5'i kritik bir sürüm olarak vurguluyor. Bu sürümde dile hem söz dizimi hem yetenek açısından önemli eklemeler yapıldı: generic sınıflar, gelişmiş for döngüsü (extended for ya da for-each) ve exception handling'de küçük bir ek notasyon desteği. <!-- BELİRSİZ: exception handling'deki ek notasyonun ne olduğu altyazıda açık değil. --> 1.5'ten itibaren söz dizimi ve kullanım geliştirmeleri sürdü, 1.6'da da devam etti. Ders notları bu yetenekleri içerdiği için 1.5 kökenlidir.

> **Hocanın vurgusu:** Bir Java kitabı seçerken ilk sayfalarına bakıp hangi Java sürümü üzerine yazıldığını kontrol edin; en az 1.5 olmalıdır.

### 4.4 Sürüm numarasının basamakları ve güncellemeler

Java'nın eski sürüm numarası dört basamaklıdır (ör. 1.8.0.x). Hoca, Java'yı kullandığı süre boyunca üçüncü basamağın sıfırdan farklı bir değer aldığını görmediğini söylüyor. Dördüncü basamak "update" diye adlandırılır ve kimi zaman sık, kimi zaman seyrek değişir. Update'ler küçük hata düzeltmeleri ve güvenlik açıklarının kapatılması içindir; yılda birkaç kez çıkabilir.

Yeni bir update'e geçmek zorunlu değildir. JDK ile birlikte kurulan JRE her yeni update'te güncelleme isteyip istemediğinizi sorar; hoca bu bildirimlerin ayarlardan kapatılmasını öneriyor. Ayrıca yeni update'in kurulum dosyası doğrudan çalıştırılırsa önceki sürüm kaldırılmadan yanına kurulur ve boşuna yer kaplar. Bu yüzden update'e geçilecekse önce eski JDK tamamen kaldırılmalıdır.

> **Hocanın vurgusu:** Bütün bu uğraşa gerek yok. Java 11'i ya da 15'i indirin; çok özel bir bitirme projesi konusu olmadıkça mezun olana kadar rahatlıkla kullanabilirsiniz.

## 5. 32 bit, 64 bit ve hangi JDK'nın kurulacağı

Bilgisayarın temel bileşeni mikroişlemcidir. Mikroişlemcide komutlar ve veriler bitlerden oluşan byte'lar hâlinde işlenir ve saklanır. Farklı işlemci ailelerinde tam sayı gibi veri türleri ve makine komutları farklı byte uzunluklarıyla simgelenir. Bilgisayar sistemi, işlemci, bellek ve diğer bileşenler arasında ikili veriyi sürekli byte'lar hâlinde taşır. Bu taşımanın kaç bit genişliğinde yapıldığı önemlidir; hoca bunu bir otoyoldaki şerit sayısına benzetiyor. Hocanın anlatımına göre Intel 80386 ile 32 bite, Pentium ile 64 bit veri yoluna geçildi; işletim sistemleri bu genişliği desteklemekte daha yavaş kaldı ve maliyet nedeniyle 32 bit işletim sistemleri hâlâ kullanılabiliyor.

> **Ek bilgi (derste anlatılmadı):** Veri yolu genişliği ile işlemcinin komut kümesi mimarisinin bit sayısı farklı şeylerdir. Pentium'un dış veri yolu 64 bitti, ama x86 işlemcilerde 64 bit adresleme ve 64 bit işletim sistemi desteği büyük olasılıkla 2000'lerin başındaki x86-64 (AMD64) mimarisiyle geldi.

32 bit işletim sistemi daha küçük, 64 bit işletim sistemi daha geniş bir bellek uzayını adresleyebilir. Bilgisayarda 4 GB bellek olsa bile 32 bit işletim sistemi kuruluysa belleğin tamamına erişilemez; hoca kullanılabilir miktarı yaklaşık 3,2 GB olarak verdi. Windows'ta hangi tür işletim sistemine sahip olunduğu, "Bilgisayar" simgesine sağ tıklayıp "Özellikler" denince açılan sistem bölümünde "Sistem türü" satırından öğrenilir. Hoca kendi makinesinde bu satırı gösterdi: "64 bit İşletim Sistemi, x64 tabanlı işlemci" (ekrandan, 01:20:00).

Hangi JDK'nın kurulacağı buna göre seçilir:

- 32 bit işletim sistemi: Java 8 (1.8).
- 64 bit işletim sistemi: LTS olan Java 11 ya da o sırada en güncel sürüm olan Java 15.

En güncel sürümü kullanmak şart değildir. Hoca, kullanması gereken bazı Java tabanlı yazılımlar JDK 11 istediği için kendisinin 11'de kaldığını söyledi. Ayrıca kullanılan JDK sürümünü IDE'nin de desteklemesi gerekir.

## 6. JDK'nın kurulması ve PATH ayarı

Başlangıç noktası Oracle'ın Java sayfasıdır (ekrandan, 01:25:00). "Download Java" düğmesiyle kullanıma açık sürümlerin listelendiği indirme sayfası açılır. Buradan Java 15, Java 11 ya da (32 bit için) Java 8'in JDK indirmesi seçilir. Bu dosya yalnız JDK içerir, IDE içermez. Hoca eskiden JDK'yı sade indirip NetBeans istenirse onu ayrıca son sürümüyle kurmayı önerdiğini söyledi.

Kurulum dosyası çalıştırılabilir bir dosyadır ve önerilen varsayılan yola kurulabilir. Hoca komut satırı çalışmalarında kolaylık olsun diye JDK'yı diskin kökünde kısa bir dizine, örneğin `C:\jdk11` dizinine kuruyor; JRE'yi ise Program Files altında bırakıyor. Kurulum, komut satırından çalışmak için gerekli tanımları kendisi yapar.

Kurulumun doğru olup olmadığını sınamak için işletim sisteminden bir komut satırı açılır ve şu komut verilir:

```text
java -version
```

Bu komut Java sanal makinesine sürüm bilgisini bildirmesini söyler. Çıktıda kurulu sürüm ve HotSpot sanal makinesi bilgisi görünüyorsa JDK düzgün kurulmuştur. <!-- BELİRSİZ: hocanın ekranındaki java -version çıktısının tam metni karede yok; altyazıdaki "1.0.9.7" okunamadı. -->

Komut tanınmıyorsa Java komut satırı araçlarının yolu sisteme tanıtılmamış olabilir. Bunun için:

1. "Bilgisayar" simgesine sağ tıklanıp "Özellikler" seçilir.
2. "Gelişmiş sistem ayarları" ve ardından "Ortam Değişkenleri" açılır.
3. Kullanıcı ya da sistem düzeyindeki `Path` değişkeni düzenlenir.
4. JDK'nın kurulduğu dizindeki `bin` dizini yeni bir satır olarak eklenir.

Hocanın ekranında listenin sonuna `C:\jdk11\bin` satırı eklenmiş görünüyor; listenin başında da kurulumun eklediği `C:\Program Files\Common Files\Oracle\Java\javapath` satırı var (ekrandan, 01:30:00). Hoca bu ikinci yolun genel bir kısa yol olduğunu açıkladı: JDK nereye kurulduysa onu gösteren sembolik bağlantılar içerir, böylece ayrıca PATH eklemeye çoğu zaman gerek kalmaz. Bu yol listede olduğu hâlde `java -version` çalışmıyorsa bir sorun vardır. O durumda JDK Denetim Masası'ndan kaldırılır, bilgisayar yeniden başlatılır ve JDK yeniden kurulur.

## 7. JDK API dokümantasyonu

### 7.1 Dokümantasyonun yerel kurulumu

Hoca yalnız JDK'yı değil, JDK dokümantasyonunu da kurmayı öneriyor. Dokümantasyon çevrim içi de mevcuttur, ama her zaman ağa bağlı olunmayabilir, mobil veri kotası azalmış olabilir ya da sayfada bir sorun çıkabilir. Dokümantasyon, indirilen Java sürümünün indirme bağlantısının altındaki bağlantıdan alınır. Sıkıştırılmış bir dosyadır ve içinde tek bir `docs` klasörü vardır. Hoca bu klasörü JDK'nın kurulduğu dizine açmayı alışkanlık edinmiş.

### 7.2 Modüller, paketler ve sınıf sayfaları

API sayfasında temel olarak `java.base` modülü, yani Java'nın ana temel bileşenleri kullanılacak. `java.base` tıklanınca dildeki temel paketler listelenir. Sınıf kitaplıklarına **paket** denir; kendi yazdığımız sınıfları da paketler altında toplayabiliriz. Hocanın örnek verdiği paketler:

- `java.io`: giriş/çıkış işlemleri.
- `java.lang`: dilin en temel çekirdek özellikleri. İçe aktarılması (import) gerekmeyen tek pakettir, otomatik eklenir.
- `java.math`: matematik işlemleriyle ilgili sınıflar ve metotlar.
- Tarih işlemleri ve generic sınıflarla sık yapılan işlemler için önemli sınıflar içeren bir paket. <!-- BELİRSİZ: altyazıda "Java JT paketi" geçiyor; bağlamdan büyük olasılıkla java.util. -->
- `javax` ile başlayan paketler: "x", "extended" demektir. Bu paketler JDK 1.2 zamanından gelir. Aradan on yıldan fazla geçtiği hâlde geriye doğru uyumluluk için adları değiştirilemiyor.

Bir paket tıklanınca o paketin ne tür işlemlere yönelik olduğu anlatılır, ardından paketteki bütün arayüzler ve sınıflar listelenir. Örnek olarak `java.lang` paketindeki `String` sınıfı açıldı. `String`, karakter katarlarını simgeleyen sınıftır ve ilk haftalardan itibaren kullanılacak. Sınıf sayfasında şunlar bulunur:

- Sınıf bir kalıtım hiyerarşisi içindeyse o hiyerarşi.
- Sınıf ve arka planı hakkında genel bilgi.
- Bütün üye alanlar.
- Kurucu metotlar (constructor). Kurucu metot, bir nesne oluşturulurken çağrılan metottur; bir sonraki derste ayrıntılı işlenecek.
- Bütün üye metotlar.

### 7.3 Deprecated kurucular ve metotlar

Hoca `String` sayfasında kurucu listesini gösterdi (ekrandan, 01:35:00). Örneğin `String()` boş bir karakter dizisini temsil eden yeni bir `String` nesnesi oluşturur, `String(byte[] bytes)` bir byte dizisini platformun varsayılan karakter kümesiyle çözerek `String` oluşturur. `String(byte[] ascii, int hibyte)` ve `String(byte[] ascii, int hibyte, int offset, int count)` ise "Deprecated. This method does not properly convert bytes into characters." diye işaretlidir.

**Deprecated**, eskimiş demektir. Böyle bir kurucu JDK 11'de hâlâ desteklenir ama ileriki bir sürümde kaldırılabilir. Hocanın açıklamasına göre bir kullanım genellikle bazı şeyleri eksik yaptığı ve bu eksiği düzeltmek daha esnek olmayan tasarımlara yol açacağı için eskimiş sayılır ve yerine bambaşka bir yöntem önerilir. Yazdığımız kodda deprecated metotlar varsa onları önerilen yeni kullanıma taşımamız gerekir; bu işaret bunun için vardır.

Ardından `compareTo` metodu açıldı. Bu metot parametre olarak başka bir string alır ve iki string'i alfabetik sıraya göre karşılaştırır. Metodun ayrıntı sayfasında ne işe yaradığı, aldığı parametre ve hangi durumda ne döndürdüğü ayrıntılı anlatılır.

> **Hocanın vurgusu:** Bir dil dokümantasyondan öğrenilmez; iyi anlatılmış bir kitaptan ve diğer kaynaklardan öğrenilir. Ama ders boyunca hangi yeteneklerin hangi paketlerde olduğunu öğreneceksiniz. Sonra bir şeyi nasıl yapacağınızı araştırmanız gerektiğinde kitapta aramak verimsiz olabilir. Sınıfın adını tahmin edip metot listesinden işinize yarayacak olanı bularak en ayrıntılı bilgiye dokümantasyondan ulaşırsınız. Dokümantasyonu el altında açık tutun.

Sıralama şöyle özetlendi: önce uygun JDK'yı indirin, sonra dokümantasyonunu, ardından bir IDE seçin. Hoca dokümantasyonun eskiden üç çerçeveli (paketler, sınıflar, ayrıntı) olduğunu, artık tek sayfalı gezinmeye geçildiğini de ekledi.

## 8. IDE seçimi ve Eclipse'in kurulması

### 8.1 IDE seçimi

IDE (Integrated Development Environment) seçimi serbesttir: Eclipse, NetBeans, JCreator, IntelliJ ya da herhangi biri olabilir. İsteyen kodu Notepad++ ile yazıp komut satırından da derleyebilir, ama bu daha zordur ve ders kapsamında gerekmez. Hoca derste örnekleri Eclipse ile yapacak. Slayttaki ücretsiz Java geliştirme araçları listesi şöyledir (ekrandan, 01:50:00):

- **Eclipse** (http://www.eclipse.org): ayrı indirilir. UML şeması çizmek için eUML2 gibi bir eklenti (plug-in) ve GUI uygulaması yazmak için ayrı bir eklenti kurmak gerekir. Bilgisayarda yönetici yetkisi gerekmez; yalnız zip dosyası açılır.
- **NetBeans:** ayrı indirilir (eski sürümlerde JSE ile birlikte isteğe bağlı gelirdi). UML çizimi için bir eklenti gerekir. Yerleşik bir GUI düzenleyicisi vardır. Kurulum için yönetici yetkisi gerekir.

### 8.2 Eclipse'i indirmek

Eclipse `eclipse.org/downloads` adresinden indirilir (ekrandan, 01:40:00). Eclipse, farklı eklentilerle çok değişik yetenekler kazandırılabilen zengin bir platformdur. Sayfadaki doğrudan indirme düğmesi yükleyiciyi getirir ve daha uzun sürer. Hoca bunun yerine "Download Packages" bağlantısını öneriyor. Orada:

- **Eclipse IDE for Java Developers** (~321 MB): klasik JSE uygulamaları için daha hafif paket, ders için yeterli.
- **Eclipse IDE for Enterprise Java Developers** (~500 MB): ders için gerekmez.

Yeni sürümlerin yalnız 64 bit paketi vardır. 32 bit gerekiyorsa "Older Versions" altında eski sürümlere bakılabilir; hoca örneğin Eclipse Neon 3 paketlerinde 32 bit seçeneğin bulunduğunu gösterdi (Java geliştirici paketi ~161 MB). Adlarda geçen "RC", "release candidate" demektir.

Eclipse'in ayrıca kurulması gerekmez. İnen zip dosyası istenen yere açılır ve içindeki `eclipse.exe` çalıştırılarak IDE açılır.

## 9. UML çizim aracı: Violet UML

Ders notlarında 14. yansıdan itibaren küçük küçük UML şemaları vardır. Proje ödevinde tasarımı anlatan bir UML sınıf şeması istenebilir. Sınavlarda genellikle sınıf şeması hazır verilir ama bazı ayrıntılar gizlenebilir; bir sıralama şeması çizmek ya da verilen bir sıralama şemasından Java kodu oluşturmak istenebilir. Bu yüzden bir UML çizim aracı gerekebilir.

Genel amaçlı çizim araçları ya da çevrim içi çizim araçları kullanılabilir, ama bunlarda UML notasyonuna ait şekiller bulunmayabilir. Hocanın önerisi **Violet UML**'dir; slayta göre hafiftir ve bu ders için yeterlidir, Argo UML de bir alternatiftir (ekrandan, 01:50:00). Hoca, yeni sürümün eski sürümle çizilen şemalara geriye doğru uyumlu olmadığı için eski bir sürümde kaldığını söyledi.

Violet UML'in kendisi küçük bir Java uygulamasıdır. `.class` dosyaları bir araya getirilip bir `.jar` dosyası hâlinde paketlenerek kullanıma sunulabilir; Violet de böyle paketlenmiştir. Bilgisayarda JRE kuruluysa (JDK kurulunca JRE de gelir) `.jar` dosyasına çift tıklamak uygulamayı çalıştırır. Hoca kısayolun simgesini kendi seçtiği bir simgeyle değiştirmiş; bu zorunlu değil.

Kullanımı şöyledir:

- Yeni bir sınıf şeması (class diagram) ya da sıralama şeması (sequence diagram) oluşturulur. Bu ders kapsamında bu ikisi gerekecek. Durum (state), etkinlik (activity) ve kullanım durumu (use case) şemaları sonraki yılın yazılım mühendisliği dersinde gerekecek.
- Paletten ilgili bileşen seçilip tıklanarak yerleştirilir.
- Seçme modunda bileşenin üstüne çift tıklayarak sınıf adı, üye alanlar ve üye metotlar yazılır.
- İki sınıf arasında örneğin kalıtım ilişkisi varsa paletten uygun ok seçilip sınıflar birleştirilir.
- Şema kaydedilir ve "Export to image file" ile PNG olarak dışa aktarılabilir; bu resim örneğin bir Word belgesine eklenebilir.

## 10. Eclipse ile ilk proje ve "Merhaba dünya"

### 10.1 Çalışma alanı ve arayüz

Eclipse ilk çalıştırıldığında bir çalışma alanı (workspace) sorusu gelir. Eclipse, yeni projelerin kaynak kodlarını ve ikili dosyalarını varsayılan olarak hangi kök dizinde tutacağını ve kendi ayarlarını (pencere boyutları, metin düzenleyici, yazı tipi seçenekleri vb.) nereye kaydedeceğini sorar. Varsayılan, kullanıcı hesabının dizini altındaki `eclipse-workspace` dizinidir. "Bunu kullan, bir daha sorma" işaretlenirse soru bir daha gelmez.

Ardından bir hoş geldiniz ekranı açılır; kapatılabilir. İlk kurulumda sol tarafta hiç proje yoktur. Eclipse temel olarak dört bölümlü bir IDE olarak görünür. Hocanın ekranındaki ek pencereler, kurduğu eklentilere aittir.

### 10.2 Hazır kodları proje olarak almak

Ders notlarındaki kodların bulunduğu zip dosyası bir dizine açıldıysa bu dosyalar topluca bir proje olarak alınabilir:

1. `File > New > Java Project` seçilir.
2. "Use default location" işareti kaldırılır, çünkü varsayılan yer çalışma alanıdır; konum olarak kodların açıldığı dizin seçilir.
3. Projeye bir ad verilir (hoca dersin kısaltmasını kullanıyor) ve "Finish" denir.
4. Modül oluşturma sorusuna "Don't create" denir; derste modüllerle uğraşılmayacak.

Proje açılınca kaynak kodlar için `src` dizini görünür ve içinde paketler listelenir. Hoca örnek olarak ilk bütüncül kod örneğinin `NYP01A` paketinde olduğunu, içinde bir araba sınıfı ve bir test sınıfı bulunduğunu gösterdi. Buradaki kodlar yansılardakiyle aynıdır; bazı yerlerde, örneğin `main` metodunda, derste öğrencilerin "şöyle olsa ne olurdu" sorularıyla denenecek ek komutlar olabilir.

### 10.3 Yeni proje, paket ve sınıf

Her şeyin yerli yerinde olduğunu (JDK kurulu, Eclipse kurulu, proje oluşturulup kod çalıştırılabiliyor) sınamak için yeni bir proje oluşturuldu:

1. `File > New > Java Project`, bu kez varsayılan konum bırakılarak; proje adı `NDP-denemeler` (ekrandan, 02:10:00 ve 02:15:00). Modül sorusuna yine "Don't create".
2. Proje çalışma alanında kendi adıyla bir klasör olarak oluşur; altında boş bir `src` klasörü vardır. Paket ve sınıf eklendikçe bu klasörde dosyalar oluşur.
3. `src` üstünde `New > Package` ile `hafta01` paketi oluşturulur; `src` altında aynı adlı bir klasör açılır.
4. Paket içinde `New > Class` ile `Merhaba` sınıfı oluşturulur ve sihirbazda `main` metodu içermesi işaretlenir.

Eclipse, `main` gövdesine geçici bir kod ve "bunu doldurmayı unutma" anlamında bir yapılacak iş (TODO) işareti koyar. Bu silinip yerine ekrana yazma kodu yazılır.

### 10.4 Nesneler ve sınıflar: ilk bakış

Hoca bu arada dersin temel yaklaşımını özetledi. Temel kodlama bileşeni nesnelerdir ve her zaman nesneler cinsinden düşünmek gerekir. Bir nesne, kendine ait verisi ve o veri üzerinde çalışan eylemleri, yani metotları içeren temel programlama birimidir. Bir nesnenin üye alanlarını, metotlarını ve metot gövdelerinin nasıl çalışacağını tanımlamak için yazılan kod ise sınıf kodudur. Bir sınıftan istenildiği kadar nesne oluşturulup metotları çağrılır. Aynı amaca yönelik sınıflar paketler altında toplanır.

### 10.5 `main` metodu

Bir kodun başlangıç noktası olabilecek metodun özel bir imzası vardır:

```java
public static void main(String[] args)
```

`public`, `private`, `static` gibi kavramlar sonraki derste ayrıntılı işlenecek. `main` adı C'den tanıdıktır; C'de de kodun başlangıç noktası `main` fonksiyonuydu. Yapısal programlamada "fonksiyon", nesneye yönelikte "metot" denir.

`String`, `java.lang` paketindeki karakter katarı sınıfıdır. `String[]` bir `String` dizisi demektir; hocanın anlatımında kutu gibi görünen simge aslında açılıp kapanan köşeli parantezlerdir. `args` argüman listesidir: Java komut satırından çalıştırılırken verilen her parametre bu dizinin bir elemanı olur. Örneğin `java -version` komutundaki `-version` gibi. Derste örnekler komut satırından parametre verilerek yapılmayacak.

### 10.6 Ekrana yazdırmak

Ekrana bir satır yazmak için kendi nesnemizi tasarlamaya gerek yoktur. Eclipse'te `sysout` yazıp Ctrl+Space'e basmak, tanımlı bir kısayolla `System.out.println();` satırını üretir. Başka IDE'de bu kısayol olmayabilir; o zaman büyük `S` ile başlamak şartıyla `System.out.println` uzun uzun yazılır. Parantez içine çift tırnakla bir string yazılır; Eclipse açılan tırnağı otomatik kapatır.

Önce tek satırlık bir `println` satırı yazıldı (ekrandan, 02:20:00). Hoca aradaki farkı göstermek için `println` yerine `print` de denedi (ekrandan, 02:25:00):

```java
package hafta01;

public class Merhaba {

    public static void main(String[] args) {
        System.out.print("Merhaba dünya. Git artık Corona.");
    }

}
```

Kodda kaydedilmemiş değişiklik olduğu sekmedeki küçük yıldızdan anlaşılır; Ctrl+S ile kaydedilir. Sonra kodun byte koda çevrilip çalıştırılması gerekir. Bunun için sınıfın üstünde sağ tıklayıp "Run As > Java Application" denir (ekrandan, 02:20:00). `main` metodu kodlanmamış olsaydı bu seçenek çıkmazdı. Araç çubuğundaki yeşil çalıştırma düğmesi en son çalıştırılan sınıfı yeniden derleyip çalıştırır; açılır listesinden daha önce çalıştırılmış `main` içeren sınıflar da seçilebilir.

Çıktı alttaki **Console** penceresinde görünür. Bu pencere tamamen işlevsel bir komut penceresidir; ayrıca Windows komut satırı açmaya gerek yoktur. Derleme hataları olsaydı **Problems** penceresinde görünecekti. Hocanın Problems penceresinde görünen uyarılar bu projeyle ilgili değildi; kod kalitesi eklentilerinin (SonarLint, PMD, Checkstyle) diğer projelerde bulduğu öneri ve uygunsuzluklardı.

`print` ile yazdırıldığında imleç aynı satırda kalır. `println` ile yazdırıldığında yazdıktan sonra alt satıra geçilir. Son hâlde kod iki `println` satırına bölündü (ekrandan, 02:30:00):

```java
package hafta01;

public class Merhaba {

    public static void main(String[] args) {
        System.out.println("Merhaba dünya. ");
        System.out.println("Git artık Corona.");
    }

}
```

Konsol çıktısı (ekrandan, 02:30:00):

```text
Merhaba dünya.
Git artık Corona.
```

Bu son sürüm, ortamda ayrı bir `javac` ikilisi bulunmadığı için JDK 25'in tek dosyalı kaynak çalıştırıcısıyla (`java hafta01/Merhaba.java`, derleme bellekte yapılır) çalıştırıldı ve ekrandaki çıktının aynısını verdi.

### 10.7 `System.out.println` ne demek?

`System`, `java.lang` paketinde yer alan bir sınıftır. Bu sınıfın, sistemle ilgili farklı bileşenleri simgeleyen üye alanları, daha doğrusu üye nesneleri vardır. `out` böyle bir nesnedir ve standart çıkışı (komut satırı çıkışını) simgeler; kendisi statik bir nesnedir ve statik kavramı sonra işlenecek. `out` nesnesinin `println` adlı bir metodu vardır. `println` parametre olarak bir string alır ve onu komut satırına yazar, ardından alt satıra geçer. Böylece sonraki `print` ya da `println` işlemleri alt satırdan devam eder. `print` kullanılsaydı sonraki işlemler aynı satırdan devam ederdi.

Hoca, `public` ve `static` gibi nesneye yönelik kurallar dışında Java söz diziminin C'ye çok benzediğini belirtti.

Hoca ayrıca Eclipse'te bir sınıfın üstünde durunca gelen açıklamanın yerel olarak kurulan dokümantasyondan mı geldiğini denedi. Dokümantasyon klasörünün adı değiştirildiğinde de açıklama gelmeye devam etti; yani Eclipse bu açıklamayı kendi kaynağından alıyor. Hoca yine de Javadoc'u yerel olarak kurmayı önermeyi sürdürdü.

## 11. Soru-cevap: nesneye yönelik nedir, Java'da değer ve referans

### 11.1 Editör ve kaynaklarla ilgili sorular

**Soru:** Hangi editörü kullanacağız?
**Cevap:** Özel bir tercih yok. Hoca Eclipse kullanıyor, ama NetBeans, JCreator, IntelliJ ya da başka bir IDE de olur. İş yerinde belirli bir IDE kurulu bilgisayarla çalışanlar onu kullanmaya devam edebilir.

**Soru:** GUI için ayrı bir ders olacak mı, önerilen bir kaynak var mı?
**Cevap:** Özel bir kaynak önerisi yok; konu Türkçe ya da İngilizce herhangi bir Java kitabından Swing üzerinden çalışılabilir. Ders sonunda gereken bütün altyapıya sahip olunacağı için okuyup anlamak zor olmayacak.

**Soru:** Java SE7 ya da SE8 kullanan bir kaynak kitaptan yararlanmanın sakıncası var mı?
**Cevap:** Hiçbir sakıncası yok; JSE5 ya da üstü olması yeterli.

**Soru:** Eclipse sitesinde macOS için yalnız 32 bit sürüm görünüyor, 64 bit yok.
**Cevap:** Olabilir; geriye doğru uyumluluk olduğu için 32 bit sürümün de sorunsuz çalışması beklenir.

> **Ders sonrası not:** O dönemin Eclipse paketleri macOS için büyük olasılıkla yalnız 64 bit olarak dağıtılıyordu (macOS 10.15'ten beri 32 bit uygulamalar da çalışmıyor). Mac'te indirme sayfasında görünen macOS paketi indirilmelidir.

### 11.2 Nesneye yönelik programlama C'den ve Python'dan nasıl ayrılır?

**Soru:** Nesneye yönelik tam olarak ne demek, C'den ve Python'dan farkı ne?
**Cevap:** Nesneye yönelim, yapısal programlamanın üst kümesidir. Yapısal programlamada görülen her şey nesneye yönelikte de geçerlidir; nesneye yönelik buna yeni kodlama bileşenleri ve yeni kurallar ekler.

En büyük fark şudur. Yapısal programlamada veri ayrı, o veriyle çalışacak fonksiyonlar ayrı tanımlanır. Bir dosyada global değişkenler, fonksiyonların içinde yerel değişkenler olabilir; birbiriyle ilişkili veri bileşenleri bir struct altında toplanabilir, ama struct yalnız veriyi toplar. Bu veri üzerinde işlem yapan fonksiyonlar aynı ya da farklı C dosyalarına ayrı ayrı yazılır ve `include` ile birbirine bağlanır.

Nesneye yönelikte ise bir varlıkla ilgili veri ve o varlıkla ilgili eylemler (metotlar) ayrılmaz bir bütündür. Aynı `.java` dosyasındaki bir sınıf kodu, o sınıftan türetilecek nesnelerin hem verilerini (üye alanlar) hem de yapabileceği eylemleri tanımlar. Eylemler genellikle nesnenin kendi verisi üzerinde çalışır. Metot parametresi ya da sahiplik gibi ilişkilerle bir nesne başka nesnelerin metotlarını da çağırabilir. Kodu gerçek dünyadaki bir problemi çözmek için yazdığımızdan, problem alanındaki varlıkları koda aktarırken onların niteliklerini veri olarak, onlarla yapılabilecek eylemleri metot olarak kodlarız. Nesneden bağımsız, doğrudan erişilebilen metot kullanımı azdır; bu statik metotlarla olur.

Hoca buna "ileriye ket vurma" (proactive interference) kavramını ekledi: eski öğrenilenlerin yenilerin önüne geçmesi ya da yeni öğrenileni eskiye uydurmaya çalışmak. Yapısal programlama alışkanlıkları nesneye yönelimin özüne aykırı davranışlara yol açabilir. Örneğin bir varlık için başlı başına bir sınıf yazmak yerine bir string matrisi kullanmak yanlıştır; doğrusu bir sınıf yazıp o sınıfa uygun türlerde üye alanlar koymaktır. Ders notları doğru kullanımı gösterecek biçimde hazırlanmıştır. <!-- BELİRSİZ: altyazıda "antiklatağını denmekte" geçiyor; bağlamdan büyük olasılıkla "anti-pattern" (karşı örüntü) kastediliyor. --> Bu yanlış kullanımlar ayrı bir konudur ve bu derste ayrıntısına girilmeyecek.

Hoca, sıralama gibi problemlerde döngülerin nasıl kurulacağı gibi önceki yapısal programlama derslerinde öğrenilenlerin elbette unutulmaması gerektiğini de ekledi. Nesneye yönelimle ilgili her şey ise sıfırdan, A'dan Z'ye öğretilecek; Java'nın bazı özel yetenekleri de ek olarak görülecek. Bu yetenekler yalnız Java'ya özgü değildir, .NET gibi ortamlarda da benzer biçimlerde vardır.

### 11.3 Değer türü, referans türü ve işaretçiler

**Soru:** Java'da value type / reference type ayrımı var mı? İşaretçi (pointer) kullanacak mıyız?
**Cevap:** Java'da iki tür veri vardır:

- **İlkel (primitive) türler:** bir birim bilgi içerir. Tam sayılar, tek bir karakter, `boolean` (true ya da false) ve ondalıklı sayılar. İki ondalıklı sayı türü vardır: `float` ve `double`.
- **İlkel olmayan (non-primitive) türler:** yazılabilecek herhangi bir sınıftan oluşturulan nesneler.

İkisi metotlara parametre olarak aktarılırken farklı davranır. Basit bir ön kabul olarak ilkel türler call by value ile, nesneler ve diziler (diziler de nesne olarak aktarılır) call by reference ile aktarılır diye düşünülebilir. Ama burada önemli bir nüans vardır: aktarım aslında "call by value of references", yani referansın değeriyle çağırmadır. Bu fark ilgili konuda örnekle gösterilecek.

Java'da ayrı bir işaretçi yapısı yoktur. Bellek yönetimini programcı yapmaz; dil bu yükü üstlenir ve işaretçi ya da referans karmaşıklığını programcıdan soyutlar.

> **Ek bilgi (derste anlatılmadı):** Java'da kullanılmayan nesnelerin belleği "çöp toplayıcı" (garbage collector) tarafından otomatik olarak geri alınır. Bu yüzden C'deki `malloc`/`free` eşleştirmesine benzer bir sorumluluk programcıda değildir.

## Örnek Sorular

**Soru 1** (derste sözlü, 02:27:29): Nesneye yönelik programlama tam olarak neyi ifade eder? Yapısal programlamadan (ör. C) temel farkı nedir?

> **Çözüm (derste verilen cevap):** Nesneye yönelim yapısal programlamanın üst kümesidir; yapısal programlamadaki her şey geçerlidir, üstüne yeni kodlama bileşenleri ve kurallar eklenir. Temel fark verinin ve onu işleyen eylemlerin birlikteliğidir. Yapısal programlamada veri (ör. struct) ve fonksiyonlar ayrı tanımlanır. Nesneye yönelikte bir varlığın verisi (üye alanlar) ve eylemleri (metotlar) aynı sınıf kodunda ayrılmaz bir bütün olarak tanımlanır; nesneler bu sınıftan oluşturulur ve metotlar çoğunlukla nesnenin kendi verisi üzerinde çalışır.

**Soru 2** (derste sözlü, 02:35:13): Java'da değer türü / referans türü ayrımı var mı? İşaretçiler kullanılacak mı?

> **Çözüm (derste verilen cevap):** Java'da ilkel türler (tam sayılar, karakter, boolean, float, double) ve ilkel olmayan türler (sınıflardan oluşturulan nesneler, diziler) vardır. İlkel türler metotlara değerle aktarılır. Nesneler ve diziler ilk yaklaşımla referansla aktarılıyor gibi düşünülebilir, ama aktarım aslında "call by value of references"tır. Java'da ayrı bir işaretçi yapısı yoktur ve bellek yönetimini dil üstlenir.

**Soru 3** (derste sözlü, 01:49:03): Java SE7 ya da SE8 üzerine yazılmış bir kaynak kitap bu ders için kullanılabilir mi?

> **Çözüm (derste verilen cevap):** Evet. Ders notları Java 1.5 tabanlıdır (generics, for-each); kitabın JSE5 ya da üstü bir sürüm üzerine yazılmış olması yeterlidir.

## Dersin Toparlaması

Bu ilk derste dersin iki amacı ortaya kondu: nesneye yönelimi doğru biçimde öğrenmek ve bunu UML sınıf ve sıralama şemalarıyla birlikte modellemek. Ardından Java'nın genel yapısına geçildi. JSE, JME ve JEE ayrımı yapıldı. Java'nın derlenip byte koda çevrilen ve JVM tarafından yorumlanan bir dil olduğu, bu modelin taşınabilirlik ve güvenlik avantajları ve HotSpot iyileştirmesiyle küçülen ek yükü anlatıldı. Sun'dan Oracle'a uzanan tarihçe ve iki kanallı sürüm adlandırması tablo üzerinden incelendi; Java 1.5'in ders için kritik sürüm, Java 8 ve 11'in LTS sürümleri olduğu vurgulandı.

Dersin ikinci yarısı geliştirme ortamına ayrıldı: işletim sisteminin bit sayısına göre JDK seçimi, JDK kurulumu ve PATH ayarı, API dokümantasyonunun kurulup kullanılması, Eclipse ve Violet UML'in indirilmesi. Eclipse'te bir proje, `hafta01` paketi ve `Merhaba` sınıfı oluşturulup `System.out.print`/`println` farkı gösterildi. Bir sonraki dersten itibaren nesneye yönelimin temel kavramlarına (sınıf, nesne, kurucu metot, `public`/`static` gibi niteleyiciler) ve ilk bütüncül kod örneğine geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
