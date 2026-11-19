# Ders 10 Çalışma Özeti

## Genel Konular

- Ağ katmanına giriş ve iki bölümlü yapı
  - Uygulama ve taşıma katmanından sonra ağ katmanına geçildi. Ağ katmanı ağın çekirdeğidir; internet "ağların ağı" olduğundan her cihaz (uç cihazlar ve yönlendiriciler) bu katmanda çalışmak zorundadır.
  - Konu çok geniş olduğu için iki bölüme ayrılır: veri düzlemi (data plane) ve kontrol düzlemi (control plane). Bu derste veri düzlemi ve IP işlendi.
  - Gönderici taşıma katmanı segmentlerini datagramlara kapsüller; alıcı segmentleri taşıma katmanına teslim eder, taşıma katmanı port numarasına göre ilgili uygulamaya iletir. Gönderici ile alıcı arasında doğrudan bağlantı yoktur.
  - Yönlendirici, içinden geçen her IP datagramının başlık alanlarını inceler ve datagramı giriş portundan uygun çıkış portuna taşır (ekrandan, 00:15:00).
- Ağ katmanının iki temel işlevi: iletme ve yönlendirme
  - İletme (forwarding): paketi tek bir yönlendiricinin giriş bağlantısından aynı yönlendiricinin uygun çıkış bağlantısına taşımak. Yereldir, her yönlendiricide olur.
  - Yönlendirme (routing): paketin kaynaktan hedefe izleyeceği yolu belirlemek. Bunun için yönlendirme algoritmaları gerekir (ekrandan, 00:20:00).
  - Benzetme: İstanbul'dan Erzurum'a yolculukta yolun tamamını planlamak (navigasyon) yönlendirmedir; yol üzerindeki her şehirde kavşak ve dönel kavşaklardan doğru çıkışı almak iletmedir.
- Veri düzlemi ve kontrol düzlemi
  - Veri düzlemi yerel, yönlendirici başına bir işlevdir: gelen datagramın başlık değerine bakılır ve yerel iletme tablosuna göre çıkış portu seçilir.
  - Kontrol düzlemi ağ genelinde bir mantıktır: datagramın uçtan uca yolda yönlendiriciler arasında nasıl yönlendirileceğini belirler.
  - İki kontrol düzlemi yaklaşımı vardır: geleneksel yönlendirme algoritmaları (yönlendiricilerin içinde çalışır) ve yazılım tanımlı ağ, SDN (uzak sunucularda çalışır).
- Yönlendirici başına kontrol düzlemi ve SDN
  - Geleneksel yaklaşımda her yönlendiricide yönlendirme algoritması çalışır; yönlendiriciler birbirleriyle mesajlaşarak yerel iletme tablolarını günceller (ekrandan, 00:25:00).
  - Slayttaki örnek yerel iletme tablosu: başlık `0100` → port 3, `0110` → port 2, `0111` → port 2, `1001` → port 1. Başlığı `0111` olan paket port 2'ye iletilir (ekrandan, 00:25:00).
  - SDN'de yönlendiricilerde yönlendirme algoritması çalışmaz. Üstte uzak bir denetleyici (remote controller) vardır; her yönlendiricideki kontrol ajanı (control agent) denetleyiciyle konuşarak iletme tablosunu günceller.
- Ağ katmanı hizmet modeli
  - Düşünülebilecek hizmetler: garantili teslim, belirli bir gecikmenin altında garantili teslim, sıralı teslim, akış başına garantili en düşük bant genişliği, paketler arası aralıktaki değişimin sınırlanması.
  - İnternetin ağ katmanı "en iyi çaba" (best effort) hizmetidir: teslim, zamanlama, sıra ve bant genişliği için hiçbir garanti yoktur.
  - Karşılaştırma tablosu (ekrandan, 00:30:00): İnternet best effort (bant genişliği yok, kayıp/sıra/zamanlama garantisi yok); ATM CBR (sabit hız, kayıp/sıra/zamanlama evet); ATM ABR (garantili en düşük hız, kayıp hayır, sıra evet, zamanlama hayır); Intserv Guaranteed, RFC 1633 (hepsi evet); Diffserv, RFC 2475 (bant genişliği "mümkün", kayıp ve sıra "olası", zamanlama hayır).
  - Bu ileri modeller yaygınlaşmadı; hâlâ best effort kullanılıyor. Basitliği, yeterli bant genişliği sağlanınca gerçek zamanlı uygulamaların başarımının "yeterince iyi" olması ve tıkanıklık denetiminin yardımı nedeniyle best effort modelinin başarısı tartışılmaz.
