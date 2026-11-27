# Ders 22 Genişletilmiş Notu: UDP, RPC, RTP ve TCP: Başlık, Bağlantı Yönetimi ve Akış Denetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Taşıma Katmanının İnternet Protokollerine Giriş
- 2. UDP (User Datagram Protocol)
- 3. RPC (Remote Procedure Call)
- 4. RTP (Real-time Transport Protocol)
- 5. Jitter ve Oynatma Tamponu
- 6. TCP Hizmet Modeli
- 7. TCP Segment Başlığı
- 8. TCP Bağlantı Kurulumu
- 9. TCP Durum Makinesi ve Bağlantı Sonlandırma
- 10. TCP Kayan Pencere ve Akış Denetimi
- 11. Aptal Pencere Sendromu
- 12. TCP Zamanlayıcı Yönetimi
- 13. TCP Tıkanıklık Denetimine Kısa Bakış
- Örnek Sorular
- Dersin Toparlaması

## 1. Taşıma Katmanının İnternet Protokollerine Giriş

Ders, önceki haftalarda kuramsal olarak incelenen taşıma katmanının (tasarım ölçütleri, nelere dikkat edilmesi gerektiği) pratikteki uygulamalarına geçişle başlar. Ağ katmanında olduğu gibi burada da önce genel ilkeler, sonra İnternet'teki gerçek protokoller incelenir. İnternet'te taşıma katmanı IP üzerinde çalışır ve iki tür protokol vardır:

- Bağlantısız (connectionless) tarafta UDP ve onun üzerine kurulan Real-Time Transport Protocol (RTP).
- Bağlantı yönelimli (connection oriented) tarafta TCP. Önceki derslerde ağ bağlantısıyla (network connection) çalıştığı söylenen ve asıl ilgi çeken protokol budur.

Bölümün UDP kısmının başlıkları ekranda şöyle verilir (ekrandan, 00:05:00):

- Introduction to UDP
- Remote Procedure Call
- Real-Time Transport

## 2. UDP (User Datagram Protocol)

### 2.1 UDP başlığı

Slaytta UDP, "IP üzerinde ince bir katman" (UDP is a shim over IP) olarak tanımlanır; başlığında portlar (TSAP'ler), uzunluk ve checksum vardır (ekrandan, 00:10:00). Başlık 32 bit genişliğinde iki satırdan oluşur:

| Bitler 0-15 | Bitler 16-31 |
|---|---|
| Source port | Destination port |
| UDP length | UDP checksum |

Bir UDP datagramının başına bunların dışında hiçbir şey eklenmez.

- **Source port ve destination port:** Daha önce kuramsal kısımda "transport service access point" (TSAP) olarak geçen kavramın TCP/IP jargonundaki adı porttur. IP başlığında kaynak ve hedef IP adresleri nasıl varsa burada da kaynak ve hedef port numaraları vardır. Her ikisi de 16 bittir, yani 0 ile 65535 arasında değer alabilir. Port, "bu veriyi o host'ta hangi prosesle ilişkilendiriyoruz?" sorusunun cevabıdır. Her prosesin benzersiz bir kimliği vardır ve proses, haberleşmek istediği port numarasıyla ilişkilendirilir. Böylece taşıma katmanı ağ katmanından gelen veriyi hangi prosese vereceğini, bir prosesten geleni de nereye yönlendireceğini bilir.
- **UDP length:** 16 bittir ve başlıkla verinin toplam boyutunu verir. Başlık tek başına 8 bayt olduğundan bu alanın en küçük değeri 8'dir.
- **UDP checksum:** 16 bittir. Hesabı IP başlık checksum'ının hesabıyla aynıdır: bire tümleyen (one's complement) aritmetikle toplanır. Alıcı taraf gelen checksum'ı da hesaba katarak aynı işlemi yapar ve sonucun sıfıra denk gelmesi beklenir. Verinin doğruluğu sizin için önemli değilse checksum hesaplanmayıp 0 bırakılabilir; böyle bir seçenek vardır.

> **Ders sonrası not:** Hoca UDP uzunluğunun en büyük değeri için "2 üzeri 16" dedi. 16 bitlik bir alanın alabileceği en büyük değer $2^{16}-1 = 65535$'tir (python ile doğrulandı).

IP başlığı ile UDP başlığı bir araya geldiğinde checksum'ın nasıl hesaplandığı da slaytlarda yer alır (bu slayt ayrıntılı anlatılmadan geçildi).

> **Hocanın vurgusu:** UDP'nin protokol numarası 17'dir, unutmayın. IP başlığının protokol alanında 17 değeri görülüyorsa taşınan içerik UDP'dir.

### 2.2 Bağlantısızlığın sonuçları

UDP bağlantısız bir taşıma protokolüdür; bunun anlamı oturum (session) mantığının olmamasıdır. Gelip giden paketler birbirine bağlanmaz, çünkü sıra numarası yoktur. Sıra numarası olmadığı için parçalama (fragmentation) da yoktur: bir UDP paketi karşı tarafa tek parça hâlinde gönderilir ve tek parça hâlinde alınır.

IP'nin zaten parçalama ve birleştirme yaptığı söylenebilir; bu doğrudur. Ancak performans ve kullanılabilirlik açısından ideal olan, bir UDP datagramının uzunluğunun alttaki veri bağı ve fiziksel katmanın bir seferde taşıyabileceği en büyük çerçeve boyutuna sığmasıdır. UDP üzerine kurulu üst seviye protokollerin çoğu, işin doğası ve basitlik gereği datagramların parçalanması ve yeniden birleştirilmesiyle uğraşmaz; tek parça gelip gittiklerini varsayar.

Taşıma katmanında konuşulan akış denetimi (flow control), tıkanıklık denetimi (congestion control) ve hata durumunda yeniden gönderim (retransmission) UDP'de yoktur. Bunlardan biri ya da birkaçı gerekiyorsa protokolü tasarlayan kişinin bunları UDP'nin üzerinde gerçekleştirmesi gerekir. RTP ve RPC bu ihtiyaçları UDP üzerinde kendileri karşılayan protokollere örnektir.

### 2.3 UDP ne için kullanılır?

UDP bu işleri yapmıyor diye işe yaramaz değildir. Yalnız bir soru sorup cevabını alacağınız, "bir bakıp çıkacağım" denebilecek durumlar için çok uygundur. En temiz örnek DNS'tir (Domain Name System): bir sunucunun adresini sorarsınız, bir soru bir cevap alırsınız, daha fazlasına ihtiyaç yoktur. Bu tek seferlik iş için UDP biçilmiş kaftandır.

Bu soru-cevap yapısı bir fonksiyon çağrısını da andırır: bir işlem yaparsınız, sonucunu alırsınız. Fonksiyon çağrısı normalde yereldir ama uzak bir sisteme de yapılabilir. Fonksiyona argümanlar tek seferde aktarılır, fonksiyon işini yapar ve bir sonuç döndürür (boyutuna göre değerle ya da referansla). Hem giden argümanlar hem dönen sonuç tek parça hâlinde alınıp verilebildiği için bağlantısız yapı buraya birebir oturur. Bu, bir sonraki konu olan RPC'ye geçişi sağlar.

## 3. RPC (Remote Procedure Call)

### 3.1 Tanım ve stub'lar

Slayt RPC'yi şöyle tanımlar (ekrandan, 00:20:00):

- RPC, ağ üzerindeki uygulamaları tanıdık yordam çağrısı (procedure call) soyutlamasıyla bağlar.
- Stub'lar parametreleri ve sonuçları bir mesaja paketler.
- Yeniden gönderimli UDP (UDP with retransmissions) düşük gecikmeli bir taşımadır.

Klasik (legacy) programlama dillerinde bu yapıya Remote Procedure Call, nesne yönelimli dillerde Remote Method Invocation (RMI) denir. Aralarında fark yoktur; yalnız programlama mantığına göre adları farklıdır.

Amaç, uzak bir sistemde çalışan bir servisi çağırmaktır. Yerel fonksiyon çağrısının argümanları paketlenmeli, ağ üzerinden uzak sisteme gönderilmeli, orada çağrı yapılmalı ve sonuç yine ağ üzerinden geri alınmalıdır. Bir yol, kullanıcıdan ağ programlamayı öğrenmesini, soketi kendisi kurmasını, connect, send, receive çağrılarını kendisinin yazmasını istemek olurdu. Bu durumda program yazan kişi bu ayrıntılarda boğulur, oradaki hatalarla ve performansla uğraşmak zorunda kalırdı; oysa asıl odaklanması gereken kendi programının problemidir. RPC ya da RMI bu yüzden bir soyutlama sağlar.

Slayttaki şekil (ekrandan, 00:20:00) iki makineyi gösterir:

