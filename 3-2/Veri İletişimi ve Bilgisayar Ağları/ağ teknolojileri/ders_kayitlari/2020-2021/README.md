# Ağ Teknolojileri Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Ağ Teknolojileri
* **Hoca:** Ali Gökhan Yavuz
* **Dönem:** Bahar
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Bilgisayar Ağlarına Giriş: Referans Modeli, Paket Anahtarlama, Connectionless/Connection-Oriented | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Routing Algoritmaları: Shortest Path, Flooding, Distance Vector | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Tıkanıklık Kontrolü: Proaktif/Reaktif, Trafik Yönetimi, Yük Atma | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Quality of Service: Trafik Şekillendirme, CBR/VBR/ABR, Noisy Neighbor | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | İnternetworking: IP, Fragmentasyon, Tünelleme | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | IPv4 Başlık Yapısı: Adres Sınıfları, Subnetting, CIDR | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Yardımcı Protokoller: ICMP, ARP, DHCP, MPLS, OSPF, BGP | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Transport Katmanı: Portlar, Bağlantı Kurulumu, 3-Way Handshake | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 11** | Bağlantı Sonlandırma: Asimetric/Symmetric, Two Army Problemi | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | UDP, RPC, RTP, TCP'ye Giriş | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 8* (27 Nisan 2021) ve *Ders 10* (11 Mayıs 2021) kayıtları resmi tatil veya ara sınav haftası nedeniyle işlenmemiş ya da kayıt altına alınmamıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Bilgisayar Ağlarına Giriş: Referans Modeli, Paket Anahtarlama, Connectionless/Connection-Oriented
* **Genel Konular:**
  - Bilgisayar Ağlarına Giriş ve Referans Modeli
    - Ağ Teknolojileri dersinin amacı, network (ağ) ve transport (taşıma) katmanlarını kapsamasıdır; ders 5. baskı Tanenbaum kitabını takip eder ve network katmanından başlayarak 5-6-7. bölümlere kadar ilerler.
    - OSI referans modelinin 7 katmanı teorik olarak bilinmelidir; TCP/IP referans modeli pratikte 4 katmana indirgenmiştir; ders kapsamında 5 katmanlı yapı (physical, link, network, transport, application) kabul edilerek session ve presentation katmanları atlanır.
    - Network katmanının temel görevi, paketleri birden fazla link üzerinden uçtan uca (end-to-end), birden fazla atlama (hop) ile kaynaktan hedefe "store and forward" (sakla ve gönder) mantığıyla iletmektir.
  - Paket Anahtarlama ve Connectionless/Connection-Oriented Servisler
    - Veriler, mesaj (message) halinden paket adı verilen daha küçük anlamlı parçalara bölünerek iletilir; tüm mesaj bir bütün olarak değil parçalar halinde gönderilir.
    - Paketin tamamı aradaki bir router bufferına (belleğine) gelip tamamlanmadan ileri yönlendirilmez; bu, store-and-forward prensibidir.
    - Connectionless (bağlantısız) servis mektupla haberleşmeye benzer: önceden uyarı yoktur, gelen zarf açılır; connection-oriented (bağlantı odaklı) servis ise telefon görüşmesine benzer: önce bağlantı kurulur, sonra iletişim gerçekleşir.
    - Internet'in temel felsefesi connectionless servis üzerine kuruludur (TCP/IP), ancak bu tek yol değildir; alt katmanlarda (data link) veya üst katmanda (transport TCP) connection-oriented çalışma mümkündür.
  - Routing ve İnternet Yapısı
    - Internet Service Provider (ISS) ve Internet Exchange Point (IXP) kavramları; ISS'ler arası trafik değişimi genellikle maliyetli ve politik nedenlerle yönlendirilir.
    - Her router bir paketin son noktası değildir; sadece hedefe doğru ilerletir (forwarding).
    - Topoloji, routerlar, hostlar ve bağlantıların oluşturduğu graf benzeri yapıdır; hatlar çift yönlü veya tek yönlü olabilir; maliyet, güvenilirlik, politika gibi kriterlere göre ağırlıklandırılır.
* **Hocanın Vurgusu:**
  - Geçmişteki (eski) yöntemlerin tekrar gündeme gelebileceği
    - Hoca, "history repeats itself" mantığını vurgular: mesela 1960'larda kullanılıp kenara atılan ALOHA algoritması RFID ile tekrar gündeme gelmiştir; Distance Vector Routing sensör ağlarda yeniden denenebilir. Bu nedenle tarihsel bilgi ileride işe yarar.
    - Mühendis olarak geçmişte benzer durumlarda uygulanan çözümleri bilmek, yeni problemlerle karşılaşıldığında ilk başvurulacak kaynaktır.
  - Mühendislik kapsamı
    - Dersin sadece kavramsal değil, mühendislik perspektifiyle verildiği; "veri iletişimi" (datacom) dersinde öğrenilen OSI, 5-katman yapı, servis ve arayüz gibi temel bilgilerin hatırlanması gerektiği vurgulanır.
    - Kitap (Tanenbaum) ve slaytlar yeterli değildir; ders kayıtları, hocaların yorumları, ek bilgiler sınav ve uygulama için kritiktir.
* **Detaylı Açıklamalar:** Dersin ilk dersi olduğu için, dersin işleyişi ve genel çerçevesi anlatılmıştır. Hocalar iki grup halinde dersi yürütür (Cihan Hoca ile Ali Gökhan Yavuz birlikte). Kayıtlar tutulur, dolayısıyla kaçırılan dersler kayıttan izlenebilir; ancak aktif katılım önerilir. Network katmanının genişletilmiş tanımı: Mevcut linklerle sağlanan bağlantıyı uçtan uca genişletir, topolojiyi büyütür. Bir paketin A noktasından D noktasına gitmesi için B, C gibi aradaki düğümlerden geçmesi gerekir; her geçiş bir "hop"tur. Bu nedenle network layer, link layer'ın (tek atlama) sağladığını birden fazla atlama için sağlar. Paket kavramı: Network açısından bakıldığında, "veri" paket adı verilen yapısal birimler halinde taşınır. Bir paket 100 byte ise, tüm 100 byte bir router'a ulaşmalı, sonra hedefe doğru yönlendirilmelidir. Bu da buffer (bellek) ihtiyacı doğurur. Connectionless vs Connection-oriented: TCP/IP dünyasında network katmanı connectionless'tır. Ancak her katmanda bu seçim yapılabilir. Örneğin, network katmanı connectionless olsa bile, üstündeki transport katmanında TCP kullanılarak connection-oriented servis sağlanabilir. Bu, katmanlı yapının esnekliğini gösterir.

### 🔹 Ders 2: Routing Algoritmaları: Shortest Path, Flooding, Distance Vector
* **Genel Konular:**
  - Routing (Yönlendirme) ve Forwarding (İletme) Ayrımı
    - Routing, bir router'ın kendisine gelen paketin bir sonraki adımda nereye gönderileceğine karar vermesi sürecidir; bu kararı veren yapıya routing algoritması denir.
    - Forwarding ise bu kararın uygulanması, paketin buffer'dan alınıp doğru çıkış hattına konulması işlemidir.
    - İlişki: Scheduler/Dispatcher benzetmesi — routing kararının alınması, forwarding ise işin gerçekleştirilmesidir.
  - Optimality Principle (Optimum Olma İlkesi)
    - Bir router (örneğin B), tüm diğer router'lara (M gibi) en iyi yolları bulundurursa, bu yollar bir "sink tree" (kök ağacı) formundadır.
    - Optimality principle der ki: B'den M'ye giden en iyi yol B→C→J→N→M ise, bu yol üzerindeki her alt yol da (B→C, C→J, J→N, N→M) kendi aralarında en iyi yoldur.
    - Her router kendisi kök olacak şekilde ayrı bir sink tree oluşturmalıdır; topolojide her router için ayrı ağaç vardır.
  - Shortest Path (En Kısa Yol) Algoritması
    - Dijkstra algoritması kullanılır; her link negatif olmayan bir ağırlıkla (weight) ilişkilendirilir.
    - Ağırlık fiziksel mesafe (km) değildir; maliyet (cost) olarak düşünülmelidir — güvenilirlik, para, gecikme, hız gibi faktörler.
    - Bazen işi basitleştirmek için her linkin ağırlığı 1 kabul edilir (hop sayısı); bu durumda en kısa yol en az hop olan yoldur.
  - Flooding (Taşkın) Algoritması
    - Bir düğümden gelen paketin geldiği yöne bakılmaksızın tüm bağlantılara gönderilmesidir; en güvenilir routing algoritmasıdır (en kötü koşullarda bile paket hedefe ulaşır).
    - Dezavantajı: aşırı yükleme yapar, en verimli değildir; broadcast storm (yayın fırtınası) oluşturabilir.
    - Optimize edilebilir: (1) paketin geldiği hatta geri gönderilmez, (2) düğümler daha önce gönderdikleri paketleri hatırlar ve tekrar göndermez (her pakete unique ID gerekir).
    - Çoğu akıllı routing algoritması kontrollü bir şekilde flooding ile başlar, sonra söndürülür.
  - Distance Vector Routing (Mesafe Vektörü)
    - 1975'te tasarlanmış, dağıtık (distributed) bir algoritmadır; Bellman-Ford algoritması olarak da bilinir.
    - Her düğüm sadece komşularına olan mesafeyi bilir ve en iyi mesafeleri tüm komşularına reklam eder (advertise eder).
    - Merkezi (centralized) routing ile karşılaştırma: merkezi sistemde tek bir nokta tüm topolojiyi bilir, routing tabloları oluşturur ve dağıtır. Dezavantajı: topoloji büyükse ölçeklenmez, dağıtık yavaş tepki verir.
    - Dağıtık (distributed) yaklaşım: divide and conquer mantığı; her düğüm kendi bölgesini bilir. Dezavantaj: komşunun ötesini göremez, hata durumlarında toparlanma (recovery) zor olabilir.
    - Hoca, 1975'te tasarlanmış bir algoritma için "neden şöyle yapmamışlar" demek yerine, o dönemin koşullarını göz önünde bulundurmak gerektiğini vurgular.
