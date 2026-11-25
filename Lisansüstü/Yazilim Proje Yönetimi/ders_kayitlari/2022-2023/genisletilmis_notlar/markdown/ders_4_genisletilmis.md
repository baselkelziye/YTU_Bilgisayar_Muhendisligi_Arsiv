# Ders 4 Genişletilmiş Notu: Proje Kavramı, Proje Başarısı ve Proje Yönetimi Yol Haritası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynak Kitabı ve Başvuru Kaynakları
- 2. Başarılı Proje: Kapsam, Bütçe, Zaman ve Kalite
- 3. Projeler Neden Başarısız Olur?
- 4. Proje Kontrolü
- 5. Proje Nedir?
- 6. Proje Katılımcıları ve Proje Yönetim Ofisi
- 7. Proje Yönetimine Genel Bakış
- 8. Proje Yönetimi Yol Haritası
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kaynak Kitabı ve Başvuru Kaynakları

Dersin ilk bölümü dönem projelerinin konularının belirlenmesine ayrıldı; akademik anlatım ekran paylaşımıyla başladı. Hoca, dersin bundan sonra büyük ölçüde izleyeceği kitap olarak AMACOM yayınlarından *Information Systems Project Management* kitabını gösterdi (ekrandan, 00:45:00). Kitap, bilgi teknolojileri projelerinde işin teslimine kadar gerçekleşen işlerin yönetimini anlatır: proje nedir, projenin katılımcıları kimlerdir, bir çalışmanın proje sayılması için neler gerekir.

Kitabın ikinci baskısının önsözünde bölümler şöyle sıralanır (ekrandan, 00:45:00): giriş bölümünde proje yönetim ofisinin rolü ve aynı anda hem yönetici hem katılımcı olmanın tuzakları; ikinci bölümde projenin anlaşılması ve proje başlatma (project initiation); üçüncü bölümde projenin tanımlanması, kapsam bildirimi için kontrol listesi ve sistem geliştirme yaşam döngüleri (SDLC); dördüncü bölümde projenin planlanması ve gerçekleştirmenin planlanması.

Hoca kitabın eski olduğunu, ama proje yönetiminin temel ilkelerini iyi işlediği için seçtiğini söyledi. Aynı konuda farklı yazarların çok sayıda *Software Project Management* ya da *Information Systems Project Management* kitabı vardır. Güncel yaklaşımlar için önceki derslerde önerilen iki kaynak çalışma hayatında da sürekli takip edilmelidir:

- **Project Management Body of Knowledge (PMBOK):** Project Management Institute'un sayfasında proje yönetim adımları ve çevik projelerle ilgili güncel yaklaşımlar bulunur.
- **Software Engineering Body of Knowledge (SWEBOK):** yazılım mühendisliği bilgi alanlarını tanımlar.

Ayrıca yazılım geliştirme süreç adımlarının plana nasıl yansıtılacağı ve nasıl takip edileceği için Pressman'ın *Software Engineering* kitabından eklemeler yapılacaktır.

Kitaba göre proje yönetimi şu sırayla ilerler: projenin anlaşılması ve tanımlanması (hemen plana başlanmaz; nasıl ki hemen kod yazmaya başlanmıyorsa, plandan önce de proje konusu anlaşılır), projenin alanının ve süreç yapısının tanınması, bilgi sistemi geliştirme yaşam döngüsünün belirlenmesi, ardından planlama. Sonra proje çalıştırılır (running) ve izlenir. Plan orada durmaz, sürekli izlenir. Özellikle çevik projelerde izleme aşaması planı yenilemek demektir; plan sürekli güncellenebilir. En sonda projenin kapatılması gelir ve bu ayrı bir adım olarak ele alınabilir.

## 2. Başarılı Proje: Kapsam, Bütçe, Zaman ve Kalite

### 2.1 Üç ayaklı yapı

Başarılı bir proje üç ayaklı bir yapıya, bir üçgenin sınırlarına benzetilir:

- **Alan / kapsam (scope):** Projenin sınırları nasıl belirtilmişti ve bu sınırlar içinde yapılması gereken bütün işler yapıldı mı?
- **Bütçe (budget):** Proje planlanan bütçeyle gerçekleştirildi mi?
- **İş listesi / zaman planı (schedule):** İş listesi zamana aktarıldığında temel işler belirli zamanlarda gerçekleştirildi mi, proje süresi aşıldı mı?

Bu üçünü sağlamak projeyi başarılı kılar. Ancak üçgenin içinde bir de **kalite** kavramı vardır: geliştirilen yazılım istenen işleri istenen kalitede yapıyor mu ve kullanım süresince aynı faydayı sağlıyor mu?

Hoca bunu iki karşıt örnekle açıkladı. Birinci örnekte proje zamanında, istenen bütçeyle bitmiş ve istenen işleri yapmaktadır. Kullanıma alındıktan üç ay sonra başta planlanmayan bir veri tabanı sorunu yüzünden verimi hızla düşer, yazılım yavaşlar. Kalitesinde sorun olduğu için bu projeye başarılı denemez. İkinci örnekte proje süresini ve bütçesini biraz aşmıştır, ama hatalar giderilerek yıllarca kullanılan bir yazılım elde edilmiştir. Bu proje başarılıdır.

