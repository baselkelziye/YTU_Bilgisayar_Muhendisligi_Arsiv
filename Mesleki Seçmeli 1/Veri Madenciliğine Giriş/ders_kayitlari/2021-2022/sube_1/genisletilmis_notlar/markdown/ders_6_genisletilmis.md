# Ders 6 Genişletilmiş Notu: Ayrıklaştırma, Kavram Hiyerarşisi ve Veri Azaltma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ayrıklaştırma: Binning
- 2. Kümeleme ile Ayrıklaştırma
- 3. Sınıflandırma ile Ayrıklaştırma
- 4. Kavram Hiyerarşisi
- 5. Veri Azaltma ve Boyutun Etkisi
- 6. Boyut Azaltma: Wavelet Dönüşümü ve PCA
- 7. Öznitelik Alt Kümesi Seçimi
- 8. Sayıca Azaltma: Veri Küpü Toplaması
- 9. Sayıca Azaltma: Örnekleme
- Örnek Sorular

## 1. Ayrıklaştırma: Binning

Ders, önceki derste başlanan veri ön işleme slaytlarının ayrıklaştırma (discretization) kısmından devam etti. Ayrıklaştırmanın amacı, elimizdeki sürekli (continuous) değerleri bir şekilde ayrık değerlere dönüştürmektir. Bunun ilk yolu binning'dir: değer aralığı parçalara (bin) bölünür ve her değer düştüğü binin etiketini alır.

Bölme iki biçimde yapılabilir. Eşit genişlikli (equal-width) binning'de aralıklar aynı genişliktedir. Eşit frekanslı (equal-frequency) binning'de ise her bine eşit sayıda eleman düşecek şekilde bölünür; bunun için her değerden kaç tane olduğu sayılır. Bölmeden sonra her değere ait olduğu binin etiketi verilir; etiketlendirme ya da isimlendirme kullanıcıya bırakılabilir.

Hoca burada bir soru sordu: binning sınıf bilgisini, yani etiketi (label) kullanıyor mu? Cevap hayırdır; binning yalnız değerlere bakıp ayırır. Bu yüzden binning denetimsiz (unsupervised) bir ayrıklaştırma yöntemidir. Aralıkları tamamen kullanıcı belirlediği için aslında basit bir kümeleme tekniği olarak da görülebilir.

> **Hocanın vurgusu:** Binning etiket kullanmaz, yalnız değerlere bakar; bu nedenle denetimsiz bir yöntemdir.

### 1.1 Eşit genişlik örneği

Slayttaki örnekte fiyat (price) özniteliğinin değerleri 5'ten başlayıp 215'e kadar gidiyordu ve toplam 12 değer vardı. Veri üç eşit genişlikli bine bölündü. Hoca bin genişliğini 70 olarak aldı ve "215'i 3'e bölerseniz tam 70 çıkmaz, yuvarlandığı için 70" dedi. Altyazıya göre 0-70 arasındaki değerler birinci bine, 70-140 arasındakiler ikinci bine, 140-210 ve sonrası üçüncü bine yerleştirildi; binlere 1, 2, 3 etiketleri verildi. Hoca bu işlemin aslında bir if-else zinciri gibi olduğunu söyledi: değer şu aralıktaysa 1, şu aralıktaysa 2, aksi halde 3.

<!-- BELİRSİZ: 12 değerlik fiyat listesi ve slayttaki bin sınırları elde edilen karelerde yok; sınırlar altyazıdan alındı. -->

> **Ders sonrası not:** Eşit genişlikli binning'de bin genişliği genellikle $w = (\max - \min)/k$ ile hesaplanır. Burada $w = (215 - 5)/3 = 70$ eder; yani 70 değeri yuvarlamadan değil, en küçük değerin çıkarılmasından gelir ($215/3 \approx 71.7$). Bu formülle sınırlar büyük olasılıkla 5-75, 75-145, 145-215 olur. Altyazıdaki 0-70, 70-140, 140-210 sınırları bu formülle uyuşmuyor; slaytta hangi sınırların yazdığı karede görülemedi.

### 1.2 Eşit frekans örneği

Eşit frekansta önce değerler sıralanır. Toplam 12 eleman olduğu için ilk dört eleman birinci bine, ikinci dört eleman ikinci bine, son dört eleman üçüncü bine konur. Buna frekansa göre binning denir.

## 2. Kümeleme ile Ayrıklaştırma

