# Ders 11 Genişletilmiş Notu: E-ticaret ve Etik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. E-ticarete Giriş ve Ticaretin Üç İlkesi
- 2. Ticaret Güvenliğinin Tarihsel Kökü: İpek Yolu ve Kervansaraylar
- 3. TCP/IP Protokolünün Yapısı
- 4. TCP/IP Protokolünün Güvenliği ve Saldırı Türleri
- 5. IPv6 ve Güvenlik Başlıkları
- 6. SSL ile Güvenli İletişim
- 7. Güvenli Elektronik Ödeme: SET Protokolü
- 8. SSL'in Sorunları ve Üç Boyutlu Güvenlik
- 9. E-ticarette Tarafların Birbirine Güvenmesi
- 10. E-ticarette Tarafların Mutluluğu
- 11. E-ticaretteki Etik ve Hukuk Sorunları
- Örnek Sorular

## 1. E-ticarete Giriş ve Ticaretin Üç İlkesi

Bu haftanın konusu e-ticaret ve etiktir. Slayttaki giriş metnine göre büyük firmaların 1970'lerden beri bilgisayarlar arası iletişim yoluyla ticaret yaptıkları bilinmektedir. Bu ticaret bir özel ağ, yani **VAN (Value Added Network)** üzerinden yürütülür. Genel ağın (internetin) yaygınlaşmasıyla daha çok bireysel kullanıma yönelik e-ticaret gelişmiş ve çok hızlı büyümüştür. İnsanların alışverişini kolaylaştıran e-ticaret, beraberinde değişik sorunları da getirmiştir (ekrandan, 00:05:00).

Hoca, e-ticaret sürekli geliştikçe farklı sorunların doğduğunu ve dersin bu sorunları incelediğini belirtti. Her ticaretin üç temel ilkesi vardır (ekrandan, 00:05:00):

- Ticaret güvenli ortam ister.
- Alıcı ve satıcının birbirine güvenmesi gerekir.
- Alan ve satan alışverişten mutlu olmalıdır.

Hoca üçüncü ilkeyi, her iki tarafın da eylemi kendi çıkarlarını karşılayacak biçimde gerçekleştirmesi olarak açıkladı. Dersin geri kalanı bu üç ilke üzerine kuruludur: önce güvenli ortam (ağ güvenliği, SSL, SET), sonra tarafların birbirine güveni, ardından tarafların mutluluğu ve son olarak etik ve hukuk sorunları.

Slayta göre büyük kuruluşların kapalı bir ağ olan VAN üzerinden, **EDI** belgelerini kullanarak yaptığı e-ticarette yeterli güvenlik sağlanmaktadır ve taraflar birbirini çok iyi tanır (ekrandan, 00:05:00). Son kullanıcılara yönelik e-ticaret uygulamaları ise böyle değildir; dersin ağırlığı bu uygulamalardır.

## 2. Ticaret Güvenliğinin Tarihsel Kökü: İpek Yolu ve Kervansaraylar

Hoca "ticaret güvenli ortam ister" ilkesinin tarihteki İpek Yolu ticaretinden bugünkü e-ticarete kadar birebir geçerli olduğunu söyledi. O dönemde mal aktarımı kervanlarla yapılırdı. İpek Yolu üzerindeki devletler ticaretin güvenli olması için yollar yaptırmış, gerektiğinde kervanların güvenliğini sağlamak üzere askerler görevlendirmiş, konaklama için de kervansaraylar ve hanlar kurmuştur.

Türkler İpek Yolu üzerinde önemli bir coğrafyada yaşamış ve yaklaşık 35-40 kilometrede bir kervansaray yapmıştır. Bu mesafe, yürüyen bir kervanın günde 7-8 saat yol aldığında aşağı yukarı varacağı noktadır. Hoca bunu bugünkü "pit stop" ya da "checkpoint" gibi bir etap noktasına benzetti. Kervansaray "kervanın sarayı" anlamındadır: güvenli konaklama, bakım ve yolla ilgili alışverişlerin yapıldığı yerdir. Yerleşim yerinin dışındaysa kervansaray, içindeyse han adını alır. Bu yapılarda insanlar için yatakhaneler, hayvanlar için ahırlar, yemekhane, temizlik için hamam, bugünkü eczanenin karşılığı olan ilaç hizmeti, kunduracılar ve nalbantlar bulunur.

Bu hizmetler kervanlara belli bir süre için ücretsiz verilirdi. Hoca "Kim karşılıyor bunun parasını?" diye sordu ve cevabı şöyle verdi: Hizmetlerin verilmesinin ve askerlerin güvenliği sağlamasının tek amacı ticareti geliştirmek, korumak ve bu ticaretten devlet olarak vergi toplamaktır. Yani ücretsiz görünen ticaret güvenliği hizmetleri, sonunda o ticaretten elde edilen vergilerle finanse edilir.

Bugünkü e-ticarette bunun karşılığı, iletişim güvenliği ve yine eskiden olduğu gibi ticaretin (ödemenin) güvenliğidir. Dersin sonraki bölümleri bu iki güvenlik türünü sırayla ele alır.

## 3. TCP/IP Protokolünün Yapısı

Hoca güvenlik altyapısına ilişkin, ağ derslerinden bilinen temel kavramların üzerinden hızlıca geçti. İnternette iletişim protokolü olarak ABD Savunma Bakanlığı (DoD) tarafından geliştirilen **TCP/IP** kullanılır. Genel olarak iki katmanı vardır:

- Üst katman **TCP**: gönderilecek veriyi paketlere ayırıp alıcıya gönderir; alıcıda gelen paketler birleştirilerek verinin ilk hâli elde edilir.
- Alt katman **IP**: paketleri adrese iletir.

> **Ders sonrası not:** Hoca TCP'nin açılımını "Transfer Control Protocol" olarak söyledi; doğrusu "Transmission Control Protocol"dür.

Daha ayrıntılı bakıldığında üst kısımda **uygulama** ve **taşıma** katmanları vardır. Uygulama katmanı farklı bilgisayarlardaki uygulamalar arasındaki iletişimi sağlar; taşıma katmanı veri akışını sağlar. Alt kısımda ise şu katmanlar bulunur:

- **Genel ağ (internet) katmanı:** yönlendiricilerle bağlanmış ağlar üzerinden verilerin kaynak bilgisayardan hedef bilgisayara iletilmesinden sorumludur.
- **Ağ erişim katmanı** (veri bağı katmanı, data link layer): ağ ile bilgisayar arasındaki mantıksal ilişkinin tanımlanmasını ve kurulmasını sağlar.
- **Fiziksel katman:** elektrik sinyallerini ve fiziksel ortamın özelliklerini belirler.

