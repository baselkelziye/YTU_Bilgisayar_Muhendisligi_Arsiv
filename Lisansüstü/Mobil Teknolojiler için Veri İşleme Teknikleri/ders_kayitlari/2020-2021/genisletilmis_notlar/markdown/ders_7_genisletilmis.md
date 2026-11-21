# Ders 7 Genişletilmiş Notu: Veri Ön İşleme: Dönüşüm, Eksik Veri, Gürültü Temizleme ve Veri İndirgeme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş Sorusu: K-NN'in Eğitim Karmaşıklığı
- 2. Mobil Cihazlarda Makine Öğrenmesinin Maliyeti
- 3. Uzaklık Metrikleri
- 4. Veri Entegrasyonu ve Veri Temizleme
- 5. Veri Dönüşümü
- 6. Eksik Verilerin Tamamlanması
- 7. Gürültü Temizleme ve Aykırı Değerler
- 8. Mobil Cihazda Öğrenme ve Veriyi Yerinde İşleme
- 9. Ensemble Filter
- 10. K-Katlı Çapraz Doğrulama
- 11. Veri İndirgeme ve Öznitelik Seçimi
- 12. Örnek Seçimi

## 1. Giriş Sorusu: K-NN'in Eğitim Karmaşıklığı

Hoca derse, her yıl sorduğunu ve genelde yanlış ya da hiç cevap alamadığını söylediği bir soruyla başladı: K-NN (K-Nearest Neighbor) algoritmasının eğitim (train) karmaşıklığı nedir? Burada eğitim karmaşıklığı, model oluşturulurken yapılan işlemlerin girdi sayısına ya da öznitelik sayısına bağlı maliyeti anlamına gelir.

Öğrencilerden farklı cevaplar geldi: karmaşıklığın k parametresine ve kullanılan uzaklık türüne bağlı olduğu, veri n boyutluysa $n^2$ olduğu, eleman sayısı ile küme sayısına bağlı olduğu ve sınıf sayısı ile eleman sayısının çarpımı ($k \cdot n$) olduğu söylendi. Küme sayısını söyleyen öğrenciye hoca "kümeden ne kastettiğini" sordu; öğrenci küme merkezlerinden söz edince hoca iki algoritmanın karıştırıldığını belirtti.

> **Hocanın vurgusu:** K-Means ile K-NN her yıl karıştırılır. K-Nearest Neighbor bir sınıflandırma algoritmasıdır (supervised learning), K-Means bir kümeleme algoritmasıdır (unsupervised learning).

Hocanın verdiği cevap: K-NN'in öğrenme adımı yoktur. Elinizde farklı sınıflardan örnekler (instance) ve bunların öznitelikleri vardır; bunlardan ayrı bir parametre ya da eğri çıkarılmaz. Bu yüzden K-NN gibi model oluşturma kısmı olmayan algoritmalara örnek tabanlı öğrenme (instance-based learning) denir: örneklerin özellikleriyle ortak bir model kurulmaz, yeni gelen örnekle kayıtlı örnekler arasındaki uzaklıklar hesaplanır.

Bir öğrenci, eğitim olmadığını cevap verirken fark ettiğini, karmaşıklık varsa bunun kaç komşuya bakıldığına bağlı sabit bir sayı olacağını söyledi. Hoca bunun ayrıca konuşulması gereken noktaları olduğunu belirtip yorum yapmadı.

Öğrenme algoritmalarında iki ayrı karmaşıklık vardır: eğitim karmaşıklığı (modeli oluşturma işlemlerinin maliyeti) ve test karmaşıklığı (model gerçek hayatta çalışırken her karar için harcanan maliyet). K-NN'de korkulan kısım test tarafıdır: her yeni örnek için bütün kayıtlı örneklere uzaklık hesaplanır.

> **Ek bilgi (derste anlatılmadı):** n eğitim örneği ve d öznitelik varsa, basit K-NN tek bir yeni örnek için yaklaşık $O(n \cdot d)$ uzaklık işlemi yapar; eğitim aşaması yalnızca veriyi saklamaktır. KD-tree gibi veri yapıları düşük boyutta bu maliyeti azaltabilir.

## 2. Mobil Cihazlarda Makine Öğrenmesinin Maliyeti

Hoca, test karmaşıklığının mobil teknolojiler açısından neden kritik olduğunu anlattı. Modeli uygulamaya koyduğunuzda karmaşıklık yüksekse modeli telefonda ya da saatte çalıştırmak maliyetli olur. Bu yüzden giyilebilir cihazlarda, IoT cihazlarında ve mobil cihazlarda test karmaşıklığı düşük modeller tercih edilir.

Eğitim karmaşıklığı yüksek olabilir; başarılı algoritmaların çoğunun model oluşturma kısmı maliyetlidir. Bu durumda öğrenme sunucuda belirli zamanlarda yapılır, elde edilen parametreler ilgili IoT cihazına, telefona ya da saate aktarılır (deploy edilir). Sinir ağlarında da durum böyledir: ağırlıkların hesaplanması çok uzun sürer, ama hesaplandıktan sonra o ağırlıklarla karar vermek çok kısa sürer, çünkü yapılan iş çarpma ve toplamadır.

Bu noktada hoca kayan noktalı sayılara dikkat çekti. Kayan noktalı işlem tam sayı işlemine göre her zaman daha maliyetlidir. Bu yüzden mümkünse tam sayılarla çalışmak tercih edilir: örneğin virgülden sonra iki basamak varsa sayılar yukarı doğru ölçeklenir (çarpılır), böylece bölme ve çarpma işlemleri tam sayılarla yapılır.

> **Hocanın vurgusu:** Ders boyunca makine öğrenmesindeki bu tür küçük farklar tartışılacak. Her yıl değişmeyen iki nokta: K-Means ile K-NN'in karıştırılmaması ve K-NN'in model oluşturma adımının olmaması.

Hoca, yüksek lisans ve doktora düzeyinde makine öğrenmesi dersleri alınmış olsa bile bazı temel bilgilerin oturmadığını gözlediği için bu noktaları ders içinde paylaştığını söyledi.

## 3. Uzaklık Metrikleri

Bir öğrencinin cevabındaki "uzaklık metriği önemlidir" vurgusu üzerine hoca hangi metriklerin bilindiğini sordu. Öğrenciler Öklid, Manhattan ve Jaccard'ı saydı; hoca Mahalanobis'i ekledi. Bunlar genel olarak uzaklık ölçmek için kullanılan metriklerdir, ama probleme göre uygun metrik değişebilir.

Birçok problemde Öklid uzaklığı ağırlıklı olarak kullanılır ve sanki her zaman en iyi sonucu veriyormuş gibi bir algı oluşur. Hoca bunun doğru olmadığını, metriğe iyi bakmak gerektiğini söyledi. Öklid uzaklığı farkların karelerinin toplamının kareköküdür; uzayda üçgenin hipotenüsü boyunca doğrudan erişim gibi düşünülebilir. Bazen ise x ve y eksenleri boyunca hareket etmenin maliyetini hesaplamak (Manhattan uzaklığı) daha akıllıcadır.

$$d_{\text{Öklid}}(a,b) = \sqrt{\sum_i (a_i - b_i)^2}$$

> **Ek bilgi (derste anlatılmadı):** Manhattan uzaklığı $\sum_i |a_i - b_i|$ biçimindedir; şehir blokları arasında yalnız eksenler boyunca yürümeye benzer. Mahalanobis uzaklığı özniteliklerin kovaryansını hesaba katarak ölçek farkını ve korelasyonu düzeltir; Jaccard ise küme benzerliğine dayanır.

## 4. Veri Entegrasyonu ve Veri Temizleme

Slaytlara geçildikten sonra önceki haftada başlanan veri ön işleme (data preprocessing) konusuna devam edildi. Ön işleme hem öğrenme başarısını hem kümeleme başarısını doğrudan etkiler.

### 4.1 Veri entegrasyonu

Veri entegrasyonu (data integration), farklı kaynaklardan gelen verinin birleştirilmesidir. Birden fazla tablodan gelen bilginin birlikte değerlendirilmesi, birden fazla kaynaktan bilginin çıkarılması (extraction) ve bu bilgilerin birleştirilerek (aggregation) birlikte kullanılması bu kapsama girer. Slayttaki şemada iki veritabanından extraction ve aggregation ile bir veri ambarı sunucusuna (data warehouse server) aktarım gösteriliyordu (ekrandan, 00:20:00).

Slayttaki örnekler (ekrandan, 00:20:00):

- Farklı ölçekler: maaşın dolar ya da euro cinsinden verilmesi. Hoca, önceki haftadaki örneği hatırlattı: 1000 dolar ile 1000 TL aynı değildir, aynı birime çevrilmeleri gerekir.
- Türetilmiş öznitelikler: bir kaynakta aylık maaş, diğerinde yıllık maaş. Slayttaki tabloda bir kaynakta 1, 2, 3 numaralı kayıtlar için aylık maaş 5000, 2400 ve 3000; diğer kaynakta 6, 7, 8 numaralı kayıtlar için yıllık maaş 50,000, 100,000 ve 40,000 idi.

Hoca, ABD'de ve genel olarak yurt dışında ücretlerin yıllık, Türkiye'de ise daha çok aylık konuşulduğunu örnek verdi. A ülkesinden ve B ülkesinden gelen bilgiyi entegrasyon sırasında aynı cinsten ifade etmek kritiktir. Hoca bunların bilinen şeyler olduğunu ama terminolojinin de öğrenilmesi gerektiğini, çünkü veri hazırlama adımları sorulduğunda entegrasyonun bunlardan biri olduğunu söyledi.

Entegrasyon genellikle ilk adımda yapılır. Çünkü eksik, fazla ve yanlış bilgiler ancak veriler birleştirildikten sonra ortaya çıkar. Arada birkaç kez tekrar entegrasyon yapılabilir ama sıra genelde önce entegrasyon, sonra temizlemedir.

### 4.2 Veri temizleme

