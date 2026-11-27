# Ders 14 Genişletilmiş Notu: Ağ Katmanı Kontrol Protokolleri, MPLS, OSPF, BGP, Multicast ve Mobil IP

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. IPv4 ve Ağ Katmanının Kontrol İhtiyacı
- 2. ICMP: İnternet Kontrol Mesajları
- 3. ARP: IP Adresinden Ethernet Adresine
- 4. DHCP: Hostun Otomatik Yapılandırılması
- 5. Etiket Anahtarlama ve MPLS
- 6. Otonom Sistemler ve OSPF
- 7. BGP: Dış Yönlendirme Protokolü
- 8. İnternette Çoklu Yayın (Multicasting)
- 9. Mobil IP
- Örnek Sorular
- Dersin Toparlaması

## 1. IPv4 ve Ağ Katmanının Kontrol İhtiyacı

Bu ders, iki şubenin birlikte yürütüldüğü ve iki hocanın dönüşümlü anlattığı bir oturumdu. Bir önceki derste IPv6'nın yapısına bakılmıştı. Hoca yine de günümüzde yoğun olarak IPv4'ün kullanıldığını, bunun fiilî (de facto) standart olduğunu hatırlattı; bu yüzden pek çok noktada anlatım IPv4 üzerinden gider.

IP bir ağ katmanı protokolüdür. Bir yandan alt katmandan kendisine servis sağlanmasını bekler, öbür yandan başka hostlardaki kendisiyle aynı seviyedeki ağ katmanlarıyla haberleşmek ve onların durumunu öğrenmek ister. Bu yüzden IP'nin çevresinde kontrol ve yönetim (control and management) amaçlı ek protokoller vardır. Bunlardan en sık karşılaşılan ve kullanılan üçü ICMP, ARP ve DHCP'dir. Slayt bunları şöyle özetler (ekrandan, 00:15:00):

- ICMP is a companion to IP that returns error info. Required, and used in many ways, e.g., for traceroute.
- ARP finds Ethernet address of a local IP address. Glue that is needed to send any IP packets. Host queries an address and the owner replies.
- DHCP assigns a local IP address to a host. Gets host started by automatically configuring it. Host sends request to server, which grants a lease.

## 2. ICMP: İnternet Kontrol Mesajları

### 2.1 ICMP'nin yeri

ICMP (Internet Control Message Protocol), bir hosttaki IP katmanının, yani ağ katmanının, başka bir hosttaki ağ katmanıyla kontrol amaçlı mesajlaşmasını sağlar. Bu mesajlaşmanın üst ya da alt katmana bir etkisi yoktur; doğrudan ağ katmanının yönetimsel işleriyle ilgilidir.

ICMP mesajları IP protokolünün içine kapsüllenerek gönderilir. Normal bir IP paketinden farkı yoktur, öyle taşınır. Ama paket açıldığında ağ katmanı, yalnız adresinden değil, yerine getirmesi gereken görev açısından da paketin kendisine geldiğini anlar ve kendisi cevap verir.

### 2.2 Gecikme ölçümü ve Timestamp mesajları

Hoca, tıkanıklık ve yönlendirme konusunda konuşulan örneği hatırlattı: Amerika kıtasının ortadan ikiye bölündüğü, doğudan batıya geçişin iki yoldan yapılabildiği örnekte bir taraf tıkanınca öbür tarafa, o tıkanınca yine diğer tarafa geçiliyordu ve bunun bir "ping pong" etkisi yaratabileceği anlatılmıştı. Yolun tıkandığını ya da yoğunlaştığını anlamak için gecikmelerden yola çıkılmıştı. Bir paketin karşıdaki ağ katmanına gidip cevabın geri dönmesine kadar geçen süre gidiş-dönüş süresidir (round trip time). Gidiş ve dönüş her zaman eşit olmayabilir, ama işi kolaylaştırmak için tek yönün bunun yarısı olduğu kabul edilir.

Bu süreyi ölçmek için uygulama katmanında bir program yazılabilir, ama elde edilen sonucun yine ağ katmanına aktarılması gerekir. Bu yüzden ölçümün ağ katmanının kendi işi olduğu kararı alınmış ve ICMP'ye Timestamp request/reply mesajları konmuştur.

### 2.3 ICMP mesaj tipleri

Slayttaki ana mesaj tipleri şunlardır (ekrandan, 00:25:00):

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

**Echo ve Echo reply.** Her zaman zaman damgasına ihtiyaç yoktur; bazen yalnız karşı tarafın ayakta olup olmadığı test edilmek istenir. Bunun için Echo ve Echo reply kullanılır. Günlük hayatta kullanılan `ping` bunu yapar: bir hosta ne kadar sürede erişilebildiğini, aradaki atlama sayısından bağımsız olarak ekonun geri dönüş süresiyle ölçer. Tablonun üst kısmındaki beş mesaj ise paketle ya da trafikle ilgili sorunları bildirir.

**Time exceeded.** Diğer hoca burada `traceroute` aracını örnek verdi. Bu araç, bir paketin kaynaktan hedefe kadar hangi atlamalardan (hop) geçtiğini adım adım belirler ve bunu Time exceeded mesajıyla yapar. Paket TTL değeri verilerek tekrar tekrar gönderilir:

- Birinci adımda TTL 1 yapılır. Paket ilk atlamaya gider, orada TTL sıfırlandığı için ölür ve geriye "paket burada öldü" diye bir cevap döner.
- Sonra TTL 2 yapılır ve paket ikinci atlamaya kadar gider.
- TTL artırılarak hedefe varılana kadar devam edilir ve yol üzerindeki bütün atlamalar bulunur.

**Destination unreachable.** Hedef router tarafından bulunamadığında, ona ulaşılamadığında gönderilir. Hoca bunu önceki derslerde konuşulan parçalamaya (fragmentation) bağladı: parçalamayı yönetmenin en iyi yolu, parçalanmaya izin vermemektir. Kaynaktan hedefe Do Not Fragment biti set edilmiş bir paket gönderilebilir; paket yol üzerinde parçalanmadan geçemiyorsa geriye kontrol mesajı olarak Destination unreachable gelir.

**Parameter problem.** IP paketinin başlığında bir sorun olduğunu, geçersiz bir alan bulunduğunu ifade eder; sebebi yazılım ya da router'daki başka bir şey olabilir. Diğer hoca bir ekleme yaptı: IP başlık sağlama toplamı (header checksum) çok güvenilir, garantili bir denetim değildir; tek bit hatalarını yakalamaya yöneliktir. İki ya da üç bitlik bir hata öyle denk gelebilir ki sağlama toplamı doğru çıkar, ama bir alan olmaması gereken, yanlış bir değer taşır. O zaman Parameter problem mesajı gönderilmelidir.