- Yönlendirici mimarisi
  - Bileşenler: N giriş portu, N çıkış portu, aradaki yüksek hızlı anahtarlama dokusu (switching fabric) ve yönlendirme işlemcisi (ekrandan, 00:35:00).
  - İletme/veri düzlemi donanımdır ve nanosaniye mertebesinde çalışır; yönlendirme/yönetim/kontrol düzlemi yazılımdır ve milisaniye mertebesinde çalışır.
- Giriş portu işlevleri
  - Hat sonlandırma (fiziksel katman, bit düzeyi), bağlantı katmanı protokolü (ör. Ethernet, 6. bölümde işlenecek), ardından ağ katmanında arama (lookup), iletme ve kuyruklama.
  - Merkezi olmayan anahtarlama: başlık alanı değeri ve arama tablosuyla çıkış portu bulunur ("eşleştir + eylem", match plus action). Amaç giriş portu işlemini hat hızında (line speed) yapmaktır.
  - Datagramlar anahtarlama dokusuna iletilebilecek hızdan daha hızlı gelirse giriş portunda kuyruğa alınır.
  - Hedefe dayalı iletme (destination-based forwarding) yalnız hedef IP adresine bakar; genelleştirilmiş iletme (generalized forwarding) herhangi bir başlık alanı değerine bakabilir.
- Hedefe dayalı iletme ve en uzun önek eşleştirme
  - Slayttaki iletme tablosu adres aralıklarını arayüzlere eşler (ekrandan, 00:40:00): aralıklar 0, 1, 2 numaralı arayüzlere, geri kalanı 3'e gider. Aralığı daha ince bölmek istenince (ör. arayüz 0 aralığının içinden küçük bir aralığı arayüz 3'e ayırmak) aralık tablosu yönetilemez hale gelir.
  - Çözüm en uzun önek eşleştirmedir (longest prefix matching): verilen hedef adres için iletme tablosunda adresle eşleşen en uzun önek kullanılır (ekrandan, 00:45:00).
  - Derste iki örnek çözüldü: ilk adres yalnız bir girdiyle eşleşir ve arayüz 0'a gider; ikinci adres iki girdiyle eşleşir, daha uzun olan (24 bitlik) seçilir ve arayüz 1'e gider. <!-- BELİRSİZ: örnek tablonun bit değerleri karelerde görünmüyor; önek uzunlukları altyazıdan (21, 24, 21) alındı. -->
  - En uzun önek eşleştirme genellikle TCAM (ternary content addressable memory) donanımıyla yapılır; arama tek saat çevriminde tamamlanır. Hoca, Cisco Catalyst yönlendiricilerinde TCAM'de yaklaşık 1 milyon yönlendirme tablosu girdisi bulunabildiğini söyledi.
- Anahtarlama dokusu
  - Paketi giriş bağlantısından uygun çıkış bağlantısına taşır. Anahtarlama hızı, giriş/çıkış hat hızının katı olarak verilir; N giriş için N kat hat hızı istenir.
  - Üç tür: bellek üzerinden, veri yolu (bus) üzerinden, ara bağlantı ağı (interconnection network) üzerinden.
  - Bellek: birinci kuşak yönlendiriciler; CPU denetiminde geleneksel bilgisayarlar. Paket sistem belleğine kopyalanır; hız bellek bant genişliğiyle sınırlıdır (datagram başına 2 veri yolu geçişi) (ekrandan, 00:50:00).
  - Veri yolu: datagram giriş portu belleğinden çıkış portu belleğine paylaşılan veri yolu ile gider. Ana sorun veri yolu çekişmesidir (bus contention); hız veri yolu bant genişliğiyle sınırlıdır. 32 Gbps'lik veri yolu erişim yönlendiricileri için yeterlidir. <!-- BELİRSİZ: hocanın andığı Cisco model numarası altyazıda bozuk ("Cisco 500,600", "Cisco 5000 series"). -->
  - Ara bağlantı ağı: çapraz çubuk (crossbar), Clos ağları; ilk olarak çok işlemcili sistemlerde işlemcileri bağlamak için geliştirildi. N×N tek bir crossbar yerine çok katlı anahtarlar kullanılarak paralellikten yararlanılır; paket parçalara bölünüp ara katlardan geçirilebilir.
  - Ölçekleme: birden çok anahtarlama düzlemi paralel kullanılır. Hoca, Cisco CRS yönlendiricisinde 8 anahtarlama düzlemi, her birinde 3 katlı ara bağlantı ağı bulunduğunu ve 100 Tbps mertebesinde anahtarlama kapasitesine ulaşıldığını söyledi.
