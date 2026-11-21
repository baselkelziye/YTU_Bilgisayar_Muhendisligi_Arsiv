# Ders 13 Çalışma Özeti

## Genel Konular

- Regresyon testi ve regresyon test stratejileri (makale sunumu)
  - Regresyon testi, uygulamada yapılan bir değişikliğin (yeni özellik, düzeltme, konfigürasyon değişikliği) sistemin tamamına ya da ilgili modüllere bir etkisi olup olmadığını görmek için yapılır. Amaç, uygulamanın eski özelliklerini korumaya devam ettiğini ve yeni özelliklerin doğru çalıştığını doğrulamaktır.
  - Ekrandaki şemaya göre (ekrandan, 00:05:00) iki ana strateji vardır: bütün testleri yeniden koşturmak (Retest All) ve seçerek yeniden test (Selective Retest). Seçerek yeniden test üçe ayrılır: Test Case Selection, Test Suite Minimization ve Test Case Prioritization.
  - Bütün test senaryolarını yeniden koşturmak çok zaman alır. Eski senaryolar için yazılmış testler geçerliliğini yitirmiş olabilir, değişmeyen modüllerin testleri de zaman kaybıdır. Bu yüzden seçerek ilerlemek mantıklıdır.
- Test senaryosu seçme teknikleri
  - Araçla yapılan seçim: kontrol akışı tabanlı (control-flow based), metinsel fark tabanlı (textual difference based, kodda statik olarak neyin değiştiğine bakılır), kod varlığı tabanlı (code entity based, değişen sınıf ve fonksiyonlara bakılır), dilimleme tabanlı (slicing based) ve önceliklendirme tabanlı seçim.
  - Araç yoksa sezgisel seçim: en çok hata yakalayan senaryolar, son kullanıcının göreceği ekranlar, entegrasyon testlerinin tamamı, kritik ve etkisi yüksek modüller.
- Test senaryosu önceliklendirmenin (test case prioritization) faydaları
  - Hata tespit oranını artırır.
  - Yüksek riskli hataların test döngüsünün erken aşamasında yakalanmasını sağlar.
  - Teste dahil edilmesi gereken kapsamın daha hızlı belirlenmesine katkı verir.
- Karınca kolonisi optimizasyonu (Ant Colony Optimization, ACO) ile test önceliklendirme
  - Benzetme: karıncalar yuvadan yiyeceğe rastgele yollarla gider; çok kullanılan (ve kısa olan) yolda salgılanan feromon miktarı artar ve sonraki karıncalar bu yolu tercih eder.
  - Test tarafında karşılığı: test senaryoları kombinasyonlar halinde denenir; birçok kombinasyonda birlikte kullanılan senaryonun feromon değeri yükselir.
  - Önceliklendirme kriterleri: senaryonun kapsadığı hata (bug) sayısı, çalışma süresi (execution time), diğer senaryolarla birlikte kullanılma oranı ve buna dayanan feromon değeri.
  - Algoritma döngüsü (ekrandan, 00:10:00): en çok hatayı kapsayan senaryoyu seç, bütün hatalar kapsandı mı kontrol et, kapsanmadıysa kalanları kapsayacak başka senaryo seç, toplam kapsanan hatayı hesapla, her iterasyonda bütün yolları keşfet, ortalama çalışma süresini ve ortalama kullanılma olasılığını hesapla, yolları hesaplanan değerlere göre karşılaştır, en iyi yolu seç ve feromon değerini güncelle. Bütün hatalar kapsandığında algoritma sonlanır.
- Makaledeki örnek sonuç
  - 5 test senaryosu ve yapay olarak oluşturulmuş 6 hata kullanılmıştır. Hangi senaryonun hangi hatayı yakaladığı bir tabloyla gösterilmiştir.
  - En çok kombinasyonda kullanılan (4 kez) ve feromon değeri 1 olan TC03 ilk sıraya, onunla birlikte kalan hataları kapsayan TC01 ikinci sıraya yerleşmiştir. TC03 1, 5 ve 6 numaralı hataları, TC01 2, 4 ve 5 numaralı hataları kapsar.
  - Önceliklendirmesiz tüm senaryolar 19 saniye sürerken önceliklendirmeyle iki senaryo 11 saniyede bütün hataları kapsamıştır. <!-- BELİRSİZ: 0,63 ve 0,55 değerlerinin hangi ölçüt olduğu (büyük olasılıkla APFD benzeri bir oran) altyazıdan net çıkmıyor; tablo değerleri karede okunmadı -->
