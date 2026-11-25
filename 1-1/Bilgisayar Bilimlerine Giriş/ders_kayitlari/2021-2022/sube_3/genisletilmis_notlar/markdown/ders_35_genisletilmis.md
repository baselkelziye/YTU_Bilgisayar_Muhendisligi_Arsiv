# Ders 35 Genişletilmiş Notu: İşletim Sistemleri ve Bilgisayar Ağlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İşletim sistemi nedir, ne yapar?
- 2. Paylaşımlı hesaplamanın tarihçesi
- 3. Yazılımın sınıflandırılması
- 4. İşletim sisteminin bileşenleri
- 5. Bilgisayarın açılması (bootstrapping)
- 6. Proses yönetimi: scheduler ve dispatcher
- 7. Kaynak paylaşımı: semafor ve kritik bölge
- 8. Deadlock (kilitlenme)
- 9. İşletim sistemi güvenliği
- 10. Ağların sınıflandırılması
- 11. Erişim protokolleri: CSMA/CD ve CSMA/CA
- 12. Ağları birleştirme: repeater, bridge, switch, router
- 13. Prosesler arası iletişim ve dağıtık sistemler
- 14. İnternet: mimari, adresleme ve DNS
- 15. İnternet uygulamaları
- 16. World Wide Web: HTTP, URL, HTML ve XML
- 17. İnternet protokolleri ve katmanlar
- 18. Ağ güvenliği

Bu derste iki konu işlendi: önce işletim sistemleri, ara verildikten sonra bilgisayar ağları ve internet. Anlatımda dersin önerilen kitabının (J. Glenn Brookshear, *Computer Science: An Overview*, 11. baskı) 3. bölüm ("Operating Systems") ve 4. bölüm ("Networking and the Internet") İngilizce slaytları kullanıldı (ekrandan, 00:10:00; ekrandan, 01:35:00). Slaytların çevrilmemesinin bir nedeni, bu alanlardaki terimlerin çoğunun İngilizce kullanılmasıdır; hoca mümkün olduğunca Türkçe karşılıklarını da verdi.

## 1. İşletim sistemi nedir, ne yapar?

### 1.1 Proses kavramı

Hoca, bütün ders boyunca kullanılacağı için proses kavramını en başta tanımladı. Program kodu yazılır, derlenir ve çalıştırılabilir dosya olarak bir yerde depolanır; bu depolanmış hâle **program** denir. Adı yazılıp Enter'a basıldığında ya da üzerine çift tıklandığında işletim sistemi bu programı çalıştırır; çalışan hâline **proses** denir. Prosesler çalışmak için birçok sistem kaynağını kullanmak zorundadır ve bu kullanımda çakışmalar olabilir. Çakışmaların nasıl engellendiği dersin ilerleyen kısımlarının konusudur.

### 1.2 İşletim sisteminin işlevleri

İşletim sistemi, adı üstünde, bilgisayarın işletilmesini, yani kullanıcı için kullanılabilir olmasını sağlayan bir yazılımdır: donanımın istendiği gibi hizmet vermesini ve uygulamaların çalışmasını sağlayan altyapı yazılımı. Slayttaki işlevler (ekrandan, 00:15:00):

- Bilgisayarın çalışmasını gözetmek (oversee operation of computer).
- Dosyaları saklamak ve geri getirmek (store and retrieve files).
- Programları çalıştırma için zamanlamak (schedule programs for execution).
- Programların çalışmasını koordine etmek (coordinate the execution of programs).

İlk işlev depolamayla ilgilidir: uygulamalar ve veriler disklerde saklanır; bunların nasıl saklanacağını düzenlemek ve erişim kurallarını tanımlamak işletim sisteminin işidir. İkincisi aynı anda birden çok programın çalıştırılmasıyla (multitasking) ilgilidir. Hoca örnek olarak o anki durumu verdi: Zoom açık, bir tarayıcı açık, belki bir kelime işlemci ya da bir C geliştirme ortamı açık, belki müzik çalıyor; ayrıca arka planda görünmeyen birçok uygulama çalışıyor. Bunların hangi sırayla ve ne kadar çalışacağının belirlenmesi (scheduling) ve hatasız yürütülmesi işletim sisteminin sorumluluğudur. Son olarak bu programların bir arada nasıl çalışacağı, birbirleriyle nasıl etkileşecekleri ve sistem kaynaklarına nasıl erişecekleri de işletim sistemi tarafından koordine edilir.

## 2. Paylaşımlı hesaplamanın tarihçesi

Slayttaki gelişim sırası şöyledir (ekrandan, 00:20:00):

- Batch processing
- Interactive processing (real-time processing gerektirir)
- Time-sharing / multitasking (multiprogramming ile gerçeklenir)
- Multiprocessor machines

### 2.1 Batch processing (toplu işleme)

1940'lar ve 1950'lerin oda büyüklüğündeki bilgisayarlarında veri teyp birimlerinde saklanıyor, girişler delikli kartlarla yapılıyordu. ENIAC gibi makinelerde kabloları ve anahtarları takarak programı bir anlamda elle kuruyordunuz. Hoca bu dönemi bir üniversitedeki araştırmacı örneğiyle anlattı: elinde kökleri hesaplanacak denklemler olan araştırmacı programını ve verilerini hazırlar, bilgisayarın bulunduğu binaya gidip randevu alır ve bir iş kuyruğuna girer. Hoca bunu maç kuyruğuna benzetti. Sırası gelen kullanıcıya örneğin 30 dakika verilir; bu sürede makinenin tek hâkimidir. Kartlarını okuyucuya yerleştirir, makinenin ayarlarını yapar, çalıştırır ve sonuçlarını alır. İşi 32 dakika sürerse sıradaki kişinin zamanından yemiş olur.

Slayttaki şekilde kullanıcı alanından (user domain) gelen işler (program, veri ve yönergeler) makine alanında (machine domain) bir iş kuyruğuna (job queue) girer, sırayla yürütülür (job execution) ve sonuçlar kullanıcıya döner (ekrandan, 00:25:00):

```text
User domain:     Jobs (program, data, directions)            Results
                          |                                     ^
                          v                                     |
Machine domain:      [Job queue]  ------>  (Job execution) -----+
```

Bu modelde etkileşim yoktur: işler sırayla verilir, çalışır, sonuç elde edilir; tek yönlü bir akış söz konusudur. Hoca karşıt örnek olarak kelime işlemciyi verdi: orada yazdıkça çıktının oluşmasını beklersiniz.

### 2.2 Operatör ve job control language

Transistörün icadıyla birlikte makinelerin işlem gücü, hızı ve kapasitesi arttı. Bütün makineyi bir kişiye 30 dakika ayırmak verimsiz hâle geldi, çünkü ayarların yapılması ve verilerin okunması sırasında gereksiz bekleme boşlukları oluşuyordu. Bunun üzerine **operatör** ortaya çıktı: kullanıcılar programlarını, verilerini ve yönergelerini operatöre verir; operatör bunları sırayla, gerekirse önceliklendirerek bir depolama birimine yerleştirir. Uzman olan operatör, kullanıcıların kartlarını takıp ayar yapmasından doğan ek yükü (process overhead) azalttı. Makineler geliştikçe girişlerin okunması ve işlerin sırayla çalıştırılması otomatikleşti. Kablo ve anahtarlarla yapılan tanımlar yönergelerle yapılabilir hâle geldi; buna **job control language** (iş denetim dili) denir. Biten işin çıktısı örneğin yazıcıya yazılır.

### 2.3 Interactive processing ve real-time processing

Bir sonuca göre yeni bir girdi vermek, sonra bir sonraki çıktıya göre yine girdi vermek gibi etkileşimli çalışma ihtiyacı doğdu. Etkileşimli işlemede kullanıcı, işi (job) çalışırken bir terminal ekranından onunla etkileşebilir. Bunun için **real-time processing** gerekir: kelime işlemcide bir tuşa bastığınızda harfin ikinci tuşa basmadan önce ekranda görünmesini, ya da bir denklemin kökleri bulunduğunda bir sonrakine geçmeden önce yazılmasını beklersiniz. Yani bir adım bitmeden diğer adım başlamamalıdır.

### 2.4 Time-sharing ve multiprogramming

Makinelerin gücü daha da artınca kişileri sırayla çalıştırmak yerine herkesin işini belirli bir zaman aralığında çalıştırma fikri ortaya çıktı. Hocanın örneği: birinci iş beş dakika çalışıp durur, sonra ikinci iş beş dakika çalışır, sonra üçüncü iş. On dakikalık bir iş iki zaman dilimi (time slot) kullanır; çok kısa bir iş tek dilimde biter; uzun bir iş birkaç dilim ister. İşler dönüşümlü çalıştığından kuyrukta bekleyenlerin toplam beklemesi azalır.

İşlerin parça parça zaman alıp hepsinin eş zamanlı çalışıyormuş gibi görünmesine **time-sharing** denir. Bunun gerçeklenme yöntemi **multiprogramming**'dir: işler (job) kendilerine ayrılan zaman dilimlerinde sırayla çalışır (birinciye beş saniye, ikinciye beş saniye, ..., sonra yeniden birinciye). Aslında tek bir kaynak art arda kullanılır; uzaktan bakıldığında hepsi birlikte çalışıyormuş gibi bir yanılsama oluşur. Tek kullanıcının kendi işlerini (bugünkü adıyla proseslerini) bu mantıkla çalıştırmasına **multitasking** denir.

### 2.5 Çok işlemcili makineler

Bugün bilgisayarlarda birden fazla fiziksel işlemci ya da bir işlemcide birden fazla çekirdek bulunabilir. Örneğin dört çekirdekte birinci işi birinci çekirdeğe, ikinci işi ikinci çekirdeğe vermek ya da bir işi iki çekirdeğe, diğerlerini kalan çekirdeklere paylaştırmak mümkündür. İşleri işlemcilere dinamik olarak dağıtmaya **load balancing** (yük dengeleme) denir. Bir işi bölüp aynı anda dört çekirdekte çalıştırmak istendiğinde basit zaman paylaşımının ötesinde yeni sorunlar doğar: senkronizasyon, hangi prosesin hangi işlemcide çalışacağı, kaynakların nasıl isteneceği. Çok işlemcili mimariler işletim sistemlerinin işini oldukça zorlaştırır ve bu hâlâ üzerinde çalışılan bir alandır.