- Giriş portu kuyruklaması ve HOL engellemesi
  - Anahtarlama dokusu giriş portlarından yavaşsa giriş kuyruklarında bekleme olur.
  - Çıkış portu çekişmesi: aynı anda yalnız bir kırmızı datagram kırmızı çıkışa aktarılabilir, diğer kırmızı datagram bekler. Kuyruğun önündeki datagramın beklemesi arkasındakileri de engeller: satır başı engellemesi (head-of-the-line blocking, HOL).
- Çıkış portu kuyruklaması
  - Anahtarlama dokusu datagramları çıkış bağlantısının iletim hızından daha hızlı getirirse tampon gerekir; boş tampon yoksa hangi datagramın atılacağına "atma politikası" (drop policy) karar verir (ekrandan, 00:55:00).
  - Tıkanıklıkta çıkış tamponu dolarsa gelen datagramlar kaybolur.
  - Zamanlama disiplini (scheduling discipline) kuyruktaki datagramlardan hangisinin gönderileceğini seçer; öncelik konusu burada önemlidir.
- Ne kadar tampon?
  - RFC 3439 temel kuralı: ortalama tampon = "tipik" RTT (ör. 250 ms) × bağlantı kapasitesi C. Örnek: C = 10 Gbps için 2,5 Gbit tampon (ekrandan, 01:15:00).
  - Daha yeni öneri: N akış için tampon $\dfrac{RTT \cdot C}{\sqrt{N}}$ (ekrandan, 01:15:00).
  - Çok fazla tampon gecikmeyi artırır (özellikle ev yönlendiricilerinde); uzun RTT gerçek zamanlı uygulamalarda kötü başarım ve ağır TCP tepkisi doğurur. Tampon "dolu olmalı ama aşırı dolu olmamalı".
- Tampon yönetimi
  - Tampon dolunca atma: kuyruk sonundan atma (tail drop: yeni gelen atılır) ya da önceliğe göre atma (en düşük öncelikli paket atılır).
  - İşaretleme: tıkanıklığı göndericiye ve alıcıya bildirmek için paketler işaretlenir (ECN gibi tıkanıklık bayrakları); bu sinyal paketleri en yüksek önceliği almalıdır.
- Paket zamanlaması
  - FCFS (ilk gelen ilk hizmet alır, FIFO): paketler çıkış portuna geliş sırasıyla gönderilir.
  - Öncelik: gelen trafik sınıflandırılır ve sınıfına göre kuyruğa konur; sınıflandırma için herhangi bir başlık alanı kullanılabilir. Tamponlanmış paketi olan en yüksek öncelikli kuyruktan gönderilir; sınıf içinde FCFS (ekrandan, 01:20:00).
  - Round robin: sınıf kuyrukları döngüsel olarak taranır, her sınıftan (varsa) bir tam paket gönderilir.
  - Ağırlıklı adil kuyruklama (WFQ): genelleştirilmiş round robin; her sınıfa ağırlık verilir. Her sınıfa en düşük bant genişliği garantisi sağlar.
