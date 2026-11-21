# Ders 2 Genişletilmiş Notu: Bağlam Farkındalığı (Context-Awareness), IoT ve Sensör Ağları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlam Farkındalığına Giriş
- 2. Mobil Hesaplama ve İlişkili Alanlar
- 3. Mobil Haberleşme Teknolojileri ve 5G
- 4. İnsan-Bilgisayar Etkileşimi, Sanal Asistanlar ve Duygu Farkındalığı
- 5. Yaygın Hesaplama ve Veri Yönetimi Sorunu
- 6. Sensör Ağları: Küme Başı ve Yinelenen Veri
- 7. Büyük Veri: 4V Kuralı
- 8. IoT'de Doğrudan Erişim, Güvenlik ve Ara Katman
- 9. IoT Verisinin Yönetimi: Alanlar, Protokoller, Saklama
- 10. İnternetin Evrimi ve IoT Ekosisteminin Sorunları
- 11. Sensör Ağı ile IoT Arasındaki Farklar
- 12. Bağlam Farkındalığı Uygulaması: Sürüş Analizi ve Yorgunluk
- 13. IoT Tanımları, Türleri ve Kategorileri
- 14. Sanal Sensörler
- 15. Sensör Ağlarına Dönüş, Eyleyiciler ve IoT'nin Temel Özellikleri
- 16. IoT Cihazlarında İşletim Sistemi
- 17. Bağlam (Context) ve Bağlam Farkındalığı
- 18. Bağlam Modeli, Öznitelikleri ve Bağlam Kalitesi

## 1. Bağlam Farkındalığına Giriş

Bu haftanın konusu bağlam farkındalığı (context-awareness) ve onunla ilişkili kavramlardır. Hoca, slaytlar her şeyi kapsamadığı ve konu konuyu açtığı için ders sırasında not alınmasını tavsiye etti.

Elektronik cihazlar artık çevrelerini anlayabilen bir noktaya geldi. Giyilebilir cihazlardan taşınabilir cihazlara kadar, hatta masaüstü ortamında çok fazla sensörle uğraşılmasa da dizüstü bilgisayarlara yeni sensörler eklenmeye başlandı. Hoca bunu insanın karar verme biçimiyle karşılaştırdı: İnsan karar verirken hem geçmiş deneyimlerine hem de o anda aldığı girdilere dayanır ve aynı anda birden fazla kaynaktan beslenir. Bağlam farkında hesaplamada da kameradan alınan görüntüden mikrofondan alınan sese, ivmeölçerden gelen bilgiye kadar her şeyi harmanlayarak kullanmak çok önemlidir.

Slaytta "What is Context-Awareness?" başlığı altında bağlam farkındalığının görüldüğü alanlar sıralanıyordu: masaüstü uygulamalar, web uygulamaları, mobil hesaplama ve yaygın (pervasive/ubiquitous) hesaplama (ekrandan, 00:15:00). Slaytın konuşmacı notunda kavramın tarihçesi de yer alıyordu: "ubiquitous computing" terimi Mark Weiser'ın 1991'deki "The Computer for the 21st Century" makalesiyle ortaya çıktı, "context-aware" terimi ilk kez 1994'te Schilit ve Theimer tarafından kullanıldı; araştırma topluluğunun bugün kabul ettiği "context" ve "context-awareness" tanımları ise 1999'da Abowd ve arkadaşları tarafından önerildi (ekrandan, 00:15:00).

## 2. Mobil Hesaplama ve İlişkili Alanlar

Bazı uygulamalar artık bayrağı mobil hesaplama (mobile computing) ile birlikte taşıyor. Kullanıcılar işlerinin çoğunu web tarayıcısı yerine telefondaki uygulamalarla yapıyor, çünkü uygulamalar daha kullanıcı dostu ve kullanıcı deneyimi daha yüksek; iki üç tuşla iş bitiyor. Tarayıcının içinde ise yönetilmesi kolay olmayan çok farklı noktalar var.

Hoca burada bir soru sordu: Uygulamalar her geçen gün özelleşiyor, telefona yüzlerce uygulama indiriliyor ve bir kısmı hiç kullanılmıyor. İleride ne olacak?

**Soru:** Bu sorunun çözümü ne olabilir? **Cevap:** Bir öğrenci, son dönemde hem Google hem Apple tarafında doğrudan tarayıcı üzerinden indirilip anlık kullanılan, 1-2 MB boyutundaki mini uygulamaları örnek verdi; 50-100 MB'lık bir uygulamayı indirip bir daha kullanmamak internet paketinden de gidiyor. Hoca bunu doğruladı: Anlık uygulamalar (instant applications) var ve kullanıcı uygulamanın yalnız kullanacağı bölümünü, modül bazında talep edebiliyor. Hoca bunun Android tarafında kurulduğunu, Apple tarafını kesin bilmediğini söyledi. Mantık mikro servislere benzer: uygulamayı bütün olarak kullanmak yerine servis özelliklerine odaklanmak.

Ardından mobil hesaplamanın hangi bilgisayar mühendisliği alt alanlarına dokunduğu soruldu. Derste toplanan cevaplar:

- Dağıtık sistemler (distributed computing).
- Nesnelerin interneti (IoT); Endüstri 4.0 ile ilişkisi nedeniyle artık bir alan olarak geçiyor.
- Konum tabanlı hesaplama (location-based computing).
- Yapay zekâ: Bir ortamdan bilgi alınıyorsa o bilgiyi işlemek çok önemlidir. Ham veriyi kullanmak tercih edilen bir yol değildir; veriyi işleyip anlamlandırmak, bilgi düzeyine getirmek gerekir.
- Mobil ağlar (mobile networking): Verinin nasıl taşınacağı.
- İnsan-bilgisayar etkileşimi (human-computer interaction, HCI).
- Yaygın (pervasive/ubiquitous) hesaplama.

Hoca, mobil hesaplamanın altında üç ana başlık olduğunu söyledi: mobil iletişim (mobile communication), mobil donanım (mobile hardware) ve mobil yazılım (mobile software).

## 3. Mobil Haberleşme Teknolojileri ve 5G

**Soru:** Mobil hesaplama için hangi protokoller var? **Cevap:** Derste sayılanlar: Bluetooth, Wi-Fi, ZigBee (hoca çok kullanılmadığını belirtti), IEEE 802.15.4, NFC (Near Field Communication) ve son dönemde ortaya çıkan Bluetooth Low Energy. Bluetooth Low Energy beacon'larda ve iç mekân konumlandırma bilgisi oluşturmada kullanılıyor. GPS verisi de bu kaynaklar arasında. Bir öğrenci radyo frekansını (RF) ekledi; hoca, protokollerin üstüne çıkıldığında bilgiyi taşıma yönteminin başında radyo frekansının geldiğini, bu protokollerin çoğunun radyo frekansı kullandığını söyledi. Baz istasyonu üzerinden çalışan protokoller olarak LTE, HSDPA ve UMTS sayıldı; bunlar 2G, 3G ve 4.5G'ye denk gelir, 5G de birkaç yıl içinde hayatımıza girecek.

**Soru:** 5G'nin diğer baz istasyonu protokollerinden en önemli, çığır açacak farkı nedir? **Cevap:** Öğrencilerden "hız" ve "eş zamanlı bağlantı" cevapları geldi. Hoca eş zamanlı bağlantının bir fark olduğunu kabul etti, ama asıl farkı gecikme (latency), yani tepki süresi olarak açıkladı: Hedeflenen değer yaklaşık 1 milisaniyelik tepki süresidir. Bu otonom araçlar için olmazsa olmazdır. Bir öğrencinin verdiği örnekle: Oyunda bir gecikme (lag) olduğunda rakibi vuramazsınız; otonom araçta gecikme olursa ciddi bir kaza yaşanır.

Hoca, kararların çoğunu çevrim içi vermek riskli olsa da sunucuya gidip gelme süresinin 1 milisaniyeye inmesinin bu riski azaltacağını, bu yüzden 5G'nin otonom araçlar için en çok beklenen teknolojilerden biri olduğunu söyledi. Öte yandan çevrim içi araçlar yeni güvenlik riskleri getirir: Bir aracı uzaktan ele geçirip yoldan çıkarmak gibi saldırılar gelecekte karşılaşılabilecek can sıkıcı gelişmelerdendir.

## 4. İnsan-Bilgisayar Etkileşimi, Sanal Asistanlar ve Duygu Farkındalığı

### 4.1 Etkileşim Biçimleri

İnsan-bilgisayar etkileşimi çok popüler bir araştırma konusudur ve konferans sayıları ciddi biçimde artmıştır. Temel hedef, cihazlarla iletişimi mümkün olan en hızlı ve en verimli hâle getirmektir.

**Soru:** Standart bilgisayardaki klavye ve farenin dışında hangi etkileşim biçimleri kullanılmaya başlandı? **Cevap:** Derste sayılanlar: sanal klavye, dokunmatik ekranlar, dokunmatik ekranda iki boyutlu hareketten basınç uygulayarak üç boyutlu harekete geçiş ve ses girişi (sesli asistanlar).

Ses işleme özellikle cihazlarla haberleşmede çok öne çıktı. Hoca birkaç yıl önce yapılmış bir çalışmayı anlattı: Anlık mesajlaşma uygulamalarında hızlı yazarak oluşturulan metin ile sesli komutla oluşturulan metin arasındaki enerji tüketimi karşılaştırılmış ve uzun metinlerde ses üzerinden giriş yapmanın daha verimli olduğu bulunmuş. Araba kullanırken de birçok kritik işte sesli komutlar kullanılıyor.

### 4.2 Sanal Asistanlar

Sanal asistanlar hayatımıza önce Siri ve Google'ın sesli asistanı ile, sonra Alexa ile girdi. Bir öğrenci operatörlerin telesekreterleri yerine kullanılan sistemleri ekledi; hoca bunların bir tür sohbet botu (chatbot) olduğunu, sohbet botunun da bir sanal asistan sayılabileceğini söyledi. Sohbet botları kalıplaşmış soruları sisteme öğreterek, insan çalıştırmadan, standart soruları hızla cevaplar; hem kullanıcı memnuniyeti yüksek tutulur hem maliyet düşer. Her dil için ayrı bir yapı kurulması gerekir.

Sanal asistanlarda iki yapı öne çıkar:

- Ses işleme: konuşmadan metne (speech-to-text) ve metinden konuşmaya (text-to-speech).
- Doğal dil işleme (natural language processing): öğretilen ifadeler içinde analiz yaparak cevap üretme.

**Soru:** Sanal asistanlar yaklaşık on yıldır gelişiyor ama hâlâ hava ve yol durumu sormanın ötesine pek geçemiyor. Yetenekleri nereye kadar gelişebilir? **Cevap:** Bir öğrenci, müşteri hizmetlerinde kullanıcının asistanla görüşmesinden memnuniyetini ölçen, memnun değilse başka bir asistana yönlendiren ve ses tonunu buna göre değiştiren bir sistemden söz etti. Hoca bunun çok önemli bir nokta olduğunu söyledi: Burada duygu analizi devreye giriyor.

### 4.3 Duygu Farkında Hesaplama

Hocaya göre önümüzdeki yıllarda en çok uğraşılacak konulardan biri insanların duygu durumunu tespit etmek olacak. Amaç yalnız standart işleri bilgisayara yaptırmak değil, insanın duygu durumuna göre çözüm üretmektir. Örneğin bir müşteri temsilcisi görüşmesinde ne kadar sessizlik olduğu, sesin ne kadar yükseldiği, gerginlik olup olmadığı, müşterinin telefonu memnun kapatıp kapatmadığı analiz edilebilir. Bu duygu farkında hesaplama (emotion-aware computing) yeni konuşulmaya başlanan bir kavramdır ve hoca bunu tez konusu olmaya uygun bir alan olarak gösterdi.

Eskiden bağlam farkındalığı denince odanın ışığının açık olup olmadığı, kombinin çalışıp çalışmadığı, sıcaklığın düşüp düşmediği gibi standart sensör olaylarını algılayıp çözüm üreten çevresel zekâ (ambient intelligence) anlaşılıyordu. Bugün ortamı algılayan çok sayıda sensör var ve kısıtlar oldukça genişledi. Yeni hedef insan duygularını sesten ve yüz ifadesinden (görüntü işleme ile) algılamaktır. Hoca uzun vadeli bir örnek verdi: Yaşam süresi uzadıkça insanlar yanlarında bir arkadaş isteyecek; robotlar insanların o anki duygusunu algılayıp onlarla bu tür bir paylaşım kuracak.

## 5. Yaygın Hesaplama ve Veri Yönetimi Sorunu

### 5.1 Yaygın Hesaplama

Yaygın hesaplama (pervasive computing) ve her yerde hesaplama (ubiquitous computing) aynı ifadedir: Her an, her yerden, her cihazdan ve her formatta erişilebilir bir yapı kurulursa yaygın hesaplama altyapısı tamamlanmış olur.

Hoca bilgisayarların ilk dönemini hatırlattı: Eskiden N kişi tek bir cihazı kullanıyordu; programlama yapılacağında operatör odasında sıraya giriliyor, biri programını verip çıktısını alıyor, sonra diğeri giriyordu. Bugün bir kişi N cihaz kullanıyor.

**Soru:** Bir kişinin N cihaz kullanmasının yarattığı teknik sorunlar nelerdir? **Cevap:** Öğrencilerden gelen ilk cevaplar şunlardı: hangi cihazı kimin kullandığını bilmek (hoca, telefonlarda pek kullanıcı yönetimi olmadığını, tek kullanıcı üzerinden ilerlendiğini, ortak cihaz kullanımında bu konuda gelişmeler olabileceğini söyledi) ve çok sayıda cihazın insanın odaklanmasını bozması (hoca bunun doğru ama sosyal bir tespit olduğunu söyledi). Hocanın aradığı teknik cevap veri yönetimiydi: Her cihazda farklı veri var.

**Soru:** Bu veri sorununu çözmek için hangi alan oluştu? **Cevap:** Bir öğrenci dağıtık sistemlerdeki tutarlılık (consistency) sorunlarını, bir başkası bulutu söyledi. Hoca, dağıtık sistemlerin bugün daha bilinen adıyla bulut bilişim (cloud computing) olarak karşımıza çıktığını, ama ikisinin birebir aynı kavram olmadığını belirtti. Bulut bilişimin sorunlarından biri verinin yinelenmesidir (redundancy): İyi bir organizasyon kurulmazsa bir cihazın yereline indirilen veri diğer cihazın yerelinde de bulunur ve bu, saklanan verinin boyutunu doğrudan artırır. Depolama kapasiteleri terabaytlara çıksa da cihazların hafızası dolmaya başlar.

### 5.2 Asıl Sorun: Sensör ve IoT Verisi

**Soru:** Veri yönetiminde gelecekteki en büyük sorun nedir? **Cevap:** Sensör ağlarının ve IoT cihazlarının üreteceği veri miktarı. Hoca, yakın gelecekte 50 milyar cihazın IP adresi alacağı bir dünyada her ortamdan toplanan verinin saklanmasının ciddi sorunlar çıkaracağını söyledi. Görüntünün çözünürlüğü ya da saniyedeki kare sayısı biraz artınca boyut çok büyür. Sıcaklık gibi fiziksel veriler küçüktür, ama bir ormandaki sensörlerin hepsi aynı bölgeden veri gönderirse aslında yinelenen bilgi gönderilmiş olur.

**Soru:** Bu veri boyutunu azaltmak için ne yapılır? **Cevap:** Bir öğrenci, ham veri yerine sonucu saklamayı, veriyi temsil edebilecek en küçük veriyi tutmayı önerdi. Hoca bunu doğruladı: Ham veriyi göndermek yerine mümkünse yerinde işleme yapmak gerekir. Bu, yerinde işleme (in-situ processing) ya da tesis içi işleme (on-premise processing) diye geçer. Buluta aktarılan veri hem bant genişliği hem maliyet açısından elenerek azaltılmalıdır. Bunun adı uç bilişimdir (edge computing): Uç noktadaki cihazlar ham veriden bilgi (information, knowledge) çıkarabilecek düzeye gelmelidir.

> **Hocanın vurgusu:** Yerinde işleme (in-situ / on-premise processing) ve uç bilişim (edge computing) kavramları not edilmeli; bu kavramlar gün geçtikçe yaygınlaşıyor.

## 6. Sensör Ağları: Küme Başı ve Yinelenen Veri

### 6.1 Küme Başı

Sensör ağları bir alana dağıtılır, o alandan bilgiyi alıp merkeze gönderir. Ancak düğümlerin enerjisi kısıtlıdır, bu yüzden ömürleri de kısıtlıdır; işlem kapasiteleri de sınırlıdır. Zamanla şu mekanizma gelişti: Düğümler arasından bazıları seçilir, veriler bu düğümlerde toplanıp harmanlanır ve oradan merkeze gönderilir. Bu düğümlere küme başı (cluster head) denir. Küme başları iki biçimde belirlenir:

- Bölgeye daha güçlü, işlem kapasitesi yüksek ve enerjisi çabuk bitmeyen özel bir düğüm atılır.
- Düğümler aynı kapasitedeyse görev dönüşümlü olarak devredilir.

**Soru:** Özel bir küme başı yoksa ağın ömrünü uzatmak için ne yapılabilir? **Cevap:** Bir öğrenci düğümlerden birinin küme başı gibi davrandığını, o düşerse başka birinin devraldığını söyledi; bu durumda bütün bilginin her yerde bulunacağını düşündü. Hoca ilk kısmı doğruladı: Küme başı enerjisi azaldığında, fiziksel sorun yaşadığında ya da belirli periyotlarla görevini başka düğümlere devreder. Böylece ağdaki her düğüm belirli aralıklarla küme başı olur, her düğüm eşit enerji harcar ve ağ uzun süre bağlantısı kopmadan çalışır. İkinci kısma ise "hayır" dedi: Her düğümde her bilgi bulunmaz. Düğümler kendi ölçtükleri bilgiyi toplar; merkeze hangi bilginin gideceği kodlamada belirlenir; bilgi önce küme başına, oradan ara düğümler üzerinden merkeze aktarılır. Görevi devralan yeni küme başı, iletişim mesafesindeki komşularına yeni bilgi olup olmadığını sorar ve gelen bilgilerle devam eder.

Hoca sensör ağlarıyla IoT arasındaki bir farkı da burada belirtti: Sensör ağlarındaki düğümlerin belirli IP adresleri yoktur, tek tek erişilemez. IoT'de ise istenen düğüme nokta atışı bağlanılabilir. Sensör ağları ağırlıklı olarak dış ortama yerleştirilir; iç ortamdakiler büyük ölçüde IoT ağlarına dönüşmüştür, ama askerî ve tarım uygulamalarında sensör ağları hâlâ kullanılır.

### 6.2 Yinelenen Verinin Yararı

Komşu düğümler aynı bilgiyi ürettiği için sensör ağlarında yinelenen bilgi oluşur. Hoca orman yangınlarını izleyen bir ağ örneği verdi: Herkes 22 derece, 22 derece, 22 derece ölçüyor. Bu yineleme şurada işe yarar: 22, 22 ölçen sensörler arasında 78 derece gösteren bir sensör varsa bu aykırı değer (outlier) olarak tespit edilir ve o sensörün bozuk olduğu anlaşılır; artık ondan gelen veri dikkate alınmaz. Bölgede tek bir sensör olsaydı, bozulduğunda o bölgeden hiç veri alınamazdı. Bu yüzden sensör ağlarında yinelenen yapı bilinçli olarak kullanılır. Ancak günümüzde her nesne akıllı hâle gelip çok fazla veri topladığı için yinelenen bilginin kullanılması sorun olmaya başladı.

## 7. Büyük Veri: 4V Kuralı

Çok fazla veri üretilmesi bizi büyük veriye götürür.

**Soru:** Bir veriye hangi özelliklere göre büyük veri diyoruz? 1 TB veri büyük müdür? **Cevap:** Bir öğrenci toplam miktardan çok saniyede üretilen veri miktarının önemli olabileceğini söyledi. Hoca 3V/4V kuralını açıkladı:

- Hacim (volume).
- Hız (velocity): verinin ne kadar hızlı üretildiği ve değiştiği.
- Çeşitlilik (variety): Tek tip veri çok sorun değildir. Örneğin 3 TB sıcaklık verisi normalde büyük veri problemi sayılmaz; çok sık üretilen, çok sık değişen bir veri de değildir.
- Doğruluk (veracity).

