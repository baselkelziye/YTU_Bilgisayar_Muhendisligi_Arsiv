# Ders 4 Çalışma Özeti

## Genel Konular

- Kablosuz sensör ağlarından Nesnelerin İnternetine (IoT) geçiş
  - Kablosuz sensör ağları (WSN), fiziksel dünyadan veri toplayan ilk organize yapılardır; 1990'larda askerî alanda, 2000'lerde tarım, çevre izleme ve hayvan takibinde yaygınlaşmıştır. Cep telefonu, hareketli bir düğüm gibi bu tabloya katılmıştır.
  - IoT'nin WSN'den iki temel farkı vardır: eşyaların içine elektronik devre yerleştirilerek ağa bağlanması ve her cihaza IP tabanlı olarak tek tek, uzaktan erişilebilmesi. WSN'de veri belirli coğrafi bölgelerden toplanır, IP mantığıyla tek tek cihaz sorgulanmaz.
  - IoT, bulut ve büyük veriyle birlikte düşünülür: her cihazın çevrim içi olması büyük miktarda veri üretir ve bu veri merkezde depolanır.
- IoT paradigması: tek paradigma, birden çok vizyon (ekrandan, 00:10:00 ve 00:15:00)
  - İnternet odaklı vizyon: nesnelerin internet üzerinden erişilebilir olması (IPSO, Internet 0, Web of Things, "connectivity for anything").
  - Nesne odaklı vizyon: nesnelerin RFID, EPC (Electronic Product Code), UID gibi tekil kimliklerle izlenebilmesi (NFC, WISP, kablosuz sensör ve eyleyiciler, gündelik nesneler, Spime, akıllı nesneler).
  - Anlamsal (semantic) vizyon: verinin anlamsal teknolojilerle gruplanması, veri üzerinde akıl yürütme ve anlamsal ara katman. Cihazlar ev, araç, kişisel, havaalanı gibi bölgelere ya da giyilebilir/taşınabilir cihaz gibi bakış açılarına göre gruplanabilir.
  - IoT bu üç vizyonun kesişimidir.
- IoT ile WSN karşılaştırması
  - WSN düğümleri temelde veri toplar ve uygulamaya özeldir (application specific). IoT'de veri akışı iki yönlüdür, nesneler birbiriyle haberleşir ve yapı insan odaklıdır (human oriented).
  - Makineden makineye haberleşme (M2M) WSN'de verinin aktarılması için kullanılırken IoT'de nesnelerin bilgi paylaşıp aksiyon almasını sağlar (ör. ev aletlerinin ya da araçların birbiriyle haberleşmesi).
- Spime kavramı (ekrandan, 00:20:00)
  - Space ve time birleşimi: ömrü boyunca uzayda ve zamanda izlenebilen, sürdürülebilir, geliştirilebilir ve tekil olarak tanımlanabilen nesne.
  - Verinin nereden ve ne zaman geldiği bilgisinin değiştirilemez olması önemlidir; adli süreçlerde sensör verileri kanıt olarak kullanılabilir. Güvenilirlik için donanımsal çözümler (bankacılıktaki HSM gibi) yazılımsal çözümlerden daha zor manipüle edilir ama daha maliyetlidir.
- Yaygın (pervasive/ubiquitous) hesaplama ve vizyonlar (ekrandan, 00:20:00)
  - ITU vizyonu: "her zaman, her yerde, herkes için bağlantıdan, her şey için bağlantıya".
  - Avrupa Komisyonu vizyonu: kimliği ve sanal kişiliği olan nesnelerin akıllı ortamlarda akıllı arayüzlerle sosyal, çevresel ve kullanıcı bağlamlarında iletişim kurması.
  - Bir eşyanın ortamı algılayıp yorumlayabilmesi çevresel zeka (ambient intelligence) kavramını doğurur; bugün bu, ev ve şehir ölçeğinde yönetime doğru genişlemiştir. Otonom araçlar, çok sayıda belirsiz parametre nedeniyle bu yönün en zor örneğidir.
- IoT ara katmanı (middleware) (ekrandan, 00:25:00)
  - SOA tabanlı mimari, aşağıdan yukarıya: Objects, Object Abstraction, Service Management, Service Composition, Applications; yanda tüm katmanları kesen "Management of Trust, Privacy, Security".
  - Ara katman, kullanıcıyı cihazlardan ayırır; cihazlara doğrudan erişimin getirdiği tehdidi azaltır, cihazlar arası koordinasyonu sağlar. Kaynakları kısıtlı cihazlarda ağır şifreleme algoritmaları çalıştırılamadığı için bu koruma önemlidir.
