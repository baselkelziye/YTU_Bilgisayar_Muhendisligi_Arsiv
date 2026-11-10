# Ders 27 Çalışma Özeti

## Genel Konular

- Ders tarihi: 5 Ocak 2021 Salı. Dönemin son haftası.
- Yay uzunluğu (arc length) formülünün Pisagor teoreminden çıkarılması.
- Dönel yüzey alanı (surface area of revolution) formülü.
- Has olmayan integraller (improper integrals):
  - 1. tip: sınırsız aralık üzerinde integral.
  - 2. tip: sınırlı aralıkta süreksizlik noktası olan integral.
- Yakınsaklık (convergence) ve ıraksaklık (divergence).
- Genel alıştırmalar: alan, hacim (disk, pul, kabuk), yay uzunluğu ve yüzey alanı integrallerinin modellenmesi.
- Simetrik bölgenin $x$ ekseni etrafında döndürülmesi: sık yapılan hata.
- Geçmiş yıl final sorusu: $y=2/x$ bölgesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Ders planı:** Bu hafta kalan konular bitiyor. Yarınki derste geçmiş yılların çıkmış soruları çözülecek ve analiz edilecek.
- **Final:** Sınavda genellikle "integrali ifade edin" (state the integration) tarzı sorular gelir. İntegrali modelleyebilmek çok önemli. Hesaplamayı evde yapın.
- **Formül ezberlemeyin:** Yay uzunluğu formülü "Pisagor teoreminden başka bir şey değildir". Yüzey alanı formülü silindirin yüzey alanından gelir. Formülü unutursanız 10-15 saniyede yeniden çıkarabilirsiniz.
- **Nokta felsefesi:** Noktanın kesin tanımı yoktur. Bir noktayı yeterince küçük bir dik üçgen gibi düşünebiliriz. Eğri, yeterince küçük noktaların birleşimidir.
- **Has olmayan integral bir limit problemidir:** Önce integrali limit problemine dönüştürün. Limit varsa integral yakınsaktır, yoksa ıraksaktır.
- **Fonksiyonun değil integralin yakınsaklığı:** "Fonksiyonun yakınsaklığından değil, integralin yakınsaklığından bahsediyoruz."
- **İstatistik bağlantısı:** Bu tür has olmayan integraller ileride istatistik dersinde yoğunluk fonksiyonlarıyla (probability density function) sık sık kullanılacak.
- **Yöntem seçimi:** Çubuğun konumuna bakarak yöntemi seçmek yetmez. Diğer yöntemi seçseydiniz hangi zorluklarla karşılaşacağınızı da görebilmelisiniz.
- **Derse katılım:** Hoca derste soru soruyor. Derse katılmayan öğrencilerin sıkıntı yaşadığını söylüyor.

## Kısa Tekrar Notları

