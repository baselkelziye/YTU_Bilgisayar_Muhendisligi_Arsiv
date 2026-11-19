# Ders 3 Genişletilmiş Notu: Uygulama Katmanı I: Ağ Uygulama İlkeleri, Web ve HTTP

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Katmanına Giriş
- 2. Yaygın Ağ Uygulamaları
- 3. Ağ Uygulaması Geliştirmek
- 4. Uygulama Mimarileri: İstemci-Sunucu ve P2P
- 5. Süreçler, İletişim ve Soketler
- 6. Süreçlerin Adreslenmesi
- 7. Uygulama Katmanı Protokolü Neleri Tanımlar?
- 8. Uygulamanın Taşıma Katmanından Beklentileri
- 9. İnternet Taşıma Protokolleri: TCP ve UDP
- 10. TCP'yi Güvenli Hale Getirmek: TLS
- 11. Web ve HTTP'ye Genel Bakış
- 12. Kalıcı Olmayan ve Kalıcı HTTP
- 13. HTTP Mesajları
- 14. Çerezlerle Durum Tutmak
- 15. Web Önbellekleri (Proxy Sunucular)
- 16. Önbellek Örneği: Bağlantıyı Hızlandırmak mı, Önbellek Kurmak mı?
- 17. Koşullu GET
- 18. HTTP/2 ve HTTP/3
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Katmanına Giriş

Hoca, ilk iki haftada giriş konularının ve dersin kapsamının işlendiğini hatırlatarak başladı (ders İngilizce anlatıldı). Önceki derste söylendiği gibi İnternet bir "ağların ağı"dır ve ağların mimarisi katmanlı bir yapıya dayanır. Bu yüzden önümüzdeki haftalarda katmanlar tek tek ele alınacaktır. İlk ele alınan katman uygulama katmanıdır: kullanıcının gördüğü katman budur ve dizüstü bilgisayarlarda, masaüstü bilgisayarlarda, cep telefonlarında ve diğer uç cihazlarda kullandığımız bütün uygulamalar bu katmanda yer alır. Uygulama katmanı bu hafta ve gelecek hafta işlenecektir.

Bölümün konu sırası şöyledir (ekrandan, 00:55:00):

- Ağ uygulamalarının ilkeleri
- Web ve HTTP
- E-posta, SMTP, IMAP
- Alan adı sistemi (DNS): adların IP adreslerine, IP adreslerinin adlara çevrildiği protokol
- Eşler arası (P2P) uygulamalar
- Video akışı ve içerik dağıtım ağları (CDN); Netflix ve Skype gibi tescilli uygulamalar bunlara dayanır

Bölümün amacı, uygulama katmanı protokollerinin hem kavramsal hem de uygulamaya dönük yönlerini vermektir. Uygulama katmanı, hemen altındaki taşıma katmanından hizmet alır. Uygulamalar iki paradigma üzerinden incelenir: istemci-sunucu ve eşler arası.

## 2. Yaygın Ağ Uygulamaları

Ekrandaki listede şu uygulamalar vardı (ekrandan, 00:15:00): sosyal ağlar, Web, metin mesajlaşma, e-posta, çok kullanıcılı ağ oyunları, depolanmış video akışı (YouTube, Hulu, Netflix), P2P dosya paylaşımı, IP üzerinden ses (ör. Skype), gerçek zamanlı video konferans (ör. Zoom), İnternet araması ve uzaktan oturum açma.

Hoca bu uygulamaların her biri için çok sayıda örnek olduğunu belirtti. Sosyal ağlarda Facebook, Instagram, Twitter ve TikTok; Web'de Chrome ve Safari gibi tarayıcılar ve pek çok Web sunucusu uygulaması; metin mesajlaşmada Skype ve Signal; video akışında YouTube, Netflix, Disney Plus ve Amazon sayıldı. Çok kullanıcılı ağ oyunlarının sayısı neredeyse sayılamayacak kadar fazladır. Dersin kendisi de gerçek zamanlı video uygulaması olan Zoom üzerinden yapılmaktadır.

Hoca mobil cihazlarla İnternet arasındaki ilişkiyi tavuk-yumurta ilişkisine benzetti: Mobil cihazların icadı ağ kullanımını artırdı, İnternet de mobil telefonları daha kullanışlı hale getirdi; mobil telefonlar ise İnternet'i daha erişilebilir yaptı.

## 3. Ağ Uygulaması Geliştirmek

Slayttaki İnternet çiziminde mavi alanlar ağlardır; çekirdekte ISS'ler ve yönlendiriciler, kenarda uç cihazlar bulunur (ekrandan, 00:20:00). Bir ağ uygulaması geliştirmek, şu özelliklere sahip programlar yazmak demektir:

- Farklı uç sistemlerde çalışırlar (cep telefonu, dizüstü, masaüstü, sunucu).
- Ağ üzerinden haberleşirler.
- Örneğin Web sunucusu yazılımı, tarayıcı yazılımıyla haberleşir.

Hocanın örneğinde çizimdeki sunucu bir Web sunucusu, üstteki cep telefonu ve alttaki masaüstü bilgisayar ise uç cihazlardı. Önemli nokta, ağ çekirdeğindeki cihazlar için yazılım yazmanın gerekmemesidir: çekirdek cihazları kullanıcı uygulaması çalıştırmaz. Uygulamaların uç sistemlerde bulunması, uygulamaların hızlı geliştirilmesini ve yayılmasını sağlar.

Yapı katmanlı olduğu için uç sistemlerde beş katman bulunur. Alttan üste: fiziksel katman, veri bağı katmanı, ağ katmanı, taşıma katmanı ve uygulama katmanı. Uygulama katmanı en üsttedir ve taşıma katmanının hizmetlerinden yararlanır.

## 4. Uygulama Mimarileri: İstemci-Sunucu ve P2P

### 4.1 İstemci-sunucu paradigması

Herkesin aşina olduğu bu modelde iki taraf vardır: sunucu tarafı ve istemci tarafı.

- **Sunucu:** Her zaman açık olan bir hosttur, kalıcı bir IP adresi olmalıdır ve ölçekleme için çoğunlukla veri merkezlerinde bulunur.
- **İstemci:** Sunucuyla haberleşir. Kalıcı ya da dinamik IP adresi olabilir; aralıklı bağlanabilir, yani bazen bağlıdır bazen değildir. İstemci-sunucu modelinde istemciler birbirleriyle doğrudan haberleşmez.

