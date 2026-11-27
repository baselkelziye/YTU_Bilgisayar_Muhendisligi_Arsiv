# Ders 14 Çalışma Özeti

## Genel Konular

- IP'nin yardımcı kontrol protokolleri (ekrandan, 00:15:00)
  - IP tek başına çalışmaz; ağ katmanının alt katmandan servis alması ve başka hostlardaki eş ağ katmanlarıyla kontrol ve yönetim amaçlı haberleşmesi gerekir.
  - Slayttaki üç protokol: ICMP, IP'ye hata bilgisi döndüren yardımcıdır (zorunludur, örneğin traceroute için kullanılır); ARP, yerel bir IP adresinin Ethernet adresini bulur (IP paketi göndermek için gereken "yapıştırıcı"dır, host adresi sorar, sahibi cevap verir); DHCP, hosta yerel bir IP adresi atar (host sunucuya istek gönderir, sunucu bir kiralama (lease) verir).
- ICMP (Internet Control Message Protocol)
  - Bir hosttaki ağ katmanının başka bir hosttaki ağ katmanıyla kontrol amaçlı mesajlaşmasını sağlar. Bu mesajlaşmanın üst ya da alt katmana bir etkisi yoktur.
  - ICMP mesajları IP paketinin içine kapsüllenerek taşınır; normal bir IP paketi gibi gider, ama ağ katmanı içeriğinden kendisine geldiğini anlar ve kendisi cevap verir.
  - Slayttaki ana mesaj tipleri (ekrandan, 00:25:00):

    | Message type | Description |
    |---|---|
    | Destination unreachable | Packet could not be delivered |
    | Time exceeded | Time to live field hit 0 |
    | Parameter problem | Invalid header field |
    | Source quench | Choke packet |
    | Redirect | Teach a router about geography |
    | Echo and Echo reply | Check if a machine is alive |
    | Timestamp request/reply | Same as Echo, but with timestamp |
    | Router advertisement/solicitation | Find a nearby router |

  - Timestamp request/reply: gidiş-dönüş süresini (round trip time) ölçmek için kullanılır. Gecikme ölçümü ağ katmanının kendi işi kabul edildiği için bu ölçüm ağ katmanında yapılır.
  - Echo ve Echo reply: yalnız karşı tarafın ayakta olup olmadığını test eder; günlük hayatta `ping` ile kullanılır.
  - Time exceeded: `traceroute` bu mesajı kullanır. TTL önce 1 yapılır, paket ilk atlamada ölür ve geri bildirim gelir; sonra 2, 3 ... yapılarak hedefe kadar aradaki bütün atlamalar bulunur.
  - Destination unreachable: hedefe ulaşılamadığında gönderilir. Parçalamayı önlemek için Do Not Fragment biti set edilmiş bir paket gönderilirse ve paket parçalanmadan geçemiyorsa da bu mesaj döner.
  - Parameter problem: IP başlığında geçersiz bir alan vardır. Başlık sağlama toplamı (header checksum) tek bit hatalarına yöneliktir; iki ya da üç bitlik bir hata gözden kaçarsa alan geçersiz bir değer taşıyabilir ve bu mesaj gerekir.
  - Source quench: tıkanıklıkta kaynağa "daha az paket gönder" demek için kullanılan boğma (choke) paketidir. Ancak bu mesaj da tıkalı yola gireceği için "yangına benzin dökmek" gibidir; bu yüzden bu kontrol üst katmanda yapılmayı tercih edilir.
  - Redirect: router paketi iletir ama hedefe daha uygun başka bir router olduğunu bildiği için kaynağa "bundan sonra bu yöndeki paketleri şu router üzerinden gönder" der; bir optimizasyondur.
  - Router advertisement/solicitation: IP ayarlarını bilen ama yerel ağdan nasıl çıkacağını bilmeyen bir host, yerel ağdaki router'ı bulmak için yayın (broadcast, hatta multicast) yapar; router olan host cevap verir.
  - ICMP mesaj tipleri bunlarla sınırlı değildir; tam liste IANA'nın sayfasındadır.
