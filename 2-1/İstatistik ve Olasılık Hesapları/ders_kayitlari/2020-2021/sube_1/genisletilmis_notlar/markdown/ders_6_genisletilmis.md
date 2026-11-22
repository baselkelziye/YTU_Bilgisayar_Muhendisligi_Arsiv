# Ders 6 Genişletilmiş Notu: Chebyshev Eşitsizliği, Kesikli Dağılım Aileleri ve Sürekli Rastgele Değişkenler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Chebyshev eşitsizliği
- 2. Bernoulli dağılımı
- 3. Binom dağılımı
- 4. Geometrik dağılım
- 5. Negatif binom dağılımı
- 6. Poisson dağılımı
- 7. Hipergeometrik ve çok terimli (multinomial) dağılım
- 8. Sürekli rastgele değişkenler, CDF ve PDF
- 9. Ortak ve marjinal yoğunluklar
- 10. Beklenen değer, varyans, kovaryans ve korelasyon
- 11. Sürekli düzgün (uniform) dağılım
- Örnek Sorular

## 1. Chebyshev eşitsizliği

Ders iPad üzerinde, "BLM2011 Lecture Notes (2020 Fall)" başlıklı not defterine el yazısıyla yürütüldü. Anlatım büyük ölçüde İngilizce, yer yer Türkçe açıklamalarla yapıldı. Ders, bir önceki derste başlanan Markov ve Chebyshev eşitsizliklerine dönülerek açıldı. Bir öğrencinin sorusu üzerine Chebyshev eşitsizliğinin ders kitabında (Baron) 3.3.7 numaralı kısımda yer aldığı belirtildi. Hoca, Markov eşitsizliğinin önemli olduğunu, çünkü Chebyshev eşitsizliğinin Markov kullanılarak ispatlandığını söyledi.

### 1.1 Teorem

Herhangi bir $Y$ rastgele değişkeni ve pozitif bir $d$ sabiti için:

$$\Pr\big(|Y - E[Y]| \ge d\big) \le \frac{\mathrm{Var}(Y)}{d^2}.$$

Bu eşitsizliğe Chebyshev eşitsizliği denir. Hoca eşitsizliğin iki tarafını ayrı ayrı yorumladı. Sol taraf bir olasılık olduğu için her zaman 0 ile 1 arasındadır. Sağ taraf ise 1'den büyük olabilir; o zaman eşitsizlik hiçbir bilgi vermez. Eşitsizliğin anlamlı olması için sağ tarafın da 1'den küçük olması, yani paydanın paydan büyük olması gerekir. Ekrandaki ifadeyle (ekrandan, 00:10:00): "Chebyshev inequality is useful when $\mathrm{Var}(Y) \ll d^2$."

Hoca ardından kesikli bir dağılımın PMF'ini çubuklarla çizdi ve eksen üzerinde $E[Y] - d$ ile $E[Y] + d$ noktalarını işaretledi. Bu iki noktanın dışında kalan çubukların toplam olasılığı, sol taraftaki $\Pr(|Y - E[Y]| \ge d)$ olasılığıdır (ekrandan, 00:15:00).

### 1.2 İspat

İspat ekranda şu adımlarla yazıldı (ekrandan, 00:15:00):

- Yeni bir rastgele değişken tanımlanır: $X = (Y - E[Y])^2$.
- Kare alındığı için $X$ her zaman sıfır ya da pozitiftir; yani $X$ negatif olmayan bir rastgele değişkendir. Bu yüzden Markov eşitsizliği $X$'e uygulanabilir.
- Markov eşitsizliği: $\Pr\big(|Y - E[Y]|^2 \ge c\big) \le \dfrac{E\big[|Y - E[Y]|^2\big]}{c}$.
- Paydaki beklenen değer varyansın tanımıdır: $\Pr\big(|Y - E[Y]|^2 \ge c\big) \le \dfrac{\mathrm{Var}(Y)}{c}$.
- İki taraf da pozitif olduğundan eşitsizliğin içinde karekök almak olayı değiştirmez: $\Pr\big(|Y - E[Y]|^2 \ge c\big) = \Pr\big(|Y - E[Y]| \ge \sqrt{c}\big)$.
- $c = d^2$ konursa $\Pr(|Y - E[Y]| \ge d) \le \mathrm{Var}(Y)/d^2$ elde edilir.

**Soru:** Bir öğrenci, ispatın Markov uygulanan satırında mutlak değerin içinde $E[Y]$ yerine yalnız $Y$ yazıldığını, orada bir $E$ eksik olduğunu söyledi. **Cevap:** Hoca uyarının doğru olduğunu, eksik harfin bir yazım hatası olduğunu kabul etti; doğru ifade $|Y - E[Y]|$'dir.

### 1.3 Standart sapma cinsinden biçim ve üç sigma kuralı

$d = k\sigma_Y$ seçilsin; burada $\sigma_Y = \sqrt{\mathrm{Var}(Y)}$ standart sapmadır. O zaman $d^2 = k^2\sigma_Y^2 = k^2\,\mathrm{Var}(Y)$ olur ve eşitsizlik şu biçimi alır (ekrandan, 00:20:00):

$$\Pr\big(|Y - E[Y]| \ge k\sigma_Y\big) \le \frac{1}{k^2}.$$

Bu da Chebyshev eşitsizliğinin alternatif bir biçimidir. Buradan **üç sigma kuralı** çıkar: $k = 3$ alınır ve tümleyen olaya geçilir:

$$\Pr\big(|Y - E[Y]| \le 3\sigma_Y\big) \ge 1 - \frac{1}{9} = \frac{8}{9}.$$

Yani herhangi bir rastgele değişkenin değerlerinin en az $8/9$'u ortalamadan en fazla üç standart sapma uzaktadır; mutlak sapması $3\sigma$'yı aşan değerlerin payı en fazla $1/9$'dur.

> **Ders sonrası not:** Hoca bu oranı %88,8 diye söyledi. $8/9 = 0{,}8888\ldots$ olduğundan yuvarlanmış değer %88,9'dur.

### 1.4 Markov ve Chebyshev ne zaman kullanılır

