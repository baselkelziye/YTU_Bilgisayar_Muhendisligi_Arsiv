# Ders 4 Genişletilmiş Notu: Limit ve Süreklilik Alıştırmaları: Süreksizlik Türleri ve Tanım Kümesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Mutlak Değerli Limitler ve Tek Taraflı Limitler
- 2. Parçalı Fonksiyonda Limit (Vize Sorusu)
- 3. Değişken Değiştirme ile Temel Limite İndirgeme
- 4. Süreksizlik Noktaları ve Türleri
- 5. Karşı Örnekle Çürütme
- 6. Parametreli Fonksiyon Ailesinde Süreklilik
- 7. Kaldırılabilir Süreksizlik ve Sürekli Hâle Getirme
- 8. Tanım Kümesi Soruları
- 9. Ek Limit Alıştırmaları
- 10. $0\cdot\infty$ Belirsizliği ve Sıkıştırma Teoremi
- 11. Eşlenik, Kök Dönüşümü ve L'Hôpital'e Uygun Sorular
- 12. Limitin Sürekli Fonksiyonun İçine Alınması ve Her Yerde Süreklilik
- Örnek Sorular

## 1. Mutlak Değerli Limitler ve Tek Taraflı Limitler

Bu ders yeni konu anlatılmayan bir alıştırma dersidir. Hoca geçmiş yılların sınav ve uygulama sorularını ekranda paylaşır, öğrencilere birkaç dakika çözmeleri için süre verir, sonra çözümü tablete yazarak anlatır. Dersin başında bir önceki derste çözülmüş bir soruya kısaca dönülür ($x\to0$ iken $\sqrt{2+\sin x}$ içeren bir limit). <!-- BELİRSİZ: 00:00:58'deki ifadenin devamı altyazıda yok. -->

### 1.1 Örnek 1: $\sin|x|$ İçeren Limit

Soru şudur:

$$\lim_{x\to0}\frac{1-\cos x}{\sin|x|\cdot\tan x}$$

Hoca hemen bir uyarı yapar: $\sin$ fonksiyonu $x$'e değil, $|x|$'e uygulanmıştır. Mutlak değerin tanımı $x$'in işaretine göre değiştiği için $0$'a sağdan ve soldan yaklaşma ayrı ayrı incelenmelidir. İki yoldan farklı sonuç çıkarsa limit yoktur.

**Tanım (Limitin varlığı):**

- $\lim_{x\to a}f(x)$ ancak sol limit ve sağ limit var ve birbirine eşitse vardır.
- Sol ve sağ limit farklıysa limit yoktur.

**Sağdan yaklaşma ($x\to0^+$).** Bu durumda $x>0$'dır. Mutlak değerin tanımına göre $|x|=x$ olur. $\tan x=\dfrac{\sin x}{\cos x}$ yazılır:

$$\frac{1-\cos x}{\sin x\cdot\dfrac{\sin x}{\cos x}}=\frac{(1-\cos x)\cos x}{\sin^2x}$$

Pisagor özdeşliğinden $\sin^2x=1-\cos^2x=(1-\cos x)(1+\cos x)$ yazılır. Belirsizliğe yol açan $(1-\cos x)$ çarpanı sadeleşir:

$$\lim_{x\to0^+}\frac{(1-\cos x)\cos x}{(1-\cos x)(1+\cos x)}=\lim_{x\to0^+}\frac{\cos x}{1+\cos x}=\frac{1}{1+1}=\frac12$$

**Soldan yaklaşma ($x\to0^-$).** Bu durumda $x<0$'dır, dolayısıyla $|x|=-x$ olur. $\sin$ tek fonksiyondur (odd function): $\sin(-x)=-\sin x$. Böylece payda $-\sin x\tan x$ olur. Aynı sadeleştirme adımları uygulanır. Tek fark işarettir:

$$\lim_{x\to0^-}\frac{1-\cos x}{-\sin x\tan x}=-\frac12$$

Sağ limit $\frac12$, sol limit $-\frac12$'dir. Farklı oldukları için limit yoktur.

**Soru:** Cevap $\frac12$ mi? **Cevap:** Hayır. $\frac12$ yalnız sağdan yaklaşmanın sonucudur. Soldan $-\frac12$ çıkar, bu yüzden limit yoktur.

**Soru:** Neden limit yok, anlayamadım. **Cevap:** Limitin var olması için sol ve sağ limitin sonucu aynı olmalıdır. Aksi hâlde limit yoktur.

## 2. Parçalı Fonksiyonda Limit (Vize Sorusu)

