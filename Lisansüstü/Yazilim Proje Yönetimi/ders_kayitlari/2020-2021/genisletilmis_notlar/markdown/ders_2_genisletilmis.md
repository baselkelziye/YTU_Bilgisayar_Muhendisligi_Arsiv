# Ders 2 Genişletilmiş Notu: Proje Kavramı, Proje Başarısı ve Proje Yöneticisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Mühendisliği ve Proje Yönetiminin Yeri
- 2. Yazılım Proje Yönetiminin Üç Bileşeni
- 3. Etkin Proje Yönetimi: 3P
- 4. Ölçümün Yazılım Projelerindeki Rolü
- 5. Proje Nedir, Ne Değildir?
- 6. Proje Başarısı
- 7. Başarıyı Getiren Faktörler ve Kilometre Taşları
- 8. Proje Yöneticisi
- 9. Proje Temel Süreçleri
- 10. Proje Bilgi Alanları ve Yaşam Döngüleri
- 11. Başlama Süreci: Berat, Paydaşlar ve Organizasyon
- 12. Planlama Süreci
- 13. İş Kırılım Yapısı (WBS)
- 14. Zaman Yönetimi
- 15. Maliyet Yönetimi

## 1. Yazılım Mühendisliği ve Proje Yönetiminin Yeri

Hoca derse, geçen hafta hızlı geçtiği kavramları toparlayarak başladı. Yazılım mühendisliği dersi almamış olanları da düşünerek ilk soruyu şöyle koydu: Yazılım proje yönetimi, yazılım mühendisliği içinde nerede duruyor?

### 1.1 Yazılım Mühendisliğinin Tanımı

Üniversitelerde yazılım mühendisliği için genellikle iki kitap okutulur: Pressman'ın *Software Engineering* kitabı ve Sommerville'in yine çok kapsamlı olan *Software Engineering* kitabı. Her ikisinde de yazılım mühendisliğinin temel tanımını içeren bütün alt başlıklar yer alır.

> **Ders sonrası not:** Altyazıda "Ayn Summerville" ve "Presma" olarak geçen adlar büyük olasılıkla Ian Sommerville ve Roger Pressman'dır.

Hoca, çok sevdiği kısa bir tanımla devam etti:

> **Hocanın vurgusu:** Yazılım mühendisliği, kaliteli yazılımı en ekonomik olarak hazırlamak üzere mühendislik araçlarını ve yeteneklerini kullanan bilim dalıdır.

Bu tanımın değeri, kısa olmasının yanında yazılım mühendisliği kitaplarındaki alt bölümleri de ortaya çıkarmasıdır. Tanımın her parçası bir alt konuya karşılık gelir:

- **Kaliteli yazılım:** Yazılım kalite ve test. Bu bölüm bütün kitaplarda vardır ve ayrı bir ders olarak da okutulur.
- **En ekonomik olarak hazırlamak:** Yazılım proje yönetimi.
- **Mühendislik araçları ve yetenekleri:** Tasarım ve ölçüm.

### 1.2 Mühendislik Yetenekleri: Tasarım ve Ölçüm

Hoca normalde burada durup "Mühendislik dediğimizde hangi yetenekler öne çıkar?" diye sorduğunu, ama slaytta cevap yazılı olduğu için bu kez soramayacağını söyledi. Cevap iki kelimedir: tasarım ve ölçüm.

Tanımın bu parçası iki sonuç doğurur. Birincisi, geliştirme sürecinde mutlaka tasarım yapılması gerekir. İkincisi, hem yazılım proje yönetiminde hem de yazılım kalite ve testte ölçüm üzerinde durulur. Çünkü iki alanda da bir yönetim işi vardır ve ölçmek yönetme kavramıyla çok ilişkilidir. Yazılım ölçümü (software metrics) kitaplarından birkaçı ön sözlerine şu cümleyle başlar:

> **Hocanın vurgusu:** Ölçemediğinizi yönetemezsiniz. Ölçemediğiniz durumları idare etmeniz zordur.

Hoca, ölçüme yazılım proje yönetiminde nasıl yer verileceği ve hangi konularla ilişkilendirileceği üzerinde de duracağını söyledi. Bunu 4. bölümde yaptı.

### 1.3 "En Ekonomik" Ne Demektir?

Tanımdaki "en ekonomik" sözü yanlış anlaşılmaya açıktır. Amaç, istenen yazılımı herhangi bir şekilde elde etmek değildir. Ama amaç, onun en ucuz hâlini elde etmek de değildir. En ekonomik demek, fiyat ile etkinlik, yani fiyat ile verimlilik arasındaki dengenin sağlanması demektir. Proje yönetiminin görevi de bu dengeyi kurmaktır.

### 1.4 Yazılım Mühendisliği Kitaplarının Alt Başlıkları

Hoca, herkesin yazılım mühendisliği bilgilerini canlandırmak için bu kitaplardaki konuları sırayla hatırlattı:

- **Yazılımın kendisi:** Yazılım nedir, yazılım tipleri nelerdir? Yazılımın diğer ürünlerden farkı nedir? Yazılım, donanımdan ve diğer mühendislik alanlarının ürünlerinden farklı, "soft" bir üründür.
- **Yazılım geliştirme süreci (software development process) ve modelleri:** Başlangıç olarak herkesin bildiği şelale (waterfall) modeli, prototip modeli, spiral model, RAD modeli gibi klasik süreçler ve çevik (agile) süreçler altındaki modeller.
- **Süreç adımları:** Önce şelale modelindeki analiz, tasarım, gerçekleştirme ve test adımları ve bunların içinde yapılanlar öğrenilir.
- **Analiz ve tasarım araçları:** Tasarım için kullanılan diyagramlar ve tasarım dilleri, analiz için kullanılan modelleme dilleri. Bunları klasik yaklaşımla anlatan kitaplar da vardır, ama son zamanlarda çıkan kitapların hepsi nesneye yönelik yaklaşımla anlatır.
- **Yazılım kalitesi ve test teknikleri:** Test sürecin içindedir, ama kalite yönetimi kısmında ona ayrı bir yer verilir.
- **Yazılım proje yönetimi:** Konfigürasyon yönetimi gibi konular hem kalite yönetiminde hem proje yönetiminde iç içe geçmiştir, ikisiyle de ilişkilidir.

Sonuç olarak yazılım proje yönetimi, yazılım mühendisliği bilim dalının bir alt başlığıdır.

## 2. Yazılım Proje Yönetiminin Üç Bileşeni

Yazılım proje yönetimi üç alanın bileşkesi olarak görülür: yazılım mühendisliği teknikleri, proje yönetimi bilgi ve deneyimi, genel yönetim bilimi.

### 2.1 Yazılım Mühendisliği Teknikleri

