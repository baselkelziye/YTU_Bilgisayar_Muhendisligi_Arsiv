# Ders 3 Genişletilmiş Notu: Çevik Yazılım Geliştirme Süreçleri: XP, Scrum ve Kanban

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Klasik Süreç Modellerinin Tekrarı
- 2. Unified Process Evreleri
- 3. Çevik Yaklaşımların Ortaya Çıkışı ve Çevik Manifesto
- 4. Çevik Yaklaşımın Tanımı ve Kalite Açısından Farkı
- 5. Çevik Ekip Yapısı
- 6. Çevik Süreçlerin Esnekliği ve Anahtar Kavramları
- 7. Extreme Programming (XP)
- 8. CRC Kartları
- 9. Eşli Programlama ve Test Güdümlü Yazılım Geliştirme
- 10. Scrum
- 11. XP Döngüsünün Şekil Üzerinden Tekrarı
- 12. Scrum ile Diğer Modellerin Karşılaştırması
- 13. Kanban
- 14. XP, Scrum ve Kanban Karşılaştırması
- Örnek Sorular
- Dersin Toparlaması

## 1. Klasik Süreç Modellerinin Tekrarı

Ders, bir önceki haftada görülen klasik yazılım geliştirme süreç modellerinin sözlü tekrarıyla başlar. Bu haftanın konusu çevik (agile) süreçlerdir; ama önce çevik süreçlerin neye karşı bir alternatif olarak doğduğunu hatırlamak için klasik modeller kısaca gözden geçirilir.

**Şelale (waterfall) modeli** lineer model ya da ardışıl model olarak da bilinir. Bu modelde bir aşama bitirilmeden bir sonraki aşamaya geçilmez.

**Prototip modeli**nde özellikle analiz ve tasarım sırasında, üzerinde denemeler yapılacak bir ön model (ön ürün) oluşturulur. Müşteriyle birlikte bu ön ürün üzerinde denemeler yapılır, ardından son ürün geliştirilir.

**Spiral model**, şelale ile prototip modelinin karışımıdır ve buna ek olarak risk analizini sürecin içine katar. Spiralin en içteki evresinde prototip yaratılır, sonraki evrede kullanılacak ürün yaratılır, ardından ürün zenginleştirilir ve bakım yapılır. Her evrede aynı altı alt adım tekrarlanır:

1. Müşteriyle iletişim, müşteriden bilgi alma.
2. Alınan bilgiye göre planlama.
3. Plan üzerinde risk analizi.
4. Risk analizi ve planı kullanarak modelleme, yani analiz ve tasarımın başlangıcı.
5. Construction: ayrıntılı tasarım, yazılımın kodlanması ve mühendislik testi.
6. Dağıtım (deployment): ürünü müşterinin değerlendirmesine sunma.

Yani yalnız bir prototip geliştirilirken bile bu altı adım uygulanır; müşteri değerlendirmesinden sonra kullanılacak ürünü geliştirmeye geçildiğinde de altı adım yeniden tekrarlanır. Bu nedenle spiral model ekleme yapa yapa ürünün en olgun haline ulaşan **artımlı** ve aynı zamanda **evrimsel** bir modeldir; belgeleme de bu modelde güçlü biçimde yapılır. Daha çok hata kritik ürünlerin geliştirilmesinde kullanılır.

**RAD (Rapid Application Development)** modeli, rekabete dayalı ve hızlı geliştirilmesi gereken bir ürün söz konusuysa ve kurumun olanakları elveriyorsa, aynı anda birden fazla ekip kurarak hızlı geliştirme yapmayı öngörür. Hoca, V modelinin de özel bir model olarak geçen hafta anıldığını hatırlatır.

**Unified Process** ise iletişim, planlama, modelleme, construction ve dağıtım (uygulamaya koyma) etkinliklerini içeren özel bir modeldir. Hoca, bu modelin daha sonra IBM'in satın aldığı Rational firmasının CASE aracı ve platformuyla birlikte tanıtıldığını; bu araçlarla yazılım geliştirildiğinde alttaki süreç modeli olarak Unified Process'in kullanılmasının daha yatkın olduğunu belirtir.

## 2. Unified Process Evreleri

Slayttaki diyagramda (ekrandan, 00:05:00) iletişim (communication), planlama (planning), modelleme (modeling), construction ve dağıtım (deployment) etkinlikleri bir döngü halinde gösterilir. Döngünün üzerine dört evre yerleştirilmiştir: **inception** iletişim ve planlamaya, **elaboration** planlama ve modellemeye, **construction** construction etkinliğine, **transition** ise construction ile dağıtım arasına bağlanır. Döngüden çıkan ok "Release: software increment" (yayım: yazılım artımı) olarak **production** (üretim, kullanım) evresine gider.

Her evrenin ürünleri ikinci slaytta listelenir (ekrandan, 00:10:00):

| Evre | Ürünler |
|---|---|
| Inception | Vizyon belgesi; başlangıç use case modeli; başlangıç proje sözlüğü; başlangıç iş durumu (business case); başlangıç risk değerlendirmesi; evreleri ve iterasyonları içeren proje planı; gerekirse iş modeli; bir ya da daha fazla prototip |
| Elaboration | Use case modeli; işlevsel olmayanlar dahil ek gereksinimler; analiz modeli; yazılım mimarisi tanımı; çalıştırılabilir mimari prototip; ön tasarım modeli; gözden geçirilmiş risk listesi; iterasyon planı, uyarlanmış iş akışları, kilometre taşları ve teknik iş ürünlerini içeren proje planı; ön kullanıcı kılavuzu |
| Construction | Tasarım modeli; yazılım bileşenleri; bütünleştirilmiş yazılım artımı; test planı ve prosedürü; test durumları; destek belgeleri (kullanıcı kılavuzları, kurulum kılavuzları, mevcut artımın tanımı) |
| Transition | Teslim edilen yazılım artımı; beta test raporları; genel kullanıcı geri beslemesi |

