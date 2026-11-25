# Ders 15 Genişletilmiş Notu: Karışık Rastgele Değişkenler, Dirac Delta ve Ortak Dağılımlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Karışık Rastgele Değişkenler
- 2. Karışık Değişkenin Sürekli ve Kesikli Parçaları
- 3. Dirac Delta Fonksiyonu
- 4. Genelleştirilmiş Olasılık Yoğunluk Fonksiyonu
- 5. İki Kesikli Rastgele Değişkenin Ortak Dağılımı
- 6. İki Sürekli Rastgele Değişkenin Ortak Dağılımı
- 7. Kovaryans ve Korelasyon
- Örnek Sorular

## 1. Karışık Rastgele Değişkenler

Ders, sürekli rastgele değişkenlerin son konusu olarak karışık (mixed) rastgele değişkenlerle başladı. Hoca önce iki tanıdık türün kümülatif dağılım fonksiyonlarını (CDF) yan yana çizdi (ekrandan, 00:10:00).

- Kesikli rastgele değişkenin CDF'i bir noktaya kadar 0'dır, sonra bir sıçrama (jump) yapar, bir sonraki değere kadar sabit kalır, orada yine sıçrar. Grafik basamaklıdır.
- Sürekli rastgele değişkenin CDF'i 0'dan başlar, artar (bu artış doğrusal olabilir ya da olmayabilir) ve bir noktada 1'e ulaşır. Grafikte hiç sıçrama yoktur.
- Karışık rastgele değişkenin CDF'i ikisinin karışımıdır: sürekli bir değişkenmiş gibi artarak başlayabilir, ama bir ya da daha fazla noktada sıçrar.

Hocanın vurguladığı ayrım şudur: karışık değişkenin CDF'inde kesikli değişkendeki gibi sıçramalar vardır, ama kesikli değişkenden farklı olarak CDF sıçramalar arasında sabit kalmaz, değişebilir.

### 1.1 Örnek: sürekli bir değişkenden elde edilen karışık değişken

Hoca tanımı bir örnekle somutlaştırdı (ekrandan, 00:10:00 ve 00:15:00). $X$ sürekli bir rastgele değişken ve yoğunluğu

$$f_X(x) = \begin{cases} 2x, & 0 \le x \le 1 \\ 0, & \text{diğer} \end{cases}$$

olsun. $Y$ de $X$'in bir fonksiyonu olsun:

$$Y = g(X) = \begin{cases} X, & 0 \le X \le \tfrac12 \\ \tfrac12, & X > \tfrac12 \end{cases}$$

İstenen, $Y$'nin CDF'idir.

**Adım 1: $Y$'nin değer aralığı.** $R_Y = \{g(x) \mid x \in R_X\}$ ve $R_X = [0,1]$. Hoca $[0,1]$ aralığını $g$'nin tanımındaki kırılma noktasına göre $[0, \tfrac12]$ ve $(\tfrac12, 1]$ diye ikiye ayırdı. $X$ ilk parçadayken $Y = X$ olduğundan $Y$ değerleri $0$ ile $\tfrac12$ arasındadır. $X$ ikinci parçadayken $Y$ hep $\tfrac12$'de kalır. Böylece $R_Y = [0, \tfrac12]$ bulunur.

**Adım 2: Uç bölgeler.** CDF, $Y$'nin en küçük değeri olan 0'ın altında 0, en büyük değeri olan $\tfrac12$'de ve üstünde 1'dir.

**Adım 3: $y = \tfrac12$ noktası.** Burada ilginç bir durum vardır: $X$'in bütün bir aralığı ($\tfrac12 < X \le 1$) tek bir $Y$ değerine, $\tfrac12$'ye gider. Bu yüzden $P(Y = \tfrac12)$ sıfır değildir. $X$ sürekli ve yoğunluğu bilindiği için bu olasılık bir integralle bulunur. Üst sınır sonsuz yerine 1 alınır, çünkü $X$ en fazla 1 olabilir (ekrandan, 00:25:00):

$$P(Y = \tfrac12) = P(X > \tfrac12) = \int_{1/2}^{1} 2x\,dx = 1 - \tfrac14 = \tfrac34.$$

**Adım 4: $0 \le y < \tfrac12$ aralığı.** Bu aralıkta $Y = X$ olduğu için

$$F_Y(y) = P(Y \le y) = P(X \le y) = \int_0^y 2x\,dx = y^2.$$

İntegralin alt sınırı $-\infty$ yerine 0'dır, çünkü $X$'in yoğunluğu 0'dan önce sıfırdır. Aralığın sol ucunda eşitlik olup olmaması önemli değildir: bu parça süreklidir, tek bir noktanın olasılığı ($P(0)$) sıfırdır.

**Sonuç:**

$$F_Y(y) = \begin{cases} 0, & y < 0 \\ y^2, & 0 \le y < \tfrac12 \\ 1, & y \ge \tfrac12 \end{cases}$$

### 1.2 Grafik ve sınıflandırma

