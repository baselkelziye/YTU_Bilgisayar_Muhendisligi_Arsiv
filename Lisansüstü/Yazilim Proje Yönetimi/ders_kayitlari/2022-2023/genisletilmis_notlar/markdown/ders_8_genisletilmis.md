# Ders 8 Genişletilmiş Notu: Proje Planlama Tekrarı: Riskler, Kabuller ve Kısıtlar, Proje Planı İçeriği ve Projeyi Yürütme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Proje Planlamanın On Beş Aktivitesi
- 2. Kaynak Atama, Seviyelendirme ve Bütçe
- 3. Teslim Edilecekler, Uygulama ve İletişim Planlaması
- 4. Risk Kategorileri
- 5. Risk Tablosu ve Risklerin Takibi
- 6. Proje Kabulleri
- 7. Proje Kısıtları
- 8. Proje Planı Dokümanının İçeriği
- 9. Tamamlanma Kriterleri
- 10. Projeyi Yürütme (Running the Project)
- Örnek Sorular
- Dersin Toparlaması

## 1. Proje Planlamanın On Beş Aktivitesi

Ders, önceki haftalarda olduğu gibi "Information Systems Project Management" kitabının proje planlama bölümü üzerinden ilerler. Son iki derste ele alınan planlama aktiviteleri, proje planının içereceği her şeyin temeli olduğu için baştan bir kez daha gözden geçirilir.

Kitap, planlamanın önemini şu yorumla açar: "Plan yapmamak, başarısız olmayı planlamaktır" sözü bir öğütten çok bir şiir gibidir; kimse başarısız olmayı planlamaz, ama yalnızca plan yapmak da başarıyı garanti etmez. Projenin gerçekliğinden kopuk bir plan, hiç plan yapmamaktan daha kötüdür, çünkü kontrol yanılsaması yaratır. Kitaba göre daha doğru ifade "Kötü planlama başarısızlığı garanti eder" olur (ekrandan, 00:20:00).

Kitaba göre bir projeyi planlamak şu on beş aktiviteden oluşur (ekrandan, 00:20:00):

- 1\. Proje risklerini tanımlamak ve bunları azaltacak (mitigation) eylemleri belirlemek
- 2\. Proje kabullerini (assumptions) ve kısıtlarını (constraints) listelemek
- 3\. Kalitenin nasıl yönetileceğini belirlemek
- 4\. Aktivite ve maliyet bileşenleri listesini oluşturmak
- 5\. Aktiviteler arasındaki bağımlılıkları kurmak
- 6\. İş gücünü ve maliyetleri tahmin etmek
- 7\. İş takvimini ve kilometre taşlarını (milestone) hazırlamak
- 8\. Proje kaynaklarını atamak ve seviyelendirmek
- 9\. Bütçeyi ve takvimi müşteri gereksinimleriyle uyumlu hale getirmek
- 10\. Proje bütçesini hazırlamak
- 11\. Proje belgelerini (paperwork) yönetmek
- 12\. Uygulamaya geçişi (implementation) planlamak
- 13\. Tamamlanmayı planlamak
- 14\. İletişimi planlamak
- 15\. Proje planını yazmak

Hoca ilk maddeleri şöyle özetler: riskler tanımlanır ve her birine karşı nasıl bir önlem alınacağı, nasıl davranılacağı belirlenir; kabuller ve kısıtlar listelenir; kalite yönetiminin nasıl yapılacağı belirlenir; maliyet belirlemek için aktivite listesi çıkarılır.

Aktivite listesinin çıkarılmasından önce gelen bir adım vardır: yazılım geliştirme süreç modelinin belirlenmesi. Hangi model seçildiyse aktivite listesi de ona bağlı olarak farklı olur. Aktiviteler belirlendikten sonra aralarındaki bağımlılıklar kurulur. Bağımlılık kurmak, hangi aktivitenin hangi aktiviteye hangi türde bağlı olduğunu bilmek demektir: bitiş-başlangıç (finish-start), başlangıç-başlangıç (start-start) ya da bitiş-bitiş (finish-finish).

İş gücü ve maliyet tahmini için MS Project ya da başka bir proje planlama yazılımından yararlanılır. Aktiviteler seviyelendirilir, her aktiviteye süre tanımlanır ve bu süreler içinde en iyi yol PERT diyagramıyla bulunur. İş takvimi ve kilometre taşları da Gantt ve PERT diyagramlarının içinde yer alır. Hocaya göre 4'ten 9'a kadar olan maddeler aslında iç içe geçmiştir ve hepsi MS Project gibi bir araçta birlikte yürütülür. Bunun dışında çok sayıda proje planlama aracı vardır; bunların ücretsiz ve açık kaynaklı olanları da bulunur ve herhangi biriyle bu süreç yürütülebilir.