**Source quench.** Slayttaki açıklaması "choke packet"tir. Bir taraf çok fazla paket gönderiyor ve karşı taraf bunları işleyemiyorsa, yani bir yerde tıkanıklık varsa, bunun kaynağa bildirilmesi gerekir; bu kontrol mesajı bunun içindir. Ama bir sorun vardır: bunu kullanmak "yangına benzin dökmek" gibidir. Hoca bunu iki yönde de tıkalı iki köprü benzetmesiyle anlattı: hedef, kaynağa "daha az paket gönder" der, ama gönderilen bu paket de aynı tıkanıklığa girer. Belki kaynağa hiç ulaşamayacak bir paket için yine zamanlayıcı kurulacak, gidip gitmediğini denetleyen bir mekanizma işletilecektir. Karışıklığı artıran bir şeydir; bu yüzden bu kontrol ağ katmanında değil, bir üst katmanda yapılmayı tercih edilir. Ayrıntısı taşıma katmanında konuşulacaktır.

> **Ders sonrası not:** Hoca burada "flow control" ifadesini kullandı. Slayttaki "choke packet" ve hocanın anlattığı ağ içindeki tıkanıklık durumu, önceki derslerde işlenen tıkanıklık kontrolüne (congestion control) aittir; akış kontrolü (flow control) ise alıcının kapasitesiyle ilgilidir. İkisinin de taşıma katmanında ele alınacağı söylendi.

> **Ek bilgi (derste anlatılmadı):** Source quench mesajının kullanımı, büyük olasılıkla RFC 6633 (2012) ile resmen kaldırılmıştır; günümüz TCP yığınları tıkanıklığı kendi mekanizmalarıyla anlar.

**Redirect.** Router paketi gidilecek yöne gönderebilir, ama kendi yönlendirme tablosuna baktığında bu paketin daha uygun, daha hızlı yönlendirilmesini sağlayacak başka bir router olduğunu bilir. Bu yüzden paketi gönderir, ama paketi ilk gönderen hosta da bir Redirect mesajı göndererek "bundan sonra bu yöne göndereceğin paketleri şu router üzerinden gönder" der. Bu bir optimizasyondur.

**Router advertisement/solicitation.** Slayttaki açıklaması "find a nearby router"dır. Hoca şu durumu düşündürdü: bir host açıldı; DHCP gibi bir şey olmadığını, daha ilkel bir ortam olduğunu varsayalım. Host kendi IP yapılandırmasını biliyor ama bulunduğu yerel ağdan nasıl çıkacağını bilmiyor. Ağ katmanının buna bir çözüm bulması gerekir. Çözüm, bağlı olunan yerel ağda router görevi gören ağ katmanlarının tespit edilmesidir. Bu da ağ katmanında yapılan, kontrollü bir yayın (broadcast), hatta bir yerde multicast olarak düşünülebilecek bir işlemdir. Bu paketi ICMP seviyesinde alan ve router olan host cevap verir; cevabı alan host da ağdan dışarı çıkmak için kullanacağı router'ı öğrenmiş olur.

ICMP mesajları bunlarla sınırlı değildir; bunlar en çok kullanılanlardır. Diğerleri IANA'nın sayfasında listelenir. Taşıma katmanında konuşulacak iyi bilinen (well-known) port numaraları gibi bilgiler de IANA'nın sitesinde yer alır.

## 3. ARP: IP Adresinden Ethernet Adresine

### 3.1 Katmanlı yapının ihlali

ARP (Address Resolution Protocol) ile katmanlar arası yalıtımın, katmanlı yapının biraz ihlal edildiği bir durum ortaya çıkar. Bir hosttan başka bir hosta ağ seviyesinde ağ adresiyle erişilir, ama bu erişim gerçekte alt katmandaki fiziksel adreslerle sağlanır. Örneğin Ethernet üzerinden bağlı bir hosta erişmek için alt seviyede kullanılacak adres IP adresi değil, o IP adresine karşılık gelen MAC adresidir. Bu yüzden ağ katmanı, yerel ağda erişmek istediği hostların yalnız IP adresini bilerek bu işi çözemez; IP adreslerine karşılık gelen MAC adreslerini de bilmesi gerekir. ARP bu işe yardım eden bir protokoldür.

> **Hocanın vurgusu:** ARP olmazsa bir yerel ağdaki iki host arasında IP trafiğini gerçekleştirme şansı yoktur; eşleşmelerin tek tek elle yazılması gerekir.

ARP ortaya atılmadan önce gerçekten de "bu IP'nin MAC adresi budur" diye elle yazma yöntemi uygulanmıştır. Hoca bunu DNS'in tarihine benzetti: hiyerarşik DNS yapısı kurulmadan önce herkesin düğüm adreslerini merkezden FTP ile indirmesi isteniyordu. Bu protokoller aslında bu elle yapılan işlerin otomatikleştirilmesidir; ARP'de de durum aynıdır, yalnız katmanı ve yeri farklıdır.

### 3.2 Slayttaki örnek topoloji

Slayt şu ağı gösterir (ekrandan, 00:35:00):

```text
CS Network 192.32.65.0/24                         EE Network 192.32.63.0/24

Host 1: IP1 = 192.32.65.7, E1 --+                 +-- Host 3: IP3 = 192.32.63.3, E5
                                |                 |
                      Ethernet switch -- Router -- Ethernet switch
                                |   E3          E4  |
Host 2: IP2 = 192.32.65.5, E2 --+                 +-- Host 4: IP4 = 192.32.63.8, E6

Router arayüzleri: E3 = 192.32.65.1 (CS tarafı), E4 = 192.32.63.1 (EE tarafı)
```

Soldaki ağ bilgisayar mühendisliğinin (computer science), sağdaki elektrik mühendisliğinin (electrical engineering) ağıdır. Slayttaki çerçeve tablosu, hedef Ethernet adreslerini pembe ile vurgular:

| Frame | Source IP | Source Eth. | Destination IP | Destination Eth. |
|---|---|---|---|---|
| Host 1 to 2, on CS net | IP1 | E1 | IP2 | E2 |
| Host 1 to 4, on CS net | IP1 | E1 | IP4 | E3 |
| Host 1 to 4, on EE net | IP1 | E4 | IP4 | E6 |

