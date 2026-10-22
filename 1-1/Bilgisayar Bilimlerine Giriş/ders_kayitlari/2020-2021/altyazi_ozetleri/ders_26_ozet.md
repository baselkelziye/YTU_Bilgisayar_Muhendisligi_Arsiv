# Ders 26 Çalışma Özeti

## Genel Konular

- Çekirdeğin görevleri (önceki dersten devam)
  - Süreç yönetimi (process management), bellek yönetimi (memory management), dosya yönetimi (file management), giriş-çıkış yönetimi (I/O management), ağ yönetimi (network management) ve aygıt sürücüleriyle (device driver) iletişim.
- Sayfalama (paging) ve sanal bellek (virtual memory)
  - RAM yetmediğinde ikincil depolamada (secondary storage) bir sanal bellek oluşturulur. Bu sanal bellek sayfalama yaklaşımıyla çalışır.
  - Örnek: 4 GB RAM ile 8 GB alan gerektiren bir program çalıştırılacaksa programın bir kısmı RAM'de, bir kısmı ikincil depolamada tutulur. Gerektikçe RAM ile ikincil depolama arasında veri alışverişi yapılır. Böylece RAM'den büyük programlar da çalıştırılabilir.
  - Veri, birkaç yüz byte ya da birkaç kilobyte büyüklüğündeki sayfalara (page) bölünür. Bu sayfaları yöneten bellek yöneticisidir (memory manager).
- Firmware
  - Cihazın işletim sistemi olmadan temel giriş-çıkış işlemlerini yapmasını ve açılış (boot) sırasında işletim sistemini yüklemek için gereken temel işleri yapmasını sağlayan yazılımdır.
  - Firmware güncellemesi, donanımda var olan ama kullanılamayan yeteneklerin kullanılabilmesini sağlar. Örnek: akıllı televizyonlara gelen güncellemeler. Android'de donanım çoklu dokunmayı (multi-touch) desteklediği hâlde bu yetenek sonradan kazandırılmıştı.
  - En bilinen firmware sistemi BIOS'tur (Basic Input Output System). Diğer örnekler: EFI (Extensible Firmware Interface), Open Firmware (Sun, bugün Oracle), Common Firmware Environment.
  - BIOS'ta açılışın hangi aygıttan yapılacağı (boot sırası), RAM ve işlemciyle ilgili ayarlar yapılır.
- Açılış süreci (booting process, bootstrapping) (ekrandan, 00:33:10)
  - Ana bellekte iki kısım vardır: ROM (Read Only Memory) ve uçucu bellek (volatile memory, elektrik olduğu sürece veriyi tutan bellek).
  - ROM'da açılışı yöneten önyükleyici (bootloader) bulunur. İşletim sistemi her zaman diskte durur. Açılış başladığında işletim sistemi diskten uçucu belleğe aktarılır ve bundan sonra bütün işlemler buradan yönetilir.
  - Günümüzde ROM'lar silinip yeniden programlanabilir (tahtada: EEPROM). Bu sınırlı sayıda yapılabilir ve flash bellek tekniğiyle uygulanır. ROM'da yapılan güncellemelere genelde firmware güncellemesi denir.
  - İşletim sistemi ROM'da tutulmaz, çünkü ROM'un boyutu sınırlıdır ve işletim sistemleri yeni özellikler ve güvenlik açıkları için sürekli güncellenir. Gömülü sistemlerde ise işletim sistemi veya onun gibi çalışan program doğrudan ROM'a konabilir.
