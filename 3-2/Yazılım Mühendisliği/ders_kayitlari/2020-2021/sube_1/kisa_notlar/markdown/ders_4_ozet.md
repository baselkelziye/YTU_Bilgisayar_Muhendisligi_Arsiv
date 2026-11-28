# Ders 4 Çalışma Özeti

## Genel Konular

- Gereksinim mühendisliğinin (requirements engineering) adımları (ekrandan, 00:05:00)
  - Genel adımlar: Başlangıç (Inception), Bilgi Toplama (Elicitation), İşleme (Elaboration), Pazarlık (Negotiation), Tanımlama (Specification), Doğrulama (Validation) ve Yönetim (Management).
  - Yönetim yeni bir adım değil, diğer bütün adımların doğru yürütülmesini sağlayan bir etkinliktir.
  - Adımlar, gerçeklenecek yazılımın doğasına ve kullanılan sürece (klasik ya da çevik) göre düzenlenmelidir.
  - Gereksinim mühendisliği boyunca yazılım ekibi ve müşteri birlikte çalışmalıdır; müşterinin bir ekibinin sürecin mümkün olduğunca çok adımına katılması yararlıdır. Analizin amacı problemi bütün ayrıntılarıyla öğrenmektir.
- Başlangıç (Inception)
  - Yazılım projesinin başlatılıp başlatılmayacağına karar verilen adımdır.
  - Projeyi başlatan nedenler: yeni bir iş gereksinimi, mevcut iş süreçlerinde karşılaşılan güçlükler, üst düzey karar vericilerin gördüğü bir ihtiyaç; bir yazılım evi için yeni bir pazarın ya da hizmetin farkına varılması veya genel ihtiyaç olduğu düşünülen bir işi isteyen yeni bir müşteri.
  - Paydaşlar belirlenir: geliştirilecek sistemden doğrudan ya da dolaylı olarak faydalanabilecek herkes paydaştır. Her paydaş sisteme farklı bir açıdan bakar ve projenin başarısı ya da başarısızlığı her paydaşı farklı biçimde etkiler.
  - Örnek: bir işletmede fatura hazırlama işinin paydaşları muhasebe, satın alma, kasadaki görevli ve alışveriş yapan kişidir; olayı her biri kendi bakış açısıyla anlatır.
- Bilgi Toplama (Elicitation) (ekrandan, 00:10:00)
  - Gereksinimler hakkında ayrıntılı bilgi, tüm paydaşların etkin katılımıyla elde edilmelidir.
  - Tüm paydaşların katıldığı toplantılar yapılmalı; toplantılara hazırlık ve katılım kuralları belirlenmelidir.
  - Gündem, önemli konuları atlamayacak kadar sıkı, yaratıcılığı önlemeyecek kadar açık olmalıdır.
  - Düzeni sağlayacak ve tıkanıklıkları çözecek bir oturum başkanı seçilir.
  - Önce her paydaşla tek tek görüşülüp yaptığı iş anlaşılır, sonra ortak toplantı yapılır.
  - Bilgi toplama yolları: birebir görüşme (interview), yerinde inceleme, benzer uygulamaların incelenmesi, yaygın bir kullanıcı ağı varsa anket, kurumun işleyişinin (hangi görevi kimin yaptığı) incelenmesi.
- İşleme (Elaboration) (ekrandan, 00:20:00)
  - Bilgi toplama aşamasında toplanan "ham" bilgiler işlenir; son kullanıcının ve diğer paydaşların yazılımla nasıl etkileşimde bulunacağı belirlenir ve ayrıntılandırılır.
  - Etkileşimler kullanım senaryolarıyla gösterilir (ileride anlatılacak).
  - Kimi bilgiler genişletilir, kimi bilgiler özetlenir.
  - Gereksinimlerin sınıflandırılması: normal gereksinimler; beklenen gereksinimler (kullanıcının belirtmeyebileceği çok temel gereksinimler, bunların da elde edilmesi gerekir); heveslendirici gereksinimler (müşteri beklentilerinin ötesinde, varlığında müşteriyi sevindirecek özellikler).