* **Hocanın Vurgusu:**
  - Algoritma tasarımındaki trade-off'lar
    - Bellman-Ford 1975'te tasarlanmıştır; o dönemin teknolojik sınırlamaları (sensör ağlar, IoT cihazları yok, basit network yapıları) bugün geçerli olmayabilir. Ancak günümüzde hâlâ bazı topolojilerde (örneğin ad hoc network'ler, sensör ağlar) uygulanabilir.
    - Algoritmaları değerlendirirken o dönemin kısıtlarını bilmek önemlidir; "şimdi şöyle yapsaydık daha iyi olurdu" demek kolaycılıktır.
  - Sink tree'nin her düğüm için ayrı oluşturulması
    - Bu, sınavda veya uygulamada sıkça karıştırılan bir noktadır: "tek bir sink tree" değil, topolojideki her router/host için bir sink tree vardır. Bu gözden kaçırılırsa routing hesabı yanlış yapılır.
* **Detaylı Açıklamalar:** Dersin ana konusu routing algoritmalarıdır. Routing, network katmanının temel işlevlerinden biridir: bir paketin hangi yoldan gideceğine karar verilmesi. Bunun için önce kriterler belirlenir (maliyet, hız, güvenilirlik, adalet). Bu kriterler algoritmanın "iyi" bir yolu bulmasını sağlar. Kısa yol algoritması, tek bir router için en iyi yolu bulur. Sink tree, o router'dan diğer tüm düğümlere giden en iyi yolları içerir. Her router'ın kendi sink tree'si farklıdır; bu yüzden "topolojide birden fazla sink tree vardır" demek önemlidir. Dijkstra algoritması, veri yapıları derslerinde öğrenilen klasik graf algoritmasıdır. Network topolojisinde her linkin ağırlığı olur; amaç, kaynaktan hedefe toplam ağırlığı en düşük yolu bulmaktır. Negatif ağırlık yoktur. Pratikte, maliyet (para), güvenilirlik, gecikme, hata oranı gibi faktörler ağırlık olarak kullanılabilir. Hoca özellikle vurgular: "Ağırlığı kilometre olarak düşünmeyin, maliyet olarak düşünün." Çünkü network'te fiziksel uzaklık çok önemli değildir; önemli olan linkin kullanım bedeli, kalitesi, politik durumu gibi faktörlerdir. Uydu haberleşmesinde "down link" (yukarıdan aşağı) ucuz, "up link" (aşağıdan yukarıya) çok pahalıdır; yani aynı linkin iki yönünde farklı ağırlıklar olabilir. Flooding, en ilkel routing yöntemidir: gelen paket geldiği yön hariç tüm bağlantılara gönderilir. Avantajı, topoloji bilgisi gerektirmemesi ve topolojideki herhangi bir arıza/bağlantı kopması durumunda bile paketin hedefe ulaşmasıdır. Dezavantajı, aşırı yük ve bant genişliği israfıdır. Pratikte, küçük network'lerde veya özel durumlarda (örneğin acil yayın, ağ keşfi) hâlâ kullanılır. Optimize edilebilir: her paket bir sequence number alır, düğümler gördükleri paketleri bir süre hatırlar ve tekrar göndermez. Distance Vector, klasik internet algoritmasıdır. Her düğüm (router) sadece komşularıyla iletişim kurar. Komşularına "bana şu hedefe şu mesafede ulaşılabilir" der. Zamanla tüm düğümler tüm hedeflere en iyi mesafeleri öğrenir. Dezavantajı, komşunun komşusu hakkında bilgi sahibi olmamasıdır; hata durumlarında yavaş iyileşir ("count to infinity" problemi). Hoca, distance vector'ün eski bir algoritma olduğunu ve bugün hâlâ bazı yerlerde kullanıldığını vurgular. Sensör ağlar veya küçük ölçekli dinamik topolojiler için hâlâ geçerli bir seçenek olabilir.

### 🔹 Ders 3: Tıkanıklık Kontrolü: Proaktif/Reaktif, Trafik Yönetimi, Yük Atma
* **Genel Konular:**
  - Congestion (Tıkanıklık) Kavramı
    - Trafik sıkışıklığı, günlük hayattan bir benzetmeyle açıklanır: yolların kapasitesinden fazla araç çıktığında yaşanan yavaşlama, durma, kazalar bilgisayar ağlarında da yaşanır.
    - Network layer'ın görevi, paketleri bir noktadan diğerine aktarmaktır; eğer topolojinin kapasitesinden fazla yüklenme olursa, paketler iletilemez hale gelir ve tamamen durma noktasına (congestion collapse) gelinebilir.
    - Bu sorun sadece network katmanına ait değildir; link, network ve transport katmanlarının hepsinde tedbirler alınmalıdır.
  - Proaktif (Önleyici) vs Reaktif (Tepkisel) Yaklaşımlar
    - Proaktif (preventif): Tıkanıklık oluşmadan önce tedbir alınır; ağın kapasitesinin %70-80'inde kalınır. Dezavantaj: kullanılmayan %20-30'luk kapasite boşa harcanır.
    - Reaktif: Tıkanıklık oluştuktan sonra çözülür; daha esnek ama riskli. Dezavantaj: müdahale gecikirse congestion collapse yaşanabilir.
    - Mühendislik problemlerinde her zaman bir trade-off vardır; burada "güvenli" kalmak (proaktif) ile "verimli" olmak (reaktif) arasında seçim yapılır.
  - Traffic Aware Routing (Trafik Farkında Yönlendirme)
    - Ağdaki trafik yoğunluğunu bilerek routing yapan algoritmalardır; bir link'te trafik eşik değerini aşarsa trafik alternatif yola yönlendirilir.
    - Dezavantaj: Çok sık güncelleme yapılırsa routerlar sürekli hesap yapar; oscillation (salınım) problemi ortaya çıkar (CF→EI→CF→EI şeklinde ping-pong).
  - Admission Control (Kabul Kontrolü)
    - Network'e sadece yeterli kapasite varsa yeni trafik kabul edilir; özellikle virtual circuit (sanal devre) yapılarında uygulanabilir.
    - Connectionless datagram yapılarda uygulanması zordur çünkü her paket farklı yoldan gidebilir.
  - Traffic Throttling (Trafik Yavaşlatma) / Explicit Congestion Notification
    - Bir router çıkışında tıkanıklık yaşarsa, paketlerdeki özel bir biti (ECN) set eder.
    - Forward (ileri) yönde: Hedef host'a ulaşan paketteki işaret, hedefin kaynağa "yavaşla" mesajı göndermesini sağlar (end-to-end).
    - Backward (geri) yönde: Router, geriye gönderdiği paketlerde işaret koyar; bir önceki router bunu görüp kendisi de yavaşlar (hop-by-hop).
    - Bu işaret için ayrı paket gönderilmez; paketin başlık alanındaki (header) özel bir bit kullanılır. Bu tekniğe "piggybacking" denir (fiziksel/link katmanından bilinen bir kavram).
  - Load Shedding (Yük Atma)
    - Tüm yöntemler yetersiz kaldığında router, paketleri drop eder (gelmemiş kabul eder).
    - End-to-end veya link-by-link yapılabilir. Link-by-link daha hızlı rahatlama sağlar; end-to-end uzun vadede daha etkilidir (kaynak da yavaşlar).
    - Paket düşürme kararı: Hangi paketler düşürülecek? "Milk" (süt) yaklaşımı — en yeniler (video için uygun, son kareden devam edilir); "Wine" (şarap) yaklaşımı — en eskiler (dosya transferi için uygun, sıra önemli).
    - Bu karar transport katmanında değerlendirilir; network katmanı sadece paket drop eder.
* **Hocanın Vurgusu:**
  - Trade-off farkındalığı
    - Proaktif önlemler (capacity'nin %70-80'ini kullanmak) güvenlidir ama israf yaratır; reaktif önlemler verimlidir ama risk taşır. Mühendis bu dengeyi bilerek karar vermelidir.
    - Doğal felaket senaryoları (herkes aynı anda arama yapar) reaktif yaklaşımın ne kadar gerekli olduğunu gösterir; aksi takdirde sistem tamamen kilitlenir.
  - Süt/Şarap benzetmesinin önemi
    - Hoca, "süt" ve "şarap" terimlerinin terminolojide yerleşik olduğunu ve hangi uygulama için hangi stratejinin seçilmesi gerektiğini vurgular. Sınavda bu kavramlar sorulabilir.
  - Network layer'ın sınırları
    - Congestion control her ne kadar network layer'da da uygulansa, asıl çözümün transport katmanında (kaynak hızı ayarı) ve uygulama katmanında (kod seviyesinde) olduğu vurgulanır.