- Ağ tarafsızlığı (network neutrality)
  - Teknik açıdan: bir ISP'nin kaynaklarını müşteriler arasında nasıl paylaştırması gerektiği; paket zamanlama ve tampon yönetimi gibi mekanizmalarla gerçeklenir.
  - Sosyal/ekonomik açıdan: herkesin ağa serbestçe erişmesi; ifade özgürlüğünü korur, yeniliği ve rekabeti teşvik eder. Ülkeden ülkeye farklı yasalar uygulanır.
  - 2015 ABD FCC "Order on Protecting and Promoting an Open Internet" üç kural koyar (ekrandan, 01:25:00): engelleme yok (no blocking), kısma yok (no throttling), ücretli önceliklendirme yok (no paid prioritization).
  - Belirsiz alan: ISP bir "telekomünikasyon hizmeti" sağlayıcısı mı yoksa "bilgi hizmeti" sağlayıcısı mı? Telekomünikasyon Yasası (1934 ve 1996) telekomünikasyon hizmetlerine "ortak taşıyıcı" (common carrier) yükümlülükleri getirir; bilgi hizmetlerinde bu yükümlülük yoktur.
- Ağ katmanı bileşenleri ve IPv4 datagram biçimi
  - Ağ katmanında yol seçme algoritmaları ve yönlendirme protokolleri (OSPF, BGP) ya da SDN denetleyicisi iletme tablosunu günceller; IP protokolü datagram biçimini, adreslemeyi ve paket işleme kurallarını tanımlar.
  - Alanlar (ekrandan, 01:30:00): sürüm (ver), başlık uzunluğu (bayt), hizmet türü (type of service), toplam uzunluk (bayt), 16 bitlik tanımlayıcı, bayraklar, parça ofseti (fragment offset), yaşam süresi (TTL), üst katman, başlık sağlama toplamı, 32 bitlik kaynak ve hedef IP adresi, seçenekler (varsa), yük verisi (genelde TCP ya da UDP segmenti).
  - Toplam uzunluk en fazla 64 KB, tipik olarak 1500 bayt ya da daha az (ekrandan, 01:30:00).
  - Hizmet türü bir bayttır: ilk 6 bit diferansiyel hizmet (0-5. bitler), son 2 bit tıkanıklık bildirimi (6-7. bitler).
  - TTL her yönlendiricide bir azaltılır; sıfıra ulaşınca paket atılır. Üst katman alanı TCP mi UDP mi olduğunu gösterir. Tanımlayıcı ve bayraklar mesajın birden çok datagrama bölünmesi ve alıcıda birleştirilmesi için kullanılır.
  - Ek yük: TCP başlığı 20 bayt + IP başlığı 20 bayt = 40 bayt + uygulama katmanı ek yükü.
- IPv4 adresleme ve alt ağlar
  - IP adresi 32 bitlik, her ana bilgisayar ya da yönlendirici **arayüzüne** verilen tanımlayıcıdır. Yönlendiricilerin genelde birden çok arayüzü vardır; ana bilgisayarlarda genelde bir ya da iki (kablolu Ethernet ve kablosuz) arayüz bulunur.
  - Noktalı ondalık gösterim: 32 bit, 8 bitlik dört parçaya bölünür (ör. 223.1.1.1).
  - Alt ağ (subnet): araya yönlendirici girmeden birbirine fiziksel olarak ulaşabilen cihaz arayüzleri. IP adresi alt ağ kısmı (yüksek mertebeli bitler, aynı alt ağda ortak) ve ana bilgisayar kısmından (kalan düşük mertebeli bitler) oluşur (ekrandan, 01:35:00).
  - Alt ağları bulma tarifi: her arayüzü ana bilgisayarından ya da yönlendiricisinden ayır; oluşan her yalıtılmış ada bir alt ağdır.
  - Slayttaki ağda 3 alt ağ vardır: 223.1.1.0/24 (223.1.1.1, .2, .3 ve yönlendirici arayüzü 223.1.1.4), 223.1.2.0/24 (223.1.2.1, 223.1.2.2, yönlendirici 223.1.2.9), 223.1.3.0/24 (223.1.3.1, 223.1.3.2, yönlendirici 223.1.3.27) (ekrandan, 01:35:00).
  - /24 alt ağ maskesidir: yüksek mertebeli 24 bit alt ağ kısmı, kalan 8 bit ana bilgisayar kısmıdır.
- CIDR
  - Sınıfsız alanlar arası yönlendirme (Classless InterDomain Routing): alt ağ kısmı herhangi bir uzunlukta olabilir. Adres biçimi a.b.c.d/x, x adresin alt ağ kısmındaki bit sayısıdır; ana bilgisayar kısmı ihtiyaca göre büyütülebilir.
