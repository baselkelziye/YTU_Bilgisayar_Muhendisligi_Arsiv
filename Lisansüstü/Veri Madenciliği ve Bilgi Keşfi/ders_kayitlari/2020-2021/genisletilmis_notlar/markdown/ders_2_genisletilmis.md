# Ders 2 Genişletilmiş Notu: Veri Ön İşleme: Ham Veri, Normalizasyon, Veri Yumuşatma ve Eksik Veri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri Ön İşlemeye Giriş
- 2. Ham Verinin Gösterimi
- 3. Ham Verinin Özellikleri ve Sorunları
- 4. Normalizasyon
- 5. Normalizasyon Örneği
- 6. Veri Yumuşatma (Data Smoothing)
- 7. Farklar ve Oranlar
- 8. Eksik Veri
- Örnek Sorular

## 1. Veri Ön İşlemeye Giriş

Geçen hafta veri madenciliğine giriş yapılmış, verinin yapısı ve terminolojisi basit veri setleri üzerinde konuşulmuştu. Bu hafta giriş konusunun devamı olarak veri ön işleme ve hazırlama işlemleri ele alınıyor. Ders slaytlarının kapağında "Data Mining: Data Preprocessing" yazıyor; sayfa altlarında ise "Data Mining: Preparing the Data" başlığı var (ekrandan, 00:23:15).

Hoca bu konunun başlıklarını şöyle sıraladı:

- Elimizdeki verinin önce analiz edilmesi.
- Özellikle nümerik öz niteliklere uygulanan değişik normalizasyon teknikleri.
- Öz niteliklerin dönüştürülmesi (attribute transformation).
- Veride sıkça karşılaşılan eksik verilerin (missing data) giderilmesi.
- Zaman serisi biçimindeki verinin (time dependent data) nasıl işlenebileceği.
- Aykırı değerlerin (outlier) veri içinde bulunmasına yönelik teknikler (outlier detection).

Bu derste ilk dört başlık işlendi. Zaman serileri ve aykırı değer analizi bir sonraki derse bırakıldı.

## 2. Ham Verinin Gösterimi

### 2.1 Veri matrisi

Veriyi incelerken kullanılacak terminolojinin iyi anlaşılması gerekir. Slayttaki şekilde (ekrandan, 00:23:15) veri bir tablo olarak gösterilir:

- Her **satır** bir örnektir (sample). Slayta göre örnekler veri madenciliği sürecinin temel bileşenleridir.
- Her **sütun** bir öz niteliktir (feature).
- Her **hücre**, ilgili örneğin ilgili öz nitelikteki değeridir ("feature's value for the given sample").

Her örnek birkaç öz nitelikle tanımlanır ve bu öz niteliklerin değerleri farklı tiplerde olabilir. En yaygın iki tip nümerik ve kategorik öz niteliklerdir.

### 2.2 Nümerik ve kategorik öz nitelikler

Nümerik bir öz nitelikten iki özellik beklenir:

- **Sıralama ilişkisi (order relation):** değerler büyükten küçüğe sıralanabilir.
- **Mesafe ilişkisi (distance relation):** iki örneğin o öz nitelikteki değerleri arasında bir mesafe hesaplanabilir.

Kategorik öz nitelikler daha basittir. Bir arabanın rengi, bir insanın hangi ülkenin vatandaşı olduğu, cinsiyeti ya da göz rengi kategorik öz niteliklere örnektir.

### 2.3 Kategorik verinin sayısal kodlanması: dummy değişkenler

Bazı uygulamalarda kategorik bir veriyi temsil eden nümerik değerlerle karşılaşılır. Slayttaki kurallar (ekrandan, 00:25:10):

- İki değerli bir kategorik değişken, ilke olarak 0 ya da 1 değerini alan ikili (binary) bir nümerik değişkene çevrilebilir.
- N değerli bir kategorik değişken, her kategorik değer için bir tane olmak üzere N tane ikili nümerik değişkene çevrilebilir. Bu şekilde kodlanmış kategorik değişkenlere istatistikte **dummy variable** denir.

Slayttaki örnekte göz rengi öz niteliğinin dört değeri dört ikili basamakla kodlanmıştır:

| Öz nitelik değeri | Kod |
|---|---|
| Black | 1000 |
| Blue | 0100 |
| Green | 0010 |
| Brown | 0001 |

Hoca, bunların yerine doğrudan 1, 2, 3, 4 gibi onluk değerler de verilebileceğini söyledi. Her durumda hangi sayının hangi kategoriye karşılık geldiği bilinir. Önemli olan şudur: Bu değerler nümerik görünse de aslında yalnızca bir kategoriyi temsil eder. Bu yüzden böyle bir değişken **asla sıralama ya da mesafe hesabında kullanılmamalıdır**.

### 2.4 Sürekli ve ayrık değişkenler

Slaytlar değişkenleri sınıflandırmanın bir başka yolunu da verir: sürekli (continuous) ve ayrık (discrete) değişkenler.

**Sürekli değişkenler** nicel ya da metrik değişkenler (quantitative / metric variables) olarak da bilinir. Aralık ölçeği (interval scale) ya da oran ölçeği (ratio scale) ile ölçülürler. Her iki ölçek de değişkenin kuramsal olarak sonsuz hassasiyetle ölçülmesine izin verir. İki ölçeğin farkı sıfır noktasının nasıl tanımlandığıdır (ekrandan, 00:26:40):

- **Aralık ölçeği:** sıfır noktası keyfi olarak konmuştur ve ölçülen şeyin tamamen yokluğunu göstermez. Slayttaki örnek sıcaklıktır: 0 derece Fahrenheit, sıcaklığın hiç olmadığı anlamına gelmez. Bu yüzden oran ilişkisi geçerli değildir; 80 °F, 40 °F'nin iki katı sıcaklık demek değildir.
- **Oran ölçeği:** mutlak bir sıfır noktası vardır, dolayısıyla oran ilişkisi geçerlidir. Boy, uzunluk ve maaş bu ölçekle ölçülür.

Hoca bu ayrımın çok önemli olmadığını, ayrık değişkenler kısmının daha ilginç olduğunu söyledi.

**Ayrık değişkenler** nominal ya da ordinal ölçekle ölçülür.

- **Nominal ölçek** sırasız (orderless) bir ölçektir. Slayttaki örnek müşteri tipidir: tipler A, B, C ya da 1, 2, 3 ile ifade edilebilir, ama bu sayılar yalnızca temsil eder.
- **Ordinal ölçek** sıralı ve ayrık derecelerden oluşur, örneğin sıralamalar. Slayttaki tanım (ekrandan, 00:30:00): ordinal değişken, **sıralama ilişkisi tanımlı ama mesafe ilişkisi tanımlı olmayan** kategorik bir değişkendir.

### 2.5 Ordinal değişken örneği

Slayttaki örnekler, bir sınıftaki öğrencinin başarı sırası ve bir spor yarışmasındaki altın, gümüş, bronz madalya dereceleridir. Sıralı ölçeğin doğrusal olması gerekmez: 4. ve 5. sıradaki öğrenciler arasındaki fark, 15. ve 16. sıradakiler arasındaki farkla aynı olmak zorunda değildir. Ordinal bir öz nitelik için kurulabilecek tek şey büyüktür, eşittir ve küçüktür ilişkileridir (ekrandan, 00:30:00).

