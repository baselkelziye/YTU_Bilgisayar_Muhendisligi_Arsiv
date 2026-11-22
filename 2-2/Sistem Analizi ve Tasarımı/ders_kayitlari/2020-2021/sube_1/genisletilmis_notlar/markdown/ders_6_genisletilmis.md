# Ders 6 Genişletilmiş Notu: Veri Varlıkları ve Nesneler, Yapısal Analiz Modeli ve Veri Akış Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin planı
- 2. Bilgi tutulacak şeylerin özellikleri: ilişki ve özellik
- 3. Veri varlıkları ve nesneler
- 4. ER diyagramında kardinalite ve zorunluluk
- 5. Nesne sınıfları ve sınıf diyagramı örnekleri
- 6. Yapısal yaklaşımla gereksinim analizi modeli
- 7. Veri akış diyagramları: bağlam diyagramı
- 8. Birinci düzey ayrıntılı veri akış diyagramı
- 9. Faturalama sistemi örneği
- 10. İkinci düzey ayrıntılı veri akış diyagramı
- 11. Araçlar ve VAD'ın yeri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin planı

Ders, analiz aşamasında kullanılan modelleme araçları üzerineydi. Hoca önce bir önceki haftanın son kısmında işlenen nesne ve varlık arasındaki farkları hızlıca tekrar etti, sonra yapısal yaklaşımla analizin nasıl yapıldığına ve bununla ilgili diyagramlara, özellikle veri akış diyagramlarına geçti. Daha önceki derslerde veri akış diyagramlarına sözlü bir giriş yapılmış ve bir taslak diyagram görülmüştü; bu derste konu genişletildi. Tekrar bölümünde kullanılan slaytlar İngilizce ders kitabı slaytlarıdır (Systems Analysis and Design in a Changing World, Satzinger, Jackson ve Burd; slayt altbilgisinden, ekrandan, 00:05:00). Veri akış diyagramı bölümünde ise Türkçe hazırlanmış "Gereksinim Analizi — Yapısal Yaklaşım ile" başlıklı bir sunum kullanıldı (ekrandan, 00:30:00).

Hoca, bu kavramların ileride ayrıntılı tasarımda veri tabanı tasarımı sırasında yeniden ele alınacağını ve veri tabanı dersinin de konusu olduğunu, ama burada kavramların özetlenmesi gerektiğini söyledi.

## 2. Bilgi tutulacak şeylerin özellikleri: ilişki ve özellik

Bir bilgi sistemi kurulurken hakkında bilgi toplanması gereken "şeylerin" (things) özellikleri incelenir. Ekrandaki "Characteristics of Things" slaytı iki başlık verir (ekrandan, 00:10:00):

- **Relationship (ilişki):** belirli şeyler arasında doğal olarak oluşan bağlantı; iki yönde oluşur; kardinalite/çokluk (cardinality/multiplicity) taşır; ikili, tekli, üçlü ya da n'li (binary, unary, ternary, n-ary) olabilir.
- **Attribute (özellik):** bir şey hakkındaki tek bir bilgi parçası.

### 2.1 Özellikler nasıl belirlenir?

Hoca öğrenci varlığı üzerinden düşünmeyi önerdi. Bir öğrencinin hangi bölümde olduğu, adı, soyadı ve numarası mutlaka tutulması gereken özelliklerdir. Bunun yanında giriş dosyasından gelen mezun olunan lise bilgisi ya da doğum tarihi de gerekebilir. Ama hoca bunların ezbere söylenmediğini vurguladı:

> **Hocanın vurgusu:** Özellikler ezbere seçilmez. Sistem analizi çalışmasında bu sistemden hangi çıktıların alınacağı ve bu çıktıların nerede kullanılacağı araştırılır. Örneğin bir karnede ya da sertifikada çıkması gereken bilgiler varsa bu bilgiler saklanmalıdır. Her varlık için tutulacak özellikler buna göre belirlenir.

Ekranda "Attributes and Values" (özellikler ve değerler) başlıklı bir tablo slaytı da vardı (slayt listesinden, ekrandan, 00:05:00). Hoca bu tabloda bütün müşterilerin sahip olduğu özellikleri saydı: müşteri numarası, ad, soyad, ev telefonu, iş telefonu. Sol sütunda özellik tanımları, sağda her müşteri için bu özelliklerin değerleri bulunur. Özellik tanımı geneldir; bu genel tanıma karşı varlığın her bir satırında (her bir müşteride) değerler yer alır.

<!-- BELİRSİZ: "Attributes and Values" tablosundaki örnek değerler karede okunacak boyutta görünmüyor. -->

### 2.2 İlişkiler

İlişkiler varlıklar arasında kurulur ve mutlaka iki yönlüdür. İlişki iki şekilde nitelenir:

- **Sayısal çokluk (kardinalite):** ilişkinin karşı tarafında kaç eleman olabileceği (bir, çok).
- **Zorunluluk / seçimlik:** karşı tarafta en az bir eleman olmak zorunda mı, yoksa sıfır da olabilir mi?

