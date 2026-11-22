# Ders 4 Genişletilmiş Notu: CDF Özellikleri, Rastgele Değişkenlerle İşlemler, Ortak Dağılım, Bağımsızlık, Beklenen Değer ve Varyans

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. PMF ve CDF tekrarı
- 2. CDF'in temel özellikleri
- 3. CDF ile aralık olasılıkları
- 4. Rastgele değişkenlerle işlemler
- 5. Rastgele vektörün dağılımı
- 6. Ortak dağılım ve ortak PMF
- 7. Marjinal dağılım
- 8. Rastgele değişkenlerin bağımsızlığı
- 9. Ortak tablodan koşullu olasılık
- 10. Beklenen değer
- 11. Momentler, varyans ve standart sapma
- 12. Varyansın özellikleri
- Örnek Sorular

## 1. PMF ve CDF tekrarı

Ders, önceki derste görülen kesikli rastgele değişken kavramının kısa bir tekrarıyla başladı. Bir para atıldığında sonucu 0 ve 1 gibi sayılara eşleyen fonksiyon bir rastgele değişkendir. Hoca rastgele değişkenleri büyük harfle ve harfin üstünde küçük bir "kanca" ile yazıyor; bu kanca, harfin bir rastgele değişken olduğunu gösteriyor. Kesikli bir rastgele değişken, aldığı değerler ve bu değerlerin olasılıklarından oluşan bir tabloyla tanımlanabilir. Bu tablo olasılık kütle fonksiyonudur (PMF). PMF tablo hâlinde yazılabilir ya da çubuk grafik olarak çizilebilir.

Hoca ardından CDF tanımını yeniden yazdı (ekrandan, 00:10:00). $X$ bir rastgele değişken ve örnek uzayı $\Omega_X = \{x_1, x_2, \dots, x_n\}$ olsun. Örnek uzayın büyüklüğü $|\Omega_X| = n < \infty$, yani sonludur. Bu nedenle $X$ kesikli bir rastgele değişkendir. $X$'in CDF'i şöyle tanımlanır:

$$F_X(x) = \Pr(X \le x) = \sum_{x_k \le x} \Pr(X = x_k).$$

Yani CDF, rastgele değişkenin önceden belirlenmiş bir $x$ eşiğine eşit ya da ondan küçük olma olasılığıdır ve $x$'e kadar olan bütün değerlerin olasılıklarının toplamıdır. Zar atmada örnek uzay $\{1, 2, 3, 4, 5, 6\}$ idi ve bunun CDF'i önceki derste hesaplanmıştı.

## 2. CDF'in temel özellikleri

CDF grafiğine bakıldığında sıfırdan başladığı, hep arttığı ve hiç azalmadığı görülür. Hoca bu gözlemden yola çıkarak CDF'in temel özelliklerini sıraladı (ekrandan, 00:15:00):

- $0 \le F_X(x) \le 1$.
- $F_X(-\infty) = \lim_{x \to -\infty} F_X(x) = 0$.
- $F_X(+\infty) = \lim_{x \to \infty} F_X(x) = 1$.
- CDF artan bir fonksiyondur ve basamak (staircase) karakteristiğine sahiptir. Yani $F_X(x)$, $x$ değişkeninin artan bir fonksiyonudur.

## 3. CDF ile aralık olasılıkları

### 3.1 Bir eşikten büyük olma olasılığı

Hoca önce $F_X(a) = \Pr(X \le a)$ ve $F_X(b) = \Pr(X \le b)$ olduğunu hatırlattı ve $a < b$ varsaydı. Aralıklara geçmeden önce $\Pr(X > b)$ olasılığını inceledi (ekrandan, 00:20:00):

$$\Pr(X > b) = 1 - \Pr(X \le b).$$

Bunun gerekçesi şöyle kuruldu. Sayı doğrusu $-\infty$'dan $+\infty$'a uzanır ve $b$ noktasının sağ tarafı taranır. Rastgele değişken bir reel sayı aldığı için $-\infty$ ile $+\infty$ arasında olma olasılığı 1'dir: $\Pr(-\infty < X < \infty) = 1$. Kümeler şöyle tanımlanır:

- $A = \{X > b\}$,
- $\Omega = \{-\infty < X < +\infty\}$ (evrensel küme),
- $B = \{X \le b\}$.

$A$ ve $B$, $\Omega$'yı iki ayrık parçaya böler. Hoca bunu bir Venn şemasıyla gösterdi. Bir öğrenci $B$'nin olasılığını "bir eksi $A$" diye cevapladı. Dolayısıyla $\Pr(B) = 1 - \Pr(A)$, aynı şekilde $\Pr(A) = 1 - \Pr(B)$ yazılabilir.

### 3.2 Aralık türleri

Hoca dört aralık türünü CDF cinsinden yazdı (ekrandan, 00:25:00 ve 00:30:00). İlki en temel olanıdır ve hoca onu kırmızıyla çevirip "çok önemli" diye işaretledi:

$$\Pr(a < X \le b) = \Pr(X \le b) - \Pr(X \le a) = F_X(b) - F_X(a).$$

> **Hocanın vurgusu:** $\Pr(a < X \le b) = F_X(b) - F_X(a)$ formülü önemlidir; diğer aralıklar buradan türetilir.

Diğer aralıklar, uç noktalardaki olasılıklar eklenip çıkarılarak bu formüle indirgenir:

$$\Pr(a \le X < b) = \Pr(X = a) + \Pr(a < X \le b) - \Pr(X = b) = \Pr(X = a) + F_X(b) - F_X(a) - \Pr(X = b),$$