Hoca bunu bir koşu yarışıyla somutlaştırdı. Öğrenciler hedefe varış sırasına göre birinci, ikinci, üçüncü diye sıralanır. 4. ve 5. sıradaki öğrenci için yalnızca kimin önce vardığı bilinir; varış süreleri arasındaki fark bilinmez. Bu fark, 14., 15. ve 16. sıradakiler arasındaki farkla aynı değildir. Yani sıralama ilişkisi vardır, mesafe ilişkisi yoktur.

Hoca geçen dersteki kredi kartı veri setinde yer alan gelir aralığı (income range) öz niteliğini de hatırlattı. 20-30K, 30-40K gibi aralıklar arasında sıralama kurulabilir, ama doğrudan bir mesafe tanımlanamaz. Low, medium, high gibi değerler de böyledir. Slayta göre ordinal değişkenler genellikle nümerik bir değişkeni küçük bir aralık kümesine kodlar ve konuşma dilindeki dilsel ya da bulanık değişkenlere yakındır; örnek olarak yaşın young, middle-aged ve old değerleriyle ifade edilmesi verilmiş (ekrandan, 00:30:00).

**Soru:** Bu durumda iki değer arasındaki uzaklığı hesaplayabilmek için, herhangi iki değer arasındaki uzaklığın başka iki değer arasındaki uzaklıkla aynı birimde olması mı gerekir? **Cevap:** Evet. Verilen örneklerde bu aralıklar değişkenlik gösterdiği için bir mesafe tanımı yapılamıyor.

## 3. Ham Verinin Özellikleri ve Sorunları

### 3.1 Ham veri neden zahmetlidir?

Hoca, geçen hafta söylediği gibi veri madenciliği süreçlerinde emeğin belki %60'ının bu aşamada harcandığını hatırlattı. Ham veriyi toplarken önce amacı ve bu amaca hizmet edecek parametreleri belirlemek gerekir. Bu tanımlamalar yapıldıktan sonra veri tabanından veriyi çekerken de pek çok zorlukla karşılaşılır: o anda çalışan veri tabanı uzmanıyla aynı dili konuşmak gerekir ve hocaya göre bu noktada anlaşmak gerçekten zordur. Gelen veride hatalar ve düzensizlikler olabilir; bunları iyi analiz edip önceden düzeltmek gerekir.

Slayttaki "Characteristics of Raw Data" maddeleri (ekrandan, 00:32:25):

- Veri madenciliği için hazırlanan ham veri setleri genelde büyüktür; çoğu insanla ilgilidir ve dağınık olma potansiyeli taşır.
- Bu ilk veri setlerinde önceden (a priori) eksik değerler, bozulmalar, yanlış kayıtlar, yetersiz örnekleme ve benzeri sorunlar beklenmelidir.
- Bu sorunların hiçbirini göstermeyen ham veri hemen şüphe uyandırmalıdır.
- Verinin bu kadar kaliteli olmasının tek gerçek nedeni, analist görmeden önce temizlenmiş ve ön işlenmiş olmasıdır; örneğin doğru tasarlanıp hazırlanmış bir veri ambarındaki veri.

### 3.2 Sorun türleri

Hoca bu sorunları tek tek açıkladı:

- **Eksik değerler (missing values):** Ölçüm alınmamış olabilir, kayıt alan kişi yazmayı atlamış olabilir. Tıbbi bir veri setinde bir hastanın belli bir değeri hiç ölçülmemiş olabilir. Sebep ne olursa olsun, veri madenciliği sürecini tamamlayabilmek için bu eksikliklerden kurtulmak gerekir.
- **Bozulmalar (distortions):** Veride çok garip, beklenmedik sayılar olabilir; "böyle bir değer nasıl gelebilir" dedirten değerlerdir. Bunlar aykırı değer analizi (outlier analysis) teknikleriyle tespit edilip temizlenebilir.
- **Yanlış kayıt (misrecording):** Kayıt sırasında birinin yanlışlıkla 5 yerine 50 girmesi gibi hatalar.
- **Yetersiz örnekleme (inadequate sampling):** Veriden ne sıklıkta ve hangi zaman aralığında örnek alınacağının iyi belirlenmemesi.

### 3.3 Yetersiz örnekleme: churn örneği

Hoca yetersiz örneklemeyi daha önce yaptıkları bir çalışmayla anlattı. Bireysel emeklilik sisteminde ayrılacak müşteriyi (churn) önceden tespit etmek amaçlanıyordu. Bunu anlayabilmek için müşterinin geriye dönük olarak son bir, üç ya da altı aydaki durumuna bakılır: bir rahatsızlığı olmuş mu, bununla ilgili sistemde bir aksiyon almış mı, müşteri temsilcisine ulaşmak istemiş mi, şikâyet yazmış mı? Son bir aya mı, üç aya mı, altı aya mı bakılmalı gibi farklı senaryolar vardır ve bunların iyi kurgulanması gerekir. Hoca, bu çalışmada son bir yıla, hatta iki yıla kadar geriye bakıldığını, ama çok uzak değerlere bakmanın bazen yanlış olabileceğini söyledi. Veriyi düzenlerken ne sıklıkta örnek alınacağını bilmek de önemlidir.

Bu haftanın asıl amacı tüm bu sorunların üstesinden gelmek ve veriyi temizlemektir (cleaning up): eksikleri gidermek, bozulmaları gidermek ve eksik veriyi düzeltmek için kullanılacak teknikleri öğrenmek.

## 4. Normalizasyon

### 4.1 Neden normalizasyon?

Veri üzerinde yapılan ön işleme adımlarından biri normalizasyondur. Slayttaki gerekçe (ekrandan, 00:40:00): Bazı veri madenciliği yöntemleri, özellikle n boyutlu uzaydaki noktalar arasında mesafe hesabına dayananlar, en iyi sonuç için normalize edilmiş veriye ihtiyaç duyabilir. Ölçülen değerler belli bir aralığa, örneğin $[-1, 1]$ ya da $[0, 1]$ aralığına ölçeklenebilir. Değerler normalize edilmezse mesafe ölçüleri, ortalamada daha büyük değer alan öz niteliklere fazla ağırlık verir.

Hoca bunu bir finans veri setiyle açıkladı. Birinci sütunda müşterilerin yaşı olsun; 18'den başlayıp belki 100'e kadar değer alır. Başka bir sütunda kişinin yıllık geliri olsun; bu sütundaki rakamlar çok daha büyük bir aralıktadır. Müşterilerin birbirine ne kadar benzediğini ya da ne kadar farklı olduğunu ölçmek için çok boyutlu uzayda iki müşteri arasındaki mesafe hesaplanır. Bir öz niteliğin aralığı çok küçük, diğerininki çok büyükse, mesafede büyük değerli sütun baskın hale gelir ve küçük değerli sütunu ezer. Bütün öz niteliklerin etkisini eşitlemek ve daha etkili bir mesafe ya da benzerlik ölçüsü tanımlamak için nümerik aralıklar sabit bir aralığa dönüştürülür.

Slayta göre veriyi normalize etmenin pek çok yolu vardır. Derste basitten karmaşığa üç teknik anlatıldı:

- Ondalık ölçekleme (decimal scaling)
- Min-max normalizasyonu (min-max normalization)
- Standart sapma normalizasyonu (standard deviation normalization); z-score normalizasyonu da denir.

### 4.2 Ondalık ölçekleme (decimal scaling)

Slayttaki açıklama (ekrandan, 00:41:10): Ondalık ölçekleme ondalık noktanın yerini değiştirir, ama orijinal rakam değerinin çoğunu korur. Tipik ölçek değerleri $-1$ ile $1$ arasında tutar. Dönüşüm denklemi:

