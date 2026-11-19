# Ders 3 Çalışma Özeti

## Genel Konular

- Uygulama katmanına giriş
  - İnternet "ağların ağı"dır ve katmanlı bir mimariye dayanır. Beş katman alttan üste: fiziksel, veri bağı, ağ, taşıma ve uygulama katmanı. Uygulama katmanı kullanıcının gördüğü en üst katmandır ve hizmetini bir alttaki taşıma katmanından alır.
  - Bölümün konu sırası: ağ uygulamalarının ilkeleri, Web ve HTTP, e-posta (SMTP, IMAP), DNS, eşler arası (P2P) uygulamalar, video akışı ve içerik dağıtım ağları (CDN).
  - Yaygın ağ uygulamaları: sosyal ağlar, Web, metin mesajlaşma, e-posta, çok kullanıcılı ağ oyunları, depolanmış video akışı (YouTube, Hulu, Netflix), P2P dosya paylaşımı, IP üzerinden ses (Skype), gerçek zamanlı video konferans (Zoom), İnternet araması, uzaktan oturum açma (ekrandan, 00:15:00).
- Ağ uygulaması geliştirme
  - Uygulamalar farklı uç sistemlerde çalışan ve ağ üzerinden haberleşen programlardır (ör. Web sunucusu yazılımı ile tarayıcı yazılımı).
  - Ağ çekirdeğindeki cihazlar (yönlendiriciler) kullanıcı uygulaması çalıştırmaz; bu yüzden çekirdek için yazılım yazmak gerekmez. Uygulamaların uç sistemlerde olması hızlı geliştirme ve yayılmayı sağlar (ekrandan, 00:20:00).
- Uygulama mimarileri (paradigmalar)
  - İstemci-sunucu: sunucu sürekli açıktır, kalıcı IP adresine sahiptir, ölçekleme için çoğunlukla veri merkezlerinde bulunur. İstemciler aralıklı bağlanabilir, dinamik IP kullanabilir ve birbirleriyle doğrudan haberleşmez. Örnekler: HTTP, IMAP, FTP.
  - Eşler arası (P2P): sürekli açık bir sunucu yoktur; uç sistemler doğrudan haberleşir. Her eş hem hizmet ister hem hizmet verir. Kendiliğinden ölçeklenir: yeni eşler hem yeni hizmet kapasitesi hem yeni talep getirir. Eşler aralıklı bağlanır ve IP adresleri değişebilir, bu yüzden yönetimi karmaşıktır. Örnek: P2P dosya paylaşımı.
- Süreçler ve soketler
  - Süreç (process), bir host üzerinde çalışan programdır. Aynı hosttaki süreçler işletim sisteminin tanımladığı süreçler arası iletişimle (IPC), farklı hostlardaki süreçler mesaj alışverişiyle haberleşir (ekrandan, 00:25:00).
  - İstemci süreci iletişimi başlatan, sunucu süreci bağlantı bekleyen süreçtir. P2P uygulamalarda bir süreç hem istemci hem sunucu sürecidir.
  - Soket, süreç ile taşıma katmanı arasındaki "kapı"dır. Gönderen süreç mesajı kapıdan dışarı iter; karşı taraftaki sokete ulaştırma işini taşıma altyapısına bırakır. Bir iletişimde iki soket yer alır.
- Süreçlerin adreslenmesi
  - Mesaj alabilmek için sürecin bir tanımlayıcısı olmalıdır. Host, benzersiz 32 bitlik (IPv4) IP adresine sahiptir; IPv6'da adres 128 bittir (ekrandan, 00:30:00).
  - Hostun IP adresi süreci tanımlamaya yetmez, çünkü aynı hostta birçok süreç çalışabilir. Tanımlayıcı IP adresi ile port numarasından oluşur.
  - Örnek port numaraları: HTTP sunucusu 80, e-posta (SMTP) sunucusu 25.
- Uygulama katmanı protokolünün tanımladıkları
  - Mesaj türleri (istek ve yanıt), mesaj sözdizimi (hangi alanlar var, nasıl ayrılır), anlambilim (alanlardaki bilginin anlamı) ve sürecin ne zaman, nasıl mesaj gönderip yanıt vereceğine dair kurallar.
  - Açık protokoller RFC'lerde tanımlanır, herkes erişebilir ve birlikte çalışabilirlik sağlar (HTTP, SMTP, DNS). Tescilli (proprietary) protokollere örnek Zoom ve Skype'ın protokolleridir.