Temizleme (data cleaning) aşamasının birkaç adımı vardır. Birincisi tip uyuşmazlıklarının giderilmesidir: örneğin tarih biçiminde görünen bir verinin aslında float olması. Hoca bunun en çok Excel'de görüldüğünü söyledi: kolonun yanlış tanımlanması ya da bir bilgisayarda tarih, diğerinde float olarak tanımlı olması yüzünden kolonda yanlış değer görünür.

İkincisi tutarsız verilerdir (inconsistent data). Slayttaki örnek (ekrandan, 00:25:00):

```text
Age="42"
Birth Date="03/07/1997"
```

Yaş ve doğum tarihi birbiriyle ilişkili iki veridir ve burada birbirini tutmaz. Hoca benzer bir örnek daha verdi: X ve Y koordinatları ile merkeze olan uzaklık (distance) birlikte verilmişse, koordinatlardan hesaplanan uzaklık verilen değerle tutarsız olabilir. Bunların düzeltilmesi gerekir; bunun için hangi bilgiye güvenileceğine karar verilip ilerlenir. Ayrıca birbiriyle ilişkili (korele) iki öznitelik varsa ikisini birden almak anlamlı olmayabilir.

## 5. Veri Dönüşümü

Hoca "Data transformation deyince ne anlıyorsunuz?" diye sordu. Bir öğrenci, işlenemeyen verinin işlenebilir hale getirilmesi, standart bir forma sokulması dedi. Hoca bunun doğru olduğunu, ikinci bir amacın da gereğinden yüksek çözünürlüğü azaltmak olduğunu söyledi.

Slayttaki tanım ve tipik işlemler (ekrandan, 00:35:00):

- Amaç: veriyi veri madenciliği algoritmalarının uygulanmasına en uygun biçime getirmek.
- Aggregation: aylık satışların toplamının tek bir "yıllık satış" özniteliğine çevrilmesi.
- Data generalization: kavram hiyerarşileri kullanılarak mevcut veriden daha üst düzey veri elde etmek. Örnekler: sokak → şehir, sayısal yaş → {young, adult, half-age, old}.
- Normalization: değer aralığını [-1,1] ya da [0,1] yapmak.
- Doğrusal, karesel, polinom dönüşümler.

### 5.1 Ayrıklaştırma

Yaş sıfırdan yüz yirmiye kadar sürekli (continuous) bir veridir. Ama bebek, çocuk, ergen, genç, yetişkin, orta yaşlı, yaşlı gibi kategorilere ayrılabilir; bu skalayı seçmek de sizin elinizdedir (çocuk, genç, yetişkin, yaşlı da diyebilirsiniz). İhtiyaç duyduğunuz veri yüksek çözünürlükte verilmişse ve bu karar verme mekanizmanızı zorlaştırıyorsa veriyi ayrıklaştırmanız (discretize) gerekir.

Hoca başka ayrıklaştırma örnekleri istedi. Öğrencilerden gelen örnekler:

- Şirket verilerinin birinci, ikinci, üçüncü ve dördüncü çeyrek olarak ifade edilmesi. Hoca, şirketlerin bilançosu ya da bütçesiyle ilgili tahmin modellerinde verinin genelde dört çeyreğe bölündüğünü söyleyerek bunu çok güzel bir örnek olarak nitelendirdi.
- Sensörlerden gelen sıcaklık verisi. Öğrenci önce verinin "sürekli toplanmasından" söz edince hoca bunun veri toplama yöntemindeki süreklilik olduğunu, kendisinin ise verinin değerinin sürekliliğini (3.2, 4.3 gibi) kastettiğini açıkladı. Ayrıklaştırma, örneğin sıfır ile sekiz derece arasını "soğuk" saymaktır. Meteorolojide de sıcaklık çok soğuk, soğuk, serin, ılık, sıcak gibi ifade edilir.
- Ders notlarının harf notlarına (A, B, C ya da A+, A, A- gibi) çevrilmesi.

Bu gruplamanın nedeni: aynı gruptaki elemanların belli bir karakteristik gösterdiği düşünülüyorsa veriyi gruplamak karar vermeyi kolaylaştırır.

### 5.2 Label encoding ve one-hot encoding

**Soru:** Kategorik veriler bu kapsama girer mi? Örneğin tabloda cinsiyeti E ve K diye tutarsak bunu algoritmaya vermek için bir işleme sokmamız gerekmez mi? One-hot encoding de buraya girer mi?
**Cevap:** Evet, bunlar da veri dönüşümüdür. Ancak az önce konuşulan dönüşüm türünün amacı, yüksek çözünürlüklü sürekli veriyi daha düşük çözünürlüklü ayrık değerlere indirmekti. Kategorik verinin sayıya çevrilmesi ayrı bir dönüşüm türüdür.

Soruyu soran öğrenci one-hot encoding'i şöyle anlattı: tek kolonda kaç farklı değer varsa o kadar yeni kolon açılır; kadın için ayrı, erkek için ayrı kolon olur. Değerleri aynı kolonda 0 ve 1 olarak tutmak yerine ayrı kolonlarda 1 ya da 0 olarak tutmanın daha iyi sonuç verdiğini okuduğunu söyledi. Derste verilen bir örnekte tek kolonda tutulan oda tipleri (tek kişilik, iki kişilik, suit vb.) one-hot encoding ile her tip için ayrı bir kolona çevriliyordu.

Hoca iki sık kullanılan yöntemi ayırdı:

- Label encoding: değerlere sayı atanır. Erkek ve kadın 0 ve 1 olur; haftanın 7 günü 1'den 7'ye numaralanır, örneğin pazartesi 1, cuma 5 olur. Bu durumda pazartesi ile salı arasındaki uzaklık 1, pazartesi ile cuma arasındaki uzaklık 4 olur. Bu uzaklık anlamlı bir bilgiyse sorun yoktur.
- One-hot encoding: çoğu durumda önemli olan, o günün pazartesi olup olmadığıdır, salı olup olmadığıdır. Bu durumda her değer için yeni bir öznitelik açılır. Pazartesiden pazara 7 gün olduğu için tek "gün" özniteliği 7 özniteliğe çıkar. Pazartesiye ait bir örnek geldiğinde "pazartesi" özniteliği 1, diğer 6 gün özniteliği 0 yapılır.

Hoca bu konuyu ekranda yazarak göstermediğini, çünkü dersin doğrudan bu teoriyi anlatmayı hedeflemediğini, ama one-hot encoding'in not alınıp ayrıntılı çalışılmasının faydalı olacağını söyledi.

### 5.3 Aggregation, genelleştirme ve normalizasyon

Slayttaki aggregation örneğinde aylık satışların tek bir yıllık değere çevrilmesi bir dönüşümdür; hoca aynı işlemin entegrasyon adımında da yapılabileceğini, iki taraftan da değerlendirilebileceğini söyledi. Veri genelleştirme, yaş aralıkları örneği gibi değerleri daha üst gruplara dönüştürmektir. Sokak bilgisi varsa ve sokak düzeyinde ayrıntıya ihtiyaç yoksa bu bilgi ilçe ya da il düzeyine dönüştürülür. Normalizasyonun genelde [-1,1] ya da [0,1] aralığına yapıldığı önceki hafta söylenmişti.

### 5.4 Boyut indirgeme: PCA ve LDA

Hoca, dönüşüm yöntemleri arasında boyut indirgeme (dimensionality reduction) için kullanılan çok bilinen algoritmaları sordu. Bu algoritmalar hem öznitelik sayısını azaltmak hem de mevcut boyutlarda ayırt edici olmayan öznitelikleri başka bir boyuta taşımak için kullanılır.

**Soru:** Eğri uydurma gibi bir şey mi?
**Cevap:** Hayır. x-y düzleminde iki boyutlu olduğunu varsaydığımız iki özniteliğin, ortasından 45 derece ile geçen bir doğru üzerinde tek bir boyuta dönüştürülerek gösterilmesi gibi düşünülebilir. Normalde örneğin 20 öznitelikten oluşan bir veri alınır ve 10 ya da 5 boyuta indirgenir; ama yeni boyutların yönleri ve ifade ediliş biçimleri uzayda değişmiştir. Hoca bunu iki boyutla anlattığını, çünkü yüksek boyutun görselleştirilemeyeceğini söyledi.

Bir öğrenci bunun temel bileşen analizi (Principal Component Analysis, PCA) olduğunu söyledi. Hoca, PCA'nin yanında onun "kardeşi" sayılan doğrusal ayırtaç analizini (Linear Discriminant Analysis, LDA) ekledi. İkisi de hem boyut indirgeme için hem de bulunulan öznitelik uzayı sınıfları ayırt etmeye yetmiyorsa uzayı değiştirmek için kullanılır.

- PCA sınıf bilgisine bakmadan dönüşüm yapar; uzayı değiştirmek için sınıf bilgisine ihtiyaç duymaz.
- LDA'da amaç sınıflar arası uzaklığı maksimize, sınıf içi uzaklığı minimize etmektir; bu yüzden sınıf bilgisini kullanarak PCA'ye benzer bir dönüşüm yapar.

LDA genelde biraz daha iyi sonuç verir. Ama birçok yerde PCA tercih edilir, çünkü sınıf bilgisi gerektirmediği için unsupervised problemlerde de kullanılabilir.

PCA'de özdeğerler (eigenvalue) ve özvektörler (eigenvector) elde edilir. Scree grafiği (scree graph) denen bir eğriyle kaç bileşene kadar almanız gerektiği görülür: örneğin 20 özellikten 15'e düştüyseniz, 15'ini mi, 10'unu mu, 5'ini mi almanın maliyete değer olduğunu bu eğri gösterir. Böylece hem karmaşıklık azalır hem de sınıflandırma problemine yeni boyutlar kazandırılarak birbirinden ayrılamayan veriler ayrılabilir.

### 5.5 Min-max normalizasyon

Hoca, en sık kullanılan normalizasyonun min-max normalizasyonu olduğunu, bunun çok kolay bir teknik olduğunu ve veriyi [-1,1] ya da [0,1] aralığına algoritmik olarak dönüştürmenin bilinmesi gerektiğini söyledi; ayrıntıya girmedi.