$$v'(i) = \frac{v(i)}{10^k}$$

Burada $v(i)$, $i$. örneğin $v$ öz niteliğindeki değeri; $v'(i)$ ise ölçeklenmiş değeridir. $k$, $\max(|v'(i)|) < 1$ koşulunu sağlayan en küçük sayıdır.

İşlem şöyle yapılır: Önce veri setindeki en büyük mutlak değer bulunur. Veride negatif değerler de olabileceği için en büyük ve en küçük değere birlikte bakılır. Sonra ondalık nokta, yeni en büyük mutlak değer 1'in altına inene kadar kaydırılır. Bulunan bölen bütün değerlere uygulanır.

Slayttaki örnek: Veri setindeki en büyük değer 455, en küçük değer $-834$ olsun.

- En büyük mutlak değer $|-834| = 834$'tür.
- $834/10^2 = 8{,}34 > 1$ olduğu için $k = 2$ yetmez (ara adım eklendi). $834/10^3 = 0{,}834 < 1$ olduğundan $k = 3$, bölen 1000'dir.
- Bütün değerler 1000'e bölünür; en büyük mutlak değer 0,834 olur.

Hocanın özetiyle bu işlem, sayının ondalık noktasını üç basamak sola kaydırmaktır.

> **Ders sonrası not:** Hoca 00:42:15'te "en küçük değer 455, en küçük değer eksi 834" dedi; slayta göre 455 en büyük, $-834$ en küçük değerdir (ekrandan, 00:41:10).

Hoca yöntemin çok basit, hatta ilkel olduğunu söyleyip dezavantajını sordu. Bir öğrenci şunu söyledi: En büyük değer 834 değil de 1001 olsaydı bölen 1000 yerine 10.000 olacaktı; elimizde aslında yalnızca 1001 civarında bir değer varken 10.000'e bölmüş olurduk. Hoca bunu şöyle toparladı: Elimizde $[-1, 1]$ gibi bir aralık var, ama böyle bir seçimde bu aralığın çok küçük bir bölümü kullanılır, büyük bölümü boş kalır. Yani yöntem aralığı verimli kullanmaz; bu yüzden alternatif çözümler aranmıştır.

### 4.3 Min-max normalizasyonu

Min-max slaytı aynı sorunu bir örnekle açar (ekrandan, 00:45:45): Bir $v$ öz niteliğinin verisi 150 ile 250 arasında olsun. Önceki yöntem bütün normalize değerleri 0,15 ile 0,25 arasında verir; değerler tüm aralığın küçük bir alt aralığında toplanır. Değerleri $[0, 1]$ gibi bütün bir aralığa daha iyi dağıtmak için min-max formülü kullanılır:

$$v'(i) = \frac{v(i) - \min(v(i))}{\max(v(i)) - \min(v(i))}$$

Mevcut değerden veri setindeki en küçük değer çıkarılır ve sonuç, en büyük değer ile en küçük değerin farkına bölünür. Böylece değerler $[0, 1]$ aralığına dönüşür ve ondalık ölçeklemedeki sorun ortadan kalkar. Slayta göre $v$ öz niteliğinin minimum ve maksimum değerleri ya veri kümesi üzerinden otomatik hesaplanır ya da ilgili alanda bir uzman tarafından tahmin edilir (ekrandan, 00:45:45).

Aynı dönüşüm $[-1, 1]$ aralığı için de kullanılabilir. Bunun için formülün düzenlenmesi gerekir, ama bu basit bir matematik işlemidir. Veri setindeki en küçük değer $-1$'e, en büyük değer $+1$'e oturtulur ve aradaki bütün değerler doğrusal (linear) bir dönüşümle eşlenir. Bir doğrunun iki noktası biliniyorsa denklemi yazılabilir; bu denklemle veri setindeki her değerin dönüşümden sonra ne olacağı bulunur. Bu dersteki örnekte (Bölüm 5) bu yol beyaz tahtada gösterildi.

Hocanın değindiği bir sıkıntı şudur: Eğitim verisi (train data) belli bir aralıkta olsun ve dönüşüm bu aralığa göre kurulsun. Test verisinde o ana kadar toplanan verinin çok dışında bir değer gelirse, normalize değer $[0, 1]$ aralığının üstüne çıkabilir.

### 4.4 Standart sapma (z-score) normalizasyonu

Bu yöntem diğer ikisinden çok daha yaygın kullanılır. Slayttaki açıklama (ekrandan, 00:48:20): Bir $v$ öz niteliği için tüm veri setinde ortalama $\text{mean}(v)$ ve standart sapma $\text{sd}(v)$ hesaplanır. Sonra $i$. örnek için değer şu denklemle dönüştürülür:

$$v'(i) = \frac{v(i) - \text{mean}(v)}{\text{sd}(v)}$$

Slayttaki örnek: $v = \{1, 2, 3\}$ ise $\text{mean}(v) = 2$, $\text{sd}(v) = 1$ ve normalize değerler $v^* = \{-1, 0, 1\}$ olur. Slayta göre standart sapmayla normalizasyon çoğu zaman mesafe ölçüleriyle iyi çalışır, ama veriyi orijinal veriden tanınmayacak bir biçime dönüştürür (ekrandan, 00:48:20).

Hoca bu yöntemin neden etkili olduğunu beyaz tahtada bir çizimle anlattı (ekrandan, 00:50:00). Koordinat düzleminde ortalaması örneğin 3 olan bir Gauss dağılımı düşünülsün. Dağılımın tepe yaptığı nokta ortalama değerdir ($m$, mean value).

- Formüldeki $v - m$ işlemi bu dağılımı sola kaydırır (shift); dağılımın şekli aynı kalır ama ortalaması sıfır olur. Yani veri sıfır ortalamalı hale gelir, orijine taşınır.
- Ardından her değer standart sapmaya bölünür. Böylece bir değerin dağılım içinde nerede olduğu standart sapma cinsinden ifade edilir: merkeze yakın mı, yoksa 1 sigma, 2 sigma uzakta mı?

Normal dağılımda verinin büyük bölümü $\pm 3\sigma$ aralığının içindedir. Normalize edilmiş değer, bu aralığın hangi parçasında olunduğunu doğrudan söyler.

> **Hocanın vurgusu:** Üç tekniğin üçünün de bilinmesi beklenir, ama standart sapma normalizasyonu özellikle çok önemlidir. Hoca kendi çalışmalarında bu yöntemi kullandıklarında başarının genelde çok daha iyi çıktığını söyledi.

### 4.5 Normalizasyon üzerine soru-cevaplar

**Soru:** Bu normalizasyonla aykırı değerlerin etkisini azaltıyor muyuz? **Cevap:** Asıl kazanç, veriyi tanımanın daha mümkün hale gelmesidir. Veri setindeki her değer, merkeze ne kadar yakın ya da ne kadar uzak olduğunu da gösterir; bu da güzel bir ölçüdür.

**Soru:** Standart sapma normalizasyonunda verinin normal dağıldığını mı kabul ediyoruz, diğer dağılımlarda da işe yarar mı? **Cevap:** Dağılımın türüne bakarak bu incelenmedi, ama denemekte fayda var. Veri madenciliğinde her ön işlem adımı alternatifli yapılır: bir tarafta min-max, bir tarafta standart sapma normalizasyonu uygulanır ve hangisinin daha iyi sonuç verdiği karşılaştırılır. Gauss dağılımında iyi sonuç verecek, diğerlerinde vermeyecek diye bir kural yoktur; denemek gerekir.

