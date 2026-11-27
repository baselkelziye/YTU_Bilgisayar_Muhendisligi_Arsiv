# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve ağ katmanına giriş
  - Ders kitabı Andrew S. Tanenbaum ve David Wetherall'ın *Computer Networks* kitabının 5. baskısıdır. Ders ağ katmanından (5. bölüm) başlar, ardından taşıma ve uygulama katmanlarına geçer.
  - Ağ katmanı bölümünün başlıkları (ekrandan, 00:35:00): Design Issues, Routing Algorithms, Congestion Control, Quality of Service, Internetworking, Network Layer of the Internet.
  - Her konuda önce teorik kısım, sonra bugünkü pratik uygulaması (İnternet ve TCP/IP) incelenir.
- Eski yöntemleri öğrenmenin önemi
  - Kenara kaldırılmış teknikler yeni teknolojilerde tekrar denenir: RFID ortaya çıktığında ALOHA yeniden gündeme geldi; sensör ağları çıktığında distance vector routing yeniden denendi.
  - Daha önce görülmemiş bir problemle karşılaşan mühendis önce geçmişte benzer durumlarda uygulanmış çözümlere bakar.
- Katmanlı model
  - Kitap OSI'nin session ve presentation katmanlarını çıkararak beş katmanlı bir model kullanır: Application, Transport, Network, Link, Physical (ekrandan, 00:40:00).
  - Physical ve Link katmanları veri haberleşmesi dersinde işlenmiştir; bu derste üstteki üç katman (Network, Transport, Application) anlatılır.
- Ağ katmanının görevi
  - Paketleri uç noktalar arasında birden fazla link üzerinden taşımak ve teslim etmek: "Responsible for delivering packets between endpoints over multiple links" (ekrandan, 00:40:00).
  - Alt katman tek atlama (iki komşu nokta), ağ katmanı uçtan uca ve çok atlamalıdır.
- Ağ katmanı tasarım konuları (ekrandan, 00:45:00)
  - Store-and-forward packet switching
  - Connectionless service – datagrams
  - Connection-oriented service – virtual circuits
  - Virtual circuit ve datagram karşılaştırması
- Store-and-forward packet switching
  - Hostlar paketleri ağa gönderir, paketler routerlar tarafından iletilir (ekrandan, 00:50:00).
  - Router paketin tamamını alıp belleğe yazmadan (store) bir sonraki linke iletmeye (forward) başlamaz.
  - Message switching: bütün mesaj adım adım bir düğümden ötekine aktarılır. Packet switching: mesaj paketlere bölünür.
- Router, host ve ISP
  - Router: paketin son noktası olmayan, paketi hedefine doğru hangi linkten göndereceğine karar veren ara sistem.
  - Host: üzerinde işletim sistemi çalışan, ağın aktif parçası olan ve ağ uygulamalarına ev sahipliği yapan bilgisayar.
  - ISP'nin routerları ve aralarındaki hatlar bu bölümde "subnet" diye adlandırılır; bu, IP alt ağ (subnetting) kavramıyla karıştırılmamalıdır.
- Connectionless (datagram) servis
  - Her paket içindeki hedef adrese göre bağımsız iletilir; farklı paketler farklı yollardan gidebilir (ekrandan, 01:00:00).
  - Paketler sırasız (out of order) gelebilir; alıcı süreç sıralamak zorundadır.
- Connection-oriented (virtual circuit) servis
  - Yol önceden kurulur, paketler içlerindeki etiketle (tag) bu sanal devre boyunca iletilir (ekrandan, 01:05:00).
- Virtual circuit ve datagram karşılaştırması (ekrandan, 01:10:00)
  - Devre kurulumu, adresleme, durum bilgisi, yönlendirme, router arızasının etkisi, hizmet kalitesi ve tıkanıklık denetimi açısından iki yaklaşım karşılaştırılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kavramların doğru öğrenilmesi
  - Store and forward, packet switching, connectionless ve connection-oriented kavramları başta ezberlense de kullanıldıkça doğal hale gelmelidir.