Adreslerin hangi ağda olduğu python ile denetlendi: 192.32.65.7, 192.32.65.5 ve 192.32.65.1 CS ağının (192.32.65.0/24), 192.32.63.3, 192.32.63.8 ve 192.32.63.1 EE ağının (192.32.63.0/24) içindedir.

### 3.3 ARP sorgusu nasıl çalışır

E1, E2 ve aynı Ethernet anahtarına bağlı olan router'ın E3 arayüzü bir yerel ağ oluşturur. Bunlar yayın (broadcast) mantığıyla, ek bir özelliğe ihtiyaç duymadan MAC adresleri ile IP adresleri arasında dönüşüm yapabilir:

1. Host 1, Host 2'ye erişmek ister. Host 2'nin IP adresini bilir ama MAC adresini bilmez.
2. MAC seviyesinde, bütün hostlara gitmesini sağlayan yayın adresini kullanır. Bu, bütün bitleri 1 olan, yani 12 tane F'ten oluşan MAC adresidir. Bu çerçeve bütün hostlara gider.
3. Hostlar gelen ARP sorgusuna bakar ve "benim adresim 192.32.65.5 mi?" diye kontrol eder. Değilse ilgilenmez, çöpe atar. Normalde bu adres tek bir hostta bulunur, çünkü ağ adreslerinin tekil olması gerekir.
4. Adresin sahibi "bu benim adresim" der ve sorguyu gönderen Host 1'e doğrudan cevap verir.

Host 2'nin, Host 1'in MAC adresini ayrıca bulmasına gerek yoktur, çünkü Host 1 sorguyu gönderirken kendi MAC adresini çerçevenin içine yerleştirmiştir.

> **Ders sonrası not:** Hoca bu adımda bir yerde "multicast" kelimesini kullandı; ARP sorgusu, hemen önce anlattığı gibi yayın (broadcast) adresine gönderilir.

Diğer hoca burada bir ekleme yaptı: yayın paketini ağdaki herkes görür, yalnız adresi sorulan host üstüne alıp cevap verir. Ama ağdaki diğer düğümler de isterse bu eşleşmeyi öğrenebilir; seslerini çıkarmazlar ama bilgiyi kenara koyup gerektiğinde kullanabilirler. Benzer şekilde Host 2'nin Host 1'e gönderdiği cevaptaki Host 2'nin MAC adresini de görebilirler.

### 3.4 ARP tablosu ve yaşam süresi

Hostlar, kendilerine gelen ya da gelmeyen bu sorgular ve cevaplarla bir ARP tablosu oluşturur. Bu tablodaki kayıtların bir yaşam süresi olmalıdır; bunun birkaç sebebi vardır:

- Hostlar sunucu gibi 7/24 kesintisiz hizmet vermek zorunda değildir; kapanıp açılabilirler, bir an vardırlar, bir an yokturlar.
- Hostun ağ kartı (bu örnekte Ethernet kartı) bozulup değiştirilebilir. MAC adresleri dünya çapında tekildir: uygulanan standartlar gereği iki farklı kartın aynı MAC adresine sahip olması mümkün değildir. Teorik olarak yapılabilir, ama üreticiler bunun olmamasını garanti eder. Kartı değişen bir hostun eski MAC adresi diğer tabloda kalırsa, bir yönetici tarafından elle silinmediği sürece o hosta ağda erişilemez.

Bu yüzden ARP tablosundaki kayıtların da bir yaşam süresi (time to live) vardır.

### 3.5 Router'ın özel durumu

Slaytta router özellikle çizilmiştir. Router iki farklı yerel ağa bağlıdır ve bunları ağ seviyesinde birleştirir. Oysa ARP yayını ağ seviyesinin altında, veri bağı katmanında, Ethernet olduğu için MAC alt katmanında gerçekleşir. Router bu yayın trafiğini bir taraftan diğerine aktarmaz; yani E1, E2, E3 tarafındaki MAC adresi bilgisi E4, E5, E6 tarafına gitmez.

Router ise iki tarafta da yayınları dinleyerek oradaki adresleri öğrenebilir. Böylece ağ seviyesinde geçiş yaparken IP adreslerinden MAC adreslerine geçişi şeffaf biçimde sağlar. O ana kadar öğrenmediği yeni bir IP adresi gelirse router, adres E3 tarafındaysa E3 tarafında, E4 tarafındaysa E4 tarafında ARP yayını yapar. Yayının sonucu gelene kadar paket router'da bekler.

### 3.6 Proxy ARP

Diğer hoca proxy ARP'den de bahsedilmesini önerdi. Bazı durumlarda bir hostun, gerçek sahibi olmasa bile bir adresi sahiplenmesi ve o adrese gönderilen paketlere cevap vermesi beklenir. Bu durumda host, adresin gerçek sahibi için bir vekil gibi, onun yerine davranır. Buna proxy ARP denir. Bunun örneği dersin sonunda Mobil IP'de görülür: home agent proxy ARP üzerinden mobil host adına cevap verir.

## 4. DHCP: Hostun Otomatik Yapılandırılması

### 4.1 Bir hostun ağa katılması için gerekenler

DHCP için ayrı bir slayt yoktu; konu sözlü anlatıldı. Bir IP ağına dahil olabilmek için şu bilgiler gerekir:

- Hostun kendi IP adresi.
- Ağ maskesi ya da önek (prefix). Sınıflı (classful) ya da sınıfsız (classless) çalışılsın, bir önek vardır ve bir maskeye karşılık gelir.
- Ağ geçidi (gateway), yani dışarı çıkışı sağlayacak router'ın adresi.
- En az bir, tercihen iki DNS sunucusu adresi.

Bu bilgiler olmadan bir hostun IP ağına dahil olması mümkün değildir.

Küçük ya da durağan, çok değişmeyen ağlarda bu bilgiler yapılandırma dosyalarına sabit olarak yazılabilir; hoca Unix'te `/etc` altındaki dosyaları örnek verdi. Ama hostların dinamik olarak katılıp ayrıldığı, kapanıp açıldığı büyük ağlarda (kampüs ya da metropol ölçeğinde) bunu elle yapmak hem iş gücü hem de oluşacak hatalar açısından mümkün değildir. İşin kuralları belirlenerek kontrollü biçimde otomatikleştirilmesi gerekir. Bu amaçla geliştirilen protokol DHCP'dir (Dynamic Host Configuration Protocol).

