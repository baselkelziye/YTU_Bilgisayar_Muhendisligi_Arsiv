# Ders 13 Çalışma Özeti

## Genel Konular

- Bu derste konu anlatımı yoktur. Gönüllü üç grup dönem projesinin test sunumunu yapar.
- Her grup aynı iskeleti izler: yazılımın tanıtımı, test planı, birim testi (unit test), sistem testi ve kullanıcı testi.
- 1. grup: web tabanlı bir kütüphane yönetim sistemi (Spring Boot).
- 2. grup: Vevericka adlı, dil öğrenmek isteyenleri eşleştiren mikroservis (microservice) mimarili bir sosyal medya platformu.
- 3. grup: otobüs bileti ve yolculuk yönetim sistemi. Bu sunumun büyük kısmında ses çok bozuktur.
- Ders sonunda son haftanın sunum sırası ve kuralları belirlenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Projede beklenen minimum koşullar şunlardır:
  - Seçilen yazılım genel olarak tanıtılır. İsteyen gereksinim (SRS) raporu üzerinden ilerleyebilir.
  - Test planı verilir.
  - Kullanıcı testi ve sistem testi için en az bir açık kaynaklı (open source) araç bulunur ve kullanılır.
  - Birim testi kod üzerinde gösterilir.
- Hoca 1. grubu bu koşulları yerine getiren başarılı bir örnek olarak gösterir.
- Hoca her gruptan test planındaki görevlerin hangi üyeye ait olduğunu açıkça söylemesini ister. Kimin hangi testi yaptığı sunumda ve raporda görünmelidir.
- Sunum yapmayan üyelere bir sonraki derste projeyle ilgili soru sorulacaktır.
- Hoca 2. gruba araçları nasıl seçtiklerini sorar. Amaç, sonraki haftanın gruplarına araç seçme yöntemini göstermektir.
- İki kişilik 3. gruba zaman planını daha iyi yapmalarını söyler.

## Kısa Tekrar Notları

- Bir test planında şunlar bulunur: test stratejisi, test edilecek öğeler, doğrulama yöntemleri, tamamlanma kriterleri, hata raporlama, test sonuç raporlama, sorumluluklar ve eğitim ihtiyacı, test takvimi (Gantt şeması), risk yönetimi, test ortamı ve araçları.
- Gruplarda ortak hata sınıflandırması:
  - 1. derece hata: sistemin genel çalışmasını doğrudan etkiler.
  - 2. derece hata: sistemi durdurmaz ama bazı işlevleri engeller.
  - 3. derece hata: çalışmayı etkilemez, görsel bir kusurdur.
- Test tamamlanma kriteri örneği: planlanan tüm testler bitmiş ve 1., 2. ve 3. derece hataların tamamı çözülmüş olmalıdır.
- Kapsam (coverage), testlerin kodun yüzde kaçını çalıştırdığını gösterir. 2. grup %60'ı hedefler ve %64'e ulaşır.
- Araçlar:
  - Java/Spring: JUnit ve Spring Boot Test.
  - Node.js: Mocha, Chai ve Istanbul (birim testi ve kapsam), Sinon ve SuperTest (entegrasyon), Postman (sistem testi).
  - Python: PyTest.
  - Vue.js: Vue Test Utils (Jest tabanlı).
  - Web performansı: GTmetrix ve Chrome Lighthouse.
- Sürekli entegrasyon (continuous integration) örneği: master dalına her push veya pull request geldiğinde GitHub Actions yazılımı derler ve birim testlerini çalıştırır.

## Detaylı Açıklamalar

### Sunum düzeni

- Hoca dersin başında gönüllü grupları sıralar. Sunuma hazırlık için 5 dakika verir.
- Bugün az grup olduğu için gruplara uzun süre tanınır. Hoca, sonraki haftanın gruplarının daha planlı ve daha özet anlatmasını ister.
- 2. grubun sunumu sırasında hocanın interneti birkaç kez kopar. Grup, kaçan bölümü hocanın isteğiyle kısaca tekrar anlatır.

### 1. grup: Kütüphane yönetim sistemi

