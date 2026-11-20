# Ders 4 Genişletilmiş Notu: Veri Ön İşleme: Veri Kalitesi, Eksik ve Gürültülü Veri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı
- 2. Veri Ön İşlemeye Giriş ve Veri Kalitesi
- 3. Eksik Veri ve Tekrarlayan Veri
- 4. Kalitenin Boyutları
- 5. Ön İşlemenin Ana Görevleri
- 6. Hatalı ve Eksik Verinin Kaynakları
- 7. Eksik Veriyle Başa Çıkma Yöntemleri
- 8. Gürültülü Veri ve Yumuşatma Teknikleri
- 9. Kutulama ile Yumuşatma Örneği
- 10. Yumuşatma, Veri Azaltma ve Kavram Hiyerarşileri
- Örnek Sorular

## 1. Önceki Dersin Tekrarı

Ders, önceki haftalarda görülenlerin kısa bir tekrarıyla başlar. Veri, veri nesnelerinden (data object) oluşur; bunlar tablonun satırlarıdır ve tuple diye de anılır. Her nesneyi tanımlayan özelliklere öznitelik (attribute) ya da feature denir; bunlar tablonun sütunlarıdır.

Öznitelikler veri tipine göre dörde ayrılmıştı. Kategorik tarafta nominal ve ordinal değerler vardır; ordinal değerler küçük, büyük gibi sıralanabilen değerlerdir. Sayısal tarafta ise aralık ve oran değerleri vardır; burada değerler arasında oransal bir şey söylenip söylenemeyeceğine bakılır. Veriyi analiz ederken ortalama, medyan ve çeyreklikler gibi çok temel istatistiklerin kullanılabileceği de görülmüştü.

Hoca bu dersin önceki derslere göre daha sözel, "hikaye gibi" olacağını, sayısal kısımların ve yöntemlerin sonraki haftalarda yavaş yavaş başlayacağını söyler.

## 2. Veri Ön İşlemeye Giriş ve Veri Kalitesi

Bu dersten itibaren veri madenciliğinin ilk adımına geçilir: veri ön işleme (data preprocessing). Slayttaki ana başlıklar şunlardır (ekrandan, 00:05:00):

- Veri kalitesi ve veri ön işlemenin ana görevleri (Data Quality and Major Tasks in Data Preprocessing)
- Veri temizleme (Data Cleaning)
- Veri bütünleştirme (Data Integration)
- Veri dönüştürme ve veri ayrıklaştırma (Data Transformation and Data Discretization)
- Veri azaltma (Data Reduction)

Günümüzdeki veritabanları hatalı, gürültülü, eksik ya da tam olarak bütünlüğü sağlanmamış veri içermeye çok müsaittir. Bunun nasıl olabileceği bir veritabanı örneğiyle açıklanır: tabloyu tanımlarken `NULL` değerlere izin verildiyse ya da bir değerin hangi koşulları sağlaması gerektiğini denetleyen bir trigger veya kural yazılmadıysa, veri nasıl toplandıysa öyle girer ve farklı, hatalı değerler oluşabilir.

İçinde eksik, yanlış, hatalı ya da hiç girilmemiş değerler olan veriye kalitesi düşük (low quality) veri denir. Veri kalitesi düşükse, ondan madencilik yapıp doğru bir bilgi elde etmenin pek bir yolu yoktur. Bu yüzden veri ön işleme ile veri biraz daha kaliteli hale getirilmeye çalışılır.

Peki kullanıcı veriyi yanlış girmiş ya da hiç girmemişse bu nasıl düzeltilir? Önceki haftada aykırı değerler (outlier) tanımlanmıştı: çeyrekler arası açıklığın (IQR) 1.5 katı dışında kalan değerler aykırı sayılıp çıkarılabiliyordu. Girilmemiş veriler için de bazı şeyler yapılabilir; örneğin bazı değerleri düzeltmek için kural ya da kod yazılabilir. Bu dersteki bütün bu işlemlerin ortak adı veri ön işlemedir ve amacı veriyi daha kaliteli hale getirmektir.

## 3. Eksik Veri ve Tekrarlayan Veri

Veri kalitesi problemleri arasında gürültü (noise), eksik veri ve tekrarlayan veri sayılabilir. Gürültü örneğin veriyi toplayan bir sensörün sürekli ürettiği bir bozulmadan gelebilir.

Slayttaki "Missing Values and Duplicate Data" başlığı şunları içerir (ekrandan, 00:10:00):

- Eksik değerlerin nedenleri
  - Bilgi toplanmamıştır (ör. insanlar yaşlarını ve kilolarını vermek istemez).
  - Öznitelik her duruma uygulanamaz (ör. yıllık gelir çocuklar için anlamlı değildir).
