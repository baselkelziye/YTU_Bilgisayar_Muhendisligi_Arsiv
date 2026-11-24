# Ders 11 Çalışma Özeti

## Genel Konular

- E-ticarete giriş (ekrandan, 00:05:00)
  - Büyük firmalar 1970'lerden beri bilgisayarlar arası iletişim yoluyla ticaret yapar. Bu ticaret özel, kapalı ağlar (VAN: Value Added Network) üzerinden yürütülür.
  - Genel ağın (internetin) yaygınlaşmasıyla bireysel kullanıma yönelik e-ticaret gelişmiş ve çok hızlı büyümüştür. Alışverişi kolaylaştıran e-ticaret, beraberinde değişik sorunlar da getirmiştir.
  - Büyük kuruluşların VAN üzerinden, EDI belgeleri kullanarak yaptığı e-ticarette yeterli güvenlik vardır ve taraflar birbirini çok iyi tanır. Dersin ağırlığı son kullanıcıya yönelik e-ticarettir.
- Ticaretin üç temel ilkesi (ekrandan, 00:05:00)
  - Ticaret güvenli ortam ister.
  - Alıcı ve satıcının birbirine güvenmesi gerekir.
  - Alan ve satan alışverişten mutlu olmalıdır.
- Tarihsel örnek: İpek Yolu ve kervansaraylar
  - İpek Yolu üzerindeki devletler kervanlar için yollar yaptırmış, gerektiğinde güvenlik için asker görevlendirmiş, konaklama için kervansaray ve hanlar kurmuştur.
  - Türkler yaklaşık 35-40 km'de bir kervansaray yapmıştır; bu, yürüyen bir kervanın günde 7-8 saatte aldığı yoldur (bir tür "etap noktası").
  - Yerleşim yeri dışındaki yapıya kervansaray, içindekine han denir. Yatakhane, ahır, yemekhane, hamam, ilaç, kunduracı, nalbant gibi hizmetler belli bir süre ücretsiz verilir.
  - Bu hizmetlerin amacı ticareti geliştirmek, korumak ve ticaretten vergi toplamaktır; yani hizmetler sonunda ticaretten alınan vergilerle finanse edilir.
- TCP/IP protokolünün yapısı ve güvenliği (ekrandan, 00:10:00 ve 00:15:00)
  - TCP/IP, ABD Savunma Bakanlığınca (DoD) geliştirilmiştir. Üst katman TCP veriyi paketlere ayırıp alıcıda birleştirir; alt katman IP paketleri adrese iletir.
  - Katmanlar: uygulama, taşıma, genel ağ (internet) katmanı, ağ erişim (veri bağı) katmanı ve fiziksel katman.
  - TCP/IP kapalı bir ağ (ARPANET) için tasarlandığından güvenlik göz ardı edilmiştir; internette yaygınlaşınca açıklar ortaya çıkmıştır.
  - Saldırı türleri: SYN saldırısı, IP kandırması, sıra numarasını (ISN) tahmin etme, kaynak yönlendirme, bağlantıyı ele geçirme (aradaki adam), yönlendirme (RIP) saldırısı, ICMP saldırısı, alan adı hizmeti (DNS) saldırısı, tekil kimliğin yokluğu.
- IPv6'nın güvenlik başlıkları
  - IPv4 (1981) asıllama konusunda yetersizdir; 1990'larda IPv6 tasarlanmıştır.
  - IPv6'da iki güvenlik başlığı vardır: Authentication Header (asıllama başlığı) göndericinin gerçek kimliğini doğrular; Encapsulating Security Payload Header (şifreleme başlığı) mesajı yalnız gerçek alıcının görebilmesini sağlar.
  - İki tarafın asıllama ve şifreleme için anahtar ve algoritma üzerinde önceden anlaşmasına güvenlik birliği denir. Alıcı her gönderici için bir SPI (Security Parameter Index, güvenlik değişken dizini) belirler. Anahtar değişimi için Diffie-Hellman gibi öneriler vardır, ama kesinleşmiş bir standart olmadığı söylendi.
