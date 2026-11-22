# Ders 1 Genişletilmiş Notu: Giriş, Sistem Kavramı ve Bilgi Sistemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Bakış Açısı
- 2. Dersin Konu Akışı
- 3. Başka Bölümlerde "Sistem Analizi"
- 4. Sistem Nedir?
- 5. Bir Sistemin Elemanları
- 6. Üniversite Bir Sistem Olarak
- 7. Sistem Sınırı ve Otomasyon Sınırı
- 8. Sistemin Amacı
- 9. Sistem Düşüncesi
- 10. Geri Besleme
- 11. Bütünleşik Bir İşletme Sistemi
- 12. Bilgi Sistemi ve Tipleri
- 13. Sistem Analisti ve Becerileri
- 14. Derste Tekrar: Sistem Yapısının Özeti
- Örnek Sorular

## 1. Dersin Amacı ve Bakış Açısı

Birinci sınıftaki bilgisayar mühendisliğine giriş, algoritmalar ve programlama dersleriyle nesneye yönelik programlama dersinde, bir programı hangi adımlarla yazacağımızı, programlama dili kavramını ve temel algoritma yapılarını gördük. Bu derslerde problem küçüktü: problem tanımlanıyor, algoritma kuruluyor ve program yazılıyordu.

Sistem analizi ve tasarımı dersinde bakış açısı yükselir. Soru artık "bu programı nasıl yazarım" değil, "bir sistemi bütünüyle nasıl hayata geçiririm" sorusudur. Bir bilgi sisteminin genel sistemler içindeki yeri nedir, bir problemi baştan sona yazılım haline getirirken sistemi bir bütün olarak nasıl kurarız, bütün adımlarıyla birlikte bunlar değerlendirilir.

Hoca bu süreci şöyle sıraladı: önce olurluluk (fizibilite) analizi yapılır, ardından sistem analizi gerçekleştirilir, sonra bu analize en uygun bilgi sistemi tasarımının hangisi olduğuna karar verilip tasarım geliştirilir. Nesneye yönelik çözümleme kısmında analiz ve tasarım işleri programı nesneye yönelik olarak geliştirmek için yapılır. Bu derste ise test edilmiş yazılımın uygulamaya nasıl konacağı ve sistemin kullanıma nasıl hazırlanacağı da dahil, bütün süreç ele alınır.

> **Hocanın vurgusu:** Bu ders bir başlangıç dersidir. Amaç, yaptığımız geliştirme çalışmalarında büyük resmi kaybetmeden ayrıntıları ele alabilmektir.

## 2. Dersin Konu Akışı

Hoca ders planını bir tablo olarak ekranda gösterdi (ekrandan, 00:05:00). Tarih ve sınav satırları dışarıda bırakılınca konu sırası şöyledir:

| Sıra | Konu |
|---|---|
| 1 | Giriş, ders planı, genel bilgiler, sistem tanımı |
| 2 | Sistem tipleri, taraflar, sistem geliştirme süreci (Waterfall) |
| 3 | Ön inceleme, fizibilite çalışmaları |
| 4 | Fizibilite çalışmaları, zaman fizibilitesi |
| 5 | Sistem analizi: veri toplama, iş analizi, kullanım senaryoları |
| 6 | Sistem analizi: veri modelleme, fonksiyonel çözümleme |
| 7 | Sistem analizi: nesneye yönelik çözümleme |
| 8 | Sistem tasarımı: mimari tasarım (yapı diyagramları, ardışıl diyagramlar) |
| 9 | Sistem tasarımı: girdi, çıktı, veri yapısı, arabirim tasarımları |
| 10 | Veritabanı tasarımı, kodlama, test süreçleri, yeni sisteme geçiş, bakım, destek süreçleri |
| 11 | Sistem analizi ve tasarımı örnek vaka çalışması |

Hoca konuların bazılarını açarak anlattı:

