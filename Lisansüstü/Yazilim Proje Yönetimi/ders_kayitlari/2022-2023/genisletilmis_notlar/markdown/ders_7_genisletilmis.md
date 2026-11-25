# Ders 7 Genişletilmiş Notu: Proje Planlama: Aktiviteler, WBS, Tahmin, Kaynak Atama, Bütçe, Proje Planı ve Risk Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Proje Planlamanın On Beş Aktivitesi
- 2. Aktivite Bağımlılıkları, Gecikme ve Öncelenme Süreleri
- 3. İş Kırılım Yapısı ve Kilometre Taşları
- 4. Kalite Planı ve Gözden Geçirmeler
- 5. WBS Numaralandırma, Bileşenler ve Aktivite Tanımı
- 6. Efor ve Süre Tahmini
- 7. Takvim, Kritik Yol ve Gantt Diyagramı
- 8. Kaynak Atama ve Seviyelendirme
- 9. Takvim ve Bütçeyi Müşteri Gereksinimine Uydurma
- 10. Proje Bütçesi ve Nakit Akışı
- 11. Proje Belgeleri, Devreye Alma ve Eğitim
- 12. Tamamlanma Kriterleri ve Kabul Testi
- 13. İletişim Planı ve Paydaşlar
- 14. Proje Planının İçeriği
- 15. Risk Yönetimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Proje Planlamanın On Beş Aktivitesi

Ders, bir önceki hafta MS Project ile yapılan uygulamanın ardından planlama konusuna devam etti. Takip edilen kitap "Information Systems Project Management" kitabıdır; hoca ekranda kitabın planlama bölümünü açtı. Bu bölümün sonunda bir örnek proje planı bulunur ve derste planın kalitesinin nasıl kurulacağı ile risklerin üzerinde de durulacağı belirtildi.

Kitaba göre bir projeyi planlamak şu on beş aktiviteden oluşur (ekrandan, 00:10:00):

- 1. Proje risklerini tanımlamak ve onları azaltacak eylemleri belirlemek (Defining project risks and identifying actions to mitigate them)
- 2. Proje kabullerini ve kısıtlarını listelemek (Listing the project assumptions and constraints)
- 3. Kalitenin nasıl yönetileceğini belirlemek (Identifying how quality will be managed)
- 4. Aktivite ve maliyet bileşenleri listesini oluşturmak (Constructing a list of activities and cost components)
- 5. Aktiviteler arası bağımlılıkları kurmak (Establishing dependencies between activities)
- 6. Efor ve maliyetleri tahmin etmek (Estimating effort and costs)
- 7. İş takvimini ve kilometre taşlarını hazırlamak (Preparing a schedule and milestones)
- 8. Proje kaynaklarını atamak ve seviyelendirmek (Assigning and leveling project resources)
- 9. Bütçe ve takvimi müşteri gereksinimlerine uydurmak (Aligning the budget and schedule to client requirements)
- 10. Proje bütçesini hazırlamak (Preparing the project budget)
- 11. Proje belgelerini yönetmek (Managing project paperwork)
- 12. Devreye almayı planlamak (Planning for implementation)
- 13. Tamamlanmayı planlamak (Planning for completion)
- 14. İletişimi planlamak (Planning for communications)
- 15. Proje planını yazmak (Writing the project plan)

Hoca bu listenin birinci maddesini (riskler) dersin sonuna bıraktığını, önce diğer adımları özetleyeceğini söyledi. İkinci madde olan kabul ve kısıtlar, riskler ile aynı maddeler üzerinde yürür: kabuller olumlu, kısıtlar olumsuz maddelerdir.

Planlamanın başlangıç noktası bir önceki aşamadır. Projenin tanımlanması (defining the project) aşamasının sonunda hangi süreç modelinin kullanılacağı belirlenmiştir. Dördüncü adımda aktiviteler bu süreç modeline göre listelenir; her aktivitenin kaç gün süreceği ve kaç çalışan gerektirdiği belirlenir. Hangi aktivitenin hangisinden sonra geleceği, aktivitelerin öncelik sırası ve aynı anda yürüyebilecek aktiviteler de burada ortaya çıkar. Aktivite listesinin oluşturulması ile aktiviteler arası bağımlılıkların kurulması birbirini tamamlayan işlerdir.

Ardından her aktivitedeki iş gücü, dolayısıyla maliyet hesaplanır. Hoca burada yazılım projelerinin diğer alanlardan farkını vurguladı: pek çok alanda maliyetin ağırlığı donanımdadır, ama yazılım projelerinde iş gücü ağırlıklıdır. Donanım fiyatları ucuzladıkça iş gücü daha da öne çıkmıştır. Bu yüzden yazılım projelerinde iş gücünü tahmin etmek, maliyeti tahmin etmekle neredeyse eşdeğerdir.

> **Hocanın vurgusu:** Planlama adımları dördüncü, beşinci, altıncı, yedinci adım diye sıralanmış gibi görünse de hepsi iç içe geçer. Aktiviteler belirlenir, bağlılıklar verilir, iş listesi (WBS) oluşturulur, kilometre taşları belirlenir; bunlar birlikte yürür.

## 2. Aktivite Bağımlılıkları, Gecikme ve Öncelenme Süreleri

Aktiviteler arası bağımlılık önceki hafta da konuşulmuştu. Hoca bunları kitaptaki "Types of Activity Dependency" tablosu üzerinden yeniden özetledi (ekrandan, 00:05:00). Tabloda her bağımlılık türü için öncül (predecessor), ardıl (successor) ve izin verilen (permissible) başlangıç-bitiş ilişkisi gösterilir:

- **Finish-Start (Bitiş-Başlangıç):** En sık görülen türdür. Öncül bitmeden ardıl başlayamaz.
- **Start-Start (Başlangıç-Başlangıç):** Ardılın başlaması için öncülün başlamış olması gerekir. Hocanın örneği: modelleme başlayacaksa bilgi toplamanın en azından başlamış olması gerekir.
- **Finish-Finish (Bitiş-Bitiş):** Bir işe "bitti" denmesi için başka bir işin bitmiş olması gerekir. Hocanın örneği: belgelemenin bitti denebilmesi için kodlama dahil yazılım geliştirmenin bitmiş olması gerekir; ancak o zaman belgeleme de bitti denebilir.

Start-Start ilişkisine bir gecikme süresi (lag time) de eklenebilir. Hoca bunu öğrencilerin kendi çalışmalarından bildikleri bir durumla açıkladı: bilgi toplamaya başladığınız anda hemen bir use case diyagramı çizemezsiniz. Bilgi toplamaya başladıktan belki iki gün sonra ancak bir use case ya da sınıf diyagramı çizmek mümkün olur. Bu durumda modelleme, bilgi toplamanın başlamasından "şu kadar gün sonra" başlar.

Kitaptaki "Lag and Lead Times" bölümü bu kavramları şöyle tanımlar (ekrandan, 00:05:00): bütün bağımlılıklar anlık değildir. Gecikme süresi (lag time), öncülün başlangıcı ya da bitişi ile ardılın başlangıcı ya da bitişi arasındaki süredir. Öncelenme süresi (lead time) ise bağımlılıklar arasındaki örtüşmedir. Bu süreler isteğe bağlı kaymalar değildir; aktivitelerin doğasından gelir. Kitabın örneğinde ekipmanın kurulumu, satın alma siparişinin verilmesine Finish-Start bağımlıdır, ama kurulum ekipman fiilen teslim edilene kadar başlayamaz. Satıcının siparişi alması, işlemesi ve teslim etmesi için geçen süre kadar bir gecikme vardır; yani kurulum, sipariş verilmesine gecikmeli Finish-Start bağımlıdır. Kitapta bir öncelenme örneği de vardır: program kodlama, programlama standartlarının tamamlanmasına Finish-Start bağımlıdır, ama standartların taslağı hazırlanıp kodlamaya standartlar kesinleşmeden başlanabilir.

