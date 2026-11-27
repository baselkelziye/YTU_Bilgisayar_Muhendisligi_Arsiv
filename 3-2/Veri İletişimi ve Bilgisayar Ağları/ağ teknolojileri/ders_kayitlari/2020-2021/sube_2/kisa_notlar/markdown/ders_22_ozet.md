# Ders 22 Çalışma Özeti

## Genel Konular

- UDP (User Datagram Protocol)
  - IP üzerine ince bir katman ("shim over IP"); başlıkta yalnız kaynak port, hedef port, UDP uzunluğu ve UDP checksum vardır, her alan 16 bittir (ekrandan, 00:10:00).
  - Portlar TSAP'lerin TCP/IP'deki karşılığıdır; 16 bit olduğu için 0-65535 arası değer alır ve gelen verinin hangi prosese verileceğini belirler.
  - UDP uzunluğu başlık ve verinin toplamıdır; en küçük değer 8'dir (yalnız başlık).
  - Checksum, IP başlık checksum'ı gibi bire tümleyen (one's complement) toplamla hesaplanır; veri bütünlüğü önemsizse 0 bırakılabilir.
  - Bağlantısızdır: oturum, sıra numarası, parçalama, akış denetimi, tıkanıklık denetimi ve yeniden gönderim yoktur. Bunlar gerekiyorsa üstteki protokolde gerçekleştirilir.
  - İdeal olan, bir UDP datagramının alt katmanın tek çerçevesine sığmasıdır; UDP üzerine kurulu protokollerin çoğu datagramın tek parça geldiğini varsayar.
  - Tek soru-tek cevap işleri için uygundur; en tipik örnek DNS'tir. IP başlığındaki protokol alanında UDP'nin numarası 17'dir.
- RPC (Remote Procedure Call)
  - Ağ üzerindeki uygulamaları tanıdık yordam çağrısı soyutlamasıyla bağlar; nesne yönelimli dillerdeki karşılığı RMI'dır (ekrandan, 00:20:00).
  - İstemci ve sunucu tarafındaki stub'lar parametreleri ve sonuçları mesaja paketler; programcı soket ayrıntılarıyla uğraşmaz.
  - Zorluklar: C'deki işaretçiler karşı tarafta anlamsızdır; işaretçinin gösterdiği alanın sınırı bilinmez, bu yüzden veri paketlenip gönderilmelidir.
  - "UDP with retransmissions is a low-latency transport": kayıp olursa çağrı kullanıcıya şeffaf biçimde tekrarlanır.
- RTP (Real-time Transport Protocol)
  - Gerçek zamanlı medyayı UDP üzerinden taşır; genellikle uygulamanın parçası olarak kullanıcı alanında (user space) bir kütüphanedir, UDP ise çekirdektedir (ekrandan, 00:30:00).
  - Kapsülleme: Ethernet başlığı | IP başlığı | UDP başlığı | RTP başlığı | RTP yükü.
  - Başlık alanları: Ver., P, X, CC, M, Payload type, Sequence number (16 bit), Timestamp, Synchronization source identifier, Contributing source identifier (ekrandan, 00:35:00).
  - RTCP kardeş protokolü yönetim (kontrol) işlerini yapar; TCP ile ilgisi yoktur.
- Jitter ve oynatma tamponu
  - Kaynak paketleri sabit hızla gönderir, ağ değişken gecikme uygular, alıcı tamponu paketleri yine sabit hızla oynatır (ekrandan, 00:40:00).
  - Gecikmesi tamponun karşılayabileceği sınırı aşan paket oynatmada boşluk (gap in playback) yaratır.
  - Yüksek jitter daha büyük oynatma tamponu ister; yayılma gecikmesi tampon boyutunu etkilemez (ekrandan, 00:45:00).
- TCP hizmet modeli
  - Güvenilmez IP üzerinde prosesler arasında güvenilir bir bayt akışı sağlar; iyi bilinen portlar tablosu (ekrandan, 00:50:00).
  - Uygulama segmentleri değil, bayt akışını görür: 512 baytlık dört segment alıcıda tek 2048 baytlık okumayla ya da bayt bayt okunabilir (ekrandan, 00:55:00).
- TCP segment başlığı
  - Kaynak/hedef port, sıra numarası, onay numarası, başlık uzunluğu (4 bit, 4 ile çarpılır), bayraklar (CWR, ECE, URG, ACK, PSH, RST, SYN, FIN), pencere boyutu (16 bit), checksum, urgent pointer, seçenekler (0 ya da daha fazla 32 bitlik kelime), isteğe bağlı veri (ekrandan, 01:00:00).
