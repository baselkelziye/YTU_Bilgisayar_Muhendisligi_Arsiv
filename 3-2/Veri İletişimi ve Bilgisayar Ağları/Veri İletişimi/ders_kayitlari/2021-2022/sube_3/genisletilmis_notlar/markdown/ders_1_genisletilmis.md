# Ders 1 Genişletilmiş Notu: Veri İletişimine Giriş, Ağların Sınıflandırılması ve Topolojiler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynak
- 2. İletişim ve Haberleşme
- 3. İletişimin Kısa Tarihi
- 4. Veri İletişiminin Temel Parçaları ve Protokol
- 5. İyi Bir İletişimin Özellikleri: Teslim, Doğruluk, Zamanında İletim, Jitter
- 6. Bilgisayar Ağlarının Faydaları
- 7. Ağları Değerlendirme Ölçütleri
- 8. Devre Anahtarlamalı ve Paket Anahtarlamalı Ağlar
- 9. Ağ Mimarisi: Katmanlı ve Çapraz Katmanlı Yaklaşım
- 10. Standartlar ve Standart Kurumları
- 11. Ağların Sınıflandırılması
- 12. Ağ Topolojileri
- 13. İletim Modları
- 14. Adresleme Modelleri
- 15. Veri Akışı, Bit Hızı ve Birimler
- 16. Verim (Throughput) ve Protokol Ek Yükü
- 17. Cevap Süresi ve Jitter
- 18. Hız Tabloları

## 1. Dersin Kapsamı ve Kaynak

Ders, Veri İletişimi dersinin ilk haftasıdır ve online yapılan 3. gruba aittir. Bu dersi Dr. Ziya Cihan Tayşi anlattı; hoca kendini derse başlarken tanıttı.

Dersin kapsamındaki konular alt seviye protokol ve teknolojilerdir: fiziksel katman (physical layer), veri bağı katmanı (data link layer) ve ortama erişim denetimi (medium access control, MAC).

Ders sonunda bir öğrenci kaynak sordu. Hoca, Tanenbaum'un *Computer Networks* kitabını önerdi. Bu kitap Ağ Teknolojileri dersinin de ana kaynağıdır. Orada ağ katmanından (network layer) itibaren anlatılır, ama kitapta öncesi de vardır. Hocaya göre 5. baskı yeterlidir. Bu derste konuşulanların çoğu kitapta vardır.

## 2. İletişim ve Haberleşme

Hoca derse, sık karıştırılan iki kavramı ayırarak başladı. Bu karışıklık bu dersin notlarında bile zaman zaman görülebilir.

- **İletişim:** Alt seviyedir. Yalnızca bir verinin bir yerden bir yere iletilmesi eylemidir.
- **Haberleşme:** Daha üst seviyedir. Anlamlı bilginin aktarılması ve alınmasıdır.

İnsan açısından bakınca, iki kişi arasında "merhaba, merhaba" gibi temel bir veri aktarımı iletişimdir. Bu sözlü olabileceği gibi işaretle de olabilir. Kaşınızla, gözünüzle, başınızla, bir gözünüzü kırparak ya da el sallayarak da iletişim kurarsınız. Yani iletişim farklı ortamlarda ve farklı şekillerde gerçekleşebilir.

Bilgisayar söz konusu olduğunda iletişim, bir ortam (medium; çoğulu media) üzerinden en az iki taraf arasında sayısal (digital) bilginin, yani sıfır ve birlerin aktarılmasıdır. Bunun için üç şey gerekir:

- **Ortam:** Bilgiyi aktardığımız ortam bir tel, iki tel, beş ya da sekiz tel olabilir. Hava da olabilir. Bu durumda radyo frekansı, kızılötesi (infrared) ya da gözle görülen ışık gibi farklı sinyaller kullanılabilir.
- **Donanım:** Bilgisayarı haberleşme ortamına bağlayan bir donanım gerekir.
- **Yazılım (protokol yığını):** Bu donanım üzerinde çalışan bir yazılım grubu gerekir. Hoca iletimi yalnızca verinin bir noktadan diğerine taşınması olarak görmememizi istedi. Verinin güvenilirliği, doğru yere gitmesi, oluşabilecek hatalardan arınması gibi bütün işlevleri bu yazılım grubu sağlar. Buna protokol yığını (protocol suite/stack) denir.

## 3. İletişimin Kısa Tarihi

Hocaya göre iletişimin tarihi insanlık tarihi kadar eskidir. İlk insanlar muhtemelen bağırıp çağırarak, garip sesler çıkararak anlaşıyordu. İletişim yüz yüze kurulabilir. Bunun için görüş hattı (line of sight) gerekir, yani birbirimizi görmemiz ve sesimizi duymamız gerekir. Ama iletişim daha uzak bir mesafeden de yapılabilir. Yunancada "uzak" anlamına gelen "tele" ile birleşince buna telekomünikasyon (telecommunication) deriz.

Hoca, yazılı alfabenin ortaya çıkışını Babil dönemine bağladı. Farklı coğrafyalardaki haberleşme tekniklerini saydı. Her birinde farklı bir ortam ya da araç kullanılır:

- Afrika'da tamtamlar.
- Kuzey Amerika'da duman.
- Avrupa'da bayraklar.
- Asya'da kuşlar.

Yakın geçmişte telgraf, telefon, radyo ve televizyon geldi. Bugün ise doğrudan bilgisayar ağlarını kullanan teknolojiler var: Metro Ethernet, fiber, ADSL. Bunların üzerine eklemeye ve değiştirmeye devam ediyoruz.

## 4. Veri İletişiminin Temel Parçaları ve Protokol

Bir veri iletişiminden bahsediyorsak ortamda bulunması gereken parçalar şunlardır:

- **İletişim ortamı (medium):** Haberleşme için bir ortam gerekir.
- **Mesaj:** Ortam tek başına yetmez. İletmek istediğiniz bir veri olmalıdır. Tipi değişebilir, ama gönderilecek bir ileti gerekir.
- **Gönderici ve alıcı:** Bir öğrencinin de söylediği gibi, mesaj alıcının anladığı kadardır. Bu yüzden bir alıcı ve mesajı ona gönderecek bir gönderici olmalıdır.
- **Protokol:** Bu iletişim ortamının nasıl kullanılacağını belirleyen kurallar bütünü.

### 4.1 Sınıf Ortamında Protokol

Hoca protokolü sınıf ortamıyla anlattı. Sınıfta hoca dersi anlatırken haberleşme ortamını kendisi kullanır. Hoca konuşur, herkes dinler. Hoca gönderir, öğrenciler alır. Öğrencilerin bir şey gönderebilmesi için söz almaları gerekir. Bunu iki yolla yaparlar:

- **El kaldırmak:** Bu görsel bir yoldur. Burada bant dışı (out-of-band) bir kontrol kanalı kullanılır. Veri için ayrı, kontrol için ayrı bir hat vardır. Hoca bunu ileride ayrıca konuşacaklarını söyledi.
- **Konuşmanın arasına girmek:** Öğrenci hocanın bir aralık vermesini bekler, sonra söze girer. Bu aslında taşıyıcı dinlemeli çoklu erişimdir (carrier sense multiple access). Önce hatta konuşan biri var mı diye bakılır. Hat boşsa konuşulur.

Bunlar alt seviyedeki protokollerdir. Üst seviyede de başka protokoller vardır. Hocayla, askerlik arkadaşınızla konuştuğunuz gibi konuşmazsınız. Annenizle, küçük kardeşinizle, dedenizle başka başka konuşursunuz. Yani farklı kuralları, farklı protokolleri izlersiniz.

## 5. İyi Bir İletişimin Özellikleri: Teslim, Doğruluk, Zamanında İletim, Jitter

Temel parçaların bulunması belli açılardan yeterlidir, ama tam değildir. Gerçek anlamda bir iletişimden bahsedebilmek için bazı özellikler de gerekir.

### 5.1 Doğru Adrese Teslim (Delivery)

Bir veriyi A'dan B'ye gönderiyorsam, B'ye gittiğinden emin olmalıyım. Hoca bunu "kızım sana söylüyorum, gelinim sen anla" deyimiyle karşılaştırdı. Bilgisayarlar böyle çalışmaz. B'ye gönderiyoruz diye yola çıkıp veriyi D'ye ya da Z'ye göndermenin anlamı yoktur. Bilginin başka yere gitmesi iletişimin karakterine aykırıdır.