Hoca dersin ilerleyen kısmında bu konuya tekrar döndü: bağlılıklar tanımlanırken süreç modelinin ve işin yapısının iyi incelenmesi gerekir. Yapılacak temel yazılım geliştirme işindeki aktiviteler ve aralarındaki bağlılıklar modele göre doğru kurulmalıdır. Bu bağlılıklar bir bağlılık-öncelik diyagramı olarak da gösterilebilir.

## 3. İş Kırılım Yapısı ve Kilometre Taşları

Önceki hafta Gantt diyagramı ve PERT de konuşulmuştu. Burada iş listesi, iş kırılım yapısının (Work Breakdown Structure, WBS) seviyelendirilmiş halidir: hangi işlerin hangi işlerin alt adımları olduğunu gösterir. WBS istenirse bir ağaç yapısıyla, istenirse numaralandırarak gösterilebilir. Kitabın tavsiye ettiği gibi numaralandırma yapılırken aralarda boşluk bırakılabilir; böylece sonradan araya yeni işler eklenebilir.

Yedinci aşama, iş listesini tam olarak oluşturmak ve kilometre taşlarını (milestone) belirlemektir. Kilometre taşları yine modele göre belirlenir. Örneğin şelale modeli seçilmişse kilometre taşları bellidir: her temel iş adımı bittiğinde bir kilometre taşı konur. Gereksinim analizi bitti bir kilometre taşı, ön tasarım bitti bir kilometre taşı, ayrıntılı tasarım bitti bir kilometre taşı.

Kilometre taşları önemlidir, çünkü gözden geçirmeler (review) bu noktalarda gerçekleşir. Bu, üçüncü adımdaki kalitenin nasıl yönetileceği konusuyla doğrudan bağlantılıdır.

## 4. Kalite Planı ve Gözden Geçirmeler

### 4.1 Gözden geçirmenin zamanlaması

Kalite yönetiminde en önemli şey gözden geçirmelerin kurallarını kurmaktır: gözden geçirmenin nasıl olacağının tanımlanması. Gözden geçirmeler kilometre taşlarına ya da iş aktivitelerine göre yapılabilir.

Dışarıdan desteklenen bir projede ise durum farklıdır. Hoca örnek olarak TÜBİTAK ya da Sanayi Bakanlığı gibi bir destekleyici kurumu verdi. Böyle bir kurum "gereksinim analizini bitirdiniz mi, gelip kontrol edelim" demez; örneğin altı ayda bir gözden geçirme yapar. Projenin kendi iç gözden geçirmeleri ayrıdır; dışarıdaki sponsorun gözden geçirmesi aslında bir denetim gibidir. Bu tür projelerde kalite değerlendirmesi zamana göre de planlanmalıdır.

### 4.2 Kalite planlamada hata kaynakları ve ölçme

Kalite planlamada hataların nerelerde bulunabileceği (hata kaynakları), gözden geçirmelerin nasıl olacağı ve kalitenin nasıl ölçüleceği üzerinde durulur. Hoca kitaptaki bir tabloyu gösterip bunun kendisi için çok önemli olmadığını söyledi. Kitap, kalitenin temel ölçümlerinin olmaması (There Are No Baseline Measurements of Quality) sorununa da değinir: müşterinin hata oranı ölçümleri yoksa, kaliteyi diğer müşteri projelerine göre ne kadar iyi yönettiğinizi belirleyemezsiniz. Önerilen eylem, ölçüm hiç yoksa ölçmeye en çok gereken alanlara (tipik olarak bütünleştirme, sistem testi ve kabul) odaklanmak ve iş planında akran gözden geçirmelerine (peer review) zaman ayırmaktır (ekrandan, 00:20:00).

### 4.3 Gözden geçirme türleri

Kalite dersini alanlar walkthrough kavramını bilir. Gözden geçirmenin (review) birkaç şekli vardır ve en ayrıntılısı incelemedir (inspection):

- **Gözden geçirme (review):** Daha az formal, daha kaba bir gözden geçirme.
- **Walkthrough:** Biraz daha ayrıntılı; hangi projenin hangi aktivitelerle gözden geçirildiği, hangi işlemlerin yapıldığı adım adım izlenir.
- **İnceleme (inspection):** En ayrıntılı ve formal gözden geçirme.

### 4.4 Kalite planının içeriği

Kalite planında esas olan, gözden geçirme kurallarının ve gözden geçirme takviminin oluşturulması ile gözden geçirme ekibinin belirlenmesidir. Ders boyunca sayılan maddeler şöyle toplanabilir:

- Kaliteyi sağlamak için önce uygun bir proje süreç modelinin seçilmesi.
- Hangi aşamada genel gözden geçirme, hangi aşamada walkthrough, hangi aşamada inspection yapılacağı.
- Gözden geçirme ekibinin hangi kişilerden oluşacağı, ekipten mi dışarıdan mı olacağı ve her üyenin gözden geçirmedeki hedefi.
- Gözden geçirmelerin hangi aralıklarla yapılacağı; kilometre taşlarında yapılacaksa kurallarının ne olduğu.
- Gözden geçirme yerine test yapıldığında hangi test kurallarının geçerli olacağı.
- Sürüm (versiyon) kontrolü: yazılım teslim edildikten sonra oluşturulan yeni sürümlerin de gözden geçirilmesi, her sürümde nelerin dağıtılacağı, sürümler arasındaki farkların ve temel değişikliklerin nasıl tanımlanacağı. Bu, sürüm yönetimini kapsar.
- Kalitenin nasıl ölçüleceği.

## 5. WBS Numaralandırma, Bileşenler ve Aktivite Tanımı

### 5.1 Numaralandırma

Önceki hafta yapılan örnekte WBS numaralandırması şöyle gösterilmişti: temel adım 1.0 gibi bir numarayla, onun altındaki ikinci seviye adımlar 5'er artan numaralarla (1.5, 1.10, 1.15 gibi) verilir. Kitaptaki örnek WBS (Exhibit 4.10) da bu yapıdadır; son satırlarında "25.10 Provide support for implementation" ve "25.15 Conduct post-implementation review" görünür (ekrandan, 00:25:00).

Kitabın "Numbering a Work Breakdown Structure" bölümüne göre (ekrandan, 00:25:00):

- WBS hiyerarşik olduğu için öğeleri seviyelerle numaralandırılabilir; örneğin 10.20.15 üçüncü seviyede bir öğedir.
- WBS numaralarının en önemli kullanımlarından biri zaman raporlamasıdır: ekip üyeleri zamanlarını WBS numarasıyla tanımlanan aktivitelere yazar. Numaralar takvimdeki aktiviteleri ve bütçedeki maliyetleri de tanımlar.
- Proje başladıktan sonra aktiviteler kolayca yeniden numaralandırılamaz; bu yüzden araya aktivite ya da maliyet eklenebilecek biçimde boşluklu numara kullanmak akıllıcadır.
- WBS, görece kararlı hale gelene kadar, yani kurum yönetimi ve kıdemli teknik ekip gözden geçirip az değişiklik kalana kadar numaralandırılmamalıdır. Aksi halde elle yeniden numaralandırma ve numaraların her yerde tutarlı olmasını sağlama zahmeti yaşanır.

İkinci seviyedeki bir aktivite daha da ayrıntılandırılabilir. Kitaptaki örnekte "donanım seçimi ve donanımın satın alınması" birinci seviye işin altında donanım seçimi ikinci seviyededir, donanım seçiminin alt adımları üçüncü seviyedir; değerlendirme ve değerlendirmenin alt adımları ise dördüncü seviyeye kadar iner. WBS yalnız numarayla, girintili yazımla ya da ağaç şekliyle gösterilebilir; öğrenciler kendi projelerinde bunlardan herhangi birini kullanabilir. Tanımlandıktan sonra WBS Gantt diyagramına geçirilir. Bunun için çok sayıda proje yönetimi aracı vardır; hoca MS Project'i önerdi. Bu örneklemeyi herhangi bir yazılım geliştirme süreç modeli için yapmak mümkündür.

### 5.2 WBS bileşenleri

