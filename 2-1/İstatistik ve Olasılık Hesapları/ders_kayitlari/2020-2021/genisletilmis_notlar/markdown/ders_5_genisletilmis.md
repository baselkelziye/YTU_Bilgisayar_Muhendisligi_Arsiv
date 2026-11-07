# Ders 5 Genişletilmiş Notu: Kesikli Rastgele Değişkenler, PMF ve CDF, Beklenen Değer, Varyans, Kovaryans ve Korelasyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Rastgele Değişken
- 2. PMF ve CDF
- 3. PMF ile CDF Arasında Dönüşüm ve Temel Özellikler
- 4. PMF ve CDF Grafikleri
- 5. Rastgele Vektörler, Birleşik ve Marjinal Dağılım
- 6. Rastgele Değişkenlerin Bağımsızlığı
- 7. Beklenen Değer
- 8. Varyans ve Standart Sapma
- 9. Kovaryans
- 10. Varyans ve Kovaryansın Türkçe Tekrarı
- 11. Korelasyon
- 12. Varyans, Kovaryans ve Korelasyonun Özellikleri

## 1. Rastgele Değişken

Hoca derse kesikli rastgele değişkenleri (discrete random variables) tanıtarak başladı. Rastgele değişken (random variable), bir deneyin çıktısının (outcome) fonksiyonudur ve genellikle büyük harfle yazılır. Yani adında "değişken" geçse de aslında bir fonksiyondur: Deneyin çıktısını alır, sonuç olarak bir değer verir.

> **Hocanın vurgusu:** Bu fonksiyonun sonucu mutlaka sayısal bir değerdir. "Yağmur" ya da "tura" gibi bir şey olamaz; bir sayı olmak zorundadır.

### 1.1 İki Madeni Para Örneği

Hocanın örneği şudur: İki adil madeni para atılıyor ve tura (heads) sayısıyla ilgileniyoruz. Rastgele değişken $X$, tura sayısıdır. Her para tura (H) ya da yazı (T) gelebildiği için örnek uzayda dört çıktı vardır:

$$S = \{HH,\ HT,\ TT,\ TH\}$$

Bu rastgele değişkenin alabileceği değerlerin kümesine $X$'in değer kümesi (range of $X$) denir ve $R_X$ ile gösterilir. $R_X$'i bulmak için çıktılara tek tek bakılır:

- $TT$ çıktısında hiç tura yoktur, dolayısıyla 0 yazılır.
- $HT$ çıktısında bir tura vardır, dolayısıyla 1 yazılır.
- $TH$ çıktısında da bir tura vardır. 1 zaten yazıldığı için tekrar edilmez, çünkü burada yalnızca olası değerler listelenir.
- $HH$ çıktısında iki tura vardır, dolayısıyla 2 yazılır.

Sonuç olarak rastgele değişken yalnızca 0, 1 ve 2 değerlerini alabilir:

$$R_X = \{0,\ 1,\ 2\}$$

Hoca sonradan, $R_X$'e bazen $X$'in **desteği (support)**, bazen de **değer kümesi (range)** dendiğini, ikisinin de kullanıldığını ekledi.

## 2. PMF ve CDF

Rastgele değişkenleri tanımladıktan sonra sıra dağılımlarına gelir. Bunun için iki fonksiyon kullanılır.

### 2.1 Olasılık Kütle Fonksiyonu (PMF)

Olasılık kütle fonksiyonu (probability mass function, PMF), rastgele değişkenin olası bir değerini alıp o değerin olasılığını veren fonksiyondur:

$$p_X(x) = P(X = x)$$

Burada $P(X = x)$, "$X$ rastgele değişkeninin küçük $x$ değerini alması olayının olasılığı" demektir. Bu derste kısaca PMF denecektir.

### 2.2 Birikimli Dağılım Fonksiyonu (CDF)

PMF'e benzeyen ikinci olasılık ölçüsü birikimli dağılım fonksiyonudur (cumulative distribution function, CDF). Genellikle büyük $F$ ile yazılır:

$$F_X(x) = P(X \le x)$$

Yani rastgele değişkenin küçük $x$ değerini ya da ondan daha küçük bir değeri alma olasılığıdır. Bu da kısaca CDF diye anılır.

> **Ders sonrası not:** Altyazıda CDF tanımı bir yerde "less than or greater" (küçük ya da büyük) diye geçiyor. Doğrusu "küçük ya da eşit"tir: $F_X(x) = P(X \le x)$. Hoca aynı ifadeyi örnekte söylerken kendisi de "less than or equal" diye düzeltti.