$$\Pr(a \le X \le b) = \Pr(X = a) + \Pr(a < X \le b) = \Pr(X = a) + F_X(b) - F_X(a),$$

$$\Pr(a < X < b) = \Pr(a < X \le b) - \Pr(X = b) = F_X(b) - F_X(a) - \Pr(X = b).$$

Kural basittir: $a$ ucu dahil edilecekse $\Pr(X = a)$ eklenir, $b$ ucu hariç tutulacaksa $\Pr(X = b)$ çıkarılır.

> **Ek bilgi (derste anlatılmadı):** Sürekli rastgele değişkenlerde tek bir noktanın olasılığı sıfırdır. Bu yüzden orada dört aralık türünün olasılığı aynı çıkar. Uç noktaların ayrımı kesikli değişkenlerde önemlidir.

## 4. Rastgele değişkenlerle işlemler

### 4.1 Toplam, çarpım ve skaler çarpım

Rastgele değişkenler örnek uzay üzerinde tanımlı fonksiyonlar olduğu için onlarla işlem yapılabilir (ekrandan, 00:30:00). $X$ ve $Y$, $\Omega$ örnek uzayı üzerinde tanımlı fonksiyonlar olarak görülürse şunlar tanımlanabilir:

- toplam: $X + Y$,
- çarpım: $X \cdot Y$,
- skaler çarpım: $kX$, $k \in \mathbb{R}$.

Bu işlemlerin her biri yeni bir rastgele değişken verir. Yeni değişkenin önce örnek uzayı (alabileceği değerler), sonra her değerin olasılığı bulunur. Böylece toplamların, çarpımların ya da herhangi bir birleşimin PMF tablosu ve CDF'i elde edilebilir.

### 4.2 Toplam örneği: $Z = X + Y$

Hoca iki tablo tanımladı (ekrandan, 00:35:00):

| $X$ | 0 | 1 |
|---|---|---|
| $\Pr(X = x_k)$ | $3/4$ | $1/4$ |

| $Y$ | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| $\Pr(Y = y_k)$ | $1/6$ | $1/6$ | $1/6$ | $1/6$ | $1/6$ | $1/6$ |

Yeni rastgele değişken $Z = X + Y$'dir. İlk soru $Z$'nin örnek uzayıydı. Bir öğrenci önce olasılık değerleri söyledi; hoca örnek uzay için olasılıklara değil, değişkenin aldığı değerlere bakılması gerektiğini hatırlattı. Başka bir öğrenci $\{0, 1, \dots, 6\}$ dedi. Hoca $Z$'nin 0 olamayacağını gösterdi: $Y$'nin en küçük değeri 1'dir, dolayısıyla $Z$ en az 1 olur. Doğru örnek uzay:

$$\Omega_Z = \{1, 2, 3, 4, 5, 6, 7\}.$$

**Soru:** $Z$'nin örnek uzayına neden 7 yazıldı? **Cevap:** $X$'in alabileceği değerler 0 ve 1, $Y$'ninkiler 1'den 6'ya kadardır. En büyük toplam $1 + 6 = 7$'dir. Hoca değerleri toplarken dikkatli olunması gerektiğini, bunun her zaman bu kadar kolay olmadığını ekledi.

Olasılıklar, $X$ ile $Y$'nin bağımsız olduğu varsayılarak hesaplandı:

- $\Pr(Z = 1)$: yalnız $X = 0$, $Y = 1$ durumu vardır. $\Pr(Z = 1) = \Pr(X = 0)\Pr(Y = 1) = \frac{3}{4} \cdot \frac{1}{6} = \frac{1}{8}$.
- $\Pr(Z = 2)$: iki durum vardır, $X = 0, Y = 2$ ya da $X = 1, Y = 1$.

$$\Pr(Z = 2) = \Pr(X = 0)\Pr(Y = 2) + \Pr(X = 1)\Pr(Y = 1) = \frac{1}{8} + \frac{1}{24} = \frac{4}{24} = \frac{1}{6}.$$

Hoca çarpımı neden yazdığını açıkladı: iki rastgele değişken birbirinden bağımsızdır ve çarpım bağımsızlıktan gelir. $\Pr(Z = 3)$'ten $\Pr(Z = 7)$'ye kadar olan olasılıkları öğrencilere bıraktı (çözüm Örnek Sorular bölümünde).

### 4.3 Daha karmaşık bir fonksiyon: $W = 2X^2/(X + Y)$

Aynı $X$ ve $Y$ ile yeni bir rastgele değişken tanımlandı:

$$W = \frac{2X^2}{X + Y}.$$

Örnek uzay şöyle bulunur. $X = 0$ ise pay sıfırdır ve $W = 0$ olur ($Y \ge 1$ olduğu için payda sıfır olmaz). $X = 1$ ise $W = \frac{2}{1 + Y}$ ve $Y = 1, \dots, 6$ için $\frac{2}{2}, \frac{2}{3}, \frac{2}{4}, \frac{2}{5}, \frac{2}{6}, \frac{2}{7}$ değerleri çıkar. Böylece

$$\Omega_W = \left\{0, 1, \tfrac{2}{3}, \tfrac{1}{2}, \tfrac{2}{5}, \tfrac{1}{3}, \tfrac{2}{7}\right\}.$$

**Soru:** $\Pr(W = 0)$ nedir? Bir öğrenci $1/7$ dedi. **Cevap:** Hoca bunun yanlış olduğunu söyledi: örnek uzayda yedi değer olması, her değerin eşit olasılıklı olduğu anlamına gelmez. $W = 0$ olması için $X = 0$ yeterlidir, bu yüzden $\Pr(W = 0) = \Pr(X = 0) = 3/4$.

