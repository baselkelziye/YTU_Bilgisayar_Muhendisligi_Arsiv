# Ders 1 Genişletilmiş Notu: Bilgisayar Ağları ve İnternete Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynak Kitap
- 2. Giriş Bölümünün Yol Haritası
- 3. İnternet Nedir? Somun ve Cıvata Görünümü
- 4. Ağların Ağı, Protokoller ve Standartlar
- 5. Servis Görünümü
- 6. Protokol Nedir?
- 7. İnternet Yapısına Yakından Bakış
- 8. Erişim Ağları
- 9. Kablo Tabanlı Erişim
- 10. DSL
- 11. Ev Ağları
- 12. Kablosuz Erişim Ağları
- 13. Kurumsal Ağlar
- 14. Sayısal Değerler Üzerine Bir Soru
- 15. Host'un Paket Göndermesi ve İletim Gecikmesi
- 16. Fiziksel Ortam

## 1. Dersin Kapsamı ve Kaynak Kitap

Ders, slayt kapağında "Computer Networking Technologies" başlığıyla açıldı; ilk sunum birinci ve ikinci haftaları kapsıyor (ekrandan, 00:05:00). Haftalık sunumlar dersin web sayfasından indirilebiliyor. Kaynak kitap, James F. Kurose ve Keith W. Ross'un "Computer Networking" kitabının 8. baskısıdır (Global Edition, Pearson, 2021) (ekrandan, 00:10:00). Kitabın yazarlarının sitesinde sunumlar, başka belgeler ve videolar da bulunuyor.

**Soru:** Kitabın dördüncü baskısı kullanılabilir mi?
**Cevap:** Kullanılabilir, ama derste güncel baskıdaki değişiklikler izlenecek. Eski baskıların içindeki teknolojiler birkaç yıl geride kaldığı için 2021 baskısındaki güncellemeleri takip etmekte fayda var.

Kitap sekiz bölümden oluşur. Güvenlik bölümü, son sınıftaki ayrı bir bilgisayar ve ağ güvenliği dersinin konusudur; bu derste güvenlik dışındaki bölümler işlenir. Dersin konu listesi şöyledir (ekrandan, 00:15:00):

- Bilgisayar ağları ve İnternet
- Uygulama katmanı (Application Layer)
- Taşıma katmanı (Transport Layer)
- Ağ katmanı: veri düzlemi (Data Plane)
- Ağ katmanı: kontrol düzlemi (Control Plane)
- Bağlantı katmanı ve yerel ağlar (Link Layer and LANs)
- Kablosuz ve mobil ağlar

İlk iki hafta giriş bölümüne ayrılır, sonra uygulama katmanıyla başlanıp aşağı doğru inilir. Hoca, ağ katmanının İnternet'in en karmaşık ve en önemli kısmı olduğunu, bu yüzden kitapta iki bölüme ayrıldığını vurguladı: önce veri düzlemi, sonra kontrol düzlemi. Ardından bağlantı katmanı ve yerel ağlar gelir. Fiziksel katmanın ayrıntısına girilmez.

## 2. Giriş Bölümünün Yol Haritası

Giriş bölümünün amacı İnternet'in büyük resmini görmek ve terminolojiyi oturtmaktır; ayrıntılar sonraki bölümlerde verilir. Bölümün sırası şöyledir:

- İnternet nedir? Herkes "İnternet" der, ama İnternet tam olarak nedir?
- Ağın kenarı: İnternet'i büyük bir bulut gibi düşünürsek, önce bizim ona dokunduğumuz kenardan başlanır. Kenarda host'lar (bireysel cihazlar), erişim ağları ve fiziksel ortam bulunur. Fiziksel ortam kablosuz ya da kablolu (bükümlü çift, koaksiyel kablo, fiber optik) olabilir.
- Ağın çekirdeği: İnternet'te kullanılan iki teknoloji, devre anahtarlamalı ağlar (genel telefon ağı PSTN'de kullanılır) ve paket anahtarlamalı ağlardır.
- Başarım: kaynaktan hedefe giderken paket kaybı, gecikme ve verim (throughput).
- Protokol nedir, protokol katmanları ve İnternet'teki servis modelleri.
- Güvenlik ve İnternet tarihi hakkında kısa bilgi.