Piyasada büyük veri denince herkes hacme bakar, ama bir verinin büyük veri olup olmadığı bu dört özellikle tanımlanır. IoT ve sensör ağlarında veriler bir merkezde toplandığında genellikle büyük veriden söz edilir, çünkü kameradan, mikrofondan, jiroskoptan gelen farklı türde veriler bir araya gelir. Hoca büyük veriye ilerleyen haftalarda ayrıca değinileceğini söyledi.

## 8. IoT'de Doğrudan Erişim, Güvenlik ve Ara Katman

**Soru:** IoT'de uç cihaza doğrudan erişmenin getirdiği sorun nedir? **Cevap:** Öğrencilerden güvenlik açığı ve adresleme cevapları geldi. Bir öğrenci, sensör ağında düğümler bir bölgeyi temsil ettiği için hangisinden veri geldiğinin önemli olmadığını, ama IoT'de her cihaza ayrı adres gerektiğini söyledi. Hoca bunu bir ev örneğiyle doğruladı: Odadaki birçok sensör sıcaklık üretiyorsa hangisinin ürettiğinin önemi yoktur, sıcaklık bilgisini tekrar tekrar göndermeye gerek yoktur. IoT cihazlarının her birine fiziksel IP vermek büyük bir sorundur, ama asıl sorun güvenliktir: Doğrudan erişim ciddi bir güvenlik açığı yaratır.

**Soru:** Doğrudan erişimi engellemek için üretilen çözüm nedir? **Cevap:** Bir öğrenci, güvenlik duvarındaki gibi birden fazla düğümü tek bir yere bağlayıp istekleri oradan aktarmayı önerdi; adı soruldu ve ara katman (middleware) cevabı geldi. Hoca, ara katmanların IoT ağlarında çok sık karşılaşılan çözümler olduğunu söyledi. Ara katman, tek tek cihazlardan ayrı ayrı veri sorgulamayı önler: Cihazlar ara katmana periyodik olarak bildirim yapar, uygulamalar da ara katmanı sorgulayarak istedikleri bilgiyi alır.

Slayttaki tanıma göre ara katman, ağ üzerindeki işletim sistemi ile uygulama arasında duran ve heterojenlik, birlikte çalışabilirlik (interoperability), güvenlik ve güvenilirlik (dependability) gibi sık karşılaşılan sorunlara bilinen, yeniden kullanılabilir çözümler sunan bir yazılım katmanıdır. Slayttaki şemada birden fazla yazılım (Software) tek bir ara katmana (Middleware) bağlı, ara katman da nesneye (Thing) bağlıdır (ekrandan, 00:45:00).

Aradan sonra hoca bu yapıyı açtı: Nesne bütün bilgilendirmeyi ara katmana yapar; ara katman topladığı bilgiyi düzenler ve farklı cihazlardan gelen bilgiler için bir tür dağıtım merkezi gibi çalışır. Böylece hem gerekli güvenlik önlemleri alınır hem de her cihaza kendine özgü bir protokolle erişmek yerine daha güvenli ve daha rahat erişilebilir bir yapı kurulur.

### 8.1 IoT İçin Ara Katman Çözümleri

Slayta göre IoT ara katman çözümlerinin sahip olması gereken özellikler (ekrandan, 01:05:00):

- Cihaz yönetimi (device management).
- Birlikte çalışabilirlik (interoperability).
- Platform taşınabilirliği (platform portability).
- Bağlam farkındalığı (context-awareness).
- Güvenlik ve mahremiyet (security and privacy).

Aynı slayttaki örnek IoT ara katman şeması, ağ geçidi (gateway), etiket (TAG), anten ve okuyucu (reader) üzerinden gelen verilerin bir makineler arası (M2M, machine-to-machine) ara katman platformunda işlendiğini gösteriyordu. Platformdaki modüller şunlardı: ID Management, Config Management, Service Application, Device Status Management, Device Authentication, Device Interface, Application Service Interface, Security Management, Remote Device Management, M2M Protocol I/F ve Logging. Bunların yanında Memory Grid, Event Processing ve bir servis veri yolu katmanı, sağ tarafta da veritabanı ile ERP, CRM, WMS, MES, Portal, Notification ve diğer uygulamalar yer alıyordu (ekrandan, 01:05:00). Hoca, farklı noktalardan toplanan bilgiler için kimlik yönetimi, yapılandırma yönetimi, cihaz durumu yönetimi ve cihaz doğrulama gibi birçok yapının yönetilmesi gerektiğini vurguladı.

## 9. IoT Verisinin Yönetimi: Alanlar, Protokoller, Saklama

### 9.1 Her Mesajda Saklanması Gereken Bilgiler

**Soru:** Bir IoT cihazından veri alırken mutlaka saklanması gereken bilgiler nelerdir? **Cevap:** Derste adım adım toplanan cevaplar:

- Zaman (zaman damgası, timestamp): Hoca "tartışmasız zaman" dedi.
- Verinin kendisi.
- Verinin türü, yani hangi sensörden geldiği: Bir öğrenci bunun cihazdan zaten bilindiğini söyledi; hoca bir IoT cihazında tek bir sensör olmak zorunda olmadığını, birden fazla sensör verisi toplanabileceğini, bu yüzden sensör bilgisinin de aktarılması gerektiğini belirtti.
- Konum bilgisi: IP ya da cihaz kimliği saklanabilir, ama bunların konumla eşleştirilmesi gerekir. Aynı konumdan gelen veriler incelenerek aykırı değer tespiti (outlier detection) yapılabilir ya da aynı konumdan gelen fazla veri bir filtreden geçirilerek saklanmayabilir.

Bir öğrenci pille çalışan cihazlarda kesinti zamanını öngörmek için batarya bilgisinin belirli sıklıkla alınabileceğini ekledi; hoca bunun cihaza özgü bilgi olarak alınabileceğini söyledi. Ayrıca sensörün veri toplama frekansının bilinmesi önemlidir.

Hoca bu bilgileri üç gruba ayırdı: bazıları her mesajda aktarılmalı, bazıları belirli aralıklarla güncellenmeli, bazıları hiç değişmez.

> **Hocanın vurgusu:** IoT cihazlarından veri toplarken değişmeyen bilgiler tekrar tekrar alınmamalı, belli periyotlarla değişebilecek bilgiler sorgulanmalı; zaman damgası, verinin kendisi ve verinin hangi sensöre ait olduğu ise her turda mutlaka aktarılmalıdır.

### 9.2 Mesajlaşma Protokolleri

**Soru:** IoT tarafında mesajlaşma protokolü olarak ne kullanılıyor? **Cevap:** Bir öğrenci MQTT'yi söyledi. TCP/IP üzerinde soket kullanılabileceği de söylendi; hoca bunun maliyetli olduğu için pek tercih edilmediğini, IoT cihazlarının kapasitesi bilgisayarlara göre düşük olduğu için daha hafif bir mesajlaşma protokolü arandığını söyledi. Bir öğrenci UDP'yi önerdi ve HTTP olmadığını belirtti. Hoca CoAP'ı ekledi: CoAP, MQTT'nin rakibidir ve ikisi arasındaki rekabet TCP ile UDP arasındaki rekabete benzer. Hoca ders sırasında CoAP'ın abone olma (subscribe) mantığıyla çalıştığını, kayıt olunduğunda belirli aralıklarla gereken bilgiyi aktardığını, MQTT'nin ise TCP mantığına daha yakın çalıştığını söyledi. Şu an MQTT yaygın olarak kullanılıyor, ama henüz oturmuş, rakipsiz bir çözüm yok ve araştırmalar sürüyor.

> **Ders sonrası not:** Hoca CoAP'ın abone olma mantığıyla, MQTT'nin TCP mantığıyla çalıştığını söyledi. Büyük olasılıkla doğrusu şudur: MQTT, TCP üzerinde çalışan ve bir aracı (broker) üzerinden yayınla-abone ol (publish/subscribe) modeli kullanan bir protokoldür; CoAP ise UDP üzerinde çalışan, HTTP'ye benzer istek-yanıt (request/response) modeli kullanan bir protokoldür ve gözlem (observe) eklentisiyle abonelik benzeri bildirim de sunar. TCP-UDP benzetmesi bu açıdan uygundur.

### 9.3 Güvenlik, Mahremiyet ve Saklama

Güvenlik ve mahremiyet IoT için çok önemlidir. Toplanan veriler yalnız korunmamalı, aynı zamanda karartılmalıdır (anonimleştirilmelidir): Bir evin içinden sürekli veri toplanıyorsa verinin hangi eve ait olduğu bilinmemelidir.

**Soru:** IoT'den toplanan veriler nerede ve nasıl bir yapıda saklanır? **Cevap:** Bir öğrenci veritabanı dedi; ilişkisel olmayan, MongoDB gibi NoSQL bir veritabanı olacağını söyledi. Hoca doğruladı. NoSQL çıktığında ilişkisel veritabanları gücünü kaybedecekmiş gibi görünmüştü; ama ilişkisel veritabanları, ilişkilerin ve bağlantıların önemli olduğu veri modellerinde hâlâ çok kullanılıyor. IoT cihazlarının ürettiği veri ise daha çok nesne bazında üretilir ve bütün olarak saklanmak istenir; bu yüzden NoSQL daha verimli bir saklama biçimi sunar. Büyük veri tarafında Hadoop mimarisi gibi çözümler de ileride görülecek.

## 10. İnternetin Evrimi ve IoT Ekosisteminin Sorunları

### 10.1 İnternetin Evrimi

Slayttaki "Evolution of Internet" şeması beş aşama gösteriyordu: Ağ (iki host), İnternet (web ile bağlı hostlar), Mobil İnternet (mobil cihazlar ve hostlar), Mobil + İnsan + PC ve Nesnelerin İnterneti (birbirine bağlı nesneler: ev, buzdolabı, araba, kahve makinesi vb.) (ekrandan, 01:15:00). Slaytın konuşmacı notunda tarihçe şöyle veriliyordu: 1960'ların sonunda iki bilgisayar arasında ağ ile iletişim mümkün oldu; 1980'lerin başında TCP/IP yığını tanıtıldı, 1980'lerin sonunda internetin ticari kullanımı başladı; 1991'de World Wide Web hızlı büyümeyi başlattı; "Internet of Things" terimi ilk kez 1998'de Kevin Ashton tarafından bir sunumda kullanıldı; IoT 2005'te Uluslararası Telekomünikasyon Birliği'nin (ITU) internet raporuyla resmî olarak tanıtıldı (ekrandan, 01:15:00).

