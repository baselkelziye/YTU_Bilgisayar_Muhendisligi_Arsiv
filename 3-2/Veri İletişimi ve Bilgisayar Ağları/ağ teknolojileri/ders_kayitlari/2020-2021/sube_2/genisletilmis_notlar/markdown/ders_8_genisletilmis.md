# Ders 8 Genişletilmiş Notu: Hizmet Kalitesi (Quality of Service)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hizmet Kalitesine Giriş
- 2. Uygulama Gereksinimleri
- 3. Ağ Hizmet Kategorileri
- 4. Erişim Hatlarında Asimetri (Öğrenci Sorusu)
- 5. Trafik Şekillendirme: Leaky Bucket ve Token Bucket
- 6. Paket Zamanlama: Round-Robin ve Weighted Fair Queueing
- 7. Kabul Kontrolü ve Akış Tanımı
- 8. Integrated Services ve RSVP
- 9. Differentiated Services
- Örnek Sorular
- Dersin Toparlaması

## 1. Hizmet Kalitesine Giriş

Bu ders iki öğretim üyesinin aynı oturumda dönüşümlü anlattığı ortak bir dersti. Bir önceki haftada tıkanıklık kontrolü işlenmiş ve hizmet kalitesi (Quality of Service, QoS) konusunun başına gelinmişti. Bu haftanın amacı QoS'u olabildiğince ayrıntılı gözden geçirmekti. Sonraki konu internetworking olacak; ağ katmanında olunduğu için TCP/IP'nin IP tarafıyla başlanacak ve sonra üst katmanlara çıkılacak.

Bölümün başlıkları slaytta şöyle sıralanıyordu (ekrandan, 00:05:00):

- Application requirements (uygulama gereksinimleri)
- Traffic shaping (trafik şekillendirme)
- Packet scheduling (paket zamanlama)
- Admission control (kabul kontrolü)
- Integrated services
- Differentiated services

### 1.1 Neden QoS?

Hoca önce uygulamalar açısından QoS'un ne anlama geldiğini anlamak gerektiğini söyledi. Bütün uygulamaların ihtiyaçları aynı olsaydı ve trafiğe bağlı olarak farklı davranmasalardı, QoS'tan söz etmek pek anlamlı olmazdı. Ancak uygulamalar belirli örnekler üzerinden kategorilere ayrılabilir ve bu kategoriler belirli ölçütlerle tanımlanabilir.

Ders sırasında hocalardan birinin sesinin zayıf geldiği söylenince, bu durum canlı bir örnek olarak kullanıldı: iki hoca farklı yerlerden bağlanarak ağın sınırlarını zorluyordu ve yaşanan ses sorunu da QoS kısıtlarının bir parçasıydı. Ses, görüntü ve normal veri trafiğinin her birinin ağdan beklentisi farklıdır.

### 1.2 Trafik şekillendirme ve polislik

İkinci önemli başlık trafiğin şekillendirilmesidir. Ağ topolojisi paketleri bir noktadan diğerine atlamalı biçimde taşır. Geçen hafta görüldüğü gibi topolojinin tasarım kriterlerine uyulmazsa ya da söz verilenden fazla trafik üretilirse doğrudan tıkanıklığa ve başka sorunlara yol açılır. Hizmetin kalitesini kontrol etmenin en iyi yolu trafiği şekillendirmektir. Trafik, uygulamanın çıkışından bağımsız olarak ağ katmanında şekillendirilir.

Bu işi ya host kendisi uygular ya da hostun bağlı olduğu servis sağlayıcı (ISP) uygular. Host yaptığında buna trafik şekillendirme (traffic shaping), ISP yaptığında trafik polisliği (policing) denir. ISP topolojinin sahibi ve yöneticisi olduğu için bu denetimi yalnız uygulamanın çıkış noktasında değil, ağın bütününde (holistik olarak) yapar.

### 1.3 Paket zamanlama ve işletim sistemleri benzetmesi

İşletim sistemlerinde paylaşılan kaynakları dağıtmanın en iyi yollarından biri, örneğin işlemci zamanının planlanmasıdır (scheduling). Ağda yönetilmesi gereken kaynak ise paketlerin bir noktadan diğerine aktarılmasıdır. Bu yüzden paketler üzerinden bir zamanlama, yani paket zamanlama yapılır.

Tıkanıklık kontrolünde de konuşulduğu gibi uygulama servis sağlayıcıyla "el sıkışır": bant genişliği, hız ve gecikme açısından ihtiyaçlarını beyan eder, bu kurallara uyacağını söyler; karşılığında ağ da paketleri bu ihtiyaçlara uygun biçimde karşı tarafa taşır. Bu, tıkanıklık kontrolünde önleyici (proaktif) ile tepkisel (reaktif) tedbirlerin ortasında duran kabul kontrolünün (admission control) devamıdır.

### 1.4 Integrated ve differentiated services

QoS uygulanırken olaya hangi taraftan bakıldığına göre integrated services ya da differentiated services denir. Bir yanda, servisler aynı topoloji üzerinden taşınmak zorundadır ve her birinin "şu şekilde trafik üreteceğim" diye beyan ettiği kurallar gözetilerek birleştirilip aktarılır. Öte yanda, servis sağlayıcı gelen trafiği gözlemler, sınıflandırır, farklılıklarını ortaya çıkarır ve her sınıfa uygun davranışı uygular.

> **Ders sonrası not:** Hoca iki yaklaşımı "aynı şeye farklı açıdan bakmak" diye tanıttı; dersin ilerleyen bölümlerinde görüldüğü gibi integrated services akış başına kaynak ayırmaya, differentiated services ise sınıf başına davranışa dayanır, yani büyük olasılıkla iki ayrı mimari olarak düşünülmelidir.

İkinci hoca differentiated services'e servis sağlayıcı açısından baktı. ISP'ler kendi ağlarından taşınan bazı trafikleri hoş görmez: örneğin eşler arası (peer-to-peer) trafik ya da sağlayıcının kendisi dışında birinin sunduğu IP üzerinden ses (VoIP). Bu trafiği tanımlamak, bir sınıf olarak ayırt etmek ve sonra sınırlamak, düşürmek ya da diğer paketlerden farklı fiyatlandırmak isterler. Bu yüzden QoS yalnız kullanıcının ya da uygulamanın hizmet kalitesi olarak değil, bütün ağın hizmet kalitesi olarak da düşünülmelidir.

### 1.5 Aşırı kapasite (over-provisioning)

Ağ gereğinden geniş tasarlanırsa QoS ile uğraşmaya gerek kalmaz. Karasal telefon ağı bunun tipik örneğidir: telefonu açınca her zaman çevir sesi alınır, çünkü kapasite boldur ve bekleme yoktur. Ancak "gereğinden fazla"nın ne kadar olması gerektiği bilinemez. Bugün fazla diye tasarlanan kapasite üç ya da beş yıl sonra yetersiz kalabilir. Bu yüzden sonunda QoS mekanizmalarına ihtiyaç duyulur.