- Makinenin etkinliklerinin koordinasyonu
  - Süreç (process): bir programın işlemci tarafından çalıştırılacak hâle getirilmiş, çalışan versiyonudur. Örneğin Word bir programdır, çalıştırıldığında bir süreç olur.
  - Süreç durumları (process state): hazır (ready) — işlemciyi beklemeye hazır; bekleyen (waiting) — giriş-çıkıştan, ağdan veya başka bir süreçten cevap bekliyor, işlemciye alınamaz.
  - Süreç tablosu (process table): her sürecin nerede kaldığı, değişkenlerinin son değerleri gibi bilgiler burada tutulur. İşlemci sürece geri döndüğünde kaldığı yerden devam edebilir.
  - Süreç geçişi (process switch, context switch): bir sürecin durumunu süreç tablosuna kaydedip başka bir sürecin durumunu yükleyerek ona geçmek.
  - Zaman dilimleri (time slice) milisaniye ya da mikrosaniye mertebesindedir. Geçişler çok hızlı olduğu için müzik, yazı ve indirme gibi işler kesintisiz çalışıyormuş gibi görünür.
  - Çok sık süreç geçişi performansı düşürür, çünkü her geçişte süreç tablosuna yazma ve okuma yapılır. İnsanların işler arasında sık geçiş yaptığında verimliliğinin düşmesine benzer.
  - Dağıtıcı (dispatcher): kuyruktaki süreçleri yönetir ve her zaman diliminde sıradaki süreci işlemciye verir.
  - Kesme (interrupt): işlemcide çalışan işin kesintiye uğratılmasıdır. Kesme olmadan başka bir işe geçilemez. Kesmeleri karşılayan mekanizmaya kesme işleyici (interrupt handler) denir. Örneğin klavyeye basılan tuş ya da fare tıklaması bir kesme üretir. Kesme gelmezse tuşa basıldığı hâlde bilgi okunmaz.
  - İşlemci bir kesme alınca elindeki komutun döngüsünü (ör. 3 döngü süren bir toplama) tamamlar, durumunu süreç tablosuna kaydeder ve kesmeye karşılık verir. Çoklu programlama bu şekilde, süreç geçişi ve kesmelerle yürür.
  - Tahtadaki tanım: "Interrupts provide an important tool for coordinating a computer's actions with its environment."
- Kilitlenme (deadlock)
  - İki süreç birbirinin elindeki kaynağa ihtiyaç duyar ve ikisi de kendi kaynağını bırakmazsa sistem tıkanır. Örnek: yazıcıyı kullanan süreç CD sürücüyü, CD sürücüyü kullanan süreç yazıcıyı isterse.
  - Paylaşılan kaynakların kilitlenmeye yol açmayacak şekilde yönetilmesi için mekanizmalar vardır.
- Diğer işletim sistemi konuları
  - Çok çekirdekli işlemciler için çok çekirdekli işletim sistemleri tasarlanır. Süreçlerin çekirdekler arasında bilgi değişiminin de koordine edilmesi gerekir. Güncel işletim sistemleri çok çekirdekten faydalanacak şekilde tasarlanır.
  - 64 bit donanım üzerinde 32 bit yazılım çalıştırılabilir, 32 bit donanım üzerinde 64 bit yazılım çalıştırılamaz.
  - Kullanıcı yönetimi: bir PC'de birden fazla kullanıcı hesabı olabilir ve dosyaları birbirinden ayrılır, ama aynı anda yalnızca biri aktif olur. Sunucularda birçok kullanıcı aynı anda bütün kaynaklara erişir. Bu yüzden sunucu işletim sistemleri farklı tasarlanır.
  - Rastgele sayı üretimi (soru üzerine): bir başlangıç noktası (genelde o anki zaman) alınır ve asal sayılar gibi yöntemlerle sayılar üretilir. Farklı yöntemleri vardır.
- Bilgisayar ağları (computer networks)
  - Bilgisayarların veri paylaşmak için birbirine bağlandığı yapıya ağ (network) denir.
  - Ölçeğe göre sınıflandırma:
    - PAN (Personal Area Network): birkaç metrelik kısa mesafe.
    - LAN (Local Area Network): bir bina ya da birbirine yakın binalar (kampüs).
    - MAN (Metropolitan Area Network): orta ölçek, genelde bir şehir.
    - WAN (Wide Area Network): bütün dünyaya yayılan ağ.
  - Genelde açık ağlar (open network) kullanılır. Bazı kuruluşlar kendi kurallarıyla kapalı ağlar (closed network) oluşturur.
  - Topoloji:
    - Bus: bilgisayarlar tek bir hat üzerinden birbirine bağlıdır. Hoca, 1990'lardan beri yaygın olan Ethernet'i örnek verdi.
    - Star: merkezdeki bir cihaz haberleşmeyi yönetir. Örnek: evdeki modem veya kampüsteki kablosuz erişim noktaları (access point).
