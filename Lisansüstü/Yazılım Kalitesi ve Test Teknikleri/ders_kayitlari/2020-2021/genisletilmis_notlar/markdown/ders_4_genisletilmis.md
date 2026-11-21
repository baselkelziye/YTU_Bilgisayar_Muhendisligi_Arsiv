# Ders 4 Genişletilmiş Notu: SRS Belgesi (IEEE 830), Test Süreci Adımları ve Test Tipleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım gereksinim belirtimi (SRS) ve IEEE 830
- 2. Örnek bir SRS belgesi
- 3. Önceki derslerin tekrarı: kalite aktiviteleri, gözden geçirme ve inceleme
- 4. V modeli, doğrulama ve geçerleme
- 5. Birim testi
- 6. Bütünleme testi ve regresyon testi
- 7. Sistem testi
- 8. Onaylama testi ve kabul muayenesi
- 9. Test tipleri: kara kutu, saydam kutu, gri kutu
- 10. Saydam kutu teknikleri: temel yollar testi ve döngü testi
- 11. Kara kutu teknikleri: eşdeğerli bölümleme ve sınır değer analizi
- 12. Keşif testi, hata giderme ve hata düzeyleri
- Örnek Sorular

## 1. Yazılım gereksinim belirtimi (SRS) ve IEEE 830

Dersin ilk bölümü, gereksinim analizi sonunda hazırlanan belgenin, yani yazılım gereksinim belirtiminin (Software Requirements Specification, SRS) nasıl yazılacağına ayrılır. Yazılım mühendisliği dersinde görülen bu konu, farklı geçmişlerden gelen öğrenciler için IEEE 830 standardı üzerinden yeniden ele alınır. Hoca bu standardı aynı zamanda daha önce işlenen "standartlar" konusuna somut bir örnek olarak seçtiğini söyler: bir IEEE standardı, bir belgenin hangi içerikte olması ve nasıl verilmesi gerektiğini tanımlar.

### 1.1 Şablonun yapısı

Ekranda gösterilen IEEE 830 tabanlı şablonun içindekiler listesi şöyledir (ekrandan, 00:10:00):

- 1. Introduction (Giriş): 1.1 Purpose, 1.2 Document Conventions, 1.3 Intended Audience and Reading Suggestions, 1.4 Product Scope, 1.5 References
- 2. Overall Description (Genel Tanım): 2.1 Product Perspective, 2.2 Product Functions, 2.3 User Classes and Characteristics, 2.4 Operating Environment, 2.5 Design and Implementation Constraints, 2.6 User Documentation, 2.7 Assumptions and Dependencies
- 3. External Interface Requirements (Dış Arabirim Gereksinimleri): 3.1 User Interfaces, 3.2 Hardware Interfaces, 3.3 Software Interfaces, 3.4 Communications Interfaces
- 4. System Features (Sistem Özellikleri): 4.1 System Feature 1, 4.2 System Feature 2 (and so on)
- 5. Other Nonfunctional Requirements (Diğer İşlevsel Olmayan Gereksinimler): 5.1 Performance, 5.2 Safety, 5.3 Security Requirements, 5.4 Software Quality Attributes, 5.5 Business Rules
- 6. Other Requirements (Diğer Gereksinimler)
- Appendix A: Glossary, Appendix B: Analysis Models, Appendix C: To Be Determined List

İçindekiler listesinin hemen ardından bir sürüm geçmişi (Revision History) tablosu gelir; sütunları Name, Date, Reason For Changes ve Version'dır. Belgenin kaçıncı sürümü olduğu ve hangi önemli değişikliklerin yapıldığı en başta belirtilir.

### 1.2 Bölümlerin içeriği

Giriş bölümünde belgenin amacı, okuyucunun önceden bakması gereken belgeler, geliştirilen yazılımın hangi alanda olduğu (ürün kapsamı) ve belge hazırlanırken kullanılan kaynaklar verilir.

Genel tanımda yazılımın tam tanımı yapılır: ürün işlevleri nelerdir, hangi kullanıcı sınıfları için hazırlanmıştır ve bu kullanıcıların özellikleri nelerdir, nasıl bir ortamda çalışacaktır. Gereksinim analizinin ardından tasarım ve gerçekleştirme yapılacağı için, yazılım ve donanım açısından kısıtlar burada belirtilir. Kullanıcı belgelerinin hangi öğelerden oluşacağı ve varsa kabuller (2.7) de bu bölümdedir. Ardından kullanıcı, donanım ve yazılım arabirimleri gibi dış arabirim gereksinimleri gelir.

Sistem özellikleri bölümü işlevsel gereksinimlerin yeridir. Sistem modüllere bölünerek verilebilir ve gereksinimler "requirement 1, requirement 2" diye, sistem özellikleri de "sistem özelliği 1, sistem özelliği 2" diye ayrılarak sıralanır. Hoca örnek olarak bir öğrenci bilgi sistemini verir: böyle büyük bir yazılımda yeni gelen öğrenci kayıtlarının aktarılması bir modül, kayıtlı öğrencinin derse kaydı başka bir modül, transkript ve diğer belgelerin verilmesi başka bir alt sistemdir. Her alt sistemin işlevsel gereksinim tanımı bu bölümde verilir.

Beşinci bölümde işlevsel olmayan (non-functional) gereksinimler sıralanır: performans gereksinimleri, güvenlik gereksinimleri, kalite özellikleri gibi. Analiz modeline ait açıklamalar (örneğin use case diyagramları) eklerde verilebilir.

## 2. Örnek bir SRS belgesi

Standardın ardından basit bir yazılım için hazırlanmış örnek bir SRS belgesi gösterilir. Belge bir üniversitenin mezunlar sayfası (alumni) uygulaması içindir ve IEEE 830'un sadeleştirilmiş bir uygulamasıdır. Hoca bu belgenin, derste beklenen gereksinim belgesinin biçimine iyi bir örnek olduğunu söyler.