**Soru:** Min-max normalizasyonu veriyi küçük bir aralığa sıkıştırıyor; standart sapma normalizasyonunda ise verinin açıklığı büyük kalabilir. Milyonlarca büyük sayıyla işlem yapmak, işlem hızını belirgin biçimde etkiler mi? **Cevap:** Hoca önce min-max'ın aralık dışı test değeri sorununu anlattı: standart sapma normalizasyonunda böyle bir değer açıkça aykırı bir değer olarak görünür. Hız konusunda ise, $[0, 1]$ aralığına geçildiğinde ondalıklı sayılarla işlem yapılmaya başlandığını, bu yüzden normalizasyonun hız açısından belirgin bir kazanç ya da yük getirdiğini düşünmediğini söyledi. Normalizasyonun amacı hız değildir; iki örnek arasındaki uzaklık hesaplanırken bir sütunun çok büyük, diğerinin çok küçük değer almasından doğan dezavantajı ortadan kaldırmak, böylece daha doğru bir mesafe ölçmek ve daha başarılı sonuç elde etmektir.

## 5. Normalizasyon Örneği

### 5.1 Soru

Arada çözülen örnek (ekrandan, 01:14:10):

> Example: Given one dimensional data set $x = \{3, 1, 0, 2, 7, 6, 4, -2, 10, 12\}$, normalize the data set and give the new values for $v = 0$ and $v = 6$ using:
> a) min-max normalization on interval $[0,1]$
> b) min-max normalization on interval $[-1,1]$
> c) standard deviation normalization

Örnek, tek boyutlu ve oldukça basitleştirilmiştir: $x$ öz niteliğinin 10 örnekteki değerleri verilmiştir.

### 5.2 a) Min-max, $[0, 1]$

Önce en küçük ve en büyük değerler bulunur. Hoca öğrencilere sordu; en küçük değer $-2$, en büyük değer $12$'dir. Formülde yerine konunca (ekrandan, 01:14:10):

$$v' = \frac{v - (-2)}{12 - (-2)} = \frac{v + 2}{14}$$

### 5.3 b) Min-max, $[-1, 1]$ ve doğru denklemi

Hoca bunu beyaz tahtada çizdi (ekrandan, 01:20:00). Yatay eksen girişi, yani orijinal değer $v$'yi; dikey eksen ölçeklenmiş değer $v'$'yü gösterir. Girişteki en küçük değer $-2$, $-1$'e; en büyük değer $12$, $+1$'e taşınmak istenir. Böylece koordinat düzleminde iki nokta tanımlanır: $(-2, -1)$ ve $(12, 1)$. Bu iki noktadan geçen doğru dönüşüm doğrusudur ve $x$ eksenindeki her değer bu doğruyla dönüştürülür.

İki noktası bilinen doğrunun denklemi şu formülle yazılabilir:

$$\frac{x - x_1}{x_2 - x_1} = \frac{y - y_1}{y_2 - y_1}$$

> **Ders sonrası not:** Altyazıda 01:20:13'te formül "x eksi x1 bölü x1 eksi x2 eşit y eksi y1 bölü y eksi y2" diye geçiyor; bu Whisper hatası da olabilir. Doğru iki nokta formülü yukarıdaki gibidir: paydalarda iki noktanın koordinat farkları ($x_2 - x_1$ ve $y_2 - y_1$) yer alır, $y - y_2$ gibi bir değişken terim yer almaz.

Değerler yerine konunca (ara adım eklendi):

$$\frac{v - (-2)}{12 - (-2)} = \frac{v' - (-1)}{1 - (-1)} \;\Rightarrow\; \frac{v+2}{14} = \frac{v'+1}{2} \;\Rightarrow\; v' = \frac{v+2}{7} - 1 = \frac{v - 5}{7}$$

Hocanın bulduğu sonuç da budur: $v' = (v-5)/7$ (ekrandan, 01:20:55). Kontrol: $v = -2$ için $v' = -7/7 = -1$, $v = 12$ için $v' = 7/7 = 1$.

### 5.4 c) Standart sapma normalizasyonu

Önce verinin ortalaması ve standart sapması hesaplanır. Ekrandaki değerler (ekrandan, 01:23:25):

- Ortalama: $m = 4{,}3$. Toplam $3+1+0+2+7+6+4-2+10+12 = 43$, örnek sayısı 10 (ara adım eklendi).
- Standart sapma: $s = 4{,}44$.
- Dönüşüm: $v' = (v - m)/s$.

Standart sapmanın nasıl hesaplandığı derste öğrencilere soruldu: her değerden ortalama çıkarılır, farkların karesi alınır ve toplanır, toplam örnek sayısının bir eksiğine bölünür, sonra karekök alınır:

$$s = \sqrt{\frac{1}{n-1}\sum_{i=1}^{n}(v_i - m)^2}$$

> **Hocanın vurgusu:** Örneklem (sample) üzerinden standart sapma hesaplanırken $n-1$'e bölünüp sonra karekök alınır; bu unutulmamalı.

$n-1$ ile hesaplanan değer $4{,}448$'dir; ekrandaki $4{,}44$ bunun kısaltılmış hâlidir (python ile doğrulandı).

### 5.5 $v = 0$ ve $v = 6$ için sonuçlar

Soru bu iki değerin dönüşümden sonra ne olacağını soruyor. Hoca formülleri yazdı, değerlerin bu denklemlerden bulunabileceğini söyledi; sayısal sonuçlar derste hesaplanmadı. Formüllerin uygulanmasıyla bulunan değerler "Örnek Sorular" bölümündedir.

Hoca örneği şu cümleyle kapattı: Formülleri uygulamak kolaydır; asıl önemli olan sonuçları yorumlayabilmek ve bu işlemlere neden ihtiyaç duyulduğunu anlamaktır.

## 6. Veri Yumuşatma (Data Smoothing)

### 6.1 Yumuşatma nedir?

Yumuşatma, veri üzerindeki değerleri "yumuşatarak" daha az sayıda farklı değerle ifade etmektir. En basit örnek, verilen ondalıklı sayıları tam sayılara dönüştürmektir. Bunun dışında, çok geniş bir aralıkta verilmiş bir sayı dizisi belli aralıklara bölünüp her aralık onu temsil eden yeni bir değerle ifade edilebilir. Yani bir öz nitelik çok sayıda farklı değer (many distinct values) alıyorsa, belli aralıktaki sayıları tek bir değerle ifade etme işlemine yumuşatma denir.

Slayttaki yöntemler (ekrandan, 01:26:40):

- **Binning:** önce veri sıralanır ve (eşit frekanslı) kutulara bölünür; sonra kutu ortalamasıyla, kutu medyanıyla ya da kutu sınırlarıyla yumuşatılır.
- **Regresyon:** veri regresyon fonksiyonlarına uydurularak yumuşatılır.
- **Kümeleme (clustering):** aykırı değerler tespit edilip çıkarılır.
- **Bilgisayar ve insan incelemesinin birlikte kullanılması:** şüpheli değerler bilgisayarla tespit edilir ve insan tarafından kontrol edilir (ör. olası aykırı değerlerle ilgilenmek).

### 6.2 Binning yöntemi

Binning yönteminin adımları:

1. Veri sıralanır.
2. Sıralı veri parçalara (kutulara, bin) bölünür (partitioning).
3. Her kutu, o kutuyu temsil eden bir değerle ifade edilir. Bu değer kutunun ortalaması, medyanı ya da sınır değerleri olabilir.

