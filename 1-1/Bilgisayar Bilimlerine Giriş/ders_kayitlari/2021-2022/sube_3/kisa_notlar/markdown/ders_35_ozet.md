# Ders 35 Çalışma Özeti

## Genel Konular

- İşletim sisteminin işlevleri
  - İşletim sistemi, bilgisayar donanımını kullanıcıya ve uygulamalara hizmet verir hâle getiren altyapı yazılımıdır.
  - Slayttaki dört işlev: bilgisayarın çalışmasını gözetmek, dosyaları saklayıp geri getirmek, programları çalıştırma için zamanlamak (scheduling), programların birlikte çalışmasını koordine etmek (ekrandan, 00:15:00).
  - Proses: diskte duran programın işletim sistemi tarafından çalıştırılan hâlidir. Prosesler sistem kaynaklarını ortak kullanır; çakışmaları işletim sistemi önler.
- Paylaşımlı hesaplamanın tarihçesi (ekrandan, 00:20:00)
  - Batch processing (toplu işleme): kullanıcı programını, verisini ve çalıştırma yönergelerini (job) verir; işler kuyrukta sırayla çalışır, sonuç alınır. Kullanıcı ile makine arasında etkileşim yoktur (ekrandan, 00:25:00).
  - Operatör ve job control language: işleri kullanıcı yerine operatör yükler; kablo ve anahtar ayarları yerine yönergeler (JCL) kullanılır, ara bekleme (overhead) azalır.
  - Interactive processing: kullanıcı iş çalışırken terminalden etkileşir. Bunun için real-time processing gerekir: bir adımın sonucu bir sonraki adımdan önce üretilmelidir.
  - Time-sharing / multitasking: her işe sırayla kısa bir zaman dilimi (time slice) verilir; dönüşümlü çalışma, işler aynı anda çalışıyormuş izlenimi verir. Bu, multiprogramming ile gerçeklenir. Tek kullanıcının kendi prosesleri için aynı mantık multitasking adını alır.
  - Çok işlemcili makineler: işleri işlemcilere dinamik dağıtmaya load balancing denir; bir işi parçalara bölüp farklı işlemcilerde çalıştırmak senkronizasyon ve kaynak paylaşımı sorunları doğurur.
- Yazılım sınıflandırması (ekrandan, 00:35:00)
  - Software → Application (uygulama) ve System (sistem) yazılımı.
  - System → Utility (hizmet yazılımı) ve Operating system.
  - Operating system → User Interface ve Kernel.
  - Utility örnekleri: disk biçimlendirme (formatlama), CD yazma, dosya sıkıştırma. Zamanla uygulama yazılımı olan işler işletim sistemiyle gelen hizmet yazılımına dönüşmüştür.
- İşletim sisteminin bileşenleri (ekrandan, 00:40:00)
  - User Interface: kullanıcıyla iletişim. Metin tabanlı kabuk (shell) ve grafik kullanıcı arayüzü (GUI). Örnekler: Windows komut satırı, Unix kabukları, macOS Terminal; GUI tarafında Windows Explorer, macOS arayüzü, KDE, GNOME (X Window).
  - Kernel: temel işlevler. File manager, device drivers, memory manager, scheduler ve dispatcher.
  - File manager: dosyaların saklanması, okunması, yazılması, silinmesi ve düzenlenmesi. Directory (folder): dosya ve alt dizinleri gruplayan yapı; directory path: iç içe dizinler dizisi (ekrandan, 00:45:00).
  - Device driver: ekran, klavye, ses kartı, yazıcı gibi cihazların kullanılabilmesini sağlayan, cihaza özgü sinyalleşmeyi bilen yazılım.
  - Memory manager: RAM'i uygulamalar arasında paylaştırır. Fiziksel bellek yetmezse diskte bir alanı bellek gibi kullanır (sanal bellek, paging): çalışan prosesin blokları belleğe, çalışmayanlarınki diske taşınır.
- Bilgisayarın açılması (bootstrapping) (ekrandan, 00:55:00)
  - CPU açıldığında belleğin başındaki adresten okumaya başlar. Bu bölge ROM'dur ve orada boot loader bulunur.
  - Adım 1: makine bellekte hazır duran bootstrap programını çalıştırır; işletim sistemi diskte durur.
  - Adım 2: boot loader işletim sistemini ana belleğe aktarır ve denetimi ona verir. Kernel ayağa kalkınca scheduler, bellek yöneticisi, disk yöneticisi ve aygıt sürücüleri çalıştırılır.
  - ROM salt okunur ve kalıcıdır, elektrik kesilince silinmez. İçeriği anakart üreticisi yazar; yeniden programlanabilen ROM ile güncellemeye firmware update denir.
  - İşletim sisteminin tamamı ROM'a yazılmaz, çünkü ROM pahalı ve küçüktür. Araç bilgisayarı gibi bazı gömülü sistemlerde küçük işletim sistemi ROM'da durabilir.