### 2.1 İşlevsel gereksinimlerin use case ile verilmesi

Örnek belgede işlevsel gereksinimler, numaralı bir liste yerine use case belgeleriyle verilmiştir. Uygulamanın her alt modülü için ayrı bir use case tablosu hazırlanmıştır: yeni kayıt oluşturma (4.3.3 Create a new entry), kayıt güncelleme (4.3.4 Update an Entry) ve mezun arama ile e-posta gönderme (4.3.5 Search for an Alumni/E-mail an Alumni) (ekrandan, 00:20:00 ve 00:25:00). Her tablo şu alanlardan oluşur:

- Use Case Name
- Brief Description
- Priority (ör. Essential, If time permits)
- Trigger
- Precondition
- Basic Path (numaralı adımlar; örneğin yeni kayıtta 8 adım)
- Alternate Path
- Post condition
- Exception Path (ör. bağlantının form gönderilmeden önce ya da sonra kesilmesi durumları)

Hoca iki yolun da geçerli olduğunu vurgular: işlevsel gereksinimler numaralanarak madde madde sıralanabilir ya da her alt modül için ayrı bir use case belgesi hazırlanabilir. Use case belgelerinde ayrıca hangi aktörlerin hangi işleri yaptığı gibi alt başlıklara da bölünebilir.

### 2.2 İşlevsel olmayan gereksinimler

Örnek belgenin beşinci bölümü işlevsel olmayan gereksinimlerdir ve bunlar madde yerine bir iki cümlelik açıklamalarla yazılmıştır (ekrandan, 00:20:00):

- 5.1 User Interface Requirements: arayüz kullanıcı dostu, sezgisel ve kullanımı kolay olmalı, ergonomi standartlarına uymalıdır.
- 5.2 Performance Requirements: sistem gerçek zamanlı çalışmalı; kayıtlı bilgi üzerindeki bir işlem 10 saniyeden kısa sürede tamamlanmalı; sistem en az 100 eşzamanlı kullanıcıya veri bozulmadan izin vermelidir.
- 5.3 Availability & Reliability: sistem kayıtlı bilgilerin otomatik yedeğini oluşturabilmeli, yetkili kullanıcılar veriyi yedekten geri yükleyebilmelidir.
- 5.4 Security Requirements: bazı özellikler için ad ve parola ile kimlik doğrulama; kullanıcı belirli bir süre (ör. 30 dakika) işlem yapmazsa otomatik çıkış; veri tabanının bulunduğu bilgisayarlara fiziksel erişimin yetkili personelle sınırlanması.

Hoca burada da maddeleyerek ya da açıklayarak yazmanın ikisinin de kabul edilebilir olduğunu söyler.

### 2.3 Büyük yazılımlarda kapsam ve gereksinim belgesinin rolü

Seçilen yazılım çok büyükse, bütün sistemin gereksinim belgesini hazırlamak verimli olmaz. Bu durumda üzerinde test yapılacak modül ya da bölüm belirtilir ve gereksinim analizi o bölüm için hazırlanır.

Gereksinim belgesinin önemi test aşamasında ortaya çıkar: kullanıcı kabul testi yapılırken yazılımın neyle karşılaştırılacağı, neye bakılarak test edileceği bu belgedir. Bu nedenle gereksinimlerin, kabul testinde karşılaştırma yapılabilecek biçimde listelenmesi gerekir.

## 3. Önceki derslerin tekrarı: kalite aktiviteleri, gözden geçirme ve inceleme

### 3.1 Kalite aktiviteleri ve standartlar

İlk derslerden bu yana yazılım kalitesi özellikleri, McCall'un kalite özellikleri üçgeni, kalite faktörlerinin sınıflanması ve McCall'un bu faktörleri metriklerle ilişkilendiren modeli görülmüştü. Ardından kaliteli yazılım elde etmek için hangi aktivitelerin yapılması gerektiği ele alınmıştı.

Bu aktivitelerden biri standart kullanmaktır. Hoca daha önce kurduğu cümleyi hatırlatır: kullandığımız yazılım standartları, yazılım ürününü nasıl ve hangi süreçle elde ettiğimizi gösteren standartlardır; süreçte yapılan işlemleri ve bunların sonunda hazırlanan belgeleri tanımlarlar. IEEE 830 bu açıdan bir belge standardı örneğidir. Standart kullanmak yazılımın belli bir formal yapı içinde geliştirilmesini sağlar. Formal bir yazılım geliştirme süreç modeli seçmek de önemlidir. Bu ikisi, yani hangi süreç modelinin seçileceği ve hangi standarda göre geliştirileceği, yazılıma başlamadan önce verilen kararlardır.

### 3.2 Gözden geçirme

Geliştirme sürecinde yapılması gereken bir sonraki aktivite gözden geçirme ve incelemedir. Gözden geçirme yazılımın her evresinde, proje yönetiminde kilometre taşı (milestone) olarak belirlenen önemli evrelerin sonunda yapılır. Örneğin kodlama sonunda yazılım hataları, kodlama standartlarına uygunluk ve açıklamaların tutarlı ve uygun olup olmadığı gözden geçirilir.

Gözden geçirme standartlarına örnekler (ekrandan, 00:35:00):

- SDR: System Design Review (Sistem Tasarım Değerlendirme)
- SSR: Software Specification Review
- PDR: Preliminary Design Review (Ön Tasarım)
- TRR: Test Readiness Review (Sınama İşlerine Hazır Olmanın Değerlendirilmesi)

Hoca ayrıca yazılım test raporunun değerlendirilmesi için kullanılan bir kontrol listesinden (checklist) söz eder.

### 3.3 İnceleme (inspection)

