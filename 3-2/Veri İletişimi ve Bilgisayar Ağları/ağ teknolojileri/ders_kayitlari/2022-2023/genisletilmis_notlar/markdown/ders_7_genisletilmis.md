# Ders 7 Genişletilmiş Notu: Taşıma Katmanı: Tıkanıklık Denetimi, TCP Tıkanıklık Denetimi ve QUIC

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tıkanıklık Nedir?
- 2. Tıkanıklığın Nedenleri ve Maliyetleri: Üç Senaryo
- 3. Tıkanıklık Denetimine Yaklaşımlar
- 4. TCP Tıkanıklık Denetimi: AIMD
- 5. Tıkanıklık Penceresi ve TCP Hızı
- 6. Yavaş Başlangıç ve Tıkanıklıktan Kaçınma
- 7. TCP CUBIC
- 8. Darboğaz Bağlantı ve Gecikme Tabanlı Denetim
- 9. Açık Tıkanıklık Bildirimi (ECN)
- 10. TCP Adilliği
- 11. Taşıma Katmanının Evrimi ve QUIC

## 1. Tıkanıklık Nedir?

Bu ders, taşıma katmanı bölümünün üçüncü ve son haftasıdır. Geçen hafta kendi güvenilir veri aktarım protokolümüzü adım adım kurmuş, ardından bağlantı yönelimli protokol TCP'yi görmüştük. TCP güvenilir veri aktarımı sağlar; bunun yanında akış denetimi (flow control) ve tıkanıklık denetimi (congestion control) mekanizmaları vardır. Akış denetimini geçen hafta işlemiştik. Konu yol haritasında sıradaki başlık "tıkanıklık denetiminin ilkeleri", ardından "TCP tıkanıklık denetimi" ve "taşıma katmanı işlevselliğinin evrimi"dir (ekrandan, 00:15:00).

Hoca tıkanıklığı bir trafik fotoğrafıyla anlattı: yolda o kadar çok araç vardır ki yol bunları taşıyamaz. Ağda da benzer biçimde, çok sayıda kaynak ağın kaldırabileceğinden fazla veriyi çok hızlı gönderebilir. Bu duruma tıkanıklık denir.

### 1.1 Akış denetiminden farkı

Hoca tıkanıklık denetiminin akış denetiminden tamamen farklı olduğunu birkaç kez vurguladı. Akış denetimi bir gönderici ile bir alıcı arasındadır: tek bir gönderici alıcıya, alıcının kaldıramayacağı kadar hızlı veri gönderir ve bu engellenir. Tıkanıklık denetiminde ise sorun alıcı değil ağdır: çok sayıda kaynak birlikte ağa fazla veri yükler.

> **Hocanın vurgusu:** Tıkanıklık denetimi akış denetiminden tamamen farklıdır. Akış denetimi bir gönderici ve bir alıcıyla ilgilidir; tıkanıklık denetimi çok sayıda göndericinin ağa fazla veri göndermesiyle ilgilidir.

Tıkanıklık varsa iki belirti görülür. Birincisi uzun gecikmedir: hatırlarsak her yönlendiricinin, gelen verileri tutup ilgili hedeflere iletmek üzere sıraya koyduğu bir iç tamponu vardır; tıkanıklıkta paketler bu tamponda uzun süre bekler. İkincisi paket kaybıdır: tampon taşarsa yeni gelen paketler düşürülür. Hoca tıkanıklık denetimini ağlarda çözülmesi gereken en önemli (ilk 10) problemlerden biri olarak tanıttı.

## 2. Tıkanıklığın Nedenleri ve Maliyetleri: Üç Senaryo

### 2.1 Senaryo 1: Tek yönlendirici, sonsuz tampon

En basit senaryoda tek bir yönlendirici vardır. Sol tarafta iki gönderici (Host A ve Host B), sağ tarafta iki alıcı (iki sunucu) bulunur (ekrandan, 00:20:00). Yönlendiricinin bağlantı kapasitesi $R$ bit/s'dir: yönlendirici $R$ bit/s kabul edip $R$ bit/s iletebilir. Basitlik için paylaşılan çıkış bağlantısı tamponunun sonsuz olduğu varsayılır.

İki akış vardır: Host A'dan bir alıcıya ve Host B'den diğer alıcıya. A için $\lambda_{in}$ uygulamanın gönderdiği (giriş) bit hızı, $\lambda_{out}$ alıcıya ulaşan bit hızıdır, yani verimdir (throughput). B için de $\lambda_{in,B}$ ve $\lambda_{out,B}$ tanımlanır.

Tampon sonsuz olduğu için gelen her veri çıkış kuyruğuna konabilir; hiçbir paket düşmez ve Host A hiçbir mesajı yeniden göndermek zorunda kalmaz. Bağlantıyı iki akış paylaştığı için her biri en çok $R/2$ alabilir:

- $\lambda_{in} < R/2$ iken gelen bütün mesajlar çıkış portuna iletilebilir; $\lambda_{out} = \lambda_{in}$, yani grafik doğrusaldır.
- $\lambda_{in}$, $R/2$'yi aşınca paketler kuyrukta beklemeye başlar; $\lambda_{out}$ hiçbir zaman $R/2$'yi aşamaz. Verim $R/2$'de doyar.
- Gecikme ise $\lambda_{in}$ $R/2$'ye yaklaştıkça artar ve $R/2$'de sonsuza gider, çünkü gelen her mesaj paylaşılan çıkış tamponunda beklemek zorundadır.

