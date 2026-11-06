# Ders 11 Genişletilmiş Notu: Risk Yönetimi, Kazanılan Değer ve Dağıtık Ekipler Üzerine Makale Sunumları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birinci Sunum: Büyük Ölçekli Sistemlerde Yazılım Risk Yönetimi
- 2. İkinci Sunum: Kazanılan Plan, Kalite ve Riskin Kazanılan Değer Yönetimine Entegrasyonu
- 3. Üçüncü Sunum: Graf Renklendirme ile Kaynak Planlama ve Çatışma Yönetimi
- 4. Dördüncü Sunum: Küresel Yazılım Geliştirmede Proje Yönetimi Riskleri
- 5. Beşinci Sunum: Dağıtık Ekiplerde Çevik ve Scrum

Bu ders öğrencilerin makale sunumlarıyla geçti. Beş sunum yapıldı. Hoca sunumların arasında kısa sorular sordu, sunum biçimine dair geri bildirim verdi ve konuları daha önce derste gördüklerimize bağladı. Aşağıda her sunum sıra numarasıyla, kendi anlatım akışı içinde aktarılıyor.

## 1. Birinci Sunum: Büyük Ölçekli Sistemlerde Yazılım Risk Yönetimi

### 1.1 Konu ve Amaç

Sunulan makale, büyük ölçekli sistemlerde yazılım risk yönetimi tekniklerinin eleştirel bir analizidir. Çıkış noktası şudur: Yüksek kaliteli yazılım sistemleri oluşturmanın birçok riski vardır. Proje yöneticileri bu riskleri hesaplayarak ürün üzerindeki etkilerini azaltabilir. Günümüzde yazılım sistemleri giderek karmaşıklaşan büyük ölçekli sistemlerdir. Bu sistemlerde yüksek kalite ve güvenilirlik talebi olduğu için risk yönetimi, ileride değerini gösterecek bir yatırım olarak görülüyor.

Risk yönetim sisteminin temel amacı, yazılım geliştirme sırasında olası bütün riskleri **oluşmadan önce** tespit etmek ve kontrol altına almaktır. Risk yönetimi çeşitli riskleri sürekli değerlendirir, izler ve yazılım geliştirme üzerindeki olumsuz etkilerini belirler. Risklere öncelik verip onları sıralayarak karar vermek için dinamik bir yol sağlar.

Riskler tipik olarak iki sınıfa ayrılır:

- **Sistematik riskler:** Genel riskler olarak bilinir.
- **Sistematik olmayan riskler:** Spesifik riskler olarak bilinir.

Makaledeki bir tablo, yazılım geliştirmedeki risk türlerini sınıflandırıyor. Sunumda örnek olarak virüsler, hackleme ve veri kaybı sayıldı. Risk yönetim sürecinin, algılanan riskleri tanımlayabilen araçlara da ihtiyacı vardır. Makale bu araçları listeleyip sınıflandırmıştır.

<!-- BELİRSİZ: Risk türleri tablosu ve risk yönetim araçları listesi slaytta kalmış, altyazıda yalnızca birkaç örnek geçiyor. -->

Tarihsel olarak risk yönetimi, 1980'de yazılım geliştirmede açık bir süreç olarak tanıtılmıştır. Son yıllarda yazılım projelerine talep arttıkça riskler de artmış, yoğun araştırmalar bu sürece yönelmiştir.

### 1.2 Büyük Ölçekli Sistemlerin Zorluğu

Yazılım geliştirme projelerinde başarısızlık oranı artıyor. Bu projeler, diğer işletmeler gibi teknik ve pahalı kaynaklar içeriyor. Büyük ölçekli sistem geliştirmenin önemli bir sorunu, sistemin yönetilemez ve kontrol edilemez hale gelmesidir. Temel sorunlar iki tanedir: uygun gereksinimlere sahip olmamak ve gereksinimlerde sık sık değişiklik yapılması.

Büyük ölçekli sistemler yalnızca yazılımdan oluşmaz. İnsanların iletişim ağlarını ve bilgisayar ile yazılım gibi teknik kaynakları birlikte içerir. Araştırmacılar bu sistemlerde risk azaltmayı konuşurken üç noktaya odaklanıyor:

- Sistemin karşılıklı bağımlılığı.
- Riskin bileşenler arasında geçişi.
- Uzun geliştirme dönemleri.

Bu karmaşıklık nedeniyle büyük ölçekli sistemler alt bileşenlere ve alt faktörlere ayrılır. Sistemi daha küçük gruplara bölerek riski en aza indirmek mümkündür.

Sunumda bu sistemlerde risk yönetiminin zor olduğu da vurgulandı, çünkü bileşenler daha karmaşıktır. Genellikle birçok yazılım projesi geliştiricilerin söz verdiği işlevselliği ve performansı sağlar, fakat bazı projelerde belirli bir zaman ve bütçe sorunu ortaya çıkar.

> **Ders sonrası not:** Sunumda bileşenlerin "birbirinden bağımsız" olduğu söylendi; aynı sunumun başındaki "karşılıklı bağımlılık" vurgusuna göre doğrusu büyük olasılıkla "birbirine bağımlı" olmalıdır. Zorluk da bu bağımlılıktan gelir.

<!-- BELİRSİZ: Bazı projelerin zaman ve bütçe hakkındaki cümlesi hocanın sözüyle kesildi, cümlenin devamı altyazıda yok. -->

### 1.3 Risk Değerlendirme Çerçevesi

Risk azaltma, risk yöneticilerinin olası bütün risk faktörlerini belirlediği risk tanımlama süreciyle başlar. Sonraki adımlar sırasıyla şöyledir:

- Riskler kategorilere ayrılır ve önceliklendirilir.
- Yöneticiler ve üst yönetim risklerin yazılım geliştirme üzerindeki etkilerini hesaplar. Daha etkili riskler önce azaltılır.
- Yüksek etkili riskler analiz edilir.
- Risk yöneticileri riskin azaltılmasını planlar ve buna karşı teknikler uygular.
- Önlemler uygulamaya konduktan sonra süreç izlenir ve raporlanır.

Bu süreç bir döngüdür. Yöneticiler daha fazla boşluk bulursa süreç yeniden risk tanımlamadan başlar. İzleme ve raporlama aşamasında ekip üyeleri riski kontrol eder. Risk geri bildirimi proje ortakları tarafından değerlendirilir, güncellenir ve ekip üyeleriyle paylaşılır.

Makale, literatürden derlenen kapsamlı bir risk faktörleri listesi sunuyor. Bu faktörler kullanıcı seviyesi, gereksinim toplama, planlama, analiz, tasarım, uygulama ve bakım aşamalarına göre kategorize ediliyor. Bu risklerden küçük veya orta büyüklükteki işletmeler de etkilenebilir, ancak büyük ölçekli sistemler için risk değerlendirmesi başlı başına bir zorluktur.

### 1.4 Hocanın Sunum Biçimine Dair Geri Bildirimi

Hoca bu noktada sunucuyu durdurdu ve sunumun okunarak yapılmaması gerektiğini söyledi. Bunu yalnız bu sunum için değil, başkaları da aynı şeyi yapmasın diye söylediğini belirtti.

> **Hocanın vurgusu:** Slaytlarda uzun metin blokları olmaz. Makalenin aynısını okuyormuş gibi sunum yapılmaz. Slaytta hatırlatıcı kısa maddeler bulunur ki dinleyenler kolay takip etsin. Sunucu o konunun en önemli noktalarını özetleyerek anlatır.

Hoca sunum başında makalenin hangi dergide ya da konferansta yayımlandığını da sordu. Aynı soruyu sonraki sunumlarda da yineledi. Yani bir makale sunumunda önce kaynağın kendisi net olarak gösterilmelidir.

### 1.5 Risk Yönetimi Sürecinin Adımları