İnceleme, gözden geçirmenin daha kurallı olan bir çeşididir. Slayttaki tanıma göre yazılım incelemesi, test yöntemiyle birlikte yazılım kalitesini sağlamak için en çok kullanılan yöntemdir; test yönteminin aksine hataları kodları çalıştırmadan tespit etme esasına dayanır (ekrandan, 00:30:00). İnceleme gereksinim spesifikasyonu, mimari tasarım, formal spesifikasyon, ayrıntılı tasarım ve program üzerinde yapılabilir.

Genel inceleme süreci planlama ve hazırlık, inceleme ve toplanma, düzeltme ve tamamlama, gerekirse yeniden inceleme ya da bitirme adımlarından oluşur. Fagan bunun daha ayrıntılı bir biçimini tanımlamıştır: önce planlama yapılır; plana göre neyin inceleneceğine genel hatlarıyla bakılır; iş kişilere bölünür ve herkes kendi kişisel incelemesini yapar; herkes incelemiş olarak toplantıya gelir, incelediği her bölüm için görüş bildirir ve karar verilir; ardından yazılım geliştiricilere düzeltme için gönderilir; en son tamamlama ve raporlama yapılır. Hoca bunun uzun süredir çok kullanılan bir süreç yapısı olduğunu ve en çok kod okuma ve kod inceleme aşamasında uygulandığını söyler.

> **Ders sonrası not:** Slaytta süreç "İnceleme (inspection) Süreci, Fagan (1986)" başlığıyla verilmiştir (ekrandan, 00:40:00). Fagan'ın inceleme yöntemini ilk tanımladığı makale büyük olasılıkla 1976 tarihlidir; 1986 tarihi büyük olasılıkla yöntemin geliştirilmiş hâlini anlatan sonraki makaleye aittir.

Slayttaki kod okuma ilkeleri şöyledir (ekrandan, 00:40:00): etkili bir kod okuma tekniği hem yukarıdan aşağıya hem de aşağıdan yukarıya incelemenin birleşimi olmalıdır. Program mümkün olan en küçük parçalara (örneğin fonksiyon, prosedür, alt program) ayrılarak önce bu parçaların kendi içindeki bütünlüğü ve doğruluğu, sonra programın bütünü ile uyumu incelenmelidir. İnceleme ekibi inceleme sorumlusu, inceleyiciler, yazar, kod okuyucu ve kayıtçıdan oluşur. Küçük projelerde bir kişi birden fazla görev üstlenebilir, büyük projelerde daha çok kişi yer alabilir.

Teknik inceleme raporunda neyin ve kimin tarafından gözden geçirildiği, hangi hata ve eksiklerin bulunduğu ve ne yapılması gerektiği açıklanır. Sonuç olarak üç karardan biri verilir:

- Değişiklik yapılmadan kabul edilebilir.
- Belirtilen önemsiz hatalar düzeltilmek koşuluyla kabul edilir.
- Reddedilir; düzeltme sonunda yeniden inceleme gerekir.

## 4. V modeli, doğrulama ve geçerleme

V modeli, yazılım geliştirme süreci ile yazılım test süreci arasındaki ilişkiyi gösterir. Model aynı zamanda test sürecinin adımlarını ve bu adımların sırasını verir; her geliştirme adımı ile ona karşılık gelen test adımı arasında doğrulama mı (verification) geçerleme mi (validation) yapıldığını da belirtir.

Geliştirme tarafında müşteri gereksinimleri alınır ve ürün spesifikasyonu oluşturulur (gereksinim analizi), ardından genel (yüksek düzey) tasarım, ayrıntılı (alçak düzey) tasarım ve kodlama gelir. Kodlamayı yapan yazılım geliştiriciler, geliştirdikleri kodun birim (ünite) testini de yapar. Bileşen yaklaşımı kullanılmışsa bileşen testi yapılır; ardından bütünleme testi ve onun hemen üzerinde regresyon testi, sonra sistem testi gelir. Kabul testi (alfa ve beta testi) bunların en üstündedir ve işlemsel kullanıma geçiş bundan sonra olur. Hoca kendi çizdiği şekilde kabul testinin yanlış yerde, sistem testinin yanında durduğunu, daha yukarıda olması gerektiğini belirtir.

### 4.1 Doğrulama ve geçerleme ayrımı

Hoca kavramları önce karıştırıp hemen düzeltir: verification doğrulama, validation geçerlemedir.

- Geçerleme (validation) "Doğru ürünü ürettik mi?" sorusuna cevap verir. Ürünü doğrudan test etmek geçerlemedir.
- Doğrulama (verification) "Ürünü doğru yolla ürettik mi?" sorusuna cevap verir. Geliştirme yolu üzerinde inceleme yapmak doğrulamadır.

İnceleme (inspection) aşamasında statik doğrulama (static verification) yapılır. Test ise programı çalıştırarak yapıldığı için dinamik doğrulamadır.

> **Hocanın vurgusu:** Validation ile verification ayrımı ve incelemenin statik, testin dinamik doğrulama olduğu ders boyunca birkaç kez sorulur.

## 5. Birim testi

Birim testi test sürecinin ilk adımıdır. Slayttaki tanıma göre ünite (birim) testi, yazılım tasarımının en küçük birimi olan modül üzerinde uygulanır; ayrıntılı tasarım tanımlarına dayanılarak modül içindeki hataları bulmak için önemli kontrol yolları sınanır (ekrandan, 00:45:00). Genellikle saydam kutu testi olarak uygulanır ve çok sayıdaki modül üzerinde paralel yürütülür: bütün modüllerin bitmesi beklenmez, her modül geliştirildikçe testi yapılır. Birim testinde modülün arabirimi, yerel veri yapısı, kontrol yapıları arasındaki ana yollar, hata arama yolları ve modül sınırları sınanır.

### 5.1 Birim test ortamı: test sürücüsü ve koçan

