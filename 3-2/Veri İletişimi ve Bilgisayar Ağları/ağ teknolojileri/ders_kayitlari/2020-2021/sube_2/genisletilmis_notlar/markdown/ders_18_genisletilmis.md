# Ders 18 Genişletilmiş Notu: Taşıma Katmanı: Hizmetler, Primitifler, Berkeley Soketleri ve Bağlantı Kurulumu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Taşıma Katmanına Giriş
- 2. Üst Katmanlara Verilen Hizmetler
- 3. TPDU, Segment ve Kapsülleme
- 4. Çoğullama ve Transport Entity
- 5. Taşıma Hizmeti Primitifleri
- 6. Basit Bağlantı Yönelimli Hizmetin Durum Diyagramı
- 7. Berkeley Soketleri
- 8. Soket Örneği: İnternet Dosya Sunucusu
- 9. Taşıma Protokollerinin Öğeleri ve Adresleme
- 10. Bağlantı Kurulumu ve Üç Yönlü El Sıkışma
- Örnek Sorular
- Dersin Toparlaması

## 1. Taşıma Katmanına Giriş

Bu derste kitabın 6. bölümü olan taşıma katmanına (transport layer) geçildi. Ağ katmanında yapıldığı gibi bu katman da önce genel kavramlar, sonra İnternet'teki gerçek protokoller üzerinden incelenecektir. Bölüm kapağı başlıkları şöyle sıralar (ekrandan, 00:05:00):

- Transport Service
- Elements of Transport Protocols
- Congestion Control
- Internet Protocols – UDP
- Internet Protocols – TCP
- Performance Issues
- Delay-Tolerant Networking

Slaytta son iki başlık soluk renkte gösterilir. Taşıma katmanı tamamlandıktan sonra uygulama katmanından örnek uygulamalara bakılacağı söylendi.

Derste ilk vurgulanan nokta, veri bağı, ağ ve taşıma katmanlarındaki yapının benzerliğidir. Her üçünde de iki seçenek vardır: ya bağlantı yönelimli (connection-oriented) ya da bağlantısız (connectionless) çalışılır. Gerçek hayatta ağ katmanında IP kullanılır ve IP bağlantısızdır.

Ağ katmanı ile taşıma katmanı aynı türden olduğunda (ikisi de bağlantısız ya da ikisi de bağlantı yönelimli) işler oldukça temiz yürür ve iki katmanın çalışma mantığı birbirine çok benzer. Türler farklı olduğunda iş zorlaşır:

- Bağlantısız bir ağ üzerinde bağlantı yönelimli bir taşıma hizmeti çalıştırılıyorsa güvenilirliği (reliability) taşıma katmanı sağlamak zorundadır. TCP'nin IP üzerinde yaptığı budur.
- Tersi de olabilir: bağlantı yönelimli bir ağın üzerinde bağlantısız bir taşıma hizmeti vermek gerekebilir. Derste verilen örnek, WiMAX üzerinde UDP çalıştırmaktır.

## 2. Üst Katmanlara Verilen Hizmetler

"Services Provided to the Upper Layers (1)" slaytı taşıma katmanının görevini tek cümleyle verir: "Transport layer adds reliability to the network layer." Taşıma katmanı uygulamalara bağlantısız (örneğin UDP) ve bağlantı yönelimli (örneğin TCP) hizmet sunar (ekrandan, 00:15:00).

Slayttaki şekil iki makineyi (Host 1 ve Host 2) katman katman gösterir:

| Öğe | Şekildeki yeri |
|---|---|
| Application (or session) layer | Her makinenin en üst kutusu |
| Transport address | Uygulama katmanı ile taşıma katmanı arasındaki bağlantı noktası |
| Application/transport interface | Uygulama ile taşıma katmanı arasındaki sınır |
| Transport entity | Taşıma katmanındaki kutu |
| TPDU | İki transport entity arasında taşınan birim |
| Transport protocol | İki transport entity arasındaki konuşma kuralları |
| Network address | Taşıma katmanı ile ağ katmanı arasındaki bağlantı noktası |
| Transport/network interface | Taşıma ile ağ katmanı arasındaki sınır |
| Network layer | Her makinenin alt kutusu |

Şekilde Host 2'nin taşıma katmanında üç ayrı bağlantı noktası çizilidir; bu, aynı makinede birden çok uygulamanın taşıma katmanını kullanabildiğini gösterir.

### 2.1 Neden ayrı bir taşıma katmanı var

Ağın kendisi, 3. katman cihazlardan oluşan bir ISP ağı ya da genel bir ağ olabilir. Taşıma katmanını ise son kullanıcılar tarafında, uç sistemlerde kullanırız. Bunun nedenleri:

- Bir soyutlama katmanı (abstraction layer) sağlar ve yapıyı tek tipleştirir.
- Güvenilirlik getirir.
- Farklı ağlar üzerinde rahatça çalışmayı sağlar. Taşıma katmanı olmasaydı uygulamalar doğrudan ağ katmanına erişir, bu durumda her uygulamanın her farklı ağ için farklı hizmetleri kullanacak şekilde uyarlanması gerekirdi. Taşıma katmanı bu işi üstlendiğinde alttaki ağın değişmesinden etkilenilmez.

Bir de işin ekonomik yanı vardır. Servis sağlayıcılar bu ek özellikleri ağ katmanında vermenin altına girmek istemez; çünkü bu özellikler bir maliyet ve yatırım getirir, üstelik sorumluluğu da almak gerekir. Bunun yerine servis sağlayıcı ağ katmanı seviyesinde kalır ve ek özellikler uçlarda, taşıma katmanında sağlanır.