Hoca bu evrimi şöyle anlattı: Önce iki bilgisayar haberleşiyordu, sonra internetle tüm dünyadaki bilgisayarlar birbirine bağlandı, sonra mobil cihazlar ve kablosuz iletişim girdi ve insanlar cihazlarla birlikte devreye girdi. Şimdi cihazlar kendi başlarına devreye giriyor: Nesnelerin birbiriyle otomatik olarak haberleştiği bir dünyaya gidiyoruz. Örnekler: Araba eve belli bir süre kala bunu eve bildirir ve kombi çalışmaya başlar; buzdolabında arıza olduğunda buzdolabı kendiliğinden arıza kaydı açar, kullanıcıya uygun saatleri sorar ve randevu talep eder.

### 10.2 Ekosistemin Sorunları

**Soru:** IoT ekosisteminde çözülmesi gereken sorunlar nelerdir? **Cevap:** Bir öğrenci en büyük engelin IPv4 olduğunu, IPv6'nın henüz yaygınlaşmadığını söyledi. Fiziksel IP vermeden çözülüp çözülemeyeceği sorulunca NAT ile bir yere kadar çözülebildiğini, servis sağlayıcıların artık NAT arkasına bir NAT daha koyduğunu, bunun da gecikme ve güvenlik açısından sorunlar getirdiğini, en gerçekçi çözümün IPv6 olduğunu ekledi. Hoca doğruladı: Ağ adresi dönüştürme (Network Address Translation) ile bir ağ geçidinin arkasındaki cihazlar farklı bir adresleme mantığıyla çalıştırılıyor; IPv4 kapasitesini çoktan doldurdu ve bu bir ara çözüm. IoT'nin en çok ihtiyaç duyduğu şeylerden biri geniş bir adres alanıdır.

Hocanın eklediği ikinci sorun mesajlaşma biçimleridir: Cihazlar veri aktarırken mümkün olan en az veriyi aktarmalı, bunun için bir düzen tutulmalıdır.

**Soru:** İnternet üzerinde bilgiyi taşırken hangi paket biçimleri kullanılır? **Cevap:** TCP/IP ve HTTP üzerinden; biçim olarak XML (Extensible Markup Language) ve JSON. Hoca, JSON'ın makineler arası haberleşmede en çok başvurulan çözümlerden biri olduğunu, ama ileride JSON'a alternatif bir çözüm çıkacağını ve bunun önemli bir araştırma konusu olduğunu söyledi.

> **Ders sonrası not:** Hoca JSON'ı "XML'den biraz daha kuvvetli bir yapı" diye niteledi. Büyük olasılıkla burada kastedilen, JSON'ın XML'e göre daha hafif ve daha az ek yük getiren bir biçim olmasıdır; ifade gücü açısından XML (şema, ad alanı, öznitelik desteğiyle) daha zengindir.

Üçüncü sorun standartlaşmadır. Hoca akaryakıt istasyonlarında araçtan inmeden temassız ödeme örneğini verdi: Bankalar ve istasyonlar anlaşıp kendi yapılarını kurdu; araç pompaya yaklaştığında araçla otomatik bir iletişim başlar, onay sorulur ve ödeme yapılır. Ama her banka ve her operatör kendi yapısını kurarsa uyumluluk sorunu çıkar. İstenen şey standartlaşma, yani ortak protokollerdir; bu da IoT'nin en çok ihtiyaç duyduğu noktalardan biridir.

## 11. Sensör Ağı ile IoT Arasındaki Farklar

**Soru:** Sensör ağı ile IoT'de verinin akış yönü arasında bir fark var mıdır? **Cevap:** Bir öğrenci, sensör ağlarında iletişimin bir yayın biçiminde olduğunu ve onay (acknowledgment) dönme ihtiyacı olmadığını, IoT'de ise bir işlemin yapıldığını teyit eden bir bilginin dönmesi gerektiğini söyledi. Hoca doğruladı: IoT ağırlıklı olarak çift yönlü bilgi taşır; sensör ağında bilgi sunucuya, merkeze doğru akar. Sensör ağında sürekli bir karşılıklı mesajlaşma yoktur; en kötü ihtimalle bir kez istek gönderilir ve tüm ağ bilgisini aktarır. IoT'de ise karşılıklı bir konuşma yapısı oluşur.

Hocanın verdiği ikinci fark: Sensör ağları uygulama odaklıdır (application-oriented), uygulamaya özgü çözümler üretir. IoT ise insan odaklıdır (human-oriented), insana özgü çözümler üretir. Sensör ağı da sonuçta insana hizmet eder, ama bir tarlanın sulanması ya da bir askerî kampın çevresinde tehlike olup olmadığının izlenmesi gibi belirli bir uygulama için kurulur. İnsan odaklı IoT ise evin konfor düzeyi gibi insan hayatını doğrudan etkileyen günlük çözümler üzerine kurulur. Toplantı salonunda ışık açık unutulduğunda içeride hareket olmadığının anlaşılıp ışığın kapatılması bu tür bir örnektir. Buradan bağlam farkındalığına gelinir: Kurulan düzen, çevredeki gelişmeleri ve insanın hareketlerini anlayabilmelidir.

**Soru:** Bağlam farkındalığı kapsamında, IoT cihazlarının ya da çevresel zekânın kullanıldığı günlük hayattan örnekler nelerdir? **Cevap:** Öğrencilerden gelen örnekler: kombideki sıcaklık sensörleri, uzaktan yönetilen ışık ve akıllı prizler (ticari olarak satılıyor), şehirde ve çatıda nem ve hava durumu bilgisi toplayan istasyonlar, akıllı binalar ve araçlardaki motor kontrol üniteleri (hava sıcaklığı, yakıt püskürtme miktarı, gaza basma miktarı, karbondioksit salımı gibi verilerle verim kontrolü). Bir öğrenci elektrikli araçların tamamen sensörle donatıldığını, yakınlık (proximity) sensörleri, hava durumu ve kamera verisi toplayabildiğini, eski araçlardaki gömülü sistemlerin ise IoT gibi çalışmayabildiğini ekledi.

## 12. Bağlam Farkındalığı Uygulaması: Sürüş Analizi ve Yorgunluk

### 12.1 Sigorta ve Sürüş Verisi

Hoca bu dönemde yaygınlaşan bir uygulamayı sordu: Araç sigortası yaptırırken cep telefonu üzerinden bilgi paylaşımına izin vererek sigortayı daha uygun hâle getirmek.

**Soru:** Bu nasıl oluyor? **Cevap:** Sürücü sürüş verilerini paylaşmayı kabul eder; veriler incelenir ve bir sonraki yıl poliçe yenilenirken yalnız hasarsızlık indirimi değil, sürücünün kullanımından kaza yapma ihtimali ve ne kadar agresif kullandığı da hesaba katılarak avantajlı teklifler sunulur. Hoca bunun son 3-4 yıldır kullanılan yeni bir yaklaşım olduğunu söyledi. Ancak veriyi telefondan toplamak sağlıklı değildir, çünkü hataya açıktır: Telefonun eldeki sallanma miktarını aracın sallanma miktarından ayırmak ve gürültüyü çıkarmak gerekir. İleride bu veriler araç üzerindeki sensörlerden alınacak.

**Soru:** Aracın kendi verilerini almak için kullanılan iletişim kanalı nedir? **Cevap:** CAN veri yolu (altyazıda "Canvas" diye geçiyor). Bu kanal üzerinden aracın devri, frene ve gaza ne şiddetle basıldığı, yakıt tüketimi gibi onlarca veri alınabilir. Protokolün bir kısmı tüm araçlar için geçerli ve genel, bir kısmı ise üreticiye özeldir; IP paketlerindeki isteğe bağlı (optional) alanlar gibi bazı araçlar bu alanları kendi amaçlarıyla kullanır.

> **Ek bilgi (derste anlatılmadı):** CAN (Controller Area Network), araç içindeki elektronik kontrol ünitelerinin birbiriyle haberleşmesi için geliştirilmiş bir seri veri yoludur. Araçlardaki OBD-II teşhis bağlantı noktası üzerinden standart parametrelere erişilebilir; üreticiye özgü mesajlar ise genellikle belgelenmemiştir.

### 12.2 Sürüş Analizinin Diğer Kullanım Alanları

**Soru:** Sürüş analizi sigorta dışında nerelerde kullanılır? **Cevap:** Derste gelen cevaplar:

- Yakıt tasarrufu sağlayan sürüş profilleri önermek; sürücüye agresif ya da tehlikeli kullandığını göstererek farkındalık yaratmak.
- Bir belediye açısından yollardaki kasis ve çukurları sürüş verilerinden tespit etmek (araçlardaki yıpranmanın ekonomik bir gider olduğu da söylendi).
- Belediye çalışanlarının ve toplu taşıma şoförlerinin araçları nasıl kullandığını analiz etmek; bazı araçların kullanım biçimi yüzünden ciddi biçimde yıprandığı bilinir.

Hoca burada önemli bir araştırma problemine dikkat çekti: Sorunun yoldan mı sürücüden mi kaynaklandığını ayırt etmek. Akıllı şehircilik ve akıllı ulaşım kavramlarının önümüzdeki on yıla damgasını vuracağını, burada IoT nesnesinin araç olduğunu, ama otobüs ile otomobilin ayrı hesaplamalar gerektirdiğini söyledi.

### 12.3 Ulaşım Araçlarında Yorgunluk

Hoca derste anlattığı bir çalışmada sürüşlerin yorgunluğa etkisinin incelendiğini ve araçların yorgunluğa ne oranda etki ettiğinin matematiksel olarak ortaya konduğunu söyledi.

**Soru:** Bir saatlik uçak, tren ve otobüs yolculuğundan hangisinde daha az, hangisinde daha çok yorulursunuz? **Cevap:** Öğrencilerin çoğu en az yorucu olarak treni, ardından uçağı, en çok yorucu olarak karayolunu gösterdi; bir öğrenci arabanın en konforlu olacağını, uçaktaki basınç değişikliğinin yorucu olduğunu düşündü. Hoca, her seferinde bu soruyu sorduğunu ve uçak cevabını beklediğini söyledi: Çalışmanın sonuçlarına göre en az yorucu ulaşım aracı uçaktır.

