# Ders 6 Genişletilmiş Notu: Kavramsal Tasarım: ER Modeli, Anahtarlar, Zayıf Varlıklar, EER ve UML

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veritabanı Tasarım Süreci
- 2. Varlık, Nitelik ve Bağıntı
- 3. ER Gösterimleri ve Nitelik Türleri
- 4. Bağıntı Kümesi Sınırlamaları ve Eleman Sayıları
- 5. Var Olma Bağımlılığı (Katılım)
- 6. Recursive, İkili ve Üçlü Bağıntılar
- 7. Anahtarlar
- 8. Zayıf Varlık Kümeleri
- 9. Bağıntı Kümelerinin Anahtarları
- 10. Çok Dereceli (Üçlü) Bağıntılar
- 11. EER: Genelleme ve Alt Varlıklar
- 12. Aggregation
- 13. UML ile Modelleme
- Örnek Sorular
- Dersin Toparlaması

Ders Zoom üzerinden yapıldı. Hoca "07-ER-UML" adlı PowerPoint sunumunu kullandı (ekrandan, 01:16:23). Not, konuların anlatım sırasına göre düzenlendi.

## 1. Veritabanı Tasarım Süreci

Şimdiye kadar SQL, fonksiyonlar, prosedürler ve veritabanı güvenliği işlenirken hep hazır bir şema kullanıldı: öğrenci kayıt veritabanı, üniversite veritabanı ve laboratuvardaki company veritabanı. Bu derste sorulan soru şu: bu şemalar, yani küçük dünyayı temsil eden yapı nereden geliyor? Hoca, ders örneklerinin eğitim amaçlı küçük "oyuncak" veritabanları olduğunu, uzun yıllar kullanılan gerçek sistemlerde tablo sayısının, fonksiyonların ve yetkilendirme ayarlarının çok daha kapsamlı olduğunu belirtti.

Kavramsal tasarım, küçük dünyada olan biteni ve oradaki varlıkları önce bilgisayara değil "kağıda taşımak", yani kutular, dörtgenler ve aralarındaki bağlantılarla temsil etmektir. Örnek veritabanı company veritabanı olacak. Asıl kullanılacak gösterim ER ve EER'dir; UML bir standart olduğu için ondan da söz edilecek.

### 1.1 Tasarım aşamaları

Slaytta (ekrandan, 00:12:15) VT tasarımı ile uygulama tasarımı ayrılıyor:

- VT tasarımı: veri modelleme; veri mühendisliği ve bilişim uzmanlığı ile ilgili.
- Uygulama tasarımı: program akışı ve arayüzlerin tasarımı; yazılım mühendisliği ile ilgili.

Aynı slayttaki şema (Figure 3.1) şu adımları gösteriyor:

```text
Miniworld
  -> REQUIREMENTS COLLECTION AND ANALYSIS
       -> Functional Requirements -> FUNCTIONAL ANALYSIS
            -> High-Level Transaction Specification
            -> APPLICATION PROGRAM DESIGN -> TRANSACTION IMPLEMENTATION -> Application Programs
       -> Data Requirements -> CONCEPTUAL DESIGN
            -> Conceptual Schema (in a high-level data model)
            -> LOGICAL DESIGN (DATA MODEL MAPPING)
            -> Logical (Conceptual) Schema (in the data model of a specific DBMS)
            -> PHYSICAL DESIGN -> Internal Schema
Kesikli çizginin üstü: DBMS-independent, altı: DBMS-specific
```

Hoca sağdaki dalı bu dersin konusu olarak tanımladı: kavramsal tasarım (ER), mantıksal tasarım (ilişkisel model tabloları) ve fiziksel tasarım. Fiziksel tasarım, sistem ayağa kalkıp kullanılmaya başladığında hızlı ve doğru çalışması için yapılan ayarlardır. Soldaki dal fonksiyonel analizdir: veritabanı uygulamaları ya da üçüncü taraf uygulama programları yazılır.

Kesikli çizginin altındaki işler veritabanına özgüdür. PostgreSQL, Oracle ve SQL Server'da saklı yordamlar ve hatta yazılan SQL farklı olabilir; bazı operatörler bazı sistemlerde yoktur. Hoca örnek olarak SQLite'ın çok küçük bir sistem olduğunu ve bazı operatörleri gerçeklemediğini, Oracle ve PostgreSQL'in ise kapsamlı ekosistemler olduğunu söyledi.

Hoca, kavramsal tasarımda verilen kararları bir ağacın çekirdeğine benzetti: çekirdekte bir bozukluk varsa ağaç istenen meyveyi vermez. Bu yüzden bu aşamadaki kararlar veritabanının bütün kullanım hayatını etkiler.

### 1.2 Geri dönüşümlü süreç ve database life cycle

İkinci slayttaki (ekrandan, 00:17:15) etkinlik diyagramı süreci şöyle veriyor:

```text
Information Requirements: Determine requirements
Logical Design: Model -> [multiple views] Integrate views -> Transform to SQL tables
                Model -> [single view] -> Transform to SQL tables
                Transform to SQL tables -> Normalize
Physical Design: Select indexes -> [special requirements] Denormalize / [else]
Implementation: Implement -> Monitor and detect changing requirements
                -> [else] Determine requirements (başa dönüş) / [defunct] son
```

Her aşamada yeni gereksinimler ortaya çıkabilir; mantıksal ve fiziksel tasarıma geri dönülerek sistem iyileştirilir. Hoca buna tuning (fine tuning) dendiğini söyledi.

Sağdaki "Database Life Cycle" kısmında küçük dünyanın varlıkları (Products, Salespersons, Orders, Customers) farklı kullanıcılar açısından farklı alt şemalar oluşturur. Retail salesperson view'da customer, product ve salesperson arasında orders, served-by ve sold-by bağıntıları vardır. Customer view'da müşteri sipariş verir (customer 1 - places - N order). Bu görünümler birleştirilince (view integration) daha büyük bir şema ortaya çıkar. Büyük şemalar böyle alt şemaların bir araya gelmesiyle büyür.

### 1.3 Aşamaların içeriği

Gereksinimlerin toplanması ve analizi kendi kuralları ve kitapları olan, yazılım mühendisliğine yakın bir alt süreçtir; derste hızlı geçildi. Kavramsal aşamada küçük dünyadaki kavramlar, varlıklar ve bağıntılar belirlenir; gereksinimler şekillerle, gerekirse yanına yazılan açıklama ve varsayımlarla ifade edilir. Mantıksal tasarımda kavramsal şemadan ilişkisel model tablolarına belirli kurallarla dönüşüm (mapping) yapılır. En son fiziksel tasarımda indeksler, yardımcı görünümler ve yetkilendirme ayarları yapılır.

ER modelinde varlıklar, bağıntılar ve nitelikler vardır; nitelikler hem varlıklara hem bağıntılara ait olabilir. UML (Unified Modeling Language) yazılım sürecindeki veriyi ve fonksiyonları tek bir dille ifade etmeyi amaçlar ve ER'deki işlemler UML ile de yapılabilir. Yine de hoca, tanınmış veritabanı kitaplarının büyük çoğunluğunda ER diyagramlarının geleneksel olarak yer aldığını belirtti. PostgreSQL gibi sistemlerin yönetim arayüzlerinde de ER diyagramı hazırlamaya yarayan araçlar vardır; bunlar dersteki ER modeline benzer ama aynısı değildir.