Hoca evreleri şöyle açıklar. Unified Process nesneye yönelik uygulamalara daha uyumludur. Başlangıç (inception) evresinde vizyon belgesi oluşturulur, başlangıç use case modeli çıkarılır, bir iş analizi yapılır ve "bu projenin riskleri nelerdir?" sorusuyla başlangıç risk değerlendirmesi gerçekleştirilir; proje planı ve iş modeli buna göre oluşturulur. Elaboration evresinde use case modeli analiz ve tasarım için gerçek anlamda geliştirilir, yazılım mimarisi tanımlanır, mimari prototip ve ön tasarım modeli oluşturulur. Risk listesi yeniden düzenlenir: başta tahmin edilen riskler hâlâ geçerli mi, olasılıklarında bir değişiklik var mı diye bakılır. Hoca, yazılım risk analizinin dersin ilerleyen bölümlerinde ayrıca işleneceğini belirtir. Proje planı da gözden geçirilip değiştirilir.

Construction evresinde ayrıntılı tasarım modeli oluşturulur, yazılım bileşenleri birbiriyle bütünleştirilir, test yazılımı geliştirilir, kodlama ve testler yapılır. Transition (geçiş) evresinde yazılım artımları, yani yazılım ürününün bitmiş ve dağıtılacak, kullanıma alınacak parçaları teslim edilir; beta test raporları oluşturulur ve kullanıcı geri beslemeleri değerlendirilir.

## 3. Çevik Yaklaşımların Ortaya Çıkışı ve Çevik Manifesto

Çevik yaklaşım başlığı altında üzerinde durulacak modeller, en eski ve ilk kullanılan çevik model olan **Extreme Programming (XP)**, ardından **Scrum** ve ticari uygulamalarda daha çok kullanılan **Kanban**'dır.

Hoca "Ne oldu da çevik süreçler yazılım geliştirme hayatına girdi?" sorusunu sorar. Çevik prensipler, 2000'li yılların başında bir manifesto sonucunda ortaya çıkmıştır.

> **Ders sonrası not:** Hoca manifestonun 1999-2000 yıllarında ortaya çıktığını söyledi; Agile Manifesto büyük olasılıkla Şubat 2001'de yayımlanmıştır.

Manifestodaki 12 çevik ilke, aynı zamanda çevik süreçlere geçilmesinin nedenleridir. Slaytlarda İngilizce asılları şöyledir (ekrandan, 00:15:00 ve 00:20:00):

1. Our highest priority is to satisfy the customer through early and continuous delivery of valuable software. (En yüksek önceliğimiz, değerli yazılımın erken ve sürekli teslimiyle müşteriyi memnun etmektir.)
2. Welcome changing requirements, even late in development. Agile processes harness change for the customer's competitive advantage. (Geliştirmenin geç evrelerinde bile değişen gereksinimleri kabul edin; çevik süreçler değişikliği müşterinin rekabet avantajı için kullanır.)
3. Deliver working software frequently. (Çalışan yazılımı sık teslim edin.)
4. Business people and developers must work together daily throughout the project. (İş insanları ve geliştiriciler proje boyunca her gün birlikte çalışmalıdır.)
5. Build projects around motivated individuals. Give them the environment and support they need, and trust them to get the job done. (Projeleri motive bireyler etrafında kurun; onlara gereken ortamı ve desteği verin, işi bitireceklerine güvenin.)
6. The most efficient and effective method of conveying information to and within a development team is face-to-face conversation. (Geliştirme ekibine ve ekip içinde bilgi aktarmanın en verimli ve etkili yolu yüz yüze konuşmadır.)
7. Working software is the primary measure of progress. (İlerlemenin temel ölçüsü çalışan yazılımdır.)
8. Agile processes promote sustainable development. The sponsors, developers, and users should be able to maintain a constant pace indefinitely. (Çevik süreçler sürdürülebilir geliştirmeyi destekler; sponsorlar, geliştiriciler ve kullanıcılar sabit bir hızı süresiz koruyabilmelidir.)
9. Continuous attention to technical excellence and good design enhances agility. (Teknik mükemmelliğe ve iyi tasarıma sürekli dikkat çevikliği artırır.)
10. Simplicity, the art of maximizing the amount of work not done, is essential. (Basitlik, yani yapılmayan iş miktarını en çoğa çıkarma sanatı, esastır.)
11. The best architectures, requirements, and designs emerge from self-organizing teams. (En iyi mimariler, gereksinimler ve tasarımlar kendi kendini örgütleyen ekiplerden çıkar.)
12. At regular intervals, the team reflects on how to become more effective, then tunes and adjusts its behavior. (Ekip düzenli aralıklarla nasıl daha etkili olabileceğini değerlendirir ve davranışını buna göre ayarlar.)

Hoca bu ilkeleri yorumlarken şunları vurgular. Yazılım geliştiriciler teslim tarihlerine uymak zorundadır; hızlı geliştirme birinci önceliktir ve geliştirme sırasında gereksinimler değişebilir. Ürünün kullanıcıları (özellikle işletmelerde) ile geliştiriciler projede bir arada çalışır; dördüncü ilke ikinci ilkeyi tamamlar, çünkü kullanıcı süreçteyse ürün verildiğinde değişiklik ihtiyacı azalır. Klasik modelde tasarımı yapan, kodlayan ve test eden evreler halinde biri işini bitirince diğeri işi devralır ve iş kağıt üzerinden ilerlerken sonradan soru sormak verimsizdir; ekibin bir arada çalışması verimliliği artırır. Spiral modele kadar gelinen klasik yaklaşımlarda çok sıkı belgeleme kuralları varken, yedinci ilke temel ölçünün çalışan yazılım olduğunu söyler. Sponsorlar, geliştiriciler ve kullanıcılar ürünü sürekli yaşayan ve çalışabilir halde tutmalıdır.