- **Taraflar:** Bilgi sistemi geliştirme sürecinde müşteri, kullanıcı, proje yöneticisi, sistem analisti gibi taraflar vardır. Bu kavramlar dönem boyunca sürekli geçeceği için tanımları ayrıca yapılacaktır.
- **Sistem geliştirme süreci:** Sektörde bugün çevik (agile) süreç modelleri çok kullanılır; daha eski olan spiral model hâlâ büyük projelerde kullanılır. Bu farklı modeller üçüncü sınıftaki yazılım mühendisliği dersinin konusudur. Bu derste başlangıç noktası olarak ilk model olan şelale (waterfall) modeli kullanılır.
- **Ön inceleme ve fizibilite:** Bize büyük ya da karmaşık bir problem sunulduğunda önce bunun olurluluğu, yani yapılabilirliği incelenir. Fizibilite bir olurluluk çalışmasıdır. Ara projelerde, bitirme projelerinde ve iş hayatında da böyle bir çalışma istenir. Fizibilitenin bir türü olan zaman fizibilitesi, yazılım mühendisliğinde proje planlama aşamasındaki zaman planlamasına karşılık gelir.
- **Sistem analizi:** Bir sisteme çözüm getirmek için önce işin kendisini analiz etmek gerekir. Bu bir işletme (business) analizi de olabilir, bir mühendislik problemi de. İşin bilgisayar devreye girmeden nasıl yürüdüğü anlaşılır, veri toplanır, kullanım senaryoları oluşturulur; sonra bu iş modellenir ve nesneye yönelik olarak nasıl çözümleneceği görülür.
- **Sistem tasarımı:** Mimari tasarımda modelleme aracı olarak diyagramlar kullanılır: yapısal yaklaşımda yapı diyagramları, nesneye yönelik yaklaşımda ardışıl (sıralama) diyagramları gibi. Ardından girdi, çıktı, veri yapısı ve arabirim tasarımları gelir.

> **Hocanın vurgusu:** Diyagramları "resim çiziyoruz, hangi sembolü kullanıyoruz" diye düşünmeyin. Sembollerin arkasındaki mantığı kaybetmeyin. Modelleme, tasarlayacağımız sistemin sembollerle anlatımıdır; diyagramı sadece bir şekil gibi görmeyin.

**Soru:** Nesneye yönelik programlama dersini bu dönem alıyoruz; oradaki konular burada nasıl kullanılacak?
**Cevap:** Bu derste nesneye yönelik çözümleme verilir. Nesneye yönelik programları yazmadan önce nasıl tasarladığınızı ve bazı diyagramları orada da göreceksiniz. Burada bunları değerlendirip kullanabilecek kadar işlenir. Analiz ve tasarım, yapısal yaklaşımla da nesneye yönelik yaklaşımla da yürütülebilir.

## 3. Başka Bölümlerde "Sistem Analizi"

"Sistem" kelimesini günlük hayatta çok kullanırız: bilgi sistemi, evren sistemi, şehir sistemi. İnsanı, bir muhasebe sistemini ya da bir üniversiteyi de sistem olarak tanımlayabiliriz. Bu dersin hedefi, gerçek hayatta gördüğümüz herhangi bir sistemin analizini yapmak, yani sistemin ne olduğunu, hangi elemanlardan oluştuğunu, ne yaptığını ve amacının ne olduğunu öğrenmek; ardından bu sisteme yeni bir yaklaşım ya da çözüm getirmek için nasıl bir bilgi sistemi tasarlanabileceğini göstermektir.

Aynı adlı ders başka bölümlerde de vardır ve içerikleri farklıdır:

- **Elektrik mühendisliği:** Buradaki sistem analizi, elektrik devresi sistemlerinin matematiksel yaklaşımlarla analizidir. Bizim dersimizden çok farklıdır.
- **Endüstri mühendisliği:** Bize daha yakındır. Endüstriyel sistemlerin analizi, modellenmesi ve tasarımı ele alınır; özellikle bilgi sistemi geliştirilirken sistemin içindeki kişilerin bilgiyi nasıl vereceği ve iş analizini nasıl yapacakları anlatılır.
- **İşletme bölümleri:** Benzer şekilde, işi yapanların bu işi modelleyecek ve bilgi sistemini yaratacak olanlara nasıl daha iyi bilgi verebileceği, yaptıkları işin analizini nasıl daha iyi yapabilecekleri anlatılır.

Bazı üniversitelerde bu ders yalnızca bilgisayar programlarını öğreten bir ders gibi de kurulabilir; ama farklı yerlerdeki hedefler genel olarak yukarıdaki gibidir.

## 4. Sistem Nedir?

Teneffüsten sonra hoca slaytlara geçti. Tanım şöyledir: **Sistem**, alt sistem denen, birbiriyle ilişkili ve her biri bir işi başaran ya da bir fonksiyonu yerine getiren parçaların bütünüdür. Biyolojik sistem, bilgisayar sistemi ve sosyal sistem örnektir; bunların hepsinin alt sistemleri vardır.

