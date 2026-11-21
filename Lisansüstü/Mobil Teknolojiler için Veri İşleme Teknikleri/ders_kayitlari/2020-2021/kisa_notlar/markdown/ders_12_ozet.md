# Ders 12 Çalışma Özeti

## Genel Konular

- Düşme tespiti (fall detection) uygulamasının işlem hattı
  - Android telefonda çalışan küçük bir düşme tespiti uygulaması tarif edildi. Uygulamada en az üç karar yöntemi bulunur: eşikleme (thresholding) kullanan kural tabanlı bir yöntem, bir makine öğrenmesi yöntemi ve bir derin öğrenme yöntemi. İstenirse k-NN, Random Forest, Decision Tree, SVM gibi farklı sınıflandırıcılar da eklenebilir.
  - Yalnız ivmeölçer kullanılır. X, Y, Z eksenlerinden gelen veri, sinyal vektör büyüklüğüne (signal vector magnitude) çevrilerek tek boyuta indirilir: $SVM = \sqrt{x^2 + y^2 + z^2}$.
  - Düşme kısa sürede olduğu için veri 2-3 saniyelik pencerelere bölünür. Okuma sırasında iki tampon (double buffer) kullanılabilir: biri işlenirken diğeri doldurulur.
  - Her pencereden ortalama, standart sapma, maksimum, minimum gibi en az beş temel öznitelik çıkarılır.
  - Öznitelik çıkarmadan önce bir ön işleme adımı konur: normalizasyon ya da yumuşatma (smoothing) için alçak geçiren süzgeç.
  - Uygulama her 3 saniyede bir "düşme / düşme değil" çıktısı verir.
  - Model, MobiFall veri setinden eğitilir. Model telefona yüklenir; hoca Weka'nın telefona entegre edilip eğitimin de telefonda yapılmasını ve süresinin ölçülmesini önerdi.
- Uygulamanın enerji tüketimini ölçme
  - Okuma, ön işleme, öznitelik çıkarma ve sınıflandırma adımlarının ve farklı sınıflandırıcıların enerjiye etkisi karşılaştırılır. Sonuç yüzde ya da joule cinsinden verilebilir.
  - Ölçümler telefon şarj cihazına bağlı değilken yapılmalıdır. Çok küçük farklar uzun süreli çalıştırmalarla (örneğin binlerce çalıştırma) karşılaştırılabilir hale getirilir.
  - Ekran, CPU'nun yoğun ve boşta (idle) olduğu durumlar gibi telefon bileşenlerinin güç tüketimi için literatürden bir referans model alınabilir. Hoca, yazılımsal ölçümün donanımsal ölçüme yakın sonuç verdiğini iddia eden bir makaleyi temel aldı.
- Kablosuz sensör ağlarının (WSN) vizyonu ve donanımı
  - "Many-tiny" ilkesi: hesaplama (computation), haberleşme (communication) ve algılama (sensing) yapabilen binlerce ucuz minyatür cihazdan oluşan kablosuz ağlar. Akıllı alanlar, çevresel izleme ve savaş alanı uygulamaları için tasarlanmıştır (ekrandan, 00:30:00).
  - Zamanla algılamaya aktüatörler (algıladığına karşılık eylem yapabilen birimler) eklendi.
  - Dış ortamda düğümler saçılarak/atılarak, iç ortamda elle yerleştirilir.
  - Bir sensör düğümü işlemci, radyo alıcı-verici (transceiver), güç kaynağı, bellek/depolama ve bazen GPS'ten oluşur.
  - RAM, flash ve mikrodenetleyici frekansı kısıtlıdır. Bu yüzden dinamik voltaj ölçekleme (dynamic voltage scaling), CPU'yu düşük frekansta çalıştırma, veriyi düğümde işleyip yalnız sonucu gönderme gibi çözümler kullanılır.
  - Bekleme (standby) modunda tüketim mikroamper düzeyindedir; birkaç mA'lik çalışma tüketimiyle arada büyük fark vardır.
  - Vücut alanı ağı (Body Area Network) vücut üzerindeki düğümleri, kişisel alan ağı (Personal Area Network) kişinin çevresini kapsar.
