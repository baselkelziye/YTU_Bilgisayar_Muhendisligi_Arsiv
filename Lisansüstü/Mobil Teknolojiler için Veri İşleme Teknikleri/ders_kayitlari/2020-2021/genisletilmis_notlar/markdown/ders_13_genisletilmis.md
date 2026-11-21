# Ders 13 Genişletilmiş Notu: IoT Standartları, Barkod/QR Kod ve RFID, Yeni Nesil Otonom Araçlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. IoT Standardizasyonu ve Adresleme (Önceki Haftanın Tamamlanması)
- 2. IoT İçin Protokol Yığını
- 3. IoT'de Güvenlik ve Mahremiyet
- 4. Barkod ve QR Kod
- 5. QR Kodun Avantaj ve Dezavantajları
- 6. NFC ve Mobil Ödeme
- 7. RFID: Etiket Türleri ve Çalışma Prensibi
- 8. RFID Frekans Bantları
- 9. RFID Spektrum Karşılaştırması ve Uygulamaları
- 10. RFID'nin Avantajları ve Dezavantajları
- 11. Yeni Nesil Araçlar ve SAE Otomasyon Seviyeleri
- 12. Araç Zekası İçin İzlenmesi Gereken Bağlamlar
- 13. ADAS'ın Tarihçesi ve Amaçları
- 14. Araç Zekası Mimarisi ve Sensörler
- 15. Açık Konular ve Otonom Araçların Henüz Yolda Olmamasının Nedenleri
- Örnek Sorular

## 1. IoT Standardizasyonu ve Adresleme (Önceki Haftanın Tamamlanması)

Ders, önceki haftanın IoT slaytlarının kaldığı yerden başladı. Hoca bu kısmı hızlı geçeceğini, çünkü otonom araçlar üzerine yaklaşık 15 slayt hazırladığını söyledi.

### 1.1 Standardizasyon çalışmaları

Ekrandaki tablo, en önemli standardizasyon çalışmalarını amaç, durum, iletişim menzili, veri hızı ve birim maliyetle karşılaştırıyordu (ekrandan, 00:20:00):

| Standart | Amaç | Durum | Menzil (m) | Veri hızı (kbps) | Birim maliyet ($) |
|---|---|---|---|---|---|
| EPCglobal | RFID'yi elektronik ürün kodu (EPC) çerçevesine entegre etmek | Advanced | ~1 | ~$10^2$ | ~0.01 |
| GRIFS | Yerel RFID uygulamalarından nesnelerin internetine geçişi destekleyen RFID standartları (Avrupa) | Ongoing | ~1 | ~$10^2$ | ~0.01 |
| M2M | Makineden makineye iletişim için düşük maliyetli çözümler | Ongoing | N.S. | N.S. | N.S. |
| 6LoWPAN | Düşük güçlü IEEE 802.15.4 cihazlarını IPv6 ağlarına entegre etmek | Ongoing | 10-100 | ~$10^2$ | ~1 |
| ROLL | Düşük güçlü ve kayıplı heterojen ağlar için yönlendirme protokolleri | Ongoing | N.S. | N.S. | N.S. |
| NFC | Kısa menzilli, çift yönlü iletişim protokolleri | Advanced | ~$10^{-2}$ | 424'e kadar | ~0.1 |
| WirelessHART | IEEE 802.15.4 üzerinde kendini organize eden, kendini onaran ağ protokolleri | Advanced | 10-100 | ~$10^2$ | ~1 |
| ZigBee | Güvenilir, düşük maliyetli, düşük güçlü kablosuz izleme ve kontrol ürünleri | Advanced | 10-100 | ~$10^2$ | ~1 |

Hoca bu alternatiflerden özellikle RFID üzerinden nesnelerin temsil edilmesinin, karakterize edilmesinin ve "sanal kimliklerinin" ortaya konmasının kritik olduğunu söyledi; çünkü artık her gönderinin, her kargonun takip edilmesi gerekiyor. Kargoların üzerinde RFID etiketi olmayabilir; orada QR kod devreye girer. Bu iki teknoloji birbirinin rakibidir ve dersin ilerleyen kısmında aralarındaki rekabet konuşuldu.

### 1.2 Adresleme ve ağ sorunları

Adresleme tarafında IPv4 ve IPv6 sorunu vardır. IPv4 adresleri tükendiği için arka planda Network Address Translation (NAT) kullanmak gerekiyor; hocaya göre IPv6'ya tamamen ve acil olarak geçilmesi gerekiyor. Slayt kenar çubuğundaki küçük görüntüde bu başlık altında IPv4'e karşı IPv6 (128 bit), RFID etiketleri (64-96 bit tanımlayıcı), Domain Name Service'e karşı Object Name Service ve trafik karakterizasyonu (QoS) maddeleri okunuyordu (ekrandan, 00:20:00).

Hoca iki noktanın altını çizdi. Birincisi RFID etiketlerinin tanımlayıcıları için kaç bit kullanılacağıdır. İkincisi trafik karakterizasyonu, yani Quality of Service: bilgiler aktarılırken hangi bilginin ağ üzerinde önceliği olacağına göre bir servis yapısı düşünülmelidir.

## 2. IoT İçin Protokol Yığını

Hoca, TCP/IP yığınının IoT için uygun olmadığını gösteren slayta geçti. Kullanılan düğümlerin ya da akıllı cihazların kapasiteleri düşük olduğu için tampon (buffer) kısmında birikmeler olabilir ve bu da bağlantılarda sorun çıkarabilir.

Akıllı nesneler için oluşturulan yığında uygulama katmanında CoAP vardır. Hocaya göre CoAP'ın karşılığı UDP'ye daha yakındır; MQTT'de ise biraz daha TCP modeli uygulanır. Hoca CoAP'ın bir kayıt yapısına dayandığını, kayıt olduktan sonra verinin size yayınla geldiğini, böylece arada bazı kayıplar olsa da UDP'deki gibi akışın çok bozulmadığını anlattı.

> **Ders sonrası not:** Hoca CoAP'ı "kayıt olunca size yayınla gelen" bir yapı olarak anlattı. Büyük olasılıkla bu tarif daha çok MQTT'nin aracı (broker) tabanlı yayınla-abone ol modeline uyar; MQTT TCP üzerinde çalışır. CoAP ise UDP üzerinde istek-yanıt modeliyle çalışır ve bir kaynağı izlemek için "observe" seçeneği sunar.

Hoca öğrencilere 6LoWPAN'ı bilip bilmediklerini sordu. Bir öğrenci açılımı "low power wireless personal area network" gibi bir şey olarak tahmin etti. Hoca 6LoWPAN'ın IoT cihazlarının birbirleriyle haberleşmesi için kurdukları ve mümkün olduğunca az enerji tüketmeye yönelik bir ağ yapısı olduğunu, yavaş yavaş yaygınlaştığını söyledi. Bağlantı katmanında ise IEEE 802.15.4e protokolü kullanılır.

> **Ek bilgi (derste anlatılmadı):** 6LoWPAN, "IPv6 over Low-Power Wireless Personal Area Networks" ifadesinin kısaltmasıdır. IPv6 paket başlıklarını sıkıştırarak IEEE 802.15.4'ün küçük çerçevelerine sığdırır.

Hoca IoT cihazlarının bu katmanları performans açısından kendi yönlerine göre değiştirdiğini, bunların hepsinin araştırma konusu olduğunu söyledi. Ağ alanında çalışmak isteyenler IoT tabanlı problemlere yönelirlerse tatmin edici işler yapabilirler.

## 3. IoT'de Güvenlik ve Mahremiyet

Hocaya göre en büyük problem, her yerde olduğu gibi güvenliktir. IoT cihazlarının kimlik doğrulamadan dış saldırılara karşı korunmaya kadar kontrollü bir yapıda olması gerekir. Daha önceki derslerde söylendiği gibi bunun için middleware kullanılmalıdır: cihazlara doğrudan erişmek yerine cihazların topladığı verileri middleware'in sunması daha uygundur.

IoT cihazları fiziksel olarak kullanılan cihazlar olduğu için bozulma ve saldırıya uğrama olasılıkları yüksektir; korunaklı konumlarda olmayabilirler. Kablosuz haberleştikleri için havada giden verinin yakalanması önemli bir risktir. Slaytta veri bütünlüğü için çoğu etiket teknolojisinde belleğin korunduğu ve kablosuz sensör ağları için çözümler önerildiği yazıyordu (ekrandan, 00:25:00).

Burada kullanılacak kriptografik algoritmalar kritiktir. Slayta göre tipik kriptografik algoritmalar hem kaynakta hem hedefte enerji ve bant genişliği açısından büyük kaynak harcar. RFID etiketleri ve sensör düğümleri enerji, iletişim ve hesaplama yetenekleri bakımından ciddi şekilde kısıtlı olduğu için bu çözümler IoT'ye uygulanamaz. Bu yüzden kaynak kıtlığına rağmen tatmin edici güvenlik sağlayabilen yeni çözümler gerekir (ekrandan, 00:25:00).