### 2.2 Senaryo 2: Tek yönlendirici, sonlu tampon

İkinci senaryoda yine tek yönlendirici vardır ama paylaşılan çıkış tamponu sonludur (ekrandan, 00:25:00). (Hoca önce "sonsuz" dedi, hemen "sonlu" diye düzeltti.) Tampon dolunca bazı paketler yönlendirici tarafından düşürülür ve belli bir zaman aşımından sonra yeniden gönderilmelidir.

Burada iki giriş hızı ayrılır (ekrandan, 00:30:00):

- $\lambda_{in}$: özgün veri (original data) hızı; uygulama katmanının taşıma katmanına verdiği veri.
- $\lambda'_{in}$: özgün veri artı yeniden iletilen veri hızı. Tampon dolup paketler düştükçe $\lambda'_{in} > \lambda_{in}$ olur.

Hoca bu senaryoyu adım adım kurdu:

1. **İdealleştirme, tam bilgi:** Gönderici yalnız yönlendiricinin tamponu müsaitken gönderir; tampon müsait değilse gönderici durur. Paket gönderilir, tamponda bekler, çıkış bağlantısı boşalınca alıcıya gider. Bu durumda kayıp yoktur ve grafik $R/2$'ye kadar doğrusaldır.
2. **İdealleştirme, bir miktar tam bilgi:** Paketler dolu tampon yüzünden yönlendiricide kaybolabilir (düşürülebilir). Gönderici paketin düştüğünü bilir ve yalnız kaybolduğunu bildiği paketi yeniden gönderir. TCP güvenilir bir bağlantı olduğu için taşıma katmanı mesajın kopyasını saklar; tamponda yer açılınca kopya yeniden gönderilir. Tampon müsaitken çok az yeniden iletim olur, ama $R/2$ yakınında bazı paketler gerekli yeniden iletimdir. Bu yüzden verim eğrisi $R/2$'nin altında kıvrılır; ideal eğriyle aradaki fark yeniden iletimler yüzünden "harcanan" (wasted) kapasitedir (ekrandan, 00:30:00).
3. **Gerçekçi durum, kopyalar:** Paketler yalnız kaybolmaz; bazıları kuyrukta çok uzun bekler. Göndericinin zamanlayıcısı paket kaybolmadan dolar ve gönderici aynı paketi ikinci kez yollar. Alıcıya aynı mesajın iki kopyası gereksiz yere ulaşır. Verim daha da düşer: kayıp hem gerekli yeniden iletimlerin hem de gereksiz kopyaların harcadığı kapasitedir.

Gerçekçi senaryonun özeti: tıkanıklığın maliyeti, aynı veriyi birden fazla kez taşımak için daha çok iş yapmaktır. Bu da ulaşılabilecek en büyük verimi düşürür.

### 2.3 Senaryo 3: Dört gönderici, çok sekmeli yollar

Üçüncü senaryoda ağ büyütülür: dört gönderici vardır, yollar çok sekmelidir (multi-hop), yani paket birden fazla yönlendiriciden geçer; her yönlendiricinin sonlu paylaşılan çıkış tamponu vardır ve zaman aşımında yeniden iletim yapılır (ekrandan, 00:35:00).

Örneğin Host A, Host C'ye mesaj gönderiyor: kırmızı yol üzerinde iki yönlendirici geçilmelidir. Aynı anda Host D, Host B'ye gönderiyor; bu ikinci yolun ortasındaki yönlendirici iki akış tarafından paylaşılır. Diğer göndericiler de başka yönlerde gönderir. İnternet en iyi çaba (best effort) hizmeti verir; gelen her datagram bir sonraki bağlantıya iletilir ve bir mesajın parçaları farklı yollardan gelebilir. Kırmızı akışın mesajı birinci, sonra ikinci yönlendiriciden geçer; tıkanıklık bu yönlendiricilerden herhangi birinde olabilir.

> **Ders sonrası not:** Hoca 00:35:02'de "Ethernet bağlantısız bir protokoldür" dedi. Bağlamda kastedilen, İnternet'in (IP katmanının) en iyi çaba, bağlantısız hizmetidir; Ethernet bu senaryonun konusu değildir.

Kırmızı akışın $\lambda_{in}$ ve $\lambda'_{in}$ değerleri büyüdükçe, üstteki kuyruğa gelen bütün mavi paketler düşürülür; çünkü bağlantı kapasitesinin tamamını kırmızı trafik tüketir. Bir maliyet daha vardır: bir paket düşürüldüğünde, o paket için yukarı akışta (upstream) kullanılan bütün iletim kapasitesi ve tampon boşa gider. Bir mesaj bir yönlendiriciden geçer, sonraki yönlendiricide düşer, sonra yeniden gönderilir. Gereksiz mesajlar bütün kapasiteyi tüketince yeni mesaj taşınamaz ve verim sıfıra kadar düşebilir. Hoca bunu en kötü senaryo olarak niteledi.

### 2.4 Senaryoların özeti

Hoca "insights" slaytıyla üç senaryoyu bir kez daha topladı (ekrandan, 00:40:00):