* **Detaylı Açıklamalar:** Tıkanıklık kontrolü mühendislik problemidir. Gerçek hayattan bir örnek: ev interneti veya telefon servisi, ortalama yoğunluğa göre (%70-80 doluluk) tasarlanır. Normal şartlarda herkes rahatça iletişim kurar. Ancak bir doğal felaket anında herkes aynı anda arama yapmak ister; bu durumda sistem tamamen kilitlenir. Çözüm: reaktif önlemler. Traffic aware routing, topolojideki yoğunluğu ölçer ve routerları bilgilendirir. Eğer bir link'te eşik değer aşılırsa, trafik alternatif bir yola yönlendirilir. Ancak bu güncelleme çok sık yapılırsa, router'lar sürekli Dijkstra algoritması çalıştırmak zorunda kalır ve sürekli yön değişikliği (oscilasyon) yaşanır. Pratikte bu teknik, yavaş değişen trafik için uygundur; ani değişimler için congestion hâlâ oluşabilir. Admission control, virtual circuit (sanal devre) yapılarında uygulanabilir; çünkü bu yapılarda bağlantı kurulmadan önce yolun tamamı bilinir. Network layer, "bu yol boyunca yeterli kapasite var mı?" sorusuna cevap verebilir ve yeterliyse yeni bağlantıyı kabul eder. Datagram yapısında her paket farklı yoldan gidebileceğinden bu kontrol zordur. Traffic throttling, modern ve etkili bir yöntemdir. Router, çıkış kuyruğunda birikme yaşarsa gelen paketlerdeki ECN (Explicit Congestion Notification) bitini set eder. Bu set edilmiş paket hedefe ulaştığında, hedef host TCP ACK'sında kaynağa "yavaşla" bilgisi gönderir. Bu end-to-end (uçtan uca) yöntemdir. Alternatif olarak router, geriye gönderdiği paketlerde de aynı biti set edebilir; bu durumda bir önceki router yavaşlar (hop-by-hop). İki yöntem de kullanılabilir; önemli olan ayrı bir paket gönderilmeden header alanı kullanılmasıdır (piggybacking). Load shedding en son çare olarak uygulanır. Eğer tüm yöntemler yetersiz kalırsa ve buffer dolmuşsa, router gelen paketleri drop eder. Bu, "yangına benzin dökmek" gibidir çünkü zaten tıkanık olan network'e ek bir retransmission yükü bindirir. Ancak başka çare kalmamıştır. Paket drop kararı önemlidir: gerçek zamanlı uygulamalar (video) için en yeni paketler düşürülür (süt mantığı — son kareden devam edilir), veri aktarımı (dosya indirme) için en eski paketler düşürülür (şarap mantığı — sıra korunmalı).

### 🔹 Ders 4: Quality of Service: Trafik Şekillendirme, CBR/VBR/ABR, Noisy Neighbor
* **Genel Konular:**
  - Quality of Service (QoS) - Servis Kalitesi
    - Network üzerinden akan trafiğin kalitesini kontrol etme mekanizmalarının tümüdür. Tüm uygulamaların ihtiyaçları farklıdır; bu nedenle her birine farklı kalite seviyeleri sağlanmalıdır.
    - Uygulama kategorileri ve ihtiyaçları:
      - **E-posta**: Düşük bant genişliği, düşük gecikme hassasiyeti (asenkron, 10 dakika gecikse sorun olmaz); yüksek kayıp hassasiyeti.
      - **Dosya paylaşımı**: Yüksek bant genişliği, düşük gecikme/jitter hassasiyeti.
      - **Web erişimi**: Orta seviye her şey.
      - **Audio on demand, Telefon**: Düşük bant genişliği, yüksek gecikme ve jitter hassasiyeti.
      - **Video conferencing**: Yüksek bant genişliği, yüksek gecikme ve jitter hassasiyeti (real-time).
    - Her uygulamanın 4 kritere göre (bandwidth, delay, jitter, loss) farklı beklentisi vardır; QoS bu beklentileri karşılayacak şekilde trafiği yönetir.
  - Trafik Şekillendirme (Traffic Shaping) ve Trafik Parlatması (Traffic Polishing)
    - Trafik şekillendirme host tarafında yapılır; uygulamanın ürettiği trafik, network'e gönderilmeden önce yeniden düzenlenir.
    - Trafik parlatması (holistik) ise ISS (servis sağlayıcı) tarafından tüm network genelinde yapılır; uygulamadan bağımsız, tüm topoloji ölçeğinde.
    - İki temel kontrol noktası: ortalama hız ve burstiness (ani artışlar).
  - ATM (Asynchronous Transfer Mode) Ağları
    - 53 byte'lık hücre (cell) yapısı; klasik paket switching'in daha mikro versiyonu.
    - Sabit boyutlu hücre yapısı sayesinde QoS uygulaması daha kolaydır; günümüzde DSL/ADSL altyapısında ATM Adaptation Layer olarak hâlâ kullanılır.
  - Servis Tipleri (CBR, VBR, ABR)
    - **CBR (Constant Bit Rate)**: Sabit bant genişliği. Örnek: telefon (4 kHz insan sesi, Nyquist teoremi → 8 kHz örnekleme).
    - **VBR (Variable Bit Rate)**: Değişken bant genişliği. İki türü:
      - Real-time VBR: Video conferencing (anlık bitrate ihtiyacı değişir, sahne içeriğine bağlı).
      - Non real-time VBR: Video on demand (client buffer sayesinde gerçek zamanlılık ortadan kalkar).
    - **ABR (Available Bit Rate)**: Kalan kapasite. File transfer gibi gecikme toleransı yüksek uygulamalar için.
  - Noisy Neighbor Kavramı
    - Bazı uygulamalar (file sharing) tüm mevcut bant genişliğini kullanmaya meyillidir; diğer uygulamaları (video konferans) olumsuz etkiler.
    - Apartman komşusu benzetmesi: Yan dairede yüksek sesle müzik dinleyen biri, diğerlerini rahatsız eder.
    - Çözüm: uygulama tipine göre uygun kalite parametreleri uygulamak ve uygulama tipini tanımlayabilmek (P2P vs VoIP gibi).
* **Hocanın Vurgusu:**
  - Matristeki "low/medium/high" anlamı
    - Tablodaki "low, medium, high" ifadeleri mutlak bant genişliği değerlerini değil, o kritere olan hassasiyeti gösterir. Yani "bandwidth low" demek, "bant genişliği bu uygulama için kritik değil" demektir.
    - Bu ayrım sınavda sıkça karıştırılır; net anlaşılmalıdır.
  - COVID-19 döneminin network trafiğine etkisi
    - Online eğitim, video konferans, streaming gibi uygulamaların artması ABR kapasitesini azaltmıştır. Aynı hızda internet bağlantısı olsa bile, başka uygulamalar (streaming) devredeyken download yavaşlayabilir.
  - Bant genişliği asimetri
    - ADSL'de download yüksek, upload düşüktür; çünkü ev kullanıcısı ağırlıklı olarak servis alır. Bu bilinçli bir tasarım kararıdır.
  - Sınavda çıkabilecek bilgiler
    - Hoca, telefon için 8 kHz / CBR, video conferencing için real-time VBR, dosya transferi için ABR gibi eşleştirmelerin sınavda çıkabileceğini vurgular.
* **Detaylı Açıklamalar:** Quality of Service, farklı uygulamaların farklı ihtiyaçlarına cevap vermek için geliştirilmiş bir dizi mekanizmadır. Temel fikir: network kaynaklarını (bant genişliği, buffer, CPU) uygulamaların ihtiyacına göre paylaştırmak. Hocanın matris açıklaması önemlidir. Matrisin satırları uygulamaları (e-posta, dosya paylaşımı, web, audio, video), sütunları kriterleri (bant genişliği, gecikme, jitter, kayıp) gösterir. Hücrelerdeki "low, medium, high" ise o uygulamanın o kritere olan hassasiyetini belirtir. Örneğin, telefon için "bandwidth low, delay high, jitter high, loss low"tur — yani telefon için bant genişliği çok kritik değildir (çok az bant yeter) ama gecikme ve jitter çok kritiktir (insan kulağı gecikmeyi fark eder). Trafik şekillendirme iki yerde yapılabilir. Host tarafında, uygulamanın çıkışında bir "shape" mekanizması konur; bu, paketleri belirli bir profile göre düzenler. ISP tarafında ise tüm network ölçeğinde bir kontrol uygulanır. İkincisi daha karmaşıktır çünkü farklı uygulamaların, farklı kullanıcıların trafiğini dengelemek gerekir. CBR, VBR, ABR kavramları ATM'den gelir. Günümüzdeki uygulamalar bu kategorilere eşlenebilir. CBR için en iyi örnek telefon: insan sesi 4 kHz ile sınırlıdır, Nyquist'e göre 8 kHz örnekleme yeterlidir, 64 kbps PCM (G.711) sabit bir bant genişliği gerektirir. VBR için en iyi örnek video: sahnenin karmaşıklığına göre anlık bitrate değişir. ABR ise file transfer gibi uygulamalar içindir — bant genişliği arttıkça daha hızlı, azaldıkça daha yavaş çalışır. Noisy neighbor kavramı modern ağlarda özellikle bulut bilişim ve veri merkezlerinde önemlidir. Bir uygulama, diğerlerinin kaynağını tüketirse, "komşu" etkisi yaratır. Aynı fiziksel linki veya router'ı paylaşan uygulamalar birbirlerini yavaşlatabilir. QoS, bu durumu uygulama tiplerini tanıyarak ve farklı politikalar uygulayarak çözmeye çalışır.

