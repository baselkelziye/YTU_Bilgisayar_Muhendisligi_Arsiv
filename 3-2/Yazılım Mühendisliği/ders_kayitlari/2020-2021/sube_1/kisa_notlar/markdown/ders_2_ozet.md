# Ders 2 Çalışma Özeti

## Genel Konular

- Yazılım mühendisliğine giriş konularının tekrarı
  - Yazılım mühendisliği, kaliteli yazılımı en ekonomik biçimde hazırlamak için mühendislik araçlarını ve yeteneklerini kullanan bilim dalı olarak tanımlandı.
  - Yazılım eşittir program değildir: yazılım; program, belgeler ve veri tabanıyla ilişkili açıklamaların bütünüdür.
  - Yazılım türleri (ekrandan, 00:05:00): sistem yazılımı (derleyiciler, işletim sistemleri gibi diğer programlara hizmet eden programlar), mühendislik/bilimsel yazılım (büyük hacimli verilerle uğraşan "number crunching" programları), gömülü (embedded) yazılım (donanımla çok sıkı ilişkili, denetim amaçlı, gerçek zamanlı), uygulama ve kurumsal yazılımlar.
  - Eski yazılım (legacy software): iş sürecinin önemli parçası olan, uzun süredir kullanılan yazılım. Eksik ya da hatalı belgeleme, düzeltmelerle karmaşıklaşmış kod ve esnek olmayan yapı nedeniyle yeni gereksinimlere uyarlanması zordur.
  - Yazılım geliştirmeyi etkileyen eğilimler: bilgi işlem kaynaklarının ve haberleşme ağlarının yaygınlaşması, açık kaynaklı yazılım ve ekip çalışması.
- Yazılım hakkındaki yanılgılar
  - Müşteri açısından (ekrandan, 00:10:00): "Amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılır" (belirsiz gereksinimler çürük atılmış temele benzer) ve "Yazılım esnektir" (yaşam döngüsünde ilerledikçe değişen gereksinimi uyarlamanın bedeli üstel olarak artar). Sonuç: yazılım oyun hamurundan çok kil ya da cam gibidir; çevik süreçlerle esnekliğin artırılması hedeflenir.
  - Geliştirici açısından: "Yazılımı teslim edince işim biter" (teslim sonrası bir takip süresi gerekir), "Yazılımı tamamlamadan kalitesini ölçemem" (kalite güvencesi her aşamada uygulanır, gözden geçirmeler ve kalite ölçütleri vardır), "Belgelemek boşa çabadır" (gereksinim raporu ve test belgeleri zorunludur).
  - İdari açıdan (ekrandan, 00:15:00): "İşler yetişmiyorsa takıma yeni programcılar ekleriz" (yeni elemanların yazılıma hakim olması üstel olarak zorlaşır, işler daha da gecikir), "Yazılımı fason yaptırırım" (kendi içinde ilerlemeyi denetleyemeyen firma dışarıya verdiği işi de izleyemez), "Açık kaynak üretirsem kâr edemem" (danışmanlık hizmetleri ve başka iş modelleriyle kâr edilebilir).