- Bağlantısız ve bağlantılı servis benzetmesi
  - Connectionless servis mektuba, connection-oriented servis telefona benzer. Telefonda önce zil çalar, bağlantı kurulur, sonra konuşulur; mektup ise önceden haber verilmeden gelir.
  - "Datagram" sözcüğünün kökeni telegramdır (telgraf).
- Her katmanın servisi ayrı değerlendirilir
  - TCP/IP'nin ağ katmanı (IP) connectionless'tır, ama üstündeki TCP connection-oriented'dır. Alt katmandaki servis kullanılan teknolojiye göre değişir.
  - Bugün neredeyse her şey connectionless servis üzerinden verilir, ama bu connectionless'ın her senaryoda tek doğru olduğu anlamına gelmez.
- Ağ katmanı da süreçlerden oluşur
  - Ağ katmanı yalnız çağrılınca çalışan fonksiyonlar değildir; routerlar servis istenmese bile kendi aralarında kontrol mesajları alıp verir. Bunlar işletim sistemindeki süreç (process) ve iş parçacıklarıyla (thread) yürür.
  - Web sunucusu, e-posta sunucusu, sohbet istemcisi gibi bütün ağ uygulamaları birer süreçtir.
- Döngü ihtimali
  - Datagram ağlarında bir paketin döngüye girmesi gerçek bir olasılıktır ve önlenmesi gerekir.

## Kısa Tekrar Notları

- Ağ katmanı: uç noktalar arasında, birden fazla link üzerinden paket teslimi.
- Store-and-forward: paket tamamen alınır, saklanır, sonra iletilir.
- Message switching bütün mesajı, packet switching paketleri adım adım taşır.
- Router: ara düğüm, paketin hangi çıkış linkine gideceğine karar verir. Host: uç sistem.
- Router kararını metriklere göre verir: hedefe yakınlık, hat maliyeti, hattın doluluğu ya da bant genişliği; ISP'ler arasında fiyat, şirket politikası ve gizlilik kısıtları.
- ISP'ler routerlarını İnternet Exchange Point'lerde (IXP) birbirine bağlar.
- Datagram: her pakette tam kaynak ve hedef adres, her paket bağımsız yönlendirilir, routerda bağlantı durumu tutulmaz.
- Virtual circuit: önce devre kurulur, pakette kısa VC numarası (etiket) vardır, routerlarda bağlantı başına tablo girdisi (durum) tutulur.
- Router çökerse: datagramda yalnız o an routerdaki paketler kaybolur; VC'de o routerdan geçen bütün sanal devreler sonlanır.
- QoS ve tıkanıklık denetimi: datagramda zor, VC'de her devre için önceden yeterli kaynak ayrılabiliyorsa kolay.
- Datagramda tıkanıklık kolay oluşur; VC'de doğru planlamada oluşması zordur, ama oluşursa çözmek daha zordur.

## Detaylı Açıklamalar

- Ağ katmanının yeri ve görevi
  - Beş katmanlı modelde ağ katmanı link katmanının üstünde, taşıma katmanının altındadır. Link katmanı iki komşu nokta arasında tek atlamalık iletim sağlar. Ağ katmanı bu linkleri birleştirerek bağlantıyı uçtan uca genişletir: bilgi, sakla-gönder mantığıyla bir uçtan çok sayıda ara düğüm üzerinden öteki uca taşınır.
  - Ağ katmanındaki veri birimine paket denir.