### 5.2 Doğruluk (Accuracy)

Hoca kulaktan kulağa oyununu hatırlattı. Bir cümle birinin kulağına söylenir, o diğerine, o da bir sonrakine aktarır. En uçta bambaşka bir şey çıkar, yani bir çöp (garbage) oluşur. İletişim olarak bunun faydası yoktur. Veri iletişiminde, aktarılan verinin bütünlüğünün ve doğruluğunun bozulmadan, göndericiden çıktığı şekliyle alıcıya ulaşmasını bekleriz.

### 5.3 Zamanında İletim (Timeliness)

Çoğu zaman bilginin alıcı tarafından zamanında alınmasını da bekleriz. Aktardığınız şey görüntü ya da ses ise, gecikmiş verinin çoğu zaman bir anlamı yoktur.

Hocanın örneği gerçek zamanlı yayındı (real-time streaming). Bir muhabir olay yerinden canlı bildiriyor. Konuşma sırasında görüntü paketlerinin bir kısmı gecikmeye başlarsa görüntü bozulur. Ama hayat akmaya devam eder. 2 saniye önceki görüntünün 2 saniye sonra varmasının anlamı yoktur. Bu veri atılır (discard).

Bunun daha az etkilendiği durum isteğe bağlı video (video on demand) platformlarıdır. Netflix, YouTube gibi bir platformda video izlerken sistem arka planda önbelleğe alma (caching) yapar. Siz $T$ anını izlerken $T+1$, $T+2$ ve 20, 30, 40 saniye ya da birkaç dakika ilerisine kadar olan bilgi arkada alınır ve önbelleğe konur. Bu yüzden ileriye doğru gecikmiş bilgi sorun olmayabilir. Yani zamanında iletimin önemi, aktarılan verinin tipine de bağlıdır.

Yine de zamanında iletim, veri iletişiminin kalitesini değerlendirirken her zaman konuşulacak bir parametredir. Bunun alt başlıkları şunlardır:

- **Hat gecikmesi:** Kullanılan ortamın karakteristiğinden gelir. Kablo üzerinde bakır mı fiber mi olduğuna göre değişir. Mesafeye göre değişir. Uydu üzerinden haberleşiyorsanız ona göre değişir. Kullanılan protokole göre de değişir.
- **Paket gecikmesi:** Paket anahtarlamalı ağlarda her paketin gecikmesidir.
- **Paket gecikmeleri arasındaki dalgalanma:** Paketleriniz bazen zamanında gidiyor, bazen gecikiyor. Geciken paketler bir 5 saniye gecikiyor, bir saniye erken geliyor, bir 10 saniye gecikiyor. Bu değişken gecikmeye bilgisayar ağlarında jitter denir. Jitter hattın kalitesinin bir ölçüsüdür.

Jitter konusuna dersin sonunda bir şekille geri dönüldü (Bölüm 17).

## 6. Bilgisayar Ağlarının Faydaları

Hoca aradan sonra "Biz niye bilgisayar ağı kullanıyoruz?" sorusuyla devam etti. Teknik olarak birkaç neden var.

### 6.1 Kaynak Paylaşımı

Bir ofiste, çalışma ortamında ya da evde çıktı almak isteyen herkese ayrı yazıcı almak yerine, yazıcıyı ve cihazları ağa bağlayıp ortak kullanırız. Veriyi kendi aramızda paylaşmak için de ağ gerekir. Yedek almak için bile tek bir yedekleme mekanizması kurup herkesin oraya yedek almasını isteriz.

### 6.2 Yük Dengeleme (Load Balancing) ve Hata Toleransı

Aynı işi yapan birden fazla cihaz bulundurup, cihazlardaki yüke göre işin birinden diğerine geçmesini sağlarız. Hocanın örneği üniversitenin OBS servisiydi. Bu servisi tek bilgisayarla verirseniz bütün istekler aynı yere gider. Bilgisayar fiziksel sınırına ulaşınca devre dışı kalır ve isteklere cevap veremez.

Bunun yerine birkaç bilgisayarı yan yana koyabilirsiniz. İki yol var:

- Önlerine bir yük dengeleyici (load balancer) koymak.
- İsim sunucusu (name server) üzerinden istekleri farklı cihazlara yönlendirmek.

Üç bilgisayar koyduysanız, her üç istekten biri bir sunucuya gider. Bunun yan faydası da vardır. Aynı servis üç makinede çalıştığı için birinin başına bir şey gelirse performans düşer, ama servis devam eder. Tek makinede olsaydı, cihaz çalışmayınca olay biterdi.

### 6.3 Pahalı Merkezi Sistemler Yerine Ağ

Merkezi ve güçlü sistemler kurmak her zaman daha maliyetlidir. Hocanın örneği ana bilgisayarlardı (mainframe). Bunlar yüksek güvenilirlik açısından en ileri (state of the art) yapılardır, ama pahalıdır. Bunun yerine sıradan donanımla (commodity hardware) kurulan bilgisayarları ağ üzerinden birbirine bağlayarak benzer güvenilirlik ve performansta bir sistem kurulabilir. Böylece tasarruf edilir.

### 6.4 Etkin Haberleşme

Kişiler telefonla, dumanla, el kol hareketiyle de haberleşebilir. Ama bilgisayar ağları etkin bir şekilde haberleşmeyi sağlar.

## 7. Ağları Değerlendirme Ölçütleri

Hoca, zamanında iletimden bahsederken bunun ağı değerlendirme ölçütlerinden biri olduğunu söylemişti. Ölçütleri sırayla anlattı.

### 7.1 Başarım (Performance)

Verinin ne kadar sürede iletildiği, ne kadar sürede cevap alındığı, birim zamanda ne kadar veri aktarılabildiği başarım ölçütleridir. Bunların bir kısmı ortamın özelliğine göre değişir. Kablosuz (wireless) haberleşmede ortamdaki su dolu bir tankın ya da engellerin haberleşmeyi kötü etkileyeceğini biliyoruz. Optik bir haberleşmede bulutlu ya da yağmurlu havanın başarımı değiştireceğini biliyoruz. Bu durumda farklı koşullarda ölçüm yapıp ortalama alabiliriz.

### 7.2 Servis Kalitesi (Quality of Service, QoS)

QoS hem bir değerlendirme ve ölçme ölçütü, hem de bir tanımlama ölçütüdür. Kişisel ağlar ve firma içi ağlar (intranet) dışındaki birçok ağda bir ağ operatörü bulunur. O ağ üzerinde de servis alan kişi ve kurumlar vardır. Bu kişilerin alacağı servisler belli parametrelerle tarif edilir ve anlaşmaya bağlanır. Bunlara QoS metrikleri denir. Hangi metriklerin kullanılacağı ağın devre anahtarlamalı mı paket anahtarlamalı mı olduğuna bağlıdır (Bölüm 8).

### 7.3 Güvenilirlik (Reliability, Availability)

Bir ağın ne derece güvenilir olduğunu ölçmek için şunlara bakılabilir:

- Ağın ne kadar süre hatasız ayakta kaldığı.
- Bağlantının (connectivity) ne kadar devam ettiği.
- Bir kopukluk varsa ağın ne kadarının koptuğu, ne kadarının çalışmaya devam ettiği.

### 7.4 Güvenlik (Security)

Aktardığımız veri isteğimiz dışında başka yerlere gidiyor mu, başkaları tarafından ele geçiriliyor mu? Ya da ağın çalışması devre dışı bırakılabiliyor mu? Güvenlik bu soruları kapsar.

### 7.5 Ölçeklenebilirlik (Scalability)

Hocanın örneği: 10 kişi için bir ağ tasarladınız, mükemmel çalışıyor. Ama 11. kişiyi bağladığınızda her şey çöktü. Bu istenen bir şey değildir. Ağ en küçükten en büyüğe farklı ihtiyaçları karşılayabilmeli, zamanla artan isteklere göre genişletilebilmelidir. Yani bağlı uç ya da düğüm sayısı artırılabilir olmalıdır.

