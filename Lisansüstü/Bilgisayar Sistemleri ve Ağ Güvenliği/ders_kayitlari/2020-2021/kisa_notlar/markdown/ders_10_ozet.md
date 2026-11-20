# Ders 10 Çalışma Özeti

## Genel Konular

- Ağ protokollerinin güvenlik açısından tekrarı (ekrandan, 00:20:00 ve 00:25:00)
  - Ethernet'in tasarımında gizlilik (confidentiality), kimlik doğrulama (authentication) ve bütünlük (integrity) yoktur. Haberleşme MAC adresleri üzerinden olur; IP adresi bilinse bile paket göndermek için hedefin MAC adresi gerekir.
  - ARP (Address Resolution Protocol), yerel ağdaki hostların birbirinin MAC adresini bulmasını sağlar. İstemci tüm MAC'lere yayın (broadcast) yapar: "192.168.1.1 IP'si hangi MAC adresinde?" ARP'de yerleşik güvenlik yoktur.
  - Saldırgan, ARP isteğine gerçek hosttan önce cevap vererek ya da kimse sormadan "gratuitous ARP" duyurusu yaparak başka hostları taklit edebilir. Ağın ortasına yakın konumdaki saldırgan, büyük LAN'lardaki yayılma gecikmesi sayesinde uçtaki gerçek hosttan daha hızlı cevap verebilir.
  - IP: yönlendirme hedef adrese göre yapılır, IP "best effort"tur. Kontrol toplamı kriptografik değildir ve yalnız başlığı (header) kapsar. Kaynak adresi gönderen yazar, dolayısıyla istenen değer konabilir.
  - BGP: servis sağlayıcıların ağlarını duyurduğu, ülkeler ve kıtalar arası geçişte de kullanılan protokol. Standart BGP'de kimlik doğrulama yoktur (Secure BGP ayrıdır). Başkasına ait ağ için duyuru yapılabilir; yanlış girilen bir maske ya da adres, uzak bölgelerdeki yönlendirmeyi de bozabilir.
  - TCP: güvenilir olmayan IP ve Ethernet üzerinde güvenilir, sürekli bir veri akışı sağlar. Veri segmentlere bölünür, alınan veri onaylanır (acknowledgement), kaybolan paketler yeniden gönderilir. Her bağlantı üç yönlü el sıkışmayla (three-way handshake) başlar.
  - İnternette en temel önlem taşıma katmanı güvenliğidir (TLS): HTTP yerine HTTPS kullanmak, çerezleri yalnız güvenli bağlantıda gönderilecek şekilde ayarlamak.
- Servis engelleme (Denial of Service, DoS) saldırıları
  - Hedef, yüksek hacimli trafikle bir sunucuyu ya da siteyi devre dışı bırakmaktır. Gerçek istekler saldırı isteklerinden ayırt edilemediği için servis düzgün verilemez.
  - Saldırganın amacı az eforla büyük etki yaratmaktır: küçük istekler, büyük cevaplar. Böylece kimliği gizli kalır ve düşük güçlü cihazlarla da saldırabilir.
- İki DoS türü (ekrandan, 00:30:00)
  - DoS Bug: tek bir makinenin servisi bozmasına izin veren tasarım hatası. Genellikle protokol asimetrisidir (istek göndermek kolay, cevap üretmek zor) ya da sunucuda durum (state) tutmayı gerektirir.
  - DoS Flood: kontrol edilen bir botnet'ten çok sayıda istek göndermek.
  - DoS her katmanda yapılabilir: bağlantı/ağ katmanında switch ve router'ları trafikle boğmak; taşıma katmanında (özellikle TCP) bağlantı durumlarını yönetilemez hale getirmek; uygulama katmanında sunucuyu pahalı sorgulara ya da kriptografik işlemlere zorlamak.
