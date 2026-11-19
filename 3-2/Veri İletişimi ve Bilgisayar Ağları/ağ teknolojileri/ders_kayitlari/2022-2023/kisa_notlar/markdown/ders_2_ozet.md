# Ders 2 Çalışma Özeti

## Genel Konular

- Ağ çekirdeği (network core) ve iki temel işlevi
  - Çekirdek, birbirine bağlı yönlendiricilerden (router) oluşan bir ağdır (mesh). Görevi, gelen paketi doğru çıkış yönüne iletmektir.
  - Çekirdekte paket anahtarlama kullanılır: Uç sistem, uygulama katmanı mesajını paketlere böler; her paket bir giriş portundan çıkış portuna bağlantının tam kapasitesiyle iletilir.
  - **Yönlendirme (routing):** Global bir işlemdir. Kaynaktan hedefe paketlerin izleyeceği yol, yönlendirme algoritmalarıyla belirlenir.
  - **İletme (forwarding):** Yerel bir işlemdir. Yönlendirici, gelen paketin başlığındaki hedef adrese bakıp yerel iletme tablosuna göre paketi uygun çıkış bağlantısına aktarır.
  - Slayttaki tablo örneği: başlık değeri `0100` → çıkış 3, `0101` → 2, `0111` → 2, `1001` → 1. Giriş portu 3'ten gelen `0111` adresli paket çıkış 2'ye iletilir (ekrandan, 00:10:00).
  - Hocanın benzetmesi: ABD'nin batısından doğusuna araçla gitmek. Uygun güzergâhı bulmak yönlendirmedir; her kavşakta (interchange) doğru çıkış yolunu seçmek iletmedir.
- Paket anahtarlama: depola ve ilet (store-and-forward)
  - Paket $L$ bit, bağlantı hızı $R$ bit/s ise iletim gecikmesi $L/R$ saniyedir.
  - Paketin tamamı yönlendiriciye ulaşmadan bir sonraki bağlantıya gönderilemez.
  - Tek yönlendiricili yolda (yayılım gecikmesi sıfır kabul edilirse) uçtan uca gecikme $2L/R$ olur.
  - Tek atlamalı sayısal örnek: $L = 10$ Kbit, $R = 100$ Mbps, iletim gecikmesi $= 0{,}1$ ms (ekrandan, 00:15:00).
- Paket anahtarlamada kuyruk ve kayıp
  - Örnek: A ve B, 100 Mb/s bağlantılarla yönlendiriciye bağlı; yönlendiriciler arası bağlantı 1,5 Mb/s (ekrandan, 00:20:00). Paketler, çıkabildiğinden hızlı geldiği için kuyruğa girer.
  - Kuyruklanma, iş hizmet verilebildiğinden hızlı geldiğinde oluşur (gişe, bina girişi, otobüs durağı kuyrukları benzetmesi).
  - Yönlendiricinin tamponu (buffer) sınırlıdır; tampon dolarsa gelen paket düşürülür (kayıp).
- Devre anahtarlama (circuit switching)
  - Kaynak ile hedef arasında baştan uca kaynaklar ayrılır (çağrı/call için rezerve edilir); paylaşım yoktur, ayrılan kapasite tam ve garantili kullanılır.
  - Hat kullanılmadığında ayrılan kapasite boşa gider. Geleneksel olarak telefon ağlarında (PSTN) kullanılır.
  - Paylaşım yöntemleri:
    - **FDM (frekans bölmeli çoğullama):** Frekans aralığı dar bantlara bölünür; her çağrı kendi bandını sürekli kullanır, en fazla o dar bandın hızıyla iletir.
    - **TDM (zaman bölmeli çoğullama):** Zaman dilimlere bölünür; her çağrı periyodik dilimler alır ve kendi diliminde bağlantının tüm (geniş bant) hızını kullanır.
