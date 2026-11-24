# Ders 3 Genişletilmiş Notu: Dönem Projesi Test Sunumları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı ve projeden beklenenler
- 2. ATM otomasyonu: negatif testler, Jira biçimi, Selenium ve Postman
- 3. Taksi bulma sistemi: gereksinimler, test planı ve Python unittest
- 4. Sözcük çözümleyici: test durumu, hata raporu, JUnit ve bütünleme testi
- 5. Marketim: kara kutu testleri, Mocha/Chai, Postman ve JMeter
- 6. Kütüphane sistemi: JUnit ile birim testleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı ve projeden beklenenler

Bu derste konu anlatımı yapılmaz. Dönemin son dersinde gruplar, dönem boyunca hazırladıkları yazılım kalite ve test projelerini sunar. Toplam beş sunum yapılır: dört grup ve tek başına çalışan bir öğrenci. Sunumların çoğu aynı iskeleti izler: test edilecek yazılımın tanıtımı, gereksinim listesi ya da yazılım gereksinim spesifikasyonu, test planı ve test stratejisi, birim testleri, fonksiyonel (kara kutu) testler, varsa performans ve yük testleri, son olarak test sonuçları.

Hoca sunumlar sırasında projeden ne beklediğini birkaç kez açıkça söyler. Bu beklentiler dersin test sürecine bakışını özetler:

- Proje için öğrencilerin daha önce geliştirdiği (örneğin başka bir dersin ara projesi), gereksinimini iyi bildiği bir yazılım seçilir.
- Bu yazılım için gereksinim spesifikasyonu yazılır ya da var olan kullanılır.
- Ardından birim testi, kullanıcı testi ve performans testi yapılır.

> **Hocanın vurgusu:** Bu dersin hedefi kapsamlı bir yazılım geliştirmek değildir. Test edebilmek için projeye çok sayıda modül eklemek ya da projeyi sıfırdan yazmak hedeften sapmadır. Gereksinim listesi gerekiyorsa açık kaynak bir projeden de bulunabilir.

Hoca ayrıca her gruptan görev paylaşımını, yani kimin hangi testi yaptığını açıkça söylemesini ister ve birim testinin slaytta değil, testin yazıldığı geliştirme ortamında gösterilmesini bekler.

## 2. ATM otomasyonu: negatif testler, Jira biçimi, Selenium ve Postman

### 2.1 Uygulama ve gereksinimler

İlk grup bir ATM otomasyonu üzerinde çalışmıştır. Uygulama Java ile yazılmış bir masaüstü uygulamasıdır; kullanıcılar bir PostgreSQL veritabanında tutulur (ekrandan, 00:05:00). İki kullanıcı tipi vardır: bireysel kullanıcı TC kimlik numarasıyla, şirket ise vergi numarasıyla kayıt olur ve giriş yapar. Giriş yapan kullanıcı para yatırabilir, para çekebilir ve başka bir kullanıcıya para gönderebilir. Para çekme ve göndermede komisyon alınır; komisyon miktarı bireysel kullanıcı ile şirket için farklıdır.

Demoda yeni bir bireysel kullanıcı sıfır bakiyeyle kayıt olur. Adım adım:

- Verilen: başlangıç bakiyesi 0 TL.
- 500 TL yatırılır: bakiye $0 + 500 = 500$ TL.
- 200 TL çekilir, 1 TL komisyon alınır: $500 - 200 - 1 = 299$ TL.
- Başka bir kullanıcıya 150 TL gönderilir, 2 TL komisyon alınır: $299 - 150 - 2 = 147$ TL.
- Alıcının bakiyesi 413 TL'den $413 + 150 = 563$ TL'ye çıkar (413 değeri ekrandan, 00:05:00).

Sistemin fonksiyonları miktar ekleme, miktar çıkarma, para aktarımı, yeni müşteri kaydı ve kullanıcı girişidir. Fonksiyonel olmayan gereksinimler, uygulamanın bankalara yönelik olmasından kaynaklanır: her yaştan kullanıcının kullanabileceği anlaşılır ve kolay bir arayüz, güvenlik ve güvenilirlik (hassas veri tutulduğu için), kullanılabilirlik ve bankacılıkla ilgili yasal gereksinimler.

### 2.2 Test stratejisi ve test edilen öğeler

Grup sistem ve kullanıcı testleri yapmıştır. Test edilen modüller kullanıcı girişi, para aktarma, müşteri, ayarlar ve para yatırma modülleridir. Sistem hassas olduğu için mümkün olan en fazla testi yapmayı hedeflemişlerdir. Slayttaki test stratejisi şöyledir (ekrandan, 00:10:00):

