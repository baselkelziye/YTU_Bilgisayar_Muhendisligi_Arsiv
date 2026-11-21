# Ders 12 Genişletilmiş Notu: Kablosuz Sensör Ağları ve IoT ile Karşılaştırma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düşme Tespiti Uygulaması: İşlem Hattı
- 2. Düşme Tespitinde Enerji Tüketimini Ölçme
- 3. Kablosuz Sensör Ağlarının Vizyonu ve Düğüm Donanımı
- 4. WSN Tarihçesi ve IPv6
- 5. WSN'lerin Temel Özellikleri
- 6. Ağ İçi İşleme, Küme Başları ve Kablosuz Ortamın Güçlükleri
- 7. Haberleşme Örüntüleri ve Veri Toplama Modelleri
- 8. Ağ Gereksinimleri ve Konuşlandırma
- 9. Ağ Topolojileri ve Bakım
- 10. WSN'den IoT'ye: Gerçek Hayat ve Enerji İhtiyacı
- 11. Güç Tüketimi, Protokol Tasarım Güçlükleri ve Güvenilirlik
- 12. Güvenlik: Ses Tabanlı Konumlama ve Şifreleme
- 13. WSN Uygulamaları
- 14. IoT ile WSN'in Karşılaştırılması
- Örnek Sorular

## 1. Düşme Tespiti Uygulaması: İşlem Hattı

Dersin ilk bölümünde hoca, Android telefonda çalışacak küçük bir düşme tespiti (fall detection) uygulamasının yapısını anlattı. Bu bölüm, dönem boyunca işlenen sensör verisi ön işleme, pencereleme, öznitelik çıkarma ve sınıflandırma konularını tek bir uygulamada birleştirir.

### 1.1 Üç tür karar yöntemi

Uygulamada en az üç karar mekanizması bulunur:

- Kural tabanlı bir yöntem: tek bir eşik değeriyle eşikleme (thresholding).
- Bir makine öğrenmesi yöntemi.
- Bir derin öğrenme yöntemi.

Bunların basit olanları seçilebilir. Hoca, mümkünse sınıflandırma yetenekleri birbirinden farklı olan k-NN, Random Forest, Decision Tree ve SVM gibi birkaç makine öğrenmesi yönteminin de eklenmesini istedi.

### 1.2 Veri okuma ve tek boyuta indirgeme

Yalnız ivmeölçer kullanılır. X, Y ve Z eksenlerinden okunan üç boyutlu veri, sinyal vektör büyüklüğüne (signal vector magnitude) çevrilerek tek boyutlu bir sinyale dönüştürülür:

$$SVM = \sqrt{x^2 + y^2 + z^2}$$

Kural tabanlı eşikleme ve diğer yöntemler bu tek boyutlu sinyal üzerinde çalışır.

> **Ek bilgi (derste anlatılmadı):** Büyüklük sinyali telefonun cepte ya da elde hangi yönde durduğundan bağımsızdır. Telefon dururken bu değer yerçekimi ivmesine (yaklaşık 9,8 m/s²) yakındır; düşme sırasında önce kısa bir serbest düşüş (değerin düşmesi), ardından çarpma anında belirgin bir tepe görülür. Eşik tabanlı yöntemler büyük olasılıkla bu tepeyi yakalamaya dayanır.

### 1.3 Pencereleme ve çift tampon

Makine öğrenmesi ve derin öğrenme için veri pencerelere bölünmelidir. Düşme kısa sürede gerçekleştiği için pencere boyutu yaklaşık 2-3 saniye seçilir. Okuma sırasında iki tampon (two buffer) kullanmak faydalıdır: bir tampon işlenirken diğeri doldurulur.

### 1.4 Ön işleme ve öznitelik çıkarma

Okuma ile karar verme arasına bir ön işleme adımı konur. Hocanın verdiği seçenekler normalizasyon ve yumuşatma (smoothing) yapan bir alçak geçiren süzgeçtir (low pass filter).

Pencere belirlendikten sonra her pencereden ortalama, standart sapma, maksimum, minimum gibi en az beş temel öznitelik çıkarılır. Hoca farklı öznitelikler de kullanılabileceğini, beşten fazla öznitelik çıkarılmasının daha iyi olacağını söyledi. Bu öznitelikler kullanılarak pencerenin düşme olup olmadığına karar verilir.

Sonuçta uygulama her 3 saniyede bir "düşme / düşme değil" çıktısı verir. Uygulamanın adımları şöyle sıralanır:

```text
İvmeölçer okuma (x, y, z)
  -> SVM = sqrt(x^2 + y^2 + z^2)
  -> Ön işleme (normalizasyon, alçak geçiren süzgeç)
  -> 2-3 s pencereler (çift tampon)
  -> En az 5 öznitelik (ortalama, std, max, min, ...)
  -> Eşikleme / makine öğrenmesi / derin öğrenme
  -> Her 3 saniyede bir "düşme / düşme değil"
```

### 1.5 Modelin kurulması

Makine öğrenmesi ve derin öğrenme modelleri için MobiFall veri setindeki ilgili dosyalar okunup model üretilir ve başarı da raporlanır.

**Soru:** Model her seferinde veri setinden yeniden mi oluşturulacak?
**Cevap:** Hayır, model doğrudan telefonun üzerine yüklenir.

**Soru:** Model Weka ile oluşturulup kaydedilip sonra yeniden yüklenebilir mi?
**Cevap:** Evet. Modeli bilgisayarda oluşturmak bir seçenektir, ama hoca Weka'nın telefona kurulup modelin telefonda eğitilmesini önerdi. Veri büyük değildir ve öznitelik sayısı azdır; eğitimin telefonda yapılıp süresinin kaydedilmesi daha iyi olur.

Bir öğrenci, Weka'nın Android'e eklenmesinin kolay olduğunu, asıl zorluğun Weka'nın çalıştığı ARFF ya da CSV dosyalarını uygulamaya gömmek ya da dosya seçtirip açmak olduğunu söyledi; dosya seçimi Android'de izin gerektirir. Hoca buna katıldı ve son dönemde dosya erişimiyle ilgili yapılan düzenlemeler yüzünden bazı ayarların gözden geçirilmesi gerekebileceğini ekledi. Hocaya göre uygulamanın kritik kısmı sensörden veri okumaktır; sonrası herhangi bir programlama diliyle bellekte yapılabilecek işlerdir.

Android sürümü konusunda, test cihazında Android 8.0/8.1 bulunduğu için minimum sürüm olarak Android 8 seçilmesi kararlaştırıldı.

## 2. Düşme Tespitinde Enerji Tüketimini Ölçme

### 2.1 Neyin ölçüleceği

Uygulamanın asıl araştırma sorusu enerji tüketimidir. Uygulama uzun süre çalıştırılır ve şu adımların enerjiye etkisi ortaya konur:

- Okuma (read)
- Ön işleme (pre-processing)
- Öznitelik çıkarma (feature extraction)
- Sınıflandırma ve sınıflandırıcıların birbirine göre farkı

Üç yaklaşımın (kural, makine öğrenmesi, derin öğrenme) ne kadar enerji tükettiği yüzde ya da joule cinsinden verilebilir; hoca burada belirli bir birim şart koşmadı.

### 2.2 Ölçüm koşulları

- Testler gerçek telefonda yapılmalıdır.
- Testler telefon şarj cihazına bağlı değilken yapılmalıdır; böylece daha doğru sonuç alınır.
- Çok küçük enerji farkları tespit edilirse daha uzun süreler için yorumlanarak karşılaştırılır. Örneğin bir dakikalık tüketim ayırt edilemeyebilir, ama iki günlük ya da bin çalıştırmalık sonuç karşılaştırılabilir.

### 2.3 Bileşenlerin güç tüketimi

Telefondaki parçaların ne kadar güç tükettiği de ele alınır: ekranın yaklaşık gücü, CPU'nun yoğun (heavy) ve boşta (idle) olduğu durumlar. Hoca burada "enerji" yerine "güç" denmesi gerektiğini özellikle belirtti. Bunun için literatürden bir makale referans model olarak alınabilir. Amaç, telefondaki enerji tüketen parçaların birbirine göre farkını kısaca göstermektir.

