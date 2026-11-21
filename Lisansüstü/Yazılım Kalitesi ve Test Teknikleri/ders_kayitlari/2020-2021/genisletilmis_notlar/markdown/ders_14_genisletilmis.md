# Ders 14 Genişletilmiş Notu: Öğrenci Proje Sunumları: Test Planları, Test Senaryoları ve Test Raporları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Bir Stok Takip Sisteminin Test Planı ve Testleri
- 3. Bir Psikolojik Envanter Uygulamasının Testi
- 4. Web Uygulaması Testinin Türleri
- 5. Bir Randevu Sisteminin Test Planı
- 6. Axios Kütüphanesinin Jest ile Testi
- 7. Bir İş/Staj Portalının Testi
- 8. Bir Emlak Fiyat Tahmin Uygulamasının Testi
- 9. Bir Stok Dağıtım Sisteminde Sevk Yasaklarının Testi
- Dersin Toparlaması

## 1. Dersin Yapısı

Dönemin son dersi, öğrencilerin dönem projesi sunumlarına ayrıldı. Her öğrenci (ya da iki kişilik grup) bir yazılım seçmiş, bu yazılım için test planı hazırlamış, test senaryolarını yazıp koşmuş ve sonuçları bir test raporunda toplamıştı. Sunumlarda bu belgelerin özeti ve kullanılan test araçları anlatıldı. Yedi sunum yapıldı: altısı somut bir yazılımın test sürecini, biri web uygulaması testinin türlerini genel olarak ele aldı. Bu not, sunumların akademik içeriğini sırasıyla verir; sunumu yapanlar adsız anılır.

Hoca sunumlar sırasında iki noktaya dikkat çekti. Birincisi, raporlar zaten teslim edildiği için sunumda kullanılan araçların nasıl kullanıldığının gösterilmesini istedi. İkincisi, genel bir anlatım yapan sunumda, anlatılan test türlerinden birinin kendi uygulamasına nasıl uygulandığını sordu.

## 2. Bir Stok Takip Sisteminin Test Planı ve Testleri

İlk sunumu iki kişilik bir grup yaptı. Test edilen yazılım, küçük ve orta ölçekli işletmelerin ürün stok yönetimi için tasarlanmış, kendi başına çalışan bir ürün stok takip sistemiydi. Use case diyagramında iki kullanıcı tipi vardı: admin ve standart kullanıcı. Standart kullanıcının yetkileri sınırlıydı; örneğin sisteme ürün ekleme ve ürün silme yetkisi yalnız admin kullanıcıdaydı. Arayüzde kategori listesi, ürün listesi, sepete ürün ekleme ve sepet detayı, admin için kullanıcı ekleme/silme ve ürün ekleme/silme ekranları bulunuyordu.

Grup, testin içeriğini dört başlıkta topladı: ürünün tanıtımı, test planı, fonksiyonel entegrasyon testi, birim testi ve kullanıcı kabul testi.

### 2.1 Test Planı: Zamanlama ve Kapsam

Proje zamanlaması bir Gantt şemasıyla gösterildi. SRS'in hazırlanması da projenin bir görevi olduğu için zamanlamaya katıldı; normalde zamanlama test hazırlık sürecinden de başlatılabilirdi. Test planı zamanlaması üç ana başlık altında yapıldı: test hazırlık, testin gerçekleştirilmesi ve test özet raporunun hazırlanıp onaylanması.

Test kapsamında fonksiyonel modüller sayıldı: kullanıcı girişi, kullanıcı ekleme, kullanıcı silme, ürün ve kategori listeleme gibi. Her modülün hedef kitlesi ve tanımı plana yazıldı; bu modüller fonksiyonel testin kapsamını oluşturdu.

### 2.2 Risk Yönetimi

Risk yönetimi bir tabloyla verildi. Tablonun sütunları risk, ihtimal, etki ve önlem planıdır (ekrandan, 00:10:00):

| Risk | İhtimal | Etki | Önlem planı |
|---|---|---|---|
| Takvim: test planı çok yoğun; tasarım ya da geliştirme uzarsa test ertelenir ama UAT'nin planlanan başlangıç tarihinin ötesine uzatılamaz | Yüksek | Yüksek | Tüm proje ekibiyle düzenli toplantılar |
| Personel: kilit konumdaki (key member) personelin ayrılması ya da test süresince çalışamaz olması | Orta | Yüksek | Bilgi yedeklemesi ve çalışan memnuniyeti |
| Hatalar: kritik hataların test sürecinin geç bir evresinde bulunması; genelde eksik gereksinim analizinden kaynaklanır | Orta | Yüksek | Sorunların derhal iletilip düzeltilmesi için hata yönetimi planı |
| Yeni sorunlar nedeniyle gecikmiş test | Orta | Yüksek | Hata yönetimi ve sorun yönetimi prosedürleri |
| Doğal afetler | Düşük | Orta | Tek merkezli yapıda önlem alınamıyor |
| Kapsam: tasarım kapsamının gereksinim analizi belgesinde tam belirtilmesi gerekir | Orta | Orta | Kapsam net tanımlandı; sonradan eklenen işlevler kapsam dışıdır, test edilmesi istenirse gecikme olur |

Takvim riski en yüksek risk olarak değerlendirildi. Test, yazılım geliştirme sürecinin son adımı olduğu için tasarım ve geliştirmedeki bütün gecikmeler testin süresinin üzerine biner. Müşteriyle çalışırken teslim tarihi neredeyse hiç değişmediği için bütün yük ve stres testin üzerinde toplanabilir.

Personel riskinde kilit kişilerin projeyle ilgili önemli bilgilere sahip olduğu vurgulandı. Bu kişinin ayrılması gerekmez; hastalanıp çalışamaz hale gelmesi de proje için büyük bir risktir. Bu yüzden her kilit kişinin bir yedeği olmalı, bilgi çalışanlar arasında paylaşılmalıdır. Sunumda bu risk, derste de konuşulan bir risk olarak hatırlatıldı.

Kritik hataların geç bulunması riski, iki fazlı test düzeniyle birlikte açıklandı. Birinci fazda bulunan hataların raporlanıp düzeltilmesi ve ikinci faza gelinmeden regresyonlarının yapılmış olması gerekir. İkinci fazda çok az kritik hata çıkması, mümkünse hiç çıkmaması hedeflenir. İkinci fazın sonuna doğru bir kritik hata bulunursa düzeltme, regresyon ve etkilenen alanların yeniden testi bütün test planını etkiler.

Doğal afet riski ilk bakışta garip görünse de sunucunun sel ya da deprem gibi bir afetten etkilenmesi projenin sürmesini engelleyebilir. Kapsam riski ise yazılım süreç yönetimiyle ilgilidir: test planı onaylandığında test ekibi koşullarını herkese sunmuş olur; plana girmeyen bir işlevin test edilmesi istenirse bu gecikmeye yol açar.

### 2.3 Takım, Ortam ve Test Kriterleri

Takım kadrosunda en üstte proje müdürü, ona bağlı test koordinatörü ve geliştirme lideri, bunlara bağlı da test uzmanları ve geliştiriciler vardı. Test ortamı olarak her test kullanıcısı için Internet Explorer 8, 9, 10, Firefox 27.0 ve Google Chrome 32.0 ve sonraki sürümleri olan bir Windows ortamı tanımlandı.

Test kriterleri dört gruptur: başlatma, tamamlama, durdurma ve tekrar başlatma (ekrandan, 00:15:00).

- Test başlatma kriterleri:
  - İlgili test seviyesine ait test durumları ve senaryoları yazılmış olmalıdır.
  - Yazılan test durumları ve senaryolarıyla ihtiyaçlar arasında izlenebilirlik kurulmuş olmalıdır.
  - Bir önceki test aşamasında testler başarıyla sona erdirilmiş olmalıdır. Örneğin fonksiyonel entegrasyon testinin birinci fazı bitmeden ikinci faza başlanamaz.
