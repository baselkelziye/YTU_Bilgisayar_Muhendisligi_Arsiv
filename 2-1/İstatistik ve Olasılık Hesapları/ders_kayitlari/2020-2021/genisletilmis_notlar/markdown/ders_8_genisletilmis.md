# Ders 8 Genişletilmiş Notu: Geometrik, Negatif Binom ve Poisson Dağılımları; Sürekli Dağılımlar: Düzgün, Üstel, Gama ve Normal

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kesikli Dağılım Aileleri: Geometrik ve Negatif Binom
- 2. Poisson Dağılımı
- 3. Binom Dağılımına Poisson Yaklaşımı
- 4. Sürekli Dağılımlara Giriş
- 5. Örnek: Elektronik Bileşenin Ömrü
- 6. Ortak ve Marjinal Yoğunluklar, Bağımsızlık
- 7. Sürekli Dağılımlarda Beklenen Değer
- 8. Düzgün Dağılım
- 9. Üstel Dağılım
- 10. Gama Dağılımı
- 11. Normal Dağılım

## 1. Kesikli Dağılım Aileleri: Geometrik ve Negatif Binom

Önceki derslerde kesikli dağılım ailelerine (families of discrete distributions) başlamış ve binom dağılımını görmüştük. Bu derste önce kesikli ailelerin kalanı tamamlanır, ardından sürekli dağılımlara geçilir.

### 1.1 Geometrik Dağılım

Geometrik dağılım (geometric distribution), ilk başarıyı elde etmek için gereken bağımsız Bernoulli denemesi sayısını modeller. Olasılık kütle fonksiyonu (probability mass function, PMF) şöyledir:

$$P(x) = (1-p)^{x-1}\,p, \qquad x = 1, 2, \dots$$

Burada küçük $p$, herhangi bir Bernoulli denemesinin başarı olasılığıdır. Dağılımın beklenen değeri ve varyansı:

$$E[X] = \frac{1}{p}, \qquad \mathrm{Var}(X) = \frac{1-p}{p^2}$$

Hoca bunları ispatlamadı, alıştırma olarak bıraktı. İspatta geometrik seri (geometric series) kullanmak gerektiğini söyledi. Formüllerin kendisi python ile sayısal olarak denetlendi ve doğru çıktı.

### 1.2 Negatif Binom Dağılımı

Negatif binom dağılımı (negative binomial distribution), bir bağımsız Bernoulli denemeleri dizisinde $k$ başarı elde etmek için gereken deneme sayısını modeller. Geometrik dağılım ilk başarıya kadar sayıyordu; burada $k$ başarıya kadar sayıyoruz. Bu yüzden hoca bu dağılımı "geometrik artı geometrik artı ..." diye, $k$ tane geometriğin toplamı olarak açıkladı.

> **Ders sonrası not:** Altyazıda bu toplam "sum of geometric series" ve "K geometric series" diye geçiyor. Doğrusu, $k$ tane geometrik **rastgele değişkenin** toplamıdır. Kısa nottaki gibi, ortalama ve varyansın geometriğinkinin $k$ katı olması da bunu yansıtır.

Olasılık dağılımı:

$$P(x) = \binom{x-1}{k-1}(1-p)^{x-k}\,p^k$$

Beklenen değer ve varyans:

$$E[X] = \frac{k}{p}, \qquad \mathrm{Var}(X) = \frac{k(1-p)}{p^2}$$

Burada $p$ yine tek bir Bernoulli denemesinin başarı olasılığıdır. Bu formüllerin ispatı da alıştırma olarak bırakıldı.

> **Ek bilgi (derste anlatılmadı):** Formülün okunuşu şöyledir: Son deneme $k$. başarı olmalıdır, kalan $k-1$ başarı önceki $x-1$ denemeye dağılır. $\binom{x-1}{k-1}$ çarpanı bu dağılımların sayısıdır. Bu sayım python ile tüm diziler tek tek sayılarak doğrulandı. $k$ başarı için en az $k$ deneme gerektiğinden, kısa notta da yazıldığı gibi $x = k, k+1, \dots$ olur.

## 2. Poisson Dağılımı

### 2.1 Tanım

Poisson dağılımı (Poisson distribution), sabit bir zaman aralığında gerçekleşen nadir olayların (rare events) sayısını modeller. Hoca bunları istersek "başarı" olarak da düşünebileceğimizi söyledi. Binomdan farkı, bu kez sabit bir zaman süresinden söz etmemizdir. Olasılık dağılımı:

$$P(x) = e^{-\lambda}\,\frac{\lambda^x}{x!}, \qquad x = 0, 1, 2, \dots$$

Beklenen değeri de varyansı da $\lambda$'dır:

$$E[X] = \lambda, \qquad \mathrm{Var}(X) = \lambda$$

Parametre $\lambda$, ortalama olay sayısıdır. Hoca bunu frekans olarak okuyabileceğimizi söyledi.

> **Ders sonrası not:** Altyazıda PMF "lambda over X" diye geçiyor. Doğrusu $\lambda^x$'tir; yukarıdaki formül budur. Formülün toplamı, ortalaması ve varyansı python ile denetlendi.

### 2.2 Nadir Olay Nedir?

Nadir olay, çok yakın zamanlarda iki kez gerçekleşme olasılığı çok düşük olan olaydır. Hocanın örnekleri, Dünya'ya meteor çarpması ve daha kullanışlı olarak çağrı merkezine yeni bir müşteri aramasının gelmesidir.