Kitaba göre WBS en alt seviyede üç tür bileşenden oluşur: iş aktiviteleri (work activities), kilometre taşları ve maliyetler (ekrandan, 00:25:00). Yazılım geliştirme süreç adımları düşünüldüğünde her adım bir aktivite olarak karşımıza çıkar. Yalnız yazılım geliştirme yapılıyorsa gereksinim analizi ve onun alt adımları (bilgi toplama, modelleme, modelin geçerliliğini sağlama, test etme gibi) ve sistemin gerçeklenmesi aşaması birer aktivitedir.

Aktiviteler birbirine bağımlı ya da bağımsız olabilir. Bağımlılığın bir nedeni de ortak kaynaktır: bir aktivitedeki çalışanlardan birinin diğerinde de çalışması gerekebilir; örneğin sistem analistinin bir taraftaki işi bitince diğer tarafta çalışması gerekir. Aktiviteler arasında çok fazla bağımlılık yoksa iş listesini kaydırmak daha kolay olur. Aktivitelerin ne kadar alt parçaya bölündüğü ve nasıl tanımlandığı da önemlidir; proje aşamaları, aktivitelerin seviyelendirilerek gösterilmesiyle ifade edilir.

### 5.3 Aktivite tanımı örneği: Teklif değerlendirme

Bilişim projelerindeki önemli işlerden biri teklif yazma ve gelen tekliflerin değerlendirilmesidir. Donanım ya da yazılım alımı için bir teklif çağrısı, şartname biçiminde yazılır ve satıcılara gönderilir. Gelen tekliflerin gereksinimleri karşılayıp karşılamadığına bakılır. Bu bağlamda sık karşılaşılan kısaltma RFP'dir (Request for Proposal, teklif çağrısı): gereksinimlerin belirtildiği belge.

Kitaptaki aktivite tanım sayfası şu alanlardan oluşur (ekrandan, 00:30:00):

| Alan | Örnekteki değer |
|---|---|
| Project | Proje adı |
| Activity | 5.5.20.5 Evaluate Written Proposals |
| Description | RFP'ye yanıt olarak alınan yazılı teklifleri değerlendirmek |
| Inputs | Gereksinim tanımı (5.5.5); teklif çağrısı (5.5.15); satıcılardan gelen yazılı teklifler |
| Effort | Satıcı tekliflerini gözden geçirmek; gereksinimleri karşılamayan teklifleri reddetmek; teklifleri isteğe bağlı gereksinimleri karşılama derecesine göre ağırlıklandırmak; öneri hazırlamak |
| Resources | Proje yöneticisi (%20); donanım analisti (%80) |

Proje yöneticisi işin yönetimini ve iş ilişkilerini yürütür, ama asıl çalışan donanım analistidir. Aktivitenin çıktıları, değerlendirme sonuçları ve satıcı firmalar hakkında toplanan bilgilerdir. <!-- BELİRSİZ: aktivite tanım sayfasının "Outputs" alanı karede görünmüyor; çıktılar altyazıdan alındı. -->

Bu örnekten çıkan genel kural şudur: WBS içindeki her aktivite için aktivitenin tanımı, girdileri (hangi işlerin daha önce yapılmış olması gerektiği), eforu (yapılacak işler), iş gücü kaynakları ve çıktısı belirtilmelidir.

## 6. Efor ve Süre Tahmini

### 6.1 İş gücü ve zaman tahmini

Projeyi tahmin etmek, ne kadar süreceğini ve ne kadar kaynak gerekeceğini bulmaktır. Önce ne kadar iş gücü gerektiği belirlenir. Her iş gücü kaynağının çalışma yüzdesi verilir (yukarıdaki örnekte donanım analisti %80, proje yöneticisi %20 gibi). İş sınıflandırması, her sınıfın çalışma yüzdesi ve her kişinin kaç saat çalışacağı belirlenir.

İş gücü tahmini önceki çalışmalara dayalı uzman görüşüyle ya da daha istatistiksel yöntemlerle yapılabilir. Zaman tahmini için projenin süreceği iş günleri planlanır. Müşterinin bir önceliği varsa, örneğin kesin bir bitiş tarihi varsa, bu öne alınır: önce bitiş tarihi konur, sonra geri kalan aktiviteler bu tarihe göre sıkıştırılır.

Kitap tahmin yaparken şu kuralları önerir (ekrandan, 00:35:00):

- Dış takvim kısıtlarını (yarı zamanlı çalışma, proje bitiş tarihleri) tahmin sırasında yok saymak; bunlar daha sonra hesaba katılır ama tahmini etkilememelidir.
- Tahminlerin, işi yapacak ya da yapmaya yetkin kişilerce yapılmasını sağlamak. Böylece tahmin daha doğru olur ve tahmin yapan kişi bir taahhüt vermiş olur; bir ekip üyesine "Bunun üç hafta süreceğini söyledin, üç haftan var" demek makuldür.
- Tahminleri bilgili kişilere gözden geçirtmek; özellikle büyük güvenlik payı koyan çalışanların aşırı tahminlerine dikkat etmelerini istemek.

Kitaptaki örnek projenin tahmini iş günü cinsinden verilir (Exhibit 4.15); her aktivite için süre, başlangıç, bitiş ve kaynak (Tech Architect) bilgisi bulunur (ekrandan, 00:35:00). <!-- BELİRSİZ: Exhibit 4.15 karede okunamayacak kadar küçük; değerler aktarılmadı. -->

### 6.2 Tahmindeki tehlikeli alanlar

Hoca tahmindeki tehlikeli alanları şöyle sıraladı:

- **Bütünleştirme şaşkınlığı:** Müşterinin bir tarih önceliği olmadığını, planın projenin başından itibaren kurulduğunu düşünelim. Bütün alt adımlar için hangi iş gücüne ne kadar ihtiyaç olduğu belirlenir ve her işe "gerektiği kadar" zaman ayrılır. En sona gelinip toplandığında çok fazla zaman geçtiği görülür; herkesin iş yükü düşünüldüğünde maliyet de çok yüksek çıkar. O zaman tahminleri sıkıştırarak geri dönüp planı yeniden düzenlemek gerekir.
- **Yeni teknoloji:** Yeni bir yazılım geliştirme ortamı kullanılıyorsa ve ekip bu teknolojiye yakın değilse tahminde kaymalar olur, iş tahmin edilen sürede bitmeyebilir.
- **Yeni metodoloji:** Benzer biçimde yeni bir yöntem de tahmini şaşırtır.
- **Dış bağımlılıklar:** Örneğin alt yükleniciler. Sözleşme iyi yapılmamışsa zamanında teslim alınamayan işler takvimi kaydırır.

Aynı tehlikeler iş gücü tahmini için de geçerlidir; iş gücü tahminleri çok düşük kalabilir. İş gücü yalnız "şu kadar kişi çalışsın" diye değil, sık sık maliyete çevrilerek değerlendirilmelidir: bütçe bu yükü kaldıracak mı? Gerekirse iş yükleri yoğunlaştırılarak gidilir. Plandan sonra, özellikle teslim tarihlerine yakın, bir sıkıştırma evresine geçilebilir.

### 6.3 Proje yöneticisinin konumu ve tahminlerin reddedilmesi

Hoca, proje yöneticisinin tanımını daha önce verdiklerini hatırlattı: proje yöneticisi projeyi yürütür, projenin zamanında, belirlenen bütçeyle ve istenen kapsamda teslim edilmesini sağlar; bunun için ölçümler yapar, zaman tahmini yapar, Gantt diyagramı gibi araçları kullanır. Bunun yanında proje yöneticisi sorumluluğu çok, yetkisi fazla olmayan bir yöneticidir, çünkü üstünde başka yöneticiler vardır. Tahminleri çok yüksek bulan bir üst yönetici bütün planı reddedebilir; o zaman plan sıkıştırılarak ve maliyetler kısılarak yenilenmelidir. Burada da iş gücü özellikle önemlidir.