> **Ders sonrası not:** Hoca bu bilgilerin örneğin `/etc` altındaki "host" dosyasında yer aldığını söyledi. `/etc/hosts` büyük olasılıkla yalnız ad ile adres eşleşmelerini tutar; DNS sunucuları genelde `/etc/resolv.conf` dosyasında, IP adresi, maske ve gateway ise dağıtıma göre değişen ağ yapılandırma dosyalarında yazılır.

### 4.2 BOOTP'den DHCP'ye

DHCP'nin bir öncülü vardır: BOOTP (Boot Protocol). İşletim sistemi açılırken, yani boot sırasında ağ parametrelerini edinmek için tasarlanmıştır. Ama bazı kısıtları ve eksikleri vardır, her senaryoda düzgün çalışmaz. Bu yüzden günümüzde endüstri standardı haline gelmiş olan protokol DHCP'dir. DHCP'nin arkasında, kurallarla sınırları ve kısıtları belirlenmiş bir veri tabanı vardır.

### 4.3 DHCP'nin işleyişi

Ağa katılmak isteyen host, sahip olduğu temel adresle, yani veri bağı katmanındaki MAC adresiyle ağda özel bir yayın yapar; bir DHCP isteğinde bulunur. Diğer hoca bu ilk yayının adının DHCP Discover olduğunu ekledi. İstek DHCP sunucusuna ulaşınca sunucu kendi veri tabanını kontrol eder:

- Bu hosta belirli bir adres mi verilecek, yoksa bir havuz (pool) içinden rastgele bir adres mi?
- Maske (önek değeri), gateway adresi ve DNS sunucusu adres ya da adresleri belirlenir.

Bunlar paketlenip hosta gönderilir.

**Soru:** Hostun kendi adı da DHCP ile belirlenebilir, değil mi? **Cevap:** Evet. DHCP sunucusunda hosta adını parametre olarak vermek mümkündür. Bu bilgiyi kendi saklayamayan ya da yönetim kolaylığı için böyle planlanan hostlara, host adı ile birlikte ait olduğu alan adı (domain name) da aktarılabilir. İkisi bir araya gelince tam nitelikli alan adı (Fully Qualified Domain Name) oluşur: örneğin bir web adresinde "www" host adı, devamı alan adıdır.

DHCP sunucusu ile isteği gönderen cihaz normal şartlarda ya aynı ağda olmalı, doğrudan erişebilmelidir ya da aradaki başka ağlar varsa istek router'lar tarafından aktarılmalıdır (relay).

### 4.4 Kiralama süresi ve yedeklilik

Sunucu sürekli birilerine adres atar ve bu adreslerin belli bir geçerlilik süresi vardır, çünkü atanan adresin geri alınabilmesi beklenir. Adres bir kiralama (lease) süresi boyunca verilir. Kiralama bitmeden önce adresi almış olan cihaz yeniden istekte bulunmalıdır; bulunursa aynı adres tekrar atanır ve devam edilir. Kime hangi adresin, hangi havuzdan atandığı bilgisi bir veri tabanında saklanır. Sunucu kapanıp açıldığında ya da başına bir şey geldiğinde ortalık karışabilir; bu yüzden DHCP sunucusu genelde bir birincil ve bir ikincil olacak şekilde yedekli (failover) yapılandırılır. Büyük kurum ağlarında bu yüzden merkezi ama iki sunuculu bir yapı kullanılır.

## 5. Etiket Anahtarlama ve MPLS

### 5.1 Fikir

Diğer hoca konuya bir soruyla girdi:

**Soru:** MPLS'i, bağlantısız (connectionless) bir sistemi bağlantı yönelimliymiş (connection-oriented) gibi çalıştırıp bazı şeyleri daha kolay yönlendirebilmek için yapılmış bir yapı olarak düşünebilir miyiz? **Cevap:** Evet, MPLS (Multi-Protocol Label Switching) tam bu görevi yerine getirir.

IP'de yönlendirme kararı vermek için hedef adrese bakmak gerekir. Önceki derslerden hatırlanacağı gibi en uzun önek eşleşmesine (longest prefix matching) göre adresler toplanır (aggregation), gidilen yerde yeniden ayrıştırılır; Oxford ve Cambridge örneğinde böyle bir ayrıştırma vardı. Ama Amerika'dan çıkıp Avrupa'ya giden bir trafiği düşünelim: Avrupa'ya varana kadar paketin İngiltere'ye mi, Almanya'ya mı, Fransa'ya mı, İspanya'ya mı gideceğinin hiçbir önemi yoktur. Bunu IP seviyesinde yaparsak adresleri toplarız, ama toplanan gruplar yine de ayrı ayrı gruplar olarak kalır. Oysa trafik zaten Amerika'dan Avrupa'ya aktarılmaktadır; bunları bir üst seviyede tek bir bütün yapmak, hocanın deyişiyle "demetlerin demetini" yapmak mümkündür. MPLS bu amaçla, en hızlı ve en kolay iletim için oluşturulmuş bir yapıdır: anahtarlama (switching) ile çalışır ve anahtarlamayı etikete (label) göre yapar.

### 5.2 MPLS başlığı

Slayt şunları söyler (ekrandan, 00:45:00): "MPLS sends packets along established paths; ISPs can use for QoS. Path indicated with label below the IP layer." Başlıkların sırası şöyledir:

```text
| PPP | MPLS | IP | TCP | User data | CRC |
 <------- Headers -------->

MPLS başlığı (bit):
| Label (20) | QoS (3) | S (1) | TTL (8) |
```

Etiket alanı toplam 32 bittir: 20 bit asıl etiket, 3 bit hizmet kalitesi (QoS), 8 bit TTL, 1 bit de özel amaçlı (S) ayrılmıştır. $20 + 3 + 1 + 8 = 32$ olduğu python ile doğrulandı. Böylece her paket için ayrı ayrı IP tablosuna girip arama yapmaya, en uzun önek eşleşmesi yapıp adresleri toplamaya gerek kalmaz. Bir yoğunlaşma noktasında paketler ilgili etiketlerle etiketlenir ve yol boyunca o etikete göre gider.

Etiket alanı 20 bit olduğu için $2^{20} = 1\,048\,576$ farklı etiket değeri kullanılabilir. QoS alanı 3 bit olduğu için 0 ile 7 arasında 8 hizmet sınıfı belirtilebilir.