Hoca bu soruyu "bu yılın vize sorusu" olarak tanıtır. Fonksiyon gerçel değerli ve gerçel değişkenlidir, parçalı tanımlanmıştır: $x\le-2$ için bir kural, $-2<x<1$ civarında $\dfrac{1}{x+2}$, $x>1$ için $\dfrac{\sin(1-\sqrt x)}{x-1}$ biçiminde kurallar vardır. <!-- BELİRSİZ: Parçalı tanımın tam hâli (özellikle x ≤ -2 kuralı ve x = 1'deki eşitlik durumu) altyazıda döngü nedeniyle okunmuyor (00:08:46); orta ve sağ kurallar kısa nottaki kare okumasından alındı. -->

### 2.1 $x=-2$'de limit

Sağdan yaklaşmada $\dfrac{1}{x+2}$ kuralı kullanılır. $x\to-2^+$ iken payda pozitif yönden $0$'a gider:

$$\lim_{x\to-2^+}\frac{1}{x+2}=+\infty$$

Tek taraflı limitlerden biri sonsuz olduğu için $x=-2$'de limit yoktur.

### 2.2 $x=1$'de limit

**Sağ limit.** Hoca önce şunu söyler: elimizde $\sin u$ biçimli bir ifade var, $u=1-\sqrt x$. Temel formülü kullanmak için paydada da $u$ görmek gerekir. Bu yüzden payda çarpanlarına ayrılır. $a^2-b^2=(a-b)(a+b)$ özdeşliğiyle:

$$x-1=-(1-x)=-(1-\sqrt x)(1+\sqrt x)$$

Böylece:

$$\lim_{x\to1^+}\frac{\sin(1-\sqrt x)}{-(1-\sqrt x)(1+\sqrt x)}=\lim_{x\to1^+}\frac{\sin(1-\sqrt x)}{1-\sqrt x}\cdot\frac{-1}{1+\sqrt x}$$

$x\to1^+$ iken $u=1-\sqrt x\to0$ olduğu için ilk çarpan $1$'e gider. İkinci çarpan $\frac{-1}{1+1}=-\frac12$ olur. Sağ limit $-\frac12$'dir.

> **Ders sonrası not:** Altyazıda hocanın sözlü sonucu "2 minus 1 over 2" gibi karışık geçiyor (00:10:55). Hesap ve kısa nottaki kare okuması sağ limitin $-\frac12$ olduğunu gösteriyor.

**Soru:** Bu çarpan nereden geliyor? **Cevap:** $x-1$'i çarpanlarına ayırdık. $1-\sqrt x$ ile $1+\sqrt x$'in çarpımı $a^2-b^2=(a-b)(a+b)$ özdeşliğinden gelir. $x-1$ bunun eksi işaretlisidir.

**Sol limit.** $x\to1^-$ iken $\dfrac{1}{x+2}$ kuralı kullanılır. Belirsizlik yoktur, doğrudan yerine konur:

$$\lim_{x\to1^-}\frac{1}{x+2}=\frac13$$

Sol limit $\frac13$, sağ limit $-\frac12$'dir. Farklı oldukları için $x=1$'de limit yoktur. Hoca burada öğrencilerin hemen L'Hôpital kuralına (L'Hôpital's rule) yöneldiğini fark eder ve önce L'Hôpital'siz çözmeyi öğrenmeleri gerektiğini söyler. L'Hôpital ileride anlatılacaktır.

### 2.3 Süreksizlik türleri

- $x=-2$: tek taraflı limitlerden biri $+\infty$. Sonsuz süreksizlik (infinite discontinuity).
- $x=1$: sol ve sağ limit sonlu ama farklı. Sıçrama süreksizliği (jump discontinuity).

## 3. Değişken Değiştirme ile Temel Limite İndirgeme

### 3.1 Örnek 3: $\lim_{x\to\pi}\dfrac{\sin2x}{x^2-\pi x}$

Hoca önce daha önce ispatlanan iki temel formülü hatırlatır:

$$\lim_{u\to0}\frac{\sin u}{u}=1,\qquad \lim_{u\to\infty}\frac{\sin u}{u}=0$$

İkincisinde $\sin u$, $-1$ ile $+1$ arasında salınan bir sinyaldir (signal). Payda sınırsız büyüdüğü için sıkıştırma teoremiyle (sandwich theorem) sonuç $0$'dır.

Soruda $x\to\pi$ iken $\frac00$ belirsizliği vardır. Temel formüle benzetmek için $t=x-\pi$ dönüşümü yapılır. $x\to\pi$ iken $t\to0$ olur ve $x=t+\pi$'dir.

- Pay: toplam formülüyle $\sin(2t+2\pi)=\sin2t\cos2\pi+\cos2t\sin2\pi=\sin2t$.
- Payda: $x^2-\pi x=x(x-\pi)=(t+\pi)t$.

Temel formülü elde etmek için $2$ ile çarpılıp bölünür:

$$\lim_{t\to0}\frac{\sin2t}{t(t+\pi)}=\lim_{t\to0}\frac{\sin2t}{2t}\cdot\frac{2}{t+\pi}=1\cdot\frac{2}{\pi}=\frac{2}{\pi}$$

Bir öğrencinin farklı bir yoldan (yarım açı benzeri bir özdeşlikle) gittiği anlaşılıyor. Hoca, mantıklı bir yol izlendiyse sorun olmadığını, o özdeşliğin de toplam formülünden geldiğini söyler.

## 4. Süreksizlik Noktaları ve Türleri

Hoca üç süreksizlik türünü hatırlatır: sıçrama (jumping), kaldırılabilir (removable) ve sonsuz (infinite) süreksizlik.

**Tanım (Süreksizlik türleri):**

- **Sonsuz süreksizlik:** tek taraflı limitlerden en az biri $\pm\infty$.
- **Sıçrama süreksizliği:** sol ve sağ limit sonlu, ama farklı. Arada "zıplanacak bir mesafe" olduğu için bu adı alır.
- **Kaldırılabilir süreksizlik:** limit var ve sonlu, ama $f(a)$ tanımsız ya da limite eşit değil.

> **Hocanın vurgusu:** Test sınavında "Aşağıdakilerden hangileri doğrudur? $x=0$ kaldırılabilir süreksizliktir; $x=2$ sonsuz süreksizliktir; $x=x_2$ sıçrama süreksizliğidir" gibi doğru-yanlış soruları gelebilir.

### 4.1 Örnek 4: $f(x)=\dfrac{3|x-2|}{x^2(4-x^2)}$

Paydayı sıfır yapan noktalar $x=0$, $x=2$ ve $x=-2$'dir. Fonksiyon bu noktalarda tanımsız, dolayısıyla süreksizdir. Her birinin türü incelenir. Payda $x^2(4-x^2)=x^2(2-x)(2+x)$ biçiminde yazılır.

**$x=0$.** Bu noktanın yakınında $x<2$ olduğu için $|x-2|=2-x$'tir. Sadeleşince:

$$f(x)=\frac{3(2-x)}{x^2(2-x)(2+x)}=\frac{3}{x^2(2+x)}$$

$x\to0$ iken iki taraftan da $+\infty$'a gider. Sonsuz süreksizliktir.

**$x=-2$.** Yine $|x-2|=2-x$'tir ve aynı sadeleşmiş ifade kullanılır.

- $x\to-2^+$: $2+x\to0^+$, sonuç $+\infty$.
- $x\to-2^-$: $2+x\to0^-$, sonuç $-\infty$.

Sonsuz süreksizliktir.

**$x=2$.** Burada mutlak değer işaret değiştirir.

- $x\to2^+$: $x>2$ olduğu için $|x-2|=x-2$. $\dfrac{3(x-2)}{x^2(2-x)(2+x)}=\dfrac{-3}{x^2(2+x)}\to\dfrac{-3}{4\cdot4}=-\dfrac{3}{16}$.
- $x\to2^-$: $|x-2|=2-x$. $\dfrac{3}{x^2(2+x)}\to\dfrac{3}{16}$.

Sol ve sağ limit sonlu ama farklıdır. $x=2$ sıçrama süreksizliğidir.

## 5. Karşı Örnekle Çürütme

Örnek 4 çözülürken bir öğrenci "$0$ ve $2$ tanım kümesinde olmadığı için sonsuz süreksizliktir" diye itiraz eder. Hoca bunun yanlış bir yaklaşım olduğunu söyler. Bir nokta tanım kümesinde olsa da olmasa da sıçrama süreksizliği olabilir.

Hoca iddiayı tek bir karşı örnekle (counterexample) çürütür:

$$f(x)=\frac{\sin x}{x}$$

- $0$, $f$'nin tanım kümesinde değildir.
- Ama $\lim_{x\to0}\dfrac{\sin x}{x}=1$'dir. Limit var ve sonludur.
- Dolayısıyla $x=0$ sonsuz süreksizlik değil, kaldırılabilir süreksizliktir.

"Tanım kümesinde değilse sonsuz süreksizliktir" genel ifadesi bu yüzden yanlıştır.

> **Hocanın vurgusu:** Örnekle çürütme yapılabilir, örnekle doğrulama yapılamaz. Genel bir iddiayı çürütmek için tek bir karşı örnek yeter. Ama birkaç örneğin iddiaya uyması iddiayı kanıtlamaz.

## 6. Parametreli Fonksiyon Ailesinde Süreklilik

### 6.1 Örnek 5: $f_{0,-1}$'in sürekliliği

Soruda $\alpha\ge0$ ve $\beta\in\mathbb{R}$ sabitlerine bağlı bir $f_{\alpha,\beta}$ fonksiyon ailesi verilir. $\alpha$ ve $\beta$, $f$'nin bağımsız değişkeni olan $x$'ten bağımsızdır; $x$'e göre sabittirler. Her $(\alpha,\beta)$ çifti için ayrı bir fonksiyon elde edilir. İstenen, $\alpha=0$, $\beta=-1$ için $f_{0,-1}$'in $\mathbb{R}$ üzerinde sürekli olup olmadığıdır. <!-- BELİRSİZ: f_{α,β}'nın tam tanımı altyazıda okunmuyor; α=0, β=-1 yerine konunca x ≠ 0 için sin(1/x) biçimi çıktığı söyleniyor (00:27:46). -->

> **Hocanın vurgusu:** Fonksiyon tek bir noktada bile sürekli değilse $\mathbb{R}$ üzerinde sürekli değildir.

$\alpha=0$, $\beta=-1$ yerine konunca fonksiyon $x\ne0$ için $\sin\dfrac1x$ biçimine gelir. $x=0$'da limitin varlığı incelenir. $t=\dfrac1x$ dönüşümü yapılır. Yaklaşma yönüne göre $t\to+\infty$ ya da $t\to-\infty$ olur:

$$\lim_{x\to0}\sin\frac1x=\lim_{t\to\pm\infty}\sin t$$

Hoca sinüs sinyalinin grafiğini çizer. $t\to\infty$ iken $\sin t$, $-1$ ile $+1$ arasında salınım yapar ve hiçbir değere yaklaşmaz. Bu yüzden limit yoktur. $f_{0,-1}$, $x=0$'da sürekli değildir, dolayısıyla $\mathbb{R}$ üzerinde sürekli değildir.

**Karıştırmayın.** Hoca bunun yanına benzer görünen ama farklı bir limit yazar:

$$\lim_{x\to\infty}\sin\frac1x=\sin0=0$$

Burada $x\to\infty$ iken $\frac1x\to0$'dır, salınım yoktur. Grafikte başta dalgalanma görülse de belli bir yerden sonra eğri $0$'a yaklaşır.

## 7. Kaldırılabilir Süreksizlik ve Sürekli Hâle Getirme

### 7.1 Örnek 6: $\lim_{x\to\infty}\dfrac{x-\sqrt{1+x^2}}{x-\sqrt x}$

Bu soru L'Hôpital'siz, eşlenik (conjugate) yöntemiyle ya da ortak çarpan almayla çözülebilir. Hoca ortak çarpan almayı daha kolay bulur. $x\to\infty$ iken $x>0$'dır, bu yüzden $\sqrt{x^2}=x$ ve:

$$\sqrt{1+x^2}=x\sqrt{1+\frac{1}{x^2}},\qquad x-\sqrt x=x\left(1-\frac{1}{\sqrt x}\right)$$

$$\lim_{x\to\infty}\frac{x\left(1-\sqrt{1+\frac{1}{x^2}}\right)}{x\left(1-\frac{1}{\sqrt x}\right)}=\frac{1-1}{1-0}=0$$

### 7.2 Örnek 7: $f(x)=\dfrac{x^2}{1-\cos x}$

İstenen iki şey vardır: önce $x=0$'daki süreksizliğin türünü belirlemek, sonra $f$'yi $x=0$'da sürekli bir fonksiyona dönüştürmek.

Hoca önce bir ön koşulu vurgular. Fonksiyonun sonsuz süreksizliği varsa sürekli bir fonksiyona dönüştürülemez. Dönüştürmek için süreksizliğin kaldırılabilir olması gerekir.

Eşlenik $1+\cos x$ ile çarpılıp bölünür. Paydada $1-\cos^2x=\sin^2x$ çıkar:

$$\lim_{x\to0}\frac{x^2(1+\cos x)}{1-\cos^2x}=\lim_{x\to0}\frac{x^2(1+\cos x)}{\sin^2x}=\lim_{x\to0}\left(\frac{x}{\sin x}\right)^2(1+\cos x)$$

Hoca iki "kutuyu" işaretler: $\left(\frac{x}{\sin x}\right)^2\to1$, $(1+\cos x)\to2$. Sonuç $1\cdot2=2$'dir.

Limit vardır ($2$), ama $0$ tanım kümesinde değildir; $f(0)$ tanımsızdır. Bu yüzden $x=0$ kaldırılabilir süreksizliktir. Yeni bir $g$ fonksiyonu tanımlanır:

$$g(x)=\begin{cases}\dfrac{x^2}{1-\cos x}, & x\ne0\\[2mm] 2, & x=0\end{cases}$$

$g$, $x=0$'da süreklidir. Hoca ayrıca soruda fonksiyon kuralının belki yanlış yazılmış olabileceğini söyler, ama verilen kurala göre çözer.

**Soru:** Bu sıçrama süreksizliği mi? **Cevap:** Hayır. Sıçrama süreksizliği için sol ve sağ limitlerin ikisi de sonlu ama farklı olmalıdır. Burada iki taraf da $2$'ye gider.

<!-- BELİRSİZ: 00:35:42 - 00:37:35 arası altyazıda döngü ve anlamsız tekrarlar var; g'nin yazılışından sonraki açıklama okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Genel kural şudur: $x=a$ kaldırılabilir süreksizlikse ve $L=\lim_{x\to a}f(x)$ ise, $g(x)=f(x)$ ($x\ne a$), $g(a)=L$ diye tanımlanan fonksiyon $a$'da süreklidir. Buna büyük olasılıkla ders kitaplarında "sürekli genişleme" (continuous extension) denir.

### 7.3 Örnek 8: $f(x)=\dfrac{2|1-x|}{x^2(1-x)}$

Fonksiyonun sürekliliği ve varsa süreksizlik türleri istenir. Paydayı sıfır yapan noktalar $x=0$ ve $x=1$'dir.

**$x=0$.** Yakınında $1-x>0$, yani $|1-x|=1-x$. Sadeleşince $\dfrac{2}{x^2}$ kalır. İki taraftan $+\infty$'a gider. Sonsuz süreksizliktir.

**$x=1$.**

- $x\to1^-$: $|1-x|=1-x$, ifade $\dfrac{2}{x^2}\to2$.
- $x\to1^+$: $|1-x|=x-1=-(1-x)$, ifade $\dfrac{-2}{x^2}\to-2$.

Sol ve sağ limit sonlu ve farklıdır. $x=1$ sıçrama süreksizliğidir.

Sonuç: $f$, $\mathbb{R}\setminus\{0,1\}$ üzerinde süreklidir. $x=0$ bir sonsuz süreksizlik, $x=1$ bir sıçrama süreksizliğidir.

> **Hocanın vurgusu:** Kaldırılabilir süreksizlik varsa fonksiyondan sürekli yeni bir fonksiyon elde edilebilir. Aksi durumda o fonksiyon asla sürekli bir fonksiyona dönüştürülemez. Bu örnekte kaldırılabilir süreksizlik olmadığı için $f$ sürekli hâle getirilemez.

### 7.4 Kısaca geçilen iki soru

Hoca bundan sonra daha önce benzerlerinin çözüldüğünü söylediği iki soruya kısaca bakar.

- İlk soruda L'Hôpital kullanmadan eşlenik yöntemi ve $\tan x$'i $\sin x$ ile $\cos x$ cinsinden yazma önerilir. Çözümde $\sin2x=2\sin x\cos x$ özdeşliği kullanılır ve sadeleşmeyle bir çarpan $1$'e gider. <!-- BELİRSİZ: Sorunun ifadesi ve sonucu altyazıda okunmuyor (00:43:10 - 00:44:55). -->
- İkinci soruda hoca, hangi yöntemin kullanılacağını öğrencinin belirlemesi gerektiğini söyler. Çözüm sıkıştırma teoremiyledir: alt sınır ve üst sınır $x\to0$ iken $0$'a gider, bu yüzden ortadaki ifade de $0$'a gider. Sonuç $0$'dır. <!-- BELİRSİZ: Bu sorunun ifadesi altyazıda yok (00:45:15 - 00:46:53). -->

## 8. Tanım Kümesi Soruları

Hoca bu tür soruların sınavda gelebileceğini söyler.

### 8.1 Örnek 9a: $f(x)=\dfrac{\sqrt{|2x+5|-3}}{x^2+1}$

**Soru:** Bu "$+5i$" mi? **Cevap:** Hayır, $i$ değil, mutlak değer. Gerçel sayılar kümesi üzerinde, gerçel değerli fonksiyonlar teorisi çalışılıyor; karmaşık değerli fonksiyonlar değil.

Karekök sembolünün anlamlı olması için kök içindeki ifade pozitif ya da sıfır olmalıdır. Bu ilk koşuldur:

$$|2x+5|-3\ge0\iff|2x+5|\ge3$$

Bu eşitsizlik iki duruma ayrılır:

- $2x+5\ge3\Rightarrow x\ge-1$,
- veya $2x+5\le-3\Rightarrow x\le-4$.

Mantık dilinde "veya" (or) birleşime (union) karşılık gelir. Bu yüzden iki durumdan gelen kümeler birleştirilir:

$$D(f)=(-\infty,-4]\cup[-1,\infty)$$

Payda $x^2+1$ her zaman pozitif olduğu için ek bir kısıt getirmez.

> **Hocanın vurgusu:** Mantık dilinde "veya" ile bağlanan durumların çözümleri birleşime alınır.

> **Ek bilgi (derste anlatılmadı):** Aynı mantıkla "ve" (and) ile bağlanan koşulların çözümleri kesişime alınır. Örneğin bir fonksiyonda hem kök hem kesirli payda varsa iki koşulun ikisi de sağlanmalıdır, yani çözüm kümelerinin kesişimi alınır.

### 8.2 Örnek 9b: $f(x)=\dfrac{1}{\sqrt{|x|-x}}$

Bu soru aradan sonra çözülür. Kök sembolünün anlamlı olması için kök içi negatif olmamalıdır. Ama kök paydada olduğu için sıfır da olamaz. Bu yüzden koşul kesindir:

$$|x|-x>0$$

- $x\ge0$ ise $|x|=x$, $|x|-x=0$. Koşul sağlanmaz.
- $x<0$ ise $|x|=-x$, $|x|-x=-2x>0$. Koşul sağlanır.

$$D(f)=(-\infty,0)$$

Hoca bunun ardından bir sonraki ifadenin logaritmik fonksiyon içerdiğini, logaritmik fonksiyonların aşkın fonksiyonlar (transcendental functions) olduğunu ve daha sonra işleneceğini söyleyerek o soruyu geçer.

## 9. Ek Limit Alıştırmaları

### 9.1 $x\to\infty$ iken kök içeren bir limit

Bir soruda eşlenik yönteminden sonra pay ve paydada ortak çarpan alınır. Kök içinden $x^2$ dışarı alınınca $\sqrt{x^2}=|x|$ çıkar. $x\to\infty$ iken $x$ pozitif olduğu için $|x|=x$ yazılır. Kalan terimler $0$'a gider, sadeleşmeden sonra sonuç $1$ olur. <!-- BELİRSİZ: Sorunun ifadesi altyazıda döngü nedeniyle okunmuyor (01:03:06 - 01:04:19); yalnız yöntem ve sonuç (1) duyuluyor. -->

### 9.2 Örnek 10: $\lim_{x\to0}\dfrac{\sin x^2}{\sqrt{1+x^2}-1}$

Öğrencilerin çoğu hızla $2$ bulur. Çözüm eşlenikle çarpıp bölmektir:

$$\frac{\sin x^2}{\sqrt{1+x^2}-1}\cdot\frac{\sqrt{1+x^2}+1}{\sqrt{1+x^2}+1}=\frac{\sin x^2\left(\sqrt{1+x^2}+1\right)}{x^2}$$

$u=x^2$ denirse $x\to0$ iken $u\to0$ olur. Hoca bunun önemli olduğunu belirtir:

$$\lim_{x\to0}\frac{\sin x^2}{x^2}\cdot\left(\sqrt{1+x^2}+1\right)=1\cdot2=2$$

Hoca aynı soruyu L'Hôpital ile denemeyi önerir ve muhtemelen daha uzun süreceğini söyler. Bazı sorular L'Hôpital ile hızlı gelmez, bazıları tabii ki daha hızlı gelir.

### 9.3 Örnek 11: $x\to1^-$ ile dönüşüm

Bir trigonometrik limitte $x\to1^-$'dir. Bir $t$ dönüşümüyle $x\to1^-$ iken $t\to0^+$ olur. Toplam formülü kullanılır (ifadede "eksi $\cos\cos$ artı $\sin\sin$" vardır, yani $\cos(a+b)=\cos a\cos b-\sin a\sin b$'nin eksilisi). Temel formülü elde etmek için $\frac\pi2$ ile çarpılıp bölünür. $u=\frac\pi2t\to0$ olduğu için $\frac{\sin u}{u}\to1$ olur ve sonuç $1\cdot\frac\pi2=\frac\pi2$'dir. <!-- BELİRSİZ: Limitin tam ifadesi ve kullanılan t dönüşümü altyazıda okunmuyor (01:07:03 - 01:10:11). Bir öğrencinin "n" diye okuduğu sembolün π olduğu söyleniyor. -->