> **Ek bilgi (derste anlatılmadı):** [0,1] aralığına min-max normalizasyonu $x' = \dfrac{x - x_{min}}{x_{max} - x_{min}}$ ile yapılır. [-1,1] aralığı için $x'' = 2x' - 1$ kullanılır.

## 6. Eksik Verilerin Tamamlanması

### 6.1 Kirli ve eksik veri sorunu

Hoca, şirketlerin verilerinde en çok şaşırdığı şeyin, verisinin sağlam olmasını beklediği şirketlerde bile verinin kirli ve eksik olması olduğunu söyledi. Bunun en büyük nedeni kullanıcıdır. IoT cihazlarından ve sensörlerden de arada hatalı veri gelebilir ama sayısı düşüktür. Kullanıcıya seçenek listesi verilmeyip elle giriş yaptırılırsa sorun başlar: ön işleme adımları arasında büyük harfe ya da küçük harfe çevirmek bile vardır; İstanbul'un i ile ya da ı ile yazılması, farklı dillerdeki yazımlar, harflerin eksik yazılması gibi. Google'ın "did you mean" önerisi bu tür hataların yaygınlığını gösterir. Hocanın verdiği bir örnek, işlemcideki cache belleğin para anlamındaki "cash" diye yazılmasıydı. Kontrollü olmayan, herkese açık bir kullanıcı grubunda veri ya eksik ya da hatalı gelir.

### 6.2 Öğrencilerin önerileri

Arada hoca eksik veriyi düzeltmek için hangi yöntemlerin akla geldiğini sordu. Bir öğrencinin önerileri: sabit bir değerle (örneğin sıfır) doldurmak; eksik olduğunun anlaşılması isteniyorsa -1 gibi dikkat çekici bir değer koymak; null koyup ayrıca değerlendirmek; diğer özniteliklerle bir ilişkisi varsa bu ilişki üzerinden dinamik bir değer atamak.

Slaytta eksik değerler, satırları örnekler (1..n) ve sütunları öznitelikler (1..m) olan bir tabloda farklı hücrelere dağılmış soru işaretleriyle gösteriliyordu (ekrandan, 00:55:00).

### 6.3 Eksikliği işaretlemek

Birinci yol verinin eksik olduğunu belirten bir bilgi koymaktır: -1 ya da N/A (not available) gibi. Hoca bunun bilinmesinin önemli olduğunu, ama pratikte eksik verinin bazen boşluk, bazen okunamayan karakter, bazen null olarak farklı sembollerle yazıldığını, bunun doğru olmadığını ve standart hale getirilmesi gerektiğini söyledi. Bu yöntem, eksik verinin yerine bir şey koymak anlamlı değilse ya da mümkün değilse tercih edilir. Yerine anlamlı bir değer koymak mümkünse doldurma yöntemleri uygulanır. Temel ilke: yerine yazılan değer başarıyı olumsuz etkilemeyecekse kullanılmalıdır.

### 6.4 Ortalama ve medyan ile doldurma

Hoca genelden özele doğru gitti:

- Bütün örneklerin ortalaması: eksik hücreye o özniteliğin genel ortalaması konur. Hocaya göre bu çok akıllıca değildir, çünkü sınıflar arasında varyans farklıysa genelleme yapılmış olur ve değer iyi temsil etmez.
- Aynı sınıftaki örneklerin ortalaması: daha iyi bir versiyondur.
- Medyan: ortalamaya alternatif olarak çok kullanılır.

> **Hocanın vurgusu:** Ortalama iki uçtaki değerleri birlikte hesaba kattığı için birçok yerde hataya neden olabilir. Medyan ise bütün dağılımın orta noktasını verir. Bu önemli, kritik bir bilgidir.

### 6.5 Eksik örnekleri atmak

**Soru:** Eksik değerler belli bir oranı geçmiyorsa o örnekler veriden çıkarılabilir mi?
**Cevap:** Evet. Eksik değerin yerini doldurmak gibi bir kaygı yoksa, eksik oranı örneğin %5-%10 kadarsa ve yeterince veri varsa bu örneklerle hiç uğraşılmaz, doğrudan atılır. Ancak her örneğin farklı bir özniteliği eksikse bütün örnekler atılmaya aday olur. Bu yöntem ancak örnek sayısı çok fazlaysa uygulanabilir. Özellikle öznitelik sayısı çoksa mutlaka eksik veri olur ve bu yaklaşım kolay uygulanamaz.

### 6.6 Benzer örneklerden doldurma ve K-NN

Hoca sınıf ortalamasından daha iyisi olup olmadığını sordu. Bir öğrenci, eksik olan öznitelikle başka bir öznitelik arasında, değeri dolu örnekler üzerinden bir ilişki (eğri uydurma gibi) kurulabileceğini önerdi.

Hoca şu yöntemi anlattı: eksik özniteliğin dışındaki öznitelikler açısından eksik örnek başka örneklere ne kadar benziyorsa, o örnekler arasında benzerlik olduğu kabul edilir ve onların değeri eksik hücreye konur. En benzer bir örneğin ya da en benzer k örneğin değerlerinin ortalaması, medyanı, maksimumu ya da minimumu kullanılabilir. Bu çok sık kullanılan bir yöntemdir.

**Soru:** Bu benzerliği bulmak için hangi algoritmadan faydalanabiliriz?
**Cevap:** K-NN yüksek adaylardan biridir. Diğer bütün özniteliklerin uzaklıklarına bakılır. Öznitelikler sayısal değil kategorikse, değerler aynıysa uzaklık 0, farklıysa 1 alınabilir; toplam uzaklık 0'a ne kadar yakınsa örnekler o kadar benzerdir. <!-- BELİRSİZ: Altyazıda cümle bozuk ("S ise 1'dir uzaklık. Farklıysa aynısı 0'dır"); hocanın "0'a ne kadar yakınsak o kadar benziyor" sonucuna göre aynı=0, farklı=1 yazıldı. -->

### 6.7 Slayttaki seçenekler ve en olası değer

Slayttaki seçenekler arasında ilgili örneği yok saymak (ignore), geri kalan örneklerin ortalaması ya da sapmasını kullanmak, aynı sınıftakilerin ortalamasını kullanmak ve en olası değerle doldurmak (impute with the most probable value) vardı. Son seçenek için slaytta şu yazıyordu: bunun için Bayes ya da karar ağaçları gibi bir çıkarım tekniği kullanılabilir (ekrandan, 01:05:00).

Hoca bu ifadeyi açmak için naive Bayes'in nasıl bir yaklaşım olduğunu sordu ve cevabı verdi: istatistiksel bir yaklaşımdır. Dağılıma bakar, daha önce öğrendiği örneklerin olasılıklarını hesaba katarak gelen örneğin hangi gruba yakın olduğunun olasılığını üretir. Karar ağacında ise en ayırt edici öznitelik ağacın tepesine yerleşir ve aşağı doğru dallanma olur. Ağacın mümkün olduğunca kısa olması istenir, çünkü bütün öznitelikler dallanmaya girerse çok fazla dallanma olur. En güzeli dengeli ve az özniteliğin kullanıldığı bir ağaçtır.

Bazıları sınıflandırma algoritmalarını kullanarak eksik değeri tahmin eder (örneğin K-NN ile en yakın örneği bulup onun değerini almak). Hocaya göre bu yapılabilir ama maliyeti çok yüksektir; sınıflandırma için model kurulacaktır ve başarı garantisi de yoktur, ne kadar akıllıca olduğu tartışılır.

Slaytta KEEL aracındaki eksik değer yöntemlerinden bir kısmı bir tabloda listelenmişti (ekrandan, 01:05:00): Delete Instances with Missing Values (Ignore-MV), Event Covering Synthesizing (EventCovering-MV), K-Nearest Neighbor Imputation (KNN-MV), Most Common Attribute Value (MostCommon-MV), Assign All Possible Values of the Attribute (AllPossible-MV), K-means Imputation (KMeans-MV), Concept Most Common Attribute Value (ConceptMostCommon-MV). Slaytta toplam "15 methods" yazıyordu.

### 6.8 K-Means ile doldurma

**Soru:** Kümeleme yöntemiyle (K-Means) eksik veri dolduruluyor olsaydı bu iş nasıl yapılırdı?
**Cevap:** Öğrenci önce bütün veriyi vermek yerine eksik örneğe en yakın olanları seçip kümeler oluşturmayı, sonra kümenin ortalamasını ya da en yakın örneği almayı önerdi. Hoca şöyle toparladı: bir öznitelik eksikse, bütün örnekler eksik özniteliğin dışındaki özniteliklerle k kümeye ayrılır. Eksik özniteliğe sahip örnek hangi kümeye düşüyorsa, o kümedeki örneklerin bu öznitelikteki değerlerine bakılarak karar verilir. Sınıf bilgisinin olmadığı unsupervised problemlerde bu doldurma yöntemi en akılcısıdır.

## 7. Gürültü Temizleme ve Aykırı Değerler

### 7.1 Karar sınırının biçimi, overfitting ve underfitting

Gürültü temizleme (noise cleaning) slaytında iki sınıf arasında dalgalı bir karar sınırı vardı. Slayttaki şekil üç örnek türünü gösteriyordu: güvenli örnekler (safe, s), sınırdaki örnekler (borderline, b) ve gürültülü örnekler (noisy, n); kesintisiz çizgi iki sınıf arasındaki karar sınırıydı (ekrandan, 01:10:00).

**Soru:** Bu eğri ne tür bir sınıflandırma algoritması kullanıldığını gösteriyor olabilir?
**Cevap:** Bir öğrenci doğrusal olmadığını söyledi. Hoca, polinom bir eğri oluşturulduğunu, problemin kesinlikle doğrusal olmadığını, eğrinin aşağı yukarı x'in 5. ya da 7. kuvvetiyle ifade edilebilecek gibi göründüğünü söyledi. Doğrusal olmayan problemlerde çok yüksek dereceli eğriler kurmak istenmez.