Kilometre taşları (hocanın deyişiyle "milestone"lar) aynı zamanda gözden geçirme noktaları olarak da kullanılabilir.

## 2. Kaynak Atama, Seviyelendirme ve Bütçe

### 2.1 Kaynakların atanması ve seviyelendirilmesi

Önceki ders yedinci maddede kalmıştı; bu derste sekizinci madde olan kaynakların atanması ve seviyelendirilmesiyle devam edilir. Projedeki en önemli kaynak iş gücü, yani insan kaynağıdır.

İşlem iki adımda yürür. Önce herkese görev ataması yapılır. Bu ilk atama genellikle, diğer projelerden edinilen bilgiyle, işi en iyi yapacak kişilere göre dağıtılır. Sonra kişi bazında proje planı çıkarıldığında bazı kişilerin planının aşırı yüklü, bazılarınınkinin daha boş olduğu görülür. Bu durumda seviyelendirme yapılır: aşırı yüklü kişilerin bazı işleri diğer kişilere yeniden atanır. Herkes çok doluysa dışarıdan, ya yalnız bu proje için ya da kalıcı olarak, eleman eklenmesi gerekir. "Atama ve seviyelendirme" ifadesi bu iki adımı anlatır.

### 2.2 Bütçe ile takvimin müşteri gereksinimlerine uyarlanması

Dokuzuncu madde, bütçe ve takvimin müşteri gereksinimleriyle uyumlu hale getirilmesidir (ekrandan, 00:25:00). Hoca bu noktada müşteri gereksinimlerini karşılamak üzere bir iş listesi oluşturulduğunu belirtir.

<!-- BELİRSİZ: 00:23:48 civarında altyazı "Müşteri gereksinimlerini belirtmek üzere de bir iş listesi oluşturulur" diyor; ekrandaki madde "Aligning the budget and schedule to client requirements". -->

### 2.3 Proje bütçesi ve kalemleri

Bütçe, projedeki görevlere atanan kişilerin ücretleri ve görevde ne kadar saat çalıştıkları göz önünde bulundurularak çıkarılır. Proje bütçesinin başlıca kalemleri şunlardır:

- İş gücü: bütçenin birinci kalemi.
- Donanım: satın alınacak donanım parçaları ve araçları; insan iş gücünden sonra gelen kalemdir.
- Bağlantı ücretleri: ağ (network) gibi bağlantılar için gereken ücretler.
- Süreli giderler: kira, malzeme gibi.
- Danışmanlık ücretleri.
- Seyahat harcamaları: işi gerçekleştirmek için yapılacak seyahatler.
- Sarf malzemeleri.

Bunların her biri bütçede ayrı bir satır olarak yer alır. Ayrıntı gerektiğinde her satır başka tablolarda daha kapsamlı gösterilir.

## 3. Teslim Edilecekler, Uygulama ve İletişim Planlaması

Projede teslim edilecekler ve dağıtımda verilecek maddeler (test planları, yarı ürünler ve ürünler) belirlenir. Dağıtım listesi, proje yönetiminin ikinci aşaması olan projenin tanımlanmasında görülmüştü. Bu maddelerin yönetimi, projenin gerçekleştirilmesi sırasında nasıl bir plan izleneceği ve iletişimin planlanması (grup içindeki iletişimin nasıl gerçekleşeceği) önceki dersin sonunda ele alınmıştı.

## 4. Risk Kategorileri

Proje yöneticisi bir risk analizi yapar. Önceki derste riskler başka bir kaynaktan proje riskleri, ürün riskleri ve teknik riskler olarak sınıflanmıştı. Kitap ise yaygın proje risklerini farklı biçimde sınıflar (ekrandan, 00:30:00 ve 00:35:00). Kitap, riskleri değerlendirirken her zaman böyle bir listeye başvurulmasını, aksi halde bütün risklerin tanımlanmamış olması gibi bir proje yönetimi riskine girileceğini belirtir.

> **Hocanın vurgusu:** Riskler değişik şekillerde kategorize edilebilir. Ama her proje için ayrı kategoriler kullanmak yerine, yazılım geliştirme ekibi ya da kurum olarak bir kez risk kategori tanımı yapılmalı ve hep o kullanılmalıdır. Böylece riskler konusunda araştırma yapmak ya da arşiv bilgisi tutmak istendiğinde her projede farklı kategoriler ve farklı adlandırmalar ortaya çıkmaz.

### 4.1 Personel (staff) riskleri

- Anahtar personel gerektiğinde bulunamayacak (izinli olması ya da yerinde olmaması).
- Anahtar yetenekler gerektiğinde bulunamayacak (ekipte gereken yeteneğe sahip kimsenin olmadığının anlaşılması).
- Proje süresince personel kaybedilecek; özellikle önemli elemanların kaybı.

### 4.2 Donanım (equipment) riskleri