Ölçüm yöntemi olarak hocanın paylaşacağı bir makaledeki yaklaşım temel alınır. Makale, kendi yazılımsal yöntemlerinin donanımsal ölçüme çok yakın sonuç ürettiğini iddia eder ve Android tarafında hangi ayarların kapatılıp açılması gerektiğini anlatan bir kod parçası içerir. Hoca, bu konuda çok fazla çalışma bulunmadığını ve sonuçların bir bildiriye dönüşebileceğini düşündüğünü söyledi.

## 3. Kablosuz Sensör Ağlarının Vizyonu ve Düğüm Donanımı

Dersin ikinci bölümünde hoca bir kablosuz sensör ağları (Wireless Sensor Networks, WSN) dersinin slaytlarını kullandı. Amacı bütün içeriği aktarmak değil, genel prensibi ve alanın bugüne nasıl dönüştüğünü anlatmaktı.

### 3.1 "Many-tiny" ilkesi

Slayttaki tanıma göre sensör ağları, hesaplama (computation), haberleşme (communication) ve algılama (sensing) yapabilen binlerce ucuz minyatür cihazdan oluşan kablosuz ağlardır. Akıllı alanlar, çevresel izleme ve savaş alanı uygulamaları için düşünülmüştür. Fiziksel dünyaya gömülü olan bu cihazlar, bilgi teknolojisinin sanal dünyası ile gerçek fiziksel dünya arasında köprü kurar ve büyük ölçekli olayları ince bir uzay-zaman çözünürlüğüyle gözlemeyi sağlar (ekrandan, 00:30:00). Slaytta örnek düğüm olarak Berkeley Mote gösteriliyordu.

Sensör ağlarında algılama temeldir, ama zamanla aktüatör kavramı da eklendi: algıladığı duruma karşılık eylem yapabilme. Bazı sensör ağlarında bu eylemler uygulanabiliyor.

WSN'ler öncelikle askeri alanda, ayrıca akıllı alanlarda ve çevresel işlerde, çoğunlukla dış sahada kullanılır. İç ortam çözümleri de vardır; bunlarda düğümler elle yerleştirilir. Dış ortamda düğümler saçılarak ya da atılarak yerleştirilir; bu da kapsama (coverage) sorunlarına ve düğümlerin zarar görmesine yol açar.

### 3.2 Sensör düğümü donanımı

Bir sensör düğümü temel olarak şunlardan oluşur:

- İşlemci
- Veri alıp gönderme için radyo alıcı-verici (transceiver)
- Güç kaynağı (pil)
- Bellek ve depolama
- Bazen (her zaman değil) GPS ile konum bilgisi

Pil olabildiğince verimli kullanılmalıdır. Devrelerin çevre koşullarından zarar görmemesi için iyi korunmaları gerekir.

### 3.3 Kısıtlar ve enerji tasarrufu

Hoca Zigbee protokolünün veri hızının oldukça düşük olduğunu, multimedya sensör ağları için bunun büyük sıkıntı olduğunu hatırlattı. Görüntü ve ses gönderilecekse veri birden fazla rota üzerinden gönderilir.

> **Ders sonrası not:** Hoca Zigbee'nin veri hızını "256 kilobit per second" olarak söyledi. IEEE 802.15.4'ün 2,4 GHz bandındaki veri hızı büyük olasılıkla 250 kbit/s'dir; slayt listesindeki Tmote Sky özellikleri küçük resminde de "250 kbps IEEE 802.15.4" ifadesi seçiliyor.

Düğümlerin RAM'i ve flash belleği küçüktür, mikrodenetleyicilerin çalışma frekansı düşüktür. Bu yüzden şu çözümler kullanılır:

- Dinamik voltaj ölçekleme (dynamic voltage scaling): mümkünse CPU'yu düşük frekansta çalıştırmak.
- Veriyi transfer etmeden düğümün kendi üzerinde işleyip yalnız sonucu aktarmak.

Bekleme (stand-by) modunda tüketim mikroamper düzeyindedir. Hoca bunu 2 mA ile kıyasladı ve 2 mA'in de aslında yüksek bir tüketim olmadığını, zamanla çok küçük sensör düğümleri tasarlandığını söyledi. <!-- BELİRSİZ: Hocanın andığı 2 mA ve mikroamper değerlerinin geçtiği Tmote Sky slaytı karelerde yalnız küçük resim olarak görünüyor; değerler okunamadı. -->

Slaytta 2001'de tasarlanan Berkeley Smart Dust projesi ile 12 mm × 12 mm LGA paketinde satılan bir yonga gösteriliyordu. Aynı slaytta nano ağlar da yer alıyordu: nano makinelerin birbirine bağlanması; elektromanyetik ya da akustik dalga yerine moleküllerin kullanılması (ekrandan, 00:35:00).

### 3.4 Vücut alanı ağları ve gelecekteki araştırma alanları

İnsan vücudunun içine yerleştirilen düğümler de vardır. Kişisel alan ağı (Personal Area Network) kişinin çevresini kapsarken, vücut alanı ağı (Body Area Network) kişinin üzerine yerleştirilen düğümleri ifade eder. Tedavi süreçlerinde kullanılan yapılar ve vücuttan alınan verilerin doğrudan aktarılmasıyla ilgili çözümler bulunur.

Hoca vücuda elektronik cihaz yerleştirmenin organların işlevini düzeltme ve organ değişimiyle başlayacağını, bunun en basit örneğinin kalp pili olduğunu söyledi. Dijital dünyanın riski, analog dünyaya göre üretmenin, değiştirmenin ve paylaşmanın çok kolay olması ve bu yüzden dış saldırılara açık olmasıdır.

Hocaya göre bilgisayar mühendisliğinde ileriye dönük güçlü araştırma alanları şunlardır: sağlık alanındaki çalışmalar (hastalık tespiti, organlarla ilgili elektronik cihazlar), siber güvenlik ve yaşlıların hayatını kolaylaştıran, onları gözeten ve sorun olduğunda uyaran sistemler. Düşme tespiti bu son gruptandır. Ev içinde yaşlılar çoğunlukla kamerayla izlenir; dış ortamda kamerayla izleme kişisel verilerin korunması düzenlemeleri yüzünden zordur.

**Soru (hocadan):** Siber güvenlik için hangi temel bilgisayar mühendisliği konularında bilgi sahibi olmak gerekir?
**Cevap:** Öğrenciler işletim sistemleri ve ağları, ayrıca donanımsal bir çalışma yapılıyorsa mikroişlemcileri ve donanımı saydı. Hoca siber güvenliğin kendi başına bir alan olmadığını, altında belli bir temel beklediğini; özellikle ağ ve işletim sistemi seviyesindeki bilginin bu alandaki yeteneğe çok katkı sağlayacağını söyledi.

## 4. WSN Tarihçesi ve IPv6

Slayttaki WSN tarihçesi şöyledir (ekrandan, 00:35:00):

- 1993-4: UCLA LWIM projesi.
- 1999-2002: Birden fazla üniversite ve sanayi ekibine fon sağlayan büyük DARPA projeleri: SensIT, PAC/C.
  - WINS (UCLA'daki LWIM'in devamı)
  - Smart Dust / Motes / TinyOS (UCB, Berkeley Intel Lab)
  - PicoRadio (UCB)
- 2003: Düşük veri hızlı kablosuz iletişim için IEEE 802.15.4 standardı.
- 2007: WSN'de IP için 6LoWPAN çalışması (IPv6 paketlerinin IEEE 802.15.4 tabanlı ağlar üzerinden gönderilip alınmasını sağlayan mekanizmalar).
- 2010: WirelessHART onaylandı (2,4 GHz ISM bandında çalışan, güvenli ve TDMA tabanlı kablosuz mesh ağ teknolojisi).

Hoca IPv6'nın yavaş yavaş hayata geçirilmek istendiğini, çünkü IP adreslerinin yetmediğini ve cihazlara tekil kimlik verilemediğini söyledi. Bu ihtiyaç IoT için gereklidir. Sensör ağlarında normalde böyle bir ihtiyaç yoktur: düğümlerin kendi tekil kimlikleri vardır, ama doğrudan adreslenebilir (direct addressable) değillerdir. Belli bir coğrafyadaki yerleri temsil ederler.

## 5. WSN'lerin Temel Özellikleri

### 5.1 Dağıtık organizasyon