Basitlik ilkesi, işe mümkün olduğunca basit bir tasarımla başlamak ve ayrıntıyı sonraki evrelere bırakmak demektir. Hoca bunun analiz ve tasarım aşamalarını gözden çıkarmak anlamına gelmediğini özellikle belirtir. Son ilkedeki düzenli iç değerlendirme XP'de ve Scrum'da farklı biçimlerde, farklı iç toplantı yapılarıyla gerçekleştirilir.

## 4. Çevik Yaklaşımın Tanımı ve Kalite Açısından Farkı

Slayttaki tanım şöyledir (ekrandan, 01:25:00): **Çevik yaklaşımlar, artan müşteri taleplerini daha hızlı karşılamak amacıyla geleneksel sistem geliştirme modellerine alternatif olarak ortaya çıkmıştır. Çevik yaklaşımlar, yazılım geliştirme safhasında geç ortaya çıkan gereksinim değişimlerini çabuk karşılamayı esas alan modellere verilen genel bir isimdir.**

Hoca burada bir düzeltme yapar: "Agile Kanban" gibi ifadeler kullanılabilir, ama çevik yaklaşım başlı başına bir süreç modeli değildir; çevik yaklaşımla oluşturulmuş süreç modelleri vardır. Spiral, RAD ve Unified Process klasik yaklaşımla geliştirilmiş modellerdir; Kanban ise çevik yaklaşımı kullanan bir süreçtir. Hem klasik hem çevik modellerin sayısı burada anılanlardan fazladır; derste yalnız en yaygın olanlardan söz edilmektedir.

Geleneksel modellere göre çevik modellerde kalite açısından farklar şunlardır (ekrandan, 00:35:00):

- Dinamik kalite değerlendirme statik değerlendirmeden daha fazla uygulanır. Yani gözden geçirmeler yerine daha çok, gerçek veri kullanılarak test yapılır. Test güdümlü geliştirme (TDD) yaklaşımı da bu bağlamda ele alınacaktır.
- Kalite ile ilgili işlemler sürecin daha erken adımlarında başlar.
- Kalite ile ilgili etkinlikler daha az aralıklarla yapılır; hoca bunu daha kısa aralıklarla test ve gözden geçirme yapılması olarak açıklar.
- Çevik yaklaşımlarda kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle doğruluk ve süreklilik sağlanır. Süreklilik, yazılımı sürekli yaşayan halde tutmak demektir.

## 5. Çevik Ekip Yapısı

Hoca 12 ilkeyi tek tek ele almak yerine birleştirerek, klasik süreçlere göre çevik süreçlerde nasıl bir ekip yapısı olduğunu anlatır:

- Yüz yüze görüşmelerin etkin aktarım yolu olduğu bir ekip yapısı vardır ve ekip üyeleri çevik yaklaşım konusunda bilgilendirilir, eğitilir.
- Amaç çalışan yazılımı üretmek ve müşteriye daha hızlı teslim etmektir.
- Ekip üyeleri birbirleriyle ve müşteriyle sürekli iş birliği içindedir; bu, karşılıklı saygı ve güven gerektirir, çünkü üyeler birbirlerini değerlendirir de.
- Tüm proje hakkında birlikte çalışırlar.

**Soru (hocanın kendi sorusu):** Bu durumda proje yöneticisi ortadan mı kalktı? **Cevap:** Hayır. Çevik yürütülen projelerde de bir proje yöneticisi vardır, ama daha çok koordinatör gibi çalışır. "Şu işi sen şu kadar günde yapacaksın" yerine ekibin ortak denetimiyle herkes işini yapar.

Proje hakkındaki fikirleri toplantılarda bütün ekip üyeleri söyleyebilir. Çözülen bir sorun sonradan gereksizleşse bile çözüm sürecinde edinilen deneyim ekibe daha sonra faydalı olabilir; bu yüzden herkesin fikri değerlendirilir. Ekip kendi kendini düzenler: süreci yapılan işe ve yerel ortama uyarlar, artımsal yazılım parçalarını teslim etmek için gerekli çalışma zamanlamasını kendisi belirler.

## 6. Çevik Süreçlerin Esnekliği ve Anahtar Kavramları

Slayt (ekrandan, 00:40:00) çevik süreçleri, değişen gereksinimler ve teknik riskler gibi önceden belirlenemeyen durumlara ve yazılım ürününü etkileyebilecek her tür değişikliğe karşı esneklik sağlayan süreçler olarak tanımlar ve iki sütunlu bir karşılaştırma verir:

| Çevik süreçlerin öne çıkardığı (sol) | Karşısındaki (sağ) |
|---|---|
| Bireyler ve etkileşimler | Süreçler ve gereçler |
| Çalışan yazılım | Ayrıntılı belgeler |
| Müşterinin sürece katılımı | Sözleşme pazarlığı |
| Değişikliklere uyum sağlamak | Bir planı izlemek |

Çevik süreçler sağ taraftaki maddelerin yararını kabul etmekle birlikte sol taraftakilere daha çok önem verir. Bir ilerleme olmaksızın yalnızca sürekli uyum sağlamak başarı değildir; ilerleme şunlarla ölçülür: yazılımın artımsal gelişimi, müşteriye erken ve sık ürün teslimi, başarımın birincil ölçütünün doğru çalışan yazılım olması.

Hoca her satırı açar. **Bireyler ve etkileşimler:** paydaşlar (müşteri, programcı, veri tabanı uzmanı, sistem analisti) arasındaki bütün etkileşimler önemlidir; süreçler yine takip edilir ama ikinci plandadır. **Çalışan yazılım:** her yazılım için amacı düşünülmeden çok ayrıntılı belgeler hazırlamak yerine, çalışan yazılımı üretmek ve bakım sırasında gerçekten kullanılacak belgeleri hazırlamak esastır.

> **Hocanın vurgusu:** Çevik süreç kullanıyoruz diye eski "önce kodla" mantığına dönmüş değiliz; gerekli belgeler yine hazırlanır.

