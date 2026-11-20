# Ders 11 Genişletilmiş Notu: İstatistiksel Veri Analizi: Betimsel İstatistik, Olasılık, Hipotez Testi, Regresyon ve Kümeleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Derste anlatım çoğunlukla İngilizcedir ve altyazının önemli bir kısmı Whisper tekrarlarıyla bozulmuştur; slaytların birçoğu animasyonlu olduğundan karelerde boş görünür. Boşluklar slayt karelerinden tamamlandı, tamamlanamayan yerler işaretlendi. -->

## İçindekiler

- 1. Veriyi Özetlemek ve Değişken Türleri
- 2. Histogramlar
- 3. Merkezi Eğilim Ölçüleri
- 4. Değişkenlik Ölçüleri
- 5. Veri Dönüşümleri
- 6. Değişkenler Arasındaki İlişkileri İncelemek
- 7. Belirsizliğin Ölçüsü Olarak Olasılık
- 8. Dağılımlar: Gauss ve Poisson
- 9. Parametre Kestirimi ve Hipotez Testi
- 10. Regresyon Analizi ve Denetimli Öğrenme
- 11. Denetimsiz Öğrenme ve Kümeleme
- 12. Örnek Sorular
- 13. Dersin Toparlaması

## 1. Veriyi Özetlemek ve Değişken Türleri

Ders, bir önceki haftada başlanan betimsel istatistik (descriptive statistics) konusundan devam etti. Hocanın çıkış noktası şudur: veri toplandıktan sonraki adım, büyük resmi görebilmek için onu özetlemektir. Ham veri tek başına bir şey anlatmaz; özetleme, sonraki bütün analizlerin (makine öğrenmesinde öznitelik çıkarma dahil) temelini oluşturur.

### 1.1 Analizden önceki adımlar

Slaytta analizden önce yapılması gereken üç ön adım sıralandı (ekrandan, 00:15:00):

- Yanıtlanmak istenen bilimsel soruyu tanımlamak (problem tanımı).
- İlgilenilen popülasyondan temsilci üyeler seçmek (örnekleme).
- Veriyi gözlemsel çalışmalarla ya da rastgele deneylerle toplamak.

Analiz genellikle veri keşfiyle (data exploration) başlar ve önce değişkenler tek tek ele alınır. Keşif için iki araç vardır: veri görselleştirme teknikleri ve özet istatistikler. Hangisinin kullanılacağı değişkenin türüne bağlıdır.

### 1.2 Kategorik ve sayısal değişkenler

Hoca değişkenlerin iki genel gruba ayrıldığını hatırlattı: kategorik değişkenler ve sayısal (nicel) değişkenler. Sayı ya da ölçüm içeren veri için çizgi grafikleri ve zaman serisi gösterimleri gibi farklı grafik türleri gerekir.

Kategorik veri, genellikle her gruptaki birey sayısıyla, yani **frekansla** özetlenir. Bu, kategorik veriyi sayısal hâle getirmenin bir yoludur; hoca bunun dizi hizalama konusunda da görüldüğünü hatırlattı. Bir gruptaki bireylerin yüzdesine **göreli frekans** denir:

$$\text{göreli frekans} = \frac{\text{gruptaki öğe sayısı}}{\text{toplam öğe sayısı}}$$

Hocanın örneği: toplam 20 öğe olsun; 5'i A grubunda, 15'i B grubunda. Frekanslar 5 ve 15'tir. Göreli frekanslar:

- A grubu: $5/20 = 0.25$
- B grubu: $15/20 = 0.75$

Göreli frekanslar 0 ile 1 arasındadır ve toplamları 1'dir. 100 ile çarpılınca yüzde olurlar (%25 ve %75); pasta grafiği bu yüzdelere dayanır.

Sayısal veri ise gerçek anlamı olan ölçümleri ya da sayımları gösterir. Bu sayılardan veri hakkında daha fazla öznitelik çıkarılabilir: merkez ölçüleri, yayılım ölçüleri ve iki değişken arasındaki ilişkinin ölçüleri. Sayısal bir değişkenin dağılımında hoca iki yönle özellikle ilgilenildiğini söyledi:

- **Konum (location):** değerlerin merkezi eğilimi, yani değerlerin çoğunun etrafında toplandığı nokta.
- **Yayılım (spread):** değerlerin bu merkez etrafında ne kadar dağıldığı.

Dağılım, olası değerleri, bu değerleri gözleme şansını ve popülasyondan çekilen rastgele bir örneklemde onları ne sıklıkla görmeyi beklediğimizi gösterir.

## 2. Histogramlar

### 2.1 Tanım ve kutulama

Histogram, sayısal değişkenleri görselleştirmek için yaygın olarak kullanılan bir frekans dağılımıdır (ekrandan, 00:20:00). Görünüşü çubuk grafiğe benzer. Değişkenin değerleri önce gruplanır; bu gruplama işlemine **binning** (kutulama), sonlu sayıdaki örtüşmeyen aralıklara da **bin** (kutu) denir. Her kutunun içinde belli sayıda sayısal değer bulunur.

Kutu sayısını seçmek için deneysel bir öneri olan **Sturges kuralı** verildi:

$$k = 1 + 3.3\log n$$

Burada $k$ kutu sayısı, $n$ örnek sayısıdır. Hoca bunun kutu sayısını belirlemek için kaba bir formül olduğunu vurguladı.

### 2.2 Tipik histogram ve biçimler

Derste, ortalaması 0 ve standart sapması 1 olan normal dağılımdan çekilmiş 1000 örneğin histogramı tipik bir histogram örneği olarak gösterildi. Hoca, ortalama ve standart sapma kavramlarını henüz tanımlamadıklarını ama öğrencilerin bunları başka derslerden bildiğini belirtti.

Slaytta histogramı betimleyen iki ölçü yer aldı (ekrandan, 00:25:00):

- Bir ya da daha fazla kutudaki **mutlak frekans**: $f_i$, $i$. kutudaki frekanstır.
- Bir ya da daha fazla kutudaki **göreli frekans**: $f_i/n$, $i$. kutudaki göreli frekanstır; $n$ özetlenen toplam örnek sayısıdır.

Histogram birkaç biçim gösterebilir: simetrik, çarpık (skewed) ya da iki tepeli (bimodal). Hoca biçimleri şöyle açıkladı:

- **Simetrik:** histogram ortası etrafında simetriktir.
- **Çarpık:** dağılım pozitif yöne (sağa) ya da negatif yöne (sola) çarpıktır. Derste sola çarpık ve sağa çarpık histogram örnekleri gösterildi.
- **İki tepeli ya da çok tepeli:** ikiden fazla tepe varsa dağılım çok tepeli (multimodal) sayılır.

Her biçimin bir anlamı vardır. Histogramın biçimi, yani verinin dağılımı bilindiğinde daha uygun betimsel istatistikler seçilir. Bu, dersin ilerleyen kısmındaki "hangi ortalama?" sorusunun temelidir.

### 2.3 Yoğunluk histogramı

Histogramda her aralığın çubuk yüksekliği göreli frekansa (ya da 100 ile çarpılınca yüzdeye) eşitlenebilir. Göreli frekans, aralığın genişliğine bölünürse **yoğunluk histogramı** (density histogram) elde edilir:

$$\text{yoğunluk}_i = \frac{f_i / n}{\text{aralık genişliği}}$$

Yoğunluk histogramında her çubuğun yüksekliği ilgili aralığın yoğunluğunu gösterir. Çubuğun alanı yükseklik çarpı genişlik olduğu için alan, o aralığın göreli frekansına eşittir.

### 2.4 Tepe sayısı

Slayttaki özet şöyledir (ekrandan, 00:30:00): önceki slaytlardaki histogramların, simetrik ya da çarpık olsun, ortak bir yanı vardır; hepsinin tek tepesi (modu) vardır. Bu tür histogramlara ve onlara karşılık gelen dağılımlara **tek tepeli** (unimodal) denir. Bazen histogramların birden fazla modu olur; **iki tepeli** histogram, iki tek tepeli histogramın birleşimi gibi görünür.