**Soru:** Meteor çarpması tamam, ama çağrı merkezinin aranması da mı nadir bir olaydır?

**Cevap:** Öyle varsayılır. Zaman gerçel (real) bir büyüklüktür. Tam olarak aynı anda aranmıyorsa, iki arama arasında büyük bir fark olduğunu varsayabilirsiniz, çünkü iki sayı arasında sonsuz farklı gerçel sayı vardır. Bu yüzden bunu nadir olay olarak kabul edebilirsiniz.

### 2.3 Örnek: İnternet Servis Sağlayıcısı

Hoca TTNET ya da Superonline gibi bir internet servis sağlayıcısı düşünmemizi istedi.

**Verilen:** Şirket günde ortalama 10 yeni hesap açıyor. Yani günde ortalama 10 yeni müşteri geliyor.

**Sorular:**

- (a) Bugün 8'den fazla yeni hesap açılma olasılığı nedir?
- (b) İki gün içinde 16'dan fazla yeni müşteri gelme olasılığı nedir?

**(a) şıkkı.** Problem Poisson ile modellenir. Aranan $P(X > 8)$'dir. Günde ortalama 10 müşteri olduğu için $\lambda = 10$ alınır:

$$P(x) = e^{-10}\,\frac{10^x}{x!}$$

Müşteri sayısı ilke olarak sonsuz olabilir. Bu yüzden $P(9) + P(10) + \dots$ toplamını doğrudan hesaplayamayız. Bunun yerine tümleyeni kullanırız:

$$P(X > 8) = 1 - \bigl(P(0) + P(1) + \dots + P(8)\bigr)$$

Parantezin içindeki dokuz terimi formülle tek tek hesaplayıp toplamak mümkündür, ama çok işlem gerektirir. Hoca parantezin aslında kümülatif olasılık olduğuna dikkat çekti: Sekize eşit veya sekizden küçük bütün değerlerin olasılıkları toplanıyor, yani bu toplam $F(8)$'dir. İstatistik kitapları bu durum için tablo verir. Baron'un kitabındaki Tablo A3, Poisson dağılımının kümülatif olasılıklarını içerir. Tablodan $F(8) = 0.333$ okunur:

$$P(X > 8) = 1 - F(8) = 1 - 0.333 = 0.667$$

Python ile hesaplandı: $F(8) = 0.33282$, $P(X > 8) = 0.66718$.

> **Ders sonrası not:** Hoca sonucu söylerken "eight or more" dedi ve 0.668 değerini söyledi. Soru "8'den fazla" idi, doğru değer yukarıdaki gibi $0.667$'dir. "8 veya daha fazla" sorulsaydı $1 - F(7)$ gerekirdi; o değer python ile hesaplandı: $0.77978$.

Hoca bu noktada Baron'un kitabının sonundaki tablolara bakmamızı istedi. Binom, Poisson, normal ve başka dağılımlar için kümülatif tablolar vardır, çünkü bu değerleri elle hesaplamak zordur. Başka bir yol da programlamadır. Hoca "programcı olduğumuz için" aslında bunu yapmamız gerektiğini, Python veya MATLAB'de değeri yazınca Poisson kümülatif dağılımını veren işlevler bulunduğunu söyledi. İşlevin adını hatırlamadığı için internetten aramamızı önerdi.

> **Ek bilgi (derste anlatılmadı):** Bu işlevler Python'da büyük olasılıkla SciPy kitaplığında `scipy.stats.poisson.cdf`, normal dağılım için `scipy.stats.norm.cdf`; MATLAB'de `poisscdf` ve `normcdf` adlarıyla bulunur. Bu makinede SciPy kurulu olmadığı için bu adlar burada çalıştırılarak denenmedi.

**(b) şıkkı.** Aranan $P(X > 16)$'dır. Yaklaşım neredeyse aynıdır, ama çok önemli bir fark vardır: $\lambda$ değişir. (a) şıkkında "bugün" sorulduğu için $\lambda = 10$ idi. Burada iki gündeki olay sayısı soruluyor. İki günde ortalama olay sayısı 20'dir. O hâlde $\lambda = 20$ kullanılır:

$$P(x) = e^{-20}\,\frac{20^x}{x!}, \qquad P(X > 16) = 1 - F(16) = 0.779$$

Hoca kalan işlemi alıştırmaya bıraktı. Python ile hesaplandı: $F(16) = 0.22107$, $P(X > 16) = 0.77893$. Hocanın değeri doğrudur.

Hoca, bir günde 8'den fazla ile iki günde 16'dan fazla olasılıkları arasında iki kat fark olmadığına dikkat çekti: Biri 0.6 küsur, diğeri 0.7 küsurdur.

> **Hocanın vurgusu:** Sürenin kaç gün olduğunu düşünün ve o süredeki ortalama olay sayısını $\lambda$ olarak alın. Burada $\lambda$ 20'dir, 10 değil. Bu çok önemlidir. Bu alıştırmanın amacı da size $\lambda$ konusunda bu uyarıyı yapmaktır.

## 3. Binom Dağılımına Poisson Yaklaşımı

Binom olasılıklarını hesaplamak $n$ büyükken zordur, çünkü ifadede $n!$ vardır. Hoca $1000!$'in ne kadar büyük bir sayı olduğunu düşünmemizi istedi. Binom olasılıklarını hesaplamanın bir yolu Poisson dağılımını kullanmaktır.

$n$ ve $p$ parametreli binom dağılımı, $\lambda$ parametreli Poisson ile yaklaşık olarak hesaplanabilir. Koşullar:

- $n$ yeterince büyük olmalıdır. Burada yeterince büyük, $n \ge 30$ demektir.
- Tek bir başarının olasılığı küçük olmalıdır: $p$, $0.05$'ten küçüktür.

Bu durumda $\lambda = np$ alınır:

$$\mathrm{Binom}(n, p) \approx \mathrm{Poisson}(\lambda = np)$$

<!-- BELİRSİZ: Hoca sözlü olarak "less than 0.05" dedi; kısa notta p <= 0.05 yazıyor. Slaytta eşitliğin olup olmadığı altyazıdan anlaşılamıyor. -->

Hoca bununla kesikli dağılımların bittiğini söyledi.

## 4. Sürekli Dağılımlara Giriş

### 4.1 Sürekli Rastgele Değişkenler

Sürekli rastgele değişkenlerin (continuous random variables) değer kümesi gerçel sayılardır. Zaman, bir insanın ağırlığı veya boyu, uzaklık, sıcaklık gibi fiziksel büyüklükler gerçel sayılarla modellenebilir. Bunlara sürekli dağılımlar (continuous distributions) diyoruz.

Şimdiye kadar büyük $P$ ile yazdığımız olasılık kütle fonksiyonuyla çalıştık. Sürekli dağılımlarda olasılık kütle fonksiyonu her zaman sıfırdır, yani tek bir noktanın olasılığı her zaman sıfırdır. Bu yüzden onun yerine olasılık yoğunluğu (probability density) kullanılır.

### 4.2 CDF ve Yoğunluk

Olasılık yoğunluğu, kümülatif dağılım fonksiyonundan (cumulative distribution function, CDF) elde edilir. Bu derste CDF büyük $F$ ile gösterilir:

$$F(x) = P(X \le x)$$

Sürekli durumda eşitliğin bir anlamı yoktur, çünkü tek noktanın olasılığı sıfırdır. Bu nedenle ikisi birbirine eşittir:

$$P(X \le x) = P(X < x)$$

Olasılık yoğunluk fonksiyonu (probability density function, PDF) küçük $f$ ile gösterilir ve CDF'nin türevidir:

$$f(x) = \frac{dF(x)}{dx}$$

### 4.3 Yoğunluktan Olasılık Hesabı

Yoğunluk elimizdeyken $X$'in $a$ ile $b$ arasında değer alma olasılığı integralle bulunur:

$$P(a \le X \le b) = \int_a^b f(x)\,dx$$

Bu, yoğunluk grafiğinde $a$ ile $b$ arasındaki eğrinin altında kalan alandır. Eğri altındaki alan integralle hesaplandığı için, bu alanlar o aralıkların olasılıklarına eşit olur.

Aynı olasılık kümülatif değerlerle de yazılabilir:

$$P(a \le X \le b) = F(b) - F(a)$$

Bunun nedeni şudur: $F(b)$, $X$'in $b$'den küçük veya eşit olma olasılığıdır. $b$'den küçük en küçük değer eksi sonsuz olabileceği için

$$F(b) = \int_{-\infty}^{b} f(x)\,dx$$

yazılır. Bu, eğrinin $b$'ye kadarki bütün alanıdır. Bundan eksi sonsuzdan $a$'ya kadarki alanı çıkarırsak, geriye $a$ ile $b$ arasındaki alan kalır.

Tahmin edileceği gibi, bütün olasılık 1 etmelidir. "Bütün" derken eksi sonsuzdan artı sonsuza kadarki integrali kastediyoruz:

$$\int_{-\infty}^{\infty} f(x)\,dx = 1$$

Hoca bunların sürekli olasılıkların en temel noktaları olduğunu söyledi.

## 5. Örnek: Elektronik Bileşenin Ömrü

**Verilen:** Bir elektronik bileşenin yıl cinsinden ömrünün olasılık yoğunluğu parçalı olarak veriliyor:

$$f(x) = \begin{cases} \dfrac{k}{x^3}, & x \ge 1 \\[4pt] 0, & \text{aksi hâlde} \end{cases}$$

**Sorular:**

- (a) $k$ nedir?
- (b) Kümülatif fonksiyonun grafiğini çizin.
- (c) Ömrün 5 yılı aşma olasılığı nedir?

<!-- BELİRSİZ: Hoca yoğunluğun şeklini tahtada "something like that" diyerek çizdi; çizim altyazıda yok. -->

**(a) şıkkı.** Sürekli dağılımlarda bütün gerçel eksen üzerindeki integralin 1 olduğunu biliyoruz. Burada dikkatli olmak gerekir. Yoğunluk 1'e kadar sıfırdır, sonrasında verilen fonksiyondur. Parçalı fonksiyon 1'e kadar farklı tanımlıdır ve integrali de sıfırdır, bu yüzden o bölgeyle uğraşmayız. Alt sınır olarak eksi sonsuz yerine 1 kullanılır:

$$\int_1^{\infty} \frac{k}{x^3}\,dx = 1$$

Hoca integralin alınmasını alıştırmaya bıraktı ve sonucun $k = 2$ olduğunu söyledi. İşlem şöyledir (ara adım eklendi):

$$\int_1^{\infty} \frac{k}{x^3}\,dx = \left[-\frac{k}{2x^2}\right]_1^{\infty} = \frac{k}{2} = 1 \quad\Rightarrow\quad k = 2$$