Sensör düğümleri birbirleriyle genelde dağıtık bir şekilde haberleşip organize olur. WSN uygulamalarında merkezi kontrolden özellikle kaçınılır, çünkü bütün verinin merkeze gitmesi ağın ömrünün çabuk tükenmesi demektir. Karar alınacaksa düğümler çevrelerindeki düğümlerin konum ve bilgilerini kullanır.

### 5.2 Slayttaki özellik listesi

Slayttaki özellikler şunlardı (ekrandan, 00:45:00):

- Düğümler birbirine yakın olmalıdır.
- Yoğunluk 20 düğüm/m³'e kadar çıkabilir.
- Bilgi akışı genelde asimetriktir: sensör düğümlerinden havuza (sink).
- Haberleşme sorgular (query) ya da olaylar (event) ile tetiklenir.
- Enerji miktarı sınırlıdır; birçok uygulamada pili değiştirmek ya da şarj etmek imkansızdır.
- Topoloji çoğunlukla statiktir.

Hoca, yüksek sayıda sensör atılmasının metrekareye çok sensör düşmesi ve ciddi bir elektronik kirlilik demek olduğunu söyledi. Bu yoğun kullanımın nedeni askeri faaliyetler, ulaşılamayan doğal alanların izlenmesi ve tarım bölgelerinde sulama gibi daha akıllı ortamlar yaratmaktır. Rastgele atmak yerine tasarlayarak yerleştirmek daha etkili bir kapsama sağlar.

Haberleşme üç şekilde başlar: bir noktadan bilgi talep edilmesi (sorgu), bir noktada olay olunca bilginin aktarılması (olay tetiklemeli yapı) ve belli periyotlarla raporlama (sorgu atmaya gerek kalmadan verinin belirlenen zamanlarda gelmesi).

### 5.3 Statik ve mobil topoloji

**Soru (hocadan):** Topoloji neden genelde statiktir?
**Cevap:** Bir öğrenci düğümlerin hareket edemediğini söyledi. Hoca onayladı: düğümler bir kez atıldıktan sonra o topoloji benimsenir.

Zamanla mobil sensör ağları (Mobile Sensor Networks) diye yeni bir alan çıktı. Düğümler aynı yere düşebildiği için hareket kabiliyeti onların çevreye daha iyi yayılmasını sağlar. Böylece bir kısmı statik, bir kısmı mobil heterojen ağlar oluştu. Kapsama daha optimal sağlanır; bir konumdaki sensör bozulduğunda mobil düğüm oraya götürülerek veri toplamaya devam edilir. Bunun da bir maliyeti vardır.

### 5.4 Topolojiyi değiştiren etkenler

Slaytta devam eden özellikler şunlardı (ekrandan, 00:45:00):

- Sensör ağının topolojisi düğüm arızası ve düğüm hareketliliği yüzünden sık değişebilir.
- Düğüm başına düşük maliyet, boyut ve ağırlık.
- Arızaya yatkınlık.
- Noktadan noktaya (point-to-point) yerine daha çok yayın (broadcast) haberleşme.
- Bilginin kalitesini artırmak için ağ içi işleme (in-network processing).

Cihazlar hataya yatkın ve çabuk yıprandığı için yapı izlenmeli ve gerekirse yeniden şekillendirilmelidir. Yayın haberleşmesinde düğümlerin aynı anda gönderim yapması kablosuz ortamda çakışmaya yol açar; bu yüzden düğümler bilgilerini belli aralıklarla ve belirli bir kurala uygun olarak çevrelerine yaymalıdır.

## 6. Ağ İçi İşleme, Küme Başları ve Kablosuz Ortamın Güçlükleri

### 6.1 Veri birleştirme ve küme başı

Ağ içi işlemede komşu düğümlerden gelen veriler birleştirilerek (data aggregation) merkeze daha kaliteli bir veri aktarılır. Sensör ağları bunu sıklıkla yapar. Birleştirmeyi yapan düğüme küme başı (cluster head) denir; bilgi onda toplanır ve o aktarır. Küme başının enerjisi çabuk tükendiği için belirli turlar sonunda değiştirilmesi ağ ömrünü (network lifetime) uzatır.

### 6.2 Bant genişliği ve kablosuz ortam

Bant genişliği sınırlıdır. Veri kablosuz ortamda taşındığı için çarpışma yüzünden ulaşmayabilir. Fiziksel koşullar ya da çıkış gücü yüzünden düğüm başka bir düğüme ya da baz istasyonuna ulaşamayabilir. Bu yüzden uygun bir çıkış gücü belirlenmelidir. Çevredeki düğümlerin yakınlığına göre çıkış gücünü dinamik ayarlamak enerji tasarrufu sağlar.

### 6.3 Radyo karakteristikleri tablosu

Slaytta tipik sensör radyolarını bir WLAN radyosuyla karşılaştıran bir tablo vardı. Karede tablonun alt satırları görünüyordu (ekrandan, 00:50:00):

| Satır | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Tx. Current | 30 mA | 26,7 mA | 17,4 mA | 12 mA | 9 mA | - |
| Rx. Current | 12,5 mA | 9,6 mA | 19,7 mA | 3,8 mA | 12 mA | - |
| Tx. Range (indoors) | 50 m | | 50 m | 100 m | 30 m | 24-90 m |
| Tx. Range (outdoors) | 125 m | >100 m | 125 m | 300 m | 80 m | 90-610 m |

<!-- BELİRSİZ: Tablonun sütun başlıkları (hangi radyo modelleri olduğu), modülasyon, çalışma frekansı ve veri hızı satırları karede görünmüyor. -->

Hoca tabloda farklı modülasyon tekniklerinin, çalışma frekanslarının ve veri hızlarının yer aldığını, veri hızlarının oldukça düşük olduğunu, yalnız Cisco tarafındaki (WLAN) veri hızının yüksek olduğunu söyledi.

## 7. Haberleşme Örüntüleri ve Veri Toplama Modelleri

### 7.1 Üç haberleşme örüntüsü

Slayttaki haberleşme örüntüleri şunlardı (ekrandan, 00:50:00):

- **Convergecast:** Sensör düğümleri topladıkları veriyi bir havuza (sink) bildirir. Hocaya göre esas olan budur: uzak düğümlerden merkeze aktarım.
- **Multicast:** Veri havuz düğümünden ağdaki sensör düğümlerine dağıtılır. Bir güncelleme ya da bilgilendirme yapılacaksa kullanılır.
- **Local broadcast/gossip:** Komşular arasında veri alışverişi; örneğin ham okumaları göndermek yerine verinin birlikte işlenmesi için. Hoca, düğümleri uzun yaşatmak için bunu tercih ettiklerini söyledi.

### 7.2 Mobil havuz

Belirli bir mobil havuz (mobile sink) sensör düğümleri arasında gezebilir. Hoca Afrika'daki hayvan izleme örneğini verdi: hayvanlara takılan çiplerin verisini uzaktaki havuza aktarmak maliyetli ve enerji tüketen bir iş olduğu için habitat içinde bir araç gezer ve bilgileri toplar. Böylece mobil bir baz istasyonu kullanılmış olur ve verinin çok uzun mesafe taşınması önlenir; haberleşme kısa ve doğrudan olur.

### 7.3 Tek atlamalı ve çok atlamalı haberleşme

Tek atlamalı (one-hop) haberleşme, alıcı yakındaysa her zaman avantajlıdır. Çok atlamalı (multi-hop) haberleşmede düğüm, kendisi hiçbir şey algılamamış olsa bile kendisine aktarılan veriyi de iletmek zorundadır; bu yüzden mobil havuza göre daha fazla enerji harcanır. Ama sahadaki uzak bir sensörün veriyi doğrudan baz istasyonuna göndermesine göre çok atlamalı haberleşme daha avantajlıdır: doğrudan gönderimde uzun mesafe yüzünden yüksek enerji harcanırdı. Bunun yerine düğüm veriyi önündeki düğüme aktarır ve veri düğümden düğüme sabit istasyona ulaşır.

### 7.4 Veri toplama modelleri

Slayttaki veri toplama modelleri şunlardı (ekrandan, 00:55:00):