**Bilgi sistemi** de farklı işletme görevlerini gerçekleştirmek için kurulmuş bir sistemdir. Tanımı dersin ilerleyen kısmında daha açık verildi (Bölüm 12).

<!-- BELİRSİZ: Tanımların bulunduğu slayt 3 ("Thinking in terms of Systems") ve slayt 4 ("Characteristics of systems") karelerde yalnız küçük önizleme olarak görünüyor; metin altyazıdan kuruldu. -->

## 5. Bir Sistemin Elemanları

Hoca sistemin elemanlarını "General Depiction of a System" şekli üzerinden anlattı (ekrandan, 00:55:00). Şekilde büyük bir elips sistemi gösterir. Elipsin çizgisi **boundary** (sınır) olarak etiketlenmiştir. İçinde beş küçük daire, yani **subsystem** (alt sistem) vardır. Daireler arasındaki çift yönlü oklar **interrelationship** (iç ilişki) olarak etiketlenmiştir. Dışarıdan elipse giren oklar **input** (girdi), elipsten dışarı çıkan oklar **output** (çıktı) olarak gösterilmiştir.

```text
          input
            |
+-----------v----------- boundary -------------+
|     (alt sistem) <--------> (alt sistem)      |
|          ^                       ^            |
|          |   interrelationship   |            |
|          v                       v            |
|   (alt sistem)   (alt sistem) <-> (alt sistem)|
+----------|------------------------|-----------+
           v                        v
        output                    output
```

Bu şekle göre bir sistem olmak için şunlar gerekir:

- Sistemin bir **amacı** olmalıdır.
- Dış ortamla bağlantısını **sınırlar** oluşturur.
- Dış ortamdan sisteme **girdiler** gelir.
- Sistem dış ortama **çıktılar** (output) üretir.
- Sistemin **elemanları** ya da **alt sistemleri** vardır.
- Bu elemanlar arasında **iç ilişkiler** vardır.

Sistem bütün bu elemanlarıyla birlikte, iç bağlantıların düzgün bir iletişim çerçevesinde işlemesiyle hedefini gerçekleştirmek üzere çalışır.

## 6. Üniversite Bir Sistem Olarak

İlk akla gelen örnek, içinde bulunduğumuz kurum olan üniversitedir. Hoca sistemin her elemanını üniversite için tek tek tanımladı.

### 6.1 Girdiler ve çıktılar

- **Girdiler:** yeni gelen öğrenciler, yeni katılan öğretim elemanları ve görevliler. Bunların hepsi dış ortamdan sisteme girer.
- **Çıktılar:** mezunlar ve çalışanların ürettiği yayınlar.

### 6.2 Elemanlar ve hiyerarşik alt sistemler

Elemanlar öğrenciler, öğretim üyeleri ve idari çalışanlardır. Bu elemanlar belirli bir hiyerarşi içinde, alt sistemler dahilinde yerleşmiştir. Üniversitede alt sistemler şöyle sıralanır: üniversite yönetimi, fakülteler, fakültelerin altında bölümler, bölümlerin altında ana bilim dalları.

Elemanlar bu hiyerarşide bir yere yerleşmiştir. Bir öğrenci sistemin elemanıdır, ama hangi fakültenin hangi bölümünün öğrencisi olduğu da onun hiyerarşideki yeridir; öğrenci için bu iki kademede kalır. Öğretim üyesi için hiyerarşi ana bilim dalına kadar iner: hangi fakültenin, hangi bölümün, hangi ana bilim dalının öğretim üyesi. İdari personel de hangi fakültenin, hangi bölümün ya da hangi idari birimin personeli olduğuyla tanımlanır.

Bunlar canlı elemanlardır. Sistemde sınıflar, odalar ve laboratuvarlar gibi cansız elemanlar da vardır.

### 6.3 İç ilişkiler

Bütün bu elemanlar arasında tanımlanmış ilişkiler vardır. Üniversitede bu ilişkileri üniversite yönetmelikleri belirler; başka bir kurumda o kurumun işleyişini ve görev tanımlarını düzenleyen mevzuat ve yönetmelikler bu rolü üstlenir. Örneğin öğrenci ile ders, öğrenci ile öğretim üyesi, öğrenci ile bölüm arasındaki ilişkiler lisans yönetmeliği ve yüksek lisans yönetmeliği gibi yönetmeliklerle düzenlenir.

### 6.4 Çevre