Örnekler: HTTP (Web); örneğin istemci cihazda çalışan Chrome, sunucuda çalışan Apache Web sunucusuyla haberleşir. Diğer örnekler e-posta için IMAP ve dosya aktarımı için FTP'dir.

### 4.2 Eşler arası (P2P) paradigma

Bu yaklaşımda sunucu bulunması gerekmez. Rastgele uç sistemler birbirleriyle doğrudan haberleşir. Her eş başka eşlerden hizmet isteyebilir ve sırası gelince başka eşlere hizmet verebilir. Yani bir istemci bazen başka bir istemciye dosya ya da mesaj gönderir, bazen de alır.

P2P'nin önemli bir özelliği kendiliğinden ölçeklenebilirliktir (self-scalability): yeni eşler hem yeni hizmet kapasitesi hem de yeni hizmet talebi getirir. Eşler aralıklı bağlanır, her zaman ağa bağlı değildir; kalıcı IP adresleri olmayabilir ve adresleri zaman zaman değişebilir. Bu yüzden yönetim çok karmaşıktır. En bilinen örnek P2P dosya paylaşımıdır: çizimdeki cep telefonu ile masaüstü bilgisayar ya da üstteki araç, diğer istemcilerle doğrudan veri alışverişi yapabilir.

## 5. Süreçler, İletişim ve Soketler

Uygulama katmanında yalnız bir uygulama bulunması gerekmez; taşıma katmanı birden fazla uygulamaya hizmet verebilir. Süreç (process), temelde bir host içinde çalışan programdır (ekrandan, 00:25:00). Sistemler çok görevli ve çok kullanıcılı olduğu için aynı hostta birden fazla süreç çalışabilir ve bu süreçler birbirleriyle haberleşebilir.

- Aynı hosttaki iki süreç, işletim sisteminin tanımladığı **süreçler arası iletişim** (inter-process communication, IPC) ile haberleşir.
- Farklı hostlardaki süreçler **mesaj** alışverişiyle haberleşir. Bu tür iletişimde de iki paradigma vardır: istemci-sunucu ya da eşler arası.

İstemci-sunucu modelinde:

- **İstemci süreci:** İletişimi başlatan süreçtir.
- **Sunucu süreci:** Kendisiyle temas kurulmasını bekleyen süreçtir; sürekli çalışır ve istemcilerin erişmesini bekler.

P2P mimarisindeki uygulamalarda haberleşilecek ayrı bir sunucu olmadığından her süreç hem hizmet verir hem hizmet alır; yani istemci süreci ile sunucu süreci aynı anda bulunur.

### 5.1 Soketler

Aynı hostta çalışan birden fazla süreç olduğunda ve her biri taşıma katmanından hizmet aldığında bu süreçleri birbirinden nasıl ayırırız? Bunu sağlayan yapı sokettir. Süreç mesajlarını soketine gönderir ve soketinden alır. Hocanın benzetmesiyle soket, alt katmana erişmek için bir kapıdır:

- Gönderen süreç mesajı kapıdan dışarı iter.
- Mesajı alıcı süreçteki sokete ulaştırmak için kapının öbür tarafındaki taşıma altyapısına, yani uygulama katmanının bir altındaki taşıma katmanına güvenir.
- Bir iletişimde iki soket yer alır: her tarafta bir tane.

## 6. Süreçlerin Adreslenmesi

Ağ yapısı gereği mesaj alıp gönderebilmek için her sürecin benzersiz bir tanımlayıcısı olmalıdır (ekrandan, 00:30:00). Bu tanımlayıcının iki işi vardır: süreci aynı hosttaki diğer süreçlerden ayırmak ve sürecin çalıştığı hostu belirlemek. Hostu belirlemek için benzersiz bir IP adresi gerekir: IPv4'te 32 bitlik, IPv6 adresleme mekanizmasında 128 bitlik adres.

Slayttaki soru şudur: Sürecin çalıştığı hostun IP adresi süreci tanımlamaya yeter mi? Cevap hayırdır, çünkü aynı hostta birçok süreç çalışabilir ve aynı hostta oturdukları halde birbirleriyle veri alışverişi yapabilirler. Bu yüzden tanımlayıcı, hem IP adresini hem de hosttaki süreçle ilişkili port numarasını içermelidir.

Örnek port numaraları:

- HTTP sunucusu: 80
- E-posta sunucusu (SMTP): 25

Hoca bir Web sunucusuna HTTP mesajı göndermek için sunucunun IP adresinin 128.119.245.12, port numarasının 80 olduğu örneği verdi. <!-- BELİRSİZ: bu örneğin slaytı karelerde yok. Sunucu adı altyazıda bozuk ("GICS, Fumis, EduTia, Edu"), IP adresi altyazıdan alındı. Port altyazıda iki yerde "18" diye geçiyor; HTTP portu 80'dir (ekrandan, 01:20:00). -->

## 7. Uygulama Katmanı Protokolü Neleri Tanımlar?

Süreçler arasında iki tür mesaj alınıp verilir: istek mesajı ve yanıt mesajı. Bir protokol kullanıldığına göre her protokolün kendine özgü bir yapısı olmalıdır. Uygulama katmanı protokolü şunları tanımlar:

- **Mesaj türleri:** istek ve yanıt.
- **Mesaj sözdizimi:** Mesajda hangi alanların bulunduğu ve alanların nasıl ayrıldığı. Bu kurallar sabittir; işletim sisteminin sürümünden ve türünden bağımsızdır.
- **Mesaj anlambilimi:** Alanlardaki bilginin anlamı.
- **Kurallar:** Süreçlerin mesajları ne zaman ve nasıl gönderip yanıtlayacağı. <!-- BELİRSİZ: bu kısım altyazıda bozuk (00:32:57-00:33:11); madde slaytın olağan içeriğine göre kısa tutuldu. -->

Uygulama katmanında iki tür protokol kullanılır:

- **Açık protokoller:** RFC'lerde (Request for Comments) tanımlanır. Herkes protokol tanımına erişebilir ve bu, birlikte çalışabilirliği sağlar. Örnekler: HTTP, SMTP, DNS.
- **Tescilli (proprietary) protokoller:** Örneğin Zoom'un ya da Skype'ın protokolü.

## 8. Uygulamanın Taşıma Katmanından Beklentileri

Benzersiz adresimiz ve protokolümüz var. Peki bir uygulama taşıma katmanından hangi hizmetleri ister?

