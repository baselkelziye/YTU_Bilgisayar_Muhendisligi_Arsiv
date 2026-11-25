# Ders 6 Genişletilmiş Notu: Proje Planlama: İş Kırılım Yapısı, Etkinlik Bağımlılıkları ve MS Project ile Gantt Diyagramı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Aşamaların Tekrarı: Projeyi Anlama ve Tanımlama
- 2. Süreç Modelinin Seçimi
- 3. Proje Planlamanın On Beş Etkinliği
- 4. Kabuller, Kısıtlar ve Riskler
- 5. Kalite Planı
- 6. Ayrıntılı Etkinlik Listesi
- 7. İş Kırılım Yapısı (WBS)
- 8. Etkinlikler Arası Bağımlılıklar
- 9. Tahmin ve Görev Ataması
- 10. MS Project ile Gantt Grafiği Uygulaması
- 11. Kritik Görevler, Takvim, Kaynak Ücreti ve PERT Diyagramı
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Aşamaların Tekrarı: Projeyi Anlama ve Tanımlama

Ders, önceki haftalarda izlenen *Information Systems Project Management* kitabından devam etti. Hoca kitabın planlama bölümünün başındaki genel bakış şemasını açtı (ekrandan, 00:05:00). Şemada proje yönetimi üst üste kutularla gösterilir: projeyi anlama (Understanding the Project), projeyi tanımlama (Defining the Project) ve projeyi planlama (Planning the Project). Ardından projenin izlenmesi ve kontrolü gelir. Her kutunun yanında, proje yöneticisinin o aşamayı bitirdiğini anlamak için kendine soracağı sorular vardır.

### 1.1 Projeyi anlama

Ekrandaki sorular şunlardır (ekrandan, 00:10:00):

- Projenin gerekçesini (justification) anlıyor muyum?
- Projenin arka planını (background) anlıyor muyum? Proje, gerçekleştirilecek işin tarihçesine nasıl dayanıyor?
- Proje politikalarını anlıyor muyum?
- Oyuncuların kim olduğunu ve üstlenecekleri rolleri anlıyor muyum?
- Müşterinin önceliklerini anlıyor muyum?

Hoca müşterinin önceliğini önceki derste görülen başarı göstergeleriyle bağladı: bütçe, kapsam ve zaman. Anlama aşamasında bunlardan hangisinin müşteri için en önemli olduğu belirlenmiş olmalıdır.

### 1.2 Projeyi tanımlama

Tanımlama aşamasının soruları şunlardır (ekrandan, 00:10:00):

- Teslim edilecekleri (deliverables) tanımladım mı?
- Kapsamı, hem sistem hem proje kapsamını, belirledim mi?
- Teslim edileceklerin nasıl gözden geçirilip onaylanacağını belirledim mi?
- Müşteri organizasyonunun yapısını tanımladım mı?

Teslim edilecekler denince ilk akla kod gelir. Ancak yazılım geliştirme sürecinin farklı aşamalarında üretilen birçok belge, anlaşma ve sözleşme de teslim edilecekler arasında olabilir. Koddan sonra ilk akla gelenler SRS (yazılım gereksinim belirtimi) belgesi, tasarım belgesi, gereksinim belgesi, hangi test örneklerinin yapıldığı, planlama aşamasının proje planı ve risk planıdır. Proje daha resmî bir projeyse, örneğin farklı kurumlarla ihaleye girilmişse, teslim edileceklerin sayısı artar. İş hayatındaki rutin projelerde ise birkaç belgeyle sınırlı kalır: veritabanı tanımları, gereksinim tanımları, yapılan testler ve en önemlisi kodun verilip verilmeyeceği. Bunlar, yazılımın teslimden sonra da yaşamasını sağlayan belgelerdir.

Teslim edilecekler belirlendikten sonra sistemin alanı tanımlanır. Bu alandaki terminolojiyi ve alanın yapısını öğrenmek önemlidir. Hoca daha önce verdiği hastane bilgi sistemi örneğini hatırlattı: önce bütün çerçeve anlaşılır, o alandaki insanlardan bilgi alırken bilinmesi gereken terimler öğrenilir, sınırlar ve yapılan işler belirlenir. Sonra kullanıcının ne istediği, yani projenin kapsamı ortaya konur ve teslim edileceklerin nasıl gözden geçirileceği belirlenir. Ayrıca organizasyonun yapısı tanımlanır.

Tanımlama aşamasının en önemli konularından biri değişiklik yönetimidir. Müşteri teslime kadar değişiklik isteyebilir ve her değişikliğin bir maliyeti olur. Bu değişikliklerin nasıl anlaşılacağı ve kayıt altına alınacağı kuralları daha tanımlama aşamasında belirlenir.

## 2. Süreç Modelinin Seçimi

Planlamaya geçmeden önce projede hangi yazılım geliştirme süreç modelinin kullanılacağı belirlenir. Dersin başında adları sayılan modeller şunlardır: şelale (waterfall), spiral model, RAD, prototip modeli ve birleşik süreç (Unified Process). Bunların yanında Scrum ve XP gibi çevik (agile) modeller vardır. Hangisinin uygun olduğu ya da bunların hibrit kullanılıp kullanılamayacağı tanımlama aşamasında belirlenir.

