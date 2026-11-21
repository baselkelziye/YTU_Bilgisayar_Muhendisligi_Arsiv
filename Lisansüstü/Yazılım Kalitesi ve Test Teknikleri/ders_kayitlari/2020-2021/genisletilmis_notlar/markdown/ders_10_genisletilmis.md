# Ders 10 Genişletilmiş Notu: Çevik Süreçlerde Test, Release Management ve Mobil Uygulama Testi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çevik Yaklaşımlar ve XP Tekrarı
- 2. Çevik Modellerde Test ve Kalite
- 3. Test Güdümlü Yazılım Geliştirme (TDD)
- 4. Yazılım Konfigürasyonu ve Konfigürasyon Yönetimi Tekrarı
- 5. Release Management (Yayınlama Yönetimi)
- 6. Release Management Süreci ve Release Manager
- 7. Release Management'ın Faydaları ve DevOps
- 8. Örnek Makale Sunumu: Mobil Uygulamalarda Test
- 9. SRS Belgesi Örneği Üzerinden Değerlendirme
- Örnek Sorular
- Dersin Toparlaması

## 1. Çevik Yaklaşımlar ve XP Tekrarı

Bu ders, dönemin konu anlatımı yapılan son dersidir. Önce bir önceki haftada işlenen çevik (agile) yaklaşımlar ve konfigürasyon yönetimi tekrar edilir, ardından yeni konu olarak Release Management işlenir. Dersin sonunda bir makale sunumu örneği ve bir SRS belgesi örneği incelenir. CMMI ve yazılım süreç iyileştirme konuları önceki derste tekrar edildiği için bu derste yeniden ele alınmaz.

Çevik yöntemler 2000'li yıllardan itibaren kullanıma alınmış, son yıllarda sektörde geleneksel modellere alternatif olarak yaygınlaşmıştır. Derste ele alınan çevik süreç modelleri XP, Scrum ve Kanban'dır. Bütün çevik modellerde ortak olan çekirdek özellikler vardır; bunun yanında her modelin kendine özgü öne çıkan özellikleri de bulunur. XP ilk örnek olduğu için çevik anlayış onun üzerinden anlatılır.

### 1.1 XP'nin dört temel değeri

XP (eXtreme Programming) dört temel değere dayanır ve hoca bunların aslında bütün çevik yaklaşımların temeli olduğunu söyler (ekrandan, 00:10:00):

- **Basitlik:** Prototiplerle çok sayıda deneme yaparak tasarımı en iyileştirip ondan sonra başlamak yerine, ilk basit tasarımdan başlayıp ilerlemek. Bu, bütün çevik modellerin birinci çekirdek hedefidir.
- **İletişim:** Ekip içi iletişim önemlidir. Bütün ekip birbirine karşı sorumludur ve kısa toplantılarla birbirinden haberdar olur. Scrum bu özelliği kısa toplantılar ve kısa görevlerle sağlar.
- **Geri besleme:** Sıkı iletişim nedeniyle geri besleme de sıktır. XP'de bu artımlı geliştirmeyle, Scrum'da kısa görevlerin sık sık değerlendirilip yenisine geçilmesiyle sağlanır.
- **Cesaret:** Yenilikleri denemek ve sonuçlarını görerek geliştirme yoluna gitmek.

Bu dört değerin amacı ürünü daha hızlı elde etmektir.

### 1.2 XP uygulamaları

Slayta göre XP, bu dört değer çevresinde oluşturulan şu özelliklere sahiptir (ekrandan, 00:10:00): planlama oyunu, küçük ve kısa aralıklı yayımlar, sistem metaforu, basit tasarım, test, devamlı yeniden tasarım (refactoring), eşli programlama (pair programming), ortak kod mülkiyeti, sürekli tümleştirme (continuous integration), devam ettirilebilir hız (haftada yaklaşık 40 saat), ekip üyesi müşteri ve kodlama standartları.

Hoca bunların bazılarını açar:

- **Küçük ve kısa aralıklı yayımlar (release):** XP'nin artımlı (incremental) yapısından kaynaklanır. Basit tasarımla bir çekirdek yazılım oluşturulur, sonra bunun üzerine eklemeler yapılır. Biten her küçük yayın hızlıca test edilir ve basit tasarım refactoring ile sürekli yeniden tasarlanır.
- **Eşli programlama:** XP'ye özgü bir özelliktir; diğer çevik yaklaşımlarda farklı özellikler öne çıkar.
- **Ortak kod mülkiyeti:** İletişim ve birbirinin işinden haberdar olmanın sonucudur. Herkesin yapılan her iş hakkında temel bilgisi vardır; iş ortak olduğu için kod mülkiyeti de ortaktır.
- **Sürekli tümleştirme:** Kod sürekli tümleştirilir ve tümleştirilen kısım test edilir.
- **Devam ettirilebilir hız:** Herkese taşıyabileceği kadar yük verilir; haftada yaklaşık 40 saat çalışılır.
- **Ekip üyesi müşteri:** Çevik yaklaşımın en önemli özelliklerinden biridir. Çevik yaklaşımla oluşturulmuş bütün süreç modellerinde müşteri ekibin bir üyesi olarak görülür.

## 2. Çevik Modellerde Test ve Kalite

Hoca, önceki derste de sorduğu soruya döner: test ve kalite açısından çevik modeller geleneksel modellerden nasıl ayrılır? Slayttaki cevap dört maddedir (ekrandan, 00:15:00):

- Dinamik kalite değerlendirme, statik değerlendirmeden daha fazla uygulanır. Yani test işi daha çok yapılır.
- Kaliteyle ilgili işlemler sürecin daha erken adımlarında başlar.
- Kaliteyle ilgili etkinlikler daha kısa aralıklarla, daha sık yapılır.
- Çevik yaklaşımlarda doğruluk ve süreklilik kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle sağlanır.