Yazılım proje yönetiminde yazılım mühendisliğinin araçları ve teknikleri kullanılır. Karar verebilmek için yazılım geliştirme sürecindeki adımları iyi bilmek gerekir. Seçilecek yöntemleri ve fizibilite analizi sırasındaki teknoloji seçimlerini de bilmek gerekir.

### 2.2 Proje Yönetimi Bilgi ve Deneyimi

Bu bileşen yazılıma özgü değildir. Bir inşaat projesi de yürütülse, bir bilgi sistemi geliştirme projesi de yürütülse karşımıza çıkan teknikleri ve işlemleri kapsar. Her proje benzer bir adımlar silsilesi içinde yürür: Önce projenin başlatılması için gerekli işlemler ve belki genel bir fizibilite analizi, sonra projenin planlanması, projenin bu plan üzerinden takip edilmesi ve kapanış.

Planlamada önce projenin kabulleri, kısıtları ve riskleri ayrıştırılır. Bunları anlayabilmek için gerekli ön çalışmalar, projenin anlaşılması ve tanınması olan giriş aşamalarında yapılmış olmalıdır. Planlama aşamasında bilinmesi gereken üç şey vardır:

- Problemin kapsamı.
- Projenin kaynakları. Yazılım projelerinde en ağır basan kaynak insan kaynağıdır.
- Projenin gerektirdiği süre.

Bunları bilmek için yapılan işlerin hepsi proje yönetimi bilgi ve deneyimi kapsamındadır.

### 2.3 Genel Yönetim Bilimi

Proje yönetiminde adından da anlaşılacağı gibi bir yönetim işi vardır. Birinci yönetim konusu proje ekibidir. Ekibin iyi yönetilmesi için ekip organizasyonunun iyi kurulması gerekir. Bu da ekip üyelerinin seçimini ve ekip üyeleri arasındaki iletişimi ve iletişim yöntemlerini kapsar.

Yönetim kavramı ekip üyeleriyle sınırlı değildir. Şu ilişkiler de yönetim prosedürleri çerçevesinde yürür:

- **Üst yönetimle iletişim:** Projedeki iyi veya kötü kritik durumların bildirilme şekli ve isteklerde bulunulması.
- **Tedarikçilerle ilişkiler:** Projeye kaynak sağlayacak firmalarla iletişim ve malzeme tedarik işlemleri.
- **Alt yüklenicilerle ilişkiler:** Hocanın belirttiği gibi artık bütün işler tek bir firma tarafından yapılmıyor, alt yükleniciler çok kullanılıyor.

## 3. Etkin Proje Yönetimi: 3P

Pressman'ın kitabında etkin bir proje yönetimi için önemli kavramlar 3P olarak geçer: insan (people), problem (problem) ve süreç (process).

> **Ek bilgi (derste anlatılmadı):** Pressman'ın yeni baskılarında bu çerçeve büyük olasılıkla ürün (product) ve projeyi (project) de içeren 4P biçiminde geçer. Derste kullanılan biçim 3P'dir.

### 3.1 İnsan

İnsan kaynaklarında en ağırlıklı konular şunlardır:

- Çalışacak kişilerin seçimi.
- Çalışanların performanslarının yönetimi.
- Eğitim ve kariyerlerinin geliştirilmesi.
- Organizasyon ve iş tasarımının gerçekleştirilmesi.
- Ekip kültürünün geliştirilmesi.

### 3.2 Problem

Bir proje planlanmadan önce projenin bir giriş aşaması vardır. Bu aşama, projeyi anlama ve tanımlamadır. Burada şu sorular cevaplanır: Projenin amacı nedir? Projenin alanı nedir? Alternatif çözümler neler olmalıdır? Teknik ve yönetim kısıtları var mı? Proje planının ilk başında belirlenen kısıtlar, varsayımlar ve riskler de problemin içine girer.

### 3.3 Süreç

Süreç bileşeni, yazılım mühendisliği tekniklerinden alınan bilgidir. Bu teknikler bilindiğinde projede yapılacak işler konusunda daha geniş düşünülebilir. Hoca burada sınıfa bir soru yöneltti.

**Soru:** Yazılım geliştirme sürecinde esas işlemlerimiz nelerdir?

Bir öğrenci önce ihtiyaçların doğru belirlenmesi, bu ihtiyaçlara göre kaynakların belirlenmesi, maliyet ve süre hesabı, aşamaların kontrolü ve sorun varsa geri dönüp yeniden planlama yapılması diye cevap verdi.

**Cevap:** Hoca, sayılanların projenin başlangıcında yapılan işler için doğru olduğunu, ama sorusunu iyi anlatamadığını söyledi. Sorduğu şey yazılım geliştirme sürecinin esas işlemleriydi: analiz, tasarım, gerçekleştirme ve test.

Pressman'ın kitabında bu esas işlemleri destekleyen işlemlere destek aktiviteleri denir:

- Yazılım proje yönetimi.
- Kalite yönetimi.
- Değişiklik yönetimi veya onu da kapsayan konfigürasyon yönetimi.
- Yazılım ölçümü (software metrics).

Etkin proje yönetimi için bu süreci iyi tanımak ve sürecin hangi modele göre uygulandığını bilmek gerekir. Proje yöneticisi işini bunların hepsini bilerek yapıyorsa etkin bir proje yönetimi gerçekleştirebilir.

## 4. Ölçümün Yazılım Projelerindeki Rolü

Mühendislik yaklaşımı yönetme, maliyet hesabı, planlama, modelleme, analiz etme, tasarlama, gerçekleştirme ve bakım işlemlerini kapsar. Bu adımların hepsinde ölçme vardır.

### 4.1 Maliyet Tahmini İçin Geçmiş Proje Verisi

Hoca ölçümün yararını önce yönetme ve maliyet hesabı üzerinden anlattı. Bir proje kapatılırken şu bilgiler not alınır: Proje hangi büyüklükteydi, ne kadar maliyetle gerçekleştirildi, ne kapsamda bir problemdi? Bu bilgiler daha sonra kullanılabilecek şekilde geçmiş bilgi arşivine yerleştirilmişse bir veri tabanı oluşur.

Böyle bir veri tabanı varsa yeni başlayacak bir projede şu yol izlenir:

- Yeni projenin yaklaşık büyüklüğü belirlenir.
- Bu büyüklükteki bir projenin kaça mal olacağı veri tabanına bakılarak tahmin edilir.
- Tahmin daha destekli olduğu için kaynak planlaması da daha iyi yapılır.

Maliyet tahmin yöntemleri planlama aşamasında kullanılır. Hocaya göre yazılım mühendisliği alanında çalışanların büyük bir kısmı sayısal işlem gerektiren yazılım maliyet tahmin modellemesi üzerinde çalışmıştır. Bu konuda genel yöntemler kullanılabilir. Hocanın daha önce yönettiği bir çalışmada ise geçmiş projelerin veri tabanı kullanılarak yapay sinir ağları ile yeni başlanacak bir projenin maliyeti tahmin edilmiştir.

