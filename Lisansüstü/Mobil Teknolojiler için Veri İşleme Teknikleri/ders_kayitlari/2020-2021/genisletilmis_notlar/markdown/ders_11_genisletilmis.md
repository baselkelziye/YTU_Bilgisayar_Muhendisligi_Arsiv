# Ders 11 Genişletilmiş Notu: Mobil Crowdsourcing ve Crowdsensing, Telsiz Algılayıcı Ağlara Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Akıllı Telefonlarda Enerji Tüketimini Ölçmek
- 2. Crowdsourcing ile Problem Çözme Süreci
- 3. Crowdsourcing Uygulamaları
- 4. Mobil Crowdsourcing Uygulamalarının Sınıflandırılması
- 5. Akıllı Telefonun Enerji Profili
- 6. SmartP2P
- 7. Kalabalıkta Senkronizasyon ve Sporda Veri Bilimi
- 8. Mobile Crowdsensing ve Teşvikler
- 9. Crowdsensing Problemleri
- 10. Problemlere Çözüm Yaklaşımları
- 11. Grup Seviyesi Teşvik ve Servis Teşvikleri
- 12. Mobil Crowdsourcing Ağlarının Genel Mimarisi ve Zorlukları
- 13. Uygulama Örnekleri
- 14. Telsiz Algılayıcı Ağlara Giriş
- Örnek Sorular

## 1. Akıllı Telefonlarda Enerji Tüketimini Ölçmek

Ders, mobil cihazlarda makine öğrenmesine dayalı bir uygulamanın enerji tüketimine ne kadar etki ettiği sorusuyla açıldı. Hocaya göre bir sınıflandırma uygulamasının enerji tüketimi tek bir yere bağlı değildir. Sensörden veri toplama, ön işleme (pre-processing), özellik çıkarımı (ortalama, medyan, standart sapma gibi istatistiksel özellikler) ve sınıflandırma algoritmasının kendisi ayrı ayrı enerji harcar. Bu bileşenlerin etkisini görmek, farklı sınıflandırıcılar, farklı özellik çıkarma yöntemleri, farklı ön işleme algoritmaları ve farklı sensörler denenerek mümkündür. Hoca buna bir de kural tabanlı (rule-based) yaklaşımı eklemeyi düşündüğünü söyledi: kural tabanlı çözümde birkaç `if` vardır, makine öğrenmesinde ise iş farklı bir hal alır. Sınıflandırıcının kendisini yazmak gerekmez; Weka gibi bir kütüphanedeki hazır sınıflandırıcılar kullanılabilir. Önemli olan karşılaştırılan senaryoların aynı şartlarda test edilmesidir.

### 1.1 Yazılımsal ve donanımsal ölçüm

Enerji ölçümü için donanım tabanlı ve yazılım tabanlı yöntemler vardır. Android'in kendi sunduğu araç Battery Stats'tir. Bu tür araçlarla çok kısa süre çalışan bir kodun yarattığı değişim görülemez. Bu yüzden iş uzun süre tekrar tekrar çalıştırılır; tekrar sonunda çıkan toplam miktar paylaşılır, ortalaması alınır ya da süreyle orantılı olarak verilir.

Hoca literatürde enerji ölçümü için yazılımsal çözümler öneren çalışmalar olduğunu, bunların bir APK'nın yüklenip belirli adımlarla ölçüm yapılması biçiminde işlediğini anlattı. Hocanın hatırladığına göre bu yazılımsal çözümler donanımsal ölçüme %1 ile %4 arası bir hata payıyla yakın sonuç verir; ancak her zaman uygulanabilir değildirler.

Donanımsal tarafta Monsoon (M-O-N-S-O-O-N) adlı bir cihaz vardır. Telefon bu cihaza bağlanıp konfigüre edilir ve cihaz enerji tüketimini doğrudan verir; ancak ayrıca satın alınması gerekir. iOS tarafında da çözümler vardır, fakat iOS'un kendi sunduğu araçların dışında sisteme müdahale şansı az olduğu için orası daha çetrefillidir.

### 1.2 Ölçümde eşit şartlar

Derste öğrencilerin soruları üzerine ölçüm koşulları tartışıldı.

**Soru:** Uygulama native olarak mı (C kütüphaneleriyle) geliştirilmeli? **Cevap:** SDK ile Android uygulaması yazılır, NDK kullanmak beklenmez. NDK ile daha performanslı sonuç görülebilir ama ayrı bir bilgi birikimi gerektirir. Java ya da Kotlin kullanılabilir; önemli olan aynı test ortamında eşit şartlarla test etmektir.

**Soru:** Uzun süren ağır işler ön yüzde bir thread ile mi, yoksa bir servis üzerinden mi çalıştırılmalı? **Cevap:** Hoca servisi zorunlu kılmadı. Ancak telefonların karar verme süreçlerinde doğal olanın, işin arayüze bağlı olmadan arka planda (servis olarak) çalışması olduğunu söyledi. Arka planda çalıştırmak ile uygulama açıkken çalıştırmak arasında enerji açısından ciddi fark vardır.

**Soru:** Testler için ADB üzerinden bir otomasyon kurup aktiviteyi tekrar tekrar başlatmak kabul edilir mi? **Cevap:** Test için kabul edilir; amaç yöntemlerin enerjiye etkisini ortaya koymaktır. Öğrenci bu yolla aktivitenin doğrudan başlatılıp kapatıldığını ve ölçüme etkisinin çok küçük olduğunu belirtti.

**Soru:** Telefonun sıcaklığı da incelenmeli mi? **Cevap:** Enerjiyle korele olduğu gösterilen bir metriği çalışmaya katmak iyi olur. İşin başlangıç ve bitiş sistem zamanı da kaydedilip enerji tüketimiyle ilişkisi gösterilebilir; sıcaklık için de aynı şey geçerlidir.

**Soru:** Testler telefon şarjdayken mi, pildeyken mi yapılmalı? **Cevap:** Öğrenci, arka plandaki enerji yöneticisinin (governor) şarj durumuna göre modunu tamamen değiştirdiğini ve bunun sonuçları belirgin biçimde etkilediğini söyledi. Hoca şartları eşit kılmak için ya hep şarjdayken ya hep şarjda değilken ölçüm yapılması gerektiğini, fırsat olursa iki durumun ayrı ayrı raporlanmasının sonucu daha güvenilir yapacağını belirtti.

> **Hocanın vurgusu:** Battery Stats olmasına rağmen Android'deki enerji tüketimini bilimsel bir çalışmada yayımlamak dikkat ister. Aynı kurulum ortamı korunmalı ve yukarıdaki özellikler gözetilmelidir.

## 2. Crowdsourcing ile Problem Çözme Süreci

Önceki derste crowdsourcing'in iki yaklaşımı (participatory ve opportunistic) ve dört uygulama kategorisi görülmüştü. Hoca geriye dönük toparlama yapmadan kaldığı yerden devam etti.

Bir problem çözülürken dört adımdan söz edilir: Intelligence, Design, Choice ve Implementation. İlk adımda fikirler toplanır. Tasarım adımında farklı noktalardan gelen fikirler birleştirilerek yaratıcı bir çözüm hedeflenir. Choice adımında bir karar alınacaksa çeşitli oylamalar yürütülür ve sonunda karar verilir. Bu, herhangi bir problemin çözümünde kullanılan genel bir mimaridir.

Crowdsourcing süreç akışı da buna benzer. Akış problemle başlar. Problemden görevler (task) oluşturulur ve bütün çözücülere dağıtılır. Her üye ilgili görevi ya da görevleri işler; üyeler aynı görevi de, aynı görevin farklı parçalarını da işleyebilir. Sonunda belirli bir veri üretilir ve geri gönderilir. Bir değerlendirme yapılır: görevlerden elde edilen bilgiler birleştirilir ya da aynı görevden dönen sonuçlar belirli bir filtreden geçirilir. Son olarak sonuç, problemi ortaya atan kişiye aktarılır.