- Eksik değerlerle başa çıkma
  - Veri nesnelerini silmek (Eliminate Data Objects)
  - Eksik değerleri tahmin etmek (Estimate Missing Values)
  - Analiz sırasında eksik değeri yok saymak (Ignore the Missing Value During Analysis)
  - Olası bütün değerlerle, olasılıklarına göre ağırlıklandırarak değiştirmek
- Veri kümesi birbirinin tekrarı ya da neredeyse tekrarı olan nesneler içerebilir; bu, farklı kaynaklardan gelen veri birleştirilirken büyük bir sorundur.

Hoca eksik verinin nedenlerini günlük örneklerle açar. Bir form doldurulurken yalnız gerekli yerler doldurulmuş, diğerleri boş bırakılmış olabilir. Gelir sorulan bir formda 18 ya da 25 yaş altındaki birinin gelir bilgisi yoktur. Okul ya da eğitim durumu sorulduğunda da benzer boşluklar oluşabilir.

Tablonuzu bir Excel sayfası gibi düşünün: bazı hücreler boştur. En kolay çözüm silmektir, ama her zaman silinemez. Önce eksik değerlerin yüzdesine bakılır; yaklaşık %10 gibi bir eşik söylenir. Silinen şey nesnedir, yani bütün satırdır. Bu yüzden eksik değerlerin dağılımı da önemlidir: tüm veride eksik oranı %10 gibi görünse bile, her sütunun %10'u farklı farklı satırlarda eksikse, eksik içeren satırlar silindiğinde elinizdeki veri çok ciddi miktarda azalır. Eksik değerlere ortalama koymak ya da en yakın komşuların değerini koymak gibi başka yollar da vardır; bunlar ileride görülür.

Tekrarlayan verinin neden oluştuğu da sınıfa sorulur. Veritabanı kendiliğinden kopyalamaz ama yanlışlıkla bir kopyalama olabilir. Ayrıca bir kullanıcı sisteme farklı e-posta adresleriyle tekrar kayıt olabilir. Farklı yerlerde şubeleri olan bir mağaza düşünün: müşteri bir şubede kayıt olur, başka bir şubede yeniden müşteri kaydı açar ve aynı kişi iki kez görünür. Tekrarlayan veri çoksa veri bozulur; bu yüzden temizlenmesi gerekir.

## 4. Kalitenin Boyutları

Veriyi işlememizin nedenleri, kalitenin farklı boyutlarına karşılık gelir:

- Doğruluk: verinin doğruluğu artırılmak istenir.
- Tamlık: girilmemiş eksik veri tamamlanabiliyorsa tamamlanır, tamamlanamıyorsa bu verilerden kurtulunur. Çünkü bazı yöntemler eksik veriyle hiç çalışmaz.
- Güncellik: bazı değerlerin güncellenmesi gerekebilir. Örneğin tabloya yalnız yaş girildiyse ve elde üç yıllık veri varsa, yaşların güncellenmesi gerekir.
- Güvenilirlik: toplanan veriye gerçekten güvenilebilmelidir. Sensörden gelen veri tamamen, yüzde yüz bozuk bile olabilir.
- Anlaşılabilirlik: madencilik sonucunda elde edilen bilginin anlaşılabilir olması gerekir. Örneğin bir karar ağacı "şu öznitelik şundan küçükse şöyle olsun" diye bir kural verdiğinde, o değerlerin neye karşılık geldiği anlaşılmalıdır. Bunun için özniteliklerin açık ve net tanımlanmış olması gerekir: elinizdeki kocaman bir sayısal sütunun nereden geldiği, nasıl işlendiği, sıcaklıksa hangi birimle, uzunluksa nasıl ölçüldüğü bilinmelidir.

## 5. Ön İşlemenin Ana Görevleri

Slayttaki "Major Tasks in Data Preprocessing" başlığı dört görevi tanımlar (ekrandan, 00:15:00):

- Veri temizleme (data cleaning) verideki gürültüyü gidermek ve tutarsızlıkları düzeltmek için uygulanır: eksik değerleri doldurmak, gürültülü veriyi yumuşatmak, aykırı değerleri bulmak ya da çıkarmak, tutarsızlıkları çözmek.
- Veri bütünleştirme (data integration) birden çok kaynaktaki veriyi veri ambarı (data warehouse) gibi tutarlı bir veri deposunda birleştirir: birden çok veritabanının, veri küpünün ya da dosyanın bütünleştirilmesi.
- Veri azaltma (data reduction) veriyi toplayarak (aggregation), gereksiz öznitelikleri eleyerek ya da kümeleyerek veri boyutunu küçültür: boyut azaltma (dimensionality reduction), sayıca azaltma (numerosity reduction), veri sıkıştırma (data compression).
- Veri dönüştürme ve veri ayrıklaştırma (data transformation and data discretization), örneğin normalizasyon uygulanabilir. Normalizasyon, uzaklık ölçümü kullanan madencilik algoritmalarının doğruluğunu ve verimliliğini artırabilir. Kavram hiyerarşisi üretimi (concept hierarchy generation) de bu başlıktadır.