## 4. TCP/IP Protokolünün Güvenliği ve Saldırı Türleri

E-ticaret açısından en önemli konu TCP/IP'nin güvenliğidir. TCP/IP tasarlandığında güvenlik göz ardı edilmiştir, çünkü protokolün ARPANET'te çalışması öngörülmüştü ve ARPANET kapalı bir ağ olarak düşünülmüştü. Hoca bunu dersin başındaki kapalı VAN ağlarındaki haberleşmeye benzetti. Ancak TCP/IP öyle yaygınlaştı ki göz ardı edilen güvenlik çeşitli açıklara dönüştü ve zamanla farklı saldırılar ortaya çıktı. Saldırı türleri iki slaytta özetlenmiştir (ekrandan, 00:10:00 ve 00:15:00).

### 4.1 SYN saldırıları

Slayttaki tanıma göre TCP/IP protokolünde bilgisayarlar üç aşamada oturum kurar. Sunucu dinleme konumundadır ve istemciden istek bekler; istek **SYN** olarak gelir. İsteği alan sunucu **75 saniyeye** kadar bekleme durumunda kalır. Genellikle sunucular ortalama **5 isteği** karşılayacak durumdadır (ekrandan, 00:10:00).

Sunucuyu meşgul etmeyi hedefleyen saldırganlar peş peşe bağlantı isteği göndererek sunucunun hizmet vermesini engelleyebilir. **SYN kandırması** adı da verilen bu saldırılar, TCP/IP'nin sunucu ile istemci arasında oturum kurmadaki zayıf yönünden yararlanır.

### 4.2 IP kandırması

Bu saldırıda saldırgan kendi IP adresi yerine sahte bir adres kullanır: gönderdiği veri paketinin içine sahte bir IP adresi ekler. Alıcı taraftaki IP katmanı paketteki adresi gerçek adres olarak değerlendirir. Slayta göre bu tür saldırılar genellikle sunucuların hizmet vermelerini aksatmak amacıyla yapılır (DDoS) (ekrandan, 00:10:00).

### 4.3 Sıra numarasını tahmin etme

TCP protokolüne uygun bağlantıda kullanılan başlangıç sıra numarası (**ISN: Initial Sequence Number**) 32 bit uzunluğundadır; bu yüzden tahmin edilme olasılığı düşüktür. Ancak kaynak bilgisayar bu numarayı belli bir kurala göre üretiyorsa tahmin etmek kolaylaşır. Slayta göre Unix çekirdeğinin ISN'yi belli bir kurala göre hesapladığı, bu nedenle bir önceki bağlantıda kullanılan ISN biliniyorsa bir sonrakinin hesaplanabileceği açıklanmıştır. Saldırganlar bu zayıflıktan yararlanmak için çok sayıda ISN dener (ekrandan, 00:10:00). Hoca, algoritmanın mantığı çözüldüğünde paket sıra numaralarının da istismar (exploit) edilebileceğini ekledi.

> **Ek bilgi (derste anlatılmadı):** 32 bitlik bir sayı $2^{32} = 4\,294\,967\,296$ farklı değer alabilir. Numara rastgele üretilirse doğru değeri körlemesine tahmin etmek bu kadar seçenek arasından birini bulmak demektir; üretim kuralı biliniyorsa aday sayısı çok küçülür.

### 4.4 Kaynak yönlendirme

Kaynak yönlendirme, yanıtın hangi yolla, hangi IP'ye ulaşması gerektiğini gönderenin belirlediği durumdur. Slayta göre günümüz yönlendiricileri bunu belirleyebildiği için bu konu sorun olmaktan çıkmıştır (ekrandan, 00:10:00).

### 4.5 Bağlantıyı ele geçirme (aradaki adam)

Slayttaki tanıma göre bağlantıyı ele geçirme ya da **aradaki adam** (man in the middle) olarak adlandırılan yöntemde saldırgan, bağlantıdaki iki bilgisayarın arasına girer. Slaytta IP kandırması yönteminin, Unix parolası, Kerberos ve TKP gibi ek güvenlik bilgilerini iki taraf arasında aktaramadığı; ancak bu yöntemde saldırganın iki bilgisayar arasındaki asıllama işleminin sürmesini sağladığı ve bağlantıyı ele geçirdiği yazar. Yöntemin çalışabilmesi için aradaki adamın iki bilgisayarın iletişim yolu üzerinde bulunması gerekir. Aradaki adam iki taraftan gelen paketleri birbirine aktarır (ekrandan, 00:15:00).

Hoca bu saldırının TCP'nin **eşzamansız durumundan** (desynchronized state), yani "ayak uyduramama" durumundan beslendiğini anlattı. Mekanizma şöyledir:

- Her veri paketinde bir sıra numarası vardır. Gelen paketin numarası beklenenden farklıysa iletişimde bir ayak uyduramama olduğuna, yani eşzamansız duruma geçildiğine karar verilir.
- Amaç paketlerin kaybolmaması ve gecikmemesidir; bunun için **kayan pencere** (sliding window) yöntemiyle etkin iletişim hedeflenir.
- Sıra numarası beklenenle uyuşmayan ama kayan pencerenin içinde kalan paket, daha sonra işlenmek üzere tampon bellekte saklanır. Pencerenin dışındaki paket reddedilir.
- Eşzamansız duruma düşen taraflar gelen paketleri reddetmeye devam eder. Bu sırada aradaki saldırgan kendi hazırladığı sahte paketleri **doğru sıra numarasıyla** gönderir; böylece paketini iletişime eklemiş ve istediği veriyi karşı tarafa aktarmış olur.

### 4.6 Yönlendirme saldırısı

TCP/IP'de kullanılması kesinlikle gerekli olmayan, ancak sıkça kullanılan **RIP (Routing Information Protocol, Yönlendirme Bilgisi Protokolü)** ağdaki en kısa ya da önerilen yolu tanımlar. RIP asıllama içermez, dolayısıyla doğrulama yapmaz. Bu açıktan yararlanan saldırganlar paketin geldiği ve gideceği adresleri değiştirebilir, böylece paketleri ele geçirebilir ve içeriğini istedikleri gibi değiştirebilir (ekrandan, 00:15:00). Hoca bunun sonucunun aradaki adam saldırısına benzediğini belirtti.

### 4.7 ICMP saldırısı

