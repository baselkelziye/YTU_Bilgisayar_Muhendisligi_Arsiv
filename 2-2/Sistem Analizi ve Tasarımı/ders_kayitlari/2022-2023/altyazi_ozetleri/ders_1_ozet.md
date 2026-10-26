# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 28 Şubat 2023 Salı. Ders Zoom üzerinden, çevrim içi yapıldı.
  - Asıl ders yaklaşık 00:03:47'de başlar. Kaydın başı bekleme kısmıdır.
  - Hoca Göksel Biricik. Ders 1'de kendini tanıtıyor (00:05:07); Zoom etiketi "Göksel BIRICIK".
- Dönemin özel durumu
  - Deprem nedeniyle bahar dönemi çevrim içi yürütülüyor. Nisan'da yeniden değerlendirme yapılacak.
  - Bu dönem yoklama alınmıyor. Kayıtlar sonradan izlenebilir.
- Dersin işleyişi
  - Ders Salı günleri 2 saat (yaklaşık 13:00-15:00). Hocanın odası D127.
  - Kaynaklar: Oya Hoca ile birlikte yazdıkları "Bilgisayar Bilimlerinde Sistem Analizi ve Tasarımı" kitabı ve Satzinger'in "Systems Analysis and Design in a Changing World" kitabının 6. baskısı.
- 14 haftalık ders planı
  - Giriş, bilgi sistemi türleri ve tarafları, geliştirme süreci.
  - Ön inceleme ve fizibilite (özellikle zaman fizibilitesi).
  - Sistem analizi: iş gereksinimleri ve çözümleme (fonksiyonel ve nesneye dayalı).
  - Sistem tasarımı: mimari, genel ve ayrıntılı tasarım; girdi, çıktı, veri ve ara birim tasarımı.
  - Veri tabanı tasarımı, gerçekleştirme, test, geçiş, bakım ve destek.
  - Bir vaka çalışması ve son iki haftada grup proje sunumları.
- Değerlendirme ve proje
  - Vize %30, proje %30, final %40.
  - Proje 5 kişilik gruplarla yapılıyor; konu ve en az 5 modül önerilecek.
- Sistem kavramına giriş
  - TDK sözlüğündeki "sistem" anlamlarından bilgi sistemi özelliklerinin çıkarılması.
  - Sistemin tanımı ve temel özellikleri.
  - Bilgi sisteminin tanımı ve bileşenleri (donanım, yazılım, insan, veri, ağ).
  - Sistemlerin teorik özellikleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Projede veya sınavda kopya tespit edilirse o kriterden not sıfır olur.
  - Ayrıca disiplin işlemi başlatılır.
- Sınavlara girmeyen veya projeyi vermeyen öğrenci F0 alabilir.
  - Yoklama alınmaması bu kuralı değiştirmiyor.
- Sistemin tanımını tam olarak bilin.
  - Belli bir amacı gerçekleştirmek için bir arada çalışan, birbiriyle ilişkili parçalardan oluşan, girdi ve çıktıları olan, sınırları belirlenmiş bütün yapıya sistem denir.
  - Bu öğelerden biri yoksa sistemden söz edilemez.
- Bilgi sisteminin bileşenlerini "D-Y-İ-V-A" diye hatırlayın: Donanım, Yazılım, İnsan, Veri, Ağ.
- Bilgi sistemi ile bilgisayar programı arasındaki temel fark ölçektir.
  - Bir programı tek kişi yazabilir; bir bilgi sistemini tek kişi kısa sürede üretemez.
- Tasarımda değişimlerden etkilenmeyecek yapılar kurmaya çalışın.
  - Bir bileşendeki değişiklik, ona bağlı bütün bileşenleri etkiler.
- Bilgi, günümüzde en değerli kaynaklardan biridir.
  - Doğru kullanılan bilgi büyük rekabet avantajı sağlar.
- Ders sonrası alıştırma: Bir bilgi sistemi seçin.
  - Bileşenlerini, ortamını, sınırını, ara birimlerini, süreçlerini ve insan ve ağ kaynaklarını yazın.

## Kısa Tekrar Notları