## 2. Varlık, Nitelik ve Bağıntı

Slayttaki tanımlar (ekrandan, 00:27:15):

- Var olan ve diğerlerinden ayırt edilebilen her nesneye **varlık** denir. Benzer varlıkların oluşturduğu kümeye **varlık kümesi** denir.
- Varlıkların **nitelikleri** vardır; bu nitelikler ile varlıklar birbirinden ayırt edilir. Örnek: EMPLOYEE (İŞÇİ) için John Smith, Research, ProductX.
- Her niteliğin bir değer alanı, yani olurlu değerlerinin tümünü içeren bir küme (**domain**) vardır. Niteliğin tipi, değer aralığı ve formatı bu kapsamdadır.
- İki ya da daha çok varlığın arasındaki "olayı" tanımlamaya yarayan kavrama **bağıntı** denir. Aynı türdeki benzer bağıntıların kümesine **bağıntı kümesi** denir. Örnek: ÖĞRENCİ DERSİ ALIYOR ise DERS ile ÖĞRENCİ arasında bir bağıntı vardır.

Öğrenci kayıt veritabanında öğrenciler ile departmanlar tanım olarak farklıdır. Öğrenciler kendi içinde aynı niteliklere sahiptir ve öğrenci numarası ya da kimlik numarası gibi bir nitelikle birbirinden ayrılır. Domain için hoca öğrenci numarasını örnek verdi: numaranın belli bir formatı (örneğin giriş yılıyla başlaması) ve bir veri tipi (integer, bigint gibi) vardır. <!-- BELİRSİZ: Hocanın öğrenci numarası formatı örneğinin ayrıntısı altyazıda bozuk. -->

Veritabanı birbiriyle alakalı varlıkların oluşturduğu küçük dünya olduğuna göre, hangi varlıklar arasında bağıntı olduğunun tespit edilmesi ve bu bağıntının biçimlendirilmesi gerekir. Yapı taşları (building blocks) varlıklar ve bağıntılardır. Küçük dünya tarif edilirken kullanılan özneler varlık olmaya, fiiller bağıntı olmaya adaydır: "öğrenciler ders alıyor" cümlesinde "alma" öğrenci ile ders arasındaki bağıntıdır. Fikir basittir ama küçük dünya bu kadar basit cümlelerle tarif edilmez; çok varlık ve olay olabilir. Kavramsal tasarımın zor tarafı tek bir doğru tasarımın olmamasıdır.

## 3. ER Gösterimleri ve Nitelik Türleri

Varlıklar dikdörtgenle, nitelikler elips içinde nitelik adıyla gösterilir. Hoca, literatürde ve PostgreSQL araçlarında başka ER gösterimleri de bulunduğunu, ama en yaygın ve klasik olanın bu olduğunu ve değerlendirmede buna uyulmasının kolaylık sağlayacağını belirtti.

Slayttaki "Temel yapı taşları: varlık, bağıntı" örnekleri (ekrandan, 00:32:15):

- DEPARTMENT: Name ve Number altı çizili, Locations çift elips, Manager, Manager_start_date.
- PROJECT: Name ve Number altı çizili, Location, Controlling_department.
- CAR: Registration (State, Number) birleşik ve altı çizili, Vehicle_id altı çizili, Year, Model, Make, Color çift elips.

### 3.1 Birleşik ve tekil nitelik

Alt niteliklere ayrılan niteliğe birleşik (composite) nitelik denir. Arabanın Registration numarası eyalet adı ve numaradan oluşur; hoca bunu il koduyla başlayan plakaya benzetti. Alt niteliğe ayrılmayan nitelik tekil (singular) niteliktir.

### 3.2 Anahtar nitelik

Altı çizili nitelik anahtardır: varlık kümesindeki varlıkları birbirinden ayırt etme kabiliyeti vardır. CAR'da Vehicle_id her araba için farklıdır; ondan bağımsız olarak birleşik Registration niteliği de arabaları biricik kılar. DEPARTMENT'ta Name ve Number ayrı ayrı anahtardır; ikisi birlikte değil, her biri tek başına departmanları farklı kılar. PROJECT'te de proje adı ve numarası ayrı ayrı benzersizdir.

Bu kararın kaynağı ezber değil, küçük dünyadır. Gereksinim analizinde müşteriyle görüşülür; müşteri "proje adları ve numaraları birbirinden farklı olacak" derse tasarım buna göre yapılır.

### 3.3 Çok değerli nitelik

Çift çizgili elips çok değerli (multivalued) niteliktir: bir varlığın o niteliği için birden çok değeri olabilir. Bir arabanın rengi kırmızı-siyah gibi birden çok renk olabilir.

### 3.4 Örnek varlık kümesi

Slaytta CAR varlık kümesinin üç örneği verildi (ekrandan, 00:32:15):

```text
CAR
Registration (Number, State), Vehicle_id, Make, Model, Year, {Color}

CAR1: ((ABC 123, TEXAS), TK629, Ford Mustang, convertible, 2004 {red, black})
CAR2: ((ABC 123, NEW YORK), WP9872, Nissan Maxima, 4-door, 2005, {blue})
CAR3: ((VSY 720, TEXAS), TD729, Chrysler LeBaron, 4-door, 2002, {white, blue})
```

ABC 123 numarası iki kez geçiyor ama eyaletler farklı; (Number, State) ikilisi bir daha aynı biçimde görülmemelidir, çünkü ikisi birlikte anahtardır. Vehicle_id değerleri ise hep farklıdır. CAR1'in rengi {red, black} olarak iki değer içerir.

### 3.5 Gösterimlerin tamamı

Hocanın ER gösterim özeti:

- Varlık: dikdörtgen. Çift çizgili dikdörtgen: zayıf varlık.
- Bağıntı: eşkenar dörtgen ("baklava" biçimi).
- Nitelik: elips. Altı çizili: anahtar nitelik. Çift çizgili: çok değerli. Alt niteliklere ayrılan: birleşik (composite / complex). Kesikli çizgili: türetilmiş (derived) nitelik.
- Bağıntı çizgileri üzerinde bağıntı adı, varlık kümelerinin adları ve eleman sayıları (cardinality) bulunur.
- Katılım (participation): tek çizgi kısmi (partial), çift çizgi tam (total) katılımdır.

## 4. Bağıntı Kümesi Sınırlamaları ve Eleman Sayıları

### 4.1 İkili bağıntı ve örnek küme

Bağıntı iki varlık kümesi arasında kurulur; bu kümeler aynı olabilir (recursive) ya da farklı olabilir. Slayttaki ÖĞRENCİ - R - DERS bağıntısı (ekrandan, 00:32:15) öğrencinin ders almasını ifade eder. Bağıntıya R yerine "ders alma" gibi hatırlatıcı bir isim verilebilir.

Varlık kümesinin bir anlık görüntüsü (instance) olduğu gibi bağıntı kümesinin de vardır. Slayttaki şekilde (Figure 3.13, M:N ilişki) sol kümedeki elemanlar (e1, e2, e3, e4) orta kümedeki bağıntı örnekleri (r1, r2, ...) üzerinden sağ kümedeki elemanlara (p1, p2, p3, p4) bağlanıyor.