## 10. $0\cdot\infty$ Belirsizliği ve Sıkıştırma Teoremi

### 10.1 Örnek 12a: $\lim_{x\to\infty}x^2\sin\dfrac1x$

$x\to\infty$ iken $\frac1x\to0$, dolayısıyla $\sin\frac1x\to\sin0=0$; öte yandan $x^2\to\infty$. Bu bir $0\cdot\infty$ belirsizliğidir (indeterminate form).

> **Hocanın vurgusu:** Bu soruda sıkıştırma teoremi kullanılamaz. Geçmişte bazı öğrenciler yanlışlıkla kullanmış. Bu tür durumlarda önce ifadeyi düzenlemek ya da değişken değiştirmek gerekir.

Derste öğrenciler farklı cevaplar bulur (kimisi $0$, kimisi sonsuz). Hoca hatalarına bakmalarını ister.

**1. yol:** $x^2\sin\dfrac1x=x\cdot\dfrac{\sin\frac1x}{\frac1x}$. İkinci çarpan $1$'e, $x$ ise $\infty$'a gider. Sonuç $\infty$'dur.

**2. yol:** $t=\dfrac1x$ dönüşümü. $x\to\infty$ iken $t\to0^+$:

$$\lim_{t\to0^+}\frac{1}{t^2}\sin t=\lim_{t\to0^+}\frac1t\cdot\frac{\sin t}{t}=+\infty$$

