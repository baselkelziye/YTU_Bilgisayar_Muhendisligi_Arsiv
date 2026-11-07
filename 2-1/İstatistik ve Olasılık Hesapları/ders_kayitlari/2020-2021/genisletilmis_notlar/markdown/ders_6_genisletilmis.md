# Ders 6 Genişletilmiş Notu: Birleşik Dağılım Örneği, Chebyshev Eşitsizliği, Bernoulli ve Binom Dağılımları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı
- 2. Sayısal Örnek: İki Modüllü Programda Hata Sayıları
- 3. Chebyshev Eşitsizliği
- 4. Yaygın Kesikli Dağılımlar ve Bernoulli Dağılımı
- 5. Binom Dağılımı
- 6. Quiz Sorusunun Çözümü

## 1. Önceki Dersin Tekrarı

Hoca derse, kesikli rastgele değişkenlere devam edeceğimizi söyleyerek başladı ve geçen dersin konularını sırayla tekrar etti.

### 1.1 Kesikli Rastgele Değişken, PMF ve CDF

Kesikli rastgele değişken (discrete random variable), bir deneyin çıktısını alıp bize bir sayı veren fonksiyondur. Hoca sonucun bir sayı olmasının önemli olduğunu özellikle söyledi. Örneği, iki hilesiz para atıldığında gelen tura sayısıydı.

Bu değişkenler için iki fonksiyon görmüştük:

- **Olasılık kütle fonksiyonu (probability mass function, PMF):** Rastgele değişkenin belirli bir değeri alma olasılığını verir.
- **Kümülatif dağılım fonksiyonu (cumulative distribution function, CDF):** Rastgele değişkenin belirli bir sayıya eşit ya da ondan küçük bir değer alma olasılığını verir.

Hoca bu ikisini aynı elmanın iki farklı parçasına benzetti: PMF'i biliyorsanız CDF'i, CDF'i biliyorsanız PMF'i elde edebilirsiniz.

<!-- BELİRSİZ: 00:05:25'te PMF ve CDF grafikleri ekranda çizildi; altyazıda yalnızca "şuna benzer" deniyor, çizimin kendisi okunmuyor. -->

### 1.2 Rastgele Vektörler ve Marjinal Dağılım

Bir rastgele vektörde (random vector) birden fazla rastgele değişken vardır. Birden fazla değişken olunca birleşik dağılımdan (joint distribution) söz edebiliriz. Birleşik PMF, $X$'in $x$ değerini **ve** $Y$'nin $y$ değerini alma olasılığıdır:

$$p_{X,Y}(x,y) = P(X = x \text{ ve } Y = y)$$

Bütün bu olasılıkların toplamı her zaman $1$ olmalıdır.

Birleşik olasılıklar elimizdeyse marjinal olasılıkları (marginal probabilities) elde edebiliriz. Bunun için diğer rastgele değişkenin bütün olası değerleri üzerinden toplam alırız. $X$'in marjinal dağılımını istiyorsak $y$'ler üzerinden, $Y$'nin marjinal dağılımını istiyorsak $x$'ler üzerinden toplarız:

$$p_X(x) = \sum_y p_{X,Y}(x,y), \qquad p_Y(y) = \sum_x p_{X,Y}(x,y)$$

### 1.3 Bağımsızlık

$X$ ve $Y$ rastgele değişkenleri, **bütün** $x, y$ değerleri için aşağıdaki eşitlik sağlanıyorsa bağımsızdır:

$$p_{X,Y}(x,y) = p_X(x)\,p_Y(y)$$

> **Hocanın vurgusu:** Bu eşitlik bütün değerler için doğru olmalıdır. Hoca bunu önce söyledi, sonra tahtaya "bütün $x, y$ değerleri için" diye açıkça yazdı.

### 1.4 Beklenen Değer

Bir rastgele değişkenin beklenen değeri (expected value, expectation), bütün olası değerlerin kendi olasılıklarıyla çarpılıp toplanmasıyla bulunur. Hoca bunu bir çeşit ortalama değer olarak düşünebileceğimizi söyledi:

$$E[X] = \sum_x x\,p_X(x)$$

Tek bir değişken yerine bir fonksiyonun beklenen değerinden de söz edebiliriz. Denklem benzerdir, $x$ yerine $g(x)$ yazılır:

$$E[g(X)] = \sum_x g(x)\,p_X(x)$$

Beklenen değerin özellikleri şunlardı:

- Bir sabitin beklenen değeri kendisidir: $E[c] = c$.
- Sabit bir çarpan beklenen değerin dışına alınır: $E[cX] = c\,E[X]$.
- Bir toplamın beklenen değeri, terimlerin beklenen değerlerinin toplamıdır.
- **Eğer** $X$ ve $Y$ bağımsızsa $E[XY] = E[X]\,E[Y]$ yazılabilir. Hoca buradaki "eğer" koşuluna dikkat çekti.

<!-- BELİRSİZ: 00:11:28'de bu özelliklerin bir ifadeye uygulanışı slaytta gösterildi; altyazıda "buna uygulayınca bunu elde edersiniz" deniyor, ifadenin kendisi okunmuyor. -->

### 1.5 Varyans ve Standart Sapma

Varyans, ortalamadan farkın karesinin beklenen değeridir. Önce ortalamayı hesaplarsınız, sonra ortalamadan farkı alıp karesini alırsınız ki negatifler pozitif olsun, sonra bunun beklenen değerini alırsınız. Beklenen değer nasıl alınıyordu? Fonksiyon çarpı olasılık, sonra toplam. Yani varyans, merkezden olan farkın beklenen değeridir. İki biçimi vardır, ikisi de kullanılabilir:

$$\mathrm{Var}(X) = E\left[(X - \mu)^2\right] = E[X^2] - \mu^2$$