- Test tamamlama kriterleri:
  - Planlanmış birim, entegrasyon ve kabul test faaliyetleri gerçekleştirilmiş olmalıdır.
  - Tüm test seviyelerindeki test durumları ve senaryolarının tamamı başarıyla sonuçlanmış olmalıdır.
  - Tüm testlerde ortaya çıkan 1., 2. ve 3. derece hataların tamamı çözülmüş olmalıdır.
  - Tüm seviyelerdeki test faaliyetlerinin tamamı raporlanmış olmalıdır.
- Testlerin durdurulma kriterleri:
  - Birinci derece bir hata bulunursa test durdurulur, hata düzeltilmeden devam edilmez.
  - İkinci derece hata oranı çok yüksekse (sunumda %80'in üstü dendi), yani sistem işlevsel olarak test edilemez durumdaysa testler durdurulur.
  - Proje yöneticisi ve test yöneticisi istediği durumda testleri durdurma yetkisine sahiptir.
- Tekrar başlatma kriterleri:
  - Bulunan birinci ve ikinci derece hatalar düzeltildikten sonra teste kalınan yerden devam edilir.
  - Proje yöneticisi ya da test yöneticisi tarafından durdurulan testler ancak onların kararıyla devam ettirilir.

### 2.4 Raporlama, Hata Düzeyleri ve Hata Süreci

Raporlama günlük ve haftalık raporlarla yapılır. Raporlarda test hazırlık ve yürütme durumu (tamamlandı, Pass, Fail), açık ve kapanan hata kayıtları yer alır.

Proje büyük kapsamlı olmadığı için üç hata düzeyi belirlendi: kritik, yüksek ve minor. Daha büyük projelerde daha fazla düzey (ör. öneri ya da daha düşük düzeyler) eklenebilir.

Hata süreci şu adımlardan oluşur:

```text
1. Test uzmanı hatayı raporlar.
2. Test koordinatörü hatayı kontrol eder; onaylar ya da test uzmanına geri gönderir.
3. Geliştirme lideri hatayı ilgili geliştiriciye atar.
4. Geliştirici hatayı düzeltir.
5. Test uzmanı hatayı tekrar test eder ve regresyon testi yapar.
6. Test başarılıysa hata kapanır ve süreç biter.
   Başarılı değilse hata yeniden geliştirme liderine gönderilir ve 3. adıma dönülür.
```

### 2.5 Fonksiyonel Entegrasyon Testi ve Test Case Belgesi

Grup bütün test case'leri tek tek anlatmak yerine, sisteme ürün ekleme modülünün test case'lerini örnek olarak gösterdi. Test case tablosunun sütunları şunlardı (ekrandan, 00:20:00): use case numarası, use case, test case numarası, test case adı, amaç, test tipi, test fazı, ön koşullar, test adımları, beklenen sonuçlar, sonuç, ekstra not, kanıtlar, oluşturulma tarihi ve test tarihi.

Ürün ekleme senaryolarının ön koşulu kullanıcının admin rolüyle sisteme giriş yapmış olmasıydı. Test adımları şöyleydi: "Ürün Adı" metin kutusuna yeni ürünün adını yazmak, "Ürün kategorisi" listesinden kategoriyi seçmek, "Birim Fiyatı", "Birim Başına Miktar" ve "Stok Miktarı" alanlarını doldurmak. Beklenen sonuçlar senaryoya göre değişiyordu: başarılı eklemede "Ürün eklendi!", zaten kayıtlı bir ürün eklenmeye çalışılınca "Ürün sistemde kayıtlıdır!", başarısız eklemede "kaydı başarısız!" türünden bir uyarı. Bu üç senaryo Pass oldu.

Dördüncü senaryo standart kullanıcının erişmemesi gereken birimlere erişimini denetliyordu: standart kullanıcı sisteme girince ana sayfada ürün silme ve ekleme birimlerini görmemeliydi. Bu senaryo Fail oldu. Ekstra not sütununa, standart kullanıcının erişim yetkisi olmayan birimlere erişebildiği ve bunun SRS'te belirtilen kurallara aykırı olduğu yazıldı.

Sunumda belgenin bazı alanlarının önemi vurgulandı:

- Ön koşullar, test adımları ve beklenen sonuç senaryonun çekirdeğidir.
- Test fazı yazılmalıdır (ör. "Fonksiyonel Entegrasyon Faz 1"), yoksa karışıklık olur.
- Testin otomasyon mu manuel mi olduğu, oluşturulma ve yapılma tarihleri belirtilir.
- Fail olan senaryoya mutlaka açıklama (remark) eklenir. Raporu sonradan açan kişinin ya da test ekibinin neyin neden başarısız olduğunu kolayca anlayabilmesi gerekir; çok sayıda test case olan projelerde bu daha da önemlidir.
- Mümkünse ekran görüntüsü ya da GIF ile kanıt eklenir.

Fonksiyonel entegrasyon testi iki fazda koşuldu. Birinci fazda 1 kritik, 2 yüksek ve 4 minor hata bulunup raporlandı. İkinci faza geçmeden bu hataların düzeltmesi ve regresyonu yapıldı. Temiz bir başlangıçla geçilen ikinci fazda yalnız 3 minor hata bulundu.

### 2.6 Birim Testi ve Kullanıcı Kabul Testi

Proje React.js ile geliştirilmiş bir frontend projesiydi ve Visual Studio Code ortamında yazılmıştı. Birim testleri için Jest ve Enzyme kullanıldı. Jest, Facebook tarafından geliştirilmiş bir JavaScript test framework'üdür; React, Angular, Vue gibi frontend kütüphaneleriyle çalışır, hem test koşucu (test runner) hem assertion kütüphanesi özelliklerini sunar. Enzyme, Airbnb tarafından yalnız React için geliştirilmiş bir test yardımcı kütüphanesidir; mount gibi özellikleriyle bileşenleri daha izole biçimde test etmeyi sağlar. Enzyme tek başına testi koşamaz, bir test koşucuya ihtiyaç duyar; bu yüzden Jest ile birlikte kullanılır.

Ürün ekleme, kullanıcı ekleme, sepete ürün ekleme gibi her özellik bağımsız bir modül olarak kodlandı ve her bileşenin hemen altında birim testi çalıştırıldı. Sonuçta 9 farklı modül için 9 test dosyası ve 31 test case koşuldu, hepsi başarıyla geçti.

Birim testlerinin ve fonksiyonel entegrasyon testlerinin sonunda kullanıcı kabul testi yapıldı. Kullanıcı kabul testi arayüzün test edilmesine ve kullanıcının hiçbir hatayla karşılaşmamasına odaklandığı ve entegrasyon testinden çözülmemiş hata kalmadığı için 29 case'in hepsi başarılı oldu.

> **Hocanın vurgusu:** Hoca, bu grubun test planı ve fonksiyonel test belgelerini kendi verdiği formatın dışında ama profesyonel hayata uygun bir formatta hazırladığını söyledi. Gerçek hayattaki bir formatı diğer öğrenciler de görsün diye sunumu süre aşılmasına rağmen kesmedi.

## 3. Bir Psikolojik Envanter Uygulamasının Testi

İkinci sunumda bir öğrenci, kişisel olarak geliştirdiği ve geliştirmesi süren bir web uygulamasının test raporunu anlattı. SRS'te tanımlanmış ama henüz gerçeklenmemiş kısımlar (ör. giriş işlemleri, elle doldurulan optik formun okunması) olduğu için test kapsamı yalnız gerçeklenmiş kısımlarla sınırlandı. Süreç dört adımdı: test edilecek yapıların belirlenmesi, test senaryolarının oluşturulması, testlerin koşulması ve sonuçların kaydedilmesi. Birim, entegrasyon ve son kullanıcı testleri yapıldı.

### 3.1 Uygulamanın Konusu

Uygulama, MMPI adlı psikolojik envanteri dijital ortama taşımayı amaçlıyordu. Bu envanterde 566 soru vardır. Yanıtlara göre, kitapçıkta belirtilen kurallar çerçevesinde K düzeltmeli değerler, ham değerler (raw values) ve T değerleri gibi ölçek değerleri üretilir. Bu değerler tek başına bir şey ifade etmez; L, F, K gibi ölçeklerin ne anlama geldiği yine kitapçıktaki yönergelerle yorumlanır.

### 3.2 Birim Testi

Birim testinde 566 soruya belirli yanıtlar verilip ölçek değerlerinin ne olması gerektiği kontrol edildi. Örneğin bir tablodaki bir ölçek değerinin verilen girdiye göre 90 olması gerekiyordu; test, JSON verisini okuyup değerlendirme fonksiyonunu çağırıyor, dönen tablonun ilgili indeksindeki değerin 90 olup olmadığını assert ile kontrol ediyordu. Benzer şekilde cinsiyet girdisi (0/1) ve boş bırakılan soru sayısı da kontrol edildi: iki soru boş gönderildiyse boş soru sayısının 2 çıkması beklendi.

Her değerin tek tek test edilmesinin sebebi, her sorunun ölçek değerlerine katkısının farklı olması ve değerlerin kitapçıktan elle bakılarak hesaplanmasıdır. Amaç, hesaplamada bir yerde yanlışlık olup olmadığını görmektir.

Uygulama Python ile yazılmıştı ve testler Django'nun unit test altyapısıyla yazıldı. Django'nun test komutu çalıştırılınca test klasöründeki bütün testler koşulur; bu örnekte 6 test koşuldu ve hepsi OK döndü. Bir test başarısız olursa hangi değerin hangi beklenen değere karşı tutmadığı raporlanır.

### 3.3 Entegrasyon Testi

Uygulamada bir web arayüzü ve arkada bir web servisi vardı. Web servisi kullanıcıdan gelen JSON'ı alıp ilgili fonksiyonlara gönderir ve sonucu yanıt olarak döndürür. Öğrenci farkı şöyle özetledi: birim testinde fonksiyonların doğru çalışıp çalışmadığı, entegrasyon testinde ise web servisinin kullanıcıdan gelen veriyi doğru işleyip fonksiyonlara doğru iletip iletmediği ve kullanıcıya doğru yanıtı döndürüp döndürmediği test edilir.

Ekrandaki entegrasyon testi kodu şöyleydi (ekrandan, 00:35:00; uzun JSON satırı kısaltıldı):

```python
def test_API_questionAnswersPOST(self):
    print("test_API_questionAnswersPOST_1")
    questionAnswersFromUser = "{\"question\":[{\"no\":1,\"response\":1},{\"no\":2,\"response\":1}, ..."
    request = self.factory.post('mmpi-api/', questionAnswersFromUser, content_type='application/json')

    response = mmpi_api(request)
    self.assertEqual(response.status_code, 200)
    self.assertContains(response, u"metrics")
    self.assertContains(response, u"\"L\":\"48.4\"")
    self.assertContains(response, u"\"Hs5K\":\"79.0\"")
    self.assertContains(response, u"\"Pa\":\"77.0\"")
    self.assertContains(response, u"\"Sc_1K\":\"86.7\"")
    self.assertContains(response, u"\"QuestionMark\":\"41\"")
    self.assertContains(response, u"KTable")
    self.assertContains(response, u"\"F\":\"0\"")
    self.assertContains(response, u"\"Pt_1K\":\"42\"")
    self.assertContains(response, u"\"sex\":\"1\"")
    self.assertContains(response, u"\"emptyQuestionsCount\":\"2\"")
```

Test, kullanıcının soru-yanıt verisini POST isteğiyle gönderir, yanıtın durum kodunun 200 olduğunu ve yanıtta "metrics" başlığı ile beklenen ölçek değerlerinin bulunduğunu kontrol eder. Farklı yanıtlarla ikinci bir test de yazıldı; iki test de başarılı oldu.

<!-- BELİRSİZ: Slaytın solundaki "Beklenen Değerler" listesinde L: 90.0 yazıyor, koddaki assert ise L için 48.4 bekliyor; anlatımda da "L değeri 48.4 bekliyorum" deniyor. Listedeki 90.0 büyük olasılıkla birim testindeki başka bir değerle karışmış. -->

### 3.4 Son Kullanıcı Testi

Son adımda arayüz test edildi. Site açılınca sorular aşağı doğru açılan (akordeon) bir yapıda listelenir; sorular koda gömülü değildir, sunucudan JSON olarak çekilip ayrıştırılır. Kullanıcı soruları yanıtlayıp "Complete Quiz" deyince form, entegrasyon testindeki JSON verisini web servisine gönderir ve sonuç tablosu ile grafikler görüntülenir. Son kullanıcı testinde bu tablo değerlerinin ve grafiklerin doğru çıkıp çıkmadığı kontrol edildi.

## 4. Web Uygulaması Testinin Türleri

Üçüncü sunum somut bir uygulamanın testi yerine web uygulaması testinin genel türlerini İngilizce slaytlarla anlattı. Altyazının bu bölümü büyük ölçüde bozuk olduğu için içerik ağırlıkla karelerden alındı.

### 4.1 Neden Web Uygulaması Testi?

Slayttaki gerekçeler şunlardı (ekrandan, 00:40:00):

- Web uygulamaları internete erişebilen her cihazda (masaüstü, tablet, cep telefonu) çalışır. Güncelleme indirip kurmak gerekmez; uygulama güncellenince yeni özellikler hemen kullanıcıya ulaşır.
- Her gün çok sayıda web uygulaması geliştirilir ve yazılan her kod satırıyla hata olasılığı doğar.
- IBM Systems Sciences Institute'a atfedilen alıntıya göre, ürün yayınlandıktan sonra bulunan bir hatanın düzeltme maliyeti tasarım sırasında bulunan bir hatanınkinden 4-5 kat fazladır; bakım evresinde belirlenen hatada bu oran 100 kata kadar çıkar.
- Hataları olabildiğince erken bulmak ve uygulamayı yayından önce kapsamlı biçimde test etmek web uygulaması testinin amacıdır. Web uygulaması testi, uygulamanın tam işlevsel olduğunu, sorunsuz ve güvenli çalıştığını garanti etmeye çalışır.

> **Ek bilgi (derste anlatılmadı):** Bu "IBM Systems Sciences Institute" maliyet oranları yazılım mühendisliği kaynaklarında çok sık alıntılanır, ancak orijinal çalışmanın kaynağı büyük olasılıkla belirsizdir ve bazı yazarlar sayıların doğrulanamadığını belirtmiştir. Yine de hatanın ne kadar geç bulunursa o kadar pahalıya düzeltildiği fikri, derste de işlenen V model ve erken doğrulama yaklaşımlarıyla uyumludur.

### 4.2 Fonksiyonellik Testi

Fonksiyonellik testi web sitesinin bütün özelliklerini test etmek için kullanılır; bir sistemin ya da bileşenin belirtilmiş fonksiyonel gereksinimlere uygunluğunu değerlendirir (ekrandan, 00:45:00). Bir kara kutu testidir: web uygulamasının iç kod gerçeklemesi bilinmeden girdilere ve çıktılara odaklanılır. Amacı web sitesinin geliştirme belgelerinde belirtilen özellikleri karşıladığını doğrulamaktır.

Slayttaki örnekler:

- Sayısal bir alana negatif sayı girilmesine izin veriliyor mu, test etmek.
- Kullanıcı yanlış değer girince açılır uyarı mesajı çıkıyor mu, test etmek.
- Butonların işlevselliğini test etmek.

Bu sırada hoca, öğrenciden anlattığı test türlerine kendi uygulamasından örnek vermesini istedi; öğrenci uygulama materyaline şu an erişimi olmadığı için genel anlatımla devam ettiğini söyledi.

### 4.3 Kullanılabilirlik ve Uyumluluk Testi

Sunumda kullanılabilirlik testinin ürünün bulunabilir, kabul edilebilir, kullanılabilir ve istenir olmasını hedeflediği, uyumluluk testinin ise aracın farklı cihazlarda doğru görüntülenmesini sağladığı söylendi.

<!-- BELİRSİZ: Bu bölümün altyazısı büyük ölçüde bozuk; kullanılabilirlik ve uyumluluk testinin slayt metinleri karelerde görünmüyor. Bir slaytta otomasyon araçları olarak Selenium ve büyük olasılıkla QTP'nin ("KUETS" diye yazılmış) adı geçiyor. -->

### 4.4 Performans Testi

Performans testi yazılım uygulamasının hızını, kararlılığını, güvenilirliğini, ölçeklenebilirliğini ve kaynak kullanımını sınar. Slayttaki dört teknik şunlardır (ekrandan, 00:50:00):

1. **Yük testi (Load Testing):** Performans testinin en basit biçimidir. Web sitesinin belirli beklenen yükler altında nasıl davrandığını test eder. Bu yük, belirli bir süre boyunca belirli bir görev üzerinde eşzamanlı çalışan beklenen kullanıcı sayısı olabilir.
2. **Stres testi (Stress Testing):** Sistemin üst sınırını kontrol eder; mevcut yük beklenen en yüksek yükü aşarsa web sitesinin nasıl davranacağını gösterir.
3. **Dayanıklılık testi (Soak / Endurance Testing):** Uzun süre sürekli yük uygulandığında web sitesinin nasıl davrandığını gözlemler. Yük uygulanmadan önce ve sonra iş hacmini (throughput) ve yanıt süresini de izler.
4. **Ani yük testi (Spike Testing):** Web sitesindeki yük çok hızlı arttığında ya da azaldığında davranışı kontrol eder; ani değişimlerde performansı, yanıt süresini ve iş hacmini inceler.

### 4.5 Veritabanı ve Arayüz Testi

Veritabanı testi de fonksiyonel testin bir parçası olarak anlatıldı; verinin erişilebilirliği gibi konuları sınar. Arayüz testi, iki farklı bileşenin (ör. web sunucusu ile uygulama sunucusu) birbiriyle doğru iletişim kurup kurmadığını doğrular. Sunumun sonunda hoca yine bu testlerden birinin uygulamaya uygulanıp uygulanmadığını sordu.

<!-- BELİRSİZ: Arayüz testinin tanımı ve listedeki son test türü altyazıda bozuk ("last testi"); kare yok. -->

## 5. Bir Randevu Sisteminin Test Planı

Dördüncü sunumda bir öğrenci, uygulamaya dönük ve daha pratik bir formatta hazırladığı test planını anlattı. Test edilen yazılım, doktor muayeneleri ya da herhangi bir randevu süreci için kullanılabilecek bir çevrimiçi randevu sistemiydi; örnek test case'ler için bir psikoterapi merkezi senaryosu seçildi.

### 5.1 Hedef Kitle, Kapsam ve Test Edilecek Modüller

Belgenin hedef kitlesi yazılım geliştiriciler, proje yöneticileri, test geliştiriciler, test uzmanları ve kullanıcılardı. Belge yalnız ilk test döngüsünü kapsar; ürünün yaşam döngüsü boyunca düzgün çalışması için testlerin belirli aralıklarla tekrarlanması gerekir, bu da hata ve kusurların (bug, fault) önüne geçer.

Öğrenci bu tür bir belgenin uygulamadaki işlevini de açıkladı: geliştirme ekibi (analist ve geliştiriciler) ön testleri yapar ve bu belgeyi test uzmanlarına verir; test uzmanları belgeyi temel alarak kendi testlerini, örneğin regresyon testini ya da yeni eklenen bir işlevin fonksiyonel testini yürütür. Referans materyali SRS belgesiydi.

İki önemli modül test edildi (ekrandan, 00:55:00):

- **Entity modülleri:** Beyaz kutu olarak, unit test ile test edildi. Bileşenler: Appointment, Banner, Client, Company, Expert (doktor), Features, Plans, Works.
- **Kullanıcı arayüzü:** Tarayıcı üzerinden kara kutu olarak, tamamen işlevselliğe yönelik test edildi.

### 5.2 Geçti/Kaldı, Durdurma ve Tekrar Başlama Kriterleri

Geçti/kaldı kriterleri şunlardı:

- Unit testlerin hepsi koşmuş ve başarılı olmalıdır.
- Minor hatalar, örneğin bir değerin başka bir değerden dolayı çok küçük bir hata vermesi, akışı bozmuyorsa kabul edilebilir.
- Sistem çökmesine (system failure) yol açan hiçbir hata kabul edilmez.
- Beşten fazla unit test başarısız olursa o testlerin bulunduğu modül yeniden gözden geçirilmelidir. Burada önce test kodu gözden geçirilir, gerekirse ana koda dönülür.
- Arayüz, minor hatalar dikkate alınarak SRS'te belirtildiği şekilde çalışmalıdır.

Testler gerektiğinde durdurulabilir. Durdurma nedenleri genelde şunlardır: testin yapıldığı sunucuda ya da test yapan kişinin bilgisayarında donanım sorunları, üst yönetimden gelen bir istek nedeniyle kodda acil değişiklik yapılması, test ortamına eksik ya da hatalı deployment, kurum içi prosedür sorunları. Sorun giderilince tekrar başlama kriteri sağlanmış olur. Örneğin bir hata sistem çökmesine yol açarsa test durdurulur, hata düzeltilir ve teste devam edilir.

### 5.3 Testler ve Test Planı

Entity modülündeki her entity için ayrı testler yazıldı. Örneğin Company testlerinde özellikle get/set metotları test edildi; veri doğru alınıp verilebiliyor mu diye bakıldı. Arayüzde önemli ekranlar test edildi: giriş sayfası, uzman (doktor) ekleme ve listeleme, danışan listesi ve ekleme, randevu işlemleri, takvim.

Test planındaki kurallar:

- Unit testler her yazılım iterasyonunda koşulur.
- Büyük bir sürümde bütün sistem üzerinde regresyon testi yapılır; küçük bir sürümde yalnız modül bazında test yapılır. Bu test planı regresyon testi olarak da kullanılabilir.
- Arayüz testleri, arayüzde ya da akıştaki öğelerde büyük bir değişiklik olmadıkça yapılmaz, çünkü arayüzün kendiliğinden bozulması pek olası değildir.

### 5.4 Ön Test Sonuçları

Ön test sonuçları test uzmanlarına "çalışması gereken şekil budur" bilgisini vermek için paylaşılır. Testler Visual Studio'da ayrı bir test projesi olarak yazıldı ve toplam 83 test vardı. İlk denemede yalnız bir test çalıştırıldı (82'si çalıştırılmadı). İkinci çalıştırmada 78 test çalıştı, 5 test çalışmadı; süre 586 milisaniyeydi. Sorun bir paketten kaynaklanıyordu: geliştirme ortamı test projesini hata veren kısmı atlayarak kısmi (partial) derliyor, kullanıcı derlemenin tamamlandığını sanıyor ama 5 test aslında çalıştırılmıyordu. Sorun giderildikten sonra 83 testin hepsi geçti, süre 780 milisaniye oldu.