Tarihçenin özeti: önce kullanıcı kendisi kuyruğa girip makineyi kullandı; sonra operatör işleri yükledi ve makine işlere hakkaniyetli zaman dilimleri verdi; en sonunda operatörün yaptığı işleri (işleri alma, yükleme, kuyruklama, çalıştırma, sonuç üretme) özelleşmiş yazılımlar devraldı. Bu yazılımların bütününe **işletim sistemi** denir.

## 3. Yazılımın sınıflandırılması

Hoca, bu sınıflandırmanın herkesin uzlaştığı kesin bir ayrım olmadığını, ama genel kabul gördüğünü belirtti. Slayttaki ağaç (ekrandan, 00:35:00):

```text
Software
├── Application
└── System
    ├── Utility
    └── Operating system
        ├── User Interface
        └── Kernel
```

- **Uygulama yazılımı (application software):** günlük işlerimizi yapan yazılımlar. Müzik dinleme uygulaması, web tarayıcısı, kelime işlemci, sunum programı, C geliştirme ortamı gibi.
- **Sistem yazılımı:** kullanıcının işini doğrudan görmeyen, uygulamaların düzgün çalışmasına altyapı hizmeti veren yazılımlar. İkiye ayrılır: hizmet yazılımları (utility) ve işletim sistemi.
- **İşletim sistemi** de iki parçadan oluşur: çekirdek (kernel) ve kullanıcı arayüzü (user interface).

Hizmet yazılımları aslında birer uygulama yazılımıdır, ama işletim sistemiyle birlikte gelen ve onunla birlikte çalışan uygulamalardır. Hocanın örnekleri:

- Yeni bir flash belleği kullanmadan önce dosya sistemi oluşturmak için biçimlendirirsiniz. Biçimlendirmeyi işletim sistemi değil, onunla birlikte gelen bir hizmet yazılımı yapar.
- Eskiden CD yazmak için ayrı bir yazma programı gerekirdi; bugün sağ tıklayıp "diske gönder" denebilir, yani bu iş bir hizmete dönüştü.
- Eskiden hiçbir işletim sistemiyle sıkıştırma yazılımı gelmezdi; ayrı programlar kullanılırdı. Bugün klasöre sağ tıklayıp sıkıştırmak mümkündür.

## 4. İşletim sisteminin bileşenleri

Slayttaki bileşenler (ekrandan, 00:40:00):

- **User Interface:** kullanıcılarla iletişim kurar.
  - Metin tabanlı (shell)
  - Grafik kullanıcı arayüzü (GUI)
- **Kernel:** gerekli temel işlevleri yerine getirir.
  - File manager
  - Device drivers
  - Memory manager
  - Scheduler and dispatcher

### 4.1 Kernel

Hoca, bir işletim sistemi dendiğinde anlaşılması gereken yerin kernel olduğunu vurguladı. Kernel; donanımın çalışmasını, bütün çevre birimlerinin kullanılabilir olmasını, uygulama ve verilerin depolanıp gerektiğinde okunmasını ve çalışan uygulamaların "birbirini ezmeden" bir arada çalışmasını sağlayan yapıdır. Bu yüzden kernel dosya işlemlerini yönetmeli, bilgisayarın içindeki ve dışındaki bütün cihazları kullanılabilir kılmalı, belleğin kullanımını düzenlemeli ve proseslerin hangi sırayla, ne kadar çalışacağını scheduler ve dispatcher ile belirlemelidir.

### 4.2 Kullanıcı arayüzü

Kullanıcı kernel'a doğrudan dokunamaz; bu mantıklı da değildir, çünkü kernel kapalı bir kutu gibi, müdahale edilmeden çalışmalıdır. Doğrudan dokunmak donanımın yönetimine müdahale etmek olur. Etkileşim bir arayüz üzerinden yapılır: komutların, isteklerin ve verilerin sunulduğu bu arayüze kullanıcı arayüzü denir. İki temel türü vardır:

- **Metin tabanlı arayüz (shell, kabuk):** komutlar klavyeden yazılır, Enter'a basılınca işletim sistemine bir komut verilmiş olur. Örneğin bir dosyayı silme komutu verildiğinde işletim sisteminin dosya yöneticisi o dosyayı diskten siler. Windows'ta komut satırı (CMD) bir kabuktur; Unix tabanlı sistemlerde farklı komut setleri ve kolaylıklar sunan değişik kabuklar vardır; macOS'ta Terminal de bir kabuk ortamı sağlar.
- **Grafik kullanıcı arayüzü (GUI):** uygulamalar pencerelerde çalışır, dosyalar ekranda görülür, işlemler tıklanarak başlatılır ya da sonlandırılır; fare kullanımı işe girer. Windows'taki Explorer da aslında çalışan bir hizmet prosesidir ve grafik arayüzü sağlar; macOS arayüzü, Linux'ta KDE ya da GNOME (X Window sunucusuyla) başka örneklerdir.

> **Ders sonrası not:** Altyazıda Unix kabuklarının adları bozuk geçiyor; bunlar Bourne Again Shell (bash), C Shell (csh) ve Korn Shell (ksh)'dir.

Hoca kullanıcının yazdığı bir oyunu çalıştırdığında neler olduğunu bileşenlerle bağladı: oyun ekranı ve klavyeyi aygıt sürücüleri üzerinden kullanır; diziler ve değişkenler için bellek ister ve bellek yöneticisi bu alanı verir; aynı anda çalışan müzik uygulaması gibi diğer işlerle sırası düzenlenir; sırası gelen iş CPU'da çalıştırılır. Bütün bu parçalar birlikte uygulamanın çalışmasını sağlar.

### 4.3 File manager (dosya yöneticisi)

Dosya yöneticisi, diskte ya da başka bir depolama biriminde duran dosyaların saklanmasını, okunmasını, yazılmasını, silinmesini ve düzenlenmesini yönetir. Her işletim sisteminin kendine özgü bir dosya sistemi ve protokolü vardır; Windows genellikle NTFS ya da FAT32 kullanır, Linux ve macOS'un da kendi dosya sistemleri vardır. <!-- BELİRSİZ: Hocanın Linux ve macOS dosya sistemleri için söylediği adlar altyazıda "X3", "XFET" diye bozuk geçiyor (00:43:31); Linux için büyük olasılıkla ext3/ext4 kastedildi; macOS büyük olasılıkla HFS+ / APFS kullanır. -->

Esas olan dosyalardır; dosyalar isteğe bağlı olarak klasör (directory, folder) denen sanal kutularda gruplanabilir. Bu bir kategorizasyondur: bir kökten başlayarak alt klasörler hâlinde düzenleme yapılır. Slayttaki tanımlar (ekrandan, 00:45:00):

- **Directory (folder):** kullanıcının oluşturduğu, dosyaları ve başka dizinleri (alt dizinler) içeren topluluk.
- **Directory path:** dizinler içindeki dizinlerin sırası. İç içe klasörlerin altındaki bir dosyaya bu yol (path) üzerinden erişilir.

### 4.4 Device driver (aygıt sürücüsü)

Aygıt sürücüleri bilgisayardaki bileşenlerin kullanılabilir olmasını sağlar: ekranda yazılanların görünmesi, klavyede basılan tuşun anlaşılıp onu dinleyen yazılıma (örneğin kelime işlemciye) bildirilmesi, ses kartında hoparlörden ses çıkması için gerekli dönüşümler. Yazıcı örneğinde her yazıcının kendine göre bir dili ve donanımı vardır; kâğıdı çıkarmak için hangi sinyallerin gönderileceği üreticiye göre değişir. Bu cihazların kullanılabilmesini sağlayan bileşenlere aygıt sürücüsü denir ve bunlar işletim sisteminin parçasıdır.

### 4.5 Memory manager (bellek yöneticisi)

Bellek yöneticisi, silinebilir ve yazılabilir olan, elektrik gidince içeriği kaybolan ana belleğin (RAM) uygulamalar tarafından kullanılabilmesini ve aralarında paylaştırılmasını sağlar. Multitasking ile birlikte her uygulamanın dizileri, değişkenleri için kendi bellek ihtiyacı olur.

Hocanın örneği: bilgisayarda 4 GB bellek var, ama o anda çalışan uygulamaların toplam ihtiyacı 8 GB. Bellek yöneticisi bir "hile" yapar: **sanal bellek** ortamı oluşturur (paging). Diskte (sabit disk ya da SSD) örneğin 4 GB'lık bir dosya oluşturulur ve bellekmiş gibi kullanılır. Bellek bloklara bölünür; o anda çalışan uygulamanın blokları belleğe taşınır, çalışmayanlarınki diskteki sanal alana yazılır. Scheduler başka bir prosesi öne aldığında duran prosesin verisi diske yazılır, sırası gelen prosesinki belleğe alınır. Böylece gerçekte olduğundan daha fazla bellek varmış gibi hizmet verilir.

**Soru:** O zaman teorik olarak sonsuz belleğimiz var mı? **Cevap:** Hayır; adreslenebilir alan mimari tarafından zaten sınırlıdır. Sanal bellek yalnızca gerçekte olduğundan daha fazla bellek varmış gibi bir yanılsama sağlar.

Dezavantajı hızdır: diskler büyük ama yavaştır, RAM hızlı ama küçüktür. Sanal bellek kullanıldığında bellek erişim hızı disk erişim hızına iner. Örneğin diskte 128 GB'lık bir alan bellek gibi kullanılırsa, bu 128 GB ancak disk hızıyla okunup yazılabilir ve zaman ve performans açısından hiçbir etkinliği kalmaz.

> **Hocanın vurgusu:** Sanal bellek abartılırsa bellek erişimi disk hızına düşer; bu yüzden ölçülü kullanılmalıdır.

## 5. Bilgisayarın açılması (bootstrapping)

Bilgisayar kapalıyken güç düğmesine basıldığında işletim sistemi nasıl ayağa kalkar? Bilgisayarın ilklendirilmesine (başlatılmasına) **bootstrapping** ya da kısaca **booting** denir; bu işi **boot loader** yapar.