- Paket anahtarlama ile devre anahtarlamanın karşılaştırılması
  - Örnek (ekrandan, 00:30:00): 1 Gb/s bağlantı; her kullanıcı aktifken 100 Mb/s ister ve zamanın %10'unda aktiftir.
  - Devre anahtarlamada en fazla $1\text{ Gb/s} / 100\text{ Mb/s} = 10$ kullanıcı desteklenir.
  - Paket anahtarlamada 35 kullanıcı ile aynı anda 10'dan fazla kullanıcının aktif olma olasılığı yaklaşık 0,0004'tür. Bu yüzden paket anahtarlama daha çok kullanıcıya izin verir.
  - Paket anahtarlama patlamalı (bursty) veri için idealdir: kaynak paylaşımı vardır ve çağrı kurulumu gerekmez.
  - Dezavantajı: aşırı tıkanıklıkta gecikme ve tampon taşmasından kayıp; bu yüzden güvenilir veri aktarımı ve tıkanıklık denetimi protokolleri gerekir.
  - Paket anahtarlamalı ağda devre benzeri davranış (sanal devre, bant genişliği garantisi) ses ve video uygulamaları için gündeme gelir.
- İnternetin yapısı: ağların ağı
  - Uç sistemler erişim ISP'leri (ev, kurum, ticari) üzerinden bağlanır; erişim ISP'lerinin de birbirine bağlanması gerekir.
  - Her ISP'yi birbirine doğrudan bağlamak ölçeklenmez ($O(N^2)$ bağlantı).
  - Çözüm: erişim ISP'leri global ISP'lere bağlanır; birden çok global ISP, IXP (internet değişim noktası) ya da doğrudan eşleme (peering) bağlantılarıyla birbirine bağlanır. Arada bölgesel ISP'ler bulunur.
  - Merkezde az sayıda iyi bağlı büyük ağ (Tier 1 ISP: Level 3, Sprint, AT&T gibi) vardır.
  - İçerik sağlayıcı ağlar (Google, Microsoft, Akamai, Facebook) kendi ağlarını kurar, veri merkezlerini çoğu zaman Tier 1 ve bölgesel ISP'leri atlayarak internete bağlar; içeriği son kullanıcıya yaklaştırırlar.
  - Tier 1 ISP haritasında POP (point of presence) noktaları, eşleme ağlarına ve müşteri ağlarına bağlantılar görülür.
- Performans: gecikme, kayıp ve verim (throughput)
  - Düğüm gecikmesi: $d_{nodal} = d_{proc} + d_{queue} + d_{trans} + d_{prop}$ (ekrandan, 00:45:00).
    - $d_{proc}$: bit hatası denetimi ve çıkış bağlantısının belirlenmesi; genellikle milisaniyeden az.
    - $d_{queue}$: çıkış bağlantısında iletim için bekleme; yönlendiricinin tıkanıklık düzeyine bağlıdır.
    - $d_{trans} = L/R$: paketi bağlantıya basma süresi.
    - $d_{prop} = d/s$: $d$ fiziksel bağlantı uzunluğu, $s$ yayılım hızı (yaklaşık $2\times10^8$ m/s).
  - Kervan benzetmesi (ekrandan, 01:00:00): 10 araçlık kervan (10 bitlik paket), gişeler arası 100 km, araç hızı 100 km/sa, gişe hizmeti araç başına 12 s. Kervanın gişeden geçmesi $12\times10=120$ s, son aracın ikinci gişeye ulaşması 1 sa; toplam 62 dakika.
  - Kuyruk gecikmesi ve trafik yoğunluğu: $La/R$ ($a$: ortalama paket geliş hızı). $La/R \approx 0$ ise gecikme küçük, $La/R \to 1$ ise büyük, $La/R > 1$ ise gelen iş hizmet verilebilecekten fazladır ve ortalama gecikme sonsuza gider.
  - Traceroute: Hedefe giden yoldaki her $i$. yönlendiriciye üç paket gönderilir (yaşam süresi alanı $i$); yönlendirici yanıt döner, gönderici gidiş-dönüş süresini ölçer. `*` işareti yanıt gelmediğini (kayıp) gösterir.
  - Kayıp: Dolu kuyruğa gelen paket düşürülür; önceki düğüm, kaynak ya da hiç kimse tarafından yeniden gönderilebilir (protokole bağlı).
  - Verim: gönderenden alıcıya bitlerin aktarılma hızı (bit/s). Anlık ve ortalama verim ayrılır.
    - Sunucu bağlantısı $R_s$, istemci bağlantısı $R_c$ ise uçtan uca verim $\min(R_s, R_c)$; verimi kısıtlayan bağlantı darboğaz bağlantısıdır (ekrandan, 01:10:00).
    - 10 bağlantının ortak $R$ hızlı bir bağlantıyı paylaştığı senaryoda bağlantı başına verim $\min(R_c, R_s, R/10)$; pratikte darboğaz çoğunlukla $R_c$ ya da $R_s$'tir.