Hoca burada da sinüsün davranışını hatırlatır: $\sin\frac1x$, $x\to\infty$ iken salınmaz, $0$'a yaklaşır. $\sin x$ ise $x\to\infty$ iken salınır ve bir değere yaklaşmaz. Sinyal dersi alacak öğrencilere bunun o derste de karşılarına çıkacağını söyler.

> **Ders sonrası not:** Hoca temel formülü bir yerde "$u\to0$ iken $\frac{\sin u}{u}$ sıfıra gider" diye söyleyip hemen düzeltiyor (01:12:05). Doğrusu: $\lim_{u\to0}\frac{\sin u}{u}=1$.

### 10.2 Örnek 12b: $\lim_{x\to\infty}\sqrt x\sin\dfrac1x$

Yine $x\to\infty$ iken $\sin\frac1x\to0$, $\sqrt x\to\infty$; $0\cdot\infty$ belirsizliği vardır ve sıkıştırma teoremi doğrudan kullanılamaz. $\frac{\sin u}{u}$ yapısını elde etmek için $\frac{1}{\sqrt x}$ ile çarpılıp bölünür; $\sqrt x=\dfrac{x}{\sqrt x}$ olduğundan:

$$\sqrt x\sin\frac1x=\frac{\sin\frac1x}{\frac1x}\cdot\frac{1}{\sqrt x}$$

