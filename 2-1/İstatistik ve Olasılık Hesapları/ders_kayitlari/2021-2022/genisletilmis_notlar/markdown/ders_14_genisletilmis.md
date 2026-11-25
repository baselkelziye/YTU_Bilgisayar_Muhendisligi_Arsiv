# Ders 14 Genişletilmiş Notu: Dönüşüm Yöntemi ve Özel Sürekli Dağılımlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sürekli Rastgele Değişkenlerin Fonksiyonları (Tekrar)
- 2. Dönüşüm Yöntemi
- 3. Düzgün Dağılım
- 4. Üstel Dağılım ve Belleksizlik
- 5. Standart Normal Dağılım ve Phi Fonksiyonu
- 6. Genel Normal Dağılım
- 7. Gama Fonksiyonu ve Gama Dağılımı
- Örnek Sorular

## 1. Sürekli Rastgele Değişkenlerin Fonksiyonları (Tekrar)

Ders, ara sınavlardan önce işlenen konunun kısa bir tekrarıyla açıldı. $X$ sürekli bir rastgele değişken ve $Y = g(X)$ ise $Y$'nin kendisi de bir rastgele değişkendir. $Y$'nin kümülatif dağılım fonksiyonu (CDF) bulunursa $Y$ hakkındaki her şey oradan çıkarılabilir. Daha önce kurulan genel çerçeve üç adımdır (ekrandan, 00:05:00):

1. $Y$'nin aralığı bulunur: $R_Y = \{ g(x) \mid f_X(x) > 0 \}$. Yani $X$'in yoğunluğunun pozitif olduğu noktalarda $g$'nin aldığı değerler.
2. CDF tanımdan yazılır: $F_Y(y) = P(Y \le y) = P(g(X) \le y)$.
3. Yoğunluk, CDF'nin türevidir: $f_Y(y) = \frac{d}{dy} F_Y(y)$.

Bu çerçeve önceki derste $X \sim \text{Uniform}(0,1)$ ve $Y = e^X$ örneğiyle uygulanmıştı (ekrandan, 00:05:00). Bu derste aynı fikir bir teoremle formül haline getirildi. Hoca teoremin mantığının ve ispatının ders kitabında (Pishro-Nik) okunabileceğini söyledi.

## 2. Dönüşüm Yöntemi

### 2.1 Monoton parçalara bölme

Bir $g(x)$ fonksiyonunun tanım aralığı, fonksiyonun sürekli arttığı (monotonically increasing) ya da sürekli azaldığı (monotonically decreasing) parçalara bölünebilir. "Monoton artan" demek, o parça boyunca fonksiyonun hep arttığı anlamına gelir. Derste çizilen örnek grafikte önce yükselen, sonra alçalan, sonra yeniden yükselen bir eğri vardı. Böylece üç parça oluştu (ekrandan, 00:15:00):

| Parça | Davranış | Türev |
|---|---|---|
| range 1 | monoton artan | $g'(x)$ var |
| range 2 | monoton azalan | $g'(x)$ var |
| range 3 | monoton artan | $g'(x)$ var |

Üç parçanın her birinde $g$ sürekli ve türevlenebilirdir. Hoca "range" yerine "partition" (parça) demenin daha doğru olduğunu belirtti; bu örnekte $n = 3$ parça vardır.

### 2.2 Teorem

Dönüşüm yöntemi teoremi (Theorem of Method of Transformations) şöyledir (ekrandan, 00:20:00):

- $X$, aralığı $R_X$ olan sürekli bir rastgele değişken olsun.
- $R_X$, her birinde $g(x)$'in kesin monoton (strictly monotone) ve türevlenebilir olduğu aralıklara bölünebilsin.
- O zaman