### 7.6 Uyumluluk

Zaman içinde ortaya çıkan farklı ihtiyaçlar için birbirinden çok farklı nitelikte servisler vermek gerekir. Ağın bu ihtiyaçları karşılayabilmesi de bir değerlendirme ölçütüdür.

## 8. Devre Anahtarlamalı ve Paket Anahtarlamalı Ağlar

Hoca QoS'u anlatırken ağları yapılarına göre ikiye ayırdı.

### 8.1 Devre Anahtarlamalı Ağ (Circuit Switching)

Bugünden örnek, eski ev telefonu ağıdır (cep telefonu değil). Eski filmlerde santralde bir operatör görülür. Elinde kablo vardır, kabloyu bir yere takar, bir başka yere takar, insanlarla konuşur. Yaptığı şey devre anahtarlamadır.

Eskiden birini aramak istediğinizde telefonu kaldırır, operatöre bağlanır, nereyi aramak istediğinizi söylerdiniz. Hat ve müsaitlik varsa operatör sizi bir üst kademeye bağlardı. Bir üst kademede boşluk varsa o da sizi aktarırdı. Telefon şebekesinde eskiden 5 kademeli bir yapı vardı. Şehirlerarası bir aramada ülkenin bir ucundan diğerine 5. kademeye kadar çıkıp 5 kademe geri inilirdi. İki nokta arasında toplam 12 kadar anahtarlama yapılarak bir hat oluşurdu.

Sonuçta aranızda fiziksel olarak bir devre kurulur ve bilgi bu devreden akar. Konuşma devre kurulduktan sonra başlar. Yani bir bağlantı kurulum süresi vardır. Bu tür bir hatta servis kalitesi şu metriklerle tanımlanır:

- Bit hızı (bit rate).
- İletim gecikmesi (transmission delay).
- Ortalama hata miktarı.

### 8.2 Paket Anahtarlamalı Ağ (Packet Switching)

Burada bağlantı kurmakla uğraşmazsınız. Elinizdeki bilgiyi paketler hâlinde bir sonraki atlamaya (hop) gönderirsiniz. Hoca bunu "suya bırakır gibi bırakmıyorsunuz" diye açıkladı. Bir sonraki düğüm, paketin gideceği ve geldiği yere bakarak bir karar verir ve paketi bir sonrakine yönlendirir. O da bir sonrakine yönlendirir.

Gönderdiğiniz her paket farklı yollardan gidebilir. Devre anahtarlamalı ağdaki gibi bütün paketlerin aynı yoldan gitmesi, aynı şeylere maruz kalması söz konusu değildir. Paketler farklı gecikmelere uğrayabilir. Hoca "sürüden ayrılanı kurt kapar" deyimiyle bazı paketlerin son hedefe hiç varamayabileceğini anlattı. Bu yüzden paket anahtarlamalı ağlarda farklı servis parametreleri kullanılır.

## 9. Ağ Mimarisi: Katmanlı ve Çapraz Katmanlı Yaklaşım

Ağ mimarisi derken genel bir yaklaşımdan, bir çatıdan bahsediyoruz. Farklı ağlarda farklı mimariler görülür, ama iki genel yaklaşım vardır.

### 9.1 Katmanlı Yaklaşım (Layered Approach)

Ağ üzerinde gerçekleştirilmesi gereken işlevler katmanlar hâlinde gruplanır. Bugün bilgisayar ağları denince konuşulan ve öğretilen her şey OSI referans modeline dayanır. OSI'de 7 katman vardır:

- Fiziksel katman (physical layer).
- Veri bağı katmanı (data link layer). Ortama erişim denetimi (MAC) de vardır, ama ayrı bir katman olarak sayılmaz.
- Ağ katmanı (network layer).
- Taşıma katmanı (transport layer).
- Oturum katmanı (session layer).
- Sunu katmanı (presentation layer).
- Uygulama katmanı (application layer).

TCP/IP'de çok daha az, dört katman vardır. Ama orada da ağ işlevlerinin bir araya getirildiği katmanlar bulunur.

Katmanlı yapının kuralı şudur: Her katman mümkün olduğu kadar kendi içinde kalır. Üstündeki katmana servis verir, altındaki katmandan servis alır. OSI çok düzgün tanımlanmış bir referans modeli olduğu için bu kurallara uyar. TCP/IP'de ise iki katman arasında tam olarak nereye ait olduğu belli olmayan, "2,5. katman" denebilecek durumlar vardır. Hoca bunu ileride konuşacaklarını söyledi.

### 9.2 Çapraz Katmanlı Yaklaşım (Cross-Layer Approach)

Bazı ağlarda katmanlı mimari, ağın ya da uygulamanın gereksinimleri yüzünden bayağı delinebilir. Hocaya göre en güzel örnek algılayıcı ağlarıdır (sensor networks). Normalde yönlendirme (routing) kararını ağ katmanı verir. Ama uygulamanın kısıtları ya da ortamın şartları yüzünden uygulama yönlendirmeye müdahale edebilir. Yönlendirme katmanı da MAC'e müdahale edebilir. Bir katman bir alt katmana değil, iki üç katman aşağıya doğrudan uzanır. Bu yaklaşıma çapraz katmanlı yaklaşım denir.

## 10. Standartlar ve Standart Kurumları

### 10.1 Ağın Değeri ve Standart İhtiyacı

Hocaya göre bir bilgisayar ağının değeri, ona bağlanabilen cihaz sayısıyla doğrudan ilişkilidir. Hoca şöyle sordu: Evinizdeki ağın değerini ne olarak görüyorsunuz? Yıldız Teknik Üniversitesi'nin ağının? Türkiye'deki bütün üniversitelerin bağlı olduğu ULAKNET'in? İnternetin? Cevap açıktır. Değer bu sırayla artar.

Bu bağlantılılığı (connectivity) sağlamak için birbiriyle uyumlu yapılar gerekir. Bunun için de standartlar gerekir.

Hocanın standartsızlık örneği yazılabilir DVD'lerdi. Bir DVD-R vardı, bir de DVD+R vardı. İkisinin yaklaşımı tamamen farklıydı, birbiriyle uyumlu (compatible) değildi. Bir türü diğer yazıcıda yazamıyordunuz. Yazdığınız DVD'yi bazen diğerinde okuyamıyordunuz. Çünkü her firma ürününü kendi belirlediği özelliklere göre üretiyordu. Benzer ürün ve hizmet üreten firmaların sayısı artınca bunların birbiriyle uyumlu olması gerekir.

Standart, imalat sürecinde bir örneğin temsil edilmesidir: "Bu böyle olmalı." Teknik olarak herkesçe kabul görmüş ölçü birimlerini ve ayarlamaları ifade eder. Günlük hayattan bir örnek: Gömleklerde düğmelerin hangi tarafta olduğu, gömleğin kadın ya da erkek gömleği olduğunu belirleyen bir standarttır.

### 10.2 De Jure ve De Facto Standartlar

Veri iletişimi standartlarında iki temel durum vardır:

- **De jure:** Resmî kurumlarca belirlenmiş ve onaylanmış standartlar.
- **De facto:** Geliştirme faaliyetleri ve elde edilen deneyimler sonucunda ortaya çıkan standartlar. Biri "şöyle bir şey yapalım" diye yola çıkar, bilgi ve deneyim edinir, "bu iş böyle olmalı" der ve standardı belirler.

De facto standartlar çoğu zaman ticari bir kurumdan çıktığı için açık ya da kapalı olabilir:

- **Kapalı standart:** Yalnızca standardın sahibi firmanın kendi ürün ve hizmetinde kullanabildiği yapılardır.
- **Açık standart:** Firma tarafından herkese açılmış, o işi yapan herkesin uygulayabileceği yapılardır.

De facto örnekleri: QWERTY klavye düzeni, VHS video, PDF. PDF de facto olarak başlayıp sonra de jure olmuştur. Hoca bunun 2000'lerin başında bir yerde olduğunu söyledi.

> **Ders sonrası not:** PDF büyük olasılıkla 2008'de ISO 32000-1 olarak uluslararası standart olmuştur. Arşiv sürümü PDF/A ise büyük olasılıkla 2005'te standartlaşmıştır. Hocanın "2000'lerin başı" ifadesi bu aralığı kabaca karşılar.

