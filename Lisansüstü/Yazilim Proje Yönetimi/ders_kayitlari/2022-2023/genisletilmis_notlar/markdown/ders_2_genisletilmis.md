# Ders 2 Genişletilmiş Notu: Yazılım Mühendisliği Temelleri ve Yazılım Süreç Modellerinin Seçimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Proje Yönetiminin Üç Bileşeni
- 2. Yazılım Proje Yönetiminin Hedefleri ve Yazılım Geliştirme Planı
- 3. Yazılım Mühendisliğinin Tanımı
- 4. Yazılım Geliştirme Sürecindeki İşlemler
- 5. Klasik Süreç Modelleri
- 6. Unified Process ve CASE Araçları
- 7. Çevik Süreçler: Prensipler, XP ve Scrum
- 8. Süreç Modellerinin Karşılaştırılması ve Seçimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Proje Yönetiminin Üç Bileşeni

Ders, önceki haftada gösterilen bir şemanın tekrarıyla başladı. Slayttaki tanıma göre yazılım proje yönetimi, yazılım projelerinde kaynakların en etkin biçimde kullanılmasını sağlamaya yöneliktir. Etkin proje yönetimi için insan kaynakları, problem ve yazılım geliştirme sürecindeki işlemler göz önünde bulundurulmalıdır (ekrandan, 00:05:00).

Şemada üç daire vardır ve yazılım proje yönetimi bu üç dairenin kesiştiği kırmızı bölgedir (ekrandan, 00:05:00):

- Proje yönetimi bilgi ve deneyimi
- Genel yönetim bilimi
- Yazılım mühendisliği teknikleri

### 1.1 Proje yönetimi bilgi ve deneyimi

Bu alan yazılım projeleri için de başka alanlardaki projeler için de geçerlidir. Bir proje tanımıyla yola çıkıldığında yapılması gereken işler şunlardır: önce projenin kapsamını belirlemek, projede gerçekleştirilecek yenilikleri tanımlamak, zaman planını oluşturmak, ekip yapısını kurup izlemek, görev tanımlarını yapıp takip etmek ve insan kaynağı dahil kaynakları yönetmek. Özetle proje yönetimi planlamak ve planı izlemektir.

Plan izlenirken şu sorular sorulur: Plan ne kadar uygulanabiliyor? Geride kalınan ya da eksik kalınan yerler varsa nasıl telafi edilecek? Yeni bir B planı var mı? Bu açıdan özellikle zaman planlaması, kaynak planlaması ve kapsam yönetimi önemlidir. Hoca proje başarısının bu üçlüyle, dördüncü olarak da kalite takibiyle sağlandığını, proje başarısı konusunun ileride ayrıca işleneceğini söyledi.

Önceki haftada anlatılan 3P de burada hatırlatıldı. Yazılım proje yönetiminde ilk sıraya insan (people) konur. Ardından problemin doğru tanımlanması (problem) ve yazılım geliştirme sürecinin doğru izlenmesi (process) gelir.

### 1.2 Genel yönetim bilimi

Proje yöneticisinin bir ekibi vardır ve bu ekibi yönetmek zorundadır; bu yüzden yönetim ilkelerini bilmelidir. Proje süresince sorunlu durumlardan haberdar olmalı, alt ekipleri sürekli izleyebilmeli ve sorunları kayıt altına alabilmelidir. Satın alma yapılacak şirketlerle, paydaşlarla ve müşterilerle ilişkiler de yönetim biliminin konusudur. Hoca bu alanın bilgisayar mühendisliğinden gelenler için biraz daha yabancı olabileceğini belirtti.

### 1.3 Yazılım mühendisliği teknikleri

Üçüncü bileşen yazılım geliştirme sürecinin adımları ve bu adımları iyileştirmek için yapılması gerekenlerdir. Bu derste önce yazılım mühendisliğinden bilinen süreç modelleri kısaca tekrar edildi, çevik yaklaşım da süreç modelleri içinde ayrı bir yerde ele alındı.

## 2. Yazılım Proje Yönetiminin Hedefleri ve Yazılım Geliştirme Planı

Yazılım proje yönetiminin hedefleri şöyle sıralandı:

- Proje yönetimi elemanlarının (az önceki alt başlıkların) açıklığa kavuşturulması.
- Yazılım ölçümü: ölçümün ne olduğu, yazılım metrikleri ve metrik yöntemleri.
- Yazılım proje maliyet tahmini. Geçmiş projeler ölçülüp bir arşiv oluşturulmuşsa yeni projelerde maliyet tahmini daha kolay ve daha bilimsel yapılır.
- Risk yönetimi: projedeki risklerin neler olduğu, nasıl yönetileceği, risk planının ne olduğu.
- Proje planının hazırlanması. Kaynak planlama ve zaman planlama zaten proje yönetimi elemanlarının içindedir.

### 2.1 Planın cevaplaması gereken sorular

Genel olarak her proje yönetiminde kapsam, kaynak ve zaman planlaması bulunmalıdır. Plan şu üç soruya cevap verir:

- Ne yapılacak? (kapsam)
- Ne kadar kaynakla yapılacak? (kaynak)
- Ne zaman yapılacak? (zaman)

Yazılım geliştirme planının alt başlıkları şunlardır:

- Sorunun tanımlanması
- Çözüm yolunun kararlaştırılması
- Geliştirme sürecinin planlanması
- Proje organizasyonu
- Proje zamanlaması

Proje zamanlaması için Gantt diyagramından yardım alınır. PERT ile de proje alt adımları izlenir: hangi alt adımın ne zaman başlayıp ne zaman biteceği ve kritik noktaların neler olduğu belirlenir. Planın içeriği ilerleyen haftalarda ayrıntılı işlenecektir.

### 2.2 Proje yönetimi ile kalite yönetiminin örtüşmesi

