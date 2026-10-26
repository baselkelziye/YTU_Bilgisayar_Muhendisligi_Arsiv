# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 7 Mart 2023 Salı. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:07:18'de başlar.
  - 01:23:20-01:25:18 arasında hoca bölümdeki bir anons (yangın tatbikatı) için kısa ara verdi.
- Bilgi sistemi türleri
  - Amaca göre altı tür ve dört seviye.
  - İşlemsel, ofis otomasyon, bilgi tabanlı iş, yönetim bilgi, karar destek ve üst yönetim bilgi sistemleri.
  - Türler arasındaki girdi-çıktı ilişkileri ve uzman sistemler.
- Bilgi sisteminin tarafları
  - Kullanıcı, yönetici (proje yöneticisi ve üst düzey yönetici), sistem analisti, tasarımcılar ve yazılım mimarı, yazılımcılar, destek personeli.
- Bilgi sistemi geliştirme süreci
  - Problem tanımı, fizibilite, analiz, tasarım, gerçekleştirme, bakım; yaşam döngüsü.
- Süreç modelleri
  - Şelale (waterfall) ve varyasyonları, prototip, artımlı ve spiral modeller.
  - Unified Process, aykırı programlama (XP) ve çevik (agile) yöntemler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgi sistemlerini amaçlarına göre türlere ayırıyoruz. Literatürde altı tür var.
  - Bir sistem başka türlerin özelliklerini de taşıyabilir; sistem, genel amacının türünde sınıflandırılır.
- Karar destek sistemi yalnızca öneri üretir; son kararı yönetici verir.
  - Hocanın anlatımında uzman sistem ise kararı otomatik uygular.
- Kullanıcı (müşteri) sistemin varoluş sebebidir.
  - Kullanıcının beklentileri ve başarı ölçütleri net ve tam belirlenmeli, kullanıcıya onaylatılmalı.
  - Kullanıcı için sistem bir kara kutudur. Teknik ayrıntılarla değil, işlev, doğruluk ve kullanım kolaylığıyla ilgilenir.
- Sistem analisti bu dersin odak noktasıdır.
  - İş birimi ile teknik ekip arasında köprü ve tercümandır.
  - Yönetici kademelerine çoğunlukla analistler yükselir; "analistlik deyip geçmeyin".
- Üst düzey yönetici (sponsor) için en önemli şey maliyet-fayda analizidir.
- Bu dersin temel süreç modeli şelale modelidir.
  - Projenin doğasına göre uygun model seçilmelidir. Çevik yöntemler yaygın olsa da şelale bazı durumlarda daha uygun olabilir.
- Proje grup önerileri için son gün 14 Mart.
  - Farklı ders gruplarından öğrencilerin aynı proje grubunda olması normalde istenmiyor.

## Kısa Tekrar Notları

- **Bilgi sistemi türleri (alttan üste):**

  | Seviye | Tür | İngilizce |
  | :--- | :--- | :--- |
  | İşlemsel | İşlemsel Bilgi Sistemi (İBS) | Transaction Processing System (TPS) |
  | Bilgi | Ofis Otomasyon Sistemi (OOS) | Office Automation System (OAS) |
  | Bilgi | Bilgi Tabanlı İş Sistemi (BTİS) | Knowledge Work System (KWS) |
  | Yönetim | Yönetim Bilgi Sistemi (YBS) | Management Information System (MIS) |
  | Yönetim | Karar Destek Sistemi (DDS) | Decision Support System (DSS) |
  | Stratejik | Üst Yönetim Bilgi Sistemi (ÜBS) | Executive Information/Support System (EIS/ESS) |

- **Türler arası akış:**
  - İBS herkese çıktı üretir; üst yönetime doğrudan değil.
  - Karar destek sistemi YBS, BTİS ve İBS'den beslenir; yalnızca ÜBS'ye çıktı verir.
  - ÜBS, YBS ve karar destek sisteminden beslenir; çıktısını üst yönetime verir.
- **Taraflar:**
  - Kullanıcı
  - Yönetici (proje yöneticisi, üst düzey yönetici/sponsor)
  - Sistem analisti
  - Tasarımcılar (veri tabanı, ağ, web, grafik, güvenlik) ve yazılım mimarı
  - Yazılımcılar (sistem, veri tabanı programcıları, test personeli)
  - Destek personeli