> **Hocanın vurgusu:** Başarılı projenin üç sac ayağını unutmayın: kapsam, bütçe ve zaman planı. Bunlara ek olarak kalite de önemlidir; yazılımın belirli bir süre kullanıldıktan sonra da aynı kalitede kalıp kalmadığına bakılarak projenin başarılı olduğuna karar verilir.

### 2.2 Teknik metrikler ve müşterinin faydası

Kitap bu noktada bir adım daha atar (ekrandan, 00:50:00): bütçe, zaman ve kapsam, projenin ne kadar iyi yönetildiğini tanımlayan teknik metriklerdir ve müşterinin asıl kaygılarıyla az ilgilidir. Bir proje, müşteri daha düşük stok, daha az personel ya da daha yüksek satış gibi bir fayda beklediği için yapılır. Proje kusursuz yürütülse bile şirket bu faydayı elde etmezse harcanan para boşa gitmiş olur.

Kitaptaki sayısal örnek (ekrandan, 00:50:00):

- Verilen: 10 milyon dolarlık stoğu olan bir şirket, stok kontrol sistemi için 100.000 dolar bütçeler. Amaç stoğu yüzde 20 azaltmaktır.
- Stok azalması: $0{,}20 \times 10.000.000 = 2.000.000$ dolar.
- Yüzde 10 faizle yıllık taşıma maliyeti kazancı: $0{,}10 \times 2.000.000 = 200.000$ dolar/yıl.
- Proje yüzde 100 bütçe aşımı yaşar: maliyet $100.000 + 100.000 = 200.000$ dolar olur.
- Şirket sistemi uygulamazsa ya da stoğu azaltamazsa bütçe ile aşımın toplamı, yani 200.000 dolar boşa gitmiştir.
- Sistem uygulanır ve stok beklendiği gibi azalırsa aşım $100.000 / 200.000 = 0{,}5$ yılda, yani altı ayda; sistemin tamamı $200.000 / 200.000 = 1$ yılda kendini öder.

Kitabın vardığı sonuç, sistemin sağladığı faydanın genellikle yıkıcı görünen aşımları bile geride bıraktığı, ama bunun için sistemin uygulanması ve faydanın gerçekleşmesi gerektiğidir. Bu, bütçeyi önemsememek anlamına gelmez; proje yöneticisi sistemin teslimi kadar faydanın teslimiyle de ilgilenmelidir. Hoca da aynı yönde, zamanında bitmiş ve istenenlerin hepsini yapan bir projede baştan fark edilemeyen maliyetler çıkmış olsa bile bunları ekonomik olarak karşılayacak yollar bulunduysa projenin yine başarılı sayılabileceğini söyledi.

## 3. Projeler Neden Başarısız Olur?

Kitabın "Why do projects fail?" bölümü çarpıcı başarısızlık hikayeleriyle açılır (ekrandan, 00:55:00): 10 milyon dolar bütçelenen bir proje 100 milyon doları geçince iptal edilir; temmuz sonunda teslim edilmesi gereken bir sistem iki yıl sonraki eylül sonunda teslim edilir. Hoca da bütçesi katlanarak büyüyen ve bitmesi için daha da para gereken bir projeye başarılı denemeyeceğini belirtti.

Kitaba göre en sık gösterilen suçlu kötü tahmindir, ama bu bir efsanedir: tahmin yüzde 100 yanlış olsa bile toplam maliyet en fazla iki katına çıkar ve bu, sektörün bilinen dev aşımlarıyla kıyaslanamaz. Kitap üç tekrarlayan neden sayar (ekrandan, 00:55:00):

- **Kapsam değişiklikleri:** büyük olasılıkla en önemli neden. Sorun yalnız maliyet eklemeleri değil, görünen eforla orantısız maliyet eklemeleridir. Örnek: 1 milyon dolar tahmin edilen bir proje 2 milyon dolarlık olarak baştan planlansa 2 milyon dolar tutacak bir projeye büyür; ama kapsam değişiklikleri planlamayı ve tamamlanmış işi bozduğu için son maliyet 4-5 milyon dolara yaklaşır. Kapsam ya başta açıkça belirlenmediği ya da değişiklikler kötü yönetildiği için sorun olur.
- **Zayıf proje planlaması.**
- **Teknoloji.**

Hoca bunlara ek olarak şu etkenleri saydı: müşterinin projeyle ilgilenmesi, yardım etmesi ve projenin içinde bulunması; hangi süreç modelinin seçildiği; proje elemanlarının doğru yerleştirilmesi; proje planına uygun hareket edilmesi; alt yüklenicilerin ve dışarıdan çalıştırılan firmaların iyi yönetilmesi ve baştan planlanması.

> **Hocanın vurgusu:** Projenin başarısız olmasında en önemli etken üst yönetimin projeye sahip çıkmasıdır. Üst yönetim projeyi destekliyorsa projenin imkanları daha iyidir ve başarı şansı yükselir; destek bulamayan proje bir takım zorluklarla karşılaşır.