Hocanın örneğinde öğrenci ile ders arasındaki ilişki sorgulandı: Bir öğrenci bir dersi mutlaka almak zorunda mıdır? Hayır, bütün dersleri alması gerekmez. Bir dönemde sıfır ders almış da olabilir, birden çok ders almış da olabilir. Bu, sıfır ya da çok olan seçimlik bir ilişkidir. Buna karşılık bir sipariş uygulamasında bir sipariş varsa en az bir kalem (alınan ürün bilgisi) mutlaka olmalıdır; bir fatura ile faturadaki kalemler arasında en az bir kalem bulunur. Bu ilişki UML gösteriminde `1..*` biçiminde yazılır.

Ders kitabındaki "Relationships Naturally Occur Between Things" şeklinde (slayt listesinden, ekrandan, 00:05:00) siparişler, muhasebe departmanı ve siparişin içerdiği kalemler arasındaki ilişkiler gösteriliyordu: bir siparişi kimin verdiği, çalışanın hangi departmanda çalıştığı, hangi siparişte hangi kalemlerin olduğu.

<!-- BELİRSİZ: "Relationships Naturally Occur Between Things" şeklinin içeriği karede okunacak boyutta görünmüyor; yukarıdaki açıklama altyazıdandır. -->

## 3. Veri varlıkları ve nesneler

Geleneksel bilgi sistemi yaklaşımında hakkında veri saklanması gereken şeyler **veri varlıklarıdır** (data entities). Slayta göre veri varlıkları varlık ilişki diyagramıyla modellenir ve genellikle ilişkisel veri tabanı geliştirmede kullanılır (slayt listesinden, ekrandan, 00:05:00). Veri tabanı kullanılarak tanımları gerçekleştirilir.

Nesneye yönelik yaklaşımda ise hakkında bilgi saklanan şeyler **nesnelerdir**. Nesnelerin hem özellikleri hem davranışları saklanır. Sınıf, bu şeyin tipidir; nesne, üzerinde bilgi tutulacak somut şeydir; metotlar da nesnelerin nasıl davrandığını gösterir. Hoca, derste her iki yaklaşımın da görüldüğünü hatırlattı.

### 3.1 Karşılaştırma şekli

Ekrandaki "Data Entities Compared with Objects" şeklinde (ekrandan, 00:15:00) iki yapı karşılaştırılır:

- **Üstte, "Data entities are separate from processes":** soldan girdi (input) gelen, sola çıktı (output) veren bir kutu içinde process 1, process 2, process 3 ayrı ayrı durur. Bu kutu, sağdaki ayrı bir "Data entity" silindiriyle çift yönlü okla veri alışverişi yapar.
- **Altta, "Objects encapsulate data and the methods that process the data into one unit":** bir "Object" kutusu içinde nesneye ait veri ("Data belonging to the object") ve veriyi işleyen metotlar ("Methods that process the data") birlikte bulunur. Nesne dışarıyla mesajlarla (message) haberleşir.

Hocanın anlatımıyla: veri varlığı dışarıda bir yerde durur, işlem yapılacağı zaman onunla bilgi alışverişi olur ve işlem 1, işlem 2, işlem 3 varlık üzerine ayrı ayrı uygulanır; işlemler ayrı tutulur. Nesnelerde ise veri üzerinde gerçekleştirilecek işlemler aynı yerde tanımlanır ve bu işlemler mesajlarla tetiklenir; yani nesnenin tanımındaki bir işlemi bir mesaj çalıştırır.

## 4. ER diyagramında kardinalite ve zorunluluk

Klasik yaklaşımdaki ER (Entity Relationship) diyagramında müşteri ve sipariş varlıkları arasındaki ilişki örneklendi.

### 4.1 Müşteri ve sipariş

**Soldan sağa okuma:** Bir müşteri sıfır sipariş de vermiş olabilir, çok sayıda sipariş de. Sıfır siparişin anlamı şudur: müşteri olarak kaydımızda vardır ama henüz sipariş vermemiştir. Sipariş tarafındaki işaret "sıfır ya da çok" anlamına gelir; bu seçimlik (optional) bir tanımdır.

**Sağdan sola okuma:** Bir sipariş varsa karşılığında mutlaka bir müşteri olmalıdır. Müşteri tanımı yapılmadan sipariş kaydı girilemez. Bu zorunlu (mandatory) bir tanımdır. Sayısal olarak bir sipariş yalnız bir müşteri tarafından verilir; bir sipariş kaydının karşısında tek bir müşteri vardır.

Hoca sembolleri şöyle özetledi:

- **Bir ve yalnız bir:** zorunlu; karşıda tam bir eleman.
- **Sıfır ya da çok:** seçimlik.
- **Bir ya da çok:** zorunluluk vardır, en az bir tane olmalıdır.
- **Sıfır ya da bir:** karşıda eleman olmayabilir, olursa yalnız bir tanedir.

Bu işaretler ilişkilerin kardinalitesini belirler.

<!-- BELİRSİZ: ER kardinalite sembollerinin çizildiği slaytın karesi yok; sembollerin görsel biçimi aktarılamadı. -->

