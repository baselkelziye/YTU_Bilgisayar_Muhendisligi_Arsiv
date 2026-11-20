# Ders 1 Genişletilmiş Notu: Veriyi Tanımak: Veri Nesneleri, Öznitelik Türleri ve Veri Seti Türleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Tahmin Edici ve Tanımlayıcı Yöntemler
- 2. Bu Dersin Planı: Veriyi Tanımak
- 3. Başarılı Veri Madenciliği İçin Veriyle İlgili Konular
- 4. Veri Nesnesi ve Öznitelik
- 5. Dört Temel Öznitelik Türü
- 6. Nominal ve İkili Öznitelikler
- 7. Ordinal Öznitelikler
- 8. Interval ve Ratio Öznitelikler
- 9. Öznitelik Değerlerinin Özellikleri
- 10. Kategorik ve Sayısal Öznitelikler, Ayrık ve Sürekli Değerler
- 11. Veri Nesnesi Bir Vektördür
- 12. Veri Seti Türleri ve Doküman Verisi
- 13. Metin Madenciliği ve Konuşma Tanıma Üzerine Bir Ara Not
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: Tahmin Edici ve Tanımlayıcı Yöntemler

Ders, bir öğrencinin aykırı değer bulmanın tahmin edici mi yoksa tanımlayıcı mı olduğunu sormasıyla başladı. Hoca soruyu cevaplamadan önce bir önceki dersi hızlıca toparladı.

Veri madenciliğinin çıkış noktası şudur: Elimizde çok veri vardır ve veri önemlidir, ama ham veri tek başına bize pek bir şey ifade etmez. Bize gereken bilgidir. Veri madenciliği, veriden işimize yarayacak bilgiyi çıkarmaya çalışır.

Veri madenciliği yöntemleri temel olarak iki gruba ayrılır:

- **Tahmin edici (predictive) yöntemler:** Verimizde bir etiket (label) vardır ve biz bu etiketi tahmin etmeye çalışırız.
  - **Sınıflandırma (classification):** Etiketler ayrık (discrete) değerlerdir.
  - **Regresyon (regression):** Yine etiket vardır, ama tahmin edilen değer ayrık değil, sürekli (continuous) bir değerdir.
- **Tanımlayıcı (descriptive) yöntemler:** Etiket yoktur.

Tanımlayıcı yöntemlerde "etiket yok" ne demektir? Hoca bunu bir önceki derste verilen müşteri bölümleme (customer segmentation) örneğiyle açıkladı. Müşterilerinizi diyelim ki üç kümeye ayırmak istiyorsunuz. Ama elinizde "bir numaralı müşteri ikinci kümede, iki numaralı müşteri üçüncü kümede" diyen bir veri yoktur. Kümeler tamamen soyuttur; "birinci kümenin özellikleri şudur, ikincininki şudur" diye bir tanım da yapılmaz. Yalnızca "elimizdeki veriyi üçe ayıralım" deriz. Üç sayısı yalnız örnektir, küme sayısı üç olmak zorunda değildir.

Kümeleme (clustering) yöntemleri genelde iki gruba ayrılır: hiyerarşik ve hiyerarşik olmayan. Hiyerarşik olmayan yöntemlerde küme sayısını biz belirleriz; yani bu yöntemler bir parametreye ihtiyaç duyar.

### 1.1 Aykırı değer bulma neden tanımlayıcıdır?

Hoca öğrencinin sorusunu sınıfa yöneltti: Aykırı değerlerin (outlier) elimizde etiketi var mı? Diyelim ki "günde yüz kereden fazla şunu yapanlar aykırıdır" diyebiliyorsunuz. Eğer bu eşik değeri önceden bilseydiniz veri madenciliğine hiç gerek kalmazdı; veri tabanına bir sorgu yazıp "şunları getir" der, gelenleri aykırı diye işaretlerdiniz.

Bu yüzden aykırı değer bulma ya da anomali tespiti (anomaly detection) yaparken tanımlayıcı yöntemler kullanılır: Genel eğilim budur, şu kayıtlar ondan farklılaşmıştır, şüphelidir denir. Aykırı görünen bir değer her zaman gerçek bir anomali olmayabilir. Hoca hava verisi örneğini verdi: Yağış miktarını az, orta ve çok diye kümelediniz; bir gün diğerlerinden çok farklı bir değer çıktı. Belki o gün gerçekten öyle bir hava olmuştur. Sonuç olarak anomali tespitinde etiket yoktur ve yöntem tanımlayıcıdır.

## 2. Bu Dersin Planı: Veriyi Tanımak

Slaytın başlığı "Getting to Know Your Data" idi ve üç başlık listeleniyordu (ekrandan, 00:05:00):

- Data Objects and Attribute Types (veri nesneleri ve öznitelik türleri)
- Basic Statistical Descriptions of Data (verinin temel istatistiksel tanımları)
- Measuring Data Similarity and Dissimilarity (veri benzerliği ve benzemezliğinin ölçülmesi)

Hoca bu dersin amacını "datayı biraz daha tanımak" diye özetledi: Verimiz hangi türlerde olabilir, nasıl görünür? Sonraki derste bu veri üzerinde hangi ön işlemlerin yapılacağına bakılacağını söyledi. Önce veri nesneleri (örnekler) ele alınacak, sonra veri üzerindeki en temel istatistiksel işlemler, en sonunda da verinin benzerliğinin ve benzemezliğinin hangi ölçülerle ölçüldüğü. Bu kayıtta yalnız ilk başlık işlendi.

### 2.1 Veri hangi türlerde olabilir?

