# Ders 14 Çalışma Özeti

## Genel Konular

- Bu ders öğrenci proje sunumlarına ayrıldı
  - Öğrenciler kendi seçtikleri bir yazılım üzerinde hazırladıkları test planını, test senaryolarını ve test raporlarını anlattı. Yedi sunum yapıldı: altısı bir yazılımın test sürecini, biri web uygulaması testinin genel türlerini ele aldı.
- Bir stok takip sisteminin test planı ve fonksiyonel entegrasyon testi
  - Test planı başlıkları: proje zamanlaması (test hazırlık, testin gerçekleştirilmesi, test özet raporunun hazırlanıp onaylanması), test kapsamı (fonksiyonel modüller), risk yönetimi, takım kadrosu, test ortamı, test kriterleri, raporlama, hata düzeyleri ve hata süreci.
  - Risk tablosu (ekrandan, 00:10:00) her risk için ihtimal, etki ve önlem planı içerir: takvim (yüksek/yüksek), kilit personelin ayrılması (orta/yüksek), kritik hataların geç bulunması (orta/yüksek), yeni sorunlar nedeniyle gecikme (orta/yüksek), doğal afetler (düşük/orta), kapsamın belirsizliği (orta/orta).
  - Test başlatma kriterleri: ilgili seviyenin test durumları ve senaryoları yazılmış olmalı, test durumları ile ihtiyaçlar arasında izlenebilirlik kurulmuş olmalı, bir önceki test aşaması başarıyla bitmiş olmalı. Tamamlama kriterleri: planlanan birim, entegrasyon ve kabul testleri yapılmış, tüm senaryolar başarıyla sonuçlanmış, 1., 2. ve 3. derece hataların tamamı çözülmüş ve tüm faaliyetler raporlanmış olmalı (ekrandan, 00:15:00).
  - Durdurma kriteri: birinci derece hata bulunursa test durur, hata düzeltilmeden devam edilmez. Tekrar başlatma: birinci ve ikinci derece hatalar düzeltilince kalınan yerden devam edilir.
  - Hata süreci: test uzmanı hatayı raporlar, test koordinatörü onaylar ya da geri gönderir, geliştirme lideri hatayı geliştiriciye atar, geliştirici düzeltir, test uzmanı yeniden test eder ve regresyon testi yapar; başarılıysa hata kapanır, değilse süreç geliştirme liderine döner.
  - Test case alanları (ekrandan, 00:20:00): use case no, test case no ve adı, amaç, test tipi, test fazı, ön koşullar, test adımları, beklenen sonuç, sonuç (Pass/Fail), ekstra not, kanıtlar, oluşturulma ve test tarihi. Fail olan senaryoya mutlaka açıklama ve kanıt (ekran görüntüsü, GIF) eklenir.
  - İki fazlı fonksiyonel entegrasyon testi: birinci fazda 1 kritik, 2 yüksek, 4 minor hata; regresyondan sonra ikinci fazda 3 minor hata bulundu.
  - React projesinde birim testi için Jest (test koşucu ve assertion kütüphanesi) ile Enzyme (React bileşenlerini izole test etmek için) kullanıldı: 9 modül için 9 test dosyası ve 31 test case'in tamamı geçti. Kullanıcı kabul testinde 29 case başarılı oldu.
- Bir psikolojik envanter (MMPI) uygulamasının birim, entegrasyon ve son kullanıcı testi
  - Birim testinde, verilen yanıtlara göre hesaplanan ölçek değerlerinin elle hesaplanan beklenen değerlere eşit olup olmadığı Django'nun unit test altyapısıyla kontrol edildi.
  - Entegrasyon testinde web servisine JSON ile POST isteği atılıp yanıtın durum kodu ve içindeki değerler `assertContains` ile kontrol edildi (ekrandan, 00:35:00).
  - Son kullanıcı testinde arayüzden form gönderilip tablo ve grafiklerin doğru çıkıp çıkmadığına bakıldı.
- Web uygulaması testi türleri
  - Yayın sonrası bulunan hatanın düzeltme maliyetinin tasarımda bulunandan 4-5 kat fazla olduğu alıntılandı (ekrandan, 00:40:00).
  - Fonksiyonellik testi bir kara kutu testidir: girdiler ve çıktılara bakılır, iç kod bilinmez. Örnekler: sayısal alana negatif sayı girme, hatalı değerde uyarı mesajı, butonların çalışması (ekrandan, 00:45:00).
  - Performans testi teknikleri (ekrandan, 00:50:00): yük (load), stres (stress), dayanıklılık (soak/endurance) ve ani yük (spike) testi.
  - Diğer türler: kullanılabilirlik, uyumluluk (farklı cihazlarda doğru görüntülenme), veritabanı testi, arayüz testi.
