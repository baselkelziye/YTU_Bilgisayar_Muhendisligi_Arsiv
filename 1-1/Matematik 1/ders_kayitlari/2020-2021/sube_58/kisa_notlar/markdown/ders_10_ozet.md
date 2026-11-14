# Ders 10 Çalışma Özeti

> Tarih: 4 Kasım 2020 (Çarşamba). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var.

## Genel Konular

- Hiperbolik fonksiyonlar (hyperbolic functions): birim hiperbol ile birim çember benzerliği, tanımlar.
- Hiperbolik özdeşlikler, tek/çift olma, toplama formülleri.
- Hiperbolik fonksiyonların türevleri.
- Ters hiperbolik fonksiyonlar (inverse hyperbolic functions), logaritma cinsinden ifadeleri ve türevleri.
- L'Hôpital kuralı (L'Hôpital's rule): şartlar, doğrusallaştırma (linearization) ile ispat fikri, örnekler.
- Diğer belirsizlikler (indeterminate forms): $0\cdot\infty$, $\infty-\infty$.
- Üstel belirsizlikler: $1^\infty$, $0^0$, $\infty^0$ ve bunların logaritma ile tespiti.
- $e^a$ limiti ve genellemesi; $u^u \to 1$ kuralı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hiperbolik fonksiyonlarda yalnız $\cosh$ ve $\sinh$ tanımını bilin. Diğer her şey bunlardan çıkar.
- Öğrenciler sıkça $\cosh$ ile $\sinh$ tanımını karıştırıyor. Şüphedeyseniz $x^2 - y^2 = 1$ denklemine koyup kontrol edin.
- Sınavda hiperbolik fonksiyon soruları basit gelir.
- L'Hôpital yalnızca $\dfrac{0}{0}$ ve $\dfrac{\infty}{\infty}$ belirsizliklerinde uygulanır. Diğer belirsizlikleri önce bu iki forma çevirin.
- L'Hôpital, kesin sonuç bulunana kadar art arda uygulanabilir.
- Doğrudan L'Hôpital uygulamak yerine limiti parçalayın. Belli bir değere giden çarpanları (ör. $\cos^2 x \to 1$) ayırın. Hoca klasik sınav kâğıtlarında buna dikkat edilmediğini, işlemin çorbaya döndüğünü söyledi.
- Formül ezberlemeyin. Hoca yalnız eşlenik (conjugate) yöntemini ve L'Hôpital'ı biliyor; diğer formüller bunlardan türer.
- Limitte $1^\infty$ yakalarsanız cevap 1 **değildir**; bu bir belirsizliktir.
- $1^\infty$ tipinde soruları $e^a$ kalıbına benzeterek çözmek, genel yöntemden (logaritma + çok sayıda L'Hôpital) çoğu zaman daha kısadır.

## Kısa Tekrar Notları

- $\cosh x = \dfrac{e^x + e^{-x}}{2}$, $\sinh x = \dfrac{e^x - e^{-x}}{2}$.
- $\tanh x = \dfrac{\sinh x}{\cosh x}$, $\coth x = \dfrac{\cosh x}{\sinh x}$, $\operatorname{sech} x = \dfrac{1}{\cosh x}$, $\operatorname{csch} x = \dfrac{1}{\sinh x}$.
- $\cosh^2 x - \sinh^2 x = 1$; $1 - \tanh^2 x = \operatorname{sech}^2 x$.
- $\sinh 2x = 2\sinh x\cosh x$; $\cosh 2x = \cosh^2 x + \sinh^2 x$.
- Türevler: $(\sinh x)' = \cosh x$, $(\cosh x)' = \sinh x$, $(\tanh x)' = \operatorname{sech}^2 x$, $(\coth x)' = -\operatorname{csch}^2 x$, $(\operatorname{sech} x)' = -\operatorname{sech} x\tanh x$, $(\operatorname{csch} x)' = -\operatorname{csch} x\coth x$.
- $\operatorname{arcsinh} x = \ln\left(x + \sqrt{x^2+1}\right)$, $(\operatorname{arcsinh} u)' = \dfrac{u'}{\sqrt{u^2+1}}$.
- L'Hôpital: $\dfrac{0}{0}$ veya $\dfrac{\infty}{\infty}$ ise $\displaystyle\lim_{x\to a}\frac{f(x)}{g(x)} = \lim_{x\to a}\frac{f'(x)}{g'(x)}$.
- $x \to 0$ iken $\dfrac{\sin ax}{bx}$, $\dfrac{\arcsin ax}{bx}$ gibi limitler $\dfrac{a}{b}$'dir.
- $\displaystyle\lim_{x\to 0}(1 + ax)^{1/x} = e^a$, $\displaystyle\lim_{t\to\infty}\left(1 + \frac{a}{t}\right)^t = e^a$.
- $u(x) \to 0$ ise $\displaystyle\lim (1 + a\,u)^{1/u} = e^a$.
- $u(x) \to 0^+$ ise $\displaystyle\lim u^u = 1$.
- Belirsiz: $0^0$, $1^\infty$, $\infty^0$. Belirsiz olmayan: $0^\infty = 0$, $\infty^\infty = \infty$.

## Detaylı Açıklamalar

### Birim çember ve birim hiperbol

- Birim çember: $x^2 + y^2 = 1$. Parametrik denklem: $x = \cos t$, $y = \sin t$ ($t$ radyan).
- Yarıçapı $r$ olan çemberde $\theta$ radyanlık dilimin alanı radyan cinsinden yazılabilir.
- Birim hiperbol eğrisi (unit hyperbola): $x^2 - y^2 = 1$. Grafik birbirinden ayrık iki eğriden oluşur.
- Tek fark denklemdeki eksi işaretidir.
- Soru: Hiperbol için de çemberdeki gibi parametrik denklem bulunabilir mi? Cevap hiperbolik fonksiyonlardır:
  - $x = \cosh t = \dfrac{e^t + e^{-t}}{2}$, $y = \sinh t = \dfrac{e^t - e^{-t}}{2}$.
  - Bunlar $x^2 - y^2 = 1$ denklemini sağlar.
- Hoca: "cosh" gösterimi trigonometrik fonksiyonlarla benzerlik nedeniyle seçilmiştir; aslında bir tanımdır.

### Diğer hiperbolik fonksiyonlar

- $\tanh x = \dfrac{\sinh x}{\cosh x}$, $\coth x = \dfrac{\cosh x}{\sinh x}$.
- $\operatorname{sech} x = \dfrac{1}{\cosh x} = \dfrac{2}{e^x + e^{-x}}$, $\operatorname{csch} x = \dfrac{1}{\sinh x}$.

### Özdeşlikler

- $\cos^2 x + \sin^2 x = 1$ birim çemberden (Pisagor teoremi) gelir.
- $\cosh^2 x - \sinh^2 x = 1$ birim hiperbolden gelir. Tanımlar yerine konup açılınca 1 çıkar.
- Bölünce: $1 - \tanh^2 x = \operatorname{sech}^2 x$. Trigonometrideki karşılığı $\sec^2 x = 1 + \tan^2 x$. Fark yine işarettir.
- $\sinh 2x = 2\sinh x\cosh x$. Tanımdan: $\sinh 2x = \dfrac{e^{2x} - e^{-2x}}{2} = 2\cdot\dfrac{e^x - e^{-x}}{2}\cdot\dfrac{e^x + e^{-x}}{2}$.
- Tek/çift:
  - $\sinh(-x) = -\sinh x$ (tek fonksiyon, odd).
  - $\cosh(-x) = \cosh x$ (çift fonksiyon, even).
  - $\tanh x$ tek fonksiyondur (tek/çift oranı).
- Toplama formülleri:
  - $\cosh(a+b) = \cosh a\cosh b + \sinh a\sinh b$. Trigonometride $\cos(a+b) = \cos a\cos b - \sin a\sin b$; fark işarettir.
  - $\sinh(a+b) = \sinh a\cosh b + \cosh a\sinh b$. Trigonometrideki ile aynı yapıdadır.
  - $\cosh 2x = \cosh^2 x + \sinh^2 x$. Trigonometride $\cos 2x = \cos^2 x - \sin^2 x$.

### Hiperbolik fonksiyonların türevi

- Hoca önce tanımları ters yazarak sık yapılan hatayı gösterdi: ters yazılınca $x^2 - y^2 = 1$ sağlanmaz, çelişki çıkar.
- $(\cosh x)' = \dfrac{e^x - e^{-x}}{2} = \sinh x$.
- $(\sinh x)' = \dfrac{e^x + e^{-x}}{2} = \cosh x$.
- $(\tanh x)' = \operatorname{sech}^2 x = 1 - \tanh^2 x$.
- $(\coth x)' = -\operatorname{csch}^2 x$.
- $(\operatorname{sech} x)' = -\operatorname{sech} x\tanh x$ (bölüm kuralıyla).
- $(\operatorname{csch} x)' = -\operatorname{csch} x\coth x$ (bölüm kuralıyla).
- Trigonometrik türevlerle çok benzer. Ezberlemenize gerek yok.

### Ters hiperbolik fonksiyonlar

- Ters fonksiyon için bire bir ve örten olma şartı gerekir.
- $\cosh x$ bire bir değildir. $[0, \infty)$ parçası seçilir:
  - $\cosh: [0, \infty) \to [1, \infty)$ bire bir ve örten.
  - $\operatorname{arccosh}: [1, \infty) \to [0, \infty)$.
  - $y = \operatorname{arccosh} x \iff \cosh y = x$.
- Ters fonksiyonun grafiği, $f$'nin grafiğinin $y = x$ doğrusuna göre simetriğidir.
- $\sinh$ tüm reel sayılarda bire bir ve örtendir: $y = \operatorname{arcsinh} x \iff x = \sinh y$.

### $\operatorname{arcsinh}$'in logaritma ile ifadesi

- $x = \sinh y = \dfrac{e^y - e^{-y}}{2}$.
- Düzenleme: $e^y - 2x - e^{-y} = 0$. $e^y$ ile çarpınca $e^{2y} - 2x e^y - 1 = 0$.
- $e^y$ cinsinden ikinci derece denklem. Kökler: $e^y = x \pm \sqrt{x^2 + 1}$.
- $e^y > 0$ olduğu için pozitif kök seçilir: $e^y = x + \sqrt{x^2+1}$.
- Sonuç: $\operatorname{arcsinh} x = \ln\left(x + \sqrt{x^2 + 1}\right)$.
- Benzer şekilde (hoca notlarda gösterdi, ayrıntıya girmedi):
  - $\operatorname{arccosh} x = \ln\left(x + \sqrt{x^2 - 1}\right)$, $x \ge 1$. Hoca: sinh'tekinden tek farkı kök içindeki işaret.
  - $\operatorname{arctanh} x = \dfrac{1}{2}\ln\dfrac{1+x}{1-x}$, $|x| < 1$. Oran alınıp düzenlenerek gelir.
- Hoca: İkinci derece denklem çözümünü bilen bunu 30 saniyede çıkarır.

### Ters hiperbolik fonksiyonların türevi

- $y = \operatorname{arcsinh} x \iff x = \sinh y$.
- $x$'e göre türev: $1 = \cosh y\cdot\dfrac{dy}{dx}$ (zincir kuralı).
- $\dfrac{dy}{dx} = \dfrac{1}{\cosh y}$. $\cosh^2 y - \sinh^2 y = 1$ ve $\sinh y = x$ olduğundan $\cosh y = \sqrt{x^2 + 1}$.
- $\dfrac{d}{dx}\operatorname{arcsinh} x = \dfrac{1}{\sqrt{x^2+1}}$; zincir kuralıyla $\dfrac{u'}{\sqrt{u^2+1}}$.
- arccosh, arctanh, arcsech türevleri benzer şekilde bulunur. Hoca bunları öğrencilere bıraktı.

### L'Hôpital kuralı

**Teorem:**

- $f$ ve $g$, $a$'yı içeren açık bir $I$ aralığında türevlenebilir.
- $x \neq a$ iken $I$'da $g'(x) \neq 0$.
- $\displaystyle\lim_{x\to a} f(x) = 0$ ve $\displaystyle\lim_{x\to a} g(x) = 0$ (yani $\dfrac{0}{0}$ belirsizliği).
- Sonuç: $\displaystyle\lim_{x\to a}\frac{f(x)}{g(x)} = \lim_{x\to a}\frac{f'(x)}{g'(x)}$ (sağdaki limit varsa ya da $\pm\infty$ ise).
- Kural $x \to \pm\infty$, $x \to a^+$, $x \to a^-$ için de geçerlidir.
- Hoca'nın yorumu: Fonksiyonların oranının limiti, anlık değişim oranlarının (instantaneous rate of change) oranının limitine eşittir.

**Basit örnek:**

- $f(a) = g(a) = 0$, $f'(x) = 4$, $g'(x) = 2$ olan iki doğrusal fonksiyon.
- $\dfrac{f(x)}{g(x)} = \dfrac{4(x-a)}{2(x-a)} = 2$. L'Hôpital de aynı sonucu verir: $\dfrac{4}{2} = 2$.
- Doğrudan yerine koyunca $\dfrac{0}{0}$ çıkar.

**İspat fikri (doğrusallaştırma):**

- $a$ yakınında $f(x) \approx f(a) + f'(a)(x-a) = f'(a)(x-a)$, benzer şekilde $g(x) \approx g'(a)(x-a)$.
- $\dfrac{f(x)}{g(x)} \approx \dfrac{f'(a)(x-a)}{g'(a)(x-a)} = \dfrac{f'(a)}{g'(a)}$.
- Burada $\approx$ yaklaşık eşitliktir. Limit alınınca kural elde edilir.
- Doğrusallaştırma geçen hafta işlenmişti.

### Örnek 1: $\dfrac{0}{0}$ tipi

- (a) $\displaystyle\lim_{x\to 1}\frac{x^3 + x^2 - 2x}{x - 1}$:
  - $\dfrac{0}{0}$. L'Hôpital: $\displaystyle\lim_{x\to 1}\frac{3x^2 + 2x - 2}{1} = 3$.
- (b) $\displaystyle\lim_{x\to 0}\frac{\sqrt{9 + 3x} - 3}{x}$ (ifade altyazıda geçmiyor; büyük olasılıkla (ekrandan)):
  - $\dfrac{0}{0}$. L'Hôpital: $\displaystyle\lim_{x\to 0}\frac{\frac{3}{2\sqrt{9+3x}}}{1} = \frac{3}{6} = \frac{1}{2}$.

### Denk limitler

- $\displaystyle\lim_{x\to 0}\frac{\sin ax}{bx} = \frac{a}{b}$. L'Hôpital ile doğrudan görülür: $\dfrac{a\cos ax}{b} \to \dfrac{a}{b}$.
- $\displaystyle\lim_{x\to 0}\frac{\arcsin ax}{bx}$: L'Hôpital ile $\dfrac{a/\sqrt{1-a^2x^2}}{b} \to \dfrac{a}{b}$.
- Hoca dört denk limitten bahsetti; hepsi $\dfrac{a}{b}$ verir. Diğer ikisi altyazıda tam anlaşılmıyor (büyük olasılıkla $\tan$ ve $\arctan$ ile olanlar).

### $\dfrac{\infty}{\infty}$ tipi

- $x \to a$ iken $f \to \pm\infty$ ve $g \to \pm\infty$ ise kural yine geçerlidir.
- **Örnek 3 (a):** $\displaystyle\lim_{x\to\infty}\frac{4x^3 - 6x^2 + 1}{2x^3 - 10x + 3}$ (ifade altyazıda geçmiyor; büyük olasılıkla (ekrandan)):
  - L'Hôpital üç kez: $\dfrac{12x^2 - 12x}{6x^2 - 10} \to \dfrac{24x - 12}{12x} \to \dfrac{24}{12} = 2$.
- **Örnek 3 (b):** $\displaystyle\lim_{x\to\pi/2^-}\frac{1 + \tan x}{\sec x}$ (ifade altyazıda geçmiyor; büyük olasılıkla (ekrandan)):
  - $\dfrac{\infty}{\infty}$. L'Hôpital: $\dfrac{\sec^2 x}{\sec x\tan x} = \dfrac{\sec x}{\tan x} = \dfrac{1}{\sin x} \to 1$.
  - Bu kısım altyazıda döngü yüzünden anlaşılmıyor; sonuç kitaptaki standart çözümdür.

### $0\cdot\infty$ ve $\infty - \infty$

- Bu belirsizliklere L'Hôpital doğrudan uygulanmaz. Önce $\dfrac{0}{0}$ veya $\dfrac{\infty}{\infty}$ formuna çevrilir.
- **Örnek 4 ($0\cdot\infty$):** $\displaystyle\lim_{x\to\infty} x^2\sin\frac{1}{4x^2}$:
  - $x^2$'yi paydaya $\dfrac{1}{x^2}$ olarak taşı: $\dfrac{\sin\frac{1}{4x^2}}{\frac{1}{x^2}}$ → $\dfrac{0}{0}$.
  - L'Hôpital sonrası $\dfrac{1}{4}\cos\dfrac{1}{4x^2} \to \dfrac{1}{4}$.
- **Örnek 5 ($\infty - \infty$):** $\displaystyle\lim_{x\to\infty}\left(x - \sqrt{x^2 - 3x}\right)$ (ifade altyazıda geçmiyor; büyük olasılıkla (ekrandan)):
  - Eşlenik yöntemi de kullanılabilir. Burada $x$ ortak paranteze alınır: $x\left(1 - \sqrt{1 - 3/x}\right)$ ($x > 0$).
  - $\dfrac{1 - \sqrt{1 - 3/x}}{1/x}$ → $\dfrac{0}{0}$.
  - Değişken değiştirme $t = \dfrac{1}{x}$, $t \to 0^+$: $\dfrac{1 - \sqrt{1-3t}}{t}$.
  - L'Hôpital: $\dfrac{\frac{3}{2\sqrt{1-3t}}}{1} \to \dfrac{3}{2}$.
- Bir öğrenci $\infty - \infty$ için başka bir formül sordu. Hoca başka formül ezberlemediğini, yalnız eşlenik yöntemi ve L'Hôpital'ı kullandığını söyledi. Diğer formüller de aynı sonucu verir ama bu iki yöntemden türer.

### L'Hôpital hakkında notlar

- **Not 1:** Bir kez uygulayınca hâlâ belirsizlik varsa tekrar uygulanır. Kesin sonuç çıkana kadar devam edilir.
- **Not 2 (limiti parçalama):** $\displaystyle\lim_{x\to 0}\frac{x\cos^2 x}{\sin(x^2 - x)}$:
  - Doğrudan L'Hôpital: paydaki $x\cos^2 x$ teriminin türevi için çarpım kuralı gerekir, işlem kalabalıklaşır.
  - Daha iyi yol: $\cos^2 x \to 1$, belirsizlik yaratmaz; ayrı tutulur.
  - $\displaystyle\lim_{x\to 0}\frac{x}{\sin(x^2 - x)}$ → $\dfrac{0}{0}$. L'Hôpital: $\dfrac{1}{\cos(x^2 - x)\cdot(2x - 1)} \to \dfrac{1}{1\cdot(-1)} = -1$.
  - Cevap: $-1$.

### Üstel belirsizlikler

- Bir ifadenin belirsiz olup olmadığını anlamak için logaritma alınır (mantıksal olarak kesin değil ama pratik bir yöntem).
- $1^\infty$: $\ln 1^\infty = \infty\cdot\ln 1 = \infty\cdot 0$ → belirsiz.
- $0^0$ (taban $0^+$, yani sıfıra yakın pozitif sayı): $0\cdot\ln 0^+ = 0\cdot(-\infty)$ → belirsiz.
- $\infty^0$: $0\cdot\ln\infty = 0\cdot\infty$ → belirsiz.
- $0^\infty$: $\infty\cdot\ln 0^+ = \infty\cdot(-\infty) = -\infty$ → belirsiz değil, sonuç $e^{-\infty} = 0$.
- $\infty^\infty$: belirsiz değil, doğrudan $\infty$. Ör. $\displaystyle\lim_{x\to\infty} x^x = \infty$.
- $\displaystyle\lim_{x\to 0^+}\ln x = -\infty$ (grafikten).
- Hoca bir ara tahtada yanlış yazdığını fark edip düzeltti. Bu tabloyu ezberlemeye gerek yok; logaritma alarak karar verilebilir.

### $e^a$ limiti

- **Soru:** $\displaystyle\lim_{x\to 0}(1 + ax)^{1/x}$ ($1^\infty$ belirsizliği; cevap 1 değil).
- **Çözüm:**
  - $A = (1 + ax)^{1/x}$ olsun. $\ln A = \dfrac{\ln(1 + ax)}{x}$.
  - $x \to 0$: $\dfrac{0}{0}$. L'Hôpital: $\dfrac{a/(1 + ax)}{1} \to a$.
  - Bu $\ln A$'nın limitidir. Geri dönmek için üstel fonksiyon uygulanır: $\displaystyle\lim A = e^a$.
- Değişken değiştirme $t = \dfrac{1}{x}$: $\displaystyle\lim_{t\to\pm\infty}\left(1 + \frac{a}{t}\right)^t = e^a$.
- Hangisinin kullanılacağı sorudaki fonksiyonun yapısına bağlıdır.

**Genel kural:**

- $x \to a$ iken $u(x) \to 0$ ise $\displaystyle\lim_{x\to a}\big(1 + a\,u(x)\big)^{1/u(x)} = \lim_{u\to 0}(1 + au)^{1/u} = e^a$.

### Örnek 6: $\displaystyle\lim_{x\to 0}\left(\frac{\sin x}{x}\right)^{1/x}$

- $1^\infty$ belirsizliği.
- **Yöntem 1 (genel yöntem):** $A$'ya logaritma uygula. Hoca bunu ödev bıraktı, sonra dersin sonunda gösterdi (aşağıda).
- **Yöntem 2 (benzetme):**
  - $\dfrac{\sin x}{x} = 1 + \left(\dfrac{\sin x}{x} - 1\right)$. $u = \dfrac{\sin x}{x} - 1 \to 0$.
  - $\left(1 + u\right)^{1/x} = \left[(1 + u)^{1/u}\right]^{u/x}$.
  - Köşeli parantez $e$'ye gider.
  - Üs: $\dfrac{u}{x} = \dfrac{\sin x - x}{x^2}$ → $\dfrac{0}{0}$. L'Hôpital: $\dfrac{\cos x - 1}{2x} \to 0$.
  - Cevap: $e^0 = 1$.
- **Genel yöntemle karşılaştırma:**
  - $\ln A = \dfrac{\ln\frac{\sin x}{x}}{x}$. L'Hôpital: $\dfrac{\left(\frac{\sin x}{x}\right)'}{\frac{\sin x}{x}}$.
  - $\left(\dfrac{\sin x}{x}\right)' = \dfrac{x\cos x - \sin x}{x^2}$. Hoca burada önce $\sin x$ yerine $\sin x \cdot x$ yazdı; bir öğrenci hatayı düzeltti.
  - Bu yolda en az 3-4 kez L'Hôpital uygulamak gerekir. Benzetme yöntemi daha kısadır.
- Hoca: Bu, klasik yöntem ve L'Hôpital'ın birlikte kullanıldığı en zor soru tiplerinden biri. Test sınavında bu zorlukta soru gelmez.

### Örnek 7: $\displaystyle\lim_{x\to 0}(2 - \cos x)^{1/x^2}$

- $2 - \cos x = 1 + (1 - \cos x)$. $u = 1 - \cos x \to 0$.
- $\left[(1 + u)^{1/u}\right]^{\frac{1 - \cos x}{x^2}}$.
- Köşeli parantez $e$'ye gider.
- Üs: $\dfrac{1 - \cos x}{x^2}$ → L'Hôpital: $\dfrac{\sin x}{2x} \to \dfrac{1}{2}$.
- Cevap: $e^{1/2}$.
- Bir öğrenci $\dfrac{1}{x^2}$'nin nereye gittiğini sordu. Hoca: üste $\dfrac{1}{x^2}\cdot(1 - \cos x)$ olarak taşındı.
- Hoca: "Burada genel yöntemi kullanmak daha avantajlıydı, bir öncekinde genel yöntem avantajlı değildi" dedi ve önceki soruyu genel yöntemle denemeyi önerdi (altyazıdaki söz bu; hangi yöntemi kastettiği tam net değil).

### Örnek 8: $\displaystyle\lim_{x\to 0^+} x^x$

- $0^0$ belirsizliği (logaritma ile $0\cdot(-\infty)$).
- $x^x = e^{x\ln x}$.
- $\displaystyle\lim_{x\to 0^+} x\ln x = \lim\frac{\ln x}{1/x}$ → $\dfrac{\infty}{\infty}$.
- L'Hôpital: $\dfrac{1/x}{-1/x^2} = -x \to 0$.
- Cevap: $e^0 = 1$.

**Genelleme:**

- $x \to a$ iken $u(x) \to 0^+$ ise $\displaystyle\lim_{x\to a} u(x)^{u(x)} = \lim_{u\to 0^+} u^u = 1$.

### Örnek 9: $\displaystyle\lim_{x\to 0^+}\left(1 - \frac{\sin x}{x}\right)^x$ (cevapsız kaldı)

- $0^0$ belirsizliği. $u = 1 - \dfrac{\sin x}{x} \to 0^+$.
- Hoca $u^u$ kalıbına benzetti: $\left(u^u\right)^{x/u}$.
- Üs: $\dfrac{x}{u} = \dfrac{x^2}{x - \sin x}$. L'Hôpital: $\dfrac{2x}{1 - \cos x}$ → yine $\dfrac{0}{0}$ (bir öğrenci fark etti). Tekrar: $\dfrac{2}{\sin x}$ → belirsizlik devam etti.
- Hoca soruyu kafasından yazdığını, haftaya tekrar bakıp açıklayacağını söyledi. Ders cevapsız bitti.
- Doğru çözüm için "Ders sonrası notlar" kısmına bakın.

### Ders sonu

- "Haftaya görüşmek üzere, kendinize iyi bakın."

### Ders sonrası notlar

- **$1 - \tanh^2 x$:** Altyazıda "sin hyperbolic square x" geçiyor. Doğrusu $1 - \tanh^2 x = \operatorname{sech}^2 x$.
- **arcsinh türetimi:** Altyazıda "iki tarafın karesini al" deniyor. Doğru adım, denklemi $e^y$ ile çarpıp $e^y$ cinsinden ikinci derece denklem elde etmektir.
- **İkinci derece denklem:** Hoca diskriminantı önce kök içinde yazdı, sonra düzeltti: $\Delta = b^2 - 4ac$, kökler $\dfrac{-b \pm \sqrt{\Delta}}{2a}$.
- **Örnek 9'un doğru çözümü:**
  - $\dfrac{x}{u} = \dfrac{x^2}{x - \sin x}$. $x - \sin x \approx \dfrac{x^3}{6}$ olduğu için $\dfrac{x}{u} \approx \dfrac{6}{x} \to +\infty$.
  - Yani $(u^u)^{x/u}$ ifadesi $1^\infty$ olur. Benzetme yöntemi burada belirsizliği çözmez. Hocanın "1 üzeri 0" dediği yer hatalıdır.
  - Genel yöntem: $\ln L = \displaystyle\lim_{x\to 0^+} x\ln\left(1 - \frac{\sin x}{x}\right)$.
  - $1 - \dfrac{\sin x}{x} \approx \dfrac{x^2}{6}$ olduğundan $x\ln\dfrac{x^2}{6} = 2x\ln x - x\ln 6 \to 0$.
  - Cevap: $L = e^0 = 1$.
- Altyazıda birkaç yerde döngü var (ör. 00:13:11, 00:26:09, 00:43:04, 00:44:31). Bu kısımlar altyazıda anlaşılmıyor; içerik ekran görüntüsü ve çevredeki anlatımdan tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
