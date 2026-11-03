# Ders 9 Çalışma Özeti

> Tarih: 3 Kasım 2020 (Salı). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var.

## Genel Konular

- Doğal logaritma fonksiyonunun türevi ve genellemesi: $\ln u(x)$, $\ln|x|$.
- Bölüm kuralının logaritma yardımıyla elde edilmesi.
- Logaritmik türev (logarithmic differentiation) yöntemi: hem tabanı hem üssü $x$'e bağlı fonksiyonlar ($x^x$, $x^{\sin x}$ vb.).
- $b$ tabanında logaritmanın türevi.
- Ters fonksiyon (inverse function) için bire bir (one-to-one) ve örten (onto) olma şartı.
- Ters trigonometrik fonksiyonlar: arcsin, arccos, arctan, arccot, arcsec, arccsc; tanım ve görüntü kümeleri.
- Ters trigonometrik fonksiyonların türevleri ve zincir kuralı (chain rule) ile genellemeleri.
- Tanım kümesi (domain) bulma ve türev alma soruları; tablodan türev hesaplama sorusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Formül ezberlemeyin. Temel gerçeklerden formülü 10-15 saniyede çıkarın.
- Sınavda sorunun "yapısına" odaklanın. Fonksiyon değişse de zorluk değişmez, sadece işlem artar.
- $x^x$'in türevi **asla** $x \cdot x^{x-1}$ değildir. Taban ve üs değişkense logaritmik türev kullanılır.
- $f$ bir noktada türevlenemiyorsa, o noktadaki türev bileşik fonksiyon için türev tanımıyla (limit) hesaplanmalıdır. Türev formülüne doğrudan değer konamaz.
- $\ln$ içindeki ifade pozitif olmalı; arcsin ve arccos'un argümanı $[-1,1]$ aralığında olmalı; arcsec'in argümanında $|x| \ge 1$ olmalı.
- $\sin^{-1} x$ gösterimi $\dfrac{1}{\sin x}$ ile karışır. Bu yüzden $\arcsin x$ yazmak tercih edilir.
- Ters trigonometrik türev tablosunda yalnız sol sütunu (arcsin, arctan, arcsec) bilmek yeter. Eş (conjugate) fonksiyonlarda (arccos, arccot, arccsc) yalnızca başa eksi gelir.
- Basit örnekleri küçümsemeyin. Günde 5-10 dakika formüle bakmadan kendinize soru sorun.
- Ödevdeki alıştırmalar doğrudan sınav sorusu değil ama pratik kazandırır.

## Kısa Tekrar Notları