Karmaşık ve büyük ölçekli sistemlerde proje yöneticilerinin riskleri tahmin edip tanımlaması yeterli değildir. Projenin etkinliği için **resmi** bir risk yönetimi süreci gerekir. Sürecin sistematik olması için her adımda standartlaştırılmış yöntemler bulunmalıdır. Makalenin özetlediği süreç şöyledir:

- **Risk tahmini:** Risk yöneticileri ve proje yöneticileri riskin içeriğini tanımlar. Bu adımda ihtiyaç analizi gibi araçlar kullanılabilir.
- **Risk azaltma planlaması:** Riskler belirlendikten sonra başlar.
- **Risk önceliklendirme:** Azaltma sürecinde risklerin hangi sırayla ele alınacağını belirler.
- **Risk izleme ve raporlama:** Tanımlanan riskleri ve ölçüm sürecini takip eder.
- **İletişim ve geri bildirim:** Bütün paydaşlar için yararlıdır. Geri bildirimlerin paylaşılması, proje yöneticilerinin risklerden kaçınmasına ve etkili bir nihai ürün çıkarmasına yardım eder.
- **Risk belgeleme:** Bütün süreç kuruluşa yardımcı olmak için doküman olarak yazılır.

### 1.6 Karşılaştırılan Risk Yönetimi Modelleri

Makalenin yazarları literatürdeki risk yönetimi modellerinden ortak özellikler çıkarıp modelleri bunlara göre karşılaştırıyor. Bu karşılaştırmalı analiz, başkalarının kendine uygun modeli seçmesine yardım etmeyi amaçlıyor. Sunucu tablodaki modellerden dördünü seçerek anlattı.

**Soru:** Bunlar risk değerlendirme için kurulmuş modeller mi? **Cevap:** Evet, risk yönetimi modelleridir. Makale hangisinin hangi özellikte iyi ya da kötü olduğunu karşılaştırıyor.

| Model | Temel özellik | Kapsam ve not |
|---|---|---|
| SRE (Software Risk Evaluation, yazılım risk değerlendirmesi) | Kapsamlı bir taslak sağlar. Risk tespiti ve risk değerinin analizi için en uygun kabul edilir. Karar verme aracı olarak da kullanılır. | Risklerin anlık görüntülerini alarak sistematik izler ve ortak bir çerçeve oluşturur. Ekip üyelerini içerir, bütün paydaşları kapsamaz. |
| TRM (Team Risk Management, ekip risk yönetimi) | Operasyonel faaliyetleri ve kuruluş yapısını sunar. Yöneticiler planlı faaliyetleri sürekli bir döngü içinde yürütür. | Bütün bireyler ve paydaşlar katılır. Riskler düzenli olarak tanımlanır ve analiz edilir. |
| SoftRisk | Belgeleme fikri üzerine kuruludur. Büyük kayıplara yol açan aşırı risklere öncelik verir. | Hem genel hem de yazılıma özgü riskleri tanımlar. Grafik ve renk kullanır: yüksek riskler kırmızı, düşük riskler yeşil. |
| Riskit | Teorik olarak geliştirilmiş ve risk yönetimine uygulanmıştır. Niteliksel risk analizine dayanır. | Bütün paydaşları içerir. SRE'den farkı budur ve bu başarısızlık nedenlerini bir ölçüde azaltabilir. Riskleri belirleme ve izleme ile sürekliliği sağlar. |

> **Ders sonrası not:** Altyazıda "SR", "TLM", "Soft Risk" ve "Risk kit" diye geçen adlar büyük olasılıkla SRE (Software Risk Evaluation), TRM (altyazıda bir yerde "TRM" diye de geçiyor), SoftRisk ve Riskit modelleridir.

Sunucu ayrıca makaledeki proje risk yönetim çerçevesini özetledi. Burada iki ana faaliyet kategorisi var. Risk tanımlama ile başlanır, olası bütün riskler listelenir, ardından analiz ve önceliklendirme yapılıp bir risk yönetimi planı oluşturulur. Çerçeve, riskin gerçekleşmesi durumunda ne yapılacağını da planlar. Nicel analizler kullanır ve var olan ile gelecekte oluşabilecek riskleri güncellemek için gözlem yapar.

<!-- BELİRSİZ: Karşılaştırma tablosu ve "iki ana faaliyet" kategorileri slaytta kalmış, altyazıda adları net değil. Sunucu büyük ölçekli proje tablosunun yazılarının da okunmadığını söyledi. -->

### 1.7 Önerilen Yöntem

Makalenin önerdiği yöntem, risk faktörlerini kullanıcı, gereksinim, planlama, analiz, tasarım, uygulama ve bakım seviyelerine ayırıp her kategori için kural ve ilkeler tanımlıyor. Yöntem şu adımlardan oluşur.

**Hazırlık adımları:**

- **Rol ve sorumluluk atamaları:** Üst yönetim atar. Roller herkesin yeteneğine göre verilir. Önemli olan, herkesin yeteneğini bilen deneyimli bir yöneticinin bu atamayı yapmasıdır.
- **Riskleri kontrol ve izleme:** Ekip üyeleri izlenir, onlarla iletişim kurulur, süreç yapılandırılır. Üst yönetimle iletişim planları ve geri bildirimler de bu adımdadır.
- **Spesifik risk azaltma modeli seçimi:** Az önceki modellerden kuruluşa uygun olanına üst yönetim karar verir. Seçilen model projeye göre değerlendirilir.
- **Resmi işlem grupları:** Sözleşmeler ve bütün yasal belgeler hazırlanıp imzalanır.

**Seviyelere göre risk azaltma:**

- **Kullanıcı seviyesi:** Düşük kullanıcı katılımı veya yeni teknoloji hakkında yeterli bilgi olmaması gibi kullanıcıdan kaynaklanan risklerdir. Kuruluş kullanıcıları yeni teknoloji konusunda eğitir, bütün paydaşlarla iletişim planları kurar ve son adımda müşteri memnuniyeti geri bildirimi alır.
- **Gereksinim seviyesi:** Kullanıcı ihtiyacını açıklayamayabilir ya da gereksinimler sık değişebilir. Bu riskler gereksinim yönetimiyle ele alınır. Üst yönetim bütün değişikliklerle ilgilenir, kuruluş müşteriden gelen periyodik geri bildirimleri değerlendirir.
- **Planlama, analiz, tasarım, uygulama ve bakım seviyeleri:** Hoca ile sunucu bu seviyeleri derste gördüğümüz için atlamaya karar verdi.

**Düzeltilmiş risk değerlendirmesi:** Herhangi bir riskin yeniden ortaya çıkması durumunda risk azaltmadan sonra uygulanır. Böylece süreç sürekli yeniden değerlendirilir. Dört adımı vardır: risk kontrol önlemlerini gözden geçirme, yeniden planlama ve değerlendirme, geri bildirim ve iletişim ile kalite ölçüsü. Sonunda belgeler güncellenir.

**Niteliksel ve niceliksel analiz:** Son adımda bütün sürece iki tür analiz uygulanır. Niteliksel analiz için grafik, çizelge ve sunumlar hazırlanır. Niceliksel analiz için üst yönetim anket ve mülakat yapar.

> **Ders sonrası not:** Sunumda mülakat niceliksel analiz aracı olarak sayıldı; araştırma yöntemlerinde mülakat genellikle niteliksel veri toplama aracı sayılır, bu eşleştirme büyük olasılıkla makaledeki ifadenin ya da aktarımın gevşekliğinden kaynaklanıyor.

### 1.8 Sonuç

Yazılım geliştirmede en önemli işlerden biri risk faktörlerini değerlendirmek ve kontrol etmektir. Son yıllarda birçok teknik ve destek aracı önerildi. Kuruluşlar arasındaki sert rekabet, ürün kalitesini ve risk değerlendirmesini iyileştirmek için bu tekniklerin kullanılmasını zorunlu kılıyor.