## 2. Uygulama Gereksinimleri

### 2.1 Gereksinim tablosu

Slayt farklı uygulamaların farklı özelliklere önem verdiğini ve amacın her uygulamaya ihtiyacını vermek olduğunu söylüyordu (ekrandan, 00:25:00). Ağ katmanından kalite açısından beklenen dört ölçüt şunlardır:

- Bant genişliği (bandwidth).
- Gecikme (delay).
- Jitter: gecikmenin anlık değişimi, yani gecikme dağılımının ne kadar geniş ya da sivri olduğu.
- Kayıp (loss).

Slayttaki tablo (ekrandan, 00:25:00):

| Uygulama | Bandwidth | Delay | Jitter | Loss |
|---|---|---|---|---|
| Email | Low | Low | Low | Medium |
| File sharing | High | Low | Low | Medium |
| Web access | Medium | Medium | Low | Medium |
| Remote login | Low | Medium | Medium | Medium |
| Audio on demand | Low | Low | High | Low |
| Video on demand | High | Low | High | Low |
| Telephony | Low | High | High | Low |
| Videoconferencing | High | High | High | Low |

Slaytın altında "High"ın zorlayıcı bir gereksinim anlamına geldiği yazıyordu (örneğin düşük gecikme istenmesi).

> **Hocanın vurgusu:** Tablodaki low, medium ve high değerleri bant genişliğinin ya da gecikmenin düşük, orta veya yüksek olduğu anlamına gelmez. O ölçütün QoS açısından uygulamaya etkisini, yani talebin ne kadar zorlayıcı olduğunu gösterir.

### 2.2 E-posta

E-posta gönderildiğinde, alıcının posta kutusuna anında düşmesi beklenmiyorsa, gönderen açısından iş çıkıştan sonra biter. Sonra alıcının cevap verme süreci başlar. Bilgiyi gönderme ve cevabını alma zaman olarak birbirinden ayrıdır, yani son derece asenkrondur; anlık bir istek-cevap söz konusu değildir.

Günümüzde e-postalar görüntü ve ses de içerebilir, ama klasik e-posta metinden oluşur. Bu yüzden bant genişliği talebi düşüktür. Gecikmeden etkilenmesi de düşüktür: on dakika geç ulaşması büyük önem taşımaz. Ayrıca istemci e-postayı önce bir posta sunucusuna, sunucular da birbirine aktarır ve gönderilebilecek en büyük e-posta boyutu zaten sınırlıdır. Paketler arasındaki gecikme farkının, yani jitter'ın da önemi yoktur. En büyük sorun veri kaybıdır, çünkü kaybolan veri yeniden gönderilmelidir.

### 2.3 Telefon ve ses

Hocalar o anki dersin kendisini örnek verdi: ders hem bir tür telefon görüşmesi (ses konferansı) hem de kaydedilip sonradan dinlendiğinde audio on demand gibidir. Tabloda iki satırda da jitter pembe işaretlidir. Sesin iyi ya da kötü duyulması teknik olarak gecikmeye ve jitter'a bağlıdır; jitter kötüleşince kalite de kötüleşir.

Sesin bant genişliği ihtiyacı teknik olarak oldukça düşüktür. Videokonferans ya da video on demand'de ses artı görüntü aktarılırken, telefon ya da bir podcast dinleme gibi yalnız ses olan uygulamalarda düşük bir bant genişliği yeterlidir. Bant genişliği zaten karşılanmış kabul edilir ve anlık olarak çok değişen bir şey değildir; kaliteyi belirleyen gecikme ve jitter'dır.

### 2.4 Dosya paylaşımı

Dosya paylaşımında baskın ölçüt bant genişliğidir. Yerel diskler artık SSD'dir, hatta PCI Express/NVMe üzerinden bağlanır; işlemciler ve veri yolları çok hızlanmıştır, işlenen veri miktarı büyüktür. Diskten erişimdeki gecikmeye neredeyse tolerans yoktur. Aynı veriyi ağdan alırken de birinci ölçüt bant genişliği olur: 100 megabit yerine 1 gigabit, 1 gigabit yerine 10 gigabit, mümkünse 100 gigabit istenir.

### 2.5 Aynı ağda farklı uygulamalar

Bir topolojide aynı anda yalnız tek tip uygulamanın paketlerinin akacağı diye bir kural yoktur; pek çok farklı tipteki uygulamanın paketleri aynı anda akar. Geçen haftadan hatırlanacağı gibi her topolojinin birim zamanda aktarabileceği en çok paket miktarı vardır ve bu aşılınca tıkanıklık başlar. Mühendislik açısından yapılması gereken, o anda aktarılacak paket tiplerini birbirinin ayağına en az basacak biçimde bir araya getirmektir.

### 2.6 Gürültücü komşu (noisy neighbor)

İkinci hoca bununla ilgili "noisy neighbor" kavramını anlattı. Bir apartmanda daireler duvarlarla birbirinden ayrılmıştır ve fiziksel olarak izole sayılır; ama yan daire televizyonu ya da müziği yüksek sesle açarsa veya duvar inceyse rahatsız olursunuz. Ağda da bazı uygulamalar, örneğin dosya paylaşımı, ne kadar bant genişliği varsa o kadarını kullanmaya meraklıdır. Kısıtlanmazsa ağın kaynaklarını tekeline almaya çalışır ve diğer uygulamaları rahatsız eder.

Aynı ölçüt açısından ihtiyacı yüksek birden fazla uygulama eş zamanlı aktarılıyorsa topolojiye binen yük daha da artar. Bu yüzden bir yandan her uygulamaya tipine göre en uygun parametreler sunulmalı, öte yandan uygulamanın ne olduğu anlaşılabilmelidir. Uygulamanın tipiyle ilgili önceden bilgi verilmiyorsa ağın bunu kendisinin fark edebilmesi gerekir.

## 3. Ağ Hizmet Kategorileri

### 3.1 ATM ağları

Slayttaki kategoriler ATM ağlarından alınmış bir örnektir (ekrandan, 00:35:00). Buradaki ATM, para çekilen makineyle ilgisizdir; Asynchronous Transfer Mode demektir. Hücre (cell) yapısında çalışır, yani bugünkü paket anahtarlamanın daha küçük birimli bir biçimidir. Hücreler 53 bayt uzunluğundadır ve özel anahtarlar üzerinden aktarılır; bu sırada tamponlama ve sınırlandırma yapılır. ATM'de QoS çok çalışılmış bir konudur.