Devreler canlandığında CPU'nun yaptığı ilk iş belleğin sıfırıncı gözünü okumaktır. Von Neumann mimarisinde veri ve program kodları aynı bellekte durduğu için CPU sıfırıncı gözdeki komutu çalıştırır, sonra birinci, ikinci, üçüncü gözlerle devam eder. Belleğin en başına, bilgisayar açıldığında ne olması gerektiği komut setine uygun olarak yazılmıştır: "Disk biriminin şu adresinden işletim sisteminin kernel'ını oku ve belleğin şu bölgesine yükle." Yükleme bitince program sayacı ilerlemeye devam eder ve denetim işletim sistemine geçer. Kernel, bilgisayarın ilk çalışan uygulaması olarak her şeyin kontrolünü ele alır; proses scheduler'ı, bellek yöneticisini, disk yöneticisini ve aygıt sürücülerini (bunların hepsi birer prosestir) ayağa kaldırır. Hepsi hizmet verir hâle gelince bilgisayar komut beklemeye hazırdır.

Slayttaki şekil (ekrandan, 00:55:00):

- Ana belleğin başında ROM bölgesi ve orada Boot Loader, geri kalanı uçucu bellek (volatile memory); işletim sistemi disk deposunda (disk storage).
- **Adım 1:** Makine bellekte hazır duran bootstrap programını çalıştırarak başlar; işletim sistemi yığın bellekte (mass storage) durmaktadır.
- **Adım 2:** Boot loader programı işletim sisteminin ana belleğe aktarılmasını yönetir ve sonra denetimi ona devreder.

### 5.1 ROM ve firmware

Belleğin bu ilk bölümü **ROM**'dur (Read Only Memory, salt okunur bellek). Genellikle anakart üzerinde bir bellek çipi olarak bulunur. Hoca bunu, birinin çekiç ve çiviyle `011011...` gibi değerleri taşa kazıması gibi düşünmeyi önerdi: içerik kazınmış bir tablet gibidir ve elektrik kesildiğinde silinmez (RAM ise sıfırlanır). İçerik, işlemci mimarisine göre bilgisayarın ya da anakartın üreticisi tarafından yazılır. Bu alanın değiştirilememesinin nedeni, değiştirilirse işletim sistemini yükleme prosedürünün bozulabilmesidir; bu, işletim sistemine doğrudan müdahale olur.

**Soru:** Bilgisayarıma bir firmware güncellemesi geldi ve sürüm güncellendi; ROM yazılamıyor değil miydi? **Cevap:** Bu ROM'u programlamanın da yolu vardır; yeniden programlanabilir ROM cihazlarıyla, bilgisayar işletim sistemini yüklemeden önce ROM içeriği değiştirilebilir. Buna **firmware** denir; örneğin bir cihazın sinyalleşmesiyle ilgili bir güncelleme yapılacaksa firmware güncellenir. Güncelleme sırasında elektrik kesilirse bilgisayar "taş olur": işletim sistemi bir daha yüklenemez. Geri dönüşün yazılımsal bir yolu yoktur; ROM çipinin sökülüp özel bir cihazda yeniden programlanması gerekir.

> **Ders sonrası not:** Hoca yeniden programlanabilir ROM için altyazıda "AppROM, elektronik programlanabilir ROM" diye geçen bir ad kullandı; doğrusu EPROM ya da EEPROM'dur (Electrically Erasable Programmable ROM). Hoca ayrıca "firmware" adını "firma yazılımı" diye açıkladı; adın kökeni İngilizce "firm" (sabit, kalıcı) sözcüğüdür ve donanımla yazılım arasındaki kalıcı yazılımı anlatır.

**Soru:** CPU okumaya ROM'dan başlıyorsa işletim sistemini de ROM'a yazamaz mıyız? **Cevap:** ROM pahalı bir devredir ve bu yüzden kapasitesi küçüktür. Bu nedenle ROM'da yalnızca "işletim sistemi diskte şurada, kernel'ı oradan oku ve buraya yükle" komutları tutulur. Bazı gömülü sistemlerde ise işletim sistemi ROM'da olabilir: bir aracın bilgisayarı araç çalıştığı anda çalışmalıdır, "işletim sistemi yükleniyor, lütfen bekleyin" gibi bir bekleme kabul edilemez. Bu tür sistemlerdeki işletim sistemi çok küçük ve sınırlı olduğu için ROM'a sığar. Genel amaçlı bilgisayarlarda ve sunucularda ise ROM'da yalnızca küçük bir başlangıç kodu bulunur.

## 6. Proses yönetimi: scheduler ve dispatcher

### 6.1 Proses durumu

Time-sharing'de prosesler arasında geçiş yapabilmek için işletim sisteminin her çalışan prosesin durumunu (state) bilmesi gerekir. Bir prosesin durumu; program sayacının (program counter) değeri, CPU yazmaçlarının (register) değerleri, prosesin kullandığı bellek adresleri ve benzeri temel verilerden oluşur. Hoca bunu bir tablo ya da defter sayfası gibi düşünmeyi önerdi. Bir proses askıya alınıp sıradaki proses çalıştırılacağı anda prosesin "şipşak fotoğrafı" çekilip bir yere yazılmalıdır. Örneğin bir prosese 10 milisaniye verildiyse, süre sonunda bu değerler CPU'nun erişebildiği özel bir bellek alanına (günümüz mimarilerinde yazmaçlarda bile) yazılır. Sonra ikinci proses (örneğin müzik uygulaması) 10 ms çalışır, sonra kelime işlemci gelir. Her geçişte fotoğraf çekilir, proses yeniden CPU'ya verildiğinde fotoğraf geri yüklenir. Bu işlerin bütününe **process administration** (proses yönetimi) denir.

### 6.2 Scheduler ve dispatcher

Slayttaki tanımlar (ekrandan, 01:05:00):

- **Scheduler:** yeni prosesleri proses tablosuna ekler ve tamamlanan prosesleri proses tablosundan çıkarır.
- **Dispatcher:** proses tablosundaki proseslere zaman dilimlerinin (time slice) ayrılmasını denetler.
  - Bir zaman diliminin sonu bir kesme (interrupt) ile bildirilir.

Hoca scheduler için Windows'taki Görev Yöneticisi listesini (Linux'ta benzer bir tabloyu) örnek verdi: hangi prosesin aktif olduğu, hangisinin uyuduğu orada görülür; proses kapandığında listeden silinir.

Dispatcher'ın çalışması şöyledir: scheduler "A prosesi" der; dispatcher çalışan prosesi durdurur, fotoğrafını özel alana yazar, A prosesinin en son fotoğrafını tablodan alıp yükler ve A'nın CPU'da, yani bütün donanımın mutlak hâkimi olarak çalışmasını sağlar. Başlattığı anda elinde bir kronometre varmış gibi süreyi başlatır; 10 ms sonra bir sinyal gelir. Bu sinyale **kesme (interrupt)** denir. Kesme, **interrupt handler**'ı çalıştırır: fotoğrafı çeker, alana yazar ve proses tablosuna, yani scheduler'a döner: "Şimdi neyi dispatch edeceğim?" Scheduler önceliğe göre B prosesini seçer; dispatcher onu CPU'ya yükler ve B kaldığı yerden devam eder. Önceliklendirme yöntemlerinin ayrıntıları İşletim Sistemleri dersinde görülecektir.

Hoca bunu filme benzetti: film, belli hızla oynatılan fotoğraflar dizisidir ve sürekli akıyormuş gibi görünür. Prosesler de milisaniyelik fotoğraflar gibi art arda işletildiğinde bilgisayar hepsini aynı anda çalıştırıyormuş gibi görünür.

Slayttaki "A ve B prosesleri arasında time-sharing" şeklinde zaman ekseni boyunca dilimler sıralanır: A çalışır, kesme gelir, process switch ile B çalışır, kesme gelir, A'ya geri dönülür ve böyle sürer (ekrandan, 01:10:00):

```text
Zaman ->   | A | B | A | B | A | ...
            ^   ^   ^   ^   ^
         her sınırda: interrupt -> process switch
```

Geçişte B'nin kaldığı yerin fotoğrafı (bellek adresleri, yazmaç değerleri, program sayacı) yüklenir. Uzaktan hızlıca bakıldığında iki proses yan yana koşuyormuş gibi görünür; time-sharing özünde bu şekilde gerçekleştirilir.

## 7. Kaynak paylaşımı: semafor ve kritik bölge

### 7.1 Sorun: paylaşılamayan kaynakta yarış

Prosesler sistem kaynaklarını kullanmak ister. Hocanın örneğinde A prosesi bir kelime işlemci, B prosesi bir hesap tablosudur ve ikisi de yazıcıya çıktı göndermek ister. Tek bir yazıcı vardır ve bir belgeyi basarken başka birini basamaz; yani yazıcı **paylaşılamayan** bir kaynaktır. Yazıcının durumunu 0-1 değerli bir bayrak (flag) tutar.

Olaylar şöyle gelişir (hocanın tahta üzerindeki anlatımı, ekrandan, 01:10:00):

1. B çalışırken işletim sisteminden yazıcıyı ister. İşletim sistemi bayrağa bakar, yazıcı boştur, yazıcıyı B'ye vermeye karar verir.
2. Ama bayrak boyanmadan B'nin zaman dilimi biter, kesme gelir; dispatcher B'yi dondurur.
3. A çalışır, yazıcıyı ister. İşletim sistemi bayrağa bakar, hâlâ boştur; bayrağı boyar ve yazıcıyı A'ya verir. A basmaya başlar, sonra onun da dilimi biter.
4. B kaldığı yerden devam eder: ona "tamam" denmişti, bayrağı boyamaya ve yazıcıyı kullanmaya çalışır.
5. Yazıcı aynı anda iki proses tarafından kullanılamaz; sistem çöker.

Demek ki kesikli çalışan bir ortamda proseslerin kaynaklara erişimi düzgün denetlenmelidir. Bu denetim yapısına **semafor** denir; tahtaya çizilen bayrak da aslında bir denetim bayrağıdır.