- DHCP
  - Bir ana bilgisayar IP adresini ya sistem yöneticisinin elle yazdığı yapılandırmadan ya da DHCP ile dinamik olarak ("tak ve çalıştır") alır.
  - Amaç: ana bilgisayarın ağa katılırken sunucudan dinamik adres alması; kullanımdaki adresin kirasını yenileyebilmesi, adreslerin yeniden kullanılması ve mobil kullanıcıların ağa girip çıkabilmesi.
  - Dört mesaj: DHCP discover, DHCP offer, DHCP request, DHCP ACK.
  - Senaryoda DHCP sunucusu 223.1.2.5'tir (ekrandan, 01:40:00). İstemci 68 numaralı portu, sunucu 67 numaralı portu kullanır.
  - Discover: kaynak 0.0.0.0 (istemcinin henüz adresi yok), hedef yayın (broadcast), yiaddr 0.0.0.0, bir işlem kimliği (transaction ID). Offer: kaynak sunucu adresi, port 67, hedef yayın, yiaddr önerilen adres (örnekte 223.1.2.4), aynı işlem kimliği ve adresin geçerlilik süresi (lifetime).
  - Request: istemci kullanmak istediği adresi ve süreyi bildirir; hedef yine yayın. ACK: sunucu onaylar; yiaddr aynı adres, aynı işlem kimliği ve süre.
  - DHCP yalnız IP adresi vermez: ilk atlama yönlendiricisinin (ağ geçidi) adresi, DNS sunucusunun adı ve adresi ve ağ maskesi de döner.
  - Örnek: yönlendiriciye gömülü DHCP sunucusu; dizüstü bilgisayarın DHCP isteği UDP'ye, IP'ye ve Ethernet'e kapsüllenerek gönderilir (ekrandan, 01:45:00).