### 2.5 Histogram neden önemli?

Hoca histograma diğer konulardan daha fazla zaman ayırdığını, çünkü histogramın önemli olduğunu söyledi. Histogram, örneklerin elde edildiği rastgele sürecin gerçek **olasılık yoğunluk fonksiyonunun** (ya da olasılık dağılımının) kaba bir kestirimidir. Olasılık yoğunluk fonksiyonu, rastgele bir $x$ olayının gerçekleşme olasılığını sayısallaştıran fonksiyondur.

## 3. Merkezi Eğilim Ölçüleri

Hoca bu kısma, merkezi eğilim ölçülerinin veri kümelerinin hemen her alanda, her analiz yönteminde ve makine öğrenmesinde kullanılan basit sayısal öznitelikleri olduğunu söyleyerek başladı. Çok basittirler ama her analiz onlarla başlar.

### 3.1 Tanım

Merkezi eğilim, bir olasılık dağılımı için merkezi ya da tipik bir değerdir; dağılımın merkezi ya da konumu da denir (ekrandan, 00:35:00). Merkezi eğilim ölçülerine çoğu zaman **ortalamalar** (averages) denir. Merkezi eğilimi yansıtan birkaç ölçü vardır (ekrandan, 00:40:00):

- örneklem ortalaması (sample mean),
- örneklem medyanı (sample median),
- örneklem modu (sample mode).

### 3.2 Hangi ölçü seçilmeli?

Hoca şu durumu sordu: elimizde $n$ örnek olsun ve bu örneklerin merkezi eğilimini bir makine öğrenmesi algoritmasında öznitelik olarak kullanmak isteyelim. Üç ölçüden hangisini seçeceğimize nasıl karar veririz? Hocanın gözlemine göre insanlar çoğu zaman başkalarının kullandığını körü körüne seçer. Oysa seçim, verinin dağılımına göre yapılmalıdır: örneklem ortalaması mı, medyanı mı, modu mu kullanılacağı ve hatta hangi tür ortalamanın seçileceği histogramın biçiminden çıkarılır.

### 3.3 Olasılık tanımıyla ortalama

Matematikte ortalamanın bağlama göre birkaç tanımı vardır. Olasılık ve istatistikte **ortalama** ile **beklenen değer** eş anlamlıdır. Kesikli bir olasılık dağılımına sahip rastgele değişken $X$ için ortalama, her olası değerin o değerin olasılığıyla ağırlıklandırılmış toplamıdır:

$$E[X] = \sum_x x\,P(x)$$

Burada $x$ örnek değeri, $P(x)$ o değerin olasılığıdır. Hocanın örneği: veri kümesinde $x_0$'dan $x_9$'a 10 örnek olsun. Her değer eşit olasılıklıysa her birinin olasılığı $1/10 = 0.1$ olur. Bu durumda formül, bütün örnek değerlerini toplayıp örnek sayısına bölmeye indirgenir. Bu, ortalamanın olasılıksal yaklaşımıdır.

### 3.4 Aritmetik ortalama

Bir veri kümesi için ortalama, aritmetik ortalama, matematiksel beklenti ve bazen de "average" terimleri, kesikli bir sayı kümesinin merkezi değerini anlatmak için eş anlamlı kullanılır. Hoca elektrik mühendisliğinden bir bağlantı kurdu: bir elektrik sinyali için bu değer sinyalin **DC değerine** (DC bileşenine) karşılık gelir.

Veri kümesi bir istatistiksel popülasyondan örnekleme yoluyla elde edilmiş gözlemlerden oluşuyorsa aritmetik ortalamaya **örneklem ortalaması** denir; bu ad onu popülasyon ortalamasından ayırır. Popülasyon ortalaması genellikle bilinmez, ama örneklem ortalamasıyla kestirilebilir.

Aritmetik ortalama (ya da kısaca ortalama), $x_1, x_2, \ldots, x_n$ örneklemi için $\bar{x}$ ile gösterilir (ekrandan, 00:45:00):

$$\bar{x} = \frac{x_1 + x_2 + \cdots + x_n}{n}$$

> **Hocanın vurgusu:** Aritmetik ortalama, verinin orta noktanın her iki yanında aşağı yukarı benzer biçimde yayıldığı durumlarda kullanılır. Böyle bir veri kümesini öznitelikle temsil etmek için basit ortalama yeterlidir; bu basit bir veri indirgemedir.

### 3.5 Geometrik ve harmonik ortalama

Aritmetik ortalamanın dışında başka ortalama tanımları da vardır. Slaytta iki tanesi formülleriyle verildi (ekrandan, 00:50:00).

**Geometrik ortalama**, çarpımlarına göre yorumlanan pozitif sayı kümeleri için yararlı bir ortalamadır; örneğin büyüme oranları:

$$\bar{x} = \sqrt[n]{x_1 \times x_2 \times \cdots \times x_n}$$

**Harmonik ortalama**, bir birime göre tanımlanmış sayı kümeleri için yararlı bir ortalamadır; örneğin hız:

$$\bar{x} = \frac{n}{\dfrac{1}{x_1} + \dfrac{1}{x_2} + \cdots + \dfrac{1}{x_n}}$$

Hocanın seçim kuralı: dağılım simetrikse aritmetik ortalama seçilir. Simetrik değilse geometrik ya da harmonik ortalama seçilebilir; örneğin veride bazı yüksek, uç değerler varsa harmonik ortalama seçilebilir.

### 3.6 Ortalamalar arasındaki eşitsizlik

Aritmetik (AM), geometrik (GM) ve harmonik (HM) ortalamalar bir eşitsizlik zinciri sağlar. Hoca, geometrik ve harmonik ortalamanın her zaman aritmetik ortalamadan küçük olduğunu, ancak belli bir koşulda üçünün tam olarak aynı değeri verdiğini söyledi ve bu koşulu sınıfa sordu. Cevabı kendisi verdi: **bütün değerler eşitse** üç ortalama da eşit olur.

$$HM \le GM \le AM$$

> **Ders sonrası not:** Hoca "geometrik ve harmonik ortalama her zaman aritmetik ortalamadan küçüktür" dedi. Kesin ifade "küçük ya da eşittir"dir; eşitlik, hocanın da belirttiği gibi, yalnız bütün değerler eşitken olur.

Hoca her ortalamanın hangi durumda en iyi olduğunu şöyle özetledi:

- **Aritmetik ortalama:** veri çarpık değilse, uç aykırı değer yoksa ve tek tek veri noktaları birbirinden bağımsızsa.
- **Geometrik ortalama:** veriler birbiriyle ilişkiliyse (interrelated).
- **Harmonik ortalama:** değerlerin çoğunun düzgün dağıldığı büyük bir popülasyonda, birkaç tane belirgin biçimde yüksek aykırı değer varsa.

### 3.7 Ağırlıklı aritmetik ortalama

Hoca, üç tür ortalama dışında bahsetmeye değer bir dördüncüsünün de olduğunu söyledi. **Ağırlıklı aritmetik ortalama**, aynı popülasyondan alınmış ama örneklem boyutları farklı olan örneklemlerin ortalama değerlerini birleştirmek için kullanılır (ekrandan, 00:55:00):

$$\bar{x} = \frac{\sum_{i=1}^{n} w_i \times x_i}{\sum_{i=1}^{n} w_i}$$

Her örnek değeri belli bir ağırlıkla çarpılır ve toplam ağırlığa bölünür. Hoca, bazı örneklere daha çok, diğerlerine daha az önem verilmek istendiğinde bu ortalamanın kullanılabileceğini söyledi. Uygulamada yaygın olarak kullanılır: örneğin konuşma işlemede ve Doppler sinyal analizinde ortalama frekansı belirlemek için. <!-- BELİRSİZ: Doppler'den sonra sayılan uygulama altyazıda "platform analysis" diye bozuk geçiyor. -->