### 🔹 Ders 5: İnternetworking: IP, Fragmentasyon, Tünelleme
* **Genel Konular:**
  - İnternetworking ve Farklı Ağların Birleştirilmesi
    - Farklı teknolojilere sahip ağların (Ethernet, 802.11 WiFi, MPLS, hücresel) birlikte çalışabilmesi için üst seviyede bir protokol gerekir; bu, IP (Internet Protocol) katmanıdır.
    - Ağ geçişlerinde karşılaşılan temel sorunlar:
      - Paket boyutu farklılıkları (Ethernet ~1500 byte, 802.11 daha küçük)
      - Adresleme format farklılıkları
      - Connection-oriented (MPLS) vs connectionless (Ethernet) yapılar
    - IP router, üst katmandan gelen veriyi paket olarak alır, hedef ağa uygun formata dönüştürür ve iletir.
  - IP'nin Ortaya Çıkışı ve Standartlaşma
    - İnternet 1960'ların sonu-1980'lerin başında Amerika'da DARPA projesi olarak 5 üniversitenin işbirliğiyle geliştirildi.
    - Amaç: nükleer saldırı gibi felaket senaryolarında bile çalışmaya devam edebilen bir bilgisayar ağı.
    - ARPANET → ticari kurumlar → bireysel kullanıcılar → dünya genelinde yayılma.
    - Farklı protokoller (IPX, AppleTalk, SNA) denenmiş olsa da IP standart olmuştur.
  - Paket Fragmentasyonu (Parçalama)
    - Bir paket, hedef ağın izin verdiği maksimum boyuttan (MTU) büyükse parçalanmalıdır.
    - İki strateji:
      - Transparent fragmentasyon: Her ağ geçişinde parçalanır, hedefe yakın router'da tekrar birleştirilir.
      - Non-transparent fragmentasyon: Parçalar yol boyunca küçülebilir, sadece hedef host'ta birleştirilir.
    - Avantajlar/dezavantajlar: Transparent'ta her router parçalanmış paketleri saklamak zorunda; non-transparent'ta parçalar yol boyunca bağımsız hareket eder, kayıp riski daha yüksek.
    - IP paket teorik olarak 65.535 byte'a kadar büyüyebilir; pratikte her ağın MTU sınırı vardır.
  - Tunnelling (Tünelleme) ve Overlay Ağlar
    - Farklı ağlar arasında geçiş yapmak için, bir protokolün paketi başka bir protokolün payload'ı içine yerleştirilebilir.
    - Örnek: IPv6 paketi IPv4 ağı üzerinden taşınırken IPv4 paketine encapsulate edilir.
    - Paris-Londra ofisleri arasında IPv6 kullanmak için, ortadaki IPv4 ağında tünel açılır.
    - Tünelleme + şifreleme = VPN (Virtual Private Network) yapısı.
  - Routing'in İki Seviyesi
    - **Intradomain routing (Interior Gateway Protocol)**: Bir organizasyonun (şirket, üniversite) kendi iç ağında kullanılan routing; herkes istediği protokolü kullanmakta serbest.
    - **Interdomain routing (Exterior Gateway Protocol)**: Farklı organizasyonlar arası routing; internet ölçeğinde ortak protokol gerekir (BGP).
* **Hocanın Vurgusu:**
  - Farklı network'lerin birleştirilmesinin zorlukları
    - Her network'ün kendine özgü yapısı, MTU'su, adresleme formatı vardır. Bunları birleştirmek için katmanlı yaklaşım (overlay) gerekir; IP bu rolü üstlenir.
    - Aynı network içinde bile routing farklı olabilir; Distance Vector, Link State, Path Vector gibi farklı algoritmalar kullanılabilir.
  - Hoca, "unutmayın" vurgusu
    - Karmaşık konularda öğrencilerin kafasının karışmaması için, "bu ve şu aslında benzer şeyler, farklı terminolojiler" gibi hatırlatmalar yapar.
  - IP'nin başarısının sırrı
    - IP, "her şeyi IP üzerinden yap" stratejisinin başarısıdır. 20+ yıldır IPv4 hâlâ kullanılmaktadır; IPv6'ya geçiş hâlâ tamamlanmamıştır.
* **Detaylı Açıklamalar:** Bu ders internetworking kavramını tanıtır. Temel fikir: dünya üzerinde farklı teknolojilere sahip birçok ağ vardır (Ethernet kablolu ağlar, WiFi ağları, hücresel ağlar, uydu ağları, MPLS ağları). Bunların hepsi farklı özelliklere sahiptir. Bu ağların birbirleriyle iletişim kurabilmesi için ortak bir dil gerekir; bu dil IP'dir. Hoca, gerçek bir senaryoyla açıklar: Paris ve Londra'daki iki ofis IPv6 kullanmak istiyor. Ancak aradaki ISP ağı sadece IPv4 destekliyor. Çözüm: Paris'te IPv6 paketi IPv4 paketi içine sarılır (encapsulation), hedefe ulaşana kadar IPv4 ağı üzerinden taşınır, Londra'da tekrar IPv6 paketi açılır. Bu, tünelleme (tunnelling) yöntemidir. Şifreleme de eklenirse VPN (Virtual Private Network) elde edilir. Fragmentasyon konusu önemlidir. Her ağın MTU (Maximum Transmission Unit) değeri farklıdır. Ethernet tipik olarak 1500 byte'lık frame kullanır; bazı ağlar daha küçük MTU'ya sahiptir. Eğer büyük bir paket daha küçük MTU'lu bir ağa gelirse, parçalanması gerekir. IP iki stratejiyi destekler: transparent (her router'da parçalanır, hedefe yakın router'da birleştirilir) ve non-transparent (parçalar yol boyunca küçültülebilir, sadece hedefte birleştirilir). Non-transparent'ta her parça bağımsız hareket ettiğinden bir parça kaybolursa tüm paket kaybedilmiş sayılır; bu yüzden güvenilir olmayan ağlarda risklidir. Routing'in iki seviyede yapılması, internet'in ölçeklenebilirliği için kritiktir. Bir kurumun kendi iç ağında (intradomain) herhangi bir routing protokolü kullanılabilir (RIP, OSPF, IS-IS). Ancak farklı kurumların ağları arasında (interdomain) ortak bir protokol gerekir; bu BGP'dir (Border Gateway Protocol). Hoca, "her network'ün kendi routing fikri olabilir, ama genel internet için ortak bir protokol şart" der.

### 🔹 Ders 6: IPv4 Başlık Yapısı: Adres Sınıfları, Subnetting, CIDR
* **Genel Konular:**
  - Dünya İnternet Topolojisi
    - İnternet, omurga (backbone) ağlardan bölgesel, ulusal, kurumsal ağlara; oradan da ev/mobil ağlara kadar hiyerarşik bir yapıdır.
    - Backbone router'lar arası bağlantılar yüksek kapasiteli (kalın hat), alt seviyelerdeki bağlantılar daha düşük kapasitelidir.
    - Türkiye'nin ulusal ağı da benzer şekilde uluslararası bağlantılara sahiptir; ULAKBİM, TT, vb. kurumlar bu yapıda yer alır.
    - Ev ağlarındaki "ADSL router" aslında sınırlı özelliklere sahip bir uç cihazıdır; gerçek router işlevi görmez.
  - IPv4 Protokol Başlığı (Header)
    - Toplam 20-60 byte (standart 20 byte + opsiyonel alanlar).
    - **Version (4 bit)**: 4 (IPv4). Tek sayılı versiyonlar (1, 3, 5) test için; çift sayılılar (2, 4, 6) sahada kullanılır.
    - **IHL (Internet Header Length, 4 bit)**: Header uzunluğunu 32-bit word cinsinden verir (min 5 = 20 byte, max 15 = 60 byte).
    - **Total Length (16 bit)**: Header + veri uzunluğu; max 65.535 byte.
    - **Identification, Flags, Fragment Offset**: Parçalama için kullanılır.
    - **TTL (Time To Live, 8 bit)**: Paketin kaç hop geçebileceğini belirtir; orijinalde saniye cinsinden tanımlanmış, pratikte hop sayısı olarak kullanılır. Her router'da 1 azalır, 0 olunca paket düşürülür.
    - **Protocol (8 bit)**: Üst katmandaki protokolü belirtir (TCP=6, UDP=17, ICMP=1).
    - **Header Checksum (16 bit)**: Sadece header hata kontrolü; veri değil. 1-bit hataları yakalar, çok-bit hataları kaçırabilir.
    - **Source Address, Destination Address (her biri 32 bit)**: IP adresleri.
    - **Options**: Değişken uzunluklu, deneysel amaçlı.
  - Byte Order (Endianness) Sorunu
    - IP, SPARC işlemcisi ve SunOS üzerinde tasarlanmıştır; Big Endian (network byte order) kullanır.
    - Modern Intel işlemcileri Little Endian kullanır; dönüşüm gerekir (htonl, htons fonksiyonları).
    - IPv6 da Big Endian'dır; IPv4 ile uyumlu kalmak için.
  - IP Adres Sınıfları (Classful Addressing)
    - 1980'lerde tasarlanmış, sınırlı sayıda network'ün düşünüldüğü bir yapı:
      - **A sınıfı**: 8 bit network + 24 bit host; 128 network, 16M host.
      - **B sınıfı**: 16 bit network + 16 bit host; 16K network, 65K host.
      - **C sınıfı**: 24 bit network + 8 bit host; 2M network, 256 host.
      - **D sınıfı**: Multicast (224.0.0.0 - 239.255.255.255).
      - **E sınıfı**: Gelecek kullanım için ayrılmış.
    - ABC sınıflama dünya genelinde yayılınca yetersiz kaldı; classless (CIDR) yapıya geçildi.
  - Subnet Mask ve Prefix Notation
    - Classless yapıda, network ve host kısımları sınıf bazlı değil, prefix uzunluğu ile belirlenir: 192.168.0.0/24 (24 bit prefix = network, 8 bit = host).
    - Subnet mask: 1'lerden oluşan bit sayısı prefix uzunluğunu gösterir. Kesintisiz olmalıdır.
    - Alt ağlar (subnet) oluşturmak için daha büyük bir network bölünebilir (örneğin bir üniversitenin /16 prefix'i, bölümler için /24'lere bölünebilir).