Böylece çok sayıda ayrık değer yerine, bir aralıktaki bütün değerler tek bir sayıyla temsil edilir.

Bölme için iki yol vardır:

- **Eşit genişlikli bölme (equal width partitioning):** Aralık eşit genişlikte $N$ parçaya bölünür. Sıralı verinin en küçük değeri $A$, en büyük değeri $B$ ise önce aralığın genişliği $B - A$ bulunur, sonra bu $N$'e bölünerek her kutunun genişliği hesaplanır:
  $$w = \frac{B - A}{N}$$
- **Eşit derinlikli ya da eşit frekanslı bölme (equal depth / equal frequency partitioning):** Her kutuya eşit sayıda örnek düşecek şekilde bölünür. Başta kaç kutu istendiğine karar verilir, veride kaç örnek olduğuna bakılır ve örnekler kutulara eşit dağıtılır. Örnek sayısı tam bölünmeyebilir; o zaman kutulardan birinde bir fazla ya da bir eksik örnek olabilir. Amaç olabildiğince eşit bölmektir.

### 6.3 Örnek: fiyat verisinin eşit frekanslı kutulara bölünmesi

Slayttaki örnek (ekrandan, 01:30:00): Dolar cinsinden sıralı fiyat verisi:

$$4,\ 8,\ 9,\ 15,\ 21,\ 21,\ 24,\ 25,\ 26,\ 28,\ 29,\ 34$$

12 değer vardır ve başta 3 kutuya bölmeye karar verilmiştir. Her kutuya 4 değer düşer: sıralı diziden ilk dört değer birinci kutuya, sonraki dördü ikinci kutuya, son dördü üçüncü kutuya konur.

| Kutu | Değerler | Kutu ortalamasıyla | Kutu sınırlarıyla |
|---|---|---|---|
| Bin 1 | 4, 8, 9, 15 | 9, 9, 9, 9 | 4, 4, 4, 15 |
| Bin 2 | 21, 21, 24, 25 | 23, 23, 23, 23 | 21, 21, 25, 25 |
| Bin 3 | 26, 28, 29, 34 | 29, 29, 29, 29 | 26, 26, 26, 34 |

**Kutu ortalamasıyla yumuşatma (smoothing by bin means).** Birinci kutudaki dört sayının ortalaması 9'dur; artık bu kutudaki bütün değerler, 4 de 15 de, 9 ile temsil edilir. İkinci kutu 23 ile, üçüncü kutu 29 ile temsil edilir. Ortalamanın yerine kutunun medyanı ya da modu da temsilci değer olarak seçilebilir.

> **Ders sonrası not:** Kutu ortalamaları tam olarak $(4+8+9+15)/4 = 9$, $(21+21+24+25)/4 = 22{,}75$ ve $(26+28+29+34)/4 = 29{,}25$'tir (python ile doğrulandı). Slayttaki 23 ve 29 yuvarlanmış değerlerdir. Ayrıca hoca 01:31:46'da üçüncü kutuyu "26, 28, 29, 30, 40" diye okudu; slaytta 26, 28, 29, 34 yazıyor (ekrandan, 01:30:00).

**Kutu sınırlarıyla yumuşatma (smoothing by bin boundaries).** Kutunun en küçük ve en büyük değeri sınır (boundary) değerleridir. İçeride kalan her değer hangi sınıra daha yakınsa o sınırla değiştirilir. Birinci kutuda sınırlar 4 ve 15'tir:

- 8'in sol sınıra uzaklığı $8 - 4 = 4$, sağ sınıra uzaklığı $15 - 8 = 7$ birimdir. Sola daha yakın olduğu için 8 yerine 4 kullanılır.
- 9'un sol sınıra uzaklığı 5, sağ sınıra uzaklığı 6 birimdir. 9 da sol sınırla, yani 4 ile temsil edilir.

İkinci kutuda sınırlar 21 ve 25'tir; 24 sağ sınıra daha yakın olduğu için 25 ile temsil edilir. Üçüncü kutuda sınırlar 26 ve 34'tür; 28 ve 29 sol sınıra daha yakın olduğu için 26 olur (ara adım eklendi).

### 6.4 Yumuşatmanın hatası

Yumuşatma yapılırken bir hata da yapılmış olur: orijinal değerler bozulur. Bu bozulmanın ne kadar olduğu bir hata hesabıyla ölçülebilir; örneğin ortalama mutlak hata (mean absolute error) hesaplanabilir. Hangi yumuşatma tekniğinin daha az hata yaptığını ölçüp ona göre karar vermek gerekebilir.

> **Ek bilgi (derste anlatılmadı):** Ortalama mutlak hata, orijinal değerler $v_i$ ve yumuşatılmış değerler $\hat{v}_i$ için $\text{MAE} = \frac{1}{n}\sum_{i=1}^{n}|v_i - \hat{v}_i|$ biçiminde tanımlanır. Değer ne kadar küçükse yumuşatma orijinal veriyi o kadar az bozmuş demektir.

### 6.5 Yumuşatma üzerine soru-cevaplar

**Soru:** Bu yöntemleri daha önce denediniz mi, faydası oluyor mu? **Cevap:** Hoca kendi çalışmalarında yumuşatmaya hiç ihtiyacı olmadığını, bu yöntemi kullanmadığını, ama belli çalışmalarda ihtiyaç olabileceğini söyledi.

**Soru:** Aynı veri eşit derinlik yerine eşit genişlikle üç kutuya bölünseydi aralıklar ne olurdu? Bir öğrenci önce 0-12, 12-24, 24-36 aralıklarını önerdi. **Cevap:** Genişlik, en büyük değer eksi en küçük değerin kutu sayısına bölünmesiyle bulunur: $w = (34 - 4)/3 = 10$. Aralıklar 4'ten başlayarak 4-14, 14-24 ve 24-34 olur.

**Soru:** Bu yaklaşım bir tür genelleme gibi duruyor; aşırı öğrenmeye (overfitting) karşı çözüm olabilir, ama fazlasıyla yetersiz öğrenmeye (underfitting) de yol açabilir mi? **Cevap:** Bunu denemek gerekir. Yumuşatmanın amacı farklı değerlerin (distinct values) sayısını azaltmaktır; veriyi analiz ederken ya da incelerken kolaylık sağlayacağı düşüncesiyle yapılıyor olabilir.

## 7. Farklar ve Oranlar

Veri dönüştürmede bir başka yol farklar ve oranlardır (differences and ratios). Slayttaki maddeler (ekrandan, 01:40:00):

- Öz niteliklerde yapılan küçük değişiklikler bile veri madenciliği başarımında önemli iyileşme sağlayabilir.
- Giriş ya da çıkış öz niteliklerindeki görece küçük dönüşümlerin etkisi, özellikle veri madenciliği hedeflerinin tanımlanmasında önemlidir.
- İki basit dönüşüm türü, farklar ve oranlar, özellikle çıkış öz niteliklerine uygulandığında hedef tanımını iyileştirebilir.

Veri içindeki bazı öz nitelikler birbirine oranlanarak ya da birbirinden çıkarılarak yeni öz nitelikler türetilebilir. Türetilen öz nitelik bazen tek başına o ikisinden çok daha faydalı olur.