## 4. Proje Kontrolü

Proje için bir kontrol aşaması oluşturulmalıdır. Projedeki gereksinimler proje raporlamasıyla ortaya çıkar:

- **Durum raporları:** Projeden sürekli durum raporu alınmalıdır. Hangi sıklıkla alınacağı da önemlidir ve baştan belirlenir.
- **Eskalasyon yapısı:** Projede gerçekleşen işlerden ve zorluklardan hem yöneticinin ekip içinden erken haber alması hem de yönetimin işleyiş hakkında haberdar edilmesi gerekir. Proje yöneticisi ekipten durumun nasıl gittiğine dair sürekli bilgi alır ve üst yönetime zamanında haber verir.

Bunların hepsi projenin başarısını etkiler.

## 5. Proje Nedir?

### 5.1 Basit tanım

Proje, birden fazla aktivitesi (alt işi) olan ve bu alt işlere bölünebilen bir iştir. Genellikle yeni bir ürün ya da yeni bir aktivite gerçekleştirmeyi gerektirir. Çoğunlukla birden fazla kişi çalışır, ama tek kişi de bir projeyi yürütebilir. Önemli olan şunlardır:

- Birden fazla alt işin bulunması ve bu işlerin bir **hedef** doğrultusunda olması,
- Başının ve sonunun belli olması: bir başlangıç ve bir bitiş zamanı,
- Bir **yenilik** içermesi.

### 5.2 Rutin iş ile proje ayrımı

Bir telekom şirketi her ay faturaları bir yazılımla hazırlar, basar ve dağıtır. Bu bir proje değildir, rutin bir iştir. Aynı şekilde bilgisayarınıza yeni bir işletim sistemi kurup çalışır hale getirmek ya da temizlik yapmak çok vakit alsa da proje değildir.

Ama faturalara bir değişiklik isteği gelirse (amblem değişecek, yeni bir yazı ya da alan eklenecek), bu bir projedir. Bir başlangıç zamanı vardır ve "bir sonraki ayın fatura basımına kadar bu değişiklik yapılmalı" denir. Değişikliğin aralıklarla yapılması ve yeni bir yazılım sürümünün oluşturulması planlanır.

Proje teknik bir iş de sosyal bir uygulama da olabilir. Yeni bir ürünün piyasaya çıkışı için yapılan reklam kampanyası, rakip firmaların çıkış tarihi de belliyse, başlangıcı ve geçirilemez bir bitişi olan, hedefli tam bir projedir. Seçim çalışmaları da zaman hedefli bir projedir: süre geçtikten sonra bir anlamı kalmaz. Dersteki dönem projeleri de böyledir: teslim tarihinden sonra bitirilen bir projenin kıymeti yoktur. Bu tür projelerde hedef zamanında bitirmektir; biraz eksik yapılsa ya da biraz fazla iş gücü (efor) harcansa bile önemli olan zamanında bitirmektir.

### 5.3 Proje tanım kriterleri

Kitap, bir işin ne zaman proje sayılacağı sorusuna "How do you know you have a project?" bölümünde cevap arar. Büyük, pahalı, görünür, onlarca kişinin çalıştığı projelerin yönetim gerektirdiği açıktır; ama daha küçük işler ne zaman proje yöneticisinin ilgisini gerektirir? Kitabın örneği: donanım ek bellek ve ek disk kapasitesiyle yükseltilirken aynı anda işletim sisteminin yeni sürümü kuruluyor. Bu bir proje midir, yoksa sistem ekibine proje yapısı dayatılmadan bırakılabilir mi (ekrandan, 01:00:00)? Birinin günlük sorumlulukları ile proje arasında gri bir alan vardır. Kitap bunun için bir kriter listesi verir (Exhibit 1.1, Project Definition Criteria; ekrandan, 01:05:00):

- Aktiviteler ikiden fazla kişiyi kapsar.
- Aktiviteler iki haftadan fazla iş gücü gerektirir.
- Aktiviteler bir aydan uzun takvim süresi gerektirir.
- Aktiviteler önemli risk içerir.
- Aktiviteler başarısız olursa önemli bir etki doğar.
- Aktiviteler iki ya da daha fazla departmanın koordinasyonunu gerektirir.
- Aktiviteler dış ortakları kapsar.
- Aktiviteler yeni teknoloji içerir.
- Aktiviteler normal işlerin kapsamı dışında kalır.

Listenin altındaki nota göre iki ya da daha fazla kutu işaretlenirse, özellikle koordinasyon ya da risk içerenler, aktiviteler bir proje olarak ele alınmalıdır (ekrandan, 01:05:00). Hoca bu maddelerin mutlaka olması gereken şeyler değil, projelerde genellikle görülen özellikler olduğunu vurguladı. Projelerde birlikte çalışma vardır; tek bir departman değil, bazen birden fazla departmanın koordinasyonu, hatta dışarıdan iş ortakları gerekir.