Makalenin katkısı iki yönlüdür: kapsamlı bir risk faktörleri ve destek araçları listesi ile modellerin karşılaştırmalı analiz tablosu. Tablodan çıkan sonuç, farklı özelliklere sahip her modelin farklı ortamlarda uygulanabileceğidir.

## 2. İkinci Sunum: Kazanılan Plan, Kalite ve Riskin Kazanılan Değer Yönetimine Entegrasyonu

### 2.1 Konu ve Amaç

Bu sunumu iki öğrenci birlikte yaptı. Makale 2019 tarihli bir IEEE dergi makalesidir. Geleneksel kazanılan değer yönetimine (Earned Value Management, EVM) kazanılan plan (earned schedule), kalite ve risk ölçütlerini eklemeyi konu alıyor. Sunum önce geleneksel yöntemi, sonra eklenen ölçütleri anlatıyor.

<!-- BELİRSİZ: Hoca derginin "IEEE Software" mı yoksa bir "Project Management" dergisi mi olduğunu sordu; verilen cevaplardan derginin adı net anlaşılmıyor. -->

Hoca, herkesin konuyu İngilizce terimleriyle okuduğunu hatırlatarak terimin İngilizcesinin söylenmesini istedi: earned value. Ayrıca dersle bağlantısını kurdu: Earned value management, daha önce fizibilite analizinde, ekonomik fizibilite kavramları içinde geçmişti.

### 2.2 Geleneksel Kazanılan Değer Yönetimi

Kazanılan değer yönetimi bir performans ve geri bildirim aracıdır. Proje yönetiminde sıkça kullanılır. Projenin mevcut durumunu ve ilerleyişini zaman, maliyet ve kapsam boyutlarından inceler. Böylece projenin gerçek maliyetini, tamamlanma zamanını ve tamamlanma maliyetini karşılaştırmayı sağlar.

Yöntemin üç temel bileşeni vardır. Projenin verimli olup olmadığı bunlardan çıkarılır:

- **Planlanan değer (Planned Value, PV):** Değerlendirilen zaman için projeye ayrılan bütçedir.
- **Kazanılan değer (Earned Value, EV):** Projenin herhangi bir anında gerçekleşen ilerlemenin karşılığı olan değerdir. Yani yapılan işin bütçelenmiş maliyetidir.
- **Gerçekleşen maliyet (Actual Cost, AC):** Tamamlanmış bütün işler için harcanmış kaynakların toplamıdır. Yani yapılan işin gerçek maliyetidir.

Bu bileşenlerden iki grup gösterge çıkar: maliyet göstergeleri ve zaman göstergeleri. Her grupta bir fark (varyans) ve bir oran (performans endeksi) vardır.

**Maliyet varyansı (Cost Variance, CV)** proje performansı ile gerçekleşen maliyet arasındaki ilişkiyi gösterir:

$$CV = EV - AC$$

**Maliyet performans endeksi (Cost Performance Index, CPI)** bütçedeki kaynakların maliyet verimliliğinin ölçüsüdür:

$$CPI = \frac{EV}{AC}$$

**Zaman çizelgesi varyansı (Schedule Variance, SV)** proje performansı ile planlanan değer arasındaki ilişkiyi gösterir:

$$SV = EV - PV$$

**Zaman çizelgesi performans endeksi (Schedule Performance Index, SPI)** ekibin zamanını ne kadar verimli kullandığının ölçüsüdür:

$$SPI = \frac{EV}{PV}$$

Bu dört göstergenin yorumu aynı kalıptadır:

| Gösterge | Pozitif farkta ya da oran $> 1$ iken | Fark $0$ ya da oran $= 1$ iken | Negatif farkta ya da oran $< 1$ iken |
|---|---|---|---|
| $CV$, $CPI$ | Bütçenin altında | Bütçeye uygun | Bütçenin üzerinde |
| $SV$, $SPI$ | Planın ilerisinde | Plana uygun | Planın gerisinde |

Fark ile oran aynı bilgiyi iki biçimde verir: $EV > AC$ ise hem $CV > 0$ hem $CPI > 1$ olur. Zaman tarafında da aynı şey $EV$ ile $PV$ için geçerlidir.

Sunumdaki örnek grafik sayısal değer verilmeden yorumlandı. Grafikte gerçekleşen maliyet eğrisi kazanılan değer eğrisinin üzerindedir, yani $AC > EV$. Fark negatif çıkar, proje bütçeyi aşmıştır. Aynı şekilde planlanan değer eğrisi kazanılan değerin üzerindedir, yani $PV > EV$. Fark yine negatiftir, proje zaman planının gerisinde kalmıştır.

<!-- BELİRSİZ: Grafiklerdeki eksen değerleri slaytta kalmış, altyazıda sayısal değer geçmiyor. Sunumda EVM için sayısal örnek çözülmedi. -->

### 2.3 Geleneksel Yöntemin Zayıflıkları

Makale bu terimleri geleneksel yöntemin sınırlarını aşmak ve daha ayrıntılı analiz yapabilmek için ekliyor. Sayılan dört eksiklik şöyledir.

**Proje ilerledikçe zaman göstergelerinin bozulması.** Kazanılan değer yönetiminde projenin zamanında olup olmadığı izlenebilir, ancak proje ilerledikçe zaman göstergeleri bozulur. Projenin sonunda kazanılan değer ile planlanan değer arasındaki fark sıfıra eşit olur. Bu da proje programın gerisinde olsa bile zamanındaymış gibi görünmesine yol açar.

> **Ek bilgi (derste anlatılmadı):** Bunun nedeni iki değerin de aynı toplama ulaşmasıdır. Proje tamamlandığında bütün işler yapılmış olduğu için $EV$ toplam bütçeye (Budget at Completion, BAC) eşit olur. Planlanan bitiş tarihi geçtiğinde $PV$ de toplam bütçeye eşittir. Bu yüzden proje gecikerek bitse de sonda $SV = 0$ ve $SPI = 1$ çıkar.

**Farklı maliyet türlerinin gösterilememesi.** Başlangıçta yalnız projeyi yürütmek için gereken kaynakların tahmini maliyeti belirlenir. Kalite maliyetleri ve ölçülmemiş risklerle ilgili maliyetler proje başladıktan sonra ortaya çıkabilir. Geleneksel yöntem bunları hesaplamaz.

**Tek risk ölçüsü olması.** Yöntemde tanımlı tek risk ölçüsü tamamlanmadaki varyanstır (Variance at Completion). Oysa bildiğimiz yaygın riskler maliyet riski, zamanlama riski ve performans riskidir. Tek ölçü eksik bilgi verir. Örneğin mali aşım riski ayrıca görülmezse projenin bütçenin çok üzerinde ilerlediği fark edilmeyebilir.

**Kalitenin programa etkisinin gösterilmemesi.** Yöntemde kalite metrikleri yoktur, dolayısıyla kalite nesnel olarak ölçülemez. Proje sonunda kalite gereksinimleri karşılanmazsa iş yeniden yapılır. Bu da yeniden çalışma (rework) maliyeti ve süresi doğurur.

Sunuculara göre makaledeki yeni model bu eksiklikleri doğrudan hedefliyor. Literatürde bu kavramları **eş zamanlı olarak** EVM'ye entegre eden başka çalışma bulunmadığı belirtiliyor.

### 2.4 Zaman Ölçütleri

Modelin zaman tarafına eklenen ölçütler şunlardır:

- **Planlanan süre:** Her kilometre taşını tamamlamak için gereken süre verildiğinde beklenen toplam süre. Yani başlangıçta planlanan süredir.
- **Gerçek zaman:** Projenin devam ettiği toplam süre.
- **Kazanılan plan (earned schedule):** Projenin program açısından nasıl ilerlediğini anlatır. Tamamlanan periyot sayısı ile eksik kalan periyodun tamamlanan kısmının toplamıdır.
- **Plan varyansı:** Projenin kendisine ayrılan zamana kıyasla tamamlanan iş için ne kadar ek zaman harcadığını gösterir. Sıfırdan büyükse proje planlanandan hızlı ilerliyordur, sıfıra eşitse plana uygundur, sıfırdan küçükse planın gerisindedir.
- **Zamanlama performans endeksi:** Gerçek zamanın her bir periyodunda, planlanan periyoda göre projenin ne kadar ilerlediğinin ölçüsüdür.

Kazanılan plan, sözlü anlatıma göre şöyle yazılabilir. Burada $C$ tamamlanan periyot sayısı, $I$ ise eksik periyodun tamamlanan kısmıdır:

$$ES = C + I$$

<!-- BELİRSİZ: Formüller slaytta kalmış. Altyazıda "tamamlanan periyot sayısı artı eksik kısım" ve "C'deki beklenen değer" ifadeleri geçiyor; $I$ gösterimi altyazıda geçmiyor. Plan varyansı için de sonuç "PV" diye okunmuş ve "önceki formülle aynı" denmiş, slayttaki gerçek formül görülemiyor. -->

> **Ek bilgi (derste anlatılmadı):** Kazanılan plan literatüründe eksik kısım, $EV$'nin $C$ ile $C+1$ periyotları arasındaki planlanan değerler arasında nereye düştüğüne göre bulunur: $I = (EV - PV_C) / (PV_{C+1} - PV_C)$. Zaman tabanlı göstergeler de gerçek zaman $AT$ ile $SV(t) = ES - AT$ ve $SPI(t) = ES / AT$ olarak tanımlanır. Bu göstergeler para değil zaman birimiyle çalıştığı için proje sonunda sıfıra yakınsama sorunu yaşamaz.

### 2.5 Kalite Ölçütleri

Kalite tarafındaki ölçütler şunlardır:

- **Kalite gereksinimleri:** Projenin her kilometre taşının çıktısı için belirlenen özelliklerdir. Bir kilometre taşının tek veya birden fazla kalite gereksinimi olabilir. Planlama aşamasında paydaşlarca belirlenir. Net olmaları kapsam kaymasını (scope creep) önler.
- **Kalite indeks numarası:** Bir kilometre taşı çıktısı için kalite gereksinimi derecelendirmelerinin ortalamasıdır. Gereksinimlerin ne kadarının karşılandığını gösterir.
- **Kazanılan kalite değeri:** Kazanılan değerin kalite gereksinimlerini karşılayan kısmıdır.
- **Kalite varyansı:** Kazanılan değerin yeniden işlenmesi gereken kısmıdır.
- **Kalite performans endeksi:** Geleneksel yöntemdeki performans endekslerine benzer. Projenin kalite gereksinimlerini karşılamadaki etkinliğini gösterir. Yapılan bütün işleri ve yeniden çalışmayı dikkate alarak ilk seferde doğru yapılan görevlerin oranını temsil eder.
- **Tahmini yeniden çalışma maliyeti:** Uygunsuzluğu ortadan kaldırmak için yapılması gereken düzeltici eylemin planlanan ek maliyetidir. Kalite problemine bağlı riskin hesabında girdi olarak kullanılır.
- **Tahmini yeniden çalışma süresi etkisi:** Yeniden çalışmaya atfedilen genel proje programı gecikmesidir.

Kalite ancak kilometre taşı tamamlandıktan sonra ölçülebilir. Bu yüzden kazanılan kalite değeri de o zamana kadar hesaplanamaz. Kilometre taşı devam ederken kazanılan kalite değerinin kazanılan değere eşit olduğu varsayılır. Tamamlanan her kilometre taşı için hesap şöyledir:

$$\text{Kazanılan kalite değeri} = EV \times \text{Kalite indeks numarası}$$

Yeniden çalışma süresinde önemli bir ayrım vardır. Yeniden çalışma gerektiren kilometre taşı kritik yolda değilse ve süreyi karşılayacak yeterli esnek zaman (slack) varsa, tamamlanma sırasındaki zaman farkı etkilenmez. Yani her yeniden çalışma projenin bitişini geciktirmez.

<!-- BELİRSİZ: Kalite varyansı, kalite performans endeksi ve kazanılan kalite değeri tanımındaki bazı ifadeler altyazıda bozuk ("kalite gerekliklerine geçen kısım" gibi); slayttaki formüller görülemiyor. -->

### 2.6 Risk Ölçütleri

Risk tarafında dört tür ölçüt var.

**Yeniden çalışma maliyeti etki oranı** şöyle hesaplanır. Maliyet etkisi, fiili yeniden çalışma maliyetinin kümülatif değeri ile tahmini yeniden çalışma maliyetinin toplamıdır:

$$\text{Yeniden çalışma maliyeti etki oranı} = \frac{\text{Maliyet etkisi}}{AC}$$

**Yeniden çalışma süresi etki oranı** da benzer biçimde tanımlanır. Zaman etkisi, gerçek yeniden çalışma süresi etkisinin kümülatif değeri ile tahmini yeniden çalışma süresinin toplamıdır:

$$\text{Yeniden çalışma süresi etki oranı} = \frac{\text{Zaman etkisi}}{\text{Gerçek süre}}$$

> **Ders sonrası not:** Sunumda bu oran "zaman etkisi bölü gerçek maliyet" diye okundu; oran süreyle ilgili olduğu için ve maliyet tarafındaki oranla simetrisine göre payda büyük olasılıkla gerçek süredir.

**Maliyet riski değeri**, projenin mevcut durumu göz önüne alındığında maliyet farkının ne kadar olacağını ölçer. Geçerli zamandaki yeniden çalışma maliyeti miktarının, kalan görevlerdeki yeniden çalışma maliyeti miktarıyla orantılı olacağını varsayar. **Zaman çizelgesi risk değeri** ise mevcut performansa göre projenin toplam zamanlama varyansını ölçer.

**Maliyet risk indeksi**, projenin planlanan maliyeti açısından maliyet riskinin ne kadar kritik olduğunu ölçer. **Zaman çizelgesi risk indeksi** de planlanan süre açısından program riskinin ne kadar kritik olduğunu gösterir.

<!-- BELİRSİZ: Maliyet riski değeri ve zaman çizelgesi risk değeri formülleri slaytta kalmış; sunucu "uzun ve detaylı" diyerek formüle girmedi. Altyazıda maliyet risk indeksi için "zamanlanan maliyet" geçiyor; "planlanan maliyet" bağlamdan çıkarıldı. -->

Hoca sunumun sonunda bu çalışmanın önemini belirtti: Sunumlarda ekonomik göstergelerle ilgili pek konuşan olmamıştı, yığılmalar farklı konulardaydı. Bu sunum bu açıdan farklıydı.

## 3. Üçüncü Sunum: Graf Renklendirme ile Kaynak Planlama ve Çatışma Yönetimi

### 3.1 Konu ve Amaç

Makale, 2020'de Hindistan'da yapılan uluslararası bir teknoloji ve inovasyon konferansında sunulmuş, iki yazarlı bir IEEE bildirisidir. Proje yönetiminde kaynak planlama ve çatışma yönetimi için graf renklendirme tekniğini kullanan bir algoritma öneriyor. Hoca, sunucunun makaleyi baştan göstermesinin iyi olduğunu söyledi.

**Soru:** Buradaki çatışma yönetimi, paydaşların farklı istekleri açısından mı? **Cevap:** Hayır. Burada çatışma daha çok ortak kaynak kullanımına yöneliktir.