Diğer değerler:

- $\Pr(W = 1) = \Pr(X = 1)\Pr(Y = 1) = \frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$.
- $\Pr(W = 2) = 0$, çünkü 2 örnek uzayda yoktur. Örnek uzayda bulunmayan bir değerin olasılığı sıfırdır.
- $\Pr(W = 2/3)$ ve $\Pr(W = 2/7)$ öğrencilere bırakıldı (ekrandan, 00:45:00).

## 5. Rastgele vektörün dağılımı

Yeni başlık rastgele vektörün dağılımıydı (ekrandan, 00:50:00). Aynı $\Omega$ örnek uzayı üzerinde tanımlı iki kesikli rastgele değişken $X$ ve $Y$ düşünülür:

| $X$ | $x_1$ | $x_2$ | $x_3$ | $\dots$ | $x_k$ |
|---|---|---|---|---|---|
| $p_X(x_i) = \Pr(X = x_i)$ | $p_1$ | $p_2$ | $p_3$ | $\dots$ | $p_k$ |

| $Y$ | $y_1$ | $y_2$ | $y_3$ | $\dots$ | $y_l$ |
|---|---|---|---|---|---|
| $p_Y(y_j) = \Pr(Y = y_j)$ | $q_1$ | $q_2$ | $q_3$ | $\dots$ | $q_l$ |

Her iki tabloda olasılıkların toplamı 1'dir: $\sum_i p_i = 1$, $\sum_j q_j = 1$. $X$'in örnek uzayında $k$, $Y$'ninkinde $l$ farklı değer vardır.

**Soru:** $Y$ tablosunda olasılık neden $\Pr(Y \le y_j)$ diye yazıldı, eşitlik olması gerekmez mi? **Cevap:** Hoca öğrencinin haklı olduğunu söyledi ve düzeltti: doğrusu $\Pr(Y = y_j)$'dir. Küçük eşit yazılsaydı bu CDF olurdu.

$(X, Y)$ çiftine **rastgele vektör** (random vector) denir. Bu çift $Z = (X, Y)$ gibi yeni bir değişken olarak düşünülebilir. Örnek uzayı bütün çiftlerden oluşur:

$$\Omega_Z = \{(x_1, y_1), (x_1, y_2), \dots, (x_1, y_l), (x_2, y_1), \dots, (x_2, y_l), \dots, (x_k, y_1), \dots, (x_k, y_l)\}.$$

Büyüklüğü $|\Omega_Z| = |\Omega_X| \cdot |\Omega_Y| = k \cdot l$'dir.

## 6. Ortak dağılım ve ortak PMF

### 6.1 Tanım

$Z = (X, Y)$ rastgele vektörünün dağılımına $X$ ve $Y$'nin **ortak dağılımı** (joint distribution) denir. Buna karşılık gelen ortak olasılık kütle fonksiyonu (joint PMF) şöyle tanımlanır (ekrandan, 01:10:00):

$$p_{(X,Y)}(x, y) = \Pr\big((X, Y) = (x, y)\big) = \Pr(X = x \cap Y = y).$$

### 6.2 Ortak dağılım tablosu

Ortak dağılım bir tabloyla verilir. Satırlar $X$'in değerleri $x_1, \dots, x_k$, sütunlar $Y$'nin değerleri $y_1, \dots, y_l$'dir. Tablonun sağına $\Pr(X = x_i)$ sütunu, altına $\Pr(Y = y_j)$ satırı eklenir:

| $X \backslash Y$ | $y_1$ | $y_2$ | $\dots$ | $y_j$ | $\dots$ | $y_l$ | $\Pr(X = x_i)$ |
|---|---|---|---|---|---|---|---|
| $x_1$ | $r_{11}$ | $r_{12}$ | $\dots$ | $r_{1j}$ | $\dots$ | $r_{1l}$ | $p_1$ |
| $x_2$ | $r_{21}$ | $r_{22}$ | $\dots$ | $r_{2j}$ | $\dots$ | $r_{2l}$ | $p_2$ |
| $\vdots$ | | | | | | | |
| $x_i$ | $r_{i1}$ | $r_{i2}$ | $\dots$ | $r_{ij}$ | $\dots$ | $r_{il}$ | $p_i$ |
| $\vdots$ | | | | | | | |
| $x_k$ | $r_{k1}$ | $r_{k2}$ | $\dots$ | $r_{kj}$ | $\dots$ | $r_{kl}$ | $p_k$ |
| $\Pr(Y = y_j)$ | $q_1$ | $q_2$ | $\dots$ | $q_j$ | $\dots$ | $q_l$ | 1 |

Hücredeki değer, $X$'in $x_i$ ve $Y$'nin $y_j$ değerini aynı anda alma olasılığıdır (ekrandan, 01:15:00):

$$r_{ij} = \Pr(X = x_i \cap Y = y_j).$$

### 6.3 Satır ve sütun toplamları

Bir satırdaki bütün hücreler toplandığında $Y$'nin bütün olası değerleri üzerinden toplama yapılır. Hoca bunu "$Y$'yi yok etmek" diye anlattı; geriye yalnız $X = x_i$ olayı kalır:

$$\sum_{j=1}^{l} \Pr(X = x_i \cap Y = y_j) = \Pr(X = x_i) = p_i, \qquad \text{yani} \qquad \sum_{j=1}^{l} r_{ij} = p_i.$$

Aynı şekilde bir sütun toplandığında $X$'in bütün değerleri üzerinden toplama yapılır:

$$\sum_{i=1}^{k} \Pr(X = x_i \cap Y = y_j) = \Pr(Y = y_j) = q_j, \qquad \text{yani} \qquad \sum_{i=1}^{k} r_{ij} = q_j.$$

Hoca bu toplamı yazarken üst sınırı bir an $l$ yazdı, sonra $k$ olması gerektiğini söyleyerek düzeltti.

### 6.4 Bütün hücrelerin toplamı

Bütün hücreler toplanırsa sonuç 1'dir. İki sırayla gösterildi:

$$\sum_{i=1}^{k} \sum_{j=1}^{l} r_{ij} = \sum_{i=1}^{k} p_i = 1, \qquad \sum_{j=1}^{l} \sum_{i=1}^{k} r_{ij} = \sum_{j=1}^{l} q_j = 1.$$

Bunun nedeni şudur (ekrandan, 01:25:00): $(X = x_i \cap Y = y_j)$ olayları, $1 \le i \le k$ ve $1 \le j \le l$ için, örnek uzayın bir parçalanışını (partition) oluşturur. Bu $k \cdot l$ olayın olasılıklarının toplamı 1 olmak zorundadır. Hoca toplama kurallarının (addition rules) da bu parçalanıştan geldiğini söyledi: $\Pr(X = x_i) = \sum_{j=1}^{l} \Pr(X = x_i \cap Y = y_j) = \sum_{j=1}^{l} r_{ij} = p_i$, benzer şekilde $q_j = \sum_{i=1}^{k} r_{ij}$.

## 7. Marjinal dağılım

Hoca tanımı doğrudan yazdı (ekrandan, 01:30:00 ve 01:35:00): $X$ rastgele değişkeni, önceki tablonun marjinal sütunuyla verilen dağılıma sahiptir ($Y$ için marjinal satır). Bu nedenle tablonun ilk sütunu (değerler) ile son sütunu (olasılıklar) birlikte $X$'in **marjinal dağılımını** oluşturur. $Y$ için ilk satır ile son satır aynı rolü oynar. Hoca cümledeki parantezlerin "ya bu ya şu" diye okunacağını belirtti: $X$ için sütun, $Y$ için satır okunur.

Tabloda en sağdaki $p_i$ sütunu $X$'in, en alttaki $q_j$ satırı $Y$'nin marjinal dağılımıdır.

## 8. Rastgele değişkenlerin bağımsızlığı

### 8.1 Tanım

$X$ ve $Y$ rastgele değişkenleri, her $(x, y)$ değer çifti için

$$\Pr(X = x \cap Y = y) = \Pr(X = x)\,\Pr(Y = y)$$

sağlanıyorsa bağımsızdır. Önceki dağılım tablosuna göre bu, her $1 \le i \le k$, $1 \le j \le l$ için

$$r_{ij} = p_i\, q_j$$

demektir. Hoca bunu tabloda gösterdi: bağımsızlıkta her hücre, bulunduğu satırın marjinali ile sütunun marjinalinin çarpımıdır (örneğin $r_{11} = p_1 q_1$, $r_{23} = p_2 q_3$). Bütün hücreler böyle ifade edilebiliyorsa $X$ ve $Y$ bağımsızdır. Hoca burada "bağımsız olabilir" değil, "bağımsızdır" denmesi gerektiğini vurguladı.

### 8.2 Bağımsızlık örneği

Örnekte $X \in \{0, 1\}$, $\Pr(X = 0) = 1/4$, $\Pr(X = 1) = 3/4$ ve $Y \in \{1, \dots, 6\}$, her değer $1/6$ alındı. Bağımsızlık varsayılarak hücreler hesaplandı: $X = 0$ satırındaki her hücre $\frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$, $X = 1$ satırındaki her hücre $\frac{3}{4} \cdot \frac{1}{6} = \frac{3}{24}$ olur (ekrandan, 01:45:00):

| $X \backslash Y$ | 1 | 2 | 3 | 4 | 5 | 6 | $\Pr(X = x_i)$ |
|---|---|---|---|---|---|---|---|
| 0 | $1/24$ | $1/24$ | $1/24$ | $1/24$ | $1/24$ | $1/24$ | $1/4$ |
| 1 | $3/24$ | $3/24$ | $3/24$ | $3/24$ | $3/24$ | $3/24$ | $3/4$ |
| $\Pr(Y = y_j)$ | $1/6$ | $1/6$ | $1/6$ | $1/6$ | $1/6$ | $1/6$ | 1 |

Her hücrede $r_{ij} = p_i q_j$ olduğundan $X$ ve $Y$ bağımsızdır. Hoca ardından marjinalleri koruyarak bazı hücreleri değiştirip bağımlı bir tablo kurmaya çalıştı (ilk satırdaki hücreleri payda 48 olan değerlerle değiştirmeyi denedi), fakat örneği tamamlamadı ve sildi.

### 8.3 Aynı değerleri alan değişkenler bağımlı mıdır?

Aradan önce bir öğrenci, iki değişkenin farklı örnek uzaylarda tanımlandığı için mi bağımsız olduğunu sordu.

**Soru:** $X$ ve $Y$ farklı uzaylarda olduğu için mi bağımsız? İkisi de aynı değerleri alsaydı bağımlı mı olurdu? **Cevap:** Hayır. Bağımsızlıkta değişkenlerin aldığı değerler değil, olasılıklar belirleyicidir. Bağımsızlık tabloya bakılarak söylenir: ortak olasılıklar marjinal olasılıkların çarpımı şeklinde yazılabiliyorsa $X$ ve $Y$ bağımsızdır, yazılamıyorsa bağımlıdır. Örnek uzaylar tamamen aynı (örneğin ikisi de $\{0, 1\}$) olabilirdi; bu bağımsızlığı etkilemez.