Ana fikir şudur: Bitmiş projelerin hepsinde ölçme yapılmış ve "bu proje şu büyüklükte, şu fiyata tamamlandı" bilgisi kaydedilmişse, planlama sırasında bu bilgi havuzuna bakılarak maliyet daha destekli tahmin edilebilir.

### 4.2 Modelleme, Analiz ve Tasarımda Ölçme

Ölçme yalnızca maliyet için kullanılmaz. Modelleme sırasında hangi modelin daha uygun olduğuna karar verirken geçmiş projelerde seçilen modelin başarısına ve bu ölçümlere bakılabilir. Analiz ve tasarım modelleri seçilirken de ölçümün faydası olur.

## 5. Proje Nedir, Ne Değildir?

Hoca buraya kadar etkin proje yönetiminin gereklerini ve yazılım proje yönetiminin hangi bilim dallarıyla iç içe geçtiğini anlattığını söyledi. Aradan sonra sıradaki sorulara geçti: Ne projedir, ne proje değildir? Bu bölümde PMI sertifikasına sahip bir proje yöneticisinin hazırladığı slaytları kullandı.

### 5.1 Projenin Özellikleri

Bir işe proje diyebilmek için şu özellikleri taşıması gerekir:

- **Başı ve sonu bellidir:** Bir başlangıç noktası ve bir bitiş noktası vardır. Slaytta bu, bir koşu gibi gösterilmiştir.
- **Belirlenmiş bir amacı vardır.**
- **Kapsamı tanımlıdır:** Kapsam, projeye başlamadan önce tanımlanmış olmalıdır. Bu tanım, projenin anlaşılması ve tanınması olan giriş aşamasında yapılır.
- **Belirli bir bütçesi vardır.**
- **Bir seferberlik girişimidir:** Proje bir ekip işidir. Ekipteki herkes, projeyi zamanında ve belirlenen bütçeyle bitirmek üzere bir hedefe uygun olarak birlikte çalışır.
- **Alt işlemleri vardır:** Hoca, slaytta belirtilmeyen bu özelliği kendisi ekledi.

### 5.2 Proje Örnekleri

Hocanın saydığı örnekler yazılımla sınırlı değildir:

- Yeni bir ilaç veya aşı geliştirilmesi.
- İki şirketin birleştirilmesi veya ayrılması. Bu, işletmecilik açısından bir projedir.
- Organizasyon içinde bir sürecin oluşturulması veya iyileştirilmesi. Örneğin bir kurumda muhasebe sisteminin iyileştirilmesi.
- Yeni bir ürünün gerçekleştirilmesi.
- Yeni bir donanımın edinilmesi ve kurulması.
- Yeni bir yazılım uygulamasının geliştirilmesi.
- Bir inşaat işi veya yol inşaatı.
- Bir doğal gaz araştırması.
- Bir fuarın hazırlanması. Slaytta Expo 2016 örneği verilmiştir: Başlangıcı ve bitişi bellidir.
- Marmaray'ın yapılışı. Başlangıç süresi, bitiş süresi ve hedefi vardır.
- Bir seçim çalışması.

Fuar ve seçim çalışmalarında en önemli unsur zamandır. Fuarın başlangıç tarihine kadar işler bitmiş olmalıdır. Seçim çalışmasında da partiler o tarihten sonra çalışmalarını istedikleri kadar iyileştirsinler, ne yapacaklarsa o süreye kadar yapmak zorundadırlar.

### 5.3 Rutin İş ile Proje Arasındaki Fark

Bu örneklerin hepsinde bir hedef vardır. Ayrıca işin rutin olmaması gerekir.

> **Hocanın vurgusu:** Her yaptığımız iş bir proje değildir.

Hoca bunu üç örnekle açıkladı:

- **Bordro:** Her ay bordro çıkarılması veya bir kurumun müşterilerine her ay ücret göndermesi rutin iştir. Bu bir iş yüküdür ama proje değildir. Bordroda yeni bir alan oluşturulması veya bordronun şeklinin değiştirilmesi ise bir yeniliktir ve projedir.
- **Fatura:** Slaytta Türksel faturalarının hazırlanması örneği vardır. Her dönem fatura hazırlamak rutindir. O aydan itibaren bir yenilik veya ekleme getirilecekse bu bir proje olarak karşımıza çıkar.
- **Ödev ve proje:** Gantt diyagramının nasıl çizildiğini öğrettikten sonra "Bir örnek üzerinde Gantt diyagramı çizin" demek, tek bir derste yapılanı uygulatan bir ödevdir. "Daha önce yaptığınız bir yazılımın proje planını hazırlayın ve takibi için gerekli işlemleri yapın" demek ise projedir. Çünkü içinde birkaç alt adım ve yeni bir uygulama vardır.

> **Ders sonrası not:** Altyazıda "Türksel" olarak geçen ad büyük olasılıkla Turkcell'dir.

İş hayatındaki işler arasında proje olanlar ve rutin olanlar da aynı şekilde ayrılır.

### 5.4 Proje Nasıl Biter?

Bir proje üç şekilde biter:

- Proje hedeflerine ulaşmıştır.
- Proje hedeflerine ulaşamamış ve bu yüzden sonlandırılmıştır.
- Projenin ihtiyacı, proje geliştirilene kadar ortadan kalkmış ve proje iptal edilmiştir.

## 6. Proje Başarısı

Bir projeye ne zaman başarılı, ne zaman başarısız denir? Hedeflerine ulaştığı için bitirilmiş bir projede bakılacak unsurlar bellidir.

### 6.1 Zaman, Kapsam, Bütçe ve Kalite

Bu işin üç temel bacağı vardır: zaman, kapsam ve bütçe. Bitmiş bir projede şu sorular sorulur:

- Zamanında bitmiş mi?
- İlk başta belirtilen kapsam yerine getirilmiş mi?
- Bütçe çerçevesinde tamamlanmış mı?

Bu üçü sağlanmışsa proje, bittiği anda başarılı sayılır. Ama başarı değerlendirmesi burada bitmez. Slaytta en üstte yazan kalite en önemli unsurdur.

> **Hocanın vurgusu:** Kalite en önemlisidir. Zamanında, tanımlanan kapsamla ve tanımlanan bütçeyle bitirilmiş bir proje, belli bir kullanım süresi sonunda yeterince doğru çalışmıyor ve çok sayıda hata veriyorsa, "başarılı proje, zamanında ve istediğimiz bütçeyle bitti, her şeyi yapıyor" sözü geri alınır.

### 6.2 Başarının Göstergeleri

Proje başarısı şu sorularla ortaya konur:

- Proje kapsam, zaman, maliyet ve kalite hedeflerini karşılıyor mu?
- Proje müşterisi memnun mu?
- Projenin sonuçları esas hedefi karşılıyor mu?
- Para kazanılmış mı veya ürün kullanıldığında yapılan harcamalardan tasarruf edilmiş mi?
- İyi bir yatırım sağlanmış mı?
- Firmanın marka değeri artmış mı?

