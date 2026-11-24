# Ders 3 Çalışma Özeti

## Genel Konular

- Bu derste konu anlatımı yoktur. Gruplar dönem projelerinin yazılım kalite ve test sunumlarını yapar.
  - Her sunum aşağı yukarı aynı iskeleti izler: yazılımın tanıtımı, gereksinim listesi ya da gereksinim spesifikasyonu, test planı ve test stratejisi, birim testi, fonksiyonel (kara kutu) testler, varsa performans ve yük testleri, test sonuçları.
- 1. grup: bir ATM otomasyonu (Java masaüstü uygulaması, PostgreSQL veritabanı).
  - Kullanıcı tipleri: bireysel kullanıcı (TC kimlik numarasıyla) ve şirket (vergi numarasıyla).
  - İşlevler: kayıt, giriş, para yatırma, para çekme, başka kullanıcıya para gönderme. Çekme ve göndermede komisyon alınır; komisyon kullanıcı tipine göre değişir.
  - Fonksiyonel olmayan gereksinimler: her yaştan kullanıcının kullanabileceği anlaşılır arayüz, güvenlik, güvenilirlik, kullanılabilirlik ve bankacılıkla ilgili yasal gereksinimler.
  - Test edilen modüller: kullanıcı girişi, para aktarma, müşteri, ayarlar ve para yatırma.
  - Test stratejisi (ekrandan, 00:10:00): test case'ler analizden sonra manuel koşulmuş, code coverage oranı gözetilerek kritik modüllerin tamamı test edilmiştir. Yazılımın yalnız yapması gerekenler değil, yapmaması gerekenler de test case'lere dahil edilmiştir. Toplam 43 fonksiyonel test case Jira formatına uygun belgelenmiştir.
  - 43 testten 36'sı geçmiş, 7'si bilerek başarısız bırakılmıştır (örneğin geçersiz karakter girildiğinde işlem yapılmıyor ama kullanıcıya uyarı çıkmıyor; bakiye yetersizken işlem gerçekleşiyor; komisyonla bakiye eksiye düşüyor).
  - Performans hedefi: yanıt süresinin (response time) 100 ms'nin altında olması.
  - Proje dışı ek gösterimler: Selenium ile web arayüz (UI) otomasyonu, Postman ile açık kaynak bir müzik servisi API'si üzerinde API testleri ve Postman Runner ile API otomasyonu, Jenkins ile otomasyonun depodan tetiklenmesi.
- 2. grup: taksi bulma sistemi (Python, daha önce bir veritabanı dersi için yazılmış proje).
  - Hedefler: müşterinin semte göre müsait taksi bulması, şoförün talepleri görüp yanıt vermesi ve kendi müsaitlik durumunu güncellemesi, yöneticinin taksi kaydı ve müsaitlik yönetimi.
  - Kullanıcı senaryoları (taksi çağırma, durak semte hizmet vermiyorsa anlaşmalı durağa yönlendirme, hatalı giriş durumları), fonksiyonel ve fonksiyonel olmayan gereksinimler (performans, güvenilirlik, görünüm ve kullanım, güvenlik, sürdürülebilirlik, taşınabilirlik, kullanılabilirlik, operasyonel, yasal).
  - Test planı: dört modül (yönetici, kullanıcı, taksi durum güncelleme, taksi listeleme ve çağırma), üç derecelik hata sınıflandırması, risk yönetimi tablosu, test ortamı ve test sonuç raporu.
  - Python `unittest` modülüyle 42 birim testi yazılmış ve hepsi geçmiştir. Ayrıca kullanıcı testi yapılmıştır.
- 3. grup: sözcük çözümleyici (lexical analyzer), Java.
  - Derleyicinin aşamaları: sözcük (lexical), sözdizimi (syntax) ve anlam (semantic) çözümleme. Proje ilk aşamaya odaklanır: kaynak kodu sözcüklere (lexeme) ayırıp her birine bir token sınıfı (anahtar kelime, özel sembol, tanımlayıcı, operatör, sayı, karakter katarı vb.) atar.
  - Fonksiyonel gereksinimler: ondalıklı sayı, karakter katarı, tam sayı, değişken ve tanımsız sözcükleri tanıma; satır içinde doğru sözcük ayrımı; kod bloğu içindeki sözcük tiplerini doğru ayırma.
  - Performans gereksinimi (ekrandan, 00:40:00): art arda sık gelen kod satırlarıyla dolu bir kod bloğunu çözümleyebilme. Güvenlik gereksinimi: farklı kullanıcıların girişini test edebilme, yönetici olarak çalıştırma modunu görebilme. Ayrıca arayüz ve uyumluluk (Windows ve Linux) gereksinimleri.
  - JUnit ile birim testleri ve arayüz üzerinden bütünleme (integration) testleri yazılmıştır. Bütünlemede hata çıkan yerlere onaylama testi uygulanmıştır.
  - Performans ölçümü: 100 kod bloğu verildiğinde işlem 32-34 ms arasında sürmüştür.