**Soru:** Bağımlılığı matematiksel olarak belirtmenin bir yolu var mı? **Cevap:** Var; tanımda gösterildiği gibi, $X = x$ ve $Y = y$ olaylarının birlikte gerçekleşme olasılığı ayrı ayrı olasılıkların çarpımına eşitse $X$ ve $Y$ bağımsızdır. Bu gösterilebiliyorsa kesinlikle bağımsızdır denir.

> **Hocanın vurgusu:** Literatürde sık yapılan bir hata vardır: elinde 0 ve 1'lerden oluşan iki metin (dizi) olan biri, ikisi de 0 ve 1'lerden oluşuyor diye bunların bağımlı olduğunu söyler. Böyle bir şey yoktur. 0 ve 1'lerin olasılıkları ayrı ayrı hesaplanır, sonra birlikte oluşma olasılıklarına bakılır (örneğin birinci dizide 0, ikincide 0; birincide 1, ikincide 1). Birleşik (joint) olasılıklar marjinal olasılıkların çarpımı olarak yazılabiliyorsa diziler bağımsız, yazılamıyorsa bağımlıdır. Karar örnek uzaydan bağımsız verilir.

### 8.4 Aynı örnek uzayda bağımlı ve bağımsız tablo

Hoca bunu göstermek için $\Omega_X = \Omega_Y = \{0, 1\}$ olan bir ortak tablo kurdu (ekrandan, 01:55:00). Marjinaller $\Pr(X = 0) = \Pr(X = 1) = 1/2$, $\Pr(Y = 0) = 1/4$, $\Pr(Y = 1) = 3/4$; ilk sütunda $r_{11} = 1/16$ ve $r_{21} = 3/16$ verildi, ikinci sütundaki $r_{12}$ ve $r_{22}$ bilinmiyor:

| $X \backslash Y$ | 0 | 1 | $\Pr(X = x_i)$ |
|---|---|---|---|
| 0 | $1/16$ | $r_{12}$ | $1/2$ |
| 1 | $3/16$ | $r_{22}$ | $1/2$ |
| $\Pr(Y = y_j)$ | $1/4$ | $3/4$ | 1 |

İlk sütunun toplamı $1/16 + 3/16 = 4/16 = 1/4$'tür ve tutarlıdır. Bilinmeyenler satır ve sütun toplamlarından bulunur (çözüm Örnek Sorular bölümünde). Bu tablo bağımsız değildir: $r_{11} = 1/16$, ama $\Pr(X = 0)\Pr(Y = 0) = \frac{1}{2} \cdot \frac{1}{4} = \frac{1}{8}$. $1/16 \ne 1/8$ olduğu için $X$ ve $Y$ bağımlıdır.

Bağımsız yapmak için her hücre marjinallerin çarpımı alınır. Öğrencilerle birlikte hesaplandı: $r_{11} = \frac{1}{2} \cdot \frac{1}{4} = \frac{1}{8}$, $r_{12} = \frac{1}{2} \cdot \frac{3}{4} = \frac{3}{8}$, $r_{21} = \frac{1}{8}$, $r_{22} = \frac{3}{8}$. Bu durumda $X$ ve $Y$ bağımsız olur; örnek uzayları aynı olduğu hâlde bağımsızdırlar.

## 9. Ortak tablodan koşullu olasılık

$X$ ve $Y$ bağımsız değilse koşullu olasılıklar kullanılır (ekrandan, 02:10:00). Koşullu olasılığın tanımından:

$$\Pr(X = x_i \mid Y = y_j) = \frac{\Pr(X = x_i \cap Y = y_j)}{\Pr(Y = y_j)} = \frac{r_{ij}}{q_j}.$$

Benzer şekilde $X$'e koşullu olarak (ekrandan, 02:15:00):

$$\Pr(Y = y_j \mid X = x_i) = \frac{\Pr(X = x_i \cap Y = y_j)}{\Pr(X = x_i)} = \frac{r_{ij}}{p_i}.$$

Tabloda bir hücre, bulunduğu sütunun alt toplamına bölünürse $Y$'ye koşullu olasılık bulunur. Örneğin $r_{32}/q_2 = \Pr(X = x_3 \mid Y = y_2)$. Hoca, ortak tablo elde olduğunda koşullu olasılıkları hesaplamanın kolay olduğunu söyledi.

## 10. Beklenen değer

### 10.1 Beklenti ve beklenen

Hoca konuya bir soruyla girdi: beklenti ile beklenen arasındaki fark nedir? Bir öğrenci beklentinin "beklenti", varyansın "dağılım" olduğunu söyledi. Hoca zar örneğini verdi: zar atıldığında 1, 2, 3, 4, 5, 6'dan birinin gelmesi beklenir; bu bir anlamda örnek uzaydır. Beklenen değer ise ortalamadır:

$$\frac{1 + 2 + 3 + 4 + 5 + 6}{6} = \frac{6 \cdot 7 / 2}{6} = \frac{7}{2} = 3{,}5.$$

> **Hocanın vurgusu:** Kelimeleri kullanırken dikkat edin; "beklenti" ile "beklenen" aynı şey değildir.

### 10.2 Tanım

Olasılık kütle fonksiyonu $p_X$ olan kesikli bir $X$ rastgele değişkeninin beklenen değeri (ekrandan, 02:20:00):

$$E[X] = \sum_k x_k\, p_X(x_k) = \sum_k x_k \Pr(X = x_k).$$

$E[X]$, rastgele değişkenin aldığı değerlerin ortalama değerinin (average value ya da mean) bir ölçüsüdür. Genel gösterim

