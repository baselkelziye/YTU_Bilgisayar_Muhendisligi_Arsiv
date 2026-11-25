# Ders 4 Genişletilmiş Notu: Nesnelerin İnterneti (IoT), QR Kod ve RFID, Büyük Veri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kablosuz Sensör Ağlarından Nesnelerin İnternetine
- 2. IoT Paradigması: Tek Paradigma, Birçok Vizyon
- 3. Spime, Yaygın Hesaplama ve Çevresel Zeka
- 4. IoT Ara Katmanı ve Uygulama Alanları
- 5. Açık Araştırma Konuları ve Dijital Unutma
- 6. Haberleşme Protokolleri ve TCP'nin Yetersizliği
- 7. IoT'de Güvenlik ve Mahremiyet
- 8. Mobil Kötücül Yazılım Tespiti ve GAN
- 9. Barkod ve QR Kod
- 10. RFID Etiketleri ve Frekans Aralıkları
- 11. RFID, QR Kod ve Barkod Karşılaştırması
- 12. Büyük Veri
- Örnek Sorular

## 1. Kablosuz Sensör Ağlarından Nesnelerin İnternetine

Ders, bir önceki derste konuşulan kablosuz sensör ağlarının (wireless sensor networks, WSN) hatırlatılmasıyla başladı. Slaytlar "Internet of Things and Data Management" başlıklı haftaya aitti (ekrandan, 00:15:00). Hoca kablosuz sensör ağlarını, fiziksel ve elektronik cihazların dış dünyayla bağlantısını sağlayan ilk organize yapılar olarak tanımladı ve IoT'nin doğuş noktası olarak gördü.

Bilgisayarlar hayatımıza girdiği ilk dönemde dışarıdan, insan eliyle girdi alıp onu işleyerek çıktı üretmek üzere tasarlanmıştı. Basit mikrofon ve kamera dışında elektronik bir cihazın çevreyle iletişimi pek söz konusu değildi. Zamanla birçok elektronik cihazın, uçaklar dahil, çalışabilmesi ve insanların gündelik sorunlarını çözebilmesi için çevreden bilgi toplaması gerekti. Bu ihtiyaçla kablosuz sensör ağları 1990'larda önce askerî alanda yoğun olarak kullanılmaya başlandı; 2000'lerde tarım, çevresel uygulamalar ve hayvan takibi gibi alanlara yayıldı. Aynı yıllarda hareketli bir düğüm gibi düşünülebilecek cep telefonu da hayatımıza girdi.

Bunun ardından "eşyalarımızı sensörlerle donatalım ve onları daha sofistike hâle getirelim" fikriyle Nesnelerin İnterneti (Internet of Things, IoT) kavramı ortaya çıktı. Hoca burada iki özel durumu vurguladı:

- Eşyaların özel bir tasarım gerektirmeden içlerine elektronik devreler yerleştirilerek ağa bağlanması.
- Sensör ağlarından farklı olarak her cihaza IP tabanlı, birebir ve uzaktan erişimin mümkün olması. IoT ağlarında teorik olarak her cihaza sorgu atıp onunla konuşabilir ve ondan veri toplayabilirsiniz.

Kablosuz sensör ağlarında ise durum farklıdır: bilgi yerel olarak ve belirli coğrafi bölgelerden toplanır, bildiğimiz IP mantığıyla çalışılmaz. IoT'yi WSN'den ayıran ve cihazları birebir kontrol etmemizi sağlayan yapı sensör ağlarında yoktur.

Önümüzdeki on yıllarda dünyadaki her eşyanın bir bulut yapısı üzerinden çevrim içi olması bekleniyor. Hoca, IoT denildiğinde bulut ve büyük verinin birlikte kullanılmasının artık kaçınılmaz olduğunu söyledi: her cihazın çevrim içi olması büyük miktarda veri üretmek ve bunu merkezi bir noktada depolamak demektir. Evdeki buzdolabından giydiğimiz ayakkabıya, uçaktan arabaya kadar bütün eşyalar bu çevrim içi dünyaya dahil olacaktır.

## 2. IoT Paradigması: Tek Paradigma, Birçok Vizyon

### 2.1 Üç vizyon

Slaytta IoT için üç farklı vizyon sıralanıyordu (ekrandan, 00:10:00):

- **Internet oriented (internet odaklı):** Bütün nesnelerin internet üzerinden erişilebilir olması.
- **Things oriented (nesne odaklı):** Nesnelerin takip edilebilir olması ve üzerlerindeki kimlik (ID) ve IP'lerle tekil olarak yer almaları. Bunun için RFID (Radio-Frequency Identification) ve EPC (Electronic Product Code) kullanılır. Hoca bunu bilgisayarlardaki MAC adreslerine benzetti: nesnelere de benzer biçimde tekil kimlikler atanır.
- **Semantic oriented (anlamsal odaklı):** Bilgilerin anlamsal açıdan bir arada kullanılması ve IoT ağlarının organize edilmesi. Örneğin cihazlar ev, araba, kişisel cihazlar, havaalanı gibi bölgelere ayrılarak gruplanabilir; ya da giyilebilir cihazlar, kıyafetler, taşınabilir cihazlar gibi farklı bakış açılarıyla organize edilebilir.

### 2.2 Vizyonların kesişimi

IoT paradigmasını gösteren şekilde üç vizyon üç küme olarak çizilmişti ve IoT bu üç kümenin kesişiminde yer alıyordu (ekrandan, 00:15:00). Şekildeki kümelerin içerikleri şöyleydi:

| Vizyon | Kümedeki kavramlar |
|---|---|
| "Things" oriented | RFID, UID, Spimes, Smart Items, NFC, Everyday objects, Wireless Sensors and Actuators, WISP |
| "Internet" oriented | IPSO (IP for Smart Objects), Internet 0, Web of Things |
| "Semantic" oriented | Semantic Technologies, Reasoning over data, Semantic execution environments |
| İki kümenin ortak alanı | Connectivity for anything, Communicating things (nesne ve internet); Smart Semantic Middleware (internet ve anlamsal) |

Hoca bunu şöyle özetledi: bir tarafta nesnelerin sahip olduğu yetenekler ve kullandığı bilgiler, bir tarafta internete bağlanmak için gerekli protokoller ve yetenekler, bir tarafta da verinin anlamsal mantıklarla parçalanıp yorumlanması vardır. Bu üç temel vizyona başka vizyonlar da eklenerek IoT ağları değerlendirilebilir.

### 2.3 IoT ile kablosuz sensör ağlarının farkı

Hocaya göre IoT'nin WSN'den en önemli farkı, çok farklı açılardan ele alınıp organize edilebilen bir yapı olmasıdır:

- WSN'de temel olarak düğümler vardır ve veri toplarlar. IoT'de ise yalnız veri toplanmaz; veri akışı simetrik, yani iki yönlüdür ve nesnelerle birebir haberleşme söz konusudur.
- Makineden makineye haberleşme (machine to machine communication, M2M) sensör ağlarında daha çok verinin aktarılması için bir haberleşme tekniğidir. IoT'de ise cihazlar birbiriyle bilgi paylaşarak belirli aksiyonlar alır: çamaşır makinesinin buzdolabına, buzdolabının bulaşık makinesine veri aktarması; araçların birbiriyle ya da bir aracın telefonunuzla haberleşerek belirli organizasyonlar yapması gibi.
- Sensör ağları uygulamaya özeldir (application specific), belirli bir uygulama amacıyla sahaya yerleştirilir. IoT ise insan odaklıdır (human oriented); insanın gündelik hayatını kolaylaştıracak işlerin bir arada organize edilmesini hedefler.

## 3. Spime, Yaygın Hesaplama ve Çevresel Zeka

### 3.1 Spime

Slayttaki tanıma göre spime, IoT'nin yanında ortaya çıkan bir kavramdır: ömrü boyunca uzayda (SPACE) ve zamanda (TIME) izlenebilen, sürdürülebilir, geliştirilebilir ve tekil olarak tanımlanabilir bir nesne (ekrandan, 00:20:00, slayt küçük resmi). Kavram, space ve time sözcüklerinin birleşiminden türetilmiştir.

Hoca spime'ın IoT ağlarında çok kritik olduğunu söyledi. Sensör verisi toplanırken de konuşulduğu gibi, toplanan verinin nereden ve hangi zamanda geldiği çok önemlidir. Bu bilginin değiştirilemez ve manipüle edilemez olması önümüzdeki yıllarda daha da önem kazanacaktır. Örneğin bir yangın olduğunda ortamdaki sıcaklık sensörleri, basınç değişimi ve nem oranı gibi veriler yangının nasıl çıktığına dair kanıt oluşturabilir. Yargı da zaman zaman bu tür bilgilere başvurur; günün sonunda veriyi bir uzman yorumlar, ama verinin kesinliği sağlanmış olmalıdır.

Bunun için yazılımsal çözümlerin yanında donanımsal çözümler de üretilmeye başlandı. Belirli bir problem için donanımsal tasarım her zaman daha güvenilirdir, çünkü o probleme özel bir donanım tasarlanır ve manipüle edilmesi çok zordur. Ama maliyetli, zaman alan ve daha fazla emek gerektiren bir iştir. Bu yüzden çözümler genelde önce yazılımsal olarak yapılır, sonra donanıma taşınır. Hoca bankacılıktaki donanım güvenlik modüllerini (hardware security module, HSM) örnek verdi: ilk etapta yazılımsal yapılan işler, güvenlik için daha sonra özel donanımlarla yapılmaya başlanmıştır.