<!-- BELİRSİZ: 00:20:27-00:20:49 arasında ağın nasıl kurulduğu ve İnternet'in yapısıyla ilgili bir cümle var; altyazı bozuk. -->

## 3. İnternet Nedir? Somun ve Cıvata Görünümü

İnternet'e ilk bakış, onu oluşturan parçalardan, yani "somun ve cıvata" görünümünden yapılır (ekrandan, 00:25:00). Slayttaki şekilde ortada bir bulut, çevresinde mobil ağ, ev ağı, kurumsal ağ, yerel ya da bölgesel İSS, ulusal ya da küresel İSS, içerik sağlayıcı ağı ve veri merkezi ağı yer alır.

- **Milyarlarca bağlı bilgi işlem cihazı:** Bunlara host ya da uç sistem (end system) denir. Host'lar İnternet'in "kenarında" ağ uygulamaları çalıştırır. Otomobilden cep telefonuna, dizüstü ve masaüstü bilgisayardan sunuculara ve veri merkezlerine kadar her cihaz bir host olabilir ve içinde bir ağ uygulaması çalışabilir.
- **Paket anahtarları (packet switches):** Paketleri, yani veri parçalarını (chunks of data) ileten cihazlardır: yönlendiriciler (router) ve anahtarlar (switch). Paket anahtarlamalı cihazlar birbirine, uç cihazlar da buluta bağlanır.
- **İletişim bağlantıları:** Kablolu (fiber optik kablo, bakır kablo) ya da kablosuz (radyo, uydu) olabilir. Taraflar arasında veri taşındığı için bağlantının bir iletim hızı vardır; buna bant genişliği (bandwidth) de denir. Bant genişliği, bağlantının saniyedeki kapasitesidir.
- **Ağlar:** Bir kurum tarafından yönetilen cihaz, yönlendirici ve bağlantılar topluluğudur.

### 3.1 İnternete Bağlı Cihazlar

Hoca, İnternet'e bağlanan cihazların ne kadar çeşitlendiğini örneklerle gösterdi: İnternet'e bağlı buzdolapları, güvenlik kameraları, İnternet telefonları, kalp pili ve sağlık izleme cihazları gibi sağlık cihazları, artırılmış ve sanal gerçeklik cihazları, akıllı saatler, IP resim çerçeveleri. Eğlenceli bir örnek de Web'e bağlı kızartma makinesidir: Günün hava durumunu indirir ve ekmeğin üzerine yakarak basar; hava güneşliyse ekmeğe güneş, bulutluysa bulut simgesi çıkar. Bunlar yalnız sınırlı örneklerdir, liste uzatılabilir.

## 4. Ağların Ağı, Protokoller ve Standartlar

İnternet temelde "ağların ağı"dır (network of networks): birbirine bağlı İSS'lerden (İnternet Servis Sağlayıcı, Internet Service Provider) oluşur (ekrandan, 00:30:00). Her İSS ayrı bir şirkete ya da kuruma aittir. Hoca örnek verdi: Okulda İnternet'i üniversite sağlar, evde bir kablo operatörü; başka evlerde mobil ya da sabit hat operatörleri. İnternet bu ayrı ağların birbirine bağlanmasıyla oluşur.

Taraflar arasında mesaj paylaşabilmek için bir mekanizma gerekir; bu mekanizma protokoldür. **Protokoller her yerdedir:** Mesaj gönderme ve almayı, gönderirken de bu süreci denetler. Örnekler: HTTP (Web protokolü), video akışı (streaming video) protokolleri, Skype, TCP, IP, WiFi, 4G, Ethernet. Bunlar farklı katmanların protokolleridir. Slayttaki şekilde bu protokoller ağın farklı yerlerine yerleştirilmiştir: mobil ağda 4G, evle uzak bir host arasında Skype, ISS'ler arasında IP, kurumsal ağda Ethernet ve WiFi, uzak sunucularla HTTP, TCP ve video akışı.

Bu protokollerin bir standardı olmalı ve bu standart bir kurum tarafından yayımlanmalıdır. **İnternet standartları** iki kaynaktan alınır:

- **RFC (Request for Comments):** Standart belgeleri.
- **IETF (Internet Engineering Task Force):** İnternet Mühendisliği Görev Gücü.

## 5. Servis Görünümü