> Uygulama kapsamında koşulmuş olan test case'ler analiz aşamasından sonra manuel olarak koşulmuş olup code coverage oranı gözetilerek kritik modüllerin tamamı test edilmiştir. Test yaklaşımında, yazılımın yalnızca yapması gereken öğeleri değil, yapmaması gereken öğeleri de test case'lerine dahil edilmiştir. Fonksiyonel test kısmında toplamda 43 adet olmak üzere yazılımın yapması ve yapmaması gereken öğeler kararlaştırılıp Jira formatına uygun bir şekilde dokümantasyonu hazırlanmıştır.

Performans testinde veritabanı bağlantıları, programın çalışma süresi ve işlemci kullanımı gibi metrikler göz önüne alınmış, kullanıcı dostu bir sistem için yanıt süresinin (response time) 100 milisaniyenin altında olması hedeflenmiştir. Grup daha sonra yük testine giremediklerini, elde ölçebildikleri tek metriğin yanıt süresi olduğunu söyler.

### 2.3 Negatif testler ve sonuçlar

43 fonksiyonel testten 36'sı geçmiş, 7'si bilerek başarısız bırakılmıştır. Başarısız testler yazılımın yapmaması gereken davranışları gösterir:

- Geçersiz karakter girildiğinde işlem gerçekleşmez, ama kullanıcıya işlemin yapılmadığını bildiren bir uyarı (pop-up) da çıkmaz.
- Para yatırma, gönderme ve çekme alanlarına sayı yerine farklı karakterler girilebilmesi.
- Bakiye yetersiz olduğu halde işlemin gerçekleşmesi.
- Bakiyenin tamamı çekilmek istendiğinde işlem gerçekleşir ve komisyon bakiyeyi eksiye düşürür. Beklenen, işlemin gerçekleşmemesidir.

<!-- BELİRSİZ: Grup başarısız testleri "low" ve "high" gibi önceliklere ayırıyor; altyazıda bu kısım bozuk, sınıf adları kesin değil. -->

### 2.4 Jira biçimli test case tablosu

Grup test case'lerini şirketlerde yaygın kullanılan Jira biçimine uygun bir tabloda tutmuştur. Kolonlar:

- Test adı (Test Name): testin ismi.
- Özet (Summary): neyin test edildiğinin kısa açıklaması.
- Beklenen sonuç: testin başarılı sayılması için vermesi gereken sonuç.
- Öncelik (Priority): yüksek ya da düşük.
- Proje: projenin adı.
- Durum (Status): testin başarılı ya da başarısız olduğu.
- Raporlayan (Reporter): testi yapan geliştiricinin adı.
- Test seti: testin ait olduğu grup. Örneğin fonksiyonel testler 001, performans testleri 002 setindedir; bu kolon aranan testlere hızlı ulaşmayı sağlar.

### 2.5 Proje dışı otomasyon örnekleri: Selenium ve Postman

Grup, Windows masaüstü uygulamasını otomatikleştiremeyince test otomasyonunu göstermek için proje dışında iki örnek eklemiştir.

**Selenium ile web arayüz otomasyonu.** Bir e-ticaret sitesinde şu senaryo kodla otomatikleştirilmiştir (ekrandan, 00:15:00): siteye git, giriş yap, arama kutusuna "bilgisayar" yaz, ikinci sayfaya geç, bir ürün seç, sepete ekle ve sepetten sil. Bu senaryo sitenin satın alma modülünü test eder; çalışma sırasında günlük (log) kayıtları tutulur. Grup otomasyonun amacını şöyle açıklar: regresyon testlerinde sürekli tekrarlanması gereken testlerde zaman kazanmak ve insanın yapabileceği hatalardan kaçınmak. Otomasyon kodu bir kod deposuna (GitHub, Bitbucket gibi) konursa Jenkins ile tetiklenebilir ve herkes istediği anda, ayrı bir sistem gereksinimi olmadan testi çalıştırabilir.

**Postman ile API testleri.** Postman genelde arka uç (backend) API testlerinde kullanılır. Grup, öğrenme amaçlı açık bir müzik servisi API'si kullanmıştır: takip edilen sanatçıları listeleme, takip edileni silme, çalma listesi oluşturma gibi istekler. Her istek için üç test case yazılmıştır. Birincisi durum kodunun 200 olup olmadığıdır: API doğru çalışıyorsa test geçer, çalışmıyorsa 400'lü ya da 500'lü bir kod döner.