Hoca bu görevleri sözel olarak da özetler. Veri farklı farklı yerlerde olabilir; bütünleştirmede bu veriler birleştirilir. Veri işlenemeyecek kadar büyük olabilir; azaltmada hem boyut olarak hem sayısal işlemlerle verinin nasıl küçültüleceğine bakılır. Dönüştürmede normalizasyon gibi işlemler yapılır.

Kitaptaki bir şekilde bu görevler görselleştirilmiştir: temizlemede köpükler çıkar ve veritabanı "parıl parıl parlar", bütünleştirmede farklı yerlerdeki veriler birleşir, azaltmada verinin boyutu küçülür. <!-- BELİRSİZ: Bu şeklin karesi yok; anlatım yalnız altyazıdan alındı. -->

Temizlemede en büyük sorun her zaman eksik değerlerdir. Bunun dışında gürültü ve aykırı değerler vardır. Bunlar temizlendiğinde, verinin içindeki uyumsuzluklar ve bütünlüğü bozan değerler de elenmiş olur.

## 6. Hatalı ve Eksik Verinin Kaynakları

Veritabanı derslerinde her şey tanımlıdır: tabloyu şöyle oluştur dersiniz ve tablo öyle oluşur. Peki neden eksik ya da hatalı veri gelir? Sınıftan gelen cevaplarla ve hocanın örnekleriyle şu kaynaklar sayılır:

- İnsan hatası.
- Bilerek yanlış girilen bilgi: insanlar internete her zaman doğru bilgi girmez. Özellikle kişisel bilgilerini, örneğin doğum tarihini, doğru vermek istemeyebilirler.
- Cihaz hatası: özellikle sensörden gelen verilerde gürültü çoktur.
- Formlarda yalnız gerekli (required) alanların doldurulması: diğer alanlar büyük olasılıkla boş bırakılır ve eksik veri oluşur.

Gürültü ya da aykırı değer gibi görünen tutarsızlık örnekleri:

- Maaşın `-10` girilmesi.
- Yaşı 42 olan birinin doğum yılının 2010 görünmesi.
- Girilen adres ya da posta kodu ile yaşanılan ilin birbirini tutmaması; kişi o an doldurmak için rastgele bir şey yazmış olabilir.
- Doğum tarihi seçerken takvimde gezinmek zor olduğu için herkesin 1 Ocak'ı işaretlemesi.

Slayttaki "Incomplete (Missing) Data" başlığı (ekrandan, 00:20:00): veri her zaman mevcut değildir; örneğin satış verisinde birçok satırın müşteri geliri gibi birçok özniteliği kayıtlı değildir. Eksik verinin nedenleri:

- Donanım arızası (equipment malfunction)
- Diğer kayıtlı verilerle tutarsız olduğu için silinmiş olması
- Yanlış anlama nedeniyle girilmemiş olması
- Bazı verilerin giriş anında önemli görülmemesi
- Verinin geçmişinin ya da değişikliklerinin kaydedilmemesi

Slayta göre eksik verinin çıkarımla (inference) bulunması gerekebilir.

Hoca donanım ya da yazılım hatasına kendi deneyiminden bir örnek verir: kurdukları bir sistemin bir sütunu birkaç hafta boyunca hep sıfır olarak topladığını anlatır; değerler veritabanına yazılırken ondalık kısımları kaybolmuştur. <!-- BELİRSİZ: Altyazı bozuk ("intijra hepsini kest etmiş"); büyük olasılıkla değerler tam sayıya (integer) dönüştürülmüş. --> Yeterince test edilmediği için bu hata gözden kaçmıştır; yani hata yazılımcıdan da kaynaklanabilir.

Yanlış anlama örneği olarak tarih biçimi verilir: Amerikan sisteminde önce ay, sonra gün, sonra yıl yazılır. Kullanıcı `07-02` girerken Şubat ile Temmuz'u karıştırmış olabilir.

## 7. Eksik Veriyle Başa Çıkma Yöntemleri

Slayttaki "How to Handle Missing Data?" başlığı yöntemleri listeler (ekrandan, 00:25:00):

- Satırı yok saymak (ignore the tuple): genelde sınıflandırmada sınıf etiketi eksikse yapılır; öznitelik başına eksik değer yüzdesi çok değişiyorsa etkili değildir.
- Eksik değeri elle doldurmak: zahmetli ve çoğu zaman uygulanamaz.
- Otomatik doldurmak:
  - global bir sabitle: ör. "unknown", yeni bir sınıf
  - özniteliğin ortalamasıyla
  - aynı sınıfa ait bütün örneklerin öznitelik ortalamasıyla (daha akıllıca)
  - en olası değerle: Bayes formülü ya da karar ağacı gibi çıkarıma dayalı yöntemlerle. Bu yaygın bir stratejidir; diğer yöntemlere göre eksik değeri tahmin etmek için eldeki veriden en çok bilgiyi kullanır.