### 10.3 Standart Kurumları

Telekomünikasyon dünyasında standartları belirleyen kurumlar şunlardır:

- **ISO:** Ülkelerin standart örgütlerinin, devletlerin ve uluslararası örgütlerin bir araya geldiği, standartları uluslararası düzeyde ortaya çıkarmaya ve birleştirmeye çalışan kurum.
- **ITU:** Telekomünikasyon standartları kurumu.
- **IEEE:** Devlet ajansı değil, daha özel bir yapı. Standartları hayatımızın her yerinde. Örneğin kullandığınız Wi-Fi'nin farklı katmanlarında IEEE standartları var.
- **ETSI:** Coğrafi olarak sınırlı bir standart örgütü. Avrupa Birliği ile doğrudan temas hâlinde. Amaç standardın Avrupa'da yapılması, ama dünyaya yayılmasıdır. Hoca burada bir hâkimiyet (dominasyon) kaygısı olduğunu söyledi.
- **EIA/TIA ve ANSI (American National Standards Institute):** Amerika tarafındaki kurumlar. Yalnızca haberleşmede değil, başka alanlarda da devreye girerler.
- **TSE:** Türkiye'nin standart kurumu. Hoca, bazı standartların üzerinde TSE yazmasına rağmen içinin ISO standardı olduğunu, hatta Türkçeye bile çevrilmediğini gördüğünü söyledi ve bunu eleştirdi.
- **IETF (Internet Engineering Task Force).**

### 10.4 Standart Savaşları: ATM Örneği

Hoca, standartlaşma yarışında harcanmış teknolojiler de olduğunu söyledi. Örneği ATM'di (Asynchronous Transfer Mode). Bugün doğrudan kullanılmasa da ADSL'de hâlâ kullanılıyor. Servis sağlayıcı tarafında, bağlantınızdaki hız sınırını uygulamak için ATM uyarlama katmanı AAL5 (ATM Adaptation Layer 5) kullanılıyor. Bunun nedeni ATM'in paket (hücre) boyutunun çok küçük olmasıdır: 53 bayt.

Hocaya göre 53 "tam bir saçmalık"tır ve standartlaşma çekişmesinden doğmuştur. Hoca, Avrupa'nın 48 bayt, Amerika'nın 64 bayt istediğini, 48'de anlaşır gibi yapıldığını, sonra üstüne adres gibi bilgiler eklenince 53 olduğunu söyledi. Hocaya göre 64 ikinin doğrudan kuvveti, 48 de ikinin kuvvetlerinin katıdır. Bu, paket işlemeyi kolaylaştırmak için düşünülmüştü. Ama standart savaşı sırasında "çamura dönmüş" teknolojilerden biri oldu.

> **Ders sonrası not:** Bilinen tarihe göre Avrupa büyük olasılıkla 32 bayt, ABD 64 bayt faydalı yük (payload) istemiştir. Uzlaşma 48 bayt faydalı yük olmuştur. Buna 5 baytlık başlık eklenince hücre $48 + 5 = 53$ bayt olur. Yani 48 Avrupa'nın değil, uzlaşmanın değeridir. 48 ikinin kuvveti değildir; $48 = 3 \cdot 2^4$ olduğu için 16'nın katıdır.

## 11. Ağların Sınıflandırılması

Ağlar farklı ölçütlere göre sınıflandırılabilir: iletim tekniğine göre, kapsama alanına göre ve hıza göre. Hoca hıza göre sınıflandırmanın biraz daha "yalan" bir sınıflandırma olduğunu söyledi.

### 11.1 İletim Tekniğine Göre

İki temel tür var: noktadan noktaya (point-to-point) ve yayın (broadcast).

Hoca buradaki yayını, ileride üst katmanlarda paket seviyesinde konuşulacak yayınla karıştırmamamızı istedi. Ağdaki herkese bilgi göndermek istemek başka bir şeydir. Gönderdiğiniz her bilginin doğrudan yayın mantığıyla iletilmesi başka bir şeydir.

**Yayın örneği, Wi-Fi:** Wi-Fi doğrudan yayın mantığıyla çalışır. Bir erişim noktasına (access point) bağlıysanız, gönderdiğiniz çerçevede (frame) teknik olarak üç adres bulunur:

- Sizin adresiniz.
- Erişim noktasının adresi.
- Karşı taraftaki hedefin adresi.

Ortamda aynı teknolojiye sahip, aynı ağa bağlı herkes bu çerçeveyi duyabilir. Ama duymazdan gelir: "Bana değil, geç" der. Herkes duyabildiği için gizli dinleme (eavesdropping) mümkündür. Paketler dinlenir, yakalanır (capture). Bunlardan şifre bulunmaya, trafik dinlenmeye ya da yönlendirilmeye çalışılır. Bu, alt seviyede iletişimin yayın olmasının doğal sonucudur.

**Noktadan noktaya örnekleri:** Bilgisayarınızdaki Ethernet kablosunu çapraz (cross) olarak başka bir bilgisayara bağlarsanız, iki bilgisayar arasında başka hiçbir şey yoktur. Birinin gönderdiğini yalnızca diğeri alır. Bu bağlantı fiberle, eskiden seri hatlarla, bugün de USB ile yapılabilir.

### 11.2 Kapsama Alanına Göre

Kapsama alanına göre adım adım şu ağlar vardır:

- **Kişisel alan ağı (Personal Area Network, PAN):** Akıllı telefonunuza Bluetooth ile bağlı akıllı bileklik, kulaklık, tablet ve tablete bağlı kalem gibi, etrafınızda dönen her şey.
- **Yerel alan ağı (Local Area Network, LAN):** Evinizde ADSL, fiber ya da kablonet varsa bir yönlendiriciniz (router) vardır. Ona bağlı bilgisayar, tablet ve telefon bir LAN oluşturur. PAN ve LAN evinizde olan ağlardır.
- **Yerleşke ağı (Campus Area Network, CAN):** Akademik ortamlardaki yerleşke içi ağlar. Hocaya göre çok özel bir durumdur. Ama bugün internet dediğimiz şeyin üniversite ağlarından çıktığı düşünülürse tanımda olması gerekir. Örnek, Davutpaşa yerleşkesindeki ağ. Boyutu üniversiteye ve kampüse göre değişir. İlla bir sınır aranıyorsa 3-5 km içinde yayılmış bir ağdan bahsedilebilir.
- **Kentsel ağ (Metropolitan Area Network, MAN):** Örnekleri kablonet ve Metro Ethernet. Hoca, bir dönem YTÜ'nün Yıldız, Maslak ve Davutpaşa kampüslerinin Metro Ethernet ile birbirine bağlı olduğunu söyledi. MAN'den bahsederken çoğu zaman ağ altyapısını sağlayan üçüncü bir taraftan da bahsediyoruz. Farklı noktalardaki ağlarınızı onun üzerinden birbirine bağlarsınız.
- **Bölgesel ağ (Regional Area Network, RAN):** Daha geniş bir yapı. İstanbul'daki ağ kentsel olabilir; bölgesel denince Marmara bölgesini düşünebilirsiniz.
- **Geniş alan ağı (Wide Area Network, WAN):** Örneğin bütün Türkiye'deki ağ. Mesafe çok arttığı için teknolojiler değişir. Fiberden başka çıkış yolu kalmaz. Fiber de zaman zaman yetmez ve arada ara bağlantılar kurmak gerekir.

Hocaya göre bu sınırlar keskin değildir. Kaynaklarda farklı sınırlar verilir. Ama 10 metrelik sınırı bir santim geçince ağ PAN olmaktan çıkar mı? Çıkmaz.

### 11.3 Hıza Göre

Hoca, slayttaki hız sıralamasına (10 kbps, 100 kbps, 1 Mbps, 10 Mbps, 100 Mbps, 1 Gbps, 10 Gbps) 25, 40, 50, 100, 200 ve 400 Gbps gibi hızların da eklenmesi gerektiğini söyledi. Bunların bir kısmı fiberde aktif olarak kullanılıyor, bir kısmı geliştirme aşamasında. Özellikle 40 Gbps ve 100 Gbps bugün ticari olarak standart hâle gelmiştir. Ciddi kurumların bunları kullanıyor olması gerekir.