- Gerekli donanım, sipariş verildiği halde zamanında teslim edilmeyecek.
- Donanıma erişim kısıtlanacak.
- Proje sırasında donanım arızalanacak.

### 4.3 Müşteri (client) riskleri

- Müşteri kaynakları gerektiği gibi sağlanmayacak.
- Müşteri personeli kararları zamanında vermeyecek.
- Teslim edilenler takvime göre gözden geçirilmeyecek.
- Bilgili müşteri personeli daha az yetkin kişilerle değiştirilecek.

Müşteri iş gücü en çok gereksinim analizinde gereklidir. Bu aşamada müşteri, yaptığı işin ne olduğunu ekibe anlatır; bunun doğru anlaşılması için müşteri kaynaklarına ulaşılabilmesi gerekir. Müşteri kararlarını zamanında vermeli ve teslim edilenler üzerindeki çalışmalarda iş takvimine uymalıdır. Örneğin bir gereksinim raporu teslim edildiyse ve gözden geçirilmesi isteniyorsa bunu zamanında yapmalıdır. Müşterinin projeye bilgi verecek kişileri, yaptığı işi daha iyi anlatabilecek kişilerden seçmesi beklenir. İşini iyi anlatamayan bir personel zaman zaman sorun olabilir; o zaman başka bir personelle değiştirilmesi gerekir.

### 4.4 Kapsam (scope) riskleri

- Ek iş gerektiren gereksinimler ortaya çıkacak.
- Kapsam değişiklikleri projeye dahil sayılacak.
- Kapsam değişiklikleri proje yönetiminin bilgisi dışında yapılacak.

Gereksinimler değişebilir, kapsam (alan) değişiklikleri olabilir; önemli olan bu değişikliklerin iyi takip edilmesidir.

> **Hocanın vurgusu:** En büyük risklerden biri, proje yöneticisinin bilgisi olmadan alttaki sistem analistlerine doğrudan istekte bulunulması, yani gereksinimlerin kuralsız biçimde değiştirilmesidir. Bu müşteriyle de ilgilidir: müşteri ile geliştiriciler arasında kurallı bir alan tanımı olmalıdır. Projenin, proje yönetiminin tanımladığı yoldan farklı biçimde yürütülmeye çalışılması önemli bir risktir.

Proje alanı, sistem alanı ve alan değişikliğinin nasıl yapılacağı, projenin tanımlanması aşamasında ele alınmıştı.

### 4.5 Teknoloji riskleri

- Teknolojinin projeyi tehlikeye atan teknik ya da performans sınırları olacak.
- Teknoloji bileşenleri kolayca bütünleştirilemeyecek.
- Teknoloji yeni ve az anlaşılmış olacak.

Hoca bileşen uyumsuzluğunu şöyle açıklar: gereksinim analizinde, tasarımda, gerçekleştirmede ve test aşamasında farklı teknolojiler kullanılmışsa ve bunların birbiriyle uyumu, entegrasyonu sağlanmamışsa bu bir teknoloji riski getirir. Yeni ve anlaşılmamış bir teknolojinin kullanılması da proje için bir tehlike oluşturur.

### 4.6 Dağıtım (delivery) riskleri

Teslim sürelerine uyulmaması, kapasite gereksinimlerinin karşılanmaması ve oluşturulan sistemin işlevsel gereksinimleri karşılayamaması, teslim edilecekler için bir dağıtım riskidir.

<!-- BELİRSİZ: Dağıtım risklerinin kitaptaki madde metinleri kareden görülmedi; yukarıdaki maddeler altyazıdan alındı. -->

### 4.7 Fiziksel riskler

Afetler, bir hasar oluşması ya da virüs gibi durumlar fiziksel risklerdir.

> **Hocanın vurgusu:** Fiziksel risklerle az karşılaşılır, ama gerçekleştiklerinde yıkımları büyük olur.

## 5. Risk Tablosu ve Risklerin Takibi

Riskler ayrıca düşük, orta ve yüksek riskler olarak derecelendirilir. Risk tablosu oluşturulurken her risk için şunlar belirlenir:

- Riskin tanımı.
- Riskin hangi kategoriye girdiği: müşteri riski mi, dağıtım riski mi, personel riski mi?
- Riskin olma olasılığı.
- Risk gerçekleşirse etkisi, yani yıkımın derecesi.
- Olasılık ile etki birleştirilerek bulunan riskin derecesi.
- Hangi tarihte değerlendirildiği ve o tarih için açıklamalar.

<!-- BELİRSİZ: Risk tablosunun kitaptaki sütun başlıkları kareden görülmedi; liste altyazıdaki anlatımdan kuruldu. -->

Hoca, kitaptaki sınıflamanın aynısının kullanılmak zorunda olmadığını, önceki dersin slaytındaki gruplandırmanın da kullanılabileceğini söyler; ama her risk tanımının hangi sınıfa girdiği mutlaka belirtilmelidir.