Hoca kalite yönetimi ile proje yönetiminin birleşiminin "yazılım yönetimi" diye de anılabileceğini söyledi. İki alanın örtüştüğü noktalar vardır. Projenin hedeflerini belirlemek için kalite özelliklerinden haberdar olmak gerekir. Maliyet tahmini için daha önce yapılmış projelerin ölçümleri kullanılır. Risk yönetimi de her iki alanda ele alınmalıdır: risklerin nasıl planlandığı, nasıl izlendiği ve risk planında değişiklik önerilip önerilmediği.

## 3. Yazılım Mühendisliğinin Tanımı

Yazılım proje yönetimi yazılım mühendisliğinin alt alanlarından biri olduğu için hoca yazılım mühendisliğinin tanımına döndü. Slayttaki tanım şöyledir: "Yazılım mühendisliği, bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim bilim dallarından yararlanmakta ve sorun çözümünde mühendislik yöntemlerini kullanmaktadır." (ekrandan, 00:20:00)

### 3.1 Kaliteli yazılım ve en ekonomik yol

Yazılım mühendisliğinin amacı kaliteli yazılımı en ekonomik yolla üretmektir. Kaliteli yazılım tarafı yazılım kalite yönetimi ve iyi bir testin nasıl yapılacağıyla ilgilidir. Hoca "en ekonomik yol"un en ucuz yol olmadığını vurguladı: amaç en etkin yazılımı en düşük maliyetle ve maliyet takibi yaparak üretmektir. Proje yönetimi bu ikinci tarafı sağlar.

### 3.2 Mühendisliğin iki gereği: tasarım ve ölçüm

Mühendisliğin birinci gereği tasarımdır. Yazılım geliştirmeye doğrudan program yazarak başlanmaz. Tasarımdan da önce gereksinim analizi yapılır: müşteri ne istiyor, ne yapmamız gerekiyor? Ardından tasarım gelir.

İkinci gereği ölçümdür. Hoca "mühendislik" kelimesinin hendese biliminden geldiğini ve mühendisin ölçüm yapan kişi olduğunu söyledi. Bu yüzden yazılım ölçümü de yazılım mühendisliğinin içinde olmalıdır. Geliştirilecek yazılımın ne büyüklükte olacağı, bitirilen yazılımın ne büyüklükte olduğu bilinmeli; bu bilgi planlamada ve süreç modeli seçiminde kullanılmalıdır. Hocanın verdiği ölçüm örnekleri:

- Büyüklük ölçümü
- Algoritma karmaşıklığı ölçümü (algoritmalar ve veri yapıları dersinden bilinen)
- Yazılımdaki aritmetik ifadelerin sayılması ve karmaşıklıklarının belirlenmesi
- CK metrikleri gibi nesneye yönelik metrikler

> **Ek bilgi (derste anlatılmadı):** CK metrikleri Chidamber ve Kemerer'in önerdiği nesneye yönelik tasarım metrikleridir. Sınıf başına ağırlıklı metot sayısı (WMC), kalıtım ağacı derinliği (DIT), alt sınıf sayısı (NOC), sınıflar arası bağlılık (CBO), sınıfın yanıt kümesi (RFC) ve metotlarda uyum eksikliği (LCOM) bu metriklerdendir.

### 3.3 Yazılım sistemi kurum içinde

Yazılım sistemi katmanlı bir çerçeve içinde yer alır: en dışta kurumun ortamı, içinde kurum içi bilgiler, onun içinde kurumdaki bilgi sistemleri ve bunların içinde yazılım sistemi. Yazılım sistemi kurumun işleyişine uygun kurulmalıdır.

Hoca bir örnek verdi: bir şirket için envanter sistemi geliştirilecek. Bunun için hazır paket programlar vardır, ama sistemin kurumun diğer bilgi sistemleriyle uyumlu çalışması gerekir. Bu nedenle bir projeye başlamadan önce kurumun çevre birimleri ve bilgi sistemleri incelenir, proje kapsamı buna göre belirlenir.

### 3.4 Yazılım mühendisliği dersinin hedefleri

Hoca yazılım mühendisliğinin alt başlıklarını hatırlattı: yazılım geliştirme süreçleri, yazılım standartları, yazılım yetkinlik modelleri, CASE yapısı ve konfigürasyon yönetimi (sürüm kontrolü). Slayttaki hedefler (ekrandan, 00:25:00):

- CASE teknolojisi
- Yazılım proje maliyeti tahmin yöntemleri, yazılım ölçümü kriterleri, yazılım proje planı hazırlama
- Yazılım kalite özellikleri ve yazılım kalite yönetimi teknikleri
- Yazılım bakımı kavramı

Konfigürasyon yönetimi ve sürüm kontrolünün planlanması kalite planında yer alır. Kalite özellikleri ve kalite yönetim teknikleri proje yönetiminde değil kalite yönetiminde ele alınır; standartlar da kalite yönetiminin parçasıdır. Proje yönetiminde ise maliyet tahmini, ölçüm kriterleri ve proje planının hazırlanması önemlidir. Bir sonraki slaytta yazılım kalite yönetiminin başlıkları da gösterildi: yazılım kalite özellikleri, yazılım kalite ölçümü, kalitenin sağlanması, yazılımın sınanması ve yazılım sınama teknikleri (ekrandan, 00:15:00).

Bir proje planı ya da proje öneri paketi hazırlanırken de gereksinim analizine başlamak önemlidir; müşterinin ne istediği ve işin ne olduğu gereksinim analiziyle ortaya çıkar, tasarıma ancak bundan sonra geçilir. Analiz ve tasarım yöntemleri (örneğin nesneye yönelik yaklaşım) yazılım mühendisliğinin parçasıdır. Bu adımların arka arkaya, bir döngü içinde ya da daha kısa ve çevik adımlarla yapılması farklı süreç modellerini tanımlar; ama her modelde yazılım mühendisliğinin hedefleri sağlanmalıdır.

## 4. Yazılım Geliştirme Sürecindeki İşlemler

### 4.1 Esas işlemler

Yazılım geliştirme sürecinin esas işlemleri şunlardır:

- Gereksinim analizi: müşterinin istediği işin ortaya konması
- Tasarım: müşteriyle anlaşılan işlerin nasıl gerçekleştirileceğinin tasarlanması
- Kodlama (gerçekleme)
- Test: kodlananın doğru olup olmadığının sınanması
- Teslim ve bakım

Hoca slaytta tasarım adımının eksik kaldığını, bunun bir hata olduğunu söyleyip ekledi.

### 4.2 Destek işlemleri (şemsiye aktiviteler)

Esas işlemleri destekleyen aktivitelere destek işlemleri ya da şemsiye aktiviteler (umbrella activities) denir. Bunlar esas adımları daha iyi, daha ekonomik ve daha kaliteli yapmayı sağlar; esas adımları koruyan bir şemsiye gibidir. Slayttaki destek işlemleri (ekrandan, 00:30:00):

- Proje yönetimi
- Kalite yönetimi
- Yazılım konfigürasyon yönetimi
- Risk yönetimi

> **Hocanın vurgusu:** Bu listeye yazılım ölçümü de eklenmelidir. Ölçüm proje yönetimi ve kalite yönetimi içinde yer alsa da destek işlemi olarak ayrıca düşünülmelidir.

Her destek işleminin içeriği şöyle özetlendi:

- **Proje yönetimi:** Yazılımın ne kadar sürede, hangi ekiple, hangi yeteneklerle ve hangi maliyetle geliştirileceği.
- **Kalite yönetimi:** Kalitenin nasıl olacağı, hangi standartların kullanılacağı, hangi aralıklarla ve hangi tarihlerde gözden geçirme yapılacağı.
- **Konfigürasyon yönetimi:** Değişikliklerin nasıl kayda geçirileceği, hangi değişikliğin hangi tarihte yapıldığının takibi, en son halden önceki hale dönebilme ve yazılım elemanları arasındaki ilişkilerin belirlenmesi.
- **Risk yönetimi:** Aşağıda 4.4'te.

### 4.3 Yazılım nedir?

Konfigürasyon yönetimini açıklamadan önce hoca "yazılım elemanları" kavramı için yazılımın ne olduğunu sordu. Bir öğrenci yazılımın bir problemi çözmek için aşamalar halinde üretilen bir çözüm olduğunu söyledi. Hoca bir güvenlik yazılımı satın alma örneğiyle soruyu derinleştirdi: alınan yazılım yalnız program mıdır?

Cevap şöyle kuruldu:

$$\text{Yazılım} = \text{Program} + \text{Veri} + \text{Belgeler}$$

- **Program:** bilgisayara ne yapacağını söyleyen komutlar.
- **Veri:** programın kullandığı veri tabanları, tablolar ve verinin tanımı (veri hakkında bilgi).
- **Belgeler:** programın nasıl kullanılacağını anlatan kullanıcı belgeleri; bakım ve düzeltme yapacak geliştiriciler için SRS (Software Requirements Specification), SDS (Software Design Specification), ER ve sınıf diyagramları gibi tasarım modelleri; testte hangi test verisiyle denendiği bilgisi.

Satın alınan paket yazılımda bakım belgeleri kullanıcıya verilmez, ama kurum içinde sürekliliği sağlanacak yazılımlarda bunlar gereklidir. Yazılım mühendisliği doğrudan program yazmak yerine yazılımı bu alt bileşenlerle birlikte tanımlamayı önerir.

> **Hocanın vurgusu:** Belge hazırlamak hoşa gitmeyebilir, ama belge varsa sizden sonraki kişiler yazılımda düzeltme yapabilir. Belge yoksa program yalnız yazan kişiye bağlı kalır.

Buna göre yazılım konfigürasyon yönetimi, yazılımı oluşturan elemanların tanımlandığı, birbirleriyle ilişkilerinin belirlendiği ve bunlardaki değişikliklerin izlendiği alandır. Yazılımın birinci, ikinci sürümü gibi her sürümde hangi elemanların değiştiği ve ilişkilerin değişip değişmediği takip edilir. Eskiden şirketler bunu izlemek için ayrıca bir veri tabanı uygulaması yazmak zorundaydı; bugün yazılım geliştirme platformları konfigürasyon yönetimini kendi içinde sağlar.

### 4.4 Risk yönetimi

Risk yönetimi yazılım geliştirilirken hangi risklerin olduğunun belirlenmesidir: önce risklerin tanımlanması, sonra birbirleriyle ilişkilerinin belirlenmesi, her evrede izlenmesi ve yeni ya da kontrol altına alınmamış risk olup olmadığına bakılması. Risk olasılıkla, dolayısıyla istatistikle ilişkilidir. Risk demek şu anda bir sorun olmadığı, ama sorun çıkmaya müsait alanlar olduğu anlamına gelir.

Hocanın verdiği örnekler:

- **Müşteriyle ilişkili riskler:** müşterinin iyi bilgi vermemesi, çalışmalara katılmaması, istediğini tam ya da doğru anlatmaması, yapılan işi yarı yolda değiştirebileceğini sanması.
- **Çalışanlarla ilişkili riskler:** ekip elemanlarından birinin işten ayrılması.
- **Teknik riskler:** bir CASE aracı kullanılması, ama süreç ilerledikçe ekibin bu aracı tam kullanamadığının görülmesi.

Bu riskler için planlama yapılır; ardından kayıt altına alınıp ders çıkarılır. Risk yönetimi kalite yönetiminde de ele alınır.

Hoca yazılım mühendisliği konusunda daha geniş bilgi için iki temel kitabı önerdi: Roger Pressman'ın ve Sommerville'in yazılım mühendisliği kitapları. Bu iki kitap dünyada bilgisayar mühendisliği bölümlerinde okutulur; Sommerville'in kitabının Türkçe çevirisi de vardır.

## 5. Klasik Süreç Modelleri

Hoca süreç modellerini, yazılım mühendisliği dersinden bilindiği için hızlıca tekrar etti.