* **Hocanın Vurgusu:**
  - Versiyon numaralarının stratejisi
    - IP'de tek numaralı versiyonlar (1, 3, 5) test/development için; çift numaralılar (4, 6) sahada kullanılır. Bu, geliştirme ve deployment'ı ayırır.
  - IPv4'ün hâlâ kullanımda olması
    - 1990'larda IPv6 ortaya atıldı, ama 30 yıl geçmesine rağmen hâlâ IPv4 kullanılıyor. Geçiş planları (2001, 2005, 2008, 2011) hep ertelendi.
    - IPv6'nın tamamen IPv4'ün yerini alması gerekiyordu ama bu gerçekleşmedi.
  - IP'nin Big Endian oluşunun nedeni
    - IP, SPARC işlemcisi üzerinde geliştirildi; SPARC Big Endian'dır. Bu yüzden network byte order = Big Endian. Günümüzde çoğu işlemci Little Endian olduğu için dönüşüm hâlâ yapılıyor.
  - Classful'ın yetersizliği
    - Hoca, kendi üniversitesinin (YTÜ) 1993'te C sınıfı adres aldığını, ABD merkezli düşünülen ABC sınıflamasının dünya genelinde yayılınca yetersiz kaldığını vurgular.
* **Detaylı Açıklamalar:** Ders, internetin fiziksel topolojisinden başlayıp IP protokol detaylarına iner. Hoca önce büyük resmi çizer: dünya üzerinde birçok backbone ağı var (ABD, Avrupa, Asya); bunlar arasında kiralık hatlarla veya denizaltı kablolarıyla bağlantı kurulmuş. Bu omurga ağlardan bölgesel ağlara, oradan da son kullanıcıya (ev/kurum) ulaşılır. Her seviyede bağlantı kapasitesi düşer. IPv4 header'ı, IP'nin en temel yapı taşıdır. Her alan önemli bir amaca hizmet eder. Version alanı protokolün uyumluluğunu sağlar; IHL header'ın nerede bittiğini gösterir; Total Length tüm paketin boyutunu verir; TTL paketin sonsuza kadar dolaşmasını engeller (yönlendirme döngüsü durumunda); Protocol üst katmanın hangi protokol olduğunu söyler (bu sayede IP aynı datagram içinde farklı protokolleri taşıyabilir); Header Checksum header'ın bozulmadığını garanti eder (sadece header, veri için değil); Source/Destination adresleri routing için kullanılır. Byte order konusu, öğrencilerin sıklıkla karıştırdığı bir noktadır. IP, 1980'lerde SPARC işlemcisi üzerinde geliştirildi. SPARC Big Endian kullanır (en anlamlı byte en düşük adreste). Bu yüzden network üzerinden gönderilen tüm sayılar Big Endian formatındadır. Günümüzde ise çoğu bilgisayar Intel/AMD işlemcisi kullanır ve bunlar Little Endian'dır. Bu yüzden programlama sırasında dönüşüm fonksiyonları (htonl, htons, ntohl, ntohs) kullanılır. IPv6 da IPv4 ile uyumlu kalmak için Big Endian'dır. Adres sınıfları (classful), internet'in ilk tasarımından kalan bir mirastır. ABD merkezli düşünülmüş, sınırlı sayıda büyük network varsayılmıştır. Ancak internet tüm dünyaya yayılınca, sınıfların esnek olmaması (her kurum için tam A, B veya C sınıfı ayrılamaması) sınıflama sistemini yetersiz kıldı. Çözüm: CIDR (Classless Inter-Domain Routing) — artık prefix uzunluğu (örn. /24) ile adres blokları tanımlanır; sınıf kavramı yoktur. Ancak eski sınıflar hâlâ tanınır (geriye uyumluluk için). Subnet'leme, büyük bir network bloğunu daha küçük parçalara bölme işlemidir. Örneğin, bir üniversitenin /16 prefix'i (örn. 144.122.0.0/16) varsa, fakültelere /24 prefix'leri (örn. 144.122.1.0/24, 144.122.2.0/24) atanabilir. Bu, routing'i de kolaylaştırır: dış dünya sadece /16'yı bilir, iç yapıyı üniversitenin router'ları yönetir.

### 🔹 Ders 7: Yardımcı Protokoller: ICMP, ARP, DHCP, MPLS, OSPF, BGP
* **Genel Konular:**
  - IP ile İlgili Yardımcı Protokoller
    - IP tek başına yeterli değildir; yönetim, hata bildirimi, otomatik konfigürasyon gibi işler için yardımcı protokoller gerekir.
    - **ICMP (Internet Control Message Protocol)**: Network katmanının kontrol ve yönetimi için.
    - **ARP (Address Resolution Protocol)**: IP adresini MAC adresine çevirmek için.
    - **DHCP (Dynamic Host Configuration Protocol)**: IP adresi, subnet mask, gateway, DNS sunucusu gibi bilgileri otomatik dağıtmak için.
  - ICMP Mesaj Türleri
    - **Echo / Echo Reply**: Ping komutunun temeli; karşı tarafın ayakta olup olmadığını kontrol eder.
    - **Destination Unreachable**: Hedef router tarafından "ulaşılamaz" bildirimi; ayrıca "Don't Fragment" biti set edilmiş ve parçalanması gereken bir paket için de kullanılır.
    - **Time Exceeded**: TTL 0 olunca veya parça zamanında gelmeyince gönderilir; traceroute komutu bu mantıkla çalışır.
    - **Redirect**: Router, host'a "daha iyi bir yol var" bilgisi gönderir; routing optimizasyonu sağlar.
    - **Parameter Problem**: Header'da beklenmeyen bir değer varsa.
    - **Source Quench**: Tıkanıklık bildirimi (artık kullanılmıyor; TCP bunu ECN ile yapar).
    - **Router Advertisement / Solicitation**: Host'un yerel router'ları keşfetmesi için (DHCP olmadan).
  - ARP (Address Resolution Protocol)
    - IP paketi yerel ağda gönderilirken, hedef IP'nin MAC adresi bilinmelidir.
    - ARP broadcast yapar: "192.168.1.5 kim? MAC adresinizi söyleyin."
    - Tüm hostlar broadcast'ı alır; sadece hedef IP'ye sahip olan cevap verir.
    - Cevapta kaynak MAC adresi de yer aldığı için, diğer hostlar da bu bilgiyi kendi ARP tablolarına ekler (öğrenme yan etkisi).
    - ARP tablosunda entry'ler yaşam süresine (TTL) sahiptir; çünkü hostlar kapanıp açılabilir, ethernet kartı değişebilir.
    - **Proxy ARP**: Bazı durumlarda, bir host başka bir host'un MAC adresi için cevap verebilir (örn. mobil IP'de home agent).
  - DHCP (Dynamic Host Configuration Protocol)
    - Bir host'un IP'ye dahil olması için gereken bilgiler: IP adresi, subnet mask, gateway, DNS sunucu adresi (en az 1, tercihen 2).
    - Bu bilgiler hardcoded olabilir (küçük, statik ağlarda), ama büyük, dinamik ağlarda DHCP gerekir.
    - DHCP 4 aşamalı süreç (kısaca): Discover → Offer → Request → Acknowledge.
    - DHCP server, IP havuzundan (pool) rastgele veya belirli bir MAC adresine rezerve edilmiş bir adres verebilir.
    - Lease time: verilen adresin geçerlilik süresi; süre dolmadan yenilenmelidir.
    - BootP, DHCP'nin öncülüdür; günümüzde yerini DHCP'ye bırakmıştır.
  - MPLS (Multiprotocol Label Switching)
    - Datagram (connectionless) network'lerde, circuit-switched hızına yakın switching yapmak için geliştirilmiş.
    - Paketlerin başına 32-bit label eklenir; router'lar IP yerine label'a bakar (en hızlı lookup).
    - Label formatı: 20 bit label + 3 bit QoS + 8 bit TTL + 1 bit stack.
    - Tek hop için anlamsız; birden fazla hop'ta faydalı (toplu switching).
    - Datagram ağ üzerinde virtual circuit benzeri davranış sağlar.
  - OSPF (Open Shortest Path First)
    - Standart interior routing protokolü; TCP/IP suitinde kabul görmüş.
    - Link state routing'in implementasyonu; dağıtık Dijkstra kullanır.
    - Hierarchical yapı: Otonom sistemler (AS), her AS alanlara bölünür (area 0 = backbone).
    - Backbone router'lar alanlar arası trafiği yönetir; internal router kendi alanı içinde kalır.
  - BGP (Border Gateway Protocol)
    - Exterior routing protokolü; farklı otonom sistemler arası.
    - Teknik kriterlerden çok politik, ticari, kurumsal kurallara dayanır.
    - Örnek: Eğitim ağı üzerinden ticari trafik aktarılamaz; Apple siteleri arası trafik Google üzerinden geçemez.
    - Internet'in "yapıştırıcısı"dır; sınır kapısı gibi düşünülebilir.