> **Ders sonrası not:** Altyazıda alt sınır için "instead of minus one" geçiyor. Doğrusu, eksi sonsuz yerine 1 alınır.

**(b) şıkkı.** Kümülatif fonksiyon, eksi sonsuzdan $x$'e kadarki integraldir. Burada $f(x)\,dx$ yazmak kafa karıştırır, çünkü $x$'i sınırda da kullanıyoruz. Bu yüzden integral değişkeni için başka bir ad seçilir, örneğin $y$. Bu değişken integralden sonra zaten yok olacağı için her ad yazılabilir. İntegral yine 1'e kadar sıfır olduğu için alt sınır 1'dir:

$$F(x) = \int_1^{x} \frac{2}{y^3}\,dy$$

Hoca bu integralin sonucunu da alıştırmaya bıraktı. İşlem şöyledir (ara adım eklendi):

$$F(x) = \left[-\frac{1}{y^2}\right]_1^{x} = 1 - \frac{1}{x^2}, \qquad x \ge 1$$

$x < 1$ için $F(x) = 0$'dır. Grafik 1'e kadar sıfırdır. 1'den sonra birkaç değer deneyerek görüleceği gibi artar ve 1'e yaklaşır.

**(c) şıkkı.** Aranan $P(X > 5)$'tir. Kümülatif dağılım kullanılarak:

$$P(X > 5) = 1 - P(X \le 5) = 1 - F(5) = 1 - \left(1 - \frac{1}{5^2}\right) = \frac{1}{25} = 0.04$$

Sonuç python ile de doğrulandı. Elimizde $F$ için güzel bir formül olduğundan bu hesap kolaydır.

> **Ders sonrası not:** Altyazıda (c) şıkkı anlatılırken "greater than one" geçiyor. Soru "5 yılı aşma" olduğundan doğrusu $P(X > 5)$'tir.

## 6. Ortak ve Marjinal Yoğunluklar, Bağımsızlık

### 6.1 Ortak CDF ve Ortak Yoğunluk

Sürekli dağılımlarda yine kümülatif dağılımdan başlanır. $X$ ve $Y$ rastgele değişkenlerinin ortak kümülatif dağılımı:

$$F(x, y) = P(X \le x,\; Y \le y)$$

Bu ortak kümülatif dağılım bir şekilde tanımlandıktan sonra ortak olasılık yoğunluğu (joint density) kolayca elde edilir. $x$'e ve $y$'ye göre kısmi türev alınır:

$$f(x, y) = \frac{\partial^2 F(x, y)}{\partial x\,\partial y}$$

Hoca önce bunu ağzından "integral" diye kaçırdı, sonra düzeltti: Yoğunluk çift türevdir, integral değildir.

### 6.2 Marjinal Yoğunluklar

Ortak yoğunluktan söz ederken tek tek değişkenlerin yoğunluklarına marjinal yoğunluk (marginal density) denir. Bunlar ortak yoğunluktan hesaplanır. $X$'in yoğunluğu için $Y$'nin bütün olası değerleri üzerinden, yani eksi sonsuzdan artı sonsuza integral alınır. $Y$ için de benzer şekilde $x$ üzerinden integral alınır:

$$f_X(x) = \int_{-\infty}^{\infty} f(x, y)\,dy, \qquad f_Y(y) = \int_{-\infty}^{\infty} f(x, y)\,dx$$

### 6.3 Bağımsızlık

Ortak yoğunluk, her $x$ ve $y$ değeri için bireysel yoğunlukların çarpımına eşitse $X$ ve $Y$ bağımsızdır:

$$f(x, y) = f_X(x)\,f_Y(y)$$

### 6.4 Ortak Yoğunlukla Olasılık Hesabı

Tek noktanın olasılığı yine sıfırdır, bu yüzden aralıklardan söz ederiz. Ortak yoğunlukla olasılık hesabı için çift katlı integral gerekir:

$$P(a \le X \le b,\; c \le Y \le d) = \int_a^b \int_c^d f(x, y)\,dy\,dx$$

Önce içteki, sonra dıştaki integral alınır. Hoca, $dx$ ve $dy$ yazım sırasının burada önemli olmaması gerektiğini söyledi.

## 7. Sürekli Dağılımlarda Beklenen Değer

Hoca önce genel bir gözlem yaptı: Sürekli dağılımlarda kullandığımız denklemlerde genellikle integral var. Bunların kesikli karşılıklarında toplam vardı. Kesikli dağılımlarda bildiğimiz kuralların çoğu, toplamı integrale çevirerek sürekli dağılımlara aktarılabilir.

$X$'in beklenen değeri ($\mu$ ile de gösterilir), $x$'in bütün olası değerleri üzerinden integraldir:

$$E[X] = \mu = \int_{-\infty}^{\infty} x\,f(x)\,dx$$

Daha genel olarak, bir $g(x)$ fonksiyonunun beklenen değeri için $x$ yerine $g(x)$ yazılır. Her $x$ için $g(x)$ hesaplanır ve yoğunlukla çarpılır:

$$E[g(X)] = \int_{-\infty}^{\infty} g(x)\,f(x)\,dx$$

$X$ ve $Y$'nin ortak dağılımı varsa, iki rastgele değişken olduğu için çift katlı integral alınır:

$$E[g(X, Y)] = \int_{-\infty}^{\infty}\int_{-\infty}^{\infty} g(x, y)\,f(x, y)\,dy\,dx$$

İkiden fazla değişken de olabilir. Yöntem aynıdır: Beklenen değeri istenen fonksiyon yazılır, yoğunluk yazılır, integraller alınır.