### 5.1 Klasik (şelale) süreç

Slayttaki şema şu sırayı gösterir: kullanıcı (User), gereksinim analizi (Requirements Analysis), sistem tasarımı (System Design), gerçekleme (Implementation), bütünleştirme ve kullanıma sunma (Integration and Deployment), ürün (Product), işletim ve bakım (Operation and Maintenance) (ekrandan, 00:45:00). Adımların altındaki oklar bir önceki adıma geri dönülebildiğini gösterir.

Gerçekleme yalnız program kodlamak değildir; veri tabanının oluşturulması da bu adımdadır, bu yüzden hepsine birden gerçekleme (implementation) denir. Bu modele doğrusal (linear) akış, klasik süreç ya da şelale (waterfall) süreci denir. "Şelale" adı, her adımın bir sonrakine sürekli bilgi aktarmasından ve şeklin görünüşünden gelir: kullanıcı ne istediğini söyler, buna göre gereksinim analizi yapılır, geliştiriciler nasıl yapacaklarını tasarlar, kodlama yapılır ve veri tabanı hazırlanır, test edilir, kurulumla müşteriye teslim (release) edilir ve bakım süreci başlar. Geri dönüş olabilir, ama adımlar sırayla yapılmalıdır.

Şelale modelinin sorunları: süreç uzundur, kullanıcılar yazılımı görmekte zorlanır ve hatalar bazen ancak sonda fark edilir.

### 5.2 Prototip modeli

Prototip modeli süreci hızlandırmaktan çok müşterinin ne istediğini daha kolay anlatmasını sağlamak için kullanılır. Kullanıcı gereksinimleri verir, gereksinimlerin doğruluğu için geri bildirim alınır. Gereksinimler hızlıca tasarlanır, daha kolay araçlarla gerçeklenir ve müşteriye sunulur. Müşteri bunun üzerinden değerlendirme yapar ve sürekli müdahale eder; bu yüzden modelde geri dönüşler vardır. Ardından, bütünleştirme ve kurulum aşamasından önce, daha kapsamlı ve farklı araçlarla asıl geliştirme yapılır.

### 5.3 Artımlı (incremental) model

Prototip ve geliştirme süreciyle birlikte artımlı yazılım geliştirme (incremental software development process) ortaya çıkmıştır. Yazılım kısa hedeflerle parçalara ayrılır ve her parça kullanıma alınacak bir artım olarak teslim edilir. Böylece yazılım daha hızlı geliştirilir.

### 5.4 Spiral model

Artımlı model daha fazla test ve daha fazla kontrolle geliştirilince spiral model oluşmuştur. Slayttaki şemanın dört bölgesi şunlardır (ekrandan, 00:50:00):

- Planlama (Planning): ilk gereksinimlerin toplanması ve proje planlaması, sonraki turlarda müşteri değerlendirmesine göre planlama.
- Risk analizi (Risk analysis): ilk gereksinimlere göre, sonraki turlarda müşteri tepkisine göre risk analizi; devam edip etmeme ("go, no-go") kararı.
- Mühendislik (Engineering): gereksinim analizi, tasarım, gerçekleme ve bütünleştirme; iterasyon 1, iterasyon 2 yapımları.
- Müşteri değerlendirmesi (Customer evaluation).

Her döngüden sonra yeni bir adıma geçilir. En içteki döngüde ürün bir prototiptir, sonra kullanıma alınacak ürüne, sonra zenginleştirilmiş ürüne dönüşür; yani sürekli eklemeler yapılır. Her aşama kontrollü ve döngüsel yürür. Spiral model aynı zamanda evrimsel bir model olarak da tanımlanır.

## 6. Unified Process ve CASE Araçları

Aradan sonra hoca yeni bir slayt dosyası açtı. Dosyanın ilk slaytı "Understand the Problem" başlıklıydı ve problemi anlamak için sorulacak soruları listeliyordu: çözümde kimin payı var (paydaşlar kim), bilinmeyenler neler (problemi çözmek için hangi veri, fonksiyon ve özellikler gerekli), problem daha küçük ve anlaşılır parçalara bölünebilir mi, problem grafikle gösterilebilir mi, bir analiz modeli oluşturulabilir mi (ekrandan, 01:05:00). Hoca bu slayt üzerinde durmadan Unified Process'e geçti.

### 6.1 Unified Process

Hoca Rational Unified Process ürününü duyan ya da kullanan olup olmadığını sordu. Unified Process, nesneye yönelik yazılım geliştirme yaklaşımı yaygınlaşınca ona uygun olarak hazırlanmış bir süreç modelidir. Slayttaki şemada döngü communication, planning, modeling, construction ve deployment kutularından oluşur; bunların üstünde aşamalar yer alır (ekrandan, 01:10:00):

- **Inception (başlangıç):** müşteriden bilgi alma ve plana başlama. Genel bir use case modeli, projeyle ilgili sözlük (işletmenin alanına göre), genel proje planı ve iş modeli oluşturulur.
- **Elaboration (ayrıntılandırma, modelleme):** gereksinim analizinin ayrıntılı yapılması ve yazılım mimarisinin (software architecture) belirlenmesi. Yazılım mimarisi, tasarımın sistem olarak nasıl yapılacağını belirten önemli bir yazılım mühendisliği konusudur. Proje planı teknik alt başlıklarla ayrıntılandırılır.
- **Construction (yapım):** tasarım modelinin netleşmesi, yazılım bileşenlerinin gerçeklenmesi, test planlarının yapılması ve teste başlanması. Birim testinden sonra bütünlük testi yapılır.
- **Transition (geçiş):** teslim süreçleri; kullanıma geçiş ya da var olan ürünün yerine yenisinin yerleştirilmesi.
- **Production (üretim):** her döngünün sonunda bir yazılım artımı (software increment) teslim (release) edilir.