- Pazarlık (Negotiation) (ekrandan, 00:25:00)
  - Müşteriler sınırlı insan, zaman ve bütçe kaynakları çerçevesinde karşılanamayacak aşırı isteklerde bulunabilir; teknik olarak mümkün olan bir istek bile kaynaklar nedeniyle karşılanamayabilir.
  - Paydaşlar gereksinimleri farklı önem düzeylerinde görebilir; farklı paydaşların gereksinimleri birbiriyle çelişebilir.
  - Pazarlık sonucunda tüm paydaşların razı olacağı bir gereksinimler listesi elde edilir.
  - İki temel ihtiyaç: müşterinin istekleriyle geliştiricinin yapabilecekleri arasında orta yol bulmak; farklı paydaşların çelişen anlatımlarını sadeleştirip süreci tarafsız bir gözle anlamak. Sistem analistleri bu aşamada destek verir.
- Tanımlama (Specification) (ekrandan, 02:30:00)
  - Gereksinimler, pazarlık sonucunda uzlaşılan haliyle kağıda dökülür.
  - Tanımlama araçları: konuşma diliyle yazılmış belgeler (fonksiyonel ve fonksiyonel olmayan gereksinim listeleri), kullanıcı senaryoları, kullanım şemaları, formel modeller (matematiksel gösterim, derste işlenmeyecek) ve bir ön ürün (prototip).
  - Birden fazla tanımlama aracı birlikte kullanılabilir.
- Doğrulama (Validation) (ekrandan, 00:30:00)
  - Tanımlanmış gereksinimlerin tutarsızlıklara karşı sağlaması yapılır: Gereksinimler açıkça ve yoruma yer bırakmayacak şekilde tanımlanmış mı? Birbiriyle çelişen gereksinimler var mı? Gereksinimlerde hatalar ve eksikler var mı? Eksik gereksinimler var mı? Gerçekçi olmayan gereksinimler var mı?
  - Önerilen temel yol teknik değerlendirmedir (formal technical review; sınama teknikleri arasında anlatılacak). Değerlendirilen şey gereksinimi anlatan kişiler değil, gereksinimlerin kendisidir.
- Yönetim (Management) (ekrandan, 00:35:00)
  - Süreç içinde yeni gereksinimler eklenebilir, bazıları geçerliliğini yitirebilir, önem sırası değişebilir, hatalı tahminler nedeniyle bazılarından vazgeçilebilir; hangi değişikliğin nasıl ve hangi şartlarda yapılacağı belirlenmelidir.
  - İki hedef: gereksinim mühendisliği adımlarının doğru yürütülmesini sağlamak ve hazırlanan SRS belgesinin bütün yazılım geliştirme süreci boyunca yönetilmesi.
  - Gereksinimlerin gerçeklenmesi ve değişiklikler izleme tablolarıyla, özellikle izlenebilirlik tablosuyla (traceability table) izlenir.
- IEEE 830 SRS şablonu (ekrandan, 01:05:00 ve 01:10:00)
  - Bölüm 1 Introduction (amaç, belge kuralları, hedef okuyucu, ürün kapsamı, referanslar) ve Bölüm 2 Overall Description (ürün perspektifi, ürün fonksiyonları, kullanıcı sınıfları, işletim ortamı, tasarım ve gerçekleme kısıtları, kullanıcı belgeleri, kabuller ve bağımlılıklar) genel tanımdır.
  - Bölüm 3 External Interface Requirements: kullanıcı, donanım, yazılım ve iletişim ara birimleri.
  - Bölüm 4 System Features: fonksiyonel gereksinimler. Bölüm 5 Other Nonfunctional Requirements: performans, safety, security, yazılım kalite özellikleri, iş kuralları. Asıl önemli bölümler 4 ve 5'tir.