Problem şudur: Proje yönetimi sıkı teslim tarihleri ve maddi bağımlılıklar içerir. Bir kuruluş sınırlı kaynaklarla birden fazla proje yürütebilir ve aynı kaynağa birden fazla projede ihtiyaç duyulabilir. Yine de zaman çizelgelerine bağlı kalıp en yüksek verimlilikle çalışmak gerekir. Günlük iş gücünü tahmin etmek ve kaynakları farklı projelere kolayca yeniden tahsis etmek için doğru çalışan araçlara ihtiyaç vardır. Bu çalışma, çatışmaları çözmek ve proje planını daha iyi temsil etmek için graf renklendirmeyi öneriyor.

### 3.2 Graf Teorisi Temelleri

Sunucu önce Königsberg köprüleri problemini anlattı. Problem şunu sorar: Başlangıç ve bitiş noktası aynı olacak şekilde yedi köprünün her birinden yalnız bir kez geçerek başlangıç noktasına dönmek mümkün müdür? Graf gösteriminde düğümler kara bölgelerini, kenarlar köprüleri gösterir.

> **Ders sonrası not:** Sunumda problemin "öyle" diye duyulan biri tarafından ortaya atıldığı söylendi; bu büyük olasılıkla Euler'dir. Euler büyük olasılıkla problemi ortaya atmamış, çözmüş ve böyle bir yolun bulunmadığını göstermiştir.

Graf, köşe (vertex) ve kenar (edge) kümelerinden oluşan bir çifttir:

$$G = (V, E)$$

Burada $V$ boş olmayan sonlu bir kümedir. $E$ ise $V$'nin farklı elemanlarının sırasız çiftlerinden oluşur. Graflar sade olabileceği gibi ağırlıklı veya yönlü de olabilir. Graf teorisi seyahat eden satıcı problemi, ağ kurulumu ve tasarımı ile devre tasarımı gibi birçok problemin çözümünde görsel bir temsil sunar.

**Graf renklendirme (graph coloring)**, yönsüz bir grafın köşelerini en az sayıda renk kullanarak boyama problemidir. Tek kural vardır: Bitişik iki köşe aynı rengi paylaşamaz. Uygulama alanları arasında harita oluşturma ve görev ayırma sayıldı.

**Kromatik sayı (chromatic number)**, bir grafı doğru renklendirmek için gereken en az renk sayısıdır. Daha az renkle boyanamayan, yani en iyi renklendirmeye ulaşılmış grafa $k$-kromatik graf denir. Buradaki $k$, $G$ grafının kromatik sayısıdır.

### 3.3 Literatür ve Terimler

Makale üç yaklaşımı önceki çalışmalar olarak anıyor:

- **Kritik zincir proje yönetimi (Critical Chain Project Management, CCPM):** Prof. Goldratt tarafından sunulmuştur. Çoklu proje girişimlerinin yönetilmesini, zamanlanmasını ve kontrolünü sağlar. Anahtar unsurları varlıklar, görevler, zaman ve görevin önemidir. Görevin önemi, bütün faaliyetlerin akışını belirleyen temel faktör kabul edilir.
- **Optimizasyon teknikleri:** Planları hazırlamak, çatışmaları çözmek ve gereken en az adım sayısını belirlemek için karınca kolonisi optimizasyonu gibi yöntemler inceleniyor.
- **Zaman çizelgesi planlama teknikleri:** Aynı kaynaklara talep olan birden fazla proje durumunda artan kaynak kısıtlı projeler için kullanılıyor.

Makale ardından kullandığı terimleri özetliyor. Sunucu bunların bir kısmının derste de görüldüğünü belirtti:

- **Planlama:** Hangi görevlerin hangi dönemde bitirileceğini ve hangi varlıklara atanacağını bilen bileşendir.
- **Görev planı:** Programa göre yapılması beklenen bütün işleri bir araya getiren kayıttır. Projenin temelini oluşturur ve maliyet, zaman ve kapsam unsurlarını etkiler.
- **Proje yönetimi:** Zaman, maliyet ve kapsam sınırları içinde hedeflere ulaşmak için prosedürlerin, yeteneklerin, bilgi ve deneyimin kullanılması sürecidir. Proje Yönetimi Enstitüsü'ne (Project Management Institute, PMI) göre beş aşaması vardır: başlatma, planlama, yürütme, izleme ve kapanış.
- **Kaynak yönetimi:** Kaynak, çalışanların yeteneklerinden başlayarak bir görevin yerine getirilmesi için gereken şeydir. Kaynak yönetimi, kaynakların tanımlanması, elde edilmesi ve yönetilmesi sürecidir.
- **Kritik yol yöntemi (Critical Path Method, CPM):** Kritik yol, projenin bitiş tarihine kadar tamamlanması gereken en uzun aktivite dizisidir. Kritik yoldaki bir aktivite, önceki aktivite tamamlanmadan başlatılamaz. Temel adımları bütün işlerin özeti, işler arasındaki koşullar ve her işin süresidir.

> **Ders sonrası not:** Sunumda CPM "Critical Path Management" diye açıldı; yerleşik açılım Critical Path Method'dur, makalede de büyük olasılıkla bu kastediliyor.

### 3.4 Önerilen Yöntem

Yöntem, proje planlamada kaynak gösterimi ve çatışma yönetimi sorununu graf renklendirmeyle ele alıyor. Model şöyle kurulur:

- Her görev ya da takım bir köşeyle gösterilir.
- İki görev aynı kaynağa ihtiyaç duyuyorsa aralarına bir kenar çizilir. Böylece farklı renk almaları gerekir.
- Köşe ağırlıkları görevin önceliğini gösterir. Ağırlıklı graf sayesinde optimize edilmiş bir proje planı hazırlanır.
- Gerektiğinde bir görevden kaynak çıkarılarak ya da göreve kaynak eklenerek çatışma çözülür.

Aynı renkteki görevler aynı kaynağı istemediği için birlikte yürütülebilir. Bu yüzden renk sayısı projenin kaç turda tamamlanacağını gösterir: Bir kaynak bir görevde kullanıldıktan sonra diğerine geçer.

### 3.5 Örnek: Yedi Takım

Projeyi zamanında bitirmek için A'dan G'ye yedi takım belirlenmiş. Slaytın alt tarafında bu takımların talep ettiği kaynaklar, yani iş gücü gösteriliyor. Bazı kaynaklar birden çok takımın parçasıdır. Örneğin bir takım lideri C ve D gruplarına birlikte liderlik edebiliyor. Her takımın, proje yöneticisinin istediği sürede tamamlaması gereken bir görevi var.

**Adım 1: Grafı kurma.** Her takım bir köşedir. Takımlar arasındaki her kaynak çatışması bir kenardır.

**Adım 2: Renklendirme.** Graf en az dört renkle doğru biçimde boyanabiliyor (kırmızı, yeşil, sarı, mavi). Kromatik sayı 4'tür. Yani projeyi tamamlamak için en az 4 tur gerekir.

**Soru:** Kromatik sayı yol sayısı mı? **Cevap:** Hayır. Köşelere renk veriliyor. Aralarında kaynak bağımlılığı olanlar farklı renkte olmak zorunda. Kromatik sayı kullanılan en az renk sayısıdır, burada 4'tür.

**Adım 3: Yorum.** Kromatik sayı ne kadar küçükse kaynak çatışması o kadar azdır. Bu da projedeki bekleme döngülerinin daha az olması demektir. Ağırlıklar ise görevlerin gerçekleştirilme sırasında öncelik vermeyi sağlar.

**Adım 4: Kaynağı çıkarma.** Takım lideri 3 dört takımda yer aldığı için aşırı yük altındadır. D takımından çıkarılması durumuna bakılıyor. Grafta D'nin C, E ve F ile bağlantısı yalnız bu takım lideri nedeniyle vardır. Bu bağlantılar kapanınca iki ayrı grup ortaya çıkıyor.

**Adım 5: Sonuç.** Sunuma göre kromatik sayı 2'ye iniyor. Proje 2 turda, daha az bekleme süresiyle ve atanan öncelikler korunarak yürütülebiliyor.