- Verim kapasiteyi asla aşamaz: $\lambda_{in}$ arttıkça $\lambda_{out}$ doğrusal olarak $R/2$'ye kadar artar (ideal durum, tampon hiç taşmaz, yeniden iletim yok).
- Kapasiteye yaklaşıldıkça gecikme artar: $R/2$'ye yaklaşınca paketler kuyrukta uzun beklediği için gecikme sonsuza gider.
- Kayıp ve yeniden iletim etkin verimi düşürür: zaman aşımıyla yeniden gönderilen paketler çıkış kapasitesini harcar.
- Gereksiz kopyalar etkin verimi daha da düşürür: kuyrukta uzun bekleyen paket yeniden gönderilince alıcı aynı paketin iki kopyasını alır.
- Aşağı akışta kaybolan paketler için harcanan yukarı akış iletim kapasitesi ve tampon boşa gider: birden fazla sekmeli yolda verim sıfıra inebilir.

> **Hocanın vurgusu:** Bu üç senaryoyu izleyerek tıkanıklığın nedenini görebilirsiniz. Akış denetimi gibi tıkanıklık da denetlenmelidir.

## 3. Tıkanıklık Denetimine Yaklaşımlar

İki temel yaklaşım vardır (ekrandan, 00:40:00):

- **Uçtan uca tıkanıklık denetimi:** Ağdan açık bir geri bildirim gelmez. Tıkanıklık, göndericinin gözlediği kayıp ve gecikmeden çıkarılır (inferred). Paket gönderilir, ACK alınır, gönderici RTT'yi ölçer. TCP'nin tıkanıklık denetimi bu yaklaşımla yapılır.
- **Ağ destekli tıkanıklık denetimi:** Yalnız gönderici ve alıcı değil, yönlendiriciler de tıkanık yönlendiriciden geçen akışların gönderen ve alan uçlarına doğrudan geri bildirim verir. Bu geri bildirim tıkanıklık düzeyini gösterebilir ya da gönderme hızını açıkça belirleyebilir. Tıkanık yönlendirici, geçen hafta gördüğümüz başlık alanlarını kullanarak iki uca açık tıkanıklık bilgisi gönderir. Örnekler: TCP ECN, ATM ve DECbit protokolleri. <!-- BELİRSİZ: 00:41:48'de altyazı "TCP ECN field, ATM field, TEC bit" diyor; "TEC bit" büyük olasılıkla Kurose-Ross slaytındaki DECbit'tir. -->

## 4. TCP Tıkanıklık Denetimi: AIMD

### 4.1 Toplamalı artış, çarpımsal azalış

TCP'de kullanılan ilk yaklaşım AIMD'dir (Additive Increase Multiplicative Decrease, toplamalı artış çarpımsal azalış). Gönderici, kayıp olana kadar, yani yolda tıkanıklık oluşana kadar gönderme hızını artırır; kayıp olayında hızı azaltır. Biraz artırır, kayıp olunca azaltır, sonra yine artırır. Hızın zamana göre grafiği testere dişine (sawtooth) benzer.

- **Toplamalı artış (AI):** Kayıp algılanana kadar her RTT'de gönderme hızı 1 MSS (maximum segment size, en büyük segment boyutu) artırılır. Grafikte bu sabit eğimli bir doğrudur.
- **Çarpımsal azalış (MD):** Her kayıp olayında gönderme hızı yarıya indirilir.

### 4.2 Çarpımsal azalışın ayrıntısı: Reno ve Tahoe

Slayttaki ayrıntı şöyledir (ekrandan, 00:45:00):

- Kayıp üç kopya ACK (triple duplicate ACK) ile algılanırsa hız yarıya indirilir (TCP Reno).
- Kayıp zaman aşımıyla algılanırsa hız 1 MSS'e indirilir (TCP Tahoe).

Hoca bunu şöyle anlattı: TCP Reno'da gönderici üç kopya ACK bekler; TCP Tahoe'da gönderici ilk zaman aşımına kadar bekler ve pencereyi 1 MSS'e indirir. <!-- BELİRSİZ: 00:44:20-00:44:35 arası altyazı Türkçe ve bozuk ("duplikator acnowledim", tekrar eden satırlar); bu aralıktaki açıklama okunamadı. -->

### 4.3 Neden AIMD?

Hoca AIMD'nin tercih edilme nedenlerini şöyle sıraladı:

- Dağıtık ve eşzamansız (asynchronous) bir algoritmadır; merkezi bir koordinasyon gerekmez.
- Ağ genelinde tıkanık akış hızlarını en iyilediği gösterilmiştir.
- Çok basittir.
- İstenen kararlılık özelliklerine sahiptir.

## 5. Tıkanıklık Penceresi ve TCP Hızı

Göndericinin sıra numarası uzayı hatırlanırsa (geçen haftaki pencere çizimi):

- Gönderilmiş ve alıcı tarafından onaylanmış baytlar; bunların sonuncusu "son onaylanan bayt" (LastByteAcked).
- Gönderilmiş ama henüz onaylanmamış, yolda olan baytlar; gönderici bunların ACK'ini bekler. Bunların sonuncusu "son gönderilen bayt" (LastByteSent).
- Kullanılabilir ama henüz gönderilmemiş baytlar.

Gönderilmiş-onaylanmamış kısım ile kullanılabilir-gönderilmemiş kısmın toplamına tıkanıklık penceresi (congestion window, `cwnd`) denir. TCP göndericisi şu kısıtı sağlar:

$$\text{LastByteSent} - \text{LastByteAcked} \leq \text{cwnd}$$

> **Ders sonrası not:** Hoca 00:47:36'da "son onaylanan bayt `cwnd` boyutundan küçük olmalıdır" dedi. Kısıtın doğru biçimi, son gönderilen bayt ile son onaylanan bayt arasındaki farkın (yoldaki onaysız veri miktarının) `cwnd`'yi aşmamasıdır.