Doğrulama: ilk denemede $1 + 82 = 83$, ikinci denemede $78 + 5 = 83$ test vardır; sayılar tutarlıdır.

Arayüz tarafında uzman listesi ve ekleme, randevu ekleme, görüntüleme, renklerin çalışması, randevu güncelleme ve ekleme ekranları kontrol edildi.

### 5.5 Ortam Gereksinimleri, Riskler ve Sorumluluklar

Bu bölüm, öğrencinin belgede en çok başvurulan kısım olarak tanımladığı yerdi; testlerde ya da sonrasında bir sorun çıkınca dönülüp bakılan bölümdür. Slayttaki maddeler (ekrandan, 01:00:00):

- Test verisi fonksiyonellik testleri (arayüz testleri) için manuel yaratılacaktır.
- Unit testler için veri otomatik üretim (auto generation) metotlarıyla üretilebilir; üretilen verinin kuralları karşılaması gerekir.
- Testler için özel bir donanım gereksinimi yoktur.
- Framework uyumluluğu test için bir risktir. Kod 2.0 framework'ünde yazılmış olup 3.5'e kadar destek verir, fakat 4.0 ve üstü uyumsuzluk sorunları yaratır. Testlerin çalışabilmesi için unit testlerde bazı paketlerin değiştirilmesi gerekebilir; destek geliştiricilerin sorumluluğundadır.

