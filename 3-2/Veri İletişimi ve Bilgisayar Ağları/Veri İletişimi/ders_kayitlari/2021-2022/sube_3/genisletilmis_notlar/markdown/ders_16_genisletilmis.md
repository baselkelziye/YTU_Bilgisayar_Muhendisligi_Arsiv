# Ders 16 Genişletilmiş Notu: IEEE 802.11 Kablosuz Yerel Ağlar, Bluetooth ve LAN Teknolojilerinin Karşılaştırması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kablolu Ağlardan Kablosuz Ağlara
- 2. Kablosuz İletişimin Özellikleri
- 3. Çarpışmadan Kaçınma (CSMA/CA) ve 802.11 MAC
- 4. DCF: Bekleme Süreleri, Geri Çekilme ve Çekişme
- 5. Üç İstasyonlu DCF Örneği
- 6. RTS/CTS ve NAV
- 7. Gizli Düğüm ve Açıkta Kalan Düğüm
- 8. Temel ve Genişletilmiş Hizmet Alanları
- 9. Kanal Kullanımı: 2,4 GHz Kanalları, FHSS ve DSSS
- 10. 802.11 Sürümleri ve Menzil
- 11. Kablosuz Teknolojilerin Hız ve Menzil Karşılaştırması
- 12. Bluetooth, ZigBee, HomeRF ve HiperLAN
- 13. Kablosuz Ağlarda Tehditler ve Güvenlik
- 14. LAN Teknolojilerinin Karşılaştırması

## 1. Kablolu Ağlardan Kablosuz Ağlara

Hoca derse, geçen haftalarda IEEE 802.3, 802.4 ve 802.5 standartlarını anlattıklarını hatırlatarak başladı. Bu derste IEEE 802 projesinin 11 numaralı standardına, yani hepimizin her gün kullandığı Wi-Fi'a geçildi. 802.11'in "a"dan başlayıp "z"ye kadar giden, hatta iki harfli adları olan pek çok sürümü vardır. Hoca bunlara kabaca değineceğini söyledi. Bağlantılı ve bağlantısız hizmetler (connectionless ve connection-oriented services) ile anahtarlama (switching) konusu ise gelecek haftaya kaldı.

Şimdiye kadar işlerin kablolu yapıda nasıl yürüdüğü görülmüştü. Bu derste kablosuz iletişimde neyin değiştiği ele alındı.

## 2. Kablosuz İletişimin Özellikleri

### 2.1 Radyo Frekansı ve Kızılötesi

Kablosuz iletişimde yayın yine bir frekans bandı üzerinden yapılır. Her frekansın bir dalga boyu vardır. 802.11'in radyo frekansı (Radio Frequency, RF) üzerinden çalışan sürümleri vardır.

Hocanın günlük örneği evdeki modemdi. Modem, adı belli bir ağ yayar. Bu adın teknik karşılığı SSID'dir. Ona bağlanan herkes bir yerel ağ (LAN) oluşturur. İnternet bağlantımız olmasa bile, o modeme bağlı cihazlar kendi aralarında veri paylaşabilir.

802.11'in bir de kızılötesi (infrared) ile çalışan sürümleri vardır. Kızılötesi bir ışıktır. Bu teknolojide göndericinin ve alıcının birbirini doğrudan görmesi gerekir. RF'de ise buna gerek yoktur. Alıcı bir duvarın arkasında olabilir. Ama her dalga boyu her duvardan geçmez. Duvarın malzemesi de önemlidir: Kurşundan yapılmış bir duvardan sinyal geçmez. Tuğla ya da betondan örülmüş evlerimizde ise modem başka bir odadayken bile bağlantı kurabiliriz.

Kızılötesi için hocanın örneği eski televizyon kumandalarıydı. Kumandayı tam televizyona doğru tutmadan kanal değiştiremiyorduk.

### 2.2 Hareketlilik ve Dolaşım

Kablosuz iletişimin en önemli avantajlarından biri hareketliliktir (mobility). Kablolu yapıda dizüstü bilgisayarınıza kablo bağlar, belki evin içinde 10 metrelik bir kabloyla dolaşırsınız. Ama bu çok verimli olmaz. Hoca, dersi o anda Wi-Fi üzerinden anlattığını, bilgisayarına bir LAN kablosu bağlı olmadığını, isterse bilgisayarı kucağına alıp her yerden ders anlatabileceğini söyledi.

Hareketlilikle birlikte dolaşım (roaming) kavramı önem kazanır. Hoca önce cep telefonu hatlarından örnek verdi. Telefonun üst köşesinde normalde LTE, H, H+, 4G ya da 4.5G gibi ifadeler görünür. Yurt dışına gidince orada "R" yazmaya başlar. Bu, dolaşımda olduğunuz anlamına gelir. Kendi operatörünüz dışında başka bir operatörden hizmet alırsınız ve operatörler arasındaki anlaşmalar çerçevesinde ücretlendirilirsiniz. Yani kendi operatörünüzün ağından çıkıp başka bir ağ üzerinden iletişim kurarsınız.

Wi-Fi'daki karşılığı için hoca Davutpaşa kampüsünün kablosuz ağını örnek verdi. Kampüsteki ağ iyileştirildiğinde, fakültedeyken belli bir erişim noktasına bağlanırsınız. Başka bir sınıfa geçince size daha yakın olan erişim noktasına, yemekhaneye gidince yine aynı ağın başka bir erişim noktasına bağlanırsınız. Ağ değişmez, siz o ağın içinde dolaşırsınız.

### 2.3 Menzil

Kablosuz ağda görüş hattında olmasanız da iletişim kurabilirsiniz. Ama menzil çok kısıtlıdır. GSM, LTE ya da 2G'de kilometrelerce mesafeye veri iletilebilirken Wi-Fi'da durum farklıdır:

- **Açık alan:** en fazla yaklaşık 100 metre.
- **Kapalı alan:** en iyimser durumda 30 metreye kadar çıkabilir. Genellikle 15-20 metre civarında kalır.

### 2.4 Sinyal Zayıflaması

Hoca, Wi-Fi'ı yayan antenden uzaklaştıkça sinyalin mesafenin karesiyle zayıfladığını söyledi ve bunun çok önemli bir bilgi olduğunu vurguladı. Ne kadar yakınsanız sinyaliniz o kadar güçlü, performansınız o kadar yüksek olur.

$$P_{alınan} \propto \frac{1}{d^2}$$

> **Ders sonrası not:** Hoca "bir metre uzaklaştığınızda dört kat, iki metre uzaklaştığınızda on altı kat zayıflar" dedi. Ters kare yasası mesafenin oranıyla çalışır, eklenen metreyle değil. Mesafe 2 katına çıkınca alınan güç $1/2^2 = 1/4$'üne, 4 katına çıkınca $1/4^2 = 1/16$'sına düşer.

### 2.5 Gürültü

Kablolu tarafta fiziksel katmanda gördüğümüz gürültüleri hoca hatırlattı: Kablodaki elektronların hareketinden doğan ısıl gürültü (thermal noise) ya da kablonun üzerinden bir araba geçmesi gibi dış etkiler. Kablosuz ağda ise asıl gürültü, kanalların birbirinin üzerine binmesidir. Siz 2,4 GHz bandının belli bir kanalından yayın yaparken aynı kanalda çok daha güçlü yayın yapan başka ağlar varsa, bu size gürültü olarak döner.

Yaşadığınız çevrede çok fazla Wi-Fi ağı yoksa rahat bağlanırsınız. Ama bir fuara ya da bir yarışma alanına gittiğinizde ortamda çok sayıda Wi-Fi ağı olur ve gürültü kaçınılmaz hâle gelir. Gürültü, verinin karşıya doğru ulaşmasını zorlaştırır. Veriyi tekrar tekrar göndermek gerekir ve bu da gönderim hızını ciddi biçimde düşürür.

## 3. Çarpışmadan Kaçınma (CSMA/CA) ve 802.11 MAC

