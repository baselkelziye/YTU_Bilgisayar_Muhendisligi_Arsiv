# Ders 5 Çalışma Özeti

## Genel Konular

- Türevin (derivative) anlamı: anlık değişim oranı (instantaneous rate of change) ve teğet doğrusunun eğimi.
- Ortalama değişim oranı (average rate of change) ile kesen doğru (secant line) arasındaki ilişki.
- Türevin iki denk tanımı: $x \to a$ biçimi ve $h \to 0$ biçimi.
- Leibniz gösterimi (Leibniz notation): $\dfrac{dy}{dx}$.
- Türevlenebilme ve süreklilik ilişkisi (differentiability and continuity).
- Tek taraflı türevler (one-sided derivatives) ve parçalı fonksiyonlarda türev.
- Türev kuralları: sabit, kuvvet, sabitle çarpım, çarpım (product rule) ve bölüm (quotient rule) kuralları.
- Trigonometrik fonksiyonların türevleri.
- Yatay teğet doğruları ve belirli eğimli teğetler.
- Zincir kuralı (chain rule) ve ağaç diyagramı (tree diagram).

## Hocanın Özellikle Vurguladığı Kısımlar

- Formül ezberlemeyin. Formülün nereden geldiğini, mantığını anlayın.
- Türev almak "sonsuz küçük bir dünyada çalışmak" demektir. $dy$ ve $dx$, yeterince küçük farklardır.
- Bazı sınav soruları doğrudan türev kurallarıyla çözülmez. Bu yüzden türevin tanımını (limitle) bilmek zorunludur.
- Süreklilik, türevlenebilme için **gerekli** koşuldur ama **yeterli** değildir.
- Parçalı fonksiyonda kısa yolu (parçaların türevini almak) kullanmadan önce sürekliliği mutlaka kontrol edin. Süreklilik yoksa türev de yoktur.
- Teğet doğrusunu asimptotla karıştırmayın.
- Zincir kuralını ağaç diyagramıyla sistemli kurun. Çok değişkenli fonksiyonlarda bu yöntem gerekecek.
- Sınavda bu kadar karmaşık zincir kuralı sorusu gelmez. Örnekler alıştırma içindir.
- Vize sınavı genelde 7. veya 8. haftada yapılır. O haftadan önce hazır olun.

## Kısa Tekrar Notları

- Ortalama değişim oranı: $\dfrac{f(x)-f(a)}{x-a}$. Bu, kesen doğrunun eğimidir.
- Türevin tanımı:
  - $f'(a) = \displaystyle\lim_{x \to a} \frac{f(x)-f(a)}{x-a}$
  - $f'(a) = \displaystyle\lim_{h \to 0} \frac{f(a+h)-f(a)}{h}$ (değişken değiştirme: $h = x-a$)
- $a$ noktasındaki teğet doğrusu: $y - f(a) = f'(a)(x-a)$.
- Denk gösterimler: $f'(a)$, $\dfrac{df}{dx}\Big|_{x=a}$, $\dfrac{dy}{dx}\Big|_{x=a}$.
- Türevlenebilir $\Rightarrow$ sürekli. Tersi doğru değil. Denk ifade: sürekli değil $\Rightarrow$ türevlenemez.
- $f'(a)$ vardır $\iff$ $f'_+(a)$ ve $f'_-(a)$ vardır ve eşittir.
- Türevin olmadığı yerler: kırılma noktası (köşe), dikey teğet, süreksizlik.
- Kurallar:
  - $(c)' = 0$
  - $(x^n)' = n x^{n-1}$
  - $(cf)' = c f'$
  - $(fg)' = f'g + fg'$
  - $\left(\dfrac{f}{g}\right)' = \dfrac{f'g - fg'}{g^2}$
- Trigonometrik türevler:
  - $(\sin x)' = \cos x$, $(\cos x)' = -\sin x$
  - $(\tan x)' = \sec^2 x = 1 + \tan^2 x = \dfrac{1}{\cos^2 x}$
  - $(\cot x)' = -\csc^2 x$
  - $(\sec x)' = \sec x \tan x$, $(\csc x)' = -\csc x \cot x$
- Zincir kuralı: $\dfrac{dy}{dx} = \dfrac{dy}{du} \cdot \dfrac{du}{dx}$.

## Detaylı Açıklamalar

### Türevin anlamı ve kesen doğrudan teğete geçiş

