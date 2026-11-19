# Ders 7 Çalışma Özeti

## Genel Konular

- Tıkanıklık (congestion) kavramı ve akış denetiminden farkı
  - Tıkanıklık, ağdaki çok sayıda kaynağın ağın kaldırabileceğinden fazla veriyi çok hızlı göndermesidir. Hoca bunu kapasitesinden fazla aracın bulunduğu bir yola benzetti.
  - Akış denetimi bir gönderici ile bir alıcı arasındadır: tek gönderici alıcıyı boğmasın diye hızını ayarlar. Tıkanıklık denetimi ise ağın kendisini ilgilendirir: birçok gönderici aynı yönlendiricileri doldurur.
  - Belirtileri: yönlendirici tamponlarında bekleme yüzünden uzun gecikme ve tampon taşması yüzünden paket kaybı.
  - Hoca tıkanıklık denetimini ağların çözülmesi gereken en önemli (ilk 10) problemlerinden biri olarak tanıttı.
- Tıkanıklığın nedenleri ve maliyetleri: senaryo 1 (sonsuz tampon)
  - İki gönderici (Host A, Host B), iki alıcı, tek yönlendirici; çıkış bağlantısı kapasitesi $R$; paylaşılan çıkış tamponu sonsuz kabul edilir (ekrandan, 00:20:00).
  - $\lambda_{in}$ uygulamanın giriş hızı, $\lambda_{out}$ alıcıdaki çıkış hızı (verimlilik, throughput). Tampon sonsuz olduğu için yeniden iletim gerekmez.
  - Her bağlantının alabileceği en büyük verim $R/2$'dir. $\lambda_{in} < R/2$ iken $\lambda_{out} = \lambda_{in}$ (doğrusal); $\lambda_{in}$ $R/2$'yi aşınca verim $R/2$'de doyar.
  - $\lambda_{in}$ $R/2$'ye yaklaştıkça kuyrukta bekleme yüzünden gecikme sonsuza gider.
- Senaryo 2 (sonlu tampon)
  - Tek yönlendirici, sonlu paylaşılan çıkış tamponu (ekrandan, 00:25:00). Tampon dolunca paket düşürülür; göndericinin taşıma katmanı kopyayı tuttuğu için zaman aşımından sonra paketi yeniden gönderir.
  - $\lambda_{in}$ özgün veri hızı, $\lambda'_{in}$ özgün veri artı yeniden iletilen veri hızıdır (offered load); $\lambda'_{in} \geq \lambda_{in}$ (ekrandan, 00:30:00).
  - İdeal durum (tam bilgi): gönderici yalnız tampon boşken gönderir; kayıp olmaz, eğri $R/2$'ye kadar doğrusaldır.
  - "Bir miktar tam bilgi" durumu: paketler dolu tampon yüzünden kaybolabilir, gönderici yalnız kaybolduğunu bildiği paketi yeniden gönderir. $R/2$ hızında gönderirken bazı paketler gerekli yeniden iletimdir; verim $R/2$'nin altında kalır, aradaki fark yeniden iletimle "harcanan" kapasitedir (ekrandan, 00:30:00).
  - Gerçekçi durum: paketler kuyrukta uzun beklediği için erken zaman aşımı olur, gönderici aynı paketi iki kez gönderir ve alıcıya gereksiz kopyalar ulaşır. Verim daha da düşer; kayıp, hem gerekli yeniden iletimlerin hem de gereksiz kopyaların harcadığı kapasitedir.
- Senaryo 3 (çok sekmeli yollar)
  - Dört gönderici, çok sekmeli (multi-hop) yollar, her yönlendiricide sonlu paylaşılan çıkış tamponu, zaman aşımı/yeniden iletim (ekrandan, 00:35:00).
  - Örnek: Host A'dan Host C'ye giden kırmızı akış iki yönlendiriciden geçer; ortadaki yönlendirici başka bir akışla (Host D'den Host B'ye) paylaşılır.
  - Kırmızı akışın $\lambda'_{in}$ değeri büyüdükçe üstteki kuyruğa gelen mavi paketlerin hepsi düşürülür; bağlantı kapasitesini kırmızı trafik tüketir.
  - Ek maliyet: paket aşağı akışta (downstream) düşürülürse o paket için yukarı akışta harcanan iletim kapasitesi ve tampon boşa gider. En kötü durumda verim sıfıra iner.