```text
Client CPU                                  Server CPU
+-------------------------+                 +-------------------------+
| Client --(1)--> Client  |                 | Server  <--(5)-- Server |
|                 stub    |                 |                  stub   |
|                  |(2)   |                 |                  ^(4)   |
| Operating system v      |                 | Operating system |      |
+-------------------------+                 +-------------------------+
          |                  (3) Network                  ^
          +-----------------------------------------------+
```

- 1: İstemci, istemci stub'ını sıradan bir fonksiyon gibi çağırır.
- 2: İstemci stub'ı parametreleri bir mesaja paketleyip işletim sistemine verir.
- 3: Mesaj ağ üzerinden sunucu makinesine gider.
- 4: Sunucunun işletim sistemi mesajı sunucu stub'ına verir.
- 5: Sunucu stub'ı parametreleri açar ve sunucudaki asıl fonksiyonu çağırır.

İstemci ve sunucu tarafındaki stub'lar, parametreleri ağ üzerinden aktarılmaya uygun hâle getiren ve ağdan gelen parametreleri yereldeki metoda aktaran kod parçalarıdır. Bunları programcı yazmaz; RPC/RMI paketinde hazır bulunurlar. Kimin nereyi nasıl çağıracağı önceden belirlenmiştir. Programcı yalnız kullanım şablonunu verir: "şu fonksiyon şu parametreleri alır, şunu döndürür" diyen bir tanım dosyası yazılır ve istemci/sunucu kodları bundan üretilir.

### 3.2 RPC'nin zorlukları

İş anlatıldığı kadar kolay değildir. C'nin en güçlü yanlarından biri işaretçilerdir (pointer), ama bir işaretçiyi parametre olarak karşı tarafa göndermek sorundur: yereldeki bir adres karşı tarafta hiçbir şey ifade etmez. Bunun için o adres bölgesindeki verinin olduğu gibi paketlenip önceden gönderilmesi gerekebilir.

İkinci sorun, C'nin "programcı bilir" mantığıyla tasarlanmış olmasıdır: bir işaretçinin gösterdiği bellek alanının nerede bittiği bilinmez, bir sınır (bound) yoktur. Bu yüzden bir dizi geçirilirken yanına dizinin boyutu da geçirilir ki sınır aşılmasın. RPC'de bunun da ele alınması gerekir. Özetle, yereldeki veri görüntüsünü uzaktaki sistemde de oluşturmak RPC yapısının görevidir.

Taşınan veri ne kadar azsa, yani uzak yordam bu tür veri taşımasına ne kadar az ihtiyaç duyarsa, iş o kadar verimli olur. Sürekli veri gidip gelirse taşımada geçen süre artar ve hesaplamayı uzakta yapmanın anlamı kalmaz.

### 3.3 Yeniden gönderimli UDP

Kullanılan ağa göre paketler kaybolabilir ya da bozulabilir; ama "fonksiyonu çağırdım, sonucu gelmedi" diye bir durum kabul edilemez. Bu yüzden yeniden gönderim mekanizması devreye girer: çağrının kullanıcıya şeffaf bir şekilde tekrarlanması ve sonucun alınması gerekir. RPC çoğunlukla güvenilir ve yüksek hızlı ağlarda kullanılır; paket kaybının fazla olduğu, bağlantıların sorunlu olduğu uzak bir sisteme RPC yapmak bu sıkıntıları baştan göze almak demektir.

TCP'de yeniden gönderim için onay ya da zaman aşımı beklenir. UDP üzerinde, yapılan işe bağlı olarak bunu beklemeye bile gerek yoktur. Gerçekleştirilen fonksiyonun tekrar tekrar çalıştırılması sorun yaratmıyorsa cevap gelene kadar aynı isteği hiç beklemeden sürekli yeniden gönderebilirsiniz; böylece kayıp anında kaybedilecek zaman en aza iner. Bunun ağ kullanımı açısından mantıklı olup olmadığı tartışılır, ama seçeneklerden biridir.

## 4. RTP (Real-time Transport Protocol)

### 4.1 RTP hangi katmandadır?

Slayt RTP'yi şöyle tanımlar (ekrandan, 00:30:00): RTP, gerçek zamanlı medyanın UDP üzerinden gönderilmesini destekler ve çoğunlukla uygulamanın bir parçası olarak gerçekleştirilir.

Adı üzerinde RTP bir taşıma protokolüdür; ama ilginç olan, bunu UDP üzerinden sağlamasıdır. Bir protokol başka bir protokolün içindeymiş gibi durur. Bu, veri bağı katmanının içindeki MAC alt katmanına (Medium Access Control Sublayer) benzetilebilir: katman yine veri bağı katmanıdır ama Ethernet gibi yayın (broadcast) ortamlarında alt katman farklı bir konuma gelir. RTP de bir taşıma protokolüdür ama UDP üzerine kurulur.

Bu, UDP için söylenenin birebir örneğidir: UDP'nin yapısından doğan kayıplar, tekrar göndermeler ve hatalara karşı önlem almak isteyen sistem tasarımcısı bunu uygulama seviyesinde yapar. Bu ihtiyaç canlı video konferans ya da isteğe bağlı video akışı (on demand video streaming) gibi pek çok uygulamada sürekli doğuyorsa ortak bir protokol olarak karşımıza çıkar; RTP bunlardan biridir.

### 4.2 Katman yapısı ve kapsülleme

Slayttaki sol şekil katmanları gösterir (ekrandan, 00:30:00):

| Alan | Katman |
|---|---|
| User space | Multimedia application |
| User space | RTP |
| (arayüz) | Socket interface |
| OS Kernel | UDP |
| OS Kernel | IP |
| OS Kernel | Ethernet |

RTP kullanıcı alanında (user space) bir kütüphanedir, çekirdekte (kernel) değildir; UDP ise TCP ile birlikte çekirdektedir. RTP'yi bir yardımcı uygulama (helper application) gibi düşünmek gerekir: normalde kendimizin yapmak zorunda kalacağı işleri hazır yapan, çağrılabilen bir kütüphanedir.

Sağdaki şekil kapsüllemeyi gösterir:

```text
| Ethernet header | IP header | UDP header | RTP header | RTP payload |
                              |<---------- UDP payload ------------>|
                  |<------------------ IP payload ---------------->|
                  |<--------------- Ethernet payload ------------->|
```

Multimedya uygulamasından çıkan her şey, RTP kütüphanesindeki ilgili fonksiyonlar çağrılarak RTP yüküne (payload) dönüştürülür, önüne RTP başlığı gelir, ardından soket arayüzü üzerinden UDP ile karşı tarafa gönderilir. Ağ düzgün çalışıyorsa paketler yeniden gönderim olmadan, kayıpsız, akarcasına gider. RTP katmanının devreye girdiği ve hayatı kolaylaştırdığı yer hata, gecikme ve kayıp anlarıdır.

### 4.3 RTP başlığı

Slayt: "RTP başlığı medyanın türünü tanımlayan ve onu birden fazla akış boyunca senkronize eden alanlar içerir; RTCP kardeş protokolü yönetim işlerine yardım eder" (ekrandan, 00:35:00). Başlık 32 bit genişliğindedir:

| Satır | Alanlar |
|---|---|
| 1 | Ver. \| P \| X \| CC \| M \| Payload type \| Sequence number |
| 2 | Timestamp |
| 3 | Synchronization source identifier |
| 4 ve sonrası (kesikli, isteğe bağlı) | Contributing source identifier |

Hocanın en önemli bulduğu iki alan sıra numarası (sequence number) ve zaman damgasıdır (timestamp). UDP bağlantısız olduğu için oturum seviyesinde bir sıralama ya da bütünlük yoktur; her UDP datagramı kendi başına bir şeydir. Datagramları ilişkilendirmek için sıra numarası gerekir; RTP başlığında sıra numarası 16 bittir, yani 65535'e kadar gider.

İkinci hoca buna şunu ekler: sıra numarasını senkronizasyon kaynak tanımlayıcısıyla (synchronization source identifier) ve CC ile birlikte düşünmek gerekir. RTP'nin yapmaya çalıştığı, farklı kaynaklardan gelen birden fazla multimedya akışını (bir yerden görüntü, bir yerden ses, başka bir yerden başka bir görüntü) tek bir UDP akışına çevirmektir. Bu yüzden bir paketin hangi kaynaktan ve hangi akıştan geldiği bilinmelidir; bir kaynaktan birden fazla akış da gelebilir. Sıra numarası ise o akış içinde paketin hangi parça olduğunu söyler. İş bu üçlüyle döner.

Zaman damgası da önemlidir: senkronizasyonu sağlayan kaynak ile alıcı arasındaki zaman kayması çok büyürse bir yerde sıfırlama yapılıp "buradan itibaren devam ediyorum" denebilmesi gerekir. Zaman damgası aynı zamanda jitter'la baş etmekte de kullanılır. Jitter, gecikmenin ortalama değerinden sapmasıdır (azalma ya da artma yönünde oynaması); gecikmenin varyansındaki oynama doğrudan jitter olarak görülür.