> **Hocanın vurgusu:** Kablosuz haberleşmedeki kriptografi, kablolu haberleşmedeki kriptografiyle aynı düzeyde olmayabilir. IoT cihazlarında bunun bir kez daha düşünülmesi gerekir, çünkü bu cihazlar kablosuz erişim noktasından bile daha düşük kaynağa sahiptir.

## 4. Barkod ve QR Kod

### 4.1 Barkod

Barkod hayatımıza çok önceden, özellikle kütüphanelerde girmiş, tek boyutlu verinin tek boyutlu şekilde kodlanarak saklandığı bir yapıdır. Bilgi siyah ve beyaz renk kavramı üzerinden kodlanır ve genellikle yatay olarak ifade edilir. Desenin parçalarının da anlamı vardır: başlangıç karakteri, bitiş karakteri, verinin bulunduğu yer, sessiz bölge (quiet zone) gibi. Farklı barkod kodlama teknikleri vardır; slaytta UPC ve Code 93 olmak üzere iki farklı desen gösterildi.

### 4.2 QR kod

Barkodu uzun süre kullandıktan sonra şu fark edildi: veri tek boyutta saklanıyor, neden matrislerde olduğu gibi iki boyutta saklanmasın? QR kod hayatımıza bu şekilde girdi; ikinci boyutta da veri saklar.

Farklı iki boyutlu kodlar vardır. Ekrandaki şekilde soldan sağa QR Code, Data Matrix/Semacode ve MaxiCode yer alıyordu (ekrandan, 00:30:00). Hoca, "QR kod" adının bir tür jenerik ad haline geldiğini, tıpkı bir kağıt mendil markasının bütün kağıt mendiller için kullanılması gibi, aslında farklı kare kodların olduğunu söyledi. Bu kare kodlar belirli desenleri kendilerine şablon alır.

Karşılaştırma yapıldığında QR kod, diğerlerine göre daha fazla veri saklama kapasitesi nedeniyle öne çıkar. Ayrıca belli bir süre içinde kabul görmesi herkesi bu tarafa kaydırdığı için standartlaşma oluşmuştur. Saklanabilecek bilgi kapasiteleri slaytta byte cinsinden verilmişti. Slayt kenar çubuğundaki küçük görüntüde QR kod için en fazla 7.089 sayısal karakter, 4.296 alfanümerik karakter ve 2.953 byte ikili (8 bit) veri okunuyordu (ekrandan, 00:30:00).

> **Ek bilgi (derste anlatılmadı):** Bu üç sınır aynı bit kapasitesinin farklı kodlamalarıdır. Sayısal modda 3 rakam 10 bitle, alfanümerik modda 2 karakter 11 bitle kodlanır. $7089 \cdot 10/3 \approx 23630$ bit ve $4296 \cdot 11/2 = 23628$ bit eder; ikisi de yaklaşık $2953$ byte'a karşılık gelir (python ile kontrol edildi).

## 5. QR Kodun Avantaj ve Dezavantajları

Hoca QR kodun yapısının bazı alanları sabit tutmaya zorladığını, geri kalan alanların istenildiği gibi yapılandırılabildiğini söyledi ve QR kodun RFID'ye göre avantaj ve dezavantajlarını sordu. Bu kısım tamamen soru-cevapla ilerledi.

**Soru:** QR kodun dezavantajları nelerdir?
**Cevap:** Bir öğrenci önce görüş hattı (line of sight) gerektirdiğini, ayrıca okuyucunun tam karşıdan bakmasını istediğini, açıya karşı çok hassas olduğunu söyledi. Hoca görüş hattının çok önemli olduğunu onayladı.

İkinci bir öğrenci, QR koda konan veri miktarı arttıkça fotoğrafın daha yüksek çözünürlükle çekilmesi gerektiğini, açı karmaşıklaştıkça bunun daha da önem kazandığını ekledi. Hoca bunu çok önemli buldu: veri miktarı arttıkça çözünürlük artmalıdır; çekilen fotoğrafın kalitesi iyi değilse en ufak farklılık yanlış bilgi okunmasına yol açar. Bu da daha kaliteli okuyucular gerektirir ve maliyeti artırır.

Bir öğrenci avantaj olarak verinin doğrudan dijital olarak alınabildiğini, pratikteki bir sorun olarak da kartvizitlerde QR kodun okunup okunamadığı kontrol edilmeden çok küçük ya da kartın çok kenarına basıldığını söyledi. Hoca, mobil teknolojiler için yalnız teorideki değil pratikteki kullanımın da çok önemli olduğunu ekledi. Başka bir öğrenci, giriş kartı gibi güvenlik amaçlı kullanımlarda QR kodun zaman zaman yenilenmesi gerekebileceğini söyledi. Bir diğer öğrenci, katlanan kağıtlar üzerinde barkodun hatayı QR koda göre daha kolay tolere ettiğini, QR kodda baskı kalitesinin çok iyi olması gerektiğini anlattı.

Hoca bunları şu dezavantajlarla tamamladı:

- QR kod fiziksel koşullarda yıpranmaya açıktır: yırtılma, silinme, yağmurdan etkilenme, taşınırken bozulma. RFID'de böyle bir sorun yoktur.
- QR kodlarda çoklu okuma kolay değildir. Çok iyi bir düzenek kurulsa bile ancak belli sayıda ürün okunabilir. RFID'nin bazı türleri ise toplu çıkışlarda o bölgeden ayrılan bütün ürünlerin etiketlerini okuyup çıkış bilgisini saklayabilir.
- Okuma için genellikle belirli bir okuyucu gerekir ve bunu ayarlamak zaman kaybıdır. Yaygın bir sistematik yoktur; kargo şirketlerinde bile okutan kişi kodu denk getirmeye çalışır.
- Açılı okuma önemli bir konudur. Marketlerdeki kendi kendine ödeme noktalarında okuyucular açılı yerleştirildiği için ürünü tam denk getirmek gerekmez.

> **Hocanın vurgusu:** Bir QR kod, kullanıma alınmadan önce kalite kontrolden ve testten geçmelidir. Bilmeden üretilen ve kameranın okuyamayacağı boyutta basılan QR kodlar pratikte ciddi sorun çıkarır.

## 6. NFC ve Mobil Ödeme

Bir öğrenci, RFID dışında bilgilerin başka bir mantıkla taşınıp taşınamayacağını, NFC'de de bir aktarım olduğunu sordu. Hoca NFC'nin biraz farklı olduğunu, orada da RFID mantığının devreye girdiğini anlattı: Near Field Communication kısa menzilde çalışır, karşı tarafta mutlaka bir NFC okuyucu ve okunacak bir etiket olmalıdır. Böylece konu QR kod, NFC ve RFID üçgenine girer.

Bir öğrenci NFC'nin mobil ödemelerde çok ciddi bir rol oynadığını ve kullanım oranlarının arttığını söyledi. Ödeme noktalarında artık ekranlar olduğu için QR kodla ödeme hem web hem POS üzerinden sağlanabiliyor; ancak Android tarafında QR'dan çok NFC kullanılıyor. NFC ile telefon internete bağlı olmasa bile doğrudan POS'a yaklaştırılarak ödeme yapılabiliyor. Bu noktada NFC ile QR kod ciddi bir yarış halinde.

**Soru (hocanın):** iOS'un NFC'yi uzun süre üçüncü taraflara açmamasının nedeni ne olabilir?
**Cevap:** Bir öğrenci, Apple'ın son sürümlerle SDK'larını açtığını ama NFC'yi yalnız kendi ödeme sisteminde kullanılabilecek şekilde sınırladığını, kartlı ödeme kuruluşlarının API'lerini destekleyecek açık bir NFC sunmadığını söyledi. Hoca bunun iOS ile Android arasındaki en önemli yaklaşım farklarından biri olduğunu belirtti.

## 7. RFID: Etiket Türleri ve Çalışma Prensibi

### 7.1 Sınıflandırma

RFID etiketleri üç farklı şekilde ayrılabilir:

- Güç tipine göre: aktif ve pasif RFID.
- Çalışma moduna göre: salt okunur ya da okuma-yazma. Maliyeti düşük olduğu için birçok RFID salt okunur modda üretilir.
- Frekans aralığına göre (bölüm 8).

Hoca RFID'de okuyucunun yalnız veri değil enerji de taşıdığını vurguladı. Bu enerjiyle pasif etiketler beslenir ve veriyi geri gönderebilecek enerji onlara aktarılmış olur. Bu önemli bir artıdır. Etiketler aktif, yarı pasif (semi-passive) ve pasif olarak üçe ayrılır.