Ethernet'i anlatırken taşıyıcı dinlemeli çoklu erişimin çarpışma algılamalı sürümünü (Carrier Sense Multiple Access with Collision Detection, CSMA/CD) görmüştük. Çarpışmaları algılayıp temizleyerek hat kullanım oranını (line utilization) artırıyordu. 802.11'de ise çarpışmadan kaçınma (Collision Avoidance, CA) tekniği kullanılır. Amaç, çarpışmayı en aza indirmektir.

Kablosuz ağda çarpışmayı algılamak zordur. Çünkü antenler yarı çift yönlü (half duplex) çalışır: Ya veri gönderir ya da alır. Gönderirken aynı anda dinleyemez. Hoca bunun yanında, kaçınma teknikleri sayesinde çarpışmanın çok az olduğunu, olduğunda da çoğunlukla küçük boyutlu çerçeveler üzerinde gerçekleştiğini söyledi. Özetle çarpışmadan kaçınmak mümkündür, ama çarpışmayı algılamakla ilgili çeşitli sorunlar vardır.

> **Ders sonrası not:** Hoca CSMA/CA'yı CSMA/CD'nin "gelişmiş bir versiyonu" olarak tanıttı. İkisi aynı ailedendir, ama CA büyük olasılıkla bir iyileştirmeden çok, çarpışmanın algılanamadığı kablosuz ortama yapılmış bir uyarlamadır. Kablolu Ethernet'te CD daha verimlidir.

IEEE 802.11'in ortam erişim denetimi (Media Access Control, MAC) kısmında iki temel yaklaşım vardır:

- **Dağıtık Koordinasyon İşlevi (Distributed Coordination Function, DCF):** Derste ayrıntılı anlatılan yöntem.
- **Nokta Koordinasyon İşlevi (Point Coordination Function, PCF):** Yoklamanın (polling) yapıldığı yöntem.

> **Ek bilgi (derste anlatılmadı):** PCF'de erişim noktası bir koordinatör gibi davranır ve istasyonları sırayla yoklar. Yoklanan istasyon çekişmeye girmeden gönderir. Bu yüzden PCF dönemi çekişmesiz (contention-free) dönem olarak adlandırılır. Uygulamada büyük olasılıkla çok az cihaz PCF'yi desteklemiştir.

## 4. DCF: Bekleme Süreleri, Geri Çekilme ve Çekişme

### 4.1 Temel Akış

DCF, Ethernet'teki mantığı temel alır. Ethernet'te önce hattın boş olup olmadığı kontrol ediliyor, hattın boş ya da meşgul olmasına göre farklı aksiyonlar alınıyordu. Burada da öyledir:

- **Hat boşsa:** İstasyon DCF çerçeveler arası boşluğu (DCF Interframe Space, DIFS) kadar bekler. Sonra iletim moduna geçip gönderir.
- **Hat meşgulse:** İstasyon kendi iletimini, o anda süren iletim bitene kadar erteler. Buna geri çekilme (backoff) denir. "Göndereceğim ama şu an hat müsait değil" diye olaya yaklaşılır.

### 4.2 W Değeri ve Geri Sayım

Bekleme süresi bir W değeri üzerinden belirlenir. Hoca W'nin 4'ten başladığını anlattı: $2^4 = 16$. İstasyon bu aralıktan seçilen bir değerden geriye doğru sayar, sanki bir kronometre gibi. Sayılan birimlere zaman dilimi (time slot) denir. Hoca bu birimin mikrosaniye ya da nanosaniye düzeyinde olabileceğini söyledi. Sayaç sıfıra indiğinde istasyon iletime geçer.

Her zaman diliminde yapılan işlem şudur:

- Sayaç henüz sıfır değilse, o zaman diliminde bir azaltılır (örneğin 14'ten 13'e).
- Sayaç sıfırsa, veri hatta basılır.

İletime geçildiğinde çarpışma olabilir. Çarpışmaya karışan istasyonların W değeri 4'ten 5'e çıkarılır: Artık $2^5 = 32$'lik bir aralıktan seçim yapılır. Yeniden çarpışırsa 6'ya, 7'ye çıkar. Yani bekleme aralığı her çarpışmada büyür.

> **Ders sonrası not:** Hoca bazı yerlerde geri sayılan değeri "DIFS süresi" diye andı ("DIFS süremizi bir azaltıyoruz"). DIFS sabit bir bekleme süresidir. Geri sayılan şey ayrı bir geri çekilme sayacıdır (backoff counter). Ayrıca W değerinden çekişme penceresi (Contention Window) $CW = 2^W - 1$ olarak çıkar ve sayaç $[0, CW]$ aralığından seçilir. Hoca W = 4 için "0 ile 16 arası" dedi; doğrusu 0–15'tir. W = 5 için $CW = 31$, W = 6 için $CW = 63$ olur. Slayttaki 31 ve 63 değerleri bununla uyumludur.

### 4.3 SIFS, ACK ve EIFS

Gönderici bir çerçeve gönderdikten sonra alıcıdan bir onay (ACK) bekler. Alıcı çerçeveyi alır, hata ve bütünlük (integrity) kontrollerinden geçirir, sonra "aldım" ya da "alamadım" bilgisini taşıyan ACK'yi gönderir. Alıcı ACK'yi göndermeden önce kısa çerçeveler arası boşluk (Short Interframe Space, SIFS) kadar bekler.

> **Hocanın vurgusu:** SIFS süresi DIFS süresinden kısadır. Bu yüzden ACK, yeni bir veri gönderimine göre önceliklidir: Hat bir veri çerçevesinden sonra boşaldığında, ACK bekleyen alıcı herkesten önce söz alır.

Çarpışma olduğu durumda çerçeveler genişletilmiş çerçeveler arası boşluk (Extended Interframe Space, EIFS) kadar bekler. Hoca bunu, çarpışmaya karışanları W değerini yükselterek "cezalandırmak" olarak anlattı.

### 4.4 Zaman Çizelgesi ve Çekişme

Hoca bir gönderici ve bir alıcı için akışı slayttaki grafik üzerinden anlattı:

1. Gönderici göndermeye karar verir, hattı dinler.
2. Hat müsaitse DIFS kadar bekler ve veri çerçevesini yollar.
3. Alıcı çerçeveyi neredeyse aynı zaman diliminde, çok az bir gecikmeyle alır.
4. Alma işlemi bittikten sonra SIFS kadar bekler ve ACK'yi yollar.
5. ACK bittikten sonra hat yeniden müsaittir. Herkes yine belli bir süre bekler ve çekişme (contention) başlar.

Çekişme, "ben göndereceğim, hayır ben göndereceğim" şeklinde bir rekabettir. Göndermek isteyen her istasyonun geri çekilme penceresi (backoff window) çalışmaya başlar. Her biri seçtiği değerden geriye doğru sayar. En önce sıfıra ulaşan çekişmeyi kazanır ve bir sonraki zaman diliminde veri gönderme hakkını elde eder.

## 5. Üç İstasyonlu DCF Örneği

Hoca slayttaki üç istasyonlu (Station 1, 2, 3) şemayı adım adım anlattı. Bu bölümdeki her sayı slayttan okundu. Hesaplar python ile kontrol edildi.

**Verilen:** İlk turda W = 5, yani $CW = 2^5 - 1 = 31$. Geri çekilme değeri (BO) $[0, 31]$ aralığından seçilir.

**Adım 1: Station 3 doğrudan gönderir.** MAC katmanına ilk çerçeve Station 3'te gelir. O anda göndermek isteyen başka istasyon olmadığı için çekişme yoktur. BO = 0 olur. Station 3, DIFS bekleyip çerçevesini gönderir ve hattı meşgul eder.

**Adım 2: Diğerleri bekler.** Station 3 göndermesini bitirmeden önce Station 1 ve Station 2'nin MAC katmanına da gönderilecek çerçeve gelir. Hat meşgul olduğu için beklerler. Şemada zaman soldan sağa artar.