### 3.2 Yaygın hesaplama

Her an, her yerden, her cihazdan bağlanabilmeyi anlatan kavramlar için yaygın hesaplama (pervasive computing) ya da her yerde hesaplama (ubiquitous computing) deniyordu. IoT ağlarının temel prensibi de budur: bilginin her zaman, her alanda ve her cihaz üzerinden paylaşılabilir ve yönetilebilir olmasını sağlamak.

Slaytta iki vizyon cümlesi yer alıyordu (ekrandan, 00:20:00):

- **ITU vizyonu:** "from anytime, anyplace connectivity for anyone, we will now have connectivity for anything" (her zaman, her yerde, herkes için bağlantıdan; her şey için bağlantıya).
- **Avrupa Komisyonu vizyonu:** "Things having identities and virtual personalities operating in smart spaces using intelligent interfaces to connect and communicate within social, environmental, and user contexts" (kimlikleri ve sanal kişilikleri olan, akıllı ortamlarda akıllı arayüzler kullanarak sosyal, çevresel ve kullanıcı bağlamlarında bağlanan ve iletişim kuran nesneler).

### 3.3 Eşyaların sanal kişiliği ve çevresel zeka

Avrupa Komisyonu vizyonundaki "sanal kişilik" ifadesini hoca insanla kıyaslayarak açıkladı. Burada ruhsal, biyolojik ya da hormonal bir şeyden söz edilmiyor; ama insanın duygularını bir kenara bırakırsak karar verirken içinde algoritmik bir yapı vardır ve bu onun kişiliğini oluşturur. Bazı araştırmalar, insanın anında karar vermesini sağlayan yapının çok karmaşık, doğrusal olmayan bir sinir ağı gibi çalıştığını, bizim programlamada kullandığımız if ve while yapılarından çok farklı olduğunu ve katsayıların yıllar içinde pekiştiğini öne sürer. Hoca bunun henüz ispatlanmış bir şey olmadığını da belirtti.

Eşyalara dönersek: bir eşyanın bulunduğu ortamı anlayabilmesi, ortamdaki hareketleri yorumlayabilmesi, kişileri algılayıp onlarla iletişim kurabilmesi o eşyanın ortamı tanımasını sağlar. Çevresel zeka (ambient intelligence) kavramı buradan doğar. Çevresel zeka, elektronik bir cihazın ortamı algılayıp o ortamla ilgili karar vermesine yönelik bir çözümdü; sınıflarda ışıkların açılıp kapanması gibi basit işlerle başladı. Bugün evlerin ve şehirlerin yönetilmesi, dairelerin ve cihazların birbiriyle haberleşmesiyle daha büyük bir akıl ortaya koymaya doğru evrildi. Hoca, bunun anlatıldığı kadar hızlı ilerlemediğini, ama ilerleme kaydedildiğini söyledi.

### 3.4 Otonom araçlar örneği

Hoca, geleceğe ışık tutan en önemli alanlardan birinin otonom araçlar olduğunu söyledi. Ocak 2022'de Las Vegas'taki bir elektronik fuarında bir firma sürücüsüz bir traktör tanıtmıştı. Tarla belirli bir alandır ve traktörü rahatsız edecek hareketli nesneler azdır. Otonom bir otomobil ise özel bir yolda gitmiyorsa sayısı milyonları bulan parametreyle karşılaşır: yola çıkan bir hayvan ya da insan, aynı anda iki tehlike varsa hangisinin göze alınacağı, yağış gibi koşullar. Otonom araçların önümüzdeki 5-10 yıl içinde belirli alanlarda sahada olması bekleniyor, ama bazı teknolojilerin düşündüğümüz kadar hızlı gitmediğini de biliyoruz.

## 4. IoT Ara Katmanı ve Uygulama Alanları

### 4.1 Ara katman (middleware)

Slaytta "Enabled Technologies" başlığı altında iki madde vardı: tanımlama, algılama ve haberleşme (Identification, Sensing, Communication) ve ara katman (Middleware). Şekil, IoT ara katmanı için SOA tabanlı bir mimariyi gösteriyordu (ekrandan, 00:25:00). Katmanlar aşağıdan yukarıya şöyledir:

- Objects (nesneler)
- Object Abstraction (nesne soyutlama)
- Service Management (servis yönetimi)
- Service Composition (servis birleştirme)
- Applications (uygulamalar)

Bütün katmanları dikey olarak kesen bir blok da "Management of Trust, Privacy, Security" (güven, mahremiyet ve güvenlik yönetimi) idi.

En alt katmanda IoT cihazları vardır. Hoca, bu cihazlara doğrudan erişimin bir hedef olmasına rağmen beraberinde bir tehdit getirdiğini söyledi. Bu yüzden cihazları kullanıcıdan ayırıp kullanıcıya yalnız belirli bilgilerin dönmesini sağlayan bir yapıya ihtiyaç vardır. IoT ara katmanı, bu katmanların koordineli çalıştığı yazılımlardır. Bu sayede hem istediğiniz cihazdan bilgi alabilir, hem diğer cihazlarla koordinasyon kurabilir, hem de cihazlara doğrudan erişilmediği için onları saldırılara karşı korumuş olursunuz.

Bu koruma özellikle önemlidir, çünkü IoT cihazlarının işlem yetenekleri kısıtlıdır ve bilgisayarlardaki yüksek işlem gücü gerektiren şifreleme algoritmalarını kullanmak mümkün olmayabilir. Hoca, IoT cihazlarının korunması ve güvenliğinin en çok çalışılan alanlardan biri olduğunu, hem güvenlik hem IoT alanında çalışmak isteyenler için iyi bir tez konusu olabileceğini söyledi.

### 4.2 Uygulama alanları

Slayttaki şekil uygulama alanlarını beş ana başlıkta topluyordu (ekrandan, 00:30:00):

| Alan | Senaryolar |
|---|---|
| Transportation and logistics | Logistics, Assisted driving, Mobile ticketing, Environment monitoring, Augmented maps |
| Healthcare | Tracking, Identification/authentication, Data collection, Sensing |
| Smart environments | Comfortable homes/offices, Industrial plants, Smart museum and gym |
| Personal and social | Social networking, Historical queries, Losses, Thefts |
| Futuristic | Robot taxi, City information model, Enhanced game room |

Hoca fütüristik uygulamalardan robot taksiyi örnek verdi: sürücüsü olmayan bir araca binip bir noktadan diğerine gideceğimiz günler gelecek. Drone'larla ilk etapta kargo şirketlerinin paket teslimi planlanıyor; apartmanlarda bu zor olduğu için girişlerde iniş alanları ayrılacak, müstakil evlerde bu alanlar zaten var. Hoca, insanların otonom araçlara güvenmesinin zaman alacağını, çünkü bir hatada can riski olduğunu söyledi.

Güvenin başlangıç noktası olarak sürücüsüz metro hatlarını örnek verdi. Bu hatlarda her şey bellidir: durak belli, kapının ne zaman kapanacağı belli, kapıdan biri geçerken sensör algıladığı için kapı asansördeki gibi kapanmaz. Kurallar yıllardır çalışılmış ve çözülmüştür. Ama sizi evden alıp rotayı belirleyen, her kavşakta sağdan soldan çıkanları değerlendirerek işe götüren bir aracı insanların kolayca kabul etmesi henüz mümkün görünmüyor. Belediyeler de şehirden gelen verilerle otobüslerin ne zaman geleceğini tahmin etmekten durakların doluluğuna göre yeni hat planlamaya kadar birçok bilgiyi işliyor; trafik ışıklarının bile otomatik sistemlerce yönetileceği bir noktaya gidiliyor.

Yapay zeka ile IoT doğal olarak iç içe çalışır. Hoca, futbolda hakem atamalarında yapay zekadan destek alınacağının açıklanmasını örnek verdi; orada girdiler, yani hakemlerin performansları, insan eliyle sisteme veriliyor. IoT uygulamalarında ise girdiler çoğunlukla sensörlerden gelir; bazı bilgiler kişi tarafından bir kez ya da belirli aralıklarla girilir.

Sürüş desteği (assisted driving) otonom araçların ön adımıdır. Park sırasında engele ne kadar yakın olduğunuzu bildiren, önünüze bir araç çıktığında otomatik yavaşlayan, şerit ihlalinde sizi şeritte tutan sistemlerin hepsi birlikte ADAS paketleri olarak düşünülebilir. Bu paketler bir noktada birleşerek otonom aracın kendisini oluşturacaktır.

## 5. Açık Araştırma Konuları ve Dijital Unutma

### 5.1 Açık konular tablosu

Slayttaki tablo IoT'deki açık araştırma konularını ve nedenlerini veriyordu (ekrandan, 00:35:00):