Standart sapma (standard deviation), varyansın kareköküdür. Hoca ikinci biçimin birinciden elde edilebileceğini, bunu kendi başımıza göstermemiz gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu gösterim, dersteki beklenen değer özellikleriyle yapılır. Kareyi açarız: $E[(X-\mu)^2] = E[X^2 - 2\mu X + \mu^2]$. Toplamı ayırıp sabitleri dışarı alırız: $E[X^2] - 2\mu E[X] + \mu^2$. $E[X] = \mu$ olduğundan sonuç $E[X^2] - \mu^2$ olur.

### 1.6 Kovaryans ve Korelasyon

Kovaryans (covariance), iki değişkenin kendi ortalamalarından farklarının çarpımının beklenen değeridir:

$$\mathrm{Cov}(X,Y) = E\left[(X - \mu_X)(Y - \mu_Y)\right] = E[XY] - \mu_X \mu_Y$$

Hoca birinci biçimin arkasındaki sezgiyi bir soruyla anlattı: $X$ ortalamanın üstüne çıkarken $Y$ de ortalamanın üstüne çıkıyor mu? Kovaryans bir bakıma bu soruyu cevaplar. İkinci biçim de birinciden elde edilir, bunu da kendimiz göstermeliyiz. Kovaryansın işaretinin anlamı şöyledir:

- **Pozitif kovaryans:** Bir değişken yükselirken diğeri de yükselir.
- **Negatif kovaryans:** Bir değişken yükselirken diğeri düşer.
- **Sıfır kovaryans:** Bir değişken yükselirken diğeri bir şey yapmaz. Yükselmez, düşmez, olduğu yerde dalgalanır.

Korelasyon (correlation) kovaryansa benzer, ama değerleri $-1$ ile $1$ arasındadır. Bunu kovaryansı standart sapmalara bölerek, yani standart sapmalarla normalize ederek sağlarız:

$$\rho(X,Y) = \frac{\mathrm{Cov}(X,Y)}{\sigma_X\,\sigma_Y}$$

### 1.7 Varyans, Kovaryans ve Korelasyonun Özellikleri

Hoca kanıtları atladı, ama bunların zor olmadığını ve kendimizin kanıtlayabileceğini söyledi:

- Bir sabitin varyansı sıfırdır: $\mathrm{Var}(c) = 0$.
- Sabit çarpan varyansın dışına karesiyle çıkar: $\mathrm{Var}(cX) = c^2\,\mathrm{Var}(X)$.
- $\mathrm{Var}(aX + bY + c) = a^2\,\mathrm{Var}(X) + b^2\,\mathrm{Var}(Y) + 2ab\,\mathrm{Cov}(X,Y)$.
- Özel bir durum: $\mathrm{Cov}(aX + b,\ cY + d) = ac\,\mathrm{Cov}(X,Y)$.
- Korelasyonda bir sabit eklemek ya da bir sabitle ölçeklemek hiçbir şeyi değiştirmez: $\rho(aX+b,\ cY+d) = \rho(X,Y)$. Hocanın ifadesiyle korelasyon bu ayrıntılardan kurtulur.
- **Eğer** $X$ ve $Y$ bağımsızsa $\mathrm{Cov}(X,Y) = 0$ ve $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$ olur. Burada da "eğer" koşulu vardır.

> **Ders sonrası not:** Hoca korelasyonun ölçeklemeyle hiç değişmediğini söyledi. Bu, $ac > 0$ iken doğrudur. $ac < 0$ olursa işaret değişir: Yukarıdaki kovaryans özelliğine göre pay $ac$ ile, payda $|ac|$ ile çarpılır. Bir sonraki bölümdeki tablo üzerinde python ile hesaplandı: $\rho(X,Y) \approx 0.140$, $\rho(2X+1,\ 3Y+5) \approx 0.140$, $\rho(-X,\ Y) \approx -0.140$.

<!-- BELİRSİZ: 00:16:29'da "bir tane daha var" denilen özellik slaytta kalmış, altyazıda hangi özellik olduğu okunmuyor. -->

## 2. Sayısal Örnek: İki Modüllü Programda Hata Sayıları

Hoca tekrarın ardından, rastgele vektörlerle ilgili ama çok şey hesaplatan, dolayısıyla tekrar yerine de geçen bir sayısal örneğe geçti.

### 2.1 Problem

İki modülden oluşan bir program var. $X$ birinci modüldeki hata sayısı, $Y$ ikinci modüldeki hata sayısı. Birleşik dağılım şöyle veriliyor:

- $P(0,0) = P(0,1) = P(1,0) = 0.20$
- $P(1,1) = P(1,2) = P(1,3) = 0.10$
- $P(0,2) = P(0,3) = 0.05$

İstenenler:

- a) Marjinal olasılıklar.
- b) $X$ ve $Y$ bağımsız mı?
- c) $\mathrm{Var}(X)$ ve $\mathrm{Var}(Y)$.
- d) Korelasyon katsayısı (correlation coefficient).

**Soru:** Soruyu çözmeden önce Türkçe açıklayabilir misiniz?

**Cevap:** Bir programda iki modül var, bunları iki dosya gibi düşünebilirsiniz. $X$ birinci dosyadaki, $Y$ ikinci dosyadaki hataların sayısı. Bize $X$ ve $Y$ doğrudan verilmemiş, birleşik dağılımları verilmiş. Örneğin birinci dosyada hiç hata olmaması ve ikinci dosyada hiç hata olmaması olasılığı $0.2$'ymiş. Birinci dosyada 1, ikinci dosyada 2 hata olması olasılığı $0.1$'miş. Bu birleşik dağılımdan yola çıkarak önce marjinal olasılıkları bulacağız, yani $X$'in ve $Y$'nin kendi olasılıklarını. Birleşik dağılım varsa bu tekil dağılımlara marjinal dağılım diyoruz. Sonra $X$ ile $Y$ birbirinden bağımsız mı, $X$'in ve $Y$'nin varyansı ve korelasyon katsayısı nedir, bunlara bakacağız.

