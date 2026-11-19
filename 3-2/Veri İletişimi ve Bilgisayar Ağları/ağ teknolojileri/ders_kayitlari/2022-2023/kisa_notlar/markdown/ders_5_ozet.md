# Ders 5 Çalışma Özeti

## Genel Konular

- Taşıma katmanına giriş
  - Dersin üçüncü konusu taşıma katmanıdır. Uygulama katmanı İnternet'in görünen katmanıdır; taşıma katmanı ona hizmet verir.
  - İnternet "ağların ağı"dır ve ağ katmanında güvenilir veri aktarımı yoktur. Güvenilir aktarım üst katmanda yapılmalıdır. Güvenilir aktarım için akış kontrolü ve tıkanıklık kontrolü mekanizmaları da gerekir.
  - Konu sırası (ekrandan, 00:20:00): taşıma katmanı hizmetleri, çoğullama ve çoğul çözme (multiplexing/demultiplexing), bağlantısız taşıma (UDP), güvenilir veri aktarımı ilkeleri, bağlantı yönelimli taşıma (TCP), tıkanıklık kontrolü ilkeleri, TCP tıkanıklık kontrolü, taşıma katmanı işlevlerinin evrimi. Bu derste ilk dördü işlendi.
- Taşıma katmanı hizmetleri
  - Taşıma katmanı, farklı hostlarda çalışan uygulama süreçleri arasında mantıksal iletişim sağlar. Örnek: cep telefonundaki tarayıcı ile uzaktaki Apache Web sunucusu arasında uçtan uca mantıksal bağlantı (ekrandan, 00:30:00).
  - Taşıma protokolleri uç sistemlerde çalışır. Gönderici taraf uygulama mesajını segmentlere böler, başlık alanlarını belirler ve ağ katmanına verir. Alıcı taraf başlıkları kontrol eder, uygulama mesajını çıkarır ve soket üzerinden doğru uygulamaya iletir.
  - Ev benzetmesi (ekrandan, 00:25:00): Ann'in evindeki 12 çocuk Bill'in evindeki 12 çocuğa mektup yolluyor. Host = ev, süreç = çocuk, uygulama mesajı = zarftaki mektup. Taşıma protokolü mektupları evdeki kardeşlere dağıtan Ann ve Bill'dir; ağ katmanı protokolü posta hizmetidir.
  - Ağ katmanı hostlar arasında, taşıma katmanı süreçler arasında mantıksal iletişim sağlar.
- İki temel İnternet taşıma protokolü (ekrandan, 00:30:00)
  - TCP (Transmission Control Protocol): güvenilir ve sıralı teslim, tıkanıklık kontrolü, akış kontrolü, bağlantı kurulumu. Sıralı teslim gerekir, çünkü mesaj segmentlere bölünür ve alıcıda yeniden birleştirilmelidir.
  - UDP (User Datagram Protocol): güvenilmez, sırasız teslim; "en iyi çaba" IP'nin süssüz (no-frills) uzantısıdır.
  - İkisi de gecikme ya da bant genişliği garantisi vermez.
- Çoğullama ve çoğul çözme
  - Bir hostta birçok süreç çalışır ve her süreç taşıma katmanına bir "kapı" olan soket üzerinden erişir.
  - Göndericide çoğullama: birden çok soketten gelen veriyi alır, sonradan çoğul çözmede kullanılacak taşıma başlığını ekler.
  - Alıcıda çoğul çözme: başlık bilgisini kullanarak alınan segmentleri doğru sokete teslim eder (ekrandan, 00:35:00).
  - Host IP datagramlarını alır; her datagramda kaynak ve hedef IP adresi, taşıdığı segmentte kaynak ve hedef port numarası vardır. Host, segmenti doğru sokete yönlendirmek için IP adreslerini ve port numaralarını kullanır.
  - TCP/UDP segment biçimi 32 bit genişliğindedir; başlıkta 16 bitlik kaynak port ve 16 bitlik hedef port ile diğer alanlar, ardından yük (payload, uygulama verisi) bulunur.