Klasik telefon ağında QoS zaten oturmuş bir konudur, çünkü tek tip trafik, yani ses vardır. Sayısal dünyada audio on demand yanında ses konferansının, video on demand yanında videokonferansın devreye girmesi durumu farklılaştırmıştır. ATM ağları telefon ağlarından yola çıkarak oluşturulmuştur ve bir dönem Ethernet ile birlikte kullanılmıştır; bugün pek örneği kalmamıştır. İkinci hoca ATM'nin hâlâ ADSL içinde bir katman olarak, uyarlama katmanı 5 (AAL5) biçiminde kullanıldığını ekledi.

Hücre boyutunun 53 bayt olması Amerika ile Avrupa arasındaki bir uzlaşmanın sonucudur. Asıl önemli nokta, küçük paket boyutu sayesinde QoS uygulama şansının artmasıdır: veri daha hassas ölçülüp yönetilebilir.

> **Ek bilgi (derste anlatılmadı):** ATM hücresi 5 baytlık başlık ve 48 baytlık yükten oluşur. 48 bayt büyük olasılıkla Amerika'nın önerdiği 64 bayt ile Avrupa'nın önerdiği 32 bayt arasında bir uzlaşmadır; altyazıda geçen "48-64" ifadesi bu tartışmaya işaret ediyor.

Slayttaki tablo (ekrandan, 00:35:00):

| Ağ hizmeti | Uygulama |
|---|---|
| Constant bit rate | Telephony |
| Real-time variable bit rate | Videoconferencing |
| Non-real-time variable bit rate | Streaming a movie |
| Available bit rate | File transfer |

Slayt, ağın uygulama gereksinimlerini karşılamak için farklı türde QoS ile hizmet verdiğini söylüyordu.

### 3.2 Constant bit rate (CBR)

CBR'da bit hızı, yani bant genişliği ihtiyacı sabittir; temel örneği telefondur. Normal konuşma seslerinin üst sınırı yaklaşık 4 kHz'dir. Bu sesi sayısala çevirirken örnekleme teoremi (Nyquist) gereği en yüksek frekansın iki katıyla, yani 8 kHz ile örneklemek gerekir. Böylece bir telefon kanalının ihtiyacı sabit olur; telefon kanalına bundan fazlasını vermenin anlamı yoktur. Şarkıcılar 20-22 kHz'e kadar çıkabilir, ama normal konuşma bu aralığın çok altındadır.

> **Ders sonrası not:** Altyazıda konuşma sesi üst sınırı "4 GHz", şarkıcılar için "20 THz" olarak geçiyor; doğrusu kHz'dir (yaklaşık 4 kHz ve 20 kHz). Telefon kanalı büyük olasılıkla 300-3400 Hz bandıdır; 8 kHz örnekleme ve örnek başına 8 bit ile 64 kbit/s'lik sabit bir kanal elde edilir. <!-- BELİRSİZ: altyazıdaki "3-604" ifadesi büyük olasılıkla 300-3400 Hz'dir; doğrulanamadı. -->

> **Hocanın vurgusu:** Constant bit rate'i telefon örneğiyle birlikte aklınızın bir kenarına yazın. Bu ayrımları bilmek gerçek hayatta karar vermeyi ve durumu değerlendirmeyi kolaylaştırır.

### 3.3 Real-time variable bit rate

Videoda bir sahnenin bir sonraki sahneye benzememesi olasılığı yüksektir: aydınlık, kontrast ve renkler değişebilir. Aynı aydınlatmada hareket ederken bile duruş ve ışık yansımasıyla değerler anlık değişir. Bu da aynı noktanın kaç bitle ifade edileceğini değiştirir. Durağan görüntüde JPEG, hareketli görüntüde MPEG kullanılır; arkadaki mantık aynıdır: büyük görüntü parçalara bölünür, parçalardaki değişim fark (delta) olarak aktarılır.

Görüntünün karşıya en az gecikmeyle gitmesi gerekir. Kafanızı hareket ettirdiğinizde karşı tarafta bir saniye sonra hareket görülürse beyin bunu yadırgar, çünkü yüz yüzeyken hareketler milisaniyeler içinde algılanır. Bu yüzden bir yandan gerçek zaman sağlanmalı, öte yandan sahnedeki değişimler yüzünden anlık bit hızı ihtiyacı değişir. Buna real-time variable bit rate (gerçek zamanlı VBR) denir.

### 3.4 Non-real-time variable bit rate

Kaydedilmiş bir ders ya da bir video sitesindeki video izlenirken gerçek zaman yoktur; olaylar izlendiği anda gelişmez, önceden kaydedilip kenara konmuştur. Kareler arası fark yine değiştiği için her kare için aktarılması gereken bilgi farklıdır, yani bit hızı yine değişkendir. Fakat istemci önden tamponlayabilir: 19. saniye izlenirken 20, 21 ve 22. saniyeler alınıp kenara konabilir. Böylece gerçek zaman kısıtı kalkar.

Hoca bu noktada bir önceki slayta, yani gereksinim tablosuna geri dönülmesini istedi ve iki şeye dikkat çekti. Video on demand satırında bant genişliği "High" olduğu halde pembe işaretlenmeyi unutulmuştu. Video on demand ile videokonferans karşılaştırıldığında fark gecikmededir: kayıtlı videoda istemci tamponladığı için izleme tuşuna basıldıktan yarım saniye sonra video başlar ve gerisi akış olarak gelir, gecikmenin etkisi düşüktür; videokonferansta ise gecikmenin etkisi yüksektir. İkisi de VBR'dır ama biri gerçek zamanlı, diğeri gerçek zamanlı değildir.

### 3.5 Available bit rate (ABR)

Son kategori ABR'dır: "olduğu kadar". Tabloda en altta olmasının sebebi de budur. Önce CBR trafik sağlanır, çünkü adı üzerinde sabit bit hızı ister. Sonra gerçek zamanlı VBR, sonra gerçek zamanlı olmayan VBR karşılanır. Geriye ne kalırsa ABR trafiğe verilir. Tipik örneği dosya aktarımıdır: bir indirme bazen göz açıp kapayana kadar biter, bazen yavaş yavaş ilerler.

Ağ üstteki üç kategorideki uygulamalarca daha yoğun kullanılıyorsa ABR kapasitesi azalır ve indirmeler yavaşlar. Örneğin pandemi döneminde insanlar belirli saatlerden sonra daha çok çevrim içi video izleyip derslere katıldığında bu saatlerde indirme hızları düşer. Ağ ve topoloji aynıdır, servis sağlayıcıyla bağlantı hızınız aynıdır; ama sizin çalıştırdığınız başka bir uygulama bile indirmenizi yavaşlatabilir, çünkü ABR en alt seviyededir.

## 4. Erişim Hatlarında Asimetri (Öğrenci Sorusu)

Trafik şekillendirmeye geçmeden önce bir öğrenci, indirme ile yükleme hızları arasındaki büyük farkın her yerde böyle olup olmadığını sordu.

**Soru:** İndirme ve yükleme hızları arasındaki büyük fark bütün dünyada böyle midir?

