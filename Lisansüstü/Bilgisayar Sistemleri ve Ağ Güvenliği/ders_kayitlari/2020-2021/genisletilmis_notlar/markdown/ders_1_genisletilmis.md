# Ders 1 Genişletilmiş Notu: Bilgisayar Güvenliği Problemine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konusu ve Yaklaşımı
- 2. Bilgisayar Güvenliği Problemi Neden Var?
- 3. Zafiyet Sayıları: 2019'un En Çok Zafiyetli Ürünleri
- 4. Örnek Olay: Zoom İstemcisi
- 5. Erişim Denetimi ve Referans Monitör
- 6. Rekabet Baskısı ve Kullanıcı Onayı
- 7. Dersin Hedefleri ve Konu Başlıkları
- 8. Sistemler Neden Ele Geçirilir?
- 9. Sunucu Tarafı Saldırılar ve Veri Kaybı
- 10. Zafiyet Pazarı
- 11. Hangi Koda Güvenebiliriz? Thompson'ın Arka Kapısı
- 12. Güven Zinciri ve Trusted Computing Base

## 1. Dersin Konusu ve Yaklaşımı

Dersin konusu bilgisayar ağları ve sistem güvenliğidir. Hoca dersi iki yönlü tarif etti: bir yandan güvenliğin temelleri öğrenilecek, öbür yandan hem sistemler hem de ağ protokolleri açısından güvenlik tehdidi oluşturan unsurların üzerinden geçilecek ve bunların nasıl oluştuğu görülecek. Bu tehditler hayatımıza birdenbire girmemiştir. Sistemlerde bazı eksikler, bazı sıkıntılar vardı; bunlar bulunup kötü amaçla kullanılınca bu durumlarla karşılaşmaya başladık. Dersin akışı da buna göre kuruludur: önce zafiyetin nasıl oluştuğu, sonra bu zafiyetten etkilenmemek için hangi yolun izlenmesi gerektiği.

Dersin sabit bir ders kitabı yoktur. Hocaya göre bu konu çok canlıdır, sürekli yeni gelişmeler olur; incelenecek başlıkları bir ders kitabından takip etmek "konuyu öldürmek" olur. Bu yüzden çevrim içi kaynaklar, yeri geldiğinde güvenlik forumlarındaki yazılar ve gönderiler de takip edilir. Slaytlar Stanford Üniversitesi'nin CS155 (Computer Security) dersinden alınmıştır; hoca bu slaytların her yıl örneklerle güncellendiğini söyledi.

Hoca, internette pek çok konunun açıklamasının ve örneğinin bulunduğunu, bunlardan bilgi edinmek için yararlanmanın sorun olmadığını, ama önerilen çözümlerin kendi çözümüne dönüştürülmeden kopyalanmasını beklemediğini belirtti.

## 2. Bilgisayar Güvenliği Problemi Neden Var?

Slaytta bilgisayar güvenliği probleminin üç nedeni sıralanıyor (ekrandan, 00:20:00):

- Lots of buggy software
- Social engineering is very effective
- Money can be made from finding and exploiting vulns.

### 2.1 Hatalı yazılım

En temel sebep, içinde hata barındırmayan yazılımın neredeyse olmamasıdır. Hatalar yanlış bir mantık kurgusundan, bazı API'lerin yanlış kullanılmasından ya da algoritmanın uç noktaları değerlendirmemesinden doğabilir. Ekrana tek satır yazan bir "Hello World" programının ötesindeki her yazılımda hata bulma ihtimali vardır.

Hata her zaman kötüdür, çünkü uygulamanın beklendiği gibi çalışmamasına yol açar. Ancak güvenlik açısından hatalar ikiye ayrılır. Bazı hatalar "zararsızdır": uygulama beklendiği gibi çalışmaz ama başka türlü de çalıştırılamaz. Bazı hatalar ise uygulamanın tasarlandığından farklı olarak, saldırganın istediği şekilde çalışmasına yön vermeye izin verir; uygulama saldırganın istediği yöne "evrilebilir". Asıl ciddi sıkıntı budur.

### 2.2 Sosyal mühendislik

Sosyal mühendislikte (social engineering) insanlar gönderilen mesajlarla belirli bir kalıpta davranmaya yönlendirilir. Mesaj kişinin merakına, zevkine ya da o an içinde bulunduğu ruh haline hitap eder; kişi normalde yapmayacağı bir işi yapar: bir linke tıklar, bir formu doldurur, bir sayfayı ziyaret eder. Bunun sonucunda ya kişinin özel bilgileri elde edilir ya da bilgisayarına, sonradan o sistemi kullanmayı, kontrol etmeyi veya oradan bilgi çekmeyi sağlayacak kötü niyetli programlar yerleştirilir.

### 2.3 Para kazanma motivasyonu

Hocaya göre son yıllardaki patlamanın arkasındaki temel motivasyon para kazanmaktır. Bu işin bir pazarı vardır; yapılan her saldırının, elde edilen her bilginin, ele geçirilen her sistemin parasal bir karşılığı vardır. Slaytta iki pazar gösteriliyor (ekrandan, 00:25:00):

1. Marketplace for exploits
2. Marketplace for owned machines (PPI)

Exploit, bir zafiyeti açığa çıkarıp onun üzerinden veri sızdırmayı ya da karşı tarafın kontrolünü ele geçirmeyi sağlayan koddur. Exploit'ler açık artırma mantığıyla satılır. Kontrolü ele geçirilmiş makineler (owned machines) için de, Android ya da Apple uygulama mağazalarına benzer pazar yerleri vardır.

PPI (pay-per-install) hizmetinde, hocanın benzetmesiyle "paralı yayın" gibi para ödenir: örneğin bin bilgisayar için ödeme yapılır ve bu bilgisayarlara istenen bir uygulama (kendi geliştirdiğiniz bir uygulama da olabilir) yüklenir. Bu uygulama da bir sisteme saldırır. Böylece saldırı, kime ait olduğu bile bilinmeyen bilgisayarlar üzerinden gerçekleşir. Hoca bunu mafyanın kendi işleri için ayak takımını kullanmasına benzetti: bir şey olduğunda "benim haberim yok" denebilir. Bu bilgisayarlar tablet, cep telefonu, dizüstü, masaüstü, daha kötüsü sunucu olabilir. Sahipleri saldırı için kullanıldıklarını çoğu zaman saldırıdan sonra fark eder ve hukuken ciddi biçimde zor duruma düşebilir.

Ele geçirilen her sistemden telefon numarası, kişi bilgileri, e-posta adresi ve şifresi, sosyal güvenlik numarası (bizdeki TC kimlik numarasına denk), özel yazışmalar, fotoğraflar, görüntüler ve ses kayıtları alınabilir; çünkü saldırgan artık o sistemin en yetkili kullanıcısı seviyesindedir. Ayrıca sistemdeki bilgiler kullanılamaz hâle getirilip yeniden açılması için fidye istenebilir.