- Uygulamanın taşıma katmanından beklentileri
  - Veri bütünlüğü: dosya aktarımı ve Web işlemleri %100 güvenilir aktarım ister; ses gibi uygulamalar bir miktar kayba dayanabilir (ekrandan, 00:35:00).
  - Zamanlama: İnternet telefonu ve etkileşimli oyunlar düşük gecikme ister.
  - Verim (throughput): multimedya belirli bir en düşük verimle çalışır; e-posta ve dosya aktarımı gibi "esnek" (elastic) uygulamalar eline geçen verimi kullanır.
  - Güvenlik: gizli veri taşıyan uygulamalar için gereklidir (ayrıntısı bu dersin konusu değildir).
- TCP ve UDP hizmetleri
  - TCP: güvenilir aktarım, akış kontrolü (gönderen alıcıyı boğmaz), tıkanıklık kontrolü (ağ yüklüyken gönderen yavaşlatılır), bağlantı yönelimli (önce bağlantı kurulur, veri aktarılır, bağlantı kapatılır). Zamanlama, en düşük verim garantisi ve güvenlik sağlamaz.
  - UDP: güvenilmez aktarım; güvenilirlik, akış ve tıkanıklık kontrolü, zamanlama, verim garantisi, güvenlik ya da bağlantı kurulumu sağlamaz ("en iyi çaba" hizmeti).
  - Uygulama-protokol eşlemesi (altyazıdan): dosya aktarımı FTP (RFC 959, TCP), e-posta SMTP (RFC 5321, TCP), Web HTTP 1.1 (TCP), İnternet telefonu SIP, RTP veya tescilli protokoller (TCP veya UDP), ses/video akışı HTTP (TCP), etkileşimli oyunlar WoW, FPS gibi tescilli protokoller (UDP veya TCP).
- TCP'nin güvenli hale getirilmesi: TLS
  - Saf TCP ve UDP soketlerinde şifreleme yoktur; sokete verilen açık metin parolalar İnternet'te açık metin olarak dolaşır (ekrandan, 00:45:00).
  - TLS (Transport Layer Security) şifreli TCP bağlantıları, veri bütünlüğü ve uç nokta kimlik doğrulaması sağlar. Uygulama katmanında gerçeklenir: uygulamalar TLS kütüphanelerini kullanır, bunlar da TCP'yi kullanır. TLS soket API'sinde sokete verilen açık metin İnternet'te şifreli dolaşır.
- Web ve HTTP
  - Web sayfası nesnelerden oluşur (HTML dosyası, JPEG görüntü, Java applet, ses dosyası...). Nesneler farklı Web sunucularında olabilir. Sayfa, birçok nesneye referans veren bir temel HTML dosyasından oluşur ve her nesne bir URL ile adreslenir. URL, host adı ile yol (path) adından oluşur (ekrandan, 01:15:00).
  - HTTP (HyperText Transfer Protocol) Web'in uygulama katmanı protokolüdür ve istemci-sunucu modelini kullanır: istemci (Firefox, Chrome, Safari) nesneleri ister ve gösterir, sunucu (ör. Apache) nesneleri gönderir.
  - HTTP TCP kullanır: istemci sunucunun 80 numaralı portuna TCP bağlantısı açar, sunucu kabul eder, HTTP mesajları alınıp verilir, TCP bağlantısı kapatılır (ekrandan, 01:20:00).
  - HTTP durumsuzdur (stateless): sunucu geçmiş istemci istekleri hakkında bilgi tutmaz. Durum tutan protokoller karmaşıktır; geçmiş saklanmalı, çökme durumunda iki tarafın durum görüşü tutarsızlaşabilir ve uzlaştırılmalıdır.
- Kalıcı olmayan ve kalıcı HTTP
  - Kalıcı olmayan HTTP: her nesne için ayrı TCP bağlantısı açılır, tek nesne gönderilir, bağlantı kapatılır. 10 JPEG içeren bir sayfada adımlar her nesne için tekrarlanır.
  - RTT (round trip time): küçük bir paketin istemciden sunucuya gidip geri dönme süresi. Kalıcı olmayan HTTP'de bir nesne için yanıt süresi 2 RTT + dosya aktarım süresidir (bir RTT bağlantı kurmak, bir RTT istek ve yanıtın ilk baytları için).
  - Kalıcı olmayan HTTP'nin sorunları: nesne başına 2 RTT, her TCP bağlantısı için işletim sistemi yükü; tarayıcılar bu yüzden çoğunlukla paralel TCP bağlantıları açar (ekrandan, 01:25:00).
  - Kalıcı HTTP (HTTP 1.1): sunucu yanıttan sonra bağlantıyı açık bırakır; sonraki istekler aynı bağlantı üzerinden gider.