> **Ders sonrası not:** Sunumda 400 kodu "zaman aşımı", 500 kodu "veritabanı sorunu" diye anıldı. Büyük olasılıkla doğrusu şudur: 400 hatalı istek (Bad Request), 408 zaman aşımıdır; 500 genel sunucu iç hatasıdır ve veritabanı ile sınırlı değildir.

Grup bir noktayı özellikle vurgular: durum kodunun 200 olması testin doğru olduğu anlamına gelmez. API çalışsa bile farklı girdilerle istenen sonuç elde edilemeyebilir. Bu yüzden yanıt gövdesi de test edilir; örneğin takip edilen sanatçılar listesinde belirli bir sanatçının bulunup bulunmadığı kontrol edilir. Postman'in Runner sekmesinde istekler seçilir, yineleme sayısı, gecikme süresi ve varsa veri dosyası verilerek API otomasyonu toplu çalıştırılır.

### 2.6 Hocanın değerlendirmesi

**Soru (hoca):** Birim testiniz var mıydı? **Cevap:** Grup birim testi yapmamıştır; onun yerine proje dışı otomasyon örneklerini eklemiştir.

**Soru (hoca):** Görev paylaşımınız nasıldı? **Cevap:** Grup önce sistem analizini birlikte yapmış, iki üye kodu yazmış, diğerleri test ve analiz kısmında çalışmıştır.

Grup ilk projenin yalnız terminalde çalıştığını, kullanıcıları sınıflarda tuttuğunu, test edebilmek için veritabanı ve arayüz ekleyip projeyi geliştirdiklerini anlatır. Hoca burada projenin hedefinden sapıldığını söyler: beklenen, gereksinimi bilinen bir projeye gereksinim spesifikasyonu yazıp ona birim, kullanıcı ve performans testi uygulamaktır.

## 3. Taksi bulma sistemi: gereksinimler, test planı ve Python unittest

### 3.1 Gereksinim spesifikasyonu

İkinci grup, daha önce bir veritabanı dersi için yazdıkları Python tabanlı taksi bulma sistemini kullanmıştır. Sistemin hedefleri:

- Müşterinin taksi bulması, taksinin uygunluk durumunu ve şoförün talebi kabul edip etmediğini görmesi.
- Şoförün müşteri taleplerini görüp yanıt vermesi ve kendi müsaitlik durumunu güncellemesi.
- Yöneticinin taksi kaydı yapması ve taksilerin müsaitlik durumunu güncellemesi.

Sistem anlık işlemlerle güncellenen bir veritabanı üzerinde çalışır: taksinin müsaitliği ya da yolcunun taksi çağırma durumu anında veritabanına yazılır. Kullanıcı özellikleri olarak kullanıcıların 18 yaş ve üzeri olması gerekir. İşletim sistemi kısıtı yoktur; Python çalışan her sistemde çalışır. Tasarım kısıtları: uygulama günün her saati kullanılabilir olmalıdır ve zamanla veri birikeceği için fazla depolama alanı gerekir.

Kullanıcı senaryoları gereksinimlerden önce açıklanmıştır:

- Taksi çağırma: kullanıcı giriş yapar, müşteri olduğunu belirtir, semt adını girer. Durak bu semte hizmet veriyorsa müsait taksilerin numaraları listelenir.
- Durak semte hizmet vermiyorsa: anlaşmalı ve bu semte hizmet veren bir durak varsa onun bilgisi döner; yoksa "bu semte hizmet vermemekteyiz" bilgisi verilir.
- Kullanıcı geçersiz semt adı girer ya da hiç girmezse uygun hata mesajı döner.
- Şoför müsaitlik durumunu değiştirebilir; yanlış kullanıcı adı ya da taksi numarası girerse sistem kapanır.

Gereksinimler fonksiyonel ve fonksiyonel olmayan olarak ikiye ayrılmıştır. Fonksiyonel gereksinimler kullanıcı, taksi ve şoför yönetimi ile aramalarını, yöneticinin ve şoförün müsaitlik belirtmesini, durağın hizmet verdiği semtleri döndürmesini ve hata mesajlarını kapsar. Fonksiyonel olmayan gereksinimler performans (7/24 kullanım, birden fazla kullanıcıya hizmet), güvenilirlik (yedekli veritabanı), görünüm ve kullanım, güvenlik, sürdürülebilirlik ve taşınabilirlik, kullanılabilirlik, operasyonel ve yasal gereksinimlerdir.

### 3.2 Test planı