Özetle çevik modellerde daha çok test yapılır, kalite etkinlikleri daha sık tekrarlanır ve kaliteye daha erken adımlarda dikkat edilmeye başlanır. Bunun pratikteki karşılığı şudur: gereksinim analizi sırasında bir use case belirlendiğinde o use case'in test senaryosu da oluşturulur. Bir kullanıcı hikayesi yazıldığında "bunun testini nasıl gerçekleştireceğiz?" sorusu da hemen sorulur.

## 3. Test Güdümlü Yazılım Geliştirme (TDD)

### 3.1 Tanım

Çevik süreç modellerinde kullanılan test yaklaşımına Test Driven Development (TDD, test güdümlü yazılım geliştirme) denir. TDD, küçük ve hızlı iterasyonlarla, yazılım geliştirme araçlarıyla hazırlanmış testler yazılarak ilerleyen bir yazılım geliştirme metodolojisidir. Test güdümlü geliştirme çevik yaklaşımlar için daha uygundur ve çevik projeler zaten bu şekilde yürür.

### 3.2 Uygulama adımları

TDD yaklaşımını kullanan yazılım mühendisleri şu adımlarla ilerler:

1. Birim kodlarını geliştirmeden önce test case'leri (test senaryolarını) yazmak.
2. Kod henüz yazılmadığı için testin başarısız olduğunu görmek.
3. Kod yazarak test case'lerin geçmesini sağlamak.
4. Testleri tekrar çalıştırıp geçtiğini görmek.
5. Kodu yeniden düzenlemek.

Bu adımlar kısa döngüler ve sık tekrarlar oluşturur. Scrum ve Kanban'da da TDD aynı şekilde kullanılır.

> **Ek bilgi (derste anlatılmadı):** Bu döngü literatürde çoğunlukla "kırmızı - yeşil - yeniden düzenle" (red - green - refactor) diye özetlenir: başarısız test, testi geçiren en basit kod, ardından kodun iyileştirilmesi.

### 3.3 TDD hakkındaki çalışmalar

Hoca, TDD üzerine yapılan ilk çalışmalardan birini aktarır (ekrandan, 00:20:00):

- H. Erdoğmuş, 24 lisans öğrencisini kullanarak önce-test (test-first) ve sonra-test (test-last) yöntemleri hakkında bir araştırma yapmıştır.
- Araştırmanın sonucunda TDD'nin programcı üretkenliğini artırdığı, ancak daha iyi kalite sağlamadığı görülmüştür.
- Önce-test yaklaşımının başarısı, programcıyı kodları ve test sonuçlarını yedeklemeye teşvik etmesiyle ilişkilendirilmiştir.

Hoca, sektörde çevik süreçlerin ve TDD'nin tercih edilmesinin üretkenlikteki bu artışla uyumlu olduğunu, ancak kalite açısından diğer yöntemlerden çok farklı bir sonuç alınmadığını vurgular. Bu konuda daha sonra başka çalışmalar da yapılmıştır.

## 4. Yazılım Konfigürasyonu ve Konfigürasyon Yönetimi Tekrarı

### 4.1 Yazılım konfigürasyonu nedir?

Test planlama konusunda yazılım konfigürasyon yönetimi, teslim sırasında başlayıp teslimden sonra da süren bir kalite etkinliği olarak tanıtılmıştı. Hoca bu konuyu, sınavda sıkça yapılan bir hatayı düzeltmek için yeniden ele alır: "Yazılım konfigürasyon yönetimi nedir, yazılım konfigürasyon elemanları nelerdir?" sorusunda öğrencilerin yaklaşık yarısı YKY etkinliklerini konfigürasyon elemanı olarak yazmıştır.

Slayttaki tanım şöyledir (ekrandan, 00:25:00):

- Yazılım mühendisliğinin ürünleri programlar, belgeler ve veri yapılarıdır. Bu ürünlere ait bütün maddelere topluca **yazılım konfigürasyonu** denir.
- **Yazılım konfigürasyon maddesi** (Software Configuration Item), YKY işlemlerinin uygulandığı yazılım modülüdür.

Hoca bunu donanım benzetmesiyle açıklar: donanımın elemanları ekran, bellek gibi donanım birimleriyse, yazılımın elemanları da programlar, belgeler ve veri yapılarıdır. Slaytta yazmasa da test verileri ve veritabanı elemanları da yazılım konfigürasyonunun elemanlarıdır. Bu elemanlar bir araya gelerek yazılımın düzenini, yani konfigürasyonunu oluşturur.

### 4.2 YKY etkinlikleri

Yazılım konfigürasyon yönetimi, bu elemanların her birinin geliştirme sürecinin başından itibaren takip edilmesini ve güncel tanımlarının her an açıklanabilecek biçimde tutulmasını sağlar. Slayta göre YKY etkinlikleri dört aşamada gerçekleştirilir (ekrandan, 00:25:00):

- Konfigürasyon tanımı (Configuration Identification)
- Konfigürasyon değişiklik kontrolü (Configuration Control)
- Konfigürasyon denetimi (Configuration Auditing)
- Konfigürasyon raporlama (Configuration Status Accounting)

YKY'nin amacı, yazılım konfigürasyonunun geliştirme sürecinin başından kullanım sürecinin sonuna kadar hangi değişikliklere uğradığını; elemanların hangi durumda, hangi tarihte, hangi sürümde ve hangi içerikte olduğunu belirtmektir.