- HTTP mesajları
  - İstek mesajı ASCII, insan tarafından okunabilir metindir. İlk satır istek satırıdır (yöntem, URL, sürüm); ardından başlık satırları (Host, User-Agent, Accept, Accept-Language, Accept-Encoding, Connection) gelir. `Connection: keep-alive`, bağlantının açık tutulmasını ister. <!-- BELİRSİZ: istek mesajı slaytının satırları karelerde yok; başlık listesi altyazıdan kuruldu. -->
  - Yöntemler: GET (nesne isteme), POST (form girdisi istek gövdesinde gönderilir), HEAD (yalnız GET'in döndüreceği başlıklar), PUT (yeni dosyayı sunucuya yükler, aynı URL'deki dosyanın yerine koyar).
  - Yanıt mesajı: durum satırı (protokol, durum kodu, durum ifadesi), başlık satırları ve veri (ör. istenen HTML dosyası) (ekrandan, 01:30:00).
  - Durum kodları ilk satırda yer alır: 200 OK, 301 Moved Permanently, 400 Bad Request, 404 Not Found, 505 HTTP Version Not Supported.
- Çerezler (cookies)
  - HTTP durumsuz olduğu için durum tutmak çerezlerle yapılır. Dört bileşen: HTTP yanıtındaki `Set-Cookie` başlık satırı, sonraki istekteki çerez başlık satırı, kullanıcının hostunda tarayıcının tuttuğu çerez dosyası ve Web sitesindeki arka uç veritabanı.
  - Örnek: daha önce eBay'den çerez almış (ebay 8734, ekrandan, 01:35:00) bir istemci Amazon'u ilk kez ziyaret eder; sunucu bir kimlik (1678) üretir, veritabanına kayıt açar ve `Set-Cookie` ile döner. Sonraki isteklerde (bir hafta sonra dahil) istemci bu kimliği gönderir, sunucu kullanıcıya özgü işlemi yapar.
  - Kullanım alanları: yetkilendirme, alışveriş sepeti, öneriler, kullanıcı oturum durumu (Web e-postası).
  - Gizlilik: çerezler sitelerin kullanıcı hakkında bilgi edinmesine izin verir; üçüncü taraf kalıcı çerezler (izleme çerezleri) birden çok sitede kullanıcının izlenmesine olanak tanır.
- Web önbellekleri (proxy sunucular)
  - Amaç: istemci isteğini kaynak sunucuya gitmeden karşılamak. Kullanıcı tarayıcısını bir Web önbelleğini gösterecek şekilde ayarlar; tarayıcı tüm HTTP isteklerini önbelleğe gönderir. Nesne önbellekte varsa önbellek döndürür; yoksa kaynak sunucudan ister, saklar ve istemciye döner (ekrandan, 01:40:00).
  - Önbellek hem istemci (kaynak sunucuya karşı) hem sunucu (istemciye karşı) gibi davranır.
- Önbellek örneği (ekrandan, 01:45:00): erişim bağlantısı 1,54 Mbps, kurum yönlendiricisinden sunucuya RTT 2 s, nesne 100K bit, ortalama istek hızı 15/s, tarayıcılara ortalama veri hızı 1,50 Mbps, kurum LAN'ı 1 Gbps.
  - LAN kullanımı $1{,}5/1000 = 0{,}0015$; erişim bağlantısı kullanımı $1{,}50/1{,}54 \approx 0{,}97$. Uçtan uca gecikme = İnternet gecikmesi (2 s) + erişim bağlantısı gecikmesi (dakikalar) + LAN gecikmesi.
  - Çözüm 1, daha hızlı erişim bağlantısı (154 Mbps): kullanım $\approx 0{,}0097$, erişim gecikmesi dakikalardan milisaniyelere iner; ama pahalıdır.
  - Çözüm 2, yerel Web önbelleği (ucuz): isabet oranı 0,4 ise isteklerin %60'ı erişim bağlantısını kullanır; hız $0{,}6 \times 1{,}50 = 0{,}9$ Mbps, kullanım $0{,}9/1{,}54 \approx 0{,}58$, ortalama gecikme yaklaşık 1,2 s.
