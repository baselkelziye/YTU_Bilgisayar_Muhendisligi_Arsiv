# Ders 18 Çalışma Özeti

## Genel Konular

- Taşıma katmanına giriş
  - Bölümün başlıkları: Transport Service, Elements of Transport Protocols, Congestion Control, Internet Protocols – UDP, Internet Protocols – TCP, Performance Issues, Delay-Tolerant Networking (ekrandan, 00:05:00).
  - Veri bağı, ağ ve taşıma katmanlarında yapı benzerdir: ya bağlantı yönelimli (connection-oriented) ya da bağlantısız (connectionless) çalışılır.
  - Gerçek hayatta ağ katmanı (IP) bağlantısızdır. Bağlantısız bir ağ üzerinde bağlantı yönelimli bir taşıma hizmeti verilecekse güvenilirliği taşıma katmanı sağlamak zorundadır.
  - Tersi de olabilir: bağlantı yönelimli bir ağ üzerinde bağlantısız bir taşıma hizmeti çalıştırmak. Örnek: WiMAX üzerinde UDP çalıştırmak.
- Üst katmanlara verilen hizmetler (ekrandan, 00:15:00)
  - Slayt: "Transport layer adds reliability to the network layer"; uygulamalara bağlantısız (örn. UDP) ve bağlantı yönelimli (örn. TCP) hizmet sunar.
  - Şekildeki kavramlar: transport entity, transport address, network address, application/transport interface, transport/network interface, TPDU, transport protocol.
  - Taşıma katmanı bir soyutlama katmanıdır: uygulamalar alttaki ağ değişse de etkilenmez. Taşıma katmanı olmasaydı her uygulamanın her ağ türüne ayrıca uyarlanması gerekirdi.
  - Servis sağlayıcılar ek özellikleri (güvenilirlik vb.) ağ katmanında vermek istemez; bu maliyet, yatırım ve sorumluluk getirir. Bu yüzden bu işler uç sistemlerdeki taşıma katmanında yapılır.
- TPDU ve segment
  - TPDU (transport protocol data unit): iki taşıma katmanı arasında taşınan veri birimi. Güncel kaynaklarda daha çok "segment" denir.
  - Veri bağı katmanında çerçeve (frame), ağ katmanında paket (packet), taşıma katmanında segment.
- Transport entity
  - Taşıma katmanı işini yapan yapıya verilen genel ad. İşletim sisteminin (çekirdeğin) parçası, bir kütüphane ya da bir süreç olabilir; ağ arayüz kartının (NIC) içinde bile gerçeklenmiş olabilir.
- Kapsülleme (ekrandan, 00:30:00)
  - Slayt: "Transport layer sends segments in packets (in frames)".
  - Çerçeve başlığı + çerçeve yükü; çerçeve yükünün içinde paket başlığı + paket yükü; paket yükünün içinde segment başlığı + segment yükü.
  - Hocanın benzetmesi: iç içe bebekler (matruşka).
- Çoğullama (multiplexing/demultiplexing)
  - Bir makinede birden fazla uygulama ağı aynı anda kullanır; ağ katmanında olmayan bu ayrımı taşıma katmanı yapar.
  - Benzetme: apartmanın tek bir numarası vardır (IP adresi), içindeki daireler ayrı numaralanır (port).
- Taşıma hizmeti primitifleri (ekrandan, 00:35:00)
  - İstemci: CONNECT, SEND, RECEIVE, DISCONNECT. Sunucu: LISTEN, RECEIVE, SEND, DISCONNECT.

    | Primitive | Segment sent | Meaning |
    |---|---|---|
    | LISTEN | (none) | Block until some process tries to connect |
    | CONNECT | CONNECTION REQ. | Actively attempt to establish a connection |
    | SEND | DATA | Send information |
    | RECEIVE | (none) | Block until a DATA packet arrives |
    | DISCONNECT | DISCONNECTION REQ. | This side wants to release the connection |

  - Bağlantı yönelimli hizmetin üç evresi: bağlantı kurulur, veri alışverişi yapılır, bağlantı sonlandırılır. CONNECT bir "aç parantez", DISCONNECT bir "kapa parantez" gibi düşünülebilir.