Elbette iki nokta arasında doğrudan tek atlamalık bir bağlantı varsa buna gerek yoktur: paket bir etikete konur, öbür taraftan çıkarken etiket yeniden açılır. Ama topoloji kendi içinde çok atlamalı olabilir; o zaman aktarım tamamen etiketteki değer üzerinden yürür. Hoca bunu sanal devre ağlarına benzetti: sanal devre bir kez kurulduktan sonra gelen paket yalnız sanal devre kimliğine göre aktarılır, başka bir şeye bakılmaz ve bu çok hızlıdır. MPLS, datagram ağlarında bu yapıyı kurup yönlendirme kararını en hızlı biçimde vermek ve paketleri bir grup olarak hedefe aktarmak için oluşturulmuştur. Günlük hayatta doğrudan kullanılan bir protokol değildir; daha çok ISP gibi yapıların içinde kullanılır.

### 5.3 Etiketin eklenmesi ve kaldırılması

Slayttaki başlık sırasında önce noktadan noktaya protokol (PPP), sonra MPLS başlığı, sonra IP başlığı gelir. Demek ki bir yerde IP paketinin başına etiket eklenmesi gerekir. İkinci slayt bunu gösterir (ekrandan, 01:00:00): "Label added based on IP address on entering an MPLS network (e.g., ISP) and removed when leaving it. Forwarding only uses label inside MPLS network."

```text
IP paketi --> [Label edge router: etiket ekle] --> router --> [Label switch router: yalnız etikete göre anahtarla]
          --> router --> [Label edge router: etiketi kaldır] --> IP paketi (sonraki ağa)
```

- Normal ağdan MPLS ağına geçişte etiketi ekleyen router'a Label Edge Router denir.
- İçeride atlamalı bir yapı vardır; buradaki her router MPLS'i anlayıp etikete göre iletmeye devam eder. Bunlara Label Switch Router denir.
- MPLS'te tek bir etiket olmak zorunda değildir; bir etiketin önüne bir etiket daha koymak mümkündür.

> **Hocanın vurgusu:** MPLS'in mantığı basit görünür, ama işletim ayrıntıları karışıktır; burada anlatılan, kavramı anlamaya yetecek kadar basitleştirilmiş halidir. Önemli olan şudur: normal bir datagram ağında anahtarlama yaparak bir devre oluşturulabilir.

Hocalar ayrıca slaytların özet olduğunu, bir slayt üzerinde dakikalarca konuşulup pek çok ayrıntı verildiğini, ek ayrıntıların ders kitabında yer aldığını ve kitaba da bakılması gerektiğini hatırlattı.

## 6. Otonom Sistemler ve OSPF

### 6.1 İç ve dış yönlendirme

OSPF'ye geçmeden önce diğer hoca çerçeveyi hatırlattı. İnternet, birbirine bağlanan farklı ağlardan oluşur. Bu ayrı ağların her birine otonom sistem (autonomous system, AS) denir. Her AS kendi içinde istediği yönlendirme algoritmasını kullanabilir; AS'lerin kendi içlerinde kullandıkları yönlendirme protokollerine iç (interior) protokoller denir. Bunlardan ayrı olarak, AS'ler arasındaki yönlendirmeyi daha esnek biçimde sağlayacak bir yapıya da ihtiyaç vardır; bunlara dış (exterior) gateway yönlendirme protokolleri denir ve bunun örneği BGP'dir. OSPF ise her AS'nin içinde, örneğin bir ISP'nin kendi içinde kullanılan yönlendirme protokolüdür.

### 6.2 OSPF

OSPF (Open Shortest Path First), link state yönlendirmenin TCP/IP kapsamında uygulanmış halidir. Link state yönlendirme akademik bir çalışma olarak ortaya atılmış, dağıtık biçimde en kısa yolu bulmaya çalışan bir yaklaşımdır. Bunun herkes tarafından uygulanabilen, gerçekleştirimi herkese açık ve TCP/IP ailesinde standart iç yönlendirme protokolü olarak kabul edilmiş haline OSPF denir; adındaki "Open", açık kaynaktaki "open" ile aynı anlamdadır.

Slayt şunu söyler (ekrandan, 01:15:00): "OSPF computes routes for a single network (e.g., ISP). Models network as a graph of weighted edges." Üstte gerçek ağ, altta onun grafı çizilidir:

```text
Gerçek ağ:
  LAN 1 -- R1 ---------- R3 --( LAN 3 )-- R5 -- LAN 4
            |          /          |
  LAN 2 -- R2 --------+          R4

Graf (yönlü kenarlar ve ağırlıklar):
  R1 -> LAN 1 : 1        R2 -> LAN 2 : 1
  R1 -> R3    : 5        R3 -> R1    : 5
  R1 -> R2    : 4        R2 -> R1    : 4
  R2 -> R3    : 7        R3 -> R2    : 8
  R3 -> LAN 3 : 3        LAN 3 -> R3 : 0
  R4 -> LAN 3 : 3        LAN 3 -> R4 : 0
  R5 -> LAN 3 : 4        LAN 3 -> R5 : 0
  R5 -> LAN 4 : 5
```

<!-- BELİRSİZ: Graf kenarlarının yönleri karedeki ok uçlarından okundu; R1-R3 arasındaki iki kenarın ve R2-R3 arasındaki 7 ve 8 ağırlıklı kenarların yönleri karede tam net değil. -->

Slayttaki not: "Broadcast LAN modeled as a well-connected node." R1, R2, R3, R4 ve R5'in birer düğüm olması doğaldır. Bir yerel ağ ise içinde birden fazla host barındırsa da tek bir düğüm olarak gösterilir, çünkü host sayısı burada önemli değildir. Yerel ağa ulaşıldıktan sonra, ARP örneğinde görüldüğü gibi, paket yerelde ARP ile teslim edilir. Yerel ağ düzeyinde dinamik bir yönlendirmeye gerek yoktur: paket ya doğrudan MAC adresiyle gönderilir ya da statik olarak yazılmış (ya da DHCP ile öğrenilmiş) gateway router üzerinden dışarı çıkar.

Bu ağda anlatılmak istenen, AS'ler arasında da yönlendirme yapılması gerektiğidir. AS'ler örgütsel, kurumsal, siyasi ya da ticari sebeplerle, ülke ya da kıta sınırlarıyla bir araya gelip bir bütün oluşturur. Bunlar arasında yönlendirme yapmak istendiğinde dış yönlendirme protokollerinden söz edilir.

### 6.3 OSPF alanları ve omurga

