# Ders 5 Genişletilmiş Notu: Taşıma Katmanı I: Hizmetler, Çoğullama, UDP ve Güvenilir Veri Aktarımı İlkeleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Taşıma Katmanına Giriş
- 2. Taşıma Katmanı Hizmetleri
- 3. İki Temel İnternet Taşıma Protokolü: TCP ve UDP
- 4. Çoğullama ve Çoğul Çözme
- 5. Bağlantısız (UDP) Çoğul Çözme
- 6. Bağlantı Yönelimli (TCP) Çoğul Çözme
- 7. UDP: User Datagram Protocol
- 8. UDP Segment Başlığı ve Checksum
- 9. Güvenilir Veri Aktarımı İlkeleri
- 10. rdt1.0: Güvenilir Kanal Üzerinde Güvenilir Aktarım
- 11. rdt2.0: Bit Hatası Olan Kanal
- 12. rdt2.1: Bozuk ACK/NAK'ların Ele Alınması
- Örnek Sorular
- Dersin Toparlaması

## 1. Taşıma Katmanına Giriş

Bu hafta dersin üçüncü konusuna, taşıma katmanına geçildi (ders büyük ölçüde İngilizce anlatıldı). Taşıma katmanı bu hafta ve sonraki iki hafta boyunca işlenecektir. Hoca konuya bir önceki konuyla bağlantı kurarak başladı: uygulama katmanı İnternet'in görünen katmanıdır ve kullanıcının uygulamaları bu katmanda çalışır. Taşıma katmanı ise uygulama katmanına hizmet veren katmandır.

İnternet bir "ağların ağı"dır ve ağ katmanında güvenilir veri aktarımı yoktur. Bu yüzden güvenilir veri aktarımı daha üst katmanlarda yapılmalıdır. Amaç güvenilir veri aktarımı sağlamaksa bunun için bir akış kontrolü (flow control) ve bir tıkanıklık kontrolü (congestion control) mekanizması da gerekir.