- **Yazılım:** Kütüphanelerde takibi kolaylaştıran web tabanlı bir sistemdir. Kitap ödünç verme, ödünç kayıtlarını izleme, kitap arama, kayıtlara erişme ve rapor oluşturma işlerini yapar.
- **Test edilen modüller:** üye, kitap, yazar, yayıncı ve kütüphane ayarları.
- **Test seviyeleri:** birim, sistem ve kullanıcı testi.
- **Doğrulama:** Test aşamasında planlanan senaryolar çalıştırılır. Analiz aşamasında beklenen değerler ile sistemin yanıtı karşılaştırılır ve sonuç raporlanır.
- **Hata yaşam döngüsü (bug life cycle):**

```text
Hata bildirim formu doldurulur
  -> Sistem mühendisi grubuna iletilir        [Bildirildi]
       -> Reddedilirse                         [Kapandı]
       -> Kabul edilirse ilgili kişiye atanır  [Atandı]
            -> Kişi hata kendisine ait değil derse: sistem mühendisi grubuna geri döner
            -> Kişi hatayı çözer, test grubuna iletir  [Testte]
                 -> Test geçerse                       [Kapandı]
```

- **Roller:** test yöneticisi, test grubu, test ortamı sorumlusu, konfigürasyon yönetimi sorumlusu ve risk sorumlusu. Test ortamı olarak üyelerin kendi bilgisayarları kullanılır.
- **Test verisi:** elle hazırlanır. Gerçek kullanıcıların girebileceği verilere benzer olması gözetilir.
- **Kullanıcı testi:** 6 test durumu (test case) vardır. Bunların 5'i fonksiyonel, 1'i fonksiyonel olmayan bir gereksinimi hedefler.
  - Yönetici rolü kullanıcı ekleyip düzenleyebiliyor mu? Eklenen kullanıcı listede görünüyor mu?
  - Yönetici kullanıcıları ad, soyad veya e-posta ile arayabiliyor mu?
  - Editör rolü kitap ekleyip düzenleyebiliyor mu? Yayıncı ve yazar yalnızca sistemde var olanlardan seçilebilir.
  - Kitap aramada adın bir kısmı yazılınca sonuç geliyor mu?
  - Editör yazar ekleyip düzenleyebiliyor mu?
  - Güvenlik: her rol yalnızca kendi modüllerine erişebiliyor mu? Kütüphaneci yalnızca üye ekleme ve ödünç kayıtlarını, editör yalnızca kitap, yazar ve yayıncı modüllerini görür. Kullanıcı modülü yalnızca yöneticiye açıktır.
- **Bulunan hata:** Kitabı olmayan bir yazar eklendikten sonra kitap listesine erişilemez. Grup bu hata için hata bildirim formu doldurur.
- **Sistem testi (performans):** GTmetrix ile web performans metrikleri ölçülür:
  - First Contentful Paint (FCP): sayfa yüklenirken ilk içeriğin ekrana gelme süresi.
  - Speed Index: içeriğin ne hızla görünür hâle geldiğini gösteren hız göstergesi.
  - Largest Contentful Paint (LCP), Total Blocking Time (TBT) ve Cumulative Layout Shift (CLS).
  - Sonuç: tam yüklenme yaklaşık 1,2 saniyedir. CLS 0,24 ile zayıf çıkar. Diğer altı metrik iyi sonuç verir.
- **Birim testi:** Spring Boot Test ve JUnit ile servis katmanı test edilir.
  - Kitap kaydı: kayıt formu servise verilir. Başarılıysa nesne, başarısızsa `null` döner. Sonuç assert ile kontrol edilir.
  - Kitabın ödünç verilebilirliği: fonksiyon `true` veya `false` döner, sonuç assert edilir.
  - Yayıncıyı ID ile bulma: kayıt varsa nesne, yoksa `null` döner.
  - Kullanıcı kaydı: `assertNotNull` ile kayıt doğrulanır. Girilen ve kaydedilen değerlerin eşitliği de kontrol edilir.
  - Hatalı girdi: kayıtlı bir e-postayla yeniden kayıt denenince "entity already exists" türü bir istisna (exception) fırlatılması beklenir. Boş veya `null` şifrede de ayrı bir istisna beklenir.
  - Yazar servisi: anahtar kelimeyle aramanın sayfalı (page) sonucu beklenen değerlerle karşılaştırılır.
  - Kütüphane ayarları: örneğin `maxExtension` bir ödünç kaydının kaç kez uzatılabileceğini belirler. Değer 5 yapılınca sonuç assert edilir. Sayısal alana metin verilince istisna beklenir.

### 2. grup: Vevericka (dil eşleştirme platformu)