> **Hocanın vurgusu:** Bazen yalnızca "dağılım" (distribution) kelimesini duyarsınız. Dağılımdan söz edildiğinde bu iki şeyden biri kastedilir. "Dağılımı bulun" denirse PMF'i ya da CDF'i bulmanız gerekir.

### 2.3 Örnek: İki Paranın PMF'i

PMF, olası bütün değerler için olasılık vermelidir. Yazmanın farklı yolları vardır; önemli olan fonksiyonu bir şekilde tanımlamaktır. Bazen tablo verilir, bazen bir denklem.

Örnek uzayda dört eşit olasılıklı eleman vardır.

- **$X = 0$:** Sıfır tura içeren tek çıktı $TT$'dir, dolayısıyla $P(X = 0) = 1/4$.
- **$X = 1$:** Bir tura içeren iki çıktı vardır ($HT$ ve $TH$), dolayısıyla $P(X = 1) = 2/4$.
- **$X = 2$:** Yalnızca $HH$ iki tura içerir, dolayısıyla $P(X = 2) = 1/4$.

Aynı bilgi tablo olarak şöyle yazılır:

| $x$ | 0 | 1 | 2 |
| :---: | :---: | :---: | :---: |
| $P(X = x)$ | 1/4 | 2/4 | 1/4 |

### 2.4 Örnek: İki Paranın CDF'i

CDF'in tanımına göre, bir değerin birikimli olasılığı o değerin ve ondan küçük değerlerin olasılıklarının toplamıdır. Yine yalnızca 0, 1 ve 2 değerlerine bakılır.

- **$F(0)$:** $P(X \le 0)$ için yalnızca 0 sayılır: $F(0) = 1/4$.
- **$F(1)$:** $P(X \le 1)$ için 1'in olasılığına, ondan küçük olan 0'ın olasılığı da eklenir: $F(1) = 1/4 + 2/4 = 3/4$.
- **$F(2)$:** $P(X \le 2)$ için üç değerin hepsi sayılır: $F(2) = 1/4 + 2/4 + 1/4 = 4/4 = 1$.

Hesaplar python ile hesaplandı; aynı sonuçları verdi.

## 3. PMF ile CDF Arasında Dönüşüm ve Temel Özellikler

Dağılımdan söz ederken birikimli dağılım da PMF de kastedilebilir, çünkü biri diğerine dönüştürülebilir. CDF değerleri biliniyorsa PMF, PMF değerleri biliniyorsa CDF elde edilir.

PMF'ten CDF'e geçmek doğrudan tanımdan gelir. Değişkenin $x$'ten küçük ya da ona eşit $y$ değerleri üzerinden olasılıklar toplanır:

$$F_X(x) = \sum_{y \le x} p_X(y)$$

Ters yönde, $X$'in $a$ ile $b$ arasında olma olasılığı iki birikimli değerin farkıyla verilir. Böylece birikimli olasılıklardan normal olasılıklar elde edilir:

$$P(a < X \le b) = F(b) - F(a)$$

> **Ders sonrası not:** Hoca bunu "$X$'in $a$ ile $b$ arasında olması" diye söyledi. Kesin ifade yukarıdaki gibidir: $F(b)$, $b$ dahil olmak üzere $b$'ye kadar olan olasılıkları toplar, $F(a)$ da $a$ dahil $a$'ya kadar olanları çıkarır. Dolayısıyla sol uç $a$ dahil değildir, sağ uç $b$ dahildir.

Hoca bu fonksiyonların iki temel özelliğini verdi. Birincisi, bütün değerlerin olasılıkları toplanırsa 1 elde edilir:

$$\sum_x p_X(x) = 1$$

İkincisi, $x$ eksi sonsuza giderken birikimli dağılım 0'a, artı sonsuza giderken 1'e gider:

$$\lim_{x \to -\infty} F_X(x) = 0, \qquad \lim_{x \to +\infty} F_X(x) = 1$$

Hoca bu limitleri söylerken iki kez sürçtü ve kendisi düzeltti; doğru hâl yukarıdaki gibidir.

## 4. PMF ve CDF Grafikleri

### 4.1 PMF Grafiği

İki para örneğinde yatay eksende 0, 1 ve 2 değerleri, dikey eksende olasılık vardır. 0'da yükseklik $1/4$, 1'de $2/4$, 2'de yine $1/4$'tür.

PMF olasılıkları yalnızca bu noktalarda tanımlıdır. Her yerde başka bir değer yoktur: Örneğin $P(X = 0.5)$ sıfırdır. Hoca bu grafiklerde olasılığın o noktalarda "sıçradığını" (jump) gösterdi. $P(X = 1)$ değeri $2/4$'tür, onun dışındaki yerlerde olasılık sıfırdır. Eksen adları bazen $x$ ve $p_X(x)$ olarak yazılır.