`cwnd`'nin boyutu, gözlenen ağ tıkanıklığına göre dinamik olarak ayarlanır; ölçülen RTT'lere, paket kayıplarına ve yeniden iletimlere göre ayarlanır.

TCP'nin gönderme davranışı kabaca şöyledir: `cwnd` bayt gönder, bir RTT boyunca ACK'leri bekle, sonra yeniden gönder. Buna göre:

$$\text{TCP hızı} \approx \frac{\text{cwnd}}{RTT} \ \text{bayt/s}$$

## 6. Yavaş Başlangıç ve Tıkanıklıktan Kaçınma

### 6.1 TCP yavaş başlangıç (slow start)

Bağlantı başladığında hız, ilk kayıp olayına kadar üstel olarak artırılır (ekrandan, 00:50:00):

- Başlangıçta `cwnd` = 1 MSS'tir.
- `cwnd` her RTT'de iki katına çıkarılır.
- Bu, alınan her ACK için `cwnd` artırılarak yapılır.

Slayttaki zaman çizgisinde Host A önce bir segment gönderir; ACK gelince iki segment gönderir; bunların ACK'leri gelince dört segment gönderir. Bu böyle 1, 2, 4, 8, 16 segment diye ilk paket kaybına kadar sürer. Özet: başlangıç hızı yavaştır, çünkü tek segmentle başlar; ama üstel olarak hızla yükselir.

### 6.2 Yavaş başlangıçtan tıkanıklıktan kaçınmaya geçiş

Soru: üstel artıştan doğrusal artışa ne zaman geçilmelidir? Cevap: `cwnd`, zaman aşımından önceki değerinin yarısına ulaştığında. Bu sınır `ssthresh` (slow start threshold, yavaş başlangıç eşiği) değişkeninde tutulur. Kayıp olayında `ssthresh`, kayıptan hemen önceki `cwnd`'nin yarısına ayarlanır. Pencere bu eşiğe kadar üstel, sonra doğrusal artar.

Hoca Reno ve Tahoe farkını burada yeniden hatırlattı: Reno üç kopya ACK'te pencereyi yarıya indirip doğrusal artışla devam eder; Tahoe ilk paket kaybında (zaman aşımı) pencereyi baştan başlatır. <!-- BELİRSİZ: 00:51:18-00:51:32 arası altyazı bozuk ("go to the trash", "TCP2 is"); Reno/Tahoe grafiğindeki ayrıntı tam okunamadı. -->

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross'taki grafikte iki sürüm 8. iletim turunda kayıp yaşar; Reno pencereyi yarıya indirip doğrusal devam ederken Tahoe 1 MSS'e düşüp yeniden yavaş başlangıç yapar. Her iki sürümde de `ssthresh` kayıptan önceki pencerenin yarısına çekilir.

### 6.3 TCP tıkanıklık denetimi sonlu durum makinesi

Hoca geçen haftalardaki sonlu durum makinesi çizimlerini hatırlatarak TCP tıkanıklık denetiminin üç durumunu gösterdi:

- **Yavaş başlangıç:** Bağlantı buradan başlar. `cwnd` `ssthresh`'ten büyük olunca tıkanıklıktan kaçınma durumuna geçilir.
- **Tıkanıklıktan kaçınma:** Pencere doğrusal artar. Zaman aşımı olursa yavaş başlangıca dönülür.
- **Hızlı kurtarma (fast recovery):** Bu durumdayken yeni ACK gelirse tıkanıklıktan kaçınmaya dönülür; zaman aşımı ve paket kaybı olursa yavaş başlangıca dönülür.

Makinede zaman aşımı geçişleri ve yeni ACK geçişleri bulunur. <!-- BELİRSİZ: 00:52:24'te hoca "tıkanıklık yoksa hızlı kurtarma" gibi bir ifade kullandı; hızlı kurtarmaya giriş koşulu altyazıdan net çıkmıyor. -->

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross'taki makinede hızlı kurtarmaya üç kopya ACK ile girilir: `ssthresh` = `cwnd`/2 yapılır, `cwnd` = `ssthresh` + 3 MSS olur ve eksik segment yeniden gönderilir. Zaman aşımında ise her durumdan `ssthresh` = `cwnd`/2 ve `cwnd` = 1 MSS ile yavaş başlangıca dönülür.

## 7. TCP CUBIC

Aradan sonra hoca AIMD'nin testere dişi davranışını hatırlattı: artış artımsaldır (doğrusal). $W_{max}$, tıkanıklık kaybının algılandığı en yüksek gönderme hızıdır. Kayıp algılanınca AIMD'ye göre hız $W_{max}/2$'ye düşer ve ilk paket kaybına kadar yeniden artar; kaybın türü Tahoe ve Reno'daki gibi üç kopya ACK ya da ilk zaman aşımıdır (ekrandan, 00:55:00).

Slayttaki soru şudur: kullanılabilir bant genişliğini "yoklamak" (probe) için AIMD'den daha iyi bir yol var mı? Sezgi (ekrandan, 01:15:00):

- $W_{max}$: tıkanıklık kaybının algılandığı gönderme hızı.
- Darboğaz bağlantının tıkanıklık durumu büyük olasılıkla pek değişmemiştir (slaytta "(?)" işaretiyle).