- TCP bağlantı kurulumu ve durum makinesi
  - Üç yönlü el sıkışma; eş zamanlı bağlantı (simultaneous connect) dört mesajla çözülür (ekrandan, 01:10:00).
  - 11 durumlu sonlu durum makinesi; bağlantı sonlandırma (FIN WAIT 1/2, CLOSING, TIME WAIT, CLOSE WAIT, LAST ACK) (ekrandan, 01:15:00 ve 01:20:00).
- TCP kayan pencere ve akış denetimi
  - ACK + WIN gönderenin sınırıdır; 4 KB'lık alıcı tamponu örneği (ekrandan, 01:25:00).
  - Pencere yoklaması (window probe), gecikmeli onay (delayed acknowledgement) ve aptal pencere sendromu (silly window syndrome) (ekrandan, 01:30:00).
- TCP zamanlayıcı yönetimi
  - Veri bağı katmanında tek bağlantının RTT dağılımı dar ve diktir; taşıma katmanında çok atlamalı yolun RTT dağılımı basık ve geniştir.
  - Zaman aşımı ortalama ve değişkenlikten dinamik olarak hesaplanır.
- TCP tıkanıklık denetimi (yalnız değinildi)
  - AIMD, tıkanıklık penceresi (cwnd), ACK saati, slow-start, additive increase, fast retransmit/recovery tablosu ekranda gösterildi (ekrandan, 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- UDP'nin IP protokol numarası 17'dir
  - IP başlığının protokol alanında 17 görülüyorsa içerik UDP'dir; "unutmayın" diye vurgulandı.
- RTCP'deki "TCP" Transmission Control Protocol değildir
  - RTCP, real-time transport'un kontrol protokolüdür; sorularda karışıklık yaratabileceği için özellikle uyarıldı.
- TCP bir bayt akışıdır
  - Çözünürlük bayttır; segment sınırları uygulamaya görünmez. "Bunu hiçbir zaman unutmayın" denildi.
- Sıra ve onay numarası
  - TCP başlığının en önemli parçalarıdır; sıranın takibi bunlarla yapılır. Gerçek TCP'de ACK, beklenen bir sonraki baytın numarasını taşır (x gönderilince x+1 döner).
- Onaylar bayt cinsindendir
  - 2 KB gönderildiğinde baytlar 0-2047 arasıdır, onay 2048 olur.
- Kontrol paketleri de kaybolabilir
  - FIN, ACK ya da pencere güncellemesi de bozulabilir veya kaybolabilir; zamanlayıcılar ve pencere yoklaması bu yüzden vardır.

## Kısa Tekrar Notları

- UDP başlığı 8 bayt: kaynak port, hedef port, uzunluk, checksum (her biri 16 bit).
- UDP: bağlantısız, sırasız, akış/tıkanıklık denetimi ve yeniden gönderim yok; DNS ve RPC için uygun.
- RPC'de stub'lar parametre/sonuç paketler; işaretçi aktarımı sorunludur.
- RTP kullanıcı alanında, UDP üzerinde çalışır; sıra numarası, zaman damgası ve SSRC ile akışları eşler, jitter ile baş eder.
- Jitter, gecikmenin ortalamadan sapmasıdır; alıcı tamponu jitter'ı söndürür; yüksek jitter büyük tampon ister.
- TCP: güvenilir, bağlantı yönelimli bayt akışı; iyi bilinen portlar 0-1023.
- TCP başlık uzunluğu alanı ×4 = bayt cinsinden uzunluk.
- URG ve PSH aciliyet için konmuştur; günümüzde URG'nin kullanılmaması önerilir.
- RST bağlantıyı sıfırlar; SYN bağlantı kurma, FIN sonlandırma içindir.
- Normal kurulum 3 mesaj; eş zamanlı açılış 4 mesaj.
- TCP durum makinesinde 11 durum vardır; bağlantı iki ayrı simplex gibi ayrı ayrı kapatılır.
- Akış denetimi örneği: ACK=2048 WIN=2048 → ACK=4096 WIN=0 → ACK=4096 WIN=2048 → 1K SEQ=4096.
- Aptal pencere sendromu: 1 baytlık pencere için 40 baytlık başlık göndermek; çözüm pencere güncellemesini bekletmektir.
- Zaman aşımı = ortalama RTT + 4 × sapma; RTT üstel ağırlıklı hareketli ortalamayla güncellenir.

## Detaylı Açıklamalar

- **UDP'nin yapısı ve kullanımı.** UDP datagramının başına yalnız dört alan eklenir. Port numaraları, IP başlığındaki kaynak ve hedef IP adreslerinin taşıma katmanındaki karşılığıdır: bir host üzerindeki hangi prosesin veriyi alacağını belirler. UDP uzunluğu başlık dahil toplam uzunluktur, bu yüzden en az 8'dir. Checksum, IP başlığındaki gibi bire tümleyen aritmetikle hesaplanır; alıcı checksum dahil hesabı yaptığında sonucun sıfıra denk gelmesi beklenir. Veri bütünlüğü önemli değilse checksum hesaplanmayıp 0 bırakılabilir. UDP'de sıra numarası olmadığından datagramlar birbirine bağlanamaz; IP parçalama yapabilse de pratikte bir UDP datagramının alt katmanın taşıyabileceği en büyük çerçeveye sığması idealdir. UDP işe yaramaz değildir: DNS gibi tek soru-tek cevaplık işlerde bağlantı kurmanın maliyeti gereksizdir.
- **RPC.** Bir uzak çağrı, yerel bir fonksiyon çağrısına benzer: argümanlar bir kerede gider, sonuç bir kerede döner. Bu, bağlantısız taşımaya birebir oturur. Programcının soket açma, connect/send/receive gibi ayrıntılarda boğulmaması için RPC bir soyutlama sağlar. İstemci ve sunucu stub'ları RPC paketiyle hazır gelir; programcı yalnız fonksiyonun hangi parametreleri alıp ne döndüreceğini tanımlayan bir şablon dosyası yazar, istemci ve sunucu kodu bundan üretilir. C'deki işaretçiler sorun çıkarır: yerel adres karşı tarafta anlamsızdır ve işaretçinin gösterdiği alanın sınırı bilinmez; bu yüzden gösterilen veri paketlenip gönderilmeli, dizilerde boyut da aktarılmalıdır. Taşınan veri ne kadar azsa uzak çağrı o kadar verimli olur. Kayıp durumunda çağrı kullanıcıya şeffaf biçimde yeniden gönderilir; tekrar tekrar çalıştırılması sorun olmayan işlemlerde cevap gelene kadar beklemeden yeniden göndermek bile mümkündür, ama ağ kullanımı açısından tartışmalıdır. RPC çoğunlukla güvenilir ve hızlı ağlarda kullanılır.
- **RTP ve RTCP.** RTP bir taşıma protokolüdür ama UDP üzerine kurulur ve kullanıcı alanında bir kütüphane olarak çalışır. Multimedya uygulamasının ürettiği veri RTP kütüphanesiyle RTP yüküne dönüşür, önüne RTP başlığı gelir ve soket arayüzü üzerinden UDP ile gönderilir. Ağ sorunsuzken paketler akar; RTP asıl olarak kayıp, gecikme ve hata olduğunda işe yarar. Sıra numarası (16 bit) akış içindeki parçayı, senkronizasyon kaynak tanımlayıcısı akışın kaynağını, zaman damgası ise senkronizasyonu ve kayma çok artınca yeniden eşlemeyi sağlar. RTP'nin amacı farklı kaynaklardan gelen birden fazla multimedya akışını tek bir UDP akışına çevirmektir; CC katkıda bulunan kaynak sayısını, contributing source identifier'lar karıştırılmış (mix) bir akışın kaynaklarını verir. P biti 32 bitin katına tamamlamak için dolgu yapıldığını, X biti uzantı başlığı olduğunu, M (marker) biti uygulamaya özgü bir işareti (örneğin videoda anahtar karenin başı) gösterir. Kontrol mesajlaşması RTCP ile içerikle aynı yol üzerinden (in-band) yapılır.
- **Jitter ve tampon.** Saniyede 25 ya da 30 kare gibi sabit bir periyot korunmalıdır. Kaynak paketleri eşit aralıkla çıkarır, ağ farklı gecikmeler uygular; paketler geldikleri anda oynatılırsa görüntüde duraksama, seste bozulma olur. Alıcı tamponu paketleri biriktirip sabit hızla oynatır. Örnekte 8 numaralı paketin gecikmesi tamponun karşılayabileceği sınırı aştığı için 7'den sonra oynatmada boşluk oluşur. Tampon sonsuz değildir: canlı yayında bir karenin geçerliliği bir sonraki kareye kadardır, kayıttan oynatmada ise daha çok bekletme mümkündür. Düşük jitter'da gecikmeler dar bir aralıkta toplandığından küçük bir tampon yeter; yüksek jitter'da geniş dağılım vardır, tampon büyür ve yine de kaçırılan paketler (misses) olabilir; bu durumda zaman damgası ve sıra numarasıyla yeniden senkronizasyon yapılır.
- **TCP hizmet modeli ve portlar.** TCP güvenilmez IP üzerinde güvenilir hizmet kurar; güvenilirlik sorununun üst katmanda çözülmesi daha esnektir. Portlara soket API'leri üzerinden erişilir. İlk 1024 port (0-1023) iyi bilinen portlardır ve listesi IANA'dan görülebilir. FTP'de 20 ve 21 olmak üzere iki port vardır: biri veri, biri kontrol (kontrol bant dışı gider). TCP'nin hedefi, yerelde karakter, satır ya da tampon bazında dosyaya erişme esnekliğini uzak sistemler arasında da sağlamaktır; uzak bir uygulamadan tek bayt okunabilir (performansı kötü olsa da).
- **TCP başlığı ve bayraklar.** Başlık uzunluğu 4 bitlik alanda 32 bitlik kelime sayısı olarak tutulur. Pencere boyutu, önceki derste anlatılan kuramsal pencere yapısının pratikteki karşılığıdır. URG ve urgent pointer, uzak terminalde uzun bir listeleme sırasında basılan Ctrl-C gibi verinin akıştan önce işlenmesi için kullanılır; ancak uygulamalar arasında farklı yorumlandığı için kullanılmaması önerilir. PSH, verinin tamponda bekletilmeden uygulamaya verilmesini ister; API'ler bunun yerine TCP_NODELAY gibi seçenekler sunar. ACK, onayın segmente gömülü olduğunu (piggyback) gösterir. RST bir sorun ya da reddedilen bağlantıda bağlantıyı sıfırlar. SYN "synchronize", FIN "finish" kelimesinden gelir. Başlık zorunludur ama arkasında veri olmayabilir (salt SYN, PSH ya da RST segmentleri).
- **Bağlantı kurulumu ve sonlandırma.** İki taraf sıra numaralarını değiş tokuş eder; client SEQ=x gönderir, server SEQ=y, ACK=x+1 ile cevap verir, client SEQ=x+1, ACK=y+1 ile bitirir. İki taraf aynı anda bağlantı açarsa dört mesaj yeter; biri bağlantıyı kurduktan sonra öteki ayrıca bağlantı açarsa altı mesaj gerekir. TCP tam çift yönlü bağlantıyı iki ayrı simplex gibi ele alır ve her yönü ayrı kapatır: FIN gönderilir, karşılığında ACK beklenir. Kontrol paketleri de kaybolabileceğinden bekleme durumları (FIN WAIT 1, FIN WAIT 2) ve zaman aşımları vardır. Mantıksal olarak kapanan bağlantıya ait gecikmiş paketler hâlâ gelebileceği için TIME WAIT durumunda bir süre beklenir. Bu süreler ve sürekli SYN gönderme (SYN saldırısı) ya da bağlantı kurup hiç kullanmama gibi yollar, sunucunun kaynaklarını tüketen saldırılara kapı açar.
- **Kayan pencere örneği.** Alıcı tamponu 4 KB ve boştur. Gönderen 2K'yı SEQ=0 ile yollar; alıcı ACK=2048 WIN=2048 döner. Gönderen 2K'yı SEQ=2048 ile yollar; tampon dolar, alıcı ACK=4096 WIN=0 döner ve gönderen bloke olur. Uygulama 2K okuyunca alıcı ACK=4096 WIN=2048 gönderir; gönderen 1K'yı SEQ=4096 ile yollar ve bu veri dairesel tamponun başına yerleşir. Böylece akış denetimi veri bağı katmanında tek atlamada değil, taşıma katmanında uçtan uca kayan pencereyle sağlanır. Pencere güncellemesi kaybolursa gönderen hiç gönderemeyebilir; bu yüzden pencere 0 iken bile pencere yoklaması ve urgent veri gönderilebilir.
- **Aptal pencere sendromu.** Alıcı tamponu doluyken uygulama 1 bayt okursa alıcı 1 baytlık pencere ilan eder; bunun için 20 bayt IP ve 20 bayt TCP başlığı, yani 40 bayt gider, karşı taraf da 1 bayt veri için 40 baytlık başlık kullanır. Bu çok düşük verimdir. Çözüm, pencere güncellemesini hemen göndermeyip bekletmektir (delay).
- **Zamanlayıcı.** TCP bir segmentin onayını ne kadar bekleyeceğini sabit değil dinamik belirler, çünkü farklı hedeflere farklı yollar üzerinden gönderir. Ortalama RTT, üstel ağırlıklı hareketli ortalamayla (EWMA, smoothed RTT) güncellenir; zaman aşımı ortalamaya değişkenliğin 4 katı eklenerek bulunur.
- **Ders sonrası not:** Hoca zaman aşımı için "varyansın 4 katı artı ortalama" dedi; standart TCP'de (büyük olasılıkla RFC 6298) RTO = SRTT + 4 × RTTVAR'dır ve RTTVAR varyans değil, ortalama mutlak sapmadır.
- **Ders sonrası not:** Hoca Remote Desktop portunu "3386 değil, 3383" diye söyledi; Microsoft Remote Desktop büyük olasılıkla 3389 numaralı portu kullanır.
- **Ders sonrası not:** Hoca UDP uzunluğunun üst sınırı için "2 üzeri 16" dedi; 16 bitlik alanın alabileceği en büyük değer $2^{16}-1 = 65535$'tir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