### 7.2 Çözüm: kritik bölge ve karşılıklı dışlama

Çözüm, bayrağın kontrol edilip ayarlandığı kod bölümünü **kritik bölge (critical region)** olarak tanımlamak ve bu bölgeyi **karşılıklı dışlamaya (mutual exclusion)** tabi tutmaktır. Kritik bölge; paylaşılamayan bir kaynağın bir prosese verilmesi sırasında sorulan "boş mu?" ve "rezerve et" adımlarının **atomik**, yani bölünemez olmasını sağlayan özel tanımlı bir bölgedir. Kritik bölgedeki bir proses kesme yemez; ya da kesmenin yakın olduğu durumda proses kritik bölgeye hiç sokulmaz (örneğin dilimin bitmesine belirli bir süreden az kaldıysa). Böylece "sorup sonra kaldığı yerden devam etme" durumu oluşmaz.

Bunun bir yolu **test-and-set**'tir: "boş mu?" ve "bana ver" sorularını tek, bölünemez bir komut (instruction) olarak modellemek. Böylece bayrak ya boştur ya da boyanıp tek bir prosese verilir.

> **Hocanın vurgusu:** Herhangi bir anda bir kritik bölgede yalnızca tek bir proses bulunabilir. İşletim sistemi bunu düzgün biçimde denetlemelidir; isteği bölünmez bir alanda yapar ve o alanda bir anda tek prosese izin verirseniz semafor yapısını doğru tasarlamış olursunuz.

Farklı kaynak türleri için farklı gerçeklemeler vardır; ayrıntılarına girilmedi.

## 8. Deadlock (kilitlenme)

### 8.1 İki kaynaklı örnek

Tek kaynakta iki prosesin aynı anda istek yapması önlenebiliyor. Peki iki ayrı kaynak varsa? Hocanın örneğinde bir yazıcı ve bir CD-ROM vardır (ekrandan, 01:15:00):

1. A prosesi yazıcıyı ister; yazıcı boştur, A'ya verilir.
2. Bir sonraki zaman diliminde B prosesi CD-ROM'dan okumak ister; CD-ROM boştur, B'ye verilir.
3. A yazıcıyı kullanmaya devam ederken CD-ROM'dan okumak ister; CD-ROM B'dedir, A beklemeye alınır.
4. B CD-ROM'dan okurken yazıcıdan bir şey bastırmak ister; yazıcı A'dadır, B beklemeye alınır.

A, B'nin kaynağının boşalmasını; B, A'nın kaynağının boşalmasını bekler. Birbirlerini kilitlemişlerdir. Bu duruma **deadlock** denir.

Slayttaki tanım ve koşullar (ekrandan, 01:15:00):

- Prosesler birbirlerinin devam etmesini engeller (processes block each other from continuing).
- Deadlock için gereken koşullar:
  1. Paylaşılamayan kaynaklar için rekabet (competition for non-sharable resources).
  2. Kaynakların parça parça istenmesi (resources requested on a partial basis).
  3. Ayrılmış bir kaynağın zorla geri alınamaması (an allocated resource can not be forcibly retrieved).

Örnekte üç koşul da oluşmuştur: yazıcı ve CD-ROM aynı anda iki proses tarafından kullanılamaz; kaynaklar teker teker istenmiştir; işletim sisteminin A'ya "yazdırmayı bırak" ya da B'ye "okumayı bırak" deme hakkı yoktur.

> **Hocanın vurgusu:** Bu üç koşul birlikte oluşursa deadlock kesin oluşur.

Hoca, hem semafor fikrinin hem de deadlock sorununun aslında çok eskiden demiryollarında çözülmüş bir problemden geldiğini söyledi: iki tren birbirinin geçeceği hat parçasını tutarsa ikisi de ilerleyemez. Tahtadaki çizim de bu tren benzetmesiydi (ekrandan, 01:20:00).

### 8.2 Deadlock'tan kurtulma yolları

Çözüm, üç koşulun aynı anda oluşmasını işletim sisteminin engellemesidir. Hoca koşulları tersten ele aldı:

- **3. koşul (zorla geri alamama) → deadlock detection and correction:** kilitlenme fark edilir ve düzeltilir. Örneğin işletim sistemi B'ye "CD-ROM kaynağını senden alıyorum" der; kaynak zorla alınınca A'ya verilebilir, A işini bitirir, sonra B'ye hem CD-ROM hem yazıcı verilir. Linux'ta prosesler fork ederek alt prosesler oluşturabilir; proses tablosunda hepsine yer kalmayıp herkes birbirini beklemeye başlarsa işletim sistemi bazı prosesleri sonlandırır (kill) ve diğerlerine yer açar.
- **2. koşul (parça parça istek) → hocanın "deadlock avoidance" dediği yaklaşım:** işletim sistemi proseslere "isteyeceğin bütün kaynakları bir kerede iste" der. A hem yazıcıyı hem CD-ROM'u aynı anda ister ve ikisini birden alır; sonra gelen B'ye "kaynaklar dolu, bekle" denir.
- **1. koşul (paylaşılamayan kaynak) → spooling:** kelime işlemciden on sayfa bastırırken hesap tablosundan da, arada bir fotoğraf da bastırırsınız ve işletim sistemi "yazıcı dolu" demez. Bunun yerine işleri sanal bir kuyruğa koyar: A gerçekten yazıcıyı kullanırken B'ye "kaynağı verdim" denir, ama B'nin yazıcıya göndermek istediği her şey aslında diskteki bir dosyaya yazılır; C geldiğinde onunki de kuyruğa eklenir. Yazıcı boşaldıkça sırayla basılır. Herkes kaynağı o anda kullanıyormuş gibi hisseder ama aslında ileride kullanır. Paylaşılamayan kaynakları paylaşılıyormuş gibi göstermeye **spooling** denir ve yazıcı bunun en güzel örneğidir.

## 9. İşletim sistemi güvenliği

Slayttaki başlıklar (ekrandan, 01:25:00):

- Dışarıdan saldırılar
  - Sorunlar: güvensiz şifreler (insecure passwords), dinleme yazılımları (sniffing software)
  - Karşı önlemler: denetim yazılımları (auditing software)

### 9.1 Dış saldırılar

İşletim sistemi kullanıcıları kullanıcı adıyla ayırt eder; kullanıcının gerçekten o kişi olduğunu şifreyle doğrular. Bir kullanıcı adının şifresini sağlayabilen kişi, işletim sistemi için o kullanıcıdır. Her işletim sisteminde tüm yetkilere sahip bir süper kullanıcı (super user) bulunmalıdır; eski bilgisayarlardaki sistem operatörü gibi. Windows'ta Administrator, Unix ortamlarında root; bu kullanıcı olmadan sistem ayarları yapılamaz.

Hoca zayıf şifre tehlikesini şöyle anlattı: süper kullanıcı için kolay tahmin edilen ardışık rakamlardan oluşan bir şifre seçerseniz, siz masadan kalktığınızda biri giriş ekranında kullanıcı adını ve bu şifreyi dener ve sisteme girer. Saldırı terminalden yapılmak zorunda da değildir: ücretli bir yazılımı kırmak için çalıştırdığınız bir "crack" programı aslında kötü niyetli olabilir. Kendine sürekli çalışan bir proses ekler ve basılan bütün tuşları, işletim sisteminin tuşları uygulamaya iletmesi gibi, ağ kartı üzerinden belirli bir IP adresine gönderir. Böylece kullanıcı adınız, şifreleriniz, sayısal kodlarınız ele geçirilir. Bilmediğiniz yazılımlara karşı çok dikkatli olunmalıdır. Yetkisiz kullanıcının işlemlerini izleyen ya da sürekli ağa veri gönderen prosesleri raporlayan güvenlik (denetim) yazılımları vardır.

### 9.2 İç saldırılar ve ayrıcalıklı kip

Saldırı içeriden de gelebilir: kötü niyetli bir proses, proses tablosunda tutulan bellek sınırlarını değiştirebilir ya da başka bir prosesin bellek alanını okuyabilir. İşletim sistemi bunu fark edip engellemelidir. Modern CPU'larda bunun için **privileged mode** (ayrıcalıklı kip) özelliği vardır. Açılışta ayrıcalıklı kipte başlanır (orada ROM'daki kod ve ardından kernel çalışır). İşletim sisteminin yüklenmesi bitince **non-privileged mode**'a geçilir; bu kipte proseslerin bellek sınırlarının başka prosesler tarafından değiştirilmesi engellenir ve bütün normal prosesler kısıtlı olarak çalışır. Ayrıcalıklı kipe geçebilen bir kod ise bütün proseslerin bellek sınırlarını değiştirebilir.

Hoca yakın geçmişte Intel işlemcilerde, kötü niyetli bir kodun ayrıcalıksız kipten çıkıp başka bellek alanlarına erişebildiği bir güvenlik açığı bulunduğunu ve bunun yamalarla giderilmeye çalışıldığını hatırlattı.

> **Ek bilgi (derste anlatılmadı):** Hocanın andığı açık büyük olasılıkla 2018'de duyurulan Meltdown açığıdır; bu açık, ayrıcalıksız kipte çalışan bir prosesin çekirdek belleğini okuyabilmesine yol açıyordu ve işletim sistemi yamalarıyla hafifletildi.

## 10. Ağların sınıflandırılması

Ara verildikten sonra ikinci konuya geçildi. Ağ bölümünde de beş başlık vardı: temeller, internet, World Wide Web, protokoller ve güvenlik. Slayttaki sınıflandırma (ekrandan, 01:45:00):

- **Kapsam (scope)**
  - **PAN (personal area network):** birbirine en yakın cihazlar arasındaki ağ. Telefon ile kablosuz kulaklığın Bluetooth üzerinden bağlanması ya da USB alıcılı kablosuz farenin 2,4 GHz'de yayın yapması.
  - **LAN (local area network):** fiziksel kapasite sınırları içinde, genellikle bir bina içindeki cihazların oluşturduğu yerel ağ; kesin bir sınırı yoktur.
  - **MAN (metropolitan area network):** daha geniş alana yayılan ağ. Örnek: bir üniversitenin farklı kampüslerindeki LAN'ların birleştirilip aynı üniversite ağı içinde konuşabilmesi.
  - **WAN (wide area network):** iller ya da kıtalar arası bağlantılar. Örnek: bir bankanın bir şehirdeki veri merkezinin deprem ve doğal afetlere karşı başka şehirlerde kopyalarının bulunması ve hepsinin birlikte çalışması.