> **Ders sonrası not:** Sunumda takım lideri 3'ün dört takımda (D, C, E, F) olduğu ve D'den çıkarılınca kromatik sayının 2'ye indiği söylendi. Lider C, E ve F'de kalıyorsa bu üç takım hâlâ ortak kaynak paylaşır, birbirine komşu olur ve kromatik sayı en az 3 olur. Altyazıdaki bilgilerle 2 sonucu tutmuyor; graf görülemediği için kesin değil, ama takım dağılımı büyük olasılıkla sunumda eksik aktarılmıştır.

<!-- BELİRSİZ: Takım-kaynak tablosu ve graf çizimi slaytta kalmış, bütün kenarlar altyazıdan çıkarılamıyor. Örnekte C ve D'ye liderlik eden kişinin takım lideri 3 olup olmadığı da net değil. -->

### 3.6 Uygulama Önerileri ve Sonuç

Yöntem mevcut zamanlama teknikleriyle birleştirildiğinde çatışmaları daha iyi temsil etme ve ağırlıklara dayalı karar alma fırsatı sunuyor. Görev ve proje öğesi sayısı arttıkça yöntem karmaşıklaşıyor, çünkü dikkate alınacak unsur çoğalıyor. Yine de çatışma temsili mevcut yöntemlere kıyasla kolaylaşıyor.

Uygulama için iki seçenek öneriliyor:

- **API olarak:** Gantt şeması gibi mevcut yöntemleri kullanan araçlara eklenen bir programlama parçası gibi düşünülebilir. Algoritma, başka bir programdan görev ve kaynak parametrelerini alıp işleyebilir.
- **Bağımsız çözüm olarak:** Ayrı bir uygulama ya da proje yönetimi portföyünü tamamlayan daha büyük bir paketin parçası olabilir.

Sonuç olarak yöntem CPM, CCPM ve Gantt tekniklerini tamamlayabilir. Kaynak tahsisi veya yeniden planlama senaryoları karşılaştırıldığında, örnekteki gibi kromatik sayının düşürülmesinin bekleme süresini büyük ölçüde azalttığı ve proje üzerinde büyük etki yaptığı gösteriliyor.

## 4. Dördüncü Sunum: Küresel Yazılım Geliştirmede Proje Yönetimi Riskleri

### 4.1 Konu ve Amaç

Makale 2016'da yayımlanmış, proje yönetimi alanında bir konferans bildirisidir. Küresel yazılım geliştirmede (global software development) proje yönetimi risklerini belirlemek için bütünleştirici bir çerçeve sunuyor.

<!-- BELİRSİZ: Yayın yerinin adı altyazıda "Aytır Guli Project Management" diye bozuk geçiyor. -->

Küresel yazılım geliştirme, uzak konumlardaki ve muhtemelen farklı sosyo-kültürel yapıdaki paydaşların yaşam döngüsüne katıldığı bir yazılım üretme biçimidir. Paydaşların zamansal, coğrafi ve sosyo-kültürel dağılımı, zaten karmaşık olan projelerin yönetimini daha da karmaşıklaştırır. Şirketler bunu proje maliyetini ve teslimat süresini azaltmak, potansiyel müşterilere yakın olmak ve değişen sektörde esnek kalmak için benimser.

Araştırmanın amacı, proje yönetimi faaliyetleriyle ilişkili zorlukları belirlemek ve bunları kapsayan bir çerçeve sunmaktır. Önceki araştırmalara bakıldığında bütün risk faktörlerini tam olarak kapsayan bir çalışma görülmemiş.

Risk yönetimi süreci, yönetim politikalarının riski tanımlama, analiz etme, değerlendirme, bağlam oluşturma, iletişim kurma, izleme ve gözden geçirme faaliyetlerine sistematik olarak uygulanmasıdır. Risk faktörü de bir olayın meydana gelme olasılığı ile proje üzerindeki etkisinin birleşimi olarak ifade edilir.

### 4.2 Yöntem

**Sistematik literatür incelemesi.** Belirli bir araştırma sorusu için yayımlanmış birincil çalışmaları tanımlama, analiz etme ve değerlendirmenin yöntemsel sürecidir. Üç aşaması vardır:

- **Arama stratejisi:** Araştırma sorusu formüle edilir, arama dizesi ve sorgulanacak kaynaklar belirlenir.
- **Çalışma seçimi:** Arama yapılır, dahil etme ve dışlama kriterleri uygulanır.
- **Veri çıkarma ve analiz.**

Bu inceleme sonunda 39 risk faktörü belirlenmiş.

**Leavitt'in organizasyonel değişim modeli.** Risk faktörleri bu modele göre sınıflandırılmış. Model, her organizasyonu dört etkileşimli bileşenden oluşmuş olarak görür:

- **Aktörler (people):** Kullanıcılar, yöneticiler ve geliştiriciler dahil bütün paydaşlar.
- **Yapı:** Proje organizasyonu ve diğer kurumsal düzenlemeler.
- **Teknoloji:** Geliştirme araçları, yöntemleri, yazılım ve donanım platformları.
- **Görev:** Hedefler ve çıktılar açısından beklenen sonuçlar.

Modele göre kuruluşun kaderini bu dört bileşen arasındaki etkileşim belirler. Birindeki değişiklik diğerlerini de etkiler. Makale bu bileşenlerin yazılım geliştirme kavramlarına kolayca dönüştürülebileceğini savunuyor. Bileşen çiftleri arasındaki karşılıklı bağımlılıklar altı risk kategorisi veriyor.

> **Ders sonrası not:** Altyazıda "Levit" diye geçen model büyük olasılıkla Harold Leavitt'in organizasyonel değişim modelidir.

### 4.3 Altı Risk Kategorisi

**Görev-aktör.** Risk faktörleri esas olarak aktörün görevi yapmak için ihtiyaç duyduğu bilgiyle ilgilidir:

- Geliştirme siteleri arasındaki dil ve terminoloji farkları. Yanlış yorumlamaya ve aktarılmayan bilgiye yol açar.
- Farklı bilgi seviyelerinin yarattığı zorluklar.
- Etkili iletişim eksikliği. Bilgi yönetimi sorunları doğurur.
- Gerçek zamanlı iletişim kuramama. İş birliği sorunlarına yol açar.
- Görev belirsizliği. Gerekli bilgi eksikliğini gösterir ve değişim sürecini yavaşlatır.
- Kötü hazırlanmış belgeler ve sınırlı çalışma deneyimi.

**Görev-yapı.** Geliştirme görevi ile iş akışı, politikalar, sistemler ve süreçler arasındaki etkileşimlerden doğar. Proje planlama, koordinasyon, kontrol ve insan kaynakları yönetimi görevleriyle eşleştirilmiştir. Açık farkla en çok risk faktörü bu kategoridedir:

- Zamansal ve coğrafi dağılım. Yöneticinin planlama ve izleme becerisini karmaşıklaştırır.
- Zayıf risk yönetimi ve zayıf kalite yönetimi.
- Sürümlerin ve izlenebilirliğin kötü yönetimi.
- Sınırlı yüz yüze etkileşim. Sosyal ilişkileri zayıflatır.
- Yetersiz hedef dağılımı ve görev yorumlaması.
- Yetersiz ayrıntılı planlama. Bazı işlerin eksik ya da birden çok kez yapılmasına yol açar.
- Rol ve sorumlulukların kötü belirlenmesi, grup bilinci eksikliği, karşılıklı bağımlılığın zor yönetilmesi.
- Etkisiz koordinasyon. Kilometre taşlarının yetersiz ele alınmasına yol açar.
- Verimsiz izleme ve kontrol, büyük hatalar ve hata takibi. Yüksek maliyete yol açar.
- Organizasyon yapısını proje ihtiyaçlarına uyarlamama.
- Yasal konuların kötü yönetilmesi.

