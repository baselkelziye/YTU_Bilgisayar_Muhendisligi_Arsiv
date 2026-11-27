# Ders 20 Çalışma Özeti

## Genel Konular

- Bağlantının sonlandırılması (connection release) (ekrandan, 00:15:00)
  - Taşıma katmanı bağlantı yönelimli çalıştığı için, alttaki ağ katmanı paket kaybetse, geciktirse ya da çoğaltsa bile bağlantı kapanırken son paket dahil hiçbir veri kaybolmamalıdır.
  - Çift yönlü (duplex) iletişim aslında iki tek yönlü (simplex) akıştan oluşur. A tarafı kapatmak istediğinde B'den A'ya akış hâlâ sürebilir; bu yüzden kapatmayı hangi taraf başlatırsa başlatsın diğer taraf haberdar olmalı, göndermeyi kesmeli ve ağda hâlâ yolda olan paketlerin varması beklenmelidir.
  - Asimetrik sonlandırma (asymmetric release): bir taraf bağlantıyı tek başına koparır. Slayttaki örnekte Host 1 CR gönderir, Host 2 ACK ile cevap verir, Host 1 iki DATA gönderir; ikinci DATA yoldayken Host 2 DR (Disconnect Request) gönderir. DR'den sonra gelen veri teslim edilmez ("No data are delivered after a disconnect request"). Slaytın ifadesiyle bu yöntem ani (abrupt) olduğu için veri kaybettirebilir.
  - Simetrik sonlandırma (symmetric release): iki tarafın birlikte kapatmaya karar vermesi. Slayta göre bu, tek başına taşıma katmanı tarafından çözülemez (ekrandan, 00:20:00).
  - İki ordu problemi (two-army problem): vadideki beyaz ordu (3 asker) her iki tepedeki mavi ordulardan (2'şer asker) tek tek daha güçlüdür; mavi ordular ancak aynı anda saldırırsa kazanır. Eşzamanlama için gönderilen ulak vadiden geçerken yakalanabilir; bu yüzden kesin bir anlaşmaya varılamaz. Ağ katmanı da paketleri bilerek değil ama fiilen kaybederek aynı belirsizliği yaratır.
  - Normal sonlandırma sırası (ekrandan, 00:25:00): Host 1 DR gönderir ve zamanlayıcı başlatır; Host 2 DR ile cevap verir ve kendi zamanlayıcısını başlatır; Host 1 bağlantıyı bırakır ve ACK gönderir; Host 2 ACK gelince bağlantıyı bırakır. İki DR de karşı tarafça onaylanır. Yine üç mesajla biter.
  - Hata durumları zamanlayıcı ve yeniden gönderimle çözülür (ekrandan, 00:30:00):
    - Son ACK kaybolur: Host 2 zaman aşımına uğrar ve bağlantıyı bırakır.
    - Host 2'nin DR'si kaybolur: Host 1 zaman aşımından sonra DR'yi yeniden gönderir, akış normal biter.
    - Uç durum: o kadar çok DR kaybolur ki Host 1 N zaman aşımından sonra, Host 2 de kendi zaman aşımından sonra bağlantıyı bırakır.
  - Daha kötü bir senaryo (derste sözlü eklendi): Host 1'in ilk DR'si tekrar tekrar kaybolursa Host 1 N denemeden sonra pes edip kapatır; Host 2'nin bundan hiç haberi olmaz. Bunun için etkinlik kontrolü (keep-alive) gibi mekanizmalar kullanılır.
- Hata denetimi ve akış denetimi (error control, flow control) (ekrandan, 00:40:00)
  - Hata denetimi: verinin istenen güvenilirlikte, yani baştan sona özgün haliyle aktarılması. Akış denetimi: hızlı bir göndericinin yavaş bir alıcıyı ezmesini engellemek.
  - Slayta göre hata denetiminin temeli, veri bağı katmanından gelen, sağlama toplamı (checksum) ve yeniden gönderimle çalışan kayan penceredir (sliding window).
  - Veri bağı katmanında hata algılama kodu, ARQ, stop-and-wait ve sliding window zaten vardır; taşıma katmanında tekrar yapılmasının nedeni bunların yalnız tek atlama (hop) üzerinde çalışmasıdır.
  - Bir paket bir yönlendiricinin tamponunda beklerken bozulursa, bozulmuş hali sonraki atlamalarda sorunsuz geçer; bu yüzden uçtan uca ayrıca kontrol gerekir.
  - Akış denetimi de çok atlamalıdır; bir host üzerinde aynı anda birden çok uygulama ve birden çok arayüz olabilir, bir bağlantıya farklı yerlerden gelen trafikler birleşir.
  - Slayttaki akış denetimi maddeleri: akış denetimi gönderici ve alıcıdaki tamponlamayı yönetir; veri ağa ve uygulamaya farklı zamanlarda gider ya da gelir; pencere, göndericiye alıcıdaki boş tampon miktarını söyler; sonuç değişken boyutlu bir kayan penceredir.
- Tampon stratejileri (ekrandan, 00:50:00)
  - a) Zincirlenmiş sabit boyutlu tamponlar: önceden belirlenmiş boyutta tamponlar ihtiyaç oldukça ayrılır ve bağlı liste ile tutulur. Küçük paketlerde tamponun bir kısmı boş kalır.
  - b) Zincirlenmiş değişken boyutlu tamponlar: her parça için ona göre tampon ayrılır; yine de kullanılmayan alan (unused space) kalabilir.
  - c) Tek büyük dairesel tampon (circular buffer): TPDU'lar art arda yazılır, parçalanma olmaz; ancak bütün bellek baştan ayrılmalıdır. Bağlantı yoğun kullanılmıyorsa verimsizdir.
  - Düşük trafikte dinamik ayırma ve bırakma sorun değildir; yüksek trafikte sürekli heap ayırma, boş alanların toparlanması (sıkıştırma, garbage collection) maliyeti yüzünden verimsizleşir.