Alıcı tarafı uyarmak üzere gönderilen mesajlar **ICMP (Internet Control Message Protocol)** olarak adlandırılır ve genellikle "ping atmak" diye bilinir. Ping atıldıktan sonra gönderen taraf karşı tarafın yanıt vermesini bekler. ICMP mesajı asıllama bilgisi içermediği için hizmet aksatma saldırılarında kolayca kullanılır (ekrandan, 00:15:00).

### 4.8 Alan adı hizmeti (DNS) saldırısı

**DNS (Domain Name Service)**, insanların kolayca belleyebildiği alan adlarını IP adreslerine dönüştüren işlemdir; bu işi yapan sunuculara DNS sunucusu denir. Saldırganlar **alan çalma** adı verilen yöntemle bir sunucunun ya da web sayfasının IP adresini ele geçirir, sonra DNS sunucusuna erişip alan adının karşılığı olan IP adresini değiştirir. Böylece kullanıcı gerçek siteye gittiğini düşünürken farklı bir sunucuya ya da sayfaya yönlendirilir (ekrandan, 00:15:00).

### 4.9 Tekil kimliğin yokluğu

İnternetin ilk dönemlerinde her bilgisayara ayrı, bağımsız bir IP adresi verileceği öngörülmüştü. Bir süre sonra bunun yetersiz kaldığı, bu kadar adres olmadığı görüldü. Günümüzde konuma bağlı ya da geçici olarak tanımlanan IP adresleri kullanılır ve bunlar sunucular ya da adres dönüştürücüler tarafından değiştirilir. Dolayısıyla yere bağlı ya da geçici IP adresine dayalı güvenlik sistemleri saldırılara karşı zayıf kalır (ekrandan, 00:15:00).

## 5. IPv6 ve Güvenlik Başlıkları

1981'de tasarlanan IPv4 özellikle asıllama konusunda yetersizdir. Bu nedenle yeni bir protokol ihtiyacı doğmuş ve 1990'larda IPv6 tasarlanmıştır; IPv4'teki eksikler ve hatalar mümkün olduğunca giderilmeye çalışılmıştır. IPv6'da güvenlik için iki ek başlık vardır:

- **Authentication Header (asıllama başlığı):** göndericinin gerçek kimliğinin öğrenilmesini sağlar.
- **Encapsulating Security Payload Header (şifreleme başlığı):** mesajın içeriğini yalnız gerçek alıcının görebilmesini sağlar.

Bu iki özelliğin işlemesi için gönderici ile alıcının asıllama ve şifrelemede kullanacakları anahtar ve algoritma konusunda önceden anlaşmış olmaları gerekir. Bu anlaşmaya **güvenlik birliği** denir. Güvenlik birliği **SPI (Security Parameter Index, güvenlik değişken dizini)** ile tanımlanır; bu bir tür anahtar değişimi olarak gerçekleşir ve alıcı her gönderici için bir SPI belirler. Hoca anahtar değişimi için Diffie-Hellman yönteminin kullanılması gibi öneriler olduğunu, ama kesin kabul görmüş bir standart bulunmadığını söyledi.

Hoca bu bölümü şöyle bağladı: Bu saldırıların hepsi asıllama sorunları üzerine kurgulanır; TCP/IP'nin doğasında asıllama yoktur, çünkü protokol güvenli bir ağ için tasarlanmıştır.

## 6. SSL ile Güvenli İletişim

Güvenlik ve gizlilik e-ticarette her zaman önemli ve endişe kaynağı olmuştur. İnternet gibi açık bir ağda yürütülen ticarette güvenliğin sağlanması bu yüzden revaçta bir konudur. E-ticaret yapan bütün taraflar hem izlenmediklerinden hem de bilgilerinin çalınmadığından emin olmak ister. Bunun için ilk adım iletişimin şifrelenmesidir.

Netscape firmasının geliştirdiği **SSL (Secure Socket Layer)** şifreleme için RSA algoritmasını kullanır ve sertifika tabanlıdır. Kuruluşlar arasında, satıcı ile müşteri arasında, bireyler arasında ve internet bankacılığında SSL ya da TLS protokolleri standart olarak kullanılır ve bugün de kullanılmaya devam eder. SSL temel olarak iletişimin **gizliliğini** ve **bütünlüğünü** sağlar. İnternette çalışması hedeflendiği için TCP/IP üzerinde çalışır: TCP/IP ile iki uygulama arasında kurulan iletişimin gizliliği ve bütünlüğü SSL tarafından sağlanır. HTTP de güvenlik için SSL'i kullanır; **HTTPS** temelde SSL'e dayalıdır.

> **Ders sonrası not:** Altyazıda "RSI" ve "TSL" olarak geçen adlar, RSA şifreleme algoritması ve TLS (Transport Layer Security) protokolüdür.

### 6.1 SSL'in çalışma mantığı

Hoca SSL mantığını şöyle anlattı:

- Bir istemci ve bir sunucu vardır. Aralarında gidip gelen veriler **simetrik** şifreleme algoritmalarıyla şifrelenir.
- Simetrik şifrelemede kullanılacak anahtar ise **asimetrik** bir algoritmayla (örneğin RSA) iletilir. İstemci ile sunucu ilk bağlantıyı kurduklarında önce asimetrik yöntemi kullanır, sonra trafikteki bütün verileri şifrelemek ve çözmek için kullanacakları anahtarı belirler.
- Anahtar değişiminde sunucu, **sayısal yetki belgesi** (sertifika) ile açık anahtarını istemciye gönderir. İstemci bu açık anahtarı kullanarak yanıtını sunucuya gönderir.
- Bu sırada istemci sertifika üzerinden sunucunun kimliğini sorgulayıp doğrulamaya çalışır: bağlandığı yer gerçekten o mudur, sertifika kime verilmiştir?

Özetle HTTP tabanlı bir SSL bağlantısında adres HTTPS ile yazılır. Önce el sıkışma (handshaking) yapılır; bu aşamada oturum için gerekli şifreler belirlenir ve sertifikadan alınan açık anahtarla üretilen şifre sunucuya iletilir. Şifreler belirlenince el sıkışma tamamlanır. Bundan sonra oturum boyunca iki taraf arasındaki veriler simetrik yöntemle şifrelenerek gidip gelir.

