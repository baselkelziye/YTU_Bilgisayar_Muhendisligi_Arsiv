# Ders 2 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumları: yazılım test sürecinin uygulanması
  - Bu derste gruplar, mevcut bir yazılım üzerinde yürüttükleri test çalışmalarını sundu. Her grup üç belge hazırladı: yazılım gereksinim spesifikasyonu (SRS), test planı ve test sonuç raporu.
  - Projede en az iki test türü istendi: birim testi ile sistem testi ya da birim testi ile kullanıcı testi. Hoca, testlerin yalnız rapor üzerinden değil, canlı çalıştırılarak gösterilmesini istedi.
  - Kod geliştirmek projenin amacı değildir. Görev, var olan kodun nasıl test edildiğini göstermektir. Birim testi yazılırken kod zaten kullanılır.
- Java Swing ile yazılmış bir uçuş takip simülasyonunun testi
  - Birim testleri JUnit 5 (Jupiter) ile yazıldı. JUnit, Gradle yapı dosyasına bağımlılık olarak eklendi. `@Test` ile test işaretlendi, `@Order` ile testlerin sırası belirlendi, `Assertions.assertEquals` statik olarak içe aktarıldı.
  - Örnek hata: güzergah ekleme ekranında süre olarak 0 dakika girilebiliyor. Test bu kaydın oluşmamasını bekliyor, program izin verdiği için test başarısız oluyor (ekrandan, 00:05:00).
  - Zamanlayıcı testi: hiç şehir yokken zamanlayıcı durdurulunca uçuş listesi güncellenirken `NullPointerException` oluşuyor (ekrandan, 00:05:00).
  - Sistem testi: arayüz bileşenleri getter metotlarıyla alınıp `doClick()` ve `setText()` ile otomatik olarak kullanıldı. Ayrıca görüntü tanımaya dayalı SikuliX aracı denendi.
  - Dayanıklılık (robustness) denemesi: kayıt dosyasının bazı baytları bozuldu. Program istisnayı yakalayıp dosyayı yok sayarak çalışmaya devam etti. Dosya nesnesinin kapatılmadığı ise iki test art arda çalıştırılınca ortaya çıktı.
- Web tabanlı bir Spider Solitaire oyununun testi (React)
  - SRS'te kullanıcı ihtiyaçları, sayfa bazında fonksiyonel gereksinimler ve fonksiyonel olmayan gereksinimler (uyumluluk, taşınabilirlik, güvenlik, performans, kapasite, yerelleştirme, ölçeklenebilirlik, kullanılabilirlik, erişilebilirlik, sürdürülebilirlik) yazıldı.
  - Kara kutu testi kullanım durumu (use case) temelli test tasarımıyla yapıldı: kart seçimi, kart hamlesi, ipucu, kart dağıtma, seri tamamlama, hatalı yerleştirme, oyunu tamamlama, kaybetme ve geri alma testleri.
  - Birim testi Jest ile yazıldı: 3 test dosyası, 23 test. Satır kapsamı yaklaşık %71 (ekrandan, 00:30:00).
  - Arayüz (uçtan uca) testi Cypress ile yapıldı. Toplam 32 test vardı, farklı ekran boyutlarında da denendi.
  - Performans testi Google Lighthouse ile yapıldı. First Contentful Paint ve Largest Contentful Paint ölçüldü.
- ASP.NET Core ile yazılmış bir kitapçı Web API'sinin testi
  - Test planında tamamlanma, başlatma, durdurma ve yeniden başlatma ölçütleri, üç seviyeli hata sınıflandırması ve test rolleri tanımlandı.
  - Birim testi xUnit.net ile yazıldı. Toplam 13 test durumu vardı. Birden çok girdiyle çalışan testlerde `[Theory]` ve `[InlineData]`, tek durumlu testlerde `[Fact]` kullanıldı.
  - Kullanıcı testi Swagger arayüzünden GET ve POST istekleriyle yapıldı. Başarılı yanıt HTTP 200 kodu döndü.
- Bir anomali tespit servisinin (PyOD) testi
  - Modülün işlevleri şunlardır: algoritma seçme, algoritma ayarları, `fit`, `predict`, karar puanı (`decision_function`), veri üretme, model kaydetme ve yükleme, toplu (batch) tahmin.
  - Birim, entegrasyon ve sistem testleri yapıldı. Entegrasyon testleri servise istek atıp yanıtı denetledi. Test sınıfı bittiğinde `tearDown` ile servis kapatıldı.
  - Bazı testler hata davranışını göstermek için bilerek başarısız yapıldı: olmayan model dosyası, yanlış biçimde veri (2 boyut beklenirken 1 boyutlu dizi) ve yanlış algoritma adı.
  - Kapsam yalnız birim testleri için hesaplandı.