- $P(a, f(a))$ ve $Q(x, f(x))$ noktalarını birleştiren doğru kesen doğrudur.
- Dik üçgenin kenarları $x-a$ ve $f(x)-f(a)$ olur. Kesenin eğimi $\dfrac{f(x)-f(a)}{x-a}$ olur.
- Bu oran, $f$'nin $[a, x]$ aralığındaki ortalama değişim oranıdır.
- $x \to a$ olurken kesen doğrular teğet doğrusuna yaklaşır. Limit, teğetin eğimini verir.
- Hoca burada "nokta" üzerine bir yorum yapıyor:
  - Noktanın matematiksel tanımı yoktur. "Kalemin kâğıtta bıraktığı iz" bir metafordur.
  - Bu bir avantajdır: noktayı yeterince küçük bir üçgen, kare ya da küre gibi düşünebiliriz.
  - Limitte üçgenler $P$ noktasına "sıkışır". $P$ noktasına yakınlaşınca (zoom) yeterince küçük bir üçgen görürüz.
- $\Delta y$ ve $\Delta x$ limit alınmamış farklardır. Limitte bunlar $dy$ ve $dx$ olur: yeterince küçük farklar.

### Örnek 1: Teğetin eğimi ve denklemi

- Soru: $f(x) = -16x^2 + 96x$ için $(1, 80)$ noktasındaki teğet.
- a) Eğim:
  - $m = \displaystyle\lim_{x \to 1} \frac{-16x^2 + 96x - 80}{x-1}$
  - $= \displaystyle\lim_{x \to 1} \frac{-16(x-5)(x-1)}{x-1} = -16 \cdot (1-5) = 64$
- b) Teğet denklemi: $y - 80 = 64(x-1)$, yani $y = 64x + 16$.
- Not: Bu örneğin sözlü anlatımı altyazıda döngüye girmiş. Çözüm, ekrandaki ders notundan alındı.

### Denk tanım ($h$ biçimi)

- $h = x - a$ dönüşümü yapılır. $x \to a$ iken $h \to 0$ olur.
- Sol tarafta $a$ limit değişkenine göre sabittir. Sağ tarafta limit değişkeni $h$'dir.
- Hangi tanımın daha kolay olduğu fonksiyonun yapısına bağlıdır.
- Trigonometrik fonksiyonlarda genelde $h$ biçimi daha avantajlıdır.

### Örnek 2: $f(x) = \sqrt{x^2+1}$ için $f'(1)$

- $f'(1) = \displaystyle\lim_{x \to 1} \frac{\sqrt{x^2+1} - \sqrt{2}}{x-1}$
- Eşlenikle çarpılır (conjugate method):
  - $= \displaystyle\lim_{x \to 1} \frac{x^2 - 1}{(x-1)(\sqrt{x^2+1} + \sqrt{2})} = \lim_{x \to 1} \frac{x+1}{\sqrt{x^2+1}+\sqrt{2}} = \frac{2}{2\sqrt{2}} = \frac{1}{\sqrt{2}}$
- Hoca burada $x \to a$ biçimini daha kolay buluyor. $h$ biçiminde önce $(1+h)^2$ açılmalı. Bu, bilgisayar için de ek işlem demektir.
- Bir öğrenci "türev kurallarıyla doğrudan alsam olmaz mı?" diye soruyor.
  - Hoca: Bu örnekte olur. Ama sınavda doğrudan türev alınamayan sorular var. Bu yüzden tanımı öğrenmek zorunludur.

### Örnek 3: Diğer tanımla türev fonksiyonu

- $f(x) = \sqrt{2x+5}$:
  - $\displaystyle\lim_{x \to a} \frac{\sqrt{2x+5} - \sqrt{2a+5}}{x-a} = \lim_{x \to a} \frac{2}{\sqrt{2x+5}+\sqrt{2a+5}} = \frac{1}{\sqrt{2a+5}}$
  - $a$ keyfi ama sabit. Sonunda $a$ yerine $x$ yazılır: $f'(x) = \dfrac{1}{\sqrt{2x+5}}$.
- $f(x) = x^3$:
  - $\dfrac{x^3 - a^3}{x-a} = x^2 + ax + a^2 \to 3a^2$. Sonuç: $f'(x) = 3x^2$.
  - $h$ biçiminde $(x+h)^3$ açılmak zorunda kalır. Hoca bu yüzden $x \to a$ biçimini daha hızlı buluyor.