Hocaya göre SSL'in birinci ve ikinci sürümlerinde yalnız sunucu asıllaması yapılıyordu; üçüncü sürümde hem istemci hem sunucu asıllaması yapılabilir. <!-- BELİRSİZ: sürüm ayrıntısı yalnız altyazıdan; bu anın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** Simetrik şifrelemede iki taraf aynı gizli anahtarı kullanır ve işlem hızlıdır; asimetrik şifrelemede açık ve gizli anahtar çifti vardır, anahtarın güvenli paylaşılması kolaydır ama işlem yavaştır. SSL/TLS ikisinin üstün yönlerini birleştirmek için asimetrik yöntemi yalnız anahtar değişiminde, simetrik yöntemi veri aktarımında kullanır.

## 7. Güvenli Elektronik Ödeme: SET Protokolü

Ödeme güvenliği e-ticaretteki en temel güven noktalarından biridir. Ödemeler özellikle kredi kartıyla yapılır ve güvenli biçimde yapılması iki taraf için de son derece önemlidir; hoca bunun hâlâ endişe kaynağı olduğunu söyledi.

### 7.1 SET'in ana ilkesi

11 teknoloji firması **SET (Secure Electronic Transaction, Güvenli Elektronik Ödeme)** ölçütünü 1996'da tasarlamıştır. Slayttaki tanıma göre SET protokolünün ana ilkesi, genel ağ üzerinden yapılacak ödemenin müşteri tarafından satıcıya doğrudan yapılmaması, bunun yerine bir aracı kuruluş (**ödeme kanalı**) üzerinden yapılmasıdır (ekrandan, 00:25:00).

Slayta göre güvenli ödeme sisteminde hem müşteri hem satıcı için **SYB (sayısal yetki belgesi)** gerekir. SET içinde SYB kullanıldığı için müşteri, satıcı ve banka arasında güvenilir ve gizli bir iletişim sağlanır. Ödeme işlemi güvenli biçimde kurulur, sorunsuz sürdürülür ve sahtecilik engellenir. Satıcı kredi kartı hakkında bilgi edinemez; yalnız kartın çalınmış ya da sahte olup olmadığına karar verebilir (ekrandan, 00:25:00). Hoca bunun iki taraflı bir güvenlik olduğunu vurguladı: alıcının kart bilgisi satıcının eline geçmez, satıcı da kartın geçerliliği hakkında gereken bilgiyi alır.

### 7.2 Bilgi güvenliğinin dört temel ilkesi

Hoca SET'in ilkelerine geçmeden önce bilgi güvenliğinin dört temel ilkesini hatırlattı: **asıllama** (authentication), **gizlilik**, **bütünlük** ve **inkâr edilemezlik**. SSL'de gizlilik için simetrik ve asimetrik şifreleme kullanılır; müşteri ile satıcı arasında güvenli bir tünel oluşur ve iki taraf dışındakiler bu tünelin içindeki verileri göremez. Ancak SSL bu dört ilkenin hepsini karşılamaz; sorunları 8. bölümde ele alınır.

### 7.3 SET'in temel ilkeleri ve tarafları

SET protokolünün temel ilkeleri şunlardır:

- Sipariş ve ödemenin gizliliğini sağlamak.
- Ödeme ve hizmetlerle ilgili veri bütünlüğünü sağlamak.
- Kredi kartı ve müşteri hesabının asıllanmasını sağlamak.
- Satıcının asıllanmasını sağlamak.

Yani SET iki tarafı da asıllar, ayrıca verilerin bütünlüğünü ve iletişimin gizliliğini sağlar. SET'te altı taraf bir araya gelir:

- Kredi kartı müşterisi (kart sahibi)
- Satıcı
- Kartı veren banka
- Satıcının çalıştığı banka
- Ödeme kanalı
- Sertifika yetkilisi

Hem satıcının hem müşterinin sertifikası olması gerekir, ama satıcılar için bu mutlaka şarttır. Her müşteri için sertifika sağlamak olanaklı olmadığından müşteri asıllaması kredi kartı doğrulaması, yani kredi kartı bilgileri üzerinden tanıma yoluyla yapılır.

### 7.4 SET ile alışveriş süreci

Hocaya göre bir alışveriş süreci genellikle dokuz adımdan oluşur. Aşağıdaki numaralandırma hocanın anlatım sırasından kurulmuştur:

1. Müşteri satıcının web sayfasına bağlanır.
2. Sipariş ve ödeme bilgileri iki parça olarak gönderilir: alışveriş (sipariş) bilgisi satıcıya, kredi kartı bilgisi satıcı üzerinden satıcının bankasına. Satıcı kart bilgisinin içeriğine erişemez.
3. Satıcı kredi kartı bilgilerini aynen kendi bankasına iletir.
4. Satıcının bankası müşterinin kartını veren kuruluşa (kart merkezine) bağlanır ve onay ister: kart doğru ve geçerli mi, limiti var mı? Yani provizyon ister.
5. Kartı veren kuruluş satıcının bankasına onay gönderir.
6. Banka satıcıya onay gönderir (ödeme doğru, provizyon alındı).
7. Satıcı siparişi tamamlar ve müşteriye onay belgesi gönderir.
8. Satıcı bankadan alışverişle, yani para trafiğiyle ilgili işlem kayıtlarını alır.
9. Satıcı ürünü ya da hizmeti, ayrıca ödemenin alındığını gösteren resmi belgeyi (fiş ya da fatura) gönderir.

### 7.5 SET çalışma biçimi diyagramı

Slayttaki diyagram üç bölgeden oluşur (ekrandan, 00:35:00):

| Bölge | İçindeki öğeler |
|---|---|
| Güvenli Elektronik İşlem SET (mavi) | Müşteri, satıcının web sayfası, ödeme kanalı |
| Satıcı (kırmızı) | Satıcının web sayfası, satıcının bilgisayarı, faks ve posta |
| Finansal ağ (sarı) | Ödeme yöneticisi, kartı veren |

Diyagramdaki bağlantılar şöyledir:

- Çevrim içi yol: müşteri ↔ satıcının web sayfası ↔ ödeme kanalı ↔ ödeme yöneticisi ↔ kartı veren.
- Geleneksel yol: müşteri ↔ satıcının bilgisayarı ("Telefon veya Havale ile Ödeme"); satıcının bilgisayarı ↔ ödeme yöneticisi.