### 7.1 Satırı silmek

En kolay yol, eksik değerin olduğu satırı doğrudan silmektir. Eksik veri az miktardaysa bu uygulanabilir. Ama eksik veri çoksa ve veriniz azsa bu, verinin bütünlüğünü epey bozar.

### 7.2 Elle doldurmak

Bazen elle doldurmak mümkündür. Hoca tıbbi veriyle çalışırken karşılaştığı bir durumu örnek verir: radyoloji görüntülerinde teşhisin doğru olup olmadığı şüpheli olan kayıtları doktorlar tekrar okuyup verisini düzeltebilir. Veri sizin için çok önemliyse ve fazla zaman almadan yapılabilecekse, örneğin metin madenciliğinde ya da elinizde görüntü gibi kaynağın kendisi duruyorsa ve uzman bilgisine ihtiyaç varsa, elle düzeltme yapılabilir.

### 7.3 Sınıf etiketi eksikse

Sınıflandırma yapılıyorsa ve eksik olan değer sınıf etiketiyse, bunu ortalamayla doldurmak işi ciddi bozar. Sınıflandırmada etiket bilgisi çok önemlidir. Bu yüzden aşağıdaki doldurma yöntemleri etiket için değil, diğer öznitelikler için geçerlidir.

### 7.4 Global sabit

Bazı araçlar boş hücreye doğrudan `NULL` yazar. Kategorik değerler varsa "bilinmiyor" gibi yeni bir kategori oluşturulup boşluklar onunla doldurulabilir. Bu sayısal özniteliklerde yapılmaz, yalnız kategorik özniteliklerde yapılır.

### 7.5 Ortalama

Sayısal özniteliklerde ikinci yol ortalamadır. Özniteliğin ortalaması uygun düşüyorsa ve eksik veri azsa ortalama yazılabilir. Bir varyantı daha vardır: veri zaman içinde toplanmışsa, bütün veri kümesinin ortalaması yerine eksik değerin kendinden önceki ve sonraki değerlerin ortalaması konabilir.

### 7.6 Sınıf ortalaması

Sınıflandırma yapılacaksa, her sınıfa ait o öznitelikteki ortalama bulunur ve eksik yere konur. Örneğin A ve B iki sınıf, uzunluk da bir öznitelik olsun. Sınıfı A olan satırlardaki eksik uzunluk değerlerine, A sınıfındaki mevcut uzunlukların ortalaması konur. Sınıfı B olanlara da B sınıfındaki mevcut uzunlukların ortalaması konur.

### 7.7 En olası değer

Diğer özniteliklerin çoğu mevcutsa, Bayes çıkarımıyla ya da karar ağacıyla eksik değer tahmin edilebilir. Örneğin bir kullanıcının cinsiyeti, boyu, kilosu gibi bilgileri var, bir değeri eksik olsun. Yöntem veritabanında bu satıra benzeyen satırlara bakar ve istatistiksel olarak boş değerin ne olabileceğini tahmin eder. Bunu her boş değer için tek tek yaptığı için boşlukları daha akıllıca doldurur: ortalama koymak gibi bütün eksiklere eşit davranmaz, her birine farklı bir değer koymaya çalışır. O satıra benzeyen profilde başka satırlar varsa, eksik değeri onlarınkine yakın bir değerle doldurur. Hoca karar ağaçları ve Bayes çıkarımı görüldükten sonra bunun daha iyi oturacağını söyler.

Sınıftan bir öğrencinin verdiği benzetme de tartışılır: film öneri sistemleri, kullanıcının izleme alışkanlıklarına bakarak izlemediği bir filme vereceği puanı tahmin eder. Hoca bunun da aynı mantıkta olduğunu söyler: "bu kişi bu filmi izleseydi kaç verirdi" sorusu, diğer değerlere bakılarak doldurulan bir eksik değerdir.

### 7.8 Eksik veri çok fazlaysa

Eksik değerler çok fazlaysa iş başkadır. Verinizin, örneğin bir sütunun yarısı yoksa, diğer yarının ortalamasını koymak iyi bir çözüm değildir; sistem iyi eğitilmez. Bunun için yeni yöntemler çıkmıştır: eksik değeri tahmin etmek yerine sistemin eldeki veriye benzeyen yeni, yapay (sentetik) veri üretmesi gibi. Hoca bu bağlamda GAN benzeri üretici modellere değinir. <!-- BELİRSİZ: Altyazıda "yeni gunlar" geçiyor; büyük olasılıkla GAN'lar kastediliyor. --> Veri kümesinin boyutunu artırmak ve küçük veriyle çalışmak için ileride "leave one out" gibi yöntemler de görülecektir.