Seçim üç şeye göre yapılır: ekibe hangisinin uygun olduğu, kurumun yapısına hangisinin uygun olduğu ve projenin yapısına hangisinin uygun olduğu. Hoca şu örneği verdi: hep kullanılan bir yazılım uygulaması yenilenmek isteniyorsa şelale modeli de uygun olabilir. Çevik yöntemlerde amaç müşterinin isteklerini hızlı anlamaktır; ama müşteri zaten kullandığı bir sistemi anlatıyorsa isteklerini anlatması daha kolaydır.

## 3. Proje Planlamanın On Beş Etkinliği

Kitap, planlama bölümünü "planlamamak başarısız olmayı planlamaktır" sözünü eleştirerek açar: yalnızca bir plan yapmak başarıyı garanti etmez, projenin gerçekliğinden kopuk bir plan kontrol yanılsaması verdiği için hiç plan yapmamaktan kötüdür (ekrandan, 00:25:00). Kitaba göre bir projeyi planlamak şu on beş etkinlikten oluşur (ekrandan, 00:25:00):

1. Proje risklerini tanımlamak ve onları azaltacak eylemleri belirlemek
2. Proje kabullerini (varsayımlarını) ve kısıtlarını listelemek
3. Kalitenin nasıl yönetileceğini belirlemek
4. Etkinliklerin ve maliyet bileşenlerinin listesini oluşturmak
5. Etkinlikler arasındaki bağımlılıkları kurmak
6. İş gücünü ve maliyetleri tahmin etmek
7. Zaman çizelgesini ve kilometre taşlarını hazırlamak
8. Proje kaynaklarını atamak ve seviyelemek
9. Bütçeyi ve çizelgeyi müşteri gereksinimleriyle uyumlamak
10. Proje bütçesini hazırlamak
11. Proje evrakını yönetmek
12. Uygulamaya geçişi planlamak
13. Tamamlamayı planlamak
14. İletişimi planlamak
15. Proje planını yazmak

Hoca bu listeyi şöyle açıkladı: riskler, kabuller ve kısıtlar tanımlanır; kalitenin nasıl yönetileceği belirlenir; etkinlikler listelenir ve her birinin kabaca kaç gün ve kaç adam-ay süreceği çıkarılır; etkinlikler arasındaki bağlılıklar belirlenir; iş gücü ve maliyet tahminleri yapılır; kilometre taşları işaretlenir ve kaynak seviyelemesi yapılır. Dördüncü ile sekizinci adımlar arasındaki işler bir yazılım paketiyle kolaylaştırılabilir. Bu da proje adımlarını ve adımlar arasındaki ilişkileri gösteren Gantt diyagramının ve etkinlik ilişkilerini daha iyi gösteren PERT diyagramının oluşturulmasıdır. Bunlardan sonra bütçeden söz edilebilir. Hangi modellerin ve belgelerin oluşturulduğu yönetilir, uygulamaya geçiş ve tamamlama aşamalarında nasıl çalışılacağı planlanır. İletişim planı ise ekibin çalışmasından proje yöneticisinin nasıl bilgi alacağını ve görev dağılımını nasıl yapacağını tanımlar. En son plan yazılır.

## 4. Kabuller, Kısıtlar ve Riskler

Kitaptaki sıraya göre ilk iş riskleri belirtmektir. Hoca, risklerin ayrıntısını sonraki derslere bırakıp önce kabuller ve kısıtlar üzerinde durdu.

> **Hocanın vurgusu:** Riskler, kabuller ve kısıtlar birbirine çok benzer; maddeleri neredeyse aynı olabilir. Fark kavramdadır.

**Kabuller (varsayımlar):** Yazılımı geliştirirken olumlu olarak "bu böyledir" diye kabul ederek başladığımız şeylerdir. İki türü vardır:

- **Proje (süreç) kabulleri:** Projenin yürütülmesiyle ilgilidir. Örnekler: çalışanlardan hiçbirinin projeden ayrılmayacağı kabul edilir; çalışanların proje bitene kadar rapor ya da izin almayacağı varsayılarak iş gücü analizi yapılır.
- **Teknik kabuller:** Örneğin her çalışanın kullanılmasına karar verilen programlama dilini ve veritabanı yönetim sistemini yeterli seviyede bildiği kabul edilir; bunun için ayrıca bir eğitim süresi ayrılmaz.

**Kısıtlar:** Planın dayandığı sınırlardır. Örnek: projede sistem analisti süresi için bir kısıt vardır; belirli bir dönemde yalnız bir sistem analisti projede çalışabilecek, diğerleri izinde olacaktır.

**Riskler:** Kabuller ve kısıtlar anlaşıldıktan sonra riskler daha iyi anlaşılır. Risk, şu anda sorun olmayan ama gelecekte sorun olabilecek durumdur. Risklere karşı nasıl bir plan geliştirileceğinin belirtilmesi de risk tanımının parçasıdır.

> **Ek bilgi (derste anlatılmadı):** Bir kabul ile risk arasındaki bağ şöyle düşünülebilir: "Hiçbir çalışan ayrılmayacak" bir kabuldür; "kilit bir çalışanın ayrılması" ise bu kabulün tutmaması durumudur ve risk listesinde yer alır. Bu yüzden kabuller listesi risk tanımlamada iyi bir başlangıç noktasıdır.

## 5. Kalite Planı

Proje planında bir de kalite planı bulunur. Kalite planı, kalite yönetimi için nasıl bir yol izleneceğini tanımlar. Hoca, önceki dönemin kalite dersinde gösterilen şemayı hatırlattı: ortada bir dikdörtgen ve çevresinde kaliteyi sağlamak için yapılanlar. Yazılım geliştirme sürecinde kalite için yapılanların başında gözden geçirme (review) gelir.