Hoca diyagramı şöyle okudu: Sağdaki finansal ağ arka taraftır; burada ödeme yöneticisi ile kartı veren kuruluş haberleşir. Alt yolda müşteri satıcıyla telefonla ya da havaleyle iletişim kurup ödeme yapar; bu ödeme doğrudan satıcı üzerinden finansal ağa gider ve gerekiyorsa kartla ilgili işlemler ödeme yöneticisinde yapılır. Hoca bu yolu posta ile sipariş (mail order) gibi düşünebileceğimizi söyledi. Üst yolda müşteri bilgisayardan satıcının web sayfasıyla konuşur; satış ve ödeme bilgilerini gönderir, ödeme bilgileri ayrıştırılarak ödeme kanalına gider ve arka taraftaki finansal ağda onay, doğrulama ve provizyon işlemleri yapılır.

### 7.6 Çift imza

Alışveriş iki parçadan oluşur: sipariş parçası satıcıya, kredi kartı bilgilerini içeren ödeme parçası satıcı üzerinden satıcının bankasına gider. Satıcının kart bilgisini görmemesi gerekir, ama alışverişin tamamlanması için iki parçanın bir şekilde birbirine bağlanması gerekir. Bunun için:

- Sipariş bilgileri bir özet (hash) fonksiyonundan geçirilerek özete dönüştürülür.
- Ödeme bilgileri ayrı bir özet fonksiyonundan geçirilir.
- Bu özetlerden yeniden özet çıkarma ve şifreleme ile **çift imzalı** bir onay mekanizması oluşturulur.

İki taraf da imzaladığı için işlem çift onaydan geçer ve taraflar alışverişin hiç olmadığını ya da bu şekilde olmadığını inkâr edemez. Sonunda satıcı; sipariş bilgilerini, çift imzalı onayı ve ödeme özetini kullanarak bankadan ödemeyi kendi ticari hesabına alır.

> **Ek bilgi (derste anlatılmadı):** SET belirtiminde çift imza, büyük olasılıkla şu biçimde tanımlanır: ödeme bilgisinin özeti $H(PI)$ ile sipariş bilgisinin özeti $H(OI)$ art arda eklenir, bunun özeti alınır ve müşterinin gizli anahtarıyla imzalanır: $DS = E_{KR_c}\big[H(H(PI) \,\|\, H(OI))\big]$. Satıcı yalnız sipariş bilgisini ve $H(PI)$'yi, banka yalnız ödeme bilgisini ve $H(OI)$'yi görür; ikisi de imzayı doğrulayabilir.

Hoca SET'i dersin başındaki tarihsel örneğe bağladı: kervansaraylar döneminden gelen ticaret güvenliğinin e-ticaretteki karşılığı, ödeme güvenliğinin sağlanmasıdır.

## 8. SSL'in Sorunları ve Üç Boyutlu Güvenlik

Slayttaki "SSL'nin sorunları" başlığına göre SSL müşteriyi kulak misafirlerinden korur, buna karşın sahte satıcılardan koruduğu söylenemez. Bazı satış siteleri sahte ya da yanıltıcı olabilir ve müşterileri dolandırmak amacıyla kurulur. Müşterilerini iki türlü dolandırırlar (ekrandan, 00:25:00):

1. Tanınmış bir satıcının taklidini yaparak.
2. Tümüyle yalancı bir site oluşturarak.

Hoca birinci yöntemi açtı: dolandırıcılar tanınmış bir satıcının web sayfasını fark edilmeyecek kadar küçük değişikliklerle birebir kopyalar. Müşteri oltalama (phishing) türünden bir bağlantıya tıklayıp girdiğinde bilinen, saygın bir alışveriş firmasından alışveriş yaptığını düşünür. Oysa güvenli olarak bağlansa bile karşı taraf bir dolandırıcı olabilir. Alışveriş yapıldıktan sonra sahte bir ürün gönderilebilir ya da karttan söylenen tutardan fazlası çekilebilir.

Bunun tersi de olur: müşteriler de satıcıları dolandırabilir. Örneğin sahte bir kredi kartıyla alışveriş yapılabilir. Hoca, kartın bilgisayar olmadan kullanıldığı (karbon kopya çıkarma gibi yöntemlerin olduğu) ya da kart için parola korumasının bulunmadığı ülkelerde başkasının kartıyla kolayca alışveriş yapılabildiğini, artık bunun pek kalmadığını söyledi.

Bu tür dolandırıcılıkların önüne geçmek için **üç boyutlu güvenlik** (3D Secure) sistemleri geliştirilmiştir. Slayta göre bu sistemde kredi kartıyla ödeme anında müşterinin cep telefonuna bir sayı gönderilir ve müşterinin bu sayıyı ödeme ekranındaki alana girmesi istenir. Böylece kredi kartıyla ödeme yapmak isteyenin gerçek müşteri olup olmadığına karar verilir (ekrandan, 00:25:00). Hoca mantığı şöyle özetledi: o kodu görebiliyorsanız kartın sahibi sizsiniz; güvenliğe bir boyut daha eklenmiş olur.

## 9. E-ticarette Tarafların Birbirine Güvenmesi

E-ticarette güven esastır ve tarafların birbirine güvenmesi gerekir. Taraflar temelde üç sınıfa ayrılır.

### 9.1 Kuruluşlar arası e-ticaret (B2B)

Kuruluşlar, eskiden VAN ağları üzerinden yaptıkları ticareti artık genel ağ üzerinden de yapabilir. Taraflar uzun süredir ticaret yapan, birbirini tanıyan tüzel kişiliklerdir; bu yüzden burada önemli bir sorun beklenmez. Hoca ayrıca iletişim ağları kapalı ve güvenli olduğu için burada etik ya da hukuki bir sorun beklenmediğini yineledi.

### 9.2 Kuruluş ve birey arası e-ticaret (B2C)

B2C çok yaygındır ve en sık sorun yaşanan alandır: satıcı gerçek olmayabilir, müşterinin ödemesi de gerçek olmayabilir. Buradaki satıcılar e-ticaret yapmak için kurulmuş firmalardır; alıcılar kendi adına ya da bir kuruluş adına alım yapan bireylerdir.

Hoca e-ticaretin hayatı kolaylaştırdığını, büyük ticari kazanç ve ticarette dinamizm sağladığını söyledi. E-ticaret firmaları sürekli artmaktadır (batanlar da vardır) ve mobil kanallar gibi alternatif dijital kanallar üzerinden evrilerek sürecektir. İnternette e-ticaret yapan firma sayısının milyonlarca olduğu, ama bunların içinde çok büyük ciro yapanların çok az, belki binden az olduğu tahmin edilmektedir; hoca bunun bilinen değil, tahmin edilen bir şey olduğunu vurguladı.