- Tıkanıklığın maliyetleri: özet (insights)
  - Verim kapasiteyi asla aşamaz.
  - Kapasiteye yaklaşıldıkça gecikme artar.
  - Kayıp ve yeniden iletim etkin verimi düşürür.
  - Gereksiz kopyalar etkin verimi daha da düşürür.
  - Aşağı akışta kaybolan paketler için yukarı akış kapasitesi ve tamponu boşa harcanır.
- Tıkanıklık denetimine yaklaşımlar
  - Uçtan uca tıkanıklık denetimi: ağdan açık geri bildirim yoktur; tıkanıklık gözlenen kayıp ve gecikmeden çıkarılır (inferred). TCP'nin yaklaşımı budur (ekrandan, 00:40:00).
  - Ağ destekli tıkanıklık denetimi: yönlendiriciler, tıkanık yönlendiriciden geçen akışların gönderen ve alan uçlarına doğrudan geri bildirim verir. Bu geri bildirim tıkanıklık düzeyini gösterebilir ya da gönderme hızını açıkça belirleyebilir. Örnekler: TCP ECN, ATM, DECbit protokolleri.
- TCP tıkanıklık denetimi: AIMD
  - Toplamalı artış, çarpımsal azalış (Additive Increase Multiplicative Decrease). Gönderici, kayıp olana kadar gönderme hızını artırır, kayıp olayında azaltır. Hızın zamana göre grafiği testere dişi (sawtooth) biçimindedir.
  - Toplamalı artış: kayıp algılanana kadar her RTT'de hız 1 MSS (maximum segment size, en büyük segment boyutu) artırılır.
  - Çarpımsal azalış (ekrandan, 00:45:00):
    - Üç kopya ACK ile algılanan kayıpta hız yarıya iner (TCP Reno).
    - Zaman aşımı ile algılanan kayıpta hız 1 MSS'e iner (TCP Tahoe).
  - Neden AIMD: dağıtık ve eşzamansız bir algoritmadır; ağ genelinde tıkanık akış hızlarını en iyilediği gösterilmiştir; basittir ve istenen kararlılık özelliklerine sahiptir.
- Tıkanıklık penceresi (cwnd)
  - Gönderici dizisinde: onaylanmış baytlar, gönderilmiş ama onaylanmamış baytlar (yolda, in flight), kullanılabilir ama gönderilmemiş baytlar. Gönderilmiş-onaylanmamış ve kullanılabilir kısmın toplamı `cwnd`'dir.
  - Kural: $\text{LastByteSent} - \text{LastByteAcked} \leq \text{cwnd}$.
  - `cwnd` gözlenen tıkanıklığa göre dinamik olarak ayarlanır (TCP tıkanıklık denetimini gerçekleyen değişken budur).
  - Yaklaşık gönderme davranışı: `cwnd` bayt gönder, bir RTT boyunca ACK bekle, sonra yeniden gönder. Buna göre TCP hızı $\approx \dfrac{\text{cwnd}}{RTT}$ bayt/s.
- TCP yavaş başlangıç (slow start)
  - Bağlantı başlarken hız ilk kayıp olayına kadar üstel artırılır: başta `cwnd` = 1 MSS, her RTT'de `cwnd` iki katına çıkar; bu, alınan her ACK için `cwnd` bir artırılarak yapılır (ekrandan, 00:50:00).
  - Gönderilen segment sayısı RTT başına 1, 2, 4, 8, 16 ... diye gider: başlangıç hızı düşüktür ama üstel olarak hızla yükselir.
- Yavaş başlangıçtan tıkanıklıktan kaçınmaya (congestion avoidance) geçiş
  - Üstel artış, `cwnd` zaman aşımından önceki değerinin yarısına ulaşınca doğrusal artışa döner.
  - Bu sınır `ssthresh` değişkeniyle tutulur. Kayıp olayında `ssthresh`, kayıptan hemen önceki `cwnd`'nin yarısına ayarlanır.
  - TCP tıkanıklık denetimi sonlu durum makinesi: yavaş başlangıç, tıkanıklıktan kaçınma ve hızlı kurtarma (fast recovery) durumları. `cwnd` > `ssthresh` olunca tıkanıklıktan kaçınmaya geçilir; zaman aşımında yavaş başlangıca dönülür; hızlı kurtarmada yeni ACK gelince tıkanıklıktan kaçınmaya dönülür.
