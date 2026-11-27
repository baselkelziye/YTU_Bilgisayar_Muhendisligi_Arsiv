# Ders 20 Genişletilmiş Notu: Bağlantı Sonlandırma, Hata ve Akış Denetimi, Çökmeden Kurtarma ve Tıkanıklık Denetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlantının Sonlandırılması
- 2. Hata Denetimi ve Akış Denetimi
- 3. Tampon Stratejileri
- 4. Akış Denetimi Örneği
- 5. Çoğullama ve Ters Çoğullama
- 6. Çökmeden Kurtarma
- 7. Tıkanıklık Denetimi ve İstenen Bant Genişliği Paylaşımı
- 8. Gönderim Hızının Ayarlanması
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağlantının Sonlandırılması

Bu derste iki şubenin öğretim üyeleri birlikte, dönüşümlü olarak ders anlattı. Taşıma katmanı konusuna önceki derste kalınan yerden, bağlantı kurulumundan (connection establishment) sonra gelen bağlantı sonlandırmayla (connection release) devam edildi. Önceki derste bağlantının üç mesajlaşmalı el sıkışmayla (three-way handshake) kurulduğu görülmüştü.

### 1.1 Sonlandırma neden hassastır?

Bağlantının sonlandırılması da kurulması kadar önemli ve hassastır. Taşıma katmanında bağlantı yönelimli (connection-oriented) çalışıldığı için, alttaki ağ katmanı paket kaybedebiliyor olsa bile, bağlantı kurulduktan sonra kapanış dahil hiçbir paketin kaybolmaması gerekir. Göndericiden çıkan paketler, son paket de dahil olmak üzere, karşı tarafa güvenilir ve sıralı biçimde aktarılmalıdır.

Ağ katmanı güvenilir değildir ve çoğu zaman datagram modunda çalışır: paketler kaybolabilir, gecikebilir, çoğalabilir (duplicate). Bu yüzden bağlantı sonlandırılırken en son çıkmış paketlerin de hedefe vardığından emin olmak gerekir.

Hoca daha önce de söylenen bir noktayı hatırlattı: A hostundaki uygulama B hostundaki uygulamayla konuşurken özel bir durum yoksa iletişimin çift yönlü (duplex) olduğu varsayılır. Ancak bu çift yönlü iletişim aslında iki tane tek yönlü akışla sağlanır: biri A'dan B'ye, diğeri B'den A'ya. Dolayısıyla A tarafı bağlantıyı kapatmak istediğinde B'den A'ya akış devam edebilir; bunu engelleyen bir şey yoktur. Benzer şekilde B, A'ya artık göndermek istemediğinde A'dan B'ye akışın duracağının garantisi yoktur.

Bu yüzden bağlantı sonlandırmanın temel fikri şudur: kapatmayı hangi taraf başlatırsa başlatsın, diğer taraf bağlantının sonlandırılacağından haberdar olmalı, paket göndermeyi kesmeli ve ağ katmanında hâlâ hareket halinde olan, farklı yollardan farklı gecikmelerle gelecek paketlerin hedefe varması beklenmelidir. İstemci de sunucu da bağlantıyı kapatabilir; ama "bağlantıyı kapattım, sonrası beni ilgilendirmez" denemez.

### 1.2 Asimetrik sonlandırma

Slayttaki ilk şekil asimetrik sonlandırmayı gösteriyordu (ekrandan, 00:15:00). Slayttaki ifadeler: "Key problem is to ensure reliability while releasing" ve "Asymmetric release (when one side breaks connection) is abrupt and may lose data". Zaman ekseninde aşağı doğru akan mesajlar şöyledir:

| Sıra | Yön | Mesaj |
|---|---|---|
| 1 | Host 1 → Host 2 | CR |
| 2 | Host 2 → Host 1 | ACK |
| 3 | Host 1 → Host 2 | DATA |
| 4 | Host 1 → Host 2 | DATA (yoldayken) |
| 5 | Host 2 → Host 1 | DR |

Host 2, Host 1'in ikinci DATA'sı henüz yoldayken DR (Disconnect Request) gönderir ve bağlantıyı bırakır. Şekildeki not: "No data are delivered after a disconnect request"; ikinci DATA Host 2'de teslim edilmez (şekilde X ile gösterilir). Normal akışta bağlantı isteğine onay gelir ve veri akmaya başlar, ama ikinci veri gelirken karşı taraf bağlantıyı kesmiştir; bu dikkate alınmazsa veri kaybı kaçınılmazdır.

Hoca "abrupt" kelimesindeki "-rupt" kökünü "interrupt"taki kesinti anlamıyla ilişkilendirdi: bağlantı koparılıp atılır ve sonrası ortada kalır. Böyle bir şeyin olmaması gerekir.

### 1.3 Simetrik sonlandırma ve iki ordu problemi

Slayttaki ikinci ifade: "Symmetric release (both sides agree to release) can't be handled solely by the transport layer" ve "Two-army problem shows pitfall of agreement" (ekrandan, 00:20:00). Simetrik sonlandırmada iki taraf "bunu karşılıklı kapatalım" diye anlaşır; ama iki tarafın aynı anda kapatmaya ikna olması tek başına taşıma katmanı tarafından sağlanamaz. Hoca bunun genel bir ilkeye bağlandığını söyledi: bir katmanda, o katmanı etkileyen hata durumları o katmanın içinde çözülemez; çözüm bir üst katmanda gerçekleşmelidir.