> **Ders sonrası not:** Hoca bu iki mekanizmayı bir yerde "ağ katmanında güvenilir veri aktarımı için gereken iki şart" diye andı (00:19:02). Anlatımın bütününden anlaşıldığı gibi bu mekanizmalar ağ katmanında değil, taşıma katmanında (TCP'de) bulunur.

İnternet'te iki taşıma katmanı protokolü vardır: bağlantısız taşıma sağlayan UDP ve bağlantı yönelimli, güvenilir veri aktarımı sağlayan TCP. TCP güvenilir veri aktarımını garanti ettiği için tıkanıklık kontrolü ve akış kontrolü mekanizmalarına sahiptir.

Taşıma katmanı bölümünün yol haritası şöyledir (ekrandan, 00:20:00):

- Taşıma katmanı hizmetleri
- Çoğullama ve çoğul çözme (multiplexing and demultiplexing)
- Bağlantısız taşıma: UDP
- Güvenilir veri aktarımı ilkeleri
- Bağlantı yönelimli taşıma: TCP
- Tıkanıklık kontrolü ilkeleri
- TCP tıkanıklık kontrolü
- Taşıma katmanı işlevlerinin evrimi

Bu derste ilk dört başlık işlendi; güvenilir veri aktarımı ilkeleri sonraki derste sürecektir.

## 2. Taşıma Katmanı Hizmetleri

### 2.1 Süreçler arası mantıksal iletişim

Hoca İnternet'in genel resmini hatırlattı: ağların ağı olan İnternet'te birçok uç cihaz ile yönlendiriciler, erişim noktaları gibi altyapı cihazları vardır. Taşıma katmanı, farklı hostlarda çalışan uygulama süreçleri arasında mantıksal iletişim sağlar.

Derste verilen örnekte bir cep telefonundaki İnternet tarayıcısı, dünyanın başka bir yerindeki bir Web sunucusunda çalışan Apache sunucusuna erişmeye çalışır. Taşıma katmanı bir uçtan diğer uca mantıksal bir iletişim bağlantısı kurar (ekrandan, 00:30:00). Slayttaki şekilde yalnız iki uçtaki cihazın taşıma katmanı işaretlenmiştir; aradaki yönlendiriciler taşıma katmanında iş yapmaz.

### 2.2 Gönderici ve alıcıdaki işlemler

Taşıma protokolü uç sistemlerde, yani gönderici ve alıcı tarafta çalışır. Göndericide taşıma katmanı, uygulama mesajlarını segment (segment) adı verilen parçalara bölmekten ve bunları bir alttaki ağ katmanına vermekten sorumludur. Alıcıda ise segmentleri yeniden birleştirip mesajı uygulama katmanına verir. İnternet uygulamalarının kullanabileceği iki taşıma katmanı protokolü vardır: TCP ve UDP.

Ders arasından sonra hoca bu işlemleri bir kez daha adım adım anlattı:

- Göndericide uygulama bir mesaj oluşturur ve soket üzerinden gönderir.
- Taşıma katmanı mesajı segmentlere böler ve segment başlık alanlarının değerlerini belirler.
- Oluşturulan segmentler ağ katmanına verilir; ağ katmanı IP başlığını ekler.
- Alıcıda mesaj ağ katmanından taşıma katmanına çıkar. Mesaj birçok segmente bölünüp her segment ayrı gönderildiği için taşıma katmanı her segmentin başlığını kontrol eder ve uygulama katmanı mesajını çıkarır.
- Son olarak mesajlar soketler üzerinden ilgili uygulamalara çoğul çözülür (demultiplex).

### 2.3 Ev benzetmesi

Taşıma katmanı ile ağ katmanı arasındaki farkı anlatmak için slayttaki ev benzetmesi kullanıldı (ekrandan, 00:25:00). Ann'in evindeki 12 çocuk, Bill'in evindeki 12 çocuğa mektup göndermektedir:

- Hostlar = evler
- Süreçler = evdeki çocuklar
- Uygulama mesajları = zarflardaki mektuplar
- Taşıma protokolü = mektupları evdeki kardeşlere dağıtan (ve onlardan toplayan) Ann ve Bill
- Ağ katmanı protokolü = posta hizmeti

Buna göre ağ katmanı hostlar arasında mantıksal iletişim sağlar; taşıma katmanı ise süreçler arasında mantıksal iletişim sağlar ve ağ katmanının hizmetine dayanır.

## 3. İki Temel İnternet Taşıma Protokolü: TCP ve UDP

Slayttaki karşılaştırma şöyledir (ekrandan, 00:30:00):

- **TCP (Transmission Control Protocol):** güvenilir, sıralı (in-order) teslim; tıkanıklık kontrolü; akış kontrolü; bağlantı kurulumu.
- **UDP (User Datagram Protocol):** güvenilmez, sırasız teslim; "en iyi çaba" (best-effort) IP'nin süssüz (no-frills) bir uzantısı.

Hoca sıralı teslimin neden önemli olduğunu sordu ve cevapladı: mesajlar segmentlere bölünmüştür, bu segmentlerin alıcı tarafta doğru sırayla yeniden birleştirilmesi gerekir. TCP bu özellikleri sağlamak için tıkanıklık ve akış kontrolüne sahiptir; ayrıca segment alışverişinden önce bağlantıyı kurar, yani bir bağlantı kurma mekanizması da vardır.

UDP ise güvenilmez ve sırasız teslim sağlar. En iyi çaba hizmeti veren IP'nin üzerine yalnızca port mekanizmasını ekler; güvenilir bağlantı sunmaz.

> **Hocanın vurgusu:** Biri güvenilir ve bağlantı yönelimli, diğeri güvenilmez ve bağlantısız olsa da iki protokolün hiçbiri gecikme ve bant genişliği için garanti vermez. İnternet'in taşıma katmanında böyle bir hizmet yoktur.

## 4. Çoğullama ve Çoğul Çözme

### 4.1 Başlıkların eklenmesi

Örnekte solda ve sağda birer istemci, ortada bir HTTP (Apache) sunucusu vardır. Uygulama mesajı oluşturup taşıma katmanına gönderir. Taşıma katmanı gelen mesajı segmentlere böler ve taşıma katmanı başlığını ekler; başlıkta gönderen port ve alan port bulunur. Ağ katmanı da kendi başlığını ekler; bu başlıkta gönderen ve alan IP adresi bulunur.

### 4.2 Soketler ve süreçler

Aynı hostta birçok süreç çalışabilir ve her süreç taşıma katmanına erişmek için bir kapı kullanır; soket (socket) bu kapıdır. Slayttaki örnekte (ekrandan, 00:35:00) ortadaki sunucuda P1 ve P2 süreçleri, soldaki istemcide P3, sağdaki istemcide P4 vardır. P1, P3 ile; P2, P4 ile haberleşir. Sunucudaki her sürecin kendine özgü bir kapısı (soketi) vardır. Böylece taşıma katmanı P1 ile P3 arasında ve P2 ile P4 arasında mesaj alışverişi için ayrı mantıksal bağlantılar kurar.

- **Göndericide çoğullama:** birden çok soketten gelen veriyi alır ve taşıma başlığını ekler. Bu başlık daha sonra çoğul çözme için kullanılır; yani başlıkta çoğul çözmeye yarayacak bir bilgi bulunmalıdır.
- **Alıcıda çoğul çözme:** aynı başlık alanı kullanılarak alınan segmentler doğru sokete teslim edilir. Bu gereklidir, çünkü ortadaki sunucuda farklı istemcilerle konuşan iki ayrı süreç vardır.

### 4.3 Çoğul çözme nasıl çalışır?

Host IP datagramlarını alır. Her datagramda bir kaynak IP adresi ve bir hedef IP adresi bulunur; ağdaki her hostun kendine özgü bir adresi olmalıdır. Her datagram bir taşıma katmanı segmenti taşır ve her segmentte kaynak port ile hedef port numarası vardır. Her soketin kendine özgü bir port numarası, her hostun kendine özgü bir IP adresi olduğu için her segment IP adresleri ve port numaralarıyla benzersiz biçimde adreslenebilir. Host, segmenti uygun sokete yönlendirmek için IP adreslerini ve port numaralarını kullanır.

TCP/UDP segment biçimi 32 bit genişliğindedir. Başlıkta 16 bitlik kaynak port ve 16 bitlik hedef port ile ileride ele alınacak diğer başlık alanları vardır. Başlığın ardından yük (payload) gelir; yük, uygulama verisidir, yani bölünmüş mesajın ilgili parçasıdır.

## 5. Bağlantısız (UDP) Çoğul Çözme

Slayt (ekrandan, 00:40:00) önce soket oluşturmayı hatırlatır. Soket oluşturulurken host-yerel port numarası belirtilmelidir:

```java
DatagramSocket mySocket1 = new DatagramSocket(12534);
```

Buradaki 12534 port numarasıdır ve o iletişim için benzersizdir.

UDP soketine gönderilecek bir datagram oluşturulurken hedef IP adresi ve hedef port numarası belirtilmelidir. Hoca, bağlantısız aktarımda kaynak IP ve kaynak port belirtmeye gerek olmadığını, UDP soketi için hedef IP ve hedef portun yeterli olduğunu söyledi.

Alıcı host bir UDP segmenti aldığında:

- Segmentteki hedef port numarasını kontrol eder.
- UDP segmentini o port numarasına sahip sokete, yani ilgili uygulamaya yönlendirir.

Sonuç olarak hedef port numarası aynı olan, ama kaynak IP adresleri ve/veya kaynak port numaraları farklı olan IP/UDP datagramları alıcı hostta aynı sokete yönlendirilir.

### 5.1 Örnek

Örnekte ortadaki sunucuda P1 (hoca bir yerde "Application 1" dedi), birinci istemcide P3, ikinci istemcide P4 vardır. Sunucudaki soketin numarası 6428, birinci istemcideki P3'ün soketi 9157'dir.

| Segment | Kaynak port | Hedef port |
|---|---|---|
| P3 (istemci 1) → sunucu | 9157 | 6428 |
| Sunucu → P3 (istemci 1) | 6428 | 9157 |
| Sunucu → P4 (istemci 2) | 6428 | P4'ün portu |

Sunucudaki süreç aynı anda P4 ile de haberleşiyorsa P4'e gönderirken de kaynak port 6428 olur; yani iki istemciden gelen segmentler aynı sunucu soketinde toplanır. <!-- BELİRSİZ: P4'ün port numarası altyazıda geçmiyor ve o ana (00:41) ait kare yok. -->

## 6. Bağlantı Yönelimli (TCP) Çoğul Çözme

TCP bağlantı yönelimli, güvenilir ve sıralı teslim sağlar. Bu yüzden bir TCP soketi dört değerle (4-tuple) tanımlanır:

- Kaynak IP adresi
- Kaynak port numarası
- Hedef IP adresi
- Hedef port numarası

Hoca, UDP'de yalnız iki değerin (hedef IP ve hedef port) kullanıldığını, TCP'de ise kaynak IP ve kaynak portun da eklendiğini vurguladı. Çoğul çözme sırasında alıcı dört değerin tamamını kullanarak segmenti uygun sokete yönlendirir, çünkü TCP gönderici ile alıcı arasında mantıksal bir bağlantı kurar. Bir sunucu aynı anda birçok TCP bağlantısını destekleyebilir. Her soket kendi dörtlüsüyle tanımlanır, farklı bağlantıların dörtlüleri farklıdır ve her soket farklı bir bağlanan istemciyle ilişkilidir.

### 6.1 Örnek

Slayttaki örnekte (ekrandan, 00:45:00) IP adresi A olan bir host (süreç P1), IP adresi B olan Apache sunucusu (süreçler P4, P5, P6) ve IP adresi C olan başka bir host (süreçler P2, P3) vardır.

A'daki P1 ile sunucudaki P4 arasındaki bağlantı:

| Yön | Kaynak IP, port | Hedef IP, port |
|---|---|---|
| A → B | A, 9157 | B, 80 |
| B → A | B, 80 | A, 9157 |

Hedef port 80'dir, çünkü HTTP hizmetini 80 numaralı port üzerinden verir.

C hostundan sunucuya iki ayrı bağlantı daha açılır. Farklı süreçlerin farklı soketleri olmalıdır:

| Bağlantı | Kaynak IP, port | Hedef IP, port |
|---|---|---|
| C'deki birinci süreç → sunucu | C, 5775 | B, 80 |
| C'deki ikinci süreç → sunucu | C, 9157 | B, 80 |

C'deki ikinci bağlantının kaynak portu, A'daki P1'in kullandığı 9157 ile aynıdır. Buna rağmen iki bağlantının dörtlüleri farklıdır, çünkü IP adresleri hostlar arasında değişir (A ve C). Böylece Apache sunucusu bu iki iletişimi birbirinden ayırt eder.

> **Ders sonrası not:** Altyazıda C'den giden birinci bağlantının hedef portu "8" ve ikinci bağlantının kaynak portu "51.9157" diye geçiyor (00:45:49, 00:46:29). Bunlar Whisper bozmalarıdır; slayttaki örnek ve hocanın sonraki toparlamasına göre hedef port 80, kaynak port 9157'dir. Hoca süreç adlarını anlatırken (P1-P4, P2-P6, P3-P5) slayttaki etiketlerle birebir eşleşmeyen numaralar da kullandı. <!-- BELİRSİZ: C hostundaki iki bağlantının sunucuda hangi süreçlere (P5, P6) gittiği karede tam görünmüyor. -->

> **Hocanın vurgusu:** Hedefi IP adresi B ve port 80 olan üç segment de farklı soketlere çoğul çözülür. Ayırt etmeyi sağlayan, dörtlünün farklı olmasıdır.

## 7. UDP: User Datagram Protocol

### 7.1 Temel özellikler

Arada hocanın bilgisayarında bir sorun çıktı ve ders aradan sonra kaldığı yerden sürdü. Hoca önce taşıma katmanında iki tür protokol olduğunu hatırlattı ve UDP'ye geçti. Slayttaki özellikler (ekrandan, 01:10:00):

- "Süssüz" (no frills), "çıplak" (bare bones) bir İnternet taşıma protokolüdür.
- "En iyi çaba" hizmeti verir; UDP segmentleri kaybolabilir ya da uygulamaya sırasız teslim edilebilir. Hiçbir garanti yoktur.
- Bağlantısızdır: UDP göndericisi ile alıcısı arasında el sıkışma (handshaking) yoktur, dolayısıyla RTT gecikmesi de yoktur. Her UDP segmenti diğerlerinden bağımsız işlenir.

Hoca ek yükün (overhead) çok düşük olduğunu, çünkü IP'nin üzerine yalnızca port numarasının eklendiğini söyledi.

### 7.2 UDP neden var?

Hoca "Böyle bir UDP'ye neden ihtiyaç duyarız?" diye sordu. Slayttaki cevaplar (ekrandan, 01:10:00):

- Bağlantı kurulmaz; bağlantı kurmak RTT gecikmesi ekleyebilir.
- Basittir: göndericide ve alıcıda bağlantı durumu tutulmaz.
- Başlık boyutu küçüktür.
- Tıkanıklık kontrolü yoktur: UDP istediği kadar hızlı gönderebilir ve tıkanıklık karşısında da çalışmaya devam edebilir.

Bunun bedeli, UDP segmentlerinin kaybolabilmesi ve sırasız gelebilmesidir. UDP, kayba dayanıklı ve hıza duyarlı oldukları için akış (streaming) medya uygulamalarında kullanılır: ek yük yoktur, başlık küçüktür ve segmentler daha hızlı ilerler; bazı segmentler kaybolsa bile aktarım hızlıdır. DNS, SNMP ve HTTP/3 de UDP kullanır.

### 7.3 HTTP/3 ve UDP

HTTP 1.1 ve HTTP/2 bağlantı yönelimlidir ve güvenilir veri aktarımı sağlar (TCP kullanır). HTTP/3 ise UDP üzerine kuruludur. Hoca "O zaman güvenilirliği nasıl sağlarız?" diye sordu: güvenilirlik uygulama katmanında eklenir. Sonuç olarak tıkanıklık kontrolü ve akış kontrolü de uygulama katmanında yapılır. HTTP/3, daha hızlı veri aktarımı sağladığı için UDP'yi kullanır; güvenilirliği, tıkanıklık ve akış kontrolünü uygulama katmanı üstlenir.

> **Ek bilgi (derste anlatılmadı):** HTTP/3'ün altında UDP üzerinde çalışan QUIC protokolü bulunur. Güvenilirlik, tıkanıklık kontrolü ve şifreleme QUIC tarafından sağlanır; uygulama açısından bu işlevler taşıma katmanının değil, kullanıcı alanındaki bu katmanın işidir.

### 7.4 RFC 768

UDP açık bir protokoldür ve standart belgesi RFC 768'dir (Request for Comments). Hoca belgenin ilk sayfasını gösterdi: hocanın deyişiyle 1980'lerde yayımlanmıştır, yalnızca üç sayfadır, okunması kolaydır ve protokolün ne kadar basit olduğunu gösterir.

### 7.5 UDP gönderici ve alıcı işlemleri

Örnekte bir SNMP istemcisi ile SNMP sunucusu vardır; SNMP uygulama katmanı protokolü UDP kullanır (ekrandan, 01:15:00).

UDP gönderici işlemleri:

- Uygulama katmanı mesajı kendisine verilir (SNMP uygulaması mesajı oluşturup soket üzerinden taşıma katmanına gönderir).
- UDP segment başlık alanlarının değerlerini belirler.
- UDP segmentini oluşturur (UDP başlığını ekler).
- Segmenti IP'ye verir; ağ katmanı IP adresini ekler ve segment ağ üzerinden alıcıya gönderilir.

UDP alıcı işlemleri:

- Ağ katmanı IP başlığını kontrol edip ayıklar ve segmenti taşıma katmanına verir.
- Taşıma katmanı UDP checksum başlık değerini kontrol eder. Amaç, alınan segmentin hata içermediğinden emin olmaktır. Hata varsa, UDP bağlantısız aktarım sağladığı için segment basitçe atılır.
- Hata yoksa uygulama katmanı mesajını çıkarır ve ilgili soket üzerinden uygulamaya iletir (çoğul çözer).

> **Ders sonrası not:** Altyazıda alıcı tarafta "IPv6 kontrol edilir" ifadesi geçiyor (01:15:06). Anlatımın akışına göre burada kastedilen IP başlığının kontrol edilip ayıklanmasıdır; büyük olasılıkla bir Whisper bozmasıdır.

## 8. UDP Segment Başlığı ve Checksum

### 8.1 Başlık alanları

UDP segment başlığında dört alan vardır, her biri 16 bittir:

- Kaynak port numarası
- Hedef port numarası
- Uzunluk (length): başlık dahil UDP segmentinin bayt cinsinden uzunluğu
- Checksum

Başlığın ardından uygulama verisi (mesaj) gelir. Hoca uzunluk alanının 16 bit olduğunu ve bu yüzden bir UDP segmentinin en büyük boyutunun $2^{16}$ olduğunu söyledi; önce "bit" deyip hemen "bayt" diye düzeltti.

> **Ders sonrası not:** Hoca uzunluk alanı 16 bit olduğu için en büyük UDP segment boyutunun $2^{16}$ bayt olduğunu söyledi. 16 bitlik bir alanın tutabileceği en büyük değer $2^{16}-1 = 65535$ olduğundan, başlık dahil en büyük UDP segmenti 65535 bayttır (python ile doğrulandı).

### 8.2 Checksum'ın amacı

Checksum alanı kritik alandır. Amacı hataları, yani iletilen segmentte ters dönmüş bitleri tespit etmektir: gönderici mantıksal 1 göndermiştir, ama alıcıda bu bit mantıksal 0'a dönmüştür ya da tersi olmuştur (ekrandan, 01:20:00). Hoca bir önceki slayttaki basit bir örnekte alıcının toplamı 10 bulduğunu, ama checksum'ın 11 olduğunu, bunun da paketin bozuk olduğu anlamına geldiğini anlattı. <!-- BELİRSİZ: Bu basit örneğin sayıları (01:18:41) karede yok; altyazıda yalnız "10" ve "11" değerleri geçiyor. -->

Slayttaki tanım (ekrandan, 01:20:00):

- **Gönderici:** UDP segmentinin içeriğini (UDP başlık alanları ve IP adresleri dahil) 16 bitlik tamsayılar dizisi olarak ele alır. Checksum, segment içeriğinin toplamasıdır (bire tümleyen toplamı, one's complement sum). Checksum değeri UDP checksum alanına konur.
- **Alıcı:** alınan segmentin checksum'ını hesaplar ve hesaplanan checksum'ın checksum alanındaki değere eşit olup olmadığını kontrol eder. Eşit değilse hata tespit edilmiştir. Eşitse hata tespit edilmemiştir; ama yine de hata olabilir mi? Bu daha sonra ele alınacaktır.

> **Hocanın vurgusu:** Değerler eşitse "hata tespit edilmedi" denir; bu, segmentin hata içermediği anlamına gelmez. Eşit değilse segmentte kesinlikle hata vardır.

### 8.3 İnternet checksum'ının hesaplanması

Hoca iki 16 bitlik tamsayıyla bir örnek çözdü. Toplama sağdan sola bit bit yapılır: "0 ile 1, 1 eder; 1 ile 0, 1 eder; 1 ile 1, 0 eder ve 1 elde olur; 0 ile 0 artı elde 1, 1 eder" diye ilerler. En soldaki toplamada bir taşma (overflow) olur. Bu taşan bit sona eklenir (wraparound) ve toplam elde edilir. Son olarak toplamın bire tümleyeni alınır: 0'lar 1'e, 1'ler 0'a çevrilir. Sonuç checksum değeridir.

> **Hocanın vurgusu:** Sayılar toplanırken en anlamlı bitten çıkan elde sonuca eklenmelidir. Kritik nokta budur.

<!-- BELİRSİZ: Örneğin anına (01:20:33-01:22:49) ait kare yok, sayılar ekrandan okunamadı. Aşağıdaki değerler, hocanın sesli okuduğu en sağdaki bitlerle (0+1, 1+0, 1+1 elde 1, 0+0+1) uyumlu olan Kurose-Ross ders kitabı slayt örneğinden alınmıştır ve python ile doğrulanmıştır. -->

Adım adım (ara adımlar python ile doğrulandı):

```text
              1110011001100110
            + 1101010101010101
            ------------------
 ham toplam  11011101110111011   (17 bit, en soldaki 1 taşan elde)
 wraparound   1011101110111011
            +                1
            ------------------
 toplam       1011101110111100
 checksum     0100010001000011   (toplamın bire tümleyeni)
```

### 8.4 Checksum'ın zayıf koruması

Hoca ardından birinci sayının en sağdaki (en düşük anlamlı) iki bitinin bozulduğunu (1 → 0, 0 → 1), ikinci sayının da en düşük anlamlı iki bitinin bozulduğunu varsaydı. Dört bit bozulmuş ve segment hatalı olduğu halde checksum aynı çıkar. Bu, eşit checksum'ın hatasızlığı kanıtlamadığını gösterir.

<!-- BELİRSİZ: Bozulmuş sayılar karede yok. Ders kitabındaki karşılık: 1110011001100101 + 1101010101010110; python ile hesaplanan toplam 1011101110111100, checksum 0100010001000011, yani ilk örnekle aynı. -->

Bu durumun nedeni, iki sayının aynı basamağındaki bitlerin ters yönde bozulmasıdır: birinci sayıda bir basamak 1 azalırken ikinci sayıda aynı basamak 1 artar ve toplam değişmez.

### 8.5 UDP'nin özeti

Hoca UDP bölümünü toparladı: UDP çok basit bir protokoldür; bağlantısız ve güvenilmez, ama hızlı veri aktarımı sağlar. Hızlı olduğu için SNMP, DNS ve hatta HTTP/3 gibi uygulama katmanı protokolleri UDP kullanır; HTTP/3'te güvenilirlik uygulama katmanında sağlanır.

> **Ders sonrası not:** Toparlamadaki listede altyazıda "SNMP, UDP, hatta HTTP/3" geçiyor (01:23:33). UDP burada bir uygulama protokolü olamaz; önceki listeye (01:11:21) göre büyük olasılıkla kastedilen DNS'tir.

## 9. Güvenilir Veri Aktarımı İlkeleri

### 9.1 Güvenilir hizmetin soyutlaması ve gerçeklenmesi

TCP'ye geçmeden önce güvenilir veri aktarımının nasıl yapılacağına bakıldı. Hoca, bu bölümde kendi güvenilir protokolümüzü adım adım tasarlayacağımızı söyledi.

Kanal %100 güvenilir olsaydı, yani kayıp, gecikme ya da başka bir sorun olmasaydı, ek bir mekanizmaya gerek kalmazdı: veri gönderilir ve değişmeden alınırdı. Asıl soru, güvenilmez bir kanal üzerinde nasıl güvenilir iletişim kurulacağıdır. Bunun için mesajı güvenilmez kanaldan gönderen göndericide bir protokol, alıcıda da güvenilirliği sağlayan protokolün diğer parçası gerekir (ekrandan, 01:25:00). Slaytta solda "güvenilir hizmet soyutlaması" (uygulamanın gördüğü güvenilir kanal), sağda "güvenilir hizmetin gerçeklenmesi" (gönderici ve alıcı tarafın güvenilir veri aktarım protokolü ile aradaki güvenilmez kanal) gösterilir. Ağ katmanı bağlantısız iletişim ve en iyi çaba hizmeti verdiği için güvenilmezdir.

Güvenilir veri aktarım protokolünün karmaşıklığı alttaki güvenilmez kanalın özelliklerine güçlü biçimde bağlıdır. Kablosuz bir kanal açık bir ortam olduğu için çok kayıp yaşar; fiber optik kanal ise neredeyse güvenilirdir.

Gönderici ve alıcı birbirinin durumunu bilmez: gönderici dünyanın bir yerinde, alıcı başka bir yerindedir. Mesajla bildirilmedikçe alıcının durumu bilinemez. Hoca bunu araya çekilmiş bir perdeye benzetti: gönderici ve alıcı birbirine karşı kördür. Bu yüzden güvenilmez bir iletişim kanalı üzerinden güvenilir hizmet için bir mekanizma gerçeklenmelidir.

### 9.2 rdt arayüzleri

Tasarlanan protokolün adı rdt'dir (reliable data transfer, güvenilir veri aktarımı). Arayüzler şöyledir (ekrandan, 01:30:00):

- `rdt_send()`: yukarıdan, örneğin uygulama tarafından çağrılır. Alıcının üst katmanına teslim edilecek veri bu çağrıyla verilir.
- `udt_send()`: rdt tarafından, paketi güvenilmez kanal üzerinden alıcıya aktarmak için çağrılır (unreliable data transfer).
- `rdt_rcv()`: paket, kanalın alıcı tarafına ulaştığında çağrılır.
- `deliver_data()`: segmentte hata yoksa rdt tarafından, alınan veriyi üst katmana teslim etmek için çağrılır.

Kanaldan geçen paketlerde veri ve başlık (header) bulunur; güvenilirlik için başlıkta bir şeyler bulunması gerekecektir.

### 9.3 Tasarım yaklaşımı

- Gönderici ve alıcı tarafı adım adım (artımlı) geliştirilir.
- Başlangıçta yalnız tek yönlü veri aktarımı ele alınır; ama kontrol bilgisi iki yönde de akar.
- Gönderici ve alıcı, sonlu durum makinesi (FSM, Finite State Machine) ile tanımlanır. Makine bir durumdadır; bir sonraki durum bir olay tarafından belirlenir ve makine kendini o duruma geçirir. Hoca bunu açık/kapalı durumlarına benzetti.

## 10. rdt1.0: Güvenilir Kanal Üzerinde Güvenilir Aktarım

rdt1.0, protokolün ilk sürümüdür. Amaç güvenilmez kanal üzerinde güvenilir protokol geliştirmek olsa da bu ilk adımda alttaki kanalın tamamen güvenilir olduğu varsayılır (ekrandan, 01:35:00):

- Bit hatası yoktur.
- Paket kaybı yoktur.
- Gönderici ve alıcı için ayrı FSM'ler vardır: gönderici veriyi alttaki kanala gönderir, alıcı veriyi alttaki kanaldan okur.

Gönderici FSM'i tek durumludur: "Yukarıdan çağrı bekle". Olay ve eylemler:

```text
rdt_send(data)
---------------------------
packet = make_pkt(data)
udt_send(packet)
```

Uygulama katmanından veri gelince veri segmentlerden büyük olabileceği için paketlere konur (`make_pkt`), sonra güvenilmez veri gönderme çağrısıyla kanala verilir.

Alıcı FSM'i de tek durumludur: "Aşağıdan çağrı bekle".

```text
rdt_rcv(packet)
---------------------------
extract(packet, data)
deliver_data(data)
```

Alıcı paketi alır, içinden veriyi çıkarır, birçok segmente bölünmüş veriyi yeniden birleştirir ve üst katmana teslim eder. Kanal %100 güvenilir olduğu için bu çok basittir; hocanın deyişiyle "ne ağrı ne baş ağrısı".

## 11. rdt2.0: Bit Hatası Olan Kanal

### 11.1 Hatadan kurtulma

Bir sonraki sürümde alttaki kanal paketteki bitleri bozabilir, yani paket hata içerebilir. Bit hataları İnternet checksum'ı ile tespit edilir. Soru, hatalardan nasıl kurtulunacağıdır. Hoca bunu insan konuşmasıyla karşılaştırdı: konuşmada karşımızdakinin söylediğini anladığımızı ya da anlamadığımızı belirtiriz.

- **Onay (ACK, acknowledgement):** alıcı göndericiye paketin doğru alındığını açıkça bildirir. Yeniden göndermeye gerek yoktur.
- **Olumsuz onay (NAK, negative acknowledgement):** alıcı göndericiye paketin hatalı olduğunu açıkça bildirir. Gönderici NAK aldığında paketi yeniden gönderir.

rdt2.0 bir **dur ve bekle** (stop-and-wait) protokolüdür: gönderici bir paket gönderir, sonra alıcının yanıt vermesini bekler. ACK gelirse bir sonraki paketi gönderir; NAK gelirse ACK alınana kadar aynı paketi yeniden gönderir.

### 11.2 Gönderici FSM'i

Gönderici FSM'inin iki durumu vardır (ekrandan, 01:40:00): "Yukarıdan çağrı bekle" ve "ACK ya da NAK bekle".

```text
[Yukarıdan çağrı bekle] --rdt_send(data)--> [ACK ya da NAK bekle]
    eylem: sndpkt = make_pkt(data, checksum)
           udt_send(sndpkt)

[ACK ya da NAK bekle] --rdt_rcv(rcvpkt) && isNAK(rcvpkt)--> [ACK ya da NAK bekle]
    eylem: udt_send(sndpkt)

[ACK ya da NAK bekle] --rdt_rcv(rcvpkt) && isACK(rcvpkt)--> [Yukarıdan çağrı bekle]
    eylem: yok (Λ)
```

Uygulama katmanından veri gelince paket veriden oluşturulur ve kanal güvenilmez olduğu için pakete checksum eklenir. Paket gönderilir ve makine "ACK ya da NAK bekle" durumuna geçer. ACK gelirse yeniden "yukarıdan çağrı bekle" durumuna döner; NAK gelirse aynı paketi yeniden gönderir.

### 11.3 Alıcı FSM'i

Alıcı taraf yine basittir:

- Paket alınır ve bozuksa NAK gönderilir.
- Paket alınır ve kontrol sonucunda hata yoksa paketten veri çıkarılır, yeniden birleştirilir, uygulamaya teslim edilir ve ACK paketi gönderilir.

Slayttaki not (ekrandan, 01:40:00): alıcının "durumu" (alıcı mesajımı doğru aldı mı?) alıcıdan göndericiye bir şekilde bildirilmedikçe gönderici tarafından bilinmez. Protokole bu yüzden ihtiyaç vardır. Slayttaki perde resmi de gönderici ile alıcı arasındaki bu görünmezliği anlatır.

### 11.4 Çalışma senaryoları

Hoca iki senaryoyu adım adım izledi:

- **Hatasız durum:** gönderici "yukarıdan çağrı bekle" durumundadır, alıcı "aşağıdan çağrı bekle" durumundadır. Uygulamadan veri gelir; `rdt_send` veriyi paketlere koyar, checksum ekler ve alıcıya gönderir. Alıcıda `rdt_receive` paketin bozuk olmadığını görür, veriyi çıkarır, birleştirir, teslim eder ve göndericiye ACK yollar. Gönderici ACK'i alır ve yeni veri beklemeye döner.
- **Hatalı durum:** alıcı bozuk paket alırsa göndericiye NAK yollar. Gönderici paketi hatasız alınana kadar yeniden gönderir. Paket hatasız alınınca alıcı ACK yollar ve gönderici durumunu "yukarıdan çağrı bekle" olarak değiştirir.

## 12. rdt2.1: Bozuk ACK/NAK'ların Ele Alınması

### 12.1 rdt2.0'ın kusuru

Hoca burada bir sorun olduğunu belirtti: ACK ya da NAK bozulursa ne olur? Gönderici alıcıda ne olduğunu bilemez. Bu durumda paketi doğrudan yeniden göndermek de olmaz, çünkü alıcı yinelenen (duplicate) veri, yani aynı paketten iki tane alabilir.

Çözüm şöyledir:

- Gönderici, ACK ya da NAK bozuk gelirse mevcut paketi yeniden gönderir.
- Gönderici her pakete bir sıra numarası (sequence number) ekler.
- Alıcı, yinelenen bir paket alırsa onu atar (üst katmana teslim etmez).

Protokol yine dur ve bekle protokolüdür: gönderici bir paket gönderir, sonra alıcının yanıtını bekler.

> **Ders sonrası not:** Hoca bu noktada "bir tür zaman aşımı (timeout) olmalı" anlamında bir cümle kurdu (01:43:25). Slayttaki rdt2.1 gönderici FSM'inde zamanlayıcı yoktur; zamanlayıcı büyük olasılıkla paket kaybının da ele alındığı sonraki sürümde (rdt3.0) eklenecektir.

### 12.2 Gönderici FSM'i

Tek bitlik sıra numarası kullanılır: 0 ve 1. Bu durumda gönderici FSM'inin dört durumu vardır (ekrandan, 01:45:00):

```text
[Yukarıdan 0 çağrısı bekle]
   rdt_send(data) / sndpkt = make_pkt(0, data, checksum); udt_send(sndpkt)
   --> [ACK ya da NAK 0 bekle]

[ACK ya da NAK 0 bekle]
   rdt_rcv(rcvpkt) && (corrupt(rcvpkt) || isNAK(rcvpkt)) / udt_send(sndpkt)
   --> [ACK ya da NAK 0 bekle]
   rdt_rcv(rcvpkt) && notcorrupt(rcvpkt) && isACK(rcvpkt) / Λ
   --> [Yukarıdan 1 çağrısı bekle]

[Yukarıdan 1 çağrısı bekle]
   rdt_send(data) / sndpkt = make_pkt(1, data, checksum); udt_send(sndpkt)
   --> [ACK ya da NAK 1 bekle]

[ACK ya da NAK 1 bekle]
   rdt_rcv(rcvpkt) && (corrupt(rcvpkt) || isNAK(rcvpkt)) / udt_send(sndpkt)
   --> [ACK ya da NAK 1 bekle]
   rdt_rcv(rcvpkt) && notcorrupt(rcvpkt) && isACK(rcvpkt) / Λ
   --> [Yukarıdan 0 çağrısı bekle]
```

Hocanın anlatımıyla: ilk durumda yukarıdan 0 numaralı veri beklenir; veri gelince 0 numarası ve checksum eklenerek gönderilir ve 0 için ACK beklenir. Olumlu onay gelirse yukarıdan 1 numaralı paket beklenir; o da gönderilir ve 1 için ACK ya da NAK beklenir. ACK gelirse makine yeniden ilk duruma, yukarıdan 0 numaralı paketi beklemeye döner. Herhangi bir bekleme durumunda gelen yanıt bozuksa ya da NAK ise aynı paket yeniden gönderilir.

### 12.3 Alıcı tarafı ve tartışma

Alıcı "aşağıdan çağrı bekle" durumundadır. Paket alınır ve içinde hata yoksa olumlu onay gönderilir ve alıcı bir sonraki sıra numaralı paketi (örneğin 1'i) aşağıdan beklemeye geçer.

Hoca, rdt2.1'de kanaldaki hatalar ele alındığı için paketlere sıra numarası eklendiğini ve bu sürümde iki sıra numarası (0 ve 1) olduğunu hatırlatarak "Bu yeterli mi?" diye sordu. Ardından alıcının durumunun, beklenen paketin sıra numarasının 0 mı 1 mi olması gerektiğini hatırlaması gerektiğini anlattı. Bazı durumlarda, örneğin bir gecikme olduğunda, aynı sıra numaralı paket yeniden gelebilir. Bu yüzden yinelenen paketler ele alınmalıdır: alıcı tarafta gelen paketin yineleme olup olmadığı kontrol edilmelidir. <!-- BELİRSİZ: Bu bölümde (01:46:19-01:47:48) altyazının bir kısmı anlamsız Türkçe tekrarlara dönüşmüş; alıcı FSM'inin ayrıntısı ve "Bu yeterli mi?" sorusunun cevabı altyazıdan tam çıkmıyor. -->

Ders bu noktada bitti; güvenilir veri aktarımı ilkeleri sonraki derste devam edecektir.

> **Ek bilgi (derste anlatılmadı):** Dur ve bekle protokolünde gönderici bir anda yalnızca bir paketi bekletir. Bu yüzden ardışık iki paketi ayırt etmek için iki sıra numarası (0 ve 1) yeterlidir; alıcı, beklediği numaradan farklı numaralı bir paket gelirse onun bir önceki paketin yinelemesi olduğunu anlar.

## Örnek Sorular

### Soru 1

(derste sözlü, 00:28:27) TCP neden sıralı (in-order) teslim sağlamak zorundadır?

**Cevap (derste verildi):** Uygulama mesajları segmentlere bölünerek gönderilir. Bu segmentlerin alıcı tarafta doğru sırayla yeniden birleştirilmesi gerekir; TCP bu yüzden güvenilir ve sıralı teslim sağlar.

### Soru 2

(ekrandan, 00:45:00) IP adresi A olan hosttaki bir süreç kaynak port 9157 ile IP adresi B olan Apache sunucusunun 80 numaralı portuna bağlanıyor. IP adresi C olan hosttaki bir süreç de aynı kaynak port 9157 ile aynı sunucunun 80 numaralı portuna bağlanıyor. Sunucu bu iki bağlantıyı nasıl ayırt eder? Sunucudan A'ya giden yanıt segmentinin kaynak ve hedef değerleri nedir?

**Cevap (derste verildi):** TCP soketi dört değerle (kaynak IP, kaynak port, hedef IP, hedef port) tanımlanır. Dörtlüler (A, 9157, B, 80) ve (C, 9157, B, 80) olduğu için, port numaraları aynı olsa da kaynak IP adresleri farklıdır ve segmentler farklı soketlere çoğul çözülür. Sunucudan A'ya giden yanıtta kaynak B, 80; hedef A, 9157'dir.

### Soru 3

(derste sözlü, 01:09:49) UDP hiçbir garanti vermediğine göre neden böyle bir protokole ihtiyaç duyarız?

**Cevap (derste verildi):** Bağlantı kurulmadığı için RTT gecikmesi eklenmez; basittir ve gönderici ile alıcıda bağlantı durumu tutulmaz; başlığı küçüktür; tıkanıklık kontrolü olmadığı için istediği kadar hızlı gönderebilir ve tıkanıklıkta da çalışabilir. Bu yüzden kayba dayanıklı ve hıza duyarlı akış uygulamaları ile DNS, SNMP ve HTTP/3 UDP kullanır.

### Soru 4

(derste sözlü, 01:20:33) İki 16 bitlik sayının İnternet checksum'ını hesaplayın: 1110011001100110 ve 1101010101010101. <!-- BELİRSİZ: Sayılar karede yok; değerler, hocanın sesli okuduğu bitlerle uyumlu ders kitabı örneğinden alındı. -->

**Çözüm (derste verildi, değerler python ile doğrulandı):** Ham toplam 17 bittir: 11011101110111011. En soldaki taşan 1 sona eklenir: 1011101110111011 + 1 = 1011101110111100. Checksum, bunun bire tümleyenidir: 0100010001000011.

### Soru 5

(derste sözlü, 01:22:03) Yukarıdaki iki sayının her birinde en düşük anlamlı iki bit bozulursa checksum değişir mi? Bu, alıcı için ne anlama gelir?

**Cevap (derste verildi):** Değişmez. Dört bit bozulmuş olduğu halde checksum aynı çıkar (python ile: 1110011001100101 + 1101010101010110 toplamı yine 1011101110111100, checksum yine 0100010001000011). Bu yüzden alıcıda checksum'ın eşit çıkması yalnızca "hata tespit edilmedi" demektir, segmentin hatasız olduğunu kanıtlamaz.

### Soru 6

(derste sözlü, 01:42:08) rdt2.0'da ACK ya da NAK bozulursa ne olur ve bu nasıl çözülür?

**Cevap (derste verildi):** Gönderici alıcıda ne olduğunu bilemez. Paketi körü körüne yeniden göndermek alıcıda yinelenen paketlere yol açabilir. Çözüm (rdt2.1): gönderici her pakete sıra numarası ekler, ACK/NAK bozuksa mevcut paketi yeniden gönderir; alıcı yinelenen paketi atar.

### Soru 7

(derste sözlü, 01:46:30) rdt2.1'de iki sıra numarası (0 ve 1) yeterli midir?

> **Çözüm (derste verilmedi):** Dur ve bekle protokolünde gönderici bir paketin onayını almadan yenisini göndermez; alıcı yalnızca "beklenen paket mi, bir önceki paketin yinelemesi mi?" ayrımını yapmak zorundadır. Bunun için tek bit, yani 0 ve 1 yeterlidir. Alıcı beklediği sıra numarasını durum olarak tutar; farklı numaralı paket gelirse onu yineleme sayıp atar.

## Dersin Toparlaması

Bu derste taşıma katmanına giriş yapıldı. Taşıma katmanının farklı hostlardaki süreçler arasında mantıksal iletişim sağladığı, ağ katmanının ise hostlar arası iletişimden sorumlu olduğu ev benzetmesiyle anlatıldı. TCP'nin güvenilir, sıralı, akış ve tıkanıklık kontrollü ve bağlantı yönelimli; UDP'nin ise güvenilmez, sırasız ve en iyi çaba hizmeti veren protokoller olduğu, ikisinin de gecikme ve bant genişliği garantisi vermediği görüldü. Çoğullama ve çoğul çözmede UDP soketinin hedef IP ve hedef portla, TCP soketinin ise dört değerle tanımlandığı port numaralı örneklerle gösterildi.

Dersin ikinci yarısında UDP'nin özellikleri, varlık nedeni, HTTP/3'teki kullanımı, RFC 768, gönderici ve alıcı işlemleri, başlık alanları ve İnternet checksum'ı işlendi; checksum'ın eşit çıkmasının hatasızlığı kanıtlamadığı bir örnekle gösterildi. Son olarak güvenilir veri aktarımı ilkelerine geçildi: rdt arayüzleri, rdt1.0 (kusursuz kanal), rdt2.0 (ACK/NAK ile dur ve bekle) ve rdt2.1 (bozuk ACK/NAK için 0/1 sıra numarası) sonlu durum makineleriyle anlatıldı. Sonraki derste güvenilir veri aktarımı ilkelerine devam edilecek, ardından TCP işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