**Cevap:** Bu tamamen kullanılan altyapıyla ilgilidir. Örneğin ADSL'de DSL "Digital Subscriber Line" demektir; baştaki "A" bağlantının asimetrik olduğunu söyler. Ev kullanıcısı servis sağlayıcı değil, hizmet alan taraftır; bu yüzden sayısal kanal iki yönde simetrik şekillendirilmez, eve gelen yöne daha fazla, evden çıkan yöne daha az kapasite verilir. Kablo modemde de durum benzerdir. Hücresel bağlantı temelde simetrik bir yapıdır, ama mantıksal kanalların kullanımında asimetrik bölümler de vardır.

Aynı öğrenci uydu tabanlı geniş bant bağlantılarını sordu: binlerce uydudan oluşan bir kablosuz ağda kimin ağı kullanıp kimin kullanamayacağı nasıl ayrılır?

**Soru:** Herkese açık bir kablosuz ortamda bir kullanıcının ağın parçası olup olmadığı ve ne kadar kaynak kullanacağı nasıl belirlenir?

**Cevap:** Az önce konuşulan ağa kabul (network admission) bunun bir parçasıdır. Fiziksel katman radyo frekansı, yani kablosuz bile olsa, üzerine oturtulan diğer katmanlarla bant genişliği sınırlaması yapılabilir; bunun için fiber ya da bakır kablo gerekmez. Hücresel ağlarda da hız testinde yüksek değerler görülebilir, ama bölgedeki kullanıcı sayısı arttıkça kapasite paylaşıldığı için hız düşer. Uydu ağlarında da uydular kendi aralarında ve aşağıya doğru temiz haberleşse bile, uydulara çıkış (uplink) için kapasite paylaşılmak zorundadır. Hocalardan biri, uydu ve yer bağlantı hızlarının teknik olarak genelde asimetrik olduğunu, simetrik bağlantının mümkün ama pahalı olduğunu söyledi.

Hoca konuyla ilgilenen öğrenciye, 1980'lerin sonunda ortaya atılıp 1990'larda hayata geçirilen Iridium uydu telefon projesini okumasını önerdi.

## 5. Trafik Şekillendirme: Leaky Bucket ve Token Bucket

### 5.1 Ortalama hız ve burst

Slayt, trafik şekillendirmenin ağa giren verinin ortalama hızını ve ani artışını (burstiness) düzenlediğini ve bunun garanti vermemizi sağladığını söylüyordu (ekrandan, 00:45:00). Şekilde hosttan çıkan paketlerin düzensiz aralıklarla geldiği, "Shape traffic here" denen çizgiden sonra ağa düzenli aralıklarla girdiği görülüyordu.

Trafik şekillendirmenin iki önemli noktası vardır:

- Ortalama hız şekillendirilir.
- Burst, yani anlık artışlar sınırlanır.

Bu ikisi birbiriyle hem ilişkili hem farklıdır. CBR'da, örneğin telefonda 8 kHz örneklemeyle bitler hiç durmadan aynı hızla gelir; ortalama değişmez. VBR'da ise hoca uç bir örnek verdi: sahne simsiyahsa sıkıştırma sayesinde gönderilecek bilgi neredeyse sıfırdır. Sonra güneş doğar, aydınlık bütün sahneyi kaplar ve sıfır olan değerler yüksek çözünürlükteki geniş değer aralığına yayılır. Bu da anlık olarak çok daha fazla bant genişliği ihtiyacı, yani burst demektir.

### 5.2 Burst neden istenmez?

İkinci hoca burst'ün neden istenmediğini açıkladı. Her ağ cihazının arayüzleri için bir tampon alanı vardır. Cihaz bir hattan aldığını başka bir hatta aktarır: bir anahtar örneğin 48 downlink'ten aldığını bir uplink'e, bir router 3-5 arayüz arasında paket aktarır. Cihaz hat hızında çalışsa bile hatların hızları birbirinden farklı olabilir ve birden fazla arayüzden aynı anda yoğun trafik gelebilir. Bunlar tamponun dolmasına ve sonunda paket düşürülmesine yol açar. Bu yüzden burst'ü zamana yaymak, trafiği sanki sabit hızlıymış gibi şekillendirmek gerekir.

Burst hep artış olarak değerlendirilir, çünkü azalma zaten işe yarar. Ayrıca bu düzenleme garantili olmalıdır. Kullanıcı servis sağlayıcıyla CBR değerini ve VBR'da burst değerini belirleyip buna uygun bir tarife seçer. Sonra daha yüksek bir hızla ya da daha büyük burst'lerle trafik üretip "nasılsa denetleyemezler, ucuza kapatırım" diyebilmemeli. Servis sağlayıcının finansal kaygıları nedeniyle bunun düzgün işlemesi gerekir. Sağlayıcı bunu sağlayamazsa, aynı ortamdaki kullanıcıların hepsi gecikme, kayıp ve jitter'dan rahatsız olur ve toplu bir sorun yaşanır. Slayttaki şekilde çizilen çizgi bunu anlatır: yukarıda paketler nasıl gelirse gelsin, aşağıda belirlenen kurala göre çıkarlar.

### 5.3 İki yöntem

Slaytta iki yöntem gösteriliyordu (ekrandan, 01:00:00). Slayt metni token ve leaky bucket'ın hem ortalama hızı (R) hem de kısa süreli burst'ü (B) sınırladığını söylüyordu: token bucket için kova boyutu B'dir, su R hızıyla girer ve göndermek için çıkarılır; leaky bucket için tersidir. Şeklin solunda leaky bucket ("göndermek için suyu koy", kova boyutu B, alttan R hızıyla akış; "göndermek için dolu olmasına gerek yok"), sağında token bucket (musluktan R hızıyla su girer, kova boyutu B, "göndermek için suyu/jetonu çıkar"; "göndermek için biraz su olmalı") vardı. Hoca slayt metnindeki sıranın şekildeki sırayla uyuşmadığına dikkat çekti: şekilde soldaki leaky bucket, sağdaki token bucket'tır.

### 5.4 Leaky bucket (sızdıran kova)

"Bucket" kova, "leaky" ise sızdıran, delikli demektir. Kovanın içinde ne kadar su olursa olsun, deliğin çapı aşağı akan su miktarını belirler. Toplu iğne başı kadar bir delikten su ancak ince bir iplik gibi akar; delik genişletilirse daha geniş akar. Ama kovadaki su bitene kadar aşağıdaki akışın hızı hiç değişmez.

Hoca uç senaryoyu düşündü: kovaya bir musluktan sürekli su verilsin ve musluk hiç kapatılmasın. Bu tam okul sınavlarındaki havuz problemleri gibidir. Su akmaya devam ettikçe bir noktada kova taşar. Kova taşsa bile, yeni gelen suya yer kalmasa bile, deliğin çapı değişmediği için alttaki çıkış aynı hızda sürer.

