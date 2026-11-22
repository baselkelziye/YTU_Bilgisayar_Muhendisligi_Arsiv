# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin amacı ve kapsamı
  - Birinci amaç nesneye yönelimi (object orientation) öğretmek ve doğru kullanmayı içselleştirmektir. Java bu amacın aracıdır; ders bir "Java programlama" dersi değildir.
  - İkinci amaç UML modelleme diline giriştir: UML sınıf şemaları ve UML sıralama (sequence) şemaları, nesneye yönelik kavramlarla birlikte işlenir.
  - Ders içeriği (ekrandan, 00:30:00): Java diline genel bakış; nesneler ve sınıflar; UML sınıf şemaları; nesne durumu, davranışı ve metotlar; ilkel türler ve sarmalayıcılar, metot parametrelerinin inceliği (call-by-value-of-references); nesne ve sınıf iş birlikleri ve ilişkileri; UML etkileşim (sıralama) şemaları; kalıtım ve soyut sınıflar; arayüzler ve çoklu kalıtım; çok biçimlilik, metot yeniden tanımlama (overriding) ve çoklu tanımlama (overloading); enum sınıfları; listeler ve map'ler üzerinden generic sınıflara giriş; exception handling; tip dönüşümü (typecasting); dosyalar ve akışlar (serialization); iç sınıflar; çoklu iş parçacığına (multithreading) giriş.
- Neden önce modelleme (UML)
  - Yapısal programlama akış şemalarıyla görselleştirilerek öğretildi. Aynı mantıkla nesneye yönelik bir çözümde de önce gerçek dünya problemindeki varlıklar, verileri, eylemleri ve aralarındaki ilişkiler modellenir, sonra koda geçilir.
  - UML (Unified Modeling Language) sektörde yaygın bir modelleme dili ailesidir; yazılım yaşam döngüsünün her aşaması için ayrı bir şema türü vardır.
- Java sürüm aileleri (edition) (ekrandan, 00:40:00)
  - Standard Edition (JSE): mobil dışında her tür uygulama için. Derste temel alınan sürümdür.
  - Micro Edition (JME): kısıtlı donanımlı cihazlar (eski cep telefonları, set üstü kutular) için JSE'nin küçük bir alt kümesi. Pratikte artık kullanılmıyor.
  - Enterprise Edition (JEE): JSE'ye ek olarak bir uygulama sunucusu (application server) yazılımı içerir. Sunucu, çok katmanlı uygulamalara ve web servislerine işlem (transaction) desteği, güvenlik gibi hizmetler verir. Uyumlu sunucular: IBM WebSphere, BEA WebLogic, Apache Tomcat.
- Java yorumlanan bir dildir (ekrandan, 00:45:00)
  - Kaynak kod `.java` dosyasındadır; derleyici (`javac.exe`) onu byte koda, `.class` dosyasına derler.
  - C gibi dillerde bağlayıcı (linker) derlenmiş kodu bağımlılıklarla birleştirip işletim sisteminin doğrudan çalıştırdığı kodu üretir. Java'da bağlama yoktur; yorumlayıcı olan Java Sanal Makinesi (JVM) byte kodu okuyup çalıştırır.
  - JDK (Java Development Kit) geliştirici içindir, `javac.exe`'yi içerir. JRE (Java Runtime Environment) son kullanıcı içindir, JVM'i (`java.exe`/`javaw.exe`) içerir. JDK, JRE'yi kapsar.
- Java'nın tarihçesi ve sürüm adlandırması (ekrandan, 01:05:00)
  - Java, sunucudan set üstü kutuya kadar geniş donanım yelpazesinde çalışacak bir dil olarak Sun Microsystems'ta çıktı. Sloganı "Write Once, Run Anywhere".
  - Dil tek bir firmanın denetiminde değildir; topluluk katılımıyla gelişir. Sun'ı satın alan Oracle'dan bağımsız olarak OpenJDK açık kaynak olarak sürer.
  - Eski (geliştirici) ve yeni (ürün) adlandırma tablosu aşağıda, Detaylı Açıklamalar bölümündedir.