Eleman sayısı (cardinality) 1-1, 1-N, N-1 ya da N-N olabilir. ÖĞRENCİ tarafından bakınca N, bir öğrencinin N ders alabileceğini söyler: e1 birden çok dersle, e2 hem p1 hem p4 ile eşleşmiş. DERS tarafından bakınca bir dersin birçok öğrencisi olabilir: p1 hem e1 hem e2'yi içerir, p2 yalnız e3'ü içerir, p3 iki öğrenciyi içerir. Bu da küçük dünyadan gelir: bir öğrenci çok ders alır, bir dersi de çok öğrenci alır.

> **Hocanın vurgusu:** SQL'de de kavramsal tasarımda da tanımlar ve kavramlar basittir. Ama bu kavramlar üst üste konur; sağlam yerleştirilmezlerse üstüne kurulan yapı yıkılır. Kolay olanlar bir araya gelince karmaşıklaşabilir, bu yüzden iyice anlamak gerekir.

### 4.2 Sınırlamalar

Slayttaki "Bağıntı Küme sınırlamaları" (ekrandan, 00:42:15):

- Bağıntı ismi (relationship name): manaya uygun bir isim.
- Bağıntıdaki varlıklar (participating entity types): 2 veya daha çok, aynı veya farklı varlıklar arasında.
- Bağıntının derecesi (degree of a relationship): 2, 3, ...
- Eleman sayıları, kaça-kaçlık olduğu (cardinality ratio): 1-1, 1-N, N-1, N-N.
- ROL tanımlama: Bağıntıdaki varlıkların bağıntıdaki işlevlerini belirleyen bir rolleri vardır. Bunun açık, anlaşılır olmadığı durumlarda belirtilmesi gerekir.

Gerçek hayatta çoğunlukla ikili bağıntılar kullanılır; tasarımı kolaylaştırırlar. Daha ince bir ayar gerektiğinde 3 ya da daha fazla dereceli bağıntılar kullanılır.

### 4.3 Customer - rents - CAR örneği

Slayttaki örnekte Customer (cust-id, cust-name) ile CAR (plateno, model, type) arasında N-N bir rents bağıntısı ve bağıntının due-date niteliği var. Bir müşteri aynı anda ya da farklı zamanlarda birden çok araba kiralayabilir, bu yüzden N makuldür. Bir arabanın farklı tarihlerde farklı müşterilere kiralanması da doğaldır. Ancak "aynı tarihte birden çok müşteri bir aracı kiralayabilir mi?" sorusunun cevabı tasarımı değiştirir: aynı aracı aynı anda birden çok müşteri kiralıyorsa bir kaza durumunda birden çok müşteri sorumlu olur. Bu tür ayrıntıların belirlenmesi için gereksinim listesinin iyice analiz edilmesi gerekir.

## 5. Var Olma Bağımlılığı (Katılım)

Slayttaki tanım (ekrandan, 00:47:15): B varlık kümesindeki her bir 'b' varlığı, A varlık kümesindeki bir 'a' varlığı ile mutlaka bir bağıntı kurması gerekiyorsa, "B varlık kümesi A varlık kümesine var olma bağımlıdır" denir. Burada A birincil varlık, B ikincil varlık olarak adlandırılır (total / partial participation).

Slayttaki genel şekilde A - R - B bağıntısı N-N'dir; B tarafı çift çizgi (total), A tarafı tek çizgidir (partial). Yani her B mutlaka bir A ile bağıntıdadır ama bütün A'lar bağıntıda yer almayabilir. Bu tanım eleman sayısından bağımsızdır.

Hoca bunu 1-1 bir bağıntı üzerinden sayısal olarak açıkladı: B tarafı total ise B'deki 100 varlığın her biri A'dan bir varlıkla eşleşir. A tarafı kısmi olduğu için A'da 200 varlık olabilir; bunlardan yalnız 100'ü bağıntıda yer alır, kalan 100'ü yer almaz. N-N'de durum benzer ama daha esnektir.

### 5.1 Department - is-managed-by - Employee

Önce eleman sayıları belirlenir, sonra katılım. Bir departmanı yöneten kişi birdir; hoca bunu bir köyün tek muhtarı olmasına benzetti, bölüm başkanı tek kişidir. Bir çalışanın birden çok departman yönetip yönetemeyeceği küçük dünyaya göre sorulabilir; slaytta 1 seçilmiş, yani bir çalışan en fazla bir departman yönetir.

Katılımda departman tarafı çift çizgilidir: her departmanın mutlaka bir yöneticisi vardır. Çalışan tarafı tek çizgi olmak zorundadır. Bir kurumdaki her çalışanın bir başkanlık görevi olması mümkün değildir; kaç bölüm varsa o kadar kişi başkanlık yapar. Bu yüzden çalışan tarafının çift çizgi olması kesinlikle yanlış olur.

### 5.2 Office - is-occupied-by - Employee

Bir ofiste birden çok çalışan oturabilir (birkaç asistanın bir odayı paylaşması gibi), bir çalışanın bir ofisi vardır: 1-N. Hoca, gerçek hayatta bazı yöneticilerin birden çok odası olabileceğini, ama gereksinim listesinde "herkesin tek odası var" yazıyorsa 1 yazılacağını söyledi.

Katılımda iki taraf da çift çizgilidir: her ofiste mutlaka biri oturur (boş oda yok) ve her çalışana işe girer girmez bir oda tahsis edilir. Hoca, bina yeni hizmete girdiğinde boş oda olacağı için ofis tarafındaki total katılımı çok gerçekçi bulmadığını, ama slayttaki tasarımın bu şekilde yapıldığını belirtti.

Küçük dünya kağıda ne kadar iyi taşınırsa ilişkisel model tablolarına aktarıldıktan sonra veritabanı da o kadar başarılı olur.

## 6. Recursive, İkili ve Üçlü Bağıntılar

Slayttaki gösterim tablosu (ekrandan, 00:57:15):

| Kavram | Gösterim ve örnek |
|---|---|
| Degree: recursive binary | Employee (1, manager) - manages - Employee (N, subordinate) |
| Degree: binary | Department (N) - is-subunit-of - (1) Division |
| Degree: ternary | Employee (N) - uses - (N) Project, (N) Skill |
| Connectivity: one-to-one | Department (1) - is-managed-by - (1) Employee |
| Connectivity: one-to-many | Department (1) - has - (N) Employee |
| Connectivity: many-to-many | Employee (N) - works-on - (N) Project; nitelikler: task-assignment, start-date |
| Existence: optional | Department (1) - is-managed-by - (1) Employee |
| Existence: mandatory | Office (1) - is-occupied-by - (N) Employee |

Recursive bağıntıda (unary) bir çalışanı yöneten başka bir çalışandır. Burada rol tanımı gerekir: bir yöneticinin (manager) birden çok alt çalışanı (subordinate) vardır, bir çalışanın bir yöneticisi vardır. Roller en çok recursive bağıntılarda karşımıza çıkar.

İkili örnekte bir departman bir division'a (fakülte gibi) bağlıdır, bir division'da birden çok departman olabilir.