- Bağlantısız (UDP) çoğul çözme (ekrandan, 00:40:00)
  - Soket oluşturulurken host-yerel port belirtilir: `DatagramSocket mySocket1 = new DatagramSocket(12534);`
  - UDP soketine datagram gönderirken hedef IP adresi ve hedef port belirtilir.
  - Alıcı host UDP segmentindeki hedef portu kontrol eder ve segmenti o porta sahip sokete yönlendirir.
  - Hedef portu aynı, kaynak IP adresi ve/veya kaynak portu farklı IP/UDP datagramları alıcıda aynı sokete yönlendirilir.
  - Örnek: sunucudaki soket 6428, istemcideki P3 9157. P3'ten sunucuya giden segment kaynak 9157, hedef 6428; dönüşte kaynak 6428, hedef 9157. Sunucu ikinci istemciye (P4) gönderirken de kaynak port 6428 olur.
- Bağlantı yönelimli (TCP) çoğul çözme
  - TCP soketi dört değerle (4-tuple) tanımlanır: kaynak IP, kaynak port, hedef IP, hedef port. Alıcı dört değeri birden kullanır.
  - Sunucu aynı anda birçok TCP bağlantısını destekleyebilir; her soket kendi dörtlüsüyle tanımlanır ve her bağlantı ayrı bir sokettir.
  - Örnek (ekrandan, 00:45:00): A hostundan B sunucusuna (Apache, port 80) giden segment kaynak A,9157, hedef B,80; dönüş kaynak B,80, hedef A,9157. C hostundan iki bağlantı: kaynak C,5775 ve kaynak C,9157, ikisinin de hedefi B,80. A ve C'deki iki süreç aynı port 9157'yi kullansa da IP adresleri farklı olduğu için dörtlüler farklıdır. Hedefi B,80 olan üç segment de farklı soketlere çoğul çözülür.
- UDP
  - Süssüz, "çıplak" İnternet taşıma protokolüdür. En iyi çaba hizmeti verir: segmentler kaybolabilir ya da uygulamaya sırasız teslim edilebilir (ekrandan, 01:10:00).
  - Bağlantısızdır: gönderici ve alıcı arasında el sıkışma yoktur, her segment diğerlerinden bağımsız işlenir.
  - Neden UDP: bağlantı kurulmaz (RTT gecikmesi eklenmez), basittir (gönderici ve alıcıda bağlantı durumu yok), başlığı küçüktür, tıkanıklık kontrolü yoktur (istendiği kadar hızlı gönderebilir, tıkanıklık sırasında da çalışabilir).
  - Kullanım: kayba dayanıklı ve hıza duyarlı akış (streaming) uygulamaları, DNS, SNMP, HTTP/3.
  - HTTP 1.1 ve HTTP/2 TCP kullanır. HTTP/3 UDP kullanır; güvenilirlik, tıkanıklık kontrolü ve akış kontrolü uygulama katmanında eklenir.
  - Standardı RFC 768'dir; yaklaşık üç sayfalık, okunması kolay bir belgedir.
- UDP gönderici ve alıcı işlemleri (ekrandan, 01:15:00)
  - Gönderici: uygulama katmanı mesajını alır (örnekte SNMP mesajı), UDP başlık alanı değerlerini belirler, UDP segmentini oluşturur, segmenti IP'ye verir.
  - Alıcı: segmenti IP'den alır, UDP checksum başlık değerini kontrol eder, uygulama mesajını çıkarır ve soket üzerinden uygulamaya çoğul çözer. Hata varsa segment atılır.
- UDP segment başlığı
  - Kaynak port (16 bit), hedef port (16 bit), uzunluk (16 bit; başlık dahil UDP segmentinin bayt cinsinden uzunluğu), checksum (16 bit), ardından uygulama verisi.