- **Veri bütünlüğü:** Verinin değişmeden ulaşması. Dosya aktarımı ve Web işlemleri gibi bazı uygulamalar %100 güvenilir veri aktarımı ister; ses ya da video gibi uygulamalar bir miktar paket kaybına dayanabilir (ekrandan, 00:35:00). Kısacası bazı uygulamalar belirli miktarda kaybı kabul eder, bazıları buna hiç katlanamaz.
- **Zamanlama:** Bazı uygulamalar, örneğin İnternet telefonu ve etkileşimli oyunlar, etkili olabilmek için düşük gecikme ister; bazı uygulamalar ise gecikmeyi kabul edebilir. <!-- BELİRSİZ: bu madde altyazıda kısmen bozuk (00:35:35-00:35:57). -->
- **Verim (throughput):** Multimedya gibi bazı uygulamalar etkili olabilmek için en az belirli bir verim ister. E-posta ya da dosya aktarımı gibi "esnek" (elastic) uygulamalar ise ne kadar verim bulursa onu kullanır; dosyamızı beklemeye razı olabiliriz.
- **Güvenlik:** Pek çok uygulama gizli veri gönderip aldığı için güvenlik de bir ihtiyaçtır. Ancak güvenlik bu dersin değil, ilerideki Bilgisayar ve Ağ Güvenliği dersinin konusudur.

### 8.1 Yaygın uygulamaların ihtiyaçları

Ekrandaki tablo (ekrandan, 00:40:00):

| Uygulama | Veri kaybı | Verim | Zaman duyarlı mı? |
|---|---|---|---|
| Dosya aktarımı/indirme | Kayıp yok | Esnek | Hayır |
| E-posta | Kayıp yok | Esnek | Hayır |
| Web belgeleri | Kayıp yok | Esnek | Hayır |
| Gerçek zamanlı ses/video | Kayba dayanıklı | Ses: 5 Kbps-1 Mbps; video: 10 Kbps-5 Mbps | Evet, onlarca ms |
| Ses/video akışı | Kayba dayanıklı | Üsttekiyle aynı | Evet, birkaç saniye |
| Etkileşimli oyunlar | Kayba dayanıklı | Kbps+ | Evet, onlarca ms |
| Metin mesajlaşma | Kayıp yok | Esnek | Evet ve hayır |

Hoca tabloyu satır satır açıkladı. Gerçek zamanlı ses için gereken en düşük verim, sesin kalitesine (ör. CD kalitesi) göre 5 kilobit/s ile 1 megabit/s arasındadır; video için görüntünün kalitesine göre 10 kilobit/s ile 5 megabit/s arasındadır. Bu uygulamalar zamana duyarlıdır ve yalnız onlarca milisaniyelik gecikmeye dayanabilir. Oyunlar da bir miktar kayba dayanır ama belirli bir verim ister.

Metin mesajlaşma kayıp kabul etmez ve esnektir; zaman duyarlılığı ise mesajın önemine bağlıdır. Metin mesajı bir komut olarak kullanılıyorsa zamana duyarlıdır; başkalarına bilgi vermek için kullanılıyorsa gecikmeyi tolere edebilir. Tablodaki "evet ve hayır" bu yüzdendir.

> **Hocanın vurgusu:** Metin mesajlaşmada zaman duyarlılığı hangi tür uygulamanın kullanıldığına bağlıdır.

## 9. İnternet Taşıma Protokolleri: TCP ve UDP

Uygulama katmanındaki uygulamalar taşıma katmanından hizmet alır ve taşıma katmanında iki hizmet türü vardır.

### 9.1 TCP hizmeti

- Gönderen ve alan süreç arasında **güvenilir taşıma** sağlar.
- Güvenilir olduğu için **akış kontrolü** vardır: gönderen alıcıyı boğmaz.
- **Tıkanıklık kontrolü** vardır: ağ aşırı yüklendiğinde gönderen yavaşlatılır.
- **Zamanlama, en düşük verim garantisi ve güvenlik sağlamaz.**
- **Bağlantı yönelimlidir:** Mesaj gönderip almadan önce bağlantı kurulur, veri alışverişi yapılır ve bağlantı kapatılır.

### 9.2 UDP hizmeti

- Gönderen ve alan süreç arasında **güvenilmez** veri aktarımı sağlar.
- Güvenilirlik, akış kontrolü, tıkanıklık kontrolü, zamanlama, verim garantisi gibi hiçbir şey sunmaz.
- Bu bir "en iyi çaba" (best effort) hizmetidir. Hocanın deyişiyle UDP gönderir ve ulaşması için dua eder.

Hoca burada bir soru sordu: UDP güvenilmez, TCP güvenilir olduğuna göre UDP neden ve nasıl hâlâ kullanılıyor? Bu sorunun cevabının ileride verileceğini söyledi.

### 9.3 Uygulamalar ve kullandıkları protokoller

Hoca uygulamaları, uygulama katmanı protokollerini ve taşıma protokollerini birleştiren tabloyu anlattı (altyazıdan):

| Uygulama | Uygulama katmanı protokolü | Taşıma protokolü |
|---|---|---|
| Dosya aktarımı/indirme | FTP (RFC 959) | TCP |
| E-posta | SMTP (RFC 5321) | TCP |
| Web belgeleri | HTTP 1.1 | TCP |
| İnternet telefonu | SIP, RTP veya tescilli | TCP veya UDP |
| Ses/video akışı | HTTP | TCP |
| Etkileşimli oyunlar | WoW, FPS (tescilli) | UDP veya TCP |

Dosya aktarımı veri kaybı kabul etmediği için TCP kullanır; FTP açık bir protokoldür. SMTP de güvenilir veri aktarımı ister ve TCP'ye dayanır.

<!-- BELİRSİZ: bu tablonun slaytı karelerde yok; RFC numaraları altyazıdan alındı. -->

> **Ders sonrası not:** Hoca etkileşimli oyunlar için "UDP veya FTP" dedi; FTP bir taşıma protokolü değildir, doğrusu büyük olasılıkla "UDP veya TCP"dir.

## 10. TCP'yi Güvenli Hale Getirmek: TLS

Saf (vanilla) TCP ve UDP soketlerinde şifreleme yoktur (ekrandan, 00:45:00). Sokete verilen açık metin parolalar İnternet'te açık metin olarak dolaşır. Bunlar yaygın ve açık protokollerdir ve her şey açık metin olarak gönderilip alınır. Peki bunların üzerine güvenliği nasıl kurarız? Hocanın cevabı: uygulama katmanı ile taşıma katmanı arasına ince bir katman eklemek. Bu katman TLS'dir.

