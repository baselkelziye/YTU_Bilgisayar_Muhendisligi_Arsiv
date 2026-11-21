# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin içeriği ve kapsamı (ekrandan, 00:05:00 - 00:40:00)
  - Ders 12 ana başlık altında ilerler. Slaytlarda görülen başlıklar şunlardır:
    - 1. Yazılım geliştirme ve kalite yaklaşımı: yazılım mühendisliğinde kalitenin yeri, yazılım geliştirme süreç modelleri, çevik yaklaşımlarda kalite bakış açısı, test güdümlü yazılım geliştirme (Test Driven Development).
    - 2-3. Yazılım kalite özellikleri (McCall sınıflaması, kalite özellikleriyle yazılım ölçütlerinin ilişkilendirilmesi) ve yazılım kalitesini sağlama aktiviteleri (kalite standartları, gözden geçirme ve onaylama). <!-- BELİRSİZ: 2. ve 3. başlıkların slayt metni karelerde okunmadı; başlıklar hocanın anlatımından alındı. -->
    - 4. Yazılım inceleme: temel kavramlar, incelemenin önemi, genel yazılım inceleme süreci, Fagan incelemesi, inceleme ekibi.
    - 5. Geçerleme ve doğrulama teknikleri (verification & validation).
    - 6. Yazılım testi: test süreci adımları; birim test, bütünleme testi, regresyon testi, sistem testi, onaylama testi.
    - 7. Test teknikleri: saydam kutu testi, kara kutu testi (hoca gri kutu testini de ekledi).
    - 8. Hata giderme (debugging): hata düzeyleri.
    - 9. Yazılım ölçümü ve güvenilirlik: kalite ölçütleri, McCabe ve Halstead metrikleri, yazılım güvenilirliği modelleri. <!-- BELİRSİZ: 9. başlığın slayt metni karelerde okunmadı; içerik hocanın anlatımından alındı. -->
    - 10. Yazılım test planlama ve yönetim: test yönetimi, test planı, test senaryoları, test çalışma ekibi yapısı.
    - 11. Yazılım teslim sonrası kalite sağlama: yazılım bakımı, yazılım konfigürasyonu.
    - 12. Kalite iyileştirme: CMMI, CMMI yeterlilik düzeyleri, CMMI anahtar süreç alanları, CMMI süreç alanları sınıflaması, People CMM.
- Yazılım gereksinimlerinin hatırlatılması
  - İşlevsel (functional) gereksinimler, yapılacak işin tanımıyla ilgilidir. Her gereksinim maddesi net, kısa cümlelerle yazılır. Liste modüllere ayrılarak ya da baştan sona numaralandırılarak verilir.
  - İşlevsel olmayan (non-functional) gereksinimler kalite özelliklerine benzer. Uygulamaya özgü değildir, yazılımın teknik özellikleriyle ilgilidir: güvenilirlik (reliability), doğruluk, güvenlik (security), hız ve performans, bağlantının kesilmemesi gibi.
  - Her yazılımda bu özelliklerin hepsi aynı ağırlıkta istenmez; bazı yazılımlarda bazı kalite özellikleri öne çıkar.
- Test süreci ve test tekniklerine ilk bakış
  - Birim testte test verisinin hazırlanması ve henüz test edilmemiş alt fonksiyonların yerine ne konacağı önemlidir.
  - Bütünleme testinde yukarıdan aşağıya ya da aşağıdan yukarıya strateji seçilir.
  - Regresyon testi bütünleme testinden sonra bir birimde değişiklik yapıldığında uygulanır.
  - Sistem testi, yazılımın içinde bulunduğu sistemle uyumlu çalışıp çalışmadığını gösterir.
  - Onaylama (kabul, acceptance) testi gereksinim spesifikasyonuna göre yapılır: kullanıcının başta istediklerinin hepsi yapıldı mı?
  - Saydam kutu testi iç yapıyı, kara kutu testi dışarıdan görünen davranışı sınar.