> **Hocanın vurgusu:** Konfigürasyon elemanları (programlar, belgeler, veri yapıları) ile YKY etkinlikleri (tanım, değişiklik kontrolü, denetim, raporlama) farklı şeylerdir; biri yönetilen nesneler, diğeri onlara uygulanan işlemlerdir.

### 4.3 YKY standartları

YKY sürecinde herhangi bir işlemin ya da ürünün değerlendirilmesi için bir standart gerekir. Örneğin YKY planı standardı, YKY planının ne içermesi gerektiğini tanımlar. Slayttaki örnekler (ekrandan, 00:30:00):

- IEEE-STD-828 IEEE Standard for SCM Plans
- IEEE-STD-1042 IEEE Guide for SCM Plans
- ISO 9004 Quality Management & Quality System Elements Part 6

Hoca konfigürasyon yönetimini bu derste yeniden hatırlatmasının nedenini de açıklar: yeni konu olan Release Management, konfigürasyon yönetimiyle doğrudan ilişkilidir. Yeni bir sürümdeki değişikliklerin tanımı konfigürasyon yönetiminde tutulur; Release Management ise bu sürümün kullanıcılara uyumlu biçimde yayınlanması için yapılanlarla ilgilenir.

## 5. Release Management (Yayınlama Yönetimi)

### 5.1 Tanım ve amaç

Release Management son yıllarda önemi çok artmış ve sektörde önemli bir konu hâline gelmiştir. Türkçede yayınlama yönetimi diye karşılanabilir. Yeni bir yazılım geliştirildiğinde ya da mevcut bir yazılımın yeni bir sürümü oluşturulduğunda bunun uygulamaya konması, yani uygulamanın yerleştirildiği dağıtım (deployment) aşaması bu sürecin konusudur. Bu aşama, yazılımın kullanılacağı işletmedeki bütün birim ve servisleri ilgilendirir; proje artık son kullanıcıların kullanımına sunulmaktadır. Süreçten sorumlu olan bir ekip vardır; bu bir kalite birimi ya da yazılım uygulamaları yönetimi olabilir.

Slayttaki tanım şöyledir (ekrandan, 00:45:00): Release Management, bir kurumun sistem ve servislerinin değişen iş ihtiyaçlarını destekleyecek biçimde değişebilmesini sağlamakla ilgilidir. Projenin, son kullanıcıların kullanabileceği üretim (canlı) ortamına taşınmasını koordine etme sürecidir. Temel amacı canlı ortamın bütünlüğünün korunmasını ve doğru bileşenlerin yayınlanmasını sağlamaktır.

Aynı slayta göre bazı kurumlar Release Management'ı yalnız IT ürün ve özelliklerinin teknik dağıtımı olarak görür; bazıları ise daha geniş bir bakışla yayına bağlı **uyum (adoption)** ve iş süreci değişikliklerini de kapsama alır. Hoca bu ikinci boyutu vurgular: bir bilişim ürününün teknik olarak kullanıma alınmasının ötesinde, kurumun ilgili organizasyon parçasının da etkileneceğini bilmek gerekir. Özellikle iş süreçlerinde değişiklik olacaksa ilgili iş biriminin yeni yazılıma uyum sağlaması gözetilmelidir.

Release Management iki taraflı bir dikkat ister: bir yandan yeni değişiklikler konfigürasyon yapısına doğru yerleştirilmeli, öte yandan yazılımın kullanılacağı iş biriminin uyumu sağlanmalıdır. Yazılım sistemlerinin hayati önem taşıdığı ve bütün iş süreçlerini etkilediği günümüzde bu süreç çok daha fazla önem kazanmıştır.

### 5.2 ITIL'de Release Management

Sektörde bu geçiş süreci rastgele yapılmaz. IT Infrastructure Library (ITIL) çerçevesi Release Management'ın nasıl yapılacağını tanımlar. Slayta göre (ekrandan, 00:50:00):

- Release and Deployment Management, ITIL çerçevesinin Service Transition (servis geçişi) bölümündeki ana süreçlerden biridir ve kısaca "release management" diye anılır.
- ITIL bu süreci, IT servislerinin, güncellemelerin ve yeni sürümlerin üretim ortamına yayılmasını planlama ve zamanlamayı yönetme süreci olarak tanımlar.
- Bu bağlamda **release**, bir servisin ya da bileşenin daha yeni bir sürümünün geliştirilmesi; **deployment** ise onun canlı üretim ortamına tümleştirilmesidir.
- Release Management, proje etkinlikleri ve proje ekiplerinin ürettikleri ile bunları kullanacak süregelen operasyonlar ve kullanıcılar arasındaki boşluğu kapatan bir köprüdür.
- Kurumlarda aynı anda birçok proje yürür. Release Management değişiklikleri bir araya getirmek, doğru çalıştıklarını test etmek ve iş operasyonlarının dayandığı canlı ortama güvenli biçimde almak için yapılandırılmış bir yaklaşım sunar.
- Ayrıca yeni özellikleri ya da bileşenleri geliştiren ekiplerden, onlara destek verecek operasyon ekibine bilgi ve kaynak aktarılmasını sağlar.

Hoca bu noktayı örnekler: tek bir departmanda bile aynı anda çok sayıda proje geliştirilebilir. Bunların hangisinin önce, hangisinin sonra devreye alınacağı ve birbirlerini nasıl etkileyecekleri planlanmalıdır. Bu kararları uzman yazılım mimarları ve yazılım mühendisleri verir, ama kurumun iş süreçlerini bilen kişilerle birlikte çalışmaları gerekir.

## 6. Release Management Süreci ve Release Manager

### 6.1 Altı alt süreç