- Store-and-forward ve packet switching
  - Ağdan gelen bir verinin işlenebilmesi için önce yerel belleğe alınması (store), hedef orası değilse uygun linke yönlendirilmesi (forward) gerekir.
  - Örnek: A'nın gönderdiği paketin ilk 10 baytı B'ye ulaştığında B, bunu C'ye aktarmaya başlamaz. Paketin tamamı (100 bayt, 1000 bayt, ne ise) B'ye gelir, tamamlanır, sonra iletim başlar.
  - Mesajın tamamı A'dan B'ye, B'den C'ye, C'den D'ye bütün olarak taşınıyorsa bu message switching'dir. Mesaj küçük paketlere bölünerek taşınıyorsa packet switching'dir.
- Slayttaki topoloji (ekrandan, 00:50:00)
  - Ortadaki gri elips ISP'nin ekipmanıdır (ISP's equipment). İçinde A, B, C, D, E routerları vardır. Bağlantılar: A–B, A–C, B–D, C–D, C–E, D–E.
  - Host H1 (Process P1) doğrudan ISP'ye ait A routerına bağlıdır. H2 (P2) ise gri alanın dışındaki F cihazına bir LAN ile bağlıdır; F de E'ye bağlıdır.
  - H1 örneği, kullanıcının yalnız bir hat ucu (örneğin metro Ethernet) kullandığı durumu; H2 örneği, kullanıcının kendi tarafında bir cihaz (örneğin evdeki ADSL modem) bulunduğu durumu anlatır.
  - A'dan C'ye giden bir paket işaretlidir. C paketi tamamen aldıktan sonra hangi linkten göndereceğine karar verir.
  - Ev ağında seçim yoktur; her şey ISP'ye gider. Port yönlendirme (port forwarding) gibi ayarlar statik yönlendirmedir.
- Datagram servisi
  - Mektup gibi her paketin üzerinde gönderici ve alıcı adresi bulunmalıdır, çünkü paketler bağımsız yönlendirilir.
  - Slaytta P1'den P2'ye giden 1, 2 ve 3 numaralı paketler A–C–E–F yolunu izler; 4 numaralı paket ise A'dan B'ye gider (ekrandan, 01:00:00); hocanın anlatımına göre B–D–E–F üzerinden devam eder, ama D–C–E–F gibi başka yollar da mümkündür.
  - Alternatif yollar trafikteki ara sokaklar gibi tıkanıklıkta rahatlatır; ama paketler farklı sürelerde gelir ve sıralanmaları gerekir.
- Virtual circuit
  - Telefon santrali benzetmesi: eski telefon sisteminde arayan, operatörler aracılığıyla hiyerarşik ofisler üzerinden karşı tarafa bağlanır, karşı taraf kabul edince bağlantı kurulur (connection setup).
  - Fiziksel devre (circuit) eskiden rölelerle, sonra elektronik anahtarlar ve çoklayıcılarla (multiplexer) kurulurdu. Sanal devrede anahtarlama yazılımla yapılır: paketin başındaki tanımlayıcıya (identifier) bakılarak paket bir giriş kuyruğundan uygun çıkış kuyruğuna aktarılır.
  - Kurulum sırasında bant genişliği ve gecikme gibi gereksinimler önceden belirtilebilir. Dezavantajı, ayrılıp kullanılmayan bant genişliğinin boşa gitmesidir.
- Karşılaştırmanın yorumu
  - Datagramda router paketi gönderdiği anda unutur. VC'de her router giriş hattı/etiket ile çıkış hattı/etiket ilişkisini tutar; bu durum bilgisidir (state).
  - VC'de servis sağlayıcı, kullanıcıyı arayüzde filtreleyerek söz verdiği parametrelere zorlayabilir; fazla trafik gönderen kullanıcıda tıkanıklık kendi tarafında oluşur, ağın geri kalanı etkilenmez.
  - Datagramda tıkanıklık bir routerı yeniden başlatarak "çözülebilir": bekleyen paketler kaybolur. Tıkanıklığı önlemeye çalışmak da ek yük getirip kapasiteyi azaltır; hoca bunu işletim sistemlerindeki deadlock'a karşı yaklaşımlara (önleme, oluşunca çözme, görmezden gelme) benzetti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
