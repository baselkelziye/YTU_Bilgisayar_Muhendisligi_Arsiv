# Ders 11 Genişletilmiş Notu: Ağ Savunmaları: Firewall, NAT, IDS ve VPN

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: On-Path ve Off-Path Saldırgan
- 2. Ağ Protokollerinde Gizlilik, Bütünlük ve Süreklilik
- 3. Ağın Kötü Niyetli Olduğunu Varsaymak
- 4. Tekrar: Denial of Service Saldırıları
- 5. Firewall ve Paket Filtreleme
- 6. Network Address Translation (NAT)
- 7. Network Firewall, Local Firewall ve Uygulama Seviyesinde Filtreleme
- 8. Saldırı Tespit Sistemleri (IDS)
- 9. VPN ve Zero Trust
- Örnek Sorular
- Dersin Toparlaması

## 1. Tekrar: On-Path ve Off-Path Saldırgan

Ders, bir önceki haftada işlenen ağ güvenliği konusunun tamamlayıcısıdır. Baştaki slaytlar geçen haftanın özetidir. Hoca burada web tarafını değil, ağ (network) tarafındaki saldırıları kastettiğini belirtti.

Ağ saldırılarında saldırgan iki konumda olabilir. Birincisinde doğrudan iki taraf arasındaki yolun üzerindedir; buna **on-path** (yolun üzerinde) saldırgan denir ve bu, man in the middle senaryosudur. İkincisinde saldırgan yolun kenarındadır; buna **off-path** saldırgan denir.

"Review: Off Path Attacker" slaytında (ekrandan, 00:05:00) iki uç arasındaki trafik bir kablosuz erişim noktası ve bir router üzerinden akar; saldırgan bu yolun üzerinde değil, router'a yandan bağlı bir noktadadır. Hoca buradaki tehlikeyi şöyle açıkladı: derste bugüne kadar görülen yöntemlerle bir sistemin kontrolü ele geçirilirse, bu sistemin sunucu olması gerekmez; router görevi gören bir host da ele geçirilebilir. O zaman bu sistemin üzerinden akan trafik kontrol edilebilir, kesintiye uğratılabilir, incelenebilir ve değiştirilebilir. Yani ağ saldırısı yapmak için illa hattın üzerinde olmak gerekmez; daha önce yapılmış başarılı bir saldırıyla dışarıdan da yoldaki trafiğe hâkim olunabilir.

## 2. Ağ Protokollerinde Gizlilik, Bütünlük ve Süreklilik

Hoca, confidentiality, integrity ve availability açısından ağ protokollerinin "bizi mutlu edecek" özellikler taşımadığını tekrarladı. En alt seviyede (fiziksel ve veri bağı katmanı) en çok kullanılan protokol Ethernet'tir; onun üzerinde IP, daha üstte UDP ve TCP vardır.

- **Gizlilik (confidentiality):** Bu protokollerin hiçbiri gizlilik sağlamaz, bu konuda bir yetenekleri yoktur. Her şey açık metin (clear text) olarak gidip gelir. Yol üzerindeki bir saldırgan her şeyi yapabilir. ARP ve BGP saldırıları ise sistemi bir buffer overflow ya da benzeri bir saldırıyla ele geçirmeye gerek kalmadan, yalnız doğru paketleri göndererek off-path saldırganı bir anda on-path hale getirir ve man in the middle saldırısını mümkün kılar.
- **Bütünlük (integrity):** Akan trafiğin değiştirilip değiştirilmediğini anlamak için bir kıyaslama ya da karşılaştırma noktası yoktur.
- **Kaynak doğrulama (source authentication):** Neredeyse yoktur. Tek istisna TCP'dir: oturum kurulurken üç paketlik değiş tokuşta gelen sıra (sequence) numaraları sayesinde ilk paketi ve ikinci paketi gönderenin aynı kaynak olduğu söylenebilir, ama bu çok zayıf bir doğrulamadır.
- **Süreklilik (availability):** Hizmetin devam edebilirliği açısından en basit örnek RST (reset) paketleridir. Geçen hafta görüldüğü gibi RST paketleriyle mevcut bir bağlantı uzaktan sonlandırılabilir.

## 3. Ağın Kötü Niyetli Olduğunu Varsaymak

Bu nedenle ağın kötü niyetli olduğu, ağdaki her unsurun saldırgan olduğu kabul edilir ve tedbirler buna göre alınır. "Assume network is malicious" slaytı (ekrandan, 00:10:00) şöyledir:

- **Always Assume:** The network is out to get you.
- **Solution:** Always use TLS if you want any protection against large-scale eavesdropping (e.g., intelligence agencies), or guarantee that data hasn't been modified or corrupted by an on-path attacker.
- **Note!** HTTPS and TLS aren't just for sensitive material! There have been attacks where malicious Javascript or malware is injected into websites.

### 3.1 TLS birinci kuraldır

Gönderilen ve alınan paketlerin, yani akıtılan trafiğin izlenmesini ve özellikle dinlenmesini istemiyorsanız transport layer security (TLS) kullanmak zorundasınız. Hocaya göre birinci kural budur; aksi halde trafiğin dinlenmediğinin ve bir kopyasının alınmadığının garantisi yoktur. TLS, yani kriptografi, bir noktaya kadar alınıp verilen bilginin değiştirilmediğini ve bozulmadığını da gösterir.

### 3.2 HTTPS her şeyi çözmez

HTTPS ve TLS kullanıldığı için kendimizi her zaman yüzde yüz korunmuş hissetmemek gerekir. Kötü niyetli JavaScript ya da zararlı yazılım (malware) bir web sitesine enjekte edildiyse, bağlantı HTTPS olsa bile bu kod bize gelir. Hoca daha önce dark web üzerinden gösterdiği örneği hatırlattı: bu örnekte bir yönetim konsolu, zararlı kodun kaç siteye bulaştığını ve hangi kullanıcıların bağlandığını gösteriyordu. Kod, doğrudan bağlı olduğumuz sunucudan geldiği için same origin principle ve cross origin resource sharing (CORS) için alınan tedbirlerin hepsi bir anda devre dışı kalır; çünkü sayfanın indirildiği sunucu saldırıya uğramış ve oraya zararlı kod yerleştirilmiştir.

Bu yüzden yalnız paylaşılan dokümanların değil, web sayfalarının da her şeyin şifreli konuşulduğu yapılara dönüştürülmesi gerekir. Hoca çerezlerle ilgili daha önceki konuyu da hatırlattı:

- Çerezler önce `HttpOnly` yapılmalıdır; böylece yerelde JavaScript çerezlere erişip onları kopyalayamaz.
- Araya giren saldırganın çerezleri normal bir istekle tarayıcıdan dışarı çıkarmaması için çerezler `Secure` özniteliğiyle işaretlenmelidir; böylece çerezler yalnız geçerli bir HTTPS bağlantısı kurulduysa gönderilir.

### 3.3 Kendi protokolünü yazmak

Ağ protokollerini düzeltmek, değiştirmek ya da yenilerini ortaya atmak da sorunludur. Bir protokolün olgunlaşması ve sayılan problemlerden etkilenmediğinin ortaya konması ciddi bir iştir. Bu yüzden düzgünlüğü analizlerle gösterilmiş mevcut protokoller kullanılmalıdır.

> **Hocanın vurgusu:** "Kendi network protokolümü yazarım, güvenliğimi de kendim sağlarım" demek çok daha can sıkıcı durumlara yol açabilir.

## 4. Tekrar: Denial of Service Saldırıları

Denial of service (DoS) saldırısının amacı bir servisi, bir ağı ya da bir organizasyonu devre dışı bırakmaktır. Bu, ağ trafiğiyle yapılır: oluşturulan trafik o kadar fazladır ki gerçek isteklere cevap verilemez. En önemli kriter, saldırganın çok fazla güç ve efor harcamaya ihtiyaç duymaması, buna karşılık kurbanın gelen istekleri işlemek ve cevaplamak için ciddi kaynak tüketmesidir.

### 4.1 Saldırı türleri

"Types of Attacks" slaytında iki tür vardır (ekrandan, 00:15:00):

- **DoS Bug:** design flaw that allows one machine to disrupt a service. Generally a protocol asymmetry, e.g., easy to send request, difficult to create response. Or requires server state.
- **DoS Flood:** control a large number of requests from a botnet or other machines you control.

Hoca, protokol tasarlamanın kolay görünebileceğini ama bu asimetrilerin hesaba katılmasının ciddi zorluk çıkardığını belirtti. Flood türünde ağ istekleri işlenemeyecek kadar çoktur ve genelde bir botnet ya da kontrol edilen başka sistemler üzerinden gönderilir. DoS her katmanda mümkündür: link, transport ve uygulama katmanında.