İkinci OSPF slaytında bir AS'nin kendi içinde alanlara bölündüğü gösterilir: sıfırıncı alan, birinci alan, ikinci alan. Sıfırıncı alanda omurga (backbone) açıkça görülür. Omurga olabilmesi için alternatif yollar olmalı, yani omurga birden fazla router içermelidir. Bir alanın içinde kalan router'lar iç (internal) router'lardır. Omurgadaki router'lar ise bir alandan diğerine trafiği aktarmak için vardır; birbirine alternatif otoyollar gibi düşünülmelidir.

> **Ders sonrası not:** Hoca bu slaytı anlatırken bir an "OSPF büyük bir ağı otonom sistemlere böler" dedi, hemen ardından "bir otonom sistem kendi içinde alt alanlara ayrılmış" diye düzeltti. Doğrusu ikincisidir: OSPF tek bir AS'nin içinde çalışır ve AS'yi alanlara (area) böler; AS'ler arası yönlendirme BGP'nin işidir.

<!-- BELİRSİZ: İkinci OSPF slaytının karesi yok; alan numaraları ve router türleri yalnız altyazıdan alındı. -->

OSPF'nin link state yönlendirmedeki genel mesajlara karşılık gelen mesajları şunlardır: hello, link state update, link state acknowledge, database description, link state request. Yine dağıtık biçimde, bütün router'lar Dijkstra algoritmasını kullanarak topoloji üzerinde en kısa yolu hesaplar.

## 7. BGP: Dış Yönlendirme Protokolü

### 7.1 Politika kısıtları

BGP (Border Gateway Protocol) bir "sınır kapısı" gibi düşünülebilir: bir kurumsal yapıdan başka bir kurumsal yapıya, bir otonom ağdan başka bir otonom ağa geçilir. İki ağ farklı AS'ler olarak sınıflandırılmışsa aralarında bir sınır geçit protokolü olmalıdır. Slayt şunu söyler (ekrandan, 01:20:00): "BGP computes routes across interconnected, autonomous networks. Key role is to respect networks' policy constraints."

Diğer hoca bunun sebebini açıkladı. Yönlendirmede normalde kullanılan ölçütler gecikme, paket kaybı gibi teknik ölçütlerdir ve iç yönlendirme protokolleri bunlara göre çalışır. Ama büyük AS'ler birbirine bağlandıktan sonra ölçütler çok farklı yerlere gidebilir. BGP bu farklı ölçütlerle yönlendirme yapabilmek için gereklidir: neyin olabileceğini, neyin olamayacağını, neye nasıl davranılacağını söyleyen bir yapı kurmayı sağlar.

Slayttaki örnek politika kısıtları:

- No commercial traffic for educational network (eğitim ağı üzerinden ticari trafik taşınmaz).
- Siyasi sebeplerle belirli bir ülke, belirli bir kaynaktan başlayan rotaya konmaz.
- Choose cheaper network (daha ucuz ağı seç).
- Choose better performing network (daha iyi performanslı ağı seç).
- Don't go from Apple to Google to Apple (bir şirketin iki noktası arasında rakip şirketin ağı üzerinden geçme).

Hoca ilk maddeyi açtı: bir eğitim ağı üzerinden ticari trafik akıtılamaz; bu bir kuraldır ve eğitim ağını işleten kurum trafiği bu açıdan izler. Bir adım ötesi de şudur: ulusal eğitim ağının yurt dışı çıkışı daha iyi olsa bile ticari bir servis sağlayıcı kendi trafiğini oradan gönderemez, çünkü onun trafiğinde ticari trafik de vardır. Bunlar teknik kısıtlar değildir:

> **Hocanın vurgusu:** BGP'deki kurallar teknik değil yönetimsel kısıtlardır: ticari, siyasi, para kazanılıp kazanılmaması, yardım amaçlı olup olmaması gibi. Teknik ölçütler ise paket kaybının düşük, güvenilirliğin yüksek, bant genişliğinin (bit/saniye) yüksek, gecikmenin düşük olmasıdır. BGP bu yönetimsel kuralların verilebilmesine imkân sağlar.

### 7.2 Transit ve peering

İkinci BGP slaytı şunu söyler (ekrandan, 01:25:00): "Common policy distinction is transit vs. peering. Transit carries traffic for pay; peers for mutual benefit. AS1 carries AS2↔AS4 (Transit) but not AS3 (Peer)."

```text
                        AS 1
          CU / TR      CU / TR       CU / TR
           |             |             |
         AS 2 <--PE--> AS 3 <--PE--> AS 4
           |             |             |
           A             B             C

Routing policy: TR = Transit, CU = Customer, PE = Peer
Kesikli çizgi: BGP yönlendirme duyurularının yolu
Düz çizgi: IP paketlerinin yolu
```

Hoca kavramları bir uçuş benzetmesiyle açıkladı: Amerika'ya bir Avrupa havayolu şirketiyle uçulursa uçak önce o şirketin merkezindeki havalimanına iner, oradan yolcu alıp Amerika'ya devam eder. Yolcu orada transit geçiş yapmış olur. Transit trafikte hedef doğrudan o AS değildir, ama trafiğin o AS üzerinden aktarılması gerekir. Customer (müşteri) ilişkisinde ise hedef doğrudan o AS'dir. Peer'ler ise birbirine denk olan AS'lerdir.

BGP'deki temel yaklaşım, trafiğin transit mi yoksa birbirine denk olanlar arasında mı olduğuna bakmaktır:

- Bir AS başkası için trafik taşıyorsa, taşıdığı trafik için genelde ücret alır. Hoca bunu yurt dışında dolaşım (roaming) üzerinden cep telefonu kullanmaya benzetti: kendi operatörünüzün gidilen yerdeki operatörle anlaşmasına göre o ağa da bir ücret ödersiniz.
- Peer'ler benzer hacimde karşılıklı trafik taşıdıkları için birbirine yarar sağlar; aralarında ödeme olmayabilir ya da başka biçimde düzenlenebilir.

Bunların hepsi yönetimle ilgili kurallardır, teknikle ilgili değildir. BGP bu tür kuralların konabilmesine ve trafiğin bu kurallara göre aktarılmasına izin verir; protokolün kendisinde çok karmaşık bir şey yoktur.

### 7.3 Yolun yayılması ve döngülerin kırılması