**Soru:** Neden uçak? **Cevap:** Bir öğrenci uçağın dur-kalk yapmadığını söyledi; hoca doğruladı. Uçak yalnız kalkışta ve inişte ivmelenir. Hava kötü değilse ve türbülans yoksa, yükseldikten sonra uzun süre aynı hızda gider ve kabin basıncı da sabittir; telefondaki ivmeölçere bakıldığında doğrusal ivmenin sıfıra yakın olduğu görülür. Tren ile otobüs karşılaştırıldığında karayolu her zaman daha fazla titreşim, trafik nedeniyle daha fazla fren ve hızlanma demektir; sabit hızla gidilmez. Bu yüzden sıralama en konforludan en konforsuza uçak, tren, otobüs olur. Hoca bu değerlendirmenin yalnız araca uygulanan fiziksel kuvvete dayandığını, eski ray, eski tren, motor sesi, kabin uğultusu gibi şartların hesaba katılmadığını, objektif bir karşılaştırma yapıldığını vurguladı.

Çalışmada metro gibi araçların sürüş konforu da incelendi ve yorgunluk analizleri yapıldı. Hocanın aktardığı sonuçlar:

- Uçak yaklaşık 1'e 8 oranında daha konforlu bulundu.
- Raylı sistemlerin konfor düzeyi tekerlekli sistemlere göre oldukça yüksek çıktı.
- A noktasından B noktasına çizilen bir rotada araçların ürettiği kuvvet ve ivme bilgileri alınarak rotaların yorgunluk düzeyi hesaplanabileceği ve yeni bir haritalama yapılabileceği gösterildi.

Hoca bunu günlük bir örnekle bağladı: Navigasyon bazen ara sokaklardan geçirerek 3-5-7 dakika kazandırır, ama her köşe başında dur-kalk ve dönüş yapıldığı için her seferinde bir ivme uygulanır ve yolcu yorgun düşer. En avantajlı yol kuş uçuşu, aktarmasız düz bir çizgidir; bu mümkün olmadığından yollar analiz edilip dönüşü en az, çukuru en az, yol kalitesi en yüksek olanlar seçilmelidir. Böylece yorgunluk haritasına göre en az yorucu rota bulunabilir. Gelecekte bir noktadan diğerine giderken yalnız süreye değil, araçların yaratacağı yorgunluğa da bakılacak.

## 13. IoT Tanımları, Türleri ve Kategorileri

### 13.1 Tanımlar

Slayttaki ilk tanım şuydu: "Things have identities and virtual personalities operating in smart spaces using intelligent interfaces to connect and communicate within social, environment, and user contexts." (ekrandan, 01:35:00) Yani her cihazın bir kimliği ve sanal kişiliği vardır ve çevresiyle haberleşir.

Aynı slayttaki piramit, toplanan verinin aşamalarını gösteriyordu: Veri (Data, ham) → Bilgi (Information, anlam) → Bilgi birikimi (Knowledge, bağlam) → Bilgelik (Wisdom, uygulama) (ekrandan, 01:35:00). Hoca amacın toplanan veriyi bilgiye çevirmek olduğunu, bilgiye çevrildiğinde bağlamın anlaşıldığını söyledi: Örneğin o anda yağmur yağıyor, kişi araçta ve telefonla konuşuyor; bu bağlamları algılayabilen bir ortam tasarlanabilirse hayat çok kolaylaşır. Bilgelik en üst noktadır; oraya erişmek kolay değildir, ama hedeflerden biridir. Slayttaki ikinci şekil "Anything, Anyone, Anytime, Any place, Any service, Any network" ifadesini gösteriyordu: IoT, yerden bağımsız bilgiye erişim demektir.

İkinci tanım (ekrandan, 01:35:00): "The semantic origin of the expression is composed by two words and concepts: Internet and Thing, where Internet can be defined as the world-wide network of interconnected computer networks, based on a standard communication protocol, the Internet suite (TCP/IP), while Thing is an object not precisely identifiable. Therefore, semantically, Internet of Things means a world-wide network of interconnected objects uniquely addressable, based on standard communication protocols." Hoca buradaki en önemli noktanın nesnelerin tekil olarak adreslenebilir (uniquely addressable) ve birbirine bağlı olması olduğunu vurguladı. Üçüncü tanım slaytı IoT'nin yaygın mobil hesaplamayla ilgili özelliklerini gösteriyordu; hoca bunları daha önce konuştuklarını söyleyerek geçti.

### 13.2 IoT Türleri

Slayttaki "Types of Internet of Things" tablosu üç grubu gösteriyordu (ekrandan, 01:40:00):

| Bilgi Teknolojisi | Kişisel Teknoloji | Operasyonel Teknoloji |
|---|---|---|
| PC'ler | Tabletler | Endüstriyel kontrol sistemleri (ICS) |
| Sunucular | Akıllı telefonlar | Denetleyici kontrol ve veri toplama (SCADA) |
| Sanallaştırma | Akıllı saatler | Medikal makineler |
| Yönlendiriciler | Ev enerjisi | Kiosklar |
| Anahtarlar | Ev eğlencesi | Üretim |
| | Ev kontrolü | Bulut hizmet altyapısı |
| | Medikal implantlar | Çevre izleme |
| | Medikal giyilebilirler | |

Bilgi teknolojisi grubunda PC'lerden, sunuculardan, yönlendiricilerden ve anahtarlardan bilgi toplanabilir (bu kısım bölüm 14'te sanal sensörlerle ele alındı).

Kişisel teknoloji grubunda kişisel araçlar önemlidir: akıllı telefonlar, giyilebilir teknolojiler ve kişisel teknolojilerle donatılmış akıllı evler. Medikal implantlar tedavilerde, örneğin kanser tedavisinde kullanılıyor; kanser hücrelerini bulup yalnız onları öldüren akıllı ilaçlar başlı başına araştırma konularıdır. Bu nesnelerin hepsinin internet bağlantısı olmayabilir; kişisel alan ağı (personal area network) ya da vücut alan ağı (body area network) gibi yalnız insan üzerindeki sensörlerin birbiriyle haberleştiği ağlarda çalışabilirler. Hoca, son dönemde akıllı saatlere kandaki oksijen miktarını ölçen sensörler eklendiğini, bunların medikal cihaz kadar doğru ölçmese de kalp ritim düzensizliği gibi durumları gösterebildiğini söyledi. Önce üzerimizde taşıdığımız, sonra vücudumuza yerleştirilen sensörler yaygınlaşacak.

Hoca işitme ve görme kaybını gideren sensörlerin önemine bir kitaptan örnekle değindi: Bebeklik döneminde duyulan kelime ve ses sayısının beyin gelişimine etkisi büyüktür; o dönemde duyulmayan seslerin sonradan işitme kazanılsa bile hayata uyumu zorlaştırabileceği gösterilmiş. Bu yüzden duyu organlarının erken dönemde aktif çalışmasını sağlayan sensörler öğrenme kapasitesini artırabilir. Pandemi döneminde yaşlı hastalara kendi üzerlerinden veri toplayan cihazlar verildiği, doktorların hastayı görmeden tansiyon ilacı dozu gibi kararlar alabildiği de örnek olarak anıldı.

Operasyonel teknoloji Endüstri 4.0'ı anlatan kısımdır. Endüstri 4.0 için siber güvenlik, büyük veri, IoT, yapay zekâ ve coğrafi bilgi sistemleri gibi uzmanlık alanları gerekir. Fabrikalar seri üretimi çok iyi yapar, ama bir hata durumunda proaktif çözüm üretmekte zorlanır. Örneğin hata verilerini inceleyerek bir makinenin bozulma zamanını tahmin etmek ve parça bozulmadan önlem almak, birimin bir gün kapalı kalmasının zararından çok daha değerlidir. Bunun yolu sensör verilerini incelemektir: Daha önce bozulmuş bir makinenin verileriyle aynı örüntüyü gösteren bir makine de büyük olasılıkla bozulma sürecindedir. Endüstri 4.0'da hedef kendi kendine karar veren ve kendi hatasını ayıklayan otonom sistemlerdir. Hoca ayrıca verimliliği artıracak ve kullanıcı memnuniyetini yükseltecek çözümlere hâlâ büyük ihtiyaç olduğunu, bir lojistik firmasının dağıtım planlamasını hâlâ elle tablo programında yaptığını örnek verdi.

### 13.3 IoT Uygulama Kategorileri

Slayttaki Venture Scanner grafiği en çok yenilik görülen IoT kategorilerini, her kategorideki şirket sayısıyla gösteriyordu (ekrandan, 02:05:00):

| Kategori | Şirket sayısı |
|---|---|
| IoT Home | 138 |
| IoT Health Care | 101 |
| IoT Fitness | 96 |
| IoT Lifestyle and Entertainment | 90 |
| IoT Platform and Components | 88 |
| IoT City and Infrastructure | 42 |
| IoT Automotive | 41 |
| IoT User Interface | 39 |
| IoT Agriculture | 33 |
| IoT Smart Watches | 27 |
| IoT Retail | 24 |
| IoT Tags and Trackers | 24 |
| IoT Toys | 23 |
| IoT Smart Jewelry | 16 |
| IoT Enterprise | 14 |

Hoca bu verilerin birkaç yıl öncesine ait olduğunu ve sıralamanın değiştiğini, önemli olanın kategorileri ve ihtiyaçlarını analiz etmek olduğunu söyledi. Özellikle otonom araçlar, akıllı şehirler, sağlık ve akıllı binalar geleceği olan alt alanlardır. Slaytın konuşmacı notunda 2020'ye kadar internete 50-100 milyar cihazın bağlanacağı ve akıllı şehir, akıllı çevre, akıllı su, akıllı ölçüm, güvenlik ve acil durumlar, perakende, lojistik, endüstriyel kontrol, akıllı tarım, akıllı hayvancılık, ev otomasyonu ve e-sağlık gibi uygulama alanları yazıyordu (ekrandan, 01:40:00).

## 14. Sanal Sensörler