- Yazılım süreçlerinin genel adımları (ekrandan, 00:20:00)
  - Çözümleme (Analysis): bir şeyi anlayabilmek için parçalarına ayırmak; uygulama alanı, kullanıcı gereksinimleri ve program parçaları (NYP'de sınıflar ve nesneler) arasındaki üst düzey ilişkiler anlaşılır. "Bir sorunu anlamadan çözemezsiniz." "Ne?" sorusuna cevap verilir.
  - Tasarım (Design): anlaşılan sorunun hangi yazılım teknikleriyle çözüme ulaştırılacağına karar verilir ve çözümün modeli oluşturulur.
  - Gerçekleme (Implementation): tasarım, seçilen programlama dili ve veri tabanıyla hayata geçirilir.
  - Sınama (Testing) (ekrandan, 00:25:00): süreçte ilerledikçe hataların giderilme maliyeti üstel olarak artar; hataların büyük çoğunluğunun kökeni isteklerin belirlenmesi ve tasarım aşamalarındaki sorunlardır. Bu yüzden erkenden, sık sık ve kolay sınama yapılmalıdır.
  - Bakım (Maintenance) (ekrandan, 00:40:00): tasarım, kodlama ya da gereksinim hatalarını düzeltmek, yeni işlev eklemek ya da yazılımı başka bir ortama taşımak için yapılır. Yeniden mühendislik (refactoring / software re-engineering): yazılımın işlevini değiştirmeden iç yapısını değiştirmek; olası eylemler belgelendirme, tasarımın iyileştirilmesi ve farklı ortama taşıma.
- Şemsiye (umbrella) etkinlikleri
  - Temel adımların sağlıklı yürümesi için yazılım proje yönetimi, yazılım kalite yönetimi, yazılım konfigürasyon yönetimi ve ölçme gibi destek etkinlikleri sürecin tamamına yayılır.
- CASE (Computer Aided Software Engineering) (ekrandan, 00:35:00)
  - Yazılım mühendisliği görevlerinin bilgisayar yardımıyla otomatik olarak gerçekleştirilmesi; CAD/CAM araçlarının yazılım geliştiriciler için karşılığı.
  - CASE ortamı, otomatik yazılım araçları ile yapısal yöntemlerin birleşimidir; süreci adım adım izleyerek yazılımı üretir. Avrupa'da IPSE (Integrated Programming Support Environments) adı da verilir.
  - Tam CASE aracı yalnız çizim yapmaz; adımlar arasında tutarlılık denetler (örneğin analizdeki aktörlerle tasarımdaki UML diyagramlarının uyumsuzluğunu bildirir).
  - Bütünleşik CASE araçları proje planlamadan kod üretimine kadar tüm süreci kapsar; diğerleri tek bir evreyi (ekran tasarımından kod üretimi, yalnız UML çizimi gibi) destekler. Temel işlevler: diyagram çizimi, analiz ve tasarım işlemleri, kod dönüştürücü ve modellerin tutulduğu bir arşiv.
  - Kapsamlı araçlar yeterli eğitim ve hazırlık olmadan kullanılırsa ilk projede zarar bile verebilir.
- Yazılım geliştirme süreç modelleri (ekrandan, 00:55:00)
  - Süreç, önceden belirlenmiş adımlardan oluşan iş akışıdır. Süreç modelleri adımların yapısını, sırasını ve kurallarını belirler; her modelin avantajı ve dezavantajı vardır, projeye uygun model seçilmelidir.
  - Şelale (ardışıl, sequential, waterfall) modeli (ekrandan, 01:00:00): Çözümleme → Tasarım → Kodlama → Sınama → Bakım; bir adım bitince diğerine geçilir, eksik ya da hata fark edilirse önceki adıma dönülür.
  - Ön ürün (prototip) modeli: müşteriyi dinleyip kolay araçlarla bir prototip oluşturmak, müşterinin denemesiyle tasarımı netleştirmek, sonra asıl ürünü geliştirmek.
  - Artımsal / yinelemeli modeller (ekrandan, 01:05:00): gereksinimler önem ve bağımlılık sırasına göre dizilir, her yinelemede bir kısmı tamamlanır. Örnekleri spiral model ve kazan-kazan modelidir.
  - Sarmal (spiral) model (ekrandan, 01:10:00): müşteriyle iletişim, planlama, risk analizi, çözümleme ve tasarım, gerçekleme ve kurulum, müşteri tarafından değerlendirme bölgeleri; içten dışa prototip, kullanılacak ürün, zenginleştirilmiş ürün ve bakım çevrimleri.
  - Kazan-kazan (WINWIN) modeli (ekrandan, 01:15:00): paydaşların belirlenmesi, kazanma durumlarının belirlenmesi, uzlaşma ve seçeneklerin belirlenmesi, seçeneklerin değerlendirilmesi ve risklerin çözülmesi, gerçekleme ve kurulum, ilgililer tarafından değerlendirme.
  - Hızlı uygulama geliştirme (RAD) (ekrandan, 01:20:00): kısa geliştirme çevrimlerine dayalı artımsal model; uygulama yaklaşık 3 aylık bölümlere ayrılabilmeli, yeterli bölüm eşzamanlı ilerleyebilmeli ve yazılım bileşenlerden kurulabilmelidir.
  - Bileşen tabanlı (component based) geliştirme (ekrandan, 01:25:00): uygulama hazır bileşenlerden oluşturulur; aşamaları konu alanı mühendisliği, aday bileşenlerin sınıflandırılması ve seçilmesi, uyarlama ve bir araya getirme.
  - Unified Process (ekrandan, 01:45:00): Inception, Elaboration, Construction, Transition evreleri ve her evrenin çıktıları.
- Proje ekibinin zamana göre büyüklüğü (ekrandan, 02:00:00)
  - Planlamada az kişi çalışır, analiz ve tasarımda ekip büyür, en fazla çalışan gerçekleme (implementation) aşamasındadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım eşittir program değildir
  - Belge hazırlamak geliştiricilerin hoşuna gitmese de gereksinim raporu ve test belgeleri yazılımın parçasıdır; hoca bunun sürekli tekrar edilmesi gerektiğini söyledi.
- Hataların zamanında yakalanması
  - Süreç ilerledikçe hatanın bulunma olasılığı azalır, düzeltilme maliyeti artar. Bu yüzden sınama yalnız sonda yapılmaz; testler önceden kararlaştırılır ve her aşamada gözden geçirme (review) yapılır.
  - Gereksinim ve tasarım hataları en korkutucu olanlardır, çünkü sürecin başına dönmeyi gerektirir.
- Yazılım bakımı makine bakımından farklıdır
  - Yazılım bakımı ilk evreye dönüp yeniden hazırlamayı gerektirebileceği için daha maliyetlidir.
- Klasik modeller hâlâ kullanılır
  - Çevik yöntemler yaygınlaşsa da klasik modellerin kullanılmadığı söylenemez; önemli olan hangi modelin ne zaman daha uygun olduğunu bilmektir.
- Spiral modelin ayırt edici yönü
  - Hoca, spiral modelin her aşamada risk analizi yapılan süreç modeli olduğunu ve hata kritik yazılımlar için uygun olduğunu vurguladı; küçük yazılımlar ve piyasaya hızlı ürün çıkarmak isteyen firmalar için uygun değildir.
- RAD'ın ön koşulları
  - Projenin eşzamanlı ilerleyebilecek alt modüllere bölünebilmesi, bileşenlerden kurulabilmesi ve her parçaya atanacak kadar eleman bulunması gerekir.

## Kısa Tekrar Notları

- Yazılım = program + belgeler + veri tabanı açıklamaları.
- Legacy yazılım: uzun süredir kullanılan, belgesi az, değiştirilmesi zor yazılım.
- Değişen gereksinimi uyarlamanın bedeli yaşam döngüsünde ilerledikçe üstel olarak artar.
- Geciken projeye eleman eklemek işi daha da geciktirebilir.
- Açık kaynakta kâr, danışmanlık hizmetleri ve başka iş modelleriyle sağlanabilir.
- Genel adımlar: çözümleme, tasarım, gerçekleme, sınama, bakım.
- Şemsiye etkinlikleri: proje yönetimi, kalite yönetimi, konfigürasyon yönetimi, ölçme.
- Hataların çoğunun kökeni gereksinim ve tasarım aşamasıdır; erken, sık ve kolay sınama yapılmalıdır.
- Yeniden mühendislik: işlevi değiştirmeden iç yapıyı değiştirmek.
- CASE: yazılım mühendisliği görevlerinin bilgisayar destekli otomasyonu; Avrupa'da IPSE.
- Şelale: iyi tanımlı adımlar, uzun süre, müşteri ürünü geç görür; rutin projeler için uygun.
- Prototip: müşteri ürünü erken dener; prototipteki kolaylık asıl ürüne yanlış beklenti olarak yansıyabilir.
- Spiral: hem artımsal hem yinelemeli; her çevrimde risk analizi; hata kritik yazılımlar için.
- WINWIN: paydaşların kazançlarını belirleyip uzlaşma seçenekleriyle ilerleyen yinelemeli model.
- RAD: yaklaşık 3 aylık eşzamanlı bölümler, bileşenlerden kurulum, hızlı ve uyumlu ekip.
- Bileşen tabanlı: domain engineering, qualification, adaptation, composition; yeniden kullanım önemli.
- Unified Process: Inception, Elaboration, Construction, Transition.
- En çok çalışan, gerçekleme aşamasındadır.

## Detaylı Açıklamalar

- **Yazılım hakkındaki yanılgıların ortak sonucu.** Müşteri, geliştirici ve yönetici yanılgılarının hepsi daha fazla maliyete yol açar. Müşteri gereksinimleri belirsiz bırakırsa ve yazılımı kolayca değiştirilebilir sanırsa geliştiricinin iş gücü artar. Geliştirici teslimden sonra takip süresini (müşterinin yazılıma, belgelere ve yardım bölümüne alışması, eğitimin sonuç verdiğinin izlenmesi) ihmal ederse daha büyük sorunlarla karşılaşır. Yöneticiler ise geciken işe yeni eleman eklemek yerine, proje yönetimiyle hangi evrede kaç kişiye ihtiyaç olduğunu önceden planlamalıdır. Alt yüklenici kullanılacaksa kurallar baştan kayda geçirilmeli ve firma dışarıya verdiği işi nasıl denetleyeceğini bilmelidir.

- **Genel adımların ilişkisi.** Çözümlemede problem iyice anlaşılmadan tasarım ve gerçekleme mümkün değildir. Çözümleme ilerleyen haftalarda gereksinim analizi ve SRS (Software Requirement Specification) belgesi başlığı altında bilgi toplama, modelleme ve belgeleme olarak ayrıntılandırılacaktır. Tasarım aşaması, sorunun kâğıt üzerinde ya da prototiple çözüme nasıl ulaştırılacağına karar verir; yazılım mimarisi bu aşamanın mühendislik yöntemleriyle ele alınan ayrı bir alt alanıdır ve sektörde yazılım mimarları önemli uzmanlar sayılır. Sınama, müşteriden alınan bilginin doğru hayata geçirilip geçirilmediğini sorgular. Bakım aşamasında gereksinim ve tasarım hataları en pahalı olanlardır.

- **CASE araçlarının kapsamı.** Klasik yaklaşımda veri akış diyagramları ve yapısal diyagramlar, nesneye yönelik yaklaşımda UML ve kullanım durumu (use case) diyagramları için CASE ortamları vardır. Yalnız çizim yapan araçlar tam CASE aracı sayılmaz; tam CASE aracı aynı problemi analizden tasarıma ve koda taşırken adımlar arasında birleşiklik ve tutarlılık sağlar. Bütünleşik araçlar diyagram çizimi, analiz ve tasarım işlemleri, kod dönüştürücü ve fonksiyonların, işlemlerin ve modellerin tutulduğu bir arşiv sunar.

- **Şelale modelinin artıları, eksileri ve kullanım alanı** (ekrandan, 01:00:00). Artıları: en eski ve yaygın kullanılan model olması, adımlarının iyi tanımlı olması. Eksileri: son ürün geç elde edildiği için müşteri sabırlı olmalıdır; geride bırakılan adımlardaki hataların düzeltilmesi üstel olarak zorlaşır; birçok müşteri gereksinimleri eksiksiz ve kesin belirtmekte zorlanır. Slayttaki sonuç: "Hiç model kullanmamaktan iyidir"; önceden birçok kez başarıya ulaştırılmış projelere benzeyen rutin projeler için kullanılabilir. Hoca, gereksinimleri iyi anlaşılmış kurumsal yazılımlarda hâlâ kullanıldığını, ancak müşterinin alışkın olmadığı yeni bir yazılımda müşterinin ürünü canlandırmasının zor olduğunu belirtti.

- **Ön ürün (prototip) modeli.** Daha kolay araçlarla oluşturulan model sayesinde müşteri ürünü erken tanımlamaya başlar; artısı ürünün erken denenmesidir. Eksileri: fizibilitede belirlenen asıl araçlar kullanılmadığı için prototip eksik ve kusurlu olabilir; ayrıca prototipte bir ekranın müşterinin yanında kolayca değiştirilmesi, müşteride asıl yazılımda da her şeyin aynı kolaylıkla değişeceği beklentisini doğurabilir.

- **Spiral model** (ekrandan, 01:10:00). Prototip modelin ve şelale modelinin güçlü yönlerini birleştirir. Slayttaki bölgeler: Müşteri ile İletişim (gereksinimlerin belirlenmesi), Planlama (kaynaklar, zamanlama, yapılacaklar vb.), Risk Analizi (teknik, mali ve politik riskler), Çözümleme ve Tasarım, Gerçekleme ve Kurulum (kullanıcı eğitimi, dokümantasyon vb. dahil), Müşteri Tarafından Ürünün Değerlendirilmesi. En içteki çevrimde kullanıma alınmayacak bir prototip geliştirilir; dışa doğru kullanılacak ürün, eklemelerle zenginleştirilmiş ürün ve bakım çevrimleri gelir. Her çevrimde aynı altı adımın tekrarlanması modeli yinelemeli, her çevrimde ürünün büyümesi artımsal yapar. Gerçekleme ve kurulum bölgesine construction (yapım) aşaması da denir. Şelaleye göre daha uzun sürer ama kontroller fazladır; hatanın en aza indirilmesi gereken ve bütçesi düşük olmayan projelere uygundur.

- **Kazan-kazan (WINWIN) modeli** (ekrandan, 01:15:00). Spiral gibi yinelemeli ve evrimseldir. Paydaş, yazılımın başarısı ya da başarısızlığından etkilenecek kişi ve kurumlardır (müşteri, geliştirici, yönetici). Her paydaşın yazılımdan beklediği kazanç belirlenir, uzlaşma seçenekleri ortaya konur, seçenekler değerlendirilip riskler çözülür ve herkesin isteğini asgari düzeyde karşılayacak biçimde ilerlenir.

- **RAD** (ekrandan, 01:20:00). Artısı, sürece uygun projelerde verimliliğin artmasıdır. Eksileri: büyük ölçekli çalışmalarda yeterli bölümü eşzamanlı ilerletecek sayıda çalışan bulunamayabilir, çalışanlar hıza uyum sağlamalıdır ve yüksek teknik riskli projelere uygun değildir. Slayttaki sonuç: prototip geliştirmede kullanılması ya da ana fikirlerinin diğer süreçlere uygulanması yerinde olur. Akış: problem anlaşılır ve koşullara uygunluğu değerlendirilir, proje alt bölümlere ayrılır, her alt modüle bir ekip atanır, her parça için analiz, tasarım, veri ve işlem modelleme yapılır, parçalar önce tek başına, sonra uyumluluk açısından birlikte test edilip kullanıma alınır.

- **Bileşen tabanlı geliştirme** (ekrandan, 01:25:00). Artısı yeniden kullanımın (reusability) özendirilmesidir (slaytta "azalan giderler?" diye soru işaretiyle). Eksileri: uygun bileşenler her zaman bulunamaz ve bileşenlerin uyarlanması göründüğü kadar kolay olmayabilir. Çok benzer programlar hazırlayan bir şirket kendi bileşen kütüphanesini oluşturarak bu modeli kullanabilir. Ana fikirleri özellikle RAD olmak üzere çeşitli süreçlere uygulanabilir.

- **Unified Process** (ekrandan, 01:45:00). Nesneye yönelik yaklaşımla birlikte kullanılan, döngüsel yapıda bir süreçtir. Evreler: Inception (iletişim ve planlamanın başlangıcı), Elaboration (planlamayla modellemenin birleştiği hazırlık), Construction (ayrıntılı tasarım, kodlama ve mühendislik testi), Transition (kullanıcı testi ve geri bildirim); sonunda production. Evre çıktıları:

  ```text
  Inception    : Vision document; initial use-case model; initial project glossary;
                 initial business case; initial risk assessment; project plan
                 (phases and iterations); business model (if necessary);
                 one or more prototypes
  Elaboration  : Use-case model; supplementary requirements (including non-functional);
                 analysis model; software architecture description; executable
                 architectural prototype; preliminary design model; revised risk list;
                 project plan (iteration plan, adapted workflows, milestones,
                 technical work products); preliminary user manual
  Construction : Design model; software components; integrated software increment;
                 test plan and procedure; test cases; support documentation
                 (user manuals, installation manuals, description of current increment)
  Transition   : Delivered software increment; beta test reports; general user feedback
  ```

  Spiralde ayrı bir risk bölgesi vardır; Unified Process'te ayrı bir risk evresi yoktur, ilk risk değerlendirmesi inception evresinde yapılır, elaboration evresinde risk listesi gözden geçirilerek netleştirilir.

- **Proje ekibinin büyüklüğü** (ekrandan, 02:00:00). Slayttaki "Staffing levels of a typical project" grafiğinde yatay eksen proje zamanı (Planning, Analysis, Design, Implementation), dikey eksen çalışan sayısıdır. Planlamada çalışan sayısı en düşüktür; planlamayı ağırlıklı olarak proje yöneticisi, müşteriden bilgi alarak ve ağ, veri tabanı gibi alanlardaki uzmanlara danışarak yürütür. Analizde sistem analistleri ve yazılım mühendisleriyle ekip büyür, tasarımda yazılım mimarları ağırlık kazanır ve sayı yaklaşık aynı düzeyde kalır, gerçeklemede en yüksek seviyeye çıkar ve proje sonunda düşer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
