# Ders 4 Çalışma Özeti

## Genel Konular

- Geçmiş yıl sınav ve uygulama sorularıyla limit, süreklilik ve süreksizlik alıştırmaları.
- Mutlak değer içeren limitlerde sağ ve sol limit incelemesi.
- Süreksizlik noktalarını bulma ve türünü belirleme (sonsuz, sıçrama, kaldırılabilir).
- Karşı örnekle (counterexample) bir iddiayı çürütme.
- Kaldırılabilir süreksizliği gidererek sürekli fonksiyon elde etme.
- Tanım kümesi soruları (mutlak değer ve kök içeren).
- $0\cdot\infty$ belirsizliği ve sıkıştırma teoremi ne zaman kullanılmaz.
- Kök dereceleri farklı ifadelerde $t^{12}$ türü dönüşüm.
- Sonraki hafta: türev (derivative).

## Hocanın Özellikle Vurguladığı Kısımlar

- Mutlak değer veya parçalı tanım varsa sağdan ve soldan limitleri ayrı ayrı inceleyin. Farklı çıkarsa limit yoktur.
- Test sınavında "Aşağıdakilerden hangileri doğrudur? $x=0$ kaldırılabilir süreksizliktir, $x=2$ sıçrama süreksizliğidir..." gibi sorular gelebilir.
- "Nokta tanım kümesinde değilse süreksizlik sonsuzdur" iddiası yanlıştır. Bir karşı örnek bunu çürütür.
- Bir iddia bir örnekle çürütülebilir, ama bir örnekle doğrulanamaz.
- Yalnız kaldırılabilir süreksizlik giderilebilir. Sonsuz veya sıçrama süreksizliği olan fonksiyon sürekli hâle getirilemez.
- Bir noktada bile sürekli değilse fonksiyon $\mathbb{R}$ üzerinde sürekli değildir.
- $0\cdot\infty$ belirsizliğinde sıkıştırma teoremi kullanılmaz. Önce düzenleme veya değişken değiştirme gerekir.
- Formülleri kalıp olarak ezberlemeyin. $\lim_{x\to\infty}\frac{\sin x}{x}=0$ ile $\lim_{x\to\infty}\frac{\sin\frac1x}{\frac1x}=1$ farklıdır. Mantığı anlayın.
- Bazı sorularda L'Hôpital daha hızlıdır. L'Hôpital 2-3 hafta sonra işlenecek. Test sınavında birçok soruda L'Hôpital kullanılabilir.
- "Ve" kesişime, "veya" birleşime karşılık gelir.

## Kısa Tekrar Notları

- **Sağ limit $x\to0^+$:** $|x|=x$. **Sol limit $x\to0^-$:** $|x|=-x$.
- $\sin$ tek fonksiyondur: $\sin(-x)=-\sin x$.
- **Sonsuz süreksizlik:** tek taraflı limitlerden biri $\pm\infty$.
- **Sıçrama süreksizliği:** sol ve sağ limit sonlu ama farklı.
- **Kaldırılabilir süreksizlik:** limit var (sonlu) ama $f(a)$'ya eşit değil veya $f(a)$ tanımsız.
- **Sürekli hâle getirme:** $g(x)=f(x)$ ($x\ne a$), $g(a)=\lim_{x\to a}f(x)$.
- $\lim_{t\to\pm\infty}\sin t$ yoktur. $\sin t$, $-1$ ile $1$ arasında salınır.
- $\lim_{x\to\infty}\sin\frac1x=\sin0=0$.

## Detaylı Açıklamalar

### Örnek 1: Mutlak Değerli Limit

$$\lim_{x\to0}\frac{1-\cos x}{\sin|x|\cdot\tan x}$$

- $\sin$ fonksiyonu $|x|$'e uygulanıyor. Dikkat.
- **$x\to0^+$:** $|x|=x$. $\tan x=\frac{\sin x}{\cos x}$ yazılır.
  - $\sin^2x=1-\cos^2x=(1-\cos x)(1+\cos x)$ ile sadeleşir.