Hoca sınıfa verinin hangi türlerde olabileceğini sordu. Gelen cevaplar: sayılar (nümerik veri), metin, fotoğraf, resim, video, ses ve farklı sinyaller. Bir öğrenci şifreli veriyi önerdi; hoca bu derste şifreleme ve veri güvenliği konularıyla pek uğraşılmayacağını söyledi.

Veri setleri çok farklı kaynaklardan gelebilir: sosyal medya, dokümanlar, tamamen sayısal tablolar. Birkaç hafta sonra yöntemler görülmeye başlanacak ve verinin türü kullanılacak yöntemi doğrudan etkileyecektir.

## 3. Başarılı Veri Madenciliği İçin Veriyle İlgili Konular

Slaytta (ekrandan, 00:10:00) "Data-Related Issues for Successful Data Mining" başlığı altında dört konu vardı.

**Verinin türü (Type of Data):** Veri setleri birçok açıdan birbirinden farklıdır. Verinin türü, analiz için hangi tekniklerin kullanılabileceğini belirler.

**Verinin kalitesi (Quality of Data):** Veri çoğu zaman kusursuz değildir. Veri kalitesini artırmak, analiz sonucunun kalitesini de artırır. Hoca kendi çalıştıkları hava kirliliği verisinden örnek verdi: İstasyonlardaki ölçümler elle girilmiş; giren kişi ondalık noktayı koymadığı için 21.2 yerine 212 yazılmış, yani değer on katına çıkmış. Bir başka sorun da gürültüdür (noise): İnsan hatası olmadan, örneğin cihazın kalibrasyonundaki bir sorundan kaynaklanan bozulmalar. Verinin kalitesinden emin olmamız, değilse onu daha kaliteli hale getirmemiz gerekir.

**Ön işleme adımları (Preprocessing Steps):** Ham verinin analize uygun hale gelmesi için işlenmesi gerekir. Slayttaki iki amaç:

- Veri kalitesini artırmak (improve data quality).
- Veriyi seçilen veri madenciliği tekniğine daha iyi uyacak şekilde değiştirmek.

**Veriyi ilişkileri açısından analiz etmek (Analyzing Data in Terms of its Relationships):** Önce veri nesneleri arasındaki ilişkiler bulunur, sonra analizin geri kalanı nesnelerin kendisi yerine bu ilişkiler üzerinden yapılır. Pek çok benzerlik ve uzaklık ölçüsü vardır; doğru seçim verinin türüne ve uygulamaya bağlıdır. Hoca bunu hava verisiyle somutlaştırdı: Sıcaklık, nem ve yağış gibi verilerin bazıları birbiriyle ilişkili (korele) olabilir, bazılarının arasında hiç ilişki olmayabilir. Bu durumlarda ne yapılacağına ileride bakılacak.

## 4. Veri Nesnesi ve Öznitelik

Hangi türde olursa olsun (görüntü, sinyal, tablo) elimizdeki veri topluluğuna veri kümesi (data set) diyeceğiz.

Hoca konuyu "A Data Object" slaytındaki tabloyla anlattı (ekrandan, 00:15:00). Tablo bir vergi iadesi senaryosunu gösteriyordu:

| Tid | Refund | Marital Status | Taxable Income | Cheat |
|---|---|---|---|---|
| 1 | Yes | Single | 125K | No |
| 2 | No | Married | 100K | No |
| 3 | No | Single | 70K | No |
| 4 | Yes | Married | 120K | No |
| 5 | No | Divorced | 95K | Yes |
| 6 | No | Married | 60K | No |
| 7 | Yes | Divorced | 220K | No |
| 8 | No | Single | 85K | Yes |
| 9 | No | Married | 75K | No |
| 10 | No | Single | 90K | Yes |

Slaytın sağında iki eşleme yazıyordu: veri tabanı satırları → veri nesneleri (data objects); veri tabanı sütunları → öznitelikler (attributes).

### 4.1 Satırlar: veri nesneleri

Tablodaki her satır bir işlemi (transaction) ve o işlemin özelliklerini gösterir. Bir varlığı (entity) gösteren her satıra veri nesnesi (data object) denir. Kitaplarda ve videolarda aynı kavram için şu adlar da geçer:

- sample (örnek)
- instance (hocanın en çok kullandığı terim)
- example (daha az kullanılır)
- tuple
- object

Bu terimlerden biri geçtiğinde verinin bir satırı anlaşılmalıdır.

### 4.2 Sütunlar: öznitelikler

Sütunlar özniteliklerdir (attribute); Türkçede "öz nitelik" denir. Refund, Marital Status, Taxable Income birer özniteliktir. Aynı kavram için variable, field, feature ve characteristic terimleri de kullanılır. Bir nesne, farklı özniteliklerin birleşimiyle tanımlanır.

Öznitelik ile öznitelik değeri (attribute value) farklı şeylerdir. Öznitelik genellikle sütunun adıdır; değer ise o sütundaki hücrelerin aldığı değerdir. "Refund özniteliğinin değerleri nelerdir?" sorusunun cevabı "Yes ve No" olur.

Veriyle ilgili hemen her şey öznitelik olabilir. Ham veri toplanırken gerekli ya da gereksiz yüzlerce öznitelik toplanmış olabilir; bunların içinde sayılar da semboller de bulunur. Veri tabanına ne kaydedildiyse öznitelik odur.

## 5. Dört Temel Öznitelik Türü