Hoca iki eşitsizliğin asıl değerini şöyle özetledi: PDF ya da CDF (kesikli durumda PMF ya da CDF) biliniyorsa olasılık doğrudan hesaplanabilir. Ama dağılım bilinmiyorsa elde yalnız bazı özet bilgiler olabilir. Yalnız ortalama biliniyorsa Markov eşitsizliğiyle, varyans da biliniyorsa Chebyshev eşitsizliğiyle olasılığa bir sınır konabilir.

## 2. Bernoulli dağılımı

Bu noktadan sonra kesikli dağılım ailelerine (families of discrete distributions) geçildi.

### 2.1 Tanım

Bernoulli denemesi (Bernoulli trial), yalnız iki olası sonucu olan bir deneydir. Para atmak bir Bernoulli denemesidir. İki sonuç sırasıyla 0 ve 1 diye etiketlenir.

$p$ parametreli ($0 \le p \le 1$) bir Bernoulli rastgele değişkeni 0 değerini (başarısızlık; para örneğinde yazı) $1-p$ olasılıkla, 1 değerini (başarı; para örneğinde tura) $p$ olasılıkla alır. Yani $p$ başarı olasılığıdır. $X \sim \mathrm{Bernoulli}(p)$ gösterimi, $X$'in $p$ parametreli Bernoulli dağılımına uyduğunu anlatır. Sonuç kümesi $\{0, 1\}$'dir ve büyüklüğü 2'dir; $x_0 = 0$, $x_1 = 1$ yazılır.

### 2.2 Beklenen değer, ikinci moment ve varyans

Beklenen değerin tanımından:

$$E[X] = \sum_{\forall x_k} x_k \Pr(X = x_k) = 0\cdot\Pr(X=0) + 1\cdot\Pr(X=1) = p.$$

Bu, Bernoulli rastgele değişkeninin ortalamasıdır.

**Soru:** Hoca ikinci momentin nasıl bulunacağını sordu; bir öğrenci "$p^2$" dedi. **Cevap:** Hoca önce karenin alınması gerektiğini, yani tanımın uygulanması gerektiğini gösterdi:

$$E[X^2] = \sum_{\forall x_k} x_k^2 \Pr(X = x_k) = 0^2\cdot(1-p) + 1^2\cdot p = p.$$

Varyans ikinci momentten birinci momentin karesinin çıkarılmasıyla bulunur:

$$\mathrm{Var}(X) = E[X^2] - E[X]^2 = p - p^2 = p(1-p).$$

$0 \le p \le 1$ olduğundan $p(1-p) \ge 0$'dır; varyans negatif olamayacağı için sonuç tutarlıdır (ekrandan, 00:35:00).

### 2.3 Birim basamak fonksiyonu ile CDF

Bernoulli rastgele değişkeninin CDF'i tanımdan başlanarak bulundu (ekrandan, 00:35:00 ve 00:40:00):

$$F_X(x) = \Pr(X \le x) = \sum_{x_k \le x} \Pr(X = x_k).$$

Hoca öğrencilere birim basamak (unit step) fonksiyonunu daha önce görüp görmediklerini sordu. Öğrenciler bunu daha önceki derslerden hatırladı: belli bir noktaya kadar 0 olan, o noktadan sonra birden 1'e çıkan ve öyle devam eden bir sinyal. Tanım:

$$u(x) = \begin{cases} 1, & x \ge 0 \\ 0, & x < 0 \end{cases}$$

$u(x - a)$ ise sıçramanın $x = a$ noktasında olduğu kaydırılmış basamaktır; $x = a$'da dolu nokta değer 1'dedir. Bu fonksiyon sayesinde koşullu toplam, bütün $x_k$'lar üzerinden alınan bir toplama çevrilebilir:

$$\sum_{x_k \le x} \Pr(X = x_k) = \sum_{\forall x_k} \Pr(X = x_k)\,u(x - x_k).$$

$x_k > x$ olan terimlerde $u(x - x_k) = 0$ olduğu için bu terimler kendiliğinden düşer.

> **Hocanın vurgusu:** Bu iki toplamın birbirine eşit olduğunu çok iyi anlayın.

Bernoulli için yalnız iki terim vardır:

$$F_X(x) = \Pr(X = x_0)\,u(x - x_0) + \Pr(X = x_1)\,u(x - x_1) = (1-p)\,u(x) + p\,u(x-1).$$

Grafiği: $x < 0$ için 0; $x = 0$'da $1-p$ yüksekliğine sıçrar ve $0 \le x < 1$ boyunca $1-p$'de kalır; $x = 1$'de 1'e sıçrar ve sonsuza kadar 1'de kalır. Hoca grafikte $x = 1$'deki sıçrama mesafesini sordu; bu mesafe $1 - (1-p) = p$'dir (ara adım eklendi).

## 3. Binom dağılımı

### 3.1 Tanım ve PMF

Sabit başarı olasılığı $p$ olan $n$ bağımsız Bernoulli denemesi düşünülsün. Bu denemelerdeki toplam başarı sayısı $X$, binom dağılımlı kesikli bir rastgele değişkendir. Parametreleri deneme sayısı $n$ ve başarı olasılığı $p$'dir. Gösterim: $X \sim \mathrm{Binomial}(n, p)$ ya da kısaca $X \sim \mathrm{Bin}(n,p)$.

PMF:

$$\Pr(X = k) = \binom{n}{k} p^k (1-p)^{n-k}, \qquad k = 0, 1, 2, \dots, n.$$

Burada $k$ başarı sayısı, $n - k$ başarısızlık sayısıdır. Başarı sayısı $n$'den büyük olamaz, çünkü toplam deneme sayısı $n$'dir.

### 3.2 Beklenen değer: türev hilesi

Tanımdan, $x_k = k$ ($x_0 = 0, x_1 = 1, \dots, x_n = n$) alınarak (ekrandan, 00:50:00):

$$E[X] = \sum_{k=0}^{n} k \binom{n}{k} p^k (1-p)^{n-k}.$$

Hoca bu toplamın nasıl sadeleşeceğini sordu ve şu fikri gösterdi: $k$ sayısı bir türev olarak yazılabilir,

$$k = \frac{\partial}{\partial a} a^k \Big|_{a=1} = k\,a^{k-1}\Big|_{a=1} = k.$$

Bu yazılıp türev ve toplam yer değiştirilir; ikisi de doğrusal işlem olduğu için sıraları değiştirilebilir:

$$E[X] = \frac{\partial}{\partial a}\left[\sum_{k=0}^{n}\binom{n}{k}(ap)^k(1-p)^{n-k}\right]_{a=1}.$$

Köşeli parantezdeki toplam binom açılımıdır (binom serisi): $(ap + 1 - p)^n$. Türevi alınır (ara adım eklendi): içteki ifadenin türevi $p$ olduğundan

$$\frac{\partial}{\partial a}(ap + 1 - p)^n = n(ap + 1 - p)^{n-1}p,$$

ve $a = 1$'de $(p + 1 - p)^{n-1} = 1$ olduğundan

$$E[X] = np.$$

### 3.3 İkinci moment ve varyans

$$E[X^2] = \sum_{k=0}^{n} k^2 \Pr(X = k).$$

Hoca $k^2$'nin türev cinsinden nasıl yazılacağını sordu. Bir öğrencinin önerisi sorulan şeye uymadı; hoca yukarıdaki mantığı genişletti: $k^2 = k\cdot k$ olduğundan iki ayrı değişkene göre birer kez türev alınır (ekrandan, 00:55:00):

$$k^2 = k\cdot k = \frac{\partial^2}{\partial a\,\partial b}(ab)^k\Big|_{a=1,\,b=1}.$$

Bunu kullanınca

$$E[X^2] = np(1-p) + n^2p^2$$

bulunur. Varyans:

$$\mathrm{Var}(X) = E[X^2] - E[X]^2 = np(1-p) + n^2p^2 - (np)^2 = np(1-p).$$

$n^2p^2$ terimleri birbirini götürür.

> **Ek bilgi (derste anlatılmadı):** Ara adımlar şöyledir: $\sum_k \binom{n}{k}(abp)^k(1-p)^{n-k} = (abp + 1 - p)^n$. Önce $b$'ye göre türev $n(abp+1-p)^{n-1}ap$, sonra $a$'ya göre türev $n(n-1)(abp+1-p)^{n-2}(bp)(ap) + n(abp+1-p)^{n-1}p$ verir. $a = b = 1$'de bu $n(n-1)p^2 + np = np(1-p) + n^2p^2$ olur.

Son olarak hoca $\binom{n}{k}$'nın neye eşit olduğunu ve adını sordu. Bir öğrenci $\frac{n!}{k!(n-k)!}$ olduğunu ve adının kombinasyon olduğunu söyledi (ekrandan, 01:10:00).

## 4. Geometrik dağılım

### 4.1 Tanım

Sabit başarı olasılığı $p$ olan bağımsız Bernoulli denemeleri dizisi düşünülsün (ekrandan, 01:10:00). İlk başarı dahil, ilk başarıya kadar yapılan deneme sayısı $X$, $p$ parametreli geometrik dağılımlı kesikli bir rastgele değişkendir: $X \sim \mathrm{Geom}(p)$.

Örnek: Para ilk tura gelene kadar atılır. Yazı gelir, tekrar atılır; yine yazı gelir, tekrar atılır; tura gelince durulur. Atış sayısı geometrik dağılımlıdır.

### 4.2 PMF

PMF şöyledir (ekrandan, 01:15:00):

$$\Pr(X = k) = (1-p)^{k-1}\,p.$$

Burada $k$, ilk başarıyı bulmak için gereken deneme sayısıdır. $(1-p)^{k-1}$ ilk $k-1$ denemenin başarısız olma olasılığı, $p$ ise $k$'ıncı denemenin başarılı olma olasılığıdır.

> **Ders sonrası not:** Ekranda açıklama "the first $(n-1)$ trials are failure" diye yazıldı; formüldeki üsse uygun doğru ifade "ilk $k-1$ deneme"dir.

**Soru:** Hoca $k$'nın hangi değerleri alabileceğini sordu. Bir öğrenci pozitif olması gerektiğini, bir başkası $k = 0$ olamayacağını söyledi. **Cevap:** En az bir deneme yapılmadan başarı gelemez, bu yüzden $k$ 1'den başlar: $k = 1, 2, 3, \dots$; yani $k$, sıfır hariç doğal sayılardır.

### 4.3 Beklenen değer ve varyans

Hoca sonuçları verdi, türetmeyi öğrencilere bıraktı:

$$E[X] = \frac{1}{p}, \qquad \mathrm{Var}(X) = \frac{1-p}{p^2}.$$

Türetmede geometrik seri kullanılır. Sonlu toplam $r^0 + r^1 + \dots$ için kapalı formül verildi ve $|r| < 1$ iken sonsuz toplamın (ekrandan, 01:20:00)

$$r^0 + r^1 + r^2 + r^3 + \cdots = \frac{1}{1-r}, \qquad |r| < 1$$

olduğu hatırlatıldı.

> **Ders sonrası not:** Hoca sonlu toplamı $r^0$'dan $r^n$'e kadar sayıp $\frac{1-r^n}{1-r}$ dedi. Doğrusu $\sum_{k=0}^{n} r^k = \frac{1-r^{n+1}}{1-r}$'dir ($\frac{1-r^n}{1-r}$, $r^0$'dan $r^{n-1}$'e kadar olan $n$ terimin toplamıdır). Dersin sonunda hoca bu formülü $n+1$ üssüyle doğru söyledi. Sonsuz toplamın limiti iki durumda da aynıdır.

Bu sonuçlar python ile sayısal olarak doğrulandı ($p = 0{,}3$ için $E[X] = 3{,}33$, $\mathrm{Var}(X) = 7{,}78$).

## 5. Negatif binom dağılımı

Bir öğrenci bu dağılımın "başarı sayısı $r$ olana kadar" mı olduğunu sordu; hoca evet dedi ve tanımı yazdı (ekrandan, 01:20:00): Sabit başarı olasılığı $p$ olan bağımsız Bernoulli denemeleri dizisinde $r$'inci başarı dahil, ona kadar yapılan toplam deneme sayısı $X$, $p$ ve $r$ parametreli negatif binom dağılımlı kesikli bir rastgele değişkendir. Geometrik dağılımda ilk başarı beklenir; burada $r$'inci başarı beklenir. Gösterim: $X \sim \mathrm{NB}(r, p)$.

Hoca bunu para atma ile anlattı: Para atılır, sonuca bakılır. Yazı gelirse bir şey sayılmaz, tura gelirse sayılır: bir, sonra iki, sonra üç... Turaların sayısı $r$ olana kadar atmaya devam edilir. Toplam atış sayısının dağılımı negatif binomdur.