Kitabın ilgili bölümü (Your Management Rejects Your Estimates as Too High) şunu söyler (ekrandan, 00:40:00): tahminlerinizin geçerli olduğuna inanıyorsanız ve yöneticileriniz bunları düşürmenizi istiyorsa, aslında sizden işe yaramayacak bir tahmin oluşturmanızı istiyorlardır; sorun, sonra o plana göre teslim etmenizin beklenecek olmasıdır. Bu, uzlaşma alanı değildir: sizin ve teknik ekibinizin kanaati işin 1.000 iş günü süreceğiyse, bu tahmini savunmak sizin sorumluluğunuzdur. Yönetim daha az eforla yapılmasında ısrar ederse iki seçenek kalır: planı ayarlamak ya da azaltılmış eforu, tahminin size dayatıldığı notuyla kabul etmek.

## 7. Takvim, Kritik Yol ve Gantt Diyagramı

İş listesinin oluşturulması ve kaynak seviyeleme noktasında PERT analizi kullanılır. Hoca PERT'in açılımını "Project Evolution and Review Technique" olarak verdi.

> **Ders sonrası not:** PERT'in yaygın açılımı "Program Evaluation and Review Technique"tir; hocanın söylediği "Project Evolution" büyük olasılıkla Whisper bozulması ya da dil sürçmesidir.

Basit bir iş listesi düşünelim: modüller kodlanacak, sonra bütünleştirme yapılacak. Bir modülü gerçekleştirirken diğer modülün bitmesine gerek var mı? Bağlılıklar düşünülerek her iş için ne kadar programcı zamanı gerektiği tahmin edilir. Bu yüzden bağlılıkları az, modüler yapıda yazılımlar oluşturulduğunda planlamada da daha serbest kalınır.

Projeyi hızlandırmak için bileşenlerden (component) yararlanılıp yararlanılamayacağına, yeniden kullanılabilir özelliklerin ne kadar katılabileceğine bakılır. Günümüzde yazılımda yeniden kullanılabilirliğin en çok görüldüğü yer tasarım kalıplarıdır; yeniden kullanılabilir kütüphanelerin ne kadar kullanılabildiği de önemlidir. Kritik yolun ve aradaki boşlukların (bolluk) belirlenmesi de bu aşamadadır.

Kilometre taşları, projenin önemli adımlarına konan işaretlerdir. Gantt diyagramı oluşturulduğunda birinci seviye aktivite, ikinci seviye aktivite ve onun alt başlıkları sıralanır; her aktivite için gereken iş gücü gösterilir. Kitaptaki örnek Gantt diyagramında (Exhibit 4.20) "Hardware selection and acquisition" ana aktivitesi, altında "Hardware selection" ("Evaluation" alt grubuyla birlikte) ve "Hardware acquisition" özet aktiviteleri, her alt aktivitenin çubuğunun yanında da atanan kaynak (Tech Architect, bazılarında [50%]) görünür; "RFQ issued" ve "Hardware selected" gibi sıfır süreli satırlar elmas biçiminde kilometre taşıdır (ekrandan, 00:45:00). <!-- BELİRSİZ: Gantt diyagramındaki süre ve tarih değerleri karede net okunmuyor; aktarılmadı. -->

## 8. Kaynak Atama ve Seviyelendirme

### 8.1 Rol düzeyinde ve kişi düzeyinde atama

Aktiviteler sıralanıp her birinin iş gücü ihtiyacı belirlendikten sonra atama aşaması gelir: işe çalışan ataması, yani kaynak ataması. İlk başta rol düzeyinde yüzde verilir. Örneğin proje planının oluşturulması aktivitesinde %70 proje yöneticisi, %20 yazılım uzmanı ve sistem analisti, %10 donanım uzmanı çalışacak denebilir. Seviyelendirme ve kaynak atamada ise doğrudan isim verilir: "sistem analisti Ali ve sistem analisti Veli çalışacak" gibi. Bunlar Gantt diyagramında takip edilebilir. Microsoft Project ya da başka bir proje yönetim aracı Gantt diyagramının oluşturulmasını kolaylaştırır.

Kişi atanırken o kişinin ne kadar kullanılabilir olduğu da belirlenir. Bir sistem analisti A projesinde çalışıyorsa ve B projesine de atanacaksa, A projesindeki yükü %70 ise B projesine ancak %30'unu (ya da %20'sini) ayırabilir. Kişilerin çalışma alanı, aynı zamanda yürüyen projelerle eşleştirilmelidir.

### 8.2 Kaynak gereksinimlerini düzleştirme

Önce herkese bir iş atanır; kişinin işe %100 adanmış mı yoksa başka işleri olduğu için %70 mi çalışacağı belirlenir. Bütün atamalar bitince çalışanlarla birlikte gözden geçirilip kaynak gereksinimleri düzleştirilir. Bunun için yalnız projenin iş listesine değil, kişilerin iş listelerine de bakılır: kişiler arasında büyük farklılık var mı? Bir kişiye çok, başkasına çok az iş verilmişse görev kaydırılır, gerekirse yeni kişi atanır. Hoca bunu bir bölümde asistanlar arasında yapılan görev paylaşımına benzetti: önce herkese görev atanır, sonra kişi listelerine tek tek bakılıp görev kaydırılır ya da yeni kişilere görev eklenir. Ayrıca işe uygun belirli bir uzman kaynak gerekip gerekmediği de yeniden gözden geçirilir.

Plan yapıldıktan sonra yürütme sırasında da bütün bunların üzerinden geçilir. Plana uygun gidiliyorsa belki değişiklik yapılmaz; planın gerisinde (ya da ilerisinde) kalınmışsa işlevlerin azaltılması, proje planı için yeni sürümlerin (release) oluşturulması ya da ilave çalışan gerekebilir.

## 9. Takvim ve Bütçeyi Müşteri Gereksinimine Uydurma

Kitabın bu bölümü müşterinin tarih isteğini iki türe ayırır (ekrandan, 00:50:00). Bazı tarihler kesindir (absolute), bazıları yalnız istenen (desirable) tarihlerdir. Örneğin müşteri sistemi mali yılın başı olduğu için Ocak'ta istiyorsa ama sistem Mart'a kadar hazır olmazsa iki aylık geçmişi girmek zorunda kalacaksa, tarih esnektir. Ayırt etmek için "Bu tarih tutturulamazsa ne olur?" diye sorulur: cevap "yetişmek için çok iş yapmamız gerekir" ise tarih istenen tarihtir; "büyük bir iş fırsatını kaçırır ve 10 milyon dolarlık yatırımı kaybederiz" ise tarih kesindir.

Tarih kesin olsa bile projenin tamamının aynı anda teslim edilmesi gerekmeyebilir. Sistemi sürümlere bölmek (Segment into Releases) mümkündür: kitabın örneğinde çevrimiçi işleme Ocak'a kadar hazır olmalı, ama yönetim raporlaması Mart'a kalabilir. Bunu müşteriye "eksik sistem" olarak değil, sistemin kendi içinde bütünlüklü parçalar halinde geliştirildiği sürüm geliştirme (release development) olarak sunmak gerekir: birinci sürüm çevrimiçi işlemeyi, ikinci sürüm yönetim raporlamasını sağlar. Kesin tarihe gerekenler birinci sürüme konur, ertelenebilen her şey sonraki sürümlere kalır. Sürümlere bölmek de mümkün değilse işlevselliği azaltmak (Reduce Functionality) bir seçenektir.

## 10. Proje Bütçesi ve Nakit Akışı

Aradan sonra hoca bütçeye geçti. Yazılım projelerinde bütçenin esası çalışanlardır. Bütün bir bilişim projesi düşünüldüğünde, donanımın oluşturulmasından bilgi sisteminin teslimine ve eğitimine kadar her aşamada çalışacak kişilerin ücretleri hesaba katılır: gereksinimlerin tanımlanması, satıcıların belirlenmesi, alım taleplerinin hazırlanması ve değerlendirilmesi, iletişim kurulması, referansların kontrolü; yazılım ve donanımın seçimi, alımı, kuruluşu; yazılım geliştirmenin bütün alt başlıkları; bakım-destek planı ve kullanıma alma.