- Bağlantı kesmenin iki biçimi
  - Asimetrik: taraflardan birinin DISCONNECT demesi bağlantıyı tümüyle keser.
  - Simetrik: bağlantı iki yönlü iki ayrı bağlantı gibi düşünülür (istemciden sunucuya, sunucudan istemciye). Her taraf kendi gönderme yönünü kapatır; veri göndermeyi bitiren taraf hâlâ dinlemeye devam edebilir. <!-- BELİRSİZ: altyazıda simetrik/asimetrik tanımları karışık geçiyor; yukarıdaki tanım anlatımın bütününden kuruldu. -->
- Basit bağlantı yönelimli hizmetin durum diyagramı (ekrandan, 00:40:00)
  - Durumlar: IDLE, ACTIVE ESTABLISHMENT PENDING, PASSIVE ESTABLISHMENT PENDING, ESTABLISHED, ACTIVE DISCONNECT PENDING, PASSIVE DISCONNECT PENDING.
  - Düz çizgiler (sağ) istemcinin, kesikli çizgiler (sol) sunucunun durum dizisidir; italik geçişler segment gelişiyle olur.
- Sunucu neden bağlantıyı başlatmaz
  - Sunucu istemcileri tek tek bilemez; istemcilerin adresleri değişir, cihazları sürekli açık değildir. İstemci ise sunucunun sabit adına, adresine ve portuna gider.
- Berkeley soketleri (ekrandan, 00:45:00)
  - UNIX'te TCP ile başlayan, çok yaygın primitifler. Soket: taşıma uç noktası. Basit kümeye SOCKET, BIND ve ACCEPT eklenir.

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

  - SOCKET yeni bir uç nokta oluşturur ama ona adres vermez; adresi BIND verir.
  - BIND sunucu tarafında gerekir: sunucunun adresi ve portu sabit olmalıdır. İstemcinin hangi porttan çıktığının önemi yoktur; istemci portu iyi bilinen portların üstünden rastgele atanır.
  - İyi bilinen portlar 0-1023'tür. Bu portlarda dinleyen bir uygulamayı ayağa kaldırmak root yetkisi ister.
  - Berkeley gerçeklemesinde LISTEN bloklamaz; yalnız gelen istekler için bir kuyruk (backlog) kurar. Bloklayan, ACCEPT'tir.
  - ACCEPT yeni bir tanımlayıcı (descriptor) döndürür. Sunucu o bağlantıyı bu yeni tanımlayıcı üzerinden sürdürür, dinleyen soket yeni istekleri beklemeye devam eder.
  - RECEIVE doğası gereği bloklar; ama veri hiç gelmeyebilir. Berkeley soketlerinde SEND ve RECEIVE bloklamayan biçimde de kullanılabilir.
- Soket örneği: İnternet dosya sunucusu
  - İstemci: `socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)` ile İnternet ailesinden, akış (byte stream) tipinde, TCP soketi açılır; port `htons` ile ağ bayt sırasına çevrilir; `connect` ile bağlantı istenir. <!-- BELİRSİZ: istemci kodunun ilk slaytı karelerde yok; bu satırlar anlatımdan kuruldu. -->
  - İstemcinin devamı (ekrandan, 01:00:00): `write` ile dosya adı gönderilir, sonra `read` döngüsüyle gelen veri standart çıktıya (`write(1, ...)`) yazılır; `bytes <= 0` olunca çıkılır.
  - Sunucu (ekrandan, 01:05:00): `memset`, `sin_family = AF_INET`, `sin_addr.s_addr = htonl(INADDR_ANY)`, `sin_port = htons(SERVER_PORT)`, sonra `socket`, `setsockopt(... SO_REUSEADDR ...)`, `bind`, `listen(s, QUEUE_SIZE)`.
  - `INADDR_ANY`: sunucu bütün arayüzlerden ve bütün adreslerden gelen isteklere cevap verir. İstenirse yalnız belli bir arayüz ya da adres dinlenebilir.
  - `htons` (host to network short) 16 bitlik port için, `htonl` (host to network long) 4 baytlık IPv4 adresi için kullanılır.
  - Soket de terminal de bir dosya tanımlayıcısıdır (0, 1, 2, ...); bu yüzden ikisine de `write` ile yazılır.
  - Backlog dolarsa (örn. backlog 5 iken kuyruğa 6. istek gelirse) yeni bağlantı isteği başarısız olur.
  - Soket kapatılmazsa port kullanımda görünür; sunucu yeniden açılınca "port already in use" hatası alınabilir. Ayrıca her sürecin açabileceği dosya tanımlayıcısı sayısının bir üst sınırı vardır.
  - Soketler yalnız TCP/UDP taşımak zorunda değildir: ham (raw) soketle doğrudan IP ya da ICMP paketi oluşturulabilir.