$t=\frac1x\to0$ olduğu için ilk çarpan $1$'e, ikinci çarpan $0$'a gider:

$$\lim_{x\to\infty}\sqrt x\sin\frac1x=1\cdot0=0$$

### 10.3 Öğrenci sorusu: İki formül çelişiyor mu?

**Soru:** Daha önce $x\to\infty$ iken $\frac{\sin x}{x}$ kalıbının sıfır olduğunu söylemiştiniz. Ama burada $\frac{\sin\frac1x}{\frac1x}$ bire gidiyor. Bu çelişki değil mi?

**Cevap:** Durumlar farklıdır.

- $\lim_{x\to\infty}\dfrac{\sin x}{x}=0$: burada belirsizlik yoktur. $\sin x$ sınırlı bir değer, $x$ sınırsız bir değerdir. Sıkıştırma teoremine göre sonuç $0$'dır.
- $\lim_{x\to\infty}\dfrac{\sin\frac1x}{\frac1x}=1$: burada $\frac00$ belirsizliği vardır. $t=\frac1x$ dönüşümüyle $t\to0^+$ olur ve $\lim_{t\to0^+}\frac{\sin t}{t}=1$'dir.

> **Hocanın vurgusu:** Ezber yaparsanız hapı yutarsınız. Formülleri kalıp olarak zihninize yerleştirmeyin; kâğıt kalemle üzerinde düşünün. Ağzımdan ara sıra yanlış bir şey çıkabilir; formülleri benim ağzımdan çıkana göre değil, öğrettiğim düşünme tarzına göre zihninize kazıyın.