**Müşterinin sürece katılımı:** Gereksinim analizinde görülecek sözleşme pazarlığı (negotiation) yine yapılır, ama müşteri yalnız gereksinim analizinde değil işin her aşamasında vardır; müşteri sürece katılmışsa sözleşme pazarlığı da daha hafif geçer. Müşteri gerçek bir ekip üyesidir; arada bir soru sorulan biri değil, müşteri tarafından seçilen kişiler sürekli ekibin içinde yer alır.

**Değişikliklere uyum:** Bir plan vardır ve izlenir, ama yalnızca belli evrelerde "yeterli mi" diye bakılmaz. Plan küçük aralıklarla dinamik olarak izlenir ve değişikliklere uyum sağlayacak şekilde değiştirilir. Çevik süreçlerde "bir plan yaptık, artık hiçbir değişiklik yapamayız" diye bir kural yoktur.

## 7. Extreme Programming (XP)

### 7.1 Ad ve temel değerler

XP (Extreme Programming) Türkçeye uç programlama, aşırı programlama gibi adlarla çevrilmiştir; hoca hiçbir çevirinin tanıma tam uymadığını düşünür. XP, çevik süreç özelliklerini dört temel değer çerçevesinde toplar (ekrandan, 01:10:00 slayt önizlemesi; altyazı): **basitlik, iletişim, geri besleme ve cesaret**.

Bu değerler çerçevesinde XP'nin özellikleri şunlardır:

- Planlama oyunu.
- Küçük ve kısa aralıklı yayımlar (release): müşterinin kullanacağı yazılım parçalarını kısa aralıklarla ekleyerek vermek. XP aynı zamanda artımsal bir süreç modelidir.
- Sistem metaforu.
- Basit tasarım: tasarımı karmaşık yapmayın, basit yapın ve giderek geliştirin öğüdü bütün çevik yaklaşımlarda vardır.
- Test.
- Sürekli yeniden tasarım (refactoring).
- Eşli programlama (pair programming): XP'ye özgü öne çıkan özelliktir.
- Ortak kod mülkiyeti: analist, tasarımcı ve programcı yalnız kendi işini değil, ürünün tamamında ne yapıldığını bilir.
- Sürekli bütünleştirme (continuous integration).
- Devam ettirilebilir hız: ekip üyesinin haftalık çalışma süresi sınırlı tutulur. <!-- BELİRSİZ: saat sınırı altyazıda düştü; slayt önizlemesinde "40 saat / hafta" gibi okunuyor ama önizleme küçük. -->
- Ekip üyesi müşteri.
- Kodlama standartlarının kullanılması.

Scrum, Kanban ve XP'nin hepsi çevik yaklaşımın felsefesi üzerinde gelişse de her birinin kendine özgü anahtar kavramları vardır; yukarıdakiler XP'ninkilerdir.

### 7.2 XP adımları ve planlama

Slayt (ekrandan, 01:10:00): **Aşırı Programlama (XP)**. Adımlar: Planlama, Tasarım, Kodlama, Sınama; döngü bir **Artımsal Ürün** verir ve planlamaya geri döner.

Planlama:

- Müşteri, kullanıcı öykülerini oluşturur.
  - Müşteri öyküleri önemine göre derecelendirir.
  - Yaklaşık 3 haftada gerçeklenemeyecek öyküler varsa ekip müşteriden bunları alt öykülere bölmesini ister.
- Ekip ve kullanıcı, öykülerin sıradaki artımsal ürüne nasıl ekleneceğine karar verir:
  - Ya önce yüksek riskli öyküler gerçeklenir,
  - Ya da önce yüksek öncelikli öyküler gerçeklenir,
  - Her olasılıkta tüm öyküler kısa sürede (birkaç hafta) gerçeklenmelidir.

Alt öykülere bölmenin nedeni, XP'de ürünün kısa artımlarla, kısa yayımlarla geliştirilmesinin istenmesidir. Planlamada ilk artımsal ürün **projenin hızını ölçmek** için değerlendirilir ve sonraki artımların teslim tarihleri buna göre belirlenir. Bu, planın dinamik olmasının somut bir örneğidir: ilk ürün ne kadar sürede teslim edildi, ekibin çalışma hızı nedir, sonraki artımlar buna göre planlanır. Artımsal ürünlerin içerikleri gözden geçirilir ve kapsam azaltılmaya çalışılır. Süreç ilerledikçe müşteri yeni öyküler ekleyebilir ya da eski öykülerin önceliğini değiştirebilir; plan da yapılan işe bağlı olarak değişir.

### 7.3 Tasarım

XP'de tasarım aşamasında basit tasarım ilkesi esastır. <!-- BELİRSİZ: "... daha üstündür" cümlesinin başı altyazıda düştü; büyük olasılıkla basit tasarımın karmaşık tasarımdan üstün olduğu söyleniyor. --> Tasarımda **Class-Responsibility-Collaboration (CRC) kartları** oluşturulur. Zor bir tasarım sorunu varsa bir prototip yaratılıp onun üzerinde geliştirilmesi tavsiye edilir. Tasarımın yenilenmesi anlamına gelen refactoring de XP'de teşvik edilir. Özetle tasarımda CRC kartları ve ön gerçeklemeler (prototipler) oluşturulur.

## 8. CRC Kartları

CRC kartı, nesneye yönelik yaklaşımda yazılımı sınıflar halinde incelerken her sınıfın yapısını, sorumluluğunu ve iş birliği içinde olduğu sınıfları belirleyen karttır. Slayttaki örnek (ekrandan, 01:15:00):

| Sınıf: Satış | |
|---|---|
| Açıklama | Kasada yapılan ödemeyi simgeleyen sınıf. |
| Üst sınıf(lar) | Yok |
| Alt sınıf(lar) | Yok |
| **Sorumluluk** | **İşbirlikçi** |
| Satışın yapıldığı tarih ve saati saklamak | |
| Yapılan ödeme tutarını saklamak | Ödeme |
| Satılan malların listesine erişim | Mal |