- Akış denetimi örneği: A'nın verisi B'nin tamponuyla sınırlıdır (ekrandan, 01:00:00)
  - 16 adımlık mesaj dizisi: A 8 tampon ister, B yalnız 0-3 mesajlarına izin verir; 2 numaralı mesaj kaybolur; A zaman aşımıyla 2'yi yeniden gönderir; B tampon açtıkça A yeni mesaj gönderir; son adımda B'nin yeni tampon bildiren ACK'i kaybolursa olası kilitlenme (deadlock) oluşur.
  - Kilitlenmeye çözüm: zaman aşımı ya da ACK/kontrol mesajının periyodik yeniden gönderilmesi.
  - ACK yalnız onay değil, alıcının bir sonraki turda kaç mesaj kabul edebileceğini de taşır; böylece pencere boyutu değişir.
- Çoğullama (multiplexing) (ekrandan, 01:05:00)
  - Çoğullama: birden çok taşıma bağlantısı tek bir ağ adresini paylaşır (port mekanizması).
  - Ters çoğullama (inverse multiplexing): bir bağlantı birden çok ağ adresini ya da arayüzü paylaşır. Amaç hem yedeklilik (failover) hem kapasiteyi artırmaktır.
  - Daha alt katmanda bunun karşılığı Link Aggregation Control Protocol'dür (LACP); bu, Ethernet'te MAC alt katmanının parçasıdır.
- Çökmeden kurtarma (crash recovery) (ekrandan, 01:10:00)
  - Yönlendirici çökerse hostlardaki taşıma varlıkları yeniden göndererek durumu kurtarır. Asıl sorun hostlardan birinin çökmesidir.
  - Stop-and-wait kullanan bir dosya sunucusunda "önce ACK, sonra yaz" sırasında çökme veri kaybına; "önce yaz, sonra ACK" sırasında çökme çift kayda (duplicate) yol açabilir. Slayttaki tabloda hiçbir gönderici ve alıcı stratejisi bileşimi her durumda doğru çalışmaz.
  - Genel ilke: N. katmandaki bir çökme ya da sorun ancak N+1. katmanda çözülebilir; uygulama kurtarmaya yardım etmelidir.
  - Eş güçlü (idempotent) işlemler tekrarlansa da tutarlılığı bozmaz; para çekme gibi işlemler ise tekrarlanınca ya da kaybolunca zarar verir.