Kümeleme algoritmaları (k-means gibi) henüz derste görülmedi; bunlar veriyi otomatik olarak kümelere ayırmaya çalışır. Slaytta k-means kullanılmamış, daha basit bir fikir gösterilmişti: sıralı sayılar arasındaki boşluğa (gap) bakmak.

Yöntem şöyle işler. Önce ardışık değerler arasındaki en büyük fark bulunur; örnekte bu 89 ile 204 arasındaydı. Veri buradan ikiye ayrılır: 89'a kadar olanlar bir küme, 204 ve sonrası başka bir küme olur. Sonra kalan boşluklar arasında en büyüğü aranır; örnekte bu fark 20 idi ve 15 ile 35 arasında bulunuyordu. Veri buradan bir kez daha ayrılır ve sonuçta üç küme elde edilir. Kaç küme isteneceği kullanıcıya bağlıdır.

<!-- BELİRSİZ: Değer listesi karede yok; 89-204 ve 15-35 boşlukları altyazıdan alındı. -->

Bu yöntem de etiket kullanmadığı için denetimsizdir.

## 3. Sınıflandırma ile Ayrıklaştırma

Ayrıklaştırma etiketlere göre de yapılabilir; bunun için genellikle karar ağacı kullanılır. Slayttaki maddeler şöyleydi (ekrandan, 00:05:00):

- Karar ağacı gibi bir sınıflandırma algoritmasında kullanılan teknikler ayrıklaştırmaya uygulanabilir.
- Karar ağacıyla ayrıklaştırma denetimlidir (supervised), yani sınıf etiketi bilgisini kullanır.
- Bu teknikler öznitelik değerleri için yukarıdan aşağı bölme (top-down splitting) yaklaşımı kullanır:
  - Bölme noktalarının hesaplanmasında ve belirlenmesinde sınıf dağılımı bilgisi kullanılır.
  - Ana fikir, bölme noktalarını oluşan her parçada mümkün olduğunca aynı sınıftan örnek (tuple) kalacak şekilde seçmektir.
    - Bu amaçla en sık kullanılan ölçü entropidir.
- Sınıflandırma algoritmaları ileride anlatılacak.

Hoca bunu şöyle açıkladı: üç sınıfınız olduğunu ve sürekli bir değeriniz olduğunu düşünün. "Değer şu aralıktaysa A sınıfı, şu aralıktaysa B sınıfı" gibi kurallar yazmak istersiniz. Bu aralıkların entropi kullanılarak otomatik öğrenilmesi sağlanır. Ayrıntı, karar ağaçlarında yaprakların ve düğümlerin entropiyle nasıl belirlendiği görüldüğünde anlatılacak. Korelasyon analiziyle ayrıklaştırma slaytı ise geçildi.

## 4. Kavram Hiyerarşisi

Ayrıklaştırmada kullanılan bir diğer kavram, kavram hiyerarşisidir (concept hierarchy). Bunu bir piramit gibi düşünmek gerekir: her zaman bir üst seviye vardır ve üst seviye alttaki seviyeleri kapsar. Bir ağaç gibi de düşünülebilir; ağaçtaki her seviye kendi dallarını kapsar. Bu hiyerarşiler çoğu zaman veri tabanının içinde zaten bulunur; ya istatistiksel analizden çıkarılır ya da elle oluşturulur.

### 4.1 Fiyat örneği

Elinizde 0 ile 1000 dolar arasında fiyatlar olduğunu düşünün. Bu aralık önce 0-200, 200-400 gibi parçalara bölünür; bu parçalar daha küçük parçalara bölünmeye devam eder ve hiyerarşi aşağı iner. Slaytta 100'er 100'er bölünmüş olması bir kural değildir; aralıkların eşit olması gerekmez, sınırlar istatistiksel değerlerden çıkar. Üst seviyeyi seçtiğinizde az sayıda (örneğin 5) ayrık değer, bir alt seviyeyi seçtiğinizde daha çok (örneğin 10) ayrık değer elde edersiniz. Hiyerarşi elle belirlenebileceği gibi entropi gibi istatistiksel ölçülerle de belirlenebilir.

### 4.2 Nominal öznitelikler için hiyerarşi