Üçlü bağıntıda (Employee, Project, Skill) eleman sayıları diğer iki varlıktan birer numune alınarak okunur. Bir işçi bir projede N tane iş (beceri) kullanır. Bir projedeki bir iş birden çok kişi tarafından yapılır. Bir işçi aynı işi birçok projede yapar. Durum böyleyse üç taraf da N olur. İkili bağıntıda tek taraftan bir numune alıp karşı tarafa gidiliyordu; üçlüde iki taraftan birer numune alınır.

Slaytta "optional / mandatory" adı kullanılıyor; derste kullanılan "kısmi / total" ile aynı anlamdadır: mandatory = total, optional = kısmi.

## 7. Anahtarlar

Slayttaki tanımlar (ekrandan, 01:02:15):

- Varlık/Bağıntı kümesindeki varlık/bağıntıları birbirinden ayırt etmek için kullanılan nitelik veya nitelik grubuna **anahtar** denir.
- **Super anahtar (superkey):** Bütün anahtarlar super anahtardır.
- **Aday anahtar (candidate key), BA:** Bir varlık/bağıntı kümesinin 'K' super anahtarının hiçbir öz-alt kümesi super anahtar değilse, 'K' o varlık/bağıntı kümesinin aday anahtarı olur. Diğer bir ifadeyle «aday anahtar» = «minimal super key».

Hoca tanımları adım adım kurdu. Önce hiçbir kısıt yoktur: bir varlık kümesinin bütün nitelikleri birlikte zaten varlıkları ayırt eder; varlıkları biricik olarak tanımlayan herhangi bir nitelik grubuna super key denir. Sonra kısıt konur: o nitelik grubundan herhangi bir nitelik çıkarıldığında anahtar olma özelliği kayboluyorsa grup minimaldir ve aday anahtar adını alır. Birincil anahtar (primary key) aday anahtardan çok farklı değildir: çok sayıda aday anahtar olabilir, bunlardan seçilen biri birincil anahtardır.

Hoca bu konunun ilişkisel model teorisine ve normalizasyona dayandığını, notasyon gerektiren kısmının sonraki derslerde görüleceğini söyledi.

## 8. Zayıf Varlık Kümeleri

Slayttaki tanım (ekrandan, 01:02:15): Bir varlık kümesinde anahtar bulunamıyorsa (bütün nitelikler bir arada olsa da anahtar olmuyorsa) bu varlık kümesine **«zayıf varlık kümesi»** denir. Anahtarı olan varlık kümesine «güçlü varlık kümesi» denilir.

- Zayıf varlık kümesi, güçlü bir varlık kümesi ile 1-1 veya N-1 tipinde var olma bağımlı bir bağıntı kurmalıdır.
- Zayıf varlık kümesindeki, aynı güçlü varlığa bağlı olan varlıkları ayırt edebilmek için ayırt edici nitelik(ler) (AN) tanımlamak gerekir.

Varlık kümesi "birbirinden ayırt edilebilen" varlıklar olarak tanımlandığı için normalde bütün nitelikler birlikte bir anahtar oluşturur. Ayırt edilemiyorsa ama yine de bu varlıklar bir küme olarak tutulmak isteniyorsa zayıf varlık kümesi kullanılır ve çift çizgili dikdörtgenle gösterilir. N tarafı zayıf varlıkta, 1 tarafı güçlü varlıktadır. Zayıf varlıklar tek başlarına ayırt edilemediği için her biri mutlaka güçlü bir varlıkla bağıntıda olmalıdır ve bağlı oldukları güçlü varlığın altında ayırt edilirler.

### 8.1 Lise - Öğrenci örneği

Slaytta (ekrandan, 01:07:15) LİSE (isim, altı çizili) 1 - kayıtlı - N ÖĞRENCİ (çift dikdörtgen, öğrNo kesikli altı çizili) var. Tasarımda lisenin yalnız bir isim niteliği, öğrencinin yalnız bir numara niteliği vardır. Türkiye'deki liselerin isimlerinin birbirinden farklı olduğu garanti ediliyor, bu nitelik liseyi güçlü kılmaya yeterlidir. Ama farklı liselerde aynı öğrenci numarası kullanılabilir; Türkiye'deki bütün lise öğrencilerinin tutulduğu büyük bir tabloda aynı numaralar tekrar eder. Bu yüzden öğrenci zayıf varlıktır; bir lise altında öğrenciler numarayla ayırt edilir.

> **Hocanın vurgusu:** Hoca, kayıtlı bağıntısının zayıf varlık için var olma bağımlı (tanımlayıcı) bir bağıntı olduğunu, bu yüzden slayttaki tek çizgili baklavanın çift çizgiyle çizilmesi gerektiğini belirtti.

### 8.2 Satış formu - Satır örneği

Aynı slaytta SatışFormu (satışno altı çizili, tarih, geneltoplam kesikli elips yani türetilmiş) 1 - SS (çift çizgili baklava) - N Satır (çift dikdörtgen, Satırno kesikli altı çizili) var. Bir satış takibinde satış formunun içinde satırlar vardır ve her satırda alınan ürün bulunur. Satır numarası her formda "birinci satır, ikinci satır" diye yeniden başladığı için tek başına satırları biricik kılmaz. Satır numarası yalnız bir satış formu içinde benzersizdir; bu yüzden Satır zayıf varlık, SatışFormu ise onun var olma bağımlı olduğu güçlü varlıktır.

## 9. Bağıntı Kümelerinin Anahtarları

Kaydın ilk yarısında (dersin ikinci saati) hoca anahtar konusunu bağıntılara genişletti. Slayt 16 (ekrandan, 01:16:23):

- **Bağıntılardaki anahtarlar:**
  - N-N bağıntı kümesinin anahtarı, bağıntı içerisindeki varlık kümelerinin anahtarlarının hepsidir.
  - 1-N bağıntı kümesinin anahtarı N-tarafındaki bağıntının anahtarıdır.
  - 1-1 bağıntı kümesinin anahtarı ise herhangi bir varlık kümesinin anahtarı olabilir.
- **Zayıf varlık kümesinin anahtarı**, var olma bağıntısı içerisindeki güçlü varlık küme(ler)sinin BA'ları + AN'dir.
- Buna göre; önceki örneklerdeki bağıntıların anahtarlarını belirleyiniz.

> **Hocanın vurgusu:** Bu kuralların hepsi çok önemlidir; bundan sonra yapılacak şeyler bunlara bağlıdır. Kuralı almak yetmez, başka türlü anahtar olamayacağını görmek gerekir.

Bağıntı da sonuçta bir kümedir: iki varlığın elemanlarının bir araya gelmesiyle oluşur ve onun da bir anahtarı vardır. Bu anahtar eleman sayısına bağlıdır. Hoca kuralları gösterim tablosundaki örnekler üzerinden gerekçelendirdi (ekrandan, 01:21:23).

### 9.1 Bire bir: Department - is-managed-by - Employee

Bu bağıntıya uygun bir örnek küme şudur:

$$(d_1,e_1),\ (d_2,e_2),\ (d_3,e_3),\ \dots$$

Hiçbir zaman $(d_1,e_1)$ ile birlikte $(d_1,e_2)$ görülmez, çünkü bağıntı bire birdir. Aynı şekilde $(d_1,e_1)$ ile $(d_2,e_1)$ de görülmez, çünkü $e_1$ bir departmanın yöneticisidir. Her departman ve her çalışan kümede en fazla bir kez geçer. Bu yüzden departman numarası tek başına bağıntı kümesini biricik kılmaya yeterlidir; çalışan numarası da yeterlidir.