İkinci bakış açısı, İnternet'i uygulamalara servis veren bir altyapı olarak görmektir. Hoca altyapıyı bir "test yatağı"na benzetti: Altyapı alttadır, servisler onun üzerine kurulur. Web, e-posta, oyunlar, e-ticaret gibi pek çok uygulama son kullanıcıya bu altyapı üzerinden servis verir.

- Altyapı, dağıtık uygulamalara bir **programlama arayüzü** sağlar.
- Bu arayüzde "kancalar" (hooks) bulunur: Gönderen ve alan uygulamaların İnternet'e bağlanmasını ve İnternet'in taşıma servisini kullanarak mesaj alışverişi yapmasını sağlarlar.
- Altyapı ayrıca **servis seçenekleri** sunar. Bu seçenekler posta servisine benzer: Altyapı mesajların alışverişinden sorumlu olduğu için mesajı nereye teslim edeceğini bilmelidir.

<!-- BELİRSİZ: 00:32:16-00:33:22 arasında posta servisi benzetmesinin ayrıntısı anlatılıyor; altyazı bozuk. -->

## 6. Protokol Nedir?

Hoca protokolü önce insan protokolleriyle anlattı (ekrandan, 00:35:00). Saatiniz yok ve saati öğrenmek istiyorsunuz. Saati olan ve size saati söyleyebilecek birini ararsınız. Ona "saat kaç?" diye sorarsınız; ya da önce "bir sorum var" dersiniz, karşı taraf "evet" der, sonra saati sorarsınız. Bu süreçte bazı kurallar vardır: Amacınız saati öğrenmek olduğu için belli bir soruyu sorarsınız ve belli bir cevap beklersiniz.

Slayttaki insan protokolü örnekleri:

- "Saat kaç?"
- "Bir sorum var."
- Tanışmalar.

Bunlarda belirli mesajlar gönderilir ve mesaj alındığında ya da başka olaylarda belirli eylemler yapılır.

Ağ protokolleri de buna benzer, ama insanların yerine bilgisayarlar (cihazlar) vardır. İnternet'teki bütün iletişim etkinliği protokollerle yönetilir. Protokol, gelen mesajın türünden, biçiminden ve benzeri kurallardan sorumludur.

> **Hocanın vurgusu:** Protokol, ağ varlıkları arasında gönderilen ve alınan mesajların **biçimini** ve **sırasını**, mesaj alındığında yapılacak **eylemleri** tanımlar.

Hoca bunu bir zaman ekseni üzerinde gösterdi. Dikey çizgiler zamanı gösterir, çünkü iletişim birkaç adımdan oluşur. İnsan protokolünde önce "merhaba" dersiniz, karşı tarafın cevabını beklersiniz, cevap gelince sorunuzu sorarsınız ve cevabı alırsınız. Bilgisayar tarafında da benzer biçimde bir web sayfasına bakmak isteyen istemci, sunucuyla adım adım mesajlaşır ve sonunda dosyayı alır.

<!-- BELİRSİZ: 00:36:35-00:37:07 arasında bilgisayar protokolü örneğinin (web sayfası isteme) adımları anlatılıyor; altyazı bozuk ve bu ana ait kare yok. -->

> **Ek bilgi (derste anlatılmadı):** Kitaptaki karşılık gelen şekilde istemci önce bir TCP bağlantı isteği gönderir, sunucudan TCP bağlantı cevabı alır, sonra bir HTTP GET isteği gönderir ve cevap olarak dosyayı alır. Bu adımlar büyük olasılıkla derste gösterilen şekildeki adımlardır.

## 7. İnternet Yapısına Yakından Bakış

Buraya kadar İnternet'in tanımı görüldü: ağların ağı. Şimdi aynı şekil üzerinden yapıya yakından bakılır (ekrandan, 00:40:00).