- C# ve MySQL ile yazılmış bir hastane yönetim sistemi masaüstü uygulamasının testi
  - Test planında fonksiyonel test, arayüz testi, performans testi, uyumluluk testi, kullanılabilirlik testi ve güvenlik testi tanımlandı.
  - Birim testleri C# birim testi projesiyle yazıldı. Kara kutu testleri bir tabloda toplandı: test durumu, hata ciddiyeti, adımlar, test verisi, beklenen ve gerçekleşen sonuç (ekrandan, 01:25:00).
  - Güvenlik testinde veritabanına yetkisiz işlem, uzun girdilerle bellek taşması (buffer overflow) ve iki pencerede aynı anda işlem yaparak yarış durumu (race condition) denendi.
- Bir borsa takip sisteminin testi (Spring tabanlı Web uygulaması)
  - Kullanım senaryolarında ana akış ile alternatif akış (hatalı e-posta biçimi, aynı kodlu hisse) yazıldı.
  - Entegrasyon testleri Postman ile yapıldı: kayıt, giriş, erişim belirteci (access token) alma ve bu belirteci başlığa ekleyerek yetkili işlemler.
  - Bir portföyde bulunan hisse silinmeye çalışıldığında yabancı anahtar kısıtı yüzünden HTTP 500 hatası alındı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Testler çalıştırılarak gösterilmeli
  - Rapor zaten teslim ediliyor. Sunumda bir testin hangi araçla ve nasıl çalıştırıldığı gösterilmeli ki diğer öğrenciler de görsün.
  - Benzer durumları tekrarlamaya gerek yok. Her test türü için bir örnek yeterli.
- Fonksiyonel test dışarıdan görünen davranışı sınar
  - Arayüzden bir gereksinimi yerine getiren adımları otomatik çalıştıran test (ör. SikuliX ile) fonksiyonel test sayılabilir. Bu test, bir fonksiyonun dışarıdan bakıldığında beklenen sonucu verip vermediğine bakar.
- Kapsam (coverage) araçla ölçülür
  - Derslerde sözü edilen test kapsamı, Jest gibi araçlarla yüzde olarak otomatik hesaplanabilir. Araç, test edilmeyen satırları da gösterir.
- Kullanıcı testi tablolaştırılmalı
  - Kullanıcı testinde her durum için tahmin edilen (beklenen) değer ile gerçekleşen değer bir tabloda karşılaştırılmalıdır. Laboratuvardaki çalışma da bu biçimdeydi.
- Test planı özetlenmeli
  - Kullanım senaryolarını tek tek okumak yerine test planındaki test türleri özetlenmeli. Plandakilerden en az ikisi çalıştırılarak gösterilmeli.

## Kısa Tekrar Notları

- Proje belgeleri SRS, test planı ve test sonuç raporudur.
- JUnit 5: `@Test`, `@Order`, statik `assertEquals`. Swing arayüzü `doClick()` ile otomatik kullanılabilir.
- SikuliX, ekrandaki nesneleri görüntüden tanıyıp fareyle tıklamayı ve yazı yazmayı otomatikleştirir.
- Jest birim testi yapar ve kapsam raporu verir. Cypress, Selenium benzeri bir uçtan uca test çatısıdır. Lighthouse ise ön yüz performansını FCP ve LCP gibi metriklerle ölçer.
- xUnit: `[Fact]` tek durum içindir. `[Theory]` ile `[InlineData]` aynı testi birden çok veriyle çalıştırır.
- Negatif test: geçersiz girdide hata beklenir. Hata gelirse test geçer.
- Entegrasyon testinde servis ayağa kaldırılır, istek atılır, yanıt denetlenir. Sonunda `tearDown` ile kapatılır.
- Hata ciddiyeti genelde Critical, High, Medium ve Low olarak sınıflanır. Sistemin ana işlevini engelleyen hata Critical sayılır.
- Güvenlik testinde yetkisiz erişim, bellek taşması ve yarış durumu denenir.
- Postman ile REST uçları test edilir. Yetki gerektiren isteklerde erişim belirteci başlıkta gönderilir.

## Detaylı Açıklamalar