Öğrenci framework riskini somutlaştırdı: geliştirme ortamının yeni sürümü test projesini varsayılan olarak 4.6 sürümüyle oluşturur. Ana proje 2.0'da kalırken test projesi 4.6'da olursa testler çalışmayabilir; test projesini 2.0'a döndürmek de başka uyumsuzluklar doğurur.

Diğer maddeler:

- Veritabanıyla ilgili bir risk öngörülmez; kolay test için SQLite kullanılabilir, belirli bir veritabanı bağımlılığı yoktur.
- Test uzmanları kendi test belgelerini yaratır; bu belgeyi beklenen sonuçlar olarak kullanabilirler.
- Bazı özellikler değişime açıktır.
- Test production (canlı) ortamında yapılmamalı, test ortamında yapılmalıdır. Öğrenci bunu özellikle vurguladı, çünkü zaman zaman "canlıya geçsin, sonra bakarız" yaklaşımıyla karşılaşılabiliyor.
- Kritik durumlar ve başarısızlıklar için test uzmanları önce yöneticilerini bilgilendirmeli, sonra modülü yazan geliştiriciyle konuşmalıdır.
- Planlama ve takvim ihtiyaca göre güncellenebilir.

## 6. Axios Kütüphanesinin Jest ile Testi

Beşinci sunumda bir öğrenci, test planını ve test raporunu IEEE formatında hazırladığını, bu yüzden sunumda yalnız kullandığı teknolojileri anlatacağını söyledi. Hoca bunun üzerine, raporlar zaten bulunduğu için sunumlarda araçların nasıl kullanıldığının anlatılmasını istediğini belirtti.