- **Yazılım:** Grup projeyi yazın kendi geliştirmiştir, bir müşterisi yoktur. Kullanıcı öğrenmek istediği dili seçer. Sistem onu o dili bilen kişilerle eşleştirir.
- **Mimari:** mikroservislerden oluşur.

| Servis | Teknoloji | Görev |
|---|---|---|
| User Info Service | Node.js, Express.js | Kullanıcı bilgileri. En büyük servis. |
| Authentication Service | Node.js, MongoDB, Mongoose, bcrypt, JWT | Giriş ve yetkilendirme |
| Message Service | Node.js, Express.js | Eşleşen kullanıcılar arasında mesajlaşma |
| Match Service | Python, FastAPI | Arkadaş önerisi |
| Web Client | Vue.js, Vuetify, Heroku | Ön yüz |

- **Test araçları:**
  - Node.js servislerinde birim testi Mocha ve Chai ile yazılır. Kapsam (coverage) Istanbul ile ölçülür.
  - Entegrasyon testi Sinon ve SuperTest ile, sistem testi Postman ile yapılır.
  - Match Service PyTest ile, Web Client Vue Test Utils ile test edilir.
- **Test raporu:** Test grupları (test suite) servislerin adlarıyla eşleşir. Test edilen birimler genelde controller, model ve validation katmanlarıdır.
  - Örnek test: kullanıcı yokken servis boş liste döndürüyor mu? Test girdi almaz, beklenen sonuç boş listedir. Test geçer.
- **User Info Service:**
  - 49 birim testi vardır, hepsi geçer.
  - Entegrasyon testleri bulutta sorunsuz çalışır. Yerelde Node.js ortamından kaynaklanan bir önbellek sorunu yüzünden hata verebilir.
  - Test planındaki geçme kriteri %60 kapsamdır. Ölçülen kapsam %64'tür: validation ve model %100, controller %63.
  - Postman ile canlı (production) ortama 9 sistem testi gönderilir. Her biri yanıt süresinin 200 ms altında olmasını kontrol eder. Hepsi geçer.
- **Araç seçimi (hocanın sorusu üzerine):**
  - Yazılımın dili ve platformu önceden belli olduğu için npm sitesinde test kategorisindeki kütüphaneler taranır.
  - Kütüphanelerin siteleri ve Medium yazıları incelenir. Mocha ile Jest arasında kalınır, arka uç için Mocha seçilir.
  - Ön yüzde Vue.js'in resmî desteği olan Vue Test Utils kullanılır. Bu araç Jest altyapısı üzerinde çalışır. Mocha ile Jest'in yazım stilleri birbirine çok benzer.
- **Authentication Service:**
  - Şifreler bcrypt ile tuz (salt) eklenerek özetlenir (hash) ve veritabanına öyle kaydedilir.
  - Gerekçe: Kullanıcılar "12345678" gibi basit şifreleri tekrar tekrar kullanır. Tuzsuz özetlemede aynı şifreler aynı özeti üretir.
  - Giriş başarılıysa kullanıcıya e-posta ve şifre yerine kullanılacak bir JSON Web Token (JWT) verilir. Token tarayıcının local storage alanında saklanır.
- **Message Service:** İki kullanıcı ilk kez mesajlaşınca veritabanında onlara ait bir sohbet odası (chat room) oluşur. Mesajlar orada tutulur ve sonraki girişlerde oradan çekilir.
- **Match Service:** User Info Service'ten hobi, dil, ülke ve okul bilgisi alınır. Bu bilgiler bir metne çevrilip vektörleştirilir. Kosinüs benzerliği (cosine similarity) ile en benzer 30 kullanıcı döndürülür.
- **Web Client:**
  - Sistem testi Chrome Lighthouse ile yapılır. Heroku'nun ücretsiz sunucusuna rağmen performans puanı 92 çıkar. Erişilebilirlik (accessibility) puanları da yüksektir.
  - Uygulama canlı olarak gösterilir: giriş, öneriler, profil, mesajlar ve ayarlar.
- **Sürekli entegrasyon:** User Info Service deposunda bir GitHub Actions YAML dosyası vardır. Master dalına her push ve pull request geldiğinde Node.js ortamında derleme yapılır ve birim testleri çalıştırılır.
- **Kullanıcı testi:** Uygulama alfa aşamasındadır ve herkese açıktır. Yoğun kullanan 20-25 kullanıcıdan farklı cihaz, tarayıcı ve işletim sistemlerinde geri bildirim alınır.