- WSN tarihçesi (ekrandan, 00:35:00)
  - 1993-4 UCLA LWIM projesi; 1999-2002 DARPA destekli büyük projeler (SensIT, PAC/C; WINS, Smart Dust / Motes / TinyOS, PicoRadio).
  - 2003 IEEE 802.15.4 (düşük veri hızlı kablosuz standart); 2007 6LoWPAN (IEEE 802.15.4 ağları üzerinden IPv6 paketleri); 2010 WirelessHART (2,4 GHz ISM bandında güvenli, TDMA tabanlı kablosuz mesh).
- WSN'lerin özellikleri (ekrandan, 00:45:00)
  - Düğümler birbirine yakın olmalıdır; yoğunluk 20 düğüm/m³'e kadar çıkabilir.
  - Bilgi akışı genelde asimetriktir: sensör düğümlerinden havuza (sink) doğru.
  - Haberleşme sorgu (query) ya da olaylarla (event) tetiklenir.
  - Enerji sınırlıdır; birçok uygulamada pil değiştirilemez ya da şarj edilemez.
  - Topoloji çoğunlukla statiktir; ama düğüm arızası ve hareketliliği yüzünden değişebilir.
  - Düğüm başına düşük maliyet, boyut ve ağırlık; arızaya yatkınlık; noktadan noktaya yerine yayın (broadcast) haberleşme; bilgi kalitesini artırmak için ağ içi işleme (in-network processing).
  - Merkezi kontrolden kaçınılır, çünkü bütün verinin merkeze gitmesi ağ ömrünü kısaltır. Düğümler komşularının bilgisiyle dağıtık karar alır.
- Ağ içi işleme ve küme başları
  - Komşu düğümlerden gelen veri birleştirilir (data aggregation) ve merkeze daha kaliteli bir veri gönderilir.
  - Birleştirmeyi küme başı (cluster head) yapar. Küme başının enerjisi çabuk bittiği için belirli turlarda değiştirilmesi ağ ömrünü (network lifetime) uzatır.
  - Komşuların yakınlığına göre çıkış gücünü dinamik ayarlamak enerji tasarrufu sağlar.
- Haberleşme örüntüleri (ekrandan, 00:50:00)
  - Convergecast: sensör düğümleri topladıkları veriyi havuza bildirir.
  - Multicast: veri havuzdan ağdaki düğümlere dağıtılır (güncelleme, bilgilendirme).
  - Yerel yayın/dedikodu (local broadcast/gossip): komşular arasında veri alışverişi; ham okumaları göndermek yerine birlikte işleme için.
