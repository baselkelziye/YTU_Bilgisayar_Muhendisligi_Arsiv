# Ders 6 Genişletilmiş Notu: Sayısal İntegrale Giriş ve Yamuk (Trapez) Yöntemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayısal Türevden Sayısal İntegrale
- 2. Temel Strateji: Fonksiyonu Polinoma Benzetmek
- 3. Yamukla Yaklaşık Alan ve Parçalara Bölme
- 4. Sayısal İntegral Çeşitleri
- 5. Trapez (Yamuk) Yöntemi
- 6. Örnek: 1/(1+x²) Fonksiyonunun 0-1 Aralığında İntegrali
- 7. Ders Sonundaki Sorular
- Örnek Sorular

## 1. Sayısal Türevden Sayısal İntegrale

Önceki konu olan sayısal türevde amaç, bir $f(x)$ fonksiyonunun türevinin belirli bir $x_i$ noktasındaki değerini, yani $f'(x_i)$ sayısını, farklı yaklaşım formülleriyle hesaplamaktı. Sayısal integralde de elimizde bir $f(x)$ fonksiyonu vardır. Bu fonksiyonun belirsiz integrali yine bir fonksiyondur. Belirli integral alındığında ise $a$'dan $b$'ye

$$\int_a^b f(x)\,dx = C$$

biçiminde sabit bir sayısal sonuç elde edilir (ekrandan, 00:15:00).

Belirli integralin analitik yöntemlerle, yani integral kurallarıyla hesaplanması bazen çok güçtür. Bilinen yöntemler değişken dönüştürme ($u$ yerine koyma), kısmi integrasyon (integration by parts, $u\,dv$) ve basit kesirlere ayırmadır. Bunlarla çözülemeyen ya da çözülmesi çok güç durumlarla karşılaşılır. Belirsiz integral bulunamayınca $a$ ve $b$ sınırlarını yerine koymak, dolayısıyla sonuca ulaşmak mümkün olmaz. Sayısal integral yöntemleri bu işi iteratif, sayısal yollarla kolaylaştırır ve yaklaşık bir çözüm bulur. $\int_a^b f(x)\,dx$ belirli integralini yaklaşık hesaplamaya sayısal integral (numerical integration) denir. Bu derste kullanılacak araçlar Newton-Cotes formülleridir.

**Soru:** $a$ ile $b$ arasındaki belirli integral geometrik olarak ne anlama gelir? **Cevap:** $a$'dan $b$'ye fonksiyonun altında kalan alan demektir. Fonksiyon ne kadar karmaşık olursa olsun, hesaplanmak istenen bu taralı alandır.

## 2. Temel Strateji: Fonksiyonu Polinoma Benzetmek

**Soru:** İntegrali (ve türevi) kolay alınan fonksiyonlara genel olarak hangi örnek verilebilir? **Cevap:** Polinom fonksiyonlar.

$A x^n$ biçimindeki bir terimin integralinde üs bir artırılır ve yeni üsse bölünür (ekrandan, 00:20:00):

$$\int A\,x^n\,dx = \frac{A\,x^{n+1}}{n+1} + c$$

Fonksiyon hangi türden olursa olsun, bir şekilde polinoma çevrilebilirse integrali, dolayısıyla alanı kolayca hesaplanır. Polinom fonksiyonlara örnekler:

- Sabit fonksiyon: Örneğin 2 ile 8 noktaları arasında değeri 4 olan sabit bir fonksiyonun integrali alınırken aslında bir dikdörtgenin alanı hesaplanır.
- Doğrusal fonksiyonlar: $y = x$ doğrusu gibi.
- Kuadratik (ikinci dereceden), kübik, dördüncü ve beşinci dereceden fonksiyonlar.

Bunların hepsinde altındaki alan analitik yöntemlerle bulunabilir: integral alınır, sonra sınır değerleri yerine yazılır. O halde yapılması gereken, karmaşık fonksiyonu bir şekilde polinomlara benzetmektir. Bu polinom ailesine Newton-Cotes formülleri denir.