Diğer alanlar sırasıyla şöyle açıklandı:

- **Ver. (versiyon):** Protokolün farklı sürümleri olursa iki tarafın anlaşabilmesi ve başlığı doğru yorumlayabilmesi için.
- **P (padding):** Paketi 32 bitin katına tamamlamak için dolgu yapılıp yapılmadığını söyler. Yükte eksik varsa dolgu eklenir.
- **X (extension):** Başlıkta ek bir uzantı başlığı olup olmadığını gösterir.
- **CC:** Bu akışa kaç kaynağın katkıda bulunduğunu söyler.
- **M (marker):** Anlamı payload type ve uygulama tarafından belirlenir. Örneğin videoda bir anahtar karenin (key frame) başlangıcını, ses kaydında her saniyenin başını işaretleyebilir; uygulamaya özgüdür.
- **Sequence number, timestamp, synchronization source identifier:** Yukarıda açıklandı.
- **Contributing source identifier:** Üretilen akış karıştırılmış (mix) bir akışsa ona katkıda bulunan kaynakları gösterir. Senkronizasyon, senkronizasyon kaynak tanımlayıcısına göre yapılır; diğer kaynaklar onun senkronuyla birlikte ilerler.

> **Ek bilgi (derste anlatılmadı):** Sabit RTP başlığında alan genişlikleri büyük olasılıkla şöyledir: Ver. 2 bit, P 1 bit, X 1 bit, CC 4 bit, M 1 bit, Payload type 7 bit, Sequence number 16 bit; timestamp, SSRC ve her CSRC 32 bittir.

### 4.4 RTCP

RTP başlığıyla birlikte RTCP kullanılır.

> **Hocanın vurgusu:** RTCP'nin içindeki "TCP"nin Transmission Control Protocol ile hiçbir ilgisi yoktur; bu, sorularda kafa karıştırabilir. RTCP, real-time transport'un kontrol protokolüdür (Real-time Transport Control Protocol).

Akışı başlatabilmek, akışta kesinti, gecikme ya da jitter olduğunda müdahale edebilmek için kaynak ile hedef arasında kontrol mesajlaşması gerekir. Bu mesajlaşma doğal olarak içerikle aynı yapı üzerinden akar; yani dersin başında konuşulan bant içi (in-band) ve bant dışı (out of band) kontrol ayrımında bu bir bant içi kontroldür. Kontrol, başlıktaki alanlar üzerinden sağlanır.

## 5. Jitter ve Oynatma Tamponu

### 5.1 Sabit hızla çıkış, değişken hızla varış

Hizmet kalitesi (Quality of Service) konusunda constant rate, variable rate ve available rate ayrımı yapılmıştı. Burada önemli olan, işi sabit hız ile değişken hız arasında yönetebilmektir. Multimedya için gereken sabit hızdır: saniyede 25 ya da 30 kare dendiğinde bir periyot tanımlanır ve bu periyot bozulmamalıdır.

Slayt: "Alıcıdaki tampon, paketleri geciktirmek ve jitter'ı söndürmek için kullanılır; böylece akan medya düzgün oynatılır" (ekrandan, 00:40:00). Şekilde üç satır ve saniye cinsinden bir zaman ekseni (0-20 s) vardır:

| Satır | Açıklama |
|---|---|
| Packet departs source (Constant rate) | 1-8 numaralı paketler eşit aralıklarla, yaklaşık 0-8. saniyeler arasında çıkar |
| Packet arrives at buffer (Variable rate) | 1, 2, 3, 4, 5, 6, 7, 8 düzensiz aralıklarla gelir; 3-4-5 art arda, 6 ve 7 seyrek, 8 çok geç (yaklaşık 18. saniye) |
| Packet removed from buffer (Constant rate) | "Time in buffer" süresi sonunda (yaklaşık 10. saniyeden itibaren) 1-7 eşit aralıklarla oynatılır; 8 kesikli çizilmiştir |

Şekilde 8 numaralı paket için "Packet 8's network delay is too large for buffer to help" (8. paketin ağ gecikmesi tamponun yardım edemeyeceği kadar büyük) ve oynatmada "Gap in playback" notları vardır.

Kaynakta işlemci, bellek ya da disk G/Ç'siyle ilgili özel bir sorun yoksa kaynak paketleri doğal olarak eşit zaman aralıklarıyla çıkarır. Ama ağ bu paketlere farklı gecikmeler uygular: birinci paket ikincinin çıkış sırasında, ikinci paket dördüncünün çıkış sırasında gelir; sonra 3, 4, 5 neredeyse çıkış zamanlarına denk gelecek şekilde gelir. Gecikmeler arasındaki bu farklar ve farkların sonradan kaybolması jitter'ı gösterir.

Paketler hedefte geldikleri anda oynatılırsa görüntüde duraksama ve bozulma, seste garip durumlar olur. Ayrıca medya bir kodlayıcıdan (codec) geçer; kodlanmış akışın belli bir sıra ve düzende çözülmesi gerekir. Aksi hâlde cep telefonu konuşmalarında duyulan "vıç vıç" gibi sesler oluşur; parçalar bağımsız değerlendirilemez, çünkü kodlama akış biçimindedir.

### 5.2 Tamponun sınırı

Hedef tarafta bir tampon mekanizması vardır. Tampon sonsuz boyutta değildir ve zaman açısından da bir üst sınırı, geçerlilik süresi olmalıdır. Burada hizmet kalitesinde konuşulan ayrım önemlidir:

- **Kayıttan oynatma (playback):** Bir video sitesinde ya da film izlerken kaynak bekleyebilir, durabilir; tamponda istenildiği kadar veri tutulabilir. En kötü durumda hizmet kalitesi düşer ve kullanıcı memnun olmaz.
- **Gerçek zamanlı yayın:** Biri televizyonda canlı açıklama yapıyorsa ve bu son kullanıcıya izletiliyorsa bir karenin geçerliliği bir önceki ve bir sonraki kare arasındaki süre kadardır. Kareleri biriktirip on tanesi toplandıktan sonra oynatmanın anlamı yoktur; o sırada konuşmacı bambaşka bir şey anlatıyor olur.

Tampon her durumda gereklidir ama boyutu (derinliği) duruma göre değişir. Var olma sebebi jitter'ı emmek, söndürmektir; böylece hedefte paketler eşit aralıklarla geliyormuş gibi düzgün oynatılır.

Örnekte 8 numaralı paketin gecikmesi tamponun zaman olarak emebileceği sınırın dışındadır. 1'den 7'ye kadar kareler kesintisiz oynarken 7'den 8'e geçişte bir boşluk (gap in playback) oluşur. RTP bu boşlukları yüzde yüz çözmekle yükümlü değildir, ama en aza indirmeli ve durumu kolaylaştırmalıdır. Özetle: paketler kaynaktan sabit hızla çıkar, ağ yüzünden değişken hızla ulaşır, ama yeniden sabit hızla oynatılabilmeleri gerekir.

### 5.3 Yüksek ve düşük jitter

Slayt: "Yüksek jitter, yani gecikmede daha çok değişkenlik, oynatma kaçırmalarını önlemek için daha büyük bir oynatma tamponu gerektirir; yayılma gecikmesi tampon boyutunu etkilemez" (ekrandan, 00:45:00). İki grafik vardır; ikisinde de dikey eksen "Fraction of packets", yatay eksen "Delay"dir:

- Sol grafik (yüksek jitter): Eğri en küçük gecikmeden (Minimum delay, ışık hızından kaynaklanan) başlar, bir tepe yapar ve uzun bir kuyrukla iner. "High jitter" geniş bir aralık olarak işaretlenmiştir. Pembe ile çizilmiş "Buffer" aralığı en küçük gecikmeden kuyruğun bir noktasına kadar uzanır; kuyruğun bu noktadan sonraki kısmı "Misses" olarak çember içine alınmıştır.
- Sağ grafik (düşük jitter): Çok dar ve dik bir tepe vardır; "Low jitter" dar bir aralıktır.

İki durumda da en küçük gecikme neredeyse aynıdır. Düşük jitter'da gecikmeler büyük oranda bir noktada toplanmıştır; ortalamadan sapma vardır ama azdır, bu yüzden küçük bir tamponla iş büyük ihtimalle çözülür. Yüksek jitter'da dağılım geniştir: çok sayıda paket çok farklı gecikmelerle gelir ve bunu emmek kolay değildir.

Bu, jitter'la baş etmek için RTP başlığındaki zaman damgası ile paketin geliş zamanının birlikte kullanılıp jitter'ın gözlemlenmesi ve tamponun jitter'ın seviyesine göre ayarlanması gerektiğini gösterir. Yine de sol örnekte tampon bir yere kadar ayarlanabilir; ondan sonrası kaçırılır (miss). Kaçırma, yeniden senkronizasyon gerektirir; bunu yaparken RTP başlığındaki zaman damgası ve sıra numarası kullanılır ve akış bir noktadan yeniden başlatılarak devam eder.