Şekil 5.2 Birim Test Ortamı'nda test programı, test sürücüsüne veri verir; test sürücüsü test edilen birimi çalıştırır ve sonuçları alır. Test edilen birimin altında Koçan 1, Koçan 2, ..., Koçan n bulunur (ekrandan, 00:50:00).

Bir modül çoğu zaman bağımsız çalışmaz; başka bir modül tarafından çağrılır ve başka modülleri çağırır. Bu yüzden:

- Test sürücüsü (test driver), test edilen modülü çağıran modülün yerini tutar; parametre geçişini ve modüle veri girişini sağlar, sonuçlar da onun üzerinden aktarılır.
- Koçan (stub), test edilen modülün çağırdığı ama henüz test edilmemiş modüllerin yerine konan yapay (dummy) modüldür.

### 5.2 Test senaryosu

Slayttaki tanıma göre test senaryosu (test case), belirli bir program yolunu işlemek ya da özel bir gereksinime uygunluğu onaylamak amacıyla düzenlenen bir dizi sınama verisinden ve buna ilişkin işlemlerden oluşur (ekrandan, 01:05:00). Test sayısı arttıkça maliyet artacağı için test senaryoları uygun seçilmeli ve testlerin uygun dağılmasına özen gösterilmelidir. Test programlarının geliştirilmesi diğer yazılımlar gibidir; geliştirmeye test planı uyarınca ve yazılım tasarımı ile birlikte başlanmalıdır. Modül bağımsız değilse sınamada diğer modüller de dikkate alınmalı ve her ünite testi için bir test sürücüsü ve/veya koçan yazılımı geliştirilmelidir. Test programları geliştirilirken destek araçlar (tool) kullanılır.

## 6. Bütünleme testi ve regresyon testi

### 6.1 Arabirim testi

Modüller bağımsız değildir, birbirine bağlıdır ve bu bağlantı yazılım arabirimiyle sağlanır. Bu yüzden arabirim testi ve bütünleme testi yapılır. Arabirim testi şeklinde bir test senaryosu A, B ve C modüllerinden oluşan yapıya veri gönderir ve sonucu geri alır; A ile B arasında iki yönlü, A ve B'den C'ye doğru veri ya da kontrol geçişleri vardır (ekrandan, 01:10:00). Uygun test verisi gönderilerek bu geçişlerin doğru çalıştığı sınanır.

### 6.2 Bütünleme testinde aranan sorunlar

Bütünleme testinde şu sorulara bakılır:

- Modüllerin birleştirilmesi sırasında veri kaybı oluyor mu?
- Dikkatsizlik nedeniyle modüller birbirini ters etkiliyor mu?
- Ana fonksiyonun gerçekleştirilmesinde sorun çıkıyor mu?
- Her modülde kabul edilebilir olan hata toleransları birleşince büyük hatalara yol açıyor mu? Gerekirse bu toleranslar yeniden gözden geçirilir.

Kısacası tek tek çalışan modüllerin birleştirildiğinde nasıl çalıştığı bütünleme testinde görülür.

### 6.3 Bütünleme stratejileri

Bütün modüller bir kerede birleştirilip test edilebilir (big bang). Rastgele modülleri seçip birleştirmek mümkündür ama daha zordur; bir hiyerarşi ve düzen içinde test etmek en iyisidir. Bu nedenle bütünleme testi artırmalı (incremental) yapılır: modüller tek tek birbirine bağlanır. Bağlama yukarıdan aşağıya ya da aşağıdan yukarıya olabilir.

Şekil 5.5 Aşağıdan Yukarı Bütünleme Testi'nde on modül vardır (ekrandan, 01:15:00):

- BU1: Module 1, Module 7'ye bağlanır.
- BU2: Module 2, Module 3 ve Module 4, Module 8'e bağlanır.
- BU3: Module 5 ve Module 6, Module 9'a bağlanır.
- BU4: Module 7, 8 ve 9, en üstteki Module 10 ile birleşir.

Hocanın anlatımına göre başta 7, 8 ve 9 numaralı modüllerin yerini test sürücüleri (yapay modüller) tutar. Module 1 test edilip 7'ye eklenir; 2, 3 ve 4 test edilip 8'in yerine konularak, 5 ve 6 test edilip 9'un yerine konularak çalıştırılır ve böylece yukarıya doğru ilerlenir. Hoca amaç modülleri bir arada birleştirerek bütünü test etmek olduğu için aşağıdan yukarıya bütünlemenin daha uygun olduğunu söyler.

<!-- BELİRSİZ: 01:12:18-01:14:14 arasında hoca anlatıma "yukarıdan aşağıya" diye başlayıp aşağıdan yukarı şeklini anlatıyor ve okları "aşağı doğru hatalı çizdiğini" söylüyor; karede oklar alttaki modülden üsttekine doğru. Hangi şeklin kastedildiği tam anlaşılmıyor. -->

Aşağıdan yukarıya birleştirirken büyük resmi kaçırmamak için üstteki büyük modüle de bakarak ilerlenir. İki yönün karma uygulandığı bu teste sandviç test (sandwich testing) denir.

### 6.4 Regresyon testi

Regresyon testi bütünleme testiyle ilişkilidir. Test edilmiş bir program ya da program parçası üzerinde değişiklik veya ekleme yapıldığında tümünün bir kez daha test edilmesidir. Uygulama ortamında gerekli değişiklikler ve sabitlemeler yapıldıktan sonra yeniden yapılan testler de regresyon testidir. Tanım olarak regresyon testi, önceden test edilmiş bir yazılımın çeşitli değişikliklerden geçtikten sonra hatasız çalışmasını sağlamak amacıyla yeniden test edilmesidir. Bu yüzden V modelinde bütünleme testinin tamamlayıcısı olarak hemen onun üzerine çizilir.

## 7. Sistem testi

