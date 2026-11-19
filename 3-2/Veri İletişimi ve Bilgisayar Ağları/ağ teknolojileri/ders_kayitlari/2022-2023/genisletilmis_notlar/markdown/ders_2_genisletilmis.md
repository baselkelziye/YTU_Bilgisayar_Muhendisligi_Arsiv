# Ders 2 Genişletilmiş Notu: Ağ Çekirdeği, Gecikme, Kayıp, Verim ve Protokol Katmanları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri ve Yol Haritası
- 2. Ağ Çekirdeği: Yönlendirme ve İletme
- 3. Paket Anahtarlama: Depola ve İlet
- 4. Kuyruklanma ve Paket Kaybı
- 5. Devre Anahtarlama, FDM ve TDM
- 6. Paket Anahtarlama mı, Devre Anahtarlama mı?
- 7. İnternetin Yapısı: Ağların Ağı
- 8. Performans: Gecikmenin Dört Kaynağı
- 9. Kervan Benzetmesi
- 10. Kuyruk Gecikmesi ve Trafik Yoğunluğu
- 11. Gerçek İnternet Gecikmeleri: Traceroute
- 12. Paket Kaybı ve Verim (Throughput)
- 13. Protokol Katmanları ve Kapsülleme
- 14. Ağ Güvenliği
- 15. İnternetin Tarihi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yeri ve Yol Haritası

Ders, giriş bölümünün ikinci ve son haftasıdır ve anlatım İngilizcedir. Hoca ilk iki haftanın tanıtım haftaları olduğunu, burada her konuya kısaca değinileceğini, ayrıntıların ilerideki haftalarda verileceğini söyledi. Slayttaki yol haritası şu başlıklardan oluşur (ekrandan, 00:05:00): İnternet nedir, protokol nedir, ağ kenarı (konaklar, erişim ağı, fiziksel ortam), ağ çekirdeği (paket/devre anahtarlama, internet yapısı), performans (kayıp, gecikme, verim), protokol katmanları ve hizmet modelleri, güvenlik ve tarih. İlk üç başlık önceki haftada işlenmişti; bu hafta ağ çekirdeğinden başlanır.

## 2. Ağ Çekirdeği: Yönlendirme ve İletme

Ağ çekirdeği, birbirine bağlı yönlendiricilerden oluşan bir ağdır (mesh). Önceki haftada görülen şekilde birçok ağın ortasında duran bu yapı, gelen paketi doğru çıkış yönüne iletmekten sorumludur. Çekirdekte paket anahtarlama kullanılır: Uç sistemdeki (host) uygulama katmanı mesajı paketlere böler ve her paket, yönlendiricinin giriş portundan çıkış portuna bağlantının tam kapasitesiyle iletilir.

Bir yönlendiricinin gelen paketi nereye vereceğine nasıl karar verdiği sorusu, iki temel işlevi ortaya çıkarır (ekrandan, 00:10:00):

- **İletme (forwarding):** Yerel bir işlemdir. Yönlendirici, giriş bağlantısına gelen paketi uygun çıkış bağlantısına aktarır. Bunun için paketin başlığındaki hedef adrese bakar ve yerel iletme tablosunu kullanır.
- **Yönlendirme (routing):** Global bir işlemdir. Paketlerin kaynaktan hedefe izleyeceği yollar yönlendirme algoritmalarıyla belirlenir. Yerel iletme tabloları bu algoritmaların sonucuyla doldurulur.

Slayttaki yerel iletme tablosu şöyledir (ekrandan, 00:10:00):

| Başlık değeri | Çıkış bağlantısı |
|---|---|
| 0100 | 3 |
| 0101 | 2 |
| 0111 | 2 |
| 1001 | 1 |

Örnekte başlığında `0111` bulunan paket yönlendiriciye giriş portu 3'ten gelir. Tabloda `0111` satırının çıkışı 2 olduğundan paket çıkış bağlantısı 2'ye verilir. Hoca, `0111` adresli bütün paketlerin çıkış 2'ye iletileceğini vurguladı.

### 2.1 Yol ve kavşak benzetmesi

Hoca farkı bir benzetmeyle açıkladı: ABD'nin batısındaki bir şehirden doğusundaki bir şehre arabayla gitmek istediğinizi düşünün. Haritada iki uygun yol vardır; biri daha uzun ama daha kısa sürede, öbürü daha kısa ama daha uzun sürede gidilir. İyi ya da en iyi yolu bulmak yönlendirme algoritmasının işidir. Yola çıktıktan sonra her kavşağa (interchange) birçok yol girer ve birçok yol çıkar. Bir yoldan kavşağa girip doğru çıkışı seçerek kavşaktan ayrılmak iletmedir. Burada kavşak yönlendiricidir, kavşaktaki yön levhaları da iletme tablosudur.

<!-- BELİRSİZ: Benzetmedeki şehir adları ve iki güzergâhın mil/saat değerleri (altyazıda yaklaşık 3502 mil/45 saat ve 3309 mil/48 saat) Whisper tarafından bozulmuş olabilir; ilgili kare yok. -->

> **Hocanın vurgusu:** Yönlendirme kaynaktan hedefe en iyi yolu bulmaktır; iletme ise yerel olarak gelen paketi doğru çıkışa vermektir. Bu ikisi birbirinden ayrılmalıdır.

## 3. Paket Anahtarlama: Depola ve İlet

Kaynaktaki mesajın küçük paketlere bölündüğünü düşünelim; örnekte üç paket vardır, her biri $L$ bittir. Kaynaktan yönlendiriciye ve yönlendiriciden hedefe giden bağlantıların hızı $R$ bit/s'dir (ekrandan, 00:15:00). Yönlendirici gelen paketi önce depolar, sonra çıkışa iletir.