- **Yay uzunluğu:**
  - $dL=\sqrt{dx^2+dy^2}$.
  - $y=f(x)$ ise: $L=\displaystyle\int_a^b\sqrt{1+[f'(x)]^2}\,dx$.
  - $x=g(y)$ ise kök içinde $dy^2$ ortak paranteze alınır: $L=\displaystyle\int_c^d\sqrt{1+[g'(y)]^2}\,dy$.
- **Dönel yüzey alanı ($x$ ekseni etrafında):**
  - $dS=2\pi f(x)\,dL$.
  - $S=2\pi\displaystyle\int_a^b f(x)\sqrt{1+[f'(x)]^2}\,dx$.
- **1. tip has olmayan integral:**
  - $\displaystyle\int_a^{\infty}f(x)\,dx=\lim_{b\to\infty}\int_a^b f(x)\,dx$.
  - $\displaystyle\int_{-\infty}^{a}f(x)\,dx=\lim_{b\to-\infty}\int_b^a f(x)\,dx$.
  - $\displaystyle\int_{-\infty}^{\infty}f\,dx=\int_{-\infty}^{a}f\,dx+\int_a^{\infty}f\,dx$. İkisi de yakınsaksa yakınsak, biri ıraksaksa ıraksak.
- **2. tip has olmayan integral ($f$ sınırlı aralıkta süreksiz):**
  - Süreksizlik $b$'de: $\displaystyle\int_a^b f\,dx=\lim_{t\to b^-}\int_a^t f\,dx$.
  - Süreksizlik $a$'da: $\displaystyle\int_a^b f\,dx=\lim_{t\to a^+}\int_t^b f\,dx$.
  - Süreksizlik iç noktada ($c$): $\displaystyle\int_a^b f\,dx=\lim_{t_1\to c^-}\int_a^{t_1} f\,dx+\lim_{t_2\to c^+}\int_{t_2}^{b} f\,dx$.
- **Önemli sonuçlar:**
  - $\displaystyle\int_{-\infty}^{\infty}\frac{dx}{x^2+1}=\pi$ (yakınsak).
  - $\displaystyle\int_0^{\infty}x e^{-x}\,dx=1$ (yakınsak).
  - $\displaystyle\int_1^{e}\frac{dx}{x\ln x}$ ıraksak.
  - $\displaystyle\int_0^{1}\frac{dx}{x(1+\ln^2 x)}=\frac{\pi}{2}$ (yakınsak).

## Detaylı Açıklamalar

### Yay uzunluğu formülünün çıkarılışı

- $[a,b]$ aralığında sürekli bir $y=f(x)$ eğrisi düşünün.
- Eğri üzerindeki çok küçük bir parçayı dik üçgenin hipotenüsü gibi düşünün. Dik kenarlar $dx$ ve $dy$.
- Pisagor teoreminden: $dL=\sqrt{dx^2+dy^2}$.
- $y$, $x$'e bağlı olduğu için $dx^2$ ortak paranteze alınır ($dx>0$):

$$dL=\sqrt{1+\left(\frac{dy}{dx}\right)^2}\,dx$$

- Sonsuz sayıdaki $dL$ integrallenince eğrinin toplam uzunluğu bulunur:

$$L=\int_a^b\sqrt{1+[f'(x)]^2}\,dx$$

### Örnek 1: $y=x^{3/2}$, $0\le x\le1$ eğrisinin uzunluğu

- $f'(x)=\dfrac{3}{2}\sqrt{x}$, $[f'(x)]^2=\dfrac{9}{4}x$.
- $L=\displaystyle\int_0^1\sqrt{1+\frac{9x}{4}}\,dx=\int_0^1\frac{\sqrt{4+9x}}{2}\,dx$.
- Yerine koyma: $u=4+9x$, $du=9\,dx$. Sınırlar: $x=0\Rightarrow u=4$, $x=1\Rightarrow u=13$.

$$L=\frac{1}{18}\int_4^{13}\sqrt{u}\,du=\frac{1}{18}\cdot\frac{2}{3}\left(13^{3/2}-4^{3/2}\right)=\frac{13\sqrt{13}-8}{27}$$

### Dönel yüzey alanı formülünün çıkarılışı

- Bu kez bölge değil, eğri döndürülüyor.
- Eğri üzerinde uzunluğu $dL$ olan çok küçük bir doğru parçası alın. Yeterince küçük olduğu için $x$ eksenine paralel kabul edilir.
- $dL$ parçası $x$ ekseni etrafında döndürülünce yarıçapı $f(x)$, yüksekliği $dL$ olan bir silindir yüzeyi oluşur.
- Silindir yüzeyi kesilip açılınca bir dikdörtgen elde edilir. Kenarları $2\pi f(x)$ ve $dL$.
- $dS=2\pi f(x)\,dL$. İntegrallenince:

$$S=2\pi\int_a^b f(x)\sqrt{1+[f'(x)]^2}\,dx$$

### Örnek 2: $y=\sqrt{x}$, $0\le x\le1$ eğrisinin $x$ ekseni etrafında yüzey alanı

- $f'(x)=\dfrac{1}{2\sqrt{x}}$, $1+[f'(x)]^2=1+\dfrac{1}{4x}$.
- $\sqrt{x}\cdot\sqrt{1+\dfrac{1}{4x}}=\sqrt{x+\dfrac14}=\dfrac{\sqrt{4x+1}}{2}$.

$$S=2\pi\int_0^1\frac{\sqrt{4x+1}}{2}\,dx=\pi\int_0^1\sqrt{4x+1}\,dx$$

- Yerine koyma: $u=4x+1$, $dx=\frac14 du$, $u$: $1\to5$.

$$S=\frac{\pi}{4}\int_1^5\sqrt{u}\,du=\frac{\pi}{6}\left(5\sqrt5-1\right)$$

- Hoca hesabı ödev bıraktı. Sonuç bu özette eklendi.
- Bir öğrenci hacimle karıştırdı. Hoca: "Hacim değil, dönel yüzeyin alanını hesaplıyoruz."

### 1. tip has olmayan integraller

- $f$, sınırsız bir aralıkta sürekli olsun: $[a,\infty)$, $(-\infty,a]$ ya da $(-\infty,\infty)$.
- Sınırsız aralıktaki integrali sonsuz bir toplam gibi düşünün. Soru şu: Bu toplam sonlu bir değere yakınsar mı, ıraksar mı?
- **Yöntem:** Önce $[a,b]$ üzerinde integral hesaplanır. $f$ sürekli olduğu için bu integral vardır. Sonra $b\to\infty$ limiti alınır.
- Limit varsa integral **yakınsak**, yoksa **ıraksak** adını alır.
- $(-\infty,\infty)$ için araya uygun bir $a$ noktası seçilir. Seçim problemin yapısına bağlıdır.

### Örnek 3: $y=\dfrac{1}{x^2+1}$ altındaki sınırsız bölgenin alanı

- Bölge, grafiğin altında ve $x$ ekseninin üstünde.
- Fonksiyon çift (even), aralık simetrik:

$$A=\int_{-\infty}^{\infty}\frac{dx}{x^2+1}=2\int_0^{\infty}\frac{dx}{x^2+1}=2\lim_{a\to\infty}\left[\arctan x\right]_0^a=2\cdot\frac{\pi}{2}=\pi$$

- İntegral yakınsak.
- **İstatistik notu:** Fonksiyon $\dfrac{1}{\pi(x^2+1)}$ olsaydı integral $1$ çıkardı. Altındaki alan $1$ olan, negatif olmayan böyle bir fonksiyona yoğunluk fonksiyonu denir.

### Örnek 4: $\displaystyle\int_0^{\infty}x e^{-x}\,dx$

- Limit problemine dönüştürülür: $\displaystyle\lim_{a\to\infty}\int_0^a x e^{-x}\,dx$.
- Kısmi integrasyonla belirsiz integral: $\displaystyle\int x e^{-x}\,dx=-e^{-x}(x+1)+C$.
- Sınırlar yerleştirilir:

$$\lim_{a\to\infty}\left[-e^{-a}(a+1)+1\right]=1-\lim_{a\to\infty}\frac{a+1}{e^a}$$

- $\infty/\infty$ belirsizliği L'Hôpital ile: $\displaystyle\lim_{a\to\infty}\frac{1}{e^a}=0$.
- Sonuç $1$. İntegral yakınsak.
- Hoca: Bu da bir olasılık yoğunluk fonksiyonu olarak karşınıza çıkacak.

### 2. tip has olmayan integraller

- $f$, sınırlı bir aralıkta bir noktada süreksiz olsun.
- **Süreksizlik $b$'de:** Araya bir $t$ konur. $[a,t]$ üzerinde integral kolayca hesaplanır. Sonra $t\to b^-$ limiti alınır.
- **Süreksizlik $a$'da:** $[t,b]$ üzerinde integral hesaplanır, $t\to a^+$ limiti alınır.
- **Süreksizlik iç nokta $c$'de:** İki değişken konur. $t_1\to c^-$ ve $t_2\to c^+$. İntegral iki limitin toplamı olarak yazılır.

### Örnek 5: $\displaystyle\int_1^{e}\frac{dx}{x\ln x}$

- $x=1$'de $\ln 1=0$, integrand tanımsız. Bu 2. tip has olmayan integraldir.

$$\int_1^{e}\frac{dx}{x\ln x}=\lim_{a\to1^+}\int_a^{e}\frac{dx}{x\ln x}$$

- Belirsiz integral: $u=\ln x$, $du=\dfrac{dx}{x}$. $\displaystyle\int\frac{du}{u}=\ln|u|=\ln|\ln x|+C$.
- Sınırlar: $\ln(\ln e)=\ln 1=0$.

$$\lim_{a\to1^+}\left[0-\ln(\ln a)\right]$$

- $a\to1^+$ iken $\ln a\to0^+$, $\ln(\ln a)\to-\infty$. Sonuç $+\infty$.
- İntegral **ıraksak**.

### Örnek 6: $\displaystyle\int_0^{1}\frac{dx}{x(1+\ln^2 x)}$

- Süreksizlik noktası $x=0$. (Bir öğrenci süreksizlik noktasını $\pi/2$ sandı. $\pi/2$ integralin değeridir, süreksizlik noktası değil.)
- Limit problemi: $\displaystyle\lim_{a\to0^+}\int_a^1\frac{dx}{x(1+\ln^2x)}$.
- Yerine koyma: $u=\ln x$, $du=\dfrac{dx}{x}$. $\displaystyle\int\frac{du}{1+u^2}=\arctan u=\arctan(\ln x)+C$.

$$\lim_{a\to0^+}\left[\arctan(\ln 1)-\arctan(\ln a)\right]=0-\arctan(-\infty)=-\left(-\frac{\pi}{2}\right)=\frac{\pi}{2}$$

- İntegral **yakınsak**, değeri $\pi/2$.

### Genel alıştırma: $x=y^2$ ve $y-x=-2$ bölgesi

- **Soru (tahtadan):** $R$ bölgesi $x=y^2$ ve $y-x=-2$ (yani $x=y+2$) ile sınırlı.
  - a) $R$'nin alanını veren integral.
  - b) $y$ ekseni etrafında dönmede hacim integrali.
  - c) $x$ ekseni etrafında dönmede hacim integrali.
  - d) $x=-2$ doğrusu etrafında dönmede hacim integrali.
  - e) $y=5$ doğrusu etrafında dönmede hacim integrali.
- **Kesişim:** $y^2-y-2=0\Rightarrow y=2,\ y=-1$.
- Yatay çubukla taranırken sağ uç hep $x_2=y+2$ doğrusunda, sol uç hep $x_1=y^2$ parabolünde.
- **a) Alan (yatay çubuk):**

$$A=\int_{-1}^{2}\left[(y+2)-y^2\right]dy=\frac92$$

- **b) $y$ ekseni etrafında (pul yöntemi):**

$$V=\pi\int_{-1}^{2}\left[(y+2)^2-(y^2)^2\right]dy=\frac{72\pi}{5}$$

- **c) $x$ ekseni etrafında (kabuk yöntemi):**
  - Neden kabuk? Dikey çubuk kullanılırsa çubuğun alt ve üst uçlarının üzerinde bulunduğu eğriler değişir. Birden fazla integral yazmak gerekir. Yatay çubukta uç noktalar hep aynı eğrilerdedir, tek integral yeter.
  - **Dikkat (simetri durumu):** Bölgenin $x$ ekseninin altında kalan parçası ($-1\le y\le0$), döndürülünce üstteki parçanın taradığı cismin içinde kalır. İki parçanın yörüngeleri çakışır.
  - Bu yüzden integral $-1$'den değil, $0$'dan $2$'ye alınır:

$$V=2\pi\int_0^{2}y\left[(y+2)-y^2\right]dy=\frac{16\pi}{3}$$

  - Bir öğrenci denedi: $-1$'den $2$'ye alınınca $9\pi/2$ çıkıyor, bu yanlış.
  - Hoca: "Böyle bir örneği şimdiye kadar görmedim. Sınavda böyle bir soru gelmez ama mantığı güzel."
- **d) $x=-2$ doğrusu etrafında (pul yöntemi):**
  - Yatay çubuk dönme eksenine dik.
  - Dış yarıçap $r_1=(y+2)+2=y+4$, iç yarıçap $r_2=y^2+2$.

$$V=\pi\int_{-1}^{2}\left[(y+4)^2-(y^2+2)^2\right]dy=\frac{162\pi}{5}$$

- **e) $y=5$ doğrusu etrafında (kabuk yöntemi):**
  - Yatay çubuk $y=5$ doğrusuna paralel.
  - Yarıçap $5-y$ (pozitif), yükseklik $(y+2)-y^2$, kalınlık $dy$.

$$V=2\pi\int_{-1}^{2}(5-y)\left[(y+2)-y^2\right]dy=\frac{81\pi}{2}$$

### Simetri örneği: $x=y^2$ ve $x=1$ arasındaki bölge

