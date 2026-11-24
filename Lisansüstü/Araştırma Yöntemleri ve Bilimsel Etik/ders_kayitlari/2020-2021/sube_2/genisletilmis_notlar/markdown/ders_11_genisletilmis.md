# Ders 11 Genişletilmiş Notu: Girişim Projesi Sunumları (İkinci Hafta)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi ve Süre Kuralı
- 2. Yazılım Test Otomasyon Platformu
- 3. Müzik Aleti Kiralama Platformu
- 4. Çevrim İçi Beslenme ve Spor Danışmanlığı
- 5. Kişisel Bakım İşletmeleri İçin Randevu Uygulaması
- 6. Ofis ve Toplantı Salonu Kiralama Platformu
- 7. Enstrüman Öğrenme Simülasyonu
- 8. Gizlilik Sözleşmelerini Açıklayan Uygulama
- 9. Akıllı Biber Gazı Spreyi Kılıfı ve Hocanın Yorumları
- 10. Köşe Yazısı Platformu
- 11. Atık Yağ Transferli Fritöz
- 12. Market Fiyat Karşılaştırma Uygulaması
- 13. Hocanın Genel Değerlendirmesi: İş Fikri Nasıl Sunulur?
- Örnek Sorular

## 1. Dersin Biçimi ve Süre Kuralı

Bu ders, öğrenci girişim projesi sunumlarının ikinci haftasıdır; konu anlatımı yapılmadı. Gruplar, TÜBİTAK 1512 girişimcilik destek başvurusu biçiminde hazırladıkları iş fikirlerini sundu. Her gruba 10 dakika verildi. Sunumların ardından dinleyicilere soru hakkı tanındı; çoğu sunumdan sonra soru gelmedi.

Üçüncü sunumdan önce hoca, sunumlara müdahale etmek istemediğini ama bir kuralı hatırlatması gerektiğini söyledi: herkesin 10 dakikası vardır ve kimse bir diğerinden daha kıymetli değildir. Bu kurala uyulmaması hem hocanın gözlemini hem de sırası bekleyen diğer grupları zor durumda bırakır.

> **Ek bilgi (derste anlatılmadı):** TÜBİTAK 1512, büyük olasılıkla "Teknogirişim Sermayesi Desteği" olarak bilinen, teknoloji tabanlı iş fikri olan girişimcilere yönelik aşamalı bir destek programıdır. Başvurular iş planı ve panel sunumu üzerinden değerlendirilir. Bu yüzden sunumlarda iş paketleri, pazar analizi ve finansal plan gibi başlıklar öne çıkar.

## 2. Yazılım Test Otomasyon Platformu

İlk grup, test süreçlerinin tamamını tek bir platformdan yönetmeyi hedefleyen bir yazılım test otomasyon aracı sundu.

### 2.1 Yazılım testi nedir?

Grup yazılım testini, bir yazılımın kendisinden beklenen özellikleri karşılayıp karşılamadığını incelemek, karşılamıyorsa istenen düzeye getirmek için belirli kurallar dahilinde işletilen bir süreç olarak tanımladı. Sürecin kalitesi, yapılan testin kalitesini de belirler. Test ürünün çıkışını geciktirse bile hatayı erken tespit ettiği ve önleyici faaliyetler içerdiği için uzun vadede maliyeti düşürür, ürün kalitesini ve müşteri güvenini artırır.

### 2.2 Yenilikçi yön

Normalde testler manuel test uzmanları ya da kod yazan test otomasyon uzmanlarınca yapılır; oysa ürüne en hâkim kişiler analistlerdir. Önerilen platform, test otomasyonunu analistlerin yönetebilmesini amaçlar. Bunun için kod bilme zorunluluğu ve kurulum gerekliliği yoktur; böylece test otomasyonunun en büyük zorluğu olan testlerin güncel tutulması kolaylaşır (ekrandan, 00:10:00).

Platformun hedeflenen özellikleri şunlardır:

- Test senaryolarının (test case) oluşturulması ve koşturulması, hataların (defect) tespiti, ilgili görevlerin yönetimi, raporlama ve gerekirse raporların e-postayla gönderilmesi.
- Modüler test senaryoları sayesinde yeniden kullanım.
- Web arayüz testlerinin yanında Android ve iOS mobil testleri; aynı arayüze sahip uygulamalarda senaryoyu yeniden yazmadan iki platformda çalıştırma.
- SOAP ve REST servis testleri.
- Tarayıcı eklentisiyle test nesnelerinin ön izlenmesi.
- Testlerin günlük, haftalık, aylık gibi periyotlarla otomatik çalıştırılması ve ortam seçimi.
- Test senaryolarının yüzde kaçının otomatikleştirildiğini gösteren bir kapsama (coverage) modülü.