### 6.3 Kurum İçi Projede Müşteri ve Sponsor Notu

Yazılım projesini yapan firma bir yazılım firması olabilir. Bu durumda müşteri dışarıdandır. Yazılım dışında bir alanda çalışan bir firmada ise projeyi yazılım geliştirme birimi yapabilir. Bu durumda müşteri diğer departmanlardır.

Örneğin muhasebe departmanı için bir ürün üretiliyorsa projedeki müşteri ve sponsor, muhasebe biriminin başkanıdır. Sponsor notu denilen notta şunlar yer alır: Proje istediklerimi karşılıyor mu, zamanında bitti mi, beni memnun etti mi? Böylece doğrudan hedefteki müşterinin memnuniyeti görülür. Ardından proje sonuçlarına göre amacın karşılanıp karşılanmadığı ve işin memnuniyetle bitip bitmediği değerlendirilir.

## 7. Başarıyı Getiren Faktörler ve Kilometre Taşları

Şimdiye kadar başarının göstergeleri söylendi. Sıradaki soru şudur: Bu başarıyı ne getirir, neler olursa proje başarılı yürür?

### 7.1 Başarı Faktörleri

Birinci sırada üst yönetim desteği gelir. Diğer faktörler şunlardır:

- **Net iş tarifleri:** İşler açıkça tarif edilmiş olmalıdır.
- **Temel gereksinimleri karşılayan kapsam:** Kapsam temel gereksinimleri yerine getirmelidir.
- **Kullanıcı katılımı:** Kullanıcı yazılım geliştirme sürecinde işle ilgilenmezse, çıktıları iyi kontrol etmezse ve isteklerini doğru aktarmazsa, proje çalışanları ne kadar gayret ederse etsin başarı çok zordur. Minimum kapsamın ve temel gereksinimlerin iyi anlatılması da mümkün olmaz.
- **Net iş hedefleri:** "Bu projeyi yapmak bize ne sağlayacak?" sorusunun farkında olunmalıdır.
- **Belirli bir metodoloji:** Belirli bir metodoloji kullanıldığında başarı daha kolay gelir. Hoca bu noktadan itibaren yazılım mühendisliği konularına gelindiğini belirtti.
- **Güvenilir tahminler:** Daha önce yapılan yazılım ölçümleri kullanılarak maliyet tahminleri yapılmış ve süre tahmini doğru yapılmış olmalıdır.
- **Küçük kilometre taşları:** Gözden geçirme yapılacak önemli dönüm noktaları belirlenmelidir.
- **Deneyimli proje yöneticisi ve yetkin ekip:** Proje yöneticisinin deneyimli, ekibin yetkin olması projenin başarısı için önemlidir.

### 7.2 Kilometre Taşı (Milestone)

Hoca kilometre taşı kavramının Sistem Analizi dersinde geçtiğini ve günlük hayatta da kullanıldığını söyleyip sınıfa sordu.

**Soru:** Kilometre taşı nedir?

Bir öğrenci, gereksinim analizi, tasarım, kodlama, sınama ve bakım onarım basamaklarının tamamlandığı noktalar olduğunu söyledi.

**Cevap:** Evet. Yazılım için esas önemli olan noktalar analizin, tasarımın ve gerçekleştirmenin (kodlamanın) bittiği noktalardır. Bunlar yazılım projesindeki önemli ilerleme noktalarıdır. Buralara projenin önemli aşamaları diye bir işaret konur ve bu işaretlerde genellikle bir gözden geçirme yapılır. Bu noktalara kilometre taşı (milestone) denir. Yazılım dışındaki projelerde de kilometre taşı, projedeki esas dönüm noktalarının işaretlendiği yerlerdir.

Gözden geçirme noktaları her zaman işin akışına bağlı olmayabilir. Sponsorlu, yani TÜBİTAK veya Sanayi Bakanlığı gibi kurumlarca desteklenen bir projede destekleyici kurum kilometre taşlarını beklemez. Belirli süreler verir: Değerlendirici 3 ayda bir, 6 ayda bir veya senede bir gelip bakar. O zaman gözden geçirme noktaları, işin kilometre taşları değil, süreye bağlı noktalar olabilir.

## 8. Proje Yöneticisi

Projede en fazla yükü proje yöneticisi alır. Hoca bu konuda kullandığı, AMACOM yayınlarından çıkan bilgi sistemleri proje yönetimi kitabının yönetici tanımıyla başladı.

### 8.1 Yetkisiz Ama Sorumlu Yönetici

> **Hocanın vurgusu:** Proje yöneticisi, yetkisiz ama sorumlulukları olan bir yöneticidir.

Kitabın böyle demesinin nedenleri şunlardır:

- Proje yöneticisinin elinde doğrudan bütçe kaynakları yoktur. Bunları üst yönetimden istemek zorundadır.
- Ekibindeki kişilerin çalışmasından ve yönetiminden o proje için doğrudan sorumludur, ama pek çok yaptırım yine esas yöneticilerin elindedir.

Yetkiler projeye göre değişir. Ama genellikle yetkiler az, sorumluluklar fazladır.

### 8.2 Sorumlulukları

- **Kapsam:** Kapsamın doğru tanımlanması, yönetilmesi ve doğrulanması. Proje bitti deyip bırakmamak, sonuçları doğrulamak, yani verifikasyon yapmak da buna dâhildir.
- **Zaman ve maliyet:** Projenin zaman ve maliyet planlarına göre takip edilmesi. Ne zaman bitecek, ne kadar bütçe kaldı?
- **Risk:** Risklerin baştan doğru tahmin edilmesi, izlenmesi ve ortadan kaldırılması için gereken risk aksiyonlarının belirlenip doğru uygulanması.
- **Metrikler:** Proje üzerinde ölçümler yapılması ve sonuçların yönetime ve ekip üyelerine doğru ve zamanında raporlanması.
- **Ekip:** Ekibin yönetilmesi.
- **Kalite:** Çıktı kalitesinin sürekli kontrol edilmesi ve iyileştirilmesi.

Listenin başında kapsam, zaman ve maliyet vardır. Çünkü proje başarısını ilk anda ortaya çıkaranlar bunlardır.

### 8.3 Çevik Yöntemlerde Proje Yöneticisi

Çevik metodoloji kitaplarında artık proje yöneticisi yoktur. Proje yönetimiyle ilişkili kavramlar vardır, ama gerçekleştirme çevik yaklaşıma göredir. "Herkes birbirine karşı sorumlu, herkes birbirinin yaptığını kontrol ediyor ve biliyor" ilkesi geçerlidir. Yine de bütün ekibi bir arada tutup yönlendirecek bir koordinatöre ihtiyaç vardır. Proje yöneticisi kavramı olmasa da bir proje koordinatörü bulunur ve yukarıdaki sorumlulukların çoğu ondadır.