- **Ağ kenarı:** Kenardaki uç cihazlara host denir. Host'lar istemci (cep telefonu, dizüstü, masaüstü, IP telefon) ya da sunucu olabilir. Sunucular çoğunlukla veri merkezlerinde bulunur.
- **Erişim ağları ve fiziksel ortam:** Erişim ağı, son kullanıcının İnternet'e erişmesi için kullanılan ağdır. Kablolu ya da kablosuz iletişim bağlantılarından oluşur. Örneğin trafik ışığı, otomobil, kablosuz dizüstü bilgisayarlar mobil hücresel ağa bağlanır. Evde kablo ya da DSL modem İnternet'e bağlanır; evdeki cihazların bir kısmı kablosuz, bir kısmı kabloyla bağlıdır.
- **Ağ çekirdeği:** Birbirine bağlı yönlendiricilerden oluşur. Her yönlendirici bir sonrakine bağlanır ve böylece bir ağ oluşur. Bazı yönlendiriciler de bir ağı başka ağlara bağlar.

## 8. Erişim Ağları

Sorulacak soru şudur: Uç sistem, kenar yönlendiriciye nasıl bağlanır? Üç tür erişim ağı vardır:

- **Konut (residential) erişim ağları:** Evlerden erişim.
- **Kurumsal (institutional) erişim ağları:** Üniversiteler ve şirketler.
- **Mobil erişim ağları:** WiFi ya da 4G/5G.

Bir erişim ağında iki şeye bakılır:

- **İletim hızı:** Saniyede iletilen bit sayısıdır ve ağın hızını verir.
- **Bağlantı paylaşımlı mı, adanmış mı?** Kablosuz hücresel ağ birçok host tarafından paylaşılır; ev ağında da İnternet bağlantısı evdeki cihazlar tarafından paylaşılır. Bazı bağlantılar ise adanmıştır, başka hiçbir cihazla paylaşılmaz.

## 9. Kablo Tabanlı Erişim

Hoca evden başlayarak kablo operatörlerinin kullandığı kablo tabanlı erişimi anlattı (ekrandan, 00:45:00).

- Bağlantı koaksiyel kabloyla kurulur ve bu kablo birçok ev tarafından **paylaşılır**.
- Her evde TV yayınını ve veriyi ayıran bir **ayırıcı (splitter)** ve İnternet'i dağıtan bir **kablo modem** vardır.
- Kablo, **kablo başlığına (cable headend)** girer; başlık doğrudan İSS'ye bağlıdır.
- Kanal birçok ev tarafından paylaşılır; ev içinde de aynı bağlantıyı TV yayınları ve veri akışları paylaşır.

### 9.1 Frekans Bölmeli Çoğullama (FDM)

Bağlantının bir bant genişliği vardır. Hoca örnek olarak 1 GHz'lik bir bant genişliği aldı. Bu bandın bir en küçük ve bir en büyük frekansı vardır; bant genişliği bu ikisinin arasıdır. FDM (Frequency Division Multiplexing) ile bu bant küçük kanallara bölünür; her kanalın kendi taşıyıcı frekansı vardır ve sinyal bu taşıyıcıyla modüle edilir. Böylece farklı kanallar farklı frekans bantlarında iletilir. Slayttaki örnekte dokuz kanal vardır: 1-6 numaralı kanallar video, 7 ve 8 veri, 9 kontrol kanalıdır (ekrandan, 00:45:00). Veri ve TV, paylaşılan kablo üzerinden farklı frekanslarda taşınır.

### 9.2 CMTS ve HFC

Kablo başlığında **CMTS (Cable Modem Termination System)** bulunur ve CMTS doğrudan İSS'ye bağlıdır; bu bağlantı genellikle fiber gibi yüksek hızlı bir kabloyla yapılır. Bu yapıya **HFC (hybrid fiber coax, hibrit fiber koaks)** denir.

HFC **asimetriktir**: iki yön vardır, yukarı akış (upstream) ve aşağı akış (downstream). Evde normalde aşağı akış ihtiyacı yukarı akıştan büyüktür. Bu yüzden kanalların çoğu aşağı akışa ayrılır, yukarı akışa sınırlı sayıda kanal kalır. Hocanın verdiği değerlerle:

- Aşağı akış: 40 Mbps'ten 1,2 Gbps'e kadar.
- Yukarı akış: 30 - 100 Mbps.

Evler, kablo başlığına giden erişim ağını paylaşır; başlık da İSS'lere bağlanır.

## 10. DSL

On beş dakikalık aradan sonra hoca, evlerden erişimin ikinci türü olan DSL'e (Digital Subscriber Line) geçti (ekrandan, 00:50:00).