- ARP (Address Resolution Protocol) (ekrandan, 00:35:00)
  - Katmanlı yapının bir ölçüde ihlalidir: hosta ağ katmanında IP adresiyle erişilir, ama gerçek iletim alt katmandaki fiziksel adresle (Ethernet'te MAC adresi) yapılır.
  - ARP olmazsa aynı yerel ağdaki iki host arasında IP trafiği ancak her IP için MAC adresini elle yazarak mümkün olur; ARP'den önce böyle yapılmıştır (DNS öncesinde adreslerin merkezden dosyayla dağıtılmasına benzer).
  - Slayttaki örnek topoloji: CS ağı 192.32.65.0/24 (Host 1: IP1 = 192.32.65.7, E1; Host 2: IP2 = 192.32.65.5, E2; router arayüzü 192.32.65.1, E3), EE ağı 192.32.63.0/24 (Host 3: IP3 = 192.32.63.3, E5; Host 4: IP4 = 192.32.63.8, E6; router arayüzü 192.32.63.1, E4).
  - Slayttaki çerçeve tablosu:

    | Frame | Source IP | Source Eth. | Destination IP | Destination Eth. |
    |---|---|---|---|---|
    | Host 1 to 2, on CS net | IP1 | E1 | IP2 | E2 |
    | Host 1 to 4, on CS net | IP1 | E1 | IP4 | E3 |
    | Host 1 to 4, on EE net | IP1 | E4 | IP4 | E6 |

  - Çalışma: Host 1, Host 2'nin IP adresini bilir ama MAC adresini bilmez. Bütün bitleri 1 olan yayın MAC adresine (12 tane F) bir ARP sorgusu gönderir. Her host "bu IP benim mi" diye bakar; değilse atar. Adresin sahibi doğrudan Host 1'e cevap verir. Host 1 kendi MAC adresini sorguya koyduğu için Host 2'nin onu ayrıca araması gerekmez.
  - Yayın herkese gittiği için diğer hostlar da sorgu ve cevaptaki eşleşmeleri öğrenip kenara koyabilir. Hostlar böylece bir ARP tablosu oluşturur.
  - ARP tablosundaki kayıtların bir yaşam süresi (TTL) vardır: hostlar kapanıp açılabilir; ağ kartı değişirse MAC adresi değişir (MAC adresleri üreticilerce dünya çapında tekil tutulur) ve eski kayıt elle silinmezse hosta erişilemez.
  - Router iki yerel ağı ağ katmanında birleştirir; yayın ise veri bağı katmanında (MAC alt katmanında) kalır ve router'dan geçmez. Router iki taraftaki yayınları dinleyerek adresleri öğrenir; bilmediği bir IP gelirse ilgili tarafta ARP yayını yapar, cevap gelene kadar paket router'da bekler.
  - Proxy ARP: bir host, gerçek sahibi olmadığı bir adres için sorgulara vekil olarak cevap verir. Mobil IP'de home agent bunu yapar.
- DHCP (Dynamic Host Configuration Protocol)
  - Bir hostun IP ağına katılabilmesi için gerekenler: kendi IP adresi, ağ maskesi ya da önek (prefix), dışarı çıkış için ağ geçidi (gateway, router) adresi, en az bir, tercihen iki DNS sunucusu adresi.
  - Küçük ve durağan ağlarda bunlar yapılandırma dosyalarına elle yazılabilir; büyük ve dinamik (kampüs, metropol) ağlarda elle yapmak hem iş gücü hem hata açısından mümkün değildir.
  - Öncülü BOOTP'dir (açılış sırasında ağ parametrelerini almak için); kısıtları yüzünden yerini endüstri standardı DHCP'ye bırakmıştır.
  - Host MAC adresiyle yerel ağa özel bir yayın (DHCP Discover) yapar. Sunucu kendi veri tabanına bakar: belirli bir adres mi, havuzdan (pool) bir adres mi verilecek; maske, gateway, DNS adresleri, istenirse host adı ve alan adı (FQDN) da paketlenip gönderilir.
  - Sunucu ile istemci aynı ağda olmalı ya da aradaki router'lar isteği aktarmalıdır (relay).
  - Adres bir kiralama (lease) süresiyle verilir; süre bitmeden istemci yeniden isterse aynı adres verilir. Kayıtlar veri tabanında tutulur; sunucu genelde birincil ve ikincil olacak şekilde yedekli (failover) kurulur.
- MPLS (Multi-Protocol Label Switching) (ekrandan, 00:45:00 ve 01:00:00)
  - Bağlantısız datagram ağında, sanal devre gibi davranan hızlı bir iletim sağlar. Router'lar her paket için yönlendirme tablosunda en uzun önek eşleşmesi yapmak yerine etikete (label) göre anahtarlama yapar.
  - Slayttaki başlık sırası: PPP, MPLS, IP, TCP, User data, CRC. MPLS başlığı 32 bittir: Label 20, QoS 3, S 1, TTL 8 bit.
  - Etiket IP adresine göre MPLS ağına (ör. ISP) girerken eklenir, çıkarken kaldırılır; içeride iletim yalnız etikete bakar. Etiketi ekleyen/kaldıran router Label Edge Router, içerideki router'lar Label Switch Router'dır.
  - Etiketin önüne bir etiket daha konabilir. 20 bitlik etiket alanı $2^{20}$ değer, 3 bitlik QoS alanı 0-7 arası 8 sınıf verir.
  - Günlük hayatta doğrudan değil, ISP gibi yapıların içinde kullanılır. Tek atlamalı bağlantı için anlamsızdır, çok atlamalı topolojide işe yarar.
- Otonom sistemler, OSPF ve BGP
  - İnternet, otonom sistemlerden (AS) oluşur. AS içinde kullanılan protokoller iç (interior) yönlendirme protokolleri, AS'ler arasında kullanılanlar dış (exterior) gateway protokolleridir; dış protokol BGP'dir.
  - OSPF (Open Shortest Path First): link state yönlendirmenin TCP/IP kapsamında uygulanmış, açık ve standart iç yönlendirme protokolüdür. Ağı ağırlıklı kenarlı bir graf olarak modeller; bir yayın LAN'ı iyi bağlı tek bir düğüm olarak gösterilir (ekrandan, 01:15:00).
  - OSPF bir AS'yi alanlara (area 0, 1, 2 ...) böler; area 0 omurgadır (backbone). Omurgada alternatif yollar için birden fazla router olmalıdır; omurga router'ları alanlar arası "otoyollar" gibidir.
  - OSPF mesajları: hello, link state update, link state acknowledge, database description, link state request. Her router Dijkstra algoritmasıyla en kısa yolu hesaplar.
  - BGP (Border Gateway Protocol): AS'ler arasında, ağların politika kısıtlarına uyarak yol hesaplar; bir "sınır kapısı" gibidir (ekrandan, 01:20:00).
  - Slayttaki politika örnekleri: eğitim ağı üzerinden ticari trafik taşınmaz; siyasi sebeplerle belirli bir ülke rotaya konmaz; daha ucuz ağı seç; daha iyi performanslı ağı seç; iki rakip şirketin ağları arasında gidip gelme.
  - Bu kısıtlar teknik değil yönetimsel kısıtlardır (para, siyaset, rekabet); teknik ölçütler ise gecikme, kayıp, bant genişliği gibi iç yönlendirme ölçütleridir.
  - Transit ve peering (ekrandan, 01:25:00): transit başkası için trafik taşır ve ücret alır; peer'ler karşılıklı yarar için taşır. Slayt örneği: AS1, AS2 ile AS4 arasındaki trafiği taşır (transit) ama AS3'ünkini taşımaz (peer). Slayttaki politika kısaltmaları: TR = Transit, CU = Customer, PE = Peer.
  - Yeni bir AS'nin bilgisi BGP router'ları arasında adım adım yayılır. Duyurulara geçilen AS'lerin tam yolu eklenir; router kendini yolda görürse duyuruyu kullanmaz, böylece kapalı döngüler kırılır.
- İnternette çoklu yayın (multicasting) (ekrandan, 01:30:00)
  - Gruplar için ayrılmış bir adres aralığı vardır (D sınıfı); bu adresler normal host adresi olarak kullanılamaz.
  - Grup üyeliği router'larda çalışan IGMP (Internet Group Management Protocol) ile yönetilir: grupların dinamik oluşturulması, güncellenmesi ve kaldırılması. ICMP ile karıştırılmamalıdır.
  - Yollar PIM gibi protokollerle hesaplanır: yoğun (dense) modda budamalı ters yol iletimi (RPF), seyrek (sparse) modda çekirdek tabanlı ağaçlar (core-based trees).
  - IP multicast tek bir ağ (veri merkezi, kablolu TV ağı) dışında yaygın değildir. Örnek: IPTV hizmetleri altta multicast kullanır ve ticari ortaklık olsa bile fiziksel olarak ayrı iki ağ arasında bu trafik geçmez.
- Mobil IP (ekrandan, 01:40:00)
  - Mobil host, ev ağındaki home agent sayesinde sabit IP'siyle erişilebilir. Router'larda ve sabit hostlarda değişiklik gerekmez.
  - Host ev ağındayken home agent bir şey yapmaz. Host başka bir ağa giderse IPv4'te aynı adresi kullanamaz; bulunduğu yerdeki foreign agent ona geçici bir care-of adresi verir ve bunu home agent'a bildirir.
  - Slayttaki adımlar: 1) care-of adresinin kaydı, 2) göndericinin ev adresine gönderimi, 3) home agent'ın paketi care-of adresine tünellemesi, 4) mobil hostun göndericiye cevabı, 5) göndericinin sonraki paketleri doğrudan care-of adresine tünellemesi.
  - Home agent, proxy ARP ile mobil hostun adresini üstlendiği için paketi alabilir.
  - IPv6'da bu yapı çok daha basittir; ev adresi/care-of adresi ayrımı kendiliğinden çözülür.