### 2.2 Birleşik Dağılım Tablosu

Hoca işe başlamadan önce bir birleşik dağılım tablosu kurmanın işleri kolaylaştıracağını söyledi. Önce değer kümelerine bakılır. Verilen olasılıklara bakınca $X$ yalnız $0$ ve $1$, $Y$ ise $0, 1, 2, 3$ değerlerini alıyor:

$$R_X = \{0, 1\}, \qquad R_Y = \{0, 1, 2, 3\}$$

Satırlara $X$'in, sütunlara $Y$'nin değerleri yazılır, hücrelere de birleşik olasılıklar. Burada yeni bir bilgi yoktur, birleşik dağılım yalnızca tablo olarak yazılmıştır. Son satır ve son sütun, biraz sonra bulacağımız marjinal olasılıklardır:

| $x \backslash y$ | 0 | 1 | 2 | 3 | $p_X(x)$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0.20 | 0.20 | 0.05 | 0.05 | 0.50 |
| 1 | 0.20 | 0.10 | 0.10 | 0.10 | 0.50 |
| $p_Y(y)$ | 0.40 | 0.30 | 0.15 | 0.15 | 1 |

### 2.3 a) Marjinal Dağılımlar

Bulmamız gereken altı değer var: $p_X(0)$, $p_X(1)$ ile $p_Y(0)$, $p_Y(1)$, $p_Y(2)$, $p_Y(3)$. İlk ikisi $X$'in, son dördü $Y$'nin PMF'ini verir.

$X$ için $y$'ler üzerinden toplarız. Hoca, toplam sembolünde başlangıç ve bitiş yazılmazsa bunun "bütün olası değerler" demek olduğunu da belirtti. $x = 0$ tablonun ilk satırıdır:

$$p_X(0) = \sum_{y=0}^{3} p_{X,Y}(0,y) = 0.20 + 0.20 + 0.05 + 0.05 = 0.50$$

$x = 1$ ikinci satırdır:

$$p_X(1) = \sum_{y} p_{X,Y}(1,y) = 0.20 + 0.10 + 0.10 + 0.10 = 0.50$$

Bu sonuçları isterseniz tablonun kenarlarına, marjlarına yazabilirsiniz. $X$'in marjinal dağılımı şöyledir:

| $x$ | 0 | 1 |
| :---: | :---: | :---: |
| $p_X(x)$ | 0.50 | 0.50 |

Buna marjinal dememizin sebebi, problemde başka bir rastgele değişkenin de bulunmasıdır. Tek değişken olsaydı yalnızca "olasılık dağılımı" derdik.

$Y$ için $x$'ler üzerinden toplarız, yani tablonun sütunlarını toplarız:

$$p_Y(0) = 0.20 + 0.20 = 0.40$$

$$p_Y(1) = 0.20 + 0.10 = 0.30$$

$$p_Y(2) = 0.05 + 0.10 = 0.15$$

$$p_Y(3) = 0.05 + 0.10 = 0.15$$

| $y$ | 0 | 1 | 2 | 3 |
| :---: | :---: | :---: | :---: | :---: |
| $p_Y(y)$ | 0.40 | 0.30 | 0.15 | 0.15 |

Hoca sağlama da yaptı: Bu olasılıkların toplamı beklendiği gibi $1$'dir.

### 2.4 b) Bağımsızlık

Bağımsız olmaları için bütün $x, y$ değerlerinde $p_{X,Y}(x,y) = p_X(x)\,p_Y(y)$ olmalıdır. Hepsi tabloda bulunduğu için hücrelere tek tek bakabiliriz.

İlk hücre $(0,0)$ için $p_{X,Y}(0,0) = 0.20$ ve $p_X(0)\,p_Y(0) = 0.50 \cdot 0.40 = 0.20$. Bu hücre uyuyor. Ama eşitlik bütün değerler için sağlanmalı, bir sonraki hücreye geçiyoruz.

$(0,1)$ için $p_{X,Y}(0,1) = 0.20$, oysa $p_X(0)\,p_Y(1) = 0.50 \cdot 0.30 = 0.15$. $0.15 \neq 0.20$ olduğundan bu ikisi bağımsız değildir.

> **Hocanın vurgusu:** Bağımsız olmadığını kanıtlamak için tek bir aykırı örnek vermek yeter.

> **Ek bilgi (derste anlatılmadı):** Derste yalnızca ilk iki hücreye bakıldı. Bütün hücreler python ile hesaplandı: Eşitlik sekiz hücreden yalnız $(0,0)$ ve $(1,0)$'da sağlanıyor. Yani birkaç hücrenin tutması bağımsızlığa yetmez, bu yüzden "bütün değerler için" şartı önemlidir.

Hoca ardından bir sonucu bulmanın yetmediğini söyledi. Sınavda ya da bir raporda kendinizi açıkça ifade edebilmelisiniz ki herkes anlayabilsin. Cevabı şöyle yazdı:

- $X$ ve $Y$'nin bağımsız olduğunu, çelişki elde etmek için varsayalım.
- Fakat $x = 0$, $y = 1$ için $p_{X,Y}(0,1) \neq p_X(0)\,p_Y(1)$'dir.
- Bir çelişkiye ulaştık.
- O halde $X$ ve $Y$ bağımsız değildir.

Yani önce bağımsız olduklarını varsayıyoruz, $x = 0$ ve $y = 1$ alıyoruz, bağımsızlık kuralıyla çeliştiğini gösteriyoruz ve çelişki olduğu için bağımsız olmadıkları sonucuna varıyoruz.

> **Ders sonrası not:** Hoca anlatırken iki kez "bağımsız olduklarını kanıtlayacağız/kanıtladık" dedi, ikincisinde hemen "bağımsız değil" diye düzeltti. Doğrusu, $X$ ve $Y$'nin bağımsız **olmadığının** kanıtlandığıdır.

### 2.5 Bir Soruya Cevap Yazma Düzeni