- Tıkanıklık denetimi (congestion control) (ekrandan, 01:15:00)
  - Taşıma katmanı sunulan yükü (offered load) denetler, ağ katmanı tıkanıklığı yaşar.
  - Verimli bant genişliği kullanımı yüksek goodput ve düşük gecikme verir; tıkanıklık başlayınca goodput yükten yavaş artar, tıkanıklık çöküşünde (congestion collapse) düşer; gecikme ise keskin biçimde yükselir (ekrandan, 01:20:00).
  - Adil kullanım ve max-min adalet (ekrandan, 01:25:00): darboğaz bağlantısını paylaşan akışlar eşit pay alır; bir akışın payı başka bir akışın payı düşürülmeden artırılamaz.
  - Trafik desenleri değiştiğinde bant genişliği payları hızlı yakınsamalıdır (ekrandan, 01:30:00).
- Gönderim hızının ayarlanması (ekrandan, 01:35:00)
  - Göndericinin yavaşlaması iki nedenle gerekir: alıcı yavaşsa akış denetimi, ağ yetersizse tıkanıklık denetimi.
  - Sinyal açık (explicit) ya da örtük (implicit), kesin (precise) ya da kesin olmayan (imprecise) olabilir.
  - Protokol tablosu (ekrandan, 01:40:00): XCP, TCP with ECN, FAST TCP, CUBIC TCP, TCP.
  - Toplamsal ya da çarpımsal artırma ve azaltma (ekrandan, 01:45:00): iki akış aynı biçimde artırıp azaltırsa adil paylaşıma yakınsamaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağlantı sonlandırma için "three-way handshake" denmemesi
  - Sonlandırma da üç mesajla yapılır, ama "three-way handshake" terimi bağlantı kurmaya ait olduğu için sonlandırmada kullanılması yanlış sayılır.
- Zamanlayıcı değeri
  - Zamanlayıcılar yalnız DR'nin karşıya gidip cevap gelmesini değil, ağda farklı yollardan ve gecikmelerle hâlâ gelmekte olan paketlerin de hedefe varmasını garanti edecek kadar uzun seçilmelidir.
- Uçtan uca kontrolün gerekliliği
  - Veri bağı katmanındaki kontrol tek atlamaya bakar; çok atlamalı yolda uçtan uca kontrol taşıma katmanında yapılmalıdır. Hoca bunun hiçbir zaman atlanmaması gereken bir nokta olduğunu söyledi.
- ACK numarasının anlamı
  - Slayttaki örnekte "ack = 1", 1 dahil her şeyin alındığını gösterir. Gerçek protokollerde (TCP) ACK bir sonraki beklenen sıra numarasıdır; aynı durumda ACK 2 olurdu. Hoca bunun her yıl kafa karıştırdığını söyledi.
- Bir katmanın sorunu o katmanda çözülemez
  - Simetrik sonlandırmada da çökmeden kurtarmada da çözüm bir üst katmana bırakılır.
- Akış denetimi ile tıkanıklık denetimi farkı
  - Benzer görünen iki slayt hangi durumda akış denetimi (alıcının kapasitesi yetersiz), hangi durumda tıkanıklık denetimi (ağın kapasitesi yetersiz) gerektiğini gösterir.

## Kısa Tekrar Notları