**Beden kitle indeksi.** Hocanın en sık verdiği örnek budur. Tıbbi bir veri setinde hastaların boy ve kilo bilgileri olsun. Boy tek başına çok anlam ifade etmeyebilir; kilo bağımsız bir öz nitelik olarak incelendiğinde de belirgin bir ipucu vermeyebilir. Kiloyu boyun karesine oranlayarak elde edilen beden kitle indeksi (body mass index) ise kişinin kilolu olup olmadığı hakkında belirgin bir ipucu verir. Kilosu yüksek ama boyu da uzun bir kişide bu bir sorun olmayabilir; boyu kısa bir kişide aynı kilo ise bir ipucudur.

$$\text{BMI} = \frac{\text{kilo (kg)}}{\text{boy (m)}^2}$$

> **Ders sonrası not:** Hoca BMI sınırlarını "18'den ya da 24'ten küçükse normal kilo aralığında, 25'in üstündeyse kilolu, 28'in üstündeyse obez" diye söyledi. Dünya Sağlık Örgütünün yetişkinler için sınıflandırması büyük olasılıkla şöyledir: 18,5'in altı zayıf, 18,5-24,9 normal, 25-29,9 fazla kilolu, 30 ve üstü obez.

**Göz ölçümlerinin farkı.** Hoca gözle ilgili bir tıbbi veri setinde, sağ ve sol gözden alınan ölçümlerin farkıyla bir öz nitelik türetildiğini gördüğünü anlattı. Bu fark doktorlar için çok önemli bir ipucu olabiliyor. Yani bir örnekte oran, diğerinde fark kullanılmıştır.

**Soru:** Ev fiyatları için de benzer bir örnek verilebilir mi? Evin metrekaresi ve fiyatı varken metrekare fiyatı türetilebilir. **Cevap:** Evet, burada da oran kullanılmış olur; daha ölçülebilir ve karşılaştırılabilir bir ölçü üretilir.

Hocanın vardığı sonuç: Veri tabanından çekilen değerlerin yanında yeni öz nitelikler türetmek mümkündür ve bunlar ne kadar iyi düşünülüp kurgulanırsa o kadar başarılı sonuç elde edilir. Bir öz niteliği tek başına kullanmak yerine oran biçiminde kullanmak avantaj sağlayabilir.

## 8. Eksik Veri

### 8.1 Otomatik doldurma yöntemleri

Slayta göre eksik değerlerin giderilmesinde daha da basit bir yaklaşım, eksik değerlerin bazı sabitlerle biçimsel, çoğu zaman otomatik olarak doldurulmasıdır (ekrandan, 01:41:45). Slaytta üç yöntem var:

- **Bütün eksik değerleri tek bir global sabitle doldurmak.** Global sabitin seçimi büyük ölçüde uygulamaya bağlıdır. Hoca bunun bir yol olduğunu, ama pek kullanışlı olmadığını söyledi.
- **Eksik değeri öz niteliğin ortalamasıyla doldurmak.** Sütun doğrultusunda bakılır; öz niteliğin kendi içindeki ortalaması hesaplanıp eksik hücreye yazılır. Hocaya göre bu güzel bir tekniktir.
- **Eksik değeri, verilen sınıf için öz nitelik ortalamasıyla doldurmak.** Slayta göre bu yalnız örneklerin önceden sınıflandırıldığı sınıflandırma problemlerinde mümkündür. Eğitim verisinde sınıf etiketi olduğu için kullanılabilir.

Hoca üçüncü yöntemi şöyle örnekledi: Veride hasta ve sağlıklı iki grup olsun. Hasta grup için belli bir kan değerinin ortalaması alınıp hasta gruptaki eksik hücrelere yazılır; sağlıklı grupta da aynı kan değerinin sağlıklı grup içindeki ortalaması kullanılır.

> **Hocanın vurgusu:** Sınıf etiketi varsa, eksik değeri aynı sınıf içindeki ortalamayla doldurmak en doğru ve en sağlıklı çözüm yöntemidir.

Slaytta geçmeyen bir yöntem daha vardır: Veride çok fazla eksik varsa o eksik örnekler silinebilir. Gerekirse çok eksikli bir öz nitelik de silinebilir.

**Soru:** En çok tekrar eden değer de kullanılabilir mi? **Cevap:** Evet, mod kullanmak da mümkündür. Bu daha çok kategorik öz niteliklerde kullanılan bir çözümdür; nümerik öz niteliklerde ortalama almak genelde daha etkilidir.

**Soru:** Eksikleri doldurmak için makine öğrenmesi yöntemleri de kullanılıyor; örneğin $V_1$'i tahmin etmek için $V_2$, $V_3$, $V_4$, $V_5$ giriş, $V_1$ çıkış olarak veriliyor. **Cevap:** Evet, bu regresyonla bulmak demektir; bu da iyi bir çözümdür.

**Soru:** Yeni veri üretmek yerine eğitimde epok sayısı artırılsa, örneğin 100 yerine 1000 epok eğitilse aynı sonuç alınmaz mı? **Cevap:** Hoca soruyu, bazı öz nitelik değerleri eksik ama örneklerin kendisi elde olan durum olarak anladı. Amaç, eldeki örnekleri kaybetmeden onlardan da faydalanmaktır; eksik veri tablosu bu durumu gösterir.

### 8.2 Eksik veri tablosu

Slayttaki örnek tablo (ekrandan, 01:50:00): 20 örnek ve hepsi nümerik 5 öz nitelik ($V_1$-$V_5$). Boş hücreler "—" ile gösterilmiştir. Son iki sütun her örnekteki eksik sayısını ve yüzdesini (missing data by case), son iki satır her öz nitelikteki eksik sayısını ve yüzdesini (missing data by variable) verir.

| Örnek | $V_1$ | $V_2$ | $V_3$ | $V_4$ | $V_5$ | Eksik sayı | Eksik % |
|---|---|---|---|---|---|---|---|
| 1 | 1.3 | 9.9 | 6.7 | 3.0 | 2.6 | 0 | 0 |
| 2 | 4.1 | 5.7 | — | — | 2.9 | 2 | 40 |
| 3 | — | 9.9 | — | 3.0 | — | 3 | 60 |
| 4 | .9 | 8.6 | — | 2.1 | 1.8 | 1 | 20 |
| 5 | .4 | 8.3 | — | 1.2 | 1.7 | 1 | 20 |
| 6 | 1.5 | 6.7 | 4.8 | — | 2.5 | 1 | 20 |
| 7 | .2 | 8.8 | 4.5 | 3.0 | 2.4 | 0 | 0 |
| 8 | 2.1 | 8.0 | 3.0 | 3.8 | 1.4 | 0 | 0 |
| 9 | 1.8 | 7.6 | — | 3.2 | 2.5 | 1 | 20 |
| 10 | 4.5 | 8.0 | — | 3.3 | 2.2 | 1 | 20 |
| 11 | 2.5 | 9.2 | — | 3.3 | 3.9 | 1 | 20 |
| 12 | 4.5 | 6.4 | 5.3 | 3.0 | 2.5 | 0 | 9 |
| 13 | — | — | — | — | 2.7 | 4 | 80 |
| 14 | 2.8 | 6.1 | 6.4 | — | 3.8 | 1 | 20 |
| 15 | 3.7 | — | — | 3.0 | — | 3 | 60 |
| 16 | 1.6 | 6.4 | 5.0 | — | 2.1 | 1 | 20 |
| 17 | .5 | 9.2 | — | 3.3 | 2.8 | 1 | 20 |
| 18 | 2.8 | 5.2 | 5.0 | — | 2.7 | 1 | 20 |
| 19 | 2.2 | 6.7 | — | 2.6 | 2.9 | 1 | 20 |
| 20 | 1.8 | 9.0 | 5.0 | 2.2 | 3.0 | 0 | 0 |
| Eksik sayı | 2 | 2 | 11 | 6 | 2 | Toplam: 23 | |
| Eksik % | 10 | 10 | 55 | 30 | 10 | Toplam: %23 | |