- Örnek SRS: Web Accessible Alumni Database (ekrandan, 01:50:00)
  - Küçük bir ders projesinde 1-3. bölümler kısa tutulabilir; fonksiyonel gereksinimler use case diyagramı ve use case belgeleriyle verilebilir.
- Yazılım kalite özellikleri ve McCall kalite modeli (ekrandan, 02:10:00 ve 02:15:00)
  - Kalite özellikleri ürünün çalışması, ürün geçişi ve ürün revizyonu olarak üçe ayrılır (McCall kalite üçgeni).
  - Kalite özellikleri doğrudan ölçülemez; ölçülebilir ölçütlerin farklı katsayılarla birleşimi olarak değerlendirilir.
  - ISO 9126 standardı da kalite özelliklerini açıklar ama gruplamadan sıralar.
- SRS standartları (ekrandan, 02:20:00)
  - IEEE 830-1998 (SRS odaklı) ve ISO/IEC/IEEE 29148:2011 (Systems and Software Engineering, Life Cycle Processes, Requirements Engineering).
  - Yazılım geliştirme sırasında kod dışında ortaya çıkarılan her türlü metin ve şemaya "artefact" denir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Gereksinimler doğal dille yazılıyorsa her basit cümlede yalnız bir gereksinim olmalıdır
  - SRS, müşteri ile geliştirici arasında sözleşme (şartname) niteliğindedir; kullanıcı kabul testinde her cümle tek tek eşleştirilerek kontrol edilebilmelidir.
  - Use case belgeleri kullanılsa bile adımların her biri tek bir işi anlatmalıdır.
- Bir projenin başka hiçbir belgesi olmasa bile SRS belgesi vardır
  - Teslimde kullanıcı "isteklerim karşılanmadı", geliştirici "karşılandı" dediğinde elde yalnız gereksinim belgesi olur. Sonradan yapılacak değişikliklerin nasıl yapılacağı da bu aşamada belirlenmelidir.
- Fonksiyonel ve fonksiyonel olmayan gereksinim ayrımı
  - Fonksiyonel gereksinimler yazılımın yaptığı işle ilgilidir ve yazılıma özgüdür (fatura sistemi, öğrenci bilgi sistemi, üretim planlama sistemi için farklıdır).
  - Fonksiyonel olmayan gereksinimler o işi yapmak için gereken altyapı ve kalite özellikleridir (performans, güvenlik, kullanılabilirlik vb.); özellik adları yazılımdan yazılıma değişmez, yalnız hangisinin öne çıktığı değişir.
  - Kullanışlılık (usability) fonksiyonel olmayan bir gereksinimdir.
- Fonksiyonel olmayan gereksinimler yalnız şablondaki safety ve security başlıklarıyla sınırlı değildir
  - Uygulamaya göre güvenirlik (reliability) gibi başka kalite özellikleri ayrı başlık olarak yazılabilir; her başlık altında birden fazla gereksinim olabilir.
  - Örnek SRS'teki gibi bir paragrafa sıkıştırmak yerine 5.2.1, 5.2.2 gibi numaralı maddeler halinde yazmak daha anlaşılırdır.
- Güvenlik (safety) ile güvenirlik (reliability) farklı kavramlardır
  - Doğruluk (correctness) doğru sonuç verilmesidir; güvenirlik bu doğru sonuca hangi hata sınırları içinde güvenilebileceğidir.
- Çevik süreçlerde de SRS gerekir
  - Süreç farklıdır (analiz, tasarım, gerçekleştirme ve test küçük birimlere bölünür) ama gereksinim belgesi ve diğer belgeler yine vardır; "çevik" diye belgesiz çalışılmaz.

## Kısa Tekrar Notları