**Transport Layer Security (TLS)** şunları sağlar:

- Şifreli TCP bağlantıları
- Veri bütünlüğü
- Uç nokta kimlik doğrulaması

TLS uygulama katmanında gerçeklenir: uygulamalar TLS kütüphanelerini kullanır, bu kütüphaneler de sırasıyla TCP'yi kullanır. TLS soket API'sinde sokete verilen açık metin, sokete gönderilmeden önce şifrelenir ve İnternet'te şifreli dolaşır. Ayrıntısı kitabın güvenlik bölümündedir.

> **Ders sonrası not:** Hoca "başlangıçta TCP ve UDP metin tabanlı protokollerdir" dedi; doğrusu, saf TCP ve UDP soketlerinde şifreleme bulunmadığı ve verinin açık metin olarak taşındığıdır (slayt da böyle der). Hoca TLS'yi "TCP ya da UDP üzerinde çalışan uygulama katmanı protokolü" diye andı; slayta göre TLS şifreli TCP bağlantıları sağlar ve TLS kütüphaneleri TCP'yi kullanır.

## 11. Web ve HTTP'ye Genel Bakış

Aradan sonra hoca, çok sayıdaki uygulama arasından en yaygın olanı, Web'i ve onun uygulama katmanı protokolü HTTP'yi seçtiğini söyledi.

### 11.1 Web sayfası, nesneler ve URL

Hızlı bir tekrar (ekrandan, 01:15:00):

- Web sayfası **nesnelerden** oluşur. Nesneler aynı Web sunucusunda ya da farklı Web sunucularında saklanabilir; bir sayfayı görüntülerken nesneler farklı sunuculardan alınabilir.
- Nesne bir HTML dosyası, JPEG görüntüsü, Java applet'i, ses dosyası, video dosyası vb. olabilir.
- Web sayfası, birçok **nesneye referans veren bir temel HTML dosyasından** oluşur ve her nesne bir **URL** ile adreslenebilir.

Slayttaki örnek URL, bu haftanın sunum dosyasının adresidir:

```text
www.hasanbalik.com/LectureNotes/ComNet/2.Application%20Layer.pdf
```

Burada `www.hasanbalik.com` host adı, `/LectureNotes/ComNet/2.Application%20Layer.pdf` yol adıdır. Adres, host adı kısmı ile yol adı kısmından oluşur.

### 11.2 HTTP'ye genel bakış

HTTP (HyperText Transfer Protocol), Web'in uygulama katmanı protokolüdür ve istemci-sunucu modelini kullanır:

- **İstemci:** Tarayıcıdır (Firefox, Chrome, Safari...). HTTP protokolüyle nesne ister, alır ve Web nesnelerini görüntüler.
- **Sunucu:** Web sunucusudur (ör. Apache). İsteklere yanıt olarak nesneleri yine HTTP ile gönderir.

Örneğin masaüstündeki Firefox tarayıcısı, host adını ve nesnenin yolunu içeren bir HTTP isteği gönderir; sunucu yanıt verir ve yanıt tarayıcıda gösterilir. iPhone'daki Safari de aynı şekilde HTTP isteği gönderir, yanıt telefon ekranında görüntülenir.

### 11.3 HTTP TCP kullanır

HTTP güvenilir dosya aktarımı gerektirdiği için TCP kullanır (ekrandan, 01:20:00):

- İstemci, sunucunun 80 numaralı portuna TCP bağlantısı başlatır (soket oluşturur). Sunucu tarafında HTTP hizmet süreci mesajları bekler.
- Sunucu istemciden gelen TCP bağlantısını kabul eder.
- HTTP mesajları (uygulama katmanı protokol mesajları) tarayıcı (HTTP istemcisi) ile Web sunucusu (HTTP sunucusu) arasında alınıp verilir.
- Nesne alındıktan sonra TCP bağlantısı kapatılır.

### 11.4 HTTP durumsuzdur

HTTP durumsuz (stateless) bir protokoldür: sunucu geçmiş istemci istekleri hakkında hiçbir bilgi tutmaz. Durum tutmak istenirse işler karmaşıklaşır:

- Geçmiş (durum) saklanmalıdır.
- Sunucu ya da istemci çökerse iki tarafın "durum" görüşleri tutarsız hale gelebilir ve uzlaştırılmaları gerekir.

## 12. Kalıcı Olmayan ve Kalıcı HTTP

HTTP bağlantıları iki türlüdür.

- **Kalıcı olmayan (non-persistent) HTTP:** TCP bağlantısı açılır, istek gönderilir, yanıt alınır ve bağlantı kapatılır. Bir bağlantı üzerinden en fazla bir nesne gönderilir. Sunucudan birden çok nesne indirilecekse birden çok TCP bağlantısı açılır, istek yapılır, yanıt alınır ve kapatılır.
- **Kalıcı (persistent) HTTP:** Sunucuya bir TCP bağlantısı açılır ve istemci ile sunucu arasında bu tek bağlantı üzerinden birden çok nesne gönderilip alınır. En sonda bağlantı kapatılır.

### 12.1 Kalıcı olmayan HTTP örneği

Kullanıcının `www.someSchool.edu/someDepartment/home.index` gibi bir URL girdiğini düşünelim. İlk kısım host, ikinci kısım nesnenin yoludur. Sayfanın 10 JPEG görüntüye referans verdiğini varsayalım. Adımlar:

```text
1a. HTTP istemcisi, www.someSchool.edu adresindeki HTTP sunucusuna
    (port 80) TCP bağlantısı başlatır.
1b. Sunucu bağlantıyı kabul eder ve istemciye bildirir.
2.  İstemci, nesnenin yolunu içeren HTTP istek mesajını TCP soketine yazar.
3.  Sunucu isteği alır, istenen nesneyi içeren yanıt mesajını oluşturup
    soketine gönderir.
4.  Sunucu TCP bağlantısını kapatır.
5.  İstemci HTML dosyasını içeren yanıtı alır, dosyayı işler ve
    10 JPEG nesnesine referans bulur.
6.  1-5. adımlar 10 JPEG nesnesinin her biri için tekrarlanır.
```

(ara adımlar eklendi: 3-5. adımların ayrıntısı altyazıda kısmen bozuk; hoca adımları "her nesne için bağlantı açılır, bir görüntü istenir, alınır, bağlantı kapatılır" diye özetledi.)