- TCP CUBIC
  - Soru: kullanılabilir bant genişliğini "yoklamak" için AIMD'den daha iyi bir yol var mı? (ekrandan, 00:55:00)
  - Sezgi: $W_{max}$, tıkanıklık kaybının algılandığı gönderme hızıdır; darboğaz bağlantının tıkanıklık durumu büyük olasılıkla pek değişmemiştir (ekrandan, 01:15:00).
  - Kayıpta pencereyi yarıya indirdikten sonra önce $W_{max}$'a doğru hızlı, $W_{max}$'a yaklaşınca yavaş artırılır. AIMD'ye göre ortalama verim daha yüksektir.
  - $K$: pencerenin $W_{max}$'a ulaşacağı zaman noktasıdır; $K$ ayarlanabilir bir değerdir. Artış, şimdiki zaman ile $K$ arasındaki uzaklığın küpüne bağlıdır. <!-- BELİRSİZ: 01:17:08-01:17:33 arası altyazı bozuk ("kubelerin var", "2K"); küp fonksiyonunun ayrıntısı altyazıdan okunamadı. -->
  - CUBIC Linux'ta varsayılan TCP'dir ve popüler web sunucularında kullanılır.
- TCP ve tıkanık "darboğaz bağlantı" (bottleneck link)
  - Klasik TCP ve CUBIC, bir yönlendiricinin çıkışında (darboğaz bağlantı) kayıp oluşana kadar gönderme hızını artırır (ekrandan, 01:20:00). Tıkanıklığı anlamak için bu darboğaza odaklanmak yeterlidir.
  - Darboğazda kuyruk neredeyse hiç boşalmaz, ara sıra taşar ve paket kaybolur.
  - Gönderme hızını artırmak uçtan uca verimi artırmaz; yalnız kuyrukta beklemeyi ve dolayısıyla RTT'yi artırır.
  - Hedef: uçtan uca "boruyu" tam dolu tutmak ama daha fazla doldurmamak.
- Gecikme tabanlı tıkanıklık denetimi
  - Ölçülen verim = son RTT aralığında gönderilen bayt / ölçülen RTT.
  - Ölçülen verim tıkanıksız verime çok yakınsa `cwnd` doğrusal artırılır (yol tıkanık değil); çok altındaysa `cwnd` doğrusal azaltılır (yolda tıkanıklık var). <!-- BELİRSİZ: 01:21:27-01:22:22 arasında altyazı yok; tıkanıksız verimin (RTTmin ile) nasıl tanımlandığı kayıtta duyulamadı. -->
  - Amaç, kayba zorlamadan tıkanıklığı denetlemek: verimi en yükseğe çıkarırken gecikmeyi düşük tutmak. Google omurgasında kullanılan BBR gecikme tabanlı bir yaklaşımdır.
- Açık tıkanıklık bildirimi (ECN)
  - TCP gerçeklemeleri ağ destekli denetimi çoğunlukla ECN ile yapar (ekrandan, 01:25:00).
  - IP başlığındaki ToS alanında iki bit, tıkanıklığı göstermek için ağ yönlendiricisi tarafından işaretlenir; işaretleme politikasını ağ işletmecisi seçer. Ekranda gönderici datagramı `ECN=10` ile yollar, tıkanık yönlendirici bunu `ECN=11` yapar (ekrandan, 01:25:00).
  - Tıkanıklık bilgisi hedefe taşınır. Hedef, ACK segmentinde TCP başlığındaki ECE bitini 1 yaparak göndericiye bildirir; gönderici `cwnd`'yi küçültür.
  - Yani hem IP başlığı (ECN bit işaretlemesi) hem TCP başlığı (ECE bit işaretlemesi) kullanılır.