Hocanın daha iyi bulduğu örnek zaman hiyerarşisidir: yıl, yılın çeyreği, ay, gün. Buna paralel olarak hafta da yıla bağlanır; örneğin nisan ayındaki bir gün hem "ikinci çeyreğin şu ayının şu günü" hem de "yılın şu haftası" olarak ifade edilebilir. Konum için de benzer bir hiyerarşi vardır: ülke, eyalet, şehir. Analizde şehirler yerine yalnız eyalet ya da yalnız ülke düzeyi kullanılabilir.

## 5. Veri Azaltma ve Boyutun Etkisi

Hoca bu bölüme bir çelişkiyle girdi: şimdiye kadar eksik değerleri doldurarak veriyi çoğaltmaya çalıştık, şimdi ise veriyi azaltacağız. Veriyi azaltmak, veriyi sıkıştırmak, boyutunu küçültmek ya da bazı öznitelikleri doğrudan atmak olabilir.

Slayttaki tanım ve gerekçe şöyleydi (ekrandan, 00:10:00):

- **Veri azaltma:** Veri kümesinin hacimce çok daha küçük, ama aynı (ya da neredeyse aynı) analiz sonuçlarını üreten bir temsilini elde etmek.
- **Neden?** Bir veri tabanı ya da veri ambarı terabaytlarca veri tutabilir; karmaşık veri analizi tüm veri kümesi üzerinde çok uzun sürebilir.
- **Stratejiler:**
  - Boyut azaltma (dimensionality reduction), örneğin önemsiz öznitelikleri çıkarmak: wavelet dönüşümleri, temel bileşenler analizi (PCA), öznitelik alt kümesi seçimi ve öznitelik oluşturma.
  - Sayıca azaltma (numerosity reduction): veri küpü toplaması, örnekleme, kümeleme.

### 5.1 Öznitelik sayısı ve uzay

Algoritmaların bir uzayda çalıştığını düşünmek gerekir. Yalnız iki sütununuz (özniteliğiniz) varsa her satır, yani her nesne, iki boyutlu uzayda bir noktadır: x ekseni birinci öznitelik, y ekseni ikinci özniteliktir. Bir sütun eklerseniz uzay üç boyutlu, bir sütun daha eklerseniz dört boyutlu olur. Bin öznitelikli bir veri bin boyutlu bir uzay demektir.

Derste görülecek algoritmaların çoğu optimizasyonla çalışır ve her zaman yüzde yüz doğru sonuç vermez; örneğin yerel minimumu bulur. Çok büyük veride bellek (RAM) yetmeyebilir. Bu yüzden verinin çok olması her zaman iyi değildir.

> **Hocanın vurgusu:** Verinin çok büyük olması her zaman avantaj değildir; çok boyutlu büyük uzayda algoritmalar zorlanır, bellek yetmeyebilir.

Boyut arttıkça veri daha dağınık hale gelir ve uzayda birbirinden uzak yerlere düşmeye başlar (boyutun laneti, curse of dimensionality). İstenen, verinin daha az boyutta, daha toplu durmasıdır; bu hem algoritmanın hem de diğer işlemlerin maliyetini düşürür.

Yapılabilecek ilk şey öznitelikler arasındaki korelasyonlara bakmaktır: iki öznitelik aynı şeyi söylüyorsa birini elemek. İkincisi boyutu azaltmaktır.

## 6. Boyut Azaltma: Wavelet Dönüşümü ve PCA

### 6.1 Wavelet dönüşümü

Hoca önce Fourier dönüşümünü hatırlattı: bir sinyaldeki frekanslara bakarak sinyali baskın frekans ya da frekanslar cinsinden ifade etmeyi sağlar, yani zamandan frekansa dönüştürür. Wavelet dönüşümü buna zaman bilgisini de ekler; zamana bağlı veriyi alıp tamamen farklı bir biçimde ifade etmeyi sağlar.

Veri madenciliğinde her satır (her nesne) bir sinyal gibi düşünülür. Wavelet, verinin içindeki tekrarlayan yapılara bakar; bazı bileşenlerin frekansı diğerlerinden fazladır. Konum bilgisi de tutulduğu için hangi sütuna karşılık geldiği bilinir; önemli bileşenler alınır, diğerleri atılır. Böylece örneğin bin sütun yedi yüz ya da sekiz yüz sütuna indirilebilir. Hoca, wavelet'i ayrıntılı anlatmanın en az üç hafta süreceğini söyleyerek geçti.

### 6.2 Temel bileşenler analizi (PCA)