### 9.2 Bire N: Department - has - Employee

Örnek küme:

$$(d_1,e_1),\ (d_1,e_2),\ (d_1,e_3)$$

$d_1$ üç çalışanla eşleştiği için departman numarası tek başına anahtar olamaz. Ama $(d_1,e_1),(d_2,e_1)$ görülemez, çünkü bir çalışan birden çok departmanda çalışamaz. Bu küçük dünyada bir çalışan kümede en fazla bir kez geçer. Bu yüzden 1-N bağıntının anahtarı N tarafındaki varlığın anahtarıdır.

### 9.3 N'e N: Employee - works-on - Project

Örnek küme:

$$(e_1,p_1),\ (e_1,p_2),\ (e_3,p_1)$$

$p_1$ hem $e_1$ hem $e_3$ ile, $e_1$ hem $p_1$ hem $p_2$ ile eşleşmiştir. Her iki taraf da birden çok kez geçebildiği için tek tarafın anahtarı yeterli değildir; anahtar iki varlığın anahtarlarının birleşimidir.

### 9.4 Zayıf varlık

Zayıf varlığın kendi niteliklerinin hepsi birlikte bile anahtar olamadığı için ona bir güçlü varlık tanımlanmıştı. Güçlü varlığın birincil anahtarı ile zayıf varlığın ayırt edici niteliği birleşince zayıf varlığın anahtarı elde edilir.

## 10. Çok Dereceli (Üçlü) Bağıntılar

Çok dereceli bağıntılar çok yaygın kullanılmaz ama ER kapsamında önemli ve biraz daha teorik bir konudur. Küçük dünyayı çok iyi ifade edebildikleri için gerekebilirler.

### 10.1 ÇALIŞAN - PROJE - MAKİNE

Slayt 17 (ekrandan, 01:26:23) ÇALIŞAN, PROJE ve MAKİNE arasında bir R bağıntısı gösteriyor ve "Yukarıdaki 3'lü bağıntıda: İki varlık arasındaki bağıntı, 3. varlıktan bağımsız bir şekilde ifade edilemiyor" diyor. Kenarlara bir şey yazılmamışsa N anlamına gelir. Küçük dünya şöyledir: bir çalışan bir projede birçok makine kullanır (masaüstü, dizüstü, GPS cihazı, cep telefonu gibi). Bir projedeki bir makineyi birçok çalışan kullanır. Bir çalışan bir makineyi birçok projede kullanır. Her okumada iki taraftan numune alınır, üçüncüsü çoklu olarak ifade edilir.

### 10.2 Bire bire bir: Technician - uses-notebook - Project

Aynı slayttaki örnekte üç taraf da 1'dir. Slayttaki küçük dünya: "A technician uses exactly one notebook for each project. Each notebook belongs to one technician for each project. Note that a technician may still work on many projects and maintain different notebooks for different projects." Fonksiyonel bağımlılıklar:

```text
emp-id, project-name -> notebook-no
emp-id, notebook-no -> project-name
project-name, notebook-no -> emp-id
```

Hoca anahtarı örnek kümeyle buldu. $(t_1,p_1,n_1)$ varken $n_1$ yine geçebilir mi? Evet: $(t_2,p_2,n_1)$ olabilir. Hatta $(t_1,p_2,n_1)$ de olabilir. İkili bağıntıdaki gibi "1 yazınca kümede bir kez görünür" durumu yoktur, çünkü üçlüdeki 1, diğer iki taraftan birer numune alındığında bir kez görüneceği anlamına gelir. Bu yüzden ne notebook'un, ne projenin, ne teknisyenin anahtarı tek başına yeterlidir.

Buna karşılık $(t_1,p_1)$ ikilisi kümede ancak bir kez geçebilir, çünkü bir teknisyen bir projede tek bir notebook kullanır. Aynı şey $(p_1,n_1)$ ve $(t_1,n_1)$ için de geçerlidir. Demek ki en az iki varlık seçilmelidir ve herhangi iki varlığın anahtarı (Technician-Project, Project-Notebook ya da Technician-Notebook) bağıntı kümesinin anahtarı olabilir.

### 10.3 Diğer üçlü örnekler

Slayt 18 (ekrandan, 01:31:23). Şekillerdeki N, P, M harfleri yalnız "çoklu" anlamındadır, farklı sayıları ifade etmez.

- **(b) one-to-one-to-many:** Project (1) - assigned-to - (N) Employee, Location (1). "Each employee assigned to a project works at only one location for that project, but can be at different locations for different projects. At a particular location, an employee works on only one project. At a particular location, there can be many employees assigned to a given project." Fonksiyonel bağımlılıklar: emp-id, loc-name -> project-name; emp-id, project-name -> loc-name. Project ve Location ikilisi çok kez geçebildiği için anahtar olamaz; N tarafındaki Employee'yi içeren bir ikili seçilmelidir: Employee-Location ya da Employee-Project.
- **(c) one-to-many-to-many:** Manager (1) - manages - (N) Engineer, (P) Project. "Each engineer working on a particular project has exactly one manager, but each manager of a project may manage many engineers, and each manager of an engineer may manage that engineer on many projects." Fonksiyonel bağımlılık: project-name, emp-id -> mgr-id. Çoklu olan iki taraftan (Engineer ve Project) anahtar seçmek yeterlidir: bu ikili kümede bir kez geçer ve managed bağıntısının anahtarını oluşturur.
- **(d) many-to-many-to-many:** Employee (M) - skill-used - (N) Project, (P) Skill. "Employees can use many skills on any one of many projects, and each project has many employees with various skills." Fonksiyonel bağımlılık: yok. Herhangi iki varlığın ikilisi çok kez geçebildiği için hiçbir ikili anahtar olamaz; üçünün anahtarları birlikte anahtar olur.

### 10.4 Üçlü bağıntı ve ikili bağıntılar

Bazı çizim araçları üçlü ya da çoklu bağıntıya izin vermez. Hoca, veritabanı tasarımcılığının ayrı bir meslek olduğunu, bu iş için ERwin gibi ücretli araçlar da bulunduğunu söyledi. Üçlü bağıntı yerine ikili bağıntılar kullanılabilir ama bunlar küçük dünyayı tam tasvir etmeyebilir.

Slayt 19 (ekrandan, 01:36:23) iki tasarımı karşılaştırıyor:

- Üçlü: SUPPLIER (Sname) - SUPPLY (Quantity) - PROJECT (Proj_name), PART (Part_no).
- İkili: SUPPLIER (M) - SUPPLIES - (N) PROJECT; SUPPLIER (M) - CAN_SUPPLY - (N) PART; PROJECT (M) - USES - (N) PART.
- Soru: "Which one conveys more information?" ve altında $(s,j,p) \neq (s,p)\ (j,p)\ (s,j)$.