<!-- BELİRSİZ: Hocanın PMF grafiğinde noktalardaki sıçramayı göstermek için tam olarak ne çizdiği altyazıda net değil ("we may delete the series"). -->

Hoca gösterim hakkında da bir not düştü. Dikkatli olmak istiyorsanız $p_X$ gibi alt indisi yazarsınız. Hızlı çalışırken ve problemde tek rastgele değişken varken alt indis yazılmayabilir, çünkü karışıklık olmaz.

### 4.2 CDF Grafiği

CDF grafiğinde yatay eksende $x$, dikey eksende birikimli olasılık vardır. Grafik soldan sağa şöyle okunur:

1. $x \to -\infty$ iken birikimli olasılık 0'dır ve 0'a kadar 0 kalır.
2. $x = 0$'da grafik $1/4$'e sıçrar ve $x = 1$'e kadar $1/4$'te kalır.
3. $x = 1$'de $2/4$'lük olasılık da eklenir, grafik $3/4$'e sıçrar ve $x = 2$'ye kadar $3/4$'te kalır.
4. $x = 2$'de son $1/4$ eklenir, grafik 1'e sıçrar ve bundan sonra sonsuza kadar 1'de kalır.

Bu anlatım fonksiyon olarak şöyle yazılır (ara adım eklendi):

$$
F(x) =
\begin{cases}
0, & x < 0 \\
1/4, & 0 \le x < 1 \\
3/4, & 1 \le x < 2 \\
1, & x \ge 2
\end{cases}
$$

Son satır, "$x$ sonsuza giderken birikimli olasılık 1'e gider" sözünün bu örnekteki karşılığıdır.

> **Hocanın vurgusu:** Birikimli olasılıklar ilk elemandan sonra sıfırdan farklıdır. Örneğin $F(0.5) = 1/4$'tür, sıfır değildir. Oysa olasılık kütle fonksiyonunda $0.5$'in olasılığı sıfırdır.

**Soru:** Limit eksi sonsuza giderken CDF neden sıfır oldu? Eksi değerlerde de olasılıklar olsa daha büyük bir şey çıkamaz mı, eksi değer koyamıyor muyuz?

**Cevap:** Koyabiliyoruz. Bu örnek problem için eksi sonsuza en yakın değerimiz sıfırdır.

<!-- BELİRSİZ: Cevabın devamı (yaklaşık 00:36:30-00:38:24) altyazıda bozuk ve döngülü. Yalnızca "Continuous Distributions" ifadesi seçilebiliyor; sürekli dağılımlara değinilmiş olabilir. -->

> **Ek bilgi (derste anlatılmadı):** Rastgele değişken negatif değerler alabilse de limit kuralı değişmez. $F$ soldan sağa olasılık biriktirir, bu yüzden $x$ bütün olası değerlerin solunda kaldığında $P(X \le x)$ toplamında hiçbir değer kalmaz. Sıfır olan yalnızca $x$, en küçük değerin solundayken $F$'in değeridir; o en küçük değerin kendisinin 0 olması gerekmez.

## 5. Rastgele Vektörler, Birleşik ve Marjinal Dağılım

Şimdi birden fazla rastgele değişkenin olasılık dağılımlarına geçilir. Bunlara bazen rastgele vektör (random vector) denir. Rastgele değişkene benzerler, ama tek bir $X$ yerine yanında $Y$ gibi başka bir rastgele değişken, belki $Z$ de vardır. Hoca iki bileşenli bir vektör yazdı, ama üç, beş ya da daha fazla bileşen de olabilir. Rastgele vektörün her bileşeni bir rastgele değişkendir.

Rastgele vektörlerin olasılık dağılımına **birleşik dağılım (joint distribution)** denir. Rastgele vektör varken yalnızca bir değişkenin dağılımından söz ediliyorsa buna **marjinal dağılım (marginal distribution)** denir. Hoca bu ayrımı Türkçe de tekrarladı: Problemde birden fazla rastgele değişken yoksa doğrudan "dağılım" dersiniz. Birden fazla rastgele değişken varsa, onlardan birinin dağılımına marjinal dağılım denir.

### 5.1 Birleşik Olasılık

Rastgele vektörün her değeri için bir olasılıktan söz edilebilir:

$$p_{X,Y}(x, y) = P(X = x \cap Y = y)$$