**Adım 3: Birinci çekişme.** Station 3'ün iletimi biter. Bütün cihazlar sabit bir süre olan DIFS kadar bekler. Ardından çekişme başlar. Seçilen değerler:

- Station 1: 10
- Station 2: 19
- Station 3 (yeni çerçevesi için): 25

**Adım 4: Station 1 kazanır.** Herkes aynı hızda geri sayar. 10 zaman dilimi sonra Station 1 sıfıra ulaşır ve gönderir. Diğerlerinin sayaçları donar:

- Station 2: $19 - 10 = 9$
- Station 3: $25 - 10 = 15$

**Adım 5: Çarpışma.** Station 1'in iletimi biter. Herkes yine DIFS bekler ve donmuş sayaçlarından devam eder. Station 1 yeni çerçevesi için 9 seçmiştir. Station 2 de 9'dan devam etmektedir. 9 zaman dilimi sonra ikisi aynı anda sıfıra ulaşır. Sıfıra ulaştıktan sonra ufak bir kontrol yaparlar, ama ikisi bu kontrolü aynı anda yaptığı için hattı boş görürler ve ikisi birden gönderir. Çarpışma olur. Station 3'ün sayacı bu sırada $15 - 9 = 6$'ya iner.

Hoca çarpışmayı en kötü durum (worst case) olarak niteledi: Karşı taraf, çarpışma yüzünden kendisine veri gönderilmek istendiğini bile bilmiyor olabilir. Bu tekniğin amacı çarpışmadan kaçınmaktır. Ama çarpışma olursa, ona karışan makineler "cezalandırılır".

**Adım 6: Ceza.** Çarpışan istasyonların W değeri 5'ten 6'ya çıkar: $CW = 2^6 - 1 = 63$. Yeni değerler:

- Station 1: 52
- Station 2: 43

**Adım 7: Station 3 kazanır.** Station 3 kaldığı yerden, 6'dan sayar. 6 zaman dilimi sonra sıfıra ulaşır ve hattı kullanır. Diğerlerinin sayaçları donar:

- Station 1: $52 - 6 = 46$
- Station 2: $43 - 6 = 37$

**Adım 8: Sonraki tur.** Station 3 çarpışmaya karışmadığı için hâlâ $CW = 31$ ile çalışır. Yeni çerçevesi için 0–31 arasından bir değer seçer. Diğer iki istasyonun en küçük sayacı 37'dir. Station 3'ün seçebileceği en büyük değer 31 olduğuna göre, Station 3 yine göndermek isterse sıradaki turu da o kazanır.

Hocanın vardığı sonuç: Çarpışmaya sebep olan istasyonlar, Station 3 art arda iki kez gönderirken hiç gönderim yapamaz. Ceza onların bir süre daha beklemesini sağlar.

> **Ders sonrası not:** Hoca çarpışmadan sonraki donmuş değerleri "37 ve 45" dedi; doğrusu $52 - 6 = 46$ ve $43 - 6 = 37$'dir. Son adımda da "en küçüğü 36'dan başlayacağına göre" dedi; en küçük sayaç 37'dir. Sonuç değişmez: 37 > 31 olduğu için Station 3 her durumda önce sıfıra ulaşır.

## 6. RTS/CTS ve NAV

DCF'nin yanında iki temel kavram daha vardır: gönderme isteği (Request to Send, RTS) ve göndermeye izin (Clear to Send, CTS). Hoca, RTS çerçevesinin 5 alandan, CTS çerçevesinin 4 alandan oluştuğunu söyledi.

İşleyiş şöyledir. A cihazı, aynı ağdaki B'ye veri göndermek istiyor:

1. A, B'ye bir RTS çerçevesi gönderir. Bu çerçevede ne göndereceği ve ne kadar süre göndereceği bilgisi vardır.
2. B, RTS'i alır ve değerlendirir. Kabul edebilir ya da meşgulse reddedebilir. Durumunu bir CTS çerçevesiyle bildirir.
3. CTS çerçevesinde özel bir alan vardır. B bu alanla herkese şunu duyurur: "A bana şu kadar süre boyunca veri gönderecek, haberiniz olsun."
4. Bu duyuruyu alan diğer istasyonlar süreyi ağ ayırma vektörlerine (Network Allocation Vector, NAV) kaydeder.
5. Bu süre boyunca diğer istasyonların hattın meşgul olup olmadığını kontrol etmesine bile gerek yoktur. Süre bitince, gönderecek ya da alacakları bir şey varsa hattı yeniden dinlerler.

> **Ek bilgi (derste anlatılmadı):** NAV'a kaydedilen süreye dayanarak susmaya "sanal taşıyıcı algılama" (virtual carrier sensing) denir. İstasyon hattı fiziksel olarak dinlemese de, NAV sıfırlanana kadar hattı meşgul sayar. RTS ve CTS kısa çerçeveler olduğu için, bir çarpışma olursa uzun bir veri çerçevesi yerine yalnızca bu kısa çerçeveler kaybedilir.

## 7. Gizli Düğüm ve Açıkta Kalan Düğüm

Hoca RTS/CTS bağlamında iki temel sorun anlattı. Bunların ilkinde bir çarpışma vardır, ikincisinde ise gönderimi gereksiz yere engelleyen bir durum.

### 7.1 Gizli Düğüm (Hidden Node)

A, B ve C istasyonları olsun. Kapsama alanları şöyledir:

- A'nın kapsama alanında yalnızca B var.
- B'nin kapsama alanında hem A hem C var.
- C'nin kapsama alanında yalnızca B var.

Hoca önce şunu hatırlattı: Kablosuz bir ağda cihazlar hareketlidir ve gönderici, alıcının tam nerede olduğunu bilerek göndermez. Bir çember içinde sürekli yayılan bir ağ vardır. İçine bir sinyal gönderdiğinizde, ağa bağlı 30 cihaz varsa hepsi bir gönderim olduğunu duyar. Verinin içeriğini bilmemeleri gerekir, bu yüzden A ile B arasındaki iletişim uçtan uca şifrelenmelidir. Ama başlıklara bakarak bir mesaj gönderildiğini fark edebilirler.

Senaryo: B, A'ya mesaj göndermek istiyor. B'den A'ya RTS gider. A müsait olduğu için CTS gönderir. Ama A'nın kapsamında yalnızca B vardır. A'nın yayınladığını C duyamaz. A'nın CTS'indeki "şu kadar süre boyunca hat meşgul olacak" bilgisi C'ye ulaşmaz. C de B'ye mesaj göndermek isterse hemen gönderir. İkisi aynı ağdadır ve B'nin çevresinde çarpışma olur.

Hocanın özeti: Ağın içinde, iletişim kurduğunuz cihaz dışındaki diğer cihazları göremiyorsanız bu bir sorundur. Burada C, A için gizli düğümdür.

### 7.2 Açıkta Kalan Düğüm (Exposed Node)

Bu kez dört istasyon var. Kapsama alanları:

- A'nın kapsamında yalnızca B var.
- B'nin kapsamında A ve C var.
- C'nin kapsamında B ve D var.
- D'nin kapsamında yalnızca C var.

A, B'ye; C de D'ye mesaj göndermek istiyor. A, RTS'ini yollar ve B alır. A'dan birkaç milisaniye sonra C de D'ye göndermek ister, ama henüz RTS göndermemiştir.

A'dan B'ye giden mesajları C ve D duymaz. Yani A–B iletişimi, C–D iletişimini engellemez, çarpışmaya da sebep olmaz. Fakat B, A'nın RTS'ini aldıktan sonra yayın yapar: "A bana mesaj gönderecek, şu kadar süreyle NAV'ınızı ayarlayın." C, B'nin kapsama alanında olduğu için bu duyuruyu alır ve kilitlenir. Ağa bir mesaj gelecek, sorun çıkarmayayım diye isteğini geri çeker ve boşuna bekler. Oysa D'ye mesaj gönderebilirdi. Buna açıkta kalan düğüm sorunu denir.

### 7.3 Ara Sonrası Soru