- Bir randevu sisteminin test planı
  - Entity modülleri beyaz kutu (unit test), kullanıcı arayüzü tarayıcı üzerinden kara kutu olarak test edildi (ekrandan, 00:55:00).
  - Geçti/kaldı kriterleri: tüm unit testler koşmuş ve geçmiş olmalı; akışı bozmayan minor hatalar kabul edilir, sistem çökmesine yol açan hiçbir hata kabul edilmez; beşten fazla unit test kalırsa ilgili modül yeniden gözden geçirilir.
  - Durdurma nedenleri: donanım sorunları, acil kod değişiklikleri, deployment sorunları, prosedür sorunları.
  - Büyük sürümlerde tüm sistemde regresyon, küçük sürümlerde modül bazında test yapılır. 83 unit test 780 ms'de geçti.
  - Ortam gereksinimleri (ekrandan, 01:00:00): fonksiyonel test verisi elle yaratılır, unit test verisi otomatik üretilebilir, özel donanım gerekmez, framework sürüm uyumluluğu risktir. Test production ortamında değil test ortamında yapılmalıdır.
- Axios kütüphanesinin Jest ile testi
  - Bir mock API'ye GET, POST, PUT, DELETE istekleri atılıp dönen değerler API belgesiyle karşılaştırıldı.
  - Jest eşleştiricileri: `toBe`, `toBeCloseTo`, `toEqual`, `toStrictEqual`, `toHaveProperty`, `toMatchSnapshot`, `toThrow`. Kurulum: paketi eklemek, `package.json` içine `"test": "jest"` betiğini yazmak, `npm test` ile koşmak.
- Bir iş/staj portalının testi
  - Test seviyeleri: birim, sistem, kabul, beta ve kullanıma alma testleri.
  - Gereksinim tabanlı yaklaşım ve kara kutu yöntemi kullanıldı (ekrandan, 01:15:00); denklik sınıflarına göre test durumları, pozitif ve negatif test durumları yazıldı.
  - Hata dereceleri: 1. derece genel çalışmayı doğrudan etkiler, 2. derece bazı işlevleri etkiler, 3. derece yalnız görseldir.
  - Unit test için MS Test, arayüz testi için Selenium IDE kullanıldı; Selenium IDE senaryoyu adım adım otomatik oynatıp log üretir.
- Makine öğrenmesi tabanlı bir emlak fiyat tahmin uygulamasının testi
  - Çıktı kesin bilinemediği için beklenen sonuç bir aralık olarak verildi. Dört unit testten biri geçti, üçü aralık dışı kaldı (ekrandan, 01:25:00).
  - Beta testinde hatalı biçimli girdilerde (oda sayısını "3" ya da harf olarak girmek) program uyarı vermeden durdu; ürünün piyasaya hazır olmadığı sonucuna varıldı (ekrandan, 01:30:00).
- Bir stok dağıtım (alokasyon) sisteminde sevk yasağı yönetiminin testi
  - Kısıtların insan kontrolüne bırakılmayıp sistemsel yönetilmesi gerekir (ekrandan, 01:35:00).
  - Gereksinimler kullanıcı hikayeleriyle toplandı. Strateji: birim, bütünleme, sistem ve kullanıcı kabul testi, hepsi manuel; 4 modülde 6'şar, toplam 24 test case (ekrandan, 01:40:00).
  - Ortamlar: geliştirme, test, UAT, canlı ve canlıya yakın release candidate ortamı. Test ve UAT'de bulunan hata "failure", canlıda bulunan hata "bug" olarak kaydedilir. Kritik, yüksek ve düşük kayıtların çözüm süreleri 1, 4 ve 8 saattir.
  - Test ortamı 4 çekirdek/8 GB, canlı ortam 7 çekirdek/32 GB (ekrandan, 01:45:00). Sistem testinde test ortamında zaman aşımı alındı; sorunun koddan mı ortamdan mı kaynaklandığını ayırmak için test release candidate ortamında tekrarlandı ve başarılı oldu.
  - Yaşanan riskler: test uzmanının ayrılması ve yedek olmaması, ortamın birden fazla projece paylaşılması, paydaşların kabul testine zaman ayırmaması, gözden kaçan bir hatanın yasal cezaya yol açması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Gerçek hayattaki test belgesi formatı
  - Hoca ilk sunumun test planı ve fonksiyonel test belgelerinin kendi verdiği formattan farklı ama profesyonel hayata uygun bir formatta hazırlandığını, diğer öğrencilerin de bu gerçek hayat formatını görmesi için sunumu kesmediğini söyledi.