Hoca bu CDF'i çizdi (ekrandan, 00:30:00). $y < 0$ için değer 0'dır. $0$ ile $\tfrac12$ arasında $y^2$ ikinci derece eğrisi yükselir; $y = \tfrac12$'de $(\tfrac12)^2 = \tfrac14$ değerine ulaşır. $\tfrac12$ bu parçaya dahil olmadığı için eğri orada içi boş bir noktada biter. $y = \tfrac12$'de olasılık 1'e sıçrar ve sonra 1'de sabit kalır.

Sıçrama miktarı $1 - \tfrac14 = \tfrac34$'tür; bu, Adım 3'te bulunan $P(Y = \tfrac12)$ ile aynıdır.

> **Ders sonrası not:** Hoca sıçrama miktarını söylerken önce "1 minus 1 over 2, 3 over 2" dedi (00:26:18), hemen ardından "3 over 4" diye düzeltti. Doğrusu $1 - \tfrac14 = \tfrac34$'tür.

Tahtadaki sonuç şudur: $Y$ karışık bir rastgele değişkendir, çünkü CDF grafiğinde sıçrama vardır ve sıçrama dışında sabit olmayan (artan) bir bölümü olduğu için kesikli bir değişken değildir.

## 2. Karışık Değişkenin Sürekli ve Kesikli Parçaları

$Y$ karışık bir rastgele değişkense CDF'i iki parçanın toplamı olarak yazılabilir (ekrandan, 00:40:00):

$$F_Y(y) = C(y) + D(y)$$

Burada $C(y)$ CDF'in sürekli parçası, $D(y)$ kesikli parçasıdır.

### 2.1 Örnekte parçalara ayırma

Önceki örneğin grafiğinde sürekli parça, 0'dan başlayıp $y^2$ biçiminde yükselen bölümdür. Sürekli parçada sıçrama olmamalıdır; bu yüzden $y \ge \tfrac12$ için $C$, ulaştığı son değer olan $\tfrac14$'te sabit devam eder:

$$C(y) = \begin{cases} 0, & y < 0 \\ y^2, & 0 \le y < \tfrac12 \\ \tfrac14, & y \ge \tfrac12 \end{cases}$$

Kesikli parça, sıçramanın oluşturduğu sabit bölümdür. $\tfrac12$'ye kadar 0'dır. Sürekli parça $\tfrac14$'te kaldığına göre 1'e ulaşmak için $\tfrac34$ gerekir; bu yüzden $\tfrac12$'den sonra $D$ sabit $\tfrac34$'tür:

$$D(y) = \begin{cases} 0, & y < \tfrac12 \\ \tfrac34, & y \ge \tfrac12 \end{cases}$$

### 2.2 Sürekli parçanın türevi ve toplam olasılık

Hoca sürekli parçanın türevini küçük harfle tanımladı:

$$c(y) = \frac{dC(y)}{dy}$$

Bu fonksiyon bir olasılık yoğunluğuna çok benzer, ama yoğunluk değildir; çünkü tek başına integrali 1 etmez. $\{y_1, y_2, y_3, \dots\}$, $D(y)$'nin sıçrama noktaları, yani $P(Y = y_k) > 0$ olan noktalar olsun. Sürekli parçanın integrali ile sıçrama noktalarının olasılıkları toplandığında 1 elde edilir (ekrandan, 00:40:00):

$$\int_{-\infty}^{\infty} c(y)\,dy + \sum_{y_k} P(Y = y_k) = 1$$

Bu nedenle bu fikir bir yoğunluk fonksiyonu gibi kullanılabilir. Hoca beklenen değeri de aynı mantıkla sözlü olarak yazdı (derste sözlü, 00:40:13): sürekli parçada $y\,c(y)$ integrallenir, sıçrama noktalarında değerler olasılıklarıyla çarpılıp toplanır:

$$EY = \int_{-\infty}^{\infty} y\,c(y)\,dy + \sum_{y_k} y_k\,P(Y = y_k)$$

<!-- BELİRSİZ: beklenen değer formülü altyazıdan kuruldu; formülün yazıldığı an kare aralığında kalmadı. -->

Hoca aynı örneğin devamındaki üç soruyu alıştırma olarak bıraktı ve kitaba yönlendirdi (ekrandan, 00:45:00); bu sorular Örnek Sorular bölümündedir.

## 3. Dirac Delta Fonksiyonu

### 3.1 Birim basamak ve delta

Hoca önce daha önce tanımlanan birim basamak fonksiyonunu hatırlattı (ekrandan, 00:45:00 ve 00:50:00):

$$u(x) = \begin{cases} 1, & x \ge 0 \\ 0, & x < 0 \end{cases}$$

Bu basamak fonksiyonu 0'da sıçrar. Dirac delta fonksiyonu da parçalı bir fonksiyondur; $x = 0$'da sonsuz, diğer her yerde 0 değerini alır:

$$\delta(x) = \begin{cases} \infty, & x = 0 \\ 0, & \text{diğer} \end{cases}$$