**Soru:** Gizli düğüm, A'nın C'yi görememesi değil mi?
**Cevap:** Evet. A'nın C'yi, doğal olarak C'nin de A'yı görememesidir. Bu yüzden "gizli" denir. Ağda öyle bir cihazın olup olmadığından habersizdir.

## 8. Temel ve Genişletilmiş Hizmet Alanları

Bir Wi-Fi ağı düşünelim: Evimizde 10 ya da daha fazla, belki daha az cihaz bağlı. Buna temel hizmet alanı (Basic Service Area) denir. Örneğin üç düğüm vardır ve yalnızca birbirleriyle konuşurlar.

Başka temel hizmet alanlarıyla konuşmak için genişletilmiş hizmet alanları (Extended Service Area) kullanılır. Kapsama alanları birbiriyle kesişmeyen ayrı ayrı hizmet alanları olsun. Bu alanların içinde yönlendirici (router) diye adlandırabileceğimiz makineler üzerinden atlamalarla (hop) iletişim kurulur. Hocanın slayttaki örneğinde bir makine mesajını bir sonrakine, o da bir sonrakine verir. Mesaj 1, 2, 3 atlamada hedefe ulaşır. Aradaki bir makinenin kendi anteni olsaydı, mesajı doğrudan uç terminale iletebilirdi. Temel hizmet alanlarının bu şekilde genişletilmiş hâline genişletilmiş hizmet alanı denir.

<!-- BELİRSİZ: Slayttaki BSS/ESS şemasında hangi makinelerin erişim noktası olduğu ve atlama sırası altyazıda yalnızca "şu, şuna" diye işaret edilerek anlatılıyor. -->

## 9. Kanal Kullanımı: 2,4 GHz Kanalları, FHSS ve DSSS

### 9.1 2,4 GHz Bandının Kanalları

Modemlerimiz bugün 2,4 GHz ya da 5 GHz bandında yayın yapabilir. 2,4 GHz'te çalışırken belli frekans aralıkları kanallara ayrılır. Kanallar 5 MHz arayla dizilir.

Hoca bunu FM radyoya benzetti. 90.5'i dinlerken bir sonraki istasyon 90.51 ya da 90.52 olmaz. Kanallar birbirine karışmasın diye aralarında belli bir frekans boşluğu bırakılır. Wi-Fi'da da 5 MHz'lik boşluklarla kanallar oluşturulur. Hoca kanal sayısını "ortalama 13 ile 15 arası" olarak verdi.

Slayttaki tabloya göre:

- Kanal 1'in merkez frekansı 2,412 GHz'tir.
- Kanal merkezleri 5'er MHz arayla artar.
- Son kanal (13) 2,472 GHz'tir.

Kontrol: $2{,}412 + 12 \times 0{,}005 = 2{,}472$ GHz. Yani 13 kanal vardır.

Kanallar bandın tam başından başlamaz, çünkü her kanalın genişliği 22 MHz'i bulur. Merkez frekans, bu genişliğin yarısı kadar (11 MHz) bandın başından içeride olmalıdır. Böylece kanal 2,4 GHz'in başından başlamış olur.

> **Ders sonrası not:** Bandın başlangıcı 2,400 GHz alınırsa kanal 1'in alt kenarı $2{,}412 - 0{,}011 = 2{,}401$ GHz olur. Türkiye ve Avrupa'da büyük olasılıkla 13 kanal kullanılabilir. 14. kanal büyük olasılıkla yalnızca Japonya'da ve yalnızca 802.11b için tanımlıdır.

### 9.2 Örtüşen ve Örtüşmeyen Kanallar

Kanallar 5 MHz arayla dizildiği hâlde her biri 22 MHz genişliğinde olduğu için komşu kanallar örtüşür. Hoca slayttaki çizim üzerinden şunu gösterdi: Kanal 1'in etkisi kanal 2, 3 ve 4'e kadar gelir. Hatta kanal 5 ile bile kesiştiği noktalar vardır. Daha az oranda kesişirler ama kesişme ihtimali vardır.

Bu, merkezler arası farkla kontrol edilebilir (ara adım eklendi). İki kanalın örtüşmemesi için merkezleri arasındaki fark en az kanal genişliği kadar, yani 22 MHz olmalıdır:

| Kanal çifti | Merkezler arası fark | 22 MHz ile karşılaştırma |
|---|---|---|
| 1 – 2 | 5 MHz | örtüşür |
| 1 – 3 | 10 MHz | örtüşür |
| 1 – 4 | 15 MHz | örtüşür |
| 1 – 5 | 20 MHz | az da olsa örtüşür |
| 1 – 6 | 25 MHz | örtüşmez |

Bu yüzden birbirini etkilemeyen üç kanal kullanılacaksa, slaytta koyu ile işaretlenmiş 1, 6 ve 11 numaralı kanallar seçilir. Üç ayrı kanal varsa ve birinde çarpışma oluyorsa, diğerinden gönderebilirsiniz. Ama örneğin kanal 1'de çarpışma varken kanal 2'den gönderirseniz, iki kanal büyük ölçüde kesiştiği için çarpışma temizlenmeden aynı bölgeye yayın yapmış olursunuz.

### 9.3 FHSS ve DSSS

Hoca kanalları kullanmanın iki temel yolunu anlattı. Modemlerde kanal otomatik olarak ya da elle seçilebilir.

**Frekans atlamalı yayılı spektrum (Frequency Hopping Spread Spectrum, FHSS):** Hocanın anlatımında, örneğin kanal 1'den veri gönderdiniz ve yolda bir sorun oldu, çarpışma yaşandı ya da karşı taraf "hatalı aldım" mesajı gönderdi. Veriyi yeniden göndermeniz gerekir. Bunu kanal 2'den ya da kanal 3'ten yapabilirsiniz. Ama kanallar örtüştüğü için örtüşmeyen kanalları kullanmak daha verimlidir.

**Doğrudan dizili yayılı spektrum (Direct Sequence Spread Spectrum, DSSS):** Hocanın anlatımında, gönderdiğiniz veri aynı anda birçok kanalın içinde bulunur. Hoca bunu paralel gönderim olarak düşünmememizi söyledi: Paralel gönderim için birçok farklı antenin olması gerekirdi. Alıcı, hangi kanaldan daha yüksek sinyal alıyorsa veriyi o kanaldan alır.

> **Ders sonrası not:** İki tekniğin tanımı derste sadeleştirildi. FHSS'te gönderici, yalnızca hata olduğunda değil, sürekli olarak alıcıyla ortak bir sözde rastgele (pseudo-random) sıraya göre kanaldan kanala atlar. DSSS'te ise her bit, daha hızlı bir yayma koduyla (chipping code) çarpılarak tek ve geniş bir banda yayılır. Alıcı aynı kodla sinyali geri toplar. Bu yüzden DSSS büyük olasılıkla dar bantlı gürültüye karşı dayanıklıdır.

### 9.4 Soru: Neden Bu Aralık?

**Soru:** Kanal kullanımını neden bu aralıkta tutuyorlar? Daha geniş yapamazlar mı?
**Cevap:** Yapamıyorlar. 2,4 GHz'in ve 5 GHz'in çevresi belli bir noktaya kadar yasal olarak ücretsiz kullanıma açılmıştır. Spektrumun çok büyük bir kısmı devletlerin, özellikle askerî kullanımına ayrılmıştır ve oraya müdahale edemezsiniz. Bir kısmı ise ticaridir: Radyo kanallarında olduğu gibi, o frekans bandını kullanmak için satın almanız gerekir.

Öğrenci "yani fiziksel değil, yasal bir zorunluluk" diye toparladı, hoca da onayladı. Düzenlemeler değişebilir. Hoca, 5 GHz tarafının da tahminen önceden askerî kullanımda olup sonradan eklendiğini, zamanla yeni bantların da eklenebileceğini söyledi. Önemli olan, bunların otoritelerce halkın ücretsiz kullanımına izin verilen bantlar olmasıdır. Devlet "benim havamda kafana göre yayın yapamazsın, ancak söylediğim aralıkta yapabilirsin" der. Bu yalnızca Türkiye'ye özgü değildir, bütün devletler böyle yaklaşır. Polis telsizleri, askerî haberleşme sistemleri gibi kullanımlar bu kontrolün nedenidir.