Hoca varyans hesabına geçerken Türkçe olarak, bir soruya nasıl cevap yazılması gerektiğini anlattı. Dört aşamalı bir cevap istiyor:

1. Aranan şeyi yazın.
2. Denklemini yazın.
3. Denklemdeki nesnelerin hangi sayılar olduğunu gösterin, sayıları yerine koyun.
4. Sonucu yazın.

Yalnızca sayılar yazıp sonuca atlamak, denklem yazmadan sonuç vermek ya da denklemi yazıp sayıları yerine koymadan sonuca geçmek bu düzene uymaz.

> **Hocanın vurgusu:** Denklemi bir şıkta gösterip diğer şıkta yazmamak yeterli değildir. Her şık için kullanacağınız denklemi yazıp göstermeniz gerekir.

### 2.6 c) Beklenen Değerler ve Varyanslar

Varyans denkleminde ortalama geçtiği için önce beklenen değerleri buluyoruz. Marjinal dağılımlardan:

$$E[X] = \sum_{x=0}^{1} x\,p_X(x) = 0 \cdot 0.5 + 1 \cdot 0.5 = 0.5$$

$$E[Y] = \sum_{y=0}^{3} y\,p_Y(y) = 0 \cdot 0.40 + 1 \cdot 0.30 + 2 \cdot 0.15 + 3 \cdot 0.15 = 0.30 + 0.30 + 0.45 = 1.05$$

$X$'in varyansını birinci denklemle buluyoruz. Bütün olası değerler için $(x-\mu)^2$ ile o değerin olasılığı çarpılır:

$$\mathrm{Var}(X) = \sum_{x=0}^{1} (x - 0.5)^2\,p_X(x) = (0 - 0.5)^2 \cdot 0.5 + (1 - 0.5)^2 \cdot 0.5 = 0.125 + 0.125 = 0.25$$

> **Ders sonrası not:** Hoca burada kareleri olasılıklarla çarpmayı unutarak $0.25 + 0.25 = 0.5$ yazdı ve $\mathrm{Var}(X) = 0.5$ buldu. Hatayı dersin ilerleyen yerinde bir öğrenci sorunca kabul etti. Doğrusu $0.25$'tir. İkinci denklem de aynı sonucu verir: $E[X^2] - \mu^2 = 0.5 - 0.25 = 0.25$ (python ile hesaplandı).

$Y$'nin varyansında alternatif denklemi kullanıyoruz:

$$\mathrm{Var}(Y) = E[Y^2] - \mu_Y^2 = \sum_{y=0}^{3} y^2\,p_Y(y) - 1.05^2$$

Toplamın terimleri $0^2 \cdot 0.40 = 0$, $1^2 \cdot 0.30 = 0.30$, $2^2 \cdot 0.15 = 0.60$ ve $3^2 \cdot 0.15 = 1.35$'tir. Hoca $1.05$'in karesini hesap makinesiyle $1.1025$ buldu:

$$\mathrm{Var}(Y) = 0.30 + 0.60 + 1.35 - 1.1025 = 2.25 - 1.1025 = 1.1475$$

> **Ders sonrası not:** Hoca ilk denemede toplamı yanlış yaptı. Kitaba bakınca kitabın $1.1475$ verdiğini gördü, bir hata olduğunu söyledi. Bir öğrencinin uyarısıyla doğru sonuca geçti. Doğru değer $1.1475$'tir (python ile hesaplandı).

<!-- BELİRSİZ: 01:15:29'da hocanın ilk denemede bulduğu yanlış değer altyazıda okunmuyor. -->

### 2.7 d) Korelasyon Katsayısı

Korelasyon katsayısı için önce kovaryans gerekir. Hoca kovaryansın iki denklemini yan yana hatırlattı. Birincisi $E[(X-\mu_X)(Y-\mu_Y)]$, işin mantığını ve sezgisini gösterir. İkincisi $E[XY] - \mu_X\mu_Y$, hesap için daha kolaydır. Bu yüzden ikincisini kullanıyoruz.

$E[XY]$'de iki rastgele değişken olduğu için iki toplam alınır: bütün $x$'ler ve bütün $y$'ler üzerinden. Toplanan şey $x\,y$ çarpı olasılıktır. Hem $x$ hem $y$ olduğu için bu olasılık **birleşik** olasılıktır:

$$E[XY] = \sum_x \sum_y x\,y\,p_{X,Y}(x,y)$$

Yani bütün tablonun üzerinden geçmek gerekir. İlk satırda $x = 0$, ilk sütunda $y = 0$ olduğu için oradaki bütün terimler sıfırdır. Sıfır olmayan yalnızca üç terim kalır ve olasılıklarının üçü de $0.10$'dur:

$$E[XY] = 1 \cdot 1 \cdot 0.10 + 1 \cdot 2 \cdot 0.10 + 1 \cdot 3 \cdot 0.10 = 0.10 + 0.20 + 0.30 = 0.60$$

$$\mathrm{Cov}(X,Y) = E[XY] - \mu_X\mu_Y = 0.60 - 0.5 \cdot 1.05 = 0.60 - 0.525 = 0.075$$

Korelasyon katsayısı kovaryansın standart sapmalara bölünmesidir. Standart sapmalar varyansların kareköküdür:

$$\rho(X,Y) = \frac{\mathrm{Cov}(X,Y)}{\sigma_X\,\sigma_Y} = \frac{0.075}{\sqrt{0.25}\,\sqrt{1.1475}} = \frac{0.075}{0.5 \cdot 1.0712} \approx 0.140$$

> **Ders sonrası not:** Hoca $0.60$'ı bulunca "kovaryans bu" dedi ve korelasyon denklemine koydu. Bir öğrenci söz alınca $\mu_X\mu_Y$'yi çıkarmayı unuttuğunu fark edip düzeltti. $0.60$, $E[XY]$'dir; kovaryans $0.075$'tir. Ayrıca paydada $\sqrt{0.5}$ kullandı, bu yüzden sonuç hatalı çıktı. Hoca bir hesap hatası olduğunu tahtaya not etti. Doğru $\mathrm{Var}(X) = 0.25$ ile $\rho \approx 0.140$ çıkar (python ile hesaplandı).