Slayttaki bir not, "İşbirlikçi" sütununa sınıf adlarının yazıldığını gösterir. Satış sınıfının sorumlulukları satışın tarih ve saatini saklamak, ödeme tutarını saklamak ve satılan malların listesine erişebilmektir. Ödeme tutarını sakladığı için **Ödeme** sınıfı, malların listesine eriştiği için **Mal** sınıfı Satış'ın iş birliği yaptığı sınıflardır.

Hoca sonradan konuya geri dönerek özetler: çevik süreçlerde, özellikle XP'de, tasarımda CRC kartlarından yararlanılır. Her sınıfın adı, yaptığı iş ve özellikleri, sorumluluğu (hangi işlemleri gerçekleştirdiği) ve iş birliği içinde olduğu sınıflarla bunların hangi sorumluluklar üzerinden birbirine bağlandığı tanımlanır.

**Soru:** CRC'nin açılımı "resource card" gibi bir şey mi? **Cevap:** Hayır. C class (sınıf), R responsibility (sorumluluk), C collaboration (iş birlikçi) demektir.

## 9. Eşli Programlama ve Test Güdümlü Yazılım Geliştirme

### 9.1 Eşli programlama

XP'de planlama ve tasarımdan sonra kodlama aşamasında diğer modellerden farklı olarak **eşli programlama (pair programming)** kullanılır. XP çevik modeller içinde ilk kullanılan süreç olduğu için 2000'li yıllarda eşli programlama çok önem kazandı. Eşli programlamada program yazımı sırasında aynı bilgisayarda iki programcı bulunur (hoca iki klavyeli bilgisayarlardan söz eder). Biri yazılımı geliştirirken diğeri gözden geçirir ve gerektiğinde müdahale eder.

Evrelere göre özetle: planlamada kullanıcı öyküleri ve derecelendirme, tasarımda basitlik ve refactoring, kodlamada eşli programlama, sınamada test güdümlü geliştirme kullanılır.

### 9.2 Test güdümlü yazılım geliştirme (TDD)

Slayt (ekrandan, 01:20:00): **Test güdümlü yazılım geliştirme (TDD) stratejisi, küçük ve hızlı iterasyonlarla, yazılım geliştirme araçları ile hazırlanmış testler yazılarak ilerleyen bir yazılım geliştirme metodolojisidir. Test güdümlü yazılım geliştirme genellikle çevik yaklaşım uygulamaları için daha uygun bir yöntemdir.**

XP'de sistemin tanımı, sistem analizi ya da gereksinim analizi yapılırken her gereksinimin nasıl test edileceği de belirtilerek ilerlenir; hangi iterasyonlar varsa onlar için testler geliştirilir. Hocanın anlattığı TDD uygulama adımları şöyledir:

1. Birim test durumları (test case) yazılır.
2. Henüz kod yazılmadığı için bu testlerin ilk başta başarısız olacağı bilinir.
3. Kod yazıldıkça belirlenen birim test durumları çalıştırılır; testler tekrar tekrar koşturularak geçtikleri görülür.
4. Gerekirse kod yeniden düzenlenir.

TDD yaklaşımı, çevik programlamanın başladığı 2000'li yıllardan beri vardır. Hoca, IEEE Software dergisinin editörlerinden olan ve bu konuda araştırmalar yapan bir akademisyenin çalışmalarını aktarır: bu çalışmalara göre TDD programcı üretkenliğini artırmakta, ama kalite açısından çok büyük bir fark yaratmamaktadır; ayrıca programcıyı kodu ve test sonuçlarını saklamaya teşvik etmektedir.

## 10. Scrum

### 10.1 Scrum adımları

Hoca Scrum'a geçmeden önce çevik süreçlerin ortak özelliklerini bilerek bir kez daha tekrarlar; amacı bu kavramların yerleşmesidir, çünkü çevik yaklaşımlar artık çok kullanılmaktadır.

Slayt (ekrandan, 01:05:00 ve 01:40:00):

- **Scrum** adımları: Görev Listesi, Koşu, İşlev Gösterimi; işlev gösteriminden görev listesine geri dönülür.
- **Görev Listesi** = Kullanıcı öyküleri.
  - Önceliklendirilmiştir.
- **Koşu:**
  - Görev listesinin maddelerinden biri seçilir ve önceden belirlenmiş kısa bir süre içerisinde (Ör. 1-4 hafta) gerçeklenir.
  - Koşu süresince ekibin her gün yaptığı kısa (Ör. 15 dk) toplantılar:
    - Proje lideri yönetir.
    - Cevaplanmaya çalışılan üç ana soru: Son toplantıdan bu yana ne yaptınız? Karşılaştığınız engeller nelerdir? Yarınki toplantıda neleri başarmayı hedefliyorsunuz?
- **İşlev Gösterimi:** Müşterinin en yeni işlevi veya o ana dek gerçeklenen tüm işlevleri sınaması.