### 5.1 Gözden geçirme ekibi

Kalite planında gözden geçirmenin kurallarını belirleriz: Proje gözden geçirmesini kimler yapacak? Müşteri grubunda kimler olacak? Müşteri sürekli ekibin içinde olacak mı, yani çevik bir yöntem mi kullanılıyor?

### 5.2 Gözden geçirmenin zamanlaması

Gözden geçirme ekibi belirlendikten sonra gözden geçirmenin hangi dönemlerde yapılacağı belirlenir. İki seçenek vardır:

- **Takvime bağlı:** Zaman planı içinde üç ayda ya da altı ayda bir gözden geçirme.
- **Kilometre taşlarına bağlı:** Yazılım geliştirme sürecinin adımlarına göre. Örneğin gereksinim analizi bittiğinde bir gözden geçirme yapılır. Tasarımda ön tasarım (genel tasarım) bittiğinde bir gözden geçirme yapılır. Ayrıntılı tasarım daha alt başlıklara ayrılabilir: veritabanı tasarımı bittiğinde ve program tasarımı bittiğinde gözden geçirme yapılır.

> **Hocanın vurgusu:** Gözden geçirmelerin zamana mı yoksa süreç adımlarına mı bağlı olduğunu, yani kilometre taşlarının nasıl oluşturulduğunu kalite planında belirtmek gerekir.

### 5.3 Kitaba göre kalite planının içeriği

Hoca kitapta kalite planına ayrılan bölümü kısaca gösterdi: gözden geçirmelerin nasıl yapılacağı, hangi hataların hangi maliyetleri getireceği (örneğin programda bir hata varsa birim testinin yeniden yapılması gerekir), bakım sırasında dikkat edilecekler, kalitenin ölçülmesi, gözden geçirme planının oluşturulması, walkthrough türü gözden geçirmenin daha uygun olduğu ve versiyon kontrolünün (konfigürasyon yönetiminin) yapılması. Bu konular kalite yönetimi dersiyle kesişir. Walkthrough kavramı başka bir derste görülmüştü.

<!-- BELİRSİZ: Kalite planı bölümünde altyazıda "D-BOK" diye geçen terim anlaşılamadı (büyük olasılıkla hata ayıklama, debug). -->

## 6. Ayrıntılı Etkinlik Listesi

Proje planındaki dördüncü madde, projedeki etkinliklerin ayrıntılı bir listesinin çıkarılmasıdır. Yazılım geliştirme projesinde etkinlikler, yazılım geliştirme sürecindeki adımlardır.

### 6.1 Gereksinim analizinin alt adımları

Gereksinim analizi bir üst başlıktır. En özet hâliyle altında üç temel adım vardır. Pressman'ın ya da Sommerville'in yazılım mühendisliği kitaplarında bu daha ayrıntılı gösterilir; Pressman'ın kitabında yedi alt adım olarak görülür:

1. **Başlangıç ve fizibilite:** Projenin yapılabilirliği.
2. **Bilgi toplama:** Ayrıntılı bilginin toplandığı aşama.
3. **Ayrıntılandırma (elaboration):** Modelleme; modeli oluşturacak diyagramların hazırlanması.
4. **Pazarlık (negotiation):** Yazılımı geliştirecek taraf ile müşteri tarafı vardır. Müşteri tarafında farklı çalışanlar ve farklı departmanlar bulunur; her birinin işi farklı olabilir ve istekleri arasında çelişkiler çıkabilir. Bu çelişkiler giderilir. Ayrıca müşterinin istekleri geliştirici açısından mantıklı ve yapılabilir mi, bu anlaşılıp bir sonuca varılır. Sistem analisti bu yüzden geliştiricilerle müşteri arasında köprü kuran kişi olarak tanımlanır.
5. **SRS belgesinin oluşturulması.**
6. **Doğrulama (validation):** SRS belgesi üzerinde kontrol.
7. **Gereksinim yönetimi:** Gereksinimler analizde tanımlanır ama yazılım geliştirme sürdüğü sürece takip edilir; modelde karşılanıp karşılanmadıkları izlenir.

### 6.2 Tasarım ve süreç modeline bağlılık

Gereksinim analizinden sonra tasarım aşaması gelir. Burada da süreç modeline uygun bir yapı kurulur. Süreç çevikse bir adımın bitip diğerinin başlaması beklenmez; iş küçük parçalara bölünür, her parça için analiz, tasarım ve gerçekleştirme yapılıp birleştirilir.

Dolayısıyla ayrıntılı etkinlik listesi hem yazılım geliştirme süreç modeline hem de işin ne kadar ayrıntılı yapılacağına bağlıdır. Ama etkinlikler her zaman bir hiyerarşi, yani ağaç yapısı içinde oluşturulur. Temel adımlar planlama, gereksinim analizi, tasarım, gerçekleştirme ve testtir. Gereksinim analizinin altında üç ya da yedi adım, tasarımın altında iki temel adım ve onların altında iki üç başlık bulunur.

Bu yapı kurulduktan sonra şu sorular cevaplanır: Hangi etkinlikler birbirine bağlıdır? Hangi etkinlik bitince hangisi başlar, hangileri birlikte yürür? Tahmini iş gücü gereksinimi (adam-ay) nedir? Kaynaklar nelerdir? Kilometre taşlarında neler tamamlanır, kaynak seviyelemesi nasıl yapılır? İş listesi nasıl takip edilir, bütçe nasıl yapılır?

## 7. İş Kırılım Yapısı (WBS)