- **İşlevsel gereksinim:** Sistemin ne yapacağı.
- **İşlevsel olmayan gereksinim:** Performans gibi teknik beklentiler. Örnek: dakikada 15 bin ders kaydı.
- **Geliştirme adımları:**
  1. Problem tanımı
  2. Fizibilite
  3. Analiz
  4. Tasarım (genel ve ayrıntılı)
  5. Gerçekleştirme (kodlama, test)
  6. Bakım
- **Süreç modelleri:**
  - Şelale (klasik)
  - Yinelemeli şelale
  - Prototip
  - Artımlı
  - Spiral
  - Unified Process (RUP)
  - XP
  - Çevik (Scrum, Kanban, Lean)

## Detaylı Açıklamalar

Ders üç başlıkta ilerledi: bilgi sistemi türleri, bilgi sisteminin tarafları ve bilgi sistemi geliştirme süreci. Hoca dersi ara vermeden, kompakt anlatmaya çalıştı. Bunun amacı, öğrencilerin kaydı sonradan tekrar izleyebilmesiydi.

### Bilgi sistemi türleri ve seviyeleri

- Bütün bilgi sistemlerinin temel girdisi veri ve bilgidir.
  - Temel işlemleri toplama, işleme, saklama ve dağıtmadır.
  - Çıktıları kullanıma sunulan hizmetler ve bilgilerdir.
- Slayttaki piramit, işletme birimlerini (satış-pazarlama, üretim, finans, muhasebe, insan kaynakları) dört seviyede gösteriyor.
- **İşlemsel seviye (pembe), İBS / TPS:**
  - Günlük işleri yürütür: veriyi alır, işler, saklar, iletir.
  - Örnekler: sipariş takibi ve işleme, makine kontrolü, tesis programlama, hammadde hareketleri, nakit yönetimi, bordro, borçlar ve alacaklar muhasebesi, özlük ve öğrenci bilgi sistemi.
  - Hoca bunları "işçi sınıfı" diye niteledi: işin çoğunu bu sistemler yapar.
  - **Turnike örneği:** Kart okutulur, kart kimliği sunucuya gönderilir, geçiş izni kontrol edilir.
    - Giriş kaydı tutulur, "şu an içeride mi?" sorusu cevaplanır.
    - "7 Mart sabah 9-11 arası B kapısından girenler" gibi raporlar üretilir.
- **Bilgi seviyesi (yeşil):**
  - **Ofis otomasyon sistemleri:**
    - Kelime işlem, doküman yönetimi, elektronik takvim, video konferans (Zoom dahil).
    - Ofis paketleri: Word/Excel/PowerPoint, Pages/Numbers/Keynote, Writer/Calc.
    - İşlemsel seviyeye yakın dururlar.
  - **Bilgi tabanlı iş sistemleri:**
    - Yalnızca ham veriyle değil, işlenmiş bilgiyle de çalışır.
    - Örnekler: CAD/CAM, simülasyon, sanal ve artırılmış gerçeklik uygulamaları (tıp eğitiminde ameliyat simülasyonu), iş istasyonlarında finansal analiz.
    - **Borsa örneği:** Borsa verisi ham veridir. "İskenderun Demir Çelik depremden sonra üretimi durdurdu" haberi ise bilgidir. İkisini birleştiren model fiyat tahmini üretebilir.
- **Yönetim seviyesi (mavi):**
  - **Yönetim bilgi sistemleri:**
    - Orta ve alt kademe yöneticilerin işlerini yürütmesini sağlar.
    - Örnekler: satış yönetimi, envanter kontrolü, yıllık bütçeleme, yatırım analizi.
    - Alttaki sistemlerle entegre çalışır. Veri tabanına, bazen veri ambarına (data warehouse, DWH) ihtiyaç duyar.
    - Birimler arası bilgi akışını yönetir. Örnek: Ar-Ge'nin uygulama indirme sayılarını izleyen projesinin satış-pazarlamaya açılması.
  - **Karar destek sistemleri:**
    - Veri, bilgi ve kullanıcı girdisiyle yöneticinin kararına destek olan öneriler üretir.
    - İstatistik, optimizasyon, makine öğrenmesi, olasılık ve finansal analiz yöntemleri kullanır.
    - Grafik arayüzler, raporlama, tahminleme, hedef arama ve optimizasyon çıktıları üretir.
    - Örnek: Bir yılın satış ve sipariş verisine bakıp tencere mi tava mı üretileceğini önermek. Yönetici öneriye uymak zorunda değildir.