- Proses yönetimi (ekrandan, 01:05:00)
  - Proses durumu (state): program sayacının değeri, CPU yazmaçlarının değerleri, prosesin kullandığı bellek adresleri vb.
  - Scheduler: yeni prosesleri proses tablosuna ekler, biten prosesleri tablodan çıkarır (Windows'ta Görev Yöneticisi'ndeki liste buna benzer).
  - Dispatcher: proses tablosundaki proseslere zaman dilimi ayırır. Zaman diliminin sonu bir kesme (interrupt) ile bildirilir; interrupt handler çalışan prosesin durumunu kaydeder, scheduler'ın seçtiği sıradaki prosesin durumunu yükler (process switch) (ekrandan, 01:10:00).
- Kaynak paylaşımı: semafor ve kritik bölge
  - Paylaşılamayan bir kaynağı (ör. tek yazıcı) iki proses kesikli çalışma sırasında aynı anda isteyebilir: "boş mu?" sorusu ile "rezerve et" adımı arasında kesme gelirse ikisi de kaynağı aldığını sanır.
  - Çözüm: kaynağın durumunu tutan bayrak (semafor) ve kontrol-ayarla işleminin bölünmez (atomik) yapılması, ör. tek komutluk test-and-set.
  - Critical region: bölünmeden yürütülmesi gereken kod bölgesi. Herhangi bir anda kritik bölgede yalnız bir proses bulunabilir (mutual exclusion).
- Deadlock (kilitlenme) (ekrandan, 01:15:00)
  - Prosesler birbirinin devam etmesini engeller. Örnek: A yazıcıyı tutup CD-ROM'u, B CD-ROM'u tutup yazıcıyı bekler.
  - Üç koşul: (1) paylaşılamayan kaynaklar için yarış, (2) kaynakların parça parça istenmesi, (3) ayrılmış bir kaynağın zorla geri alınamaması. Üçü birlikte oluşursa deadlock olur.
  - 3. koşula karşı deadlock detection and correction: kilitlenme fark edilir, bir prosesin kaynağı zorla alınır ya da proses sonlandırılır (fork ile proses tablosunu dolduran prosesler örneği).
  - 2. koşula karşı (derste deadlock avoidance diye anıldı): proses gereken bütün kaynakları tek seferde ister.
  - 1. koşula karşı spooling: yazıcı işleri bir kuyruğa (diskteki bir alana) yazılır, sırayla basılır; paylaşılamayan kaynak paylaşılıyor gibi görünür.
- İşletim sistemi güvenliği (ekrandan, 01:25:00)
  - Dış saldırılar: kullanıcı adı ve şifre ile kimlik doğrulama; her sistemde tüm yetkilere sahip bir süper kullanıcı (Windows'ta Administrator, Unix'te root) vardır. Zayıf şifre ve tuş kaydeden (sniffing/keylogger) kötü niyetli yazılımlar risktir; karşı önlem denetim (auditing) yazılımıdır.
  - İç saldırılar: bir prosesin başka proseslerin bellek alanına erişmesi. Modern CPU'larda privileged mode / non-privileged mode ayrımı vardır; açılışta ayrıcalıklı kipte başlanır, işletim sistemi yüklendikten sonra normal prosesler ayrıcalıksız kipte çalışır ve bellek sınırlarını değiştiremez.
- Ağ sınıflandırmaları (ekrandan, 01:45:00)
  - Kapsam: PAN (telefon-kablosuz kulaklık, kablosuz fare), LAN (bina), MAN (bir üniversitenin kampüslerini birleştiren ağ), WAN (iller, kıtalar).
  - Sahiplik: kapalı (closed) ve açık (open) ağ.
  - Topoloji: bus (Ethernet) ve star (merkezde erişim noktası olan kablosuz ağlar).
- Erişim protokolleri (ekrandan, 01:50:00)
  - CSMA/CD (Ethernet): hat sessizse mesaj gönderilir; çarpışma olursa iki taraf da susar, rastgele süre bekleyip tekrar dener.
  - CSMA/CA (Wi-Fi, IEEE 802.11): hat boşsa bir süre daha beklenir, yine boşsa gönderilir.
  - Hidden terminal problem: engel ya da menzil yüzünden istasyonlar birbirini duyamaz ve aynı anda erişim noktasıyla konuşabilir. Çözüm: önce istek gönderilir, erişim noktasından onay gelirse konuşulur.