Slaytın tamamında üçüncü bir madde de vardır: "Many methods to profit from owned machines" (ekrandan, 00:10:00). Hoca bunları özetle "exploit'ler, owned machines ve owned machines'ten kâr" diye üç temel sıkıntı olarak andı.

## 3. Zafiyet Sayıları: 2019'un En Çok Zafiyetli Ürünleri

Slaytın başlığı "Top 10 products by total number of 'distinct' vulnerabilities in 2019"dur. Değerler slayt küçük resminden okunmuştur (ekrandan, 00:10:00):

| Sıra | Ürün | Üretici | Tür | Zafiyet sayısı |
|---|---|---|---|---|
| 1 | Android | Google | OS | 414 |
| 2 | Debian Linux | Debian | OS | 360 |
| 3 | Windows Server 2016 | Microsoft | OS | 357 |
| 4 | Windows 10 | Microsoft | OS | 357 |
| 5 | Windows Server 2019 | Microsoft | OS | 351 |
| 6 | Acrobat Reader DC | Adobe | Application | 342 |
| 7 | Acrobat DC | Adobe | Application | 342 |
| 8 | cPanel | cPanel | Application | 321 |
| 9 | Windows 7 | Microsoft | OS | 250 |
| 10 | Windows Server 2008 | Microsoft | OS | 248 |

Hoca "distinct" kelimesinin altını çizdi: bu zafiyetler birbirinin türevi değildir, biri diğerini tetiklemez, birbirinden tamamen farklıdır. Debian Linux için, uzun sürüm döngüsüyle en güvenilir dağıtımlardan biri sayıldığını, ancak Ubuntu'nun ön yüz olup Debian'ın arka planda kalmasıyla bazı işlerin hızlandırılıp aceleye getirildiğini yorumladı. Windows 10 ile Windows Server 2016'nın sayıları aynıdır; biri masaüstü, biri sunucu sürümüdür.

> **Ders sonrası not:** Hoca 8. sıradaki ürünü "Control Panel" diye okudu; slaytta yazan ürün cPanel'dir (web barındırma yönetim paneli).

Bu sayıların her biri bir saldırı vektörüdür (attack vector). Her zafiyet, özelliğine bağlı olarak aktif bir saldırıya dönüştürülebilir; bu saldırıların bir kısmı da karşı taraftaki sistemin kontrolünün ele geçirilmesini sağlar. Hoca, dersten yaklaşık bir ay önce Windows Active Directory etki alanlarına şifre kullanmadan yönetici seviyesinde girilebilmesini sağlayan bir açığın gösterildiğini anlattı. İçinde ünlem, diyez, sayı, büyük-küçük harf olan uzun ve sık değiştirilen güçlü şifreler oluşturulsa bile, böyle bir zafiyet şifreye hiç gerek bırakmadan en yetkili kullanıcı olarak bağlanmaya izin verir.

> **Ek bilgi (derste anlatılmadı):** Hocanın andığı açık büyük olasılıkla Ağustos 2020'de yaması çıkan, Eylül 2020'de ayrıntıları yayımlanan "Zerologon" (CVE-2020-1472) zafiyetidir. Netlogon protokolündeki bir kriptografik hatadan yararlanarak etki alanı denetleyicisinde yönetici yetkisi elde etmeyi sağlıyordu.

## 4. Örnek Olay: Zoom İstemcisi

Slaytın başlığı "Why so many security bugs? Case study: Zoom client"tır. Kullanıcıların bir mahremiyet beklentisi vardır (Users have an expectation of privacy). Bir görüşme yapılırken, örneğin ders işlenirken, bu içerik sonradan yayımlanabilir de; ama her görüşme böyle değildir, özel iş görüşmeleri vardır ve insanlar belirli bir mahremiyet seviyesi ister. Slaytta üç sorun sıralanıyor (ekrandan, 00:40:00):

- (1) Problems with crypto (Marczak and Scott-Railton, April 2020)
- (2) How not to save a user click (J. Leitschuh, July 2019)
- (3) Disable MacOS hardened runtime (P. Wardle, April 2020)

### 4.1 Kriptografi sorunları

Kriptografik özelliklerin uygulanmasıyla ilgili sıkıntılar sürekli hayatımızdadır. Hocaya göre bunun temel sebebi şudur: bir kripto kütüphanesini projeye eklemek ve içindeki fonksiyonları dokümandaki bir iki örneğe bakarak kullanmak kriptografik güvenliği sağlamaz. Hoca bunu gerek ve yeter koşula benzetti: doğru kütüphaneyi seçmek ve API'lerini bilmek gereklidir, ama bunları hangi mantıkla, hangi sırayla kullanırsanız doğru olduğunu da bilmek gerekir.

### 4.2 Kullanıcı tıklamasından tasarruf etmemek

Masaüstünde sürekli tıklarız: sağ tık, sol tık, pencere kaydırmak, menü seçmek, alan doldurmak. Bunlar tek başına masum görünür, ama farklı kanallardan gelen tıklama ve tuş bilgileri bir araya geldiğinde zafiyet olarak kullanılabilecek bilgiler açığa çıkar.

Tipik senaryo şudur: linke tıklanır, tarayıcı açılır, tarayıcıdan da uygulama açılır. Tarayıcı ile uygulama arasında işletim sistemi seviyesinde bir haberleşme kanalı vardır. Uygulama açıldıktan sonra bu kanal düzgün kapatılmazsa uygulama, tarayıcıdaki kullanıcı tuşlamalarını ve tıklamalarını dinleyip kaydedebilir hâle gelir. Birbiriyle ilgisi olmayan iki uygulamadan biri yalnız atlama tahtası olarak kullanılmıştır; bunların izole olması gerekir, ama kanal düzgün kapatılmadığı, unutulduğu ya da iş aceleye getirildiği için sorun büyür.

Bu mantık çok yaygındır: pek çok uygulama, işlerini HTTP istekleri ve REST API'ler üzerinden yürütmek için içine gömülü (bundled) küçük bir web sunucusu barındırır. Zoom'da bu yapı şöyledir (ekrandan, 00:35:00):

- Yerel Zoom web sunucusu `localhost:19421` portunu dinler.
- Uygulamayı başlatmak için zoom.com'daki web sayfası tarayıcıya yerel web sunucusuna bir HTTP isteği göndermesini söyler.
- İstek: `http://localhost:19421/launch?action=join&confno=[conference number]`

Yani tarayıcı üzerinden yerel makinedeki küçük web sunucusuna giden istekle Zoom istemcisi devreye girer. Ama arada bir diyalog yoktur: web istekleri diyalog gerektirmez (web requests do not require a dialogue), her şey kullanıcı farkında olmadan otomatik gerçekleşir.