Hoca sonucu şöyle yorumladı: Bu iki değişken arasında bir korelasyon var, ama büyük değil. Sıfır da değil. En büyük korelasyon $1$, en küçük korelasyon $-1$ olabilir. Bulduğumuz değer sıfıra çok yakın göründüğü için korelasyon çok zayıftır.

> **Ders sonrası not:** Hoca burada "en küçük değer aslında sıfır" dedi, ardından "en küçük pozitif korelasyon sıfırdan büyük herhangi bir değerdir" diye açtı. Korelasyonun aralığı $-1$ ile $1$ arasıdır. Sıfıra yakın olması en küçük olması demek değildir, zayıf ilişki demektir.

**Soru:** Yukarıda $\mathrm{Var}(X)$'i bulduğumuz yerde kare ile ilgili bir şey sorabilir miyim?

**Cevap:** Evet, orada öyle bir hatamız olmuş. Sonuçtaki uyuşmazlık sanırım oradan geliyor. Genel mantığı anladınız, bu şekilde devam ettiğinizde yapmanız gerekir.

<!-- BELİRSİZ: 01:26:47-01:27:39 ve 01:29:45-01:30:22 altyazısı bozuk. Hocanın ekranda bulduğu korelasyon değeri ile kitapla karşılaştırması ve öğrencinin sorusunun tam metni okunmuyor. Python ile hesaplandı: hocanın kullandığı 0.5 ile bu değer yaklaşık 0.099 olur. -->

## 3. Chebyshev Eşitsizliği

### 3.1 Eşitsizlik

Chebyshev şu eşitsizliği kanıtlamıştır. $X$ rastgele değişkeni ile ortalamasının farkının mutlak değerinin bir $\varepsilon$ değerinden büyük olması olayının olasılığı, varyansın $\varepsilon^2$'ye bölümünden küçük ya da ona eşittir:

$$P\left(|X - \mu| > \varepsilon\right) \le \frac{\sigma^2}{\varepsilon^2}$$

Burada $\mu = E[X]$, $\sigma^2 = \mathrm{Var}(X)$'tir. $\varepsilon$'a, elimizdeki probleme göre biz bir değer veririz. Eşitsizlik böylece bu olayın olasılığına bir sınır koyar. Kanıtı dersin kitabında, Baron'un kitabında bulabilirsiniz.

> **Hocanın vurgusu:** Chebyshev eşitsizliği herhangi bir rastgele değişken için geçerlidir.

> **Ek bilgi (derste anlatılmadı):** Kitaplarda bu eşitsizlik büyük olasılıkla $P(|X-\mu| \ge \varepsilon) \le \sigma^2/\varepsilon^2$ biçiminde de karşınıza çıkar. Dersteki "$>$" biçimi bununla çelişmez. $|X-\mu| > \varepsilon$ olayı, $|X-\mu| \ge \varepsilon$ olayının içindedir, bu yüzden olasılığı daha büyük olamaz.

### 3.2 Yazılımdaki Hata Sayısı Örneği

Yeni bir yazılımdaki hata sayısının beklenen değeri $20$, standart sapması $2$ olsun. $30$'dan fazla hata olma olasılığına bir sınır bulmak istiyoruz.

Bu olasılığı doğrudan hesaplayamayız, çünkü $X$'in olasılık kütle fonksiyonunu bilmiyoruz. Ama beklenen değeri ve varyansı biliyoruz, dolayısıyla Chebyshev eşitsizliğiyle bu olasılık hakkında akıl yürütebiliriz.

$X$ hata sayısı olsun. Verilenler $\mu = 20$ ve $\sigma = 2$, yani $\sigma^2 = 4$. Eşitsizliğe koyunca geriye yalnız $\varepsilon$ kalır:

$$P\left(|X - 20| > \varepsilon\right) \le \frac{4}{\varepsilon^2}$$

Hangi $\varepsilon$ bu soruya uygundur? Burada ortalamadan farkı $\varepsilon$ ile karşılaştırıyoruz, yani $\varepsilon$ aslında ortalamadan uzaklıktır. Ortalama $20$, soruda geçen değer $30$ olduğu için:

$$\varepsilon = 30 - \mu = 30 - 20 = 10$$

$$P\left(|X - 20| > 10\right) \le \frac{4}{10^2} = \frac{4}{100} = 0.04$$

### 3.3 Sonucun Anlamı

Hoca sonucu sayı doğrusu üzerinde çizerek açıkladı. Ortalamadan sağa $\varepsilon = 10$ gidince $30$'a varırız. Zaten $\varepsilon$'u $30$'a ulaşmak için seçmiştik. Aynı miktar sola gidince $10$'a varırız. Mutlak değerli olay, $X$'in bu iki noktanın dışında kalmasıdır:

```text
   taralı bölge                                  taralı bölge
<--------------- 10 --------- 20 --------- 30 --------------->  X
                 |<-- 10 ---> | <-- 10 --->|
```

Yani $0.04$ sınırı, $X < 10$ ve $X > 30$ bölgelerinin **ikisinin toplamı** içindir. Oysa bize sorulan yalnız sağdaki bölgedir. Sağ bölge ile sol bölgenin toplam olasılığı $0.04$'ten küçük ya da eşitse, yalnız sağ bölgenin olasılığı da $0.04$'ten küçük ya da eşittir. Sol bölgenin olasılığını da bilmediğimiz için sınırı daha fazla daraltamayız. Söyleyebileceğimiz en iyi şey şudur:

$$P(X > 30) \le 0.04$$