> **Hocanın vurgusu:** Sunumda raporu tekrarlamak yerine test araçlarının nasıl kullanıldığını göstermek gerekir.

### 6.1 Test Ortamı ve Test Edilen Kütüphane

Testler öğrencinin kendi bilgisayarında, Node.js 14.15.4 ve Jest 26.6 ile yapıldı (ekrandan, 01:05:00). Test edilen kütüphane Axios'tur: hem tarayıcıdan hem Node.js üzerinden HTTP isteği atmayı sağlayan bir kütüphane. Kütüphaneyi test etmek için istek atılacak bir API gerekiyordu; bunun için internette bulunan bir mock (sahte) API kullanıldı. Bu API'nin desteklediği yollar (route) üzerinden istekler atıldı.

### 6.2 Jest ve Eşleştiricileri

Jest çok popüler, basitlik üzerine kurulu ve birçok framework'ü destekleyen bir test kütüphanesidir. Test sonuçlarını kontrol etmek için birçok eşleştirici (matcher) sunar. Sunumda anlatılanlar:

- `toBe`: İki değerin denk olup olmadığını kontrol eder.
- `toBeCloseTo`: İki değerin farkının beklenen aralıkta olup olmadığını (yaklaşık eşitliği) kontrol eder.
- `toEqual`: `toBe`'ye benzer ama nesnelerin içeriğini de karşılaştırır.
- `toStrictEqual`: `toEqual`'dan farklı olarak `undefined` değerli özelliklere de bakar. `toEqual`, bir nesnede olmayan bir özellik ile diğerinde `undefined` olan özelliği eşit kabul edebilir; `toStrictEqual` kabul etmez.
- `toHaveProperty`: Verilen nesnede bir özelliğin (alt başlığın), hatta iç içe bir özelliğin bulunup bulunmadığını kontrol eder.
- `toMatchSnapshot`: Arayüz bileşenleri için kullanılır; bir bileşenin düzgün render edilip edilmediğini önceki anlık görüntüyle karşılaştırarak kontrol eder.
- `toThrow`: Verilen fonksiyonun hata fırlatıp fırlatmadığını ve hata mesajının beklenen mesajla aynı olup olmadığını kontrol eder.

> **Ders sonrası not:** Sunumda `toBe`'nin çift eşittire (`==`), `toEqual`'ın üçlü eşittire (`===`) karşılık geldiği söylendi. Doğrusu: `toBe`, `Object.is` ile karşılaştırır, yani `===`'e yakın bir katı özdeşlik denetimidir (iki nesne içerikleri aynı olsa bile farklı nesnelerse `toBe` başarısız olur). `toEqual` ise nesneleri özyinelemeli olarak içerik bakımından karşılaştırır (derin eşitlik).

### 6.3 Kurulum ve Testlerin Koşulması

Kurulum basittir: paket projeye yarn ya da npm ile eklenir, `package.json` içindeki betikler (scripts) bölümüne bir test betiği eklenip karşısına `jest` yazılır. Ardından `npm test` komutu testleri çalıştırır.

```json
"scripts": {
  "test": "jest"
}
```

<!-- BELİRSİZ: package.json örneği altyazıdaki anlatımdan kuruldu; slaytın karesi yok. -->

Axios bir HTTP istek kütüphanesi olduğu için temel işlemler test edildi: GET, POST, PUT ve DELETE. Her istek için dönecek değer mock API'nin belgesinden alındı ve dönen değerin bununla eşit olup olmadığı test edildi. `npm test` çalıştırıldığında bütün testlerin geçtiği görüldü.

## 7. Bir İş/Staj Portalının Testi

Altıncı sunumda bir öğrenci, aslında iki kişilik bir grupla hazırlanan projeyi tek başına sundu. Test edilen yazılım, bir üniversitenin bölüm öğrencileri için daha önce geliştirilmiş bir iş/staj portalıydı. Portal, panolarda asılan iş ilanlarının yerini alacak bir web uygulamasıydı: kurum ve kuruluşlar üye olup ilan yayımlar, öğrenciler aradıkları özelliklere uyan iş ve staj olanaklarını bulup başvurur.

### 7.1 Modüller ve Ortam

Portal dört modülden oluşuyordu: yönetici, işveren, öğrenci ve memur. Her modül için ayrı test case'ler oluşturulup test edildi.

Yazılım Windows 8 üzerinde .NET ile geliştirilmiş, veritabanı olarak MS SQL kullanılmış, Visual Studio 2013 ile yazılmıştı. Uygulama HTTP üzerinde çalışır ve Google Chrome, Firefox, Internet Explorer tarayıcılarında test edildi. Test araçları MS Test, Selenium ve Chrome için Selenium IDE eklentisiydi.

### 7.2 Test Planı ve Test Yaklaşımı

Test planı birim testiyle başladı; ardından yazılım sistem testi, kabul testleri, beta testleri ve kullanıma alma testleri yapıldı. Belgeler zinciri şöyleydi: yazılım gereksinimleri belgesi, test tanımlama belgesi ve test sonuçlarının raporlandığı bir belge.

Test yaklaşımı (ekrandan, 01:15:00):