CUBIC'te kayıpta pencere yarıya indirildikten sonra önce $W_{max}$'a doğru daha hızlı çıkılır, sonra $W_{max}$'a daha yavaş yaklaşılır. Mantık şudur: kaybın $W_{max}$ hızında olduğunu biliyoruz; o hâlde $W_{max}$'a kadar hızlı artabiliriz, yaklaştıkça yavaş artarız. Slayttaki grafikte kırmızı eğri klasik TCP AIMD, mavi kesikli eğri TCP CUBIC'tir; CUBIC hızla yükseldiği için bu örnekte verimi daha yüksektir.

CUBIC'in işleyişinde $K$, TCP pencere boyutunun $W_{max}$'a ulaşacağı zaman noktasıdır. $K$ ayarlanabilir bir değerdir; kayba göre ayarlanabilir. Pencere, şimdiki zaman ile $K$ arasındaki uzaklığın küpüne bağlı olarak artırılır. <!-- BELİRSİZ: 01:17:08-01:17:33 arası altyazı bozuk ("kubelerin var", "2K"); küp fonksiyonunun ayrıntısı okunamadı. -->

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross slaytına göre CUBIC, $K$'den uzaktayken büyük, $K$'ye yaklaştıkça küçük (temkinli) artışlar yapar; pencere büyüklüğü zamanın $K$'ye uzaklığının küpüyle orantılı değişir.

İkinci grafikte $W_{max}$'a kadar CUBIC (kesikli) Reno'dan (kırmızı) daha yüksekte kalır. $W_{max}$ aşıldıktan sonra ise hocaya göre CUBIC, Reno'ya kıyasla biraz bant genişliği harcar gibi görünür. CUBIC Linux'ta varsayılan TCP protokolüdür ve popüler web sunucularında kullanılır.

## 8. Darboğaz Bağlantı ve Gecikme Tabanlı Denetim

### 8.1 TCP ve tıkanık "darboğaz bağlantı"

Ortadaki kırmızı yönlendiricinin tıkanık bağlantı olduğunu düşünelim, çünkü birçok yol onu paylaşır. Bu yönlendiricinin kuyruğu neredeyse hiç boşalmaz; ara sıra taşar ve bazı paketler kaybolur. Sonuçta darboğaz (bottleneck) bu yönlendiricide oluşur ve yönlendirici hep meşguldür.

Klasik TCP (AIMD) ve CUBIC, bir yönlendiricinin çıkışında paket kaybı oluşana kadar gönderme hızını artırır; bu yönlendirici darboğaz bağlantıdır (ekrandan, 01:20:00). O yönlendiricide tampon zaman zaman dolar, uzun gecikme olur ve yeniden iletim gerekir. Tıkanıklığı anlamak için tıkanık darboğaz bağlantıya odaklanmak yeterlidir; diğer yönlendiriciler unutulabilir.

Buradan iki sonuç çıkar:

- Gönderme hızını artırmak uçtan uca verimi artırmaz, çünkü darboğaz yönlendiricide sınır vardır.
- Gönderme hızını artırmak RTT'yi artırır: paketler tamponda daha uzun bekler, dolayısıyla gidiş-dönüş süresi büyür.

Hedef, uçtan uca "boruyu" tam dolu tutmak ama daha fazla doldurmamaktır. Daha fazla doldurmak bazı paketlerin düşmesi demektir.

### 8.2 Gecikme tabanlı TCP tıkanıklık denetimi

Gecikme tabanlı denetim, göndericiden alıcıya boruyu "tam yetecek kadar dolu, daha fazla değil" tutmayı amaçlar. Tıkanıksız verim, paket kaybı ve tıkanıklık olmadan elde edilebilecek bit/s hızıdır. <!-- BELİRSİZ: 01:21:27-01:22:22 arasında altyazı yok; tıkanıksız verimin (en küçük RTT ile) nasıl tanımlandığı kayıtta duyulamadı. -->

- Ölçülen verim = son RTT aralığında gönderilen bayt sayısı / ölçülen RTT.
- Ölçülen verim tıkanıksız verime çok yakınsa yol tıkanık değildir; `cwnd` doğrusal artırılır.
- Ölçülen verim tıkanıksız verimin çok altındaysa yolda bir sorun, yani tıkanıklık vardır; `cwnd` doğrusal azaltılır.

Fikir çok basittir: tıkanıklık denetimi kayba yol açmadan ya da kayba zorlamadan yapılır. Amaç verimi en yükseğe çıkarırken gecikmeyi düşük tutmak, yani tamponu yeterince dolu ama taşmayacak durumda tutmaktır. Kullanımdaki birçok TCP gecikme tabanlı yaklaşım izler; Google omurgasında (backbone) kullanılan BBR bunlardan biridir.

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross'ta tıkanıksız verim $\text{cwnd}/RTT_{min}$ olarak tanımlanır; $RTT_{min}$ gözlenen en küçük RTT'dir, yani kuyrukta beklemenin olmadığı durumdaki gidiş-dönüş süresidir.

## 9. Açık Tıkanıklık Bildirimi (ECN)

TCP gerçeklemeleri ağ destekli tıkanıklık denetimini çoğunlukla açık tıkanıklık bildirimi (Explicit Congestion Notification, ECN) bayrağıyla yapar (ekrandan, 01:25:00):

- IP başlığındaki ToS alanında bulunan iki bit, tıkanıklığı göstermek için ağ yönlendiricisi tarafından işaretlenir. İşaretlemenin hangi koşulda yapılacağını belirleyen politika ağ işletmecisi tarafından seçilir.
- Tıkanıklık bilgisi hedefe taşınır.