### 3. grup: Otobüs bilet ve yolculuk yönetim sistemi

- **Yazılım:** Otobüs biletleri ve seferler için bir yönetim sistemidir. Grup bir önceki yılın bir ders projesini seçmiştir. Yönetici otobüsleri, çalışanları, seferleri, kullanıcıları ve biletleri yönetir. Kullanıcı bakiyesiyle bilet alır.
- **Birim testi:** iki senaryo vardır:
  - Kullanıcı adı veya şifre eksik verilerek giriş denenir.
  - Yanlış bilgilerle giriş denenir.
- **Sistem testi:** veritabanı bağlantısı kurulabiliyor mu ve doğru hata kodları dönüyor mu kontrol edilir.
- **İstemci testi:** istemci giriş izni ister ve iznin dönüp dönmediği kontrol edilir.
- **Öncelikli senaryolar:** yeni müşteri ekleme ve sisteme giriş. Gerekçe: yetkisiz biri sisteme girerse başkasının bilgilerini değiştirebilir veya bilet alabilir.
- **Entegrasyon testi:** sahte (dummy) veriler içeren ayrı bir test veritabanı ayağa kaldırılır. JUnit testleri REST istekleriyle kayıt ve giriş akışını dener.
- Sunumun ikinci yarısında ses neredeyse anlaşılmaz. Bu bölüm altyazıdan güvenilir biçimde çıkarılamaz.
- Hoca sesin çok az geldiğini, raporla birlikte takip ettiğini söyler.

### Son hafta için duyurular

- Bir sonraki ders dönemin son dersidir. Kalan bütün gruplar sunum yapmak zorundadır.
- Sunum süresi en fazla 20 dakikadır.
- Raporun tümünü okumak yerine ana hatları slayta dökmek önerilir. Bu, sunumları hızlandırır.
- Kodlar birim testini anlatırken kullanılmalıdır. Uygulama kısaca tanıtılmalıdır.
- Ders 13.00'te başlar. İlk üç grubun sırası bu derste belirlenir. Kalan sıralamayı hoca derste yapacaktır.
- İlk üç gruptan sonra (yaklaşık 13.45'ten itibaren) herkes derste bulunmalıdır.

### Ders sonrası notlar

- 1. grup rollere göre modül erişimini "authentication" olarak adlandırır. Kimlik doğrulama (authentication) kullanıcının kim olduğunu doğrular. Rolün hangi modüle erişebileceğini belirleyen işlem yetkilendirmedir (authorization). Grubun test ettiği şey yetkilendirmedir.
- 1. grubun CLS sonucu (0,24) Google'ın Web Vitals eşiklerine göre "iyileştirme gerekli" aralığındadır (0,1-0,25). 0,25'in üstü "zayıf" sayılır. Araçlar renklendirmeyi farklı yapabilir.
- 2. grup bcrypt işlemini "önce özetleme, sonra tuzlama" diye anlatır. Doğrusu: bcrypt her şifre için rastgele bir tuz üretir ve şifreyi bu tuzla birlikte özetler. Tuz, özetin içinde saklanır. Böylece aynı şifreler farklı özetler üretir ve hazır özet tablolarıyla (rainbow table) yapılan saldırılar zorlaşır.
- 2. grup JWT'yi "bir tür cookie" diye anlatır. JWT bir token biçimidir. Cookie'de de local storage'da da saklanabilir. Local storage JavaScript'ten okunabildiği için XSS saldırısına açıktır. Bu yüzden HttpOnly cookie sık önerilen bir seçenektir.
- 2. grubun entegrasyon testleri yerelde başarısız olup bulutta geçer. Ortama göre sonucu değişen test güvenilir değildir. Sebebi bulunup giderilmelidir.
- %60 kapsam hedefi grubun kendi seçimidir. Evrensel bir eşik yoktur. Hedef, projenin riskine ve kod türüne göre test planında gerekçesiyle yazılmalıdır.
- Altyazıda araç adları bozuk geçer. Doğruları: "Çay" Chai, "İstanbul CS" Istanbul, "GT metrics" GTmetrix, "First Content Mode Paint" First Contentful Paint, "Mongo's" Mongoose, "BigRibs" bcrypt, "Sinan" Sinon, "FASC API" FastAPI, "kosans simerite" cosine similarity, "Hiroku" Heroku, "Verika / Weberichka / WebExCambient" Vevericka.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