$$\lim_{x\to0^+}\frac{(1-\cos x)\cos x}{(1-\cos x)(1+\cos x)}=\lim_{x\to0^+}\frac{\cos x}{1+\cos x}=\frac12$$

- **$x\to0^-$:** $|x|=-x$, $\sin(-x)=-\sin x$.
  - Aynı adımlar. Tek fark işaret: sonuç $-\frac12$.
- Sağ ve sol limit farklı. Limit yoktur.

### Örnek 2: Bu Yılın Vize Sorusu (Parçalı Fonksiyon)

- Fonksiyon parçalı tanımlı. $x=-2$ ve $x=1$ civarında farklı kurallar var.
  - $-2<x<1$ civarında $\frac{1}{x+2}$, $x>1$ için $\frac{\sin(1-\sqrt x)}{x-1}$ biçiminde.
- **a) $\lim_{x\to-2}f(x)$:**
  - $\lim_{x\to-2^+}\frac{1}{x+2}=+\infty$. Limit yoktur.
- **$\lim_{x\to1}f(x)$:**
  - Sağ limit: $u=1-\sqrt x$. $x\to1^+$ iken $u\to0$.
  - $x-1=-(1-\sqrt x)(1+\sqrt x)$ çarpanlara ayrılır:

$$\lim_{x\to1^+}\frac{\sin(1-\sqrt x)}{-(1-\sqrt x)(1+\sqrt x)}=1\cdot\frac{-1}{2}=-\frac12$$

  - Sol limit: $\lim_{x\to1^-}\frac{1}{x+2}=\frac13$. Belirsizlik yok.
  - Farklı. Limit yoktur.
- **b) Süreksizlik türleri:**
  - $x=-2$: sonsuz süreksizlik.
  - $x=1$: sıçrama süreksizliği.

### Örnek 3: $\lim_{x\to\pi}\frac{\sin2x}{x^2-\pi x}$

- $\frac00$. Değişken değiştirme: $t=x-\pi$, $x\to\pi$ iken $t\to0$.
- $\sin(2t+2\pi)=\sin2t$. Payda $x(x-\pi)=(t+\pi)t$.

$$\lim_{t\to0}\frac{\sin2t}{2t}\cdot\frac{2}{t+\pi}=1\cdot\frac2\pi=\frac2\pi$$

### Örnek 4: Süreksizlik Noktaları ve Türleri

$$f(x)=\frac{3|x-2|}{x^2(4-x^2)}$$

- Payda sıfır: $x=0$, $x=2$, $x=-2$. Bu noktalarda süreksiz.
- **$x=0$:** $|x-2|=2-x$. Sadeleşince $\frac{3}{x^2(2+x)}\to+\infty$ (iki taraftan). Sonsuz süreksizlik.
- **$x=-2$:** $|x-2|=2-x$.
  - $x\to-2^+$: $+\infty$. $x\to-2^-$: $-\infty$. Sonsuz süreksizlik.
- **$x=2$:**
  - $x\to2^+$: $|x-2|=x-2$. $\frac{3(x-2)}{x^2(2-x)(2+x)}=\frac{-3}{x^2(2+x)}\to-\frac{3}{16}$.
  - $x\to2^-$: $|x-2|=2-x$. Sonuç $+\frac{3}{16}$.
  - Sonlu ve farklı. Sıçrama süreksizliği.

### Karşı Örnek: "Tanım Kümesinde Değilse Sonsuz Süreksizliktir" Yanlış

- Bir öğrenci "$0$ ve $2$ tanım kümesinde olmadığı için sonsuz süreksizliktir" diyor.
- Karşı örnek: $f(x)=\frac{\sin x}{x}$.
  - $0\notin D(f)$.
  - Ama $\lim_{x\to0}\frac{\sin x}{x}=1$, sonlu.
  - $x=0$ sonsuz değil, kaldırılabilir süreksizliktir.