### 4.2 SYN flood ve amplification

TCP el sıkışmasına yönelik SYN flood'da saldırgan bir botnet üzerinden çok sayıda SYN paketi gönderir; hedef sistemin yapabileceği çok şey yoktur. Çözüm olarak durum (state) bilgisinin üç yönlü el sıkışma tamamlanana kadar tutulmaması anlatılmıştı; buna **SYN cookie** denir.

Amplification saldırılarında basit bir UDP paketiyle gönderilen sorgu çok büyük bir cevaba yol açar. Sahte (spoofed) IP adresleri kullanılır ve yine bir botnetten yararlanılır. Slayttaki diyagramda kurban (victim) sisteme, kendisi istemediği halde her taraftan DNS cevapları gelir; cevaplar büyük olduğu için bant genişliği daralır. DNS ve NTP sık kullanılan iki UDP yükselticisidir. Hocaya göre 2020'de bile internette herkesin erişimine açık, yanlış yapılandırılmış yüz binlerce böyle host vardır ve bu, amplification saldırıları için büyük bir fırsattır.

Hoca 2018'deki memcached saldırısında istek ile cevap arasındaki boyut oranının yaklaşık 1'e 50 bin olduğunu hatırlattı. <!-- BELİRSİZ: Altyazıda 2013, 2014 ve 2016 saldırılarına ve "2013'teki 300 gigabitlik saldırının 3 network kullanılarak gerçekleştirildiğine" kısaca değiniliyor; bu cümlelerin ayrıntısı altyazıdan net çıkmıyor. -->

### 4.3 Mirai

Hoca Mirai IoT botnet'inin bir ilk olduğunu ve kötü yazılmış olmasına, yeni ya da karmaşık bir şey içermemesine rağmen neden başarılı olduğunu üç maddeyle tekrarladı:

- IoT cihazlarındaki güvenlik seviyesi çok düşüktür.
- Saldırı basittir; IoT cihazlarının kullanım şeklinin basitliği çok farklı sistemlere saldırılabilmesini mümkün kılar.
- O zamana kadar taramalar çoğunlukla stateful'du ve stateful taramayı tespit etmek daha kolaydır. Mirai stateless tarama yaptığı için hem tespit edilmesi zordur, hem de az yük getirdiği için çok daha fazla cihaz kısa sürede taranabilir.

### 4.4 Project Shield ve GET flood

Google'ın Project Shield'ında önde bir proxy bulunur ve tamamlanmamış bağlantıları arkaya göndermez. Bu, sahte IP adresli saldırıları durdurur; ama saldırı bu kez GET flood'a dönüşür. "Moving Up Stack: GET Floods" slaytı (ekrandan, 00:20:00):

- Command bot army to: complete real TCP connection, complete TLS Handshake, GET large image or other content.
- Will bypass flood protections... but attacker can no longer use random source IPs.
- Victim site can block or rate limit bots.

Yani saldırı gerçek adreslerden yapılır, bağlantı kurulur, sonra ciddi trafik oluşturan GET istekleri gönderilir. Kurban belirli IP adreslerini engeller ya da onlara trafik sınırı koyar. Hoca bu bağlamda GitHub saldırısını hatırlattı.

> **Ders sonrası not:** Hoca GitHub saldırısının büyüklüğünü "1.35 TB per second" diye söyledi; doğrusu saniyede 1,35 terabittir (Tbps), terabayt değil.

### 4.5 Ingress filtering

Sahte IP adresleri kullanıldığında servis sağlayıcılara (ISP) büyük bir sorumluluk düşer. ISP arkasındaki adreslerin tamamını bilir; adresleri kendisi dağıtmış ve kullandırmaktadır. Bu yüzden kendi ağından gelemeyecek bir kaynak adresin dışarı çıkmasını engellemelidir. Buna **ingress filtering** denir: "ISP only forwards packets with legitimate source IP."

Sorun, ISP'lerin yüzde 10'u bile bunu yapmasa savunmanın devre dışı kalmasıdır. ISP'leri bunu yapmaya zorlayan bir şey yoktur, çünkü bu onlara kazanç değil ek yük getirir. Hocanın aktardığı 2017 verisine göre otonom sistemlerin %33'ü, duyurulan ve kullanımda olan IP adres bloklarının ise %23'ü sahte kaynak adrese (spoofing) izin veriyordu. Hoca bunun çok eski bir rakam olmadığını vurguladı.