Dışarıdaki ilişkilere bakıldığında mezunlar ve mezunların çalıştığı yerler dolaylı ilişkiler sayılabilir. Sistemin çevresini oluşturan diğer unsurlar şunlardır:

- mezunların çalıştığı kurumlar,
- öğrencilerin aileleri,
- öğrencilerin staj yaptığı yerler,
- yürütülen projeler ve bu projeler kapsamında ilişki kurulan diğer üniversiteler,
- üniversitenin genel kurallarını aldığı Yükseköğretim Kurulu,
- öğrencinin geldiği liseler.

Liselerin neden çevreye dahil olduğunu hoca şöyle açıkladı: kendi müfredatımızı oluştururken gelen öğrencinin ne bildiğini ve ne bilmediğini belirlemek için liselerde okutulan dersleri bilmemiz gerekir. Demek ki öğrencinin geldiği kurumlar da sistemin ortamındaki ilişkili kurumlardır.

### 6.5 Alt sistemlerin görevleri

Alt sistemlere doğru inildikçe her birinin fonksiyonları ve özellikleri de sayılabilmelidir:

- **Fakülte:** bütün bölümlerin laboratuvarlarını ve derslerini düzgün yürütebilmesi, araştırmalarını yapabilmesi için gerekli olanakları eşit şekilde sağlamak; üniversite yönetimiyle bölümler arasındaki ilişkiyi ve iletişimi sağlamak.
- **Bölüm:** fakülteye karşı bu hedeflere uygun olarak laboratuvarların bakımını yapmak, ders programlarını hazırlamak, yeni ders açılması için kararlar vermek.

Alt sistemler arasındaki sınırlar, sistemin girdi ve çıktıları ve alt sistemler arasındaki ilişkiler de tanımlanmalıdır. Alt sistemler işlevsel bir bütünlük oluşturmalı, ama ayrı ayrı izlenebilir, yani ayrıştırılabilir olmalıdır.

## 7. Sistem Sınırı ve Otomasyon Sınırı

Hoca "Figure 1-4: The system boundary and the automation boundary" şeklini gösterdi (ekrandan, 01:00:00). Şekil iç içe üç kutudan oluşur:

```text
+-------------------------------------------------------+
| Environment Surrounding the System (sistemin çevresi) |
|                                                       |
|  System boundary --> +------------------------------+ |
|                      | Manual Part of the System    | |
|                      | (sistemin elle yürüyen kısmı)| |
|                      |                              | |
|  Automation -------> |   +----------------------+   | |
|  boundary            |   | Automated Part of    |   | |
|                      |   | the System           |   | |
|                      |   +----------------------+   | |
|                      +------------------------------+ |
+-------------------------------------------------------+
```

En dışta sistemi çevreleyen ortam vardır. Sistem sınırı sistemi bu ortamdan ayırır. Sistemin içinde elle yürüyen bir kısım ve onun içinde, otomasyon sınırıyla ayrılmış otomatik kısım bulunur.

Üniversite örneğinde sistemin bir parçası bir otomasyon sistemi, yani bilgi sistemidir. Personel sistemi, öğrenci sistemi ve evrak takip sistemi aynı yönetim bilgi sistemi içinde birbiriyle haberleşerek çalışıyorsa, bütün kurumun tek bir otomasyon sistemi vardır ve bu sistemler onun parçalarıdır. Hepsi ayrı ayrı çalışıyorsa onları birbiriyle konuşturmak gerekir. Bir bilgiyi bulmak için araya belge gidip geliyorsa, bu sistem bütün kurumu otomatikleştiren bir bilgi sistemi değildir.

Sistem sınırları, sistemle ortamı ayıran sınırlardır ve ortamdan gelen girdileri de belirler. Bu yüzden ortamla ilişkileri doğru tanımlamak gerekir; liselerden gelen öğrencinin bilgisini bilmek bunun örneğidir (Bölüm 6.4).

## 8. Sistemin Amacı

Hoca üniversite örneğine geri döndü: girdiler, çıktılar, alt ve üst sistemler (bölüm, ana bilim dalı, fakülte) ve iç ilişkiler (yönetmelikler) tanımlandı; ama bir sistem olmak için gereken **amaç** henüz tanımlanmadı. Sistem bir amaç çerçevesinde çalışır.