**Soru (hocanın):** Pasif, aktif ve yarı pasif etiket hakkında ne biliyorsunuz?
**Cevap:** Bir öğrenci kıyafetlerde ve tekstil ürünlerinde kullanılan etiketlerin pasif olduğunu düşündüğünü söyledi; hoca kıyafet bölümünde daha çok pasif etiket kullanıldığını onayladı.

**Soru (hocanın):** Aktif etiketleri nerede kullanabiliriz?
**Cevap:** Bir öğrenci ortak bir yetkilendirme sunucusuna bağlı kapıları önerdi: şifresi ve kriptosu değişebilen yerlerde bunun dinamik olarak güncellenmesi gerekir. Hoca bunu mantıklı buldu. Aktif etiketler üzerinde değişiklik yapılabilen ve güvenlik açısından da daha koruyucu etiketlerdir. Diğerlerinde ise bilgi üzerine bir kez yazılır, ürün dolaşıma çıkar ve kritik olmayan bilgi paylaşılır; bu bilgi genelde ürün kimliği, rengi, kodu gibi şeylerdir.

### 7.2 Pasif etiketin çalışması

Ekrandaki şekil pasif RFID etiketinin çalışmasını dört adımda gösteriyordu (ekrandan, 00:40:00):

1. RFID okuyucu etikete elektromanyetik bir sinyal yayar.
2. Etiketteki anten okuyucunun sinyalini alır ve yükü bir kondansatörde biriktirir.
3. Kondansatör yeterli enerjiyi biriktirdiğinde bunu zamanla etiketin bobinlerine bırakır.
4. Etiketin bobinleri, etiketteki bilgiyi içeren kodlanmış bir radyo dalgası yayar; okuyucu bunu demodüle eder.

## 8. RFID Frekans Bantları

### 8.1 Düşük frekans (LF)

Slayta göre LF etiketleri 125 kHz ile 134 kHz arasında çalışır ve pasif etiketlerdir (ekrandan, 00:40:00). Okuma mesafeleri en kısadır: metrenin üçte birinden az, yani yaklaşık 33 cm ve altı. Düşük frekansta veri aktarım hızı da düşüktür.

> **Ders sonrası not:** Hoca aralığı "125 GHz ile 134 GHz" diye söyledi; slayttaki doğru değer 125-134 kHz'dir.

Hocaya göre buradaki en büyük sıkıntılardan biri, bu frekanstaki etiketlerin çarpışmalara (collision) karşı kendilerini yeterince koruyamamasıdır. Bu yüzden çarpışmanın çok olabileceği durumlarda tercih edilmezler ve aynı anda çoklu okuma yapmak zordur.

Hocanın en ilginç bulduğu taraf, LF etiketlerin sıvı ortamların yakınında başarıyla çalışabilmesidir. Düşük frekansta veri hızı düşük olsa da dalga ortamdan çok etkilenmeden daha fazla yol kat edebilir.

### 8.2 Yüksek frekans (HF)

HF etiketleri 13.56 MHz'de çalışır ve bunlar da pasiftir; ama veri aktarım hızları LF'den daha iyidir. Slayta göre HF etiketler daha basit antenler sayesinde daha ucuz üretilir ve bu frekans için kısıtlama olmadığından en popüler etiketlerdir. En yüksek okuma mesafesi yaklaşık 1 metredir. Near Field Communication da bu frekansı kullanır. HF ve LF etiketleri lisans gerektirmeden dünya çapında kullanılabilir (ekrandan, 00:40:00, 00:45:00).

### 8.3 Ultra yüksek frekans (UHF)

Slayta göre UHF etiketleri 433 MHz ile 860-930 MHz aralığında çalışır. 433 MHz aktif etiketler için daha uygundur; 860-930 MHz penceresi daha çok pasif ve yarı pasif etiketler için kullanılır. UHF etiketleri çarpışma önleme (anti-collision) protokollerini destekler ve bu sayede aynı anda yüzlerce etiket okunabilir. Başarıyla okunabilmeleri için su ya da metal içeren maddelerden yalıtılmaları gerekir. Okuma mesafesi etiketin güç kaynağına bağlıdır ve aktif etiketlerde 30 metreye kadar çıkar (ekrandan, 00:45:00).

Hoca çarpışma önlemenin ciddi bir avantaj olduğunu, etiketlerin "birbirinin üzerine basmadığını" vurguladı ve UHF'nin nerelerde kullanılabileceğini sordu.

**Soru (hocanın):** UHF'nin kullanılabileceği uygulamalar neler olabilir?
**Cevap:** Bir öğrenci otoyol geçiş sistemlerinin (HGS) çok uygun bir örnek olduğunu söyledi; hoca bunu çok güzel bir örnek olarak kabul etti. Başka bir öğrenci deprem anında enkaz altında kalanlar ya da yakın mesafede iletişim kurması gerekenler için mesajlaşma uygulamalarını önerdi; hoca bu bandın telefonlar üzerinden atlamalı (multi-hop) haberleşmede kullanılabileceğini onayladı. Bir diğer öğrenci telefondan kullanılan telsiz uygulamalarını ve kamp gibi ortamları örnek verdi. Hoca bunun sensör ağlarını andırdığını, merkeze ulaşmadan uzak bir noktada haberleşmenin kritik olduğunu söyledi. Kamp bölgelerinde ve belli rotalarda baz istasyonu sorunu olduğundan trekking, kamp ve mağaracılık için akademik camiada geliştirilmiş ve uygulanmış çözümler vardır.

### 8.4 Mikrodalga

Mikrodalga etiketleri çoğunlukla 2.4 GHz, bazen de 5.8 GHz'de çalışır. Slayta göre yüksek frekans daha fazla enerji taşıyabildiği için okuma mesafesi ve veri hızı düşük frekanslı etiketlere göre çok daha yüksektir. Ortak sorun, mikrodalga ve UHF bantlarındaki radyo dalgalarının kolayca soğurulması, girişime uğraması ya da yansımasıdır. Ekipman maliyeti ve kullanım kısıtlamaları mikrodalga çözümlerinin nadiren kullanılmasına yol açar; bu tür ekipmanı az sayıda firma üretir (ekrandan, 00:45:00).

**Soru (hocanın):** Bu yüksek bantlarda sıkıntı nedir?
**Cevap:** Bir öğrenci mesafeyi, bir başkası yüksek enerji gereksinimini söyledi. Hoca çok uzun mesafelere gidilemediğini kabul etti, ama asıl sıkıntının hem UHF hem de mikrodalgada etraftaki nesnelerden çok etkilenme ve bundan dolayı sinyallerin bozulma olasılığı olduğunu söyledi.

Hoca bunu Bluetooth örneğiyle somutlaştırdı: evde bile sinyal gücüne bağlı olarak bir insan cihazın önüne geçtiğinde kopmalar yaşanabilir; araya bir duvar ve bir de insan girerse bağlantı gidip gelebilir. Bunlar yüksek frekanstaki haberleşmenin dezavantajlarıdır.

> **Hocanın vurgusu:** Mobil teknolojilerle yapılan uygulamalarda kullanılacak protokolün ve frekans bandının yapılacak işle doğrudan uyumlu olması gerekir. Dezavantajları iyi gözetilerek yatırım yapmak kritiktir.

## 9. RFID Spektrum Karşılaştırması ve Uygulamaları

### 9.1 Karşılaştırma tablosu

Aradan sonra hoca dört bandı karşılaştıran tabloyu açtı (ekrandan, 01:00:00):

| | LF (125-134 kHz) | HF (13.56 MHz) | UHF (433, 860-930 MHz) | Mikrodalga (2.4, 5.8 GHz) |
|---|---|---|---|---|
| Etiket maliyeti | Yüksek | Yüksek, orta | Orta | Yüksek |
| Okuyucu maliyeti | Düşük | Orta | Yüksek, orta | Yüksek |
| En yüksek menzil | ~30 cm | ~1 m | ~30 m (aktif) | 100 m'den fazla (aktifte 300 m'den fazla) |
| Veri hızı | Düşük | Orta | Yüksek | Yüksek |
| Girişim | Düşük | Düşük | Orta | Yüksek |
| Avantaj | Ortamda düşük soğurulma | Dünya çapında kullanılabilir | Orta menzilli uygulamalar için ideal | Geniş erişim menzili |
| Yaygın uygulamalar | Hayvan kimliği, güvenlik, motor immobilizer | Güvenlik, ürün takibi, biletleme | Konteyner, tır takibi | Erişim kontrolü, endüstri, üretim hatları |

Hoca LF ve mikrodalga etiketlerinin maliyetinin daha yüksek olduğuna dikkat çekti. Menzil 30 cm, 1 m, 30 m ve 100 m olarak, veri hızı da düşükten yükseğe doğru ilerler. Hoca bunun uzun mesafeli haberleşmede verinin bozulma olasılığının da arttığını gösterdiğini, bunun bilinen bir kural olduğunu söyledi.