PCA tamamen lineer cebire dayanır. Örneğin bin sütunlu, bir milyon satırlı bir veri alınır; özdeğer (eigenvalue) ve özvektörler (eigenvector) bulunarak sütunlar ve satırlar arasındaki ilişkiye bakılır, fazlalık olan kısım çıkarılır. En önemli bileşenler bırakılır, daha az etkileyenler atılır. Hoca bunu şöyle özetledi: bir şeyi on özelliğin hepsine bakarak değil, yedi özellikle ifade edebilir miyim?

> **Ek bilgi (derste anlatılmadı):** PCA, verinin kovaryans matrisinin özvektörlerini bulur ve veriyi en büyük özdeğerlere karşılık gelen özvektörlerin oluşturduğu yeni eksenlere izdüşürür. Bu yeni eksenler (temel bileşenler) birbirine diktir ve verideki varyansın büyük kısmını ilk birkaç bileşende toplar.

Wavelet ve PCA'nın arkasında ciddi matematik vardır, ama kütüphaneleri hazırdır ve çok sık kullanılırlar. İkisi de bilgi kaybıyla çalışır: bin boyutlu veri yedi yüz boyutla birebir aynı değil, benzer şekilde ifade edilir.

## 7. Öznitelik Alt Kümesi Seçimi

Boyut azaltmanın bir başka yolu gereksiz ve ilgisiz öznitelikleri atmaktır. Slayttaki tanımlar (ekrandan, 00:15:00):

- Analiz için kullanılan veri kümeleri yüzlerce öznitelik içerebilir; bunların çoğu madencilik görevi için ilgisiz (irrelevant) ya da gereksiz (redundant) olabilir.
- **Gereksiz öznitelikler**, bir ya da daha fazla başka öznitelikteki bilginin çoğunu ya da tamamını tekrarlar. Örnek: bir ürünün fiyatı ile ödenen satış vergisi büyük ölçüde aynı bilgiyi içerir.
- **İlgisiz öznitelikler**, veri madenciliği görevi için neredeyse hiç yararlı bilgi içermez. Örnek: öğrencilerin notunu tahmin etmek için öğrenci kimlik numaraları ilgisizdir.
- **Öznitelik alt kümesi seçimi**, ilgisiz ya da gereksiz öznitelikleri çıkararak veri kümesini küçültür.
  - Amaç, veri sınıflarının olasılık dağılımı tüm özniteliklerle elde edilen dağılıma mümkün olduğunca yakın olacak şekilde en küçük öznitelik kümesini bulmaktır.
  - Bulunan örüntülerde yer alan öznitelik sayısını azaltır ve örüntülerin anlaşılmasını kolaylaştırır.

Hoca gereksizlik için derste ayrıca şu örneği verdi: bir tabloda satış fiyatı, yanında yüzde on sekiz vergi ve bir de toplam tutar sütunu bulunabilir; bunlar aynı bilgiyi tekrarlar. Bir sütun tahmin edilecek şeyle hiçbir ilgisi olmayan bir bilgi taşıyorsa o da atılabilir.

### 7.1 Alt küme nasıl aranır?

Bu yöntemler genellikle optimizasyon algoritmaları üzerinden çalışır. Sınıflandırma yapacağınızı ve on özniteliğiniz olduğunu düşünün. Algoritma alt kümeleri dener: 3., 5. ve 7. özniteliklerle ne kadar iyi tahmin ediyorum? 3., 5., 6. ve 7. ile ne kadar iyi? Tahmin on öznitelikle de yapılabilir; aranan, on özniteliğin hangi alt kümesiyle bu tahmine en yakın sonucun alındığıdır.

Hoca bu yöntemlerin genelde pek iyi çalışmadığını açıkça söyledi, çünkü tüm alt kümelere bakılamaz. On öznitelik için ikili, üçlü, beşli tüm kombinasyonlara bakmak gerekir; $n$ öznitelik için $2^n$ alt küme vardır. Kaba kuvvet (brute force), yani bütün kombinasyonları denemek, büyük veride çalışmaz.

Bunun yerine sezgisel (heuristic) yöntemler kullanılır. Adım adım (stepwise) ilerlenir: en iyi öznitelik eklenir; skoru iyileştiriyorsa ya da düşürmüyorsa devam edilir; birkaç kez eklendiğinde sonucu kötüleştiren bir özniteliğe bir daha bakılmaz. Hoca ayrıca kullanıcının deneme yanılmayla öznitelik aralıklarını (örneğin önce bir grup özniteliği, sonra başka bir grubu) çalıştırıp hangisinin daha iyi sonuç verdiğine bakarak en iyi alt kümeyi seçmesinden de söz etti; bunun kötü bir yöntem olduğunu ama yine de sık kullanıldığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Adım adım seçimin iki yaygın türü ileri seçim (forward selection: boş kümeden başlayıp her adımda en iyi özniteliği ekleme) ve geriye doğru eleme (backward elimination: tüm özniteliklerle başlayıp her adımda en kötüsünü çıkarma) olarak bilinir.