- **Sürekli veri teslimi (Continuous Data Delivery):** Sensör düğümleri topladıkları veriyi periyodik aralıklarla gönderir. Geleneksel izleme uygulamalarının temel modelidir (bir tarlanın sıcaklık haritası).
- **Sorguya dayalı veri teslimi (Query-Driven Data Delivery):** Sensörler yalnız havuzun açık isteğine yanıt olarak veri bildirir; izlenen koşulların anlık görüntüsü ya da kısa bir aralık için veri akışı (önümüzdeki 2 dakikanın ortalama sıcaklığı).
- **Olaya dayalı veri teslimi (Event-Driven Data Delivery):** Sensör düğümleri yalnız ilgili bir olay olursa veri bildirir (yangın bildirimi, sıcaklığın belli bir eşiği aşması).

Hoca sorguya dayalı modele örnek olarak bir olay olduktan sonra sorgu atıp oradan görüntü alınmasını verdi; sürekli görüntü almak ve göndermek çok maliyetlidir. Olaya dayalı modele örnek olarak bir kişinin ya da aracın geçişini verdi; özellikle askeri alanda bir birliğin ya da aracın bir noktadan geçmesi kritiktir.

### 7.5 Araç geçişinin tespiti

**Soru (hocadan):** Bir aracın geçtiği nasıl tespit edilir?
**Cevap:** Öğrencilerden gelen öneriler ve hocanın değerlendirmesi şöyledir:

- Lazer sensörü: Kullanılır, özellikle vücut ısısı üzerinden tarama yapan termal kameralarla hareket tespit edilir. Ama sensör düğümleri küçük cihazlardır; lazer yerleştirmek ve sürekli tam kapsama sağlamak kolay değildir, maliyetlidir ve her an her yeri taramak mümkün olmayabilir.
- Ağırlık/basınç: İkinci kullanılan yöntemdir. Ancak araç döşenen sensörün üzerinden geçmeyebilir ve basınç mekanizması tetiklenmeyebilir.
- Ses: Bu tür çalışmalar çoğunlukla ortam sesi üzerinden yapılır. Daha az maliyetli ve kapsaması daha yüksektir.
- Motor sıcaklığı da bir öğrenci tarafından önerildi.

Hoca, lazer taramasını hapishane filmlerinde gezen ışıklara benzetti: kaçaklar spotların hangi noktada ne kadar kaldığını hesaplayıp rota çizer. Sensör ağlarına sızma operasyonlarında da yerleştirilen sensörlerin zayıf noktası bulunmaya çalışılır; düşmanın stratejisi bunun üzerinedir.

Bir öğrenci, elektrikli araçların ses çıkarmadığı, basınç ve motor sıcaklığı izlerinin de çok az olduğu için lazer dışındaki yöntemlerden kaçabileceğini söyledi. Hoca bunun aklına gelmediğini, elektrikli araçların bu anlamda "hayalet araçlar" olma yolunda olduğunu belirtti. Belirli ve insanın duyamadığı frekanslarda ses çıkıp çıkmadığına bağlı olarak elektrikli araçların tespitine yönelik bir çalışma yapılabileceğini, radara yakalanmayan uçakların da sonradan tespit edilebildiğini söyledi.

## 8. Ağ Gereksinimleri ve Konuşlandırma

### 8.1 Ağ gereksinimleri

Slaytta WSN'lerin ağ gereksinimleri şöyle veriliyordu (ekrandan, 00:55:00):

- **Enerji verimliliği (Energy Efficiency):** Radyo haberleşmesi optimize edilmelidir. En yaygın yöntem, radyoyu uyku ve uyanma modları arasında periyodik geçiş yapan görev döngüleriyle (duty cycle) çalıştırmaktır.
- **Ölçeklenebilirlik (Scalability):** Konuşlandırılan düğüm sayısı yüzler ya da binler mertebesinde olabilir.

Hoca buna altyapı olmaması, güvenilir olmayan haberleşme bağlantıları ve düğümler yüzünden kendi kendine organize olan bir yapının tasarlanması gerektiğini ekledi.

### 8.2 Konuşlandırma hedefleri

Konuşlandırmada temel hedefler şunlardır:

- **Kapsama (coverage):** Çok önemlidir.
- **Bağlanırlık (connectivity):** Bilgiyi toplamak ile onu yakındaki düğüme aktarmak ayrı şeylerdir.

Bunlar sağlandıktan sonra izlenen bölge daha az sensörle ve daha düşük enerjiyle izlenebilir mi diye bakılır.

### 8.3 Konuşlandırma türleri

- **Rastgele konuşlandırma (Random Deployment):** Düğümler rastgele dağıtılır.
- **Yapılandırılmış konuşlandırma (Structured Deployment):** Düğümler elle ya da otonom robotlarla yerleştirilir. Hoca, bölgeye birkaç robotun bırakıldığı ve robotların sensörleri belirlenen pozisyonlara götürüp yerleştirdiği çalışmalar olduğunu söyledi.
- **Fazla konuşlandırma (Over-deployment):** Ortamda oluşabilecek açıkları gidermek ve hatalara önceden çözüm bulmak için artık (redundant) düğümlerle ekstra sensör yerleştirmek.
- **Artımlı konuşlandırma (Incremental Deployment):** Düğümler bir kez atıldıktan sonra boş alanlar tespit edilir, oralara gidilip takviye yapılır.

Alternatif olarak mobil sensör düğümleri kullanılabilir. Slayta göre bunlar konuşlandırma eksiklerini telafi etmek için hareket edebilir ve "ilginç" alanları aktif olarak arayabilir (ekrandan, 01:15:00). Mobil sensör istenen yere konumlandırılabildiği için bölgeye çok daha az sensör atılır; ama mobil düğümlerin de maliyeti vardır.

## 9. Ağ Topolojileri ve Bakım

### 9.1 Yıldız topoloji

Slaytta yıldız topoloji "tek atlamalı topoloji" olarak veriliyordu: tasarımı önemli ölçüde basitleştirir, ama ölçeklenebilirliği ve dayanıklılığı zayıftır (ekrandan, 01:15:00).

**Soru (hocadan):** Günlük hayatta sık kullandığımız bir yıldız topoloji örneği nedir?
**Cevap:** Hoca cevabı kendisi verdi: kablosuz erişim noktası (access point). Hep bir erişim noktası üzerinden bağlanırız. Baz istasyonunda da aynı mantık vardır.

Sensör ağlarında yıldız topoloji uygulanamaz: bu kadar çok düğüm tek atlamayla uzak mesafedeki baz istasyonuna erişirse enerjileri çabuk tükenir. Bu yüzden düğümler birbirleri üzerinden atlayarak haberleşir.

### 9.2 Diğer topolojiler

- **Düz çok atlamalı mesh (flat multi-hop mesh):** Düğümler birbirleri üzerinden veriyi aktarır (ekrandan, 01:15:00).
- **Yapılandırılmış ızgara (structured grid):** Elle yerleştirilmiş düğümlerde daha düzenli bir yapı (ekrandan, 01:20:00).
- **İki katmanlı hiyerarşik küme topolojisi (two-tier hierarchical cluster topology):** Düğümler küme başlarına raporlar. Büyük ağı, verinin yerelde işlenip birleştirilebildiği ayrı bölgelere ayırır (ekrandan, 01:20:00).

Hoca son yapıyı en ilginç bulduğunu söyledi. Burada iki seçenek vardır: küme başı olarak daha güçlü özelliklere sahip bir düğüm seçmek ya da düz bir ağda küme başı görevinin grup içinde sürekli düğümden düğüme geçmesi. İkincisi ağ ömrünü uzatır.

### 9.3 Bakım seçenekleri

Slaytta bakımla ilgili şu sorular vardı (ekrandan, 01:20:00):

- Sensör düğümlerinin bakımı mümkün ya da pratik mi? Örneğin pil değiştirmek? Ya da gözetimsiz çalışma (unattended operation)? İmkansız ama önemsiz mi; görev ömrü çok kısa olabilir.
- Enerji kaynağı: Konuşlandırma anındakiyle sınırlı mı? Çevreden şarj ya da enerji toplama (energy scavenging) mümkün mü? Örneğin güneş hücreleri.

Hoca pil değiştirmenin kolay olmadığını, bozulan düğüme müdahalenin de zor olduğunu söyledi. Güneşten enerji almak mümkündür ve yapılır, ama pratikte yaygın değildir; daha çok teoride kalır.