**Soru:** PC'lerden, sunuculardan ne tür bilgiler toplanabilir? **Cevap:** Bir öğrenci ağ tarafında IP üzerinden yapılan iletişimden ve standart IP servislerinden bilgi toplanabileceğini söyledi. Hoca güvenlikle ilgili bir örnek verdi: IP paketleri birer bilgi kaynağıdır; paketler ve ağ akışı (network flow) incelenerek bir saldırı olup olmadığı anlaşılabilir. PC, yönlendirici ve anahtarlardaki kayıtlara (log) bakarak hareketler incelenebilir, saldırılarla ilgili bilgi edinilebilir ya da çökmeye yol açan sorunun ne olduğu tespit edilebilir.

Hoca bunu neden anlattığını açıkladı: Şimdiye kadar hep jiroskop, ivmeölçer, mikrofon gibi fiziksel sensörlere odaklanıldı. Ama yalnız fiziksel sensörler yoktur.

**Soru:** Fiziksel sensörler dışında hangi sensörler vardır? **Cevap:** Bir öğrenci fan sesinden bilgi sızdırma gibi yan kanal örneklerini hatırlattı; hoca bunların da fiziksel sensörlere dayandığını söyledi. Fiziksel sensörlerin dışında:

- IP paketleri: Wi-Fi modülü üzerinden telefona gelen tüm paketler bir sensör üretiyormuş gibi alınıp incelenebilir ve çıkarım yapılabilir.
- Sanal sensörler (virtual sensors): Örneğin takvim. Takvimde bir toplantı varsa telefon toplantı saatinde otomatik olarak sessize alınabilir.
- Mesajlar: Mesaj içeriği analiz edilerek gereksiz (spam) mesajlar ayıklanabilir, mesaj kutusu düzenlenebilir; kampanya ve puan mesajları tarihlerine göre düzenlenip kullanılacak puan için hatırlatma kurulabilir. Başka bir örnek: Cevapsız arama bildirimi mesajındaki numara rehberdeki kayıtla eşleştirilip mesaja doğrudan arayan kişinin adı yazdırılabilir.

> **Hocanın vurgusu:** Çevrede bilgi üreten her türlü uygulama ya da fiziksel birim bir sensör olarak görülmelidir. Yalnız fiziksel ya da kimyasal sensörler değil, bilgi sağlayabilecek her kaynak bağlam farkındalığı ekosisteminin bir parçasıdır. Bu kaynakların çoğunun ek maliyeti yoktur ve sürekli veri üretmedikleri için sürekli işlenmeleri de gerekmez.

## 15. Sensör Ağlarına Dönüş, Eyleyiciler ve IoT'nin Temel Özellikleri

### 15.1 Sensör Ağlarında Veri Akışı

Slayttaki "Sensor Networks" şeması verinin katmanlar boyunca tek yönlü akışını gösteriyordu: Katman 1 düşük uçlu sensör düğümleri, Katman 2 yüksek uçlu sensör düğümleri, Katman 3 alıcı düğümler (sink; statik ya da mobil), Katman 4 düşük uçlu hesaplama cihazları, Katman 5 yüksek uçlu hesaplama cihazları, Katman 6 bulut (internet) (ekrandan, 02:05:00). Hoca, bilginin sensör düğümlerinden baz istasyonuna, yani alıcıya (sink) geldiğini, alıcıların bir kısmının statik bir kısmının mobil olabileceğini söyledi. Aradaki bazı katmanlar olmayabilir; veri alıcıdan doğrudan buluta da aktarılabilir. Bu, verinin nerede ve nasıl toplandığına bağlıdır.

Hoca zoolojiden bir örnek verdi: Göç eden balinalar gibi hayvanların üzerine sensörler yerleştirilip yıl boyunca hareketleri incelenerek hayvanların mevsimleri nasıl geçirdiği anlaşılıyor. Bazı durumlarda veri uzun süre sensörün kendi üzerinde depolanır ve hayvan habitatına döndüğünde topluca alınır; bazı durumlarda küçük bir SIM kart üzerinden aktarılır. Kullanılacak donanım ve yazılım, ne yapılacağına göre seçilmelidir.

### 15.2 Eyleyiciler

Sensör ağları IoT'nin biraz altında yer alır. Sistemde sensörler ve eyleyiciler (actuator) vardır. Eyleyiciler, sensörlerden toplanan bilgiyle karar verildikten sonra gereken hamleyi yapan hareket birimleridir (bir yere gitmek, sağa ya da sola dönmek gibi).

Bir cihaza IoT cihazı diyebilmek için mutlaka bir eylem (actuation) yapması gerekir; yalnız veri toplaması yeterli değildir, veriden çıkardığı kararı uygulayabilmelidir. Örneğin akıllı ev yalnız sıcaklık bilgisini toplayıp paylaşmaz: Kombiyi otomatik çalıştırır, alışkanlıkları öğrenir (her pazartesi saat 19.00'da eve geliniyorsa kombiyi 18.30'da çalıştırır), dış hava sıcaklığına ve evin sıcaklığına bakarak karar verir. Eylem yoksa daha çok sensör ağından söz ediliyor demektir: Veri algılanır, toplanır ve bir yerde işlenir.

### 15.3 IoT'nin Temel Özellikleri

Slayttaki "Major Characteristics for IoT" listesi (ekrandan, 02:10:00):

- Zekâ (intelligence): sensör verilerinin birleştirilmesi (fuse sensor data).
- Mimari (architecture): olay güdümlü (event-driven) ve zaman güdümlü (time-driven) veri toplama.
- Karmaşık sistem (complex system): sensörler ve eyleyiciler.
- Boyut (size considerations): 50-100 milyar cihaz.
- Zaman (time considerations): gerçek zamanlı veri işleme.
- Mekân (space considerations): konum bağlam farkında hesaplamada önemli rol oynar.
- Her şey hizmet olarak (everything-as-a-service): paylaşım temel olacak.

**Soru:** Olay güdümlü ve zaman güdümlü veri toplama nedir? **Cevap:** Bir öğrenci, olay güdümlünün bir olay olduğunda (ör. sıcaklık 50 dereceyi geçtiğinde) veri göndermek, zaman güdümlünün belirli periyotlarla veri almak olduğunu söyledi. Hoca üçüncü bir biçim sordu; bir öğrenci "istek ile" dedi. Hoca bunun sorgu tabanlı (query-based) toplama olduğunu doğruladı. Örneğin yangın olduğu düşünülen bir noktada oradaki kamerayı açıp görüntü akışı istemek sorgu tabanlıdır. İnsanların bugün elle yaptığı bu işler otomatikleştirilmeli: Görüntüyü işleyip ya da işlemeden kullanıcının telefonuna ya da e-postasına göndermek, yangın hattını aramak, düşme tespitinde (fall detection) sağlık birimlerini ya da yakınları aramak gibi.

Ölçeklenebilirlik gereklidir, çünkü yakın gelecekte 50-100 milyarlık bir cihaz topluluğundan söz edilecek. Birçok IoT cihazında anlık karar vermek gerektiğinden veriyi bekletip analiz etme şansı olmayabilir; yapı kurulurken gerçek zamanlı ihtiyaç olup olmadığına bakılmalıdır. Bağlam farkında hesaplama yapılıyorsa konum bilgisi mutlaka gerekir.

Bütün bu kavramlar birleşince "her şey hizmet olarak" yapısı ortaya çıkar: altyapı hizmet olarak (Infrastructure as a Service), yazılım hizmet olarak (Software as a Service). Fiziksel sunucu almak yerine sunucu kiralanır; yazılım bilgisayara kurulmak yerine buluttan kullanıldığı kadar ödenerek alınır; kullanıcı sayısı arttıkça yeni sunucular kiralanır. Bunu mümkün kılan sanallaştırmadır: Tek bir fiziksel cihazda birden fazla sanal işletim sistemi çalıştırılarak eskiden 3-4 cihazın yaptığı iş, işlemci boşta kalmadan organize edilebilir. Hoca, işi donanımla yapmanın her zaman daha verimli olduğunu, ama sanallaştırma yazılımlarının bu anlamda çok ilerlediğini ve konunun araştırmaya değer olduğunu söyledi.

## 16. IoT Cihazlarında İşletim Sistemi

**Soru:** IoT cihazlarında bir işletim sistemi var mı? **Cevap:** Bir öğrenci işletim sistemi çalıştırmanın maliyetli olacağını söyledi; başka bir öğrenci telefon ve tablet gibi cihazlarda olduğunu, ama sensör ağlarındaki küçük sensörlerde olmayacağını düşündü. Hoca, sensör düğümleri için bile zamanında Contiki ve TinyOS gibi işletim sistemleri tasarlandığını, ama işletim sisteminin bir maliyeti olduğunu söyledi: Birçok servisi yönetmesi gerekir; bu da cihazın enerji tüketmesi ve kaynaklarını bu işe ayırması demektir.

**Soru:** Bundan sonraki adım ne olacak, IoT cihazlarına özelleşmiş bir işletim sistemiyle karşılaşacak mıyız? **Cevap:** Öğrencilerden gelen görüşler:

- İlk işletim sistemine bir bilgisayarda birden fazla iş yapmak istendiği için ihtiyaç duyuldu; bir IoT cihazında da birden fazla özellik çalıştırılmak istenirse işletim sistemi kaçınılmaz olur.
- Bir bölgede birden fazla cihaz yerine, sanallaştırmadaki gibi tek cihazı güçlendirip bütün işleri onun üzerinden yapmak istenebilir; bu da özel bir işletim sistemi ihtiyacı doğurur.
- Enerji ya da donanım çok kısıtlıysa işletim sistemi olmadan tek iş yapan cihazlar kalacak; ama işlemciler hızlandıkça çoğu ürün birden fazla iş yapabilecek ve işletim sistemi kullanacak.
- Sensörler tek başına veri toplar; IoT'nin özü sensörleri birlikte kullanıp yorumlamak olduğundan birden fazla işi yönetmek için daha hafif işletim sistemlerine ihtiyaç artacak.
- Bir öğrenci ise IoT cihazında işletim sistemi kullanılmaması gerektiğini savundu.

Hoca ev aletleri örneğini tartışmaya açtı: Çamaşır makinesi, bulaşık makinesi ve buzdolabı ortam sıcaklığı ve nemi gibi ortak bilgileri toplayabiliyorsa, sensör ağlarındaki gibi görevleri birbirine devredip koordineli çalışabilirler mi? Hoca ayrıca IoT cihazlarının çoğunun sensör ağlarındaki gibi enerji kısıtı olmadığını belirtti (çamaşır makinesi, araba; ama akıllı bir sandalyenin olabilir). Bir öğrenci elektrikli araçlarda pil kısıtı bulunduğunu hatırlattı; hoca akünün uzun süre desteklediğini, bu yüzden pratikte önemsenmeyeceğini söyledi.