- Uygulama sunumu 1: Bir seyahat acentesi masaüstü uygulamasının testi
  - C# ve .NET Framework 4.6 ile yazılmış, MySQL veritabanı kullanan, dört modüllü (giriş-çıkış, kullanıcı, ulaşım, bilgilendirme) bir bilgi sistemi test edilmiştir. Üç kullanıcı sınıfı vardır: yetkili sistem personeli, acente görevlisi ve müşteri (müşteri sisteme doğrudan erişmez).
  - Test planı dört aşamalıdır ve her aşamanın sonunda bir kilometre taşı (milestone) vardır (ekrandan, 00:25:00): planlama; kodun incelenmesi ve yerel makinede çalıştırılması; test (birim testi, arayüz testi, sonuçların birleştirilmesi); dokümanların tamamlanması (test planı, test tanımlama ve test sonuç belgeleri).
  - Birim testi Visual Studio test aracı üzerine ReSharper, dotCover ve TestCop eklentileriyle yapılmış; ücretsiz Community sürümü kod kapsamı göstermediği için kapsam eklentiyle ölçülmüş ve yaklaşık %93 kapsama ulaşılmıştır. Panel (arayüz) kısımları stub yazılamadığı için birim testine girmemiştir.
  - Fonksiyonel kullanıcı testinde bulunan iki örnek hata: firma puanına 3.5 girildiğinde listede 35 görünmesi; kullanıcı eklerken istenen uzunlukta ad ve şifre kabul edilmesine rağmen giriş ekranının belirli bir uzunluktan fazla karakter almaması, yani eklenen kullanıcının giriş yapamaması (ekrandan, 00:30:00).
  - Sonuç: birim testinde 2 hata (biri orta, biri yüksek önemde), kullanıcı testinde 3 hata (ikisi yüksek, biri düşük önemde).
  - Test riskleri: test takviminde gecikme (etki yüksek, olasılık orta), test ortamının kurulamaması (etki orta, olasılık düşük), test ekibinden birinin ayrılması (etki yüksek, olasılık düşük). Her risk için neden, önlem ve ilgili taraflar tanımlanmıştır.
- Uygulama sunumu 2: Web tabanlı envanter yönetim sistemi ve PHPUnit
  - PHP (Laravel) ile yazılmış hazır bir envanter yönetim uygulamasının 12 modülü için test planı ve kullanıcı/fonksiyon testleri, 9 modülü için birim testleri yazılmıştır. Toplam 9 test sınıfında 96 doğrulama (assertion) başarılı geçmiştir (ekrandan, 00:50:00).
  - Test senaryoları SRS'teki gereksinimlerden türetilmiştir: örneğin ad-soyad alanının 3 ile 255 karakter arasında olması, geçerli e-posta adresi, şifrenin en az 8 karakter olması ve doğrulama alanıyla aynı olması, 5 hatalı girişte 15 dakika giriş engeli.
  - Birim testinde bir kullanıcı nesnesi alanlarla doldurulup kaydedilir, sonra `assertArrayHasKey` ve `assertEquals` ile alanlar doğrulanır. Tanımlı olmayan fazladan bir alanın (`name2`) kayda girmediği `assertArrayNotHasKey` ve `assertNotEquals` ile kontrol edilir; bu, güvenlik açığı denemesine karşı ters yönden yazılmış bir testtir (ekrandan, 00:55:00).
  - Beklenen değer bilerek değiştirildiğinde testin başarısız olduğu canlı gösterilmiştir.
  - Test yazarken kodda bir tasarım sorunu fark edilmiştir: müşteri kaydındaki belge türü alanı sayısal bir değerdir ama ilişkili bir tabloya bağlı değildir.