Kovanın taşması paketlerin düşürülmesi, işlenememesi, yani router ya da hosttaki ağ arayüzü tamponlarının dolmuş olması demektir. Her host, router ve ağ arayüzünün bir tamponu vardır ve bu tampon bir kova olarak canlandırılmıştır. Deliğin çapı tampondan dışarıya bilgi çıkarma hızıdır ve sabittir. Bu yüzden leaky bucket sabit bit hızlı (CBR) trafik için uygulanan bir yöntemdir.

### 5.5 Token bucket (jeton kovası)

Token bucket'tan bir şey çıkarabilmek için elde bir "kredi" olması gerekir; kredi varsa kovanın deliği açıktır ve akış olur. İkinci hoca bunu çaycıdaki pul sistemine benzetti: önceden pul alınmıştır, pul gösterdikçe çay gelir; pul bitince yeni çay için, yani yeni paket göndermek için yeni pul almak gerekir.

Bu yöntem CBR'a değil VBR'a uygundur. Leaky bucket'ta delik çapı hiç değişmiyordu; burada eldeki jeton sayısına bağlı olarak, jetonlar bitene kadar gelen paketler hiç gecikmeden çıkarılabilir. Jeton bitince bir sonraki jeton gelene kadar beklenir.

Bir jeton üretim süresi (token generation time) vardır. Her sürede bir jeton üretilip kenara konur. Trafik gelmezse jetonlar birikir. Örneğin 10 tur boyunca hiç trafik gelmezse kenarda 10 jeton olur. Ardından gelen trafik bu 10 jetonun karşıladığı miktara eşit ya da daha azsa hiç beklemeden çıkar; bu anlık bir burst'tür. Bu burst en çok biriken 10 jeton kadar sürer. Jetonlar bitip trafik gelmeye devam ederse çıkış sabit hıza (CBR'a) döner.

Bu bir emniyet valfidir. Kontrolsüz gelen trafiği çıkış hattına olduğu gibi hiç durmadan basmak, geçen haftadan bilindiği gibi tıkanıklığa yol açar. Bu yüzden burst'e en çok biriken jeton kadar izin verilir, sonra leaky bucket'taki gibi belirli bir hızla devam edilir. Leaky bucket katı bir kuraldır ve kendini uyarlamaz; token bucket ise eldeki jeton miktarına göre uyarlanır.

> **Hocanın vurgusu:** Kenarda biriken jeton miktarı da sınırlanmalıdır: tampon boyutuyla. Dışarıya çıkarılacak en büyük trafik tampon miktarıyla sınırlanmalı ki bir sonraki router'a gereksiz yük bindirilmesin; onun tamponu biterse paket düşürmek zorunda kalır ve bu da tıkanıklığa gider.

### 5.6 Kova boyutunun etkisi

Sonraki slaytta kova boyutunun trafiğe etkisi grafikle gösterildi. B değeri kovanın boyutunu verir; 16000 KB, 9600 KB ya da 0 olması durumunda trafiğin nasıl şekilleneceği ve ne kadar burst'e izin verileceği karşılaştırıldı. Hızın 200 Mbps ile değişmediği, kova büyükken kısa bir süre (125 ms) çok yüksek bir hızla çıkış yapılabildiği, kova 9600 KB iken bu yüksek hızın daha kısa sürdüğü ve sonra jeton üretimini bekleyerek sabit hızla gidildiği anlatıldı. B = 0 yapılırsa token bucket leaky bucket gibi çalışır: geldikçe çıkarır.

<!-- BELİRSİZ: Bu slayt (Traffic Shaping (3)) karelere düşmedi. Altyazıda "125 ms için 125 Mbps" geçiyor; birimin MB/s mi Mbps mi olduğu ve grafikteki diğer değerler kareden doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Hoca leaky bucket ve token bucket formüllerinin slaytta olmadığını, kitaptan okunması gerektiğini söyledi. Kitaptaki temel ilişki burst süresi için $S = B / (M - R)$'dir; burada $M$ çıkış hattının en yüksek hızı, $R$ jeton hızı, $B$ kova boyutudur. Kitaptaki örnekte büyük olasılıkla $M = 125$ MB/s (1000 Mbps), $R = 25$ MB/s (200 Mbps), $B = 9600$ KB alınır; bu değerlerle $S \approx 9600 \cdot 10^3 / (100 \cdot 10^6) \approx 0{,}096$ s, yani yaklaşık 96 ms bulunur.

## 6. Paket Zamanlama: Round-Robin ve Weighted Fair Queueing

### 6.1 FIFO'nun sorunu

Slayt, paket zamanlamanın router ve hat kaynaklarını trafik akışları arasında FIFO'ya (First In First Out) alternatif yöntemlerle böldüğünü söylüyordu (ekrandan, 01:10:00). İkinci hoca konuya, başta söylenen işlemci zamanlaması benzetmesiyle girdi: birden fazla arayüzden gelen bilgi çoğu zaman başka bir arayüzden çıkarılır. Farklı giriş kuyrukları ve farklı akışlar vardır. Bunlardan saldırgan (greedy), sürekli veri basan bir akış, standart FIFO uygulandığında kuyruğa çok daha fazla paket sokacağı için diğer akışları ezer. Amaç bunu daha adil hale getirmektir.

### 6.2 Round-robin

Genel yöntemin adı işletim sistemlerinden de bilinen round-robin'dir. Slayttaki şekil (ekrandan, 01:10:00):

- Giriş kuyrukları: 1. kuyrukta üç paket (ortadaki dar), 2. kuyrukta iki paket, 3. kuyrukta üç paket.
- Ortada round-robin hizmet.
- Çıkış hattında sırayla (sağdan sola, çıkış yönüne doğru) 1, 2, 3, 1, 2, 3 paketleri.

Şekildeki paket kutularının genişliği paket boyutunu gösterir. Hiçbir kural gözetmeden sırayla birinci, ikinci ve üçüncü kuyruktan paket alındığında: ilk turda birden büyük, ikiden küçük, üçten büyük paket alınır; ikinci turda birden küçük, ikiden büyük paket alınır. İki tur sonunda bir ve iki numaralı kuyruklardan çekilen paketlerin toplam uzunluğu yaklaşık aynıdır. Ama üçüncü kuyruğun ikinci paketi de birincisi gibi büyüktür; böylece üçten dışarıya diğerlerinden daha fazla bit çıkarılmış olur.

Saldırgan biçimde ve büyük paketler gönderen bir uygulama varsa, klasik round-robin uygulandığında bir ya da birkaç kuyruk diğerlerine göre birim zamanda daha fazla bit çıkarır. Paket sayısını bite dönüştürmek gerekir, çünkü bant genişliği bit/s ile ifade edilir. Klasik round-robin dengesiz bir çıkış oluşturma ihtimali yüksek bir yöntemdir.