- Bir nokta tanım kümesinde olsa da olmasa da sıçrama süreksizliği olabilir.

### Örnek 5: Parametreli Fonksiyonun Sürekliliği

- $f_{\alpha,\beta}(x)$, $\alpha\ge0$ ve $\beta\in\mathbb{R}$ sabitlerine bağlı bir fonksiyon ailesi. $\alpha$ ve $\beta$, $x$'ten bağımsız.
- $f_{0,-1}$ için ($\alpha=0$, $\beta=-1$) fonksiyon $x\ne0$'da $\sin\frac1x$ biçimine geliyor.
- $x=0$'da limit: $t=\frac1x$ dönüşümüyle $\lim_{t\to\pm\infty}\sin t$.
  - $\sin t$ salınır, hiçbir değere yaklaşmaz. Limit yok.
- Bir noktada sürekli olmadığı için $f_{0,-1}$, $\mathbb{R}$ üzerinde sürekli değildir.
- **Karıştırmayın:** $\lim_{x\to\infty}\sin\frac1x=\sin0=0$. Burada $\frac1x\to0$ olduğu için salınım yoktur.

### Örnek 6: $\lim_{x\to\infty}\frac{x-\sqrt{1+x^2}}{x-\sqrt x}$

- Ortak çarpan almak daha kolay. $x>0$ için $\sqrt{1+x^2}=x\sqrt{1+\frac1{x^2}}$.

$$\lim_{x\to\infty}\frac{x\left(1-\sqrt{1+\frac1{x^2}}\right)}{x\left(1-\frac{1}{\sqrt x}\right)}=\frac{1-1}{1-0}=0$$

### Örnek 7: Kaldırılabilir Süreksizliği Giderme

$$f(x)=\frac{x^2}{1-\cos x}$$

- $x=0$'da süreksizlik türü nedir? Fonksiyonu sürekli hâle getirin.
- Eşlenik $1+\cos x$ ile çarpılıp bölünür:

$$\lim_{x\to0}\frac{x^2(1+\cos x)}{\sin^2x}=\lim_{x\to0}\left(\frac{x}{\sin x}\right)^2(1+\cos x)=1\cdot2=2$$

- Limit var (2), ama $f(0)$ tanımsız. $x=0$ kaldırılabilir süreksizlik.
- Yeni fonksiyon:

$$g(x)=\begin{cases}\dfrac{x^2}{1-\cos x}, & x\ne0\\ 2, & x=0\end{cases}$$

- $g$ her yerde süreklidir.
- Bir öğrencinin "sıçrama süreksizliği" cevabı yanlış. Sıçrama için sağ ve sol limitler farklı olmalı.

### Örnek 8: Sıçrama ve Sonsuz Süreksizlik Birlikte

$$f(x)=\frac{2|1-x|}{x^2(1-x)}$$

- Payda sıfır: $x=0$, $x=1$.
- **$x=0$:** iki taraftan $+\infty$. Sonsuz süreksizlik.
- **$x=1$:**
  - $x\to1^-$: $|1-x|=1-x$. Sonuç 2.
  - $x\to1^+$: $|1-x|=-(1-x)$. Sonuç $-2$.
  - Sıçrama süreksizliği.
- $f$, $\mathbb{R}\setminus\{0,1\}$ üzerinde süreklidir.
- Kaldırılabilir süreksizlik olmadığı için sürekli hâle getirilemez.

### Örnek 9: Tanım Kümesi Soruları

- **a)** $f(x)=\frac{\sqrt{|2x+5|-3}}{x^2+1}$.
  - Kök için $|2x+5|-3\ge0$, yani $|2x+5|\ge3$.
  - $2x+5\ge3\Rightarrow x\ge-1$ veya $2x+5\le-3\Rightarrow x\le-4$.
  - "Veya" birleşimdir: $D(f)=(-\infty,-4]\cup[-1,\infty)$.
  - Payda $x^2+1>0$, sorun yok.