Üniversitenin amacı iyi öğrenciler yetiştirmektir. Bunun ölçüleri mezunların ne kadar iyi işlerde çalıştığı, lisansüstü sınavlarında ne kadar başarılı olduğu gibi değerlerdir. Üniversite çalışanlarının çıkardığı yayınların sayıca fazla ve nitelikli olması da bir ölçüdür; bunlar aynı zamanda çıktılardır. Kısacası ilk hedef iyi mezunlar yetiştirmektir.

Son yıllarda bütün kurumlardan vizyon ve misyonlarını ve hedeflerini yazmaları istenir. Kurum bir vizyon belirler, ardından o vizyonu gerçekleştirmek için hangi hedefleri sağlaması gerektiğini yazar. Sistem hangi kurumsa, kendi hedefini bu şekilde oluşturur.

## 9. Sistem Düşüncesi

Karşımıza çıkan bir kurumu ya da problemi incelerken izlenecek kurallar "Systems Thinking" slaytında listelenmiştir (ekrandan, 01:10:00):

- Being able to identify something as a system: bir şeyi sistem olarak tanımlayabilmek.
- Involves being able to identify subsystems: alt sistemlerini belirleyebilmek.
- Identifying system characteristics and functions: sistemin özelliklerini ve fonksiyonlarını belirlemek.
- Identifying where the boundaries are (or should be): sınırların nerede olduğunu (ya da nerede olması gerektiğini) belirlemek.
- Identifying inputs and outputs to systems: sistemin girdilerini ve çıktılarını belirlemek.
- Identifying relationships among subsystems: alt sistemler arasındaki ilişkileri belirlemek.

Hoca, alt sistemlere doğru ilerledikçe her birinin fonksiyonlarının ve özelliklerinin de sayılabilmesi gerektiğini ekledi (fakülte ve bölüm örneği için Bölüm 6.5).

> **Hocanın vurgusu:** Slaytta yazılı olmasa da sistem düşüncesine eklenmesi gereken önemli bir madde daha vardır: çıktıların iyileştirilmesi, yani geri besleme.

## 10. Geri Besleme

Sistemin çıktılarını iyileştirmek için önce çıktıları değerlendirmek gerekir. Değerlendirmede bulunan eksiklikleri düzeltmek için ya işlemler, yani sistemin fonksiyonları değiştirilir ya da girdiler değiştirilir. Buna **geri besleme** denir. Sistem düşüncesi kapsamında bütün sistemlerin geri beslemeli olması gerekir.

Hoca geri beslemeyi yine üniversite üzerinden örnekledi. Mühendislik programları kalite açısından bir akreditasyon (MÜDEK) değerlendirmesinden geçer. Bu süreçte bölüm kendi iç değerlendirmesini yapar: bölümdeki elemanlar, öğrenciler, öğretim üyeleri ve dersler değerlendirilir. "Biz bunu iyi yapıyoruz" demek yetmez, bunun belgelenmesi gerekir.

Paydaşlardan görüş alınır. Paydaşlar şunlardır: öğrencilerin staj yaptığı yerler, mezunların çalıştığı yerler, kendini hangi konuda eksik gördüğünü söyleyen eski mezunlar ve diğer üniversitelerin öğrencilerine göre kendini nerede eksik ya da güçlü gördüğünü söyleyen stajyer öğrenciler. Örneğin işbirliği yapılan kurumlardan test konusunda ayrı bir seçmeli ders isteği geldi; bunun üzerine daha önce yüksek lisansta verilen yazılım kalite süreçleri dersi lisansa da seçmeli ders olarak kondu. Diğer derslerde de benzer eklemeler ve çıkarmalar yapıldı.

Bu değerlendirmelere göre işleyiş değiştirilir, ders eklenir ya da çıkarılır. Bir ana bilim dalında ya da konuda eksik olunduğu görülürse o konuda yeni öğretim elemanı alınır. Lisansüstü öğrenci alımında belirli konularda çalışacak öğrenci aranması da aynı türden bir değişikliktir.

Tanım olarak geri besleme: elde edilen çıktıların değerlendirilmesi ve bu değerlendirmenin sonuçlarına göre girdilerin ya da sistemdeki fonksiyonların ve elemanların değiştirilmesidir.

## 11. Bütünleşik Bir İşletme Sistemi

Hoca daha yukarıdan bakmak için bir işletme sistemini örnek verdi. İşletmede bir **müşteri destek sistemi** vardır; bu tür uygulamalar CRM olarak bilinir. Müşteri destek sistemi müşteri bilgilerini tutar, gerekli değişiklikleri yapar ve müşterinin verdiği siparişleri kaydeder.