Temel olanlar ise başlangıç tarihi, bitiş tarihi, alt aktivitelerin de başlangıç ve bitiş tarihlerine ayrılabilmesi ve sonunda bir hedefin bulunmasıdır. Kitaptaki donanım yükseltme ve belirli yazılımların kurulumu örnekleri rutin işlerdir. Projenin ise amacı, riskleri ve teslim süresinin belirlenmesi gibi hedefleri vardır.

### 5.4 Somut, hizmet ve sosyal projeler

Kitabın tanımına göre proje, başlangıcı ve sonu açıkça belirlenmiş, somut bir ürün ortaya koyan aktiviteler dizisidir. Proje yeni bir uygulama sistemi ya da önemli bir iyileştirme üretebilir; hazır bir yazılım paketinin kurulması, donanım yükseltmesi, uygulama gereksinimleri gibi rapor ve analizler, bir teknoloji mimarisi, stratejik teknoloji planı ya da yeniden yapılandırma planı da proje çıktısı olabilir. Buna karşılık düzenli bakım, yardım ya da danışmanlık gibi süregelen işler proje değildir (ekrandan, 01:15:00).

Hoca kapsamı genişletti: proje bir yazılımın geliştirilmesi ya da bir köprünün yapılması gibi somut bir iş, bir hizmet ya da bir ürünün tanıtımı ve pazarlama süreci gibi sosyal bir iş olabilir.

**Konferans örneği.** Üniversitede nisan ayında üç gün sürecek bir konferans düzenlendiğini düşünelim. Konferans yalnızca üç gün sürer, ama hazırlığı en az sekiz ay önce başlamalıdır:

1. Konferans çalışanlarının ve organizasyon komitesinin belirlenmesi,
2. Konferans yerinin belirlenmesi,
3. Program komitesinin belirlenmesi,
4. Bildiri gönderme duyurusunun hazırlanması,
5. Bildirilerin alınması ve program komitesine gönderilmesi,
6. Değerlendirme süreci ve kabul edilen bildirilerin duyurulması,
7. Kabul edilen bildirilerin tam metinlerinin alınması.

Bu, bildiri gönderenler için olan süreçtir. Bir de organizasyon süreci vardır: davetli konuşmacı listesi, program listesi, paralel oturum olup olmayacağı, sosyal etkinlikler, ikramlar. Biri bittiğinde diğeri başlayan bu işlerin zamanlanması ve planlanması bir projedir, çünkü yeni bir iş yapılmaktadır.

## 6. Proje Katılımcıları ve Proje Yönetim Ofisi

### 6.1 Katılımcılar

Kitap proje katılımcılarını şöyle tanımlar (ekrandan, 01:15:00):

- **Müşteri (client):** Projenin neyi başaracağını belirleyen, faturayı ödeyen ve sistemin teslimini kabul eden şirket ya da departmandır. Danışmanlık firmasının müşterisi gibi dış bir müşteri ya da şirket içi bir departman olabilir.
- **Müşteri ekibi:** Müşteriyi temsil eden personel; aralarında müşteri yöneticileri, karar vericiler ve kullanıcılar vardır.
- **Proje yöneticisi:** Bir projenin ya da alt projenin zaman planından, bütçesinden, işlevselliğinden ve gerçekleştirilmesinden sorumlu kişidir. Bazı kurumlar proje yöneticisi ile proje lideri arasında ayrım yapar; kitaba göre fark, sorumlulukta değil adlandırmada ve bazen proje büyüklüğündedir.
- **Kullanıcılar:** Projenin sonuçlarını fiilen kullanacak kişilerdir. Çoğu projede müşteri ekibinin parçasıdırlar ve proje gereksinimlerini belirlemekten sorumludurlar.

**Proje sponsoru.** Önceki derslerde de değinilen sponsor, projenin parasını ödeyen, projeyi mali olarak destekleyen ve projeyi kullanacak taraftaki kişidir. Büyük bir şirkette yazılım birimine bir iş istendiğinde, yazılımı hangi departman kullanacaksa o departmanın yöneticisi sponsordur. Örneğin muhasebe birimi için yazılım üretilecekse muhasebe departmanının yöneticisi projenin sponsorudur, çünkü proje başarısı hakkında üst yönetime o bilgi verecektir. Proje alanının tanımlanması da müşteri tarafındaki bu grupla birlikte yapılır.

### 6.2 Proje yönetim ofisi (PMO)

Kitaba göre proje yönetimini standartlaştırma çabaları iki sorunla karşılaşır: proje yöneticileri kuruluştan ayrıldığında belgeler kişisel tercihlerine göre tutulduğu için yerlerine gelenler işi devralmakta zorlanır; satın alınan metodolojiler ise çoğunlukla proje aktivitelerine (geliştirme gibi) odaklanır, projelerin nasıl yönetileceğine değil, ve tutarsız uygulandıklarında işe yaramaz (ekrandan, 01:10:00). Giderek kabul gören çözüm proje yönetim ofisidir (Project Management Office, PMO): kuruluşta ya da onun bir bölümünde proje yönetimi uygulamasından ve disiplininden sorumlu kurumsal birimdir. PMO'lar kuruluşa göre değişir: bazıları yetkisi olmayan destek gruplarıdır, bazıları proje yöneticileri üzerinde yönetim kontrolü ve proje başarısı sorumluluğu olan tam departmanlardır. Bir BT ya da mühendislik departmanına, proje yönetimini stratejik gören kuruluşlarda üst yönetime, hatta genel müdüre raporlayabilir (ekrandan, 01:10:00).