$$f_Y(y) = \sum_{i=1}^{n} \frac{f_X(x_i)}{|g'(x_i)|} = \sum_{i=1}^{n} f_X(x_i) \left| \frac{dx_i}{dy} \right|$$

Burada $x_i$'ler $g(x) = y$ denkleminin gerçel çözümleridir; her parçada bir tane. Türevin mutlak değerine bölmek ile $x_i$'nin $y$'ye göre türevinin mutlak değeriyle çarpmak aynı şeydir; bu yüzden iki biçimden hangisi kolaysa o kullanılabilir.

### 2.3 Örnek: standart normal değişkenin karesi

$X$ sürekli bir rastgele değişken olsun ve yoğunluğu $f_X(x) = \frac{1}{\sqrt{2\pi}} e^{-x^2/2}$ (her $x \in \mathbb{R}$) olsun. $Y = X^2$ için $f_Y(y)$ bulunacak (ekrandan, 00:20:00).

**Parçalar.** $y = g(x) = x^2$ grafiği $(-\infty, 0)$ aralığında azalır, $(0, \infty)$ aralığında artar. Dolayısıyla $n = 2$ parça vardır: parça 1 $(-\infty, 0)$, parça 2 $(0, \infty)$ (ekrandan, 00:25:00).

**Çözümler.** Verilen bir $y$ için her parçada $g(x) = y$ denkleminin çözümü bulunur. Parça 1'deki değerler negatif olduğu için karekökün önüne eksi konur; parça 2'de gerek yoktur (ekrandan, 00:30:00):

- $x_1 = g^{-1}(y) = -\sqrt{y}$ (parça 1)
- $x_2 = g^{-1}(y) = \sqrt{y}$ (parça 2)

**Türev.** $g(x) = x^2 \Rightarrow g'(x) = 2x$.

**Formül.** Teoremin ilk biçimi kullanılır (ekrandan, 00:30:00 ve 00:35:00):

$$f_Y(y) = \sum_{i=1}^{2} \frac{f_X(x_i)}{|g'(x_i)|} = \frac{\frac{1}{\sqrt{2\pi}} e^{-x_1^2/2}}{|2x_1|} + \frac{\frac{1}{\sqrt{2\pi}} e^{-x_2^2/2}}{|2x_2|}$$

Çözümler yerine konur:

$$= \frac{1}{\sqrt{2\pi}} \frac{e^{-(-\sqrt{y})^2/2}}{|2(-\sqrt{y})|} + \frac{1}{\sqrt{2\pi}} \frac{e^{-(\sqrt{y})^2/2}}{|2\sqrt{y}|}$$

Birinci terimde paydanın mutlak değeri eksiyi kaldırır ve $(-\sqrt{y})^2 = y$ olur. İki terim de aynı hale gelir:

$$= \frac{1}{\sqrt{2\pi}} \frac{e^{-y/2}}{2\sqrt{y}} + \frac{1}{\sqrt{2\pi}} \frac{e^{-y/2}}{2\sqrt{y}} = \frac{1}{\sqrt{2\pi y}} e^{-y/2}, \quad y \in (0, \infty)$$

Hoca burada $Y$'nin aralığının mutlaka kontrol edilmesi gerektiğini vurguladı: $Y = X^2$ negatif olamaz, bu yüzden yoğunluk yalnız $y > 0$ için bu ifadedir, diğer yerlerde sıfırdır. Sonuç, $F_Y(y) = \Phi(\sqrt{y}) - \Phi(-\sqrt{y})$ ifadesinin sayısal türeviyle birkaç $y$ değerinde karşılaştırıldı ve uyuştu.

> **Hocanın vurgusu:** Yöntem uzun görünebilir, ama kullanılmasaydı fonksiyonu CDF üzerinden ayrıntılı düşünmek gerekirdi. Fonksiyon karmaşıklaştıkça bu çok zorlaşır; dönüşüm yöntemi düzenli bir yol verir.

> **Ek bilgi (derste anlatılmadı):** Bulunan $f_Y(y) = \frac{1}{\sqrt{2\pi y}} e^{-y/2}$ yoğunluğu, 1 serbestlik dereceli ki-kare dağılımının yoğunluğudur. Bu dağılım ileride örnekleme dağılımlarında ve hipotez testlerinde karşılaşılan ki-kare dağılımının en basit halidir.

## 3. Düzgün Dağılım

Dersin ikinci bölümü özel sürekli dağılımlara (special continuous distributions) ayrıldı. Bunlar sık karşılaşılan, adı konmuş ve özellikleri önceden hesaplanmış dağılımlardır (ekrandan, 00:40:00). İlki daha önce de görülmüş olan düzgün (uniform) dağılımdır.

**Tanım.** Sürekli bir rastgele değişken $X$, aşağıdaki yoğunluğa sahipse $[a, b]$ aralığında düzgün dağılımlıdır:

$$f_X(x) = \begin{cases} \frac{1}{b-a} & a < x < b \\ 0 & \text{aksi halde} \end{cases}$$

Bu durum $X \sim \text{Uniform}(a, b)$ diye yazılır; $a$ ve $b$ dağılımın parametreleridir (ekrandan, 00:45:00).

**Grafik.** Değişken yalnız $a$ ile $b$ arasında değer alır ve bu aralıkta yoğunluk sabittir; "düzgün" adı buradan gelir. Aralık dışında yoğunluk sıfırdır. Sabit yüksekliğin $\frac{1}{b-a}$ olması kolayca bulunur: eğri altındaki alan 1 olmalıdır, çünkü olasılıkların integrali 1'dir; genişliği $b-a$ olan dikdörtgenin alanının 1 olması için yükseklik $\frac{1}{b-a}$ olmalıdır.

**Ortalama ve varyans.** Ekrana şu sonuçlar yazıldı ve türetmeleri öğrenciye bırakıldı (ekrandan, 00:45:00):

$$E X = \frac{a+b}{2}, \qquad \text{Var}(X) = \frac{(b-a)^2}{12}$$

## 4. Üstel Dağılım ve Belleksizlik

### 4.1 Tanım ve grafik

Üstel (exponential) dağılım çok kullanılan bir dağılımdır ve olaylar arasında geçen süreyi modeller. Bekleme süresi gibi büyüklükler için uygundur (ekrandan, 00:50:00).

**Tanım.** Sürekli bir rastgele değişken $X$, $\lambda > 0$ parametreli üstel dağılıma sahipse $X \sim \text{Exponential}(\lambda)$ yazılır ve

$$f_X(x) = \begin{cases} \lambda e^{-\lambda x} & x > 0 \\ 0 & \text{aksi halde} \end{cases}$$

**Grafik.** $X$ bir bekleme süresi olduğu için negatif olamaz; negatif değerlerde yoğunluk sıfırdır. $x = 0$'da yoğunluk $\lambda e^{0} = \lambda$'dır. $x \to \infty$ iken $\lambda e^{-\infty} \to 0$ olur. Dolayısıyla grafik $\lambda$ yüksekliğinden başlayıp azalarak sıfıra yaklaşan bir eğridir (ekrandan, 00:50:00).

### 4.2 Birim basamak fonksiyonu ile yazım

Parçalı tanımlı fonksiyonları yazarken birim basamak fonksiyonu (unit step function) işe yarar (ekrandan, 00:55:00):

$$u(x) = \begin{cases} 1 & x \ge 0 \\ 0 & \text{aksi halde} \end{cases}$$

Grafiği sıfıra kadar 0'dır; $x = 0$'da değer 1'e sıçrar ve sonra hep 1 kalır. Bu fonksiyonla üstel yoğunluk tek bir ifadeyle yazılır:

$$f_X(x) = \lambda e^{-\lambda x} u(x)$$

Yani $u(x)$, $x$ pozitifken çarpanı 1 yapıp ifadeyi korur, negatifken 0 yapıp yoğunluğu sıfırlar.

> **Ders sonrası not:** Hoca açıklama sırasında bir an "x birden büyükken" dedi; doğrusu "x sıfırdan büyükken"dir. Basamak fonksiyonunun sıçradığı nokta 0'dır.

Bir karışıklık noktası şudur: üstel tanımda $x > 0$, basamak fonksiyonunda ise $x \ge 0$ yazar. İki ifade yalnız $x = 0$ noktasında ayrılır. Ancak sürekli bir değişkenin tek bir noktayı alma olasılığı sıfırdır; bu yüzden bu fark hiçbir olasılık hesabını değiştirmez.

### 4.3 Ortalama ve varyans

Ekrana yazılan sonuçlar şunlardır (ekrandan, 01:10:00 ve 01:15:00):

$$\mu_X = E X = \frac{1}{\lambda}, \qquad \sigma_X^2 = \text{Var}(X) = \frac{1}{\lambda^2}$$

Bunların türetilmesi de alıştırma olarak bırakıldı; hoca kısmi integrasyonun (integration by parts) gerekeceğini söyledi.

### 4.4 Belleksizlik özelliği

Üstel dağılımın ilginç bir özelliği belleksizliktir (memoryless property). Tanım (ekrandan, 01:15:00): $X \sim \text{Exponential}(\lambda)$ ise

$$P(X > x + a \mid X > a) = P(X > x), \qquad a, x \ge 0$$

Hoca bunu bir çağrı merkezi örneğiyle açıkladı. Bir çağrı merkezi işlettiğinizi ve bir müşterinin aramasını beklediğinizi düşünün. Zaten 5 dakika beklediniz ($a = 5$). Şimdi toplamda 15 dakika ya da daha fazla bekleme olasılığı soruluyor ($x = 10$). Belleksizlik, 5 dakika beklemiş olmanın bir şey değiştirmediğini söyler: 5 dakika beklendiği bilindiğinde 15 dakikadan fazla bekleme olasılığı, sıfırdan başlayarak 10 dakikadan fazla bekleme olasılığına eşittir. İspatı ders kitaplarında (Pishro-Nik ve Baron) okunabilir ya da öğrenci kendisi yapabilir.

> **Ek bilgi (derste anlatılmadı):** İspat kısadır. Üstel dağılımda $P(X > t) = e^{-\lambda t}$ olduğundan $P(X > x+a \mid X > a) = \frac{P(X > x+a)}{P(X > a)} = \frac{e^{-\lambda(x+a)}}{e^{-\lambda a}} = e^{-\lambda x} = P(X > x)$. Kesişim $\{X > x+a\} \cap \{X > a\}$, $x \ge 0$ olduğu için $\{X > x+a\}$ kümesine eşittir.

## 5. Standart Normal Dağılım ve Phi Fonksiyonu

### 5.1 Tanım ve grafik

Sıradaki özel dağılım normal dağılımdır; Gauss dağılımı da denir. Hoca bunun çok önemli bir dağılım olduğunu ve nedeninin ileride görüleceğini söyledi. Önce standart normal değişken tanımlandı.

**Tanım.** Sürekli bir rastgele değişken $Z$, yoğunluğu

$$f_Z(z) = \frac{1}{\sqrt{2\pi}} \exp\left\{ -\frac{z^2}{2} \right\}$$

ise standart normal (standart Gauss) rastgele değişkendir ve $Z \sim N(0, 1)$ diye gösterilir. Burada $X$ yerine $Z$ harfi kullanılır, çünkü problemlerde çoğu zaman bir $X$ değişkeni $Z$'ye dönüştürülür; standart normal değişken için $Z$ kullanmak gelenektir. $N$ "normal"den gelir; $0$ ve $1$ değerleri dağılımı standart yapan değerlerdir. Örneğin parametreler $1$ ve $2$ olsaydı dağılım standart olmazdı.

**Grafik.** Yoğunluk $z = 0$ etrafında simetriktir; tepe noktası $0$'dadır ve tepenin çevresinde çan biçimindedir (ekrandan, 01:25:00).

### 5.2 Ortalama ve varyans

Ekrana yazılan sonuçlar (ekrandan, 01:30:00):

$$E Z = E Z^3 = E Z^5 = \dots = 0, \qquad \text{Var}(Z) = 1 = \sigma^2 \Rightarrow \sigma = 1$$

Yani standart sapma da 1'dir. İspatlar için Pishro-Nik kitabı önerildi.

### 5.3 CDF ve kapalı form olmaması

Standart normalin CDF'si tanım olarak yazılabilir, ama kapalı bir çözümü yoktur (ekrandan, 01:30:00). İntegral değişkeni $z$ ile karışmasın diye $u$ kullanılır:

$$F_Z(z) = \int_{-\infty}^{z} f_Z(u)\, du = \int_{-\infty}^{z} \frac{1}{\sqrt{2\pi}} e^{-u^2/2}\, du$$

Kapalı form çözümü olmasa da normal dağılım çok önemli olduğu için sayısal yaklaşık değerler hesaplanmıştır. Bu değerler bazı kitapların sonundaki tablolarda (örneğin Baron'un kitabında) bulunur ya da yazılım paketlerindeki ilgili fonksiyonlarla elde edilir.

### 5.4 Phi sembolü

Bu CDF çok kullanıldığı için ona özel bir sembol verilir: büyük Phi, $\Phi$ (ekrandan, 01:35:00):

$$F_Z(z) = \Phi(z), \qquad F_Z(z) = P(Z \le z)$$

Hoca bunun yeni bir kavram olmadığını, alışılmış kümülatif dağılım fonksiyonu olduğunu, yalnız çok kullanıldığı için özel bir sembol aldığını hatırlattı.

### 5.5 Phi değerlerini elde etmek

Örneğin $\Phi(1.6)$ nasıl bulunur? İki yol vardır (ekrandan, 01:35:00):

1. Bir $\Phi$ tablosuna bakmak (örneğin Baron'un kitabındaki tablo).
2. Sevdiğiniz programlama dilini kullanmak.

Python'da önce `scipy.stats` paketinden `norm` modülü içe aktarılır. $\Phi(z)$ değeri `norm.cdf(z)` ile, ters fonksiyon (bir olasılık değeri verildiğinde ona karşılık gelen $z$) ise `norm.ppf(p)` ile bulunur. Bunun için Python ve SciPy paketinin kurulu olması gerekir. Derste etkileşimli Python kabuğunda şu çalıştırıldı (ekrandan, 01:40:00):

```python
>>> from scipy.stats import norm
>>> norm.cdf(1.6)
0.945200708300442
>>> a = norm.cdf(1.6)
>>> norm.ppf(a)
1.6000000000000003
```

Ters fonksiyonla dönüldüğünde $1.6$ yerine $1.6000000000000003$ çıkması, sayısal yaklaşımlarda olağan küçük bir hatadır. Hoca C, Java ya da başka bir dil kullananların internette arayarak standart normal CDF değerlerini veren bir paket bulabileceğini söyledi. $\Phi(1.6) = 0.945200708300442$ değeri `math.erf` ile ayrıca doğrulandı.

### 5.6 Phi grafiği ve simetri özelliği

Yoğunluk grafiğinde $-\infty$'dan $x$'e kadar eğri altındaki alan $\Phi(x)$'i verir:

$$\Phi(x) = P(Z \le x) = \int_{-\infty}^{x} f_Z(u)\, du$$

$\Phi$'nin kendi grafiği, solda 0'a yaklaşıp sağda 1'e yaklaşan ve $x = 0$'da $\frac{1}{2}$ değerinden geçen bir S eğrisidir (ekrandan, 01:50:00). Yoğunluğun simetrisinden şu özellik gelir:

$$\Phi(-x) = 1 - \Phi(x), \qquad x \in \mathbb{R}$$

Hoca bu özelliğin yoğunluk grafiği üzerinde kontrol edilmesini önerdi: $-x$'in solundaki alan, simetri nedeniyle $x$'in sağındaki alana eşittir.

## 6. Genel Normal Dağılım

### 6.1 Tanım

$Z$ standart normal değişken olsun. $\sigma > 0$ olmak üzere

$$X = \sigma Z + \mu$$

tanımlanırsa $X$ de bir rastgele değişkendir; ortalaması $E X = \mu$, varyansı $\text{Var}(X) = \sigma^2$'dir (ekrandan, 01:55:00). $X$'e normal rastgele değişken denir ve $X \sim N(\mu, \sigma^2)$ yazılır. Standart normalde $N(0,1)$ yazılırken $0$ ortalama, $1$ varyanstı; genel durumda bunların yerine $\mu$ ve $\sigma^2$ gelir. Yani parantez içinde ortalama ve varyans yazılır.

Yoğunluk standart normalinkine çok benzer (ekrandan, 01:55:00):

$$f_X(x) = \frac{1}{\sqrt{2\pi}\, \sigma} \exp\left( -\frac{(x-\mu)^2}{2\sigma^2} \right)$$

### 6.2 CDF'nin Phi ile yazılması

$F_X(x) = P(X \le x)$ için de kapalı form yoktur. Bu yüzden CDF, $\Phi$ cinsinden yazılır. $X = \sigma Z + \mu$ olduğundan $Z = \frac{X - \mu}{\sigma}$'dır (ekrandan, 02:00:00). Eşitsizliğin iki yanından $\mu$ çıkarılıp $\sigma$'ya bölünürse ($\sigma > 0$ olduğu için yön değişmez):

$$F_X(x) = P(X \le x) = P\left(Z \le \frac{x - \mu}{\sigma}\right) = \Phi\left(\frac{x - \mu}{\sigma}\right)$$

Aynı fikirle bir aralığın olasılığı da yazılır:

$$P(a < X \le b) = F_X(b) - F_X(a) = \Phi\left(\frac{b - \mu}{\sigma}\right) - \Phi\left(\frac{a - \mu}{\sigma}\right)$$

> **Hocanın vurgusu:** Bu fikri bilmek gerekir. Normal bir değişkenin kümülatif olasılığı gerektiğinde $\mu$ çıkarılır, $\sigma$'ya bölünür ve sonra standart normalin kümülatif değerleri kullanılır.

**Soru:** İkinci terimde de $b$ mi olacak, $a - \mu$ olması gerekmiyor mu? **Cevap:** Hoca iki terime de yanlışlıkla $b$ yazdığını kabul etti ve düzeltti; ikinci terim $a$'nın kümülatif değeri olduğu için $\Phi\left(\frac{a - \mu}{\sigma}\right)$'dır (ekrandaki ilk yazımda iki terim de $b$ ile yazılmıştı; ekrandan, 02:00:00).

### 6.3 Grafik ve varyansın etkisi

Normal dağılımın grafiği de standart normal gibi simetriktir, ama merkezi $x = \mu$'dedir. Varyans grafiğin ne kadar yayıldığını belirler. Varyans yüksekse olasılık geniş bir alana dağılır; varyans düşükse olasılığın hepsi $\mu$ çevresindeki küçük bir alana sıkışır ve daha dar, daha sivri bir çan oluşur (ekrandan, 02:20:00). Bu yüzden varyansa bazen "yayılım" (spread) da denir.

### 6.4 Sayısal örnek

$X \sim N(-5, 4)$ olsun. $P(-7 < X < -3)$ bulunacak (ekrandan, 02:20:00).

**Verilen.** $\mu = -5$, $\sigma^2 = 4$, yani $\sigma = 2$.

**Standartlaştırma.** $X$'in yoğunluğundaki $-7$ ile $-3$ arası alan, standart normalde karşılık gelen iki nokta arasındaki alana eşittir. Standart normalde ortalama $0$, varyans $1$'dir. Sınırlar (ekrandan, 02:25:00):

$$\frac{-7 - (-5)}{2} = -1, \qquad \frac{-3 - (-5)}{2} = 1$$

Hoca ilk çizimde $-3$'ü $-5$'in soluna koyduğunu fark etti ve grafiği yeniden çizdi: $-7$, $-5$'ten küçüktür ama $-3$ büyüktür; aralık ortalamanın iki yanına simetrik yayılır.

**İşlem.** (ekrandan, 02:25:00 ve 02:30:00)

$$P(-7 < X < -3) = P(X \le -3) - P(X \le -7) = F_X(-3) - F_X(-7)$$

$$= \Phi\left(\frac{-3 - \mu}{\sigma}\right) - \Phi\left(\frac{-7 - \mu}{\sigma}\right) = \Phi(1) - \Phi(-1)$$

**Sonuç.** $\Phi$ değerleri bir yerden bakılmalıdır. Python'da:

```python
norm.cdf(1) - norm.cdf(-1)   # yaklaşık 0.6827
```

Sonuç $\approx 0.6827$'dir. Bu değer `math.erf` ile ayrıca hesaplandı: $\Phi(1) - \Phi(-1) = 0.682689\ldots$

> **Ders sonrası not:** Hoca soruyu okurken bir an "mean is 5" dedi; doğrusu ekrandaki gibi ortalama $-5$'tir.

> **Ek bilgi (derste anlatılmadı):** $\Phi(-x) = 1 - \Phi(x)$ özelliği kullanılırsa $\Phi(1) - \Phi(-1) = 2\Phi(1) - 1$ olur. Bu, normal bir değişkenin ortalamadan bir standart sapma uzaklık içinde kalma olasılığıdır ve her normal dağılım için yaklaşık $0.68$'dir.

### 6.5 Normal değişkenin doğrusal dönüşümü

Normal dağılımın önemli bir özelliği: normal bir rastgele değişkenin doğrusal dönüşümü de normaldir (ekrandan, 02:30:00). $X \sim N(\mu_X, \sigma_X^2)$ ve $Y = aX + b$ ise

$$Y \sim N(a\mu_X + b,\; a^2 \sigma_X^2)$$

Yani yeni ortalama, eski ortalamaya aynı doğrusal işlem uygulanarak; yeni varyans ise eski varyans $a^2$ ile çarpılarak bulunur. Ekranda $X^2$ ve $\log X$ gibi ifadeler doğrusal olmayan (non-linear) dönüşüm örnekleri olarak üstü çizilerek gösterildi; özellik bunlar için geçerli değildir (bölüm 2.3'teki $X^2$ örneğinin sonucu da normal değildir).

## 7. Gama Fonksiyonu ve Gama Dağılımı

### 7.1 Gama dağılımının tanımı

Son özel dağılım gama dağılımıdır. Hoca bunun biraz karmaşık olduğunu ve uzun ifadeyi ezberlemeye gerek olmadığını söyledi.

**Tanım.** Sürekli bir rastgele değişken $X$, $\alpha > 0$ ve $\lambda > 0$ parametreli gama dağılımına sahipse (ekrandan, 02:35:00):

$$f_X(x) = \begin{cases} \dfrac{\lambda^\alpha x^{\alpha - 1} e^{-\lambda x}}{\Gamma(\alpha)} & x > 0 \\ 0 & \text{aksi halde} \end{cases}$$

İki parametre vardır: $\alpha$ ve $\lambda$. Paydadaki $\Gamma(\alpha)$ gama fonksiyonudur; dağılımı anlamak için önce onu bilmek gerekir.

### 7.2 Gama fonksiyonu

$\alpha > 0$, $\alpha \in \mathbb{R}$ için (ekrandan, 02:45:00):

$$\Gamma(\alpha) = \int_0^{\infty} x^{\alpha - 1} e^{-x}\, dx$$

$\alpha$ bir doğal sayıysa ($\alpha \in \{1, 2, 3, \dots\}$) gama fonksiyonu faktöriyele bağlanır:

$$\Gamma(n) = (n - 1)!$$

Tam sayılarda faktöriyel kullanılabilir; tam sayı olmayan değerlerde integralle hesaplamak gerekir. Örneğin $\Gamma(3) = 2! = 2$. Ayrıntılar için Pishro-Nik kitabı önerildi.

### 7.3 Grafiğin parametrelere bağlılığı

Gama dağılımının grafiği esnektir; $\alpha$ ve $\lambda$ değiştikçe biçimi çok değişir. Derste üç eğri çizildi:

- $\alpha = 1$, $\lambda = 1$: grafik üstel dağılıma çok benzer.
- $\alpha = 2$, $\lambda = \frac{1}{2}$
- $\alpha = 3$, $\lambda = \frac{1}{2}$

<!-- BELİRSİZ: α=2 ve α=3 eğrilerinin tam biçimi altyazıdan çıkmıyor; bu anın karesine bakılmadı. -->

Hocaya göre $\alpha$ arttıkça grafik giderek normal dağılım grafiğine benzer.

### 7.4 Gama ve üstel dağılım ilişkisi

**Birinci nokta.** Yoğunlukta $\alpha = 1$ konursa: $\Gamma(1) = 0! = 1$ (tanım gereği $0! = 1$), $\lambda^1 = \lambda$ ve $x^{1-1} = x^0 = 1$ olur. Geriye $\lambda e^{-\lambda x}$ kalır; bu tam olarak üstel dağılımdır (ekrandan, 02:45:00 ve 02:50:00):

$$\text{Gamma}(1, \lambda) = \text{Exponential}(\lambda)$$

**İkinci nokta.** $n$ tane bağımsız üstel rastgele değişken toplanırsa Gamma$(n, \lambda)$ rastgele değişkeni elde edilir (ekrandan, 02:50:00). Hoca bunu "gama dağılımı üstellerin toplamına denktir" diye de ifade etti.

### 7.5 Ortalama ve varyans

Ekrana yazılan sonuçlar (ekrandan, 02:50:00):

$$E X = \frac{\alpha}{\lambda}, \qquad \text{Var}(X) = \frac{\alpha}{\lambda^2}$$

Türetme yine alıştırma olarak bırakıldı. İpucu: en azından $\alpha \in \{1, 2, 3, \dots\}$ için gamanın üstellerin toplamı olduğu kullanılabilir.

Hoca bu bölümle özel sürekli dağılımların bittiğini, ilgili kitap bölümünün okunmasını ve problemlerin çözülmesini önerdi.

## Örnek Sorular

### Soru 1: Standart normal değişkenin karesinin yoğunluğu

(ekrandan, 00:20:00) $X$, yoğunluğu $f_X(x) = \frac{1}{\sqrt{2\pi}} e^{-x^2/2}$ (her $x \in \mathbb{R}$) olan sürekli bir rastgele değişkendir. $Y = X^2$ olsun. $f_Y(y)$'yi bulun.

> **Çözüm (derste verildi):** $g(x) = x^2$ iki monoton parçaya ayrılır: $(-\infty, 0)$ ve $(0, \infty)$. Çözümler $x_1 = -\sqrt{y}$, $x_2 = \sqrt{y}$; $g'(x) = 2x$. Dönüşüm yöntemiyle $f_Y(y) = \frac{f_X(-\sqrt{y})}{|-2\sqrt{y}|} + \frac{f_X(\sqrt{y})}{|2\sqrt{y}|} = \frac{1}{\sqrt{2\pi y}} e^{-y/2}$, $y > 0$; diğer yerlerde $0$.

### Soru 2: Phi(1.6) değeri

(ekrandan, 01:35:00) $\Phi(1.6) = ?$

> **Çözüm (derste verildi):** Bir $\Phi$ tablosundan ya da Python'da `norm.cdf(1.6)` ile: $\Phi(1.6) \approx 0.9452$. Ters yönde `norm.ppf(0.945200708300442)` yaklaşık $1.6$ verir (ekrandan, 01:40:00).

### Soru 3: Normal dağılımda aralık olasılığı

(ekrandan, 02:20:00) $X \sim N(-5, 4)$. $P(-7 < X < -3)$'ü bulun.

> **Çözüm (derste verildi):** $\sigma = 2$. $P(-7 < X < -3) = \Phi\left(\frac{-3+5}{2}\right) - \Phi\left(\frac{-7+5}{2}\right) = \Phi(1) - \Phi(-1) \approx 0.6827$.

### Soru 4: Gama fonksiyonu değeri

(ekrandan, 02:45:00) $\Gamma(3) = ?$

> **Çözüm (derste verildi):** $3$ doğal sayı olduğundan $\Gamma(3) = (3-1)! = 2! = 2$.

### Soru 5: Düzgün dağılımın ortalaması ve varyansı

(ekrandan, 00:45:00) $X \sim \text{Uniform}(a, b)$ için $E X = \frac{a+b}{2}$ ve $\text{Var}(X) = \frac{(b-a)^2}{12}$ olduğunu kendiniz bulun.

> **Çözüm (derste verilmedi):** $E X = \int_a^b \frac{x}{b-a} dx = \frac{b^2 - a^2}{2(b-a)} = \frac{a+b}{2}$. $E X^2 = \int_a^b \frac{x^2}{b-a} dx = \frac{b^3 - a^3}{3(b-a)} = \frac{a^2 + ab + b^2}{3}$. $\text{Var}(X) = E X^2 - (E X)^2 = \frac{a^2 + ab + b^2}{3} - \frac{a^2 + 2ab + b^2}{4} = \frac{a^2 - 2ab + b^2}{12} = \frac{(b-a)^2}{12}$.

### Soru 6: Üstel dağılımın ortalaması ve varyansı

(ekrandan, 01:10:00) $X \sim \text{Exponential}(\lambda)$ için $E X = \frac{1}{\lambda}$ ve $\text{Var}(X) = \frac{1}{\lambda^2}$ olduğunu kısmi integrasyonla kendiniz bulun.

> **Çözüm (derste verilmedi):** $E X = \int_0^\infty x \lambda e^{-\lambda x} dx$. Kısmi integrasyonda $u = x$, $dv = \lambda e^{-\lambda x} dx$ alınırsa $v = -e^{-\lambda x}$ ve $E X = \left[-x e^{-\lambda x}\right]_0^\infty + \int_0^\infty e^{-\lambda x} dx = 0 + \frac{1}{\lambda}$. Benzer şekilde $u = x^2$ ile $E X^2 = \left[-x^2 e^{-\lambda x}\right]_0^\infty + \int_0^\infty 2x e^{-\lambda x} dx = \frac{2}{\lambda} E X = \frac{2}{\lambda^2}$. Böylece $\text{Var}(X) = \frac{2}{\lambda^2} - \frac{1}{\lambda^2} = \frac{1}{\lambda^2}$. ($\lambda = 0.2$ için sayısal integralle $E X \approx 5$ ve $\text{Var}(X) \approx 25$ bulunarak kontrol edildi.)

### Soru 7: Gama dağılımının ortalaması ve varyansı

(ekrandan, 02:50:00) $X \sim \text{Gamma}(\alpha, \lambda)$ için $E X = \frac{\alpha}{\lambda}$ ve $\text{Var}(X) = \frac{\alpha}{\lambda^2}$ olduğunu gösterin. İpucu: $\alpha \in \{1, 2, 3, \dots\}$ için gama, üstellerin toplamıdır.

> **Çözüm (derste verilmedi):** $\alpha = n$ doğal sayı olsun. $X = X_1 + \dots + X_n$, $X_i$'ler bağımsız ve her biri Exponential$(\lambda)$'dır. Beklenen değer toplamın üzerine dağıldığından $E X = n \cdot \frac{1}{\lambda} = \frac{n}{\lambda}$. Bağımsız değişkenlerde varyanslar toplandığından $\text{Var}(X) = n \cdot \frac{1}{\lambda^2} = \frac{n}{\lambda^2}$. $n = \alpha$ yazılınca istenen sonuçlar çıkar.

## Dersin Toparlaması

Bu derste önce sürekli bir rastgele değişkenin fonksiyonunun yoğunluğunu bulmak için dönüşüm yöntemi öğrenildi: $g$'nin tanım aralığı monoton parçalara bölünür, her parçada $g(x) = y$'nin çözümü bulunur ve $f_Y(y) = \sum_i f_X(x_i)/|g'(x_i)|$ formülü uygulanır. Standart normal bir değişkenin karesinin yoğunluğu bu yolla bulundu ve sonucun yalnız $y > 0$ için geçerli olduğu vurgulandı.

Ardından sık kullanılan özel sürekli dağılımlar tanıtıldı: düzgün, üstel (ve belleksizlik özelliği), standart normal ile genel normal ve gama dağılımları. Normal dağılımda CDF'nin kapalı formu olmadığı, $\Phi$ değerlerinin tablodan ya da `scipy.stats.norm` ile bulunduğu ve her normal değişkenin $\mu$ çıkarılıp $\sigma$'ya bölünerek standart normale indirgendiği gösterildi. Gama dağılımının $\alpha = 1$'de üstel dağılıma indiği ve $n$ bağımsız üstel değişkenin toplamı olduğu bağlantısıyla özel sürekli dağılımlar bölümü tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