**Soru:** Saçılan sensörler kullanım ömrü bittikten sonra orada mı kalıyor?
**Cevap:** Evet, işin kötü tarafı budur. Bazen askeri operasyonların sonunda toplandığı söylenir; hayvanlara takılan düğümler de geri alınabilir ya da ortam kontrollüdür.

## 10. WSN'den IoT'ye: Gerçek Hayat ve Enerji İhtiyacı

### 10.1 Anlatım ile gerçek hayat

Hoca, binlerce düğümün dağıtıldığı anlatımın gerçek hayata bu kadar yansımadığını açıkça söyledi. Sık sık sensör ağı konuşlandırıldığını duymadığını, uygulamaların daha çok deneysel ya da çok özel hedefe yönelik bütçesi ayrılmış çalışmalar olduğunu belirtti. Akademik çalışmalar sanki her ay yeni bir ağ kuruluyormuş gibi yürür. Hedef buydu ve bu yüzden düğümler küçültüldü, maliyetleri düşürüldü. Ama 2000'lerin başında alan IoT'ye evrildi: ayrı düğüm tasarlamanın gereksiz bir elektronik çöplük yarattığı ve konuşlandırmada birçok sorun çıktığı görüldü; bunun yerine cihazların kendisi akıllı hale getirildi.

> **Hocanın vurgusu:** Sensör ağlarının çözüp IoT'nin çözemeyeceği yerler vardır. Coğrafi olarak erişilmesi zor yerlerde sensör ağı konuşlandırmadan IoT cihazlarıyla çözüm bulunamaz.

### 10.2 Enerji ihtiyacı

Sensör ağları ile IoT arasındaki en büyük farklardan biri enerji ihtiyacıdır. Sensör ağlarında sahada ciddi enerji sorunu vardır ve buna çözüm bulmak zorunludur. IoT cihazlarının çoğunda bu sorun yoktur: enerjilerini araçtan ya da şebekeden alırlar. Kalem, yaka iğnesi, çatal gibi taşınabilir eşyalar ise enerji ihtiyacı olan IoT cihazlarıdır. Hocaya göre IoT cihazları iki başlıkta incelenmelidir: enerji ihtiyacı olanlar ve bir enerji kaynağına sahip olanlar.

**Soru (hocadan):** IoT cihazı olarak kullanılan ya da kullanılacak, enerji ihtiyacı olan cihazlar nelerdir?
**Cevap:** Derste şu örnekler konuşuldu:

- Uzaktan programlanabilen çamaşır makinesi: Hoca bunun bir IoT cihazı olduğunu ama enerji ihtiyacı olmadığını söyledi.
- Robot süpürge: Hareketli olduğu için enerjisini çabuk bitirebilir, ama günün sonunda şarj etmek kolaydır. Hoca bunu soruya daha uygun bir örnek olarak kabul etti. Öğrenciler köşe temizliği için yan fırçaların tozu süpürge ağzına ittiğini, bunun büyük yol temizleme araçlarının küçük bir versiyonu olduğunu anlattı; hoca bunu mobil teknolojinin hayata etkisine iyi bir örnek olarak gördü.
- Büyük pil kapasiteli güvenlik kamerası: Evin uzak bir köşesine onlarca metre kablo çekmek yerine doğrudan monte edilir ve birkaç ayda bir şarj edilir.
- Yürüyüş bozukluğu için akıllı ayakkabı: Fizik tedavide yürüyüş bandındaki basınçlardan yürüyüş bozukluğu çıkarılıyor; bu sensörler ayakkabıya konursa belli aralıklarla şarj edilmesi gereken bir IoT cihazı olur. Hoca tam bu tür bir örneği aradığını söyledi.

Hoca ayrıca kaşık, çatal, tenis raketi gibi nesnelere çip yerleştirilerek insan davranışlarının analiz edilip edilemeyeceğini sordu; raket vuruşunun aslında akıllı saatle de analiz edilebileceğini hatırlattı.

### 10.3 Göz ameliyatı öncesi bakış mesafesi ölçümü

Hoca aklındaki bir IoT fikrini anlattı. Göz ameliyatında tek odaklı (monofokal), üç odaklı (trifokal) ve iki odaklı mercek seçenekleri vardır; geçişlerde kırılmalar olur ve doktorlar hastanın gün içinde ne kadar yakına, orta mesafeye ve uzağa baktığını bilmek ister. Fikir şudur: gözlüğün kenarına bir ivmeölçer ve kızılötesi (infrared) bir mesafe sensörü konur. Baş eğimi ivmeölçerden, önündeki nesneye uzaklık kızılötesi sensörden ölçülür. Önde bir nesne varsa kişi yakına bakıyordur, yoksa uzağa. Hasta cihazı bir hafta takarsa doktor ona sormadan bakış alışkanlıklarını öğrenebilir.

**Soru:** Göz bebeğinin büyüyüp küçülmesine bakılarak anlaşılamaz mı?
**Cevap:** Hoca fikrin güzel olduğunu, ama göz bebeğinin kamerayla görülmesi gerektiği için kontrollü ortam (örneğin araba kullanırken) gerektirdiğini söyledi. Günlük hayatta, yürüyüşte ya da ev içinde kişiyi sürekli kamerayla izlemek gerekir; bu da kullanıcıyı rahatsız eder. Hocanın ivmeölçer ve kızılötesi sensörü tercih etmesinin nedeni budur.

Hoca, sürücünün göz kırpma sıklığı ve aynalara bakma süresi üzerinden yorgunluk tespiti yapan bir çalışmayı da örnek verdi. Göz çok sık kırpılıyorsa ya da göz aralığı belli bir mesafeye inmişse uyku gelmiş olabilir. Hocaya göre bazı araç markalarındaki yorgunluk tespiti büyük olasılıkla bu mantıkla aynalara konan kameralarla yapılıyor; direksiyondaki nabız ölçerler de bilgi verebilir. Hoca önümüzdeki dönemde medikal sensörlerin öne çıkacağını, akıllı saatlere EKG ve oksijen ölçme özelliklerinin geldiğini, sensörlerin insan vücudunun fizyolojik davranışlarını analiz eden yapılara doğru geçtiğini söyledi.

## 11. Güç Tüketimi, Protokol Tasarım Güçlükleri ve Güvenilirlik

### 11.1 Güç tüketimi

Güç tüketimine bakıldığında radyo, yani haberleşme tarafı ciddi derecede yüksek enerji harcar; boşta (idle) olması bile ciddi tüketimdir. Sensör ve CPU'nun güç tüketimi çok düşüktür. Bu yüzden güç farkında (power-aware) protokollere ihtiyaç vardır. Hocaya göre sahada çalışan IoT cihazları için de aynı güç tüketimi yönetimi gerekecektir.

> **Ek bilgi (derste anlatılmadı):** Slayt listesindeki "Power Consumption" sayfasının küçük resminde sensör, CPU, TX, RX, IDLE ve SLEEP için bir çubuk grafik bulunuyor; RADIO başlığı altındaki TX, RX ve IDLE çubukları sensör ve CPU çubuklarından belirgin biçimde yüksek görünüyor. Grafik okunacak boyutta olmadığı için değerler buraya alınmadı.

### 11.2 Protokol tasarım güçlükleri

Ölçeklenebilirlik ve öz-yapılandırma (self-configuration) daha önce konuşulmuştu. Slayttaki diğer güçlükler şunlardı (ekrandan, 01:45:00):

- **Öz-optimizasyon ve uyum (self-optimization and adaptation):** Zamanla toplanan sensör ve ağ ölçümlerinden öğrenip bu öğrenmeyi performansı sürekli iyileştirmek için kullanmak.
- **Sistematik tasarım (systematic design):** Uygulamaya özel ağlar için yeniden kullanıma, modülerliğe ve çalışma zamanında uyuma izin veren sistematik tasarım yöntemleri gerekir.
- **Gizlilik ve güvenlik (privacy and security):** Bilginin hassasiyeti ve düşmanca ortamlara konuşlandırma.

### 11.3 Güvenilirlik ve hatalı sensör verisi

> **Hocanın vurgusu:** Listeye güvenilirlik (reliability) de eklenmelidir. Sensörlerden gelen veriye ne kadar güvenileceği, gizlilik ve güvenlik kadar önemli bir problemdir.