Bu ifade, "$X$ rastgele değişkeninin küçük $x$ değerini **ve** $Y$ rastgele değişkeninin küçük $y$ değerini alması" olayının olasılığıdır. Birleşik olasılıklar da toplanınca 1 verir:

$$\sum_x \sum_y p_{X,Y}(x, y) = 1$$

### 5.2 Birleşik Olasılıktan Marjinal Olasılığa

Birleşik olasılıklar biliniyorsa marjinal olasılıklar hesaplanabilir. Fikir, diğer bütün rastgele değişkenler üzerinden toplamaktır. Örneğin $P(X = x)$ isteniyorsa, $Y$'nin bütün olası değerleri üzerinden birleşik olasılıklar toplanır. $Y$'nin marjinali için de $X$'in bütün olası değerleri üzerinden toplanır:

$$p_X(x) = \sum_y p_{X,Y}(x, y), \qquad p_Y(y) = \sum_x p_{X,Y}(x, y)$$

Buradaki alt indisler, hangi rastgele değişkenin hangi değeri aldığını gösterir. Her şey açıksa yazılmayabilir, matematiksel olarak daha dikkatli olmak istiyorsanız yazarsınız.

## 6. Rastgele Değişkenlerin Bağımsızlığı

Birden fazla rastgele değişken konuşulduğu için bağımsızlıkları da tanımlanır. İki rastgele değişken $X$ ve $Y$, birleşik olasılıkları marjinal olasılıklarının çarpımına eşitse bağımsızdır:

$$p_{X,Y}(x, y) = p_X(x)\, p_Y(y) \quad \text{(tüm } x, y \text{ için)}$$

Hoca birleşik olasılıklara burada ara verdiğini, bir örnek üzerinde bu konuya döneceğini söyledi.

## 7. Beklenen Değer

### 7.1 Tanım

Beklenen değer (expectation, expected value), rastgele değişkenin ortalaması (mean) ya da ortalama değeridir (average value). $E[X]$ biçiminde yazılır; buradaki $E$ "expectation" demektir ve $X$ rastgele değişkendir. Bazen de ortalama anlamında, m harfine yakın olan $\mu$ (mü) harfiyle yazılır. $\mu_X$, $X$'in ortalaması demektir.

Hesaplamak için rastgele değişkenin bütün olası değerleri olasılıklarıyla çarpılıp toplanır:

$$\mu = E[X] = \sum_x x\, p(x)$$

> **Ders sonrası not:** Hoca beklenen değerin "ne tür bir değerin en olası olduğu" fikrini verdiğini söyledi. Bu doğru değil: Beklenen değer ağırlıklı ortalamadır, en olası değer değildir. Aşağıdaki örnekte en olası değer 2, beklenen değer $2.25$'tir (python ile hesaplandı). Kısa notta en olası değerin mod (mode) olduğu belirtilir.

### 7.2 Örnek

Hoca önce 0 ve 1 değerlerini yazdı, sonra örneği biraz farklılaştırmak için değerleri 2 ve 3 yaptı. Rastgele değişken $X$ yalnızca iki değer alıyor:

| $x$ | 2 | 3 |
| :---: | :---: | :---: |
| $P(X = x)$ | 0.75 | 0.25 |

Beklenen değer, tanımdaki toplamla bulunur:

$$E[X] = 2 \cdot 0.75 + 3 \cdot 0.25 = 1.5 + 0.75 = 2.25$$

Sonuç python ile hesaplandı. Burada dikkat çekici bir şey vardır: $X$ hiçbir zaman $2.25$ değerini almaz, çünkü yalnızca 2 ya da 3 çıkabilir. Peki $2.25$ ne demektir? Hocanın verdiği yorum şudur: İki ya da üç veren bu deneyi milyonlarca kez tekrarlayıp sonuçları toplar ve deney sayısına bölerseniz, $2.25$'e çok yakın bir değer elde edersiniz.

### 7.3 Bir Fonksiyonun Beklenen Değeri

Bazen rastgele değişkenin kendisi yerine bir fonksiyonuyla ilgileniriz. $g(X)$, $X$'in verdiği sonucun üzerinde bir işlem yapıp döndüren fonksiyondur. Formül öncekine çok benzer, yalnızca $x$ yerine $g(x)$ gelir:

$$E[g(X)] = \sum_x g(x)\, p(x)$$

### 7.4 Beklenen Değerin Özellikleri

Hoca dört özellik verdi. Burada $a$ ve $c$ sabittir, $X$ ve $Y$ rastgele değişkendir.