- Kurulum ve geliştirme ortamı
  - JDK indirilir, kurulur, `java -version` ile denenir; komut bulunmazsa JDK'nın `bin` dizini PATH ortam değişkenine eklenir.
  - JDK dokümantasyonu (API belgeleri) ayrıca indirilip kurulması önerilir.
  - IDE serbesttir (Eclipse, NetBeans, IntelliJ, JCreator). Derste Eclipse kullanılır.
  - UML çizimi için Violet UML önerilir.
- İlk program: Eclipse'te proje, paket, sınıf oluşturma ve `System.out.println` ile ekrana yazma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Derste soru sormak
  - Canlı derse katılmanın en büyük avantajı soru sorabilmektir. Anladığını sanıp aslında oturmamış bir şey, bir arkadaşın sorusuyla bütün sınıfa açıklanmış olur.
- Java 1.5 kritik sürümdür
  - Generic sınıflar, gelişmiş for (for-each) döngüsü ve exception handling'de ek bir notasyon bu sürümle geldi. Ders notları 1.5 tabanlıdır.
  - Seçilecek kaynak kitabın en az Java 1.5 (JSE5) üzerine yazılmış olması gerekir; SE7 ya da SE8 kitapları da uygundur.
- Yorumlanan dillerin iki avantajı
  - Taşınabilirlik: kod, yorumlayıcısı olan her ortamda aynı şekilde çalışır.
  - Güvenlik ve güvenilirlik: yorumlayıcı programa güvenli bir çerçeve sunar; C'de bir yıldızı fazla ya da eksik yazmakla sistemi çökertmek kolaydır.
  - Ek yük Java 1.2'den sonra çalıştırma öncesi kod iyileştirmesiyle (HotSpot) büyük ölçüde kapandı. Büyük dağıtık sistemlerde birkaç milisaniyelik fark ağ gecikmesinin yanında önemsiz kalır.
- Hangi JDK kurulmalı
  - 32 bit işletim sisteminde Java 8 (1.8); 64 bit sistemde LTS olan Java 11 ya da derste en güncel sürüm olarak gösterilen Java 15.
  - Her yeni güncellemeye geçmek gerekmez. Geçilecekse eski JDK önce kaldırılmalıdır; yoksa yan yana birden fazla kurulum birikir.
- Dokümantasyonun rolü
  - Dil dokümantasyondan öğrenilmez, kitaptan öğrenilir. Ama sonradan bir şeyin nasıl yapılacağını ararken sınıf ve metot ayrıntısına en hızlı API belgelerinden ulaşılır.
  - "Deprecated" işaretli kurucu ya da metotlardan yeni önerilen kullanıma geçilmelidir.
- Nesneye yönelik ile yapısal programlama farkı
  - Nesneye yönelik, yapısal programlamanın üst kümesidir. Temel fark, bir varlığın verisi ile o veri üzerinde çalışan eylemlerin (metotların) ayrılmaz bir bütün olarak aynı sınıfta tanımlanmasıdır.
  - Yapısal programlama alışkanlıkları (ör. bir varlık için sınıf yazmak yerine string matrisi kullanmak) nesneye yönelimin özüne aykırı kullanımlara yol açabilir.

## Kısa Tekrar Notları

- Ders: nesneye yönelim + UML (sınıf ve sıralama şemaları), araç dili Java.
- JSE: genel amaçlı; JME: kısıtlı cihaz, artık kullanılmıyor; JEE: JSE + uygulama sunucusu.
- `.java` → `javac` → `.class` (byte kod) → JVM yorumlar. Linker yok.
- JDK = geliştirici (derleyici + JRE); JRE = kullanıcı (JVM).
- Yorumlamanın avantajları: taşınabilirlik ve güvenlik.
- Java 1.5: generics, for-each; ders notlarının temeli.
- Java 8 ve Java 11 LTS sürümlerdir; ara sürümler yaklaşık 6 ayda bir çıkar.
- PATH'e `...\jdk11\bin` eklenir; `java -version` ile denenir.
- `java.lang` paketi otomatik içe aktarılır; `String` ve `System` bu pakettedir.
- `javax` paketlerindeki "x", "extended" demektir; geriye uyumluluk için ad değişmedi.
- Başlangıç metodu: `public static void main(String[] args)`; `args` komut satırı parametreleridir.
- `println` yazdıktan sonra alt satıra geçer, `print` geçmez.
- İlkel türler (tam sayı, karakter, boolean, float, double) değerle aktarılır; nesneler ve diziler "referansın değeriyle" (call by value of references) aktarılır. Java'da ayrı bir işaretçi (pointer) yapısı yoktur, bellek yönetimini dil üstlenir.