Buradan çıkan saldırı şudur: herhangi bir web sitesi yerel web sunucusuna istek gönderebilir (any website can send a request to the local web server) ve kullanıcıları haberleri olmadan bir konferansa katabilir. Hoca derste taraflar için A, B ve E (Evil, saldırgan) isimlerinin kullanılacağını söyledi. Bu, sosyal mühendislikle yapılabilir; ya da kullanıcı zaten bir toplantı linki beklemektedir ve gelen linkin o olduğunu düşünür. Sonuçta iki, üç ya da n kişi arasındaki görüşmeye bir başkası katılmış olur. Çözüm olarak web sunucusu Apple'ın MRT aracıyla kaldırılmıştır (Web server removed by Apple's MRT tool). Hocaya göre sorun tasarımsaldır: bu işi bir web sunucusu üzerinden yapmaya hiç gerek yoktur.

### 4.3 MacOS hardened runtime'ın devre dışı bırakılması

Slayta göre hardened runtime kod enjeksiyonuna, kütüphane ele geçirmeye (library hijacking) ve süreç bellek alanının kurcalanmasına karşı korur. Kullanıcı Zoom'a kamera ve mikrofon erişimi verdiğinde MacOS uygulama kodunun tamamının değişmediğini garanti eder (ekrandan, 00:40:00).

Zoom istemcisi MacOS'un bu sertleştirilmiş (hardened) çalışma zamanı özelliklerine uygun değildi, bu yüzden daha düşük bir koruma seviyesindeydi. Çalışmasına izin verildiği için de işletim sistemi bu yoldan gelebilecek saldırılara karşı korumasız kalıyordu. Uyumlu olmadığı için karar kullanıcıya bırakılıyor, kullanıcı da kamera ve mikrofon erişimini onaylıyordu.

Zoom açılışta kütüphaneleri dinamik olarak yükler. Bu doğaldır: sistemde zaten olan kütüphaneleri statik bağlamanın anlamı yoktur ve bellek ayak izi azalır. Saldırı şöyle işler (ekrandan, 00:50:00):

- Saldırgan libssl'e aracılık eden (proxy'leyen) zararlı bir kütüphane yükler; bu kütüphane kamera ve mikrofona erişir hâle gelir.
- Şekildeki Zoom uygulaması `libssl.1.0.0` (saldırganın kütüphanesi) üzerinden gerçek `libssl.1.0.0`'a bağlanır; `curl64` gibi diğer kütüphaneler de yüklenir.
- Kullanıcının MacOS sisteminde `disable-library-validation:true` ayarı geçerlidir.

Kullanıcı onay verdiği anda işletim sistemi kütüphane doğrulamasının kapatılmasını kabul etmiş olur ve gelen kütüphanenin kriptografik hash'inin olması gereken değer olup olmadığını denetlemekten vazgeçer. Saldırganın libssl'i hedeflemesinin sebebi şudur: mahremiyet için görüntü, ses, ekrandaki yazışmalar, paylaşılanlar ve sohbet şifrelemeden geçer, şifrelemeye de bunların düz metin (plaintext) hâli gelir. Proxy kütüphane bu düz metni alıp istediği yere gönderebilir. Arkada gerçek SSL çalışmaya devam eder ve karşı tarafla iletişim şifreli sürer; hiçbir şey bozuk görünmez, ama saldırgan her şeyin açık hâlini elde eder.

Hardened runtime'a göre çalışılsaydı libssl kütüphanesinin gerçek ve doğrulanmış (kriptografik özeti oluşturulmuş) olması gerekirdi; kullanıcıya böyle bir seçenek sunulmaz, sistem "bu uygulama uyumlu değil, yüklemiyorum" derdi.

Hoca bu durumu Windows XP'nin ilk dönemine benzetti. O dönemde birçok donanım üreticisi sürücülerini (driver) Microsoft'a gönderip doğrulatmamıştı; bazısı kısa sürede yetişemediği, bazısı parasal sebeplerle bunu yapmamıştı. Sürücü yüklenirken "imzası hatalı, yüklemeye devam etmek istiyor musunuz?" uyarısı çıkardı. Bu, üreticinin kodu Microsoft'a göndermediği, Microsoft'un onu doğrulayıp kriptografik özetini çıkarmadığı ve işletim sisteminin sürücünün özgün olup olmadığını denetleyemediği anlamına geliyordu. Kullanıcı zaten o sürücüyü yüklemek istediği için "evet" diyordu. Zoom'da da kullanıcı birinin istediği bir toplantıya katılmaya odaklanmıştır ve "evet, istiyorum" der. Hocaya göre buradan yine sosyal mühendisliğe varılır.

## 5. Erişim Denetimi ve Referans Monitör

Hoca bu özelliğin Linux, Windows ve MacOS'ta karşılığı olduğunu, işletim sistemi güvenliği kısmında ayrıntılı işleneceğini söyledi. Normalde işletim sisteminden sistem çağrısıyla bir istekte bulunulduğunda bu isteğin yerine getirilip getirilemeyeceği kullanıcıya ve kullanıcının yetkilerine bağlıdır. Bu, işletim sistemlerindeki temel erişim denetimi (access control) mekanizmasıdır ve çok eskiden beri vardır. Ancak bu hâliyle bazı saldırılara açıktır.

Bunun önüne geçmek için referans monitör (reference monitor) kullanılır. Referans monitör, işletim sistemine gönderilen bütün istekleri gözden geçiren, bir isteğin bilinen bir zafiyeti tetikleyip tetiklemeyeceğini değerlendiren ve isteğin devam edip etmeyeceğine ya da o anda kesilmesi gerektiğine karar veren bir mekanizmadır.

Dosya sisteminin kendi koruma mekanizması da vardır. Unix dosya sisteminde sahip (owner), grup ve diğer kullanıcılar bazında bir konuma okuma, yazma ve çalıştırma yetkisi verilebilir. Referans monitör bunun üstüne yerleştirilip bütün istekler ondan geçirildiğinde, işletim sistemi dışında bağımsız bir mekanizma da kullanıcının o dizine belirtilen biçimde erişmesine izin olup olmadığını denetler. Böylece denetim mekanizmalarının sayısı artar ve birbirinden bağımsızlaşır.

İşletim sistemi bir zafiyet sonucu saldırıya uğrayıp bilgi dışarı çıkarılabilir hâle gelebilir ve bunu fark etmeyebilir. Ancak eklenen referans monitörün bütünlüğü ayrıca denetlendiği için o yapı saldırıya uğradığında ya da bozulduğunda bütün erişim engellenebilir.

## 6. Rekabet Baskısı ve Kullanıcı Onayı