### 3.8 Kuvvet ortalaması

Bir başka ortalama türü **kuvvet ortalamasıdır** (power mean). Hoca bunun çok genel bir ortalama olduğunu, $p$ üssü değiştirilerek diğer ortalama türlerinin elde edilebildiğini anlattı:

- $M_{-\infty}$: veri örneğinin en küçük değeri,
- $M_{-1}$: harmonik ortalama,
- $M_0$: geometrik ortalama,
- $M_1$: aritmetik ortalama,
- $M_2$: karekök ortalama kare (RMS),
- $M_{\infty}$: veri örneğinin en büyük değeri.

<!-- BELİRSİZ: Kuvvet ortalamasının formülü slaytta gösterildi ama karelerde görülmedi. -->

### 3.9 Medyan

Hoca sınıfa medyanın merkezi eğilimi temsil etmek için ne zaman kullanıldığını sordu. Cevap: veri simetrik değilse, yani çarpık dağılımlarda. Böyle bir dağılımda merkezi eğilimin doğru temsili medyandır.

Medyan şöyle bulunur: veri sıralanır; örnek sayısı $n$ tekse ortadaki değer medyandır, $n$ çiftse ortadaki iki değerin ortalaması medyan olarak alınır.

> **Hocanın vurgusu:** Örneklem ortalamasıyla karşılaştırıldığında örneklem medyanı, veri kümesindeki aykırı değerlere ya da uç değerlere daha az duyarlıdır.

Slayta göre (ekrandan, 01:00:00):

- Medyan, çeyrekler arası açıklığıyla (IQR) birlikte verilebilir.
- 1. çeyrek noktasının altında verinin 1/4'ü bulunur.
- 3. çeyrek noktasının altında örneğin 3/4'ü bulunur.
- IQR, örneğin ortadaki yarısını içerir.
- Bu durum bir "kutu ve bıyık" (box and whisker) grafiğinde gösterilebilir.

### 3.10 Mod ve üçünün karşılaştırması

Üçüncü merkezi eğilim ölçüsü **moddur**. Hoca ortalama, medyan ve modu karşılaştıran bir şekil gösterdi: veri simetrikse mod, medyan ve ortalama aynı noktada bulunur. Dağılım giderek asimetrikleştikçe (çarpıklaştıkça) üç ölçünün merkezi eğilimi temsil edişi birbirinden ayrılır.

<!-- BELİRSİZ: Mod anlatımının ayrıntıları (01:00-01:02 arası) altyazıda okunamıyor. Bunun ardından yaklaşık 18 dakikalık bir ara verildi (karelerde slayt 61 sabit kalıyor). -->

## 4. Değişkenlik Ölçüleri

Aradan sonra hoca, veri indirgemede kullanılan bir başka öznitelik grubuna geçti: **değişkenlik ölçüleri** (measures of variability). Verinin değişkenliğini anlatan iki yaygın özet istatistik örneklem varyansı ve örneklem standart sapmasıdır; bunlar birbirine bağlıdır, biri bilinirse diğeri kolayca bulunur. Çeyrekler arası açıklıklar da değişkenliği betimlemek için kullanılır.

### 4.1 Varyans ve standart sapma

$\bar{x}$, merkezi eğilim ölçülerinden biriyle belirlenen ortalamadır. Örneklem varyansı, ortalamadan sapmaların karelerine dayanan yaygın bir yayılım ölçüsüdür; varyansın karekökü **standart sapmadır**.

<!-- BELİRSİZ: Varyans formülünün slaydı karede görülmedi. Korelasyon slaydındaki (n-1) paydası, formülün örneklem varyansı olarak $s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(x_i - \bar{x})^2$ biçiminde verildiğini düşündürüyor. -->

$$s^2 = \frac{1}{n-1}\sum_{i=1}^{n}(x_i-\bar{x})^2, \qquad s = \sqrt{s^2}$$

> **Hocanın vurgusu:** Standart sapma (kısaca SD) normal dağılan veri için kullanılır ve verinin ortalaması etrafında ne kadar değiştiği hakkında bilgi verir.

Standart sapma, bir değer kümesinin ortalama etrafında ne kadar yayıldığını gösterir. Normal dağılımda:

- $\pm1$ SD aralığı verinin yaklaşık %68.3'ünü,
- $\pm2$ SD aralığı %95.4'ünü,
- $\pm3$ SD aralığı %99.7'sini içerir.

> **Ders sonrası not:** Altyazıda hoca $\pm1$ SD için "%62.2" diyor; doğrusu yaklaşık %68.3'tür (python: $\mathrm{erf}(1/\sqrt{2}) \approx 0.6827$). Hoca dersin ilerisinde normal dağılım için "yaklaşık %68" dedi. %95.4 ve %99.7 değerleri doğrudur.

Standart sapmayı yorumlarken işe yarayan özellikler:

- Kare alma nedeniyle hiçbir zaman negatif olamaz; her zaman pozitiftir.
- Alabileceği en küçük değer sıfırdır.
- Ortalamaya olan uzaklığa dayandığı ve ortalama aykırı değerlerden etkilendiği için standart sapma da aykırı değerlerden etkilenir.
- Standart sapmanın birimi orijinal verinin birimiyle aynıdır; varyans ise birimin karesindedir.

Slaytta önemli bir not vardı (ekrandan, 01:25:00): normal dağılımlarda (simetrik histogramlarda) örneklem ortalaması ve örneklem standart sapması, altta yatan olgunun istatistiğini betimlemek için gereken tek parametrelerdir. Hoca buradan şu sonucu çıkardı: verinin histogramı simetrikse öznitelik kümesi olarak örneklem ortalaması ve standart sapması kullanılabilir.

### 4.2 Kantiller

Hoca "quantity" kelimesinden gelen **kantil** (quantile) kavramını tanımladı. Kantil, bir örneğin eşit büyüklükte bitişik alt gruplara bölündüğü noktadır; fraktil (fractile) de denir. Olasılık dağılımını eşit olasılıklı aralıklara bölmek anlamına da gelebilir.

- **Çeyrekler** (quartiles) kantildir; dağılımı dört eşit parçaya böler.
- **Yüzdelikler** (percentiles) kantildir; dağılımı 100 eşit parçaya böler.
- **Ondalıklar** (deciles) kantildir; dağılımı on eşit parçaya böler.

Çeyrekler cinsinden medyan **2. çeyrektir**, kısaca $Q_2$. $Q_2$ bilindiğinde:

- $Q_1$ (1. çeyrek), $Q_2$'nin altında kalan örneklerin medyanı alınarak bulunur.
- $Q_3$ (3. çeyrek), $Q_2$'nin üstünde kalan örneklerin medyanı alınarak bulunur.

Çeyrekler yüzdeliklerle de ifade edilir: 1. çeyrek 25. yüzdelik, 2. çeyrek 50. yüzdelik, 3. çeyrek 75. yüzdeliktir. Derste $Q_1$, $Q_2$ ve $Q_3$'ün bir dağılım üzerindeki yerini gösteren bir şekil de verildi.

### 4.3 Beş sayı özeti

Bir veri kümesini betimsel istatistiklerle temsil etmek için genellikle beş öznitelik kullanılır; bunlara **beş sayı özeti** (five-number summary) denir. Artan sırayla:

- en küçük değer (minimum),
- 1. çeyrek ($Q_1$),
- medyan ($Q_2$),
- 3. çeyrek ($Q_3$),
- en büyük değer (maximum); örneklemdeki en büyük değerdir.

Beş sayı özetinden iki yayılım ölçüsü türetilebilir (ekrandan, 01:30:00):

- **Açıklık** (range): gözlenen en büyük değer ile en küçük değer arasındaki fark.
- **Çeyrekler arası açıklık** (IQR): $IQR = Q_3 - Q_1$.