WBS'teki her adımda daha önce nasıl bir görevlendirme yapılmışsa, her görevlinin adam-ay başına alacağı ücret belirlenir. Genel harcamalar ve belli başlı harcamalar da eklenerek bir nakit akışı analizi oluşturulur. Ardından projenin çalışması durumundaki getiriler bununla eşleştirilir. Hoca, projeyi anlama aşamasında "bu proje başlamaya değer mi" sorusu için bu hesabın kabaca yapıldığını hatırlattı. Orada yalnız "ne kadara çıkar, getirisi ne olur, başlayalım mı" seviyesindeydi; burada artık kişilerin adam-ay olarak ne kadar çalışacağı bilindiği için her kalem daha ayrıntılı verilir. Maliyet, yazılım projelerinde iş gücüyle (eforla) orantılıdır; bu yüzden tahminlerin ve ekip büyüklüğünün doğru yapılması gerekir.

Kitaba göre bir proje bütçesi dört tür maliyet kaleminden oluşur: personel ücretleri (staff charges), harcamalar (expenses), sermaye maliyetleri (capital costs) ve ofis genel giderleri (office overhead). Müşteri dönemsel ödeme yapacaksa bütçe bir nakit akışı da içerebilir (ekrandan, 01:00:00). Kitaptaki örnek projenin bütçe parçası (Exhibit 4.21) şöyledir (ekrandan, 00:55:00 ve 01:00:00):

| ID | Aktivite | Sabit maliyet | Toplam maliyet | Baseline | Sapma |
|---|---|---|---|---|---|
| 3 | Define requirements | \$0.00 | \$4,600.00 | \$0.00 | \$4,600.00 |
| 4 | Identify qualified vendors | \$0.00 | \$920.00 | \$0.00 | \$920.00 |
| 5 | Prepare and issue RFQ | \$0.00 | \$4,600.00 | \$0.00 | \$4,600.00 |
| 6 | RFQ issued | \$0.00 | \$0.00 | \$0.00 | \$0.00 |
| 8 | Evaluate written quotations | \$0.00 | \$4,600.00 | \$0.00 | \$4,600.00 |
| 9 | Conduct demos and presentations | \$0.00 | \$9,200.00 | \$0.00 | \$9,200.00 |
| 10 | Check references | \$0.00 | \$920.00 | \$0.00 | \$920.00 |
| 11 | Negotiate terms and prices | \$0.00 | \$1,840.00 | \$0.00 | \$1,840.00 |
| 12 | Make final hardware selection | \$0.00 | \$920.00 | \$0.00 | \$920.00 |
| 13 | Hardware selected | \$0.00 | \$0.00 | \$0.00 | \$0.00 |
| 15 | Purchase and expedite delivery | \$225,000.00 | \$225,920.00 | \$0.00 | \$225,920.00 |
| 16 | Install hardware and system software | \$5,000.00 | \$7,760.00 | \$0.00 | \$7,760.00 |

Baseline henüz kaydedilmediği için sapma sütunu toplam maliyete eşittir. "RFQ issued" ve "Hardware selected" kilometre taşı olduğu için maliyeti sıfırdır. Satın alma aktivitesinde toplam maliyetin büyük kısmı sabit maliyettir (donanımın kendisi); kalan 920 dolar iş gücüdür.

> **Ek bilgi (derste anlatılmadı):** Tablodaki iş gücü maliyetleri saatlik 115 dolarlık tek bir ücretle tutarlıdır (python ile kontrol edildi): 40 saat × 115 = 4.600, 8 saat × 115 = 920, 80 saat × 115 = 9.200, 16 saat × 115 = 1.840; satın almada 225.000 + 8 × 115 = 225.920, kurulumda 5.000 + 24 × 115 = 7.760. Yani örneğin "Define requirements" büyük olasılıkla tek bir teknik mimarın 5 gün tam zamanlı (40 saat) çalışmasıdır. Ücretin kitapta bu değer olduğu derste söylenmedi; büyük olasılıkla örneğin varsayımıdır.

## 11. Proje Belgeleri, Devreye Alma ve Eğitim

### 11.1 Proje belgeleri

Projeden üretilen belgelerin başında proje planı gelir. Planın farklı sürümleri olabilir, çünkü ilk sürümden sonra yürütme aşamasında planda değişiklikler yapılabilir. Plana önemli açıklamalar eklenebilir; toplantı gündemleri (ajanda) ve durum raporları oluşturulur. Bunlar proje planı aşamasındaki belgeler ve materyallerdir.

### 11.2 Devreye alma ve eğitim

Kod oluşturulduktan sonra kullanıma verme aşamasında yapılacaklardan biri eğitimdir. Kitap, birçok projenin devreye almada tökezlediğini, çünkü bunun teknik değil ağırlıkla idari bir iş olduğunu ve teknik ekibin ilgisini çekmediğini belirtir; devreye alma aktiviteleri eğitim, destek devri, müşteri devri, faydalar ve kullanımdan kaldırmalar olarak beş kategoride toplanır (ekrandan, 01:05:00).

Hoca eğitimin iki yönlü olduğunu vurguladı:

- **Proje ekibinin eğitimi:** Yeni bir uygulamaya başlanırken proje üyelerinin eğitilmesi.
- **Kullanıcıların eğitimi:** Projeyi kullanacak kişilerin eğitilmesi.

Planlarken kullanıcı kitlesinin kimlerden oluştuğu ve bilgi düzeyi belirlenir. Yazılım geliştiricilere de gerçekleştirilen işlemler ve veri tabanı desteği konusunda bilgi verilmesi gerekir. Farklı grupların eğitim ihtiyacı farklı olabilir; hangi gruba hangi eğitimin verileceği planlanır. Müşteri tarafında da aynı planlama yapılır.

Kitabın örneği eğitimin kullanıcı etkisi az görünen projelerde bile gerektiğini gösterir: birkaç sunucunun bir ya da iki sunucuda birleştirildiği bir proje kullanıcılar için şeffaf sayılır, ama sunucu adı kullanıcıların ekranında göründüğü için ad değişince kullanıcılar şaşırabilir ve destek hattını aramaya başlayabilir. Bu durumda eğitim basittir: geçişten bir hafta önce, bir gün önce ve geçişin sabahı olmak üzere üç e-posta göndermek yeterlidir. Eğitimde yalnız son kullanıcılar değil, uygulama bakımı, operasyon ve etkilenen destek grupları da düşünülmelidir (ekrandan, 01:05:00).

## 12. Tamamlanma Kriterleri ve Kabul Testi

### 12.1 Tamamlanma kriterleri

> **Hocanın vurgusu:** Bu önemli bir tablodur. Proje planında, projenin her aşamasının tamamlandığını belirten kriterler bulunmalıdır.

Tamamlanma kriterleri proje türüne göre değişir. Uygulama geliştirme projesinde müşteri kabulüne ulaşıldı mı, kullanıcı eğitimi tamamlandı mı, teslim tarihi açısından bir kıyaslama yapıldı mı gibi sorular sorulur. Sistem bütünleştirme projesinin kriterleri farklıdır. Yalnız analiz, spesifikasyon belirleme ya da stratejik planlama projesi de olabilir; bu bir geliştirme projesi değildir. O zaman tamamlanma kriteri, analiz aşamasındaki tespitlerin yerini bulması ve karşı tarafın bunları kullanılabilir olarak kabul etmesidir.

Kitap bunun için bir tamamlanma kriteri formu önerir (Exhibit 4.24, Sample Completion Criteria Form) (ekrandan, 01:10:00). Formda proje adı, tarih ve proje yöneticisi alanları vardır; ardından "Aşağıdakiler bu projenin tamamlanma kriterleridir; bunlar sağlandığında proje tamamlanmış sayılır" cümlesiyle şu maddeler sıralanır, her birinin yanında işaretlenecek bir çizgi bulunur:

- Kullanıcı tanımlı kabul testleri başarıyla tamamlandı.
- Uygulama kullanıcıları eğitildi.
- Uygulama, uygulama bakım ekibi tarafından kabul edildi.
- Yardım masası prosedürleri kuruldu.
- Üretim prosedürleri kuruldu.
- Uygulama üretim (operasyon) tarafından kabul edildi.
- Garanti süresi tamamlandı.