> **Ders sonrası not:** Altyazıda hoca 1 gigabitten sonra "10 megabit" diyor. Sıralamanın akışına göre doğrusu 10 gigabittir.

## 12. Ağ Topolojileri

Kapsama alanına göre en yaygın ağlar LAN ve WAN'dır. Her evde bir LAN vardır ve LAN'ın boyutu çok esnektir. Evdeki ağa da, 8-10 ya da 20-30 kişinin çalıştığı bir ofisteki ağa da LAN deriz. WAN da çok yaygındır, çünkü internet bağlantısı sunan farklı firmalar ülkenin her yerinde bulunmak zorundadır. Bu iki yapının topolojileri farklıdır.

### 12.1 Topoloji Seçiminde Maliyet

LAN'da mesafeler kısa olduğu için farklı topolojiler kurulabilir. Topolojiler şunlardır:

- Yol (bus).
- Yıldız (star).
- Ağaç (tree).
- Halka (ring).
- Örgü (mesh).
- Melez (hybrid).

WAN'da ise daha çok noktadan noktaya bağlantılar vardır. Hocaya göre buradaki temel ölçüt, her şeyde olduğu gibi maliyettir.

<!-- BELİRSİZ: Altyazıda bu cümle "tamamen duygusal" diye geçiyor; bağlam ve kısa not maliyet olduğunu gösteriyor. -->

Ev ya da ofis içinde çekeceğiniz kablo 5, 10 ya da 50 metredir. WAN'da ise nereden bakarsanız kilometrelerce kablo çekersiniz. Hocaya göre fiber kablonun metre maliyeti, içindeki damar sayısına göre 1,5 ile 2,5 dolar arasındadır. O gün dolar yaklaşık 9 TL idi. Buna göre metre maliyeti şöyledir:

- $1{,}5 \times 9 = 13{,}5$ TL.
- $2{,}5 \times 9 = 22{,}5$ TL.

Hoca bunu "metresine 20 lira vermek mi, 5 lira vermek mi" diye özetledi.

<!-- BELİRSİZ: Hocanın karşılaştırmadaki "5 lira" değerinin neye ait olduğu (başka bir kablo türü mü) altyazıdan anlaşılmıyor. Python ile 1,5-2,5 dolar × 9 = 13,5-22,5 TL doğrulandı; "20 lira" üst sınıra yakın. -->

WAN'daki bütün düğümleri düşünün. Yıldız topolojisi kurup bir binadaki herkese ayrı kablo çekmek isterseniz, binada 72 daire varsa kablo maliyetiniz 72 katına çıkar. Bir milyon aboneniz varsa maliyet bir milyon kat artar. Metresi bir dolar olsa bile bir milyon dolar fark eder, oysa gerçek fark çok daha fazladır. Bu yüzden WAN'da noktadan noktaya bağlantı tercih edilir.

### 12.2 Yol (Bus) Topolojisi

Bugün kablolu ağlarda Ethernet kullanıyoruz. Geriye doğru gidince anahtarlamalı Ethernet (switched Ethernet), Fast Ethernet, normal Ethernet ve ilk Ethernet vardır. İlk Ethernet bir eş eksenli (coax) kablo üzerinde yol topolojisiyle çalışıyordu:

- Bilgisayarlar T adaptörlerle hattan bir çıkış alarak bağlanıyordu.
- Hattın iki ucuna sonlandırma dirençleri (terminator) konuyordu.

Hocaya göre coax kabloyu Ethernet için kullanan pek kalmamıştır. Bugün coax en çok uydu alıcılarında, televizyon yayınında kullanılır.

Bu yapının sorunları şunlardır:

- **Arıza:** Hattın ortasında bir yerde bağlantı koparsa ağ bir anda ikiye ayrılır. Hatanın yerini bulmak da kolay değildir; hattı dolanarak aramak gerekir.
- **Ortamın kullanımı:** Herkes aynı tek hat üzerindedir. Aynı anda herkes veri koymaya kalkarsa çarpışmalar ve bozulmalar olur. Yani herhangi bir $T$ anında yalnızca bir kişi gönderebilir. Yapı olarak yarı çift yönlüdür (half duplex). Hoca bu kavramı birkaç slayt sonra anlatacağını söyledi (Bölüm 13).

### 12.3 Yıldız (Star) Topolojisi

Ortaya bir hub ya da anahtar (switch) konur ve cihazlar ona bağlanır.

- **Hub ile:** Yol topolojisinden hiçbir farkı kalmaz. Hub, yol topolojisinin bir kutu içinde gerçekleştirilmesidir. Cihazlardan biri konuşursa diğerleri dinlemek zorundadır.
- **Switch ile:** Switch'in port sayısına ve içeride nasıl bir anahtarlama yapabildiğine bağlı olarak, aynı anda birden fazla ikili birbiriyle konuşabilir.

Hub da switch de kullansanız bir esneklik kazanırsınız: Bir kabloda sorun olursa yalnızca o kablonun ucundaki bilgisayar etkilenir, ağın geri kalanı çalışmaya devam eder. Bunun bedeli fazladan kablodur. Ortaya bir cihaz koyduğunuz için, yol topolojisinde 3 metreyle halledeceğiniz işe belki 8-10 metre kablo çekmeniz gerekir. Ama bu size güvenilirlik ve sürdürülebilirlik olarak geri döner.

### 12.4 Ağaç (Tree) Topolojisi

Yıldız topolojisini biraz değiştirerek ağaç topolojisi kurulur. Hiyerarşik bir yaklaşımla en üste bir switch, onun altına bilgisayarlar ve başka switch'ler, o switch'lerin etrafına yine cihazlar konur. Kampüs ağlarında kullanılan yapı da çoğu zaman bir ağaçtır:

- **Çekirdek/omurga (core/backbone):** Ortada bir veri merkezi ve ona doğrudan bağlı bir çekirdek ağ vardır. Örneğin çekirdek ağ 40 Gbps olabilir.
- **Dağıtım (distribution):** Çekirdeğin kapasitesinin 10, 20 ya da 40 Gbps'e inerek dağıtıldığı dağıtım switch'leri. Bunlara genelde doğrudan cihaz bağlanmaz.
- **Erişim (access):** En alttaki üçüncü seviye. Son kullanıcının doğrudan bağlandığı switch'ler.

Hoca, üniversitenin eskiden buna benzer bir topolojisi olduğunu anlattı. En uçta Ethernet gerekir, bu yüzden Ethernet switch'leri kullanılır. Bu switch'ler bir üst seviyeye örneğin ikişer adet 10 Gbps bağlantıyla çıkar. Bu bağlantılar, tamamı fiber bağlantılı, daha yüksek kapasiteli üst seviye switch'lere gider. Onlar da doğrudan çekirdek ağa bağlıdır.

#### Öğrenci Sorusu: Hub, VLAN ve Trunk

**Soru:** Önceki slayttaki en üstteki hub, altında 3 kullanıcı var gibi mi görüyor, yoksa 4 olduğunu biliyor mu?

**Cevap:** Hoca önce böyle bir yapıda en üstteki cihazın hub olamayacağını söyledi. Ciddi bir topolojide, gerçek bir kampüs ağında en üstte yüksek kapasiteli, çok fazla anahtarlama yapabilen bir switch olmalıdır. Buna genelde omurga anahtarı (backbone switch) denir.

Hoca slayttaki grafiğin biraz yanıltıcı olduğunu, her seviyede son kullanıcı bağlıymış gibi göründüğünü söyledi. Gerçekte üstteki dağıtım switch'ine doğrudan bağlı cihazlar varsa, bunlar sunuculardır, yani servis verilen cihazlardır. Örneğin her binaya ayrı bir hat düşünün. Her binaya yalnızca fiberle giden bir dağıtım switch'i konur. Bunların altına da son kullanıcıların bağlanacağı erişim switch'leri konur.

Kampüste genel yapı şöyledir: Erişim hattından gelen bir paket ya da istek çekirdek ağa gelir. Kampüs içindeyse doğrudan sunuculara gider. Kullanıcı internette bir yere gitmeye çalışıyorsa internet hattına gider. Yani en uçtaki trafik yavaş yavaş yukarı çıkarılmalı ve anahtarlanmalıdır.