## 6. TCP Hizmet Modeli

### 6.1 Güvenilmez ağ üzerinde güvenilir hizmet

UDP ve onun üzerine kurulu RTP'den sonra TCP'ye geçilir. TCP bağlantı yönelimli bir taşıma protokolüdür. Amacı, altta güvenilir olmayan (unreliable) bir ağ katmanı varken onun üzerinde güvenilir bir hizmet sağlamaktır.

Altta farklı özellik ve yapıda ağlar vardır (internetworking). Bunları birleştirip aralarında haberleşme kurmanın bir yolu, işi olabildiğince esnek ve rahat yapmaktır; bu yüzden IP katmanında güvenilirlik gibi konulara fazla takılınmaz. Tasarımda bir sorunu bazen bir üst katmanda çözmek çok daha makuldür. TCP/IP'de yapılan da güvenilmez IP üzerinde güvenilir bir TCP hizmeti kurmaktır.

TCP kısmında hizmet modeli, segment başlığı, bağlantı kurulumu ve durum modeli, akış denetimi için kayan pencere (sliding window), kayan pencere yüzünden gereken zamanlayıcı sistemi ve tıkanıklık denetimi konuşulur.

### 6.2 Portlar ve iyi bilinen servisler

Taşıma katmanında bir haberleşme adresine ihtiyaç vardır; bunun için port kullanılır. Portlar üzerinden haberleşmek için API'ler sağlanır; bunlara soket denir. $2^{16}$ port vardır ve bunların bir kısmı belli işlere ayrılmıştır. İlk 1024 port (0-1023) iyi bilinen (well-known) portlardır; hangi portun hangi servise atandığı IANA'nın sitesinden görülebilir.

Bu atamalar tarihsel olarak oluşmuş kararlardır. Örneğin Microsoft'un uzak masaüstü (Remote Desktop) servisi çok bilinen bir servistir ama iyi bilinen port aralığında değildir; tuhaf bir port kullanır. Bu yüzden bir sunucu geliştirirken 1024'ün altında olmak zorunda değilsiniz.

> **Ders sonrası not:** Hoca Remote Desktop portunu "3386 değil, 3383 mü? 3383" diye söyledi; Microsoft Remote Desktop büyük olasılıkla 3389 numaralı TCP portunu kullanır.

Slayttaki iyi bilinen portlar tablosu (ekrandan, 00:50:00), "TCP, prosesler arasında uygulamalara güvenilir bir bayt akışı sağlar; İnternet'in beygiridir. Popüler sunucular iyi bilinen portlarda çalışır" başlığı altında:

| Port | Protokol | Kullanım |
|---|---|---|
| 20, 21 | FTP | File transfer |
| 22 | SSH | Remote login, replacement for Telnet |
| 25 | SMTP | Email |
| 80 | HTTP | World Wide Web |
| 110 | POP-3 | Remote email access |
| 143 | IMAP | Remote email access |
| 443 | HTTPS | Secure Web (HTTP over SSL/TLS) |
| 543 | RTSP | Media player control |
| 631 | IPP | Printer sharing |

Hocanın açıklamaları:

- **FTP (20, 21):** İki port vardır: biri veri, biri kontrol. Kontrol bilgisi bant dışı (out of band) gider: kontrol kanalında bağlantı kurulur, oturum açılır, örneğin dizin listeleme komutu gönderilir; cevap veri kanalından gelir.
- **SSH:** Bir sisteme uzaktan bağlanıp komut çalıştırmak için kullanılır.
- **SMTP (25):** Simple Mail Transfer Protocol.
- **POP3 (110) ve IMAP (143):** Posta erişimi için kullanılır; günümüzde POP3 yerine çoğunlukla IMAP kullanılır.
- **HTTP (80):** Tarayıcı, karşı makinenin 80 numaralı portunda çalışan web sunucusuyla konuşur; bu port açıkça yazılmaz. Farklı bir portta çalışan bir servis varsa adresin sonuna iki nokta ve port numarası (örneğin 8080) yazılır. <!-- BELİRSİZ: Hocanın örnek verdiği ikinci port altyazıda "8043" olarak geçiyor; büyük olasılıkla 8443 kastedildi. -->
- **HTTPS (443):** Güvenli HTTP haberleşmesi; adres başına HTTPS yazıldığında port bu adreslemeyle çözülür.
- **RTSP:** Daha önce konuşulan akış (streaming) protokolleriyle ilgilidir.
- **IPP (631):** Ağ yeteneği olan bir yazıcıyı ya da bir bilgisayara bağlı yazıcıyı paylaşmak için kullanılan port.

### 6.3 Bayt akışı

TCP'nin asıl derdi, kesintisiz, hatasız ve temiz bir bayt akışı oluşturmaktır. Bu, dosyalara karakter, satır ya da tampon bazında erişmeye (character I/O, line I/O, buffer I/O) benzetilir. En verimlisi tampon tampon erişmektir, ama uygulama gereği bazen karakter karakter erişmek gerekir. TCP'nin amacı, yerelde sahip olunan bu esnekliği araya ağ katmanı girse bile uzak sistemler arasında sağlamaktır. Performans açısından çok kötü olsa da TCP ile uzaktaki bir uygulamadan tek bir bayt okunabilir. Bu, karşıdan tek bayt geldiği anlamına gelmez; belki daha fazlası gelmiştir ama tamponda bekleyenden yalnız bir bayt okunur. Çözünürlük bayttır.

Slayt (ekrandan, 00:55:00): "TCP kullanan uygulamalar yalnız bayt akışını [sağda] görür, ayrı IP paketleri olarak gönderilen segmentleri [solda] görmez." Solda her biri IP başlığı ve TCP başlığı taşıyan dört segment (A, B, C, D) vardır; altta "her biri 512 bayt veri taşıyan ve bir IP paketinde giden dört segment" yazar. Sağda "A B C D" tek bir kutudadır; altta "tek bir READ çağrısıyla uygulamaya teslim edilen 2048 bayt veri" yazar.

Segmentlerin 512'şer bayt olması yalnız anlaşılsın diyedir; 500, 256 ya da 1000 gibi farklı boyutlarda da olabilirlerdi. Her birinde bir IP başlığı ve bir TCP başlığı vardır. Hedefe ulaştıklarında A, B, C, D tek bir bütün olur; uygulama bunu tek bir 2048 baytlık parça olarak da okuyabilir, bayt bayt da okuyabilir.

> **Hocanın vurgusu:** Bunu hiçbir zaman unutmayın: TCP birbirinden uzak uygulamalar arasında, sanki aynı sistemdeymiş gibi bayt çözünürlüğünde bir akış (byte stream) oluşturur. Temeli budur.

## 7. TCP Segment Başlığı

### 7.1 Alanlar

Slayt: "TCP başlığı adresleme (portlar), kayan pencere (sıra/onay numarası), akış denetimi (pencere), hata denetimi (checksum) ve daha fazlasını içerir" (ekrandan, 01:00:00). Başlık 32 bit genişliğindedir:

| Satır | Alanlar |
|---|---|
| 1 | Source port \| Destination port |
| 2 | Sequence number |
| 3 | Acknowledgement number |
| 4 | TCP header length \| (kullanılmayan, gri alan) \| CWR \| ECE \| URG \| ACK \| PSH \| RST \| SYN \| FIN \| Window size |
| 5 | Checksum \| Urgent pointer |
| 6 ve sonrası | Options (0 or more 32-bit words) |
| sonra | Data (optional) |