### 9.2 Uygulama örnekleri

Hoca kullanım alanlarının önemli olduğunu söyleyerek tablonun son satırını tek tek tartıştı.

LF etiketler hayvan kimliği (Animal ID) olarak kullanılır. Özellikle Afrika'da ya da vahşi doğada sürülerin hareketlerini incelemek için hayvana etiket takılır; belgesel yapımcılarının bunu sık kullandığı biliniyor. Bir öğrenci nesli tükenmekte olan hayvanların takibinde de kullanıldığını ekledi. Hoca bu teknolojinin zooloji ve belgeselcilik alanında kullanıldığını söyledi.

**Soru (hocanın):** Engine immobilizer nedir?
**Cevap:** Bir öğrenci, motorların şasi numarası gibi bir numarası olduğunu ve bunun tanınmasında kullanılabileceğini tahmin etti. Hoca doğru yönde olduğunu söyleyip açıkladı: anahtar yuvaya girdiğinde çok kısa mesafedeki haberleşme noktasında immobilizer sistemi, anahtarın aracın şasi numarasıyla eşleşip eşleşmediğini kontrol eder. Başka bir anahtar yerleştirilmeye çalışılıyorsa araç kendini kilitler. Bu, uzun yıllardır kullanılan ve hırsızlığa karşı etkili bir yaklaşımdır; LF bandını kullanır. Bir öğrencinin anahtarsız çalıştırmanın da bu sistemle mi yapıldığı sorusuna hoca emin olmadığını, farklı sistemler olduğunu söyledi; bazı üreticilerin aracın uzaktan yetki devriyle, anahtar olmadan bir koda göre açılabileceğini duyurduğunu hatırlattı.

Ürün takibi (item tracking) hocaya göre en çok karşılaşılan uygulamalardan biridir. Bugün sipariş edilen bir ürünün hangi noktada olduğu takip edilebiliyor; ürün size gelene kadar farklı aktarma merkezlerine giriş-çıkış yapıyor ve bu bilgi artık elle değil otomatik giriliyor. Ama bunların çoğunda RFID değil QR kod kullanılıyor. Daha profesyonel ve büyük ölçekli firmalar transferlerini RFID ile yapıyor. Konteyner ve tır takibi özellikle deniz taşımacılığında önemlidir: büyük limanlarda konteynerlar gemiye yüklenirken ve indirilirken onlara takılan UHF etiketler üzerinden işler yürür.

**Soru (hocanın):** Mikrodalga bandında erişim kontrolü, endüstri ve üretim hatları görüyorsunuz. Bandın özellikleriyle bu kullanım alanlarını nasıl ilişkilendirirsiniz?
**Cevap:** Bir öğrenci Wi-Fi'ın buna girip girmediğini sordu; hoca girmediğini söyledi. Başka bir öğrenci 2.4 GHz ve 5 GHz'in herkese açık frekanslar olduğunu, Wi-Fi ve Bluetooth'un da 2.4'ü kullandığını, endüstrideki farklı standartlarda da bu frekansların kullanılabildiğini anlattı; raylı sistemlerin kendi içindeki iletişiminde 5 GHz bandının kullanıldığını duyduğunu ekledi. Hoca, endüstride yüksek yoğunlukta veri aktarımı gerektiğini ve büyük fabrika mesafeleri düşünüldüğünde bu bandın akıllıca bir seçim olduğunu söyledi. Seri üretim hatlarında verinin çok hızlı alınıp aktarılması gerektiği için mikrodalga bandı kullanılır; ağırlıklı olarak 2.4 ve 5 GHz geçse de son dönemde 5.8 GHz'in de yaygınlaştığını belirtti.

### 9.3 Diğer uygulama alanları

Uygulamalar tablosunda (ekrandan, 01:20:00) belge yönetimi (ofis ve hastanelerde belge takibi), ulaşım yönetimi (tır ve konteyner takibi, demiryolu, hız takibi, anahtarsız çalıştırma ve motor immobilizer sistemleri), biletleme (toplu taşıma, metro, havayolu biletleri, kayak pasosu), yaban hayatı ve evcil hayvan takibi ve bagaj takibi (havalimanları ve diğer aktarma istasyonları) yer alıyordu. Hoca ayrıca temassız ödeme, spor, sağlık ve üreticilerin ürün taşıma ve takibini saydı. Bagaj takibinde son dönemde bagaja yerleştirilen QR kodlarla takip yapıldığını, valizin yanlış yöne gitmemesi için okuyucular yerleştirildiğini söyledi.

## 10. RFID'nin Avantajları ve Dezavantajları

### 10.1 Avantajlar

Slaytta RFID'nin avantajları şöyle sıralanmıştı (ekrandan, 01:20:00): yeniden yazılabilme, görüş hattına gerek olmaması, okuma mesafesinin artması, daha fazla veri saklama, çoklu etiket okuma, RFID etiketlerinin okunabilmesi, çalışma ortamı, akıllı davranış ve yüksek güvenlik.

Hoca bunları şöyle açıkladı. Aktif etiketler yeniden yazılabilir ve görüş hattı ihtiyaçları yoktur. QR kodda belli bir mesafeden sonrasını okuma şansı yoktur; zaten küçük basıldığı için kamera bazen yeterince net okuyamaz. RFID'de böyle bir sorun olmadığı için verim doğal olarak artar. QR kodda veri ancak bir yere kadar depolanabilir; aktif RFID'de bu daha da iyidir. Birden fazla etiket aynı anda okunabilir.

Çalışma ortamı hocanın ilginç bulduğu bir maddedir: bir QR kodu suyun altında ya da toprak altında rahatlıkla çözemezsiniz; RFID'de ise havanın dışında da belirli koşullar sağlandığında veri aktarılabilir. Belli oranda programlama yapma şansı vardır; özellikle aktif etiketlerle bazı işlemler yapılabilir. Son olarak güvenlik: QR kod ortadadır, RFID'de böyle bir açıkta olma durumu yoktur.

### 10.2 Dezavantajlar

- Maliyet: QR kodun maliyeti çok düşüktür ve bu yüzden çok yaygındır. RFID'nin maliyeti belli bir noktaya gelmiş ama altına inememiştir; hocaya göre rekabet koşulları eşit değildir ve bu her zaman bir dezavantaj olarak kalacak gibi görünüyor.
- Yatırımın geri dönüşü: Uzun vadeli yatırım yapılıyorsa RFID akıllıca olabilir; uzun vadeli düşünülmüyorsa en hızlı çözüm QR koddur. Uzun vadede RFID altyapının daha sağlıklı yürütülmesini sağlar.
- Elektromanyetik alanlara duyarlılık: QR kodda nasıl görüş hattı sorunu varsa, RFID'de de elektromanyetik etkilere duyarlılık vardır. Hoca, ciddi elektromanyetik alan oluşan metroda RFID'nin nerede kullanıldığını merak ettiğini söyledi. Bir öğrenci, sürücüsüz metro hatlarında istasyonlardaki raylarda bulunan sarı kare işaretlerin RFID benzeri bir teknolojiyle çalıştığını ve aracın duracağı yeri bunlara göre belirlediğini anlattı. Hoca otonom hatlarda böyle bir yapının gerekli olduğunu, otonom araçların konumlamayı tam yapamadığında bir tık daha ilerleyerek kendini ayarlamasının genel bir refleks olduğunu, robotlarda ve otomatik asansörlerde de bu mantığın bulunduğunu söyledi.
- Güven eksikliği (lack of trust): Bu, QR kodla karşılaştırmadan bağımsız olarak RFID'nin genel bir dezavantajıdır. Bilgi taşıdığı için saldırılara açıktır; ne kadar güvenli olsa da kişisel bilgiler her zaman tehlikededir.
- Barkod uygulamalarının çok daha yaygın, RFID'nin daha az kullanılıyor olması ve RFID'de açık standartların henüz yaygınlaşmamış olması. Hocaya göre 2020'li yıllar RFID'nin hayatımıza daha çok nüfuz ettiği bir dönem olacak.

Hoca son slayttaki barkod, QR kod ve RFID'yi başka metriklerle karşılaştıran tabloyu göstermeden geçti.

## 11. Yeni Nesil Araçlar ve SAE Otomasyon Seviyeleri

### 11.1 Giriş

Hoca "next generation" ifadesinin çok kullanıldığını, bir jenerasyon sonraki araçların nasıl olacağına, problemlerin neler olduğuna, araçların neden hâlâ yollarda olmadığına ve hangilerinin yolda olduğuna bakacaklarını söyledi.

### 11.2 SAE seviyeleri

Society of Automotive Engineers temelde 5 seviye belirlemiştir; otomasyonun olmadığı seviye 0 olarak sayıldığında 6 seviye olur (ekrandan, 01:30:00).