Test planı, yazılım sürecinde çıkacak hataların nasıl takip edileceğini, nasıl kontrol edileceğini ve bunlara nasıl tepki verileceğini tanımlar. Yazılım dört modüle ayrılmıştır: yönetici modülü, kullanıcı modülü, taksi durum güncelleme modülü ve taksi listeleme ve çağırma modülü. Hatalar üç derecede sınıflandırılmıştır:

- Birinci derece hata: yazılımın çalışmasını doğrudan etkileyen hatalar.
- İkinci derece hata: sistemin çalışmasını doğrudan etkilemeyen ama bazı işlevsel aksaklıklara yol açan hatalar; sistem çalışmaya devam eder.
- Üçüncü derece hata: estetik kaygılarla ilgili görsel hatalar. Yazılımın arayüzü olmadığı için bu derecede hata ile karşılaşılmamıştır.

Risk yönetimi bölümünde olası sorunlar (gereksinimlerin belirlenmesinde gecikme, donanımsal altyapı sorunu, kodlamayla ilgili hatalar) ve her birinden sorumlu üye bir tabloda verilmiştir. Test ortamı olarak Python ile yazılmış bir kod için herhangi bir işletim sistemi ve bir geliştirme ortamı (IDE) yeterlidir.

### 3.3 Test sonuç raporu ve birim testleri

Test sonuç raporu belgenin amacını ve kapsamını, kullanılan kaynakları, test tanımlarını, testlerin tarihlerini, kullanılan donanım ve yazılım bilgilerini, test sonuç tablolarını ve hata bildirim tablosunu içerir. Grup birim testleri Python'ın `unittest` modülüyle yazmıştır; çalıştırıldığında 42 test koşar ve hepsi geçer. Bunun dışında kullanıcı testi yapılmıştır; performans testi yapılmamıştır.

## 4. Sözcük çözümleyici: test durumu, hata raporu, JUnit ve bütünleme testi

### 4.1 Uygulama

Üçüncü grubun yazılımı Java ile yazılmış bir sözcük çözümleyicidir (lexical analyzer). Üst düzey bir dilde yazılmış kodun bilgisayarın anlayacağı biçime çevrilmesi için derleyici gerekir. Çözümleme sözcük (lexical), sözdizimi (syntax) ve anlam (semantic) çözümleme olarak ayrılabilir; proje ilk aşamaya odaklanır. Sözcük çözümleyici kaynak kodu onu oluşturan sözcüklere (lexeme) ayırır ve her sözcüğe bir token sınıfı atar: anahtar kelimeler, özel semboller, tanımlayıcılar (identifier), operatörler vb.

### 4.2 Gereksinimler

Fonksiyonel gereksinimler:

- Ondalıklı sayı, karakter katarı, tam sayı ve değişkenleri tanıma.
- Tanımsız sözcükleri tanıma.
- Bir kod satırında doğru sözcük ayrımı yapabilme.
- Bir kod bloğu içindeki sözcük tiplerini doğru ayırıp sayılarını verebilme ve kod satırlarının blok içindeki bütünlüğünü koruma.

Diğer gereksinimler (ekrandan, 00:40:00):

- Performans: art arda sık periyotlarla gelen kod satırlarıyla dolu bir kod bloğunu çözümleyebilme. Yani program tek satırda gösterdiği doğruluğu ve verimi art arda 100 satır girildiğinde de göstermelidir.
- Güvenlik: farklı kullanıcıların girişini test edebilme ve yönetici olarak çalıştırma modunu görebilme.
- Arayüz: tokenların arayüzde düzgün görünmesi; kodun boşluklu ve boşluksuz yazıldığında aynı sonucu vermesi.
- Uyumluluk: Windows ve Linux'ta aynı verimle çalışma.

### 4.3 Test durumu ve hata raporu

Grup her test için bir test durumu (test case) belgesi ve başarısız testler için bir hata raporu hazırlamıştır. Ekrandaki örnek (ekrandan, 00:45:00):

| Test durumu alanı | Değer |
|---|---|
| Başlık | Ondalıklı sayı yerine farklı bir değişken alımı |
| Öncelik | Yüksek |
| Numara | #02 |
| Test türü | İşlevsellik |
| Yürütme türü | Otomatik |
| Açıklama | Normalde `Float` olması gereken değerin `Invalid` olma durumunun görüntülenmesi |
| Adımlar | 1. VS Code açılır. 2. `assertEquals(Token.FLOAT, automaton.evaluate(" 100.888"));` yazılır. 3. Çalıştırılıp sonuçlar yazılır. |