Güvenilirlikte iki ayrı risk vardır: verinin manipüle edilmesi ve cihazın sensörünün hatalı veri üretmesi.

**Soru (hocadan):** Bir bölgeden veri toplanırken hatalı veri üretilip üretilmediği nasıl anlaşılır?
**Cevap:** Bir öğrenci aykırı değer tespitini (outlier detection) önerdi; bunun için düğümün ölçümü diğer, özellikle yakındaki düğümlerinkiyle karşılaştırılır. Hoca bunun seçeneklerden biri olduğunu söyledi: düğüm çevresindeki düğümlerle haberleşir, hepsinin aynı büyüklük için algıladığı değeri alır ve aykırı bir durum varsa sensörün hatalı veri ürettiği bilgisi merkeze iletilir.

**Soru (hocadan):** Bir bölgede sıcaklık ölçülüyor ve cihazlar arasında 2-3 derecelik küçük farklar var; tam bir aykırı değer yok. Hangi değer kullanılır?
**Cevap:** Medyan ya da ortalama. Standart sapma yüksekse ortalama yanıltır ve medyan tercih edilmelidir; standart sapma düşükse genelde ortalama tercih edilir. Bu şekilde bir veri birleştirme yapılır.

Aynı mantık IoT için de geçerlidir. Bir evdeki çamaşır makinesi, buzdolabı gibi cihazlar veri gönderiyorsa, birbirleriyle haberleştikten sonra tek bir veri göndermeleri daha akıllıcadır. Bu iş bütün veriler merkeze gönderilerek değil, tek bir düğümde toplanıp karar verilerek yapılır.

## 12. Güvenlik: Ses Tabanlı Konumlama ve Şifreleme

### 12.1 Açık alandaki sensörlerin riski

Sensörler açık alana dağıtıldığı için düşman bunların üzerindeki veriyi alıp kullanabilir. Askeri uygulamalarda bu bir sorundur.

**Soru (hocadan):** Uzak noktalara yerleştirilen sensörlerle bir keskin nişancının yeri nasıl tespit edilir?
**Cevap:** Bir öğrenci sesi önerdi ve bir şehirde silah sesinin hangi bloktan geldiğini tespit eden mikrofonlardan söz etti. Hoca şunu ekledi: en az iki mikrofon olmak zorundadır, tek mikrofonla konum belirlenemez. Mikrofonlar arasındaki mesafe ve sesin mikrofonlara ulaşma süresine bağlı olarak konum hesaplanır. İkiden fazla mikrofonla daha doğru tespit yapılır.

Ses tabanlı tespitin bir avantajı, yüksek ses çıkaran bir olay tespit edilecekse sensörlerin düşmanın dibine kadar götürülmesinin gerekmemesidir. Böylece sensörler korunaklı bir şekilde konuşlandırılabilir.

> **Ek bilgi (derste anlatılmadı):** Bu yöntem varış zamanı farkı (time difference of arrival, TDOA) olarak bilinir. İki mikrofon arasındaki varış zamanı farkı, kaynağın bulunabileceği bir hiperbol eğrisi tanımlar; üçüncü bir mikrofon ikinci bir eğri verir ve kaynak eğrilerin kesişiminde bulunur. Hocanın "daha fazla mikrofonla daha doğru" demesi bu yüzdendir.

### 12.2 Şifreleme

**Soru (hocadan):** Sensörlerden ya da IoT cihazlarından gönderilen bilgi güvenlik açısından nasıl korunur?
**Cevap:** Bir öğrenci şifreleme yöntemlerini önerdi. Hoca şifrelemenin zorunlu olduğunu, ama kablosuz erişim noktaları ile kablolu ortamlar için kullanılan şifreleme yöntemlerinin aynı olmadığını söyledi: işlem gücü ve enerji tüketimi önemli olduğu için daha hafif versiyonlar kullanılır. Sensör ve IoT ağlarında da aynı kısıt vardır.

Seçilecek yöntemin uç noktada şifreleme (encrypt) yaparken daha az enerji harcaması, şifre çözmede (decrypt) daha uzun işlem yapacak şekilde tasarlanması önemlidir. Telefonda kullanılan bütün şifreleme ve çözme işlemlerinin de bir maliyeti vardır.

Temelde iki yöntem vardır: gizli anahtar (private key) kullanmak ve açık anahtarlı kriptografi (public key cryptography). Hoca, açık anahtarlı kriptografinin daha çok gizli anahtarların değişimi için kullanıldığını, haberleşmenin sonra bu anahtarlar üzerinden yapıldığını, ama farklı tasarımların da kurulabileceğini söyledi.

> **Ders sonrası not:** Hocanın "private key" dediği, büyük olasılıkla tarafların paylaştığı simetrik (gizli) anahtardır. Açık anahtarlı sistemlerdeki "private key" ise yalnız sahibinin bildiği anahtardır ve paylaşılmaz. Hocanın anlattığı akış, açık anahtarlı kriptografiyle bir simetrik oturum anahtarının değiştirilip haberleşmenin bu anahtarla sürdürülmesidir.

## 13. WSN Uygulamaları

Slayttaki WSN uygulamaları şunlardı (ekrandan, 01:55:00):

- Askeri
- Çevre/habitat izleme
- Sağlık
- Acil durum/gözetim
- Afet erken uyarı sistemleri
- Ulaşım ve lojistik
- Yapısal/endüstriyel izleme

Afet erken uyarı sistemlerinde sensörler rastgele atılmaz. Sismik hareketleri izlemek için özellikle deniz tabanlarına sensörler yerleştirilir ve kırığın ilerlemesiyle ilgili bilgi edinilmeye çalışılır.

### 13.1 Su altı sensör ağları

**Soru (hocadan):** Su altı akustik sensör ağlarında (Underwater Acoustic Sensor Networks) neden normal bir sensör düğümü tasarımı kullanılmıyor da farklı düğüm ve farklı ağ çözümleri gerekiyor?
**Cevap:** Bir öğrenci su altında aktarımın havadaki gibi olmayacağını söyledi. Hoca bunu açtı: bilgiyi aktarmak için kullanılan ortam (medium) farklıdır. Suda sinyalin kırılım olasılığı ve gücünü kaybetme olasılığı yüksektir. Bu toprak altı sensörler için de geçerlidir. Farklı düğümler ve farklı protokoller gerekir; veri aktarım hızı havaya göre çok düşer.

Su altı düğümleri farklı derinliklerde asılı kalır. Bu yüzden modellemeleri üç boyutlu olmalıdır. Karada, üç boyutlu bir ortamda yaşansa da arazi uygunsa düğüm dağılımı iki boyutlu tasarlanabilir; denizde düğümler yüzeye ve farklı derinliklere yerleştirildiği için kapsama gibi bütün problemler 3B ele alınmalıdır.

### 13.2 Ulaşım, lojistik ve yapısal izleme

Ulaşım ve lojistikte ürünlerin üzerindeki RFID etiketleri, ürünün bir noktadan ayrılıp ayrılmadığı ve nerede olduğu bilgisini verir. İnşaat mühendisliğinde viyadük ve köprülerin fiziksel dayanıklılığı ve yollarda buzlanma izlenir. Hoca, viyadüklerden kış döneminde alınan verilere göre tuzlanacak yerlerin seçildiği bir uygulamayı örnek verdi.

### 13.3 Çevresel sorunlar ve aktüasyon

Hoca su kullanımında bilinçlenme gerektiğini, diş fırçalarken ya da bulaşık yıkarken ne kadar su harcandığını gözlemleyen akıllı evlere ihtiyaç olduğunu söyledi. Bu da WSN ve IoT cihazlarının çevresel problemleri çözmek için kullanılmasını gerektirir.

> **Hocanın vurgusu:** IoT'nin WSN'den en büyük farkı aktüasyon, yani eylem alma yeteneğidir. Eskiden çevre gözlenip anlaşılmaya çalışılıyor ve tespit yapılıyordu. Şimdi hava aydınlıksa ışık otomatik kapanıyor, toplantı odasından insanlar çıkınca ışık kapanıyor.