PMF:

$$\Pr(X = k) = \binom{k-1}{r-1}p^r(1-p)^{k-r}, \qquad k = r, r+1, r+2, \dots$$

Burada $r$ başarı sayısı, $k - r$ başarısızlık sayısıdır. $k$ en az $r$ olabilir, çünkü $r$ başarı için en az $r$ deneme gerekir.

<!-- BELİRSİZ: Altyazıda binom katsayısı "R minus 1, k minus 1" sırasıyla okunuyor ve PMF karesi yok; yukarıdaki $\binom{k-1}{r-1}$ standart biçimdir ve sayısal olarak (toplamın 1 olması, ortalama ve varyans) doğrulandı. -->

Beklenen değer ve varyans (ekrandan, 01:25:00):

$$E[X] = \frac{r}{p}, \qquad \mathrm{Var}(X) = \frac{r(1-p)}{p^2}.$$

> **Ek bilgi (derste anlatılmadı):** $r = 1$ alındığında negatif binom dağılımı geometrik dağılıma indirgenir; formüller de $1/p$ ve $(1-p)/p^2$ olur.

## 6. Poisson dağılımı

### 6.1 Nadir olaylar

Poisson dağılımı nadir olaylarla (rare events) ilgilidir: kısa bir zaman diliminde gerçekleşmesi son derece olası olmayan olaylar. Hocanın verdiği örnekler: iş gelişleri (arrivals of jobs), telefon çağrıları, e-posta mesajları, virüs saldırıları, trafik kazaları, ağ ve yazılım hataları, sel ve deprem. Hoca bu örneklerin Poisson dağılımının literatürde çok uygulaması olduğunu gösterdiğini söyledi.

Sabit (fixed) bir zaman aralığında gerçekleşen nadir olayların sayısı Poisson dağılımlıdır. Gösterim (ekrandan, 01:30:00): $X \sim \mathrm{Poisson}(\lambda)$ ya da $X \sim \mathrm{Pois}(\lambda)$. Burada $\lambda$ ortalama olay sayısıdır, başka bir deyişle ortalama frekanstır.

### 6.2 PMF

$$\Pr(X = k) = \frac{\lambda^k}{k!}e^{-\lambda}, \qquad k = 0, 1, 2, \dots$$

Yani $k$ bütün doğal sayıları alabilir.

### 6.3 Beklenen değer

Tanımdan:

$$E[X] = \sum_{k=0}^{\infty} k\,\frac{\lambda^k}{k!}e^{-\lambda}.$$

$e^{-\lambda}$ terimi $k$'ya bağlı olmadığı için toplamın dışına çıkar. Binomdaki gibi $k = \frac{\partial}{\partial a}a^k\big|_{a=1}$ yazılır ve türev ile toplamın sırası değiştirilir:

$$E[X] = e^{-\lambda}\,\frac{\partial}{\partial a}\left[\sum_{k=0}^{\infty}\frac{(a\lambda)^k}{k!}\right]_{a=1}.$$

Hoca köşeli parantezdeki serinin neye eşit olduğunu sordu. Cevap üstel fonksiyonun serisidir; ekranın köşesine yazıldı (ekrandan, 01:40:00):

$$e^x = \sum_{k=0}^{\infty}\frac{x^k}{k!}.$$

Böylece seri $e^{a\lambda}$'dır. Türevi $\lambda e^{a\lambda}$, $a = 1$'de $\lambda e^{\lambda}$ olur ve (ara adım eklendi)

$$E[X] = e^{-\lambda}\cdot\lambda e^{\lambda} = \lambda.$$

> **Hocanın vurgusu:** Bu tür seri açılımlarına hazır olun; olasılık hesabı bu matematik temelleri gerektirir.

Varyansın da $\lambda$ olduğu söylendi, türetmesi öğrencilere bırakıldı: $E[X] = \lambda$, $\mathrm{Var}(X) = \lambda$ (ekrandan, 01:40:00).

### 6.4 Poisson değişkenlerin toplamı

Ekrana şu sonuç yazıldı (ekrandan, 01:40:00): $X \sim \mathrm{Poisson}(\lambda)$ ve $Y \sim \mathrm{Poisson}(\nu)$ ise $Z = X + Y$, $\lambda + \nu$ parametreli Poisson dağılımına uyar: $Z \sim \mathrm{Poisson}(\lambda + \nu)$. Bunun gösterilmesi istendi.

> **Ders sonrası not:** Ekrandaki ifadede bağımsızlık koşulu yazılmadı. Bu sonuç $X$ ile $Y$ bağımsız olduğunda geçerlidir.

### 6.5 Binom dağılımına Poisson yaklaşımı

Poisson dağılımı, binom dağılımının bir yaklaşımıdır. Deneme sayısı sonsuza, başarı olasılığı sıfıra giderken çarpımları sabit kalırsa ($np = \lambda$):

$$\lim_{\substack{n\to\infty,\ p\to 0\\ np=\lambda}}\binom{n}{k}p^k(1-p)^{n-k} = \frac{\lambda^k}{k!}e^{-\lambda}.$$

Sol taraf binomun, sağ taraf Poisson'un PMF'idir. Hoca bunun pratik bir sonucunu da söyledi: Poisson rastgele değişkeni üretmek için deneme sayısı çok büyük, başarı olasılığı çok küçük ve çarpımları sabit olan binom değişkenler üretilebilir. Yaklaşım python ile kontrol edildi ($\lambda = 2{,}5$, $n = 100000$ için ilk dört olasılık virgülden sonra beş basamak uyuşuyor).

## 7. Hipergeometrik ve çok terimli (multinomial) dağılım

### 7.1 Hipergeometrik dağılım

Hoca hipergeometrik dağılımı derste anlatmadı. Ders kitabında iyi açıklandığını ve örneklendirildiğini, binom ve negatif binom dağılımı bilindikten sonra kolay anlaşılacağını söyledi ve bu konunun kitaptan çalışılmasını istedi.

### 7.2 Çok terimli dağılım

$n$ bağımsız denemeden oluşan bir dizi düşünülsün; her deneme $k$ sonuçtan birini verir. Sonuçların olasılıkları $p_1, p_2, \dots, p_k$'dır ve