Hoca dört temel öznitelik türünü tahtaya yazdı ve önce sınıfa "kategorik" ve "sayısal" kelimelerinin ne anlama geldiğini sordu. Bir öğrenci saç rengini örnek verdi, bir başkası "nitelik ve nicelik" dedi. Hoca anahtar kelimenin bu olduğunu söyledi: Nicelik sayısaldır; nitelik ise sayısal olmayan ama bir şey ifade eden değerlerdir. Kategorik değerler genellikle bir durumu ya da bir şeyin adını belirtir.

Slayttaki özet (ekrandan, 00:20:00):

- **Nominal:** Kategorik (nitel, qualitative). Kategoriler, durumlar ya da "şeylerin adları". Örnekler: saç rengi, medeni durum, meslek, kimlik numaraları, posta kodları.
  - Önemli bir nominal öznitelik türü **binary**: yalnız iki durumu (0 ve 1) olan nominal öznitelik.
- **Ordinal:** Kategorik (nitel). Değerlerin anlamlı bir sırası vardır, ama ardışık değerler arasındaki farkın büyüklüğü bilinmez. Örnekler: boyut = {small, medium, large}, notlar, askeri rütbeler.
- **Interval:** Sayısal (nicel, quantitative). Eşit büyüklükte birimlerden oluşan bir ölçekte ölçülür, değerlerin sırası vardır. Örnekler: Celsius ya da Fahrenheit sıcaklık, takvim tarihleri. Gerçek sıfır noktası yoktur, oranlar anlamlı değildir.
- **Ratio:** Sayısal (nicel). Doğal bir sıfır noktası vardır, oranlar anlamlıdır. Örnekler: Kelvin sıcaklık, uzunluk, sayımlar, parasal değerler.

Hoca ilk tanıtımda türleri şöyle bağladı. Nominal ve ordinal kategoriktir. Ordinali nominalden ayıran, değerlerin sıralanabilmesidir: Örneğin insanları çocuk, genç ve yaşlı diye üçe ayırırsanız bunları sıralayabilirsiniz, bu yüzden ordinaldir. Binary ise nominalin özel bir halidir. Sayısal tarafta interval, sayısal değerlerin eşit aralıklı bir şeye karşılık geldiği türdür: 5 ile 10 derece arasındaki fark 5 derecedir, 15 ile 20 derece arasındaki fark da yine 5 derecedir ve aynı şeyi ifade eder. Ratio ise sıfırı referans alan, değerlerin kat olarak ifade edilebildiği (üç katı, beş katı gibi) türdür.

## 6. Nominal ve İkili Öznitelikler

Nominal öznitelikler hakkındaki slayt (ekrandan, 00:25:00) şunları söylüyordu:

- Nominal özniteliğin değerleri semboller ya da şeylerin adlarıdır. Her değer bir kategori, kod ya da durum gösterir.
- Nominal öznitelikler kategorik öznitelikler diye de anılır.
- Değerlerin anlamlı bir sırası yoktur.
- Örnek: marital_status özniteliği single, married, divorced ve widowed değerlerini alabilir.
- Değerler sıralı ve nicel olmadığı için böyle bir özniteliğin ortalamasını (mean) ya da ortancasını (median) bulmak anlamsızdır. Ancak en sık görülen değeri, yani modu (mode) bulabiliriz.

Hoca, nominal bir özniteliğin değerlerinin genellikle önceden belli olduğunu, herkesin kafasına göre değer yazmadığını ekledi.

### 6.1 Öğrenci numarası ne tür bir özniteliktir?

Hoca sınıfa sordu: Öğrenci numaralarınız sayısal görünüyor, ama siz bunları ne olarak tutarsınız? Cevap: Sayısal değerler üzerinde toplama, çıkarma gibi işlemler yaparsınız; sayısal değerler arasında bir ilişki vardır. Öğrenci numaraları üzerinde ise hiçbir operatörle işlem yapılmaz. Numaranın içinde bir anlam olabilir (örneğin giriş yılı), ama bu da string işlemleriyle doğrudan okunabilir. Bu yüzden öğrenci numarası, TC kimlik numarası ve benzeri değerler genellikle nominal tutulur.

Medeni durum (bekar, evli, boşanmış, dul) örneğinde de değerler arasında bir sıralama yapılamaz. Nominal özniteliklerde ortalama ya da medyan gibi bir analiz yapılamaz; yapılabilecek tek şey "en çok tekrarlanan değer şudur" demektir. Mod, bir sayı dizisinde en çok tekrarlanan değerdir; istatistiksel tanımlar kısmında ayrıca ele alınacaktır.

### 6.2 Simetrik ve asimetrik ikili öznitelikler

İkili (binary) öznitelik 0 ve 1 gibi görünse de aslında "var/yok", "evet/hayır", "almak istiyorum/istemiyorum" gibidir; bu yüzden nominal bir özniteliktir. İkili öznitelikler iki türlüdür:

- **Simetrik ikili öznitelik:** 0 ile 1 arasında bir sıra ya da üstünlük anlamı yoktur; "1, 0'dan büyüktür" denmez. Örneğin cinsiyeti 0/1 olarak tutabilirsiniz, ama bu 0'ın küçük, 1'in büyük olduğu anlamına gelmez. 0 ile 1'in yerini değiştirseniz de bir şey değişmez.
- **Asimetrik ikili öznitelik:** Değerlerden biri bir şeyin varlığını gösterir. Örneğin tıbbi bir testte pozitif sonuç 1, negatif sonuç 0 olarak gösteriliyorsa, bu asimetrik bir ikili özniteliktir.

## 7. Ordinal Öznitelikler