### 8.4 Yetkinlikleri

Proje yöneticisi ekibi yönettiği için şu yeteneklere sahip olmalıdır: liderlik, ekip oluşturma, motivasyon, iletişim, etkileme, karar verme, müzakere etme, çatışma yönetimi ve koçluk.

### 8.5 Yönetici Alan Uzmanı Olmalı mı?

Hoca, bu listede alan bilgisinin sayılmadığına dikkat çekti. İlk derste yazılım proje yönetiminin üç ana bilim dalının bileşkesi olduğu söylenmişti. Konu çok tartışılıyor:

- Yazılım proje yöneticisi, işini çok iyi bilen, deneyimli ve proje yönetimi konusunda ek bilgi almış bir bilgisayar veya yazılım mühendisi olursa mı daha başarılı olur?
- Yoksa proje yönetimini ve yönetim bilimini çok iyi bilen, alanda biraz bilgisi olan ama uzmanlığı olmayan bir kişi de başarılı olabilir mi?

Hocanın aktardığı görüş, yöneticinin üçüncü ayağa, yani alan bilgisine de sahip olması gerektiğidir. Sektörde de bu görüş daha fazla ortaya çıkıyor. Ama proje yönetim ofislerinde zaman zaman sadece diğer ikisinin yeterli olduğu tartışılıyor. Hocanın toparlaması şudur: Yetkinlikler vardır, ama temel alan üzerine de bilgi sahibi olunması gerekir.

> **Ders sonrası not:** Hoca güncel bilgilerin alınabileceği kurum olarak "Project Management Body of Knowledge kurumu" dedi; PMBOK bir kurum değil bir bilgi birikimi rehberidir. Kastedilen kurum büyük olasılıkla bu rehberi yayımlayan Project Management Institute'tur (PMI).

### 8.6 Yönetim Tarzları

Ekip yönetiminde dört tarzdan söz edildi:

- **Delege edici:** Hoca bunu sadece "Şu şöyle yapılacak" diye sert bir şekilde söylemek olarak tarif etti.
- **Yönlendirici:** "Bunu şu şekilde yaptığımızda hata alıyoruz, bir de bu şekilde deneyelim" diyebilmek.
- **Destekleyici:** "Ekibin sahibi benim, ben de yardım edeyim, proje başarılı olsun" diyen ve her işin altında kendisi de çalışmayı kural edinmiş yönetici.
- **Yol gösterici:** Yönlendiriciye çok yakındır. Farkı, kişinin neye ihtiyacı olduğunu ve eksiklerini belirleyip eğitim yolunu da göstermesi, yol çizme desteği vermesidir.

> **Ders sonrası not:** Hoca "delege edici" için "şu şöyle yapılacak diye sert söylemek" dedi; bu tarif büyük olasılıkla delege etmeye değil, doğrudan talimat vermeye (directing) uyar. Delege etmede yönetici işi ve kararı ekip üyesine bırakır. Hocanın dört tarzı büyük olasılıkla Hersey-Blanchard durumsal liderlik modelindeki yönlendirme, koçluk, destekleme ve delege etme tarzlarına yakındır.

Yöneticinin başarılı olması için bunlardan yalnızca birini rol olarak alıp yürütmek yetmez. Hepsini içinde taşımalı ve duruma göre kullanmalıdır:

- **Ekip üyesine göre:** Bir kişide delege edici tarz başarı getirirken başka bir kişide tamamen başarısızlığa götürebilir.
- **Zamana göre:** Örneğin projenin bitiş tarihi yaklaşmışsa proje yöneticisinin de gerektiğinde işin içine girmesi gerekebilir.

Hoca bu bölümü üç başlıkla özetledi: Proje yöneticisinin sorumlulukları, kendisinden beklenen yetkinlikler ve yönetim tarzları.

## 9. Proje Temel Süreçleri

Hoca, projenin temel süreç adımlarını şimdiye kadar hep sözlü olarak saydığını söyledi. Project Management Institute'un en son verdiği aşamalar şunlardır: başlama, planlama, yürütme, yürütme sırasında izleme ve kontrol, kapanış.

Kullandığı *Information Systems Project Management* kitabı ise başlama aşamasını biraz daha açar. Başlamayı projenin anlaşılması (project understanding) ve projenin tanımlanması (project defining) olarak ikiye ayırır. Bazı kaynaklar da girişi bu şekilde daha ayrıntılı gösterir.

### 9.1 Anlama Aşaması

Proje her zaman yöneticinin kendi projesi olarak ortaya çıkmaz. Yönetim "Şu projeyi gerçekleştirin" diye üstten de verebilir. Bu durumda proje yöneticisi önce projenin ne olduğunu ve nereden geldiğini anlamalıdır:

- Şirkette daha önce yapılmış bir projenin devamı mı?
- Daha önce yapılmış bir projenin değiştirilmesi mi?
- Yeni bir proje olup eski projelerle ilişkili mi çalışacak?

Hoca bunu projenin hayat hikâyesini ve geliş noktasını öğrenmek olarak anlattı. Ardından planlamaya başlamadan önce projenin temel önceliği anlaşılmalıdır: Proje zaman öncelikli mi, bütçe öncelikli mi, yoksa kapsam öncelikli mi?

Bu aşamanın en önemli işi ise kabaca bir ekonomik fizibilite çalışmasıdır:

- Bu projeye girilebilir mi?
- Proje harcamalarımızı geri getirebilecek mi?
- Maddi olarak mı getirecek, yoksa firma marka tanınırlığı açısından mı?
- Ne kadar sonra getirisi olacak?

### 9.2 Tanımlama Aşaması

Project defining aşamasında projenin doğru tanınıp tanınmadığına bakılır:

- Projede teslim edilecekler nelerdir?
- Müşteri tarafı nedir? Müşterinin önceliği (zaman, bütçe, kapsam) anlama aşamasında öğrenilmiştir.
- Çıktılar neler olacak, hangi aşamada hangi çıktılar isteniyor?
- Nasıl ara değerlendirmeler yapılacak, kilometre taşları nasıl belirlenecek?
- Her esas adımda müşteriye teslim edilecekler nelerdir?

### 9.3 Planlama Aşaması

Planlama aşamasında önce projenin kabulleri, kısıtları ve riskleri belirlenir. Sonra süreç adımları ortaya çıkarılır ve bu adımlar zaman ve insan kaynağı açısından belirlenir. Örneğin analiz, tasarım ve gerçekleştirme ana adımlarının her biri için şunlar çıkarılır:

- Ne zaman başlayacak, ne zaman bitecek, birbiriyle nasıl ilişkili?
- Her birinde kaç kişiye ihtiyaç var?
- Satın alınması gereken araçlar var mı?

Zaman ve kaynaklar birleştirilerek bütçe çıkarılır. Bunların hepsi proje planlama teknikleriyle yapılır. Gantt ve PERT diyagramlarıyla zaman fizibilitesi oluşturulur.