- **b)** $f(x)=\frac{1}{\sqrt{|x|-x}}$.
  - Kök paydada olduğu için $|x|-x>0$ (sıfır olamaz).
  - $x\ge0$ ise $|x|-x=0$. Olmaz.
  - $x<0$ ise $|x|-x=-2x>0$. Olur.
  - $D(f)=(-\infty,0)$.
- Gerçel değerli fonksiyonlar çalışılıyor, karmaşık sayılar değil.

### Örnek 10: $\lim_{x\to0}\frac{\sin x^2}{\sqrt{1+x^2}-1}$

- Eşlenikle çarpılıp bölünür:

$$\lim_{x\to0}\frac{\sin x^2}{x^2}\cdot\left(\sqrt{1+x^2}+1\right)=1\cdot2=2$$

- $u=x^2\to0$.

### Örnek 11: $x\to1^-$ ile Dönüşüm

- $x\to1^-$ iken bir trigonometrik ifade. $t$ dönüşümüyle $t\to0^+$ olur.
- Toplam formülü ($\cos\cos-\sin\sin$) uygulanır.
- $\frac{\sin\frac{\pi}{2}t}{\frac\pi2t}$ oluşturmak için $\frac\pi2$ ile çarpılıp bölünür.
- Sonuç $\frac\pi2$.
- Tam ifade altyazıda net değil. Yöntem: dönüşüm, toplam formülü, $\frac{\sin u}{u}$.

### Örnek 12: $0\cdot\infty$ Belirsizliği

- **a)** $\lim_{x\to\infty}x^2\sin\frac1x$.
  - $x\to\infty$ iken $\sin\frac1x\to0$, $x^2\to\infty$. $0\cdot\infty$ belirsizliği.
  - Sıkıştırma teoremi kullanılamaz. Geçmişte bazı öğrenciler yanlışlıkla kullanmış.
  - **1. yol:** $x\cdot\frac{\sin\frac1x}{\frac1x}$. İkinci çarpan 1'e, $x$ ise $\infty$'a gider. Sonuç $\infty$.
  - **2. yol:** $t=\frac1x$, $t\to0^+$:

$$\lim_{t\to0^+}\frac{1}{t^2}\sin t=\lim_{t\to0^+}\frac1t\cdot\frac{\sin t}{t}=\infty$$

- **b)** $\lim_{x\to\infty}\sqrt x\sin\frac1x$.
  - Yine $0\cdot\infty$. $\frac{1}{\sqrt x}$ ile çarpılıp bölünür:

$$\lim_{x\to\infty}\frac{\sin\frac1x}{\frac1x}\cdot\frac{1}{\sqrt x}=1\cdot0=0$$

### Öğrenci Sorusu: İki Formül Çelişiyor mu?

- $\lim_{x\to\infty}\frac{\sin x}{x}=0$: $\sin x$ sınırlı, $x$ sınırsız. Belirsizlik yok. Sıkıştırma teoremi.
- $\lim_{x\to\infty}\frac{\sin\frac1x}{\frac1x}=1$: $\frac00$ belirsizliği var. $t=\frac1x\to0^+$ dönüşümüyle $\frac{\sin t}{t}\to1$.
- Çelişki yok. Durumlar farklı. Kalıp ezberlenirse karışır.

### Örnek 13: Diğer Alıştırmalar

- **$\cos^2x$ ve $\sin^2x$ içeren bir limit:** eşlenik ve $\cos2x=1-2\sin^2x$ özdeşliği. Hoca bu soruda L'Hôpital'in daha rahat olabileceğini söylüyor.
- **$\sqrt{1-\cos2x}$ benzeri ifade, $x\to0^-$:**
  - Eşlenikle $\sqrt{\sin^22x}=|\sin2x|$ çıkar.
  - $x\to0^-$ iken $\sin2x<0$. Bu yüzden $|\sin2x|=-\sin2x$.
  - Sonuç $-\frac{1}{\sqrt2}$.