## 3. TPDU, Segment ve Kapsülleme

Hocalardan biri slayttaki tanımların (transport entity, network address, transport address vb.) önemli olduğunu ve üzerinden geçmekte fayda olduğunu belirtti.

TPDU (transport protocol data unit), iki taşıma katmanı arasında taşınan veriye verilen addır. Hoca bu adın artık pek kullanılmadığını, eski belgelerde kaldığını söyledi; güncel kullanımda buna segment denir. Katmanlara göre veri birimlerinin adları:

| Katman | Veri birimi |
|---|---|
| Veri bağı katmanı | Çerçeve (frame) |
| Ağ katmanı | Paket (packet) |
| Taşıma katmanı | Segment (eski adıyla TPDU) |

"Services Provided to the Upper Layers (2)" slaytı kapsüllemeyi gösterir: "Transport layer sends segments in packets (in frames)" (ekrandan, 00:30:00). Şekil iç içe üç kutudan oluşur:

```text
+--------------+------------------------------------------------------+
| Frame header | +---------------+----------------------------------+ |
|              | | Packet header | +----------------+-------------+ | |
|              | |               | | Segment header | Segment     | | |
|              | |               | |                | payload     | | |
|              | |               | +----------------+-------------+ | |
|              | +---------------+----------------------------------+ |
+--------------+------------------------------------------------------+
               |<------------------- Frame payload ------------------>|
                               |<--------- Packet payload --------->|
```

Segmentte taşıma katmanına ait başlık bilgilerinin yanında, bir üst katmandan (uygulamadan) aktarılan bilgi de vardır. Segment başlığı ve segment yükü bir bütün olarak ağ katmanına verilir; paketin yükü bununla dolar. Hoca bunu iç içe bebeklere (matruşka) benzetti: bebeğin içinden bebek çıkar. En dışta çerçeve vardır, çerçevenin bir başlığı vardır; onun içine paket gömülüdür, paketin de başlığı vardır; onun içinde de başlığıyla birlikte segment bulunur.

Büyük bir veri segmente, pakete ya da çerçeveye indirgenirken parçalara bölünerek taşınır.

## 4. Çoğullama ve Transport Entity

### 4.1 Çoğullama (multiplexing / demultiplexing)

Bir makinede aynı anda birden fazla uygulama ağı kullanır. Bu uygulamaların verisinin ayrıştırılması için taşıma katmanında bir çoğullama (multiplexing) ve ayrıştırma (demultiplexing) yapılması gerekir; ağ katmanında olmayan şey budur. Hoca bunu bir apartman benzetmesiyle açıkladı: çoğumuz apartmanlarda otururuz; apartmanın bir numarası vardır, ama içindeki dairelerin de ayrı numaraları vardır. Apartman numarası makinenin ağ adresine (IP adresi), daire numarası ise taşıma adresine (port) karşılık gelir.

### 4.2 Transport entity

Ağ katmanı için nasıl bir süreç çalışıyorsa taşıma katmanı için de orada çalışan bir yapı vardır. Bu yapı işletim sisteminin bir parçası, bir kütüphane ya da bir süreç olabilir; hangisi olursa olsun genel adı transport entity'dir. Hoca bunun kart seviyesinde, yani ağ arayüz kartının (NIC) içinde bile gerçeklenmiş olabileceğini ekledi.

## 5. Taşıma Hizmeti Primitifleri

Hoca, kitabın taşıma katmanını adeta iki kez anlattığını belirtti: önce "olması gereken", yani ideal ve basit bir taşıma katmanında hangi hizmetlerin ve bu hizmetleri karşılayacak hangi primitiflerin olması gerektiği; sonra gerçek hayatta IP üzerinde kullanılan taşıma katmanının, yani TCP'nin neler sağladığı. Bu yüzden ilk kısımda ayrıntıya fazla girilmedi. Bağlantısız hizmet daha basit olduğu için onda bu kadar ayrıntıya gerek yoktur.

Primitifler, protokol rollerinin çalıştırılabilmesi, tetiklenmesi ve bir durumdan başka bir duruma geçebilmesi için gereken işlemlerdir. "Transport Service Primitives (1)" slaytı basit bir bağlantı yönelimli hizmet için uygulamaların çağırabileceği primitifleri verir (ekrandan, 00:35:00):

- Client calls CONNECT, SEND, RECEIVE, DISCONNECT
- Server calls LISTEN, RECEIVE, SEND, DISCONNECT

| Primitive | Segment sent | Meaning |
|---|---|---|
| LISTEN | (none) | Block until some process tries to connect |
| CONNECT | CONNECTION REQ. | Actively attempt to establish a connection |
| SEND | DATA | Send information |
| RECEIVE | (none) | Block until a DATA packet arrives |
| DISCONNECT | DISCONNECTION REQ. | This side wants to release the connection |

İstemci açısından CONNECT bağlantı isteği oluşturur, SEND gönderir, RECEIVE alır ve doğal olarak DISCONNECT bağlantıyı bitirir. Bağlantı yönelimli hizmetin temel yapısı hatırlatıldı: önce bağlantı kurulur, sonra veri alışverişi yapılır, en sonda bağlantı sonlandırılır. CONNECT bir "aç parantez" gibi düşünülürse DISCONNECT de onun "kapa parantezi"dir.