$$p_1 + p_2 + \cdots + p_k = 1.$$

$X_1, X_2, \dots, X_k$ rastgele değişkenleri her sonucun kaç kez görüldüğünü sayar. Bu değişkenler birlikte çok terimli dağılıma uyar. Değişken sayısı birden fazla olduğu için PMF bir ortak (joint) PMF'tir (ekrandan, 01:50:00):

$$\Pr(X_1 = n_1 \cap X_2 = n_2 \cap \cdots \cap X_k = n_k) = \frac{n!}{n_1!\,n_2!\cdots n_k!}\,p_1^{n_1}p_2^{n_2}\cdots p_k^{n_k},$$

burada $n_1 + n_2 + n_3 + \cdots + n_k = n$.

Her $X_i$ tek başına ele alınınca binom dağılımlıdır (ilgili sonuç "başarı", diğerleri "başarısızlık"):

$$E[X_i] = np_i, \qquad \mathrm{Var}(X_i) = np_i(1-p_i), \qquad i = 1, 2, \dots, k.$$

Önemli bir not: $X_1, X_2, \dots, X_k$ bağımsız değildir. Bağımsız olsalardı ortak PMF binom PMF'lerinin çarpımı olurdu; oysa öyle değildir.

Hoca sezgi için para örneği verdi: tek paranın atılması Bernoulli'dir; birden fazla paranın aynı anda atılmasını çok terimli duruma örnek gösterdi.

> **Ders sonrası not:** Bu benzetme kesin değildir. $n$ para atılıp tura sayısı sayılırsa her deneme yine iki sonuçludur ve sonuç binomdur. Çok terimli dağılımın tipik örneği her denemenin ikiden fazla sonucu olduğu durumdur; örneğin bir zarın $n$ kez atılıp her yüzün kaç kez geldiğinin sayılması ($k = 6$). İki paranın birlikte atılması tek bir deneme sayılırsa (YY, YT, TT gibi üç sonuç) çok terimli yapı elde edilir.

Çok terimli PMF'in toplamının 1 olduğu, $E[X_1] = np_1$ ve $\mathrm{Var}(X_1) = np_1(1-p_1)$ olduğu küçük bir örnekle ($n = 4$; $p = 1/2, 1/3, 1/6$) python'da tam kesirlerle doğrulandı.

## 8. Sürekli rastgele değişkenler, CDF ve PDF

Arada verilen moladan sonra yeni bölüme, sürekli rastgele değişkenlere ve dağılımlarına geçildi. Bu, ders kitabının (Baron) 4. bölümüdür. Kesikli rastgele değişkenler burada bitirildi.

### 8.1 Sürekli rastgele değişken

Sürekli rastgele değişken, sayılamayacak kadar sonsuz (uncountably infinite) sayıda değer alabilen rastgele değişkendir. Böyle bir değişkenin aldığı değerlerin kümesinin büyüklüğü sonsuzdur. Sürekli bir rastgele değişkenin dağılım fonksiyonu, yani birikimli dağılım fonksiyonu (CDF, cumulative distribution function)

$$F_X(x) = \Pr(X \le x)$$

olarak tanımlanır ve süreklidir; basamak (merdiven) biçiminde değildir.

### 8.2 Kesikli ve sürekli CDF karşılaştırması

Hoca iki CDF çizdi (ekrandan, 02:15:00): solda $F_Y(y)$, $y_1, y_2, y_3$ noktalarında sıçrayan ve 1'de duran bir basamak fonksiyonu; sağda $F_X(x)$, 0'dan 1'e düzgün biçimde artan bir eğri.

**Soru:** Soldaki CDF'e bakılırsa $Y$ kaç farklı değer alabilir? **Cevap:** Üç: $y_1, y_2, y_3$. $X$ ise sonsuz sayıda değer alabilir.

Ekrandaki sonuç: $Y$ kesikli bir rastgele değişkendir, çünkü alabileceği değer sayısı yalnız 3'tür. $X$ süreklidir, çünkü alabileceği değer sayısı sayılamayacak kadar sonsuzdur. Hoca, sürekliliği belirleyenin grafiğin biçimi değil, değişkenin alabileceği değer sayısı olduğunu vurguladı.

### 8.3 Olasılık yoğunluk fonksiyonu (PDF)

Olasılık yoğunluk fonksiyonu (probability density function, PDF), CDF'in türevi olarak tanımlanır. Hoca bunu bir yoğunluk eğrisi üzerinde gösterdi (ekrandan, 02:20:00): eğrinin altında $x$ ile $x + \Delta x$ arasında taranmış ince bir şerit çizildi. Bu şeridin alanı

$$\int_x^{x+\Delta x} f_X(t)\,dt = \text{taranmış alan} = \Pr(x < X \le x + \Delta x)$$

dir. Aynı olasılık CDF cinsinden $F_X(x + \Delta x) - F_X(x)$'tir. $\Delta x$ çok küçükken şerit boyunca $f_X$ hemen hemen sabittir; sabit olduğu için integralin dışına çıkar ve integral $f_X(x)\Delta x$'e yaklaşır:

$$\lim_{\Delta x \to 0}\int_x^{x+\Delta x} f_X(t)\,dt = f_X(x)\,\Delta x.$$

İki denklem birleştirilip $\Delta x$'e bölününce (ekrandan, 02:25:00):

$$f_X(x) = \lim_{\Delta x \to 0}\frac{F_X(x + \Delta x) - F_X(x)}{\Delta x} = \frac{d}{dx}F_X(x).$$

### 8.4 PDF ve CDF'in özellikleri

Ekranda sıralanan özellikler (ekrandan, 02:25:00):

- $f_X(x) \ge 0$, her $x \in \mathbb{R}$ için. PDF bütün $x$ değerlerinde sıfır ya da pozitif olmak zorundadır.
- $F_X(x) = \Pr(X \le x) = \int_{-\infty}^{x} f_X(t)\,dt$. $f_X$ hiç negatif olmadığı için $F_X$ artan bir fonksiyondur.
- $\Pr(a < X \le b) = F_X(b) - F_X(a) = \int_a^b f_X(x)\,dx$.
- $X$ sürekli ve $c$ bir sabitse $\Pr(X = c) = 0$.