- $\dfrac{d}{dx}\ln x = \dfrac{1}{x}$ ($x>0$), $\dfrac{d}{dx}\ln u(x) = \dfrac{u'(x)}{u(x)}$ ($u>0$), $\dfrac{d}{dx}\ln|x| = \dfrac{1}{x}$.
- $\dfrac{d}{dx}\log_b x = \dfrac{1}{x \ln b}$; aynı sonuç $\log_b |x|$ için de geçerli.
- $\dfrac{d}{dx} a^x = a^x \ln a$; $\dfrac{d}{dx} x^a = a x^{a-1}$ ($a$ sabit).
- Logaritmik türev: $y = f(x)^{g(x)}$ ise $\ln y = g(x)\ln f(x)$, sonra iki tarafın türevi alınır.
- $\dfrac{d}{dx}x^x = x^x(\ln x + 1)$.
- Ters trigonometrik türevler:

| Fonksiyon | Türev | Tanım kümesi (türev için) |
|---|---|---|
| $\arcsin u$ | $\dfrac{u'}{\sqrt{1-u^2}}$ | $\lvert u\rvert<1$ |
| $\arccos u$ | $-\dfrac{u'}{\sqrt{1-u^2}}$ | $\lvert u\rvert<1$ |
| $\arctan u$ | $\dfrac{u'}{1+u^2}$ | tüm reel sayılar |
| $\operatorname{arccot} u$ | $-\dfrac{u'}{1+u^2}$ | tüm reel sayılar |
| $\operatorname{arcsec} u$ | $\dfrac{u'}{\lvert u\rvert\sqrt{u^2-1}}$ | $\lvert u\rvert>1$ |
| $\operatorname{arccsc} u$ | $-\dfrac{u'}{\lvert u\rvert\sqrt{u^2-1}}$ | $\lvert u\rvert>1$ |

- $\arcsin x + \arccos x = \dfrac{\pi}{2}$. Türevi alınınca iki türevin toplamı 0 çıkar.

## Detaylı Açıklamalar

### Ders başı ve duyuru

- Bir öğrenci 1. vizenin kapsamını sordu. Hoca henüz resmî bilgi gelmediğini söyledi. Büyük ihtimalle 7. haftanın sonuna kadarki konular sorumlu olunacak.
- Hoca, şu an 5. haftada olduklarını, konuları erken bitirip soru çözeceklerini söyledi.

### Doğal logaritmanın türevi ve genellemesi

- $\dfrac{d}{dx}\ln x = \dfrac{1}{x}$, $x>0$.
- Zincir kuralı ile: $u(x)>0$ ise $\dfrac{d}{dx}\ln u(x) = \dfrac{u'(x)}{u(x)}$. $u \le 0$ ise logaritma tanımlı değildir.
- $\ln|x|$: $x>0$ için $\ln x$, $x<0$ için $\ln(-x)$. İki durumda da türev $\dfrac{1}{x}$ çıkar.
- Basit örnekler:
  - $\dfrac{d}{dx}\ln(4x) = \dfrac{4}{4x} = \dfrac{1}{x}$.
  - Logaritma özelliğiyle üs katsayı olarak öne alınabilir: $\ln u^2 = 2\ln u$.

### Bölüm kuralının logaritmayla ispatı

- $h(x) = \dfrac{f(x)}{g(x)}$ olsun. Logaritma uygulanınca: $\ln h(x) = \ln f(x) - \ln g(x)$.
- İki tarafın $x$'e göre türevi: $\dfrac{h'(x)}{h(x)} = \dfrac{f'(x)}{f(x)} - \dfrac{g'(x)}{g(x)}$.
- $h'(x)$ çekilip $h = f/g$ yerine konunca:

$$h'(x) = \frac{f'(x)g(x) - f(x)g'(x)}{g(x)^2}$$

### Örnek 1: Bileşke ve $\ln|g(x)|$

- **Soru:** $f$ ve $g$ türevlenebilir, $g(1) = 1$, $g'(1) = 4$. $F(x) = f\big(\ln|g(x)|\big)$ ise $F'(1) = ?$
- **Çözüm:**
  - Zincir kuralı: $F'(x) = f'\big(\ln|g(x)|\big)\cdot \dfrac{g'(x)}{g(x)}$.
  - $x=1$: $\ln|g(1)| = \ln 1 = 0$, $\dfrac{g'(1)}{g(1)} = 4$.
  - $F'(1) = 4 f'(0)$. $f'(0)$ verilmediği için cevap bu şekilde kalır.

### Örnek 2: Türevlenemeyen fonksiyonla çarpım

- **Soru:** $f$, $x=2$'de sürekli, $f(2)=6$ ve $f$, $x=2$'de **türevlenemez**. $g(x) = \sin\!\left(\dfrac{x-2}{3}\right)\cdot f(x)$ ise $g'(2) = ?$
- **Neden tanım?** $f'(2)$ yok. Çarpım kuralı kullanılamaz. Türev tanımı kullanılmalı.
- **Çözüm:**
  - $g(2) = \sin 0 \cdot f(2) = 0$.
  - $g'(2) = \displaystyle\lim_{x\to 2}\frac{g(x)-g(2)}{x-2} = \lim_{x\to 2}\frac{\sin\left(\frac{x-2}{3}\right)}{x-2}\cdot f(x)$.
  - Pay ve paydayı 3'e bölüp $u = \dfrac{x-2}{3}$ alınır. $x\to 2$ iken $u\to 0$.
  - $\displaystyle\lim_{u\to 0}\frac{\sin u}{3u}\cdot f(x) = \frac{1}{3}\cdot 1 \cdot 6 = 2$.
  - $f$ sürekli olduğu için $f(x)\to 6$.
- **Cevap:** $g'(2) = 2$.

### Örnek 3: Normal doğru ve ters fonksiyonun türevi

- **Soru:** $x + 2y - 5 = 0$ doğrusu, $y = f(x)$ grafiğine $x=1$ noktasında normaldir (normal line). $(f^{-1})'(2) = ?$
- **Çözüm:**
  - Normal doğrunun eğimi: $m_n = -\dfrac{1}{2}$.
  - Teğet ve normal dik: $m_t \cdot m_n = -1$, yani $m_t = f'(1) = 2$.
  - Nokta normal doğru üzerinde: $1 + 2y_0 - 5 = 0 \Rightarrow y_0 = 2$. Yani $f(1) = 2$.
  - Ters fonksiyonun türevi: $(f^{-1})'(y_0) = \dfrac{1}{f'(x_0)}$.
  - $(f^{-1})'(2) = \dfrac{1}{f'(1)} = \dfrac{1}{2}$.
- Hoca, 2 bulan öğrencilerin adımlarını kontrol etmesini istedi.

### Örnek 4: $f(x) = x^{\sin x}$ (logaritmik türev)

- Taban da üs de $x$'e bağlı. Bu olağan üstel fonksiyon değildir.
- **Çözüm:**
  - $\ln f(x) = \sin x \cdot \ln x$ ($x>0$).
  - Türev: $\dfrac{f'(x)}{f(x)} = \cos x \ln x + \sin x\cdot\dfrac{1}{x}$.
  - (a) $f'(x) = x^{\sin x}\left(\cos x \ln x + \dfrac{\sin x}{x}\right)$.
  - (b) $f'\!\left(\dfrac{\pi}{2}\right) = \left(\dfrac{\pi}{2}\right)^{1}\left(0 + 1\cdot\dfrac{2}{\pi}\right) = 1$.
- Bir öğrenci $e^{2/\pi}$ bulduğunu söyledi. Hoca adımları tekrar gösterdi ve doğru cevabın 1 olduğunu belirtti.
- Bir öğrenci neden logaritma alındığını sordu. Hoca karşılaştırma yaptı:
  - $x^a$ ($a$ sabit): türev $a x^{a-1}$.
  - $a^x$ ($a$ sabit): türev $a^x \ln a$.
  - $x^x$: ikisi de değişken. Bu formüllerin hiçbiri uygulanamaz. Logaritma alınır.
- Hoca: "$x^x$'in türevi $x^x \ln x$" diyenler de yanlış yapıyor; ezberden kaynaklanıyor.

### Örnek 5: $y = x^x$ grafiğinin yatay teğeti

- Yatay teğet (horizontal tangent) için türevin kökleri bulunur.
- $x^x = e^{x\ln x}$ yazılabilir ya da $\ln y = x\ln x$ alınır.
- $y' = x^x(\ln x + 1)$.
- $x^x > 0$ olduğundan $\ln x + 1 = 0 \Rightarrow x = e^{-1} = \dfrac{1}{e}$.
- **Cevap:** $x = \dfrac{1}{e}$ noktasında yatay teğet vardır.

### $b$ tabanında logaritmanın türevi

- $y = \log_b x \iff b^y = x$. Türev alınınca: $b^y \ln b \cdot y' = 1 \Rightarrow y' = \dfrac{1}{x\ln b}$.
- **Örnek:** $y = \log_5(2x+1)$.
  - $5^y = 2x + 1$.
  - $5^y \ln 5 \cdot y' = 2 \Rightarrow y' = \dfrac{2}{\ln 5}\cdot\dfrac{1}{5^y} = \dfrac{2}{(2x+1)\ln 5}$.
- Hoca, notlardaki bir yazım hatasını gösterip "buna odaklanmayın" dedi.

### Ödev alıştırmaları (logaritma ile sadeleştirme)

- **Örnek:** $f(x) = \ln\dfrac{(2x-1)(x+2)^3}{(1-4x)^2}$.
  - $f(x) = \ln(2x-1) + 3\ln(x+2) - 2\ln(1-4x)$.
  - $f'(x) = \dfrac{2}{2x-1} + \dfrac{3}{x+2} + \dfrac{8}{1-4x}$.
  - Son terim: $-2\cdot\dfrac{-4}{1-4x} = \dfrac{8}{1-4x}$.
- **Örnek (teğet doğru):** $y = 2^{\sin x}$, $x = \dfrac{\pi}{2}$.
  - $\ln y = \sin x \ln 2 \Rightarrow y' = 2^{\sin x}\cos x \ln 2$.
  - $y\!\left(\dfrac{\pi}{2}\right) = 2$, $y'\!\left(\dfrac{\pi}{2}\right) = 0$.
  - Teğet doğru: $y - 2 = 0\cdot\left(x - \dfrac{\pi}{2}\right)$, yani $y = 2$.
- **Örnek (yatay teğetler):** $y = \cos x \cdot \ln(\cos^2 x)$ grafiğinin $[0, 2\pi]$ aralığında 7 yatay teğeti vardır. Noktaların $x$ koordinatlarını bulun.
  - Hoca yalnız türevin nasıl alınacağını gösterdi, gerisini ödev bıraktı.
  - Çözüm aşağıda "Ders sonrası notlar" kısmında.
- **Örnek:** $y = x^{10x}$.
  - $\ln y = 10x\ln x \Rightarrow \dfrac{y'}{y} = 10(\ln x + 1)$.
  - $y' = 10\,x^{10x}(\ln x + 1)$.
- **Örnek:** $y = (\ln x)^{x^2}$.
  - $\ln y = x^2 \ln(\ln x)$.
  - $\dfrac{y'}{y} = 2x\ln(\ln x) + x^2\cdot\dfrac{1/x}{\ln x}$.
  - $y' = (\ln x)^{x^2}\left(2x\ln(\ln x) + \dfrac{x}{\ln x}\right)$.
- **Örnek:** $y = x^{x^{10}}$ benzer şekilde çözülür: $\ln y = x^{10}\ln x$, iki tarafın türevi alınıp $y'$ çekilir.

### Ters fonksiyon şartı

- $f: A \to B$ fonksiyonunun tersinin olması için $f$ bire bir ve örten olmalıdır.
- Örten: $f(A) = B$.
- Bu yüzden $f: A \to f(A)$ bire bir ise tersi vardır.
- Bire bir olmayan fonksiyonlarda (ör. $\sin x$) bire bir olduğu yerel bir parça seçilir.

### arcsin

- $\sin: \mathbb{R} \to [-1, 1]$ bire bir değildir.
- $\sin: \left[-\dfrac{\pi}{2}, \dfrac{\pi}{2}\right] \to [-1,1]$ bire bir ve örtendir.
- Tersi: $\arcsin: [-1, 1] \to \left[-\dfrac{\pi}{2}, \dfrac{\pi}{2}\right]$.
- $\arcsin(\sin x) = x$ ve $\sin(\arcsin x) = x$ (uygun aralıklarda).
- $y = \arcsin x \iff x = \sin y$.

**Türevin elde edilmesi:**

- $\dfrac{dy}{dx} = \dfrac{1}{dx/dy}$, $\dfrac{dx}{dy} \neq 0$ olmalı.
- $x = \sin y \Rightarrow \dfrac{dx}{dy} = \cos y$.
- Dik üçgen: karşı kenar $x$, hipotenüs 1, komşu kenar $\sqrt{1-x^2}$. Yani $\cos y = \sqrt{1-x^2}$.
- Sonuç: $\dfrac{d}{dx}\arcsin x = \dfrac{1}{\sqrt{1-x^2}}$.
- Zincir kuralı: $\dfrac{d}{dx}\arcsin u(x) = \dfrac{u'(x)}{\sqrt{1-u(x)^2}}$.

### Örnek 6: $y = \arcsin(x^2 - 1)$

- (a) Tanım kümesi:
  - $-1 \le x^2 - 1 \le 1 \Rightarrow 0 \le x^2 \le 2$.
  - Sol taraf hep doğru. Sağ taraf: $|x| \le \sqrt{2}$.
  - Tanım kümesi: $\left[-\sqrt{2}, \sqrt{2}\right]$.
- (b) Türev: $y' = \dfrac{2x}{\sqrt{1-(x^2-1)^2}}$.
- Not: Fonksiyonun tam yazımı altyazıdan çıkarıldı (argüman $x^2 - 1$); sonuçlar bununla tutarlı.

### Örnek 7: $y = \arcsin\big(\ln(x^2 + x)\big)$

- $u = \ln(x^2 + x)$, $u' = \dfrac{2x+1}{x^2+x}$.
- $y' = \dfrac{\dfrac{2x+1}{x^2+x}}{\sqrt{1 - \ln^2(x^2+x)}}$.

### arccos

- $\cos: [0, \pi] \to [-1,1]$ bire bir ve örtendir.
- $\arccos: [-1, 1] \to [0, \pi]$.
- $y = \arccos x \iff \cos y = x$.
- Türev: $\dfrac{dx}{dy} = -\sin y = -\sqrt{1-x^2}$.
- $\dfrac{d}{dx}\arccos x = -\dfrac{1}{\sqrt{1-x^2}}$.
- Zincir kuralı: $\dfrac{d}{dx}\arccos u = -\dfrac{u'}{\sqrt{1-u^2}}$.

### Örnek 8: $y = \arccos(\ln x - 1)$ tanım kümesi

- $\ln x$ için $x > 0$ (ön şart).
- $-1 \le \ln x - 1 \le 1 \Rightarrow 0 \le \ln x \le 2$.
- Üstel fonksiyon uygulanınca: $1 \le x \le e^2$.
- $x>0$ şartıyla çelişki yok.
- **Cevap:** Tanım kümesi $[1, e^2]$.
- Hoca, ders anlatırken önceki haftaların konularıyla ilgili soru sorulmamasını, onları soru çözüm saatinde sormalarını istedi.

### arctan

- $\tan x$, $x = \pm\dfrac{\pi}{2}$'de düşey asimptota (vertical asymptote) sahiptir.
- $\tan: \left(-\dfrac{\pi}{2}, \dfrac{\pi}{2}\right) \to \mathbb{R}$ bire bir ve örtendir. Uç noktalar dahil değildir.
- $\arctan: \mathbb{R} \to \left(-\dfrac{\pi}{2}, \dfrac{\pi}{2}\right)$. Argüman herhangi bir reel sayı olabilir.
- $y = \arctan x \iff \tan y = x$.
- $\dfrac{dx}{dy} = 1 + \tan^2 y = 1 + x^2$.
- $\dfrac{d}{dx}\arctan x = \dfrac{1}{1+x^2}$; zincir kuralıyla $\dfrac{u'}{1+u^2}$.

### Örnek 9: $y = \arctan\big(\ln(x^2 - x)\big)$

- (a) Tanım kümesi:
  - $\ln$ için $x^2 - x = x(x-1) > 0$.
  - Kökler 0 ve 1. İşaret tablosu: dışarıda pozitif.
  - Tanım kümesi: $(-\infty, 0) \cup (1, \infty)$. Eşitlik durumu yok.
- (b) Türev: $y' = \dfrac{\dfrac{2x-1}{x^2-x}}{1 + \ln^2(x^2 - x)}$.

### arccot

- $y = \operatorname{arccot} x \iff \cot y = x$.
- $\dfrac{d}{dx}\operatorname{arccot} x = -\dfrac{1}{1+x^2}$.
- arctan ile tek fark eksi işaretidir. Zincir kuralı: $-\dfrac{u'}{1+u^2}$.

### arcsec

- $y = \operatorname{arcsec} x \iff \sec y = x$. Ters fonksiyonun grafiği $y = x$ doğrusuna göre simetriktir.
- arcsec iki parçalıdır.
- Anlamlı olması için $|x| \ge 1$ gerekir.
- Türev parçalı:
  - $x > 1$: $\dfrac{1}{x\sqrt{x^2-1}}$.
  - $x < -1$: $-\dfrac{1}{x\sqrt{x^2-1}}$.
- Kompakt yazım: $\dfrac{d}{dx}\operatorname{arcsec} x = \dfrac{1}{|x|\sqrt{x^2-1}}$, $|x| > 1$.
- Türevde uç noktalar ($x = \pm 1$) dışlanır. Orada tek bir teğet doğru yoktur.

### Genel tablo ve eşlenik kuralı

- $\arcsin x + \arccos x = \dfrac{\pi}{2}$ (liseden). İki tarafın türevi alınarak türevlerin ters işaretli olduğu görülür.
- sin–cos, tan–cot, sec–csc eşleniktir. Eşlenik fonksiyonun türevine yalnızca eksi gelir.
- Hoca: Sol sütunu bilen, 6 formülü 10-15 saniyede çıkarır.

### Örnek 10: $y = x\arctan\dfrac{x}{2}$

- Çarpım kuralı: $y' = \arctan\dfrac{x}{2} + x\cdot\dfrac{1/2}{1 + x^2/4}$.
- Verilen noktadaki değer ve teğet doğru denklemi öğrencilere bırakıldı (notlar daha önce paylaşılmıştı).

### Örnek 11: Tablodan türev (sınav tipi soru)

- Hoca bu yapının test sınavında çıkabileceğini söyledi.

| $x$ | 1 | 3 | 5 | 7 | 9 |
|---|---|---|---|---|---|
| $f(x)$ | 3 | 1 | 9 | 7 | 5 |
| $f'(x)$ | 7 | 9 | 5 | 1 | 3 |
| $g(x)$ | 9 | 7 | 5 | 3 | 1 |
| $g'(x)$ | 5 | 9 | 3 | 1 | 7 |

- (a) $\dfrac{d}{dx}\big(f(x) + 2g(x)\big)\Big|_{x=3} = f'(3) + 2g'(3) = 9 + 18 = 27$.
- (b) $\dfrac{d}{dx}\left[\dfrac{x f(x)}{g(x)}\right]_{x=1}$:
  - $= \dfrac{\big(f(1) + 1\cdot f'(1)\big)g(1) - 1\cdot f(1)\,g'(1)}{g(1)^2}$.
  - $= \dfrac{(3 + 7)\cdot 9 - 3\cdot 5}{81} = \dfrac{90 - 15}{81} = \dfrac{75}{81} = \dfrac{25}{27}$.
- (c) $\dfrac{d}{dx} f\big(g(x^2)\big)\Big|_{x=3}$:
  - $= f'\big(g(x^2)\big)\cdot g'(x^2)\cdot 2x$.
  - $x = 3$: $g(9) = 1$, $f'(1) = 7$, $g'(9) = 7$, $2x = 6$.
  - $= 7\cdot 7\cdot 6 = 294$.
- Hoca: "Sorular güzel. İşlem hatası yapmamak lazım."

### Ders sonu

- Hoca sağlıkla ilgili acil bir işi olduğu için dersi erken bitirdi; arsec sonrası bazı örnekleri hızlı geçti.
- "Yarın görüşmek üzere" diyerek kapattı.

### Ders sonrası notlar

- **Bölüm kuralı ispatı:** Altyazıda "f'x over f'x" geçiyor. Doğrusu $\dfrac{f'(x)}{f(x)}$.
- **Örnek 1:** Altyazıda "$G'(1)$ is 1" geçiyor. Verilen bilgi $g(1) = 1$, $g'(1) = 4$.
- **Örnek 11 (c):** Altyazıda "49 çarpı 2..." diye anlaşılmayan bir ifade var. Doğru hesap $7\cdot 7\cdot 6 = 294$ ($2x$ terimi $x=3$'te 6'dır).
- **arcsec türevi:** Altyazıda $x < -1$ için "only this minus" deniyor. Kompakt yazımda mutlak değer bu eksiyi karşılar: $\dfrac{1}{|x|\sqrt{x^2-1}}$.
- **$\log_5(2x+1)$:** Hoca türevin $x$ yerine $y$'ye göre alındığını söylerken dil sürçmesi yaptı. İki tarafın türevi $x$'e göre alınır.
- **Ödev 84'ün çözümü** ($y = \cos x \ln(\cos^2 x)$, $[0, 2\pi]$):
  - $y' = -\sin x\,\ln(\cos^2 x) + \cos x\cdot\dfrac{-2\sin x\cos x}{\cos^2 x} = -\sin x\big(\ln(\cos^2 x) + 2\big)$.
  - $\sin x = 0$: $x = 0, \pi, 2\pi$ (3 nokta).
  - $\ln(\cos^2 x) = -2 \Rightarrow \cos x = \pm\dfrac{1}{e}$: $x = \arccos\dfrac{1}{e},\ 2\pi - \arccos\dfrac{1}{e},\ \pi - \arccos\dfrac{1}{e},\ \pi + \arccos\dfrac{1}{e}$ (4 nokta).
  - Toplam 7 yatay teğet.
- Altyazıda birkaç yerde döngü var (ör. 00:04:16, 01:34:00, 01:42:05, 01:45:27). Bu kısımlar altyazıda anlaşılmıyor; içerik çevredeki anlatımdan tamamlandı.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