## Detaylı Açıklamalar

- **Erken nesne / geç nesne yaklaşımı.** Programlama dillerinde önce yapısal programlama ortaya çıktığı için müfredatlar çoğunlukla önce yapısal, sonra nesneye yönelik programlamayı öğretir. Doğrudan nesneye yönelikle başlayan programlar da vardır. Bazı Java kitaplarının "early objects" ve "late objects" diye iki sürümü bulunur. Ders notları doğrudan nesneye yönelimle başladığı için derse paralel olan sürüm "early objects" sürümüdür.

- **Önerilen kaynaklar (ekrandan, 00:05:00).** Java How to Program (H. M. Deitel, P. J. Deitel; 7. baskı ya da yenisi, early objects sürümü); Core Java 2 Volume I & II (C. S. Horstmann, G. Cornell; 7. baskı ya da yenisi; derste ağırlıkla I. cilt, II. ciltten bir konu kullanılır); UML için UML Distilled, 3. baskı (Martin Fowler). UML Distilled, her şema türünü arkasındaki nesneye yönelik kavramlarla birlikte anlatır; ders notlarının anlatımı da buna benzer. Kitap almak zorunlu değildir; ders notları esastır.

- **Derleme, bağlama ve yorumlama.** Her dilde insanın okuyabildiği bir kaynak kod yazılır ve bir derleyici bunu ikili (binary) bir derlenmiş koda çevirir. Bundan sonra iki yol vardır. C gibi dillerde bağlayıcı, programın kendi kodunu işletim sisteminden alınacak hizmetlerle (Windows'taki DLL dosyaları gibi bağımlılıklarla) birleştirir ve işletim sisteminin doğrudan çalıştıracağı bir dosya üretir. Java gibi yorumlanan dillerde bağlama yapılmaz. Yorumlayıcı byte kodu okur ve işletim sistemine iletir; araya bir tercüman girmiş gibidir. Bu ek bir yük getirir. Eski sürümlerde (1.2'ye kadar) bu yük hissedilirdi. Sonra yorumlayıcı kodu sırayla çalıştırmak yerine önce iyileştirip (HotSpot) çalıştırmaya başladı. Hoca, bir milyon elemanlı bağlı listede sıralama, ekleme ve silme gibi işlemlerde doğrudan çalıştırılan dillerle başa baş noktaya gelindiğini söyledi. .NET dahil güncel ortamlar da taşınabilirlik ve güvenlik için yorumlama yoluna yönelmiştir.

- **Sürüm adlandırma tablosu (ekrandan, 01:05:00).**

  | Geliştirici sürümü (eski yol) | Ürün sürümü (yeni yol) |
  | --- | --- |
  | Java 1.0, 1.1 | — |
  | Java 1.2 | Java 2 Platform |
  | Java 1.3 | Java 2 SE 3 (J2SE3) |
  | Java 1.4, 1.5 | J2SE4, J2SE5 |
  | Java 1.6 {Sun} | Java Platform Standard Edition, version 6 (Java SE6 / JSE6) |
  | Java 1.7 {Oracle} | Java Platform Standard Edition, version 7 (Java SE7 / JSE7) |
  | Java 1.8 | Java SE8 / JSE8. Eski sistemler için LTS; bu derste işlenmeyen yeni dil özellikleri getirir |
  | Java 1.9-1.10, 1.12-1.14 | Kısa süreli sürümler (~6 ayda bir), desteği bitti |
  | Java 1.11 | Java SE11. LTS; bu derste işlenmeyen dil özellikleri ve araçlar |
  | Java 1.15 | Java SE15. Güncel sürüm |

  - 1.0 "umut verici" bir ilk sürümdü, 1.1 sınıf kütüphanesini genişletti. 1.2 ile dil ve kütüphaneler sektörde ana platform olacak düzeye geldi ve pazarlama bunu "Java 2" diye sundu.
  - Hoca bu adlandırmayı teknik olarak yanlış buluyor: sürüm numarasında ilk basamak ana, ikinci basamak ara sürümdür. "Java 2" adı 2.0 gibi bir ana sürüm geçişi izlenimi verir, oysa 1.1'den 1.2'ye geçiş bir ara sürüm geçişidir. Bu yüzden teknik belgelerde 1.x adı hep kullanılmaya devam etti.
  - 1.6, tamamen Sun tarafından çıkarılan son sürümdür; 1.7 Oracle'ın denetiminde çıktı. Oracle Java'nın açık yönetim yapısını sürdürdü.
  - Eski sürüm numarası dört basamaklıdır (ör. 1.8.0.x). Üçüncü basamak hep sıfır kaldı. Dördüncü basamak "update"tir: küçük hata düzeltmeleri ve güvenlik yamaları.