- **Sahiplik (ownership):** kapalı (closed) ve açık (open). Kapalı ağ dışarıdan erişime kapalıdır (örneğin bir şirketin Ar-Ge laboratuvarının ağı); açık ağ, internetteki gibi başka bağlantılara izin verir.
- **Topoloji (configuration)**
  - **Bus (Ethernet):** bütün cihazlar fiziksel olarak tek bir hatta bağlıdır.
  - **Star:** merkezde bir erişim noktası (access point) bulunan kablosuz ağlar.

### 10.1 Bus yapısında iletim

A bilgisayarı E'ye mesaj göndermek isterse mesajı hatta çıkarır ve üzerine "E" yazar, zarfa etiket yapıştırmak gibi. Herkes bu hatta bağlı olduğu için herkes mesajı alır; ama her bilgisayar etikete bakar, "bana gelmemiş" diyen ilgilenmez, yalnızca E mesajı alıp işler.

Göndermeden önce hattın boş olup olmadığına bakılır, boşsa mesaj gönderilir. Şans eseri aynı anda C de D'ye mesaj gönderirse iki mesaj aynı anda hatta çıkar ve **çarpışma (collision)** olur. Bu durumda tam olarak insanların yaptığı yapılır: iki kişi aynı anda konuşmaya başlarsa ikisi de susar. İki taraf da mesajı geri çeker ve rastgele bir süre bekler; örneğin biri 10 ms, diğeri 8 ms. 8 ms sonra hattı boş bulan gönderir; 10 ms bekleyen ise hattı dolu bulur ve hat boşalınca gönderir.

### 10.2 Star yapısında iletim

Star topolojisinde herkes ortadaki erişim noktası (AP) üzerinden konuşur. Burada "hat boş mu, konuşabilir miyim?" sorusu daha zordur, çünkü aynı anda iki cihaz istek yaparsa erişim noktası ikisine de cevap vermek zorunda kalır. Genel yaklaşım şudur: önce hattın boş olup olmadığına bakılır, bir süre sonra bir daha bakılır, hâlâ boşsa konuşulur. Hoca bunu yola çıkmadan önce araba gelip gelmediğine bakan, hemen çıkmayıp biraz bekleyip bir kez daha bakan yayaya benzetti.

## 11. Erişim protokolleri: CSMA/CD ve CSMA/CA

Slayttaki başlıklar (ekrandan, 01:50:00):

- **CSMA/CD** (Carrier Sense Multiple Access with Collision Detection)
  - Ethernet'te kullanılır.
  - Sessiz bir bus, yeni mesaj gönderme hakkı verir.
- **CSMA/CA** (Carrier Sense Multiple Access with Collision Avoidance)
  - WiFi'da kullanılır.
  - Gizli terminal problemi (hidden terminal problem).

CSMA/CD'de hat boşsa doğrudan konuşulur; iki taraf aynı anda başlarsa farklı sürelerde bekleyip yeniden dener, kısa bekleyen önce konuşur. CSMA/CA'da ise hat boşsa bir süre daha beklenir, yine boşsa mesaj gönderilir. CSMA/CA, IEEE (Elektrik ve Elektronik Mühendisleri Enstitüsü; standartlar koyan uluslararası bir meslek kuruluşu) tarafından **802.11** standardı olarak tanımlanmıştır ve Wi-Fi'da temel kullanılan tekniktir.

### 11.1 Gizli terminal problemi

Hocanın tahtadaki örneği: B bilgisayarının kablosuz etki alanı geniştir, C'ninki daha küçüktür, A'nınki ortanca büyüklüktedir ve arada sinyallerin geçmesini engelleyen bir bina vardır. B, CSMA/CA gereğince yalnızca kendi menzilinde hattın boş olup olmadığına bakabilir; boş görür, biraz bekler, yine boş görür ve gönderir. A da aynısını yapar, çünkü B'yi göremez; C de aynısını yapabilir. Hiçbiri diğerinin konuştuğunu görmediği için hepsi aynı anda ortadaki erişim noktasıyla konuşmaya çalışabilir. CSMA/CA bunu çözmez.

Çözüm: konuşmak isteyen (örneğin B) erişim noktasına önce bir istek (request) gönderir. Erişim noktasından bir onay (acknowledgement, "tamam, konuş") gelirse hattı kullanır ve paketlerini gönderir; onay gelmezse bir süre bekleyip yeniden istek gönderir. Başkasının konuştuğu görülemediğine göre, konuşulacak tarafa sorup onay alındıktan sonra konuşulur.

> **Ek bilgi (derste anlatılmadı):** 802.11'de bu istek-onay mekanizması RTS/CTS (Request to Send / Clear to Send) adıyla bilinir; erişim noktasının gönderdiği CTS çerçevesini menzildeki bütün istasyonlar duyduğu için birbirini göremeyen istasyonlar da o süre boyunca susar.

## 12. Ağları birleştirme: repeater, bridge, switch, router

Birden fazla ağı birleştirmek için dört temel cihaz vardır: repeater, bridge, switch ve router. Slayttaki şekil "küçük bus ağlarından büyük bir bus ağı kurmak" başlığını taşır: (a) iki bus'ı bağlayan bir repeater ya da bridge, (b) birden çok bus'ı bağlayan bir switch (ekrandan, 01:55:00).

- **Repeater:** soldaki bütün trafiği sağa, sağdaki bütün trafiği sola körlemesine aktarır. A düğümü aynı taraftaki B'ye mesaj gönderse bile mesaj repeater'dan geçip öbür taraftaki bütün düğümlere ulaşır; onlar da "bize gelmemiş" deyip bırakır. Hoca bunu papağana benzetti.
- **Bridge:** repeater'ın daha akıllısıdır. A, aynı taraftaki B'ye mesaj gönderirse bridge mesajı diğer tarafa geçirmez ve o taraf serbest kalır. Öbür taraftaki C, B'ye gönderirse bridge mesajı B'nin tarafına geçirir; C kendi tarafındaki D'ye gönderirse mesaj hiç geçmez. Yani gerekmedikçe paketi diğer tarafa göndermez.
- **Switch:** aynı mantıkla çalışan birden fazla bridge'i içinde barındırıyormuş gibi düşünülebilir. Gri, siyah ve beyaz üç ağ olsun: gri-siyahı bir köprü, beyaz-siyahı ikinci bir köprü, gri-beyazı üçüncü bir köprü bağlıyormuş gibi davranır. Gri ağ içinde kalması gereken mesajı diğerlerine taşımaz; siyahtan griye giden mesajı beyaza göndermez. Her ağ kendi içinde kalır, karşıya yalnızca gerektiği kadar trafik taşınır.
- **Router:** heterojen ağları birbirine bağlayan, paketleri anahtarlayan ve mesajların hedefe doğru yol almasını sağlayan cihazdır. Aslında ağ bağlantıları çok güçlü, özelleşmiş bir bilgisayardır; içindeki yönlendirme (routing) algoritmalarıyla paketlerin nereye ve nasıl gideceğine karar verir.

Router örneğinde üç ağ, her biri bir router'a bağlı ve router'lar da birbirine bağlıdır. Bir ağdaki bilgisayar başka ağdaki bir bilgisayara mesaj gönderdiğinde mesaj önce erişim noktasına, oradan router'a gider. Normalde router mesajı doğrudan hedef ağın router'ına gönderir. Ama bu bağlantı, her saat trafiği olan bir köprü gibi çok meşgulse, router yönlendirme algoritmaları sayesinde başka hatların boş olduğunu bilir ve paketi başka bir router üzerinden dolaştırarak daha hızlı ulaştırır.

Router'ların birbirine bağladığı ağlardan oluşan yapıya (küçük harfle) **internet** denir.

## 13. Prosesler arası iletişim ve dağıtık sistemler

### 13.1 IPC: client-server ve peer-to-peer

Farklı makinelerde çalışan proseslerin haberleşerek birlikte çalışmasını sağlayan yapılara **IPC (inter-process communication)** denir. İki temel model vardır:

- **Client-server (istemci-sunucu):** genellikle bir sunucu birçok istemciye hizmet verir. Sunucunun sürekli çalışır hâlde kalması esastır; bağlantıyı ve isteği istemcinin başlatması beklenir.
- **Peer-to-peer (eşler arası):** herkes hem istemci hem sunucudur. En güzel örneği torrentlerdir: dosyanın parçaları herkeste durur; bir dosyayı başkalarından alırken siz de başkalarının istediği parçaları gönderirsiniz.

Client-server örneği olarak hoca bir yazıcı sunucusunu (print server) çizdi: yazıcı bir cihaza, o cihaz da ağa (erişim noktasına) bağlıdır. Bir bölüm sekreterliğindeki ağ fotokopi makinesi tam böyle çalışır: kullanıcılar baskı istemcisidir, ağ üzerinden baskı isteği gönderirler; sunucu isteği kabul eder ve kâğıt çıktısını üretir. Hoca, sanki istemci buyuruyor gibi görünse de hizmeti sunan tarafın sunucu, alan tarafın istemci olduğunu vurguladı.

### 13.2 Dağıtık sistemler

Belli parçaları ağla bağlı farklı bilgisayarlarda çalışan, birlikte sonuç üreten sistemlere **dağıtık sistem** denir. Hoca kabaca şu kategorileri verdi:

- **Cluster computing:** makineler birbirine yakın ve bağlıdır (aynı alt ağda, aynı bus üzerinde). Genellikle basit makineler bir araya getirilerek daha büyük işlem gücüne ulaşılır.
- **Grid computing:** kümenin makineleri arasındaki mesafe açılmıştır; farklı odalarda ya da binalarda dururlar.
- **Cloud computing (bulut hesaplama):** tamamen dağınık; veri merkezleri dünyanın farklı şehirlerine yayılmıştır. Büyük web ve depolama hizmetleri böyle çalışır: bir dosyayı bulut depolamaya koyduğunuzda hangi şehirdeki sunucuya gittiğiyle ilgilenmezsiniz.