* **Hocanın Vurgusu:**
  - ICMP'nin network katmanı içinde taşınması
    - ICMP mesajları normal IP paketleri gibi taşınır; ancak hedefteki IP katmanı bunları tanır ve cevap verir. Üst veya alt katmana etkisi yoktur.
  - ARP tablosunun yaşam süresi
    - TTL olmadan ARP tablosu hatalı kalır; hostlar kapanabilir, ethernet kartı değişebilir. Bu nedenle entry'ler periyodik olarak temizlenir.
  - DHCP'nin vize haftası öncesi vurgusu
    - Hoca, vizede sorulabilecek DHCP bilgisi olarak; adres, maske, gateway, DNS sunucu kavramlarını netleştirir.
  - MPLS'in "ne işe yaradığı"
    - Datagram network'te, normalde her router'da IP lookup yapılır (longest prefix matching). MPLS, paketleri birleştirip (aggregate) tek bir label ile yoluna devam ettirir; router'lar sadece label'a bakar. Bu, core router'larda büyük performans artışı sağlar.
  - BGP'nin "yönetimsel" doğası
    - Teknik kriterler (hız, bant genişliği, gecikme) dışında politik, ticari, kurumsal kısıtlar vardır. BGP bu kuralların ifade edilebileceği bir protokoldür.
* **Detaylı Açıklamalar:** Bu derste IP'nin etrafındaki yardımcı protokoller öğretilir. ICMP, IP'nin "hata bildirim" mekanizmasıdır. Bir paket hedefe ulaşamıyorsa, aradaki bir router ICMP Destination Unreachable mesajı gönderir. Benzer şekilde, TTL sıfırlanırsa Time Exceeded gönderilir. Ping, ICMP Echo/Echo Reply'in uygulama seviyesindeki kullanımıdır. Traceroute ise Time Exceeded'in yaratıcı bir kullanımıdır: artan TTL değerleriyle paket gönderilir, her router'da Time Exceeded alınır, böylece yol üzerindeki tüm router'lar keşfedilir. ARP, network katmanı ile data link katmanı arasındaki "çeviri" protokolüdür. Network katmanı IP adresiyle ilgilenir, data link katmanı MAC adresiyle. Yerel ağda bir paket gönderebilmek için hedef IP'nin MAC adresini bilmek gerekir. ARP broadcast ile bunu sorgular. Önemli bir detay: ARP tablosu statik değildir; entry'lerin yaşam süresi vardır çünkü ağda her an değişiklikler olabilir. Örneğin, bir laptop'un ethernet kartı bozulup yenisi takılırsa, eski MAC adresi geçersiz olur. DHCP, modern ağların vazgeçilmez bileşenidir. Bir üniversite kampüsünde 10.000 öğrenci var; her birinin IP'sini, subnet maskesini, gateway'ini, DNS'ini manuel olarak yapılandırmak imkansızdır. DHCP, bu bilgileri otomatik dağıtır. Süreç basittir: yeni bağlanan host "DHCP Discover" yayını yapar; DHCP server "Offer" ile cevap verir; host "Request" ile seçtiği teklifi kabul eder; server "Acknowledge" ile onaylar. Bu sürecin sonunda host tüm gerekli konfigürasyona sahip olur. MPLS, modern internet omurgasında yaygın kullanılan bir teknolojidir. Temel fikir: datagram (connectionless) network'lerde bile, paketleri bir "virtual circuit" mantığıyla yönlendirmek. Bunun için her pakete kısa bir label eklenir; router'lar uzun IP prefix matching yerine sadece label'a bakar. Bu, yüksek hızlarda büyük performans artışı sağlar. MPLS aynı zamanda QoS (Quality of Service) için de temel sağlar; label içindeki 3-bit QoS alanı, paketin önceliğini belirtir. OSPF ve BGP, internet'in iki routing seviyesini oluşturur. OSPF, bir organizasyonun kendi iç ağında kullanılır; alanlara (area) bölünmüş hiyerarşik bir yapıdadır, area 0 her zaman backbone'dur. BGP, farklı organizasyonların ağları arası routing için kullanılır; burada teknik kriterler yerine politik, ticari, kurumsal kurallar ön plana çıkar.

### 🔹 Ders 9: Transport Katmanı: Portlar, Bağlantı Kurulumu, 3-Way Handshake
* **Genel Konular:**
  - Transport Katmanına Giriş
    - Network katmanı güvenilir değildir; paketler kaybolabilir, bozulabilir, sırasız gelebilir, duplicate olabilir. Transport katmanı bu güvensizliği üst katmana "güvenilir" olarak yansıtır.
    - Servisler: connectionless (UDP) veya connection-oriented (TCP) — datagram veya virtual circuit.
    - Network'te dört kombinasyon mümkündür; network'te hangisinin seçildiği önemlidir.
  - Transport Katmanının Temel Görevleri
    - Üst katmana güvenilirlik sağlamak (hata kontrolü, sıralama, tekrar gönderim).
    - Uygulamalar arası multiplexing/demultiplexing (port numaraları).
    - Akış kontrolü (flow control).
    - Tıkanıklık kontrolü (congestion control).
  - Transport Adresleme ve Port
    - Network adresi (IP) host'u tanımlar; transport adresi (port) o host'taki uygulamayı/prosesi tanımlar.
    - Port 16-bit (0-65535); 0-1023 "well-known port" (örn. 80=HTTP, 443=HTTPS, 22=SSH, 25=SMTP, 53=DNS, 110=POP3, 143=IMAP).
    - Apartman/daire benzetmesi: aynı IP altında farklı daireler (portlar) farklı kiracılara (prosesler) kiralanır.
    - TCP/IP'de transport adres = port numarası; OSI terminolojisinde "TSAP" (Transport Service Access Point).
  - Segment, Paket, Frame, Message
    - **Message**: Uygulama katmanında değiş tokuş edilen veri bütünü; teorik olarak sınırsız büyüklükte.
    - **Segment**: Transport katmanı PDU'su (Protocol Data Unit); header + payload.
    - **Packet / Datagram**: Network katmanı PDU'su.
    - **Frame**: Data link katmanı PDU'su.
    - Rus matruşka bebek gibi iç içe geçmiş yapı.
  - Primitifler (Connection-Oriented Servis)
    - **Listen**: Server tarafında dinleme pozisyonuna geçme.
    - **Connect**: Client'ın bağlantı başlatma isteği (connection request).
    - **Send**: Veri gönderme.
    - **Receive**: Veri alma.
    - **Disconnect**: Bağlantı sonlandırma.
    - **Accept**: Server tarafında gelen isteği kabul etme (multiplexing için kritik).
  - Durum Diyagramı (State Diagram)
    - Connection-oriented protokol için durumlar ve geçişler tanımlanmalıdır.
    - **Idle**: Pasif bekleme.
    - **Passive Establishment Pending**: Server bağlantı bekliyor.
    - **Active Establishment Pending**: Client bağlantı başlatmış.
    - **Established**: Bağlantı kurulmuş, veri alışverişi.
    - **Passive/Active Disconnect Pending**: Bağlantı sonlandırma aşamasında.
    - **Idle**: Bağlantı sona ermiş.
    - Network layer "vahşi batı" gibi çalışır (kayıp, sırasız, bozuk); transport layer bu kaosu düzene sokar.
  - Socket, Bind, Listen, Accept
    - **Socket**: Transport adresini tanımlayan veri yapısı (file descriptor gibi).
    - **Bind**: Soket'i belirli bir IP ve port'a bağlama.
    - **Listen**: Dinleme kuyruğu oluşturma (backlog parametresi ile).
    - **Accept**: Gelen bağlantı isteğini kabul etme; multiplexing tablosu kullanarak her isteği farklı iç porta yönlendirme.
    - Örnek: Google 80 portunu dinler; gelen istekler 10000-10740 arası iç portlara dağıtılır. Telefon santralı benzetmesi.
  - Connection Establishment Problemleri
    - Gecikmiş (delayed) paket: Karşı taraf cevap gelmeyince zaman aşımı ile yeni istek gönderir; eski cevap geç gelirse, karşı taraf aynı bağlantıyı iki kez kurmuş olur.
    - Duplicate paket: Aynı paket iki kez gelirse, eski durum ile yeni durum karıştırılabilir.
    - Çözüm: 3-way handshake (SYN, SYN+ACK, ACK) ve sequence number kullanımı.
    - Gecikmenin üst sınırı bilinmediğinden, üst sınır koyup aşan paketleri "kayıp" saymak gerekir.