> **Hocanın vurgusu:** Bu bir endüstri standardıdır ve akademik makalelerde bu standardın takip edilmesi beklenir.

| Seviye | Ad | Slayttaki tanım (özet) |
|---|---|---|
| 0 | No Automation | Otonomi yok; bütün sürüş görevlerini sürücü yapar. |
| 1 | Driver Assistance | Araç sürücü tarafından kontrol edilir; araç tasarımında bazı sürüş destek özellikleri bulunabilir. |
| 2 | Partial Automation | Araçta hızlanma ve direksiyon gibi birleşik otomatik fonksiyonlar vardır; sürücü sürüşe dahil kalmalı ve ortamı her an izlemelidir. |
| 3 | Conditional Automation | Sürücü gereklidir ama ortamı izlemesi gerekmez; bildirimle her an kontrolü almaya hazır olmalıdır. |
| 4 | High Automation | Araç belirli koşullarda bütün sürüş fonksiyonlarını yapabilir; sürücü isterse kontrolü alabilir. |
| 5 | Full Automation | Araç her koşulda bütün sürüş fonksiyonlarını yapabilir; sürücü isterse kontrolü alabilir. |

### 11.3 Seviye 1: Sürücü desteği

Seviye 1'de araç sürücü tarafından kullanılır, ama sürücünün konforunu artıracak ya da aracın enerji tüketimini en iyi hale getirecek bazı özellikler otomatik olarak gerçekleşir. Hoca örnek istedi; öğrenciler yol tutuş desteğini (virajlarda hayat kurtardığını), şerit takibini ve ani frenleme sistemini saydı. Bir öğrencinin yakıt-oksijen oranının ayarlanmasını sorması üzerine hoca bunun motorun verimli çalışması için teknolojik bir destek olduğunu, ama sürücüye doğrudan destek olmadığı için burada konuşulan Advanced Driver Assistance Systems (ADAS) kapsamına girmediğini söyledi.

ADAS'ın klasik örneği Cruise Control, yani hız sabitleyicidir. Hoca bunun özellikle geniş ve düz yollara sahip ülkelerde yalnız konfor değil hayat kurtarma açısından da önemli olduğunu anlattı: çok uzun yollarda dikkat belli bir süre sonra dağılır ve ayaklarda uyuşma olabilir. Hız sabitlendiğinde ayaklar hareket ettirilebilir ve bu uzun yolda sağlık açısından önemli bir konfor sağlar. Yorgunluk takibi ve park desteği de seviye 1 kapsamında sayıldı.

### 11.4 Seviye 2: Kısmi otomasyon

Öndeki araca belli bir mesafeden fazla yaklaşıldığında hızı düşürme yönünde tepki veren bir sistem varsa, bu kısmi otomasyondur: sürücü dışında aracın gidişatını kontrol eden bir yapı söz konusudur. Hoca, endüstri standardına göre bu özelliklerden bir tane bile olsa aracın seviye 2 olarak adlandırıldığını söyledi.

Bir öğrenci yokuş kalkış desteğinin de bu kapsama girip girmediğini sordu. Hoca girebileceğini, çünkü sürüşe otomatik olarak katkı sağlayan ve kazayı önleyen bir çözüm olduğunu söyledi. Aracı şeritte tutmak (lane keeping) da aracı seviye 1'den seviye 2'ye taşır.

Hoca ayrımı şöyle özetledi: sürücü destek sistemleri daha temel, daha az müdahale gerektiren ve alınan verinin yorumlanmasını pek içermeyen çözümlerdir. Kısmi otomasyon ise veriyi sürekli alıp onunla belirli bir iş yapan çözümlerdir.

**Soru:** Virajlarda farın yönünü otomatik değiştiren sistem bu seviyeye girer mi?
**Cevap:** Hocaya göre bu daha çok sürücü destek sistemidir; yalnız far kontrol ediliyor, küçük bir destek var. Ama seviye 1 ile 2 arasındaki çizgi incedir. Bir öğrencinin karşıdan araç gelince uzunları otomatik kapatan sistem örneği de konuşuldu. Hoca kilit noktanın slayttaki "combined automated functions" ifadesi olduğunu, seviye 2'de birden fazla fonksiyonun bir arada sunulduğunu söyledi.

### 11.5 Seviye 3: Koşullu otomasyon

Seviye 3'te geçiş yavaş yavaş başlar. Sürücünün başında olması beklenir ama araç genel olarak etrafı gözlemleyerek kontrolü sürdürür. Bir öğrenci, direksiyon bırakıldığında aracın kendi kendine park ettiği otomatik park sisteminin buraya girdiğini söyledi; hoca onayladı. Hoca okuduğu birkaç makaleye göre otomatik park sistemlerinin alanları daha verimli kullanacağını, küçük alanlara da girebilen araçlarla bir alana daha fazla aracın yerleştirilebileceğini aktardı.

Hoca görüş açısının önemine değinerek otonom araçlarda kameraların nereye yerleştirildiğini sordu. Öğrenciler bazı araçlarda kameraların her yöne (sağ ön, sol ön, arka) konduğunu, park desteği olan araçlarda yan aynaların altına, öne ve arkaya konarak yukarıdan bakış görüntüsü oluşturulduğunu, bazılarında aracın tepesinde bir kamera bulunduğunu söyledi. Hoca ilk başta tavanda 360 derecelik tek bir kamera kullanıldığını, ama tek kameranın ya da yukarıdaki iki kameranın işi çözmediğinin görüldüğünü, kamera sayısının arttığını ve bunların koordineli izlenmesi gerektiğini anlattı.

### 11.6 Seviye 4 ve 5

Seviye 4'te araç belirli koşullarda bütün sürüşü yapabilir. Hoca metrobüs hattını örnek verdi: o hatta girildiğinde araç kendi gider, ama acil bir durumda araç "kontrolü devral" dediğinde sürücü alabilmelidir. Bir öğrenci bunun uçaklardaki otopilota benzediğini söyledi. Hoca güzel bir benzetme olduğunu, uçaklarda rotalar tarif edildiği ve katı kurallar uygulandığı için yüksek otomasyonun daha rahat gerçekleştiğini söyledi. Karada ise ayrılmış hatlar gerekir; şehirlerarası otoyollar da "belirli koşullar" kapsamında değerlendirilebilir. Ama şehir içi trafikte bu koşulları sağlamak kolay değildir. Belirli koşullar; çizgilerin çizildiği, belirli yol altyapılarının yerleştirildiği bölgeler de olabilir.

Seviye 5 tam otomasyondur: bütün koşullarda kontrol araca bırakılır, araç evden işe "anahtar teslim" gider. İddiaya göre 2030'lara kadar bu araçlar belli miktarda yollarda görülecek. Hoca, kişi değil ürün taşıyan ve ürünü evin otoparkına kadar getirip ödemeyi araca yaptıran otonom teslimat araçlarının 2020'de başladığını, ileride drone versiyonlarının ve evlerde drone iniş alanlarının konuşulacağını söyledi.

## 12. Araç Zekası İçin İzlenmesi Gereken Bağlamlar

### 12.1 Bağlam grupları

Hoca araç zekası (vehicle intelligence) denince takip edilmesi gereken çok fazla ortam olduğunu söyledi: sürücü, dış ortam (kar, yağmur, yayalar, hayvanlar), yol altyapısı (çukur, tümsek, mıcırlı ya da kaygan yol), trafik göstergeleri ve hava. Sürüş tarafında hız, şerit, şerit değiştirme, sola-sağa dönüş, hızlanma ve yavaşlama kaydedilmelidir ki aracın sürüş performansı değerlendirilebilsin ya da araç bundan öğrenebilsin. Aracın mekanik kısımları da izlenmelidir: motorun fazla ısınması, devrin çok yükselmesi, kapı kilitlenmesi, aracın çalıştırılması. Hoca sürüş anı ile sürüş dışı kısmı ayırdı ve derste daha çok sürüş anıyla ilgilendiklerini söyledi.

Önceki slaytta bu bağlamlar bir ağaç diyagramında gruplanmıştı; görünen kısımda L1-L2 ve L4-L5 başlıkları altında uykulu göz tespiti, yüksek devir, motor aşırı ısınması, kapı kilitleme, tekerlek hızı, OBD kodları (güç aktarma P, gövde B, şasi C, ağ N), enerji ve yakıt tüketimi, araç çalıştırma ile yanal sürüş altında dönüş, sağ/sol dönüş, keskin dönüş, U dönüşü, sollama ve boylamsal sürüş altında hızlanma, ani hızlanma, aşırı ve düşük hız kutuları vardı (ekrandan, 01:45:00).

Sonraki slaytta bağlamlar liste halinde verildi (ekrandan, 01:45:00): sürücü durumu, dikkat dağıtıcı aktiviteler, boylamsal sürüş, yanal sürüş, hatalı sürüş, yaya, yol durumu, hava, trafik göstergeleri, araç içi, araç arızaları.

