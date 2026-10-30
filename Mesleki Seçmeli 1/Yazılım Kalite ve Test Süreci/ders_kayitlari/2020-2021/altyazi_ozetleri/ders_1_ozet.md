# Ders 1 Çalışma Özeti

## Genel Konular

- Bu ilk derstir. Ders yeni Zoom sistemiyle, ekran paylaşımı yapılmadan işlenir.
- Hoca dersin yazılım mühendisliği dersinin devamı olduğunu anlatır. Yazılım mühendisliğindeki destek süreçlerinden kalite yönetimi ve test burada ayrıntılı işlenecektir.
- Dönem boyunca işlenecek yaklaşık 8 bölüm sıralanır.
- Dersin değerlendirmesi açıklanır: bir ara sınav (vize), bir final ve bir grup projesi. Not dağılımı bir sonraki derste konuşulacaktır.
- Grup projesinin kapsamı anlatılır: var olan bir yazılımın gereksinim listesi, test planı, test raporları ve sunumu.
- Yazılım mühendisliğinin tanımı, katmanlı yapısı, süreç adımları ve destek süreçleri (umbrella activities) hatırlatılır.
- Klasik ve çevik (agile) yazılım geliştirme süreç modelleri kısaca sayılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu ders yazılım mühendisliği bilgisini varsayar. Yazılım mühendisliği dersini almamış olanlar (ör. Erasmus ile başka üniversitede alanlar) hocaya e-posta atmalıdır. Hoca eksiklerin nasıl tamamlanacağını ayrıca söyleyecektir.
- Yazılım sektöründe artık ayrı yazılım kalite ve test birimleri vardır. Büyük firmalar ve yazılım evleri bu ekipleri ayrı kurar. Dersin içeriği bu ekiplerde çalışacak kişilerin bilmesi gereken konulardır.
- Bazı firmalarda sistem analizini yapan ekip ile kullanıcı testini yapan ekip zaman zaman birleştirilir.
- Hoca, sektörden (TÜBİTAK Marmara'daki kalite grubu gibi) en az bir konuğu derse davet etmeyi planlar. Konuk, test senaryolarının nasıl oluşturulduğunu ve test süreçlerinin nasıl yönetildiğini anlatacaktır.
- Tasarım kalıpları (design patterns) bu dersin konusu değildir. O konu nesneye yönelik tasarım ve yazılım mühendisliği derslerine aittir.
- Gereksinim listesi en az 50-70 madde olmalıdır. Çok küçük bir yazılım seçmeyin.
- Hazırlık: bir sonraki derse kadar yazılım mühendisliği notlarındaki kaliteyle ilgili bölümleri tekrar edin ve proje grubunuzu kurun.

## Kısa Tekrar Notları

- Yazılım mühendisliği tanımı (hocanın kısa tanımı): bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim dallarından yararlanan; kaliteli yazılımı en ekonomik şekilde elde etmek için mühendislik yöntemlerini kullanan bilim dalıdır.
- Yazılım: bir problemin bilgisayara aktarılması ve çözülmesi için gerçekleştirilen uygulamalardır.
- Yazılım mühendisliğinin katmanları (alttan üste): kalite bakış açısı, süreçler (process), yöntemler (methods), araçlar (tools).
- Temel süreç adımları: gereksinim analizi, tasarım, gerçekleştirme (kodlama), test. Sonrasında bakım.
- Destek süreç adımları (umbrella activities): proje yönetimi, kalite yönetimi, geçerleme ve doğrulama (validation, verification), formal teknik gözden geçirme, konfigürasyon yönetimi, yeniden kullanılabilirlik (reusability) yönetimi, yazılım ölçümü, risk yönetimi.
- Gereksinim tipleri:
  - İşlevsel (functional): yazılımın yaptığı işle ilgili. Örnek: öğrenci bilgi sistemi harf notunu doğru hesaplasın.
  - İşlevsel olmayan (non-functional): işe bağlı olmayan genel özellikler. Örnek: güvenirlik (reliability), kullanıcı dostu olma, güvenlik (security), hızlı yanıt.
- Klasik süreç modelleri: şelale (waterfall), prototip, artımlı (incremental), spiral, hızlı uygulama geliştirme (Rapid Application Development, RAD), birleşik süreç (Unified Process).
- Çevik modeller: Scrum, Kanban, XP (Extreme Programming).

## Detaylı Açıklamalar

### Dersin bölümleri

Hoca dersi yaklaşık 8 bölüme ayırır:

1. Yazılım geliştirme süreçlerine genel bakış ve kalitenin önemi. Spiral model, çevik yaklaşımlar ve çevik projelerde test süreci. Test güdümlü geliştirme (Test Driven Development, TDD).
2. Yazılım kalitesinin temel kavramları. Kalite etkenleri ve kalite özellikleri. McCall modeli ve kalite faktörleri ile yazılım özellikleri arasındaki ilişki matrisi. Hoca McCall'a göre kalite etkenlerini sınavlarda da sorduğunu söyler.
3. Geçerleme ve doğrulama (verification, validation). Kalite yönetim sistemi. Gözden geçirme (review), onaylama ve inceleme. Testin süreçteki yeri: "test en sonda yapılır" düşüncesi doğru mu? TDD gibi süreçle birlikte giden test.
4. İnceleme (inspection). Gözden geçirme ile inceleme farkı. Kod inceleme. Fagan'ın önerdiği inceleme süreci. İnceleme ekibinin kurulması. Teknik inceleme.
5. Test adımları ve test teknikleri (kapsamlı bölüm):
  - Test süreci adımları: birim testi (unit test), bütünlük testi (integration test), regresyon testi (regression test), sistem testi, onaylama testi (acceptance test).
  - Test tipleri: kara kutu (black box), gri kutu (grey box), saydam kutu (white box).
6. Yazılım kalite ölçümü (software metrics). Kalite ölçütleri ve metrikler. Halstead metrikleri, McCabe karmaşıklık ölçüsü. Yazılım güvenirliği (reliability) ve güvenirlik modelleri. Hoca güvenirliği ayrı bir bölüm sayılabilecek kadar önemli bulur.
7. Test planlama ve yönetim. Test ekibinin ve aktivitelerinin yönetimi, test planı, test senaryosu, test sonuç raporu. Teslim sonrası kalite: bakım, konfigürasyon yönetimi, bakım maliyetini azaltma.
8. Kalite iyileştirme: CMMI, yeterlik düzeyleri, anahtar süreç alanları (key process areas), People CMM.

Ölçmenin önemi:

- Bitirdiğimiz yazılımı değerlendirmek için ölçeriz.
- Başlayacağımız yazılımın değerini (maliyetini) tahmin etmek için ölçeriz.
- Kaynakları yönetmek için ölçeriz.

### Grup projesi

- Grup 4 kişidir. Yazılımın kapsamı büyükse 5 kişi olabilir; 5'ten fazla olamaz. 5 kişilik grup daha fazla test yapmalıdır.
- Gruplar kendi üyelerini seçer. Hoca, grubu olmayanları en son kendisi birleştirecektir. Hoca rastgele atamayı tercih etmez, çünkü bu durumda işi bırakan üyeler çıkar.
- Test edilecek yazılım: grup üyelerinden birinin önceki projesi, başka bir derste üretilmiş proje veya seçilen başka bir yazılım olabilir.
- Yazılım mühendisliği projesinden farkı: orada yazılım geliştiriliyordu. Burada var olan bir yazılım test edilir.
- İstenenler:
  - Gereksinim listesi ve gereksinim raporu (50-70 madde).
  - Gereksinim listesine dayalı kullanıcı testi (zorunlu).
  - Grubun seçimine göre birim testi veya sistem testi. Birim testi için kaynak kodun elinizde olması gerekir. Sistem testi; dayanıklılık, sistemle uyum gibi sistem testi tiplerini içerir.
  - Test planı, test raporları ve sonuç raporu.
  - Sunum (bir veya iki ders ayrılacak). Gereksinimden sorumlu üye yazılımı ve gereksinimleri tanıtır. Grup test ekibini ve yaptığı testleri açıklar.
- Hoca, 7. bölümde işlenecek test planı ve test raporu bilgisinin bu projede uygulanmasını bekler.
- Raporların e-postayla mı yoksa sisteme mi yükleneceğine sonra karar verilecektir.

### Diğer duyurular

- Hoca derse devamı takip etmek için ders içinde küçük quizler yapabileceğini söyler.
- Dersin içindekiler slaytı sisteme yüklenecektir. Derslerde slayt dışında konular da anlatılacaktır.
- Hoca e-posta adresini derste paylaşır (altyazıda adres eksik çıkmıştır).
- Bu ders bölümde 2012'den beri seçmeli ders olarak verilmektedir. Hoca daha önce yüksek lisans düzeyinde de vermiştir.

### Ders sonrası notlar

- Whisper bazı adları bozmuştur. Doğruları: "Makkol" McCall, "Makkep" McCabe, "hashtag metriği" muhtemelen Halstead metrikleri, "Spray/Sprower model" spiral model, "Reizability/J-Yuzubility" reusability, "Presma" Pressman, "Summerville" Sommerville.
- Altyazıda dersin adı "yazılım kayıta" diye geçer; doğrusu "yazılım kalite"dir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