Ordinal özniteliklerde sıra önemlidir. Bunlar da kategoriktir; sayıyla değil, kategorik değerlerle ifade edilirler. Fark şudur: Değerler arasında büyüklük-küçüklük gibi bir sıralama yapılabilir. Örnekler: içecek boyutu küçük/orta/büyük, menü boyutu.

Hoca ordinal değerlerde ortalamanın bir şey söylemediğini belirtti. Medyanın da (değerleri sıraladıktan sonra) bir şey söylemediğini, ama modun kullanılabileceğini söyledi: "En çok orta boy alınmış" gibi bir ifade anlamlıdır.

> **Ek bilgi (derste anlatılmadı):** Ders kitaplarında ordinal özniteliklerin merkezi eğilimi genellikle mod ve medyan ile gösterilir; değerler sıralanabildiği için ortadaki değer tanımlıdır. Ortalama ise ardışık değerler arasındaki uzaklık bilinmediği için anlamsızdır. Hocanın medyan hakkındaki ifadesi altyazıda kısa ve kopuk geçtiği için bu nokta derste tartışılmamış olabilir.

<!-- BELİRSİZ: 00:28:35-00:28:53 arası altyazıda medyan sorusuna verilen cevap kopuk ("Sıraladık. Yine bir şey söylemez."). Hocanın medyanı gerçekten anlamsız saydığı kesin değil. -->

## 8. Interval ve Ratio Öznitelikler

### 8.1 Interval öznitelikler

Interval ve ratio öznitelikler sayısal (numerik) değerlerdir. Interval özniteliklerde sayıları bir sayı doğrusu gibi düşünebiliriz: Bir, iki, üç eşit aralıklarla çizilir. Sayının ifade ettiği değer sayı doğrusu üzerinde eşit aralıklarla ifade edilebiliyorsa bu bir interval özniteliktir.

Slayt (ekrandan, 00:30:00) şunu söylüyordu:

- Interval öznitelikler eşit büyüklükte birimlerden oluşan bir ölçekte (scale of equal-size units) ölçülür. Değerler arasındaki farkı karşılaştırabilir ve sayısallaştırabiliriz.
- Örnek: Sıcaklık bir interval özniteliktir. 20 °C, 15 °C'den beş derece daha sıcaktır.
- Celsius sıcaklıklarının gerçek bir sıfır noktası (true zero-point) yoktur: 0 °C "sıcaklık yok" anlamına gelmez.
- Sıcaklık değerleri arasındaki farkı hesaplayabilsek de bir sıcaklık değerini diğerinin katı olarak ifade edemeyiz. Gerçek sıfır olmadan, örneğin 10 °C'nin 5 °C'den iki kat daha sıcak olduğunu söyleyemeyiz.
- Interval bir özniteliğin merkezi eğilimi mod, medyan (sıralı dizideki ortanca değer) ve ortalama ile gösterilebilir.

Hoca kitabın Celsius ve Fahrenheit örneği verdiğini söyledi: 15 ile 16 derece arasında da bir derece fark vardır, başka iki ardışık derece arasında da. Sayısal oldukları için ortalama ve medyandan da, moddan da bahsedebiliriz.

### 8.2 Ratio öznitelikler

Ratio öznitelikler de sayısaldır, ama oransal olarak ifade edilirler. Slayttaki örnek Kelvin'dir. Hoca Celsius'a çevirirken 273'ün kullanıldığını hatırlattı: Kelvin ölçeği mutlak sıfırı sıfır kabul eder ve sıcaklığı bu sıfıra göre kat olarak ifade eder. Celsius'ta "5 derece, ötekinin iki katı sıcaktır" diyemiyorduk; Kelvin için bunu söyleyebiliriz. Sayısal değerler size kat cinsinden bir şey ifade ediyorsa, özniteliğiniz ratio'dur.

> **Ders sonrası not:** Celsius ile Kelvin arasındaki fark tam olarak 273,15'tir ($T_K = T_C + 273{,}15$). Hoca yuvarlak olarak 273 dedi.

### 8.3 Çubuk örneği

Hoca tahtaya uzunlukları 1, 2, 3 ve 5 birim olan dört çubuk çizdi. Bu çubukların arasında kat ilişkisi vardır; ratio olarak bunları 1, 2, 3 ve 5 diye ifade edebiliriz. Sonra şunu ekledi: Bu çubukları santimetre cinsinden ölçtüğünüzü düşünün; örneğin birincisi 1,3 cm, ikincisi 2,6 cm çıktı. Hoca bu durumda ölçümü interval, 1, 2, 3, 5 olarak ifade edilen durumu ratio diye örnekledi; ikisi de sayısaldır.

> **Ders sonrası not:** Slaytta uzunluk ratio özniteliğine örnek olarak verilmiştir. Santimetre cinsinden ölçülen uzunluğun da gerçek bir sıfırı vardır (0 cm uzunluk yok demektir) ve 2,6 cm gerçekten 1,3 cm'nin iki katıdır. Bu yüzden santimetreyle yapılan ölçüm de büyük olasılıkla ratio sayılmalıdır; interval ile ratio arasındaki ayrımı belirleyen ölçüm birimi değil, sıfır noktasının gerçek olup olmadığıdır.

<!-- BELİRSİZ: 00:32:26-00:33:11 arası altyazı kopuk; hocanın bu örnekle tam olarak neyi kastettiği net değil. -->

### 8.4 Bu ayrım neden önemli?