Şekilde vadide bir beyaz ordu (White army, 3 asker), iki yandaki tepelerde ise birer mavi ordu (Blue army #1 ve Blue army #2, ikişer asker) vardır; mavi ordular birbirine "Attack?" diye sorar. Toplam olarak mavi ordular (4) beyaz ordudan (3) güçlüdür; ama bu üstünlük ancak iki mavi ordu aynı anda saldırırsa işe yarar. Ayrı ayrı saldırırlarsa sayıları 3'ten az olduğu için yenilirler. Saldırı anını eşzamanlamak için aralarında mesajlaşırlarsa mesajlar vadideki beyaz ordunun içinden geçer, yakalanabilir; dolayısıyla eşzamanlama sağlanamaz.

Örnek savaş üzerine kuruludur ama ağdaki karşılığı şudur: ağ katmanı taşıma katmanının paketlerini bilerek ve düşmanca kaybetmez, ama kaybederek, geciktirerek, yanlış yere götürerek, çift teslim ederek ya da farklı gecikmelerle teslim ederek taşıma katmanındaki eşzamanlamayı ve simetrik yapıları bozar. Kâğıt üzerinde A ve B mikrosaniyesine kadar aynı anda kapatmaya karar verebilir gibi görünse de gerçekte böyle bir şey yoktur; çözüm, ağ katmanının sorunları bilinerek üretilmelidir.

### 1.4 Normal sonlandırma sırası

Slayt: "Normal release sequence, initiated by transport user on Host 1", "DR=Disconnect Request", "Both DRs are ACKed by the other side" (ekrandan, 00:25:00).

| Adım | Host 1 | Mesaj | Host 2 |
|---|---|---|---|
| 1 | Send DR + start timer | DR → | |
| 2 | | ← DR | Send DR + start timer |
| 3 | Release connection; Send ACK | ACK → | |
| 4 | | | Release connection |

Host 1 bir DR gönderir ve aynı anda bir zamanlayıcı başlatır. Bu DR makul bir süre sonra Host 2'ye ulaşır; Host 2 de bunu kendi DR'si ile onaylar ve o da bir zamanlayıcı (timeout) başlatır, çünkü kendi gönderdiği DR'ye Host 1'den bir onay bekler. Normalde Host 2'nin DR'sinin, Host 1'in zamanlayıcısı dolmadan gelmesi beklenir. Host 1 bağlantıyı bırakır ve son onayı (final ACK) gönderir; bu da Host 2'nin zamanlayıcısı dolmadan ulaşır ve Host 2 bağlantıyı bırakır. Her şey düzgünken, kayıp ve ek gecikme yokken bağlantı yine üç mesajla sonlanır.

> **Hocanın vurgusu:** Bağlantı sonlandırma da üç mesajla yapılan bir el sıkışmadır; ama "three-way handshake" terimi hep bağlantı kurmayla ilişkilendirildiği için sonlandırma için bu terimi kullanmayın, yanlış kullanmış olursunuz. Yalnız sonlandırmanın da üç mesajla yapıldığını bilin.

Hoca burada bir düşünme sorusu da sordu ve cevabını verdi (bkz. Örnek Sorular): zamanlayıcılar yalnız DR'nin belirli sürede karşıya gidip cevap üretilmesini sağlamaz; değerleri, ağ katmanında farklı yollardan, farklı gecikmelerle hâlâ gelmekte olan paketlerin de hedefe ulaşmasını garanti edecek kadar uzun seçilmelidir. Çünkü hiçbir paketin kaybolmaması hedeflenmektedir.

### 1.5 Hata durumları

Slayt: "Error cases are handled with timer and retransmission" (ekrandan, 00:30:00). Önceki slayt "mutlu senaryo" (happy path) idi; bu slaytta en kötü durumlar vardır.

```text
a) Final ACK lost, Host 2 times out
   Host 1: Send DR + start timer         --DR-->
   Host 2: Send DR + start timer         <--DR--
   Host 1: Release connection
   Host 1: Send ACK                      --ACK--> (Lost)
   Host 2: (Timeout) release connection

b) Lost DR causes retransmissions
   Host 1: Send DR + start timer         --DR-->
   Host 2: Send DR & start timer         <--DR-- (Lost)
   Host 1: (Timeout) send DR + start timer --DR-->
   Host 2: Send DR & start timer         <--DR--
   Host 1: Release connection
   Host 1: Send ACK                      --ACK-->
   Host 2: Release connection

c) Extreme: Many lost DRs cause both hosts to timeout
   Host 1: Send DR + start timer         --DR-->
   Host 2: Send DR & start timer         <--DR-- (Lost)
   Host 1: (Timeout) send DR + start timer --DR--> (Lost)
   Host 1: (N Timeouts) release connection
   Host 2: (Timeout) release connection
```

Soldaki senaryoda DR'ler karşılıklı gider gelir, ama Host 1'in son ACK'i kaybolur. Host 2 kendi zamanlayıcısı dolduğunda yeniden deneme yerine en yalın haliyle şunu düşünebilir: "Karşı taraftan DR geldi, ben de DR gönderdim, artık ondan ekstra bir paket gelmeyecektir; zaman aşımım da doldu", ve bağlantıyı bırakır. Ortadaki senaryoda Host 2'nin DR'si kaybolur; Host 1 zaman aşımından sonra DR'yi yeniden gönderir ve akış normal biçimde tamamlanır. Sağdaki uç senaryoda aradaki ağ o kadar kötü durumdadır ki o kadar çok DR kaybolur ki iki host da zaman aşımına uğrar: Host 1 N zaman aşımından sonra, Host 2 kendi zaman aşımından sonra bağlantıyı bırakır.

<!-- BELİRSİZ: 00:29:42 ile 00:35:43 arasında altyazı yok; bu senaryoların sözlü anlatımının bir kısmı kayıtta okunamıyor. Senaryolar slayttan aktarıldı. -->

### 1.6 Daha kötü bir senaryo

Diğer hoca bu senaryoların hepsinin birleşimi olan, daha da kötü bir durum ekledi ve önce öğrencilere sordu (bkz. Örnek Sorular). Bütün senaryolarda ilk DR'nin karşıya temiz biçimde ulaştığı varsayılmaktadır. Oysa Host 1'in gönderdiği ilk DR kaybolabilir; tekrar gönderilir, tekrar kaybolur. Bu, en sağdaki durumun bir alt versiyonudur. Konuşulan mekanizmaya göre Host 1 her zaman aşımından sonra yeniden dener ve N denemeden sonra pes edip bağlantıyı kapatır. Ama Host 2'nin bundan hiç haberi olmaz. Hocaya göre olası en kötü senaryo budur; bu yüzden pratikte bağlantıda etkinlik olup olmadığına bakmak, bir keep-alive mekanizması kurmak gibi yöntemler kullanılır.

## 2. Hata Denetimi ve Akış Denetimi

### 2.1 Tanımlar

Konuya bu bölümden itibaren diğer hoca devam etti. Hata denetimi (error control) ve akış denetimi (flow control) daha önce veri iletişimi dersinde konuşulmuş olmalıdır. Hata denetimi, bilginin bir yerden başka bir yere istenen güvenilirlik düzeyinde aktarılmasıdır; burada istenen düzey hatasızlıktır, yani verinin baştan sona özgün haliyle aynı kalmasıdır. Akış denetimi ise hızlı bir göndericinin yavaş bir alıcıyı ezmesini engellemek, en basit haliyle gönderim hızını denetim altına almaktır.

Bunlar veri bağı katmanında zaten yapılır: hata denetimi için hata algılama kodu konur, otomatik yeniden gönderim isteği (ARQ) kullanılır. Akış denetimi için stop-and-wait ve kayan pencere (sliding window) kullanılır; hatta aynı anda çıkabilecek paket sayısı denetlenir ve hat verimli kullanılmaya çalışılır.

Slayttaki ifadeler (ekrandan, 00:40:00):

- "Foundation for error control is a sliding window (from Link layer) with checksums and retransmissions"
- "Flow control manages buffering at sender/receiver"
  - "Issue is that data goes to/from the network and applications at different times"
  - "Window tells sender available buffering at receiver"
  - "Makes a variable-size sliding window"

### 2.2 Veri bağı katmanında yapılan, taşıma katmanında neden tekrar yapılır?

Akla gelen ilk soru budur. Hata denetimi açısından: veri bağı katmanındaki hata denetimi iki düğüm arasında, tek bir atlamada (hop) yapılır; paketin bir düğümden diğerine doğru aktarılıp aktarılmadığını kontrol eder. Ama gönderilen paket bir sonraki düğüme geçip orada bir tamponda beklerken bozulabilir. Bu hata aynen kopyalanarak sonraki atlamalarda hiçbir sorun çıkarmadan ilerleyebilir. Bu yüzden son noktada, uçtan uca, bilginin gerçekten özgün bilgi olup olmadığı kontrol edilebilmelidir. Hoca bu konuda çalışmalar ve yayınlar olduğunu, bu ek kontrolün tam denetimi sağladığını söyledi.

Akış denetimi açısından da durum benzerdir. Veri bağı katmanındaki akış denetimi yalnız iki düğüm arasındaki tek hattın hızını denetler. Taşıma katmanındaki akış denetimi ise birden fazla atlamayı içerir. Ayrıca:

- Bir host üzerinde aynı anda haberleşen tek bir uygulama ya da süreç olmak zorunda değildir; birden çok uçtan uca haberleşme olabilir.
- Host'un birden çok arayüzü olabilir; hepsinin denetlenmesi gerekir.
- Veri bağı katmanı yalnız o bağlantıyla sınırlıdır; oysa o bağlantının üzerine çok farklı yerlerden gelen trafikler birleşir.

Bu nedenlerle bu işler hem alt katmanda hem taşıma katmanında birlikte yapılmalıdır.

> **Hocanın vurgusu:** Diğer hoca bunun en önemli noktalardan biri olduğunu ve hiçbir zaman atlanmaması gerektiğini söyledi: veri bağı katmanı tek atlamayla ilgilenir; çok atlamalı (multiple hop) yolda denetim üst katmana, taşıma katmanına taşınmalıdır. Uygulamaya bırakmak da çok anlamlı değildir.

<!-- BELİRSİZ: 00:42:39-00:46:12 arasında altyazı büyük ölçüde bozuk; hatadan en az kayıpla kurtulma ve değişken pencere boyutu üzerine ek açıklamalar okunamıyor. -->

### 2.3 Uçtan uca ilke ve hata düzeltmenin sınırı

Hoca kaynak olarak Saltzer'in 1984 tarihli çalışmasını verdi: bu işin yalnız veri bağı katmanıyla olmayacağı, uçtan uca (end-to-end) yapılması durumunda daha iyi olacağı üzerine bir çalışmadır. Veri bağı katmanında hata düzeltme ya da hata algılama uygulanabilir. Hata düzeltme kaç hataya karşı tasarlanırsa tasarlansın (1, 2, 3, 5, 10), tasarlanandan fazla hata olduğunda, örneğin tek hataya göre tasarlanmışken öyle iki hata olur ki bütün sağlamalar (checksum) düzgün çıkar, alıcı hata olduğunu anlayamaz. Sağlama tuttuğu için paket o atlamayı geçer, son noktaya ulaşır ve "düzgün" diye teslim edilir; üst katmanda da hata denetimi yapılmıyorsa hata fark edilmez.

Diğer hoca buna şunu ekledi: aynı çerçeve içinde birden fazla hata patlaması (burst) olmaması bir varsayımdır; olduğu zaman, örneğin bit dönmesi (bit flip) hatalarında, algılama yüzde yüz değildir. Tek bitlik hataların tamamı bulunur; iki bitlik hataların belli bir oranı bulunur; daha fazlası fark edilebilir ya da edilmeyebilir. Bu yüzden bir çerçevenin bir ülkenin bir ucundan öbür ucuna her atlamada hatasız geçmiş olması, gerçekten hatasız olduğu anlamına gelmez.

<!-- BELİRSİZ: 00:48:47'de algılama oranı için söylenen yüzde değeri (altyazıda "99.98") ve hangi koda ait olduğu net değil. -->

> **Ek bilgi (derste anlatılmadı):** Saltzer, Reed ve Clark'ın 1984 tarihli "End-to-End Arguments in System Design" makalesi büyük olasılıkla burada kastedilen çalışmadır. Makalenin ana fikri, bir işlevin ancak iletişimin uç noktalarındaki uygulamanın bilgisiyle tam ve doğru gerçeklenebileceği, alt katmandaki gerçeklemenin yalnız başarım iyileştirmesi olabileceğidir.

## 3. Tampon Stratejileri

Akış denetimi için gönderici ve alıcı, gelen veriyi işleyebilmek için tamponlamalıdır; bu tamponun nasıl yönetileceği önemli bir stratejidir. Slayt: "Different buffer strategies trade efficiency / complexity" (ekrandan, 00:50:00).

- a) Chained fixed-size buffers (zincirlenmiş sabit boyutlu tamponlar)
- b) Chained variable-size buffers (zincirlenmiş değişken boyutlu tamponlar)
- c) One large circular buffer (tek büyük dairesel tampon); şekilde TPDU 1, TPDU 2, TPDU 3, TPDU 4 art arda yazılmış ve altta kullanılmayan alan (unused space) gösterilmiştir.