Bunun için yukarı doğru bağlantıların trunk olması gerekir. Hoca bunu telefon santralindeki trunk hatlara benzetti. Santralde siz de konuşsanız, ben de konuşsam, başkası da konuşsa, santral hepsini tek bir hat üzerinden bir üst seviyeye çıkarır. Bunu zaman bölmeli çoğullama (time division multiplexing) ya da frekans bölmeli çoğullama (frequency division multiplexing) ile yapar. Kampüs ağında da aynı şey vardır.

Böyle bir yapıda bütün trafik birbirine açık bırakılmaz. Örneğin bir fakültede beş bölüm varsa, her birinin trafiği yalıtılmaya çalışılır. Cihazların nereye servis verdiği bilindiği için her portu belli bir sanal yerel ağa (virtual LAN, VLAN) atanır. Bilgisayar Mühendisliği'nin 3. katındaki bir prize Ethernet kablosunu bağladığınızda, Bilgisayar Mühendisliği'nin VLAN'ına bağlanmış olursunuz. Trafiğiniz o VLAN'ın trafiğiyle birlikte akar, Elektrik Mühendisliği'nin trafiğine karışmaz.

Ama yalıtılmış trafiğin de dışarı çıkması gerekir. İstek aynı VLAN içindeki bir komşuya değil, başka bir yere gidiyorsa, trafiğin yukarı çıkmasına izin verilmelidir. Karşıdan gelen cevabın da size aktarılması gerekir. Trunk, cihaz üzerinde tanımlı bütün VLAN'ların trafiğini taşıyabilen bağlantıdır.

Hoca bazı terimlerin yabancı geldiğini, VLAN konusu ilerleyen haftalarda işlendiğinde bunun daha iyi oturacağını söyledi. Öğrenciden, soruyu ara ara hatırlatmasını istedi.

### 12.5 Halka (Ring) Topolojisi

Halka topolojisinin farklı uygulamaları olmuş, ama bugün pek aktif kullanılmıyor. Hoca son örneğini bir ana bilgisayarda (mainframe) gördüğünü anlattı. Ana bilgisayarın işlemci kutusunun içinde, donanım yönetim konsolu (HMC) olarak kullanılan dizüstü bilgisayarlar var. Bunlardan iki tane var, bir de işlemcinin kendisi ve ona bağlı denetleyici kısmı var. Haberleşme ve arayüz için bu dizüstü bilgisayarlar kullanılıyor ve aralarında halka topolojisi kullanılıyor. Hoca bunun dışında halkanın dünyada başka kullanımı kaldığından emin değil.

Yapı şundan ibarettir: Gerçekten bir halka vardır, bir de jeton (token) vardır. "Jeton kimdeyse söz ondadır" ilkesiyle çalışır. Yani ortama erişim bir jetonla düzenlenir.

> **Ders sonrası not:** Hoca HMC'yi "Hardware Monitoring Control" diye açtı. IBM ana bilgisayarlarında bu kısaltma büyük olasılıkla "Hardware Management Console" anlamına gelir.

### 12.6 Örgü (Mesh) Topolojisi

Mesh denince normalde üzerindeki bütün düğümlerin birbirine bağlı olması kastedilir. Slayttaki şekilde 4 düğüm ve toplam 6 bağlantı vardır. Bütün düğümler bütün düğümlere, başkası üzerinden değil, doğrudan bağlıdır. Buna tam örgü (full mesh) denir.

$n$ düğümlü tam örgüde her düğüm diğer $n-1$ düğüme bağlanır. Her bağlantı iki düğüm tarafından paylaşıldığı için bağlantı sayısı şöyledir (ara adım eklendi):

$$L = \frac{n(n-1)}{2}, \qquad n = 4 \Rightarrow L = \frac{4 \cdot 3}{2} = 6$$

Tam örgü maliyetlidir, çünkü herkesi herkese bağlamak için çılgınca kablo çekmek gerekir. Bu yüzden kısmi örgü (partial mesh) gibi topolojiler de kurulur. Ortadaki bağlantılardan biri yapılmaz ya da ağ farklı organize edilir. Örneğin her düğüm diğerlerine en az iki bağlantıyla bağlanır.

Herkesi herkese bağlamanın bir sorunu da her bağlantı için ayrı bir ağ arayüz kartı (network interface card, NIC) gerekmesidir. Hocanın örneği: Ethernet ile 10 bilgisayarı tam örgüyle bağlamak isterseniz, her birine $10 - 1 = 9$ Ethernet bağlantısı gerekir. Çoğu makinede o kadar kart takılacak yuva (slot) yoktur.

### 12.7 Melez (Hybrid) Topoloji

Melez topoloji zamanla oluşur. Bugün bir teknolojiyle bir topoloji kurarsınız. Yarın bambaşka bir ihtiyaç doğar ya da teknoloji güncellenir, yeni kısmı farklı bir topolojiyle kurarsınız. Sonuçta farklı topolojiler bir arada bulunur. Aralarındaki bağlantıyı sağlamak için ağ geçidi (gateway) tarzı cihazlar gerekir. Bunlar farklı topolojiler ya da teknolojiler arasında çevirmenlik yapar. Slayttaki şekilde, yukarıdaki yol topolojisini ağaca bağlayan bir cihaz, ağacı da aşağıdaki halkaya bağlayan başka bir cihaz vardı. Bu cihazlar her iki ağda da haberleşebilen cihazlardır.

## 13. İletim Modları

Hoca, yol topolojisinde yarı çift yönlülükten bahsettiği için bu slaytın aslında daha önce gelmesi gerektiğini söyledi. İletim modu, iletim ortamının alıcı ve gönderici tarafından kullanılabilme yeteneğidir.

- **Tek yönlü (simplex):** Hattın bir ucunda gönderici (sender), diğer ucunda alıcı (receiver) vardır. Bilgi hep aynı yönde akar. Örnek uydu alıcısıdır. Uydudan bilgi alırsınız, televizyonda görüntülersiniz. Akıllı bir uydu alıcısı internete ya da Wi-Fi'ye bağlıysa geri dönüş oradan olur. Ama asıl veri akışı uydudan televizyona doğrudur.
- **Yarı çift yönlü (half duplex):** Gönderici ve alıcı rol değiştirebilir. İki taraf da gönderip alabilir, ama aynı anda değil. En basit örnek telsizdir. Telsizde iki taraf aynı anda konuşamaz; biri konuşurken diğeri dinler.
- **Tam çift yönlü (full duplex):** İki taraf aynı anda hem gönderici hem alıcı olabilir. Hoca örnek olarak bugün kullandığımız Fast Ethernet'i verdi. Bükümlü çift (twisted pair) kabloda 8 tel olduğunu, bunların dördünün bir yönde, dördünün diğer yönde kullanıldığını, böylece tam çift yönlü çalışıldığını söyledi.

> **Ders sonrası not:** Hoca Fast Ethernet'te 8 telin dördünün bir yönde, dördünün diğer yönde kullanıldığını söyledi. Doğrusu büyük olasılıkla şudur: 100BASE-TX dört çiftin yalnızca ikisini kullanır, bir çift gönderme, bir çift alma için. Yani 8 telin 4'ü kullanılır. Dört çiftin hepsini kullanan Gigabit Ethernet'tir (1000BASE-T); orada her çift aynı anda iki yönde çalışır.

## 14. Adresleme Modelleri

Hoca, iletim tekniğindeki yayın ile üst katmandaki yayını karıştırmamamız gerektiğini hatırlattı. Bilgi gönderirken alıcıyı adreslemem gerekir. Bu adresleme tek bir kişiye, birden fazla kişiye ya da herkese olabilir. Bu, alttaki iletim ortamının özelliğinden bağımsızdır. Örneğin yol topolojisi değil de anahtarlamalı Ethernet kullanılan bir ortamda yayın yapmak istiyorsanız, adresi ona göre girersiniz: "Bu paket herkese gidecek." Herkes de onu alır.