- SSL ile güvenli iletişim
  - Netscape'in geliştirdiği SSL (Secure Socket Layer), şifrelemede RSA algoritmasını kullanır, sertifika tabanlıdır ve TCP/IP üzerinde çalışır. Bugün SSL/TLS standarttır; HTTPS de buna dayanır.
  - SSL iletişimin gizliliğini ve bütünlüğünü sağlar.
  - Çalışma: el sıkışmada sunucu, sayısal yetki belgesi (sertifika) ile açık anahtarını istemciye gönderir; istemci sertifikayla sunucunun kimliğini doğrular. Asimetrik yöntemle (örneğin RSA) oturum anahtarı belirlenir; oturum boyunca trafik simetrik şifrelemeyle korunur.
  - Hocaya göre SSL'in ilk iki sürümünde yalnız sunucu asıllaması, üçüncü sürümde hem istemci hem sunucu asıllaması yapılabilir.
- Güvenli elektronik ödeme: SET (ekrandan, 00:25:00 ve 00:35:00)
  - 1996'da 11 teknoloji firmasınca tasarlanan SET'in (Secure Electronic Transaction) ana ilkesi: ödemenin müşteri tarafından satıcıya doğrudan değil, bir aracı kuruluş (ödeme kanalı) üzerinden yapılması.
  - Hem müşteri hem satıcı için sayısal yetki belgesi (SYB) gerekir; böylece müşteri, satıcı ve banka arasında güvenilir ve gizli iletişim kurulur. Satıcı kredi kartı bilgisini göremez, yalnız kartın çalıntı ya da sahte olup olmadığına karar verebilir.
  - Pratikte satıcı için sertifika şarttır; her müşteriye sertifika vermek olanaklı olmadığından müşteri asıllaması kredi kartı bilgileri üzerinden yapılır.
  - SET'in ilkeleri: sipariş ve ödemenin gizliliği, ödeme ve hizmet verilerinin bütünlüğü, kredi kartı ve müşteri hesabının asıllanması, satıcının asıllanması.
  - Altı taraf: kart sahibi müşteri, satıcı, kartı veren banka, satıcının bankası, ödeme kanalı, sertifika yetkilisi.
  - Sipariş bilgisi ve ödeme bilgisi ayrı ayrı özetlenir (hash), sonra birleşik özet şifrelenerek çift imza oluşturulur. Böylece taraflar alışverişi inkâr edemez.
- SSL'in sorunları ve 3D Secure (ekrandan, 00:25:00)
  - SSL müşteriyi kulak misafirlerinden korur ama sahte satıcıdan korumaz. Sahte siteler ya tanınmış bir satıcının taklidini yaparak ya da tümüyle yalancı bir site kurarak dolandırır.
  - Müşteri de satıcıyı sahte ya da çalıntı kartla dolandırabilir. Buna karşı üç boyutlu güvenlik (3D Secure) geliştirilmiştir: ödeme anında müşterinin cep telefonuna bir sayı gönderilir, müşteri bunu ödeme ekranına girer.
- E-ticarette tarafların birbirine güvenmesi (ekrandan, 00:40:00)
  - B2B (kuruluşlar arası): taraflar birbirini tanır, önemli sorun beklenmez.
  - B2C (kuruluş-birey): en çok sorun yaşanan alan; hem satıcı hem müşterinin ödemesi gerçek olmayabilir.
  - C2C (bireyler arası): iki taraf da sahteci olabilir, iki tarafın da sertifikası yoktur; en riskli türdür.
  - Az bilinen e-ticaret firmalarıyla yaşanan sorunlar: ayıplı ürün, taklit ürün, eksik ürün ve sahte ürün gönderilmesi; ucuz "lisanslı" işletim sistemi ve ofis yazılımı satışları.
  - İnternet bankacılığı da bir tür B2C ilişkisidir; paralar müşteri bilgilerini çalan soyguncularca çalınabilir.