- SYN Flood (ekrandan, 00:35:00)
  - Sunucu SYN aldığında istemcinin ve kendi SYN/ACK'inin sıra numaralarını saklar ve üçüncü paketi (ACK) bekler. Bu bekleyen kayıtlar backlog kuyruğunu oluşturur ve kuyruk sınırlıdır.
  - Saldırgan rastgele kaynak IP adresli SYN paketleri gönderir. Üçüncü paket hiç gelmez, backlog dolar, gerçek istemciler de bağlanamaz.
  - Kötü çözümler: backlog boyutunu artırmak (saldırgan daha çok gönderir) ve zaman aşımını (timeout) kısaltmak (yavaş gerçek istemciler bağlanamaz).
  - Doğru yaklaşım: el sıkışma tamamlanmadan sunucuda durum tutmamak.
- SYN Cookies (ekrandan, 00:40:00)
  - Fikir: $SN_C$ ve $SN_S$'i saklamak yerine durumu istemciye bir "cookie" olarak göndermek.
  - $L = MAC_{key}(SAddr, SPort, DAddr, DPort, SN_C, T)$. Anahtar (key) açılışta rastgele seçilir ve yalnız sunucu bilir.
  - $T$: her 64 saniyede bir artan 5 bitlik sayaç. $SN_S = (T \,\|\, mss \,\|\, L)$; mss, maximum segment size'dan elde edilen değerdir.
  - Dürüst istemci ACK'te $AN = SN_S$ ve $SN = SN_C + 1$ gönderir. Sunucu soket için yeri ancak $SN_S$ geçerliyse ayırır.
  - Bedeli: her bağlantıda MAC hesabı ek işlem yükü getirir; ayrıca sunucu durum tutmadığı için TCP seçenekleri kaybolur. Bu yüzden SYN cookie çoğu zaman, bekleyen bağlantı sayısı bir eşiği aşınca açılır, ikinci bir eşiğin altına inince kapatılır.
- Amplification (güçlendirme) saldırıları (ekrandan, 00:45:00 ve 00:50:00)
  - Open DNS Resolver: herkesten gelen sorguya cevap veren DNS sunucusu. Normalde DNS sunucusu yalnız kendi alanındaki istemcilere cevap vermelidir. Google'ın 8.8.8.8'i de açık resolver'dır.
  - Saldırgan botlar üzerinden açık resolver'lara kaynak adresi kurbanın adresi olan (spoofed) "DNS ANY example.com" sorguları gönderdirir. Bütün büyük cevaplar kurbana gider; cevap sorgudan 60-70 kat büyüktür.
  - UDP bu saldırıya uygundur. DNS'teki ANY sorgusu bir alan adının bütün kayıtlarını döndürdüğü için en tehlikeli güçlendiricilerden biridir. NTP'deki monlist komutu, zamanı sorgulayan son 600'e kadar istemcinin listesini döndürür.
  - Güçlendirmenin işe yaraması için cevabın tek parça halinde dönmesi gerekir; gözlemlere göre çoğu yapılandırma buna izin verir.
  - 2013: DNS üzerinden 300 Gbps DDoS; yaklaşık 31.000 yanlış yapılandırılmış açık resolver, her biri 10 Mbps; kaynak IP sahteciliğine izin veren 3 ağ. 2014: 4.500 NTP sunucusuyla 400 Gbps.
  - Memcached saldırısı (Mart 2018): web sayfalarını hızlı sunmak için kullanılan önbellek sistemi; isteğe göre yaklaşık 50.000 kat büyük cevap üretebilir.