* **Hocanın Vurgusu:**
  - Connectionless vs connection-oriented dört kombinasyon
    - Network layer connectionless + transport connectionless → UDP.
    - Network layer connectionless + transport connection-oriented → TCP.
    - Diğer iki kombinasyon teorik olarak mümkün ama pratikte yaygın değil.
  - Port numarasının önemi
    - Bir IP adresi tek başına yeterli değildir; aynı IP'de birden fazla uygulama çalışabilir (örn. web + mail + ssh). Port, bu ayrımı sağlar.
  - Accept'in multiplexing'deki rolü
    - Eğer sadece bir bağlantı kabul edilebilse, Google aynı anda milyonlarca kullanıcıya hizmet veremezdi. Accept, gelen istekleri farklı iç portlara dağıtarak multiplexing sağlar.
  - Network layer'ın "vahşi batı" oluşu
    - Hoca, network layer için "kelimenin tam anlamıyla vahşi batı" der; paketler kaybolur, sırasız gelir, her türlü sorun yaşanır. Transport layer, bu kaotik ortamı düzene sokar.
* **Detaylı Açıklamalar:** Transport katmanı, network katmanının güvensizliğini soyutlar. Network katmanı "best-effort" çalışır; en iyi çabayı gösterir ama garanti vermez. Transport katmanı ise uygulamaya "sıralı, hatasız, kayıpsız veri akışı" sözü verir. Bu, tekrar gönderim, sıralama, hata tespiti gibi mekanizmalarla sağlanır. Port kavramı, transport katmanının en temel bileşenidir. Aynı IP adresine sahip bir sunucu, farklı portlarda farklı hizmetler sunabilir. Örneğin, bir sunucu 80 portunda HTTP, 22 portunda SSH, 25 portunda SMTP hizmeti verebilir. Bu sayede tek bir IP, birden fazla rol üstlenir. Soket programlama, port kavramının pratiğe dökülmüş halidir. C'deki `socket()`, `bind()`, `listen()`, `accept()` fonksiyonları, transport adreslerini oluşturur, bağlar, dinler ve kabul eder. Aynen bir dosya açmak gibi, ama dosya yerine network bağlantısı. Bu soyutlama, programcıların dosya işlemleri gibi network işlemleri yapmasını sağlar. Connection establishment, güvenilir bir bağlantının kurulması sürecidir. En temel sorun: network'te duplicate veya gecikmiş paketler olabilir. Eğer bir bağlantı isteği kaybolursa, gönderici tekrar gönderir. Karşı taraf bunu yeni bir istek olarak algılar ve bağlantı kurar. Ancak aslında bu, aynı bağlantının iki kez kurulması demektir. Çözüm: sequence number kullanmak. Her bağlantı isteğine benzersiz bir numara verilir; karşı taraf bunu hatırlar ve aynı numarayla gelen tekrarı reddeder. 3-way handshake (SYN → SYN+ACK → ACK) bu mantıkla çalışır. Hoca, gecikmiş paketler için pratik bir sınır koyma gerekliliğini vurgular. Network'te bir paketin en fazla ne kadar gecikebileceğini bilemeyiz; bu nedenle bir üst sınır (timeout) belirlenir. Bu süreyi aşan paket "kayıp" sayılır ve yeniden gönderilir. Bu, basit ama etkili bir yaklaşımdır; gerçek dünyada da benzer şekilde çalışır (örn. bir mektup uzun süre gelmezse, karşı taraf "gelmemiş" sayar).

### 🔹 Ders 11: Bağlantı Sonlandırma: Asimetric/Symmetric, Two Army Problemi
* **Genel Konular:**
  - Connection Release (Bağlantı Sonlandırma)
    - Bağlantı kurmak kadar sonlandırmak da hassas bir süreçtir; network katmanı güvenilir olmadığı için son pakete kadar verilerin düzgün iletilmesi garanti edilmelidir.
    - Duplex (çift yönlü) haberleşmede her iki yön bağımsız uniplex akışla sağlanır; bu nedenle bir taraf bağlantıyı kapatmak istese, diğer taraftan hâlâ veri akabilir.
    - Asimetric release: A tarafı disconnect isteği gönderir; bu istek B'ye ulaştığında, A→B yönü kapanır ama B→A yönü hâlâ açıktır. B, kendi verisini bitirip sonra kendisi de disconnect gönderir.
    - Symmetric release: İki tarafın aynı anda bağlantıyı kapatmaya karar vermesi gerekir; bu, transport layer'ın tek başına çözemeyeceği bir problemdir (two army problem).
  - Two Army Problem (İki Ordu Problemi)
    - Beyaz bayraklılar vadide, siyah bayraklılar iki tarafta (toplam 4 siyah vs 3 siyah).
    - Siyahlar saldırıda başarılı olmak için eş zamanlı saldırmalı; birbirleriyle mesajlaşmaları gerekir.
    - Ancak mesajlaşma vadiden geçer ve beyazlar tarafından görülür.
    - Bu, senkronize kapanma probleminin neden tek başına transport layer ile çözülemeyeceğini gösterir; üst katman (uygulama) müdahalesi gerekebilir.
  - Üç Yönlü El Sıkışma ile Bağlantı Sonlandırma
    - 3 mesajlaşma ile bağlantı sonlandırılabilir: DR (Disconnect Request) → DR (karşı taraftan) → ACK.
    - Her iki taraf bir timer başlatır; bu timer, ağda hâlâ dolaşan paketlerin (farklı yollardan farklı gecikmelerle) hedefe ulaşmasını bekleyecek kadar uzun olmalıdır.
    - Normal koşullarda 3-way handshake (kurulumdakine benzer şekilde) bağlantı sonlandırmada da kullanılabilir; ancak kavramsal olarak "3-way handshake" denilince genellikle bağlantı kurulumu kastedilir.
  - En Kötü Durum Senaryoları
    - **Senaryo 1**: Final ACK kaybolur. Host2 timer'ı başlatır, tekrar retransmission yapar.
    - **Senaryo 2**: DR kaybolur. Host1 tekrar retransmission yapar.
    - **Senaryo 3**: Ağ çok kötü durumda; her iki taraf da timeout'a uğrar. Bu durumda her iki taraf bağlantıyı zorla kapatır; olası veri kaybı kabul edilir.
* **Hocanın Vurgusu:**
  - 3-way handshake'in bağlantı kurulumu ile ilişkilendirilmesi
    - Hoca, "3-way handshake" dendiğinde akla ilk gelenin bağlantı kurulumu olduğunu, bu nedenle bağlantı sonlandırmada bu terimin kullanılmaması gerektiğini vurgular. Yanlış kullanım öğrencileri yanıltabilir.
  - Two army problem'in önemi
    - Transport layer'ın sınırlarını gösterir: senkronize kapatma sorunu üst katmanın yardımı olmadan çözülemez. Bu, gerçek hayatta da karşımıza çıkan bir problemdir.
  - Timer'ın önemi
    - Network'te hâlâ dolaşan paketler için yeterli süre beklenmelidir. Bu süre, network'ün en kötü gecikmesine göre belirlenmelidir; aksi takdirde veri kaybı yaşanır.