- Asimetrik sonlandırma ani olduğu için veri kaybettirebilir; simetrik sonlandırma iki ordu problemi yüzünden tek başına taşıma katmanında çözülemez.
- Normal sonlandırma: DR + zamanlayıcı, DR + zamanlayıcı, ACK.
- Son ACK kaybolursa karşı taraf zaman aşımıyla kapatır; DR kaybolursa zaman aşımı sonrası yeniden gönderilir; N denemeden sonra pes edilir.
- Hata ve akış denetimi veri bağı katmanında hop bazında, taşıma katmanında uçtan uca yapılır.
- Tampon stratejileri: zincirli sabit boyut, zincirli değişken boyut, tek dairesel tampon.
- ACK'e tampon bilgisi eklenince değişken boyutlu pencere elde edilir; tampon açan ACK kaybolursa kilitlenme olabilir.
- Çoğullama: birçok bağlantı bir adres; ters çoğullama: bir bağlantı birçok adres.
- Çökmeden kurtarma: ACK ve yazma atomik değildir; uygulama katmanı yardım etmelidir.
- Max-min adalet: darboğazda eşit pay, kimse başkasını düşürmeden artamaz.
- XCP açık ve kesin; ECN açık ama kesin değil; FAST TCP örtük ama kesin; CUBIC TCP ve TCP paket kaybına bakar, ne açık ne kesin.

## Detaylı Açıklamalar

- Bağlantı sonlandırmanın zorluğu
  - Bağlantı kurmak kadar sonlandırmak da hassastır. Ağ katmanı çoğu zaman datagram modunda çalışır; paketler kaybolabilir, gecikebilir, çoğalabilir, farklı gecikmelerle gelebilir. Kâğıt üzerinde iki tarafın "aynı anda kapatalım" demesi mümkün görünse de, ağ bu eşzamanlamayı garanti etmez.
  - Asimetrik sonlandırma slaytında Host 2, Host 1'in ikinci DATA'sı yoldayken DR gönderir; o DATA artık teslim edilmez. Hoca bunu "abrupt" kelimesindeki kopma anlamıyla açıkladı: bağlantıyı kapatıp gerisini önemsememek kabul edilemez.
  - İki ordu problemi literatürde bu sorunun tipik örneğidir: iki mavi ordu ancak birlikte saldırırsa üstündür; aralarındaki her mesaj düşman bölgesinden geçtiği için son mesajın ulaştığından hiçbir taraf emin olamaz.
- Normal ve hatalı sonlandırma senaryoları
  - Normal akışta Host 1 DR gönderip zamanlayıcı başlatır; Host 2 kendi DR'si ile cevap verip zamanlayıcı başlatır; Host 1 bağlantıyı bırakıp son ACK'i gönderir; Host 2 ACK ile bağlantıyı bırakır.
  - Slayttaki üç hata durumu: son ACK kaybolursa Host 2 zaman aşımıyla bırakır; Host 2'nin DR'si kaybolursa Host 1 zaman aşımından sonra DR'yi yeniden gönderir; çok sayıda DR kaybolursa Host 1 N zaman aşımından, Host 2 kendi zaman aşımından sonra bağlantıyı bırakır.
  - Derste eklenen daha kötü durum: ilk DR hiç ulaşmazsa Host 1 N denemeden sonra kapatır, Host 2 bağlantının hâlâ açık olduğunu sanır. Bu yüzden keep-alive gibi etkinlik denetimleri kullanılır.
- Neden hem veri bağı hem taşıma katmanında denetim?
  - Veri bağı katmanındaki hata düzeltme belli sayıda hataya göre tasarlanır. Tasarlanandan fazla hata olur ve sağlama yine tutarsa paket hatalı haliyle sonraki atlamaya geçer. Hoca, bu konuda Saltzer'in 1984 tarihli uçtan uca (end-to-end) çalışmasını kaynak gösterdi.
  - Akış denetiminde de veri bağı katmanı yalnız tek bir hattın hızını denetler; taşıma katmanı ise çok atlamalı yolu, aynı host üzerindeki birden fazla süreci ve arayüzü, farklı yerlerden birleşen trafiği hesaba katmalıdır.