- IoT botnet'i: Mirai (ekrandan, 00:55:00 ve 01:00:00)
  - Yazıcı, router, kamera, DVR, set üstü kutu, IP telefon gibi web ya da komut satırı arayüzü olan, internete bağlı cihazlardan kurulan botnet (yaklaşık 200 bin cihaz). Hedefler: OVH, Dyn, Krebs.
  - Güçlendirme değil, taşkın (flood) yapılır: SYN, ACK, UDP ve GRE paketleri.
  - İşleyiş: tarama ve rapor (cihaz veritabanı), loader ile cihazın ele geçirilmesi, ardından saldırı komutları (başlat/durdur, hedef IP'ler, saldırı tipi, süre).
  - Cihazlar, üreticilerin belgelerinde açıkça yazan fabrika çıkışı varsayılan parolalarla ele geçirilir (çok kısa, tekrarlı rakamlar, "admin", "root", "default" gibi kelimeler ya da hiç parola olmaması). Telnet/SSH portlarını değiştirmek de pek işe yaramaz, çünkü port bilgisi de çevrimiçi kılavuzlardadır.
  - Krebs'in güvenlik bloğuna yapılan saldırı Akamai'nin o güne kadar gördüğü en büyük saldırılardandı (555 Gbps tepe değeri). Bu tür DDoS'lar içeriği sansürlemek için de kullanılır.
- Savunmalar ve diğer örnekler (ekrandan, 00:50:00, 00:55:00, 01:15:00)
  - Google Project Shield: Google'ın bant genişliğini savunmasız siteleri (haber, blog, insan hakları kuruluşları) korumak için kullanır. Proxy, SYN'lere SYN/ACK döner; yalnız ACK'i gelen bağlantıları siteye iletir. Bunun için çok yüksek bant genişliği gerekir.
  - Saldırganın cevabı: botların gerçek adresleriyle bağlantıyı tamamlamak, TLS el sıkışmasını yapmak ve sitedeki en büyük dosyaları GET ile istemek. Burada adresler bilindiği için kurban site botları engelleyebilir ya da hızlarını sınırlayabilir (rate limit).
  - GitHub saldırısı: HTTP isteklerine enjekte edilen JavaScript (imageFlood.js) dürüst kullanıcıların tarayıcılarından GitHub'a 1.35 Tbps trafik üretti.
  - Client puzzle: her bağlantıda istemciden işlem gücü gerektiren bir bulmaca çözmesi istenir; sunucuda doğrulama ucuzdur. Gerçek dünyada pek kullanılmaz: protokolde, istemcide ve sunucuda değişiklik gerekir, düşük güçlü meşru istemcilere (telefon, pilli cihazlar) zarar verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ethernet, ARP, IP ve standart BGP'de güvenlik özelliği yoktur.
  - Kaynak adresin gönderen tarafından yazılması, SYN flood ve amplification saldırılarının temelidir.
- İnternet üzerinden haberleşirken mutlaka TLS kullanılmalıdır.
  - HTTPS ve yalnız güvenli bağlantıda gönderilen çerezler en kolay örneklerdir.
- DoS'ta saldırganın kazancı asimetriden gelir.
  - Küçük istek, büyük cevap; 30-40 baytlık sorguya 3-4 KB'lık cevap.
- SYN cookie'de anahtar yalnız sunucuda durur.
  - İstemci cookie'yi çözmez, aynen geri gönderir; sunucu MAC'i yeniden hesaplayıp doğrular.
- Fabrika çıkışı parolaların değiştirilmemesi ciddi bir sorundur.
  - Mirai'nin yaklaşık 600 bin cihazı ele geçirmesi, bu cihazların hiçbirinin düzgün yapılandırılmadığını gösterir.
- Web güvenliğindeki basit kurallardan biri bile atlanırsa sonuç çok ağır olabilir.
  - GitHub saldırısı bunun örneğidir.

## Kısa Tekrar Notları

- ARP spoofing: isteğe önce cevap vermek ya da gratuitous ARP duyurusu yapmak.
- IP kontrol toplamı kriptografik değildir, yalnız başlığı korur.
- BGP'de kimlik doğrulama yoktur; yanlış duyuru ya da yapılandırma hatası uzak ağları da etkiler.
- DoS Bug = tasarım hatası ya da asimetri; DoS Flood = botnet ile trafik.
- SYN flood backlog'u doldurur. Backlog'u büyütmek ve timeout'u kısaltmak işe yaramaz.
- SYN cookie: $SN_S = (T \,\|\, mss \,\|\, L)$, $L = MAC_{key}(SAddr, SPort, DAddr, DPort, SN_C, T)$, $T$ = 64 saniyede bir artan 5 bitlik sayaç.
- Amplification: sahte kaynak adresi + açık resolver + büyük cevap. DNS ANY (60-70 kat), NTP monlist, memcached (yaklaşık 50.000 kat).
- 2013: 300 Gbps (31.000 resolver); 2014: 400 Gbps (4.500 NTP sunucusu).
- Mirai: IoT cihazları, flood (güçlendirme değil), varsayılan parolalar.
- Project Shield: el sıkışmayı tamamlamayan bağlantılar proxy'de kalır.
- Gerçek IP'lerle gelen saldırıya karşı engelleme ya da hız sınırlama.
- Client puzzle: istemciyi yavaşlatır ama pratikte nadir kullanılır.

## Detaylı Açıklamalar

Ders, önceki derste başlanan ağ güvenliği konusunun devamıdır. Hoca önce ağ katmanlarının güvenlik eksiklerini hatırlattı. Ethernet'te ve onun yardımcısı ARP'de hiçbir güvenlik mekanizması yoktur. ARP yayına dayandığı için, ağın ortasına yakın bir saldırgan sorulan IP için gerçek hosttan önce cevap verebilir. Kimse sormadan "benim IP'm bu, MAC'im bu" diye gratuitous ARP duyurusu da yapabilir. Gratuitous ARP normalde haberleşme başındaki gecikmeyi azaltmak için vardır, ama kötü niyetli host bununla kendini birçok host gibi tanıtabilir. IP'de kaynak adres alanını gönderen doldurur ve kontrol toplamı yalnız başlıktaki bit hatalarını bulmaya yarar. BGP'de de standart halinde kimlik doğrulama yoktur.

Dersin asıl konusu servis engelleme saldırılarıdır. DoS Bug, sunucu uygulamasındaki bir tasarım hatasını tetiklemektir. Bu ya sunucuyu çökertir ya da onu çok büyük işlem veya cevap üretmeye zorlar; genellikle uygulama protokollerindeki istek-cevap asimetrisinden kaynaklanır. DoS Flood ise botnet ile kesintisiz trafik göndermektir.

SYN flood'da sunucu, el sıkışmanın ilk paketini alınca iki sıra numarasını saklar ve üçüncü paketi bekler. Örneğin en fazla 1.000 yarım bağlantıya göre ayarlanmış bir sunucu, 1.001. isteğe ve sonrakilere cevap veremez. SYN cookie bu durumu istemciye taşır. Sunucu, bağlantının dört adres/port bilgisinden, istemcinin sıra numarasından ve zaman sayacı $T$'den yalnız kendi bildiği bir anahtarla bir MAC değeri $L$ üretir. Bunu $T$ ve mss ile birlikte kendi sıra numarası olarak gönderir. Gerçek istemci bu değeri ACK alanında geri yollar ve sunucu doğrular. Rastgele kaynak adresli sahte istemciler ACK yollamadığı için sunucuda hiçbir kayıt oluşmaz.

Amplification saldırılarında saldırgan, kaynak adresi kurban olan küçük sorguları açık DNS resolver'lara, NTP ya da memcached sunucularına gönderdirir; büyük cevaplar kurbana yağar. 2013'teki saldırıda 31.000 resolver, her biri yaklaşık 10 Mbps ile 300 Gbps üretti ($31000 \times 10$ Mbps $= 310$ Gbps). Bir yıl sonra yalnız 4.500 NTP sunucusuyla 400 Gbps üretildi, çünkü NTP cevabı istekten çok daha büyüktür. Mirai ise güçlendirme kullanmaz. Varsayılan parolalarla ele geçirdiği yüz binlerce IoT cihazıyla doğrudan taşkın yapar.

Savunmalarda Project Shield gibi yüksek bant genişlikli proxy'ler el sıkışmayı tamamlamayan bağlantıları ayıklar. Saldırgan buna karşı botların gerçek adresleriyle tam bağlantı kurup büyük dosyalar ister. Bu durumda adresler bilindiği için hız sınırlama uygulanabilir. Client puzzle ise istemciyi her bağlantı için hesap yapmaya zorlayarak saldırıyı yavaşlatır, ama protokol değişikliği gerektirdiği ve düşük güçlü cihazlara zarar verdiği için yaygın değildir.

<!-- BELİRSİZ: Client puzzle slaytı karelerde yok; bulmacanın tam tanımı (C ve X'in SHA-1 ile birleştirilmesi, n bit koşulu) altyazıdan net çıkmıyor (01:10:52-01:12:11). -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