Uygulama yazılımı kendi başına çalışmaz; altında işletim sistemi, onun altında donanım vardır. Yazılım hem donanıma hem işletim sistemine bağlıdır. Bütünleme testinden sonra uygulama yazılımı kendi içinde düzgün çalışıyor olabilir; sistem testi ise sistemin bütün öğelerinin uygun biçimde bir araya gelip gelmediğini ve her birinin işlevini tam gerçekleştirip gerçekleştirmediğini onaylar: uygulama işletim sistemiyle, veri tabanı yönetim sistemiyle ve donanımla uyumlu mu?

Sistem testi şu testlerle uygulanır:

- Güvenlik testi: sistem dış ortamdaki tehditlere karşı korunabiliyor mu, uygulama yazılımı sistem yazılımının bu konudaki servisleriyle uyumlu çalışıyor mu?
- Dayanıklılık (stres) testi: sistem miktar, frekans ya da hacim bakımından anormal şekilde yüklendiğinde dayanabiliyor mu? Hocanın örneği: 140 kullanıcılık denen bir sistem, 139-140 kullanıcıyla çalıştırılıp hepsi istek gönderdiğinde cevap verebiliyor mu, yoksa çöküyor mu? Veri tabanındaki kayıt sayısı arttığında aynı hizmeti verebiliyor mu?
- Yetenek (performans) testi: yazılımın işlem süresinin uygunluğunu, bellek ve işlemci performansını sınar. Birim düzeyinde de uygulanabilir; sistem testinde ise bütünleme testinden sonra bütün uygulama için yapılır.

### 7.1 Performans testi ayrıntıları

Performans testinde performans seviyeleri belirlenir, belirli bir yük altında sistemin çalışma zamanı performansı ölçülür ve sistem ayarları (tuning) değerlendirilir. Şu sorulara cevap aranır:

- İşlevsel olmayan gereksinimler karşılanıyor mu?
- Normal şartlar altında sistem nasıl davranıyor?
- Sistem trafiğindeki artışlar işlem süresini nasıl etkiliyor?
- Hangi kullanıcı seviyesinde performans sorunları başlıyor?
- Performans düşüşü sistemin hangi bileşeninden kaynaklanıyor?

## 8. Onaylama testi ve kabul muayenesi

Slayttaki tanıma göre bütünleme testi sonunda yazılım bir paket hâlinde derlenmiş, arabirim hataları bulunmuş ve düzeltilmiştir. Bundan sonra onaylama testi yapılır; bu testte yazılımın müşteri ve kullanıcı beklentilerini gerçekleştirme olanağı denetlenir. Bu amaçla onaylama testi, düzenlik testi ve kabul muayenesi olarak yürütülür (ekrandan, 01:20:00).

### 8.1 Müşteri ve kullanıcı

Müşteri ve kullanıcı çoğu zaman aynı anlamda kullanılır ama aralarında fark vardır. Müşteri, uygulamayı finanse eden ve onu kullanacak şirketin yöneticileridir. Son kullanıcı (end user) ise kurum içinde uygulamayı doğrudan kullanacak kişidir.

### 8.2 Alfa ve beta testi

Kullanıcı testi iki aşamalıdır. Önce yazılım ekibi içinde kullanıcılara benzer bir grup oluşturulur ve testi onların yapması istenir; buna alfa testi denir. Bu grup yardım menüsüne ve kullanıcı el kitaplarına yönlendirilir ve bunlara göre çalıştırdıklarında doğru sonuç alıp alamadıklarına bakılır. Daha sonra sistem potansiyel kullanıcılara açılır; onlar kullanır ve onaylar (beta testi).

### 8.3 Kabul muayenesi

Şekil 5.7 Onaylama testi'nde iki kol vardır (ekrandan, 01:25:00):

- Onaylama testi: girdileri bütünleşmiş yazılım, gereksinimler ve kullanıcı belgeleridir.
- Düzenin incelenmesi: girdileri kullanıcı belgeleri, tasarım belgeleri, kayıtlar ve test belgeleridir.

İki kol kabul muayenesinde birleşir ve oradan yazılımın teslimine gidilir. Kabul muayenesi (acceptance test), müşterinin kabul işlemini yapması ve sonunda yazılımı teslim almasıdır. Düzen (konfigürasyon) incelemesinde yazılımı oluşturan konfigürasyon öğelerinin, yani kullanıcı belgeleri, tasarım belgeleri, program ve test belgelerinin tam olup olmadığına, teslim edilecek denilenlerin teslim edilip edilmediğine bakılır. Onaylama testinde ise yazılım çalıştırılır ve gereksinim analizinde istenen her şeyi gerçekleştirdiği gösterilir.

Böylece test süreci adımları tamamlanmış olur: birim testi, bütünleme testi (ve regresyon), sistem testi, kullanıcı (kabul) testi.

## 9. Test tipleri: kara kutu, saydam kutu, gri kutu

Test sürecinin adımlarından sonra, bu adımlarda hangi test tiplerinin uygulandığı ele alınır.

Slayttaki tanıma göre işlevsel-performans ve dayanıklılık testleri sistemin dış spesifikasyonlarına ve gereksinimlerine dayandırıldığı için kara kutu testi (black box testing) adını alır (ekrandan, 01:30:00). Kara kutu testinde sistemin iç yapısıyla ilgilenilmez; verilen gereksinimler sağlanıyor mu, yapılan iş istenen iş mi ve istenen performansta mı, ona bakılır. Kullanıcı testi ve sistem testinde ağırlıklı olarak kara kutu testi uygulanır.

Buna karşılık yapısal denetimde, modül düzeyinde ve bazen modüller arası bütünleme çalışmalarında program deyimleri, veri akış yolları ve kontrol akış yolları sınanarak iç yapı incelenir. Buna saydam kutu testi (white box, glass box testing) denir. Her ikisinden bazı özellikler taşıyan teste de gri kutu testi (grey box testing) denir: bazı yönleriyle kara kutu, bazı yönleriyle saydam kutu testidir.