- Ağları birbirine bağlayan cihazlar
  - Repeater: uzun hatta gücünü kaybeden sinyali yeniden oluşturup iletir. Her sinyali aktarır.
  - Bridge: iki bus ağı birbirine bağlar. Yalnızca diğer ağa gitmesi gereken mesajları aktarır. Örneğin A'dan F'ye (diğer ağda) giden mesajı aktarır, A'dan B'ye (aynı ağda) gideni aktarmaz.
  - Switch: ikiden fazla bus yapısını birleştirir. Aynı ağdaki mesajlar o ağda kalır, başka ağa gidenler oraya yönlendirilir. Ağlar karmaşıklaştığı için günümüzde ağırlıklı olarak switch kullanılır.
  - Router (ekrandan, 01:26:40): farklı yapıdaki (ör. Ethernet ve Wi-Fi) veya farklı adres bloklarındaki ağların haberleşmesini sağlar, paketleri iletir (forward). Kendi yönlendirme tablosunu (forwarding table) kullanarak paketin hangi router'a gideceğine karar verir. Son router paketi kendi yerel ağındaki doğru bilgisayara ulaştırır.
  - Router'lar ağ geçidi (gateway) olarak da adlandırılır: bir ağın dünyadaki diğer ağlara çıkış noktasıdır. Örneğin Davutpaşa kampüsünün çıkışında bir router vardır. Kampüs içi, fakülte, bölüm ve kat düzeyindeki switch'lerle yönetilir.
  - Switch'ler aynı tip ağ içinde cihazları bağlamak ve sanal alanlar (ör. öğrenci, öğretim üyesi, sunucu bölgeleri) oluşturmak için kullanılır. Router'lar farklı tip ağları ve uzaktaki ağları birbirine bağlar.
  - İnternet trafiğinin tamamı router'lar üzerinden geçer. Bir paket kampüsten Amerika'ya giderken birçok router'dan geçer. Her router, paketin adresine bakarak bir sonraki noktayı bilir.
- Protokoller ve OSI modeli
  - Haberleşme protokolleri, bilginin hangi kurallarla taşınacağını belirler: Ethernet (kablolu), Wi-Fi, Bluetooth, NFC (kablosuz).
  - OSI modeli 7 katmandır: Application, Presentation, Session, Transport, Network, Data Link, Physical.
  - Uygulama katmanında HTTP, FTP, SSH, DNS gibi protokoller vardır.
  - TCP: iki bilgisayar arasında bir oturum (session) kurulur. Her paketten sonra alındı (acknowledgement) mesajı gönderilir. Güvenilirdir ama yük altında performansı düşer.
  - UDP: paket gönderilir, ulaşmama ihtimali kabul edilir. Daha hızlıdır ama daha az güvenilirdir. Hangi uygulamada hangisinin kullanılacağı çok önemlidir.
- Süreçler arası iletişim (interprocess communication)
  - Bir işin parçaları farklı bilgisayarlarda çalışabilir (dağıtık hesaplama, distributed computing). Bu parçalar arasındaki iletişime süreçler arası iletişim denir.
  - İstemci-sunucu (client-server) modeli: istemciler sunucudan istekte bulunur. Örnekler: yazıcı sunucusu (print server) gelen istekleri kuyruğa koyup sırayla basar. Dosya sunucusu (file server) istenen dosyayı ilgili istemciye gönderir.
  - Eşler arası (peer-to-peer) model: sunucu olmadan iki bilgisayar doğrudan haberleşir. Her iki taraf hem sunucu hem istemci gibi çalışır. Örnekler: Bluetooth ile telefonlar arası dosya gönderme, torrent, eşleşme sunucu üzerinden yapıldıktan sonra doğrudan oynanan çevrim içi oyunlar.
  - Bulut bilişim (cloud computing): dağıtık sistemlerin bir türüdür. Veriler merkezi bir yerde saklanır ve bütün cihazlardan erişilir. Veri saklamanın yanında yazılım hizmeti (Software as a Service), sunucu ve işletim sistemi kiralama gibi hizmetler de sunulur. Verileri USB bellekle taşıma ihtiyacını ortadan kaldırmıştır.