### 3.1 Sabit boyutlu tamponlar

Hoca bunu işletim sistemlerindeki thread havuzuna benzetti: önceden örneğin 100 thread oluşturulur ve gelen istek bunlardan birine yönlendirilir. Burada da önceden belirlenmiş bir boyut vardır; her paket geldiğinde o boyutta bir ayırma (allocation) yapılır. Şekilde tamponlar bağlı liste gibi gösterilmiştir: bütün bellek baştan ayrılmaz, ihtiyaç oldukça ayrılır ve bağlı liste yapısı hızlı olsun diye kullanılır. Bütün tamponlar aynı boydaysa daha küçük paketler geldiğinde tamponun bir kısmı (şekildeki gri alan) boşa gider.

### 3.2 Değişken boyutlu tamponlar

Farklı boyutlarda tamponlar oluşturulabilir; her gelen isteğe o istek kadar tampon ayrılabilir. Ancak burada da iç parçalanma (internal fragmentation) tamamen engellenemez: ayrılan yere daha sonra konacak paket değişebilir ve yine bir boşluk kalabilir.

### 3.3 Dairesel tampon

Üçüncü alternatif, tamponu düz bir alan gibi düşünüp dairesel bir tampon olarak gerçeklemektir. Şekilde birbirinden tamamen farklı boyutta TPDU'lar vardır; her gelen segment tampona kalınan yerden yazılır ve hiç parçalanma olmaz. Ancak tek bir dairesel tampon oluşturabilmek için bu iş için kullanılacak bütün belleğin önceden ayrılması gerekir. Bu yüzden tampon kullanımının yüksek olmayacağı yerlerde mantıklı değildir. Tam verimli olması için bağlantının gerçekten sonuna kadar kullanılması gerekir; o zaman şekildeki kullanılmayan alan küçülür ve bellek kullanımı artar.