Unified Process de artımlı bir modeldir: kısa hedefler belirlenip artımlar halinde teslim edilir. Hoca bunu klasik modeller ile çevik modeller arasında bir ara model ve artımlı modelin nesneye yönelik yaklaşım için oluşturulmuş özel bir hali olarak tanımladı.

### 6.2 CASE araçları

Hoca CASE kavramını sordu ve açılımını verdi: Computer Aided Software Engineering (bilgisayar destekli yazılım mühendisliği). Bir öğrenci bunun yazılım mühendisliği süreçlerini yazılımla sistematik hale getirmekle ilgili olabileceğini tahmin etti. Hoca şu benzetmeyle açıkladı: CAD/CAM yazılımları tasarım ve üretim yapanlara nasıl destek oluyorsa, CASE araçları da yazılım geliştirme sürecinin her adımında yazılım geliştiricilere destek olur.

CASE araçlarının destek verdiği işlere örnekler:

- Konfigürasyon yönetimi ve proje yönetimi.
- Gereksinim analizi ve tasarımda nesneye yönelik ya da klasik yaklaşımla çizilen modeller ve diyagramlar: UML sınıf ve etkileşim diyagramları, klasik veri akış diyagramları, iş ve yapı diyagramları, veri tabanı yapısını gösteren ER diyagramları. CASE aracı bu diyagramların kurallara uygun ve birbiriyle tutarlı çizilmesini kural kontrolüyle sağlar.
- Test aşamasında birim testi, bütünlük testi ve sistem testi.

Bu araçlar tek tek de kullanılabilir (örneğin yalnız analiz ve tasarım diyagramları için), bütün adımları kapsayan bütünleşik CASE araçları olarak da kullanılabilir. Rational Unified Process bu alandaki en güçlü uygulamalardan biriydi; bu yüzden ürün ve firma sonradan IBM tarafından satın alındı. Unified Process de bu aracın altında çalışan süreç modelidir.

## 7. Çevik Süreçler: Prensipler, XP ve Scrum

### 7.1 Çevik yaklaşımın amacı

Unified Process'ten sonra çevik (agile) süreçler başladı. Çevik süreçlerin amaçları şöyle sıralandı:

- Değerlendirilebilir yazılımı müşteriye daha hızlı vermek ve müşteriyle daha yakın çalışmak (müşterinin de buna uygun olması gerekir).
- Değişen gereksinimlere daha kolay uyum sağlamak.
- Çalışan yazılımı sık sık, farklı artımlarla teslim etmek.
- Yazılımı kullanacak işletme çalışanlarını ve geliştiricileri aynı ekip içinde, motive edici bir yapıda çalıştırmak.
- Değerlendirmeleri kağıt üzerinden değil yüz yüze yapmak.
- Çalışan yazılımı ilerlemenin ve başarının ölçüsü saymak; artımların müşteri tarafından alınıp değerlendirilmesini sağlamak.

Çevik süreçler daha güvenilir ve sürdürülebilir bir geliştirme sağlar. Sponsorlar (yazılımın geliştirilmesi için para sağlayan yatırımcılar), geliştiriciler ve kullanıcılar daha etkileşimli çalışır. Teknik mükemmelliğe ve iyi tasarıma sürekli dikkat çevikliği artırır.

**Basitlik ilkesi:** Geliştirilecek proje başta çok ayrıntılı tanımlanmaz; basit tanımlanır ve sonra bu basit yapı zenginleştirilir. Hoca bunu çeviklik prensibinin önemli maddelerinden biri saydı.

### 7.2 Çevik prensipler

Çevik prensipler 12 maddedir. Slayttaki ilk altı madde şunlardır (ekrandan, 01:15:00):

1. En yüksek öncelik, değerli yazılımın erken ve sürekli teslimiyle müşteriyi memnun etmektir.
2. Geliştirmenin geç aşamalarında bile değişen gereksinimler kabul edilir; çevik süreçler değişimi müşterinin rekabet avantajı için kullanır.
3. Çalışan yazılım sık sık teslim edilir.
4. İş tarafındaki kişiler ve geliştiriciler proje boyunca her gün birlikte çalışmalıdır.
5. Projeler motive olmuş bireyler etrafında kurulur; onlara gereken ortam ve destek verilir ve işi yapacaklarına güvenilir.
6. Geliştirme ekibine ve ekip içinde bilgi aktarmanın en verimli ve etkili yolu yüz yüze konuşmadır.

<!-- BELİRSİZ: 7-12. maddeler ayrı bir slaytta; o slayt yalnız küçük önizleme olarak göründü, maddeler okunamadı. Hoca kalan maddelerden çalışan yazılımın ilerleme ölçüsü olması, teknik gelişme ve tasarıma dikkat ve basitlik ilkesine sözlü değindi. -->

> **Hocanın vurgusu:** 12 prensibin en can alıcı noktaları müşterinin ekip içinde yer alması, ekip üyeleri arasında daha sıkı işbirliği, daha hızlı çalışan yazılım üretilmesi ve basitlik ilkesinin gözden kaçırılmamasıdır.

### 7.3 Extreme Programming (XP)

Extreme Programming, çevik yaklaşımı uygulayan ilk modellerden biridir ve XP olarak kısaltılır. Spiral model ve Rational Unified Process gibi klasik modellerden sonra çevik yaklaşım başlamış, XP bunu uygulayan ilk modellerden olmuştur. Hoca XP'nin bir dönem "aşırı programlama" diye Türkçeleştirildiğini, sonra XP kısaltmasının yerleştiğini söyledi. XP de artımlı bir modeldir: ilk artım temel yapıyı kurar, sonraki artımlar onu zenginleştirir. Slayttaki döngü şöyledir (ekrandan, 01:20:00):

- **Planlama (planning):** kullanıcı hikayeleri (user stories), değerler, kabul testi kriterleri, iterasyon planı.
- **Tasarım (design):** basit tasarım, CRC kartları, spike çözümleri ve prototipler.
- **Kodlama (coding):** eşli programlama (pair programming) ve refactoring.
- **Test:** birim test, sürekli bütünleştirme (continuous integration), kabul testi.
- **Teslim (release):** yazılım artımı; proje hızı (project velocity) hesaplanır.