## 11. Eşlenik, Kök Dönüşümü ve L'Hôpital'e Uygun Sorular

Bu bölümde hoca birkaç soruyu hızlıca çözer. Birçoğunda eşlenik yönteminin işe yaradığını, ama bazılarında L'Hôpital kuralının daha rahat olacağını söyler. L'Hôpital kuralı 2-3 hafta sonra anlatılacaktır.

> **Hocanın vurgusu:** Sınav büyük ihtimalle test (çoktan seçmeli) olacak. Bu durumda birçok soruda L'Hôpital kuralı kullanılabilir.

### 11.1 $\cos^2x$ içeren bir limit

Hoca eşlenik yöntemini önerir; L'Hôpital ile denerse daha uzun süreceğini söyler. Eşlenikle çarpılıp bölününce $a^2-b^2$ çıkar. $x\to0$ iken bazı terimler $1$'e gider. $\cos^2x$, $1-\sin^2x$ olarak yazılır; toplam formülünden $\cos2x=1-2\sin^2x$ özdeşliği kullanılır. Ortak çarpan olarak $\sin^2x$ ve $x^2$ alınır, bir çarpan $\frac12$'ye gider. Hoca sonra bu soruyu L'Hôpital ile de çözdüğünü, L'Hôpital'in uzun sürse de daha rahat olabileceğini söyler. <!-- BELİRSİZ: Sorunun ifadesi ve son sonucu altyazıda okunmuyor (01:18:41 - 01:23:51). -->

### 11.2 $|\sin2x|$ çıkan bir limit, $x\to0^-$

Eşlenikle çarpılıp bölününce kök içinde $\sin^22x$ çıkar. Burada dikkat gerekir:

$$\sqrt{\sin^22x}=|\sin2x|$$

$x\to0^-$ iken $2x$ küçük negatif bir sayıdır, bu yüzden $\sin2x<0$'dır. Pozitif değer elde etmek için $|\sin2x|=-\sin2x$ yazılır. Bir çarpan $\frac{1}{\sqrt2}$'ye gider, bir de $-1$ katsayısı gelir. Sonuç $-\dfrac{1}{\sqrt2}$'dir. <!-- BELİRSİZ: Limitin tam ifadesi altyazıda yok (01:25:14 - 01:26:21); yalnız yöntem ve sonuç duyuluyor. -->

**Soru:** Neden eksi olduğunu açıklayabilir misiniz? **Cevap:** $x$ sıfıra soldan yaklaşırken $\sin2x$ negatiftir. Bu yüzden mutlak değer içindeki ifade $-\sin2x$ olarak çıkar.

Hemen ardından $x\to2^-$ olduğu sanılan bir soruda çarpanlara ayırma yapılır; hoca bu tür sorularda L'Hôpital'in daha avantajlı olduğunu söyler. <!-- BELİRSİZ: 01:27:09 - 01:27:46 arası döngü; soru ve sonuç okunmuyor. -->

### 11.3 Küp kök ve dördüncü kök: $x=t^{12}$ dönüşümü

Bir soruda $x\to1$ iken hem küp kök hem dördüncü kök vardır. Kökleri yok etmek için kök derecelerinin en küçük ortak katı alınır ve $x=t^{12}$ dönüşümü yapılır. $x\to1$ iken $t\to1$ olur. Kökler kalkınca polinom elde edilir ve çarpanlarına ayrılır; örneğin $t^4-1=(t^2-1)(t^2+1)$ biçiminde. <!-- BELİRSİZ: Limitin tam ifadesi ve sonucu altyazıda okunmuyor (01:28:07 - 01:28:49). -->

> **Hocanın vurgusu:** Bazen böyle dönüşümler işinizi kolaylaştırabilir. Kök derecelerinin en küçük ortak katını alıp $t^{12}$ gibi bir dönüşüm yaparsınız, iş basitleşir.

### 11.4 $1-\cos(x^2)$ içeren bir limit

Hoca payın $1-\cos(x^2)$ olduğuna, $\cos^2x$ olmadığına dikkat çeker. Eşlenik $1+\cos(x^2)$ ile çarpılıp bölünür. Pisagor özdeşliğinden pay $\sin^2(x^2)$ olur. Sadeleşmeden sonra geriye tek bir $\sin(x^2)$ kalır ("kare değil, dikkat"). $x\to0$ iken $x^2\to0$ olduğu için $\dfrac{\sin x^2}{x^2}\to1$, kalan kısım $\dfrac{1}{1+\cos x^2}\to\dfrac12$ olur. Sonuç $\dfrac12$'dir. Hoca bu sorunun L'Hôpital ile de çözülebileceğini söyler. <!-- BELİRSİZ: Limitin tam ifadesi altyazıda yok (01:30:26 - 01:31:45); anlatılan adımlar (1-cos x²)/(x² sin x²) ifadesiyle uyumlu ve bu ifade için sonuç 1/2. -->

### 11.5 Sıçrama süreksizliği: $x=1$

Bir başka soruda $x=1$'de limitin varlığı incelenir. $1-x$ çarpanlarına ayrılır ve bir eksi işareti çıkar; hoca bu eksinin unutulmamasını ister. Sadeleşmeden sonra $x\to1^-$ iken kalan terimde $1$ doğrudan yerine konur, $2$ ve eksi katsayıyla sonuç $-2$ olur. Sağ ve sol limitler sonlu ama farklı olduğu için $x=1$'de sıçrama süreksizliği vardır. <!-- BELİRSİZ: Fonksiyonun ifadesi ve sağ limitin değeri altyazıda okunmuyor (01:34:12 - 01:35:45). -->

### 11.6 İki ayrı kök içeren bir limit

