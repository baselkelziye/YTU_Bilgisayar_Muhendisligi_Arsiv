# Veri İletişimi Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

### Genel Bilgiler

* **Ders:** Veri İletişimi
* **Hoca:** Dr. Furkan Çakmak
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021

Bu dizin, Veri İletişimi ders kayıtlarının altyazılarını, altyazılardan çıkarılmış çalışma özetlerini ve PDF formatındaki çalışma dosyalarını içerir.

## Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Sinyaller, Analog/Dijital Ayrımı, Genlik-Frekans-Faz ve Gürültü | [Özet](altyazi_ozetleri/ders_1.md) | [PDF (İndir)](ders_1.pdf) |
| **Ders 2** | İletim Ortamları, Paralel/Seri İletim, Simplex/Half-Duplex/Full-Duplex | [Özet](altyazi_ozetleri/ders_2.md) | [PDF (İndir)](ders_2.pdf) |
| **Ders 3** | Multiplexing, FDM/TDM/WDM, Hata Tespiti ve Hata Düzeltme | [Özet](altyazi_ozetleri/ders_3.md) | [PDF (İndir)](ders_3.pdf) |
| **Ders 4** | Data Link Control, Framing, Flow Control, Stop-and-Wait ve Sliding Window | [Özet](altyazi_ozetleri/ders_4.md) | [PDF (İndir)](ders_4.pdf) |
| **Ders 5** | HDLC Frame Yapısı, Flag, Stuffing, I/S/U Frame Türleri | [Özet](altyazi_ozetleri/ders_5.md) | [PDF (İndir)](ders_5.pdf) |
| **Ders 7** | HDLC Çalışma Mekanizması, IEEE 802, Ethernet ve CSMA/CD | [Özet](altyazi_ozetleri/ders_7.md) | [PDF (İndir)](ders_7.pdf) |
| **Ders 8** | IEEE 802.4 Token Bus ve IEEE 802.5 Token Ring | [Özet](altyazi_ozetleri/ders_8.md) | [PDF (İndir)](ders_8.pdf) |
| **Ders 10** | IEEE 802.11 Wi-Fi, CSMA/CA, RTS/CTS ve Kablosuz Ağ Problemleri | [Özet](altyazi_ozetleri/ders_10.md) | [PDF (İndir)](ders_10.pdf) |
| **Ders 11** | WiMAX, Frame Relay, ATM, ADSL ve Geniş Alan/Erişim Teknolojileri | [Özet](altyazi_ozetleri/ders_11.md) | [PDF (İndir)](ders_11.pdf) |
| **Ders 12** | Connectionless/Connection-Oriented Servisler ve Switching | [Özet](altyazi_ozetleri/ders_12.md) | [PDF (İndir)](ders_12.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 6* ve *Ders 9* için altyazı kaydı bulunmamaktadır.

## Derslerin Detaylı Özetleri ve Kazanımları

### Ders 1: Sinyaller, Analog/Dijital Ayrımı, Genlik-Frekans-Faz ve Gürültü

* **Genel Konular:**
  - OSI modelinden fiziksel iletime geçiş
    - Üst katmanlarda paketlenen verinin karşı tarafa ulaşabilmesi için fiziksel ortamda sinyale dönüştürülmesi gerekir.
  - Analog ve dijital sinyal ayrımı
    - Analog sinyal zamanın her anında tanımlıdır; dijital sinyal ayrık değerler üzerinden temsil edilir.
  - Sinyal parametreleri
    - Genlik, frekans ve faz veri kodlama sırasında değiştirilebilen temel büyüklüklerdir.
  - Gürültü ve bozulma
    - Gerçek iletim ortamlarında sinyal zayıflaması ve gürültü kaçınılmazdır.
* **Hocanın Vurgusu:**
  - Sinyal, verinin fiziksel dünyadaki temsilidir.
    - Paketlenmiş veri ancak sinyal haline getirildiğinde ortam üzerinden taşınabilir.
  - Analog/dijital ayrımı değerlerin sürekliliğiyle ilgilidir.
    - Analogda değerler sürekli, dijitalde ayrık yorumlanır.
  - Gürültü baştan hesaba katılmalıdır.
    - Kodlama değerleri birbirinden ayırt edilebilir seçilmelidir.
* **Detaylı Açıklamalar:** Ders, veri iletişiminin fiziksel katman tarafına giriş yapar. Verinin katmanlar boyunca başlıklarla kapsüllenmesi tek başına iletim değildir; son aşamada veri, genlik, frekans veya faz gibi fiziksel özellikleri olan bir sinyal olarak taşınır. Analog sinyaller sürekli değer alırken dijital sinyaller belirli ayrık seviyeler üzerinden yorumlanır. Bu ayrım, iletimde kullanılacak kodlama ve hata dayanımı açısından önemlidir. Gürültü, sıcaklık, elektromanyetik etkiler ve ortam koşulları sinyali bozabileceği için alıcı tarafın doğru yorum yapabilmesi için sinyal seviyeleri açık ayrılmalıdır.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 2: İletim Ortamları ve Veri Aktarım Biçimleri

* **Genel Konular:**
  - Medium kavramı
    - Veri göndericiden alıcıya ulaşana kadar fiziksel veya kablosuz bir ortam içinde taşınır.
  - Paralel ve seri iletim
    - Paralel iletimde birden fazla bit aynı anda farklı hatlardan, seri iletimde bitler tek hat üzerinde sırayla gönderilir.
  - Simplex, half-duplex ve full-duplex
    - İletişimin yönü ve eş zamanlılığı bu üç kavramla açıklanır.
  - Kablolu ve kablosuz ortamlar
    - Bakır, koaksiyel, fiber optik ve kablosuz ortamlar farklı hız, maliyet ve gürültü özelliklerine sahiptir.
* **Hocanın Vurgusu:**
  - Ortam seçimi sadece kablo seçimi değildir.
    - Mesafe, hız, gürültü, maliyet ve altyapı birlikte değerlendirilmelidir.
  - Paralel iletim her zaman üstün değildir.
    - Kısa mesafede avantajlı olabilir; uzun mesafede senkronizasyon ve kablo maliyeti artar.
  - Full-duplex yapı ek fiziksel veya mantıksal düzen gerektirir.
    - Aynı anda iki yönde iletişim, ortamın nasıl paylaşıldığıyla doğrudan ilişkilidir.
* **Detaylı Açıklamalar:** Bu ders fiziksel iletim ortamlarını ve temel veri aktarım biçimlerini açıklar. Medium, sinyalin yol aldığı ortamdır ve ortamın özellikleri iletim başarısını doğrudan belirler. Paralel iletimde aynı anda çok bit gönderilebilse de çok sayıda hatta ihtiyaç duyulur. Seri iletim daha az hatla çalıştığı için uzun mesafelerde daha pratiktir. Simplex tek yönlü, half-duplex sırayla çift yönlü, full-duplex ise aynı anda çift yönlü iletişimi ifade eder. Fiber optik yüksek hız ve düşük elektromanyetik etkilenme avantajı sunarken, kablosuz iletimde parazit, kapsama ve güvenlik sorunları daha belirgin hale gelir.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 3: Multiplexing ve Hata Kontrolü

* **Genel Konular:**
  - Multiplexing
    - Birden fazla veri akışının aynı iletim ortamını paylaşmasını sağlar.
  - FDM, TDM ve WDM
    - Frekans, zaman veya dalga boyu eksenleri kullanılarak akışlar birbirinden ayrılır.
  - Hata tespiti ve hata düzeltme
    - Alıcı taraf, ek kontrol bilgileriyle verinin bozulup bozulmadığını anlamaya çalışır.
  - Parity, checksum, CRC ve Hamming
    - Farklı hata kontrol yöntemleri farklı maliyet ve güvenilirlik düzeyleri sunar.
* **Hocanın Vurgusu:**
  - Multiplexing sınırlı hattı verimli kullanma problemidir.
    - Aynı ortamı paylaşırken akışların birbirine karışmaması gerekir.
  - Hata kontrolü veri iletişiminin doğal parçasıdır.
    - Gürültülü ortamda alıcının veriyi doğrudan doğru kabul etmesi beklenmez.
  - Basit yöntemlerin sınırları bilinmelidir.
    - Parity her hatayı yakalayamaz; CRC daha güçlü hata tespiti sağlar.
* **Detaylı Açıklamalar:** Multiplexing, pahalı veya sınırlı bir iletim hattını birden fazla iletişim için kullandırır. FDM farklı frekans bantları, TDM farklı zaman dilimleri, WDM ise fiber optikte farklı dalga boyları üzerinden ayrım yapar. Dersin ikinci ana ekseni hata kontrolüdür. Parity biti temel bir kontrol sağlar ama çoklu hata örüntülerinde yetersiz kalabilir. Checksum blok seviyesinde özet üretir. CRC polinom tabanlı güçlü bir hata tespit yöntemidir. Hamming kodu gibi yaklaşımlar ise belirli koşullarda hatanın yerini bulup düzeltmeyi hedefler.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 4: Data Link Control, Framing ve Flow Control

* **Genel Konular:**
  - Data link control
    - Veri bağı katmanı framing, akış kontrolü, hata kontrolü ve bağlantı düzenini yönetir.
  - Framing
    - Bit akışının anlamlı frame bloklarına ayrılması gerekir.
  - Flow control
    - Göndericinin alıcının işleyebileceğinden daha hızlı veri göndermesi engellenir.
  - Stop-and-wait ve sliding window
    - Stop-and-wait basit ama verimsiz; sliding window daha yüksek hat kullanımı sağlayan bir yaklaşımdır.
* **Hocanın Vurgusu:**
  - Akış kontrolü hız farkı problemidir.
    - Alıcı tamponları dolarsa veri kaybı oluşabilir.
  - Window mantığı verimliliği artırır.
    - Gönderici birden fazla frame'i onay beklemeden gönderebilir.
  - ACK, NACK ve zaman aşımı güvenilirliği destekler.
    - Hangi frame'in alındığı ve hangisinin yeniden gönderileceği bu bilgilerle izlenir.
* **Detaylı Açıklamalar:** Bu ders veri bağı katmanının frame düzeyindeki kontrol görevlerini inceler. Framing, alıcının bit akışını doğru sınırlara göre ayırmasını sağlar. Flow control, hızlı gönderici ve yavaş alıcı arasındaki dengesizliği yönetir. Stop-and-wait yönteminde her frame için onay beklenir; bu yöntem basittir fakat gecikmeli hatlarda verimsizdir. Sliding window, pencere boyutu kadar frame'in onay beklemeden gönderilmesine izin verir. ACK ve NACK mesajları ile zaman aşımı mekanizmaları güvenilir aktarımın temel araçlarıdır.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 5: HDLC Frame Yapısı ve Stuffing

* **Genel Konular:**
  - HDLC protokolü
    - Veri bağı katmanı için bit yönelimli bir protokol olarak ele alınır.
  - Frame alanları
    - Flag, address, control, information ve FCS alanları frame yapısını oluşturur.
  - Bit stuffing ve byte stuffing
    - Özel kontrol dizilerinin veriyle karışmasını önlemek için kaçış mekanizmaları kullanılır.
  - I-frame, S-frame ve U-frame
    - Veri taşıma, kontrol ve bağlantı yönetimi farklı frame türleriyle yapılır.
* **Hocanın Vurgusu:**
  - Frame sınırları hatasız anlaşılmalıdır.
    - Flag'in veri içinde yanlış yorumlanması tüm frame ayrımını bozabilir.
  - Stuffing ezber değil mantık konusudur.
    - Özel diziler veri olarak geldiğinde protokol bunları ayırt etmelidir.
  - Frame türlerinin görevleri karıştırılmamalıdır.
    - I-frame veri, S-frame kontrol, U-frame yönetim amaçlıdır.
* **Detaylı Açıklamalar:** HDLC, veri bağı katmanında protokol kurallarının somut bir örneğidir. Frame başlangıcı ve bitişi flag ile belirtilir. Ancak flag'e benzeyen bit dizileri veri alanında oluşabilir; bit stuffing bu karışıklığı önlemek için araya ek bit koyar ve alıcı bu biti çıkarır. HDLC'de I-frame esas veriyi taşır. S-frame onay, akış ve hata kontrolü için kullanılır. U-frame ise bağlantı kurma, sonlandırma ve yönetim işlemlerinde görev alır.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 7: HDLC İşleyişi, IEEE 802 ve Ethernet

* **Genel Konular:**
  - HDLC çalışma aşamaları
    - Bağlantı kurma, veri aktarımı ve bağlantı kapatma süreçleri ele alınır.
  - U-frame yönetim komutları
    - Bağlantının başlatılması, kabul edilmesi ve sonlandırılması için kullanılır.
  - IEEE 802 ailesi
    - Yerel ağlarda veri bağı katmanı ve ortam erişim kontrolü standartları tanıtılır.
  - Ethernet ve CSMA/CD
    - Paylaşımlı ortamda hattı dinleme, gönderme, çakışmayı algılama ve yeniden deneme mantığı açıklanır.
* **Hocanın Vurgusu:**
  - HDLC'de bağlantı açıkça yönetilir.
    - Bazı yapılarda taraflardan biri bağlantıyı başlatmak zorundadır.
  - Ethernet'te collision ortam paylaşımından doğar.
    - Aynı anda gönderim yapan istasyonlar çakışma yaratabilir.
  - Backoff mekanizması çakışmaların tekrarını azaltır.
    - Binary exponential backoff bekleme aralığını çakışma sayısına göre büyütür.
* **Detaylı Açıklamalar:** Dersin ilk kısmı HDLC'nin çalışma düzenine odaklanır. U-frame'ler bağlantı yönetiminde, I-frame'ler veri aktarımında, S-frame'ler ise kontrol görevlerinde kullanılır. İkinci kısım Ethernet'e geçer. Ethernet paylaşımlı ortamda çalıştığında iki istasyon aynı anda gönderim yapabilir ve collision oluşabilir. CSMA/CD, önce ortamı dinleme, sonra gönderme ve çakışma olursa bunu algılayıp tekrar deneme yaklaşımıdır. Backoff mekanizması, çakışma sonrası istasyonların rastgele sürelerle beklemesini sağlayarak sürekli aynı çakışmanın yaşanmasını engellemeye çalışır.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 8: Token Bus ve Token Ring

* **Genel Konular:**
  - Token yaklaşımı
    - Token, gönderim hakkını temsil eder ve ortam erişimini sıraya koyar.
  - IEEE 802.4 Token Bus
    - Fiziksel bus üzerinde mantıksal token sırası kurulabilir.
  - IEEE 802.5 Token Ring
    - Token halka üzerinde dolaşır ve veri göndermek isteyen istasyon token'ı kullanır.
  - Öncelik ve monitor mekanizmaları
    - Token kaybı, hatalı frame dolaşımı ve öncelikli erişim gibi durumlar yönetilmelidir.
* **Hocanın Vurgusu:**
  - Token collision'ı azaltmak için kullanılır.
    - Ortamı rastgele kullandırmak yerine gönderim hakkı dolaştırılır.
  - Fiziksel ve mantıksal topoloji farklı olabilir.
    - Token bus bunun iyi bir örneğidir.
  - Token yönetimi ek karmaşıklık getirir.
    - Token kaybı tüm iletişimi etkileyebilir.
* **Detaylı Açıklamalar:** Token tabanlı erişim, Ethernet'teki çakışma problemine farklı bir cevap verir. Ortama çıkma hakkı token ile temsil edilir. Token bus yapısında istasyonlar fiziksel olarak ortak bir hat üzerinde bulunabilir; ancak mantıksal olarak token sırasına göre erişir. Token ring yapısında istasyonlar halka mantığıyla düşünülür ve token sırayla dolaşır. Bu yaklaşım çakışmayı azaltır, fakat token'ın korunması, kaybolduğunda yeniden üretilmesi ve önceliklerin yönetilmesi gibi ek kurallar gerektirir.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 10: IEEE 802.11 ve Kablosuz Ağlar

* **Genel Konular:**
  - Wi-Fi ve IEEE 802.11
    - Kablosuz yerel ağların veri bağı ve fiziksel katman kuralları ele alınır.
  - CSMA/CA
    - Kablosuz ortamda collision detection yerine collision avoidance yaklaşımı kullanılır.
  - RTS/CTS
    - Gönderim öncesi kısa kontrol mesajlarıyla ortamın ayrılması sağlanabilir.
  - Hidden ve exposed terminal problemleri
    - Kablosuz kapsama alanlarının farklılığı çakışma veya gereksiz bekleme sorunları doğurabilir.
  - Bluetooth
    - Kısa mesafeli kablosuz iletişim için farklı bir teknoloji ailesi olarak değerlendirilir.
* **Hocanın Vurgusu:**
  - Kablosuz ortam kablolu Ethernet gibi davranmaz.
    - Çakışmanın fiziksel olarak nerede gerçekleştiğini algılamak zordur.
  - CSMA/CD ve CSMA/CA karıştırılmamalıdır.
    - Biri çakışmayı algılamaya, diğeri çakışmadan kaçınmaya odaklanır.
  - RTS/CTS yardımcı ama maliyetli bir mekanizmadır.
    - Özellikle hidden terminal probleminde faydalıdır.
* **Detaylı Açıklamalar:** Kablosuz ağlarda ortam havadır ve istasyonların birbirini duyma durumu konuma göre değişir. Bu nedenle klasik Ethernet'teki CSMA/CD doğrudan uygulanamaz. CSMA/CA, istasyonların ortamı dinleyip uygun bekleme süreleriyle gönderime başlamasına dayanır. RTS/CTS mesajları, alıcı ve gönderici çevresindeki istasyonlara ortamın kullanılacağını bildirerek çakışma ihtimalini azaltır. Hidden terminal probleminde iki istasyon birbirini duymadığı halde aynı alıcıya gönderim yapabilir. Exposed terminal probleminde ise bir istasyon ortamı meşgul sanıp aslında yapılabilecek bir gönderimi erteleyebilir.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 11: Geniş Alan ve Erişim Teknolojileri

* **Genel Konular:**
  - WiMAX
    - Geniş kapsama hedefleyen kablosuz erişim teknolojisi olarak ele alınır.
  - Frame Relay
    - WAN ortamlarında sanal devrelerle hızlı veri iletimi sağlayan bir yaklaşım olarak anlatılır.
  - ATM
    - Sabit boyutlu hücrelerle farklı trafik türlerini taşıma fikrine dayanır.
  - ADSL
    - Telefon hattı altyapısı üzerinden asimetrik veri iletimi sağlar.
  - Sanal devre mantığı
    - Fiziksel özel hat olmadan mantıksal bağlantı kurulabilir.
* **Hocanın Vurgusu:**
  - Teknolojiler hangi probleme çözüm sunduklarıyla anlaşılmalıdır.
    - Sadece isim ve hız ezberi yeterli değildir.
  - Sanal devre fiziksel devre değildir.
    - Paylaşımlı altyapı üzerinde özel bağlantı varmış gibi davranır.
  - Hız tek başarı ölçütü değildir.
    - Kapsama, kalite, maliyet ve altyapı gereksinimi de önemlidir.
* **Detaylı Açıklamalar:** Bu ders öğrenci sunumları üzerinden farklı ağ teknolojilerini karşılaştırır. WiMAX geniş kapsama ve servis kalitesi gibi hedeflerle Wi-Fi'den ayrılır. Frame Relay, router'lar ve servis sağlayıcı ağı arasında sanal devreler kurarak WAN üzerinde veri taşımayı sağlar. ATM sabit boyutlu hücrelerle ses, görüntü ve veri gibi farklı trafik türlerini aynı altyapıda taşımayı amaçlar. ADSL ise mevcut telefon hattı üzerinden indirme yönüne daha fazla bant genişliği ayıran asimetrik bir erişim teknolojisidir.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.

### Ders 12: Servis Türleri ve Switching

* **Genel Konular:**
  - Connectionless ve connection-oriented servisler
    - Bağlantısız yapıda ön bağlantı kurulmaz; bağlantı yönelimli yapıda aktarım öncesi yol veya bağlantı mantığı vardır.
  - Switching
    - Verinin ağ içindeki ara düğümler üzerinden hedefe taşınması problemidir.
  - Circuit switching
    - İletişim süresince ayrılmış bir yol kurulur.
  - Packet switching
    - Veri paketlere bölünür ve ağ kaynakları daha esnek paylaşılır.
  - Datagram ve virtual circuit
    - Datagram paketleri bağımsız taşır; virtual circuit önce mantıksal bir yol kurar.
* **Hocanın Vurgusu:**
  - Servis türü ve switching birlikte düşünülmelidir.
    - Bağlantının kurulup kurulmadığı paket davranışını etkiler.
  - Circuit switching kaynak ayırır, packet switching kaynak paylaşır.
    - Bu fark verimlilik ve gecikme açısından belirleyicidir.
  - Datagram ve virtual circuit farklı paket anahtarlama mantıklarıdır.
    - Biri bağımsız paketlere, diğeri önceden belirlenen mantıksal yola dayanır.
* **Detaylı Açıklamalar:** Son derste veri iletişimi konuları ağ katmanı sınırına yaklaşarak servis türleri ve anahtarlama yöntemleriyle tamamlanır. Connectionless servislerde her paket bağımsız ele alınabilir. Connection-oriented servislerde aktarım öncesinde bağlantı veya yol kurma fikri vardır. Circuit switching telefon ağı benzeri ayrılmış devre mantığına dayanır; kaynaklar iletişim boyunca o bağlantıya tahsis edilir. Packet switching'de veri paketlere bölünür ve ağ kaynakları daha verimli paylaşılır. Datagram modelinde paketler farklı yollardan gidebilir ve farklı sırada varabilir. Virtual circuit modelinde ise önce mantıksal bir yol belirlenir, paketler bu yol üzerinden taşınır.
* **NotebookLM Çalışma Notu:** İsterseniz ilgili `.srt` dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek bu ders üzerinde daha ayrıntılı çalışabilirsiniz.