Her proje ekibinin bir release'i planlarken, oluştururken, test ederken ve dağıtırken aynı süreci, politikaları ve rehberleri (guideline) izlemesi önemlidir. Böylece her devreye alınan uygulama için yeni kurallar uydurulmaz. ITIL, Release Management'ı etkin, verimli ve güvenli yapılabilmesi için altı alt sürece böler (ekrandan, 00:55:00):

1. **Release management support (destek):** Release'lerin dağıtımı için rehberlik ve destek sağlar; sürecin diğer kısımlarında yer alan rolleri de tanımlar.
2. **Release planning (planlama):** Release'lerin kapsamını ve içeriğini politikalara göre belirler, onaylanmış değişiklikleri release paketlerine atar ve build, test ve deployment için bir takvim tanımlar.
3. **Release build (oluşturma):** Gereken bütün release bileşenlerinin fiilen geliştirilmesiyle ilgilenir; tedarikçilerden gelecek bileşenler için iş ve satın alma emirlerini çıkarır ve bütün bileşenlerin doğrulama ve teste hazır olmasını sağlar.
4. **Release deployment (dağıtım):** Bileşenlerin canlı üretim ortamına dağıtımını ve belgelerin, eğitimin son kullanıcılara ve işletim personeline aktarılmasını yönetir.
5. **Erken yaşam desteği (early life support):** Yeni release'e geçildikten sonraki ilk dönemde uygulama yakın takibe alınır; hata çıkıp çıkmadığı ve işleyişin nasıl yürüdüğü izlenir.
6. **Release kapanışı (release closure):** Bütün güncellemelerin, raporların, çıktıların ve proje ekiplerine geri bildirimin tamamlandığı doğrulanır; belgeler ve release etkinlikleri resmî olarak kapatılır.
<!-- BELİRSİZ: Son iki alt süreç (early life support, release closure) slaytın küçük önizlemesinde ve altyazıda geçiyor; ayrıntılı slaytın karesi yok, tanımlar hocanın anlatımından alındı. -->

Hoca planlama aşamasını biraz açar: geçiş süreci için bir proje iş takvimi oluşturulmalı, hangi işten kimin sorumlu olduğu belirlenmeli ve iş bu takvim çerçevesinde yürütülmelidir. Build aşamasında bütün bileşenlerin geçerlik ve test çalışmaları için hazır olup olmadığı kontrol edilir. Deployment aşamasında son kullanıcılara ve işletenlere eğitim verilir ve yazılımla ilgili belgelere uyum sağlamaları desteklenerek uygulama yaşama geçirilir. Hoca, Project Management Institute'un da Release Management için tanımlar yaptığını ve yeni bir release'e geçişte izlenecek yolu gösteren bir rehber oluşturulması gerektiğini ekler.

### 6.2 Kavramın tarihî arka planı

Hoca, kuralları konmuş ve tanımlı bir süreç olarak Release Management'ın son yıllarda öne çıktığını, ama özünün çok eskiden beri öğretildiğini anlatır. Otuz yıl kadar önce bile, küçük boyutlu yazılımlar için şöyle denirdi: ne kadar iyi bir yazılım yapmış olursanız olun, ilk uygulamaya geçiş sırasında takibini bırakmamalısınız; kullanıcıya uğrayıp "nasıl gidiyor?" diye sormalısınız. Bugün Release Management ve konfigürasyon yönetimi kavramları daha tanımlı hâle gelmiş, yaygınlaşmış ve birçok kurumun bu kurallara göre çalışması gerekir olmuştur.

### 6.3 Release Manager

Devreye alma aşamasında birçok kişinin görevi vardır, ama en önemli rol release manager'ındır. Slayta göre (ekrandan, 01:05:00):

- Release manager koordinasyon ve yönetişim/gözetim (governance/oversight) rollerini birlikte üstlenir; release'in etkin ve güvenli biçimde tamamlanmasından sorumludur.
- Genellikle uzmanlaşmış beceri ve deneyime sahip IT profesyonelleridir; release etkinliklerini koordine etmek için standartları, süreçleri ve araçları kullanırlar.
- IT bağlamında iş birimi liderleri, IT proje ekipleri ve operasyon personeliyle çalışırlar. Ürün yönetimi bağlamında iş geliştirme, pazarlama, Ar-Ge ve diğer ekiplerle şirket çapında koordinasyon sağlarlar.
- Büyük release'lerde birden çok kişi bir release ekibi olarak çalışabilir. Bu durumda release manager hem ekibi hem release'in kendisini koordine eden genel yönetim ve liderlik işlevini üstlenir.
- Release'in yönetişiminden ve kalite gözetiminden sorumludur; release'in ne düzeyde risk ve karmaşıklık taşıdığını belirler ve şirketin süregelen operasyonlarını tehlikeye atmadan hedeflere ulaşılması için gereken özenin gösterilmesini sağlar.

Hoca şunu vurgular: büyük bir uygulama tek bir birimi değil, birçok birimi birlikte etkileyebilir. Bu durumda release manager hem kurumun kuralları içinde iş süreçlerinin yürümesinden hem de canlı yaşamın en az etkilenmesinden sorumlu olacak biçimde ekibini kurmalı, büyük geçişler için risk yönetimi de yapmalıdır.

Hoca, Scrum ile Release Management'ın iç içe geçtiğini ve Release Management'ın konfigürasyon yönetimiyle ilişkisini gösteren klasik şekiller bulunduğunu, ancak bu derste yalnız kavramı yerleştirmek istediği için şekillere girmediğini belirtir.

## 7. Release Management'ın Faydaları ve DevOps

### 7.1 Faydalar

Slayttaki faydalar şunlardır (ekrandan, 01:10:00):