## Hocanın Özellikle Vurguladığı Kısımlar

- ARP'nin zorunluluğu
  - ARP olmadan aynı yerel ağdaki iki host arasında IP trafiği, eşleşmeler elle yazılmadan mümkün değildir.
- ARP yayınının router'dan geçmemesi
  - Yayın veri bağı katmanındadır, router ise ağ katmanında birleştirir; bu yüzden MAC bilgisi bir LAN'dan diğerine geçmez.
- Source quench'in sakıncası
  - Tıkanıklığı bildiren paketin kendisi de tıkanıklığa girer; "yangına benzin dökmek" gibidir. Bu kontrol üst katmana bırakılır.
- ICMP ile IGMP sık karıştırılır
  - Biri kontrol mesajları, diğeri multicast grup yönetimi içindir; birbirinden çok farklıdır.
- BGP kısıtlarının teknik olmaması
  - BGP'deki kurallar yönetimsel, ticari ve siyasi kurallardır; BGP bu kuralların verilebilmesini sağlar.
- Slaytlar özettir
  - Slaytlarda az şey yazar ama anlatımda çok ayrıntı verilir; ayrıntılar için ders kitabına da bakılmalıdır. MPLS'in mantığı basit görünse de işletim ayrıntıları karışıktır.

## Kısa Tekrar Notları