Ağa yeni bir AS eklendiğinde bu AS'nin bilgisi, eklendiği BGP router'ından başlayarak ona bağlı bütün diğer BGP router'larına adım adım aktarılır ve herkes onun ağa girdiğini öğrenir. Her BGP router'ı hangi BGP router'larıyla bağlı olduğunu bildiği için, daha önce Bellman-Ford'da görülen sorunlar olmadan tablolarını günceller ve hesaplarını yapar; hesapları yaparken de bu özel kuralları uygular.

Diğer hoca yol yayılmasını (route propagation) kısaca açıkladı: duyurular iletilirken geçilen her AS pakete eklenir ve böylece tam yol (full path) ortaya çıkar. Amaç döngüleri kırmaktır. Bir duyuru router'a geldiğinde router bakar: kendisi bu yolun içinde geçiyor mu? Geçiyorsa bir kapalı döngü vardır ve duyuruyu devam ettirmemelidir. Kapalı döngü oluşursa paketler hiçbir yere gidemez.

> **Hocanın vurgusu:** Kapalı döngü oluşmaması için duyuruda geçilen otonom sistemlerin, yani yolun, belirtilmesi gerekir.

## 8. İnternette Çoklu Yayın (Multicasting)

Hoca slaytı sondan okumaya başladı (ekrandan, 01:30:00): "IP multicasting is not widely used except within a single network, e.g., datacenter, cable TV network." Multicast'in çalışabilmesi için belirli şartların, sınırların olması gerekir. İnternetin tamamında multicast yapmak mümkün değildir; yayın (broadcast) ise zaten imkânsızdır. Demek ki kısıtlar gerekir. Bunun için bir multicast grubu oluşturmak, yani bir mesajın hangi hostlar tarafından alınacağını belirlemek gerekir. Başlangıçta bu elle yapılabilir, ama yönetilebilir değildir; otomatik olması gerekir.

Slayt şöyle der: "Groups have a reserved IP address range (class D). Membership in a group handled by IGMP (Internet Group Management Protocol) that runs at routers."

> **Hocanın vurgusu:** ICMP ile IGMP sürekli birbirine karıştırılan iki protokoldür, çünkü yalnız bir harf farklıdır (C ve G). Ama birbirlerinden çok farklıdırlar.

IGMP'nin amacı, IP ile konuşan hostların bir multicast grubu oluşturmak için dinamik olarak bir araya getirilmesi, grubun güncellenmesi ya da ortadan kaldırılmasıdır.

Slaytın ikinci kısmı: "Routes computed by protocols such as PIM: Dense mode uses RPF with pruning. Sparse mode uses core-based trees." Hoca bunu yönlendirme konusunda görülen iki yaklaşımla bağladı:

- **Yoğun (dense) grup:** Gruptaki host sayısı fazlaysa ters yol iletimi (reverse path forwarding) kullanılır. Çıkış noktasından varış noktalarına kadar ilerlenir, nerelerden geçildiği kaydedilir; dönüşte herkes ilerisinde ne olduğunu ve oraya nasıl gelindiğini öğrenmiş olur. Bütün hostlar olmasa da hostların büyük kısmının grupta olduğu kabul edilir.
- **Seyrek (sparse) grup:** Bu kez çekirdek tabanlı bir ağaç (core-based tree) kurulur. Az sayıdaki hostun arasından geçecek, onları kesecek bir iskelet, bir ana çekirdek yapısı oluşturulur; diğer hostlar multicast edilecek veriyi en yakın noktadan bu çekirdeğe aktarır.

Bunun ötesinde bir yaklaşım yoktur. Ayrıca internet multicast'i için sınıflı adreslemedeki D sınıfı kullanılır; sınıfsız ya da sınıflı çalışılması fark etmez, bu adresler her zaman multicast için ayrılmıştır ve internette yönlendirilebilir, erişilebilir host adresi olarak kullanılamaz.

> **Ek bilgi (derste anlatılmadı):** D sınıfı adres aralığı 224.0.0.0 ile 239.255.255.255 arasıdır (224.0.0.0/4); bu sınır python ile hesaplandı.

Diğer hoca bunun günlük hayattaki karşılığını hatırlattı: mobil operatörlerin ve servis sağlayıcıların IPTV uygulamalarının çoğu altta multicast kullanır. Hoca şu örneği verdi: iki servis sağlayıcı ticari ortaklık yapmış olsa ve son kullanıcı açısından aynı servis sağlayıcıdan hizmet alınıyormuş gibi görünse bile, bir sağlayıcının IPTV kutusu yalnız o sağlayıcının kendi hatlarının geldiği yerlerde çalışır, diğerinin altyapısının olduğu yerlerde çalışmaz. Çünkü ortada fiziksel olarak birbirinden bağımsız iki ağ vardır (biri baştan sona fiber, diğeri bir yere kadar fiber, sonrasında koaksiyel kablo kullanır) ve bu ağlar arasında multicast geçişi yoktur. Slayttaki "within a single network" ifadesi bu yüzden anlamlıdır: tek bir ağda multicast rahatça kullanılabilir, farklı ağlar söz konusu olduğunda internet multicast'ini kullanmak çok zordur.

## 9. Mobil IP

Son konu Mobil IP'dir. Slayt (ekrandan, 01:40:00): "Mobile hosts can be reached at fixed IP via a home agent. Home agent tunnels packets to reach the mobile host; reply can optimize path for subsequent packets. No changes to routers or fixed hosts." Slayttaki harita üzerindeki adımlar şunlardır:

1. Register care of address: mobil host, care-of adresini ev ağındaki home agent'a kaydettirir.
2. Send to home address: gönderici paketi mobil hostun ev adresine gönderir.
3. Tunnel to care of address: home agent paketi care-of adresine tüneller.
4. Reply to sender: mobil host göndericiye cevap verir.
5. Tunnel to care of address: gönderici sonraki paketleri doğrudan care-of adresine tüneller.

Hoca anlatımın IPv4'e göre olduğunu, IPv6'da buradaki pek çok şeyin değiştiğini ama hâlâ IPv4 kullanıldığı için bunun üzerinden gidileceğini söyledi.

Bir host bir yerde bir ağa bağlıdır ve oradan servis alır; bu hostun özelliği hareketli (mobile) olmasıdır. Servis aldığı yerde ona servis veren home agent adlı bir servis vardır. Hoca bunu çok basitleştirerek anlattığını, arkadaki gerçekleştirimin ciddi bir iş olduğunu belirtti. Home agent mobil hostun IP adresini ve MAC adresini kendinde tutar. Mobil host home agent'ın bulunduğu ağdaysa ve çalışıyorsa home agent hiçbir şey yapmaz, çünkü paketler doğrudan mobil hosta gelip gider.