> **Ders sonrası not:** Altyazıda yöntemin sonunda "that gives you this joint density" geçiyor. Bu işlemin verdiği şey ortak yoğunluk değil, fonksiyonun beklenen değeridir.

Hocanın örneği, $X$ ile $Y$'nin çarpımının beklenen değeridir:

$$E[XY] = \int_{-\infty}^{\infty}\int_{-\infty}^{\infty} x\,y\,f(x, y)\,dy\,dx$$

Hoca bunun yazımının $dx\,dy$ sırasıyla da olabileceğini söyledi. Hocanın özeti şudur: Şimdiye kadar gördüklerimize çok benziyor; fark, toplamın yerine integralin, PMF'nin yerine yoğunluğun geçmesidir.

## 8. Düzgün Dağılım

Hoca sürekli dağılım ailelerine düzgün dağılımla (uniform distribution) başladı. Bu dağılımda yoğunluk sabittir. Grafiği çizilirken aralık da belirtilmelidir: Yoğunluk $a$ ile $b$ arasında sabit bir değerdir, başka her yerde sıfırdır.

Bu sabit değer nedir? Eğri altındaki alan 1 olmalıdır. Taban ile yüksekliği çarptığımızda 1 bulmamız gerektiği için yükseklik $1/(b-a)$ olur:

$$f(x) = \frac{1}{b-a}, \qquad a \le x \le b$$

Parametreleri $a$ ve $b$ olduğu için $X \sim U(a, b)$ yazılır.

> **Ders sonrası not:** Altyazıda bir yerde yoğunluk "one minus B" diye geçiyor, hemen ardından doğrusu söyleniyor. Yoğunluk $1/(b-a)$'dır.

### 8.1 Standart Düzgün Dağılım

$a = 0$ ve $b = 1$ alınırsa standart düzgün dağılım (standard uniform distribution) elde edilir. Alanı 1 yapan sabit burada 1'dir, çünkü $1 \times 1 = 1$:

$$f(x) = \begin{cases} 1, & 0 \le x \le 1 \\ 0, & \text{aksi hâlde} \end{cases}$$

Hoca, 0 ile 1 arasında yoğunluğun 1, başka yerde 0 olduğunun unutulmamasını istedi.

Düzgün dağılım standart düzgün dağılıma, standart düzgün dağılım da standart olmayana çevrilebilir. Ayrımı netleştirmek için standart değişkene $Y \sim U(0,1)$, standart olmayana $X \sim U(a,b)$ diyelim. Standartlaştırma ve tersi:

$$Y = \frac{X - a}{b - a}, \qquad X = a + (b - a)\,Y$$

### 8.2 Programlamadaki Kullanımı

Bu dönüşüm programlamada işe yarar. C veya Python gibi dillerde `rand` adıyla bilinen, çağrıldığında 0 ile 1 arasında değer veren işlevler vardır. Bu işlevin döndürdüğü $R$ değeri için $R \sim U(0,1)$ denebilir.

10 ile 20 arasında değerler istediğimizi düşünelim. Dönüşüm uygulanır:

$$X = 10 + (20 - 10)\,R$$

$R = 0$ için 10, $R = 1$ için 20 elde edilir (ara adım eklendi). Böylece standart düzgün dağılımdaki bir rastgele sayıdan, standart olmayan düzgün dağılımda bir rastgele sayı elde edilir.

### 8.3 Beklenen Değer ve Varyans

$X \sim U(a, b)$ için:

$$E[X] = \frac{a + b}{2}, \qquad \mathrm{Var}(X) = \frac{(b - a)^2}{12}$$

Hoca bunları da alıştırma olarak bıraktı. Standart düzgün dağılım için formüllere 0 ve 1 yazmak yeterlidir.

## 9. Üstel Dağılım

### 9.1 Tanım

Üstel dağılım (exponential distribution) zamanı modellemek için kullanılır. Başka şeyler için de kullanılabilir, ama bu derste çoğunlukla zamanı modelleyeceğiz. Bu zaman bir bekleme süresi veya çağrı merkezinde iki telefon araması arasındaki süre (inter-arrival time) olabilir.

$$f(x) = \lambda e^{-\lambda x}, \qquad x > 0$$

$$E[X] = \frac{1}{\lambda}, \qquad \mathrm{Var}(X) = \frac{1}{\lambda^2}$$

Kümülatif dağılımının güzel bir denklemi vardır:

$$F(x) = 1 - e^{-\lambda x}, \qquad x > 0$$

Bunlar da alıştırmadır. İntegral almanız gerekir, yapılabilir hesaplardır. Bir veya iki kez kısmi integrasyon (integration by parts) kullanılır.

$\lambda$ frekans parametresidir (frequency parameter): birim zamandaki olay sayısı.

### 9.2 Poisson, Üstel ve Gama Arasındaki İlişki

Hoca yazıcı örneğini sorduktan sonra çözüme geçmeden önce yazmadığı bir noktayı not etti: Nadir olaylar arasındaki süreler üsteldir. Zaman eksenini ve bu eksen üzerinde art arda gerçekleşen nadir olayları düşünelim. Başlangıç anı $t_0$'ı bir olay gerçekleştikten hemen sonra alalım.