Hocanın vardığı sonuç: Bu hâlâ ucu açık bir sorudur. IoT cihazlarının gerçekten birden fazla iş yapması gerekirse, sıfırdan işletim sistemi yazmak yerine Android gibi mevcut işletim sistemlerinin özellikleri seyreltilerek cihazlarda çalıştırılması düşünülebilir; bu yönde çalışmalar zaten var. Ama hoca IoT cihazlarının şimdilik belirli işlerden sorumlu kalacağını düşünüyor: Bulaşık makinesinin görevi bulaşık yıkamaktır; buzdolabı en fazla son kullanma tarihini ya da azalan ürünleri bildirebilir. Araba ise farklıdır: Otonom araçlardan beklentiler çok farklı olduğu için yapısı bilgisayara yaklaşacaktır. Hocanın anlattığı bir derleme çalışmasına göre otonom aracın merkezinde bir araç zekâsı çekirdeği (vehicle intelligence core) olacak, çevresinde kullanıcı konforunu sağlayan ve aracın dış dünyayla haberleşmesini sağlayan servisler yer alacak. Bu yüzden işletim sistemi konusu en çok araçlarda gündeme gelecektir.

> **Ek bilgi (derste anlatılmadı):** Contiki ve TinyOS, kaynakları çok kısıtlı kablosuz sensör düğümleri için geliştirilmiş, olay güdümlü ve küçük bellekli işletim sistemleridir. Daha güçlü IoT cihazlarında ise genellikle gömülü Linux türevleri ya da gerçek zamanlı işletim sistemleri kullanılır.

## 17. Bağlam (Context) ve Bağlam Farkındalığı

### 17.1 Bağlamın Tanımı

Slayttaki tanım (ekrandan, 02:25:00): "Context is any information that can be used to characterise the situation of an entity. An entity is a person, place, or object that is considered relevant to the interaction between a user and an application, including the user and applications themselves." Yani bağlam, bir varlığın (insan, yer ya da nesne) durumunu tanımlamakta kullanılabilecek her bilgidir. Bir sonraki slaytta bağlamın eş anlamlıları sıralanıyordu: circumstance, situation, phase, position, posture, attitude, place, point, terms, regime, footing, standing, status, occasion, surroundings, environment, location, dependence; şekilde de "who, what, when, where, how" soruları yer alıyordu (ekrandan, 02:25:00).

**Soru:** Şu anda sizin bağlamınız nedir? **Cevap:** Derste sayılanlar: bulunulan şehir, evde olunması, bulunulan ülke, öğrenci kimliği, ders dinleniyor olması (ve aynı anda başka işlerle uğraşılması). Hoca için: ders anlatıyor, masa başında oturuyor, bir odada. Sınıfta olunsaydı sınıfta olunduğu ve sınıfta belirli sayıda insan bulunduğu anlaşılmalıydı. Bağlam kişiyle ilgili olmak zorunda değildir: Güneşin olması ve havanın açık olması da bir bağlamdır (dışarı çıkarken şemsiyeye gerek yok); yağmurun yağması ya da kapının açılıp kapanması da.

### 17.2 Kesikli ve Sürekli Olaylar

Hoca iki tür bağlamdan söz etti (slaytta "Events: Discrete Events, Continuous Events", ekrandan, 02:30:00):

- Kesikli (discrete) olaylar: anlık gerçekleşir; kapının açılması, kapının kapanması, arabaya binme ya da direksiyonun başına oturma anı.
- Sürekli (continuous) olaylar: devam eden süreçlerdir; yağmurun yağmaya devam etmesi, havanın güneşli kalması, araba yolculuğu.

Sürekli durumlarda bağlamın devam ettiği güncel olarak denetlenmelidir; kesikli durumlarda ise anlık gelişme tespit edilip bildirim yapılmalıdır (ör. aracın kapısının açılması ya da evin kapısının kapanması).

### 17.3 Ham Veri ve Bağlam Bilgisi

Slayttaki tanımlar (ekrandan, 02:30:00):

- Ham (sensör) verisi: işlenmemiştir ve sensörler gibi veri kaynağından doğrudan alınır.
- Bağlam bilgisi: ham sensör verisinin işlenmesiyle üretilir; ayrıca tutarlılığı denetlenir ve üst veri (meta data) eklenir.

Slayttaki şekilde veri → içerik → bilgi birikimi → anlama → bilgelik basamakları vardı.

**Soru:** Bağlam bilgisi elde ederken tek sensör mü birden fazla sensör mü tercih edilir? **Cevap:** Bir öğrenci doğruluk açısından birden fazlasının tercih edileceğini söyledi. Hoca, bazı olayların tek bir sensörle büyük doğrulukla tespit edilebildiğini, bazılarının ise birden fazla sensör bilgisi gerektirdiğini söyledi.

> **Hocanın vurgusu:** Karar vermek için mümkünse en az enerji tüketen ve en az veri toplayan sensör kullanılmalıdır. Tek bir sensörün maliyeti yüksekse, onun yerine maliyeti düşük üç sensörle karar vermek daha akıllıcadır. Örneğin bir kişinin hareketini incelerken kolundaki saatin manyetometresini, jiroskobunu ve ivmeölçerini kullanmak, eve kamera sistemi kurmaktan daha akıllıcadır; kamera sisteminin hem kurulum hem görüntü alma maliyeti yüksektir.

**Soru:** Telefonda güvenlik için parmak izi tanıma mı yüz tanıma (Face ID) mı tercih edilmeli? **Cevap:** Bir öğrenci parmak izini tercih ettiğini, daha az enerji tükettiğini düşündüğünü söyledi. Hoca biyometrik bilgilerin merkezi olarak tutulmasının ve sızdırılabilmesinin bir risk olduğunu, kişiye özel biyometrik veriler için mutlaka koruma önlemleri alınması gerektiğini belirtti. Biri kamera, diğeri parmak izi sensörü üzerinden tespit yapar; kamera tabanlı yüz tanımanın parmak izine göre daha güvenli olduğu söylenir; Face ID için milyonda bir hata olasılığı konuşulur.

> **Ek bilgi (derste anlatılmadı):** Apple'ın açıkladığı değerlere göre Face ID'de rastgele bir kişinin cihazı açabilme olasılığı yaklaşık milyonda bir, Touch ID'de (parmak izi) ise yaklaşık elli binde birdir. Bu oranlar üreticinin beyanıdır; ikizler ya da küçük çocuklar gibi durumlarda olasılık değişebilir.

### 17.4 Bağlam Farkında Sistem

Hocanın slayttan okuduğu tanım: "A system is context-aware if it uses context to provide relevant information or services to the user where relevancy depends on the user task." Yani bir sistem, bağlamı kullanarak kullanıcıya görevine göre ilgili bilgi ya da hizmet sunuyorsa bağlam farkındadır.

Bir sistemin bağlam farkındalığına sahip olabilmesi için dört özelliği olmalıdır:

- Edinme (acquisition): verinin toplanması. Sistemin mutlaka veri toplayan bir yapısı olmalıdır.
- Temsil (representation): verinin işlenmesi ve veriden bilgi çıkarılması.
- İletme (delivery): çıkarılan bilginin ilgili birimlerle paylaşılması.
- Tepki (reaction): Ortamda A birimi bir karar verdiyse ve ışığı kapatacak mekanizma başka bir birimse, bu tepkinin de gerçekleşmesi gerekir.

Bunların hepsi bir yaşam döngüsü içinde gerçekleşir.

## 18. Bağlam Modeli, Öznitelikleri ve Bağlam Kalitesi

### 18.1 Bağlam Modeli ve Bağlam Özniteliği

Slayttaki tanımlar (ekrandan, 02:35:00):

- Bağlam modeli, bağlamın sensörlerden, uygulamalardan ve kullanıcılardan gerçekçi biçimde elde edilebilen ve görevin yürütülmesinde kullanılabilen somut bir alt kümesidir. Bir bağlam farkında uygulamanın kullandığı model genellikle uygulama geliştiricisi tarafından açıkça belirlenir, ama zamanla gelişebilir.
- Bağlam özniteliği (context attribute), bağlam modelinin bağlamı tanımlayan bir elemanıdır. Bir özniteliğin kimliği (identifier), türü ve değeri, isteğe bağlı olarak da belirli özellikleri tanımlayan bir özellikler kümesi vardır.

**Soru:** Bir bağlamı tanımlayan öznitelikler neler olabilir? **Cevap:** Bir öğrenci bir oda için içindeki yapıları (cam, pencere, ışık) söyledi. Hoca örnek olarak odadaki ışık miktarını ve karbondioksit miktarını verdi; karbondioksit hava kalitesini ölçmek için çok önemlidir ve akıllı şehirlerle ilgili hava kalitesi üzerine birçok çalışma vardır. Önce bağlamdan beklenti belirlenmelidir: Hava temizliğiyle uğraşılıyorsa ona yönelik öznitelikler tanımlanmalıdır.

> **Hocanın vurgusu:** Bağlam iyi tanımlanmazsa seçilecek sensörler de iyi seçilemez ve yapı düzgün kurulamaz. Bu yüzden bağlamı çok düzgün kurmak gerekir.

### 18.2 Bağlam Kalitesi

Slayttaki "Quality of Context" başlığı üç parametre sıralıyordu (ekrandan, 02:40:00): bağlam verisinin geçerliliği (context data validity), hassasiyeti (context data precision) ve güncelliği (context data up-to-dateness).

**Soru:** Bu üç özellik ne anlama gelir? **Cevap:** Bir öğrenci Türkçe karşılıklarını güvenilirlik, hassasiyet ve güncellik olarak verdi. Güncellik için: Geçmişe dönük bir araştırma yapılmıyorsa her zaman en güncel veriyle çalışılmak istenir; arşivleme ihtiyacı yoksa eski veri ayıklanabilir. Otonom araçta 3 saniye önceki veriyle "şimdi sola dönelim" kararı verilirse araç yoldan çıkabilir. Hassasiyet için: Ortam sıcaklığının 25 ya da 26 derece ölçülmesi arasında büyük fark yoktur, ama sapma 5-10 derece gibi uç değerlere çıkarsa kararlar ciddi biçimde etkilenir. Geçerliliğin sensörün kalitesiyle, ne kadar doğru ölçüm yapabildiğiyle ilgili olduğunu düşündü.