- IP'nin üç yardımcısı: ICMP (hata/kontrol), ARP (IP → MAC), DHCP (otomatik yapılandırma).
- ICMP mesajları IP paketi içinde taşınır.
- `ping` = Echo/Echo reply; `traceroute` = artan TTL + Time exceeded.
- DF biti set edilmiş paket parçalanamıyorsa Destination unreachable döner.
- ARP sorgusu yayın MAC adresine (FF:FF:FF:FF:FF:FF) gider, cevap doğrudan sorana döner.
- ARP tablosu kayıtlarının yaşam süresi vardır.
- Proxy ARP: başka bir host adına cevap verme; Mobil IP'de home agent kullanır.
- Hostun ağa katılması için: IP, maske/önek, gateway, DNS (tercihen iki).
- DHCP: Discover yayını, havuz ya da sabit adres, lease süresi, relay, failover.
- MPLS başlığı 32 bit: Label 20, QoS 3, S 1, TTL 8.
- Label Edge Router etiketi ekler/kaldırır; Label Switch Router yalnız etikete bakar.
- OSPF: iç protokol, link state, Dijkstra, alanlar ve omurga (area 0).
- BGP: dış protokol, politika kısıtları, transit ve peer, tam AS yolu ile döngü kırma.
- Multicast: D sınıfı adresler, IGMP, PIM dense (RPF) ve sparse (core-based tree).
- Mobil IP: home agent, foreign agent, care-of adresi, tünelleme.