### 3.4 Trafiğe göre seçim

Ağ trafiği yüksek değilse, seyrek ve düşük hacimli ise, ihtiyaç oldukça ayırma ve bırakma büyük bir sorun değildir. Ancak trafik yüksekse sürekli ayırma-kullanma-bırakma döngüsü sorun olur. Programlamadan hatırlanacağı gibi bu ayırma heap alanında gerçekleşir; boş alanların bulunması, geri verilen alanların işletim sistemindeki sıkıştırma (compaction) mantığıyla ya da dinamik bellek yönetimindeki çöp toplama (garbage collection) ile bir bütün haline getirilmesi derken, yüksek trafik altında sürekli ayırma ve bırakma verimli olmaktan çıkar. Bellek en değerli kaynaklardan biridir.

<!-- BELİRSİZ: 00:55:10-00:56:18 arasında trafiğe göre strateji seçimi ve tamponların "chunk" (öbek) halinde gruplanarak ayrılması önerisi anlatılıyor; altyazı bozuk olduğu için ayrıntı çıkarılamadı. -->

## 4. Akış Denetimi Örneği

### 4.1 Gönderici ve alıcı arasında anlaşma

Akış denetimini yönetmenin yollarından biri, işi gönderici ile alıcı arasında bir anlaşma yapısına çevirmektir. Slayt: "Flow control example: A's data is limited by B's buffer" (ekrandan, 01:00:00). Tablodaki 16 adımlık mesaj dizisi şöyledir (B's Buffer sütununda B'nin tampon gözlerinde hangi sıra numaralarının bulunduğu yazılıdır):

| # | Yön | Mesaj | B's Buffer | Açıklama |
|---|---|---|---|---|
| 1 | A → B | <request 8 buffers> | | A wants 8 buffers |
| 2 | B → A | <ack = 15, buf = 4> | 0 1 2 3 | B grants messages 0-3 only |
| 3 | A → B | <seq = 0, data = m0> | 0 1 2 3 | A has 3 buffers left now |
| 4 | A → B | <seq = 1, data = m1> | 0 1 2 3 | A has 2 buffers left now |
| 5 | A → B (kayıp) | <seq = 2, data = m2> | 0 1 2 3 | Message lost but A thinks it has 1 left |
| 6 | B → A | <ack = 1, buf = 3> | 1 2 3 4 | B acknowledges 0 and 1, permits 2-4 |
| 7 | A → B | <seq = 3, data = m3> | 1 2 3 4 | A has 1 buffer left |
| 8 | A → B | <seq = 4, data = m4> | 1 2 3 4 | A has 0 buffers left, and must stop |
| 9 | A → B | <seq = 2, data = m2> | 1 2 3 4 | A times out and retransmits |
| 10 | B → A | <ack = 4, buf = 0> | 1 2 3 4 | Everything acknowledged, but A still blocked |
| 11 | B → A | <ack = 4, buf = 1> | 2 3 4 5 | A may now send 5 |
| 12 | B → A | <ack = 4, buf = 2> | 3 4 5 6 | B found a new buffer somewhere |
| 13 | A → B | <seq = 5, data = m5> | 3 4 5 6 | A has 1 buffer left |
| 14 | A → B | <seq = 6, data = m6> | 3 4 5 6 | A is now blocked again |
| 15 | B → A | <ack = 6, buf = 0> | 3 4 5 6 | A is still blocked |
| 16 | B → A (kayıp) | <ack = 6, buf = 4> | 7 8 9 10 | Potential deadlock |

### 4.2 Adım adım anlatım

A başta 8 tampon ister (satır 1). B bu 8'i karşılayamayacağını, 4 ile, yani 0-3 sıra numaralarıyla yetinilmesi gerektiğini söyler (satır 2). A 0 sıra numarasıyla m0'ı, 1 ile m1'i, 2 ile m2'yi gönderir. Ancak m2 beşinci adımda kaybolur ve B'ye ulaşmaz; A ise 0, 1, 2'yi gönderdiğini ve geriye bir kredisi kaldığını düşünür.

Satır 6'da B, 0 ve 1'i onaylar ve tamponunun 3 olduğunu söyler; yani 2, 3 ve 4'e izin verir. A daha önce 2'yi gönderdiği için 3 ve 4'ü gönderir (satır 7-8) ve kredisi biter. 2 için zaman aşımı olur ve A onu yeniden gönderir (satır 9).