Hoca, proje yöneticisi ve onunla birlikte çalışanlardan oluşan yapıya proje yönetim ofisi denebileceğini söyledi. Çevik projelerde çevik koç ve bütün ekibin, yani projede iş yapan herkesin birlikte proje yönetim ofisi gibi çalıştığı da söylenir. Yine de sektörde çevik projelerde de üst yönetim ile proje ekibi arasında işlerin sürdürülmesini sağlayan bir proje yöneticisi bulunur.

### 6.3 Proje yönetimi ve sistem geliştirme yaşam döngüsü

Proje yönetimi ile sistem geliştirme yaşam döngüsü (System Development Life Cycle) arasında bir ilişki vardır. Bilgi sistemi, özellikle yazılım geliştirme işlerinde projede gerçekleştirilecek iş adımları, seçilen yazılım geliştirme süreç modelinin gerektirdiği adımlardır. Proje yönetimi adımlarını yazılım geliştirme adımlarıyla uyumlu hale getiren kişi proje yöneticisidir. Projenin gerçekleştirilmesinden ve projeyle alt projeler arasındaki ilişkiden de proje yöneticisi sorumludur.

## 7. Proje Yönetimine Genel Bakış

### 7.1 Proje planlama, proje yönetimi değildir

Kitabın "About this book" bölümüne göre her projenin dört ayrı aşaması vardır: projeyi anlamak, tanımlamak, planlamak ve çalıştırmak. Bu aşamaların hepsinde proje yönetimi bağlamı içinde hem genel yönetim becerileri hem de özelleşmiş proje yönetimi becerileri kullanılır. Kitaptaki şekil (Exhibit 1.2, Project Management Overview) şöyledir (ekrandan, 01:20:00):

```text
Proje Yönetimi Bağlamı (sekizgen çerçeve)
  İki kesişen daire:
    - Genel Yönetim Becerileri (General Management Skills)
    - Özelleşmiş Proje Yönetimi Becerileri (Specialized Project Management Skills)
  Kesişim bölgesindeki dört aşama:
    Projeyi anlama (Understanding the project)
    Projeyi tanımlama (Defining the project)    Projeyi planlama (Planning the project)
    Projeyi çalıştırma (Running the project)
```

> **Hocanın vurgusu:** Proje planlama eşittir proje yönetimi değildir. Bu şekle bakınca ilk anlaşılması gereken budur. Planlama, proje yönetiminin alt başlıklarından yalnızca biridir; önce projeyi anlama ve tanımlama gelir.

### 7.2 Üçüncü halka: alan bilgisi

Hoca ilk derste bu yapının üç daire olarak gösterildiğini hatırlattı. Yalnız genel yönetimi ve proje yönetim tekniklerini bilmek bir projeyi yönetmek için yeterli değildir; üçüncü bir halka daha vardır: alan, yani yazılım konusunda bilgi sahibi olmak. Proje yönetimi topluluğunda zaman zaman, genel yönetim bilgisi ve proje yönetimi yetenekleri olan bir kişinin her projeyi yönetebileceği fikri savunuldu. Bu çok başarılı olmadı ve daha sonra bu görüşten sapıldı. Yazılım geliştirme bilgisi olmayan bir kişi, genel yönetim ve proje yönetimi yetenekleri olsa bile bir yazılım projesini iyi yönetemez. Çünkü zaman ve kaynak planı yaparken hangi yetenekteki kişinin hangi işte görevlendirileceğini ve hangi işin en az ne kadar süreceğini bilmesi gerekir. Aynı şekilde bir köprü yapımını yöneten kişinin de her alt aktivitenin ne kadar süreceğini ve kimlerin yapabileceğini bilmesi için o alanda bilgisi olmalıdır. <!-- BELİRSİZ: 01:20:16 civarında altyazı bozuk ("Bir kişinin inşaat projesini yönetmesi daha doğru"); büyük olasılıkla inşaat bilgisi olan kişinin inşaat projesini yönetmesinin daha doğru olduğu kastediliyor. -->

### 7.3 Beş adım

Kitap dört başlık kullanır ve projenin kapatılmasını çalıştırmanın (running) bir parçası olarak alır. Risk yönetimi ve geçmiş proje arşivleri önem kazandıkça, biten projelerin kapatılması sırasında yapılan işler ayrı bir boyut kazanmıştır. Bu yüzden derste beş adım kullanılacaktır:

1. Projenin anlaşılması,
2. Projenin tanımlanması,
3. Projenin planlanması,
4. Projenin izlenmesi ve kontrolü (çalıştırma),
5. Projenin kapatılması.

## 8. Proje Yönetimi Yol Haritası