## 14. İnternet: mimari, adresleme ve DNS

### 14.1 The Internet

Küçük harfli internet, router'ların birbirine bağladığı heterojen ağlardır. Büyük harfle "the Internet" ise bütün dünyayı kaplayan, birbirine bağlı ağlar bütünüdür. Slayttaki bilgiler (ekrandan, 02:05:00):

- The Internet: dünyayı saran bir internet.
  - İlk amaç, yerel felaketlerden etkilenmeyecek bir ağ bağlama yöntemi geliştirmekti.
  - Bugün akademik bir araştırma projesinden ticari bir girişime dönüşmüştür.

Hoca, başlangıçta bunun ABD Savunma Bakanlığı'nın bir projesi (DARPA) olduğunu, yerel bir felakette bilgiler kaybolmasın diye üniversitelerin birbirine bağlandığını anlattı.

### 14.2 ISP katmanları

İnternetin temelde üç katmanı vardır ve hepsi internet servis sağlayıcısı (ISP) katmanıdır:

- **Tier-1:** çok yüksek hızlı, çok yüksek kapasiteli uluslararası ya da kıtalararası router ağı; internetin omurgası (backbone). Okyanusların altından geçen fiber optik kablolar gibi.
- **Tier-2:** bölgesel ağlar. Örneğin Avrupa'ya gelen trafik oradan farklı ülkelere ve bölgelere dağılır.
- **Access ISP (Tier-3):** son kullanıcıya erişim veren yerel servis sağlayıcıları; kablo, DSL, kablosuz ya da mobil modem ile bağlantı sağlanır. Fatura ödenen kısım burasıdır.

En alttaki uç sistemler (end system) bir cep telefonu, bir sunucu, bir veri merkezi, hatta bir IoT sensörü olabilir; yeter ki bir erişim ISP'sine bağlansın. Para trafikte döner: kullanıcı erişim ISP'sine öder, erişim ISP'si üstteki omurgayı kullanmak için trafik başına öder, o da daha üstüne öder.

Bir uç sistemden diğerine gitmek için kendi ISP'nize, oradan üst kademelere, gerekirse omurgaya kadar çıkılır, sonra hedefin yerel ISP'si üzerinden hedefe inilir. Hedefin nerede olduğu adresiyle bilinir.

### 14.3 IP adresi

Slayttaki tanım (ekrandan, 02:10:00):

- **IP address:** genellikle noktalı ondalık gösterimle (dotted decimal notation) yazılan 32 ya da 128 bitlik desen.
- **Mnemonic address:** domain names, top-level domains.
- **Domain name system (DNS):** name servers, DNS lookup.

32 bitlik adres, noktalarla ayrılmış dört adet 8 bitlik alandan oluşur; hocanın slayta yazdığı örnek `193.140.4.1`'dir (ekrandan, 02:10:00). Her alan 0 ile 255 arasında değer alabilir ($2^8 = 256$ farklı değer), ama bazı değerler ayrılmıştır (rezerve). Teorik olarak her uç sistemin tekil bir adresi olmalıdır; ancak 32 bitle adres sayısı sınırlıdır ($2^{32} \approx 4{,}3$ milyar) ve ayrılmış adresler düşülünce daha da azalır. Bir şirket tek bir dış IP alıp kendi içindeki bin bilgisayara yerel (sanal) IP'ler dağıtabilir; herkes o tek IP üzerinden internete çıkar. Bu da yetmediği için, özellikle IoT cihazlarının adreslenmesi nedeniyle, 128 bitlik adreslemeye, yani **IPv6**'ya geçiş çalışmaları sürmektedir.

### 14.4 Alan adları ve DNS

Sayısal adresleri akılda tutmak çok zordur. Bunun için **domain name** (etki alanı adı) denen bir isimlendirme sistemi vardır. Alan adları **top-level domain (TLD)** denen kategorilere ayrılır; `.com`, `.edu` gibi genel amaçlı uzantılar ve `.tr` gibi ülke uzantıları vardır. <!-- BELİRSİZ: TLD türlerinin anlatıldığı 02:11:54-02:12:53 aralığı altyazıda büyük ölçüde kopuk; slayttaki TLD listesi okunamadı. --> Örneğin Türkiye'deki bir eğitim kurumunun alan adı `.edu.tr` uzantılıdır ve arka planda bir IP adresine karşılık gelir.

İnsanın hatırlayabildiği adın sayısal karşılığı, telefon rehberi gibi duran bir sistemde tutulur; buna **DNS (Domain Name System)** denir. Bu hizmeti veren sunuculara **name server** (alan adı sunucusu), sorgulama işlemine **DNS lookup** denir. Tarayıcıya bir alan adı yazdığınızda aslında bir DNS sunucusuna "bu adresin IP karşılığı nedir?" diye sorarsınız ve cevap olarak sayısal bir adres gelir; ağ üzerinde hep bu sayısal adresle konuşulur.

DNS sunucusu adresi biliyorsa doğrudan söyler; bilmiyorsa bir üst kademeye sorar ve bu, bir sunucuda adres bulunana kadar sürer. Hiçbir yerde bulunamazsa "böyle bir adres yok" cevabı döner.

### 14.5 ICANN ve yerel otoriteler

Slayttaki bilgiler (ekrandan, 02:15:00):

- **ICANN (Internet Corporation for Assigned Names and Numbers):** IP adreslerini ISP'lere dağıtır, ISP'ler de bu adresleri kendi bölgelerinde atar.
- Alan adlarının kaydını gözetir.

ICANN dünyadaki bütün alan adlarını kendisi tutmaz; bu işi bölgesel olarak yerel otoritelere dağıtmıştır. Hoca, `.tr` uzantısının yakın zamana kadar ODTÜ'nün kontrolünde olduğunu, şirketlerin belgeleriyle başvurup ücret ödeyerek alan adı aldığını, günümüzde ise bu işi BTK'nın yürüttüğünü söyledi. ABD'de bu iş belirli şirketlere dağıtılmıştır; bu şirketler alan adı-IP eşlemesini yapar ve bilgi ICANN'e ve DNS sunucularına iletilir.

> **Ders sonrası not:** Hoca BTK'nın açılımından emin olmadığını söyledi; açılım Bilgi Teknolojileri ve İletişim Kurumu'dur. `.tr` alan adlarının yönetiminin BTK'nın sistemine geçişi büyük olasılıkla 2022'de tamamlandı.

## 15. İnternet uygulamaları

Bu kadar trafik hizmet almak ya da vermek için yaratılır. Hoca en yaygın uygulamalara kısaca baktı:

- **E-posta:** internet trafiğinde önemli yer tutar ve kendine özgü protokolleri vardır. Mail göndermek için **SMTP** (Simple Mail Transfer Protocol), almak için **POP3** (Post Office Protocol) ya da alternatif olarak **IMAP** kullanılır. Bu protokoller metin tabanlıdır, ASCII karakterlerinden oluşur. ASCII'de olmayan Türkçe karakterler ya da emojiler için **MIME** (Multipurpose Internet Mail Extensions) dönüşümü kullanılır; her şey ASCII karakter dizisine dönüştürülür. Paketlerin içi açıldığında anlamsız karakter dizileri görülmesinin nedeni budur.
- **FTP (File Transfer Protocol):** ağ üzerinden dosya alıp vermek için; ikili (binary) dosya aktarımına olanak sağlar.
- **Telnet ve SSH:** uzak sistemlere erişip onların metin tabanlı kullanıcı arayüzlerini kullanmak için.

Daha yeni uygulamalar (ekrandan, 02:20:00):

- **Voice over IP (VoIP)**
- **Internet Radio:** N-unicast, multicast. Bir dönem vardı, hâlâ var ama çok tutmadı.
- **On-Demand Streaming:** Content Delivery Networks (CDN) (anycast).

İnternet radyosunun yerini isteğe bağlı yayın (on-demand streaming) aldı: müzik ve dizi-film platformları gibi, ne isterseniz o içerik size sunulur. Arka planda **CDN** teknolojisi vardır. Hocanın örneğinde bir müzik platformunun verilerinin kopyaları Hollanda, Moskova, Ankara, Atina, Kaliforniya ve New York'taki sunucularda durur. İstanbul'dan bir şarkı istendiğinde platform, ağ trafiğine de bakarak en uygun kopyayı seçer: Ankara'ya yakın olduğunuz için içeriği Ankara'dan akıtabilir; Ankara'nın trafiği yüksekse Atina'dan gönderebilir. Karar algoritmalarla verilir. Bu yapıya anycast ya da CDN denir.

## 16. World Wide Web: HTTP, URL, HTML ve XML

### 16.1 HTTP ve URL

**HTTP (Hypertext Transfer Protocol)**, birbirine bağlı web sayfaları arasında tıklayarak gezinmeyi, başka alan adlarındaki kaynaklara geçmeyi sağlayan protokoldür. Bu içeriğin bütününden oluşan yapıya **World Wide Web** denir.

Web'deki her belgenin, sayfanın ve içeriğin benzersiz bir tanımlayıcısı vardır; alan adına benzer, ama bir alan adı altında birçok içerik bulunabilir. Bu tanımlayıcıya **URL (Uniform Resource Locator)** denir. Slayttaki tipik URL şu parçalardan oluşur:

- En başta protokol: `http`, çünkü belge hipermetin protokolüyle alınacaktır.
- Ardından alan adı: `aw.com` alan adı ve onun altında `ssenterprise` alt alanı (subdomain).
- Ardından web sunucusundaki dizin yolu: `authors/Shakespeare` (işletim sistemlerindeki dosya yolu gibi).
- En sağda erişilen belgenin adı: `Julius_Caesar.html`.

<!-- BELİRSİZ: URL slaytının karesi incelenmedi; parçalar altyazıdan kuruldu (02:23:09-02:24:18). Tam yazım büyük olasılıkla http://ssenterprise.aw.com/authors/Shakespeare/Julius_Caesar.html biçimindedir. -->