> **Ek bilgi (derste anlatılmadı):** Bu tür ER gösteriminde kardinalite genellikle "kaz ayağı" (crow's foot) sembolleriyle çizilir: çizgiye dik bir çubuk "bir", küçük daire "sıfır", üç kollu çatal "çok" anlamına gelir. İki sembol yan yana konarak en az ve en çok değerler birlikte gösterilir.

### 4.2 Sipariş ve sipariş kalemi

Hoca bir marketten alınan fatura örneğini verdi: bir alışveriş işlemi yapıldıysa ve bir sipariş varsa, bunun karşısında en az bir ürün olmalıdır. Yani bir sipariş en az bir kalem içermelidir, ama çok sayıda kalem de içerebilir. Hoca bu ilişkilerin ileride veri tabanında da yerleşeceğini, ama dönem çalışmalarında şimdiden kullanılacağını söyledi. Analiz sırasında hangi varlıklar hakkında bilgi tutulacağı ve bunların ilişkileri hep belirlenmeye çalışılır.

### 4.3 Somut örnek: müşteriler, siparişler ve sipariş kalemleri

"Customers, Orders, and Order Items" şekli ilişkileri örneklerle canlandırır (ekrandan, 00:20:00):

- **John:** Order 1 (Feb 4) — First shirt, Second shirt, Belt; Order 2 (March 29) — Boots, First sandals, Second sandals.
- **Mary:** "no orders for Mary yet!" (henüz sipariş yok).
- **Sara:** Order 3 (March 30) — First sandals, Second sandals, Third sandals.

Yani bir müşteri çok sayıda sipariş vermiş, bir müşteri hiç sipariş vermemiş, bir müşteri yalnız bir sipariş vermiştir. Her siparişte en az bir (burada üçer) kalem vardır; ilk siparişte aynı üründen iki tane ve farklı bir ürün bulunur.

## 5. Nesne sınıfları ve sınıf diyagramı örnekleri

Veri varlıklarından nesne sınıflarına geçildiğinde nesnelerin veri varlıklarından daha fazla bilgi içerdiği görülür:

- **Genelleştirme/özelleştirme hiyerarşileri:** nesneler üst sınıfların bilgilerini kalıtım yoluyla paylaşır.
- **Bütün-parça (aggregation) ilişkileri:** nesneler ve onların parçaları arasındaki ilişkiler ve parçalar hakkındaki tanımlar görülür.

Hoca bu kavramların nesneye yönelik analiz konularında da geçtiğini ama burada da yerleşmesini istediğini söyledi. Bütün-parça örneği olarak bilgisayar ve alt parçaları verildi: işlemci, bellek, klavye gibi elemanlar bilgisayarın parçalarıdır ve bütün-parça ilişkisi aggregation ile gösterilir.

### 5.1 Sınıf sembolü

Sınıf sembolü üç bölmelidir: en üstte sınıf adı (ör. Müşteri), ortada özellikler (müşterinin adı, adresi, telefonu), altta bu sınıftaki nesnelere uygulanacak metotlar (işlemler).

### 5.2 Bankacılık örneği

Bankacılık sistemine ait sınıf diyagramında müşteri, müşterinin sahip olduğu hesaplar ve hesapların tipi gösterilir. Müşteri ile hesap arasında: bir müşteri daha önce bankayla işlem yapmış ama şu anda hiç hesabı olmayabilir (müşteri kaydı var, hesap sıfır), ya da çok sayıda hesabı olabilir. Hesapların hangi türde olduğu da diyagramda görünür.

<!-- BELİRSİZ: Bankacılık sınıf diyagramının ve genelleştirme/bütün-parça şekillerinin karesi yok; içerikleri yalnız altyazıdan aktarıldı. -->

### 5.3 İlişki sınıflı ders kaydı diyagramı

Daha karmaşık örnek, ders kaydıdır (ekrandan, 00:25:00, "Enrollment Class Diagram with Association Class"):

| Sınıf | Özellikler | Metotlar |
|---|---|---|
| Course | courseNumber, title, creditHours | addCourse |
| CourseSection | sectionNumber, startTime, roomNumber | openSection, closeSection |
| Student | studentID, name, major | admitStudent, recordDegree |
| CourseEnrollment (ilişki sınıfı) | grade | postGrade |

İlişkiler:

- **Course — CourseSection:** Course tarafında `1`, CourseSection tarafında `0..*`.
- **CourseSection — Student:** iki tarafta da `0..*`.
- **CourseEnrollment:** CourseSection–Student ilişki çizgisine kesikli çizgiyle bağlı ilişki sınıfı.

Hocanın okuması: Öğrenci ile açılan dersler (şubeler) arasında bir ilişki kurulur ve öğrencinin derse kaydı bir ara sınıf, yani ilişkinin tanımı olarak görülür. Bir öğrenci hiç ders seçmemiş olabilir ya da çok sayıda ders seçmiş olabilir. Bir ders şubesi açılmış ama hiçbir öğrenci tarafından seçilmemiş olabilir ya da çok sayıda öğrenci tarafından seçilmiş olabilir. Ders tarafından bakılırsa bir ders o dönem hiçbir şubede açılmamış olabilir (sıfır). Ama açılan her şube mutlaka ders kataloğundaki bir derse, kesin olarak tek bir derse karşılık gelmelidir.

## 6. Yapısal yaklaşımla gereksinim analizi modeli

Hoca bu bölümde Türkçe sunuma geçti. Yazılım mühendisliğinde bu aşama gereksinim analizi (requirement analysis) olarak geçer; hoca şimdilik "sistem analizi" demeyi tercih etti.

### 6.1 Modelin üç amacı

Slayttaki "Gereksinim Analizi Modeli" maddelerine göre sistem analizi süresince oluşturulan model şu üç amacı yerine getirmelidir (slayt listesinden, ekrandan, 00:35:00):

- Müşteri ihtiyaçlarını açıklamak.
- Yazılım tasarımının nasıl oluşturulacağına dair temel oluşturmak.
- Yazılım bir kere oluşturulduktan sonra belirlenen ihtiyaçları karşılayıp karşılamadığını onaylayan unsurları belirlemek.

Hoca üçüncü maddeyi şöyle açtı: sistem analizi sırasında müşterinin ne istediği iyi anlaşılır, müşteriye de iyi anlattırılır ve uygun model oluşturulup üzerinde anlaşma sağlanırsa, bilgi sistemi hazırlandıktan sonra kullanıcı testi yapılırken ve onay verilirken bakılacak bir materyal elde edilmiş olur.

### 6.2 Modelin bileşenleri

Ekrandaki halka şekli (ekrandan, 00:30:00):

```text
                 en dış halka (spesifikasyonlar)
   Veri Nesne Tanımı   |  Süreç Spesifikasyonu  |  Kontrol Spesifikasyonu
                 orta halka (diyagramlar)
   Varlık İlişki Diy.  |  Veri Akış Diyagramı   |  Durum Geçiş Diyagramı
                 merkez
                         Veri Sözlüğü
```

- **Veri / nesne tanımı (varlık ilişki diyagramı):** Çok kapsamlı olmayacak; sistemde hangi varlıklar hakkında bilgi tutulacağı, bunların özellikleri ve birbirleriyle ilişkileri belirlenir.
- **Süreç spesifikasyonu (veri akış diyagramı):** Veri üzerinde uygulanacak iş süreçlerinin, işlemlerin ayrıntılı tanımıdır; "spesifikasyon" burada ayrıntılı tanımlama anlamındadır. Müşteriyle yapılan ilk görüşmelerde sistem çok ayrıntılı ve karmaşık olmamalıdır ki yavaş yavaş ilerlenip iş anlaşılsın. Bu yüzden VAD'lar aşamalı paketler halinde çizilir: önce özet diyagram, sonra ayrıntılı, sonra daha ayrıntılı diyagram.
- **Kontrol spesifikasyonu (durum geçiş diyagramı):** Durum geçişleri arasında neler olduğu, nasıl bir kontrol mekanizması bulunduğu tanımlanır.
- **Veri sözlüğü (data dictionary):** "Veri hakkında veri" tutar. Uygulamada hangi varlıklar olduğu, özelliklerinin neler olduğu, hangi işlemlerin gerçekleştiği ve bu işlemlerin tanımları; yani uygulamada kullanılan bütün tanımlamalar veri sözlüğündedir.

Hoca pratikte en çok varlık ilişki diyagramlarının (veri/nesne tanımı) ve veri akış diyagramlarının kullanılacağını belirtti.

### 6.3 Slayttaki tanımlar

Sunumun sonraki slaytındaki maddeler hoca tarafından okundu (slayt listesinden, ekrandan, 00:35:00):

- Modelin ortasındaki veri sözlüğü, yazılım tarafından kullanılan ve üretilen tüm veri nesnelerinin tanımını içerir.
- Varlık ilişki diyagramı (Entity Relationship Diagram, ERD) veri nesneleri arasındaki ilişkiyi tarif eder; her veri nesnesinin özellikleri de ERD'de belirtilir ve veri modelleme aşamasında kullanılır.
- Sistem içinde her verinin nasıl taşındığı ve bu veri akışını sağlayan fonksiyonların neler olduğu veri akış diyagramında (VAD, data flow diagram, DFD) tarif edilir. VAD, sistem analizi süresince bütün fonksiyonların modellenmesinde kullanılan bilgiyi sağlar.

## 7. Veri akış diyagramları: bağlam diyagramı

### 7.1 Öğrenci bilgi sistemi örneği

Daha önce görülen taslak diyagram yeniden ele alındı. Slayttaki tanım (ekrandan, 00:35:00): "Sistemin dışsal birimlerinin sistem ile ilişkisini basitçe gösterildiği diyagramdır. Tek bir işlem olur ve sistemin ismi ile belirtilir." Şeklin adı "Şekil 2. Örnek taslak diyagram"dır.

```text
+---------+  Ders Seçimi        +-------------+  Sınıf listesi    +-----------+
| Öğrenci | ------------------> |   Öğrenci   | ----------------> | Öğretim   |
|         | <------------------ |    Bilgi    | <---------------- | Üyeleri   |
+---------+  Sınav sonuçları    |   Sistemi   |  Sınav sonuçları  +-----------+
                                +-------------+
```

Diyagramda tek işlem vardır: Öğrenci Bilgi Sistemi. Dış varlıklar (öğrenci ve öğretim üyeleri) kareyle gösterilir. Hoca durumu şöyle canlandırdı: bir üniversiteye öğrenci bilgi sistemi kurmak için görüşmeye gittiniz. Bu sistem hangi varlıklarla, nasıl bir ilişki içinde? Burada ER diyagramındaki gibi sayısal çokluk ya da zorunluluk yoktur; iş açısından sistemin öğretim üyelerine hangi bilgiyi gönderdiği ve onlardan hangi bilgiyi alıp sisteme yerleştirdiği belirtilir.

- Öğrenci ders seçimi yaparken sisteme başvurur; sınav sonuçları açıklandığında sistem öğrenciye sınav sonuçlarını gönderir.
- Öğretim üyeleri sistemden ilk ders haftasında öğrenci sınıf listesini (dersi kimlerin aldığını) alır; sisteme sınav sonuçlarını gönderir. Sonuçlar sisteme girildiğinde öğrencinin e-postasına da düşer.

Daha kapsamlı bir uygulamada daha çok varlık olur ve işlemler daha ayrıntılı anlatılır; ama bu diyagram bir bağlam diyagramında bulunması gereken en az bilgiyi gösterir. Bu diyagrama örnek taslak diyagram, bağlam (context) diyagramı ya da özet diyagram denir. Hoca daha sonra "aslında taslak değil özet oluyor" diye düzeltti.

> **Hocanın vurgusu:** Bir bilgi sistemiyle ilgili analiz aşamasında bağlam diyagramı çizerken kesinlikle birden fazla işlem kullanılmaz. Tek işlem vardır ve bu işlemin adı bütün bilgi sistemini kapsayan bir ad olmalıdır.

Hoca özet diyagramın sisteme üstten, daha geniş açıdan bakmayı sağladığını söyledi: sistem ne kadar karmaşık ve çok alt işlemli olursa olsun, tek bir işlem olarak görülür ve yalnız hangi varlıklarla iletişim kurduğu gösterilir.

## 8. Birinci düzey ayrıntılı veri akış diyagramı

### 8.1 Öğrenci bilgi sistemi örneği

Aynı örneğin birinci seviye diyagramı "Şekil 3. Örnek birinci seviye diyagram" olarak gösterildi (ekrandan, 00:40:00):

```text
Öğrenci          --(Ders Seçimi)-->                    [Ders Seç]
[Ders Seç]       --(Öğrenci-seçilen dersler bilgisi)--> (Öğrenci-Ders veritabanı tablosu)
[Ders Seç]       --(Öğrenci-seçilen ders bilgileri)-->  [Sınav sonuçlarını sisteme ekle]
[Sınav sonuçlarını sisteme ekle] --(Sınıf listesi)-->   Öğretim Üyeleri
Öğretim Üyeleri  --(Sınav sonuçları)-->                 [Sınav sonuçlarını sisteme ekle]
[Sınav sonuçlarını sisteme ekle] --(Sınav sonuçları)--> (Öğrenci-Not veritabanı tablosu)
[Sınav sonuçlarını sisteme ekle] --(Öğrenci-not bilgisi)--> [Sınav sonucu görüntüle]
(Öğrenci-Not veritabanı tablosu) --(Sınav sonuçları)--> [Sınav sonucu görüntüle]
[Sınav sonucu görüntüle] --(Sınav sonuçları)-->          Öğrenci (ikinci kez çizilen varlık)
```

Burada köşeli parantez işlemi, normal parantez veri tablosunu gösterir. Diyagramda iki varlık vardır (öğrenci ve öğretim üyeleri); öğrenci ikinci kez çizilmiştir.

**Tekrar kullanılan varlık:** Aynı varlık diyagramda ikinci kez kullanıldığında üçüncü bir varlık sanılmasın diye, ikinci kullanıldığı yerde köşesine çapraz bir çizgi çizilir. Bu, yeni bir varlık olmadığını, daha önce kullanılan varlığın tekrar kullanıldığını gösterir. Hoca anlatırken önce çizginin "eskiden kullanılan" yere konduğunu söyledi, sonra düzeltti: çizgi ikinci kullanıldığı yere konur.

İşlemler sırayla:

- **Ders seç:** Öğrenci ders seçimi yapar. Sistem öğrencinin seçtiği dersler bilgisini öğrenci-ders veri tabanı tablosuna kaydeder.
- **Sınav sonuçlarını sisteme ekle:** Öğretim üyesi tarafından yapılır. Öğretim üyesi önce sistemden sınıf listesini alır, sonra sınav sonuçları bilgisini sisteme gönderir; sonuçlar öğrenci-not veri tablosuna işlenir. En çok veri akışı bu ortadaki işlemdedir.
- **Sınav sonucu görüntüle:** Sonuçlar çıktığında öğrenci sistemi açıp sınav sonuçlarını görüntüler.

Hoca, bu diyagramla analiz aşamasının başlatıldığını söyledi: ders seçimi yap, sınav sonuçlarını sisteme ekle, sınav sonucunu görüntüle ve veri tabanı tablosuna ekle gibi işler sırayla işlemlere dönüştürülmüş olur.

### 8.2 "Diyagram 0" adı

Farklı kaynaklarda birinci düzey ayrıntılı diyagrama "0 diyagramı" denir. Bunun nedeni numaralandırmanın sıfırdan başlatılmasıdır; diyagram sıfırıncı düzey ayrıntılı VAD olarak okunur. Derste numaralandırma birden başlatıldığı için "birinci düzey" denir.

## 9. Faturalama sistemi örneği

### 9.1 Bağlam diyagramı

Başka bir uygulama: bir doktor muayenehanesi. Hasta gelir, doktora muayene olur. Hastanın sigortası varsa faturanın bir kısmı sigortaya, bir kısmı hastaya gönderilir; sigorta yoksa tümü hastaya kesilir. Ekrandaki diyagram (ekrandan, 00:45:00):

```text
Doktor  --(Muayene Kaydı)-->  [FATURALAMA SİSTEMİ]  --(Sigorta Faturası)-->  Sigorta
Hasta   --(Sigorta Formu)-->  [FATURALAMA SİSTEMİ]
Hasta  <--(Hasta Faturası)--  [FATURALAMA SİSTEMİ]
```

Hoca bu diyagramın adını öğrencilere sordu (bkz. Örnek Sorular). Cevap: bağlam (context) veri akış diyagramı; taslak, özet ya da soyut diyagram adları da kullanılır. Bu, VAD paketinin ilk örneğidir.

Semboller tekrar edildi: kare ya da dikdörtgenler varlıklar, kenarları yuvarlatılmış dikdörtgen işlem; işlemlerle varlıklar ve veri kaynakları arasında oklar vardır. "Faturalama Sistemi" sistemin genel adıdır ve tek işlemi temsil eder.

- **Hasta ile ilişki:** sistem hastadan sigorta formunu alır, hastaya hasta faturasını gönderir.
- **Sigorta ile ilişki:** sistem yalnız sigorta faturasını gönderir. Hoca, daha ayrıntılı düşünülseydi sigortadan hastanın nasıl bir sigortalı olduğunu belirten bir bilgi de alınabileceğini ekledi.
- **Doktor ile ilişki:** doktor muayeneyi yapar ve faturalama sistemine muayene kaydını gönderir. Kayıt yalnız muayeneyi mi, yanında kısa bir kan analizi gibi başka işlemleri de mi içeriyor, bunu belirtir; hastanın faturası buna göre hazırlanır.

### 9.2 Birinci düzey ayrıntılı diyagram

Bu diyagram öğrenci örneğine göre gerçek bir birinci düzey VAD yapısına daha uygundur (ekrandan, 00:55:00). Hoca önce şunu düşünmek gerektiğini söyledi: sistem hakkında bilgi toplandı, şimdi modellenecek; istenen işin olması için sırayla hangi işlemler gerçekleşmelidir? İşlemler 1.0, 2.0, 3.0, 4.0 diye numaralanır.

| No | İşlem |
|---|---|
| 1.0 | Muayene Kaydı İnceleme ve Ücret Hesabı |
| 2.0 | Fatura Hazırlama |
| 3.0 | Hasta Ödemeleri İşleme |
| 4.0 | Sigorta Ödemeleri İşleme |

| Veri deposu | Ad |
|---|---|
| D1 | Ücret Listeleri |
| D2 | Hastalar |
| D3 | Sigorta Şirketleri |
| D4 | Muhasebe Kayıtları |

Veri akışları:

```text
Doktor              --(Muayene Kaydı)-->                  1.0
1.0                 --(Ücret)-->                          D1 Ücret Listeleri
1.0                 --(Doğrulanmış Ücret)-->              2.0
Hasta               --(Sigorta Formu)-->                  2.0
D3 Sigorta Şirketleri --(Sigorta Şirketi Adı ve Adresi)--> 2.0
D2 Hastalar         --(Hasta Adresi)-->                   2.0
2.0                 --(Hasta Faturası)-->                 Hasta (ikinci kez çizilen, köşesi çizgili)
2.0                 --(Sigorta Faturası)-->               Sigorta Şirketi
Hasta               --(Hasta Ödeme)-->                    3.0
Sigorta Şirketi     --(Sigorta Ödeme)-->                  4.0
3.0                 --(Hasta Ödeme)-->                    D4 Muhasebe Kayıtları
4.0                 --(Sigorta Ödeme)-->                  D4 Muhasebe Kayıtları
```

Hocanın anlatımıyla akış:

- **1.0:** Doktor ne yaptığını söyler. İşlem, doktorun muayene kaydındaki her bir işin ücret listesinde ne kadara karşılık geldiğine bakar; ortaya doğrulanmış ücret çıkar ve 2.0'a gönderilir.
- **2.0:** Doğrulanmış ücrete göre fatura hazırlanır. Hastadan sigorta formu, dosyalardan sigorta şirketi bilgileri ve hasta bilgileri alınır. Hastaya kendi bilgileriyle, sigorta şirketine kendi bilgileriyle fatura gönderilir.
- **3.0 ve 4.0:** Hastanın ödemesi ve sigorta ödemesi alınır, muhasebe kayıtlarına işlenir. Hoca, muhasebe kayıtlarının bu uygulamanın kendi içinde var olan bir veri ortamı olmadığını ama gerekli bir ortam olduğunu belirtti.

> **Ders sonrası not:** Ekrandaki şekilde 1.0 ile D1 arasındaki "Ücret" okunun ucu D1'e doğrudur. Hocanın anlatımına göre ise 1.0 ücret listesinden ücreti okur; anlatıma uygun gösterim büyük olasılıkla D1'den 1.0'a doğru olmalıdır.

**D1, D2, D3 neyi gösterir?** Veri tabanı, dosya gibi veri saklama ortamlarını, yani hakkında sürekli bilgi tutulan birimleri gösterir.

**Okların üzerinde ne yazar?** Veri saklama ortamından işleme, işlemden işleme ya da varlıktan işleme giden okların üzerinde giden-gelen veri yazar. Örneğin birinci işlemden ikinci işleme doğrulanmış ücret verisi gider; hastadan fatura hazırlamaya sigorta formu bilgisi gider. Hoca bir öğrencinin "gerçekleşen olaylar" cevabını düzeltti: olay değil, giden-gelen veri; girdi-çıktı da denebilir. Bir işlemin bir veri tabanından hangi veriyi aldığı, hangi veriyi kullandığı okların üzerine yazılır.

**Köşesi çizgili hasta kutusu:** Hasta varlığı daha önce kullanılmıştır; ikinci çizimdeki çizgi bunun aynı varlık olduğunu gösterir.

**Soru:** Bu diyagramın bağlam diyagramından farkı nedir? **Cevap (öğrenci ve hoca):** Önce taslak (bağlam) diyagram çizilir; birinci düzey diyagramda bu taslağın içindeki alt işlemlerin ayrıntısı verilir. Bağlam diyagramından sonra gelen, onun ayrıntılısı olan diyagramdır. Bir öğrenci bunu nesneye yönelik analizdeki bir diyagrama benzetince hoca "öyle değil, bir nevi akış diyagramı gibi" diye düzeltti.

## 10. İkinci düzey ayrıntılı veri akış diyagramı

İkinci düzey ayrıntılı VAD'da her bir işlem için daha fazla ayrıntı vermek amaçlanır. Bunun için birinci düzeyde verilen her işlem alt işlemlere bölünür ve ayrı bir diyagramı çizilir. Bu alt işlemlerin diğer işlemlerle, kendi aralarında ve varlıklarla nasıl bir ilişki içinde olduğu gösterilir.

Ekrandaki örnek 2.0 Fatura Hazırlama işleminin ikinci düzey diyagramıdır (ekrandan, 01:05:00). 2.0 büyük bir işlem kutusu olarak çizilmiş, içine üç alt işlem konmuştur:

| No | Alt işlem | Girdiler | Çıktılar |
|---|---|---|---|
| 2.1 | Hastanın Sigorta Durumunun İncelenmesi | Hasta'dan Sigorta Formu; 1.0'dan Doğrulanmış Ücret | 2.2'ye Sigorta ve Ücret Bilgisi |
| 2.2 | Listelenen Miktarla Faturayı Kıyaslama | 2.1'den Sigorta ve Ücret Bilgisi; D3 Sigorta Şirketleri'nden Sigorta Şirketi Adı ve Adresi | Sigorta Şirketi'ne Sigorta Faturası; 2.3'e Hastanın Ödemesi Gereken Tutar |
| 2.3 | Hastanın Ödemesi Gereken Tutarın Faturalanması | 2.2'den Hastanın Ödemesi Gereken Tutar; D2 Hastalar'dan Hasta Adresi | Hasta'ya Hasta Faturası |

Hocanın anlatımıyla: hastanın sigorta durumu incelenir, listelenen miktarla fatura kıyaslanır, hastanın ödemesi gereken fatura kaydedilip hastaya gönderilir.

### 10.1 Numaralandırma ve kapsam

2.0'ın alt işlemleri 2.1, 2.2, 2.3 olarak numaralanır; bu yüzden numara önemlidir. İkinci düzey diyagramı bütün işlemler için çizmek zorunlu değildir; yalnız gerçekten alt işlemi olan işlemler için ayrı bir VAD olarak çizilir.

### 10.2 Düzeyler arası tutarlılık

> **Hocanın vurgusu:** Birinci düzey ile ikinci düzey arasında mantıksal bağlılık ve tutarlılık olmalıdır.

- **İşlem tutarlılığı:** Birinci düzeyde 2.0 "Fatura Hazırlama" ise ikinci düzeyde 2.0'ın altındaki işlemler fatura hazırlamanın alt işlemleri olmalıdır.
- **Akış tutarlılığı:** Birinci düzeyde 2.0 hastadan ve 1.0'dan bilgi alıyor, D3 ve D2'den veri alıyor, hastaya ve sigorta şirketine bilgi gönderiyorsa, bütün bu giden-gelen oklar ikinci düzey diyagramda da aynı şekilde bulunmalıdır.

> **Ek bilgi (derste anlatılmadı):** Üst düzeydeki bir işlemin giriş ve çıkış akışlarının alt düzey diyagramda korunmasına literatürde "dengeleme" (balancing) denir. Dengesiz bir diyagram, ayrıntılandırma sırasında bir verinin kaybolduğunu ya da yeni bir verinin açıklamasız eklendiğini gösterir.

## 11. Araçlar ve VAD'ın yeri

CASE (Computer Aided Software Engineering) araçları, yani yazılım geliştirmeye yardımcı araçlar kullanılırsa, bu diyagramlar çizilirken yukarıdaki kurallara dikkat edilerek çizdirilir.

VAD genellikle yapısal yaklaşımın analiz modeli olarak kullanılır. Ama nesneye yönelik yaklaşımda da bazı şeyleri VAD ile ifade etmek gerekebilir.

**Soru:** Birinci ve ikinci düzey VAD'ları taslak olarak kolayca oluşturmak için önerdiğiniz bir program var mı? **Cevap:** Bunun için yazılımlar var, ama çoğu satın alınan programlar. Nesneye yönelik diyagramlar için Violet gibi kullanımı kolay açık kaynaklı yazılımlar daha fazladır; VAD için açık kaynaklı olanlar daha azdır. Hoca kolay kullanılacak açık kaynaklı programları araştırıp söyleyeceğini belirtti.

<!-- BELİRSİZ: Hocanın andığı bir program adı altyazıda "data analiz" diye geçiyor; hangi araç olduğu anlaşılamadı. -->

Hoca konunun bütünlüğü için ders kitabına da bakılabileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00; derste sözlü, 00:46:00): Ekrandaki diyagram bir doktor muayenesinde hastaya faturayı hazırlayan bilgi sistemini anlatıyor (Doktor → Muayene Kaydı; Hasta → Sigorta Formu; sistem → Hasta Faturası, Sigorta Faturası). Bu diyagramın adı nedir ve en önemli özelliği nedir?