Mobil host başka bir yere götürüldüğünde, IPv4'te ev ağındaki adresin aynısına sahip olması mümkün değildir; farklı bir adrese sahip olması gerekir. Buna care-of adresi denir: mobil hostu ağda erişilebilir kılmak için verilen geçici bir adrestir. Bu adresi foreign agent verir. Foreign agent, bulunulan bölgede home agent gibi çalışan ama görevi care-of adresi vermek, mobil hostların ağa katılmasını ve ağda hareket etmesini sağlamak olan başka bir servistir. Mobil host foreign agent'a "ben buyum, senin yetki alanındayım, bana bir adres ver; orijinal ev adresim şu, bağlı olduğum home agent bu" der. Foreign agent bu bilgiyi home agent ile kontrol eder.

Gönderici, mobil hostun hareketli olduğunun farkında değildir, bilmek zorunda da değildir. Mobil hostun ev ağındaki adresini bilir ve paketi oraya gönderir. Paketi home agent alır. Home agent, proxy ARP ile mobil hostun adresini üstlenmemiş olsaydı bu paket hedefine hiçbir zaman ulaşamazdı, çünkü mobil host orada değildir. Adresi üstlendiği için paketi mobil host adına alır ve mobil hostun foreign agent'ın yetki alanındaki yeni adresine gönderir. Home agent bu yeni adresi, foreign agent mobil hostu kaydedip care-of adresini verirken bu bilgiyi kendisine aktardığı için bilir. Böylece gönderici, mobil hostun gerçek adresine gönderdiğini düşünürken aslında onun o anki hareketli adresine göndermiş olur.

Mobil host göndericiden gelen pakete cevap verir; bunu doğrudan yapabilir, çünkü paketteki kaynak adresi bilir. Gönderici de bu cevapla mobil hosta şu an yeni bir adresten erişmesi gerektiğini öğrenir. Böylece sonraki paketler home agent üzerinden dolaşmak yerine doğrudan care-of adresine gönderilebilir.

Bu yapı gerçekten karmaşıktır ama çalışır. IPv6'ya tamamen geçilmiş olsaydı bu kadar karmaşık olmayacaktı: ev adresi ve care-of adresi meseleleri kendiliğinden çözülmüş olacak, mobil host nerede olursa olsun hep aynı adresten erişilebilir olacaktı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:45): Bir paketin bir noktadan çıkıp karşıdaki ağ katmanına varması ve cevabın geri dönmesine kadar geçen süreye ne denir? Bu süre ICMP'nin hangi mesajlarıyla ölçülür?

> **Çözüm:** Gidiş-dönüş süresi (round trip time) denir. Ölçüm ağ katmanının işi kabul edildiği için ICMP Timestamp request/reply mesajlarıyla yapılır; tek yön gecikmesi için genelde bu sürenin yarısı alınır.

**Soru 2** (derste sözlü, 00:35:23): ARP sorgusunu alan Host 2, cevabı gönderebilmek için Host 1'in MAC adresini ayrıca bulmak zorunda mıdır?

> **Çözüm:** Hayır. Host 1 yayın çerçevesini gönderirken kendi MAC adresini çerçeveye koymuştur; Host 2 bunu sorgudan öğrenir ve doğrudan Host 1'e cevap verir.

**Soru 3** (derste sözlü, 00:38:27): ARP tablosundaki kayıtlara neden bir yaşam süresi verilir ve bu süreye ne denir?

> **Çözüm:** Hostlar kapanıp açılabilir ve ağ kartı değişince MAC adresi değişir; eski kayıt kalırsa hosta erişilemez. Bu yüzden kayıtların bir yaşam süresi (time to live) vardır.

**Soru 4** (derste sözlü, 00:50:13): MPLS, bağlantısız bir datagram ağını bağlantı yönelimliymiş gibi kullanıp yönlendirmeyi kolaylaştırmak için yapılmış bir yapı olarak düşünülebilir mi?

> **Çözüm:** Evet. Paketler MPLS ağına girerken etiketlenir, içeride yalnız etikete göre anahtarlanır ve çıkarken etiket kaldırılır. Bu, sanal devrede paketlerin devre kimliğine göre aktarılmasına benzer.

**Soru 5** (derste sözlü, 01:30:29): Multicast grubunun elle değil, otomatik ve dinamik olarak oluşturulup yönetilmesi için hangi protokol kullanılır?

> **Çözüm:** IGMP (Internet Group Management Protocol). ICMP ile karıştırılmamalıdır.

**Soru 6** (ekrandan, 00:35:00): Slayttaki topolojide Host 1'den Host 4'e giden bir IP paketi CS ağında ve EE ağında hangi kaynak ve hedef Ethernet adreslerini taşır?

> **Çözüm:** Slayttaki tabloya göre CS ağında kaynak E1, hedef E3 (router'ın CS arayüzü); EE ağında kaynak E4 (router'ın EE arayüzü), hedef E6'dır. IP adresleri iki ağda da IP1 → IP4 olarak kalır.

## Dersin Toparlaması

Bu derste ağ katmanı bitirildi. Önce IP'nin yardımcı protokolleri işlendi: ağ katmanları arasında kontrol mesajlaşmasını sağlayan ICMP ve mesaj tipleri (`ping`, `traceroute`, DF biti ile Destination unreachable, Source quench'in sakıncası, Redirect, router bulma); IP adresinden MAC adresini yayınla bulan ARP, ARP tablosu, yaşam süresi, router'ın iki LAN arasındaki rolü ve proxy ARP; hostun adres, maske, gateway ve DNS bilgisini otomatik alan DHCP, kiralama süresi, relay ve yedeklilik. Ardından datagram ağında etiketle anahtarlama yaparak devre benzeri hızlı iletim sağlayan MPLS ve başlık yapısı anlatıldı.

İkinci kısımda yönlendirme internet ölçeğine taşındı: AS içinde link state tabanlı OSPF (graf modeli, alanlar ve omurga, Dijkstra) ve AS'ler arasında teknik değil yönetimsel politikalara göre çalışan BGP (transit ve peering, tam yol ile döngü kırma) işlendi. Son olarak D sınıfı adresler, IGMP ve PIM ile internet multicast'i ve home agent, foreign agent ve care-of adresiyle çalışan Mobil IP anlatıldı. Hocalar bir sonraki konunun taşıma katmanı olacağını, source quench ile başlayan akış ve tıkanıklık kontrolü tartışmasının orada sürdürüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