Tabloya bakılarak en etkili olacak riskler belirlenir ve takibe alınır. Bir riski takibe almak, her kilometre taşında o riskin hâlâ aynı olasılıkta olup olmadığını ve gerçekleşirse yıkımının aynı derecede olup olmayacağını kontrol ederek ilerlemek demektir.

Riskleri ortadan kaldırmak için bir risk değerlendirme mekanizması kurulur: hangi önlem alınacak, bu önlemin maliyeti nedir ve bu maliyet çerçevesinde risk nasıl takip edilecek? Her risk için bunun planı yapılır. Riskler hem planlama hem de aktivite yönetimi sırasında ele alınır; ekip, belirlenen davranışlarla riskleri önlemeye çalışır. Risk yönetimi için de takip edilmesi gereken her risk bir tabloda izlenir.

## 6. Proje Kabulleri

Kabuller ve kısıtlar, kitapta planlamanın başına yerleştirilmiş olsa da derste daha sonraya bırakılmıştı. Bu derste ele alınır.

Kitaba göre projelerde sorun çıktığında nedeni çoğu zaman geçersiz çıkan bir kabul ya da hiç belirlenmemiş bir kısıttır. Kabuller ve kısıtlar belgelenirse, iş gerektirebilecek tehlikeli alanlar önceden görülebilir (ekrandan, 00:45:00).

### 6.1 Kabul nedir?

Genel olarak, doğru olduğu kabul edilen şeyler projeye destek olur. Kabuller geçersiz çıkarsa proje zarar görür; tersine, belirlenmemiş kabuller genellikle projenin lehine sonuçlanır. Kabul edilen durumlara uymayan bir şey olursa bir B planı devreye girer.

Kitaptaki örnek (ekrandan, 00:40:00 ve 00:45:00): Müşterinin ana bilgisayarının (mainframe) günde 24 saat erişilebilir olacağı kabul edilirse ve müşteri ekibi normal sekiz saatlik iş gününe sınırlarsa proje zarar görür. Öte yandan normal iş günü kabul edilmişse ve fazla mesai gerekirse, müşteri 24 saat erişim sağladığında proje kazançlı çıkar. Hoca bunu şöyle anlatır: proje planı ana bilgisayarda aksaklık olmayacağı kabulüyle kurulur; bir aksaklık olursa kabulün dışına çıkılmış olur.

Benzer şekilde, müşteri tarafında projeye destek olacak personelin istendiği zaman çalışır durumda olacağı varsayılır. Oysa görevlendirilen kişiler haftanın bir günü izinli olabilir ya da kendi işlerinde çalıştıkları için destek veremeyebilir. Müşterinin görevlendirdiği kişilerin sürekli olarak projeye adanmış çalışacakları kabul edilerek işe girilir.

Kitaba göre kabuller planı olumlu etkiler; iş yükünü azaltır ve kaynakları güvenceye alır. Genellikle donanımın ve insanların gerektiğinde erişilebilir olacağı, planlamada kullanılan istatistiklerin doğru olduğu, kritik bileşenlerin zamanında teslim edileceği ve hem proje hem müşteri ekibindeki anahtar kişilerin yeterli performans göstereceği kabul edilir (ekrandan, 00:40:00).

### 6.2 Kabul türleri

Kitap tipik kabulleri şu sınıflarla verir (ekrandan, 00:40:00 ve 00:50:00):

- Kaynak kabulleri:
  - Proje personeli gerektiğinde ve gerektiği kadar erişilebilir olacak.
  - Gerekli bilgisayar kaynakları gerektiğinde ve gerektiği kadar erişilebilir olacak.
  - Gerekli müşteri kaynakları gerektiğinde ve gerektiği kadar erişilebilir olacak.
  - Proje personelinin en az $n$ yüzdesi geliştirme ortamında deneyimli olacak.
  - Müşteri, sistemin işlevsel gereksinimlerini ayrıntılı ve yeterli biçimde anlatabilecek personel sağlayacak.
- Dağıtım kabulleri:
  - Onaya sunulan teslim edilenler $n$ iş günü içinde geri dönecek.
  - Donanım siparişlerinin teslim süresi belirtilen kadar olacak.
- Ortam kabulleri:
  - Projeyi etkileyecek bir grev ya da toplu eylem (industrial action) olmayacak.
  - Sorunlar zamanında çözülecek.
  - Tanımlanan proje organizasyonu kurulacak.
  - Belirlenen metodoloji projede kullanılacak.
  - Müşterinin iç süreçleri (satın alma gibi) zamanında tamamlanacak.
  - Sistem geliştirme bileşenleri bütünleştirilebilecek.
- Bütçe kabulleri.
- İşlevsel kabuller.