### 9.1 Saydam kutu testi

Slayttaki tanıma göre saydam kutu testinde işlemsel (procedural) tasarımın kontrol yapısı kullanılır ve bu test ile (ekrandan, 01:35:00):

- Bir modüldeki bütün bağımsız yolların en az bir kez çalışacağı garanti edilir.
- Bütün mantıksal kararların "doğru" ve "yanlış" durumları denenmiş olur.
- Bütün döngülerin kendi içinde ve çevresinde işlerliği sağlanır.
- İç veri yapıları denenerek geçerliliği güvence altına alınır.
- Uygulamada temel yol testi ve döngü testi teknikleri kullanılır.

## 10. Saydam kutu teknikleri: temel yollar testi ve döngü testi

> **Hocanın vurgusu:** "Temel yollar testi eşittir saydam kutu" denmemeli; temel yol testi bir tür saydam kutu testidir. Döngü testi de bir saydam kutu testidir, çünkü ikisi de iç yapıyı değerlendirmek için hazırlanır. İkisinden biri seçilmez, ikisi birlikte uygulanır.

### 10.1 Temel yollar testi (basis path testing)

Slayttaki tanıma göre temel yollar testi, işlemsel tasarımın mantıksal karmaşıklığını ölçmek ve bu ölçüye göre uygulama yolları için bir temel grup oluşturmak esasına dayanır; test programları, test sırasında programdaki her deyimi en az bir kez uygulayarak dener (ekrandan, 01:40:00). Uygulama şu basamaklarla yürütülür:

- Ayrıntılı tasarım veya kaynak programa dayanarak bir akış grafı çizilir.
- Akış grafı üzerinde döngüsel karmaşıklık (cyclomatic complexity, McCabe) ölçüsü saptanır.
- Doğrusal bağımsız yolların temel grubu ve düğümler belirlenir.
- Temel grubun içerdiği her yolun denenmesi için birer test programı düzenlenir.
- Her test programı uygulanır ve beklenen sonuçla karşılaştırılır.

McCabe ölçüsünün düğümler ve kenarlardan nasıl hesaplandığı bir sonraki derste (yazılım ölçümü) görülecektir. Buradaki hedef, programın iç yapısındaki kontrol deyimlerini izleyerek kaç tane program akışı olduğunu bulmaktır. Basit programlarda bu, akış diyagramını izleyerek de bulunabilir; karmaşık programlarda bütün kontrol akışlarının bulunup bulunmadığını denetlemek için ölçü kullanılır. Döngüsel karmaşıklık değeri programdaki bağımsız kontrol akışı sayısına eşittir ve en az bu sayı kadar test senaryosu (test case 1, test case 2, ...) hazırlanır. Her yol için en az bir test verisi olmalıdır; daha fazlası da hazırlanabilir, ama test sayısının ne kadar artırılabileceği maliyetle sınırlıdır.

**Soru:** Bir programda çok sayıda kontrol yapısı (for, while, if) varsa yol sayısı çok artmaz mı, her yol için test verisi hazırlamak maliyeti çok yükseltmez mi? **Cevap:** Denenmemiş her yol bir risktir; tam test yapıldı diyebilmek için her yolun denenmesi gerekir. Hocanın örneği: ikinci dereceden denklemin köklerini bulan program deltaya göre üç farklı yoldan gider. İki yol çalıştırılıp doğru bulunur ama üçüncüsü denenmeden teslim edilirse, o yolda bir işlem hatası varsa iki veri grubuyla yapılan test bunu yakalayamaz. Ayrıca belirli sayıda test yapılabiliyorsa (hocanın örneğinde dört test, üç temel yol), yollar önceden belirlenmeden rastgele veri seçilirse test verileri hep aynı yola düşebilir ve diğer yollar hiç denenmez. Önce temel yolları belirlemek hata riskini azaltır; test edilmeden teslim edilen program teslimden sonra daha büyük sorunlar çıkarır.

### 10.2 Döngü testi

Slayttaki tanıma göre döngü testi bir saydam kutu testidir ve temel yollar analizine ek olarak yürütülür. Bir döngü içinde bir giriş ve bir çıkışlı olarak soyutlanmış yollar da birer döngü hâlinde ayrıca sınanır. Döngü testinin amacı döngü içindeki başlama hatalarının, indeksleme ve artırma hatalarının ve döngüyü sınırlama hatalarının bulunmasıdır. Test sonunda döngü yapısının geçerliliği onaylanmış olur (ekrandan, 01:45:00). Döngü girdisi, başlangıç değeri ve çıkış koşullarının hepsi sınanmalıdır.

Program döngüleri üç türlüdür:

- Basit döngüler: tekrarlar sırasındaki artışlar ve sonsuz döngü olasılığı araştırılır.
- İç içe (yuvalanmış) döngüler: içteki döngü ile dıştaki döngü karşılaştırılır.
- Birbirine bağlı döngüler: bir döngüden diğer döngünün içine kontrol akışı olup olmadığına bakılır.

Temel yollardaki her yolun ve döngü yapılarının test edilmesi, kod elde iken yapılan testlerdir. Birim testinde ağırlıklı olarak saydam kutu testi uygulanır; bütünleme testinde de birimler arası arabirimler ve genel veri yapıları test edilirken saydam kutu testi yapılabilir.

## 11. Kara kutu teknikleri: eşdeğerli bölümleme ve sınır değer analizi

### 11.1 Kara kutu testi

Kara kutu testinde yazılımın iç yapısı, algoritmanın nasıl kurulduğu ya da döngülerin nasıl yazıldığı önemli değildir ve görülmek istenmez. Programı dışarıdan kullanacak kişilerin bakış açısıyla yazılımın baştaki gereksinimlere uygun olup olmadığı kontrol edilir.