En temel çözüm bütün paketlerin aynı boyutta olmasıdır, ama bunu her uygulama için sağlamak mümkün olmayabilir. Bir topoloji için bir maksimum paket boyutu belirlenip her noktada uygulanırsa, son paket dışındakilerin hepsi neredeyse aynı boyutta olur; son pakette fark olabilir. Bu konu internetworking'de, IP ile birlikte daha ayrıntılı konuşulacak.

### 6.3 Weighted Fair Queueing (WFQ)

Slayt, Fair Queueing'in farklı paket boyutlarıyla bit düzeyindeki adaleti yaklaşık olarak sağladığını, ağırlıkların hedef düzeyleri değiştirdiğini ve sonucun WFQ (Weighted Fair Queueing) olduğunu söylüyordu (ekrandan, 01:15:00). "Fair" hakkaniyetli, karşılıklı hakları gözeten demektir; kuyruklama yapılır ama kuyruklara ağırlık (weight) verilir.

Hoca bunu işletim sistemlerindeki çok düzeyli kuyruklara (multi-level queue, multi-level feedback queue) benzetti. Orada kuyruklara birbirinin katı olan zaman dilimleri (time quantum) verilirdi: birinden sekiz tane alınınca diğerinden bir tane alınır; bir tur tamamlandığında hepsinden eşit miktarda zaman geçmiş olur. Burada da benzer bir şey uygulanır.

Slaytta pembe yazıyla paketlerin varış sırasından farklı sırayla gönderilebileceği belirtiliyordu. Ağ katmanı paketleri sırasız gönderme hakkına sahiptir, özellikle datagram ağlarında paketler varış noktasında yeniden birleştirilir. Bu biliniyorsa lehe kullanılabilir: birinci kuyruktan belirli uzunlukta bir paket çekildiyse, ikinci kuyruktan en başta değil ikinci ya da üçüncü sırada bekleyen ama uzunluğu ona en yakın paket gönderilebilir; üçüncü kuyruktan da benzer bir paket. Böylece üç kuyruktan da birim zamanda aynı uzunlukta veri çıkar. Sıranın düzeltilmesi varış noktasının işidir. Ayrıca bir kuyrukta bekleyen paketlerin aynı uygulamadan ardışık gelen paketler olduğunun garantisi de yoktur; giriş kuyruklarına farklı hostlardan paketler gelmiş olabilir. Bu yüzden sırayı uzunlukları denk düşecek şekilde bozmak büyük bir karmaşıklık yaratmaz.

Başka bir yaklaşım, paketin gelişiyle çıkışı arasındaki bekleme süresini paket uzunluğuna göre oranlayıp ortalama bekleme süresini eşitleyecek bir normalizasyon yapmaktır. Sonuçta amaç hep aynıdır: farklı kuyruklardan çekilen paketlerin, zamana yayıldığında ortalama olarak birbirine eşit olmasını sağlamak; uzunluk cinsinden, bekleme süresi cinsinden vb.

Slayttaki şekil ve tablo (ekrandan, 01:15:00):