| Açık konu | Nedenin kısa açıklaması |
|---|---|
| Standards | Birçok standartlaştırma çalışması var, ama kapsamlı bir çerçevede birleştirilmemiş. |
| Mobility support | Nesne adresleme için birçok öneri var, ama IoT senaryosunda hareketlilik desteği yok; ölçeklenebilirlik ve heterojen teknolojilere uyum kritik. |
| Naming | Bir nesneye yapılan referansı nesnenin tanımına ve tanımlayıcısına eşlemek için Object Name Server (ONS) gerekir. |
| Transport protocol | Mevcut taşıma protokolleri bağlantı kurulumu ve tıkanıklık denetimi yüzünden IoT'de başarısız; nesnelerde aşırı tampon gerektirirler. |
| Traffic characterization and QoS support | IoT trafiği bugünkü internetten çok farklı desenler üretecek; yeni QoS gereksinimleri ve destek şemaları gerekir. |
| Authentication | Uygun kimlik doğrulama altyapıları IoT'de bulunmayacak; nesnelerin kaynakları kıt; ortadaki adam saldırısı ciddi bir sorun. |
| Data integrity | Genelde veriyi parolayla korumakla sağlanır, ama IoT teknolojilerinin desteklediği parola uzunlukları çoğu zaman güçlü koruma için çok kısa. |
| Privacy | Bir kişi hakkında, kişi farkında olmadan çok sayıda özel bilgi toplanabilir; bu bilginin yayılmasını denetlemek mevcut tekniklerle imkânsız. |
| Digital forgetting | Depolama ucuzladıkça IoT'nin bir kişi hakkında topladığı bilgi süresiz saklanabilir; veri madenciliğiyle yıllar sonra bile geri getirilebilir. |

Hoca standartların hâlâ tam oturmadığını, ama bazılarının yavaş yavaş oturmaya başladığını söyledi.

### 5.2 Hizmet kalitesi (QoS)

Hoca, verinin hangi öncelikle taşınacağı konusunun (quality of service, QoS) ciddi biçimde araştırılmaya değer olduğunu söyledi, çünkü çok sayıda IoT cihazının birbiriyle haberleşmesi büyük bir trafik yaratır ve bu trafikte önceliklendirme yapmak gerekir. Örnek olarak bilgisayarda video konferans yaparken bir dosya indirmeyi verdi: QoS mekanizması gerçek zamanlı kullanılan uygulamayı, yani video konferans paketlerini öne alır. IoT'de de verinin önceliği, gerçek zamanlı aktarılıp aktarılmayacağı, toplanarak tek seferde gönderilip enerji tasarrufu sağlanıp sağlanmayacağı gibi konular vardır.

### 5.3 Enerji

Fiziksel eşyaların elektronik aksamla donatılmasıyla oluşan IoT cihazları genelde güç sıkıntısı çekmez. Kablosuz sensör ağlarındaki gibi dışarıda ve güç kaynağından uzak değillerdir; şehirlere yerleştirilenler, evdeki, okuldaki, araçtaki cihazlar bir şekilde elektrikle beslenir. Ama ileride örneğin bir ayakkabıdaki IoT yapısı güç kaynağına bağlı olmayacak ve enerji tasarruflu yönetilmesi gerekecek. Yani enerji sorunu özellikle taşınabilir eşyalar için ileride karşımıza çıkacaktır.

### 5.4 Dijital unutma

Hoca dijital unutma (digital forgetting) konusunun uzun süredir ilgisini çektiğini ve hâlâ güncel olduğunu söyleyip sınıfa ne olabileceğini sordu. Bir öğrenci kişisel bilgilerin kişiye bağlı olarak saklanmaması gibi bir şey olabileceğini söyledi. Hoca bunun genel çatı altındaki bir başlık olabileceğini, ama yalnız kişisel değil cihazlar açısından da düşünmek gerektiğini söyledi.

Hocanın verdiği rakama göre dünyada yaklaşık 50 milyar bağlı cihaz var ve bunların üzerinde çeşitli bilgiler bulunuyor. Bu veriyi saklamak maliyetlidir; her cihaz belirli bir elektrik tükettiği için çevreye de zarar verir. Bu yüzden kullanılan bilgiyi arşivlemek yerine ondan kurtulmak ya da tekrar eden (redundant) veriyi ortadan kaldırmak gerekir. Örneğin mutfaktaki bulaşık makinesi ve buzdolabı benzer sensörlere sahiptir ve ikisi de ortamdan veri alır; ikisinin verisini de saklamak akıllıca değildir. Sensör ağlarında da konuşulduğu gibi, aynı bölgedeki beş sensörden gelen sıcaklık verisini ilk etapta doğrulama için kullanabilirsiniz, ama uzun vadede hepsini saklamak akıllıca değildir. Hangi verinin aktarılacağına, hangisinin merkeze gönderileceğine ve hangisinin cihazda tutulacağına karar vermek, ardından bu verileri belli aralıklarla silmek gerekir.

Hoca, kendi cihazlarımızda da birçok tekrar eden veri olduğunu hatırlattı ve bunu önlemek için kullanılan yapıyı sordu. Bir öğrencinin cevabı üzerine bunun bulut bilişim (cloud computing) olduğunu söyledi: veriyi ve yazılım hizmetini tek bir noktada tutmak, örneğin üç bilgisayara ayrı ayrı ofis programı kurmak yerine onu buluttan almak. Bulut bu işin başlangıç noktasıdır. Yine de verinin bir kısmını, özellikle ortamı izleyen cihazlarda, cihaz üzerinde tutmak zorundasınız. Bu cihazların saklama kapasitesi sınırlıdır ve belirli zamanlarda güncellenmesi gerekir. Veriyi sıkıştırarak saklamak, sıkıştırırken tekrarlı olanlardan kurtulmak; işte bu temizleme işine dijital unutma denir. İnsan hafızası da belirli bir kapasiteye sahiptir; kullanılmayan bilgiyi zamanla siler, bazen ikincil belleğe atar, bazen tamamen unutur.

Slayttaki ilgili maddeler de bunu söylüyordu: depolama maliyeti düştükçe saklanabilen veri miktarı çok artıyor; bu yüzden üretildiği amaç için artık işe yaramayan bilgiyi periyodik olarak silen çözümler gerekiyor ve gelecekte geliştirilecek yazılım araçları bu unutma işlevlerini desteklemeli (ekrandan, 01:10:00, slayt küçük resmi).

#### Fotoğraf seçme örneği

Hoca, bir cihazda aynı sahneye ait sekiz fotoğraf olduğunu ve bunlardan bir ya da iki tanesinin bırakılacağını düşünmemizi istedi: hangisini silersiniz ve nasıl karar verirsiniz? Bir öğrenci önce insanın karar vermesi gerektiğini düşündü; hoca ileride bir yapay zekanın bu kararı verip veremeyeceğini sordu, öğrenci verebileceğini söyledi. Hoca, böyle bir sistemi tasarlasaydık neye bakacağımızı sordu. Öğrencilerin ve hocanın saydığı ölçütler şunlardı: fotoğrafta insan varsa yüz ifadesi doğru görünüyor mu, bulanıklık (blur) var mı, netlik nasıl, renkler nasıl, kompozisyon doğru mu yoksa kaymış mı, gözler kapalı mı, kişi gülümsemiş mi, gülümseme abartılı mı yoksa hafif bir tebessüm mü, fotoğraf resmî bir fotoğraf mı.

Hoca, insanın da karar verirken bir algoritması olduğunu, herkesin algoritmasının farklı olabileceğini söyledi. Dijital unutma alanında da aynı mantıkla resimler, müzikler (örneğin hiç dinlenmeyen bir müziğin zamanla telefondan buluta taşınması ya da temizlenmesi) için sistemlerin otomatik karar verdiği mekanizmalar geliştirilecek. Hoca bu konunun güzel bir tez konusu olabileceğini de söyledi.

## 6. Haberleşme Protokolleri ve TCP'nin Yetersizliği

### 6.1 Haberleşme protokolleri

Cihazların birbiriyle haberleşirken kullandığı çok farklı protokoller vardır. Hoca bunların bir kısmını bir slaytta gösterdi.
<!-- BELİRSİZ: 00:40:14 civarında gösterilen protokol karşılaştırma slaytı karelerde yakalanmadı (00:40:00 karesinde slayt Zoom hatası yüzünden başa dönmüş görünüyor); tablodaki menzil ve veri hızı değerleri yalnız altyazıdan aktarıldı. -->

- **ZigBee:** Kablosuz sensör ağlarında kullanılan IEEE 802.15.4 protokolü. Yaklaşık 10 ile 100 metre arasında bir alanda çalışır ve veri hızı oldukça düşüktür.
- **6LoWPAN:** Son dönemde IEEE 802.15.4 üzerine kurulan bir standart. Hoca bu standardın, düşük güçlü olması ve IPv6 ağlarında kullanılabilmesi nedeniyle daha da yaygınlaşacağını öngördü; bunu ZigBee'nin IP ağına uyarlanmış hâli olarak tarif etti.
- **NFC:** Kullanımı giderek sıklaşıyor. Yakın temas gerektiren uygulamalarda güvenlik açısından çok değerlidir.
- **Bluetooth:** Daha uzak mesafeden bağlantıya izin verir.

Hoca NFC ile Bluetooth farkını bir sınıfta yoklama alma örneğiyle açıkladı: Bluetooth ile yoklama alınırsa yan sınıftaki biri de bağlanıp yoklamaya katılabilir; NFC yakın temas gerektirdiği için bu durumda tercih edilir. Hangi protokolün hangi uygulama için seçileceğine uygulamanın gereksinimlerine göre karar verilmelidir.

Haberleşme protokollerinin ötesinde mesajlaşma protokolleri de vardır; en bilinenleri MQTT ve CoAP'tır. Hoca bunlara da göz gezdirmenin faydalı olacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** MQTT, bir aracı sunucu (broker) üzerinden çalışan yayınla-abone ol (publish-subscribe) modelli, TCP üzerinde çalışan hafif bir mesajlaşma protokolüdür. CoAP ise UDP üzerinde çalışan, HTTP'ye benzer istek-yanıt (GET, POST vb.) modeli sunan ve kısıtlı cihazlar için tasarlanmış bir protokoldür.

### 6.2 Adresleme: IPv4 ve IPv6