- **İletim gecikmesi:** $L$ bitlik paketi $R$ bps hızlı bağlantıya basmak (push out) $L/R$ saniye sürer.
- **Depola ve ilet:** Paketin tamamı yönlendiriciye ulaşmadan bir sonraki bağlantıya iletilemez.
- **Uçtan uca gecikme:** Yayılım gecikmesi sıfır kabul edilirse bir paketin kaynaktan hedefe gitmesi $L/R$ (kaynaktan yönlendiriciye) $+ L/R$ (yönlendiriciden hedefe) $= 2L/R$ saniyedir.

### 3.1 Tek atlamalı sayısal örnek

"Tek atlama" yolda yalnız bir yönlendirici bulunduğu anlamına gelir (ekrandan, 00:15:00).

- Verilen: $L = 10$ Kbit, $R = 100$ Mbps.
- İşlem: $d_{trans} = L/R = \dfrac{10\times10^3}{100\times10^6}$ s.
- Sonuç: $d_{trans} = 10^{-4}$ s $= 0{,}1$ ms $= 100\ \mu s$.

> **Ders sonrası not:** Hoca anlatırken bir an "$L$ saniyede 10 kilobit, $R$ paketin boyutu" dedi, sonra düzeltti. Doğrusu slayttaki gibidir: $L = 10$ Kbit paket uzunluğu, $R = 100$ Mbps bağlantı hızıdır.

## 4. Kuyruklanma ve Paket Kaybı

Önceki örnekte yalnız bir kaynak, bir yönlendirici ve bir hedef vardı. Şimdi A ve B konakları aynı yönlendiriciye bağlı olsun (ekrandan, 00:20:00). A sağ taraftaki C'ye, B ise E'ye mesaj göndermek istiyor. Konaklardan yönlendiriciye bağlantılar $R = 100$ Mb/s, yönlendiriciler arasındaki bağlantı ise $R = 1{,}5$ Mb/s'tir.

Paketler yönlendiriciye, yönlendiriciden çıkabildiklerinden daha hızlı gelir. Bu yüzden yönlendirici onları bir kuyruğa koyar ve sırayla sonraki yönlendiriciye iletir. Önceki örnekte yalnız iletim gecikmesi vardı; burada buna kuyruk gecikmesi de eklenir, çünkü her paket çıkış bağlantısına verilene kadar kuyrukta beklemek zorundadır.