- Sabitin beklenen değeri kendisidir: $E[c] = c$. Örneğin $E[5] = 5$.
- Sabit dışarı çıkar: $E[aX] = a\,E[X]$.
- Toplam ayrılır: $E[X + Y] = E[X] + E[Y]$.
- **Eğer $X$ ile $Y$ bağımsızsa** $E[XY] = E[X]\,E[Y]$.

> **Hocanın vurgusu:** Son özellikte bir "eğer" vardır. $X$ ve $Y$ bağımsız değilse bunu yazamazsınız.

Bu özellikler birleştirilerek $E[aX + bY + c]$ hesaplanabilir. Burada $a$, $b$, $c$ sabit, $X$ ve $Y$ rastgele değişkendir. Önce toplamlar ayrılır, sonra sabitler dışarı alınır, en sonda sabitin beklenen değerinin kendisi olduğu kullanılır:

$$E[aX + bY + c] = E[aX] + E[bY] + E[c] = a\,E[X] + b\,E[Y] + c$$

> **Hocanın vurgusu:** Bu özellikler çok işe yarar, bilmeniz gerekir. Derste vakit ayrılmadı, evde kendiniz ispatlayın.

> **Ek bilgi (derste anlatılmadı):** Bağımsızlık özelliğinin kısa gerekçesi, birleşik olasılığın çarpıma ayrılmasıdır: $E[XY] = \sum_x \sum_y xy\, p_{X,Y}(x,y) = \sum_x \sum_y xy\, p_X(x)\, p_Y(y) = \sum_x x\, p_X(x) \sum_y y\, p_Y(y) = E[X]\,E[Y]$. Özdeşlik python ile bir bağımsız dağılım üzerinde sınandı.

## 8. Varyans ve Standart Sapma

### 8.1 Sezgi

Beklenen değer, ne tür bir merkezi nokta beklediğimizi gösterir. Varyans (variance) ise değerlerin ne kadar farklı olabileceğini gösterir.

Hoca önce iki rastgele değişken aldı: $X_1$'in değer kümesi $\{1, 2\}$, $X_2$'nin değer kümesi $\{1000, 2000\}$. Değerler daha çok değiştiği için $X_2$'nin varyansı daha yüksektir. Sonra örneği iyileştirdi ve değerleri şöyle değiştirdi:

$$R_{X_1} = \{-2,\ 2\}, \qquad R_{X_2} = \{-2000,\ 2000\}$$

Olasılıklar da aynı olsun: $P(X_1 = -2) = P(X_1 = 2) = 1/2$ ve $P(X_2 = -2000) = P(X_2 = 2000) = 1/2$. Bu durumda ikisinin de ortalaması sıfırdır, yani beklenen değerler aynıdır. Yine de $X_2$'nin değerleri çok daha geniş bir aralığa yayıldığı için varyansı daha yüksektir. Varyansı yükselten şey budur.

### 8.2 Tanım

Varyans $\sigma^2$ ya da $\mathrm{Var}(X)$ ile yazılır. Matematiksel olarak, $X$'in beklenen değerinden farkının karesinin beklenen değeridir:

$$\sigma_X^2 = \mathrm{Var}(X) = E\big[(X - E[X])^2\big] = \sum_x (x - \mu)^2\, p(x)$$

Yani her değerden ortalama çıkarılır, karesi alınır, olasılıkla çarpılır ve toplanır.

Standart sapma (standard deviation), varyansın karekökünden ibarettir. $\sigma$ ya da $\mathrm{std}(X)$ ile yazılır:

$$\sigma_X = \mathrm{std}(X) = \sqrt{\mathrm{Var}(X)}$$

Standart sapmanın birimi problemin birimiyle aynıdır, bu yüzden yorumlaması ve anlaması daha kolaydır.

### 8.3 Alternatif Formül

Varyans için başka bir denklem daha vardır:

$$\mathrm{Var}(X) = E[X^2] - \mu^2$$

> **Hocanın vurgusu:** Bunu önceki denklemden elde edebilirsiniz, evde kendiniz ispatlayın. Zor değildir; kitapta ya da internette de bulunur, ama internete bakmadan önce kendiniz deneyin.

> **Ek bilgi (derste anlatılmadı):** İspatı denedikten sonra kontrol etmek için: Kareyi açıp beklenen değerin özelliklerini kullanınca $E[(X-\mu)^2] = E[X^2] - 2\mu E[X] + \mu^2 = E[X^2] - \mu^2$ olur. Aynı yol kovaryansta da işler: $E[(X-\mu_X)(Y-\mu_Y)] = E[XY] - \mu_X E[Y] - \mu_Y E[X] + \mu_X\mu_Y = E[XY] - \mu_X\mu_Y$. İki özdeşlik de python ile rastgele dağılımlar üzerinde sınandı.