LISTEN ile hiçbir segment gönderilmez; LISTEN bir segmentin gelmesini bekler. RECEIVE için de aynısı geçerlidir: gönderilen bir segment yoktur, bir DATA segmentinin gelmesi beklenir.

Bir makinenin istemci ya da sunucu olması birbirini dışlayan durumlar değildir; aynı makine bir haberleşmede istemci, diğerinde sunucu olabilir.

Hoca primitiflerin ayrıntısına burada girmeye gerek olmadığını, aynı primitiflerin Berkeley soketlerinde yeniden konuşulacağını söyledi.

### 5.1 Bağlantıyı kesmenin iki biçimi

Bağlantı kurulumu CONNECT ile yapılır, ama DISCONNECT iki farklı biçimde gerçeklenebilir: simetrik ve asimetrik. Haberleşmede karşılıklı iki taraf vardır. Bir tarafın bağlantıyı koparma isteği yalnız daha fazla veri göndermeyecek olmasından kaynaklanabilir, ya da o taraf artık ne veri almak ne de vermek istiyor olabilir. Örneğin bir taraf yalnız veri göndermekten vazgeçmiş, ama karşıdan gelecek veriyi dinlemeye hâlâ istekli olabilir.

- **Simetrik kesme:** Bağlantı iki ayrı tek yönlü bağlantı gibi düşünülür: biri istemciden sunucuya, biri sunucudan istemciye. Her taraf kendi yönünü kapatır; karşı tarafın da göndermeyi kestiğini bildirmek için bir DISCONNECT mesajı göndermesi ya da primitifini çalıştırması gerekir.
- **Asimetrik kesme:** Taraflardan herhangi birinin DISCONNECT demesi yeterlidir; iletişim tamamen kesilir.

<!-- BELİRSİZ: altyazıda simetrik ve asimetrik tanımları karışık geçiyor ("Bu simetrik bir yapı olabilir ... Asimetrik değilse herhangi bir tarafın disconnect demiş olması yeterli"); yukarıdaki tanımlar anlatımın bütününden kuruldu. -->

## 6. Basit Bağlantı Yönelimli Hizmetin Durum Diyagramı

"Transport Service Primitives (2)" slaytı basit bir bağlantı yönelimli hizmetin durum diyagramını verir (ekrandan, 00:40:00). Slayttaki açıklamalar:

- Solid lines (right) show client state sequence (düz çizgiler, sağda: istemcinin durum dizisi).
- Dashed lines (left) show server state sequence (kesikli çizgiler, solda: sunucunun durum dizisi).
- Transitions in italics are due to segment arrivals (italik geçişler segment gelişiyle olur).

Diyagramdaki geçişler tablo olarak:

| Başlangıç durumu | Olay | Varılan durum | Taraf |
|---|---|---|---|
| IDLE | Connect primitive executed | ACTIVE ESTABLISHMENT PENDING | İstemci |
| ACTIVE ESTABLISHMENT PENDING | *Connection accepted TPDU received* | ESTABLISHED | İstemci |
| IDLE | *Connection request TPDU received* | PASSIVE ESTABLISHMENT PENDING | Sunucu |
| PASSIVE ESTABLISHMENT PENDING | Connect primitive executed | ESTABLISHED | Sunucu |
| ESTABLISHED | Disconnect primitive executed | ACTIVE DISCONNECT PENDING | Kesmeyi başlatan |
| ACTIVE DISCONNECT PENDING | *Disconnection request TPDU received* | IDLE | Kesmeyi başlatan |
| ESTABLISHED | *Disconnection request TPDU received* | PASSIVE DISCONNECT PENDING | Karşı taraf |
| PASSIVE DISCONNECT PENDING | Disconnect primitive executed | IDLE | Karşı taraf |

Hoca diyagramı, ortadaki ESTABLISHED durumunun üstündeki ve altındaki yapıların birbirine benzediği, yukarıdaki iki kutunun aşağıdaki iki kutuyla eşleştiği biçiminde yorumladı: üstte bağlantı kurulurken aktif ve pasif taraf, altta bağlantı kesilirken aktif ve pasif taraf vardır. <!-- BELİRSİZ: altyazıda bu yorum bozuk geçiyor ("passive establishment pending ile passive disconnecting ..."). -->

### 6.1 Sunucu neden bağlantıyı başlatmaz

Diğer hoca bu noktaya bir ekleme yaptı. Sunucunun bağlantıyı başlatan taraf olamamasının temel nedenlerinden biri, istemcileri tek tek bilmesinin mümkün olmamasıdır. Bir yere erişmek istediğimizde doğrudan bir sunucuya erişiriz; çünkü sunucular için ayrılmış belirli adlar, adresler ve hizmetler için portlar vardır. Google'a eriştiğimizde aslında onun bir değil birden çok IP adresinden birine erişiriz. Google'ın bize tersten erişmesi ise mümkün değildir: IP adreslerimiz sürekli değişir, cihazlarımız sürekli açık değildir; işin doğası böyledir. Sunucu kime bağlanacağını bilmez, bu yüzden bu anlamda başlatan taraf olamaz.

## 7. Berkeley Soketleri

"Berkeley Sockets" slaytı (ekrandan, 00:45:00):