### 16.2 HTML

URL'deki içerik genellikle **HTML** ile biçimlenir: etiketlerle "bu bir başlık, bu bir paragraf" diye içerik işaretlenir. Slayttaki basit web sayfası (ekrandan, 02:25:00):

```html
<html>
<head>
<title>demonstration page</title>
</head>
<body>
<h1>My Web Page</h1>
<p>Click here for another page.</p>
</body>
</html>
```

Slayttaki açıklamalara göre `<html>` belgenin başını, `</html>` sonunu gösterir; `<head>` bölümü ön bilgileri (başlık bilgisi `title`) içerir; `<body>` bölümü tarayıcıda görüntülenecek kısımdır. `<h1>` birinci düzey başlık, `<p>` paragraf etiketidir. Tarayıcı bu yapıyı biçimlendirilmiş sayfa olarak gösterir.

Bağlantı (link) mekanizması başka bir etiketle gösterilir: "here" sözcüğü bir bağlantı etiketiyle işaretlenir ve bu etiketin referans özelliğine (`href`) yeni bir URL verilir. Kullanıcı "click here"e tıkladığında o URL'ye gider. Hoca, HTTP'nin bütün gücünün burada olduğunu söyledi: tek tıkla bambaşka bir alan adındaki bambaşka içeriğe geçilebilir ve bütün içerik bir örümcek ağı gibi birbirine bağlanabilir; "web" adı buradan gelir.

### 16.3 XML

HTML'de etiketler önceden tanımlıdır ve tarayıcılar bunları anlamlandırır; **XML**'de ise etiketleri kullanıcı tanımlayabilir. Hocanın örneğinde bir müzik dizesi XML ile kodlandı: dizenin bir anahtarı (sol anahtarı), bemol işaretleriyle belirtilen bir tonu (do minör) ve 2/4'lük bir ölçüsü vardır. Notalar ölçü (measure) etiketleri içinde yazılır:

- Birinci ölçü: bir sekizlik es ve üç sekizlik Sol notası. Toplam süre $\frac{1}{8} + 3 \times \frac{1}{8} = \frac{4}{8} = \frac{1}{2}$, yani 2/4'lük ölçüyü doldurur (ara adım eklendi).
- İkinci ölçü: bir ikilik Mi notası, süresi $\frac{1}{2}$.

Böylece bir müzik ifadesi, bir makinenin okuyup anlamlandırabileceği etiketli bir biçime çevrilmiş olur.

> **Ders sonrası not:** Hoca HTML'in XML'in özelleştirilmiş bir alt kümesi olduğunu söyledi; doğrusu HTML SGML kökenlidir, XML kurallarına uyan sürümü XHTML'dir.

### 16.4 İstemci ve sunucu tarafı işlevsellik

Client-server mimarisinde iki tarafta da işlevsellik sağlanabilir. İstemci tarafında genellikle JavaScript ile küçük kontroller ya da animasyonlar bulunur. Sunucu tarafında ise veriyle çalışan, veri kullanarak içerik üreten uygulamalar tercih edilir. İstemciden gelen verileri arkadaki veri tabanında işleyip sonuç üreten bir hizmet veriliyorsa mutlaka sunucu tarafında işlevsellik gerekir.

## 17. İnternet protokolleri ve katmanlar

### 17.1 Kargo benzetmesi

Mesajların internette nasıl dağılacağına protokollerle karar verilir. Hoca konuyu bir kargo örneğiyle açtı: ABD'deki bir arkadaşınıza paket göndereceksiniz. Paketi bir kargo şirketine verirsiniz; şirket onu kendi havayoluna verir; uçak Frankfurt'a, oradan New York'a, oradan batı kıyısına gider; orada yerel kargo şubesi paketi arkadaşınıza teslim eder. Slayttaki "paket gönderme örneği" şekli bunu gösterir (ekrandan, 02:30:00):

```text
Origin                    Intermediate stops            Final destination
You                                                     Friend
  | (paketi hazırlar)                                     ^ (paketi alır, açar)
Shipping company                                        Shipping company
  | (konteynere koyar)                                    ^ (konteynerden çıkarıp teslim eder)
Airline  ---------->  Airline  ---->  Airline  ---->    Airline
(uçağa yükler)        (konteyneri başka uçağa aktarır)   (konteyneri kargo şirketine yollar)
```

İnternetteki bütün mesaj trafiği de özünde bu mantıkla işler.

### 17.2 Dört katman

Sorumlulukları ve odak noktaları farklı katmanlar tanımlanmıştır. Gerçekte OSI modelinde yedi katman vardır, ama hoca dört katmanlı sadeleştirilmiş hâlini anlattı:

- **Application (uygulama) katmanı:** kullanıcı, protokole (örneğin HTTP ya da FTP) uygun olarak adresini ve mesajını oluşturur.
- **Transport (taşıma) katmanı:** protokole uygun oluşturulan mesajı paketlere böler, yani zarflara koyar.
- **Network (ağ) katmanı:** zarfın üzerine adresi yazar ve adresi okuyarak paketin hangi yolu izleyeceğini yönetir. Hoca bunu bir kargonun merkezden bölge merkezine, ilçe dağıtım merkezine ve kuryeye gitmesine benzetti.
- **Link (bağlantı) katmanı:** paketlerin fiziksel olarak nasıl gidip geleceğinin tanımlandığı ve işletildiği katman (uçağa, trene, kamyona yüklemek gibi).

Gönderen tarafta mesaj application katmanında hazırlanır, transport katmanında paketlere bölünür, network katmanında her paketin nereye gideceği işlenir ve link katmanına verilir. Ara düğümlerde paketin transport katmanına çıkmasına gerek yoktur; network katmanı yalnızca adresi okuyup "sen şuraya git" der (router örneğindeki gibi farklı yollar seçilebilir). Alıcı tarafta paketler network katmanından transport katmanına çıkar; örneğin üç pakete bölünmüş mesaj burada birleştirilir ve application katmanına orijinal mesaj olarak iletilir.

### 17.3 TCP ve UDP

Transport katmanında iki temel yaklaşım vardır: bağlantılı (güvenilir) ve bağlantısız (güvenilmez). İkisi de adresleme için IP'yi kullanır.

- **TCP (Transmission Control Protocol):** karşı tarafın varlığından emin olur; "seninle haberleşebilir miyim?" diye onay (acknowledgement) alır, ondan sonra paketleri oluşturup network katmanına verir. Bağlantılıdır ve güvenilirdir. Bir web sayfasına bağlanırken önce sunucunun var olup olmadığına bakılması buna örnektir.
- **UDP (User Datagram Protocol):** onay beklemeden paketi doğrudan gönderir; karşı tarafın olup olmamasıyla ilgilenmez. Bağlantısızdır ve güvenilmez sayılır. Yine de ağ katmanı yeterince iyiyse paketler büyük olasılıkla karşıya ulaşır.

Seçim uygulamaya bağlıdır. Güvenilirlik gerekiyorsa ve garantici davranışın getirdiği verim kaybı önemli değilse TCP kullanılır. Örneğin uzun bir e-posta altı pakete bölünmüşse, 4. ve 5. paketlerin kaybolması kabul edilemez, çünkü karşı taraf içeriği yeniden oluşturamaz. DNS sorgusu ya da VoIP'te ise önemli olan hızdır: VoIP'te bazı paketlerin düşmesi "sesin gitti" anlarına yol açar ama iletişim sürer; DNS cevabı gelmezse istek yeniden gönderilir. Bu durumlarda UDP kullanılır.

Hoca TCP'yi taahhütlü mektuba benzetti: gitmesini garanti eder ve "teslim edildi" bilgisi verir. UDP ise kapıların önüne broşür bırakan bir kuryeye benzer: alan alır, almayan almaz, kurye umursamaz; ama aynı anda çok sayıda mesajı iletmiş olur.

## 18. Ağ güvenliği

Slayttaki başlıklar (ekrandan, 02:40:00):

- **Saldırılar (attacks)**
  - Malware (virüsler, solucanlar, truva atları, casus yazılımlar, phishing yazılımları)
  - Denial of service
  - Spam
- **Korunma (protection)**
  - Firewalls
  - Spam filters
  - Proxy servers
  - Antivirus software

### 18.1 Saldırılar

Kötü niyetli yazılımlara (malicious software) **malware** denir:

- **Virüs:** amacı bir bilgisayara bulaşmak, girebildiği bütün uygulamalara kendi kodunu kopyalamak ve onlar çalıştıkça kendisi de çalışır kalmaktır. Bulaşmış bir programı başkasına gönderdiğinizde virüsü de göndermiş olursunuz. Virüs bilgisayarın içinde yayılır; ağ üzerinden yayılmak gibi bir derdi yoktur. Ağlar gelişmeden önce bile disketlerle yayılıyordu.
- **Worm (solucan):** ağ üzerinden bulaşan ve sürekli ağda yayılmaya çalışan virüs benzeri yazılım.
- **Truva atı (Trojan horse):** faydalı bir şeymiş gibi görünüp içinde zararlı yazılım barındıran program; mitolojideki hikâye gibi.
- **Casus yazılım (spyware) ve phishing yazılımları:** daha önce anlatılan tuş kaydedici örneğindeki gibi, bir "crack" programıyla birlikte kurulup fare hareketlerini, tuşları, belki ses ve kamera kayıtlarını başka yerlere gönderen yazılımlar.

**Denial of service (hizmet engelleme):** bir kurban (örneğin bir web sunucusu) seçilip çalışmaz hâle getirilir. Genellikle **DDoS (Distributed Denial of Service)** olarak yapılır: kullanıcıların farkında olmadan truva atı ya da casus yazılımla kurduğu bir program uyur, ta ki dinlediği bir porttan "şu adresin 80. portuna saniyede bin istek at" gibi bir komut gelene kadar. Sunucu örneğin saniyede on bin kullanıcıya hizmet verebiliyorken saniyede bir milyon istek gelirse isteklerle boğulur, kuyruktakilere bile cevap veremez ve gerçek kullanıcılar hizmete erişemez. Diğer saldırı türleri Bilişim Sistemleri Güvenliği dersinde görülecektir.