- $f(x) = \sqrt{x^3 + x}$:
  - Eşlenikle çarpılır. Payda $x^3 - a^3 + x - a = (x-a)(x^2 + ax + a^2 + 1)$ olur.
  - Sonuç: $f'(x) = \dfrac{1 + 3x^2}{2\sqrt{x^3 + x}}$.
- Bir başka örnekte $h$ biçimiyle teğetin eğimi $-\dfrac{1}{9}$ bulunuyor. Fonksiyonun kuralı altyazıda anlaşılmıyor.

### Türevlenebilme ve süreklilik

- **Teorem:** $f$, $a$ noktasında türevlenebilir ise $a$ noktasında süreklidir.
- Mantık dili:
  - $P$: $f$, $a$'da türevlenebilir. $Q$: $f$, $a$'da sürekli.
  - $P \Rightarrow Q$ doğrudur. $Q \Rightarrow P$ her zaman doğru değildir.
  - Denk ifade (karşıt ters, contrapositive): $\neg Q \Rightarrow \neg P$. Sürekli değilse türevlenemez.
  - Örnek: "Yağmur yağıyorsa hava bulutludur" doğrudur. "Hava bulutluysa yağmur yağar" doğru değildir.
- $Q$ gerekli koşuldur, yeterli koşul değildir.
- Süreksiz bir noktada tek bir teğet çizilemez. O noktadan sonsuz sayıda doğru geçer.

### Örnek 4: $f(x) = |x|$, $x = 0$

- Parçalı fonksiyonlarda türevin tanımını kullanmak gerekir.
- Sağdan: $\displaystyle\lim_{x \to 0^+} \frac{x - 0}{x - 0} = 1$
- Soldan: $\displaystyle\lim_{x \to 0^-} \frac{-x - 0}{x - 0} = -1$
- Sağ ve sol türev farklı. $f'(0)$ yok.
- $f$ ise $0$'da süreklidir. Bu, "sürekli ama türevlenemez" örneğidir.
- Grafikte $0$'da kırılma (köşe) vardır. Tek bir teğet çizilemez.
- Dikey teğetli durumlar: teğetin eğimi sonsuzdur. Bu noktalarda da türev yoktur.

### Tek taraflı türevler

- $f'_+(a) = \displaystyle\lim_{x \to a^+} \frac{f(x)-f(a)}{x-a}$ ve $f'_-(a) = \displaystyle\lim_{x \to a^-} \frac{f(x)-f(a)}{x-a}$.
- $f'(a)$ vardır $\iff$ ikisi de vardır ve eşittir. Bu gerek ve yeter koşuldur.

### Örnek 5: $f(x) = |x - 2|$, $x = 2$

- $x \ge 2$ için $f(x) = x - 2$, $x < 2$ için $f(x) = 2 - x$.
- Grafik, $y = x-2$ doğrusunun $x$ ekseninin altındaki kısmının yukarı katlanmasıyla elde edilir.
- $f'_+(2) = 1$, $f'_-(2) = -1$. Farklı oldukları için $f'(2)$ yok.
- Bir öğrenci kırılma noktasını nasıl bulacağını soruyor. Hoca: grafiğe bakarak değil, cebirsel olarak, türevin tanımıyla gösterilir.

### Parçalı fonksiyonlar için kısa yol (genel kural)

- Koşullar:
  - $f$, $a$ noktasında süreklidir.
  - Her parça her yerde türevlenebilirdir (ör. polinomlar, $\sin$, $\cos$).
- Bu durumda türevin tanımına gerek yoktur. Parçaların türevi alınıp $a$'daki değerleri karşılaştırılır.
- Örnek 6: $f(x) = 4 - x^2$ ($x \le 1$), $f(x) = 2x + 1$ ($x > 1$).
  - $x = 1$'de iki taraf da $3$'e gider ve $f(1) = 3$. Fonksiyon sürekli.
  - $(4-x^2)' = -2x \big|_{x=1} = -2$, $(2x+1)' = 2$.
  - $-2 \ne 2$ olduğu için $f'(1)$ yok.

### Örnek 7: Yanlış çözüm tuzağı (doğru/yanlış sorusu)

- $f(x) = 3x - 6$ ($x \ge 1$), $f(x) = 3x + 5$ ($x < 1$). İfade: "$f$, $x = 1$'de türevlenebilirdir."
- Yanlış çözüm: $(3x-6)' = 3$, $(3x+5)' = 3$. Eşit oldukları için "türevlenebilir" demek.
- Bu yanlıştır. $x=1$'de sağdan değer $-3$, soldan $8$'e gidilir. Fonksiyon sürekli değil.
- Süreklilik gerekli koşul olduğu için $f'(1)$ yoktur. İfade **yanlıştır**.