- Koşullu GET
  - Amaç: önbellekteki sürüm güncelse nesneyi göndermemek (aktarım gecikmesi yok, bağlantı kullanımı düşük). Önbellek isteğe `If-Modified-Since: <tarih>` satırı ekler. Nesne değişmediyse sunucu `HTTP/1.0 304 Not Modified` döner ve gövde göndermez; değiştiyse `200 OK` ile nesneyi gönderir, önbellek güncellenir.
- HTTP/2 ve HTTP/3
  - HTTP 1.1 tek TCP bağlantısında ardışık (pipelined) GET'ler getirdi, ancak sunucu ilk gelen ilk hizmet alır (FCFS) sırasıyla yanıt verir. Büyük bir nesne küçüklerin önünde olunca küçükler bekler: hat başı tıkanması (head-of-line, HOL blocking).
  - HTTP/2 (RFC 7540, 2015): yöntemler, durum kodları ve çoğu başlık alanı HTTP 1.1 ile aynıdır; nesnelerin gönderim sırası istemcinin belirttiği önceliğe göre olabilir (FCFS zorunlu değil); istenmemiş nesneler istemciye itilebilir (push); nesneler çerçevelere (frame) bölünür ve çerçeveler sırayla dağıtılarak HOL tıkanması azaltılır (ekrandan, 01:50:00).
  - Örnek: istemci O1 (büyük) ile O2, O3, O4 (küçük) nesnelerini ister. HTTP 1.1'de O2-O4, O1'in bitmesini bekler. HTTP/2'de çerçeveler dönüşümlü gönderilir; O2, O3, O4 erken teslim edilir, O1 yalnız biraz gecikir.
  - HTTP/3: HTTP/2 hâlâ tek TCP bağlantısı kullanır ve güvenlik içermez. HTTP/3, UDP üzerinde nesne başına güvenlik, hata kontrolü ve tıkanıklık kontrolü ekler; ayrıntısı taşıma katmanında işlenecektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- IP adresi tek başına süreci tanımlamaz
  - Aynı hostta birçok süreç birbirleriyle ve dış dünyayla haberleşebildiği için süreç tanımlayıcısı IP adresi ile port numarasının birleşimidir.
- Uygulamaların ihtiyaçları farklıdır
  - Dosya, e-posta ve Web belgesi kayıp kabul etmez ama esnektir; gerçek zamanlı ses/video kayba dayanır ama en düşük verim ve onlarca milisaniyelik gecikme ister. Metin mesajlaşmada zaman duyarlılığı kullanım amacına bağlıdır: mesaj komut olarak kullanılıyorsa zaman duyarlıdır, bilgi vermek için kullanılıyorsa değildir.
- UDP neden hâlâ kullanılır?
  - TCP güvenilir, UDP güvenilmez olduğu halde UDP'nin neden kullanıldığı sorusunu hoca açık bıraktı; tablo, kayba dayanıklı ve zamana duyarlı uygulamaların UDP'yi seçebildiğini gösterir.
- Önbellek, bağlantı hızını artırmaktan ucuzdur
  - Erişim bağlantısını 100 kat hızlandırmak sorunu çözer ama çok pahalıdır; bir önbellek sunucusu almak daha ucuzdur ve gecikmeyi de düşürür. Önbellekte saklanan sayfa sayısı arttıkça isabet oranı artar.
- HOL tıkanması ve HTTP/2
  - Büyük nesnenin çerçevelere bölünmesi O1'i pek değiştirmez ama küçük nesneleri çok daha erken teslim eder.

## Kısa Tekrar Notları

