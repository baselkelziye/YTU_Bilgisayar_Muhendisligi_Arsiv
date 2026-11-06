# Ders 2 Çalışma Özeti

## Genel Konular

- Sıkıştırma teoremi (Sandwich Theorem) ile limit alıştırmaları.
- Parçalı fonksiyonda limitin var olması için sabit bulma.
- Eşlenik yöntemi (conjugate method) ile limit.
- Sonsuz limitler (infinite limits) ve düşey asimptot (vertical asymptote).
- Sonsuzda limit ve yatay asimptot (horizontal asymptote).
- Polinomların ve rasyonel fonksiyonların sonsuzdaki davranışı.
- Limitin kesin tanımı (precise definition, $\varepsilon$-$\delta$).
- Bir noktada süreklilik (continuity at a point), süreksizlik türleri.
- Süreklilik kuralları, bileşkenin sürekliliği.
- Bir aralıkta süreklilik, soldan ve sağdan süreklilik.

## Hocanın Özellikle Vurguladığı Kısımlar

- L'Hôpital kuralını şimdilik kullanmayın. Türev henüz işlenmedi. Bazı sorularda L'Hôpital işe yaramaz.
- Mutlak değerli bir eşitsizlik veya sınırlı (salınım yapan) bir fonksiyon görürseniz büyük olasılıkla sıkıştırma teoremi gerekir.
- $\theta\to\infty$ iken $\sin\theta$, $\cos\theta$ $-1$ ile $1$ arasında salınır. Böyle limitlerde L'Hôpital değil sıkıştırma teoremi kullanın.
- Üniversitede açılar derece değil radyan olarak düşünülür. $\theta$ bir gerçel sayıdır.
- Düşey asimptot için sonlu bir noktaya yaklaşırken limitin $\pm\infty$ olması gerekir. Sonlu bir değer çıkarsa düşey asimptot yoktur.
- Yatay asimptot için $x\to\pm\infty$ iken limitin sonlu bir değer olması gerekir.
- Test sınavlarında "verilen fonksiyon için hangisi söylenebilir?" türünden asimptot soruları gelebilir.
- $\varepsilon$-$\delta$ tanımı test sınavında büyük olasılıkla çıkmaz. Müfredatta olduğu için mantığı anlatılıyor.
- Süreklilik sayesinde limit, sürekli bir fonksiyonun içine alınabilir. Bu çok önemli.
- Ödev soruları basit pratik sorularıdır. Hoca cevaplarını vermiyor. Sınava yönelik sorular derste çözülecek.

## Kısa Tekrar Notları

- **Sınırlı çarpı sıfıra giden:** $\lim_{x\to c}f(x)=0$ ve $|g(x)|\le K$ ise $\lim_{x\to c}f(x)g(x)=0$.
- **Sonsuz limit:** $\lim_{x\to a^\pm}f(x)=\pm\infty$ ise $x=a$ düşey asimptottur.
- **Yatay asimptot:** $\lim_{x\to\pm\infty}f(x)=L$ (sonlu) ise $y=L$ yatay asimptottur.
- **Sabit / sınırsız:** $x\to\pm\infty$ iken $\frac{c}{x^n}\to 0$ ($n>0$).
- **Polinomun sonsuzdaki davranışı:** baş terime ve onun katsayısının işaretine bakılır.
- **$x^n$:** $n$ çift pozitif ise $x\to\pm\infty$ iken $+\infty$. $n$ tek pozitif ise $x\to-\infty$ iken $-\infty$.
- **$\varepsilon$-$\delta$ tanımı:** Her $\varepsilon>0$ için öyle bir $\delta>0$ vardır ki $0<|x-a|<\delta$ iken $|f(x)-L|<\varepsilon$ olur.
- **$a$'da süreklilik:** (1) $f(a)$ tanımlı, (2) $\lim_{x\to a}f(x)$ var, (3) $\lim_{x\to a}f(x)=f(a)$.
- **Sağdan süreklilik:** $\lim_{x\to a^+}f(x)=f(a)$. **Soldan süreklilik:** $\lim_{x\to a^-}f(x)=f(a)$.
- **$[a,b]$'de süreklilik:** iç noktalarda sürekli, $a$'da sağdan, $b$'de soldan sürekli.
- **Bileşke:** $g$, $a$'da ve $f$, $g(a)$'da sürekliyse $\lim_{x\to a}f(g(x))=f\left(\lim_{x\to a}g(x)\right)$.