**Soru:** Neden yüksek dereceli (daha girintili çıkıntılı, $x^{11}$, $x^{13}$ gibi) eğriler istemeyiz?
**Cevap:** Bir neden hesap yüküdür. Daha önemlisi aşırı uyumdur (overfitting): model ne kadar karmaşıksa veriyi ezberleme olasılığı o kadar yüksektir. Mümkün olduğunca genelleştirilebilir modeller kurmak önemlidir, bu da basit modellere yaklaşmayı gerektirir. Ama doğrusal modeller de çoğu zaman yetmez; XOR kapısında bile doğrusal bir model işe yaramaz. Bu dengeyi iyi kurmak gerekir.

**Soru:** Underfitting nedir?
**Cevap:** Öğrenciler, öğrenememek, eğitim sonucunun iyileşmemesi ve modeli genelleştirmeye çalışırken performansın düşük kalması dedi. Hoca örnekle açıkladı: karmaşıklığı düşük tutalım derken ekrandaki örnekler arasından tek bir doğru çekilirse muhtemelen örneklerin en az %20'si yanlış tarafta kalır. Biraz daha iyi bir eğri bu eksikliği giderir.

### 7.2 SVM

Hoca bu şekildeki ayrımın çok bilinen bir algoritmada görülebileceğini söyleyip cevabı verdi: destek vektör makinesi (Support Vector Machine, SVM). Şekildeki işaretli gruplar küme değildir, etiketi bilinen iki sınıftır. SVM'de doğrusal, polinom, radyal tabanlı (radial basis) gibi farklı çekirdek (kernel) tipleri seçilebilir. SVM genelde iki sınıflı problemlere uygulanır; çok sınıflı problemler için de farklı yöntemler vardır. Amaç iki sınıf arasındaki farkı olabildiğince açmak, iki sınıfın destek vektörlerini birbirinden uzak noktalara koymak ve bunların ortasından geçen bir çizgiyle sınıfları ayırmaktır. <!-- BELİRSİZ: Altyazıda çekirdek adları bozuk ("Kernel Beyses, Radial Beyses, Neyer Beyses"); doğrusal, polinom ve radyal tabanlı diye yorumlandı. -->

### 7.3 Zorlayıcı örnekler: borderline ve aykırı değerler

**Soru:** Böyle bir veri grubunda destek vektörleri oluşturulurken bizi hangi örnekler zorlar?
**Cevap:** Birincisi iki sınıfın birbirine en yakın olduğu, mavi ve pembe örneklerin iç içe geçtiği yerdeki örneklerdir; tam çizginin çekileceği yerdir ve bu örnekler iki sınıftan biri olarak da etiketlenebilir. Bunlara sınırdaki örnekler (borderline examples) denir ve her zaman risklidir. İkincisi aykırı değerlerdir (outlier).

**Soru:** Kendi grubundan çok uzakta duran bir örneği (outlier) modele vermek mi, temizlemek mi doğru olur?
**Cevap:** Hoca bunun zor bir soru olduğunu ve probleme bağlı olduğunu söyledi. Genelde kendi grubundan çok uzakta olan veriler aykırı değer sayılıp temizlenir. Ama bazı problemlerde o veri gerçekten gözlenmiştir, doğrudur ve o sınıfa aittir. Sayısı az olduğu için modele yeterli katkı sağlamaz. Bu durumda veriyi tutup benzerlerinin sayısını sentetik veri üreterek artırmak bir seçenektir; özellikle veri sayısı ya da çeşitliliği azsa.

### 7.4 Sentetik veri ve dengesiz veri setleri

Hoca örnek olarak dolandırıcılık tespitini (fraud detection) ve yeni, hasta sayısı az olan hastalıkları verdi. Çok sayıda sağlıklı birey ile az sayıda hasta bireyin verisi öğretilirken model bir tarafa yakınsar. Bunu önlemenin iki yolu vardır: sağlıklı bireylerin veri sayısını azaltarak dengeli bir veri seti oluşturmak ya da hasta bireylerin özelliklerinden yola çıkarak yeni sentetik veriler üretip veri setini büyütmek. Son dönemde sentetik veri kullanmak bazı problemlerde ciddi olumlu sonuçlar vermektedir; eskiden pek istenmezdi. Hoca bunu dolandırıcılık tespitinde açıkça gözlediğini söyledi. Elbette verinin önemli bir kısmının gerçek olması gerekir; her şey sentetik üretilemez.

Sentetik verinin işe yaramadığı bir örnek ağ saldırılarıdır: birkaç saldırı tipinden sentetik veri üretildiğinde başarı düşük kalır, gerçek saldırılardan öğretildiğinde başarı daha yüksek çıkar. Ağ akışını (flow) taklit etmek kolay değildir, çünkü paketlerin değer aralığı çok geniştir. Dolandırıcılık tespitinde ise örneğin 60 öznitelik varsa bunların alabileceği değerler bellidir; taklit edildiğinde üretilen verinin çeşitliliği artırması ve sonucu bozmaması daha olasıdır. Sonuç: değer aralığı genişledikçe taklit etmek zorlaşır.

### 7.5 Aykırı değer tespitinin iki ölçütü

Gürültü temizlemede aykırı değer tespiti çok önemlidir. Hocanın anlattığı iki ölçüt:

- Merkezden uzaklık: bir yarıçap R seçilir, R'nin dışında kalanlar elenmeye adaydır.
- Çevresindeki örnek sayısı: örneğin etrafında belli sayıda örnek yoksa bu da eleme gerekçesidir.

Çok uzak noktada tek bir örnek bulunduysa önemli bir elenme adayıdır. Ama çok uzak noktada 50 örnek bulunduysa, yalnız uzaklığa bakarak bu 50 örnekten kurtulmak doğru değildir. Aykırı değer hem uzak olacak hem de çevresinde çok fazla örnek olmayacaktır.

### 7.6 İç içe geçmiş sınıflar

Slayttaki ikinci şekil sınıflar arası etkileşimi gösteriyordu: (a) küçük ayrık gruplar (small disjuncts), yani bir sınıfın diğer sınıfın içinde küçük adacıklar oluşturması; (b) sınıfların örtüşmesi (overlapping) (ekrandan, 01:20:00). Hoca en zor ve en sevilmeyen problemlerin birbirinin içine geçmiş sınıflar olduğunu söyledi ve iki soru sordu: bu tür doğrusal olmayan problemlerde başarılı olan yöntem hangisidir, ve böyle bir probleme örnek nedir?

**Soru:** İç içe geçmiş, doğrusal olmama derecesi yüksek problemlerde hangi yöntem başarılıdır?
**Cevap:** Bir öğrenci sinir ağları dedi; hoca doğruladı. Karmaşıklık arttıkça katman sayısının ve nöron sayısının da artması gerekir.

**Soru:** Birbirinden ayırt edilmesi zor bir probleme örnek verebilir misiniz?
**Cevap:** Bir öğrenci benzer semptomlar gösteren hastalıkların teşhisini önerdi. Hoca bunu güncel bir örnekle açtı: zatürre ile COVID'in ayırt edilmesi. Normal bir zatürre geçiren kişinin akciğer tomografisinde görülen desen COVID'de de görülür; tedavi ve teşhis protokolleri sürekli değişir ve hastanın o noktaya COVID'den mi yoksa başka bir hastalıktan mı geldiğini anlamak zordur. Hoca ikinci örnek olarak dolandırıcılığı verdi: son dönemde çipli kart mı manyetik kart mı kullanıldığı gibi ayırt edici yeni öznitelikler var, ama kartı çalan kişi kart sahibinin alışveriş karakteristiğini taklit ederse (örneğin kart sahibi her hafta kahve alıyorsa o da kahve alırsa) işlem dolandırıcılık gibi görünmez.

Bu tür doğrusal olmayan problemlerde sinir ağlarının başarısı açıkça ortaya çıkar. Hoca sinir ağlarının yeni bir yöntem olmadığını, yaklaşık 30 yıl öncesine dayandığını söyledi.

**Soru:** Sinir ağlarının dezavantajı nedir?
**Cevap:** Bir öğrenci, katmanlar arttıkça doğruluğun arttığını ama bunun için güçlü makinelere ihtiyaç olduğunu, öğrenmenin çok uzun sürdüğünü söyledi. Hoca kritik noktanın öğrenme maliyetinin çok yüksek olması olduğunu doğruladı.

## 8. Mobil Cihazda Öğrenme ve Veriyi Yerinde İşleme

### 8.1 Sık öğrenme ve sunucu trafiği

Mobil cihazlarda sık öğrenme ve sık veri değişimi öngörülüyorsa ve öğrenmenin sunucuda yapılacağı varsayılıyorsa, bu sunucu trafiğini ve cihazlar arası iletişimi çok artırır; tercih edilmez, daha basit modellere yönelinmelidir. Hoca o gün için öğrenmenin telefonda ya da saatte yapılmasının düşünülmediğini, ama bunun olmayacağı anlamına gelmediğini söyledi.

**Soru:** Bugünkü telefonların işlemci ve belleği kaç yıl önceki bilgisayarlara denk geliyor? Telefonlarda kaç gigabayt RAM var?
**Cevap:** Bir öğrenci, piyasadaki telefonların 8 GB RAM'e sahip olabildiğini, dizüstü bilgisayarların da aynı miktarda RAM'e sahip olabildiğini, yani telefonların bir noktada bilgisayarları yakaladığını söyledi. Hoca işlemci tarafında mimari ve performans farkı olduğunu, telefonlarda dinamik ölçekleme olduğu için bir PC ortamından ayrıldıklarını belirtti. GPU kenara konup CPU üzerinde öğrenme düşünülürse telefonların buna yanıt verme ihtimali vardır. Asıl sorun telefonun buna harcayacak enerjisinin olmamasıdır.

### 8.2 Şarjdayken öğrenme

**Soru:** Telefonda mecburen bir öğrenme yaptırılacaksa bunu ne zaman yaptırırsınız?
**Cevap:** Bir öğrenci "şarjdayken" dedi; hoca doğruladı. İşletim sistemleri son dönemde kullanıcıyı bu yönde yönlendiriyor: güncellemenin şarjdayken yapılması, belli boyuttaki verinin Wi-Fi'ye bağlanınca indirilmesi gibi. Eskiden böyle seçenekler yoktu; şarj azken başlayan güncelleme sırasında kullanılamaz hale gelen telefonlar olmuştu. Verinin saklanması ve işlemin yeniden başlatılması için mekanizmalar vardı, ama bazı telefonlarda bu kurgu doğru oturtulmadığı için kayıplar yaşandı. Sonuç olarak makine öğrenmesi yöntemleri mobil teknolojilere entegre edilirken cihazın mevcut özellikleri göz önüne alınmalıdır.