- Uygulama katmanı en üst katmandır, taşıma katmanından hizmet alır.
- İki mimari: istemci-sunucu (sürekli açık sunucu, kalıcı IP) ve P2P (sunucu yok, kendiliğinden ölçeklenir, yönetimi karmaşık).
- Süreç = çalışan program; aynı host içinde IPC, farklı hostlar arasında mesaj.
- Soket = süreç ile taşıma katmanı arasındaki kapı.
- Süreç tanımlayıcı = IP adresi + port. HTTP 80, SMTP 25.
- Protokol: mesaj türü, sözdizimi, anlambilim, kurallar. Açık (RFC) ve tescilli protokoller.
- Taşıma ihtiyaçları: veri bütünlüğü, zamanlama, verim, güvenlik.
- TCP: güvenilir, akış ve tıkanıklık kontrolü, bağlantı yönelimli; zamanlama/verim/güvenlik yok. UDP: hiçbirini sağlamaz.
- TLS: şifreli TCP bağlantısı, veri bütünlüğü, uç nokta doğrulaması; uygulama katmanında gerçeklenir.
- Web sayfası = temel HTML + referans verilen nesneler; URL = host adı + yol adı.
- HTTP: TCP, port 80, durumsuz.
- Kalıcı olmayan HTTP: nesne başına 2 RTT + aktarım süresi. Kalıcı HTTP (1.1): bağlantı açık kalır.
- Yöntemler: GET, POST, HEAD, PUT. Durum kodları: 200, 301, 304, 400, 404, 505.
- Çerez bileşenleri: Set-Cookie yanıt başlığı, istekteki çerez başlığı, istemcideki çerez dosyası, sunucudaki arka uç veritabanı.
- Web önbelleği: isabet varsa önbellekten, yoksa kaynak sunucudan. Örnekte isabet oranı 0,4 ile erişim bağlantısı kullanımı 0,97'den 0,58'e iner.
- Koşullu GET: `If-Modified-Since`, değişmediyse `304 Not Modified`.
- HTTP/2: çerçeveler, öncelik, push, HOL tıkanmasını azaltma. HTTP/3: UDP üzerinde güvenlik ve tıkanıklık kontrolü.

## Detaylı Açıklamalar

- Bu ders, ağ teknolojileri dersinin katmanlar üzerinden ilerleyen ana bölümünün ilk konusu olan uygulama katmanına girer. Uygulama katmanı yazılım geliştiricinin doğrudan çalıştığı katmandır: geliştirici yalnız uç sistemlerde çalışan programları yazar, ağın çekirdeğindeki yönlendiriciler için hiçbir şey yazması gerekmez. Bu ayrım, yeni uygulamaların hızlı geliştirilip yayılmasının nedenidir.

- Uygulamalar iki temel mimariden birine dayanır. İstemci-sunucu mimarisinde sürekli açık ve sabit adresli bir sunucu, aralıklı bağlanan istemcilere hizmet verir; istemciler birbirleriyle konuşmaz. P2P mimarisinde ise her eş hem istemci hem sunucudur. P2P'nin en önemli özelliği kendiliğinden ölçeklenebilirliktir; ancak eşlerin adresleri değişip bağlantıları kopabildiği için yönetim zordur.

- Haberleşen asıl varlıklar programlar değil süreçlerdir. Bir süreç ağa soket aracılığıyla erişir; hocanın benzetmesiyle soket bir kapıdır ve gönderen süreç mesajı bu kapıdan iter, gerisini taşıma katmanına bırakır. Karşı taraftaki süreci bulmak için hem hostun IP adresi hem de o hostta sürecin bağlı olduğu port numarası gerekir. Örneğin derste bir Web sunucusuna HTTP mesajı göndermek için sunucunun IP adresi (128.119.245.12) ve port numarası (80) birlikte verildi. <!-- BELİRSİZ: bu örneğin slaytı karelerde yok; IP adresi altyazıdan alındı, port altyazıda "18" diye geçiyor, HTTP için doğru değer 80'dir (ekrandan, 01:20:00). -->

- Bir uygulamanın taşıma katmanından ne istediği, TCP ile UDP arasındaki seçimi belirler. Ekrandaki tablo (ekrandan, 00:40:00) bu ihtiyaçları özetler:

| Uygulama | Veri kaybı | Verim | Zaman duyarlı mı? |
|---|---|---|---|
| Dosya aktarımı/indirme | Kayıp yok | Esnek | Hayır |
| E-posta | Kayıp yok | Esnek | Hayır |
| Web belgeleri | Kayıp yok | Esnek | Hayır |
| Gerçek zamanlı ses/video | Kayba dayanıklı | Ses: 5 Kbps-1 Mbps; video: 10 Kbps-5 Mbps | Evet, onlarca ms |
| Ses/video akışı | Kayba dayanıklı | Üsttekiyle aynı | Evet, birkaç saniye |
| Etkileşimli oyunlar | Kayba dayanıklı | Kbps+ | Evet, onlarca ms |
| Metin mesajlaşma | Kayıp yok | Esnek | Evet ve hayır |