Hoca kaynak kabullerini hem kendi ekibi hem müşteri için açıklar. Kendi ekibi için çalışanların ihtiyaç duyulduğunda her an çalışabileceği ve bilgisayar kaynaklarının zamanında sağlanacağı kabul edilir. Müşteri tarafında ise destek verecek kişilerin kontrolleri ve testleri yapacakları zaman erişilebilir olacağı varsayılır. Örneğin teslim edilen gereksinim raporu üzerinde gözden geçirme yapılacaksa ve bunun için belirli bir gün sayısı sözleşilmişse, kontrollerin o süre içinde yapılacağı kabul edilir.

Ortam kabullerinde hoca, proje içinde çalışanların hiyerarşisinin ve organizasyonunun tanımlandığı şekilde işleyeceğini, metodoloji örneğinde de Scrum kullanılacaksa bütün çalışanların Scrum'a hakim olacağını örnek verir. Sistemi oluşturan bileşenlerin birbiriyle bütünleşebileceği kabulü, kullanılan yazılım kütüphaneleri ve diğer bileşenler için de geçerlidir.

Bütçe kabullerine örnekler şunlardır: tahminlerin (ilk başta tahmin edilen bütçenin) belirli bir yüzdeyle doğru olduğu; listede hiç belirtilmeyen seyahat ve sarf malzemesi harcamalarına ihtiyaç olmayacağı; danışmana gerek olmayacağı ya da danışmanlık giderinin bütçede belirtildiği kadar kalacağı.

İşlevsel kabuller ise hazırlanacak yazılımın iş alanıyla ilgili, iş tanımları anlatılırken yapılan varsayımlardır ve "böyle olacağı varsayılmıştır" biçiminde yazılır.

## 7. Proje Kısıtları

Kısıtlar, projeyi sınırlayan koşullardır ve baştan potansiyel sınırlamaları gösterir. Kitaba göre kabuller ve kısıtlar çoğu zaman birbirinin tersidir: projenin bir ağ yöneticisine ihtiyacı varsa ve bu kişi zamanın yarısında erişilebilirse, kaynağın yarı zamanlı erişilebilir olduğu kabul edilebilir ya da daha fazla erişilebilir olmadığı bir kısıt olarak yazılabilir (ekrandan, 00:45:00).

Kısıtlar da kabullerle aynı sınıflarla verilir (ekrandan, 00:55:00):

- Kaynak kısıtları:
  - Anahtar personel yalnız yarı zamanlı (part-time) erişilebilir olacak.
  - Bilgisayar kaynakları sınırlı erişilebilir olacak.
  - Anahtar müşteri kaynakları kısıtlı erişilebilir olacak.
- Dağıtım kısıtları:
  - Onaya sunulan teslim edilenlerin gözden geçirilmesi en az $n$ iş günü gerektirecek.
  - Donanım siparişlerinin teslim süresi doğru olarak belirlenemiyor.
- Ortam kısıtları:
  - Geliştirme ortamı yeni ve geliştirme personelinden kimse ona aşina değil.
  - Bütün işi normal mesai saatleriyle sınırlayan bir fazla mesai yasağı var.
  - Anahtar karar vericiler başka bir şehirde bulunuyor ve sorun çıktığında onlara ulaşmak zor.
  - Projenin müşteri tarafında bir proje yöneticisi (ya da üst düzey sponsor, yönlendirme komitesi) yok.
  - Müşterinin iç süreçleri (satın alma gibi) verimsiz ve öngörülemez.
  - Belirlenen metodoloji yeni ve geliştirme ekibine yabancı.
  - Sistem geliştirme ortamı yeni ve bileşenler henüz başarıyla bütünleştirilmedi.
- Bütçe kısıtları.
- İşlevsel kısıtlar.

Hocanın örnekleri:

- Kaynak kısıtı: Bir anahtar teslim projede ağ uzmanı gereklidir, ama başka projelere de destek verdiği için yalnız yarı zamanlı çalışabileceği baştan bir kısıt olarak belirtilebilir. Müşteri tarafında değerlendirmeleri yapacak personelin yalnız haftanın belirli bir günü çalışacağı, bu yüzden teslimlerin o güne yetiştirilmesi gerektiği de bir kaynak kısıtıdır.
- Dağıtım kısıtı: Gözden geçirme için teslimin belirli bir gün sayısı önce yapılması gerekmesi hem kaynak hem dağıtım kısıtına örnek olur. Donanımın ne zaman geleceğinin tam belirlenememesi de bir teslim kısıtıdır.
- Ortam kısıtı: Müşterinin iç süreçlerinde donanımla ilgili bazı satın almalar istenmiştir, ama bu süreçlerde bir kısıtlama vardır ve tahmin edilemeyen gecikmeler olabilir. Ekip tarafından bir örnek: hep Scrum ile çalışan bir ekip yürüyen projede Kanban ile çalışıyorsa ve Kanban'a aşina değilse, bu ilk deneme ekip için bir ortam kısıtıdır.
- Bütçe kısıtı: Seyahat harcamaları tam doğrulukla tahmin edilememiş olabilir; dışarıdan danışman gereksinimi vardır ama tam olarak tahmin edilememiştir.
- İşlevsel kısıt: Proje alanı belirsiz olabilir. Proje, girdilerini başka bir dış uygulamanın çalışması sonucunda elde edilen verilerden alıyorsa o uygulamaya bağlıdır; diğer uygulamanın beklenmesi gerekebilir.