Tablonun okunuşu:

- **Satır doğrultusunda:** 1. örnekte hiç eksik yoktur (0). 2. örnekte $V_3$ ve $V_4$ eksiktir; beş öz nitelikten ikisi yoksa örneğin %40'ı eksiktir. En çok eksik 13. örnektedir: dört değer eksik, yalnızca bir öz niteliği ($V_5$) biliniyor.
- **Sütun doğrultusunda:** $V_1$'de iki eksik vardır; 20 örnekten ikisinin eksik olması %10 demektir. $V_3$'te 11 eksik vardır, yani %55'i eksiktir.

**Soru:** 12. örnekte hiç eksik yok, ama yüzde sütununda 9 yazıyor. Neden? **Cevap:** Bu tablodaki bir yazım hatasıdır; değer 0 olmalıdır.

Tablodaki sayılar python ile yeniden sayıldı: satır ve sütun eksik sayıları slaytla aynıdır, toplam 23 eksik hücre vardır ($23/100 = \%23$).

### 8.3 Silme kararları

Hoca öğrencilere silme hakkı verdi.

**Önce öz nitelik silme.** Hocaya göre bu çok marjinal ve radikal bir karardır, ama bir öz nitelikte o kadar çok eksik olabilir ki gerekirse veri setinden kaldırılır. Bu tabloda kaldırılabilecek öz nitelik açıkça $V_3$'tür (%55 eksik). Hoca bunu bireysel emeklilik çalışmasından bir örnekle destekledi: Kişilere beyan usulüyle eğitim durumları sorulmuştu, ama bu bilgi opsiyonel olduğu için sütunun yalnızca %20-30'u doluydu. Eğitim durumu önemli bir bilgi olmasına rağmen, bu kadar az doldurulmuş bir veriden anlam çıkarmak çok zor olduğu için öz nitelik veri setinden çıkarıldı. Yani bir öz nitelik çalışmaya fayda sağlamayacaksa silinebilir.

**Sonra örnek silme.** $V_3$ silindikten sonra hangi örnekler silinmeli? En büyük eksiğin olduğu 13. örnek ve %60 eksiği olan 3. ve 15. örnekler silinir.

**Kalan eksikleri doldurma.** Geriye kalan eksikler hesaplanıp yerine yazılacaktır. Örneğin 18. örneğin $V_4$ değeri boştur. Bir öğrencinin cevabıyla: $V_4$ sütunundaki mevcut değerlerin ortalaması alınır ve 18. örneğin $V_4$ hücresine yazılır.

**Sınıf etiketi eklenince.** Hoca soruyu değiştirdi: İlk 10 örnek sağlıklı insanlara, son 10 örnek hasta gruba ait olsun. Bu durumda 18. örneğin $V_4$ değeri, kendi sınıfı olan hasta gruptaki 10 örnek üzerinden hesaplanan ortalamayla doldurulur.

Hoca bu işlemlerin önemini şöyle açıkladı: Bazı algoritmalar bazı hücreler boş olsa bile sonuç üretebilir, ama bazıları işlem yapabilmek için mutlaka tamamlanmış veri ister. Bu yüzden eksikliği baştan gidermek çok önemlidir.

Özetle bu tabloda $V_3$ elendi; bu radikal bir seçimdir ve yapılıp yapılmayacağı çok iyi düşünülmelidir. Sonra çok eksikli örnekler silindi; ama eldeki örnek sayısı azsa örnek silme yoluna da gidilemeyebilir. Geriye kalan yaklaşık %7,4'lük boşluk hesaplama teknikleriyle doldurulacak. Kalan 17 örnek ve 4 öz nitelikte 68 hücre vardır ve bunlardan 5'i ($V_4$ sütununda 2, 6, 14, 16 ve 18. örnekler) eksiktir: $5/68 \approx \%7{,}35$ (python ile doğrulandı).

### 8.4 Gerçek veride eksik veri üzerine tartışma

Bir öğrenci kendi çalışmasındaki deneyimi paylaştı. Öneri sistemlerinde tekil değer ayrışımı (singular value decomposition, SVD) gibi yöntemlerle tablo ayrıştırılıp yeniden kurulduğunu (reconstruct) ve boş değerlerin böyle doldurulabildiğini anlattı. Kendi veri seti çoğunlukla kategorik öz niteliklerden oluşan bir işlem veri setiydi; işlemin yapıldığı yerin şehri gibi çok önemli bir sütunun büyük kısmı boştu. Sütun kategorik olduğu için ortalama alınamıyordu, mod almak da doğru görünmüyordu.

Hoca iki öneride bulundu:

- Bir öz niteliğin sezgisel olarak çok faydalı olduğu düşünülebilir. Ama onu işleme koyarak ve koymayarak iki türlü çözüm yapılıp başarıya nasıl etki ettiği bir test verisiyle gözlemlenebilir.
- Öz nitelik sayısı azsa (öğrencinin verisinde 44 öz nitelik ve yaklaşık 200 bin örnek vardı) diğer öz niteliklerin sonuca götürüp götürmediğine bakılmalıdır. Hoca kendi çalışmalarında 200'den fazla öz nitelik olduğunu ve orada eğitim durumu öz niteliğini eleyebildiklerini söyledi.

Öğrenci sonunda eksik değerleri dış bir servisten konum bilgisi çekerek doldurduğunu anlattı. Hocaya göre her zaman çok emek harcayarak bile olsa çözülemeyecek sorunlar olabilir; bu yüzden yerine göre silme yapılabilir.

Bir başka öğrenci, çok önemli görülen bir öz nitelik için ayrı bir model, onun olmadığı durum için başka bir model eğitilebileceğini, ama öz nitelikler arasındaki kovaryansın önemli olduğunu söyledi. GAN gibi üretici modellerle eksik verinin üretilmesi de tartışıldı. Hoca, veriyi düzenlemek için gerçekten çok büyük zaman harcamak gerektiğini söyleyerek tartışmayı bağladı.

> **Ek bilgi (derste anlatılmadı):** Tekil değer ayrışımıyla doldurmada eksik hücreler önce geçici bir değerle (ör. sütun ortalaması) doldurulur, matris düşük ranklı bir yaklaşıklıkla yeniden kurulur ve eksik hücreler bu yaklaşıklıktaki değerlerle güncellenir. İşlem değerler yakınsayana kadar büyük olasılıkla birkaç kez tekrarlanır. Bu yöntem öz nitelikler arasındaki korelasyondan yararlanır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:14:10): $x = \{3, 1, 0, 2, 7, 6, 4, -2, 10, 12\}$ tek boyutlu veri setini a) $[0,1]$ aralığına min-max, b) $[-1,1]$ aralığına min-max, c) standart sapma normalizasyonuyla normalize edin; $v = 0$ ve $v = 6$ için yeni değerleri verin.

Çözüm (formüller derste verildi, ekrandan 01:14:10, 01:20:55 ve 01:23:25; sayısal sonuçlar derste hesaplanmadı):

- min $= -2$, max $= 12$.
- a) $v' = (v+2)/14$.
- b) $v' = (v-5)/7$.
- c) $m = 4{,}3$, $s = 4{,}44$, $v' = (v - m)/s$.