- TCP adilliği (fairness)
  - Hedef: $K$ TCP oturumu bant genişliği $R$ olan aynı darboğaz bağlantıyı paylaşıyorsa her biri ortalama $R/K$ hız almalıdır.
  - İki rakip oturum: toplamalı artış verim arttıkça eğimi 1 olan bir hareket verir, çarpımsal azalış verimi orantılı azaltır. Bu döngü iki bağlantıyı eşit paylaşım çizgisine yaklaştırır.
  - TCP adil midir? İdealleştirilmiş varsayımlar altında evet: iki bağlantının RTT'si aynıdır ve oturum sayısı sabittir, oturumlar yalnız tıkanıklıktan kaçınma durumundadır.
  - UDP ve adillik: çoklu ortam uygulamaları (örneğin IP üzerinden ses) çoğunlukla TCP kullanmaz; hızlarının tıkanıklık denetimiyle kısılmasını istemezler, sabit hızda gönderip kaybı tolere ederler. Tıkanıklık denetimi kullanımını denetleyen bir "İnternet polisi" yoktur (ekrandan, 01:30:00).
  - Paralel TCP bağlantıları: uygulama iki uç arasında birden çok bağlantı açabilir (web tarayıcıları böyle yapar). Hızı $R$ olan ve 9 bağlantının bulunduğu bağlantıda yeni uygulama 1 TCP isterse $R/10$, 11 TCP isterse $R/2$ alır (ekrandan, 01:30:00).
- Taşıma katmanı işlevselliğinin evrimi ve QUIC
  - TCP ve UDP yaklaşık 40 yıldır temel taşıma protokolleridir. Özel senaryolar için farklı TCP türleri geliştirilmiştir: büyük veri aktarımı yapan "uzun şişman borular" (long fat pipes, yolda çok paket, kayıp boru hattını durdurur), kablosuz ağlar (gürültü ve hareketlilik kaynaklı kayıp TCP tarafından tıkanıklık kaybı sanılır).
  - Eğilim: taşıma katmanı işlevlerini UDP üzerinde uygulama katmanına taşımak. HTTP/3 bunun örneğidir.
  - QUIC (Quick UDP Internet Connections): UDP üzerinde çalışan uygulama katmanı protokolü; HTTP başarımını artırır; birçok Google sunucusunda ve uygulamasında (Chrome, mobil YouTube uygulaması) kullanılır (ekrandan, 01:35:00).
  - Katman karşılaştırması (ekrandan, 01:35:00): HTTP/2 over TCP yığını HTTP/2, TLS, TCP, IP'dir. HTTP/2 over QUIC over UDP yığını HTTP/2 (inceltilmiş, slimmed), QUIC, UDP, IP'dir; HTTP/2 (slimmed) ve QUIC birlikte HTTP/3'ü oluşturur.
  - QUIC, bu bölümde görülen bağlantı kurma, hata denetimi ve tıkanıklık denetimi yaklaşımlarını uygulama katmanında benimser. TCP kayıp algılama ve tıkanıklık denetimini bilen biri QUIC'te bunlara paralel algoritmalar bulur.
  - Bağlantı kurma: güvenilirlik, tıkanıklık denetimi, kimlik doğrulama, şifreleme ve durum kurulumu tek RTT'de yapılır. TCP + TLS'de biri TCP, biri TLS için iki ardışık el sıkışma vardır; QUIC tek el sıkışmayla bir RTT kazandırır.
  - Akışlar: birden çok uygulama katmanı akışı tek QUIC bağlantısı üzerinde çoğullanır; her akışın ayrı güvenilir veri aktarımı vardır, güvenlik ve tıkanıklık denetimi ortaktır. Bu yüzden satır başı engellemesi (head-of-line blocking) olmaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tıkanıklık denetimi akış denetiminden tamamen farklıdır
  - Hoca bunu ders başında birkaç kez tekrarladı: akış denetimi tek gönderici ve tek alıcı arasındadır, tıkanıklık denetimi çok sayıda göndericinin ağa fazla veri yüklemesiyle ilgilidir.
- Üç senaryonun karşılaştırması
  - Hoca senaryoları iki kez (önce tek tek, sonra "insights" slaytında) özetledi: sonsuz tamponda sınır $R/2$ ve sonsuz gecikme; sonlu tamponda yeniden iletim kaybı; gerçekçi durumda kopyalar; çok sekmede verimin sıfıra kadar inmesi.
  - "Bu üç senaryoyu izleyerek tıkanıklığın nedenlerini görebilirsiniz" dedi.