Formun altında iki imza bölümü vardır: proje başında "Bu tamamlanma kriterleri üzerinde anlaşılmıştır" ve proje sonunda "Bu tamamlanma kriterleri sağlanmıştır"; ikisini de müşteri ve proje yöneticisi imzalar. Hoca, her maddenin yanına tik atılarak ya da "yüzde şu kadar yapıldı" yazılarak proje başlangıcından itibaren gerçekleştirilenlerin izlenebileceğini söyledi.

### 12.2 Kabul testiyle ilişkisi

Test dersinden bilinen kabul testi (acceptance test) kavramı burada devreye girer. Hoca, bazı iş yerlerinde kabul testini gerçekleştiren grubun sistem analizi grubuyla eşleştirildiğini daha önce örnek verdiğini hatırlattı. Proje planı ile kullanıcı kabul testi arasında, dolayısıyla gereksinimler ile kabul testi arasında bir ilişki vardır. Kabul testinde şunlara bakılır: yapılanların ne kadarı kabul edildi; gerçekleştirilenler proje kapsamı içinde kaldı mı; proje planındaki ekip sağlanabildi mi; müşteri bunları çalıştırabiliyor mu?

## 13. İletişim Planı ve Paydaşlar

### 13.1 İletişim kararları

Proje yöneticisi görev dağılımından ve görev kontrolünden sorumludur, ama proje planı sırasında iletişim konusunda da kararlar vermelidir. İletişimin üç ekseni vardır: ekibin kendi içindeki iletişim, ekibin müşteriyle iletişimi ve proje yöneticisinin (dolayısıyla ekibin) üst yönetimle ilişkisi.

Proje yöneticisinin bu kararları çok önemlidir, çünkü ekip içindeki sorunları kısa sürede duyabilmelidir. Bir sorun varsa üst yönetim kendiliğinden duymadan önce proje yöneticisi bunu üst yönetime aktarmalıdır: "bu sorun nedeniyle gecikme olacak" ya da "bütçe artışı olacak" gibi. Sorunu bir basamak üste taşımaya yükseltme ya da eskalasyon (escalation) denir.

### 13.2 Paydaş kategorileri

Kitaba göre iletişim planlanırken paydaşların kim olduğu ve onlarla en iyi nasıl iletişim kurulacağı belirlenir. Paydaşlar genelde sekiz kategoriye ayrılır (ekrandan, 01:15:00):

- **Müşteri proje yönetimi (client project management):** Projenin yönetimine ve yönlendirilmesine doğrudan katılan müşteri personeli; müşteri proje yöneticisi, proje sponsoru, müşteri onaylayıcısı ve yönlendirme komitesi üyeleri.
- **Müşteri ekibi (client team):** Projeye doğrudan katılan ve iş ile teknik gereksinimlerin ayrıntılarını sağlayan müşteri personeli.
- **Proje ekibi (project team):** Kendi ekibiniz.
- **Kullanıcılar (users):** Projeye doğrudan katılmayan ama ürün devreye alındığında ondan etkilenen müşteri personeli; ürünü kullanarak, ondan rapor gibi çıktılar alarak ya da işten çıkarma ve görev değişikliklerine maruz kalarak etkilenirler.
- **Müşteri yönetimi (client management):** Müşteri kurumun yöneticileri; projeye doğrudan katılmazlar ama başarısıyla ilgilenirler.
- **Kendi yönetiminiz (your management):** Kendi kurumunuzda ya da bölümünüzde hiyerarşide sizin üstünüzde olan herkes.
- **Alıcı gruplar (recipient groups):** Ürünü teslim alacak ve işletiminden sorumlu olacak gruplar.
- **Dış paydaşlar (external stakeholders).**

Hoca bu yapının bağlama göre nasıl değiştiğini açıkladı. Bir yazılım projesi, bir kurumun yazılım ekibinin aynı kurumdaki başka bir departman için ürettiği bir yazılım olabilir; bir yazılım evinde genel amaçlı bir ürün olabilir; ya da gerçek bir müşteriye, başka bir firmaya üretilen bir ürün olabilir. Yazılım evinde çalışılıyorsa müşteri proje yönetimi ve müşteri ekibi gerçek bir müşteridir. Değilse, örneğin telekomünikasyon alanında çalışan bir şirketin yazılım ekibi için muhasebe departmanı müşteri ekip olur ve o ekipten de birinin görevlendirilmiş olması gerekir. İletişimin nasıl planlandığı ve haberleşmenin nasıl sağlanacağı planda gösterilmelidir.

## 14. Proje Planının İçeriği

### 14.1 Plan başlıkları

Hoca kitaptaki örnek proje planının içindekiler listesi üzerinden, şimdiye kadar görülen adımların plana nasıl yansıdığını özetledi (ekrandan, 01:20:00; 01:25:00; 01:30:00):

- 1. Giriş (Introduction): proje planının amacı.
- 2. Proje tüzüğü (Project Charter): hedef (objective), kapsam (scope), ana teslim edilecekler (major deliverables), iş ihtiyacı ya da fırsat (business need or opportunity), projenin finansal faydaları. Bunların hepsi projeyi anlama ve tanımlama aşamalarında belirlenmişti: proje hangi işletme ihtiyacıyla ya da hangi fırsat nedeniyle doğdu?
- 3. Tamamlanma kriterleri (Completion Criteria): hangi aşamanın bittiğini neyle belirlediğimiz.
- 4. Kabul ve kısıtlar (Assumptions and Constraints): tarih ve bütçeyle ilgili kısıtlar, kabuller ya da teknik kısıtlar.
- 5. İş planı (Workplan): genel yaklaşım, WBS, kilometre taşları, tahmin, bütçe ve nakit akışı analizi. Hoca bunların çoğunun MS Project ile yapılabileceğini söyledi.
- Kapsam (alan) değişikliği yönetimi: müşteri kapsamda değişiklik istediğinde bunun nasıl gerçekleşeceği. Bu konu iki hafta önce projeyi tanımlama aşamasında görülmüştü.
- İş takvimi yönetim planı: proje takvimi, olası kaymalar ve takvim sorunları.
- Maliyet yönetim planı: iş gücü ve çalışan maliyetleri; buradan proje maliyet yapısı kurulur.
- Risk yönetim planı: risklerin yeniden değerlendirilmesi, olasılığı, gerçekleştiğinde maliyeti ve önlemleri; bunların nasıl değerlendirileceği. Örnek planda 10.4 başlığı "Re-Evaluation, Identification, and Notification of Risks" olup altında yeniden değerlendirme, risk tanımlama ve risk bildirme prosedürleri vardır.
- 11. İletişim yönetim planı (Communications Management Plan): giriş, amaç, iletişim mekanizmalarının tanımı ve listesi.
- 12. Kalite yönetim planı (Quality Management Plan): kalite hedefleri (örnek planda uygulama yazılımı hedefleri ve altyapı hedefleri), kalite ölçüleri, kalite kontrolünün nasıl sağlanacağı; review, inspection, walkthrough ve peer review'in ne zaman, nasıl ve kimler tarafından yapılacağı, gözden geçirme ekibinde kimlerin olacağı.
- 13. Proje organizasyonu (Project Organization): organizasyon ve proje rolleri ile sorumlulukları; yönlendirme komitesi (Project Steering Committee), müşteri onaylayıcısı (Customer Approver), müşteri proje yöneticisi (Customer Project Manager), kullanıcı temsilcileri (User Representatives), proje yöneticisi (Project Manager). Proje ekibinin yapısı, aktivitelerde yapılacak işler ve görevlendirme gereksinimleri burada belirlenir. Hoca rol ve ekip yapılarını sonraki derste ayrıca işleyeceğini söyledi.
- 14. Faturalama prosedürleri (Invoicing Procedures): faturalama türü ve prosedürü.
- Ekler: Ek A ayrıntılı proje takvimi, Ek B risk kontrol listelerinin kaynakları, Ek C iş kırılım yapısı. Hoca eklerde risk tablolarının, Gantt ve PERT diyagramlarının, seviyelendirilmiş WBS'in, paydaşların ve kabul-kısıt kontrol listelerinin bulunabileceğini söyledi.