- Hiyerarşik adresleme ve adres bloğu alma
  - Bir ISP'nin /20'lik bloğu varsa ana bilgisayar kısmı 12 bittir, yani $2^{12}$ adres vardır. ISP 3 bit daha ayırarak bloğunu müşteri kuruluşlarına /23'lük parçalar halinde dağıtır.
  - Kuruluşlardan biri başka bir ISP'ye geçerse o kuruluşun /23'lük bloğu yeni ISP tarafından da ilan edilir. Gelen paket için en uzun önek eşleştirme uygulanır; /23, /20'den uzun olduğundan paket yeni ISP'ye yönlendirilir. <!-- BELİRSİZ: hocanın okuduğu adresler altyazıda "223.16.0/20" ve "223.18.0/23"; ilgili slayt karelerde görünmüyor. Ders kitabı örneğinde büyük olasılıkla 200.23.16.0/20 ve 200.23.18.0/23 kullanılır. -->
  - ISP'ler adres bloklarını ICANN'den (Internet Corporation for Assigned Names and Numbers) alır. ICANN adresleri beş bölgesel kayıt kuruluşu üzerinden dağıtır ve DNS kök bölgesini (.com, .edu gibi TLD'lerin devri dahil) yönetir.
  - IPv4 adresleri tükendiği için NAT (ağ adresi dönüştürme) ya da IPv6 kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- İletme ile yönlendirmenin farkı
  - İletme tek bir yönlendiricide, yerel olarak olur; yönlendirme kaynaktan hedefe tüm yolu planlar. Yolculuk benzetmesi (kavşak geçmek ve navigasyon) bu farkı akılda tutmak için verildi.
- Geleneksel yönlendirme ile SDN'nin ayrımı
  - Geleneksel yaklaşımda algoritma her yönlendiricide çalışır; SDN'de uzak denetleyici tabloları günceller. Her iki yaklaşımda da her yönlendiricide olan biten veri düzlemidir.
- İnternetin best effort olması
  - Teslim, sıra, zamanlama ve bant genişliği garantisi yoktur. Güvenilirlik üst katmanda TCP ile sağlanır.
- En uzun önek eşleştirme
  - Birden fazla eşleşme olabilir; her zaman en uzun eşleşen önek seçilir. Hoca bunun adresleme ve hiyerarşik adreslemede yeniden karşımıza çıkacağını söyledi.
- IP adresi arayüze verilir
  - Ana bilgisayara değil, arayüze verilir; birden çok arayüzü olan cihazın her arayüzünün ayrı adresi vardır.
- Tampon boyutu
  - Tampon dolu olmalı ama aşırı dolu olmamalı; fazla tampon gecikmeyi artırır.

## Kısa Tekrar Notları

- Ağ katmanı = veri düzlemi (yerel iletme, donanım, ns) + kontrol düzlemi (ağ geneli yönlendirme, yazılım, ms).
- İletme: giriş bağlantısı → çıkış bağlantısı, tek yönlendiricide. Yönlendirme: kaynaktan hedefe yol.
- Kontrol düzlemi: geleneksel (algoritma her yönlendiricide) ya da SDN (uzak denetleyici + kontrol ajanı).
- İnternet hizmet modeli: best effort; garanti yok. ATM CBR her şeyi garanti eder; Intserv (RFC 1633) de öyle; Diffserv (RFC 2475) kısmen.
- Yönlendirici: giriş portları, anahtarlama dokusu, çıkış portları, yönlendirme işlemcisi.
- Giriş portu: hat sonlandırma → bağlantı katmanı → arama, iletme, kuyruklama; "eşleştir + eylem".
- En uzun önek eşleştirme; TCAM ile tek saat çevriminde arama.
- Anahtarlama dokusu: bellek (1. kuşak, 2 veri yolu geçişi), veri yolu (çekişme), ara bağlantı ağı (crossbar, Clos, çok katlı, paralel düzlemler).
- HOL engellemesi: kuyruk başındaki datagram arkasındakileri bekletir.
- Tampon: RTT × C (250 ms × 10 Gbps = 2,5 Gbit); N akışta $RTT \cdot C / \sqrt{N}$.
- Atma: tail drop ya da önceliğe göre. Zamanlama: FCFS, öncelik, round robin, WFQ.
- Ağ tarafsızlığı: no blocking, no throttling, no paid prioritization (FCC 2015).
- IPv4 başlığı: 20 bayt (seçeneksiz); toplam en fazla 64 KB, tipik ≤ 1500 bayt; TTL her atlamada azalır.
- IP adresi 32 bit, arayüz başına; alt ağ = araya yönlendirici girmeden ulaşılan arayüzler; /24 = 24 bit alt ağ, 8 bit ana bilgisayar.
- CIDR: a.b.c.d/x.
- DHCP: discover → offer → request → ACK; istemci port 68, sunucu port 67; ayrıca ağ geçidi, DNS ve maske verir.
- /20 blok → $2^{12} = 4096$ adres; 3 bit daha ayırınca 8 tane /23.
- Adres blokları: ICANN, beş bölgesel kayıt kuruluşu; IPv4 tükendi → NAT, IPv6.

## Detaylı Açıklamalar

- **Ağ katmanının yeri ve işlevleri.** Ders, taşıma katmanından sonra ağ katmanına geçti. Bir evdeki dizüstü bilgisayarın bir kurumsal ağdaki web sunucusuna ulaşmak istediği senaryoda gönderici taşıma katmanı segmentlerini datagramlara kapsüller ve aşağı katmanlara iletir; alıcı tarafta datagramdan çıkan segment taşıma katmanına, oradan port numarasına göre uygulamaya gider. Arada doğrudan bağlantı yoktur; yol üzerindeki her yönlendirici datagram başlığına bakar ve iletme tablosuna göre datagramı uygun çıkış portuna yönlendirir. Bu iş iki temel işleve ayrılır: tek bir yönlendiricide giriş bağlantısından çıkış bağlantısına taşıma (iletme) ve kaynaktan hedefe tüm yolun belirlenmesi (yönlendirme).

- **Veri düzlemi ve kontrol düzlemi.** Veri düzlemi her yönlendiricinin kendi içindeki yerel işlevdir. Slayttaki örnekte gelen paketin başlık değeri `0111`'dir ve yerel iletme tablosunda `0111` → 2 satırı olduğu için paket 2 numaralı çıkış portuna gider (ekrandan, 00:25:00). Kontrol düzlemi ise bu tabloların nasıl dolduğuyla ilgilenir. Geleneksel yaklaşımda her yönlendirici bir yönlendirme algoritması çalıştırır ve diğer yönlendiricilerle mesaj alışverişi yaparak tablosunu günceller. SDN'de tabloyu uzak denetleyici hesaplar, yönlendiricideki kontrol ajanı bu tabloyu alır.
  - Ders sonrası not: Hoca tablonun son satırını "0101 → port 1" diye okudu; slaytta bu satır `1001` → 1'dir (ekrandan, 00:25:00).

- **Hizmet modeli.** Ağ katmanı garantili teslim, sıralı teslim ya da en düşük bant genişliği gibi hizmetler verebilirdi; ancak internet en iyi çaba modelini kullanır. Video akışı, video konferans, IP üzerinden ses gibi uygulamalar bu modelin üzerinde çalışır; güvenilirliği TCP sağlar. ATM'nin CBR ve ABR modelleri ile Intserv ve Diffserv gibi garantili modeller tanımlanmış, ama yaygınlaşmamıştır.
  - Ders sonrası not: Hoca Diffserv için "RFC 2470" dedi; slaytta RFC 2475 yazıyor (ekrandan, 00:30:00).

- **Yönlendirici içi.** Giriş portları, anahtarlama dokusu ve çıkış portları donanımda nanosaniye ölçeğinde çalışır; yönlendirme işlemcisindeki yazılım milisaniye ölçeğinde çalışır. Giriş portunda gelen sinyal önce fiziksel katmanda sonlandırılır, sonra bağlantı katmanı protokolü işlenir, en son ağ katmanında başlığa göre arama yapılır. Hedefe dayalı iletmede aralık tablosu kullanmak, aralıklar alt aralıklara bölündükçe zorlaşır: slaytta arayüz 0'ın aralığının içinden küçük bir alt aralık arayüz 3'e ayrılmıştır (ekrandan, 00:40:00). En uzun önek eşleştirme bu sorunu çözer: birden çok girdi eşleşse bile en uzun önek kazanır.

- **Anahtarlama ve kuyruklar.** Bellek tabanlı anahtarlamada paket iki kez sistem veri yolundan geçtiği için hız bellek bant genişliğiyle sınırlıdır. Veri yolu tabanlı anahtarlamada tek bir paylaşılan veri yolu vardır ve aynı anda tek datagram geçebilir. Ara bağlantı ağları paralellikle ölçeklenir. Doku yavaşsa giriş kuyruğu oluşur ve HOL engellemesi görülür; doku çıkış hattından hızlıysa çıkış kuyruğu oluşur, tampon dolunca paket kaybı olur. Bu yüzden atma politikası ve zamanlama disiplini gerekir.

- **IPv4 başlığı ve hocanın sayısal ifadeleri.**
  - Ders sonrası not: Hoca TTL'nin "16 bit" olduğunu söyledi; slayttaki biçimde TTL ve üst katman alanları birlikte 16 bitlik yarım satırı paylaşır, yani TTL 8 bittir (ekrandan, 01:30:00).
  - Ders sonrası not: Hoca ek yükü "TCP için 20 bayt, IP için 25 bayt, toplam 40 bayt" diye söyledi; toplamın 40 olması için IP başlığı da 20 bayt olmalıdır. Doğrusu büyük olasılıkla seçeneksiz IPv4 başlığının da 20 bayt olmasıdır.
  - Ders sonrası not: Hoca /24 için "kalan en düşük mertebeli 8 bit ağ kısmıdır" dedi; doğrusu ana bilgisayar (host) kısmıdır.

- **DHCP akışı.** İstemcinin henüz adresi olmadığı için ilk mesajlar kaynak 0.0.0.0 ve hedef yayın adresiyle gönderilir. Sunucu teklifinde yiaddr alanına önerdiği adresi (örnekte 223.1.2.4), aynı işlem kimliğini ve geçerlilik süresini koyar. İstemci request ile bu adresi ve süreyi ister, sunucu ACK ile onaylar. DHCP aynı akışta ağ geçidi adresini, DNS sunucusunu ve ağ maskesini de verir.
  - Ders sonrası not: Hoca request mesajını daha önce adres almış bir istemcinin doğrudan gönderebileceği ayrı bir senaryo olarak anlattı. Standart dört mesajlık akışta request, istemcinin offer'daki adresi kabul ettiğini bildiren mesajdır (büyük olasılıkla ders kitabı akışı discover → offer → request → ACK sırasındadır).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