- IoT uygulama alanları (ekrandan, 00:30:00)
  - Ulaşım ve lojistik, sağlık, akıllı ortamlar, kişisel ve sosyal, fütüristik (robot taksi, şehir bilgi modeli vb.).
  - Örnekler: sürücüsüz metro hatları, drone ile paket teslimi, belediyelerin şehir verisiyle hat planlaması, sürüş destek sistemleri (ADAS) ve otonom araçlara geçiş.
- Açık araştırma konuları (ekrandan, 00:35:00)
  - Standartlar, hareketlilik desteği, adlandırma (ONS), taşıma protokolü, trafik karakterizasyonu ve QoS, kimlik doğrulama, veri bütünlüğü, mahremiyet, dijital unutma.
  - QoS: çok sayıda cihazın oluşturduğu trafikte gerçek zamanlı verinin önceliklendirilmesi.
  - Enerji: IoT cihazlarının çoğu bir güç kaynağına bağlıdır; taşınabilir nesnelerde (ör. ayakkabı) enerji yönetimi ileride sorun olacaktır.
- Dijital unutma (digital forgetting)
  - Tekrarlayan (redundant) ve artık işe yaramayan verilerin sıkıştırılması, ayıklanması ve belirli aralıklarla silinmesi. İnsan hafızasının kullanılmayan bilgiyi unutmasına benzetilir.
  - Bulut bilişim tekrarlanan veriyi azaltmanın temel yoludur, ama uç cihazlarda da kapasite sınırlıdır.
- Haberleşme ve mesajlaşma protokolleri
  - ZigBee: IEEE 802.15.4 tabanlı, yaklaşık 10-100 m menzil, düşük veri hızı. 6LoWPAN: 802.15.4 üzerinde IPv6 taşıyan, düşük güçlü standart.
  - NFC: yakın temas gerektirdiği için güvenlik açısından değerlidir; Bluetooth daha uzaktan bağlantıya izin verir.
  - Mesajlaşma protokolleri: MQTT ve CoAP.
  - IPv4 adresleri tükendiği için IPv6'ya geçiliyor; IPv6 güvenlik açısından ek çözümler de getirir. Adresleme konuları: IPv6 (128 bit), RFID etiketleri (64-96 bit tanımlayıcı), DNS ve Object Name Service (ekrandan, 00:45:00).
- TCP'nin IoT için yetersizliği (ekrandan, 00:45:00)
  - Bağlantı kurulumu (az veri, kısıtlı kaynak), tıkanıklık denetimi, veri tamponlama.
  - IoT'de ağırlıklı olarak UDP kullanılır: veriler küçüktür, sıra çok önemli değildir, her cihazla el sıkışma pahalıdır.
  - TCP/IP yığını: HTTP/FTP/SMTP - TCP/UDP - IPv4/IPv6 - 802.3/802.11. IP akıllı nesne yığını: CoAP - UDP - 6LoWPAN - IEEE 802.15.4e.
- IoT güvenliği ve mahremiyeti (ekrandan, 00:55:00, 01:05:00)
  - Temel ilkeler: saldırılara dayanıklılık (tek hata noktası olmamalı), veri kimlik doğrulama, erişim denetimi, istemci mahremiyeti.
  - Tehditler: DDoS, kimlik doğrulama sorunları, verinin manipülasyonu, fiziksel saldırı, kablosuz iletişimin kolay dinlenmesi, veri bütünlüğü.
  - Klasik kriptografi enerji ve bant genişliği açısından pahalıdır; kaynakları kısıtlı cihazlar için yeni çözümler gerekir. Şifrelemesi ucuz, şifre çözmesi pahalı algoritmalar uç cihazda enerji tasarrufu sağlayabilir.
  - Mobil kötücül yazılım (malware) tespiti: izin ve kategori uyumsuzluğu, sandbox/emülatörde davranış analizi; zararlı yazılım emülatörü fark edip kendini gizleyebilir, bu yüzden emülatörün gerçek telefon gibi davranması (arama, SMS, hareket, sensör verisi) gerekir. Bunun için GAN ile sentetik veri üretimi bir araştırma konusudur.