- **Sistem:** amaç + ilişkili parçalar + girdi/çıktı + sınır.
- **Sistemin temel özellikleri:**
  - Bileşen
  - Değişken
  - Parametre (sabit)
  - İlişki
  - Sınır
  - Ara birim
  - Kısıt
  - Ölçüt
  - Ortam
  - Geri besleme
- **Ortam:** sistemin dışında kalan her şey.
- **Ara birim:** sistemin ortamla veya başka sistemlerle konuştuğu nokta. Örnek: API (Application Programming Interface).
- **Ölçüt:** sistemin amacına ne kadar ulaştığını ölçen metrik. Örnek: saniyede 1000 ders kaydı.
- **Geri besleme:** çıktı ve ölçüm sonuçlarının sistemi iyileştirmek için tekrar girdi olarak kullanılması.
- **Bilgi sistemi:** veriyi toplayan, işleyen, depolayan ve dağıtan; insan, veri, iş akışı ve bilgi teknolojilerinin birlikte çalıştığı yapı.
- **Bileşenler (DYİVA):** Donanım, Yazılım, İnsan, Veri, Ağ.
- **Değerlendirme:**

  | Tip | Ağırlık | Tarih |
  | :--- | :---: | :--- |
  | Vize | %30 | 24 Nisan haftası |
  | Proje | %30 | Öneri 14 Mart, değerlendirme 17 Mart, rapor 22 Mayıs 2023 |
  | Final | %40 | 5-15 Haziran 2023 arası |

## Detaylı Açıklamalar

Hoca dersi deprem sonrası çevrim içi döneme dair bir değerlendirmeyle açtı. Ardından dersin kaynaklarını, haftalık planını ve değerlendirme kriterlerini anlattı. Konu anlatımı yaklaşık 00:38:00'de "sistem nedir?" sorusuyla başlar.

### Ders kaynakları ve plan

- **Türkçe kaynak:** Hocanın Oya Hoca ile yazdığı "Bilgisayar Bilimlerinde Sistem Analizi ve Tasarımı" kitabı.
  - Kitap artık basılmıyor, dersin özeti gibi düşünülebilir.
  - Hoca, derste kitapta olmayan ek bilgiler de vereceğini söyledi.
- **İngilizce kaynak:** Satzinger, *Systems Analysis and Design in a Changing World*.
  - Ders 6. baskıyı temel alıyor. Bu baskı hem geleneksel (fonksiyonel) hem nesneye dayalı yaklaşımı birlikte ele alıyor. Sonraki baskılar tamamen nesneye dayalı.
- **Haftalık plan (slayttan):**
  - **1. hafta:** Giriş.
  - **2. hafta:** Bilgi sistemi türleri, taraflar, geliştirme süreci.
  - **3. hafta:** Ön inceleme ve fizibilite.
  - **4-5. haftalar:** Sistem analizi.
    - İş gereksinimleri; veri toplama yöntemleri.
    - Kullanım senaryoları (use case).
  - **5-6. haftalar:** Çözümleme.
    - Fonksiyonel çözümleme ve nesneye dayalı çözümleme.
  - **7-8. haftalar:** Sistem tasarımı.
    - Mimari, genel ve ayrıntılı tasarım.
    - Girdi, çıktı, veri yapısı ve ara birim tasarımı.
  - **9. hafta:** Ara sınav.
  - **10. hafta (2 Mayıs):** Veri tabanı tasarımı (ilişkisel model).
  - **11. hafta ve sonrası:** Gerçekleştirme, test, yeni sisteme geçiş, bakım ve destek; ardından bir vaka çalışması.
  - **Son iki hafta:** Grup proje sunumları.

### Proje

- **Kapsam:** Seçilen bir bilgi sisteminin bütün süreci. Ön inceleme, fizibilite, analiz, tasarım, kodlama, veri tabanı tasarımı, test ve destek aktiviteleri dahil.
- **Gruplar:** 5 kişilik. Yaklaşık 80 öğrenci ve 16 grup olacak.
  - Eksik kalan gruplara rastgele öğrenci eklenir.
  - Grubu olmayanları hoca rastgele gruplar; gerekirse konuyu da hoca atar.
  - Başka bir gruptan ortak üye alınamaz.