- E-ticarette tarafların mutluluğu (ekrandan, 00:50:00)
  - Müşteri için: satıcıya gitmeden seçim, istediği zaman sipariş, ayağına teslim; gerekçesiz iade hakkı ve iade kargosunun satıcıya ait olması karar vermeyi kolaylaştırır.
  - Satıcı için: dükkân, depo, satış elemanı, ısıtma-soğutma-aydınlatma gibi giderlerden tasarruf; dünyaya satış yapabilme ve ciro artışı.
- E-ticaretteki etik ve hukuk sorunları (ekrandan, 00:55:00)
  - Güvenliğin sağlanması: ticaretin güvenliğini sağlamak kamunun görevidir. Müşterinin açık kastı ya da belirgin kusuru yoksa güvenlik kaynaklı soygunda sorumluluk satıcı tarafa yüklenir; ama müşterinin bilerek kendi hesabını soydurabileceği de göz ardı edilmemelidir.
  - Satıcının güvenilirliği: ayıplı, taklit, eksik ve sahte ürün gönderen satıcılar dolandırıcıdır; hukuk yolu zordur.
  - Müşterinin güvenilirliği: müşteri kılıklı kişiler, kimi zaman örgütlü olarak, satıcıları dolandırabilir; çoğunlukla ülke dışında konuşlandıkları için yasalardan kaçabilirler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ticaretin güvenliği kervansaraylardan bugüne aynıdır
  - İpek Yolu'ndaki devletlerin yol, asker ve kervansaray hizmeti ile e-ticaretteki güvenlik ve ödeme güvenliği aynı amaca hizmet eder: ticareti geliştirmek ve korumak.
- TCP/IP'nin doğasında asıllama yoktur
  - Saldırıların çoğu asıllama eksikliği üzerine kurgulanır; çünkü TCP/IP kapalı ve güvenli kabul edilen bir ağ için tasarlanmıştır.
- SSL güvenli bir tünel kurar ama karşıdakinin dürüst olduğunu garanti etmez
  - Güvenli bağlantıyla bağlanılan site bile sahte ya da dolandırıcı olabilir.
- Sertifikası olmayan satıcıdan uzak durulmalıdır
  - Sertifikanın doğruluğu bile tartışılabilir, ama sertifikası olmayan bir yere güvenmek çok büyük bir yanlıştır.
- Ayıplı ya da taklit ürünü bilerek gönderen satıcıdan düzgün ürün beklemek saflıktır
  - Satıcının ilk tepkisi "biz sağlam gönderdik, siz bozdunuz" olur; müşterinin bunu çürütmesi çok zordur.
- Çok ucuz ya da başka yerde bulunmayan ürün sorgulanmalıdır
  - Ucuzluğun bir nedeni vardır; başka yerde satılmayan ürün ya yasal olarak satılmıyordur ya da sahtedir.

## Kısa Tekrar Notları

- Ticaretin üç ilkesi: güvenli ortam, karşılıklı güven, iki tarafın da mutluluğu.
- VAN: büyük firmaların EDI belgeleriyle ticaret yaptığı kapalı, güvenli ağ.
- TCP/IP saldırıları: SYN, IP kandırması, ISN tahmini, kaynak yönlendirme, aradaki adam, RIP, ICMP, DNS (alan çalma), tekil kimliğin yokluğu.
- ISN 32 bittir; üretim kuralı biliniyorsa tahmin kolaylaşır.
- Kayan pencere içindeki sıra dışı paket tampon bellekte tutulur, dışındaki reddedilir; aradaki adam bu eşzamansız durumdan yararlanır.
- IPv6 güvenlik başlıkları: AH (asıllama) ve ESP (şifreleme); ön anlaşma = güvenlik birliği, SPI ile tanımlanır.
- SSL: asimetrik yöntemle anahtar değişimi, sonra simetrik şifreleme; gizlilik ve bütünlük sağlar; HTTPS SSL/TLS'ye dayanır.
- Bilgi güvenliğinin dört temel ilkesi: asıllama, gizlilik, bütünlük, inkâr edilemezlik.
- SET: ödeme aracı kuruluş (ödeme kanalı) üzerinden; altı taraf; çift imza; satıcı kart bilgisini görmez.
- 3D Secure: ödeme anında cep telefonuna gelen kodun girilmesi.
- B2B en güvenli, B2C en çok sorun yaşanan, C2C en riskli e-ticaret türüdür.
- Sorunlu ürünler: ayıplı, taklit, eksik, sahte.