## 9. Kovaryans

Beklenen değer ve varyans tek değişken içindir. Rastgele vektörler varken, yani en az iki rastgele değişken olduğunda, bu değişkenlerin birlikte nasıl değiştiği düşünülebilir. Bunu kovaryans (covariance) ölçer. $\sigma_{XY}$ ya da $\mathrm{Cov}(X, Y)$ ile yazılır ve bir beklenen değer olarak tanımlanır:

$$\sigma_{XY} = \mathrm{Cov}(X, Y) = E\big[(X - \mu_X)(Y - \mu_Y)\big]$$

Yani $X$'ten kendi ortalaması, $Y$'den kendi ortalaması çıkarılır ve bu farklar çarpılır. Bunun için de alternatif bir denklem vardır:

$$\mathrm{Cov}(X, Y) = E[XY] - \mu_X \mu_Y$$

> **Hocanın vurgusu:** Bunu da evde ispatlayın, zor olmaması gerekir.

### 9.1 Kovaryansın Yorumu

Hoca yatay ekseni $X$, dikey ekseni $Y$ olan grafikler üzerinde veri noktalarını çizip üç durumu gösterdi.

- **Pozitif kovaryans:** $X$ artarken $Y$ de artar. Hoca bunu "pozitif ya da yüksek kovaryans" diye adlandırdı.
- **Negatif kovaryans:** $X$ artarken $Y$ azalır. Noktalara bir doğru oturtulursa doğru aşağı iner. Hoca bunu "yüksek negatif kovaryans" diye niteledi. Burada değişkenler ilişkisiz değildir, ters yönde birlikte değişirler (inversely covariant).
- **Sıfır kovaryans:** $X$ değişirken $Y$ değerleri pek değişmez. Birlikte değişmezler. Bu durumda ilişkisiz (uncorrelated) oldukları ya da kovaryanslarının sıfır olduğu söylenir.

Kovaryans, iki değişkenin birlikte nasıl değiştiğini söyler: $X$ artarken $Y$ de aynı anda artıyor mu?

> **Ders sonrası not:** Hoca üçüncü durum için "bağımsız değişiyorlar, dolayısıyla kovaryant değiller" dedi. Burada ters yön geçerli değildir: Bağımsızlık sıfır kovaryansı gerektirir (Bölüm 12), ama sıfır kovaryans bağımsızlığı gerektirmez. Kısa nottaki örnek: $X \in \{-1, 0, 1\}$ eşit olasılıklı ve $Y = X^2$ ise $\mathrm{Cov}(X, Y) = 0$ çıkar, ama $Y$ tamamen $X$'e bağlıdır. Örneğin $P(X = 0, Y = 0) = 1/3$ iken $P(X = 0)\,P(Y = 0) = 1/9$ olur (python ile hesaplandı).

## 10. Varyans ve Kovaryansın Türkçe Tekrarı

**Soru:** Varyans ve sonrasındaki bölüm (tanımlar ve formüller: varyans, kovaryans, korelasyon) kısaca Türkçe olarak tekrar anlatılabilir mi?

**Cevap:** Hoca varyans ve kovaryansı Türkçe olarak yeniden anlattı. Bu bölümde altyazı yer yer bozuktur; aşağıda yalnızca anlaşılan kısımlar yer alır.

### 10.1 Varyans ve Sayısal Örnek

Varyans, rastgele değişkenin aldığı değerlerin ne kadar değiştiğini, ne kadar dalgalı olduğunu gösterir. Matematiksel olarak, değerlerin ortalamadan farkının karelerinin beklenen değeridir. Her değerin ortalamadan ne kadar farklı olduğu bulunur, negatif değerler olmasın diye karesi alınır, sonra bunun ortalaması alınır.

Hoca Bölüm 8'deki örneği sayısal olarak çözdü.

**Verilen:** $X_1$, $-2$ ve $2$ değerlerini $1/2$ olasılıkla alıyor. $X_2$, $-2000$ ve $2000$ değerlerini $1/2$ olasılıkla alıyor.

**$X_1$ için ortalama:**

$$\mu_{X_1} = (-2) \cdot \tfrac{1}{2} + 2 \cdot \tfrac{1}{2} = 0$$

**$X_1$ için varyans:** Varyans, $(X_1 - 0)^2$'nin beklenen değeridir. Hoca bunu bir $g(X)$ gibi düşünmemizi söyledi; fonksiyonun beklenen değeri, $X$'in bütün olası değerleri üzerinden fonksiyonun $p(x)$ ile çarpılıp toplanmasıyla bulunur. Hoca hesaba 0 değeriyle başladı, $X_1$'in $-2$ ve $2$ değerlerini aldığını fark edip düzeltti:

$$\mathrm{Var}(X_1) = (-2 - 0)^2 \cdot \tfrac{1}{2} + (2 - 0)^2 \cdot \tfrac{1}{2} = 4 \cdot \tfrac{1}{2} + 4 \cdot \tfrac{1}{2} = 2 + 2 = 4$$

**$X_2$ için:** Ortalama yine sıfırdır ve işlemler bire bir aynıdır:

$$\mathrm{Var}(X_2) = (-2000 - 0)^2 \cdot \tfrac{1}{2} + (2000 - 0)^2 \cdot \tfrac{1}{2} = 2\,000\,000 + 2\,000\,000 = 4\,000\,000$$

**Sonuç:** $\mathrm{Var}(X_1) = 4$ ve $\mathrm{Var}(X_2) = 4\,000\,000$, python ile hesaplandı. Karekök alınırsa standart sapmalar $\sigma_{X_1} = 2$ ve $\sigma_{X_2} = 2000$ olur (ara adım eklendi); bunlar değişkenlerin kendi birimindedir.

> **Ders sonrası not:** Hesabın başında $\mathrm{Var}(X_2)$ için "4000" sözü geçiyor, altyazıda bir yerde de "4.000.000.000" yazıyor. Doğrusu, hocanın vardığı sonuç olan $2000^2 = 4\,000\,000$'dur.

Hoca buradan bir benzetme yaptı: $X_2$ çok daha dalgalı bir şeydir. Borsada yatırım yaptığınızı düşünün. $X_1$, İMKB 30 gibi bir yatırıma; $X_2$ ise çok spekülatif bir hisse senedine benzer.

<!-- BELİRSİZ: Hocanın X1 için kullandığı nitelik altyazıda bozuk ("it's a very good feeling"). Kısa not bunu "istikrarlı" diye veriyor. -->

Hoca ayrıca iki değer için bunun çok fazla anlamlı olmadığını, binlerce değer olsa daha anlamlı olacağını söyledi.

### 10.2 Kovaryans

Kovaryans, iki rastgele değişkenin beraber hareket edip etmediğine bakar. Hoca bunu da hisse senetleriyle anlattı. Aynı sektördeki hisse senetleri beraber hareket edebilir, bu pozitif kovaryansa karşılık gelir. Birinin hareketi diğerinin ters yönde hareketiyle sonuçlanıyorsa kovaryans negatiftir.

<!-- BELİRSİZ: Hisse senedi örneğinin ayrıntıları (yaklaşık 01:52:34-01:54:42) altyazıda bozuk. Yalnızca "same sector", "positive" ve "negative covariance ... hisse senet" ifadeleri seçilebiliyor; yukarıdaki iki cümle bu parçalardan kuruldu. -->

Sıfır kovaryansta ise grafikteki gibi $X$ artıyor, ama $Y$'ye bakınca pek alakası yok: Azaldığı da oluyor, arttığı da. Bu durumda aralarında kovaryans yok denir.

Hoca kelimenin kökünü de açıkladı: "Co" İngilizcede "beraber" demektir, variance da değişimdir. Dolayısıyla kovaryans beraber değişim, kovaryant da beraber değişen demektir. Kovaryans sıfırsa bunlar beraber değişen rastgele değişkenler değildir.

## 11. Korelasyon

Korelasyon (correlation) kovaryansa çok benzer, ama normalleştirilmiştir. Kovaryansın sorunu şudur: Değeri çok büyük ya da çok küçük olabilir ve bu değerin büyük mü küçük mü olduğunu söylemek zordur. Büyük sayı nedir, küçük sayı nedir? Bunlar göreli şeylerdir.

Korelasyon bütün değerleri $-1$ ile $+1$ aralığına getirir. Bu yüzden yorumlaması daha kolaydır: Değer 1'e yakınsa korelasyon çok yüksektir, $-1$'e yakınsa negatif korelasyon vardır. Korelasyon $\rho$ (ro) harfiyle gösterilir.

Normalleştirme için kovaryans alınır ve $X$'in standart sapması ile $Y$'nin standart sapmasının çarpımına bölünür:

$$\rho_{XY} = \frac{\mathrm{Cov}(X, Y)}{\sigma_X\, \sigma_Y}, \qquad -1 \le \rho_{XY} \le 1$$

## 12. Varyans, Kovaryans ve Korelasyonun Özellikleri