- **Source port, destination port:** UDP'de olduğu gibi başlık bunlarla başlar; X host'undaki hangi uygulamadan Y host'undaki hangi uygulamaya bilgi gideceğini belirler.
- **Sequence number ve acknowledgement number:** UDP'de yoktu; gerekirse üstte eklenmeleri gerekiyordu (RTP'de olduğu gibi). TCP'de sıra numarası ve son alınan parçanın onaylandığı numara başlığın parçasıdır. Bu sayede sıra, neyin alındığı ve neyin beklendiği takip edilir.
- **TCP header length:** 4 bittir. IP başlığında olduğu gibi buradaki değer 4 ile çarpılarak bayt cinsinden uzunluk bulunur, çünkü TCP başlığı da 32 bitlik (4 baytlık) sınırlara oturtulmuştur.
- **Window size:** 16 bittir; bayraklardan hemen sonra gelir (7.3'te).
- **Checksum:** 16 bittir.
- **Urgent pointer:** URG bayrağıyla birlikte kullanılır (7.2'de).
- **Options:** Adı üzerinde isteğe bağlıdır; "0 ya da daha fazla 32 bitlik kelime" yazdığı için hiç olmayabilir.

> **Hocanın vurgusu:** Sıra numarası ve onay numarası "kesinlikle çok çok önemli"dir; sıranın takibi bunlarla yapılır.

> **Ek bilgi (derste anlatılmadı):** Başlık uzunluğu alanı 4 bit olduğu için en büyük değeri 15'tir; $15 \times 4 = 60$, yani TCP başlığı en çok 60 bayttır. Seçeneksiz başlık 5 kelime, yani 20 bayttır (python ile doğrulandı). CWR (Congestion Window Reduced) ve ECE (ECN-Echo) bayrakları büyük olasılıkla açık tıkanıklık bildirimi (Explicit Congestion Notification) için kullanılır.

### 7.2 Bayraklar

İlk iki bayrak (CWR ve ECE) tıkanıklıkla ilgilidir ve tıkanıklık konusunda konuşulacağı söylendi.

**URG ve urgent pointer.** Bir uzak terminal düşünün: terminal ağ üzerinden asıl sisteme bağlıdır ve içinde binlerce dosya olan bir dizindeki dosyaların adlarını, sahiplerini, son erişim zamanlarını ve boyutlarını listeliyorsunuz (Unix'te `ls -l` gibi). Liste ekrana durmadan akar. Bir noktada görmek istediğinizi görür ve durdurmak istersiniz; Ctrl-C'ye basarsınız. Karşıdan size gelen bir bütün (bir akış) vardır, ama sizin bastığınız Ctrl-C'nin bu akıştan önce karşıya gidip işlenmesi ve sonucunun (akışı kesme) gelmesi gerekir. Yerelde bu işletim sistemine bir kesme, bir sinyal olarak giderdi. Ağ üzerinden bunu yapmanın yolu paketteki URG bitinin set edilmesi ve urgent pointer'ın Ctrl-C verisini gösterecek şekilde ayarlanmasıdır. Karşı taraf bu paketin diğerlerinden öncelikli olduğunu anlar ve önce onu işler; o anda akışın bütünlüğü önemli değildir. Buna bazen hızlandırılmış hizmet (expedited) de denir; kargo şirketlerinin öncelikli gönderilerine benzer.

**PSH (push).** Uygulamadan gelen veri her zaman hemen parçalara bölünüp aşağı indirilmez; bir segmenti dolduracak kadar birikmediği sürece tamponda bekletilir. Alıcı tarafta da veri bir tampona girip tampon belli bir boyuta gelince yukarı aktarılabilir. Bu gecikmeye yol açar. Gecikme istenmiyorsa, verinin bir an önce uygulamaya ulaşması gerekiyorsa PSH bayrağı set edilir. Karşıdaki TCP bunu görünce paketi bekletmeden, tamponlamadan doğrudan uygulamaya verir.

URG ve PSH aciliyeti çözmek için konmuş mekanizmalardır, ama günümüzde ikisi de doğrudan pek kullanılmaz. URG'nin gerçekleştirimi farklı cihazlarda ve işletim sistemlerinde farklı yorumlanabildiği için ne olacağı net değildir; kullanılmaması önerilir. Alternatif olarak PSH kullanılabilir, ama birçok API bunun yerine TCP_NODELAY gibi seçenekler sunar.

**ACK.** Segmentin içinde bir onay olup olmadığını söyler; 0 ise segmentte onay yoktur. Bu, daha önce konuşulan "piggyback" mantığıdır: size bir paket gelir, siz ona bir cevap gönderirken gelen paketi aldığınızın onayını da bu cevabın içine gömersiniz.

**RST (reset).** Bir bağlantıda sorun, karşılıklı anlaşamama durumu oluştuysa bağlantıyı sıfırlamak için kullanılır. Bunun sebebi aradaki yönlendiricilerden birinin gitmesi, makinelerden birinin kendini yeniden başlatması, ilgili taşıma uç noktasının açık olmaması ya da bağlantının kabul edilmek istenmemesi olabilir.

**SYN ve FIN.** SYN "synchronize" kelimesinden gelir ve bağlantı isteği için, FIN "finish" kelimesinden gelir ve bağlantıyı sonlandırmak için kullanılır.

### 7.3 Pencere boyutu

Önceki derste A'dan B'ye veri akışı bir senaryo üzerinden anlatılmıştı: A tarafı 8 slot isterken B "şu anda en fazla 4 slot verebilirim" diyordu; yani bir taraf 8'lik pencere istiyor, diğeri 4'lük pencere veriyordu. A bu 4'lük pencereyi 0, 1, 2, 3 diye dolduruyordu; B tarafındaki uygulama veriyi çektikçe B'den A'ya onay gidiyor ve A boşalan yerlere yeniden gönderebiliyordu. Orada bir kilitlenme (deadlock) senaryosu da ele alınmış, bunu önlemek için zamanlayıcılara ihtiyaç olduğu söylenmişti. Kuramsal olarak görülen bu pencere yapısı burada pratikte 16 bitlik window size alanı olarak karşımıza çıkar. Bu alan alıcı ile verici arasında akışı düzenler: alıcının alamayacağı miktarda veri gönderilirse alıcı ezilir, çünkü buna yetecek tamponu olmayabilir.

### 7.4 Verisiz segmentler

TCP başlığı her segmentte olmak zorundadır, ama arkasında veri olmayabilir. Örneğin uygulama tamponda bekleyen verinin push edilmesini istediğinde ek veri gerekmez, bu PSH ile ifade edilir. Bağlantı başlatılırken yalnız sıra numarasının gitmesi yeterlidir; reset durumunda da veri gitmez.

Özetle slayttaki başlık cümlesi doğrulanmış olur: TCP başlığı adresleme ve çoğullama, kayan pencere, aldım/verdim (onay), akış ve hata denetimiyle ilgili bilgileri içerir.

## 8. TCP Bağlantı Kurulumu

### 8.1 Üç yönlü el sıkışma

Slayt: "TCP bağlantıları üç yönlü el sıkışmayla (three-way handshake) kurar; sonlandırma, daha önce anlatıldığı gibi simetriktir" (ekrandan, 01:10:00).

İstemci sunucuya "gel aramızda senkronize olalım" der; senkronizasyon, sıra numaralarının karşılıklı değiş tokuşudur. Hocanın canlandırması şöyledir: bir hoca diğerine "benim sıra numaram 5" der; öteki "anladım, benim sıra numaram da 7" der; ilki "tamam, seninki 7" diye karşılık verir. Bundan sonra biri 6, 7, 8 diye gönderirken, diğeri de 8, 9, 10 diye gönderir ve iki taraf karşıdan gelecek paketlerin sırasını takip edebilir.

Slayttaki normal durum (Normal case):

```text
Host 1                                   Host 2
  |---- SYN (SEQ = x) ------------------->|
  |<--- SYN (SEQ = y, ACK = x + 1) -------|
  |---- (SEQ = x + 1, ACK = y + 1) ------>|
```

Kuram ile pratik arasında bir fark vardır: kuramsal anlatımda en son alınan onaylanıyordu, gerçek hayatta ise beklenen bir sonraki numara gönderilir. İstemci sırasını x olarak gönderir, onay x+1 olarak döner; sunucu sırasını y olarak gönderir, istemci onayı y+1 olarak gönderir.

### 8.2 Eş zamanlı bağlantı

Solda bir taraf istemci, öteki yalnız sunucu gibi davranır; ama iki taraf aynı anda hem istemci hem sunucu olarak birbirine bağlantı açabilir (Simultaneous connect):

```text
Host 1                                   Host 2
  |---- SYN (SEQ = x) ---------->         |
  |         <---------- SYN (SEQ = y) ----|
  |<--- SYN (SEQ = y, ACK = x + 1) -------|
  |---- SYN (SEQ = x, ACK = y + 1) ------>|
```

**Soru:** İki taraf birbiriyle bağlantı kurduğuna göre, her bağlantı için üç yönlü el sıkışma gerektiğinden 6 mesaj mı gerekir? **Cevap:** Hayır. Bu açılış aynı zaman diliminde gerçekleştiği ve sıra numaralarıyla onaylar karşılıklı değiş tokuş edildiği için 4 mesaj yeter; eş zamanlı, karşılıklı bağlantı özel bir durumdur. Ama host 1 host 2'ye bağlantı kurduktan sonra host 2 ayrıca host 1'e bağlantı kuracaksa üç mesajlık bir el sıkışma daha gerekir; o durumda toplam 6 mesaj olur.

Bağlantı kurulumuna yapılabilecek SYN saldırısı gibi saldırıların ayrıntısının güvenlik konusunun kapsamında olduğu belirtildi.

## 9. TCP Durum Makinesi ve Bağlantı Sonlandırma

### 9.1 Durumlar

Basit taşıma protokolü daha önce birkaç durumlu (4 ya da 5) bir durum makinesiyle anlatılmıştı. TCP basit değildir; daha karmaşıktır ve 11 durumu vardır. Slayt: "TCP bağlantısının sonlu durum makinesinde önceki basit örneğimizden daha çok durum vardır" (ekrandan, 01:15:00).

| Durum | Açıklama |
|---|---|
| CLOSED | No connection is active or pending |
| LISTEN | The server is waiting for an incoming call |
| SYN RCVD | A connection request has arrived; wait for ACK |
| SYN SENT | The application has started to open a connection |
| ESTABLISHED | The normal data transfer state |
| FIN WAIT 1 | The application has said it is finished |
| FIN WAIT 2 | The other side has agreed to release |
| TIME WAIT | Wait for all packets to die off |
| CLOSING | Both sides have tried to close simultaneously |
| CLOSE WAIT | The other side has initiated a release |
| LAST ACK | Wait for all packets to die off |

CLOSED durumu, ne aktif bir bağlantının ne de gönderilmiş ya da beklenen bir bağlantı isteğinin olduğu durumdur.

### 9.2 Bağlantının sonlandırılması

Slaytlarda sonlandırma (connection release) ayrıca verilmediği için durum modeli konuşulurken sonlandırmanın nasıl olduğu da anlatıldı. Bir bağlantı yapı olarak tam çift yönlüdür (full duplex): bir taraf gönderirken öteki de gönderebilir. TCP gerçekleştiriminde ise bu, iki ayrı simplex gibi düşünülür: A'dan B'ye bir simplex, B'den A'ya bir simplex. Bunlar birbirinden ayrı sonlandırılabilir: A artık B'ye bilgi göndermeyecekse bu yön kapatılır ama B'den A'ya bilgi gelmeye devam edebilir.

Bir taraf bağlantıyı kapatmak istediğini FIN paketiyle bildirir. FIN gönderen taraf, karşının bu isteği aldığını ve kabul ettiğini bilmek için bir ACK görmek ister. Öteki yön için de karşı taraf bir FIN gönderirse buna da bir ACK gelmelidir.

Ağdaki hatalar ve sorunlar kontrol paketlerine uygulanmaz diye bir istisna yoktur. Veri paketi nasıl bozulup kaybolabiliyorsa gönderilen FIN ya da ACK paketi de bozulabilir, kaybolabilir. FIN gönderildi ama karşıdan hiç ACK gelmezse belli bir süre beklenmesi gerekir. Durum makinesindeki FIN WAIT 1 ve FIN WAIT 2 gibi durumlar bu anlaşma sırasında oluşan bekleme durumlarıdır.

Akış şöyledir: istemci sunucuya FIN biti set edilmiş bir bağlantı kesme isteği (disconnect request) gönderir ve "işimi bitirdim" diyerek FIN WAIT 1'e girer. Önceki derste konuşulduğu gibi karşı taraf da isteği görünce "ben de işimi bitirdim" diye kendi isteğini gönderir. Bir mesaja daha ihtiyaç vardır: "senden gelen isteği de aldım, artık bağlantıyı kapatabiliriz."

<!-- BELİRSİZ: Altyazıda hoca bu noktada "Server FinWait 2'ye giriyor" diyor; slayttaki durum makinesine göre FIN WAIT 2, ilk FIN'i gönderen (aktif kapatan) tarafın durumudur, pasif kapatan taraf CLOSE WAIT ve LAST ACK durumlarından geçer. -->

Unutulmaması gereken şudur: mantıksal olarak bağlantı kapansa da ağda paketler gelmeye devam edebilir. En son çıkan paketin en son geleceği diye bir kural yoktur; bağlantısız, büyük ağlarda önce çıkan paketler sonra gelebilir. Bir veri merkezinin içindeki ağda bunun olasılığı yok denecek kadar düşüktür, ama İnternet'in coğrafi yapısı ve mesafeler düşünüldüğünde karşılaşılabilir. Bu yüzden TIME WAIT ("Wait for all packets to die off") durumunda bütün paketlerin gelmesi için bir süre daha beklenir. Bu gecikmiş paketler için onay vb. yönetmeye gerek yoktur; yalnız gelirler. Ağda bir felaket olup bunların hiç ulaşmaması da mümkün olduğundan bekleme sonsuz değildir, bir zaman aşımına bağlıdır.

Bu zaman aşımı değerleri günümüzdeki standart TCP/IP gerçekleştirimlerinde hâlâ ilk zamanlardaki ağ altyapısına (o zamanki bant genişliği ve gecikmelere) göre belirlenmiş değerlerdir; özellikle değiştirilmediği sürece sunucu sistemlerinde de öyle kalır. Hoca TIME WAIT için 180 saniye örneğini verdi: mantıksal olarak kapanmış bir bağlantıya ait bir paket üç dakika içinde gelebilir ve buna şaşırmamak gerekir.

> **Ders sonrası not:** Hoca TIME WAIT süresi için 180 saniye dedi. Özgün TCP tanımında bu süre büyük olasılıkla iki en uzun segment ömrü (2 × MSL) kadardır ve gerçekleştirmeye göre değişir (bazı sistemlerde 60 saniye, bazılarında 2-4 dakika).

### 9.3 Saldırı yüzeyi

Bu bekleme süreleri üzerinden bir servisi işlevsiz hâle getirmeye yönelik saldırılar yapılabilir:

- **SYN saldırısı:** Birine sürekli SYN gönderip bağlantı başlatmak. Bir yerden sonra karşı tarafın açabileceği bağlantı sayısı bloke edilir.
- **Kurup kullanmamak:** Bağlantıyı kurup sonra hiçbir şey göndermemek. FIN karşıya ulaşmazsa karşı taraf hattı izler ve bilgi gelmediğini görünce bir süre sonra kapatır; saldırgan sürekli bağlantı açıp kullanmayarak karşının kaynaklarını tüketir.
- **TIME WAIT penceresi:** Kapanmış bir bağlantıya ait gecikmiş paketler bir süre kabul edildiği için bu süre saldırganlara bir zaman penceresi tanır.

### 9.4 Durum diyagramı

Slayttaki diyagramın yanındaki açıklamalar (ekrandan, 01:20:00):

- Düz çizgi bir istemcinin normal yoludur.
- Kesikli çizgi bir sunucunun normal yoludur.
- Açık renkli çizgiler olağan dışı olaylardır.
- Geçişler "sebep/eylem" biçiminde, eğik çizgiyle ayrılarak etiketlenmiştir.

Diyagramın metne dökülmüş hâli:

```text
Kurulum
  CLOSED --CONNECT/SYN (3 yönlü el sıkışmanın 1. adımı)--> SYN SENT
  CLOSED --LISTEN/- --> LISTEN ;  LISTEN --CLOSE/- --> CLOSED
  LISTEN --SYN/SYN + ACK (2. adım)--> SYN RCVD
  LISTEN --SEND/SYN--> SYN SENT
  SYN SENT --SYN/SYN + ACK (eş zamanlı açılış)--> SYN RCVD
  SYN SENT --CLOSE/- --> CLOSED
  SYN RCVD --RST/- --> LISTEN
  SYN RCVD --ACK/- --> ESTABLISHED
  SYN SENT --SYN + ACK/ACK (3. adım)--> ESTABLISHED
  SYN RCVD --CLOSE/FIN--> FIN WAIT 1

Aktif kapatma
  ESTABLISHED --CLOSE/FIN--> FIN WAIT 1
  FIN WAIT 1 --ACK/- --> FIN WAIT 2
  FIN WAIT 1 --FIN/ACK--> CLOSING
  FIN WAIT 1 --FIN + ACK/ACK--> TIME WAIT
  FIN WAIT 2 --FIN/ACK--> TIME WAIT
  CLOSING --ACK/- --> TIME WAIT
  TIME WAIT --(Timeout)/ --> CLOSED (başa dön)

Pasif kapatma
  ESTABLISHED --FIN/ACK--> CLOSE WAIT
  CLOSE WAIT --CLOSE/FIN--> LAST ACK
  LAST ACK --ACK/- --> CLOSED
```

Slaytların siyah beyaz hazırlanması yüzünden açık renkli (olağan dışı) geçişlerin dikkatle incelenmesi gerektiği belirtildi. Bağlantı kurulumu için basit protokoldekine benzer durumlar vardır (SYN SENT, SYN RCVD, oradan ESTABLISHED); ama sonlandırma tarafında FIN WAIT 1, FIN WAIT 2, CLOSING, TIME WAIT ve öbür tarafta CLOSE WAIT ile LAST ACK olmak üzere çok sayıda geçiş vardır. Basit bir yapı değildir, ama yerleşmiş, hataları ayıklanmış ve günümüzde kullanılan yapıdır.

## 10. TCP Kayan Pencere ve Akış Denetimi

### 10.1 Örnek

Önceki derste dört slotla konuşulan kayan pencerenin gerçek hayattaki uygulaması budur. Slayt: "TCP önceki gibi kayan pencereye akış denetimi ekler; ACK + WIN gönderenin sınırıdır" (ekrandan, 01:25:00). Burada alıcının tamponu 4 KB ve başlangıçta boştur.

> **Hocanın vurgusu:** TCP/IP'de bütün onaylar bayt cinsindendir.

Adım adım (değerler kareden, ACK ve WIN değerleri python ile doğrulandı):

| Adım | Olay | Segment | Alıcı tamponu (0-4K) |
|---|---|---|---|
| 1 | Uygulama 2K yazar | Gönderen → alıcı: 2K, SEQ = 0 | 2K dolu, 2K boş |
| 2 | Alıcı onaylar | Alıcı → gönderen: ACK = 2048, WIN = 2048 | |
| 3 | Uygulama 2K daha yazar | Gönderen → alıcı: 2K, SEQ = 2048 | Full |
| 4 | Alıcı onaylar | Alıcı → gönderen: ACK = 4096, WIN = 0 (gönderen bloke) | |
| 5 | Alıcıdaki uygulama 2K okur | Alıcı → gönderen: ACK = 4096, WIN = 2048 | ilk 2K boş, son 2K dolu |
| 6 | Gönderen 2K'ya kadar gönderebilir | Gönderen → alıcı: 1K, SEQ = 4096 | 1K \| boş \| 2K |

Ayrıntılar:

- **Adım 1-2:** 2K, yani 2048 bayt gönderilir; indeksler 0'dan başlar ve 2047'de biter. Bu yüzden alıcı 2048'i onaylar: "2048 ve sonrasını bekliyorum." 4K'nın yarısı dolduğu için alabileceği en çok veri de 2048'dir.
- **Adım 3-4:** Gönderen SEQ = 2048 ile 2K daha gönderir; tampon dolar. Veri sorunsuz geldiği için onay 4096'dır (beklenen bir sonraki bayt), ama pencere 0'dır. Bundan sonra gönderen bloke olur, çünkü alıcı "bende senin için tampon kalmadı" demiştir.
- **Adım 5:** Uygulama bir okuma yaptığında tampon boşalır. Uygulama tek bir bayt bile okuyabilir (bu ayrıca sorunludur, 11. bölümde). Burada 2K okur (4K'nın tamamını da okuyabilirdi); tamponun başındaki 2K'lık alan boşalır, sonundaki 2K dolu kalır. Alıcı hemen gönderene bildirir: onay değeri değişmez (hâlâ 4096 beklenir), ama pencere 0'dan 2048'e çıkar.
- **Adım 6:** Gönderenin gönderecek 2K'sı olmayabilir; belki yukarıdan push gelmiştir. 1K'yı SEQ = 4096 ile gönderir. Tampon dairesel kullanıldığı için bu 1K tamponun başına yerleşir.

Bunun ardından alıcı 4096'ya 1024 ekleyerek yeni onay numarasını 5120 yapar ve pencereyi 1024 olarak ilan eder: baştaki 1K dolu, sondaki 2K dolu, ortadaki 1K boştur (bu son adım slaytta yok, hoca sözlü anlattı).

Böylece altta ağ katmanıyla birbirine bağlanan iki taşıma katmanı arasında, taşıma seviyesinde akış denetimi sağlanmış olur. Akış denetimi yine kayan pencereyle yapılır; ama veri bağı katmanındaki kayan pencere bağlantı bazında, tek atlamalıydı (single hop). Burada ise çok atlamalı (multiple hop), uçtan uca taşıma seviyesinde bir kayan pencere gerçekleştirilir.

### 10.2 Kayıp pencere güncellemesi ve istisnalar

Kontrol paketleri istisna değildir: alıcının "tampon boşaldı, WIN = 2048" diyen güncellemesi de kaybolabilir. O durumda gönderen alıcının tamponunun boşaldığını hiç göremeyebilir. Normalde alıcının tamponu doluyken gönderenin hiçbir şey göndermemesi beklenir; ama bu sorun yüzünden iki istisna vardır:

- **Pencere yoklaması (window probe):** Gönderen, "sende yer var mı, penceren neydi, bir daha söyler misin?" diye bir istekte bulunabilir; böylece kaybolmuş bir pencere güncellemesi varsa yeniden alınır.
- **Urgent veri:** Pencere 0 iken bile acil veri gönderilebilir.

Ayrıca gecikmeli onay (delayed acknowledgement) vardır: alıcı onayı hemen göndermeyip belli bir süre bekler. Bunun anlatımı bir sonraki konuya, aptal pencere sendromuna bağlanır.

## 11. Aptal Pencere Sendromu

Slayt: "İstenmeyen davranışları önlemek için özel durumlar eklemek gerekir; örneğin aptal pencere sendromu (silly window syndrome)" (ekrandan, 01:30:00). Şekildeki döngü:

```text
Receiver's buffer is full
  -> Application reads 1 byte
  -> Room for one more byte
  -> Window update segment sent        (yalnız Header giden segment)
  -> New byte arrives                  (Header + 1 Byte gelen segment)
  -> Receiver's buffer is full
  -> (başa döner)
```

Slaytın altında "Alıcı uygulama tek tek bayt okur, bu yüzden gönderen hep bir baytlık segmentler gönderir" yazar.

Bir önceki örnekle ilişkilendirerek: alıcının tamponu doludur ve uygulama bir bayt okur. Bir baytlık yer açılır; alıcı gönderene "bir bayt gönderebilirsin" diyerek pencereyi 1 bayt ilan eder. IP başlığı 20 bayt, hiç seçenek yoksa TCP başlığı da 20 bayttır; yani bir baytlık yer açıldığını anlatmak için 40 bayt gönderilir. Karşı taraf da bir bayt gönderebilmek için 40 baytlık başlık kullanır. Hoca bunu "sonuçta 80'de 1" diye özetledi; bu felaket kötü bir verimdir ve aptal pencere sendromu diye adlandırılır.

Böyle küçük bir pencere ilan etmenin anlamı yoktur. Çözüm olarak pencere değişikliğini bildiren paketler hemen gönderilmez, belli bir süre bekletilir (delay); en azından anlamlı miktarda yer açılması beklenir. Hoca bunu "en azından bir başlık boyutu kadar yer açılsın" diye örnekledi.

Hesap (python ile doğrulandı): pencere güncellemesi 40 bayt, 1 bayt veri taşıyan segment $40 + 1 = 41$ bayttır; toplam $81$ bayt ağa çıkar ve bunun yalnız 1 baytı kullanıcı verisidir. Verim $1/81 \approx \%1{,}2$ olur.

> **Ek bilgi (derste anlatılmadı):** Bu sorun için bilinen alıcı tarafı çözüm Clark'ın çözümüdür: alıcı, büyük olasılıkla en az bir en büyük segment boyutu (MSS) ya da tamponunun yarısı boşalana kadar pencere güncellemesi göndermez. Gönderen tarafta ise Nagle algoritması küçük verileri biriktirip tek segmentte gönderir; derste anılan TCP_NODELAY seçeneği bu algoritmayı kapatır.

## 12. TCP Zamanlayıcı Yönetimi

### 12.1 Veri bağı ve taşıma katmanında RTT

Zamanlayıcı yönetiminde temel kavram gidiş-dönüş süresidir (round trip time, RTT). Gösterilen iki grafiğin farkı, RTT'lerin farklı katmanlardan elde edilmesidir:

- **Sol grafik (veri bağı katmanı):** Tek bir bağlantıya ait RTT'dir; mikrosaniye ölçeğindedir, dağılım daha dik ve daha dardır. Bu, RTP'de jitter konuşulurken görülen düşük jitter grafiğine benzer.
- **Sağ grafik (taşıma katmanı):** Uçtan uca RTT'dir; daha basık ama daha geniş bir dağılım vardır, varyans çok oynar. Bunun sebebi, birbirinden farklı özelliklerde atlamalardan (yerel ağ, metropol ağı, geniş alan ağı, belki uydu) geçen bir yolun bütününü ifade etmesidir. Sağ taraf İnternet'e daha uygundur.

<!-- BELİRSİZ: Bu iki RTT grafiğinin olduğu slaydın karesi yok; açıklama yalnız altyazıdan yazıldı. -->

### 12.2 Dinamik zaman aşımı

TCP, gönderdiği bir segmentin onayını ne kadar beklemesi gerektiğini sabit bir değerle değil dinamik olarak hesaplar, çünkü farklı yerlere gönderiyor olabilir. Bunun için ortalama ve değişkenlik değerlerine bakar; hocanın anlatımıyla zaman aşımı "varyansın 4 katı artı ortalama" olarak ayarlanır. Ortalama, düzleştirilmiş RTT (Smoothed Round Trip Time) olarak üstel ağırlıklı hareketli ortalamayla (EWMA, exponentially weighted moving average) hesaplanır: RTT'nin şu anki ölçümü ile bir önceki ortalamanın ne kadarının dahil edileceği bir katsayıyla belirlenir. Diğer hoca bunu işletim sistemlerinde alfa değeriyle yapılan tahminlere benzetti.

> **Ders sonrası not:** Hoca "varyansın 4 katı" dedi. Standart TCP'de (büyük olasılıkla RFC 6298) zaman aşımı $RTO = SRTT + 4 \cdot RTTVAR$ biçimindedir; burada $RTTVAR$ varyans değil, RTT'nin ortalamadan mutlak sapmasının üstel ortalamasıdır.

> **Ek bilgi (derste anlatılmadı):** Güncellemeler büyük olasılıkla şöyledir: $SRTT \leftarrow \alpha \cdot SRTT + (1-\alpha) \cdot R$ ve $RTTVAR \leftarrow \beta \cdot RTTVAR + (1-\beta) \cdot |SRTT - R|$; tipik değerler $\alpha = 7/8$ ve $\beta = 3/4$'tür. Burada $R$ yeni RTT ölçümüdür.

## 13. TCP Tıkanıklık Denetimine Kısa Bakış

Tıkanıklık denetiminin temelleri (denge noktası, adalet (fairness) eğrisi, artırma ve azaltmanın toplamsal ya da çarpımsal yapılabilmesi) önceki derste genel olarak konuşulmuştu; TCP'deki slaytlar ayrıntılı anlatılmadı ve öğrencilerin incelemesine bırakıldı. TCP'nin toplamsal artırma, çarpımsal azaltma (Additive Increase Multiplicative Decrease, AIMD) kullandığı ve TCP Tahoe ile TCP Reno sürümlerinin olduğu hatırlatıldı.

Ekranda gösterilen tablo (ekrandan, 01:35:00), "TCP tıkanıklığı denetlemek için kayıp sinyaliyle AIMD kullanır; ağda bulunabilecek segment sayısı için bir tıkanıklık penceresi (cwnd) olarak gerçekleştirilir; birlikte çalışan birkaç mekanizma kullanır" başlığı altında:

| Ad | Mekanizma | Amaç |
|---|---|---|
| ACK clock | Congestion window (cwnd) | Smooth out packet bursts |
| Slow-start | Double cwnd each RTT | Rapidly increase send rate to reach roughly the right level |
| Additive Increase | Increase cwnd by 1 packet each RTT | Slowly increase send rate to probe at about the right level |
| Fast retransmit / recovery | Resend lost packet after 3 duplicate ACKs; send new packet for each new ACK | Recover from a lost packet without stopping ACK clock |

Tahoe ile Reno arasındaki farka kısaca değinildi: birinde pencere bir eşiğe (threshold) kadar iner, diğerinde her kayıpta en başa iner.

<!-- BELİRSİZ: Altyazıda hangi sürümün "sıfıra kadar" indiği net değil. -->

> **Ders sonrası not:** Hoca bir sürümde pencerenin "sıfıra kadar" indiğini söyledi. Büyük olasılıkla kastedilen TCP Tahoe'dur: Tahoe her kayıpta tıkanıklık penceresini 1 segmente indirip slow-start'a döner; Reno ise üç yinelenen ACK ile anlaşılan kayıpta pencereyi yarıya indirip (fast recovery) devam eder. Pencere sıfıra değil, 1 segmente iner.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:16:38): UDP akış denetimi, tıkanıklık denetimi ve yeniden gönderim yapmıyorsa ne için kullanılır? En tipik örnek nedir?

> **Cevap (derste verildi):** Tek soru-tek cevaplık işler için uygundur; en temiz örnek DNS'tir. Soru-cevap yapısı bir fonksiyon çağrısına da benzediği için RPC için de uygundur.

**Soru 2** (derste sözlü, 00:27:00): Slayttaki katman şekline bakıldığında Real-time Transport Protocol hangi katmandadır?

> **Cevap (derste verildi):** RTP bir taşıma protokolüdür, ama UDP üzerine kurulur ve kullanıcı alanında bir kütüphane olarak çalışır.

**Soru 3** (derste sözlü, 00:57:26): TCP başlığındaki başlık uzunluğu alanı 4 bittir. Bayt cinsinden başlık uzunluğunu bulmak için bu alandaki değer neyle çarpılır, neden?

> **Cevap (derste verildi):** 4 ile çarpılır, çünkü TCP başlığı da IP başlığı gibi 32 bitlik (4 baytlık) sınırlara oturtulmuştur.

**Soru 4** (derste sözlü, 01:10:20): İki host aynı anda birbirine bağlantı açarsa (simultaneous connect) kaç mesaj gerekir? Biri bağlantıyı kurduktan sonra öteki ayrıca bağlantı açarsa kaç mesaj gerekir?

> **Cevap (derste verildi):** Eş zamanlı açılışta 4 mesaj yeter; ardışık iki ayrı bağlantıda her biri için üç yönlü el sıkışma gerektiğinden 6 mesaj olur.

**Soru 5** (derste sözlü, 01:11:46): Basit taşıma protokolünün durum makinesinde 4-5 durum vardı. TCP bağlantı durum makinesinde kaç durum vardır?

> **Cevap (derste verildi):** 11 durum (ekrandan, 01:15:00): CLOSED, LISTEN, SYN RCVD, SYN SENT, ESTABLISHED, FIN WAIT 1, FIN WAIT 2, TIME WAIT, CLOSING, CLOSE WAIT, LAST ACK.

**Soru 6** (ekrandan, 01:25:00; derste sözlü, 01:22:46-01:25:31): Alıcı tamponu 4 KB'dır. Gönderen 2K'yı SEQ = 0 ile gönderir. (a) Alıcı hangi onay numarasını ve pencereyi döner? (b) Gönderen 2K'yı daha SEQ = 2048 ile gönderdiğinde? (c) Alıcıdaki uygulama 2K okuyunca? (d) Gönderen 1K'yı SEQ = 4096 ile gönderdiğinde alıcı ne döner?

> **Cevap (derste verildi, python ile doğrulandı):** (a) ACK = 2048, WIN = 2048 (baytlar 0-2047 alındı). (b) ACK = 4096, WIN = 0; gönderen bloke olur. (c) ACK = 4096, WIN = 2048. (d) ACK = 4096 + 1024 = 5120, WIN = 1024 (baştaki 1K ve sondaki 2K dolu, ortadaki 1K boş).

**Soru 7** (derste sözlü, 01:28:35): Alıcının tamponu doluyken uygulama yalnız 1 bayt okursa ve alıcı hemen 1 baytlık pencere ilan ederse ne olur?

> **Cevap (derste verildi):** 20 bayt IP + 20 bayt TCP = 40 baytlık bir pencere güncellemesi 1 baytlık yer için gönderilir; karşı taraf da 1 bayt için 40 baytlık başlık kullanır. Bu aptal pencere sendromudur; çözüm pencere güncellemesini bekletmektir. (Hesap: 81 bayttan 1'i veri, verim $1/81 \approx \%1{,}2$; python ile doğrulandı.)

## Dersin Toparlaması

Bu derste taşıma katmanının kuramsal ilkeleri İnternet'teki protokollere uygulandı. UDP'nin yalnız port, uzunluk ve checksum içeren 8 baytlık başlığıyla bağlantısız, sırasız ve denetimsiz bir hizmet verdiği; bu yüzden DNS ve RPC gibi tek soru-tek cevaplık işlere uygun olduğu görüldü. RPC'nin stub'larla yordam çağrısı soyutlaması sağladığı, işaretçi aktarımı gibi zorlukları ve yeniden gönderimli UDP'yi kullandığı anlatıldı. RTP'nin kullanıcı alanında, UDP üzerinde çalışan bir taşıma protokolü olduğu; sıra numarası, zaman damgası ve kaynak tanımlayıcılarla birden fazla medya akışını eşlediği, RTCP ile bant içi kontrol yaptığı ve alıcı tamponuyla jitter'ı söndürdüğü incelendi.

TCP tarafında güvenilmez IP üzerinde güvenilir bir bayt akışı kurulduğu, uygulamanın segmentleri değil bayt akışını gördüğü vurgulandı. Segment başlığındaki alanlar ve bayraklar (URG, ACK, PSH, RST, SYN, FIN), üç yönlü el sıkışma ve eş zamanlı açılış, 11 durumlu durum makinesi ile iki ayrı simplex gibi yapılan bağlantı sonlandırma ve TIME WAIT'in gerekçesi ele alındı. 4 KB tamponlu örnekle bayt cinsinden onaylar ve pencere üzerinden uçtan uca akış denetimi, pencere yoklaması, aptal pencere sendromu ve dinamik zaman aşımı hesabı açıklandı. Tıkanıklık denetiminde AIMD, slow-start ve fast retransmit/recovery tablosu gösterildi; ayrıntılar önceki derste konuşulan genel ilkelere dayanır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