Bu sistemin işini yapabilmesi için başka alt sistemlerle ilişkili olması gerekir:

- Müşterinin verdiği siparişler için **üretim (manufacturing) sistemiyle** ilişkili olmalıdır.
- **Envanter yönetim sistemi** hem üretim sistemiyle hem müşteri destek sistemiyle ilişkili olmak zorundadır. Müşteri sipariş verecektir, ama ürün envanterde var mı yok mu, bu bilgi envanterden gelir.

<!-- BELİRSİZ: Bu örneğin şekli (slayt 8) karelerde yalnız küçük önizleme olarak görünüyor; alt sistemler arasındaki okların yönü okunamadı. -->

## 12. Bilgi Sistemi ve Tipleri

**Bilgi sistemi**, gerekli bilgiyi çıktı olarak sağlamak üzere veriyi toplamak, işlemek ve saklamak için bütün iç bileşenlerin bir arada çalıştığı sistemdir.

Bilgi sistemleri farklı tiplerde olabilir. Hoca bunları kısaca tanıttı ve bir sonraki derste ayrıntılandıracağını söyledi.

### 12.1 İşlem işleme sistemi (TPS)

Transaction Processing System temel bir işi yapar. Örnek: yalnızca bordro hazırlayan bir sistem ya da ATM'den yalnızca para çekme işlemi. Tek bir işi yapan sistemdir.

### 12.2 Yönetim bilgi sistemi (MIS)

Management Information System, işlem işleme sistemlerinin bir arada çalışmasını sağlar ve gerektiğinde kurumun tepe yönetimine doğru birbiriyle karşılaştırılabilir, özetlenmiş bilgi sunar; raporlama da yapar. Örneğin bir muhasebe bilgi sistemi bir yönetim bilgi sistemidir. Altında pek çok alt uygulama vardır; bordro sistemi de muhasebe bilgi sisteminin alt programlarından biridir.

<!-- BELİRSİZ: TPS ve MIS tanımlarının bulunduğu slayt 9 karelerde okunamadı; tanımlar altyazıdan kuruldu. -->

### 12.3 Üst yönetim bilgi sistemi (EIS)

Executive Information System üst yönetime doğrudan bilgi verir. Slayttaki tanım (ekrandan, 01:20:00): yöneticilerin stratejik planlamada kullanacağı bilgiyi sağlar; bu bilgi kurumun veritabanından ya da borsa raporları gibi dış kaynaklardan gelebilir.

### 12.4 Karar destek sistemi (DSS)

Slayttaki tanım (ekrandan, 01:20:00): Decision Support System insanın karar vermesini destekler ve kullanıcıların mevcut seçeneklerin ya da kararların olası etkisini incelemesine izin verir; örneğin "ne olur eğer" (what if) sorusu sorulabilir. "Uzman sistemler" ya da "bilgi tabanlı" sistemlerle yakından ilişkilidir.

Hoca bunun çok geniş bir kategori olduğunu söyledi: bir Excel tablosu da karar destek sistemi olarak çalışabilir; bir uzman sistem ya da bilgi tabanlı bir iş sistemi de. Senaryolar yaratıp bu senaryolara göre en uygun hareketi seçmek gerektiğinde karar destek sistemleri kullanılır.

## 13. Sistem Analisti ve Becerileri

**Sistem analisti** denince, küçük firmalarda bazen proje yöneticisi ya da teknik destek ekibi; büyük firmalarda ise iş analistlerinden sonra işin analizini ve tasarımını yapıp yazılım mühendislerine aktaracak seviyede çalışan kişiler kastedilir. Sistem analistinin üç beceri alanı vardır.

### 13.1 Teknik bilgi ve beceriler

Analist programlama dillerini ve genel bilgisayar bilgisini bilmelidir. Örneğin küçük bir firmaya anahtar teslim bir sistem kurulurken hangi ağ uygulamasının seçileceğine karar verebilecek kadar ağdan ve iletişimden, ayrıca veritabanı yönetim sistemlerinden ve işletim sistemlerinden anlamalıdır. Yazılımın hazırlanması için kullanılacak araçlara (tool) da karar verebilmelidir.

<!-- BELİRSİZ: Teknik ve işletme becerilerinin listelendiği slayt 11 ve 12 karelerde okunamadı; bu iki alt bölüm altyazıdan kuruldu. -->

### 13.2 İşletme bilgisi ve becerileri