- İnternet
  - İnternet, dünyaya açık bir ağda bilgisayarların birbiriyle haberleşmesini sağlayan altyapıdır. Herkesin bir IP adresi ve alan adı (domain name) vardır.
  - İntranet, şirketlerin kendi iç ağlarında haberleşmesi için kurulan, erişimi belirli bir ağla sınırlı yapıdır.
  - İnternet servis sağlayıcıları (ISP) katmanlıdır: en üstte Tier 1, altında Tier 2, en altta son sistemler (end systems). Her son sisteme host denir.
  - Aynı ağdaki iki host doğrudan, yan ağdaki host switch üzerinden, farklı ağdaki host router üzerinden ve ISP altyapısı kullanılarak haberleşir.
  - Bağlantı genelde bakır kablolarla yapılır. Fiber kablolar dış etkenlerden çok daha az etkilenir ve çok daha hızlıdır. Kablolu taşıma güvenlik ve hata açısından kablosuza göre avantajlıdır, ama kablosuz haberleşme de çok yaygınlaşmış ve hızlanmıştır.
  - IP adresleri 32 bit (4 byte) uzunluğundadır ve noktalarla ayrılmış dört sayıyla yazılır. Örnek: `192.207.177.133`.
  - Alan adı sistemi (DNS): `yildiz.edu.tr` gibi adlar, DNS sunucuları tarafından ilgili bilgisayarın IP adresine çevrilir. Böylece her bilgisayarın adresini ezberlemek gerekmez. Router'ların ve bilgisayarların DNS arama tabloları (lookup table) vardır ve sürekli güncellenir. Tabloda olmayan bir ad DNS sunucusuna sorulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- RAM'den büyük programların çalışabilmesi sanal bellek ve sayfalama sayesindedir.
- Firmware güncellemesi donanıma yeni yetenek eklemez, donanımda var olan ama kullanılamayan yetenekleri kullanılabilir hâle getirir.
- Süreç geçişi çok sık olursa performans düşer.
- Kesmeler olmadan bilgisayarın çevresiyle (klavye, fare, diğer süreçler) koordineli çalışması mümkün değildir.
- Router ile switch'i karıştırmayın: switch aynı tip ağ içinde, router farklı tip ve uzak ağlar arasında çalışır.
- TCP ile UDP arasında seçim, uygulamanın güvenilirlik ve hız ihtiyacına göre yapılır.
- Dönem projesiyle ilgili cevaplar:
  - Projede `break` kullanılmayacak.
  - Kod, platformdan bağımsız standart C ile yazılmalıdır. Görsellik için kullanılan kütüphanelerin her yerde çalışması gerekmez.
  - C'de "string" diye ayrı bir tip yoktur, karakter dizisi vardır. Bir matris gözünde kelime saklamak için pointer gerekir. Bu konu öğretilmediği için başkasından alınmış bir pointer çözümü kabul edilmez. Alternatif: her hücreye bir indis koyup kelimeleri ayrı bir dizide tutmak.
  - Bir matris kısmen karakter, kısmen tamsayı saklayamaz. `%d` ve `%c` yalnızca yazdırma biçimidir. Tahtayı saklamak ile ekranda göstermek ayrı işlerdir, gösterim saklama yapısıyla aynı olmak zorunda değildir.
  - Seçilen piyon kendi piyonunun üzerine gelecekse tekrar sorulmaz, sıra geçer.

## Kısa Tekrar Notları