$$\mu = E[X] \qquad \text{ya da} \qquad \mu_X = E[X]$$

biçimindedir; buna rastgele değişkenin ortalaması da denir.

### 10.3 Özellikler

Hoca beklenen değerin özelliklerini sıraladı (ekrandan, 02:25:00):

- $E[a] = a$, her sabit $a$ için. Bir sabitin beklenen değeri kendisidir.
- $E[aX] = aE[X]$, her sabit $a$ ve her $X$ için. Skaler değerler beklenen değerin dışına çıkarılabilir.
- $E[X + Y] = E[X] + E[Y]$, her $X$ ve $Y$ için. Bu, beklenen değerin doğrusallığıdır (linearity of expectation).
- $X$ ve $Y$ bağımsızsa $E[XY] = E[X]E[Y]$. Hoca, bağımsız değillerse bu çarpımın böyle yazılamayacağını söyledi.
- $\inf X \le E[X] \le \sup X$.
- $E\big[X - E[X]\big] = E[X] - E\big[E[X]\big] = E[X] - E[X] = 0$. Burada $E[X]$ bir sabittir, bu yüzden onun beklenen değeri kendisidir.
- $g$ bir fonksiyon olsun. $E[g(X)] = \sum_k g(x_k) \Pr(X = x_k)$; $X$, $x_1, \dots, x_n$ değerlerini $p_X(x_1), \dots, p_X(x_n)$ olasılıklarıyla alır.

> **Ders sonrası not:** Hoca 4. özelliği "$E[XY] = E[X]E[Y]$ ancak ve ancak $X$ ve $Y$ bağımsızsa" diye yazdı (ekrandan, 02:25:00). Doğrusu tek yönlüdür: bağımsızlık bu eşitliği gerektirir, fakat eşitlik bağımsızlığı gerektirmez. Eşitlik sağlanan ama bağımsız olmayan değişkenler vardır; bunlara ilişkisiz (uncorrelated) denir.

**Soru:** Beklenen değer kavramına hangi durumlarda ihtiyaç duyuyoruz? **Cevap:** Olasılığın temel kavramlarından biridir ve istatistikte sürekli kullanılır: bir rastgele değişkenin ortalaması, bir fonksiyondan geçirildikten sonraki ortalaması, varyansı, basıklık (kurtosis) ve çarpıklık (skewness) gibi ölçüler bu kavramla tanımlanır.

## 11. Momentler, varyans ve standart sapma

### 11.1 Momentler

$E[g(X)]$ formülünde $g$ özel seçilerek önemli büyüklükler elde edilir (ekrandan, 02:30:00):

- $g(x) = x$ ise $E[g(X)] = E[X]$.
- $g(x) = x^\gamma$ ise $E[g(X)] = E[X^\gamma]$. Buna $X$'in **$\gamma$'ıncı momenti** denir. $\gamma = 2$ için ikinci moment, $\gamma = 3$ için üçüncü moment elde edilir.
- $g(x) = \big(x - E[X]\big)^\gamma$ ise $E\big[(X - E[X])^\gamma\big]$, $X$'in **$\gamma$'ıncı merkezî momentidir** (centered moment).

### 11.2 Varyans

$\gamma = 2$ için merkezî moment varyanstır (ekrandan, 02:35:00):

$$\mathrm{Var}(X) = E\big[(X - E[X])^2\big] = \sum_k \big(x_k - E[X]\big)^2 p_X(x_k) = \sum_k (x_k - \mu)^2 \Pr(X = x_k).$$

Varyans, birinci ve ikinci momentler cinsinden de yazılabilir. Köşeli parantez içindeki ifade ikinci dereceden bir formdur ve açılır. $\mu = E[X]$ bir sabittir; sabitler beklenen değerin dışına çıkar:

$$\begin{aligned}
\mathrm{Var}(X) &= E\big[X^2 - 2XE[X] + E[X]^2\big] \\
&= E[X^2] - 2E[X]E[X] + E[X]^2 \\
&= E[X^2] - 2E[X]^2 + E[X]^2 \\
&= E[X^2] - E[X]^2.
\end{aligned}$$

Sonuç (ekrandan, 02:40:00):

$$\boxed{\mathrm{Var}(X) = E[X^2] - E[X]^2}$$

Yani varyans, ikinci moment ile birinci momentin karesinin farkıdır.

Varyans dağılımın yayılımını (spread) ölçer. Hoca "spread" kelimesinin "yayılmak" anlamına geldiğini hatırlattı. Varyans $\sigma^2$ ile gösterilir; hangi değişkene ait olduğu belirtilmek istenirse $\mathrm{Var}(X) = \sigma_X^2$ yazılır.

### 11.3 Standart sapma

$X$ rastgele değişkeninin standart sapması varyansın kareköküdür:

$$\sigma_X = \sqrt{\mathrm{Var}(X)}.$$

Standart sapma $X$ ile aynı ölçü birimine sahiptir (ekrandan, 02:45:00).

### 11.4 Varyansın sezgisi

Hoca zaman ekseni üzerinde iki deney dizisinin sonuçlarını noktalarla çizdi: biri siyah, biri kırmızı (ekrandan, 02:45:00). İki dizinin ortalaması aynı yerde olsa da kırmızı noktalar ortalamadan daha uzağa dağılıyordu. Öğrencilere hangisinin varyansının büyük olduğunu sordu; cevap kırmızılardı. Varyans, ortalamadan olan uzaklığı ifade eder.

## 12. Varyansın özellikleri

### 12.1 Sabitin varyansı