### 7.1 Tanım

Kitaba göre planlama, neyin ne zaman yapılacağını belirleme eylemidir. İlerlemeyi izleyebilmek için proje küçük ve yönetilebilir etkinliklere bölünmelidir. Bunun sistematik yolu hiyerarşik ayrıştırmadır (hierarchical decomposition): önce projenin ana bileşenleri tanımlanır, sonra her bileşen daha küçük parçalara bölünür ve bu, parçalar "yeterince küçük" olana kadar sürer. Sonuç iş kırılım yapısıdır (Work Breakdown Structure, WBS) (ekrandan, 00:30:00).

Projedeki bütün etkinliklerin hiyerarşik olarak sıralandığı bu yapıya iş kırılım listesi ya da iş kırılım yapısı denir. Gantt diyagramına yazarken bütün etkinlikler alt alta, aynı seviyedeymiş gibi yazılır; seviyelendirme diyagram aracının içinde (girinti ile) yapılır. WBS ağaç yapısı olarak da, madde madde içeriden yazılan numaralı bir liste olarak da gösterilebilir.

> **Ek bilgi (derste anlatılmadı):** Kitaptaki tanıma göre WBS yalnız iş etkinliklerini değil, ekipman alımı, seyahat, malzeme ya da eğitim ücreti gibi maliyet kalemlerini de içerir; en alt seviyesi etkinliklerin ve maliyetlerin listesidir (ekrandan, 00:30:00).

### 7.2 Kitaptaki örnek WBS

Kitaptaki örnek, donanım alımı da içeren bir anahtar teslim bilgi sistemi projesidir. Ana işler sayılarla, 5'er aralıkla numaralanmıştır:

- **1.0 Yönetim ve destek** (ekrandan, 00:30:00)
- **5.0 Donanım seçimi ve edinimi**
  - **5.5 Donanım seçimi:** gereksinimlerin tanımlanması; belirli kalitedeki satıcıların belirlenmesi ve listelenmesi; gereksinimlere göre tanımlamaların hazırlanması; değerlendirme.
    - Değerlendirmenin altında (üçüncü seviye): değerlendirme kurallarının yazılması, sunumlar, referansların kontrol edilmesi, fiyat ve istenenlerin pazarlığı, son seçim.
  - **5.10 Donanım edinimi:** satın alma mı kiralama mı olacağına karar verilmesi ve alım sırasında dikkat edilecekler.
- **10.0 Sistem geliştirme:** gereksinim belirtimlerinin oluşturulması ile başlayan geliştirme adımları.
- **20 Müşteriye teslim:** müşteri tarafında gerçekleştirilecek işlemler.
- **25.0 Uygulamaya geçiş (Implementation)** (ekrandan, 00:35:00)
  - 25.5 Uygulamaya geçişin planlanması
  - 25.10 Uygulamaya geçişe destek
  - 25.15 Uygulama sonrası gözden geçirme

<!-- BELİRSİZ: Örnek WBS tablosunun (Exhibit 4.10) tamamı karelerde görünmüyor; 5.0, 10.0 ve 20 altındaki maddeler altyazıdan aktarıldı. -->

Hoca, örnekte ilk maddede içeriden yazma kuralına tam uyulmadığını belirtti: 1.0, 5.0, 10.0 gibi ana maddeler aynı seviyede olduğu için hepsi aynı hizada yazılmış; alt maddeler ise içeriden yazılmalıdır.

### 7.3 WBS'in numaralandırılması

WBS hiyerarşik olduğu için öğeleri seviyelere göre numaralanabilir. Örneğin 10.20.15 numarası üçüncü seviyedeki bir öğedir (ekrandan, 00:35:00). Örnekteki gibi aralıklı numara verilirse araya sonradan iş eklemek kolaylaşır; bu bazen tercih edilir, bazen edilmez. Kitap ayrıca şunları söyler (ekrandan, 00:35:00):

- WBS numaraları zaman raporlamasında kullanılır; ekip üyeleri zamanlarını WBS numarasıyla belirtilen etkinliklere yazar. Aynı numaralar çizelgedeki etkinlikleri ve bütçedeki maliyetleri de tanımlar.
- Proje başladıktan sonra etkinlikler kolayca yeniden numaralanamaz; bu yüzden araya ekleme yapmaya izin veren bir numara düzeni seçmek akıllıcadır.
- WBS, görece kararlı hâle gelene kadar (üst yönetim ve kıdemli teknik personel gözden geçirip az değişiklik beklenene kadar) numaralanmamalıdır; aksi hâlde elle yeniden numaralama zahmeti doğar.

### 7.4 WBS hazırlarken dikkat edilecekler

- Önce işi gerçekleştirmek için gereken bütün işler, yönetim, koordinasyon ve kontrol dahil, yazılır; sonra seviyelendirilir.
- Sistem hangi adımlarla elde ediliyorsa bu adımların hepsi sırayla etkinlik listesine yazılır.
- Etkinlikler bağımsız olmalıdır; her etkinliğe bir çalışan ya da görevli grubu tanımlanabilmelidir.
- Etkinlikler arasındaki iletişim sağlanmalıdır.
- Proje aşamaları bu etkinliklerden izlenebilmelidir.

Her etkinlik için bir tanım hazırlanır: hangi projenin hangi etkinliği olduğu ve hangi işi gerçekleştirdiği, girdileri, gereken iş gücü ve çalışan türü, kaynakları, kimlerin hangi oranda çalışacağı ve çıktısı. Örneğin donanım seçiminde daha çok donanım analistleri ve proje yöneticisi çalışır.