> **Cevap (derste verildi):** Bağlam (context) veri akış diyagramıdır; taslak, özet ya da soyut diyagram da denir. Ayrıntı yoktur; sistemin dış varlıklarla arasında ne gidip ne geldiği gösterilir. Tek bir işlem vardır ve bu işlem sistemin genel adını taşır ("Faturalama Sistemi"). Bir öğrencinin "fonksiyonlar oklarla gösteriliyor" cevabını hoca düzeltti: oklar fonksiyon değil, giden-gelen veridir.

**Soru 2** (ekrandan, 00:55:00; derste sözlü, 00:55:01): Ekrandaki faturalama diyagramı ne diyagramıdır, işlemleri nelerdir?

> **Cevap (derste verildi):** Birinci düzey ayrıntılı veri akış diyagramıdır. İşlemler: 1.0 Muayene Kaydı İnceleme ve Ücret Hesabı, 2.0 Fatura Hazırlama, 3.0 Hasta Ödemeleri İşleme, 4.0 Sigorta Ödemeleri İşleme.

**Soru 3** (derste sözlü, 00:56:32–00:58:38): Diyagramdaki D1, D2, D3 neyi gösterir? Okların üzerindeki ifadeler nedir?

> **Cevap (derste verildi):** D1 Ücret Listeleri, D2 Hastalar, D3 Sigorta Şirketleri; veri tabanı, dosya gibi sürekli bilgi tutulan veri saklama ortamlarıdır. Okların üzerinde işlemler, varlıklar ve veri depoları arasında giden-gelen veri (girdi-çıktı) yazar; örneğin 1.0'dan 2.0'a "Doğrulanmış Ücret", hastadan 2.0'a "Sigorta Formu".