- Gereksinim mühendisliği adımları: Inception, Elicitation, Elaboration, Negotiation, Specification, Validation, Management.
- Sistem analizindeki üç adım (bilgi toplama, modelleme, raporlama) burada daha fazla adıma ayrılır; pazarlık sistem analizinde ayrıca ele alınmayan yeni bir adımdır.
- Paydaş: sistemden doğrudan ya da dolaylı faydalanan herkes.
- Gereksinim sınıfları: normal, beklenen, heveslendirici.
- Tanımlama araçları: konuşma dili, kullanıcı senaryoları, kullanım şemaları, formel modeller, prototip.
- Doğrulama: açıklık, çelişki, hata ve eksik, gerçekçilik; yöntem teknik değerlendirme (formal technical review).
- İzlenebilirlik tablosu: satırlarda gereksinimler (G1, G2, ...), sütunlarda sisteme bakış açıları (modüller, paketler, sınıflar: B1, B2, ...).
- IEEE 830 bölümleri: 1 Introduction, 2 Overall Description, 3 External Interface Requirements, 4 System Features, 5 Other Nonfunctional Requirements, 6 Other Requirements.
- Her fonksiyonel gereksinim tek tek tanımlanır ve sıra numarasıyla ya da anlamlı bir etiketle (REQ-1, REQ-2) kimliklendirilir.
- McCall: ürünün çalışması (correctness, reliability, usability, integrity, efficiency), ürün geçişi (portability, reusability, interoperability), ürün revizyonu (maintainability, flexibility, testability).
- SRS'in kullanım yerleri: tasarım, kabul testi, müşteriyle sözleşme.

## Detaylı Açıklamalar

- Analiz ile tasarımın farkı
  - Gereksinim analizi (ve sistem analizi) "ne?" sorusuna cevap verir: üzerinde yazılım geliştirilecek sistem nedir, bu nasıl anlaşıldı ve nasıl belgelendi. Bu aşamada modeller oluşturulur ama yazılım hazırlanmaz.
  - Tasarım ise bu gereksinimleri karşılamak için yazılımın en iyi nasıl kurulacağını (yazılım mimarisi, modüller arası ilişkiler, nesneye yönelikse sınıflar) belirler.
- Başlangıç aşamasının proje planlamayla ilişkisi
  - Proje planlamada sistemin neden geliştirildiği zaten sorgulanmıştır; gereksinim analizinin başında bu problem tanımı iş süreçleri açısından yeniden ele alınır ve farklı kullanıcı tiplerinin sisteme hangi açıdan baktığı belirlenir.
- Pazarlığın iki yüzü
  - Müşteri ile geliştirici arasında: geliştirici ekip, sınırlı kaynaklarla karşılayamayacağı istekleri belirler ve net bir "yapılabilecekler listesi" çıkar.
  - Paydaşlar arasında: fatura örneğinde muhasebe, satın alma ve stok tarafı olayı farklı anlatır ve herkes kendi işini öne çıkarır; dışarıdan, tarafsız bir bakışla gerçek iş akışı ortaya konmalıdır.
- İzlenebilirlik tablosu (ekrandan, 00:35:00)

  |    | B1 | B2 | B3 | ... |
  |----|----|----|----|-----|
  | G1 | X  |    | X  |     |
  | G2 |    | X  |    |     |
  | G3 | X  |    |    |     |
  | ...|    |    |    |     |

  - G1, G2, ...: gereksinimler; B1, B2, ...: sisteme çeşitli bakış açıları (modüller, paketler, sınıflar vb.).
  - Tablo, hangi gereksinimin hangi modülde, pakette ya da sınıfta karşılandığını, ne kadar karşılandığını ve değişiklik olduysa nerede olduğunu izlemeyi sağlar.