IPv4 hâlâ kullanılsa da artık dağıtılacak IP bloğu kalmadığı için dünyadaki cihazlar IPv6'ya geçiyor. Hoca IPv6'nın başka özellikler de getirdiğini, özellikle paketlerin içindeki bilginin korunmasına yönelik güvenlik çözümleri sunduğunu ve bunların IoT ağlarında değerlendirilmesi gerektiğini söyledi.

"Addressing and Networking Issues" slaytında şu maddeler yer alıyordu (ekrandan, 00:45:00, slayt küçük resmi): IPv4 ve IPv6 (128 bit), RFID etiketleri (64-96 bit tanımlayıcılar), Domain Name Servers ve Object Name Service karşılaştırması, trafik karakterizasyonu (QoS). Slaytta bir RFID mesajının IPv6 paketi içine yerleştirilmesini gösteren bir şekil de vardı. Hoca, lojistikte QR kodla birlikte çok sık kullanılan bu tanımlama mekanizmalarına birazdan daha yakından bakılacağını söyledi.

### 6.3 TCP neden IoT için yetersiz?

Slaytta TCP'nin IoT için yetersiz olmasının üç nedeni yazıyordu (ekrandan, 00:45:00):

- **Connection Setup (bağlantı kurulumu):** Az miktarda veri, kurulum aşaması, kısıtlı kaynaklar.
- **Congestion Control (tıkanıklık denetimi).**
- **Data Buffering (veri tamponlama).**

Hoca, TCP'nin bağlantı kurma ihtiyacı yüzünden IoT tarafında pek tercih edilmediğini söyledi. En önemli neden, her cihazla bir el sıkışma (handshaking) mekanizması olmasıdır; bunun maliyeti yüksektir ve ciddi gecikmeye yol açabilir. IoT'de ağırlıklı olarak UDP kullanılır: arada bazı paketler kaybolsa da IoT cihazları küçük boyutlu veri gönderir ve bu veriler belirli bir sıraya çok ihtiyaç duymaz.

Slayttaki şekil iki protokol yığınını karşılaştırıyordu (ekrandan, 00:45:00):

| Katman | Internet Protocol Suite (TCP/IP) | IP Smart Objects Protocol Suite |
|---|---|---|
| Application Layer | HTTP/FTP/SMTP/etc. | CoAP |
| Transport Layer | TCP/UDP | UDP |
| Network Layer | IPv4/IPv6 | 6LoWPAN |
| Link Layer | 802.3 - Ethernet / 802.11 - Wireless LAN | IEEE 802.15.4e |

Hoca, CoAP'ın IP dünyasındaki HTTP ve FTP gibi uygulama katmanı protokollerine karşılık geldiğini, yani IoT'nin uygulama katmanı protokolü olduğunu söyledi.

## 7. IoT'de Güvenlik ve Mahremiyet

### 7.1 Temel tehditler

Aradan sonra hoca IoT güvenliğine geçti. IoT ağlarındaki en büyük sorun DDoS saldırıları ve bu saldırılarla IoT cihazlarının devre dışı bırakılma potansiyelidir. Düğümlerin, yani cihazların, bu tür yoğun isteklere karşı kendini koruyabilmesi gerekir ve bu konuda çözümler beklenmektedir.

Bir başka önemli sorun kimlik doğrulamadır (authentication). Hoca otonom araçlarda yeni nesil saldırılara dikkat çekti: bir aracın sistemine sızıldığında aracın yoldan çıkarılabileceği, yani bir kişiye bu yolla zarar verilebileceği kadar tehlikeli bir yapıdan söz ediyoruz. Verilerin manipüle edilmesiyle seçim sonuçlarının değiştirilebilmesi ya da bir olay yerindeki görüntülerin ortadan kaldırılabilmesi de verinin dijitalleşmesinden kaynaklanan ciddi risklerdir. Bu yüzden dijital adli bilişim (digital forensics) bölümleri çalışmaktadır ve verilerin kullanımına yönelik yeni düzenlemeler yapılmaktadır.

Hoca burada özellikle gönderilen verinin zaman damgasının ve cihaza kimlik doğrulamalı bir giriş mekanizmasıyla bağlanılabilmesinin çok önemli olduğunu vurguladı.

### 7.2 Güvenlik ilkeleri

"Security Basics in IoT" slaytındaki dört ilke şunlardı (ekrandan, 00:55:00):

- **Resilience to attacks (saldırılara dayanıklılık):** Sistem tek hata noktalarından kaçınmalı ve düğüm arızalarına kendini uyarlayabilmelidir.
- **Data authentication (veri kimlik doğrulama):** İlke olarak, elde edilen adres ve nesne bilgisi doğrulanmalıdır.
- **Access control (erişim denetimi):** Bilgi sağlayıcılar sağladıkları veri üzerinde erişim denetimi uygulayabilmelidir.
- **Client privacy (istemci mahremiyeti):** Belirli bir müşteriyle ilgili arama sisteminin kullanımını gözlemleyerek çıkarım yapabilen yalnız bilgi sağlayıcı olmalı; en azından böyle bir çıkarım çok zor olmalıdır.

Hoca, bilgiler buluta aktarılıyorsa başkaları tarafından öğrenilememesi ve verinin kime ait olduğu bilgisinin anlaşılamaması gerektiğini söyledi. Bunu parolaların saklanmasına benzetti: parolalar MD5 gibi tek yönlü özet (hash) fonksiyonlarıyla saklanır; verilerinize de belirli prosedürler uygulanarak verinin size ait olduğu, veriyi ele geçiren kişi tarafından anlaşılamamalıdır.

> **Ders sonrası not:** Hoca parolaların MD5 ile tek yönlü özetlenerek saklandığını örnek verdi. MD5 bugün parola saklama için güvenli kabul edilmez (hızlı hesaplanır ve çakışma saldırıları bilinir); parola saklamada büyük olasılıkla bcrypt, scrypt ya da Argon2 gibi tuzlu ve kasıtlı olarak yavaş fonksiyonlar önerilir. Örneğin ana fikri (tek yönlü saklama) doğrudur.

Telefonlarda da cihazın kendini korumasına yönelik mekanizmalar vardır: parmak izi ve Face ID gibi biyometrik özellikler, başkasının telefonu açıp kullanamaması için kullanılır. Telefon çalındığında konumunun ya da en son görüldüğü noktaların bulunabilmesi de benzer bir güvenlik çözümüdür ve bunlar IoT cihazlarına da uygulanabilir. Mobil cihazlar ek çözümler gerektirir. Sabit ve kişisel kullanımdaki cihazlarda ise eve ne zaman girip çıktığınızın anlaşılması bile ciddi bir açıktır: bu veriyi izleyen biri, evi fiziksel olarak gözlemeden hangi evin hangi saatlerde kullanıldığını çıkarabilir.

### 7.3 Kısıtlı kaynaklarda güvenlik

"Security and Privacy" slaytlarında şu noktalar vardı (ekrandan, 01:05:00 ve slayt küçük resmi):

- Nesnelere fiziksel olarak saldırmak kolaydır.
- İletişimin çoğu kablosuzdur; bu da gizlice dinlemeyi (eavesdropping) son derece kolaylaştırır.
- IoT bileşenlerinin çoğu, özellikle pasif bileşenler, enerji ve hesaplama kaynakları açısından düşük yeteneklidir; bu yüzden güvenliği destekleyen karmaşık şemaları uygulayamazlar.
- Veri bütünlüğü çözümleri: çoğu etiket teknolojisinde bellek korunur; kablosuz sensör ağları için de çözümler önerilmiştir.
- Tipik kriptografik algoritmalar hem kaynakta hem hedefte enerji ve bant genişliği açısından büyük kaynak harcar. IoT, enerji, iletişim ve hesaplama yeteneği ciddi biçimde kısıtlı elemanlar (RFID etiketleri, sensör düğümleri gibi) içerdiği için bu çözümler doğrudan uygulanamaz. Dolayısıyla kaynak kıtlığına rağmen yeterli güvenlik sağlayan yeni çözümler gerekir.

Hoca, cihazın ele geçirilip içindeki verinin dışarı çıkarılabileceğini, kablosuz haberleşme yüzünden havadan giden verinin dinlenebileceğini ya da manipüle edilebileceğini, zamanla veri bütünlüğü sorunları çıkabileceğini ve verinin gerçekten ilgili cihaz tarafından üretilip üretilmediğinin doğrulanması gerektiğini anlattı.

Yoğun işlem gücü gerektiren kriptografik çözümler kaynak tüketimi ve bant genişliği açısından uygun değildir. Hoca burada bir enerji dengesi önerdi: şifreleme için harcanacak enerji yüksekse, şifrelemesi ucuz ve şifre çözmesi daha maliyetli bir algoritma seçmek akıllıca olabilir. Böylece uç noktada, yani IoT cihazında şifrelerken az enerji harcanır, şifre çözme işi kaynakları bol olan merkezde yapılır. Bazı algoritmalar bu yönde, bazıları tersi yönde (şifrelemesi pahalı, çözmesi ucuz) çalışır; seçim yaparken buna dikkat etmek gerekir.

> **Ek bilgi (derste anlatılmadı):** Bu asimetriye bilinen bir örnek RSA'dır: küçük bir açık üs (ör. 65537) kullanıldığında şifreleme ve imza doğrulama ucuz, şifre çözme ve imzalama ise büyük özel üs nedeniyle çok daha pahalıdır.