## 8. Etkinlikler Arası Bağımlılıklar

Etkinlikler tanımlandıktan sonra aralarındaki ilişkiler kurulur. Çelişen adımlar olmamalıdır. Kitap bağımlılığı şöyle açıklar: duvarlar örülmeden çatı konamaz; planlama yalnızca etkinlik listesi değil, etkinliklerin hangi sırayla yapılacağını bilmektir (ekrandan, 00:40:00). Bağımlılık iki etkinlik arasındaki ilişkidir: bir etkinlik, diğeri başlamadan ya da bitmeden başlayamaz ya da bitemez. Bağımlı olan etkinliğe ardıl (successor), bağlı olunan etkinliğe öncül (predecessor) denir. Bağımlılık ifadeleri açık yazılmalıdır: "tasarım ile kodlama arasında bağımlılık var" demek yerine "kodlama tasarıma bağlıdır" denir; burada tasarım öncül, kodlama ardıldır (ekrandan, 00:40:00).

Dört bağımlılık türü vardır:

- **Bitiş-Başlangıç (finish-start, FS):** Bir etkinlik bittiğinde diğeri başlar. En çok kullanılan türdür. Gantt aracında hiçbir tür belirtilmezse varsayılan olarak bitiş-başlangıç kabul edilir.
- **Bitiş-Bitiş (finish-finish, FF):** Öncül bittiğinde ardıl da biter; birinin bitmesi gerekir ki diğeri bitsin. Örnekler: yazılım test süreci, geliştirme süreci bittiğinde biter. Kitaptaki örnekte dokümantasyonun bitmesi için kodlamanın bitmesi gerekir; yazılım geliştirme bitmeden dokümantasyon da bitmez.
- **Başlangıç-Başlangıç (start-start, SS):** Birinin başlaması için diğerinin başlamış olması gerekir. Örnek: modellemeye başlamak için bilgi toplamanın bitmiş olması gerekmez ama başlamış olması gerekir.
- **Başlangıç-Bitiş (start-finish, SF):** Bir işin bitmesi için diğerinin başlamış olması gerekir. Daha çok kimya gibi alanlardaki projelerde örneği vardır; yazılımda örneği zorlamayla verilir. Kitap bu türün nadir olduğunu, proje yöneticilerinin çoğunun yalnız ilk üç türü kullandığını söyler (ekrandan, 00:40:00).

Bağımlılıklara iki zaman bileşeni eklenebilir: gecikme (lag) ve öne alma (lead). Örneğin "bilgi toplama başladıktan beş gün sonra modellemeye başla" denebilir; aynı gün başlamak şart değildir ama bilgi toplamanın başlamış olması gerekir.

Hoca, bir süreç modeli tanımlandığında etkinliklerin ne zaman başlayıp ne zaman bittiğini bu türlerle düşünmeyi önerdi: hangi modelde süreç adımları nasıl ilerliyorsa yapı ona göre kurulur. Böylece hangi işin hangi işten sonra yapıldığını gösteren bir öncelik-sonralık diyagramı oluşur.

## 9. Tahmin ve Görev Ataması

Planlama sırasında proje için tahminler geliştirilir: her etkinlik ne kadar sürer, kaç kişi gerekir? Her etkinlik için görev tanımları yapılır; kimin ve ne kadar çalışacağı düşünülerek görev ataması yapılır. Örneğin donanım seçimi sırasında belirli sayıda donanım uzmanının ve proje yöneticisinin görevi vardır.

Kitabın tahmin bölümünde şu ilkeler yer alır (ekrandan, 00:45:00):

- **Tahmin bütçe değildir.** Tahmin, projeyi tamamlamak için ne kadar iş gücü (effort) gerektiğini; bütçe ise projenin ne kadara mal olacağını söyler. Tahmin iş haftası gibi sürelerle, bütçe parayla ifade edilir.
- **Tahmin aşağıdan yukarı yapılır.** İş gücü WBS'in en alt seviyesinde tahmin edilir; üst seviye etkinliklerin tahmini alt seviyelerin toplamıdır.
- Bir iş gücü tahmininin üç bileşeni vardır:
  - İşi yapacak kişi ya da kişilerin iş sınıfı (rolü)
  - Her iş sınıfı için gereken zaman yüzdesi
  - Etkinliğin gerektirdiği toplam iş gücü (saat ya da gün)
- Tahmin, personelin atanması ya da müsaitliğiyle ilgilenmez; bunlar kaynak seviyelemesinde ele alınır.
- **Kaynak sınıflandırma:** Etkinlikleri kişiler yapar ama planlama genellikle sistem analisti, programcı analist gibi sınıflarla başlar.

Hoca tahminin kaynak sınıflandırmayla birlikte ele alınacağını söyleyip proje yönetimi tekniklerine geçti. Ders sırasında ekranda kitabın tahmin ilkeleri de görüldü (ekrandan, 00:55:00): tahminler ortalama personelin performansına dayanmalı, dış çizelge kısıtları (yarı zamanlı müsaitlik gibi) tahmini etkilememeli, tahmin işi yapacak yetkin kişilerce yapılmalı ve bilgili kişilerce gözden geçirilmelidir.

> **Hocanın vurgusu:** Yazılım proje yönetimi tanımında üç alan önemlidir: alan bilgisi (yazılım ve bilgisayar mühendisliği), proje yönetimi bilgisi ve temel yönetim bilgisi. MS Project, Gantt ve PERT ile proje yönetimi teknikleri bölümüne geçilir.