Hoca sınıfa sordu: Neden sayısal öznitelikler ayrıca ratio ve interval diye ikiye ayrılıyor? Bir öğrenci sürekli/ayrık ayrımıyla ilgili bir şey önerdi; hoca bunun o ayrım olmadığını, örneğin Kelvin'in de ondalıklı değerler alabileceğini söyledi. Bir başka öneriye (verinin baştan nasıl toplanacağı) hoca şöyle cevap verdi: Veriyi çoğu zaman biz toplamayız; veri tabanı yöneticisi veriyi nasıl kaydettiyse öyle gelir ve veri bilimcisi olarak buna karışamayız.

Asıl neden şudur: Sonraki derste veri üzerinde ön işleme yapılacak. Değerleri normalize ettiğinizde ya da bir sayıyla çarptığınızda, bu değerlerin hangi türde olduğunu bilmeniz gerekir ki işlemi buna göre yapabilesiniz. Aksi halde yaptığınız işlem hataya yol açabilir.

## 9. Öznitelik Değerlerinin Özellikleri

"Properties of Attribute Values" slaytı (ekrandan, 00:35:00) öznitelik türünü, sahip olduğu özelliklere göre tanımlıyordu:

- Farklılık (distinctness): $=$, $\neq$
- Sıra (order): $<$, $>$
- Toplama (addition): $+$, $-$
- Çarpma (multiplication): $*$, $/$

Bu özelliklerin türlere dağılımı:

| Öznitelik türü | Sahip olduğu özellikler |
|---|---|
| Nominal | farklılık |
| Ordinal | farklılık ve sıra |
| Interval | farklılık, sıra ve toplama |
| Ratio | dört özelliğin hepsi |

Hoca bunu şöyle açıkladı. Nominallerde değerlerin hepsi birbirinden farklıdır; medyan ya da ortalama işe yaramaz, yalnız mod vardır ve yalnızca iki değerin aynı olup olmadığına bakılabilir. Ordinallerde zaten sıra vardır; büyük-küçük ya da önce-sonra ilişkisi ifade edilebilir. Interval değerlerde toplama ve çıkarma yapılabilir. Ratio değerlerde ise hem farklılık, hem sıra, hem toplama-çıkarma, hem de çarpma-bölme yapılabilir.

### 9.1 Celsius'ta neden çarpma yapılmaz?

Hoca bir soruyu kendisi sordu: Celsius tutulan bir veride toplama ve çıkarma yapıyoruz da neden çarpma ve bölme yapmıyoruz? Sınıftan gelen cevapla birlikte varılan sonuç şuydu: Çarpma, verinin özelliğini değiştirebilir ve bozabilir, çünkü sonuç fiziksel olarak anlamlı bir şeye karşılık gelmez. Bunun tek istisnası normalizasyondur: Veriyi örneğin 0-1 aralığına normalize ederken çarpma ve bölme yapılır, ama bütün değerler aynı miktarda çarpılıp bölündüğü için bir sorun çıkmaz.

> **Hocanın vurgusu:** Bu öznitelik türleri dönem boyunca sürekli konuşulacak. Örneğin bir ordinal değerin karar ağacına girdi olarak nasıl verileceği gibi sorularda hep bu türlere döneceğiz.

### 9.2 Türlerin örneklerle toparlanması

Hoca türleri bir kez daha örneklerle toparladı. Nominaller genellikle yalnız farklı isimlerden oluşur: posta kodu (zip code), saç rengi gibi. Ordinal değerler sıralanabilen (enumerate edilebilen) değerlerdir; bir şeye göre sıralayabiliyorsanız ordinaldir, bu sıranın illa büyüklük-küçüklük olması gerekmez. Interval tamamen sayısal değerler için kullanılır ve toplama-çıkarma bir şey ifade eder. Ratio ise oransal değerlerdir.

**Yaş ratio mudur, interval midir?** Hoca, slaytta yaşın neden ratio tarafına konduğunu sordu. Bir öğrenci sıfırın alınabileceğini söyledi. Hoca eksi yaş diye bir şey olmadığını ve "bu kişi diğerinden iki kat daha fazla yaşamıştır" ya da "onun yarısı kadar yaşamıştır" denebildiğini vurguladı. Yaşta toplama, çıkarma, çarpma ve bölmenin hepsi anlamlı bir sonuç verir; bu yüzden yaş ratio bir özniteliktir. Kütle, uzunluk ve sayımlar da aynı şekildedir; ama sonuçta bir değeri nasıl ifade ettiğiniz de önemlidir.

Ardından bir öğrenci sıcaklıkla ilgili bir soru sordu. Hocanın cevabından anlaşılan şuydu: Celsius'ta 5 ile 10 derece arasındaki fark ile 20 ile 25 derece arasındaki fark derece olarak eşittir, ama bu iki farkın "sıcaklık" olarak, yani oran olarak aynı şeyi ifade etmediği vurgulandı.

<!-- BELİRSİZ: 00:39:09-00:39:36 arası altyazıda öğrenci sorusu ve cevap büyük ölçüde bozuk (Whisper tekrarı); soru ve cevabın tam metni çıkarılamadı. -->

Hoca, kimlik numarası, öğrenci numarası ve TC kimlik numarası gibi değerlerin tam sayı gibi görünse de nominal (ya da duruma göre ordinal) tutulmasının daha mantıklı olduğunu tekrarladı.

## 10. Kategorik ve Sayısal Öznitelikler, Ayrık ve Sürekli Değerler

### 10.1 Nitel ve nicel öznitelikler

Slayttaki özet (ekrandan, 00:40:00):

- Nominal ve ordinal öznitelikler birlikte kategorik ya da nitel (qualitative) öznitelikler diye anılır.
  - Çalışan numarası (employee ID) gibi nitel öznitelikler sayıların özelliklerinin çoğundan yoksundur.
  - Sayılarla, örneğin tamsayılarla gösterilseler bile daha çok sembol gibi ele alınmalıdırlar.
  - Değerlerin ortalamasının bir anlamı yoktur.