Slayttaki örnekte kaynak IP datagramını `ECN=10` ile gönderir; datagram tıkanık (kırmızı) yönlendiriciden geçince yönlendirici alanı `ECN=11` yapar ve datagram hedefe bu değerle ulaşır (ekrandan, 01:25:00). Hedef, alınan paketi onaylarken ACK segmentindeki TCP başlığında ECE bitini (ECN-Echo) 1 yapar ve böylece göndericiye tıkanıklığı bildirir. Gönderici de `cwnd`'yi küçültür.

Özetle: yönlendirici bayrağı "11" yaparak alıcıya tıkanıklığı haber verir; alıcı ACK'le göndericiye haber verir; gönderici `cwnd`'yi azaltır. Süreç hem IP başlığını (ECN bit işaretlemesi) hem de ACK'teki TCP başlığını (ECE bit işaretlemesi) kullanır. Hoca bu alanın geçen hafta incelenen TCP başlığında bulunduğunu hatırlattı.

## 10. TCP Adilliği

### 10.1 Adillik hedefi

Adillik hedefi şudur: $K$ adet TCP oturumu, bant genişliği $R$ olan aynı darboğaz bağlantıyı paylaşıyorsa her oturumun ortalama hızı $R/K$ olmalıdır. Çünkü $K$ farklı bağlantı darboğaz bağlantıyı paylaşmaktadır.

### 10.2 İki rakip oturumla AIMD

Slayttaki çizimde TCP bağlantısı 1 ve TCP bağlantısı 2 kapasitesi $R$ olan aynı darboğaz yönlendiriciyi paylaşır. Eksenler iki bağlantının verimidir; toplam en çok $R$ olabilir. Köşegen çizgi eşit bant genişliği paylaşımıdır: bağlantıyı iki bağlantının ideal, adil biçimde paylaştığı durum.

- Toplamalı artış, verim arttıkça eğimi 1 olan bir hareket verir (iki bağlantı aynı miktarda artar).
- Çarpımsal azalış verimi orantılı olarak azaltır (iki bağlantı da yarıya iner).

Bağlantılar art arda artırıp yarıya indirdikçe nokta eşit paylaşım çizgisine yaklaşır.

### 10.3 TCP adil midir?

**Soru:** TCP adil midir? **Cevap:** İdealleştirilmiş varsayımlar altında evet. Bu varsayımlar şunlardır: iki bağlantının RTT'si (gidiş-dönüş süresi) aynıdır ve oturum sayısı sabittir, oturumlar yalnız tıkanıklıktan kaçınma durumundadır. Bu iki varsayım altında TCP adildir.

### 10.4 Bütün ağ uygulamaları adil olmalı mı?

**Adillik ve UDP** (ekrandan, 01:30:00): Çoklu ortam uygulamaları çoğunlukla TCP kullanmaz, çünkü hızlarının tıkanıklık denetimiyle kısılmasını istemezler. Bunun yerine UDP kullanırlar: sesi ya da videoyu sabit hızda gönderir, paket kaybını tolere ederler. Hoca HTTP/3 ve IP üzerinden ses (Voice over IP) örneklerini verdi ve UDP kullanılırsa güvenilirliğin uygulama katmanında eklenebileceğini hatırlattı. Tıkanıklık denetimi kullanımını denetleyen bir "İnternet polisi" yoktur.

**Adillik ve paralel TCP bağlantıları** (ekrandan, 01:30:00): Bir uygulama iki uç arasında birden fazla paralel bağlantı açabilir; web tarayıcıları bunu yapar. Örneğin hızı $R$ olan ve üzerinde 9 bağlantı bulunan bir bağlantıda:

- Yeni bir uygulama 1 TCP bağlantısı isterse $R/10$ hız alır.
- Yeni bir uygulama 11 TCP bağlantısı isterse yaklaşık $R/2$ hız alır.

> **Ders sonrası not:** Bağlantı başına eşit pay varsayımıyla 11 bağlantılı uygulamanın payı tam olarak $\dfrac{11}{9+11}R = 0{,}55R$'dir; slayttaki $R/2$ yuvarlanmış değerdir.

## 11. Taşıma Katmanının Evrimi ve QUIC

### 11.1 TCP'nin farklı türleri

TCP ve UDP yaklaşık 40 yıldır temel taşıma katmanı protokolleridir ve hâlâ kullanılmaktadır. Belirli senaryolar için farklı TCP türleri (flavors) geliştirilmiştir. Hocanın saydığı zorluklar:

- **Uzun şişman borular (long fat pipes):** Büyük veri aktarımı gerektiren yollar. Yolda (in flight) çok sayıda paket bulunur ve bir kayıp boru hattını durdurur.
- **Kablosuz ağlar:** Ağın doğası gereği gürültülü kablosuz bağlantı ve hareketlilik yüzünden kayıp olur; TCP bunları tıkanıklık kaybı gibi yorumlar.

<!-- BELİRSİZ: 01:31:54-01:32:31 arası altyazı Türkçe ve bozuk; çok uzun RTT ve diğer senaryolara dair anlatım okunamadı. -->

Araştırmacılar bu sorunlara çözüm arar. Eğilimlerden biri, taşıma katmanı işlevlerini uygulama katmanına taşımaktır; bazı çözümler uygulama katmanında bulunabilir.