Hoca açıklamayı genel olarak doğru buldu ve şöyle toparladı:

- Geçerlilik (validity): bağlam verisine duyulan güveni gösterir. Bağlam verisinin alındığı kaynaklar güvenilirlik açısından puanlanabilir; birden fazla kaynaktan bilgi geldiğinde değerlendirme ya da model buna göre güncellenir.
- Hassasiyet (precision): kullanılan sensörün ne kadar hassas ölçüm yapması gerektiğidir. Örneğin standart çözünürlüklü (ör. 800×600) bir kamerayla kişinin yüzü çözülemiyorsa yüksek çözünürlüklü (HD) görüntü almak gerekebilir.
- Güncellik (up-to-dateness): karar verirken elde toplanan veriler arasından en güncelinin kullanılmasıdır. Büyük veride aynı yer için farklı kaynaklardan bilgi gelebileceği için bu bir sorundur; önemli olan güncel, doğru ve yüksek çözünürlüklü bilgiyi kullanmaktır.

<!-- BELİRSİZ: 02:38:54 civarında hocanın andığı daha düşük çözünürlük değeri altyazıda "644-180" diye bozuk geçiyor (büyük olasılıkla 640×480); karede bu kısım görünmüyor. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:21:01): 5G'nin diğer baz istasyonu protokollerinden (2G, 3G, 4.5G) en önemli farkı nedir ve neden otonom araçlar için kritiktir?

> **Cevap (derste verildi):** Hedeflenen yaklaşık 1 ms'lik gecikme (tepki süresi); çok sayıda eş zamanlı bağlantı da bir farktır. Otonom araçta sunucuya gidip gelme süresi kısaldıkça çevrim içi verilecek kararlardaki gecikme riski azalır.

**Soru 2** (derste sözlü, 00:40:57): Sensör ağında özel bir küme başı düğümü yoksa ağın ömrünü uzatmak için ne yapılır?

> **Cevap (derste verildi):** Küme başı görevi düğümler arasında dönüşümlü olarak devredilir (enerjisi azaldığında, arızalandığında ya da belirli periyotlarla). Böylece her düğüm eşit enerji harcar ve ağ uzun süre kopmadan çalışır.

**Soru 3** (derste sözlü, 00:44:12): Bir ormana yerleştirilmiş sensörlerden 22, 22 ve 78 derece değerleri geliyor. Bu durum nasıl yorumlanır ve yinelenen veri burada neden yararlıdır?

> **Cevap (derste verildi):** 78 derece aykırı değerdir ve o sensörün bozuk olduğu anlaşılır; ondan gelen veri artık dikkate alınmaz. Komşu sensörler aynı bilgiyi ürettiği için bu tespit yapılabilir; tek sensör olsaydı bozulduğunda o bölgeden veri alınamazdı.

**Soru 4** (derste sözlü, 00:45:29): Bir veriye hangi özelliklere göre büyük veri denir? 3 TB sıcaklık verisi büyük veri midir?

> **Cevap (derste verildi):** Hacim, hız, çeşitlilik ve doğruluk (4V). Tek tip ve yavaş değişen 3 TB sıcaklık verisi normalde büyük veri problemi sayılmaz.

**Soru 5** (derste sözlü, 01:02:23): Bir IoT cihazından veri alırken her mesajda mutlaka aktarılması gereken bilgiler nelerdir? Hangi bilgiler tekrar tekrar alınmamalıdır?

> **Cevap (derste verildi):** Zaman damgası, verinin kendisi ve verinin hangi sensöre ait olduğu her turda aktarılmalıdır; konum (ya da cihaz kimliği ile eşlemesi) de önemlidir. Örnekleme frekansı gibi değişmeyen bilgiler tekrar alınmamalı, batarya durumu gibi zamanla değişen bilgiler belirli aralıklarla sorgulanmalıdır.

**Soru 6** (derste sözlü, 01:05:43): IoT'de hangi mesajlaşma protokolleri kullanılır? Neden HTTP ya da doğrudan soket tercih edilmez?

> **Cevap (derste verildi):** MQTT (yaygın) ve rakibi CoAP. IoT cihazlarının kapasitesi düşük olduğu için daha hafif bir protokol gerekir; soket tabanlı çözümler maliyetlidir. (MQTT ve CoAP'ın çalışma modeli için bölüm 9.2'deki ders sonrası nota bakın.)

**Soru 7** (derste sözlü, 01:08:13): IoT'den toplanan veriler genellikle nasıl bir veritabanında saklanır ve neden?

> **Cevap (derste verildi):** MongoDB gibi NoSQL veritabanlarında. IoT verisi ilişkisel bağlantılardan çok nesne bazında üretilir ve bütün olarak saklanmak istenir.

**Soru 8** (derste sözlü, 01:15:21 ve 01:16:26): Sensör ağı ile IoT arasındaki iki temel fark nedir?

> **Cevap (derste verildi):** Sensör ağında veri ağırlıklı olarak tek yönlü merkeze akar, IoT'de çift yönlü bir konuşma vardır. Sensör ağları uygulama odaklıdır, IoT insan odaklıdır. Ayrıca bir cihazın IoT cihazı sayılması için bir eyleyiciyle eylem yapması gerekir.

**Soru 9** (derste sözlü, 01:29:15): Hava koşulları normalken bir saatlik uçak, tren ve otobüs yolculuğunu yorgunluk açısından sıralayın ve nedenini açıklayın.

> **Cevap (derste verildi):** En az yorucudan en çok yorucuya uçak, tren, otobüs. Uçak yalnız kalkış ve inişte ivmelenir, sonra sabit hızla gider ve doğrusal ivme sıfıra yakındır; karayolunda titreşim, fren ve hızlanma fazladır. Derste anlatılan çalışmada uçak yaklaşık 1'e 8 oranında daha konforlu bulundu.

**Soru 10** (derste sözlü, 01:40:35): Fiziksel sensörler dışında bağlam bilgisi sağlayan kaynaklara örnekler verin.

> **Cevap (derste verildi):** IP paketleri ve ağ akışları (saldırı tespiti), cihaz kayıtları (çökme nedeni), takvim (toplantıda telefonu sessize alma), mesajlar (spam ayıklama, puan hatırlatma, arayan numarayı rehberle eşleştirme). Bunlara sanal sensör denir.

**Soru 11** (derste sözlü, 02:08:59 ve 02:09:23): IoT ve sensör ağlarında kullanılan üç veri toplama biçimi nedir?

> **Cevap (derste verildi):** Olay güdümlü (ör. sıcaklık 50 dereceyi geçince gönderme), zaman güdümlü (belirli periyotlarla gönderme) ve sorgu tabanlı (istek gelince gönderme; ör. yangın şüphesinde kameranın açılması).

**Soru 12** (derste sözlü, 02:28:14): Sürekli ve kesikli bağlam (olay) örnekleri verin.

> **Cevap (derste verildi):** Sürekli: araba yolculuğu, yağmurun yağmaya devam etmesi, havanın güneşli olması. Kesikli: direksiyonun başına oturma ya da arabaya binme anı, kapının açılması ya da kapanması.

**Soru 13** (derste sözlü, 02:29:43): Bağlam bilgisi elde ederken sensör seçimi nasıl yapılmalıdır? Hareket tanıma için hangisi daha akıllıcadır: saatteki sensörler mi, evdeki kamera sistemi mi?

> **Cevap (derste verildi):** Mümkünse en az enerji tüketen ve en az veri toplayan sensör seçilir; tek pahalı sensör yerine birkaç ucuz sensör tercih edilebilir. Hareket tanımada saatteki ivmeölçer, jiroskop ve manyetometre, kurulum ve görüntü alma maliyeti yüksek olan kamera sisteminden daha akıllıcadır.

**Soru 14** (derste sözlü, 02:33:21): Bir sistemin bağlam farkında olabilmesi için sahip olması gereken dört özellik nedir?

> **Cevap (derste verildi):** Edinme (verinin toplanması), temsil (işlenip bilgi çıkarılması), iletme (bilginin ilgili birimlerle paylaşılması) ve tepki (kararın uygulanması).

**Soru 15** (derste sözlü, 02:35:59): Bağlam kalitesini belirleyen üç parametre nedir ve her biri ne anlama gelir?

> **Cevap (derste verildi):** Geçerlilik (veriye ve kaynağına duyulan güven), hassasiyet (sensörün ölçüm inceliği; ör. yüz tanıma için yeterli çözünürlük) ve güncellik (karar anında en yeni verinin kullanılması; ör. otonom araçta eski veriyle karar vermemek).

## Dersin Toparlaması

Bu derste bağlam farkındalığına geniş bir girişle başlandı. Önce mobil hesaplamanın kapsamı, mobil haberleşme teknolojileri, 5G'nin düşük gecikme hedefi ve insan-bilgisayar etkileşimindeki yeni biçimler (ses, sanal asistanlar, duygu farkında hesaplama) ele alındı. Ardından yaygın hesaplamanın getirdiği veri yönetimi sorunu, bu soruna karşı yerinde işleme ve uç bilişim, sensör ağlarında küme başı ve yinelenen verinin aykırı değer tespitindeki yararı, büyük verinin 4V kuralı ve IoT'de güvenlik için ara katman kullanımı tartışıldı. IoT verisinde zorunlu alanlar, mesajlaşma protokolleri, veri biçimleri ve NoSQL saklama da bu bölümde konuşuldu.

Dersin ikinci yarısında internetin evrimi, IoT tanımları, türleri ve kategorileri, sensör ağı ile IoT farkları (tek/çift yönlü akış, uygulama/insan odaklılık, eyleyici), sanal sensörler, IoT'nin temel özellikleri ve IoT cihazlarında işletim sistemi tartışması işlendi. Sürüş analizi ve ulaşım yorgunluğu çalışması bağlam farkındalığının uygulama örneği olarak anlatıldı. Son bölümde bağlamın tanımı, kesikli ve sürekli olaylar, ham veri ile bağlam bilgisi ayrımı, bağlam farkında sistemin dört özelliği, bağlam modeli ve öznitelikleri ile bağlam kalitesi ele alındı. Hoca, şimdiye kadar genel bir giriş yapıldığını, ilerleyen haftalarda daha belirli konulara inileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