Uygulamaların işletim sistemindeki bu yeni yapıya kendilerini uyarlaması gerekir. Ama geçiş dönemlerinde uygulama kullanıcıya "şunu da yapayım mı, bunu da yapayım mı" diye sorar; hepsine izin verildiğinde ciddi açıklar oluşur. Zoom örneğinde de çözüm uygulamanın güncellenmesidir.

> **Hocanın vurgusu:** Bu durum yalnız Zoom'a özgü değildir, bütün rekabetçi üreticiler için geçerlidir. Rekabet yüzünden yetişilmesi gereken teslim tarihleri vardır; bunlara yetişmek için bazı şeylerden feragat edilir ve feragat edildiği anda otomatik olarak güvenlik zafiyeti oluşur.

Pandemi nedeniyle Zoom'un kullanımı çok kısa sürede yüzlerce, binlerce, belki on binlerce katına çıktı. Beklenmeyen sayıda kullanıcı, beklenmeyen hassasiyette bilgiyi paylaşmak için onu kullanmaya başladı. Bu saldırganların iştahını kabarttı: Zoom düşük öncelikli bir hedeften birdenbire yüksek öncelikli bir hedefe dönüştü. Daha fazla emek harcanıp daha derin inceleme yapıldı, arka arkaya zafiyetler bulundu ve saldırılar gerçekleşti. Hoca bu örneğin birkaç ay önce yaşandığı için aydınlatıcı olduğunu söyledi.

## 7. Dersin Hedefleri ve Konu Başlıkları

Dersin hedefleri üç tanedir:

- **Zafiyet tekniklerini anlamak.** Bir saldırının nasıl yapıldığı anlaşılırsa ona karşı savunma kurulabilir, engellemek için tedbir alınabilir.
- **Güvenlik araçlarını doğru kullanmak.** Açık kaynak ve ücretli araçlar vardır. Hoca "vidayı çekiçle vidalayamazsınız, tornavidaya ihtiyacınız var" benzetmesini yaptı: hangi durumda hangi aracın uygun olduğu ve araçların ürettiği sonuçlara hangi şartlarda güvenilip hangi şartlarda soru işaretiyle bakılacağı öğrenilmelidir.
- **Güvenli sistem kurmak.** Sistem, ağ ve web tarafı adım adım incelendikten sonra güvenli sistemlerin mimarisi hakkında fikir sahibi olunur.

Slayttaki konu başlıkları şunlardır (ekrandan, 00:55:00):

- **Part 1: basics (architecting for security).** Uygulamaların, işletim sisteminin ve eski kodun (legacy code, "bize miras kalan kod") güvenliği: sandboxing, access control ve security testing. Bu kısım tamamen işlenecektir.
- **Part 2: Web security (defending against a web attacker).** Sağlam web siteleri kurmak ve tarayıcı güvenlik modelini anlamak. Web sunucusunun en önemli tamamlayıcı parçası tarayıcıdır; tarayıcı tarafındaki güvenliğin nasıl sağlanacağı da işlenecektir.
- **Network security.** Günümüzde pek çok saldırının gerçekleşebilmesi için ağ üzerinden gelmesi gerekir. Yerel saldırı mümkündür ve göz ardı edilemez, ama esas tehdit ağ üzerinden gelen saldırılardır. Ağ protokollerinin tasarımında güvenlikle ilgili bazı temel tedbirlerin alınmadığı, prensiplerin uygulanmadığı görülecektir.
- **Mobil uygulama güvenliği** bu derste işlenmez; ayrı bir mobil dersinde ele alındığı için oraya bırakılmıştır.

> **Hocanın vurgusu:** Bütün denemeler izole ortamda, kendi makinenize kurduğunuz sanal makineler (VM) ve onların arasındaki sanal ağ üzerinde yapılmalıdır. ADSL, kablo ya da iş yerinin ağından deneme yapmak ciddi bir suçtur ve hukuki sorun doğurur; kayıtlar tutulur. Bu konular bir yere saldırmak için değil; zafiyetleri öğrenmek, onlardan korunmanın yolunu görmek, araçları kullanmayı öğrenmek ve güvenli sistemlerin kurulmasına katkı vermek için anlatılır.

## 8. Sistemler Neden Ele Geçirilir?

Aradan sonra saldırganların motivasyonları incelendi. Temel sebep yine paradır.

### 8.1 IP adresi ve bant genişliği çalma