- Ağları birleştirme (ekrandan, 01:55:00)
  - Repeater: bütün trafiği körlemesine diğer tarafa aktarır.
  - Bridge: mesajı yalnız hedef diğer taraftaysa geçirir.
  - Switch: birden çok bus'ı bağlayan, birden çok köprü gibi çalışan cihaz.
  - Router: farklı türden (heterojen) ağları bağlar, yönlendirme algoritmalarıyla paketin hangi yoldan gideceğine karar verir. Ağlardan oluşan ağa internet denir.
- Prosesler arası iletişim (IPC) ve dağıtık sistemler
  - Client-server: sunucu sürekli çalışır, istemciler istek başlatır (ör. yazıcı sunucusu). Peer-to-peer: her katılımcı hem istemci hem sunucudur (ör. torrent).
  - Dağıtık sistem: parçaları ağla bağlı farklı bilgisayarlarda çalışan sistem. Yakın makineler: cluster computing; daha dağınık: grid computing; dünyaya yayılmış veri merkezleri: cloud computing.
- İnternet (ekrandan, 02:05:00)
  - The Internet: dünyayı saran internet. Amaç yerel felaketlerden etkilenmeyen bir bağlantı yöntemiydi; akademik projeden ticari yapıya dönüştü.
  - ISP katmanları: Tier-1 (omurga, kıtalararası), Tier-2 (bölgesel), access ISP / Tier-3 (son kullanıcıya erişim). Uç sistemler telefon, sunucu, IoT sensörü olabilir.
  - IP adresi: 32 ya da 128 bitlik desen, genellikle noktalı ondalık gösterimle yazılır; dört adet 8 bitlik alan, her biri 0-255. Örnek: `193.140.4.1` (ekrandan, 02:10:00). Adres yetersizliği yerel (özel) IP'ler ve IPv6 (128 bit) ile aşılır.
  - Domain name, top-level domain (`.com`, `.edu`, `.tr` vb.), DNS, name server, DNS lookup: alan adının IP karşılığı sorgulanır; bilmeyen sunucu üst kademeye sorar.
  - ICANN: IP adreslerini ISP'lere dağıtır, alan adlarının kaydını gözetir (ekrandan, 02:15:00).
- İnternet uygulamaları
  - E-posta: SMTP (gönderme), POP3 ya da IMAP (alma); ASCII dışı karakterler MIME ile dönüştürülür.
  - FTP (dosya aktarımı), Telnet ve SSH (uzak terminal).
  - Yeni uygulamalar: VoIP, internet radyosu (N-unicast, multicast), on-demand streaming ve CDN (anycast): içerik kullanıcıya yakın kopyadan sunulur (ekrandan, 02:20:00).
- World Wide Web
  - HTTP, hipermetin bağlantılarıyla birbirine bağlı belgeler; URL: protokol, alan adı (alt alan), dizin yolu ve belge adı.
  - HTML: etiketlerle biçimlenen belge (`<html>`, `<head>`, `<title>`, `<body>`, `<h1>`, `<p>`); bağlantı `href` özelliğiyle verilir (ekrandan, 02:25:00).
  - XML: etiketleri kullanıcı tanımlar; derste bir müzik dizesi XML ile kodlandı.
  - İstemci tarafında JavaScript gibi küçük işlevler, sunucu tarafında veriyle çalışan uygulamalar yer alır.