- Test durumları proje test ekibi tarafından belirlenip belgelendirildi.
- Test durumları belirlenirken gereksinim tabanlı test yaklaşımı (birim test) ve kara kutu test yöntemi kullanıldı.
- Yazılım Gereksinim Özellikleri belgesinde verilen işlevsel ve görsel ihtiyaçların doğrulanması göz önünde tutuldu.
- Kullanıcı arayüzü Selenium ile test edildi.

Test durumları oluştururken eşdeğer girdi kullanan ve farklı davranışla sonuçlanan durumlar ayrı test durumları olarak yazılmaya çalışıldı; bu, derste görülen denklik sınıflarına ayırma fikrine karşılık gelir. Yazılımın görevini yerine getirmesine yönelik beklenen veri girişleri için pozitif test durumları, kabul edilmeyen veri girişlerinde yazılımın nasıl davranması gerektiğine yönelik negatif test durumları yazıldı.

### 7.3 Hata Dereceleri ve Risk Yönetimi

Hatalar üç dereceye ayrıldı:

- **Birinci derece:** Portalın genel çalışmasını doğrudan etkileyen hatalar.
- **İkinci derece:** Genel çalışmayı doğrudan etkilemeyen ama işlevsel yönden bazı kısımların çalışmasını engelleyen hatalar.
- **Üçüncü derece:** Çalışmayı etkilemeyen, görsel olarak ortaya çıkan hatalar.

Risk takibi için bir risk yönetim planı geliştirildi. Plan dahilinde her risk belirlenip olası durumlar ve alternatif çözümler değerlendirildi. Bir risk izleme tablosunda her riskin ne derece riskli olduğu ve alternatif çözümü yazıldı; her riske bir risk sorumlusu atandı.

### 7.4 Test Case'ler, Sonuçlar ve Selenium IDE

Test case'lerde test adımları, test girdileri ve beklenen çıktılar adım adım gösterildi. Test sonuçları tablolar halinde verildi; başarısız testlerin açıklamasına hatanın bilgisi ve derecesi yazıldı (örneğin ekrandaki bir resim bozukluğundan kaynaklanan görsel bir hata). Test değerlendirme tablosunda toplam test sayısı 7'ydi ve testlerin hepsi gerçekleştirildi; hata bulunan testlerin sayısı ayrıca gösterildi.

Öğrenci Selenium IDE'nin kullanımını canlı göstermeye çalıştı: eklentide yeni proje oluşturulur, bir isim ve test edilecek adres verilir, ardından senaryo kaydedilip oynatılır (ekrandan, 01:20:00). Demo sırasında test başlatılamadı. Öğrenci normalde Selenium IDE'nin bir simülasyon gibi adımları otomatik olarak sırayla gerçekleştirdiğini ve sonunda testin geçip geçmediğini, hangi adımların yapıldığını gösteren loglar ürettiğini anlattı.

## 8. Bir Emlak Fiyat Tahmin Uygulamasının Testi

Yedinci sunumda bir öğrenci, makine öğrenmesiyle çalışan bir emlak fiyat tahmin uygulamasını test etti. Öğrencinin amacı, makine öğrenmesi uygulamalarında testin nasıl yapıldığını görmekti. Uygulama Python ile (Spyder ortamında) yazılmıştı. Programcı önceden örnek bir veri setini uygulamaya verir; uygulama bu veri setini işleyip kullanıcının verdiği parametrelere göre fiyat tahmini yapar. Parametreler metrekare, oda sayısı, banyo sayısı, dairenin bulunduğu kat ve bina yaşıdır. Uygulama doğrusal regresyonla tahmin yapar.

### 8.1 Kullanılan Test Türleri

İki test türü uygulandı:

- **Birim testi:** Bir yazılımın en küçük test edilebilir bölümlerinin tek tek ve bağımsız olarak doğru çalışıp çalışmadığının incelendiği testtir.
- **Beta testi:** Potansiyel kullanıcıların ürünün beta sürümünü test edip buldukları hataları geliştiricilere bildirdiği test sürecidir.

Birim testleri, girdiler karşılığında fiyat tahmini yapan fonksiyon üzerinde uygulandı (4 test). Beta testinde programın girdileri yorumlama biçimi test edildi (3 test).

### 8.2 Test Senaryosu Tablosu

Makine öğrenmesi uygulamasında çıktının ne olacağı kesin olarak bilinemez. Bu yüzden öğrenci veri setinin alındığı sitedeki ilanları inceleyip beklenen çıktıyı bir fiyat aralığı olarak belirledi. Test senaryosu tablosu şöyleydi (ekrandan, 01:25:00):

| Grup | No | Test verisi (m², oda, bina yaşı, kat, banyo) | Beklenen çıktı | Gerçekleşen çıktı | Durum |
|---|---|---|---|---|---|
| 1 (Unit) | 1 | 100, 3+1, 1, 5, 1 | 300.000-500.000 | 496.812 TL | Başarılı |
| 1 (Unit) | 2 | 100, 3+1, 4, 5, 1 | 300.000-470.000 | 550.150 TL | Başarısız |
| 1 (Unit) | 3 | 50, 1+1, 1, 5, 1 | 160.000-250.000 | 80.091 TL | Başarısız |
| 1 (Unit) | 4 | 250, 7+1, 10, 5, 3 | 900.000-1.100.000 | 1.927.523 TL | Başarısız |
| 2 (Beta) | 1 | 100, 3, 1, 5, 1 | "Hatalı giriş! Yeniden deneyiniz." | Program çıktı vermedi, çalışmayı durdurdu | Başarısız |
| 2 (Beta) | 2 | a, b, c, d, e | "Hatalı giriş! Yeniden deneyiniz." | Program çıktı vermedi, çalışmayı durdurdu | Başarısız |
| 2 (Beta) | 3 | 100, 3+1, 1, 5, 1 | Program doğru çalışmalı | Program olması gerektiği gibi çalıştı | Başarılı |

Gerçekleşen değerlerin beklenen aralıklarla karşılaştırılması (python ile kontrol edildi): $300.000 \le 496.812 \le 500.000$ olduğu için 1. test geçer; $550.150 > 470.000$, $80.091 < 160.000$ ve $1.927.523 > 1.100.000$ olduğu için 2., 3. ve 4. testler aralık dışında kalır.

Her testin gerekçesi şöyle anlatıldı:

- **Test 1:** Aralık çok daraltılamadı, çünkü emlak fiyatı yalnız bu beş parametreye değil şehir ve konum gibi birçok başka etkene bağlıdır. Gerçekleşen çıktı (496.812 TL) aralığın üst sınırına çok yakın kaldı ama test geçti.
- **Test 2:** Bina yaşı 3 artırıldı. Sitedeki verilere göre bina yaşı arttıkça fiyatın 20-30 bin civarı düşmesi bekleniyordu; oysa program daha yüksek bir tahmin verdi ve test başarısız oldu. Öğrencinin yorumu, sitedeki verilerin çok gürültülü olmasıydı: ilanların çoğu 300-470 bin aralığındayken bazı seçkin semtlerde aynı özellikte evler 1 milyon ya da 1,2 milyon liraya konabiliyordu.
- **Test 3:** Metrekare ve oda sayısı belirgin biçimde azaltıldı (50 m², 1+1). Program 80 bin civarı bir tahmin yaptı ve aralığın altında kaldı. Öğrenci, programın doğrusal regresyonla çalıştığı için sonucun "biraz lineer gittiğini" söyledi.
- **Test 4:** Metrekare ve oda sayısı aşırı artırıldı (250 m², 7+1). Amaç, nadir bulunan veriler için programın nasıl tahmin yapacağını görmekti: sitede bu özelliklerde yalnız üç ilan vardı. Gerçekleşen çıktı bu ilanların fiyatlarının da üstünde kaldı ve test başarısız oldu.
- **Beta testleri:** Potansiyel kullanıcılarla birlikte yapıldı. Uygulama oda sayısını "3+1" biçiminde beklediği için oda sayısı yalnız bir sayı olarak girilince "Hatalı giriş, yeniden deneyiniz" türünden bir uyarı beklenirken program hiçbir çıktı vermeden durdu. Bütün alanlara harf girildiğinde de aynı şey oldu. Doğru biçimde girdi verildiğinde program doğru çalıştı.