- Mobil havuz, tek atlamalı ve çok atlamalı haberleşme
  - Mobil havuz (mobile sink): bir araç alanda gezip düğümlerden veri toplar (Afrika'daki hayvan izleme örneği). Verinin uzun mesafe taşınmasını önler.
  - Çok atlamalı (multi-hop) haberleşmede düğüm, kendisine gelen veriyi de aktarmak zorundadır. Yine de uzak bir düğümün baz istasyonuna doğrudan göndermesinden daha az enerji harcar.
- Veri toplama modelleri (ekrandan, 00:55:00)
  - Sürekli (continuous): periyodik raporlama, örneğin bir tarlanın sıcaklık haritası.
  - Sorguya dayalı (query-driven): yalnız havuzun açık isteğine yanıt, örneğin önümüzdeki 2 dakikanın ortalama sıcaklığı.
  - Olaya dayalı (event-driven): yalnız ilgili olay olunca raporlama, örneğin yangın ya da eşiği aşan sıcaklık. Askeri alanda araç ya da birlik geçişinin tespiti bu türdendir.
- Ağ gereksinimleri ve konuşlandırma (deployment)
  - Gereksinimler: enerji verimliliği (radyonun uyku/uyanma döngüleriyle çalıştırılması), ölçeklenebilirlik (yüzlerce-binlerce düğüm), altyapı olmadığı için öz-organizasyon (ekrandan, 00:55:00).
  - Konuşlandırma hedefleri: kapsama (coverage), bağlanırlık (connectivity), ardından daha az düğüm ve daha az enerjiyle aynı bölgeyi izlemek.
  - Rastgele (random) ve yapılandırılmış (structured) konuşlandırma; yapılandırılmışta elle ya da otonom robotlarla yerleştirme.
  - Fazla konuşlandırma (over-deployment): artık (redundant) düğümlerle önceden yerleştirme. Artımlı konuşlandırma (incremental deployment): boşluklar tespit edilince düğüm ekleme.
  - Alternatif olarak mobil sensör düğümleri konuşlandırma eksiklerini telafi eder ve "ilginç" alanlara yönelebilir (ekrandan, 01:15:00).
- Tipik ağ topolojileri (ekrandan, 01:15:00; 01:20:00)
  - Yıldız (tek atlamalı): tasarımı basitleştirir, ama ölçeklenebilirliği ve dayanıklılığı zayıftır. Günlük örnek: kablosuz erişim noktası, baz istasyonu.
  - Düz çok atlamalı mesh, yapılandırılmış ızgara (structured grid) ve iki katmanlı hiyerarşik küme topolojisi (two-tier hierarchical cluster). Sonuncusunda düğümler küme başlarına raporlar ve büyük ağ, verinin yerelde işlenip birleştirildiği bölgelere ayrılır.
  - Küme başı ya daha güçlü bir düğüm seçilir ya da düz bir ağda görev düğümler arasında dönüşümlü değiştirilir.
- Bakım ve gerçek hayattaki durum
  - Pil değiştirmek ya da bozulan düğüme müdahale etmek çoğu zaman pratik değildir; güneşten enerji toplama mümkündür ama yaygın değildir (ekrandan, 01:20:00).
  - Hocaya göre binlerce düğümün sık sık konuşlandırıldığı anlatımı gerçek hayatı yansıtmaz; uygulamalar çoğunlukla deneysel ya da bütçesi ayrılmış hedefe yönelik çalışmalardır. Bu yaklaşım zamanla IoT'ye evrildi: ayrı düğüm tasarlamak yerine mevcut cihazlar akıllı hale getirildi. Erişilmesi zor coğrafyalarda WSN'in yerini IoT tutamaz.
- WSN ile IoT'nin enerji açısından farkı
  - WSN'de enerji sahada temel sorundur. IoT cihazlarının çoğu enerjisini araçtan ya da şebekeden alır. Enerji ihtiyacı olan IoT cihazları (kalem, yaka iğnesi, ayakkabı gibi taşınabilir eşyalar) ayrı bir sınıftır.
  - Derste sayılan örnekler: robot süpürge, büyük pilli kablosuz güvenlik kamerası, yürüyüş bozukluğunu basınçtan çıkaran akıllı ayakkabı.
- Güç tüketimi, protokol tasarım güçlükleri ve güvenilirlik
  - Radyo (haberleşme) en çok enerjiyi harcar; boşta (idle) beklemesi bile ciddi tüketimdir. Sensör ve CPU'nun tüketimi çok düşüktür. Bu yüzden güç farkında (power-aware) protokoller gerekir.
  - Protokol tasarım güçlükleri: öz-optimizasyon ve uyum, uygulamaya özel ağlar için sistematik tasarım, gizlilik ve güvenlik (bilginin hassasiyeti, düşmanca ortamlara konuşlandırma) (ekrandan, 01:45:00).
  - Hoca listeye güvenilirliği (reliability) ekledi: verinin manipüle edilmesi ve sensörün hatalı veri üretmesi.
  - Hatalı veri, komşu düğümlerle karşılaştırılarak aykırı değer tespiti (outlier detection) ile bulunur. Küçük farklarda birleştirme için standart sapma yüksekse medyan, düşükse ortalama tercih edilir. Birleştirme merkezde değil, bir düğümde yapılır.
- Ses tabanlı konum belirleme ve şifreleme
  - Keskin nişancının yerini bulmak için en az iki mikrofon gerekir; konum, sesin mikrofonlara varış süreleri ve mikrofonlar arası mesafeden hesaplanır. Daha çok mikrofon daha doğru sonuç verir.
  - Sensör ve IoT ağlarında kablolu ağlardakinden daha hafif şifreleme kullanılır. Uç noktada şifreleme (encrypt) az enerji harcamalı, ağır iş çözme (decrypt) tarafında olmalıdır. Açık anahtarlı kriptografi çoğunlukla gizli anahtarların değişimi için kullanılır, haberleşme bu anahtarlarla sürer.
- WSN uygulamaları (ekrandan, 01:55:00)
  - Askeri, çevre/habitat izleme, sağlık, acil durum/gözetim, afet erken uyarı, ulaşım ve lojistik, yapısal/endüstriyel izleme.
  - Su altı akustik sensör ağlarında ortam (medium) farklıdır: sinyal kırılımı ve güç kaybı yüksek, veri hızı düşüktür; kapsama 3 boyutlu modellenmelidir. Toprak altı sensörler için de benzer sorunlar vardır.
  - Lojistikte RFID, inşaat mühendisliğinde köprü ve viyadüklerin dayanıklılığı ve buzlanma izleme örnek verildi.
- IoT ile WSN'in farkları
  - WSN'de bilgi akışı tek yönlü, IoT'de çift yönlüdür. WSN düğümlerinin IP adresi yoktur, doğrudan erişilemezler; IoT cihazlarına doğrudan erişilebilir. IPv6 yaygınlaşmadığı için IoT cihazları çoğunlukla bir ağ geçidinin arkasında kalır ve NAT gerekir.
  - Üç bakış açısı: internet odaklı (internet-oriented), nesne odaklı (things-oriented), anlam odaklı (semantic-oriented). WSN, nesne odaklı bakışta bir alt küme gibi görülebilir, ama IoT'nin adreslenme yeteneği yoktur.
  - IoT cihazlarının ürettiği büyük veri cihazda saklanamaz; işlenip belirli süre sonra silinmesi gerekebilir.
  - Spime: yaşam süresi boyunca uzay (SPACE) ve zaman (TIME) içinde izlenebilen, sürdürülebilir, geliştirilebilir ve tekil olarak tanımlanabilen nesne (ekrandan, 02:15:00). Verinin nereden ve ne zaman alındığı karar mekanizmasını doğrudan etkiler; zaman bilgisi verinin güncel olup olmadığını, yer bilgisi doğru yerden gelip gelmediğini gösterir ve yakın konumlardaki veriler korele edilebilir.
  - Zaman bilgisi veriyle birlikte taşınmak zorundadır. Yer bilgisi taşınmayabilir, ama cihaz yer değiştirdiğinde merkeze bildirilmelidir.
  - Her cihaza doğrudan erişim hizmet engelleme (denial of service) riski doğurur. Bu yüzden araya bir ara katman (middleware) konur: nesneler, nesne soyutlama, servis yönetimi, servis bileşimi ve uygulamalar (ekrandan, 02:20:00).
  - IoT uygulama alanları: ulaşım ve lojistik, sağlık, akıllı ortamlar, kişisel ve sosyal, fütüristik (ekrandan, 02:20:00).
  - IoT uygulamaları insan odaklıdır (yaşam kalitesini artırmaya yönelik); WSN uygulamaları göreve özeldir (tarım, hayvan izleme, meteoroloji) ve çoğunlukla gözlemle sınırlıdır.
  - Açık sorunlar: kimlik doğrulama, gizlilik, veri bütünlüğü, trafik karakterizasyonu, dijital unutma (digital forgetting). Paket başlığının küçük olması gerekir; MQTT ve CoAP kullanılsa da yerleşmiş bir protokol yoktur. WSN uygulamaları görev bitince sona erer, IoT ağları yıllarca çalışacak şekilde kurulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Düşme tespitinde asıl soru adımların enerjiye etkisidir
  - Hedef, telefonda veri işlerken sınıflandırıcı seçiminin ve okuma, ön işleme, öznitelik çıkarma adımlarının enerji tüketimini ne kadar etkilediğini göstermektir. Hocaya göre bu konuda çok fazla çalışma yoktur.
- Radyo en pahalı bileşendir
  - Haberleşme, hesaplamadan çok daha fazla enerji harcar. Veriyi düğümde işleyip sonucu göndermek, küme başını döndürmek ve çıkış gücünü ayarlamak bu yüzden önemlidir.
- Güvenilirlik, gizlilik ve güvenlik kadar önemlidir
  - Sensör verisine ne kadar güvenileceği büyük bir sorundur; manipülasyon ve hatalı sensör ayrı risklerdir.
- WSN anlatımı ile gerçek hayat farklıdır
  - Binlerce düğümün sık konuşlandırıldığı bir gerçeklik yoktur; alan IoT'ye evrilmiştir.
- IoT'nin WSN'den en büyük farkı eylem alabilmesidir
  - Eskiden çevre gözlenip tespit yapılıyordu. IoT ise aktüasyonla doğrudan nesneyi yapılandırır: ışığı kapatmak, vanayı açıp kapamak gibi.
- Spime: yer ve zaman bilgisi
  - IoT verisinde zaman bilgisi mutlaka taşınmalı, yer değişikliği merkeze bildirilmelidir.

## Kısa Tekrar Notları

- Düşme tespiti: ivmeölçer → $\sqrt{x^2+y^2+z^2}$ → ön işleme (normalizasyon, alçak geçiren süzgeç) → 2-3 s pencere → en az 5 öznitelik → eşik / ML / derin öğrenme → 3 saniyede bir karar.
- Enerji karşılaştırması şarjsız telefonda, uzun çalıştırmalarla yapılır; yüzde ya da joule olarak verilir.
- WSN: many-tiny ilkesi; hesaplama + haberleşme + algılama; sonradan aktüatörler.
- Düğüm: işlemci, radyo, güç kaynağı, bellek, (GPS).
- Tarihçe: LWIM (1993-4), DARPA (1999-2002), IEEE 802.15.4 (2003), 6LoWPAN (2007), WirelessHART (2010).
- Özellikler: yoğun, asimetrik akış, sorgu/olay tetiklemeli, sınırlı enerji, çoğunlukla statik topoloji, broadcast, ağ içi işleme.
- Haberleşme örüntüleri: convergecast, multicast, local broadcast/gossip.
- Veri toplama: continuous, query-driven, event-driven.
- Konuşlandırma: random / structured; over-deployment / incremental; mobil düğümler.
- Topoloji: yıldız, mesh, ızgara, iki katmanlı hiyerarşik küme.
- Radyo > sensör, CPU; boşta bile tüketir → power-aware protokoller.
- Hatalı veri: komşularla aykırı değer tespiti; yüksek std → medyan, düşük std → ortalama.
- Ses konumlama en az iki mikrofon ister.
- Hafif şifreleme; ucuz şifreleme, pahalı çözme.
- Su altı ağları: farklı ortam, düşük veri hızı, 3B kapsama.
- IoT vs WSN: çift yönlü / tek yönlü, IP'li / IP'siz, insan odaklı / göreve özel, eylem alan / gözleyen.
- Spime = space + time; middleware katmanları; dijital unutma; MQTT, CoAP.

## Detaylı Açıklamalar

- Düşme tespiti uygulamasında veri akışı birkaç katmana ayrılır. İvmeölçerin üç ekseni tek bir büyüklük sinyaline ($\sqrt{x^2+y^2+z^2}$) indirgenir; bu, telefonun yönünden bağımsız bir sinyal verir. Sinyal önce yumuşatılır ya da normalize edilir. Düşme birkaç saniye sürdüğü için 2-3 saniyelik pencereler kullanılır; iki tamponlu okuma sayesinde bir pencere işlenirken bir sonraki doldurulur. Pencereden çıkarılan ortalama, standart sapma, maksimum, minimum gibi öznitelikler hem eşik tabanlı kurala hem makine öğrenmesi ve derin öğrenme sınıflandırıcılarına girer. Model MobiFall veri setiyle kurulur. Hoca, Weka'nın Android'e eklenip eğitimin de telefonda yapılmasını önerdi; bir öğrenci Weka'nın ARFF ya da CSV dosyalarını uygulamaya gömmenin ya da dosya seçtirmenin Android dosya izinleri yüzünden iş çıkaracağını söyledi, hoca da son sürümlerdeki dosya düzenlemelerinin bazı ayarlar gerektirdiğini onayladı. Enerji ölçümünde bir makaledeki yazılımsal yöntem temel alınır; makale, bu yöntemin donanımsal ölçüme yakın sonuç verdiğini iddia eder.
- Kablosuz sensör ağları "many-tiny" ilkesine dayanır: çok sayıda küçük ve ucuz düğüm, fiziksel dünyayı ince bir uzay-zaman çözünürlüğüyle gözlemek için bilgi teknolojisiyle gerçek dünya arasında köprü kurar (ekrandan, 00:30:00). Düğümlerin RAM'i, flash belleği ve işlemci frekansı düşüktür. Haberleşme için Zigbee/IEEE 802.15.4 gibi düşük hızlı radyolar kullanılır; multimedya sensör ağlarında görüntü ve ses bu düşük hızla taşınamadığı için veri birden fazla rota üzerinden gönderilir.
- Hoca Zigbee veri hızını "256 kilobit per second" olarak söyledi.

  > **Ders sonrası not:** IEEE 802.15.4'ün 2,4 GHz bandındaki veri hızı büyük olasılıkla 250 kbit/s'dir. Slayt listesindeki Tmote Sky özellikleri küçük resminde de "250 kbps IEEE 802.15.4" ifadesi seçiliyor.

- WSN'de bilgi genelde uç düğümlerden baz istasyonuna, oradan merkeze akar. Haberleşme üç biçimdedir: düğümlerden havuza (convergecast), havuzdan düğümlere (multicast) ve komşular arasında (gossip). Hoca, düğümlerin ömrünü uzatmak için yerel haberleşmeyi tercih ettiklerini söyledi. Mobil havuz yaklaşımında bir araç habitat içinde gezerek veri toplar ve verinin uzun mesafe taşınmasına gerek kalmaz. Çok atlamalı haberleşmede ara düğümler kendileri bir şey algılamasa bile gelen veriyi aktarmak zorundadır; buna rağmen uzak bir düğümün doğrudan gönderim yapmasından daha az enerji harcanır.
- Slaytta radyo karakteristiklerini karşılaştıran bir tablonun gönderim akımı (Tx current: 30 mA, 26,7 mA, 17,4 mA, 12 mA, 9 mA), alım akımı (Rx current: 12,5 mA, 9,6 mA, 19,7 mA, 3,8 mA, 12 mA) ve kapsama mesafesi (iç ortam: 50 m, boş, 50 m, 100 m, 30 m, 24-90 m; dış ortam: 125 m, >100 m, 125 m, 300 m, 80 m, 90-610 m) satırları görünüyordu (ekrandan, 00:50:00). Hoca veri hızlarının düşük olduğunu, yalnız WLAN (Cisco) tarafındaki veri hızının yüksek olduğunu vurguladı. <!-- BELİRSİZ: Tablonun sütun başlıkları (hangi radyo modelleri olduğu) ve veri hızı satırları karede görünmüyor. -->
- Olaya dayalı veri teslimine örnek olarak araç geçişinin nasıl tespit edileceği tartışıldı. Lazer ve termal kamera mümkündür ama küçük düğümler için pahalıdır ve sürekli tam kapsama sağlamak zordur. Basınç sensörü aracın üzerinden geçmediği durumda tetiklenmeyebilir. Ortam sesi üzerinden tespit daha ucuzdur ve kapsaması daha yüksektir. Bir öğrenci elektrikli araçların sessiz olduğu, basınç ve motor sıcaklığı izinin de az olduğu için bu yöntemlerden kaçabileceğini söyledi; hoca bunun ilginç bir araştırma sorusu olabileceğini belirtti.
- Konuşlandırmanın ilk hedefleri kapsama ve bağlanırlıktır; bunlar sağlandıktan sonra aynı bölgenin daha az düğümle ve daha az enerjiyle izlenmesi hedeflenir. Rastgele atılan düğümler aynı yere düşebildiği için mobil sensör ağları ortaya çıktı; kısmen statik, kısmen mobil heterojen ağlarda bozulan bir düğümün yerine mobil düğüm götürülebilir, ama bunun maliyeti vardır.
- Hatalı sensör verisi sorununda iki durum ayrıldı. Bir düğüm belirgin biçimde farklı ölçüyorsa komşularla karşılaştırma bunu aykırı değer olarak gösterir ve merkeze bildirilir. Ölçümler arasında yalnız 2-3 derecelik küçük farklar varsa birleştirmede tek bir temsil değeri seçilir: standart sapma yüksekse ortalama yanıltıcı olacağı için medyan, düşükse ortalama kullanılır. Aynı mantık bir evdeki IoT cihazları için de geçerlidir: cihazlar kendi aralarında haberleşip tek bir değer göndermelidir.
- Su altı akustik sensör ağlarında sinyalin taşındığı ortam havadan farklı olduğu için kırılım ve güç kaybı yüksektir, veri hızı düşer. Düğümler farklı derinliklere yerleştirildiği için kapsama gibi problemler üç boyutlu ele alınmalıdır; karada ise arazi uygunsa iki boyutlu modelleme yeterli olabilir.
- IoT'de veri hacmi büyük olduğu için paket başlığı küçük tutulmalıdır. MQTT ve CoAP (hoca bunları TCP ve UDP'ye benzetti) kullanılsa da literatürde hala alternatif aranmaktadır. Dijital unutma, cihazların topladıkları bilgiden nasıl kurtulacağı ve veri temizliğinin nasıl yapılacağı sorusudur; hoca bunun üzerinde daha fazla araştırma yapılması gerektiğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