> **Ders sonrası not:** Hoca sınırı ekranda sırayla "$0.25$", "$0.05$" ve son satırda "$0.004$" diye okudu. Öğrencilerin de katıldığı bu karışıklığın arasında "$0.04$" da söylendi. Doğru değer $4/100 = 0.04$'tür (python ile hesaplandı).

Chebyshev'in güzel yanı, olasılıklara sınır koymamıza yardım etmesi ve her tür rastgele değişken için geçerli olmasıdır. Rastgele değişkenin olasılık kütle fonksiyonunu biliyorsanız çok daha iyi hesaplar yapabilirsiniz. Ama hiç bilmiyorsanız, elinizde yalnız ortalama ve varyans varsa, Chebyshev eşitsizliği size yine bir fikir verir.

**Soru:** $\varepsilon$'u hesaplarken neden $30$'dan ortalamayı çıkardık?

**Cevap:** Chebyshev denklemi $X - 20$ farkını $\varepsilon$ ile karşılaştırıyor. Biz $X$'in $30$'dan büyük olması durumunu merak ediyoruz. $X > 30$ demek $X - 20 > 30 - 20$ demektir. Demek ki Chebyshev denklemine koyarken $\varepsilon$'u $30 - 20 = 10$ almamız gerekir.

## 4. Yaygın Kesikli Dağılımlar ve Bernoulli Dağılımı

Hoca bu kısımda yaygın kesikli dağılımları görmeye başladığımızı söyledi. Bunlar kesikli dağılım aileleridir ve en çok karşılaşılan olasılık dağılımlarıdır. Beş tanesi görülecek:

- Bernoulli dağılımı
- Binom dağılımı (binomial distribution)
- Geometrik dağılım
- Negatif binom dağılımı
- Poisson dağılımı

Her biri için ne zaman kullanıldığına, olasılık dağılım fonksiyonuna, beklenen değerine, varyansına ve kümülatif olasılık dağılımına bakılacak.

### 4.1 Bernoulli Denemesi

Bernoulli denemesi (Bernoulli trial), iki çıktılı bir olasılıksal denemedir. Hocanın örnekleri şunlardı:

- Para atışı: Yazı ya da tura.
- Yeni doğan bir bebeğin cinsiyeti: Kız ya da erkek.
- Bir dersi geçmek: Geçersiniz ya da geçemezsiniz.
- Yüz yaşından fazla yaşamak: Yaşarsınız ya da yaşamazsınız.

### 4.2 Bernoulli Değişkeni ve Dağılımı

Bernoulli denemesinin çıktılarını $0$ ve $1$'e götüren rastgele değişkene Bernoulli değişkeni, bu değişkenin dağılımına da Bernoulli dağılımı denir. Deney ne olursa olsun onu hep $0$ ve $1$ olarak düşünürüz. Hocanın örneğinde bebek erkekse $X = 0$, kızsa $X = 1$ olabilir.

> **Ders sonrası not:** Hoca İngilizce anlatımda çıktıları $0$ ve $1$'e götüren şeyin "Bernoulli dağılımı" olduğunu söyledi. Türkçe tekrarında bunu doğru söyledi: Çıktıları sayıya götüren fonksiyon rastgele değişkendir, dağılım ise o değişkenin dağılımıdır.

Genellikle iki çıktıdan birine başarı (success), diğerine başarısızlık (failure) denir. Hoca bu adlandırmanın önemli olmadığını söyledi. Hangi çıktıya $1$ dendiği, modeli kurarken yapılan bir seçimdir ve sonucu değiştirmez.

<!-- BELİRSİZ: 02:23:11-02:25:28 altyazısı bozuk. Hoca bebek örneği üzerinden hangi çıktıya "başarı" denmesi gerektiğini öğrencilerle konuşuyor; ayrıntılar okunmuyor, yalnız sonucun değişmediği ve bunun bir model seçimi olduğu anlaşılıyor. -->

$X$ yalnız $0$ ve $1$ değerlerini alabilir. $1$ gelmesinin olasılığına küçük $p$ diyelim. Olasılıkların toplamı $1$ olması gerektiği için $0$ gelmesinin olasılığı $1 - p$'dir. Bazı kitaplar buna $q$ der. Denklem yazarken $q$ yazmak bazen daha kolaydır, ama $q$ yalnızca $1 - p$'dir.

| $x$ | 0 | 1 |
| :---: | :---: | :---: |
| $P(X = x)$ | $1 - p = q$ | $p$ |

$p$ probleme göre değişir. Örneğin kız ya da erkek probleminde $p = 0.5$'tir.

Kısa gösterim olarak şöyle yazarız:

$$X \sim \mathrm{Bernoulli}(p)$$

Bu, "$X$, $p$ parametreli Bernoulli dağılımı ile dağılır" (X is distributed by Bernoulli distribution with parameter p) demektir. Tek parametresi $p$'dir. $p$'yi bilirseniz beklenen değerini ve varyansını da bilirsiniz.

### 4.3 Beklenen Değer ve Varyans

Beklenen değer denklemini iki olası değer için yazarız:

$$E[X] = \sum_{x=0}^{1} x\,P(X=x) = 0 \cdot (1-p) + 1 \cdot p = p$$

Varyans için alternatif denklemi kullanıyoruz. $\mu$'yü az önce $p$ bulmuştuk:

$$\mathrm{Var}(X) = E[X^2] - \mu^2 = \sum_{x=0}^{1} x^2\,P(X=x) - p^2 = 0^2 \cdot (1-p) + 1^2 \cdot p - p^2$$

$$\mathrm{Var}(X) = p - p^2 = p(1-p) = pq$$

Hoca Bernoulli'yi olasılık dağılımlarının en basiti olarak tanımladı ve bu yüzden üzerinde fazla durmadı.

## 5. Binom Dağılımı

### 5.1 Tanım ve Gösterim