Görev listesini sistem analistleri ya da onların yerine geçen kişiler kullanıcıyla birlikte hazırlar: kullanıcının istekleri kullanıcı öyküleri (use case'ler) olarak yazılır ve önceliklendirilir, yani hangilerinin önce yazılım haline getirileceği belirlenir. Koşu en fazla dört hafta sürmelidir; örneğin bir hafta ya da dört hafta olabilir. Koşu başındaki toplantıda o koşuda hangi use case'lerin çalışır hale getirilip test edileceği belirlenir ve iş dağıtımı yapılır.

Günlük toplantılarda her ekip üyesi kendisine verilen işlerin ne kadarını tamamladığını, ne kadarını tamamlayamadığını söylemek zorundadır; karşılaşılan engeller ve sıradaki işler belirtilir. Böylece bilgi birikimi (know-how) oluşur ve herkes birbirine karşı sorumludur.

### 10.2 Scrum adının kaynağı ve toplantılar

Scrum'da toplantılar mümkün olduğunca kısa ve motive edici olmalıdır. Uzun sürmesin diye bütün ekip ayakta toplantı yapar; toplantının bir sonraki çalışmaya itici bir güç sağlaması önemlidir. Hoca adı, oyuncuların maç arasında yaptığı kısa ve itici güç yaratmaya çalışan toplanmalara benzetir.

> **Ders sonrası not:** Hoca bu toplanmaları "Amerikan rugby futbolu" ile ilişkilendirdi; "scrum" terimi büyük olasılıkla rugby union'daki hücum düzeninden (oyuncuların omuz omuza toplanması) gelir, Amerikan futbolundan değil.

Toplantılar kademelidir: günlük toplantılar, haftalık toplantılar ve örneğin dört haftalık işin toplantıları. Kapsam kademe kademe genişlerken hedefler küçültülerek her güne aktarılır.

> **Hocanın vurgusu:** XP ilk kullanılan çevik yazılım geliştirme süreç modelidir, Scrum ise şu anda sektörde en fazla kullanılan modeldir. Bunu hakkıyla kullananlar da vardır, işi yalnız programcılığa döndürüp buna Scrum diyenler de vardır.

### 10.3 Ürün sahibi, backlog ve sprint

Dersin sonunda hoca Scrum'ı bir kez daha toparlar. Ürün sahibi (product owner) bir **ürün backlog'u** oluşturur: ürünü geliştirmek için nasıl bir çevrim yapılması gerektiği belirlenir. Takım ve ürün sahibi bir koşuda (sprint) yapılacak işleri birlikte belirler. Bu yüzden Scrum şekilleri iç içe döngüler halinde çizilir: 24 saatlik (günlük) işler ve 30 günlük işler; 30 günden uzun sprint belirlenmez, gerekirse yeni bir backlog tanımlanır. Sprintler genellikle 2-4 haftalıktır ve her sprintin sonunda yeni bir sürüm elde edilir.

Scrum'da öne çıkan kavramlar sırasıyla şunlardır: kapsamın belirlenmesi, bu kapsamı gerçekleştirmek için ürün backlog'larının oluşturulması, gereksinimlerin belirlenmesi, koşuların planlanması için bir toplantı (sprint planlama) ve her iş bittiğinde işlerin gözden geçirilmesi (sprint review).

Use case'lerin (kullanıcı hikayelerinin) önceliklendirilmesinde en riskli olandan ya da dağıtımının en önce yapılması istenen, en gerekli olandan başlanabilir.

## 11. XP Döngüsünün Şekil Üzerinden Tekrarı

Üçüncü bölümün başında hoca XP'yi slayttaki şekil üzerinden adım adım tekrarlar (ekrandan, 02:05:00; şekil 00:25:00'ta da görünür). Şekildeki döngü metin olarak şöyledir:

```text
planning (planlama)
  - user stories (kullanıcı öyküleri)
  - values (değerler)
  - acceptance test criteria (kabul test kriterleri)
  - iteration plan (iterasyon planı)
      |
design (tasarım)
  - simple design (basit tasarım), CRC cards
  - spike solutions (prototypes)
      |
coding (kodlama)
  - pair programming
  - refactoring (kodlamadan tasarıma dönen küçük döngü)
      |
test
  - unit test, continuous integration
  - acceptance testing
      |
Release: software increment, project velocity computed
  (yayım: yazılım artımı; proje hızı hesaplanır) --> planlamaya geri
```

XP artımlı bir süreç modelidir ve çevik yaklaşıma dahildir. Planlama sırasında kullanıcı hikayeleri alınır, değerlendirilir; test güdümlü geliştirme geçerli olduğu için kabul test kriterleri de planlamada oluşturulur ve iterasyon planı yapılır. Tasarımda basit bir tasarım yapılır ve CRC kartları kullanılır; şekildeki spike solution'lar aslında prototiplerdir. CRC kartları ve prototiplerle tasarım yapılmasının amacı müşteriyle birlikte çalışabilmektir.

Kodlamada eşli programlama kullanılır ve tasarımda tanımlananlar kodlanır. Sonuçtan memnun kalınmazsa ya da tasarımda eksiklikler görülürse tasarım değiştirilir; refactoring kavramı burada kullanılır. Kodlama sırasında birim test de yapılır. Test aşamasında sürekli bütünleştirme vardır: bir kod ya da tasarım parçası gerçekleştirilip birim testten geçtikten sonra diğerleriyle bütünlük testiyle birleştirilir. Müşteri kabul testini yapar ve yeni bir yayım, yani yeni bir yazılım artımı çıkar. Bu sırada proje hızı hesaplanır ve plan bu hıza göre dinamik olarak güncellenir.

## 12. Scrum ile Diğer Modellerin Karşılaştırması

Slayttaki "Scrum ve Diğer Modeller" tablosu (ekrandan, 02:10:00):

| Kriter | Waterfall | Spiral | İteratif | Scrum |
|---|---|---|---|---|
| Tanımlı süreçler | Gerekli | Gerekli | Gerekli | Planlama ve kapatma aşamasında |
| Final ürün | Planlamada tanımlanmış | Planlamada tanımlanmış | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Proje maliyeti | Planlama esnasında hesaplanıyor | Kısmen değişken | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Tamamlanma tarihi | Planlama esnasında belirleniyor | Kısmen değişken | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Dış çevreye duyarlılık | Sadece planlamada | Planlama öncelikli | İterasyon sonlarında | Her zaman |
| Takım esnekliği, yaratıcılığı | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | İterasyonlar boyunca yaratıcılıkta ve esneklikte limit yok |
| Bilirkişi desteği (harici) | Proje eğitimi esnasında | Proje eğitimi esnasında | Proje eğitimi esnasında | Gerekirse proje içinde takıma bile dahil edilebiliyor |
| Başarı olasılığı | Düşük | Orta düşüklükte | Orta seviye | Yüksek |

Hoca tabloyu satır satır yorumlar:

- **Tanımlı süreçler:** Şelalede ve spiralde süreç tanımları gereklidir; Scrum'da süreç tanımları yalnız planlama ve projenin kapatılması aşamasında verilir.
- **Final ürün:** Şelalede ve spiralde planlamada tanımlanır; Scrum'da proje esnasında şekillenir, iş olgunlaştıkça son ürün hakkında bilgi verilir.
- **Proje maliyeti:** Şelalede planlama sırasında hesaplanır. Spiralde kısmen değişkendir, çünkü spiraldeki her döngüde plan yenilenir. Scrum'da proje esnasında şekillenir.
- **Tamamlanma tarihi:** Şelalede planlama sırasında, doğru ya da yanlış, bir tarih belirlenir. Bu tarih çoğu zaman tutmadığı için şelalede proje başarısız ya da gecikmiş gibi görünür. Oysa maliyet proje ilerledikçe şekillenir; Scrum'da bir süre sonra gerçekçi bir fikir verilebilir.
- **Dış çevreye duyarlılık:** Dış çevrede gerçekleşen uygulamalardan etkilenme demektir. Şelalede yalnız planlamada vardır; Scrum'da süreç her zaman dış çevredeki çalışmalara göre kendini ayarlar.
- **Takım esnekliği ve yaratıcılığı:** Şelalede istekler baştan belirlenir, fazla yaratıcılık ve esneklik desteklenmez. Spiralde plan yenilense de takım yapısı ve kişilere verilen görevler çok esnek değildir. Scrum'da iterasyonlar boyunca yaratıcılıkta ve esneklikte limit yoktur; ekip yapısı değişebilir. Bu yüzden kod ve yapılan işler anonimdir, herkes her konuyu bilir; analizdeki bir kişinin teste ya da tasarıma kaydırılması mümkündür. Hoca bunun çalışanlar için hem bir olanak hem de bir tehlike olduğunu söyler.
- **Bilirkişi desteği:** Klasik modellerde dışarıdan uzman desteği proje eğitimi sırasında alınır; Scrum'da Scrum Master denilen Scrum uzmanları proje içinde takıma bile dahil edilebilir.
- **Başarı olasılığı:** Scrum'da daha yüksek görünür, ama yüzde yüz değildir ve projeye göre değişir.

Hoca, ulusal yazılım mühendisliği sempozyumlarında çevik yaklaşımın gerçek çözüm olup olmadığını, klasik süreçlerle karşılaştırıldığında iyi ve kötü taraflarını sorgulayan bildirilerin sunulmaya başlandığını aktarır. Yine de zaman kazandırdığı için çevik yaklaşımların uzun süre kullanılmaya devam edeceği görülmektedir.

## 13. Kanban

### 13.1 Tanım ve kökeni

Slayt (ekrandan, 02:15:00 ve 02:20:00):

- Az sayıda görevi akıcı ve eşzamanlı yönetebilmeyi sağlar.
- Japonya, Toyota'da ilk kullanılmıştır.
- Sinyal veya büyük görsel tahta anlamındadır.
- Evrimsel değişim çerçevesidir.
- Müşteri ihtiyaçlarını anla ve odaklan.
- İnsanları değil işi yönet.
- Ekosistemi sürekli gözden geçir.
- İş listesinde sürekli değişiklik varsa Kanban tercih edilir.

Az sayıda görevi akıcı ve eş zamanlı yönetmek isteniyorsa Kanban kullanmak daha uygundur. "Büyük görsel tahta" anlamı Scrum'daki Scrum Board'a benzer: tahtaya yapılacak işler ve bunların ne kadarının gerçekleştirildiği yazılır. Kanban, süpermarket raflarındaki malların stoklanmasının gözlenmesinden ve üretim bandında yürüyen kaynakların görselleştirilmesinden doğmuş bir üretim yönetimi biçimidir: süreç hakkında bilgi sahibi olmak, süreci yönetmek ve işleri belirlemek için kullanılır. Kanban felsefesi 1940'ların sonlarından beri kullanılmaktadır; 2000'li yıllardan itibaren Kanban yöntemi çevik yazılım süreçlerinde de kullanılmaya başlanmıştır.

Kanban'ın temel felsefelerinden biri önce müşteri ihtiyaçlarını anlamak ve bunlara odaklanmaktır. Bir diğeri insanları değil işi yönetmektir; bu yüzden büyük görsel tahtada iş listesi üzerinden gidilir. Ekosistem sürekli gözden geçirilir.

### 13.2 Kanban tahtası

Kanban'da süreklilik vardır, geliştirme sürekli yapılır, ama esas olan iş listesi ve onun ne kadarının gerçekleştirildiğidir. Tahtada farklı renklerde yapışkan notlar (post-it) kullanılır; hocanın verdiği örnekte kullanıcı hikayeleri mor, verilen görevler turkuaz, yapılacak işle ilgili tanımlanmış özellikler kırmızı renktedir. Bu işler ilgili kişiler tarafından işlenip bitmiş işler sütununa aktarılır. Tahtanın sütunları şunlardır: yapılacaklar (to do), planlananlar, geliştirilenler, test edilenler, dağıtıma hazır hale getirilenler ve tamamlananlar (done). Hangi kullanıcı hikayelerinin tanımlandığı da tahtada belirtilir. <!-- BELİRSİZ: Kanban tahtası görseli karelerde yok; sütunlar ve renkler altyazıdan aktarıldı. -->

Hoca bu arada XP'nin yaratıcılarından ve çevik yaklaşımın öncülerinden Kent Beck'i anar ve XP'nin önemli taraflarını yeniden sayar: oyun planlama, test odaklı geliştirme, tüm ekibin birlikte çalışması, sürekli entegrasyon, tasarım gelişmeleri için refactoring ve küçük sürümler.

**Soru:** Kanban yazılım geliştirme süreçleri için ortaya çıkmamış herhalde, Toyota'da kullanıldığına göre? **Cevap:** Evet. Kanban bir üretim yönetimi modelidir; 1940'larda Toyota'da üretim bantlarında daha etkin bir yapı kurmak için kullanılmaya başlanmış, üretimde bir kalite modeline dönüşmüş ve sonra çevik yazılım geliştirme modelleri arasında da kendini göstermiştir.

## 14. XP, Scrum ve Kanban Karşılaştırması