- **Belirli bir $t$ süresindeki olay sayısı** ($X$ diyelim) Poisson dağılır. Bunu az önce gördük.
- **İki olay arasındaki süre** üstel dağılır. Bu süreler zaman ekseninde $T_1, T_2, T_3, \dots$ diye gösterilebilir.
- **$k$ olay için gereken süre** ($Y$ diyelim) gama dağılır. Hocanın örnek sorusu şuydu: Bir çağrı merkezinde altıncı aramanın 10 dakika içinde gelme olasılığı nedir? Gama dağılımını birazdan göreceğiz.

Nadir olaylar art arda gerçekleşirken bu üç dağılım birlikte çalışır.

<!-- BELİRSİZ: Zaman ekseni çizimi altyazıda yok. Hoca 01:53 civarında X ve T harflerini karıştırarak söylüyor; olay sayısı X, olaylar arası süreler T1, T2, T3 olarak anlaşıldı. -->

### 9.3 Örnek: Yazıcı

**Verilen:** Ortak kullanılan bir ofis yazıcısına, insanlar kendi bilgisayarlarından iş gönderiyor. Yazıcıya saatte ortalama 3 iş geliyor.

**Sorular:**

- (a) İşler arasındaki beklenen süre nedir?
- (b) Sonraki işin 5 dakika içinde gönderilme olasılığı nedir?

Burada $X$, sonraki iş için bekleme süresidir: Yazıcı sonraki iş için ne kadar bekleyecek? İşler arası süre, nadir olaylar arasındaki süre olduğu için üstel dağılır. Üstel dağılımda $\lambda$'yı bilirsek, denklemler sayesinde her şeyi biliriz. "Saatte ortalama 3 iş" denildiği için:

$$\lambda = 3 \text{ iş/saat}$$

> **Hocanın vurgusu:** Bu tür problemlerde önemli olan soru şudur: $\lambda$ nedir?

**(a) şıkkı.** Beklenen değer $1/\lambda$'dır:

$$E[X] = \frac{1}{\lambda} = \frac{1}{3} \text{ saat/iş} = 20 \text{ dakika/iş}$$

Yani her 20 dakikada bir iş gelmesini bekleriz.

**(b) şıkkı.** $P(X \le 5 \text{ dakika})$ doğrudan kümülatif dağılımdır. Ama saat ve dakikaya dikkat etmek gerekir, çünkü $\lambda$ saat cinsindendir. Dakikayı saate ya da saati dakikaya çevirmek fark etmez. 5 dakikayı saate çevirelim. Bir saatte 60 dakika olduğu için 5 dakika $= 5/60$ saattir. Denklemde yerine yazılır:

$$F\!\left(\frac{5}{60}\right) = 1 - e^{-3 \cdot 5/60} = 1 - e^{-0.25} = 0.2212$$

Python ile hesaplandı: $0.22120$. Hocanın değeri doğrudur.

> **Ders sonrası not:** Altyazıda 5 dakikanın saat karşılığı "five over six dollars" diye geçiyor. Doğrusu $5/60$ saattir.

### 9.4 Belleksizlik Özelliği

Üstel dağılımın ilginç bir özelliği belleksizlik özelliğidir (memoryless property): Üstel dağılımın belleği yoktur.

$$P(T > t + x \mid T > t) = P(T > x)$$

Burada büyük $T$ rastgele değişkendir: bir olay için bekleme süresidir ve üstel dağılır. Küçük $t$ ise bekleme süresinin geçmiş kısmıdır.

Hocanın örneği yine yazıcıdır: Yazıcının yanında bir yazdırma işi bekliyoruz. 10 dakikanın geçmiş olması hiçbir şeyi değiştirmez, 5 dakikadan fazla bekleme olasılığı yine aynıdır. Beklemeye başladığımızdan beri ne kadar zaman geçtiği, verilen bir süreden fazla bekleme olasılığını değiştirmez.

Sürekli dağılımlarda bu özellik üstel dağılımda vardır. Kesikli dağılımlarda aynı özellik geometrik dağılımda vardır.

> **Ek bilgi (derste anlatılmadı):** Özellik, derste verilen $F$ formülünden çıkar. $P(T > t) = e^{-\lambda t}$ olduğu için koşullu olasılık $e^{-\lambda(t+x)} / e^{-\lambda t} = e^{-\lambda x}$ olur ve bu da $P(T > x)$'tir. Eşitlik python ile bir değer ızgarasında sayısal olarak denetlendi.

## 10. Gama Dağılımı

### 10.1 Tanım

$\alpha$ tane bağımsız adımımız olsun. Zaman ekseninde adımlar art arda geliyor ve her iki olay arasındaki süre üstel dağılıyor. Bu durumda $\alpha$ adım için geçen toplam süre gama dağılımına (gamma distribution) uyar.

Gama dağılımının iki parametresi vardır: $\alpha$ ve $\lambda$. $\lambda$ üstel dağılımdan gelen $\lambda$'dır, $\alpha$ ise adım sayısıdır. Yoğunluk:

$$f(x) = \frac{\lambda^{\alpha}}{\Gamma(\alpha)}\,x^{\alpha-1}\,e^{-\lambda x}, \qquad x > 0$$

Burada $\Gamma$, gama fonksiyonudur:

$$\Gamma(\alpha) = \int_0^{\infty} x^{\alpha-1}\,e^{-x}\,dx, \qquad \alpha > 0$$

$\alpha$ tamsayı olmak zorunda değildir. Tamsayı ise $\Gamma(\alpha) = (\alpha - 1)!$ olur.