Hoca çözmek isteyen bir öğrenciye söz verir; öğrenci soruyu L'Hôpital ile çözdüğünü, L'Hôpital'siz çözemediğini söyler. Hoca hazır çözümü gösterir: pay ve paydanın ikisinin de eşleniği alınmıştır, iş "bayağı sarpa sarmıştır". Payda iki ayrı kök ifadesi olduğu için hoca bu tür sorularda L'Hôpital'in daha uygun olduğunu söyler. <!-- BELİRSİZ: Sorunun ifadesi ve sonucu altyazıda okunmuyor (01:36:03 - 01:39:11). -->

### 11.7 $\sin(x^2-x)$ içeren bir limit, $x\to1$

L'Hôpital'siz çözümde ifade, $\frac{\sin u}{u}$ yapısı elde edilecek şekilde düzenlenir. $u=x^2-x$ seçilir; $x\to1$ iken $u\to0$ olur. Gereken argümanı elde etmek için $x$ ile çarpılıp bölünür. Sonunda $\frac{\sin u}{u}$ biçimli çarpanlar $1$'e gider. <!-- BELİRSİZ: Sorunun ifadesi ve sonucu altyazıda okunmuyor (01:39:33 - 01:40:43); 01:40:17'deki "as for this tree" sonucun 3 olduğu anlamına gelebilir, doğrulanamadı. -->

## 12. Limitin Sürekli Fonksiyonun İçine Alınması ve Her Yerde Süreklilik

### 12.1 Örnek 14: $\lim_{x\to0}\sin\left(\dfrac{\frac\pi2-\frac\pi2\cos^2x}{x^2}\right)$

$\sin$ fonksiyonu sürekli olduğu için limit $\sin$'in içine alınabilir:

$$\lim_{x\to0}\sin\left(\frac{\frac\pi2(1-\cos^2x)}{x^2}\right)=\sin\left(\lim_{x\to0}\frac{\frac\pi2\sin^2x}{x^2}\right)$$

Burada $1-\cos^2x=\sin^2x$ kullanıldı. $\dfrac{\sin^2x}{x^2}=\left(\dfrac{\sin x}{x}\right)^2$ olduğu için içteki limit $\frac\pi2\cdot1^2$'dir:

$$=\sin\left(\frac\pi2\right)=1$$

Hoca bunun basit bir soru olduğunu, çok uzun görünse de öyle olmadığını söyler.

> **Ek bilgi (derste anlatılmadı):** Kullanılan kural şudur: $g$, $L$ noktasında sürekli ve $\lim_{x\to a}h(x)=L$ ise $\lim_{x\to a}g(h(x))=g(L)$'dir. Bu yüzden sürekli bir dış fonksiyonun içindeki limit ayrı hesaplanabilir.

### 12.2 Örnek 15: $f(x)=x\sin\dfrac1x$ her yerde sürekli mi?

$$f(x)=\begin{cases}x\sin\dfrac1x, & x\ne0\\[2mm] 0, & x=0\end{cases}$$

Hoca bu sorunun daha önce çözüldüğünü hatırlatır ve dersi bununla bitirir.

**$x=0$'da.** Limit hesaplanır. $x\sin\dfrac1x=\dfrac{\sin\frac1x}{\frac1x}$ yazılır. $t=\dfrac1x$ dönüşümüyle $x\to0$ iken $t\to\pm\infty$ olur:

$$\lim_{x\to0}x\sin\frac1x=\lim_{t\to\pm\infty}\frac{\sin t}{t}=0$$

Son adım sıkıştırma teoremindendir: $\sin t$ sınırlı, $t$ sınırsızdır. Limit değeri $0$, fonksiyonun değeri $f(0)=0$'dır. Eşit oldukları için $f$, $x=0$'da süreklidir.

**$x\ne0$'da.** $f$, sürekli fonksiyonların çarpımı ve bileşkesidir; bu noktalarda da süreklidir.

Sonuç: $f$ her yerde süreklidir.

**Soru:** $\frac1x=t$ dönüşümünde $t$'nin sonsuza mı sıfıra mı gittiğine nasıl karar veriyoruz? **Cevap:** $x$'in nereye ve hangi yönden yaklaştığına bakılır. $x\to0^+$ ise $t\to+\infty$, $x\to0^-$ ise $t\to-\infty$ olur.

## Örnek Sorular

Bu derste video karesi kullanılmadı. Aşağıdaki sorular derste sözlü okunan ya da sorulan sorulardır. Çözümleri yukarıdaki bölümlerde ayrıntılı verildi; burada kısa sonuçlar var.

- **Soru 1** (derste sözlü, 00:01:18): $\lim_{x\to0}\dfrac{1-\cos x}{\sin|x|\cdot\tan x}$ var mıdır?
  - Çözüm (derste verildi): sağ limit $\frac12$, sol limit $-\frac12$. Limit yoktur.
- **Soru 2** (derste sözlü, 00:08:22): Bu yılın vize sorusu. Parçalı $f$ için $\lim_{x\to-2}f(x)$ ve $\lim_{x\to1}f(x)$'i inceleyin, süreksizlik türlerini belirleyin. <!-- BELİRSİZ: parçalı tanımın tamamı altyazıda yok. -->
  - Çözüm (derste verildi): $x=-2$'de sağ limit $+\infty$, sonsuz süreksizlik. $x=1$'de sol limit $\frac13$, sağ limit $-\frac12$, sıçrama süreksizliği.
- **Soru 3** (derste sözlü, 00:12:44): $\lim_{x\to\pi}\dfrac{\sin2x}{x^2-\pi x}$ değerini L'Hôpital'siz bulun.
  - Çözüm (derste verildi): $t=x-\pi$ dönüşümüyle $\dfrac{2}{\pi}$.
- **Soru 4** (derste sözlü, 00:17:19): $f(x)=\dfrac{3|x-2|}{x^2(4-x^2)}$'nin süreksizlik noktalarını bulun ve türlerini belirleyin.
  - Çözüm (derste verildi): $x=0$ ve $x=-2$ sonsuz süreksizlik, $x=2$ sıçrama süreksizliği (sağ $-\frac{3}{16}$, sol $\frac{3}{16}$).
- **Soru 5** (derste sözlü, 00:18:13): Test sınavı biçimi: "$x=0$ kaldırılabilir süreksizliktir; $x=2$ sonsuz süreksizliktir; $x=x_2$ sıçrama süreksizliğidir. Hangileri doğrudur?"
  - Bu bir soru kalıbıdır; Soru 4'teki gibi tek taraflı limitler hesaplanarak her ifade tek tek denetlenir.