Delta fonksiyonu birim basamak fonksiyonunun türevi olarak yazılabilir:

$$\delta(x) = \frac{d}{dx}u(x)$$

Hoca bu konunun ayrıntılı tartışmasının ders kitabında (Pishro-Nik) bulunduğunu, ilgili bölümlerin okunması gerektiğini söyledi.

### 3.2 Grafik gösterimi

Delta fonksiyonu grafikte $x = 0$'da yukarı doğru bir okla çizilir ve okun yüksekliği 1 olarak işaretlenir (ekrandan, 00:50:00).

**Soru:** Delta fonksiyonunun $x = 0$'daki değeri sonsuz mu, 1 mi? **Cevap:** $x = 0$'da değer sonsuzdur. Sonsuz uzunlukta bir çizgi çizilemediği için grafikte 1 olarak gösterilir. 1 olan fonksiyonun kendisi değil, 0 çevresindeki integralidir; grafik yalnızca bir gösterimdir.

Sık kullanılan bir biçim de kaydırılmış deltadır: $\delta(x - x_0)$, $x_0$ dışında her yerde sıfırdır. Grafikte ok $x_0$ noktasına çizilir ve yine yüksekliği 1 olarak gösterilir.

### 3.3 Delta fonksiyonunun özellikleri

Delta fonksiyonunu integrallemeyi sağlayan iki özellik tahtaya yazıldı (ekrandan, 00:55:00 ve 01:00:00):

- Her $\varepsilon > 0$ için $\displaystyle\int_{-\varepsilon}^{\varepsilon} \delta(x)\,dx = 1$. Yani $-\varepsilon$ ile $+\varepsilon$ ne kadar yakın olursa olsun, sıfır olmadıkça integral 1'dir.
- Her $\varepsilon > 0$ ve $(x_0 - \varepsilon, x_0 + \varepsilon)$ aralığında sürekli her $g(x)$ fonksiyonu için

$$\int_{-\infty}^{\infty} g(x)\,\delta(x - x_0)\,dx = \int_{x_0 - \varepsilon}^{x_0 + \varepsilon} g(x)\,\delta(x - x_0)\,dx = g(x_0).$$

Yani integral sınırları $-\infty$ ve $+\infty$ yerine $x_0$'ın hemen öncesi ve hemen sonrası alınabilir; sonuç değişmez ve $g$'nin $x_0$'daki değerine eşittir.

## 4. Genelleştirilmiş Olasılık Yoğunluk Fonksiyonu

Delta fonksiyonuyla, kesikli ve karışık değişkenler dahil her tür için geçerli bir "genelleştirilmiş" yoğunluk fonksiyonu yazılabilir.

### 4.1 Kesikli rastgele değişken

Kesikli rastgele değişkenlerin normalde yoğunluk fonksiyonu değil, olasılık kütle fonksiyonu (PMF) vardır. $X$, değer aralığı $R_X = \{x_1, x_2, x_3, \dots\}$ ve PMF'i $P_X(x_k)$ olan kesikli bir değişken olsun. Genelleştirilmiş PDF şöyle tanımlanır (ekrandan, 01:15:00):

$$f_X(x) = \sum_{x_k \in R_X} P_X(x_k)\,\delta(x - x_k)$$

Her değer noktasında, o değerin olasılığıyla çarpılmış bir delta bulunur.

### 4.2 Karışık rastgele değişken

Karışık değişkende kesikli duruma benzer bir toplam vardır, ama bunun yanında olağan bir yoğunluk bileşeni de bulunur (ekrandan, 01:20:00):

$$f_X(x) = \underbrace{\sum_k a_k\,\delta(x - x_k)}_{\text{kesikli parça}} + \underbrace{g(x)}_{\text{sürekli parça}}$$

Burada $a_k = P(X = x_k)$ ve $g(x) \ge 0$ hiçbir delta fonksiyonu içermez.

> **Ders sonrası not:** Tahtada $a_k = P(X = a_k)$ yazıldı (ekrandan, 01:20:00); doğrusu $a_k = P(X = x_k)$'dır.

Bu yoğunluk $-\infty$'dan $+\infty$'a integrallendiğinde sonuç 1'dir. İntegral, olasılıkların toplamı ile sürekli parçanın integraline ayrılır:

$$\int_{-\infty}^{\infty} f_X(x)\,dx = \sum_k a_k + \int_{-\infty}^{\infty} g(x)\,dx = 1$$

### 4.3 Örnek: CDF'ten genelleştirilmiş PDF'e

Hoca şu CDF ile bir örnek verdi (ekrandan, 01:20:00):

$$F_X(x) = \begin{cases} \tfrac12 + \tfrac12(1 - e^{-x}), & x \ge 1 \\ \tfrac14 + \tfrac12(1 - e^{-x}), & 0 \le x < 1 \\ 0, & x < 0 \end{cases}$$