- Taşıma protokollerinin öğeleri (ekrandan, 01:10:00)
  - Addressing, Connection establishment, Connection release, Error control and flow control, Multiplexing, Crash recovery.
  - Adresleme slaytı: taşıma katmanı TSAP'ler ekler; tek bir IP adresli makinede birden çok istemci ve sunucu çalışabilir; TCP/UDP'de TSAP'ler porttur (ekrandan, 01:15:00).
- Bağlantı kurulumu (ekrandan, 01:20:00)
  - Ana sorun: paketler kaybolabilir (lost), bozulabilir (corrupted), gecikebilir (delayed) ve çoğalabilir (duplicated). Eski ya da kopya bir paket yeni gibi işlenmemelidir.
  - Kayıp ve bozulma için ARQ ve sağlama toplamı (checksum) kullanılır. Asıl zor olanlar gecikme ve kopyalardır.
  - Yaklaşım: sıra numaraları, MSL'nin (Maximum Segment Lifetime) iki katı süre (2T = 240 s) içinde yeniden kullanılmaz; bağlantı üç yönlü el sıkışmayla (three-way handshake) kurulur.
- Üç yönlü el sıkışma (ekrandan, 01:25:00)
  - Host 1 → Host 2: CR (seq = x). Host 2 → Host 1: ACK (seq = y, ACK = x). Host 1 → Host 2: DATA (seq = x, ACK = y).
  - İki taraf da kendi taze sıra numarasını katar. TCP'de bağlantı isteği SYN (synchronization) olarak geçer.
  - Kopya CR ve kopya CR + DATA durumlarında el sıkışma sahte bağlantıyı engeller (ekrandan, 01:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- TPDU, transport entity, network address, transport address tanımları önemlidir.
- Taşıma katmanı, alttaki ağdan bağımsız bir soyutlama sağlar; güvenilirlik ağda değil uçlarda sağlanır.
- BIND sunucu tarafında gereklidir; istemcinin portu önemsizdir ve rastgele atanır.
- Berkeley gerçeklemesinde LISTEN bloklamaz, ACCEPT bloklar ve yeni bir tanımlayıcı döndürür.
- `read`'in dönüş değeri mutlaka kontrol edilmelidir: istenen kadar veri gelmeyebilir.
- Soketler kapatılmalıdır; aksi hâlde port meşgul kalır ve tanımlayıcı sınırı tüketilir.
- Bağlantı kurulumunda asıl sorun gecikmiş ve kopya paketlerdir; çözüm sıra numaraları ve üç yönlü el sıkışmadır.

## Kısa Tekrar Notları

- IP bağlantısızdır; TCP bağlantı yönelimli, UDP bağlantısız taşıma hizmeti verir.
- Birimler: frame (veri bağı), packet (ağ), segment/TPDU (taşıma).
- IP adresi = apartman numarası, port = daire numarası.
- Basit primitifler: LISTEN, CONNECT, SEND, RECEIVE, DISCONNECT.
- Berkeley: SOCKET, BIND, LISTEN, ACCEPT, CONNECT, SEND, RECEIVE, CLOSE.
- İyi bilinen portlar 0-1023; root yetkisi ister.
- `htons` port (16 bit), `htonl` IPv4 adresi (32 bit); `INADDR_ANY` bütün arayüzler.
- LISTEN backlog'u kuyruk boyunu verir; kuyruk doluysa yeni istek başarısız olur.
- Bağlantı kurulumu: CR(seq=x) → ACK(seq=y, ACK=x) → DATA(seq=x, ACK=y).
- Sıra numaraları 2·MSL (240 s) içinde yeniden kullanılmaz.

## Detaylı Açıklamalar

- Taşıma katmanının yeri
  - Ağ katmanı, 3. katman cihazlardan oluşan bir ISP ağında paketleri taşır. Taşıma katmanı ise yalnız uç sistemlerde çalışır. Böylece uygulamalara tek tip bir arayüz sunar, güvenilirlik ekler ve farklı ağlar üzerinde rahatça çalışmayı sağlar.
  - Ağ ile taşıma katmanının ikisi de bağlantısız ya da ikisi de bağlantı yönelimli olduğunda yapı temizdir. Farklı olduklarında taşıma katmanı aradaki farkı kapatmak zorundadır: bağlantısız IP üzerinde bağlantı yönelimli TCP, güvenilirliği kendisi sağlar.
  - Kitap taşıma katmanını iki kez anlatır gibidir: önce ideal bir taşıma katmanında hangi hizmetlerin ve primitiflerin olması gerektiği, sonra IP üzerindeki gerçek taşıma katmanı (TCP) üzerinden. Bu yüzden ilk bölümde ayrıntıya fazla girilmedi.
- Primitifler ve durum diyagramı
  - Primitifler, protokolün bir durumdan diğerine geçmesini tetikleyen işlemlerdir. İstemci bağlantıyı aktif olarak başlatır (CONNECT); sunucu pasif olarak bekler (LISTEN).
  - LISTEN ve RECEIVE herhangi bir segment göndermez; yalnız bir segmentin gelmesini bekler.
  - Durum diyagramında istemci IDLE → ACTIVE ESTABLISHMENT PENDING → ESTABLISHED yolunu, sunucu IDLE → PASSIVE ESTABLISHMENT PENDING → ESTABLISHED yolunu izler. Kesmede DISCONNECT'i çağıran taraf ACTIVE DISCONNECT PENDING'e, karşı taraf PASSIVE DISCONNECT PENDING'e geçer ve sonunda ikisi de IDLE'a döner.
  - Bir makine bir bağlantıda istemci, başka bir bağlantıda sunucu olabilir; bu roller birbirini dışlamaz.
- Soketlerle sunucu yazmak
  - Sunucu önce `socket` ile uç noktayı oluşturur, `bind` ile ona yerel adres ve port bağlar, `listen` ile kuyruğu kurar ve döngüde `accept` ile gelen her bağlantıyı yeni bir tanımlayıcıya alır. Her bağlantı için bilgi alıp verdikten sonra o tanımlayıcı kapatılır.
  - Tek süreçli bir sunucu bile kuyruk boyu kadar istemciyi bekletebilir; ilk bağlananın işini yaparken diğerleri kuyrukta bekler.
  - İstemci tarafında `read` döngüsü, okunan bayt sayısını kontrol eder: 0 ya da negatif değer verinin bittiğini ya da bir hata olduğunu gösterir.
- Bağlantı kurulumunda gecikme ve kopya sorunu
  - Kayıp bir paketin yalnız gelmediği anlaşılır, yanlış karar verdirmez. Bozuk paket fark edilip işlenmez. Gecikmede ise gecikmenin üst sınırı bilinmez: bir saniye daha beklense paket gelecek miydi? Belli bir süreden sonra paket gelmemiş sayılır.
  - Kopyada alıcı, paketi daha önce işleyip işlemediğini bilmek için durum tutmalıdır; aksi hâlde aynı durum geçişi ikinci kez yapılır. Doğru davranış, daha önce işlenmiş ya da süresi geçmiş bir paketi yeni paket gibi işlememektir.
  - Üç yönlü el sıkışmada iki taraf da kendi sıra numarasını gönderir ve karşı tarafınkini onaylar. Böylece hem kopya hem gecikmiş bağlantı isteklerine karşı korunulur. Sıra numaraları, alıcının paketleri doğru sıraya koyabilmesi için de gereklidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