> **Ders sonrası not:** Slayt ve hoca Java 9 sonrası sürümleri "Java 1.11", "Java 1.15" diye adlandırıyor. Java 9'dan itibaren resmî sürüm numarası "1." önekini bırakmıştır; `java -version` çıktısı büyük olasılıkla "11.0.x" biçimindedir. Ders bağlamında 1.11 = Java 11, 1.15 = Java 15 diye okunmalıdır.

- **32 ve 64 bit.** İşlemci içinde ve bileşenler arasında veri byte'lar hâlinde taşınır; yolun kaç bit genişliğinde olduğu bir otoyoldaki şerit sayısına benzetildi. 32 bit bir işletim sistemi daha küçük bir bellek uzayını adresleyebilir: makinede 4 GB bellek olsa bile yaklaşık 3,2 GB'ı kullanılabilir. Windows'ta sistem türü "Bilgisayar > Özellikler > Sistem türü" altında görülür. 32 bit sistemde Java 8 kurulmalıdır.

- **JDK kurulumu ve PATH.** JDK, Oracle'ın Java sayfasındaki indirme bölümünden indirilir ve kurulur. Hoca JDK'yı komut satırı kolaylığı için kısa bir dizine (ör. `C:\jdk11`) kurmayı tercih ediyor (ekrandan, 01:30:00). Kurulumdan sonra bir komut satırında `java -version` yazılır; sürüm bilgisi ve HotSpot sanal makinesi bilgisi geliyorsa kurulum doğrudur. Komut tanınmıyorsa "Gelişmiş sistem ayarları > Ortam Değişkenleri" altında Path değişkenine JDK'nın `bin` dizini (ör. `C:\jdk11\bin`) eklenir. Bu da çözmezse JDK kaldırılıp bilgisayar yeniden başlatılır ve yeniden kurulur.

- **API dokümantasyonu.** İndirilen sıkıştırılmış dosyanın içinde tek bir `docs` klasörü vardır; JDK dizinine açılır. API dizininden `java.base` modülüne girilince temel paketler listelenir. Sınıf kitaplıklarına paket denir; kendi sınıflarımız da paketlere toplanabilir. `java.lang` içe aktarılması gerekmeyen tek pakettir; `java.io` giriş/çıkış, `java.math` matematik işlemleri içindir. Tarih işlemleri ve generic sınıflarla ilgili sık kullanılan sınıflar bir başka pakettedir. <!-- BELİRSİZ: altyazıda "Java JT paketi" geçiyor; bağlamdan büyük olasılıkla java.util. --> Bir sınıf sayfasında (ör. `String`) sınıfın kalıtım hiyerarşisi, genel açıklaması, üye alanları, kurucu metotları ve metotları yer alır. Ekranda `String(byte[] ascii, int hibyte)` kurucusunun "Deprecated. This method does not properly convert bytes into characters." diye işaretli olduğu gösterildi (ekrandan, 01:35:00). Eskimiş işaretlenen bir kullanımın yerine önerilen yeni yöntem kullanılmalıdır. `compareTo` metodunun ayrıntı sayfası da açılıp parametresi ve dönüş değeri gösterildi.