- Değişikliklerin ve yeni özelliklerin kullanıcılara daha hızlı ulaştırılması.
- Yetkisiz release'lerin kullanılan özellikleri bozma riskinin azalması.
- İş üzerindeki etkiyi en aza indiren zamanlarda, öngörülebilir bir dağıtım takvimi.
- Yeni ya da değişen servislerin üzerinde anlaşılmış servis gereksinimlerini karşılamasının güvenceye alınması.
- Kullanıcılara ve destek personeline uygun bilgi aktarımının sağlanması.

Hoca bunları şöyle özetler: Release Management'ın baş faydası değişiklikleri riski azaltarak, bir iş listesine bağlı biçimde ve kullanıcıların uyumunu sağlayarak devreye almaktır. Bu yüzden yeni yayınlanan her uygulamada, önemli değişikliklerde ve sürüm değişikliklerinde kullanılmalıdır.

### 7.2 Release Management ve DevOps

DevOps, development (geliştirme) ve operations (operasyon) kelimelerinin birleşimidir. Çevik süreçlerle yazılım geliştirme yaygınlaştıkça ortaya çıkmış bir kavramdır; geliştirme ekibi ile operasyon ekibinin birlikte çalışmasını öngörür. Slayta göre (ekrandan, 01:15:00):

- Release Management, disiplinli bir DevOps stratejisinin önemli bir parçasıdır.
- Birçok IT departmanı DevOps'u benimsemenin henüz başındadır ama yine de etkin bir release yönetimine ihtiyaç duyar. Release Management'a yaklaşım, DevOps benimseme yolunda ne kadar ilerlendiğine göre değişir.
- Hiç DevOps yoksa release yönetimi etkinlikleri büyük olasılıkla IT teslim ekiplerinden tamamen ayrı bir ekip tarafından yapılır.
- DevOps zihniyeti benimsenme sürecindeyse release yönetimi IT teslim ekipleriyle release yönetim ekibinin ortak çalışmasıdır.
- DevOps stratejileri tam benimsendiğinde release yönetimini büyük ölçüde teslim ekiplerinin kendisi yapar.

Hoca, çevik süreçler kullanıldığında Release Management yapısının daha dinamik ve daha kolay uygulanabilir hâle geldiğini, DevOps stratejisiyle Release Management birlikte kullanıldığında daha etkin çözümler elde edildiğini söyler.

## 8. Örnek Makale Sunumu: Mobil Uygulamalarda Test

Hoca, öğrencilerin hazırlayacağı makale sunumlarına örnek olması için önceki yıldan ortalama düzeyde bir sunumu gösterir. Konu, derste işlenmeyen bir alandır: mobil uygulamaların nasıl test edildiği. Sunum IEEE Software ve konferans yayınlarından derlenmiştir. Sunumun bölümleri: mobil uygulama test kapsamı ve gereklilikleri, mobil uygulama test stratejileri ve mobil uygulamaların test edilmesinin zorlukları (ekrandan, 01:30:00).

### 8.1 Mobil uygulamaların özellikleri ve test kapsamı

Mobil cihazlar çok yaygınlaştıkça bu cihazlarda çalışan yazılımların güvenilirliği ve test süreci farklılaşmıştır. Mobil uygulamaların testinde kullanılabilirlik, mobilite ve güvenlik daha çok ağır basar; test daha zaman alıcı ve maliyetlidir. Bu yüzden ilk testler genellikle emülatörlerle yapılır.

Mobil uygulamalar akıllı telefon ve tabletlerde çalışan, grafik kullanıcı arayüzü ağırlıklı yazılımlardır. Üç türü vardır: mobil web uygulamaları, doğal (native) mobil uygulamalar ve hibrit mobil uygulamalar. Çoğu sunucu tarafı (server-side) teknolojiyle oluşturulur ve internet bağlantısı gerektirir. Başarılı bir mobil uygulamanın ayırt edici nitelikleri olarak bağlantı, kaliteli tasarım, desteklenen cihazlar, programlama dili, içerik, güvenlik, kişiselleştirilebilirlik ve erişilebilirlik sayılır.

İnternet bağlantısının hızı ve güvenilirliği değişebildiği için işlevsel testler farklı ağlarda ve bağlantı senaryolarında tekrarlanmalıdır. Grafik arayüzün ve kullanım kolaylığının sınanması için de farklı cihazlarda test gerekir. Kullanılabilirlik, birlikte çalışabilirlik, mobil bağlantı, güvenlik ve mahremiyet test açısından büyük önem taşır. Yüksek dinamiklik, sık güncelleme ve her uygulamanın kendine özgü iş ve veri akışı karmaşıklığı artıran etkenlerdir. Mobil uygulamalar donanım uyumluluğu, yazılım güvenilirliği ve uygulama işlevselliği gibi farklı amaçlarla test edilir.

### 8.2 Yapısal (beyaz kutu) test ve test adımları

Slayta göre bir uygulamanın test edilmesi için genel olarak iki farklı test tipi vardır. Birincisi yapısal (structural) test, yani beyaz kutu (white box, saydam kutu) testtir (ekrandan, 01:35:00):

- Mobil uygulama dilleri mobilite (yeni mobil teknolojilerine uyumluluk), algılama ve enerji tüketimini yönetmek için bazı özel yapılar ekler; test bu yapılara uygun olmalıdır.
- Otomatik tarama testi yazılımı, hataların ve cihaz tutarsızlıklarının hızlı biçimde test edilmesini sağlayan güçlü ve uygun maliyetli bir araç olarak kabul edilir.
- Yeni kapsama kriterleri, en azından yeni mobilite algılamasını ve enerji yapılarını düşünmenin bir yolu olarak görülebilir.