> **Ders sonrası not:** Altyazıda yoğunluk karışık okunuyor: "$x$ to the alpha $x$ or minus one, $e$ to the minus alpha $x$". Doğrusu yukarıdaki formüldür; yukarıdaki biçim, $\alpha = 1$'de üstel yoğunluğu verir (aşağıya bakın). Hoca ayrıca faktöriyel eşitliği için "$\alpha > 1$" şartını koydu; eşitlik $\alpha = 1$'de de geçerlidir. Python ile hesaplandı: $\Gamma(1) = 1 = 0!$.

Hoca denklemin oldukça karmaşık olduğunu söyledi. $\alpha$ şekil parametresi (shape parameter), $\lambda$ frekans parametresidir. $\alpha$'ya şekil denmesinin nedeni, dağılımın şeklini çok değiştirmesidir.

### 10.2 Şekil

Yoğunluğun grafiği özellikle $\alpha$'ya göre çok değişir:

- **$\alpha = 1$:** Üstel dağılımın grafiği elde edilir. Karmaşık denklem $\alpha = 1$ yazınca üstel denkleme dönüşür. Hoca bunu denememizi söyledi: $\frac{\lambda^1}{\Gamma(1)} x^0 e^{-\lambda x} = \lambda e^{-\lambda x}$ (ara adım eklendi).
- **$\alpha > 1$:** Hocanın tahtada çizdiği başka biçimde bir eğri.
- **$\alpha < 1$:** Hocanın tahtada çizdiği üçüncü bir eğri.

<!-- BELİRSİZ: Hoca alpha > 1 ve alpha < 1 eğrilerini "something like this" diyerek çizdi; çizimler altyazıda yok. Python ile yoğunluk değerleri hesaplandı: alpha = 3 için eğri önce artıp sonra azalıyor (tepeli); alpha = 0.5 için x sıfıra yaklaşınca çok büyük değerler alıyor ve x arttıkça azalıyor. -->

Şekli çok esnek olduğu için gama dağılımı mühendislikte çok farklı şeyleri modellemek için kullanılır. Yine de bu ders için zamandan söz ettiğimizi varsayacağız.

### 10.3 Beklenen Değer ve Varyans

$$E[X] = \frac{\alpha}{\lambda}, \qquad \mathrm{Var}(X) = \frac{\alpha}{\lambda^2}$$

Bunlar, gama dağılımının üstel dağılımların toplamı olmasından gelir: $\alpha$ tane üstel dağılım vardır.

> **Ders sonrası not:** Hoca "her birinin beklenen değeri $1/\alpha$" dedi. Doğrusu, her üstel değişkenin beklenen değeri $1/\lambda$'dır. $\alpha$ tanesinin toplamı $\alpha/\lambda$ eder.

### 10.4 Gama Olasılıklarını Poisson ile Hesaplamak

Hoca, gama, Poisson ve üstelin birbiriyle ilişkili olduğunu daha önce söylemişti. Gama olasılıkları Poisson ile hesaplanabilir. $T$ süresi gama dağılsın, $X$ ise parametresi $\lambda t$ olan bir Poisson olsun:

$$T \sim \mathrm{Gamma}(\alpha, \lambda), \qquad X \sim \mathrm{Poisson}(\lambda t)$$

O zaman iki güzel denklem vardır:

$$P(T > t) = P(X < \alpha)$$

$$P(T \le t) = P(X \ge \alpha)$$

Gama denklemi gerçekten zordur ve kümülatif dağılımının güzel bir denklemi yoktur. Bu yüzden Poisson kullanılabilir. Fikir az önce konuştuğumuz fikirdir: Belirli bir sürede olay sayısı Poisson, $k$ olay için gereken süre gamadır. Aynı problem ters yönden düşünülerek bu denklemlere varılır.

> **Ek bilgi (derste anlatılmadı):** Ters yönden düşünmek şu demektir: "$\alpha$. olay $t$ anına kadar gerçekleşmedi" ile "$t$ süresinde $\alpha$'dan az olay oldu" aynı durumdur. Bu okuma, $\alpha$'nın adım sayısı yani tamsayı olduğu durum içindir. Python ile hesaplandı: Denenen tamsayı $\alpha$ değerlerinde iki taraf sayısal olarak eşit çıktı, denenen tamsayı olmayan $\alpha$ değerlerinde eşit çıkmadı.

## 11. Normal Dağılım

### 11.1 Tanım

Normal dağılım (normal distribution), ortalamaları ve toplamları modellemek için kullanılır. Bazen hatalar için de kullanılır, ayrıca ağırlık ve sıcaklık gibi şeyleri modeller. Çok yaygın kullanılan bir dağılımdır.

> **Hocanın vurgusu:** Toplamları ve ortalamaları modelleyebilmemiz çok önemlidir.

Yoğunluğu:

$$f(x) = \frac{1}{\sigma\sqrt{2\pi}}\,e^{-\frac{(x-\mu)^2}{2\sigma^2}}, \qquad -\infty < x < \infty$$

İki parametresi vardır: Beklenen değer $\mu$ ve standart sapma $\sigma$. Bir rastgele değişkenin normal dağıldığını söylerken genellikle ortalamasını ve standart sapmasını veririz: $X \sim N(\mu, \sigma)$.

$$E[X] = \mu, \qquad \mathrm{Var}(X) = \sigma^2$$

### 11.2 Standart Normal Dağılım