- Uygulama sunumu 3: PHP kitap satış sitesi ve envanter uygulaması, PHPUnit ve ApacheBench
  - PHPUnit Composer ile kurulur; `vendor/bin/phpunit` çalıştırılınca `tests` klasöründeki testler koşar. `phpunit.xml` yapılandırma dosyasıyla bütün testler tek seferde çalıştırılabilir (ekrandan, 01:00:00).
  - HTML üreten fonksiyonların çıktısında beklenen etiketlerin (liste için `li`, görsel için `img`) bulunup bulunmadığı `expectOutputString` benzeri çıktı karşılaştırmasıyla test edilmiştir. Oturum (session) durumuna bağlı fonksiyonlar, giriş yapılmış ve yapılmamış iki durumda denenmiştir.
  - Veritabanı bağlantı fonksiyonu ve tablo satır sayısını döndüren fonksiyon için birim testleri yazılmış; bağlantı bilgisi bilerek bozulduğunda testin başarısız olduğu gösterilmiştir (ekrandan, 01:10:00).
  - Sistem (yük/stres) testi ApacheBench (`ab`) ile yapılmıştır: 10 eşzamanlı kullanıcıyla 1000 istek 1,623 saniyede tamamlanmış, saniyede yaklaşık 616 istek karşılanmıştır (ekrandan, 01:05:00). İstek sayısı on katına çıkınca süre doğrusal artmamış, kullanıcı sayısı artırılınca saniyedeki istek sayısı yükselmiştir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Birim testinin nasıl çalıştığının adım adım gösterilmesi
  - Hoca, ekran görüntüleriyle sonuç göstermek yerine bir birim testinin seçilip kodunun ve aracın nasıl çalıştırıldığının ayrıntılı gösterilmesini istedi. Amaç, PHPUnit gibi bir aracın nasıl kullanıldığını bütün sınıfın görmesidir.
- Sistem testi ve sistem testi aracı
  - Hoca sunumlarda sistem testinin ayrıca yer alıp almadığını sordu ve sistem testi için de bir araç kullanılmasını önerdiğini hatırlattı.
- Test raporlarında tek tip format zorunlu değil
  - Hoca farklı bakış açılarının ve sektördeki farklı uygulama biçimlerinin görülmesini daha değerli buldu; bu yüzden test raporu için tek bir format vermediğini söyledi.

## Kısa Tekrar Notları

- Regresyon test stratejileri: Retest All ve Selective Retest (Test Case Selection, Test Suite Minimization, Test Case Prioritization).
- Seçme teknikleri: control-flow, textual difference, code entity, slicing ve önceliklendirme tabanlı.
- Sezgisel seçim: çok hata yakalayan, son kullanıcıya görünen, entegrasyon ve kritik modül senaryoları.
- ACO: çok birlikte kullanılan senaryonun feromonu artar; kriterler kapsanan hata, çalışma süresi, birlikte kullanılma oranı.
- Makale örneği: 5 senaryo, 6 hata; TC03 ve TC01 ile bütün hatalar kapsandı, süre 19 saniyeden 11 saniyeye indi.
- Test planı: planlama, kod inceleme/çalıştırma, test, dokümantasyon; her aşama bir milestone ile biter.
- Belgeler: test planı, test tanımlama, test sonuç belgesi.
- Fonksiyonel testte bulunan tipik hatalar: ondalık değerin yanlış saklanması, kayıt ve giriş ekranlarında alan uzunluğu tutarsızlığı.
- Risk tablosu: risk, etki, olasılık, neden, önlem, ilgili taraf.
- PHPUnit: `assertEquals`, `assertArrayHasKey`, `assertArrayNotHasKey`, `assertNotEquals`, `assertFalse`; `phpunit.xml` ile toplu çalıştırma.
- Testin kendisini sınamak için beklenen değer bilerek bozulur ve testin başarısız olduğu görülür.
- ApacheBench: `ab -k -n <istek> -c <eşzamanlı>`; süre, saniyedeki istek, istek başına süre ve yüzdelik yanıt süreleri raporlanır.

## Detaylı Açıklamalar

- **Regresyon testinde seçim problemi.** Büyük bir uygulamada her değişiklikten sonra bütün test senaryolarını yeniden koşturmak hem çok zaman alır hem de gereksiz olabilir; bazı eski senaryolar artık geçerli değildir, bazıları değişmeyen modülleri sınar. Bu yüzden seçerek yeniden test yapılır. Seçimin bir yolu test senaryosu seçimi (yalnız değişiklikten etkilenen testler), bir yolu test kümesini küçültme (gereksiz tekrarları atma), bir yolu da önceliklendirmedir. Önceliklendirmede bütün testler yine koşturulabilir ama sıraları değişir: yüksek riskli hataları erken yakalayacak senaryolar öne alınır.