### Örnek 8: Bilinmeyen sabit

- $f(x) = 2x^2$ ($x \le 1$), $f(x) = ax - 2$ ($x > 1$). $f'(1)$ hangi $a$ için vardır?
- Önce süreklilik: $a - 2 = 2$, yani $a = 4$.
- Sonra türevler: $(2x^2)' = 4x \big|_{x=1} = 4$, $(4x - 2)' = 4$. Eşit.
- Sonuç: $a = 4$ için $f'(1)$ vardır.
- Hoca uyarıyor: Basit görünen sorular düşürücü olabilir. Önce bütün koşulları kontrol edin.

### Türev kuralları

- Sabit kural: Sabit fonksiyonun değişim oranı $0$'dır.
- Kuvvet kuralı: Önce $n$ pozitif tam sayı kabul edilir. $x^n - a^n$ çarpanlarına ayrılarak $(x^n)' = n x^{n-1}$ bulunur.
- Sabitle çarpım: Sabit limitin dışına alınır: $(cf)' = c f'$.
- Çarpım kuralı: $(fg)' = f'g + fg'$. Kanıttan sorumlu değilsiniz.
- Bölüm kuralı: $\left(\dfrac{f}{g}\right)' = \dfrac{f'g - fg'}{g^2}$.
- Kuvvet kuralı bölüm kuralıyla negatif tam sayılara genişletilir. Gerçel üsler ileride görülecek.

### Trigonometrik türevler

- $(\sin x)'$ için $h$ biçimi kullanılır:
  - $\dfrac{\sin(x+h) - \sin x}{h} = \sin x \cdot \dfrac{\cos h - 1}{h} + \cos x \cdot \dfrac{\sin h}{h}$
  - $h \to 0$ iken $\dfrac{\cos h - 1}{h} \to 0$ ve $\dfrac{\sin h}{h} \to 1$. Sonuç: $(\sin x)' = \cos x$.
- Benzer şekilde $(\cos x)' = -\sin x$.
- $(\tan x)'$ bölüm kuralıyla bulunur: $\dfrac{\cos^2 x + \sin^2 x}{\cos^2 x} = \sec^2 x$.
- Ezber kolaylığı: $\sin$–$\cos$, $\tan$–$\cot$ ve $\sec$–$\csc$ birbirinin tümleridir (cofunction). Tümlere geçerken eksi işareti eklenir.
- Hoca: Ezberlemek zorunda değilsiniz. $\sin$, $\cos$ türevleri ve bölüm kuralıyla 5–10 saniyede çıkarırsınız.
- Örnek 9: $y = x \cos x \sin x$. Gruplanıp çarpım kuralı uygulanır:
  - $y' = \cos x \sin x + x(-\sin^2 x + \cos^2 x)$.

### Yatay teğetler ve belirli eğimli teğetler

- Örnek 10: $g(x) = x - \sin x$.
  - $g'(x) = 1 - \cos x$.
  - Yatay teğet: $g'(x) = 0 \Rightarrow \cos x = 1 \Rightarrow x = 2k\pi$. Sonsuz sayıda nokta vardır.
  - Eğimin 1 olduğu yerler: $1 - \cos x = 1 \Rightarrow \cos x = 0 \Rightarrow x = \dfrac{\pi}{2} + k\pi$.
- Bir öğrenci cevabın nasıl yazılacağını soruyor. Hoca: Şıklarda "sonsuz sayıda $x$ değeri vardır" gibi bir ifade olur. Yorumlamayı öğrenin.
- Bir öğrenci teğetin asimptot olup olmadığını soruyor. Hoca: Hayır, ikisini karıştırmayın.
  - Asimptot, fonksiyonun sonsuzda bir doğru gibi davranmasıdır.
  - Dikey asimptotun olduğu $x = a$ noktasında fonksiyon sürekli değildir. Bu yüzden orada türev yoktur.

### Zincir kuralı

- Ağaç diyagramı: $y$, $u$'ya bağlı; $u$, $x$'e bağlı.
  - $u$, $y$'ye göre bağımsız değişkendir ama $x$'e göre bağımlıdır.
  - $x$, hem $u$'ya hem $y$'ye göre bağımsızdır.
