# Ders 9 Çalışma Özeti

## Genel Konular

- Web güvenliğinden ağ güvenliğine geçiş
  - Önceki iki haftada web güvenliğinin prensipleri ve saldırıları incelenmişti. Web, uygulama katmanı ile altındaki taşıma ve ağ katmanlarından soyutlanamaz; bu yüzden araya ağ (network) konusu alınır.
  - Önce TCP/IP'nin temel yapısı gözden geçirilir, sonraki derste bu yapılara yönelik saldırılar ve tedbirler ayrıntılı incelenir.
  - Günümüzde sistemler arası haberleşmenin büyük çoğunluğu (hocaya göre %90-95'ten fazlası) TCP/IP üzerinden yürür; odak TCP/IP'dir.
- internet ve Internet
  - Küçük harfle "internet" (internetworking): aynı ya da farklı protokol kullanan ağların birbirine bağlanıp birlikte çalışmasıdır.
  - Büyük harfle "Internet": TCP/IP protokol yapısını kullanan küresel ağdır.
  - Internet, bağlı hostlar arasında paketlerin "best-effort" iletimini sağlayan küresel bir ağdır (ekrandan, 00:10:00).
- Paket ve IP'nin best-effort iletimi
  - Bilgi tek parça gönderilmez, paketlere bölünür. Paketler farklı yollardan gidebilir, kaybolabilir, çoğalabilir, sırası bozulabilir.
  - Paket, yapılandırılmış bir bayt dizisidir: header (ağın kullandığı metadata) ve payload (taşınacak kullanıcı verisi) (ekrandan, 00:10:00).
  - Her hostun tekil bir IP adresi vardır. Slayttaki örnekte 141.212.120.7 adresli host, 8.8.8.8 adresli Google DNS sunucusuna erişir (ekrandan, 00:10:00).
  - Router'lar paketin header'ındaki hedef adrese bakıp paketi hedefe doğru bir hop ilerletir (packet switching).
- Ağ protokolü: sözdizimi ve anlam
  - Syntax: haberleşmenin yapısı, mesajların biçimi ve sırası. Semantics: mesajın anlamı; gönderme, alma ya da zamanlayıcı dolunca yapılacak işler (ekrandan, 00:15:00).
  - Alıcı, verici ve aradaki router'lar alanların yerini, uzunluğunu ve değerlerin anlamını aynı biçimde bilmelidir.
  - Slayttaki örnek header: Source Port (16 bit), Destination Port (16 bit), Length (16 bit), Checksum (16 bit), toplam 8 bayt (ekrandan, 00:15:00).
- Protokol katmanları
  - TCP/IP'de beş katman: Physical, Data Link, Network, Transport, Application (ekrandan, 00:20:00). OSI'deki Session ve Presentation katmanlarının görevleri TCP/IP'de Application katmanına gömülüdür.
  - Alt katman üst katmana hizmet verir ve üstün ne yaptığıyla ilgilenmez; üst katman alttakinin nasıl çalıştığıyla ilgilenmez.
  - Katmanlama, güvenlik prensiplerindeki compartmentalization ve separation of duties fikriyle uyuşur.
  - Physical: bitleri elektrik, optik ya da radyo sinyaline çevirir. Data Link: doğrudan bağlı iki nokta arasında (bir hop) iletim. Network: birden çok hop üzerinden kaynaktan hedefe iletim. Transport: iki uç arasında sürekli bir akış görüntüsü. Application: HTTP, FTP, SMTP, SSH, Telnet gibi uygulama protokolleri.
- IP: dar bel (narrow waist) (ekrandan, 00:25:00)
  - Her şeyin ortasında IP vardır. Altında Cellular, WiFi, Ethernet (radyo, bakır, fiber); üstünde UDP ve TCP; en üstte DNS (UDP), SSH, FTP, SMTP, NNTP, HTTP (TCP).
  - Transport katmanı doğru servise ulaşmayı ve güvenilir bir bayt "stream"i sağlar.
- Veri birimleri ve kapsülleme
  - Application: message; Transport: segment; Network: paket; Data Link/Physical: frame.
  - Mesaj birden çok segmente, segment birden çok pakete bölünebilir. Paket ile frame boyunun eşit tutulmasına özen gösterilir.
  - Kapsülleme: N1 protokolünün P1 paketi, alt katmandaki N2'nin P2 paketinin payload'u olur. Örnek: IP Header + [TCP Header + HTTP Request] (ekrandan, 00:30:00).
  - Aşağı inerken her katman önüne header ekler, yukarı çıkarken birer header çıkarılır (Rus matruşka bebekleri benzetmesi).
- Ethernet
  - 48 bitlik (6 bayt) MAC adresleri kullanır. Frame: hedef MAC, kaynak MAC, EtherType, payload (46-1500 bayt), 4 baytlık CRC.
  - EtherType: 0x0800 IPv4, 0x0806 ARP, 0x86DD IPv6.
  - En kısa frame 64, en uzun 1518 bayttır: 14 bayt header + 4 bayt CRC = 18 bayt; 46 + 18 = 64, 1500 + 18 = 1518.
  - İlk Ethernet bir broadcast ortamıydı (kalın koaksiyel kablo): herkes her frame'i alır, MAC adresine bakıp kendine değilse atar. Sorunlar: çarpışma/gürültü ve mahremiyet yokluğu.
  - Switched Ethernet: switch, kaynak MAC adreslerinden hangi MAC'in hangi portta olduğunu öğrenir; M adresi P portundaysa frame'i yalnız P'ye gönderir, bilmiyorsa tüm portlara yayınlar (ekrandan, 00:35:00).
  - `ifconfig` çıktısı örneği: MTU 1500, IPv4/IPv6 adresleri, MAC adresi, transmit kuyruğu 1000 frame, alınan/gönderilen paket ve hata sayıları. Hatalı paket sayısı çok küçüktü; yerel Ethernet oldukça güvenilir çalışır.
- ARP (Address Resolution Protocol) (ekrandan, 00:40:00)
  - IP adresi N'ye karşılık gelen MAC adresi M'yi bulmak için yerel ağa "IP adresi N kimde?" diye broadcast yapılır; N adresli host "IP N, MAC M'dedir" diye cevap verir.
  - ARP paketi 28 bayttır; Ethernet'in en küçük payload şartını sağlamak için sonuna sıfır dolgu (padding) eklenir.
  - Güvenlik sorunu: kötü niyetli bir host, gerçek hosttan önce "bu IP bana ait" diye cevap verebilir. İlk gelen cevap kabul edilir, sonraki atılır. Sonuç tipik bir man-in-the-middle saldırısıdır. ARP'de bu konuda güvenlik yoktur.
- IP adresleri (ekrandan, 00:45:00)
  - IPv4: 32 bit, A.B.C.D (dotted quad / noktalı ondalık), her parça 8 bitlik ondalık sayı. Örnek: 192.168.1.1.
  - IPv6: 128 bit, 16 baytlık adres, 16 bitlik onaltılık gruplar `:` ile ayrılır; `::` ardışık sıfır gruplarını kısaltır ve adreste yalnız bir kez kullanılabilir.
  - Örnek: `2620:0:e00:b::53 = 2620:0:e00:b:0:0:0:53` (3 sıfır grubu kısaltılmış).
- IPv4 header (ekrandan, 00:50:00)
  - Router ve hostlara pakete ne yapılacağını söyler; bütün değerleri gönderen host doldurur.
  - Alanlar: Version (4 bit), IHL (4 bit), Type of Service, Total Length, Identification, IP Flags (x, D, M), Fragment Offset, TTL, Protocol, Header Checksum, Source Address (32 bit), Destination Address (32 bit), IP Option (değişken uzunluklu, isteğe bağlı, nadir).
  - IHL 32 bitlik kelime cinsindendir: 5 → 20 bayt, 8 → 32 bayt; en çok 15 × 4 = 60 bayt. En kısa header 20 bayttır; IPv4'te ilk bayt 0x45 olur.
  - Identification aynı paketin parçalarını eşleştirir, Fragment Offset parçanın yerini gösterir.
  - TTL her hop'ta bir azalır; sıfıra inince paket atılır.
  - Header Checksum yalnız header'ı korur; IP taşıdığı verinin doğruluğuyla ilgilenmez.
- Hedef ve kaynak adres
  - Router'lar yalnız hedef adrese (destination address) bakar; kaynak adresi denetlemez (ekrandan, 00:55:00).
  - Kaynak adresi gönderen yazar; libnet gibi kütüphanelerle istenen kaynak ve hedef adresle IP paketi üretilebilir. Cevap, gerçek gönderene değil kaynak alanına yazılan adrese gider.
  - Ele geçirilmiş bir makinedeki kötü kod, bu özelliği hizmet engelleme saldırısı ya da kimliğini gizleme için kullanabilir.
  - IP yalnız yönlendirme, parçalama/birleştirme ve TTL ile hata bildirimi yapar. Sıralama, yeniden gönderme, header dışında hata denetimi, onay, bağlantı ve güvenlik yoktur.
- BGP olayı: Pakistan YouTube'u ele geçiriyor (ekrandan, 01:00:00)
  - 24 Şubat 2008'de Pakistan Telecom (AS 17557), YouTube'un (AS 36561) ağının bir kısmını BGP ile duyurdu. PCCW (AS 3491) bu duyuruyu (208.65.153.0/24) doğrulamadı ve YouTube dünya çapında erişilemez oldu.
  - Ülke içi engelleme amaçlı bir yapılandırma hatası bütün dünyayı etkiledi; ardından BGP güvenliği üzerine çalışmalar başladı.
- Portlar ve UDP
  - Host üzerindeki her uygulama bir port numarasıyla tanınır. Port 16 bittir, geçerli değerler 1-65535 (ekrandan, 01:15:00).
  - TCP bağlantısı X hostundaki A portu ile Y hostundaki B portu arasında kurulur. Bazı hedef portlar uzlaşmayla belirli uygulamalara ayrılmıştır: 80, 443, 25, 67, 22, 23.
  - UDP her paketi bağımsız ele alır; bilgi tek pakete sığmalıdır. İstek-cevap uygulamaları için hızlıdır ama kayıp tespit edilemez; güvenilirlik gerekiyorsa uygulama katmanında önlem alınmalıdır.
- TCP (ekrandan, 01:20:00)
  - Bağlantı yönelimli (açık kurulum/sonlandırma), güvenilir ve sıralı bayt akışı, tıkanıklık denetimi. IP paketleri kaybolsa, sırası bozulsa, çoğalsa bile çalışır.
  - Çift yönlüdür: iki tek yönlü akıştan oluşur. 32 bitlik sıra (sequence) numarası kullanır.
  - Header 20 bayt: Source/Destination Port, Sequence Number, Acknowledgment Number, Offset (4 bit), bayraklar, Window, Checksum, Urgent Pointer.
  - Alıcı her zaman bir sonra beklediği baytın sıra numarasıyla onay (ACK) verir. Birden çok segment tek ACK ile onaylanabilir. Kayıp segmentte alıcı eksik baytın numarasını bildirmeyi sürdürür (ekrandan, 01:25:00).
  - Üçlü el sıkışma: SYN (client, sıra no) → SYN/ACK (server kendi sıra no'su, ACK = client sıra + 1) → ACK (client, ACK = server sıra + 1). Bağlantıyı her zaman client başlatır.
  - Sonlandırma dört mesajla: FIN → ACK, FIN → ACK; her yön ayrı kapanır. Ağda gecikmiş paketler için bir zamanlayıcı beklenir.
  - Reset: oturumun durumuna göre geçersiz paket gelirse bağlantı yıkılır ve RST bayraklı paket gönderilir; RST bayraklı paket alan host bağlantıyı kapatır (ekrandan, 01:30:00).
- TCP'ye iki saldırı fikri
  - Sahte bağlantı (TCP spoofing): kaynak adres sahte yazılarak SYN gönderilebilir, ama server'ın SYN/ACK'i gerçek client'a gider. Üçüncü mesaj için server'ın sıra numarası tahmin edilmelidir. Sıra numarası düzgün rastgeleyse olasılık $1/2^{32}$'dir; öngörülebilirse saldırı mümkün olur.
  - TCP reset saldırısı: RST bayrağı, port numaraları (bilinen servislerde zaten bilinir) ve pencere içine düşen bir sıra numarası gerekir. Pencere yaklaşık 32K-64K olduğundan arama $2^{32}$ yerine yaklaşık $2^{32}/2^{16} = 2^{16}$ adıma iner.
- DNS (Domain Name Service) (ekrandan, 01:35:00)
  - İnsanlar ve uygulamalar hostlara adla (ör. google.com) başvurur. DNS yetkisi devredilebilen (delegatable) hiyerarşik bir isim uzayıdır: root → edu → stanford → cs → www.
  - Her DNS sunucusu yetkili olduğu bölge için kayıtlara sahiptir. `dig` / `nslookup` ile sorgu yapılır.
  - 13 kök isim sunucusu vardır (A'dan M'ye), çoğu ABD'dedir.
  - Bütün cevaplar, olumsuz cevaplar dahil, önbelleğe alınır; her kaydın bir TTL'i vardır. Örnek: olumsuz cevap TTL'i 86400 s ise bir gün boyunca aynı olumsuz cevap döner.
  - DNS sorguları UDP üzerinden gider. TCP ile yapılsa 3 (kurulum) + 2 (soru-cevap) + 4 (kapanış) = 9 mesaj gerekirdi; verim yaklaşık 2/9'a düşer.
  - DNS paketi: dört bölüm (questions, answers, authority, additional records); 12 baytlık header; Query ID 16 bitlik rastgele değerdir ve cevabı sorguya bağlar (ekrandan, 01:40:00).
  - Header bayrakları arasında QR, Opcode, AA, TC, RD, RA, RCode vardır. AA = 1 ise cevap yetkili (authoritative) sunucudandır; değilse önbellekten öğrenilmiş bilgidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Router kaynak adresi denetlemez
  - Paketin iletiminde istisnasız yalnız hedef adres kullanılır. Kaynak adrese istenen değer yazılabilir ve bunu kimse sorgulamaz. Hoca bunu "çok önemli nokta" diye vurguladı; IP'nin temelinde ciddi bir güvenlik zafiyeti vardır.
- ARP'de doğrulama yok
  - İlk gelen ARP cevabı kabul edildiği için ağın ortasına yerleşmiş kötü niyetli bir host araya girebilir. Bu, ARP'nin en sorunlu noktasıdır.
- TCP/IP en yaygın ama zaafları en yüksek protokol yapısı
  - Network, transport ve application katmanlarının hepsinde ciddi zaaflar vardır.
- Alıcı her zaman bir sonra beklediği baytı onaylar
  - TCP ACK hesabında "bunu hiçbir zaman unutmuyoruz" vurgusu yapıldı.
- Sıra numarasının rastgeleliği
  - Sıra numarası düzgün dağılımlı değilse sahte TCP bağlantısı kurulabilir; pencere boyutu reset saldırısının arama uzayını küçültür.
- Katmanlama ve güvenlik prensipleri
  - Katman yapısı, daha önce görülen compartmentalization ve separation of duties ilkeleriyle uyumludur.

## Kısa Tekrar Notları

- Internet = TCP/IP ile best-effort paket iletimi. Paket = header + payload.
- Beş katman: Physical, Data Link, Network, Transport, Application. Birimler: frame, paket, segment, message.
- IP dar beldir: altında Cellular/WiFi/Ethernet, üstünde UDP/TCP.
- Ethernet: 48 bit MAC, EtherType 0x0800 IPv4, 0x0806 ARP, 0x86DD IPv6, frame 64-1518 bayt, payload 46-1500 bayt.
- Switch, kaynak MAC'lerden port eşlemesini öğrenir; bilmediği MAC için tüm portlara yayınlar.
- ARP: "N kimde?" broadcast'i, ilk cevap kabul edilir → ARP ile man-in-the-middle.
- IPv4 32 bit, IPv6 128 bit; `::` yalnız bir kez.
- IPv4 header en az 20, en çok 60 bayt; IHL × 4; ilk bayt 0x45.
- TTL her hop'ta bir azalır, sıfırda paket atılır.
- Router yalnız hedef adrese bakar; kaynak adres sahte yazılabilir (spoofing).
- Pakistan Telecom 2008: doğrulanmayan BGP duyurusu YouTube'u dünyaca erişilemez yaptı.
- Port 16 bit (1-65535). UDP bağımsız paket, TCP bağlantılı ve sıralı akış.
- ACK = bir sonra beklenen bayt. Üçlü el sıkışma SYN, SYN/ACK, ACK; kapanış FIN/ACK iki yönde.
- Sıra no tahmini $1/2^{32}$; reset saldırısında pencere sayesinde yaklaşık $2^{16}$ deneme.
- DNS hiyerarşik ve devredilebilir; 13 kök sunucu; önbellek ve TTL; UDP üzerinde; 16 bit Query ID; AA biti yetkili cevap.

## Detaylı Açıklamalar

- Ders, ağ güvenliği konusuna giriş niteliğindedir. Hoca, web güvenliğinin altında yatan ağ teknolojisini anlamadan saldırıların kavranamayacağını belirterek TCP/IP protokol yığınını alttan üste doğru anlattı ve her katmanda güvenlik açısından nelere dikkat edilmesi gerektiğine işaret etti. Saldırıların ayrıntısı sonraki derse bırakıldı.
- Bir ağ protokolü, iki tarafın anlaşmasıdır. Sözdizimi (syntax), header içindeki alanların nerede başlayıp bittiğini ve uzunluğunu; anlam (semantics) ise bu alanlardaki değerlerin ne ifade ettiğini belirler. Hoca bunu günlük dilde cümlenin öznesi, yüklemi ve sıfatın yerinin belli olmasına benzetti. Örneğin bir bitlik bir alanın 0 ya da 1 olması ayrı anlamlar taşır; bunu hem alıcı hem verici hem de aradaki router'lar aynı biçimde bilmelidir.
- Katmanlı yapıda görevler gruplanır ve bu gruplar arasında görünmez sınırlar oluşur. Bir katmanın verdiği ve aldığı hizmetler net olarak tanımlanır. Bu yapı, güvenlik derslerinde görülen bölümlere ayırma (compartmentalization) ilkesinin ağdaki karşılığıdır. TCP/IP'de beş katman bulunur; OSI'nin yedi katmanlı modelini uygulayan protokoller bugün pratikte yaygın değildir.
- Kapsüllemede üst katmanın paketi, alt katmanın paketinin payload'u olur. Örneğin bir HTTP isteği TCP header'ı ile bir TCP segmenti olur; bu segment IP header'ı eklenerek bir IP paketinin payload'una yerleşir. Karşı tarafta ağ katmanı IP header'ına bakarak payload'u TCP'ye mi UDP'ye mi vereceğine karar verir. Hoca bunu iç içe geçen matruşka bebeklerine benzetti.
- Ethernet'te frame yapısı sabittir: 6 bayt hedef MAC, 6 bayt kaynak MAC, 2 bayt EtherType (toplam 14 bayt header), 46-1500 bayt payload ve 4 bayt CRC. Bu yüzden en kısa frame $46 + 18 = 64$, en uzun frame $1500 + 18 = 1518$ bayttır. 64 bayttan kısa frame hatalı sayılır. CRC, bit hatalarını tespit edip hatalı frame'lerin kabul edilmemesini sağlar.
- İlk Ethernet'te bütün hostlar aynı kalın koaksiyel kabloya bağlıydı ve gönderilen her frame'i herkes alıyordu. Bu hem aynı anda konuşanlar yüzünden gürültüye (herkesin aynı anda konuştuğu bir ortam benzetmesi) hem de mahremiyetin olmamasına yol açıyordu. Switched Ethernet'te her host switch'in ayrı bir portuna bağlanır; switch MAC adreslerini öğrenir ve frame'i yalnız ilgili porta gönderir.
- ARP, katman 3'teki IP adresiyle katman 2'deki MAC adresi arasındaki boşluğu doldurur. Yerel ağda broadcast ile sorulan soruya tasarım gereği yalnız o IP'nin sahibi cevap vermelidir. Ancak büyük bir ağda broadcast'in her hosta ulaşma süresi farklıdır. Ağın ortasına yakın yerleşmiş kötü niyetli bir host gerçek sahibinden önce cevap verirse, soran taraf ilk cevabı kabul edip ikinciyi atar. Kötü niyetli host gerçek cevabı da gördüğü için A ile B arasındaki trafiği kendi üzerinden geçirebilir.
- IPv4 header'ında IHL alanı 4 bittir ve 0-15 arası değer alabilir. Bu yüzden değer 32 bitlik (4 baytlık) kelime cinsinden okunur: 5 ise $5 \times 4 = 20$ bayt, 8 ise $8 \times 4 = 32$ bayt. En kısa header 20 bayt, en uzun $15 \times 4 = 60$ bayttır. IPv4'te Version = 4 ve en kısa header'da IHL = 5 olduğundan ilk bayt onaltılık 0x45 olur. Seçenekler (options) varsa 20. bayttan başlar.
- IP'nin en temel zafiyeti kaynak adresin denetlenmemesidir. Source routing bile kaynak adresi yönlendirme için kullanmaz; yalnız paketin uğrayacağı router'ları belirtmeye yarar. libnet gibi Unix, Linux ve Windows sürümleri olan kütüphanelerle C, C++ ya da Python'dan istenen kaynak/hedef adresli paket üretilebilir. Kontrolü ele geçirilmiş bir bilgisayardaki kötü kod bu yolla hizmet engelleme saldırısına katılabilir ya da kendi kimliğini gizleyerek o makinenin hattını kullanabilir.
- TCP'de alıcı her zaman bir sonra beklediği baytın sıra numarasını onaylar. Derste verilen örnekte 401-403 baytlarını taşıyan 3 baytlık bir segment alınınca ACK 404 olur. Ardından 404'ten 4 bayt (404-407) ve 408'den 3 bayt (408-410) taşıyan iki segment gelirse alıcı tek bir ACK 411 gönderebilir ($404 + 4 = 408$, $408 + 3 = 411$). 404 segmenti kaybolursa alıcı 408-410'u almış olsa bile ACK 404 gönderir; gönderen 404'ü yeniden yollar ve ardından ACK 411 gelir (ekrandan, 01:25:00).
- Üçlü el sıkışmada client bir SYN ve kendi sıra numarasını gönderir; server isteği kabul ederse ACK alanına gelen sıra numarasının bir fazlasını, sıra alanına kendi numarasını yazar; client da ACK alanına server'ın sıra numarasının bir fazlasını yazar. Derste anlatılan örnekte son mesajda client ACK 201 ve sıra numarası 101 kullanır, yani client'ın başlangıç numarası 100, server'ınki 200'dür.
- Sahte bağlantı saldırısında asıl engel, server'ın SYN/ACK cevabının sahte kaynak adresin gerçek sahibine gitmesidir. Saldırgan bu cevaptaki sıra numarasını görmeden üçüncü mesajı doğru ACK ile göndermek zorundadır. Reset saldırısında ise sıra numarasının tam tutması gerekmez; pencere içinde kalması yeterlidir. Hoca pencere boyunu yaklaşık 32K-64K aldı ve $2^{32}$'lik uzayın $2^{16}$'lık parçalara bölündüğünü, bu yüzden tahmin olasılığının belirgin biçimde arttığını söyledi.
- DNS'te sorumluluk kademeli olarak devredilir: root bazı yetkileri edu'ya, edu Stanford'a, Stanford CS'e devreder; www yapraktır, yani hosttur. Önbellekleme DNS sistemine gelen yükü azaltır; olumsuz cevaplar da olmayan adresler için gereksiz sorgu oluşmasın diye önbelleğe alınır. DNS'in UDP üzerinde çalışmasının nedeni verimdir: tek soru ve tek cevap paketi yeterlidir, TCP ile aynı iş 9 mesaj tutardı.
- Derste bir `dig` çıktısı incelendi: sorulan sunucu cevabı yetkili olarak değil, önbellekten bildiği bilgiyle verdi (AA biti 0), recursion yapmadı, ama sorulan alanın iki yetkili isim sunucusunu ve onların IP adreslerini ek kayıt (additional records) olarak gönderdi. Böylece soran taraf ek sorgu yapmadan bu sunuculara gidebilir. <!-- BELİRSİZ: Sorgulanan alan adı altyazıda "unix.viz.net" diye geçiyor; büyük olasılıkla unixwiz.net. İlgili kare yok. -->

> **Ders sonrası not:** Hoca 00:16:59'da slayttaki 32 bitlik örneği "IP header'ından bir parça" diye tanıttı. Slayttaki alanlar (Source Port, Destination Port, Length, Checksum, 8 bayt) UDP header'ına aittir (ekrandan, 00:15:00).

> **Ders sonrası not:** Hoca IP header checksum'ı "bir XOR işlemi" diye anlattı. Doğrusu, header'ın 16 bitlik kelimelerinin birler tümleyeni (one's complement) toplamının birler tümleyenidir.

> **Ders sonrası not:** Hoca Fragment Offset'in bayt cinsinden olduğunu söyledi. Doğrusu, Fragment Offset 8 baytlık birimlerle ifade edilir.

> **Ders sonrası not:** Hoca Pakistan Telecom'un YouTube'un bütün adres aralığını duyurduğunu söyledi. Slaytta duyurulanın YouTube ağının küçük bir kısmı (208.65.153.0/24) olduğu yazıyor (ekrandan, 01:00:00). Büyük olasılıkla bu daha özel (more specific) önek, YouTube'un kendi duyurusundan öncelikli seçildiği için trafik dünya çapında Pakistan'a yöneldi.

> **Ders sonrası not:** Hoca ARP paketinde en küçük frame boyunu sağlamak için "10 bayt kadar" eksik kaldığını söyledi. 28 baytlık ARP verisi ile 46 baytlık en küçük payload arasındaki fark $46 - 28 = 18$ bayttır; dolgu büyük olasılıkla 18 bayttır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