Veri saklama açısından da cihazların kapasitesi sınırlıdır. Bu yüzden cihazların yakındaki diğer IoT cihazlarıyla koordine olması ve bazı bilgileri kendi üzerinde değil onlarda saklaması gerekebilir. Örneğin birden fazla sıcaklık sensörü varsa bir görevi belli bir süre bir cihazın yürütmesi önemlidir. Cihazın ürettiği veriyi gönderdikten sonra silebilmesi, hatta göndermeden önce ondan anlamlı bilgi çıkarıp ham veriden kurtulabilmesi de IoT cihazları için çok önemlidir.

## 8. Mobil Kötücül Yazılım Tespiti ve GAN

### 8.1 Kötücül yazılımı nasıl anlarız?

Hoca güvenlik konusunu telefon üzerinden somutlaştırdı. Telefonlarda kötücül yazılımlar (malware) vardır ve genelde telefondaki bilgileri dışarı sızdırmak üzere kurgulanır. Hoca, mağazadan indirilen bir uygulamanın kötücül olup olmadığını nasıl anlayabileceğimizi sordu; bilgisayarda antivirüs programları bu işi yaparken telefonda genelde antivirüs kullanılmaz.

Bir öğrenci, uygulamaların kategorileri olduğunu ve uygulamanın kategorisiyle ilgisi olmayan izinler istemesinin bir işaret olabileceğini söyledi. Örnek olarak bir finans uygulamasının tek kullanımlık şifreleri (OTP) otomatik doldurmak için SMS okumak istemesine Google'ın izin vermemesini verdi; bazı işlemler (ör. diyalog kutusu göstermek) için ise ayrıca izin gerekmez. Hoca bunun iyi bir başlangıç noktası olduğunu söyledi ve kötücül yazılımın analizinin özel bir ortamda nasıl yapıldığını sordu. Bir öğrenci daha önce emülatörden bahsedildiğini hatırlattı.

### 8.2 Sandbox ve emülatör analizi

Hoca daha önce anlatılan sandbox kavramını hatırlattı: Android'de her uygulama kendi sanal makinesinde ve diğer uygulamalardan izole olarak çalışır. Bir uygulama indirildiğinde, telefonda çalıştırılmadan önce aynı mantıkla bir emülatörde, yani izole bir sandbox ortamında çalıştırılıp nasıl davrandığı analiz edilebilir. Yazılım arka planda belirli verilere ya da erişim hakkı olmayan yerlere ulaşmaya çalışırsa bu analizle uygulama hakkında fikir edinilir.

Ancak kötücül yazılımlar da gelişmiştir: izole bir ortamda olduğunu anladığı anda bu davranışları sergilemez. Gerçek bir telefonda mı yoksa izole bir ortamda mı olduğunu kontrol eder; gerçek telefona geçtiğinde veriyi dışarı aktarmaya çalışır. Bu yüzden emülatörün gerçek telefon gibi davranabilmesi önemlidir. Gerçek bir telefon:

- belirli aralıklarla arama alır ve arama yapar,
- SMS alır ve gönderir,
- gün içinde belirli zamanlarda aktif olarak kullanılır,
- hem ivmeölçer gibi sensörler bazında hem fiziksel konum bazında hareket eder,
- ortam sıcaklığı, basınç gibi sensör değerleri değişir.

Kötücül yazılım bu karakteristiği algıladığında "hareketli ve kullanılan bir telefondayım" deyip kendini açığa çıkarır. Bu karakteristiği öğrenip benzer davranışı emülatöre sergiletebilmek bir araştırma konusudur. Sanal gelen ve giden arama, gelen ve giden SMS gibi aksiyonlar üreten çalışmalar zaten vardır, ama bunu daha profesyonel hâle getirmek mümkündür.

### 8.3 GAN ile sentetik veri

Bunun için çekişmeli üretici ağlar (generative adversarial networks, GAN) kullanılabilir. GAN'lar taklit yetenekleriyle gerçek veriden öğrenip benzer sahte, yani sentetik veri üretir; böylece emülatörlerin ya da başka alanlardaki sistemlerin gerçek veriye benzer verilerle çalışması sağlanır. GAN'da bir üreteç (generator) ve bir ayırt edici (discriminator) vardır. Üretecin ürettiği verinin ayırt ediciyi ne kadar kandırabildiği ve ayırt edicinin gerçek ile üretilmiş veriyi ne derece ayırabildiği çok önemlidir.

Hoca, birçok alanda veri toplamanın zor ve maliyetli olduğunu, bu yüzden GAN ile gerçeğe en yakın alternatif sentetik veriyi üretmek istediğimizi söyledi. Örneğin elinizde 100 veri varsa, bu 100 veriyi taklit eden 1000 sentetik veri üretip sistemi daha fazla veriyle eğitmek ve başarısını artırmak mümkündür. Bu çalışmalar birçok alanda yapılmaktadır ve hoca bunu zengin bir tez konusu olarak önerdi.

> **Ek bilgi (derste anlatılmadı):** GAN eğitimi iki oyunculu bir minimax oyunu olarak yazılır: $\min_G \max_D \; \mathbb{E}_{x \sim p_{\text{veri}}}[\log D(x)] + \mathbb{E}_{z \sim p_z}[\log(1 - D(G(z)))]$. Ayırt edici $D$ gerçek ile sahteyi ayırmayı, üreteç $G$ ise $D$'yi yanıltmayı öğrenir.

## 9. Barkod ve QR Kod

### 9.1 Barkoddan QR koda

Hoca, eşyalar hakkındaki bilgiyi nereden alacağımız sorusuna geçti. Covid döneminde birçok restoran fiziksel menü yerine masaya bir QR kod koyuyor; QR kodu telefonla okutup menüyü ya da menünün bağlantısını telefona alıyoruz. Tek boyutlu (1D) olarak başlayan barkod mantığı sonra iki boyutluya (2D) dönüştü. QR kod çok daha fazla bilgi saklayabildiği için bugün çok daha yoğun kullanılıyor. Tamamen 1 ve 0'ların kombinasyonuyla oluşturulan bir yapıdır.

Hoca "QR kod" adının bir marka adının genel ada dönüşmesi gibi olduğunu söyledi: bütün 2D kodlara QR kod diyoruz, ama içlerinde farklı mekanizmalarla tasarlanmış kodlar da var. 1D kodlar ağırlıklı olarak kütüphane sistemlerinde kullanılıyordu.

"Bar Codes and QR Codes" slaytında şunlar gösteriliyordu (ekrandan, 01:10:00):

- Bir barkodun yapısı: iki uçta boş bölge (quiet zone), başlangıç karakteri (start character), veri (data) ve bitiş karakteri (stop character).
- Dört QR kod sürümü: Version 1 (21×21), Version 2 (25×25), Version 3 (29×29), Version 4 (33×33).
- QR kod ile barkod farkı: QR kod (2D kod) hem yatay hem dikey yönde veri taşır; barkod yalnız yatay yönde veri taşır, dikey yönde veri yoktur.

Slayttaki sürüm boyutları her sürümde kenara 4 modül eklendiğini gösterir; yani Version $v$ için kenar uzunluğu $17 + 4v$ modüldür: $17+4 \cdot 1 = 21$, $17+4 \cdot 2 = 25$, $17+4 \cdot 3 = 29$, $17+4 \cdot 4 = 33$ (ara adım eklendi).

### 9.2 QR kod ne saklar, nerede kullanılır?

Hoca QR kodlarla hangi bilgilerin saklanabileceğini ve nerelerde kullanıldığını sordu. Sınıftan gelen cevaplar ve hocanın eklemeleri:

- Esas olarak bir dizgi (string) saklar; dolayısıyla her türlü bilgi saklanabilir.
- Her türlü bağlantı (link) için kullanılabilir.
- Akıllı otobüs duraklarında her durağa ekran koymak yerine bir QR kod konur; yolcu bağlanıp bilgiyi kendi cihazında görüntüler.
- Bazı kartvizitlerin üzerine kartvizitin dijital hâli gömülür.
- Kargo takibinde çok sık kullanılır.

### 9.3 QR kod ile RFID farkı

Hoca QR kodun RFID'den en büyük farkını sordu. Bir öğrenci QR kodun elektronik içermediğini ve temasa ihtiyaç duymadığını söyledi. Hoca, RFID'nin de temas gerektirmediğini ama elektromanyetik alanla çalıştığını, QR kodun ise tamamen fiziksel görüntüyle çalıştığını belirtti. QR kodda elektronik aksam yoktur. Diğer önemli fark görüş hattıdır (line of sight): kamera ile kod arasında engel olmadan doğrudan görüş olmalıdır; araya bir engel girerse RFID'deki gibi okuma şansı yoktur. RFID pasif bile olsa bir elektronik aksam içerdiği için QR kodun maliyeti çok daha uygundur.

### 9.4 İki QR kod karışabilir mi?

Hoca bir QR kodun başka bir QR kodla karışma olasılığını sordu. Bir öğrenci olabileceğini ama başına eklenecek ek bir kodla önlem alındığını düşündüğünü, uygulamaya özel kullanılırsa ya da bağlantı olarak kullanılırsa zaten belli olacağını söyledi. Hoca, denk gelme olasılığının milyarda bir mertebesinde olduğunu söyledi: kodu üreten her kişi kendi kodlamasını yapar ve alanlar (domain) farklı olduğu için başka bir noktadaki kombinasyonla örtüşme olasılığı çok düşüktür.

### 9.5 Farklı barkod ve 2D kodlar

