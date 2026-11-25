# Ders 14 Çalışma Özeti

## Genel Konular

- Sürekli rastgele değişkenlerin fonksiyonları (tekrar)
  - $X$ sürekli bir rastgele değişken ve $Y = g(X)$ ise $Y$ de bir rastgele değişkendir.
  - Genel yol: önce $R_Y = \{ g(x) \mid f_X(x) > 0 \}$ aralığı bulunur, sonra $F_Y(y) = P(Y \le y) = P(g(X) \le y)$ hesaplanır, en sonda $f_Y(y) = \frac{d}{dy} F_Y(y)$ alınır (ekrandan, 00:05:00).
- Dönüşüm yöntemi (method of transformations) teoremi
  - $X$'in aralığı $R_X$, $g(x)$'in her parçada kesin monoton ve türevlenebilir olduğu $n$ parçaya bölünebiliyorsa:
  - $f_Y(y) = \sum_{i=1}^{n} \frac{f_X(x_i)}{|g'(x_i)|} = \sum_{i=1}^{n} f_X(x_i) \left| \frac{dx_i}{dy} \right|$; burada $x_i$, $g(x) = y$ denkleminin $i$. parçadaki gerçel çözümüdür (ekrandan, 00:20:00).
  - Örnek: $X$ standart normal, $Y = X^2$ için $f_Y(y) = \frac{1}{\sqrt{2\pi y}} e^{-y/2}$, $y > 0$.
- Özel sürekli dağılımlar
  - Düzgün (uniform) dağılım: $X \sim \text{Uniform}(a,b)$, $f_X(x) = \frac{1}{b-a}$ ($a < x < b$), aksi halde 0.
  - Üstel (exponential) dağılım: $X \sim \text{Exponential}(\lambda)$, $f_X(x) = \lambda e^{-\lambda x}$ ($x > 0$), aksi halde 0; olaylar arası süreyi modeller.
  - Birim basamak fonksiyonu $u(x)$ ve üstel yoğunluğun $\lambda e^{-\lambda x} u(x)$ biçiminde yazılması.
  - Üstel dağılımın belleksizlik özelliği.
  - Standart normal (Gauss) dağılım, $\Phi$ fonksiyonu ve Python ile hesaplanması.
  - Genel normal dağılım $N(\mu, \sigma^2)$, standartlaştırma ve doğrusal dönüşüm.
  - Gama fonksiyonu ve gama dağılımı; üstel dağılımla ilişkisi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dönüşüm yönteminde $Y$'nin aralığı mutlaka kontrol edilmeli
  - $Y = X^2$ örneğinde sonuç yalnız $y \in (0, \infty)$ için geçerlidir; aralık yazılmazsa cevap eksik kalır.
- Dönüşüm yöntemi, CDF üzerinden uzun uzun düşünmek yerine hazır bir formül verir
  - Fonksiyon karmaşıklaştıkça CDF yolu zorlaşır; parçalara bölüp formülü uygulamak daha düzenlidir.
- Normal dağılım çok önemlidir
  - Standart normalin CDF'si için kapalı form yoktur; tablolar ya da yazılım paketlerindeki sayısal yaklaşımlar kullanılır.
  - Normal bir değişkenin CDF'si gerektiğinde: $\mu$ çıkarılır, $\sigma$'ya bölünür, sonra $\Phi$ kullanılır.
- Ortalama ve varyans türetmeleri öğrenciye alıştırma olarak bırakıldı
  - Düzgün, üstel ve gama dağılımları için; üstelde kısmi integrasyon (integration by parts) gerekir, gamada üstellerin toplamı fikri ipucudur.

## Kısa Tekrar Notları

- Dönüşüm yöntemi: $f_Y(y) = \sum_i f_X(x_i) / |g'(x_i)|$, $x_i$: $g(x) = y$'nin her monoton parçadaki çözümü.
- $X \sim N(0,1)$, $Y = X^2$: iki parça, $x_1 = -\sqrt{y}$, $x_2 = \sqrt{y}$, $g'(x) = 2x$, sonuç $f_Y(y) = \frac{1}{\sqrt{2\pi y}} e^{-y/2}$, $y > 0$.
- Uniform$(a,b)$: $E X = \frac{a+b}{2}$, $\text{Var}(X) = \frac{(b-a)^2}{12}$.
- Exponential$(\lambda)$: $E X = \frac{1}{\lambda}$, $\text{Var}(X) = \frac{1}{\lambda^2}$.
- Birim basamak: $u(x) = 1$ ($x \ge 0$), $u(x) = 0$ (aksi halde).
- Belleksizlik: $P(X > x + a \mid X > a) = P(X > x)$, $a, x \ge 0$.
- Standart normal: $f_Z(z) = \frac{1}{\sqrt{2\pi}} e^{-z^2/2}$, $Z \sim N(0,1)$, $E Z = E Z^3 = E Z^5 = \dots = 0$, $\text{Var}(Z) = 1$.
- $\Phi(z) = F_Z(z) = P(Z \le z)$; $\Phi(0) = \frac{1}{2}$; $\Phi(-x) = 1 - \Phi(x)$.
- Python: `from scipy.stats import norm`; $\Phi(z)$ = `norm.cdf(z)`, ters fonksiyon `norm.ppf(p)`.
- $X = \sigma Z + \mu$ ($\sigma > 0$): $X \sim N(\mu, \sigma^2)$, $f_X(x) = \frac{1}{\sqrt{2\pi}\,\sigma} \exp\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)$.
- $F_X(x) = \Phi\left(\frac{x-\mu}{\sigma}\right)$, $P(a < X \le b) = \Phi\left(\frac{b-\mu}{\sigma}\right) - \Phi\left(\frac{a-\mu}{\sigma}\right)$.
- $X \sim N(\mu_X, \sigma_X^2)$, $Y = aX + b$ ise $Y \sim N(a\mu_X + b, a^2 \sigma_X^2)$.
- $\Gamma(\alpha) = \int_0^\infty x^{\alpha-1} e^{-x} dx$; $n$ doğal sayı ise $\Gamma(n) = (n-1)!$.
- Gamma$(\alpha, \lambda)$: $f_X(x) = \frac{\lambda^\alpha x^{\alpha-1} e^{-\lambda x}}{\Gamma(\alpha)}$ ($x > 0$); $E X = \frac{\alpha}{\lambda}$, $\text{Var}(X) = \frac{\alpha}{\lambda^2}$.
- Gamma$(1, \lambda)$ = Exponential$(\lambda)$; $n$ bağımsız Exponential$(\lambda)$ değişkenin toplamı Gamma$(n, \lambda)$'dır.