Bir işletmeye yazılım geliştiriyorsak organizasyonun nasıl çalıştığını, yapısını, nasıl yönetildiğini ve hangi kademedekilerin hangi işi yaptığını bilmek gerekir. Her uygulamada aktivitelerin ve aktörlerin neler olduğu bilinmelidir. Ayrıca organizasyonun ne olduğu, bu sistemde başarılı olmanın ne demek olduğu, stratejileri, planları ve kurum kültürü de bilinmelidir. Kısacası analist kurum ya da şirket hakkında bu anlamda bilgi sahibi olmalıdır.

### 13.3 İnsan bilgisi ve becerileri

Slayttaki maddeler (ekrandan, 01:25:00):

- En önemli kişilerarası beceri: başkalarıyla açık ve etkili **iletişim** kurmak.
- Analistler başkalarıyla (ekip üyeleri, müşteriler vb.) ekip halinde çalıştığı için insanları anlamalıdır:
  - insanların nasıl düşündüğü,
  - nasıl öğrendiği,
  - değişikliğe nasıl tepki verdiği,
  - nasıl iletişim kurduğu,
  - nasıl çalıştığı ("aktiviteler" ve "aktörler").
- Diğer alanlar:
  - görüşme (interview), dinleme ve gözlem becerisi,
  - iyi yazılı ve sözlü sunum,
  - ekip içinde çalışabilmek.

Hoca bunları şöyle açtı: analist mutlaka başka kişilerle çalışacağı için etkin iletişim kurmak zorundadır; ekip üyelerinin görevleri sırasında birbiriyle iletişim kurmasını da sağlamalıdır. Normalde bu işleri proje yöneticisi yapar, ama küçük bir kurumda sistem analisti görevindeki kişi de yapacaktır. Kullanıcılar için insanların değişikliğe tepkisini bilmek çok önemlidir; çünkü yeni sistemle kullanıcıların yaptığı işi değiştiriyoruz, onlar da buna tepki veriyor. Analist bunu önceden kestirip ona göre davranmalıdır. Müşteriyle ve ürün alınan firmalarla yazılı, sözlü ve raporlarla nasıl iletişim kurulacağını bilmelidir. Görüşme, dinleme ve gözlem, sistem analizi aşamasında bilgi toplamanın yöntemleridir; bunlar ileride ayrıca işlenecektir.

## 14. Derste Tekrar: Sistem Yapısının Özeti

Dersin sonunda bir öğrenci kısa bir özet istedi; hoca sistem yapısını şekil üzerinden yeniden özetledi.

Genel olarak sistem; bir hedefi olan, elemanları olan, bu elemanların birbiriyle ilişkili olduğu, çevresinden sınırlarla ayrılan, bu çevreden girdiler alan ve elemanlar arasındaki iç ilişkiler ile fonksiyonların yerine getirilmesiyle elde edilen çıktıları çevresine üreten bir yapıdır.

Bu tanımın sağlaması gereken kurallar şunlardır:

1. Sistemin mutlaka bir hedefi olmalıdır.
2. Sistemin dışarıda bir çevresi olmalı ve bu çevreden sınırlarla ayrılmış olmalıdır.
3. Sistem çevreden girdiler almalı, dışarıya çıktılar üretmelidir.
4. Çıktıları üretebilmek için elemanları arasında iyi düzenlenmiş iç ilişkiler olmalıdır.
5. Sistem alt sistemlere ayrılmalı ve bu alt sistemler hiyerarşik olarak düzenlenmelidir; alt sistemlerle iç ilişkiler tanımlanmalıdır (üniversitede fakülteler, bölümler, ana bilim dalları; elemanlar olarak öğrenciler, öğretim üyeleri, sınıflar, dersler).
6. Sistemde gerekirse otomasyon vardır ve otomasyon sınırları içinde nelerin yapılacağı tanımlanmış olmalıdır.
7. En önemlisi, sistem yapısı içinde mutlaka geri besleme bulunmalıdır.

Hoca son olarak insanı da bir sistem örneği olarak verdi. İnsanın amacı hayatta kalmaktır. Bu amaçla çevreyle ilişkisini düzenler: üşürse palto giyer, hava ısınınca paltoyu çıkarır, sağlığına dikkat eder. Elemanları vardır ve bu elemanlar arasında çok ince ilişkiler vardır. Sistemin canlı olması da gerekmez; üniversite örneğinde olduğu gibi canlı ve cansız unsurlar, kurallar ve insanlar arasındaki ilişkiler bir arada bulunabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:03:44): Üniversite örneğinde girdiler, çıktılar, alt sistemler ve iç ilişkiler tanımlandı. Bir sistem olmak için eksik kalan nedir ve üniversite için bu nedir?