- Yazılım mühendisliğinde kalitenin yeri (ekrandan, 00:55:00)
  - Yazılım mühendisliği bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim bilim dallarından yararlanır ve sorun çözümünde mühendislik yöntemlerini kullanır.
  - Temelinde kalite bakış açısı olan, mühendislik yöntemleri, süreçler, metodolojiler ve yazılım araçlarından (CASE tool) oluşan katmanlı bir yapısı vardır.
- Yazılım mühendisliğinin katmanlı yapısı (ekrandan, 01:00:00, Şekil 1.1)
  - Alttan üste: kalite bakış açısı, süreçler, yöntemler, yazılım araçları.
- Süreç adımları
  - Esas süreç adımları: gereksinim analizi, tasarım, kodlama, test, bakım. Bunlar yazılımın hazırlanması için temel işlemlerdir.
  - Destek süreç adımları: proje yönetimi, kalite yönetimi, geçerleme ve doğrulama, formal ve teknik gözden geçirme, yazılım konfigürasyon yönetimi, yeniden kullanılabilirlik yönetimi, yazılım ölçümü, risk yönetimi. <!-- BELİRSİZ: destek adımları listesi slaytın küçük önizlemesinden ve anlatımdan okundu. -->
- Yazılım geliştirme süreç modelleri (ekrandan, 01:05:00)
  - Süreç modeli, yazılım geliştirme süreci adımlarının hangi sırada ve düzende uygulanacağını tanımlar.
  - Başlıca modeller: klasik doğrusal akış (Waterfall), prototip model, artımlı (incremental) model, helezon (spiral) model, hızlı uygulama geliştirme (Rapid Application Development), birleştirilmiş süreç (Unified Process) modeli.
  - Bütün modellerde analiz, tasarım, gerçekleştirme ve test vardır; modeller bu adımların dizilişi ve destek aktivitelerinin nasıl yerleştirildiğiyle ayrılır.
- Spiral model (ekrandan, 01:10:00 ve 01:15:00)
  - Altı aşama: müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve değişim (construction & release), müşteri değerlendirme.
  - Halkalar: kavram geliştirme projesi, yeni ürün geliştirme projesi, ürün zenginleştirme projesi, ürün bakım projesi.
- Çevik modeller
  - XP (Extreme Programming) ilk kullanılan çevik modellerdendir; bugün en çok Scrum kullanılır; Kanban da yaygındır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım mühendisliğinin tanımı
  - Yazılım mühendisliği, kaliteli yazılımı en ekonomik olarak elde etmek üzere mühendislik yöntem ve tekniklerinin kullanılmasıdır.
  - "Kaliteli" kısmı kalite yönetimi ve test tekniklerine, "en ekonomik" kısmı (en ucuz değil, en faydalıyı en iyi maliyetle) proje yönetimine karşılık gelir.
- Mühendisliğin iki ayağı: tasarım ve ölçüm
  - "Mühendis" kelimesi hendese yapan, ölçen biçen anlamına gelir; ölçüm (software metrics) yazılım mühendisliğinin konularından biridir.
  - Tom DeMarco: "Ölçemediğinizi yönetemezsiniz."
- Kullanıcı testinde kara kutu testi
  - Kullanıcı iç yapıyla ve algoritmanın iyiliğiyle değil, yazılımın gereksinimlerine uyup uymadığıyla ilgilenir; bu yüzden kullanıcı testinde kara kutu testi daha uygundur.
- Spiral modelin maliyeti
  - Spiral model daha sağlam ilerler ama çok emek ve süre ister; prototipte bile risk analizi gerekir. Bu yüzden genellikle hata açısından kritik yazılımlarda kullanılır, küçük ya da hızla ürüne dönüşmesi gereken projelerde kullanılmaz.
- Testin model içindeki yeri
  - Waterfall'da test sürecin sonunda yapılır; spiral modelde her çevrimde test yapılır; Unified Process'te ise test daha farklı bir noktada yer alır.

## Kısa Tekrar Notları