- İnternet protokolleri ve katmanlar (ekrandan, 02:30:00)
  - Kargo benzetmesi: paket farklı uçaklardan geçerek hedefe varır.
  - Dört katman (OSI'nin yedi katmanının sadeleştirilmiş hâli): application, transport, network, link.
  - TCP: bağlantılı, karşı tarafın onayını alır, güvenilir (e-posta). UDP: bağlantısız, onay beklemez, hızlı (DNS sorgusu, VoIP).
- Ağ güvenliği (ekrandan, 02:40:00)
  - Saldırılar: malware (virüs, solucan, truva atı, casus yazılım, phishing yazılımı), denial of service (DDoS), spam.
  - Korunma: firewall, spam filtresi, proxy sunucu, antivirüs.
  - Şifreleme: FTPS, HTTPS gibi güvenli sürümler; açık anahtarlı şifreleme: herkes açık anahtarla şifreler, yalnız özel anahtar sahibi çözer (ekrandan, 02:50:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Proses kavramı
  - Bütün işletim sistemi konuları proses üzerine kurulduğu için en başta tanımlandı: programın çalışan hâli.
- İşletim sisteminin özü kernel'dır
  - Kullanıcı kernel'a doğrudan dokunamaz, yalnız kullanıcı arayüzü üzerinden etkileşir; aksi donanım yönetimine müdahale olur.
- Sanal belleğin bedeli
  - Disk bellek gibi kullanılınca bellek erişim hızı disk hızına iner; aşırı kullanımda performans çöker.
- Kritik bölgede aynı anda tek proses
  - Semaforun doğru çalışması için kontrol ve ayırma işlemi bölünmez olmalı, kritik bölgede bir anda yalnız bir proses bulunmalıdır.
- Deadlock'ın üç koşulu
  - Üç koşul birlikte oluşursa deadlock kesin oluşur; çözüm, işletim sisteminin bu koşullardan birini engellemesidir.
- TCP ve UDP seçimi
  - Eksik paket kabul edilemiyorsa TCP, hız önemliyse ve kayıp tolere edilebiliyorsa UDP.

## Kısa Tekrar Notları

- İşletim sistemi işlevleri: gözetim, dosya saklama, zamanlama, koordinasyon.
- Batch → interactive (real-time) → time-sharing (multiprogramming) → çok işlemcili (load balancing).
- Yazılım: uygulama ve sistem; sistem: utility ve işletim sistemi; işletim sistemi: user interface ve kernel.
- Kernel: file manager, device drivers, memory manager, scheduler, dispatcher.
- Boot: ROM'daki boot loader işletim sistemini diskten belleğe yükler ve denetimi ona verir.
- Scheduler proses tablosunu yönetir; dispatcher zaman dilimi verir; dilim sonu interrupt ile bildirilir.
- Semafor + atomik test-and-set + kritik bölge = karşılıklı dışlama.
- Deadlock koşulları: paylaşılamayan kaynak yarışı, parça parça istek, zorla geri alamama.
- Çareler: tespit ve düzeltme (zorla alma), bütün kaynakları baştan isteme, spooling.
- Ağ kapsamı: PAN, LAN, MAN, WAN; topoloji: bus (Ethernet), star (Wi-Fi).
- CSMA/CD Ethernet'te, CSMA/CA Wi-Fi'da; gizli terminal problemi istek-onay ile çözülür.
- Repeater < bridge < switch; router heterojen ağları bağlar.
- IP adresi 32/128 bit; DNS alan adını IP'ye çevirir; ICANN adres ve alan adı dağıtımını gözetir.
- Katmanlar: application, transport, network, link. TCP güvenilir/bağlantılı, UDP hızlı/bağlantısız.
- Açık anahtarla şifrelenen mesajı yalnız özel anahtar sahibi çözer.

## Detaylı Açıklamalar

- Bu derste yazılan kod yoktur; içerik ders kitabının (Brookshear, Computer Science: An Overview, 11. baskı) 3. ve 4. bölüm slaytlarıyla anlatıldı (ekrandan, 00:10:00).
- Tarihçe bölümünde hoca ilk bilgisayarlardaki kullanım modelini bir maç kuyruğuna benzetti: kullanıcı randevu alır, sırası gelince makineyi belirli bir süre tek başına kullanır, kartlarını okutur, ayarlarını yapar ve sonucu alır. Süre aşılırsa sıradaki kullanıcının zamanından yenir. Makineler hızlandıkça bu model verimsizleşti, önce operatör, sonra yazılım bu işi devraldı. Operatörün işlerini yapan yazılımların bütünü bugün işletim sistemi dediğimiz şeydir.
- Time-sharing örneğinde her işe beş dakikalık (sonra beş saniyelik) dilimler verildi: on dakikalık iş iki dilim, kısa bir iş tek dilim kullanır. Dönüşümlü çalışma sayesinde kuyruktaki herkesin toplam beklemesi azalır.
- Sanal bellek örneği: bilgisayarda 4 GB bellek varken çalışan uygulamalar toplam 8 GB isterse, bellek yöneticisi diskte 4 GB'lık bir dosyayı bellek gibi kullanır. Sırası gelen prosesin verisi belleğe alınır, duran prosesinki diske yazılır. Adreslenebilir alan mimariyle sınırlı olduğundan bu "sonsuz bellek" anlamına gelmez.
- Açılış sürecinde hoca ROM'u "taşa kazınmış" bir tablete benzetti: içerik elle çakılmış gibidir, elektrik kesilince silinmez. ROM yeniden yazılırken elektrik kesilirse bilgisayar açılamaz hâle gelir ("taş olur") ve ancak ROM'un donanımsal olarak yeniden programlanmasıyla kurtarılabilir.
- Dispatcher'ın işi bir kronometreye benzetildi: prosese 10 ms verilir, süre dolunca kesme gelir, interrupt handler prosesin "anlık fotoğrafını" (durumunu) kaydeder ve sıradaki prosesin fotoğrafını yükler. Fotoğraflar hızlı oynatılınca film gibi akan görüntü oluşması gibi, prosesler de aynı anda çalışıyormuş gibi görünür.
- Semafor örneğinde B prosesi (Excel) yazıcının boş olduğunu öğrenir ama bayrağı ayarlayamadan kesme gelir; A prosesi (Word) bayrağı boş görüp ayarlar ve yazdırmaya başlar. B yeniden çalışınca kaldığı yerden devam edip yazıcıyı kullanmaya kalkar ve çakışma olur. Kontrol ve ayarlamanın tek bölünmez komut olması bunu engeller.
- Deadlock'ın tren yollarından gelen bir problem olduğu belirtildi: iki tren birbirinin geçeceği yolu tuttuğunda ikisi de ilerleyemez.
- Ağlar bölümünde bus yapısındaki iletim zarf benzetmesiyle anlatıldı: mesajın üzerine alıcı yazılır, herkes alır ama yalnız alıcı ilgilenir. Çarpışmada iki taraf rastgele süre bekler (ör. 10 ms ve 8 ms); kısa bekleyen önce gönderir, diğeri hattı dolu bulup bekler.
- Router örneğinde doğrudan bağlantı çok yoğunsa paketin başka router'lar üzerinden daha hızlı bir yoldan gönderilebileceği gösterildi.
- XML örneğinde 2/4'lük bir ölçü kodlandı: bir sekizlik es ve üç sekizlik Sol notası ($4 \times \frac{1}{8} = \frac{1}{2}$), ikinci ölçüde bir ikilik Mi notası ($\frac{1}{2}$). Böylece müzik bilgisi makinenin okuyabileceği etiketli bir yapıya dönüştürüldü.
- TCP taahhütlü mektuba, UDP kapı kapı broşür dağıtan kuryeye benzetildi: TCP teslimi garanti edip bildirir; UDP gönderir ve sonucu umursamaz ama aynı anda çok mesaj iletir.
- DDoS'ta farkında olmadan kurulmuş uyuyan yazılımlar bir komutla belirli bir sunucuya saniyede binlerce istek göndererek onu boğar. Proxy sunucu ise iç ağ ile dış dünya arasında aracıdır; dış taraf iç ağdaki gerçek makineyi bilmez.
- Ders sonrası notlar:
  - Hoca "firmware"i "firma yazılımı" diye açıkladı; doğrusu İngilizce "firm" (sabit, kalıcı) sözcüğünden gelir ve donanımla yazılım arasındaki kalıcı yazılımı anlatır.
  - Hoca yeniden programlanabilir ROM için "AppROM, elektronik programlanabilir ROM" dedi; doğrusu EPROM / EEPROM'dur (Electrically Erasable Programmable ROM).
  - Hoca Unix kabukları için altyazıda bozuk geçen adları saydı; bunlar Bourne Again Shell (bash), C Shell (csh) ve Korn Shell (ksh)'dir.
  - Hoca HTML'in XML'in bir alt kümesi olduğunu söyledi; doğrusu HTML SGML kökenlidir, XML'e uyan sürümü XHTML'dir.
  - Hoca SSH'yi "Secure Socket Shell" diye açtı ve SSH'nin Secure Socket Layer ile yapılacağını söyledi; doğrusu SSH "Secure Shell"dir ve kendi şifreleme protokolünü kullanır; SSL/TLS HTTPS gibi protokollerde kullanılır.
  - Hoca sertifika doğrulamasını "açık anahtarla şifrelenen veriyi sertifika tarafı çözer" diye anlattı; dijital imzada ise doğrusu ters yöndedir: imza özel anahtarla atılır, açık anahtarla doğrulanır.
  - Hoca BTK'nın açılımından emin olmadığını söyledi; açılım Bilgi Teknolojileri ve İletişim Kurumu'dur. `.tr` alan adı yönetiminin ODTÜ'den BTK'ya geçişi büyük olasılıkla 2022'de tamamlandı.
  <!-- BELİRSİZ: Hocanın Linux ve macOS dosya sistemleri için söylediği adlar altyazıda "X3", "XFET" diye bozuk geçiyor (00:43:31); Linux için büyük olasılıkla ext3/ext4 kastedildi. macOS büyük olasılıkla HFS+ / APFS kullanır. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