> **Ders sonrası not:** Kayıttaki karede ikinci özellikte integralin sınırları alt sınır $x$, üst sınır $+\infty$ olarak görünüyor; hoca yazarken sözlü olarak sınırla ilgili bir düzeltme yaptı ama karede düzeltilmiş hâli görünmüyor. Doğru ifade alt sınır $-\infty$, üst sınır $x$ olan yukarıdaki integraldir; hoca ders sonunda uniform örneğinde de bu biçimi kullandı (ekrandan, 03:10:00).

Son özellik için hocanın sezgisi şuydu: sürekli değişkenin örnek uzayında sonsuz sayıda eleman vardır. Bütün değerlerin eşit olasılıklı olduğu kabul edilse bile tek bir değerin olasılığı $1/|\text{örnek uzay}|$ gibi olur, bu da sıfıra gider.

> **Ek bilgi (derste anlatılmadı):** Aynı sonuç üçüncü özellikten de çıkar: $\Pr(X = c) \le \Pr(c - \varepsilon < X \le c) = \int_{c-\varepsilon}^{c} f_X(x)\,dx$ ve $\varepsilon \to 0$ iken bu integral sıfıra gider. Bu yüzden sürekli değişkenlerde $\Pr(a < X \le b)$, $\Pr(a \le X \le b)$ ve $\Pr(a < X < b)$ birbirine eşittir.

## 9. Ortak ve marjinal yoğunluklar

### 9.1 Ortak CDF ve ortak PDF

Bir rastgele vektörün $(X, Y)$ ortak birikimli dağılım fonksiyonu (joint CDF), kesikli durumda görülenle aynı tanıma sahiptir:

$$F_{X,Y}(x, y) = \Pr(X \le x \cap Y \le y).$$

Ortak olasılık yoğunluk fonksiyonu (joint PDF), ortak CDF'in $x$ ve $y$'ye göre türevidir:

$$f_{X,Y}(x, y) = \frac{\partial^2}{\partial x\,\partial y}F_{X,Y}(x, y).$$

### 9.2 Marjinal yoğunluklar ve olasılık hesabı

Marjinal yoğunluklar, ortak PDF'in istenmeyen değişkene göre bütün eksen boyunca integrallenmesiyle bulunur (ekrandan, 02:35:00):

$$f_X(x) = \int_{-\infty}^{+\infty} f_{X,Y}(x, y)\,dy, \qquad f_Y(y) = \int_{-\infty}^{+\infty} f_{X,Y}(x, y)\,dx.$$

Bir $A$ bölgesinin olasılığı çift katlı integralle hesaplanır:

$$\Pr\big((X, Y) \in A\big) = \iint_A f_{X,Y}(x, y)\,dx\,dy.$$

### 9.3 Marjinal CDF'ler

Marjinal CDF de ortak yoğunluktan bulunabilir:

$$F_X(x) = \int_{-\infty}^{x}\int_{-\infty}^{+\infty} f_{X,Y}(t, y)\,dy\,dt = F_{X,Y}(x, \infty),$$

$$F_Y(y) = \int_{-\infty}^{y}\int_{-\infty}^{+\infty} f_{X,Y}(x, t)\,dx\,dt = F_{X,Y}(\infty, y).$$

Hoca bunun pratik anlamını vurguladı: ortak CDF biliniyorsa marjinal CDF, kurtulmak istenen değişkenin yerine sonsuz konarak çok kolay bulunur.

### 9.4 Ortak CDF'in sınır değerleri

Hoca $F_{X,Y}(\infty, \infty)$'un neye eşit olduğunu sordu; bir öğrenci 1 dedi ve hoca bunu çok iyi bir çıkarım olarak karşıladı. Ardından eksi sonsuzdaki değerler soruldu; cevap 0'dı. Ekrandaki liste (ekrandan, 02:40:00):

- $F_{X,Y}(\infty, \infty) = 1$
- $F_{X,Y}(-\infty, -\infty) = 0$
- $F_{X,Y}(-\infty, \infty) = F_X(-\infty) = 0$
- $F_{X,Y}(\infty, -\infty) = F_Y(-\infty) = 0$

Gerekçe: $F_X(-\infty)$, $X$'in eksi sonsuzdan küçük ya da ona eşit olma olasılığıdır. Eksi sonsuz zaten en küçük şeydir; hiçbir değer ondan küçük olamaz, bu olasılık sıfırdır.

## 10. Beklenen değer, varyans, kovaryans ve korelasyon

### 10.1 Beklenen değer

Sürekli bir $X$ rastgele değişkeninin beklenen değeri

$$E[X] = \int_{-\infty}^{+\infty} x\,f_X(x)\,dx$$

ile verilir. Kesikli durumda bu $E[X] = \sum_{\forall x_k} x_k \Pr(X = x_k)$ idi; sürekli durumda toplamın yerini integral, $\Pr(X = x_k)$'nin yerini PDF alır.

> **Ders sonrası not:** Hoca sözlü anlatımda bir an integralin içindeki fonksiyona "CDF" dedi; doğrusu PDF'tir, $f_X(x)$.

### 10.2 Varyans

$$\mathrm{Var}(X) = E\big[(X - E[X])^2\big] = \int_{-\infty}^{+\infty}(x - E[X])^2 f_X(x)\,dx.$$

$(x - E[X])^2$ açılıp yerine konunca

$$\mathrm{Var}(X) = E[X^2] - E[X]^2$$

elde edilir. Varyansın tanımı kesikli durumdakine benzerdir; yalnız toplamın yerini integral alır.

### 10.3 Kovaryans

İki sürekli rastgele değişkenin kovaryansı (ekrandan, 02:50:00):

$$\mathrm{Cov}(X, Y) = E\big[(X - E[X])(Y - E[Y])\big] = E[XY] - E[X]E[Y] = \int_{-\infty}^{\infty}\int_{-\infty}^{\infty} xy\,f_{X,Y}(x, y)\,dx\,dy - E[X]E[Y].$$

$X$ ve $Y$ bağımsız iki sürekli rastgele değişkense ortak PDF marjinallerin çarpımıdır:

$$f_{X,Y}(x, y) = f_X(x)\,f_Y(y).$$

Bu durumda kovaryans sadeleşir: çift integral iki tek integralin çarpımına ayrılır, $\int x f_X(x)\,dx \cdot \int y f_Y(y)\,dy = E[X]E[Y]$ olur ve sonuç