Üçlü bağıntı "bir tedarikçi bir parçayı bir projeye sağladı" bilgisini taşır. İkili tasarım ise bir tedarikçinin bir projeye mal sağladığını, bir tedarikçinin bir parçayı sağlayabildiğini ve bir projede bir parçanın kullanıldığını söyler. Bu üç bilgiden "bu tedarikçi bu parçayı bu projede sağladı" sonucu yüzde yüz çıkarılamaz; en fazla olasılıksal bir çıkarım yapılabilir. Ancak belirli koşullarda (örneğin bir projede o parçanın tek tedarikçisi varsa) bu çıkarım yapılabilir. Bu yüzden bağıntı N-N-N ise küçük dünyayı tam ifade etmek için üçlü bağıntı kullanmak gerekir; N-N-N değilse ikili bağıntılar bazı durumlarda yeterli olabilir.

### 10.5 Zayıf varlıkla üçlü bağıntının ifadesi

Kullanılan araç üçlü bağıntıya izin vermiyorsa aynı anlam zayıf bir varlıkla verilebilir (ekrandan, 01:36:23):

```text
SUPPLIER (Sname) 1 --SS-- N SUPPLY (Quantity) N --SPJ-- 1 PROJECT (Proj_name)
                              N
                              |
                             SP
                              |
                              1
                         PART (Part_no)
SUPPLY: zayıf varlık; SS, SPJ, SP: tanımlayıcı bağıntılar (çift çizgili)
```

Tedarik etme olayı SUPPLY adlı zayıf bir varlık yapılır ve miktarı (Quantity) da tutulur. Zayıf varlığın var olma bağımlılığı üç güçlü varlık kümesi üzerinden kurulur; üç bağlantı birlikte onu "güçlü" kılar. SUPPLY'ın anahtarı Sname, Part_no ve Proj_name'in üçü birden olur; bu da üçlü bağıntının anahtarına denk gelir.

Slayttaki bir sonraki soru: "One more step further: If we do not want to use weak entity type, how to design?" Hoca, zayıf varlık kullanılmak istenmiyorsa ya da araç izin vermiyorsa SUPPLY'ın güçlü bir varlık yapılıp kendine ait bir anahtar verilebileceğini söyledi. Zayıf varlık kullanmadan her şeyi güçlü yapmak ya da üçlü bağıntı kullanmamak her zaman mümkündür; bunlar kavramsal tasarımın ince ayarlarıdır.

> **Hocanın vurgusu:** Kullanılabiliyorsa zayıf varlık kullanmak iyi bir tasarımdır. Ek bir birincil anahtarın takip edilmesi ve biricik kılınması sistem için ayrı bir yüktür; zayıf varlık bu yükü getirmez.

### 10.6 Enrolls-in örneği

Slaytın devamında (ekrandan, 01:41:23) Student, Class, Room, Day ve Time arasında beşli bir enrolls-in bağıntısı var ve bütün eleman sayıları soru işaretiyle bırakılmış. Bu, üniversite veritabanı şemasının kavramsal tasarımıyla ilgili bir kısımdır. Eleman sayıları ifadeden yola çıkarak, diğer varlıklardan birer numune alınarak belirlenir:

- Class tarafı: Bir öğrenci bir günde, o günün bir saatinde, bir odada birden çok ders alabilir mi? Alamaz: aynı odada aynı anda birden çok ders olmaz, öğrenci de aynı anda iki derse kaydolamaz (çakışma). Bu yüzden Class tarafı 1'dir.
- Day tarafı: Bir öğrenci aynı derse aynı sınıfta, aynı saatte, farklı günlerde girebilir mi? Evet: veritabanı dersi örneğin pazartesi ve cuma aynı sınıfta saat 9'da başlayabilir. Bu yüzden Day tarafı N'dir.

Diğer soru işaretleri öğrencilere bırakıldı (çözüm için Örnek Sorular bölümüne bakın).

## 11. EER: Genelleme ve Alt Varlıklar

Bazı küçük dünyalar yalnız ER ile tam ifade edilemez ya da eksik kalır. Bu yüzden genişletilmiş ER (Extended ER, EER) ek malzemeler kullanır: genelleme ve "IS A" (ait olma) bağıntıları. Süper varlık (superclass, supertype) ve alt varlık (subtype) kavramları nesne yönelimli programlamadaki kavramlardan çok farklı değildir ama dikkat edilmesi gereken bazı noktalar vardır.

Slayt 20 "EER-Genelleme («IS A», «Ait olma» bağıntısı)" (ekrandan, 01:46:23):

- Katılım kısıtlaması: Zorunlu, Seçimli.
- Ayrıklık kısıtlaması: OR, AND.
- 4 farklı kısıtlama tanımlanabilir, ihtiyaca göre kullanılabilir.
- Supertype varlık nitelikleri/anahtarı, subtype varlıklarında geçerlidir.

### 11.1 Kısıtlamalar

Süper varlığın bütün elemanları mutlaka bir alt gruba dahilse bu zorunlu (total) katılımdır: bütün gemiler ya yolcu gemisi ya yük gemisidir. Bazı gemiler bu kategorilere girmiyorsa katılım kısmi (seçimli) olur. Bir eleman birden çok alt varlıkta bulunabiliyorsa bu OR ile (overlap), bulunamıyorsa AND ile (disjoint) ifade edilir. Böylece total-OR, total-AND, kısmi-OR ve kısmi-AND olmak üzere dört kısıtlama ortaya çıkar.

### 11.2 Gemi örneği

Slayttaki ER (disjoint, total) örneği:

```text
GEMİ (gNo [anahtar], ağırlık)
   |  (çift çizgi: total)
  (d)
   |-- YOLCUGEMİSİ (yolcuSayısı, kaliteSınıfı)
   |-- YÜKGEMİSİ (yükKapasitesi, yükTürü)
```

Süper varlık alt varlıkların "ebeveyni" gibidir; süper varlıktaki bütün nitelikler otomatik olarak alt varlıkların da niteliğidir. Yolcu gemisinin de gemi numarası (birincil anahtar) ve ağırlığı vardır, yük gemisinin de. Ama yolcu gemisinin yük kapasitesi ve yük türü yoktur; alt varlıklara yazılan nitelikler yalnız o alt varlık için geçerlidir.

Bu gösterim kullanılmasaydı bütün nitelikler GEMİ'ye yazılır, belki bir "gemi tipi" niteliği eklenirdi. O zaman yolcu gemileri için yük nitelikleri, yük gemileri için yolcu nitelikleri NULL olurdu. NULL belirsiz bir durumdur (veri girilemiyor ya da bilinmiyor); tabloda NULL görmek istenmez. Alt varlıklı tasarım bu NULL'ları ortadan kaldırdığı için daha isabetlidir.

### 11.3 Diğer örnekler

- ER (disjoint, partial): Employee süper varlığı; Manager, Engineer, Technician, Secretary alt varlıkları. Bazı çalışanlar bu gruplardan hiçbirine dahil değildir (kısmi). Disjoint olduğu için bir çalışan dahil olacaksa yalnız birine dahil olur; hem mühendis hem teknisyen olamaz.
- ER (overlap, total): Individual süper varlığı; Employee ve Customer alt varlıkları. Bütün kişiler bu ikisinden birine dahil olmak zorundadır (total) ve ikisine birden de dahil olabilir (overlap, şekilde "o").

Slaytta alt küme ilişkisini gösteren yay biçimli işaretin çok şart olmadığını hoca belirtti.

## 12. Aggregation