### 12.2 Yanıt süresi ve RTT

RTT (round trip time, gidiş-dönüş süresi), isteği gönderip yanıtı almak için geçen süredir. Kalıcı olmayan HTTP'de bir nesne için:

- Bir RTT, TCP bağlantısını kurmak için,
- Bir RTT, HTTP isteğini gönderip yanıtın ilk baytlarını almak için,
- Ve dosya aktarım süresi gerekir. Aktarım süresi bağlantının hızına bağlıdır.

$$\text{Kalıcı olmayan HTTP yanıt süresi} = 2\,\text{RTT} + \text{dosya aktarım süresi}$$

### 12.3 Kalıcı olmayan HTTP'nin sorunları ve kalıcı HTTP

Kalıcı olmayan HTTP'nin sorunları (ekrandan, 01:25:00):

- Nesne başına 2 RTT gerekir.
- Her TCP bağlantısı için işletim sistemi yükü vardır.
- Tarayıcılar bu yüzden çoğunlukla referans verilen nesneleri paralel almak için birden çok paralel TCP bağlantısı açar.

Kalıcı HTTP'de (HTTP 1.1) sunucu yanıtı gönderdikten sonra bağlantıyı açık bırakır; aynı istemci ile sunucu arasındaki sonraki HTTP mesajları bu açık bağlantı üzerinden gönderilir. Böylece her nesne için bağlantı kurma süresi tasarruf edilir.

> **Ek bilgi (derste anlatılmadı):** Kalıcı HTTP'de istemci referans verilen bir nesneyle karşılaştığı anda isteğini gönderir; bu durumda referans verilen her nesne için yaklaşık bir RTT yeterli olabilir. Bu, kalıcı olmayan HTTP'deki nesne başına 2 RTT ile karşılaştırılınca bağlantının açık tutulmasının kazancını açıklar.

## 13. HTTP Mesajları

İki tür HTTP mesajı vardır: istek mesajı ve yanıt mesajı.

### 13.1 İstek mesajı

HTTP istek mesajı ASCII ile biçimlendirilmiş, insan tarafından okunabilir düz metindir. İlk satır **istek satırıdır**; mesaj türünü (örnekte GET), istenen nesneyi (örnekte `index.html`) ve protokol sürümünü içerir. Ardından **başlık satırları** gelir: host adı, kullanıcı aracısı (tarayıcı), kabul edilen metin türü, dil, kodlama türü ve bağlantı türü. `Connection: keep-alive` satırı, sunucunun bağlantıyı açık tutmasını ister. Boş bir satır mesajın sonunu belirtir. Hocanın vurguladığı gibi mesajlaşma çok basittir, insan tarafından okunabilir ve ilgili bütün bilgiyi içerir.

<!-- BELİRSİZ: istek mesajı örneğinin slaytı karelerde yok; satırların tam değerleri verilemedi. -->

Genel istek mesajı biçiminde ilk satırda yöntem, URL ve sürüm; ardından "başlık alanı adı: değer" biçiminde başlık satırları; en sonda gerekirse gövde (body) yer alır.

### 13.2 İstek yöntemleri

- **GET:** Nesne ister.
- **POST:** Web sayfaları çoğunlukla form içerir; kullanıcının girdisi istemciden sunucuya HTTP POST istek mesajının gövdesinde gönderilir.
- **HEAD:** Belirtilen URL bir HTTP GET yöntemiyle istenseydi döndürülecek başlıkları ister; nesnenin kendisini istemez.
- **PUT:** POST'a benzer; yeni dosyayı ya da nesneyi sunucuya yükler. Sunucudaki aynı URL'deki nesnenin yerine gelen yeni nesne konur.

### 13.3 Yanıt mesajı

Yanıt mesajı örneği (ekrandan, 01:30:00):

```text
HTTP/1.1 200 OK\r\n
Date: Sun, 26 Sep 2010 20:09:20 GMT\r\n
Server: Apache/2.0.52 (CentOS)\r\n
Last-Modified: Tue, 30 Oct 2007 17:00:02 GMT\r\n
ETag: "17dc6-a5c-bf716880"\r\n
Accept-Ranges: bytes\r\n
Content-Length: 2652\r\n
Keep-Alive: timeout=10, max=100\r\n
Connection: Keep-Alive\r\n
Content-Type: text/html; charset=ISO-8859-1\r\n
\r\n
data data data data data ...
```

- İlk satır **durum satırıdır**: protokol, durum kodu ve durum ifadesi.
- Ardından **başlık satırları** gelir.
- En sonda **veri**, örneğin istenen HTML dosyası bulunur.

### 13.4 Durum kodları

Durum kodları yanıt mesajının ilk satırında yer alır; tam liste ilgili RFC belgesindedir. Derste geçenler:

- **200 OK:** İstek başarılı oldu; istenen nesne bu mesajın devamında gönderiliyor.
- **301 Moved Permanently:** İstenen nesne o konumdan kalıcı olarak taşındı.
- **400 Bad Request:** İstek mesajı sunucu tarafından anlaşılamadı.
- **404 Not Found:** İstenen belge sunucuda bulunamadı. Hocanın dediği gibi bununla çok karşılaşmışızdır.
- **505 HTTP Version Not Supported:** HTTP sürümü desteklenmiyor. <!-- BELİRSİZ: altyazıda "545" diye geçiyor; slayt karelerde yok, kod büyük olasılıkla 505'tir. -->

## 14. Çerezlerle Durum Tutmak

HTTP durumsuzdur, yani önceki durum bilgisini tutmaz. Durum tutmak istenirse iki yöntem vardır: koşullu GET ya da çerezler. Web siteleri ve istemci tarayıcıları, işlemler arasında bir durum tutmak için çerez kullanır.

### 14.1 Çerezin dört bileşeni

- HTTP yanıt mesajındaki çerez başlık satırı (`Set-Cookie`),
- Sonraki HTTP istek mesajındaki çerez başlık satırı,
- Kullanıcının hostunda tutulan ve tarayıcı tarafından yönetilen çerez dosyası,
- Web sitesindeki arka uç veritabanı.

### 14.2 Örnek

Susan dizüstü bilgisayarındaki tarayıcıyla bir e-ticaret sitesini (hoca Trendyol, Hepsiburada, Amazon gibi örnekler verdi) ilk kez ziyaret eder. İlk HTTP isteği siteye ulaşınca site:

- Benzersiz bir kimlik (çerez kimliği) oluşturur,
- Arka uç veritabanında bu kimlik için bir kayıt açar.

Susan'ın bu siteye sonraki HTTP istekleri çerez kimliğini içerir ve site Susan'ı tanır. Sunucu kimliği veritabanında arar ve önceki bilgileri getirir.

Slayttaki akış (ekrandan, 01:35:00): İstemcide daha önce eBay'den alınmış bir çerez vardır (çerez dosyasında "ebay 8734"). İstemci Amazon'u ilk kez ziyaret eder ve olağan bir HTTP isteği gönderir. Sunucu bunun ilk ziyaret olduğunu görür, bir kimlik (1678) oluşturur, arka uç veritabanına kayıt ekler ve yanıtında `set-cookie: 1678` satırını gönderir. Artık istemcinin çerez dosyasında Amazon kimliği de saklanır. Sonraki istekte istemci `cookie: 1678` satırını gönderir; sunucu kimliği kontrol eder, kullanıcıya özgü işlemi yapar ve olağan yanıtı döner. Bir hafta sonraki ziyarette de istemci aynı kimliği gönderir ve aynı şekilde tanınır.

<!-- BELİRSİZ: Amazon çerez kimliği (1678) karelerde görünmüyor, altyazıdan alındı; altyazıda bir yerde "16, 17" diye bozulmuş. -->

### 14.3 Çerezlerin kullanım alanları

- Yetkilendirme
- Alışveriş sepetleri (sepetteki önceki ürünler)
- Öneriler
- Web sayfasının ayarları
- Kullanıcı oturum durumu (ör. Web e-postası)

### 14.4 Çerezler ve gizlilik

Çerezler sitelerin kendi sitelerindeki kullanıcı hakkında bilgi edinmesine izin verir. Üçüncü taraf kalıcı çerezler (izleme çerezleri), birden çok Web sitesine yayılarak kullanıcı hakkında bilgi toplanmasına olanak tanır.

Durum tutmanın genel sorunu şudur: protokol uç noktaları birden çok işlem boyunca göndericide ve alıcıda durum tutmalıdır. Çerezlerde HTTP mesajları, protokol durumsuz olduğu halde durumu kendileri taşır. Böylece durumsuz HTTP protokolüne bir tür durum kazandırılmış olur.

## 15. Web Önbellekleri (Proxy Sunucular)

Birçok sunucu ve birçok istemci vardır; yerel ağ ile İnternet arasındaki bağlantının kapasitesi sınırlı olduğunda bu bağlantı darboğaz olur ve aynı siteye çok sayıda istek gelir. <!-- BELİRSİZ: önbelleğe giriş kısmı altyazıda bozuk (01:38:09-01:38:42 ve 01:39:12-01:39:52). -->

Web önbelleğinin (proxy sunucu) amacı, istemci isteğini kaynak sunucuyu işe karıştırmadan karşılamaktır (ekrandan, 01:40:00):

- Kullanıcı tarayıcısını bir Web önbelleğini gösterecek şekilde ayarlar.
- Tarayıcı bütün HTTP isteklerini önbelleğe gönderir.
  - Nesne önbellekteyse önbellek nesneyi istemciye döndürür.
  - Değilse önbellek nesneyi kaynak sunucudan ister, alınan nesneyi saklar ve sonra istemciye döndürür.

Önbellek, istemci açısından sunucu gibi, kaynak sunucu açısından ise istemci gibi davranır; kaynak sunucudan siteyi sanki bir istemciymiş gibi ister.

> **Ek bilgi (derste anlatılmadı):** Web önbellekleri çoğunlukla ISS'ler, üniversiteler ya da şirketler tarafından kurulur. Faydaları istemci isteğine yanıt süresini kısaltmak, kurumun erişim bağlantısındaki trafiği azaltmak ve küçük içerik sağlayıcıların içeriği daha etkin dağıtmasını sağlamaktır.

## 16. Önbellek Örneği: Bağlantıyı Hızlandırmak mı, Önbellek Kurmak mı?

### 16.1 Senaryo

Slayttaki senaryo (ekrandan, 01:45:00):

- Kurum ağı: 1 Gbps LAN
- Erişim bağlantısı hızı: 1,54 Mbps
- Kurum yönlendiricisinden sunucuya RTT: 2 s
- Web nesnesi boyutu: 100K bit
- Tarayıcılardan kaynak sunuculara ortalama istek hızı: 15/s
- Tarayıcılara ortalama veri hızı: 1,50 Mbps

İstenenler: LAN kullanımı, erişim bağlantısı kullanımı ve ortalama uçtan uca gecikme.

### 16.2 Önbellek yokken

Ortalama veri hızı: $15 \times 100\text{K bit/s} = 1{,}50$ Mbps (ara adım eklendi).

$$\text{LAN kullanımı} = \frac{1{,}50\ \text{Mbps}}{1\ \text{Gbps}} = 0{,}0015$$

$$\text{Erişim bağlantısı kullanımı} = \frac{1{,}50}{1{,}54} \approx 0{,}97$$

Erişim bağlantısının %97'si doludur. Uçtan uca gecikme:

$$\text{Gecikme} = \text{İnternet gecikmesi} + \text{erişim bağlantısı gecikmesi} + \text{LAN gecikmesi} = 2\ \text{s} + \text{dakikalar} + \text{mikrosaniyeler}$$

Görüldüğü gibi darboğaz ortadaki erişim bağlantısıdır.

> **Ders sonrası not:** Hoca örneği anlatırken ortalama istek hızını "100 kilobit per second", tarayıcılara ortalama veri hızını "154 Mbps" diye söyledi; slayttaki değerler 15 istek/s ve 1,50 Mbps'tir. Hoca LAN gecikmesini "1 mikrosaniye" dedi; 100K bitlik nesnenin 1 Gbps'teki aktarım süresi $10^5/10^9 = 10^{-4}$ s, yani 100 µs'dir. Erişim bağlantısındaki "dakikalar", nesnenin aktarım süresinden ($10^5 / 1{,}54 \cdot 10^6 \approx 0{,}065$ s) değil, kullanım 1'e yaklaşınca büyüyen kuyruk gecikmesinden kaynaklanır.

### 16.3 Seçenek 1: Daha hızlı erişim bağlantısı

Erişim bağlantısının hızı 1,54 Mbps'ten 154 Mbps'e, yani 100 kat artırılırsa:

$$\text{Erişim bağlantısı kullanımı} = \frac{1{,}50}{154} \approx 0{,}0097$$

Erişim bağlantısı gecikmesi dakikalardan milisaniyelere iner. Uçtan uca gecikme 2 s + milisaniyeler + mikrosaniyeler olur. Sorun çözülür, ancak çok para ödenmiştir; bu çözüm pahalıdır.

### 16.4 Seçenek 2: Yerel Web önbelleği

Kurum ağına yerel bir Web önbelleği konur. Bir sunucu almak, bağlantının kapasitesini artırmaktan ucuzdur. İsteklerin %40'ının önbellekte bulunduğunu (isabet oranı 0,4), %60'ının kaynak sunucudan istenmesi gerektiğini varsayalım.

$$\text{Erişim bağlantısındaki veri hızı} = 0{,}6 \times 1{,}50 = 0{,}9\ \text{Mbps}$$

$$\text{Erişim bağlantısı kullanımı} = \frac{0{,}9}{1{,}54} \approx 0{,}58$$

Kullanım 0,97'den 0,58'e iner. Ortalama uçtan uca gecikme yaklaşık 1,2 s olur.

$$\text{Ortalama gecikme} \approx 0{,}6 \times (2{,}01\ \text{s}) + 0{,}4 \times (\text{ms}) \approx 1{,}2\ \text{s}$$

(ara adım eklendi; hoca yalnız sonucu verdi, altyazıda bu değer "average utilization around 1.2 seconds" diye geçiyor ve kastedilen ortalama gecikmedir.)

Bu çözüm, 154 Mbps'lik bağlantıdan daha düşük ortalama gecikme verir ve çok daha ucuzdur. Hoca ayrıca zamanla daha çok sayfa ziyaret edilip diske kaydedildikçe önbellekteki içeriğin ve buna bağlı olarak isabetin arttığını belirtti.

> **Hocanın vurgusu:** Bir önbellek sunucusu almak, bağlantının kapasitesini artırmaktan ucuzdur ve gecikmeyi de azaltır.

## 17. Koşullu GET

Önbellekteki nesnenin güncel olup olmadığını denetlemek için koşullu GET kullanılır. Amaç, önbellekte güncel bir kopya varsa nesneyi hiç göndermemektir; böylece nesne aktarım gecikmesi olmaz ve bağlantı kullanımı düşer.

- Önbellek, HTTP isteğinde önbellekteki kopyanın tarihini belirtir: `If-Modified-Since: <tarih>`. Bu tarih, nesnenin önbellekteki sürümünün tarihidir.
- Sunucu, önbellekteki kopya güncelse yanıtında nesneyi göndermez: `HTTP/1.0 304 Not Modified`. Bu yanıtın gelmesi, sunucudaki ve önbellekteki sürümün aynı olduğu anlamına gelir; aktarım yapılmaz.
- Nesne o tarihten sonra değiştirildiyse sunucu `HTTP/1.0 200 OK` ile nesneyi gönderir ve önbellek nesneyi günceller.

<!-- BELİRSİZ: koşullu GET slaytı karelerde yok; altyazıda "HTTP 1.304" diye geçiyor, sürüm satırı (HTTP/1.0) slaytın olağan biçimine göre yazıldı. -->

## 18. HTTP/2 ve HTTP/3

### 18.1 HTTP 1.1'in zayıflığı: HOL tıkanması

HTTP 1.1, tek bir TCP bağlantısı üzerinden birden çok ardışık (pipelined) GET'i getirdi. Ancak sunucu isteklere sırayla, ilk gelen ilk hizmet alır (FCFS, first come first served) ilkesiyle yanıt verir. FCFS zamanlaması, büyük bir nesne küçük nesnelerin önündeyse küçük nesnelerin büyüğün bitmesini beklemesine yol açar. Buna **hat başı tıkanması** (head-of-line blocking, HOL blocking) denir.

### 18.2 HTTP/2

HTTP/2'nin temel amacı çok nesneli HTTP isteklerinde gecikmeyi azaltmaktır. HTTP/2 (RFC 7540, 2015), sunucunun istemciye nesne gönderirken esnekliğini artırır (ekrandan, 01:50:00):

- Yöntemler, durum kodları ve çoğu başlık alanı HTTP 1.1'den değişmemiştir.
- İstenen nesnelerin gönderim sırası istemcinin belirttiği nesne önceliğine göre belirlenir; FCFS zorunlu değildir.
- İstenmemiş nesneler istemciye itilebilir (push).
- Nesneler çerçevelere (frame) bölünür ve çerçeveler HOL tıkanmasını azaltacak şekilde zamanlanır.

> **Ders sonrası not:** Hoca RFC numarasını "7440" diye okudu; slaytta RFC 7540 yazmaktadır.

### 18.3 HOL tıkanması örneği

İstemci sırasıyla O1, O2, O3 ve O4 nesnelerini ister. O1 çok büyüktür; kalan üç nesnenin toplamından bile büyüktür.

- **HTTP 1.1:** Önce büyük O1 gönderilmelidir; O2, O3 ve O4 onu bekler. O4 için bu çok uzun sürer.
- **HTTP/2:** Nesneler çerçevelere bölünür ve çerçeve çerçeve, dönüşümlü gönderilir. Örnekte O2 tek çerçeve, O3 iki çerçeve, O4 dört çerçevedir. İlk turda her nesneden birer çerçeve gönderilir; O2 tek çerçeve olduğu için hemen teslim edilir. Sonraki turlarda O3 ve O4 tamamlanır, en sonda O1'in kalan çerçeveleri gider.

Sonuç: O1 için pek bir şey değişmez, yalnızca biraz gecikir; ama O2, O3 ve O4 HTTP/2'de çok daha erken teslim edilir, çünkü büyük nesne küçük çerçevelere bölünmüştür.

<!-- BELİRSİZ: HOL örneğinin çerçeve sayıları altyazıdan alındı (O2 bir, O3 iki, O4 dört çerçeve); bu slayt karelerde yok. -->

### 18.4 HTTP/3

HTTP/2 de tek TCP bağlantısı üzerinde nesneleri çerçevelere böler; ancak hâlâ güvenlik içermez. HTTP/3'ün amacı da çok nesneli HTTP isteklerinde gecikmeyi azaltmaktır. HTTP/3, UDP üzerinde nesne başına güvenlik, hata kontrolü ve tıkanıklık kontrolü ekler. Önceki sürümler TCP'ye dayanırken HTTP/3 güvenilirliği, güvenliği ve tıkanıklık kontrolünü UDP üzerinde kendisi sağlar. HTTP/3'ün ayrıntıları taşıma katmanında işlenecektir.