Bir $a$ sabiti için $\mathrm{Var}(a) = E[a^2] - E[a]^2 = a^2 - a^2 = 0$. Sabit sayıların varyansı sıfırdır, çünkü ortalamadan uzaklaşma yoktur.

### 12.2 Skalerle çarpım

$$\mathrm{Var}(aX) = E[a^2X^2] - \big(E[aX]\big)^2 = a^2E[X^2] - \big(aE[X]\big)^2 = a^2\big(E[X^2] - E[X]^2\big),$$

$$\boxed{\mathrm{Var}(aX) = a^2\,\mathrm{Var}(X)}$$

(ekrandan, 02:50:00).

### 12.3 Toplamın varyansı

$$\mathrm{Var}(X + Y) = E\big[(X + Y)^2\big] - \big(E[X + Y]\big)^2 = E[X^2 + 2XY + Y^2] - \big(E[X] + E[Y]\big)^2.$$

Açılınca:

$$\mathrm{Var}(X + Y) = E[X^2] + 2E[XY] + E[Y^2] - E[X]^2 - 2E[X]E[Y] - E[Y]^2.$$

$X$ ve $Y$ bağımsızsa $E[XY] = E[X]E[Y]$ olur. Bu yazıldığında $2E[X]E[Y]$ ile $-2E[X]E[Y]$ birbirini götürür (ekrandan, 02:55:00):

$$\mathrm{Var}(X + Y) = \big(E[X^2] - E[X]^2\big) + \big(E[Y^2] - E[Y]^2\big) = \mathrm{Var}(X) + \mathrm{Var}(Y).$$