- Barkod ve QR kod (ekrandan, 01:10:00)
  - 1D barkod çizgi kalınlıklarıyla kodlar (UPC, Code 93); 2D kodlar matrise dayanır (QR, Data Matrix, Maxi Code vb.).
  - QR kod sürümleri: Version 1 = 21×21, Version 2 = 25×25, Version 3 = 29×29, Version 4 = 33×33 modül.
  - QR kapasitesi: 7089 sayısal karakter, 2953 bayt ikili veri (yaklaşık 3 KB).
  - Elektronik aksam yoktur, ucuzdur, ama görüş hattı (line of sight) gerekir.
- RFID (ekrandan, 01:15:00, 01:20:00)
  - Sınıflandırma: güç türü (aktif, yarı pasif, pasif), bellek kapasitesi/çalışma kipi (salt okunur ya da okunur-yazılır), frekans aralığı.
  - Pasif etikette okuyucunun yaydığı elektromanyetik sinyalden alınan enerjiyle etiket bilgisini radyo dalgasıyla geri gönderir.
  - LF (125-134 kHz): pasif, en kısa okuma mesafesi (metrenin üçte birinden az), en düşük veri hızı, sınırlı çakışma önleme; sıvı ortama yakın çalışabilir.
  - HF (13.56 MHz): pasif, daha iyi veri hızı, ucuz, en yaygın; yaklaşık 1 m okuma mesafesi; NFC bu frekansı kullanır.
  - UHF (433 MHz ve 860-930 MHz): 433 MHz aktif, diğeri pasif ve yarı pasif etiketler için; çakışma önleme ile yüzlerce etiket aynı anda okunur; aktif etiketlerde 30 m'ye kadar; su ve metalden yalıtılmalıdır.
  - Mikrodalga (2.4 GHz, bazen 5.8 GHz): yüksek okuma menzili ve veri hızı, ama dalgalar kolay soğrulur ve yansır; maliyetli ve az kullanılır.
- RFID ile QR/barkod karşılaştırması (ekrandan, 01:25:00, 01:30:00)
  - RFID avantajları: yeniden yazılabilme, görüş hattı gerekmemesi, daha uzak okuma, daha fazla veri, çoklu etiket okuma, dayanıklılık, yüksek güvenlik.
  - RFID dezavantajları: üretim karmaşıklığı ve maliyet, yatırım getirisi (ROI) hesabı, elektromanyetik girişim, mahremiyet kaygısı, standart ve uyumluluk sorunları.
- Büyük veri (ekrandan, 01:35:00, 01:40:00, 01:45:00, 01:50:00)
  - Bilimin evrimi: deneysel, kuramsal, hesaplamalı bilim ve veri bilimi.
  - 3V: hacim (volume), hız (velocity), çeşitlilik (variety); dördüncü V doğruluk (veracity): verinin hatalı, eksik ya da tekrarlı olabilmesi.
  - Büyük veri dosya ya da klasik veritabanı üzerinden işlenemez; bellek içi işleme (in-memory processing) ve Hadoop gibi platformlar kullanılır.
  - Uygulama alanları: banka, havacılık, eğitim, devlet, meteoroloji, astronomi, tıp, genomik, sosyal ağ analizi, öneri sistemleri.
  - Kazanımlar: operasyonel verimlilik, stratejik planlama, daha iyi müşteri hizmeti. Zorluklar: işlemci yükü ve yavaş G/Ç, tutarsızlık, eksiklik, ölçeklenebilirlik, zamanlılık, güvenlik.

## Hocanın Özellikle Vurguladığı Kısımlar

- IoT'yi WSN'den ayıran şey her cihaza IP tabanlı birebir erişimdir
  - WSN coğrafi bölgeden toplu veri toplar; IoT'de tek bir cihaza sorgu atılıp yanıt alınabilir.
- Verinin zaman damgası ve kaynağı değiştirilemez olmalıdır
  - Spime kavramı ve adli kanıt örneği; IoT güvenliğinde zaman damgası ve cihaza kimlik doğrulamalı bağlanma çok önemlidir.
- IoT cihazlarının güvenliği önemli bir araştırma alanıdır
  - Kısıtlı kaynaklar nedeniyle bilgisayarlardaki ağır şifreleme algoritmaları uygulanamaz.