Bu senaryolar, derste görülen negatif test durumlarının bir örneğidir: kullanıcı programın beklediği girdi biçimini bilemeyeceği için hatalı türde girdilerde sistemin anlamlı bir uyarı vermesi gerekir.

### 8.3 Sonuçlar

Sonuç slaytında iki bulgu vardı (ekrandan, 01:30:00):

- Unit testlerin sonucunda, veri setindeki gürültülü veriler ve verilerin tek bir kaynaktan alınması, uygulamanın temel fonksiyonunun doğruya yakın sonuçlar vermesini zorlaştırmıştır. Emlak fiyatları çok değişken olduğu ve yalnız beş parametre kullanıldığı için tahminler yeterince iyi değildir; örneğin 250 metrekarelik bir ev için kaynakta yalnız üç örnek vardır.
- Kullanıcılar üzerinde yapılan beta testlerinin sonucunda ürünün piyasaya sürülmeye hazır bir ürün olmadığı tespit edilmiştir. Beta testi zaten ürünün piyasaya hazır olup olmadığını ölçer; burada program, hatalı türde veri girişi gibi basit durumlara bile hazırlıksızdı.

> **Ek bilgi (derste anlatılmadı):** Çıktısı önceden kesin bilinemeyen programlarda (makine öğrenmesi modelleri, bilimsel hesaplamalar) beklenen sonucu belirleme güçlüğüne "test oracle problemi" denir. Bu sunumda kullanılan aralık tabanlı beklenen çıktı bir çözüm yoludur. Ders 11'de anlatılan metamorfik test ise bu soruna başka bir yoldan yaklaşır; örneğin "bina yaşı artınca tahmin edilen fiyat artmamalı" gibi bir ilişki, 2. testteki türden bir metamorfik ilişki olarak yazılabilir.

## 9. Bir Stok Dağıtım Sisteminde Sevk Yasaklarının Testi

Son sunumda bir öğrenci, derste görülen test kavramlarını kurumsal bir projeye uyguladı. Öğrenci gerçek projelerde testin yapıldığını, ama çoğu zaman "acil" kavramı yüzünden resmi ve olması gerektiği kadar düzenli yapılmadığını, bu çalışmayla testi daha sistemli biçimde ele aldığını söyledi.

### 9.1 Projenin Konusu: Alokasyon ve Sevk Yasakları

Slayttaki tanımlar şöyleydi (ekrandan, 01:35:00):

- Kısıtlı olan stoğu en yüksek kârla ve en kısa sürede satabilmek için analizler yapan ve bu analizleri uygulamaya geçiren işe alokasyon denir.
- Alokasyon, perakende dünyasında doğru ürünü, doğru fiyata, doğru lokasyona sevk etme işi olarak tanımlanır.
- Her ürün her lokasyona belirli sebeplerden dolayı gidemez. Bu kısıtları insan kontrolüne bırakmamak ve yapılan hataları en aza indirmek için sevk yasak kısıtlarının sistemsel olarak yönetilmesi gerekir.

Lojistik işlemi ürünü depodan mağazalara taşır; alokasyonun uzmanlık alanı ise ürünün hangi mağazada, hangi zamanda ve hangi fiyatla yer alacağına karar vermektir. Öğrenci stok yönetiminin önemini Toyota üretim sistemiyle ilişkilendirdi: sıfır stoğa en yakın biçimde çalışıp doğru zamanlama ve planlamayı yapabilen şirketler hem lojistik maliyetinden hem de mağazada doğru ürünü satma maliyetinden kazançlı çıkar.

Sevk kısıtlarına örnek olarak bazı ülkeler arasındaki menşe kısıtları (belirli bir ülkede üretilen ürünün belirli bir ülkeye gönderilememesi) ve belirli ürün türlerinin belirli ülkelere yasal olarak gönderilememesi verildi. Bu kısıtlar ihlal edilirse gümrükte ceza gibi yasal yaptırımlar doğar. Bu yüzden kısıtın bir kişinin dikkatine bırakılmaması, sistemsel olarak uygulanması gerekir.

### 9.2 Gereksinimler: Kullanıcı Hikayeleri

Projenin yaşam döngüsünün başında, analize başlamadan önce kullanıcılardan ve müşterilerden ne yapmak istediklerini kullanıcı hikayesi (user story) olarak anlatmaları istendi. Örnekler:

- Alokasyon ekibi olarak ülke ve mağaza bazındaki yasakların yanında kanal (channel) bazında da yasak koyabilmek istiyoruz. Kanal satış noktası demektir: e-ticaret, yurt içi mağaza, yurt dışı mağaza ya da ürünleri satan ama kuruma ait olmayan pazar yeri (marketplace) firmaları olabilir.
- Lot bazında da yasak koymak istiyoruz.
- Bir yasağı bütün ülkede uygulamak ama bir e-mağaza kanalında uygulamamak istiyoruz.

Bu gereksinimler analistlerle birlikte değerlendirildi: nasıl yapılabileceği, riskleri ve ek ihtiyaçlar analiz edildi.

### 9.3 Test Stratejisi ve Test Edilen Modüller

Test stratejisi dört adımdan oluşuyordu: birim, bütünleme, sistem ve kullanıcı kabul testleri (ekrandan, 01:40:00). Unit testlerin otomatik koşması hedeflense de bu projede bütün testler, birim testleri dahil, manuel yapıldı. Dört modülün her birinde 6 test case vardı, toplam $4 \times 6 = 24$ test case koşuldu. Öğrenci slayttaki "6 test case" ifadesinin modül başına olduğunu düzeltti.

Modüller ürün yasaklamanın dört düzeyine karşılık geliyordu:

- **Hiyerarşi bazında:** Ürünün bağlı olduğu ürün grubu ağacıdır (ör. bir ana grup, onun alt grubu, onun altındaki ürün türü).
- **Option bazında:** Bir ürünün renk gibi varyant ayrıntısına kadar inen düzeyidir.
- **Lot bazında:** Lot, tekil ürün değil, aynı ürünün farklı varyantlarının (boyutlarının) tek pakete konmuş halidir.
- **Product bazında:** Kullanılan her bir birim adet ürünü ifade eder.

Örnek test senaryoları hedef (target) ve kaynak (source) lokasyon bazında yazıldı. Örneğin "kanal bazında hiyerarşi yasağı konulmasının kontrolü" senaryosunda hedef lokasyon (yasağın konulacağı yer) seçilir, test adımları uygulanır ve verilen veriyle doğru sonucun alınıp alınmadığı kontrol edilir.

### 9.4 Ortamlar ve Hata Kayıtları

Projelerin teknik yönetimi ve iş kayıtları bir proje yönetim aracı üzerinden takip ediliyordu. Dört ortam (branch) vardı:

- **Development:** Yazılımın geliştirildiği ortam.
- **Test:** Test ekibinin testleri koştuğu ortam.
- **UAT:** Kullanıcı kabul testlerinin yapıldığı ortam.
- **Canlı (production):** Kullanıcıların kullandığı ortam.

Bunların yanında canlıya yakın bir release candidate (RC) ortamı vardır; canlı verisiyle test koşulması gerektiğinde bu ortam kullanılır.

Hata kayıtlarında önemli bir ayrım yapıldı. Test ortamında bulunan hata "Test Failure", UAT ortamında bulunan hata "UAT Failure" olarak işaretlenip yazılım ekibine geri gönderilir; böylece hatanın hangi ortamda ve hangi case'lerle bulunduğu anlaşılır. Canlı ortamda çıkan hata ise artık failure değil "bug" olarak kaydedilir ve servis masası üzerinden yazılım ekibine iletilir.