## Detaylı Açıklamalar

- **E-ticaretin gelişimi ve ticaretin ilkeleri.** Büyük firmalar 1970'lerden beri özel ve kapalı VAN ağları üzerinden EDI belgeleriyle ticaret yapar. Bu ağlarda taraflar birbirini tanıdığı ve ağ kapalı olduğu için güvenlik sorunu azdır. İnternetin yaygınlaşmasıyla son kullanıcıya yönelik e-ticaret büyümüş, bununla birlikte yeni sorunlar ortaya çıkmıştır. Her ticaretin üç ilkesi vardır: güvenli ortam, alıcı ile satıcının birbirine güvenmesi ve iki tarafın da alışverişten memnun olması. Hoca güvenli ortam ilkesini İpek Yolu ile açıkladı: devletler kervanlar için yol, asker ve kervansaray sağlamış, yerleşim dışındaki yapılara kervansaray, içindekilere han denmiştir. Bu hizmetler kervanlara belli bir süre ücretsiz verilmiş, ama ticaretten alınan vergilerle finanse edilmiştir. Bugünkü e-ticarette bunun karşılığı iletişim güvenliği ve ödeme güvenliğidir.

- **TCP/IP saldırıları.** Slayttaki tanımlar şöyledir (ekrandan, 00:10:00 ve 00:15:00):
  - SYN saldırısı: TCP/IP'de oturum üç aşamada kurulur. Sunucu dinleme konumunda istemciden istek (SYN) bekler, isteği alan sunucu 75 saniyeye kadar bekleme durumunda kalır ve sunucular genellikle ortalama 5 isteği karşılayacak durumdadır. Saldırgan peş peşe bağlantı isteği göndererek sunucuyu meşgul eder ve hizmet vermesini engeller (SYN kandırması).
  - IP kandırması: saldırgan gönderdiği paketin içine kendi adresi yerine sahte bir IP adresi koyar; alıcıdaki IP katmanı bunu gerçek adres sayar. Genellikle hizmet aksatma (DDoS) amacıyla kullanılır.
  - Sıra numarasını tahmin etme: TCP bağlantısındaki başlangıç sıra numarası (ISN) 32 bittir, bu yüzden tahmin olasılığı düşüktür. Ancak numara belli bir kuralla üretiliyorsa tahmin kolaylaşır. Unix çekirdeğinin ISN'yi belli bir kurala göre hesapladığı, bir önceki ISN biliniyorsa sonrakinin hesaplanabileceği açıklanmıştır; saldırganlar çok sayıda ISN dener.
  - Kaynak yönlendirme: yanıtın hangi yolla, hangi IP'ye ulaşacağını gönderenin belirlemesidir. Günümüz yönlendiricileri bunu belirleyebildiği için artık sorun değildir.
  - Bağlantıyı ele geçirme (aradaki adam): saldırgan bağlantıdaki iki bilgisayarın iletişim yolu üzerine girer, asıllamanın sürmesini sağlayıp bağlantıyı ele geçirir ve iki taraftan gelen paketleri birbirine aktarır. Hoca bunun TCP'nin eşzamansız (desynchronized) durumundan beslendiğini anlattı: gelen paketin sıra numarası beklenenden farklıysa paket kayan pencerenin içindeyse tampon bellekte tutulur, dışındaysa reddedilir. Taraflar bu durumda paketleri reddetmeye devam ederken saldırgan kendi hazırladığı sahte paketleri doğru sıra numarasıyla göndererek iletişime ekleyebilir.
  - Yönlendirme saldırısı: TCP/IP'de zorunlu olmayan ama sıkça kullanılan RIP (Routing Information Protocol), ağdaki en kısa ya da önerilen yolu tanımlar ve asıllama içermez. Saldırganlar paketlerin geldiği ve gideceği adresleri değiştirip paketleri ele geçirebilir ve içeriğini değiştirebilir.
  - ICMP saldırısı: alıcıyı uyarmak için gönderilen ICMP mesajları (ping) asıllama bilgisi içermediği için hizmet aksatma saldırılarında kolayca kullanılır.
  - DNS saldırısı: DNS alan adlarını IP adreslerine dönüştürür. Saldırgan "alan çalma" yöntemiyle bir sunucunun ya da sayfanın IP adresini ele geçirir, DNS sunucusuna erişip karşılık gelen IP'yi değiştirir; kullanıcı farklı bir sunucuya yönlendirilir.
  - Tekil kimliğin yokluğu: başta her bilgisayara ayrı bir IP adresi verileceği düşünülmüş ama adres yetmemiştir. Günümüzde konuma bağlı ya da geçici adresler kullanılır ve bunlar sunucular ya da adres dönüştürücülerce değiştirilir; bu yüzden yere bağlı ya da geçici IP'ye dayanan güvenlik sistemleri zayıf kalır.