Hoca aggregation'ı biraz daha ince ve zor bir kavram olarak tanıttı. Slayt 21 (ekrandan, 01:51:23):

- Used when we have to model a relationship involving (entity sets and) a relationship set.
- Aggregation allows us to treat a relationship set as an entity set for purposes of participation in (other) relationships.

Şekil:

```text
Employees (ssn [anahtar], name, lot)
   | N
 Monitors (until)
   | N
 [ Projects (pid [anahtar], started_on, pbudget) N --Sponsors (since)-- N Departments (did [anahtar], dname, budget) ]
   (köşeli parantez: kesikli çerçeve, aggregation)
```

Departmanlar projelere sponsor olur, yani belli bir tarihten (since) beri onlara destek verir; bir departmanın birden çok projesi, bir projenin birden çok sponsor departmanı olabilir (N-N). Bu sponsorluğu izleyecek (monitor) bir çalışan atanır. Burada Sponsors bağıntısı bir bütün olarak, Employees ile Monitors bağıntısına girer.

Slayttaki açıklama:

- Aggregation vs. ternary relationship: Here, aggregation is best. Since «monitors» is a distinct relationship, with a descriptive attribute. Otherwise, if we had designed with ternary, «since» attribute will repeat for every «monitoring».
- If we do not need to store «until», then ternary may be used!

Monitors kendi niteliği (until) olan ayrı bir bağıntıdır: bir çalışan bu sponsorluğu belli bir tarihe kadar izler, sonra başka bir çalışan izleyebilir. Üçlü bağıntıyla tasarlansaydı since niteliği her izleme için tekrarlanır, since ve until kavramları çakışırdı. until olmasaydı aggregation'a gerek kalmazdı. Bu yapının gerektiğini anlamak için küçük dünya tarifini dikkatle okumak gerekir.

## 13. UML ile Modelleme

UML'yi yazılım mühendisliği derslerinden tanıyor olabilirsiniz; veritabanı tasarımında da benzer notasyonlar kullanılır. Slayt 22 "UML ile modelleme" (ekrandan, 01:56:23):

| Kavram | UML gösterimi |
|---|---|
| Sınıf | Üç bölmeli kutu: Class Name / attribute1, attribute2 / operation1(), operation2(). Örnek: Car (vin, mileage / accelerate(), brake()) |
| Association | Car ---- Driver (düz çizgi) |
| Generalization | Sedan ---▷ Car (içi boş üçgen ok) |
| Aggregation (Part_of) | Car Pool ◇---- Car (içi boş baklava) |
| Composition | Car ◆---- Frame (içi dolu baklava) |
| Reflexive association | Employee: manager 1 / managed * |
| Binary association | Department * ---- 1 Division |
| Ternary association | Skill, Project, Employee bir baklavaya bağlı; skill used, assignment rolleri |
| one-to-one | Department 1 ---- 1 Employee (manager) |
| one-to-many | Department 1 ---- * Employee |
| many-to-many | Employee * ---- * Project, WorkAssignment (task-assignment, start-date) kesikli çizgiyle bağlı |
| Existence: optional | Department 0..1 ---- 1 Employee (manager) |
| Existence: mandatory | Office 1 ---- 0..* Employee (occupant) |

İkili bağıntıda baklava çizilmez, üçlüde bir baklava (dörtgen) kullanılır. Eleman sayıları, bağıntının niteliği ve diğer bilgiler ER'dekiyle aynı yöndedir. Fark var olma durumundadır: ER'de var olma bağımlılığı çizgiyle gösterilirken UML'de çoklukla birlikte ifade edilir.

Department-manager örneğinde bir departmanın bir yöneticisi vardır ve olmak zorundadır; bu yüzden çalışan tarafında 0..1 değil 1 yazılır. Departman tarafında 0..1 yazılır: bir çalışan en fazla bir departmanın yöneticisidir, hiç yönetici olmayabilir de. Office örneğinde 0..* bir ofiste çok sayıda çalışan olabileceğini, boş da kalabileceğini (bağıntıda yer almayabileceğini) gösterir; bu taraf isteğe bağlıdır (optional). Ofis tarafındaki 1 ise her çalışanın mutlaka bir ofisi olduğunu söyler.

Hoca, UML'nin ER diyagramına oldukça yakın olduğunu, eleman sayıları, üçlü ve recursive bağıntıların hemen hemen aynı olduğunu, farkın var olma gösteriminde ve aggregation kavramında olduğunu özetledi.

### 13.1 Generalization, composition ve aggregation

UML'de genelleme aşağıdan yukarı okununca generalization, yukarıdan aşağı okununca specialization anlamı taşır; disjoint gibi kısıtlar da yanına yazılabilir.

Composition'da parçalar tek başına bulunmaz ve anlam taşımaz; hepsi birlikte bir anlam ifade eder. Car ve Frame (pencere) örneğinde her pencere bir arabaya aittir ve arabayla birlikte anlam kazanır. Pencere bir zayıf varlık gibi düşünülebilir: pencereler bir araba içinde ayırt edilir ama farklı arabalarda aynı pencere numarası olabilir. UML'de ayrıca bir zayıf varlık notasyonu yoktur; zayıf varlık aslında composition gibidir.

Aggregation'da ise parçalar kendi başına anlam ifade eder. Course, Teacher ve Textbook örneğinde ders kitabı derse ya da hocaya bağımlı değildir. Buna karşılık bir yazılım ürünü içindeki program ya da elektronik doküman ürünle birlikte anlam taşır; bu composition'dır.

> **Hocanın vurgusu:** Hoca, UML'deki aggregation ile ER'deki aggregation'ın (12. bölüm) farklı kavramlar olduğunu vurguladı; aynı adı taşımaları karıştırılmamalıdır.

UML'de birincil anahtar "BA" yazılarak gösterilir.

### 13.2 UML örnekleri

Slayt 25 "UML ile Varlık ve Bağıntı Örnekleri" (ekrandan, 02:01:23):