Aynı slayttaki şekil test sürecinin adımlarını verir: Unit Testing, Integration Testing, System Testing, User Interface Testing, Regression Testing ve Acceptance Testing (ekrandan, 01:35:00). Hoca bunların derste işlenen test süreci adımları olduğunu ve mobil testte de uygulandığını hatırlatır. Fark, sistem testinin içinden kullanıcı arayüzü testinin ayrı bir adım olarak öne çıkmasıdır; çünkü mobil uygulamada arayüz özelliklerinin mutlaka test edilmesi gerekir.

### 8.3 Fonksiyonel (kara kutu) testler

İkinci tip fonksiyonel, yani kara kutu testlerdir. Burada durum temelli bir yaklaşım da kullanılır: düşük pil, uçuş modu gibi durumlarda uygulamanın nasıl çalıştığı sınanır. Bu yapı içinde yapılması gereken testler fonksiyonel test, performans testi, güvenlik testi, kullanışlılık testi, yük (load) ve stres testi, yerelleştirme (lokalizasyon) testi ve senkronizasyon testidir.

- **Kullanıcı arayüzü testi:** Farklı cihazların veriyi yeterli biçimde gösterip göstermediğini sınar. Hızlı yapılabilmesi için otomatik ve açık kaynaklı test araçlarından yararlanmak önemlidir.
- **Performans testi:** Mobil uygulamanın başarıyla piyasaya çıkmasında önemli bir adımdır. Uygulama performansı son kullanıcı için zayıfsa kullanıcı başka uygulama ve hizmetlere yönelebilir. Hız ve kullanım kolaylığını etkileyebilecek mobil taşıyıcıların testi de önemlidir. Cevap süresi belirlenir; performans ve güvenilirlik cihazın donanım gücüne, çalışma moduna, bağlantı kalitesine ve değişkenliğine bağlıdır. Bu yüzden aygıt özellikleri belirtilerek test yapılmalıdır.
- **Güvenlik testi** (ekrandan, 01:40:00): Mobil ağların farklı güvenlik seviyeleri vardır ve virüsler kişisel bilgilere erişebilir. Şifrelerin veya kullanıcı adlarının cihazda şifrelenmemiş bırakılması, diğer kullanıcılar tarafından yararlanılabilecek gerçek bir tehlikedir. Uygulama yüklenirken çeşitli bağlantı türlerine, etkileşimlere veya kullanıcı verilerine erişim için izin vermeniz, istemeniz ya da reddetmeniz istenebilir. Kurulumdan sonra bile cihazın güvenlik ayarları ve uygulama izinleri değiştirilebilir; test bu senaryoları kapsayan test durumlarını içermelidir.

### 8.4 Mobil testin zorlukları

Cihaz çeşitliliği bu tür testlerde en büyük zorluktur: farklı telefonlar, farklı donanım bileşenleri ve farklı işletim sistemleri söz konusudur ve çok sayıda cihazda test maliyeti artırır. Test sırasında şu kilit sorular sorulur: uygulama hangi cihazları ve işletim sistemi sürümlerini destekleyecek, bu platformlarda çalıştığından nasıl emin olunacak, platform farklarına uyum için hangi değişiklikler gerekecek, sürekli güncellenen yeni cihaz ve teknolojiler nasıl desteklenecek ve yapılan testlerin yeterli olduğu nasıl anlaşılacak?

> **Hocanın vurgusu:** "Testlerin yeterli olduğu nasıl anlaşılır?" sorusu yalnız mobil uygulamalar için değil, genel olarak testte önemli bir sorundur. Bu aslında olması gereken en az test sayısı sorusudur; test sayısı arttıkça maliyetin ne kadar artacağı değerlendirilerek yeterli test sayısına karar verilir.

Mobil uygulamalarda test matrisi karmaşık bir senaryoya dönüşür: ağ, gizlilik, kullanılan araçlar gibi boyutlar ve merkezde hangi test yöntemlerinin kullanılacağı birbirini etkiler. Slaytta zorluklar dört başlıkta toplanır (ekrandan, 01:45:00):

- **Parçalanma (fragmentation):** Çeşitli işletim sistemlerinde çalışan çok sayıda mobil cihaz vardır. Farklı kullanıcı arayüzleri uyumluluk nedeniyle zorluk seviyesini artırır; bu yüzden testte parçalanmalar olur.
- **Ağ (network):** Kullanıcının uygulama deneyimini etkiler. Her mobil operatör birden fazla şebeke teknolojisini destekleyebilir; bütün olası ağlarda test çok pahalı ve zaman alıcı olabilir.
- **Güvenlik:** Uygulamanın etkililiğinin ve geçerliliğinin bir başka boyutudur; uygulamanın güvenli olduğundan ve kullanıcının kişisel bilgilerinin korunduğundan emin olmak esastır.
- **Test araçlarının çeşitliliği:** Literatürde geniş bir araç seti bulunduğu için uygun test aracının eksik olma olasılığı dikkate alınmalıdır; hangi aracın seçileceği de ayrı bir karardır.

### 8.5 Test stratejileri

Cihaz zorluğunu ele almak için üç seçenek vardır: gerçek cihazlar, emülatörler ya da ikisinin birlikte kullanılması.