### 4.6 Client puzzle

Client puzzle'da istemciyi, özellikle bağlantı kurarken yavaşlatmak için ona cevaplaması gereken bir soru sorulur. Bu soru CPU yoğun ya da bellek yoğun olabilir; istemcinin işlemci ve bellek kapasitesinin sunucudan düşük olduğu kabul edilir. Zararı şudur: saldırganı yavaşlatırken, gerçekten sorunsuz olan istemcilere de ek yük çıkarılır ve ek enerji tüketmelerine yol açılır.

## 5. Firewall ve Paket Filtreleme

Tekrar kısmından sonra hoca "buna karşı ne yapabiliriz?" sorusuyla savunmalara geçti.

### 5.1 Gereksiz açık servisler

Popüler TCP ve UDP servisleri standart portlardan hizmet verir; örneğin HTTPS 443'ten, SSH 22'den. Oysa bazı servislerin internetten erişilebilir olmasına bile gerek yoktur. Örnekler:

- **Recursive DNS resolver'lar:** Kendi domeni dışındaki istekleri de çözebilmek için bir üstteki, onun üstündeki, en tepeye kadar DNS sunucularına gidecek şekilde yapılandırılmış resolver'lar.
- **Windows dosya paylaşımı (Windows File Sharing):** Başından beri pek çok zafiyet içerir. En basitinden yerel tarafta çoğu zaman şifre bile kullanılmaz; bir bilgisayardan diğerine doğrudan erişilebilir.

Bunların hepsi zafiyet ve saldırı noktalarıdır.

### 5.2 Firewall

En kolay çözüm firewall kullanmaktır. "Firewalls" slaytı (ekrandan, 00:25:00): "Separate local area network (LAN) from the Internet. Only allow some traffic to transit. Sometimes rules on a router. Sometimes a standalone device." Diyagramda yerel ağ ile internet arasında bir router, router'a bağlı da bir firewall vardır. Router, bir taraftan diğerine aktaracağı her paket için firewall'a sorar. Router ile firewall bazen tek bir cihazdır.

Burada yapılan temel iş paket filtrelemesidir. Filtreleme şu beş alana göre yapılır; buna **five tuple** (beşli) denir:

- Kaynak IP adresi
- Hedef IP adresi
- Protokol
- TCP/UDP kaynak portu
- TCP/UDP hedef portu

Slayttaki örnek kural: "Drop all inbound packets to TCP port 445." Port 445 Windows dosya paylaşımıdır. Kural, internetten gelip içerideki herhangi bir hostun 445 numaralı portuna gidecek bütün paketlerin düşürülmesini, aktarılmamasını söyler.

### 5.3 Yalnız web sunucusuna erişim ve stateful filtering

Slayttaki ikinci soru: "What if you have a network with lots of servers but only want outsiders to be able to access the web server?" İçeride çok sayıda sunucu var, ama dışarıdan gelenlerin yalnız web sunucusuna erişmesi isteniyor. İlk akla gelen kural "hedef port 80'den farklıysa paketi düşür"dür.

Hoca bu kuralın sorununu gösterdi: içeriden dışarı çıkan bağlantıların da kaynak portları vardır. Kural böyle yazılırsa içeriden başlayan bir trafiğin geri dönüşü de engellenir ve içerideki hostlar dışarıyla konuşamaz hale gelir. Bu durumda içeriden başlayıp dışarı giden bir bağlantının dönüşüne izin vermek gerekir.

Bunun için portların numaralandırılmasıyla ilgili bir standart vardır:

- **0-1023:** Sistem tarafından kullanılan, well-known portlar. Servisler burada çalışır.
- **1024-49151:** Kullanıcıya açık ya da kaydettirilmiş (registered) portlar; well-known değil, "less well-known".
- **49152-65535:** Bağlantılar kurulurken dinamik olarak kullanılan portlar. Kullanıcı bir bağlantı açar, iki dakika sonra işi biter ve bağlantı kapanır; TCP ve UDP'nin sağladığı çoğullama (multiplexing) bu portlarla gerçekleşir.

> **Ders sonrası not:** Altyazıda ilk aralık "1 ile 23 arası" diye geçiyor; büyük olasılıkla Whisper "1023"ü bozmuştur. Standart well-known aralığı 0-1023'tür.