Fonksiyonun $a$ ve $b$ noktalarındaki değerleri $f(a)$ ve $f(b)$'dir. **Soru:** Fonksiyonun $a$ ve $b$'deki görüntülerini bulmak zor olmaz mı? **Cevap:** Bazı fonksiyonlarda elle hesaplamak zor olabilir. Ancak programlama dillerinin matematik kütüphaneleri (ör. C'deki `math.h`) bunu çok kolaylaştırır. Örneğin $e^{\sin(x^2)}$ ya da $\log_3(x^3)$ gibi karmaşık bir ifadenin değeri bile verilen bir $x$ için rahatça hesaplanır; Excel ile bile bulunabilir.

## 3. Yamukla Yaklaşık Alan ve Parçalara Bölme

### 3.1 Tek yamuk

Elimizde $(a, f(a))$ ve $(b, f(b))$ noktaları vardır. Bu iki noktadan, iki noktası bilinen doğru denklemiyle bir doğru çizilir. Doğrunun, $x$ ekseninin ve $x=a$, $x=b$ dikmelerinin oluşturduğu şekil geometrik olarak bir yamuktur. Yamuk alanı (alt taban + üst taban) × yükseklik / 2'dir. Yükseklik $b-a$, tabanlar $f(a)$ ve $f(b)$ olduğundan:

$$A \approx \frac{(b-a)\,\big(f(a)+f(b)\big)}{2}$$

> **Ders sonrası not:** Tahtada formül $(b-a)\cdot f(a)\cdot f(b)/2$ gibi yazılmış görünüyor (ekrandan, 00:20:00). Hocanın sözlü anlatımı ("alt taban artı üst taban çarpı yükseklik bölü 2") doğrudur; tabanlar çarpılmaz, toplanır.

Bu, fonksiyonun $a$-$b$ arasındaki alanının yaklaşık değeridir. Doğru üretmek, birinci dereceden bir polinom üretmek demektir. Doğru ile eğri arasında kalan bölge ise hatadır.

### 3.2 Aralığı bölerek hatayı azaltmak

Hata şu şekilde azaltılabilir: $a$ ile $b$'nin tam ortası $c = (a+b)/2$ alınır ve $f(c)$ bulunur. $a$'dan $c$'ye ve $c$'den $b$'ye birer doğru çizilir. İki yamuk oluşur, alanlarına $A_1$ ve $A_2$ denirse $A_1 + A_2$, tek yamukla bulunan $A$'dan daha doğrudur, yani hatası daha azdır. Bu düşünce, üniversiteye hazırlıkta görülen Riemann integraline benzer.

Sayısal integralin en temel mantığı budur. Yöntemde bölme sayısı (division sayısı) $n$ diye bir parametre bulunur. $n = 2$ alınırsa integral aralığı iki parçaya bölünür ve üç nokta kullanılır. $n = 3$ ise üç, $n = 4$ ise dört parçaya bölünür. Örneğin $n=4$ için $a$ ile $c$'nin ve $c$ ile $b$'nin ortaları da alınır; dört parçanın alanları toplamı iki parçalı sonuçtan daha doğrudur. $n$ sonsuza götürüldüğünde gerçek anlamda integral alınmış olur.

### 3.3 Doğru yerine eğri

Hatayı azaltmanın bir yolu da doğru yerine ikinci ya da üçüncü dereceden bir eğri geçirmektir. Doğru için iki nokta gerekir; doğru denklemi $y = mx + n$ biçiminde yazılır, eğim bulunup doğru denklemine geçilir.

> **Ders sonrası not:** Hoca doğru denklemini "y eşittir ax artı by artı c" diye söyledi; genel biçim $ax + by + c = 0$'dır. $y$ yalnız bırakıldığında söylendiği gibi $y = mx + n$ elde edilir.

İkinci dereceden bir eğri gerekirse $a_2 x^2 + a_1 x + a_0$ biçiminde bir parabol denkleminin katsayıları bulunur ve parabolün altındaki alan hesaplanır. Parabol de kullanılsa yapılan iş yine bir dikdörtgen ya da yamuk alanı hesabına benzer.

Özetle amaç, $f(x)$ fonksiyonunu yaklaşık alanı verecek şekilde $n$. dereceden bir polinoma dönüştürmektir. Bu polinom sabit, doğrusal, kuadratik ya da en fazla kübik olabilir. Fonksiyonu bulmak, önündeki katsayıları bulmak demektir; sonrası kolaydır. Genellikle üç yaklaşım kullanılır: doğrusal, parabol ve kübik.

## 4. Sayısal İntegral Çeşitleri

Slaytta üç çeşit gösterildi (ekrandan, 00:25:00):

| Yaklaşım | Polinom | Kural | Gereken nokta |
|---|---|---|---|
| Doğru uydurma | $f_n(x) = a_0 + a_1 x$ | Yamuk kuralı (Trapezoidal Rule) | 2 |
| Parabol uydurma | $f_n(x) = a_0 + a_1 x + a_2 x^2$ | Simpson'ın 1/3 kuralı | 3 |
| Kübik polinom uydurma | $f_n(x) = a_0 + a_1 x + a_2 x^2 + a_3 x^3$ | Simpson'ın 3/8 kuralı | 4 |

Sayısal türevdeki üç noktalı, beş noktalı türev formüllerinde olduğu gibi bu üç kuralın da temel formülleri vardır. Birinci parametre, verilen $[a,b]$ aralığının kaç parçaya bölüneceğidir (örneğin beş parça). Bu parça sayısına göre kuralın formülü uygulanır ve yaklaşık sonuç elde edilir.

### 4.1 Parabol için doğrusal denklem sistemi

Parabol uydurmak için üç nokta gerekir, çünkü üç bilinmeyen ($a_2$, $a_1$, $a_0$) vardır. Hoca, $x$ değişkeniyle karışmasın diye noktaları $\alpha$, $\beta$ ve $\theta$ diye adlandırdı. Bu değerler ve görüntüleri yerine konunca:

$$\begin{aligned}
a_2\,\alpha^2 + a_1\,\alpha + a_0 &= f(\alpha)\\
a_2\,\beta^2 + a_1\,\beta + a_0 &= f(\beta)\\
a_2\,\theta^2 + a_1\,\theta + a_0 &= f(\theta)
\end{aligned}$$

$\alpha$, $\beta$, $\theta$ ve $f(\alpha)$, $f(\beta)$, $f(\theta)$ bilinen sayılardır. Böylece üç bilinmeyenli üç doğrusal denklem elde edilir. Bu sistem (önceki derslerde görülen yöntemlerle) çözülünce parabolün denklemi ortaya çıkar ve algoritmanın sonraki adımlarında kullanılır.

Kübik eğri için dört nokta gerekir. Dört nokta arasında üç aralık, üç nokta arasında iki aralık oluşur. Örneğin üç aralık varsa ilk iki aralığa bir ikinci dereceden polinom, sonrakine başka bir polinom geçirilebilir; böylece daha az hata alınır. Her bölümde üç noktayla ayrı alan hesabı yapılır. Bunlara çok noktalı integraller denir.

## 5. Trapez (Yamuk) Yöntemi

### 5.1 Tanım

Slayttaki tanım (ekrandan, 00:30:00): Bu yöntemde integral $n$ sayıda dikdörtgen kullanılarak hesaplanır; $n$ ne kadar büyük ise gerçek değere o kadar yakın sonuç elde edilir.

$$I = \sum h_i f_i, \qquad f_i \rightarrow f(x_i), \qquad h_i = x_{i+1} - x_i \ (i.\text{ dikdörtgenin genişliği})$$

Dikdörtgenlerin genişliği sabit olduğundan

$$h = \frac{b-a}{n}$$

olarak yazılır. Burada bütün parçaların genişliği eşittir ve bu ortak genişliğe $h$ denir. Değişken uzunluklu trapez kuralları da vardır (uyarlamalı, adaptive trapez yöntemi gibi modifikasyonlar), fakat bu derste $h$ her zaman aynı kalır. Sonra her aralığın alanı alınır ve bunlar toplanır.

> **Ek bilgi (derste anlatılmadı):** Slayttaki $\sum h_i f_i$ ifadesi dikdörtgenlerle yapılan bir Riemann toplamı biçimindedir. Yamuk kuralında her parçanın yüksekliği olarak iki uç değerin ortalaması $(f_i + f_{i+1})/2$ kullanılır, bu yüzden aşağıda türetilen formül ortaya çıkar.

### 5.2 Kodun ilk adımları

Hoca, kod yazıldığını düşünerek ilk adımları sordu. **Soru:** Fonksiyon girildikten sonra ne yapılır? **Cevap:** $n$ sayısı ve aralık, yani $a$ ve $b$ alınır. $a$, $b$ ve $n$ olmadan sonraki adımlara geçilemez.

Bunlar alındıktan sonra $x$ ekseni bir dizide saklanabilir: ilk eleman $a$, sonra $a+h$, $a+2h$, $a+3h$, ..., en son $a + nh$, yani $b$. Bu $x$ dizisine karşılık $y$ dizisi de doldurulur: fonksiyonda $a$, $a+h$, $a+2h$, ... yerine konur. İki dizi ya da iki sütunlu bir matris kullanılabilir.

### 5.3 Formülün türetilmesi

Slayttaki şekilde $I = \int_a^b f(x)\,dx$ integralinin değerini hesaplamak üzere $[a,b]$ kapalı aralığı $n$ eşit parçaya ayrılır (ekrandan, 00:35:00). Noktalar $a = x_0, x_1, x_2, \dots, x_{n-1}, x_n = b$, görüntüleri $y_0, y_1, \dots, y_n$'dir. Hoca $x_0, x_1, x_2, x_3$ noktalarına küçük harflerle $a, b, c, d$, bunların görüntülerine büyük harflerle $A, B, C, D$ dedi: $A = f(a)$, $B = f(b)$, $C = f(c)$, ... Burada küçük $a$ girilen alt sınırdır, $b = a + h$, $c = b + h$ diye birbirinden türetilir.

**Soru:** $S_1$ alanının formülü nedir? **Cevap:** $\dfrac{A+B}{2}\,(x_1 - x_0)$. Bütün aralıklar eşit olduğundan $x_1 - x_0 = h$'dir. Bu yüzden $h = (b-a)/n$ bir değişkende saklanır; $h$ formülde tekrar tekrar kullanılır.

Öğrencilerin cevaplarıyla diğer parçalar da yazıldı (ekrandan, 00:35:00):

$$S_1 = \frac{A+B}{2}\,h, \qquad S_2 = \frac{B+C}{2}\,h, \qquad S_3 = \frac{C+D}{2}\,h$$

Alanın $d$ noktasında bittiği kabul edilirse toplam:

$$S_1 + S_2 + S_3 = \frac{h}{2}\,(A + B + B + C + C + D) = \frac{h}{2}\,\big(A + D + 2(B + C)\big)$$

Görüldüğü gibi $B$'ler ve $C$'ler ortaktır. İntegralin başlangıç ve bitiş noktası hariç bütün değerler ikişer kez gelir. Aralık uzatılırsa $D + E$, $E + F$ diye devam eder; formülün yapısı değişmez. Genel olarak:

$$I \approx \frac{h}{2}\Big(y_0 + 2\,(y_1 + y_2 + \dots + y_{n-1}) + y_n\Big), \qquad y_i = f(x_i),\ x_0 = a,\ y_0 = f(a)$$

$y$ dizisi $0$'dan $n$'e kadar $n+1$ elemanlıdır.

### 5.4 Algoritmik biçim

Ara değerlerin iki katı alınıyordu, dışarıda da $h/2$ vardı. $h/2$ bu 2'yi götürür. Böylece iki katını almaya da, sonra bölmeye de gerek kalmaz; ara değerler doğrudan toplanır:

$$I \approx h\left(\frac{y_0 + y_n}{2} + \sum_{i=1}^{n-1} y_i\right)$$

Yani $i = 1$'den $n-1$'e kadar değerlerin toplamı $h$ ile, $0$. ve $n$. değerlerin toplamının yarısı da $h$ ile çarpılır. Bu biçim, gereksiz bölme işleminin maliyetinden de kurtarır.

Program açısından kullanıcıdan yalnız $a$, $b$ ve $n$ alınır. Fonksiyonun eşitliği ne olursa olsun (örneğin $x^3$ ya da başka bir şey) bu üç parametre yeterlidir. Fonksiyonun görüntüleri hesaplanıp "ilk değer + son değer + 2 × aradakilerin toplamı" bulunur ve $h/2$ ile çarpılır. Aslında $x$ dizisine pek gerek yoktur, $y$ dizisi yeterlidir: $y[0] = f(a)$, $y[1] = f(a+h)$, ...

> **Hocanın vurgusu:** Bu yöntem gayet kolaydır, her şeyiyle yarım saatte kodlanabilir. Fonksiyonun değerini hesaplayan bir yardımcı C fonksiyonu yazılır; bu fonksiyon çağrılarak dizi doldurulur. Toplama, çarpma ve bir `for` döngüsüyle iş biter; hatta diziyi doldururken alan hesabı da aynı döngüde yapılabilir.

## 6. Örnek: 1/(1+x²) Fonksiyonunun 0-1 Aralığında İntegrali

Slayttaki soru (ekrandan, 00:40:00):

$$\int_0^1 \frac{1}{1+x^2}\,dx$$

integralini $n = 4$ alarak trapez yöntemi ile hesaplayınız.

**Verilen:** $x_0 = 0$, $x_n = 1$, $n = 4$.

**Adım 1:** $h = (1 - 0)/4 = 0{,}25$ (ekrandan, 00:40:00). Noktalar $0;\ 0{,}25;\ 0{,}5;\ 0{,}75;\ 1$'dir; dört aralık oluşur.

**Adım 2:** Fonksiyon değerleri:

| $i$ | $x_i$ | $y_i = 1/(1+x_i^2)$ |
|---|---|---|
| 0 | 0 | 1 |
| 1 | 0,25 | $1/1{,}0625 \approx 0{,}9412$ |
| 2 | 0,5 | $1/1{,}25 = 0{,}8$ |
| 3 | 0,75 | $1/1{,}5625 = 0{,}64$ |
| 4 | 1 | $1/2 = 0{,}5$ |

<!-- BELİRSİZ: Değer tablosunun gösterildiği slayt karelerde yok; değerler altyazıdaki sözlü anlatımdan ve hesaptan alındı. -->

**Adım 3:** İlk ve son değer toplanır: $1 + 0{,}5 = 1{,}5$. Bu, $h/2 = 0{,}125$ ile çarpılır: $1{,}5 \times 0{,}125 = 0{,}1875$.

> **Ders sonrası not:** Hoca $h/2$'yi söylerken "0.5 bölü 2" dedi; $h = 0{,}25$ olduğundan doğrusu $0{,}25/2 = 0{,}125$'tir. Söylenen sonuç ($0{,}125$) doğrudur.

**Adım 4:** Ara üç değer toplanıp $h$ ile çarpılır: $0{,}25 \times (0{,}9412 + 0{,}8 + 0{,}64) = 0{,}25 \times 2{,}3812 \approx 0{,}5953$.

**Sonuç:** $I \approx 0{,}1875 + 0{,}5953 \approx 0{,}7828$ birim kare. Hoca sonucu "0.78 küsur" olarak verdi; python ile hesaplanan değer $0{,}782794$'tür.

**Analitik çözüm:** Bir öğrenci, $1/(1+x^2)$'nin integralinin arktanjant olduğunu, $0$'dan $1$'e sınırlar konunca $\pi/4$ geldiğini ve $\pi \approx 3{,}14$ alınınca bunun yaklaşık $0{,}785$ ettiğini söyledi. Hoca da $\arctan 1 = 45° = \pi/4$ olduğunu doğruladı. Gerçek değer $\pi/4 \approx 0{,}785398$'dir. $n=4$ ile hata yaklaşık $0{,}0026$'dır; sonuç gerçek değere gayet yakındır. Hoca, $n$ biraz daha artırıldıkça hatanın daha da azaldığını gösterdi.

> **Ders sonrası not:** Hocanın ekrandaki hesaplayıcıda denediği $n = 9$ değeri altyazıdan net çıkmıyor. Python ile $n = 9$ için sonuç büyük olasılıkla $0{,}784884$, hata yaklaşık $0{,}00051$'dir; $n=4$'e göre hata yaklaşık beş kat azalır.

### 6.1 Çevrimiçi hesaplayıcıyla kontrol

Hoca, Google'da "numerical integration calculator" aratarak bulduğu bir çevrimiçi hesaplayıcıyı (PlanetCalc) gösterdi. Fonksiyon $1/(1+x^2)$, alt sınır 0, üst sınır 1, aralık sayısı 4 girildi. Sayfada her bölgenin sonucu ayrı ayrı ve etkileşimli olarak görülebiliyordu. Sayfadaki kuralın "Trapezoidal (open) rule" seçeneği ile sonuç $0{,}786266$ çıktı (ekrandan, 00:45:00). Hoca bu "açık" kuralın farkını bilmediğini, büyük olasılıkla son noktayı dahil etmediğini söyledi.

> **Ek bilgi (derste anlatılmadı):** "Açık" (open) Newton-Cotes formülleri, aralığın uç noktalarındaki $f(a)$ ve $f(b)$ değerlerini kullanmaz; yalnız iç noktaları kullanır. Ekrandaki formül $\int_{x_0}^{x_3} f(x)\,dx \approx \frac{3}{2}h\,\big(f(x_1) + f(x_2)\big)$ böyle bir formüldür (ekrandan, 00:45:00). Derste anlatılan yamuk kuralı ise uç noktaları kullanan "kapalı" bir formüldür; bu yüzden iki sonuç farklıdır.

## 7. Ders Sonundaki Sorular

**Soru:** İntegralde alan alınırken fonksiyon $x$ ekseninin altında kalırsa sonuç negatif olur. Bunu nasıl düşünmeliyiz, fonksiyonların hep pozitif değer ürettiğini mi varsaymalıyız? **Cevap:** Kod yazarken öyle düşünülebilir. Eksen altındaki bir parçada yükseklik negatif (örneğin $-2$), genişlik pozitif olduğu için alan değeri negatif gelir. Negatif gelen alan değeri $-1$ ile çarpılarak pozitife çevrilebilir.

> **Ek bilgi (derste anlatılmadı):** Belirli integralin değeri işaretlidir: eksen altındaki bölgeler integrale negatif katkı yapar. "İntegralin değeri" isteniyorsa negatif parçalar olduğu gibi toplanır; "eğri ile eksen arasındaki toplam geometrik alan" isteniyorsa parçaların mutlak değeri alınır. Hocanın önerdiği $-1$ ile çarpma ikinci duruma karşılık gelir.

**Soru:** Sayısal türev için seriye açılan çok noktalı formüller mi, yoksa slayttaki temel formüller mi kullanılmalı? **Cevap:** Merkezi, ileri ve geri fark seçenekleriyle, slayttaki $x$, $x+h$ ve $x-h$ noktalarını kullanan en basit formüller yeterlidir. Üç noktalı ve beş noktalı türev formüllerine gerek yoktur, isteyen yine de kullanabilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): $\displaystyle\int_0^1 \frac{1}{1+x^2}\,dx$ integralini $n = 4$ alarak trapez yöntemi ile hesaplayınız.