- **Emülatörler:** Bir test cihazı yalnız uygun cihaz profilini yükleyerek kolayca farklı cihaz türlerine geçebilir. Gerçek cihaz kullanılmadan kullanıcı arayüzü, stres ve performans gibi farklı test tipleri yapılabilir. Dezavantajı, gerçek sonuçları her zaman yansıtmayabilmesidir.
<!-- BELİRSİZ: Altyazıda mobil testlerin "%30-40'ının" emülatörlerle yapıldığı geçiyor; bu oranın slayt karesi yok, değer doğrulanamadı. -->
- **Mobil bulut bilişim çözümleri:** Mobil cihaza web arayüzü üzerinden erişilir; uygulamalar uzaktan dağıtılabilir, test edilebilir ve yönetilebilir. Saatlik kiralamayla maliyeti düşürme, sorun gidermede cihaz günlüğünü kaydetme, çok sayıda cihazın hazır olması ve birkaç cihazda paralel test yapabilme gibi faydaları vardır.
- **Gerçek ağdaki gerçek cihazlar:** Gerçek dünya senaryosu için en uygun çözüm kabul edilir, ama maliyetlidir.

Hangi stratejinin seçileceği uygulamaya bağlıdır: uygulama yalnız cihaz özelliklerine ve arayüze bağlı çalışıyorsa ve bu özellikler test araçlarınca destekleniyorsa gerçek cihazda test gerekmez. Buna karşılık uygulama cihazın coğrafi konum yeteneklerine ve çeşitli ağlarda kullanıcının varlığına dayanıyorsa gerçek cihazlarda test edilmelidir.

Sunumun sonucu şöyle özetlenir: mobil uygulamalara her zaman her yerden erişilir; farklı cihazlarda farklı işletim sistemleri bulunduğu için çeşitli cihazlarda test gerekir; büyük ölçekli mobil simülasyon ve sanallaştırma performans ve ölçeklenebilirliği değerlendirmeye yardım eder ve donanım maliyetini azaltır; farklı ağ bağlantılarıyla da test yapılmalıdır.

### 8.6 Sunum hazırlamaya dair akademik öneriler

Hoca bu örnekten hareketle bir makale sunumunda nelere dikkat edilmesi gerektiğini söyler: sunumda yararlanılan kaynaklar ilk ya da son slaytta mutlaka listelenmelidir (örnek sunumda kaynaklar yoktu). Slaytlar tekrarlardan arındırılmalıdır; konu iyi özümsendikten sonra yaklaşık 10 slayt yeterlidir. Amaç, seçilen konuyu iyi özetleyerek dinleyicilere ana hatlarını aktarmaktır. Hoca ayrıca araştırma makalelerinden, özellikle atıf indekslerine giren dergilerden seçilen konuların bilgisayar ya da yazılım kalitesi magazin yazılarına göre daha değerli olduğunu belirtir. Yazılı olarak teslim edilecek makale ise IEEE formatında hazırlanır.

## 9. SRS Belgesi Örneği Üzerinden Değerlendirme

Dersin son bölümünde hoca, uygulama projeleri için teslim edilen yazılım gereksinim belirtimi (SRS) belgelerinden rastgele birini açarak IEEE 830 düzenini ve sık yapılan hataları gösterir. Örnek belge, bir HTTP istemci kütüphanesi için hazırlanmış bir "Yazılım Gereksinim Analizi"dir (ekrandan, 02:05:00).

### 9.1 Belgenin yapısı

IEEE 830'a göre gereksinim belgesinde önce amaç, ürün kapsamı ve genel tanım verilir, sonra gereksinimler, ardından sistem özellikleri belirtilir. Örnek belgede giriş kısmı oldukça uzundur: ürünün nasıl bir ürün olduğu, referanslar ve belgede geçen kısaltmalar tanımlanmış, uygulamanın çalışma ortamı bir diyagramla gösterilmiştir. İşlevsel gereksinimler sistemin kullanıcıya hangi hizmetleri verdiğini tanımlar; ürünün fonksiyonları ve kullanıcı belgelerinin taşıması gereken özellikler de verilmiştir.

### 9.2 İşlevsel gereksinimlerin ayrıntı düzeyi

Hoca, yalnız ürünün hangi işleri yapabileceğini sıralayan genel bir fonksiyon listesinin yetmediğini, her iş adımının daha alt seviyede görülmek istendiğini vurgular. Örnek belgede iki temel fonksiyon use case diyagramlarıyla verilmiş, her use case için alt işlemler yazılmıştır. Örneğin "isteğin iptal edilmesi" use case'i bir şekille gösterilmiş ve şu biçimde açıklanmıştır (ekrandan, 02:10:00):

- **Kısa açıklama:** Kullanıcı, kütüphane ile yaptığı bir isteği iptal eder.
- **Detaylı açıklama:**
  1. Kullanıcı kütüphaneyi projeye dahil eder (import).
  2. Kullanıcı isteği yaparken tanımlamış olduğu jetonu (token) getirir.
  3. Jetonun `.source()` metodu ile isteğin referansına erişilir.
  4. İsteğin referansının `.cancel()` metodu ile istek iptal edilir.

Hoca, istediği alt işlem gereksinim tanımlarının tam olarak bu düzeyde olduğunu söyler: önce uygulamanın alt fonksiyonları yazılır, sonra bu fonksiyonların hangi use case çerçevesinde ve hangi alt işlemlerle yapılacağı belirtilir.

### 9.3 Fonksiyonel olmayan gereksinimlerin yeri

Örnek belgenin "4. Sistem Özellikleri" başlığı altında şu alt başlıklar vardır (ekrandan, 02:15:00):