- **Küp kök ve dördüncü kök birlikte, $x\to1$:**
  - Kök derecelerinin en küçük ortak katı alınır: $x=t^{12}$ dönüşümü.
  - $x\to1$ iken $t\to1$. Kökler kalkar, polinom çarpanlarına ayrılır.
- **$1-\cos(x^2)$ içeren bir limit:** $\cos^2x$ değil, $\cos(x^2)$. Eşlenik $1+\cos x^2$ ile çarpılır. $\sin^2(x^2)$ çıkar. Sonuç $\frac12$.
- **Sıçrama süreksizliği örneği:** $1-x$ çarpanlarına ayrılır. Eksi işareti unutulmamalı. $x\to1^-$ iken $-2$. Sağ limit farklı. $x=1$ sıçrama süreksizliği.
- **İki ayrı kök içeren bir limit:** hem pay hem paydanın eşleniği gerekir. Hoca bu tür sorularda L'Hôpital'in daha uygun olduğunu söylüyor.
- **$\sin(x^2-x)$ içeren bir limit, $x\to1$:** $u=x^2-x\to0$. $x$ ile çarpılıp bölünerek $\frac{\sin u}{u}$ oluşturulur.

### Örnek 14: Limit Sürekli Fonksiyonun İçine Alınır

$$\lim_{x\to0}\sin\left(\frac{\frac\pi2-\frac\pi2\cos^2x}{x^2}\right)$$

- $\sin$ sürekli olduğu için limit içeri alınır.
- $\frac\pi2(1-\cos^2x)=\frac\pi2\sin^2x$.

$$=\sin\left(\frac\pi2\left(\lim_{x\to0}\frac{\sin x}{x}\right)^2\right)=\sin\left(\frac\pi2\cdot1\right)=1$$

### Örnek 15: Her Yerde Süreklilik

$$f(x)=\begin{cases}x\sin\frac1x, & x\ne0\\ 0, & x=0\end{cases}$$

- $x=0$'da: $\lim_{x\to0}\frac{\sin\frac1x}{\frac1x}$. $t=\frac1x\to\pm\infty$.
  - $\lim_{t\to\pm\infty}\frac{\sin t}{t}=0$ (sıkıştırma teoremi).
  - $f(0)=0$ ile eşit. Sürekli.
- $x\ne0$'da $f$ sürekli fonksiyonların çarpımı ve bileşkesi. Sürekli.
- Sonuç: $f$ her yerde süreklidir.
- **Öğrenci sorusu:** $t=\frac1x$ dönüşümünde $t$'nin nereye gittiği nasıl belirlenir?
  - $x\to0^+$ ise $t\to+\infty$. $x\to0^-$ ise $t\to-\infty$.

### Ders sonrası notlar

- **Örnek 2 sağ limit:** Altyazıda hocanın sözlü sonucu "2 minus 1 over 2" gibi karışık geçiyor. Kare doğruluyor: sağ limit $-\frac12$.
- **Örnek 1:** Bir öğrenci $\frac12$ buluyor. Bu yalnız sağ limittir. Sol limit $-\frac12$ olduğu için limit yoktur.
- **Kayıtlar:** Hoca ders kayıtlarının gelecek hafta yükleneceğini söylüyor. Kayıt paylaşımına itirazı yok.
- **Kaynak:** Çözülen uygulama soruları başka bir hocanın herkese açık Avesis dokümanlarından.
- **Sonraki hafta:** türev. Ardından aşkın fonksiyonlar (transcendental functions): logaritmik, üstel ve ters trigonometrik fonksiyonlar.
- Hoca derste rastgele yoklama alıyor.
- Altyazıda uzun tekrar döngüleri var (ör. 00:08:46, 00:35:42, 00:40:15, 01:03:19, 01:18:12, 01:34:12). Bu yerlerdeki çözüm adımları altyazıda anlaşılmıyor. Kareyle doğrulanan kısımlar özete eklendi.

---

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
