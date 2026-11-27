# Ders 5 Çalışma Özeti

## Genel Konular

- Tıkanıklık (congestion) kavramı
  - Bir ağa planlanmış paket aktarım kapasitesinden fazla trafik verildiğinde, trafik sıkışıklığına benzer biçimde paketler gecikir, kaybolur ve en kötü durumda ağ hiçbir paketi ilerletemez hale gelir.
  - Ağ katmanının temel görevi paketi kaynaktan hedefe taşımaktır; bu yüzden tıkanıklığı önlemek ya da oluştuysa çözmek için ağ katmanında mekanizmalar bulunmalıdır.
  - Tıkanıklık kontrolü yalnız ağ katmanının işi değildir: bağlantı (link) katmanı, ağ katmanı ve taşıma katmanı birlikte tedbir alır. Slaytta "ağ ve taşıma katmanlarının ortak sorumluluğu" olduğu, bu bölümde ağ katmanı kısmına bakıldığı yazıyor (ekrandan, 00:05:00).
  - Bağlantı katmanı noktadan noktaya, ağ ve taşıma katmanları ise birden fazla atlama (hop) üzerinden uçtan uca çalışır.
- Proaktif (önleyici) ve reaktif yaklaşımlar
  - Proaktif (preventatif) yaklaşımlar tıkanıklık oluşmadan önce planlama ve tedbirle onun hiç oluşmamasını hedefler.
  - Reaktif yaklaşımlar tıkanıklık oluştuktan sonra devreye girip onu çözer.
  - İkisi arasında bir ödünleşim (trade-off) vardır: tıkanıklığı hiç yaşamamak için ağ kapasitesinin örneğin yüzde 70-80'i kullanılır, kalan dilim atıl kalır; atıl kapasiteyi kullanmaya kalkınca uygulamaların tepe (peak) noktaları üst üste geldiğinde tıkanıklık oluşur.
- Goodput eğrisi ve tıkanıklık çöküşü (ekrandan, 00:20:00)
  - Yatay eksen sunulan yük (offered load, paket/s), düşey eksen goodput (paket/s).
  - Goodput: hedefe zamanında ulaşan yararlı paket miktarı; throughput'tan farklı olarak tekrar gönderilen ve geç kalan paketleri saymaz.
  - Eğriler: ideal (kapasiteye kadar doğrusal, sonra kapasitede düz), istenen tepki (desirable response, kapasiteye asimptotik yaklaşır), tıkanıklık çöküşü (congestion collapse, belirli bir yükten sonra goodput hızla düşer).
  - Eğrilerin ayrıştığı bölge tıkanıklık başlangıcıdır (onset of congestion); kontrol burada yapılmalıdır.
- Yaklaşımların zaman ölçeği (ekrandan, 00:25:00)
  - Yavaştan (önleyici) hızlıya (reaktif) sıra: network provisioning, traffic-aware routing, admission control, traffic throttling, load shedding.
- Network provisioning (ağın planlanması)
  - Giriş hatlarının toplam kapasitesinin çıkış hatlarınca karşılanabilmesi gerekir.
  - Örnek: 48 adet 1 Gbit/s girişli bir katman 3 anahtar ve 4 adet 10 Gbit/s uplink: dördü de kullanılsa 40 Gbit/s'e karşı 48 Gbit/s vardır, 8 Gbit/s fark tamponlanmak zorundadır.
- Traffic-aware routing (ekrandan, 00:30:00)
  - Rota yalnız topolojiye göre değil trafiğe göre de seçilir; örnekte Batı-Doğu arasında CF ve EI olmak üzere iki geçiş vardır.
  - CF yüklenince trafik EI'ye, EI yüklenince yeniden CF'ye kayar; bu salınım (oscillation) sık olursa sürekli rota güncellemesi ve yeniden hesaplama maliyeti doğar.
  - Alternatif: bir yönde CF, diğer yönde EI kullanmak; ama gidiş ve dönüş gecikmeleri farklılaşır, gecikme ölçümü bozulur, gereksiz tekrar gönderimler tetiklenebilir.
- Admission control (kabul kontrolü)
  - Yeni trafiğe yalnız ağda yeterli kapasite varsa izin verilir; örneğin sanal devrelerle (virtual circuit).
  - Yol önceden bilinmelidir, yani bağlantı yönelimli yapı gerekir; datagram ağlarda neredeyse uygulanamaz.
- Traffic throttling (trafiği frenleme) (ekrandan, 00:40:00)
  - Tıkanan yönlendirici, paketleri işaretler (ECN, Explicit Congestion Notification); alıcı bu işareti göndericiye geri bildirir, gönderici hızını düşürür (ileri yönde bildirim, uçtan uca).
  - İkinci seçenek: yönlendirici geri yöndeki paketlerde bit işaretleyerek bir önceki yönlendiriciye haber verir; bu atlama atlama kaynağa kadar gider (geri yönde bildirim, hop-by-hop).
  - Bildirim ayrı paketle değil, mevcut paketin başlığındaki bitle taşınır (piggybacking); böylece ek trafik üretilmez.