**Görev-teknoloji.** Görev gereksinimlerini karşılamak için uygun teknolojinin seçilmesiyle ilgilidir. Risk faktörleri, araçların uyumsuzluğu ve yaşam döngüsünün tamamını kapsayan araçların eksikliğidir.

**Aktör-yapı.** Paydaşların sosyo-kültürel değerlerinin, normlarının ve davranışlarının iş akışını nasıl etkilediğiyle ilgilidir. Risk faktörleri şunlardır: geliştirme siteleri ve ekipler arasındaki kültürel çeşitlilik, çalışma kültürü farkları, kültürel önyargı, çatışma yönetimi, iş kaybı korkusu, sınırlı iletişim olanağı ve sınırlı yüz yüze toplantı.

**Aktör-teknoloji.** Deneyimsiz kullanıcıların bilinmeyen ve karmaşık teknolojilerle eşleştirilmesi ya da denenmemiş teknolojilerin getirilmesi sorunudur. Risk faktörleri, iletişim ve iş birliği araçlarında eğitim eksikliği ile küresel geliştirme araçlarını kullanmada sınırlı deneyimdir.

**Yapı-teknoloji.** Kullanılan teknolojiye uygun olmayan bir yapının ya da mevcut yapıya uygun olmayan bir teknolojinin seçilmesinden doğar. Bu uyumsuzluk iş akışını bozar ve üretkenliği azaltır. Dağıtık ortamda güvenlik ve gizlilik de yeni bir zorluktur. Risk faktörleri, uygun olmayan bilgi ve iletişim teknolojisi seçimi, zayıf iş birliği ve iletişim altyapısı, ağ güvenliği ve yetkisiz erişimdir.

<!-- BELİRSİZ: Görev-yapı listesinde "site işlemlerinin izalanmaması" diye geçen madde altyazıda bozuk olduğu için listeye alınmadı. 39 faktörün tam listesi slaytta; yukarıdaki sayım altyazıdakine dayanır. -->

### 4.4 Sonuç

Küresel yazılım geliştirme, yazılım üretmenin ana akım yollarından biri haline gelmiştir. Şirketler avantajlarından kolayca etkilenir, ama zorlukların üstesinden gelecek yeteneklerden genelde yoksundur. Proje yöneticileri bu tehditlerin farkında olmalıdır.

Çerçeve, bu projelere özgü riskleri kapsayan güncel ve geniş bir liste sağlıyor. Ancak yalnızca risk tanımlama için temel görevi görür ve her projeye farklı şekilde uyarlanmalıdır. Gelecek çalışma olarak aynı yöntemle risk azaltma stratejileri çerçevesi önerilebilir.

## 5. Beşinci Sunum: Dağıtık Ekiplerde Çevik ve Scrum

### 5.1 Konu ve Amaç

Makale, dağıtık ekiplerde yazılım geliştirme süreçlerinde çevik (agile) ve Scrum yöntemlerinin kullanımını inceliyor. Hedef, ofiste bir arada bulunmayan çalışma ortamlarıdır: farklı şehir, ülke, hatta kıtalar (Amerika ve Avrupa). Çalışma salgından önce yapılmış, ama evden çalışma düzenini de kapsayabilecek bir konudur.

Sunucu, konu derste yeterince işlendiği için çevik yöntemi kısaca hatırlattı. Çevik takımlar genelde 5-7 kişiliktir, 2-3 haftalık koşulardan (sprint) oluşan bir süreç izler. Görevler küçük parçalara ayrılır, proje yinelemeli biçimde ilerler. Her sprint sonunda değerlendirme toplantısında iyi ve kötü gidenler konuşulup çözüme bağlanır.

> **Ders sonrası not:** Altyazıda "Ecal", "Ejel" ve "heyecan" diye geçen terim, aynı sunumun başka yerlerinde doğru yazıldığı gibi "agile"dır (çevik).

### 5.2 Ön Çalışma

Araştırmacılar önce eski çalışmaları ve PMI raporlarını incelemiş. 23 kuruluştan 4 yıl boyunca düzenli raporlar gelmiş. Ön çıkarımlar şunlardır:

- Takımların dışarıdan oluşturulması yerine kendiliğinden oluşması ve öz sorumluluk taşıması daha iyi sonuç veriyor.
- Çevik yönteme alışık olmayan biri takıma katıldığında, deneyimli üyelerin yöntemi ona anlatması sonucu iyileştiriyor.
- Scrum'da genelde bir proje yöneticisi ve bir Scrum Master bulunur. Dağıtık ortamda takımların mentor, koordinatör, destekleyici, yönetici ve kontrolör gibi farklı rolleri de üstlenmesi gerekiyor.

### 5.3 Tartışma Noktaları

Makalenin ele aldığı noktalar şunlardır:

- **Lokasyon:** Yakın lokasyonda dağıtık çalışma (aynı şehirde, herkes kendi evinde) ile uzak lokasyonda çalışma (farklı il ve ülkeler) ayrı ayrı incelenmiş.
- **Çokluk:** Bir takım, bir yönetici ve tek lokasyon yerine çoklu takım, çoklu iş modeli, çoklu lokasyon ve çoklu zaman dilimi araştırılmış.
- **Yöntem karşılaştırması:** Çevik ile yinelemeli-artımlı (iterative-incremental) geliştirme karşılaştırılmış.
- **Uzaktan çalışmanın öne çıkan sorunları:** Projenin amacının eksik belirlenmesi, karar ve süreçlerin belirlenmemiş olması, projenin bağlamından kopması.
- **Takım büyüklüğü ve yük dağılımı:** Proje ölçeğine göre takım büyüklüğü ve bölgelere eşit iş yükü dağıtımı.
- **Çalışma biçimi:** Eşli programlama (pair programming) ve yapılan işlerin takımlar arasında aktarımı.
- **Zaman ve kültür farkı:** Proje yönetimine etkisi.

### 5.4 Vaka: Telekom Projesi

Örnek, yaklaşık bir yıllık bir telekom projesidir. Müşteri, geliştirme ve test ekipleri gibi birçok ekipten oluşuyor. Paydaşlar ABD, Kanada ve Almanya'da.

İlk adım görsel ön tasarımdır (GUI). Müşteri ön tasarımları proje ekibine göndermiş. Bunların 2 haftada olgunlaşması bekleniyordu, ama bazı belgelerdeki eksiklikler ve beklenmeyen süreçler yüzünden süre 4 haftaya çıkmış. Bu gecikmenin olumlu bir yanı da olmuş: Yeni fikirler ortaya çıkmış ve projeye katkı sağlamış.

Plana göre ön tasarım gibi işleri kapsayan planlama 2 ayda bitecek, proje 8-12 ayda tamamlanacak. Test, gözden geçirme ve bakım bu 12 aydan sonra yürütülecek.

Ekip düzeni, bir ölçüde dağıtık (distributed) ve kısmen dağınık (partially dispersed) yapıdadır. Üç ülkede belli bir yönetim ve proje ekibi var. Ekiplerin tamamı birbiriyle iletişim kursa da çoğu zaman her ekipten belli alt gruplar birbiriyle iletişimde oluyor.

### 5.5 Toplantılar

Toplantılar standart çevik düzenden çok farklı değil. En büyük fark Scrum of Scrums toplantısının kullanımıdır.