Satır 10'dan itibaren B'nin onayları görülür: 4'e kadar her şey onaylanmıştır ama tampon 0'dır; A hâlâ bloklanmıştır. B tamponunu boşalttıkça yer açar: önce 1 (A artık 5'i gönderebilir), sonra 2 (B bir yerde yeni bir tampon bulmuştur). Bu açıldıkça alt satırlarda A'nın sıra numarasını artırarak yeni veri gönderdiği görülür: m5 ve m6 (satır 13-14). 5 ve 6 için onay gelmediği sürece A penceresini ilerletemez; B tarafındaki tampon doludur ve A bloklanır. Satır 15'te gelen onay 6'nın alındığını ama tamponda yer olmadığını söyler; A beklemede kalır.

Satır 16'da B "ack = 6, buf = 4" gönderir, yani bundan sonra 7, 8, 9 ve 10 gönderilebilir. Ancak A tarafındaki üç nokta, tıpkı beşinci satırda B tarafında olduğu gibi, mesajın A'ya ulaşmadığını gösterir. Önerilen haliyle bu protokolde bu onay A'ya gelmezse A bloklu kalmaya devam eder; B de A'dan bir şey alamadığı için bekler. Bu potansiyel bir kilitlenmedir (deadlock).

Kilitlenmeye çözüm olarak diğer hoca iki mekanizma saydı: zaman aşımı, ya da bu bilginin periyodik gönderilmesi; ikisi de aslında belirli bir zaman aşımından sonra onayı yeniden göndermeye denk düşer.

> **Ek bilgi (derste anlatılmadı):** Satır 2'deki "ack = 15" büyük olasılıkla 4 bitlik sıra numarası uzayında 0'dan bir önceki değeri, yani henüz hiçbir mesajın alınmadığını gösterir.

### 4.3 ACK'in anlamı

> **Hocanın vurgusu:** Her yıl burada kafa karışıklığı olur. Gerçek hayat gerçeklemelerinde onay (acknowledgement) bir sonraki beklenen sıra numarasını gösterir. Bu slayttaki ise farklıdır: "ack = 1", 1 de dahil olmak üzere doğru alındığı anlamına gelir. Gerçek hayatta bunun karşılığı "ack = 2" olurdu, yani "2'yi bekliyorum". Bu ikisini karıştırmayın.

Hoca kitabın genel yaklaşımını da hatırlattı: gerçek hayatta kullanılan protokolden önce kitapta olası, önerilen protokoller konuşulur, sonra gerçeği konuşulur. Burada da hata ve akış denetiminde yapılabilecekler konuşulmaktadır; bir adım sonra UDP, RTP ve TCP'de gerçek hayatta kullanılan protokollerin içindekiler konuşulacaktır.

### 4.4 Değişken boyutlu pencere

Bu örnekte onay mesajında yalnız onay gönderilmez; akış denetimi açısından bir sonraki turda ne kadar bilgi kabul edilebileceği de gönderilir. Tablodaki "buf" değerinin 0, 1 ya da 2 olması buna karşılık gelir: B önce sıfır mesaj kabul edebileceğini, iki adım sonra iki mesaj kabul edebileceğini söyler. Böylece pencere boyutu değişir; onay hem hata denetimine hem de akış denetimine hizmet eder. Slayttaki "variable-size sliding window" ifadesi bunu anlatır.

## 5. Çoğullama ve Ters Çoğullama

Slayt: "Kinds of transport / network sharing that can occur: Multiplexing: connections share a network address; Inverse multiplexing: addresses share a connection" (ekrandan, 01:05:00). Şekilde katmanlar 1-4 olarak numaralandırılmıştır. Çoğullama tarafında 4. katmandaki dört taşıma adresi tek bir ağ adresinde birleşir ve tek bir yönlendirici hattından (router lines) yönlendiriciye (to router) gider. Ters çoğullama tarafında tek bir taşıma adresi üç ağ adresine dağılır ve üç ayrı hattan aşağı iner.

Taşıma katmanında çoğullama iki şey için gereklidir. Birincisi daha önce konuşulmuştu: ağ katmanından gelen bilginin kime aktarılacağı. Bunun için bir port mekanizması vardır ve bu port mekanizması üzerinden çoğullama yapılır.

İkinci ihtiyaç ters çoğullamadır (inverse multiplexing). Bir host'un tek bir ağ adresi ya da tek bir ağ kartı (arayüzü) olması zorunlu değildir. Birden çok arayüzü olan bir host'ta bağlantılar bu arayüzlerin hepsini ya da birkaçını aynı anda kullanacak şekilde kurulabilir. Örneğin bir sunucunun iki arayüzünden biri bir anahtar (switch) üzerinden, diğeri başka bir anahtar üzerinden geçecek şekilde çapraz bağlanır. Bunun ilk amacı yedekliliktir (failover): biri arızalanınca diğerinden devam edilebilir. Ama kapasite ve hat varsa, ikisi birden çalışırken kapasiteyi iki katına çıkarmak için de kullanılır. Ters çoğullamayı düzgün yapabilmek için bağlantıların bir araya getirilerek (birleştirilerek) kullanılması gerekir; hangi bağlantı üzerinden gönderileceğine karar verilmeli, biri üzerinden gidilemiyorsa diğeri kullanılmalıdır.

Diğer hoca bunun daha alt katmandaki karşılığını hatırlattı: Link Aggregation Control Protocol (LACP), Medium Access Control (MAC) alt katmanının parçasıdır ve Ethernet'e aittir. Taşıma katmanında ise bir host'un birden çok ağ adresi olabileceği için yukarıdan aşağıya ters çoğullama yapılabilmelidir.

<!-- BELİRSİZ: 01:06:26-01:07:34 arasındaki anlatımın bir kısmı (ters çoğullamada bağlantıların birleştirilmesi ve LACP açıklaması) altyazıda bozuk. -->

## 6. Çökmeden Kurtarma

### 6.1 Yönlendirici çökmesi ve host çökmesi

Slayt: "Application needs to help recovering from a crash" ve "Transport can fail since A(ck) / W(rite) not atomic" (ekrandan, 01:10:00). Birkaç farklı çökme durumu vardır ve ayrı ayrı bakmak gerekir. Taşıma varlıkları (transport entities) hostlardadır; ISS içindeki yönlendiriciler ağ katmanında kalmayı sever, çünkü böylece diğer sorumluluklardan kurtulurlar. Ağ tarafında kaybolan her paket için hostlar yeniden gönderim yapar. Dolayısıyla yönlendiricilerden biri çökse, yeniden başlasa bile durum kurtarılabilir; burada sorun yoktur. Asıl sorun, çökmenin hostlardan birinde olmasıdır.

### 6.2 Dosya sunucusu örneği

Stop-and-wait protokolü kullanan bir dosya sunucusu düşünülsün. Gelen her segment üst katmana verilir ya da diske yazılır ve karşı tarafa "bu paketi aldım" diye onay gönderilir. Sorun şudur: paketi alıp çökmek, paketi alıp yazıp çökmek, paketi alıp yazıp onay gönderip çökmek ayrı ayrı olabilecek senaryolardır ve her biri farklı sorunlara yol açabilir.

- Önce onay, sonra yazma: paket alınır, onay gönderilir, sonra çökülür. Host yeniden ayağa kalktığında karşı taraf son paketin alındığını, yazıldığını ve her şeyin normal olduğunu sanır. Oysa paket alınmış, onayı gönderilmiş ama yazılamamıştır; veri kaybolmuştur.
- Önce yazma, sonra onay: paket alınır, yazılır, onay gönderilmeden çökülür. Host geri geldiğinde karşı taraf onay almadığı için paketi yeniden gönderir; bu sefer çift kayıt (duplicate) oluşur.

Slayttaki tablo bu sıralamaların ve göndericinin yeniden gönderim stratejisinin bileşimlerini gösterir:

| Gönderici stratejisi | AC(W) | AWC | C(AW) | C(WA) | W AC | WC(A) |
|---|---|---|---|---|---|---|
| Always retransmit | OK | DUP | OK | OK | DUP | DUP |
| Never retransmit | LOST | OK | LOST | LOST | OK | OK |
| Retransmit in S0 | OK | DUP | LOST | LOST | DUP | OK |
| Retransmit in S1 | LOST | OK | OK | OK | OK | DUP |

İlk üç sütun alıcının "önce ACK, sonra yaz" (First ACK, then write), son üç sütun "önce yaz, sonra ACK" (First write, then ACK) stratejisidir. Açıklamalar: OK = protokol doğru çalışır, DUP = protokol çift mesaj üretir, LOST = protokol bir mesaj kaybeder. Gördüğünüz üzere hiçbir satır her durumda iyi sonuçla bitmez: ya bir paket kaybedilir ya da çift üretilir.

> **Ek bilgi (derste anlatılmadı):** Tanenbaum'un gösteriminde büyük olasılıkla A = onay gönderme, W = yazma, C = çökme anlamındadır; parantez içindeki olay çökme nedeniyle hiç gerçekleşmez. S0, göndericinin yolda onaylanmamış segmenti olmadığı durum; S1 ise yolda onaylanmamış bir segment olduğu durumdur.

### 6.3 Genel ilke

Bu, dersin başında söylenen ilkeye geri döner: bu katmandaki sorunu bu katmanda çözemezsiniz; bir üst katmana bırakmanız gerekir. Genel ifadeyle: N. katmanda bir sorun ya da çökme varsa bu ancak N+1. katmanda çözülebilir.

### 6.4 Eş güçlü (idempotent) işlemler

Diğer hoca bunu bir para çekme işlemiyle örnekledi. Bazı işlemler arka arkaya n kez yapılsa da tutarlılık açısından sorun yaratmaz; bunlara eş güçlü (idempotent) işlem denir. Ama para çekme gibi işlemler n kez tekrarlanırsa kötü sonuçlara yol açar. Örneğin kişi 500 lira çeker, ama işlem çift işlendiği için hesabından 1000 lira düşer. Kayıp da kabul edilemez: hesaptan 500 lira çekildiği halde bu arka taraftaki kayda yansımaz ve hesapta hâlâ 500 lira görünür. Bir senaryoda bir taraf, öbür senaryoda diğer taraf zarar görür; bu yüzden çift kayıt da kayıp da kabul edilebilir değildir.

<!-- BELİRSİZ: 01:12:26-01:14:13 arasında altyazı kısmen bozuk; "Elimizde 5 şıkkı da var" ifadesinin neye karşılık geldiği net değil. -->

## 7. Tıkanıklık Denetimi ve İstenen Bant Genişliği Paylaşımı

### 7.1 Tıkanıklık denetiminin sorumluları

Slayt (ekrandan, 01:15:00): "Two layers are responsible for congestion control: Transport layer, controls the offered load [here]; Network layer, experiences congestion [previous]". Alt başlıklar: "Desirable bandwidth allocation", "Regulating the sending rate", "Wireless issues".

<!-- BELİRSİZ: 01:14:15-01:25:08 arasında altyazı neredeyse yok; bu bölümün sözlü anlatımı kayıtta okunamıyor. Aşağıdaki 7.2 bölümü slayttan aktarıldı. -->

### 7.2 Verimli kullanım: goodput ve gecikme

Slayt: "Efficient use of bandwidth gives high goodput, low delay" (ekrandan, 01:20:00). İki grafik vardır:

- Soldaki grafikte yatay eksen sunulan yük (offered load, packets/sec), dikey eksen goodput (packets/sec) ve yukarıda bir kapasite (capacity) çizgisi vardır. İstenen davranış (desired response), yük arttıkça goodput'un kapasiteye yaklaşmasıdır; tıkanıklık çöküşünde (congestion collapse) ise goodput belli bir noktadan sonra düşer. Slayt notu: "Goodput rises more slowly than load when congestion sets in".
- Sağdaki grafikte yatay eksen sunulan yük, dikey eksen gecikme (seconds) vardır; tıkanıklığın başlangıcında (onset of congestion) gecikme keskin biçimde artar. Slayt notu: "Delay begins to rise sharply when congestion sets in".

### 7.3 Adil kullanım ve max-min adalet

Slayt: "Fair use gives bandwidth to all flows (no starvation)" ve "Max-min fairness gives equal shares of bottleneck" (ekrandan, 01:25:00). Şekilde altı yönlendirici (R1-R6) ve dört akış vardır:

- A: R1 → R2 → R3 yolundan gider; payı 2/3.
- B: R4 → R5 → R2 → R3 yolundan gider; payı 1/3.
- C: R4 → R5 → R6 yolundan gider; payı 1/3.
- D: R4 → R5 → R6 yolundan gider; payı 1/3.

R4-R5 bağlantısı darboğazdır (bottleneck link): B, C ve D bu bağlantıyı paylaştığı için her biri 1/3 alır. R2-R3 bağlantısını A ve B paylaşır; B'nin payı darboğaz yüzünden 1/3'te kaldığı için A kalan 2/3'ü kullanır. (Bağlantı kapasiteleri 1 alınarak, payların adım adım artırılmasıyla python ile kontrol edildi: A = 2/3, B = C = D = 1/3.)

Bir hoca max-min adaleti şöyle özetledi ve diğer hoca onayladı: herhangi bir akışa verilen kapasite, diğer akışların bant genişliği kullanımını etkilemeyecek şekilde artırılabilmelidir. Birinin kapasitesini artırırken diğerlerininkini düşürmek zorunda kalınıyorsa max-min adalet sağlanmamış demektir. Bu yapıyı kurmak için iki yol vardır:

- Ağın geneli hakkında fikir sahibi olmak: ağda hangi akışların olduğuna, kimin nereden geçtiğine bakıp planlama yapmak. Bu çok olası bir durum değildir.
- Her akışın kapasitesini adım adım artırmak; belli bir kapasiteye gelip daha fazla artırılması durumunda diğer akışların etkileneceği düşünülen noktada o akışı durdurmak ve kalan kapasiteyi diğer akışlar arasında paylaştırmak.

### 7.4 Trafiğin değişkenliği ve yakınsama

Trafik sabit değildir. İsteğe bağlı video izleme, görüntülü ve sesli arama, gerçek zamanlı video konferans gibi uygulamalarda sahneler, konuşan sayısı değişir, sessizlikler gelir. Uygulamanın özelliğine göre de değişir: büyük indirim günlerinde bir e-ticaret sitesi bir saat sonra çok yoğun trafik almaya başlar; sınav sonucu açıklandığında da benzer bir ani artış olur. Bu değişkenlik daha önce ağ katmanındaki hizmet kalitesi (QoS) parametrelerinde de konuşulmuştu.

Hoca bunu devre dersinden bir örnekle açıkladı: bir sisteme genişliği sıfıra yakın, yüksekliği sonsuz bir impuls uygulanıp frekans spektrumuna bakılırsa, içinde çok sayıda frekansta yüksek değerli bileşenler görülür. Çünkü dengedeki bir sistemin dengesi bir anda bozulmuştur ve sistemin yeniden düzgün bir noktaya oturması zaman alır. Ağdaki ani trafik değişimleri de böyledir.

Slayt: "We want bandwidth levels to converge quickly when traffic patterns change" (ekrandan, 01:30:00). Grafikte yatay eksen zaman (saniye), dikey eksen bant genişliği payıdır (0, 0.5, 1):

- 0-1 s: yalnız Flow 1 vardır ve hattın tamamını (1) kullanır.
- 1. saniyede Flow 2 başlar; Flow 1 hızla yavaşlar ("Flow 1 slows quickly when Flow 2 starts"), Flow 1 azalırken Flow 2 artar ve ikisi 0.5 civarında buluşur.
- 4. saniyede Flow 3 başlar; Flow 3 küçük bir pay alır, Flow 1 ve Flow 2 biraz düşer. Hocaya göre Flow 3'ün payının artmamasının nedeni, Flow 3'ün kendini zaten sınırlamış olması, daha fazlasına ihtiyacı olmamasıdır.
- 9. saniyede Flow 2 durur ("Flow 2 stops"); Flow 1 hızla hızlanır ("Flow 1 speeds up quickly when Flow 2 stops").

<!-- BELİRSİZ: 01:26:29-01:29:56 ve 01:31:32-01:32:42 arasındaki anlatımın bir kısmı altyazıda bozuk. -->

## 8. Gönderim Hızının Ayarlanması

### 8.1 Akış denetimi ile tıkanıklık denetimi

Slayt: "Sender may need to slow down for different reasons: Flow control, when the receiver is not fast enough [right]; Congestion, when the network is not fast enough [over]" (ekrandan, 01:35:00). Şekilde bir musluk (transmission rate adjustment), bir huni ve bir iletim ağı (transmission network) ile küçük kapasiteli bir alıcı (small-capacity receiver) vardır. Slayt notu: "A fast network feeding a low-capacity receiver → flow control is needed". Hızlı bir gönderici varsa ama karşı taraftaki alıcı düşük kapasiteliyse akış denetimi yapılmalıdır.

Bir sonraki slaytta ise alıcının kapasitesinde hiçbir sorun yoktur; sorun ağdadır ve burada tıkanıklık denetimi uygulanmalıdır. İki slayt çok benzer görünür ama hangi durumda akış denetimi, hangi durumda tıkanıklık denetimi gerektiğini çok iyi temsil eder. Asıl yoğunlaşılacak konu tıkanıklıktır.

### 8.2 Açık ve örtük, kesin ve kesin olmayan sinyaller

Tıkanıklık ağdan, akış denetimi ihtiyacı alıcıdan kaynaklansa da ikisinin sonucunda gönderim hızı ayarlanmalıdır. Bu iki biçimde yapılabilir:

- Açık (explicit): göndericiye doğrudan "yavaşla" (ya da "hızlan") denir; bunun için ayrı bir şey gönderilebilir.
- Örtük (implicit): göndericinin bunu kendisinin ölçmesi beklenir. Gönderici bilginin gidip gelme süresine (round trip time) bakar; süre artıyorsa ağda bir sorun olduğunu düşünüp yavaşlar, düşüyorsa biraz hızlanır.

Açık bildirim yapılırken de iki seçenek vardır: yalnız "yavaşla" demek kesin (precise) değildir; "hızını 2 Mbps'e indir" demek ise kesindir.

Slayt: "Different congestion signals the network may use to tell the transport endpoint to slow down (or speed up)" (ekrandan, 01:40:00):

| Protocol | Signal | Explicit? | Precise? |
|---|---|---|---|
| XCP | Rate to use | Yes | Yes |
| TCP with ECN | Congestion warning | Yes | No |
| FAST TCP | End-to-end delay | No | Yes |
| CUBIC TCP | Packet loss | No | No |
| TCP | Packet loss | No | No |

- XCP (eXplicit Congestion Protocol): göndericiye ne yapması gerektiğini birebir söyler.
- ECN (Explicit Congestion Notification): kısaltması ilginç biçimde benzer, ama bu bir protokol değil bir bildirimdir ve TCP ile birlikte kullanılır. Yönlendiriciler paketleri işaretleyerek göndericiye yavaşlaması gerektiğini söyler. Bunu açıkça, bir bayrakla söyler ama miktar belirtmez; bu yüzden kesin değildir.
- FAST TCP: örtük bir tasarımdır; gidiş-dönüş gecikmelerini ölçer ve tıkanıklığı önlemek için kullanır.
- TCP: daha önce IP katmanında da konuşulduğu gibi doğrudan yalnız paket kaybına bakar.

Paket kaybı için ayrıca "bu paket kayboldu" diye bildirim göndermenin bir anlamı yoktur; bu yangına benzin ya da mazot dökmek gibidir: paketler kaybolurken ağa bir de bildirim için ek paket verilmiş olur. Bu yüzden TCP bunu kullanmaz.

<!-- BELİRSİZ: 01:41:01-01:41:43 arasında CUBIC TCP'nin anlatımı (altyazıda "Drop Tail ve Red" geçiyor) bozuk; tablodaki değerler slayttan alındı. -->

### 8.3 Toplamsal ve çarpımsal artırma-azaltma

Slayt: "If two flows increase/decrease their bandwidth in the same way when the network signals free/busy they will not converge to a fair allocation" (ekrandan, 01:45:00). Grafikte yatay eksen User 1's bandwidth, dikey eksen User 2's bandwidth (0-100%) vardır:

- Fairness line (adalet doğrusu): orijinden geçen, iki kullanıcının eşit pay aldığı köşegen.
- Efficiency line (verimlilik doğrusu): iki eksende %100 noktalarını birleştiren, toplam kullanımın %100 olduğu doğru.
- Optimal point: iki doğrunun kesiştiği nokta.
- Additive increase and decrease (+/- constant): nokta 45 derecelik bir doğru boyunca ileri geri gider.
- Multiplicative increase and decrease (+/- percentage): nokta orijinden geçen bir doğru boyunca ileri geri gider.

Anlatımda önce tek bir akışın hattı kullandığı, sonra ikinci akışın geldiği ve iki akışın ortada, 0.5 noktasında birleştiği hatırlatıldı; iki doğrunun kesiştiği nokta en uygun noktadır. Hoca kontrol sistemlerinden de bir benzetme yaptı: bir motorun dönüş hızı ya da bir açının ayarlanması gibi süreç denetiminde de değer önce olması gereken yere hızla yaklaştırılır, sonra ince ayar yapılır.

Diğer hoca bunun bir güzelliğini daha ekledi: artırma toplamsal (additive) yapılır, azaltma ise çok hızlı yapılır. Artırma çarpımsal yapılırsa bir anda tıkanıklık oluşturulabilir; toplamsal yapılırsa daha kontrollü gidilir. Böylece artırma sırasında bir bakıma tıkanıklıktan kaçınma (congestion avoidance) da yapılmış olur.

<!-- BELİRSİZ: 01:43:37-01:47:31 arasında altyazı büyük ölçüde bozuk; iki akışın grafikte nasıl hareket ettiğinin sözlü anlatımı çıkarılamadı. -->

> **Ek bilgi (derste anlatılmadı):** Tanenbaum'un anlattığı sonuç büyük olasılıkla şudur: yalnız toplamsal ya da yalnız çarpımsal artırma-azaltma adil noktaya yakınsamaz; toplamsal artırma ile çarpımsal azaltmanın birleşimi (AIMD) ise hem verimlilik hem adalet doğrusunun kesişimine doğru salınarak yakınsar. TCP büyük olasılıkla bu AIMD kuralını kullanır.

Son olarak TCP/IP daha yakından incelenirken TCP'nin ana sürümlerinin ABD'deki yer adlarıyla anıldığı söylendi. <!-- BELİRSİZ: 01:48:58'de sürüm adları altyazıda "LEMO" ve "TAHV" olarak geçiyor; büyük olasılıkla Reno ve Tahoe kastediliyor. --> Ders, UDP konusunun başında bitti (ekrandan, 01:50:00); bir sonraki slaytta UDP'ye giriş, uzak yordam çağrısı (Remote Procedure Call) ve gerçek zamanlı taşıma (Real-Time Transport) başlıkları vardı.

## Örnek Sorular

**Soru 1 (derste sözlü, 00:25:34):** Bağlantı sonlandırmada Host 1 ve Host 2'nin başlattığı zamanlayıcıların değeri neyi garanti edecek kadar uzun seçilmelidir?

> **Cevap (derste verildi):** Zamanlayıcılar yalnız DR'nin belirli bir sürede karşı tarafa gitmesini ve cevap üretilmesini sağlamakla kalmamalı, ağ katmanında farklı yollardan, farklı gecikmelerle hâlâ aktarılmakta olan paketlerin de hedefe ulaşmasını garanti edecek kadar uzun olmalıdır. Amaç hiçbir paketin kaybolmamasıdır.

**Soru 2 (derste sözlü, 00:35:58):** Slayttaki üç hata senaryosundan daha kötü olabilecek bir durum aklınıza geliyor mu?

> **Cevap (derste verildi):** Slayttaki senaryoların hepsinde ilk DR'nin karşıya temiz biçimde ulaştığı varsayılır. Host 1'in ilk DR'si tekrar tekrar kaybolursa Host 1, N zaman aşımından sonra pes edip bağlantıyı kapatır, ama Host 2'nin bundan hiç haberi olmaz. Bu yüzden keep-alive gibi etkinlik denetimleri kullanılır.

**Soru 3 (derste sözlü, 00:39:23):** Hata denetimi ve akış denetimi veri bağı katmanında zaten yapılıyorsa taşıma katmanında neden bir daha yapılır?

> **Cevap (derste verildi):** Veri bağı katmanındaki denetim tek atlamada (iki düğüm arasında) yapılır. Bir paket yoldaki bir düğümün tamponunda bozulursa, ya da hata düzeltme kodunun kapasitesini aşan bir hata sağlamayı yine tutturursa, hata sonraki atlamalardan fark edilmeden geçer; bu yüzden uçtan uca kontrol gerekir. Akış denetiminde de taşıma katmanı çok atlamalı yolu, aynı host üzerindeki birden çok süreci ve arayüzü, farklı yerlerden birleşen trafiği hesaba katmalıdır.

**Soru 4 (derste sözlü, 01:02:23):** Akış denetimi örneğinin 16. satırında B'den çıkan "ack = 6, buf = 4" mesajı A'ya ulaşmazsa ne olur?

> **Cevap (derste verildi):** Önerilen haliyle bu protokolde A bloklu kalmaya devam eder; B de A'dan bir şey alamadığı için bekler. Bu potansiyel bir kilitlenmedir (deadlock). Çözüm, zaman aşımından sonra ya da periyodik olarak bu kontrol mesajının yeniden gönderilmesidir.

## Dersin Toparlaması

Bu derste taşıma katmanının bağlantı yönetimi ve güvenilirlik mekanizmaları tamamlandı. Bağlantı sonlandırmada asimetrik sonlandırmanın veri kaybettirebildiği, simetrik sonlandırmanın ise iki ordu problemi yüzünden tek başına taşıma katmanında çözülemediği görüldü; pratikte DR, zamanlayıcı ve yeniden gönderimle çalışan üç mesajlı bir sonlandırma kullanılır. Hata ve akış denetiminin veri bağı katmanında tek atlamada yapılmasına rağmen taşıma katmanında uçtan uca tekrar yapılması gerektiği, tampon stratejileri ve onay mesajına tampon bilgisi eklenerek değişken boyutlu pencere elde edilmesi işlendi. Çoğullama ve ters çoğullama, çökmeden kurtarmada ACK ve yazmanın atomik olmaması ve sorunun bir üst katmanda çözülmesi gerektiği konuşuldu.

Dersin son bölümünde tıkanıklık denetimine geçildi: verimli ve adil bant genişliği paylaşımı (max-min adalet), trafik değiştiğinde hızlı yakınsama, açık-örtük ve kesin-kesin olmayan tıkanıklık sinyalleri ve toplamsal-çarpımsal artırma-azaltma. Bir sonraki derste UDP, RTP ve TCP gibi gerçek hayatta kullanılan protokollere geçilecek ve burada teorik olarak konuşulan mekanizmaların bu protokollerdeki karşılıkları görülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
