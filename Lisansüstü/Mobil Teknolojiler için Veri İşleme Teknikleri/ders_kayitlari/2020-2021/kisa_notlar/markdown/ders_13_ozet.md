# Ders 13 Çalışma Özeti

## Genel Konular

- IoT standartları, adresleme ve güvenlik (önceki haftanın tamamlanması)
  - Standardizasyon tablosunda EPCglobal, GRIFS, M2M, 6LoWPAN, ROLL, NFC, WirelessHART ve ZigBee gibi çalışmalar; iletişim menzili, veri hızı ve birim maliyetleriyle karşılaştırıldı (ekrandan, 00:20:00).
  - Adresleme: IPv4 adresleri tükendiği için NAT kullanılıyor; IPv6'ya geçiş gerekiyor. RFID etiketlerinin tanımlayıcı uzunluğu ve trafik karakterizasyonu (QoS) da açık konular.
  - TCP/IP yığını kısıtlı IoT cihazları için uygun değil: düşük kapasite yüzünden tamponda birikme ve bağlantı sorunları olabiliyor. Akıllı nesneler için CoAP (UDP'ye yakın), MQTT, 6LoWPAN ve bağlantı katmanında IEEE 802.15.4e kullanılıyor.
  - Güvenlik: kimlik doğrulama, dış saldırılara karşı koruma, doğrudan erişim yerine middleware kullanımı. Cihazlar fiziksel olarak korumasız ve kablosuz haberleştiği için veri havada yakalanabilir. Klasik kriptografik algoritmalar enerji ve bant genişliği açısından pahalı; kaynağı kısıtlı cihazlara uygun yeni çözümler gerekiyor (ekrandan, 00:25:00).
- Barkod ve QR kod
  - Barkod tek boyutlu veriyi siyah-beyaz çizgilerle yatayda kodlar; desende başlangıç/bitiş karakteri, veri alanı ve sessiz bölge (quiet zone) vardır. UPC ve Code 93 farklı barkod kodlamalarıdır.
  - QR kod veriyi iki boyutta saklar. Farklı iki boyutlu kodlar: QR Code, Data Matrix/Semacode ve MaxiCode (ekrandan, 00:30:00). QR kod, daha fazla veri saklama kapasitesi ve yaygın kabul sayesinde standartlaştı.
- QR kodun RFID'ye göre avantaj ve dezavantajları (derste tartışıldı)
  - Görüş hattı (line of sight) ve doğru açı gerekir; veri arttıkça daha yüksek çözünürlüklü görüntü ve kaliteli okuyucu gerekir.
  - Baskı kalitesi önemlidir; yırtılma, silinme, yağmur gibi fiziksel etkilerle bozulur. Aynı anda çok sayıda ürün okumak zordur.
  - Maliyeti çok düşüktür; bu yüzden yaygındır.
- NFC ve mobil ödeme
  - NFC kısa menzilde çalışır; okuyucu ve etiket gerekir, RFID mantığına yakındır. Mobil ödemede QR kod ile NFC yarış halindedir; NFC ile internet olmadan da ödeme yapılabilir.
- RFID
  - Sınıflandırma: güç tipine göre aktif/pasif, çalışma moduna göre salt okunur ya da okuma-yazma, frekans aralığına göre. Aktif, yarı pasif ve pasif etiketler vardır.
  - Pasif etiket: okuyucunun yaydığı elektromanyetik sinyal etiketin anteninde kondansatörde biriktirilir, yeterli enerji olunca bobine verilir ve etiket bilgiyi kodlanmış radyo dalgasıyla geri yollar (ekrandan, 00:40:00).
  - Frekans bantları (ekrandan, 00:40:00, 00:45:00, 01:00:00):
    - LF (125-134 kHz): pasif, en kısa okuma mesafesi (yaklaşık 30 cm), düşük veri hızı, sınırlı çarpışma önleme, sıvı ortam yakınında çalışabilme.
    - HF (13.56 MHz): pasif, veri hızı LF'den iyi, okuma mesafesi yaklaşık 1 m, NFC bu frekansı kullanır, lisanssız ve dünya çapında kullanılabilir.
    - UHF (433 MHz ve 860-930 MHz): çarpışma önleme protokolleri var, aynı anda yüzlerce etiket okunabilir, aktif etiketlerde menzil 30 m'ye kadar; su ve metalden yalıtılmalı.
    - Mikrodalga (2.4 GHz, bazen 5.8 GHz): yüksek veri hızı, 100 m'den fazla menzil; dalgalar kolay soğurulur, girişime ve yansımaya uğrar, ekipmanı pahalıdır.
  - Uygulamalar: hayvan takibi (LF), motor immobilizer (LF), ürün takibi ve biletleme (HF), konteyner ve tır takibi (UHF), erişim kontrolü ve üretim hatları (mikrodalga), temassız ödeme, bagaj takibi.
  - Avantajlar: yeniden yazılabilme, görüş hattı gerekmemesi, uzun okuma mesafesi, daha fazla veri saklama, çoklu etiket okuma, farklı çalışma ortamları, akıllı davranış, yüksek güvenlik (ekrandan, 01:20:00).
  - Dezavantajlar: QR koda göre yüksek maliyet ve yatırımın geri dönüşü, elektromanyetik alanlara duyarlılık, kişisel veriye saldırı riski (güven eksikliği), barkodun daha yaygın olması, açık standartların henüz yaygınlaşmaması.
- Yeni nesil araçlar ve otonom sürüş
  - SAE otomasyon seviyeleri 0-5: otomasyon yok, sürücü desteği, kısmi otomasyon, koşullu otomasyon, yüksek otomasyon, tam otomasyon (ekrandan, 01:30:00).
  - Araç zekasında izlenmesi gereken bağlamlar: sürücü durumu, dikkat dağıtıcı aktiviteler, boylamsal ve yanal sürüş, hatalı sürüş, yaya, yol durumu, hava, trafik göstergeleri, araç içi, araç arızaları (ekrandan, 01:45:00).
  - ADAS'ın tarihsel gelişimi (1885 ilk mekanik araçtan 2031 hedeflenen tam otonom sürüşe) ve ADAS'ın amaçları: güvenlik, verimlilik, konfor (ekrandan, 02:20:00, 02:25:00).
  - Kazaların büyük çoğunluğu (derste söylenen oran %94) insan kaynaklıdır.
  - Araç zekası mimarisi: sensörler, VANET ve büyük veri girdileri; konfor, eğlence, sürüş ve güvenlik servisleri; en üstte bağlam füzyonu (ekrandan, 02:30:00).
  - Açık konular: çekirdek tasarım, bulut servisleri, hesaplama darboğazı, veri toplama, yol altyapısı, simülasyon (ekrandan, 02:35:00).
  - Otonom araçların hâlâ yolda olmamasının nedenleri: sensörler, makine öğrenmesi, açık yol, regülasyon, toplumsal kabul (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- IoT cihazlarında güvenlik en büyük problemdir
  - Cihazlar fiziksel olarak korumasızdır ve kablosuz haberleşir. Kablosuz cihazlarda kullanılabilecek kriptografi, kablolu sistemlerdeki düzeyde olmayabilir; çünkü cihazların kaynakları kablosuz erişim noktasından bile düşüktür.
- QR kodun pratik kullanım sorunları
  - Teoride çalışan bir QR kod, yanlış boyutlandırıldığında ya da kenara basıldığında okunamayabilir. QR kod kullanıma alınmadan önce kalite kontrolden ve testten geçmelidir.
- Frekans bandı uygulamaya göre seçilmeli
  - Yüksek frekans (UHF, mikrodalga) daha hızlıdır ama çevredeki nesnelerden çok etkilenir; Bluetooth'ta araya bir insan girince kopma olması buna örnektir. Uygulamada kullanılacak protokol ve bant, dezavantajları gözetilerek seçilmelidir.
- RFID ile QR kod arasındaki seçim bir yatırım kararıdır
  - Uzun vadede RFID altyapıyı daha sağlıklı yürütür; kısa vadede en hızlı ve ucuz çözüm QR koddur.
- SAE seviyeleri endüstri standardıdır
  - Akademik makalelerde bu seviyelendirmenin takip edilmesi beklenir. Seviye 1 ile seviye 2 arasındaki çizgi incedir; seviye 2'nin anahtarı "birleşik otomatik fonksiyonlar"dır.
- Yollarda eski nesil araçlar kalacak
  - Bu yüzden yalnız otonom araçları değil, mevcut araçları da ADAS'larla akıllı hale getirmek ve yeni mimarileri mevcut ADAS'ları entegre edecek şekilde tasarlamak gerekir.
- Sürekli öğrenme sorunu
  - Ortam dinamik olduğu için otonom aracın öğrenmesi sürer; eski öğrendiğini unutmadan yenisini nasıl katacağı hâlâ açık bir problemdir.

## Kısa Tekrar Notları

- 6LoWPAN: düşük güçlü IEEE 802.15.4 cihazlarını IPv6 ağlarına bağlar.
- IPv4 adresleri tükendi, NAT kullanılıyor; IPv6'ya geçiş gerekli.
- Barkod tek boyutlu, QR kod iki boyutlu; QR kod daha fazla veri saklar.
- QR kod: görüş hattı ve açı ister, fiziksel bozulmaya açıktır, çoklu okuma zordur, ama çok ucuzdur.
- RFID etiketleri: aktif, yarı pasif, pasif. Pasif etiket enerjisini okuyucunun sinyalinden alır.
- LF 125-134 kHz (~30 cm), HF 13.56 MHz (~1 m, NFC), UHF 433 / 860-930 MHz (~30 m aktif), mikrodalga 2.4 / 5.8 GHz (>100 m).
- Frekans arttıkça veri hızı artar, girişim ve maliyet artar.
- UHF çarpışma önleme sayesinde aynı anda çok sayıda etiketi okuyabilir.
- SAE: 0 otomasyon yok, 1 sürücü desteği, 2 kısmi, 3 koşullu, 4 yüksek, 5 tam otomasyon.
- Seviye 3'te sürücü ortamı izlemek zorunda değildir ama her an kontrolü almaya hazır olmalıdır.
- Seviye 4 belirli koşullarda (ayrılmış hatlar, otoyollar), seviye 5 her koşulda tüm sürüşü yapar.
- ADAS amaçları: güvenlik, verimlilik, konfor.
- Uzun menzilli radarın görüş alanı dardır; sensör füzyonunda görüş alanları hesaba katılmalıdır.
- Açık konular: çekirdek tasarım, bulut, hesaplama darboğazı, veri toplama, yol altyapısı, simülasyon.

## Detaylı Açıklamalar

- IoT protokol yığını ve güvenlik
  - Ders, önceki haftanın IoT standardizasyon slaytlarıyla başladı. Standardizasyon tablosunda EPCglobal (RFID'nin elektronik ürün kodu çerçevesine entegrasyonu), GRIFS (yerel RFID uygulamalarından nesnelerin internetine geçiş), M2M, 6LoWPAN, ROLL, NFC, WirelessHART ve ZigBee yer alıyordu. Örneğin NFC için iletişim menzili yaklaşık $10^{-2}$ m ve veri hızı 424 kbps'ye kadar, 6LoWPAN ve ZigBee için menzil 10-100 m ve veri hızı yaklaşık $10^2$ kbps olarak verilmişti (ekrandan, 00:20:00).
  - Hoca TCP/IP yığınının kısıtlı akıllı nesneler için uygun olmadığını anlattı. Bağlantı kurulumu, tıkanıklık kontrolü ve veri tamponlama, düşük kapasiteli düğümlerde birikmeye ve bağlantı sorunlarına yol açabilir. Hocaya göre CoAP UDP'ye daha yakındır; MQTT'de daha çok TCP modeli uygulanır.
  - Bir öğrenci 6LoWPAN'ın açılımını "low power wireless personal area network" diye tahmin etti. Hoca bunun IoT cihazlarının mümkün olduğunca az enerji tüketerek haberleşmesi için kurulan bir ağ yapısı olduğunu, bağlantı katmanında IEEE 802.15.4e kullanıldığını ve bu katmanların IoT için değiştirilmesinin bir araştırma alanı olduğunu söyledi.
  - Ders sonrası not: Hoca CoAP'ı "kayıt olunca size yayınla gelen" bir yapı olarak anlattı. Büyük olasılıkla bu tarif daha çok MQTT'nin aracı (broker) tabanlı yayınla-abone ol modeline uyar. CoAP ise UDP üzerinde istek-yanıt modeliyle çalışır; kaynağı izlemek için "observe" seçeneği vardır.
- QR kod ve RFID karşılaştırması
  - Öğrencilerin saydığı QR kod dezavantajları şunlardı: görüş hattı ve tam karşıdan okuma gerekmesi, veri arttıkça çözünürlük ihtiyacının artması ve bunun okuyucu maliyetini yükseltmesi, kartvizit gibi yerlerde yanlış boyut ya da konum yüzünden okunamama, güvenlik amaçlı kullanımlarda kodun zaman zaman yenilenmesi gereği ve baskı kalitesi. Hoca buna fiziksel koşullara dayanıksızlığı ve çoklu okumanın zorluğunu ekledi. RFID'nin bazı türleri, toplu çıkışlarda bölgeden ayrılan bütün ürünleri okuyabilir.
  - NFC'nin rolü tartışılırken bir öğrenci, mobil ödemede NFC ile QR kodun yarıştığını, NFC'nin internet olmadan da ödeme yapabildiğini anlattı. iOS'ta NFC'nin uzun süre yalnız Apple'ın kendi ödeme sistemine açık olması iki platformun yaklaşım farkı olarak konuşuldu.
- RFID frekans spektrumu
  - Karşılaştırma tablosunda (ekrandan, 01:00:00) etiket maliyeti LF ve mikrodalgada yüksek, HF'de yüksek-orta, UHF'de orta; okuyucu maliyeti LF'de düşük, mikrodalgada yüksektir. Menzil 30 cm, 1 m, 30 m (aktif) ve 100 m'den fazla (aktifte 300 m'den fazla) olarak artar. Veri hızı ve girişim de düşükten yükseğe doğru gider.
  - Hoca LF'nin sıvı ortamda avantaj sağlamasını en ilginç özellik olarak gösterdi: veri hızı düşüktür ama dalga ortamdan daha az etkilenir.
  - Ders sonrası not: Hoca LF aralığını "125 GHz ile 134 GHz" diye söyledi; slaytta doğrusu 125-134 kHz'dir.
  - Uygulama tartışmasında UHF için HGS gibi geçiş sistemleri ve deprem anında telefonlar arası atlamalı haberleşme örnekleri verildi; hoca kampçılar ve mağaracılar için baz istasyonu olmayan yerlerde haberleşme çözümlerinden söz etti. Motor immobilizer, anahtar yuvaya girdiğinde kısa mesafeli LF haberleşmesiyle anahtarın araçla eşleştiğini kontrol eder; eşleşmezse araç kendini kilitler. Mikrodalga bandı, yoğun verinin hızlı aktarılması gereken üretim hatlarında ve fabrika ortamlarında kullanılır.
- Otonom araçlar
  - SAE seviyeleri: seviye 1'de araç sürücü tarafından kontrol edilir, bazı destek özellikleri (hız sabitleyici gibi) vardır. Seviye 2'de hızlanma ve direksiyon gibi birleşik otomatik fonksiyonlar vardır ama sürücü sürüşe dahil kalmalı ve ortamı her an izlemelidir; öndeki araca yaklaşınca hızı düşüren sistem, şeritte tutma ve yokuş kalkış desteği bu seviyeye örnek verildi. Seviye 3'te sürücü gereklidir ama ortamı izlemek zorunda değildir, bildirimle her an kontrolü almaya hazır olmalıdır; otomatik park sistemi örnek verildi. Seviye 4 belirli koşullarda (metrobüs hattı gibi ayrılmış hatlar, otoyollar) tüm sürüşü yapar; seviye 5 her koşulda yapar (ekrandan, 01:30:00).
  - Araç zekası çok sayıda bağlamı izlemelidir. Sürücü durumu (var/yok bilgisi, yorgunluk, esneme, göz kırpma, nabız), dikkat dağıtıcı aktiviteler (telefon, sigara, yüksek ses), boylamsal ve yanal sürüş (ani fren, ani hızlanma, şerit değiştirme), hatalı sürüş (ters yönde gitme, uygunsuz dönüş, hatalı park, çok yaklaşma, aşırı ya da çok düşük hız), yaya, yol durumu (çukur, tümsek, kaygan yol, yol çalışması), hava, trafik göstergeleri, araç içi (emniyet kemeri, yolcu sayısı) ve araç arızaları (yağ seviyesi, motor ısınması; CAN-BUS üzerinden) bu bağlamlardır (ekrandan, 01:45:00).
  - Araç zekası mimarisinde (ekrandan, 02:30:00) konum, jiroskop, LIDAR, ivmeölçer ve görsel sensörler, VANET üzerinden diğer araçlardan gelen bilgi ve bulutta toplanan büyük veri birlikte kullanılır. Merkezde sürüş vardır; konfor, eğlence ve güvenlik ayrı servislerle adreslenir. Bulut bağlantısı kritik olduğu kadar güvenlik zafiyeti de doğurur.
  - Otonom araç sensörlerinde (uzun ve kısa menzilli radar, LIDAR, kamera, kızılötesi) menzil uzadıkça görüş alanı daralır. Farklı kaynaklardan gelen verilerin birleştirilmesi ve hangisinin öncelikli olacağına karar verilmesi ciddi bir zorluktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