- **Tekli gönderim (unicast):** En standart model. Bilgi bir yerden çıkıp doğrudan tek bir alıcıya gider.
- **Yayın (broadcast):** Herkese gönderim.
- **Çoklu gönderim (multicast):** Herkese değil, belirli bir alt gruba (subset) gönderim. Hocanın güncel örneği IP üzerinden TV yayınıydı. Aynı yayını izleyen üyelere aynı bilgi aktarılır. Daha etkin olması için multicast yapılır. Çoğu zaman kapalı bir alan (domain) içinde, kimlerin alacağı önceden belirlenmiş kurallara göre gönderilir.
- **Herhangi birine gönderim (anycast):** Daha farklı bir yapı. Farklı ağlarda farklı şekillerde ortaya çıkar.
  - Bilginin önemli olduğu, veri merkezli (data-centric) bir algılayıcı ağında anycast şu demektir: Bu bilgi bir şekilde bir merkeze gitmeli; kimin üzerinden gittiğinin önemi yok. "Ben gönderiyorum, kim duyarsa o aktarsın."
  - Araçlar arası iletişimde (inter-vehicle communication) coğrafi anycast (geographic anycast) konuşulur. Hocanın örneği bir emniyet (safety) uygulamasıydı. Öndeki araç frene bastı, sizin aracınız bunu algıladı. Bu bilgi coğrafi olarak arkanızdaki araçları ilgilendirir. Ama belirli bir araç değil, o bölgedeki herhangi biri bilgiyi almalıdır.

> **Ders sonrası not:** Altyazıda bu model "Nyquist" diye geçiyor; doğrusu anycast'tir. Nyquist örnekleme teoremiyle ilgisi yoktur.

## 15. Veri Akışı, Bit Hızı ve Birimler

### 15.1 Simetrik ve Asimetrik Akış

Bilgiyi bir göndericiden bir alıcıya iletiyoruz. Bu iletim simetrik ya da asimetrik olabilir.

- Doğası gereği tek yönlü olan yapılar daha çok asimetriktir: simplex, broadcast, multicast, unicast. Hoca bir istisna düşündüğünü, ama aklına gelmediğini söyledi.
- Yarı ve tam çift yönlü modeller, uygulamanın çalışma yapısına göre simetrik de asimetrik de olabilir. Bu, uygulamanın nasıl veri ürettiğine ve aktardığına bağlıdır.

### 15.2 Bit Hızı ve Önekler

Veri iletim hızı çoğunlukla saniyedeki bit sayısıyla (bits per second, bps) ölçülür. Teknoloji geliştikçe önüne önekler konur: kilo, mega, giga, tera, peta, eksa, zetta ve yotta. Bu sembolleri yazarken dikkat edilecek noktalar:

- Hız bazen bit değil bayt cinsinden verilir. O zaman "B" büyük yazılır: "Bps".
- Yalnızca kilo küçük harfle yazılır: kbps.
- Bin bin artan diğer katlar (mega, giga, tera, peta...) hep büyük harfle yazılır.

> **Hocanın vurgusu:** Bu önemli bir nokta, karıştırılmamalı: küçük "b" bit, büyük "B" bayt; kilo küçük "k", diğer önekler büyük harf.

> **Ek bilgi (derste anlatılmadı):** Veri iletişiminde önekler büyük olasılıkla ondalık (SI) anlamda kullanılır: 1 kbps = 1000 bps, 1 Mbps = $10^6$ bps. 1024 tabanlı ikili önekler (KiB, MiB gibi) daha çok bellek ve dosya boyutu için kullanılır. Hocanın "bin bin artan katlar" ifadesi de bu ondalık kullanıma uyar.

## 16. Verim (Throughput) ve Protokol Ek Yükü

Veri iletimiyle ilgili konuşulacak bir şey de verimdir (throughput). Hoca bir soru sordu: 100 Mbps diye bir ağ arayüz kartı alıyorsunuz. Gerçekten 100 Mbps veri aktarabiliyor musunuz?

Öğrencilerin çoğu "hayır" dedi. Gelen cevaplar kayıplar, donanım sınırlamaları, iletim ortamından kaynaklanan kayıplar, kablo malzemesi ve kablo uzunluğuydu. Hoca bunları tek tek ele aldı:

- **Donanım sınırlaması:** Hocaya göre tutarlı bir cevap değil. 100 Mbps diye satılan kartta donanım sınırlaması olması mantıklı değil.
- **Kablo malzemesi:** Hocaya göre Ethernet kablosunun 20 küsur farklı adlandırması var. Normalde 8 tel olmalı. Sorular şunlar: Her telin kendi yalıtımı var mı? Hepsinin ortak bir yalıtımı var mı? Teller çiftler hâlinde bükülü olmanın yanında çiftler de kendi içinde bükülü mü? Genel bir kılıf (shield) var mı, her çiftin ayrı kılıfı var mı? Hoca bunu "kablo sapıklığı" diye niteledi. Ama bunlar iletişimi doğrudan etkilemez. Etkilediği durum da vardır: Kabloyu taşıdığınız ortam endüstriyel bir ortamsa ve hat üzerinde çok sayıda elektromanyetik etken varsa, kablo malzemesi sorun çıkarabilir. Ya da CAT4 veya CAT5 kabloyu 1 Gbps'lik bir Ethernet cihazında kullanırsanız başınıza iş gelebilir.
- **Kablo uzunluğu:** Hocaya göre bununla ilgisi yok. Kablo kısayken 100 Mbps'i görüyor musunuz? Görmüyorsunuz.
- **İletim kanalının sınırı:** Hoca bundan da bahsetmediğini söyledi. CAT6 kablo döşersiniz, kablo 1 Gbps bile aktarabilir. Yine de 100 Mbps'i görmezsiniz.

Hoca cevaba veri iletişiminin temel parçalarını hatırlatarak götürdü. Gönderici ve alıcının iletim ortamına bağlanması için fiziksel cihazlar gerekir. Bunun dışında protokol yığını, kurallar ve ortamın sağladığı yapı vardır. Kablo 100 Mbps aktarır. Ama verinin aktarılabilmesi için protokol ek yükü (protocol overhead) vardır. 100 kilobit aktarmak istediğinizde aslında 100 kilobitten fazlasını aktarmak zorundasınız. Yalnızca ham veriyi değil, protokol yığınının eklediği fazladan veriyi de gönderirsiniz. Bu yüzden faydalı veri (payload) kısmı hiçbir zaman 100 Mbps olmaz.

> **Hocanın vurgusu:** Aranan cevap protokol ek yüküdür. Kart ya da kablo 100 Mbps olsa bile faydalı veri hızı 100 Mbps'e ulaşmaz.

> **Ek bilgi (derste anlatılmadı):** Protokol ek yükü büyük olasılıkla her katmanın veriye kendi başlığını eklemesinden doğar. Ethernet'te her çerçeveye başlık, kontrol alanı ve çerçeveler arası boşluk gibi alanlar eklenir; IP ve TCP de kendi başlıklarını ekler. Bu yüzden ağ ne kadar hızlı olursa olsun faydalı veri oranı her zaman 1'den küçüktür. Oran, faydalı veri büyüdükçe artar, küçük paketlerde düşer.

## 17. Cevap Süresi ve Jitter

### 17.1 Cevap Süresi (Response Time)

Cevap süresi, bir sistemin kendisine verilen komuta cevap verme süresidir. Bir sunucuyla konuşuyorsunuz; bir istek gönderip cevap alacaksınız. Cevap süresi üç zamanın toplamıdır:

$$T_{\text{cevap}} = T_{\text{istemci} \to \text{sunucu}} + T_{\text{işleme}} + T_{\text{sunucu} \to \text{istemci}}$$

- İsteğin istemciden sunucuya gönderilme süresi.
- İsteğin anlaşılıp karşılığındaki işlemin yapılması ve sonucun üretilmesi.
- Sonucun geri gönderilmesi.

Ortamdaki trafik yoğunluğu cevap süresini etkiler. Özellikle paket anahtarlamalı ağlarda her paket farklı yollardan gider ve farklı hatalara maruz kalabilir. Bu yüzden cevap süresi oldukça değişkendir.