Sorular: (a) $X$ ne tür bir değişkendir? (b) Genelleştirilmiş PDF'i bulun. (c) $P(X > 0.5)$'i hem CDF hem PDF ile bulun. (d) $EX$ ve $\mathrm{Var}(X)$'i bulun (ekrandan, 01:30:00).

**(a) Tür.** Değişkenin türünü anlamak için önce CDF grafiği çizilir (ekrandan, 01:30:00). $x < 0$ için değer hep 0'dır. $x = 0$'da $0.25$'e bir sıçrama vardır. $0$ ile $1$ arasında grafik artarak ilerler. $x = 1$'de bir sıçrama daha vardır; sonra fonksiyon artmaya devam eder ve sonsuzda 1'e yaklaşır. Sıçramalar ve sıçramalar arasında artan bölümler olduğu için $X$ karışık bir değişkendir.

**(b) Genelleştirilmiş PDF.** Kesikli parçada her sıçrama noktasında, sıçrama miktarıyla çarpılmış bir delta yazılır.

- $x = 0$'daki sıçrama: CDF 0'dan $\tfrac14$'e çıkar, yani $\tfrac14\,\delta(x - 0)$.
- $x = 1$'deki sıçrama: 1'den önceki ve sonraki ifadeler aynıdır, yalnız sabit terim farklıdır. $\tfrac12$, $\tfrac14 + \tfrac14$ diye yazılırsa 1'den sonra $\tfrac14$ fazladan kümülatif olasılık olduğu görülür. Sıçrama $\tfrac14$'tür: $\tfrac14\,\delta(x - 1)$.
- Sürekli parça: iki bölgede de değişen kısım $\tfrac12(1 - e^{-x})$'tir; türevi $\tfrac12 e^{-x}$'tir. Bu ifade her yerde yazılamaz, çünkü fonksiyon yalnız 0'dan sonra pozitiftir; 0'dan önce 0'dır. Parçalı fonksiyon yazmak yerine birim basamakla çarpılır, çünkü $u(x)$ 0'dan önce 0, sonra 1'dir.

$$f_X(x) = \tfrac14\,\delta(x) + \tfrac14\,\delta(x - 1) + \tfrac12 e^{-x}u(x)$$

**(c) PDF ile $P(X > 0.5)$.** Yoğunluk $0.5$'ten sonsuza integrallenir ve terimler tek tek ele alınır (ekrandan, 01:35:00):

$$P(X > 0.5) = \int_{0.5}^{\infty} \tfrac14\,\delta(x)\,dx + \int_{0.5}^{\infty} \tfrac14\,\delta(x - 1)\,dx + \int_{0.5}^{\infty} \tfrac12 e^{-x}\,dx$$

- Birinci terim: $\delta(x)$ yalnız $x = 0$'da sıfırdan farklıdır, ama integral 0.5'ten başlar. Bu aralıkta delta sıfırdır, sıfırın integrali de sıfırdır.
- İkinci terim: $\delta(x - 1)$'in noktası $x = 1$, integral aralığının içindedir; terim $\tfrac14 \cdot 1 = \tfrac14$ verir.
- Üçüncü terim: integral 0.5'ten başladığı için $u(x)$ yazmaya gerek yoktur (hoca önce yazdı, sonra gereksiz olduğunu belirtti). Basit bir integralle $\tfrac12 e^{-0.5}$ bulunur.

$$P(X > 0.5) = 0 + \tfrac14 + \tfrac12 e^{-0.5} \approx 0.5533$$

Sonuç python ile doğrulandı ($0.25 + 0.5\,e^{-0.5} = 0.55327$).

> **Hocanın vurgusu:** Delta fonksiyonuyla çalışırken integral aralığına dikkat edilmelidir. Delta fonksiyonunun noktası aralığın içindeyse integrali 1 alınır; dışındaysa terim sıfırdır.

Hoca $P(X > 0.5)$'in CDF ile hesabını, $EX$'i ve $\mathrm{Var}(X)$'i alıştırma olarak bıraktı; çözümleri Örnek Sorular bölümündedir.

## 5. İki Kesikli Rastgele Değişkenin Ortak Dağılımı

Bu örnekle sürekli rastgele değişkenler konusu kapandı ve ortak dağılımlara (joint distributions) geçildi. Hoca, kitapta bu konunun Bölüm 5'te (iki rastgele değişken) olduğunu, Bölüm 6'nın ikiden fazla değişkeni anlattığını söyledi (ekrandan, 01:45:00). Zaman sınırı nedeniyle bazı kısımlar atlanacağı için Bölüm 5'in de okunması, Bölüm 6'nın ise tamamen okunarak çalışılması gerektiğini, oradaki birçok fikrin iki değişkenli duruma çok benzediğini belirtti.

### 5.1 Ortak PMF

İki kesikli değişkenin ortak olasılık kütle fonksiyonu bir tabloyla verilebilir (ekrandan, 01:45:00):