- Araçların nasıl kullanıldığının gösterilmesi
  - Hoca, raporlar zaten teslim edildiği için sunumda kullanılan test araçlarının nasıl kullanıldığının anlatılmasını istedi; genel anlatım yapan sunumda da uygulamadan örnek istedi.

## Kısa Tekrar Notları

- Test planı: zamanlama, kapsam, risk yönetimi, kadro, ortam, kriterler, raporlama, hata düzeyleri, hata süreci.
- Risk tablosu: risk, ihtimal, etki, önlem planı.
- Test kriterleri: başlatma, tamamlama, durdurma, tekrar başlatma.
- Bir sonraki faza geçmeden önce önceki fazın hataları düzeltilip regresyonu yapılır.
- Fail olan test case'e açıklama ve kanıt eklenir.
- Fonksiyonellik testi kara kutu testidir.
- Performans testi: load, stress, soak (endurance), spike.
- Beyaz kutu için unit test, arayüz için kara kutu test.
- Test production ortamında yapılmaz.
- Makine öğrenmesi çıktısında beklenen sonuç aralık olarak verilebilir.
- Negatif test durumları hatalı girdide sistemin davranışını sınar.
- Failure (test/UAT) ve bug (canlı) ayrımı; çözüm süreleri önem derecesine bağlanır.
- Test ortamı canlıdan zayıfsa performans sonucu kesin değildir; canlıya yakın ortamda tekrar edilir.

## Detaylı Açıklamalar

- Test planı ve risk yönetimi: İlk sunumda test planı IEEE tarzı başlıklarla kuruldu. Risk tablosunda takvim riski en yüksek risk sayıldı, çünkü tasarım ve geliştirmedeki gecikmeler testin süresinden yenir ama teslim tarihi çoğu zaman değişmez. Önlem olarak düzenli toplantılar planlandı. Kilit personel riski için bilgi yedeklemesi, yani her kilit kişinin bir yedeğinin olması önerildi. Kritik hataların geç bulunması, düzeltme, regresyon ve etkilenen alanların yeniden testi gerektirdiği için tüm planı etkiler; bu yüzden ikinci fazda kritik hata çıkmaması hedeflenir.
- Test case belgesi: Bir ürün ekleme modülünün test case'lerinde adımlar ("Ürün Adı" alanına adı yaz, kategoriyi seç, birim fiyatı, miktarı ve stok miktarını yaz) ve beklenen mesajlar yazıldı. Standart kullanıcının ürün ekleme ve silme birimlerine erişmemesi gerektiğini sınayan senaryo Fail oldu: standart kullanıcı yetkisi olmayan birimlere erişebiliyordu, bu da SRS'teki kurallara aykırıydı (ekrandan, 00:20:00).
- Entegrasyon testinde beklenen değerler: MMPI uygulamasının entegrasyon testi, web servisine kullanıcı yanıtlarını gönderip yanıtın durum kodunun 200 olduğunu ve "metrics", "KTable" başlıklarıyla ölçek değerlerini içerdiğini kontrol etti. Birim testi fonksiyonların, entegrasyon testi web servisinin veriyi doğru alıp fonksiyonlara doğru iletmesinin ve yanıtı doğru döndürmesinin sınanmasıdır.
- Emlak fiyat tahmini: Doğrusal regresyonla çalışan uygulamada bina yaşı artırılınca fiyatın düşmesi beklenirken yükselmesi, küçük dairede tahminin aralığın altına, çok büyük dairede üstüne çıkması, veri setindeki gürültülü veriye ve verinin tek kaynaktan alınmasına bağlandı. Nadir görülen girdiler için veri azlığı tahmini zayıflatır.
- Ortam ve risk: Son sunumda test ortamı canlıdan zayıf olduğu için büyük veriyle yapılan sistem testinde zaman aşımı alındı. Release candidate ortamında test başarılı olunca, canlı ortamın daha fazla kaynağı olduğu gerekçesiyle onay verildi. Paylaşılan ortamlar, kaynak eksikliği ve kabul testinin ciddiye alınmaması gerçek hayatta yaşanan riskler olarak anlatıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