- AIMD testere dişi davranışı ve Reno/Tahoe farkı
  - Reno üç kopya ACK'te yarıya indirir, Tahoe zaman aşımında 1 MSS'e indirir. Hoca bu farkı CUBIC anlatımında yeniden hatırlattı.
- Darboğaz bağlantıda hızı artırmak verimi değil RTT'yi artırır
  - Amaç boruyu "tam dolu ama daha fazla değil" tutmaktır.
- QUIC'in uygulama katmanında olduğu
  - Hoca QUIC'in TCP'ye benzer algoritmalar kullanmasına karşın uygulama katmanında geliştirildiğini "unutmayın" diye vurguladı.

## Kısa Tekrar Notları

- Tıkanıklık: çok kaynak, ağın kaldıramayacağı kadar veri; belirtisi uzun gecikme ve paket kaybı.
- Senaryo 1: sonsuz tampon, en büyük verim $R/2$, $\lambda_{in} \to R/2$ iken gecikme $\to \infty$.
- Senaryo 2: sonlu tampon, $\lambda'_{in}$ = özgün + yeniden iletim; yeniden iletim ve gereksiz kopyalar kapasite harcar.
- Senaryo 3: çok sekme; aşağı akışta düşen paketin yukarı akış kapasitesi boşa gider; verim sıfıra inebilir.
- Uçtan uca denetim (TCP): geri bildirim yok, kayıp ve gecikmeden çıkarım. Ağ destekli: yönlendirici geri bildirimi (ECN, ATM, DECbit).
- AIMD: her RTT'de +1 MSS; üç kopya ACK'te yarıya (Reno), zaman aşımında 1 MSS'e (Tahoe).
- $\text{LastByteSent} - \text{LastByteAcked} \leq \text{cwnd}$; TCP hızı $\approx \text{cwnd}/RTT$.
- Yavaş başlangıç: `cwnd` = 1 MSS'ten başlar, her RTT iki katına çıkar (her ACK'te +1); `ssthresh`'e gelince doğrusal artış.
- Kayıpta `ssthresh` = kayıptan önceki `cwnd` / 2.
- CUBIC: $W_{max}$'a önce hızlı, yakınında yavaş yaklaş; Linux varsayılanı.
- Gecikme tabanlı: ölçülen verim tıkanıksıza yakınsa `cwnd` doğrusal artar, değilse doğrusal azalır; BBR (Google).
- ECN: IP ToS alanında 2 bit, yönlendirici 11 yapar; alıcı TCP ACK'inde ECE bitiyle göndericiye bildirir.
- Adillik: $K$ oturum $\Rightarrow$ her biri $R/K$; aynı RTT ve sabit oturum sayısı varsayımıyla TCP adildir.
- 9 bağlantılı $R$ hızında hatta: 1 yeni TCP $\Rightarrow R/10$; 11 yeni TCP $\Rightarrow$ yaklaşık $R/2$.
- QUIC: UDP üzerinde uygulama katmanı; HTTP/3 = HTTP/2 (slimmed) + QUIC; tek el sıkışma (1 RTT); akışlar paralel, HOL engellemesi yok.

## Detaylı Açıklamalar

- Senaryoların ortak fikri
  - Üç senaryo aynı soruya giderek daha gerçekçi koşullarda yanıt verir: gönderici hızını artırınca alıcıya ulaşan faydalı veri (verim) ne olur? Sonsuz tamponda sorun yalnız gecikmedir; verim $R/2$'de doyar ama hiçbir şey kaybolmaz. Tampon sonlu olunca düşen paketler yeniden gönderilir ve bağlantı kapasitesinin bir kısmı aynı verinin ikinci kopyasına harcanır. Paketler kuyrukta uzun bekleyip zamanlayıcı erken dolunca hiç kaybolmamış paketler de yeniden gönderilir; alıcıya gereksiz kopyalar gelir. Çok sekmeli ağda ise bir paket yolun sonlarında düşürülürse, ondan önceki yönlendiricilerde harcanan iş de boşa gider; yük çok artınca yönlendiriciler yalnız sonunda düşecek paketleri taşır ve verim sıfıra iner.
  - Bu yüzden tıkanıklık denetimi, akış denetimi gibi zorunludur: göndericiler ağın durumuna göre hızlarını düşürmelidir.