Kabul testi kriterlerinin daha planlama sırasında belirlenmesi, XP ve Scrum dahil çoğu çevik yaklaşımda bulunan test güdümlü geliştirme (Test Driven Development, TDD) anlayışının bir parçasıdır. Tasarımda önce basit bir tasarım yapılır, sonra prototipler üretilir. Eşli programlamada iki kişi aynı kod üzerinde çalışır, böylece kodlarken bir yandan da test yapılmış olur. Refactoring kod üzerinde kolay değişiklik yapılabilmesini sağlar. Artımlar sürekli bütünleştirilir, kabul testi yapılır ve yazılım artımı kullanıma alınır; proje başarısı da hızlıca değerlendirilir.

> **Ek bilgi (derste anlatılmadı):** CRC kartları (Class-Responsibility-Collaborator), her sınıfın adının, sorumluluklarının ve birlikte çalıştığı sınıfların küçük kartlara yazıldığı basit bir nesneye yönelik tasarım tekniğidir. Spike çözümü, belirsiz bir teknik sorunu anlamak için yapılan kısa ve atılabilir bir deneme uygulamasıdır.

### 7.4 Scrum

Scrum'da iş önce alt parçalara bölünür. Girdileri proje sahibi (ürün sahibi) verir ve projede neler olduğunu belirtir; bu ürün tanımıdır. Ürün tanımından her sprintin hangi işleri içereceği seçilir ve seçilen sprint için bir backlog oluşturulur. Bir ile dört hafta arasında bitecek işler belirlenir, işlerin başlangıç, bitiş ve süreleri tanımlanır, görevler herkese dağıtılır. Tamamlanan işler gözden geçirilir. Scrum koçları ekibin günlük tartışmalarının nasıl yapılacağını düzenler.

Günlük toplantılarda proje yöneticisi herkese tek tek "verdiğim işi bitirdin mi?" diye sormaz; biten ve bitmeyen işler ve bitmeyen işlerin kime ait olduğu konuşulur. Böylece herkes birbirine karşı sorumlu olur. Yeni görev dağılımıyla süreç devam eder.

Hoca Scrum'un tam anlamıyla bir süreç modeli sayılmadığını, Scrum'da da test güdümlü geliştirmenin kullanıldığını belirtti. XP ilk çevik başlangıç olsa da daha az kullanılır; Scrum, ekip üyelerinin nasıl kaynaşacağı, birbirini nasıl sorgulayacağı ve proje yöneticisi yapısının nasıl değişeceği konularını daha çok ele aldığı için daha çok tercih edilmiştir. Crystal ve Feature Driven Development (özellikleri ortaya çıkararak gereksinim analizi yapan bir yol) da çevik modellerdir.

## 8. Süreç Modellerinin Karşılaştırılması ve Seçimi

### 8.1 Scrum ve diğer modeller

Slaytta Scrum'u şelale, spiral ve iteratif modellerle karşılaştıran bir tablo gösterildi (ekrandan, 01:25:00):

| Kriter | Şelale | Spiral | İteratif | Scrum |
|---|---|---|---|---|
| Tanımlı süreçler | Gerekli | Gerekli | Gerekli | Planlama ve kapatma aşamasında |
| Final ürün | Planlamada tanımlanmış | Planlamada tanımlanmış | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Proje maliyeti | Planlama esnasında hesaplanıyor | Kısmen değişken | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Tamamlanma tarihi | Planlama esnasında belirleniyor | Kısmen değişken | Proje esnasında şekilleniyor | Proje esnasında şekilleniyor |
| Dış çevreye duyarlılık | Sadece planlamada | Planlama öncelikli | İterasyon sonlarında | Her zaman |
| Takım esnekliği, yaratıcılığı | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | Limitli, fazla yaratıcılık ve esneklik desteklenmiyor | İterasyonlar boyunca yaratıcılıkta ve esneklikte limit yok |
| Bilirkişi desteği (harici) | Proje eğitimi esnasında | Proje eğitimi esnasında | Proje eğitimi esnasında | Gerekirse proje içinde takıma bile dahil edilebiliyor |
| Başarı olasılığı | Düşük | Orta düşüklükte | Orta seviye | Yüksek |

Hoca tabloyu şöyle yorumladı: Scrum'da süreçler planlama ve kapatma aşamasında tanımlanır, final ürün proje esnasında şekillenir; şelale ve spiralde ise final ürün planlamada tanımlanır. Scrum'da proje maliyeti ve tamamlanma tarihi proje esnasında plan üzerinde yapılan değişikliklerle şekillenir. Dış çevre her zaman izlenir. İterasyonlar boyunca çalışanlardan sürekli geri bildirim alınır ve çalışanların yaratıcılığına önem verilir. Diğer modellerde dış uzman desteği eğitim ve ekibi yönlendirme biçiminde alınırken Scrum'da uzman gerekirse ekibin içine alınabilir.

Bu tabloya göre Scrum'un başarı olasılığı yüksek görünür ve birçok firmada Scrum kullanıldığı görülür. Ancak hoca, başarı olasılığının projeden projeye değiştiğini, bazı projelerde diğer modellerin de başarılı olabileceğini ve Scrum'un her projeye ve her ekibe uygun olup olmadığının yazılım mühendisliği sempozyumlarında hâlâ tartışıldığını vurguladı.

### 8.2 Süreç seçiminin önemi

Proje yönetiminde süreç önemlidir. Yazılım proje yönetiminin başında projeye ve ekibe hangi modelin uygun olduğuna ve hangi modelin izleneceğine karar verilmiş olmalı, proje buna uygun bir yapıyla başlamalıdır. Hoca bu konuda bir çalışmanın slaytlarını açtı.

### 8.3 PMI anketi

