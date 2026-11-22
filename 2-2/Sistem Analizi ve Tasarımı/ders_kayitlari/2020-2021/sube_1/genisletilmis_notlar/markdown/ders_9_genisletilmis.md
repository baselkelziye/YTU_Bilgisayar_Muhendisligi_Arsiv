# Ders 9 Genişletilmiş Notu: Veri Tabanı Tasarımı (ERD ve Sınıf Diyagramı), Sistem Tasarımı, Kodlama ve Test

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin planı
- 2. Veri varlıkları ve nesneler
- 3. ER diyagramı: kardinalite ve zorunluluk
- 4. Özellikler ve anahtarlar
- 5. Sınıf diyagramı
- 6. Çoka çok ilişki ve ilişki tablosu
- 7. Sistem tasarımı ve ön tasarım
- 8. Yapı diyagramı
- 9. Ayrıntılı tasarım
- 10. Kodlama
- 11. Yazılım kalitesi ve test
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin planı

Bu derste tasarım konusunun tamamı gözden geçirildi. İlk yarıda veri tabanı tasarımı ve nesneye yönelik tasarımda kullanılan diyagramlar, ikinci yarıda sistem tasarımının aşamaları, kodlama, yazılım kalitesi ve test basamakları ele alındı. Proje yönetimi konusunda daha önce zaman ve kaynak fizibilitesi işlenmişti; kalite ve test kavramlarına bu derste giriş yapıldı.

İlk yarıdaki slaytlar Satzinger, Jackson ve Burd'ün "Systems Analysis and Design in a Changing World" (2. baskı) kitabının 5. bölüm slaytlarıdır (slayt altbilgisinden, ekrandan, 00:10:00). Bu slaytlar daha önceki bir derste de kullanılmıştı; hoca projelerden ve sınavlardan önce konuları sağlamlaştırmak için yeniden üzerinden geçtiğini söyledi. İkinci yarıda Türkçe hazırlanmış sistem tasarımı ve kodlama/test sunumları kullanıldı.

## 2. Veri varlıkları ve nesneler

### 2.1 Geleneksel yaklaşım: varlık ilişki diyagramı

Bir bilgi sistemi geliştirirken önce hangi verinin tutulacağını ve veri parçaları arasında nasıl bir ilişki olduğunu anlamak gerekir. İlişkisel veri tabanı geliştirilmeden önce varlık ilişki diyagramı (Entity Relationship Diagram, ERD) çizilir ve veri tabanı bu diyagramla modellenir. Bu modelleme analiz aşamasında başlar, tasarım aşamasında daha ayrıntılı hale gelir ve son halini alır.

Geleneksel bilgi sistemi yaklaşımında verinin nasıl saklanacağı ERD ile tanımlanır. Uygulamada hakkında bilgi tutulacak varlıklar (entity) belirlenir ve bu varlıklar arasındaki ilişkiler gösterilir.

### 2.2 Nesneye yönelik yaklaşım

Nesneye yönelik yaklaşımda bilginin nasıl saklandığına ek olarak nesnelerin davranışları da tanımlanır. ERD'de varlıkların yalnız özellikleri tanımlanırken, nesnelerde önce sınıf tanımlanır: hakkında bilgi tutulacak şeyin tipi nedir, sınıf-nesne-metot hiyerarşisinde bu nesne hangi sınıfa aittir, hangi özellikleri vardır ve hangi davranışları (metotları) gerçekleştirir. Analiz sırasında uygulamada hangi nesnelerin bulunduğu tanımlanır.

Derste her iki yaklaşım başlangıç düzeyinde verilir; dönem projelerinde hangisi istenirse o kullanılabilir.

### 2.3 Veri varlıkları ile nesnelerin karşılaştırılması

Hoca bu karşılaştırmanın akılda yer etmesi gerektiği için konuyu yeniden ele aldığını söyledi. Ekrandaki şekil iki yapıyı yan yana koyar (Figure 5-21, ekrandan, 00:10:00):

- **Veri varlıkları işlemlerden ayrıdır (Data entities are separate from processes):** girdi (input) bir işlem bloğuna girer; blokta process 1, process 2, process 3 sırayla tanımlanmıştır; işlem bloğu ile veri tabanı silindiri olarak çizilen "Data entity" arasında çift yönlü ok vardır; işlenmiş sonuç çıktı (output) olarak gönderilir. Sürekli saklanan veri veri tabanından alınır, kullanılır ve geri yerleştirilir.
- **Nesneler veriyi ve veriyi işleyen metotları tek birimde toplar (Objects encapsulate data and the methods that process the data into one unit):** nesneye bir mesaj (message) gelir; nesnenin içinde "nesneye ait veri" (data belonging to the object) ve "veriyi işleyen metotlar" (methods that process the data) bulunur; sonuçta nesneden yine bir mesaj çıkar.

Yani geleneksel yaklaşımda varlıklarla işlemler arasındaki ilişki dışarıdan kurulurken, nesneye yönelik yaklaşımda nesne tanımının içinde nesnenin sınıfı, veri özellikleri, bu veriyi işleyen metotlar ve bunları tetikleyen mesajlar birlikte görülür.

## 3. ER diyagramı: kardinalite ve zorunluluk

### 3.1 Basit ERD: müşteri ve sipariş

Ekrandaki basit ERD'de iki varlık vardır: Customer (müşteri) ve Order (sipariş) (Figure 5-22, ekrandan, 00:15:00). Aralarındaki çizginin müşteri ucunda tek dik çizgi, sipariş ucunda bir daire ve kaz ayağı (çatal) bulunur. Slayttaki açıklamalar şöyledir:

- "a Customer can place zero or more Orders": bir müşteri sıfır ya da daha çok sipariş verebilir.
- "an Order must be placed by exactly one Customer": bir sipariş tam olarak bir müşteri tarafından verilmelidir.

Hoca ilişkiyi iki yönden okudu. Müşteri siteye kayıt yaptırmış ama henüz hiç sipariş vermemiş olabilir; bu yüzden sipariş ucunda sıfır vardır. Çok kez sipariş vermiş de olabilir; bu da çatalla gösterilir. Tersten okunduğunda bir sipariş yalnız bir müşteriye karşılık gelir: bir siparişin iki sahibi olamaz, sahipsiz de olamaz. Bu "bir ve mutlak bir" demektir, yani en az bir, en çok bir müşteri.

Bu kitapta kullanılan gösterim, iki varlık arasındaki ilişkinin hem sayısal durumunu hem de zorunlu/seçimlik durumunu daha iyi gösterdiği için tercih edilmiştir.

### 3.2 Kardinalite sembolleri

Hoca kardinalite (cardinality) sembollerini gösteren slaytın üzerinden geçti. <!-- BELİRSİZ: kardinalite sembolleri slaytının karesi yok; aşağıdaki liste altyazıdan kuruldu -->

- **Sıfır ya da daha çok (zero or more):** seçimlik (optional) ilişki; ilişki hiç olmayabilir, çok sayıda da olabilir. Daire ve çatalla gösterilir.
- **Bir ya da daha çok (one or more):** zorunlu (mandatory) ilişki; en az bir tane mutlaka vardır. Dik çizgi ve çatalla gösterilir.
- **Bir ve yalnız bir (one and only one):** tam olarak bir, zorunlu ilişki. İki dik çizgiyle ya da tek çizgiyle gösterilir.
- **Sıfır ya da bir (zero or one):** seçimlik ilişki; karşı taraftaki varlıkla hiç ilişki olmayabilir, olursa da bir tane olur.

Kural basittir: ilişki sıfırdan başlıyorsa seçimliktir, birden başlıyorsa zorunludur. Çatal "çok" anlamına gelir.

### 3.3 Chen gösterimi

Başka derslerde, örneğin veri tabanı dersinde, Chen gösterimi kullanılır. Bu gösterimde iki varlık arasındaki birleşim çizgisinin ortasına bir eşkenar dörtgen konur ve içine ilişkinin fiili yazılır. Varlığın özellikleri de varlık dikdörtgeninden çıkan çizgilerle elipslere yazılır. Örneğin bir öğrenci varlığı için numara, ad, soyad, bölüm gibi özellikler ayrı elipslerde gösterilir.

Hoca, eğitim aşamasında bu gösterimin kullanışlı olduğunu, ama profesyonel hayatta bir varlığın o kadar çok özelliği olacağını ki hepsini elipslerle göstermenin mümkün olmadığını söyledi; bu yüzden başka bir yol izlenir.

## 4. Özellikler ve anahtarlar

### 4.1 Özellikleri gösterilmiş genişletilmiş ERD

Kitaptaki gösterimde özellikler varlık dikdörtgeninin içine yazılır (Figure 5-24, ekrandan, 00:20:00):

| Varlık | Özellikler |
|---|---|
| Customer | Cust number*, Name, Bill address, Home phone, Office phone |
| Order | Order ID*, Order date, Amount |
| Order Item | Item ID*, Quantity, Price |

Şekildeki not "*Indicates the identifier or key": yıldız tanımlayıcıyı ya da anahtarı gösterir.

İlişkiler:

- Customer — Order: müşteri ucunda tek çizgi, sipariş ucunda daire ve çatal. Bire çok ilişkidir ama zorunlu değildir; müşteri hiç sipariş vermemiş olabilir.
- Order — Order Item: sipariş ucunda tek çizgi, kalem ucunda dik çizgi ve çatal. Bir siparişin en az bir, en çok çok sayıda kalemi vardır; bir kalem de bir ve mutlak bir siparişle bağlantılıdır.

Sipariş ve sipariş kalemi işletmecilikte kullanılan terimlerdir. Hoca bunu market alışverişine benzetti: kasada ödeme yaptığınızda kaç parça mal aldıysanız her biri için bir kalem oluşur; her kalemin ürün numarası (kimlik numarası), miktarı ve fiyatı vardır. Kasadan geçmiş bir alışverişin mutlaka en az bir kalemi olur, ama çok daha fazlası da olabilir.

### 4.2 Birincil anahtar

Varlık tanımlayıcıları anahtarlardır: Customer'da müşteri numarası, Order'da sipariş numarası (Order ID), Order Item'da parça numarası (Item ID). Hepsi birer birincil anahtardır (primary key). Bu konu veri tabanı dersinde daha ayrıntılı görülecektir; burada bir giriş yapılmıştır.

Gerçekleme aşamasında her varlık bir veri tabanı tablosu olur ve her tablo için bir birincil anahtar (esas anahtar) tanımlanır. Tablodaki bir satıra birincil anahtar üzerinden, o kolona göre indekslenerek erişilir: müşteriye müşteri numarasıyla, siparişe sipariş numarasıyla, sipariş kalemine parça numarasıyla ulaşılır.

> **Hocanın vurgusu:** Birincil anahtarın iki özelliği vardır. Biricik (unique) olmalıdır, yani her satır için farklı ve tek olmalıdır. Boş olmamalıdır (not null); her müşterinin bir müşteri numarası, her siparişin bir sipariş numarası olmalıdır.

Birincil anahtar bazen birkaç alanın birleşimiyle biricik yapılabilir. Hoca, uygulamada müşteri telefonunun (cep telefonu) da tanımlayıcı olarak kullanıldığını, alışverişte hemen telefon numarasının sorulmasını örnek verdi.