**Spam:** özellikle e-postayla, kötü niyetli yazılımların dağıtılması için kullanılan bir başka kapı.

### 18.2 Korunma

- Kişisel düzeyde **spam filtresi** ve **antivirüs** yazılımlarıyla korunulur.
- Ağ düzeyinde **firewall** artık olmazsa olmazdır. Yazılan ya da otomatik oluşturulan kurallara göre dış ağlardan gelebilecek tehlikelere karşı korur. Örneğin bir saldırının belirli bir bölgenin IP havuzundan geldiği anlaşılırsa o havuz bloklanır ve sunucu rahatça çalışmaya devam eder. Belirli portlar açılıp kapatılabilir, belirli uygulamalara ya da kullanıcılara izin verilebilir, trafik sınırı konabilir. Ama firewall'un da aşıldığı durumlar olabilir.
- **Proxy server (vekil sunucu):** iç sistemlerle internet arasına konan aracıdır; dışarıdan gelen bütün trafik proxy üzerinden alınır. Bir sorun olursa proxy etkilenir, bağlantı kesilir ve iç taraf korunur. Dış taraf hep proxy ile konuştuğu için içeride gerçekte kiminle konuştuğunu (yerel IP'sini, cihazın ne olduğunu) bilmez. Hoca bunu ev sahibi ile kiracının emlakçı üzerinden konuşmasına benzetti; kendisi de benzetmenin çok iyi olmadığını ekledi.

### 18.3 Şifreleme ve açık anahtar

Protokollerin neredeyse hepsinin trafiği, yani paket içeriklerini şifreleyen güvenli sürümleri vardır: dosya aktarımı için FTPS, web için HTTPS gibi. Burada genellikle **açık anahtarlı şifreleme (public key encryption)** kullanılır. İki anahtar vardır:

- **Public key (açık anahtar):** yayınlanır, herkes bilir; gönderilecek mesajı şifrelemek için kullanılır.
- **Private key (özel anahtar):** tamamen size özeldir, kimseye verilmez; size gelen şifreli mesajları bununla çözersiniz.

Slayttaki şekil (ekrandan, 02:50:00):

- Üst kısım: Alice ve Carol açık anahtara sahiptir; ikisi de Bob'a şifreli mesaj gönderebilir. Özel anahtar Bob'dadır.
- Alt kısım: Carol, Alice'in mesajını nasıl şifrelediğini bilse bile (açık anahtar elinde olsa bile) Alice'in mesajını çözemez.

Hoca bunu bir web sunucusuyla anlattı: istemciler sunucunun açık anahtarını (sertifika bilgisini) bilir ve bütün trafiği onunla şifreleyerek gönderir; sunucu kendi özel anahtarıyla iki istemcinin mesajlarını da çözüp gerçek isteği okur. Kötü niyetli Carol trafiği dinleyip paketi ele geçirse bile elindeki açık anahtarla çözemez, çünkü mesaj yalnızca özel anahtarla çözülebilir. Bu **asimetrik şifreleme** ile mesajın içeriğini yalnızca anahtar sahibinin okuyabilmesi sağlanır; HTTPS ve sertifika kontrolüyle yürüyen mesajlaşma da bu mantıkla işler. Sertifikalar ve dijital imzalar da açık anahtar mantığıyla çalışır. Hoca kripto paraların bu şekilde değil, blokzincir teknolojisiyle çalıştığını ve bunun ayrı bir konu olduğunu belirtti.

> **Ders sonrası not:** Hoca sertifika doğrulamasını "veri açık anahtarla şifrelenir, sertifika tarafı özel anahtarıyla çözebiliyorsa geçerlidir" diye anlattı. Dijital imzada yön terstir: imza özel anahtarla oluşturulur, herkes açık anahtarla doğrular. Ayrıca hoca SSH'yi "Secure Socket Shell" diye açtı ve SSL ile ilişkilendirdi; doğrusu SSH "Secure Shell"dir ve kendi şifreli protokolünü kullanır, SSL/TLS ise HTTPS ve FTPS gibi protokollerde kullanılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:47:01): Bilgisayarda 4 GB bellek var, ama o anda çalışan uygulamaların toplam ihtiyacı 8 GB. İşletim sisteminin bellek yöneticisi ne yapmalıdır?

> **Çözüm (derste verilen):** Sanal bellek (paging) kullanılır: diskte örneğin 4 GB'lık bir dosya bellek gibi kullanılır. Çalışan prosesin blokları ana bellekte tutulur, duran proseslerin blokları diske yazılır; scheduler başka bir prosesi öne aldığında bloklar yer değiştirir. Bedeli, diske taşınan verilere erişimin disk hızına inmesidir.

**Soru 2** (derste sözlü, 00:58:10): CPU okumaya ROM'dan başladığına göre neden işletim sisteminin tamamı ROM'a yazılmaz?

> **Çözüm (derste verilen):** ROM pahalı bir devredir ve kapasitesi küçüktür. Bu yüzden ROM'da yalnızca işletim sistemini diskten okuyup belleğe yükleyen küçük başlangıç kodu (boot loader) tutulur. Çok küçük işletim sistemleri kullanan bazı gömülü sistemlerde (ör. araç bilgisayarları) işletim sistemi ROM'da olabilir.

**Soru 3** (derste sözlü, 01:10:16): Yazıcının boş olduğunu öğrenen B prosesi bayrağı ayarlayamadan kesmeye uğrar; bu sırada A prosesi bayrağı boş görüp yazıcıyı alır. B kaldığı yerden devam edip yazıcıyı kullanmaya çalışırsa ne olur ve bu nasıl önlenir?

> **Çözüm (derste verilen):** Paylaşılamayan kaynak iki prosese birden verilmiş olur ve sistem çöker. Önlemek için kontrol ve ayarlama adımları bir kritik bölgede atomik olarak yapılır (ör. test-and-set); bir anda kritik bölgede yalnız bir proses bulunabilir.

**Soru 4** (ekrandan, 01:15:00): Deadlock oluşması için gereken üç koşul nedir? Yazıcı ve CD-ROM örneğinde her biri nasıl ortadan kaldırılabilir?

> **Çözüm (derste verilen):** (1) Paylaşılamayan kaynaklar için rekabet: spooling ile kaynak paylaşılıyormuş gibi gösterilir. (2) Kaynakların parça parça istenmesi: proses bütün kaynakları tek seferde ister. (3) Ayrılmış kaynağın zorla geri alınamaması: deadlock tespit edilip bir prosesin kaynağı zorla alınır ya da proses sonlandırılır.

**Soru 5** (ekrandan, 02:10:00): Noktalı ondalık gösterimdeki `193.140.4.1` adresi kaç bitliktir ve her alan hangi aralıkta değer alabilir?

> **Çözüm (derste verilen):** Dört adet 8 bitlik alandan oluşan 32 bitlik bir IPv4 adresidir; her alan 0 ile 255 arasında değer alabilir ($2^8 = 256$). IPv6 adresleri ise 128 bitliktir.

**Soru 6** (derste sözlü, 02:36:23): Uzun bir e-posta altı pakete bölünmüş ve 4. ile 5. paketler kaybolmuş olsun. Karşı taraf mesajı yeniden oluşturabilir mi? Bu uygulama için hangi taşıma protokolü seçilmelidir?

> **Çözüm (derste verilen):** Hayır; eksik paketler yüzünden içerik yeniden oluşturulamaz. Bu yüzden onay alan, güvenilir ve bağlantılı TCP kullanılır. Hızın önemli olduğu ve kaybın tolere edilebildiği DNS sorgusu ya da VoIP gibi uygulamalarda ise UDP tercih edilir.

**Soru 7** (ekrandan, 02:50:00): Carol, Alice'in Bob'a gönderdiği şifreli mesajı ele geçirir ve Bob'un açık anahtarına sahiptir. Mesajı çözebilir mi?

> **Çözüm (derste verilen):** Hayır. Açık anahtarla şifrelenmiş mesaj yalnızca eşleşen özel anahtarla çözülebilir ve özel anahtar yalnızca Bob'dadır.

## Dersin Toparlaması

Dersin ilk yarısında işletim sisteminin, donanımı kullanıcıya ve uygulamalara hizmet verir hâle getiren altyapı yazılımı olduğu görüldü. Toplu işlemeden etkileşimli işlemeye, zaman paylaşımına ve çok işlemcili makinelere uzanan tarihçe, operatörün yaptığı işlerin zamanla yazılıma devredilmesi olarak özetlendi. Yazılım uygulama ve sistem yazılımı olarak ayrıldı; işletim sisteminin kullanıcı arayüzü ve kernel'dan oluştuğu, kernel'ın dosya yöneticisi, aygıt sürücüleri, bellek yöneticisi, scheduler ve dispatcher'ı içerdiği anlatıldı. Açılış süreci, proses durumu ve kesmelerle proses değişimi, semafor ve kritik bölgeyle karşılıklı dışlama, deadlock'ın üç koşulu ve bunlara karşı çareler, son olarak şifreler ve ayrıcalıklı kip üzerinden işletim sistemi güvenliği ele alındı.

İkinci yarıda ağlar kapsama, sahipliğe ve topolojiye göre sınıflandırıldı; Ethernet'te CSMA/CD, Wi-Fi'da CSMA/CA ve gizli terminal problemi, ağları birleştiren repeater, bridge, switch ve router incelendi. Client-server ve peer-to-peer modelleri ile cluster, grid ve cloud gibi dağıtık sistemler tanıtıldı. İnternetin ISP katmanları, IP adresleme, DNS ve ICANN; e-posta, FTP, SSH, VoIP ve CDN gibi uygulamalar; HTTP, URL, HTML ve XML; dört katmanlı protokol yapısı ile TCP-UDP farkı anlatıldı. Ders, kötü niyetli yazılımlar, DDoS, firewall, proxy ve açık anahtarlı şifrelemeyle bitti. Bu ders dönemin son dersiydi; işletim sistemleri, ağlar ve güvenlik konularının ayrıntıları ilerideki İşletim Sistemleri ve Bilişim Sistemleri Güvenliği gibi derslerde görülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