## 8. Gürültülü Veri ve Yumuşatma Teknikleri

Slayttaki "Noisy Data and How to Handle Noisy Data?" başlığı (ekrandan, 00:30:00):

- Gürültü (noise): ölçülen bir değişkendeki rastgele hata ya da varyans.
- Aykırı değerler gürültüyü temsil edebilir.
- Fiyat (price) gibi sayısal bir öznitelik verildiğinde, gürültüyü gidermek için veri nasıl "yumuşatılır" (smooth)?
- Veri yumuşatma teknikleri:
  - Kutulama (binning): önce veri sıralanır ve eşit frekanslı kutulara bölünür; sonra kutu ortalaması, kutu medyanı, kutu sınırları vb. ile yumuşatılır.
  - Regresyon: veri regresyon fonksiyonlarına uydurularak yumuşatılır.
  - Kümeleme (clustering): aykırı değerler bulunur ve çıkarılır.
  - Bilgisayar ve insan denetiminin birlikte kullanılması: şüpheli değerler bulunur ve insan tarafından kontrol edilir (ör. olası aykırı değerlerle ilgilenmek).

### 8.1 Gürültü nedir, nasıl anlaşılır?

Gürültü rastgele olan hatadır; sesteki cızırtı gibi düşünülebilir. Gürültünün nasıl anlaşılacağı sınıfa sorulur. Dağılıma bakmak önerilir; ama hoca elimizdeki bütün verilerin standart bir Gauss dağılımı izleyeceğine dair bir kural olmadığını, bu yüzden gürültünün dağılımdan her zaman çıkarılamayacağını söyler.

Sinyal üzerinde çalışılıyorsa gürültüyü eleyen farklı filtreler vardır; bunlar sinyal işleme derslerinde görülür. Görüntüde medyan filtresi ya da tuz-biber (salt and pepper) gürültüsü için filtre uygulanır. Ama verinin nereden geldiği her zaman iyi bilinmez: sensörden mi, kullanıcının girdiği veriden mi geldiği belli olmayabilir. Bu durumda özellikle sayısal veriler için veri yumuşatılır (smoothing).

### 8.2 Yumuşatmanın bedeli

Yumuşatmak, zikzaklı veriyi biraz daha düz hale getirmek, basitleştirmektir. Görüntü benzetmesi: piksellerin arasında uç değerler varsa, bir filtreyle ortalama alınıp onların yerine konur. Göz bunu pek fark etmez ama hassas değerler kaybolur. O uç değerler aslında önemli olabilir. Sayısal veride de yumuşatma yapılırken hassas değerler kaybedilir.

### 8.3 Regresyon ile yumuşatma

Regresyonda elimizdeki veriye bir eğri ya da doğru uydurulur. Doğrusal regresyon yapılırsa veriye bir doğru oturtulur. Sonra her noktanın değeri, doğru üzerindeki karşılığıyla değiştirilir: $x_1$ noktasının değeri $y_1$ ise, $y_1$ yerine doğrunun $x_1$'deki değeri konur. Böylece bütün noktalar sanki bir doğru üzerindeymiş gibi olur. Bu, gürültüyü azaltmanın farklı bir yoludur. <!-- BELİRSİZ: Hoca bu kısmı tahtada ya da ekranda çizerek anlattı; o anın karesi yok ve altyazı bozuk. Çizimdeki eksen ve nokta adları kesin değil. -->

Regresyondan sonra aykırı değerler de bulunabilir: noktaların doğruya ortalama uzaklığı hesaplanır, bu ortalama uzaklığın örneğin bir buçuk katından daha uzak olan noktalar atılır.

### 8.4 Kümeleme ile aykırı değer bulma

Benzer veriler kümelenir. Kümelerin çok dışında kalan değerler aykırı değerlerdir ve atılabilir. Hoca dersin devamında, tek elemanlı ya da az elemanlı kümelerin de aykırı değer diye silinebileceğini ekler.

Bütün bu yöntemler için matematiksel işlemleri elle yapmak gerekmez: hazır araçlar ya da kütüphaneler bu yöntemleri içerir. Asıl zorluk çok fazla yöntem olmasıdır; hangi yöntemin kullanılacağını bilmek gerekir.

> **Hocanın vurgusu:** Hatalı olabilecek değerler bulunduktan sonra doğrudan silinmez. Bir uzmana bunun aykırı değer mi yoksa gerçek değer mi olduğu sorulur.

### 8.5 Bilgisayar ve insan denetimi