- TCP güvenilirlik, akış kontrolü ve tıkanıklık kontrolü sağlar; ama hiçbir zamanlama ya da verim garantisi vermez. UDP hiçbir şey sağlamaz; hocanın deyişiyle "gönderir ve ulaşması için dua eder". İki protokolde de şifreleme yoktur. Güvenlik, uygulama ile taşıma katmanı arasına eklenen ince bir katman olan TLS ile sağlanır.

- Web'de bir sayfa, birçok nesneye referans veren bir temel HTML dosyasından oluşur. HTTP istemcisi (tarayıcı) sunucunun 80 numaralı portuna TCP bağlantısı açar ve nesneleri ister. Kalıcı olmayan HTTP'de her nesne için yeni bağlantı açıldığından nesne başına 2 RTT harcanır; 10 resimli bir sayfada bu bedel on kez ödenir. Kalıcı HTTP'de (HTTP 1.1) bağlantı açık kaldığı için bu tekrar ortadan kalkar.

- HTTP yanıt mesajı örneği (ekrandan, 01:30:00):

```text
HTTP/1.1 200 OK\r\n
Date: Sun, 26 Sep 2010 20:09:20 GMT\r\n
Server: Apache/2.0.52 (CentOS)\r\n
Last-Modified: Tue, 30 Oct 2007 17:00:02 GMT\r\n
ETag: "17dc6-a5c-bf716880"\r\n
Accept-Ranges: bytes\r\n
Content-Length: 2652\r\n
Keep-Alive: timeout=10, max=100\r\n
Connection: Keep-Alive\r\n
Content-Type: text/html; charset=ISO-8859-1\r\n
\r\n
data data data data data ...
```

- HTTP durumsuz olduğu halde e-ticaret siteleri kullanıcıyı tanır; bunu çerezler sağlar. Sunucu ilk ziyarette bir kimlik üretir, arka uç veritabanına yazar ve `Set-Cookie` ile istemciye bildirir; istemci sonraki her istekte bu kimliği gönderir. Böylece HTTP mesajları durumu kendileri taşır.

- Web önbelleği örneği, darboğazın kurum ile İnternet arasındaki erişim bağlantısı olduğunu gösterir. Kullanım 0,97'ye yaklaştığı için kuyruk gecikmesi dakikalar düzeyine çıkar. Bağlantıyı 154 Mbps'e yükseltmek bunu çözer ama pahalıdır. Yerel önbellek ise isteklerin %40'ını yerelde karşılayarak kullanımı 0,58'e indirir ve ortalama gecikmeyi yaklaşık 1,2 saniyeye düşürür.

> **Ders sonrası not:** Hoca örnekte ortalama istek hızını "100 kilobit per second" ve tarayıcılara ortalama veri hızını "154 Mbps" diye okudu; slayttaki değerler 15 istek/s ve 1,50 Mbps'tir (ekrandan, 01:45:00). Ayrıca hoca 1 Gbps LAN'daki gecikmeyi "1 mikrosaniye" dedi; 100K bitlik nesnenin 1 Gbps'teki aktarım süresi $10^5/10^9 = 100\ \mu s$'dir. Erişim bağlantısındaki "dakikalar" ise nesnenin aktarım süresinden ($10^5/1{,}54\cdot10^6 \approx 65$ ms) değil, kullanımın 1'e yakın olmasından doğan kuyruk gecikmesinden kaynaklanır.

> **Ders sonrası not:** Hoca TCP ve UDP için "metin tabanlı protokol" dedi; doğrusu, saf TCP ve UDP soketlerinde şifreleme olmaması ve verinin açık metin olarak taşınmasıdır (ekrandan, 00:45:00). Hoca TLS'yi "TCP ya da UDP üzerinde" diye andı; slayttaki TLS şifreli TCP bağlantıları sağlar ve TLS kütüphaneleri TCP'yi kullanır.

> **Ders sonrası not:** Hoca HTTP/2'nin RFC numarasını "7440" diye okudu; slaytta RFC 7540 (2015) yazar (ekrandan, 01:50:00). Altyazıda "545" diye geçen durum kodu büyük olasılıkla 505 HTTP Version Not Supported'dır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