### 4.4 Kutu grafikleri ve aykırı değerler

Kutu grafiği (boxplot), beş sayı özetini (en küçük, $Q_1$, medyan, $Q_3$, en büyük) kullanarak veriyi görselleştiren bir tekniktir. Hoca, bu sayede bir veri kümesinde aykırı değer olup olmadığını belirlemenin çok verimli olduğunu söyledi. Derste verilen aykırı değer tanımı:

$$x > Q_3 + 3 \cdot IQR \quad \text{ya da} \quad x < Q_1 - 3 \cdot IQR \;\Rightarrow\; \text{aykırı değer}$$

Bu formülde 3 yerine 1.5 alınırsa, sınırları aşan değerler **şüpheli aykırı değer** (suspected outlier) sayılır.

> **Ders sonrası not:** Hoca tanımı ilk söylediğinde "Q2'nin üstünde 3 IQR'yi aşan değer" dedi; hemen ardından söylediği gibi üst sınır $Q_3 + 3\,IQR$'dir.

> **Ek bilgi (derste anlatılmadı):** Pek çok kaynakta (ve kutu grafiği çizen yazılımlarda) bıyıklar varsayılan olarak $Q_1 - 1.5\,IQR$ ve $Q_3 + 1.5\,IQR$ sınırlarına kadar uzatılır, bu sınırları aşan noktalar aykırı değer olarak tek tek çizilir. 3 IQR sınırı ise "uç aykırı değer" için kullanılır. Hangi katsayının kullanıldığı kaynağa göre değişir.

### 4.5 Değişim katsayısı

Genel olarak **değişim katsayısı** (coefficient of variation, CV), ortalamaları belirgin biçimde farklı olan değişkenleri yayılımları açısından karşılaştırmak için kullanılır; bu fark büyük olasılıkla farklı ölçü birimlerinden kaynaklanır. Yayılımı birimden bağımsız sayısallaştırmak için CV kullanılır; CV, standart sapmanın örneklem ortalamasına bölümüdür (ekrandan, 01:35:00). Ortalamanın pozitif olduğu varsayılır:

$$CV = \frac{s}{\bar{x}}$$

## 5. Veri Dönüşümleri

Veri analizinden önce veri dönüşümleri de yaygın biçimde kullanılır. Dönüşümler, bazı özellikleri daha belirgin hâle getiren ya da bazı işlemleri kolaylaştıran süreçlerdir. Dönüşüm yapmanın nedenleri: analizde uç değerlerin etkisini azaltmak, veri dağılımını daha normal hâle getirmek ya da aykırı değerleri daha iyi görmek için daha bilgilendirici grafikler üretmek.

### 5.1 Ölçekleme ve kaydırma

Bir değişkenin gözlenen değerleri bir $a$ sabitiyle çarpılırsa ($y = a x$), ortalaması, standart sapması ve varyansı sırasıyla $a$, $|a|$ ve $a^2$ ile çarpılır:

$$\bar{y} = a\bar{x}, \qquad s_y = |a|\,s_x, \qquad s_y^2 = a^2 s_x^2$$

Gözlenen değerler bir $b$ sabitiyle kaydırılırsa ($y = x + b$):

$$\bar{y} = \bar{x} + b, \qquad s_y = s_x, \qquad s_y^2 = s_x^2$$

Değerler önce $a$ ile çarpılıp sonra $b$ eklenirse ($y = a x + b$) iki etki birleşir: $\bar{y} = a\bar{x} + b$, $s_y = |a|\,s_x$, $s_y^2 = a^2 s_x^2$.

> **Ders sonrası not:** Hoca bir yerde değişim katsayısının ölçekleme ve kaydırmadan etkilenmediğini söyledi, ardından $ax + b$ dönüşümünde CV'nin "elbette değişeceğini" belirtti. Doğrusu: pozitif bir $a$ ile ölçekleme CV'yi değiştirmez ($|a|s/(a\bar{x}) = s/\bar{x}$), $b$ ile kaydırma ise ortalamayı değiştirip standart sapmayı değiştirmediği için CV'yi değiştirir.

### 5.2 Değişken standartlaştırma

Bir başka yöntem **değişken standartlaştırmadır**. Bu basit bir doğrusal dönüşümdür: gözlenen değerlerden örneklem ortalaması çıkarılır ve sonuç örneklem standart sapmasına bölünür.

$$z_i = \frac{x_i - \bar{x}}{s}$$

Bunu yapınca ortalama sıfıra kayar ve standart sapma bire eşitlenir. Hoca birkaç başka standartlaştırma yöntemi de olduğunu, ama bunların ders kapsamı dışında kaldığını söyledi. Bu dönüşüm özellikle regresyon analizinde ve kümelemede yaygındır. Ayrıca verinin ölçeğinden bağımsız olduğu için her değeri kabul edip doğru sonuç veren genel bir analiz sistemi tasarlamayı mümkün kılar.

> **Ders sonrası not:** Hoca standartlaştırılmış verinin "0 ile 1 arasında normalize edildiğini" söyledi. $z$ dönüşümü ortalamayı 0, standart sapmayı 1 yapar; değerleri 0-1 aralığına sıkıştırmaz, negatif değerler de oluşur. Değerleri 0-1 aralığına getiren dönüşüm min-max normalizasyonudur.

## 6. Değişkenler Arasındaki İlişkileri İncelemek

Bir başka analiz türü değişkenler arasındaki ilişkiyi keşfetmektir. Hoca bunu değişken türlerine göre üç durumda ele aldı.

### 6.1 İki sayısal değişken: saçılım grafikleri

İki sayısal değişken varsa (ekrandan, 01:40:00), ilişki önce saçılım grafikleriyle incelenir. Derste dört örnek gösterildi:

- iki değişken arasında **pozitif doğrusal** ilişki,
- $x$ ile $y$ arasında **negatif doğrusal** ilişki,
- ilişki yok ya da ihmal edilecek kadar küçük,
- ilişki var ama **doğrusal değil**.

Hoca verinin gözlemsel bir çalışmadan geldiğini belirtti; bu tür veride bulunan ilişki bir birliktelik (association) ilişkisidir.

### 6.2 Pearson korelasyon katsayısı

Korelasyon, iki değişken arasındaki ilişkiyi sayısal olarak incelemenin bir yöntemidir. Slayttaki tanım (ekrandan, 01:45:00): korelasyon, iki sayısal değişken arasındaki doğrusal ilişkinin gücünü ve yönünü sayısallaştırır. $n$ gözlemlik bir örneklemde $(x_1, y_1), (x_2, y_2), \ldots, (x_n, y_n)$ gözlem çiftleri için **Pearson korelasyon katsayısı** $r$ bir özet istatistik olarak kullanılabilir:

$$r_{xy} = \frac{\sum_{i=1}^{n}(x_i - \bar{x})(y_i - \bar{y})}{(n-1)\,s_x s_y}$$

Burada $s_x$ ve $s_y$ örneklem standart sapmalarıdır. $r$ değerleri her zaman $-1$ ile $+1$ arasındadır. Hocanın yorumu:

- $+1$: tam ilişki; $x$ ile $y$ (ölçek dışında) aynı biçimde değişir.
- $-1$: yine tam ilişki ama ters yönde; hoca bunu sinyal işleme diliyle "aynı ama 180 derece faz kaymalı" diye anlattı.
- Arada kalan değerler belli derecede bir ilişkiyi gösterir.
- Katsayı pozitifse ilişki pozitiftir: biri doğrusal arttıkça diğeri de artar.
- Negatifse ilişki negatiftir: biri artarken diğeri azalır.
- Katsayı 0.5'ten büyükse genellikle ilişkinin güçlü olduğu kabul edilir.