### 11.2 HTTP/3 ve QUIC

HTTP/1 ve HTTP/1.1, güvenilir veri aktarımına dayandığı için TCP kullanır. HTTP/3 ise UDP kullanır; güvenilirlik uygulama katmanında sağlanır. HTTP/3 bunun için QUIC'i kullanır.

QUIC (Quick UDP Internet Connections), UDP üzerinde çalışan bir uygulama katmanı protokolüdür (ekrandan, 01:35:00):

- HTTP'nin başarımını artırır.
- Birçok Google sunucusunda ve uygulamasında (Chrome, mobil YouTube uygulaması) kullanılmaktadır.

QUIC güvenilir olmayan UDP üzerinde güvenilir veri aktarımı sağlar. Hoca UDP'nin çok hızlı olduğunu ve QUIC ile HTTP/3'ün HTTP başarımını artırdığını söyledi.

Slayttaki katman karşılaştırması (ekrandan, 01:35:00):

```text
                HTTP/2 over TCP         HTTP/2 over QUIC over UDP
Application     HTTP/2                  HTTP/2 (slimmed)  \
                TLS                     QUIC              /  HTTP/3
Transport       TCP                     UDP
Network         IP                      IP
```

HTTP/3'te HTTP/2 protokolü biraz inceltilmiştir. QUIC, TLS'yi (Transport Layer Security) içerir ve UDP'nin üzerine güvenilirlik ekler.

> **Ders sonrası not:** Hoca 01:35:03'te TLS'yi "transmission line security" diye açtı; doğrusu Transport Layer Security'dir.

### 11.3 QUIC'in benimsediği yaklaşımlar

QUIC, taşıma katmanı bölümünde incelenen bağlantı kurma, hata denetimi ve tıkanıklık denetimi yaklaşımlarını uygulama katmanında benimser, çünkü UDP kullanır.

- **Hata ve tıkanıklık denetimi:** TCP'nin kayıp algılama ve tıkanıklık denetimini bilen okuyucular QUIC'te iyi bilinen TCP algoritmalarına paralel algoritmalar bulur.

> **Hocanın vurgusu:** Bu algoritmalar TCP'dekilere paraleldir, ama QUIC'te uygulama katmanında geliştirilmiştir; bunu unutmayın.

- **Bağlantı kurma:** Güvenilirlik, tıkanıklık denetimi, kimlik doğrulama, şifreleme ve durum kurulumu tek RTT'de yapılır.
- **Çoğullama:** Birden çok uygulama katmanı akışı (stream) tek bir QUIC bağlantısı üzerinde çoğullanır. Her akışın ayrı güvenilir veri aktarımı vardır; güvenlik ve tıkanıklık denetimi ortaktır.

### 11.4 Bağlantı kurma: TCP + TLS ve QUIC

TCP ile TLS kullanıldığında iki el sıkışma gerekir: biri TCP bağlantısı için, biri güvenlik (TLS) için. Bu el sıkışmalar ardışık yapılır. QUIC'te ise UDP üzerinde güvenlik dahil tek bir QUIC el sıkışması yeterlidir. Böylece bir el sıkışma, sonuç olarak bir RTT kazanılır.

> **Ders sonrası not:** Hoca 01:37:08'de geleneksel TCP bağlantısında "üç ardışık el sıkışma" olduğunu söyledi. Hemen önceki anlatımıyla tutarlı olan ve Kurose-Ross slaytında büyük olasılıkla yer alan ifade, TCP + TLS için iki ardışık el sıkışmadır.

### 11.5 Paralel akışlar ve satır başı engellemesi

QUIC akışları paraleldir; satır başı engellemesi (head-of-line blocking) olmaz. Hocanın anlattığı karşılaştırma: tek bağlantı üzerinde üç GET isteği (TLS şifreli) gönderildiğini düşünelim.

- HTTP/1.1'de istekler tek TCP bağlantısında sıralıdır. Bir GET'te hata olursa, arkasındaki istekler onun başarıyla tamamlanmasını bekler; üçüncü GET ancak sonra ilerleyebilir.
- HTTP/2 ve QUIC'te her GET ayrı bir QUIC akışında paralel gider. Bir akışta hata olsa da diğerleri ilerler; üçüncü GET bu sırada alınabilir. Alıcı tarafta parçalar yeniden birleştirilir.

Bu nedenle QUIC ile HTTP/2'de satır başı engellemesi yoktur. Ders bu konuyla, taşıma katmanı bölümünün sonunda bitti.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00; çözüm derste sözlü, 00:22:48): Kapasitesi $R$ olan, sonsuz paylaşılan çıkış tamponlu tek bir yönlendiriciyi iki gönderici (Host A ve Host B) paylaşıyor. Her bağlantının ulaşabileceği en büyük verim nedir ve $\lambda_{in}$ bu değere yaklaşınca gecikme nasıl değişir?

> **Çözüm (derste verildi):** İki akış bağlantıyı paylaştığı için her birinin verimi en çok $R/2$'dir. $\lambda_{in} < R/2$ iken $\lambda_{out} = \lambda_{in}$; $\lambda_{in} > R/2$ olunca verim $R/2$'de doyar. $\lambda_{in}$ $R/2$'ye yaklaştıkça paketler kuyrukta beklediği için gecikme sonsuza gider.

**Soru 2** (ekrandan, 00:30:00): Sonlu tamponlu senaryoda $\lambda_{in}$ ile $\lambda'_{in}$ arasındaki fark nedir ve gönderici $R/2$ hızında gönderirken verim neden $R/2$'nin altında kalır?