### 12.2 Sürücü durumu

**Soru (hocanın):** Driver status denince aklınıza ne geliyor?
**Cevap:** Bir öğrenci sürücünün var ya da yok bilgisinin bile bir sürücü durumu olabileceğini söyledi. Hoca bunun seviye 5'in altındaki durumlar için gerçekten kritik olduğunu kabul etti. Bunun ötesinde sürücünün yorgunluk düzeyi, esnemesi, aynaları kontrol etmesi, göz kırpma miktarı, göz açıklığı, oksijen seviyesi ve nabzı (nabız düşerse uykuya gidiş başlar) toplanmalıdır. Bu bilgilerle sürücünün kendisi ya da riskli bir sürücü geliyorsa karşı taraf uyarılabilir.

### 12.3 Dikkat dağıtıcı aktiviteler

Telefon kullanımı, sigara içilmesi, araç içindeki yüksek ses ve konuşmalar dikkat dağıtıcı aktivitelerdir. Bunlar otonom aracı etkilemez, ama seviye 4'e kadar sürücüyü etkilediği için sistemi de etkiler. Araç telefon kullanımını otomatik tespit edip direksiyondaki kullanıcıyı uyarabilir.

> **Hocanın vurgusu:** Yeni nesil araçları konuşsak da yollarda eski nesil araçlar kalacak. Bu yüzden eski araçları da akıllı hale getirmek, onlarda bu aktiviteleri takip etmek ve hem araçtaki sürücüyü hem karşı tarafı uyarmak kritik hale geliyor.

### 12.4 Boylamsal ve yanal sürüş

Trafik ışığına yaklaşma, yüksek hızda seyretme, ani fren, ani hızlanma ve şerit değiştirme gibi sürüş durumlarının kaydedilmesi, otonom aracın ne kadar konforlu ve ne kadar güvenli sürüş yaptığını anlamayı sağlar. Boylamsal (longitudinal) ve yanal (lateral) hareketlerin takibi hem otonom hem eski tip araçlar için büyük önem taşır. Hoca, sigorta şirketlerinin bu amaçla cep telefonu uygulamaları kullandığını ve sürüş riskini ölçerek kişiye uygun seçenekler sunabildiğini söyledi.

### 12.5 Hatalı sürüş

**Soru (hocanın):** Incorrect driving'e ne örnek verilebilir?
**Cevap:** Bir öğrenci ters şeritten gitmeyi söyledi. Hoca onaylayıp otoyola ters girenleri ve trafikte emniyet şeridinden geri geri gelmeye çalışanları ekledi. Ayrıca çarpma, uygun olmayan yerden dönme, park edilmemesi gereken yere park etme, bir araca gereğinden fazla yaklaşma, aşırı hız ve otoyolda çok düşük hız da hatalı sürüştür. Bunlar sürücünün puanlamasını etkileyen hareketlerdir; geliştirilme aşamasındaki otonom araçların bu tür hareketleri de kayıt altına alınıp incelenir.

### 12.6 Yaya

Bir öğrenci, hem hatalı sürüşü hem yayayı kapsayan bir uygulama olarak bazı yaya geçitlerinde yayaya yol vermeyen sürücülere kamerayla otomatik ceza kesildiğini anlattı. Hoca bunu güzel bir akıllı ulaşım (smart transportation) örneği olarak kabul etti. Araç açısından yayayı, canlıyı algılamak ve yaya geçidinde olup olmadığını anlamak gerekir. Ama mesele "geçitteyse dokunmam, değilse devam ederim" değildir: yayanın yolun neresinde olduğu ve hızın azaltılması gerektiği dikkate alınmalıdır. Hocaya göre uzun vadede yanlış yerden geçen yayaya ya da durmayan araca otomatik ceza kesilecektir.

### 12.7 Yol durumu, hava ve trafik göstergeleri

Yol durumu (çukur, tümsek, kaygan yol, çakıl ve çöplerle dolu yol) otonom aracın sürüşünü etkiler; çukura girip çıkmak aracın eskimesini de etkiler. Bir öğrenci yol çalışmalarında işaretlerin olmadığı ve yeni yolun keşfedilmesi gereken durumları anlattı. Hoca, işaretlerin net olmadığı yol bakım çalışmalarının otonom araçların en büyük zorluklarından biri olduğunu, yolun aniden 3 şeritten 2 şeride inebildiğini söyledi.

Havanın sisli, rüzgarlı, yağışlı olması, kar ve soğuk seviyesi algılanmalıdır. Bu bilgi meteorolojiden alınabilir, ama yolun kayganlığı açısından o bölgedeki gerçek bilgi daha kritiktir: hava tahmininden beslenemezsiniz, yol altyapısındaki sensörlere dayanmanız gerekir. Trafik sinyallerini takip etmek de durma ve kalkma açısından çok kritiktir.

### 12.8 Araç içi ve araç arızaları

**Soru (hocanın):** Vehicle interior denince ne olabilir?
**Cevap:** Bir öğrenci klimanın yönetimini önerdi. Hoca klimanın olabileceğini, ama güvenliği doğrudan etkileyen bir şey sordu; başka bir öğrenci emniyet kemeri takılmadığında verilen uyarıyı söyledi. Hoca onayladı. Araçta bebek olduğunu gösteren işaretin ileride otomatik algılanması, radyonun açık olup olmadığı ve içeride kaç yolcu olduğu da araç içi bağlamlardır. Hoca, içerideki yolcu sayısının depremde evde kaç kişi olduğunun bilinmesine benzediğini ve bu verilerin kişisel verilerin korunması kapsamında nasıl saklanacağına dair, afet durumları gibi istisnalar için düzenlemelere ihtiyaç olduğunu söyledi.

Araç arızaları (vehicle troubles) tarafında yağ seviyesinin düşmesi, motorun aşırı ısınması gibi CAN-BUS üzerinden alınabilecek bilgiler baştan takip edilmelidir.

**Soru:** Otonom araçlarda bir sensör bozulduğunda nasıl bir çözüm olacak?
**Cevap:** Hoca bunun regülasyonla ilgili olduğunu, büyük olasılıkla hata veren noktalar için kritiklik seviyeleri tanımlanacağını ve buna göre kurallar konacağını söyledi; örneğin lastik basıncı belli bir seviyenin altına inerse aracın doğrudan servise ya da benzinliğe gitmesi gibi. Hoca, uçak teknolojisinin geldiği noktada bile pilotsuz bir uçağa kimsenin binmeyeceğini düşündüğünü söyledi. Bir öğrenci, otomatik pilotla ilgili sorunlar yüzünden uzun süre yerde kalan bir uçak modelinin insanların güvenini sarstığını hatırlattı. Hoca, insanların bugün sürücüsüz olarak yalnız rotaları ve koşulları çok net tanımlanmış tren ve metrolara bindiğini, otonom araçların mutlaka geleceğini ama 2030'larda çok yaygınlaşmasının kolay olmayabileceğini söyledi.

## 13. ADAS'ın Tarihçesi ve Amaçları

### 13.1 Zaman çizelgesi

Ekrandaki zaman çizelgesi (ekrandan, 02:20:00) ve hocanın anlatımı şu kilometre taşlarını veriyordu:

- 1885: ilk mekanik araç. 1910: hız göstergesi. 1914: aynalar. Hoca yaklaşık 30 yıl aynasız kullanım olduğunu ve 100 yıl sonra hâlâ eski tip araçlar görülebildiğini söyledi.
- 1948: hız sabitleyici (cruise control). 1951: hava yastığı. 1958: otomatik fren sistemi.
- 1981: navigasyon sistemi. 1983: yol tutuş (electronic stability control). 1986: lastik basıncı izleme.
- 1992: uyarlanabilir hız sabitleyici (adaptive cruise control). 1995: çarpışma önleme. Hoca çarpışma önlemenin neredeyse 30 yıllık olduğu halde çevresinde pek görmediğini söyledi.
- 1999: park yardımı. 2000: yaya tespiti.
- 2000'lerin başı: gece görüşü, akıllı hız uyarlaması, şeritten ayrılma uyarısı. <!-- BELİRSİZ: Çizelgede 2001 ve 2002 noktalarının hangi özelliğe ait olduğu karede kesin ayrılamıyor; hoca akıllı hız uyarlaması için 2002 dedi. -->
- 2006: akıllı far yardımı ve sürücü uykululuk tespiti. Hoca uykulu halin tespitinin neredeyse 15 yıl önce çözüldüğünü ama araçların büyük çoğunluğunda hâlâ olmadığını söyledi.
- 2007 civarı: kör nokta tespiti ve otonom sürüş kavramı.
- 2015: otomatik park. 2017: araçtan araca iletişim (vehicle-to-vehicle).
- 2031: tam otonom sürüş hedefi.