| Hata raporu alanı | Değer |
|---|---|
| Test durumu numarası | #02 |
| Hata önem derecesi | Kritik |
| Hata açıklaması | Başta boşluk olduğu için `Float` olması gerekirken `Invalid` atandı |
| Test verisi | Kod satırı |
| Beklenen sonuç | `FLOAT` |
| Gerçek sonuç | `INVALID` |

Bu örnek, test durumunun beklenen sonuç ile gerçek sonucu karşılaştırarak hatayı nasıl ortaya çıkardığını gösterir. Sunumda tanımlayıcı olması gereken bir değerin geçersiz olarak sınıflandırılması da benzer bir test olarak anlatılır.

Bir başka test durumu (ekrandan, 00:55:00) manuel bir kara kutu testidir: "Tüm fonksiyonların kara kutu kontrolü", öncelik yüksek, numara #14, test türü işlevsellik, yürütme türü manuel. Adımlar: aralarına boşluk koyarak tokenlar yazılır ve çözümle (Analyse) düğmesine basılır. Beklenen sonuç girilen bütün tokenların görüntülenmesidir; arayüzdeki tabloda satır, token adı ve öznitelik kolonları vardır.

### 4.4 Birim testi ve bütünleme testi

Birim testleri JUnit ile yazılmıştır. Basit bir örnekte bir atama ifadesi çözümlenir; testten beklenen değişkeni tanımlayıcı (identifier), eşittir işaretini atama operatörü ve sağdaki değeri tam sayı (integer) olarak tespit etmesidir.

**Soru (hoca):** Bu program hangi dilde yazıldı, birim testi JUnit ile mi yaptınız? **Cevap:** Java ile yazıldı, testler JUnit ile yapıldı.

> **Hocanın vurgusu:** Hoca birim testini slayttan değil, testin yazıldığı ortamdan görmek ister; amaç ortamın nasıl kullanıldığını görmektir.

Bütünleme (integration) testleri arayüz üzerinden yapılmıştır. Test kodu kod alanına tıklar, bir kod parçası yazar, çözümle düğmesine basar, bekler ve dönen token tablosunu satır satır `assertEquals` ile karşılaştırır (ekrandan, 00:50:00). Ekrandaki örnekte girdi şudur:

```text
if ( 2 * 3 = 6 )
    print ( "six" )
```

Beklenen token listesi sırasıyla INTEGER, INTEGER, INTEGER, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, TIMES, KEYWORD, EQUAL, KEYWORD, STRING, LEFT_PARENTHESIS, RIGHT_PARENTHESIS olarak yazılmıştır. <!-- BELİRSİZ: Ekrandaki assert sırası girdideki sözcük sırasıyla örtüşmüyor; tablo türe göre sıralanıyor olabilir. Liste ekrandaki gibi aktarıldı. --> Bir sonraki testte `while ( true ) { i + + ; print ( 3 * 4 ) ; }` gibi iç içe, döngü içeren daha uzun bir blok verilir. Amaç, uzun ve iç içe kodda parantezlerin, çarpma işaretlerinin ve `print` gibi anahtar kelimelerin doğru tanınmasıdır.

### 4.5 Test stratejisi ve sonuçlar

Grup birim testi ve bütünleme testi yapmış, bütünlemede hata çıkan yerlere onaylama testi uygulamıştır. Birim testleri saydam kutu (beyaz kutu) yaklaşımıyla yazılmıştır; ayrıca kara kutu ve arayüz testleri yapılmıştır. Testlerin yaklaşık üçte biri başarısız olmuştur; grup bunu yaklaşık %66'lık bir başarı olarak özetler. Performans testinde 100 kod bloğu verildiğinde işlemin 32 ile 34 milisaniye arasında sürdüğü ölçülmüştür.

**Soru (hoca):** Hangi testleri gerçekleştirdiniz, özetleyin. **Cevap:** Birim testleri ve fonksiyonel testler; test stratejisinde birim testi, bütünleme testi ve hata çıkan yerlerde onaylama testi.

**Soru (hoca):** Bu test stratejisinin biçimini nereden aldınız? **Cevap:** Grup biçimin kendi hazırladıkları bir Excel tablosu olduğunu söyler. Hoca bu biçimi bu yıl vermediğini, önceki yıllarda verdiğini belirtir.

## 5. Marketim: kara kutu testleri, Mocha/Chai, Postman ve JMeter

### 5.1 Uygulama ve gereksinim listesi

Dördüncü grubun uygulaması "Marketim"dir: bakkal benzeri küçük işletmelerin stok ve iş takibini kolaylaştırmayı, gelir-gider dengesi hakkında bilgi vermeyi amaçlar. Hedef kitle ticaretle uğraşan küçük esnaftır. Proje iki parçadır: Node.js ile yazılmış bir REST API sunucusu ve React ile yazılmış web istemcisi.