Kayıtların önem derecesine bağlı çözüm süreleri (SLA kriterleri) vardır. Canlıdan gelen bir kayıt kritikse çözüm süresi 1 saat, yüksekse 4 saat, düşükse 8 saattir. Test failure kayıtlarında da aynı dereceler kullanılır:

- **Kritik:** Projenin önünde engeldir.
- **Yüksek:** Tüm sistemi etkilemez ama belirli bir iş yapılamıyordur, o kısım kullanılamaz.
- **Düşük:** Daha çok kozmetiktir ya da kullanıcı ihtiyacına göre şekillenmiştir; canlıya alınmaya engel değildir.

### 9.5 Test Ortamı, Kaynak ve Eğitim İhtiyacı

Slayttaki bilgiler (ekrandan, 01:45:00):

- Test ortamı donanımsal olarak 4 çekirdekli CPU ve 8 GB RAM içerir.
- Canlı ortam donanımsal olarak 7 çekirdekli CPU ve 32 GB RAM içerir.
- Testleri yürütmek için gereken insan kaynağı: yazılım geliştirme ekibinden 1 yazılım geliştirici, proje yönetimi ekibinden 1 iş analisti, test ekibinden 1 test uzmanı.
- İş analistinin test uzmanına süreçleri, analiz belgesini ve iş akış diyagramlarını anlattığı bir eğitim seansına ihtiyaç vardır.

Test ve canlı ortam arasındaki farkın belirtilmesinin sebebi şudur: büyük veriyle çalışılan noktalarda test ortamının donanımı yeterse canlıya almak için engel yoktur; yetmezse test tekrarlanmalıdır. Uygulama canlıda çalışabilir ama bunun garantisi test ortamının kaynaklarıyla verilemez.

Eğitim seansı, test uzmanının iş sürecini anlaması için gereklidir: bulduğu bir bulgunun süreçten kaynaklanan beklenen bir davranış mı yoksa gerçekten bir hata mı olduğunu ayırt edebilmesi gerekir.

### 9.6 Test Takvimi

Test takvimi bir buçuk gün sürdü:

- Yarım gün test uzmanının eğitimi.
- Birim testleri: geliştirici tarafından 2 saat.
- Bütünleme testleri: test uzmanı tarafından test ortamında 2 saat.
- Sistem testleri (yük testleri ve ortam testleri): 1 saat.
- Kullanıcı kabul testleri: UAT ortamında müşteriyle birlikte tüm ekip tarafından 3 saat.

Kontrol (ara adım eklendi, 8 saatlik iş günü varsayımıyla): yarım gün 4 saattir; $4 + 2 + 2 + 1 + 3 = 12$ saat, yani $12 / 8 = 1{,}5$ gün eder. Bulgular düzeltilmesi gerektiği için süreç bundan sonra da devam etti.

### 9.7 Yaşanan Riskler

Öğrenci, anlattığı risklerin kâğıt üzerindeki değil gerçekten yaşanmış riskler olduğunu vurguladı. Derste "bu risk olursa ne olur" diye konuşulan risklerle pandemi döneminde doğrudan yüzleşildiğini söyledi.

- **Test uzmanı kaybı:** Test uzmanının ayrılması bir risktir; yedek bir uzman varsa yerine konabilir. Ancak test hizmeti dışarıdan alınıyordu ve bütçe kısıtlaması nedeniyle sözleşmeler durdurulunca yedek test uzmanı bile kalmadı. Önlem olarak işin sürmesi için test görevi analistlere yüklendi; analistler uzmanlıkları olmasa da süreci devam ettirdi.
- **Ortamın paylaşılması:** Test ortamı aynı takvimde başka bir proje tarafından da kullanılıyorsa sorun çıkabilir. Ortamın yetmediği sanılabilir; oysa sorun, birden fazla projenin aynı ortamı kullanmasıdır.
- **Paydaşların kabul testine zaman ayırmaması:** Müşteri kabul testine gerekli vakti ayırmazsa projenin gecikme riski doğar. Testi ciddiye almadan "kabul ettim, canlıya alabiliriz" derse bu kez canlıda hatalarla karşılaşma riski doğar.
- **Gözden kaçan hata:** Gözden kaçan bir hata yüzünden yasal olarak gönderilmemesi gereken ürünler bir ülkeye gönderildi; sonuçta ürünleri geri alma maliyeti ve yüksek tutarlı cezai işlem ortaya çıktı. Bu, sevk kısıtlarının neden sistemsel olarak yönetilmesi ve iyi test edilmesi gerektiğini gösteren bir örnektir.

### 9.8 Test Çıktıları

Modül ekranlarında üstte bir filtre alanı, altta yasakların listelendiği bir tablo ve sağda yasağın dayanağının girildiği bir bölüm vardı (ekrandan, 01:50:00). İşlem başarılı olunca üst barda bir onay mesajı, hatalıysa kırmızı bir uyarı görünür.

Sonuçlar:

- Birim ve bütünleme testlerinde işlevsel bir sorun çıkmadı.
- Sistem testlerinde, 4 çekirdek/8 GB'lık test ortamı 100-200 bin adetlik ürün yasağını işlemeye yetmedi ve zaman aşımı (timeout) hataları alındı. Sorunun koddaki bir performans sorunundan mı yoksa ortamın yetersizliğinden mi kaynaklandığını ayırmak için test, 5 çekirdekli CPU ve 16 GB RAM içeren release candidate ortamında tekrarlandı. Burada sistem testleri başarıyla koştu; canlı ortamın kaynağı daha fazla olduğu için projenin canlıda çalışacağı sonucuna varılıp onay alındı.
- Web uygulaması birden fazla tarayıcıda denendi. Kullanılan arayüz framework'ünün en iyi performansı ve en kararlı çalışmayı Chrome'da verdiği raporlandı; müşteri ve paydaşlar Chrome kullanmaları yönünde bilgilendirildi.
- UAT ortamında müşteriyle yapılan kabul testleri başarıyla sonuçlandı ve proje onay alınarak canlıya taşındı.

> **Ders sonrası not:** Öğrenci canlı ortamın kaynağının release candidate ortamının "bir buçuk katı" olduğunu söyledi. Verilen değerlere göre çekirdek sayısında oran $7 / 5 = 1{,}4$, RAM'de $32 / 16 = 2$'dir; yani çekirdekte yaklaşık 1,4 kat, bellekte 2 kat fazladır.

## Dersin Toparlaması

Bu son derste öğrenciler dönem boyunca görülen test kavramlarını kendi projelerine uyguladı. Sunumlar, bir test planının ortak bileşenlerini farklı örneklerle gösterdi: kapsam ve test edilecek modüller, test seviyeleri (birim, entegrasyon/bütünleme, sistem, kabul, beta), test ortamı, başlatma/tamamlama/durdurma/tekrar başlatma kriterleri, hata dereceleri ve hata süreci, risk tablosu (ihtimal, etki, önlem), raporlama ve test case belgesinin alanları. Beyaz kutu ve kara kutu testinin nerede kullanıldığı (entity katmanında unit test, arayüzde kara kutu), pozitif ve negatif test durumları, denklik sınıfları, regresyon testi ve fazlar arası geçiş kuralları somut örneklerle işlendi.

Sunumlar ayrıca araç kullanımını da gösterdi: Jest, Enzyme, Django unit test, MS Test, Selenium IDE. Makine öğrenmesi uygulamasının testi, beklenen çıktının kesin bilinmediği durumlarda testin nasıl kurulabileceğini, son sunum da test ortamı ile canlı ortam arasındaki farkın, kaynak eksikliğinin ve paydaş katılımının gerçek projelerde nasıl risklere dönüştüğünü gösterdi. Hoca, profesyonel hayattaki test belgesi formatlarının görülmesinin yararlı olduğunu ve sunumlarda araçların nasıl kullanıldığının anlatılması gerektiğini vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