- **Öneri:** 14 Mart'a kadar e-postayla ekip ve konu gönderilecek. Konu ve içinde olacak en az 5 modül (işlev) yazılacak.
- **Değerlendirme:** 17 Mart'a kadar yapılacak. Sonuç "uygun", "içerik değişmeli" veya "konu değişmeli" olabilir.
- **Rapor:** 22 Mayıs 2023 Pazartesi'ye kadar teslim edilecek.
  - Sunumlar 13. hafta Salı başlıyor. Herkese eşit süre olsun diye bütün raporlar bir gün önce isteniyor.
- **Sunum:** Her grup Zoom'da sunum yapacak. Amaç 16 farklı vakayı birlikte görmek ve deneyimi paylaşmak.
- **Programlama dili:** Serbest. Fizibilite sonucunda uygun görülen dil kullanılabilir.

### Sistem kavramı

- Hoca TDK sözlüğündeki "sistem" anlamlarından yola çıktı. Her anlamdan bilgi sisteminin bir özelliği çıktı:
  - **Düzen:** Bilgi sistemi bilgileri düzenler.
  - **Bir sonuç elde etmeye yarayan yöntemler düzeni:** Bilgi sistemi bir amaca hizmet eder ve çıktı üretir.
  - **Yol, yöntem:** Bilgi sisteminde süreç ve iş akışı tanımları olmalıdır.
  - **Düzenek, tertibat (fren sistemi gibi):** Bilgi sisteminin birlikte çalışan bileşenleri vardır.
  - **Model, tip ("son sistem"):** Aynı işi yapan daha eski veya daha yeni modelde bilgi sistemleri olabilir.
  - **Dizge (felsefe):** Bir bütün oluşturacak biçimde birbirine bağlı öğelerin düzeni.
- **Tanım:** Belli bir amacı gerçekleştirmek için bir arada çalışan, birbiriyle ilişkili parçalardan oluşan, girdi ve çıktıları olan, sınırları belirlenmiş bütün yapı, oluşum veya çözüm.
- **Temel özellikler:**
  - **Bileşen:** sistemi oluşturan parçalar.
  - **Değişken:** çalışma sırasında değer tutan özellikler (programdaki değişkenler gibi).
  - **Parametre:** sabitler (`final`, constant).
  - **İlişki:** bileşen, değişken ve parametreler arasındaki bağlantılar.
  - **Sınır:** sistemi ortamdan ayıran çizgi (hücre duvarı gibi).
  - **Ara birim:** ortamla veya başka sistemlerle etkileşim noktası. Bugün çoğu bilgi sistemi API üzerinden haberleşir. API, hangi hizmetin hangi koşulla verileceğini belirleyen bir sözleşme gibidir.
  - **Kısıt:** değişkenlerin alabileceği değerler ve kaynak sınırları.
  - **Ölçüt:** amaca ne kadar ulaşıldığını gösteren metrik. "Saniyede 1000 kayıt" gibi bir ölçüt, tasarımın ölçeğini belirler.
  - **Ortam:** sistem dışındaki her şey.
  - **Geri besleme:** çıktının ölçülüp sistemi iyileştirmek için tekrar girdi olarak verilmesi.

### Sistem ve ortam

- Sistemler bulundukları ortama bağlıdır. Genellikle bir sistem başka bir sistemin üzerinde durur.
  - Öğrenci bilgi sistemi sunucuda, sunucu işletim sisteminde, işletim sistemi donanımda çalışır.
- Sistem ortamda değişiklik yapabilir. Örnek: diske yazılan veri manyetik ortamı değiştirir.
- Bina örneği: Isıtma, güvenlik, enerji, aydınlatma ve su sistemleri birbirini etkiler. Hepsi binanın alt sistemleridir. Bina caddede, cadde şehirde durur.
- Aynı uygulama farklı ortamlarda farklı sistemdir. Windows, iPad ve Android'deki Zoom aynı görünse de ortama göre ayrı tasarlanmıştır.
- Örnek sistemler: Ev sinema sistemi (ses, görüntü, video alt sistemleri) ve restoran.
  - Restoranın girdileri malzeme, para ve alettir; çıktısı yiyecektir.
  - Bileşenleri depo, büro, mutfak, salon ve müşteri hizmetleridir.