Sistem şüpheli değerleri bulur, insan bunlara bakıp aykırı değer olup olmadığına karar verir; buna göre değer silinir ya da veritabanında kalır. Bu yaklaşım, özellikle verinin az ve önemli olduğu durumlarda çok kullanılır.

Hoca bir firmayla yürüttükleri bir projeden örnek verir. Ellerinde az veriyle eğitilmiş, yaklaşık %80 doğrulukla çalışan bir model vardır. Yeni bir veri kümesinin işlenmesi gerekir. Bütün veriyi insanların baştan işaretlemesi yerine bu model çalıştırılır; insanlar yalnız sistemin tereddütte kaldığı, hata payının yüksek olabileceği örnekleri kontrol eder.

Tıbbi veri ve kredi kartı dolandırıcılığı (fraud) gibi alanlarda bu daha da önemlidir. Dolandırıcılık örnekleri belki milyonda bir işlemde görülür; böyle bir örnek aykırı görünüyor diye hemen silinemez. Bu verileri kaybetmemek için insanın tekrar devreye girip elle işaretlemesi gerekir.

Kitle kaynaklı işaretleme (crowdsourcing) de anlatılır. Örneğin Amazon Mechanical Turk'te işaretlenen her öğe başına para alınır; sistem bir resim gösterip "buradaki ağaca tıkla" ya da "bu şu mudur" gibi küçük görevler verir. Biri 10, biri 20 tane işaretler ve herkesin işaretlediğinden kocaman bir veri ortaya çıkar. Tek bir kişinin ya da iki üç kişinin işaretlemesinin zor olduğu büyük verilerde bu yöntemle veri toplanır. Bu verilerde eksik değer pek olmaz ama çok sayıda aykırı değer olabilir: bir işaretleyen tamamen kötü işaretlediyse veriyi bozabilir. Bu tür örneklerin de aynı yöntemlerle bulunup tekrar insan eliyle işaretlenmesi gerekebilir.

**Soru:** Bir öznitelikte (örneğin basınçta) ani bir değişim önemliyse ne yapılır? <!-- BELİRSİZ: Öğrencinin sorusu altyazıda yok; cevaptan kurulmuştur. -->
**Cevap:** O basınç değişimi sizin için önemliyse, onu aykırı değer diye silmezsiniz. İnsan denetiminde değerlere tek tek bakıp, örneğin basıncın gerçekten yükseldiğini başka bir kaynaktan da kontrol ederek "bunu silme" dersiniz; bu insan denetimidir. Eğer "basınç özniteliğinde hiç aykırı değer tespiti yapma" diye bir kural koyarsanız, bu da kural tabanlı bir yaklaşım olur.

## 9. Kutulama ile Yumuşatma Örneği

Kutulamada (binning) önce veri sıralanır, sonra kutulara (bin) bölünür. Ardından her kutuda yumuşatma yapılır: kutu ortalaması ile, kutu medyanı ile ya da kutu sınırları ile (her değer, kutunun başındaki ve sonundaki değerden hangisine daha yakınsa onunla değiştirilir).

> **Ders sonrası not:** Hoca yumuşatmanın "dört tane kuralı" olduğunu söyledi ama ortalama, medyan ve sınır olmak üzere üç yöntem saydı. Slaytta da bu üç yöntem ve "etc." vardır (ekrandan, 00:40:00).

Slayttaki örnek "Binning Methods for Data Smoothing: Example" (ekrandan, 00:40:00):

- Fiyat (dolar) için sıralı veri: `4, 8, 15, 21, 21, 24, 25, 28, 34`. Toplam 9 sayı vardır.
- Kaç kutu kullanılacağına kullanıcı karar verir. Burada eşit frekanslı üç kutu seçilmiştir:
  - Kutu 1: `4, 8, 15`
  - Kutu 2: `21, 21, 24`
  - Kutu 3: `25, 28, 34`

**Kutu ortalamasıyla yumuşatma.** Her kutunun ortalaması bulunur ve kutudaki bütün değerler bununla değiştirilir.

$$\frac{4+8+15}{3}=\frac{27}{3}=9,\qquad \frac{21+21+24}{3}=\frac{66}{3}=22,\qquad \frac{25+28+34}{3}=\frac{87}{3}=29$$

Sonuç: Kutu 1: `9, 9, 9`; Kutu 2: `22, 22, 22`; Kutu 3: `29, 29, 29`. Yani 4 artık 9 olur, 8 de 9 olur, 15 de 9 olur. Hassas değerler kaybolur, ama verinin içindeki olası gürültü de elenmiş olur.

**Kutu medyanıyla yumuşatma.** Her kutunun medyanı bulunur: `4, 8, 15` için medyan 8, `21, 21, 24` için 21, `25, 28, 34` için 28. Sonuç: Kutu 1: `8, 8, 8`; Kutu 2: `21, 21, 21`; Kutu 3: `28, 28, 28`.