- Bölge $x$ eksenine göre simetrik. Üst ve alt parçaların alanları eşit ($S$ ve $S$).
- **Yanlış yaklaşım (disk, $-1$'den $1$'e ya da üst ve alt eğri farkı):**
  - $\pi\displaystyle\int_0^1\left[(\sqrt{x})^2-(-\sqrt{x})^2\right]dx=0$ çıkar. Bu anlamsızdır.
  - Kabukta da $y$ işaretli alınıp $-1$'den $1$'e integrallenirse sonuç $0$ çıkar.
- **Doğru yaklaşım:** $2S$ bölgesini $x$ ekseni etrafında döndürmekle tek bir $S$ bölgesini döndürmek aynı cismi verir. Yalnız üst parçaya odaklanın.
  - Disk yöntemi: $V=\pi\displaystyle\int_0^1(\sqrt{x})^2\,dx=\pi\int_0^1 x\,dx=\frac{\pi}{2}$.
  - Kabuk yöntemi: $V=2\pi\displaystyle\int_0^1 y(1-y^2)\,dy=\frac{\pi}{2}$.
- İki yöntem aynı sonucu verir.

### Geçmiş yıl sorusu: $y=2/x$, $x=1$, $x=3$, $y=0$

- a) $x$ ekseni etrafında hacim (disk yöntemi):