- 1. kuyruk: A, F (F, D'den sonra gelir ama önce gider).
- 2. kuyruk: B, D, H (H geç gelir).
- 3. kuyruk: C, E, G; ağırlık 2 (2X).
- Sanal bitiş zamanı formülü: $F_i = \max(A_i, F_{i-1}) + L_i / W$. Sanal bitiş zamanları iletim sırasını belirler.

| Paket | Varış zamanı | Uzunluk | Bitiş zamanı | Çıkış sırası |
|---|---|---|---|---|
| A | 0 | 8 | 8 | 1 |
| B | 5 | 6 | 11 | 3 |
| C | 5 | 10 | 10 | 2 |
| D | 8 | 9 | 20 | 7 |
| E | 8 | 8 | 14 | 4 |
| F | 10 | 6 | 16 | 5 |
| G | 11 | 10 | 19 | 6 |
| H | 20 | 8 | 28 | 8 |

Tablonun hesabı derste adım adım yapılmadı; aşağıdaki Örnek Sorular bölümünde formülle çözülmüştür.

## 7. Kabul Kontrolü ve Akış Tanımı

### 7.1 Akış tanımı (flow specification)

Slayt, kabul kontrolünün bir trafik akışı tanımını alıp ağın bunu taşıyıp taşıyamayacağına karar verdiğini ve QoS'u karşılamak için paket zamanlamayı kurduğunu söylüyordu (ekrandan, 01:20:00). İkinci hoca, kabul kontrolü yapılacaksa ağa girecek trafiğin tanımlanması gerektiğini açıkladı. Bir noktadan diğerine akan trafiğe akış (flow) denir. Akış cihazlarda işlemci yükü, tampon kullanımı ve bant genişliği kullanımı yaratır, ama bunları doğrudan "hangi trafik hangi router'da ne kadar işlemci yükü yaratır" diye ifade etmek pek mümkün değildir. Bunun yerine, ağın akışın uygun olup olmadığına karar verebileceği başka tanımlayıcı bilgiler gerekir.

Slayttaki örnek akış tanımı (ekrandan, 01:20:00):

| Parametre | Birim |
|---|---|
| Token bucket rate | Bayt/s |
| Token bucket size | Bayt |
| Peak data rate | Bayt/s |
| Minimum packet size | Bayt |
| Maximum packet size | Bayt |

Token bucket'ta bir hız ve bir kova boyutu konuşulmuştu; bunlar parametredir. Veri hızının tavan noktası ve en küçük ile en büyük paket boyutu da parametredir.

### 7.2 Router'ın kararı

Bir sanal devre (virtual circuit) oluşturulacaksa, yol bu parametrelere uygun router'lar üzerinden belirlenebilir ve yol boyunca seçilen router'lar trafiği bu parametrelere göre taşır. Router'lar kendi kapasitelerini bu parametreler cinsinden bildikleri için yeni bir trafiği kabul ederken mevcut kaynaklarının yeni isteği karşılayıp karşılayamayacağına kolayca karar verir. Tampon ve işlem gücü yetiyorsa router akışı kabul eder; karşılayamıyorsa isteği geri çevirmelidir.

İkinci hoca bir seçenek daha ekledi: router doğrudan reddetmek yerine bir alternatif sunabilir, örneğin istenen hızı değiştirerek "şunu karşılayabilirim" diyebilir. Hangisi olursa olsun yönlendirme bu çalışma prensibine bağlı olarak gerçekleşir: sanal devre, ilk giriş noktasından son çıkış noktasına kadar her router'a kabul kontrolü parametreleri aktarılıp "uygun mu" sorusunun cevabına göre adım adım kurulur.

> **Hocanın vurgusu:** Bunun adı flow specification'dır, aklınızda tutun. Bir ağ akışının tariflenmesini sağlar.

### 7.3 Akış nedir?

Akış, iki uygulama arasında ağ tarafından paket paket aktarılan ve gönderen ile alan uygulama açısından aynı sırada olan, birbirini izleyen paketlerdir. Topolojide sanal devre ya da datagram kullanılmasına bağlı olarak bu paketler ağ içinde gerçekten sıralı ya da sırasız ilerleyebilir; ama buna yine akış denir. TCP/IP'ye geçildiğinde bir akışın hangi ölçütlerle tanımlandığı ayrıntılı görülecek: kaynak adresi, hedef adresi, kaynak portu, hedef portu ve protokol.

### 7.4 Bant genişliği ve gecikme garantisi

Sonraki slayt, bant genişliği B ve gecikme D garantisi için kurulacak yapıyı veriyordu (ekrandan, 01:25:00):

- Trafik kaynağı (R, B) token bucket ile şekillendirilir.
- WFQ, ağırlık $W / \sum \text{ağırlıklar} > R / \text{kapasite}$ olacak şekilde çalıştırılır.
- Bu, bütün trafik desenleri ve bütün topolojiler için geçerlidir.

Şekilde solda (R, B) trafik kaynağı, ortada içinde ağırlıkları $w_i$, $W$, $w_i$ olan kuyrukları bulunan bir router (weighted fair queue), sağda kapasitesi C olan çıkış hattı ve koşul $R < \dfrac{W \times C}{\sum \text{weights}}$ görülüyordu.

Trafik kaynağı router'a girerken parametrelerini (token bucket ile ilgili parametreler, gecikme beklentisi) belirtir. Bu trafik router'da uygun bir kuyruğa eşlenir: "bu trafiğin özelliği buysa, bende bu tarz trafik için şu kuyruk var" denir ve trafik o kuyruktan round-robin/WFQ mantığıyla çıkarılır. Slayttaki "bütün topolojiler için geçerli" ifadesi bunun topolojinin tamamında uygulanması gerektiğini anlatır: tek bir router'ın bunu yapması yetmez, yol üzerindeki router'ların bunu ortak uygulaması gerekir.

## 8. Integrated Services ve RSVP

### 8.1 Integrated services

Integrated services ile her akış için QoS parametreleri verilebilir. Aynı zamanda çok noktaya yayın (multicast) trafiği diğer trafiklerle bir arada taşınabilir. Multicast'te bir kaynak bir bilgiyi topolojinin tamamına değil bir gruba ortak olarak yollar ve grup üyeleri bilgiyi neredeyse eş zamanlı alır; bu özellikle video ve audio on demand için önemlidir.

Kabul kontrolü uygulanmalıdır. Integrated services'in mantığı zaten budur: yeni trafik mevcut yapıya entegre edilir, ama hangi özelliklerle entegre edileceği kabul kontrolüyle belirlenir. Burada kullanılan protokolün adı RSVP'dir (Resource Reservation Protocol, kaynak ayırma protokolü).

### 8.2 RSVP örneği

Slayttaki üç şekil (ekrandan, 01:30:00) aynı ağı gösteriyordu: üstte 1 ve 2 numaralı kaynaklar (yayın yapanlar), altta 3, 4 ve 5 numaralı alıcılar (yayını izlemek isteyenler), arada A-L ile adlandırılmış router'lar.

- Sol şekil, "R3 reserves flow from S1": alıcı 3, kaynak 1'den yayın için J, H, E ve A üzerinden bant genişliği ayırır. Rezervasyon 3'ten 1'e doğru giden bir istekle yapılır; alıcı yayına bir tür abone olur ve gereken bant genişliği ve diğer parametreler bu yol üzerinde ayrılır.
- Orta şekil, "R3 reserves flow from S2": aynı alıcı, örneğin resim içinde resim gibi bir yandan 1'i izlerken bir yandan 2'yi de izlemek isterse J, H, E ve C üzerinden ikinci bir yol oluşur.
- Sağ şekil, "R5 reserves flow from S1; merged with R3 at H": multicast mantığının asıl oturduğu yer burasıdır. Alıcı 5, kaynak 1'in yayınını izlemek istediğinde A ile E ve E ile H arasında alıcı 3 için ayrılmış bir kaynak zaten vardır. Örneğin alıcı 3 yüksek çözünürlükte, alıcı 5 daha düşük çözünürlükte izliyorsa ve 3'ün ayırdığı bant genişliği 5'in ihtiyacını karşılıyorsa, 5'in isteği mevcut ayırmaya dahil edilir (entegre edilir). Yeni bir akış başlatılmaz; akış H noktasına kadar zaten gelmektedir, oradan dallanıp H'den L'ye, L'den 5'e gider.

Dikkat edilecek nokta, bu işi alıcıların başlatmasıdır. Bir tarafın istemci, diğer tarafın sunucu olduğu bu yaklaşım daha çok video on demand ve sayısal yayın için kullanılır.

## 9. Differentiated Services

### 9.1 Sınıf tabanlı hizmet

İkinci hoca differentiated services'i anlattı. Bu kabaca iki şekilde yapılabilir: Expedited Forwarding ve Assured Forwarding. Amaç farklı trafik sınıfları oluşturmak ve her sınıfa nasıl davranılacağını belirlemektir.

En basit seviyede trafik sıradan ve önemli (aciliyeti yüksek) diye ikiye ayrılır. Sıradan trafik için bir kanal vardır ve bütün normal paketler buraya konur. Ne zaman geleceği bilinmeyen bir grup özel paket için ise kaynak önceden ayrılıp tutulur; bu paketler geldiğinde o kaynak üzerinden gönderilir ve sıradan trafiğin karmaşasına girmeden geçer. Bu Expedited Forwarding'dir.

Hoca günlük hayattan benzetmeler verdi: kargo firması paket gönderirken normal mi, bir günlük mü diye sorar; eğlence parklarında herkesin girdiği normal bir kuyruk ve ek ücret ödeyenlerin doğrudan geçtiği hızlı bir kuyruk vardır. Diğer hoca "önemli" yerine "aciliyeti yüksek" demeyi önerdi.

### 9.2 DiffServ'in uygulanışı

Slayttaki DiffServ uygulaması (ekrandan, 01:35:00):

- Müşteriler istenen sınıfı paketin üzerine işaretler.
- ISP, işaretlerin karşılığının ödendiğinden emin olmak için trafiği şekillendirir.
- Router'lar farklı hizmet düzeyleri vermek için WFQ kullanır.

Şekilde paket kaynağı, bir sınıflandırıcı (classifier, dört öncelik sınıfı), bir polis (policer, on iki öncelik/düşürme sınıfı), DiffServ işaretli paketler ve içinde Gold, Silver, Bronze ve bir dördüncü kuyruk bulunan bir router (weighted fair queues) görülüyordu.

Bu Assured Forwarding'e karşılık gelir: farklı hizmet sınıfları oluşturulur ve her sınıfta, paket düşürülmesi gerektiğinde hangisinin nasıl düşürüleceğini belirleyen ayrı düşürme sınıfları tanımlanır. Bunların çaprazlanmasıyla çok sayıda sınıf ortaya çıkar. Bu yapı, ISP'nin kullanıcı trafiğini sınıflandırıp tıkanıklık anında hangilerini düşüreceğini ve hangilerine öncelik vereceğini belirlemesine çok uygundur.

> **Ek bilgi (derste anlatılmadı):** Assured Forwarding standart olarak dört öncelik sınıfı ve her birinde üç düşürme olasılığı tanımlar; slayttaki on iki sınıf büyük olasılıkla bu $4 \times 3$ çarpımından gelir.

### 9.3 Gerçek hayattaki örnekler

İkinci hoca bugün neredeyse bütün ISP'lerin bu mantıkla çalıştığını söyledi. Bir operatörün IPTV kutusu örneğini verdi: kutu ayrı bir cihazdır ve fiber bağlantıda kutunun bağlandığı port, modemin yapılandırmasında "IPTV kutusu bağlantısı" olarak işaretlenir. Bu trafik etiketlenir ve eve de etiketli olarak gelir. Bu, DiffServ'in statik bir uygulamasıdır. Hücresel ağlarda da yalnız tabletlerde kullanılan veri hatlarının trafiği benzer biçimde etiketlenir ve router'lardan geçerken buna göre davranılır.

Slayttaki örnekte trafik altın, gümüş, bronz ve geri kalanı (hocanın deyişiyle "teneke") olmak üzere dört sınıfa ayrılmıştır; bu da WFQ'nun farklı bir uygulamasıdır. İkinci hoca, mekanizmanın RFC'lerde tanımlı olduğunu, ama altın, gümüş ve bronz adlarının kitabın örneği olduğunu, olayın bu adlar olmadığını vurguladı.

## Örnek Sorular

**Soru 1** (ekrandan, 01:15:00): Üç giriş kuyruğu olan bir WFQ router'ında 1. kuyrukta A ve F, 2. kuyrukta B, D ve H, 3. kuyrukta (ağırlık 2) C, E ve G paketleri vardır. Varış zamanları ve uzunluklar: A (0, 8), B (5, 6), C (5, 10), D (8, 9), E (8, 8), F (10, 6), G (11, 10), H (20, 8). $F_i = \max(A_i, F_{i-1}) + L_i/W$ formülüyle her paketin sanal bitiş zamanını ve çıkış sırasını bulun.

> **Çözüm (derste verilmedi):** $F_{i-1}$ aynı kuyruktaki bir önceki paketin bitiş zamanıdır; 1. ve 2. kuyrukta $W = 1$, 3. kuyrukta $W = 2$.
>
> - 1. kuyruk: A: $\max(0, 0) + 8 = 8$. F: $\max(10, 8) + 6 = 16$.
> - 2. kuyruk: B: $\max(5, 0) + 6 = 11$. D: $\max(8, 11) + 9 = 20$. H: $\max(20, 20) + 8 = 28$.
> - 3. kuyruk: C: $\max(5, 0) + 10/2 = 10$. E: $\max(8, 10) + 8/2 = 14$. G: $\max(11, 14) + 10/2 = 19$.
>
> Bitiş zamanına göre sıra: A (8), C (10), B (11), E (14), F (16), G (19), D (20), H (28). Buna göre çıkış sıraları A=1, B=3, C=2, D=7, E=4, F=5, G=6, H=8 olur ve slayttaki tabloyla aynıdır (python ile kontrol edildi). F, D'den sonra gelmesine rağmen D'den önce gider.

**Soru 2** (derste sözlü, 01:00:05): Leaky bucket benzetmesinde kovanın taşması, yani yeni gelen suyun kovada duramaması ağda ne anlama gelir?

> **Cevap (derste verildi):** Router ya da hosttaki ağ arayüzüne bağlı tamponların dolduğu ve yeni gelen paketlerin işlenemeyip düşürüldüğü anlamına gelir. Kova taşsa bile çıkış hızı değişmez.

**Soru 3** (derste sözlü, 01:03:49): Token bucket'ta 10 tur boyunca trafik gelmediği için 10 jeton birikmişse, ardından gelen burst en fazla ne kadar sürebilir? Jetonlar bitince trafik neye dönüşür?

> **Cevap (derste verildi):** Burst en çok biriken 10 jetonun karşıladığı kadar sürer. Jetonlar bitip trafik gelmeye devam ederse çıkış jeton üretim hızında sabit bit hızına (CBR) döner.

**Soru 4** (derste sözlü, 01:07:30): Token bucket'ın kova boyutu B sıfır yapılırsa token bucket nasıl çalışır?

> **Cevap (derste verildi):** Leaky bucket gibi çalışır: jeton biriktiremediği için burst'e izin vermez, paketleri geldikçe sabit hızla çıkarır.

**Soru 5** (derste sözlü, 01:21:35): Bir router, akış tanımında belirtilen parametreleri kaynakları yetmediği için karşılayamıyorsa ne yapmalıdır?

> **Cevap (derste verildi):** İsteği geri çevirmelidir. Diğer hocanın eklediği gibi doğrudan reddetmek yerine, örneğin hızı değiştirerek karşılayabileceği bir alternatif de önerebilir.

**Soru 6** (derste sözlü, 00:45:29): İndirme ve yükleme hızları arasındaki büyük fark her yerde böyle midir?

> **Cevap (derste verildi):** Kullanılan altyapıya bağlıdır. ADSL ve kablo modem asimetriktir; ev kullanıcısı hizmet alan taraf olduğu için eve gelen yöne daha çok kapasite verilir.

## Dersin Toparlaması

Bu derste hizmet kalitesi baştan sona işlendi. Önce farklı uygulamaların bant genişliği, gecikme, jitter ve kayıp açısından farklı taleplerde olduğu görüldü ve bu talepler ATM'den gelen CBR, gerçek zamanlı VBR, gerçek zamanlı olmayan VBR ve ABR hizmet kategorileriyle eşleştirildi. Ardından ağa giren trafiğin ortalama hızını ve burst'ünü sınırlayan iki yöntem, sabit hızlı leaky bucket ve biriken jeton kadar burst'e izin veren token bucket anlatıldı. Router'da kuyruklar arasında adaleti bit düzeyinde sağlamak için round-robin'in eksikliği ve sanal bitiş zamanlarıyla çalışan WFQ incelendi.

Son bölümde bu parçalar birleştirildi: akış tanımıyla kabul kontrolü yapılır, kaynak token bucket ile şekillendirilir ve router'larda uygun ağırlıklı WFQ ile bant genişliği ve gecikme garanti edilir. Bunun akış başına uygulanan biçimi RSVP ile integrated services, sınıf başına uygulanan biçimi ise Expedited ve Assured Forwarding ile differentiated services'tir. Bir sonraki konu internetworking'dir; orada IP ile başlanacak ve bir akışın kaynak/hedef adresi, kaynak/hedef portu ve protokolle nasıl tanımlandığı ayrıntılı görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