Binom dağılımı, bağımsız Bernoulli denemelerinden oluşan bir dizideki başarı sayısını verir. $n$ tane Bernoulli denemesi yaparsınız, bunların kaç tanesinin başarılı olduğu binom rastgele değişkenidir. Buradaki Bernoulli denemesinin örneklem uzayı başarı ve başarısızlıktan oluşur. Bernoulli dağılımında olduğu gibi başarı $1$'e, başarısızlık $0$'a götürülür.

Binom dağılımının iki parametresi vardır:

- $n$: Deneme sayısı.
- $p$: Her Bernoulli denemesindeki başarı olasılığı.

"$X$, $n$ ve $p$ parametreli binom dağılımıyla dağılır" cümlesinin tamamını yazmak yerine kısaca şöyle yazarız:

$$X \sim \mathrm{Binomial}(n, p)$$

Binom dağılımının olasılık kütle fonksiyonu şöyledir:

$$P(X = x) = \binom{n}{x}\,p^x\,(1-p)^{n-x}$$

Kaynaklarda farklı gösterimlerle karşılaşabilirsiniz. Bazen parametreler değerden sonra yazılır, bazen zaten binom dağılımından söz edildiği için hiç yazılmaz. Şu gösterimlerin hepsi aynı şeydir:

- $P(x)$
- $P(x; n, p)$
- $\mathrm{binomial}(x; n, p)$
- $B(x; n, p)$

### 5.2 Hedefe Atış Örneği

Hoca binomu Türkçe olarak bir örnekle anlattı. Elinizde bir oyuncak tabanca var, karşıya bir hedef tahtası diktiniz. Her atışta hedefi vurup vurmamak bir Bernoulli denemesidir: Vurursanız başarı ($1$), vuramazsanız başarısızlık ($0$). 5 atış hakkınız var. 5 atışta 3 kez vurma olasılığınız nedir? Binom dağılımı bunu verir.

Bu hesap için $n = 5$ ve $x = 3$'tür. Ama atışı yapan kişinin ne kadar iyi nişancı olduğunu da söylememiz gerekir. Hoca kendisi ile tecrübeli bir subayın aynı hedefi farklı olasılıklarla vuracağını söyledi. Bunu her Bernoulli denemesindeki başarı parametresi $p$ ile ifade ederiz. Hoca, yakın bir hedef için $p = 0.6$ olduğunu varsaydı: 10 kez atarsa 6 tanesini vurmasını bekliyoruz.

Soru şöyle: Bir hedefe 5 kez atış yapılıyor. Tek atışta isabet olasılığı $0.6$'dır. Tam 3 kez isabet etme olasılığı nedir?

$$p = 0.6, \qquad 1 - p = 0.4, \qquad n = 5, \qquad x = 3$$

$$P(X = 3) = \binom{5}{3}\,0.6^3\,(1 - 0.6)^{5-3} = \binom{5}{3}\,0.6^3\,0.4^2$$

Hoca denklemi kurmakla yetindi. Sayısal sonuç şöyledir (ara adım eklendi, python ile hesaplandı):

$$P(X = 3) = 10 \cdot 0.216 \cdot 0.16 = 0.3456$$

### 5.3 PMF Denklemi Nereden Geliyor?

Hoca bu denklemin, üzerinde düşününce zor olmadığını söyledi. Beş atış yapacağız. Her biri başarı ($B$) ya da başarısızlık ($F$) olabilir. Bizi 3 başarı ilgilendiriyor. Bu 3 başarı değişik sıralarda gelebilir:

- $B\,B\,B\,F\,F$
- $B\,F\,F\,B\,B$
- ve benzerleri.

Bu sıralamalardan $\binom{5}{3}$ tane vardır. Her birinin olasılığı aynıdır. Başarılı atışların her birinin olasılığı $0.6$ olduğundan 3 başarıdan $0.6^3$ gelir. Kalan iki atış başarısızlıktır, her birinin olasılığı $1 - 0.6 = 0.4$ olduğundan $0.4^2$ gelir.

Genel denklemin üç parçası böylece anlam kazanır:

- $\binom{n}{x}$: Farklı sıralamaların sayısı.
- $p^x$: $x$ başarının olasılığı.
- $(1-p)^{n-x}$: $n - x$ başarısızlığın olasılığı.

### 5.4 Beklenen Değer ve Varyans

Bir binom değişkeni, tek tek Bernoulli değişkenlerinin toplamı olarak yazılabilir:

$$X = X_1 + X_2 + \dots + X_n$$

$X_1$ birinci Bernoulli denemesinin, $X_2$ ikinci denemenin rastgele değişkenidir, böyle devam eder. İlk deneme başarılıysa $X_1 = 1$, son deneme başarısızsa $X_n = 0$ olur. Bunları topladığınızda başarı sayısını, örneğin $3$'ü elde edersiniz.

Her iki tarafın beklenen değerini alırız. Toplamın beklenen değeri terimlerin beklenen değerlerinin toplamıdır:

$$E[X] = E[X_1] + E[X_2] + \dots + E[X_n]$$

Bu Bernoulli denemeleri özdeştir, yani parametreleri aynıdır. Bir Bernoulli değişkeninin ortalaması $p$ olduğu için her terim $p$'dir. $n$ tane terim olduğundan:

$$E[X] = np$$

Burada yapılan varsayımın bir adı var: IID (independent and identically distributed), yani bağımsız ve özdeş dağılımlı. Denemeler bağımsızdır, ortalamaları ve parametreleri aynıdır.

Hoca bunun bir varsayım olduğunu da belirtti. Gerçek hayatta 5 kez atış yaparken daha iyi kestirim yapabildiğim için isabet olasılığım normalde artar. Ama burada atış yaptıkça olasılığın aynı kaldığını, denemelerin bağımsız ve özdeş olduğunu varsayıyoruz.

Varyans da benzer şekilde hesaplanır. Tekrarda gördüğümüz özelliğe göre $X$ ve $Y$ bağımsızsa $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$ yazılabilir. Denemeler bağımsız olduğu için bu özellik kullanılır. Her Bernoulli değişkeninin varyansı $pq$ olduğundan bunları toplarız:

$$\mathrm{Var}(X) = npq$$

## 6. Quiz Sorusunun Çözümü

Hoca dersin sonunda quiz sorusunu Türkçe olarak çözdü. Şu birleşik olasılıklar veriliyor:

| | $B_1$ | $B_2$ |
| :---: | :---: | :---: |
| $A_1$ | 0.2 | 0.1 |
| $A_2$ | 0.1 | 0.2 |
| $A_3$ | 0.1 | 0.3 |

<!-- BELİRSİZ: 02:54:50-02:55:14 arasında öğrencilerin soruyu anlatma konuşması var, sorunun tam metni okunmuyor. Tablo, hocanın 02:55:40-02:56:10'da okuduğu değerlerden kuruldu. -->

### 6.1 a) $A_i$ Olasılıkları

Burada toplam olasılık (total probability) kullanılır. $A_1$'in olasılığını bulmak için $A_1$'in bütün $B_i$'lerle kesişimlerini toplarız:

$$P(A_1) = \sum_{i=1}^{2} P(A_1 \cap B_i) = 0.2 + 0.1 = 0.3$$

Benzer şekilde:

$$P(A_2) = 0.1 + 0.2 = 0.3, \qquad P(A_3) = 0.1 + 0.3 = 0.4$$

> **Hocanın vurgusu:** Hoca burada yine aranan şeyi, denklemi, denkleme konan sayıları ve sonucu görmek istediğini söyledi. Bu dört şeyi $A_1$ için gösterdiği gibi yazmak gerekir.

**Soru:** Toplam sembolü yerine sembolik yazıp toplamı açık şekilde yazsak olur mu?

**Cevap:** Olur.

**Soru:** Venn şemasıyla yapıp değerleri yerine koyarak toplasak kabul edilir mi?

**Cevap:** Venn şeması da kabul edilir.

### 6.2 b) $B_j$ Olasılıkları

Aynı mantıkla, bu kez $B_j$'nin bütün $A_i$'lerle kesişimlerini toplarız (ara adım eklendi):

$$P(B_1) = \sum_{i=1}^{3} P(A_i \cap B_1) = 0.2 + 0.1 + 0.1 = 0.4$$

$$P(B_2) = \sum_{i=1}^{3} P(A_i \cap B_2) = 0.1 + 0.2 + 0.3 = 0.6$$

### 6.3 c) Şartlı Olasılıklar

Bunlar doğrudan şartlı olasılığın tanımından gelir:

$$P(A_1 \mid B_1) = \frac{P(A_1 \cap B_1)}{P(B_1)} = \frac{0.2}{0.4} = 0.5$$

$$P(A_2 \mid B_1) = \frac{P(A_2 \cap B_1)}{P(B_1)} = \frac{0.1}{0.4} = 0.25$$

### 6.4 d) $A_1$ Verildiğinde Şartlı Olasılıklar

Bir kümenin kendisiyle kesişimi kendisidir:

$$P(A_1 \mid A_1) = \frac{P(A_1 \cap A_1)}{P(A_1)} = \frac{P(A_1)}{P(A_1)} = 1$$

Sonucu yalnızca "1" diye yazmak yerine bu adımları göstermek gerekir. İkincisinde $A_2$ ile $A_1$'in kesişimi boş kümedir, çünkü $A_1$, $A_2$, $A_3$ bir deneyin çıktılarıdır ve çıktılar ayrıktır. Boş kümenin olasılığı $0$'dır:

$$P(A_2 \mid A_1) = \frac{P(A_2 \cap A_1)}{P(A_1)} = \frac{P(\emptyset)}{P(A_1)} = 0$$

### 6.5 $A$ ve $B$ Bağımsız mı?

Hoca bu soruda bugün gördüğümüz çelişki yöntemini kullanmak gerektiğini söyledi. $A$ ve $B$'nin bağımsız olduğunu, çelişki elde etmek için varsayalım. O zaman bütün $i, j$ için şu eşitlik sağlanmalıdır:

$$P(A_i \cap B_j) = P(A_i)\,P(B_j)$$

Üç tane $A$, iki tane $B$ olduğu için altı durum vardır ve eşitlik altısında da sağlanmalıdır. Sağlamayan tek bir örnek bulursak çelişkiye ulaşırız. $A_1$ ve $B_1$ için:

$$P(A_1)\,P(B_1) = 0.3 \cdot 0.4 = 0.12 \neq 0.20 = P(A_1 \cap B_1)$$

Bir çelişkiye ulaştık. O halde $A$ ve $B$ bağımsız değildir.

<!-- BELİRSİZ: 03:03:18-03:03:28 ve 03:06:24-03:08:14 altyazısı bozuk. Bu kısımda çözüm üzerine bir konuşma var, içeriği okunmuyor. -->

## Dersin Toparlaması

Bu derste önce rastgele vektörlerle ilgili bütün araçları tek bir sayısal örnekte kullandık: birleşik dağılım tablosundan marjinal dağılımları çıkardık, tek bir aykırı hücreyle bağımsız olmadığını gösterdik, varyansları ve kovaryansı hesaplayıp zayıf bir pozitif korelasyon bulduk. Ardından Chebyshev eşitsizliğini gördük. Bu eşitsizlik, PMF bilinmese bile yalnız ortalama ve varyansla her rastgele değişkenin olasılıklarına sınır koymamızı sağlıyor.

Sonra yaygın kesikli dağılımlara girdik. İki çıktılı denemenin modeli olan Bernoulli dağılımının ortalamasını $p$, varyansını $pq$ bulduk. Binom dağılımını bağımsız ve özdeş Bernoulli denemelerinin toplamı olarak kurup PMF'ini sıralama sayısından açıkladık, $E[X] = np$ ve $\mathrm{Var}(X) = npq$ sonuçlarını Bernoulli'den elde ettik. Hoca sonraki derste geometrik dağılımla devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