Slaytta crowdsourcing araştırma konularının dört kategori altında sıralandığı bir tablo da vardı (ekrandan, 00:30:00). Görünen satırlar "Behavioral" (görev çeşitliliği, görev karmaşıklığı, görev ayrıştırma, kitlenin güveni ve motivasyonu, crowdsourcing'de hile vb.) ve "Technology and Systems" (platform seçimi, sistem mimarisi tasarımı, sosyal ağ ve yapay zeka kullanımı, fikir değerlendirme araçları vb.) başlıklarıydı. Hoca bu tablonun detayına girmedi.

## 3. Crowdsourcing Uygulamaları

Slayttaki uygulama listesi şöyleydi (ekrandan, 00:30:00):

- Waze ile kitle kaynaklı trafik izleme.
- VTrack2 ile yol trafiği gecikme tahmini.
- Kullanıcıların telefon mikrofonlarıyla topladığı veriden ayrıntılı gürültü haritaları (Ear-Phone3 ve NoiseTube4).
- Telefonların yakaladığı titreşim ve konum verisiyle yol çukurlarının tespiti (PotHole5).
- Coğrafi veri toplamayı amaçlayan konum tabanlı oyunlar (CityExplorer6) ve işbirlikçi trafik sinyali zamanlama tavsiyeleri (SignalGuru7).
- Wi-Fi erişim noktalarının sinyal gücünü kullanan gerçek zamanlı iç mekan konumlama (Airplace8).

Hoca trafik izlemede Yandex ve Google Maps'in bu mekanizmayı sıklıkla kullandığını, çukur ve yol bozukluğu tespitinin de bu kapsamda olduğunu hatırlattı.

### 3.1 Konum tabanlı oyunlar

Konum tabanlı oyunlarda crowdsourcing mekanizması sıklıkla devreye girer. Pokemon Go, artırılmış gerçekliği oyunlaştırıp konuma ve oyuncunun hareketine bağladığı için bir dönem çok popüler oldu. Hoca bunu akıllıca bir fikir olarak değerlendirdi: kapalı ortamda oyun oynamak yerine gezmeyi, yeni yerler görmeyi ve hareket etmeyi sağlıyordu. Bir öğrenci de haritadaki üsleri iki takımın ele geçirmeye çalıştığı bir oyunu anlattı; orada ödül maddi değildi ama oyuncular uzak noktalara gidip üs fethetmek için toplanıyordu. Hoca bu oyunun grup hareketine, Pokemon Go'nun ise kişisel puanlara dayandığını belirtti.

### 3.2 Denizde kapsama haritası

Karada baz istasyonu kapsaması büyük ölçüde sorun olmaktan çıkmıştır; asıl sorun aynı anda yüklenme olduğunda kapasite ve performanstır. Deniz üstünde ise durum farklıdır. Kıyıdan uzaklaştıkça yakında baz istasyonu olmadığı için bazı noktalarda telefon çekmez ve uydu haberleşmesi gerekir. Ege gibi yazın tekne trafiği yoğun bir denizde teknelerdeki telefonlardan alınan sinyal güçleri merkezi bir noktada toplanarak deniz haritası üzerinde hangi noktaların ne kadar iyi çektiği haritalanabilir. Bu, ani fırtına, karaya oturma, ada çevresinde sıkıntı ya da teknede yangın gibi durumlarda denizcilerin kendilerini konumlandırması açısından önemlidir.

### 3.3 Kuyruk bilgisi ve diğer örnekler

Hoca listede olmayan BlaBlaCar ve Airbnb gibi uygulamaları da andı. Havalimanında pasaport ya da havayolu kuyruğunun uzunluğunu gösteren bir uygulama ve market, otobüs, stat ya da konser girişi kuyruğunu bildiren başka bir uygulamadan söz etti. Normalde sıraya giren bir arkadaşın "gel, kalabalıklaşıyor" diye araması bu uygulamalarla crowdsourcing mantığına taşınmıştır. Öğrenciler navigasyon uygulamalarını ve Yandex'te kullanıcıların yol durumu hakkında yazdığı yorumları örnek verdi.

**Soru:** Yorum yazmak participatory mi, opportunistic mi? **Cevap:** Participatory. Opportunistic yaklaşım daha çok non-intrusive (müdahalesiz) çözümler için kullanılır: kişinin emek harcamadan, doğal yaptığı bir işten ya da cihazından gelen veriler. Kişinin geri bildirim vermek ya da veri toplamak gibi aktif olarak işin içinde olduğu durumlar participatory'dir. Bütün yorumlar participatory sayılır.

## 4. Mobil Crowdsourcing Uygulamalarının Sınıflandırılması

Slayttaki "Taxonomy of mobile crowdsourcing applications" tablosu uygulamaları şu boyutlarda karşılaştırıyordu (ekrandan, 00:35:00): Web-extend, Involvement, Data wisdom, Contribution quality, Incentives, Human skill, Sensors, Location.

| Uygulama | Web-extend | Involvement | Data wisdom | Contribution quality | Incentives | Human skill | Sensors | Location |
|---|---|---|---|---|---|---|---|---|
| Gigwalk.com | Y | Participatory | Individual | Heterogeneous | Monetary | Labor | Camera | Y |
| Jana.com | Y | Participatory | Individual | Heterogeneous | Monetary | Visual | X | Y |
| Crowd Translator | Y | Participatory | Collective | Homogeneous | Service | Visual | X | X |
| Waze.com | X | Both | Collective | Homogeneous | Ethical/service | Visual | Camera | Y |
| CityExplorer | X | Participatory | Collective | Homogeneous | Entertainment | Visual | Camera | Y |
| VTrack | X | Opportunistic | Collective | Homogeneous | Ethical/service | X | X | Y |
| SignalGuru | X | Opportunistic | Collective | Homogeneous | Ethical/service | X | Camera | Y |
| Ear-Phone | X | Opportunistic | Collective | Homogeneous | Ethical | X | Audio | Y |
| NoiseTube | X | Opportunistic | Collective | Homogeneous | Ethical | X | Audio | Y |
| PotHole | X | Opportunistic | Collective | Homogeneous | Ethical | X | Vibration | Y |
| AirPlace | X | Opportunistic | Collective | Homogeneous | Service | X | X | Y |
| SmartTrace | X | Opportunistic | Collective | Homogeneous | Service | X | X | Y |
| Crowdcast | X | Opportunistic | Collective | Homogeneous | Service | X | X | Y |
| SmartP2P | X | Opportunistic | Collective | Homogeneous | Service | X | X | Y |

Tablodan görülen genel eğilim şudur: insan emeği ve görsel beceri isteyen uygulamalar participatory ve çoğunlukla parasal teşviklidir; sensörden otomatik veri toplayan uygulamalar opportunistic, kolektif ve homojen katkılıdır ve teşvikleri etik ya da servis niteliğindedir. Waze her iki katılım biçimini de içerir.

## 5. Akıllı Telefonun Enerji Profili

Crowdsourcing'in bir parçası olmak enerji harcamak demektir. Yandex ya da İBB trafik uygulamasına belli periyotlarla konum bilgisi vermek, Google'ın arka planda topladığı hareket verileri (yürüyor musunuz, araçta mısınız) kullanıcıya bir maliyet getirir; bunların bir kısmı sözleşme imzalanırken onaylanır. Hoca bu maliyeti gösteren, biraz eski bir çalışmanın tablosunu paylaştı (ekrandan, 00:40:00):

| Temel telefon işlemi | Güç (mW = mJ/s) |
|---|---|
| CPU minimal kullanım (yalnız işletim sistemi) | 35 |
| CPU standart kullanım (hafif işlem) | 175 |
| CPU pik (ağır işlem) | 469 |
| Wi-Fi boşta (bağlı) | 34 |
| Wi-Fi konumlama (dakika ortalaması) | 125 |
| Wi-Fi pik (uplink 123 Kbps, -58 dBm) | 400 |
| 3G konumlama (dakika ortalaması) | 300 |
| 3G meşgul | 900 |
| GPS açık (sabit) | 275 |
| OLED ekonomi modu | 300 |
| OLED tam parlaklık | 676 |

Hoca CPU'nun en az kullanımda 35 mW harcadığını, standart kullanımda bunun 5 katına, ağır kullanımda yaklaşık 12-13 katına çıktığını söyledi. Tablodan hesaplanınca oranlar şöyledir (python ile doğrulandı):

- Standart / minimal: $175 / 35 = 5$
- Pik / minimal: $469 / 35 \approx 13{,}4$

GPS sabit açıkken 275 mW harcar; konum saniyede bir gibi sürekli sorgulanırsa yüksek enerji tüketilir. Ekran tarafında güneşli, açık havada parlak kullanılan ekran oldukça yüksek enerji tüketir: OLED tam parlaklıkta 676 mW, ekonomi modunda 300 mW'tır. <!-- BELİRSİZ: Hoca 00:39:45-00:40:09 arasında 3G, baz istasyonu ve Wi-Fi tüketimlerini karşılaştırdı ("yarısı kadar", "Wi-Fi görece daha düşük"); altyazı bozuk olduğu için hangi satırların karşılaştırıldığı net değil. Tabloya göre Wi-Fi pik (400 mW), 3G meşgulün (900 mW) yarısından biraz azdır. -->

> **Ders sonrası not:** Slayttaki sütun başlığında "Megawatts of power" yazıyordu; mW miliwatt'tır (megawatt değil). Hoca değeri "35 milivat" diye doğru okudu.

## 6. SmartP2P

Hoca "SmartP2P ne olabilir?" diye sordu. Bir öğrenci cihazlar arasında sunucusuz doğrudan iletişim olabileceğini söyledi. Hoca bunu doğru buldu ama bu tasarımda bir Optimizer sunucusuna ihtiyaç duyulduğunu ekledi.

### 6.1 Çalışma biçimi

Kullanıcı, telefonlardaki bir resim, dosya ya da video gibi bir nesneyi istemektedir. Amaç bu nesneyi, ağa üye olan kişi grubunun içinde kullanıcıya en yakın telefondan getirmektir. Bunun için Optimizer sunucusunda bir look-up table tutulur. Üye telefonların konum bilgileri de Optimizer'da saklandığı için kullanıcı her telefona tek tek sorgu atmaz. İstediği nesneyi Optimizer'a sorar; Optimizer en yakın telefonla konuşmasını sağlar ve gereken bilgiyi gönderir; kullanıcı nesneyi o telefondan indirir.

Slayttaki şema bu akışı adımlarla gösteriyordu (ekrandan, 00:45:00): (a) Query (telefondan Optimizer'a sorgu), (b) Optimization (PF), (c) Decision making, (d) QRT, (e) Search (P2P ağında arama), (f) Results of interest (sonuçların kullanıcıya dönmesi). Telefon ekranları SmartP2P, Query, PF & DM Query user, QRT ve Result diye etiketlenmişti.

SmartP2P'nin hedefleri slaytta üç maddeydi (ekrandan, 00:50:00):

- Arama sırasında enerji tüketimini en aza indirmek.
- Aramayı yürütürken sorgu cevap süresini en aza indirmek.
- Kullanıcı sorgusunun recall oranını en yükseğe çıkarmak.

### 6.2 Kullanım alanları

En güzel örneklerden biri konferanslardır. Konferansta onlarca fotoğraf ve video paylaşılır; bunlar buluta gider, katılımcılar da buluttan indirir. Bu çok maliyetlidir; işi yerelde halletmek daha akıllıcadır. Bu fikrin eski hali proxy sunuculardır: uzaktaki bilgi değişmediği sürece yakında bir kopyası tutulur. SmartP2P aynı yapıyı telefonlar için kurgular.

Afetlerde de karşımıza çıkar. Deprem gibi bir afette ses hatları muhtemelen çöker, veri hatları da bir süre sıkıntı yaratabilir. Bu durumda baz istasyonu ya da Wi-Fi erişim noktası olmadan telefonların birbiri üzerinden hop-by-hop haberleştiği ad hoc ağlar önemlidir. Çok uzun mesafelere aktarım yapılamaz, ama afet bölgesinde veriyi bir noktaya kadar çıkarmak yeterlidir; çünkü esas darboğaz olayın yaşandığı yerdedir. Statlar da benzer bir örnektir: maç günleri çevredeki baz istasyonları kapasite yoğunluğu yüzünden iyi servis veremez, ek mobil baz istasyonları getirilir. Ana sunucuya gitmeden etraftaki telefonlar üzerinden konuşmak faydalı olur.

Böyle bir kalabalığa katılmanın bir maliyeti vardır: telefon bir hop olarak kullanılır, gelen veriyi alıp iletir. Herkes buna açık olmayabilir; bu hizmetten faydalanmak isteyenler bunu kabul etmelidir.

## 7. Kalabalıkta Senkronizasyon ve Sporda Veri Bilimi

Bir öğrenci telefonlar arasında müzik paylaşarak konser havası yaratmayı amaçlayan bir uygulamadan söz etti; denendiğinde arada kesilmeler olduğunu, büyük ihtimalle bir optimizer bulunmadığını belirtti. Hoca da benzer bir örnek verdi: statlarda telefonlarla yapılan ışık gösterileri. Bir uygulama, kullanıcılar bağlandığında bütün telefonları senkronize edip iki saniyede bir, üç saniyede bir yakıp söndürerek statın tamamının gecikmesiz aynı koreografiyi yapmasını hedefliyordu. Bu konserler ve büyük etkinlikler için de geçerlidir. Basit görünse de aynı bölgedeki 5000 telefonu senkron tutmak gecikme problemleri yüzünden üzerine düşünülmesi gereken bir çalışmadır.

Hoca daha sonra crowd sensing'in sporda nasıl kullanılabileceğini sordu. Bir öğrenci kitle fonlamasını hatırlattı; hoca spor kulüplerinin crowdfunding kampanyalarını doğru buldu ama kendisinin sporcuya yönelik bir uygulamayı kastettiğini söyledi. Bir öğrenci sporcunun vücut verilerinin toplanıp diğer oyuncularla kıyaslanmasını önerdi. Hoca bunun sporda veri bilimi diye adlandırılan, artık profesyonel bir meslek hâline gelen alan olduğunu anlattı: yeni antrenman tekniklerinde sporcuların üzerine sensörler bağlanır, kas hareketleri, takım koordinasyonu, harcanan enerji ve laktik asit gibi bilgiler toplanır.

İkinci örnek daha basit ama öğreticidir. Bir tenis hocası iyi öğrencisinin kol hareketini ve vuruş stilini sensörlerle izleyip yeni başlayanların buna ne kadar yaklaştığını ölçebilir. Basketbolda topun elden çıkışı gibi atış tekniklerinde de herkes farklı atar; teorik bir atış öğretilir, ama bazen bambaşka bir stil yüksek isabet verir. Bu motor öğrenme hareketleri sensörlerle izlenerek yeni çalışmalar yapılabilir.

## 8. Mobile Crowdsensing ve Teşvikler

Mobile crowdsensing, crowdsourcing'den farklı olarak mobil cihazların üzerindeki sensörlerden bilgi toplanmasına odaklanır. Slayttaki tanım: mobil crowdsensing, sıradan akıllı telefon kullanıcıları gibi çok sayıda katılımcının, cihazlardaki ivmeölçer, jiroskop, pusula, mikrofon, kamera, GPS ve kablosuz ağ arayüzleri gibi zengin yerleşik sensörlerle çevrelerini algılamasını gerektirir (ekrandan, 00:55:00).

Bir kullanıcı neden bu sistemin parçası olur? Slaytta teşvikler iki liste halindeydi (ekrandan, 01:20:00):

- Entertainment, Service, Money.
- Başka bir çalışmada: Altruism, Enjoyment, Reputation, Service, Payment.

Hoca ilk listede eğlence, hizmet almak (bilgi verip karşılığında hizmet almak) ve paranın öne çıktığını anlattı. İkinci listedeki reputation (ün), para kazanmadan daha çok beğeni almak ya da bilinirliği artırmak için katkı yapanları anlatır; bu kişiler bunu bir şekilde paraya da dönüştürebilir. Hizmet örnekleri: trafik hizmeti alıp karşılığında veri paylaşmak, para karşılığında anket doldurmak, bir işletim sisteminin ya da yazılımın beta sürümünü kullanarak ücret ya da kredi almak (Google tarafında kredi kazanmak gibi).

## 9. Crowdsensing Problemleri

> **Hocanın vurgusu:** Crowdsourcing'de iş veriyi toplamakla bitmez. Veri toplandığı gibi kullanılırsa ciddi hayal kırıklığı yaratabilir.

### 9.1 Enerji

Hoca problemleri sorduğunda bir öğrenci kullanılan enerjinin fazlalığını söyledi: toplamda, o işe özel çalışan makinelere göre çok daha fazla enerji harcanır ve kayıp da çoktur. Hoca bunu doğru bir tespit olarak kabul etti: crowdsourcing'in parçası olan cihazların ya da kişilerin harcadığı fazla enerji bir problemdir.

**Soru:** Blockchain bir crowdsourcing ya da crowdsensing örneği sayılabilir mi? **Cevap:** Evet. Önceki derste de örnek olarak verilmişti. Dağıtık mekanizmalar kullanıldığı, güvenlik dağıtık olarak sağlandığı ve farklı kaynaklar olmadan blockchain devam ettirilemeyeceği için bir crowdsourcing uygulaması olarak görülebilir. Bir öğrenci, white paper aşamasında destekçi toplamanın doğrudan kitle fonlaması olduğunu da ekledi. Burada da bir enerji problemi vardır; hocaya göre dünyanın blockchain ile ilgili en büyük derdi budur: güvenilir bir yapı kurulurken çok enerji tüketen bir mimari oluşturulmuştur.

### 9.2 Güvenlik, gizlilik ve verinin güvenilirliği

Bir öğrenci en ciddi problemin güvenlik ve veri gizliliği, uygulama bazında ise verinin doğrulanabilir olması olduğunu söyledi. Hoca güvenliğin önemli olduğunu, ama en kritik konulardan birinin verinin güvenilirliği olduğunu vurguladı. Bir ürüne sahte yorum yazılırsa ürünü alan hayal kırıklığı yaşar. Bir otelin işletmecileri on yorum yazar, on yorum da arkadaşlarına yazdırır; otel 10 üzerinden 9,8 alır, fotoğraflar harikadır, ama gidildiğinde hiç de düşünüldüğü gibi değildir. Manipülasyon noktası açıktır ve bunu gidermenin yolları vardır.

**Soru:** Hedeflenen kitlenin dışından veri toplanması da bir problem midir? Örneğin gençlere yönelik bir uygulamaya yaşlılar da katılırsa toplanan veri yanlış olur. **Cevap:** Evet. Uygulamada "bu yaş grubu görüş paylaşsın" diye yazılsa bile bunun kontrolü çok zordur. Ancak e-Devlet gibi güvenilir bir merkez ya da sertifika üzerinden giriş yaptırılırsa, kişi kimlik numarasıyla girmek zorunda olduğu için kontrol şansı doğar.

Slayttaki problem listesi (ekrandan, 01:30:00): Imbalanced data, Unreliable data, Malicious data, Unbalanced crowd, Lack of crowd.

### 9.3 Imbalanced data

Dengesiz veri, verinin bir tarafta yoğunlaşmasıdır. Bir öğrenci zamana bağlı örnekleri verdi: bir olayın sabah gerçekleşme olasılığı daha yüksekse veriler sabaha yığılır, akşam daha az örnek olur. Hoca trafik örneğini verdi: bazı lokasyonlardan çok az araç geçer, bazı lokasyonlardan belli saatlerde çok sık araç geçer. Oralarda veri yığılır, diğer yerlerde eksik veri olur. Hocaya göre yığılmanın kendisi büyük bir problem değildir, asıl büyük problem verinin eksik üretilmesidir; ayrıca veri dengesizliğinin karar verme aşamasında yarattığı sorunlar da bilinmektedir.

### 9.4 Unreliable data ve malicious data

Hoca ikisinin farkını sordu. Bir öğrenci malicious data'yı sistemi yanıltmak için kasıtlı olarak yanlış verilmiş veri diye tanımladı. Bir başkası birinde güvenilirlik (reliability), diğerinde güvenlik (safety) sorunu olduğunu söyledi. Hoca ayrımı şöyle yaptı: malicious data, kalabalığın bilinçli ve kasıtlı olarak sistemi yanıltmaya yönelik ürettiği bilgidir. Unreliable data'da kasıt yoktur, üretilen verinin hatalı olma ihtimali vardır. Örneğin bir sensör hatalı değer üretebilir; yer çekimi için 9,81 civarında değer üretmesi gereken bir telefon ivmeölçerinin 8,81 civarında değer üretmesi o sensörün güvenilir olmadığını gösterir. Ya da bir kullanıcı bir ürün hakkında kasıtsız ama konuda uzman olmadığı için güvenilmez bir yorum yapabilir. Bunu algılamanın çözümleri vardır.

### 9.5 Unbalanced crowd

Bir öğrenci genç nüfusun kullanımda ağırlıkta olmasını örnek verdi. Hoca bunu doğru buldu: burada sorun üretilen verinin dengesizliğinden çok, veriyi üretecek kalabalığın (crowd) dengesiz olmasıdır. İkisi farklıdır: imbalanced data'da verinin dengesiz üretilmesi, unbalanced crowd'da katkı sağlayacak grubun dengesiz dağılımı söz konusudur. Bir bölgede yaşayanların çok, kırsalda yaşayanların az olması da bu kapsamda düşünülebilir. Bir öğrencinin verdiği, belli bir bölgede ya da ortamda yapılan anket çalışmaları örneğini hoca çok doğru buldu.

### 9.6 Lack of crowd

Kalabalığın olmaması da bir problemdir: bir ürüne hiç yorum girilmemesi, bir lokasyona hiç gidilmemesi. Bir öğrenci yaygınlaşma sorunlarının buna yol açtığını, insanlarla temasın az olduğu her noktada bunun görülebileceğini söyledi. Hoca, kaynakların ya da insanların az olduğu her noktanın problem olduğunu ekledi. Kırsal bölgelerden veri toplama olasılığı daha düşüktür; çünkü orada az sayıda insan vardır ve kaynak da oraya o kadar akmaz.

Bu durum konum doğruluğunu da etkiler. Telefonun konumu en az üç baz istasyonundan gelen sinyal gücü üzerinden üçgenleme mantığıyla hesaplanır. Kilometrelerce baz istasyonu olmayan bir yerde ya veri toplanamaz ya da kullanıcının daha geniş bir aralıkta olduğu tahmin edilir ve doğruluk (accuracy) düşer.

> **Ek bilgi (derste anlatılmadı):** Sinyal gücünden mesafe tahmin edilip en az üç referans noktasına olan mesafelerle konum bulunmasına teknik olarak trilaterasyon denir; açı ölçümüyle yapılan yönteme ise triangulation (üçgenleme) denir. Günlük kullanımda ikisi sıklıkla "üçgenleme" diye anılır.

## 10. Problemlere Çözüm Yaklaşımları

### 10.1 Kimlik doğrulama

Bir öğrenci e-Devlet ile oturum açılan uygulamaların hem malicious data'yı hem de dengesiz kitle sorununu çözmeye yardım edebileceğini, örneğin belli bir orandan sonra belli bir yaşın üstündekilerin sisteme alınmayabileceğini söyledi. Hoca, e-Devlet gibi kontrollü mekanizmalar üzerinden veri toplamanın ya da oradan bir giriş mekanizması kurmanın doğru bir bağlantı olduğunu belirtti.

Airbnb'nin yaklaşımı sorulduğunda bir öğrenci, insanların genelde değerli tek bir cep telefonu numarası olduğunu ve doğrulamanın bunun üzerinden yapıldığını söyledi; e-posta daha kolay manipüle edilebilir. Hoca kimlik doğrulamanın tarihsel evrimini özetledi: önce istenen kullanıcı adı verilebiliyordu, sonra e-posta adresi kullanılmaya başlandı, şimdi cep telefonu bilgisi kullanılıyor. Bir kişinin en fazla birkaç telefon numarası olacağı için bir kişinin beş hesap açması gibi sorunların önü kısmen kesilmiştir.

### 10.2 LoA (Level of Assurance)

Hoca LoA, yani güvence seviyesi kavramını tanıttı. OTP mesajlarıyla bir siteye giriş bilinen en kolay yöntemlerden biridir ve SMS ile yürür. Bunun LoA 2, LoA 3 ve LoA 4 seviyeleri vardır.

**Soru:** Bu, iki faktörlü (two-factor) kimlik doğrulamayla aynı şey mi; üç ya da dört faktör mü demek? **Cevap:** Aynı anlama gelmez. İki faktörlü doğrulama kimlik doğrulamanın başka bir mimarisidir. Burada doğrulama giderek cep telefonu üzerinden sağlanır hale gelmiştir ve gidilen yön SIM kart üzerinden doğrulamadır.

SIM kartı manipüle etmek, akıllı telefonun yazılımını manipüle etmekten daha zor bir işlemdir. Operatörlerin LoA 4 (ve LoA 3) üzerinde çalışan servisleri vardır: kullanıcı, operatörlerin üye olduğu bir servise bağlanır, telefonuna SIM kart düzeyinde şifrelenmiş bilgi gelir ve bunu onaylayarak alışveriş sitelerine, ileride bankalara ve operatör sayfalarına giriş yapar. Bir öğrencinin sorduğu, bir operatör uygulamasında SMS yerine açılan onay penceresi hakkında hoca bunun Mobile Connect servisi üzerinden yürüdüğünü, o servisin LoA 4 olup olmadığından emin olmadığını ama büyük ihtimalle SIM kartı kullandığı için OTP'den daha güvenli olduğunu söyledi. OTP SMS ile havadan (over the air) gittiği için mesajdaki bilginin ele geçirilme ihtimali her zaman vardır. Hoca mobil güvenliğin giderek önem kazandığını ve bu alanda bilgili kişilere ihtiyaç olduğunu ekledi.

### 10.3 Kimliği doğrulanmış kullanıcının yanlılığı

Hoca asıl üzerinde durmak istediği noktaya geçti: kişi telefonuyla kendini doğrulasa bile otelin sahibini tanıyor ya da ürünü satan firmada çalışıyor olabilir ve en iyi niyetle bile yüksek puan verebilir. Mevcut yapılar bunu nasıl dengeler?

**Soru:** Bu yanlılık nasıl dengelenir? **Cevap (öğrencilerden ve hocadan):**

- Bazı sistemlerde ürün satın alınmadan yorum yapılamaz; satın almadan sonra belli bir süreye kadar yorum açıktır. Bazı otel sitelerinde de otelde kalmadan puan verilemez. Hoca bunu bir doğrulama (verify) mekanizması olarak kabul etti.
- Kullanıcının da bir puanı olabilir: beş otelde kalmış biri daha güvenilirdir. Hoca, kullanıcının ne kadar çok yerde kaldığının onun ağırlığını (weight) artırdığını söyledi. Ama bu yetmez, kullanıcının yorumlarına da bakmak gerekir: her yere 10 veren ya da her yere 2 veren bir kullanıcı ya aşırı iyimserdir ya da hiçbir şeyden memnun olmaz. Bir şey eksik diye her şeyi güzel bulduğu otele 6 veren kullanıcı örneği de verildi.

> **Hocanın vurgusu:** Bu mekanizmalar teknik görünmeyebilir, ama crowdsourcing sistemi kurarken çok iyi hesaplanıp uygulanmaları gerekir; kullanıcının kurulan sisteme olan güveni çok önemlidir. Ne kadar çok kullanıcı oyladıysa, oylayan kullanıcı ne kadar çok oylama yaptıysa ve veri dağılımı ne kadar genişse güvenilirlik hakkında o kadar net şey söylenebilir.

### 10.4 Verinin güncelliği ve toplu manipülasyon

Hoca verinin güncelliğinin neden kritik olduğunu sordu. Bir öğrenci, bir yerin zamanla değişebileceğini söyledi: önceden çok iyi olan yer kötüleşebilir, kötü olan iyileşebilir. Başka bir öğrenci yorum mekanizmasının çöktüğü bir noktaya dikkat çekti: Google Play'de bazı kullanıcılar "görünsün diye bir yıldız verdim" yazıp aslında uygulamayı övüyor, bu yorum çok yararlı bulunarak üste çıkıyor ve sistem uygulamayı kötü sanıyor. Bir başka öğrenci de bir topluluğun bir uygulamaya toplu olarak düşük puan verip ortalamasını düşürmesini örnek gösterdi; bu kullanıcılar gerçek olduğu için veri ayıklanamaz.

Hoca bunun artık ülkeler ve firmalar arasında bir savaşa dönüştüğünü, fanatizmin de işe girdiğini söyledi. Kullanıcılar sosyal medyada birçok şeyi etkileyebildiklerini gördükleri için belirli ortak hareketler oluşur; bu ortak hareketler akıllı algoritmalarla incelenip filtrelenerek bir puanlama mekanizmasına gidilecektir. Risk sıfırlanamaz ama her gün yeni çözümler çıkmaktadır. Güncellik için de farklı puanlar ve kategoriler olmalı, değerlendirmeler zaman içinde takip edilmelidir. Hoca film, müzik, restoran ve etkinlik gibi bütün kategorileri puanlatan yeni bir girişimi crowdsensing'in ruhuna birebir uygun bir örnek olarak andı.

Slaytta ayrıca crowdsensing oyunlarını listeleyen bir tablo vardı (ekrandan, 01:40:00): Treasure ve Feeding Yoshi (belirli alanların Wi-Fi kapsamını incelemek), Tycoon ve Hitchers (GSM hücrelerinin kapsamını değerlendirmek), GeoTicTacToe ve CityPoker (önceden belirlenmiş alanlar için GPS izleri toplamak), Ostereiersuche (yapısal yer işaretlerini belirlemek), CityExplorer (konum tabanlı servis için coğrafi veri üretmek), BudBurst Mobile (iklim değişikliği eğitimi ve veri toplama), EyeSpy (tanınabilir ve bulunabilir konumlar hakkında bilgi üretmek). Hoca bunların şu an kritik olmadığını söyledi.

## 11. Grup Seviyesi Teşvik ve Servis Teşvikleri

### 11.1 Grup seviyesi teşvik

Daha önce bireysel teşvikler görülmüştü: para kazanmak, servis almak, eğlenmek, ün kazanmak. Hoca bunların grup seviyesinde nasıl uygulanabileceğini sordu. Öğrencilerden "arkadaşını getir" kampanyaları ve bölgeler arası yarışmalar gibi öneriler geldi; hoca bunların tam olarak kastettiği şey olmadığını söyledi.

Grup seviyesi teşvik, bir servise ya da crowdsourcing uygulamasına grup olarak katılmak, grup olarak bilgi sağlamak ve grup olarak yararlanmaktır. Slayttaki şemada User 1-3 Group A'da, User 4 Group B'de, User 5-8 Group C'de yer alıyor ve hepsi bir "Credit database"e bağlanıyordu (ekrandan, 01:40:00 ve 01:45:00).

Hocanın örneği bir aile ve bir park uygulamasıdır. Bir kişi park yerinden ayrılırken konum bilgisini paylaşır; sisteme katkı verdiği için daha sonra boş park yeri ararken sistemden bilgi çekebilir. Ailenin bir üyesi işi gereği gün içinde çok gezip beş kez katkıda bulunmuş olsun. Ailenin başka bir üyesi bir yere gittiğinde bu kişinin kredilerinden yararlanabilir. Böylece "ben katkı yaparsam yakınım da faydalanacak" düşüncesiyle katkı artar, birikim daha hızlı büyür ve hizmet daha fazla kişiye ulaşır. Bir öğrenci bunu müzik ve video platformlarının aile ya da grup aboneliklerine benzetti; hoca bunu güzel bir benzetme olarak kabul etti ve uygun bir iş modeli kurulabilirse crowdsourcing çözümünde bu yaklaşımı kullanmakta fayda olduğunu söyledi.

### 11.2 Servis teşvikleri

Slayttaki "Sensing Tasks with Service Incentives" tablosu (ekrandan, 01:45:00):

| Sensör türü | Algılama servisi |
|---|---|
| genel | iki teşvik mekanizması: biri kullanıcı adaletini, diğeri sosyal refahın en büyüklenmesini gözetir |
| GPS | sürücülere uygun park bilgisini (ne zaman, nerede) sağlar |
| video kamera | mobil gözetim videoları ve veri iletim servisi sağlar |
| yok | yerel dildeki metni sayısallaştırır |
| kamera | ürün fiyatı paylaşım servisi sağlar |
| kamera, GPS, mikrofon | yeme alışkanlığı karşılaştırma ve öneri servisi sağlar |
| genel | kablosuz sensör ağlarında farklı türde veri toplar |

### 11.3 Duty free fiyat paylaşımı örneği

Hoca ürün fiyatı paylaşım servisine kendi sevdiği bir örnekle değindi. Sık yurt dışına çıkan biri çikolata, parfüm, kozmetik gibi ihtiyaçlarını duty free'den alıyorsa en büyük sorusu şudur: ürün gittiği havalimanında mı, döneceği havalimanında mı, yoksa aktarma yaptığı havalimanında mı daha ucuz? Aradaki fiyat farkları büyük olabilir, ama duty free'lerin kapsamlı bir fiyat paylaşma mekanizması yoktur. Çözüm crowdsourcing'dir: dünyada gezen her kişi uğradığı duty free'de bir ürünün fiyatını paylaştıkça kredi toplar, karşılığında istediği bölgedeki ürünün fiyatını görebilir. Böylece herkes her havalimanındaki ürünler hakkında fikir sahibi olur ve daha uygun alışveriş yapar.

Bir öğrenci benzer bir fikri tarım ürünleri için anlattı: tarladan çok düşük fiyata çıkan bozulabilir bir ürün tüketiciye gelene kadar katlanarak pahalanır; üreticilerin katıldığı bir sistemle aracılar azaltılabilir. Hoca bunun bir türevinin bugün küçük e-ticaret firmalarının ürünleri uygun temin edip kargo firmalarıyla doğrudan göndermesi biçiminde yaşandığını söyledi.

Hoca bir başka örnek olarak market fişi projesini anlattı. Kullanıcılar fişlerini telefonla okutur; fişteki ürünler, fiyatlar, hangi marketten ve hangi lokasyondan alındığı veritabanına kaydedilir. Kullanıcı alışveriş listesini girdiğinde hangi ürünü hangi marketten almanın en uygun olduğu, lokasyon bazlı olarak birden fazla market önerisiyle birlikte otomatik çıkar. Hocanın aktardığına göre bu yolla alışverişte en az %20 civarında tasarruf sağlandığı gösterilmişti.

### 11.4 Parasal teşvik modelleri

Anket gibi işlerde parasal teşvik birkaç biçimde uygulanır: tamamlanan her soru için eşit miktar ödemek, her soru için farklı miktar ödemek, ya da farklı miktar ödeneceğini söyleyip miktarı anket bitince açıklamak. Yani bir modelde katılımcı soruyu ve ücretini görür, diğerinde görmez. Slayttaki başlıklar arasında parasal teşvikler için Online Mechanism Design, Task Assignment, Quality Control ve Privacy Tradeoff yer alıyordu (ekrandan, 01:50:00).

## 12. Mobil Crowdsourcing Ağlarının Genel Mimarisi ve Zorlukları

Slayttaki "General Architecture of MCN" şemasında (ekrandan, 01:50:00) en üstte bir service provider (bulut) vardı. Son kullanıcılar (end users) ona request gönderir ve result alır. Service provider katmanında task decomposition, task recommendation, distribution, recomposition ve storage işlevleri bulunur. Altta iki kalabalık vardır: sensing crowd (giyilebilir cihazlar, akıllı araçlar, akıllı telefon kullanıcıları) ve computing crowd (akıllı araçlar, telefon kullanıcıları ve laptop kullanıcıları). Bunlar RSU'lar (yol kenarı birimleri), hücresel baz istasyonları ve Wi-Fi erişim noktaları üzerinden service provider'a bağlanır. Algılama yapan bir katılımcı da, hesaplama gücü veren bir katılımcı da bu yollarla sisteme katılır.

Hoca mimarinin sorunlarını şöyle sıraladı:

- İşin içinde insan olması manipülasyonu getirir; bu büyük bir sorundur.
- Task crowdsourcing: kullanıcılara görev verilir (Pokemon Go'daki gibi). Sorun, bu görevlere talip olacak kişi bulunup bulunmayacağıdır. Kullanıcı paylaşım yapar ama bazı görevlerin karşılığı ona dönmeyebilir. Sistemin yürümesi için kullanıcıyı sürekli motive edip içeride tutan bir yapı gerekir; kalabalığın sayısı düştükçe problem büyür.
- Dinamik topoloji: katılımcılar sürekli girip çıkar, katılım durumu sürekli değişir.
- Heterojenlik: bilginin farklı kaynaklardan, mümkün olduğunca çeşitlendirilerek toplanması sistemin güvenilirliğini artırmak için önemli bir zorluktur.

## 13. Uygulama Örnekleri

Slayttaki "Application examples of mobile crowdsourcing networks" tablosu (ekrandan, 01:55:00):

| Uygulama | Açıklama |
|---|---|
| Air pollution | Fabrikaların, araçların ve çiftliklerin yaydığı hava kirliliğini tespit etmek |
| Water quality | Su kalitesini izlemek ve içilebilirliğini incelemek |
| Levels | Baz istasyonlarının ve Wi-Fi yönlendiricilerinin yaydığı enerjiyi ölçmek |
| Smart navigation | Hava durumu, kaza ve trafik sıkışıklığına göre rota planlamak |
| Smart parking | Şehirdeki park yeri durumunu izleyip ücretleriyle önermek |
| Smart traffic light | Trafik ışıklarını trafik yüküne ve ortaya çıkan olaylara göre kontrol etmek |
| Health monitoring | Kalp atışı, EKG, tansiyon vb. ile sağlık durumunu izlemek |
| Disease diagnosis | Kişisel sağlık parametreleri ve diğer vakalardan hastalık teşhis etmek |
| Food recommendation | Kişisel sağlık durumuna göre yiyecek ya da içecek önermek |

### 13.1 Akıllı trafik ışığı

Hoca en çok ilgilendiği konulardan birinin akıllı trafik ışığı olduğunu söyleyip bunun şehirde uygulanıp uygulanmadığını sordu. Bir öğrenci, sağ cepte araç beklemedikçe yanmayan bir ışık gördüğünü söyledi. Başka bir öğrenci, trafiğin sabah bir yöne akşam diğer yöne yoğunlaştığı yollarda orta refüjün sabit olmaması, örneğin sabah gidiş yönüne dört şerit verilip akşam azaltılması fikrini anlattı. Hoca bunun bir köprüde dubalar elle kaydırılarak uygulandığını, ancak ciddi maliyet gerektirdiğini, kaydırma teknolojisi ya da alttan çıkan bariyerler gerektiğini, bunun da yolu bir nevi raylı sistem altyapısına çevirmek demek olduğunu ve güvenlik endişeleri bulunduğunu söyledi. Bir öğrenci yurt dışında büyük bir otoyolda zincir şeklindeki bariyerin özel bir araçla kaydırılarak şeritlerin değiştirildiğini gördüğünü aktardı.

Trafik ışığına dönülünce hoca dinamik trafik ışığı yönetimini henüz hayatımızda çok görmediğini söyledi. Burada bir ödünleşim (trade-off) vardır. Işıklarla çok oynanır, süreler çok dinamik yapılırsa trafiğin akışkanlığı bozulur. Standart hızda (60-70 km/sa) giden bir araç yeşil dalgada bir ışıktan geçince diğerlerinden de geçer; süreler değiştirilirse bu bozulur ve daha çok yakıt tüketilebilir. Ama gece saatleri gibi trafiğin azaldığı ya da çoğaldığı zamanlarda dinamik ayar uygulanabilir. Hoca bu konunun ileride hayatımıza daha çok gireceğini düşünüyor.

**Soru:** Yeşil dalga yıllardır kullanılıyor; bu akıllı ışık sayılır mı? **Cevap:** Hayır. Yeşil dalga, güvenliği artırdığı ve yakıt tüketimini düşürdüğü için mevcut çözümler içinde en sık kullanılanıdır; ama sabit bir programdır. İçinde öğrenme yoktur, trafik karakteristiğini anlık değerlendirmez. Gece belli saatten sonra sarıya dönmek de periyot ayarıdır.

### 13.2 Sağlık izleme

Sağlık izleme alanında çok çalışma yapılmaktadır ve artacaktır. Farklı kişilerin daha önceki semptomlarından risk izlemek önemlidir. Hoca COVID verilerinin tıpçılar arasında crowdsourcing mantığıyla paylaşılmasının aşı ve tedavi yöntemlerinin gelişmesine katkı sağladığını söyledi. Bir öğrenci, özellikle yaşlılar için evdeki sensörlerle sağlık durumunun ölçülüp hastalıkların önceden önlenebileceğini söyledi; hoca bu konuda Avrupa Birliği projeleri bulunduğunu ekledi. Bir öğrenci de mahalle bazında düzenli ölçümlerle bir salgının başlayıp başlamadığının tahmin edilebileceği fikrini anlattı. Hoca, hastane otoparklarının doluluğuna bakarak hastane yoğunluğu çıkaran çalışmalardan ve virüsün yeni varyantlarını izlemek için DNA dizilimlerine bakılmasından söz etti.

Hoca konuyu tahminleme (forecasting) ile bağladı: vaka sayısının ertesi gün kaç olacağını hesaplamak, finansta borsanın destek ve direnç noktalarını tahmin etmek, tweetlerden döviz kurunun seyrini tahmin etmeye çalışmak birer forecasting problemidir. İnsanın en çok merak ettiği şey gelecekte ne olacağını bilmektir. Meteoroloji bu işe en başta başlamıştır ve hocaya göre bugün en az iki hafta için iyi tahmin yapılabilmektedir; trafikte de aynısı yapılmaya çalışılmaktadır. Yemek önerisi konusunda da çalışmalar vardır, ancak biraz geri plandadır.

Son olarak slaytta "Security and Privacy Challenges" başlığı altında Privacy Threats ve Reliability Threats maddeleri vardı (ekrandan, 02:05:00). Hoca bu kısma vakit ayırmadan slaytı paylaşacağını söyledi.

## 14. Telsiz Algılayıcı Ağlara Giriş

Dersin son bölümünde hoca telsiz algılayıcı ağlara (wireless sensor networks) geçti. Ekranda bir telsiz algılayıcı ağlar dersinin uygulama katmanı slaytları açıktı (ekrandan, 02:30:00); anlatım ise büyük ölçüde sözlüydü. Türkçede kablosuz algılayıcı ağlar ya da genellikle telsiz algılayıcı ağlar diye adlandırılır. Askeri uygulamalarla başlayan bu konu, bugün IoT'ye gelinen noktanın başlangıcı kabul edilebilir.

### 14.1 Düğümler ve yerleştirme

Üzerinde işlemcisi, haberleşme birimi ve algılama birimi olan düğümler (node) ortama elle yerleştirilir ya da helikopter, uçak veya mancınıkla saçılır ve etraftan bilgi toplar. Kullanım alanları bitkileri gözleyip verimliliklerini artırmak, hayvanlar hakkında bilgi toplamak ve askeri operasyonlarda en az kayıpla ortam bilgisi edinmektir. Düğümler özellikle açık ve ulaşılması zor alanlara dağıtılır.

Düğümler sabit olabilir, kendi etrafında dönebilir ya da bir yerden bir yere hareket edebilir. Hareket, hem enerji hem de düğümde kullanılan bileşenler açısından çok maliyetlidir. Bu yüzden statik düğümler tercih edilir: hem ucuzdur hem de hareket etmediği için enerji harcamaz. Ancak statik düğümlerin yerleştirmede bir handikapı vardır: aynı bölgeye düşen düğümler hemen hemen aynı alanı algılar ve aynı alanla haberleşir. 100 düğüm atılan bir yerde belki ancak 20-30 düğüm kapsama alanını etkin biçimde büyütür.

### 14.2 Kapsama ve algılama modelleri

İki tür kapsama alanı vardır:

- Algılama (sensing) kapsaması: düğümün algılayabildiği mesafe.
- Haberleşme (communication) kapsaması: iki düğümün birbiriyle haberleşebildiği mesafe.

Algılama mesafesi genelde haberleşme mesafesinden kısadır; aralarında genelde bire iki oran vardır.

Algılama yönüne göre iki tür vardır. Omnidirectional (yönsüz) algılamada 360 derece algılanır. Directional (yönlü) algılamada bir kameranın bakış açısı gibi bir pasta dilimi algılanır; mikrofon için de aynısı geçerlidir.

Algılama modeli olarak iki model anılır. Binary sensing'de bir nokta ya algılanır ya algılanmaz (0 ve 1). Probabilistic sensing'de ise kesin bir sınır yoktur.

**Soru:** Probabilistic sensing nasıl bir sonuç üretir? **Cevap:** Bir öğrenci ortamdaki gürültüyü ve belirsizlikleri modellediğini, sonucun bir olasılık dağılımı olduğunu söyledi. Hoca, mesafe uzaklaştıkça algılama olasılığının düştüğünü, en yakın noktalarda 1 iken sonra 0,9, sonra 0,8 diye devam ettiğini ve belli bir mesafeden sonra dramatik biçimde düştüğünü anlattı. Bu model daha gerçekçidir, ama bilimsel çalışmalarda genelde 1-0 mantığı kullanılır. Örneğin bir kameranın ya da pasif kızılötesi sensörün hareketi algılaması ortam şartlarına bağlıdır; sınır her zaman keskin değildir.

### 14.3 Kapsama problemleri

Bu modeller kapsama (coverage) problemini çözmek için kullanılır. Hocaya göre kapsama düzgün sağlanamazsa sensör ağlarının anlamı kalmaz. Üç temel kapsama yaklaşımı vardır:

- Area coverage: hedef, en büyük alanı kapsamaktır.
- Target coverage: verilen hedeflerden en fazla sayıda hedefi kapsamaktır; alandaki her noktayı kapsamak gerekmez.
- Border coverage: bir bölgeye giriş ya da çıkış yapılıp yapılmadığını algılamaktır. Bütün alana sensör yerleştirmek yerine sensörler bir hat boyunca dizilebilir.

Border coverage'ın dezavantajı, en sık sorulan soruyla özetlenir: biri paraşütle inerse bu nasıl kapsanacak? Sensör ağlarında kapsama problemleri bugüne kadar ağırlıklı olarak 2D çözülmüştür; artık 3D kapsama problemleri popüler hâle gelmiştir. Böylece giriş-çıkış yalnız yeryüzünde değil, havadan yaklaşan araçlar için de izlenebilir. Hoca dronların konumlandırılması ve birlikte hareketi (cooperation) üzerine de son dönemde ciddi çalışmalar olduğunu ekledi.

### 14.4 Ağ türleri ve protokol

Farklı sensör ağı türleri vardır: underwater acoustic sensor networks, multimedia sensor networks gibi. Multimedia sensör ağlarında ağırlıklı olarak ses ve görüntü taşınır; bu, sıcaklık ya da nem gibi fiziksel değerler taşımaktan çok farklıdır. Yönlendirmeden (routing) topolojiye kadar farklı çözümler gerekir. Sensörler küçük cihazlar oldukları için iletim kapasiteleri ve bant genişlikleri düşüktür; enerjileri çabuk bitmesin diye farklı protokoller kullanılır.

**Soru:** Sensör ağları hangi protokolü kullanır? **Cevap:** Bir öğrenci MQTT dedi; hoca MQTT'nin daha çok IoT tarafında kullanıldığını, sensör ağlarında haberleşme için ZigBee'nin (IEEE 802.15.4) kullanıldığını söyledi. Bant genişliği oldukça sınırlıdır, ama enerji tüketimi de o oranda azdır.

> **Ek bilgi (derste anlatılmadı):** IEEE 802.15.4 düşük hızlı kablosuz kişisel alan ağları için fiziksel ve MAC katmanını tanımlayan standarttır; ZigBee bunun üzerine ağ ve uygulama katmanlarını ekleyen protokol yığınıdır. Bu yüzden ikisi sıklıkla birlikte anılır.

### 14.5 Ağ ömrünü uzatmak

Sahaya atılan sensörleri yenilemek ve yeniden yerleştirmek (redeployment) kolay değildir. Bu yüzden düğümler ve bilgi akışı, ağ ömrünü (network lifetime) en uzun tutacak şekilde tasarlanmalıdır. Hoca, ağın ayakta kalmasının düğümlerin ayakta kalmasına bağlı olduğunu varsayarak neler yapılabileceğini sordu:

- Fiziksel koruma: düğümlerin zarar görmeyecek biçimde korunarak bölgeye atılması.
- Enerjiyi verimli kullanmak.
- Enerji hasadı (energy harvesting): sensörün enerjiyi güneş, rüzgar, su ya da basınç değişimi gibi farklı kaynaklardan elde etmesi. Hoca gönderilen bir dalganın gücünün bile dönüştürülüp sensöre enerji aktarılabileceğini, ama bunların pratikte kullanımının kolay olmadığını ve farklı tasarımlar gerektirdiğini söyledi.
- Uyku ve uyanma: düğümlerin belli periyotlarda uyuyup belli periyotlarda uyanması. Uyanma zaman dilimleri (slot) ile düzenlenebilir. Bilgi gönderecek düğüm, alıcının uyanık olduğu periyotta ona bir sonraki turda veri göndereceğini bildirebilir.
- Veriyi düğümde işleyip ham veri yerine yalnız önemli olanı ya da yalnız bir olay (action) olduğunda veri göndermek (öğrenci önerisi; hoca bu noktaya ayrıca geleceğini söyledi).

**Soru:** Sensörün uyutulması veri kaçırmaya neden olmaz mı? Uyurken bir olay olup olmadığı bilinemez. **Cevap:** Burada farklı çözümler vardır. Etrafı izlemek (algılamak) ile haberleşmek birbirinden bağımsızdır. Sıcaklık topluyorsanız, yangınla ilgili bir gelişmeyi 30 saniye ya da 1 dakika önce algılamak çok şey değiştirmez, aralık açılabilir. Ama bir düşman giriş-çıkışı gözleniyorsa düğüm bu kadar uzun süre uyutulamaz.

> **Hocanın vurgusu:** Sensör ile sensör düğümü farklı şeylerdir. Düğüm bütün birimleri içerir; sensör düğümün bir parçasıdır ve bir düğüm üzerinde birden fazla sensör olabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:37:23): Bir ürüne ya da otele yorum yazmak participatory mi, opportunistic crowdsourcing mi sayılır? Neden?

> **Çözüm (derste verildi):** Participatory. Kişi geri bildirim vermek için aktif olarak işin içindedir. Opportunistic yaklaşım, kişinin emek harcamadan doğal hareketinden ya da cihazından gelen veriler için kullanılır.

**Soru 2** (derste sözlü, 00:40:59; ekrandan, 00:45:00): SmartP2P nedir, Optimizer sunucusu ne işe yarar?

> **Çözüm (derste verildi):** Telefonlar arası paylaşımda istenen nesneyi en yakın telefondan getiren bir mimaridir. Optimizer, üye telefonların konumlarını ve sahip oldukları nesneleri bir look-up table'da tutar; kullanıcı her telefona sorgu atmadan Optimizer'a sorar ve en yakın telefona yönlendirilir. Hedefler: aramada enerjiyi ve cevap süresini en aza indirmek, recall oranını en yükseğe çıkarmak.

**Soru 3** (ekrandan, 00:40:00): Tabloya göre CPU'nun standart ve pik kullanımdaki güç tüketimi minimal kullanımın kaç katıdır?

> **Çözüm (derste verildi, oranlar python ile doğrulandı):** $175/35 = 5$ kat ve $469/35 \approx 13{,}4$ kat. Hoca "12-13 kata kadar" dedi.

**Soru 4** (derste sözlü, 00:57:16): Crowdsourcing ve crowdsensing sistemlerinin problemleri nelerdir?

> **Çözüm (derste verildi):** Katılımcıların harcadığı fazla enerji, güvenlik ve gizlilik, verinin güvenilirliği ve doğrulanabilirliği; slayttaki liste: imbalanced data, unreliable data, malicious data, unbalanced crowd, lack of crowd.

**Soru 5** (derste sözlü, 01:17:03): Unreliable data ile malicious data arasındaki fark nedir?

> **Çözüm (derste verildi):** Malicious data sistemi yanıltmak için kasıtlı üretilen veridir (sahte yorumlar). Unreliable data'da kasıt yoktur; bozuk bir sensörün hatalı değeri ya da konuda uzman olmayan bir kullanıcının yorumu gibi verinin hatalı olma ihtimali söz konusudur.

**Soru 6** (derste sözlü, 01:19:10): Imbalanced data ile unbalanced crowd arasındaki fark nedir?

> **Çözüm (derste verildi):** Imbalanced data'da verinin kendisi dengesiz üretilir (belli yer ve saatlerde yığılma, diğerlerinde eksiklik). Unbalanced crowd'da veriyi üretecek grubun dağılımı dengesizdir (genç nüfusun ağırlıkta olması, anketin tek bir bölgede yapılması).

**Soru 7** (derste sözlü, 01:29:17): Kimliği doğrulanmış bir kullanıcı da yanlı puan verebilir (otel sahibini tanıyor ya da ürünü satan firmada çalışıyor olabilir). Sistemler bunu nasıl dengeler? Verinin tarihi önemli midir?

> **Çözüm (derste verildi):** Satın almadan ya da konaklamadan yorum yaptırmamak; kullanıcıya geçmişine göre ağırlık vermek (çok yerde kalmış ve puanları dağılımlı kullanıcı daha güvenilir, her yere aynı puanı veren daha az güvenilir); çok sayıda kullanıcı ve oylama ile geniş veri dağılımı; ortak manipülasyon hareketlerini akıllı algoritmalarla filtrelemek. Verinin güncelliği kritiktir, çünkü bir yer zamanla iyileşebilir ya da kötüleşebilir.

**Soru 8** (derste sözlü, 01:37:35): Grup seviyesi teşvik nasıl uygulanır?

> **Çözüm (derste verildi):** Kullanıcılar gruplar hâlinde ortak bir kredi veritabanına katkı yapar; bir üyenin kazandığı krediden grubun diğer üyeleri de yararlanır (aile içinde park yeri bilgisi örneği). Bu, katkı motivasyonunu ve birikimi artırır.

**Soru 9** (derste sözlü, 01:42:20 ve 01:43:56; hoca bunu daha önce bir sınavda sorduğunu belirtti): Sık seyahat eden biri duty free'de alışveriş yaparken hangi eksikliği yaşar ve bu crowdsourcing ile nasıl çözülebilir?

> **Çözüm (derste verildi):** Bir ürünün gidilen, dönülen ya da aktarma yapılan havalimanlarından hangisinde daha ucuz olduğunu bilemez; duty free'ler fiyatları kapsamlı paylaşmaz. Her yolcu uğradığı duty free'de ürün fiyatı paylaştıkça kredi toplar ve karşılığında istediği havalimanındaki fiyatları görür. Böylece herkes her havalimanındaki fiyatlar hakkında bilgi sahibi olup daha uygun alışveriş yapar.

**Soru 10** (derste sözlü, 01:51:14): Task crowdsourcing nedir ve temel sorunu nedir?

> **Çözüm (derste verildi):** Kullanıcılara görev verilerek verinin toplanmasıdır (Pokemon Go'daki görevler gibi). Sorun, görevlere talip olacak kişi bulunup bulunmayacağı ve kullanıcının sürekli motive edilip sistemde tutulmasıdır; kalabalık azaldıkça sorun büyür.

**Soru 11** (derste sözlü, 01:58:29): Yeşil dalga sistemi akıllı trafik ışığı sayılır mı?

> **Çözüm (derste verildi):** Hayır. Güvenliği artıran ve yakıt tüketimini azaltan sabit bir programdır; öğrenme içermez ve trafiğin anlık karakteristiğini değerlendirmez.

**Soru 12** (derste sözlü, 02:33:13): Binary ve probabilistic sensing modelleri arasındaki fark nedir?

> **Çözüm (derste verildi):** Binary modelde nokta ya algılanır ya algılanmaz (1/0). Probabilistic modelde algılama olasılığı mesafeyle azalır (yakında 1, sonra 0,9, 0,8 ...) ve belli bir mesafeden sonra keskin düşer; daha gerçekçidir, ama bilimsel çalışmalarda çoğunlukla binary model kullanılır.

**Soru 13** (derste sözlü, 02:36:00): Sensör ağlarında üç temel kapsama yaklaşımı nedir? Border coverage'ın zayıf noktası nedir?

> **Çözüm (derste verildi):** Area coverage (en büyük alan), target coverage (en çok hedef), border coverage (giriş-çıkışı algılama). Border coverage hat şeklinde dizildiği için havadan (örneğin paraşütle) gelen girişi kaçırır; bu yüzden 3D kapsama modelleri geliştirilmektedir.

**Soru 14** (derste sözlü, 02:39:21): Sensör ağlarında haberleşme için hangi protokol kullanılır?

> **Çözüm (derste verildi):** ZigBee (IEEE 802.15.4). Bant genişliği sınırlıdır ama enerji tüketimi düşüktür. MQTT daha çok IoT tarafında kullanılır.

**Soru 15** (derste sözlü, 02:40:02): Sensör ağlarında ağ ömrü nasıl uzatılabilir? Uyku-uyanma döngüsü veri kaçırmaya yol açar mı?

> **Çözüm (derste verildi):** Fiziksel koruma, enerjinin verimli kullanılması, enerji hasadı (güneş, rüzgar, su, basınç), zaman dilimli uyku-uyanma döngüleri, veriyi düğümde işleyip yalnız önemli olanı göndermek. Algılama ile haberleşme bağımsızdır; sıcaklık izlemede kısa gecikme sorun değildir, ama düşman giriş-çıkışı izlenirken düğüm uzun süre uyutulamaz.

## Dersin Toparlaması

Ders, mobil cihazlarda makine öğrenmesi uygulamalarının enerji tüketiminin nasıl ölçüleceğiyle başladı: veri toplama, ön işleme, özellik çıkarımı ve sınıflandırma ayrı ayrı enerji harcar; ölçüm yazılımsal (Battery Stats ve literatürdeki araçlar) ya da donanımsal (Monsoon) yapılabilir ve eşit şartlar, özellikle şarj durumu ve arka plan/ön plan çalışma farkı gözetilmelidir. Ardından crowdsourcing konusu tamamlandı: problem çözme adımları, süreç akışı, uygulamalar ve sınıflandırma tablosu, akıllı telefonun enerji profili, SmartP2P, mobil crowdsensing ve teşvikler. Crowdsensing problemleri (imbalanced data, unreliable ve malicious data, unbalanced crowd, lack of crowd, enerji) ve bunlara karşı kimlik doğrulama (e-Devlet, telefon numarası, LoA ve SIM tabanlı doğrulama), kullanıcı ağırlıklandırma ve verinin güncelliği gibi çözümler tartışıldı. Grup seviyesi teşvik, servis teşvikleri, MCN genel mimarisi ve akıllı trafik ışığı ile sağlık izleme gibi uygulama örnekleri bu kısmı kapattı.

Son bölümde IoT'nin başlangıç noktası olarak telsiz algılayıcı ağlara giriş yapıldı: düğümlerin yapısı ve yerleştirilmesi, algılama ve haberleşme kapsaması, binary ve probabilistic algılama, area, target ve border coverage, ZigBee ve ağ ömrünü uzatma yöntemleri. Hoca bir sonraki derste sensör ağlarını tamamlayıp IoT ve büyük veriye geçeceğini, son derste de otonom araçları anlatacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