Slayttaki tanıma göre kara kutu testi, yazılımın bütünlenmesi sırasında uygulanan ve yazılım arabirimi üzerinde yapılan bir sınamadır. Bu sınama ile yazılım işlevlerinin yerine getirildiği, girdilerin kabul edildiği, çıktıların doğru olarak sağlandığı gösterilir. Kara kutu testinde mantıksal iç yapıdan çok temel sistem modeli denenmiş olur. Bu nedenle kara ve saydam kutu testleri birlikte uygulanarak yazılım arabiriminin geçerliliği onaylanır ve yazılımın iç işlerliğinin doğruluğu kısmen güvence altına alınır (ekrandan, 01:50:00).

Kara kutu test modelinde sisteme test verisi girdi olarak verilir; bunlar genellikle uygulamanın senaryolarına göre hazırlanır. Yalnız normal girdiler değil, anormal davranışa yol açabilecek girdiler de verilir ve sistemin buna karşı davranışı ölçülür. Kara kutu testiyle işlevsel gereksinimler denenir: programın bütün işlevsel gereksinimlerini denemek için bir dizi girdi ve durum oluşturulur, iç yapıdaki bütün kontrol deyimlerini deneme kaygısı yoktur. Bu test saydam kutunun alternatifi değil, tamamlayıcısıdır. Kara kutu testiyle arabirim hataları, veri yapılarında ve veri tabanı erişiminde hatalar ve performans hataları bulunur.

Başlıca kara kutu test yöntemleri şunlardır:

- Eşdeğerli bölümleme
- Sınır değer analizi
- Neden-sonuç grafı çizimi
- Veri onaylama testi

Derste bunlardan ilk ikisi ayrıntılı işlenir.

### 11.2 Eşdeğerli bölümleme (equivalence partitioning)

Saydam kutu testinde akış grafı üzerinden yollar sayılıp her biri test edilirken, kara kutu testinde senaryolara göre girdiler oluşturulur. Rastgele veri girildiğinde veriler hep aynı bölgeye düşebilir. Bu yüzden girdi alanı önce sınıflara bölünür ve her sınıftan değer seçilir; böylece daha az sayıda testle daha iyi sonuç alınır.

Slayttaki tanıma göre eşdeğerli bölümleme yönteminde programın girdi alanı, test programları oluşturulabilecek veri sınıflarına bölünür; böylece her test programı belirli sınıftaki hataları ortaya çıkarır ve daha az sayıda test programı ile yetinilir (ekrandan, 01:55:00).

Hocanın örneği 0 ile 99 arasında girilen bir yaş verisidir. Aralık 20'ye kadar, 21-40, 41-60 ve 60 üstü gibi sınıflara bölünür; her sınıftan bir değer alınıp çalıştırıldığında veri uzayı daha iyi değerlendirilmiş olur. Şekilde geçerli girdiler sınıflara bölünerek verilir; geçersiz girdiler de sonucu test etmek için ayrıca verilir ve çıktılar belirli sınıfların karşılığı olarak alınır.

> **Ders sonrası not:** Hoca son sınıfı "60 ve daha üstü" diye söyledi. 41-60 sınıfıyla çakışmaması için son sınıf 61-99 olmalıdır; 0-20, 21-40, 41-60 ve 61-99 sınıfları 0-99 aralığını çakışmasız kaplar (python ile kontrol edildi).

### 11.3 Sınır değer analizi (boundary value analysis)

Slayttaki tanıma göre sınır değer analizi, test verisinin girdi alanı (ya da çıktı serisi) sınıflarının, veri yapılarının, alt program parametrelerinin vb. sınırlarından veya uç değerlerinden seçilmesi tekniğidir (ekrandan, 02:00:00). Genellikle en büyük, en küçük ya da en az beklenen değerler ve parametreler seçilir. Hataların genel olarak merkezden çok kenarlarda toplandığı görülmüştür; bu yüzden sınır değerlerini denemeye yönelik test programları geliştirilmiştir. Bu programlar girdi alanında olduğu kadar çıktı alanında da uygulanır.

> **Ek bilgi (derste anlatılmadı):** Eşdeğerli bölümleme ile sınır değer analizi genellikle birlikte kullanılır: önce sınıflar belirlenir, sonra her sınıfın alt ve üst sınırları ile bunların hemen yanındaki değerler test verisi olarak seçilir.

## 12. Keşif testi, hata giderme ve hata düzeyleri

### 12.1 Keşif testi

Keşif testi, ürün spesifikasyonu ya da gereksinim belgesi olmadan yazılımı genel olarak çalıştırıp nasıl olduğuna, çalışıp çalışmadığına ve çok hata verip vermediğine bakarak genel bir değerlendirme yapmaktır. Slaytta bu başlık "keşif testi Smoke Test" olarak geçer (ekrandan, 02:05:00, slayt listesi).

> **Ders sonrası not:** İngilizce literatürde keşif testi büyük olasılıkla "exploratory testing" karşılığıdır; "smoke test" ise büyük olasılıkla yeni bir sürümün temel işlevlerinin çalışıp çalışmadığını hızlıca denetleyen ayrı bir test türünün adıdır. Slayttaki eşleştirme bu iki kavramı birlikte anmaktadır.

### 12.2 Hata giderme (debugging)

Test ile hatalar bulunur. Hata giderme (debug) aşamasında, sınama sonucunda saptanan hata ve eksiklerin nedeni bulunur ve düzeltilir.