## 10. MS Project ile Gantt Grafiği Uygulaması

Aradan sonra oturumun ikinci yarısında, dersin yardımcılığını yürüten asistan MS Project üzerinde bir Gantt grafiği uygulaması yaptı. Örnek, öğrencilerin tanıdığı bir projeydi: bir bitirme projesi (tez yazım süreci olarak da düşünülebilir). Görev ve süreler tamamen örnek olarak verildi; her proje için farklılık gösterir.

### 10.1 Proje özet görevi ve WBS sütunu

Yeni bir görev çizelgesinde Biçim menüsünden "Proje Özet Görevi" seçilir ve projeye ad verilir (Bitirme Projesi). Altına adımlar, onların altına da alt adımlar eklenir; özet görevin süresi alt adımların sürelerinden otomatik hesaplanır. Ardından yeni bir sütun olarak WBS sütunu eklenir. Bu sütun her adımı numaralandırır; Türkçe arayüzde "ÇÇY" (çalışma çözümleme yapısı) adıyla geçer (ekrandan, 01:00:00).

### 10.2 Alt görevler ve otomatik zamanlama

İlk adım literatür taramasıdır. Altına veritabanı taramaları alt görev olarak eklenir: IEEE, Elsevier, SpringerLink ve Google Scholar. Bir görevi alt görev yapmak için Görev sekmesindeki girinti (içeri al) düğmesi kullanılır. Görev modu "Otomatik Zamanla" seçilince başlangıç ve bitiş tarihleri girilen gün sayısına göre otomatik belirlenir; tarih elle girilmez. Literatür taramasının süresi de alt adımların sürelerinden hesaplanır.

### 10.3 Kilometre taşı ve öncüller

Literatür taramasından sonra danışmanla bir değerlendirme toplantısı yapılır. Süre olarak 0 gün girildiğinde MS Project bu görevi kilometre taşı olarak tanır ve elmas simgesiyle gösterir. Kilometre taşı, her adımdan sonra yapılan bir değerlendirme toplantısı gibi düşünülebilir.

Öncüller sütununda bir görevin hangi görevden sonra ya da hangisiyle birlikte başlayacağı belirtilir. Öncül değeri hücreye elle yazılabilir ya da göreve çift tıklanarak açılan "Görev Bilgileri" penceresinin "Öncüller" sekmesinden girilebilir. Bu sekmede öncülün kimliği (görev numarası), görev adı, bağımlılık türü ve öteleme (lag) belirlenir (ekrandan, 01:10:00). Örnekte:

- SpringerLink taraması IEEE taramasından (kimlik 2) sonra başlar: bitiş-başlangıç.
- Google Scholar taraması Elsevier taramasından (kimlik 3) sonra başlar.
- Danışman toplantısının iki öncülü vardır: Google Scholar (kimlik 5) bittikten bir gün sonra (bitiş-başlangıç, öteleme 1 gün) ve SpringerLink (kimlik 4) bittikten sonra.

### 10.4 Veri seti oluşturma ve eş zamanlı görevler

Danışman toplantısından sonraki adım veri seti oluşturmadır (örnek proje bir görüntü işleme projesi olarak düşünülmüştür). Bu görev literatür taramasının altında değil, başlı başına bir adım olduğu için girintisi geri alınır. Altına görüntü toplama (5 gün) ve görüntüleri etiketleme (8 gün) eklenir. Görüntü toplama danışman toplantısından (kimlik 6) sonra başlar. Görüntü etiketlemenin öncülü olarak 8 numaralı görüntü toplama ve tür olarak "Başlangıç-Başlangıç" seçilir: görüntü toplamaya başlandığı anda etiketleme de başlar, ikisi eş zamanlı ilerler.

### 10.5 Ara rapor ve uygulama

Sonra ara rapor yazımı gelir. Altında özet-giriş (4 gün), metot (3 gün) ve rapor teslimi bulunur. Rapor teslimi de 0 gün süreli bir kilometre taşıdır ve 11 ile 12 numaralı görevlerden (özet-giriş ve metot) sonra gerçekleşir. Öncül verilmediği için ara rapor yazımı önce projenin başlangıç tarihine yerleşti; ona öncül olarak 9 numaralı görüntü etiketleme (bir gün öteleme ile) ve 8 numaralı görüntü toplama eklendi. Son adım uygulamadır: 20 gün sürer ve 13 numaralı rapor tesliminden sonra başlar.

Ekranda görülen son Gantt tablosu şöyledir (ekrandan, 01:20:00):

```text
ÇÇY  Görev                    Süre    Başlangıç     Bitiş         Öncüller      Kaynak
0    Bitirme Projesi          41 gün  Sal 4.04.23   Sal 30.05.23
1    Literatür Taraması       8 gün   Sal 4.04.23   Per 13.04.23
1.1    IEEE                   3 gün   Sal 4.04.23   Per 6.04.23                 Ali
1.2    Elsevier               3 gün   Sal 4.04.23   Per 6.04.23                 Veli
1.3    SpringerLink           3 gün   Cum 7.04.23   Sal 11.04.23  2             Ali
1.4    Google Scholar         4 gün   Cum 7.04.23   Çar 12.04.23  3             Veli
1.5    Danışman Toplantısı    0 gün   Per 13.04.23  Per 13.04.23  5TB+1 gün;4
2    Veri Seti Oluşturma      8 gün   Cum 14.04.23  Sal 25.04.23
2.1    Görüntü Toplama        5 gün   Cum 14.04.23  Per 20.04.23  6
2.2    Görüntüleri Etiketleme 8 gün   Cum 14.04.23  Sal 25.04.23  8BB
3    Ara Rapor Yazımı         4 gün   Per 27.04.23  Sal 2.05.23   9TB+1 gün;8
3.1    Özet-Giriş             4 gün   Per 27.04.23  Sal 2.05.23
3.2    Method                 3 gün   Per 27.04.23  Pzt 1.05.23
3.3    Rapor teslimi          0 gün   Sal 2.05.23   Sal 2.05.23   11;12
4    Uygulama                 20 gün  Çar 3.05.23   Sal 30.05.23  13
```