Grup, uygun bir projeleri olmadığı için yeni bir proje hazırladıklarını, benzer bir uygulamanın daha iyi bir sürümünü yazıp masaüstünden web'e taşıdıklarını anlatır. Hoca gereksinim listesinin GitHub gibi bir kaynaktan da bulunabileceğini, çünkü dersin hedefinin yazılım geliştirmek olmadığını yineler.

Gereksinim listesi modüllere ayrılmıştır:

- Tedarikçiler: ad, adres ve telefon bilgisi.
- Ürünler: ad, benzersiz barkod, alış ve satış fiyatı, KDV oranı, stok. Maliyet hesaplanırken alış fiyatına KDV eklenir.
- Müşteriler: ad, adres, telefon, alacak-verecek bilgisi.
- Satış: ürünler barkod okuyucuyla okutulur, adetleri girilir ve tabloya eklenir; tabloda adet artırılıp azaltılabilir ya da ürün çıkarılabilir. Satış nakit, kredi kartı ya da veresiye olabilir. Veresiyede kayıtlı bir müşteri seçilir ve müşterinin borç-alacak durumu güncellenir.
- Kasa: miktar, açıklama ve gelir/gider türü; kayıt sistem saatiyle tutulur.

İşlevsel olmayan gereksinimler:

- Kullanıcı arayüzü: kullanıcılar teknolojiye hakim olmayabilir, bu yüzden modüller ayrı panellerde ve anlaşılır biçimde sunulmalıdır.
- Güvenlik: her kullanıcı kendi kullanıcı adı ve şifresiyle girer.
- Güvenilirlik: amaç esnafın defter yerine dijital sisteme geçmesidir; bu yüzden sistem belirli aralıklarla yedekleme yapmalıdır.
- Performans: en az 1000 kullanıcı aynı anda istek yaptığında da sistem yanıt vermelidir.

### 5.2 Tamamlanma kriterleri ve kara kutu testleri

Testlerin tamamlanma kriterleri:

- Planlanan yazılım, sistem ve kabul testi faaliyetleri gerçekleştirilmiş olmalıdır.
- Bütün test seviyelerindeki test durumları ve senaryolarının tamamı başarıyla sonuçlanmış olmalıdır.
- Testlerde çıkan 1., 2. ve 3. derece hataların tamamı çözülmüş olmalıdır.

Hata dereceleri ikinci gruptakiyle aynıdır: birinci derece sistemin genel çalışmasını doğrudan etkiler, ikinci derece sistemi durdurmaz ama bazı işlevleri engeller, üçüncü derece yalnız görseldir. Bir testin başarılı sayılması için sonucun belirli bir sürede dönmesi ve test edilen modülün görevini tamamlaması gerekir. <!-- BELİRSİZ: Yanıt süresi sınırı altyazıda bozuk ("300 bin saniye"); değer kesin değil. -->

Gereksinimlerden türetilen test senaryoları uygulama üzerinde canlı olarak kara kutu testiyle gösterilir:

- Tedarikçi ekleme: ad, adres ve telefon girilir; "başarıyla eklendi" mesajından sonra kaydın veritabanında olduğu kontrol edilir. Sonuç: başarılı.
- Satış listesindeki ürün adetlerinin değiştirilmesi: iki ürün eklenip adet artırılınca ürünün listede yer değiştirmesi gibi bir görüntü hatası çıkar. Sonuç: başarısız; yalnız görsel olduğu için üçüncü derece hata.
- Kasa olaylarını görüntüleme: başlangıç ve bitiş tarihi seçilir, olaylar getirilir. Sonuç: başarılı.
- Veresiye satış: "veresiye satış modülü aktif değildir" hatası alınır. Modül çalışmıyor ama program çalışmaya devam ediyor; bu yüzden ikinci derece hata.

### 5.3 Mocha ve Chai ile birim testleri

Birim testleri Mocha ve Chai ile yazılmıştır. Mocha, Node.js üzerinde ve tarayıcıda çalışan, senkron ve asenkron fonksiyonların test edilmesine izin veren bir JavaScript test çatısıdır. Chai, hem Node.js hem tarayıcı için kullanılabilen bir doğrulama (assertion) kütüphanesidir. Birim testleri dört gruptadır (ekrandan, 01:05:00): kasa olayları, müşteri, tedarikçi ve ürün birim testleri. Her grupta düzenleme, ekleme, getirme (çağırma) ve silme testleri vardır; ürün testlerinde ayrıca "barkodu ile ürün çağırma" testi bulunur. Her testin beklentisi, işlem başarılıysa `true` dönmesidir.