> **Çözüm (derste verilmedi):** Formüller python ile uygulandı.
>
> - a) $v = 0$: $2/14 \approx 0{,}143$. $v = 6$: $8/14 \approx 0{,}571$.
> - b) $v = 0$: $-5/7 \approx -0{,}714$. $v = 6$: $1/7 \approx 0{,}143$.
> - c) $v = 0$: $(0 - 4{,}3)/4{,}44 \approx -0{,}968$. $v = 6$: $(6 - 4{,}3)/4{,}44 \approx 0{,}383$. ($s$ yuvarlanmadan $4{,}448$ alınırsa sonuçlar $-0{,}967$ ve $0{,}382$ olur.)

**Soru 2** (ekrandan, 00:41:10): Bir öz niteliğin en büyük değeri 455, en küçük değeri $-834$'tür. Ondalık ölçeklemede $k$ ve bölen ne olur?

Çözüm (derste verildi): En büyük mutlak değer 834'tür. $\max|v'(i)| < 1$ olması için en küçük $k$ değeri 3'tür; bölen $10^3 = 1000$, ölçeklenmiş en büyük mutlak değer 0,834'tür.

**Soru 3** (derste sözlü, 00:44:03): Ondalık ölçekleme yönteminin dezavantajı nedir?

Çözüm (derste verildi): En büyük mutlak değer örneğin 1001 olsaydı bölen 10.000 olurdu ve değerler $[-1, 1]$ aralığının çok küçük bir bölümünde toplanırdı. Yöntem hedef aralığı verimli kullanmaz. Min-max slaytındaki örnekte de 150-250 arasındaki veri 0,15-0,25 aralığına sıkışır.

**Soru 4** (ekrandan, 01:30:00): Sıralı fiyat verisi 4, 8, 9, 15, 21, 21, 24, 25, 26, 28, 29, 34 eşit frekanslı üç kutuya bölünüyor. Kutuları, kutu ortalamasıyla ve kutu sınırlarıyla yumuşatılmış değerleri bulun.

Çözüm (derste verildi; python ile doğrulandı):

- Kutular: [4, 8, 9, 15], [21, 21, 24, 25], [26, 28, 29, 34].
- Kutu ortalamasıyla: 9, 9, 9, 9 / 23, 23, 23, 23 / 29, 29, 29, 29. Tam ortalamalar 9; 22,75; 29,25'tir, slayt tam sayıya yuvarlamıştır.
- Kutu sınırlarıyla: 4, 4, 4, 15 / 21, 21, 25, 25 / 26, 26, 26, 34. Örneğin 8'in sol sınıra uzaklığı 4, sağ sınıra 7 olduğu için 4 olur; 24 sağ sınıra (25) daha yakındır.

**Soru 5** (derste sözlü, 01:35:10): Aynı veri eşit genişlikle üç kutuya bölünseydi kutu genişliği ve aralıklar ne olurdu?

Çözüm (derste verildi): $w = (34 - 4)/3 = 10$. Aralıklar 4-14, 14-24 ve 24-34'tür.

> **Çözüm (derste verilmedi):** Değerlerin kutulara dağılımı derste yapılmadı. Aralıklar soldan kapalı, sağdan açık ($[4,14)$, $[14,24)$, $[24,34]$) alınırsa kutular [4, 8, 9], [15, 21, 21] ve [24, 25, 26, 28, 29, 34] olur (python ile doğrulandı). Eşit genişlikte kutulardaki örnek sayıları eşit değildir.

**Soru 6** (ekrandan, 01:50:00): Eksik veri tablosunda (Bölüm 8.2) hangi öz nitelik ve hangi örnekler silinebilir?

Çözüm (derste verildi): %55 eksik olan $V_3$ öz niteliği silinebilir. Örneklerden %80 eksik olan 13. örnek ve %60 eksik olan 3. ve 15. örnekler silinir. Bu silmelerden sonra kalan boşluk yaklaşık %7,4'tür ($5/68$; python ile doğrulandı).

**Soru 7** (derste sözlü, 01:50:19 ve 01:57:18): 18. örneğin $V_4$ değeri boştur. a) Sınıf etiketi yokken, b) ilk 10 örnek sağlıklı, son 10 örnek hasta grup olarak etiketlenmişken bu değer nasıl doldurulur?

Çözüm (derste verildi): a) $V_4$ sütunundaki mevcut değerlerin ortalaması yazılır. b) 18. örnek hasta gruptadır; $V_4$ için yalnızca hasta gruptaki (11-20. örnekler) mevcut değerlerin ortalaması yazılır.

> **Çözüm (derste verilmedi):** Sayısal değerler derste hesaplanmadı; tablodaki değerlerle python ile hesaplandı. a) Tablodaki 14 mevcut $V_4$ değerinin ortalaması $\approx 2{,}857$'dir (3., 13. ve 15. örnekler silindikten sonra kalan 12 değerin ortalaması $\approx 2{,}833$). b) Hasta gruptaki mevcut $V_4$ değerleri 3.3, 3.0, 3.0, 3.3, 2.6, 2.2'dir; ortalama $2{,}9$'dur (15. örnek silindikten sonra kalan beş değerle $2{,}88$).

**Soru 8** (derste sözlü, 01:46:43): Eksik veri tablosunda 12. örnekte hiç eksik yok, ama yüzde 9 yazıyor. Neden?

Çözüm (derste verildi): Tablodaki bir yazım hatasıdır; değer 0 olmalıdır.

**Soru 9** (derste sözlü, 00:30:24): Ordinal bir değişkenin değerleri arasında mesafe hesaplayabilmek için ne gerekir?

Çözüm (derste verildi): Herhangi iki değer arasındaki uzaklığın, başka iki değer arasındaki uzaklıkla aynı birimde (eşit aralıklı) olması gerekir. Sıralama ya da gelir aralığı gibi örneklerde aralıklar değişken olduğu için mesafe tanımlanamaz; yalnızca sıralama ilişkisi vardır.

## Dersin Toparlaması

Bu derste veri ön işlemenin temelleri işlendi. Önce verinin satır (örnek) ve sütun (öz nitelik) yapısı, nümerik ve kategorik öz nitelikler, dummy değişken kodlaması ve ölçek türleri (aralık, oran, nominal, ordinal) konuşuldu. Ordinal değişkende sıralama ilişkisinin olduğu, mesafe ilişkisinin olmadığı vurgulandı. Ham verinin eksik değer, bozulma, yanlış kayıt ve yetersiz örnekleme gibi sorunları ve bu aşamanın veri madenciliği emeğinin büyük kısmını aldığı hatırlatıldı. Ardından mesafeye dayalı yöntemlerde öz nitelikleri eşitlemek için üç normalizasyon tekniği (ondalık ölçekleme, min-max, standart sapma) anlatıldı ve bir örnekle uygulandı. $[-1, 1]$ aralığına dönüşüm, iki noktadan geçen doğru denklemiyle kuruldu.

Dersin ikinci yarısında binning ile veri yumuşatma, fark ve oranlarla yeni öz nitelik türetme ve eksik verinin giderilmesi ele alındı. Eksik veri tablosu üzerinde hangi öz niteliğin ve hangi örneklerin silinebileceği, kalan eksiklerin öz nitelik ortalaması ya da sınıf içi ortalamayla nasıl doldurulacağı tartışıldı. Hocaya göre her ön işleme adımı alternatifli yapılmalı ve sonuçlar karşılaştırılmalıdır. Slaytların kalan kısmı olan aykırı değer analizi ve zaman serisi verisinin düzenlenmesi bir sonraki derste işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