- Protokol katmanları ve hizmet modelleri
  - Havayolu yolculuğu benzetmesi: bilet (alma/şikâyet), bagaj (teslim/alım), kapı (biniş/iniş), pist (kalkış/iniş), uçak yönlendirme (ekrandan, 01:15:00). Her katman alt katmanın hizmetine dayanarak kendi hizmetini verir.
  - Katmanlamanın faydası: karmaşık sistemin parçaları ve ilişkileri açıkça tanımlanır; modülerlik bakım ve güncellemeyi kolaylaştırır.
  - İnternet protokol yığını (5 katman):
    - Uygulama: ağ uygulamaları (HTTP, IMAP, SMTP, DNS).
    - Taşıma: süreçten sürece veri aktarımı (TCP, UDP).
    - Ağ: datagramın kaynaktan hedefe yönlendirilmesi (IP, yönlendirme protokolleri).
    - Bağlantı: komşu ağ elemanları arasında aktarım (Ethernet, Wi-Fi, PPP).
    - Fiziksel: kablodaki bitler (elektrik sinyali, elektromanyetik dalga).
  - Kapsülleme: mesaj $M$ → segment ($H_t + M$) → datagram ($H_n + H_t + M$) → çerçeve ($H_l + H_n + H_t + M$). Hoca bunu iç içe Matruşka bebeklerine benzetti.
- Ağ güvenliği
  - İnternet başlangıçta güvenlik düşünülerek tasarlanmadı ("birbirine güvenen kullanıcılar"); tasarımcılar sonradan güvenlik ekliyor.
  - Saldırılar: paket koklama (packet sniffing, paylaşımlı ortamda tüm paketlerin kaydedilmesi), IP sahteciliği (IP spoofing, sahte kaynak adresi), hizmet engelleme (DoS, botlarla hedefin bant genişliğini doldurma), kötücül yazılım (virüs, solucan, casus yazılım, botnet).
  - Savunma hatları (ekrandan, 01:30:00): kimlik doğrulama (hücresel ağlarda SIM kart), gizlilik (şifreleme), bütünlük denetimi (dijital imza), erişim kısıtlama (parola korumalı VPN), güvenlik duvarları ve ara kutular, saldırı tespit/önleme sistemleri (IDS/IPS).