$$\mathrm{Cov}(X, Y) = E[X]E[Y] - E[X]E[Y] = 0$$

çıkar. Bu, $X$ ve $Y$'nin ilişkisiz (uncorrelated) sürekli rastgele değişkenler olduğu anlamına gelir.

### 10.4 Korelasyon katsayısı

Hoca korelasyon katsayısının daha önce görüldüğünü hatırlattı:

$$\rho_{X,Y} = \frac{\mathrm{Cov}(X, Y)}{\sqrt{\mathrm{Var}(X)\,\mathrm{Var}(Y)}}, \qquad -1 \le \rho_{X,Y} \le +1.$$

$\rho_{X,Y} = 0$ ise $X$ ve $Y$ ilişkisizdir. Ekrana şu iki cümle yazıldı (ekrandan, 02:55:00): "Uncorrelation does not mean independence. Independence means uncorrelation." Yani ilişkisizlik bağımsızlık demek değildir; bağımsızlık ise ilişkisizlik demektir.

### 10.5 Gauss değişkenler için önemli not

Hoca bunu "çok önemli bir not" diye kırmızıyla yazdı: $X$ ve $Y$ rastgele değişkenleri Gauss (normal) dağılımına uyuyorsa ilişkisizlik bağımsızlık demektir, bağımsızlık da ilişkisizlik demektir.

> **Hocanın vurgusu:** $X$ ve $Y$ Gauss dağılımlıysa ve ilişkisizse aynı zamanda bağımsızdır. Ama $X$ ve $Y$'den herhangi biri Gauss değilse, ilişkisiz olmaları bağımsız oldukları anlamına gelmez. Bağımsızlarsa, dağılımları ne olursa olsun ilişkisizdirler. Bu çok önemlidir.

Hoca kuralı bir öğrenciye tekrarlattı. Öğrencinin cevabı: bağımsızlık varsa ilişkisizlik kesindir, Gauss olsun olmasın; ama tersi, değişkenler Gauss dağılımına uymuyorsa doğru değildir. Hoca bu cevabı doğru buldu.

> **Ders sonrası not:** Kesin ifade şudur: ilişkisizliğin bağımsızlık anlamına gelmesi için $X$ ile $Y$'nin ortak (jointly) Gauss olması gerekir. Her birinin ayrı ayrı Gauss olması yetmez; marjinalleri Gauss olduğu hâlde ilişkisiz ama bağımlı değişken çiftleri kurulabilir.

## 11. Sürekli düzgün (uniform) dağılım

Ders konusu bittikten sonra hoca isteyenler için bir örnek yaptı: sürekli rastgele değişken ailelerinden düzgün (uniform) dağılımın PDF, CDF, ortalama ve varyans hesabı.

### 11.1 Tanım ve PDF

Düzgün dağılımlı bir rastgele değişken $[a, b]$ aralığında dağılır ve aralıktaki her değerin olabilirliği aynıdır. Bir öğrenci bunun "equally likely outcomes" (eşit olabilirlikli sonuçlar) olduğunu söyledi; hoca onayladı. Hoca, "possibility"nin Türkçe karşılığının olabilirlik, "probability"ninkinin olasılık olduğunu belirtti.

$X$, $[a, b]$ aralığından rastgele (at random, randomly) bir reel sayı seçme deneyinin sonucunu gösteren düzgün rastgele değişken olsun. Seçim eşit olabilirlikle yapıldığından PDF aralık boyunca sabittir ve yüksekliği $\frac{1}{b-a}$'dır. Bu yükseklik, eğri altındaki toplam alanın 1 olmasından gelir (ekrandan, 03:10:00):

$$\int_a^b \frac{1}{b-a}\,dx = \frac{x}{b-a}\Big|_a^b = \frac{b}{b-a} - \frac{a}{b-a} = \frac{b-a}{b-a} = 1.$$

Parçalı fonksiyon olarak PDF:

$$f_X(x) = \begin{cases}\dfrac{1}{b-a}, & x \in [a, b] \\[4pt] 0, & \text{aksi hâlde}\end{cases}$$

### 11.2 CDF

$$F_X(x) = \Pr(X \le x) = \int_{-\infty}^{x} f_X(t)\,dt.$$

Hoca bu integralin sonucunu sordu; bir öğrenci doğrusal bir çizgi olacağını söyledi ve hoca onayladı. Üç durum vardır:

- $x < a$ ise integral, PDF'in sıfır olduğu bölgede alınır: $F_X(x) = 0$.
- $a \le x \le b$ ise $F_X(x) = \int_a^x \frac{1}{b-a}\,du = \frac{x-a}{b-a}$.
- $x > b$ ise $F_X(x) = \int_a^b \frac{1}{b-a}\,du = 1$.

$$F_X(x) = \begin{cases} 0, & x < a \\[2pt] \dfrac{x-a}{b-a}, & a \le x \le b \\[4pt] 1, & x > b \end{cases}$$

### 11.3 Beklenen değer

PDF $a$ ile $b$ arasında simetrik olduğu için ortalamanın aralığın ortası olması beklenir. Tanımdan (ekrandan, 03:15:00):

$$E[X] = \int_a^b x\,\frac{1}{b-a}\,dx = \frac{1}{b-a}\cdot\frac{x^2}{2}\Big|_a^b = \frac{b^2 - a^2}{2(b-a)} = \frac{a+b}{2}.$$

Hoca hesap sırasında integralin içine bir an PDF yerine CDF ifadesini yazdı, sonra fark edip düzeltti; yukarıdaki doğru hâlidir.

### 11.4 İkinci moment ve varyans

$$E[X^2] = \int_{-\infty}^{+\infty} x^2 f_X(x)\,dx = \frac{1}{b-a}\int_a^b x^2\,dx = \frac{x^3}{3(b-a)}\Big|_a^b = \frac{b^3 - a^3}{3(b-a)}.$$

$b^3 - a^3 = (b-a)(a^2 + ab + b^2)$ çarpanlarına ayrılınca $(b-a)$ sadeleşir (ekrandan, 03:20:00):

$$E[X^2] = \frac{a^2 + ab + b^2}{3}.$$

Varyans:

$$\mathrm{Var}(X) = E[X^2] - E[X]^2 = \frac{a^2 + ab + b^2}{3} - \frac{(a+b)^2}{4} = \frac{(b-a)^2}{12}.$$