Dersin sonunda üç çevik yaklaşım birkaç açıdan karşılaştırılır:

- **Odak ve değerler:** Kanban'da çok görevliliği azaltmaya, boşa geçen zamanı azaltmaya ve müşteri ihtiyaçlarını en öncelikli değerlendirmeye odaklanılır. Scrum'da ekibin ortak kararı, her sprintte doğru olduğunu düşündüğün şeyi yapma cesareti, karşılaşılan zorluklara karşı açık sözlülük (yapılamayan işin neden yapılamadığını ekibin bütün üyelerinin belirtmesi) ve herkesin elinden gelenin en iyisini yaptığına inanma, yani saygı öne çıkar. XP'nin değerleri iletişim, basitlik, geri bildirim ve cesarettir; bunlara saygı da eklenebilir.
- **Değişiklik:** Yazılımda geliştirilmiş bir özellikten vazgeçilecek ya da değiştirilecekse Kanban'da mevcut plan değiştirilebilir. Scrum'da bu biraz daha zordur. XP'de geliştirilmiş bir özellik başka bir iterasyonda değiştirilebilir.
- **Roller:** Kanban'da roller yoktur, çünkü "insanları değil işi yönet" ilkesi geçerlidir. Scrum'da roller net tanımlıdır: Product Owner (ürün sahibi), Scrum Master ve geliştirme ekibi. XP'de müşteri ve ekip vardır, ekip içinde ayrım yoktur.
- **Önceliklendirme:** XP'de müşteri işleri nasıl önceliklendiriyorsa ona uyulur. Scrum'da sprintte işleme alınacak işler takım tarafından belirlenir. Kanban'da da müşteri ihtiyaçları en önceliklidir.

> **Hocanın vurgusu:** Çevik süreçlere bu kadar zaman ayrılmasının nedeni sektörde çok kullanılmalarıdır. İş hayatında en çok Scrum ve XP üzerinde durulur, ama Kanban'ın da adı geçer.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:45): Şimdiye kadar gördüğümüz klasik yazılım geliştirme süreç modellerinden üç tanesini sayınız.

> **Çözüm (derste verilen tekrara göre):** Şelale (waterfall, lineer) modeli, prototip modeli, spiral model, RAD (Rapid Application Development), Unified Process; özel bir model olarak V modeli de anılmıştır.

**Soru 2** (derste sözlü, 00:25:19): Spiral modelin özelliği neydi, nasıl bir çalışma şekli vardır?

> **Çözüm (derste verildi, 00:26:55):** Spiral model şelale ile prototip modelinin karışımıdır ve risk analizini sürece katar. En içteki evrede prototip, sonraki evrelerde kullanılacak ürün geliştirilir, ürün zenginleştirilir ve bakımı yapılır. Her evrede altı alt adım tekrarlanır: müşteriyle iletişim, planlama, risk analizi, modelleme, construction (ayrıntılı tasarım, kodlama, mühendislik testi) ve dağıtım ile müşteri değerlendirmesi. Bu yüzden artımlı ve evrimsel bir modeldir.

**Soru 3** (derste sözlü, 01:24:59): XP nasıl bir yazılım geliştirme süreç modelidir, temel özellikleri nelerdir?

> **Çözüm (derste verildi, 01:27:53 - 01:29:43):** XP çevik ve **artımlı** bir yazılım geliştirme süreç modelidir: uzun süreli geliştirme yerine kısa aralıklarla yayımlar (release) yapılır ve hatalar erken test edilir. Kodlamada eşli programlama, sınamada test güdümlü geliştirme kullanılır. Müşteri ekibin bir parçasıdır: müşteri tarafından seçilen temsilciler sürekli ekipte yer alır ve bilgi verir, değerlendirme yapar.

**Soru 4** (derste sözlü, 01:31:39): CRC kartı nedir, açılımı nedir?

> **Çözüm (derste verildi, 01:33:04 - 01:34:04):** CRC, Class (sınıf), Responsibility (sorumluluk), Collaboration (iş birlikçi) demektir. Kartta her sınıfın adı, açıklaması, üst ve alt sınıfları, sorumlulukları (hangi işlemleri yaptığı) ve bu sorumluluklar için iş birliği yaptığı sınıflar yazılır. Örnek olarak Satış sınıfının iş birlikçileri Ödeme ve Mal sınıflarıdır.

## Dersin Toparlaması

Bu derste önce klasik süreç modelleri (şelale, prototip, spiral, RAD, Unified Process) tekrar edildi ve Unified Process'in dört evresi ile ürünleri ayrıntılandırıldı. Ardından çevik yaklaşımların, artan müşteri taleplerini hızla karşılamak ve geç gelen gereksinim değişikliklerine uyum sağlamak için doğduğu, çevik manifestonun 12 ilkesi ve "bireyler ve etkileşimler, çalışan yazılım, müşteri katılımı, değişime uyum" karşıtlıkları üzerinden anlatıldı. Çevik yaklaşımın belgesiz ya da plansız çalışmak olmadığı, belgelerin ve planın gerekli olduğu kadar ve dinamik biçimde tutulduğu vurgulandı.

Çevik modellerden XP; dört değeri, planlama-tasarım-kodlama-sınama döngüsü, CRC kartları, eşli programlama ve test güdümlü geliştirmeyle ele alındı. Scrum; görev listesi, koşu ve işlev gösterimi adımları, günlük kısa toplantılar, roller ve klasik modellerle karşılaştırma tablosuyla anlatıldı. Kanban ise Toyota kökenli, "insanları değil işi yönet" ilkesine dayanan, büyük görsel tahta üzerinden işi izleyen bir yöntem olarak tanıtıldı ve üç yaklaşım değerler, değişiklik, roller ve önceliklendirme açısından karşılaştırıldı. Bir sonraki derste gereksinim analizine ve onunla ilişkili kalite özelliklerine geçileceği belirtildi; yazılım geliştiren birimlerin iyileştirilmesine yönelik modeller kalite kavramından sonraya bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