- Very widely used primitives started with TCP on UNIX (UNIX'te TCP ile başlayan, çok yaygın kullanılan primitifler).
- Notion of "sockets" as transport endpoints (taşıma uç noktası olarak soket kavramı).
- Like simple set plus SOCKET, BIND, and ACCEPT (basit kümeye SOCKET, BIND ve ACCEPT eklenmiş hâli).

| Primitive | Meaning |
|---|---|
| SOCKET | Create a new communication end point |
| BIND | Associate a local address with a socket |
| LISTEN | Announce willingness to accept connections; give queue size |
| ACCEPT | Passively establish an incoming connection |
| CONNECT | Actively attempt to establish a connection |
| SEND | Send some data over the connection |
| RECEIVE | Receive some data from the connection |
| CLOSE | Release the connection |

Önceki basit primitiflerden farklı olarak burada SOCKET, BIND ve ACCEPT vardır; geri kalanlar aynıdır.

### 7.1 SOCKET ve BIND

SOCKET primitifinin temel amacı yeni bir soket, yani haberleşmenin uç noktasını tanımlayan bir yapı oluşturmaktır. SOCKET çalıştırıldığında bir soket oluşur, ama bu sokete doğrudan ağ adresi bilgisi verilmez. Bunun için BIND gerekir.

BIND, hem sunucu hem istemci tarafında çalıştırılan bir primitif değildir; sunucu tarafında çalıştırılır. Nedeni önceki konuyla bağlantılıdır: Google'a erişmeye çalıştığınızda onun hangi portuna erişeceğinizi bilirsiniz ve o porta yönelirsiniz. Kendi tarafınızdaki portun hangisi olduğunun ise bir önemi yoktur; 60 numaralı porttan mı, 70'ten mi, 3217'den mi çıktığınızın anlamı yoktur. Karşı taraftaki sunucunun ise her zaman sabit, belirli bir adresi olmalıdır ki herkes ona doğrudan bağlanabilsin. Bu yüzden BIND ihtiyacı sunucu tarafındadır. İstemcinin portunun ise iyi bilinen (well-known) portların üstünde kalan bir aralıktan rastgele atandığı ileride görülecektir.

> **Ek bilgi (derste anlatılmadı):** İstemci de isterse `bind` çağırıp belirli bir yerel port seçebilir; ancak bu genelde gerekmez. `bind` çağrılmadan `connect` yapılırsa işletim sistemi istemciye geçici (ephemeral) bir port atar.

İyi bilinen portlar, bu işin içindeki kişilerin bildiği varsayılan 0-1023 aralığındaki portlardır. Bu portlardan haberleşecek bir uygulamayı ayağa kaldırmaya çalıştığınızda root yetkisi (root şifresi) istenir; aksi hâlde çalıştıramazsınız.

### 7.2 LISTEN ve ACCEPT

LISTEN ile beklenir, karşı taraftan bir hareket beklenir; basit modelde bu bloklayan bir yapıdır. Ancak Berkeley gerçeklemesinde LISTEN bloklamaz. LISTEN yalnız gelen istekler için bir kuyruk oluşturulacağını söyler ve bu bekleme yapısının başlatılmasını (initialize) sağlar. Primitifin backlog (kuyruk boyu) gibi parametreleri de vardır.

ACCEPT ise gelen bağlantı isteğinin kabul edileceği duruma geçmeyi sağlar. Berkeley gerçeklemesinde asıl bloklayan yapı ACCEPT'tir. ACCEPT'in önemli bir özelliği vardır: bir soket üzerinden dinler, o adres üzerinden isteğin gelmesini beklersiniz. İstek geldiğinde, ona cevap verirken aynı adrese gelebilecek diğer istekleri de dinlemeye devam etmeniz gerekir. Bu yüzden bir bağlantı isteği geldiğinde onu arka tarafta başka bir yere aktarıp oradan devam edersiniz. Bu aktarma işini ACCEPT yapar: ACCEPT yeni bir tanımlayıcı (descriptor) döndürür. Bu tanımlayıcı üzerinden, sizinle CONNECT ile iletişime geçmiş olan istemciye bilgi gönderebilir ya da ondan bilgi alabilirsiniz.

Hoca bunu bir örnekle pekiştirdi: bir sunucunun 80 numaralı portuna bağlantı yapıldığını, ama o portta herhangi bir anda yalnızca tek bir bağlantı yapılabildiğini düşünün. Google aynı anda on binlerce, abartırsak milyonlarca kişiye hizmet verir; böyle bir kısıt olsaydı taşıma seviyesindeki çoğullamanın bir anlamı kalmazdı. <!-- BELİRSİZ: örneğin devamı altyazıda kesik; bağlantıların nasıl ayrıştırıldığı açık geçmiyor. -->

### 7.3 SEND ve RECEIVE

RECEIVE ile karşı taraftan bilgi gelmesi beklenir; doğası gereği bloklayan bir yapıdır. Ancak şu göz ardı edilmemelidir: size hiç bilgi gelmeyebilir ya da belli bir süre sonunda gelmiyorsa bu işi durdurmak isteyebilirsiniz. Berkeley soketleri SEND ve RECEIVE için, ikisinde de yapının bloklayan olup olmayacağını seçme imkânı sunar.

## 8. Soket Örneği: İnternet Dosya Sunucusu

Bu örnek uygulamada da yapılacağı için kısaca geçildi; konuşulan bütün primitifler örnekte adım adım yer alır.

### 8.1 İstemci kodu

İstemci kodunun ilk kısmı anlatımda şöyle açıklandı. Önce soket açılır: İnternet soket tipinde, akış (stream) yapısında ve TCP protokolüyle çalışan bir soket. Soketin üç parametresi vardır: protokol ailesi (İnternet), tip (stream; çünkü datagram değil, TCP olduğu için bir bayt akışı gönderilecek) ve protokol (TCP). Sonra bir yapı (structure, örnekte `channel`) oluşturulur ve ona adres tipi, adres ve port verilir. Burada dikkat edilmesi gereken nokta host ve network bayt sırasıdır: port numarası atanırken `htons` (host to network, `s` = short; `l` olsaydı long) kullanılır. Sunucunun port numarası 16 bit olduğu için short olarak geçer ve dönüştürülerek yapıya aktarılır. Ardından bağlantının başlatılması, yani bir bağlantı isteği oluşturulması gerekir; bunun için CONNECT primitifi kullanılır ve hangi soketten bağlantı yapılacağı verilir. <!-- BELİRSİZ: istemci kodunun ilk slaytı ("Internet File Server (1)") karelerde yok; bu kısım yalnız anlatımdan kuruldu, kod satırları ekrandan doğrulanamadı. -->

İstemci kodunun devamı (ekrandan, 01:00:00):

```c
. . .
write(s, argv[2], strlen(argv[2])+1);   /* Write data (equivalent to send) */

while (1) {                              /* Loop reading (equivalent to receive) */
    bytes = read(s, buf, BUF_SIZE);      /* until no more data;                  */
    if (bytes <= 0) exit(0);             /* exit implicitly calls close          */
    write(1, buf, bytes);
}
}
```

Slayttaki yan açıklamalar: "Write data (equivalent to send)" ve "Loop reading (equivalent to receive) until no more data; exit implicitly calls close". Kod parçadır, `main` içermez; derlenmedi.

Bu kodda şu noktalar konuşuldu:

- Terminale yazarken de sokete yazarken de `write` kullanılır; hiçbir şey değişmez. Bunların hepsi sonuçta tanımlayıcıdır (descriptor): süreç kontrol bloğundan hatırlanacağı gibi 0, 1, 2, 3 diye giden tamsayı değerler. `write(1, buf, bytes)` karşı tarafın gönderdiğini soketten okuduktan sonra standart çıktıya (stdout) yazar; terminal başka bir yere yönlendirilmişse oraya gider.
- `read`'in parametreleri soketten (`s`), `buf`'a, en çok `BUF_SIZE` kadar okunacağını söyler, ama dönüş değerine (`bytes`) mutlaka bakılmalıdır. Siz 1 KB okumak isteyebilirsiniz ama size daha az veri gelmiş olabilir. Doğru yaklaşım, gelebilecekten daha büyük bir yer açıp veriyi oraya kopyalamak ve gelen miktarı kontrol etmektir.
- `bytes` sıfır ya da daha küçükse ya bir problem vardır ya da artık veri gelmemektedir (sıfır); dosya bitmiştir. Program ekrana yazıp çıkar.

> **Ders sonrası not:** Altyazıda "1K okumak istersiniz ama size 100 byte ya da 10 byte daha fazla gelmiş olabilir" diye geçiyor. `read` hiçbir zaman istenen `BUF_SIZE`'tan fazla bayt döndürmez; istenenden daha az dönebilir. Kontrolün amacı da budur.

### 8.2 Sunucu kodu

Sunucu kodu (ekrandan, 01:05:00):

```c
. . .
memset(&channel, 0, sizeof(channel));
channel.sin_family = AF_INET;
channel.sin_addr.s_addr = htonl(INADDR_ANY);
channel.sin_port = htons(SERVER_PORT);

s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);          /* Make a socket */
if (s < 0) fatal("socket failed");
setsockopt(s, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));

b = bind(s, (struct sockaddr *) &channel, sizeof(channel));   /* Assign address */
if (b < 0) fatal("bind failed");

l = listen(s, QUEUE_SIZE);                              /* Prepare for incoming connections */
if (l < 0) fatal("listen failed");
. . .
```

Kod parçadır, `main` içermez; derlenmedi.

Sunucuda hangi adresten ve hangi porttan gelecek isteklerin dinleneceği belirlenir. Örnekte `INADDR_ANY` kullanılmıştır: `INADDR` İnternet adres formatını, `ANY` ise isteğin herhangi bir adresten gelebileceğini belirtir. İstenseydi yalnız belirli bir adresten bağlantı kabul edilebilirdi.

Diğer hoca burada bir ekleme yaptı: bir cihazda birden fazla arayüz (interface) olabilir ve her arayüzün üzerinde birden fazla adres olabilir. Sunucu her arayüzden ve her adresten gelen bütün isteklere cevap verecekse `INADDR_ANY` kullanılır. Ama bu zorunlu değildir; belli bir arayüze, o arayüzdeki adreslere ya da yalnız tek bir adrese gelen isteklere cevap verecek şekilde de kurulabilir. Arayüz listesini ve adres listesini sorgulamak için gereken fonksiyonlar kütüphanede vardır.

Port için `htons` (host to network short) kullanılırken, adres 4 bayt olduğu için `htonl` (host to network long) kullanılır. Sonra soket oluşturulur, `bind` ile adres ailesi, hangi arayüzden (ya da hepsinden) ve hangi porttan dinleneceği sokete bağlanır, ardından `listen` ile dinlemeye başlanır.

> **Ek bilgi (derste anlatılmadı):** İnternet protokollerinde çok baytlı alanlar "network byte order" denen büyük sonlu (big-endian) sırayla taşınır. x86 gibi küçük sonlu (little-endian) makinelerde `htons`/`htonl` baytların sırasını çevirir; büyük sonlu makinelerde hiçbir şey yapmaz.

### 8.3 Kuyruk boyu (backlog)

`listen`'e verilen `QUEUE_SIZE` kadar istemci size bağlanabilir ve kuyrukta bekleyebilir. Tek bir süreç olsanız ve herkese tek tek hizmet veriyor olsanız bile ilk bağlananın işini yaparsınız; backlog'unuz 5 ise diğer 5 istemci kuyrukta bekler. 6. istemci geldiğinde kuyruğa giremez ve bağlantı isteği başarısız olur, çünkü kuyrukta yer yoktur.

> **Ders sonrası not:** Kuyruk dolduğunda ne olacağı işletim sistemine bağlıdır. Linux'ta büyük olasılıkla yeni bağlantı isteği sessizce düşürülür ve istemci isteği bir süre sonra yeniden dener; bazı sistemler ise bağlantıyı reddeder.

Bundan sonra sunucu, her gelen istek için ACCEPT ile yeni bir tanımlayıcı alır, onun üzerinden bilgi alıp verir ve yazar.

### 8.4 Soketi kapatmak

Hoca, öğrencilerin yazdığı kodlarda çoğu zaman soketin, yani dosya tanımlayıcısının düzgün kapatılmadığını belirtti. Soket kapatılmazsa o sokete atanmış port hâlâ kullanımda görünür. Sunucuyu kapatıp yeniden açmaya kalktığınızda "port already in use" hatası alıp zaman aşımı (timeout) olana kadar beklemede kalabilirsiniz.

Ayrıca bütün işletim sistemlerinde bir sürecin aynı anda açabileceği dosya tanımlayıcısı sayısının (dosya, soket ya da başka bir giriş/çıkış cihazı fark etmez) bir üst sınırı vardır. Kapatılmayan her tanımlayıcı bu sınırdan yer.

> **Ek bilgi (derste anlatılmadı):** TCP'de bağlantıyı ilk kapatan taraf bir süre TIME_WAIT durumunda kalır; bu sürede aynı port yeniden `bind` edilmek istenirse "address already in use" hatası alınabilir. Sunucu kodundaki `setsockopt(..., SO_REUSEADDR, ...)` satırı bu durumda portun yeniden kullanılabilmesini sağlar.

### 8.5 Soketlerle başka neler yapılabilir

Birden fazla transport entity olabilir; işletim sistemine gömülü çekirdeğin içinde yer alabilir ya da kütüphane olabilir. Soket ailesi olarak İnternet dışında örneğin `AF_UNIX` da vardır, ama burada kullanılan İnternet ağıdır, yani TCP/IP'ye karşılık gelen aile.

Soketle oluşturulan yapı illa TCP ya da UDP taşımak zorunda değildir. Doğrudan IP paketi de oluşturabilirsiniz: sokete ham (raw) olarak erişip üstüne kendi yapınızı kurabilirsiniz. ICMP paketi gönderecekseniz soketi ham (raw) olarak tanımlayıp protokolü ICMP olarak verebilirsiniz. Yani bu örnekteki seçeneklerle sınırlı değilsiniz; ayrıntısına bakmakta fayda vardır.

## 9. Taşıma Protokollerinin Öğeleri ve Adresleme

"Elements of Transport Protocols" slaytı bu bölümün başlıklarını sıralar (ekrandan, 01:10:00):

- Addressing (adresleme)
- Connection establishment (bağlantı kurulumu)
- Connection release (bağlantının bırakılması)
- Error control and flow control (hata kontrolü ve akış kontrolü)
- Multiplexing (çoğullama)
- Crash recovery (çökmeden kurtarma)

Bu öğeler veri bağı katmanında hata kontrolü ve akış kontrolü için görülenlere benzer; bağlantı yönelimli olanların karmaşıklığı, bağlantısızlarınkinden farklıdır. Çökmeden kurtarma, sürecin ya da makinenin çökmesi gibi durumlarda, durum bilgisi kaybolduğunda yapılması gerekenlerle ilgilidir.

"Addressing" slaytı (ekrandan, 01:15:00):

- Transport layer adds TSAPs (taşıma katmanı TSAP'ler, yani taşıma hizmeti erişim noktaları ekler).
- Multiple clients and servers can run on a host with a single network (IP) address (tek bir IP adresine sahip bir makinede birden çok istemci ve sunucu çalışabilir).
- TSAPs are ports for TCP/UDP (TCP/UDP'de TSAP'ler portlardır).

Şekilde Host 1'deki uygulama süreci TSAP 1208'e bağlıdır; Host 2'de Server 1 TSAP 1522'ye, Server 2 TSAP 1836'ya bağlıdır. Ağ katmanında her makinenin bir NSAP'i (ağ hizmeti erişim noktası) vardır. Taşıma bağlantısı (transport connection) Host 1'deki TSAP 1208'den, iki makinenin NSAP'leri üzerinden, Host 2'deki TSAP 1522'ye uzanır. Bu, apartman benzetmesindeki "aynı bina, farklı daire" fikrinin şekle dökülmüş hâlidir.

## 10. Bağlantı Kurulumu ve Üç Yönlü El Sıkışma

### 10.1 Ana sorun

"Connection Establishment (1)" slaytı (ekrandan, 01:20:00):

- Key problem is to ensure reliability even though packets may be lost, corrupted, delayed, and duplicated (ana sorun, paketler kaybolabildiği, bozulabildiği, gecikebildiği ve çoğalabildiği hâlde güvenilirliği sağlamaktır).
  - Don't treat an old or duplicate packet as new (eski ya da kopya bir paketi yeni gibi işleme).
  - (Use ARQ and checksums for loss/corruption) (kayıp ve bozulma için ARQ ve sağlama toplamı kullan).
- Approach (yaklaşım):
  - Don't reuse sequence numbers within twice the MSL (Maximum Segment Lifetime) of 2T=240 secs (sıra numaralarını MSL'nin iki katı, 2T = 240 saniye, içinde yeniden kullanma).
  - Three-way handshake for establishing connection (bağlantı kurmak için üç yönlü el sıkışma).

Hoca dört durumu tek tek ele aldı ve slaytta altı çizili olan iki durumun (gecikme ve kopya) asıl sorun olduğunu gösterdi:

- **Kayıp:** Paketin gelmediği anlaşılabilir; ama bu yanlış bir karar verdirmez.
- **Bozulma:** Paket bozulup hedefine gittiyse bu aslında iyi bir durumdur; çünkü paketin bozulduğu fark edilir ve o paket işlenmez.
- **Gecikme:** Gecikmenin üst sınırı bilinmez. Ne kadar beklenirse gecikme kabul edilecek? Ya bir saniye daha beklenseydi ve o sırada paket gelseydi? Belli bir süreden sonra gelmeyen paket kayıp gibi, gelmemiş gibi kabul edilir.
- **Kopya:** Bir paketin daha önce gelip gelmediğinin kaydını tutmak gerekir, çünkü protokol bir durum yapısıyla çalışır. Aynı paketten bir daha geldiğinde ama durum zaten değiştirilmişken iki seçenek vardır: durumu geri alıp aynı geçişi yeniden yapmak ya da bu paketin daha önce işlendiğini anlayıp onu bir daha işlememek. Doğrusu ikincisidir.

Sonuç olarak işlenmiş ya da süresi geçmiş bir paket yeni bir paket olarak işlenmemelidir. Bunun için ağda bir segmentin en uzun yaşama süresi (MSL) saniye cinsinden bir zaman olarak kullanılır. Slayttaki değerle $2T = 240$ s olduğundan $T = 120$ s'dir.

### 10.2 Üç yönlü el sıkışma

"Connection Establishment (3)" slaytı (ekrandan, 01:25:00):

- Three-way handshake used for initial packet (ilk paket için üç yönlü el sıkışma kullanılır).
  - Since no state from previous connection (çünkü önceki bağlantıdan kalan bir durum bilgisi yoktur).
  - Both hosts contribute fresh seq. numbers (iki makine de taze sıra numarası katar).
  - CR = Connect Request (bağlantı isteği).

Şekildeki mesaj dizisi (zaman aşağı doğru akar):

| Adım | Yön | Mesaj |
|---|---|---|
| 1 | Host 1 → Host 2 | CR (seq = x) |
| 2 | Host 2 → Host 1 | ACK (seq = y, ACK = x) |
| 3 | Host 1 → Host 2 | DATA (seq = x, ACK = y) |

Anlatımda: önce bağlantı isteği ilk sıra numarasıyla gelir. Karşı taraf buna kendi sıra numarasıyla cevap verir. Sonra bağlantıyı başlatan taraf bunu kabul eder ve iki sıra numarasını veriyle birlikte yeniden gönderir. Böylece hem kopya (duplicate) bağlantı isteğine hem de gecikmiş (delayed) bağlantı isteğine karşı korunulmuş olunur. Şekilde Host 1 istemcidir. TCP'de bu bağlantı isteği "synchronization" kelimesinin kısaltması olan SYN ile geçer.

Sıra numaraları neden önemlidir? Host 2'nin kendisine gelen paketleri sıraya sokması gerekir. IP'de anlatıldığı gibi büyük bir veri gönderilirken bayt bazında parçalara bölünür; bu parçaların alıcıda doğru sırayla birleştirilmesi sıra numaralarıyla yapılır. Üç adımdan sonra veri akışı normal biçimde devam eder.

### 10.3 Garip durumlara karşı koruma

"Connection Establishment (4)" slaytı üç yönlü el sıkışmanın garip durumlara karşı nasıl koruduğunu iki senaryoyla gösterir (ekrandan, 01:30:00):

- a) Duplicate CR. Spurious ACK does not connect (kopya CR; sahte ACK bağlantı kurdurmaz).
- b) Duplicate CR and DATA. Same plus DATA will be rejected (wrong ACK) (kopya CR ve DATA; aynısı, artı DATA reddedilir, çünkü ACK yanlıştır).