Ara adım (ara adım eklendi): ortak payda 12 ile $\frac{4a^2 + 4ab + 4b^2 - 3a^2 - 6ab - 3b^2}{12} = \frac{a^2 - 2ab + b^2}{12} = \frac{(b-a)^2}{12}$.

> **Ders sonrası not:** Hoca çarpanlara ayırmayı sözlü olarak önce "$(a-b)$" ile söyledi, hemen "$(b-a)$ olmalı" diye düzeltti. Formüller python ile $a = 2$, $b = 7$ için tam kesirlerle doğrulandı: $E[X] = 9/2$, $E[X^2] = 67/3$, $\mathrm{Var}(X) = 25/12$.

Hoca bu dört sonucun (PDF, CDF, ortalama, varyans) düzgün dağılım için çok kullanışlı sonuçlar olduğunu söyledi ve sıradaki konunun üstel (exponential) rastgele değişken olduğunu belirterek örneği burada bitirdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:30:43): Bernoulli($p$) rastgele değişkeninin ikinci momenti $E[X^2]$ nedir?

> **Çözüm:** $E[X^2] = 0^2(1-p) + 1^2 p = p$. Buradan $\mathrm{Var}(X) = p - p^2 = p(1-p)$.

**Soru 2** (derste sözlü, 00:52:46; ekrandan, 00:55:00): Binom dağılımında $k^2$ türev cinsinden nasıl yazılır ve $E[X^2]$ nedir?

> **Çözüm:** $k^2 = \frac{\partial^2}{\partial a\,\partial b}(ab)^k\big|_{a=b=1}$. Toplam $(abp + 1 - p)^n$'e dönüşür ve türevler alınınca $E[X^2] = np(1-p) + n^2p^2$, $\mathrm{Var}(X) = np(1-p)$ bulunur.

**Soru 3** (derste sözlü, 00:55:15): $\binom{n}{k}$ neye eşittir ve adı nedir?

> **Çözüm:** $\binom{n}{k} = \frac{n!}{k!(n-k)!}$; kombinasyon.

**Soru 4** (derste sözlü, 01:15:17): Geometrik dağılımda $k$ hangi değerleri alabilir?

> **Çözüm:** $k = 1, 2, 3, \dots$; ilk başarı için en az bir deneme gerekir, $k = 0$ olamaz.

**Soru 5** (derste sözlü, 01:32:24; ekrandan, 01:40:00): Poisson beklenen değeri türetilirken çıkan $\sum_{k=0}^{\infty}\frac{(a\lambda)^k}{k!}$ serisi neye eşittir?

> **Çözüm:** $e^x = \sum_{k=0}^{\infty}\frac{x^k}{k!}$ olduğundan seri $e^{a\lambda}$'dır. $E[X] = e^{-\lambda}\frac{\partial}{\partial a}e^{a\lambda}\big|_{a=1} = e^{-\lambda}\lambda e^{\lambda} = \lambda$.

**Soru 6** (derste sözlü, 02:12:43; ekrandan, 02:15:00): Basamak biçimindeki $F_Y(y)$ CDF'ine sahip $Y$ kaç farklı değer alabilir? Düzgün artan $F_X(x)$ CDF'ine sahip $X$ kaç değer alabilir?

> **Çözüm:** $Y$ yalnız üç değer ($y_1, y_2, y_3$) alır, kesiklidir. $X$ sayılamayacak kadar sonsuz değer alır, süreklidir.

**Soru 7** (derste sözlü, 02:37:08; ekrandan, 02:40:00): Ortak CDF için $F_{X,Y}(\infty, \infty)$ ve $F_{X,Y}(-\infty, -\infty)$ nedir?

> **Çözüm:** $F_{X,Y}(\infty, \infty) = 1$, $F_{X,Y}(-\infty, -\infty) = 0$. Ayrıca $F_{X,Y}(-\infty, \infty) = F_X(-\infty) = 0$ ve $F_{X,Y}(\infty, -\infty) = F_Y(-\infty) = 0$.

**Soru 8** (derste sözlü, 02:58:36): $X$ ve $Y$ Gauss dağılımlı ve ilişkisizse ne söylenebilir? Gauss değillerse?

> **Çözüm:** Gauss iseler (kesin olarak: ortak Gauss iseler) bağımsızdırlar. Gauss değillerse ilişkisizlikten bağımsızlık çıkmaz. Bağımsızlık her durumda ilişkisizlik demektir.

**Soru 9** (derste sözlü, 03:09:01; ekrandan, 03:10:00): $[a, b]$ üzerindeki düzgün dağılımın CDF'i nasıl bir fonksiyondur?

> **Çözüm:** $x < a$ için 0, $a \le x \le b$ için doğrusal olarak artan $\frac{x-a}{b-a}$, $x > b$ için 1.

## Dersin Toparlaması

Bu derste önce Chebyshev eşitsizliği Markov eşitsizliğinden ispatlandı ve standart sapma cinsinden biçimiyle üç sigma kuralı elde edildi. Bu eşitsizliklerin değeri, dağılım bilinmeden yalnız ortalama ve varyansla olasılığa sınır koyabilmeleridir. Ardından kesikli dağılım aileleri sırayla işlendi: Bernoulli, binom, geometrik, negatif binom, Poisson ve çok terimli dağılım. Binom ve Poisson'da beklenen değer ve ikinci moment, $k$'yı bir türev olarak yazıp toplamla türevin yerini değiştiren bir teknikle türetildi. Poisson'un binomun limiti olduğu ve bağımsız Poisson değişkenlerin toplamının yine Poisson olduğu gösterildi. Hipergeometrik dağılım kitaptan çalışılmak üzere bırakıldı.

İkinci yarıda sürekli rastgele değişkenlere geçildi: sürekli CDF, CDF'in türevi olarak PDF, PDF'in özellikleri, ortak ve marjinal yoğunluklar, sürekli durumda beklenen değer, varyans, kovaryans ve korelasyon. İlişkisizlik ile bağımsızlık arasındaki farkın ve Gauss değişkenlerdeki istisnanın önemi vurgulandı. Ders, sürekli düzgün dağılımın PDF, CDF, ortalama ve varyansının türetildiği bir örnekle bitti. Hoca sıradaki sürekli dağılımın üstel dağılım olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