1D barkodlarda kodlama, çizgiler arasındaki kalınlıklar esas alınarak tek boyutta yapılır. Prensip basittir, ama UPC ve Code 93 gibi farklı barkodların farklı mekanizmaları vardır (ekrandan, 01:10:00, slayt küçük resmi). 2D tarafta QR kodun yanında Data Matrix, Semacode ve MaxiCode gibi kodlar da vardır; literatürde kullanılırlar ama en sık QR kod kullanılır.

QR kodun kapasitesi hocanın verdiği değerlere göre 7089 sayısal karakter ya da ikili (binary) olarak 2953 bayttır; bu yaklaşık 3 KB'lık oldukça yüksek bir bilgidir. Hoca, 2D barkodların dört farklı yapısını karşılaştıran bir slaytta en yüksek veri kapasitesinin QR kodda olduğunu, her birinin geliştiricisinin farklı olduğunu ama temel yapının matrise dayandığını söyledi.

> **Ek bilgi (derste anlatılmadı):** 7089 sayısal karakter ve 2953 bayt değerleri, QR kodun en büyük sürümü olan Version 40 (177×177 modül, $17 + 4 \cdot 40 = 177$) ve en düşük hata düzeltme seviyesi (L) için geçerlidir. Aynı sürümde alfasayısal kapasite 4296 karakterdir; hata düzeltme seviyesi arttıkça kapasite düşer.

## 10. RFID Etiketleri ve Frekans Aralıkları

### 10.1 Sınıflandırma ve çalışma prensibi

RFID etiketleri üç temel ölçüte göre sınıflandırılır (ekrandan, 01:15:00, slayt küçük resmi):

- güç türü (aktif ya da pasif),
- bellek kapasitesi ve çalışma kipi (salt okunur ya da okunur-yazılır),
- frekans aralığı.

Güç türüne göre üç kategori vardır: pasif etiketler, yarı pasif etiketler ve aktif etiketler. Pasif RFID'de etiket, okuyucunun enerjisiyle okunur. Okuyucu (RFID reader) önce bir elektromanyetik sinyal yayar; etiketin anteni bu sinyali alır, enerji bir kondansatörde biriktikten sonra yeterli enerji oluştuğunda etiket üzerindeki bilgiyi radyo dalgalarıyla okuyucuya geri gönderir.

### 10.2 Frekans aralıkları

Hoca, çalışma frekansının RFID'lerin yeteneklerini çok değiştirdiğini söyledi. Slaytlardaki bilgiler şöyleydi (ekrandan, 01:15:00 ve 01:20:00):

**Düşük frekans (LF, 125-134 kHz):** Birçok uygulamada kullanılan pasif etiketlerdir. Diğer frekanslara göre en kısa okuma mesafesine (metrenin üçte birinden az) ve en düşük veri hızına sahiptir. Çakışma önleme (anti-collision) desteği sınırlıdır; aynı anda çok sayıda etiketi okumak zordur. Avantajı, sıvı ortamların yakınında başarıyla çalışabilmesidir. Hoca buna şu yorumları ekledi: düşük frekanslı ortamlarda çakışma olduğunda bunu gidermek kolay değildir ve aynı anda çok sayıda okuma yapılamaz; bu yüzden bir mağazada düşük frekans kullanılabilir, ama bir ambarda ya da limanda başarılı sonuç vermez. Sıvı ortamlarda sinyal iletimi avantajı nedeniyle bu ortamlar için LF etiket kullanmak akıllıcadır.

**Yüksek frekans (HF, 13.56 MHz):** Bunlar da pasif etiketlerdir, ama veri hızı LF'den iyidir. Antenleri daha basit olduğu için üretimleri ucuzdur. HF frekansı için kısıtlama olmadığından en yaygın etiketlerdir. En fazla okuma mesafesi yaklaşık bir metredir. NFC bu çalışma frekansını kullanır; HF ve LF etiketleri dünya genelinde lisanssız kullanılabilir. Hoca, NFC'nin pratikte bir metre değil santimetreler mertebesinde okuma yaptığını da ekledi.

**Ultra yüksek frekans (UHF, 433 MHz ve 860-930 MHz):** Birkaç farklı tasarımda uygulanır. 433 MHz aktif etiketler için en uygundur; diğer UHF penceresi çoğunlukla pasif ve yarı pasif etiketler için kullanılır. UHF etiketler çakışma önleme protokollerini destekler; bu sayede yüzlerce etiket aynı anda okunabilir. Başarıyla okunabilmesi için su ve metal içeren maddelerden yalıtılmalıdır. Okuma mesafesi etiketin güç kaynağına bağlıdır ve aktif etiketlerde 30 metreye kadar çıkar.

Hoca toplu okumanın lojistikteki önemini anlattı: toplu eşya aktarımında ürünlerin bir noktadan ayrıldığının işaretlenmesi gerekir ve paketleri tek tek okutmak insan gücü açısından maliyetlidir. Bu yüzden topluca RFID etiketi kullanmak tercih edilebilir; ama maliyet yüksek olduğu için bir ödünleşim vardır ve firmalar ne gönderdiklerine göre karar verir. 30 metrelik okuma mesafesi sayesinde bir tır bir noktadan geçerken ya da bir forklift yükü taşırken geçilen bölgedeki okuyucu yükün üzerindeki etiketi okuyabilir.

**Mikrodalga frekansı (çoğunlukla 2.4 GHz, bazen 5.8 GHz):** Yüksek frekans daha fazla enerji taşıyabildiği için okuma menzili ve veri hızı düşük frekanslı etiketlere göre çok daha yüksektir. Ortak sorun, mikrodalga ve UHF bantlarındaki radyo dalgalarının kolayca soğrulması, girişime uğraması ya da yansımasıdır. Ekipman maliyeti ve kullanım kısıtlamaları nedeniyle mikrodalga çözümleri nadir kullanılır; bu tür ekipmanı az sayıda firma üretir. Hoca mouse gibi cihazların 2.4 ya da 5 GHz'de çalıştığını örnek verdi.

> **Ders sonrası not:** Hoca 01:20:02 civarında yüksek frekanslarda verinin "uzun mesafelerle" ve ardından "daha kısa mesafelerle" taşınabildiğini söyledi; ifade altyazıda karışık. Slayta göre mikrodalgada okuma menzili ve veri hızı daha yüksektir; hoca 01:22:27'de bunu açık alan için doğruladı ve engeller olduğunda yüksek frekanslı sinyalin kolay bozulduğunu ekledi.

### 10.3 Frekansların karşılaştırması

Hoca frekansları bir tabloda bir arada gösterdi. Açık alanda aktarım mesafesi yüksek gigahertzlerde artar; ama yüksek frekanslarda dalga boyu küçüldüğü için engeller sinyali kolayca bozar. Bluetooth hoparlöre müzik gönderirken araya iki üç duvar girdiğinde bağlantının kopması bunun gündelik örneğidir.

Tablonun küçük resminden okunabilen değerler aşağıdadır (ekrandan, 01:20:00 ve 01:25:00, slayt küçük resimleri):

| | LF | HF | UHF | Mikrodalga |
|---|---|---|---|---|
| Frekans | 125-134 kHz | 13.56 MHz | 433, 860-930 MHz | 2.4, 5.8 GHz |
| Çalışma mesafesi | ~30 cm | ~1 m | ~30 m (aktif) | 100 m'den fazla |
| Girişim | Düşük | Düşük | Orta | Yüksek |
| Avantaj | Ortamda düşük soğrulma | Dünya genelinde kullanılabilir | Orta menzilli uygulamalar için ideal | Geniş erişim menzili |
| Yaygın uygulamalar | Hayvan kimliği, güvenlik, motor immobilizer | Güvenlik, mağaza takibi, biletleme | Konteyner ve kamyon takibi | Erişim denetimi, endüstri, üretim hatları |

<!-- BELİRSİZ: tablonun etiket maliyeti, okuyucu maliyeti ve veri hızı satırları küçük resimde okunamadı; mesafe satırı da küçük resimden okunduğu için kesin değil. -->

Hoca kullanım alanlarını şöyle açıkladı: LF daha çok hayvanların takibinde, araç anahtarıyla araç arasındaki haberleşmeyle motorun kilitlenip kilitlenmemesini yöneten güvenlik uygulamalarında ve yakın alan uygulamalarında kullanılır. HF eşya takibi ve biletlemede kullanılır. UHF limanlarda, ambarlarda, konteynerlerin, tırların ve kamyonların ve üzerlerindeki eşyaların takibinde kullanılır. Mikrodalga ise uzun mesafeli gönderim özelliğine rağmen daha çok fabrika ortamlarında, erişim denetiminde ve üretim hatlarında, makinelerin hızlı veri aktarması gereken yerlerde kullanılır.

## 11. RFID, QR Kod ve Barkod Karşılaştırması

### 11.1 RFID'nin avantajları

Slayttaki avantajlar şunlardı (ekrandan, 01:25:00): yeniden yazılabilme (rewrite capability), görüş hattı gerekmemesi, okuma mesafesinin artması, saklanan veri miktarının artması, birden çok etiketin okunabilmesi, RFID etiketlerinin (label) okunabilmesi, çalışma ortamı, akıllı davranış ve yüksek güvenlik.