* **Detaylı Açıklamalar:** Bağlantı sonlandırma, bağlantı kurulumu kadar dikkat gerektiren bir süreçtir. Çünkü güvenilir bir bağlantıda, bağlantı sonlandırılmadan önce gönderilen tüm verilerin karşı tarafa ulaşmış olması garanti edilmelidir. Bunu sağlamak için, network'te hâlâ dolaşan paketlerin teslim edilmesi beklenmelidir. Hoca, duplex haberleşmenin aslında iki ayrı uniplex akıştan oluştuğunu vurgular. Bu nedenle, bir taraf bağlantıyı kapatmak istediğinde, sadece kendi yönündeki akışı durdurur. Karşı taraf hâlâ veri gönderebilir. Karşı taraf verisini bitirip kendi disconnect isteğini gönderdiğinde, bağlantı tamamen sonlanır. Asimetric release, iki tarafın bağımsız hareket edebildiği bir senaryodur. A disconnect isteği gönderir; B bunu alır ve onaylar. A artık veri göndermeyi durdurur; ama B hâlâ A'ya veri gönderebilir. B de kendi verisini bitirip disconnect isteği gönderdiğinde, bağlantı tamamen kapanır. Bu, pratikte yaygın olan modeldir. Symmetric release ise daha karmaşıktır. İki tarafın aynı anda kapatmaya karar vermesi gerekir. Ancak bu, two army problemi nedeniyle tek başına transport katmanıyla çözülemez. Çünkü "ben kapatıyorum" mesajı kaybolabilir; karşı taraf "acaba gerçekten kapatıyor mu?" diye emin olamaz. Pratikte, üst katman (uygulama) bu senkronizasyonu sağlar (örn. "Dosya aktarımı tamamlandı, şimdi kapat" mesajı uygulama seviyesinde değiş tokuş edilir). Two army problem, eş zamanlı karar verme problemlerinin klasik örneğidir. İki taraf, karşı tarafın da aynı anda harekete geçeceğinden emin olmadan harekete geçmemelidir. Ama "emin olma" mesajı da aynı sorunu taşır. Bu, bazı durumlarda üst katman müdahalesi gerektiren bir sınırdır. 3-way handshake (DR → DR → ACK) ile bağlantı sonlandırma, normal koşullarda çalışır. Her iki taraf bir timer başlatır; bu timer, ağda hâlâ dolaşan paketlerin (farklı yollardan farklı gecikmelerle) hedefe ulaşmasını bekleyecek kadar uzun olmalıdır. Ancak ağ çok kötü durumdaysa (her iki taraf da timeout'a uğrarsa), bağlantı zorla kapatılır ve olası veri kaybı kabul edilir.

### 🔹 Ders 12: UDP, RPC, RTP, TCP'ye Giriş
* **Genel Konular:**
  - UDP (User Datagram Protocol)
    - Connectionless transport protokolü; en basit, en hafif transport katmanı protokolü.
    - Header yapısı (8 byte):
      - Source Port (16 bit): Kaynak uygulamanın port numarası.
      - Destination Port (16 bit): Hedef uygulamanın port numarası.
      - Length (16 bit): Header + veri toplam uzunluğu (min 8 byte).
      - Checksum (16 bit): Hata tespiti; isteğe bağlı olarak 0 bırakılabilir.
    - Checksum hesabı, IP header checksum'a benzer: 1'e göre komplemanı alınarak yapılır.
    - IP'de Protocol alanında UDP = 17.
    - Fragmentation, sıralama, akış kontrolü, tıkanıklık kontrolü YOKTUR.
    - Tek parça halinde gönderilir/alınır; ideal olarak tek bir data link frame'ine sığmalıdır.
  - UDP'nin Kullanım Alanları
    - **DNS**: Bir soru bir cevap, basit istek-cevap yapısı; function call benzeri.
    - **RPC (Remote Procedure Call) / RMI (Remote Method Invocation)**: Uzaktaki bir servisi çağırma; UDP üzerinde çalışabilir.
    - Gerçek zamanlı uygulamalar (ses/görüntü aktarımı) için taban olarak kullanılır (RTP gibi protokoller UDP üzerine kurulur).
    - Avantaj: Düşük overhead, hızlı kurulum, basitlik.
  - RPC (Remote Procedure Call) / RMI
    - Lokaldeki bir fonksiyon çağrısını uzaktaki bir sisteme taşıma mekanizmasıdır.
    - Stub: Client ve server tarafında, parametreleri network'e uygun formata dönüştüren kod parçaları.
    - Programcı, network detaylarıyla uğraşmadan uzaktaki servisi sanki lokalde çağırıyormuş gibi yazar.
    - C'de pointer gibi yapılar sorun çıkarır (karşı tarafta anlamsız); bunun çözümü pointer'ın gösterdiği alanın tamamını göndermektir.
    - UDP ile çalışırken güvenilirlik uygulama seviyesinde sağlanmalıdır (retransmission).
    - Avantaj: abstraction, geliştirici verimliliği; dezavantaj: pointer/veri yapısı dönüşümü, performans.
  - RTP (Real-time Transport Protocol)
    - UDP üzerine kurulu bir transport protokolü (paradoks gibi görünür, ama user space'te çalışan bir kütüphane).
    - Multimedia (ses, görüntü) akışı için tasarlanmıştır.
    - Temel özellikler:
      - **Sequence number**: Paket sırasını belirleme; kayıp tespiti.
      - **Timestamp**: Zaman senkronizasyonu; jitter hesaplama.
      - **Source identifier**: Hangi kaynaktan geldiğini belirleme.
      - **Payload type**: Veri tipi (ses, video, vb.).
      - **Marker**: Frame başlangıcı gibi önemli noktaları işaretleme.
    - RTCP (RTP Control Protocol): Akış kalitesi kontrolü, istatistik toplama; "RTCP'deki TCP, Transmission Control Protocol ile ilgisi yoktur" vurgusu önemlidir.
  - Jitter ve Buffer Yönetimi
    - Jitter: Gecikmenin ortalama değerinden sapmalarıdır; paketler arası gecikme farkları.
    - Sabit hızda gönderilen paketler (constant rate) network'te farklı gecikmelerle ulaşır.
    - Destination'da buffer ile jitter absorbe edilir; buffer'ın sınırları vardır (sonsuz değildir).
    - Eğer buffer yetersizse, paket kaçırılır (miss) ve resync gerekir (sequence number, timestamp ile).
    - Real-time playback: Önceki ve sonraki frame arasındaki süre kadar geçerli; bu süre dışındaki buffer birikimi anlamsızdır.
  - TCP'ye Giriş
    - Connection-oriented, güvenilir transport protokolü.
    - Service model: Byte stream (sıralı, hatasız, kayıpsız).
    - TCP başlıca yapılar: sequence number, ACK, sliding window, timer, retransmission.
    - Port numaraları well-known portlar (0-1023) ve dinamik portlar (1024+) olarak ikiye ayrılır.
    - FTP: 21 (kontrol) + 20 (veri); SSH: 22; SMTP: 25; DNS: 53; HTTP: 80; HTTPS: 443; POP3: 110; IMAP: 143.
    - Application-layer: TCP/IP'nin güvenilirliği, uygulamaların ihtiyacına göre tasarlanmıştır; ağ katmanının sınırları kabul edilir, üst katmanda çözüm üretilir.
* **Hocanın Vurgusu:**
  - UDP'nin "işe yaramaz" olmadığı
    - UDP basit görünür ama birçok kritik uygulama için idealdir. DNS, RPC, gerçek zamanlı uygulamalar UDP kullanır.
  - RPC'nin pointer sorunu
    - C gibi dillerde pointer'lar lokal adreslerdir; karşı tarafta anlamsızdır. Bu, RPC implementasyonunda dikkat edilmesi gereken önemli bir noktadır. Çözüm: pointer'ın gösterdiği alanı olduğu gibi göndermek.
  - RTP'nin "transport üzerine transport" paradoksu
    - RTP, UDP üzerine kuruludur; ama aslında bir transport protokolüdür. Bu, katmanlı yapının her zaman katı olmadığını gösterir. Pratikte, RTP user space'te çalışan bir kütüphanedir.
  - RTCP'nin TCP ile ilişkisi yok
    - Hoca özellikle uyarır: RTCP'deki "TCP" harfleri, Transmission Control Protocol ile ilgili değildir; bu karışıklık sorularda sıkıntı yaratabilir.
  - TCP'nin temel özellikleri
    - Connection-oriented, reliable, byte stream, full-duplex.
    - Flow control (sliding window) ve congestion control mekanizmaları vardır.
    - TCP üzerinde uygulama geliştirmek için socket API kullanılır.
* **Detaylı Açıklamalar:** UDP, transport katmanının en basit protokolüdür. Sadece 8 byte'lık bir header ekler; geri kalan her şey uygulamaya bırakılmıştır. Bu, hem avantaj hem dezavantajdır: basit olduğu için hızlıdır, ama güvenilirlik yoktur. Modern internet'te UDP, çoğu zaman "alt yapı" olarak kullanılır; üzerine RTP gibi daha akıllı protokoller kurulur. RPC, dağıtık sistemlerin temel yapı taşlarından biridir. Bir programcı, lokalde `calculate(x, y)` çağrısı yaptığında, bu çağrı aslında uzaktaki bir sunucuya gider, orada çalışır, sonuç geri döner. Programcı network detaylarını bilmez; sadece fonksiyonu çağırır. Bu, geliştirici verimliliğini büyük ölçüde artırır. Ancak pointer, struct, array gibi karmaşık veri tiplerinin aktarımı zorluk çıkarır; çünkü farklı sistemlerde farklı temsiller (endianness, alignment) olabilir. RTP, gerçek zamanlı multimedia akışı için tasarlanmış bir protokoldür. UDP üzerine kurulu olması paradoks gibi görünür çünkü UDP güvenilir değildir. Ancak RTP'nin amacı, gerçek zamanlı akış için yeterli bilgiyi (sıra numarası, zaman damgası, kaynak kimliği) sağlamaktır; güvenilirlik uygulamanın sorumluluğundadır. RTP, kullanıcı alanında (user space) çalışan bir kütüphanedir, kernel'a gömülü değildir. Jitter yönetimi, gerçek zamanlı uygulamaların en önemli sorunlarından biridir. Sabit hızda üretilen bir video akışı, network'te farklı gecikmelerle ulaşır. Eğer destination'da anında oynatılırsa, kullanıcı sık sık duraksamalar veya atlamalar görür. Çözüm: bir buffer ile jitter absorbe edilir. Ancak buffer sonsuz değildir; gerçek zamanlı akışlarda, bir frame'in geçerliliği bir sonraki frame'e kadardır. Bu nedenle, çok eski frame'ler biriktirilemez; buffer'dan zamanında oynatılmalıdır. TCP, transport katmanının en karmaşık ve en yaygın protokolüdür. Connection-oriented yapısı, sliding window ile akış kontrolü, retransmission ile güvenilirlik sağlar. Uygulamalar, TCP üzerinden güvenli bir byte stream olarak iletişim kurar. TCP, network katmanının güvenilmezliğini tamamen soyutlar; uygulama, paket kaybı, sırasız gelme gibi sorunlarla uğraşmak zorunda kalmaz.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