> **Ek bilgi (derste anlatılmadı):** Güç yorumunda katsayının mutlak değerine bakılır; $r = -0.8$ de güçlü (negatif) bir ilişkidir. Pearson katsayısı yalnız doğrusal ilişkiyi ölçer; 6.1'deki doğrusal olmayan ilişki örneğinde güçlü bir bağ olduğu hâlde $r$ sıfıra yakın çıkabilir.

### 6.3 Çapraz korelasyon ve otokorelasyon

Pearson katsayısı tek bir değer verir. **Çapraz korelasyon** ise iki dizi arasındaki bütün olası ilişkileri (bütün kaydırmaları) dikkate alır; sonuç tek değer yerine bir ilişki dağılımıdır. $x$ ve $y$ aynı büyüklükse buna **otokorelasyon** denir.

Çapraz korelasyon ya da otokorelasyon algoritması iç içe iki `for` döngüsü olarak yazılabilir; bu uygulama açısından oldukça zaman alıcıdır. Hızlı Fourier dönüşümüne dayanan "hızlı korelasyon" adlı alternatif bir uygulama vardır, ama hoca bu algoritmanın ders kapsamı dışında olduğunu söyledi.

### 6.4 Örneklem kovaryansı

İlişkiyi incelemek için bir başka parametre **örneklem kovaryansıdır**. Pearson korelasyon katsayısının paydasından standart sapmalar çıkarılırsa elde edilen istatistik örneklem kovaryansıdır:

$$\operatorname{cov}(x, y) = \frac{\sum_{i=1}^{n}(x_i - \bar{x})(y_i - \bar{y})}{n-1}$$

Buna göre $r_{xy} = \operatorname{cov}(x,y)/(s_x s_y)$ yazılabilir.

### 6.5 İki kategorik değişken: olumsallık tabloları

İki kategorik değişken varsa ilişki **olumsallık tablolarıyla** (contingency tables) incelenebilir. Bu tablo, birkaç kategorik değişken arasındaki ilişkiyi özetlemek için kullanılır ve özel bir frekans dağılımı tablosu türüdür.

İlişkinin gücünü ölçmenin bir yolu **oranlar farkını** hesaplamaktır: $p_2 - p_1$ (ekrandan, 01:50:00). Derste aspirin ve plasebo gruplarında kalp krizi örneği kullanıldı. Bu örnekte kalp krizi geçirenlerin oranı, aspirin grubunda plasebo grubuna göre 0.0077 daha düşüktür. Hoca daha anlamlı bir ölçü olarak bu farkı plasebo oranına göre ifade etti: yaklaşık **−%45**.

<!-- BELİRSİZ: Olumsallık tablosunun kendisi (grup sayıları) karelerde görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** Bu örnek büyük olasılıkla ders kitaplarında sık kullanılan Physicians' Health Study verisidir: plasebo grubunda 11034 kişiden 189'u, aspirin grubunda 11037 kişiden 104'ü kalp krizi geçirmiştir. Python ile $p_1 = 189/11034 \approx 0.0171$, $p_2 = 104/11037 \approx 0.0094$, $p_2 - p_1 \approx -0.0077$, $(p_2 - p_1)/p_1 \approx -0.45$, $p_2/p_1 \approx 0.55$ ve odds oranı $\approx 0.546$ bulunur; bu değerler dersteki sayılarla uyuşur.

Örneklem oranlarını karşılaştırmak için bir başka yaygın özet istatistik **göreli orandır** (relative proportion), yani iki oranın bölümü. İki oran eşitse bölüm 1 olur; bu, iki kategorik değişken arasında ilişki olmadığı anlamına gelir.

Daha yaygın olanı ise **örneklem odds'larını** karşılaştırmaktır. Hoca bu terimin önceki derslerde de kullanıldığını hatırlattı. $p$, ilgilenilen olay için örneklem oranıysa odds:

$$o = \frac{p}{1-p}$$

Plasebo grubunda kalp krizi odds'u $o_1$, aspirin grubunda $o_2$ olarak hesaplanır ve ikisi **odds oranıyla** karşılaştırılır:

$$OR = \frac{o_2}{o_1}$$

Derste bu örnek için $OR \approx 0.54$ bulundu. $OR = 1$ ise iki değişken arasında ilişki yoktur; $OR$'un 1'den uzak değerleri güçlü ilişkiyi gösterir.

### 6.6 Sayısal ve kategorik değişken

Bir sayısal ve bir kategorik değişken karşılaştırılmak istenirse ilişki **nokta grafikleriyle** (strip chart da denir) görselleştirilebilir. Derste farklı kültivarlarda, C vitamininin bir biçimi olan askorbik asit içeriğinin nokta grafikleri gösterildi. Burada kültivar kategorik değişken, askorbik asit içeriği sayısal değişkendir; her kategori (kategori 1, kategori 2) için sayısal değerler ayrı ayrı çizilir. Kategorik değişkenin farklı değerleri için sayısal değişkenin **kutu grafikleri** de yan yana kullanılabilir.

## 7. Belirsizliğin Ölçüsü Olarak Olasılık

### 7.1 Neden olasılık?

Hoca, bir ölçüm varsa her zaman bir tür belirsizlik olduğunu söyledi. İstatistikte belirsizlik genellikle olasılıkla ölçülür. Slayttaki gerekçe (ekrandan, 01:55:00):

- Grafikler ve özet istatistikler, değişkenlerin dağılımını öğrenmek ve aralarındaki ilişkileri incelemek için kullanılır.
- Ancak popülasyonun bütün üyelerine neredeyse hiçbir zaman erişemediğimiz için popülasyondaki gerçek dağılımlar ve ilişkiler hakkında her zaman belirsizlik içindeyiz.
- Ayrıca gözlenen örneğe dayanan bulgularımız, popülasyondan başka örnekler alınsaydı değişebilirdi.
- Bu yüzden bulguları örneklemden bütün popülasyona genellerken belirsizliğimizin boyutunu açıkça belirtmeliyiz. Belirsizliğin ölçüsü olarak olasılığı kullanırız.

Hocanın vurguladığı bir nokta: olasılık belirsizliğin ölçüsüdür; belirsizlik yoksa olasılık da yoktur, olgu deterministiktir. Hoca ayrıca bu birkaç saatte bütün olasılık teorisini anlatmayı amaçlamadığını, yalnız hatırlatma yaptığını belirtti.

### 7.2 Temel kavramlar

- Sonucu gerçekleşmeden önce kesinlikle belirlenemeyen olguya **rastgele** (random) denir.
- Bütün olası sonuçların kümesine **örnek uzayı** ($S$) denir; örnek uzayındaki her olası sonuca bir olasılık $P$ atanır.
- **Olay**, örnek uzayının bir alt kümesidir. $E$ olayının olasılığı $P(E)$ ile gösterilir ve olayın içerdiği bütün tek tek sonuçların olasılıklarının toplamıdır.
- $E$ olayının **tümleyeni** $E^c$, örnek uzayında olup $E$'de olmayan bütün sonuçların kümesidir. Toplam olasılık 1 olduğu için $P(E^c) = 1 - P(E)$'dir.
- Bir olayın **odds**'u, olayın gerçekleşeceğinden, gerçekleşmeyeceğinden ne kadar daha emin olduğumuzu gösterir: $\text{odds}(E) = \dfrac{P(E)}{1 - P(E)}$. Hoca bunun kategorik değişkenlerde tanımlanan denklemin aynısı olduğunu hatırlattı.

<!-- BELİRSİZ: 01:58 civarında hocanın küme işlemlerine (birleşim, kesişim) değinen kısa anlatımı altyazıda bozuk. -->

### 7.3 Ortak ve marjinal olasılık

Slayttaki tanımlar (ekrandan, 02:00:00):

- İki olayın kesişiminin olasılığı $P(E_1 \cap E_2)$, bu olayların **ortak olasılığıdır** (joint probability).
- Buna karşılık $P(E_1)$ ve $P(E_2)$, $E_1$ ve $E_2$ olaylarının **marjinal olasılıklarıdır**.
- Herhangi iki olay $E_1$ ve $E_2$ için toplama kuralı geçerlidir:

$$P(E_1 \cup E_2) = P(E_1) + P(E_2) - P(E_1 \cap E_2)$$

- Hiçbir zaman birlikte gerçekleşmeyen iki olaya **ayrık** (disjoint) ya da **karşılıklı dışlayan** (mutually exclusive) olaylar denir.

### 7.4 Bağımsızlık ve Bayes kuralı

İki olay bağımsızsa bütün kesişimler, her olayın marjinal olasılıklarının basitçe çarpılmasıyla bulunur:

$$P(E_1 \cap E_2) = P(E_1)\,P(E_2)$$

Bayes teoremine (Bayes kuralına) göre iki olay $E_1$ ve $E_2$ için bir eşitlik, $E_1$'e koşullu $E_2$ olasılığı ile $E_2$'ye koşullu $E_1$ olasılığı arasındaki ilişkiyi gösterir:

$$P(E_2 \mid E_1) = \frac{P(E_1 \mid E_2)\,P(E_2)}{P(E_1)}$$

<!-- BELİRSİZ: Bayes kuralının slayttaki tam yazımı karede görülmedi; yukarıdaki standart biçimdir. -->

### 7.5 Göreli frekans olarak olasılık

Bazı rastgele olgular tekrar tekrar gözlenebilir; bu tekrarlanan deneylere ya da gözlemlere **deneme** (trial) denir. Böyle rastgele olgularda bir olayın olasılığı göreli frekans olarak yorumlanabilir. Bu yorum iki önemli varsayım gerektirir; derste anlaşılabilen ilki şudur: bir olayın olasılığı bir denemeden diğerine değişmez.

<!-- BELİRSİZ: İkinci varsayım altyazıda okunamıyor. -->

Hoca bu kavramları hatırlattığını, çünkü olasılık kavramlarının birçok biyoenformatik algoritmasında kullanıldığını vurguladı.

## 8. Dağılımlar: Gauss ve Poisson

### 8.1 Gauss (normal) dağılımı

Dağılımlardan sık söz edildiğini belirten hoca, dağılımın temelde verinin yayılımıyla ilgili olduğunu söyledi. Verinin yayılımı düzenli, çarpık, Gauss ya da başka biçimde olabilir. Gauss dağılımı üstel bir denklemle verilir; denklemde $\mu$ gerçek ortalama (popülasyon ortalaması), $\sigma$ ise çok sayıda ölçümün gerçek standart sapmasıdır.

$$f(x) = \frac{1}{\sigma\sqrt{2\pi}}\,e^{-\frac{(x-\mu)^2}{2\sigma^2}}$$

<!-- BELİRSİZ: Gauss denkleminin slayttaki yazımı karede görülmedi; yukarıdaki standart biçimdir. -->

Derste birkaç dağılım ve bunların standart sapma ve ortalamayla ilişkisi bir şekilde gösterildi. Normal dağılımda verinin yaklaşık %68'i $\mu \pm \sigma$ aralığındadır. Hoca ayrıca bir kuyruk olasılığından ($\alpha$) söz etti. <!-- BELİRSİZ: Kuyruk olasılığı $\alpha$ ile ilgili cümle altyazıda bozuk ("Alpha is the tail probability that x does not differ from u by more than sigma..."); slayt karede görülmedi. -->

### 8.2 Poisson dağılımı

**Poisson olasılık** yoğunluk fonksiyonu başka bir dağılım türüdür (ekrandan, 02:05:00). Başka şeylerin yanında radyoaktif bozunma olaylarının olasılığını, bir sayaçtan geçen hücreleri ya da ışık fotonlarının gelişini betimleyebilir.

Bir ölçümde ortalama $m$ iken belli bir sayıda $k$ olayın gerçekleşme olasılığı şöyledir:

$$P(k) = \frac{m^k\,e^{-m}}{k!}$$

Poisson dağılımının standart sapması basitçe $\sqrt{m}$'dir. Poisson kesikli bir dağılımdır; derste $m = 3$ için tipik bir Poisson dağılımı gösterildi.

<!-- BELİRSİZ: Poisson formülü sözlü anlatımdan ve standart tanımdan yazıldı; formül slaydı karede görülmedi. -->

## 9. Parametre Kestirimi ve Hipotez Testi

### 9.1 Parametreler ve çıkarım

İstatistiğin amacı, bir örneklemde bulunan bilgiye dayanarak popülasyon hakkında çıkarım yapmaktır. Popülasyonlar, **parametre** adı verilen sayısal betimleyici ölçülerle nitelenir. Hoca, herhangi bir veri bilimi, makine öğrenmesi ya da yapay zekâ algoritmasında betimleyici ölçülerin parametre olarak kullanıldığını söyledi. Tipik popülasyon parametreleri ortalama, medyan, standart sapma ve orandır.

Çıkarım problemlerinin çoğu, popülasyonun bir ya da daha fazla parametresi hakkında çıkarım olarak formüle edilebilir. Parametreler hakkında çıkarım yöntemleri iki kategoriden birine girer:

- ilgilenilen popülasyon parametresinin değerini **kestirmek**,
- parametrenin değeri hakkında bir **hipotezi test etmek**.

Hipotez testinde şu sorunun cevabı aranır: popülasyon parametresi belirli bir koşulu sağlıyor mu?

### 9.2 Kestirim

Kestirim, parametrenin bilinmeyen değerini tahmin etme sürecidir. Hocanın örneği: gerçek popülasyon ortalamasını hiçbir zaman bilemeyiz, ama örneklem ortalamasıyla (gözlenen veriyle) kestirebiliriz. Bunun için bir istatistik olan **kestirici** (estimator) kullanılır. İstatistik, yalnız gözlenen verinin bir fonksiyonudur.

- Bazen kestirim olarak tek bir değer verilir; buna **nokta kestirimi** denir.
- Nokta kestirimleri, bir parametreyi kestirirken taşıdığımız belirsizliği yansıtmaz. Popülasyondan alınan bir örneklemle kestirim yaptığımızda gerçek değer hakkında her zaman belirsizlik içinde kalırız, çünkü gerçek değer ile kestirilen değer arasında her zaman bir hata olacaktır.
- Bu sorunu gidermek için kestirim olası değerler aralığı olarak sunulabilir; buna **aralık kestirimi** denir.

### 9.3 Hipotez

Slayttaki tanım (ekrandan, 02:10:00): bir **hipotez** (çoğulu: hypotheses),

- iki ya da daha fazla değişken arasındaki ilişki hakkında test edilebilir bir önermedir,
- gözlenen bir olgu için önerilen bir açıklamadır.

Bilimsel bir deney ya da çalışmada hipotez, araştırmacının çalışmanın bulgularına ilişkin tahmininin kısa bir özetidir; sonuç bu tahmini destekleyebilir ya da desteklemeyebilir. Hipotez testi bilimsel yöntemin özüdür. Genel olarak pek çok bilimsel araştırma bir hipotez ortaya koyarak başlar. Hipotezi değerlendirmek için kestiricilere, onların örnekleme dağılımlarına ve gözlenen verideki somut değerlerine dayanılır. Hoca slayttaki bir örneği atladı.

### 9.4 Sıfır ve alternatif hipotez

Hipotez testinde iki hipotez kullanılır:

- **Sıfır hipotezi** ($H_0$): genellikle mevcut durumu (status quo) ya da ilginç hiçbir şeyin olmadığını yansıtır.
- **Alternatif hipotez** ($H_A$): araştırmacının kendi hipotezidir; sembolik olarak $H_A$ ile gösterilir.