- Tampon yönetimi
  - Sabit boyutlu zincirli tamponlar işletim sistemindeki thread havuzuna benzetildi: boyut önceden belirlenir, her paket gelince o boyutta yer ayrılır, bağlı liste hızlı ekleme sağlar. Küçük paketlerde iç parçalanma olur.
  - Değişken boyutlu tamponlar bu kaybı azaltır ama tamamen önlemez. Dairesel tampon parçalanma yaratmaz ama bütün belleği önceden ayırmayı gerektirir; bağlantı sonuna kadar kullanılıyorsa kullanılmayan alan küçülür ve bellek kullanımı verimli olur.
  - <!-- BELİRSİZ: 00:53:45-00:56:18 arasında yüksek trafikte bellek ayırmanın maliyeti ve tamponların "chunk" (öbek) halinde ayrılması önerisi anlatılıyor; altyazı büyük ölçüde bozuk. -->
- Akış denetimi örneği
  - A 8 tampon ister; B "ack = 15, buf = 4" ile yalnız 0-3 mesajlarına izin verir. A m0, m1, m2'yi gönderir; m2 kaybolur ama A bir kredisi kaldığını düşünür. B "ack = 1, buf = 3" ile 0 ve 1'i onaylar ve 2-4'e izin verir. A m3 ve m4'ü gönderir, krediyi bitirir; zaman aşımıyla m2'yi yeniden gönderir. B önce "ack = 4, buf = 0" ile her şeyi onaylar ama A'yı bekletir, sonra "buf = 1" ve "buf = 2" ile yer açar. A m5 ve m6'yı gönderip tekrar bloklanır. B "ack = 6, buf = 0" sonra "ack = 6, buf = 4" gönderir; bu son mesaj kaybolursa iki taraf da birbirini bekler.
- Çökmeden kurtarma
  - "Önce ACK sonra yaz" sırasında ACK gönderilip yazmadan çökülürse gönderici paketin yazıldığını sanır, veri kaybolur. "Önce yaz sonra ACK" sırasında yazıp ACK göndermeden çökülürse gönderici paketi yeniden gönderir, çift kayıt oluşur.
  - Para çekme örneği: 500 liralık işlem çift işlenirse hesaptan 1000 lira düşebilir; kaybolursa para çekildiği halde hesapta görünmeyebilir. Eş güçlü olmayan işlemlerde ne kayıp ne çift kayıt kabul edilebilir.
- Bant genişliği paylaşımı ve gönderim hızı
  - Max-min adaletin sağlanması için ya ağın tamamı (hangi akış nereden geçiyor) bilinmeli ya da her akışın payı adım adım artırılıp, artışın başkasını etkileyeceği noktada durdurulmalı ve kalan kapasite diğerlerine paylaştırılmalıdır.
  - Trafik sürekli değişir: isteğe bağlı video, görüntülü ve sesli görüşme, video konferans, indirim günlerinde ya da sınav sonucu açıklandığında birden artan trafik. Hoca bunu devre dersindeki impuls örneğine benzetti: dengedeki bir sisteme ani bir darbe uygulanınca sistemin yeniden dengeye oturması zaman alır.
  - Açık sinyalde göndericiye doğrudan "yavaşla" denir; örtük sinyalde gönderici RTT gibi ölçümlerden kendisi çıkarım yapar. Açık sinyal yalnız "yavaşla" diyorsa kesin değildir; "2 Mbps'e in" diyorsa kesindir.
  - XCP göndericiye kullanacağı hızı söyler. ECN'de yönlendiriciler paketleri işaretleyerek göndericiye yavaşlamasını söyler ama miktar belirtmez. FAST TCP uçtan uca gecikmeyi ölçen örtük bir tasarımdır. TCP yalnız paket kaybına bakar; tıkanıklık sırasında ağa ek bildirim paketi göndermek yangına benzin dökmek gibi olacağı için ayrı bir kayıp bildirimi kullanılmaz.
  - Toplamsal artırma ve hızlı (çarpımsal) azaltma: artırma çarpımsal yapılırsa birden tıkanıklık yaratılabilir; toplamsal artırma daha kontrollüdür ve bir tür tıkanıklıktan kaçınma (congestion avoidance) işlevi görür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
