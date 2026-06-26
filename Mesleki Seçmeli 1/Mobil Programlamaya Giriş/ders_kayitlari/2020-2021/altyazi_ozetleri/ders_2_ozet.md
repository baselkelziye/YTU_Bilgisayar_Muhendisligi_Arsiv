# Ders 2 Çalışma Özeti

## Genel Konular

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

## Hocanın Özellikle Vurguladığı Kısımlar

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

## Kısa Tekrar Notları

- Mobil bilgi işlem = mobil iletişim + mobil donanım + mobil yazılım.
- Mobil iletişim örnekleri: NFC, Bluetooth, BLE, Wi-Fi, hücresel ağ (4G, 5G, GPRS), uydu haberleşmesi.
- ARM işlemciler RISC kullanır, düşük enerji tüketir; Intel CISC kullanır, yüksek performans ama çok enerji.
- Co-processor: sensör verilerini düşük güçte okuyan yardımcı işlemci.
- Çok çekirdekli yapı: 4 düşük güçlü + 4 yüksek performanslı çekirdek; Android buna göre yönetir.
- Android Doze: hareketsizlikte arka plan işlemlerini azaltan enerji tasarruf mekanizması.
- İşletim sistemi türleri: masaüstü, sunucu, gerçek zamanlı, mobil, gömülü (Tizen, ROS).

## Detaylı Açıklamalar

Dersin başlangıcında hoca, geçen hafta mobil teknolojiler konusuna giriş yapıldığını hatırlatmış, bu hafta mobil işletim sistemleri ve mobil geliştirme yöntemlerine geçileceğini belirtmiştir. Dersin ilk bölümünde mobil bilgi işlem (mobile computing) kavramı detaylı olarak ele alınmıştır. Mobil bilgi işlemin üç temel bileşeni vurgulanmıştır: mobil iletişim (mobile communication), mobil donanım (mobile hardware) ve mobil yazılım (mobile software). Mobilitenin sağlanması için cihazların haberleşebilme yeteneğine sahip olması gerektiği, bu özelliğin mobil bilgi işlemi masaüstü bilgi işlemden ayıran temel özellik olduğu belirtilmiştir.

Mobil iletişim konusunda öğrencilerle etkileşimli bir şekilde ilerlenmiştir. Bir öğrenci RESTful API ile ağ servislerine bağlanma ve veritabanından veri okuma örneği vermiş, ancak hoca bu örneğin daha çok frontend/backend operasyonlarına girdiğini belirterek daha net bir örnek olarak NFC'yi vermiştir. NFC'nin geliştirilmesinin doğrudan mobil iletişim konusunun bir parçası olduğu açıklanmıştır. Diğer örnekler olarak Bluetooth, Bluetooth Low Energy, Wi-Fi verilmiştir. Bir öğrenci 4G, 5G, GPRS'in de mobil iletişim kapsamında olup olmadığını sormuş, hoca bu teknolojilerin hepsinin hücresel ağ (cellular network) kapsamında olduğunu, özellikle 5G üzerine yoğun araştırma yürütüldüğünü belirtmiştir. Hoca, mobil iletişim alanının çok geniş olduğunu, bu yüzden dersin amaçlarını aşmamak için kısa tutulacağını söylemiştir.

Bir öğrencinin Mars'taki araca yazılım yüklenmesi ve fotoğraf aktarımının mobil bilgi işlem kapsamında olup olmadığı sorusuna hoca ilginç bir cevap vermiştir: Bu tür senaryolarda fiziksel bir bağlantı olmadığı için doğal olarak mobil iletişim başlığı altında değerlendirilebileceğini, ancak koşulların farklı olduğunu belirtmiştir. Uydu haberleşmesinin (genellikle uydu iletişimi olarak adlandırılır) bu tür durumlarda devreye girdiği, Mars araçlarından veri aktarımının uydu iletişimi mantığı üzerinden ilerlediği açıklanmıştır. Bu tür çalışmaların ileride daha fazla gündemde olacağı ve daha çok alt başlık açılacağı öngörülmüştür.

Mobil donanım konusunda ARM işlemci ailesinin mobil cihazlarda yaygın olarak kullanıldığı, bunun nedeninin ARM'ın RISC (Reduced Instruction Set Computing) mimarisini kullanması olduğu açıklanmıştır. Bir öğrenci ARM mimarisi, sinetron (Synopsys?) ve microcontroller örneği vermiş, ardından ARM'ın hangi instruction set'i kullandığı sorulduğunda RISC cevabı alınmıştır. Hoca, iki temel komut seti mimarisi olduğunu (RISC ve CISC) açıklamış, ARM'ın RISC kullanmasının temel avantajının daha az enerji tüketimi olduğunu vurgulamıştır. Daha temel ve basit komut seti kullandığı için enerji tüketiminin azaldığı, ancak performans açısından bazı karmaşık hesaplamalarda CISC'in bir tık daha iyi olabileceği belirtilmiştir. Bataryanın doğrudan bilgisayar mühendisliği çalışma alanı olmadığı, ancak mobil donanımda kritik bir unsur olduğu, özellikle telefonlarda pil ömrünün çok önemli olduğu söylenmiştir.