<!-- BELİRSİZ: 5 ile 10 arasındaki başlıkların numaraları karelerde görünmüyor; sıralama altyazıdaki anlatımdan alındı. -->

Hoca bu listenin öğrencilerin hazırlayacağı proje planı için bir örnek olabileceğini belirtti. Ayrıca yazılım proje planları için, belgede nelerin bulunması gerektiğini tanımlayan (bir içerik listesi gibi) standartlar da vardır. <!-- BELİRSİZ: standardın adı altyazıda bozuk ("artırık planı", "ayrıplı standartları"); büyük olasılıkla IEEE yazılım proje yönetim planı standardı kastediliyor. -->

### 14.2 Üst yönetim desteği

İletişim yönetimini anlatırken hoca bir gözlemini paylaştı. Başka bir derste birkaç yıl üst üste sektörden proje yöneticilerini ve yazılım geliştirme ekiplerinden kişileri davet ederek proje başarısı, gerçekleştirdikleri projeler ve nasıl karar verdikleri üzerine konuşturmuş. Öğrenciler sonunda şu yorumu yapmış: proje başarısı için bir sürü madde sayılıyor, ama gelen bütün konuşmacılar aynı şeyi söylüyor; üst yönetim ekip veriyorsa, para veriyorsa, müşteriyle iletişimi sağlıyorsa proje başarılı oluyor. Farklı büyük firmalardan gelen konuşmacılar da aynı şeyi vurgulamış: proje başarısındaki en büyük destek üst yönetim desteğidir.

> **Hocanın vurgusu:** Proje başarısında en önemli etken üst yönetim (sponsor) desteğidir. Bu yüzden iletişim yönetimi planlanmalıdır; sektörde bir sorunu üst tarafa aktarmak anlamına gelen "eskalasyon" kavramı çok geçer.

## 15. Risk Yönetimi

### 15.1 Riskin tanımı

Hoca risk yönetimini Roger Pressman'ın "Software Engineering" kitabının özetinden anlattı; kitabın daha eski baskılarında risk kategorileriyle ilgili çok daha ayrıntılı bilgi olduğunu, ama o kadar ayrıntıya girmeyeceğini söyledi. Slaytlardaki (ekrandan, 01:35:00) ana başlıklar şunlardır:

- Riskle uğraşma taktikleri:
  - Sonradan (reaktif): risk gerçekleşince çözmek.
  - Önceden (proaktif): riskleri daha gerçekleşmeden önlemeye çalışmak. Derste proaktif yaklaşım işlenir.
- Risk tanımı: tam bir uzlaşı yoktur; uzlaşılan özellikler:
  - Olasılık: belirli bir risk ortaya çıkabilir ya da çıkmayabilir; %100 olasılıkla ortaya çıkacak bir risk yoktur.
  - Kayıp: risk ortaya çıktığında istenmeyen sonuçlar ve kayıplar doğurur.
  - Gelecek.
- Genel risk çeşitleri: proje riskleri, teknik riskler, iş (işletme) riskleri.

Hoca üç anahtar kelimeyi şöyle açıkladı: şu anda bir tehlike yoktur, ama gelecekte bir tehlike olasılığı vardır; ve bu risk gerçekleşirse bir kayıp getirecektir. Bu yüzden risk yönetimi istatistikle yakından ilişkilidir: riskin gerçekleşme olasılığı ve gerçekleşirse getireceği kaybın büyüklüğü (tahribatı, şiddeti) tahmin edilmeye çalışılır. Proaktif yaklaşımda risk gerçekleşmeden nasıl önleneceği ya da gerçekleşirse nasıl başa çıkılacağı (B planları) önceden hazırlanır.

### 15.2 Risk türleri

Slayttaki sınıflandırma (ekrandan, 01:40:00):

- **Proje riskleri:** Proje planını tehdit eder; gerçekleşirse takvim ileri tarihlere sarkar ve maliyet artar. Örnekler: bütçe, zaman ve personel riskleri.
- **Teknik riskler:** Üretilen yazılımın kalitesini ve zamanında bitirilmesini etkiler; gerçekleşirse yazılımı gerçeklemek zorlaşır ya da imkansızlaşır. Çözümleme, tasarım, gerçekleme ve bakım aşamalarıyla ilgilidir. "Son teknoloji" ürünler yüksek teknik risk taşır. Sorulacak sorular: hatalar (bug) var mı, belgeleme tam mı, bu teknoloji tam anlaşılabildi mi, yarın da bu teknoloji hayatta olacak mı?
- **İşletme riskleri:** Pazar riskleri (ürüne talep olur mu? slayttaki örnek: tıraş bıçağı ve tıraş makinesi), satış riskleri (pazarlama ekibi ürünü nasıl satacağını biliyor mu?), MIS/MBA konuları.

Hoca her türü örneklerle açtı:

- Proje riski örnekleri: yazılım ya da veri tabanı yönetim sistemi satın almak için gereken paranın zamanında çıkarılamaması (bütçe riski), zamanla ilgili bir problem (zaman riski). Personel riskinde ilk akla gelen kilit kişilerden birinin işten ayrılmasıdır. Bunun dışında kişinin sahip olduğunu söylediği yeteneklere sahip olmaması ya da kişilik kaynaklı riskler, örneğin ortak çalışmaya uygun olmama, de vardır; hoca bunun bilgisayar alanındaki çalışanlarda daha sık görüldüğünün söylendiğini aktardı.
- Teknik risk örnekleri: yazılımın herhangi bir aşamasında kullanılacak teknik altyapının kullanılamaması (bu durumda yazılımı gerçekleştirmek imkansız bile olabilir), donanımın zamanında kurulamaması, yazılımın zamanında güncellenememesi. Analiz, tasarım, gerçekleme ve bakım sırasında uygun olmayan yöntemlerin kullanılması da teknik risktir; yani süreç modeliyle ya da süreçteki bir adımla ilgili sıkıntı. Son teknoloji ya da yeni bir ürün kullanmak da risklidir: ekip ilk defa yeni bir veri tabanı kullanıyorsa ve deneyimi yoksa, ya da daha önce deneyimi olmadığı bir CASE aracı kullanıyorsa bu yarardan çok zarar getirebilir. Hatalar ve belgeleme sorunları da teknik risktir.
- İşletme riski örnekleri: bir yazılım evi ilk defa bu kadar büyük bir proje geliştiriyorsa bu bir büyüklük riskidir. Şirketin batması ya da ayakta kalması bu projeye bağlıysa, yani proje şirketin kritik bir döneminde yapılıyorsa, bu da bir risktir. Pazar riski, ürüne talep olup olmayacağıdır. Satış riski, genel amaçlı hazırlanan bir yazılım için alıcı firmaların olup olmadığı, pazar talebi araştırmasının yapılıp yapılmadığıdır; yazılım ürünü sonuçta çoğaltılıp satılacak bir ürün olduğu için bu bir işletme riskidir. Ürün bir şirket içinde geliştiriliyorsa işletme riski daha çok o departmanın işletmedeki yeriyle ilgilidir.

### 15.3 Risk tablosu

Risk yönetiminde önce bir risk tablosu oluşturulur. Bunun için şirketteki bütün işler, çalışanlar ve proje düşünülerek bu projede risk olabilecek maddeler sıralanır ve her birinin hangi kategoriye girdiği yazılır. Ekipten de yardım istenir: "Bu proje süresince sizin için neler problem çıkarabilir?" Kabul edilen ve edilmeyen riskler ayrıştırılır; riskler türlerine (proje, teknik, işletme) ve alt türlerine ayrılır.