- UDP (İnternet) checksum (ekrandan, 01:20:00)
  - Amaç: iletilen segmentte bit hatalarını (1'in 0'a ya da 0'ın 1'e dönmesini) tespit etmek.
  - Gönderici: UDP segmentinin içeriğini (UDP başlık alanları ve IP adresleri dahil) 16 bitlik tamsayılar dizisi olarak ele alır; checksum, içeriğin bire tümleyen (one's complement) toplamıdır; değer UDP checksum alanına yazılır.
  - Alıcı: alınan segmentin checksum'ını hesaplar, checksum alanıyla karşılaştırır. Eşit değilse kesin hata vardır. Eşitse hata tespit edilmemiştir, ama yine de hata olabilir.
  - Hesap: 16 bitlik sayılar toplanır, en anlamlı bitten taşan elde (carry) sonuca geri eklenir (wraparound), toplamın bitleri ters çevrilir (bire tümleyen).
- Güvenilir veri aktarımı (rdt) ilkeleri
  - Kanal %100 güvenilirse ek mekanizma gerekmez. Güvenilmez kanal üzerinde güvenilir iletişim için göndericide ve alıcıda bir protokol gerekir (ekrandan, 01:25:00).
  - Protokolün karmaşıklığı alttaki kanalın özelliklerine bağlıdır: kablosuz kanalda kayıp çoktur, fiber optik kanal neredeyse güvenilirdir.
  - Gönderici ve alıcı birbirinin durumunu, mesajla bildirilmedikçe bilemez; aralarında bir "perde" vardır.
  - Arayüzler (ekrandan, 01:30:00): `rdt_send()` yukarıdan (uygulama) çağrılır; `udt_send()` rdt tarafından paketi güvenilmez kanala vermek için çağrılır; `rdt_rcv()` paket alıcı tarafa ulaşınca çağrılır; `deliver_data()` veriyi üst katmana teslim eder.
  - Protokol adım adım geliştirilir. Başlangıçta yalnız tek yönlü veri aktarımı ele alınır, kontrol bilgisi iki yönde akar. Gönderici ve alıcı sonlu durum makineleriyle (FSM) tanımlanır.
- rdt1.0: güvenilir kanal üzerinde güvenilir aktarım (ekrandan, 01:35:00)
  - Kanal tamamen güvenilirdir: bit hatası ve paket kaybı yoktur. Gönderici ve alıcı için ayrı FSM vardır.
  - Gönderici "yukarıdan çağrı bekle" durumundadır: `rdt_send(data)` gelince `packet = make_pkt(data)`, `udt_send(packet)`.
  - Alıcı "aşağıdan çağrı bekle" durumundadır: `rdt_rcv(packet)` gelince `extract(packet,data)`, `deliver_data(data)`.
- rdt2.0: bit hatası olan kanal (ekrandan, 01:40:00)
  - Kanal paketteki bitleri bozabilir; hata checksum ile tespit edilir. Hatadan kurtulmak için insan konuşmasındaki gibi geri bildirim kullanılır.
  - ACK (olumlu onay): alıcı paketin doğru alındığını bildirir. NAK (olumsuz onay): alıcı paketin hatalı olduğunu açıkça bildirir, gönderici paketi yeniden gönderir.
  - Dur ve bekle (stop-and-wait): gönderici bir paket gönderir, alıcının yanıtını bekler.
  - Gönderici FSM'inin iki durumu vardır: "yukarıdan çağrı bekle" ve "ACK ya da NAK bekle". `rdt_send(data)` gelince `sndpkt = make_pkt(data, checksum)`, `udt_send(sndpkt)`. NAK gelirse aynı paket yeniden gönderilir; ACK gelirse ilk duruma dönülür.
  - Alıcı: paket bozuksa NAK; bozuk değilse veriyi çıkarır, teslim eder ve ACK gönderir.
- rdt2.1: bozuk ACK/NAK'ların ele alınması (ekrandan, 01:45:00)
  - Sorun: ACK ya da NAK bozulursa gönderici alıcıda ne olduğunu bilemez; doğrudan yeniden göndermek alıcıda yinelenen (duplicate) paketlere yol açabilir.
  - Çözüm: gönderici her pakete sıra numarası ekler; ACK/NAK bozuksa mevcut paketi yeniden gönderir; alıcı yinelenen paketi atar.
  - Tek bitlik sıra numarası (0 ve 1) yeterlidir. Gönderici FSM'inin dört durumu vardır: "yukarıdan 0 çağrısı bekle", "ACK ya da NAK 0 bekle", "yukarıdan 1 çağrısı bekle", "ACK ya da NAK 1 bekle".
  - Alıcı, beklediği paketin sıra numarasının 0 mı 1 mi olduğunu hatırlamalı ve gelen paketin yineleme olup olmadığını kontrol etmelidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağ katmanı güvenilir değildir
  - İnternet'te ağ katmanı en iyi çaba hizmeti verir; güvenilir aktarım üst katmanda yapılır. TCP güvenilir aktarımı garanti ettiği için tıkanıklık ve akış kontrolüne sahiptir.
- Hiçbir taşıma protokolü gecikme ve bant genişliği garantisi vermez
  - TCP ve UDP'nin ikisi de böyle bir hizmet sunmaz.
- UDP ve TCP çoğul çözmesinin farkı
  - UDP soketi hedef IP ve hedef portla belirlenir; TCP soketi dört değerle belirlenir. Aynı port numarasını kullanan iki istemci süreci IP adresleri farklı olduğu için sunucuda ayrı bağlantılar olarak ayırt edilir.
- Checksum'da taşan elde geri eklenmelidir
  - Toplamada en anlamlı bitten taşan elde sonuca eklenir; hoca bunu kritik nokta olarak vurguladı.
- Checksum'ın eşit çıkması hatasızlık demek değildir
  - Örnekte dört bit bozulduğu halde checksum aynı çıktı. Eşit değilse hata kesin vardır; eşitse yalnız "hata tespit edilmedi" denebilir.
- HTTP/3 UDP kullanır
  - Hızlı olduğu için UDP seçilir; güvenilirlik, akış ve tıkanıklık kontrolü uygulama katmanında sağlanır.

## Kısa Tekrar Notları

- Taşıma katmanı: süreçler arası mantıksal iletişim. Ağ katmanı: hostlar arası mantıksal iletişim.
- Gönderici mesajı segmentlere böler, alıcı yeniden birleştirir.
- TCP: güvenilir, sıralı, akış ve tıkanıklık kontrolü, bağlantı kurulumu. UDP: güvenilmez, sırasız, en iyi çaba.
- Soket = süreç ile taşıma katmanı arasındaki kapı. Port alanları 16'şar bit.
- UDP soketi: hedef IP + hedef port. TCP soketi: kaynak IP, kaynak port, hedef IP, hedef port.
- UDP: el sıkışma yok, RTT gecikmesi yok, küçük başlık, tıkanıklık kontrolü yok. DNS, SNMP, HTTP/3, akış uygulamaları kullanır. RFC 768.
- UDP başlığı: kaynak port, hedef port, uzunluk, checksum (her biri 16 bit).
- Checksum: 16 bitlik toplama, taşan elde geri eklenir, bire tümleyen alınır. Eşitlik hatasızlığı kanıtlamaz.
- rdt1.0: kusursuz kanal. rdt2.0: bit hatası, ACK/NAK, dur ve bekle. rdt2.1: bozuk ACK/NAK, 0/1 sıra numarası, yinelenen paketin atılması.

## Detaylı Açıklamalar

- Taşıma katmanının yeri
  - Uygulama mesajları birden çok segmente bölünerek gönderilir. Gönderici taraf her segment için başlık alanlarını belirler ve segmentleri ağ katmanına verir; ağ katmanı IP başlığını ekler. Alıcıda ağ katmanı segmenti taşıma katmanına çıkarır; taşıma katmanı başlıkları kontrol eder, segmentlerden uygulama mesajını oluşturur ve doğru sokete iletir.
  - Ev benzetmesinde kardeşlere mektup dağıtan Ann ve Bill, bir hosttaki süreçlere segment dağıtan taşıma protokolüne karşılık gelir. Postanenin evden eve taşıması ise ağ katmanının hostlar arası iletişimidir.
- Çoğullamanın mantığı
  - Bir sunucuda aynı anda birçok süreç farklı istemcilerle konuşabilir. Örnekteki sunucuda P1, istemcideki P3 ile; P2 ise diğer istemcideki P4 ile haberleşir. Her sürecin kendi soketi olduğu için taşıma katmanı P1-P3 ve P2-P4 arasında ayrı mantıksal bağlantılar kurar.
  - Göndericide başlığa eklenen port bilgisi, alıcıda segmentin hangi sokete gideceğine karar verirken kullanılır. Ağ katmanındaki IP adresleri hostu, taşıma katmanındaki port numaraları süreci (soketi) ayırt eder.
- UDP ile TCP çoğul çözmesinin karşılaştırılması
  - UDP'de alıcı yalnız hedef portu kontrol eder. Bu yüzden farklı kaynaklardan gelip aynı hedef porta yönelen datagramlar aynı sokete düşer.
  - TCP'de bağlantı kurulduğu için her bağlantıya ayrı soket açılır ve dört değerin tamamı kullanılır. Örnekte A hostundaki süreç ile C hostundaki süreç aynı kaynak port 9157'yi kullanır, ama kaynak IP adresleri (A ve C) farklı olduğu için sunucu bu iki bağlantıyı ayırt eder.
- UDP'nin varlık nedeni
  - UDP hiçbir garanti vermez; bunun karşılığında bağlantı kurma gecikmesi yoktur, başlığı küçüktür ve tıkanıklık kontrolü gönderimi yavaşlatmaz. Bu yüzden bazı segmentlerin kaybolmasına dayanabilen, ama hız isteyen akış uygulamaları ve DNS, SNMP gibi protokoller UDP kullanır.
  - HTTP/3 güvenilirlik isteyen bir protokol olduğu halde UDP kullanır; güvenilirlik, akış ve tıkanıklık kontrolü uygulama katmanında yapılır.
- İnternet checksum örneği (ekrandan çıkarılamadı)
  - Derste iki 16 bitlik sayı toplandı, en anlamlı bitten taşan elde sonuca eklendi ve toplamın bire tümleyeni checksum olarak alındı. Ardından iki sayının en düşük anlamlı ikişer biti bozulduğunda (toplam dört bit) checksum'ın değişmediği gösterildi.
  - <!-- BELİRSİZ: Bu anlara (01:20:33-01:22:49) ait kare yok; sayıların değerleri ekrandan okunamadı. Hocanın sesli okuduğu bitler Kurose-Ross ders kitabının standart örneğiyle uyumludur: 1110011001100110 + 1101010101010101, wraparound sonrası toplam 1011101110111100, checksum 0100010001000011 (python ile doğrulandı). -->
  - Derste, checksum için bir önceki slaytta alıcının hesapladığı değerin 10, gönderilen checksum'ın 11 çıktığı ve paketin bozuk sayıldığı basit bir örnek de geçti. <!-- BELİRSİZ: Örneğin tam değerleri karede yok (01:18:41). -->
- rdt protokolünün adım adım kurulması
  - rdt1.0'da kanal kusursuz olduğu için gönderici veriyi pakete koyup gönderir, alıcı paketi açıp teslim eder; geri bildirime gerek yoktur.
  - rdt2.0'da kanal bit bozabilir. Alıcı checksum ile hatayı tespit eder ve ACK ya da NAK ile göndericiye bildirir. Gönderici ACK alınca yeni veri bekler, NAK alınca aynı paketi doğru alınana kadar yeniden gönderir. Bu bir dur ve bekle protokolüdür.
  - rdt2.0'ın açığı, ACK/NAK'ın da bozulabilmesidir. Gönderici emin olamadığı için paketi yeniden gönderir; alıcı bu durumda aynı paketi iki kez alabilir. rdt2.1 her pakete 0 ya da 1 sıra numarası koyar; alıcı beklediği sıra numarasını hatırlar ve yinelenen paketi atar. Böylece göndericinin durum sayısı ikiden dörde çıkar.
  - Ders, alıcı tarafın sıra numarası kontrolü anlatılırken bitti; konu bir sonraki derste devam edecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