- Load shedding (yük atma) (ekrandan, 00:50:00 ve 00:55:00)
  - Diğer yöntemler yetmezse ağ paketleri düşürür; uçtan uca ya da bağlantı bağlantı (link-by-link) yapılabilir.
  - Link-by-link hızlı rahatlama sağlar; uçtan uca daha geç etki eder ama tıkanıklığın asıl nedenini (aşırı trafik üreten kaynağı) daha iyi hedefler.
  - Hangi paketin düşürüleceği: süt (milk) yaklaşımında yeni paket değerlidir, eski düşürülür (video akışı); şarap (wine) yaklaşımında eski paket değerlidir, yeni düşürülür (dosya aktarımı).
- Hizmet kalitesine (QoS) geçiş (ekrandan, 01:00:00)
  - Sonraki bölümün başlıkları: application requirements, traffic shaping, packet scheduling, admission control, integrated services, differentiated services.

## Hocanın Özellikle Vurguladığı Kısımlar

- Network provisioning mühendisliğin asıl parçasıdır
  - Cihazları bağlamak herkesin yapabileceği iştir; kaç uygulamanın aynı anda, ne kadar süre, ne yoğunlukta trafik üreteceğini hesaplayıp maliyeti optimize ederek tıkanıklığı en aza indirmek mühendislik işidir.
- Goodput grafiğinde tıkanıklık başlangıcı bölgesi
  - Kontrol için ne yapılacaksa o bölgede yapılmalıdır; bir adım ötesi kontrolsüz tıkanıklıktır.
- Salınımda önemli olan periyottur
  - Rota değişimi uzun aralıklarla oluyorsa sorun büyük değildir; dakikalar mertebesindeyse yönlendiricilerin işlem gücü rota hesabına harcanır ve performans düşer.
- Tıkanıklık bildirimi için ayrı paket gönderilmez
  - Zaten tıkalı ağa ek trafik eklememek için başlıktaki ayrılmış bit kullanılır (piggybacking).
- Tıkanıklığın temel nedeni bir uygulamanın öngörülenden fazla trafik üretmesidir
  - Kalıcı çözüm için kaynağın yavaşlatılması gerekir; bu yüzden uçtan uca çözümler daha etkilidir.
- Admission control sanal devrede doğal, datagram ağda uygun değildir
  - Sanal devrede kabul kontrolü yapıldıysa ayrıca traffic throttling'e gerek kalmamalıdır; throttling ise datagram ağlarda ileri ya da geri yönde rahatça uygulanabilir.

## Kısa Tekrar Notları

- Tıkanıklık: sunulan yük kapasiteyi aşınca kayıp, gecikme ve tekrar gönderimle performansın düşmesi.
- Tıkanıklık kontrolü link, ağ ve taşıma katmanlarının ortak işidir.
- Proaktif: önceden planla, kapasitenin bir kısmı atıl kalır. Reaktif: oluşunca müdahale et.
- Goodput: zamanında hedefe ulaşan yararlı paketler. Eğriler: ideal, desirable response, congestion collapse.
- Sıra (yavaş/önleyici -> hızlı/reaktif): provisioning, traffic-aware routing, admission control, traffic throttling, load shedding.
- Traffic-aware routing'in riski salınımdır.
- Admission control bağlantı yönelimli (sanal devre) yapı ister.
- ECN: yönlendirici paketi işaretler, alıcı göndericiye bildirir.
- Geri yönde hop-by-hop bildirim de mümkündür; bildirimler piggybacking ile taşınır.
- Load shedding: link-by-link hızlı rahatlama, uçtan uca nedeni daha iyi hedefler. Boğulan yönlendiricinin gönderdiği bildirim choke paketidir.
- Süt: yeni paket değerli (akış). Şarap: eski paket değerli (dosya aktarımı).
- Admission control hem proaktif hem reaktif kullanılabilir; throttling ve load shedding yalnız tıkanıklık varken uygulanır.

## Detaylı Açıklamalar