| | $Y = 0$ | $Y = 1$ | $Y = 2$ |
|---|---|---|---|
| $X = 0$ | $1/6$ | $1/4$ | $1/8$ |
| $X = 1$ | $1/8$ | $1/6$ | $1/6$ |

Örneğin tablodan $P(X = 1, Y = 0) = \tfrac18$ okunur. Buradaki virgül "ve" anlamına gelir. Ortak PMF tanımı:

$$P_{XY}(x, y) = P(X = x, Y = y) = P\big((X = x) \text{ ve } (Y = y)\big)$$

Ortak dağılımın değer aralığı tek sayılardan değil çiftlerden oluşur (ekrandan, 01:50:00):

$$R_{XY} = \{(x, y) \mid P_{XY}(x, y) > 0\}$$

Hoca bunun bazen $R_X \times R_Y$ biçiminde de yazıldığını söyledi.

> **Ders sonrası not:** Tahtada $R_{XY} = R_X \times R_Y$ yazıldı. Genelde $R_{XY}$, $R_X \times R_Y$'nin bir alt kümesidir; eşitlik büyük olasılıkla yalnız bütün çiftlerin olasılığı sıfırdan büyük olduğunda (bu tablodaki gibi) geçerlidir.

Her zamanki gibi bütün olasılıkların toplamı 1'dir:

$$\sum_{(x_i, y_j) \in R_{XY}} P_{XY}(x_i, y_j) = 1, \qquad \tfrac16 + \tfrac14 + \tfrac18 + \tfrac18 + \tfrac16 + \tfrac16 = 1.$$

### 5.2 Marjinal PMF

Ortak olasılıktan tek tek değişkenlerin olasılıkları bulunabilir. Bunlara marjinal PMF denir; "marjinal" burada "ortak olmayan", yani tek değişkene ait demektir. Adı, tablonun en sağındaki kenar boşluğundan (margin) gelir: $X = 0$ olasılığı bu satır toplanıp kenara yazılarak bulunur (ekrandan, 01:50:00 ve 01:55:00).

$$P_X(x) = \sum_{y_j \in R_Y} P_{XY}(x, y_j), \quad x \in R_X \qquad\qquad P_Y(y) = \sum_{x_i \in R_X} P_{XY}(x_i, y), \quad y \in R_Y$$

$X$'in marjinali için $Y$'nin bütün olası değerleri üzerinden, $Y$'nin marjinali için $X$'in bütün olası değerleri üzerinden toplanır.

> **Ders sonrası not:** Hoca $P_X(0)$'ı ilk kez yazarken tablonun kenarına $\tfrac16 + \tfrac18 + \tfrac18$ yazdı ve öyle söyledi (01:48:20; ekrandan, 01:50:00). Doğrusu $x = 0$ satırının toplamı $\tfrac16 + \tfrac14 + \tfrac18 = \tfrac{13}{24}$'tür. Hoca koşullu olasılık hesabında doğru toplamı kullandı (ekrandan, 02:00:00).

### 5.3 Örnek: koşullu olasılık

$X = 0$ verildiğinde $Y = 1$ olasılığı koşullu olasılık kuralıyla bulunur (ekrandan, 01:55:00 ve 02:00:00):

$$P(Y = 1 \mid X = 0) = \frac{P(Y = 1 \text{ ve } X = 0)}{P(X = 0)} = \frac{P_{XY}(0, 1)}{P_X(0)}$$

Pay doğrudan tablodan okunur: $\tfrac14$. Payda, $X = 0$'ın marjinal olasılığıdır ve $Y$'nin bütün değerleri üzerinden toplanarak bulunur:

$$P(Y = 1 \mid X = 0) = \frac{1/4}{\sum_{y_j \in R_Y} P_{XY}(0, y_j)} = \frac{1/4}{\tfrac16 + \tfrac14 + \tfrac18} = \frac{1/4}{13/24} = \frac{6}{13}\ \text{(ara adım eklendi)}$$

Derste ifade kesir biçiminde bırakıldı; son değer python ile hesaplandı. Hoca bu tür her sorunun ortak dağılımdan cevaplanabileceğini, örneğin geri kalanının kitapta olduğunu söyledi.

### 5.4 Ortak CDF

Ortak kümülatif dağılım fonksiyonu (ekrandan, 02:00:00):

$$F_{XY}(x, y) = P(X \le x, Y \le y)$$

### 5.5 Koşullu PMF

Koşullu olasılıktaki gibi, ortak olasılık koşul olan değişkenin marjinal olasılığına bölünür (ekrandan, 02:10:00). Gösterimde "|" işareti "verildiğinde" (given) anlamına gelir:

$$P_{X|Y}(x_i \mid y_j) = \frac{P_{XY}(x_i, y_j)}{P_Y(y_j)}, \qquad x_i \in R_X,\ y_j \in R_Y$$

### 5.6 Koşullu beklenen değer

Koşullu PMF ile koşullu beklenen değer yazılır (ekrandan, 02:15:00). $A$ bir olay, $X$ bir rastgele değişken olsun. Beklenen değer hesabında her zaman olduğu gibi değerler olasılıklarıyla çarpılıp toplanır:

$$E[X \mid A] = \sum_{x_i \in R_X} x_i\,P_{X|A}(x_i)$$

Olay yerine "$Y$ bir değer aldı" olayı yazılırsa:

$$E[X \mid Y = y_j] = \sum_{x_i \in R_X} x_i\,P_{X|Y}(x_i \mid y_j)$$

### 5.7 Bağımsızlık

İki kesikli değişken $X$ ve $Y$, bütün $x, y$ değerleri için

$$P_{XY}(x, y) = P_X(x)\,P_Y(y)$$

sağlanıyorsa bağımsızdır (ekrandan, 02:20:00).

> **Hocanın vurgusu:** "Bütün" (all) kelimesi çok önemlidir. İki değişkenin bağımsız olup olmadığı sorulduğunda bütün $x$ ve $y$ değerleri denetlenmelidir.

### 5.8 İki değişkenin fonksiyonu ve LOTUS

İki değişkenin bir fonksiyonunun beklenen değeri, bütün değer çiftleri üzerinden toplanarak bulunur (ekrandan, 02:20:00):

$$E[g(X, Y)] = \sum_{x_i \in R_X}\sum_{y_j \in R_Y} g(x_i, y_j)\,P_{XY}(x_i, y_j)$$

Örnek olarak tablodaki dağılım için $E[XY]$ hesaplandı:

$$E[XY] = \sum_{x=0}^{1}\sum_{y=0}^{2} xy\,P_{XY}(x, y)$$

$$= 0\cdot0\cdot\tfrac16 + 0\cdot1\cdot\tfrac14 + 0\cdot2\cdot\tfrac18 + 1\cdot0\cdot\tfrac18 + 1\cdot1\cdot\tfrac16 + 1\cdot2\cdot\tfrac16$$

Tablonun ilk satırındaki ($X = 0$) bütün terimler ve $Y = 0$ terimi sıfırdır; kalan $\tfrac16 + \tfrac26 = \tfrac12$'dir (ara adım eklendi; sonuç derste söylenmedi, python ile doğrulandı). Hoca bunun LOTUS'un iki değişkenli hali olduğunu belirtti.

## 6. İki Sürekli Rastgele Değişkenin Ortak Dağılımı

Sürekli durumda fikir aynıdır; toplamlar integrale dönüşür.

### 6.1 Ortak sürekli değişkenler ve ortak PDF

İki rastgele değişken $X$ ve $Y$, $\mathbb{R}^2$'den $\mathbb{R}$'ye negatif olmayan bir $f_{XY}(x, y)$ fonksiyonu varsa ve $\mathbb{R}^2$'deki her $A$ kümesi için

$$P\big((X, Y) \in A\big) = \iint_A f_{XY}(x, y)\,dx\,dy$$

sağlanıyorsa ortak sürekli (jointly continuous) olarak adlandırılır (derste sözlü, 02:21:05). $f_{XY}(x, y)$, $X$ ve $Y$'nin ortak olasılık yoğunluk fonksiyonudur. Beklendiği gibi her iki değişken üzerinden $-\infty$'dan $+\infty$'a integrali 1'dir (ekrandan, 02:25:00):

$$\int_{-\infty}^{\infty}\int_{-\infty}^{\infty} f_{XY}(x, y)\,dx\,dy = 1$$

### 6.2 Marjinal PDF

Kesikli durumdaki toplam yerine integral alınır (ekrandan, 02:25:00):

$$f_X(x) = \int_{-\infty}^{\infty} f_{XY}(x, y)\,dy, \qquad \text{her } x \text{ için}$$

### 6.3 Ortak CDF ve PDF ilişkisi

Ortak CDF tanımı kesikli durumdakiyle aynıdır: $F_{XY}(x, y) = P(X \le x, Y \le y)$. Tek değişkende olduğu gibi yoğunluk integrallenince kümülatif dağılım, kümülatif dağılımın türevi alınınca yoğunluk elde edilir (ekrandan, 02:30:00):

$$F_{XY}(x, y) = \int_{-\infty}^{y}\int_{-\infty}^{x} f_{XY}(u, v)\,du\,dv, \qquad f_{XY}(x, y) = \frac{\partial^2}{\partial x\,\partial y} F_{XY}(x, y)$$

<!-- BELİRSİZ: ortak CDF integralinin karede yalnız alt kısmı görünüyor; integral değişkenlerinin adları (u, v) okunamadı, standart gösterimle yazıldı. -->

### 6.4 Bağımsızlık

İki sürekli değişken, bütün $x, y$ için ortak yoğunluk marjinal yoğunlukların çarpımına eşitse bağımsızdır (ekrandan, 02:30:00):

$$f_{XY}(x, y) = f_X(x)\,f_Y(y)$$

Bilinmesi gereken bir sonuç: $X$ ve $Y$ bağımsızsa çarpımlarının beklenen değeri beklenen değerlerin çarpımıdır:

$$E[XY] = EX \cdot EY$$

### 6.5 Sürekli LOTUS

$X$ ve $Y$'nin bir fonksiyonunun beklenen değeri, kesikli durumdaki çift toplam yerine çift integralle bulunur (derste sözlü, 02:30:27):

$$E[g(X, Y)] = \int_{-\infty}^{\infty}\int_{-\infty}^{\infty} g(x, y)\,f_{XY}(x, y)\,dx\,dy$$

Hoca bu ifadelerin büyük denklemler gibi göründüğünü, ama fikir anlaşılınca yazmanın çok kolay olduğunu söyledi.

## 7. Kovaryans ve Korelasyon

### 7.1 Kovaryans

$X$ ve $Y$ arasındaki kovaryans, değişkenler kesikli de sürekli de olsa geçerli olan bir tanımdır (derste sözlü, 02:32:24; ekrandan, 02:35:00):

$$\mathrm{Cov}(X, Y) = E\big[(X - EX)(Y - EY)\big] = E[XY] - (EX)(EY)$$

İkinci biçim hesapta daha kolaydır.

### 7.2 Korelasyon

$X$ ve $Y$ arasındaki korelasyon (kesikli ve sürekli için geçerli), kovaryansın iki değişkenin standart sapmalarının çarpımına bölünmesidir (derste sözlü, 02:35:16):

$$\rho_{XY} = \rho(X, Y) = \frac{\mathrm{Cov}(X, Y)}{\sigma_X\,\sigma_Y}$$

### 7.3 Sezgi

Hoca kovaryansı bir veri tablosu ($x$ ve $y$ değer çiftleri) ve saçılım grafiğiyle anlattı (ekrandan, 02:40:00):

- Noktalar artan bir doğru çevresinde toplanıyorsa (iyi bir doğru uydurulabiliyorsa) $X$ ile $Y$ arasında pozitif kovaryans vardır.
- Noktalar azalan bir doğru çevresinde toplanıyorsa kovaryans negatiftir.
- Noktalar dağınıksa, yani $X$ büyük ya da küçük olduğunda $Y$ değişmiyorsa kovaryans sıfıra yakındır.

Korelasyona neden gerek duyulduğu da açıklandı: kovaryans herhangi bir gerçel değeri alabilir. Örneğin $X$ çok büyük değerler alıyorsa kovaryans da büyük çıkar; bu durumda kovaryansın yüksek mi düşük mü olduğu anlaşılamaz. Korelasyon kovaryansın standart sapmalarla normalleştirilmiş halidir ve $-1$ ile $1$ arasında değer alır. Korelasyon 1'e yakınsa yüksek (pozitif) korelasyon, $-1$'e yakınsa yüksek negatif korelasyon, 0 çevresindeyse korelasyon yok demektir. Bu yüzden korelasyonu yorumlamak kovaryanstan çok daha kolaydır.

### 7.4 Kovaryansın bir özelliği

$a$ ve $b$ sabit, $X$ ve $Y$ rastgele değişken olmak üzere (ekrandan, 02:45:00):

$$\mathrm{Var}(aX + bY) = a^2\,\mathrm{Var}(X) + b^2\,\mathrm{Var}(Y) + 2ab\,\mathrm{Cov}(X, Y)$$

Korelasyon ya da kovaryans sıfırsa son terim düşer:

$$\mathrm{Var}(aX + bY) = a^2\,\mathrm{Var}(X) + b^2\,\mathrm{Var}(Y)$$

Bölüm 5 burada bitti. Hoca zaman sınırı nedeniyle bazı konuların atlandığını, bunların ve ikiden fazla değişkeni anlatan Bölüm 6'nın kitaptan çalışılması gerektiğini söyledi.

## Örnek Sorular

### Soru 1: Karışık değişkenin CDF'i (ekrandan, 00:15:00)

$X$'in yoğunluğu $f_X(x) = 2x$ ($0 \le x \le 1$), diğer yerlerde 0'dır. $Y = X$ ($0 \le X \le \tfrac12$), $Y = \tfrac12$ ($X > \tfrac12$). $Y$'nin CDF'ini bulun.

> **Çözüm (derste verildi):** $R_Y = [0, \tfrac12]$. $P(Y = \tfrac12) = \int_{1/2}^1 2x\,dx = \tfrac34$. $0 \le y < \tfrac12$ için $F_Y(y) = \int_0^y 2x\,dx = y^2$. Sonuç: $F_Y(y) = 0$ ($y < 0$), $y^2$ ($0 \le y < \tfrac12$), $1$ ($y \ge \tfrac12$). $y = \tfrac12$'de $\tfrac34$'lük sıçrama olduğu ve sıçrama dışında artan bir bölüm bulunduğu için $Y$ karışıktır.

### Soru 2: Örneğin devamı (ekrandan, 00:45:00)