Hoca ayrıca otomatik sistemler tasarlansa bile bu sistemlerin çalışmadığı durumları da gözeten tasarımlar yapılması gerektiğini söyledi; örneğin bütün katların ışıklarının yalnız bir merkezden kontrol edildiği bir binada otomasyon kurulamazsa ciddi kullanım sorunu doğar. Ona göre otonom hayata geçiş de kademeli olacaktır.

## 14. IoT ile WSN'in Karşılaştırılması

Dersin son bölümünde hoca IoT slaytlarına geçti.

### 14.1 Temel farklar

- WSN'de tek yönlü bilgi akışı vardır, IoT'de çift yönlü.
- WSN'de onlarca, yüzlerce sensör vardır ve bunların IP adresi yoktur; doğrudan erişilemezler. IoT cihazlarına normalde doğrudan erişilebilir.
- IoT cihazlarının bugünkü en büyük sorunu IPv6'nın yaygınlaşmamasıdır. Cihaz bir ağ geçidinin (gateway) arkasında kalır ve iç ağdan adres alır; doğrudan adresleme olmaz, ağ adres dönüşümü (network address translation, NAT) gerekir.

### 14.2 Üç bakış açısı

IoT'ye üç bakış açısı vardır: internet odaklı (internet-oriented), nesne odaklı (things-oriented) ve anlam odaklı (semantic-oriented). İnternet odaklı bakışta artık yalnız Internet of Things değil, Web of Things de vardır. IoT, internet üzerinden doğrudan erişilebilir bütün eşyalara verilen genel isimdir ve farklı versiyonları ortaya çıkmıştır. Her noktadan bağlanılabilir olmak hem internetin kapsamı içindedir hem de nesnenin yeteneklerinden biri haline gelmiştir. <!-- BELİRSİZ: Altyazıda "Fox Things" diye geçen ve bu sürümlerden biri olarak anılan terim tam anlaşılmadı. -->

Kablosuz sensörler ve aktüatörler nesne odaklı bakışta bir küme olarak yer alır. Bu yüzden WSN, IoT'nin hem dönüşmüş hali hem de bir alt grubu gibi düşünülebilir. Ama WSN'in IoT gibi bir adreslenme yeteneği yoktur; alt grup gibi görülse de IoT'nin özelliklerini taşımaz.

### 14.3 Veri hacmi ve saklama

IoT cihazlarının ürettiği veri çok büyüktür ve saklanması gerekir. Cihazların kendi üzerinde bu kapasite yoktur; veri belli bir yere kadar depolanabilir, sonra anlamlandırılıp taşınması gerekir. Bu durumda ham veri saklanır, üzerinde belli bir süre işlem yapılır ve sonra silinir. Hoca, şirketlerin son bir haftalık video kayıtlarını saklamakla yükümlü olması gibi düzenlemeleri örnek verdi.

### 14.4 Spime: yer ve zaman

Slayttaki tanıma göre spime, IoT'nin yanında ortaya çıkan bir kavramdır: yaşam süresi boyunca uzay (SPACE) ve zaman (TIME) içinde izlenebilen, sürdürülebilir, geliştirilebilir ve tekil olarak tanımlanabilir bir nesne (ekrandan, 02:15:00). Aynı karede ITU vizyonu da yer alıyordu: "herkes için her zaman, her yerde bağlantıdan, her şey için bağlantıya" (ekrandan, 02:15:00).

> **Hocanın vurgusu:** IoT cihazı tanımlanırken iki bilgi kritiktir: yer (space) ve zaman (time). Verinin nereden ve ne zaman alındığı önemlidir.

Hoca bunun nedenlerini sıraladı:

- Bu iki bilgiye göre model oluşturulur ya da çıkarım yapılır; karar mekanizmasını doğrudan etkiler.
- Zaman bilgisi verinin güncel (up to date) olup olmadığını gösterir.
- Yer bilgisi verinin doğru yerden gelip gelmediğini gösterir.
- Yer bilgisi korelasyon imkanı verir: birbirine yakın konumlardaki veriler korele edilebilir.

Zaman bilgisi veriyle birlikte taşınmak zorundadır. Yer bilgisinin her pakette taşınması gerekmez, ama IoT cihazı yer değiştirdiği anda bunu merkeze bildirmek zorundadır.

### 14.5 Nesnelerin kimliği ve topluluk

Hocaya göre IoT'ye her eşyanın bir kimliği olduğu bilgisinden yola çıkarak bakılmalıdır. Bu cihazlar birer sanal kişiliktir. Birbirleriyle etkileşirken yeteneklerinin bilinmesi gerekir: üzerlerinde hangi sensörler var, bu sensörler hangi verileri ne sıklıkla toplayabiliyor. Böylece aynı topluluktaki (community) cihazlar veri paylaşabilir, birbirlerinin yerine veri toplayabilir, biri yetmediğinde diğeri devreye girebilir ya da birinin yerini alabilir. Artık (redundant) cihazlar olabilir.

### 14.6 Ara katman (middleware)

Her cihaza doğrudan erişmek güzel bir fikirdir: cihazlar tek tek yapılandırılabilir ve istenildiği zaman bilgi alınabilir. Ama bunun bir güvenlik riski vardır. Herkesin erişimine açık bir cihaza aynı anda çok sayıda kişi erişirse ya da bilinçli olarak istek gönderilirse hizmet engelleme (denial of service) olur. Bu yüzden IoT cihazlarından toplanan veriyi organize edip servis edecek bir ara katmana (middle layer) ihtiyaç vardır. Hocaya göre cihazlar doğrudan erişilebilir tasarlanmış olsa bile araya katman koymanın önemi son çalışmalarda bir kez daha görülmüştür.

Slayttaki "IoT ara katmanı için SOA tabanlı mimari" şekli şu katmanlardan oluşuyordu; yanlarında güven, gizlilik ve güvenlik yönetimi katmanı dikey olarak yer alıyordu (ekrandan, 02:20:00):

```text
Applications
Service Composition
Service Management
Object Abstraction
Objects
```

### 14.7 Uygulama alanları

Slayttaki IoT uygulama alanları şunlardı (ekrandan, 02:20:00):

- **Ulaşım ve lojistik:** lojistik, destekli sürüş (assisted driving), mobil biletleme, çevre izleme, artırılmış haritalar.
- **Sağlık:** takip, tanımlama/kimlik doğrulama, veri toplama, algılama.
- **Akıllı ortamlar:** konforlu evler/ofisler, endüstriyel tesisler, akıllı müze ve spor salonu.
- **Kişisel ve sosyal:** sosyal ağlar, geçmiş sorgular, kayıplar, hırsızlıklar.
- **Fütüristik:** robot taksi, şehir bilgi modeli, gelişmiş oyun odası.

Hoca destekli sürüşün sık duyulacak bir kavram olacağını, çevre izlemenin artık yalnız WSN'de değil akıllı binalar ve akıllı şehirlerde kullanıldığını söyledi.

**Soru (hocadan):** IoT uygulamasının WSN uygulamasından farkı nedir?
**Cevap:** Bir öğrenci IoT'nin seviye olarak daha yüksek, daha çok işletim sistemi katmanına yakın olduğunu söyledi. Hoca farkı şöyle açıkladı: IoT uygulamaları insan odaklıdır (human oriented), doğrudan insanların ihtiyaçlarını çözmeye ve yaşam kalitesini yükseltmeye yöneliktir. WSN uygulamaları göreve özeldir (task specific): tarımsal uygulama, hayvanlarla ilgili uygulama, meteorolojik uygulama. Örneğin akıllı ulaşımda hedef insanın bir noktadan diğerine en az bekleyerek gitmesidir; çevresel bir WSN uygulamasında ise ortam gözlemlenir, müdahale edilmez, yalnız tespit yapılır. Akıllı tarımda akıllı sulama için WSN kullanımı bir geçiş uygulamasıdır ve iki tarafa da sayılabilir. IoT çözümlerinde özel tasarlanmış düğümler yerine doğrudan ilgili nesne yapılandırılır: çekilen bir boru hattındaki vana açılıp kapatılır.

### 14.8 Açık sorunlar

IoT'deki açık sorunlar arasında şunlar sayıldı:

- Kimlik doğrulama (authentication)
- Gizlilik (privacy)
- Veri bütünlüğü (data integrity)
- Trafik karakterizasyonu: hangi paketin önce gideceği, hangi bilginin kesintisiz gitmesi gerektiği, hangi bilginin daha acil olduğu.
- Dijital unutma (digital forgetting): veri temizliğinin nasıl yapılacağı, cihazların topladıkları bilgilerden nasıl kurtulacağı. Hoca bu konuda araştırma yapılması gerektiğini söyledi.

WSN'de Zigbee kullanılıyordu ve belli sınırlar içinde haberleşildiği için büyük sorun yoktu. IoT cihazlarının taşıdığı veri miktarı çok arttığı için paketlerin ekstra yükü (overhead) olmamalı, başlık kısmı çok küçük olmalıdır. Daha önce konuşulan MQTT önemli mesajlaşma protokollerinden biridir; CoAP da kullanılır. Hoca bunları TCP ve UDP'ye benzetti. Yine de IoT tarafında yerleşmiş, tam kabul görmüş bir protokol yoktur ve literatürde alternatif arayışı sürmektedir.

Son olarak hoca ömür farkını vurguladı: WSN uygulamaları uygulamaya özeldir ve görev tamamlanınca işi biter. IoT ağları ise beş-altı aylık süreçler için değil, yıllarca çalışmak üzere kurulur. IoT uygulamaları tasarlanırken bu gözden kaçırılmamalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:06:10): Android telefonda, yalnız ivmeölçer kullanan bir düşme tespiti uygulaması tasarlayın. Uygulama en az bir kural tabanlı (eşikleme), bir makine öğrenmesi ve bir derin öğrenme yöntemi içersin; X, Y, Z verisini sinyal vektör büyüklüğüne çevirsin, bir ön işleme adımı uygulasın, 2-3 saniyelik pencerelerden en az beş öznitelik çıkarsın ve her 3 saniyede bir karar versin. Modeli MobiFall veri setiyle kurun ve okuma, ön işleme, öznitelik çıkarma ve sınıflandırma adımlarının enerji tüketimine etkisini karşılaştırın.

> **Çözüm (derste verilmedi):** Derste yalnız işlem hattı tarif edildi (Bölüm 1 ve 2). Büyüklük sinyali $\sqrt{x^2+y^2+z^2}$ ile hesaplanır, pencere başına ortalama, standart sapma, maksimum, minimum gibi en az beş öznitelik çıkarılır. Enerji karşılaştırması şarjsız gerçek telefonda, küçük farklar için uzun süreli ya da çok sayıda tekrarlı çalıştırmalarla yapılır ve yüzde ya da joule olarak raporlanır.

**Soru 2** (derste sözlü, 00:43:49): Sensör ağlarında topoloji neden genelde statiktir?

Cevap derste verildi: Düğümler hareket edemediği için bir kez atıldıktan sonra o topoloji benimsenir. Mobil sensör ağlarında ise bir kısmı mobil düğümlerle heterojen ağlar kurulur.

**Soru 3** (derste sözlü, 00:51:33): Olaya dayalı bir sensör ağında bir aracın geçtiği nasıl tespit edilir? Yöntemlerin artı ve eksileri nelerdir?

Cevap derste verildi: Lazer/termal tarama pahalıdır ve sürekli tam kapsama zordur; basınç sensörü araç üzerinden geçmezse tetiklenmez; ortam sesi daha ucuz ve kapsaması daha yüksektir. Elektrikli araçlar ses, basınç ve sıcaklık izleri az olduğu için bu yöntemler için zorluk oluşturur.

**Soru 4** (derste sözlü, 01:14:51): Günlük hayatta sık kullandığımız bir yıldız topoloji örneği verin. Bu topoloji sensör ağlarında neden uygulanamaz?

Cevap derste verildi: Kablosuz erişim noktası (ve baz istasyonu). Sensör ağlarında çok sayıda düğüm tek atlamayla uzaktaki baz istasyonuna erişirse enerjileri çabuk tükenir; bu yüzden çok atlamalı haberleşme kullanılır.

**Soru 5** (derste sözlü, 01:20:33): IoT cihazı olarak kullanılan ya da kullanılacak, enerji ihtiyacı olan cihazlara örnek verin.

Cevap derste verildi: Robot süpürge, büyük pilli kablosuz güvenlik kamerası, yürüyüş bozukluğunu basınçtan çıkaran akıllı ayakkabı. Çamaşır makinesi bir IoT cihazıdır ama enerji ihtiyacı yoktur.

**Soru 6** (derste sözlü, 01:44:51): Bir sensör ağında bir bölgeden veri toplanırken hatalı veri üretilip üretilmediği nasıl anlaşılır? Ölçümler arasında yalnız küçük farklar varsa birleştirmede hangi değer kullanılır?

Cevap derste verildi: Düğümün ölçümü komşu düğümlerinkiyle karşılaştırılır (aykırı değer tespiti) ve aykırılık merkeze bildirilir. Küçük farklarda standart sapma yüksekse medyan, düşükse ortalama kullanılır; birleştirme bir düğümde yapılır.

**Soru 7** (derste sözlü, 01:47:13): Uzak noktalara yerleştirilen sensörlerle bir keskin nişancının yeri nasıl bulunur?

Cevap derste verildi: Ses ile. En az iki mikrofon gerekir; konum, mikrofonlar arası mesafe ve sesin mikrofonlara varış süresinden hesaplanır. Daha fazla mikrofon daha doğru sonuç verir.

**Soru 8** (derste sözlü, 01:48:25): Sensörlerden ya da IoT cihazlarından gönderilen bilgi nasıl korunur? Şifreleme yöntemi seçerken neye dikkat edilir?

Cevap derste verildi: Şifreleme gerekir, ama işlem gücü ve enerji kısıtı yüzünden hafif yöntemler kullanılır. Uç noktada şifreleme az enerji harcamalı, ağır iş çözme tarafında olmalıdır. Açık anahtarlı kriptografi çoğunlukla gizli anahtarların değişimi için kullanılır.

**Soru 9** (derste sözlü, 01:51:38): Su altı akustik sensör ağlarında neden normal bir sensör düğümü tasarımı kullanılmaz?

Cevap derste verildi: Aktarım ortamı farklıdır; suda sinyal kırılımı ve güç kaybı yüksektir, veri hızı düşer. Farklı düğüm ve protokoller gerekir ve kapsama gibi problemler 3 boyutlu modellenmelidir.

**Soru 10** (derste sözlü, 02:18:51): IoT uygulaması ile kablosuz sensör ağı uygulaması arasındaki fark nedir?

Cevap derste verildi: IoT uygulamaları insan odaklıdır ve doğrudan yaşam kalitesini artırmaya, gerekirse eyleme geçmeye yöneliktir. WSN uygulamaları göreve özeldir (tarım, hayvan izleme, meteoroloji) ve çoğunlukla gözlem ve tespitle sınırlıdır.

## Dersin Toparlaması

Ders iki parçadan oluştu. İlk parçada dönem boyunca işlenen sensör verisi işleme adımları, Android üzerinde bir düşme tespiti uygulamasında birleştirildi: ivmeölçer verisinin büyüklük sinyaline indirgenmesi, ön işleme, 2-3 saniyelik pencereler, temel öznitelikler, kural tabanlı, makine öğrenmesi ve derin öğrenme sınıflandırıcıları. Bu uygulamanın asıl sorusu, her adımın ve her sınıflandırıcının telefonun enerji tüketimine etkisidir.

İkinci parçada kablosuz sensör ağları ele alındı: many-tiny ilkesi, düğüm donanımı ve kısıtları, tarihçe, asimetrik ve olaya/sorguya dayalı haberleşme, ağ içi işleme ve küme başları, haberleşme örüntüleri, veri toplama modelleri, konuşlandırma türleri, topolojiler, güç tüketimi ve protokol tasarım güçlükleri. Hoca bu anlatımın gerçek hayatta beklenen ölçüde uygulanmadığını ve alanın IoT'ye evrildiğini vurguladı. Son bölümde IoT ile WSN karşılaştırıldı: çift yönlü akış ve adreslenebilirlik, spime kavramı (yer ve zaman bilgisi), ara katman mimarisi, insan odaklı uygulamalar, aktüasyon ve dijital unutma ile protokol eksikleri gibi açık sorunlar. Hoca IoT konusuna sonraki derste devam edileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