**Soru 4** (derste sözlü, 00:59:04 ve 01:00:16): Hasta kutusunun bir köşesine çizilen çizginin anlamı nedir?

> **Cevap (derste verildi):** Hasta varlığı diyagramda daha önce kullanılmıştır; çizgi, bunun yeni bir varlık değil aynı varlığın tekrar çizimi olduğunu gösterir.

**Soru 5** (ekrandan, 01:05:00; derste sözlü, 01:06:24): Ekrandaki diyagram ne diyagramıdır? Birinci düzey ayrıntılı diyagramdan farkı nedir?

> **Cevap (derste verildi):** İkinci düzey ayrıntılı veri akış diyagramıdır. Birinci düzeydeki bir işlem (burada 2.0 Fatura Hazırlama) alt işlemlerine ayrılarak daha ayrıntılı incelenir; alt işlemler 2.1, 2.2, 2.3 diye numaralanır. Alt işlemler üst işlemin alt işlemleri olmalı, üst işleme giren ve çıkan akışlar alt diyagramda da aynı biçimde bulunmalıdır.

**Soru 6** (derste sözlü, 00:10:00): Öğrenci ile ders arasındaki ilişkide bir öğrencinin bir dersi alması zorunlu mudur, sayı sıfır olabilir mi?

> **Cevap (derste verildi):** Zorunlu değildir. Bir öğrenci bir dönemde sıfır ders de, birden çok ders de almış olabilir; ilişki sıfır ya da çok olan seçimlik bir ilişkidir. Buna karşılık bir siparişin en az bir kalemi olmak zorundadır.