- **Performans gereksinimleri:** JavaScript'in asenkron çalışması nedeniyle aynı anda birden çok isteğe izin vermeli; alt katmandaki API'lar üzerine hissedilebilir bir yavaşlık koymamalı.
- **Güvenilirlik gereksinimleri:** Aynı anda işlenen isteklerin karışmamasını, alt katmandan gelen mesajın kullanıcıya iletilmesini ve internet olmaması ya da sunucunun bulunamaması gibi durumlarda çökmemeyi garanti eder.
- **Güvenlik gereksinimleri:** XSRF koruması içerir ve güncel HTTP güvenlik protokollerini destekler.
- **Donanım gereksinimleri:** Modern tarayıcıların ya da Node.js'in kurulabildiği, internet bağlantısı olan sistemlerde kullanılabilir.
- **Evrilebilirlik:** İleride çıkabilecek güvenlik açıklarına ve yeni protokollere uyum sağlayabilmelidir.

Hocanın değerlendirmesi: "sistem özellikleri" diye verilen bu maddeler aslında fonksiyonel olmayan (işlevsel olmayan) gereksinimlerdir; başlığın bu şekilde konması daha doğru olurdu. Ayrıca donanım gereksinimi bunlardan ayrı bir başlık olarak verilmeliydi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:25:05): Yazılım konfigürasyon yönetimi nedir? Yazılım konfigürasyon elemanları nelerdir?

> **Cevap (derste verildi):** Yazılım konfigürasyonu, yazılım mühendisliğinin ürünleri olan programlar, belgeler ve veri yapılarına (ayrıca test verileri ve veritabanı elemanlarına) ait bütün maddelerin toplamıdır; bunlar konfigürasyon elemanlarıdır. Yazılım konfigürasyon yönetimi, bu elemanların geliştirmenin başından kullanımın sonuna kadar hangi sürümde, hangi tarihte, hangi içerikte olduğunu ve hangi değişikliklere uğradığını izler. Etkinlikleri konfigürasyon tanımı, değişiklik kontrolü, denetim ve durum raporlamadır; bunlar eleman değil, elemanlara uygulanan işlemlerdir (ekrandan, 00:25:00).

**Soru 2** (derste sözlü, 00:13:52): Geleneksel yazılım geliştirme süreç modellerine göre çevik modellerde test ve kalite etkinlikleri nasıl farklılaşır?

> **Cevap (derste verildi):** Dinamik kalite değerlendirme (test) statik değerlendirmeden daha fazla uygulanır; kaliteyle ilgili işlemler sürecin daha erken adımlarında başlar; kalite etkinlikleri daha kısa aralıklarla, daha sık yapılır; doğruluk ve süreklilik kullanıcı hikayeleri, birim testler ve müşteri geri beslemesiyle sağlanır (ekrandan, 00:15:00).

**Soru 3** (derste sözlü, 01:34:28): Test süreci hangi adımlardan oluşur ve mobil uygulama testinde hangi adım öne çıkar?

> **Cevap (derste verildi):** Birim testi, tümleştirme testi, sistem testi, kullanıcı arayüzü testi, regresyon testi ve kabul testi (ekrandan, 01:35:00). Mobil testte sistem testinin içinden kullanıcı arayüzü testi ayrı bir adım olarak öne çıkar, çünkü arayüz özelliklerinin farklı cihazlarda mutlaka sınanması gerekir.

**Soru 4** (derste sözlü, 01:42:36): Yapılan testlerin yeterli olduğu nasıl anlaşılır?

> **Cevap (derste verildi):** Bu, olması gereken en az test sayısı sorusudur ve yalnız mobil uygulamalara özgü değildir. Test sayısı artırıldığında maliyetin ne kadar artacağı değerlendirilerek yeterli test sayısına karar verilir.

**Soru 5** (derste sözlü, 02:11:27): Bir SRS belgesinde performans, güvenilirlik, güvenlik ve donanım gereksinimleri "Sistem Özellikleri" başlığı altında verilmiştir. Bu düzen IEEE 830 açısından nasıl değerlendirilir?

> **Cevap (derste verildi):** Performans, güvenilirlik ve güvenlik maddeleri fonksiyonel olmayan gereksinimlerdir ve bu başlıkla verilmelidir. Donanım gereksinimi bunlardan ayrı bir başlıkta yer almalıdır. Fonksiyonel gereksinimler ise yalnız üst düzey fonksiyon listesi olarak değil, use case'ler ve her use case'in alt işlem adımlarıyla verilmelidir.

## Dersin Toparlaması

Ders, çevik yaklaşımların test ve kalite boyutunu toparlayarak başladı: XP'nin dört temel değeri, çevik modellerde testin daha erken, daha sık ve daha dinamik yapılması ve test güdümlü geliştirmenin döngüsü. TDD'nin üretkenliği artırdığı ama kaliteyi belirgin biçimde değiştirmediği bulgusu hatırlatıldı. Ardından yazılım konfigürasyonu ile konfigürasyon yönetimi etkinliklerinin farkı netleştirildi; bu ayrım, dersin yeni konusu olan Release Management'a geçişi hazırladı. Release Management, yeni bir yazılımın ya da sürümün canlı ortamı koruyarak, kullanıcı ve iş birimi uyumunu gözeterek devreye alınması olarak tanımlandı; ITIL'deki altı alt süreci, release manager'ın rolü, faydaları ve DevOps ile ilişkisi işlendi.

Dersin ikinci yarısında örnek bir makale sunumu üzerinden mobil uygulamalarda test ele alındı: yapısal ve fonksiyonel testler, kullanıcı arayüzü, performans ve güvenlik testleri, parçalanma ve ağ çeşitliliği gibi zorluklar ve emülatör, mobil bulut ve gerçek cihaz stratejileri. Son olarak bir SRS belgesi üzerinden IEEE 830 düzeni ve işlevsel gereksinimlerin use case alt adımlarıyla, fonksiyonel olmayan gereksinimlerin ayrı başlıkta verilmesi gerektiği gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