## Detaylı Açıklamalar

- ICMP ve gecikme ölçümü
  - Tıkanıklık kontrolünde ve yönlendirmede yolun yoğunlaştığı gecikmelerden anlaşılır. Bir paketin karşı ağ katmanına gidip cevabın dönmesine kadar geçen süre gidiş-dönüş süresidir (round trip time); gidiş ve dönüş eşit olmayabilir ama işi kolaylaştırmak için yarısı tek yön kabul edilir. Bu ölçümü uygulama katmanında yapmak mümkündür, ama sonucu yine ağ katmanına aktarmak gerekir. Bu yüzden ölçüm ağ katmanının kendi işi sayılmış ve Timestamp request/reply mesajları tanımlanmıştır.
- ARP'nin router üzerinden çalışması
  - Slayttaki tabloda Host 1'den Host 4'e giden paket, CS ağında hedef Ethernet adresi olarak router'ın E3 arayüzünü taşır; EE ağında ise kaynak Ethernet adresi E4, hedef E6 olur. IP adresleri (IP1 → IP4) yol boyunca değişmez, Ethernet adresleri her LAN'da değişir. Router iki ağdaki yayınları dinleyerek tablosunu doldurur ve ağ katmanında geçiş yaparken IP'den MAC'e dönüşümü şeffaf biçimde yapar.
- DHCP ve host adı
  - DHCP sunucusu hosta adres, maske, gateway ve DNS bilgisinin yanında host adını ve ait olduğu alan adını da verebilir. Host adı ile alan adı birleşince tam nitelikli alan adı (Fully Qualified Domain Name) oluşur; örneğin bir web sunucusunun adında "www" host adı, devamı alan adıdır.
- MPLS'in neden gerektiği
  - IP yönlendirmesinde her router hedef adrese bakıp en uzun önek eşleşmesi yapar; adresler toplanır (aggregation) ve gittiği yerde yeniden ayrıştırılır. Bir kıtadan diğerine giden trafikte ara noktalarda paketin hangi ülkeye gideceği fark etmez. MPLS bu trafiği bir yoğunlaşma noktasında etiketleyip "demetlerin demeti" gibi tek bir bütün olarak taşır. Sanal devre ağlarında devre kurulduktan sonra paketlerin devre kimliğine göre hızla aktarılmasına benzer. Böylece datagram ağında anahtarlama ile bir devre kurulmuş olur.
- BGP'de transit ve peering mantığı
  - Transit, bir AS'nin hedefi kendisi olmayan trafiği başka AS'ler için taşımasıdır; hoca bunu aktarmalı bir uçuşta ara havalimanından geçmeye benzetti. Taşınan trafik için genelde ücret alınır; yurt dışında dolaşımda (roaming) gidilen ülkedeki operatöre ödeme yapılması buna benzer. Peer'ler benzer hacimde karşılıklı trafik taşıdığı için birbirine yarar sağlar ve ödeme olmayabilir. BGP router'ları hangi BGP router'larıyla bağlı olduğunu bildiği için, Bellman-Ford'daki sorunlar olmadan tablolarını günceller; hesaplamayı da bu özel kurallara göre yapar.
- Multicast yol bulma
  - Grupta çok host varsa (yoğun) ters yol iletimi kullanılır: kaynaktan hedeflere ilerlenir, geçilen yollar kaydedilir ve dönüşte herkes yolu öğrenmiş olur. Grup seyrekse az sayıdaki hostun arasından geçen bir çekirdek (core) ağaç kurulur; diğer hostlar veriyi en yakın noktadan bu çekirdeğe aktarır.
- Mobil IP'de yolun kısalması
  - Gönderici mobil hostun hareket ettiğini bilmez ve ev adresine gönderir. Home agent proxy ARP ile bu paketi alır ve foreign agent'ın bildirdiği care-of adresine tüneller. Mobil host cevabı doğrudan göndericiye gönderir; gönderici bundan sonra paketleri doğrudan care-of adresine gönderebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