Ülke çapında geçmişi olan, tanınmış firmalara insanlar güvenebilir. Ancak hoca bu firmaların artık pazar yeri modeline geçtiğini, bu yüzden karşıdaki satıcının gerçekten o kurumsal firma mı yoksa o firmanın pazar yerine takılmış bir dolandırıcı mı olduğunu bilmenin zorlaştığını belirtti. Geçmişi bilinmeyen, yeni açılmış, tanınmayan firmalarla yapılan ticarette risk daha yüksektir. Alışveriş sonundaki iade süreci de ayrı bir sıkıntıdır: çoğu firma iadeyi kabul ediyor görünse de özellikle küçük firmalar bu konuda sözünü tutmaz.

> **Hocanın vurgusu:** Satıcıların mutlaka sertifikası olmalıdır. Sertifikası olmayan bir yerle ticaret yapıyorsanız oradan uzaklaşın. Sertifikanın bile doğruluğu tartışılabilir, ama sertifikası yoksa o yere güvenmek çok büyük bir yanlıştır.

### 9.3 Az bilinen e-ticaret firmalarıyla yaşanan sıkıntılar

Slaytta bu sıkıntılar şöyle sıralanır (ekrandan, 00:40:00):

- **Ayıplı ürün gönderilmesi:** E-ticaret sayfasında beğenilip seçilen ürün müşteriye gönderilir, ama ürün kullanılmış, bozuk, arızalı ya da tamir edilmiş olabilir. Ürün geri gönderildiğinde yenisini gönderen firmalar olduğu gibi hiç yanıt vermeyenler de vardır. Özellikle ayıplı ürünü bilerek gönderen firmalardan yeni ve sağlam bir ürün beklemek saflık olur.
- **Taklit ürün gönderilmesi:** Dış görünüşü bilinen bir ürüne çok benzeyen bir ürün gönderilir. Taklit ürün gönderenlerin dolandırıcı olduğu kesindir; dolayısıyla ürünü geri göndermek ve gerçeğini beklemek anlamsızdır. Hoca para iadesinin de söz konusu olmadığını ekledi.
- **Eksik ürün gönderilmesi:** Bazı ürünler paketler hâlinde satılır ve her pakette kaç tane olduğu belirtilir. Dolandırıcı firmalar paketlere web sayfasında yazandan daha az ürün koyar. Hoca, üç tane sipariş edip bir ya da iki tane gelmesi gibi durumları da örnek verdi.
- **Sahte ürün gönderilmesi:** Slaytta disk yerine demir kütle, ilaç yerine toz kireç, kitap yerine kitabın kapağının geldiğini söyleyen insanlardan söz edilir. Hoca, uzak doğudan alınan diskin kutusundan aynı ağırlıkta olsun diye konmuş demir parçası çıkması ve telefon yerine salatalık gelmesi gibi haberlere yansıyan örnekleri de andı.

Slaytta ayrıca lisanslı yazılım satışı örneği vardır (ekrandan, 00:40:00): Bazı Uzak Doğu ülkesi firmaları lisanslı programları, özellikle işletim sistemlerini, ucuz fiyatla satar ve gelen ürün bilgisayara lisanslı bir ürün gibi kurulabilir. Bunun nasıl mümkün olduğu araştırıldığında şu sonuca varılmıştır: İşletim sistemi üreten firmalar, bilgisayar donanımı üreticisi firmalara programların bir aslını verir ve çoğaltma hakkı tanır; her çoğaltma için de lisans numarası tanımlar. Satıcının işletim sisteminin kopyasını elde etmesi kolaydır. Bu kopyaları CD ya da DVD üzerine hazırlayıp aslı gibi etiketler, donanım üreticilerinden elde ettikleri lisans numaralarını da pakete ekleyip pazarlarlar.

Hoca bunu günümüzdeki "çok ucuz ofis yazılımı lisansı" ya da "yalnız anahtar satıyorum" diyen satıcılara bağladı: bu anahtarlar donanım üreticilerine tanınan lisans havuzundan alınıp satılır ve büyük olasılıkla anlaşma bittiğinde ya da havuz kapandığında ucuza alınan lisans da iptal edilir. Bu yüzden bunların da taklit sayılabileceğini söyledi.

### 9.4 İnternet bankacılığı ve müşterinin satıcıyı kandırması

Hoca internet bankacılığını da kuruluş ile birey arasındaki bir tür ticaret, "para ticareti" olarak değerlendirdi: insanlar bankaya güvenip paralarını yatırır. İnternet bankacılığında paralar çalınabilir; bu bankanın değil, müşterinin hesap bilgilerini çalan soyguncuların işidir, ama yine bir B2C işlemi gibi görülebilir.

Ters yönde müşteri de satıcıyı kandırabilir, özellikle kredi kartıyla ödemelerde. Hoca bunun artık çok azaldığını, ancak çalıntı kartlarla ya da şifresi bilinen kartlarla yapılabildiğini söyledi. 3D Secure varsa burada artık pek sorun yaşanmaz. Saygın ve güvenilir ticaret firmaları kendi sayısal yetki belgelerine sahiptir, SET protokolünü ve üç düzeyli güvenliği kullanır; bunlarla yapılan e-ticaretin daha güvenli olduğu söylenebilir. Bilinmeyen, hele sertifikası olmayan yerlerden kaçınmakta fayda vardır. Satıcılar da kendilerini kredi kartı sahteciliğine karşı korumalıdır.

### 9.5 Bireyler arası e-ticaret (C2C)

Satıcı da tüzel kişi değil bir birey ise bireyler arası (customer to customer, C2C) e-ticaret söz konusudur. Burada iki taraf da sahteci olabilir ve iki tarafın da gerçek olduğuna dair bir kanıt yoktur; iki tarafın da sertifikası yoktur ve olması da beklenmez. Hoca bunu, kurumsal kimlikli bir satıcıyla yapılan ticaretten bile daha riskli, en tehlikeli e-ticaret türü olarak nitelendirdi.

Ödemeyi güvence altına almak için çeşitli düzenlemeler vardır. Örneğin bazı ilan ve pazar yeri platformlarında para platforma verilir, platform parayı bekletir ve alıcı ürünü aldığını onaylamadan para satıcıya aktarılmaz. Hoca, pazar yerlerinin otomatik onay gibi uygulamalara geçtiğini, ürün kargoya verildiği anda onay çıkabildiğini ve bunun da gariplikler doğurabildiğini söyledi. C2C'de de B2C'de olduğu gibi ayıplı, taklit, eksik ve sahte ürün gönderilmesi sorunları yaşanabilir.