**Soru:** Gantt diyagramı nedir?

Bir öğrenci, nasıl yapıldığını tam bilmediğini, ama proje planlamasında zaman çizelgesi oluştururken kullanılan bir araç olduğunu söyledi.

**Cevap:** Hoca bunu doğruladı. PERT de zaman yönetimini iş adımlarıyla eşleştirerek Gantt diyagramının çizilmesine destek olur ve optimum süreleri bulmaya yardımcı olur. İkisi temel proje yönetim araçlarıdır. Planlama sırasında zaman planını, kaynak planını ve bütçeyi çıkarırken ve bunları takip ederken kullanılır.

Bunları daha kolay çizmeyi ve takip etmeyi sağlayan yazılımlar vardır. Piyasada en yaygın olanı MS Project'tir. Başka firmaların ürünleri de vardır, hoca en yaygın olduğu için bunu örnek verdi.

### 9.4 Yürütme, İzleme ve Kontrol

Projenin yürütülmesi ile izleme ve kontrol, bütünleşik yürür. Hocanın kullandığı kitap yürütme (project executing) ile izleme ve kontrolü (project monitoring and control) birleştirerek "project running" olarak tanımlar. Proje çalıştırılırken "Plana göre doğru gidiyor muyuz?" diye bir kontrol süreci de işler.

Hoca dersin ilerleyen kısmında bu adımlara yeniden döndü. İzleme ve kontrol bütün süreci kapsar: Başlangıç bilgileri, anlama, tanımlama ve planlama bütün adımlarda izlenir. Çalıştırma ile planlama birbiriyle döngü hâlinde ilerler. Çünkü yapılan bütün işlerin plana uygun olup olmadığı kontrol edilir.

Bu kontrol genellikle kilometre taşlarında yapılır. Örneğin analiz bittiğinde şu sorular sorulur: Analizde neler yaptık, durum nedir, plana uygun muyuz? Böylece plan ile gerçekleşen durum arasında bir değerlendirme yapılır.

### 9.5 Kapanış

Kitap bu konuda şöyle der: Kapanış yalnızca "Ekip olarak projeyi tamamladık, bitirdik, kutlayalım" demek değildir. Bitmiş projenin ölçümleri yapılmalı ve bir veri tabanında toplanmalıdır. Proje bilgisi (know-how) daha sonra kullanılabilecek şekilde sayısallaştırılır, kategorize edilir ve kuruluşun projeler veri tabanına yerleştirilir. Bu, 4. bölümde anlatılan maliyet tahminini mümkün kılan adımdır.

### 9.6 Proje Yönetimi Yol Haritası

Hocanın referans kitabı bu temel süreçleri proje yönetimi yol haritası (project management roadmap) olarak adlandırır: anlama, tanımlama, çalıştırma (yürütme ve izleme) ve kapanış. Hoca bunun üzerinde özellikle durdu.

> **Hocanın vurgusu:** Sınavlarda "proje yönetimi yol haritası" veya "proje yönetimi temel süreçleri" sorulduğunda cevapların yarısı yazılım geliştirme temel süreçleri oluyor. Bu yanlıştır. Proje temel süreçleri bütün projelerde geçerlidir: başlama, planlama, yürütme ve kapanış.

Yazılım geliştirme temel süreçleri (analiz, tasarım, gerçekleştirme, test) ise proje planlamada planlanan iş adımlarının yerine geçer. Projeyi çalıştırma aşamasında yapılan işler de bu adımların içine girer. Yani ikisi farklı düzeylerdedir ve karıştırılmamalıdır.

## 10. Proje Bilgi Alanları ve Yaşam Döngüleri

### 10.1 Bilgi Alanları

Proje yönetiminde hangi alt yönetim işlemleri vardır? Bunlara proje bilgi alanları denir, ama hoca "proje yönetiminin alt alanları" da dedi. Bir projeyi doğru yönetebilmek için şu alanların iyi gerçekleştirilmesi gerekir:

- **Kapsam yönetimi:** Slaytta en üsttedir. Projenin kapsamı gözden kaçırılmamalıdır.
- **Zaman yönetimi:** Çok önemlidir. O da en üstte yer alır.
- **Bütünlük yönetimi:** Projenin alt başlıklarıyla geneli ve bunların birbiriyle ilişkileri gözden kaçırılmamalıdır. Bu da en üstte yer alır.
- **Kalite yönetimi.**
- **Maliyet yönetimi.**
- **İnsan kaynakları yönetimi:** Çalışanların yönetimi.
- **Paydaş yönetimi:** Alt yükleniciler, satın alma yapılan firmalar, ürünün gönderileceği kullanıcılar.
- **İletişim yönetimi:** Esas yönetimle, müşteriyle, paydaşlarla ve çalışanlarla iletişimin nasıl olacağı.
- **Risk yönetimi:** Risklerin neler olduğu ve takibi.
- **Satın alma yönetimi.**

> **Ek bilgi (derste anlatılmadı):** Bu on alan büyük olasılıkla PMBOK rehberindeki bilgi alanları (knowledge areas) listesine dayanır. Rehberde bütünlük yönetimi "integration management" adıyla geçer.

### 10.2 Yaşam Döngüleri

Slaytta üç yaşam döngüsü de vardır: projenin yaşam döngüsü, şirketin iş yaşam döngüsü ve ürün yaşam döngüsü.

- **Ürün yaşam döngüsü:** Ürünün ne kadar kullanıldığıdır. Ürün iyi çıkmadığı veya ihtiyaç kalmadığı için daha kısa ya da daha uzun olabilir.
- **Proje yaşam döngüsü:** Projede hangi işlerin gerçekleştiği ve geliştirme için anlatılan adımlardan hangilerinin kullanıldığıdır.

<!-- BELİRSİZ: Şirketin iş yaşam döngüsü yalnızca adıyla geçiyor; slayttaki şeklin ayrıntısı altyazıda yok. -->

## 11. Başlama Süreci: Berat, Paydaşlar ve Organizasyon

Başlama sürecinde projenin anlaşılması ve tanımlanmasına ek olarak proje paydaşlarının anlaşılması, proje organizasyon şeması ve proje içi toplantılar da vardır. Hoca bunların kurumlarda pratik hayattaki tecrübelerle gerçekleştirilen işlemler olduğunu söyledi.

### 11.1 Proje Beratı

Projenin başlangıç aşamasında bir berat dokümanı oluşturulur. İçeriği şunlardır:

- Projenin açılma nedenleri: Bu projeye niye başlıyoruz, neden önemli?
- İlişkili olduğu projeler.
- Projenin hedefi.
- Projenin ana kısıtları.
- Ana paydaşı: Hangi kurum veya firma? Kurum içi projeyse hangi departmanın projesi?
- Kapsamı ve kapsam dışında kalan işler.
- Riskler.
- Taslak bütçe: Yönetimin bu projeye ayırabileceği, kafasındaki bütçe. Bu bütçe bilinip ondan sonra planlamaya başlanmalı, kapsam da buna göre belirlenmelidir.