- TCP'nin tıkanıklık penceresini nasıl yönettiği
  - TCP ağdan açık bir bilgi almadan (uçtan uca yaklaşım) yalnız ACK'lerden ve kayıplardan yola çıkar. `cwnd` bir RTT içinde yolda bulunabilecek onaysız bayt miktarını sınırlar, bu yüzden hız yaklaşık `cwnd`/RTT olur.
  - Bağlantı başında `cwnd` 1 MSS'tir ve her ACK'te 1 MSS artar; her RTT'de pencere iki katına çıktığı için artış üsteldir (1, 2, 4, 8, 16 segment). `cwnd`, `ssthresh`'e ulaşınca tıkanıklıktan kaçınma durumuna geçilir ve her RTT'de yalnız 1 MSS artırılır (toplamalı artış). Kayıp olunca `ssthresh` kayıptan önceki pencerenin yarısına çekilir; Reno üç kopya ACK'te pencereyi yarıya indirir, Tahoe zaman aşımında 1 MSS'e düşer ve yavaş başlangıca döner.
  - Sonuçta pencerenin zamana göre grafiği testere dişidir: doğrusal tırmanış ve kayıpta ani düşüş.
- CUBIC'in AIMD'den farkı
  - AIMD kayıptan sonra $W_{max}/2$'den yeniden doğrusal tırmanır ve kaybın olduğu $W_{max}$ düzeyine yavaş ulaşır. CUBIC ise kaybın $W_{max}$'ta olduğunu bildiği için oraya kadar hızla çıkar, $W_{max}$ yakınında temkinli artar. Böylece zamanın daha büyük kısmında yüksek hızda kalır ve verimi artar. Hoca $W_{max}$ aşıldıktan sonra CUBIC'in Reno'ya göre biraz bant genişliği harcar gibi göründüğünü de belirtti.
- Kayıp tabanlı ve gecikme tabanlı denetim
  - Klasik TCP ve CUBIC kayba kadar hızlanır; bu da darboğaz kuyruğunu sürekli dolu tutar ve RTT'yi şişirir. Gecikme tabanlı yaklaşım ölçülen verimi tıkanıksız verimle karşılaştırır ve kayıp oluşmadan pencereyi ayarlar. Amaç kuyruğu doldurmadan boruyu dolu tutmaktır.
- ECN'nin işleyişi
  - Tıkanık yönlendirici paketi düşürmek yerine IP başlığındaki ECN bitlerini 11 yapar. Hedef bunu gördüğünde ACK'teki TCP ECE bitini işaretler; gönderici bu ACK'i alınca `cwnd`'yi küçültür. Böylece kayıp beklenmeden tıkanıklık haber verilir.
- QUIC neden uygulama katmanında?
  - Hoca, araştırmacıların TCP'nin özel senaryolardaki sorunlarına çözümü taşıma işlevlerini uygulama katmanına taşıyarak aradığını söyledi. QUIC, UDP'nin üzerine güvenilirlik, tıkanıklık denetimi ve şifrelemeyi uygulama katmanında ekler. TCP + TLS'de iki ardışık el sıkışma gerekirken QUIC bunları tek el sıkışmada birleştirir ve bir RTT kazandırır. HTTP/1.1'de bir isteğin kaybı arkasındaki istekleri bekletir (satır başı engellemesi); QUIC'te her GET ayrı akışta gittiği için bir akıştaki hata diğerlerini durdurmaz, parçalar alıcıda yeniden birleştirilir.
- Ders sonrası notlar
  - Hoca 00:35:02'de "Ethernet bağlantısız bir protokoldür" dedi; bağlamda kastedilen İnternet'in (IP katmanının) en iyi çaba (best effort), bağlantısız hizmetidir.
  - Hoca 01:35:03'te TLS'yi "transmission line security" diye açtı; doğrusu Transport Layer Security'dir.
  - Hoca 01:37:08'de geleneksel TCP bağlantısında "üç ardışık el sıkışma" dedi; hemen önce anlattığı gibi TCP + TLS'de büyük olasılıkla iki ardışık el sıkışma vardır (biri TCP, biri TLS), QUIC bunu teke indirir.
  - Paralel bağlantı örneğinde 11 TCP isteyen uygulamanın payı tam olarak $11/20\,R = 0{,}55R$'dir; slayttaki $R/2$ yuvarlanmış değerdir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