- İnternet tarihi
  - Paket anahtarlama ilkeleri, ARPANET (1969'da ilk düğüm), 1972'de ARPANET halka açık gösterimi ve NCP.
  - 1970'ler: ALOHAnet uydu ağı (Hawaii), Cerf ve Kahn'ın ağ bağlama mimarisi; ilkeleri bugün de geçerli: minimalizm, özerklik, en iyi çaba (best effort) hizmet modeli, durumsuz yönlendirme, merkeziyetsiz denetim.
  - 1980'ler: TCP/IP yaygınlaşması, SMTP, DNS, FTP, TCP tıkanıklık denetimi.
  - 1990'lar: ticarileşme, web (HTML, HTTP), tarayıcılar (Mosaic, Netscape), P2P paylaşım, ağ güvenliği.
  - 2005-günümüz: geniş bant ev erişimi (10-100 Mbps), 2008 yazılım tanımlı ağ (SDN), 4G/5G ve Wi-Fi, büyük sağlayıcıların kendi ağları, bulut hizmetleri, mobil cihazların sabitleri geçmesi (ekrandan, 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yönlendirme ile iletme farkı
  - Yönlendirme global (yol bulma), iletme yereldir (iletme tablosuna göre girişten çıkışa aktarma). Hoca bu ayrımı yol ve kavşak benzetmesiyle tekrar tekrar anlattı.
- İletim gecikmesi ile yayılım gecikmesi farklıdır
  - $d_{trans} = L/R$ paketi hatta basma süresidir ve bağlantı kapasitesine bağlıdır; $d_{prop} = d/s$ sinyalin hattın bir ucundan öbürüne gitme süresidir ve uzunluğa bağlıdır.
- Paket anahtarlamanın üstünlüğü
  - Aynı bağlantıda devre anahtarlama 10, paket anahtarlama 35 kullanıcıya hizmet verebilir; çünkü kullanıcılar zamanın yalnız %10'unda aktiftir.
- Kuyruk, gecikme ve kayıp ilişkisi
  - Gelen hız çıkış kapasitesini aşarsa kuyruk büyür, tampon dolarsa kayıp olur. Trafik yoğunluğu $La/R$ 1'e yaklaştıkça gecikme hızla büyür.
- Kapsülleme terimleri
  - Uygulamada mesaj, taşımada segment, ağda datagram, bağlantıda çerçeve.

## Kısa Tekrar Notları

- Çekirdek = yönlendiricilerden oluşan ağ; paket anahtarlama kullanır.
- Routing: global, algoritma ile yol bulma. Forwarding: yerel, tabloya göre çıkış seçme.
- Store-and-forward: tek atlamada $L/R$, tek yönlendiricide uçtan uca $2L/R$.
- $10\text{ Kbit} / 100\text{ Mbps} = 0{,}1$ ms.
- Devre anahtarlama: ayrılmış kaynak, FDM (frekans bantları) ve TDM (zaman dilimleri).
- 1 Gb/s, 100 Mb/s, %10 aktiflik: devre 10 kullanıcı, paket 35 kullanıcı (P(>10 aktif) ≈ 0,0004).
- İnternet: erişim ISP → bölgesel ISP → Tier 1 ISP; IXP ve peering; içerik sağlayıcı ağları.
- $d_{nodal} = d_{proc} + d_{queue} + d_{trans} + d_{prop}$.
- $La/R > 1$: gecikme sonsuz, paket kaybı.
- Traceroute: her yönlendiriciye 3 sonda, `*` = yanıt yok.
- Verim = darboğaz bağlantının hızı: $\min(R_s, R_c)$, paylaşımlı durumda $\min(R_c, R_s, R/N)$.
- 5 katman: uygulama, taşıma, ağ, bağlantı, fiziksel.
- Mesaj → segment → datagram → çerçeve.
- Saldırılar: sniffing, spoofing, DoS, malware. Savunma: kimlik doğrulama, şifreleme, imza, VPN, firewall, IDS/IPS.

## Detaylı Açıklamalar

- **Ağ çekirdeğinde paketin yolculuğu.** Uç sistemdeki uygulama bir mesaj üretir, mesaj paketlere bölünür ve çekirdeğe gönderilir. Çekirdekteki her yönlendirici gelen paketin başlığındaki hedef adrese bakar ve yerel iletme tablosundan çıkış bağlantısını bulur. Slayttaki örnekte giriş portu 3'ten gelen ve başlığında `0111` bulunan paket, tabloda `0111 → 2` satırı olduğu için çıkış bağlantısı 2'ye verilir. Bu tablonun içeriği ise yönlendirme algoritmaları tarafından hesaplanır. Yani yönlendirme algoritması "hangi yoldan gidilmeli" sorusunu bütün ağ için çözer, iletme ise her yönlendiricide "bu paketi hangi çıkışa vermeliyim" sorusunu yerel olarak cevaplar. Hoca bunu ABD'nin bir ucundan öbür ucuna arabayla gitme benzetmesiyle anlattı: haritada güzergâhı seçmek yönlendirme, her kavşakta doğru çıkışı almak iletmedir. <!-- BELİRSİZ: Benzetmedeki şehir adları ve iki güzergâhın mil/saat değerleri altyazıda bozuk; karede görülmedi. -->
- **Depola ve ilet.** Yönlendirici bir paketi ancak tamamı geldikten sonra çıkışa verebilir. $L$ bitlik paketin $R$ bit/s hızlı bağlantıya basılması $L/R$ saniye sürer. Kaynak, yönlendirici ve hedeften oluşan yolda bir paket önce kaynakta $L/R$, sonra yönlendiricide yine $L/R$ sürede iletilir; yayılım gecikmesi sıfır kabul edilirse uçtan uca gecikme $2L/R$ olur. Örnekte $L=10$ Kbit, $R=100$ Mbps için $L/R = 10^4/10^8 = 10^{-4}$ s $=0{,}1$ ms bulunur.
  - Ders sonrası not: Hoca örnekte bir an "$L$ saniyede 10 kilobit, $R$ paketin boyutu" dedi; doğrusu slayttaki gibidir: $L = 10$ Kbit paket boyu, $R = 100$ Mbps bağlantı hızıdır.
- **Kuyruk ve kayıp.** Slayttaki örnekte A ve B konakları 100 Mb/s bağlantılarla bir yönlendiriciye bağlıdır, ama yönlendiriciden sonraki bağlantı 1,5 Mb/s'tir. Paketler yönlendiriciye çıkabildiklerinden hızlı geldiği için yönlendirici onları tamponda bekletir. Böylece iletim gecikmesine bir de kuyruk gecikmesi eklenir. Tampon sınırlı olduğundan, kuyruk doluyken gelen paket düşürülür. Hoca kuyruğu otoyol gişesindeki araç yığılmasına, tek kapılı binaya girişe ve otobüs durağı kuyruğuna benzetti.
- **Devre anahtarlama ve çoğullama.** Devre anahtarlamada iletişim başlamadan önce kaynakla hedef arasında bir devre kurulur ve bu devrenin kaynakları yalnız o çağrıya ayrılır. Kullanıcı ayrılan kapasitenin tamamını garantili kullanır, ama konuşma ya da veri olmadığında bu kapasite boşta kalır ve başkası kullanamaz. Telefon ağları bu mantıkla çalışır. Bir bağlantıyı birden çok devreye bölmek için iki yol vardır. FDM'de frekans aralığı dar bantlara bölünür ve her çağrı kendi bandını sürekli kullanır. TDM'de zaman periyodik dilimlere bölünür ve her çağrı kendi diliminde bağlantının bütün hızını kullanır, ama yalnız o dilim süresince.
- **Neden paket anahtarlama?** 1 Gb/s'lik bağlantıyı, aktifken 100 Mb/s isteyen ve zamanın %10'unda aktif olan kullanıcılar paylaşsın. Devre anahtarlamada her kullanıcıya 100 Mb/s ayrılması gerektiğinden en fazla 10 kullanıcı bağlanabilir. Paket anahtarlamada 35 kullanıcı olsa bile aynı anda 10'dan fazlasının aktif olma olasılığı çok küçüktür (yaklaşık 0,0004); yani neredeyse her zaman her kullanıcı 100 Mb/s'ye kadar hız alır. Paket anahtarlama patlamalı trafik için idealdir ve kurulum gerektirmediği için basittir. Bedeli, aşırı yükte gecikme ve kayıptır; bunun için güvenilir aktarım ve tıkanıklık denetimi protokolleri gerekir.
  - Ders sonrası not: Binom dağılımıyla hesaplanınca $P(X>10)$, $X \sim B(35;\,0{,}1)$ için yaklaşık $0{,}00042$ çıkar (python ile hesaplandı). Slayttaki "less than .0004" ifadesi bu yüzden tam değil; doğrusu "yaklaşık 0,0004"tür. Hoca bir yerde "45 kullanıcı" dedi; slayttaki değer 35'tir.
- **İnternetin yapısı.** Milyonlarca erişim ISP'sini birbirine doğrudan bağlamak $N^2$ mertebesinde bağlantı gerektirir ve ölçeklenmez. Bu yüzden erişim ISP'leri global ISP'lere bağlanır. Global ISP'ler birbirine rakip olsa da birbirine bağlanmak zorundadır; bunu IXP'ler ya da doğrudan peering bağlantılarıyla yaparlar. Arada bölgesel ISP'ler bulunur. En üstte Tier 1 ISP'ler yer alır. Google, Facebook, Microsoft gibi içerik sağlayıcılar ise kendi ağlarıyla veri merkezlerini internete bağlar ve içeriği son kullanıcıya olabildiğince yakın tutar.
  - Ders sonrası not: Hoca IXP'yi bir yerde "internet access point" diye açtı; doğrusu "Internet Exchange Point"tir. Altyazıda "Kamayi" geçen içerik ağı büyük olasılıkla Akamai'dir.
- **Gecikmenin dört bileşeni.** Bir düğümdeki toplam gecikme işleme, kuyruk, iletim ve yayılım gecikmelerinin toplamıdır. İşleme gecikmesi bit hatası denetimi ve çıkış bağlantısının belirlenmesinden gelir ve genelde milisaniyenin altındadır. Kuyruk gecikmesi tıkanıklığa bağlıdır. İletim gecikmesi $L/R$, yayılım gecikmesi $d/s$'dir. Hoca 100 m'lik Cat 6 UTP kabloyu ve $s = 2\times10^8$ m/s'yi örnek verdi; bu durumda $d_{prop} = 100 / (2\times10^8) = 0{,}5\ \mu s$ olur (ara adım eklendi).
- **Kervan benzetmesi.** Araçlar bit, kervan paket, gişe yönlendiricidir. 10 araç, araç başına 12 s hizmetle gişeden $120$ s'de geçer (iletim). Son aracın 100 km'yi 100 km/sa hızla gitmesi 1 saat sürer (yayılım). Kervanın ikinci gişe önünde dizilmesi $60 + 2 = 62$ dakika sürer. İkinci senaryoda araçlar 1000 km/sa hızla gider ve gişe araç başına 1 dakika harcar. İlk araç 1 dakikada gişeden çıkar, 100 km'yi 6 dakikada gider ve 7. dakikada ikinci gişeye varır; bu sırada ilk gişede hâlâ 3 araç vardır. Yani paketin ilk bitleri, son bitleri ilk yönlendiriciden çıkmadan ikinci yönlendiriciye ulaşabilir.
- **Trafik yoğunluğu.** $R$ bağlantı hızı, $L$ paket boyu, $a$ ortalama paket geliş hızı ise $La/R$ oranı trafik yoğunluğudur. Oran sıfıra yakınsa kuyruk neredeyse boştur; 1'e yaklaştıkça ortalama kuyruk gecikmesi hızla büyür; 1'i geçerse gelen iş hizmet kapasitesini aşar, gecikme sonsuza gider ve paketler düşürülür. Hoca bunu E-5'e katılmak için bekleyen araç kuyruğuna benzetti.
  - Ders sonrası not: Hoca bir yerde "$L/R$" dedi; kastedilen oran $La/R$'dir.
- **Traceroute ve verim.** Traceroute, yoldaki her $i$. yönlendiriciye yaşam süresi $i$ olan üç sonda gönderir ve dönüş sürelerini ölçer; yanıt gelmeyen satırlar `*` ile gösterilir. Verim ise bitlerin gönderenden alıcıya aktarılma hızıdır. Hoca bunu su borusu benzetmesiyle anlattı: ince boru akışı sınırlar. $R_s < R_c$ ise verim $R_s$, $R_s > R_c$ ise $R_c$'dir; yani uçtan uca verimi darboğaz bağlantı belirler. 10 sunucu ve 10 istemcinin ortak bir $R$ bağlantısını paylaştığı durumda bağlantı başına verim $\min(R_c, R_s, R/10)$'dur.
  <!-- BELİRSİZ: Traceroute örnek çıktısındaki kaynak/hedef adları ve IP adresi altyazıda bozuk; karede görülmedi. -->
- **Katmanlar ve kapsülleme.** Havayolu yolculuğu bilet, bagaj, kapı, pist ve uçak yönlendirme adımlarından oluşur; her adım alttaki adımın hizmetini kullanır. Ağ da böyle katmanlara ayrılır. Uygulama katmanındaki mesaj $M$, taşıma katmanında $H_t$ başlığı eklenerek segment olur. Ağ katmanı $H_n$ başlığını ekleyip datagram oluşturur. Bağlantı katmanı $H_l$ başlığını ekleyip çerçeve oluşturur. Fiziksel katman bitleri sinyal olarak taşır. Hedefte bu başlıklar sırayla çıkarılır ve en içteki mesaj uygulamaya ulaşır.
- **Güvenlik ve tarih.** Paylaşımlı ortamda (Ethernet, kablosuz) her paket herkese ulaşır; koklama programı şifrelenmemiş parolaları bile görebilir. IP spoofing ile saldırgan paketi başka bir kaynaktan geliyormuş gibi gönderir. DoS saldırısında botlar hedefin bağlantısını doldurur. Savunma için kimlik doğrulama, şifreleme, dijital imza, erişim kısıtlama, güvenlik duvarı ve saldırı tespit/önleme kullanılır. Tarih kısmında hoca paket anahtarlama fikrinden ARPANET'e, Cerf ve Kahn'ın ağ bağlama ilkelerinden web'e ve bugünkü SDN, bulut ve mobil internete kadar ana dönemleri özetledi.
  - Ders sonrası not: Hoca Kleinrock'un paket anahtarlama çalışmasını "1991" diye söyledi; bu çalışma büyük olasılıkla 1961 tarihlidir. Hoca 1990'ların sonu için "50 milyar konak" dedi; doğrusu büyük olasılıkla yaklaşık 50 milyon konaktır. TCP/IP'nin ilk yaygın kullanımı için söylenen 1982 büyük olasılıkla 1983'tür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