Şekil 5.11 Yazılım Bug Nedenleri pasta grafiğinde nedenler gereksinim, tasarım, kod ve diğer olarak verilmiştir; en büyük dilim gereksinim, ardından tasarım, sonra kod ve diğer gelir (ekrandan, 02:05:00). Hoca bunun daha eski bir değerlendirme olduğunu, günümüzde gereksinim kaynaklı hataların azaldığını söyler ve bunun nedenini sorar (bkz. Örnek Sorular). Derste varılan sonuç: çevik (agile) süreç modelleri kullanıldığından beri gereksinim hataları azalmıştır. Bir neden, gereksinimlerin küçük parçalara bölünüp artımlı (incremental) süreçle gerçekleştirilmesidir (özellikle XP'de); şelale modelinde baştan tek bir gereksinim belgesi hazırlanır ve geliştirme sırasında gereksinimler değişir. Diğer neden, müşterinin ekibin bir parçası olmasıdır: müşteri isteklerini daha dinamik biçimde bildirir ve kontrol eder, ekip içinde çalıştığı için sorunlar şelale modeline göre daha hızlı giderilir.

### 12.3 Hata düzeyleri

Hata düzeyleri slaytta altı başlık olarak verilir: ölümcül, kritik, büyük, orta, küçük ve görünüm hataları (ekrandan, 02:10:00, slayt listesi). Bu sıralama ve adlar zorunlu değildir; yazılım ekibi hata sınıflaması için baştan kendi standardını oluşturup bütün programlarda ona göre sınıflama yapabilir. Dört düzeyli sınıflamalar da kullanılır.

Her düzeyde nasıl davranılacağı slaytta şöyle verilir (ekrandan, 02:10:00):

- Ölümcül hatalar testin devamını engeller; hata düzeltilmeden teste devam edilmez.
- Kritik hatada test devam eder, ama hata düzeltilmeden yazılım teslim edilmez.
- Büyük hata giderilmeden yazılımın teslimi zararlıdır.
- Orta hata ile testler devam edebilir; ürün bu hatayla teslim edildiğinde telafisi mümkün sorunlar çıkarabilir. Hoca bu durumda telafinin daha zor olabileceğini, çok acil durumlarda ürünün teslim edilip çözümün bir yandan aranabileceğini ekler.
- Küçük hata ile testler devam edebilir ve ürün bu hatayla da teslim edilebilir; yazılım için önemli bir sonuç doğurmaz.
- Görünüm hataları yazılımın renk, font ve büyüklükle ilgili hatalarıdır; bunlarla teslim yapılabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:36:25): İnceleme (inspection) nasıl bir doğrulamadır?

> **Cevap (derste verildi):** Statik doğrulamadır (static verification), çünkü kod çalıştırılmadan yapılır. Test ise programı çalıştırarak yapıldığı için dinamik doğrulamadır.

**Soru 2** (derste sözlü, 01:29:04): Kodlama aşaması bitmiş, her geliştirici kendi kodunu tamamlamış bir yazılım üzerinde hangi adımlarla test yapılır? Test süreci adımları nelerdir?

> **Cevap (derste verildi):** Birim testi, bütünleme testi, sistem testi ve kullanıcı (kabul) testi. Bir öğrencinin cevabındaki "validasyon" bir adım adı değildir: sistem testinde hem geçerleme hem doğrulama vardır, kullanıcı testi de bir geçerlemedir. Kara kutu, saydam kutu gibi kavramlar ise adım değil test tipidir.

**Soru 3** (derste sözlü, 01:59:13): Test tipi ve test süreci adımı nedir?

> **Cevap (derste verildi):** Test süreci adımları birim testiyle başlar, bütünleme testi, sistem testi ve kullanıcı kabul testiyle sürer. Test tipleri kara kutu, saydam kutu ve gri kutu testleridir. Saydam kutu testinde amaç yazılımın içeriğini, doğru algoritmanın kurulup kurulmadığını ve (temel yol testinde) bütün program akışlarının test edilip edilemediğini denetlemektir. Kara kutu testi kullanıcı tarafıyla ilgilidir; temel soru yazılımın işlevlerini yerine getirip getirmediğidir.

**Soru 4** (derste sözlü, 02:03:24): Eski verilerde bug nedenlerinin en büyük kısmı gereksinim hatalarıdır; çevik yöntemlerle bu hatalar azalmıştır. Çevik yöntemlerin hangi özelliği bu azalmaya yol açmıştır?

> **Cevap (derste verildi):** Gereksinimlerin küçük parçalara bölünüp artımlı (incremental) olarak gerçekleştirilmesi ve müşterinin ekibin bir parçası olarak isteklerini sürekli bildirip denetlemesi. Şelale modelinde ise baştan hazırlanan tek gereksinim belgesi geliştirme sırasında değişir.

## Dersin Toparlaması

Ders, gereksinim analizinin çıktısı olan SRS belgesiyle başladı: IEEE 830 şablonunun bölümleri ve bir örnek belgede işlevsel gereksinimlerin use case tablolarıyla, işlevsel olmayan gereksinimlerin kısa açıklamalarla nasıl verildiği gösterildi. Bu belge, kabul testinde yazılımın karşılaştırılacağı ölçüttür. Ardından kalite aktiviteleri, gözden geçirme, Fagan incelemesi ve V modeli tekrar edildi; doğrulama ile geçerleme ayrımı ve incelemenin statik, testin dinamik doğrulama olduğu vurgulandı.

Dersin ana kısmında test süreci adımları (birim, bütünleme ve regresyon, sistem, onaylama ve kabul) ile test tipleri (kara kutu, saydam kutu, gri kutu) birbirinden ayrıldı. Saydam kutu tarafında temel yollar testi ve döngü testi, kara kutu tarafında eşdeğerli bölümleme ve sınır değer analizi işlendi; son olarak keşif testi, hata giderme, bug nedenleri ve hata düzeyleri görüldü. Bir sonraki ders yazılım ölçümü ve ölçütleridir; temel yollar testinde kullanılan McCabe döngüsel karmaşıklığının nasıl hesaplandığı orada ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