> **Ders sonrası not:** Altyazıda geçen "berat dökümanı", büyük olasılıkla proje yönetimi kaynaklarındaki proje beratı (project charter) belgesidir.

### 11.2 Paydaşlar

Projenin paydaşları ilk olarak şöyle sayıldı: proje ekibi, proje yöneticileri, alt yükleniciler, müşteriler, satın alma yapılacak kişi ve kurumlar, projenin yapılacağı departmanın çalışanları. Slaytta ise paydaşlar iç ve dış olarak ayrılmıştır. İç paydaşlar şirketin içindeki birimler ve kişilerdir, dış paydaşlar şirket dışındakilerdir.

- **İç paydaşlar:**
  - Esas yönetim, doğrudan bağlı olunan yöneticiler ve diğer yöneticiler.
  - Şirket sahipleri.
  - Ekip üyeleri ve proje ekibinde çalışanların aileleri.
  - Çalışanların hakları açısından sendikalar.
  - Sponsorlar: Projeyi kimler destekliyor?
  - Sponsorlara bağlı çalışan son kullanıcılar.
  - Fonksiyonel yöneticiler: Proje nereye yapılıyorsa oranın yönetimi.
  - Muhasebe ve insan kaynakları gibi çalışanların bağlı bulunduğu birimler.
- **Hem iç hem dış olabilenler:** Tedarikçiler ve müşteriler. Bunlar şirket içinde de dışında da olabilir. Slaytta bu yüzden ortaya yazılmıştır.
- **Dış paydaşlar:**
  - Bazı sivil toplum kuruluşları.
  - Medya.
  - Rakip firmalar.
  - Dıştaki tedarikçiler.
  - Yasalara uygunluk gibi konularda projeyle ilişkili devlet tarafı.

Bu bir örnektir. Her projede bunların hepsi olmayabilir, daha fazlası da olabilir.

### 11.3 Organizasyon Şeması ve Başlangıç Toplantısı

Projenin organizasyon şemasında proje sponsoru, yönlendirme komitesi ve proje yöneticisi yer alır. Şema, iş adımlarına göre (analiz ve geliştirme sırasında yapılan işlemler) veya projenin kullanılacağı yerlere göre de kurulabilir.

Başlama sürecinde projede hangi işlerin yapılacağı ve bu işler nedeniyle kimlerle ilişkide olunacağı kabaca ortaya çıkarılır. Ayrıntıları, planlama aşamasında proje ekip yapısının kuruluşunda görülecek.

<!-- BELİRSİZ: Organizasyon şeması slaytının kutuları altyazıda tam sayılmıyor; yalnız sponsor, yönlendirme komitesi ve proje yöneticisi net olarak geçiyor. -->

Son olarak hedeflerin gözden geçirildiği bir başlangıç gözden geçirme toplantısı yapılır. Böylece projenin başlama süreci tamamlanır.

## 12. Planlama Süreci

Hoca planlama sürecini "bizim esas işimiz" diye tanıttı. Bir inşaat projesinde önce mimari bir plan yapılır. Yazılım projelerinde de iyi bir başlangıç için önce yapılacak işin planı yapılır. Planın nasıl olacağı ihtiyaçlara göre değişir, ama sonrasında bu plana uygun gitmek gerekir.

> **Hocanın vurgusu:** Çok kullanılan "Kervan yolda düzülür" sözündeki gibi yürümemek gerekir. Planda gerçekleştirilecek işler ve geçerli kriterler baştan tanımlanmış olmalıdır.

Projenin paydaşları arasında farklı uluslardan kişiler varsa davranış farkları da dikkate alınmalıdır. Bazıları hakikaten dakiktir ve plandaki bütün ayrıntıların belli olmasını ister. Bazı ülkelerle çalışırken ise karşı tarafın çok ince ayrıntıyı baştan konuşmaya tahammülü yoktur, "Sonra devam ederiz" yaklaşımı görülür.

Planlama sırasında şu sorulara cevap aranır:

- **Ne yapacağız?** Örneğin yazılım geliştireceğiz.
- **Nasıl yapacağız?** Hangi iş adımları var (analiz, tasarım, gerçekleştirme)? Her adımda hangi tür kaynaklarla çalışacağız?
- **Kiminle yapacağız?** Hangi kaynaklar ve araçlar kullanılacak? Yazılım aracı kullanılacak mı, donanımda farklılık var mı?
- **Ne zaman yapacağız?** Zaman planlaması.
- **Kaça yapacağız?** Bütçe.
- **Riskler nelerdir?** Bunlar da planlanmalıdır.

## 13. İş Kırılım Yapısı (WBS)

### 13.1 Kapsam Yönetiminin Aracı

Kapsam yönetiminin aracı iş kırılım yapısıdır (Work Breakdown Structure, WBS). Slaytta bir yazılım geliştirme projesi örneği vardır. Üst düzey adımlar şunlardır: ürün ihtiyaçlarının ortaya çıkarılması ve analizi, tasarım, geliştirme, entegrasyon ve test. Bütün bu süreç proje yönetimi altında yürütülür.

Bir sonraki soru her adımın alt başlıklarıdır. "İkinci düzeye kadar ayrıntı verelim" dendiğinde örneğin tasarım şöyle ayrılabilir:

- Yazılım için sunucu (server) tarafı tasarımı.
- Yazılım için istemci (client) tarafı tasarımı.
- Belgelerin tasarımı.
- Eğitimin tasarımı.

Kırılımda kilometre taşları da belirtilir. Slayttaki örnekte bunlar çözüm analizi, teknik detayların verilmesi, tasarım, geliştirme, test gözden geçirmesi ve kullanıma alma (deployment) olarak geçmektedir.

<!-- BELİRSİZ: Altyazıda "test drive" diye geçen kilometre taşının slayttaki tam adı net değil. -->

### 13.2 Düzey Sorusu

Hoca bir zaman planı örneğinde önce kısa bir iş listesi gösterdi: yeni ürün için çalışmalara başlanması, birinci komponentin ve ikinci komponentin tamamlanması, bütünleştirme, yeni ürünün tamamlanması. Listeyi ayrıntılandırınca altyazıdan kurulabilen yapı şöyledir:

```text
Ürün Z'nin çalışmalarına başlanması
  Ürün Z'yi geliştir ve dağıt
    İş paketi 1 (komponent 1)
      Komponent 1 tasarımı
      Komponent 1 oluşturma (build)
      Komponent 1 testi
```

<!-- BELİRSİZ: Ayrıntılı iş listesinin iş paketi 1'den sonraki satırları ve numaraları slaytta kalmış; altyazıda yalnız iş paketi 1'in kolu okunuyor. -->