## Detaylı Açıklamalar

- **Dönüşüm yöntemi.** Ders, ara sınav öncesinde işlenen "sürekli rastgele değişkenin fonksiyonu" konusunun özetiyle başladı. Daha önce $Y = g(X)$ için önce $Y$'nin aralığını bulup CDF'yi $P(g(X) \le y)$ üzerinden hesaplamış, sonra türev almıştık. Dönüşüm yöntemi bu fikri formüle bağlar. $g$'nin grafiği, fonksiyonun sürekli artan ya da sürekli azalan olduğu parçalara ayrılır; derste çizilen örnekte artan, azalan, artan olmak üzere $n = 3$ parça vardı ve her parçada $g'(x)$ mevcuttu (ekrandan, 00:15:00). Her parçada $g(x) = y$ denkleminin tek bir çözümü $x_i$ vardır. Bu çözümlerdeki yoğunluk değerleri, türevin mutlak değerine bölünüp toplanınca $f_Y(y)$ elde edilir. Türevin mutlak değerine bölmek yerine $|dx_i/dy|$ ile çarpmak da aynı sonucu verir.
- **$Y = X^2$ örneği.** $X$'in yoğunluğu $f_X(x) = \frac{1}{\sqrt{2\pi}} e^{-x^2/2}$ (her $x \in \mathbb{R}$). $g(x) = x^2$, $(-\infty, 0)$ aralığında azalan, $(0, \infty)$ aralığında artandır; yani $n = 2$ parça vardır (ekrandan, 00:25:00). Birinci parçada $x_1 = -\sqrt{y}$, ikinci parçada $x_2 = \sqrt{y}$ bulunur; $g'(x) = 2x$'tir (ekrandan, 00:30:00). Formüle koyunca her iki terim de $\frac{1}{\sqrt{2\pi}} \frac{e^{-y/2}}{2\sqrt{y}}$ olur, toplamları $\frac{1}{\sqrt{2\pi y}} e^{-y/2}$ verir ve bu yalnız $y > 0$ için geçerlidir (ekrandan, 00:35:00). Sonuç, sayısal türevle karşılaştırılarak doğrulandı.
- **Düzgün dağılım.** Yoğunluk $a$ ile $b$ arasında sabittir; "uniform" adı da buradan gelir. Eğri altındaki alan 1 olması gerektiği için yükseklik $\frac{1}{b-a}$'dır. Ortalama $\frac{a+b}{2}$, varyans $\frac{(b-a)^2}{12}$ olarak ekrana yazıldı ve türetmesi öğrenciye bırakıldı (ekrandan, 00:45:00).
- **Üstel dağılım.** Bekleme süreleri gibi olaylar arası süreleri modellemek için kullanılır; süre negatif olamayacağı için negatif $x$'te yoğunluk sıfırdır. Grafik $x = 0$'da $\lambda$ değerinden başlar ve $x \to \infty$ iken sıfıra iner (ekrandan, 00:50:00). Parçalı fonksiyonları tek ifadeyle yazmak için birim basamak fonksiyonu kullanılabilir: $f_X(x) = \lambda e^{-\lambda x} u(x)$ (ekrandan, 00:55:00). Tanımda $x > 0$, $u(x)$'te ise $x \ge 0$ yazması tek bir noktada farka yol açar; sürekli bir değişkenin tek bir noktayı alma olasılığı 0 olduğu için bu fark hesapları etkilemez.
- **Belleksizlik.** Bir çağrı merkezinde müşteri araması beklendiğini düşünelim. 5 dakika zaten beklenmişse ($a = 5$), toplamda 15 dakikadan fazla bekleme olasılığı, sıfırdan başlayıp 10 dakikadan fazla bekleme olasılığına eşittir ($x = 10$). Yani geçmişte beklenen 5 dakika, gelecekteki bekleme olasılığını değiştirmez (ekrandan, 01:15:00).
- **Standart normal dağılım ve $\Phi$.** Standart normal değişken genelde $Z$ ile gösterilir, çünkü problemlerde $X$'ten $Z$'ye dönüşüm yapılır. Yoğunluk $z = 0$ etrafında simetrik ve çan biçimlidir. CDF'nin kapalı bir çözümü yoktur; integral yalnız tanım olarak yazılır ve değerler kitap sonundaki tablolardan ya da yazılım paketlerinden sayısal olarak alınır (ekrandan, 01:30:00). Bu CDF çok kullanıldığı için özel bir sembolü vardır: $\Phi$. Derste $\Phi(1.6)$ Python'da `norm.cdf(1.6)` ile $0.945200708300442$ bulundu, `norm.ppf` ile geri dönüldüğünde küçük bir sayısal hatayla $1.6$ elde edildi (ekrandan, 01:40:00). $\Phi$ grafiği 0'dan 1'e çıkan bir S eğrisidir, $\Phi(0) = \frac{1}{2}$'dir ve simetri nedeniyle $\Phi(-x) = 1 - \Phi(x)$ olur (ekrandan, 01:50:00).
- **Genel normal dağılım.** $X = \sigma Z + \mu$ ($\sigma > 0$) tanımlanınca $E X = \mu$, $\text{Var}(X) = \sigma^2$ olur ve $X \sim N(\mu, \sigma^2)$ yazılır (ekrandan, 01:55:00). $X$'in CDF'sinin de kapalı formu yoktur; ama $Z = \frac{X - \mu}{\sigma}$ olduğundan $F_X(x) = \Phi\left(\frac{x-\mu}{\sigma}\right)$ yazılabilir. Grafik $x = \mu$ etrafında simetriktir; varyans büyüdükçe olasılık daha geniş alana yayılır, küçüldükçe ortada sıkışır. Bu yüzden varyansa "yayılım" (spread) da denir.
- **Sayısal örnek.** $X \sim N(-5, 4)$ için $P(-7 < X < -3)$: $\sigma = 2$; sınırlar standartlaştırılınca $\frac{-7-(-5)}{2} = -1$ ve $\frac{-3-(-5)}{2} = 1$ olur. Sonuç $\Phi(1) - \Phi(-1) \approx 0.6827$'dir (ekrandan, 02:25:00 ve 02:30:00).
- **Doğrusal dönüşüm.** Normal bir değişkenin doğrusal dönüşümü yine normaldir: $Y = aX + b$ için $Y \sim N(a\mu_X + b, a^2 \sigma_X^2)$. $X^2$ ya da $\log X$ gibi doğrusal olmayan dönüşümler bu kapsamda değildir (ekrandan, 02:30:00).
- **Gama dağılımı.** İki parametresi vardır: $\alpha > 0$ ve $\lambda > 0$. Yoğunluktaki $\Gamma(\alpha)$, gama fonksiyonudur: $\Gamma(\alpha) = \int_0^\infty x^{\alpha-1} e^{-x} dx$. Doğal sayılarda faktöriyelle ilişkilidir: $\Gamma(n) = (n-1)!$, örneğin $\Gamma(3) = 2! = 2$ (ekrandan, 02:45:00). Gama dağılımının grafiği parametrelere göre çok değişir: $\alpha = 1, \lambda = 1$'de üstel dağılım gibi görünür; derste $\alpha = 2, \lambda = \frac{1}{2}$ ve $\alpha = 3, \lambda = \frac{1}{2}$ eğrileri de çizildi ve $\alpha$ arttıkça grafiğin normal dağılıma benzediği söylendi. $\alpha = 1$ konunca $\Gamma(1) = 0! = 1$ ve $x^0 = 1$ olduğundan yoğunluk $\lambda e^{-\lambda x}$'e, yani üstel dağılıma iner. Ayrıca $n$ bağımsız üstel değişkenin toplamı Gamma$(n, \lambda)$ dağılımına uyar; ortalama ve varyans bu fikirle (en azından $\alpha \in \{1, 2, 3, \dots\}$ için) bulunabilir (ekrandan, 02:50:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