Aradan sonra hoca, her aşamanın içinde hangi işlerin bulunduğunu kitaptaki "Project Management Roadmap" (Exhibit 1.3) üzerinden anlattı (ekrandan, 01:45:00, 01:55:00). Şekilde dört kutu (anlama, tanımlama, planlama, çalıştırma) çift yönlü oklarla birbirine bağlıdır ve her kutunun yanında proje yöneticisinin kendine sorması gereken sorular vardır. Hoca bu yol haritasının bir kontrol listesi olarak elde bulunması gerektiğini söyledi.

### 8.1 Projeyi anlama

Ekrandaki sorular (ekrandan, 01:50:00):

- Projenin gerekçesini anlıyor muyum?
- Projenin arka planını anlıyor muyum?
- Proje politikalarını anlıyor muyum?
- Oyuncuların kimler olduğunu ve hangi rolleri üstleneceklerini anlıyor muyum?
- Müşterinin önceliklerini anlıyor muyum?

Hoca bu soruları açtı. Projenin hikayesi nedir: fikir bir ekip üyesinden mi çıktı, yönetim tarafından yukarıdan mı verildi, yoksa bir iş sırası dahilinde sıra bu işe mi geldi? Projede hangi roller var: sistem analisti, kod geliştirici, veri tabanı uygulayıcısı? Müşteri tarafı kimdir, önceliği nedir?

Yazılım proje yönetiminde her proje sıfırdan bir yazılımın geliştirilmesi değildir. Bir yazılım sisteminin satın alınıp uyarlanması (customization) ya da yalnız bakımının yapılması da proje olabilir. Bu yüzden projenin sınırları ve yapısı farklılık gösterir.

Kitap projeyi yönetmek için anlaşılması gereken dört şeyi şöyle sıralar (ekrandan, 02:05:00):

1. **Bu proje neden yapılıyor?** Müşteri bundan ne elde etmeyi bekliyor?
2. **Projenin arka planı nedir?** Bugünkü noktaya nasıl gelindi?
3. **Oyuncular kimler?** Projeyi kim savundu, kim karşı çıktı, üst düzey sponsor (executive sponsor) kim?
4. **Müşterinin bu projedeki öncelikleri nelerdir?**

Kitaba göre bu sorular örtüşür ve kapsayıcı değildir; projeler farklı çıkarları, felsefeleri ve öncelikleri olan insanların dinamik bir karışımıdır ve proje yöneticisinin temel işlevlerinden biri bu karışımı tutarlı hale getirip projeyi ileri taşımaktır (ekrandan, 02:05:00).

**Müşteri önceliği.** Hoca müşteri önceliğinden kastın, proje başarı göstergelerinden (zaman, bütçe ya da iş gücü, kapsam ve kalite) hangisinin müşteri için öncelikli olduğu olduğunu açıkladı. Bazı müşteriler maliyeti en düşük tutmayı hedefler, bazıları süreyi. Önceliği anlayıp planı buna göre yapmak proje yöneticisinin önceliğidir. Dönem projeleri örneğinde öncelik sürenin aşılmamasıdır: süreyi aşmamak için daha fazla iş gücü harcanabilir, bazı maddeler daha kısa yazılabilir, modellemede eksikler kalabilir; önemli olan bitirmektir. Bir yerde ayrıntıya girip projeyi tamamlamamak en kötüsüdür.

### 8.2 Projeyi tanımlama

Ekrandaki sorular (ekrandan, 01:50:00):

- Proje teslim edilecekleri (deliverables) tanımladım mı?
- Kapsamı, hem sistem hem proje kapsamını, belirledim mi?
- Teslim edileceklerin nasıl gözden geçirilip onaylanacağını belirledim mi?
- Müşteri ekibinin yapısını ve organizasyonunu tanımladım mı?

**Teslim edilecekler.** Sektörde genellikle kaynak kodun verilip verilmeyeceği konuşulur. Ama bazı anlaşmalarda tasarımla ilgili model elemanları, SRS (yazılım gereksinim belirtimi) belgesi, gereksinim analizi sonucunda oluşan diğer belgeler, test durumları ve hangi veriyle test edildiği, proje planı, proje riskleri gibi çok farklı belgeler de istenebilir. Yalnız kod değil, ER modeli ve veri tabanı modeli de teslim edilecekler arasında olabilir.

**Kapsam.** Sistem kapsamı ve proje kapsamı ayrı kavramlardır; aralarındaki farklılıklar ileride ele alınacaktır.

**Gözden geçirme ve onay.** Ara teslimlerin nasıl gözden geçirileceği önemli bir sorudur. Şelale aşamalarıyla mı gidiliyor, başka bir süreç modeliyle mi? Her modelde bu aşamalar farklıdır (yazılım geliştirme süreç modellerinde görüldüğü gibi). Müşterinin kontrolünün ve gözden geçirmenin nasıl olacağı planlanmalı ve tanımlanmalıdır.

**Müşteri ekibi.** Müşteri ekibinin yapısı da tanımlanmalıdır.

### 8.3 Projeyi planlama

Ekrandaki sorular (ekrandan, 01:50:00):