Akıllı saatlerde boyut ve enerji tüketiminin minimuma indirilmesi gerektiği, bu nedenle üreticilerin çeşitli çözümler geliştirdiği anlatılmıştır. Bir öğrencinin katlanabilir ekranlar ve 5G çipleri örneğini mobil donanım alanına vermesi üzerine hoca, bu örneklerin uygun olduğunu belirtmiştir. İşlemci, bellek, SD kart gibi telefonun içindeki bileşenlerin hepsinin mobil donanım kapsamında değerlendirilebileceği, bunların geliştirilmesi üzerine yapılan çalışmaların mobil donanım başlığı altında incelenebileceği söylenmiştir. Ekran teknolojilerinde kapasitif ve rezistif ekranlar, dokunmatik ekranlar üzerine farklı araştırmaların sürdüğü belirtilmiştir.

Apple'ın cihazlarında ana işlemciye ek olarak bir co-processor (yardımcı işlemci) kullandığı, bunun sensörlerden gelen verileri okumak için tasarlandığı detaylı olarak açıklanmıştır. Saniyede 100-200 defa sensör okuma gereksiniminde ana işlemci sürekli uyanık kalmak zorunda kalmakta, bu da pil tüketimini ciddi şekilde artırmaktadır. Co-processor, düşük enerjiyle sensör verilerini okur, ana işlemci sadece kritik görevler için uyanır. Telefon kapalıyken bile bu yardımcı işlemci sayesinde enerji tasarrufu sağlandığı vurgulanmıştır. Bir öğrenci cihazların birbirine daha hızlı bağlanabilmesi için bir işlemci kullanıldığını tahmin etmiş, ancak asıl amacın bu olmadığı belirtilmiştir.

İşletim sistemi kavramı tanıtılmış, bir işletim sisteminin üzerinde çalıştığı donanımın kaynaklarını yöneten temel yazılım olduğu açıklanmıştır. Farklı işletim sistemi türleri sıralanmıştır: masaüstü işletim sistemleri, sunucu işletim sistemleri, gerçek zamanlı işletim sistemleri, mobil işletim sistemleri. Bir öğrenci giyilebilir araçlar için işletim sistemi örneği (Tizen) vermiş, bunun da gömülü işletim sistemi (embedded operating system) adı altında değerlendirildiği belirtilmiştir. Her cihaz için mutlaka bir işletim sistemi olmasının gerekmediği, ancak gömülü cihazların yavaş yavaş daha fazla yetenek kazanmasıyla küçük işletim sistemlerine ihtiyaç duyulacağı söylenmiştir. Bir paradoks olarak vurgulanan nokta, spesifik bir görevi olan bir cihazın neden işletim sistemine ihtiyaç duyacağıdır; cevap olarak bu cihazların birden fazla görevi yerine getirmeye başlaması gösterilmiştir. Bir öğrencinin ROS (Robotic Operating System) örneği vermesi üzerine, robotik sistemlerde çalışan işletim sistemlerinin robotların özel donanım yapısına göre tasarlandığı açıklanmıştır. Mobil işletim sistemi tasarımında Linux kernelinin kullanıldığı, ancak kernel dışındaki yeteneklerin donanıma göre şekillendiği vurgulanmıştır.

Donanım tarafında çok çekirdekli işlemcilerin (4+4 yapı: 4 düşük güçlü, 4 yüksek performanslı çekirdek) kullanıldığı, Android'in bu çekirdekleri duruma göre yönetebildiği belirtilmiştir. Ancak asıl kritik noktanın yazılım tarafı olduğu, Android'in Doze mekanizması sayesinde telefonun hareketsiz kaldığı anları tespit edip arka plan sorgulamalarını azalttığı açıklanmıştır. WhatsApp gibi mesaj uygulamalarının sunucuyu yoklama sıklığı örnek verilmiş; normalde saniyede bir olan bu sıklık, Doze devreye girdiğinde yarım dakika veya dakikaya çıkabilir. Android 7 ile birlikte Doze'un makine öğrenmesi ile daha akıllı hale getirildiği, cihazın yanında taşınıp taşınmadığının tespit edilebildiği belirtilmiştir. Android kullanıcısının günlük hareket miktarının takip edilebildiği, bu sayede pil tasarrufunun optimize edildiği vurgulanmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