- Interval ve ratio öznitelikler birlikte nicel (quantitative) ya da sayısal öznitelikler diye anılır.
  - Sayılarla gösterilirler ve sayıların özelliklerinin çoğuna sahiptirler.
  - Tamsayı değerli de olabilirler, sürekli de.
  - Ortalama ve standart sapma gibi sayısal işlemler anlamlıdır.

Hoca ortalama ve standart sapmanın tanımlarının istatistiksel tanımlar kısmında verileceğini söyledi.

### 10.2 Ayrık ve sürekli öznitelikler

Öznitelikler, aldıkları sayısal değerlere göre ayrıca ikiye ayrılır:

- **Ayrık (discrete):** Tamamen ayrık değerler alan özniteliklerdir. Örneğin öğrenci numaraları ayrıktır. Genellikle tamsayılarla (integer) gösterilirler.
- **Sürekli (continuous):** Genellikle gerçek dünya değerleridir; sıcaklık, uzunluk, uzaklık gibi. Tamsayı olmayan, ondalıklı gösterilebilen değerlerdir.

Hoca ardından sınıfa sordu: Gerçek dünyada ayrık olan nedir? Sıcaklık ayrık mıdır? Hocanın vardığı sonuç şuydu: Dünyadaki çoğu şey, neredeyse her şey süreklidir. İnsanlar bunu anlayabilmek için ayrıklaştırır. Örneğin çizgi film izleyen bir çocuk "bu karakter iyi mi kötü mü?" diye sorar; bu 0-1'dir. Bilgisayarın 0 ve 1'den anladığını söyleriz, ama aslında gelen sinyal sürekli değişir; bilgisayar onu bir eşik değerine (threshold) göre 0 ya da 1 olarak algılar.

Sürekli değerler özellikle bilgisayar biliminde ve matematikte işi zorlaştırır. Çocuk saymayı öğrenirken ondalık sayılarla başlamaz, parmaklarıyla sayar; parmaklar ayrık görünür. İnsan beyni çok karmaşık sayısal değerlerle uğraşmak istemediği için veriyi ayrık değerlerle ifade etmek işine gelir. Bu yüzden anketlerde yaş bile çoğu zaman tam değer olarak değil, "30-40 arası, 40-50 arası" gibi aralıklarla sorulur.

## 11. Veri Nesnesi Bir Vektördür

Bir öğrencinin vektörel verilerle ilgili sorusu üzerine hoca şunu anlattı: Veri madenciliğinde aslında hep vektörlerle uğraşacağız. Bir satırdaki öznitelik değerlerini birleştirdiğinizde elde ettiğiniz şey bir vektördür. Hoca bunu göstermek için veri nesnesi tablosuna geri dönüp ilk satırı (Yes, Single, 125K, No) ekranda çizerek işaretledi (ekrandan, 00:45:00).

Özellikle görüntüden ya da sinyalden elde edilen öznitelikler genelde vektör olur. Hoca bunu bir sinyal (örneğin ses) üzerinden açıkladı. Elimizde tek boyutlu bir sinyal vardır. Bu sinyal kaydedilirken genellikle sabit bir pencere boyutu (fixed window size) kullanılır; böylece vektör sabit boyutlu olur (onluk, yüzlük, binlik). Vektörün her elemanı aslında bir özniteliktir. Örneğin tabloya dört elemanlı bir vektör ekleyecekseniz tabloya dört yeni sütun eklersiniz: öznitelik 1, öznitelik 2, öznitelik 3 ve öznitelik 4.

### 11.1 Kategorik değerlerin yöntemlere verilmesi

Bir başka öğrenci, yöntemlere verirken kategorik değerlerin sayısala çevrilip çevrilmediğini sordu. Hoca bunun gerektiğini ve konunun sonraki derste ayrıntılı görüleceğini söyledi. Örnek olarak bir yapay sinir ağını verdi: Beş kategorili bir değeri ağa verirken, kategorilerin hepsi birbirine eşit olsun diye her kategori ayrı bir 0/1 girişle temsil edilir. Bu, kategorilere 1, 2, 3 gibi sıralı sayılar vermek demek değildir; hangi giriş nöronu uyarılıyorsa değer o kategoridir.

<!-- BELİRSİZ: 00:46:27-00:46:45 arası altyazıda kodlama örneği ("sıfır sıfır sıfır bir", "sıfır sıfır sıfır bir iki") kopuk; tahtada yazılan kodlamanın tam biçimi okunamadı, bu anın karesi yok. -->

> **Ek bilgi (derste anlatılmadı):** Bu kodlama yaygın olarak one-hot encoding diye bilinir. $k$ kategorili bir öznitelik $k$ ikili sütuna açılır ve her satırda yalnız bir sütun 1 olur. Böylece yönteme kategoriler arasında olmayan bir sıra bilgisi verilmemiş olur.

Hoca ayrıca yöntemlere verirken bütün kategorik değerlerin sayısala çevrileceğini, sayısal değerlerin de normalize edileceğini söyledi; çoğu yöntem girdileri bu şekilde kabul eder.

## 12. Veri Seti Türleri ve Doküman Verisi

Veri setleri farklı türlerde olabilir:

- **Kayıt verisi (record data):** Klasik olandır. Bir Excel tablosu da olabilir, bir veri tabanı tablosu da; hatta düz bir metin dosyası da olabilir. Hoca, doktorların hasta verisini geriye dönük tararken çoğu zaman veri tabanı yerine daha kolay geldiği için Excel kullandığını örnek verdi.
- **Veri matrisi (data matrix):** İki boyutlu olmak zorunda değildir, çok boyutlu olabilir. Veriyi hem görsel olarak gösterebildiğimiz hem de daha hızlı analiz edebildiğimiz bir yapıdır. Hoca bunun birkaç hafta sonra görüleceğini söyledi.
- **Graf ve ağlar (graph, network):** Veri yapılarından bilinen graf yapıları.
- **Sıralı veri (ordered data):** Video ya da zaman serisi gibi veriler.

### 12.1 Doküman verisi nasıl tutulur?

Hoca sınıfa sordu: Elinizde bir sürü doküman var, örneğin her Wikipedia sayfası bir nesne (instance); birinci satırda bir numaralı doküman, ikinci satırda iki numaralı doküman var. Bunu nasıl tutarsınız? Bir öğrenci sayfalar arası bağlantıları önerdi; hoca bunun hangi sayfanın hangisiyle ilişkili olduğunu göstereceğini, ama kendisinin dokümanın içinde yazanları istediğini söyledi.

Genelde şöyle yapılır: Bağlaçlar, edatlar ve çok geçen ama bir şey ifade etmeyen kelimeler temizlenir. Sonra kelimeler tek tek ele alınır ve her kelimenin kaç kez geçtiği sayılır.

"Document (Text) Data" slaytı (ekrandan, 00:50:00) bunu şöyle tanımlıyordu:

- Her doküman bir terim vektörü (term vector) olur.
  - Her terim vektörün bir bileşenidir (özniteliğidir).
  - Her bileşenin değeri, ilgili terimin dokümanda kaç kez geçtiğidir.
- Metin dokümanları, kelime frekansları sayılarak kayıt verisine çevrilir (document-term matrix).

Slayttaki doküman-terim matrisi:

| | team | coach | play | ball | score | game | win | lost | timeout | season |
|---|---|---|---|---|---|---|---|---|---|---|
| Document 1 | 3 | 0 | 5 | 0 | 2 | 6 | 0 | 2 | 0 | 2 |
| Document 2 | 0 | 7 | 0 | 2 | 1 | 0 | 0 | 3 | 0 | 0 |
| Document 3 | 0 | 1 | 0 | 0 | 1 | 2 | 2 | 0 | 3 | 0 |

Hoca tabloyu okudu: Birinci dokümanda team kelimesi üç kez geçmiş, coach kelimesi hiç geçmemiş, play kelimesi beş kez geçmiş.

Bir öğrenci kelime sırasının önemli olup olmadığını sordu. Hoca bu gösterimde sıranın tutulmadığını, ama aslında sıranın önemli olduğunu söyledi. Örneğin bir haberin spor mu, ekonomi mi olduğunu bulmak için on gruplu bir sınıflandırma yapacaksınız; içindeki kelimelerin sayılarından bunu bulmaya çalışabilirsiniz. Ama bu sistemler iyi çalışmaz. Bir kelimenin birçok anlamı olabilir; aynı kelime hem ekonomi hem spor haberinde geçebilir (eş sesli kelimeler). Bu yüzden kelimelerin ikili, üçlü olarak nasıl bir arada geçtiği ve birbirine uzaklığı önemlidir.

## 13. Metin Madenciliği ve Konuşma Tanıma Üzerine Bir Ara Not

Hoca metin madenciliğinin başlı başına ayrı bir konu olduğunu söyledi. Yeni sistemlerde, başka metinlerden bir kelime uzayı çıkarılır: Her kelime uzayda bir nokta olarak düşünülür ve kelimelere birbirine olan uzaklıklarına, ne kadar birlikte kullanıldıklarına göre sayısal değerler verilir. Yeni NLP sistemleri, bir metnin kelimelerinin bu uzayda nereye düştüğüne bakarak çalışır. Hoca bu konuların dördüncü sınıftaki NLP dersinde görülebileceğini söyledi.

Konuşma tanıma (speech recognition) örneğinde eski yaklaşım şuydu: Bir kelimeyi birçok kişi mikrofona okur; harflerin ve kelimelerin birbiri ardına gelme olasılıkları tek tek Hidden Markov modelleriyle modellenirdi. Ama bu yaklaşım dillerde çok iyi çalışmadı. Türkçede özne başta, yüklem sonda görünse de çok sayıda devrik cümle vardır; öğelerin yeri değişince cümlenin anlamı çoğu zaman bozulmaz. Yeni sistemler bir model kurmaya çalışmadan, çok sayıda örnekten derin öğrenmeyle doğrudan öğrenir ve yıllarca üzerinde çalışılan Hidden Markov model yaklaşımı büyük ölçüde terk edilmiştir. Chatbotlar ve ses tanıyan sistemler bu sayede çalışır hale gelmiştir.

Bu sistemler İngilizcede çok iyi, Türkçede daha zayıf çalışır. Nedeni şudur: Modeller ne kadar çok veriyle eğitilirse o kadar iyi çalışır. Üç doküman değil, milyonlarca dokümanla eğitmek gerekir; bu eğitim çok büyük sunucu kümelerinde haftalar sürer, bir üniversitenin imkanlarıyla yapılamaz. Hoca, Türkçe için eski bir kütüphane olan Zemberek'in kökleri bulup frekans saymak gibi işler yaptığını, sesli komut sistemlerinin eskiye göre daha iyi çalıştığını ama hâlâ tam olmadığını söyledi ve konunun dersin dışına çıktığını belirterek bu kısmı kapattı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:05:21): Aykırı değer bulma (outlier detection) tahmin edici bir yöntem midir, tanımlayıcı bir yöntem midir?