- DSL bağlantısında **mevcut telefon hattı** kullanılır.
- Kablo örneğinde ayırıcı TV ve veri sinyallerini ayırıyordu; burada ayırıcı **ses frekanslarını ve veri akışlarını** ayırır.
- Veri yine farklı frekanslarda, FDM ile taşınır.
- Kablo örneğinde paylaşılan koaksiyel kablo vardı; burada ev ile telefon santrali arasında **adanmış** bir telefon hattı vardır.
- DSL modem, mevcut telefon hattını santraldeki (central office) **DSLAM**'a kadar kullanır. DSL telefon hattındaki veri İnternet'e, ses ise telefon ağına gider.
- Adanmış aşağı akış hızı 24-52 Mbps, adanmış yukarı akış hızı 3,5-16 Mbps'tir (ekrandan, 00:50:00). Burada da aşağı akışa daha çok frekans kanalı ayrılır.

> **Ders sonrası not:** Hoca DSLAM'ı "Digital Subscriber Line Access Management Office" diye açtı (01:07:16); slaytta doğrusu "DSL access multiplexer" (DSL erişim çoğullayıcısı) olarak yazar (ekrandan, 00:50:00).

## 11. Ev Ağları

Ev ağı şekli (ekrandan, 01:10:00) şu parçalardan oluşur:

- **Kablo ya da DSL modem:** Kablo başlığına ya da santrale bağlanır. Modem, kanalı modüle etmekten sorumludur. Modülasyon, sinyali bağlantı üzerinden iletime uygun hâle getirmektir.
- **Yönlendirici, güvenlik duvarı, NAT:** Ağ adresi dönüşümü (NAT) yapar ve mesajları hedefleri arasında yönlendirir.
- **Kablolu Ethernet:** 1 Gbps.
- **WiFi kablosuz erişim noktası:** 54, 450 Mbps.

Modemle santral ya da başlık arasındaki hat, erişim türüne göre adanmış ya da paylaşımlı olabilir. Evde cep telefonu, dizüstü bilgisayar, buzdolabı gibi cihazlar bu ağa bağlanır. Çoğu zaman erişim noktası, yönlendirici ve modem tek bir kutuda birleşir; evinizdeki cihaza bakarak bunu görebilirsiniz.

## 12. Kablosuz Erişim Ağları

Kablosuz ağda, bilgi alışverişi için kablosuz iletişim ortamı kullanılır. Kablosuz erişim ağı da **paylaşımlıdır** ve uç sistemi bir baz istasyonu, yani erişim noktası üzerinden yönlendiriciye bağlar. İki tür kablosuz ağ vardır:

- **Kablosuz yerel ağlar (WLAN, WiFi):** Tipik olarak bina içinde ya da çevresinde çalışır, kapsama yaklaşık 30 m, engel yoksa 100 m'ye kadardır. Her standardın kendi hızı vardır. Hocanın saydığı 802.11 standartları:
  - 802.11b: 11 Mbps
  - 802.11g: 54 Mbps
  - 802.11n: 450 ya da 600 Mbps
  - 802.11ac: 7 Gbps'e kadar
  - 802.11ax: hoca 14 Gbps dedi
- **Geniş alan hücresel ağlar:** Mobil operatörlerin 4G ve 5G ağları.

<!-- BELİRSİZ: 01:12:57-01:13:57 arasında geniş alan hücresel ağların ayrıntısı anlatılıyor; altyazı bozuk ve bu ana ait kare yok. -->

> **Ders sonrası not:** Hoca 802.11ax için burada 14 Gbps, derste daha sonra 13 Gbps dedi (01:12:34, 01:25:29). 802.11ax'in teorik üst sınırı büyük olasılıkla yaklaşık 9,6 Gbps'tir. 802.11ac için söylenen "7 Gbps'e kadar" değeri, yaklaşık 6,9 Gbps olan teorik sınırla uyumludur.

## 13. Kurumsal Ağlar