- $\dfrac{dy}{dx} = \dfrac{dy}{du} \cdot \dfrac{du}{dx}$. $du$'lar sadeleşiyormuş gibi düşünülebilir.
- Genel hâli: $\big(f(u(x))\big)' = f'(u) \cdot u'(x)$.
- Örnek 11: $y = (5x+4)^3$. $u = 5x + 4$ ise $y = u^3$.
  - $\dfrac{dy}{dx} = 3u^2 \cdot 5 = 15(5x+4)^2$.
- Örnek 12: $y = \sin^3(x^2)$. $v = \sin u$, $u = x^2$, $y = v^3$.
  - $\dfrac{dy}{dx} = \dfrac{dy}{dv} \cdot \dfrac{dv}{du} \cdot \dfrac{du}{dx} = 3\sin^2(x^2) \cdot \cos(x^2) \cdot 2x$.
- Örnek 13: $y = \tan^2(x^3 + \sin^2 x)$. $y = v^2$, $v = \tan u$, $u = x^3 + \sin^2 x$.
  - $y' = 2\tan(x^3 + \sin^2 x) \cdot \sec^2(x^3 + \sin^2 x) \cdot (3x^2 + 2\sin x \cos x)$.
  - $(\sin^2 x)' = 2\sin x \cos x$ de zincir kuralıyla bulunur ($h = u^2$, $u = \sin x$).
- Örnek 14 (alıştırma): $y = \sec^3\big((x^2+2x)^3 \sin x\big)$ gibi uzun bir ifade.
  - Önce dış kuvvet, sonra $\sec$, sonra iç çarpım türevlenir.
  - $(\sec u)' = \sec u \tan u \cdot u'$.
  - İç çarpım: $\big((x^2+2x)^3 \sin x\big)' = 3(x^2+2x)^2(2x+2)\sin x + (x^2+2x)^3 \cos x$.
  - Yazılı ifadenin bir kısmı altyazıda tam anlaşılmıyor. Yöntem budur.
- Zincir kuralıyla genel formüller:
  - $(\sin u)' = \cos u \cdot u'$, $(\cos u)' = -\sin u \cdot u'$
  - $(\tan u)' = \sec^2 u \cdot u'$, $(\sec u)' = \sec u \tan u \cdot u'$
  - $(\cot u)' = -\csc^2 u \cdot u'$, $(\csc u)' = -\csc u \cot u \cdot u'$
- Örnek 15: $y = \sec(x^2 + \sin x)$. $y' = \sec(x^2+\sin x)\tan(x^2+\sin x)(2x + \cos x)$.
- Örnek 16: $y = \tan(x^3 + \cos x)$. $y' = \sec^2(x^3 + \cos x)(3x^2 - \sin x)$.

### Ders sonrası notlar

- Hoca İngilizcede "derivation" diyor. Doğru terim "derivative" (türev) ve "differentiation" (türev alma).
- Altyazıdaki "likeness notation" Leibniz gösterimidir.
- Hoca $\sin/\cos$ gibi çiftlere "conjugate" diyor. Doğru terim "cofunction" (tümler fonksiyon).
- Hoca $(\cot x)'$ için bir yerde "$-\cos^2 x$" der gibi söylüyor. Doğrusu $(\cot x)' = -\csc^2 x$.
- Bölüm kuralı sözlü anlatımda karışık söyleniyor. Doğrusu $\left(\dfrac{f}{g}\right)' = \dfrac{f'g - fg'}{g^2}$.
- Hoca, yatay asimptot varsa sonsuzda türevin $0$'a gittiğini söylüyor. Bu her zaman doğru değil. Örnek: $f(x) = \dfrac{\sin(x^2)}{x}$ sonsuzda $0$'a gider, ama $f'(x)$ $0$'a gitmez.
- "Türev yoksa ya kırılma ya dikey teğet vardır" sözü eksiktir. Süreksizlikte ve salınımlı fonksiyonlarda (ör. $x\sin(1/x)$, $x = 0$) da türev yoktur.
- Bir öğrenci 7. örnekte $3x - 6$'nın $x=1$'deki değerinin $-3$ olduğunu söylüyor. Bu doğrudur ve fonksiyonun süreksiz olduğunu gösterir.
- Ders notlarının (slaytların) hocanın Avesis sayfasında olduğu söyleniyor. Öğrenciler buradan indirmeli.
- Kaydın başındaki "x−1" örneğinin ve birkaç geçişin sözlü anlatımı altyazıda döngüye girmiş. Bu kısımlar altyazıda anlaşılmıyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