- Dijital unutma ve GAN ile sentetik veri üretimi tez konusu olarak önerildi
  - Dijital unutma: hangi verinin saklanacağına ve silineceğine otomatik karar verme.
  - GAN: üreteç ve ayırt edicinin yarışmasıyla gerçeğe yakın veri üretip az veriyle çalışan sistemleri güçlendirme.
- Protokol seçimi uygulamaya göre yapılır
  - NFC yakın temas ister; yoklama gibi işlerde Bluetooth'a göre daha güvenlidir.
- QR kod ile RFID birbirinin yerine geçmez
  - Uygulamaya ve maliyete (ROI) göre seçilir; etiket fiyatları 5 sent ile 1 dolar arasında, yani yaklaşık 20 kat farklıdır.
- Büyük veri yalnız hacim değildir
  - En az 3V gerekir; sürekli değişmeyen büyük bir veri kütlesi tek başına büyük veri sayılmaz.

## Kısa Tekrar Notları

- IoT = internet odaklı + nesne odaklı + anlamsal vizyonların kesişimi.
- WSN: uygulamaya özel, veri toplama; IoT: insan odaklı, iki yönlü veri akışı, IP ile birebir erişim.
- Spime: uzay ve zamanda izlenebilen, tekil tanımlanabilen nesne.
- IoT middleware (SOA): Objects, Object Abstraction, Service Management, Service Composition, Applications; yanda güven, mahremiyet, güvenlik yönetimi.
- Açık konular: standartlar, hareketlilik, adlandırma, taşıma protokolü, QoS, kimlik doğrulama, veri bütünlüğü, mahremiyet, dijital unutma.
- TCP IoT için uygun değil (bağlantı kurulumu, tıkanıklık denetimi, tamponlama); UDP + CoAP + 6LoWPAN + 802.15.4e.
- Mesajlaşma: MQTT, CoAP. Ağ: ZigBee (802.15.4), 6LoWPAN, NFC, Bluetooth.
- Güvenlik ilkeleri: saldırıya dayanıklılık, veri kimlik doğrulama, erişim denetimi, istemci mahremiyeti.
- Malware tespiti: izin uyumsuzluğu, sandbox/emülatör analizi; emülatörün gerçek telefon gibi davranması gerekir; GAN ile sentetik davranış verisi.
- QR: 7089 sayısal karakter, 2953 bayt; Version v boyutu 17+4v modül (21, 25, 29, 33).
- RFID frekansları: LF 125-134 kHz (<1/3 m), HF 13.56 MHz (~1 m, NFC), UHF 433 / 860-930 MHz (aktifte 30 m'ye kadar), mikrodalga 2.4 / 5.8 GHz.
- RFID: görüş hattı gerekmez, çoklu okuma, yeniden yazılabilir ama pahalı ve standart sorunu var.
- Büyük veri: volume, velocity, variety (+ veracity); bellek içi işleme, Hadoop.

## Detaylı Açıklamalar

- Bilgisayarlar uzun süre yalnız insanın verdiği girdiyi işleyip çıktı üreten makineler olarak tasarlanmıştı; çevreden veri toplama ihtiyacı kablosuz sensör ağlarıyla karşılandı. Nesnelerin İnterneti bu fikri bir adım öteye taşır: gündelik eşyalar sensör ve elektronik devrelerle donatılır, her biri IP üzerinden tek tek erişilebilir hâle gelir ve üretilen veri bulutta toplanır. Bu nedenle IoT bulut bilişim ve büyük veriyle ayrılmaz biçimde birlikte anılır.
- IoT tek bir bakış açısıyla tanımlanamaz. İnternet odaklı vizyon bağlantıyı, nesne odaklı vizyon RFID ve EPC gibi tekil kimliklerle izlenebilirliği, anlamsal vizyon ise verinin anlamlandırılmasını ve cihazların bağlama göre gruplanmasını öne çıkarır. Bu esneklik IoT'yi WSN'den ayırır: WSN uygulamaya özel ve tek yönlü veri toplamaya yönelikken IoT nesnelerin birbiriyle konuşup aksiyon aldığı, insanın gündelik hayatını kolaylaştırmayı hedefleyen bir yapıdır.
- Verinin nereden ve ne zaman geldiği (spime) güvenilir olmalıdır. Hoca, sıcaklık, basınç, nem gibi sensör verilerinin bir yangının nasıl çıktığına dair kanıt olarak kullanılabileceğini örnek verdi. Bu tür güvenilirlik için yazılım yetmeyebilir; bankacılıktaki donanım güvenlik modülleri (HSM) gibi, önce yazılımla yapılan iş zamanla güvenlik için özel donanıma taşınır.
- Ara katman cihazlarla uygulamalar arasında bir tampon görevi görür. Kullanıcı cihazdan istediği bilgiyi alır, cihazlar birbiriyle koordine olur, ama cihaza doğrudan erişilmediği için saldırı yüzeyi küçülür. Bu, işlem gücü kısıtlı ve güçlü şifreleme çalıştıramayan cihazlar için özellikle önemlidir.
- Dijital unutma, IoT'de üretilen verinin sonsuza kadar saklanamayacağı fikrine dayanır. Mutfaktaki iki cihazın aynı ortamı ölçmesi ya da aynı bölgedeki beş sıcaklık sensörünün verisi gibi tekrarlı veriler ayıklanmalı, hangi verinin merkeze gönderileceği ve hangisinin cihazda kalacağı belirlenmeli, veriler belirli aralıklarla silinmelidir. Hoca bunu insan hafızasına benzetti ve bir sahnedeki sekiz fotoğraftan hangilerinin silineceğine karar veren bir sistemi örnek verdi: yüz ifadesi, netlik, bulanıklık, renk ve kompozisyon gibi ölçütler bir algoritmaya dönüştürülebilir.
- IoT protokol yığını klasik TCP/IP'den farklıdır. TCP'nin bağlantı kurulumu, tıkanıklık denetimi ve tamponlama gereksinimi küçük veri gönderen, kaynakları kısıtlı cihazlar için pahalıdır; bu yüzden UDP üzerinde CoAP (HTTP'nin IoT karşılığı), ağ katmanında 6LoWPAN ve bağlantı katmanında IEEE 802.15.4e kullanılır.
- Güvenlikte en büyük sorunlar DDoS, kimlik doğrulama ve verinin manipülasyonudur. Hoca otonom araçlara sızılarak aracın yoldan çıkarılabilmesini ve dijital verinin silinip değiştirilebilmesini örnek verdi; bu yüzden dijital adli bilişim (digital forensics) önem kazanmaktadır. Şifrelemede enerji dengesi önemlidir: uç cihazda şifrelemesi ucuz, merkezde şifre çözmesi pahalı bir algoritma seçmek akıllıca olabilir.
- Mobil kötücül yazılımlar telefondaki bilgiyi dışarı sızdırmayı amaçlar. Bir uygulamanın kategorisiyle ilgisiz izinler istemesi ilk ipucudur. Android'de her uygulama kendi sanal makinesinde, izole çalışır; şüpheli uygulama sandbox/emülatörde çalıştırılıp davranışı incelenir. Ancak zararlı yazılım gerçek telefonda olup olmadığını kontrol edip emülatörde kendini gizleyebilir. Emülatörün gerçek telefon gibi arama, SMS, hareket ve sensör verisi üretmesi gerekir; bunun için GAN'larla gerçek veriden öğrenilmiş sentetik veri üretmek bir araştırma konusudur.
- QR kod ile RFID farklı amaçlara hizmet eder. QR kod basılması ucuz, elektronik içermeyen ama görüş hattı gerektiren, güncellenemeyen bir yapıdır; RFID ise görüş hattı gerektirmez, uzaktan ve topluca okunabilir, yeniden yazılabilir ama pahalıdır ve frekansa bağlı girişim sorunları vardır. Seçim yatırım getirisi hesabıyla yapılır.
- Büyük veri, veri biliminin temel yapı taşıdır. Hacim tek başına yetmez; verinin sürekli ve hızlı üretilmesi ve farklı türlerde olması gerekir; dördüncü V olan doğruluk, verinin eksik, hatalı ya da tekrarlı olabileceğini anlatır. Bu tür veriyi işlemek için veri tek seferde belleğe alınır, orada işlenir ve belli aralıklarla depoya yazılır. Hoca banka verisini (milyonlarca müşteri, sürekli değişen işlemler, farklı formatlar, eksik ve tutarsız kayıtlar) tam bir büyük veri örneği olarak verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