Wavelet dönüşümünün ayrıntılı slaytları ise temeli ağır olduğu için geçildi.

## 8. Sayıca Azaltma: Veri Küpü Toplaması

Veri, öznitelik atmadan da azaltılabilir. Yıllara ve çeyreklere göre yapılan satışların tutulduğu bir veri düşünün. Analizde yıllık satışlar ilgileniyorsa, her yılın çeyreklik satışları toplanıp tek değer olarak yazılabilir. Buna veri küpü toplaması (data cube aggregation) denir. Hoca bunu Excel'deki pivot tablolara benzetti: veri üzerinde işlem yapılarak özet elde edilir.

Slayttaki örnek (ekrandan, 00:20:00):

| Çeyrek (2002) | Satış |
|---|---|
| Q1 | \$224,000 |
| Q2 | \$408,000 |
| Q3 | \$350,000 |
| Q4 | \$586,000 |

Çeyreklik satışlar toplanarak yıllık satışlar elde edilir:

| Yıl | Satış |
|---|---|
| 2002 | \$1,568,000 |
| 2003 | \$2,356,000 |
| 2004 | \$3,594,000 |

2002 için hesap: $224{,}000 + 408{,}000 + 350{,}000 + 586{,}000 = 1{,}568{,}000$; bu, tablodaki yıllık değerle uyuşur. 2003 ve 2004'ün çeyreklik değerleri slaytta üst üste binen tablolar nedeniyle okunamıyor. Slayta göre ortaya çıkan veri kümesi hacimce daha küçüktür ve analiz görevi için gereken bilgi kaybolmaz.

### 8.1 Neden küp?

Sonraki slaytta bir veri küpü gösterildi: kimin (hangi mağazanın) sattığı, hangi yılda sattığı ve hangi ürünü sattığı üç boyutta tutuluyordu. Hoca sordu: veri tabanları hep iki boyutlu tablolardan oluşur; bu veriyi neden iki değil üç boyutlu tutuyoruz, bunun faydası ne?

Cevap hızdır. Veri küpü gerçek zamanlı oluşturulmaz; tek tek satış kayıtları sonradan işlenir, gerekli yerler toplanır ve küp oluşturulur. Bu sayede aranan özet veriye hızlıca ulaşılır. Bu yaklaşım bugün de kullanılır; OLAP gibi alanlar ve bunun uzmanları vardır. Örneğin en yakın benzerleri bulan algoritmalar, veriyi en hızlı erişilecek biçimde küp olarak nasıl tutacağına göre tasarlanabilir.

Bedeli ayrıntı kaybıdır: küp çeşitli düzeylerde özet tutar, günlük veri tutmaz. Örneğin belirli bir günde kaç bilgisayar satıldığı küpten bulunamaz, ama özet bilgiye hızla ulaşılır.

## 9. Sayıca Azaltma: Örnekleme

Son konu örneklemedir (sampling). Hoca, örneklemenin istatistikten bilindiğini hatırlatarak en çok nerede kullanıldığını anlattı: veri çok büyükse, örneğin milyonlarca satır varsa, model bu verinin tamamıyla eğitilemeyebilir. Bu durumda veriden örnek almak gerekir; örneğin 300 bin örnek alınıp model onunla çalıştırılır.

Asıl soru nasıl seçileceğidir. İlk 300 bin kaydı ya da son 300 bin kaydı almak mantıklı mıdır? Seçimin neye göre yapılacağı önemlidir. Rastgele seçim yapılabilir. Ayrıca seçilen örneğin geri konup konmayacağı (yerine koyarak ya da koymadan, with/without replacement) ya da seçilene benzeyenlerin çıkarılıp çıkarılmayacağı gibi farklı yöntemler vardır. Hoca slaytta yerine koyarak ve koymadan örneklemenin ve büyük olasılıkla tabakalı (stratified) örneklemenin gösterildiğini söyledi, ama ayrıntısına girmedi.