- **Eclipse kurulumu ve kullanımı.** `eclipse.org/downloads` sayfasından "Download Packages" ile "Eclipse IDE for Java Developers" (~321 MB) indirilmesi önerildi; "Enterprise Java Developers" paketi (~500 MB) gerekli değil. Yeni sürümlerin 32 bit paketi yok; 32 bit için eski sürümlere (ör. Neon 3) bakılabilir. Eclipse kurulum gerektirmez, zip açılıp `eclipse.exe` çalıştırılır. İlk açılışta çalışma alanı (workspace) dizini sorulur; varsayılan, kullanıcı dizini altındaki `eclipse-workspace`'tir. Hazır kodları proje olarak almak için `File > New > Java Project` denir, "Use default location" kaldırılıp kodların bulunduğu dizin seçilir. Modül oluşturma sorusuna "Don't create" denir. Projede kaynak kodlar `src` klasörüne, sınıflar paketlere gider.

- **Violet UML (ekrandan, 01:50:00).** Hafif bir UML aracıdır ve bu ders için yeterlidir; Argo UML bir alternatiftir. Kendisi bir `.jar` dosyası olarak paketlenmiş bir Java uygulamasıdır; JRE kuruluysa çift tıklayınca açılır. Yeni sınıf şeması ya da sıralama şeması oluşturulur; paletten bileşen seçilip yerleştirilir, çift tıklayarak sınıf adı, üye alanları ve metotları yazılır, sınıflar oklarla (ör. kalıtım) bağlanır. Şema PNG olarak dışa aktarılabilir.

- **İlk program (ekrandan, 02:25:00 ve 02:30:00).** `NDP-denemeler` projesinde `hafta01` paketi ve içinde `main` metodu olan `Merhaba` sınıfı oluşturuldu. Eclipse'te `sysout` yazıp Ctrl+Space'e basmak `System.out.println` kısayoludur. Kaydedilmemiş dosya sekmede yıldızla görünür, Ctrl+S ile kaydedilir. Sınıfın üstünde sağ tıklayıp "Run As > Java Application" denir; `main` metodu yoksa bu seçenek çıkmaz. Çıktı Console penceresinde, derleme hataları Problems penceresinde görünür.

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

  - Kod JDK 25'in tek dosyalı kaynak çalıştırıcısıyla (`java hafta01/Merhaba.java`) çalıştırıldı ve aynı çıktıyı verdi. Ortamda ayrı `javac` ikilisi yoktu; derleme bellekte yapıldı.
  - `System`, `java.lang` paketindeki bir sınıftır. `out` onun statik bir üye nesnesidir ve standart çıkışı temsil eder. `println` aldığı string'i yazar ve alt satıra geçer; `print` alt satıra geçmez. Hoca önce tek satırda `print` ile yazıp (ekrandan, 02:25:00) sonra iki `println` satırına geçerek farkı gösterdi.
  - `main` metodunun imzası `public static void main(String[] args)` biçimindedir. `args`, komut satırından verilen parametrelerin her birini bir eleman olarak tutan `String` dizisidir. `public` ve `static` anlamları sonraki derslerde işlenecek. Söz dizimi, nesneye yönelik kurallar dışında C'ye çok benzer.

- **Nesneye yönelik nedir?** Yapısal programlamada veri (ör. bir C struct'ı) ayrı, o veri üzerinde çalışan fonksiyonlar ayrı tanımlanır. Nesneye yönelikte bir varlığın verisi (üye alanlar) ve eylemleri (metotlar) aynı sınıf kodunda ayrılmaz bir bütündür. Sınıftan istenildiği kadar nesne oluşturulur ve metotları çağrılır. Metotlar çoğunlukla nesnenin kendi verisi üzerinde çalışır; metot parametresi ya da sahiplik ilişkileriyle başka nesnelerin metotları da çağrılabilir. Nesneye yönelikte "fonksiyon" yerine "metot" denir; nesneden bağımsız, doğrudan erişilen metot kullanımı (statik metotlar) azdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