- **Stratejik seviye (turuncu), ÜBS:**
  - CEO, CIO, CFO, CTO ve yönetim kurulu için hazırlanır.
  - Pazar analizi, 5 yıllık satış tahmini, bütçe ve kâr planlama, rakip analizi, risk ve fırsat değerlendirmesi yapar.
  - Veri madenciliği, OLAP küpleri, drill-down analizleri ve dashboard'lar kullanılır.
  - Genellikle şirket içinde (in-house) geliştirilir; piyasada hazırı az bulunur.
- **Karma sistemler:** Bir İBS içinde de makine öğrenmesi kullanılabilir.
  - Örnek 1: Makinede kestirimci bakım (predictive maintenance) yapan bir izleme sistemi.
  - Örnek 2: Geçmiş notlara göre ders öneren bir öğrenci bilgi sistemi.
  - Bu sistemler yine İBS olarak sınıflandırılır.

### Bilgi sisteminin tarafları

- **Kullanıcı:**
  - Müşteriyle eş anlamlıdır; en değerli taraftır.
  - Beklentiler ve başarı ölçütleri belirlenmeli, kullanıcıya onaylatılmalıdır.
  - Örnek: "Saniyede 3000 kayıt" ölçütü, 10 bin öğrencinin 50 bin ders seçeceği bir sistemde yetmeyebilir.
- **Yönetici:**
  - **Proje yöneticisi:** Genelde teknik kökenlidir. İnsan kaynağını, zaman planını ve işlerin sırasını yönetir. Gerekince planı değiştirir.
  - **Üst düzey yönetici (sponsor, "patron tayfası"):** Projenin bedelini karşılar. Maliyet-fayda analizi onun için en önemli şeydir.
- **Sistem analisti:**
  - Hem teknik bilgiye hem iş ve yönetim bilgisine sahip olmalıdır.
  - İş birimi ile teknik ekip arasında tercümanlık yapar.
  - **Tarım örneği:** Çiftçinin sulama ve gübreleme anlatımını debimetre, nem sensörü ve alarm gereksinimlerine çevirmek.
  - **İzlediği yol:**
    1. Problemi araştırır ve anlar.
    2. Maliyet-fayda analizi yapar.
    3. Gereksinimleri belirler.
    4. Alternatif çözümler üretir ve en iyisini gerekçesiyle seçer.
    5. Seçtiği çözümün ayrıntılarını ortaya koyar.
    6. Çözümün uygulanmasını sağlar.
    7. Sonuçları izler.
  - **Gereken beceriler:**
    - Analitik düşünme
    - Teknik bilgi (dil, framework, protokol seçimleri)
    - Yönetim ve iş bilgisi (organizasyon, sektör, kurum kültürü, risk ve değişim yönetimi)
    - İyi insan ilişkileri
  - Çalışanların teknoloji düzeyini bilmelidir. Örnek: RFID kullanamayacak bir depo ekibine barkod önermek.
  - Bütün ilerlemeyi belgelemelidir. Analist ayrılırsa proje başka biriyle devam edebilmelidir.
- **Tasarımcılar:**
  - Veri tabanı tasarımcısı ve yöneticisi
  - Ağ mimarı
  - Web ve mobil mimar
  - Grafik tasarımcı
  - Güvenlik uzmanı
  - Özel teknolojilerin uzmanları
- **Yazılım mimarı (software architect):**
  - İşlevsel gereksinimlerin nasıl ve hangi altyapıyla karşılanacağını tasarlar.
  - İşlevsel olmayan gereksinimleri (performans gibi) de karşılamak zorundadır.
  - Bileşenleri, dağıtımı ve haberleşmeyi kurgular.
- **Yazılımcılar:**
  - Sistemi kodlar. İyi yazılımcı optimize, entegre edilebilir, taşınabilir, değiştirilebilir ve dokümante edilmiş kod yazar.
  - Bu şemsiyenin altında sistem programcıları, veri tabanı programcıları ve test personeli de vardır.
- **Destek personeli:**
  - Sistemi ayakta tutar: ağ, donanım ve yazılım izleme, ürün desteği, güvenlik, web arayüzü takibi ve entegrasyonların sürekliliği.

### Bilgi sistemi geliştirme süreci

- **Adımlar:**
  1. **Problem tanımı:** İhtiyaçlar kabaca belirlenir.
  2. **Fizibilite:** Kapsam ve hedefler belirlenir, rapor üretilir.
  3. **Analiz:** Çözüm önerisi ve mantıksal model hazırlanır.
  4. **Genel tasarım:** Maliyet ve üst düzey yapı belirlenir.
  5. **Ayrıntılı tasarım:** Modüller, veri tabanı, protokoller, girdi ve çıktı tasarımları yapılır.
  6. **Gerçekleştirme:** Kodlama, yapılandırma ve test yapılır; sonunda çalışan sistem ve dokümantasyonu çıkar.
  7. **Bakım:** Sistem çalışır hâlde tutulur.