- **Günlük Scrum:** Her takım kendi içinde yapar. 15 dakika sürer: Dün ne yapıldı, bugün ne yapılacak, engel var mı? Proje yöneticisi ya da Scrum Master'ın değerlendirmesine göre bazı haftalarda günlük toplantının ardından yarım saatlik bir backlog gözden geçirmesi eklenmiş. Normalde backlog değerlendirmesi günlük toplantıya dahil değildir. Bu küçük bir farklılıktır.
- **Scrum of Scrums:** Yerel çalışan firmalarda da görülür. Burada asıl amaç, farklı saat dilimlerindeki ekiplerin ortak bir zaman yaratarak birbirine bilgi aktarmasıdır: "Biz neler yaptık, siz neler yaptınız, birbirimizden kopuyor muyuz?" Yüz yüze iletişimle takımlar arası bağ güçlenir.
- **Sprint planlama ve değerlendirme:** Normal çevik takımlardan çok farklı değildir. Bütün takımlar ya da katılabilecek olanlar ortak kesişim zamanlarında bir araya gelir.

### 5.6 İletişim Etkinliği ve Başarı Oranları

PMI'dan alınan bir grafik, toplantı biçimine göre etkinlik seviyesini gösteriyor. Aynı lokasyondaki takımlar yüz yüze ve beyaz tahta üzerinde çizim yapabilecekleri bir ortamda en yüksek etkinliği yakalıyor. Çizim olmasa bile yüz yüze görüşme ve video konferans gerekir. Coğrafi olarak çok uzak olup aynı odada toplanamayan ekiplerde dijital yöntemler devreye girer. Dağıtık ekipler için etkisi ölçülmesi gereken araçlar video konferans, telefon ve e-postadır.

Bunun yanında kalıcılık (persistency) da gerekir: Ne yaptık, belli bir düzeni tutturduk mu, ilerleyebiliyor muyuz? Bu sorulara cevap verecek dokümantasyon ve kayıtlar, aslında dağıtık olmayan projelerde de gereklidir.

Bir araştırmanın sonucuna göre yinelemeli, çevik ve geleneksel yöntemlerde proje başarı oranları incelenmiş. Sunumda iki yöntem için değerler okundu:

| Çalışma düzeni | Başarı oranları |
|---|---|
| Aynı lokasyon | %80, %79 |
| Yakın lokasyon | %74, %73 |
| Uzak lokasyon | %59, %55 |

Aynı ve yakın lokasyonda iki değer arasında yalnız 1 puan fark var. Uzak lokasyonda fark 4 puana çıkıyor ve bu küçük fark bir projenin büyüklüğünde farklı etkiler yaratabilir. Sunucunun verdiği yaklaşık %70'lik ortalama, altı değerin ortalamasıyla uyuşuyor (ara adım eklendi):

$$\frac{80 + 79 + 74 + 73 + 59 + 55}{6} = \frac{420}{6} = 70$$

<!-- BELİRSİZ: Grafikte hangi değerin hangi yönteme ait olduğu ve grafikteki üçüncü yöntemin değerleri altyazıda geçmiyor. -->

### 5.7 Çıkarılan Dersler

**Takımların çevik düzene alışık olması gerekir.** Bu aslında dağıtık olmayan ekipler için de geçerlidir. Ama alışık olmayan bir ekibin bir de dağıtık olması proje yönetimini daha büyük bir riske sürükler. Bu yüzden mentor, kontrolör, yönetici ve düzenleyici gibi görevleri üstlenen kişiler ekibi daha sıkı yönetmeli ve projeyi anlatmalıdır.

**Plandaki küçük sapmalar doğaldır.** Farklı coğrafyalarda genelde bir ana yüklenici ve alt yükleniciler bulunur. Alt yükleniciler, özellikle startup'lar, küçük sapmalarda işi yapamama endişesine kapılıyor. Ana yüklenicinin, bu sapmaların uzaktan yönetimin bir sonucu olduğunu ve doğru yönetilince etkisinin azalacağını plan üzerinden sakince anlatması büyük etki yaratıyor.

**Yüz yüze görüşmenin etkisi büyüktür.** Bütçe ve proje büyüklüğü uygunsa ve ekipler çok uzak değilse, proje yöneticisi veya Scrum Master gibi birkaç kişi 3 ayda, 6 ayda ya da yılda bir diğer lokasyonlardaki ekipleri ziyaret etmelidir. Bu hem motivasyonu hem de projenin ilerleyişini olumlu etkiliyor.

**Takım büyüklüğü düzeni belirler.** PMI'dan alınan bir görsele göre takım boyutu 500-1000 kişiye yaklaştıkça global bir takım yapısına yaklaşılır. Orta büyüklükte daha yerel ya da aynı lokasyonda yakın bir düzen önemlidir. 5 kişilik bir ekip ise herkesin bireysel çalıştığı bir noktaya evriliyor.

<!-- BELİRSİZ: Takım büyüklüğü görselindeki eşik değerleri altyazıda bozuk geçiyor ("takım sayımız 2 ve şuraları 500"); yalnız net anlaşılan kısım yazıldı. -->

**Yetenek bulmak ve yasal uyum maliyetlidir.** Farklı noktalarda yetenekli kişi bulmak daha zordur. İnsan kaynakları araştırması zaman, dolayısıyla maliyet demektir. Ülkelerin kuralları ve uyum süreçleri de farklıdır ve projenin başında incelenmelidir.

### 5.8 Sonuç

Makalenin sonuçları şöyle özetlendi:

- Çözüm aranırken bütün ekiplerin, hatta bütün kişilerin fikri alınmalıdır. Toplantılar olabildiğince kameralar açık yapılmalıdır.
- Bütçe el veriyorsa en azından proje yöneticileri bütün ekipleri yüz yüze görmelidir.
- Yalnız kodlama beklenmemeli, beyin fırtınası toplantıları yapılmalıdır. Örneğin ABD'deki ekip bir gereksinim dokümanı hazırlayıp Almanya'daki ekipten yalnızca çalışan uygulama beklerse süreç çevik olmaktan çıkar, yinelemeli-artımlı bir sürece doğru evrilir.
- Sık sürüm çıkarılmalıdır. Böylece uzaktaki ekipler projenin doğru ilerleyip ilerlemediğini görür ve en küçük değişiklik bile test edilebilir.
- Gereksinimler ayrıntılı oluşturulmalıdır. Çevik düşünce gereksinimleri yolda güncellemeye açık olsa da, gereksinimlerin nokta atışı belirlenmesi başarıda önemli bir etkendir.
- Doğru araçlar seçilmelidir: Teams, Zoom gibi iletişim araçları ve kod entegrasyon araçları.
- Takımlar birbirine sık demo yapmalıdır. "Biz bunları yaptık, sonuç bu oldu" diyerek iletişim güçlendirilir.

## Dersin Toparlaması

Bu derste beş makale üzerinden risk yönetimi, ekonomik göstergeler, kaynak planlama ve dağıtık çalışma konuları ele alındı. Birinci sunum riskleri tanımlama, önceliklendirme, azaltma ve izleme döngüsünü ve bu döngü için önerilen modellerin karşılaştırmasını verdi. İkinci sunum, derste ekonomik fizibilite içinde geçen kazanılan değer yönetimini $CV$, $CPI$, $SV$ ve $SPI$ göstergeleriyle hatırlattı ve yöntemin zaman, kalite ve risk açısından eksiklerini gidermek için eklenen ölçütleri tanıttı. Üçüncü sunum kaynak çatışmalarını graf renklendirmeyle temsil etti ve kromatik sayıyı bekleme turlarının bir ölçüsü olarak kullandı.

Dördüncü ve beşinci sunumlar dağıtık çalışmaya odaklandı. Küresel geliştirme riskleri Leavitt'in modeline göre altı kategoride toplandı. Çevik ve Scrum'ın dağıtık ekiplerde uygulanması da yüz yüze iletişim, Scrum of Scrums, sık sürüm ve ayrıntılı gereksinim gibi derslerle özetlendi. Sunumlar boyunca hocanın biçimsel uyarısı da akılda tutulmalıdır: İyi bir makale sunumu kaynağını baştan gösterir, metni okumaz, en önemli noktaları özetler. Kalan makale sunumları ve uygulama projelerinin anlatımı sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