Hipotez testinde iki tür hata yapılabilir. Birinci tip hata yapma olasılığı $\alpha$, ikinci tip hata yapma olasılığı $\beta$ ile gösterilir; derste bu hata türlerinin tablosu da gösterildi. Slayttaki ifade (ekrandan, 02:15:00): reddedilmesi gerektiği hâlde sıfır hipotezini $\beta$ olasılığıyla reddedemeyen bir test prosedürümüz olsun; bu, testimizin sıfır hipotezini $1 - \beta$ olasılığıyla doğru biçimde reddettiği anlamına gelir.

> **Ek bilgi (derste anlatılmadı):** Birinci tip hata, $H_0$ doğruyken onu reddetmektir (yanlış pozitif); ikinci tip hata, $H_0$ yanlışken onu reddetmemektir (yanlış negatif). $1-\beta$ değerine testin **gücü** (power) denir.

Hoca bu hataların birden çok parametreye genişletilmiş hâlinin makine öğrenmesinde ve veri madenciliğinde bir adı olduğunu söyleyip sınıfa sordu. <!-- BELİRSİZ: Verilen cevap altyazıda "ModTable" diye bozuk geçiyor; büyük olasılıkla karışıklık matrisi (confusion matrix) kastediliyor. -->

### 9.5 Test istatistiği ve sıfır dağılımı

Sıfır hipotezinin reddedilip reddedilmeyeceğine karar vermek için, sıfır hipotezine karşı olan deneysel destek bir istatistikle sayısallaştırılır. Hipotezi değerlendirmede kullanılan bu istatistiğe **test istatistiği** denir. Bir istatistiğin test istatistiği sayılabilmesi için sıfır hipotezi altında örnekleme dağılımının tamamen bilinmesi gerekir. Test istatistiğinin sıfır hipotezi altındaki dağılımına **sıfır dağılımı** (null distribution) denir.

## 10. Regresyon Analizi ve Denetimli Öğrenme

### 10.1 Regresyonun amacı

Hoca, istatistiksel veri analizinde yaygın kullanılan bir başka yöntem olarak regresyon analizine geçti ve bu kavramları biyoenformatikte de yoğun biçimde kullanıldıkları için hatırlattığını tekrarladı. Regresyon analizi, temelde nedensellik (causation) ilişkisini keşfetmeye çalışır.

Bir yanıt değişkeni ile bir dizi açıklayıcı değişken arasındaki ilişkiyi modellemek, bütün istatistiksel tekniklerin en yaygın kullanılanlarındandır. Bu tür modellemeye regresyon analizi denir; hoca bunun yapay zekâ ve makine öğrenmesinde de en temel kavramlardan biri olduğunu söyledi.

Regresyon modeli, yanıt değişkeni ile açıklayıcı değişkenler arasında fonksiyonel bir ilişki sağlar; bu ilişki, hangi açıklayıcı değişkenlerin yanıt üzerinde etkisi olduğunu belirlemeye izin verir. Hoca bunun basit bir birliktelik değil, bir neden-sonuç etkisi olduğunu vurguladı. Model, açıklayıcı değişkenlerde belirli değişiklikler olduğunda yanıt değişkenine ne olacağını keşfetmeye de olanak tanır.

Slayttaki tanım (ekrandan, 02:20:00): regresyon analizinin temel fikri, bir **yanıt değişkeni** (çoğu zaman **bağımlı değişken** denir) ile bir ya da daha fazla **açıklayıcı değişken** (çoğu zaman **bağımsız değişkenler** denir) arasındaki fonksiyonel ilişki için bir model elde etmektir.

### 10.2 Regresyon modellerinin kullanımları

- Model, veri kümesinin temel özelliklerinin bir betimlemesini sağlar.
- Regresyon analizinden çıkan, yanıt değişkenini açıklayıcı değişkenlere bağlayan denklem, çalışmada gözlenmemiş açıklayıcı değişken değerleri için yanıt değişkeninin kestirimlerini verir. Hoca bunu "geleceği tahmin etmek" diye özetledi: gerçek bir çalışmada birkaç gerçek ölçüm ve kayıt vardır; bu kayıtlarla bir regresyon modeli kurulur ve model, çalışmaya dahil edilmemiş düzeyler için tahmin üretir.
- İş dünyasından örnek: bir ürünün gelecekteki satışlarını tahmin etmek, üretim planlaması için çok önemlidir. Veri, şimdiki satışları önceki aylardaki satışlara iyi uyduran bir model sağlıyorsa bu model gelecek satışları tahmin etmekte kullanılabilir.

### 10.3 Basit doğrusal regresyon

Basit bir regresyon modeli şu ilişki denklemiyle verilir:

$$y = \alpha + \beta x + \varepsilon$$

- $\alpha$: kesişim (intercept),
- $\beta$: regresyon doğrusunun eğimi; açıklayıcı değişkene ait **regresyon katsayısı** da denir,
- $\varepsilon$: hata terimi.

<!-- BELİRSİZ: Regresyon denkleminin slayttaki yazımı karede görülmedi; terimler sözlü anlatımdan alındı. -->

Regresyon parametrelerini bulma işlemine **regresyon modelini veriye uydurma** (fitting) denir.

### 10.4 Neden denetimli öğrenme?

Slayta göre (ekrandan, 02:25:00) doğrusal regresyon modelleri, yanıt değişkeninin bilinmeyen değerlerini tahmin etmek için kullanılır. Bu modellerde yanıt değişkeninin merkezi bir rolü vardır: model kurma süreci, yanıt değişkenindeki değişimi açıklamaya ya da değerlerini tahmin etmeye yöneliktir. Bu nedenle regresyon modelleri kurmak **denetimli öğrenme** (supervised learning) olarak bilinir. Hocanın gerekçesi: modeli kurmak için önceki (yanıtı bilinen) veriler kullanılır, bu yüzden öğrenme denetimlidir.

## 11. Denetimsiz Öğrenme ve Kümeleme

### 11.1 Denetimsiz öğrenme

Verinin altta yatan yapısını belirlemek için istatistiksel modeller kurmaya **denetimsiz öğrenme** denir. Denetimsiz öğrenmenin önemli bir sınıfı **kümelemedir**; hoca, denetimsiz öğrenme denince akla ilk gelen yöntemin kümeleme olduğunu söyledi.

Kümeleme, bir popülasyon içindeki alt grupları belirlemek için kullanılır. Genel olarak küme analizi, veriyi alt gruplara bölmeye çalışan yöntemleri anlatır; öyle ki aynı gruptaki gözlemler, farklı gruplardaki gözlemlere göre birbirine daha çok benzer.

### 11.2 Uzaklık, benzerlik ve benzemezlik

Kümelemede metrik olarak genellikle uzaklık kullanılır. Uzaklık ölçüsü her küme analizinin temel kavramıdır. Hoca, uzaklığın bir benzerlikten çok bir benzemezlik (dissimilarity) ölçüsü olduğunu belirtti.

<!-- BELİRSİZ: 02:26-02:27 arasında kategorik değişkenler için uzaklık anlatımı altyazıda bozuk. -->

Sayısal değişkenler için uzaklıklar tanımlanır. Örneğin kare uzaklık sayısal değişkenlerle kullanılan bir uzaklık metriğidir: $d_{ij}$, $i$ ve $j$ gözlemleri arasındaki uzaklıktır; $x_i$ rastgele değişken $x$'in $i$. gözlemdeki değeri, $x_j$ ise $j$. gözlemdeki değeridir.

$$d_{ij} = (x_i - x_j)^2$$

Benzerlik ve benzemezlik birbiriyle ilişkili ve kolayca karıştırılan iki kavramdır:

- **Benzerlik**, iki veri nesnesinin ne kadar benzediğinin sayısal ölçüsüdür; nesneler daha çok benzedikçe büyür. Genellikle 0 ile 1 arasındadır.
- **Benzemezlik**, nesneler farklılaştıkça büyür; üst sınırı yoktur, sonsuz olabilir. Benzemezlik genellikle uzaklık cinsinden ölçülür.
- **Yakınlık** (proximity) benzerlik ya da benzemezliği anlatır; ikisini kapsayan şemsiye kavramdır.