Hoca, araçtan araca iletişimin (VANET, vehicular ad-hoc networks) otonom araçların ve "connected car" kavramının en kritik noktası olduğunu, bunun için IEEE 802.11p'nin kullanılacağını ve 2020'lerde yaygınlaşmasının şaşırtıcı olmayacağını söyledi. Bu çizelge, teknolojinin dünyada çıkışı ile bize gelişi arasındaki farkı da gösteriyordu.

### 13.2 ADAS'ın amaçları

Slayttaki şemada ADAS'ın amaçları üç grupta toplanmıştı (ekrandan, 02:25:00):

- Güvenlik: trafik kazalarının azaltılması, yaşlı ve acemi sürücülere yardım, araç durumunun sağlıklı tutulması.
- Verimlilik: enerji tüketiminin azaltılması, iyi trafik yönetimi, gaz emisyonunun azaltılması.
- Konfor: sürüş sırasında daha az yorgunluk, yolcu mutluluğu.

Hoca, kullanım kolaylığı getiren ve hayatı değiştiren bir ADAS örneği olarak otomatik vitesi verdi: büyük bir konfor farkı sağlar ve yakıt tüketimini daha iyi yönetir. Klimatize ortam ve dışarıdaki toz bulutunun içeri alınmaması da araç içi durumun yönetimine örnektir. Trafik yönetimi tarafında, bütün araçlar akıllı olursa sürekli şerit değiştirmeler daha kontrollü olacağı için yolculuklar kısalabilir; trafiği oluşturan en büyük sebeplerden biri sürekli sağdan sola geçen araçlardır. Gaz emisyonu hem elektrikli araçlar hem otonom araçlar sayesinde düşecektir. Konfor tarafında daha az hızlanma-yavaşlama ve araç içindeki eğlence sistemleri öne çıkar; hoca ileride aracın nasıl sürdüğünü hiç düşünmeyip içerideki film, gazete ya da kahveyi düşüneceğimizi söyledi.

### 13.3 Kazaların kaynağı ve ADAS uygulamaları

Hoca bir tabloya göre kazaların kaynağının %94 oranında insan olduğunu, bunun bütün istatistiklerde görüldüğünü söyledi. <!-- BELİRSİZ: Bu tablonun karesi yok; oran altyazıdan alındı. --> İnsan kaynaklı kazalar otomatik sistemlerle çok azaltılabilir; ama özellikle gelişmekte olan ülkelerde hâlâ büyük sorun vardır.

> **Hocanın vurgusu:** Otonom araçların sayısını artırmak önemli, ama bu hemen olmayacağı için ADAS'ların mevcut araçlara, üretim bandında eklenmediyse bile sonradan eklenmesi ayrıca çalışılması gereken bir konudur.

Bilinen ADAS uygulamaları şunlardır: uyku ve dalgınlık tespiti, trafik ışıklarının tespiti ve sürücünün uyarılması ya da aracın durdurulması, navigasyon desteğiyle uyarı, sürücünün izlenip kalp krizi gibi rahatsızlıkların tespit edilmesi, şerit tespiti, yaya tespiti, çarpışma önleme ve yol durumu tespiti. Hoca bu uygulamaları bir robotun gözü, kulağı ve ayağına benzetti: hepsi var, ama koordineli hareket etmeleri isteniyor. Bu yüzden yeni nesil araçlarda sıfırdan tasarım yerine mevcut ADAS'ları entegre edecek bir mimari kurmak gerekir; böylece üzerinde çalışılmış problemler sisteme eklenebilir ve adımlar daha hızlı atılabilir.

## 14. Araç Zekası Mimarisi ve Sensörler

### 14.1 Araç zekası mimarisi

Hoca kendi araştırma grubunun bir çalışmasında önerdikleri mimariyi gösterdi (ekrandan, 02:30:00). Mimari üç katmanlıdır:

- En altta veri kaynakları: sensörler (konum, jiroskop, LIDAR, ivmeölçer, görsel), VANET (diğer araçlardan gelen bilgiler) ve büyük veri (bulutta bir havuza aktarılan, örneğin bir konumda çukur olduğu bilgisi).
- Ortada araç zekası servisleri ve modülleri: konfor (sesli asistan, hız sabitleyici, otomatik klima, iç hava filtresi), eğlence (müzik akışı, mesajlaşma, internet erişimi), sürüş (navigasyon, uykululuk tespiti, trafik işareti tespiti, yol durumu tespiti, yaya tespiti, sürücü izleme, çarpışma öncesi sistemler, şerit tespiti) ve güvenlik (dijital veri yolu güvenliği, hırsızlık önleme, mahremiyet koruma sistemleri).
- En üstte bağlam füzyonu: yürüyen yaya, frenleme, çukur, park, şerit/dönüş, vites, yağmurlu hava, uykulu göz, esneme, araç çalıştırma, sağ-sol dönüş, hız sınırı işareti gibi bağlamlar.

Hoca bu üç kaynak birlikte kullanıldığında otonom araçların hayata bağlandığını, bu yüzden bulut bilişimin otonom araçlar için çok kritik olduğunu söyledi. Ama "connected car" olunca bir güvenlik zafiyeti de ortaya çıkar. Merkezde sürüş vardır ve çözülmesi gereken temel problem odur; eğlence, konfor ve güvenlik ise ayrı servislerle adreslenmelidir. Bunlar araç zekasının içine gömülebilirse yeni nesil araçlar yalnız sürüş problemini değil kullanıcının konforunu, mutluluğunu ve veri güvenliğini de sağlayabilir.

### 14.2 Otonom aracın sensörleri

Hoca bir makaleden aldığı sistem şemasını gösterdi. Bir otonom araçta LIDAR, uzun menzilli radar, kamera, kızılötesi ve kısa menzilli radar bulunur. Şemada sensörler şerit değiştirme uyarısı, kısa menzilli nesne tespiti, trafik görüntüsü oluşturma, ön ve arka tamponda çarpışma önleme, çarpışma önleme ve acil fren gibi işlevlerle ilişkilendirilmişti (ekrandan, 02:35:00).

> **Hocanın vurgusu:** Mesafe uzadıkça görüş alanı (field of view) küçülür. En uzağa giden uzun menzilli radarın görüş alanı dardır. Sensörlerden gelen veriler birleştirilirken ve karar verilirken bu görüş alanları hesaba katılmalıdır.

Hoca bunun daha önce sensör ağlarında, özellikle yönlü algılamada (directional sensing) konuşulan kapsama konusuna benzediğini söyledi. Aynı anda birçok kaynaktan görüntü işlemek ayrı bir zorluktur; diğer kaynaklardan da bilgi gelir ve karar anında hangisinin öncelikli olacağına, hangisinin diğerini geçersiz kılacağına karar vermek gerekir.

## 15. Açık Konular ve Otonom Araçların Henüz Yolda Olmamasının Nedenleri

### 15.1 Açık konular

Slayttaki açık konular şunlardı (ekrandan, 02:35:00):

- Çekirdek tasarım (core design): Şu anda herkes kendi tasarımını oluşturuyor, deniyor, yanılıyor. Hocaya göre ileride bugünkü mekanik araçlarda olduğu gibi otonom araçlar için de ortak bir çekirdek tasarım oluşacak.
- Bulut servisleri: Araç bulutla nasıl haberleşecek, hangi verileri alacak, iletişim ne sıklıkla ya da sürekli mi olacak, gelen verinin manipüle edilmediği nasıl kontrol edilecek? 5G burada çok önemlidir.
- Hesaplama darboğazı: Bütün veriler işlenip derin öğrenmede kullanılacaksa araca özel bir donanım mekanizması tasarlanması gerekebilir. Hocaya göre bu, bir bilgisayara CPU ve GPU koymak gibi olmayacak.
- Veri toplama: Hangi noktalardan, hangi sensörlerle veri akacağı netleşmelidir; bir kısmı netleşti, belli sensörler kesinlikle olacak.
- Yol altyapısı: Yol kenarındaki bilgi sağlayıcıların araca hangi bilgileri hangi sıklıkla aktaracağı önemlidir. Araç geçerken yalnız belli başlı bilgileri almalı, çok fazla bilgiye maruz kalmamalıdır. Bu bilgi önden giden aracın bıraktığı ya da ileriden gelen aracın gönderdiği bir bilgi de olabilir.
- Simülasyon: Gerçek hayatta test etmek risklidir; bilgisayarda en kötü ihtimalle donanım bozulur, ama gerçek hayatta ölümlü kazalar olabilir. Bu yüzden hoca yolların modellenip otonom araç davranışlarının izlendiği daha yaygın ve detaylı simülatörlerin olacağını düşünüyor.

### 15.2 Otonom araçlar neden hâlâ yolda değil?