- ARABA: Kayıt No BA, Plaka No, Marka, Model, Sene, Renk.
- ÖĞRENCİ (#, adı, soyadı, cns, doğumtar) 0..* - aldığı - 0..* DERS (#, adı, kredisi, dili). Bağıntının niteliği (notu) kesikli çizgiyle bağlanan kutuda yazılır.
- A 1..* - AB - 0..* B.
- BÖLÜM 1..1 - okuyan - 0..* ÖĞRENCİ.

ÖĞRENCİ-DERS örneğindeki sıfırlar var olma durumunu gösterir: bir öğrenci hiç ders almamış olabilir, bir dersi henüz hiçbir öğrenci seçmemiş olabilir.

Hoca sözlü olarak başka örneklerden de söz etti: erkek-kadın "evli" bağıntısı bire birdir ve evli olmayabilecekleri için iki tarafta da sıfır vardır (kısmi). UML'de eleman sayıları daha ayrıntılı verilebilir: genel bir "N" yerine bir tarafın en fazla belirli sayıda elemanla eşleşebileceği yazılabilir. <!-- BELİRSİZ: Hoca bir örnekte üst sınırları 50 ve 6 olarak okudu; bu örneğin slaytı karelerde görünmüyor. -->

Slayt 27 "Örnek (UML)" (ekrandan, 02:06:23):

- LİSE (liseNo BA, liseAdı, sehir) 1..1 - okuyan - 0..* ÖĞRENCİ (öğrNO AN, adı, soyadı).
- KİŞİ (kişiNo BA, adı, soyadı) 0..* - katılır - 0..* KURS (kNO BA, kAdı, kTür); bağıntı nitelikleri: yıl, başarı.

Lise-öğrenci örneği, ER'de zayıf varlık olarak çizilen modelin UML karşılığıdır. Öğrenci numarası ayırt edici nitelik (AN), lise güçlü varlıktır; bu ilişki için aslında composition işareti kullanılmalıdır, slaytta eksik kalmıştır. Aynı durum daha önceki fatura örneği için de geçerlidir: sipariş formu ile satır numarası (invoice number + line number) composition içinde zayıf varlık olarak ifade edilir.

Kişi-kurs örneği için sorulan soru Örnek Sorular bölümünde çözüldü.

Slayttaki diğer örneklerde gemi alt tiplerinin UML versiyonu ve personelin akademik ve idari personel gibi alt tiplere ayrıldığı daha kapsamlı bir genelleme örneği var. UML'de zorunlu ve disjoint kısıtları ayrı bir notasyon yerine yazıyla belirtilir: bir personel mutlaka iki gruptan birine girer ve ikisine birden giremez; akademik personel de üç alt gruptan birine girmek zorundadır. <!-- BELİRSİZ: Personel örneğinin kalan ayrıntıları altyazıda net değil ve karelerde görünmüyor. -->

Son örnek bina, oda, personel ve bölüm arasındaki bir composition örneğidir. Oda numarası farklı binalarda aynı olabileceği için oda zayıf varlıktır ve ayırt edici niteliği vardır; güçlü varlığı binadır. Bir personel bir oda kullanır, bir odayı birden çok personel kullanabilir; personelin bağlı olduğu bölümler de vardır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:16:23): Bağıntılardaki anahtar kurallarına göre önceki örneklerdeki bağıntıların anahtarlarını belirleyiniz.

> **Çözüm (derste verildi):** Department - is-managed-by - Employee (1-1): departman numarası ya da çalışan numarası. Department - has - Employee (1-N): N tarafındaki çalışanın anahtarı. Employee - works-on - Project (N-N): çalışan ve proje anahtarlarının birleşimi. Gerekçeler 9. bölümdeki örnek kümelerde.

**Soru 2** (ekrandan, 01:26:23 ve 01:31:23): Aşağıdaki üçlü bağıntıların anahtarları nedir? (a) Technician-Project-Notebook (1-1-1), (b) Project (1)-Employee (N)-Location (1), (c) Manager (1)-Engineer (N)-Project (P), (d) Employee (M)-Project (N)-Skill (P).

> **Çözüm (derste verildi):** (a) Herhangi iki varlığın anahtarı. (b) Employee-Location ya da Employee-Project. (c) Engineer-Project. (d) Üç varlığın anahtarlarının birleşimi.

**Soru 3** (ekrandan, 01:36:23): "Which one conveys more information?" SUPPLIER-PART-PROJECT üçlü SUPPLY bağıntısı mı, yoksa SUPPLIES, CAN_SUPPLY ve USES ikili bağıntıları mı?

> **Çözüm (derste verildi):** Üçlü bağıntı daha fazla bilgi taşır: $(s,j,p) \neq (s,p)\ (j,p)\ (s,j)$. İkili bağıntılardan "bu tedarikçi bu parçayı bu projeye sağladı" sonucu kesin olarak çıkarılamaz.

**Soru 4** (ekrandan, 01:36:23): "One more step further: If we do not want to use weak entity type, how to design?"

> **Çözüm (derste verildi):** SUPPLY güçlü bir varlık yapılır ve ona kendi birincil anahtarı verilir. Hoca, bunun ek bir birincil anahtar takibi yükü getirdiğini, kullanılabiliyorsa zayıf varlığın daha iyi bir tasarım olduğunu belirtti.

**Soru 5** (ekrandan, 01:41:23): Student, Class, Room, Day ve Time arasındaki enrolls-in bağıntısında soru işaretli eleman sayılarını belirleyiniz.

> **Çözüm (derste kısmen verildi):** Class tarafı 1: bir öğrenci aynı gün, aynı saatte, aynı odada birden çok ders alamaz. Day tarafı N: bir öğrenci aynı derse aynı sınıfta, aynı saatte farklı günlerde girebilir.

> **Çözüm (derste verilmedi):** Kalan taraflar küçük dünyanın varsayımlarına bağlıdır. Yaygın bir varsayımla: Student tarafı N (belirli bir gün ve saatte belirli bir odadaki bir derste birçok öğrenci vardır). Room tarafı 1 (bir öğrenci bir derse belirli bir gün ve saatte tek bir odada girer). Time tarafı, bir dersin aynı gün aynı odada birden çok saat dilimine yayılmasına izin verilirse N, verilmezse 1 olur.

**Soru 6** (ekrandan, 02:06:23): Aşağıdaki örnekte bir kişi aynı kursu farklı yıllarda tekrar alabiliyorsa bağıntı kümesinin anahtarı ne olur? (KİŞİ (kişiNo BA, adı, soyadı) 0..* - katılır - 0..* KURS (kNO BA, kAdı, kTür); bağıntı nitelikleri yıl, başarı.)

> **Çözüm (derste verildi):** Kişi kursu yalnız bir kez alabiliyorsa N-N bağıntının anahtarı iki tarafın anahtarlarıdır: kişiNo + kNO. Aynı kurs farklı yıllarda tekrar alınabiliyorsa (örneğin 2015'te ve 2020'de) kişiNo + kNO ikilisi tekrar eder; bu yüzden yıl da anahtara girer: kişiNo + kNO + yıl. N-N ve N-N-N bağıntılarda böyle bir durum varsa iki varlığın birincil anahtarları yeterli olmaz.

## Dersin Toparlaması

Ders, veritabanı şemalarının nereden geldiği sorusuyla başladı: küçük dünya incelenir, gereksinimler toplanır, ER ile kavramsal şema çizilir, bu şema ilişkisel tablolara dönüştürülür ve fiziksel olarak ayarlanır. ER modelinin yapı taşları olan varlıklar, nitelikler (birleşik, çok değerli, türetilmiş, anahtar) ve bağıntılar, bağıntıların derecesi, eleman sayıları, rolleri ve katılım (var olma bağımlılığı) durumları küçük dünyadan çıkarılarak belirlendi. Super anahtar, aday anahtar ve birincil anahtar tanımlandı. Bütün nitelikleriyle bile anahtarı olmayan kümeler için zayıf varlık kavramı verildi.

İkinci saatte bağıntı kümelerinin anahtarları örnek kümelerle gerekçelendirildi ve üçlü bağıntılara genişletildi. Üçlü bağıntının üç ikili bağıntıyla aynı bilgiyi taşımadığı, gerekirse zayıf varlıkla ifade edilebileceği gösterildi. EER'de genelleme ve kısıtlamaları, aggregation ve UML gösterimi işlendi. Hoca, bu derste temel kavramların öğrenildiğini, sonraki derste bunların daha kapsamlı küçük dünya örneklerinde kullanılacağını, ardından tasarımın ilişkisel model tablolarına dönüştürüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