### 11.3 Öklid ve Minkowski uzaklıkları

Hoca birkaç uzaklık türü olduğunu söyledi. İlki çok yaygın olan **Öklid uzaklığıdır**: kare farkların toplamının karekökü.

$$d(\mathbf{x}, \mathbf{y}) = \sqrt{\sum_{k=1}^{p}(x_k - y_k)^2}$$

**Minkowski uzaklığı**, parametresinin değerine göre farklı adlar alır (ekrandan, 02:30:00):

- $r = 1$: şehir bloğu (Manhattan, taksi, L1 normu) uzaklığı,
- $r = 2$: Öklid uzaklığı,
- $r \to \infty$: supremum uzaklığı.

$$d(\mathbf{x}, \mathbf{y}) = \left(\sum_{k=1}^{p}|x_k - y_k|^{r}\right)^{1/r}$$

<!-- BELİRSİZ: Öklid ve Minkowski formüllerinin slayttaki yazımı karede görülmedi; yukarıdakiler standart biçimdir. -->

Genel olarak $p$ rastgele değişken $x_1, \ldots, x_p$ ölçülürse, örneklemdeki $i$ ve $j$ gözlemleri arasındaki kare uzaklık bütün değişkenlerdeki kare farkların toplamıdır:

$$d_{ij}^2 = \sum_{k=1}^{p}(x_{ik} - x_{jk})^2$$

Bu benzemezlik ölçüsüne **kare Öklid uzaklığı** denir.

### 11.4 K-ortalamalar kümelemesi

**K-ortalamalar** (k-means) kümelemesi, benzemezlik ölçüsü olarak kare Öklid uzaklığını kullanan basit bir algoritmadır. Gözlemler rastgele $k$ gruba bölünüp her kümenin merkezi bulunduktan sonra algoritma, aşağıdaki adımları yineleyerek en iyi kümeleri bulur:

```text
1. Her gözlem için k merkezin her birine kare Öklid uzaklığını bul;
   gözlemi uzaklığı en küçük olan kümeye ata.
2. Bütün gözlemler k kümeye yeniden dağıtıldıktan sonra
   k merkezi yeniden hesapla.
3. Kümeler değişmeyene kadar 1. ve 2. adımları tekrarla.
```

### 11.5 Hiyerarşik kümeleme

K-ortalamalar kümelemesinin bazı sorunları vardır; alternatif olarak **hiyerarşik kümeleme** kullanılabilir. Hoca, hiyerarşik kümelemeyi filogenetik ağaçlar konusunda zaten işlediklerini, bu yüzden hızlı geçeceğini söyledi. İki yaklaşım vardır:

- **Bölücü** (divisive): bütün veriyle başlayıp grupları bölerek ilerler.
- **Birleştirici** (agglomerative): tek tek gözlemlerle başlayıp en yakın grupları birleştirerek ilerler.

Hoca, filogenetik ağaçlarda farklı bir adla karşılaşılan UPGMA'nın da bu yöntemlerden olduğunu hatırlattı ve kümelerin oluşturulmasında kullanılan farklı yöntemleri gösteren bir şekille konuyu kapattı.

<!-- BELİRSİZ: 02:34 civarında sayılan bağlantı (linkage) yöntemlerinin adları altyazıda bozuk ("klasitlik", "censiyonluik"); büyük olasılıkla tek, tam ve ortalama bağlantı gibi yöntemler kastediliyor, slayt karede görülmedi. -->

## 12. Örnek Sorular

Derste ekranda quiz ya da alıştırma gösterilmedi. Aşağıdaki sorular hocanın derste sözlü olarak sınıfa sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:33:56): Merkezi eğilim ölçüleri nelerdir?

> **Cevap (derste verildi, ekrandan 00:40:00):** Örneklem ortalaması, örneklem medyanı ve örneklem modu. Hoca üçünün de merkezi eğilimi temsil etmek için kullanıldığını söyledi.

**Soru 2** (derste sözlü, 00:39:19): $n$ örneğin merkezi eğilimini bir makine öğrenmesi algoritmasında öznitelik olarak kullanmak istiyoruz. Hangi ölçüyü seçeceğimize nasıl karar veririz?

> **Cevap (derste verildi):** Başkalarının kullandığını körü körüne seçmek yerine verinin dağılımına, yani histogramın biçimine bakılır. Dağılım simetrikse aritmetik ortalama; çarpıksa medyan ya da (veriye göre) geometrik veya harmonik ortalama seçilir.

**Soru 3** (derste sözlü, 00:51:53): Aritmetik, geometrik ve harmonik ortalama hangi koşulda birbirine eşit olur?

> **Cevap (derste verildi):** Bütün değerler eşitse üç ortalama da eşit olur. Diğer bütün durumlarda $HM \le GM \le AM$ eşitsizliği kesin olarak sağlanır ($HM < GM < AM$).

**Soru 4** (derste sözlü, 00:57:00): Medyan, merkezi eğilimi temsil etmek için ne zaman kullanılır?

> **Cevap (derste verildi):** Veri simetrik olmadığında, yani çarpık dağılımlarda. Medyan, ortalamaya göre aykırı değerlerden daha az etkilenir.

**Soru 5** (derste sözlü, 02:14:17): Birinci ve ikinci tip hataların birden çok sınıfa genişletilmiş tablosuna makine öğrenmesinde ve veri madenciliğinde ne ad verilir?

> **Çözüm (derste verilmedi):** <!-- BELİRSİZ: Derste verilen cevap altyazıda "ModTable" diye bozuk. --> Büyük olasılıkla **karışıklık matrisi** (confusion matrix) kastediliyor: satırlarda gerçek sınıflar, sütunlarda tahmin edilen sınıflar bulunur; iki sınıflı durumda yanlış pozitifler birinci tip, yanlış negatifler ikinci tip hataya karşılık gelir.

## 13. Dersin Toparlaması

Bu derste biyoenformatikte sık kullanılan istatistiksel veri analizi kavramları toplu olarak hatırlatıldı. Önce veri türleri ve özetleme ele alındı: kategorik veri frekans ve göreli frekansla, sayısal veri histogramla özetlendi; histogramın biçimi (simetrik, çarpık, tek ya da çok tepeli) uygun betimsel istatistiği seçmenin anahtarı olarak sunuldu. Merkezi eğilim için aritmetik, geometrik, harmonik, ağırlıklı ve kuvvet ortalamaları, medyan ve mod; yayılım için varyans, standart sapma, kantiller, beş sayı özeti, IQR, kutu grafikleri ve değişim katsayısı işlendi. Ardından ölçekleme, kaydırma ve standartlaştırma dönüşümleri, değişkenler arasındaki ilişkileri ölçen Pearson korelasyonu, çapraz korelasyon, kovaryans, olumsallık tabloları ve odds oranı anlatıldı.

Dersin ikinci yarısı olasılık ve çıkarıma ayrıldı: olasılığın belirsizliğin ölçüsü olarak tanımı, toplama kuralı, bağımsızlık, Bayes kuralı, Gauss ve Poisson dağılımları, nokta ve aralık kestirimi, sıfır ve alternatif hipotezler, hata türleri ve test istatistiği. Son olarak regresyonun denetimli öğrenme, kümelemenin denetimsiz öğrenme olarak yeri gösterildi; Öklid ve Minkowski uzaklıkları, k-ortalamalar ve hiyerarşik kümeleme (filogenetik ağaçlardaki UPGMA ile bağlantısıyla) özetlendi. Hoca dersin sonunda ortalama ve medyan kavramlarının uygulaması olarak hareketli ortalama (moving average) ve hareketli medyan (moving median) filtrelerini bir sonraki derste anlatacağını, bu pencere kavramını daha önce dot plot'taki gürültüyü gidermek için kullandıklarını hatırlattı; ardından görselleştirme konusuna geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