### 2.3 Ar-Ge gereksinimleri

Slaytta "Otomatik Test Case Oluşturulması (Web + Mobil)" başlığı altında şu gereksinimler sayıldı (ekrandan, 00:15:00):

- Yalnız gerekli test nesneleri otomatik oluşturulmalı; bunun için gereksiz nesneleri filtreleyen akıllı algoritmalar yazılmalı.
- Yeni test nesnesi eklemek kolaylaştırılmalı ve bir ön izleme mekanizması kurulmalı.
- Kaynak koddaki değişiklikler algılanıp güncellenmesi gereken test senaryolarının sahiplerine sistem üzerinden bildirim gönderilmeli.

Bunlara ek olarak test olgunluğunu ölçecek metriklerin belirlenmesi (alandaki deneyimli kişilerle anket ya da saha gözlemiyle), Oracle, MySQL gibi farklı veri tabanlarını destekleyen ortak bir sorgu yapısı ve performans testlerinin platforma eklenmesi de araştırma konuları olarak verildi.

### 2.4 Rakip karşılaştırması

Robot Framework ve Serenity ile karşılaştırmada, bu araçların kurulum ve kod yazma gerektirdiği, geliştiricilere uygun olduğu; önerilen platformun ise kurulumsuz, kod gerektirmeyen ya da çok az kod gerektiren ve analistlere uygun olduğu söylendi. En benzer rakip olarak Ranorex gösterildi: o da kodsuz test otomasyonu sunar, ama büyük bir kurulum dosyası, özel eğitim ve danışmanlık gerektirir ve lisans ücreti yüksektir. Lisans ücretleri slaytta şöyle verildi (ekrandan, 00:20:00):

| Araç | Ücret |
|---|---|
| Ranorex | 2.890 € (kullanıcı başına) |
| TestComplete | 3.730 € (kullanıcı başına) |
| HP UFT | 800 $ (kullanıcı başına, 3 aylık) |
| IBM Rational Functional Testing | Bulunamadı (N/A) |

Bu ücretlere danışmanlık ve eğitim maliyetlerinin eklendiği belirtildi.

## 3. Müzik Aleti Kiralama Platformu

İkinci sunum, web sitesi ve mobil uygulama üzerinden müzik aleti ve ses sistemi kiralamayı sağlayan bir platformdu. Platform hem büyük müzik markalarıyla müşteriler arasında köprü olmayı hem de bireylerin evlerindeki (örneğin taşınması zor bir piyano gibi) aletleri satmadan kiraya vererek gelir elde etmesini hedefler. Kullanıcı satın alamayacağı ya da merak ettiği bir aleti satın almadan deneyimleyebilir.

Prototipte "Bireysel" ve "Kurumsal" olmak üzere iki üyelik türü gösterildi. Kurumsal üyelikte markalar kiralanacak aletlerini ekler; bireysel üyelikte kişiler kendi aletlerini sunar. Her iki durumda da kiralama maliyetleri, kullanıcıya ulaştırma ve teslim alma süreçleri platform tarafından takip edilir (ekrandan, 00:25:00). Teslimat ve iade kargo şirketleriyle yapılan anlaşmalarla sağlanacaktır.

Pazar analizinde ithal müzik aletleri pazarının büyüklüğüne, gitar ve bağlama satış adetlerine ve ülkedeki mağaza sayısına ilişkin bir dergi araştırmasından alıntılar verildi. Pazarlama için sosyal medya reklamları, sektör fuarları ve müşteri geri bildirimlerinin yayımlanması planlandı.

### 3.1 Kâra geçiş tablosu

Finansal planda üç yıllık bir "Kâra Geçiş Noktası" tablosu gösterildi (ekrandan, 00:35:00):