Senaryo (a):

| Adım | Yön | Mesaj | Sonuç |
|---|---|---|---|
| 1 | Host 1 → Host 2 | CR (seq = x), eski kopya | Host 2 bunu yeni bir istek sanır |
| 2 | Host 2 → Host 1 | ACK (seq = y, ACK = x) | Host 1 böyle bir istek göndermemiştir, ACK'i tanımaz (X) |
| 3 | Host 1 → Host 2 | REJECT (ACK = y) | Bağlantı kurulmaz |

Senaryo (b):

| Adım | Yön | Mesaj | Sonuç |
|---|---|---|---|
| 1 | Host 1 → Host 2 | CR (seq = x), eski kopya | Host 2 bunu yeni bir istek sanır |
| 2 | Host 2 → Host 1 | ACK (seq = y, ACK = x) | Host 1 ACK'i tanımaz (X) |
| 3 | Host 1 → Host 2 | DATA (seq = x, ACK = z), eski kopya | Host 2 ACK = z'yi kendi y değeriyle eşleştiremez, DATA'yı atar (X) |
| 4 | Host 1 → Host 2 | REJECT (ACK = y) | Bağlantı kurulmaz |

Hoca bu senaryolarda bağlantı isteğini başlatmamış olan tarafın, kendisine gelen ACK'i sorgulamadan bile reddettiğine dikkat çekti: Host 1 beklemediği bir onay aldığında bağlantıyı kabul etmez. Senaryo (b)'de eski DATA paketi de onay alanındaki değer (z) güncel sıra numarasıyla (y) uyuşmadığı için reddedilir. <!-- BELİRSİZ: bu bölümde altyazı büyük ölçüde kesik; senaryo açıklamaları slayttan kuruldu. -->