## Detaylı Açıklamalar

### Sıkıştırma Teoremi Alıştırması

- **Örnek 1:** $\lim_{x\to c}f(x)=0$ ve bir $K$ sabiti için $|g(x)|\le K$ olsun. $\lim_{x\to c}f(x)g(x)=0$ olduğunu gösterin.
  - $|g(x)|\le K$, $g$'nin sınırlı olduğu anlamına gelir. Grafiği $y=K$ ile $y=-K$ arasında salınır.
  - Mutlak değer özelliğiyle:

$$0\le|f(x)g(x)|=|f(x)|\,|g(x)|\le K|f(x)|$$

  - Buradan $-K|f(x)|\le f(x)g(x)\le K|f(x)|$.
  - $x\to c$ iken $f(x)\to0$, dolayısıyla $|f(x)|\to0$. Alt ve üst sınır 0'a gider.
  - Sıkıştırma teoremiyle $\lim_{x\to c}f(x)g(x)=0$.
  - Hoca slayttaki "$x\to0$" yazımını "$x\to c$" olarak düzeltiyor.

### Parçalı Fonksiyonda Sabit Bulma

- **Örnek 2:**

$$g(x)=\begin{cases}x^2-5x, & x\le-1\\ ax^3-7, & x>-1\end{cases}$$

  - $g$'nin $x=-1$'de limiti olması için $a$ ne olmalı?
  - Sol limit (birinci kural): $\lim_{x\to-1^-}(x^2-5x)=1+5=6$.
  - Sağ limit (ikinci kural): $\lim_{x\to-1^+}(ax^3-7)=-a-7$.
  - Belirsizlik yok, doğrudan yerine konur.
  - Limit var olması için sol limit = sağ limit: $6=-a-7\Rightarrow a=-13$.
- **Ödev (çarpanlara ayırma formülü):** $x^n-a^n=(x-a)(x^{n-1}+x^{n-2}a+\dots+a^{n-1})$.
  - Örnek: $\lim_{x\to2}\frac{x^5-32}{x-2}$. $x=2$ yazınca $\frac00$. Formülle $x-2$ sadeleşir.

### Eşlenik Yöntemi

- **Örnek 3:** $\lim_{x\to1}\frac{x-1}{\sqrt{4x+5}-3}$.
  - Pay ve payda $\sqrt{4x+5}+3$ ile çarpılır.
  - $(a-b)(a+b)=a^2-b^2$: payda $4x+5-9=4(x-1)$ olur.

$$\lim_{x\to1}\frac{(x-1)(\sqrt{4x+5}+3)}{4(x-1)}=\frac{6}{4}=\frac32$$

### Sonsuz Limitler ve Düşey Asimptot

- Sonsuz limitler genelde fonksiyonun kuralını tanımsız yapan noktalarda olur.
- Dört durum: $x\to a^+$ veya $x\to a^-$ iken $f(x)\to+\infty$ veya $-\infty$.
- Sonsuz limitin işareti grafik çizmeden, çarpanların işaretiyle bulunur.
- **Örnek 4:** Paydada çift kuvvetli bir çarpan $(x-1)^2$ benzeri bir terim varsa, $x\to1$ iken payda sağdan ve soldan $0^+$'ya gider. Sonuç her iki taraftan $+\infty$.
- **Örnek 5:** Paydada $(x-2)(x-3)$ benzeri çarpanlar olan bir rasyonel fonksiyon:
  - $x\to3^+$: $x-3>0$ ve sıfıra yaklaşır, $x-2>0$. Sonuç $+\infty$.
  - $x\to3^-$: $x-3<0$ ve sıfıra yaklaşır ($0^-$). Diğer çarpanlar pozitif. Sonuç $-\infty$.