> **Çözüm (derste verildi):** Eksik kalan sistemin amacıdır. Üniversitenin amacı iyi mezunlar yetiştirmektir; bunun ölçüleri mezunların çalıştığı işlerin niteliği, lisansüstü sınavlarındaki başarıları ve çalışanların yayınlarının sayısı ve niteliğidir.

**Soru 2** (derste sözlü, 01:09:03): Üniversitede sistemin alt sistemleri ve elemanları arasındaki ilişkileri ne ile sağlıyoruz?

> **Çözüm (derste verildi):** Yönetmeliklerle. Öğrenci ile ders, öğrenci ile öğretim üyesi, öğrenci ile bölüm arasındaki ilişkiler lisans yönetmeliği, yüksek lisans yönetmeliği gibi yönetmeliklerle düzenlenir.

**Soru 3** (derste sözlü, 01:32:21): Geri besleme nedir?

> **Çözüm (derste verildi):** Bir öğrenci geri beslemeyi "bizim sisteme yaptığımız etki sonucunda sistemin bize gösterdiği tepki" olarak tanımladı. Hoca daha kesin tanımı isteyince başka bir öğrenci "çıktıların değerlendirilip bu değerlendirme sonucunda tespit edilen eksikliklerin düzeltilmesi" dedi ve hoca bunu onayladı: çıktılar değerlendirilir, eksiklik ya da düzeltme gereken yer görülürse girdiler ya da iç işlemler yeniden düzenlenerek iyileştirme yapılır.

**Soru 4** (derste sözlü, 01:33:58): Çevrenizden bir şeyi sistem olarak seçin. Üniversite örneğinde olduğu gibi amacını, girdisini, çıktısını, elemanlarını (alt sistemlerini), iç ilişkilerini ve geri beslemesini anlatın ve bir şekil içinde çizin.

> **Çözüm (derste verilmedi):** Örnek olarak bir halk kütüphanesi seçilebilir. Amaç: topluma bilgiye erişim sağlamak. Sınır ve çevre: kütüphanenin kendisi sistemdir; okuyucular, yayınevleri, bağlı olduğu belediye ve diğer kütüphaneler çevredir. Girdiler: satın alınan ya da bağışlanan kitaplar, yeni üyeler, bütçe. Çıktılar: ödünç verilen kitaplar, verilen hizmet (okuma salonu, etkinlikler), istatistik raporları. Alt sistemler: sağlama (kitap alımı), kataloglama, ödünç verme, üyelik, okuma salonu. Elemanlar: kütüphaneciler, üyeler, kitaplar, raflar, bilgisayarlar. İç ilişkiler: kütüphane yönetmeliği ve ödünç verme kuralları (süre, gecikme cezası). Geri besleme: en çok istenen ama bulunamayan kitapların ve üye anketlerinin değerlendirilip alım listesinin (girdinin) ya da çalışma saatlerinin (işleyişin) değiştirilmesi. Otomasyon sınırı: kataloglama ve ödünç verme bir bilgi sistemiyle yürütülürken kitap bağışı kabulü elle yürüyebilir.

## Dersin Toparlaması

Bu ilk derste dersin bakış açısı kuruldu: küçük problemler için program yazmaktan, bir sistemi baştan sona analiz edip ona uygun bilgi sistemini tasarlamaya geçiliyor. Sistem kavramı amaç, sınır, girdi, çıktı, alt sistemler, iç ilişkiler ve geri besleme üzerinden tanımlandı; üniversite örneğinde bu elemanların hepsi tek tek gösterildi. Sistem sınırı ile otomasyon sınırının farkı, sistem düşüncesinin adımları ve her sistemin geri beslemeli olması gerektiği vurgulandı. Bilgi sistemi tanımlandı ve dört tipi (TPS, MIS, EIS, DSS) kısaca tanıtıldı. Son olarak sistem analistinin teknik, işletme ve insan becerileri ele alındı; bunlar arasında en önemlisinin iletişim olduğu belirtildi.

Sonraki derste bilgi sistemi tipleri ayrıntılı işlenecek, öğrencilerin hazırladığı sistem örnekleri üzerinde durulacak ve bilgi sistemi geliştirme adımlarına başlanacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