Bağlantının bırakılması (connection release) bir sonraki derse bırakıldı.

> **Ek bilgi (derste anlatılmadı):** TCP'de üç yönlü el sıkışma SYN, SYN+ACK ve ACK segmentleriyle yapılır. Her iki taraf da başlangıç sıra numarasını (ISN) rastgeleye yakın seçer; bu, eski bağlantılardan kalan segmentlerin yeni bağlantıyla karışmasını zorlaştırır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:40): Ağ, 3. katman cihazlardan oluşurken son kullanıcılar tarafında neden ayrıca bir taşıma katmanı kullanılır?

> **Cevap (derste verildi):** Taşıma katmanı bir soyutlama katmanı sağlar ve yapıyı tek tipleştirir, güvenilirlik getirir ve farklı ağlar üzerinde rahat çalışmayı sağlar. O olmasaydı her uygulamanın her ağ türü için ayrı uyarlanması gerekirdi; taşıma katmanıyla uygulamalar alttaki ağın değişmesinden etkilenmez.

**Soru 2** (derste sözlü, 00:50:35): Sunucu bir soket üzerinden dinlerken bir bağlantı isteği geldiğinde ne yapması gerekir, Berkeley soketlerinde bu nasıl sağlanır?

> **Cevap (derste verildi):** Gelen isteğe cevap verirken aynı adrese gelecek diğer istekleri de dinlemeye devam etmesi gerekir. Bunun için bağlantı arka tarafta başka bir yere aktarılır: ACCEPT yeni bir tanımlayıcı döndürür, istemciyle iletişim bu tanımlayıcı üzerinden sürer, dinleyen soket yeni istekleri beklemeye devam eder.