Hoca özellikleri basitten karmaşığa doğru sıraladı. Aşağıda $a, b, c, d$ sabit, $X, Y, Z, W$ rastgele değişkendir.

### 12.1 Simetri

Kovaryansta ve korelasyonda değişkenlerin yeri değiştirilebilir:

$$\mathrm{Cov}(X, Y) = \mathrm{Cov}(Y, X), \qquad \rho(X, Y) = \rho(Y, X)$$

### 12.2 Varyansın Özellikleri

Sabit değişmediği, varyans da değişimle ilgili olduğu için sabitin varyansı sıfırdır:

$$\mathrm{Var}(c) = 0$$

Sabit çarpanı varyansın dışına karesi alınarak çıkar:

$$\mathrm{Var}(aX) = a^2\, \mathrm{Var}(X)$$

İki değişkenli doğrusal bileşimde, hocanın "büyük denklem" dediği özellik geçerlidir:

$$\mathrm{Var}(aX + bY + c) = a^2\, \mathrm{Var}(X) + b^2\, \mathrm{Var}(Y) + 2ab\, \mathrm{Cov}(X, Y)$$

Bu denklemde $b = 0$ alınırsa $\mathrm{Var}(aX + c) = a^2\, \mathrm{Var}(X)$ elde edilir (ara adım eklendi).

### 12.3 Kovaryansın Özellikleri

Hoca bu özelliği bir çarpma işlemine benzetti: İki parantezi çarpar gibi terimler eşlenir, ama doğrudan çarpmak yerine $\mathrm{Cov}$ yazılır.

$$\mathrm{Cov}(aX + bY,\ cZ + dW) = ac\,\mathrm{Cov}(X, Z) + ad\,\mathrm{Cov}(X, W) + bc\,\mathrm{Cov}(Y, Z) + bd\,\mathrm{Cov}(Y, W)$$

<!-- BELİRSİZ: Son terim bd Cov(Y, W) altyazıda duyulmuyor; hocanın "çarpma gibi" anlatımından ve kısa nottan alındı. Özdeşlik python ile sınandı. -->

Bunun özel bir hâli, her değişkene bir sabit eklendiği durumdur:

$$\mathrm{Cov}(aX + b,\ cY + d) = ac\, \mathrm{Cov}(X, Y)$$

### 12.4 Korelasyonun Özelliği

Hoca, $a$ ve $c$ ile ölçekleme yapıldığında korelasyonun değişmediğini söyledi: $\rho(aX + b,\ cY + d) = \rho(X, Y)$.

> **Ders sonrası not:** Bu eşitlik yalnızca $ac > 0$ iken doğrudur. Tanımda pay $ac\,\mathrm{Cov}(X,Y)$, payda $|a||c|\,\sigma_X\sigma_Y$ olur; bu yüzden genel hâli $\rho(aX + b,\ cY + d) = \mathrm{sgn}(ac)\,\rho(X, Y)$'dir ($a, c \ne 0$). $ac < 0$ ise korelasyonun işareti değişir. Davranış python ile hesaplandı.

### 12.5 Bağımsızlık Durumu

$X$ ve $Y$ bağımsızsa kovaryans sıfırdır ve toplamın varyansı varyansların toplamına eşittir:

$$\mathrm{Cov}(X, Y) = 0, \qquad \mathrm{Var}(X + Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$$

Bölüm 7.4'teki gibi burada da bir "eğer" vardır: Bu iki eşitlik bağımsızlık koşuluna dayanır. İkinci eşitlik, Bölüm 12.2'deki büyük denklemde $a = b = 1$, $c = 0$ ve $\mathrm{Cov}(X, Y) = 0$ alınarak da görülür (ara adım eklendi).

## Dersin Toparlaması

Bu derste rastgele değişkenin deneyin çıktısını bir sayıya götüren fonksiyon olduğu ve dağılımının PMF ya da CDF ile verildiği görüldü. İki madeni para örneğinde PMF ve CDF hem tablo hem grafik olarak kuruldu, ikisi arasındaki dönüşüm ve CDF'in basamaklı yapısı incelendi. Birden fazla değişkene geçince rastgele vektörler, birleşik ve marjinal dağılımlar ile bağımsızlık tanımlandı.

Ardından dağılımı özetleyen ölçüler geldi: Beklenen değer merkezi, varyans ve standart sapma dalgalanmayı, kovaryans birlikte değişimi, korelasyon da normalleştirilmiş birlikte değişimi gösterir. Hoca sonraki derste sayısal bir örnek yapılacağını söyledi; birleşik olasılıklara da bir örnek üzerinden dönüleceğini belirtmişti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