Çözüm **stateful filtering**'dir: firewall dışarıya giden bağlantıları takip eder ve buna bağlı olarak dönüşte ilgili porta paket gelmesine izin verir. Böylece filtre hem dış hem iç yönde iki taraflı çalışır.

## 6. Network Address Translation (NAT)

Bir başka yapı network address translation'dır: içeride kullanılan adreslerle dışarıda kullanılan adresler birbirinden farklıdır. "Network Address Translation (NAT)" slaytı (ekrandan, 00:30:00): "NATs map between two different address spaces. Most home routers are NATs and firewalls."

Slayttaki diyagramda yerel ağdaki (Private IP Address `192.168.X.X`) üç bilgisayarın adresleri `192.168.100.3`, `192.168.100.4` ve `192.168.100.5`'tir. Router/NAT cihazının yerel taraftaki adresi, yani varsayılan ağ geçidi (default gateway) `192.168.1.1`'dir; internetteki public adresi `145.12.131.7`'dir.

> **Ders sonrası not:** Hoca public adresi "145.12.131.17" diye okudu; slaytta `145.12.131.7` yazıyor (ekrandan, 00:30:00).

Yerel ağdaki adresler tamamen özel (private) adreslerdir; başka yerel ağlarda da aynen kullanılabilirler, çünkü bu yerel ağlar birbirinden router'lar ve NAT cihazlarıyla ayrılmıştır. Slayttaki özel alt ağlar (Private Subnets):

| Aralık | Hocanın andığı sınıf |
|---|---|
| `10.0.0.0 - 10.255.255.255` | A sınıfı, en büyüğü |
| `172.16.0.0 - 172.31.255.255` | B sınıfı |
| `192.168.0.0 - 192.168.255.255` | C sınıfı, en küçüğü |

> **Ek bilgi (derste anlatılmadı):** Bu üç aralık CIDR gösteriminde `10.0.0.0/8`, `172.16.0.0/12` ve `192.168.0.0/16`'dır ve sırasıyla 16.777.216, 1.048.576 ve 65.536 adres içerir (python `ipaddress` modülüyle kontrol edildi). "A/B/C sınıfı" adlandırması eski sınıflı adreslemeden gelir: ilki tek bir A sınıfı ağ, ikincisi 16 B sınıfı ağ, üçüncüsü 256 C sınıfı ağdır.

## 7. Network Firewall, Local Firewall ve Uygulama Seviyesinde Filtreleme

### 7.1 Network firewall ve local firewall

Şimdiye kadar konuşulan, iç ağ ile dış ağı birbirinden ayırmaktı; bu yüzden bunlara **network firewall** denir. Ayrıca hostların üzerinde de firewall servisi çalıştırılabilir; buna **local firewall** denir. Örneğin Linux'ta iptables vardır. Çoğunlukla ikisi birlikte kullanılır: iç ağı internetten filtrelemek için ağ sınırında bir network firewall, hostların üzerinde de local firewall.

### 7.2 Uygulama seviyesinde filtreleme

Bir başka yaklaşım uygulama seviyesinde filtrelemedir. Örnekler:

- **E-posta virüs taraması:** Protokolün ve MIME kodlamasının anlaşılması gerekir; ek zip, jpeg, pdf ya da başka bir şey olabilir. E-postanın içeriği tamamen açılıp virüs taramasından geçirilir, sorun yoksa kullanıcıya aktarılır.
- **SQL injection için HTTP POST isteklerinin incelenmesi:** Gelip giden paketlerde SQL injection için kullanılabilecek özel yapılar aranır: tırnak işareti, yan yana iki eksi işareti (`--`) ya da `or 1=1` gibi ifadeler.

### 7.3 Dışarı çıkan trafik

Dışarı çıkan trafiğin de incelenmesi gerekir. Pek çok kurum maliyeti yüzünden bunu yapmak istemez, ama hocaya göre yapılmalıdır. Nedenleri:

- Kötü niyetli olduğu bilinen sitelere erişimi engellemek.
- Kurum dışına istenmeyen verinin çıkarılmasını engellemek.
- Kullanımı sıkıntılı olan ve organizasyonun bant genişliğini daraltan uygulamaları devre dışı bırakmak. <!-- BELİRSİZ: Hocanın verdiği örnek altyazıda "bit donatı servisi" diye geçiyor; büyük olasılıkla BitTorrent kastediliyor. -->