- **IPv6 ve güvenlik birliği.** IPv6'daki Authentication Header göndericinin gerçek kimliğini, Encapsulating Security Payload Header ise mesajın yalnız gerçek alıcıca görülmesini sağlar. Bunun için iki taraf anahtar ve algoritma konusunda önceden anlaşmalıdır (güvenlik birliği); alıcı her gönderici için bir SPI belirler.

- **SSL'in çalışması.** İstemci ile sunucu arasındaki veri simetrik şifrelemeyle korunur. Simetrik anahtar ise asimetrik bir yöntemle (örneğin RSA) iletilir: sunucu sertifikasıyla açık anahtarını gönderir, istemci sertifikadan sunucunun kimliğini doğrular ve yanıtını bu açık anahtarla şifreler. El sıkışma tamamlanınca oturum boyunca trafik simetrik şifrelenir. SSL iletişimin gizliliğini sağlar, çünkü iki taraf arasında güvenli bir tünel kurar; ama hoca bilgi güvenliğinin dört ilkesini (asıllama, gizlilik, bütünlük, inkâr edilemezlik) hatırlatarak SSL'in sahte satıcıya karşı koruma sağlamadığını vurguladı.
  - Ders sonrası not: Hoca TCP'nin açılımını "Transfer Control Protocol" olarak söyledi; doğrusu "Transmission Control Protocol"dür. Altyazıda "RSI" ve "TSL" olarak geçen adlar RSA ve TLS'dir.

- **SET ile güvenli ödeme.** Slayttaki tanıma göre SET'in ana ilkesi ödemenin satıcıya doğrudan değil, bir ödeme kanalı üzerinden yapılmasıdır (ekrandan, 00:25:00). Hocanın anlattığı alışveriş süreci dokuz adımdır: müşteri satıcının sayfasına bağlanır; sipariş ve ödeme bilgisi iki parça olarak gönderilir; satıcı içeriğini göremediği kart bilgisini kendi bankasına iletir; satıcının bankası kartı veren kuruluştan onay (provizyon) ister; kartı veren kuruluş bankaya, banka da satıcıya onay gönderir; satıcı siparişi tamamlayıp müşteriye onay belgesi gönderir; satıcı bankadan işlem kayıtlarını alır; son olarak ürünü ve fişi ya da faturayı gönderir. İki parçanın birleştirilmesi için sipariş ve ödeme bilgileri ayrı ayrı özetlenir, bu özetlerden çift imza üretilir. Satıcı, sipariş bilgisi, çift imzalı onay ve ödeme özetiyle bankadan ödemesini alır.
  - SET çalışma biçimi diyagramı (ekrandan, 00:35:00): "Güvenli Elektronik İşlem SET" bölgesinde müşteri, satıcının web sayfası ve ödeme kanalı; "Finansal ağ" bölgesinde ödeme yöneticisi ve kartı veren kuruluş; "Satıcı" bölgesinde satıcının web sayfası ve satıcı bilgisayarı vardır. Çevrim içi yolda müşteri web sayfasıyla, web sayfası ödeme kanalıyla, ödeme kanalı ödeme yöneticisiyle, ödeme yöneticisi kartı verenle haberleşir. Alternatif yolda müşteri telefon ya da havaleyle satıcıyla doğrudan iletişim kurar, satıcı da finansal ağdaki ödeme yöneticisine bağlanır (hoca bunu posta ile sipariş gibi düşünülebileceğini söyledi).