Tablodaki gösterimde "TB" bitiş-başlangıç, "BB" başlangıç-başlangıç bağımlılığıdır; "+1 gün" bir günlük ötelemedir; noktalı virgül birden fazla öncülü ayırır. Tarihler hafta içi çalışma günlerine göre hesaplanmıştır: 4 Nisan ile 30 Mayıs 2023 arasında 41 iş günü, uygulamanın 3-30 Mayıs aralığında 20 iş günü, veri seti oluşturmanın 14-25 Nisan aralığında 8 iş günü vardır (python ile doğrulandı). Danışman toplantısı 12 Nisan çarşamba biten Google Scholar taramasından bir gün sonraya (13 Nisan), ara rapor 25 Nisan salı biten etiketlemeden bir gün sonrasına (27 Nisan perşembe başlangıç) yerleşmiştir.

> **Ders sonrası not:** MS Project'in standart takvimi büyük olasılıkla resmî tatilleri içermez; örnekte 1 Mayıs 2023 (Emek ve Dayanışma Günü, resmî tatil) çalışma günü olarak sayılmıştır. Gerçek bir planda tatiller proje takvimine elle eklenmelidir.

### 10.6 Kaynak atama

Kaynak Adları sütununa kişi adları yazılarak kaynak ataması yapılır. Bitirme projesi genellikle tek kişiyle yapılsa da iki kişinin ya da bir iş yerindeki ekibin çalıştığı düşünülerek örnekte iki genel ad kullanıldı: Ali ve Veli. Ad yazıldığında MS Project bunu otomatik olarak kaynak olarak tanımlar. Aynı anda yürüyen işlerde birden fazla kaynak atanabilir.

## 11. Kritik Görevler, Takvim, Kaynak Ücreti ve PERT Diyagramı

### 11.1 Kritik görevler ve bolluk

Bazı görevler projenin bitiş süresini doğrudan etkiler: o görev uzarsa proje de uzar. Bunlara kritik görevler denir. Bazı görevler ise uzasa bile projenin bitiş süresi değişmez; bunlar kritik olmayan görevlerdir. Biçim menüsünde "Kritik Görevler" ve "Bolluk" seçenekleri işaretlenince MS Project kritik görevleri renklendirir ve bollukları gösterir.

Örnekte SpringerLink taramasında bolluk görüldü. Danışman toplantısı hem SpringerLink'in bitişine hem de Google Scholar bittikten bir gün sonrasına bağlıydı. Google Scholar daha geç bittiği için SpringerLink bir gün uzasa da toplantı tarihi, dolayısıyla proje bitişi değişmez. Bolluk, girilen gün sayılarına göre değişir.

### 11.2 Çalışma takvimi

MS Project başlangıçta cumartesi ve pazarı çalışma zamanına katmaz; bu günler Gantt çubuklarının arkasında gri gösterilir. Hafta sonu da çalışılacaksa Proje > Çalışma Zamanını Değiştir > Çalışma Haftaları yolundan cumartesi ve pazar seçilir, "belirli çalışma zamanları içinde gün ayarla" denerek başlangıç-bitiş saatleri girilir. Bu yapılınca projenin başlangıç tarihi değişmedi ama bitiş tarihi öne geldi: proje bitişi 30.05.23'ten 19.05.23'e çekildi (ekrandan, 01:25:00). Hafta sonları artık gri gösterilmez.

### 11.3 Kaynak ücreti

Kaynak Sayfası görünümünde her kaynak için tür (Çalışma), baş harfler, en büyük birim (%100), standart ücret, fazla mesai ücreti, kullanım başına maliyet, tahakkuk şekli (eşit dağıtılmış) ve temel takvim (Standart) bulunur. Örnekte iki kaynağa da standart ücret olarak ₺30,00/hf girildi (ekrandan, 01:25:00). Gantt görünümüne dönülüp kaynak bilgisine bakıldığında, kişinin her görevde çalıştığı gün sayısına göre alacağı ücret görülür: ücret görevlere dağıtılır, daha uzun süren görevde (örneğin 24 günlük çalışmada) tutar artar.

Gantt grafiğinin amacı eldeki kaynakları hem zaman hem maliyet (parasal) açısından doğru yönetmek ve projedeki kaynak dağılımını doğru yapmaktır. Gantt grafiği ayrıca adımların başlangıç ve bitişlerini net görmeyi sağlar.

### 11.4 PERT (ağ) diyagramı