### 4.3 Birden fazla aday alan olduğunda seçim

Hoca öğrencilerin sorabileceği bir soruyu kendisi açtı: anahtar özelliği taşıyabilecek birden fazla kolon olabilir. Öğrenci bilgi sisteminde her öğrencinin bir öğrenci numarası vardır; ayrıca kimlik numarası vardır (yabancı öğrencilerde bunun yerine pasaport numarası gelir). İkisi de boş olmayan ve her kişi için farklı olma özelliğine uygundur. O zaman hangisi birincil anahtar olacaktır?

Bu karara analiz sırasında varılır ve tasarım ona göre oluşturulur. Belirleyici ölçütler: alanın tipi (sayısal ya da karakter), daha hızlı erişime imkan tanıması ve kullanıcılar tarafından daha yaygın ve kolay kullanılması. Öğrenciler için öğrenci numarası kimlik numarasından daha kolaydır. Birincil anahtardaki değerle kayda ulaşılır ve veri tabanında tablo buna göre indekslenir.

> **Ek bilgi (derste anlatılmadı):** Anahtar olabilecek her alana aday anahtar (candidate key) denir. Aday anahtarlardan seçilen birincil anahtar olur; seçilmeyenler alternatif ya da ikincil anahtar olarak kalabilir. Birden fazla alanın birleşiminden oluşan anahtara birleşik anahtar (composite key) denir.

### 4.4 Örnek veriyle kardinalite

ERD'deki yapının gerçek veride nasıl göründüğü örnek kayıtlarla gösterildi. <!-- BELİRSİZ: örnek veri slaytının karesi yok; kalem adları altyazıdan alındı --> Solda üç müşteri vardır; müşteriler siparişlerle, siparişler de hangi tarihte verildikleri ve hangi kalemleri içerdikleriyle ilişkilidir:

- Birinci müşteri iki sipariş vermiştir; birinde bir şort ve bir kemer gibi kalemler, ikincisinde başka ürünler vardır. Bu, ilişkinin "çok" ucuna uyar.
- İkinci müşteri üye olmuş ama henüz hiç sipariş vermemiştir. Bu, "sıfır" ucuna uyar.
- Üçüncü müşteri bir kez sipariş vermiş ve bu siparişte üç ürün almıştır.

## 5. Sınıf diyagramı

### 5.1 Sınıf diyagramı ERD'den neyi fazla gösterir?

Sınıf diyagramı yalnız veri varlıklarını değil, nesneleri ve sınıfları gösterir. Ayrıca:

- Genelleştirme/özelleştirme (generalization/specialization) hiyerarşilerini gösterir. Genel üst sınıflar (superclass) ve onlardan türeyen alt sınıflar (subclass) görülür. Üst sınıfın karakteristiklerinin alt sınıflarca nasıl paylaşılacağını kalıtım (inheritance) belirler.
- Bütün-parça (aggregation, whole-part) hiyerarşisini gösterir: bir nesnenin hangi parçalardan oluştuğu tanımlanır.

### 5.2 Genelleştirme/özelleştirme: motorlu araçlar

Ekrandaki hiyerarşi (Figure 5-29, ekrandan, 00:30:00) üçgen uçlu kalıtım oklarıyla çizilmiştir:

```text
MotorVehicle
├── Truck
├── Car
│   ├── SportsCar
│   ├── Sedan
│   └── SportUtility
└── Tractor
```

Hoca bunun klişe bir örnek olduğunu söyledi. Kamyon, araba ve traktör genelleştirilerek "motorlu araç" denir. Araba da daha da özelleştirilebilir: spor araba, sedan gibi tipler. Motorlu araçların genel özellikleri otomatik olarak kamyonda, arabada ve traktörde de bulunur; aynı şekilde arabanın bütün özellikleri sedanda ve spor arabada da vardır.

### 5.3 Bütün-parça ilişkisi (aggregation)

Bütün-parça ilişkisinde bir nesneyi oluşturan diğer nesneler birleşerek bir bütün oluşturur. Kitaptaki örnekte bilgisayar sınıfı bütündür; işlemci, ana bellek, klavye, disk belleği ve monitör parçalardır. Parçalar bilgisayara, bütün tarafında eşkenar dörtgen bulunan çizgilerle bağlanır; eşkenar dörtgen bu bağlantının bir bütün-parça ilişkisi olduğunu gösterir. <!-- BELİRSİZ: aggregation slaytının (Figure 5-31) karesi yok; parça listesi altyazıdan alındı -->

### 5.4 Sınıf sembolü

Sınıf sembolü üç bölmelidir. En üstte sınıfın adı (ör. Customer), ortada sınıfın özellikleri (ad, adres, telefon gibi), en altta sınıfa uygulanacak metotlar, yani sınıfın ne yapacağını ve hangi işleri gerçekleştireceğini belirten işlemler yer alır. Hoca bunların nesneye yönelik programlama dersinden bilindiğini hatırlattı.

### 5.5 Banka hesap sistemi sınıf diyagramı

Ekrandaki diyagram (Figure 5-33, ekrandan, 00:35:00) metotları da içerdiği için bir tasarım sınıf diyagramıdır:

| Sınıf | Özellikler | Metotlar |
|---|---|---|
| Customer | name, address, phone | (yok) |
| Account | accountNumber, balance, dateOpened | makeDeposit, makeWithdrawal |
| SavingsAccount (Account'tan türer) | interestRate | calculateInterest |
| CheckingAccount (Account'tan türer) | checkStyle, minimumBalance | (yok) |

İlişki: Customer `1` — `0..*` Account. Siparişte olduğu gibi, bir kişinin bankada müşteri tanımı ve müşteri numarası vardır, ama hiç hesap açtırmamış olabilir (başka bir işlem için bankaya gelmiş olabilir); birden fazla hesabı da olabilir.

Account'ta hesap numarası, hesabın açıldığı tarih ve şu anki bakiye tutulur; para yatırma ve para çekme işlemleri tanımlıdır. Bu temel özellikler kalıtımla alt sınıflara geçer: SavingsAccount'ta (birikim, vadeli hesap) da accountNumber, balance, dateOpened vardır; buna ek olarak faiz oranı (interestRate) ve faiz hesaplama metodu (calculateInterest) bulunur. CheckingAccount'ta (vadesiz hesap) ek olarak çek tipi (checkStyle) ve hesabın altına düşmemesi gereken en düşük bakiye (minimumBalance) bulunur.

> **Ek bilgi (derste anlatılmadı):** Slaytta Account adı italik yazılmıştır. UML'de italik sınıf adı soyut sınıfı (abstract class) gösterir; böyle bir sınıftan doğrudan nesne üretilmez, yalnız alt sınıfları üzerinden nesne oluşturulur.

### 5.6 Ders kaydı sınıf diyagramı ve ilişki sınıfı

Ekrandaki diyagram (Enrollment Class Diagram with Association Class, ekrandan, 00:40:00):

| Sınıf | Özellikler | Metotlar |
|---|---|---|
| Course | courseNumber, title, creditHours | addCourse |
| CourseSection | sectionNumber, startTime, roomNumber | openSection, closeSection |
| Student | studentID, name, major | admitStudent, recordDegree |
| CourseEnrollment (ilişki sınıfı) | grade | postGrade |

İlişkiler:

- Course `1` — `0..*` CourseSection.
- CourseSection `0..*` — `0..*` Student.
- CourseEnrollment, CourseSection ile Student arasındaki çizgiye kesikli bir çizgiyle bağlanır.

Öğrenci ders seçimi yapar ve seçtiği derse kayıt yaptırır. Kayıt, öğrenci ile ders şubesi arasındaki bağlantıdır: hangi derse kayıt yaptırdığı, o dersten hangi notu aldığı burada tutulur. Ders şubesinde şube numarası, başlangıç saati ve derslik bilgisi; öğrencide numara, ad ve bölüm bilgisi bulunur.

`0..*` gösterimi "sıfır, bir ya da çok" demektir; ERD'deki "sıfır ya da çok" ile aynı anlamı taşır. Hoca ilişkileri tek tek okudu:

- Bir ders, ders seçim listesine hiç alınmamış olabilir ya da çok sayıda şube için alınmış olabilir.
- Seçim listesindeki bir şubeyi hiç öğrenci almamış olabilir; o zaman şube kapatılır. Çok sayıda öğrenci almış da olabilir; o zaman ek şube açılabilir.
- Tersten bakıldığında bir öğrenci hiç ders seçmemiş de olabilir, çok sayıda ders seçmiş de olabilir.

## 6. Çoka çok ilişki ve ilişki tablosu

Sıfırları bir yana bırakıp yalnız sayısal yapıya bakıldığında, şube ile öğrenci arasındaki ilişki çoka çoktur: bir ders çok sayıda öğrenci tarafından alınır, bir öğrenci de çok sayıda ders alabilir. Hoca ERD örnekleri arasında çoka çok ilişkili bir örnek aradı, bulamadı; bu sınıf diyagramı örneğinin konuya uyduğunu söyledi.

Açılan dersler ile öğrenciler arasındaki çoka çok ilişki veri tabanında doğrudan gösterilemez. Gerçekleme sırasında araya bir tablo daha konur; bu bir varlık tablosu değil, ilişki tablosudur (relation table). Sınıf diyagramında da buna karşılık bir sınıf (CourseEnrollment) düşünülür.

Ders kayıt tablosunun yapısı:

- Birincil anahtar iki parçanın birleşimidir: ders numarası ve şube numarasını içeren ders/şube anahtarı ile öğrenci numarası (studentID).
- Özellik olarak öğrencinin bu dersten aldığı not (grade) tutulur. Ders listesinde görünen her öğrenci için öğretim üyesinin notu yazacağı bir yer olmalıdır; bu yer ilişki tablosudur.

Böylece ilişki tablosu, açılan derslerle öğrenciler arasındaki ilişkilendirmeyi ifade eden yerdir.

## 7. Sistem tasarımı ve ön tasarım

### 7.1 Sistem tasarımının tanımı

Aradan sonra Türkçe sistem tasarımı sunumuna geçildi. Slayttaki tanım (ekrandan, 01:10:00): "Belirlenmiş olan bir dizi gereksinimin, ana sistem içerisinde işlevsel bir öğe haline getirilmesi, başka bir deyimle, yazılım şekline dönüştürülmesidir. Sistem tasarımı ön tasarım ve ayrıntılı tasarım olarak iki aşama halinde gerçekleştirilmektedir."

Önce sistem analizi yapılır; analizde belirlenen gereksinimleri yazılım şekline dönüştürmek için yapılan işlerin bütününe sistem tasarımı denir. Az önce görülen veri tabanı tasarımı ayrıntılı tasarımın bir parçasıdır.

### 7.2 Ön (genel) tasarım

Ön tasarımda şu sorulara cevap aranır: uygulamanın alt parçaları nelerdir ve birbirleriyle ilişkileri nasıldır, amaç ve hedeflere nasıl ulaşılacaktır, sistem nasıl gerçekleştirilecektir, modüller nasıl belirlenecektir. Uygulama alt modüllere ayrılır, modüllerin ara birimlerle nasıl bir araya geleceğine ve hangi kısıtların bulunduğuna karar verilir. Sistemin altyapısı ve mimarisi de bu aşamada belirlenir. Sistem analizinde oluşturulan sistem gereksinimleri ön tasarıma girdi olarak alınır.

Ön tasarımın adımları daha önceki derslerde ayrıntılı işlenmişti; hoca yalnız hatırlattı:

- **Envanter:** var olan bilgisayar donanımının envanteri çıkarılır. Altyapıda fizibilitede belirlenen ürünler kullanılacaktır; ama önceki uygulamadan ya da şirket envanterinden kullanılabilecek ürün var mı, sorunlu olanlar tamir edilebilir mi, bunlar belirlenir.
- **İş yükü tahmini:** sistemin var olan ve planlanan iş yükleri nelerdir, donanım altyapısının kapasitesi bu iş yüküne yeterli midir, hesaplanır.
- **Yazılım değerlendirmesi:** isteklere uyan bir paket program var mı, istekleri yerine getirebilir mi, fiyatı nasıldır? Yazılımdan beklenenler performansla ilgilidir: işleri istenen şekilde yerine getiriyor mu, ekran çıktıları uygun mu, kapasitesi yeterli mi, hızlı cevap veriyor mu?
- **Satıcı seçimi:** hangi ürün alınacaksa hangi satıcıdan alınacağına donanım desteği, yazılım desteği, kurulum ve eğitim, bakım gibi faktörlere bakılarak karar verilir.
- **Elde etme türü:** ürün satın alma, kiralama ya da leasing yoluyla elde edilebilir. Hoca bunlara "satın alma türleri" yerine "elde etme türleri" demenin daha doğru olduğunu belirtti.
- **Sistem mimarisi:** yazılım anlamında esas yapılacak iş budur; programın ana yapısal öğeleri ve modülleri belirlenir. Modüller yapı diyagramıyla en iyi şekilde görülür.

## 8. Yapı diyagramı

### 8.1 Bordro programı örneği

Genel tasarım sırasında modül yapısını göstermek için yapı diyagramı (structure chart) çizilir. Hoca ders kitabından bir bordro (ücret hesaplama) programı örneği gösterdi (ekrandan, 01:20:00). Diyagramın modül hiyerarşisi:

```text
Payroll program  (altında yarım daire döngü oku)
├── Enter time cards
│   ├── Enter employee time card
│   ├── Read employee record
│   └── Validate time card
├── Calculate amounts
│   ├── Get employee pay rates
│   └── Calculate pay amounts
│       ├── Calculate base amount
│       ├── Calculate overtime amount
│       ├── Calculate taxes
│       └── Calculate other deductions
└── Output payroll
    ├── Update employee record
    ├── Write payroll transactions
    └── Update general ledger
```

Okların yanındaki küçük oklarla gösterilen veri akışlarından bazıları (ekrandan, 01:20:00):

- Payroll program ile Enter time cards arasında "Validated time card information"; Calculate amounts'a "Validated time card" gider, "Payroll amounts" döner; Output payroll'a "Employee information" ve "Payroll information" gider.
- Enter time cards altında "Time card", "Employee name", "Employee data" ve doğrulama sonucunu bildiren "Valid flag".
- Calculate amounts altında "Employee pay/tax rates", "Rates", "Payroll amounts".
- Calculate pay amounts altında "Job category", "Hours", "Base pay", "Overtime amount", "Taxes", "Dependents", "Deduction amount", "Deduction information".

Hoca diyagramı şöyle okudu:

- Ana modülün altındaki yarım daire ok, ana modülün her birim (her çalışan) için tekrar edildiğini, yani bir döngü içinde çalıştığını gösterir. Her kişi için zaman kartları girilir, okunur ve geçerli zaman kartı belirlenir.
- Aşağıya inildikçe her modülün alt modülleri görülür. Aynı düzeyde üç modül varsa soldan sağa doğru işlenme sırası görülür.
- Küçük oklar, alt modülün üst modüle hangi değeri göndereceğini ya da üst modülden hangi değeri alacağını, yani argümanları ve geri döndürülen değerleri gösterir.
- İçi boş daireli oklar veridir. İçi dolu daireli oklar kontrol akışıdır; evet/hayır gibi lojik bir değer döndürür. Hoca bu örnekte içi dolu ok bulunmadığını söyledi.

### 8.2 Koşullu modül: sipariş örneği

Başka bir örnekte, sipariş işleme yapı diyagramında, bir modülün çalışıp çalışmayacağı bir soruya bağlıdır. Müşteri bilgisi alınır; müşteri kaydı yoksa yeni müşteri kaydı yaratılır. Bu koşul eşkenar dörtgenle gösterilir. Hoca slaytta bir hata olduğunu, eşkenar dörtgenin iki modülün arasında olması gerektiğini belirtti. Ayrıca her sipariş için tekrarlanan bir döngü vardır ve sipariş kalemlerinin kaydedilip kaydedilmemesi de yine bir soruya bağlıdır. <!-- BELİRSİZ: sipariş yapı diyagramı slaytının karesi yok; modül adları ve eşkenar dörtgenin konumu kareden doğrulanamadı -->

### 8.3 Veri akış diyagramından yapı diyagramına

Veri akış diyagramı çizildikten sonra ona uygun bir yapı diyagramı oluşturulabilir. Ancak VAD'daki her işlemi modül yapmak zorunlu değildir. Tasarımda amaç, analizdeki gereksinimleri en iyi şekilde tasarlamaktır; bu yüzden modül yapısı işlem yapısından farklı olabilir ve buna tasarımcı karar verir.

### 8.4 Numaralı yapı diyagramı

Başka bir yapı diyagramında hiyerarşi numaralarla gösterilir. Örneğin envanter güncelleme ve raporlama programında envanter güncelleme bir modül, raporlama başka bir modüldür; envanter güncellemenin işlem girişi, doğrulama, düzeltme gibi alt modülleri 2.1, 2.2, 2.3, 2.4 diye numaralanır. <!-- BELİRSİZ: numaralı yapı diyagramı slaytının karesi yok -->

## 9. Ayrıntılı tasarım

### 9.1 Tanım ve kapsam

Slayttaki tanım (ekrandan, 01:15:00): "Ayrıntılı tasarımda; ön tasarım aşamasında oluşturulan modüller alt modüllere ayrılmakta ve ayrıntılı olarak tanımlanmaktadır. Dosyalar veya tablolar, ekran görüntüleri ve rapor biçimleri tasarlanmakta, programlar için ayrıntılı planlar düzenlenmektedir."

Ayrıntılı tasarımın başlıkları veri tabanı tasarımı, çıktı tasarımı, girdi tasarımı, program tasarımı ve ara birim tasarımıdır. Derste çıktı, girdi ve ara birim tasarımı daha önce işlenmiş, program tasarımı üzerinde fazla durulmamıştı.

### 9.2 Çıktı tasarımı

Sistem analistleri en faydalı çıktıyı elde etmek için kullanıcılarla etkileşimli çalışır. İyi çıktı:

- belirli bir amaca hizmet eder,
- kullanıcı için anlamlıdır; hangi kullanıcıya hangi bilginin verileceğine göre şekillenir,
- doğru zaman aralığındadır (günlük mü, aylık mı),
- doğru ortamda verilir (grafik çıktısı mı, işlem çıktısı mı).

Genellikle sıralı listeler alınır ve kabul edilebilir sınırlar belirlenir. Çıktı grafikse grafiğin tipi, rengi ve ölçeği ayarlanır.

### 9.3 Girdi tasarımı

Girdi tasarımında kolay kullanım, uyumlu olma ve doğruluk sağlanmalıdır. GIGO (garbage in, garbage out) ilkesi önemlidir: doğru girdi verilirse doğru çıktı alınır.

> **Hocanın vurgusu:** Kullanıcının giriş bilgisini doğru gireceği şekilde yönlendirmek tasarımcının sorumluluğudur. "Kullanıcı yanlış girmiş, bizim hatamız yok" denemez. Ekran yapısı düzgün olursa kullanıcı da hatalı bilgi girmez. Bu yüzden girdi ekranlarında web tasarımcılarıyla birlikte çalışılır.

### 9.4 Girdi kodlaması

Girdi tasarımındaki kodlama kavramı (yazılım kodlamasıyla karıştırılmamalı), işlem sırasında çıktıları daha anlamlı yapmak ve uygulamada daha iyi çalışabilmek için girdilerin sayısal ya da uygun karşılıklarla girilmesidir. Örneğin eğitim derecesi (ilkokul, ortaokul, lise, üniversite) yazıyla girilirse sorun çıkar; kısaltma kullanmak belki işe yarar, ama en iyisi bunlara 1, 2, 3, 4 gibi sayılar vermektir. Böylece daha hızlı sınıflama yapılır. Kodlamaya analizde düşünülerek tasarımda karar verilmiş olmalıdır. Daha önceki bir derste hastalık kodları da örnek olarak konuşulmuştu.

Slayttaki "İyi bir kodlamada dikkat edilmesi gereken durumlar" (ekrandan, 01:25:00):

- Kodlamanın mümkün olduğunca kısa olması gerekir.
- Kodlama kolay değişmeyecek şekilde olmalıdır; koda başlamadan önce kesin olarak karar verilmiş olmalıdır.
- Tekrarlanmamalı, tekil (unique) olmalıdır; her sınıfa bir kod verilir.
- Birbiriyle karıştırılabilecek sembollerden kaçınılmalıdır.
- Kodlamada kısaltmalar varsa anlamlı olmalıdır.
- Araya eleman eklemeye izin verecek şekilde değişikliğe izin verilebilmelidir.

### 9.5 Veri tabanı tasarımı

Veri yapısı ile program yapısı birbiriyle ilişkilidir. Veri tabanı tasarımında kullanışlı veri, veri bütünlüğü ve etkin (kolay) güncelleme sağlanmalıdır.

### 9.6 Ara birim tasarımı

Ara birim tasarımında etkinlik, verimlilik, kullanıcıların görüşlerinin alınabilmesi ve ergonomi önemlidir. Ergonomi için ekran renkleri göz yormamalıdır. Bir ekran tasarımı yapılmışsa aynı uygulamada ve benzer uygulamalarda aynı tasarımla devam edilmelidir; kullanıcı her sayfada farklı bir tasarımla karşılaşmamalıdır.

Nesneye yönelik sistem tasarımında sıralama (sequence) diyagramları ve sınıf diyagramları kullanılır; hoca bunlara bu derste girmedi.

## 10. Kodlama

### 10.1 Kodlamanın tanımı ve akışı

Tasarımdan sonra kodlamaya geçilir. Buradaki kodlama girdi kodlaması değil, yazılımın kodlanmasıdır: spesifikasyonlara uygun olarak yazılımın seçilen programlama diline çevrilmesi. Kodlamaya geçmeden önce programlama dili ve geliştirme platformuna karar verilir; komutlar dilin yapısına uygun girilir.

Ekrandaki akış şeması (ekrandan, 01:30:00):

```text
Sistem Gereksinimleri
   | Kabul
   v
Kodlama  ------------------------> Programlar
   | Kabul                ^
   v                      |
Denetim (karar) -- Revizyon --+   (revizyonda kodlamaya geri dönülür)
   | Kabul
   v
Test (Modüler, Genel, Onaylama) --> Test Planı ve İşlemleri
   |
   v
Sistem Kullanıma Hazır
```

Kodlama sistem gereksinimleri ve tasarım dikkate alınarak yapılır, programlar oluşturulur. Ardından kod denetimi yapılır: kodun yorumlayıcıya ya da derleyiciye uygun yazılıp yazılmadığı gözle ya da bir araçla kontrol edilir. Uygun değilse revizyonla kodlamaya dönülür. Sonra modüler test, genel test ve onaylama testi yapılır; test planı ve işlemleri kayıt altına alınır.

Kodlama ve test aşamasından iki belge (artifact) çıkar: programlar ile test planı ve test işlemleri, yani hangi testler uygulanarak bu aşamadan çıkıldığı. Böylece sistem kullanıma hazır hale gelir.

### 10.2 Programlama dilinin seçimi

Programlama dili aslında fizibilite aşamasında seçilir, burada uygulamaya konur. Seçim uygulama alanına, algoritmaya, veri yapısına, yazılımın kullanılacağı ortama, uygulama koşullarına ve yazılım geliştiricilerin bilgisine bağlıdır.

### 10.3 İyi kod yazma kuralları

- Açıklama satırları olmalıdır; çok fazla olmamalı ama programı kontrol eden ya da düzeltmek isteyen birinin anlayacağı kadar yeterli olmalıdır.
- Her modülün adı, işlevi ve amacı belirtilmelidir.
- Kod yazım düzeni, programın okunabilirliğini sağlayacak şekilde programlama diline uygun hazırlanmalıdır.
- Veri tabanı tabloları, değişkenler ve diğer adlar anlamlı olmalı; kısaltmalar anlamlı olmalı ve kurumun bir isimlendirme standardı bulunmalıdır. Böylece kodun üzerinden sonradan daha kolay geçilir.

## 11. Yazılım kalitesi ve test

### 11.1 Kaliteli yazılım ve kalite faktörleri

Kaliteli yazılım, önceden belirlenmiş olan işlevsel gereksinimlere ve yazılım geliştirme standartlarına tamamen uygun bir yazılımdır. Kalite faktörleri:

- **Doğruluk:** doğru sonuç vermesi.
- **Güvenilirlik (reliability):** doğru sonucun hangi duyarlılıkla verildiği (yüzde 95 mi, yüzde 96 mı), yani hata olmama olasılığı.
- **Verimlilik:** programın işlevlerini yerine getirirken kaynakları nasıl kullandığı.
- **Güvenlik:** yetkisiz kişilerin müdahale edip edemediği.
- **Kullanışlılık.**
- **Hata bulma kolaylığı.**
- **Esneklik.**
- **Test etme kolaylığı.**
- **Taşınabilirlik.**
- **Tekrar kullanılabilirlik:** yazılımın tamamının ya da bir parçasının başka bir yazılımda kullanılabilmesi (ya da başka bir yazılımın parçasının burada kullanılması).
- **Bağlanabilirlik (interoperability):** başka uygulamalarla bir arada kullanılabilme özelliği.

### 11.2 Test basamakları

Slayttaki "Yazılım Sınama Basamakları" (ekrandan, 01:35:00): yazılımın sınanması ünite testi, bütünlük testi, sistem testi ve onaylama testi basamakları halinde gerçekleştirilir. Böylece sınama işlemi, yazılım geliştirmenin son basamağı olan kodlamadan geriye doğru yürütülür.

- **Birim (ünite) testi:** programın kodlanmasının hemen arkasından yapılır.
- **Bütünlük testi:** bütün modüllerin bir arada doğru çalışıp çalışmadığı sınanır.
- **Sistem testi:** yazılımın sistemin diğer elemanlarıyla uygun çalışıp çalışmadığı sınanır.
- **Onaylama testi:** yazılımın kullanıcının belirttiği gereksinimlere uygun çalışıp çalışmadığı sınanır.

> **Ek bilgi (derste anlatılmadı):** "Kodlamadan geriye doğru" ifadesi, testlerin geliştirme aşamalarını ters sırada doğrulamasıyla ilgilidir: birim testi ayrıntılı tasarımı, bütünlük testi ön tasarımdaki modül yapısını, sistem testi sistem gereksinimlerini, onaylama testi de kullanıcı gereksinimlerini sınar. Bu eşleşme V modeli olarak da bilinir.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:41:12)

**Soru:** Bir ER diyagramında hangi tip ilişkiler vardır?

**Cevap (derste verildi):** Bir öğrencinin cevabı ve hocanın tamamlamasıyla:

- Sayısal (kardinalite) olarak: bire bir, bire çok ve çoka çok ilişkiler.
- Zorunluluk açısından: ilişki birden başlıyorsa (en az bir varsa) zorunludur (mandatory); sıfırdan başlıyorsa seçimliktir (optional), yani ilişki hiç olmayabilir. Örneğin "sıfır ya da bir" ve "sıfır ya da çok" seçimlik, "bir ya da çok" ve "bir ve yalnız bir" zorunlu ilişkilerdir.

### Soru 2 (derste sözlü, 01:36:58; bir öğrencinin çözümü ekrandan, 01:40:00)

**Soru:** Bir önceki derste verilen alıştırma: daha önceki bir sınav sorusundaki araba kiralama şirketi sistemi için yapı diyagramı oluşturun. <!-- BELİRSİZ: sınav sorusunun tam metni derste gösterilmedi; içerik öğrencilerin anlatımından kuruldu -->

Öğrencilerin anlatımından anlaşılan sistem: müşteri araç kiralar (araç özelliklerini belirler, aracı ister) ve aracı iade eder (kilometre bilgisi verir, ödeme yapar). Şirket tarafında yönetici kiralama fiyatını belirler; galeri envantere yeni araç ekler, kiralama işlemini oluşturur ve iade bilgilerini saklar.

**Birinci çözüm (bir öğrenci, sözlü anlatım):** Ana modülün altında önce bir eşkenar dörtgenle şirket mi müşteri mi olarak devam edileceğine karar verilir. Müşteri dalında "araç kiralama" (araç özelliklerini belirleme, aracı isteme) ve "araç iade etme" (kilometre bilgisi verme, ödeme yapma) modülleri vardır. Şirket dalında yönetici için "kiralama fiyatı belirleme" (araç bilgisini öğrenme, fiyatı belirleme), galeri için "envantere yeni araç ekleme" (araç bilgisini girme, depolama), "kiralama işlemi oluşturma" (müşteriyle araç bilgisi paylaşma, kiralama bilgilerini saklama) ve "iade bilgilerini saklama" (kiralama bilgisini, kilometre bilgisini ve ödeme bilgisini alıp saklama) modülleri vardır.

Derste vurgulananlar: en üstte eşkenar dörtgenle verilen bir karar, alttaki dalları ayırır; diyagram hiyerarşik olarak aşağıya doğru ilerler ve hiyerarşi numaralandırmayla netleştirilebilir. Giren ve çıkan veri akışları oklarla gösterilebilir, ama çok sayıda veri akışı diyagramı karıştırabilir.

**İkinci çözüm (bir öğrenci, ekrandan, 01:40:00):**

```text
Araba Kiralama Programı  (altında yarım daire döngü oku)
├── Fiyat İşleme
│   ├── Fiyat Belirleme      (gider: Araba Bilgileri, Yeni Fiyat)
│   └── Fiyat Okuma          (gider: Araba Bilgileri; döner: Araba Fiyatı)
├── Araç Kiralama
│   ├── Fiyat Okuma          (gider: Araba Bilgileri; döner: Araba Fiyatı)
│   ├── Ödeme                (gider: Araba Fiyatı; döner: Onaylanan Ödeme Bilgileri)
│   │   └── Kredi Kartı Bilgisi Girme   (döner, kontrol: Ödeme Onaylandı)
│   └── Araba Kaydı Güncelleme          (gider: Araba Bilgileri)
├── Araç İadesi
│   ├── Fiyat Okuma          (gider: Araba Bilgileri; döner: Araba Fiyatı)
│   ├── Geri Ödeme           (gider: Araba Fiyatı; döner: Onaylanan Ödeme Bilgileri)
│   │   └── Bankaya İade Bilgilerinin İletilmesi   (döner, kontrol: Ödeme Onaylandı)
│   └── Araba Kaydı Güncelleme          (gider: Araba Bilgileri)
└── (araç ekleme modülü; karede sağ kenarda kesik)
```

Ana modülle alt modüller arasındaki akışlar: Fiyat İşleme'den "Güncel Araba Fiyatı" döner; Araç Kiralama'ya "Araba Bilgileri" gider, kontrol bilgisi olarak "Kiralama İşlemi Tamamlandı" döner; Araç İadesi'ne "Araba Bilgileri" gider, "İade İşlemi Tamamlandı" döner; araç ekleme modülüne "Araba Bilgileri" gider, "Ekleme İşlemi Tamamlandı" döner. Kiralamada ödeme onaylandıktan sonra araba kaydı "kiralandı" olarak güncellenir; iadede kredi kartı yerine bankaya geri ödeme talimatı verilir. <!-- BELİRSİZ: dördüncü (araç ekleme) modülünün adı karede görünmüyor; öğrenci bu modülün tek işlem olduğunu ve alt modül gerekmediğini söyledi -->

Derste vurgulananlar:

- İşlemin tamamlandığını bildiren dönüşler içi dolu daireli kontrol oklarıyla gösterilir.
- Her ayrıntıyı (ör. her adımda "işlem tamamlandı") göstermek karışıklığa yol açar; temel akışları göstermek yeterlidir.
- **Soru:** Aynı modül (Fiyat Okuma) diyagramda iki kez yazılabilir mi? **Cevap:** Yazılabilir; ama ortak modül tek bir kez kullanılıp diğer çağrılar da aynı modüle bağlanabilir.

## Dersin Toparlaması

Derste önce veri tabanı tasarımı tekrar edildi. Geleneksel yaklaşımda veri, işlemlerden ayrı varlıklar olarak ERD ile modellenir; ilişkiler iki yönden okunur ve hem kardinaliteyi (bire bir, bire çok, çoka çok) hem zorunluluğu (sıfırdan başlıyorsa seçimlik, birden başlıyorsa zorunlu) gösterir. Her varlığın biricik ve boş olmayan bir birincil anahtarı vardır. Nesneye yönelik yaklaşımda sınıf diyagramı veriye ek olarak metotları, kalıtım hiyerarşisini ve bütün-parça ilişkisini de gösterir. Çoka çok ilişkiler veri tabanında ara bir ilişki tablosuyla, sınıf diyagramında ise ilişki sınıfıyla gerçeklenir; ilişkiye ait özellik (ders kaydındaki not gibi) bu tabloda tutulur.

İkinci yarıda sistem tasarımı baştan sona özetlendi: ön tasarımda modüller, mimari, envanter, iş yükü, yazılım ve satıcı seçimi; modül yapısını gösteren yapı diyagramı (döngü, veri ve kontrol okları, koşul); ayrıntılı tasarımda veri tabanı, çıktı, girdi (GIGO, girdi kodlaması), program ve ara birim tasarımı. Ardından kodlama aşaması, denetim-revizyon döngüsü, yazılım kalitesinin faktörleri ve birimden onaylamaya test basamakları anlatıldı. Hoca, sonraki derste bir sistemin hem nesneye yönelik hem yapısal yaklaşımla ele alındığı bir uygulama üzerinde durulacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