## 8. Saldırı Tespit Sistemleri (IDS)

Intrusion detection (saldırı tespiti), dışarıdan ya da içeriden gelen trafikte oluşturulmuş ağ kurallarını ihlal eden bir durum olup olmadığını anlamak için uygulanan sistemdir. Böyle bir durum fark edildiğinde **SIEM** (Security Information and Event Management) denilen sistemlere ne fark edildiğini, ne zaman ve nerede fark edildiğini içeren bir rapor gönderilir.

İki yaklaşım vardır:

- **Signature detection:** Kural tabanlıdır; kurallara bağlı olarak "bu olmalıydı, bu olmamalıydı" denir.
- **Anomaly detection:** Yapay zekâ ve makine öğrenmesi üzerine kuruludur; son dönemde derin öğrenme de kullanılır. Normalden sapmalar anomali olarak değerlendirileceği için önce normalin öğrenilmesi gerekir.

Açık kaynak IDS olarak üç sistem anıldı: Snort, Suricata ve Zeek. Hocaya göre Snort en eski ve en yaygınlaşmış olanıdır.

> **Ders sonrası not:** Hoca Zeek'i "son dönemde" çıkan sistem olarak andı. Büyük olasılıkla Zeek, 1990'lardan beri geliştirilen Bro'nun 2018'de değişen adıdır; dolayısıyla Suricata'dan daha eskidir.

### 8.1 Örnek Snort kuralı

"Example Snort Rule" slaytındaki kural (ekrandan, 00:35:00):

```text
alert icmp 192.168.1.10 any -> any any (msg: "ICMP Attempt Attack"; sid:1000005)
```

Kural iki kısımdan oluşur. Parantez öncesi **rule header**, parantez içi **rule option**'dır:

| Alan | Değer |
|---|---|
| Action | `alert` |
| Protocol | `icmp` |
| Source Address | `192.168.1.10` |
| Source Port | `any` |
| Direction | `->` |
| Destination Address | `any` |
| Destination Port | `any` |
| Rule Option | `msg: "ICMP Attempt Attack"; sid:1000005` |

Hocanın okumasıyla: ICMP protokolünde bir paket `192.168.1.10`'dan geliyorsa, hangi hosta ve hangi porta giderse gitsin alarm üretilir ve "ICMP Attempt Attack" mesajı log'a basılır ya da log sunucusuna gönderilir. `msg` mesaj kısmıdır.

## 9. VPN ve Zero Trust

### 9.1 Virtual private network

Sonraki slaytlar sanal özel ağ (VPN) ve uzaktan erişimle ilgilidir. Mantık basittir: internet herkesin kullanımına açıktır ve internetteki sıkıntılar bilinmektedir. Bu sıkıntılar varken internetteki herhangi bir yerden kurumsal çalışma ortamına nasıl erişilecek? Bunun için internetin üzerinde sanal olarak özel (private) ağlar oluşturulur.

En çok karşılaşılan iki temel tip vardır:

- **Uzaktan bağlantı (remote client):** Hareket halindeki bir çalışan (satıcı, pazarlamacı, mühendis) kurumsal ağına bağlanmak ister.
- **İki lokasyonun birbirine bağlanması:** Aynı kurumun farklı illerdeki, hatta farklı ülkelerdeki lokasyonları birbirine bağlanır.

Kullanılan protokoller çok çeşitlidir. En çok kullanılan IPsec'tir; IPsec, Internet Engineering Task Force (IETF) tarafından oluşturulmuş bir protokoldür. Buna karşılık açık kaynak OpenVPN vardır; benzer bir çalışmayla, kamuya açık (public domain) olarak oluşturulmuştur. Hocaya göre bu dönemde en çok bu ikisi kullanılmaktadır. Ticari ürünlere örnek olarak Cisco AnyConnect anıldı. <!-- BELİRSİZ: Cisco AnyConnect'in yanında anılan ikinci ürün altyazıda "GUI Middle" diye bozulmuş; adı çıkarılamadı. -->

### 9.2 Zero Trust Security

Son kavram **Zero Trust Security**'dir. İç ağların (intranet) güvenli olduğu artık düşünülmez, çünkü saldırıların büyük kısmı iç ağdan gelir. O zaman servislerin tamamı internette olur; internete açık olanı korumak için zaten ekstra çaba harcanacaktır. Örneğin Google gibi bir ortamda bütün servisler herkese açık bir yerde barındırılır ve böylece uygulamalar ve ağ doğrudan korunur.