**Kutu sınırlarıyla yumuşatma.** Her kutunun sınırları en küçük ve en büyük değeridir. Kutu 1'in sınırları 4 ve 15'tir. 4 zaten sınırdır, olduğu gibi kalır. 8 için 4'e ve 15'e uzaklık karşılaştırılır: $|8-4|=4$, $|15-8|=7$ (ara adım eklendi); 8, 4'e daha yakın olduğu için 4 ile değiştirilir. 15 sınırdır, kalır. Kutuda 13 olsaydı 15'e daha yakın olduğu için 15 ile değiştirilirdi. Aynı işlem diğer kutulara uygulanır: Kutu 2'de 21'ler alt sınırdır, 24 üst sınırdır; Kutu 3'te 28 için $|28-25|=3$, $|34-28|=6$ olduğundan 25 seçilir (ara adım eklendi). Sonuç: Kutu 1: `4, 4, 15`; Kutu 2: `21, 21, 24`; Kutu 3: `25, 25, 34`.

Bu üç sonuç python ile yeniden hesaplanmış ve slayttaki değerlerle aynı çıkmıştır.

### 9.1 Kutulama nerede işe yarar?

Bu küçük örnekte kutulama anlamsız gibi görünebilir. Asıl faydası çok sayıda farklı değer olan özniteliklerde ortaya çıkar. Örneğin kilo girilirken biri 55.8, biri 60, biri 62.3 girmiş; ondalıklı bir sürü farklı değer vardır. Bu değerleri 20 kutuya ayırırsanız, elinizde toplam 20 farklı kilo değeri kalır; örneğin 60 ile 64 kilo arasındaki değerler tek bir değerle temsil edilir. Birbirine çok yakın ama farklı değerlerden kurtulmuş olursunuz.

Sıralama sayesinde çok nadir görülen değerler de diğerlerine yaklaştırılır. Örneğin kilosu 170 olan biri aykırı değer değildir, kilosu gerçekten 170 olabilir; ama çok nadir görülen bu değer kutulamayla diğerlerine biraz yaklaştırılır. Aykırı değerlerin dizinin başında ya da sonunda olması da gerekmez, arada da olabilir.

Bedeli yine aynıdır: yumuşatırken gerçek değerdeki hassasiyet kaybedilir.

### 9.2 Kutulama ile ilgili sorular

**Soru:** Kutulama farklı kişilerin değerlerini birbirine yaklaştırır; bu bir sorun değil mi? <!-- BELİRSİZ: Öğrencinin sorusu altyazıda bozuk; soru, hocanın cevabından kurulmuştur. -->
**Cevap:** Önce kutulama tablodaki bütün değerlere birden uygulanmaz; her öznitelik, yani her sütun için ayrı ayrı yapılır. Bu işlem gerçekten farklı kişileri birbirine yaklaştırır: örneğin 70 kilo ile 60 kilo, 180 boy ile 185 boy olan iki kişi bu işlemden sonra aynı değerlere, uzayda aynı noktaya gelebilir. Ama istenen de budur. Veri çok dağınık ve çok boyutludur; nihai amaç ya sınıflandırma yapıp bu kişilerin aynı sınıfa girip girmediğini bulmak, ya da kümeleme yapıp onları aynı kümeye koymaktır. Bu yüzden benzer örnekleri yaklaştırmak işe yarar. <!-- BELİRSİZ: Altyazıda boy değerleri "80" ve "85" olarak geçiyor; büyük olasılıkla 180 ve 185 kastedildi. -->

**Soru:** Kutulama yalnız eğitim verisine mi uygulanır? <!-- BELİRSİZ: Öğrencinin sorusu altyazıda yok; cevaptan kurulmuştur. -->
**Cevap:** Hayır, aynı işlem test verisine de uygulanmalıdır. Örneğin eğitim verisinde 4 ile 15 arasındaki değerler 9'a dönüştürüldüyse, test verisinde 14 diye bir değer verilmez, 9 verilir. Aksi halde sonraki işlemler karışır ve ciddi hata oluşur.

## 10. Yumuşatma, Veri Azaltma ve Kavram Hiyerarşileri

Slayttaki "Data Smoothing" başlığı (ekrandan, 00:45:00):

- Veri yumuşatma yöntemlerinin çoğu aynı zamanda ayrıklaştırma içeren veri azaltma yöntemleridir.
  - Örneğin kutulama teknikleri bir öznitelikteki farklı değer sayısını azaltır.
  - Bu, sıralı veri üzerinde sürekli değer karşılaştırması yapan karar ağacı gibi mantık tabanlı madencilik yöntemleri için bir tür veri azaltmadır.