Slayta göre saldırganın amacı rastgele bir İnternet kullanıcısı gibi görünmektir (Attacker's goal: look like a random Internet user). Virüslü makinenin ya da telefonun IP adresi kullanılır (ekrandan, 01:20:00). Kime ait olduğu bile bilinmeyen bir IP adresi saldırı için kullanılınca saldırının asıl saldırganla ilişkilendirilmemesi umulur; loglara ve izlere bakıldığında saldırı adresi ele geçirilmiş sistemin adresidir. Tek başına bir makinenin bant genişliği bir saldırıya yetmeyebilir, ama bin, on bin, milyon sistem ele geçirildiğinde (hoca IoT cihazlarının ele geçirildiği saldırıları hatırlattı) bunların bant genişliği koordineli bir saldırıda birleşir ve çok yüksek değerlere ulaşılır.

**Spam.** Ele geçirilen IP adreslerinden çoğunlukla spam, yani istenmeyen, beklenmeyen ve kendiliğinden gelen e-posta gönderilir (ör. Storm botnet). Slayttaki "Spamalytics" değerleri şöyledir (ekrandan, 01:20:00):

- 1:12M pharma spams leads to purchase: ilaç sektörüyle ilgili 12 milyon spam e-postadan biri satışla sonuçlanır.
- 1:260K greeting card spams leads to infection: 260 bin tebrik kartı spam'inden biri bulaşmayla sonuçlanır; karta tıklayan kişi bilgisayarına zararlı yüklemiş ve makinesini bir "owned machine"e dönüştürmüş olur.

Hoca 12 milyonda birin küçük göründüğünü, ama günde milyarlarca e-posta alınıp verildiği için uzun vadede iyi bir oran olduğunu söyledi.

**Denial of service (DoS).** Her sistemin, ister ağ ister işlemci gücü açısından olsun, hizmet verebildiği bir üst sınır vardır. Bu sınırdan fazla istek gönderilirse bant genişliği dolar, işlemci gücü yetmez ve sistem hizmet veremez: biri hizmet almak ister, karşı taraf veremez. Hoca, dark web forumlarında yayımlanan rakamlara göre bir adrese bir saatlik DoS saldırısının bedelinin 20 dolar, 24 saatlik saldırının 100 dolar olduğunu söyledi; yani 24 katı değil, "toptan" alınca ciddi indirim yapılıyor. <!-- BELİRSİZ: DoS fiyatları bu anın karesi olmadığı için yalnız altyazıdan alındı. -->

**Click fraud.** Slaytta bir başlık olarak geçti. <!-- BELİRSİZ: Altyazıda "ClickFraud" başlığından hemen sonra bilgi çalmaya geçiliyor; click fraud ayrıca açıklanmadı. -->

### 8.2 Kullanıcı bilgisi çalma

Bilgisayarda nereye tıklandığı, ne girildiği; sosyal güvenlik (TC kimlik) numarası, e-posta adresi, banka bilgileri, şifreler, özel yazışmalar ve özellikle uzaktan çalışma döneminde kurumların uzaktan bağlantı bilgileri çalınabilir. Oyun sektöründe de ciddi para vardır; oyuncu hesaplarının ele geçirilmesi, hesaplardaki değerin (genelde kripto para üzerinden) transfer edilebilmesi demektir.

**Silent Banker ve man-in-the-browser.** Solda kullanıcı, sağda banka vardır. Kullanıcı bankanın giriş sayfasına gitmek ister, banka sayfayı gönderir, ama araya saldırgan girer. Taraflar A (Alice, kullanıcı), B (Bob, banka) ve E (Evil, saldırgan) olarak adlandırılır. Saldırgan sayfaya kötü niyetli JavaScript kodu enjekte eder; kullanıcının o sayfada yaptığı her şeyin, yani kullanıcı adının, şifrenin, hesap numarasının kopyası saldırgana gider. Bu saldırının genel adı man-in-the-middle (ortadaki adam) saldırısıdır; ortadaki adam kendini tarayıcıya yerleştirilen JavaScript ile gösterdiği için bu özel örnekte adı man-in-the-browser olur.

**Finansal zararlılar.** Kötü niyetli yazılımın İngilizcesi malicious software (malware) olup Türkçede kötücül ya da kötü niyetli yazılım denir. Kaspersky 2017 güvenlik bültenindeki liste şöyledir (ekrandan, 01:25:00):

| Sıra | Zararlı |
|---|---|
| 1 | Trojan-Spy.Win32.Zbot |
| 2 | Trojan.Win32.Nymaim |
| 3 | Trojan.Win32.Neurevt |
| 4 | SpyEye |
| 5 | Trojan-Banker.Win32.Gozi |
| 6 | Emotet |
| 7 | Caphaw |
| 8 | Trickster |
| 9 | Cridex/Dridex |
| 10 | Backdoor.Win32.Shiz |

Bu zararlıların üç temel görevi vardır: banka şifrelerini keylogger ile kaydetmek (records banking passwords via keylogger), spam e-posta ve hacklenmiş web siteleriyle yayılmak (spread via spam email and hacked web sites) ve gelecekteki yüklemeler için PC'ye erişimi korumak (maintains access to PC for future installs). Hoca bunların sürekli evrildiğini, yeni sürümlerin birbirinin kopyası ya da permütasyonu olduğunu söyledi.

**FinSpy.** Mobil cihazlar için geliştirilmiş bir finansal casus yazılımdır (Financial Spy'dan kısaltılmış). iOS, Android ve Windows sürümleri vardır. Bir kez yüklenirse kişi bilgilerini, arama geçmişini, konumu, kısa mesajları ve şifreli sanılan sohbet uygulamalarındaki mesajları gönderir. Telegram ya da WhatsApp gibi uygulamalardaki şifreleme, mesajın aktarımı sırasındadır; cihazda düz metin olarak saklanan mesajlar çalınabilir. 2017 öncesinde Android'de SMS ya da e-postayla link göndermek yeterliydi. 2017 sonrasında iOS ve Android'e ciddi koruma mekanizmaları geldiği için cihaza fiziksel erişim (şarj portundaki USB bağlantısı üzerinden) ve Android'de root, iOS'ta jailbreak benzeri bir mod gerekir. Bu da cihazların fiziksel güvenliğinin önemli olduğu, ortalıkta bırakılmaması gerektiği anlamına gelir.

### 8.3 Fidye yazılımı (ransomware)

Fidye yazılımı sisteme girer, verileri geri dönülemeyecek, dönmeye çalışılsa bile çok para harcanması gerekecek biçimde şifreler ve belirli bir Bitcoin karşılığında verileri geri açmayı teklif eder; süre içinde ödenmezse fiyat artar, daha sonra veriler tamamen kaybolur. Hoca Türkiye'de bir e-ticaret sitesinin ve ABD'de bir üniversitenin böyle bir saldırıya uğrayıp fidye ödediğini anlattı. Bundan çıkan ders, yedeğin bile canlı sistemlerde son noktaya dönmek için yetmeyebileceği, yedek alma politikasının (ne sıklıkla, ne kadar geriye) çok önemli olduğudur.

Slayttaki tablo, saldırıya uğrayan kullanıcıların yüzdesini gösterir (ekrandan, 01:30:00):

| Sıra | Ad | Saldırıya uğrayan kullanıcı (%) |
|---|---|---|
| 1 | WannaCry | 7.71 |
| 2 | Locky | 6.70 |
| 3 | Cerber | 5.89 |
| 4 | Jaff | 2.58 |
| 5 | Cryrar/ACCDFISA | 2.20 |
| 6 | Spora | 2.19 |
| 7 | Purgen/GlobeImposter | 2.11 |
| 8 | Shade | 2.06 |
| 9 | Crysis | 1.25 |
| 10 | CryptoWall | 1.13 |

WannaCry ile ilgili slayttaki bilgiler (ekrandan, 01:30:00):

- Solucan (worm), SMB protokolündeki bir zafiyetle yayılır (port 445).
- 14 Nisan 2017: EternalBlue zafiyeti ShadowBrokers tarafından yayımlandı.
- 12 Mayıs 2017: solucan tespit edildi (silahlaştırma 3 hafta sürdü).

SMB (Server Message Block), Windows'un dosya paylaşım protokolüdür ve hocaya göre hep açıkları olan bir protokol olmuştur. Zararlı, bu zafiyet üzerinden sistemden sisteme atlar. 14 Nisan ile 12 Mayıs arasında "ölü yatar"; amacı ağda olabildiğince çok sisteme erişmek ve olabildiğince çok veriyi şifreleyebilmektir.

Hoca bunu gelişmiş kalıcı tehdit (advanced persistent threat, APT) kapsamında değerlendirdi: saldırı vur-kaç değildir, kalıcıdır. Zararlı kendini sisteme yerleştirdikten sonra port taraması yapıp ağ haritasını çıkararak çevrede hangi sürümde hangi sistemlerin olduğunu öğrenir, kendi içindeki veri tabanından hangisine nasıl saldıracağına dair prototip kodları kullanarak bir sistemden diğerine yayılır ve yaklaşık üç hafta sonra gerçek anlamda etkin hâle gelir. WannaCry'ın fidye ekranında belirli bir tarihten sonra ödemenin artacağı, daha sonraki bir tarihte dosyaların kaybolacağı yazıyordu ve bir adrese 300 dolar değerinde Bitcoin gönderilmesi isteniyordu; kripto para olduğu için takibi neredeyse imkânsızdır. <!-- BELİRSİZ: WannaCry fidye ekranı karede görülmedi; tutar ve tarihler altyazıdan alındı. -->

## 9. Sunucu Tarafı Saldırılar ve Veri Kaybı

### 9.1 Sunucu tarafı saldırılar

Slayttaki başlıklar şunlardır (ekrandan, 01:35:00):

- **Data theft:** credit card numbers, intellectual property. Örnek: Equifax (July 2017), yaklaşık 143M "customer" data impacted; Apache Struts'taki bilinen bir zafiyetten (RCE) yararlanıldı. 2000'den beri buna benzer çok sayıda saldırı vardır.
- **Political motivation:** DNC, Tunisia Facebook (Feb. 2011), GitHub (Mar. 2015).
- **Infect visiting users.**

Equifax saldırısında ad, soyad, sosyal güvenlik numarası, adres, banka ve kredi kartı bilgileri çalındı. Apache Struts, web uygulaması geliştirmede kullanılan bir çatıdır (framework). Bu çatıda uzaktan kod çalıştırma (Remote Code Execution, RCE) zafiyeti vardı ve şirket güncellemeyi yapmadı. Hoca bunun büyük olasılıkla yapının hantallığından, çok parçalı olmasından ve değişikliğin maliyetinden kaynaklandığını yorumladı.

**Ziyaret eden kullanıcılara bulaştırma.** Sosyal mühendislikle kişinin ilgi alanına göre (spor, moda, araba) bir link gönderilir. Link, aslında ziyaretçinin bilgisayarına zararlı yüklemek için kurulmuş, görsel olarak çekici bir siteye götürür; kullanıcı orada vakit geçirir, tıklar, hatta form doldurur. Bu işi kolaylaştıran hazır paketler vardır. Hocanın andığı paket PHP tabanlıdır ve sitelerin zarar görmesini sağlayan betikler içerir: zararlı, virüslü sayfaya bir iframe olarak gömülür ve siteyi ziyaret eden tarayıcılara bulaşır. Iframe neredeyse sıfır boyutlu, görünmez bir nokta olabilir; fare imlecinin üzerinden geçmesi ya da sayfanın kaydırılması bile yeter. Paketin yönetim konsolu bulaşma oranlarına dair istatistik verir, birkaç yüz dolara satılır ve bir yıllık destek sözleşmesi bile alınabilir. Hoca, birkaç yıl önceki bir araştırmaya göre 500 bin sitenin bu paketle enfekte edildiğini söyledi. <!-- BELİRSİZ: Altyazıda paketin adı "MPEG" diye geçiyor; CS155 slaytlarındaki ad büyük olasılıkla MPack'tir. Bu anın karesi yok. -->

Hoca ayrıca SQL injection'dan söz etti: dinamik web sitelerinin neredeyse tamamının arkasında bir veri tabanı (PostgreSQL, MySQL vb.) vardır, çünkü dinamik veri bir yerde tutulmalıdır.

Buna karşı bugün kullanılabilen bir önlem güvenli tarama (safe browsing) listeleridir. Tarayıcıya bir site adı yazıldığında tarayıcı arka planda bunu üreticisine sorar: Chrome Google'a, Firefox Mozilla'ya, Safari Apple'a. Site güvenilir ise devam edilir ve yanında yeşil bir işaret gösterilir. Bazı virüs koruma programlarında da benzer yapılar vardır.

### 9.2 Ne çalınıyor?

California Breach Notification Report (2015) grafiğinde y ekseni milyon kayıt sayısıdır. Hocanın okuduğu değerler: yaklaşık 25 milyon sosyal güvenlik numarası, 15 milyondan fazla kredi/banka kartı bilgisi, yaklaşık 17 milyon tıbbi sağlık sigortası kaydı, 8-9 milyon arası ehliyet bilgisi ve 11-12 milyon arası çevrim içi kimlik bilgisi. <!-- BELİRSİZ: Bu grafiğin karesi yok; değerler hocanın grafikten yaklaşık okumasıdır. --> Bu veriler çok değerlidir, çünkü başka yerlerde de kullanılabilir: bankaya ya da oyun sitesine giriş, oradan başka bir yere atlama ve sonunda parasal karşılığa dönüştürme.

### 9.3 Şirketler müşteri verisini nasıl kaybediyor?

PrivacyRights.org'un 2020 verilerine göre dağılım şöyledir (ekrandan, 01:40:00):

| Neden | Pay |
|---|---|
| malware/hacking | %32 |
| Accidental disclosure | %22 |
| Physical document loss | %21 |
| lost/stolen laptops or servers | %17 |
| insider misuse/attack | %8 |

Dilimlerin toplamı %100'dür (python ile kontrol edildi).

Hocanın dikkat çektiği nokta, %22 ve %21'lik iki dilimdir. Fiziksel belge kaybı; belgenin kenarda bırakılması, çöpe atılması, arşive giderken kaybolması ya da bir dava dosyasının bir kafede unutulması gibi durumları kapsar. Yanlışlıkla ifşa (accidental disclosure), bir bilginin hassas olmadığına karar verilip korunmadan yayımlanmasıdır. İkisi birlikte $22 + 21 = 43$, yani %43 eder ve malware/hacking'in (%32) üzerindedir.

Kaybolan ya da çalınan dizüstü bilgisayarlarda ve sunucularda disk şifrelenmemişse (hocaya göre ancak çok özel durumlarda şifreleniyor), çalan kişi diski sektör sektör okuyup bilgiyi olduğu gibi alabilir. Hoca, bir bankanın şube terminali olarak kullandığı mini bilgisayarları yükseltme sonrası hurdaya verdiğini ve bunların diskleriyle birlikte bir hurdacıda ortaya çıktığını anlattı. Bu disklerde bankacılık uygulamalarının veri tabanı kullanıcı adları, şifreleri ve IP adresleri gibi bilgiler bulunabilir.

## 10. Zafiyet Pazarı

Zafiyetlerin bir "aydınlık" bir de "karanlık" tarafı vardır. Slayttaki değerler şöyledir (ekrandan, 01:45:00):

**Option 1: bug bounty programs (many).** Bir hata bulan kişi, karşılığında ödüllendirilmek ister.

| Program | Ödül |
|---|---|
| Google Vulnerability Reward Program | up to \$31,337 |
| Microsoft Bounty Program | up to \$100K |
| Apple Bug Bounty program | up to \$200K |
| Stanford bug bounty program | up to \$1K |
| Pwn2Own competition | \$15K |

Google kendi metriklerine göre en büyük zafiyete bu tutarı verir. Stanford'unki akademik bir programdır. Pwn2Own, belirli bir hedefin hacklenip hacklenemeyeceğinin sınandığı, hackathon benzeri bir yarışmadır.

> **Ek bilgi (derste anlatılmadı):** 31337 sayısı büyük olasılıkla rastgele değildir; hacker argosunda "eleet" (elite) kelimesinin rakamlarla yazılışıdır (31337 → "eleet"). Google bu üst sınırı büyük olasılıkla bu yüzden seçmiştir.

**Option 2: Zerodium:** iOS için \$2M'a, Android için \$2.5M'a kadar (2019) ve başka pek çok şirket. Bazı şirketler buradaki rakamlar düşük kalırsa insanların para hırsıyla buldukları zafiyeti karanlık tarafa satmayı seçebileceğini bildikleri için özel fiyat koyar. Zerodium'un tablosunda uzaktan kod çalıştırma (Remote Code Execution), yerel yetki yükseltme (Local Privilege Escalation) ve sandbox'tan kaçış (Sandbox Escape) kategorileri, işletim sistemlerine göre renklerle gösterilir. Hocanın tablodan okuduğu örnekler: Windows'ta tıklamasız (zero click) uzaktan kod çalıştırma için 1 milyon dolara, Chrome'da RCE ya da LPE için 500 bin dolara, VMware ESXi'de sanal makineden kaçış için 200 bin dolara kadar; mobil tarafta 2.5 milyon ve 2 milyon dolar en üst iki sıradadır. <!-- BELİRSİZ: Zerodium fiyat tablosunun karesi yok; bu değerler altyazıdan alındı. -->

Zerodium'un "Why buy zero-days" (sık sorulan sorular) sayfasına göre müşterileri, gelişmiş sıfırıncı gün (zero-day) exploit'lerine ve siber güvenlik yeteneklerine ihtiyaç duyan, ağırlıkla Avrupa ve Kuzey Amerika'daki devlet kurumlarıdır. Şirket satın aldığı zafiyet araştırmalarını kapsamlı biçimde test eder, analiz eder, doğrular ve belgeler. Hoca bunun savaşın kılıçtan topa, tanka, nükleere ve oradan siber alana kaydığını gösterdiğini; böyle şirketlerin bazı zafiyetlerin karanlık tarafa gitmesini engellediğini ama bu yetenekleri kullandırdıkları güçlerin nasıl kullanacağının sorgulanması gerektiğini söyledi.

## 11. Hangi Koda Güvenebiliriz? Thompson'ın Arka Kapısı

Dersin son kısmı, Turing ödülü sahibi Ken Thompson'ın 1984'te ACM'de yaptığı konuşmaya dayanır. Hoca ACM'yi bilgisayar dünyasının en saygın kuruluşlarından biri olarak tanıttı.

> **Ders sonrası not:** Hoca ACM'nin açılımını "Advanced Computing Machinery" dedi; doğrusu büyük olasılıkla bilinen açılımıyla Association for Computing Machinery'dir.

Thompson soruyu Unix için sormuştu; slayt bunu bugüne uyarlar: "Can we trust the 'login' program in a Linux distribution? (e.g. Ubuntu)" (ekrandan, 01:50:00).

Ubuntu sitesinden indirilir; güvenmeyenler için ISO imajının özgün olup olmadığını denetleyen SHA-256 kriptografik özeti bile verilir. Yine de cevap hayırdır. Login programına ya da işletim sistemine kullanıcı adı ve şifreyi bir yere kaydeden ya da gönderen bir arka kapı (backdoor) yerleştirilmediğini bilemeyiz.

"O zaman programı kaynak koddan kendim derlerim" denebilir; Linux'un özelliği de budur, her şey açık kaynaktır, çekirdek dahil her şey baştan derlenebilir. Kaynaktan üretilmiş login programına güvenebilir miyiz? Yine hayır, çünkü derlemek için derleyici kullanılacaktır. Derleyici ele geçirilmişse ve derlediği kodda login yapısını gördüğü anda içeri otomatik olarak bir login arka kapısı enjekte ediyorsa ne olacak? Hoca bu fikrin 1984'te ortaya atıldığını ve sonradan defalarca gerçekleştiğini söyledi. Demek ki derleyiciye de güvenemeyiz.

"O zaman derleyicinin kaynak kodunu satır satır inceleyip derleyiciyi yeniden derlerim" denebilir. Hoca GNU C derleyicisini (GCC) kendisinin derlediğini anlattı: normal bir C derleyicisiyle başlanır, birkaç aşamadan sonra kendini derleyebilen bir GCC çıkar ve sonunda kararlı bir noktaya gelinir. GCC'nin kendisi C ile yazılmıştır, yani kendini derler; ilk hâlini derlemek için yine bir C derleyicisine ihtiyaç vardır. Bu bir tavuk-yumurta ilişkisidir: en başta güvenmek zorunda olunan, yalnız ikili (binary) olarak var olan, kaynağı elde olmayan küçük bir C derleyicisi vardır. Soru şudur: bu derleyici ikilisinde arka kapı varsa?

Slayttaki saldırı adımı 1 (Attack step 1: change compiler source code) şöyledir (ekrandan, 01:55:00):

```c
compile(s) {
    if (match(s, "login-program")) {
        compile("login-backdoor");
        return
    }
    if (match(s, "compiler-program")) {
        compile("compiler-backdoor");
        return
    }
    /* regular compilation */
}
```

Kutu içindeki kısım slaytta (*) ile işaretlenmiştir. Bu bir sözde koddur (`match` ve `compile` tanımsız, `return`'den sonra noktalı virgül yok); derlenebilir bir C programı olmadığı için derlenmedi. Mantığı şudur: derleyici, derlediği kaynak login programıysa login arka kapısını, derleyicinin kendisiyse derleyici arka kapısını ekler.

Saldırının devamı şöyle anlatıldı: değiştirilmiş derleyici derlenir ve bir derleyici ikilisi çıkar (compile modified compiler → compiler binary). Sonra derleyicinin kaynağı özgün hâline döndürülür (restore compiler source to original state). Derleyici kaynağını incelemek olağandışı hiçbir şey göstermez (inspecting compiler source reveals nothing unusual). Ama derleyiciyi derlemek bozuk bir derleyici ikilisi üretir (compiling compiler gives a corrupt compiler binary), çünkü yıldızlı kısmı ikili derleyici, derleme sırasında kendisi yerleştirir. Bunun için derleyici arka kapısının (*) kısmının tamamını içermesi gerekir. Hoca bunu "çok zekice" diye niteledi.

## 12. Güven Zinciri ve Trusted Computing Base

Thompson'ın "Neye güvenebiliriz?" sorusuna cevabı basittir: hiçbir şeye. Slayt bunu bugüne taşır: postayla bir dizüstü bilgisayar sipariş edildiğinde, geldiğinde üzerinde neye güvenilebilir? Uygulamalar ve/veya işletim sistemi arka kapılı olabilir. Çözüm işletim sistemini ve uygulamaları yeniden kurmaktır. Peki nasıl yeniden kurulacak? İşletim sistemini yeniden kurmak için işletim sistemine güvenilemez; önceki örnekteki gibi bir dağıtım arka kapı içerecek biçimde derlendiyse, dağıtımı hazırlayanların bile bundan haberi olmayabilir. O zaman ön önyükleme (preboot) BIOS / UEFI koduna güvenmek gerekir. Ona da güvenemeyiz: UEFI BIOS'un da müdahaleyle değiştirilebildiği bilinmektedir; hoca ShadowHammer örneğini verdi. Böylece donanıma güç verildiğinde ona "can veren" firmware seviyesine kadar inilmiştir; o firmware ele geçirilmişse donanımın üzerine kurulan hiçbir şeye güvenilemez. Soru sonunda anakarta güvenip güvenemeyeceğimize gelir.

Hoca, eskiden neredeyse ayda bir çıkan BIOS güncellemelerinin keyifle disket, CD ve sonra USB üzerinden yapıldığını, ama içine ne yerleştirildiğine kimsenin bakmadığını hatırlattı. Bugün de BIOS güncellemesi işletim sistemi üzerinden yapılır; tasarım, işlemci ile anakart yönetiminden sorumlu işlemci arasında bir bağlantı üzerinden güncellemeye dönüşmüştür.

Sonuç slaytı şöyledir (ekrandan, 02:00:00):

- Sadly, nothing ... anything can be compromised; but then we can't make progress.
- **Trusted Computing Base (TCB):** Assume some minimal part of the system is not compromised. Then build a secure environment on top of that.
- will see how during the course.

Yani bu gerçeğe takılıp kalırsak ilerleyemeyiz. Çözüm, güvenilir işlem yapmamızı sağlayacak bir taban noktası, yani Trusted Computing Base'tir: sistemin minimal bir parçasının ele geçirilmediği varsayılır ve güvenli ortam bunun üzerine kurulur. Bu, pratikte cihaza konan firmware'in kriptografik olarak imzalanmasıyla sağlanmaya çalışılır. Ancak o imzayı atanların, yukarıdaki süreçlerden geçerken koda arka kapı koymadıklarını da varsaymak zorundayız; ancak o zaman bunun üzerine güvenli bir ortam kurulabilir.

> **Ek bilgi (derste anlatılmadı):** Thompson'ın 1984 tarihli Turing ödülü konuşmasının adı büyük olasılıkla "Reflections on Trusting Trust"tır. Bu saldırıya karşı sonradan önerilen bir yöntem, David A. Wheeler'ın "diverse double-compiling" (DDC) tekniğidir: derleyici, bağımsız ikinci bir derleyiciyle de derlenip sonuçlar karşılaştırılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:23:42)

Silent Banker örneğinde saldırgan, kullanıcı ile banka arasına girip giriş sayfasına kötü niyetli JavaScript enjekte ediyor. Genel adı man-in-the-middle olan bu saldırının bu özel örnekteki adı nedir?

> **Cevap (derste verildi):** Man-in-the-browser. Ortadaki adam kendini tarayıcıya yerleştirilen JavaScript koduyla gösterdiği için bu adı alır.

**Soru 2** (ekrandan, 01:50:00)

Can we trust the "login" program in a Linux distribution? (e.g. Ubuntu)

> **Cevap (derste verildi):** Hayır. İndirilen imajın SHA-256 özeti tutsa bile login programında arka kapı olmadığını bilemeyiz. Kaynaktan derlersek derleyiciye, derleyiciyi kaynaktan derlersek kendini derleyen derleyicinin başlangıçtaki ikili hâline güvenmek zorunda kalırız. Thompson'ın arka kapısı, derleyici kaynağı temiz görünse bile derleyici ikilisinin login ve derleyici arka kapılarını yeniden yerleştirebileceğini gösterir.

**Soru 3** (derste sözlü, 01:55:55)

Postayla bir dizüstü bilgisayar sipariş ettiniz. Geldiğinde üzerinde neye güvenebilirsiniz?

> **Cevap (derste verildi):** Uygulamalar ve işletim sistemi arka kapılı olabilir. Yeniden kurmak için işletim sistemine güvenilemez; preboot BIOS/UEFI'ye güvenmek gerekir, o da değiştirilebilir (ShadowHammer). Zincir anakarta kadar iner.

**Soru 4** (ekrandan, 02:00:00)

So, what can we trust?

> **Cevap (derste verildi):** Ne yazık ki hiçbir şeye; her şey ele geçirilebilir. Ama bu durumda ilerleyemeyiz. Bu yüzden Trusted Computing Base kullanılır: sistemin minimal bir parçasının ele geçirilmediği varsayılır ve güvenli ortam onun üzerine kurulur.

**Soru 5** (ekrandan, 01:40:00)

PrivacyRights.org 2020 verilerine göre şirketlerin müşteri verisini kaybetme nedenlerinden "accidental disclosure" ve "physical document loss" birlikte toplam payın ne kadarıdır, malware/hacking ile karşılaştırınca ne söylenebilir?

> **Cevap (derste verildi):** $22 + 21 = 43$, yani %43'tür; malware/hacking'in %32'lik payından fazladır. Veri kaybının önemli bir kısmı saldırıdan değil, dikkatsizlikten kaynaklanır.

## Dersin Toparlaması

Bu ilk derste bilgisayar güvenliği probleminin kaynakları ortaya kondu: hatalı yazılım, sosyal mühendisliğin etkinliği ve zafiyetlerden para kazanılabilmesi. 2019 zafiyet sayıları, Zoom istemcisindeki üç sorun (kriptografi, `localhost:19421` üzerinden diyalogsuz katılma, hardened runtime'ın devre dışı kalması ve libssl'in proxy'lenmesi) ve referans monitör fikri, gerçek sistemlerde zafiyetlerin nasıl doğduğunu gösterdi. Ardından saldırganların motivasyonları (spam, DoS, bilgi çalma, man-in-the-browser, fidye yazılımı, sunucu tarafı saldırılar) ve zafiyetlerin hem bug bounty programlarında hem de Zerodium gibi şirketlerde alınıp satıldığı bir pazar incelendi.

Ders, Thompson'ın derleyici arka kapısıyla "hiçbir koda tam güvenilemez" sonucuna vardı ve buna karşı Trusted Computing Base yaklaşımını tanıttı. Slaytın son satırına göre bu güvenilir tabanın üzerine güvenli ortamın nasıl kurulacağı dersin geri kalanında görülecektir; ilk kısımda sandboxing, erişim denetimi ve güvenlik testi, ardından web ve ağ güvenliği işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