- Yazılım mühendisliği = kaliteli yazılım + en ekonomik elde etme + mühendislik yöntemleri.
- Katmanlar (alttan üste): kalite bakış açısı, süreçler, yöntemler, yazılım araçları.
- Esas adımlar: gereksinim analizi, tasarım, kodlama, test, bakım.
- Destek adımlar: proje ve kalite yönetimi, geçerleme/doğrulama, gözden geçirme, konfigürasyon yönetimi, yeniden kullanım, ölçüm, risk yönetimi.
- Test süreci: birim, bütünleme, regresyon, sistem, onaylama (kabul).
- Test teknikleri: saydam kutu (iç yapı), kara kutu (dış davranış), gri kutu.
- İşlevsel gereksinim = işin tanımı; işlevsel olmayan gereksinim = kalite benzeri teknik özellikler.
- Spiral modelin 6 aşaması: müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve değişim, müşteri değerlendirme.
- Çevik: XP, Scrum, Kanban.
- McCabe metriği birim test verisi hazırlamada da kullanılır; Halstead metriği işlemci (operator) ve işlenen (operand) sayımına dayanır.

## Detaylı Açıklamalar

- **Kalite ve test bakışıyla ders planı.** Ders yazılım mühendisliği bilgisinin üzerine kurulur. Önce kalitenin yazılım mühendisliğindeki yeri ve süreç modelleri hatırlatılır, ardından çevik yaklaşımlar ile geleneksel yaklaşımların farkı ve test güdümlü geliştirme ele alınır. Sonra kalite özellikleri (McCall sınıflaması) ve bunların yazılım ölçütleriyle çapraz ilişkisi, kaliteyi sağlama aktiviteleri (standartlar, gözden geçirme/review ve onun daha formal, ayrıntılı hali olan inceleme/inspection, Fagan incelemesi, inceleme ekibinin kurulması), geçerleme ve doğrulama, test süreci ve teknikleri, hata giderme, ölçüm ve güvenilirlik, test yönetimi, teslim sonrası kalite ve son olarak CMMI ile kalite iyileştirme gelir.

- **Test ile hata giderme farkı.** Test hatanın varlığını ortaya koyar; hata giderme (debugging) hatanın yerinin belirlenmesi ve sorunun giderilmesidir. Hata düzeyleri bu bölümde ele alınacaktır.

- **Ölçüm ve güvenilirlik.** Kalite ölçütleri McCall matrisi üzerinden kalite özellikleriyle ilişkilendirilir. McCabe metriği birim test aşamasında test verisi hazırlanırken de kullanılır. Halstead metriği algoritmadaki işlemci ve işlenenleri sayarak yazılımdaki işlem miktarını ölçer. Güvenilirlik kabaca, test sırasında yazılımdan beklenen sonucun alınmasına ve doğruluğuna ne kadar güvenilebildiğidir; arkasında hata sayıları ve belirli süre içindeki hata oranlarına dayanan istatistiksel yazılım güvenilirliği modelleri vardır.

- **Test yönetimi.** Bir kurumda geliştirilen yazılım test aşamasına geldiğinde ekibin nasıl kurulacağı, ayrı bir test grubu olup olmayacağı, hangi testleri kodu yazanların, hangilerini test grubunun yapacağı test yönetiminin konusudur. Test planı, proje planına benzer biçimde hangi testlerin hangi sırada yapılacağını, test takvimini ve hedefleri belirler. Ardından test senaryoları ve raporları hazırlanır. Gereksinim belgesi olmayan bitmiş bir yazılım için gereksinimler tersine mühendislikle (reverse engineering) yeniden çıkarılabilir.

- **Süreç modelleri.** Waterfall doğrusal akıştır. Prototip modelde belli bir noktaya kadar model oluşturulup üzerinde denemeler yapılır. Artımlı model yazılımı bütün olarak değil artımlarla oluşturur. Spiral model yazılımı sürekli evrim geçirerek, sarmal biçimde oluşturur; her sarmalde müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve müşteri değerlendirme tekrarlanır. Mühendislik aşaması gereksinim analizinin bir bölümünü ve tasarımı, yapım aşaması ayrıntılı tasarımı ve kodlamayı, müşteri değerlendirme ise kullanıcı testini kapsar. RAD hızlı yazılım geliştirme içindir; Unified Process UML'e dayalı bir yaklaşımdır. Rekabet ve hızlı üretim baskısı nedeniyle spiral model her yazılım evinde kullanılamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