| Kalem | 1. yıl | 2. yıl | 3. yıl |
|---|---|---|---|
| Satış gelirleri | 24.480,00 | 42.032,75 | 151.470,00 |
| İşletme giderleri | 98.450,79 | 110.979,33 | 127.073,10 |
| Amortismanlar | 1.673,20 | 1.673,20 | 1.673,20 |
| Finansman gideri | 0,00 | 0,00 | 0,00 |
| Vergi öncesi kâr | −75.643,99 | −70.619,78 | 22.723,70 |
| Vergiler | 0,00 | 0,00 | 4.544,74 |
| Vergi sonrası kâr | −75.643,99 | −70.619,78 | 18.178,96 |
| Amortismanlar (geri eklenir) | 1.673,20 | 1.673,20 | 1.673,20 |
| Net nakit akışı 1 | −73.970,79 | −68.946,58 | 19.852,16 |
| İşletme sermayesi | 8.204,23 | 9.248,28 | 10.589,43 |
| Sabit yatırım | 60.866,64 | 0,00 | 0,00 |
| Kâra geçiş için net nakit akışı 2 | −143.041,66 | −78.194,86 | 9.262,73 |
| Toplam net nakit akımları | −143.041,66 | −221.236,52 | −211.973,79 |

(Tutarlar TL'dir.) Tablonun mantığı adım adım şöyledir:

- Vergi öncesi kâr = satış gelirleri − işletme giderleri − amortisman − finansman gideri. 3. yıl için: $151.470{,}00 - 127.073{,}10 - 1.673{,}20 = 22.723{,}70$.
- Zarar varsa vergi doğmaz; kâr varsa %20 vergi düşülür: $22.723{,}70 \times 0{,}20 = 4.544{,}74$, vergi sonrası kâr $18.178{,}96$.
- Amortisman nakit çıkışı gerektirmeyen bir gider olduğu için net nakit akışına geri eklenir: $18.178{,}96 + 1.673{,}20 = 19.852{,}16$.
- Net nakit akışı 2 = net nakit akışı 1 − işletme sermayesi − sabit yatırım: $19.852{,}16 - 10.589{,}43 = 9.262{,}73$.
- Toplam net nakit akımı yıllık değerlerin kümülatif toplamıdır: $-221.236{,}52 + 9.262{,}73 = -211.973{,}79$.

Tablodaki bütün değerler python ile kontrol edildi ve tutarlıdır. Sunumda ilk yıl zarar göze alındığı, üçüncü yılda kâra geçilmesinin hedeflendiği söylendi.

> **Ek bilgi (derste anlatılmadı):** Tabloda üçüncü yılda yıllık net nakit akışı pozitife geçse de kümülatif toplam hâlâ negatiftir. Yatırımın geri dönüşü (geri ödeme süresi) için kümülatif nakit akımının sıfırı geçtiği yıl esas alınır; bu tabloya göre bu durum büyük olasılıkla üçüncü yıldan sonra gerçekleşir.

## 4. Çevrim İçi Beslenme ve Spor Danışmanlığı

Üçüncü sunumda antrenörleri ve diyetisyenleri tek bir platformda kullanıcılarla buluşturan bir mobil uygulama anlatıldı. Kullanıcı hedefine göre (kilo vermek ya da almak) kişiye özel beslenme ve spor programı alır; seçtiği uzmanla uygulama üzerinden sürekli iletişim kurabilir. Uzmanların deneyimleri ve geçmişleri görüntülenebilir; kullanıcılar puan ve yorum bırakabilir, yüksek puanlı uzmanlar listede üste çıkar. Hizmet aylık ücretlendirilir; 6 ve 12 aylık toplu üyeliklerde indirim, tavsiye ile gelen kullanıcıya bir ay ücretsiz üyelik planlandı. Rakiplerden farkı olarak diyetisyen hizmeti ve kripto para ile ödeme seçeneği sayıldı.

Projenin iş paketleri 2021 Mayıs ile 2022 Mart arasını kapsayan 8 aşamalı bir Gantt çizelgesiyle gösterildi: işletme kuruluşu, gereksinim analizi/kurulum işlemleri, yazılım, mobil cihazlar için uygulama geliştirilmesi, internet sitesinin oluşturulması, müşteri ilişkileri yönetimi, son test ve pazarlama. Ekip bir analist, bir sistem mühendisi, bir back-end geliştirici ve bir mobil uygulama geliştiricisinden oluşur (ekrandan, 00:40:00).

## 5. Kişisel Bakım İşletmeleri İçin Randevu Uygulaması

Dördüncü sunum, kuaför, güzellik merkezi, makyaj stüdyosu, tırnak butiği ve serbest çalışanlar için bir randevu platformuydu. Kullanıcı işletmeleri haritada görür, önceki değerlendirmeleri ve görsel içerikleri inceler, çevrim içi randevu alır ve ödeme yapar; randevudan birkaç saat önce e-posta ve SMS ile hatırlatma alır. Hizmetten sonra değerlendirme ve görsel paylaşımıyla puan kazanır.

Slayttaki yenilikçi yön şöyle verildi: internet erişimi olmadığında da işletmelerin ve içeriklerin çevrim dışı incelenebilmesi, uygulamanın tek bir sektöre değil birden fazla sektöre hizmet vermesi ve uygulama içi satın alımların daha uygun fiyatlı olması (ekrandan, 00:50:00). Teknik tarafta iOS için Swift, Android için Kotlin, ödeme için 3D Secure ve dağıtım için uygulama mağazaları planlandı. Web tarafında Selenium gibi araçlarla senaryo tabanlı test, mobil tarafta fiziksel cihazlar ile emülatör ve simülatörler kullanılacağı söylendi. İş planı 15 ay (2 ay kuruluş, 8 ay geliştirme, 5 ay satış ve pazarlama) olarak verildi. Gelir modeli komisyon ve üyelik satışıdır.

## 6. Ofis ve Toplantı Salonu Kiralama Platformu

Beşinci sunumda bir hibrit çalışma platformu anlatıldı: gereksinimleri karşılayan her yer (ev, ofis, belediye konferans salonu, tatildeki okul sınıfı) saatlik, yarım günlük ya da günlük kiralanabilir. Hedef kitle sanal ofis firmaları, belediyeler, özel ve kamu okulları, genç girişimciler ve firma çalışanlarıdır (ekrandan, 01:05:00). Grup bu fikri "bu işin Uber'i" diye özetledi. Firmaların insan kaynakları ve raporlama sistemleriyle SDK üzerinden entegrasyon, kimlik doğrulamalı üyelik, kiralama başına yaklaşık %5 komisyon, ana sistem için bir bulut sağlayıcısı ve felaket kurtarma (disaster recovery) için ikinci bir bulut sağlayıcısı planlandı.

İş planı, her biri üç ay süren dört adımdan oluşur: araştırma ve kavram geliştirme; tasarım ve geliştirme; sistem testleri; sistem kabulü ve uygulama öncesi son işlemler. Son adımın alt başlıkları sistem kabulü, uygulama sonrası değişiklik kontrolü, kayıt saklama, uygulama sonrası periyodik değerlendirme ve tüm projeye ait raporun oluşturulmasıdır (ekrandan, 01:10:00).

## 7. Enstrüman Öğrenme Simülasyonu

Altıncı sunum, enstrüman öğrenmeyi birebir özel ders deneyimine yaklaştırmayı amaçlayan bir uygulamaydı. Grup önce müziğin teknik temeline değindi: basit harmonik hareketten sinyal işlemeye kadar uzanan bilgiler müziğin temelini oluşturur; ses, esnek bir ortamda mekanik titreşimlerle yayılan dalgadır.

İlk aşamada yan flüt ve piyano ile başlanacaktır. Kullanıcı önce eğitmen eşliğinde temel videoları izler (enstrümanın parçaları, notalar), sonra simülasyon ortamında çalar; uygulama çıkan sesi analiz ederek doğruluğunu teyit eder. Yöntem olarak sinyal analizi için Fourier dönüşümü ve MATLAB, veri tabanı için MS SQL, arka uç için ASP.NET, ön yüz için React ve React Native kullanılacağı söylendi (ekrandan, 01:15:00). <!-- BELİRSİZ: Altyazıda "füredönüşmü" geçiyor; bağlamdan büyük olasılıkla Fourier dönüşümü, kare ile doğrulanmadı. -->

Rakipler olarak yalnız akort/ses analizi sunan bir uygulama ile yalnız pasif eğitim içeriği sunan platformlar gösterildi; önerilen uygulama bu ikisini birleştirir. Gelir modeli aylık üyeliktir.

## 8. Gizlilik Sözleşmelerini Açıklayan Uygulama

Yedinci sunum bir bilgi güvenliği farkındalık uygulamasıydı. Kullanıcıların çoğu mobil uygulama ve çevrim içi hizmetlerde gizlilik sözleşmesini okumadan ya da hukuki terimleri anlamadan onaylar; böylece hangi verilerinin işlenip paylaşılacağını bilmez. Önerilen uygulamaya sözleşme PDF ya da görüntü olarak yüklenir; uygulama maddelerin hangi riskleri doğurabileceğini açıklar. Yurt içindeki benzer uygulamaların yalnız avukata sorduğu, yurt dışındaki örneklerin ise Türkçe ve Türk hukuku açısından yetersiz kaldığı söylendi; önerilen sistem hem yapay zekâ hem de "avukata sor" seçeneği sunar.

### 8.1 Çözüm diyagramı

Slayttaki çözüm diyagramı üç bloktan ve bir geri besleme döngüsünden oluşur (ekrandan, 01:30:00):

```text
[AI geliştirme platformu]
  Verilerin toplanıp etiketlenmesi (avukat/bilirkişi)
    -> Verilerin temizlenmesi (durak kelimeler vb.)
    -> NLP yöntemleri ve makine öğrenmesi algoritmalarıyla hesaplama
        |
        v
[AI model production]  (Kubernetes, Docker; izle - geliştir - çalıştır döngüsü)
        |
        v
[Mobil uygulama platformu]
  Uygulamanın Flutter üzerinde geliştirilmesi
    -> Görüntünün işlenmesi (Python, OpenCV) ve etiket yorumunun kullanıcıya sunulması
        |
        v  (madde hiçbir etikette bulunmuyorsa)
  Model güncellemesinde kullanılmak üzere veri tabanına gönderilir
        |
        v
[Model performans ölçüm yapısı] -> AI geliştirme platformuna geri döner
```

Servis tarafında her yeni istekte modelin tetiklenmesi gerektiği için mikroservis mimarisi kurulacağı belirtildi. Sistemde karşılığı olmayan maddeler için kullanıcı "avukata sor" seçeneğine yönlendirilir.

## 9. Akıllı Biber Gazı Spreyi Kılıfı ve Hocanın Yorumları

Sekizinci sunum bir donanım ürünüydü: biber gazı spreyine takılan akıllı bir kılıf. Grup, sokakta yaşanan şiddet vakalarının çoğunun kanıt yetersizliği yüzünden sonuçsuz kaldığını, mevcut spreylerin kendini korumaya yardım etse de saldırganın tespitine katkı sağlamadığını anlattı. Kılıfın özellikleri şunlardır:

- Sprey sıkıldığı anda buton kamerayı ve sesli uyarıcıyı (buzzer) tetikler; basılı kaldığı sürece fotoğraf çekilir.
- Fotoğraflar dahili SD kartta saklanır, bağlantı olduğunda Bluetooth ile telefona gönderilir; mobil uygulama zorunlu değildir.
- Düşük ışıkta net fotoğraf için güçlü LED, şarjlı batarya ve kullanılmadığında bekleme modu vardır.
- Yaylı mekanizma sayesinde farklı ölçülerdeki yaygın gaz spreyleriyle uyumludur (ekrandan, 01:35:00).

Pazar analizinde gaz spreyi pazarı dünya için 35 milyon dolar, Avrupa için 9 milyon dolar, Türkiye için 2,5 milyon dolar olarak gösterildi (ekrandan, 01:40:00). Pazarlama için e-ticaret, işyerlerine satış ve ileride distribütör ağı olmak üzere üç kanal planlandı.

### 9.1 Hocanın yorumları

Hoca iki öneri ve bir soru getirdi. Birincisi, cihazın dış gövdesinin 3B yazıcıyla basılabilir hale getirilmesi ve "kendin yap" (do it yourself) biçiminde paylaşılmasıydı; böylece ihtiyacı olan herkes ürünü kolayca üretip başka parçalarla birleştirebilir. Grup, prototipi zaten 3B yazıcıyla, seri üretimi plastik enjeksiyonla düşündüğünü, ama tasarımı açık kaynak paylaşma ve kâr amacı gütmeyen bir kuruluşla yürütme fikrini değerlendirebileceğini söyledi.

İkincisi, hoca biber gazının hukuki durumunun kontrol edilip edilmediğini sordu. Grup bunu birkaç kaynaktan araştırdığını ve ürünün spreyin kendisi değil kılıf olduğunu belirtti. Hoca burada bir ayrım yaptı: yasallık ile doğruluk aynı şey değildir. Genel geçer örnek olarak, kölelik bir zamanlar yasaldı ama o zaman da doğru değildi. Hoca sorusunun amacının yalnız bu kontrolün yapılıp yapılmadığını öğrenmek olduğunu, kontrol yapıldıysa sorun olmadığını söyledi.

## 10. Köşe Yazısı Platformu

Dokuzuncu sunumda, kullanıcıların gündemdeki toplumsal konularda köşe yazısı niteliğinde görüş yazdığı, yazıların kullanıcılar tarafından oylandığı ve en çok oy alan yazının basın yayın organlarında yayımlandığı bir web ve mobil platform anlatıldı. Hedefler herkesin fikrini resmî bir ortamda ifade edebilmesi ve gazete-dergi okuma alışkanlığının yeniden kazandırılmasıdır. Proje 6 ayda ve beş iş paketinde (proje yönetimi, yazılımın oluşturulması, yazılımın testi, basın yayın organlarıyla görüşme, projenin paylaşımı) planlandı.

Test tarafında slaytta yazılımın doğru çalıştığının kontrolü için önce birim testlerin yazılacağı, ardından belirlenen test kullanıcılarının ürünü test edip eksiklerin giderileceği belirtildi (ekrandan, 01:55:00). Slaytta "Util Test" yazıyor; kastedilen büyük olasılıkla birim testtir (unit test). Fikrî koruma için patent, rakiplerden fark olarak yazının resmî bir yayın organında yer alması gösterildi. Finansal planda iki yıllık toplam bütçe 621.500 TL olarak verildi.

## 11. Atık Yağ Transferli Fritöz

Onuncu sunum bir makine tasarımıydı. Önce bitkisel atık yağın tanımı (kızartma yağları, yağ tutuculardan çıkan yağlar, kullanım süresi geçmiş yağlar), sağlığa ve çevreye zararları (atık su borularında tıkanma, su kaynaklarının kirlenmesi) anlatıldı. İlgili yönetmeliğe göre atık yağ üreticisinin yükümlülükleri slaytta şöyle verildi: atık yağları diğer çöplerden ayrı tutmak, sağlam bidon ya da tank benzeri gereçlerde biriktirmek, yalnız lisanslı geri kazanımcılara teslim etmek, sevkiyat belgesini beş yıl saklamak ve valiliğe ulaştırmak (ekrandan, 02:00:00). Geri kazanılan yağ biyodizel olarak kullanılır; sunumda biyodizelin, kükürt içeren petrol kaynaklı dizele göre çevreye daha az zarar verdiği belirtildi.

### 11.1 Tasarım süreci

Tasarım için önce bir ihtiyaç listesi çıkarıldı: darbeye dayanıklı kabuk, insan sağlığına uygun malzeme, basit kullanıcı arayüzü, yüksek kullanım konforu, enerji sürekliliği, tek kişinin kullanabilmesi, estetik görünüm, başlangıç ve bitişte sinyal üretme, kolay montaj ve üretim. Sunan öğrenci tasarım felsefesindeki "en kötü kullanıcıya göre yapılan tasarım en iyi tasarımdır" fikrini basit arayüz gereksinimine bağladı.

Ardından yedi kriterli bir morfolojik seçim tablosu hazırlandı. Her kriter için alternatifler şunlardı:

| Kriter | Alternatifler |
|---|---|
| Enerji | Batarya, priz, güneş enerjisi |
| Malzeme | Kompozit, çelik |
| Uyarı | Ses, ışık, ışık+ses, titreşim |
| Kontrol | Kumanda, panel, manuel, manuel+panel |
| Montaj | Duvara dayalı, montajlanabilir |
| Tahliye | Musluk, pompa |
| Kullanım şekli | Dokunmatik, buton |

Kombinasyonlardan 3, 5 ve 6 numaralı seçenekler bütün kriterleri karşıladı. Bunlar, kullanım kolaylığı, basit üretim ve işlev olmak üzere üç ana amaç altında ağırlıklandırılarak puanlandı ve seçenek 3 seçildi: prizden beslenen, çelik malzemeli, ışıklı uyarılı, manuel ve panel kontrollü, montajlanabilir, pompalı ve dokunmatik kullanımlı bir fritöz.

Ağırlıklı amaç ağacı slaytta şöyle gösterildi (ekrandan, 02:05:00):

```text
Atık Yağ Transferli Fritöz (W1 = 1)
- Kullanım Kolaylığı (W11 = 0,5)
    - Arayüz/Erişilebilirlik  W111 = 0,4 | 0,3
    - Uyarı Sistemi           W112 = 0,3 | 0,2
    - Tahliye                 W113 = 0,3 | 0,2
- Basit Üretim (W12 = 0,2)
    - Yedek Parça             W121 = 0,6 | 0,06
    - Montaj Kolaylığı        W122 = 0,4 | 0,04
- İşlev (W13 = 0,3)
    - Amaca Uygun             W131 = 0,5 | 0,1
    - Memnuniyet              W132 = 0,5 | 0,1
Toplam: 0,3 + 0,2 + 0,2 + 0,06 + 0,04 + 0,1 + 0,1 = 1
```

Ağırlıklı amaç ağacında her alt amacın göreli ağırlığı üst amacın ağırlığıyla çarpılarak mutlak ağırlık bulunur ve mutlak ağırlıkların toplamı 1 olur.

> **Ders sonrası not:** Slayttaki mutlak ağırlıklar göreli ağırlıklarla üst ağırlığın çarpımına uymuyor. Çarpımla hesaplanırsa değerler $0{,}5\times0{,}4=0{,}20$; $0{,}5\times0{,}3=0{,}15$; $0{,}5\times0{,}3=0{,}15$; $0{,}2\times0{,}6=0{,}12$; $0{,}2\times0{,}4=0{,}08$; $0{,}3\times0{,}5=0{,}15$; $0{,}3\times0{,}5=0{,}15$ olur ve toplam yine 1'dir (python ile kontrol edildi). Slayttaki değerler toplamı 1 verse de büyük olasılıkla hatalı yazılmıştır.

### 11.2 Ürünün çalışması

Kızartma bölümünün altındaki plaka, kulplarından biri çekilince açılır ve atık yağ alttaki depolama bölmesine akar. Bölmedeki ağırlık sensörü yağ seviyesini belirler; dolunca kırmızı ışık yanar. İçerideki yağ pompası yağı restoran dışındaki belediye toplama varillerine kimse dokunmadan aktarır. Bir haberleşme modülü, yağ seviyesinin dolduğunu ve pompalandığını belediyeye bildirir. Böylece belediye restoranların atık yağ teslimini denetleyebilir, çalışanların iş yükü de azalır.

## 12. Market Fiyat Karşılaştırma Uygulaması

Başta hazır olmadığı için sona bırakılan grup, zincir marketlerdeki ürün fiyatlarını karşılaştıran bir mobil uygulama sundu. Slayttaki tanıma göre uygulama, rekabetin ve fiyat hareketliliğinin yüksek olduğu market sektöründe en ucuz ve güncel fiyatlara hızla ulaşmayı ve market zincirlerindeki fiyatların tek bir uygulamadan bulunmasını sağlar (ekrandan, 02:10:00). Hedef, geliri kısıtlı kullanıcıların market harcamalarında tasarruf etmesidir. Barkod tarama, sesli arama ve haritada en yakın marketi gösterme özellikleri planlandı.

Rakiplerden temel fark şudur: mevcut uygulamalar ya konum bilgisi sunmuyor ya da bir markette ürün yoksa muadilini göstererek birebir karşılaştırmayı bozuyor. Önerilen uygulama, seçilen ürünlerin her birini en ucuz olduğu markete atayarak sepeti birden çok markete böler (örneğin 10 ürünün 3'ü bir markette, 2'si başka bir markette, 5'i üçüncü bir markette).

Hedef kitle 25-45 yaş arası, alt ve orta gelir grubundaki akıllı telefon sahipleridir. Gelir modeli reklam, sponsorluk ve partnerlik anlaşmalarına dayanır. Slayttaki tahmini gelir tablosu şöyledir (ekrandan, 02:15:00):

| | 1. yıl | 2. yıl | 3. yıl | 4. yıl |
|---|---|---|---|---|
| Tahmini cihaz sayısı | 50.000 | 100.000 | 300.000 | 600.000 |
| Tahmini reklam tıklanma | 20.000 | 50.000 | 250.000 | 500.000 |
| Tahmini reklam sayısı | 10 | 20 | 30 | 40 |
| Tahmini ciro | 600.000 TL | 1.200.000 TL | 3.600.000 TL | 7.200.000 TL |

Maliyet tablosunda (sonraki slayt) personel 150.000 TL, seyahat 2.000 TL, alet/teçhizat/yazılım 90.594,4 TL, danışmanlık 4.000 TL, malzeme 12.877 TL, genel giderler 12.000 TL ve toplam 271.471,4 TL olarak verildi. Toplam python ile doğrulandı; personelin payı %55,25, alet/teçhizatın payı %33,37'dir.

## 13. Hocanın Genel Değerlendirmesi: İş Fikri Nasıl Sunulur?

Ders sonunda hoca, dersin geç saate uzamasının temel nedeninin bazı grupların süre kuralına uymaması olduğunu söyledi. Daha uzun bir sunum hazırlanmış olabilir, ama akış sırasında bazı slaytları atlayarak süreye uymak sunanın elindedir. Hoca sonuna kadar dinlemeye hazır olduğunu, ama sunum süresine uymanın bir görgü kuralı olduğunu vurguladı.

> **Hocanın vurgusu:** Sunum süresine uymuyorsanız, yaptığınız iş karşınızdakilere gerekli saygıyı göstermemektir.

Hoca, sunum teknikleri konusunda daha önce konuşulan en basit kuralın, yani ağzına kadar metin dolu slayt hazırlamamanın, bazı sunumlarda hiçe sayıldığını söyledi. İkinci haftada sunan grupların ilk haftayı görüp daha iyi hazırlanma avantajı olduğu için daha iyi sunumlar beklediğini belirtti. Bu sunumların yalnız notlama için değil, sunum tekniklerini geliştirmek için yapıldığını hatırlattı.

Ardından iş fikri sunumunun mantığını anlattı:

- Sunan kişi bir girişimcidir; bir iş fikri sunar ve karşısındakinden para ister.
- Yaptığı işe önce kendisi inanmalıdır ki karşısındaki de inanabilsin. Kendi inanmadığı bir fikri anlatamaz, kimseyi ikna edemez.
- "Ben de bu konuyu pek bilmiyorum, bu kadarını yapabildim" gibi cümleler sunumu anlamsız kılar.
- Kendinizi hocanın ya da 1512 panelindeki panelistlerin yerine koyun.
- Dürüstlük elbette güzeldir ve yalan söylemek ya da gerçeği bükmek istenmiyor. Ama böyle bir proje hazırlığında eksik bir konu varsa danışmanlık alarak, araştırma yaparak ya da tasarım desteği alarak kapatılmalı, konsepte uygun davranılmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:35:28): Müzik aleti kiralama platformunda kiralanan aletler için sigorta (kasko) yapılıyor mu? Alet kırılırsa servis verilecek mi?

> **Cevap (derste verilen):** Grup, kargo şirketleriyle anlaşarak güvenli teslimatı garanti edeceklerini, teslimattaki sorumluluğu kargo şirketine bırakacaklarını; sigorta fikrini henüz planlamadıklarını ama değerlendireceklerini söyledi.

**Soru 2** (derste sözlü, 01:44:16): Akıllı sprey kılıfını 3B yazıcıyla basılabilir ve "kendin yap" biçiminde paylaşılabilir hale getirmeyi düşündünüz mü?

> **Cevap (derste verilen):** Grup, prototipi 3B yazıcıyla, seri üretimi plastik enjeksiyon kalıbıyla düşündüğünü; tasarımı ve yazılımı açık kaynak olarak paylaşma, bir sivil toplum kuruluşu desteğiyle kamu hizmeti gibi yürütme fikrini değerlendirebileceğini söyledi.

**Soru 3** (derste sözlü, 01:46:20): Ürünün kullandığı biber gazının hukuki durumunu kontrol ettiniz mi?

> **Cevap (derste verilen):** Grup birkaç kaynaktan araştırdığını, satılan ürünün spreyin kendisi değil kılıf olduğunu söyledi. Hoca, yasal olanın her zaman doğru, yasa dışı olanın her zaman yanlış olmadığını; sorunun amacının yalnız bu kontrolün yapılıp yapılmadığını öğrenmek olduğunu belirtti.

## Dersin Toparlaması

Bu ders, girişim projesi sunumlarının ikinci haftasıydı ve on bir grup yazılım ya da donanım tabanlı iş fikirlerini sundu. Sunumlar, bir destek başvurusunun tipik bölümlerini (iş fikri, yenilikçi yön, pazar ve rakip analizi, iş paketleri ve zaman çizelgesi, ekip, finansal plan) somut örneklerle gösterdi. Kâra geçiş tablosu, morfolojik seçim tablosu, ağırlıklı amaç ağacı ve yapay zekâ tabanlı bir sistemin çözüm diyagramı gibi araçlar, bir iş fikrinin sayısal ve teknik olarak nasıl gerekçelendirileceğine örnek oldu.

Hocanın değerlendirmesi iki noktada toplandı: sunum süresine uymak dinleyiciye saygının gereğidir ve metin dolu slayt kullanılmamalıdır; bir iş fikri sunan kişi önce fikrine kendisi inanmalı, eksiklerini danışmanlık ve araştırmayla kapatarak paneli ikna edecek biçimde hazırlanmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