- IEEE 830 şablonunun ayrıntıları (ekrandan, 01:25:00, 01:30:00, 01:35:00)
  - 2.2 Product Functions: ürünün yapması gereken ana fonksiyonların üst düzey özeti (madde listesi); ayrıntı sonraki bölümlerde verilir. Üst düzey veri akış diyagramı ya da sınıf diyagramı gibi bir resim çoğu zaman etkilidir.
  - 2.3 User Classes and Characteristics: kullanıcı sınıfları kullanım sıklığına, kullanılan fonksiyon alt kümesine, teknik uzmanlığa, güvenlik ya da yetki düzeyine, eğitim düzeyine veya deneyime göre ayrılabilir.
  - 2.5 ve 2.7: tasarım ve gerçekleme kısıtları ile kabuller. Örneğin belirli bir işletim sisteminin seçileceği kabulü; yanlış bir kabul sonradan değişirse projeyi etkiler.
  - 4.x System Feature: her özellik için açıklama ve öncelik (yüksek, orta, düşük), 4.1.2 Stimulus/Response Sequences (özelliği tetikleyen kullanıcı eylemleri ve sistem yanıtları; use case diyalog öğelerine karşılık gelir) ve 4.1.3 Functional Requirements (özelliğin ayrıntılı fonksiyonel gereksinimleri; beklenen hata koşulları ve geçersiz girdilere yanıt dahil; gereksinimler kısa, tam, belirsizlik içermeyen, doğrulanabilir ve gerekli olmalı; henüz bilinmeyen bilgi için "TBD" kullanılır).
  - Büyük bir uygulamada System Feature 1, System Feature 2 alt modülleri temsil eder (örneğin faturalama, irsaliye, stok); küçük bir uygulamada doğrudan fonksiyonel gereksinimler listelenebilir.
  - 5.4 Software Quality Attributes: adaptability, availability, correctness, flexibility, interoperability, maintainability, portability, reliability, reusability, robustness, testability, usability; mümkünse belirli, nicel ve doğrulanabilir yazılmalıdır.
  - 5.5 Business Rules: hangi kişinin ya da rolün hangi koşulda hangi fonksiyonu yapabileceği gibi işletim ilkeleri; kendileri fonksiyonel gereksinim değildir ama bazı fonksiyonel gereksinimleri gerektirebilir.
  - Analiz modelleri isteğe bağlıdır; veri akış diyagramı, sınıf diyagramı ya da use case diyagramı eklenebilir.
- Örnek SRS'ten notlar (ekrandan, 01:55:00, 02:00:00)
  - Aktörler: mezun (Alumnus) ve sekreterlik görevlisi. Mezun ana sayfaya erişme, anket doldurma, yeni kayıt oluşturma, kayıt güncelleme ve mezun arama işlemlerini yapar; görevli anket doldurma dışındaki aynı işlemleri yapar, bu yüzden ana aktör mezundur.
  - Her use case belgesinde ad, açıklama, öncelik, ön koşul, temel akış (basic path) adımları ve gerekirse istisna akışı (exception path) bulunur; anket doldurma use case'inde 6 adım vardır.
  - Fonksiyonel olmayan gereksinimler: kullanıcı ara birimi (kullanıcı dostu, sezgisel, kolay kullanılır, ergonomi standartlarına uygun), performans (mezunun tetiklediği her işlem 10 saniyeden kısa sürede tamamlanmalı; en az 100 kullanıcının veri bozulması olmadan aynı anda kullanımı), erişilebilirlik ve güvenirlik, güvenlik.
- McCall modelinde kalite özellikleri ve ölçütler (ekrandan, 02:10:00)
  - Güvenirlik: doğruluk (accuracy) ve hata toleransı; etkinlik: çalışma etkinliği (yanıt süresi) ve bellek etkinliği; bütünlük: erişim kontrolü ve erişim denetimi; kullanışlılık: çalıştırılabilirlik, eğitim, iletişim kolaylığı.
  - Bakım yapılabilirlik: kendi kendini tanımlama (kod içi açıklamalar ve belgeler) ve modülerlik; birlikte çalışabilirlik: veri ortaklığı, iletişim ortaklığı ve modülerlik.
  - Test edilebilirlik: basitlik, açıklamalar ve belgeler, modülerlik; esneklik: genişletilebilirlik ve genellik; taşınabilirlik: yazılım sisteminden ve makineden bağımsızlık; yeniden kullanılabilirlik: basitlik, genellik, modülerlik, yazılım sisteminden ve makineden bağımsızlık.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