- Süreç tek yönlü değil, bir döngüdür. Yeni istek veya hata çıktığında kapsam ve planlamaya geri dönülür. Sistem kullanımdan kaldırılınca döngü kırılır.
- **Şelale (waterfall):**
  - 1970'lerde ortaya çıktı. İnşaat mühendisliğindeki sıralı işleyişten esinlendi: zemin etüdü, plan, tasarım, inşa, test, kullanım.
  - Adımlar sırayla, geri dönmeden işlenir.
- **Varyasyonlar:**
  - Yinelemeli (iteratif) şelalede önceki adımlara geri dönülebilir.
  - Prototip modelde taslak tasarımdan bir model kurulur. Model sürüm sürüm (v0, v1, v2...) geliştirilir.
- **Evrimsel süreçler:**
  - **Artımlı model:** Şelale tekrar tekrar uygulanarak ürün büyütülür.
  - **Spiral model:** Altı faz döngüsünden oluşur: müşteri iletişimi, planlama, risk analizi, mühendislik, gerçekleştirme ve müşteri değerlendirmesi. Ürün her turda olgunlaşır.
- **Unified Process (RUP):**
  - 2000'lerde öne çıktı. Kullanım senaryosu (use case) güdümlüdür, mimari merkezlidir, artımlı ve yinelemelidir.
  - Dört faz ve birden çok iterasyon vardır. Her iterasyonda analiz, tasarım, gerçekleştirme ve test farklı ağırlıklarla yapılır.
- **Aykırı programlama (Extreme Programming, XP):**
  - **Dört değer:** İletişim, basitlik, geri besleme, cesaret. Bu değerlere bağlı 12 pratik var.
  - **Önemli pratikler:**
    - Eşli programlama (pair programming)
    - Ortak kod sahipliği
    - Kodlama standartları
    - Test güdümlü geliştirme
    - Sürekli entegrasyon
    - Küçük sürümler
    - Refactoring
    - Sabit, sürdürülebilir çalışma temposu (haftada 40 saat)
  - Bugünkü CI/CD ve DevOps süreçlerinin kökü buradadır.
- **Çevik (agile) yöntemler:** XP'den sonra yaygınlaştı. Scrum, Kanban ve Lean en bilinenleridir.

### Ders sonrası notlar

- **CI/CD:** Derste "Continuous Integration, Continuous Development" dendi. CD, Continuous Delivery (sürekli teslim) veya Continuous Deployment (sürekli dağıtım) demektir.
- **Unified Process fazları:** Standart adları Inception, Elaboration, Construction, Transition'dır.
  - Türkçe karşılıkları: başlangıç, ayrıntılandırma (olgunlaştırma), inşa (yapım), geçiş.
  - Derste ikinci faz "geliştirme", üçüncüsü "üretim" diye söylendi. Hoca anlatımın devamında "olgunlaştırma" ifadesini de kullandı.
- **Uzman sistem:** Literatürde uzman sistem, bir alan uzmanının bilgisini bilgi tabanı ve çıkarım motoruyla taklit eden sistemdir. Tanı koyma ve öneri üretme gibi işler yapar.
  - Kararı otomatik uygulaması tanımın zorunlu parçası değildir. Hocanın anlattığı otomatik proses kontrolü, uzman sistemin bir kullanım biçimidir.
- **Şelale modelinin kökeni:** Model genellikle Winston Royce'un 1970 tarihli makalesine dayandırılır.
  - Royce bu makalede saf sıralı modelin riskli olduğunu söylemiş, geri besleme döngüleri önermişti.
- **XP'nin değerleri:** Kent Beck XP'nin sonraki baskısında beşinci değer olarak saygıyı (respect) ekledi.
- **Sürüm numaraları:** Hocanın "çok parçalı sürüm numaraları aykırı programlamadan gelir" yorumu basitleştirmedir. Yaygın şema anlamsal sürümlemedir (MAJOR.MINOR.PATCH). Derleme numarası isteğe bağlı bir ektir.
- **Altyazı hataları:**
  - "Pay Programming" doğrusu pair programming.
  - "RUB" doğrusu RUP (Rational Unified Process).
  - "Scram" doğrusu Scrum.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