$$V=\pi\int_1^3\left(\frac{2}{x}\right)^2dx=\frac{8\pi}{3}$$

- b) $x=4$ doğrusu etrafında hacim (kabuk yöntemi):
  - Dikkat: integral $1$'den $4$'e değil, $1$'den $3$'e alınır. Bölge orada.
  - Yarıçap $4-x$, yükseklik $\dfrac{2}{x}-0$.

$$V=2\pi\int_1^3(4-x)\frac{2}{x}\,dx=16\pi\ln3-8\pi$$

- c) $1\le x\le3$ için yay uzunluğu:

$$L=\int_1^3\sqrt{1+\left(-\frac{2}{x^2}\right)^2}\,dx=\int_1^3\sqrt{1+\frac{4}{x^4}}\,dx$$

  - Bu integralin hesaplanması istenmiyor. Hesabı zor ve uzun.
- d) Eğri $x$ ekseni etrafında döndürülünce yüzey alanı:

$$S=2\pi\int_1^3\frac{2}{x}\sqrt{1+\frac{4}{x^4}}\,dx$$

### Ders sonrası notlar

- **Tarihler:** Ders başında hoca "Sınav tarihimiz 11 Ocak mıydı?" diye soruyor. Ders sonunda gelecek haftanın final haftası olduğunu, ders yapılmayacağını söylüyor. Bir öğrencinin sorusuna göre sınav günü kesin değil; hoca "yine bakarsınız" diyor. Kesin final tarihi altyazıda doğrulanamıyor.
- **Yarınki ders:** 6 Ocak 2021'de çıkmış sorular çözülecek.
- **Örnek 1:** Altyazıda üst sınır "30" diye geçiyor. Doğrusu $u=4+9\cdot1=13$. Hoca da sonucu $13^{3/2}-4^{3/2}$ ile yazıyor.
- **Örnek 2:** Hoca önce kök içini yanlış dağıtıp "$x+4$" diyor, sonra "$4x+1$ olacak" diye düzeltiyor.
- **Çan eğrisi:** Hoca $\dfrac{1}{\pi(x^2+1)}$ için "çan eğrisi" diyor. Bu yoğunluk Cauchy dağılımınındır. "Çan eğrisi" adı genellikle normal dağılım için kullanılır.
- **Yoğunluk değerleri:** Hoca yoğunluk fonksiyonunun değerlerinin $0$ ile $1$ arasında değiştiğini söylüyor. Bu genel olarak doğru değil. Yoğunluk fonksiyonu negatif olmamalı ve altındaki toplam alan $1$ olmalı. Fonksiyonun değeri $1$'i aşabilir.
- **Genel alıştırma (c):** Hoca simetri durumunu "birbirini elimine ediyor" diye açıklıyor. Daha doğru açıklama: alt parçanın döndürülmesiyle oluşan cisim, üst parçanınkinin içinde kalır. Hocanın bir yerde söylediği "$0$'dan $1$'e" ifadesi simetrik kısım ($-1\le y\le1$) içindir; bütün integral $0$'dan $2$'ye alınır. Öğrencinin söylediği "$8\pi/3$" değeri de hatalı; $0$'dan $2$'ye kabuk integrali $16\pi/3$ verir.
- **Genel alıştırma (d):** Hoca önce "kabuk yöntemi" dedi, sonra çubuk dönme eksenine dik olduğu için pul yöntemi olarak düzeltti.
- **Hesaplanan sonuçlar:** Hoca çoğu integrali ödev bıraktı. Sayısal sonuçlar ($\frac{13\sqrt{13}-8}{27}$, $\frac{\pi}{6}(5\sqrt5-1)$, $\frac92$, $\frac{72\pi}{5}$, $\frac{16\pi}{3}$, $\frac{162\pi}{5}$, $\frac{81\pi}{2}$, $\frac{8\pi}{3}$, $16\pi\ln3-8\pi$) bu özette hesaplandı.
- **Altyazı:** Yaklaşık 00:05:01, 00:16:26-00:16:51, 00:45:41, 01:43:23 ve 02:46:34 civarında altyazı tekrar döngüsüne giriyor ("birçok birçok", "İnteklisi", "bu bölümde"). Bu kısımlar altyazıda anlaşılmıyor. Formüller hocanın sonraki anlatımından ve tahtadan kuruldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