## Dersin Toparlaması

Ders iki parçadan oluştu. İlk parçada analizde hakkında bilgi tutulacak şeylerin ilişkileri ve özellikleri tekrar edildi: ilişkiler iki yönlüdür ve kardinalite ile zorunluluk/seçimlik bilgisi taşır; özellikler sistemin üreteceği çıktılara bakılarak belirlenir. Veri varlıklarının işlemlerden ayrı durduğu, nesnelerin ise veriyi ve metotları birlikte kapsülleyip mesajlarla çalıştığı görüldü. Müşteri–sipariş–kalem, bankacılık ve ilişki sınıflı ders kaydı örnekleri üzerinden kardinalite okuma alıştırması yapıldı.

İkinci parçada yapısal yaklaşımla gereksinim analizi modeli tanıtıldı: merkezde veri sözlüğü, çevresinde varlık ilişki diyagramı (veri tanımı), veri akış diyagramı (süreç spesifikasyonu) ve durum geçiş diyagramı (kontrol spesifikasyonu). Veri akış diyagramlarının aşamalı paketi öğrenci bilgi sistemi ve doktor muayenehanesi faturalama örnekleriyle işlendi: tek işlemli bağlam diyagramı, numaralı işlemler ve veri depolarıyla birinci düzey diyagram, bir işlemin alt işlemlerini gösteren ve üst düzeyle tutarlı olması gereken ikinci düzey diyagram.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