Hoca bunları QR kodla kıyaslayarak açıkladı. QR kodun üzerindeki bilgi değiştirilemez; RFID'de yeniden yazılabilir. RFID'de kesintisiz ve engelsiz görüş zorunluluğu yoktur, araya engel girse de okuma sorunu yaşanmaz. QR kod kısa mesafeden okunur; metrelerce uzaktaki bir QR kod boyutu nedeniyle okunamayabilir. RFID'ye daha fazla bilgi saklanabilir ve aynı anda birden çok etiket okunabilir. RFID korunaklı olduğu için yağmurdan ve sudan etkilenmez; QR kod ise silinebilir, üzerindeki kod bozulabilir ve okunamaz hâle gelebilir. QR kodun bilgisi açıkta olduğu için RFID daha yüksek güvenlik sağlar.

### 11.2 RFID'nin dezavantajları

Slayttaki dezavantajlar (ekrandan, 01:30:00, slayt küçük resmi):

- Üretim karmaşıklığı: (2D) barkodlar herhangi bir yazıcıyla basılabilir, RFID etiket üretimi ise endüstriyel ekipman ya da özel yazıcı gerektirir.
- RFID sistemlerinin maliyeti (2D) barkoda dayalı sistemlerden yüksektir.
- Firmalar teknoloji yatırımının kendilerine faydasını yatırım getirisi (Return on Investment, ROI) gibi hesaplarla değerlendirir.
- Elektromanyetik alanlarda girişim; LF ve HF, yüksek frekanslı etiket ve okuyuculara göre girişime daha az maruz kalır.
- Güven eksikliği: kişiler hakkında özel bilgi toplanabilmesi.
- Barkod tabanlı çözümlerin sayısı RFID tabanlılardan çok fazladır.
- Açık standart eksikliği: farklı üreticilerin ekipmanları farklı standartlarda olabilir; bu da uyumluluk sorunları doğurur.

Hoca, QR kodun bastığınız anda işinizi gördüğünü, RFID'nin ise elektronik aksam içerdiği için pahalı olduğunu söyledi. Yaptığınız işe göre ROI mantığıyla bir operasyonda QR kod kullanıp maliyeti çok düşürebilirsiniz; uzun süreli bir RFID kullanımı olmayacaksa, yalnız geçici olarak bilgi taşınacaksa RFID yatırımı anlamlı olmaz. Elektromanyetik sinyaller ortamdaki fiziksel nesneler yüzünden saparak hatalı okumalara yol açabilir; çok nesneli ortamlarda kullanılan bant önemlidir ve doğru yapılanma gerekir. Barkod çok yüksek miktarda üretilebilir, RFID'yi maliyeti nedeniyle o kadar üretmek mümkün olmayabilir. Hoca örnek olarak küçük bir restoranda QR kodun yeterli olacağını, RFID'ye gitmenin gereksiz ve maliyetli olacağını söyledi. Standartların tam oturmaması ve farklı standartların bulunması da birlikte çalışabilirlik (interoperability) sorunları doğurur.

### 11.3 Karşılaştırma tablosu

Barkod, QR kod ve RFID'yi karşılaştıran slayt tablosu (ekrandan, 01:30:00):

| Özellik | Barkod | QR kod | RFID |
|---|---|---|---|
| Görüş hattı | Gerekli | Gerekli | Çoğu durumda gerekmez |
| Okuma mesafesi | Birkaç inç - birkaç fit | Birkaç inç - birkaç fit | Pasif: 30 fite kadar; aktif: yüzlerce fit |
| Tanımlama | Çoğu barkod yalnız ürün türünü tanımlar (tekil değil) | Her ürünü tekil tanımlayabilir (belirli bir değere kadar) | Her ürünü tekil tanımlayabilir |
| Okuma/yazma | Yalnız okuma | Yalnız okuma | Okuma ve yazma |
| Teknoloji | Optik (lazer) | Optik (lazer) | Radyo frekansı |
| Otomasyon | Çoğu barkod okuyucu insan gerektirir | QR okuyucular insan gerektirir | Sabit okuyucular insan emeği gerektirmez |
| Güncelleme | Güncellenemez | Güncellenemez | Eski etikete yeni bilgi yazılabilir |
| Takip | Elle takip gerekir | Elle takip gerekir | Takip gerekmez |
| Bilgi kapasitesi | Çok az | Az | QR ve barkoddan fazla |
| Dayanıklılık | Yok | Yok | Var |
| Güvenilirlik | Buruşmuş ve lekeli etiket çalışmaz | Buruşmuş etiket çalışabilir, verinin %30'u kurtarılabilir | Neredeyse kusursuz okuma oranı |
| Veri kapasitesi | Doğrusal kodda 20 karakterden az | 7089 karaktere kadar | Yüzlerce - 1000 karakter |
| Yön bağımlılığı | Var | Yok | Yok |
| Birim maliyet | 0.01 \$ | 0.05 \$ | 0.05-1 \$ |

Hoca, barkodun veri kapasitesinin çok düşük olduğunu, QR kodla bunun çok arttığını tekrar vurguladı. Maliyete bakıldığında çok uygun fiyatlı RFID etiketleri de vardır, ama bunların çalışma frekanslarının uygulamaya uygun olması gerekir. 5 sent ile 1 dolar arası çok geniş bir aralıktır: $1 / 0.05 = 20$, yani yaklaşık 20 kat fark vardır. Her etiket her uygulama için kullanılamaz; ama maliyet her geçen gün düştüğü için etiketlerin kullanımı yaygınlaşmaktadır.

> **Hocanın vurgusu:** QR kod ve RFID farklı amaçlar için kullanılır ve birbirinin yerine tercih edilmeleri söz konusu değildir; bazı uygulamalar için QR kod, bazıları için RFID akıllıca bir seçimdir.

## 12. Büyük Veri

### 12.1 Mobil veri her zaman büyük veri midir?

Dersin son bölümünde hoca "Big Data" başlıklı haftanın slaytlarına geçti (ekrandan, 01:35:00) ve kısa bir giriş yaptı. Soru şuydu: mobil cihazlardan toplanan veri her zaman büyük veri midir? Bunun yanıtı yalnız boyutla verilemez.

Hoca bilimin tarihsel gelişimini özetledi: yüzyıllar önce deneysel bilim, sonra çeşitli formüllerin ortaya atıldığı kuramsal bilim, son 50-60 yılda hesaplamalı bilim (computational science) ve bilgisayar dünyasına geçiş. Bugün ise bilgisayar özelinden bir parça ayrılarak herkesin veriyi anlamlandırmaya çalıştığı bir dünyadayız; bunun üzerine yapılan bilime veri bilimi (data science) denir. Veri biliminin temel yapı taşı da veridir.

### 12.2 3V ve 4V

Slayttaki 3V tanımı şöyleydi (ekrandan, 01:40:00):

- **Volume (hacim):** Veri kümesinin boyutu. Şekilde örnekler: terabaytlar, kayıtlar, işlemler (transactions), tablolar ve dosyalar.
- **Velocity (hız):** Verinin giriş ve çıkış hızı. Şekilde: toplu (batch), gerçek zamanlı, akış (stream), gerçeğe yakın zamanlı (near-time).
- **Variety (çeşitlilik):** Veri türlerinin ve kaynaklarının çeşitliliği. Şekilde: yapılandırılmış, yapılandırılmamış, yarı yapılandırılmış ve hepsi.

Hoca hacmin yeterli olmadığını vurguladı: verinin hızlı üretiliyor olması da önemlidir. Değişmeden bir kütle hâlinde duran veri bize büyük veriyi anlatmaz; sürekli değişen veri o verinin büyük veri olabileceğini söyler. Bu yüzden büyük veri, terabaytlarca veriyi işlemek demek değildir; günümüzde sistemler sürekli veri üretmeye devam ettiği için 3V kuralı çok önemlidir. Farklı veri kaynakları ve veri türleri de varsa, üçünün birlikte olduğu durumlara büyük veri denir.

Buna dördüncü bir V, doğruluk (veracity) da eklenmiştir. Minimum 3V özelliği gerekir; dördüncü V artık sorgulanmaktadır. Veracity, verilerde kesinlik kazanmamış, şüpheye yer veren durumların bulunmasıdır: verinin hatalı, eksik ya da tekrarlı olması. Hoca, hatalı ya da eksik verinin elbette istenmediğini, ama farklı kaynaklardan gelen, farklı cihazların ürettiği ve insanların sisteme girdiği verilerin bugün büyük oranda (hocanın tahminiyle %90-95) bu özelliklere sahip olduğunu söyledi. En düzgün toplanan veride bile bu dört özellik karşımıza çıkabilir.

> **Hocanın vurgusu:** Büyük veri yalnız boyut demek değildir; en az hacim, hız ve çeşitlilik birlikte bulunmalıdır.

### 12.3 Bellek içi işleme

Büyük veri, standart bir dosya üzerinden okuma yaparak koordine edilemez; veritabanından okuyarak bir sistem tasarlamak da pek mümkün değildir. Sık yanıt vermesi gereken sistemlerde veriyi depolama biriminde (storage) değil bellekte (memory) işlemek gerekir; bunun için bellek içi işleme (in-memory processing) çözümleri vardır. Sürekli depoya erişip veriyi belleğe taşımak yerine verinin önemli bir kısmı tek seferde belleğe aktarılır, mümkünse işlem orada tamamlanır ve belirli periyotlarla depoya yazılır.

### 12.4 Banka verisi örneği

Hoca sınıfa daha önce büyük veriyle çalışan olup olmadığını sordu; bir öğrenci banka verisiyle çalışan bir tanıdığını örnek verdi. Hoca banka verisini 4V açısından değerlendirdi: milyonlarca müşterinin verisidir (hacim); bir kısmı, özellikle işlemler (transactions), sürekli değişir (hız); kişiye ait bilgiler veritabanında, bazı bilgiler metin, bazıları multimedya formatında saklanır (çeşitlilik); verilerde belirli eksiklik ve tutarsızlıklar olabilir (doğruluk). Bu yüzden tam bir büyük veri örneğidir.