Gösterilen çalışma, çevik modellerin yaygınlaşmasından yıllar sonra ABD'de yapılmış bir ankettir. Hoca çevik metodolojilerin 2003 civarından itibaren kullanılmaya başladığını, çalışmanın bu kullanımın yaklaşık 10-15 yıl sonrasında yapıldığını söyledi (hoca iki farklı süre söyledi). Slayttaki bilgiye göre veriler anonim bir çevrimiçi anketle toplanmış, anket Proje Yönetimi Enstitüsü'nün (PMI, www.pmi.org) sitesinde yayımlanmış ve 2000 proje yöneticisine ve ekip üyesine gönderilmiş; katılımcılardan cevaplarını aktif rol oynadıkları ve yakın zamanda tamamlanmış bir yazılım projesine dayandırmaları istenmiştir (ekrandan, 01:35:00).

Hoca PMI'nın proje yöneticilerinin birbiriyle haberleştiği bir kuruluş olduğunu, sitesine arada bakılmasını önerdi. Kuruluşun üyeleri arasında en çok yazılım geliştiriciler, ikinci sırada inşaat mühendisleri yer alır; inşaat mühendisliğinde de proje yönetimi önemlidir. Katılımcılar proje yöneticisi, geliştirici ve analist gibi farklı rollerden gelir, çoğunluğu bilgi teknolojisi alanındandır.

**Proje türleri.** Slayttaki birinci grafik katılımcıların çalıştığı proje türlerini gösterir (ekrandan, 01:40:00):

| Proje türü | Yüzde |
|---|---|
| Yeni yazılım geliştirme | 38,6 |
| Yazılım iyileştirme (enhancement) | 24,2 |
| Hazır ticari yazılımın (COTS) özelleştirilmesi | 13,1 |
| Dış kaynaklı (outsourced) yazılım geliştirme | 2,0 |
| Yazılım entegrasyonu | 9,8 |
| Sistem taşıma (migration) | 6,5 |
| Kurumsal kaynak planlama (ERP) uygulaması | 2,6 |
| Diğer | 3,9 |

Yüzdelerin toplamı 100,7'dir; fark yuvarlamadan kaynaklanır (python ile kontrol edildi).

> **Ders sonrası not:** Slayttaki Türkçe metinde "ticari dışı yazılım (yüzde 13,1) kişiselleştirme" yazıyor. Grafikteki kategori "customization of commercial off-the-shelf software", yani hazır ticari paket yazılımın (COTS) kuruma özelleştirilmesidir; hoca da sözlü olarak bu anlamda anlattı.

COTS (Commercial Off-The-Shelf) hazır paket programlardır; şirketlere özelleştirme projeleri iş hayatında çok yapılır. ERP de önemli bir uygulama alanıdır.

**Proje süreleri.** İkinci grafik projelerin süresini gösterir (ekrandan, 01:40:00):

| Süre | Yüzde |
|---|---|
| 6 aydan az | 43,1 |
| 6-12 ay | 33,3 |
| 13-18 ay | 7,2 |
| 19-24 ay | 9,2 |
| 25-30 ay | 3,3 |
| 31-36 ay | 1,3 |
| 36 aydan fazla | 2,6 |

Toplam 100,0'dır. Hoca projelerin çoğunun küçük bütçeli ve kısa süreli olduğunu söyledi.

**Kullanılan metodolojiler.** Slayttaki grafik katılımcıların kullandığı metodolojilerin yüzdesini gösterir (ekrandan, 01:30:00):

| Metodoloji | Yüzde |
|---|---|
| Şelale (Waterfall) | 32,0 |
| Agile Unified Process | 28,1 |
| Scrum | 20,3 |
| Test güdümlü geliştirme (TDD) | 19,6 |
| Hızlı uygulama geliştirme (RAD) | 18,3 |
| Joint Application Development | 15,7 |
| Feature-driven development | 14,4 |
| Adaptive software development | 13,7 |
| Lean software development | 13,1 |
| Yapısal sistem analiz ve tasarım yöntemi (SSADM) | 9,2 |
| Extreme Programming | 8,5 |
| Rational Unified Process | 5,9 |
| PRINCE / PRINCE2 | 3,3 |
| Crystal | 3,3 |
| Dynamic systems development method | 1,3 |

Bu yüzdelerin toplamı 206,7'dir (python ile kontrol edildi). Hocanın açıklamasıyla uyumlu olarak bir projede birden çok yöntem (örneğin hem Scrum hem TDD) işaretlenebildiği için toplam 100'ü aşar.

Hocanın yorumları:

- Agile Unified Process, Unified Process'in klasik ve çevik arasında bir geçiş aşaması olduğunu gösterir.
- Rational Unified Process çok kullanılan bir platform olduğu için listede yer alır.
- Metodolojiler ve süreç modelleri birlikte değerlendirilmiştir; bu yüzden cevaplar iç içedir.
- Çevik süreçlere geçişin ilk yıllarında arka planda yine şelale kullanılmış, geleneksel proje yönetimi alışkanlıkları sürmüştür. Sonuçlarda şelalenin geçiş sürecinde en çok kullanılan yöntem çıkması bunu gösterir.
- Scrum uyguladığını söyleyen firmaların Scrum'un bütün aşamalarını ne kadar uyguladığı tartışmalıdır.
- Kurumlar modelleri birleştirerek kendilerine özgü bir süreç tanımlayabilir. Hoca, Türkiye'de bir şirketin Scrum'a geçişte kendi adını taşıyan bir çevik model tanımladığını örnek verdi.

### 8.4 Geleneksel, çevik ve hibrit yaklaşımlar