- **Soru 6** (derste sözlü, öğrenci iddiası, 00:18:53): "Nokta tanım kümesinde değilse süreksizlik sonsuzdur" iddiası doğru mu?
  - Çözüm (derste verildi): Yanlış. Karşı örnek $f(x)=\frac{\sin x}{x}$: $0\notin D(f)$ ama limit $1$, kaldırılabilir süreksizlik.
- **Soru 7** (derste sözlü, 00:26:07): $f_{0,-1}$'in ($\alpha=0$, $\beta=-1$) $\mathbb{R}$ üzerinde sürekliliğini inceleyin.
  - Çözüm (derste verildi): $x\ne0$'da $\sin\frac1x$; $x=0$'da limit yok (salınım). $\mathbb{R}$ üzerinde sürekli değil.
- **Soru 8** (derste sözlü, 00:30:27): $\lim_{x\to\infty}\dfrac{x-\sqrt{1+x^2}}{x-\sqrt x}$.
  - Çözüm (derste verildi): ortak çarpan $x$; sonuç $0$.
- **Soru 9** (derste sözlü, 00:32:05): $f(x)=\dfrac{x^2}{1-\cos x}$'in $x=0$'daki süreksizlik türünü belirleyin ve $f$'yi sürekli bir fonksiyona dönüştürün.
  - Çözüm (derste verildi): limit $2$, kaldırılabilir süreksizlik; $g(0)=2$ ile sürekli genişleme.
- **Soru 10** (derste sözlü, 00:38:12): $f(x)=\dfrac{2|1-x|}{x^2(1-x)}$'in sürekliliğini ve süreksizlik türlerini inceleyin.
  - Çözüm (derste verildi): $x=0$ sonsuz, $x=1$ sıçrama (sol $2$, sağ $-2$); $f$, $\mathbb{R}\setminus\{0,1\}$'de sürekli, sürekli hâle getirilemez.
- **Soru 11** (derste sözlü, 00:47:04 ve 01:01:45): $f(x)=\dfrac{\sqrt{|2x+5|-3}}{x^2+1}$ ve $f(x)=\dfrac{1}{\sqrt{|x|-x}}$'in tanım kümelerini bulun.
  - Çözüm (derste verildi): $(-\infty,-4]\cup[-1,\infty)$ ve $(-\infty,0)$.
- **Soru 12** (derste sözlü, 01:04:34): $\lim_{x\to0}\dfrac{\sin x^2}{\sqrt{1+x^2}-1}$.
  - Çözüm (derste verildi): eşlenikle $2$.
- **Soru 13** (derste sözlü, 01:10:24 ve 01:17:22): $\lim_{x\to\infty}x^2\sin\frac1x$ ve $\lim_{x\to\infty}\sqrt x\sin\frac1x$.
  - Çözüm (derste verildi): $0\cdot\infty$ belirsizliği, sıkıştırma teoremi kullanılmaz. Sonuçlar $\infty$ ve $0$.
- **Soru 14** (derste sözlü, öğrenci sorusu, 01:14:46): $\lim_{x\to\infty}\frac{\sin x}{x}=0$ iken $\lim_{x\to\infty}\frac{\sin(1/x)}{1/x}=1$ olması çelişki mi?
  - Çözüm (derste verildi): çelişki yok; ilkinde belirsizlik yok (sınırlı/sınırsız), ikincisinde $\frac00$ belirsizliği var.
- **Soru 15** (derste sözlü, öğrenci sorusu, 01:26:29): $x\to0^-$ iken $\sqrt{\sin^22x}$ neden $-\sin2x$ olur?
  - Çözüm (derste verildi): $x\to0^-$ iken $\sin2x<0$, bu yüzden $|\sin2x|=-\sin2x$.
- **Soru 16** (derste sözlü, 01:41:06): $\lim_{x\to0}\sin\left(\dfrac{\frac\pi2-\frac\pi2\cos^2x}{x^2}\right)$.
  - Çözüm (derste verildi): limit içeri alınır; $\sin\frac\pi2=1$.
- **Soru 17** (derste sözlü, 01:42:25): $f(x)=x\sin\frac1x$ ($x\ne0$), $f(0)=0$ her yerde sürekli mi?
  - Çözüm (derste verildi): evet; $x=0$'da limit $0=f(0)$.
- **Soru 18** (derste sözlü, öğrenci sorusu, 01:44:39): $\frac1x=t$ dönüşümünde $t$'nin nereye gittiğine nasıl karar verilir?
  - Çözüm (derste verildi): $x\to0^+$ ise $t\to+\infty$, $x\to0^-$ ise $t\to-\infty$.

## Dersin Toparlaması

Bu derste yeni konu anlatılmadı; limit ve süreklilik konuları geçmiş yıl sınav ve uygulama sorularıyla pekiştirildi. Temel fikir, mutlak değer ya da parçalı tanım olan her yerde sağ ve sol limitleri ayrı ayrı incelemektir. Süreksizlik noktaları paydayı sıfır yapan noktalardan bulunur, türleri tek taraflı limitlerle belirlenir: biri sonsuzsa sonsuz süreksizlik, ikisi sonlu ve farklıysa sıçrama, limit var ama değerle uyuşmuyorsa kaldırılabilir süreksizlik. Yalnız kaldırılabilir süreksizlik giderilebilir. "Tanım kümesinde değilse sonsuz süreksizliktir" gibi genel bir iddia tek bir karşı örnekle çürütülür; ama örnekle doğrulama yapılamaz.

Limit tekniklerinde değişken değiştirme, eşlenikle çarpma, ortak çarpan alma, $t^{12}$ türü kök dönüşümü ve sürekli fonksiyonun içine limit alma kullanıldı. $0\cdot\infty$ belirsizliğinde sıkıştırma teoremi doğrudan uygulanmaz; önce ifade düzenlenir. Formüller kalıp olarak değil mantığıyla öğrenilmelidir. Hoca bazı soruların L'Hôpital kuralıyla daha rahat çözüleceğini, bu kuralın 2-3 hafta sonra anlatılacağını söyledi. Sonraki hafta türev (derivative) konusuna geçilecek; türevden sonra logaritmik, üstel ve ters trigonometrik fonksiyonlar, yani aşkın fonksiyonlar (transcendental functions) işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