- Riskleri tanımlayıp azaltma planları geliştirdim mi?
- Proje kabullerini ve kısıtlarını belgeledim mi?
- Bir kalite planı geliştirdim mi?
- Ayrıntılı proje aktiviteleri listesi hazırladım mı?
- Aktiviteler arasındaki bağımlılıkları tanımladım mı?
- Gereken işin tahminini yaptım mı?
- Kaynakları atayıp seviyelendirdim mi?
- Kilometre taşlarıyla zaman planını tamamladım mı?
- Zaman planını müşterinin gereksinimleriyle uyumlu hale getirdim mi?
- Proje bütçesini geliştirdim mi?
- Gerçekleştirmeyi (implementation) planladım mı?
- Tamamlanmayı (completion) planladım mı?
- İletişimi planladım mı?
- Genel bir proje planı hazırladım mı?

Hoca bu listede önce kabullerin ve kısıtların belgelenip sonra risklerin tanımlanmasının daha doğru olduğunu belirtti. İş tahmini, işin ne kadar iş gücü gerektirdiğidir; kaynakların atanması işe eleman atamayı da kapsar ve ardından seviyelendirme yapılır. İş listesi kilometre taşlarıyla ve müşteri gereksinimleriyle eşleştirilir.

"Genel proje planının hazırlanması" listede tek bir maddedir, ama proje planında neler olduğu ve planı yapmak için hangi işlerin yapıldığı ayrıca önemlidir; bunlar sonraki derslerde ayrıntılı görülecektir. Yazılım proje planı belgesinin nasıl yazılacağı, hangi alt başlıklardan oluşacağı IEEE yazılım standartlarında verilmektedir. Planlama araçlarından MS Project'in kullanımı da ilerleyen derslerde uygulamalı olarak gösterilecektir.

### 8.4 Projeyi çalıştırma: izleme ve kontrol

Çalıştırma aşaması PMI'ın adımlarında "running the project" değil "tracking", yani projenin izlenmesi ve kontrol edilmesidir. Ekrandaki sorular (ekrandan, 01:55:00):

- Etkin bir ekip kuruyor muyum?
- Zaman planı, tahmin ve bütçe karşısında nerede durduğumu biliyor muyum?
- Riskleri yönetiyor muyum?
- Zaman planı sorunlarını çözüyor muyum?
- Kapsam değişikliği isteklerini yönetiyor muyum?
- Kaliteyi yönetiyor muyum?
- Gerektiğinde ayrıntıya iniyor (micromanaging), gerekmediğinde inmiyor muyum?
- Alt yüklenicilerim taahhütlerini yerine getiriyor mu?
- Müşterinin beklentilerini anlıyor ve karşılayabiliyor muyum?
- Düzenli ekip toplantıları yapıyor muyum ve bunlar etkin mi?
- Proje durumunu ve açık konuları düzenli raporluyor muyum?
- İlerlemeyi kendi içimde değerlendirmeye zaman ayırıyor muyum?
- Ekibimle başarılarımızı kutluyor muyuz?

Hoca bu soruları şöyle açtı. Tahminlerle gerçekleşenler her aşamada, yani her kilometre taşında (milestone) karşılaştırılmalıdır: proje plana uygun gidiyor mu, bütçe ya da zaman aşıldı mı, aşıldıysa B planı ne olacak? Kapsam değişiklikleri her zaman olacaktır, proje bittikten sonra bile. Daha planlama aşamasında bile müşteriden "şunu da istiyoruz", "bu böyle olmayacaktı", "yanlış anlatılmış" gibi istekler gelir; bunların yönetilmesi gerekir.

Alt yükleniciler (subcontractor) yazılım geliştirmede de artık çok kullanılır; örneğin içerik yönetimi başka bir firmaya verilebilir. Onlarla iletişim, sözlerini yerine getirmeleri ve teslimlerini zamanında yapmaları için kontrol önemlidir. Müşteri beklentileri sürekli takip edilmelidir; çevik yöntemlerde müşteri zaten sürecin içinde tutulur. Ekip toplantılarının düzgün ve etkin yapılıp yapılmadığı, durum raporlarının düzgün verilip verilmediği ve ilerlemelerin zamanında kaydedilip kaydedilmediği izlenir.

### 8.5 Projeyi kapatma

Kitap kapatmayı "başarıları ekip olarak kutluyor muyuz?" sorusuyla çalıştırma aşamasının sonuna koymuştur. Hoca ise kapatmayı ayrı bir madde olarak ele alacağını söyledi. Kapatma yalnız başarıların kutlanması ya da başarısızlıklara üzülmek değildir, kayıt altına almaktır: projeden izlenimler, kazanımlar, ortaya çıkan sorunlara nasıl çözüm bulunduğu, risklerin nasıl takip edildiği kaydedilir. Bir başka önemli iş de elde edilen ürünün büyüklüğünün, satır sayısı ya da işlevsel büyüklük olarak, hesaplanmasıdır; bu büyüklük ölçümleri yazılım kalitesi dersinde görülmüştü. <!-- BELİRSİZ: altyazıda "kaç botluk bir şey" geçiyor; büyük olasılıkla "kaç satırlık" (LOC) kastediliyor. -->