Aynı $X$ ve $Y$ için: (a) $P(\tfrac14 \le Y \le \tfrac38)$, (b) $P(Y \ge \tfrac14)$, (c) $EY$'yi bulun.

> **Çözüm (derste verilmedi):** (a) Aralık sürekli bölgede kaldığı için $P = F_Y(\tfrac38) - F_Y(\tfrac14) = \tfrac{9}{64} - \tfrac{4}{64} = \tfrac{5}{64}$. (b) $P(Y \ge \tfrac14) = 1 - P(Y < \tfrac14) = 1 - \tfrac{1}{16} = \tfrac{15}{16}$. (c) $c(y) = 2y$ ($0 \le y < \tfrac12$) ve tek sıçrama noktası $y = \tfrac12$ (olasılık $\tfrac34$) olduğundan $EY = \int_0^{1/2} y \cdot 2y\,dy + \tfrac12 \cdot \tfrac34 = \tfrac{1}{12} + \tfrac38 = \tfrac{11}{24}$. Değerler python ile doğrulandı.

### Soru 3: Karışık değişken ve genelleştirilmiş PDF (ekrandan, 01:20:00 ve 01:30:00)

$F_X(x) = \tfrac12 + \tfrac12(1 - e^{-x})$ ($x \ge 1$), $\tfrac14 + \tfrac12(1 - e^{-x})$ ($0 \le x < 1$), $0$ ($x < 0$). (a) $X$ ne tür bir değişkendir? (b) Genelleştirilmiş PDF'i bulun. (c) $P(X > 0.5)$'i hem CDF hem PDF ile bulun. (d) $EX$ ve $\mathrm{Var}(X)$'i bulun.

> **Çözüm (a, b ve c'nin PDF kısmı derste verildi):** (a) $x = 0$ ve $x = 1$'de sıçrama, arada artan bölümler olduğu için karışıktır. (b) $f_X(x) = \tfrac14\delta(x) + \tfrac14\delta(x - 1) + \tfrac12 e^{-x}u(x)$. (c) PDF ile: $0 + \tfrac14 + \tfrac12 e^{-0.5} \approx 0.5533$.

> **Çözüm (derste verilmedi):** (c) CDF ile: $P(X > 0.5) = 1 - F_X(0.5) = 1 - \big[\tfrac14 + \tfrac12(1 - e^{-0.5})\big] = \tfrac14 + \tfrac12 e^{-0.5} \approx 0.5533$; iki yol aynı sonucu verir. (d) $EX = 0 \cdot \tfrac14 + 1 \cdot \tfrac14 + \int_0^\infty x \cdot \tfrac12 e^{-x}\,dx = \tfrac14 + \tfrac12 = \tfrac34$. $E[X^2] = 0 \cdot \tfrac14 + 1 \cdot \tfrac14 + \int_0^\infty x^2 \cdot \tfrac12 e^{-x}\,dx = \tfrac14 + 1 = \tfrac54$. $\mathrm{Var}(X) = \tfrac54 - \tfrac{9}{16} = \tfrac{11}{16}$. Değerler python ile sayısal integralle doğrulandı.

### Soru 4: Ortak PMF tablosu (ekrandan, 01:45:00, 01:55:00 ve 02:20:00)

Bölüm 5.1'deki tablo için: (a) $P(X = 1, Y = 0)$, (b) $P(Y = 1 \mid X = 0)$, (c) $E[XY]$ nedir?

> **Çözüm (derste verildi, son sayısal değerler python ile hesaplandı):** (a) Tablodan $\tfrac18$. (b) $\dfrac{1/4}{1/6 + 1/4 + 1/8} = \dfrac{6}{13}$. (c) $1 \cdot 1 \cdot \tfrac16 + 1 \cdot 2 \cdot \tfrac16 = \tfrac12$ (diğer terimler sıfır).

## Dersin Toparlaması

Bu derste sürekli rastgele değişkenler konusu karışık değişkenlerle tamamlandı. CDF'inde hem sıçrama hem de sıçramalar arasında artan bölümler bulunan değişkenlerin karışık olduğu, CDF'in sürekli ve kesikli parçaların toplamı olarak yazılabildiği görüldü. Dirac delta fonksiyonu birim basamağın türevi olarak tanıtıldı ve integral özellikleri sayesinde kesikli ve karışık değişkenler için genelleştirilmiş bir yoğunluk fonksiyonu yazılabildi. Bu araçla bir karışık değişkenin olasılıkları tek bir integralle hesaplandı.

Dersin ikinci yarısında iki rastgele değişkenin ortak dağılımlarına geçildi: kesikli durumda ortak PMF, marjinal ve koşullu PMF'ler, koşullu beklenen değer, bağımsızlık ve LOTUS; sürekli durumda ortak PDF, marjinal PDF, ortak CDF ile ilişki ve bağımsızlık ele alındı. Son olarak kovaryans, korelasyon ve $\mathrm{Var}(aX + bY)$ formülü işlendi. Hoca bir sonraki derste kitabın Bölüm 7'sinden devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