<!-- BELİRSİZ: Örnekleme slaytının içeriği karede yok; altyazıda "certified" diye geçen terim büyük olasılıkla "stratified" (tabakalı örnekleme). -->

> **Ek bilgi (derste anlatılmadı):** Tabakalı örneklemede veri önce gruplara (örneğin sınıflara) ayrılır ve her gruptan oranına uygun sayıda örnek alınır; böylece az temsil edilen sınıflar örnekte kaybolmaz.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:01:38): Binning sınıf bilgisini (etiketi) kullanır mı? Denetimli mi, denetimsiz mi bir yöntemdir?

> **Cevap (derste verildi):** Kullanmaz; yalnız değerlere bakarak ayırır. Bu yüzden denetimsiz bir yöntemdir ve basit bir kümeleme tekniği olarak da görülebilir.

**Soru 2** (derste sözlü, 00:02:03): Değerleri 5 ile 215 arasında olan bir fiyat özniteliği eşit genişlikli üç bine bölünürse bin genişliği ne olur?

> **Cevap (derste verildi):** Hoca genişliği 70 olarak verdi.
>
> **Ders sonrası not:** Genişlik $(215 - 5)/3 = 70$ ile bulunur; sınırlar büyük olasılıkla 5-75, 75-145, 145-215 olur. Derste söylenen 0-70, 70-140, 140-210 sınırları bu hesapla uyuşmaz (bkz. Bölüm 1.1).

**Soru 3** (derste sözlü, 00:16:10): $n$ öznitelik varken en iyi öznitelik alt kümesini kaba kuvvetle aramanın maliyeti nedir?

> **Cevap (derste verildi):** $2^n$ alt küme vardır; maliyet üstel büyür. Büyük veride bütün kombinasyonlar denenemez, bu yüzden adım adım sezgisel yöntemler kullanılır. Örneğin $n = 10$ için $2^{10} = 1024$ alt küme vardır (ara adım eklendi).

**Soru 4** (ekrandan, 00:20:00): 2002 yılının çeyreklik satışları Q1 = \$224,000, Q2 = \$408,000, Q3 = \$350,000, Q4 = \$586,000 ise veri küpü toplamasıyla elde edilen yıllık satış nedir?

> **Çözüm:** $224{,}000 + 408{,}000 + 350{,}000 + 586{,}000 = \$1{,}568{,}000$. Slayttaki yıllık tabloyla uyuşur.

**Soru 5** (derste sözlü, 00:19:24): Veri tabanı tabloları iki boyutluyken satış verisini mağaza, ürün ve yıl boyutlarında üç boyutlu bir küp olarak tutmanın faydası nedir?

> **Cevap (derste verildi):** Küp önceden toplanmış özetleri tutar; bu sayede aranan özet bilgiye hızlıca ulaşılır. Bedeli ayrıntı kaybıdır: örneğin belirli bir günün satışı küpten bulunamaz.

**Soru 6** (derste sözlü, 00:21:25): Milyonlarca satırlık bir veriden 300 bin örnek alınacaksa ilk ya da son 300 bin kaydı almak mantıklı mıdır?

> **Cevap (derste verildi):** Hayır; seçimin nasıl yapılacağı önemlidir. Rastgele seçim, yerine koyarak ya da koymadan seçim ve benzerleri çıkararak seçim gibi yöntemler kullanılır.

## Dersin Toparlaması

Bu derste veri ön işlemenin son iki adımı tamamlandı. Ayrıklaştırmada denetimsiz yöntemler (eşit genişlikli ve eşit frekanslı binning, boşluğa göre kümeleme) ile denetimli yöntem (karar ağacı ve entropiyle bölme) karşılaştırıldı; kavram hiyerarşilerinin sayısal (fiyat aralıkları) ve nominal (zaman, konum) öznitelikler için nasıl kurulduğu görüldü.

Ardından veri azaltmaya geçildi. Boyut arttıkça verinin uzayda dağıldığı ve algoritmaların zorlandığı anlatıldı. Boyut azaltma için wavelet dönüşümü, PCA ve öznitelik alt kümesi seçimi; sayıca azaltma için veri küpü toplaması ve örnekleme ele alındı. Karar ağacıyla ayrıklaştırmanın ayrıntısı sınıflandırma algoritmaları işlendiğinde ele alınacak; bir sonraki derste ön işlemenin Weka aracında bir veri kümesi üzerinde nasıl yapıldığına bakılacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