Daha sıkıntılı olan durum şudur: Noktadan noktaya bir bağlantı yoksa ve veri atlamalarla gidiyorsa, isteğiniz arada kaybolup karşıya hiç gitmeyebilir. Ya da istek karşıya gider, ama cevap size hiç gelmez. Bu durumlarla başa çıkmak için onay (ACK), olumsuz onay (NAK) gibi mekanizmalar ve zamanlayıcılar (timer) devreye girer. Hoca bunun veri bağı katmanının işi olduğunu ve o konuya gelince ayrıntılı konuşacaklarını söyledi.

### 17.2 Jitter Örneği

Hoca jitter'ı, ardı ardına gönderilen paketlerin gecikmelerinin farklılık göstermesi diye tekrar tanımladı ve bir şekil üzerinden anlattı. Üstte gönderilen paketler var ve hepsi aynı aralıkla gönderiliyor. Ama karşı tarafa farklı zamanlarda ve farklı sırayla varıyorlar. Önce 1. paket geliyor, sonra 4. ve 5. geliyor; 6. ve 7. bayağı geç geliyor. Olması gereken standart bir gecikme var ve paketler sürekli bu gecikmeden sapıyor. Jitter budur.

<!-- BELİRSİZ: Şekildeki paketlerin tam varış sırası altyazıdan yalnızca kısmen anlaşılıyor (1, 4, 5 önce; 6 ve 7 geç); 2 ve 3'ün yeri sözlü anlatımda tam net değil. -->

Hoca, en başta söylediğini bu şekille bağladı. Bu gerçek zamanlı bir trafik olsaydı, örneğin bir cep telefonu konuşması, 2 numaralı paket büyük ihtimalle atılmış olurdu. 1. paket geldi, çözüldü, dinlendi. 3. paket geldi, arada bir kopukluk kaldı; konuşan kişinin belki bir kelimesi gitti. Sonra gelen 2. paketin anlamı yoktur. 4. paket geldiğinde arada bir boşluk olduğu için bir sessizlik olur, siz de "alo, orada mısın?" dersiniz. Böyle bir jitter dağılımı varsa iletişim kopuk kopuk devam eder.

> **Ek bilgi (derste anlatılmadı):** Gerçek zamanlı uygulamalar jitter'ı azaltmak için alıcıda büyük olasılıkla bir jitter tamponu (jitter buffer) kullanır. Gelen paketler kısa bir süre bekletilip düzenli aralıklarla oynatılır. Tampon süresinden daha geç gelen paket yine atılır. Bu, hocanın anlattığı "geç gelen paketin anlamı yok" durumunun pratikteki karşılığıdır.

## 18. Hız Tabloları

Dersin sonunda hoca, en düşükten en yükseğe doğru giden üç slaytlık bir veri iletim hızı tablosu gösterdi. Hız arttıkça Ethernet gibi teknolojilere geçildiğini ve hızla birlikte desteklenen mesafenin de değiştiğini söyledi. Bunları genel bilgi olarak geçti, her birinin tekniği üzerinde durmadı.

<!-- BELİRSİZ: Hız ve mesafe tablolarının içeriği slaytta; altyazıda yalnızca genel olarak anılıyor. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:11:36): Bir veri iletişiminden bahsediyorsak ortamda bulunması gereken temel parçalar nelerdir?

> **Çözüm (derste verildi):** İletim ortamı (medium), mesaj, gönderici ve alıcı, ve ortamın nasıl kullanılacağını belirleyen kurallar bütünü olan protokol. Hoca, bunların varlığının belli açılardan yeterli ama tam olmadığını; iyi bir iletişim için doğru adrese teslim, doğruluk ve zamanında iletimin de gerektiğini ekledi.

**Soru 2** (derste sözlü, 00:44:02): Evinizdeki ağın, YTÜ ağının, ULAKNET'in ve internetin değerini nasıl sıralarsınız? Bir ağın değeri neye bağlıdır?

> **Çözüm (derste verildi):** Değer bu sırayla artar. Bir ağın değeri, ona bağlanabilen cihaz sayısıyla doğrudan ilişkilidir. Bu bağlantılılığı sağlamak için birbiriyle uyumlu yapılar, yani standartlar gerekir.

**Soru 3** (derste sözlü, 01:31:54): 100 Mbps diye satılan bir ağ arayüz kartıyla gerçekten 100 Mbps veri aktarabilir misiniz? Aktaramıyorsanız neden?

> **Çözüm (derste verildi):** Aktaramazsınız. Donanım sınırlaması, kablo uzunluğu ya da iletim kanalının sınırı asıl neden değildir; kablo malzemesi yalnızca gürültülü ortamlarda ya da hıza uygun olmayan kablo (örneğin 1 Gbps cihazda CAT4/CAT5) kullanıldığında sorun çıkarır. Asıl neden protokol ek yüküdür (protocol overhead). 100 kilobit faydalı veri için hatta 100 kilobitten fazlası gider, çünkü protokol yığını veriye kendi bilgilerini ekler. Bu yüzden faydalı veri (payload) hızı hiçbir zaman 100 Mbps olmaz.

**Soru 4** (derste sözlü, 01:39:04): Cevap süresi (response time) hangi bileşenlerden oluşur?

> **Çözüm (derste verildi):** Üç zamanın toplamıdır: isteğin istemciden sunucuya iletilmesi, sunucuda işlenip sonucun üretilmesi ve sonucun istemciye geri iletilmesi. Paket anahtarlamalı ağlarda trafik yoğunluğu ve paketlerin farklı yollardan gitmesi yüzünden bu süre çok değişkendir; istek ya da cevap kaybolabilir, bu da ACK/NAK ve zamanlayıcı gerektirir.

**Soru 5** (derste sözlü, öğrenci sorusu, 01:13:02): Ağaç topolojisi şeklinde en üstteki hub, altındaki kullanıcı sayısını görür mü?

> **Çözüm (derste verildi):** Böyle bir yapıda en üstteki cihaz hub olamaz; yüksek kapasiteli bir omurga anahtarı (backbone switch) olmalıdır. Yukarı doğru bağlantılar, cihaz üzerinde tanımlı bütün VLAN'ların trafiğini taşıyan trunk bağlantılardır (Bölüm 12.4).

<!-- BELİRSİZ: Öğrencinin sorusu altyazıda "3 tane kullanıcı var gibi mi görüyor yoksa 4 olduğunu biliyor mu" diye geçiyor; slayttaki şekil görülemediği için sorunun tam kastı net değil. -->

## Dersin Toparlaması

Bu ilk derste veri iletişiminin temel kavramları kuruldu. İletişim, verinin bir yerden bir yere aktarılması; haberleşme ise anlamlı bilginin aktarılmasıdır. Bir veri iletişimi için ortam, mesaj, gönderici, alıcı ve protokol gerekir. İyi bir iletişim doğru adrese teslim, doğruluk ve zamanında iletim ister; paket gecikmelerindeki dalgalanma olan jitter da hat kalitesinin ölçüsüdür. Ağlar kaynak paylaşımı, yük dengeleme ve etkin haberleşme için kullanılır ve başarım, QoS, güvenilirlik, güvenlik, ölçeklenebilirlik ve uyumluluk ölçütleriyle değerlendirilir. Devre anahtarlamalı ağlarda önce bir devre kurulur; paket anahtarlamalı ağlarda her paket ayrı yönlendirilir.

Mimari tarafta OSI ve TCP/IP'nin katmanlı yaklaşımı ile algılayıcı ağlarında görülen çapraz katmanlı yaklaşım ayrıldı. Uyumlu yapılar için standartların, de jure ve de facto ayrımının ve standart kurumlarının önemi anlatıldı. Ağlar iletim tekniğine (noktadan noktaya, yayın), kapsama alanına (PAN'dan WAN'a) ve hıza göre sınıflandırıldı. Topolojiler (yol, yıldız, ağaç, halka, örgü, melez), iletim modları (simplex, half duplex, full duplex) ve adresleme modelleri (unicast, broadcast, multicast, anycast) incelendi. Son olarak bit hızı birimleri, protokol ek yükünün verimi neden düşürdüğü ve cevap süresinin bileşenleri konuşuldu. Hoca, ACK/NAK ve zamanlayıcılar gibi mekanizmaların veri bağı katmanında, VLAN ve trunk konusunun da ilerleyen haftalarda ayrıntılı işleneceğini söyledi. OSI modeline yetişilemezse bir sonraki hafta devam edileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