> **Ek bilgi (derste anlatılmadı):** Zero Trust yaklaşımında erişim kararı, kullanıcının iç ağda olup olmamasına göre değil, her istekte kullanıcının ve cihazın kimliği ile durumu doğrulanarak verilir. Google'ın bu yaklaşımı kendi içinde uygulamasının adı BeyondCorp'tur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:04): Araya giren bir saldırganın, tarayıcıdaki çerezleri normal bir istekle dışarı çıkarmasını önlemek için ne yapılmalıdır?

> **Cevap (derste verildi):** Çerezler `Secure` özniteliğiyle işaretlenmelidir; böylece yalnız geçerli bir HTTPS bağlantısı kurulduysa gönderilirler. Yerel JavaScript'in çerezlere erişip kopyalamasını önlemek için de `HttpOnly` gerekir.

**Soru 2** (derste sözlü, 00:11:30): Ele geçirilmiş bir sunucudan gelen zararlı JavaScript'in etkisini azaltmak için yalnız paylaşılan dokümanlar değil, web sayfaları da neye dönüştürülmelidir?

> **Cevap (derste verildi):** Her şeyin şifreli (encrypted) konuşulduğu yapılara, yani HTTPS/TLS kullanan sayfalara dönüştürülmelidir.

**Soru 3** (derste sözlü, slayttan okundu, 00:26:23): "What if you have a network with lots of servers but only want outsiders to be able to access the web server?" İçeride çok sayıda sunucu varken dışarıdan yalnız web sunucusuna erişim nasıl sağlanır, "hedef port 80 değilse düşür" kuralı neden yetmez?

> **Cevap (derste verildi):** Bu kural, içeriden başlatılan bağlantıların dinamik portlara (49152-65535) gelen dönüş paketlerini de düşürür ve içerideki hostlar dışarıyla konuşamaz. Çözüm stateful filtering'dir: firewall dışarı giden bağlantıları takip eder ve yalnız bu bağlantıların dönüş paketlerine izin verir.

**Soru 4** (ekrandan, 00:35:00): `alert icmp 192.168.1.10 any -> any any (msg: "ICMP Attempt Attack"; sid:1000005)` kuralının alanları nelerdir ve kural ne yapar?

> **Cevap (derste verildi):** Action `alert`, protocol `icmp`, kaynak adres `192.168.1.10`, kaynak port `any`, yön `->`, hedef adres ve hedef port `any`; parantez içi rule option'dır. `192.168.1.10`'dan gelen her ICMP paketi için "ICMP Attempt Attack" mesajıyla alarm üretilir ve log'a ya da log sunucusuna yazılır.

## Dersin Toparlaması

Ders, önceki haftadaki ağ saldırılarının tekrarıyla başladı: off-path bir saldırgan bir router'ı ele geçirerek ya da ARP/BGP gibi kimlik doğrulaması olmayan protokolleri kullanarak on-path olabilir, çünkü Ethernet, IP, TCP ve UDP gizlilik, bütünlük ve kaynak doğrulama sağlamaz. Buradan çıkan ilke ağın her zaman kötü niyetli olduğunu varsaymak ve TLS kullanmaktır; ama sunucunun kendisi ele geçirilmişse HTTPS de tek başına koruma sağlamaz. DoS tekrarında protokol asimetrisi, SYN flood ve SYN cookie, amplification, Mirai, Project Shield'a karşı GET flood, ingress filtering ve client puzzle hatırlatıldı.

Dersin yeni kısmı ağ savunmalarıydı: five tuple'a göre paket filtreleyen firewall, dönüş trafiğine izin veren stateful filtering ve port aralıkları, iki adres uzayını eşleyen NAT ve özel alt ağlar, network ve local firewall, uygulama seviyesinde ve çıkış trafiğinde filtreleme, signature ve anomaly tabanlı IDS'ler ile örnek bir Snort kuralı, son olarak VPN tipleri ve iç ağa güvenmeyen Zero Trust yaklaşımı. Hoca bu dersle dönem başında duyurduğu konuların (güvenlik kavramları, işletim sistemleri, web ve ağ güvenliği) neredeyse tamamlandığını belirtti; mobil güvenlik ayrı bir derste işlendiği için bu derste ayrıntısına girilmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