- Paging: veri sayfalara bölünür, RAM ile disk arasında taşınır. Sanal bellek diskte oluşturulur.
- Firmware: işletim sistemi olmadan temel I/O ve açılışı sağlar. En bilineni BIOS.
- Boot: ROM'daki bootloader, işletim sistemini diskten RAM'e yükler.
- Süreç durumları: ready, waiting. Süreç tablosu, context switch, dispatcher, time slice.
- Interrupt + interrupt handler: işlemcinin işi kesip başka bir işe geçmesi.
- Deadlock: iki süreç birbirinin kaynağını bekler.
- PAN < LAN < MAN < WAN. Topoloji: bus, star.
- Repeater (sinyali güçlendirir) < bridge (iki ağ, seçerek aktarır) < switch (çok ağ) < router (farklı ağlar, forwarding table, gateway).
- OSI 7 katman. TCP güvenilir (ack), UDP hızlı.
- Client-server ve peer-to-peer. Cloud computing.
- IPv4: 32 bit. DNS: alan adını IP'ye çevirir.

## Detaylı Açıklamalar

Ders, önceki derste başlanan işletim sistemi konusuyla devam eder: sayfalama, firmware, açılış süreci, süreçlerin yönetimi, kesmeler ve kilitlenme anlatılır. Arada dersle ilgili bir değerlendirme anketi doldurulur. İkinci yarıda bilgisayar ağlarına geçilir: ağların sınıflandırılması, topolojiler, ağ cihazları, protokoller, süreçler arası iletişim modelleri, bulut bilişim ve internetin yapısı anlatılır. Son bölümde dönem projesiyle ilgili sorular cevaplanır. Kalan birkaç ağ konusu ve binary search bir sonraki derse bırakılmıştır.

### Süreç geçişinde arka plandaki program durur mu?

Bir öğrenci, başka bir pencereye geçildiğinde arka plandaki işin devam edip etmediğini sordu. Hoca, işlemcinin bir zaman diliminde bir süreci çalıştırdığını açıkladı. Örneğin bir toplama işlemi biter bitmez o zaman dilimi sona erer ve işlemci kuyruktaki sıradaki süreci alır. O sırada müzik çalan ya da metin düzenleyen süreç gerçekten durur. Ama bu duraklamalar milisaniye ya da mikrosaniye mertebesinde olduğu için fark edilmez ve hizmet kesintisiz görünür.

### Repeater, bridge ve switch farkı

Uzun bir bus hattında sinyal belirli bir mesafeden sonra zayıflar. Repeater, zayıflayan sinyali yeniden oluşturarak her şeyi diğer tarafa aktarır. Bridge daha akıllıdır: mesajın hedefi kendi tarafındaysa mesajı diğer tarafa geçirmez. Switch ise ikiden fazla bus'ı birbirine bağlayabilir ve mesajı yalnızca hedef bilgisayarın bulunduğu bus'a yönlendirir. Bir mesaj aynı bus içinde kalacaksa switch onu diğer bus'lara göndermez.

### Ders sonrası notlar

- TCP ve UDP derste "iki IP protokolü" olarak söylendi. Daha doğru ifadeyle bunlar, IP protokolünün üzerinde çalışan taşıma katmanı (transport layer) protokolleridir.
- Ethernet'in ilk yıllarında bilgisayarlar gerçekten ortak bir hatta (bus) bağlanıyordu. Bugünkü Ethernet ağlarında bilgisayarlar genelde bir switch'e bağlanır, yani fiziksel yapı daha çok star topolojisine benzer.
- Hoca, WhatsApp gibi anlık mesajlaşma uygulamalarının eşler arası mı yoksa sunucu üzerinden mi çalıştığından emin olmadığını, bildiği kadarıyla bir sunucu kullanıldığını söyledi. Uçtan uca şifreleme, mesajın sunucudan geçse bile yalnızca iki uç tarafından okunabilmesi demektir. Mesajın eşler arası iletildiği anlamına gelmez.
- Derste bahsedilen IP adresleri IPv4 adresleridir. Bugün 128 bitlik IPv6 adresleri de kullanılmaktadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