### 12.5 Uygulama alanları

Hoca başka alanları da saydı: havacılık, eğitim ve devlet. Devlet, kişilerin bilgilerini ve farklı kurumlardaki işlemlerini yönetir; bir kişi anlık olarak sisteme girip öğrenci belgesi ya da askerlik durumu gibi belgeleri isteyebilir. Meteorolojide hava olaylarının çok değişken olması, uzayda gezegen ve meteor hareketlerinin değişkenliği, ilaç sektöründe ve gen ve biyoloji alanında simülasyonlarda üretilebilecek olası senaryolar da büyük veri örnekleridir. İşin bir de sosyal tarafı vardır: sosyal hesaplama (social computing) ile sosyal ağlarda insanlara ilişkin analizler yapılır. Kişilerin gündelik hareketlerinin incelenerek tehlikeli olabilecek aktivitelerin anlaşılmaya çalışılması ve havalimanlarında kamera görüntülerinden şüpheli davranışların tespit edilmesi de bu kapsamdadır.

Slayttaki "Some Big Data App in Different Scientific Disciplines" listesi (ekrandan, 01:45:00): astronomi, atmosfer bilimi, tıp, genomik, biyoloji, biyojeokimya, sosyal hesaplama (sosyal ağ analizi, öneri sistemleri, tahmin piyasaları) ve internet arama indekslemesi.

### 12.6 Kazanımlar ve zorluklar

Hocaya göre büyük verinin kazandırdıkları ağırlıklı olarak operasyonel verimliliği artırmak, ileriye dönük stratejik planları (ör. şehir planlama) veriye dayanarak yapmak ve daha iyi müşteri hizmeti vermektir. Bugün bu sayede meteorolojide iki haftalık, hatta ay mertebesinde tahmin yapılabilmektedir; iki haftalık tahminler oldukça başarılı noktaya gelmiştir. Trafik akış hızı tahmini de büyük veriyle çözülen sorunlara bir örnektir.

Zorluklar slaytta şöyle sıralanıyordu (ekrandan, 01:50:00): işlemci yoğun ama G/Ç zayıf (CPU-heavy but I/O poor), veri tutarsızlığı, veri eksikliği, veri ölçeklenebilirliği, veri zamanlılığı ve veri güvenliği. Bir sonraki slaytta büyük veri zorlukları veri yakalama, düzenleme (curation), depolama, arama, paylaşma, aktarma, analiz ve sunum olarak listeleniyordu. Hoca, yapılacak işlerin hesaplama açısından karmaşık olabileceğini, G/Ç'de tutulan veriye erişimin yavaş olduğunu ve verideki eksiklikler ile tutarsızlıklar için çözüm üretmek gerektiğini söyledi. Büyük veriyi yönetmek için Hadoop gibi platformlar kullanılmaktadır. Hoca kalan yaklaşık on slaytın okunmasını istedi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:33:42): Dijital unutma (digital forgetting) nedir? IoT'de neden gereklidir?

> **Cevap (derste verildi):** IoT cihazlarının ürettiği tekrarlı ve artık işe yaramayan verinin ayıklanması, sıkıştırılması ve belirli aralıklarla silinmesidir. Yaklaşık 50 milyar bağlı cihazın verisini saklamak maliyetlidir ve enerji tüketir; aynı ortamı ölçen cihazların (ör. mutfaktaki iki cihaz ya da aynı bölgedeki beş sıcaklık sensörü) verisinin hepsini saklamak gereksizdir. Hangi verinin merkeze gönderileceği, hangisinin cihazda kalacağı ve ne zaman silineceği belirlenmelidir.

**Soru 2** (derste sözlü, 00:36:23): Verilerimizin farklı cihazlarda toplanıp tekrar etmemesi için bugün kullanılan, çok bilinen yapı nedir?

> **Cevap (derste verildi):** Bulut bilişim (cloud computing). Veri ve yazılım hizmeti tek bir noktada tutulur; örneğin üç bilgisayara ayrı ayrı ofis programı kurmak yerine hizmet buluttan alınır. Yine de ortamı izleyen cihazlarda bir miktar veri tutulmak zorundadır.

**Soru 3** (derste sözlü, 00:38:00): Bir cihazda aynı sahneye ait sekiz fotoğraf var ve bir ya da ikisi bırakılacak. Hangilerini silersiniz, neye göre karar verirsiniz? Bu kararı bir yapay zeka verebilir mi?

> **Cevap (derste verildi):** Ölçütler: yüz ifadesi, gözlerin açık olması, gülümseme ve tebessümün doğallığı, bulanıklık ve netlik, renkler, kompozisyonun kaymış olup olmadığı, fotoğrafın resmî olup olmadığı. İnsanın da karar verirken bir algoritması vardır; bu ölçütler bir yapay zeka sistemine öğretilerek dijital unutma kararları otomatikleştirilebilir.

**Soru 4** (derste sözlü, 00:56:38): Mobil tarafta, mağazadan indirdiğimiz bir uygulamanın kötücül yazılım (malware) olup olmadığını nasıl anlayabiliriz?

> **Cevap (derste verildi):** İlk ipucu, uygulamanın kategorisiyle ilgisiz izinler istemesidir (ör. SMS okuma). Sistematik yol, uygulamayı telefonda çalıştırmadan önce izole bir sandbox/emülatör ortamında çalıştırıp davranışını analiz etmektir. Gelişmiş zararlı yazılımlar emülatörde olduklarını anlayıp kendilerini gizlediği için emülatörün gerçek telefon gibi arama, SMS, hareket ve sensör verisi üretmesi gerekir; bunun için GAN ile sentetik davranış verisi üretmek bir araştırma konusudur.

**Soru 5** (derste sözlü, 01:07:32): QR kodlarla hangi bilgiyi saklayabiliriz, hangi alanlarda kullanılır?

> **Cevap (derste verildi):** QR kod esas olarak bir dizgi sakladığı için her türlü bilgi saklanabilir. Kullanım alanları: her türlü bağlantı (link), restoran menüleri, akıllı otobüs duraklarında bilgi ekranı yerine QR kod, kartvizitlerin dijital hâli, kargo takibi.

**Soru 6** (derste sözlü, 01:08:34): QR kodun RFID'den en büyük farkları nelerdir?

> **Cevap (derste verildi):** QR kodda elektronik aksam yoktur, tamamen fiziksel görüntüyle çalışır; RFID ise elektromanyetik alanla çalışır (temas ikisinde de gerekmez). QR kod görüş hattı gerektirir, araya engel girerse okunamaz. QR kod çok daha ucuzdur ama güncellenemez, kısa mesafeden okunur ve fiziksel olarak bozulabilir.

**Soru 7** (derste sözlü, 01:09:51): Bir QR kodun başka bir QR kodla karışma olasılığı var mıdır?

> **Cevap (derste verildi):** Olasılık milyarda bir mertebesinde, yani çok düşüktür. Kodu üreten her kişi kendi kodlamasını yapar ve kullanım alanları (domain) farklı olduğu için iki kodun örtüşmesi pek olası değildir.

**Soru 8** (derste sözlü, 01:43:28): Banka verisi neden büyük veri sayılır?

> **Cevap (derste verildi):** Milyonlarca müşterinin verisidir (hacim); işlemler sürekli değişir (hız); veri veritabanı, metin ve multimedya gibi farklı formlarda saklanır (çeşitlilik); verilerde eksiklik ve tutarsızlık olabilir (doğruluk). Dört V'nin hepsini taşıdığı için tam bir büyük veri örneğidir.

## Dersin Toparlaması

Bu derste Nesnelerin İnterneti, kablosuz sensör ağlarının devamı olarak ele alındı. IoT'nin internet, nesne ve anlamsal vizyonların kesişimi olduğu, her cihaza IP ile birebir erişim ve iki yönlü veri akışıyla WSN'den ayrıldığı anlatıldı. Spime kavramı ve verinin zaman ile kaynak bilgisinin değiştirilemez olması, SOA tabanlı ara katman, uygulama alanları ve açık araştırma konuları (standartlar, QoS, kimlik doğrulama, mahremiyet, dijital unutma) incelendi. Protokol tarafında TCP'nin bağlantı kurulumu, tıkanıklık denetimi ve tamponlama nedeniyle IoT'ye uygun olmadığı, bunun yerine UDP, CoAP, 6LoWPAN ve IEEE 802.15.4e yığınının kullanıldığı görüldü. Güvenlikte kaynak kısıtları, şifreleme enerjisi dengesi ve mobil kötücül yazılımların emülatörde tespit edilmesi tartışıldı; GAN ile sentetik veri üretimi bir araştırma yönü olarak önerildi.

Dersin ikinci yarısında nesneleri tanımlamanın iki temel yolu olan QR kod ve RFID karşılaştırıldı: QR kod ucuz ama görüş hattı gerektiren ve güncellenemeyen bir yapıdır; RFID frekansına göre (LF, HF, UHF, mikrodalga) farklı menzil ve veri hızları sunan, toplu ve görüş hattı olmadan okunabilen ama pahalı bir teknolojidir. Son olarak büyük veriye giriş yapıldı: büyük verinin yalnız boyut değil hacim, hız, çeşitlilik ve doğruluk özellikleriyle tanımlandığı, bellek içi işleme ve Hadoop gibi platformlarla işlendiği ve birçok bilim alanında kullanıldığı anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