Her riskin olasılığı (düşük, orta, yüksek ya da %30, %50, %60 gibi yüzdelerle) ve etkisi belirlenir. Özet risk tablosunda risk numarası, riskin adı, türü, etkisi ve olasılığı yer alır; örneğin "proje tahminleri" bir proje riski, CASE araçlarının kullanılması ise orta seviyede bir teknik risk olabilir. Etkisi küçük ve olasılığı düşük olan riskler elenir; bunların projenin her aşamasında takip edilmesine gerek yoktur. Geri kalan riskler izlenir. <!-- BELİRSİZ: özet risk tablosu slaytının (slayt 10) karesi yok; hocanın izlenecek diye saydığı risk numaraları altyazıda "2, 3, 5, 1, 9" olarak geçiyor, tablodaki değerler doğrulanamadı. -->

### 15.4 Risk bilgi sayfası

İzlenecek her risk için ayrı bir risk bilgi sayfası tutulur. Derste gösterilen örnek (ekrandan, 01:45:00):

| Alan | İçerik |
|---|---|
| Risk | #09: Pazarlama |
| Olasılık / Etki / Türü | Yüksek / Büyük / Ticari |
| Açıklama | Firmamız sadece yazılım geliştiricilerden oluşan çekirdek kadroyla çalışmaktadır. Ortaya çıkaracağımız yazılımın piyasada çok fazla alternatifi vardır. |
| İşaretleri | 1. Müşteri adayları ile görüşmede dinleyicilerin ilgisizliği ve "Biz zaten X yazılımını kullanıyoruz. Neden sizi seçelim?" türü yorumlar. 2. Bakım aşamasının ilk altı aylık süresince ürünümüzün kendisini amorti etme oranının %50'nin altında kalması. |
| Önlemler | 1. Bir programcımıza MBA yaptırmak. 2. Gereksinim mühendisliği aşamasında konu uzmanlığı odaklı danışmanlık hizmeti almak. 3. Bir ya da iki firma ile pilot uygulama yapmak ve bu firmalara ürünü özel indirimle satmak. |

Hoca örneği şöyle açtı: yazılım firması yeni kurulmuştur, çekirdek ekip hep yazılımcıdır, aralarında bir işletmeci yoktur; bu yüzden iyi bir pazar araştırması yapılmamıştır. Ürünün piyasada birçok alternatifi vardır ve ilgili şirketlerle nasıl konuşulacağı bilinmemektedir. Teknik kişilerin alçakgönüllülüğüyle ürün öne çıkarılamaz, "niye sizi seçelim" sorusuna iyi cevap verilemez. Önlem olarak teknik ekipten birine MBA yaptırılarak işletmecilik tarafı güçlendirilebilir, bir pazarlama uzmanı alınabilir, pazarlama konusunda danışmanlık alınabilir ya da birkaç firmayla önce düşük fiyatla anlaşılarak ürünün kullanımı yaygınlaştırılabilir.

### 15.5 Risklerin izlenmesi

Risk tablosu ilk başta olasılık ve etkiyle kurulur; izlenecek riskler için açıklama, işaretler ve önlemler eklenir. Her risk ayrı sayfada tutulur, ama ayrıca bir izleme tablosu oluşturulur: izlenen her riskin etkisi, olasılığı, değerlendirme tarihi ve onu azaltmak için alınması gereken önlemler bu tabloda yer alır.

> **Hocanın vurgusu:** Hiçbir önlem bedava değildir. Tabloda her önlemin yanına maliyeti yazılmalıdır.

Her yeni kilometre taşında, örneğin gereksinim analizi bittiğinde, risk yeniden değerlendirilir: şu anda olasılığı nedir, şu andaki önlem nedir ve bu önlemin maliyeti ne kadardır? Böylece riskler izlenebilir. Etkisi büyük ve olasılığı yüksek olan riskler ise daha sık aralıklarla takip altında tutulmalıdır.

Hoca risk kategorilerini çok daha ayrıntılandıran başka slaytları olduğunu ama bu derste proje, teknik ve işletme riskleri ile örnekleriyle yetindiğini belirtti. Yazılım ölçümüne giriş bir sonraki derse kaldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:05:32): Aktivite bağımlılığı kavramı nedir? Bağımlılık türleri nelerdir?

> **Cevap (derste verildi):** Aktiviteler arası bağımlılık, bir aktivitenin başlaması ya da bitmesinin başka bir aktivitenin başlamasına ya da bitmesine bağlı olmasıdır. Türleri Finish-Start (en yaygın; öncül bitmeden ardıl başlamaz), Start-Start (öncül başlamadan ardıl başlamaz; örneğin bilgi toplama başlamadan modelleme başlamaz) ve Finish-Finish'tir (öncül bitmeden ardıl bitmiş sayılmaz; örneğin geliştirme bitmeden belgeleme bitmez). Bağımlılıklara gecikme (lag) ya da öncelenme (lead) süresi eklenebilir.

**Soru 2** (derste sözlü, 00:05:54): Planlamada hangi işlemler gerçekleştirilir ve iş kırılım yapısı (WBS) nedir?

> **Cevap (derste verildi):** Planlama; risklerin ve kabul-kısıtların belirlenmesi, kalite yönetiminin planlanması, aktivite listesi, bağımlılıklar, efor ve maliyet tahmini, takvim ve kilometre taşları, kaynak atama ve seviyelendirme, bütçe, belgeler, devreye alma, tamamlanma ve iletişim planları ile proje planının yazılmasından oluşur. WBS, işlerin hangi işlerin alt adımları olduğunu seviyeli olarak gösteren iş listesidir; ağaç yapısıyla ya da seviyeli numaralandırmayla (örneğin 10.20.15 üçüncü seviye) gösterilir.

**Soru 3** (derste sözlü, 00:42:53): Yeniden kullanılabilir özelliklerden günümüzde yazılımda en çok kullanılan nedir?

> **Cevap (derste verildi):** Tasarım kalıplarıdır (design patterns). Yeniden kullanılabilir kütüphaneler de projeyi hızlandırmak için önemlidir.

**Soru 4** (ekrandan, 00:30:00): "Evaluate Written Proposals" aktivitesinde proje yöneticisi %20, donanım analisti %80 çalışıyor. Aktivite tanım sayfasında hangi alanlar bulunmalıdır?

> **Cevap (derste verildi):** Proje, aktivite (WBS numarası ve adı), tanım, girdiler (önceden tamamlanmış olması gereken işler ve belgeler), efor (yapılacak işler), kaynaklar (çalışma yüzdeleriyle) ve çıktılar.

## Dersin Toparlaması

Bu derste proje planlamanın on beş aktivitesi kitap üzerinden baştan sona özetlendi. Aktiviteler süreç modeline göre listelenir, aralarındaki Finish-Start, Start-Start ve Finish-Finish bağımlılıklar gecikme ve öncelenme süreleriyle birlikte kurulur, WBS seviyeli ve boşluklu numaralarla oluşturulur ve kilometre taşları süreç modeline göre konur. Kalite planının özü gözden geçirme kuralları, takvimi ve ekibidir. Efor tahmininde bütünleştirme şaşkınlığı, yeni teknoloji, yeni metodoloji ve dış bağımlılıklar tehlikeli alanlardır; yazılım projelerinde iş gücü tahmini maliyet tahmininin kendisidir. Kaynaklar önce rol ve yüzde düzeyinde, sonra kişi düzeyinde atanır ve düzleştirilir. Bütçe, takvimin müşteri gereksinimine uydurulması, belgeler, eğitim, tamamlanma kriteri formu ve paydaş temelli iletişim planı da proje planının parçalarıdır; kitaptaki örnek proje planı bu bölümlerin hepsini bir arada gösterir.

Dersin son kısmında Pressman'ın tanımıyla risk (olasılık, kayıp, gelecek), proaktif risk yönetimi, proje-teknik-işletme risk türleri, risk tablosu ve risk bilgi sayfası işlendi; her önlemin maliyeti olduğu ve risklerin her kilometre taşında yeniden değerlendirilmesi gerektiği vurgulandı. Sonraki derste yazılım ölçümüne ve proje organizasyonu ile ekip yapılarına geçilecek; bu yapıların çevik modellerde nasıl değiştiği de ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