- **Örnek 6:** $x=-4$ yazınca $\frac00$ çıkan bir rasyonel fonksiyon. Önce çarpanlara ayrılır ve sadeleşir. Kalan $x+4$ çarpanı sonsuz limite yol açar. $x\to-4^+$ iken sonuç $-\infty$.
  - Örnek 4-6'nın tam fonksiyonları altyazıda anlaşılmıyor. Yöntem: sadeleştir, sonra her çarpanın işaretine bak.

### Yatay Asimptot

- Burada limit noktası $\pm\infty$, ama sonuç sonlu olmalı.
- $x$ yeterince büyüdüğünde grafik $y=L$ doğrusuna benziyorsa $y=L$ yatay asimptottur.
- Bulmak için $x\to\infty$ ve $x\to-\infty$ limitlerine bakılır.
- **Örnek 7:** $f(x)=2+\frac{10}{x^2}$.
  - $x\to\pm\infty$ iken $\frac{10}{x^2}\to0$. Sonuç 2. Yatay asimptot $y=2$ (iki yönde de).
  - $x\to0^\pm$ iken $\frac{10}{0^+}\to+\infty$. Düşey asimptot $x=0$ ($y$ ekseni).
- **Örnek 8:** $f(x)=5+\frac{\sin x}{\sqrt x}$, $x\to\infty$.
  - $-1\le\sin x\le1$. $\sqrt x$'e bölünür: $-\frac{1}{\sqrt x}\le\frac{\sin x}{\sqrt x}\le\frac{1}{\sqrt x}$.
  - İki sınır 0'a gider. Sıkıştırma teoremiyle $\frac{\sin x}{\sqrt x}\to0$.
  - Sabit 5 unutulmamalı. Yatay asimptot $y=5$.
- **Örnek 9:** $\lim_{\theta\to\infty}\frac{\cos\theta}{\theta^2}$.
  - $-1\le\cos\theta\le1$. $\theta^2$'ye bölünür.
  - İki sınır 0'a gider. Sonuç 0.
  - $\cos$'un çift olması gerekmez. Önemli olan sınırlı olması.
- $y=x^3$ gibi fonksiyonlarda ne yatay ne düşey asimptot vardır. $x\to\pm\infty$ iken $f(x)\to\pm\infty$.

### Polinom ve Rasyonel Fonksiyonların Sonsuzdaki Davranışı

- $p(x)=a_nx^n+\dots+a_0$ için $x\to\pm\infty$ davranışını baş terim $a_nx^n$ belirler.
  - İşaret: derece (tek/çift) ve $a_n$'nin işareti.
- **Örnek 10:** Baş terimi $3x^4$ olan polinom: $x\to\infty$ ve $x\to-\infty$ iken $+\infty$ (çift kuvvet).
- **Örnek 11:** Baş terimi $-2x^3$ olan polinom:
  - $x\to-\infty$ iken $-2\cdot(-\infty)=+\infty$.
  - $x\to+\infty$ iken $-\infty$.
- **Örnek 12:** $f(x)=\frac{4x^3+1}{2x^3+\sqrt{16x^6+1}}$, $x\to\infty$.
  - Pay ve paydada $x^3$ ortak çarpan alınır. $x>0$ olduğu için $\sqrt{16x^6+1}=x^3\sqrt{16+\frac{1}{x^6}}$.