- **Proje çerçevesi.** Bu derste dönem projesinin sunumları yapıldı. Her grup daha önce geliştirilmiş bir yazılımı seçip ona test süreci uyguladı. Önce gereksinimleri SRS belgesinde tanımladılar. Sonra test planında hangi testlerin, hangi araçla, kimin tarafından ve hangi koşullarda yapılacağını yazdılar. Son olarak testleri çalıştırıp sonuçları test sonuç raporunda topladılar. Hoca iki test türü istedi: birim testi ile sistem testi ya da birim testi ile kullanıcı testi. Kod geliştirmek görev değildi. Mevcut kodu test etmek yeterliydi.
- **JUnit ile birim ve sistem testi.** Uçuş takip simülasyonunda (şehir ekleme, şehirler arası güzergah, zamana göre uçuşların izlenmesi) testler JUnit 5 ile yazıldı. Gösterilen test, iki şehir ekledi ve aralarına 0 dakikalık bir güzergah girdi. Sonra güzergah listesinin boş kalmasını `assert` ile denetledi (ekrandan, 00:05:00). Program bu kaydı kabul ettiği için test başarısız oldu. Raporda bu hata için senaryo numarası, test edilen işlem, sonuç ve ciddiyet yazıldı. Sistem testinde arayüzdeki metin alanları doldurulup düğmelere programla tıklandı. Ardından listelerin boyutu ve içerikleri `assertEquals` ile denetlendi (ekrandan, 00:15:00). SikuliX, ekran görüntüsündeki bir nesneyi bulup fareyle tıklayabildiği için arayüz otomasyonu için de denendi. Hoca bu tür testin fonksiyonel test sayılabileceğini söyledi.
- **Kara kutu, birim, arayüz ve performans testi (web oyunu).** Spider Solitaire oyununda kara kutu testleri kullanım durumlarından türetildi. Örneğin ipucu testinde Hint düğmesine basılınca geçerli bir hamle öneren iki kartın vurgulanması beklendi (ekrandan, 00:25:00). Geri alma testinde yalnız bir adım geri gidilebildiği görüldü. Jest raporunda tüm dosyalar için kapsam şöyleydi: Stmts %71,63, Branch %50,63, Funcs %81,25, Lines %70,88 (ekrandan, 00:30:00). Cypress testleri sayfa gruplarına ayrıldı: Finish Page, Rules Page, Component Length, Game Page ve Timer. Lighthouse sonucu ağ, tarayıcı ve eklentilere göre değişir. Araç, puanı artırmak için yapılabilecekleri de söyler (ör. resimleri JPEG yerine WebP gibi daha küçük bir biçimde vermek).
- **xUnit ile parametreli negatif test (Web API).** Kitap oluşturma doğrulaması dört kurala dayanıyordu: tür kimliği 0'dan büyük olmalı, sayfa sayısı 0'dan büyük olmalı, yayın tarihi bugünden önce olmalı ve başlık en az 4 karakter olmalı. `[Theory]` ile verilen her `[InlineData]` satırı en az bir kuralı ihlal eder. Bu yüzden doğrulayıcının hata döndürmesi beklenir ve test başarılı sayılır (ekrandan, 00:50:00). Var olan bir kitabı tekrar ekleyen test ise veritabanında aynı kayıt olduğu için başarısız oldu.
- **PyOD servisi.** SRS, her özellik için açıklama ve öncelik, uyarı-yanıt (stimulus/response) dizisi ve fonksiyonel gereksinimler biçiminde yazıldı (ekrandan, 01:00:00). Test planında efor tahmini adam-saat olarak verildi. Toplam 84 adam-saattir (ekrandan, 01:05:00). Bilerek başarısız yapılan testlerden biri, 1 boyutlu bir dizi verildiğinde scikit-learn'ün `ValueError: Expected 2D array, got 1D array instead` hatasını gösterdi (ekrandan, 01:10:00).
- **Hastane yönetim sistemi.** Kara kutu test tablosunda reçete işlemlerinin çalışmaması Critical olarak işaretlendi, çünkü uygulamanın ana hizmetini engelliyordu. Rapor oluşturma, doktor silme ve ekran büyütme sorunları ise Medium olarak işaretlendi (ekrandan, 01:25:00).
- **Borsa takip sistemi.** Birim testlerinde yetkilendirme katmanı aşılamadı. Bu eksik, entegrasyon testlerinde her uç Postman ile tek tek denenerek kapatıldı. Tarihsel veri ucu, her gün için en düşük, en yüksek, açılış ve kapanış fiyatıyla hacmi döndürüyordu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