**Soru:** Komponent 1'in tasarım, oluşturma ve test işleri WBS'in kaçıncı düzeyindedir?

**Cevap:** Bir öğrenci dört dedi. Hoca doğruladı: Ana işlem birinci düzey sayılırsa dördüncü düzeydir. Başlangıç olan ana işleme düzey numarası verilmezse üçüncü düzey de denebilir, ama dördüncü demek uygundur.

Hoca bu soruyu bir amaçla sordu: Daha sonra "Şu iş için WBS'i dördüncü düzey ayrıntıya kadar oluşturun" dediğinde herkes aynı dili konuşsun.

## 14. Zaman Yönetimi

Projenin zamanında tamamlanması gerekir. Zaman; kapsam ve para ile birlikte projenin en önemli bileşenlerinden biridir.

### 14.1 Adımlar

- **Aktivitelerin belirlenmesi:** Örneğin yazılım geliştiriyorsak esas aktiviteler analiz, tasarım, gerçekleştirme ve testtir.
- **Aktivitelerin sıralanması:** Öncelik-sonralık ilişkisine göre sıralanır ve bağımlılıklar belirlenir. Örneğin şelale modelinde sıra analiz, tasarım, gerçekleştirme ve testtir. Biri bitmeden diğeri başlamaz.
- **Aktivite kaynaklarının belirlenmesi:** Hangi aktivitede hangi kişiler ve hangi araçlar kullanılacak?
- **Aktivite sürelerinin tahmini:** Örneğin analizde yalnızca iki kişi kullanılabiliyorsa analizin ne kadar sürede tamamlanacağı buna göre çıkarılır.
- **Zaman planının oluşturulması:** Aktivitelerin belirlenmesi, sıralanması ve süre tahmini ile Gantt diyagramı ve PERT çalışılarak zaman planı ortaya çıkar.
- **Zaman planının kontrolü:** Proje yürütülürken nereye kadar gelindiği ve planın neresinde olunduğu kontrol edilir.

### 14.2 Gantt Diyagramı

Gantt diyagramı, WBS'ten gelen iş adımlarını ve hangi işin hangi sürede yapıldığını, nereye kadar gelindiğini gösterir.

<!-- BELİRSİZ: Slayttaki Gantt örneğinin iş adları ve süreleri altyazıda okunmuyor. -->

### 14.3 PERT ve Kritik Yol

Zaman planı yapılırken kritik yol da önemlidir. PERT diyagramında proje evrelerinin süreleri ve her iş adımı yazılır. Ardından şu sorular cevaplanır: En sona ulaşmak için en kritik yol nedir? Arada hiç bekleme yapılmaması gereken yol hangisidir?

Sonuca ulaşmak için farklı yollar olabilir. Slayttaki örnekte istenen sonuca ulaşmak için dört farklı yol vardır. Bu yolların her birinin süreleri kontrol edilir ve aralarda bekleme süresi olup olmadığına bakılır.

> **Ders sonrası not:** Hoca PERT'in açılımını okurken altyazıda "Project Evaluation, CEM, Teknik" geçiyor ve hoca bunu "proje evrelerinin gözden geçirildiği" diye açıkladı; açılım büyük olasılıkla Program Evaluation and Review Technique'tir.

> **Ek bilgi (derste anlatılmadı):** Kritik yol genellikle başlangıçtan bitişe toplam süresi en uzun olan yol olarak tanımlanır. Bu yoldaki aktivitelerin bolluğu (slack) sıfırdır. Yani bu aktivitelerden birindeki gecikme projenin bitiş tarihini de geciktirir. Hocanın "arada hiç bekleme yapılmaması gereken yol" tarifi bu özelliğe karşılık gelir.

<!-- BELİRSİZ: Dört yollu PERT örneğinin düğümleri ve süreleri slaytta kalmış, altyazıda sayısal değer yok. Bu yüzden kritik yol örneği burada hesaplanamadı. -->

## 15. Maliyet Yönetimi

Zamanla ilgili çalışmaların dışında bir de maliyet yönetimi vardır. Maliyet yönetimi, planlama, tahmin ve bütçeleme gibi işlerle finansal kaynakların yönetildiği bir bilgi alanıdır. Üç ana işi vardır:

- **Maliyeti tahmin etmek:** Önce her aktivite için maliyet tahminleri yapılır.
- **Bütçeyi belirlemek:** Sonra tahminlere göre işletmeciliğe uygun olarak bütçeleme yapılır. Maliyet kalemlerine değer atanır ve yönetim için bir miktar rezerv konur.
- **Maliyetleri kontrol etmek:** Evreler ilerledikçe bu kontrol sürekli yapılır. Örneğin analizle başlanıp tasarıma gelindiğinde şu sorular sorulur: O ana kadarki hedefler tuttu mu, ne kadar harcandı, ne kadar planlanmıştı?

Slayttaki bütçe belirleme örneği, maliyet tahmini yapıldıktan sonra her kalemin bütçeye nasıl yazıldığını gösteriyor.

<!-- BELİRSİZ: Bütçe parçaları anlatılırken altyazıda "ekantların kontrol edilmesi" gibi anlaşılmayan bir ifade geçiyor; slayttaki bütçe örneğinin kalemleri ve rakamları altyazıda yok. -->

## Dersin Toparlaması

Bu derste yazılım proje yönetimi, önce yazılım mühendisliği içindeki yerine oturtuldu: Kaliteli yazılımı en ekonomik şekilde üretmek, fiyat ile verimlilik dengesini kurmaktır. Proje yönetimi de yazılım mühendisliği teknikleri, proje yönetimi bilgisi ve genel yönetim biliminin bileşkesidir. Ölçüm bu yapının her adımındadır, çünkü ölçülemeyen yönetilemez. Ardından proje kavramı rutin işten ayrıldı, başarı zaman, kapsam, bütçe ve hepsinden önemlisi kalite üzerinden tanımlandı, başarıyı getiren faktörler ve kilometre taşları görüldü. Proje yöneticisinin az yetkili ama çok sorumlu konumu, yetkinlikleri ve duruma göre değişen yönetim tarzları üzerinde duruldu.

Dersin ikinci yarısında proje yönetiminin yol haritası kuruldu: başlama (anlama ve tanımlama), planlama, yürütme ile izleme ve kontrol, kapanış. Bu süreçlerin yazılım geliştirme adımlarıyla karıştırılmaması gerektiği özellikle vurgulandı. Başlama sürecinde proje beratı ve paydaşlar, planlama sürecinde ise WBS, zaman yönetimi (Gantt, PERT, kritik yol) ve maliyet yönetimi görüldü. Hoca, yazılım projeleri için gereken diğer bilgi alanlarına, bu arada iletişim yönetimine, sonraki derslerde devam edeceğini söyledi. Proje organizasyonunun ayrıntıları da planlama aşamasındaki ekip yapısı kurulurken ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