- **ACO ile önceliklendirme mantığı.** Karınca kolonisinde kısa ve çok kullanılan yolda feromon birikir. Sunulan makalede bu fikir test senaryolarına uyarlanmıştır: senaryolar hata kapsamına göre kombinasyonlar halinde denenir, birlikte en sık kullanılan senaryonun feromon değeri en yükseğe çıkar. Seçimde yalnız feromon değil, senaryonun kapsadığı hatalar ve çalışma süresi de dikkate alınır. Örnekte TC03 hem en sık kullanılan hem de en yüksek feromonlu senaryo olduğu için ilk sıraya geçmiştir. TC01'in çalışma süresi yüksek, feromon değeri düşük olsa da TC03'ün kapsamadığı hataları kapsadığı için ikinci sıraya alınmıştır. Böylece iki senaryoyla bütün yapay hatalar yakalanmış ve toplam süre kısalmıştır. Bir öğrencinin sorusu üzerine bu bağlantı yeniden açıklanmıştır: feromon, senaryonun kombinasyonlar içinde ne sıklıkla kullanıldığını gösterir; kapsama bilgisiyle birlikte sıralamayı belirler.

- **Seyahat acentesi uygulamasının testi.** Nesneye dayalı yazılmış bir C# uygulamasında birim testi sınıf düzeyinde yapılmıştır. Kod kapsamı ücretsiz geliştirme ortamında gösterilmediği için harici eklentiler kullanılmış, %93 kapsama ulaşılmıştır. Arayüz panelleri için stub yazılamadığından bu kısımlar kapsam dışında kalmıştır. Fonksiyonel testte SRS'teki her gereksinim denenmiştir. Puan alanına 3.5 girilip listede 35 görünmesi, verinin yanlış saklandığını gösteren bir hatadır. Kullanıcı ekleme ekranının uzun ad ve şifre kabul etmesi, giriş ekranının ise bunları girmeye izin vermemesi iki ekran arasındaki tutarsızlıktır; eklenen kullanıcı işlevsiz kalır. Ayrıca çok kısa şifrelerin kabul edilmesi de hata sayılmıştır.

- **Test riskleri.** Risk yönetimi, test sürecinin bir parçası olarak her risk için etki ve olasılık derecesi, olası nedenler, önleme yolları ve riskten etkilenen taraflar belirtilerek yapılmıştır. Takvim gecikmesi gereksinim belgesinin geç hazırlanması ya da ekipte yeterli kişi olmamasından doğabilir; test ortamının kurulamaması araçlarla ilgili tecrübe eksikliğinden doğar ve eğitimle önlenir; ekipten birinin ayrılması çalışan memnuniyetinin artırılmasıyla önlenebilir.

- **PHPUnit ile birim testi.** Laravel tabanlı envanter uygulamasında her modül için bir test sınıfı yazılmıştır. Kullanıcı oluşturma testinde alanlar tanımlanır, nesne doldurulup kaydedilir, ardından her alanın varlığı ve değeri kontrol edilir. Modelde tanımlı olmayan bir alan gönderilip kayda girmediği doğrulanarak beklenmeyen veri gönderimine karşı uygulama sınanmıştır. Beklenen şifre değeri bilerek farklı yazıldığında testin başarısız olması, testin gerçekten bir şey kontrol ettiğini gösterir. Diğer grupta HTML üreten fonksiyonların çıktısı beklenen etiketlerle karşılaştırılmış, oturuma bağlı fonksiyonlar giriş yapılmış ve yapılmamış durumlarda denenmiştir. Veritabanı testlerinde bağlantı bilgisi değiştirildiğinde bağlantı testi başarısız olmuştur.

- **ApacheBench ile sistem testi.** `ab -k -n 1000 -c 10 http://localhost/index.php` komutuyla 10 eşzamanlı kullanıcı 1000 istek göndermiştir. Çıktıda başarısız istek 0, süre 1,623 saniye, saniyede 615,99 istek, istek başına ortalama 16,234 ms (eşzamanlı istekler üzerinden 1,623 ms) görülür (ekrandan, 01:05:00). İki ortalama arasındaki 10 kat fark eşzamanlılık düzeyinden gelir. İstek sayısı artınca süre doğrusal artmamış, kullanıcı sayısı artırıldığında saniyede karşılanan istek sayısı yükselmiştir. Diğer sunumda daha küçük istek sayılarıyla denenmiş ve sürenin istek sayısıyla yaklaşık doğrusal arttığı gözlenmiştir; bu, Apache'nin eşzamanlı istekleri yeterli iş parçacığıyla karşılayabildiği şeklinde yorumlanmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