Test kodunda `describe` bloğu testin hangi test olduğunu belirtir; hangi modülün hangi metodunun çalıştırılacağı ve beklenen cevap yazılır. Veritabanına istek gönderilip yanıt beklendiği için test fonksiyonları `async` olmalıdır. Çalıştırıldığında 16 testten 15'i geçmiş, müşteri düzenleme testi başarısız olmuştur; grup bunu yeni müşteri eklemelerinin test verisini değiştirmesine bağlar.

### 5.4 Postman ile sistem testi

Sistem testlerinde fonksiyonel olmayan gereksinimler sınanmıştır. Postman, çok kod yazmadan HTTP istekleri göndermek için bir kullanıcı arayüzü sunan yaygın bir test aracıdır. Postman ile sistemin birçok parçasının birlikte çalışırken doğru sonuç üretip üretmediğine bakılır. Gösterilen adımlar:

- Tedarikçi getirme isteği gönderilir ve sonuç alınır.
- Mevcut ürün tablosuna bakılır, Postman üzerinden yeni bir ürün ekleme isteği gönderilir ve ürünün eklendiği doğrulanır.
- Barkodla ürün getirme isteği gönderilir.
- Ürün silme isteği gönderilir; aynı ürün tekrar istendiğinde bulunamadığı görülür.

### 5.5 JMeter ile yük testi

Yük testleri Apache JMeter ile yapılmıştır. JMeter, yük ve performans testi için tasarlanmış açık kaynaklı bir programdır; web uygulamalarını yoğun yüke ve eş zamanlı kullanıcı trafiğine karşı test etmek için kullanılır. Kurulum adımları (ekrandan, 01:10:00):

- Yeni bir test planı oluşturulur.
- Bir thread grubu eklenir ve sanal kullanıcı sayısı (örneğin 100 ya da 1000) verilir.
- Testlerde kullanılacak değişkenler için bir veri seti oluşturulur (örneğin müşteri bilgileri).
- İstek gövdesi JSON olduğu için bir HTTP Header Manager eklenir: `Content-Type: application/json`.
- Thread grubuna örnekleyici (sampler) olarak bir HTTP isteği eklenir; istek, yerel sunucunun 3001 portuna POST olarak gönderilir.
- Sonuçları görmek için "View Results in Table" ya da "View Results Tree" dinleyicileri eklenir.

Ekrandaki planda tekli tedarikçi getirme, çoklu tedarikçi getirme, tekli ürün ekleme, tekli tedarikçi çağırma, 100 kullanıcı ürün ekleme ve 100 kullanıcı müşteri ekleme testleri bulunur. Test başlatılmadan önce müşteri tablosuna bakılır; 100 kullanıcılı test çalıştırıldıktan sonra 100 müşterinin eklendiği görülür ve test başarılı sayılır.

## 6. Kütüphane sistemi: JUnit ile birim testleri

Son sunumu tek başına çalışan bir öğrenci yapar. Yazılım, daha önce bir ders için yapılmış klasik bir kütüphane sistemidir. Kitaplar stok bilgileriyle veritabanında tutulur. Sistemde ödünç verme ve rezervasyon servisleri vardır. Kullanıcı tipine göre limitler bulunur: ders kitabı türündeki kitapları yalnız öğretim üyeleri alabilir; öğrenci ve memurlar en fazla 3, öğretim üyeleri en fazla 6 kitap alabilir. Yönetici kullanıcılar bu limitleri ve ödünç alma sürelerini değiştirebilir. Gereksinimler bir kullanım durumu (use case) diyagramıyla gösterilmiştir.

**Soru (hoca):** Gereksinimleri alt alta listelememiş miydin? **Cevap:** Gereksinimler yalnız düz metin ve kullanım durumu diyagramı olarak yazılmıştır.

Dört test türü planlanmış ama yalnız birim testleri ve fonksiyonel testler yapılabilmiştir. Birim testleri Java ve JUnit ile yazılmıştır:

- Kullanıcı ekleme: yeni bir kullanıcı veritabanına yazılır, veritabanından geri okunur ve eklenen kullanıcıyla karşılaştırılır (ekrandan, 01:15:00). Kodda kullanıcı bilgileri sabit değişkenlere atanır, `registerANewUser` ile kayıt yapılır, `getACard` ile geri okunur ve ad alanı `Assert` ile karşılaştırılır.
- Aynı TC kimlik numarasıyla ikinci kayıt: bu işlem başarısız olmalıdır; test hata alınıp alınmadığını kontrol eder.
- Parça (kitap kopyası) ekleme: eklenen parçanın bilgileri veritabanından okunup karşılaştırılır.
- Kitap limiti: limitini dolduran kullanıcı daha fazla kitap alamamalıdır.
- Yöneticinin limit değiştirmesi: limit artırılır ya da azaltılır, sonra değişikliğin yansıdığı kontrol edilir.
- Ödünç alma süresinin değiştirilmesi ve doğru yansıması.
- Geç iade cezası: veritabanından bir kullanıcı çekilir, bakiyesine ekleme yapılır ve yeni bakiye kontrol edilir.
- Ders kitaplarının yalnız öğretim üyelerine verilmesi.
- Stok kontrolü: rastgele bir kullanıcıya rastgele bir kitap verilir, kullanıcı kitabı iade eder ve o kitabın stok adedinin arttığı kontrol edilir.

> **Ek bilgi (derste anlatılmadı):** Birim testlerinde gerçek veritabanına yazmak testleri birbirine bağımlı hale getirebilir; bir testin eklediği kayıt başka bir testin sonucunu değiştirebilir. Bu yüzden testler genellikle her çalıştırmada temizlenen bir test veritabanı ya da sahte (mock) nesnelerle yazılır. Marketim grubunun başarısız müşteri düzenleme testi büyük olasılıkla bu türden bir test verisi bağımlılığından kaynaklanmıştır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00): Bir sözcük çözümleyici için aşağıdaki test yazılmıştır:

```java
assertEquals(Token.FLOAT, automaton.evaluate(" 100.888"));
```

Test çalıştırıldığında beklenen ve gerçek sonuç nedir, hata raporunda neler yazılır?

> **Çözüm (derste sunumda verildi):** Beklenen sonuç `FLOAT`, gerçek sonuç `INVALID`'dir. Girdinin başında boşluk olduğu için çözümleyici sayıyı ondalıklı sayı olarak tanıyamamıştır. Hata raporunda test durumu numarası (#02), hata önem derecesi (Kritik), hata açıklaması (başta boşluk olduğu için `Float` yerine `Invalid` atandı), hatayı oluşturma adımları, test verisi (kod satırı), beklenen ve gerçek sonuç yer alır.

**Soru 2** (derste sözlü, 00:51:26): Projenizde hangi testleri gerçekleştirdiniz, özetleyin.

> **Cevap (derste verildi):** Birim testi ve fonksiyonel testler. Test stratejisinde birim testi ve bütünleme testi, bütünlemede hata çıkan yerlerde onaylama testi yer alır. Hocanın beklediği en az set birim testi, kullanıcı testi ve performans testidir.

**Soru 3** (derste sözlü, 00:17:51): Bir API isteğinin durum kodu 200 dönüyorsa test başarılı sayılabilir mi?

> **Cevap (derste verildi):** Hayır. 200 yalnız API'nin çalıştığını gösterir. Farklı girdilerle istenen sonuç elde edilemeyebilir; bu yüzden yanıt gövdesi de ayrı test case'lerle kontrol edilir (örneğin listede beklenen kaydın bulunması).

## Dersin Toparlaması

Bu derste beş proje sunumu üzerinden dersin test sürecinin bütün parçaları uygulamalı olarak görülür. Gruplar gereksinim listesi ya da spesifikasyonu ile başlayıp test planına geçer; test planında test edilecek modüller, hata derecelendirmesi (1., 2. ve 3. derece), risk yönetimi, test ortamı ve tamamlanma kriterleri yer alır. Test durumu ve hata raporu belgeleri beklenen ve gerçek sonucu karşılaştırarak hatayı izlenebilir kılar; Jira biçimi bunun sektördeki karşılığıdır. Negatif test, yani yazılımın yapmaması gerekenlerin de test edilmesi, birkaç grupta öne çıkar.

Araç tarafında Java için JUnit, Python için `unittest`, Node.js için Mocha ve Chai birim testinde; Selenium web arayüz otomasyonunda; Postman API ve sistem testinde; JMeter yük testinde; Jenkins otomasyonun sürekli tetiklenmesinde kullanılır. Hocanın genel mesajı, dersin amacının yazılım geliştirmek değil, gereksinimi bilinen bir yazılıma sistemli bir test süreci uygulamak olduğudur: gereksinim spesifikasyonu, birim testi, kullanıcı testi ve performans testi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