## 10. 802.11 Sürümleri ve Menzil

IEEE 802.11'in slaytta gösterilenlerden başka da pek çok sürümü vardır. Bir kısmı hem 2,4 GHz'i hem 5 GHz'i destekler. Biri yalnızca 5 GHz'i, farklı bant genişliği ve hızlarla destekler. Sürümler modülasyonları ve örtüşmeyen kanal sayıları bakımından da ayrılır.

Hocanın örneği çok kullandığımız 802.11n'di. Slaytta 802.11n için "örtüşmeyen 3 veya 11 kanal" yazar. Bunun nedeni 802.11n'in hem 2,4 GHz'te hem 5 GHz'te yayın yapmasıdır: 2,4 GHz'te örtüşmeyen 3 kanal, 5 GHz'te örtüşmeyen 11 kanal vardır.

<!-- BELİRSİZ: Slayttaki 802.11 sürümleri tablosunun (a, b, g, n vb.) hız, bant ve modülasyon sütunları altyazıda okunmuyor; yalnızca 802.11n satırı sözlü olarak anıldı. -->

Erişim mesafeleri:

- **Dış ortam:** Bir Wi-Fi ağının, 802.11n ve türevleri sayılmazsa, ortalama 100 metreye kadar erişimi vardır. Hoca 100 metreyi bölüm binasıyla somutlaştırdı: Laboratuvar katında fotokopi merkezinden diğer uçtaki mescide kadar olan mesafe 40 metredir. 100 metre bunun $100 / 40 = 2{,}5$ katıdır.
- **İç ortam:** Ortamın özelliklerine göre değişmekle birlikte en fazla 20 metre civarındadır. Evin duvarları uygunsa evin içinde 20 metre rahatça kullanılabilir.

Farklı dalga boyları farklı yapılardan ve malzemelerden geçemeyebilir. Bazı modemler hem 2,4 GHz'te hem 5 GHz'te yayın yapar ve iki ayrı ağ kurulabilir:

- **5 GHz:** Daha hızlı veri aktarımı sağlar. Ama dalga boyu kısaldığı için daha kısa mesafeye gönderim yapılır.
- **2,4 GHz:** Daha uzun mesafeye gönderim yapılır.

Hocanın örneği: Modemin olduğu odada 5 GHz'e bağlanıp çok hızlı veri indirirsiniz. Modeme uzak bir odada 5 GHz çekmiyorsa 2,4 GHz çekecektir, çünkü dalga boyu daha uzaklara erişmeye imkân tanır.

## 11. Kablosuz Teknolojilerin Hız ve Menzil Karşılaştırması

Hoca, slayttaki grafik üzerinden farklı kablosuz haberleşme tekniklerini hem veri hızı (bit/s) hem ulaşabildikleri mesafe bakımından karşılaştırdı.

### 11.1 Hücresel Nesiller

- **2G:** Eski tuşlu telefonlar internete bağlanmıyordu, bunlar 2G'ydi. Grafikte 2G yaklaşık 10.000 feet, yani yaklaşık 3 kilometre ve biraz fazlasında gösteriliyor. Hoca 5 kilometreye kadar, bazı durumlarda daha fazla çekim sağlayabildiğini söyledi. Ama veri aktarımı çok düşüktür. Ancak ses ve kısa mesaj gönderilebilir. Video izlemek, görüntülü görüşme yapmak, fotoğraf göndermek bu hızlarda mümkün değildir.
- **3G:** Telefonlar artık internete bağlanabiliyordu. Telefonda H ve H+ yazanlar 3G'dir. Veri hızı çok yükseldi. Dalga boyu küçüldüğü için gönderilebilecek en büyük mesafe azaldı ve baz istasyonu sayısı arttı. Belki 10 kilometreden bağlanırken artık 5-6 kilometreden bağlanmak gerekti.
- **4G ve 4.5G:** Türkiye 4G'yi atlayıp doğrudan 4.5G'ye geçti. Veri hızları daha da arttı. Grafikte yok, ama hücreleri daha da küçüktür. Baz istasyonuna daha yakın olmak gerekir.
- **5G:** Bazı ülkeler kullanmaya başladı. Mikrodalgaya geçiliyor. Daha yüksek hız ve belki daha kesintisiz iletişim sağlanacak, ama baz istasyonlarının bize daha da yakın olması gerekecek.
- **6G:** Hoca, 6G'de her cihazın aynı zamanda bir baz istasyonu olmasının beklendiğini söyledi. Telefonumuz üzerinden başkaları haberleşme kurabilecek. Dalga boyu çok küçüleceği ve her dairenin içine baz istasyonu kurulamayacağı için böyle bir mantık üzerinde çalışılıyor. Hoca, en fazla 10 yıl içinde 6G kullanıyor olacağımızı tahmin etti. Bu hocanın öngörüsüdür.

Kontrol: $10.000 \text{ ft} \times 0{,}3048 = 3048$ m, yani yaklaşık 3 km.

### 11.2 Wi-Fi, HomeRF ve Bluetooth

Aynı grafikte 802.11 iç ve dış ortam için, HomeRF ve Bluetooth da gösteriliyor. Bluetooth'un menzili çok kısadır. Açık alanda belki 100 metreye çıkabilir, ama veri aktarımı için kullanıldığında menzili Wi-Fi'dan da kısadır.

802.11 projesinin hızı ve performansı artan sürümlerinde mesafe daha da daralır. Hocanın genel kuralı:

> **Hocanın vurgusu:** Hızı artırmak için frekansı yükseltmek, yani dalga boyunu küçültmek gerekir. Dalga boyu küçülünce gönderilebilecek mesafe azalır. Frekans arttıkça hız artar, menzil kısalır.

### 11.3 Hayata Geçmeyen Geniş Alan Kablosuz Ağı

Hoca daha önce bahsettiği, çok uzak menzillerde çok yüksek hızda veri gönderen bir sistemi hatırlattı. Prototipler üretilmiş, standart geliştirilmiş, ama yaygın kullanıma girmemiştir. Yerini 4G, 5G ve 6G almıştır. Hayal şuydu: Davutpaşa kampüsünün orta bahçesine devasa bir direk ve anten dikiliyor. Bu anten Wi-Fi yayıyor ve 10, 50, belki 100 kilometre çaptaki herkes ona bağlanıyor. Maliyeti ve ticari uygulanabilirliği (feasibility) yüzünden yaygınlaşmadı.

> **Ders sonrası not:** Hocanın anlattığı uzak mesafeli kablosuz şehir ağı (WMAN) fikri büyük olasılıkla IEEE 802.16 (WiMAX) olarak standartlaştı ve bir dönem bazı ülkelerde ticari olarak kullanıldı. Bugün yerini büyük ölçüde 4G/LTE almıştır.

## 12. Bluetooth, ZigBee, HomeRF ve HiperLAN

### 12.1 Bluetooth'un Yaygınlaşması

Hoca, slayt hazırlandığında Bluetooth'un 3. sürümünün olduğunu, bugün 5'in çeşitli alt sürümlerinin (5.2, 5.3 gibi) bulunduğunu söyledi. Bluetooth sürekli geliştiriliyor, belki Wi-Fi standartlarından bile hızlı. Çünkü artık belki Wi-Fi'dan daha çok Bluetooth kullanıyoruz.

Hocanın kendi kullanımından örnekler:

- Telefon, saatle Bluetooth üzerinden çalışıyor.
- Arabaya binince telefon arabanın Bluetooth'una bağlanıyor.
- Evdeki akıllı ampul ve akıllı elektronik cihazlar Bluetooth ile bağlanıyor.
- Telefon ekranını televizyona yansıtırken (mirroring) görüntü Wi-Fi üzerinden gidiyor, ama eşzamanlama (senkronizasyon) Bluetooth üzerinden yapılıyor.
- Kablosuz kulaklıkla müzik dinleniyor.