## 8. Proje Planı Dokümanının İçeriği

Önceki haftalarda görülenler ve bu derste kabul, kısıt ve risk tekrarıyla, proje planını hazırlamak için yapılması gereken bütün çalışmalar görülmüş olur. Sırada bu çalışmaların proje plan dokümanında nasıl yer alacağı vardır. Hoca kitaptaki örnek proje planı içerik tablosunu izler (ekrandan, 01:25:00).

### 8.1 Giriş ve proje tanımı

Plan, projenin amacıyla başlar. Proje tanımında projenin amacı, alanı (kapsamı), proje sonunda temel teslim edilecekler, projenin ortaya çıkmasına neden olan iş gereksinimi ya da iş fırsatı ve projenin finansal tahmini (ne kazandıracağı) yer alır.

### 8.2 Tamamlanma kriterleri

Projenin bittiğine karar vermek için kullanılacak tamamlanma kriterleri yazılır. Bu kriterler proje türüne göre değişir (ayrıntısı Bölüm 9'da).

### 8.3 İş planı

İş planı, açık kaynaklı ya da profesyonel bir proje planlama yazılımıyla (örneğin MS Project) hazırlanır. Teslim edilecekler, genel yaklaşım, iş kırılım yapısı (Work Breakdown Structure, WBS), iş listesi ve kilometre taşları gösterilir. Tahmini zaman ve bütçe yapısı ile nakit akışı da burada verilir.

### 8.4 Proje organizasyonu

Proje organizasyonunun, ekip yapısının ve proje görevlerinin nasıl olacağı belirtilir. Hoca bu konunun derste henüz ayrıntılı işlenmediğini, ileride ekleneceğini söyler. Görevlendirilecek kişilerin sahip olması gereken yetenekler yazılır: proje yöneticisi, yazılım uzmanı, ağ uzmanı gibi her rolün gereksinimleri. Yazılım geliştirme sürecinin nasıl yürütüleceği de belirtilir.

### 8.5 Yönetim planları

İçerik tablosunda her yönetim planının kendi amacı ve alt başlıkları vardır (ekrandan, 01:25:00):

- Kapsam (alan) yönetim planı: proje kapsamı, projenin gerekçesi, teslim edilecekler (proje yönetimi teslim edilecekleri ve proje teslim edilecekleri), proje hedefleri, kapsam değişiklikleri (kapsam değişikliği etkenleri, kapsam değişikliklerinin belirlenmesi, kapsam değişikliği prosedürleri). Kapsam değişikliği için nasıl bir form hazırlanacağı da burada tanımlanır.
- Takvim yönetim planı: proje takvimi, takvim kaymalarının olası nedenleri, proje kontrol prosedürleri (takvim sorunlarının belirlenmesi ve çözümü).
- Maliyet yönetim planı: bütçenin tanımı, başlıca proje maliyetleri ve maliyetin artmasına yol açabilecek etkenler (örneğin donanım edinme maliyetlerinin artması). Plan yapıldıktan sonra artış olabilir mi sorusu bu planın konusudur.
- Risk yönetim planı: risklerin tanımı, riskleri önlemek için yapılacaklar ve bunların gözden geçirilmesi.
- İletişim yönetim planı: hangi tür iletişimlerin yapılacağı. Proje çevik yürüyorsa iletişim daha sık ve daha önemli olur.
- Kalite yönetim planı: gözden geçirmeler ve kaliteyi sağlamak için kullanılacak araçlar (test araçları, kalite ölçüm araçları).

### 8.6 Ekler

Müşteri tarafında planı uygulayan yapı (örneğin müşteri tarafında bir proje yöneticisi olup olmadığı) belirtilir. Ekler olarak risk kontrol listeleri, ayrıntılı proje iş listesi, iş kırılım yapısı ve proje paydaşları verilir.

Hoca bu içerik tablosunun bir taslak olduğunu vurgular: bütün ayrıntılarıyla aynısı yapılmak zorunda değildir, bazı bölümler genişletilip bazıları kısaltılabilir. Alternatif olarak IEEE proje planı formatı da kullanılabilir.

> **Ek bilgi (derste anlatılmadı):** IEEE'nin yazılım proje yönetim planı standardı büyük olasılıkla IEEE 1058 (Software Project Management Plans) standardıdır; bu standart daha sonra ISO/IEC/IEEE 16326 ile birleştirilmiştir. Bu standartlarda da giriş, proje organizasyonu, yönetim süreçleri, teknik süreçler ve destek süreçleri gibi benzer başlıklar bulunur.

## 9. Tamamlanma Kriterleri

Kitaba göre tamamlanma kriterleri projenin başında tanımlanmalıdır. Özel kriterler proje türüne göre değişir; kitap farklı proje türleri için şu önerileri verir (ekrandan, 01:20:00):

| Proje türü | Tamamlanma kriterleri |
|---|---|
| Uygulama geliştirme (applications development) | Kabul testlerinin başarıyla tamamlanması; kullanıcı eğitiminin tamamlanması; uygulamanın devreye alınması (rollout); tarih karşılaştırması; mevcut sistemin kullanımdan kaldırılması; destek gruplarına devir |
| Sistem entegrasyonu (systems integration) | Garanti süresinin tamamlanması; uygulama bakım prosedürlerinin kurulması; yardım masası prosedürlerinin kurulması; üretim prosedürlerinin kurulması; üretime devir |
| Altyapı (infrastructure) | Donanım kurulumunun tamamlanması; sistem yazılımı kurulumunun tamamlanması; sistem testinin başarıyla tamamlanması; masaüstü değişikliklerinin tamamlanması; sistem destek prosedürlerinin kurulması; yardım masası prosedürlerinin kurulması |

Hoca uygulama geliştirme projesini şöyle anlatır: yazılım bitmiş ve kabul testleri yapılmıştır, kullanıcı eğitimleri tamamlanmıştır, şu anda kullanılan sistemin kullanımı bitirilmiş ve yeni sistem kurulabilir durumdadır. Sistem entegrasyonu ya da altyapı projesinde kriterler farklıdır.

Hoca tabloda olmayan bir tür daha ekler: yalnız analiz projesi. Gerçekleştirmeye geçilmeden yalnız analiz yapılan bir projede tamamlanma kriterleri şunlardır: son SRS raporu hazırlandı mı, gözden geçirildi mi, sunumu yapıldı mı, müşteri tarafının gözlemleri ve uyarıları alındı mı?

Kitap ayrıca memnuniyete dayalı (müşteriyi memnun etmeye bağlı) bir tamamlanma ölçütüne karşı uyarır: birini memnun etmenin nesnel bir yolu yoktur. Müşteri ısrar ederse "Onu ne memnun eder?" diye sorulup test edilebilir bir kriter kümesine ulaşılana kadar ayrıntıya inilmelidir (ekrandan, 01:20:00).

## 10. Projeyi Yürütme (Running the Project)

Planlama tamamlandıktan sonraki aşama projeyi yürütmedir. Plandan sonra gereksinim analizi, tasarım ve gerçekleştirme adımları devam eder. Bu süreçte nasıl bir kontrol mekanizması kurulacağı belirlenmelidir.

Kitap, bu aşama için yöneticinin kendine sorması gereken soruları listeler (ekrandan, 01:30:00):

- Etkin bir ekip kuruyor muyum?
- Takvim, tahmin ve bütçe karşısında nerede olduğumu biliyor muyum?
- Riskleri yönetiyor muyum?
- Takvim sorunlarını çözüyor muyum?
- Kapsam değişikliği isteklerini yönetiyor muyum?
- Kaliteyi yönetiyor muyum?
- Gerektiğinde ayrıntıya iniyor (mikro yönetim yapıyor), gerekmediğinde inmiyor muyum?
- Alt yüklenicilerim taahhütlerini yerine getiriyor mu?
- Müşterinin beklentilerini anlıyor ve karşılayabiliyor muyum?
- Düzenli ekip toplantıları yapıyor muyum ve bunlar etkin mi?
- Proje durumunu ve açık sorunları düzenli raporluyor muyum?
- İlerleme üzerine kendi başıma düşünmeye zaman ayırıyor muyum?
- Ben ve ekibim başarılarımızı kutluyor muyuz?

Hoca bu soruları açarken ekibin etkin çalışıp çalışmadığını, iş listesi, tahmin ve bütçe karşısında tahminlerin tutup tutmadığını, zaman kayması olup olmadığını ve olduğunda çözülüp çözülemediğini, isteklerin planlanan formata uygun yürüyüp yürümediğini sorgular. Toplantılardaki iletişimin planlandığı gibi yürümesi, proje durum raporlarının düzenli tarihlerde oluşturulması ve bütün ekip tarafından görülebilmesi de kontrol edilir.

Başarının ekipçe kutlanması ve proje bilgilerinin belirli indekslerle arşivlenmesi ise projenin kapatılması aşamasında ele alınacaktır.

> **Hocanın vurgusu:** Projeyi yürütmek aslında projeyi kontrol edebilmektir: planlanan ile gerçekleşen arasındaki fark her adımda görülebilmeli, takip edilebilmeli ve belirtilmelidir.

Kitap planlama ile yürütme arasındaki farkı da vurgular: planlama yoğunlaşmadır, yürütme ise kaotiktir; planlamaya az sayıda kişi katılırken yürütme çok sayıda katılımcı, talep, kriz ve sorun içerir (ekrandan, 01:30:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:45): Bir proje planı oluştururken, proje planlama aşamasında hangi aktiviteler vardır?

> **Cevap (derste verildi):** Kitaba göre on beş aktivite vardır: risklerin tanımlanması ve azaltma eylemleri, kabul ve kısıtların listelenmesi, kalite yönetiminin belirlenmesi, aktivite ve maliyet bileşenleri listesi, aktiviteler arası bağımlılıklar, iş gücü ve maliyet tahmini, iş takvimi ve kilometre taşları, kaynak atama ve seviyelendirme, bütçe ve takvimin müşteri gereksinimlerine uyarlanması, proje bütçesi, belge yönetimi, uygulamanın, tamamlanmanın ve iletişimin planlanması, proje planının yazılması (Bölüm 1).

**Soru 2** (derste sözlü, 00:23:58): Proje bütçesindeki kalemler nelerdir?

> **Cevap (derste verildi):** Birinci kalem iş gücüdür. Ardından satın alınacak donanım, ağ gibi bağlantı ücretleri, kira ve malzeme gibi süreli giderler, danışmanlık ücretleri, seyahat harcamaları ve sarf malzemeleri gelir. Her kalem bütçede ayrı bir satırdır.

**Soru 3** (derste sözlü, 00:30:52): Müşteri iş gücüne projede en çok ne zaman ihtiyaç duyulur?

> **Cevap (derste verildi):** Özellikle gereksinim analizinde. Müşteriler bu aşamada yaptıkları işin ne olduğunu anlatır; bunun doğru anlaşılması için müşteri kaynaklarının ulaşılabilir olması gerekir.

**Soru 4** (derste sözlü, 00:39:31): Bir risk nasıl takibe alınır?

> **Cevap (derste verildi):** Risk tablosunda olasılığı ve etkisi birleştirilerek derecesi bulunan en etkili riskler seçilir. Her kilometre taşında riskin hâlâ aynı olasılıkta olup olmadığı ve gerçekleşirse yıkımının aynı derecede olup olmayacağı kontrol edilerek ilerlenir.

**Soru 5** (derste sözlü, 00:42:55): Riskleri ortadan kaldırmak için ne yapılır?

> **Cevap (derste verildi):** Bir risk değerlendirme mekanizması kurulur: hangi önlemin alınacağı, bu önlemin maliyeti ve bu maliyet çerçevesinde riskin nasıl takip edileceği belirlenerek her risk için bir plan hazırlanır.

**Soru 6** (derste sözlü, 01:17:08): Proje plan dokümanında neler olmalıdır?

> **Cevap (derste verildi):** Proje tanımı (amaç, kapsam, temel teslim edilecekler, iş gereksinimi ya da fırsatı, finansal tahmin), tamamlanma kriterleri, iş planı (WBS, iş listesi, kilometre taşları, zaman, bütçe, nakit akışı), proje organizasyonu, kapsam, takvim, maliyet, risk, iletişim ve kalite yönetim planları ve ekler (risk kontrol listeleri, ayrıntılı iş listesi, WBS, paydaşlar).

## Dersin Toparlaması

Bu derste proje planlama konusu toparlandı. Kitaptaki on beş planlama aktivitesi tekrar edildi; kaynakların atanması ve seviyelendirilmesi, bütçe kalemleri ve teslim edilecekler üzerinde duruldu. Riskler kitabın sınıflamasıyla (personel, donanım, müşteri, kapsam, teknoloji, dağıtım, fiziksel) yeniden ele alındı; risk tablosu, risk derecesi ve kilometre taşlarında risk takibi açıklandı. Daha önce sonraya bırakılan kabuller ve kısıtlar kaynak, dağıtım, ortam, bütçe ve işlevsel sınıflarıyla, örnekleriyle işlendi; ikisinin çoğu zaman birbirinin tersi olduğu görüldü.

Ardından bütün bu çalışmaların proje plan dokümanında nasıl yer alacağı, kitaptaki örnek içerik tablosu üzerinden gösterildi ve proje türüne göre tamamlanma kriterleri incelendi. Son olarak proje yönetiminin bir sonraki aşaması olan projeyi yürütmeye geçildi; bu aşamanın özünün planlanan ile gerçekleşenin sürekli karşılaştırılması olduğu vurgulandı. Proje organizasyonu ve ekip yapısı ile projenin kapatılması ilerideki konular olarak bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