Slayttaki beş neden şunlardı (ekrandan, 02:45:00):

- Sensörler: Sensörlerin veri güvenilirliğiyle ilgili hâlâ sorunlar var; hatalı veri üretme ve bozulma durumları. Uçaklardaki gibi yedekli (redundant) sensörler kullanılmalı ve üretilen veriler sürekli birbiriyle kontrol edilmelidir. Bu kısım hem sensör çeşitliliği hem güvenilirlik açısından oturmuş değildir.
- Makine öğrenmesi: Birçok çözüm konuşulsa da kabul görmüş bir yol haritası yok; herkesin kendi kapalı kutu çözümleri var. Hocaya göre belirli bir referans çizgi (baseline) belirlenmesi gerekiyor ve bu özellikle akademinin işi.
- Açık yol: Hoca, bu araçlar öğrenmeye devam ettiği için "araca bunu yükledim, artık bunu kullansın" denemeyeceğini ekledi. Ortam dinamik olduğu ve araç yeni yerlere gittiği için öğrenme sürmelidir. Eski öğrendiğini unutacak mı, yeni öğrendiğini onun üzerine nasıl katacak? Bu hâlâ bir problemdir.
- Regülasyon: Verilerin neler olacağı ve nasıl aktarılacağı tanımlanmalı. Bir kaza olduğunda kimin suçlu olacağı (yazılım firması mı, aracı yapan mı, sürücü mü) henüz oturmadı.
- Toplumsal kabul: Hoca, derste "binmeyiz" cevabının alındığını hatırlattı. Hocaya göre otonom araçlarla seyahat önce çok güvenli ortamlarda ve düşük hızlarda, eğlence amaçlı turlarla başlayacak, insan güveni yavaş yavaş kazanılacak. Bir öğrenci, bazı araçların otoparktan ya da garajdan çıkıp düşük hızda sahibinin yanına gelebildiğini örnek verdi; hoca ilk öğrenen araçların gidip durarak hareket ettiği videoları hatırlattı.

> **Ek bilgi (derste anlatılmadı):** Hocanın "eski öğrendiğini unutma" diye tarif ettiği sorun, literatürde "felaket unutma" (catastrophic forgetting) olarak bilinir. Yeni veriyle eğitilen bir modelin önceki görevlerdeki başarısını kaybetmesidir; bunu çözmeye çalışan alana sürekli öğrenme (continual learning) denir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:13): QR kodun RFID etiketlerine göre avantaj ve dezavantajları nelerdir?

> **Cevap (derste verildi):** Dezavantajlar: görüş hattı ve doğru açı gerekir; veri arttıkça yüksek çözünürlüklü görüntü ve kaliteli okuyucu gerekir; baskı kalitesine bağlıdır ve yırtılma, silinme, yağmur gibi fiziksel etkilerle bozulur; aynı anda çok sayıda ürün okumak zordur; güvenlik amaçlı kullanımda yenilenmesi gerekebilir. Avantajlar: maliyeti çok düşüktür, veri doğrudan dijital olarak alınır, yaygın ve standartlaşmıştır.

**Soru 2** (derste sözlü, 00:38:14): Pasif ve aktif RFID etiketleri nerelerde kullanılır?

> **Cevap (derste verildi):** Pasif etiketler daha çok kıyafet ve tekstil ürünlerinde, kimlik, renk, kod gibi kritik olmayan bilginin bir kez yazılıp paylaşıldığı yerlerde kullanılır. Aktif etiketler üzerinde değişiklik yapılabildiği ve güvenlik açısından daha koruyucu olduğu için, örneğin ortak bir yetkilendirme sunucusuna bağlı ve şifresi dinamik olarak değişen kapılarda kullanılabilir.

**Soru 3** (derste sözlü, 00:42:23): UHF bandındaki RFID'ler hangi uygulamalarda kullanılabilir?

> **Cevap (derste verildi):** Otoyol geçiş sistemleri (HGS), konteyner ve tır takibi, deprem anında ya da baz istasyonu olmayan kamp ve doğa ortamlarında telefonlar arası atlamalı haberleşme. UHF'nin çarpışma önleme protokolleri aynı anda çok sayıda etiketin okunmasını sağlar; aktif etiketlerde menzil 30 m'ye kadar çıkar.

**Soru 4** (derste sözlü, 00:44:43): Mikrodalga (2.4 / 5.8 GHz) RFID'de veri hızı çok yüksektir. Buradaki temel sıkıntı nedir?

> **Cevap (derste verildi):** Öğrenciler mesafeyi ve enerji ihtiyacını söyledi. Hocaya göre asıl sıkıntı, UHF ve mikrodalga dalgalarının etraftaki nesnelerden çok etkilenmesi; kolayca soğurulmaları, girişime uğramaları ve yansımaları nedeniyle sinyalin bozulma olasılığıdır. Bluetooth'ta araya bir insan girince yaşanan kopmalar buna örnektir.

**Soru 5** (derste sözlü, 01:00:58): Engine immobilizer nedir ve hangi RFID bandını kullanır?

> **Cevap (derste verildi):** Anahtar yuvaya girdiğinde çok kısa mesafeli haberleşmeyle anahtarın aracın şasi numarasıyla eşleşip eşleşmediğini kontrol eden, eşleşmezse aracı kilitleyen hırsızlık önleme sistemidir. LF (125-134 kHz) bandını kullanır.

**Soru 6** (ekrandan, 01:30:00): SAE otomasyon seviyelerini sıralayın. Seviye 2 ile seviye 3 arasındaki temel fark nedir?

> **Cevap (derste verildi):** 0 otomasyon yok, 1 sürücü desteği, 2 kısmi otomasyon, 3 koşullu otomasyon, 4 yüksek otomasyon, 5 tam otomasyon. Seviye 2'de araçta hızlanma ve direksiyon gibi birleşik otomatik fonksiyonlar vardır ama sürücü ortamı her an izlemek zorundadır. Seviye 3'te sürücü ortamı izlemek zorunda değildir, ancak bildirimle her an kontrolü almaya hazır olmalıdır.

**Soru 7** (derste sözlü, 01:44:31): "Driver status" bağlamında hangi bilgiler toplanabilir ve ne işe yarar?

> **Cevap (derste verildi):** Sürücünün varlığı, yorgunluk düzeyi, esneme, ayna kontrolü, göz kırpma miktarı, göz açıklığı, oksijen seviyesi ve nabız. Bu bilgilerle sürücü ya da riskli bir sürücü geliyorsa karşı taraf uyarılabilir. Bu bağlam özellikle seviye 5'in altındaki araçlar için kritiktir.

**Soru 8** (derste sözlü, 02:07:04): Hatalı sürüşe (incorrect driving) örnekler verin.

> **Cevap (derste verildi):** Ters şeritten ya da otoyola ters yönde girerek gitme, emniyet şeridinden geri geri gelme, çarpma, uygun olmayan yerden dönme, park edilmemesi gereken yere park etme, öndeki araca gereğinden fazla yaklaşma, aşırı hız ve otoyolda çok düşük hız.

## Dersin Toparlaması

Dersin ilk yarısı nesnelerin internetinde nesnelerin tanımlanması üzerineydi. IoT standartları, IPv6'ya geçiş ihtiyacı, kısıtlı cihazlara uygun protokoller (6LoWPAN, CoAP, MQTT) ve kaynağı kısıtlı cihazlarda güvenlik sorunu kısaca tamamlandıktan sonra barkod, QR kod, NFC ve RFID karşılaştırıldı. QR kod ucuz ve yaygın, ama görüş hattına, açıya, baskı kalitesine ve fiziksel koşullara bağımlıdır. RFID ise görüş hattı gerektirmez, çoklu okuma yapabilir ve farklı ortamlarda çalışır; ama daha pahalıdır ve elektromanyetik etkilere ve saldırılara açıktır. LF, HF, UHF ve mikrodalga bantları menzil, veri hızı, girişim ve maliyet açısından birbirinin karşıtı özellikler taşır; bu yüzden bant uygulamaya göre seçilmelidir.

İkinci yarıda yeni nesil araçlar ele alındı. SAE'nin 0-5 otomasyon seviyeleri, araç zekasının izlemesi gereken sürücü, sürüş, yaya, yol, hava ve araç bağlamları, ADAS'ın yüz yılı aşan gelişimi ve güvenlik-verimlilik-konfor amaçları anlatıldı. Sensör, VANET ve büyük veriyi bağlam füzyonunda birleştiren bir mimari gösterildi. Ders, çekirdek tasarım, bulut, hesaplama darboğazı, veri toplama, yol altyapısı ve simülasyon gibi açık konularla ve otonom araçların sensör, makine öğrenmesi, açık yol, regülasyon ve toplumsal kabul nedeniyle henüz yaygınlaşmadığı tespitiyle kapandı. Bu dersle dönemin konu anlatımı tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