> **Çözüm (derste verildi):** $\lambda_{in}$ özgün veri hızı, $\lambda'_{in}$ özgün veri artı yeniden iletilen veri hızıdır. $R/2$ hızında gönderirken bazı paketler dolu tampon yüzünden düştüğü için gerekli yeniden iletimdir; bağlantının bir kısmı aynı verinin kopyalarına harcanır ("wasted" kapasite), bu yüzden alıcıya ulaşan faydalı veri $R/2$'nin altında kalır.

**Soru 3** (ekrandan, 00:45:00): TCP'de çarpımsal azalış, kaybın nasıl algılandığına göre nasıl farklılaşır?

> **Çözüm (derste verildi):** Kayıp üç kopya ACK ile algılanırsa gönderme hızı yarıya indirilir (TCP Reno). Kayıp zaman aşımıyla algılanırsa hız 1 MSS'e indirilir (TCP Tahoe).

**Soru 4** (ekrandan, 00:50:00): TCP yavaş başlangıçta `cwnd` = 1 MSS ile başlanıyor ve kayıp olmuyor. İlk beş RTT'de gönderilen segment sayıları nedir?

> **Çözüm (derste verildi):** `cwnd` her RTT'de iki katına çıktığı için (her ACK'te +1 MSS) segment sayıları sırasıyla 1, 2, 4, 8, 16'dır. Başlangıç yavaştır ama artış üsteldir.

**Soru 5** (ekrandan, 00:55:00 ve 01:15:00): Kullanılabilir bant genişliğini yoklamak için AIMD'den daha iyi bir yol var mı?

> **Çözüm (derste verildi):** TCP CUBIC: kaybın $W_{max}$ hızında olduğu ve darboğazın durumunun büyük olasılıkla pek değişmediği bilindiği için, pencere yarıya indikten sonra $W_{max}$'a önce hızlı, yakınında yavaş yaklaşılır. Bu, AIMD'nin doğrusal tırmanışına göre daha yüksek ortalama verim sağlar.

**Soru 6** (ekrandan, 01:25:00): ECN'de kaynak datagramı `ECN=10` ile gönderiyor ve datagram tıkanık bir yönlendiriciden geçiyor. Tıkanıklık bilgisi göndericiye nasıl ulaşır?

> **Çözüm (derste verildi):** Tıkanık yönlendirici IP başlığının ToS alanındaki iki ECN bitini `11` yapar. Hedef bunu görünce ACK segmentinin TCP başlığındaki ECE bitini 1 yaparak göndericiye bildirir; gönderici `cwnd`'yi küçültür.

**Soru 7** (derste sözlü, 01:28:07): TCP adil midir?

> **Çözüm (derste verildi):** İdealleştirilmiş varsayımlar altında evet: bağlantıların RTT'leri aynıysa ve oturum sayısı sabitse (oturumlar yalnız tıkanıklıktan kaçınma durumundaysa) AIMD bağlantıları eşit paylaşıma götürür; $K$ oturumun her biri ortalama $R/K$ alır.

**Soru 8** (ekrandan, 01:30:00): Hızı $R$ olan ve üzerinde 9 bağlantı bulunan bir bağlantıda yeni bir uygulama 1 TCP bağlantısı isterse ne kadar hız alır? 11 TCP bağlantısı isterse?

> **Çözüm (derste verildi):** 1 bağlantıyla toplam 10 bağlantı olur, uygulama $R/10$ alır. 11 bağlantıyla toplam 20 bağlantı olur, uygulama $11R/20 = 0{,}55R$, yani yaklaşık $R/2$ alır (slayt $R/2$ diye verir).

## Dersin Toparlaması

Ders, tıkanıklığın akış denetiminden farklı, ağın kendisine ait bir sorun olduğunu göstererek başladı. Üç senaryo tıkanıklığın maliyetlerini adım adım ortaya koydu: sonsuz tamponda bile kapasiteye yaklaşınca gecikme sonsuza gider; tampon sonlu olunca yeniden iletimler ve gereksiz kopyalar kapasite harcar; çok sekmeli ağda aşağı akışta düşen paketler yukarı akışın emeğini boşa çıkarır ve verim sıfıra inebilir. Ardından uçtan uca ve ağ destekli denetim yaklaşımları ayrıldı.

İkinci kısımda TCP'nin uçtan uca tıkanıklık denetimi incelendi: AIMD'nin testere dişi davranışı, Reno ve Tahoe farkı, `cwnd` kısıtı ve hızın yaklaşık `cwnd`/RTT olması, yavaş başlangıç ve `ssthresh` ile tıkanıklıktan kaçınmaya geçiş. Sonra AIMD'nin alternatifleri görüldü: $W_{max}$ bilgisini kullanan CUBIC, darboğazda kuyruk oluşturmadan boruyu dolu tutmayı amaçlayan gecikme tabanlı yaklaşım (BBR) ve yönlendirici işaretlemesine dayanan ECN. Adillik tartışması, TCP'nin ideal varsayımlar altında adil olduğunu ama UDP ve paralel bağlantıların bunu bozabileceğini gösterdi. Bölüm, taşıma katmanı işlevlerini UDP üzerinde uygulama katmanına taşıyan QUIC ve HTTP/3 ile kapandı. Taşıma katmanı bölümü bu dersle tamamlandı; hoca sonraki derste ağ katmanına başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