Görünüm menüsünden "Ağ Diyagramı" seçilerek aynı projenin PERT diyagramı oluşturulur. Diyagramda literatür taraması ve alt görevleri (IEEE, SpringerLink, Elsevier, Google Scholar), kilometre taşı olan danışman toplantısı ve ondan sonra başlayan veri seti adımları kutular ve bağlantılar olarak görülür. Kritik görevler kırmızı, kritik olmayanlar mavi gösterilir. PERT diyagramı işlemler arasındaki bağlantıları gösterir, ama işlemlerin başlangıç ve bitiş sıralaması hakkında çok net bir görüntü vermez. Başlangıç ve bitiş tarihleri Gantt diyagramında daha açık görülür.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:29:31): Şelale modeliyle yeni geliştirilecek bir yazılım projesi için iş kırılım yapısını (WBS) üçüncü seviyeye kadar oluşturun.

> **Çözüm (derste verilmedi):** Aşağıdaki yapı bir örnektir; seviyeler numaradan okunur.
>
> - 1.0 Proje yönetimi: 1.1 Planlama (1.1.1 Risk ve kabullerin belirlenmesi, 1.1.2 Kalite planı, 1.1.3 Çizelge ve bütçe); 1.2 İzleme ve kontrol (1.2.1 İlerleme raporları, 1.2.2 Gözden geçirmeler)
> - 2.0 Gereksinim analizi: 2.1 Bilgi toplama (2.1.1 Görüşmeler, 2.1.2 Mevcut belgelerin incelenmesi); 2.2 Modelleme (2.2.1 Kullanım senaryoları, 2.2.2 Veri modeli); 2.3 SRS (2.3.1 SRS yazımı, 2.3.2 Doğrulama ve onay)
> - 3.0 Tasarım: 3.1 Genel tasarım (3.1.1 Mimari tasarım, 3.1.2 Genel tasarım gözden geçirmesi); 3.2 Ayrıntılı tasarım (3.2.1 Veritabanı tasarımı, 3.2.2 Program tasarımı)
> - 4.0 Gerçekleştirme: 4.1 Kodlama (4.1.1 Modüllerin kodlanması, 4.1.2 Kod gözden geçirmesi); 4.2 Birim testi (4.2.1 Test örneklerinin hazırlanması, 4.2.2 Birim testlerinin yürütülmesi)
> - 5.0 Test: 5.1 Bütünleştirme testi; 5.2 Sistem testi; 5.3 Kabul testi (5.3.1 Müşteriyle kabul testi, 5.3.2 Onay)
> - 6.0 Teslim ve kurulum: 6.1 Kurulum; 6.2 Kullanıcı eğitimi; 6.3 Belgelerin teslimi
>
> Şelalede adımlar sırayla ilerlediği için ana maddeler arasında çoğunlukla bitiş-başlangıç bağımlılığı olur; gözden geçirmeler her ana adımın sonunda kilometre taşı olarak konabilir.

**Soru 2** (derste sözlü, 00:34:57): Donanım alımı gibi işler dışarıda bırakılıp yalnızca yazılım geliştirme ele alınırsa, spiral modele göre geliştirilecek bir projenin iş kırılım yapısı nasıl gösterilir? Hoca burada iki şeyin düşünülmesini istedi: spiral modelin süreç adımları ve bunların WBS'te ağaç ya da girintili numaralı liste olarak gösterimi.

> **Çözüm (derste verilmedi):** Spiral modelde her tur planlama, risk analizi, mühendislik (geliştirme ve test) ve müşteri değerlendirmesi adımlarından geçer. WBS'te her tur bir ana madde, bu dört adım ikinci seviye, adımların işleri üçüncü seviye olabilir. Örnek: 1.0 Tur 1: 1.1 Planlama (1.1.1 Hedef ve kısıtların belirlenmesi, 1.1.2 Alternatiflerin belirlenmesi); 1.2 Risk analizi (1.2.1 Risklerin tanımlanması, 1.2.2 Prototip); 1.3 Mühendislik (1.3.1 Gereksinimlerin belirlenmesi, 1.3.2 Doğrulama); 1.4 Müşteri değerlendirmesi (1.4.1 Gözden geçirme, 1.4.2 Sonraki turun planı). 2.0 Tur 2 ve sonraki turlar aynı yapıyla devam eder; mühendislik adımı turlar ilerledikçe tasarım, kodlama ve test işlerini içerir.

## Dersin Toparlaması

Bu derste proje yönetiminin planlama aşamasına geçildi. Önce projeyi anlama ve tanımlama aşamalarının soruları, teslim edilecekler, kapsam, değişiklik yönetimi ve süreç modelinin seçimi tekrar edildi. Ardından kitaptaki on beş planlama etkinliği sıralandı; kabuller, kısıtlar ve risklerin farkı, kalite planındaki gözden geçirmelerin ekibi ve zamanlaması anlatıldı. Ayrıntılı etkinlik listesinin süreç modeline bağlı olarak hiyerarşik bir iş kırılım yapısı (WBS) biçiminde kurulduğu, WBS'in numaralandırılması, etkinlikler arasındaki dört bağımlılık türü (FS, FF, SS, SF) ve gecikme kavramı, tahminin bütçeden farkı ve aşağıdan yukarı yapılması ele alındı.

Oturumun ikinci yarısında bu kavramlar MS Project üzerinde bir bitirme projesi örneğiyle uygulandı: özet görev, alt görevler, ÇÇY (WBS) numaraları, otomatik zamanlama, öncüller ve öteleme, 0 günlük kilometre taşları, başlangıç-başlangıç bağımlılığıyla eş zamanlı görevler, kaynak atama ve ücret, kritik görevler ve bolluk, hafta sonunun takvime eklenmesi ve PERT (ağ) diyagramı gösterildi. Risk yönetiminin ayrıntıları sonraki derste ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