> **Ek bilgi (derste anlatılmadı):** HTTP/3, QUIC adlı ve UDP üzerinde çalışan bir taşıma protokolüne dayanır. TCP üzerinde tek bağlantıda kaybolan bir segment bütün akışları bekletirken QUIC'te her akış ayrı ele alındığı için bu tür tıkanma azalır.

## Örnek Sorular

### Soru 1

(ekrandan, 00:30:00) Mesaj alabilmesi için sürecin bir tanımlayıcısı olmalıdır ve host cihazın benzersiz 32 bitlik bir IP adresi vardır. Sürecin çalıştığı hostun IP adresi, süreci tanımlamaya yeter mi?

**Cevap (derste verildi):** Hayır. Aynı hostta birçok süreç çalışabilir. Süreci tanımlamak için IP adresiyle birlikte o süreçle ilişkili port numarası gerekir (ör. HTTP sunucusu için 80, e-posta sunucusu için 25).

### Soru 2

(derste sözlü, 00:42:28) UDP güvenilmez, TCP güvenilir olduğuna göre UDP neden ve nasıl hâlâ kullanılmaktadır?

> **Çözüm (derste verilmedi):** Derste gösterilen tabloya göre gerçek zamanlı ses/video ve etkileşimli oyunlar bir miktar kayba dayanabilir, ama zamana duyarlıdır. TCP'nin bağlantı kurma süresi, kayıp segmentleri yeniden göndermesi ve tıkanıklık kontrolüyle gönderimi yavaşlatması bu uygulamalarda gecikmeyi artırır. UDP bu mekanizmaları içermediği için bu tür uygulamalar, gerekiyorsa ihtiyaç duydukları güvenilirliği ya da güvenliği uygulama katmanında kendileri ekleyerek UDP'yi tercih edebilir (HTTP/3'ün UDP üzerinde güvenlik ve tıkanıklık kontrolü eklemesi gibi). Bu cevap büyük olasılıkla taşıma katmanı derslerinde ayrıntılandırılacaktır.

### Soru 3

(derste sözlü, 01:22:00-01:24:00) Bir Web sayfası bir temel HTML dosyası ve 10 JPEG görüntüden oluşuyor. Kalıcı olmayan HTTP kullanılırsa her nesne için hangi adımlar tekrarlanır ve bir nesnenin yanıt süresi nedir?

**Cevap (derste verildi):** Her nesne için TCP bağlantısı açılır, nesne istenir, alınır ve bağlantı kapatılır; 1-5. adımlar 10 JPEG nesnesinin her biri için tekrarlanır. Bir nesnenin yanıt süresi bir RTT bağlantı kurma, bir RTT istek ve yanıtın ilk baytları ve dosya aktarım süresinden oluşur: $2\,\text{RTT} + \text{dosya aktarım süresi}$.

> **Çözüm (derste verilmedi):** Paralel bağlantı kullanılmazsa temel HTML dosyası ve 10 JPEG için toplam süre $11 \times (2\,\text{RTT}) + \text{11 nesnenin toplam aktarım süresi} = 22\,\text{RTT} + \text{aktarım süreleri}$ olur.

### Soru 4

(ekrandan, 01:45:00) Erişim bağlantısı hızı 1,54 Mbps, kurum yönlendiricisinden sunucuya RTT 2 s, Web nesnesi 100K bit, tarayıcılardan kaynak sunuculara ortalama istek hızı 15/s (tarayıcılara ortalama veri hızı 1,50 Mbps), kurum LAN'ı 1 Gbps. LAN kullanımı, erişim bağlantısı kullanımı ve ortalama uçtan uca gecikme nedir? 154 Mbps'lik bağlantı ve isabet oranı 0,4 olan yerel önbellek seçeneklerini karşılaştırın.

**Çözüm (derste verildi, değerler python ile doğrulandı):**

- Önbellek yok: LAN kullanımı $1{,}5/1000 = 0{,}0015$; erişim bağlantısı kullanımı $1{,}50/1{,}54 \approx 0{,}97$; gecikme = 2 s + dakikalar + mikrosaniyeler.
- 154 Mbps bağlantı: kullanım $1{,}50/154 \approx 0{,}0097$; gecikme = 2 s + milisaniyeler + mikrosaniyeler; pahalı.
- Önbellek (isabet 0,4): erişim bağlantısındaki hız $0{,}6 \times 1{,}50 = 0{,}9$ Mbps, kullanım $0{,}9/1{,}54 \approx 0{,}58$; ortalama gecikme $\approx 0{,}6 \times 2{,}01 + 0{,}4 \times (\text{ms}) \approx 1{,}2$ s; ucuz.

## Dersin Toparlaması

Bu derste uygulama katmanının temelleri kuruldu. Ağ uygulamalarının uç sistemlerde çalışan ve soketler aracılığıyla taşıma katmanını kullanan süreçlerden oluştuğu; istemci-sunucu ve P2P olmak üzere iki temel mimari bulunduğu; bir sürecin IP adresi ile port numarasının birleşimiyle adreslendiği görüldü. Uygulamaların veri bütünlüğü, zamanlama, verim ve güvenlik ihtiyaçları karşılaştırıldı; TCP'nin güvenilir ve bağlantı yönelimli, UDP'nin ise en iyi çaba hizmeti sunduğu, ikisinin de şifreleme içermediği ve güvenliğin TLS ile sağlandığı anlatıldı.

Dersin ikinci yarısında Web ve HTTP işlendi: nesneler ve URL'ler, TCP ve port 80, durumsuzluk, kalıcı olmayan ve kalıcı bağlantılar ile RTT'ye dayalı yanıt süresi, istek ve yanıt mesajları, yöntemler ve durum kodları, çerezlerle durum tutma, Web önbellekleri ve önbelleğin bağlantı hızını artırmaktan daha ucuz bir çözüm olduğunu gösteren sayısal örnek, koşullu GET ve son olarak HOL tıkanmasını azaltan HTTP/2 ile UDP üzerinde çalışan HTTP/3. Gelecek derste uygulama katmanına e-posta (SMTP, IMAP), DNS, P2P uygulamalar, video akışı ve içerik dağıtım ağlarıyla devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