Çözüm (derste verildi): $h = (1-0)/4 = 0{,}25$. Değerler $y_0 = 1$, $y_1 \approx 0{,}9412$, $y_2 = 0{,}8$, $y_3 = 0{,}64$, $y_4 = 0{,}5$.

$$I \approx \frac{0{,}25}{2}(1 + 0{,}5) + 0{,}25\,(0{,}9412 + 0{,}8 + 0{,}64) = 0{,}1875 + 0{,}5953 \approx 0{,}7828$$

Gerçek değer $\arctan 1 = \pi/4 \approx 0{,}7854$; hata yaklaşık $0{,}0026$ (python ile doğrulandı).

**Soru 2** (derste sözlü, 00:31:46): Eşit genişlikli parçalara bölünmüş bir aralıkta $x_0, x_1, x_2, x_3$ noktalarının görüntüleri $A, B, C, D$ ise $S_1$, $S_2$, $S_3$ yamuk alanlarının formülleri ve toplamları nedir?

Çözüm (derste verildi): $S_1 = \frac{A+B}{2}h$, $S_2 = \frac{B+C}{2}h$, $S_3 = \frac{C+D}{2}h$; toplam $\frac{h}{2}\big(A + D + 2(B+C)\big)$ (ekrandan, 00:35:00).

## Dersin Toparlaması

Bu derste sayısal integrale giriş yapıldı. Belirli integralin analitik olarak hesaplanamadığı ya da hesaplanmasının çok güç olduğu durumlarda, fonksiyonu integrali kolay alınan polinomlarla (Newton-Cotes ailesi) değiştirip eğrinin altındaki alanı yaklaşık bulmak temel stratejidir. Doğru uydurma yamuk kuralını, parabol uydurma Simpson'ın 1/3 kuralını, kübik polinom uydurma Simpson'ın 3/8 kuralını verir; sırasıyla 2, 3 ve 4 nokta gerekir. Yamuk (trapez) yönteminde $[a,b]$ aralığı $h = (b-a)/n$ genişliğinde $n$ eşit parçaya bölünür; ilk ve son değerin yarısı ile aradaki değerlerin toplamı $h$ ile çarpılır. $\int_0^1 \frac{dx}{1+x^2}$ örneğinde $n=4$ ile $0{,}7828$ bulundu; gerçek değer $\pi/4 \approx 0{,}7854$'tür ve $n$ arttıkça hata azalır.

Bir sonraki derste Simpson yöntemleriyle devam edileceği, yöntemlerin mantığından algoritmalarına ve kodlanmasına geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