- Tıkanıklık, yol trafiğine benzetilerek anlatıldı: yollar belirli bir kapasiteye göre planlanır; daha fazla araç çıkarsa hız düşer, süre uzar. Bilgisayar ağlarında da kağıt üzerinde tasarlanmış topolojinin bir paket aktarım kapasitesi vardır; bu aşılınca önce gecikme ve kayıp, sonra tam bir durma noktası görülebilir. Ev internet ve telefon servisleri de ortalama yoğunluğa (yüzde 70-80 doluluk) göre tasarlanır; doğal afet gibi herkesin aynı anda ulaşmaya çalıştığı durumlarda telefonların meşgul sesi bile veremediği bir kilitlenme yaşanır.
- Proaktif yaklaşımlarda uygulamalar "beyan usulü" çalışır: bir uygulama birim zamanda göndereceği bit miktarını bildirir. Ancak bu beyan, uygulamanın üretebileceği en üst trafiğe göre yapıldığı ve hiçbir uygulama bunu sürekli üretmediği için ağda kullanılmayan atıl bir kapasite kalır. Bu atıl kapasiteyi kullanmak istendiğinde ise çok sayıda uygulamanın tepe noktalarının çakıştığı anlarda toplam ihtiyaç ağ kapasitesini aşar.
- Tıkanıklıkta tekrar gönderim (retransmission) şöyle artar: bağlantı yönelimli iletişimde gönderici, onay gelmeyince paketin kaybolduğunu düşünüp yeniden gönderir; oysa paket yalnız yavaşlamış olabilir. Ağ açısından sonuç, içerideki paket sayısının artmasıdır. Bu yüzden ideal eğri pratikte görülemez; hatalar, kayıplar ve anlık sıçramalar salınım ve tıkanıklık üretir. Tıkanıklık kontrolünün hedefi, goodput'un kapasiteye asimptotik yaklaştığı istenen tepkiyi elde etmektir.
- Provisioning örneği: 48 adet 1 Gbit/s portu ve 4 adet 10 Gbit/s uplink'i olan bir katman 3 anahtarda giriş toplamı 48 Gbit/s, çıkış en fazla 40 Gbit/s'tir. Aradaki 8 Gbit/s ancak sınırlı süre tamponlanabilir. Bütçe nedeniyle uplink'lerin yalnız biri, ikisi ya da üçü kullanılırsa (10, 20, 30 Gbit/s) durum daha da kötüleşir. Daha hızlı uplink seçenekleri (25, 50, 100 Gbit/s) vardır ama maliyet getirir; doğru karar, eş zamanlı trafik üreten uygulama sayısı ve süresinin hesabına dayanır.
- Traffic-aware routing örneğinde topoloji Batı (A, B, C, D, E) ve Doğu (F, G, H, I, J) olarak ikiye ayrılmıştır; iki taraf C-F ve E-I bağlantılarıyla birleşir (ekrandan, 00:30:00). CF yoğunlaşıp eşik değerine yaklaşınca yönlendirme algoritması rota güncellemesi yayımlar ve trafik EI'ye kayar; bu kez EI dolar ve trafik CF'ye döner. Bu "pinpon" hali salınımdır. Dağıtık yönlendirmede (shortest path first, IS-IS) her değişiklik güncelleme yayımı ve Dijkstra'nın yeniden çalıştırılması demektir. Yönleri ayırmak (bir yön CF, diğer yön EI) da asimetrik gecikmeye yol açar: gidiş-dönüş süresi ikiye bölünerek hesaplandığında yanlış sonuç çıkar ve taşıma katmanı gereksiz tekrar gönderim yapabilir.
- Admission control slaytında "yeni trafik yükü yalnız ağın yeterli kapasitesi varsa kabul edilir; örneğin sanal devrelerle" ifadesi okundu. Örnekte A ile B arasında, üstte ve altta tıkanmış bölgeler varken, bunlardan geçmeyen ve yeterli kapasitesi olan bir sanal devre kurulur. <!-- BELİRSİZ: admission control slaytının şekli (yaklaşık 00:37:00) kareler arasında yok; şekil ayrıntısı yalnız altyazıdan aktarıldı. -->
- Traffic throttling'de bir yönlendiricinin çıkışındaki tıkanıklığı, girişinden gelen trafik oluşturur; bu yüzden paketlerin geldiği yönün tersine haber verilmelidir. En iyi yol kaynağı yavaşlatmaktır; aradaki yönlendiricilerin tamponlayarak durdurmaya çalışması daha zordur. ECN'de işaretli paket alıcıya gider, alıcı göndericiye "daha seyrek gönder" der. Geri yönlü seçenekte her yönlendirici bir öncekine haber verir ve bu kaynağa kadar uzanır.
- Load shedding'de link-by-link örneği (ekrandan, 00:50:00): A-E-F-D yolunda ağır akış vardır; D, F'ye choke bildirimi gönderir, F paket düşürmeye başlar ve bildirimi E'ye aktarır, E de düşürür ve A'ya iletir; yol boyunca düşürme olduğu için akış hızla azalır. Uçtan uca örnekte (ekrandan, 00:55:00) choke bildirimi F ve E üzerinden A'ya kadar gider ve ara düğümler bir şey yapmadan iletir; A gönderme hızını düşürünce akış sonunda azalır. Etki geç gelir ama nedeni hedefler.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