> **Cevap (derste verildi):** Tanımlayıcıdır. Aykırı değerlerin etiketi yoktur. Aykırılığı belirleyen eşik önceden bilinseydi veri madenciliğine gerek kalmaz, bir veri tabanı sorgusu yeterdi. Yöntem genel eğilimi bulur ve ondan farklılaşan kayıtları şüpheli olarak işaretler.

**Soru 2** (derste sözlü, 00:23:03): Öğrenci numaraları sayısal görünür. Bunları hangi tür öznitelik olarak tutarsınız, neden?

> **Cevap (derste verildi):** Nominal tutulur. Numaralar üzerinde toplama, çıkarma gibi hiçbir aritmetik işlem yapılmaz; numaranın içinde bir anlam varsa (giriş yılı gibi) o da string işlemleriyle okunabilir. TC kimlik numarası ve posta kodu da aynı şekildedir.

**Soru 3** (derste sözlü, 00:33:11): Sayısal öznitelikler neden ayrıca interval ve ratio diye ikiye ayrılır?

> **Cevap (derste verildi):** Veri üzerinde ön işleme sırasında normalizasyon, çarpma gibi matematiksel işlemler yapılır. Bu işlemleri doğru yapabilmek için değerlerin hangi türde olduğunu bilmek gerekir; aksi halde yapılan işlem hataya yol açabilir.

**Soru 4** (derste sözlü, 00:35:29): Celsius cinsinden tutulan bir veride toplama ve çıkarma yapılabiliyor da neden çarpma ve bölme yapılmıyor?

> **Cevap (derste verildi):** Celsius'ta gerçek sıfır yoktur; çarpma ve bölme verinin anlamını değiştirir ve bozar. Bütün değerlerin aynı oranda ölçeklendiği normalizasyon bunun dışındadır.

**Soru 5** (derste sözlü, 00:37:37): Slaytta yaş neden ratio öznitelikler arasında? Yaş oransal mıdır, aralık mıdır?

> **Cevap (derste verildi):** Oransaldır (ratio). Eksi yaş yoktur, sıfır anlamlı bir başlangıçtır ve "iki kat daha fazla yaşamış" ya da "yarısı kadar yaşamış" denebilir. Dört işlemin hepsi anlamlı sonuç verir.

**Soru 6** (ekrandan, 00:30:00): Slayta göre "10 °C, 5 °C'nin iki katı sıcaktır" denebilir mi?

> **Cevap (derste verildi):** Denemez. Celsius'un gerçek sıfır noktası yoktur, bu yüzden değerler oran olarak konuşulamaz.

> **Çözüm (derste verilmedi):** Aynı sıcaklıklar gerçek sıfırı olan Kelvin ölçeğinde 283,15 K ve 278,15 K'dir. Oranları $283{,}15 / 278{,}15 \approx 1{,}018$'dir, yani gerçek oran 2 değil, yaklaşık 1,018'dir (python ile hesaplandı).

**Soru 7** (derste sözlü, 00:41:15): Gerçek dünyada ayrık (discrete) olan şeyler nelerdir? Sıcaklık ayrık mıdır?

> **Cevap (derste verildi):** Sıcaklık süreklidir. Gerçek dünyadaki neredeyse her şey süreklidir (sinyal, görüntü, uzunluk). İnsanlar ve bilgisayarlar onları ayrıklaştırarak (eşik değeriyle 0/1'e çevirerek ya da aralıklara bölerek) anlar.

**Soru 8** (derste sözlü, 00:48:31): Elinizde çok sayıda doküman var (örneğin her Wikipedia sayfası bir nesne). Dokümanların içeriğini bir veri setinde nasıl tutarsınız?

> **Cevap (derste verildi):** Bağlaç ve edat gibi anlam taşımayan kelimeler atılır, her kelimenin dokümanda kaç kez geçtiği sayılır. Her doküman bir terim vektörü olur ve dokümanlar bir doküman-terim matrisine dizilir. Slayttaki örnekte birinci doküman için team = 3, coach = 0, play = 5'tir (ekrandan, 00:50:00).

## Dersin Toparlaması

Bu derste veriyi tanımanın ilk adımı atıldı. Bir veri setinde satırların veri nesneleri (sample, instance, tuple), sütunların öznitelikler (feature, variable, field) olduğu görüldü. Öznitelikler dört temel türe ayrıldı: nominal ve ordinal (kategorik, nitel) ile interval ve ratio (sayısal, nicel). Bu türler, izin verdikleri işlemlere göre iç içe geçer: nominal yalnız eşitliği, ordinal ek olarak sırayı, interval ek olarak toplama-çıkarmayı, ratio ise ek olarak çarpma-bölmeyi destekler. İkili öznitelikler nominalin özel bir halidir ve simetrik ya da asimetrik olabilir. Bunlardan bağımsız bir eksen olarak öznitelikler ayrık ya da sürekli olabilir. Ders, veri setlerinin kayıt, matris, graf ve sıralı veri gibi türleriyle ve metin verisinin doküman-terim matrisine çevrilmesiyle sona erdi.

Hoca bu öznitelik türlerinin dönem boyunca sürekli kullanılacağını vurguladı. Sonraki adımlarda verinin temel istatistiksel tanımlarına (ortalama, standart sapma vb.), benzerlik ve benzemezlik ölçülerine ve veri üzerinde yapılacak ön işlemlere (kategorik değerlerin sayısala çevrilmesi, normalizasyon) geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