- 4. grup: "Marketim" adlı, küçük esnaf için stok, satış ve gelir-gider takip uygulaması (Node.js REST API ve React istemci).
  - Gereksinimler modüllere ayrılmıştır: tedarikçiler, ürünler (benzersiz barkod, alış/satış fiyatı, KDV oranı, stok), müşteriler (alacak/verecek), satış (nakit, kredi kartı, veresiye), kasa.
  - İşlevsel olmayan gereksinimler: modül modül ayrı paneller (kullanıcı arayüzü), kullanıcı adı ve şifreyle giriş (güvenlik), belirli aralıklarla yedekleme (güvenilirlik), en az 1000 eş zamanlı kullanıcıya yanıt (performans).
  - Test tamamlanma kriterleri ve üç derecelik hata sınıflandırması; uygulama üzerinde canlı kara kutu test senaryoları.
  - Birim testleri Mocha ve Chai ile (16 testten 15'i geçmiş), sistem testleri Postman ile, yük testleri Apache JMeter ile yapılmıştır.
- 5. sunum (tek kişi): kütüphane sistemi (Java, JUnit).
  - Kullanıcı tipine göre kitap ve süre limitleri, yalnız öğretim üyelerine verilen ders kitapları, yöneticinin limitleri değiştirmesi, geç iadede ceza, stok kontrolü için birim testleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Projenin amacı büyük bir yazılım geliştirmek değil, test sürecini uygulamaktır.
  - Hoca öğrencilerin daha önce geliştirdikleri ve gereksinimini bildikleri bir projeyi seçmelerini, bunun için gereksinim spesifikasyonu yazmalarını ya da var olanı kullanmalarını, sonra birim testi, kullanıcı testi ve performans testi yapmalarını bekler.
  - Projeyi test edebilmek için çok sayıda modül eklemek ya da projeyi baştan yazmak dersin hedefinden sapmadır. Gereksinim listesi gerekiyorsa açık kaynak bir projeden (örneğin bir kod deposundan) da alınabilir.
- Birim testi her projede beklenir. Hoca birim testi yapmayan gruba bunu ayrıca sorar.
- Birim testi yalnız slaytta değil, testin yazıldığı geliştirme ortamında (IDE) gösterilmelidir.
- Görev paylaşımı (kimin hangi testi yaptığı) sunumda açıkça söylenmelidir.
- Gereksinimler alt alta, madde madde listelenmelidir.

## Kısa Tekrar Notları

- Test yaklaşımı: yazılımın yapması gerekenler kadar yapmaması gerekenler de (negatif test) test case olarak yazılır.
- Code coverage, testlerin kodun ne kadarını çalıştırdığını gösterir; kritik modüller önceliklidir.
- Hata derecelendirmesi (2., 4. grup ortak):
  - 1. derece: sistemin çalışmasını doğrudan etkiler.
  - 2. derece: sistem çalışır ama bazı işlevler aksar.
  - 3. derece: yalnız görsel/estetik hata.
- Test tamamlanma kriteri örneği: planlanan yazılım, sistem ve kabul testleri yapılmış, tüm test durumları başarıyla sonuçlanmış, 1., 2. ve 3. derece hataların hepsi çözülmüş olmalıdır.
- Bir test durumu (test case) belgesinde: başlık, öncelik, numara, test türü, yürütme türü (manuel/otomatik), açıklama, test adımları, test verisi, beklenen sonuç. Hata raporunda: test durumu numarası, hata önem derecesi, açıklama, hatayı oluşturma adımları, beklenen ve gerçek sonuç.
- Jira biçimli test case tablosu kolonları: test adı, özet, beklenen sonuç, öncelik, proje, durum (başarılı/başarısız), raporlayan, test seti.
- HTTP durum kodu 200 olması API'nin çalıştığını gösterir ama doğru sonuç ürettiğini göstermez; yanıt gövdesi de kontrol edilmelidir.
- Araçlar: JUnit (Java), `unittest` (Python), Mocha + Chai (Node.js), Selenium (web arayüz otomasyonu), Postman (API/sistem testi, Runner ile tekrarlı koşum), Apache JMeter (yük ve performans testi), Jenkins (otomasyonun sürekli tetiklenmesi), Jira (test case ve hata takibi).
- Otomasyonun amacı: regresyon testlerinde tekrarlanan testlerde zaman kazanmak ve insan hatasından kaçınmak.

## Detaylı Açıklamalar

- **Negatif test ve bilerek başarısız bırakılan testler.** 1. grup, ATM uygulamasında yazılımın yapmaması gereken davranışları da test case olarak yazmıştır. Bakiye yetersizken işlemin gerçekleşmesi ya da komisyonla bakiyenin eksiye düşmesi beklenmeyen durumlardır; bu testler başarısız (fail) olarak raporlanmıştır. Demoda 500 TL yatırılıp 200 TL çekilince 1 TL komisyonla 299 TL kalır; 150 TL gönderilince 2 TL komisyonla bakiye 147 TL'ye iner ve alıcının bakiyesi 150 TL artar.
- **Jira biçimi.** Grup test case'lerini, şirketlerde yaygın kullanılan Jira biçimine uygun bir tabloda tutmuştur. Test seti kolonu, testleri türüne göre gruplar (örneğin fonksiyonel testler bir set, performans testleri başka bir set).
- **Selenium ile web arayüz otomasyonu.** Bir e-ticaret sitesinde giriş yapma, arama kutusuna ürün yazma, ikinci sayfaya geçme, ürünü sepete ekleyip silme adımları kodla otomatikleştirilmiş ve günlük (log) kaydı alınmıştır. Bu otomasyon bir kod deposuna konunca Jenkins ile tetiklenip herkes tarafından istenen anda çalıştırılabilir.
- **Postman ile API testi.** Açık kaynak bir müzik servisi API'sinde her istek için üç test case yazılmıştır: durum kodunun 200 olması, yanıt gövdesinde beklenen verinin bulunması (örneğin takip edilen sanatçılar listesinde belirli bir sanatçının olması) vb. API doğru çalışmazsa 400'lü ya da 500'lü durum kodları döner. Postman Runner ile istekler seçilip yineleme sayısı, gecikme süresi ve veri dosyası verilerek toplu koşturulur.
- **Python `unittest` ile birim testleri.** 2. grup taksi bulma sisteminin modüllerini 42 birim testiyle sınamış, test sonuç raporunda amaç, kapsam, tanımlar, kullanılan donanım ve yazılım, test sonuç tabloları ve hata bildirim tablosuna yer vermiştir.
- **Sözcük çözümleyicinin birim testi.** 3. grubun ekranda gösterdiği test durumunda (ekrandan, 00:45:00) `assertEquals(Token.FLOAT, automaton.evaluate(" 100.888"));` komutu çalıştırılır. Başta boşluk olduğu için beklenen `FLOAT` yerine `INVALID` döner; hata raporunda önem derecesi "Kritik" olarak yazılmıştır.
- **Arayüz üzerinden bütünleme testi.** 3. grup arayüze kod yazdırıp çözümle düğmesine bastıran ve dönen token tablosunu satır satır karşılaştıran testler yazmıştır (ekrandan, 00:50:00). Örneğin `if ( 2 * 3 = 6 ) \n print ( "six" )` girdisinde sırayla INTEGER, INTEGER, INTEGER, LEFT_PARENTHESIS, RIGHT_PARENTHESIS, TIMES, KEYWORD, EQUAL, KEYWORD, STRING, LEFT_PARENTHESIS, RIGHT_PARENTHESIS tokenları beklenir. <!-- BELİRSİZ: Kodda beklenen token sırası girdideki sözcük sırasıyla örtüşmüyor; ekrandaki assert listesi olduğu gibi aktarıldı. -->
- **Mocha ve Chai.** Mocha, Node.js'te ve tarayıcıda çalışan, senkron ve asenkron fonksiyonları test etmeye izin veren bir test çatısıdır; Chai ise onunla kullanılan bir doğrulama (assertion) kütüphanesidir. `describe` bloğunda testin adı verilir; veritabanına istek gönderilip yanıt beklendiği için test fonksiyonları `async` yazılır.
- **JMeter ile yük testi.** Test planı oluşturulur, thread grubunda sanal kullanıcı sayısı (örneğin 100) verilir, değişkenler için veri seti ve JSON gövde için HTTP Header Manager (`Content-Type: application/json`) eklenir, HTTP isteği örnekleyici (sampler) olarak eklenir. Çalıştırınca veritabanına 100 müşteri eklendiği doğrulanmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