> **Ek bilgi (derste anlatılmadı):** İşlevsel büyüklük ölçümü için en yaygın yöntem fonksiyon noktası (function point) analizidir; satır sayısı (LOC) ise programlama diline bağlı bir fiziksel büyüklük ölçüsüdür. Kapanışta ölçülen gerçek büyüklük, büyük olasılıkla sonraki projelerin efor tahminlerinde (ör. COCOMO gibi modellerde) geçmiş veri olarak kullanılır.

> **Hocanın vurgusu:** Bugün en çok bilinmesi gereken, proje planlamanın proje yönetiminin bir alt başlığı olduğudur. Planlamanın dışında projenin anlaşılması, tanımlanması, çalıştırılması (izlenmesi ve kontrolü) ve kapatılması da proje yönetimi adımlarıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:00:00): Donanım ek bellek ve ek disk kapasitesiyle yükseltiliyor, aynı anda işletim sisteminin yeni sürümü kuruluyor. Bu bir proje midir?

> **Cevap:** Kitaptaki kriter listesine (Exhibit 1.1) göre değerlendirilir: iki ya da daha fazla kriter, özellikle koordinasyon ya da risk içerenler, sağlanıyorsa iş proje olarak ele alınır (ekrandan, 01:05:00). Hoca, belirli dönemlerde yapılan donanım yükseltmelerinin ve yazılım kurulumlarının rutin işler olduğunu, proje olmadığını söyledi.

**Soru 2** (derste sözlü, 01:02:20 ve 02:06:32): Bir telekom şirketinin her ay faturaları hazırlayıp basması bir proje midir? Faturaya yeni bir amblem ya da alan eklenmesi bir proje midir?

> **Cevap (derste verildi):** Her ayki basım rutin bir iştir, proje değildir. Fatura formatındaki değişiklik ise bir sonraki basıma kadar bitmesi gereken, alt aktivitelere bölünen, her alt aktivitenin başlangıç ve bitiş süresi belli olan ve bir hedefe yönelik yeni bir iştir; bu nedenle projedir.

**Soru 3** (derste sözlü, 02:01:07): Projeyi anlama aşamasında "müşterinin önceliği" ile ne kastediliyor?

> **Cevap (derste verildi):** Bir öğrenci, bazı müşterilerin maliyeti en düşük tutmayı hedefleyebileceğini söyledi. Hoca bunu onaylayıp genelleştirdi: müşteri önceliği, proje başarı göstergelerinden (zaman, bütçe/iş gücü, kapsam, kalite) hangisinin müşteri için öncelikli olduğudur ve plan buna göre yapılır.

**Soru 4** (derste sözlü, 02:01:54): Bu dersteki dönem projelerinde öncelik nedir?

> **Cevap (derste verildi):** Sürenin aşılmamasıdır. Süreyi aşmamak için daha fazla iş gücü harcanabilir ya da bazı kısımlar daha kısa tutulabilir; önemli olan projeyi bitirmektir.

**Soru 5** (derste sözlü, 02:03:36): Proje nedir? Bir işe proje diyebilmek için hangi özellikler gerekir?

> **Cevap (derste verildi):** Öğrencilerden gelen cevaplar "geliştirilmek istenen sistem", "yapılması gereken iş", "en az iki kişiden oluşması", "bir probleme çözüm olması" ve "belirli bir sürede tamamlanması" oldu. Hoca, kişi sayısının listede olabilir maddelerden biri olduğunu ama zorunlu olmadığını (tek kişilik projeler de vardır) belirtti. Esas özellikler şunlardır: iş rutin olmamalı ve yeni bir şey içermeli; kesin bir başlangıç ve beklenen bir bitiş zamanı olmalı; alt aktivitelere bölünmeli ve her alt aktivitenin başlangıç ve bitiş süreleri belli olmalı; bir hedefi yerine getirmeli. Bittiğinde dışarıdan görünen somut bir ürün, bir hizmet ya da tamamlanmış bir sosyal olay ortaya çıkar (konferans düzenlemek, bir ürünün piyasaya çıkışı için pazarlama çalışması gibi).

## Dersin Toparlaması

Bu derste dersin izleyeceği temel kitap tanıtıldı ve proje yönetiminin temel kavramları kuruldu. Başarılı bir proje kapsam, bütçe ve zaman planı üçgeniyle ölçülür, ama kalite ve müşterinin beklediği faydanın gerçekleşmesi de başarının parçasıdır. Projeler en çok kapsam değişiklikleri, zayıf planlama ve teknoloji yüzünden başarısız olur; üst yönetimin desteği ise başarıyı en çok etkileyen etkendir. Proje; başı ve sonu belli, alt aktivitelere bölünen, bir hedefe yönelik ve yenilik içeren iştir. Rutin işler proje sayılmaz.

Proje yönetimi, planlamadan ibaret değildir: anlama, tanımlama, planlama, çalıştırma (izleme ve kontrol) ve kapatma olmak üzere beş adımdan oluşur ve her adım proje yönetimi yol haritasındaki sorularla bir kontrol listesi gibi takip edilir. Sonraki derslerde bu adımların her biri, özellikle proje planının içeriği ve planlama araçları ayrıntılı olarak ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