### 8.3 Veriyi olduğu yerde işlemek

Hoca önemli bir kavramdan daha söz etti: veriyi saklamak da, bir yerden bir yere aktarmak da maliyettir. Örnek olarak bir konferansta birlikte bulunan bir grubun aynı resimleri birbiriyle paylaşırken resimlerin sürekli sunucuya gidip gelmesini verdi; bin kişi gereksiz ağ trafiği oluşturur (proxy sunucular bunun için vardır). Yeni eğilim, verinin olduğu yerde işlenip bilginin çıkarılması ve ondan sonra paylaşılmasıdır. Bu yüzden cep telefonları, saatler ve IoT cihazları üzerinde ham veri işleniyor, cihazların kapasitesi buna göre ayarlanıyor ve çıkarılan bilgi merkeze gönderiliyor. Tasarım yapılırken bunu gözetmek çok önemlidir.

## 9. Ensemble Filter

### 9.1 Topluluk öğrenmesi

Hoca, gürültü filtreleme teknikleri arasında üç yaklaşımın slaytta yer aldığını söyleyip "Ensemble Filter ne olabilir?" diye sordu, sonra "Ensemble learning nedir?" sorusuna geçti. Birkaç öğrenci fikri olmadığını söyledi; bir öğrenci internette Kalman filtrelerine ulaştığını belirtti, bir başkası parçacık ve Kalman filtrelerini bildiğini ama bunu bilmediğini söyledi.

**Soru:** Topluluk öğrenmesi (ensemble learning) nedir?
**Cevap:** Bir öğrencinin cevabı: normalde bir algoritma çalıştırılır; topluluk öğrenmesinde birden çok algoritma, bazı koşulları değiştirilerek çalıştırılır ve çeşitli kararlar elde edilir. Sonra bu kararlardan çoğunluk oylamasıyla ("demokrasi usulü") ya da önem verilen özellikler seçilerek ortak bir karar çıkarılır; bu genelde kararın doğruluğunu ve kararlılığını artırır. Hoca bu özeti onayladı: topluca karar almak, doğru karar vericilerle çalışılıyorsa genelde olumlu sonuç verir. Örneğin iki ya da üç sınıflandırıcının kararlarının çoğunluğuna ya da hepsinin aynı kararı vermesine bakılarak karar alındığında sonuç genelde daha başarılıdır.

### 9.2 Ensemble Filter algoritması

Bir öğrenci, birçok filtre uygulanıp hepsinin elediği örneklerin kesin elenmiş sayılabileceğini önerdi. Hoca bunun farklı filtrelerin karar vermesi olmadığını, burada sınıflandırma algoritmalarının kararlarının kullanıldığını söyleyip şekli gösterdi.

Slayttaki bilgi (ekrandan, 01:35:00):

- Kaynak: C.E. Brodley, M.A. Friedl, "Identifying Mislabeled Training Data", Journal of Artificial Intelligence Research 11 (1999) 131-167.
- Farklı öğrenme algoritmaları (C4.5, 1-NN ve LDA), eğitim verisinin birkaç alt kümesinde sınıflandırıcı oluşturmak için kullanılır; bu sınıflandırıcılar eğitim kümeleri için gürültü filtresi görevi görür.
- İki ana adım vardır:

```text
1. Her öğrenme algoritması için k-katlı çapraz doğrulama ile her eğitim örneği
   "correct" (tahmin = eğitim etiketi) ya da
   "mislabeled" (tahmin ≠ eğitim etiketi) diye etiketlenir.
2. Gürültülü örneklerin son kümesini bulmak için bir oylama şeması kullanılır:
   - Consensus voting: örnek bütün sınıflandırıcılar tarafından yanlış
     sınıflanırsa atılır.
   - Majority voting: örnek sınıflandırıcıların yarısından fazlası tarafından
     yanlış sınıflanırsa atılır.

Training Data -> Classifier #1 ... Classifier #m
              -> Classification #1 ... #m (correct/mislabeled)
              -> Voting scheme (consensus or majority)
              -> Noisy examples
```

Hocanın örneği: 5 sınıflandırıcıdan 3'ü bir örneği yanlış etiketledi, 2'si doğru etiketledi. Majority voting seçildiyse bu örnek aykırı kabul edilip elenir. Consensus voting'de ise örneğin elenmesi için 5 sınıflandırıcının hepsinin yanlış etiketlemesi gerekir.

### 9.3 Dezavantaj ve hibrit çözüm

**Soru:** Bu yöntemin gürültü filtrelemede sıkıntısı nedir?
**Cevap:** Hoca yöntemin kulağa mantıklı geldiğini, çünkü beş sınıflandırıcının hepsi bir örneği yanlış sınıflıyorsa bir sorun olduğunun açık olduğunu söyledi. Dezavantajı maliyettir: belki tek bir örneğin aykırı olduğunu bulmak için bütün sınıflandırma algoritmaları uygulanıp çalıştırılır ve hangisinde olduğu bilinmediği için n örneğin hepsi verilir. Çözüm hibrit bir yapıdır: önce basit bir elemeyle aykırı değer adayları belirlenir (sınırdakiler ya da belli bir uzaklıkta olanlar), yalnız bunlar Ensemble Filter'a verilir. Böylece karmaşıklık azalır.

**Soru:** Ensemble Filter genel olarak diğer yöntemlerden daha mı başarılıdır?
**Cevap:** Diğer aykırı değer yöntemlerine göre biraz daha doğru karar veren bir yapıdır. Ama derin öğrenmenin her şeyi çözdüğü söylenemeyeceği gibi bunun da her zaman daha iyi sonuç verdiği söylenemez; hangi yöntemin uygulanacağı veri setine doğrudan bağlıdır. Hoca bazı veri setlerinde çok ciddi başarı elde ettiğini söyleyebileceğini ekledi.

## 10. K-Katlı Çapraz Doğrulama

Aradan sonra hoca, "çok tehlikeli bir ölçme yöntemi" diye nitelediği k-katlı çapraz doğrulamayı (k-fold cross validation) konuştu ve ne yaptığını, neden ortaya atıldığını sordu.

**Soru:** K-katlı çapraz doğrulama ne yapar ve neden ortaya atılmıştır?
**Cevap:** Bir öğrenci verinin örneğin %10'unun test için ayrıldığını, bu %10'luk parçanın bütün veri içinde döndürüldüğünü, böylece 100 birimlik veride 10 kez eğitim yapıldığını ve bunun özellikle veri boyutu küçükken kullanıldığını söyledi. Hoca doğruladı: veri seti k parçaya bölünür, bir parça test, kalan $k-1$ parça eğitim için kullanılır ve bu bütün k parça için döndürülerek bir başarı elde edilir. Az veri setleri için ortaya atılmış bir doğrulama biçimidir.

Hocanın küçük veri örneği: 10 örnek varsa ve 9'uyla eğitim, 1'iyle test yapılırsa yalnız bir örnekle test edilmiş olur. Her seferinde bir örnek ayrılıp kalan 9'la eğitim yapılırsa 10 örneğin hepsi test edilmiş olur. Veri 100'e çıkarsa 10 yerine 100 örnek test edilmiş olur. Burada k'nın değeri de önemlidir: 10-fold, 5-fold ya da 3-fold seçilebilir.

**Soru:** Bu yöntemin dezavantajı nedir? Büyük veri setlerinde neden eğitim, doğrulama ve test kümesi 60-20-20 ya da 80-10-10 gibi ayrılıyor da çapraz doğrulama kullanılmıyor?
**Cevap:** Öğrencilerden ve hocadan gelen noktalar:

- Uzun sürer. Hoca bunun yanlış olmadığını söyledi.
- Parçalardan biri tamamen bozuk ya da yanıltıcı verilerden oluşabilir ve başarıyı düşürebilir. Hoca bunun verinin saklanma biçimiyle ilişkili olduğunu söyledi: veri karıştırılmadan bölünürse bir sınıfın bütün örnekleri tek bölgede toplanabilir; o sınıf testte hiç olmayabilir ya da tamamı testte kalıp eğitimde hiç bulunmayabilir. Hoca bir araç türü tanıma probleminde bunu yaşadıklarını, belli tip örnekler bir tarafa toplandığı için modelin bunları hiç öğrenemediğini, veriyi rastgele karıştırınca bu olasılığın azaldığını ama karıştırmanın da garanti olmadığını anlattı.
- Bir öğrenci, aynı veri seti içinde çalışıldığı için farklı yapıdaki gerçek verilerle karşılaşınca sorun yaşanabileceğini söyledi. Hoca bunun eğitim/doğrulama/test ayrımında da geçerli olduğunu, ama test kümesi tamamen ayrıldığında ve sonuca dahil edilmediğinde gerçek başarının daha iyi ölçüldüğünü belirtti.

Hocaya göre çapraz doğrulama kullanılan çalışmalarda başarı oranları istisnasız çok yüksektir. Çapraz doğrulama sistematik bir öğrenme ve veri üzerinde sistematik bir çalışma modeli verdiği için başarıyı bir miktar "boost" eder; hocanın gözlemine göre başarı genelde %5 ile %10 arasında daha yüksek çıkar. Rastgele karıştırılmış veride eğitim, doğrulama ve test ayrıldığında, hiperparametreler doğrulama kümesiyle belirlendiğinde ve test tamamen ayrı tutulduğunda gerçek başarı ortaya çıkar. Bu yüzden birçok güncel çalışma çapraz doğrulama kullandığını söylemekten uzak durup veri setini kendi içinde bölümlüyor.