- **Tarafların birbirine güvenmesi ve sorunlu ürünler.** Az bilinen e-ticaret firmalarıyla yaşanan sıkıntılar slaytta şöyle sıralanır (ekrandan, 00:40:00): ayıplı ürün (kullanılmış, bozuk, arızalı ya da tamir edilmiş ürün; bilerek gönderen firmadan yenisini beklemek saflıktır), taklit ürün (dış görünüşü bilinen ürüne benzer; gönderenin dolandırıcı olduğu kesindir), eksik ürün (paketteki adet sayfada yazandan azdır) ve sahte ürün (disk yerine demir kütle, ilaç yerine toz kireç, kitap yerine kitabın kapağı). Slaytta ayrıca bazı firmaların lisanslı programları, özellikle işletim sistemlerini, ucuza sattığı anlatılır: işletim sistemi üreten firmalar donanım üreticilerine çoğaltma hakkı ve her kopya için lisans numarası verir; satıcılar kopyaları CD ya da DVD'ye hazırlayıp asıl gibi etiketler ve donanım üreticilerinden elde ettikleri lisans numaralarını pakete ekler. Hoca, çok ucuz satılan ofis yazılımı anahtarlarının da bu şekilde elde edildiğini ve anlaşma bittiğinde büyük olasılıkla iptal edileceğini söyledi.

- **Etik ve hukuk sorunları.** Güvenliğin sağlanması kamunun görevidir; SET gibi çalışmalar yapılmıştır ve müşteri kimlik ve kart bilgilerini çaldırmadıkça büyük sorun yaşamaz. Hesap bilgileri ve parolalar genellikle casus programlarla çalınır; buna karşı tek kullanımlık parolalar, cep telefonuna onay ve üç düzeyli güvenlik gibi yöntemler geliştirilmiştir. Müşterinin açık kastı ya da belirgin kusuru yoksa sorumluluk satıcı tarafa yüklenir. Satıcının güvenilirliği konusunda slayt şunu söyler (ekrandan, 00:55:00): ayıplı ürün gönderen satıcının ilk tepkisi "biz sağlam gönderdik, siz bozdunuz" olur; müşteri teslim alırken yanında tarafsız tanık olmadığından bunu çürütmesi çok zordur; taraflar farklı ülkelerdeyse hak aramak daha da zordur; aynı ülkede firmanın benzer şekilde ayıplı ürün sattığı kanıtlanırsa mahkeme suçlu bulabilir. Hoca aynı ülkedeki süreç için tüketici hakem heyeti ve tüketici mahkemelerini andı. Taklit ürün satan sitelerin kuruluş amacı dolandırıcılıktır; kısa sürede kapanıp yeni adla açılırlar. Müşterileri bu yerlere yönelten iki neden fiyatın her yerden ucuz olması ve başka yerde bulunmayan ürünün orada bulunmasıdır. Müşteri tarafında da örgütlü dolandırıcılık vardır ve bu kişiler çoğunlukla ülke dışında olduğu için yasalardan kaçabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