Bluetooth bu kadar çok cihazda kullanılınca enerji tüketimi önem kazandı. Telefonda küçük bir Bluetooth işlemi, örneğin MP3 dinlemek bile çok şarj harcıyorsa bu kabul edilemez. Bu yüzden 4.0 ile birlikte düşük enerjili (Low Energy) sürümlere geçildi ve son sürümlerde düşük enerji üzerine yoğunlaşıldı.

### 12.2 Bluetooth'un Teknik Özellikleri

Hocanın slayttan aktardıkları:

- Bluetooth, IEEE 802.15 projesindedir.
- İlk sürüm Ericsson tarafından 1994'te çıkarıldı.
- Bluetooth Özel İlgi Grubu (Bluetooth Special Interest Group, SIG) tarafından geliştirilir.
- 2,45 GHz civarındaki kanallarda yayın yapar.
- Kanalları frekans atlamalı yayılı spektrum mantığıyla kullanır.
- Antenin gücüne göre 10 metreden 100 metreye kadar yayın yapabilir.

> **Ders sonrası not:** Hoca kanal sayısını "90 küsur" ve ilk sürümün hızını "24 Mbps'e kadar" verdi. Klasik Bluetooth büyük olasılıkla 1 MHz genişliğinde 79 kanal kullanır, BLE ise 2 MHz genişliğinde 40 kanal. İlk sürümün hızı büyük olasılıkla yaklaşık 1 Mbps'tir. 24 Mbps, büyük olasılıkla Bluetooth 3.0 + HS'te yanındaki 802.11 bağlantısı üzerinden ulaşılan hızdır. Bluetooth'un standart numarası büyük olasılıkla 802.15.1'dir. Ders tarihinde en güncel sürüm büyük olasılıkla 5.3'tü.

### 12.3 Eşleştirme, Piconet ve Scatternet

Bluetooth cihazları eşleştirme (pairing) ile çalışır. Örneğin kulaklığa bağlanırken bir şifre olur. Bir taraf şifreyi girer, diğeri de girer. Eşleştikten sonra birbirine veri gönderebilirler: Kulaklıksa müzik dinlersiniz, bir arkadaşınızın telefonuyla eşleşince dosya aktarırsınız.

Peki noktadan noktaya (point-to-point) çalışan bu sistemle bir ağ nasıl kurulur? Bunun için piconet kurulur:

- **Piconet:** Bluetooth cihazlarından oluşan bir ağ. İçinde aktif olarak veri gönderen en çok 8 cihaz olabilir. Ağa bağlı olup veri göndermeyen (beklemedeki) cihaz sayısı ise 255'e kadar çıkabilir.
- **Scatternet:** Aktif cihaz sınırı 8 ise daha büyük ağ nasıl kurulur? Piconet'ler bir araya gelerek scatternet'i oluşturur.

### 12.4 ZigBee

Hoca ZigBee'yi daha düşük enerjili, daha düşük donanımlı bir teknoloji olarak anlattı. Düşük sıklıkta ve düşük hacimde veri gönderilmesi ya da işlenmesi istendiğinde, sensörlü makinelerde kullanılır.

Hocanın örneği: Bir seradasınız. Seranın sıcaklığını ve nemini ölçüp saatte bir kez merkeze gönderen bir yapınız var. Çalışma sıklığı saatte bir, gönderilen veri belki tek bir bayt. Böyle bir şeyin hızlı olmasına hiç gerek yoktur. Ama bu sensörlerden 300 tane, belki 1000 tane gerekebilir. Bu yüzden ucuz olmaları gerekir. Yüksek veri aktarımına elverişli değildir, zaten ihtiyaç da duyulmaz. Yüksek veri aktarımı gerekiyorsa başka teknolojiler kullanılmalıdır. Nesnelerin interneti (Internet of Things, IoT) uygulamalarında sıkça kullanılır.

> **Ders sonrası not:** Hoca ZigBee'yi "Bluetooth'un bir versiyonu" ve "Bluetooth altyapısını kullanan" bir teknoloji olarak tanıttı. ZigBee Bluetooth'tan bağımsızdır. Büyük olasılıkla IEEE 802.15.4 standardının üzerine kurulmuştur. Bu da düşük güçlü, düşük hızlı bir kişisel alan ağı standardıdır.

### 12.5 HomeRF ve HiperLAN

- **HomeRF:** Hocaya göre IoT kavramı içinde, yani akıllı evler ve küçük cihazlarla haberleşme için düşünülmüştü. Ev içinde yalnızca sıcaklık ya da nem ölçen cihazlara radyo sinyalleriyle bağlanıp veri almak için standartlaştırılmıştı. Yaklaşık 2003-2004 yıllarında, başka teknolojiler gelişip bu açığı kapatınca gerek görülmedi ve sürdürülmedi.
- **HiperLAN:** Kişisel alan ağı ya da yerel ağ olarak kullanılan hizmeti genişletmek için ortaya atıldı. Yerel ağ 100 metrelik ya da 3-5 odalık bir alandır. HiperLAN ile örneğin bir kampüsün tamamının tek bir yerel ağ içinde olması amaçlandı. Gelişen teknoloji ve başka standartların öne çıkmasıyla bugün pek kullanılmıyor.

## 13. Kablosuz Ağlarda Tehditler ve Güvenlik

### 13.1 Dinleme ve İzinsiz Erişim

Kablolu ağı dinlemek için ya kabloyu kesip araya bir bağlantı (T) atarak kendinize bir hat çekmeniz ya da kablodan geçen akımın yarattığı elektromanyetik etkiyi ölçen bir cihaz kullanmanız gerekir. Bu cihazı kablonun üzerine koyarsınız ve geçen veriyi tespit eder. Veri şifreli değilse birebir dinleyebilirsiniz. Kablo kesilirse karşı taraf dinlendiğini anlayabilir.

Kablosuzda böyle bir engel yoktur. Zaten herkese yayın yapıyorsunuz. Ağınız açıktır, üst kattaki komşu da ağınızı görür. Şifre yoksa ya da güvenlik seviyesi düşükse bağlanır, sızar. Bu yüzden en büyük sorunlardan ikisi şunlardır:

- **Herkesin dinleyebilmesi.**
- **İzinsiz erişim:** Saldırgan mesaj gönderebilir, sizinkini alabilir, değiştirebilir ya da gönderilen mesajı değiştirip yerine başka bir mesaj koyabilir.

Hoca, kaldığı sitede telefonunun Wi-Fi'ını açsa pek çok ağ göreceğini söyledi. Biri veri çalmak için değil, sadece başkasının parasını ödediği internetten yararlanmak için bile bu ağlara girmek isteyebilir. Yetkilendirmede (authorization) sorun varsa, böyle bir sızıntıyla ağa girebilir.

### 13.2 Kimlik Doğrulamayı Atlatma: Aynı Adlı Sahte Ağ

Hoca, kimlik doğrulama (authentication) kısmında kullanılan bir hileyi, "yapın diye söylemiyorum, ne tür yaklaşımlar olduğunu anlatıyorum" diyerek anlattı:

1. Komşunuzun bir ağı var, adı "Furkan". Bağlanmak istediğinizde ağ sizden şifre, protokole göre belki kullanıcı adı ve şifre ister. Bilmediğiniz için bağlanamazsınız.
2. Komşunuzun modemi salonda, sizin salonunuz hemen altında. Bağlanabilseniz çok güçlü bağlanırsınız. Şifreyi öğrenmeniz gerekir.
3. Kaba kuvvetle (brute force) şifreyi deneyerek bulmak artık yıllar sürer.
4. Komşunuz yatak odasına gidince telefonu modemden uzaklaşır ve sinyali zayıflar. Siz de onun yatak odasının tam altındaki odadasınız.
5. Siz, komşunuzun ağıyla aynı adda (aynı SSID'de, yine "Furkan") bir ağ yayarsınız.
6. Komşunun telefonu, adı aynı olduğu için kendi ağı yerine sizin ağınıza bağlanmaya çalışır.
7. Şifreyi bilmediği için ekranda bir pencere (pop-up) açılır: "Şifreni ve kullanıcı adını gir." Kullanıcı bir sorun olduğunu düşünüp bilgilerini girer ve gönderir.
8. Artık kullanıcı adı ve şifre sizdedir. Kendi yayınınızı kapatırsınız. Kullanıcı kendi ağına bağlanır, siz de öğrendiğiniz bilgilerle onun ağına bağlanırsınız.

Bu yüzden kimlik doğrulama sistemlerinin iyi kurulması gerekir.

> **Ek bilgi (derste anlatılmadı):** Gerçek bir ağın adını taklit eden bu tür sahte erişim noktasına literatürde "kötü ikiz" (evil twin) denir. Kurumsal ağlarda istemcinin erişim noktasının sertifikasını doğrulaması bu saldırıyı zorlaştırır. Ev ağlarında WPA3'ün parola tabanlı el sıkışması da büyük olasılıkla parolanın bu şekilde ele geçirilmesini zorlaştırmak için tasarlanmıştır.

### 13.3 Girişim, Karıştırma ve Fiziksel Tehditler

- **Girişim (interference):** Kanalların, daha önce gösterildiği gibi, birbirinin üzerinde etki bırakmasıdır. Bir kanalda yayın yapan cihazın anteni çok yüksek güçte çalışıyorsa, aynı kanalda başka ağlarda yayın yapanlar bile birbiriyle konuşamaz. Hocanın benzetmesi: Herkes farklı borulardan birbiriyle konuşuyor ve duyabiliyor. Ama ben öyle yüksek sesle bağırıyorum ki benim bağırışımdan başka hiçbir şey anlaşılmıyor.
- **Karıştırma (jamming):** Daha önce anlatıldığı gibi, bir sinyalin başka bir sinyal (karıştırma sinyali) tarafından hiç yokmuş gibi kesilmesidir.
- **Fiziksel tehditler:** Örneğin kediniz ya da köpeğiniz modemi alıp başka bir yere götürürse işinizde sorun çıkabilir.

### 13.4 Şifreleme ve Güvenlik Protokolleri

Şifrelemenin (encryption) amacı şudur: Biri mesajınıza kulak misafiri olsa bile, uçtan uca şifreyi bilmiyorsa mesaj onun için hiçbir anlam ifade etmemelidir. Gelişmiş Şifreleme Standardı (Advanced Encryption Standard, AES) ile şifrelenmiş bir mesajı çözmek yüzyıllar sürer.

Modem ayarlarında görülen güvenlik tipleri:

- **WEP:** Şifrelemesi çok zayıftır. Pek çok sorun çıkıyordu.
- **TKIP:** Hocaya göre artık güvenilir olmadığı için 2008'de modemlerden kaldırıldı. Sızılmaması neredeyse imkânsızdır.
- **WPA2:** AES kullanır.

Hoca, bazı WPA ayarlarının "DES mi, AES mi" diye seçtirdiğini söyledi. DES, Veri Şifreleme Standardı'dır (Data Encryption Standard). AES çok daha gelişmiş bir şifreleme tekniğidir. Hoca böyle bir seçimde AES'in seçilmesini tavsiye etti. Az önceki kimlik doğrulama sorunlarını yaşamamak için de Genişletilebilir Kimlik Doğrulama Protokolü (Extensible Authentication Protocol, EAP) vardır. Güvenlik ayarlarını WPA2 ile yapanların daha iyi sonuç alacağını söyledi.

> **Ders sonrası not:** Modemlerde sunulan seçim büyük olasılıkla "DES mi AES mi" değil, "TKIP mi AES (CCMP) mi"dir. TKIP, WEP'in yerine geçici bir çözüm olarak geldi. TKIP'e yönelik saldırılar büyük olasılıkla 2008'de yayımlandı; standarttan kaldırılması ise büyük olasılıkla 802.11-2012 ile oldu. Bugün WPA3 de vardır.

## 14. LAN Teknolojilerinin Karşılaştırması

Ders boyunca anlatılan ağlar avantaj ve dezavantajlarıyla karşılaştırıldı: 802.3 Ethernet, 802.4 Token Bus, 802.5 Token Ring, fiber tabanlı FDDI ve bu derste anlatılan kablosuz LAN (WLAN).

### 14.1 IEEE 802.3 Ethernet

Avantajlar:

- Çok yaygın kullanılır.
- Algoritması ve kurulumu basittir. Yıldız topolojisinde yeni bir bilgisayar eklemek çok kolaydır.
- Sayısal (dijital) teknikler kullanılır. En düşük anlamlı bit (Least Significant Bit, LSB) önce gönderilir.
- Manchester kodlama kullanılır. Hoca, Manchester'ın çeşitli sorunları çözdüğünü, Differential Manchester'ın da ondan bir tık daha iyi olduğunu hatırlattı.
- Düşük yükte neredeyse sıfıra yakın gecikmeyle çalışabilir.

Dezavantajlar:

- Çarpışma algılama donanımı analog (hocanın deyişiyle "örneksel") bir donanımdır. Bu yüzden çarpışma algılama performansı düşüktür. Çarpışma algılanamadığında hat kullanım oranı iyice düşer.
- Çok yüklü çalışmada çarpışma olasılığı iyice artar.
- Gerçek zamanlı uygulamalar için kesinlikle ideal değildir. Hocanın örnekleri: Bir verinin karşıya mutlaka iletilmesi gereken askerî durumlar ya da canlı video akışı (streaming), canlı oyun izleme veya oynama. Bu konuda Token Bus ve Token Ring'e göre performansı düşüktür.
- Öncelik mekanizması yoktur. Token Bus ve Token Ring'de vardır.
- En küçük çerçeve 64 bayttır. Token Bus ve Token Ring'de binlerce baytlık çerçevelerden bahsediliyordu. Hoca Ethernet'in çerçeve boyutunun küçük olmasını bir dezavantaj olarak saydı.

### 14.2 IEEE 802.4 Token Bus

Avantajlar:

- Oldukça kararlı bir performans gösterir.
- Öncelik mekanizması vardır. Ağdaki bazı cihazlar gerçek zamanlı işlem yapmak istiyorsa, onlara önce hak tanınması önemlidir.
- Yüklü çalışmada mükemmel sonuç verir.
- Birden fazla analog kanal üzerinden erişim imkânı sağlar.

Dezavantajlar:

- Düşük veri yükünde gecikme artar. Hocanın örneği: Bir çerçeve 2000 bayt veri alabiliyor, ama siz içine 2-3 bayt koyup gönderiyorsunuz ve onun gitmesi bekleniyor.
- Analog olmasının dezavantajları vardır: Ağdaki bütün donanım elemanlarının analog çalışması gerekir.
- Protokol yapısı, özellikle MAC kısmı, son derece karmaşıktır.
- Fiber altyapı kullanımına uygun değildir. Bu, onu günümüzde dezavantajlı bir konuma koyar.

### 14.3 IEEE 802.5 Token Ring

Avantajlar:

- 8 seviyeli öncelik mekanizması vardır.
- Rezervasyon imkânı vardır.
- Differential Manchester kodlama kullanılır. En yüksek anlamlı bit (Most Significant Bit, MSB) önce gönderilir. Bu kodlama eşzamanlama (senkronizasyon) ve DC bileşen sorunlarını ortadan kaldırdığı için başarımı artırır.
- Yüksek yükte yüksek verim sağlar.
- Yalnızca bakır kablo değil, çok farklı iletim ortamlarında çalışabilir.
- Hem kısa hem uzun çerçevelerle kullanılabilir. Ethernet kısa çerçevelerde, Token Bus uzun çerçevelerde yüksek performanslıydı. Token Ring ikisinde de kullanılabilir.
- Token Bus gibi kararlıdır.

Dezavantajlar:

- Hoca, burada dezavantaj sayılan şeyin aslında bir avantaj olduğunu söyledi. Token Ring'de öksüz çerçeve (orphan frame) ve jeton kaybı sorunları vardı. Bunları izleyen bir izleyici cihaz (monitoring device) bulunur. Bu cihaz olayları izlediği için gecikmelere sebep olur. Ayrıca birinin bu cihazla ayrıca ilgilenmesi ve geliştirmesi gerekir.
- Düşük yükte jeton iletiminde gecikmeler yaşanır.

### 14.4 FDDI

Avantajlar:

- Zamana duyarlı, yani gerçek zamanlı çalışması gereken veriler fiber üzerinde daha hızlı iletilir.
- Çift halka kullanımı performansı artırır. Bir halkada sorun olduğunda gönderim diğer halka üzerinden sürer.
- Ağ cihazı olarak çift bağlantılı (Dual Attached Station, DAS) ve tek bağlantılı (Single Attached Station, SAS) istasyonlar vardı. Çift bağlantılılar üzerinde çift hat kurulabiliyordu.
- Fiber kullanımıyla kapsanan mesafe çok artar. Hoca bakır kabloda elektriğin iletimini, fiberde ışığın iletimini düşünmemizi istedi.

Dezavantaj:

- Donanım tarafında desteklenebilen en yüksek hızlar gelişirken, bu yöntem kendini o kadar geliştirememiştir.

### 14.5 WLAN

Avantajlar:

- En büyük avantajı hareketliliktir: Kabloya bağlı olma ihtiyacı yoktur.
- Özellikle kablo çekilmesinin mümkün olmadığı yerlerde çok kullanışlıdır.

Hoca, WLAN'ın belki hayatımıza en son giren teknoloji olduğunu, ama her zaman onu kullanacağımız anlamına gelmediğini söyledi. Evde oyun oynarken performans daha yüksek olsun diye bilgisayara kablo takarsınız. Ama kabloyu taktığınız andan itibaren hareketli olmazsınız.

Dezavantajlar:

- Mesafesi diğerlerine göre çok kısıtlıdır. Hocaya göre en fazla, 802.11n'de dış ortamda 250 metreye ulaşılabilir. Bunun ötesinde ağ kurulamaz.
- Kablolu ağlara göre iletişim hızı düşüktür.

> **Ek bilgi (derste anlatılmadı):** Hocanın DCF'yi anlatırken değindiği "öncelikli istasyon daha küçük aralıktan seçer" fikri, büyük olasılıkla 802.11e ile gelen geliştirilmiş dağıtık kanal erişimine (EDCA) karşılık gelir. Orada ses, görüntü, normal ve arka plan trafiği için ayrı erişim sınıfları vardır. Yüksek öncelikli sınıfların hem bekleme süresi hem çekişme penceresi daha küçüktür, bu yüzden ortalamada daha önce söz alırlar.

## Örnek Sorular

**1. (derste sözlü, 00:24:45)** CW değeri ne işe yarar?

> **Çözüm (derste verildi):** Her istasyonun bir W değeri vardır, başlangıçta örneğin 4'tür. Geri çekilme sayacı, bu W'den hesaplanan bir aralıktan rastgele seçilir. Önceliği olan istasyon daha küçük bir aralıktan (hocanın örneğinde 0 ile 5 arası) seçim yapar, önceliği olmayan tüm aralıktan rastgele seçer. Slayttaki örnekte W = 5 olduğu için üst sınır 31'dir ve 10, 19, 25 değerleri seçilmiştir: Bu istasyonlar sırasıyla 10, 19 ve 25 zaman dilimi beklemelidir. Çarpışma olunca ya da bir istasyon art arda çok fazla gönderince W bir artar ve aralık büyür, yani ortalama bekleme süresi uzar. Doğru aralık $[0,\ 2^W - 1]$'dir: W = 4 için 0–15, W = 5 için 0–31, W = 6 için 0–63.

**2. (derste sözlü, 00:35:50)** Gizli düğüm sorunu, A'nın C'yi görememesi midir?

> **Çözüm (derste verildi):** Evet. A–B–C dizilişinde A'nın kapsamında yalnızca B, C'nin kapsamında da yalnızca B vardır. A, C'yi; C de A'yı göremez ve birbirinin varlığından habersizdir. Bu yüzden A'nın CTS'i C'ye ulaşmaz. C, B'ye gönderirse çarpışma B'de olur.

**3. (derste sözlü, 00:56:28)** Wi-Fi kanalları neden bu frekans aralığında tutuluyor, daha geniş yapılamaz mı?

> **Çözüm (derste verildi):** Sınır fiziksel değil yasaldır. 2,4 GHz ve 5 GHz çevresindeki bantlar otoritelerce halkın ücretsiz kullanımına açılmıştır. Spektrumun büyük kısmı devletlerin, özellikle askerî kullanımına ayrılmıştır. Bir kısmı da radyo kanallarında olduğu gibi satın alınarak kullanılır. Düzenlemeler zamanla değişebilir ve yeni bantlar eklenebilir.

**4. (derste sözlü, 01:28:55)** Token Bus ve Token Ring bugün bilinen bir yerde kullanılıyor mu?

> **Çözüm (derste verildi):** Hocanın cevabı: Kullanılıyor. Bunlar veri bağlantı katmanında, ortam erişim denetimi kısmında arka planda çalışan tekniklerdir. Veri bağlantı katmanında HDLC gibi tekniklerle yapılan akış denetiminin evrimleşmiş ya da onu temel alarak geliştirilmiş hâlleridir.

> **Ders sonrası not:** Token Bus ve Token Ring büyük olasılıkla bugün yeni kurulumlarda neredeyse hiç kullanılmıyor. Yerel ağlarda yerlerini büyük ölçüde anahtarlamalı Ethernet aldı. IEEE'nin 802.4 ve 802.5 çalışma grupları da büyük olasılıkla dağıtıldı. Jeton dolaştırma fikri ise bazı endüstriyel ağlarda yaşamaya devam ediyor.

## Dersin Toparlaması

Bu derste kablolu yerel ağlardan sonra IEEE 802.11 kablosuz yerel ağlar ele alındı. Kablosuz ortamda antenler yarı çift yönlü çalıştığı için çarpışma algılanamaz. Bu yüzden 802.11, çarpışmayı algılamak yerine ondan kaçınmaya çalışır (CSMA/CA). DCF'de istasyon hattı dinler, DIFS bekler, hat meşgulse rastgele bir geri çekilme sayacıyla çekişmeye girer. İlk sıfıra inen gönderir, diğerleri sayaçlarını dondurur. ACK, DIFS'ten kısa olan SIFS sonrasında gönderildiği için önceliklidir. Çarpışan istasyonların çekişme penceresi büyüyerek cezalandırılır. RTS/CTS ve NAV ile ortam önceden ayrılır. Ama bu düzende gizli düğüm (çarpışma) ve açıkta kalan düğüm (boşuna bekleme) sorunları vardır. 2,4 GHz bandında kanallar 5 MHz arayla dizildiği ve 22 MHz genişliğinde olduğu için örtüşür; örtüşmeyen üçlü 1, 6 ve 11'dir. Frekans arttıkça hız artar, menzil kısalır.

Dersin ikinci yarısında Bluetooth (piconet, scatternet), ZigBee, HomeRF ve HiperLAN tanıtıldı, hücresel nesillerle birlikte hız ve menzil karşılaştırması yapıldı. Ardından kablosuz ağlara özgü tehditler (dinleme, izinsiz erişim, aynı adlı sahte ağ, girişim, karıştırma) ve WPA2/AES, EAP gibi korunma yolları anlatıldı. Ders, Ethernet, Token Bus, Token Ring, FDDI ve WLAN'ın avantaj ve dezavantajlarının karşılaştırılmasıyla bitti. Hoca, bağlantılı ve bağlantısız hizmetler ile anahtarlama konusunun gelecek haftaya kaldığını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