**Soru 3** (derste sözlü, 01:07:45): Soketi (dosya tanımlayıcısını) kapatmazsanız ne olur?

> **Cevap (derste verildi):** Sokete atanmış port hâlâ kullanımda görünür; sunucu yeniden açılmak istendiğinde "port already in use" hatası alınır ve zaman aşımına kadar beklenebilir. Ayrıca sürecin açabileceği tanımlayıcı sayısının üst sınırından yer harcanır.

**Soru 4** (derste sözlü, 01:16:48): Gecikmiş bir paket için gecikmenin üst sınırını biliyor muyuz; ne kadar beklenmeli?

> **Cevap (derste verildi):** Bilinmez; bir saniye daha beklense paketin gelip gelmeyeceği bilinemez. Belli bir süreden sonra gelmeyen paket gelmemiş (kayıp) kabul edilir. Gecikmiş ya da kopya bir paketin yeni gibi işlenmemesi için sıra numaraları 2·MSL içinde yeniden kullanılmaz ve üç yönlü el sıkışma yapılır.

**Soru 5** (derste sözlü, 01:25:35): Sıra numaraları neden önemlidir?

> **Cevap (derste verildi):** Alıcının (Host 2) kendisine gelen paketleri doğru sıraya sokabilmesi için. Büyük bir veri bayt bazında parçalara bölünerek gönderildiğinden parçaların doğru birleştirilmesi sıra numaralarıyla yapılır; ayrıca kopya ve gecikmiş istekler sıra numaralarıyla ayırt edilir.