## 10. E-ticarette Tarafların Mutluluğu

Slayttaki açıklamaya göre bir ticaretin ticaret sayılabilmesi ve sürdürülebilir olması için alıcı ve satıcının yapılan alışverişten mutlu olması gerekir. Güvenlik sorunu olmadığını bilen bir müşteri, güvendiği bir satıcıdan ürün almayı her zaman yeğler. Çünkü (ekrandan, 00:50:00):

- Ürünü seçmek için satıcının yerine gitmesi gerekmez. Özellikle, özellikleri bilinen ve ölçünlere uygun üretilmiş ürünleri elle inceleyip denemek gerekmediğinden e-ticaret sitesinden seçmek yeterlidir. Oturduğu yerden istediği zaman sipariş vermek ve ürünün ayağına kadar getirilmesi müşteriyi mutlu eder.
- Satın aldığı ürünü hiçbir gerekçe belirtmeden değiştirebileceğinin garantisini bilmesi, alışveriş kararını daha kolay ve hızlı vermesini sağlar. Geri gönderme yükünün satıcıya ait olması kararı daha da etkiler. Bu kolaylık birden fazla ürün sipariş etmenin yolunu açar; müşteri beğenmediklerini belli süre içinde geri gönderebilir ve ürünleri ve satıcıyı ayağına kadar getirmiş duygusuyla mutlu olur.
- E-ticarette satıcı ürünleri sergilemek için geniş alanlara gereksinim duymaz; hatta ürünleri kendi deposunda saklaması da gerekmeyebilir, siparişi aldıktan sonra üreticiden isteyebilir. Bu, işletme giderlerinde çok büyük tasarruf sağlar. Satış elemanı ve ortamı ısıtma, soğutma, aydınlatma gibi giderler de olmaz. Giderleri çok azalan bir kuruluş için e-ticaretle ürün ya da hizmet satmak son derece kârlıdır.
- E-ticaretle dünya geneline ürün ve hizmet satılabilir; dolayısıyla firmaların ciroları artar. Bu da satıcı için mutluluk vericidir.

Hoca gerekçesiz iade hakkının e-ticaret kanunu gereği tanındığını belirtti. İade kargosunun ücretsiz olduğu bir dönemde, örneğin ayakkabı alınırken bütün numaralardan birer tane sipariş edilip uymayanların geri gönderildiğini; kargo firmalarının buna tepki göstermesi ve iade kargolarının ücretsiz olmaktan çıkmasıyla bu alışveriş tarzının azaldığını anlattı. Satıcı tarafında ise fiziksel mağaza giderlerinin yerine pazar yerlerinin aldığı komisyonlar devreye girer; yine de e-ticaretin fiziksel satışa göre oldukça kârlı olduğu söylenebilir.

> **Ek bilgi (derste anlatılmadı):** Türkiye'de mesafeli satışlarda tüketicinin gerekçe göstermeden cayma hakkı, büyük olasılıkla 6502 sayılı Tüketicinin Korunması Hakkında Kanun ve Mesafeli Sözleşmeler Yönetmeliği ile düzenlenir ve genel kural olarak 14 gündür.

## 11. E-ticaretteki Etik ve Hukuk Sorunları

### 11.1 Güvenliğin sağlanması

Hocaya göre alışveriş ortamının, yani ticaretin güvenliğinin sağlanması doğal ve doğrudan olarak kamunun görevidir; internetteki ticaretin güvenliğini sağlamak aslında müşterinin ya da satıcının görevi değildir. E-ticaretin güvenliği için önemli çalışmalar yapılmış, SET gibi protokoller oluşturulmuştur. Bir müşteri kimlik ve kredi kartı bilgilerini çaldırmadığı sürece büyük bir sorun yaşamaz.

Kullanıcının kimlik bilgileri genellikle hesap bilgilerinin ve parolaların çalınmasıyla ele geçirilir. Hoca bunun bilişim suçları başlığında işlendiğini hatırlattı: soyguncu, müşterinin bilgisayarına casus program yükleyerek internet bankacılığı bilgilerini alabiliyordu ve bu konular davalarda çok tartışılıyordu. Buna karşı tek kullanımlık parolalar, cep telefonuna onay gönderme ve üç düzeyli güvenlik gibi pek çok yöntem geliştirildi.

Genel olarak internette güvenlik kaynaklı bir soygun olursa, müşterinin açık bir kastı ya da belirgin bir kusuru yoksa (örneğin şifresini kendisi vermemişse) sorumluluk satıcı tarafa yüklenir; ticaretin doğası gereği gerekli güvenlik önlemlerini satıcının sağlaması gerektiği kabul edilir. Ancak hoca, müşterinin kendi hesabını bilerek ve isteyerek soydurabileceğinin de göz ardı edilmemesi gerektiğini vurguladı.

### 11.2 Satıcının güvenilirliği

B2C ve C2C'de dolandırıcılık hikâyeleri çok yaygındır. Slayttaki değerlendirme şöyledir (ekrandan, 00:55:00):

- **Ayıplı ürün gönderilmesi:** Bir satıcı bilerek ayıplı ürün gönderiyorsa o satıcının dolandırıcı olduğu söylenebilir. Ürünü geri gönderip yenisini istemek boşuna bir çaba olur; hukuk yolunu denemek de çok anlamlı değildir. Satıcının ilk tepkisi "Biz sağlam ürün gönderdik; siz onu bozdunuz." olacaktır. Müşteri ürünü teslim alırken yanında tarafsız bir tanık olmayacağı için bu savı çürütmesi çok zordur. Satıcı ile müşterinin farklı ülkelerde olması durumunda mahkemede hak aramak daha da zordur. Aynı ülkede yaşanan olaylarda aynı firmanın benzer şekilde ayıplı ürün sattığı kanıtlanırsa mahkeme suçlu bulabilir.
- **Taklit ürün gönderilmesi:** Bir satıcının web sayfasında asıl ürünü sergileyip müşteriye taklidini göndermesi açıkça dolandırıcılıktır. Bu tür satıcıların e-ticaret sitesi kurmaktaki amaçları dolandırıcılıktır; bunlarla hukuk yolu kullanılarak başa çıkmak zordur. Firmalarını kısa süre sonra kapatıp yeni adla yeni e-ticaret sitesi açarlar.
- **Eksik ürün gönderilmesi:** Eksik ürün gönderen satıcılar için de aynı değerlendirme yapılabilir.
- **Sahte ürün gönderilmesi:** Disk yerine demir kütle, ilaç yerine kireç tozu gönderen firma için dolandırıcılık sıfatı bile yetersiz kalır.