- Kavram hiyerarşileri, veri yumuşatmada da kullanılabilen bir veri ayrıklaştırma biçimidir.
  - Örneğin fiyat için bir kavram hiyerarşisi, gerçek fiyat değerlerini ucuz, orta fiyatlı ve pahalı olarak eşleyebilir; böylece madencilik sürecinin işleyeceği değer sayısı azalır.

Hoca bunu önceki konularla bağlar. Yumuşatma için kutulama, regresyon ve kümeleme görülmüştü. Kümelemede kümelerin dışında kalan ya da tek elemanlı veya az elemanlı kümelerdeki noktalar aykırı değer diye silinebilir. Bu yöntemler veri azaltmada da kullanılır. Kilo örneğine dönülürse, bin farklı kilo değeri varken kutulama yapıldığında farklı değer sayısı kutu sayısına iner. Böylece sayısal değerler bile bir tür kategoriye yaklaştırılmış olur. Kavram hiyerarşisinin ne olduğu ise dersin sonuna doğru hiyerarşik bir örnekle ayrıca görülecektir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Fiyat (dolar) için sıralı veri `4, 8, 15, 21, 21, 24, 25, 28, 34` veriliyor. Veriyi eşit frekanslı üç kutuya bölün ve kutu ortalamaları, kutu medyanları ve kutu sınırlarıyla yumuşatın.

> **Çözüm (derste verildi):** Kutular `{4, 8, 15}`, `{21, 21, 24}`, `{25, 28, 34}`.
> Ortalama ile: `9, 9, 9`; `22, 22, 22`; `29, 29, 29`.
> Medyan ile: `8, 8, 8`; `21, 21, 21`; `28, 28, 28`.
> Sınır ile: `4, 4, 15`; `21, 21, 24`; `25, 25, 34`.

**Soru 2** (derste sözlü, 00:42:02): Sınırlarla yumuşatmada birinci kutu `4, 8, 15` yerine `4, 13, 15` olsaydı 13 hangi değerle değiştirilirdi?

> **Çözüm (derste verildi):** $|13-4|=9$, $|15-13|=2$; 13, 15'e daha yakın olduğu için 15 ile değiştirilir.

**Soru 3** (derste sözlü, 00:10:47): Bir veri kümesinde aynı satır neden birden fazla kez bulunabilir?

> **Çözüm (derste verildi):** Yanlışlıkla kopyalama olabilir; aynı kullanıcı farklı e-posta adresleriyle tekrar kayıt olabilir; bir mağazanın farklı şubelerinde aynı müşteri için ayrı kayıt açılabilir. Farklı kaynaklardan veri birleştirilirken bu sorun büyür.

**Soru 4** (derste sözlü, 00:16:14): Veritabanında her şey tanımlı olduğu halde neden eksik ya da hatalı veri oluşur?

> **Çözüm (derste verildi):** İnsan hatası, bilerek yanlış girilen bilgi (ör. doğum tarihi), cihaz ya da sensör hatası, formlarda yalnız zorunlu alanların doldurulması, yazılım hatası ve yanlış anlama (ör. tarih biçiminde gün ile ayın karışması).

**Soru 5** (derste sözlü, 00:29:11): Veride gürültü olduğunu nasıl anlarsınız?

> **Çözüm (derste verildi):** Dağılıma bakılabilir, ama her veri Gauss dağılımı izlemediği için gürültü her zaman dağılımdan çıkarılamaz. Sinyal ve görüntüde gürültüyü eleyen filtreler (ör. medyan filtresi) vardır. Kaynağı belirsiz sayısal veride ise veri kutulama, regresyon ya da kümeleme ile yumuşatılır.

## Dersin Toparlaması

Bu derste veri madenciliğinin ilk adımı olan veri ön işlemeye giriş yapıldı. Düşük kaliteli veriden doğru bilgi çıkarılamayacağı, kalitenin doğruluk, tamlık, güncellik, güvenilirlik ve anlaşılabilirlik gibi boyutları olduğu görüldü. Ön işlemenin dört ana görevi (temizleme, bütünleştirme, azaltma, dönüştürme ve ayrıklaştırma) tanıtıldı, ardından temizlemenin iki büyük sorunu ele alındı: eksik veri ve gürültülü veri. Eksik veri için satır silme, elle doldurma, global sabit, ortalama, sınıf ortalaması ve en olası değer yöntemleri; gürültülü veri için kutulama, regresyon, kümeleme ve insan denetimi anlatıldı. Kutulama örneği üç yumuşatma yöntemiyle adım adım çözüldü.

Son olarak yumuşatma yöntemlerinin aynı zamanda veri azaltma ve ayrıklaştırma işlevi gördüğü vurgulandı. Veri bütünleştirme, dönüştürme, veri azaltma ve kavram hiyerarşileri derslerin devamında ayrıntılı olarak ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