Çalışmada yaklaşımlar geleneksel, çevik, iteratif (spiral model gibi) ve hibrit (şirketlerin geleneksel ve çeviği birleştirdiği) olarak gruplanmıştır. Slayttaki "Proje Faktörleri" bölümünde projelerin kritikliğine göre bir dağılım verilmiştir: bütün projelerin yalnızca yüzde 5,1'i düşük kritikliğe sahiptir; orta kritiklikteki projeler çevik, iteratif ve karma yaklaşımları kullanan projelerin sırasıyla yüzde 48,8, 40,0 ve 25,4'ünü oluşturur, geleneksel yaklaşım projelerinin ise yalnızca yüzde 11,8'idir; kritikliği yüksek projeler bütün yaklaşımlarda en büyük grubu oluştursa da grupların boyutları yaklaşımlar arasında tekdüze değildir (ekrandan, 01:55:00).

<!-- BELİRSİZ: Aynı slayttaki yığılmış çubuk grafiklerin renk açıklaması karede görünmüyor; slayt metnindeki yüzdeler grafikteki değerlerle tam örtüşmüyor. Grafik değerleri bu yüzden nota alınmadı. -->

Hocanın verdiği seçim kuralları:

- **Hata kritik yazılım:** çok sayıda iterasyon ve tekrar tekrar kontrol gerekir; spiral model buna uygundur.
- **Sektörün günlük iş hayatına yönelik yazılımları:** Scrum daha uygundur.
- **Eski bir yazılım üzerinde yeni geliştirme:** Şelalenin en çok eleştirilen yanı, müşteriye ne yapılacağının uzun süre gösterilememesidir. Ama eskiden kullanılan bir yazılım varsa kullanıcılar ne istediklerini onun üzerinden canlandırabilir; bu tür projelerde şelale de hızlı işleyebilir.
- **RAD (Rapid Application Development):** IBM'in eski yıllarda ortaya attığı hızlı yazılım geliştirme modelidir. Birkaç ekip kurulup yazılım parçalara bölünerek hızlı ürün çıkarılır. İki koşul gerekir: yazılım parçalara bölünebilmeli ve yeterli sayıda ekip kurulabilecek kadar çalışan olmalıdır. Bu koşullar varsa ve hızlı geliştirme gerekiyorsa RAD kullanılabilir.
- Kurumun sektörü, gelir düzeyi ve çalışan sayısı da seçimi etkiler.

Hoca Türkiye'de birkaç yıl önce Ulusal Yazılım Mühendisliği Sempozyumu'nda (UYMS) hangi projelerde şelale kullanılması gerektiği ve her projede çevik kullanmanın faydaları ile zorluklarının tartışıldığı bildiriler sunulduğunu anlattı.

> **Hocanın vurgusu:** Projenin yapısına uygun süreç modeli seçilmelidir. "Artık Scrum var, her şeyi Scrum ile yaparız" diye gözü kapalı karar vermek uygun değildir.

Bu konu, proje başarı faktörleri ve başarılı ya da başarısız proje değerlendirme kriterleri işlendiğinde yeniden ele alınacaktır.

### 8.5 İteratif ve artımlı modellerin farkı

Ders boyunca geçen iki terim ayrıca açıklandı:

- **İteratif modeller:** yazılımın kendini tekrarlayarak, yavaş yavaş iyileştirildiği yaklaşımlardır.
- **Artımlı (incremental) modeller:** bir çekirdek modül oluşturulup kullanıma alınır, sonra yeni özellikler eklenerek ilerlenir. Her artım yeni yazılım modüllerinin eklenmesidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:31:43): Yazılım dediğimiz zaman ne anlıyoruz? Yazılım eşittir program mıdır?

> **Cevap (derste verildi):** Hayır. Yazılım; program, programın kullandığı veri (veri tabanı, tablolar ve veri tanımı) ve belgelerden (kullanıcı belgeleri, SRS, tasarım belgesi ve diyagramlar, test verileri) oluşur: Yazılım = Program + Veri + Belgeler.

**Soru 2** (derste sözlü, 01:07:03): CASE aracı nedir? Computer Aided Software Engineering kavramını açıklayın.

> **Cevap (derste verildi):** Bilgisayar destekli yazılım mühendisliği araçları, yazılım geliştirme sürecinin her adımında (proje ve konfigürasyon yönetimi, analiz ve tasarım diyagramlarının kurallı ve tutarlı çizimi, birim, bütünlük ve sistem testleri) geliştiricilere destek veren yazılımlardır. CAD/CAM yazılımlarının tasarım ve üretime verdiği desteğin yazılım geliştirmedeki karşılığıdır.

**Soru 3** (derste sözlü, 00:27:17): Yazılım geliştirme sürecindeki esas işlemler nelerdir?

> **Cevap (derste verildi):** Gereksinim analizi, tasarım, kodlama (gerçekleme), test ve bakım. Bunları destekleyen şemsiye işlemler proje yönetimi, kalite yönetimi, konfigürasyon yönetimi, risk yönetimi ve yazılım ölçümüdür.

## Dersin Toparlaması

Bu derste yazılım proje yönetiminin üç halkasından yazılım mühendisliği teknikleri, özellikle 3P'nin süreç (process) tarafı ele alındı. Yazılım mühendisliğinin tanımı, mühendisliğin tasarım ve ölçüm gerekleri, yazılımın program, veri ve belgelerden oluştuğu hatırlatıldı. Yazılım geliştirmenin esas işlemleri (gereksinim analizi, tasarım, kodlama, test, bakım) ve bunları destekleyen şemsiye işlemler (proje, kalite, konfigürasyon ve risk yönetimi, ölçüm) görüldü. Şelale, prototip, artımlı, spiral, Unified Process ve çevik modeller (XP, Scrum) tekrar edildi; bir anket çalışması üzerinden hangi modellerin ne kadar kullanıldığı ve modelin projenin yapısına göre nasıl seçileceği tartışıldı.

Hoca ilerleyen haftalarda temel proje yönetimi konularına geçileceğini söyledi: proje nedir, neye proje denir ve denmez, proje planı hazırlamak için hangi maddeler ve çalışmalar gerekir, proje yönetiminin aşamaları nelerdir. Bu konular bir bilgi sistemleri proje yönetimi kitabı üzerinden işlenecek ve yazılım projelerinden örneklerle desteklenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