Slaytın ana cümlesi şudur: Kuyruklanma, iş hizmet verilebildiğinden hızlı geldiğinde oluşur. Hoca gerçek hayattan üç örnek verdi: çok sayıda aracın sınırlı sayıda gişeye yığıldığı otoyol gişeleri (İstanbul'daki Mahmutbey gişeleri), tek kapıdan aynı anda tek kişinin girebildiği bir bina ve İngiltere'deki otobüs durağı kuyruğu.

Yönlendirici kuyruğu tutmak için bir tampon (bellek) kullanır. Belirli bir süre boyunca bağlantıya gelen hız (bit/s), bağlantının iletim hızını ($R$) aşarsa paketler çıkış bağlantısında iletilmeyi beklerken kuyruklanır. Kuyrukta yer kalmadığında, yani tampon dolduğunda, gelen paketler düşürülür ya da kaybolur. Böylece üç terim ortaya çıkar: kuyruklanma, iletim süresi ve kayıp.

## 5. Devre Anahtarlama, FDM ve TDM

Paket anahtarlamada paket gelir, kuyruğa konur ve sırasını bekler. Bunun alternatifi devre anahtarlamadır. Devre anahtarlamada kaynak ile hedef arasında baştan uca bir devre kurulur ve kaynaklar o çağrı (call) için ayrılır, yani rezerve edilir. Hocanın gösterdiği şekilde her bağlantıda dört devre vardır; çağrı, üst bağlantıdaki ikinci devreyi ve sağ bağlantıdaki birinci devreyi kullanır.

Ayrılmış bağlantılar paylaşılmaz. Bu sayede kaynak ve hedef ayrılan kapasitenin tamamını garantili kullanır. Ancak bu yaklaşım verimli değildir: Kaynak ile hedef arasında gönderilecek mesaj olmadığında ayrılan kapasitenin tamamı boşa gider, devre boşta (idle) kalır. Devre anahtarlama geleneksel olarak genel anahtarlamalı telefon ağlarında (PSTN) kullanılır; telefonla birini aradığınızda iki telefon arasında ayrılmış bir devre kurulur.

Bağlantının tüm kapasitesi bir devreye ayrıldığına göre, bir fiziksel bağlantı birden çok çağrı arasında nasıl paylaştırılır? Bunun için iki teknoloji vardır (ekrandan, 00:25:00).

### 5.1 Frekans bölmeli çoğullama (FDM)

Optik ya da elektromanyetik frekans aralığı dar frekans bantlarına bölünür. Örnekte mavi, yeşil, sarı ve pembe ile gösterilen dört çağrı vardır. Her çağrıya kendi bandı ayrılır ve çağrı en fazla o dar bandın hızıyla iletim yapabilir. Fiziksel bağlantının kapasitesi dar bantlara bölünür ve her dar bant bir çağrıya adanır; her kullanıcı kendi dar bandını her zaman kullanabilir.

### 5.2 Zaman bölmeli çoğullama (TDM)

Aynı grafikte yine dört kullanıcı vardır, ama bu kez paylaştırılan değişken zamandır. Zaman dilimlere (slot) bölünür ve her çağrıya periyodik dilimler ayrılır. Çağrı kendi diliminde dar bandın değil, fiziksel bağlantının bütün (daha geniş frekans bandına karşılık gelen) hızının en yüksek değeriyle iletebilir; ama yalnız sınırlı bir süre için.

Özetle FDM'de her kullanıcı her zaman bandın bir parçasını, TDM'de ise zamanın bir parçasında bandın tamamını kullanır. İkisi de devre anahtarlamalı ağda bağlantıyı paylaştırmak için kullanılır.

## 6. Paket Anahtarlama mı, Devre Anahtarlama mı?

Slaytın başlığı "paket anahtarlama ağı daha çok kullanıcının kullanmasına izin verir" iddiasıdır (ekrandan, 00:30:00). Örnek şöyledir:

- Çıkış bağlantısı: 1 Gb/s.
- Her kullanıcı aktifken 100 Mb/s kullanır.
- Her kullanıcı zamanın %10'unda aktiftir.

Devre anahtarlamada her kullanıcıya sürekli 100 Mb/s ayrılması gerekir. Bu yüzden en fazla $1\text{ Gb/s} / 100\text{ Mb/s} = 10$ kullanıcı desteklenir.

Paket anahtarlamada ağda 35 kullanıcı olsun. Her kullanıcı zamanın yalnız %10'unda aktif olduğundan, aynı anda 10'dan fazla kullanıcının aktif olma olasılığı yaklaşık 0,0004'tür. Bu olasılık çok düşüktür; yani neredeyse her zaman her kullanıcı ağa 100 Mb/s'ye kadar erişebilir. Aynı bağlantı devre anahtarlamada 10, paket anahtarlamada 35 kullanıcıya hizmet verir; bu yüzden paket anahtarlama üstündür.

> **Ders sonrası not:** Hoca anlatırken bir an "45 kullanıcı" dedi; slayttaki değer 35'tir. Ayrıca slayt "less than .0004" der; ama $X \sim B(35;\,0{,}1)$ için $P(X > 10) \approx 0{,}00042$ çıkar (python ile hesaplandı). Doğru ifade "yaklaşık 0,0004"tür.

> **Ek bilgi (derste anlatılmadı):** Bu olasılık binom dağılımıyla hesaplanır: 35 kullanıcının her biri bağımsız olarak $p = 0{,}1$ olasılıkla aktiftir. Aynı anda $k$ kullanıcının aktif olma olasılığı $\binom{35}{k}(0{,}1)^k(0{,}9)^{35-k}$'dir ve $k = 11, \dots, 35$ için bu değerler toplanır.

### 6.1 Patlamalı veri ve paket anahtarlamanın bedeli

Paket anahtarlama patlamalı (bursty) veri için çok uygundur. Patlamalı veride paketler sınırlı bir süre içinde gelir, kalan süre boştur; kaynağın bazen gönderecek verisi olur, bazen hiçbir şey göndermez. Paket anahtarlama bu durumda kaynak paylaşımına izin verir ve basittir. Basittir, çünkü yönlendirici paketi alır, kuyruğa koyar ve iletir; çağrı kurulumu yoktur. Devre anahtarlamada ise mesaj alışverişinden önce bağlantı kurulmalıdır.

Bunun bedeli aşırı tıkanıklık olasılığıdır. Tampon sınırlı olduğundan paket gecikmesi ve tampon taşmasından kaynaklanan kayıp ortaya çıkabilir. Bu yüzden güvenilir veri aktarımı için protokollere ve tıkanıklık denetimine ihtiyaç vardır.

Buradan bir soru doğar: Paket anahtarlamalı ağda devre benzeri davranış nasıl sağlanır? Bir tür sanal devre oluşturularak, paket anahtarlama kullanılsa da bant genişliği garantisi verilebilir. Bu tür garantiler geleneksel olarak belirli bir bant genişliğine ihtiyaç duyan ses ve video uygulamaları için kullanılır.

## 7. İnternetin Yapısı: Ağların Ağı

İnternet bir ağlar ağıdır. Konaklar internete erişim ISP'leri (internet servis sağlayıcıları) üzerinden bağlanır. Erişim; evden (residential), kurumsal (üniversite, şirket) ya da ticari ISP üzerinden olabilir. Erişim ISP'lerinin de, herhangi iki konak birbirine paket gönderebilsin diye, birbirine bağlanması gerekir.

Slayttaki soru şudur: Milyonlarca erişim ISP'si varken bunlar birbirine nasıl bağlanır (ekrandan, 00:35:00)?

- **Doğrudan bağlantı:** En basit yaklaşım her ISP'yi her ISP'ye bir ağ gibi bağlamaktır. Ama bu ölçeklenmez, çünkü $N^2$ mertebesinde bağlantı gerektirir.
- **Global ISP:** Her erişim ISP'si bir global ISP'ye bağlanır. Global ISP ortada bir bulut, yani bir ağ oluşturur.
- **Birden çok global ISP:** Global ISP olmak değerli bir iştir, bu yüzden rakipler çıkar (ISP A, ISP B, ISP C). Rakip global ISP'ler de birbirine bağlanmalıdır. Bunun iki yolu vardır: internet değişim noktaları (IXP) ya da iki global ISP'nin yönlendiricileri arasında doğrudan eşleme (peering) bağlantısı.
- **Bölgesel ISP'ler:** Erişim ağlarına hizmet veren ve global ISP'lere bağlanan ara katmandır.
- **İçerik sağlayıcı ağları:** Google, Microsoft, Akamai gibi şirketler bu bulutun üzerinde kendi ağlarını çalıştırır. Örneğin Netflix içeriğe erişimin hızlı olması için içeriği son kullanıcıya olabildiğince yakın tutar.

> **Ders sonrası not:** Hoca IXP'yi bir yerde "internet access point" diye açtı; doğrusu "Internet Exchange Point"tir. Altyazıda "Kamayi" diye geçen şirket büyük olasılıkla Akamai'dir.

Sonuç olarak en altta yerel erişim ISP'leri, üstünde bölgesel ISP'ler ve değişim noktaları, merkezde ise az sayıda iyi bağlanmış büyük ağ, yani Tier 1 ISP'ler bulunur. Tier 1 ticari ISP'lere Level 3, Sprint ve AT&T örnek verildi; bunlar ulusal ve uluslararası kapsama sahiptir. Google ve Facebook gibi içerik sağlayıcılar kendi veri merkezlerini internete bağlayan ağlar kurar ve çoğu zaman Tier 1 ve bölgesel ISP'leri atlar.

Hoca son olarak 2019 tarihli bir Tier 1 ISP ağ haritası gösterdi. Haritada omurga düğümleri, Ethernet POP'ları, deniz kablosu iniş istasyonları ve POP (point of presence) noktaları vardır. POP'larda eşleme ağlarına ve müşteri ağlarına bağlanan çok sayıda yönlendirici bulunur; bütün yapı bir tür ağ örgüsüdür.

## 8. Performans: Gecikmenin Dört Kaynağı

Yol haritasındaki sonraki başlık performanstır: kayıp, gecikme ve verim (ekrandan, 00:40:00).

Paket anahtarlamalı ağda paketler yönlendirici tamponunda iletim sırası için bekler. Bağlantıya geliş hızı çıkış bağlantısının kapasitesini aştığında kuyruk uzar. Kuyruk dolarsa gelen paketi koyacak yer kalmaz ve paket kaybı olur. Kuyruğun başındaki paket iletilirken iletim gecikmesi, kuyrukta bekleyen paketler için kuyruk gecikmesi oluşur.

Bir düğümdeki toplam gecikme dört bileşenin toplamıdır (ekrandan, 00:45:00):

$$d_{nodal} = d_{proc} + d_{queue} + d_{trans} + d_{prop}$$

- **$d_{proc}$, düğüm işleme gecikmesi:** Yönlendirici gelen her paketi işler: bit hatası olup olmadığını denetler ve iletme tablosuna göre çıkış bağlantısını belirler. Yönlendiricinin kapasitesine göre genelde milisaniyeden azdır.
- **$d_{queue}$, kuyruk gecikmesi:** Çıkış bağlantısında iletim için bekleme süresidir; yönlendiricinin tıkanıklık düzeyine bağlıdır.
- **$d_{trans}$, iletim gecikmesi:** $L$ paket uzunluğu (bit), $R$ bağlantı iletim hızı (bps) olmak üzere $d_{trans} = L/R$'dir. Paketin tamamını bağlantıya basma süresidir.
- **$d_{prop}$, yayılım gecikmesi:** $d$ fiziksel bağlantının uzunluğu, $s$ yayılım hızı olmak üzere $d_{prop} = d/s$'dir. Boşlukta $s$ ışık hızına eşittir; fiziksel ortamlarda yaklaşık $2\times10^8$ m/s'dir.

Hoca yayılım gecikmesi için bir örnek başlattı: Cat 6 UTP kablo kullanılıyor, $d = 100$ m ve $s = 2\times10^8$ m/s. Buradan $d_{prop} = d/s = 100 / (2\times10^8) = 5\times10^{-7}$ s $= 0{,}5\ \mu s$ bulunur (ara adım eklendi).

> **Hocanın vurgusu:** İletim gecikmesi ile yayılım gecikmesi tamamen farklıdır. İletim gecikmesi mesajı çıkış bağlantısına basma süresidir ve bağlantının kapasitesine bağlıdır. Yayılım gecikmesi sinyalin hattın bir ucundan öbür ucuna gitme süresidir.

## 9. Kervan Benzetmesi

Aradan sonra hoca bu iki gecikmeyi bir benzetmeyle somutlaştırdı (ekrandan, 01:00:00). 10 araçlık bir kervan 10 bitlik bir pakete, gişe ise yönlendiriciye karşılık gelir. Hoca örneği Marmara otoyolu üzerinden anlattı.

- Araçlar 100 km/sa hızla "yayılır".
- Gişe bir araca 12 saniyede hizmet verir (bit iletim süresi). Bu, bilet almaya ya da otoyol ücretini ödemeye karşılık gelir.
- Araç ~ bit, kervan ~ paket.
- İki gişe arası 100 km'dir.
- Soru: Kervanın ikinci gişenin önünde dizilmesi ne kadar sürer?

Çözüm:

- Kervanın tamamını gişeden otoyola itme süresi (iletim): $12 \times 10 = 120$ s $= 2$ dakika.
- Son aracın birinci gişeden ikinci gişeye yayılma süresi: $100\text{ km} / (100\text{ km/sa}) = 1$ saat.
- Toplam: $60 + 2 = 62$ dakika.

### 9.1 Kervan benzetmesinin ikinci hali

Şimdi araçlar 1000 km/sa hızla yayılsın ve gişe bir araca 1 dakikada hizmet versin. Araçlar, birinci gişede bütün araçlara hizmet verilmeden ikinci gişeye varır mı?

Cevap evet. İlk araç birinci gişeden 1 dakikada çıkar ve 100 km'yi $100/1000$ saat $= 6$ dakikada gider; böylece 7. dakikada ikinci gişeye ulaşır (ara adım eklendi). Bu sırada birinci gişeden 7 araç geçmiştir, 3 araç hâlâ hizmet beklemektedir. Paket açısından bu, paketin ilk bitlerinin, son bitleri daha birinci yönlendiriciden çıkmadan ikinci yönlendiriciye ulaşabileceği anlamına gelir.

## 10. Kuyruk Gecikmesi ve Trafik Yoğunluğu

$R$ bağlantı hızı (bps), $L$ paket uzunluğu (bit), $a$ ortalama paket geliş hızı olsun. Hoca, $La/R$ oranına göre üç durumu ayırdı:

- $La/R \approx 0$: Ortalama kuyruk gecikmesi çok küçüktür; kuyrukta neredeyse kimse yoktur.
- $La/R \to 1$: Ortalama kuyruk gecikmesi giderek büyür.
- $La/R > 1$: Gelen iş, hizmet verilebilecek olandan fazladır. Ortalama gecikme sonsuza gider; kuyrukta yer kalmadığı için paketler düşürülür.

Hoca bunu yine trafikle anlattı: Şirinevler'de E-5'te makul sayıda araç vardır, ama E-5'e girmek için bekleyen çok sayıda araç birikir. Oran sıfıra yakınken yol boştur; oran 1'e yaklaştığında ya da aştığında trafik sıkışır.

> **Ders sonrası not:** Hoca anlatırken birkaç kez "$L/R$" dedi; kastedilen oran trafik yoğunluğu $La/R$'dir.

> **Ek bilgi (derste anlatılmadı):** $La/R$ oranına trafik yoğunluğu (traffic intensity) denir. Pay, saniyede bağlantıya gelen ortalama bit sayısı ($La$), payda bağlantının saniyede iletebildiği bit sayısıdır ($R$). Bu yüzden oran 1'i geçtiğinde kuyruk sınırsız büyür.

## 11. Gerçek İnternet Gecikmeleri: Traceroute

Gerçek internette gecikme ve kayıp neye benzer? Bunu ölçmek için `traceroute` programı kullanılır (ekrandan, 01:05:00). Program, kaynaktan hedefe giden uçtan uca yol boyunca her yönlendiriciye kadar olan gecikmeyi ölçer. Her $i$ için:

- Hedefe giden yoldaki $i$. yönlendiriciye ulaşacak üç paket (sonda) gönderilir; bu paketlerin yaşam süresi (time-to-live) alanı $i$'dir.
- $i$. yönlendirici paketleri göndericiye geri döndürür.
- Gönderici, gönderme ile yanıt arasındaki süreyi ölçer.

Önce birinci yönlendiriciye, sonra ikinciye, sonra üçüncüye üçer paket gönderilerek bu işlem yol boyunca tekrarlanır.

Hoca bir örnek çıktı gösterdi. İlk satırlar kaynağın kendi kurumundaki ağ geçitleridir ve üç ölçüm de yaklaşık 1 ms'dir. Satırlar ilerledikçe hedefe doğru ilerlenir. 17. ve 18. satırlarda görülen yıldız (`*`) işaretleri yanıt gelmediğini ya da paketin kaybolduğunu gösterir.

<!-- BELİRSİZ: Örnek traceroute çıktısındaki kaynak/hedef sunucu adları ve ilk satırdaki IP adresi altyazıda bozuk; o anın karesi yok, değerler nota alınmadı. -->

> **Ek bilgi (derste anlatılmadı):** Yaşam süresi (TTL) alanı her yönlendiricide bir azaltılır. Değer sıfıra inince yönlendirici paketi atar ve göndericiye bir hata mesajı döner. Traceroute bu davranışı kullanarak TTL değeri $i$ olan paketle tam olarak $i$. yönlendiriciden yanıt alır.

## 12. Paket Kaybı ve Verim (Throughput)

### 12.1 Paket kaybı

Kuyruğa tampon da denir. Bağlantının önündeki tamponun kapasitesi sonludur. Çıkış bağlantısının kapasitesi gelen bağlantınınkinden düşük olduğu için paketler tamponda bekler. Dolu bir kuyruğa gelen paket düşürülür, yani kaybolur. Kaybolan paket, protokole göre önceki düğüm tarafından, kaynak uç sistem tarafından yeniden gönderilebilir ya da hiç yeniden gönderilmeyebilir.

### 12.2 Verim

Verim (throughput), bitlerin göndericiden alıcıya gönderildiği hızdır; birimi bit/s'dir. İki tür verimden söz edilir:

- **Anlık verim:** Belirli bir andaki hız.
- **Ortalama verim:** Uzun bir süre boyunca hız.

Örnekte solda $F$ bitlik dosyası olan bir sunucu, sağda bir istemci vardır. Sunucudan yönlendiriciye bağlantının hızı $R_s$, yönlendiriciden istemciye bağlantının hızı $R_c$ bit/s'dir (ekrandan, 01:10:00). Hoca bunu su borusu benzetmesiyle anlattı: bağlantılar farklı kalınlıkta borulardır, dosya da borulardan akan sudur.

- $R_s < R_c$ ise: Sunucu tarafındaki boru incedir; ortalama uçtan uca verim $R_s$'tir.
- $R_s > R_c$ ise: İstemci tarafındaki boru incedir; ortalama uçtan uca verim $R_c$'dir.

Uçtan uca verimi kısıtlayan bağlantıya **darboğaz bağlantısı** (bottleneck link) denir. Kısacası uçtan uca verim $\min(R_s, R_c)$'dir.

### 12.3 Paylaşımlı bağlantı senaryosu

İkinci senaryoda üstte her biri $R_s$ hızlı bağlantıya sahip 10 sunucu, altta her biri $R_c$ hızlı bağlantıya sahip 10 istemci vardır ve 10 bağlantı ortadaki $R$ hızlı bağlantıyı paylaşır. Bağlantı başına uçtan uca verim:

$$\min(R_c,\ R_s,\ R/10)$$

Pratikte darboğaz çoğunlukla $R_c$ ya da $R_s$'tir, çünkü $R/10$ genellikle daha büyüktür. Yani paylaşımlı yolda verim, yoldaki en düşük kapasiteli bağlantının hızıdır.

## 13. Protokol Katmanları ve Kapsülleme

İnternet, ağlardan oluşan karmaşık bir yapıdır ve en iyi çaba (best effort) ilkesiyle çalışan paket anahtarlamalı bir ağdır. Bir hizmet sunmak için protokoller gerekir ve yapı karmaşık olduğundan bunları katmanlar hâlinde düzenlemek daha iyidir. Ağda çok sayıda parça vardır: konaklar, yönlendiriciler, Wi-Fi, Ethernet, fiber optik, koaksiyel kablo gibi farklı ortamlardaki bağlantılar; e-posta, web tarayıcısı, ERP gibi uygulamalar; birçok protokol; farklı üreticilerin donanımları ve yazılımları. Soru şudur: Ağın yapısını, ya da en azından ağ hakkındaki tartışmamızı düzenlemenin bir yolu var mı?

### 13.1 Havayolu yolculuğu benzetmesi

Hoca katmanlamayı havayolu yolculuğuyla anlattı (ekrandan, 01:15:00). Kişinin ve bagajının uçtan uca taşınması bir dizi adımdan oluşur:

| Kalkış tarafı | Varış tarafı |
|---|---|
| bilet (satın alma) | bilet (şikâyet) |
| bagaj (teslim) | bagaj (alım) |
| kapı (biniş) | kapı (iniş) |
| pist (kalkış) | pist (iniş) |
| uçak yönlendirme | uçak yönlendirme |

Önce para ödeyip bilet alırsınız, bagajınızı havalimanına götürüp teslim eder, kapıya gidip uçağa binersiniz; uçak piste gider ve kalkar. Örneğin İstanbul'dan Kayseri'ye belirli bir yol izlenir ve bunun için bir yönlendirme mekanizması gerekir. Kayseri'ye inince uçak pistten kapıya yönlendirilir, uçaktan inersiniz, bagajınızı alırsınız; her şey yolundaysa şirkete teşekkür eder, sorun varsa şikâyet edersiniz.

Burada bilet hizmeti, bagaj hizmeti, kapı hizmeti, pist hizmeti ve yönlendirme hizmeti katmanlardır. Her katman kendi iç işlemleriyle bir hizmet verir ve bunu yaparken alttaki katmanın hizmetine dayanır; yapı bir çağlayan gibidir.

### 13.2 Neden katmanlama?

İnternet karmaşık bir sistemdir ve karmaşık sistemlerle başa çıkmanın basit yolu katmanlamadır.

- Açık bir yapı, karmaşık sistemin parçalarının ve aralarındaki ilişkilerin tanımlanmasını sağlar; bu bir katmanlı başvuru modelidir.
- Modülerlik bakımı ve güncellemeyi kolaylaştırır, çünkü katmanlar birbirinden bağımsızdır. Bir katmanın hizmetinin gerçekleştirilme biçimi değişse de sistemin geri kalanı etkilenmez.

### 13.3 İnternet protokol yığını

TCP/IP modelinde beş katman vardır:

- **Uygulama:** Ağ uygulamalarını destekler; HTTP, IMAP, SMTP, DNS.
- **Taşıma:** Süreçten sürece veri aktarımı. Uygulamanın ürettiği mesaj taşıma katmanına gelir ve burada paketlere dönüştürülür; TCP ve UDP bu katmandadır.
- **Ağ:** Datagramların kaynaktan hedefe yönlendirilmesi; IP ve yönlendirme protokolleri.
- **Bağlantı (link):** Komşu ağ elemanları arasında veri aktarımı; kaynaktan ilk atlamaya, oradan sonraki atlamaya. Ethernet, Wi-Fi, PPP.
- **Fiziksel:** Kablodaki bitler; elektrik sinyali ya da elektromanyetik dalga.

### 13.4 Kapsülleme

Kaynaktan hedefe giden yolu adım adım izleyelim (ekrandan, 01:20:00):

1. Uygulama katmanı bir mesaj $M$ üretir ve taşıma katmanının hizmetini kullanarak bir uygulama hizmeti gerçekleştirir.
2. Taşıma katmanı protokolü $M$'yi bir süreçten öbürüne (örneğin güvenilir biçimde) ağ katmanının hizmetini kullanarak aktarır. Bunun için $M$'ye taşıma katmanı başlığı $H_t$ eklenir; $H_t + M$ birimine **segment** denir. $H_t$, taşıma katmanı protokolünün kendi hizmetini gerçekleştirmesi için kullanılır.
3. Ağ katmanı protokolü segmenti bir konaktan öbürüne bağlantı katmanının hizmetini kullanarak aktarır. Segmente ağ katmanı başlığı $H_n$ eklenir; $H_n + H_t + M$ birimine **datagram** denir.
4. Bağlantı katmanı protokolü datagramı bir konaktan komşu konağa aktarır. Datagrama bağlantı katmanı başlığı $H_l$ eklenir; $H_l + H_n + H_t + M$ birimine **çerçeve** (frame) denir.
5. Fiziksel katman çerçeveyi bit olarak iletir.

Hoca kapsüllemeyi Matruşka bebeklerine benzetti: Mesaj en içteki küçük bebektir. Aşağı inildikçe her katman onu bir büyük bebeğin içine koyar: mesaj, segment, datagram, çerçeve. Hedefte bebekler sırayla açılır ve uygulama en içteki küçük kırmızı bebeği, yani mesajı alır. Daha büyük örnekte paket yol üzerindeki anahtarda ve yönlendiricide de ilgili katmana kadar açılır, işlenir (hata denetimi, kuyruk vb.), yeniden kapsüllenir ve hedefe ulaşır.

> **Hocanın vurgusu:** Uygulama katmanında veri birimine mesaj, taşıma katmanında segment, ağ katmanında datagram, bağlantı katmanında çerçeve denir.

## 14. Ağ Güvenliği

Hoca, ilk iki haftanın tanıtım haftaları olduğunu ve her konuya kısaca değineceğini hatırlatarak güvenliğe geçti (ekrandan, 01:25:00). İnternet başlangıçta pek güvenlik düşünülerek tasarlanmadı; ilk vizyon "şeffaf bir ağa bağlı, birbirine güvenen kullanıcılar grubu" idi. İnternet bugün herkese açık bir alan olduğundan, protokol tasarımcıları geride kalanı yakalamaya çalışıyor ve var olan protokollere güvenlik mekanizmaları ekliyor. Güvenlik bütün katmanlarda düşünülmelidir. Ağ güvenliği alanı şu soruları inceler: kötü niyetli kişiler ağlara nasıl saldırır, ağlar saldırılara karşı nasıl savunulur ve saldırılara bağışık mimariler nasıl tasarlanır.

### 14.1 Saldırı türleri

- **Paket koklama (packet sniffing):** Ethernet ya da kablosuz gibi yayın (paylaşımlı) ortamlarda gönderilen paketi herkes görebilir, ama normalde yalnız alıcı alır. Ancak bir ağ arayüzü geçen bütün paketleri, aktarım şifresizse parolalar dahil, kaydedebilir. Örnekte A, B'ye mesaj gönderirken saldırgan C, ortam paylaşımlı olduğu için paketleri toplayıp içeriğini görebilir.
- **Sahte kimlik (IP spoofing):** Sahte kaynak adresiyle paket gönderilir. C, A'ya bir paketi B'den geliyormuş gibi gönderebilir.
- **Hizmet engelleme (DoS):** Saldırganlar hedefi sahte trafikle boğarak sunucu, bant genişliği gibi kaynakları meşru trafik için kullanılamaz hâle getirir. Çok sayıda bot, hedefin bağlantı kapasitesini doldurmak için paket gönderir.
- **Kötücül yazılım (malware):** Virüs, solucan ya da casus yazılım yoluyla konağa bulaşır. Bulaşan konaklar bir botnet'in parçası olarak kullanılabilir.

<!-- BELİRSİZ: 01:28:56-01:29:15 arasında altyazı anlamsız Türkçe tekrarlara dönüşmüş; bu aralıkta kötücül yazılım ve savunmaya giriş anlatılmış olabilir. -->

### 14.2 Savunma hatları

Slayttaki savunma hatları şunlardır (ekrandan, 01:30:00):

- **Kimlik doğrulama:** Kişinin söylediği kişi olduğunu kanıtlaması. Hücresel ağlar SIM kart ile donanımsal kimlik sağlar; geleneksel internette böyle bir donanım desteği yoktur.
- **Gizlilik:** Şifreleme ile sağlanır.
- **Bütünlük denetimi:** Dijital imzalar kurcalamayı önler ya da tespit eder.
- **Erişim kısıtlama:** Parola korumalı VPN'ler; hoca parola ve PIN numaralarının erişimi kısıtlamak için kullanılabileceğini söyledi.
- **Güvenlik duvarları:** Erişim ve çekirdek ağlarda özel "ara kutular" (middlebox). Varsayılan olarak kapalıdır, gelen paketleri göndereni, alıcıyı ve uygulamayı kısıtlamak için süzer; DoS saldırılarını tespit eder ve tepki verir.

Hoca bunlara ek olarak sandbox ve honeypot gibi yapılardan, saldırıyı tespit eden ve önleyen IDS/IPS sistemlerinden de söz etti. Konunun ayrıntısı dördüncü sınıf güz döneminde işlenecektir.

## 15. İnternetin Tarihi

Haftanın son konusu internetin tarihidir.

- **İlk paket anahtarlama ilkeleri:** Kleinrock'un kuyruk teorisiyle paket anahtarlamanın etkinliğini göstermesi; askerî ağlarda paket anahtarlama çalışmaları. 1967'de ARPANET'in İleri Araştırma Projeleri Ajansı (ARPA) tarafından tasarlanması, 1969'da ilk ARPANET düğümünün çalışmaya başlaması. 1972'de ARPANET'in halka açık gösterimi, ilk konaktan konağa protokol olan NCP (Network Control Protocol) ve 15 ARPANET düğümü arasında ilk e-posta programı.
- **1970'ler, ağ bağlama:** Hawaii'de ALOHAnet uydu ağı; Cerf ve Kahn'ın ağları birbirine bağlama mimarisi. Bu mimari bugünkü internet mimarisinin temelidir ve ilkeleri şunlardır: minimalizm ve özerklik (ağları birbirine bağlamak için iç değişiklik gerekmez), en iyi çaba hizmet modeli, durumsuz yönlendirme ve merkeziyetsiz denetim. Bu ilkeler bugün de ağ mimarisini tanımlar.
- **1980'ler, yeni protokoller:** TCP/IP'nin ilk yaygın kullanımı, SMTP e-posta protokolü ve DNS'in tanımlanması; 1985'te FTP, 1988'de TCP tıkanıklık denetimi. ABD'de 100.000 konak bir ağlar konfederasyonuna bağlıdır.
- **1990-2000, ticarileşme ve web:** 1990'ların başında ARPANET (1991) ve ardından NSFNET hizmetten kaldırılır. Web: hipermetin, HTML ve HTTP; 1994'te Mosaic, sonra Netscape tarayıcıları. 1990'ların sonunda web'in ticarileşmesi, P2P dosya paylaşımı, ağ güvenliği; 100 milyondan fazla kullanıcı ve gigabit hızında çalışan omurga.
- **2005-günümüz, ölçek, SDN, mobilite, bulut** (ekrandan, 01:35:00): geniş bant ev erişiminin hızla yaygınlaşması (slaytta 10-100 Mbps; hoca bugün evde 1 Gbps'e kadar erişim olabileceğini ekledi), 2008'de yazılım tanımlı ağlar (SDN), 4G/5G ve Wi-Fi gibi yüksek hızlı kablosuz erişimin her yerde bulunması. Google, Facebook ve Microsoft gibi büyük sağlayıcılar, ticari interneti atlayıp son kullanıcıya yakın kendi ağlarını kurar ve sosyal medya, arama ve video içeriğine anında erişim sağlar. Kurumlar hizmetlerini Amazon ve Microsoft Azure gibi bulutlarda çalıştırır. Akıllı telefonlarla internete bağlı mobil cihazlar sabit cihazları geçmiştir (2017) ve hocaya göre 2023'te internete bağlı cihaz sayısı 15 milyarı aşmıştır.

> **Ders sonrası not:** Hoca Kleinrock'un çalışmasını "1991" diye söyledi; bu çalışma büyük olasılıkla 1961 tarihlidir (aynı maddede sonra gelen 1967 ve 1969 tarihleri de bunu gösterir). TCP/IP'nin ilk yaygın kullanımı için söylenen 1982 büyük olasılıkla 1983'tür. Altyazıda 100.000 konağın bağlanması 1990'lara yerleştirilmiş görünse de bu büyük olasılıkla 1980'lerin sonudur. Hoca 1990'ların sonu için "50 milyar konak" dedi; doğrusu büyük olasılıkla yaklaşık 50 milyon konaktır.

> **Ek bilgi (derste anlatılmadı):** Altyazıda "FNET" diye geçen ağ büyük olasılıkla NSFNET'tir; ABD Ulusal Bilim Vakfı'nın akademik omurga ağıdır ve 1990'ların ortasında yerini ticari omurgalara bırakmıştır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Yerel iletme tablosu `0100 → 3`, `0101 → 2`, `0111 → 2`, `1001 → 1` olan bir yönlendiriciye giriş portu 3'ten başlığında `0111` bulunan bir paket gelir. Paket hangi çıkış bağlantısına iletilir?

> **Çözüm (derste verildi):** Tabloda `0111` satırının çıkış değeri 2'dir; paket çıkış bağlantısı 2'ye iletilir. Giriş portunun hangisi olduğu kararı etkilemez, karar hedef adrese göre verilir.

**Soru 2** (ekrandan, 00:15:00): Paket uzunluğu $L = 10$ Kbit, bağlantı hızı $R = 100$ Mbps ise tek atlamalı iletim gecikmesi nedir? Yayılım gecikmesi sıfırken kaynak, bir yönlendirici ve hedeften oluşan yolda uçtan uca gecikme nedir?

> **Çözüm:** $d_{trans} = L/R = 10^4 / 10^8 = 10^{-4}$ s $= 0{,}1$ ms (derste verildi). Uçtan uca gecikme $2L/R = 0{,}2$ ms olur (ara adım eklendi; python ile doğrulandı).

**Soru 3** (ekrandan, 00:30:00): 1 Gb/s bağlantıyı, aktifken 100 Mb/s kullanan ve zamanın %10'unda aktif olan kullanıcılar paylaşıyor. Devre anahtarlama kaç kullanıcıyı destekler? Paket anahtarlamada 35 kullanıcı varken aynı anda 10'dan fazla kullanıcının aktif olma olasılığı nedir?

> **Çözüm:** Devre anahtarlama $1000/100 = 10$ kullanıcıyı destekler (derste verildi). Paket anahtarlamada olasılık derste yaklaşık 0,0004 olarak verildi. Python ile $X \sim B(35;\,0{,}1)$ için $P(X > 10) = \sum_{k=11}^{35}\binom{35}{k}(0{,}1)^k(0{,}9)^{35-k} \approx 0{,}00042$ bulundu.

**Soru 4** (ekrandan, 01:00:00): 10 araçlık kervan, araç başına 12 s hizmet veren bir gişeden geçiyor; gişeler arası 100 km, araç hızı 100 km/sa. Kervanın ikinci gişenin önünde dizilmesi ne kadar sürer?

> **Çözüm (derste verildi):** İletim: $12 \times 10 = 120$ s $= 2$ dk. Yayılım: $100/100 = 1$ sa $= 60$ dk. Toplam: $62$ dakika.

**Soru 5** (derste sözlü, 01:00:31): Aynı düzende araçlar 1000 km/sa hızla gidiyor ve gişe araç başına 1 dakika harcıyor. Birinci gişede bütün araçlara hizmet verilmeden araçlar ikinci gişeye ulaşır mı?

> **Çözüm (derste verildi):** Evet. İlk araç 1 dakikada gişeden çıkar ve 100 km'yi $100/1000$ sa $= 6$ dakikada alır; 7. dakikada ikinci gişeye varır. O anda birinci gişede hâlâ 3 araç vardır.

**Soru 6** (ekrandan, 01:10:00): Sunucu bağlantısı $R_s$, istemci bağlantısı $R_c$ olsun. $R_s < R_c$ ve $R_s > R_c$ durumlarında ortalama uçtan uca verim nedir? 10 bağlantı ortak bir $R$ bağlantısını paylaşırsa bağlantı başına verim nedir?

> **Çözüm (derste verildi):** $R_s < R_c$ ise verim $R_s$, $R_s > R_c$ ise $R_c$; genel olarak $\min(R_s, R_c)$, yani darboğaz bağlantının hızı. Paylaşımlı durumda bağlantı başına verim $\min(R_c, R_s, R/10)$'dur.

## Dersin Toparlaması

Bu derste giriş bölümü tamamlandı. Önce ağ çekirdeği ele alındı: Çekirdek yönlendiricilerden oluşur, yönlendirme algoritmaları kaynaktan hedefe yolu belirler, her yönlendirici de yerel iletme tablosuyla paketleri çıkışlara aktarır. Paket anahtarlamanın depola ve ilet yapısı, iletim gecikmesi $L/R$, kuyruklanma ve tampon taşmasından kaynaklanan kayıp anlatıldı. Alternatif olarak devre anahtarlama ile FDM ve TDM tanıtıldı; paket anahtarlamanın aynı bağlantıda daha çok kullanıcıya hizmet verdiği, patlamalı trafik için uygun olduğu, ama tıkanıklık denetimi ve güvenilir aktarım protokolleri gerektirdiği gösterildi. İnternetin erişim, bölgesel ve Tier 1 ISP'lerden, IXP'lerden ve içerik sağlayıcı ağlardan oluşan "ağların ağı" yapısı açıklandı.

İkinci yarıda performans ölçütleri işlendi: düğüm gecikmesinin işleme, kuyruk, iletim ve yayılım bileşenleri, kervan benzetmesi, trafik yoğunluğu $La/R$, traceroute ile gerçek gecikme ölçümü ve darboğaz bağlantının belirlediği verim. Ardından beş katmanlı internet protokol yığını ve mesaj, segment, datagram, çerçeve biçiminde ilerleyen kapsülleme anlatıldı. Ders, ağ güvenliğindeki temel saldırı ve savunmalar ile internetin ARPANET'ten bugünkü SDN, bulut ve mobil internete uzanan tarihinin özetiyle kapandı. Hoca, bu konuların her birinin sonraki haftalarda ayrıntılı işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