Standart normal dağılım, $\mu = 0$ ve $\sigma = 1$ olan normal dağılımdır. Çok kullanıldığı için özel bir sembolü vardır: Standart normal değişken genellikle $Z$ ile gösterilir. Yoğunluğu için $f$ yerine genellikle küçük $\phi$ kullanılır. Yukarıdaki denklemde $\mu$ yerine 0, $\sigma$ yerine 1 yazılır:

$$\phi(x) = \frac{1}{\sqrt{2\pi}}\,e^{-x^2/2}$$

Kümülatif dağılımı için büyük $F$ yerine büyük $\Phi$ kullanılır.

> **Ders sonrası not:** Altyazıda standart sürüm için "mu zero and mu zero" geçiyor; doğrusu hemen ardından söylendiği gibi $\mu = 0$ ve $\sigma = 1$'dir. Sabit de "one over two pi square" diye okunuyor; doğrusu $1/\sqrt{2\pi}$'dir. Bu sabitle yoğunluğun integrali python ile hesaplandı: 1.

Normal ile standart normal birbirine çevrilebilir. $X \sim N(\mu, \sigma)$ ise:

$$Z = \frac{X - \mu}{\sigma}, \qquad X = \mu + \sigma Z$$

### 11.3 Grafik ve Olasılık Hesabı

Grafiği çok bilinir, çan şekillidir (bell shaped) ve simetriktir. Merkezinde $\mu$ bulunur.

<!-- BELİRSİZ: Hoca çan eğrisini çizdi ve üzerinde sigma ile standart normalin değerlerini gösterdi; çizim altyazıda yok. -->

Olasılık hesabı oldukça karmaşıktır, çünkü kümülatif olasılıklar için güzel bir denklem yoktur. Baron'un kitabındaki Tablo A4 veya programlama dillerinin işlevleri kullanılabilir.

> **Hocanın vurgusu:** Bu tabloları kullanmayı öğrenmeniz gerekir, onlara bir göz atın.

### 11.4 Örnek: Bir Oyun Ülkesinde Gelir

**Verilen:** Hoca muhtemelen bir oyundaki ülke olduğunu söylediği bir ülke tarif etti. Ortalama hane geliri 900 jeton, standart sapma 200 jeton. $X$ gelirleri modelliyor ve normal dağılıyor: $X \sim N(900, 200)$.

**Soru:** Orta sınıfın, yani geliri 600 ile 1200 jeton arasında olanların oranı nedir?

> **Ders sonrası not:** Hoca soruyu önce iki kez "600 ile 900 arası" diye okudu, sonra aralığı 600 ile 1200 olarak düzeltti. Hesap da 600–1200 ile yapıldı. Hoca ayrıca standart sapmayı "ortalama hane gelirinin standart sapması" diye söyledi. Hesapta kullanıldığı gibi bu, gelir değişkeni $X$'in standart sapmasıdır.

**Çözüm.** Çan eğrisi üzerinde 600 ile 1200 arasındaki alan aranıyor. Bu, kümülatif dağılımla şöyle yazılır:

$$P(600 \le X \le 1200) = F(1200) - F(600)$$

Bunu doğrudan hesaplayamayız, çünkü güzel bir denklem yoktur. Kitabın sonunda standart kümülatif olasılıklar için bir tablo vardır. Bu yüzden büyük $F$'yi $\Phi$'ye çeviririz. Çeviri, az önce öğrendiğimiz $z = (x-\mu)/\sigma$ denklemiyle yapılır:

$$F(1200) - F(600) = \Phi\!\left(\frac{1200 - 900}{200}\right) - \Phi\!\left(\frac{600 - 900}{200}\right)$$

$$= \Phi\!\left(\frac{300}{200}\right) - \Phi\!\left(\frac{-300}{200}\right) = \Phi(1.5) - \Phi(-1.5)$$

Tablo A4'ten bu değerler okunur (hoca tablonun numarasını "A4, sanırım" diye verdi). İkinci değer negatif bir $z$ içindir:

$$\Phi(1.5) = 0.9332, \qquad \Phi(-1.5) = 0.0668$$

$$P(600 \le X \le 1200) = 0.9332 - 0.0668 = 0.8664$$

Bu oran, bu nüfusta orta sınıfın yaklaşık %87 olduğunu söyler. Python ile hesaplandı: $\Phi(1.5) = 0.93319$, $\Phi(-1.5) = 0.06681$, fark $0.86639$. Hocanın değeri doğrudur.

## Dersin Toparlaması

Bu derste kesikli aileler geometrik, negatif binom ve Poisson dağılımlarıyla tamamlandı; Poisson'un binoma yaklaşımı görüldü. Ardından sürekli dağılımlara geçildi: Tek noktanın olasılığı sıfır olduğu için PMF yerine yoğunluk, toplam yerine integral kullanılır. Ortak ve marjinal yoğunluklar, bağımsızlık ve beklenen değer bu yeni dille yeniden yazıldı. Son olarak düzgün, üstel, gama ve normal aileleri işlendi. Poisson, üstel ve gama arasındaki ilişki dersin ana bağlarından biridir: Belirli süredeki nadir olay sayısı Poisson, olaylar arası süre üstel, $\alpha$ olayın toplam süresi gamadır.

Gelecek ders merkezi limit teoremi (central limit theorem) görülecek. Hoca bu hafta çok hızlı gidildiğini ve yalnız çok önemli örneklerin yapıldığını söyledi. Dolayısıyla atlanan örneklere kitaptan bakmak gerekir. Baron'un 3. ve 4. bölüm alıştırmaları çalışılmalıdır; aynı konular Pishro-Nik'in kitabından da çalışılabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