Kurumsal ağlar şirketlerde, üniversitelerde ve benzeri kurumlarda bulunur (ekrandan, 01:15:00). Hoca üniversiteyi örnek aldı: Üniversitenin İSS'si ulusal akademik ağdır. Kurumsal yönlendirici, İSS'ye (İnternet'e) giden bağlantıyı sağlar. İç tarafta çekirdek anahtarlar vardır; kurumsal e-posta ve web sunucuları bu çekirdek anahtara bağlıdır. Ayrıca kenar anahtarlar, bunlara kabloyla bağlı bilgisayarlar ve kablosuz erişim noktaları bulunur.

- Kablolu ve kablosuz bağlantı teknolojilerinin karışımıyla anahtarlar ve yönlendiriciler birbirine bağlanır.
- **Ethernet:** 100 Mbps, 1 Gbps, 10 Gbps hızlarında kablolu erişim.
- **WiFi:** 11, 54, 450 Mbps hızlarında kablosuz erişim noktaları. Hoca, 5 GHz'te ac ve ax standartlarıyla bu hızın 7 Gbps'e kadar çıkabildiğini ekledi.

## 14. Sayısal Değerler Üzerine Bir Soru

**Soru:** Slaytlarda çok sayıda sayısal değer var. Bunları ezberlemek mi gerekiyor, yoksa genel bilgi mi önemli?
**Cevap:** Sayısal değerleri ezberlemeye gerek yok, ama bilmekte fayda var. Örneğin slaytta ax için verilen hız optimal hızdır; erişim noktalarında görüldüğü gibi mesafe arttıkça hız düşer. Teknolojinin farkında olmak başka, değerleri kelime kelime ezberlemek başka.

> **Hocanın vurgusu:** Bir bilgisayar mühendisi değerlerin mertebesini bilmelidir. Biri Ethernet hızını sorduğunda 100 Mbps ve üstü denmeli, 60-70-80 gibi bir değer söylenmemeli. Dışarıdan biri için "İnternet'im hızlı" sözünün sayısal anlamı olmayabilir, ama hız denince biriminin bit/s olduğu bilinmelidir.

## 15. Host'un Paket Göndermesi ve İletim Gecikmesi

Şimdiye kadar görülenler: İnternet bir ağlar ağıdır, uç cihazlar İnternet'e kablolu ya da kablosuz bağlantılarla bağlanır. Peki mesajlar nasıl alışveriş edilir? Uygulama katmanında Web tarayıcıları, e-posta uygulamaları, oyunlar gibi sayısız uygulama vardır. Bu uygulamaların çoğu çevrimiçidir ve mesaj üretir. Bu mesajlar taraflar arasında iletilmelidir; bazıları küçük, bazıları büyüktür. Kapasitenin verimli kullanılması için büyük mesajlar paket denen küçük parçalara bölünür.

Host'un gönderme işlevi (ekrandan, 01:20:00):

- Uygulama mesajını alır.
- Mesajı **paket** denen, $L$ bit uzunluğunda küçük parçalara böler.
- Paketi erişim ağına **iletim hızı $R$** ile gönderir. Bağlantı iletim hızına bağlantı kapasitesi ya da bağlantı bant genişliği de denir; birimi bit/s'dir.

Hız sonsuz değildir; bir paketin iletimi bağlantı kapasitesine bağlı bir süre alır. Buna **paket iletim gecikmesi** denir:

$$\text{paket iletim gecikmesi} = \frac{L\ \text{(bit)}}{R\ \text{(bit/s)}}$$

Slayttaki tanıma göre bu, $L$ bitlik paketi bağlantıya vermek için gereken süredir.

> **Ders sonrası not:** Hoca iletim gecikmesini bir yerde "paketin kaynaktan hedefe iletilmesi için gereken süre" diye anlattı (01:20:30). Slayttaki tanım "L bitlik paketi bağlantıya vermek için gereken süre"dir (ekrandan, 01:20:00). Kaynaktan hedefe toplam süre, büyük olasılıkla giriş bölümünün devamında görülecek yayılım, işleme ve kuyruk gecikmelerini de içerir.

## 16. Fiziksel Ortam

Fiziksel ortamda bit, verici ve alıcı çiftleri arasında yayılır. Bir bit mantıksal 1 ya da 0'dır. Verici ile alıcı arasındaki fiziksel bağlantı kablolu ya da kablosuz olabilir. İki tür fiziksel ortam vardır:

- **Kılavuzlu ortam (guided media):** Sinyal katı bir ortam boyunca yönlendirilir: bakır, koaksiyel kablo, fiber optik kablo.
- **Kılavuzsuz ortam (unguided media):** Sinyal serbestçe yayılır: kablosuz (radyo) ortam.

### 16.1 Bükümlü Çift

Bükümlü çift (twisted pair, TP), birbirine bükülmüş iki yalıtılmış bakır telden oluşur; UTP ve FTP türleri vardır. Kategori 5, 6 ve 7 kabloları bükümlü çifttir. Hocanın verdiği değerler: Kategori 5, Ethernet'te 1 Gbps'e kadar, Kategori 6 ise 10 Gbps'e kadar destekler.

### 16.2 Koaksiyel Kablo ve Fiber Optik

Koaksiyel kablonun özellikleri anlatıldı, ancak altyazının bu kısmı bozuk.

<!-- BELİRSİZ: 01:22:56-01:23:20 arasında koaksiyel kablo anlatılıyor; altyazı bozuk, yalnız "100 Mbps" değeri okunuyor ve bu ana ait kare yok. -->

Fiber optik, ışık darbeleri taşıyan bir cam liftir. Tek modlu (single mode) ya da çok modlu (multi-mode) olabilir. Her bit ışıkla temsil edilir. Hoca, uzun mesafede tekrarlayıcının (repeater) görevini de anlattı: Gelen sinyali alır, yükseltir ve bir sonraki adıma geçirir.

<!-- BELİRSİZ: 01:23:43-01:24:10 arasında fiberin yüksek hızlı noktadan noktaya işletimi, düşük hata oranı ve tekrarlayıcı aralığı anlatılıyor olabilir; altyazı bozuk ve bu ana ait kare yok. -->

### 16.3 Kablosuz Radyo

Kablosuz radyonun özellikleri (ekrandan, 01:25:00):

- Sinyal elektromanyetik spektrumda, elektromanyetik dalga olarak taşınır.
- Fiziksel bir "tel" yoktur.
- Yayın (broadcast) ve yarı çift yönlü (half-duplex) iletişimdir. Yarı çift yönlü, her tarafın bir anda ya gönderici ya da alıcı olabilmesi demektir.
- Yayılım ortamının etkileri: yansıma (reflection), nesnelerin engellemesi (obstruction), girişim (interference). Hoca girişime kaynak olarak başka sinyalleri, güneş ışığını ve şehirler arasındaki yüksek gerilim hatlarını örnek verdi.

Radyo bağlantı türleri:

- **Kablosuz LAN (WiFi):** Slaytta 100'lerce Mbps'e kadar.
- **Geniş alan (hücresel):** 4G hücresel, yaklaşık 10'larca Mbps.
- **Karasal mikrodalga:** 45 Mbps'e kadar kanallar.
- **Uydu:** Kanal başına 45 Mbps'e kadar, 270 ms uçtan uca gecikme; yer eşzamanlı (geosynchronous) ve alçak yörüngeli (low-earth-orbit) uydular. Hoca, elektromanyetik dalganın iyonosferi geçmesi gerektiği için uydu iletişiminde daha yüksek frekansların kullanıldığını söyledi.

## Dersin Toparlaması

Bu ilk derste İnternet iki açıdan tanımlandı: donanım açısından host'lar, paket anahtarları, iletişim bağlantıları ve ağlardan oluşan, birbirine bağlı İSS'lerin oluşturduğu bir ağlar ağı; servis açısından da dağıtık uygulamalara programlama arayüzü sunan bir altyapı. Protokol, mesajların biçimini, sırasını ve alındığında yapılacak eylemleri tanımlayan kurallar bütünü olarak tanıtıldı; standartların RFC ve IETF tarafından yayımlandığı belirtildi. Ardından ağın kenarına geçildi: kablo (paylaşımlı koaks, FDM, CMTS, asimetrik HFC), DSL (adanmış telefon hattı, DSLAM), ev ağları, kablosuz ağlar ve kurumsal ağlar karşılaştırıldı. Son olarak paket iletim gecikmesi $L/R$ ve kılavuzlu ile kılavuzsuz fiziksel ortamlar ele alındı.

Giriş bölümü iki haftalıktır; sonraki derste kalınan yerden devam edilecek; yol haritasına göre sırada ağın çekirdeği (devre ve paket anahtarlama), başarım ölçütleri (kayıp, gecikme, verim) ve protokol katmanları vardır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