### Bilgi sistemi ve bileşenleri

- **Tanım:** Bir oluşumun ihtiyaçlarını desteklemek için veriyi toplayan, işleyen ve depolayan yapıdır. Bu süreçte insan, veri, iş akışı ve bilgi teknolojileri bir arada çalışır.
- Bilgi sistemi yalnızca girdi, işlem, depolama ve çıktıdan oluşmaz; insanlar ve iş akışları da sistemin parçasıdır.
- **Donanım kaynakları:** Sunucu, bilgisayar, monitör, yazıcı, tablet, barkod okuyucu gibi elle tutulan her şey.
- **Yazılım kaynakları:** Kullanılan kütüphaneler, hazır uygulamalar ve süreçler.
  - Örnek: Bir fabrika sistemi muhasebeyi sıfırdan yazmaz, hazır muhasebe sistemi entegre eder.
- **İnsan kaynakları:** Bilgi sisteminin tarafları; sahibi, tasarlayanı, kullananı, bakımını yapanı.
- **Veri kaynakları:** Verinin tutulduğu veri tabanı, bilgi tabanı, veri ambarı veya NoSQL ortamı.
- **Ağ kaynakları:** İşletme içi ve dışı birimleri bağlayan yapılar ve protokoller.
- Bilgi sistemleri katmanlıdır. Sipariş, stok, üretim ve hammadde alt sistemleri birbirini besleyebilir.

### Sistemlerin teorik özellikleri

- Sistemler girdiyi çıktıya dönüştürür. Bilgi sistemi veriyi bilgiye dönüştürür.
- Disiplinler arasıdır. Bir alandaki ürün başka bir alanda kullanılabilir.
- Elemanlar arasında etkileşim vardır. Bir bileşendeki değişiklik bağlı bileşenleri etkiler.
- Farklı elemanlardan oluşur. Örnek: Demir, deniz ve hava yolunu birlikte kullanan bir taşımacılık sistemi.
- Hiyerarşiktir ve ortama göre düzenlenir. Windows'ta çalışan bir sistem Linux'a doğrudan taşınamayabilir.
- Hoca ortamla ilişkiyi entropi kavramıyla bağladı.
- Her sistemin bir amacı olmalıdır.

### Ders sonrası notlar

- **Kitabın adı:** Satzinger, Jackson ve Burd'un kitabının adı *Systems Analysis and Design in a Changing World*. Derste "System Analysis" diye söylendi.
- **Entropi:** Derste "ortamla olan ilişkiye entropi diyoruz" dendi. Sistem teorisinde entropi, sistemin düzensizliğe ve çözülmeye doğru gitme eğilimidir.
  - Açık sistemler ortamdan enerji, madde veya bilgi alarak bu eğilimi yavaşlatır. Bu karşı eğilime negatif entropi (negentropi) denir.
  - Yani entropi ortamla ilişkinin adı değildir. Ortamla etkileşim, entropiyle başa çıkmanın yoludur.
- **"Dizge" ve program:** Hoca öz Türkçede program kodlarına "dizge" dendiğini söyledi.
  - TDK'da "dizge" sözcüğü "sistem" karşılığıdır.
  - Öz Türkçede "program" için önerilen karşılık "izlence"dir.
  - Bilişimde karakter dizisi (string) için "dizgi" kullanılır.
- **Dünya savaşlarının nedenleri:** Hocanın "1. Dünya Savaşı hammadde, 2. Dünya Savaşı pazar paylaşımı" açıklaması bilginin önemini anlatmak için yapılmış bir basitleştirmedir. Savaşların nedenleri tarihçilerce çok daha karmaşık değerlendirilir.
- **Altyazı hataları:**
  - Hocanın e-posta adresi altyazıda bozuk geçiyor ("G1. G2. G2..."). Adresi ders duyurularından kontrol edin.
  - "Rototip" kelimesi "rotatif"tir.
  - Altyazıda "NovaSQL" geçiyor; kastedilen NoSQL.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