> **Hocanın vurgusu:** Tezinizde veri setiyle ve öğrenmeyle ilgili bir iş yapıyorsanız, gerçekten küçük bir veri seti söz konusu değilse ve kullanım gerekçesi yoksa k-katlı çapraz doğrulama kullanmayın; yanıltır. Büyük veriniz varsa veriyi rastgele dağıtarak parçalara ayırın, gerekiyorsa bunu turlar halinde yapın. k'yı yüksek seçmek de risklidir, çünkü tekrar sayısı arttıkça başarı genelde yukarı yansır.

> **Ders sonrası not:** Çapraz doğrulama doğru kullanıldığında başarıyı kendiliğinden yükseltmez; büyük olasılıkla hocanın gözlemlediği iyimserlik, aynı çapraz doğrulama skorunun hem model ve hiperparametre seçiminde hem de son başarı olarak raporlanmasından ya da ön işlemenin (öznitelik seçimi, normalizasyon) bütün veri üzerinde yapılıp sonra bölünmesinden kaynaklanır. Bu sızıntıyı önlemek için iç içe (nested) çapraz doğrulama ya da hiç dokunulmamış ayrı bir test kümesi kullanılır.

## 11. Veri İndirgeme ve Öznitelik Seçimi

### 11.1 Neden indirgeme?

Veri dönüştürüldü, entegre edildi ve temizlendi. Bundan sonraki sorun şudur: öznitelik sayısı ve veri seti büyüdükçe karmaşıklık artar. Ayrıca her öznitelik ayırt edici değildir; bazıları karar vermede yanıltabilir. Yani ne kadar çok öznitelik varsa o kadar başarılı sonuç üretileceği anlamına gelmez. Hem işlem karmaşıklığını azaltmak hem de ayak bağı olan, ayırt edici olmayan özniteliklerden kurtulmak için indirgeme (reduction) yaklaşımları uygulanır.

**Soru:** Bir veri setinde indirgeme yapacaksanız neleri eleyebilirsiniz?
**Cevap:** Bir öğrenci aşırı uç verilerin elenebileceğini söyledi. Hoca iki temel şeyin azaltılabileceğini söyledi: öznitelikler ve örnekler. Bu adımların adı öznitelik seçimi (feature selection) ve örnek seçimidir (instance selection).

Slayttaki "Data Reduction" şekli üç biçimi gösteriyordu: öznitelik seçimi (sütunların azalması), örnek seçimi (satırların azalması) ve ayrıklaştırma (discretization) (ekrandan, 02:05:00). Hoca üçüncü biçimi o anda konuşmadığını, daha önce kısmen ele alındığını söyledi.

### 11.2 Basit yöntemler: ileri ve geri yönlü seçim

**Soru:** Basit bir yöntemle öznitelik seçimine nasıl karar verirsiniz?
**Cevap:** Bir öğrenci, karar ağacında dallanmayı oluşturan özniteliklerden etkisi az olanın çıkarılabileceğini söyledi. Hoca, örneğin özniteliklerin bilgi kazancına (information gain) ve entropisine bakılabileceğini, entropinin özniteliğin gerçekten ayırt edici olup olmadığını göstereceğini ekledi.

Hocaya göre ayırt ediciliğe bakmadan önce yapılabilecek en kolay yöntemlerden biri ileri yönlü öznitelik seçimidir (forward feature selection): öznitelikler tek tek eklenerek başarının değişimi izlenir. Elinizde 20 öznitelik varsa birini eklersiniz, başarıya bakarsınız; ikinciyi eklersiniz, bakarsınız. Eklenen öznitelik fark yaratmıyorsa işleme dahil edilmez. Böylece 20 öznitelikten başarıyı artıranlar alınır. Ama bu yöntem en iyi kombinasyonu vermez: örneğin 1, 3, 7, 8 seçilmiş olabilir ama en iyi kombinasyon 2, 10, 15 olabilir. Yöntem kabaca gereksiz özniteliklerden kurtarır.

Geri yönlü öznitelik seçiminde (backward feature selection) sistem önce bütün özniteliklerle eğitilir, öznitelikler tek tek çıkarılır ve çıkarılan özniteliğin başarıya etkisine bakılır; katkısı yoksa öznitelik elenir. İleri ve geri yönlü yöntemler alt küme oluştururken hâlâ kullanılan öznitelik seçimi yöntemlerindendir. Daha önce anlatılan PCA ve LDA gibi veriyi farklı uzaylara taşıyan yöntemler de veri ve boyut indirgeme adımlarında kullanılır.

### 11.3 Öznitelik seçimi neden gereklidir?

Slayttaki gerekçeler (ekrandan, 02:10:00):

- Daha fazla öznitelik veri madenciliğinde daha fazla başarı demek değildir.
- Daha az öznitelikle çalışmak problemin karmaşıklığını ve çalışma süresini azaltır.
- Daha az öznitelikle genelleştirme yeteneği artar.
- Bazı özniteliklerin değerlerini elde etmek zor ve pahalı olabilir.

Slayttaki sonuçlar: daha az veri → algoritmalar daha hızlı öğrenir; daha yüksek doğruluk → algoritma daha iyi genelleştirir; daha basit sonuçlar → anlaşılmaları kolaylaşır. Slaytta öznitelik seçiminin uzantısının özniteliklerin çıkarılması ve inşası (extraction and construction) olduğu da yazıyordu.

Hoca, çok öznitelik olduğunda tam overfitting olmasa da önerilen modelin genelleştirilebilme ihtimalinin düştüğünü söyledi. Özniteliği sadeleştirmek karmaşıklık, genelleştirilebilirlik ve maliyet açısından avantajlıdır. Ayrıca az öznitelikle modeli birine anlatmak kolaylaşır.

**Soru:** Kararının nasıl verildiği anlaşılması zor olan algoritmaların başında hangisi gelir?
**Cevap:** Hoca kendisi cevapladı: sinir ağları. Nöronlar ve ağırlıklar vardır; hangi özniteliğin karar noktasında etkili olduğu hakkında hiçbir çıkarım yapılamaz. Veri madenciliği yapmak istiyorsanız özniteliklerin başarıya ve ilişkiye etkisini ortaya koymanız gerekir. PCA gibi bir dönüşümle yeni bir uzaya geçildiğinde de özniteliklerin problemdeki etkisini söylemek zorlaşır. Karar ağacında ise bilgi kazancıyla özniteliklerin etkisine bakılarak kararın neden verildiği net söylenebilir. Hoca sağlık örneğini verdi: doktorlar karar destek sistemlerinden bunu talep eder; doktora "sistem karar veriyor, kullan" denemez, sistem karar desteği olarak kullanılır ama kararın anlamlandırılması gerekir.

### 11.4 Öznitelik seçimi bir arama problemidir

**Soru:** n tane özniteliğiniz var ve en iyi başarıyı veren öznitelik kombinasyonunu bulmak istiyorsunuz. Bütün kombinasyonlara bakarsanız karmaşıklık nedir?
**Cevap:** Hoca bunu "çok güzel bir doktora yeterlilik sorusu" olarak niteledi. Öğrencilerden $n!$ ve "n'in m'li kombinasyonu" cevapları geldi. Bir öğrenci 4 elemanlı bir kümenin alt kümelerini düşünerek 16 alt küme olduğunu, genel formülün $2^n$ olduğunu söyledi; hoca doğru cevabın bu olduğunu belirtti.

Slaytta öznitelik seçiminin bir arama problemi olarak görülebileceği, 4 öznitelik için alt küme kafesiyle gösterilmişti: boş küme {} en üstte; {1}, {2}, {3}, {4}; ikili alt kümeler {1,2}, {1,3}, {2,3}, {1,4}, {2,4}, {3,4}; üçlü alt kümeler {1,2,3}, {1,2,4}, {1,3,4}, {2,3,4}; en altta {1,2,3,4} (ekrandan, 02:15:00). Aynı slaytın üst kısmında arama yönleri "Complete Set of Features" ve "Empty Set of Features" olarak gösteriliyordu.

Adım adım:

- Verilen: $n$ öznitelik; her öznitelik bir alt kümede ya bulunur ya bulunmaz.
- İşlem: her öznitelik için 2 seçenek olduğundan alt küme sayısı $2 \cdot 2 \cdots 2 = 2^n$ olur.
- $n = 4$ için: $2^4 = 16$ alt küme. Boş kümede öznitelik olmadığı için sayılmazsa $2^4 - 1 = 15$ olur.
- Genel sonuç: $2^n$ (boş küme hariç $2^n - 1$).

Hoca, $n = 100$ olduğunda karmaşıklığın ne kadar büyüyeceğini düşünmeyi önerdi; bu yüzden öznitelik sayısı yüksek problemlerde bütün kombinasyonlar denenemez. Teorik ve optimum çözüm budur ama uygulanamaz.

> **Ders sonrası not:** Bir öğrencinin $n!$ cevabını desteklemek için verdiği "4 faktöriyel 16" hesabı yanlıştır; $4! = 24$'tür. Alt küme sayısı $2^4 = 16$ ile faktöriyel farklı şeylerdir (python ile doğrulandı).