$$\lim_{x\to\infty}\frac{x^3\left(4+\frac1{x^3}\right)}{x^3\left(2+\sqrt{16+\frac1{x^6}}\right)}=\frac{4}{2+4}=\frac23$$

  - Yatay asimptot ($+\infty$'da): $y=\frac23$.
  - $x\to-\infty$ ödev. Dikkat: $\sqrt{x^6}=|x^3|=-x^3$ olur.
- Benzer bir örnekte hoca $x\to-\infty$ iken kökten dışarı $-x^3$ çıktığını vurguluyor. O örnekte $+\infty$'da $y=2$, $-\infty$'da $y=-2$ yatay asimptot bulunuyor.

### Yatay ve Düşey Asimptot Birlikte

- **Örnek 13:** $f(x)=\frac{\sqrt{x^2+2x+6}-3}{x-1}$.
  - **Düşey asimptot adayı $x=1$:** doğrudan yerine koyunca $\frac00$.
  - Eşlenik $\sqrt{x^2+2x+6}+3$ ile çarpılır:

$$\lim_{x\to1}\frac{x^2+2x+6-9}{(x-1)\left(\sqrt{x^2+2x+6}+3\right)}=\lim_{x\to1}\frac{(x+3)(x-1)}{(x-1)\left(\sqrt{x^2+2x+6}+3\right)}=\frac46=\frac23$$

  - Sonuç sonlu. Bu yüzden $x=1$ düşey asimptot değildir. Bu fonksiyonun düşey asimptotu yok.
  - **Yatay asimptot ($x\to\infty$):** pay ve paydadan $x$ ortak çarpan alınır.

$$\lim_{x\to\infty}\frac{x\left(\sqrt{1+\frac2x+\frac6{x^2}}-\frac3x\right)}{x\left(1-\frac1x\right)}=1$$

  - $+\infty$'da yatay asimptot $y=1$.
- Test sınavında bu kadar uzun yazılmaz. Hoca anlaşılsın diye uzun yapıyor.

### Limitin Kesin Tanımı ($\varepsilon$-$\delta$)

- $|x-a|<\delta$ eşitsizliği $a-\delta<x<a+\delta$ demektir. Merkezi $a$ olan açık aralık.
- $|f(x)-L|<\varepsilon$: $f(x)$, $L-\varepsilon$ ile $L+\varepsilon$ arasında.
- $\varepsilon$ keyfi ama pozitif bir sayıdır. Çok küçük seçilebilir (ör. $0{,}00000001$).
- Amaç: verilen her $\varepsilon$ için $\varepsilon$'a bağlı bir $\delta$ bulmak.
- **Örnek 14:** $\lim_{x\to4}(4x-15)=1$ olduğunu kanıtlayın.

$$|f(x)-L|=|4x-15-1|=4|x-4|<\varepsilon\iff|x-4|<\frac{\varepsilon}{4}$$

  - $\delta=\frac{\varepsilon}{4}$ seçilirse $0<|x-4|<\delta$ iken $|f(x)-1|<\varepsilon$ olur.
  - Her $\varepsilon$ için böyle bir $\delta$ bulunabildiği için limit kanıtlanmıştır.
- Grafikte: $x$'ler $(a-\delta,a+\delta)$ içinde kaldıkça $f(x)$'ler $(L-\varepsilon,L+\varepsilon)$ içinde kalır.

### Bir Noktada Süreklilik

- MATLAB gibi bir araçla çizilen parçalı bir fonksiyonda grafikte delik (hole) görülürse fonksiyon orada sürekli değildir.
- **Tanım:** $\lim_{x\to a}f(x)$ var ve $f(a)$'ya eşitse $f$, $a$'da süreklidir.
- **Örnek 15 (grafikten):**
  - $x=2$: limit 1, ama $f(2)=3$. Sürekli değil.
  - $x=3$: limit yok. Sürekli değil.
  - $x=6$: delik veya kopma yok. Sürekli.
- **Örnek 16:** Bir fonksiyon $x=1$'de tanımlı değilse orada sürekli değildir. $x=2$'de tanımlı, limiti var ve eşitse süreklidir.
- **Örnek 17:**

$$h(x)=\begin{cases}x\sin\frac1x, & x\ne0\\ 0, & x=0\end{cases}$$

  - $x=0$'da sürekli mi?
  - $\frac00$ veya $\frac\infty\infty$ biçimi yok. L'Hôpital uygulanamaz.
  - Değişken değiştirme: $t=\frac1x$. $x\to0^+$ iken $t\to+\infty$, $x\to0^-$ iken $t\to-\infty$.

$$\lim_{x\to0}x\sin\frac1x=\lim_{t\to\pm\infty}\frac{\sin t}{t}=0$$

  - $\sin t$ sınırlı, $t$ sınırsız. Sıkıştırma teoremiyle 0.
  - $h(0)=0$ ile eşit. $h$, $x=0$'da süreklidir.
  - $h(0)=1$ olsaydı sürekli olmazdı.

### Süreklilik Kuralları

- $f$ ve $g$, $a$'da sürekliyse: $f+g$, $f-g$, $cf$, $fg$, $f^n$ süreklidir. $f/g$ ise $g(a)\ne0$ koşuluyla süreklidir.
- Polinomlar her yerde süreklidir.
- Rasyonel fonksiyonlar paydayı sıfır yapan noktalar dışında her yerde süreklidir.
- **Bileşke:** $g$, $a$'da sürekli ve $f$, $g(a)$'da sürekliyse $f\circ g$, $a$'da süreklidir.
  - Sonuç: $\lim_{x\to a}f(g(x))=f\left(\lim_{x\to a}g(x)\right)$.
  - Örnek: kök içindeki ifadenin limiti, kökün içinde hesaplanabilir. Bu, kök fonksiyonunun sürekliliği sayesinde yapılır.

### Bir Aralıkta Süreklilik

- Bir aralıkta süreklilik: grafik o aralıkta kalemi kaldırmadan çizilebilir, delik yoktur.
- Aralığın uç noktalarında tek taraflı süreklilik gerekir.
- **Örnek 18 (grafikten):**
  - Grafik $[a,b)$'de sürekli, ama $b$ dahil edilirse ($[a,b]$) sürekli değil. Çünkü $b$'de soldan süreklilik yok.
  - $a$'da sağdan limit var ama $f(a)$ tanımsızsa: $(a,b]$'de sürekli, $[a,b]$'de sürekli değil. $a$'da sağdan süreklilik yok.
- **Örnek 19 (doğru/yanlış):**
  - Deliksiz bir grafik için "$f$, $[a,b]$'de sürekli": doğru. $a$'da sağdan, $b$'de soldan süreklilik var.
  - $a$'da delik olan grafik için "$f$, $[a,b]$'de sürekli": yanlış. $(a,b)$'de sürekli: doğru.
  - "Polinomlar $\mathbb{R}$'de süreklidir": doğru.
  - "$f(x)=\frac{1}{x^2-1}$, $\mathbb{R}\setminus\{-1,1\}=(-\infty,-1)\cup(-1,1)\cup(1,\infty)$ üzerinde süreklidir": doğru.
  - "$\sin x$ ve $\cos x$ her yerde süreklidir": doğru.
  - "$\tan x$ her yerde süreklidir": yanlış. $\tan x=\frac{\sin x}{\cos x}$, $\cos x=0$ olan noktalarda ($\frac\pi2+k\pi$) süreksiz. Sonsuz tane süreksizlik noktası var.

### Ders sonrası notlar

- Hoca dersin başında kendini yeniden tanıtıyor (öğrenciler diğer grupla karıştırdığını hatırlatıyor). Adı altyazıda "Muttalip Ödavşar" olarak geçiyor (Muttalip Özavşar).
- **Örnek 1'deki yazım:** Slaytta $x\to0$ yazıyor, hoca bunu $x\to c$ olarak düzeltiyor.
- **Örnek 13'ün $-\infty$ tarafı:** Hoca yalnız $x\to+\infty$'u hesaplıyor. $x\to-\infty$ iken $\sqrt{x^2}=|x|=-x$ olduğu için limit $-1$ çıkar. Yani $-\infty$'da yatay asimptot $y=-1$.
- **Örnek 12'nin $-\infty$ tarafı (ödev):** $\sqrt{16x^6+1}=-x^3\sqrt{16+\frac1{x^6}}$. Sonuç $\frac{4}{2-4}=-2$.
- **Eğik asimptot (oblique asymptote):** Müfredatta yok ama hoca ileride anlatacağını söylüyor.
- **Sonraki ders:** Logaritmik ve üstel fonksiyonlar, ardından soru çözümü.
- Altyazıda birkaç yerde uzun tekrar döngüsü var (ör. 00:22:06, 00:25:15, 00:38:22, 01:20:36). Bu yerlerdeki anlatım altyazıda anlaşılmıyor. Kareyle doğrulanan kısımlar özete eklendi.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
