# Mobil Programlamaya Giriş Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Mobil Programlamaya Giriş
* **Hoca:** Doç. Dr. M. Amaç Güvensan
* **Dönem:** Bahar
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Mobil Teknolojilere Giriş: Hücresel Ağ Nesilleri, ARM/RISC Mimarisi, Pil Optimizasyonu | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Mobil Bilgi İşlem Bileşenleri: Mobil İletişim, Donanım, Yazılım ve İşletim Sistemleri | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Mobil Uygulama Geliştirme Yaklaşımları: Native, Cross-Platform, Hybrid, Mobile Web ve PWA | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Android Geliştirme Ortamı: JIT/AOT Derleme, ART Runtime, SDK/NDK, Cihaz Çeşitliliği | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Activity ve Fragment Kavramları: Yaşam Döngüsü, Non-Deterministic Gezinme, Modüler Geliştirme | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Intent Türleri: Explicit/Implicit Geçiş, putExtra ile Veri Taşıma, IntentFilter Manifest Bildirimi | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Liste Yapıları: RecyclerView, ListView, ViewHolder Pattern, LayoutManager Çeşitleri, Adapter Mimarisi | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Veri Saklama Yöntemleri: SharedPreferences, SQLite/Room, İç/Dış Depolama, Dosya ve Cache Yönetimi | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 12** | Sensörler: Hareket/Pozisyon/Çevresel Türler, Sensör Framework, Register/Unregister, Activity Recognition | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Arka Plan İş Yönetimi: WorkManager, AlarmManager, Foreground Service, App Standby Buckets, Doze | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Konum Tabanlı Servisler: GPS, Foreground/Background İzinler, Geofencing, FusedLocationProviderClient | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 8* (28 Nisan 2021), *Ders 10* (12 Mayıs 2021) ve *Ders 11* (19 Mayıs 2021 - 19 Mayıs Atatürk'ü Anma Gençlik ve Spor Bayramı nedeniyle ders yapılmamıştır) haftaları resmi tatil veya kayıt dışı nedenlerle işlenmemiş ya da kayıt altına alınmamıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Mobil Teknolojilere Giriş: Hücresel Ağ Nesilleri, ARM/RISC Mimarisi, Pil Optimizasyonu
* **Genel Konular:**
  - Mobil teknolojilere giriş ve mobil cihazların tarihsel gelişimi
    - Kablosuz iletişimin mobilitenin temelini oluşturduğu; ilk olarak ev içi kablosuz telefonlardan başlayan, sonra telsiz telefonlar, hücresel ağlar (GSM) ve nihayetinde 5G'ye uzanan süreç.
    - Her bir neslin (1G, 2G, 3G, 4G, 4.5G, 5G) getirdiği yenilikler; analog haberleşmeden sayısal paket iletimine, SMS'in hayatımıza girişine, GPRS, UMTS, LTE gibi teknolojilere geçiş süreci.
  - Mobil bilgi işlem (mobile computing) kavramı ve temel yapı taşları
    - Mobil bilgi işlem üç ana başlık altında incelenir: mobil iletişim (mobile communication), mobil donanım (mobile hardware), mobil yazılım (mobile software).
    - Mobil iletişim örnekleri: NFC (Near Field Communication), Bluetooth, Bluetooth Low Energy, Wi-Fi, hücresel ağlar (cellular networks) ve 5G.
    - Mobil donanımda işlemci ailesi olarak ARM mimarisi; ARM'ın RISC (Reduced Instruction Set Computing) kullandığı, Intel işlemcilerin ise CISC (Complex Instruction Set Computing) kullandığı; RISC'in daha az enerji tüketmesinin mobil cihazlarda tercih edilme sebebi olduğu.
  - Mobil cihazlarda sensör ve işlemci mimarisi optimizasyonu
    - Apple cihazlarında ana işlemciye ek olarak sensör verilerini okumak için kullanılan yardımcı işlemci (co-processor) yapısı; saniyede 100-200 defa sensör okuma ihtiyacında ana işlemciyi uyutmak için düşük enerjili bir işlemci ayrılması.
    - Android işletim sisteminin Doze (uyku) mekanizması: telefon hareketsiz kaldığında arka plan işlemlerinin sıklığını azaltarak pil tüketimini minimize etmesi.
  - Mobil uygulama geliştirmenin temel felsefesi
    - Bu dersin amacının "mobil programlama = Java = Android" denkleminden öteye geçmek olduğu; farklı işletim sistemleri, farklı programlama dilleri, farklı geliştirme yaklaşımlarının olduğu bir dünyada öğrencilere kavramsal bir çerçeve sunmak.
    - Web uygulaması, masaüstü uygulaması ve mobil uygulama geliştirme arasındaki farklar; pil kapasitesi, işlemci gücü, ekran boyutu gibi kısıtların mobil geliştirmeyi şekillendirmesi.
* **Hocanın Vurgusu:**
  - Pil kapasitesinin mobil dünyadaki her şeyin belirleyicisi olduğu
    - "Bütün hikaye bu pil kapasitesini iyi kullanmakla alakalı"; eğer telefon pilleri bir ay dayansaydı, bu kadar optimizasyonla uğraşmamıza gerek kalmayacağı.
    - Bu yüzden Doze, co-processor, RISC mimarisi gibi tüm teknolojilerin asıl sebebinin pil ömrünü uzatmak olduğu.
  - Mobil uygulama geliştirmenin "hemen kod yazalım"dan ibaret olmadığı
    - Dersin kurgusunun önce mobil dünyanın temellerini anlatmak, sonra kodlamaya geçmek olduğu; bu nedenle ilk haftalarda doğrudan Android kodlaması yapılmayacağı.
    - "Keşke daha önce başlasaydık" eleştirisine karşı hoca, bu beklentilerin ileri seviye bir "İleri Mobil Programlama" dersinde karşılanabileceğini belirtti.
  - 5G'nin kritik önem taşıdığı senaryolar
    - Otonom araçlar için 5G'nin 1 ms gecikme süresi sunmasının hayati önem taşıdığı; yüksek gecikmenin kazaya yol açabileceği.
    - 5G'nin araçtan araca iletişim (V2V) için olmazsa olmaz bir altyapı olduğu.
  - Geliştirilen uygulamanın fonksiyonel olduğu kadar görsel açıdan da kaliteli olması gerektiği
    - "Geliştirdiğiniz uygulamalar sadece fonksiyonel olmamalı, görselliği de belli oranda düzgün olmalı"; çünkü kullanıcı karmaşık bir uygulamayı görsel olarak beğenmezse kullanmıyor.
    - Ödev ve dönem projesi değerlendirmesinde görsellikten de puan alınacağı.
* **Detaylı Açıklamalar:** Dersin ilk yarısı büyük ölçüde tanışma, dersin tanıtımı, değerlendirme ölçütleri (1 sınav %20, 2-3 ödev %20, dönem projesi %20, final %40), ders içeriği haftalık planı (ilk hafta mobil teknoloji kavramı, 2. hafta mobil cihazlar ve diller, Android işletim sistemi yapı taşları, MVC/MVVM, layout ve widget'lar, aktiviteler ve intent'ler, ListView/RecyclerView, sensörler, broadcast receiver'lar, arka plan işleri, lokasyon servisleri, haritalar, Google Play Store'a yükleme) gibi örgütsel içerikten oluşmaktadır. Öğrencilerden gelen sorular Zoom kamerası açma, derslere katılım, kayıtlara erişim, Classroom kullanımı gibi konularda olmuştur. Hoca, AVESIS, YOKSIS, ARBIS, USIS, GESIS gibi platformların pandemi sürecinde yarattığı yükten de söz etmiştir. Bologna bilgi paketinde dersin 3 kredi, 5 AKTS olduğu belirtilmiştir. Dersin akademik içeriğe geçtiği ikinci bölümde mobil teknoloji kavramı ele alınmıştır. Mobilitenin aslında "mobility" kelimesinden geldiği ve kablosuz iletişim sayesinde mümkün olduğu vurgulanmıştır. Hücresel ağların gelişimi sırasıyla ele alınmış; 1G'nin analog radyo sinyalleriyle haberleşme sağladığı, cep telefonunun dijital sinyali analog sinyale dönüştürdüğü, 2G ile birlikte dijital haberleşme ve SMS'in hayatımıza girdiği, GPRS'in paket iletimini sağladığı, ardından 3G/UMTS, LTE, 4.5G ve son olarak 5G'nin geldiği anlatılmıştır. 5G'nin 2021 yılı itibarıyla belirli yerlerde kullanılmaya başlandığı ancak henüz yaygınlık kazanmadığı belirtilmiştir. 5G'nin en önemli özelliği olan 1 ms gecikme süresinin otonom araçlar için neden kritik olduğu açıklanmıştır: otonom bir aracın yüksek gecikmeyle alacağı karar ciddi bir kazaya yol açabilir. Bu nedenle araçtan araca iletişim (V2V) 5G altyapısına bağımlıdır. Mobil iletişim konusunda paket kaybı sorunlarına da değinilmiş; hareket halindeyken baz istasyonu değiştirmenin eskiden kesintilere yol açtığı, ancak günümüzde bu kesintilerin minimize edildiği belirtilmiştir. Yine de "kör noktalar"ın (blind spot) halen sorun olduğu, hücresel ağların birbiriyle kesişmediği bölgelerde bağlantı kesintileri yaşandığı vurgulanmıştır. Daha sonra mobil bilgi işlem (mobile computing) kavramının tanımı yapılmıştır. Üç temel başlık altında incelenmiştir: mobil iletişim, mobil donanım ve mobil yazılım. Mobil iletişim örnekleri olarak NFC (yakın alan iletişimi), Bluetooth, Bluetooth Low Energy, Wi-Fi ve hücresel ağlar verilmiştir. 5G üzerinde yoğun araştırma yapıldığı, mobil iletişimin araştırma alanı olarak hâlâ çok geniş olduğu belirtilmiştir. Mobil donanım konusunda işlemci ailesi olarak ARM mimarisi ele alınmıştır. ARM işlemcilerin RISC (Reduced Instruction Set Computing) kullandığı, Intel işlemcilerin ise CISC (Complex Instruction Set Computing) kullandığı açıklanmıştır. RISC'in daha az ve basit komut setine sahip olduğu için daha az enerji harcadığı, bu yüzden mobil cihazlarda tercih edildiği vurgulanmıştır. Performans açısından CISC'in bazı karmaşık hesaplamalarda daha iyi olabildiği, ancak enerji verimliliğinin mobil dünyada çok daha önemli bir kriter olduğu belirtilmiştir. Bataryanın doğrudan bilgisayar mühendisliği alanı olmadığı, ancak mobil donanımda kritik bir unsur olduğu söylenmiştir. Akıllı telefon ve akıllı saatlerde boyut ve enerji tüketiminin minimuma indirilmesi gerektiği, bu yüzden üreticilerin çeşitli çözümler geliştirdiği anlatılmıştır. Apple cihazlarının ana işlemciye ek olarak bir "co-processor" (yardımcı işlemci) kullandığı, bu yardımcı işlemcinin sensörlerden gelen verileri okumak için tasarlandığı açıklanmıştır. Saniyede 100-200 defa sensör okuma gereksinimi olduğunda ana işlemci sürekli uyanık kalmak zorunda kalmakta, bu da pil tüketimini artırmaktadır. Co-processor düşük enerjiyle bu işi üstlenir, ana işlemci sadece kritik görevler için uyanır. Yazılım tarafında ise Android'in Doze mekanizması benzer bir görevi yerine getirmektedir: telefon uzun süre hareketsiz kaldığında (ekran kapalı, cihaz sabit) arka plan sorgulama sıklığını azaltır. Örneğin WhatsApp mesajlarının sunucudan çekilme sıklığı normalde 1 saniyeyken, Doze devreye girdiğinde 30 saniye veya 1 dakikaya çıkabilir. Android 7 ile birlikte Doze daha da geliştirilmiş, makine öğrenmesi teknikleri kullanılarak cihazın gerçekten "hareketsiz" mi yoksa "yanında taşınıyor" mu olduğu daha akıllı tespit edilmeye başlanmıştır. Son olarak mobil yazılım tarafına kısaca değinilmiş; uygulamaların (applications) mobil yazılım başlığı altında incelendiği, uygulama geliştirme tekniklerinin dersin ilerleyen haftalarında detaylı olarak anlatılacağı belirtilmiştir.

### 🔹 Ders 2: Mobil Bilgi İşlem Bileşenleri: Mobil İletişim, Donanım, Yazılım ve İşletim Sistemleri
* **Genel Konular:**
  - Mobil bilgi işlem (mobile computing) kavramının detaylı tanımı
    - Mobil bilgi işlemin üç temel bileşeni: mobil iletişim (mobile communication), mobil donanım (mobile hardware) ve mobil yazılım (mobile software).
    - Mobilitenin sağlanabilmesi için cihazların "haberleşebilme yeteneğine" sahip olmasının şart olduğu; bu özelliğin mobil dünyayı masaüstü bilgisayar dünyasından ayıran temel fark olduğu.
  - Mobil iletişim teknolojileri ve protokolleri
    - NFC (Near Field Communication): yakın alan iletişimi, mobil iletişim kapsamında doğrudan bir örnek.
    - Bluetooth ve Bluetooth Low Energy: kısa mesafeli kablosuz iletişim teknolojileri.
    - Wi-Fi: kablosuz ağ bağlantısı.
    - Hücresel ağ (cellular network): 4G, 5G, GPRS gibi teknolojiler; 5G üzerine yoğun araştırma ve geliştirme faaliyetlerinin sürdüğü.
    - Uydu haberleşmesi: Mars araçları gibi fiziksel bağlantısı olmayan sistemler için uydu iletişiminin devreye girdiği; uzak mesafelerden veri aktarımı için tek alternatif olduğu.
  - Mobil donanım bileşenleri ve mimarisi
    - İşlemciler: ARM işlemci ailesinin mobil cihazlarda yaygın olarak kullanılması; ARM'ın RISC (Reduced Instruction Set Computing) mimarisini kullanması, bunun da Intel'in CISC (Complex Instruction Set Computing) mimarisine kıyasla daha az enerji tüketmesine yol açması.
    - Ekran teknolojileri: kapasitif ve rezistif ekranlar, dokunmatik ekranlar; bu alanda farklı teknolojiler üzerinde araştırmaların sürdüğü.
    - Akıllı saatler: boyut ve enerji tüketiminin minimuma indirilmesi gereken cihazlar.
    - Co-processor (yardımcı işlemci): Apple cihazlarında ana işlemciye ek olarak sensör verilerini okumak için kullanılan düşük güçlü işlemci; ana işlemciyi uyutmak ve pil ömrünü uzatmak için tasarlanmış bir yapı.
  - İşletim sistemi sınıflandırması
    - İşletim sistemi kavramı: donanım kaynaklarını yöneten temel yazılım.
    - İşletim sistemi türleri: masaüstü işletim sistemleri, sunucu işletim sistemleri, gerçek zamanlı işletim sistemleri (real time operating systems), mobil işletim sistemleri ve gömülü işletim sistemler (embedded operating systems, örn. Tizen).
    - Robotik işletim sistemi (ROS - Robotic Operating System): robotlar için özel olarak tasarlanmış işletim sistemi; her işletim sisteminin çalıştığı donanımın özelliklerine göre optimize edildiği.
    - Gömülü cihazlar (IoT): spesifik görevleri olan cihazlarda işletim sistemi ihtiyacının tartışmalı olduğu, ancak bu cihazların da zamanla birden fazla görev üstlenmesiyle küçük işletim sistemlerine ihtiyaç duyulacağı.
  - Android Doze mekanizması
    - Donanım tarafında çok çekirdekli işlemciler: 4+4 yapısında düşük güçlü çekirdekler ve yüksek performanslı çekirdekler; Android'in buna göre çekirdek yönetimi yapabildiği.
    - Yazılım tarafında Doze: telefonun hareketsiz kaldığı anları tespit ederek arka plan sorgulamalarını (WhatsApp gibi mesaj uygulamalarının sunucuyu yoklama sıklığı) azaltması; pil ömrünü korumak için geliştirilmiş yazılımsal bir çözüm.
    - Android 7 ile birlikte Doze'un makine öğrenmesi ile daha akıllı hale getirildiği: cihazın sadece hareketsiz mi yoksa yanında taşınıyor mu olduğunun tespiti.
* **Hocanın Vurgusu:**
  - Mobil dünyanın gelişiminde pil ömrünün belirleyici faktör olması
    - Co-processor ve Doze mekanizmasının asıl amacının pil ömrünü uzatmak olduğu; çekirdeklerin belli kısımlarının enerji tasarrufu amacıyla organize edilebilmesi.
    - ARM işlemcilerin RISC mimarisi sayesinde daha az enerji harcamasının, onları mobil cihazlarda vazgeçilmez kıldığı; Intel işlemcilere göre avantajının temel kaynağı.
  - Mobil iletişimin kapsamının genişliği
    - "5G alanında ciddi bir çalışma yürütülüyor" vurgusu; 5G'nin sadece hız değil, düşük gecikme ve yüksek cihaz yoğunluğu gibi birçok yenilik getirdiği.
    - Uydu haberleşmesinin bile mobil iletişim kapsamında değerlendirilebileceği; Mars araçlarından veri aktarımının fiziksel bağlantı olmadığı için bu alana girdiği.
  - İşletim sistemlerinin donanıma göre tasarlanması gerektiği
    - "Linux kernelini kullanıyorsunuz ama Linux kerneli dışındaki yetenekler..." ifadesiyle, mobil işletim sistemi tasarımında çekirdeğin ötesinde donanıma özel optimizasyonların kritik olduğu.
    - Robotik işletim sistemlerinin (ROS) robotların özel donanım yapısına göre tasarlanma zorunluluğu.
  - Mobil uygulama geliştirirken yazılım bilgisinin yanı sıra kavramsal çerçevenin de öğretilmesi
    - "Hangi niyetle neler yapıldığını" anlamanın önemli olduğu; bu yüzden ilk haftalarda kavramsal bilgilerin verildiği.
    - Her bir teknoloji alanında (mobil iletişim, donanım, yazılım) araştırma yapılıp proje alanı belirlenebileceği.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, geçen hafta mobil teknolojiler konusuna giriş yapıldığını hatırlatmış, bu hafta mobil işletim sistemleri ve mobil geliştirme yöntemlerine geçileceğini belirtmiştir. Dersin ilk bölümünde mobil bilgi işlem (mobile computing) kavramı detaylı olarak ele alınmıştır. Mobil bilgi işlemin üç temel bileşeni vurgulanmıştır: mobil iletişim (mobile communication), mobil donanım (mobile hardware) ve mobil yazılım (mobile software). Mobilitenin sağlanması için cihazların haberleşebilme yeteneğine sahip olması gerektiği, bu özelliğin mobil bilgi işlemi masaüstü bilgi işlemden ayıran temel özellik olduğu belirtilmiştir. Mobil iletişim konusunda öğrencilerle etkileşimli bir şekilde ilerlenmiştir. Bir öğrenci RESTful API ile ağ servislerine bağlanma ve veritabanından veri okuma örneği vermiş, ancak hoca bu örneğin daha çok frontend/backend operasyonlarına girdiğini belirterek daha net bir örnek olarak NFC'yi vermiştir. NFC'nin geliştirilmesinin doğrudan mobil iletişim konusunun bir parçası olduğu açıklanmıştır. Diğer örnekler olarak Bluetooth, Bluetooth Low Energy, Wi-Fi verilmiştir. Bir öğrenci 4G, 5G, GPRS'in de mobil iletişim kapsamında olup olmadığını sormuş, hoca bu teknolojilerin hepsinin hücresel ağ (cellular network) kapsamında olduğunu, özellikle 5G üzerine yoğun araştırma yürütüldüğünü belirtmiştir. Hoca, mobil iletişim alanının çok geniş olduğunu, bu yüzden dersin amaçlarını aşmamak için kısa tutulacağını söylemiştir. Bir öğrencinin Mars'taki araca yazılım yüklenmesi ve fotoğraf aktarımının mobil bilgi işlem kapsamında olup olmadığı sorusuna hoca ilginç bir cevap vermiştir: Bu tür senaryolarda fiziksel bir bağlantı olmadığı için doğal olarak mobil iletişim başlığı altında değerlendirilebileceğini, ancak koşulların farklı olduğunu belirtmiştir. Uydu haberleşmesinin (genellikle uydu iletişimi olarak adlandırılır) bu tür durumlarda devreye girdiği, Mars araçlarından veri aktarımının uydu iletişimi mantığı üzerinden ilerlediği açıklanmıştır. Bu tür çalışmaların ileride daha fazla gündemde olacağı ve daha çok alt başlık açılacağı öngörülmüştür. Mobil donanım konusunda ARM işlemci ailesinin mobil cihazlarda yaygın olarak kullanıldığı, bunun nedeninin ARM'ın RISC (Reduced Instruction Set Computing) mimarisini kullanması olduğu açıklanmıştır. Bir öğrenci ARM mimarisi, sinetron (Synopsys?) ve microcontroller örneği vermiş, ardından ARM'ın hangi instruction set'i kullandığı sorulduğunda RISC cevabı alınmıştır. Hoca, iki temel komut seti mimarisi olduğunu (RISC ve CISC) açıklamış, ARM'ın RISC kullanmasının temel avantajının daha az enerji tüketimi olduğunu vurgulamıştır. Daha temel ve basit komut seti kullandığı için enerji tüketiminin azaldığı, ancak performans açısından bazı karmaşık hesaplamalarda CISC'in bir tık daha iyi olabileceği belirtilmiştir. Bataryanın doğrudan bilgisayar mühendisliği çalışma alanı olmadığı, ancak mobil donanımda kritik bir unsur olduğu, özellikle telefonlarda pil ömrünün çok önemli olduğu söylenmiştir. Akıllı saatlerde boyut ve enerji tüketiminin minimuma indirilmesi gerektiği, bu nedenle üreticilerin çeşitli çözümler geliştirdiği anlatılmıştır. Bir öğrencinin katlanabilir ekranlar ve 5G çipleri örneğini mobil donanım alanına vermesi üzerine hoca, bu örneklerin uygun olduğunu belirtmiştir. İşlemci, bellek, SD kart gibi telefonun içindeki bileşenlerin hepsinin mobil donanım kapsamında değerlendirilebileceği, bunların geliştirilmesi üzerine yapılan çalışmaların mobil donanım başlığı altında incelenebileceği söylenmiştir. Ekran teknolojilerinde kapasitif ve rezistif ekranlar, dokunmatik ekranlar üzerine farklı araştırmaların sürdüğü belirtilmiştir. Apple'ın cihazlarında ana işlemciye ek olarak bir co-processor (yardımcı işlemci) kullandığı, bunun sensörlerden gelen verileri okumak için tasarlandığı detaylı olarak açıklanmıştır. Saniyede 100-200 defa sensör okuma gereksiniminde ana işlemci sürekli uyanık kalmak zorunda kalmakta, bu da pil tüketimini ciddi şekilde artırmaktadır. Co-processor, düşük enerjiyle sensör verilerini okur, ana işlemci sadece kritik görevler için uyanır. Telefon kapalıyken bile bu yardımcı işlemci sayesinde enerji tasarrufu sağlandığı vurgulanmıştır. Bir öğrenci cihazların birbirine daha hızlı bağlanabilmesi için bir işlemci kullanıldığını tahmin etmiş, ancak asıl amacın bu olmadığı belirtilmiştir. İşletim sistemi kavramı tanıtılmış, bir işletim sisteminin üzerinde çalıştığı donanımın kaynaklarını yöneten temel yazılım olduğu açıklanmıştır. Farklı işletim sistemi türleri sıralanmıştır: masaüstü işletim sistemleri, sunucu işletim sistemleri, gerçek zamanlı işletim sistemleri, mobil işletim sistemleri. Bir öğrenci giyilebilir araçlar için işletim sistemi örneği (Tizen) vermiş, bunun da gömülü işletim sistemi (embedded operating system) adı altında değerlendirildiği belirtilmiştir. Her cihaz için mutlaka bir işletim sistemi olmasının gerekmediği, ancak gömülü cihazların yavaş yavaş daha fazla yetenek kazanmasıyla küçük işletim sistemlerine ihtiyaç duyulacağı söylenmiştir. Bir paradoks olarak vurgulanan nokta, spesifik bir görevi olan bir cihazın neden işletim sistemine ihtiyaç duyacağıdır; cevap olarak bu cihazların birden fazla görevi yerine getirmeye başlaması gösterilmiştir. Bir öğrencinin ROS (Robotic Operating System) örneği vermesi üzerine, robotik sistemlerde çalışan işletim sistemlerinin robotların özel donanım yapısına göre tasarlandığı açıklanmıştır. Mobil işletim sistemi tasarımında Linux kernelinin kullanıldığı, ancak kernel dışındaki yeteneklerin donanıma göre şekillendiği vurgulanmıştır. Donanım tarafında çok çekirdekli işlemcilerin (4+4 yapı: 4 düşük güçlü, 4 yüksek performanslı çekirdek) kullanıldığı, Android'in bu çekirdekleri duruma göre yönetebildiği belirtilmiştir. Ancak asıl kritik noktanın yazılım tarafı olduğu, Android'in Doze mekanizması sayesinde telefonun hareketsiz kaldığı anları tespit edip arka plan sorgulamalarını azalttığı açıklanmıştır. WhatsApp gibi mesaj uygulamalarının sunucuyu yoklama sıklığı örnek verilmiş; normalde saniyede bir olan bu sıklık, Doze devreye girdiğinde yarım dakika veya dakikaya çıkabilir. Android 7 ile birlikte Doze'un makine öğrenmesi ile daha akıllı hale getirildiği, cihazın yanında taşınıp taşınmadığının tespit edilebildiği belirtilmiştir. Android kullanıcısının günlük hareket miktarının takip edilebildiği, bu sayede pil tasarrufunun optimize edildiği vurgulanmıştır.

### 🔹 Ders 3: Mobil Uygulama Geliştirme Yaklaşımları: Native, Cross-Platform, Hybrid, Mobile Web ve PWA
* **Genel Konular:**
  - Mobil uygulama geliştirme yaklaşımları ve sınıflandırılması
    - Temel geliştirme yaklaşımları: Native (yerel) geliştirme, Cross-platform (çapraz platform) geliştirme, Hybrid (melez) uygulama geliştirme, Mobile Web geliştirme ve Progressive Web App (PWA).
    - Native geliştirme: Google (Android için) ve Apple (iOS için) tarafından sağlanan Software Development Kit (SDK) kullanılarak geliştirilen yazılımlar; user experience ve user interface açısından en yüksek memnuniyeti sağlayan yöntem.
    - iOS tarafında Swift ve Objective-C ile; Android tarafında Kotlin, Java, C ve C++ ile native geliştirme yapılabilmesi.
    - Android'e özel Native Development Kit (NDK): SDK'nın yanına ek olarak Google'ın sunduğu, daha alt seviye program geliştirmeyi ve C dili ile yazmayı kolaylaştıran, özellikle gömülü sistem tarafında katkı sağlayan araç.
  - Cross-platform geliştirme araçları ve kategorileri
    - Yaygın cross-platform araçları: Flutter, Xamarin, Ionic, React Native, PhoneGap, Titanium, Appcelerator.
    - Son dönemin parlayan yıldızları: React Native ve Flutter.
    - İki kategoriye ayrım: web teknolojilerini kullananlar (React Native: JavaScript, HTML, CSS) ve web teknolojileri kullanmayanlar (Flutter: Dart, Xamarin: C#).
    - "Write once, run everywhere" (bir kere yaz, her yerde çalıştır) felsefesi; kodun farklı platformlara dönüştürülmesi.
    - Unity oyun geliştirme platformu da cross-platform olarak değerlendirilebilir.
  - Cross-platform'un avantajları ve dezavantajları
    - Avantaj: tek kod tabanı ile birden fazla platforma uygulama geliştirme; UI bileşenlerinin neredeyse native gibi üretilebilmesi.
    - Dezavantaj: cross-platform framework'ü ilgili platforma native özellikleri sağlamadıysa bazı donanım özelliklerini desteklememesi; performans, kod uzunluğu ve enerji tüketimi açısından native'e göre geri kalma potansiyeli.
    - Derleyici kalitesinin önemli olduğu; iyi bir derleyici daha iyi makine dili kodu üretir, ancak arada her zaman bir dönüştürücü katmanı vardır.
  - Hybrid uygulama geliştirme
    - Cross-platform'un altındaki bazı araçlarla hybrid app geliştirmenin mümkün olduğu.
    - Web kit üzerinde çalışan uygulamalar; container içinde paketlenerek sanki native gibi markete yüklenme.
    - Hybrid uygulamaların web ortamının güvenlik zayıflıklarına tabi olması.
  - Mobil web geliştirme
    - Bilgisayar için web uygulaması geliştirmekten tek farkı: responsive (duyarlı) tasarım.
    - Responsive tasarım: HTML5 ile yazılan uygulamanın her türlü cihazda (telefon, tablet, PC) düzgün görüntülenmesi.
    - Avantajlar: kurulum gerektirmemesi, uygulama indirme zorunluluğunun olmaması, arka planda bilgi erişimi yapılmaması.
    - Ticaret uygulamaları için en güzel örnek olduğu.
    - Dezavantaj: internet bağlantısı olmadan çalışamama.
  - Progressive Web App (PWA)
    - Mobil web geliştirmeden çok büyük farkı olmayan, modern web teknolojileriyle geliştirilen uygulamalara verilen isim.
    - HTML, CSS ve JavaScript ile geliştirilir ve bir tarayıcı üzerinden kullanılır.
    - Tüm tarayıcılarla uyumlu çalışabilen, belli standartlara uygun web uygulamaları oluşturma hedefi.
    - Responsive tasarımın ötesinde, tarayıcı farklılıklarını minimize etme amacı.
  - Geliştirme yaklaşımlarının karşılaştırılması
    - Quality of user experience (kullanıcı deneyimi kalitesi)
    - Quality of applications (uygulama kalitesi)
    - Potential users (potansiyel kullanıcı sayısı)
    - App development cost (geliştirme maliyeti)
    - Güvenlik seviyesi
    - Güncellenebilirlik
    - Desteklenebilirlik (supportability)
    - Markete ulaşma süresi (time to market)
    - Native: üstün UX, yüksek uygulama kalitesi, platforma özel kullanıcı kitlesi, yüksek maliyet, üstün güvenlik.
    - Mobile Web: orta UX, orta uygulama kalitesi, geniş kullanıcı kitlesi, düşük maliyet, tarayıcı güvenliğine bağlı.
    - Cross-platform: orta-iyi UX, orta-düşük uygulama kalitesi, geniş kullanıcı kitlesi, değişken maliyet, gelişen güvenlik.
  - Cross-platform framework tasarım kriterleri
    - Kolay kodlanabilir programlama dili
    - Çoklu mobil platform desteği
    - Zengin kullanıcı arayüzü
    - Güvenlik
    - Düşük güç tüketimi
    - Yerleşik özelliklere erişim (accessing built-in features)
    - Backend iletişim desteği
  - Frontend ve Backend kavramları
    - Frontend: kullanıcının yüz yüze olduğu, isteklerini kontrol eden ve gönderecek mesajları yöneten kısım.
    - Backend: arka planda çalışan motor, sunucu tarafı organizasyonu.
* **Hocanın Vurgusu:**
  - Cross-platform seçerken platformun iyi belirlenmesi gerektiği
    - "Hangi cross platformla çalışacağınızı iyi belirlemeniz lazım" çünkü çeşitlilik çok fazla; PhoneGap 8-9 senedir var ama artık eski kalmış.
    - Cross-platform seçimi uygulama kalitesini doğrudan etkiler.
  - Time to market kavramının yanıltıcı olabileceği
    - "Time to market" ile kastedilen geliştirme süresi değil, kullanıcılara ulaşma süresidir.
    - Cross-platform'da uygulama hem hızlı geliştirilir hem de market üzerinden doğrudan kullanıcıya ulaşır; bu büyük avantajdır.
    - Mobile web'de ise milyonlarca web sayfası arasından fark edilmek zor olduğu için kullanıcıya ulaşma zaman alır.
  - Güvenlik konusunda farkındalık
    - Native uygulamalar SDK ile garanti altına alınmış, güvenlik açısından daha iyi.
    - Browserlarda çalışan uygulamalar (mobile web ve hybrid) her zaman bir tık daha saldırıya açık.
  - Sınıf ortamında cevap verememenin notu etkileyeceği uyarısı
    - Hoca, derste soru sorduğunda cevap alamadığı öğrencilerin notlarını olumsuz etkileyeceğini açıkça belirtmiştir.
    - Sınıf mevcudunun derse aktif katılımı konusunda ısrarcı tutum takınmıştır.
  - E-ticaret uygulamalarının native tercih etme eğilimi
    - "E-ticaret firmalarının bir şekilde native tarafa da kaydığını görüyoruz son dönemde" çünkü güvenlik ve hızlı işlem yapma ihtiyacı.
    - Fiziksel mağazası olmayan firmaların ise mobile web'i tercih edebildiği; bunun prestij ve marka ihtiyacıyla ilgili olduğu.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, geçen haftanın mobil uygulama geliştirme tekniklerine ayrıldığını hatırlatmıştır. Bu hafta öğrencilere bir ödev verileceği, ancak bunun kodlama ödevi değil bir araştırma ödevi olacağı belirtilmiştir. Önümüzdeki haftadan itibaren yavaş yavaş kodlama işine geçileceği, Android Studio'nun en son sürümünün indirilebileceği, geliştirilecek API olarak Android 8.0 (API 27 civarı) belirlenebileceği söylenmiştir. Bu kurulumların önümüzdeki hafta itibarıyla konuşulacağı vurgulanmıştır. Dersin ana konusu olan mobil uygulama geliştirme yaklaşımlarına geçildiğinde önce native development tanımlanmıştır. Native development, ilgili kurumun (Google ve Apple) kendi geliştirdikleri Software Development Kit kullanılarak geliştirilen tüm yazılımları kapsar. Bu yöntemin user experience ve user interface açısından en yüksek memnuniyeti sağladığı, ilgili işletim sisteminin ve telefonun yeteneklerini en iyi kullanma alternatifi olduğu belirtilmiştir. Ancak her platform için ayrı ayrı geliştirme yapılması gerektiği, bu nedenle maliyetli olduğu söylenmiştir. iOS tarafında Swift ve Objective-C, Android tarafında ise Kotlin, Java, C ve C++ ile geliştirme yapılabileceği açıklanmıştır. Android'e özel Native Development Kit (NDK) tanıtılmış, bunun SDK'nın yanına ek olarak Google'ın sunduğu, daha alt seviye program geliştirmeyi sağlayan, C dili ile yazmayı kolaylaştıran ve özellikle gömülü sistem tarafında katkı sağlayan bir araç olduğu belirtilmiştir. Cross-platform geliştirme konusuna geçildiğinde öğrencilerden geri bildirim alınarak ilerlenmiştir. Bir öğrenci Flutter, Xamarin, Ionic saymış, başka bir öğrenci React Native'i eklemiştir. Hoca, bunların en temel bilinen cross-platform araçları olduğunu, son dönemin parlayan yıldızlarının React Native ve Flutter olduğunu belirtmiştir. PhoneGap, Titanium, Appcelerator da diğer bilinen araçlar olarak sıralanmıştır. Cross-platform araçları iki kategoriye ayrılmıştır: web teknolojilerini kullananlar (React Native: JavaScript, HTML, CSS) ve web teknolojileri kullanmayanlar (Flutter: Dart). Xamarin'in C# kullandığı, Flutter'ın Dart diliyle ön plana çıktığı ve React Native'in önemli bir rakibi olduğu vurgulanmıştır. Bir öğrencinin Unity sorusu üzerine, Unity'nin özellikle oyun geliştirme noktasında kullanıldığı ve cross-platform olarak değerlendirilebileceği, ancak ne hybrid, ne mobile, ne de native olarak tam sınıflandırılamayacağı belirtilmiştir. Cross-platform'un "Write once, run everywhere, anywhere" felsefesiyle çalıştığı, tek bir kod parçası ile birden fazla platform için geliştirme yapılabildiği açıklanmıştır. Kodun üretilmesinin arka planda çok iyi bir kütüphane ve yazılım altyapısı gerektirdiği, çünkü hem Android'e hem iOS'a çeviri yapıldığı belirtilmiştir. React Native ve Flutter'ın UI bileşenlerini neredeyse native gibi üretebildiği, eskiden cross-platform'ın en önemli sıkıntılarından biri olan bu görsel farkın artık çok azaldığı söylenmiştir. Ancak cross-platform'un bazı donanım özelliklerini framework sağlamadıysa desteklemediği, performans, kod uzunluğu ve enerji tüketimi açısından native'e göre geri kalabildiği vurgulanmıştır. Hoca bunu bir derleyici benzetmesiyle açıklamıştır: kod makina diline çevrilirken arada compiler giriyor, ne kadar iyi olursa olsun sonuçta bir dönüştürücü var ve alt seviye dile yazılsaydı daha performanslı olurdu. Performans farkı kullanıcıya yansımıyorsa (örneğin 10 ms vs 15 ms) cross-platform'un native ihtiyacını ortadan kaldırabileceği belirtilmiştir. Hybrid uygulama konusu ele alınmıştır. Cross-platform'un altındaki bazı araçlarla web kit üzerinde çalışan hybrid uygulama geliştirmenin mümkün olduğu, container içinde paketlenen uygulamanın sanki native gibi markete yüklenebildiği açıklanmıştır. Ancak web kit üzerinde çalıştığı için web ortamının güvenlik zayıflıklarına tabi olduğu, native'in SDK ile garanti altına alınmış güvenliğinin aksine browserlarda çalışan uygulamaların bir tık daha saldırıya açık olduğu vurgulanmıştır. Mobile web geliştirme, bilgisayar için web uygulaması geliştirmekten farklı bir kavram olarak ele alınmıştır. Tek farkın "responsive" (duyarlı) tasarım olduğu, bir öğrencinin bu konuyu doğru tespit etmesi üzerine açıklanmıştır. Responsive tasarımın hangi cihazda çalışıyorsa kendini o cihazın formunda görüntüleme yeteneği olduğu, HTML5 ile yazılan uygulamanın her türlü cihazdan erişilebilir hale geldiği belirtilmiştir. Mobil web'in en büyük avantajları: uygulama indirme zorunluluğunun olmaması, kurulum sırasında arka planda bilgi erişimi yapılmaması, kurulum gerektirmemesi. E-ticaret uygulamalarının bu yaklaşıma en güzel örnek olduğu söylenmiştir. Ancak native uygulama prestijinin de önemli olduğu, birçok firmanın bu nedenle native uygulama da geliştirdiği vurgulanmıştır. Dezavantaj olarak internet bağlantısı olmadan çalışamama, yani telefon üzerinde uygulamayı çalıştırma imkanı olsa bile internet olmadan işlem yapılamaması belirtilmiştir. Progressive Web App kavramı açıklanmıştır. Mobile web development'tan çok büyük bir farklılığı olmadığı, modern web teknolojileriyle geliştirilen uygulamalara verilen isim olduğu belirtilmiştir. PWA'nın tüm tarayıcılarla uyumlu çalışabilen, belli standartlara uygun web uygulamaları oluşturma hedefinde olduğu, responsive tasarımın ötesinde tarayıcı farklılıklarını minimize etme amacı taşıdığı vurgulanmıştır. Bir öğrencinin "progressive" kelimesinin neden kullanıldığı sorusuna hoca, ileri derece anlamında responsive tasarımın ötesine geçildiğini, tüm browserlarla uyumlu çalışma hedefinin ifade edildiğini söylemiştir. Geliştirme yaklaşımlarını karşılaştırmak için kullanılan kriterler hoca tarafından öğrencilere sorularak belirlenmiştir. Bir öğrenci hız ve erişim, başka bir öğrenci platformlar ve güvenlik/optimizasyon, bir başkası markete dağıtım süreleri ve geliştirme maliyetleri, user experience demiştir. Hoca bu kriterleri derleyerek şu listeyi oluşturmuştur: Quality of user experience, Quality of applications, Potential users, App development cost, Güvenlik düzeyi, Güncellenebilirlik, Supportability (desteklenebilirlik), Markete ulaşma süresi (time to market). Bu kriterler üç yaklaşım (Native, Mobile Web, Cross-platform) için doldurulmuştur. Native'in UX açısından "excellent", Mobile Web'in "tatminkar" (responsive ve progressiv design ile), Cross-platform'ın "very good" (eskiden "not as good as native apps" denirdi ama artık çok tatminkar deneyimler elde ediliyor) olduğu belirtilmiştir. Time to market kavramının özellikle vurgulanması dikkat çekicidir: hoca, "time to market" ifadesinin geliştirme süresi değil, kullanıcılara ulaşma süresi olduğunu açıkça belirtmiştir. Cross-platform'da uygulama hem hızlı geliştirilir hem de markete konduğu için tek noktadan ulaşılabilir; mobile web'de ise milyonlarca web sayfası arasından fark edilmek zor olduğu için Google aramalarında ön plana çıkmak zaman alır. Hoca, dersin ilerleyen bölümlerinde bir cross-platform framework tasarımı için nelere dikkat edilmesi gerektiğini sormuştur. Öğrencilerden gelen cevaplar: kolay kodlanabilir programlama dili, çoklu mobil platform desteği (responsive değil, multiple platform support), zengin UI, güvenlik, düşük enerji tüketimi, native özelliklere erişim (night mode, sensör verisi, kamera) şeklinde olmuştur. Backend iletişim desteği de eklenmiştir. Frontend ve backend kavramları kısaca açıklanmıştır.

### 🔹 Ders 4: Android Geliştirme Ortamı: JIT/AOT Derleme, ART Runtime, SDK/NDK, Cihaz Çeşitliliği
* **Genel Konular:**
  - Araştırma ödevi gereksinimleri
    - IEEE formatında 4-8 sayfa arası makale hazırlanması.
    - Ana konu: mobil kullanıcı deneyimi (mobile user experience); hangi faktörlerin önemli olduğu, neden kritik olduğu, iOS ve Android farklılıkları.
    - Mobile uygulama geliştirme konseptleri; karşılaştırmalı tablolar ve şekiller kullanılması.
    - Hikaye anlatımı (beginning-middle-end) önemli; sadece bilgi yığmak değil, akış oluşturmak gerekiyor.
    - Kaynakça (bibliyografi) zorunlu; sadece internet siteleri değil akademik makaleler de kullanılmalı.
    - Scholar Google kullanımı; üniversite kütüphanesi üzerinden IEEE, Springer, Elsevier, ACM gibi veritabanlarına erişim.
  - JIT (Just-In-Time) ve AOT (Ahead-Of-Time) derleme kavramları
    - JIT: uygulama başlatıldığında, kullanılmadan hemen önce derlenmesi; her açılışta compile edilmesi gerektiği.
    - AOT: uygulama kurulduğunda bir kez derlenmesi, sonraki açılışlarda tekrar derlenmemesi.
    - AOT'un avantajı: zamandan tasarruf (her açılışta compile edilmediği için).
    - AOT'un dezavantajı: platform değişikliklerinde uyumsuzluk yaşanabilmesi, hata ile karşılaşma riski, disk alanı kullanımı.
    - Google ve Android'in her ikisinin kombinasyonunu kullandığı; Dalvik Virtual Machine yerine artık Android Runtime (ART) environment'ı kullanıldığı.
    - ART'ta Java veya Kotlin ile geliştirilen kodlar bir sanal işlemci üzerinde çalışır, oradan makine kodu üretilir.
  - Android cihaz çeşitliliği
    - Android Studio yüklendiğinde geliştirme yapılabilecek cihaz türleri: akıllı telefon, tablet, akıllı saat (smart watch), Android Auto (arabalar için), Android Things (IoT cihazları), televizyonlar.
    - Her cihaz türünün farklı arayüz önerileri ve arka plan kütüphaneleri olduğu.
    - Proje açarken hangi ortam için geliştirileceğinin kritik bir karar olduğu.
  - Android uygulama geliştirme gereksinimleri
    - Android SDK: uygulama geliştirmek için gerekli.
    - JDK (Java Development Kit) ve JRE (Java Runtime Environment): native development için gerekli.
    - NDK (Native Development Kit): alt seviye geliştirme (C/C++ ile) için gerekli, ama zorunlu değil.
    - Bilgisayar: Linux, macOS veya Windows işletim sistemi.
    - Emülatör veya Android cihaz: test ve çalıştırma için.
    - IDE: Android Studio (IntelliJ IDEA altyapısına dayalı, 2013'ten beri); Android uygulama geliştirmek için olmazsa olmaz seçeneklerden biri.
    - Android Studio dışında cross-platform araçları da kullanılabilir; "Android uygulama geliştirmek" ile "native Android uygulama geliştirmek" kavramları farklıdır.
    - Donanım gereksinimleri: en az 4 GB RAM (8 GB önerilir), belirli disk alanı (4 GB civarı).
* **Hocanın Vurgusu:**
  - Araştırma ödevi için copy-paste yapılmaması gerektiği
    - "Copy paste mantığıyla değil, okuduklarınızı belirli bir süzgeçten geçirerek aktarmanız"; bazı temel bilgiler kullanılabilir ama hikaye size ait olmalı.
    - İngilizce yazıp bir yerden copy paste alındığı düşünülen ödevin notunun sıfır olacağı; Türkçe yazmanın bu riski azaltacağı.
    - Şekil ve tablo kullanımının desteklendiği; anlatım dilinin önemli olduğu, hikayenin başı-sonu-gelişmesi olması gerektiği.
  - API level uyumunun önemi
    - Farklı API level'larında farklı sıkıntılar çıkabileceği; hocanın belirlediği API level'a uyulması gerektiği.
    - Önümüzdeki haftadan itibaren Android Studio kurulumu ve API level'ın konuşulacağı.
  - ART (Android Runtime) ile gelen performans kazanımı
    - JIT ve AOT kombinasyonu sayesinde Android'in performans avantajı elde ettiği; Dalvik VM'in yerini ART'ın aldığı.
    - Java veya Kotlin kodunun bir sanal işlemci üzerinde çalışıp oradan makine kodu üretilmesi süreci.
  - Derse aktif katılımın önemi
    - Sorulara cevap veremeyen öğrencilerin notlarının olumsuz etkileneceği uyarısı.
    - Sınıfta söz alarak düşüncelerin paylaşılması gerektiği.
  - Bilgisayar mühendisliğinin farklı alanlarında uzmanlaşmanın önemi
    - Bilgisayar mühendislerinin sadece kod yazmak yerine farklı alanlarda da yetkin olması gerektiği.
    - Android uygulama geliştirmenin sadece kod yazmaktan ibaret olmadığı, kavramsal bilginin de önemli olduğu.
* **Detaylı Açıklamalar:** Dersin başlangıcında araştırma ödevi hakkında detaylı bilgi verilmiştir. Ödevin IEEE formatında 4-8 sayfa arasında bir makale olarak hazırlanması beklendiği, dökümanda belirli başlıklar önerildiği ancak bunların zorunlu olmadığı, hatta kendi belirlenecek başlıklarla hareket etmenin daha iyi olacağı belirtilmiştir. Çünkü herkesin konuyu farklı bir hale getirebileceği, temelde mobile user experience konusunda hangi önemli faktörlerin olduğu ve neden bu konunun kritik olduğunun anlatılması gerektiği söylenmiştir. iOS ve Android tarafındaki farklılıklara da değinilebileceği, mobile uygulama geliştirme konseptleri özelinde farklı bakış açılarının incelenebileceği belirtilmiştir. Şekil ve tablo kullanımının özellikle desteklendiği, anlatım dilinin önemli olduğu, hikayenin bir başı ve sonu olması gerektiği vurgulanmıştır. Kaynakça bölümünün olmazsa olmaz olduğu, sadece internet sitelerinin değil akademik makalelerin de kullanılması gerektiği, Scholar Google kullanımının öğrenilmesi gerektiği, üniversite kütüphanesi üzerinden IEEE, Springer, Elsevier, ACM gibi veritabanlarına erişim sağlanabileceği anlatılmıştır. Hoca, son hafta sonuna bırakılmaması gerektiğini, hafta sonu itibarıyla arama işinin başlatılması gerektiğini ısrarla vurgulamıştır. Dersin ana konusuna, yani Android'e ve geliştirme ortamına geçildiğinde ilk olarak JIT (Just-In-Time) ve AOT (Ahead-Of-Time) derleme kavramları işlenmiştir. JIT'de uygulamanın başlatıldığı anda, kullanılmadan hemen önce derlendiği ve her açılışta bu derleme sürecinin tekrarlandığı açıklanmıştır. AOT'da ise uygulamanın kurulduğu anda bir kez derlendiği, sonraki açılışlarda tekrar derlenmesine gerek kalmadığı belirtilmiştir. AOT'un performans açısından zaman kazancı sağladığı, her seferinde compile edilmediği için hızlı açıldığı söylenmiştir. Ancak AOT'un bazı dezavantajları da vurgulanmıştır: platformda değişiklikler olduğunda önceden derlenmiş versiyonla uyumsuzluk çıkabilir, hata ile karşılaşılabilir ve disk alanı açısından daha fazla yer kaplayabilir. Google ve Android'in her iki yaklaşımın kombinasyonunu kullandığı, Dalvik Virtual Machine yerine artık Android Runtime (ART) environment'ının kullanıldığı belirtilmiştir. ART'ta Java veya Kotlin ile geliştirilen kodların bir sanal işlemci üzerinde çalıştığı, oradan makine kodu üretilerek dönüşümün sağlandığı açıklanmıştır. Android Studio yüklendiğinde geliştirme yapılabilecek cihaz türleri öğrencilerle birlikte listelenmiştir. Akıllı telefon, tablet, akıllı saat, Android Auto (arabalar için), Android Things (IoT cihazları için), televizyonlar bu cihaz türleri arasında sayılmıştır. Her bir cihaz türünün farklı arayüz önerileri ve arka planda farklı kütüphaneler kullandığı, proje açarken hangi ortam için geliştirileceğinin kritik bir karar olduğu vurgulanmıştır. Android uygulama geliştirme gereksinimleri detaylı olarak ele alınmıştır. Android SDK'nın uygulama geliştirme için gerekli olduğu, JDK ve JRE'nin native development için gerekli olduğu belirtilmiştir. NDK'nın (Native Development Kit) alt seviye geliştirme (C/C++ ile) için gerekli olduğu ancak zorunlu olmadığı, sadece belirli durumlarda gerektiği söylenmiştir. Bilgisayar tarafında Linux, macOS veya Windows işletim sistemi kullanılabileceği, her biri için uygun yazılımların indirilmesi gerektiği belirtilmiştir. Emülatör veya Android cihazın test ve çalıştırma için gerekli olduğu vurgulanmıştır. IDE olarak Android Studio'nun olmazsa olmaz seçeneklerden biri olduğu, IntelliJ IDEA altyapısına dayalı olduğu ve 2013'ten beri kullanıldığı belirtilmiştir. Android Studio dışında cross-platform araçlarıyla da Android uygulaması geliştirilebileceği, ancak "Android uygulama geliştirmek" ile "native Android uygulama geliştirmek" kavramlarının farklı olduğu vurgulanmıştır. Donanım gereksinimleri olarak en az 4 GB RAM (8 GB önerilen), belirli bir disk alanı (yaklaşık 4 GB) gerektiği belirtilmiştir.

### 🔹 Ders 5: Activity ve Fragment Kavramları: Yaşam Döngüsü, Non-Deterministic Gezinme, Modüler Geliştirme
* **Genel Konular:**
  - Activity kavramı
    - Android tarafında en önemli bileşen olan Activity; uygulamaya giriş noktası.
    - Bir activity'ye farklı noktalardan ulaşılabilmesi; sadece uygulamaya girip değil, uygulamanın içindeki farklı activity'lere başka activity'ler üzerinden de erişim sağlanabilmesi.
    - Her activity'nin kendi içerisinde belli yetenekleri barındıran, en küçük parça (atom parçası) olarak düşünülebilecek bir bileşen olması.
    - Örnek: bir uygulamadan mail gönderilmek istendiğinde, mail gönderme işini yapabilen başka bir uygulamanın activity'sine yönlendirme yapılması.
  - Activity'lerin non-deterministic (belirsiz) yapısı
    - Telefondaki activity'ler arasındaki gezinmenin belli bir yolu olmaması; desktop tarafında genelde belli rotalar üzerinden ilerlenirken ve aynı uygulama içinde kalınırken, mobilde uygulamalar arası geçiş yapılabilir.
    - Bir uygulamadan başka bir uygulamaya iş paslanıp, o iş yapıldıktan sonra kaldığınız uygulamaya geri dönülebilmesi.
    - Bu nedenle activity'lerin yaşam döngüsünün (lifecycle) yönetiminin önemli olduğu.
  - Fragment kavramı
    - Bir activity'nin ikiye bölünüp birbirinden bağımsız iki işin aynı aktivite içinde yönetilmesi ihtiyacından doğan yapı.
    - Örnek: bir fragment'ta e-postaların listelendiği, diğer fragment'ta seçilen e-postanın görüntülendiği senaryo.
    - Activity bir process olarak düşünülürse, fragment bir thread olarak düşünülebilir.
    - Her uygulamanın bir main activity'si vardır; C'deki main fonksiyonu gibi düşünülebilir.
* **Hocanın Vurgusu:**
  - Bilgisayar mühendisliğinde farklı alanlarda uzmanlaşmanın önemi
    - 2000'li yıllarda sadece kod yazarak (PHP, HTML) başarı elde edilebilirken, 2010'larda basit bir mobil uygulama ile ciddi gelir elde edilebileceği.
    - Günümüzde makine öğrenmesi, veri madenciliği, yapay zeka konularında bilgi sahibi olmanın fark yarattığı.
    - Yeni dönemin şartlarına uygun bilgisayar mühendisliği alt dallarında kariyer planlamasının önerilmesi.
  - Hobi ve aktivitenin sağlık üzerindeki etkisi
    - Uzun süre bilgisayar başında kalmanın sağlık açısından sorunlu olduğu; hareket etmenin önemli olduğu.
    - Bilgisayar mühendislerinin genel hayatlarının bilgisayar başında geçtiği gerçeği; bunu telafi etmek için aktivite eklenmesi gerektiği.
  - Online çalışmanın olumlu ve olumsuz yanları
    - Yolda zaman kaybetmemenin büyük avantaj olduğu.
    - Günde 10 saat bilgisayar başında olmanın verimi azalttığı; ortam değişikliğinin olmamasının motivasyonu düşürdüğü.
    - Online iş yapmanın güvenilirliğinin artması (pandemi sonrası).
    - Gece/gündüz kavramının kalkması, yükün artması.
  - Modüler kod geliştirmenin dersin temel felsefesi olması
    - Her hafta bir özellik eklenecek, bir yapı kurulacak, üzerine başka şeyler eklenerek ilerlenecek.
    - Login mekanizmasıyla başlanıp, login ekranı tasarlandıktan sonra başka ekranlara geçileceği.
    - Ders sırasında gerçekleştirilen faaliyetlerin zamandan tasarruf ve öğrenme kolaylığı sağlayacağı.
  - Hocaların "kötü polis" rolü
    - Pandemide otokontrol mekanizmasının herkeste iyi çalışmadığı için hocaların bu rolü üstlendiği.
    - Öğrencilere kulak verildiği, iletişim kurmaktan çekinmemeleri gerektiği.
* **Detaylı Açıklamalar:** Dersin ilk büyük bölümü pandemi sürecinin öğrenciler üzerindeki psikolojik etkisi, uzaktan eğitim deneyimleri ve online çalışmanın getirdiği zorluklar üzerine bir sohbet şeklinde geçmiştir. Öğrenciler, online eğitimin yolda zaman kaybetmeme gibi avantajları olduğunu, ancak günde neredeyse 10 saat bilgisayar başında kalmak zorunda kaldıklarını, bu durumun verimi azalttığını, ortam değişikliğinin olmamasının motivasyon ve performans düşüklüğüne yol açtığını paylaşmışlardır. Hoca, bu durumun uzun vadede sağlık açısından sıkıntılara yol açabileceğini, özellikle bilgisayar mühendislerinin zaten genel hayatlarının bilgisayar başında geçtiğini, her koşulda hayata bir hareket katmanın faydalı olduğunu vurgulamıştır. Açık havada vakit geçirmek, iki-üç arkadaşla uzaktan ve gerekli önlemler alınmış açık hava buluşmaları düzenlemenin iyi geldiği belirtilmiştir. Online iş yapmanın güvenilirliğinin pandemi sonrasında arttığı, birçok şirketin tamamen online çalıştığı, fiziksel mekana gitmeden de işlerin yürütülebildiği, ancak bunun yükü artırdığı, gece-gündüz kavramının kalktığı, sekizde toplantı yapabilme gibi durumların oluştuğu paylaşılmıştır. Hoca, bu konuda bir paradoks yaşandığını (çok ödev verilmeyen derslerde ödev vermeye başlayınca öğrencilerin isyan etmesi) belirtmiş, vites düşürmeye çalıştıklarını, orta yolu bulmaya çalıştıklarını söylemiştir. "Kayıp nesil olmamanız için" ifadesini kullanarak, bilgisayar başında sizi sıkıntıya sokan durumların sizin iyiliğinize uzun vadede olduğunu vurgulamıştır. Otokontrol mekanizmasının herkeste iyi çalışmadığını, bu yüzden hocaların "kötü polis" rolünü üstlendiğini, ancak her zaman kulak verdiklerini ve iletişim kurmaktan çekinmemeleri gerektiğini belirtmiştir. Dersin akademik içeriğe geçtiği bölümde, hoca ilk dört haftadaki mobil dünya konularının detayına merak eden öğrenciler için araştırma konuları bulmalarını önermiştir. Bilgisayar mühendisliğinin farklı ihtiyaçlara cevap vermesi gerektiği, 2000'li yıllarda kod yazarak başarı elde edilirken, 2010'larda basit mobil uygulamalarla ciddi gelir sağlandığı, günümüzde makine öğrenmesi, veri madenciliği, yapay zeka konularında bilgi sahibi olmanın fark yarattığı vurgulanmıştır. Yeni dönemin şartlarına uygun bilgisayar mühendisliği alt dallarında kariyer planlaması yapmanın uzun vadede yüksek ücretler ve pozisyonlar anlamına geleceği söylenmiştir. Bu haftadan itibaren kodlamaya geçileceği belirtilmiştir. Önce slide'larla başlanacağı, arkasından Android Studio'nun açılacağı, bir telefon bağlantısının USB üzerinden ekrana yansıtılacağı, hangi uygulamanın kullanılabileceğinin anlatılacağı, Android Studio içindeki yeteneklerin tanıtılacağı belirtilmiştir. Dersin ilk bölümünde konu anlatımı, ikinci bölümünde o konuyla ilgili küçük bir uygulama parçası geliştirileceği açıklanmıştır. Android bileşenlerinden en önemlisinin Activity olduğu, bunun uygulamaya giriş noktası olduğu belirtilmiştir. Bir activity'ye farklı noktalardan ulaşılabileceği, sadece uygulamaya girip değil, uygulamanın içindeki farklı activity'lere başka activity'ler üzerinden de erişim sağlanabileceği açıklanmıştır. Örnek olarak, bir uygulamadan mail gönderilmek istendiğinde, mail gönderme işini yapabilen başka bir uygulamanın activity'sine yönlendirme yapılması verilmiştir. Her activity'nin kendi içerisinde belli yetenekleri barındıran, uygulamadaki en küçük parça (atom parçası) olarak düşünülebilecek bir bileşen olduğu vurgulanmıştır. Activity'lerin non-deterministic yapısı detaylı olarak açıklanmıştır. Telefondaki activity'ler arasındaki gezinmenin belli bir yolu olmaması, desktop tarafında genelde belli rotalar üzerinden ilerlenip aynı uygulama içinde kalınırken, mobilde uygulamalar arası geçiş yapılabilmesi, hatta bir uygulamadan başka bir uygulamaya iş paslanıp o iş yapıldıktan sonra kaldığınız uygulamaya geri dönülebilmesi örnekleri verilmiştir. Bu nedenle non-deterministic bir hikayeden bahsedildiği, her uygulamanın birden fazla ekran içerebileceği belirtilmiştir. Aynı anda bir activity'nin yetmediği durumlarda, activity'nin ikiye bölünüp Fragment kavramının kullanıldığı açıklanmıştır. Birbirinden bağımsız iki işin aynı aktivite içinde yönetilebildiği Fragment yapısı, e-postaları listeleme ve seçilen e-postayı görüntüleme örneğiyle somutlaştırılmıştır. Activity process, fragment thread benzeri yapılar olarak kavramsallaştırılmıştır. Her uygulamanın bir main activity'si olduğu, C'deki main fonksiyonu gibi düşünülmesi gerektiği vurgulanmıştır. Dersin kod felsefesi açıklanmıştır: Ders sırasında gerçekleştirilecek faaliyetler, bir hafta bir özellik ekleyip bir yapı kurup, arkasından onun üzerine başka şeyler ekleyerek ilerleme şeklinde olacaktır. Örneğin login mekanizmasıyla başlanacak, login giriş ekranı tasarlanacak, sonra başka bir ekrana geçilecektir. Bunlar daha sonra ödev olarak alınma potansiyeli taşımaktadır. Bu yüzden ders sırasında gerçekleştirilen faaliyetlerin zamandan tasarruf ve öğrenme kolaylığı sağlayacağı belirtilmiştir.

### 🔹 Ders 6: Intent Türleri: Explicit/Implicit Geçiş, putExtra ile Veri Taşıma, IntentFilter Manifest Bildirimi
* **Genel Konular:**
  - Intent kavramı ve temel tanımı
    - Intent bileşeni, bir activity'den başka bir activity'ye geçiş sırasında bu görevi gerçekleştiren bileşendir.
    - Intent'lerle hem gidilmek istenen aktivite belirtilir hem de yapılmak istenen iş belirtilerek sisteme uygun aktiviteler listeletilebilir.
    - Kendi uygulaması içinde aktiviteler arasında gezmeyi sağladığı gibi bir uygulamadan başka bir uygulamaya geçerek o andaki işi yapabilmesi.
  - İki tip intent
    - Explicit Intent (Açık Intent): doğrudan işi yapacak aktivitenin veya ait olduğu paketleme isminin belirtildiği; hedefin net olarak gösterildiği intent türü.
    - Implicit Intent (Örtük Intent): yapılmak istenen işin ne olduğunun belirtildiği, bunu yapabilecek uygulamaların sistemden talep edildiği intent türü.
    - Explicit intent uygulama içerisinde kalır, implicit intent sistem seviyesine kadar çıkar; bu yüzden explicit intent performans açısından daha önemlidir.
    - Bir web adresinin gösterilmesi veya bir numaranın aranması implicit intent örnekleridir; sistem uygun uygulamaları (Chrome, Firefox, telefon uygulaması) listeler.
  - Intent özellikleri ve metodları
    - Explicit intent'te genelde target'ın component name field'ının set edilmesi beklenir.
    - Implicit intent'te component name field'ı boş bırakılmalı, sadece hangi aksiyonun alınacağı eklenmelidir.
    - Önemli metodlar: setComponent, setType, putExtra, setData, setAction.
    - Birden fazla bilgi göndermek için ArrayList yapısı kullanılabilir; URI bilgisi intent'in constructor'ına aktarılır.
    - putExtra metodu: intent'in içine bilgi yerleştirmek için kullanılır; her aksiyona ait sabitler (EXTRA_EMAIL, EXTRA_SUBJECT gibi) vardır.
  - Intent karşılama (handle) süreci
    - Bir intent oluşturulduğunda karşı tarafın bu intenti alması gerekir.
    - Alabilme yolu: setContentView'dan sonra getIntent metodu ile gelen intent'i alacak kodun yazılması.
    - İçeriğin kontrol edilip (resim mi, metin mi vb.) uygun aksiyonun kodlanması gerekir.
    - Bu kod yazılmazsa intent discard edilir, aktivite sadece kodlanmış işi yapar.
  - startActivity vs startActivityForResult
    - Çağrılan activity'den bilgi alınacaksa startActivityForResult metodu kullanılır.
    - Sadece bilgi gönderilecekse ve alınmayacaksa startActivity yeterlidir.
    - AndroidX ile birlikte startActivityForResult yerine daha çok önerilen yeni API'ler gelmiştir (AndroidX activity 1.2.0.alpha.02, Fragment 1.3.0).
  - IntentFilter ve manifest bildirimi
    - Kendi uygulamasının belirli işleri yapabilmesi için Android Manifest'te intent filter olarak gömülmesi gerekir.
    - Bu sayede işletim sistemi uygulamanın hangi yeteneklere sahip olduğunu bilir ve diğer uygulamaların talepleri karşısında uygulamayı listeleyebilir.
    - Email client, web browser, harita, sosyal medya uygulamaları hep bu yapıyı kullanır.
    - Data kısıtlaması ile belirli domainlere yönlendirme gibi durumlar yönetilebilir; action bazında değil, kategori bazında filtreleme yapılabilir.
  - onActivityResult metodu
    - startActivityForResult ile başlatılan aktiviteden geri dönüldüğünde çağrılan metot.
    - Request code, result code ve intent bilgisi parametre olarak gelir.
    - Request code: gönderilen isteği tanımlayan kod (birden fazla istek arasında ayrım için).
    - Result code: işlemin gerçekleştirilip gerçekleştirilmediğini belirten kod (RESULT_OK, RESULT_CANCELLED).
    - Result ok ise cursor üzerinden gelen veri alınır ve kullanılır.
  - Chooser (Seçici) kullanımı
    - Implicit intent'te sistem "Just once" / "Always" seçenekleri sunar.
    - "Always" seçilirse hep aynı uygulama açılır; her seferinde sormak için chooser oluşturulabilir.
    - intent.createChooser ile chooser oluşturulur.
    - Implicit intent'te uygulama seçimini filtrelemek (örneğin Chrome'u gizlemek) mümkün değildir; bu işletim sistemi tarafından organize edilir.
  - Performans ipuçları
    - Bir karşılayan yoksa intent başarısız olur; bu yüzden package manager üzerinden queryIntentActivities çağrılarak dönen size sıfırdan büyük mü kontrol edilmelidir.
    - Aksi halde kullanıcıya bilgilendirme yapılmalıdır, yoksa hata mesajı alınır.
* **Hocanın Vurgusu:**
  - Explicit intent'in performans açısından tercih edilmesi gerektiği
    - "Doğrudan bir hedefiniz varsa onun için implicit intent tanımlamalısınız" ifadesiyle, eğer hedef belli ise system seviyesine çıkıp tekrar inmeye gerek olmadığı vurgulanmıştır.
    - Explicit intent uygulama içerisinde kaldığı için daha performanslıdır.
  - IntentFilter'ın Android geliştirmedeki kritik rolü
    - Kendi uygulamasının yeteneklerini manifest'te intent filter olarak gömmek, uygulamanın diğer uygulamalar tarafından keşfedilebilirliği için şarttır.
    - WhatsApp, Signal gibi uygulamaların "instant mesaj gönder" yeteneği bu şekilde tanımlanır.
  - Yeni API'lerin kullanımı konusunda farkındalık
    - AndroidX ile birlikte startActivityForResult'un yerini yeni API'ler almıştır.
    - Eski API'ler hâlâ desteklense de, yeni projelerde AndroidX activity 1.2.0.alpha.02 ve Fragment 1.3.0 API'lerinin tercih edilmesi gerektiği.
  - Code paylaşımı ve akademik dürüstlük konusunda ders genelinde vurgulanan tutum
    - Ödevlerde birebir paylaşımın notun sıfırlanmasına yol açacağı, bu konuda çok sert yaptırımlar uygulanabileceği.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, artık hızlı gitmeleri gerektiğini, 3-4 keçe gibi başlayacaklarını belirtmiştir. Zoom'da mikrofon ve kameranın default kapalı olması için ayar önerilmiştir (Ayarlar > Video/Audio > "Toplantıya katılırken mikrofonumu kapat" ve "videomu durdur"). Her hafta bir-iki kişinin istenmeyen ses yayınına yol açtığı, bu ayarın bir kez yapılmasının yeterli olduğu vurgulanmıştır. Geçen haftanın ödevi hatırlatılmıştır: Bir login ekranı tasarlanmış, kişi üç defa yanlış giriş yaptığında login butonunun disable olması implement edilmişti. Hemen arkasında bir sign up ekranı yazılacak, intent ile ilgili bilgiler öğrenilip kayıtlar görülecekti. Yarım saat sonra yapılacak uygulama ile ilgili bilgi verilmiştir: Android aktiviteleri üzerinden quiz/sınav soruları oluşturulacak, bir soru girişi yapılacak, şıklar oluşturulacak, doğru şık işaretlenip kaydedilecektir. Bir ekran bunu yapmayı sağlayacak, başka bir ekran soruları görmeyi sağlayacaktır. Bu bir alıştırma olarak yapılacak, daha sonra ödev olarak istenebileceği belirtilmiştir. Intent kavramı detaylı olarak anlatılmıştır. Uygulamalar arası ve aktiviteler arası geçiş için gerekli olan bu bileşen, hem bilgi taşımak hem de bir butona tıklandığında yeni bir aktiviteye geçmek istendiğinde kullanılır. İki tip intent olduğu belirtilmiştir: Explicit intent ve Implicit intent. Explicit intent'te doğrudan o işi yapacak aktivitenin veya ait olduğu paketleme isminin belirtildiği, hedefin net gösterildiği vurgulanmıştır. Implicit intent'te ise yapılmak istenen işin ne olduğunun belirtildiği, bunu yapabilecek neler varsa sistemden talep edildiği açıklanmıştır. Örnek olarak bir haritada adres gösterilecekse ActionView, bir numara aranacaksa ActionDial, bir web adresi gösterilecekse ActionView kullanıldığı belirtilmiştir. Implicit intent'te browser'lar arasından seçim yapılabileceği (Chrome, Safari, Firefox, Explorer) vurgulanmıştır. Performans açısından explicit intent'in daha avantajlı olduğu, çünkü uygulama içerisinde kalıp sistem seviyesine çıkıp tekrar aşağı inmeye gerek olmadığı vurgulanmıştır. Explicit intent'te target'ın component name field'ının set edilmesi gerektiği, bu ya package özelinde ya da doğrudan class ismi verilerek yapıldığı belirtilmiştir. Implicit intent'te ise component name field'ının boş bırakılması, sadece hangi aksiyonun alınacağının eklenmesi gerektiği söylenmiştir. Intent'in oluşturulması ve bilgi taşıma yöntemleri açıklanmıştır. Constructor'a aksiyon ve bilgi eklenebileceği, URI üzerinden bilgi parse edilip intent'e aktarıldığı belirtilmiştir. Bir email intent'i oluşturulurken ActionSend kullanıldığı, bu bilgiyi gönderebilecek uygulamalarla ilgilenildiği, uygulamaların Android manifestlerinde intent filter olarak yeteneklerini dekler ettikleri için işletim sisteminin hangi uygulamaların bunu yapabileceğini bildiği açıklanmıştır. Tip belirleme, to/subject gibi bilgileri putExtra metoduyla aktarma yöntemi anlatılmıştır. Birden fazla bilgi (örneğin birden fazla kişi ismi) göndermek için ArrayList yapısının kullanılabileceği belirtilmiştir. startActivityForResult ve onActivityResult detaylı olarak ele alınmıştır. Bir activity'ye gidip oradan bilgi alarak geri dönmek için startActivityForResult metodu çağrılır. startActivityForResult sonrası onActivityResult metodu tanımlanmalıdır. Bu metoda requestCode, resultCode ve intent parametreleri gelir. Request code öğrenciye verilmiş bir kod, result code ise karşı tarafın verdiği koddur. Result code RESULT_OK, RESULT_CANCELLED gibi değerler alabilir. Result ok ise cursor üzerinden gelen veri alınır, content provider kullanıldığında cursor yapısı kullanılır. Chooser (seçici) kavramı açıklanmıştır. Implicit intent'te sistem "Just once" / "Always" seçenekleri sunar. Always seçilirse hep aynı uygulama açılır. Her seferinde sormak için chooser oluşturulur, intent.createChooser ile yapılır. Bu sayede Just once ve Always seçeneği devre dışı bırakılmış olur. Ancak bir uygulamayı listeden filtrelemenin (örneğin Chrome'u gizlemek) mümkün olmadığı, bu işlemin işletim sistemi tarafından organize edildiği belirtilmiştir. IntentFilter ve manifest bildirimi detaylı olarak anlatılmıştır. Kendi uygulamasının belirli işleri yapabilmesi için Android Manifest'te intent filter olarak gömülmesi gerektiği, bu sayede işletim sisteminin uygulamanın hangi yeteneklere sahip olduğunu bilmesi ve diğer uygulamaların talepleri karşısında uygulamayı listeleyebilmesi açıklanmıştır. Email client, harita, web browser, sosyal medya uygulamalarının hepsinin bu yapıyı kullandığı belirtilmiştir. Action bazında değil, kategori (data) bazında filtreleme yapılabileceği, örneğin sadece text gönderme yeteneği tanımlanırsa resim gönderilmek istendiğinde uygulamanın bunu yapmayacağı vurgulanmıştır. Hoca, login ekranından başarı giriş sonrası menü ekranına geçiş örneği vererek Explicit intent kullanımını somutlaştırmıştır. Intent'in o andaki context'i (bulunulan activity) alıp hedef activity'nin ismini (package.ClassName formatında) yazdığını açıklamıştır. putExtra ile UserID gibi bilgiler eklendiğini, bu bilgilerin yeni ekranda "Hoş geldiniz X kişisi" gibi mesajlar için kullanılabileceğini belirtmiştir. Eğer 3 defa hatalı giriş yapılırsa toast mesajıyla kullanıcıya bilgi verildiğini ve finish ile uygulamanın destroy edildiğini (ödev kapsamında), ya da butonun disable edileceğini söylemiştir.

### 🔹 Ders 7: Liste Yapıları: RecyclerView, ListView, ViewHolder Pattern, LayoutManager Çeşitleri, Adapter Mimarisi
* **Genel Konular:**
  - Sınav bilgilendirmesi
    - Sınav haftasının bir sonraki hafta olduğu, dersin sınavının programa göre cuma günü yapılacağı.
    - Sınav formatı: klasik sınavdan öte, şıklı sorular veya boşluk doldurma tarzında olacağı; belki küçük bir kod parçasında boşluk doldurma olabileceği.
    - Belirli bir terminolojide kullanılan ifadenin bilinmesi ve açıklamasının karşılığında ne olduğuna dair yazılması isteneceği.
    - Bilgi ezberi beklenmediği, sürenin çok uzun olmayacağı belirtilmiştir.
    - Sınava hazırlanmak için developer.android.com üzerinden ilgili chapter'ların okunması önerilmiş, ek farklı bilgi veren siteler de kullanılabileceği belirtilmiştir.
    - Sınavda Dependency, Gradle, RecyclerView vs ListView farkı, aktivite tipleri, aktiviteler arası gezinme komponenti, bilgi taşıma gibi temel konuların sorulacağı.
  - Liste yapıları: ListView, GridView, RecyclerView, ScrollView
    - ListView: en çok kullanılan yapı ancak son 4-5 senede yerini RecyclerView'a bırakmıştır.
    - RecyclerView'ın daha fazla özellik sunması ve performans artırma noktasında ciddi katkılar sağlaması.
  - ListView vs RecyclerView temel farkları
    - ListView'da tüm item'lar aynı anda telefon üzerine yüklenir; bu yükleme sırasında belli bir bekleme süresine neden olur.
    - RecyclerView'da ise aşağı kaydırıldıkça item'lar yüklenir; bin item'dan on tanesini gösteriyorsanız bir sonraki on tanenin henüz çekilmemiş olması anlamına gelir.
    - RecyclerView, recycling (geri dönüşüm) mantığını kullanarak eski item view'u çöpe atmayıp yeni gelen item için kaynak olarak kullanır; büyük performans ve kaynak farkı yaratır.
    - Hem verinin görsel olarak sunulmasında hem de RAM ve pil tüketiminde avantaj sağlar.
  - ViewHolder pattern
    - ListView ve RecyclerView'in her ikisinin de kullanabildiği bir pattern.
    - RecyclerView'da ViewHolder pattern'i zorunludur; ListView'da opsiyoneldir.
    - ListView'da ViewHolder pattern'i kullanılırsa performans önemli ölçüde RecyclerView'a yaklaşır, ancak RecyclerView hâlâ daha iyi performans gösterir.
    - ListView'da standart yapıyla ViewHolder kullanılmazsa ciddi kullanıcı memnuniyetsizliği ve kaynak tüketimi sorunu ortaya çıkar.
  - LayoutManager kavramı
    - ListView'da sadece dikeyde bir view oluşturma şansı vardır; başka bir opsiyonu yoktur.
    - RecyclerView'da üç farklı layout kullanma opsiyonu vardır: Linear Layout Manager (yatay ve dikey), Grid Layout Manager (galeri uygulamaları için ideal), Staggered Layout Manager (Pinterest benzeri, farklı boyutlarda item düzeni için).
  - Item dekorasyonu ve animasyonu
    - ListView bu konuda oldukça zayıftır; opsiyonel olarak sunmamasının ötesinde customize etme imkanı da vermez.
    - RecyclerView'da item animator ve item decoration ile farklı item'lar tasarlanabilir ve anime edilebilir.
    - Karmaşıklık: animation ve decoration işine girildiğinde belli oranda efor harcanması gerekir.
  - OnItemTouchListener
    - RecyclerView'da bulunan özellik; onClickListener'dan farklı yetenekler sunar.
    - Tek tip click işlemi yerine touch işleminde birden fazla touch tipini destekleyen listener ile item üzerinde farklı aksiyonlar tanımlanabilir.
  - setHasFixedSize metodu
    - RecyclerView'da performans iyileştirme metodu.
    - Eğer item'ların sayısı belli ve değişmezse (örneğin 200 ülke × 100 şehir = 20.000 item) kullanılır.
    - Bu sayede RecyclerView her seferinde aynı pozisyonu alacağı için daha iyi kaynak planlaması yapılır ve cache mekanizması oluşturulur.
  - Ne zaman ListView, ne zaman RecyclerView?
    - Çok basit yapılar (Türkiye'nin 81 ili gibi) ve animasyon ihtiyacı olmayan durumlarda ListView + ViewHolder yeterlidir.
    - Daha karmaşık, animasyon/dekorasyon istenen, büyük veri setleri için RecyclerView tercih edilmelidir.
  - RecyclerView ile liste yaratma adımları
    - XML içinde RecyclerView tanımlanır; dependencies'e com.android.support:recyclerview eklenmelidir.
    - Java tarafında: RecyclerView bileşeni, Adapter ve LayoutManager tanımlanır.
    - setContentView ile bağlama, findViewById ile ilişkilendirme yapılır.
    - setHasFixedSize, setLayoutManager, setAdapter çağrıları yapılır.
  - Adapter kavramı
    - View (ön yüz) ile data source arasındaki veri akışını sağlayan parça.
    - RecyclerView Adapter'ı kullanılır; kendi tarafınızdan extend edilerek yazılır.
    - Controller ile karıştırılmamalıdır: Controller tüm işlemleri yönetir, Adapter sadece verinin view'a aktarımını sağlar.
  - Adapter'ın temel metotları
    - onCreateViewHolder: her item için bir ViewHolder üretir; LayoutInflater.from.inflate ile yeni bir item görüntüsü oluşturulur.
    - onBindViewHolder: oluşturulan view'un içine data source'dan gelen veriyi position'a göre set eder.
    - getItemCount: data set uzunluğunu döndürür.
  - MyViewHolder sınıfı
    - RecyclerView.ViewHolder'ı extend ederek oluşturulur.
    - Her item'ın görsel bileşenlerini (TextView, ImageView, Button vb.) barındırır.
    - findViewById ile XML'deki view'lar holder'a atanır.
  - ViewHolder'ın dinamik oluşumu
    - "Creates only as many ViewHolders as are needed to display on screen portion of the dynamic content" ifadesiyle, RecyclerView sadece ekranda görünen kadar ViewHolder oluşturur.
    - Scroll edildikçe ekranın dışına çıkan item'ların ViewHolder'ları yeni gelen item'lar tarafından yeniden kullanılır.
* **Hocanın Vurgusu:**
  - ViewHolder pattern'inin kritikliği
    - "ListView'un en büyük sıkıntısı ViewHolder'ı opsiyonel yapmasıdır" vurgusu; eğer kullanılmazsa ciddi performans düşüklüğü yaşanır.
    - Performans farkı sadece teorik değil, pratikte de gözlemlenebilir.
  - Dependency'lerin eklenmesinin zorunluluğu
    - RecyclerView'ı kullanabilmek için dependencies bölümüne com.android.support:recyclerview-version-7 versiyonunun eklenmesi gerektiği; eklenmezse hata alınacağı.
  - Core Android programlamanın derste tamamen öğretilemeyeceği
    - "Core Android programlamayı derste öğretmek gibi bir amacımız yok"; 3 saatlik haftalık dersle her sene değişen package yapısına sahip ortamda her şeyi öğretmek zor.
    - Amaç, temel bilgileri vermek ve ileride ilgi duyanların kullanmasını sağlamak.
  - Adapter ve Controller farkı
    - Öğrencilerin adapter ile controller'ı karıştırması üzerine hoca, bunların farklı kavramlar olduğunu açıkça belirtmiştir: Controller arka plan veri modeli ile ön yüz arasındaki tüm işlemleri yöneten kod, Adapter ise sadece RecyclerView/ListView'e özel veri aktarımını sağlayan yapı.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, mikrofonların kapatılmasını hatırlatmış, sınav haftasının bir sonraki hafta olduğunu ve başarılar dilediğini belirtmiştir. Sınavın cuma günü yapılacağı, sınavın şıklı sorular ve boşluk doldurma tarzında olacağı, küçük bir kod parçasında boşluk doldurma olabileceği, belirli bir terminolojide kullanılan ifadenin bilinmesinin isteneceği söylenmiştir. Bilgi ezberi beklenmediği, çok uzun süren bir sınav olmayacağı belirtilmiştir. Sınavdan sonra ikinci ödevin verileceği, bu ödevin o sırada geliştirilen uygulamayla ilgili olacağı ve muhtemelen bir hafta-10 gün içinde teslim edileceği açıklanmıştır. Sınava hazırlanmak için developer.android.com üzerinden ilgili chapter'ların okunması, dependencies, gradle, RecyclerView vs ListView farkı, aktivite tipleri, aktiviteler arası gezinme komponenti, bilgi taşıma gibi konulara çalışılması önerilmiştir. Hoca, Core Android programlamanın derste tamamen öğretilemeyeceğini, 3 saatlik haftalık dersle her şeyin öğrenilemeyeceğini, amaçlarının kritik bilgileri vermek ve ileride ilgi duyanların kullanmasını sağlamak olduğunu vurgulamıştır. Slide'ların cuma gününe kadar paylaşılacağı, bunların developer.android.com'dan toplanmış seçmece slide'lar olduğu söylenmiştir. Dersin ana konusuna, yani liste yapılarına geçildiğinde ilk olarak ListView, GridView, RecyclerView ve ScrollView tanıtılmıştır. ListView'ın en çok kullanılan yapı olduğu ancak son 4-5 senede yerini RecyclerView'a bıraktığı, bunun pek çok nedeni olduğu belirtilmiştir. RecyclerView'ın daha fazla özellik sunması ve performans artırma noktasında ciddi katkılar sağlaması temel nedenlerdir. ListView ve RecyclerView arasındaki temel fark bir öğrenci tarafından doğru bir şekilde açıklanmıştır: ListView'da bin kişilik bir listeden bahsedildiğinde, tüm item'lar aktivite açıldığı anda yüklenir; RecyclerView'da ise aşağıya kaydırıldıkça item'lar yüklenir. Hoca bunu onaylamış, ekranda gösterilen on item'ın yüklendiğini, bir sonraki on item'ın henüz çekilmemiş olduğunu belirtmiştir. RecyclerView adından da anlaşılacağı üzere item'ları aşağı doğru ilerledikçe bazı item'lar ekranın görüntüsünden çıktığında, bu item view'lar sonraki view'lara geçildiğinde yeni gelen item'lar tarafından tekrar kullanılabilir. Bu recycling (geri dönüşüm) mantığı kaynak ve performans farkı yaratır; hem user experience (verinin görsel olarak sunulması) hem de kaynak tüketimi (RAM, pil) açısından büyük avantaj sağlar. ViewHolder pattern açıklanmıştır. Her iki liste yapısının da kullanabildiği bu pattern, RecyclerView'da zorunlu, ListView'da opsiyoneldir. ListView'da ViewHolder pattern'i kullanılırsa performans önemli ölçüde RecyclerView'a yaklaşır, ancak RecyclerView hâlâ daha iyi performans gösterir. ListView'da ViewHolder kullanılmazsa ciddi kullanıcı memnuniyetsizliği ve kaynak tüketimi sorunu ortaya çıkar. Hoca, ViewHolder opsiyonelliğinin ListView'un en büyük sıkıntısı olduğunu vurgulamıştır. LayoutManager kavramı detaylı olarak ele alınmıştır. ListView'da sadece dikeyde bir view oluşturma şansı varken, RecyclerView'da üç farklı layout kullanma opsiyonu vardır: Linear Layout Manager (hem yatay hem dikey), Grid Layout Manager (galeri uygulamaları için ideal, resimler arasında hızlı ilerleme), Staggered Layout Manager (Pinterest benzeri, farklı boyutlarda item düzeni). Windows Phone'un tile management yapısına yakın bir yapı sunduğu, farklı görünümlerle kullanma şansı verdiği belirtilmiştir. Item dekorasyonu ve animasyonu açısından ListView'ın oldukça zayıf olduğu, opsiyonel olarak sunmamasının ötesinde customize etme imkanı da vermediği, RecyclerView'da ise item animator ve item decoration ile farklı item'lar tasarlanıp anime edilebileceği belirtilmiştir. Bu konunun karmaşıklığı da vurgulanmış, animation ve decoration işine girildiğinde belli oranda efor harcanması gerektiği söylenmiştir. OnItemTouchListener özelliği RecyclerView'a özel olarak tanıtılmıştır. Tek tip click işlemi yerine touch işleminde birden fazla touch tipini destekleyen listener ile item üzerinde farklı aksiyonlar tanımlanabilir. setHasFixedSize metodu ise item sayısı belli ve değişmezse kullanılır; örneğin dünyadaki 200 ülke ve her ülkedeki 100 şehir (toplam 20.000 item) gibi. Bu sayede RecyclerView her seferinde aynı pozisyonu alacağı için daha iyi kaynak planlaması yapılır ve cache mekanizması oluşturulur. Hoca, "her an RecyclerView kullanılmalı mı" sorusuna da cevap vermiştir: Hayır. Çok basit durumlar (İstanbul, Ankara, İzmir, tüm Türkiye'nin şehirleri gibi), animasyon ihtiyacı olmayan, kompleks bir yapı oluşturulmayacak durumlarda basit bir ListView yeterlidir. Önemli olan ListView'da ViewHolder pattern'inin kullanılmasıdır. RecyclerView ile liste yaratma adımları kod üzerinden açıklanmıştır. XML'de RecyclerView tanımlanır ve dependencies'e com.android.support:recyclerview-version-7 versiyonu eklenmelidir. Java tarafında RecyclerView bileşeni, Adapter ve LayoutManager tanımlanır. setContentView ile bağlama, findViewById ile ilişkilendirme, setHasFixedSize, setLayoutManager ve setAdapter çağrıları yapılır. Adapter kavramı detaylı olarak açıklanmıştır: view (ön yüz) ile data source arasındaki veri akışını sağlayan parça. Hoca, adapter ile controller kavramlarını ayırmıştır: Controller tüm işlemleri (veri çekme, işleme, ön yüze aktarma) yönetir, Adapter ise sadece RecyclerView/ListView'e özel verinin view'a aktarımını sağlar. Bir öğrencinin "controller adapter mı oluyor" sorusuna hoca, MVC'deki controller'ın tüm işlemleri yöneten kod, adapter'ın ise sadece veri aktarımını sağlayan yapı olduğunu açıkça belirtmiştir. Adapter'ın temel metotları açıklanmıştır. onCreateViewHolder her item için bir ViewHolder üretir; LayoutInflater.from.inflate ile yeni bir item görüntüsü oluşturulur, burada item'ın dış kıyafeti XML dosyasıyla temsil edilir. onBindViewHolder oluşturulan view'un içine data source'dan gelen veriyi position'a göre set eder. getItemCount ise data set uzunluğunu döndürür. Bir öğrencinin "onCreateViewHolder içinde farklı tiplerde yapılar oluşturmak istersem nasıl tutarım" sorusuna hoca, eğer gerçekten farklı tipler gerekirse iki ayrı RecyclerView konulabileceğini, çünkü aynı RecyclerView içinde tüm item'ların aynı yapıda olması gerektiğini söylemiştir. ViewHolder'ın dinamik oluşumu konusunda bir öğrencinin sorusu üzerine, "Creates only as many ViewHolders as are needed to display on screen portion of the dynamic content" ifadesi açıklanmıştır. RecyclerView sadece ekranda görünen kadar ViewHolder oluşturur, scroll edildikçe ekranın dışına çıkan item'ların ViewHolder'ları yeni gelen item'lar tarafından yeniden kullanılır. Bu temel prensibin dinamik bir şekilde gerçekleştiği vurgulanmıştır.

### 🔹 Ders 9: Veri Saklama Yöntemleri: SharedPreferences, SQLite/Room, İç/Dış Depolama, Dosya ve Cache Yönetimi
* **Genel Konular:**
  - İkinci ödev gereksinimleri
    - Kullanıcı giriş ekranı ve kullanıcı kayıt ekranı gereksinimi; başarılı aksiyonlarda mesajlarla bilgilendirme.
    - Kayıt ekranından alınacak bilgiler, şifrelerin eşleşmemesi durumunda hata mesajı.
    - Aynı kullanıcı adının sistemde var olması durumunda hata mesajı.
    - Kullanıcı bilgilerini kalıcı alana taşıma: SQLite veya dosya yapısı (artık ArrayList yeterli değil).
    - Menü ekranı: soru ekle, soru listele, sınav oluştur, sınav ayarları gibi faaliyetler (farklı tasarımlar kabul edilir; tab, floating action button, action bar vb.).
    - Soru ekleme ekranı: 5 şık, doğru cevap, resim/ses/video eklenebilme.
    - Soru listeleme ekranı (RecyclerView): soruları silme, tıklayarak güncelleme; silme sırasında dialog box ile emin misiniz sorusu.
    - Sınav ayar ekranı: sınav süresi, soru puanı, zorluk düzeyi (2-5 arası) gibi bilgileri SharedPreferences ile saklama.
    - Zorluk düzeyi 2 olduğunda 2 şık (1 doğru, 1 yanlış), düzey 5 olduğunda 5 şık.
    - Sınav oluşturma ekranı: ayarları değiştirebilme, oluşturulan sınavı metin formatında kaydetme.
    - WhatsApp/Signal gibi mesajlaşma uygulaması üzerinden paylaşabilecek kod üretme.
    - Teslim: kaynak kodları + APK dosyası GitHub'a, 3-5 dakikalık YouTube videosu, PDF (link içeren) Online Yıldız'a.
    - UI puanı: tutarlı, dengeli, hızlıca her şey yerleştirilmiş olmayan, planlı arayüzler bekleniyor; yeni UI bileşenleri kullanmak ekstra puan.
  - Veri saklama yöntemleri
    - Dört temel veri saklama yöntemi:
      1. App-specific storage (uygulamaya özel depolama): dahili ve harici bellek olmak üzere iki türlü.
      2. Shared storage: video, fotoğraf, ses, belge gibi paylaşılabilir içerikler.
      3. Preferences: uygulama ayarları, oyun ayarları gibi key-value formatında basit veriler.
      4. Veritabanı: yapılandırılmış, ilişkisel veri (SQLite + Room library, Firebase).
    - Lokalde vs network/cloud'da veri saklama seçenekleri.
  - App-specific storage detayları
    - getFilesDir (kalıcı bilgiler) ve getCacheDir (geçici bilgiler) dizinleri.
    - Harici bellek karşılığı: getExternalFilesDir ve getExternalCacheDir.
    - Uygulama kaldırıldığında app-specific dosyalar otomatik olarak silinir.
    - Shared storage: MediaStore API (medya dosyaları) ve Storage Access Framework (diğer dosyalar).
    - İzinler: READ_EXTERNAL_STORAGE, WRITE_EXTERNAL_STORAGE, MANAGE_EXTERNAL_STORAGE.
    - Android 10 ve 11 ile gelen Scoped Storage; belli bölgelere erişim yeteneği kazandırma.
    - Android 10 ile gelen internal storage'daki tüm verilerin şifrelenmesi özelliği.
  - SharedPreferences
    - Primitif verileri (int, long, float, boolean) ve string'i key-value şeklinde saklar.
    - Uygulama kaldırıldığında shared preferences dosyaları da silinir.
    - Diğer uygulamalar tarafından erişilemez (güvenli alan).
    - Tek bir veya birden fazla shared preferences dosyası oluşturulabilir.
    - getSharedPreferences veya Activity'nin kendi getPreferences metodu kullanılabilir.
  - SQLite ve Room
    - Yapılandırılmış, ilişkisel veriler için internal storage'da veritabanı.
    - En alt katmanda SQLite, üst katmanda Room library ile erişim kolaylığı.
    - Room, SQLite'ın verimli kullanımını sağlar.
  - Internal vs External storage
    - Internal storage sürekli erişilebilir; external storage fiziksel olarak orada olduğu sürece erişilebilir.
    - Internal storage'da harici alan yaratma imkanı vardır (fiziksel SD card olmak zorunda değil).
    - USB olarak Android telefon USB storage olarak enable edildiğinde external storage ile çalışan uygulamalar bloklanır ve kapatılır (telefon hard drive moduna geçer).
    - external storage'a yüklenen uygulamaların APK'sı orada olsa da, uygulamaya özel dosyalar internal storage'da bulunur.
    - Manifest'te installLocation özelliği ile uygulamanın external'a mı yoksa internal'a mı kurulacağı belirlenebilir (preferExternal, auto).
  - Dosya okuma/yazma işlemleri
    - getFileStream: file objesi üzerinden dosya oluşturma.
    - openFileOutput metodu: context üzerinden doğrudan dosyaya erişim.
    - FileOutputStream (yazma), FileInputStream (okuma).
    - write, close, flash metotları.
    - flash: verilerin senkron olarak storage'a yazılmasını sağlar; çağrılmazsa asenkron olarak uygun zamanda yazılır.
    - Try-catch mekanizması: dosya yok, açılamaz gibi durumlar nedeniyle zorunlu.
    - StreamReader ile satır satır okuma.
  - Cache kullanımı
    - Cache dizini: sonradan silinmesi sorun yaratmayacak, kalıcı olması gerekmeyen dosyalar için.
    - İnternetten indirilen yüksek boyutlu dosyalar işlendikten sonra cache'de tutulabilir.
    - İşletim sistemi bellek yetersiz kaldığında cache dizinlerini otomatik temizler (garbage collector kadar sık değil).
    - Normal dizinlerde tek tek dosya kontrolü gerekir, cache'de toplu silme yapılabilir.
  - Content Provider
    - Uygulamalar arası veri paylaşımı için kullanılan yapı.
    - Rehber uygulaması, SMS mesajları gibi paylaşımlı verilere erişim sağlar.
    - Cursor yapısı ile veri okuma.
  - Firebase
    - Google'ın cloud tabanlı veri saklama çözümü.
    - Karmaşık olmayan yapısı sayesinde verilerin sunucuda saklanması, uygulama yükünün azaltılması, veri kaybı riskinin minimize edilmesi.
    - Lokalde veri saklamak ve network üzerinde/cloud'da veri saklamak seçenekleri.
* **Hocanın Vurgusu:**
  - Veri saklama seçiminde sorulması gereken kritik sorular
    - Ne kadarlık bir alana ihtiyaç var?
    - Verinin güvenlik seviyesi ne olmalı?
    - Veri özel mi yoksa paylaşılabilir mi?
    - Paylaşılabilir içerik ise shared storage, gizli ise internal storage + preferences + veritabanı + dosya.
    - Büyük boyuttaki oyun gibi veriler external storage'da saklanır.
  - USB bağlantısı sırasında external storage uygulamalarının bloklanması
    - "Aklınızdan çıkarmayın" vurgusu; telefon USB'ye bağlandığında hard drive moduna geçer ve external storage uygulamaları kapatılır.
    - Bu durum sıklıkla göz ardı edilir ve uygulama beklenmedik şekilde kapanır.
  - Cache kullanımının pil ömrüne etkisi
    - Cache dizinlerinin temizlenme sıklığı, dosya kontrolü yapmaya gerek olmaması pil ömrü için önemli.
    - Telefon açılıp kapatıldığında cache temizlenmesi konusunda kesin bilgisi olmadığını belirtmiştir.
  - Kodun kendiniz tarafından yazılmasının önemi
    - SQLite'ı anlatmamış olsa da bilen arkadaşların kullanmasına izin verdiği, ama bilmeyenler için zorunlu olmadığı.
    - Yapılan işin "kendiniz tarafından yapılmış olması"nın kritik olduğu; bir yerden alındıysa puan olarak değerlendirilmeyeceği.
  - GitHub'da ödevin paylaşım zamanlaması
    - Teslim tarihinden önce public paylaşım yapılmaması gerektiği; kötüye kullanım riski.
    - Teslimden bir gün sonra private'ı public'e çevirme önerisi.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, sınav haftasının bittiğini, geçmiş olsun dileklerini iletmiştir. Sınav hakkında bir öğrenci sürenin az geldiğini, başka bir öğrenci soruların zor olmadığını belirtmiştir. Hoca final sınavında bir tık daha süreyi uzatma şansı olabileceğini söylemiştir. İkinci ödev detaylı olarak anlatılmıştır. Ödevin tüm konuları kapsadığı, kullanıcı giriş/kayıt ekranı, menü ekranı, soru ekleme/listeleme, sınav ayar ekranı, sınav oluşturma ekranı gibi ekranlar içerdiği belirtilmiştir. Artık kullanıcı bilgilerinin kalıcı alana taşınması gerektiği (SQLite veya dosya), ArrayList'in yeterli olmadığı vurgulanmıştır. Soru ekleme ekranında 5 şık, doğru cevap, resim/ses/video eklenebilme özelliği; soru listeleme ekranında RecyclerView ile silme/güncelleme (silme sırasında dialog box ile onay); sınav ayar ekranında SharedPreferences ile süre/puan/zorluk düzeyi (2-5) saklama; sınav oluşturma ekranında metin formatında kaydetme ve mesajlaşma uygulaması üzerinden paylaşma özellikleri istenmiştir. Teslim şekli: kaynak kodları ve APK GitHub'a, 3-5 dakikalık YouTube videosu (kendini tanıtma + uygulamayı anlatma + neler yapılamadığını söyleme), PDF (link içeren) Online Yıldız Teknik Üniversitesi'ne yüklenecektir. Süre önümüzdeki hafta çarşamba gece yarısına kadardır. Hoca, ödevi teslim ederken dikkat edilmesi gereken önemli bir noktayı vurgulamıştır: GitHub'da ödevin teslim süresinden önce public şekilde paylaşılmaması gerektiği, aksi halde kötüye kullanılabileceği, ödevi teslim ettikten bir gün sonra private'ı public'e çevrilebileceği belirtilmiştir. UI puanı konusunda beklenti: tutarlı, dengeli, hızlıca her şeyin yerleştirilmediği, planlı arayüzler; yeni UI bileşenleri kullanmak ekstra puan kazandıracaktır. Dersin ana konusuna, yani veri saklama yöntemlerine geçildiğinde dört temel yöntem tanıtılmıştır. App-specific storage (uygulamaya özel depolama) iki türlü olabilir: dahili bellek (internal storage) ve harici bellek (external storage). Shared storage ile video, fotoğraf, ses ve diğer belge türleri saklanabilir. Preferences ise uygulama ve oyun ayarları gibi basit primitif verileri key-value şeklinde saklar. Veritabanı (SQLite + Room) yapılandırılmış, ilişkisel veriler için kullanılır. Firebase ise cloud tabanlı veri saklama çözümüdür. Hoca, ne tür veri saklama yönteminin kullanılacağına karar vermek için şu soruların sorulması gerektiğini vurgulamıştır: ne kadarlık bir alana ihtiyaç var, verinin güvenlik seviyesi ne olmalı, veri özel mi yoksa paylaşılabilir mi. Paylaşılabilir içerik için shared storage, gizli veri için internal storage + preferences + veritabanı + dosya yapısı, büyük boyuttaki oyun gibi kritik olmayan veriler için external storage tercih edilmelidir. App-specific storage detaylı olarak açıklanmıştır. Internal storage'da getFilesDir (kalıcı bilgiler) ve getCacheDir (geçici bilgiler) dizinleri kullanılır. Harici bellek karşılığı ise getExternalFilesDir ve getExternalCacheDir'dir. App-specific dosyalar uygulama kaldırıldığında otomatik olarak silinir. Shared storage MediaStore API (medya dosyaları) ve Storage Access Framework (diğer dosyalar) üzerinden erişilebilir. İzinler: READ_EXTERNAL_STORAGE, WRITE_EXTERNAL_STORAGE ve Android 11 ile eklenen MANAGE_EXTERNAL_STORAGE. Android 10 ve 11 ile gelen Scoped Storage; belli bölgelere erişim yeteneği kazandırma, dosya bazında genel yönetim imkanı. Android 10 ile gelen internal storage'daki tüm verilerin şifrelenmesi özelliği, security seviyesini artırmıştır. Internal ve external storage arasındaki fark vurgulanmıştır. Internal storage sürekli erişilebilir, external storage fiziksel olarak orada olduğu sürece erişilebilir. Internal storage'da harici alan yaratma imkanı vardır; fiziksel SD card olmak zorunda değildir, bazı firmalar internal storage üzerinde external bir alan yaratma imkanı verir. USB olarak Android telefon USB storage olarak enable edildiğinde external storage ile çalışan uygulamalar bloklanır ve kapatılır (telefon hard drive moduna geçer). Bu durumun "akıldan çıkarılmaması" gerektiği ısrarla vurgulanmıştır. External storage'a yüklenen uygulamaların APK'sı orada olsa da, uygulamaya özel dosyalar internal storage'da bulunur. Manifest'te installLocation özelliği ile uygulamanın external'a mı yoksa internal'a mı kurulacağı belirlenebilir (preferExternal, auto). SharedPreferences kavramı açıklanmıştır. Primitif verileri (int, long, float, boolean) ve string'i key-value şeklinde saklar. XML dosyası kullanarak SharedPreferences API üzerinden bilgileri saklama imkanı vardır. Uygulama kaldırıldığında shared preferences dosyaları da silinir. Diğer uygulamalar tarafından erişilemez (güvenli alan). Tek bir veya birden fazla shared preferences dosyası oluşturulabilir. getSharedPreferences veya Activity'nin kendi getPreferences metodu kullanılabilir. SQLite ve Room kavramı açıklanmıştır. Yapılandırılmış, ilişkisel veriler için internal storage'da veritabanı kullanılır. En alt katmanda SQLite, üst katmanda Room library ile erişim kolaylığı sağlanır. Room, SQLite'ın verimli kullanımını sağlar. Hoca, SQLite'ı anlatmamış olsa da bilen arkadaşların kullanmasına izin verdiğini, ama bilmeyenler için zorunlu olmadığını belirtmiştir. Dosya formatında saklama da kabul edilecektir. Yapılan işin "kendiniz tarafından yapılmış olması"nın kritik olduğu, bir yerden alındıysa puan olarak değerlendirilmeyeceği vurgulanmıştır. Dosya okuma/yazma işlemleri kod üzerinden açıklanmıştır. getFileStream file objesi üzerinden dosya oluşturma, openFileOutput metodu context üzerinden doğrudan dosyaya erişim imkanı sağlar. FileOutputStream yazma, FileInputStream okuma için kullanılır. write, close, flash metotları mevcuttur. flash verilerin senkron olarak storage'a yazılmasını sağlar; çağrılmazsa asenkron olarak uygun zamanda yazılır. Try-catch mekanizması dosya yok, açılamaz gibi durumlar nedeniyle zorunludur. StreamReader ile satır satır okuma yapılabilir. Parcelable ve Serializable interface'leri objelerin bütün halinde binary formatta kaydedilmesini sağlar. Cache kullanımı detaylı olarak ele alınmıştır. Cache dizini sonradan silinmesi sorun yaratmayacak, kalıcı olması gerekmeyen dosyalar için uygundur. İnternetten indirilen yüksek boyutlu dosyalar işlendikten sonra cache'de tutulabilir. İşletim sistemi bellek yetersiz kaldığında cache dizinlerini otomatik temizler (garbage collector kadar sık değildir, belli bir oranı doldurmuş olmanız gerekir). Normal dizinlerde tek tek dosya kontrolü gerekir, cache'de toplu silme yapılabilir. Bu, pil ömrü için avantaj sağlar.

### 🔹 Ders 12: Sensörler: Hareket/Pozisyon/Çevresel Türler, Sensör Framework, Register/Unregister, Activity Recognition
* **Genel Konular:**
  - Sensör kavramı
    - Sensörler, cihazların (akıllı telefon, akıllı saat) gözü kulağı olarak kabul edilebilir.
    - Mevcut sensörler insanlardan daha hassas ölçümler yapabilir (düşme tespiti, adım sayma, sıcaklık ölçümü).
    - Cihazlardaki sensörler küçük boyutlarına rağmen yeterli olsa da, profesyonel (plasman) sensörler kadar detaylı ölçüm yapamayabilir.
  - Sensör çeşitliliği
    - Farklı cihazlarda farklı sensörler bulunabilir; program yazarken bu durumun gözetilmesi önemlidir.
    - Her sensörün yetenekleri farklıdır: ölçebileceği aralık (range), çözünürlük (resolution), ihtiyaç duyduğu güç ve enerji.
    - Çok sık arka planda değer okunan sensörler için bu özelliklerin gözetilmesi kritik öneme sahiptir.
  - Sensör türleri
    - Hareket sensörleri: ivme ölçer (accelerometer), jiroskop (gyroscope), yerçekimi sensörü.
    - Pozisyon sensörleri: manyetometre, proximity (yakınlık) sensörü.
    - Çevresel sensörler: ışık, sıcaklık, basınç, nem sensörü.
    - Donanımsal (hardware) ve yazılımsal (software) sensörler ayrımı; yazılımsal sensörler donanım sensörlerinden elde edilen değerler kullanılarak hesaplanır (örneğin yerçekimi sensörü, doğrusal ivme ölçer).
  - Sensör framework'ı
    - Dört temel bileşen:
      1. SensorManager: sensörlere erişim ve sisteme entegrasyon/çıkarma sorumluluğu.
      2. Sensor sınıfı: sensörün yeteneklerini paylaşır.
      3. SensorEvent: sensörden veri üretildiğinde oluşan obje; verinin ne zaman üretildiği, hareketin değeri, hangi sensörden geldiği bilgilerini saklar.
      4. SensorEventListener: tetikleme sırasında değişen değerleri takip etmek için listener.
  - Sensör kullanım adımları
    - SensorManager objesi oluşturulur (getSystemService ile sensör servisi alınır).
    - getSensorList ile cihazdaki sensörler listelenir (type all veya type accelerometer gibi).
    - Cihazda birden fazla aynı tip sensör olabilir (hastal sebepler, enerji verimliliği, yedeklilik).
    - Sensör özellikleri: getResolution, getMaximumRange, getPower, getVendor, getVersion.
    - Sensör kaydı: registerListener ile sensör dinlenmeye başlanır, unregister ile durdurulur.
    - Sensör sorgulama: queryIntentActivities benzeri bir kontrol ile ihtiyaç duyulan sensör var mı yok mu tespit edilir.
  - Sensör frekansı (veri toplama hızı)
    - Saniyedeki veri toplama hızına "frekans" denir (örneğin 50 Hz = saniyede 50 veri, 20 ms'de bir).
    - Akselerometre ve jiroskop gibi hareket sensörleri saniyede 200 defaya kadar veri toplayabilir.
    - Işık sensörü gibi sensörler daha düşük aralıklarla (saniyede 1-2) değer üretir; sık okuma anlamsızdır.
    - Hangi sensörle çalışılıyorsa çözünürlük ve frekans set edilebilir.
  - SensorEventListener metotları
    - onAccuracyChanged: sensör hassasiyeti değiştiğinde çağrılır.
    - onSensorChanged: her veri değişiminde çağrılır; her bir değişim gerçekleştiğinde sensör event üzerinden değerler alınır.
    - Birden fazla sensör okunuyorsa hangi sensörden değer geldiği kontrol edilmelidir.
    - Sürekli veri alan sensörler (accelerometer, gyroscope) "continuous" olarak event üretir.
    - Step counter gibi sensörler sadece değişim olduğunda event üretir ("on-change").
    - Significant motion sensör gibi trigger sensörler sadece belirli bir olay tetiklendiğinde bir kez event üretir ("one-shot").
  - Sensör veri formatı
    - 3 eksenli sensörler (X, Y, Z) için values[0], values[1], values[2].
    - 5 eksenli (kalibre olmamış) sensörler için values[0..4].
    - Tek eksenli sensörler (örn. ışık) için sadece values[0].
    - Kalibre ve kalibre olmayan sensörlerin farklı veri formatları.
  - Sensör kayıt ve kaldırma (register/unregister)
    - Kullanılmayan sensörlerin mutlaka unregister edilmesi gerekir (pil ömrü için).
    - Activity pause olduğunda (örneğin oyun duraklatıldığında) sensör unregister edilebilir.
    - Arka planda çalışan servisler için sensör kaydı gerekli olduğunda, gerekli durumlarda unbind edilerek durdurulabilir.
    - Manifest'te Google Play Filter ile sensör/kamera gibi parçalar required="true" olarak tanımlanabilir; olmayan cihazlarda uygulama Google Play'de görünmez.
    - required="false" yapılırsa iki farklı yol (sensörü olan/olmayan) kodlanabilir.
  - Android Run-time izin mekanizması ve sensörler
    - Sensörlere erişim için de izin sistemi kullanılabilir.
    - "Allow once, allow while using the app" gibi seçenekler sunulabilir.
    - Android 9 ile birlikte sensör kullanımı yaygınlaşmıştır; doğru frekans seçimi önemlidir.
  - Sanal sensörler
    - GPS, kamera, mikrofon, Wi-Fi modülü, Bluetooth modülü sanal sensör olarak değerlendirilebilir.
    - Mesajlar, takvim eventleri de sanal sensör verisi olarak kabul edilebilir (toplantı varsa telefon kendini sessize alabilir).
    - Fiziksel sensörler: kamera, mikrofon, Wi-Fi modülü, Bluetooth modülü, GPS modülü.
  - İnsan Activity Recognition API
    - Android'in sunduğu bir API; kişinin hareketlerini takip eder.
    - Hareket değişimi algılandığında arka planda trigger sensörü tetiklenir.
    - Araba, yürüyüş, dans, egzersiz gibi aktiviteleri tanıyabilir.
    - Activity Recognition API kullanılmazsa kendi aktivite tanıma mantığı accelerometer, gyroscope, magnetometer ile yazılabilir.
  - Hareketsizlik hesaplama (Su terazisi örneği)
    - Telefon düz bir yüzeye konulduğunda tek bir eksende 9.81, diğer 2 eksende 0 görülür.
    - Eğimli yüzeye konulduğunda değerler eksenlere dağılır.
    - Bu basit kontrol ile yüzeyin eğimli olup olmadığı tespit edilebilir.
    - Daha hassas ölçüm için orientation sensörü (deprecated) yerine gyroscope ve magnetometer kombinasyonu kullanılabilir.
  - Jiroskop ve accelerometer farkı
    - Jiroskop: belirli bir eksendeki açısal hızı rad/s cinsinden verir (X, Y, Z etrafında ne kadar hızlı dönüyorsunuz).
    - İvme ölçer: doğrusal ivmeyi ölçer.
    - İvme ölçer yeterli olduğunda jiroskop bilgisine ihtiyaç duyulmayabilir.
    - Düşme veya aktivite hareketlerini tanımada jiroskop kullanılır; yürüme/koşma gibi 3 eksende hareket eden detaylı analizler için jiroskop + manyetometre birlikte kullanılır.
* **Hocanın Vurgusu:**
  - Sensör seçiminin ve yönetiminin kritikliği
    - Farklı cihazlarda farklı sensörler bulunduğundan, program yazarken bu çeşitliliğin göz önünde bulundurulması gerektiği.
    - Çok sık arka planda değer okunan sensörler için frekans ve enerji tüketiminin dikkatlice yönetilmesi.
  - Sensör unregister işleminin pil ömrü için önemi
    - Kullanılmayan sensörlerin mutlaka unregister edilmesi gerektiği; oyun duraklatıldığında sensörün unregister edilmesi örnekleri.
    - Arka planda çalışan servislerde gerekli durumlarda unbind edilmesi gerektiği.
  - Sensör veri üretme sırasında uzun iş yapılmaması
    - onSensorChanged, onTrigger gibi metotlarda uzun süren işler yapılmamalı.
    - Bunun yerine farklı thread, go async, job scheduler gibi background taskları kullanılmalı.
  - Sanal sensör kavramının genişletilmesi
    - Sensör denilince sadece fiziksel sensörler değil, kamera, mikrofon, GPS, mesajlar, takvim eventleri de düşünülmeli.
    - Veri kaynağı olan her nokta sanal sensör verisi olarak değerlendirilebilir.
  - Manifest tanımlamalarının uygulama görünürlüğüne etkisi
    - Google Play Filter ile sensör, kamera gibi parçalar required="true" yapılırsa, o parçaya sahip olmayan telefonlarda uygulama görünmez.
    - required="false" yapılırsa iki farklı yol kodlanmalıdır.
  - Android 9 ile gelen sensör kullanımı yaklaşımı
    - Continuous, on-change, one-shot (trigger) reporting mode'larının her birinin uygun kullanım senaryoları.
    - Hangi sensör için hangi modun seçileceğinin bilinmesi gerektiği.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, iki haftadır görüşemediklerini, toplamda üç hafta olduğunu, bu sene iki dersin bayramlardan dolayı gerçekleşmediğini belirtmiştir. Dönemin sonuna doğru yaklaştıklarını, üç haftalarının kaldığını söylemiştir. Bugün tempolu bir şekilde ilerleyecekleri, önce sensörlerden (telefonlar üzerinde nasıl veri toplandığı), arkasından broadcast receiver'ı tamamlayacakları, önümüzdeki hafta location based servisleri, arkasından background task'ları, notification'ları, vakit kalırsa mapler ve Android market'e uygulama yükleme prosedürlerini anlatacakları belirtilmiştir. Dönem projesi ile ilgili soru sorulmuş, bonus konusunda Firebase kullanımının ötesinde, bilgilerin lokalde saklanıp telefonun şarja takıldığı anda network'e aktarılmasını kastettiği, Firebase üzerinden de implemente edilebileceği ama özel yapıyı kuranların bonus alacağı söylenmiştir. Dersin ana konusuna, yani sensörlere geçildiğinde ilk olarak sensör kavramı tanıtılmıştır. Sensörler, cihazların (akıllı telefon, akıllı saat) gözü kulağı olarak kabul edilebilir. Mevcut sensörler insanlardan daha hassas ölçümler yapabilir (düşme tespiti, adım sayma, sıcaklık ölçümü). Cihazlardaki sensörler küçük boyutlarına rağmen yeterli olsa da, profesyonel (plasman) sensörler kadar detaylı ölçüm yapamayabilir. Cihazlar üzerindeki hangi sensörlerin olduğunu bilmek programlama yaparken önemlidir; farklı cihazlarda farklı sensörler bulunabilir. Bu durum program yazarken göz önünde bulundurulmalıdır. Her sensörün yetenekleri farklıdır: ölçebileceği aralık (range), çözünürlük (resolution), ihtiyaç duyduğu güç ve enerji. Bu nedenle özellikle çok sık arka planda değer okunan sensörler için bu özelliklerin gözetilmesi kritik öneme sahiptir. Sensör türleri detaylı olarak açıklanmıştır. Hareket sensörleri: ivme ölçer (accelerometer), jiroskop (gyroscope), yerçekimi sensörü. Pozisyon sensörleri: manyetometre, proximity (yakınlık) sensörü. Çevresel sensörler: ışık, sıcaklık, basınç, nem sensörü. Donanımsal (hardware) ve yazılımsal (software) sensörler ayrımı vardır; yazılımsal sensörler donanım sensörlerinden elde edilen değerler kullanılarak hesaplanır (örneğin yerçekimi sensörü, doğrusal ivme ölçer, ivme ölçerden yer çekimi çıkarılarak). Sensör framework'ı dört temel bileşenden oluşur: SensorManager (sensörlere erişim ve sisteme entegrasyon/çıkarma sorumluluğu), Sensor sınıfı (sensörün yeteneklerini paylaşır), SensorEvent (sensörden veri üretildiğinde oluşan obje; verinin ne zaman üretildiği, hareketin değeri, hangi sensörden geldiği bilgilerini saklar), SensorEventListener (tetikleme sırasında değişen değerleri takip etmek için listener). Sensör kullanım adımları açıklanmıştır. SensorManager objesi oluşturulur (getSystemService ile sensör servisi alınır). getSensorList ile cihazdaki sensörler listelenir (type all veya type accelerometer gibi). Cihazda birden fazla aynı tip sensör olabilir (hastal sebepler, enerji verimliliği, yedeklilik). Sensör özellikleri: getResolution, getMaximumRange, getPower, getVendor, getVersion. Sensör sorgulama: queryIntentActivities benzeri bir kontrol ile ihtiyaç duyulan sensör var mı yok mu tespit edilir. Sensör kaydı: registerListener ile sensör dinlenmeye başlanır, unregister ile durdurulur. Hoca, registerListener'a üç parametre (SensorEventListener, Sensor, frekans) verildiğini, burada Google'ın üreticisi ve versiyon 3 gibi özelliklere göre spesifik sensör seçilebileceğini açıklamıştır. Sensör frekansı (veri toplama hızı) detaylı olarak ele alınmıştır. Saniyedeki veri toplama hızına "frekans" denir (örneğin 50 Hz = saniyede 50 veri, 20 ms'de bir). Akselerometre ve jiroskop gibi hareket sensörleri saniyede 200 defaya kadar veri toplayabilir. Işık sensörü gibi sensörler daha düşük aralıklarla (saniyede 1-2) değer üretir; sık okuma anlamsızdır. Hangi sensörle çalışılıyorsa çözünürlük ve frekans set edilebilir. SensorEventListener metotları açıklanmıştır. onAccuracyChanged sensör hassasiyeti değiştiğinde çağrılır. onSensorChanged her veri değişiminde çağrılır; her bir değişim gerçekleştiğinde sensör event üzerinden değerler alınır. Birden fazla sensör okunuyorsa hangi sensörden değer geldiği kontrol edilmelidir. Sürekli veri alan sensörler (accelerometer, gyroscope) "continuous" olarak event üretir. Step counter gibi sensörler sadece değişim olduğunda event üretir ("on-change"). Significant motion sensör gibi trigger sensörler sadece belirli bir olay tetiklendiğinde bir kez event üretir ("one-shot"); event yakalandıktan sonra sensör kendini deaktif eder ve devamlı dinleme rutininde kalmaz. Sensör veri formatı açıklanmıştır. 3 eksenli sensörler (X, Y, Z) için values[0], values[1], values[2]. 5 eksenli (kalibre olmamış) sensörler için values[0..4]. Tek eksenli sensörler (örn. ışık) için sadece values[0]. Kalibre ve kalibre olmayan sensörlerin farklı veri formatları vardır; kalibre olanlar belirli bir gürültü kontrolü yapılıp değeri ona göre üretir. Sensör kayıt ve kaldırma (register/unregister) konusu özellikle vurgulanmıştır. Kullanılmayan sensörlerin mutlaka unregister edilmesi gerekir (pil ömrü için). Activity pause olduğunda (örneğin oyun duraklatıldığında) sensör unregister edilebilir. Arka planda çalışan servisler için sensör kaydı gerekli olduğunda, gerekli durumlarda unbind edilerek durdurulabilir. Manifest'te Google Play Filter ile sensör/kamera gibi parçalar required="true" olarak tanımlanabilir; olmayan cihazlarda uygulama Google Play'de görünmez. required="false" yapılırsa iki farklı yol (sensörü olan/olmayan) kodlanabilir. Sanal sensör kavramı genişletilmiştir. GPS, kamera, mikrofon, Wi-Fi modülü, Bluetooth modülü sanal sensör olarak değerlendirilebilir. Mesajlar, takvim eventleri de sanal sensör verisi olarak kabul edilebilir (toplantı varsa telefon kendini sessize alabilir). Veri kaynağı olan her nokta sanal sensör verisi olarak değerlendirilebilir. Hoca, "kendi sanal sensörünüzü bu yönde üretme şansınız var" diyerek uygulama özelinde sanal sensör yazılabileceğini belirtmiştir. İnsan Activity Recognition API açıklanmıştır. Android'in sunduğu bir API; kişinin hareketlerini takip eder. Hareket değişimi algılandığında arka planda trigger sensörü tetiklenir. Araba, yürüyüş, dans, egzersiz gibi aktiviteleri tanıyabilir. Activity Recognition API kullanılmazsa kendi aktivite tanıma mantığı accelerometer, gyroscope, magnetometer ile yazılabilir (Squat hareketi yaparken telefonun üzerinden anlamak kolay değil ama saat üzerinden anlayabilirsiniz). Hareketsizlik hesaplama (su terazisi örneği) detaylı olarak verilmiştir. Telefon düz bir yüzeye konulduğunda tek bir eksende 9.81, diğer 2 eksende 0 görülür. Eğimli yüzeye konulduğunda değerler eksenlere dağılır. Bu basit kontrol ile yüzeyin eğimli olup olmadığı tespit edilebilir. Daha hassas ölçüm için orientation sensörü (deprecated) yerine gyroscope ve magnetometer kombinasyonu kullanılabilir. Hoca, "orientation sensörü deprikate olmuş bir sensördür, software based" demiştir. Jiroskop ve accelerometer farkı açıklanmıştır. Jiroskop belirli bir eksendeki açısal hızı rad/s cinsinden verir (X, Y, Z etrafında ne kadar hızlı dönüyorsunuz). İvme ölçer doğrusal ivmeyi ölçer. İvme ölçer yeterli olduğunda jiroskop bilgisine ihtiyaç duyulmayabilir. Düşme veya aktivite hareketlerini tanımada jiroskop kullanılır; yürüme/koşma gibi 3 eksende hareket eden detaylı analizler için jiroskop + manyetometre birlikte kullanılır.

### 🔹 Ders 13: Arka Plan İş Yönetimi: WorkManager, AlarmManager, Foreground Service, App Standby Buckets, Doze
* **Genel Konular:**
  - Background task kavramı
    - Arka plan işlerinin tanımı: kullanıcı ile doğrudan etkileşimde olmayan, bir arayüz ile bağlantısı olmayan, genelde uzun süren (milisaniyelerin ötesinde) ve herhangi bir uygulamanın bir aktivitesi tarafından başlatılmamış işler.
    - Arka plan işlerinin neden gerekli olduğu: kullanıcı etkileşiminin kesintiye uğramaması, kaynakların verimli kullanımı, performans artırma.
    - Ana thread (main thread, UI thread) bütün UI bileşenlerini ve kullanıcı ilişkisini yürütür; uzun süreli işler burada yapılırsa ekran donar (ANR - Application Not Responding).
  - Arka plan iş yönetim yapıları
    - Handler: tek bir thread'in yönetiminden sorumlu; veri tabanı bağlantısı, tek bir veri sorgusu gibi tek işler için uygun.
    - ExecutorService: birden fazla thread'in yönetiminden sorumlu; thread'lerle ilgili genel bilgi almayı sağlar (thread'in ne kadar çalıştığı, ne kadar beklediği); thread pool oluşturarak birden fazla thread'i yönetir.
    - Broadcast Receiver: manifestte register edildiğinde tipik bir arka plan işi; sistem koşulu oluştuğunda onReceive metodu çalışır.
    - AlarmManager: belirli işleri belirlenen saatlerde bir kez veya tekrar edecek şekilde (saatlik, günlük, haftalık) çalıştırır; daha strikt, kaynak tüketimi yüksek.
    - WorkManager: JobScheduler ile uyumlu çalışan modern API; belli koşullar (güç bağlantısı, network) oluştuğunda işlerin çalışmasını sağlar; foreground service olarak da belli işlerin çalışmasından sorumlu olabilir; kaynak tüketimi açısından daha verimli.
    - Foreground Service: kullanıcı arayüzüne sahip olmayan, uzun süre kullanıcı ile interaksiyon olmadan çalışan yapı; notification tray, pop-up dialog box, voice command gibi yapılarla iletişim; en öncelikli, en korunan, sistem tarafından ortadan kaldırılma olasılığı çok düşük işler.
  - Background task kategorizasyonu
    - Üç temel kategori: hemen yapılması gerekenler (immediate), belirlenmiş kesin zamanda yapılması gerekenler (exact), belli bir periyoda tamamlanması gereken veya ertelenebilir olanlar (deferred).
    - Hangi yapının seçileceği şu sorulara verilen cevaba göre belirlenir:
      - İş kesin bir saatte mi çalışacak? (AlarmManager)
      - Hemen mi yapılması gerekiyor? (WorkManager veya Foreground Service)
      - Belli periodlarla mı çalışacak? (WorkManager)
      - İş kesintiye uğrayabilir mi? (büyük upload/download için dikkat)
      - Cihaz koşullarıyla ilişkisi var mı? (güç kaynağı, Wi-Fi)
      - Hassas kullanıcı verisi toplamayı içeriyor mu? (lokasyon bilgisi vb.)
  - Android background task yönetiminin tarihsel gelişimi
    - Android 6.0 öncesi: inanılmaz özgürlük; istenen iş arka plana atılıyor, sınırsız çalışabiliyor; RAM ve pil tüketimi olumsuz etkileniyor; ANR hataları.
    - Android 6.0 (Doze): pil tüketimi için çözüm; telefon kullanılmıyorsa ve ekran kapalıysa sabit olarak hareket etmediğini tespit edip arka plan sıklığını azaltır.
    - Android 7 (Doze on the Go): hareket halinde de arka plan servislerini yönetir; araçla seyahat gibi durumları tespit eder.
    - Android 9 (App Standby Buckets): uygulamaları kullanım karakteristiklerine göre önceliklendirir; makine öğrenmesi yaklaşımı.
  - App Standby Buckets
    - 5 kategori (bucket):
      - Active: şu anda kullanılan veya çok yakında kullanılmış uygulamalar.
      - Working set: gün içinde sık kullanılan (sosyal medya gibi).
      - Frequent: günde bir iki kez veya gün aşırı kullanılan (gym uygulaması gibi).
      - Rare: ayda yılda bir kez kullanılan (seyahat uygulamaları gibi).
      - Never: hiç uğranmamış uygulamalar.
    - Sistem karar verir, makine öğrenmesi kullanır, müdahale edilmemelidir.
    - Amaç: sık kullanılan uygulamalara daha fazla kaynak (CPU, RAM, pil) ayırmak; nadir kullanılanları kısıtlamak.
    - Launcher olmadan uygulama hiçbir zaman Active bucket'a giremez.
    - Foreground service'e sahip uygulamalar Active olabilir (müzik uygulaması gibi).
    - Content provider üzerinden veri senkronizasyonu yapan uygulamalar da Active'te.
    - getAppStandByBucket metodu ile bucket durumu gözlemlenebilir (UsageStatsManager).
  - Foreground Service kullanım örnekleri
    - Müzik uygulaması: arka planda çalıp notification bar üzerinden kontrol.
    - Sesli/görüntülü konuşma uygulamaları: kesintisiz hizmet kalitesi.
    - Navigasyon uygulamaları: arka planda lokasyon takibi + sesli direktifler.
    - Download uygulamaları: indirme sırasında kesinti olmaması (ama Download Manager yapısı da var).
  - AlarmManager
    - Belirli zamanlarda çalışacak işler için: tek bir kez gerçekleşebilir veya birden fazla (saatlik, günlük, haftalık).
    - Örnek: gece 2'de yedekleme, sabah 7'de alarm.
    - WorkManager'ın AlarmManager'a göre avantajı: kaynak tüketimi açısından daha verimli (esneklik var).
    - AlarmManager kesin dakika/saniyede çalışmak zorunda olduğu için kaynak tüketimi yüksek.
  - Service (Servis) bileşeni
    - Android'in dört temel bileşeninden biri.
    - Kullanıcı arayüzüne sahip olmayan, uzun süre kullanıcı ile interaksiyon olmadan çalışan yapı.
    - Günümüzde en son başvurulan komponentlerden biri (alternatif çözümler çıkmasıyla).
    - Örnek: sağlık bilgilerini arka planda takip eden uygulama; GPS, accelerometer, gyroscope, magnetometer gibi sensörlerden faydalanır.
  - Doze modunun detayları
    - Telefon hareketsiz kaldığında arka plan lokasyon bilgisi sıklığını azaltır; sıklık saniyede 1'den yarım dakika/dakikada 1'e çıkabilir.
    - 7 ile gelen Doze on the Go: araç hareket halindeyken de (stationer pozisyonda değilken) arka plan servislerini yönetir; kaynak tasarrufu sağlar.
    - Android 9'da uygulamaların kullanım sıklığına göre bucket'lara ayrılması (App Standby Buckets).
* **Hocanın Vurgusu:**
  - Doze modunun yazılımsal çözüm olarak kritikliği
    - Android 6.0 ile gelen Doze modunun yazılımsal bir çözüm olduğu, pil tüketimini azaltmak için telefonun hareketsizliğini tespit edip arka plan sıklığını azalttığı.
    - "Yazılımsal bir çözüm olduğunu hatırlıyorum" diyen öğrenciye hoca bu tespiti onaylamıştır.
  - Background işlerde main thread'den kaçınmanın önemi
    - "Application not responding" hatasının en önemli sebebinin kısa sürmeyen işlerin main thread'de yapılması.
    - User experience'ın kötü deneyimler yaşatmaması için hangi yapıların kullanılacağının iyi bilinmesi.
  - App Standby Buckets'e müdahale edilmemesi gerektiği
    - "Kesinlikle müdahale edilmemesi gerekiyor" vurgusu; sistem bu yapıyı makine öğrenmesi ile yönetir.
    - Bucket'lar zaman içinde değişebilir; uygulama bir bucket ile girdiğinde hep orada kalmaz.
    - Üreticinin device'e bağlı olarak farklı aritmetikle çalıştığı, dinamik bir yapı olduğu.
  - Foreground service'in kritik senaryolar için kullanılması
    - Müzik, video konferans, navigasyon gibi kesintisiz çalışması gereken uygulamalar.
    - Sistem tarafından ortadan kaldırılma olasılığı en düşük yapı olduğu.
    - Download manager'ın Android'in sunduğu bir başka yapı olduğu, download için foreground service yerine onun da tercih edilebileceği.
  - Sık kullanılan uygulamalara daha fazla kaynak ayrılmasının amacı
    - "Hedef pil tüketimini minimize etmek"; RAM'i az kullanmak değil, pili az kullanmak asıl amaç.
    - "Daha çok RAM'i az kullanmak değil onları az kullandığınızda doğal olarak pili de az kullanmış oluyorsunuz" ifadesi.
* **Detaylı Açıklamalar:** Dersin başlangıcında hoca, derse 30 dakika geç başlamak zorunda kaldığını belirterek özür dilemiştir. Bu hafta background task'ları konuşacakları, Android tarafında arka plan işlerini yönetmek için çeşitli seçenekler olduğu belirtilmiştir. Küçük bir uygulama örneği verileceği, arkasından notification'lar anlatılacağı ve haftanın noktalanacağı söylenmiştir. Bir sonraki hafta location based servislerden, haritalardan bahsedileceği ve dönemin tamamlanacağı belirtilmiştir. Dönem projesi ile ilgili soru sorulmuş, ancak spesifik bir soru gelmemiştir. Background task kavramı detaylı olarak açıklanmıştır. Arka plan işlerinin tanımı öğrencilerle etkileşimli olarak yapılmıştır. Bir öğrenci web servisi ile yedekleme veya arka planda dosya indirme örneği vermiştir. Hoca bunu kabul etmiş, lokasyon bilgisini web servisine gönderme örneğini de eklemiştir. Resmi olarak şu özellikler tanımlanmıştır: kullanıcı ile etkileşimde olmayan işler, bir arayüz ile bağlantısı olmayan işler, uzun süren (milisaniyelerin ötesinde, saniyenin üzerinde) işler, herhangi bir uygulamanın bir aktivitesi tarafından başlatılmamış foreground servisler. Ana thread (main thread, UI thread) bütün UI bileşenlerini ve kullanıcı ilişkisini yürütür; uzun süreli işler burada yapılırsa ekran donar (freeze eder, dolar, bloklanır) ve bu problem olur. Arka plan iş yönetim yapıları detaylı olarak ele alınmıştır. Handler tek bir thread'in yönetiminden sorumlu; veri tabanı bağlantısı, tek bir veri sorgusu gibi tek işler için uygun. ExecutorService birden fazla thread'in yönetiminden sorumlu; thread'lerle ilgili genel bilgi almayı sağlar (thread'in ne kadar çalıştığı, ne kadar beklediği); thread pool oluşturarak birden fazla thread'i yönetir. Bir öğrencinin Java'daki Executor sorusu üzerine hoca, Android'e spesifik bir yapı olmadığını, aynı yapının burada da kullanıldığını belirtmiştir. Broadcast Receiver manifestte register edildiğinde tipik bir arka plan işi; sistem koşulu oluştuğunda onReceive metodu çalışır. AlarmManager belirli işleri belirlenen saatlerde bir kez veya tekrar edecek şekilde (saatlik, günlük, haftalık) çalıştırır; daha strikt, kaynak tüketimi yüksek. WorkManager JobScheduler ile uyumlu çalışan modern API; belli koşullar (güç bağlantısı, network) oluştuğunda işlerin çalışmasını sağlar; foreground service olarak da belli işlerin çalışmasından sorumlu olabilir; kaynak tüketimi açısından AlarmManager'a göre daha verimli. Foreground Service kullanıcı arayüzüne sahip olmayan, uzun süre kullanıcı ile interaksiyon olmadan çalışan yapı; notification tray, pop-up dialog box, voice command gibi yapılarla iletişim; en öncelikli, en korunan, sistem tarafından ortadan kaldırılma olasılığı çok düşük işler. Background task kategorizasyonu üç temel kategori üzerinden açıklanmıştır. Hemen yapılması gerekenler (immediate), belirlenmiş kesin zamanda yapılması gerekenler (exact), belli bir periyoda tamamlanması gereken veya ertelenebilir olanlar (deferred). Hangi yapının seçileceği şu sorulara verilen cevaba göre belirlenir: İş kesin bir saatte mi çalışacak? Hemen mi yapılması gerekiyor? Belli periodlarla mı çalışacak? İş kesintiye uğrayabilir mi? (büyük upload/download için dikkat, Wi-Fi üzerine indirilmediğinde gigabyte'ların boşa kullanılması). Cihaz koşullarıyla ilişkisi var mı? (güç kaynağı, Wi-Fi). Hassas kullanıcı verisi toplamayı içeriyor mu? (lokasyon bilgisi). Android background task yönetiminin tarihsel gelişimi detaylı olarak anlatılmıştır. Android 6.0 öncesi inanılmaz bir özgürlük vardı; istenen iş arka plana atılıyordu, arka plan sınırsız bir özgürlükle processleri çalıştırabiliyordu. Bu da özellikle RAM ve pil tüketimini çok olumsuz etkiliyordu. Birçok uygulamanın farkında olmadan pillerin hızla bitmesine ve ANR (Application Not Responding) hatalarına yol açıyordu. 6.0 ile birlikte Android yeni bir düzen oluşturmaya başladı: Doze modu devreye sokuldu. Bir öğrencinin "yazılımsal bir çözüm olduğunu hatırlıyorum" tespiti hoca tarafından onaylanmıştır. Doze, telefonun hareketsiz kaldığı anları tespit edip arka plan sorgulamalarını azaltır; sıklık saniyede 1'den yarım dakika/dakikada 1'e çıkabilir. 7 ile birlikte Doze on the Go geldi: araçla seyahat gibi durumları tespit edip arka plan servislerini yönetir. 9'da App Standby Buckets geldi: uygulamaları kullanım karakteristiklerine göre önceliklendirir. App Standby Buckets 5 kategoriden oluşur: Active (şu anda kullanılan veya çok yakında kullanılmış uygulamalar), Working set (gün içinde sık kullanılan, sosyal medya gibi), Frequent (günde bir iki kez veya gün aşırı kullanılan, gym uygulaması gibi), Rare (ayda yılda bir kez kullanılan, seyahat uygulamaları gibi), Never (hiç uğranmamış uygulamalar). Sistem karar verir, makine öğrenmesi kullanır; müdahale edilmemelidir. Bucket'lar zaman içinde değişebilir; uygulama bir bucket ile girdiğinde hep orada kalmaz. getAppStandByBucket metodu ile bucket durumu UsageStatsManager üzerinden gözlemlenebilir. Hoca, "sistemin bunu kendi yönettiğini ve her bir üreticinin ürettiği device'e bağlı olarak farklı bir aritmetikle çalıştığını rahatlıkla söyleyebiliriz" diyerek dinamik yapıyı vurgulamıştır. Active bucket'a girmek için launcher olması şarttır; foreground service'e sahip uygulamalar (müzik uygulaması gibi) Active olabilir; content provider üzerinden veri senkronizasyonu yapan uygulamalar da Active'tedir. Hoca, "daha sık kullanılan uygulamalara daha fazla öncelik vererek kullanıcının günlük telefon kullanımını rahatlatmak" diyen öğrenciye, "daha fazla kaynak temin ederek" şeklinde düzeltmiştir: "Ne kadar önceliği yüksekse o uygulama daha fazla kaynak alıyor. Bütün aslında mantık bu." Hoca ayrıca "temel hedef enerji tüketimini minimize etmek" vurgusunu yapmıştır. Foreground Service kullanım örnekleri açıklanmıştır. Müzik uygulaması: arka planda çalıp notification bar üzerinden kontrol. Sesli/görüntülü konuşma uygulamaları: kesintisiz hizmet kalitesi. Navigasyon uygulamaları: arka planda lokasyon takibi + sesli direktifler. Download uygulamaları için bir öğrenci download'ın foreground service olup olmadığını sormuş, hoca "Android'in sunduğu bir başka yapı daha var, download manager" diyerek alternatif sunmuştur. Hoca ayrıca "en öncelikli, en korunan ve genelde sistem tarafından ortadan kaldırılma olasılığı çok düşük olan işler" diyerek foreground service'in önemini vurgulamıştır. AlarmManager ve WorkManager karşılaştırması yapılmıştır. AlarmManager belirli zamanlarda çalışacak işler için: tek bir kez gerçekleşebilir veya birden fazla (saatlik, günlük, haftalık). Örnek: gece 2'de yedekleme, sabah 7'de alarm. WorkManager'ın AlarmManager'a göre avantajı: kaynak tüketimi açısından daha verimli (esneklik var). AlarmManager kesin dakika/saniyede çalışmak zorunda olduğu için kaynak tüketimi yüksek. Hoca, "Work Manager özellikle Job Scheduler'la da uyumlu bir şekilde çalışıyor. Yeni versiyonu olarak da düşünebilirsiniz" demiştir. Service bileşeni kısaca açıklanmıştır. Android'in dört temel bileşeninden biri (activity, service, broadcast receiver, content provider). Kullanıcı arayüzüne sahip olmayan, uzun süre kullanıcı ile interaksiyon olmadan çalışan yapı. Günümüzde en son başvurulan komponentlerden biri (alternatif çözümler çıkmasıyla). Örnek: sağlık bilgilerini arka planda takip eden uygulama; GPS, accelerometer, gyroscope, magnetometer gibi sensörlerden faydalanır.

<!--MARKER_DERS14-->