**Soru:** Özniteliği sabit bir sayıya (örneğin 5'e) indirmeyi mi düşünüyoruz?
**Cevap:** Hayır. En iyi kombinasyon 3 öznitelik de içerebilir, 12 öznitelik de. Kaç öznitelik seçileceği önceden bilinseydi (örneğin 5) iş kolaylaşırdı ve hesap $\binom{n}{5}$ üzerinden yapılırdı; ama bu bilgi yoktur.

Hoca bir ilginç noktayı daha vurguladı: yüksek başarı veren öznitelik kümesi başka bir sınıflandırma algoritmasında aynı başarıyı vermeyebilir. SVM'de beşli bir kombinasyonla en yüksek sonuç elde edildiyse, karar ağacında yedili ve farklı özniteliklerden oluşan bir kombinasyonla elde edilebilir. Bu yüzden genelde sınıflandırma algoritması sabit tutulur ve öznitelikler ona göre kombinlenerek denenir. Bilgi kazancı ise özniteliklerin ayırt ediciliğini sınıflandırıcıdan bağımsız değerlendirir.

### 11.5 Filter ve wrapper yaklaşımları

Slayttaki tanımlar (ekrandan, 02:20:00):

- Filter: amaç fonksiyonu alt kümeleri içerdikleri bilgiye göre değerlendirir. Sınıf ayrılabilirliği ölçüleri, istatistiksel bağımlılıklar ve bilgi teorisi gibi ölçüler amaç fonksiyonu olarak kullanılır.
- Wrapper: amaç fonksiyonu, seçilen özniteliklerle elde edilen veri üzerinde daha sonra kullanılacak öğrenme tekniğinin aynısının uygulanmasından oluşur. Döndürülen değer genellikle kurulan sınıflandırıcının doğruluk oranıdır.

Hocanın açıklaması: filter yöntemlerinde bilginin ayırt ediciliği farklı yöntemlerle değerlendirilir ve hiçbir sınıflandırma algoritması kullanılmaz; tamamen verinin dağılımına ve istatistiksel yapısına bakılır. Filter size öznitelikleri en ayırt ediciden en az ayırt ediciye doğru sıralar (ranking) ve etkilerini gösterir; Weka'daki karşılığı ranker'lardır. Wrapper yöntemlerinde bir sınıflandırıcı vardır ve onun performansına bakarak karar verilir; size doğrudan bir alt küme verir ("3, 5, 9, 12'yi kullanırsan en iyi başarıyı elde edersin"). Bu alt kümeyi bütün alt kümeleri deneyerek değil, kullandığı yönteme (ileri ya da geri yönlü seçim gibi) bağlı olarak bulur.

Korelasyon ve bilgi teorisi:

- Korelasyonun sağladığı bilgi: birbiriyle ilişkili iki öznitelik varsa birinden kurtulmayı sağlar; bir öznitelik sınıfla ilişkiliyse onun ayırt ediciliğinin yüksek olduğunu gösterir.
- Slayta göre korelasyon yalnız doğrusal bağımlılıkları tahmin edebilir; karşılıklı bilgi (mutual information) daha güçlü bir yöntemdir. Hoca bunun entropi bilgisine dayandığını söyledi.

> **Ek bilgi (derste anlatılmadı):** İki değişken arasındaki karşılıklı bilgi $I(X;Y) = H(Y) - H(Y \mid X)$ ile tanımlanır; X bilindiğinde Y hakkındaki belirsizliğin ne kadar azaldığını ölçer. Karar ağaçlarındaki bilgi kazancı, bir özniteliğin sınıf etiketiyle karşılıklı bilgisine karşılık gelir ve doğrusal olmayan ilişkileri de yakalar.

Slayttaki avantajlar (ekrandan, 02:25:00):

- Wrapper, doğruluk: amaç fonksiyonunda kullanılan sınıflandırıcı ile eğitim verisi arasındaki etkileşim sayesinde genellikle filter'lardan daha doğrudur.
- Wrapper, genelleştirme yeteneği: kullanılan doğrulama teknikleri sayesinde aşırı uyumdan kaçınma kapasitesi vardır.
- Filter, hız: genelde frekans hesaplarlar; sınıflandırıcı eğitmekten çok daha hızlıdır.
- Filter, genellik: sınıflandırıcıyla etkileşimlerini değil verinin içsel özelliklerini değerlendirdikleri için her problemde kullanılabilirler.

**Soru:** Slayta göre filter'ın "generality" maddesi neyi vurguluyor?
**Cevap:** Öğrencilerden hız, aşırı uyumdan kaçınma ve çözümün genelleştirilebilmesi cevapları geldi. Hoca, verinin sınıflandırıcıdan bağımsız olarak karakteristiğinin ortaya konmasını vurguladığını söyledi. Wrapper'da başarı o sınıflandırma probleminin özelinde değerlendirilir. Ama aynı veri birçok yerde kullanılır: örneğin bir hastanın verileri bir hastalığın tedavisinde kullanılıyorsa o hastalığa özel karar verilir; ama kişinin bütün verilerinin genel karakteristiği ve ne kadar ayırt edici olduğu hakkındaki fikir filter'lardan alınır.

> **Hocanın vurgusu:** Verinin karakteristiğini ve ayırt ediciliğini tartışmak ve ortaya koymak istiyorsanız filter kullanmanız gerekir. Bir sınıflandırma problemine özel başarıyı ortaya çıkarmak istiyorsanız wrapper kullanmanız gerekir.

Dezavantajlar: filter'larda çok sayıda değişken elde kalır, çünkü problemin çözümüne az da olsa katkısı olan değişkeni dışarı çıkarmaz; yalnız sıralama değeri sıfırsa, yani hiç katkısı yoksa dışarıda tutulabilir. Wrapper'ların dezavantajı ise maliyetin yüksek olması ve sınıflandırıcıya özel bir çözüm üretmesidir.

## 12. Örnek Seçimi

### 12.1 Parmak izi kavramı

Hoca örnek seçiminin çok kritik olduğunu söyledi ve önceki derslerde Shazam, SoundHound ve Face ID örneklerinde geçen bir anahtar kelimeyi sordu.

**Soru:** Örnek seçimini bir anahtar kelimeyle ilişkilendirseniz bu ne olurdu?
**Cevap:** Bir öğrenci maliyeti doğrudan etkileyen bir faktör olduğunu, ardından "özet, hash" olabileceğini söyledi. Hoca özet, hash ve parmak izi (fingerprint) anahtar kelimelerinin kullanılabileceğini doğruladı.

Öznitelik tarafında parmak izi, örneğin bir yüzün ayırt edici özellikleriyle ilgilidir. Örnek tarafında ise doğru örnekleri seçmek öğrenmeyi hızlandırır ya da performansı artırır. Birebir aynı özelliğe sahip ya da aynı bölgedeki örneklerden beş, on tane olmasının çok katkısı olmaz. Bu yüzden örnekler, veri setinin parmak izini çıkaracak şekilde seçilmelidir: öznitelik seçimi bir yüzün parmak izini çıkarırken, örnek seçimi veri setindeki yüzlerin farklılığını çıkarır. Hocanın örneği: birinden 50 fotoğraf, diğerinden 2 fotoğraf konursa ilk kişiden 50 fotoğraf almanın pek yararı yoktur; bir insan yüzünün farklı açıları (düz, hafif açılı vb.) olsa olsa 8 tane olur. Farklı ışık, karanlık ve aydınlık ortam, gözlüklü ve sakallı fotoğraflar gerçekten fark yaratır; ama aynı açıdan üç yan fotoğrafın katkısı yoktur ve bunlardan kurtulmak gerekir.

Slaytta aynı şeklin 8000, 2000 ve 500 noktayla gösterildiği "Different size examples" görseli vardı; nokta sayısı azalsa da şekil seçilebiliyordu. Aynı sayfada örnek seçiminin uzantısının yeni örnek üretimi (prototype generation) olduğu yazıyordu (ekrandan, 02:30:00).

### 12.2 Örnek seçiminin algoritmalara etkisi

Örnek seçimi, model kurulurken birbirine benzeyen ya da aykırı olma ihtimali olan örneklerden kurtulmaktır. K-NN'in test maliyetinin yüksek olduğu söylenmişti; veri setindeki örnek sayısı azaltılırsa karşılaştırılacak örnek sayısı azaldığı için K-NN'e doğrudan katkı sağlanır. Karar ağacı kurulurken her seferinde bütün örnekler ve öznitelikler gezilerek bir yapı oluşturulur; yeni örnekler eklendikçe ağacın baştan kurulması gerekir ve bu uzun bir öğrenme süreci demektir.

**Soru:** Sinir ağında yeni bir örnek geldiğinde yeniden öğrenme gerekir mi?
**Cevap:** Hayır; önceki verilerle yeniden eğitmeye gerek yoktur. Yalnızca sistemdeki ağırlık değerleri güncellenir. Sinir ağlarının öğrenme sürecinin uzun olduğu söylenmişti, ama yeni örnekle evrilirken karar ağacı bütün işi tekrar yaparken sinir ağına tek örnek verilir, ağırlıklar güncellenir ve iş biter.

Örnek seçimi hem modelin karmaşıklığı hem öğrenme karmaşıklığı açısından işi kolaylaştırır; daha az örnekle çalışmak maliyet açısından ciddi avantaj sağlar ve kararı yanıltan örnekleri temizler. Bu da bir ön işleme adımıdır.

### 12.3 Alan bilgisine dayalı seyreltme

Derste konuşulan bir örnekte, sık aralıklarla kaydedilen ama kaynağı daha seyrek güncellenen frekans değerlerinde aynı değerlerin tekrar tekrar kullanılması anlamsız olduğu için tekrar eden kayıtlar eleniyordu.

Hoca bunun örnek seçimine güzel bir örnek olduğunu ama burada sofistike bir karar bulunmadığını söyledi. Sık örneklenen ivmeölçer ve jiroskop verisinde, konum değişmiyorsa GPS verisinde ardışık kayıtlar birbirine benzer. Trafikteki araçların hız verisinde de durum aynıdır: dakikada bir alınan hız verisini tek tek değerlendirmek yerine 5 dakikalık kararlar vermek daha akıllıcadır. Bu durumda örnekler elenmiş olur ama özel bir algoritma kullanılmaz; alan bilgisi kullanılarak ara adım olarak gereksiz (redundant) veri çıkarılmış olur. Bu, verinin sık tekrar ettiği durumlarda yükü azaltmak için sık kullanılan bir yaklaşımdır.

## Örnek Sorular

**1. (derste sözlü, 00:04:19)** K-NN algoritmasının eğitim (model oluşturma) karmaşıklığı nedir, nelere bağlıdır?

> **Cevap (derste verildi):** K-NN'in öğrenme adımı yoktur; örnek tabanlı (instance-based) bir algoritmadır, örnekleri saklar ve test anında yeni örneğe uzaklıkları hesaplar. Asıl maliyet test tarafındadır ve mobil cihazlarda bu önemlidir. K-NN sınıflandırma algoritmasıdır; K-Means ile karıştırılmamalıdır.

**2. (derste sözlü, 00:25:01)** Ayrıklaştırılabilecek sürekli verilere örnek veriniz.

> **Cevap (derste verildi):** Yaşın bebek, çocuk, genç, yetişkin, yaşlı gibi gruplara ayrılması; şirket verilerinin çeyreklere bölünmesi; sıcaklığın soğuk, serin, ılık, sıcak diye gruplanması; ders notlarının harf notlarına çevrilmesi.

**3. (derste sözlü, 00:31:06)** Haftanın günleri label encoding ile 1-7 arasında kodlanırsa ne sorun çıkar? One-hot encoding bunu nasıl çözer?

> **Cevap (derste verildi):** Label encoding'de pazartesi (1) ile salı (2) arasındaki uzaklık 1, pazartesi ile cuma (5) arasındaki uzaklık 4 olur; bu uzaklık anlamlı değilse model yanılır. One-hot encoding'de "gün" özniteliği 7 ayrı özniteliğe çevrilir; pazartesi örneğinde pazartesi özniteliği 1, diğer 6 öznitelik 0 olur.

**4. (derste sözlü, 00:38:05)** PCA ile LDA arasındaki fark nedir? Hangisi unsupervised problemlerde kullanılabilir?

> **Cevap (derste verildi):** PCA sınıf bilgisi kullanmadan uzay değiştirir; bu yüzden unsupervised problemlerde de kullanılabilir. LDA sınıflar arası uzaklığı maksimize, sınıf içi uzaklığı minimize ederek sınıf bilgisini kullanır ve genelde biraz daha iyi sonuç verir.

**5. (derste sözlü, 00:54:08)** Eksik verileri düzeltmek için hangi yöntemler kullanılabilir?

> **Cevap (derste verildi):** Eksikliği standart bir işaretle (-1, N/A) belirtmek; veri bolsa ve eksik oranı düşükse örneği atmak; bütün örneklerin ortalaması; aynı sınıftaki örneklerin ortalaması; medyan; en olası değer (Bayes ya da karar ağacıyla çıkarım); eksik öznitelik dışındaki özniteliklere göre en benzer k örneğin değerleri (K-NN); sınıf bilgisi yoksa K-Means kümelemesiyle eksik örneğin düştüğü kümedeki değerler.

**6. (derste sözlü, 01:04:56)** K-Means kullanarak eksik bir öznitelik değeri nasıl doldurulur?

> **Cevap (derste verildi):** Bütün örnekler, eksik özniteliğin dışındaki özniteliklerle k kümeye ayrılır. Eksik örneğin düştüğü kümedeki örneklerin o öznitelikteki değerlerine bakılarak doldurma yapılır. Sınıf bilgisi olmayan problemlerde en akılcı yoldur.

**7. (derste sözlü, 01:08:38)** Doğrusal olmayan problemlerde çok yüksek dereceli eğriler neden istenmez? Underfitting nedir?

> **Cevap (derste verildi):** Hesap yükü getirir ve daha önemlisi aşırı uyuma (overfitting) yol açar; model veriyi ezberler, genelleştirme düşer. Underfitting ise modelin fazla basit kalması ve öğrenememesidir; örneğin iç içe dağılmış iki sınıf arasına tek bir doğru çekilirse örneklerin en az %20'si yanlış tarafta kalabilir.

**8. (ekrandan, 01:10:00)** Sınıflandırmada güvenli, sınırdaki ve gürültülü örnekler nedir? Destek vektörleri kurulurken hangi örnekler zorlar?

> **Cevap (derste verildi):** Güvenli örnekler kendi sınıflarının içinde, sınırdaki (borderline) örnekler iki sınıfın birbirine geçtiği karar sınırı yakınında, gürültülü örnekler diğer sınıfın içine düşmüş örneklerdir. Zorlayan örnekler borderline örnekler ve aykırı değerlerdir.

**9. (derste sözlü, 01:18:22)** Bir örneğin aykırı değer olarak elenmesi için hangi iki ölçüt birlikte kullanılır?

> **Cevap (derste verildi):** Merkezden belli bir yarıçapın (R) dışında olmak ve çevresinde yeterince örnek bulunmamak. Uzakta tek örnek elenmeye adaydır; uzakta 50 örneklik bir grup yalnız uzaklığa bakılarak atılmamalıdır.

**10. (derste sözlü, 01:26:44)** Telefonda mecburen bir öğrenme yaptırılacaksa bu ne zaman yapılmalıdır?

> **Cevap (derste verildi):** Telefon şarjdayken. İşletim sistemlerinin güncellemeyi şarjda, büyük indirmeleri Wi-Fi'de yapması aynı mantığa dayanır.

**11. (ekrandan, 01:35:00)** Ensemble Filter nasıl çalışır? 5 sınıflandırıcıdan 3'ü bir örneği yanlış etiketlerse örnek consensus ve majority oylamasında elenir mi? Yöntemin dezavantajı nedir?

> **Cevap (derste verildi):** Farklı algoritmalarla (C4.5, 1-NN, LDA) sınıflandırıcılar kurulur; her biri için k-katlı çapraz doğrulamayla her eğitim örneği "correct" ya da "mislabeled" diye etiketlenir, sonra oylama yapılır. 5'te 3 yanlış etiket, yarıdan fazla olduğu için majority voting'de örneği eler; consensus voting'de elemek için 5 sınıflandırıcının hepsinin yanlış etiketlemesi gerekir, bu yüzden elenmez. Dezavantajı maliyettir; önce basit bir elemeyle aday seçip yalnız onları filtreye vermek (hibrit yapı) maliyeti azaltır.

**12. (derste sözlü, 01:56:13)** K-katlı çapraz doğrulamanın dezavantajları nelerdir? Büyük veri setlerinde neden eğitim/doğrulama/test ayrımı tercih edilir?

> **Cevap (derste verildi):** Uzun sürer; veri karıştırılmadan bölünürse bir sınıfın örnekleri tek parçada toplanabilir. Hocaya göre çapraz doğrulama başarıyı yapay olarak yükseltir (deneyimine göre %5-%10); büyük veride rastgele karıştırılıp ayrılmış, hiperparametre seçimine katılmayan bir test kümesi gerçek başarıyı verir. Çapraz doğrulama küçük veri setleri için ortaya atılmıştır.

**13. (derste sözlü, 02:03:58)** Bir veri setinde indirgeme yapılacaksa neler azaltılabilir?

> **Cevap (derste verildi):** Öznitelikler (öznitelik seçimi) ve örnekler (örnek seçimi). Slaytta üçüncü biçim olarak ayrıklaştırma da gösteriliyordu.

**14. (ekrandan, 02:15:00)** n öznitelik içinden en iyi başarıyı veren öznitelik kombinasyonunu bütün olasılıkları deneyerek bulmak istersek kaç alt kümeyi denememiz gerekir? 4 öznitelik için sayı nedir?

> **Cevap (derste verildi):** Her öznitelik bir alt kümede ya bulunur ya bulunmaz; alt küme sayısı $2^n$'dir. Boş küme sayılmazsa $2^n - 1$. $n = 4$ için $2^4 = 16$ (boş küme hariç 15) alt küme vardır; python ile doğrulandı. $n = 100$ gibi değerlerde bu sayı uygulanamayacak kadar büyür, bu yüzden ileri/geri yönlü seçim gibi sezgisel yöntemler kullanılır.

**15. (ekrandan, 02:20:00)** Öznitelik seçiminde filter ve wrapper yaklaşımları arasındaki fark nedir? Her birinin avantajı ve dezavantajı nedir?

> **Cevap (derste verildi):** Filter, sınıflandırıcı kullanmadan verinin istatistiksel yapısına (korelasyon, karşılıklı bilgi, entropi) bakar ve öznitelikleri sıralar; hızlıdır ve sınıflandırıcıdan bağımsız olduğu için her problemde kullanılabilir, ama az katkılı çok sayıda değişkeni elde tutar. Wrapper, sonradan kullanılacak sınıflandırıcının doğruluğuyla alt küme seçer; genelde daha doğrudur ve doğrulama sayesinde aşırı uyumdan kaçınır, ama maliyetlidir ve sınıflandırıcıya özeldir.

**16. (derste sözlü, 02:29:34)** Örnek seçimi hangi anahtar kavramla ilişkilendirilebilir? K-NN ve sinir ağı açısından önemi nedir?

> **Cevap (derste verildi):** Özet, hash, parmak izi (fingerprint): seçilen örnekler veri setinin parmak izini taşımalıdır. K-NN'de örnek sayısını azaltmak test maliyetini doğrudan düşürür. Karar ağacı yeni örnekle baştan kurulurken sinir ağında yalnız ağırlıklar güncellenir, yeniden eğitime gerek yoktur.

## Dersin Toparlaması

Ders, K-NN'in eğitim adımı olmadığı ve asıl maliyetin test tarafında olduğu sorusuyla açıldı ve bu fikir ders boyunca mobil teknolojiler açısından tekrar tekrar kullanıldı: telefon, saat ve IoT cihazlarında test karmaşıklığı düşük modeller çalıştırılmalı, ağır öğrenme sunucuda ya da cihaz şarjdayken yapılmalı, veri mümkünse olduğu yerde işlenip yalnız bilgi merkeze gönderilmelidir. Ardından veri ön işlemenin adımları sırayla işlendi: farklı kaynaklardan gelen verinin entegrasyonu, tip uyuşmazlıklarının ve tutarsızlıkların temizlenmesi, ayrıklaştırma, label ve one-hot encoding, PCA ve LDA ile boyut indirgeme, eksik verinin ortalama, medyan, K-NN ve K-Means ile tamamlanması, aykırı değerlerin uzaklık ve yoğunluk ölçütleriyle bulunması ve Ensemble Filter ile gürültülü örneklerin ayıklanması.

Dersin son bölümünde k-katlı çapraz doğrulamanın küçük veri için tasarlandığı ve büyük veride başarıyı olduğundan yüksek gösterebileceği tartışıldı. Veri indirgeme kapsamında öznitelik seçimi (ileri ve geri yönlü seçim, $2^n$ alt küme sorunu, filter ve wrapper yaklaşımları) ve örnek seçimi (veri setinin parmak izini taşıyan örnekleri seçmek) anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