Hoca ayıplı ürün konusunu açtı: Satıcı "servis sürecinden geçelim" diyerek süreci sürekli uzatabilir. Müşteri ürünü teslim alırken yalnız kargo paketinin bozuk ya da hasarlı olup olmadığına dair tutanak tutturabilir; koliyi ve ürünün kendi kutusunu teslim anında açma imkânı yoktur ve bozukluğu ancak açtıktan sonra fark eder. Bu yüzden "siz bozdunuz" itirazını çürütmek zordur; ürün başka bir ülkeden alınmışsa bu daha da zordur. Hoca, bazı uluslararası pazar yerlerinin bu tür anlaşmazlıklarda müşteri lehine hızla para iadesi yaptığını ya da parayı satıcıya aktarmadığını örnek verdi. Aynı ülkedeyse mahkeme süreçlerinden geçilir: belli bir tutara kadar tüketici hakem heyeti, daha yüksek tutarlarda tüketici mahkemelerinde uzun sürebilecek bir dava süreci söz konusudur.

Taklit ürün satan siteler kısa süre satış yapıp kapanır, sonra başka bir site açıp başka bir şey satar. Hoca günümüzde pazar yerlerindeki yorumların daha düzgün olmaya başladığını, eksik ürün gönderen satıcıların hızla fark edilebildiğini; ama bu satıcıların dükkânı kapatıp başka bir dükkân açarak yollarına devam edebildiğini söyledi.

### 11.3 Müşteriler neden bu tuzağa düşer?

Slayttaki "Değerlendirme" bölümüne göre müşterileri bu tür yerlerden alışveriş yapmaya yönelten iki neden vardır (ekrandan, 00:55:00):

1. Fiyatların her yerden ucuz olması.
2. Başka yerlerde bulamadıkları ürünleri burada bulmaları.

Müşteri, ürünün ucuz olmasının bir nedeni olduğunu düşünmelidir; bu arada satıcı hakkında genel ağda araştırma yapmasında yarar vardır. Başka yerlerde satılmayan bir ürünün bu tür bir sitede bulunmasının iki nedeni olabilir: ya ürünün yasal olarak satışı yoktur ya da satıyoruz dedikleri ürün sahtedir (ekrandan, 00:55:00). Hoca bu iki nedenin müşterileri "merdiven altı" e-ticaret sitelerine yönlendirebildiğini söyledi. Pek çok insan dolandırılır ve dolandırıldığını söyleyemez; satıcılar da bu açığı bilerek dolandırıcılık yapar. Bireyler arası ticarette durum daha da kötüdür, yaşanan sorunlar ise aşağı yukarı aynıdır.

### 11.4 Müşterinin güvenilirliği

Bazen müşteri kılığındaki kişiler satıcıları dolandırır ve bunu örgütlü olarak da yapabilir; özellikle internet bankacılığı dolandırıcılıkları örgütlü yapılabilir. Böyle durumlarda satıcı firmaların çeşitli önlemler alması gerekir. Ancak bu kişiler genellikle ülke dışında konuşlandığı için yasalardan kolayca kaçabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:06:03): İpek Yolu'ndaki kervansaray ve hanlarda kervanlara verilen yatak, yemek, hamam, nalbant gibi hizmetler belli bir süre ücretsizdi. Bu hizmetlerin parasını kim karşılıyordu?

> **Cevap (derste verildi):** Bu hizmetlerin ve askerlerin sağladığı güvenliğin amacı ticareti geliştirmek, korumak ve ticaretten vergi toplamaktı. Yani ücretsiz görünen hizmetler, sonunda o ticaretten elde edilen vergilerle finanse ediliyordu.

**Soru 2** (derste sözlü, 00:37:45): E-ticarette güven esastır; peki e-ticaretin tarafları kimlerdir?

> **Cevap (derste verildi):** Üç sınıf vardır: kuruluşlar arası (B2B; taraflar birbirini tanır, sorun az), kuruluş ile birey arası (B2C; en sık sorun yaşanan alan) ve bireyler arası (C2C; iki tarafın da sertifikası olmadığı için en riskli tür).

**Soru 3** (derste sözlü, 00:55:42): Müşteriler neden az bilinen, güvenilirliği belirsiz e-ticaret sitelerinin tuzağına düşer?

> **Cevap (derste verildi):** İki nedenle: fiyatın her yerden çok daha ucuz olması ve başka yerde bulunamayan bir ürünün orada bulunması. Ucuzluğun bir nedeni olduğu düşünülmeli ve satıcı araştırılmalıdır; başka yerde satılmayan ürün ya yasal olarak satılmıyordur ya da sahtedir.

## Dersin Toparlaması

Ders, ticaretin üç ilkesini (güvenli ortam, karşılıklı güven, tarafların mutluluğu) e-ticarete uyguladı. Güvenli ortam ilkesi İpek Yolu'ndaki kervansaraylardan başlayarak bugünkü ağ güvenliğine bağlandı: TCP/IP kapalı bir ağ için tasarlandığından asıllama içermez; SYN, IP kandırması, ISN tahmini, aradaki adam, RIP, ICMP ve DNS saldırıları bu eksiklikten yararlanır. IPv6'nın asıllama ve şifreleme başlıkları, SSL'in asimetrik anahtar değişimi ile simetrik şifrelemeyi birleştiren yapısı ve ödemeyi aracı bir ödeme kanalı ile çift imza üzerinden yürüten SET protokolü bu soruna verilen yanıtlardır. Ancak SSL güvenli bir tünel kursa da karşıdaki satıcının dürüst olduğunu garanti etmez; 3D Secure gibi önlemler ise müşteri tarafındaki kart sahteciliğini azaltır.

Güven ve mutluluk ilkeleri ise B2B, B2C ve C2C ayrımı üzerinden tartışıldı. Az bilinen satıcılarda ayıplı, taklit, eksik ve sahte ürün gönderilmesi; bunlara karşı hukuk yolunun zorluğu; müşteriyi bu sitelere yönelten ucuzluk ve bulunmazlık; müşteri tarafındaki örgütlü dolandırıcılık dersin etik ve hukuk boyutunu oluşturdu. Hoca sonraki derste bilişim hukuku ve adli bilişim konularına geçileceğini, dönem boyunca işlenen konularla ilgili kanunlara ve ticaret yasasına da dönemin sonunda bakılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