## Dersin Toparlaması

Bu derste taşıma katmanına giriş yapıldı. Taşıma katmanı, bağlantısız ve güvenilmez IP'nin üzerine uç sistemlerde çalışan bir soyutlama katmanı ekler: uygulamalara bağlantısız (UDP) ya da bağlantı yönelimli (TCP) hizmet verir, aynı makinedeki uygulamaları portlarla ayırt eder (çoğullama) ve alttaki ağ değişse de uygulamaları etkilenmekten korur. Taşıma katmanının veri birimi segmenttir (eski adıyla TPDU); segment paketin, paket de çerçevenin içinde taşınır.

Önce ideal bir bağlantı yönelimli hizmetin primitifleri (LISTEN, CONNECT, SEND, RECEIVE, DISCONNECT) ve durum diyagramı incelendi, sonra bunların gerçek hayattaki karşılığı olan Berkeley soketleri (SOCKET, BIND, LISTEN, ACCEPT, CONNECT, SEND, RECEIVE, CLOSE) ve İnternet dosya sunucusu örneğinin istemci ve sunucu kodu ele alındı. Son kısımda taşıma protokollerinin öğelerine geçildi; adreslemede TSAP/port kavramı ve bağlantı kurulumunda gecikmiş ve kopya paketlerin yarattığı sorun ile buna karşı kullanılan sıra numaraları ve üç yönlü el sıkışma anlatıldı. Bağlantının bırakılması (connection release) bir sonraki derse bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