Sonuç: $X$ ve $Y$ bağımsızsa $\mathrm{Var}(X + Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$. Hoca önce "ancak ve ancak" dedi, sonra bunu "eğer" diye düzeltti ve aynı sonucun ilişkisiz (uncorrelated) değişkenler için de geçerli olduğunu, ilişkisizliğin ileride işleneceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Türetmede iptal olmayan terim $2\big(E[XY] - E[X]E[Y]\big)$'dir; bu ifade $2\,\mathrm{Cov}(X, Y)$'dir. Genel formül $\mathrm{Var}(X + Y) = \mathrm{Var}(X) + \mathrm{Var}(Y) + 2\,\mathrm{Cov}(X, Y)$'dir. Kovaryans sıfırsa (ilişkisiz değişkenler) eşitlik sağlanır; bağımsızlık bunun özel bir durumudur.

## Örnek Sorular

### Soru 1: $Z = X + Y$'nin dağılımı (ekrandan, 00:35:00 ve 00:40:00)

$X$: $\Pr(X = 0) = 3/4$, $\Pr(X = 1) = 1/4$. $Y$: 1'den 6'ya her değer $1/6$. $X$ ile $Y$ bağımsız ve $Z = X + Y$. $Z$'nin örnek uzayını ve $\Pr(Z = 1), \dots, \Pr(Z = 7)$ olasılıklarını bulun.

**Çözüm (derste verilen kısım):** $\Omega_Z = \{1, \dots, 7\}$. $\Pr(Z = 1) = \frac{3}{4} \cdot \frac{1}{6} = \frac{1}{8}$. $\Pr(Z = 2) = \frac{3}{4} \cdot \frac{1}{6} + \frac{1}{4} \cdot \frac{1}{6} = \frac{1}{8} + \frac{1}{24} = \frac{1}{6}$.

> **Çözüm (derste verilmedi):** $2 \le z \le 6$ için iki durum vardır ($X = 0, Y = z$ ve $X = 1, Y = z - 1$): $\Pr(Z = z) = \frac{3}{24} + \frac{1}{24} = \frac{1}{6}$. Böylece $\Pr(Z = 3) = \Pr(Z = 4) = \Pr(Z = 5) = \Pr(Z = 6) = \frac{1}{6}$. $Z = 7$ için yalnız $X = 1, Y = 6$ vardır: $\Pr(Z = 7) = \frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$. Kontrol: $\frac{1}{8} + 5 \cdot \frac{1}{6} + \frac{1}{24} = \frac{3 + 20 + 1}{24} = 1$. Python ile doğrulandı.

### Soru 2: $W = 2X^2/(X + Y)$'nin olasılıkları (ekrandan, 00:45:00)

Aynı $X$ ve $Y$ ile $W = \dfrac{2X^2}{X + Y}$. $W$'nin örnek uzayını ve $\Pr(W = 0)$, $\Pr(W = 1)$, $\Pr(W = 2)$, $\Pr(W = 2/3)$, $\Pr(W = 2/7)$ olasılıklarını bulun.

**Çözüm (derste verilen kısım):** $\Omega_W = \{0, 1, \frac{2}{3}, \frac{1}{2}, \frac{2}{5}, \frac{1}{3}, \frac{2}{7}\}$. $\Pr(W = 0) = \Pr(X = 0) = 3/4$ (eşit olasılık varsayılarak $1/7$ denemez). $\Pr(W = 1) = \frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$. $\Pr(W = 2) = 0$, çünkü 2 örnek uzayda yoktur.

> **Çözüm (derste verilmedi):** $W = 2/3$ yalnız $X = 1, Y = 2$ için, $W = 2/7$ yalnız $X = 1, Y = 6$ için oluşur. Bu yüzden $\Pr(W = 2/3) = \Pr(W = 2/7) = \frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$. Sıfır dışındaki altı değerin her biri $1/24$ olasılıklıdır ve $\frac{3}{4} + 6 \cdot \frac{1}{24} = 1$. Python ile doğrulandı.

### Soru 3: Tablo bağımsız mı? (ekrandan, 01:45:00)

$X \in \{0, 1\}$, $\Pr(X = 0) = 1/4$, $\Pr(X = 1) = 3/4$; $Y \in \{1, \dots, 6\}$, her değer $1/6$. Ortak tabloda $X = 0$ satırındaki her hücre $1/24$, $X = 1$ satırındaki her hücre $3/24$'tür. $X$ ve $Y$ bağımsız mıdır?

**Çözüm (derste verildi):** Her hücrede $r_{ij} = p_i q_j$ sağlanır: $\frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$ ve $\frac{3}{4} \cdot \frac{1}{6} = \frac{3}{24}$. Bu yüzden $X$ ve $Y$ bağımsızdır.

### Soru 4: Eksik hücreler (ekrandan, 01:55:00)

Hoca bunu "güzel bir sınav sorusu" diye sundu. $\Omega_X = \Omega_Y = \{0, 1\}$; ortak tabloda $r_{11} = 1/16$, $r_{21} = 3/16$; marjinaller $\Pr(X = 0) = \Pr(X = 1) = 1/2$, $\Pr(Y = 0) = 1/4$, $\Pr(Y = 1) = 3/4$. $X$ ve $Y$ birbirinden bağımsız değilse $r_{12}$ ve $r_{22}$ hakkında ne söylenebilir?

**Çözüm (derste verilen kısım):** Hoca denklemleri kurdu: $\frac{1}{16} + r_{12} = \frac{1}{2}$, $\frac{3}{16} + r_{22} = \frac{1}{2}$ ve $r_{12} + r_{22} = \frac{3}{4}$. Bu tablo bağımsız değildir, çünkü $r_{11} = 1/16 \ne \frac{1}{2} \cdot \frac{1}{4} = \frac{1}{8}$. Bağımsız olsaydı hücreler $1/8, 3/8, 1/8, 3/8$ olurdu.

> **Çözüm (derste verilmedi):** Satır denklemlerinden $r_{12} = \frac{1}{2} - \frac{1}{16} = \frac{7}{16}$ ve $r_{22} = \frac{1}{2} - \frac{3}{16} = \frac{5}{16}$ bulunur. Sütun kontrolü: $\frac{7}{16} + \frac{5}{16} = \frac{12}{16} = \frac{3}{4}$, tutarlı. Marjinaller ve ilk sütun verildiği için $r_{12}$ ve $r_{22}$ bir aralık değil, tek değer olarak belirlenir. Python ile doğrulandı.

### Soru 5: Aynı değerleri alan değişkenler (derste sözlü, 01:47:04)

İki rastgele değişkenin ikisi de $\{0, 1\}$ değerlerini alıyorsa bağımlı olduklarını söyleyebilir miyiz?

**Çözüm (derste verildi):** Hayır. Bağımsızlık değerlere değil olasılıklara bağlıdır. Ortak olasılıklar her hücrede marjinallerin çarpımına eşitse değişkenler bağımsızdır, değilse bağımlıdır. Soru 4'teki tablo aynı örnek uzayla hem bağımlı ($r_{11} = 1/16$) hem bağımsız ($r_{11} = 1/8$) kurulabildiğini gösterir.

### Soru 6: Zarın beklenen değeri (derste sözlü, 02:14:47)

Hilesiz bir zar atıldığında ne beklenir, beklenen değer nedir?

**Çözüm (derste verildi):** 1'den 6'ya kadar herhangi bir değer gelebilir. Beklenen değer ortalamadır: $E[X] = \sum_{k=1}^{6} k \cdot \frac{1}{6} = \frac{21}{6} = 3{,}5$.

### Soru 7: Hangi dizinin varyansı büyük? (ekrandan, 02:45:00)

Zaman ekseni üzerinde iki deney dizisinin sonuçları çizilmiştir; kırmızı noktalar ortalamadan siyah noktalara göre daha uzağa dağılmıştır. Hangisinin varyansı daha büyüktür?

**Çözüm (derste verildi):** Kırmızıların. Varyans ortalamadan uzaklığı ölçer; ortalamadan daha uzağa yayılan dizinin varyansı daha büyüktür.

## Dersin Toparlaması

Ders, kesikli rastgele değişkenin CDF'inden başlayıp birden fazla rastgele değişkenle çalışmaya geçti. Önce CDF'in özellikleri ve aralık olasılıklarının CDF ile nasıl hesaplandığı görüldü; temel formül $\Pr(a < X \le b) = F_X(b) - F_X(a)$'dır. Ardından rastgele değişkenler toplanıp çarpılarak yeni rastgele değişkenler elde edildi; yeni değişkenin önce örnek uzayı, sonra olasılıkları bulunur ve değerlerin eşit olasılıklı olmadığı unutulmamalıdır. İki değişken birlikte ele alındığında rastgele vektör, ortak dağılım tablosu ve marjinal dağılım kavramlarına ulaşıldı. Bağımsızlık, her hücrenin marjinallerin çarpımına eşit olmasıyla tanımlandı; değişkenlerin aldığı değerlerin bağımsızlıkla ilgisi olmadığı örneklerle gösterildi. Bağımlı durumda koşullu olasılıklar tablodan hücreyi marjinale bölerek bulunur.

Dersin son bölümünde beklenen değer ve özellikleri, momentler, varyans ($\mathrm{Var}(X) = E[X^2] - E[X]^2$), standart sapma ve varyansın özellikleri işlendi. Bağımsız değişkenler için toplamın varyansı varyansların toplamıdır. Hoca bir sonraki derste kovaryansın işleneceğini söyledi; toplamın varyansı türetilirken iptal olan terim bu konuyla doğrudan bağlantılıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
