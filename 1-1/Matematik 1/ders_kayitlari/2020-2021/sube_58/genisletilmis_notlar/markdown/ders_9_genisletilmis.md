# Ders 9 Genişletilmiş Notu: Logaritmik Türev ve Ters Trigonometrik Fonksiyonların Türevleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Doğal Logaritmanın Türevi ve Genellemeleri
- 2. Bölüm Kuralının Logaritmayla Elde Edilmesi
- 3. Türev Alıştırmaları: Bileşke, Türev Tanımı ve Ters Fonksiyon
- 4. Logaritmik Türev Yöntemi
- 5. b Tabanında Logaritmanın Türevi
- 6. Ödev Alıştırmaları: Logaritmayla Sadeleştirme
- 7. Ters Fonksiyon Şartı ve arcsin
- 8. arccos
- 9. arctan ve arccot
- 10. arcsec ve Ters Trigonometrik Türev Tablosu
- 11. Son Alıştırmalar: Çarpım ve Tablodan Türev
- Örnek Sorular

## 1. Doğal Logaritmanın Türevi ve Genellemeleri

Ders, bir öğrencinin birinci sınavın kapsamını sormasıyla başladı. Hoca henüz resmi bir bilgi gelmediğini, kapsamın büyük ihtimalle 7. haftanın sonuna kadarki konular olacağını söyledi. Konuları erken bitirip soru çözmeye geçeceklerini belirtti. Ardından geçen haftanın konusu olan logaritmik fonksiyonun türevini hatırlattı.

**Tanım (doğal logaritmanın türevi):**

- $x>0$ için
$$\frac{d}{dx}\ln x = \frac{1}{x}.$$
- $u(x)>0$ ise zincir kuralı (chain rule) ile
$$\frac{d}{dx}\ln u(x) = \frac{u'(x)}{u(x)}.$$
- $u(x)\le 0$ olursa logaritma tanımlı değildir. Bu yüzden $u(x)>0$ şartı konur.

Hoca bu durumu daha genel bir hâle, $\ln|x|$ fonksiyonuna genişletti. Mutlak değerin tanımına göre iki durum vardır. $x>0$ iken $\ln|x| = \ln x$ olur ve türev doğrudan $\dfrac{1}{x}$ çıkar. $x<0$ iken $\ln|x| = \ln(-x)$ olur. Genel kural kullanılınca $\dfrac{-1}{-x} = \dfrac{1}{x}$ bulunur (ara adım eklendi). İki durumda da sonuç aynıdır:

$$\frac{d}{dx}\ln|x| = \frac{1}{x}, \qquad x\neq 0.$$

<!-- BELİRSİZ: 00:04:16 - 00:04:46 arası altyazıda döngü var; x<0 durumunun hocanın yazdığı adımları okunmuyor. Yukarıdaki ara adım genel kuraldan kuruldu. -->

### 1.1 Basit Örnekler

Hoca birkaç basit örnek gösterdi. İlki $\ln(4x)$ idi. Genel kurala göre türev, içerinin türevinin içeriye bölümüdür:

$$\frac{d}{dx}\ln(4x) = \frac{(4x)'}{4x} = \frac{4}{4x} = \frac{1}{x}.$$

Ardından logaritmanın özelliğiyle üssün katsayı olarak öne alınabileceğini hatırlattı: $\ln u^2 = 2\ln u$. Böylece türev $2\cdot\dfrac{u'}{u}$ olur.

<!-- BELİRSİZ: 00:05:08 - 00:05:38 arasında "derivation of second x over second x" gibi okunamayan bir ifade var; bu sıradaki ikinci ve üçüncü örneklerin tam fonksiyonu altyazıdan çıkmıyor. -->

## 2. Bölüm Kuralının Logaritmayla Elde Edilmesi

Hoca, bölüm kuralının (quotient rule) logaritma yardımıyla elde edilebileceğini gösterdi. $h(x) = \dfrac{f(x)}{g(x)}$ olsun. İki tarafa doğal logaritma uygulanır ve logaritmanın bölüm özelliği kullanılır:

$$\ln h(x) = \ln f(x) - \ln g(x).$$

Eşitliğin iki tarafının $x$'e göre türevi alınır:

$$\frac{h'(x)}{h(x)} = \frac{f'(x)}{f(x)} - \frac{g'(x)}{g(x)}.$$

$h'(x)$ yalnız bırakılır ve $h = f/g$ yerine yazılır:

$$h'(x) = \frac{f(x)}{g(x)}\left(\frac{f'(x)}{f(x)} - \frac{g'(x)}{g(x)}\right) = \frac{f'(x)g(x) - f(x)g'(x)}{g(x)^2}.$$

Böylece bilinen bölüm kuralı logaritma ile elde edilmiş olur.

> **Ders sonrası not:** Altyazıda (00:06:42) "f'x over f'x minus g'x over g'x" geçiyor. Doğrusu $\dfrac{f'(x)}{f(x)} - \dfrac{g'(x)}{g(x)}$; paydalarda türev değil fonksiyonun kendisi vardır.

> **Ek bilgi (derste anlatılmadı):** Bu ispat $f(x)>0$ ve $g(x)>0$ olduğu yerde doğrudan geçerlidir. İşaretler negatif olabildiğinde $\ln|f|$ ve $\ln|g|$ kullanılır. $\ln|x|$ türevi de $\dfrac{1}{x}$ olduğu için aynı sonuç çıkar.

## 3. Türev Alıştırmaları: Bileşke, Türev Tanımı ve Ters Fonksiyon

### 3.1 Örnek 1: $\ln|g(x)|$ İçeren Bileşke

**Soru:** $f$ ve $g$ türevlenebilir fonksiyonlar olsun. $g(1) = 1$ ve $g'(1) = 4$ veriliyor. $F(x) = f\big(\ln|g(x)|\big)$ ise $F'(1)$ nedir?

**Çözüm:** Hoca önce zincir kuralını uyguladı. İç fonksiyon $u = \ln|g(x)|$ alınırsa $F'(x) = f'(u)\cdot u'$ olur. $\ln|g(x)|$ türevi, bir önceki kısımdaki genelleme ile $\dfrac{g'(x)}{g(x)}$'tir:

$$F'(x) = f'\big(\ln|g(x)|\big)\cdot\frac{g'(x)}{g(x)}.$$

Verilen değerler yerine konur. $\ln|g(1)| = \ln 1 = 0$ ve $\dfrac{g'(1)}{g(1)} = \dfrac{4}{1} = 4$:

$$F'(1) = f'(0)\cdot 4 = 4f'(0).$$

Hoca, $f'(0)$ değerinin soruda verilmediğini, bu yüzden cevabın $4f'(0)$ olarak kaldığını söyledi.

> **Ders sonrası not:** Altyazıda (00:12:47) "G' of 1 is 1" geçiyor. Soruda verilen $g(1) = 1$'dir; $g'(1) = 4$'tür.

### 3.2 Örnek 2: Türevlenemeyen Fonksiyonla Çarpım

**Soru:** $f$, $x=2$ noktasında sürekli ve $f(2) = 6$. $f$, $x=2$ noktasında **türevlenemez**. $g(x) = \sin\!\left(\dfrac{x-2}{3}\right)f(x)$ ise $g'(2)$ nedir?

Hoca, "$f$, 2'de türevlenemez" şartının çok önemli olduğunu vurguladı. Bu şart yüzünden $g'(x)$ çarpım kuralıyla bulunup içine $x=2$ yazılamaz, çünkü $f'(2)$ yoktur. $g'(2)$ türevin tanımıyla (limit) hesaplanmalıdır.

> **Hocanın vurgusu:** Fonksiyon bir noktada türevlenemiyorsa, o noktadaki türev türev tanımı kullanılarak hesaplanır. Türev formülüne doğrudan değer konamaz.

**Çözüm:**

- Önce $g(2) = \sin 0\cdot f(2) = 0\cdot 6 = 0$.
- Türev tanımı:
$$g'(2) = \lim_{x\to 2}\frac{g(x) - g(2)}{x-2} = \lim_{x\to 2}\frac{\sin\!\left(\frac{x-2}{3}\right)}{x-2}\,f(x).$$
- Pay ve payda 3 ile düzenlenir: $\dfrac{\sin\left(\frac{x-2}{3}\right)}{x-2} = \dfrac{1}{3}\cdot\dfrac{\sin u}{u}$, burada $u = \dfrac{x-2}{3}$.
- $x\to 2$ iken $u\to 0$ ve $\dfrac{\sin u}{u}\to 1$ (ilk haftalarda görülen limit).
- $f$, 2'de sürekli olduğu için $f(x)\to f(2) = 6$.
- Sonuç: $g'(2) = \dfrac{1}{3}\cdot 1\cdot 6 = 2$.

### 3.3 Örnek 3: Normal Doğru ve Ters Fonksiyonun Türevi

**Soru:** $x + 2y - 5 = 0$ doğrusu, $y = f(x)$ grafiğine $x = 1$ noktasında normaldir (normal line). $(f^{-1})'(2)$ nedir?

Hoca bu tür bir yapının test sınavında çıkabileceğini söyledi.

> **Hocanın vurgusu:** Sorunun yapısına odaklanın, fonksiyonun yapısına değil. Fonksiyon değişse de sorunun zorluk seviyesi çok değişmez, sadece işlem artar.

**Çözüm:** Hoca önce bir şekil çizdi: $y = f(x)$ grafiği, $x=1$ noktasındaki teğet doğru ve ona dik olan normal doğru.

- Normal doğru: $2y = -x + 5$, yani eğimi $m_n = -\dfrac{1}{2}$.
- Teğet ve normal birbirine dik olduğundan $m_t\cdot m_n = -1$. Buradan $m_t = 2$, yani $f'(1) = 2$.
- Nokta hem grafiğin hem normal doğrunun üzerindedir. $x_0 = 1$ normal doğruda yerine yazılır: $1 + 2y_0 - 5 = 0 \Rightarrow y_0 = 2$. Yani $f(1) = 2$.
- Ters fonksiyonun türevi formülü: $(f^{-1})'(y_0) = \dfrac{1}{f'(x_0)}$, $y_0 = f(x_0)$.
- Hoca, soruda istenen noktanın tam olarak bulunan $y_0 = 2$ olduğunu gösterip "doğru yoldayız" dedi.
- Sonuç: $(f^{-1})'(2) = \dfrac{1}{f'(1)} = \dfrac{1}{2}$.

Hoca, cevabı 2 bulan öğrencilerin adımlarını kontrol etmesini ve hatalarını anlamaya çalışmasını istedi.

## 4. Logaritmik Türev Yöntemi

### 4.1 Örnek 4: $f(x) = x^{\sin x}$

**Soru:** $f(x) = x^{\sin x}$ veriliyor. (a) $f'(x)$'i bulun. (b) $f'\!\left(\dfrac{\pi}{2}\right)$'yi hesaplayın.

Hoca, bunun olağan bir üstel fonksiyon olmadığını belirtti: taban da üs de $x$'e bağlıdır. Böyle bir fonksiyona doğal logaritma uygulanınca karmaşık ifade temel bir ifadeye dönüşür. Bu yönteme **logaritmik türev** (logarithmic differentiation) denir.

**Tanım (logaritmik türev yöntemi):**

- $y = f(x)^{g(x)}$ biçiminde, hem taban hem üs değişkenli bir fonksiyon verilsin.
- İki tarafa doğal logaritma uygulanır: $\ln y = g(x)\ln f(x)$.
- İki tarafın $x$'e göre türevi alınır. Sol taraf zincir kuralıyla $\dfrac{y'}{y}$ olur.
- $y'$ yalnız bırakılır ve $y$ yerine fonksiyonun kendisi yazılır.

**Çözüm (a):**

- $\ln f(x) = \ln x^{\sin x} = \sin x\ln x$. Burada $x>0$ olmalıdır.
- Sol tarafın türevi zincir kuralıyla $\dfrac{f'(x)}{f(x)}$.
- Sağ taraf çarpım kuralıyla: $(\sin x)'\ln x + \sin x(\ln x)' = \cos x\ln x + \sin x\cdot\dfrac{1}{x}$.
- Sonuç:
$$f'(x) = x^{\sin x}\left(\cos x\ln x + \frac{\sin x}{x}\right).$$

**Çözüm (b):** $x = \dfrac{\pi}{2}$ yazılır. $\sin\dfrac{\pi}{2} = 1$, $\cos\dfrac{\pi}{2} = 0$:

$$f'\!\left(\frac{\pi}{2}\right) = \left(\frac{\pi}{2}\right)^{1}\left(0\cdot\ln\frac{\pi}{2} + 1\cdot\frac{2}{\pi}\right) = \frac{\pi}{2}\cdot\frac{2}{\pi} = 1.$$

**Soru:** Bir öğrenci, logaritma alınan yerden devam edince $e^{2/\pi}$ bulduğunu söyledi. **Cevap:** Hoca adımları baştan tekrar etti: logaritma uygulanır, sol tarafın türevi $\dfrac{f'(x)}{f(x)}$, sağ tarafın türevi $\cos x\ln x + \sin x\cdot\dfrac{1}{x}$ olur. İçler dışlar çarpımıyla $f'(x)$ bulunur. $x = \dfrac{\pi}{2}$ yazılınca $\left(\dfrac{\pi}{2}\right)^1\cdot\dfrac{2}{\pi}$ kalır ve sadeleşince cevap 1 olur. Hoca bu sorunun başka bir yolu olmadığını, cevabın 1 olduğunu söyledi.

<!-- BELİRSİZ: Öğrencinin e^{2/π} sonucuna hangi adımda ulaştığı altyazıdan anlaşılmıyor; büyük olasılıkla ln f'nin değerini f' sanmış. -->

### 4.2 Neden Logaritma Alıyoruz?

**Soru:** Bir öğrenci, $f(x)$'i neden önce logaritmaya çevirdiklerini sordu. **Cevap:** Hoca üç durumu karşılaştırdı:

| Fonksiyon | Taban | Üs | Türev |
|---|---|---|---|
| $x^a$ ($a$ sabit) | değişken | sabit | $a x^{a-1}$ |
| $a^x$ ($a$ sabit), ör. $2^x$ | sabit | değişken | $a^x\ln a$, ör. $2^x\ln 2$ |
| $x^x$ | değişken | değişken | ilk iki formül uygulanamaz |

$x^x$'te hem taban hem üs değişkendir. Bu yüzden ilk iki formülden hiçbiri doğrudan kullanılamaz. $y = x^x$ için iki tarafa logaritma uygulanır: $\ln y = x\ln x$. İki tarafın türevi alınırsa $\dfrac{y'}{y} = 1\cdot\ln x + x\cdot\dfrac{1}{x}$ olur. İçler dışlar çarpımıyla $y'$ bulunur.

> **Hocanın vurgusu:** $x^x$'in türevi asla ve asla $x\cdot x^{x-1}$ değildir. Bazıları $x^x\ln x$ diyor; bu da yanlıştır. Bunlar ezberden ve işin mantığını kavramamaktan kaynaklanır. "Şimdi burada hata yapalım ki gerçek sınavda yapmayın."

### 4.3 Örnek 5: $y = x^x$ Grafiğinin Yatay Teğeti

**Soru:** $y = x^x$ ($x>0$) grafiğinin yatay teğet doğrusu (horizontal tangent line) var mıdır?

Yatay teğet, türevin sıfır olduğu yerdedir. Bu yüzden türev fonksiyonunun kökleri bulunur. Hoca iki yol gösterdi:

- Üstel ve logaritma birbirinin tersi olduğundan $x^x = e^{\ln x^x} = e^{x\ln x}$ yazılabilir ve türev buradan alınır.
- Ya da $\ln y = x\ln x$ alınır ve iki tarafın türevi bulunur.

Her iki yolla:

$$y' = x^x(\ln x + 1).$$

$x^x > 0$ olduğundan $y' = 0 \iff \ln x + 1 = 0 \iff \ln x = -1$. İki tarafa üstel fonksiyon uygulanırsa $e^{\ln x} = x = e^{-1}$. Sonuç: $x = \dfrac{1}{e}$ noktasında yatay teğet vardır.

Hoca bu soruları "gayet basit" olarak nitelendirdi.

## 5. b Tabanında Logaritmanın Türevi

Hoca, $b$ tabanında logaritmanın türevini daha önce gördüklerini hatırlattı ve kısaca geçti. $y = \log_b x \iff b^y = x$. Bu eşitliğin iki tarafının $x$'e göre türevi alınırsa $b^y\ln b\cdot y' = 1$ olur (ara adım eklendi). Buradan:

$$\frac{d}{dx}\log_b x = \frac{1}{x\ln b}.$$

Hoca, argümana mutlak değer konduğunda da ($\log_b|x|$) aynı ifadenin çıktığını belirtti.

Burada hoca ders arası verdi.

### 5.1 Örnek 6: $y = \log_5(2x+1)$

Aradan sonra hoca, notlardaki bir ifadenin hatalı yazıldığını gösterip "buna odaklanmayın" dedi ve şu fonksiyonun türevini aldı:

- $y = \log_5(2x+1) \iff 5^y = 2x + 1$.
- İki tarafın $x$'e göre türevi: $5^y\ln 5\cdot y' = 2$.
- $y' = \dfrac{2}{\ln 5}\cdot\dfrac{1}{5^y}$.
- $5^y = 2x+1$ olduğundan:
$$y' = \frac{2}{(2x+1)\ln 5}.$$

> **Hocanın vurgusu:** Her şeyi ezberlemenize gerek yok. Logaritmanın tanımından türevi hemen alabiliyorsunuz.

> **Ders sonrası not:** Hoca (01:00:24) "iki tarafın $y$'ye göre türevi" dedi; bu bir dil sürçmesidir. Türev $x$'e göre alınır. Sonuç sympy ile doğrulandı.

## 6. Ödev Alıştırmaları: Logaritmayla Sadeleştirme

Hoca ödev alıştırmalarından örnekler gösterdi. Karmaşık çarpım ve bölümlerde önce logaritma kurallarını uygulamanın daha iyi olduğunu söyledi: $\ln(AB) = \ln A + \ln B$, $\ln\dfrac{A}{C} = \ln A - \ln C$, $\ln A^n = n\ln A$.

> **Hocanın vurgusu:** Bu kuralları uygulamak çok önemli. Böylece problemi sadeleştirebiliriz.

### 6.1 Örnek 7: Logaritmanın İçindeki Bölüm

**Soru:** $f(x) = \ln\dfrac{(2x-1)(x+2)^3}{(1-4x)^2}$ fonksiyonunun türevini bulun.

<!-- BELİRSİZ: Fonksiyonun tam yazımı altyazıdan sözlü anlatımla kuruldu (01:03:15): "A = 2x-1, B = (x+2)^3, C = (1-4x)^2". -->

**Çözüm:**

- $A = 2x-1$, $B = (x+2)^3$, $C = (1-4x)^2$ denirse $f = \ln(AB) - \ln C = \ln A + \ln B - \ln C$.
- Üsler katsayı olarak öne alınır: $f(x) = \ln(2x-1) + 3\ln(x+2) - 2\ln(1-4x)$.
- Türev:
$$f'(x) = \frac{2}{2x-1} + \frac{3}{x+2} - 2\cdot\frac{-4}{1-4x} = \frac{2}{2x-1} + \frac{3}{x+2} + \frac{8}{1-4x}.$$

Sonuç sympy ile doğrulandı.

### 6.2 Örnek 8: $y = 2^{\sin x}$ Grafiğine Teğet Doğru

**Soru:** $y = 2^{\sin x}$ grafiğinin $x = \dfrac{\pi}{2}$ noktasındaki teğet doğrusunu bulun.

Hoca, bunun olağan bir üstel fonksiyon olduğunu, formülle de türevi alınabileceğini, ama sadeleştirmek için doğal logaritma uygulanabileceğini söyledi.

- $\ln y = \sin x\ln 2$.
- İki tarafın türevi: $\dfrac{y'}{y} = \cos x\ln 2$.
- $y' = 2^{\sin x}\cos x\ln 2$.
- Nokta: $y_0 = 2^{\sin(\pi/2)} = 2^1 = 2$.
- Eğim: $y'\!\left(\dfrac{\pi}{2}\right) = 2\cdot\cos\dfrac{\pi}{2}\cdot\ln 2 = 0$.
- Teğet doğru: $y - 2 = 0\cdot\left(x - \dfrac{\pi}{2}\right)$, yani $y = 2$.

### 6.3 Örnek 9: Yedi Yatay Teğet

**Soru:** $y = \cos x\ln(\cos^2 x)$ grafiğinin verilen aralıkta 7 yatay teğeti vardır. Bu noktaların $x$ koordinatlarını bulun.

Hoca, yatay teğetin türev fonksiyonunun kökleri demek olduğunu, verilen aralıkta türevin 7 kökünün bulunması gerektiğini söyledi. Türevin nasıl alınacağını gösterdi ve gerisini ödev bıraktı. $\ln(\cos^2 x) = 2\ln|\cos x|$ biçiminde düşünülebilir. Çarpım kuralı uygulanır: birinci terimin türevi çarpı ikinci terim, artı birinci terim çarpı ikinci terimin türevi. $\ln|\cos x|$ türevi $\dfrac{-\sin x}{\cos x}$'tir. Bulunan türev sıfıra eşitlenir ve aralıktaki $x$ değerleri bulunur.

> **Ders sonrası not:** Hoca aralığı (01:07:17) "zero to pi" diye okudu. $[0,\pi]$ aralığında türevin yalnız 4 kökü vardır. 7 kök büyük olasılıkla $[0, 2\pi]$ aralığı içindir. Derste verilmeyen çözüm, sympy ile doğrulanarak şöyledir:
>
> - $y' = -\sin x\ln(\cos^2 x) + \cos x\cdot\dfrac{-2\sin x\cos x}{\cos^2 x} = -\sin x\big(\ln(\cos^2 x) + 2\big)$.
> - $\sin x = 0$: $x = 0,\ \pi,\ 2\pi$.
> - $\ln(\cos^2 x) = -2 \iff \cos x = \pm\dfrac{1}{e}$: $x = \arccos\dfrac{1}{e},\ \pi - \arccos\dfrac{1}{e},\ \pi + \arccos\dfrac{1}{e},\ 2\pi - \arccos\dfrac{1}{e}$.
> - Toplam 7 nokta (yaklaşık $0;\ 1{,}194;\ 1{,}948;\ 3{,}142;\ 4{,}336;\ 5{,}089;\ 6{,}283$). $\cos x = 0$ olan noktalarda fonksiyon tanımlı değildir.

### 6.4 Örnek 10: $y = x^{10x}$

Taban da üs de $x$'e bağlı. Bu tür durumlarda iki tarafa doğal logaritma uygulamak daha iyidir.

- $\ln y = 10x\ln x$.
- $\dfrac{y'}{y} = 10\left(1\cdot\ln x + x\cdot\dfrac{1}{x}\right) = 10(\ln x + 1)$.
- $y' = 10\,x^{10x}(\ln x + 1)$.

### 6.5 Örnek 11: $y = (\ln x)^{x^2}$

- $\ln y = x^2\ln(\ln x)$.
- Çarpım kuralı: $\dfrac{y'}{y} = 2x\ln(\ln x) + x^2\cdot\dfrac{1/x}{\ln x}$.
- Sadeleştirip $y = (\ln x)^{x^2}$ yerine yazılırsa:
$$y' = (\ln x)^{x^2}\left(2x\ln(\ln x) + \frac{x}{\ln x}\right).$$

Hoca, bunları ödevlerde bol bol yapacaklarını söyledi. Ödevlerin doğrudan sınav sorusu olmadığını, ama pratik kazandıracağını belirtti.

**Soru:** Bir öğrenci, ödevdeki 88. alıştırmada bu yöntemi kullanmak gerekmediğini, çünkü değişkenle sabit olduğunu söyledi. **Cevap:** Hoca, aynı yaklaşımla çözülebileceğini ve basit olduğunu söyledi.

<!-- BELİRSİZ: 88. alıştırmanın fonksiyonu altyazıda geçmiyor. -->

Son olarak hoca, artık olayın anlaşılmış olması gerektiğini söyledi: $y = x^{x^{10}}$ gibi bir ifadede de iki tarafa logaritma uygulanır ($\ln y = x^{10}\ln x$), türev alınır, düzenlenir ve $y'$ bulunur. "Bu tarz soruları her zaman logaritmik fonksiyonla çözüyorsunuz."

<!-- BELİRSİZ: 01:11:30'daki ifade "x üzeri x üzeri 10" diye okunuyor; x^{x^{10}} mu yoksa (x^x)^{10} mu olduğu altyazıdan kesin değil. -->

> **Ders sonrası not:** Hoca bu örneğin sonucunu yazmadı. $y = x^{x^{10}}$ için sonuç (sympy ile doğrulandı): $y' = x^{x^{10}}\left(10x^9\ln x + x^9\right)$.

## 7. Ters Fonksiyon Şartı ve arcsin

### 7.1 Tersinirlik Şartı

**Tanım (tersinirlik):**

- $f: A\to B$ fonksiyonunun tersinin olması için gerek ve yeter şart $f$'nin bire bir (one-to-one) ve örten (onto) olmasıdır.
- $f: A\to B$ örten $\iff f(A) = B$.
- Bu yüzden $f: A\to f(A)$ her zaman örtendir. Bu durumda $f: A\to f(A)$ bire bir ise tersinirdir.

### 7.2 arcsin'in Tanımı

Hoca sinüs grafiğini hatırlattı. $\sin: \mathbb{R}\to[-1,1]$, $+1$ ile $-1$ arasında salınır. Bu yüzden bire bir değildir ve tersi yoktur. Ancak grafiğin bir yerel parçası seçilirse, örneğin $-\dfrac{\pi}{2}$ ile $\dfrac{\pi}{2}$ arası, diğer kısımlar göz ardı edilirse durum değişir:

$$\sin: \left[-\frac{\pi}{2}, \frac{\pi}{2}\right]\to[-1,1]$$

bire bir ve örtendir. Tersi vardır, **arcsin** ile gösterilir. Tanım ve değer kümeleri yer değiştirir:

$$\arcsin: [-1,1]\to\left[-\frac{\pi}{2}, \frac{\pi}{2}\right].$$

Ters fonksiyon özelliğiyle $\arcsin(\sin x) = x$ ve $\sin(\arcsin x) = x$ (uygun aralıklarda).

> **Hocanın vurgusu:** arcsin'in argümanı $-1$ ile $+1$ arasında olmalıdır, yoksa arcsin anlamsızdır. Görüntü $\left[-\dfrac{\pi}{2}, \dfrac{\pi}{2}\right]$ aralığındadır.

$y = \arcsin x$ eşitliğinin iki tarafına sinüs uygulanırsa $\sin y = \sin(\arcsin x) = x$ olur, çünkü $f\circ f^{-1}$ birim (özdeşlik) fonksiyondur. Yani bu yerel parça için iki eşdeğer yazım vardır:

$$y = \arcsin x \iff x = \sin y.$$

Hoca, sinüs grafiğinin tamamının değil, yalnız bu yerel parçanın düşünüldüğünü tekrar vurguladı.

### 7.3 arcsin'in Türevi

$y = \arcsin x$ için $\dfrac{dy}{dx}$ aranıyor. Ters fonksiyonun türevi kuralı kullanılır:

$$\frac{dy}{dx} = \frac{1}{dx/dy}, \qquad \frac{dx}{dy}\neq 0.$$

Hoca, $\dfrac{dx}{dy}$ sıfır olursa ters fonksiyondan söz edilemeyeceğini belirtti. $x = \sin y$ yazımında $x$ bağımlı, $y$ bağımsız değişken gibi düşünülürse $\dfrac{dx}{dy} = \cos y$, yani $\dfrac{dy}{dx} = \dfrac{1}{\cos y}$.

Ancak türevin $x$ cinsinden yazılması gerekir. Bunun için hoca bir dik üçgen çizdi. $\sin y = x$ olduğundan, $y$ açısının karşı kenarı $x$, hipotenüs 1 alınır. Pisagor ile komşu kenar $\sqrt{1-x^2}$ olur. Buradan $\cos y = \sqrt{1-x^2}$:

$$\frac{d}{dx}\arcsin x = \frac{1}{\sqrt{1-x^2}}.$$

Zincir kuralıyla genel hâli:

$$\frac{d}{dx}\arcsin u(x) = \frac{u'(x)}{\sqrt{1-u(x)^2}}.$$

> **Ek bilgi (derste anlatılmadı):** $y\in\left[-\dfrac{\pi}{2},\dfrac{\pi}{2}\right]$ aralığında $\cos y\ge 0$ olduğundan karekökün pozitif işareti alınır. $x = \pm 1$ uçlarında $\cos y = 0$ olur ve türev tanımsızdır. Bu yüzden arcsin'in türevi $|x|<1$ için geçerlidir.

Bir öğrenci bu çıkarımı anlamadığını söyledi. Hocanın açıklaması altyazıda yer almıyor.

<!-- BELİRSİZ: 01:23:27 - 01:24:00 arasında öğrencinin sorusuna verilen cevap altyazıda yok. -->

### 7.4 Örnek 12: $y = \arcsin(x^2-1)$

**Soru:** (a) Fonksiyonun tanım kümesini (domain) bulun. (b) Türev fonksiyonunu bulun.

Hoca bunun basit bir soru olduğunu, ama birçok önemli şey anlattığını söyledi.

<!-- BELİRSİZ: Fonksiyonun argümanı altyazıda açıkça söylenmiyor; "x squared bigger than zero and smaller than two" ve "2x over ..." ifadelerinden x^2 - 1 olduğu çıkarıldı. -->

**Çözüm (a):** arcsin'in argümanı $[-1,1]$ aralığında olmalıdır. Bu zorunlu bir şarttır:

- $-1\le x^2 - 1\le 1 \Rightarrow 0\le x^2\le 2$.
- Sol taraf ($x^2\ge 0$) her zaman doğrudur.
- Sağ taraf: $|x|\le\sqrt{2}$.
- Tanım kümesi: $\left[-\sqrt{2}, \sqrt{2}\right]$.

**Çözüm (b):** Argümanın türevi bölü karekök:

$$y' = \frac{2x}{\sqrt{1-(x^2-1)^2}}.$$

Hoca, "Unutursanız nasıl bulacağınızı biliyorsunuz artık" dedi.

> **Ders sonrası not:** Hoca (01:26:14) paydayı "square root of 1 minus square root of argument" diye okudu; doğrusu argümanın karesidir: $\sqrt{1-(x^2-1)^2}$. Ayrıca türev formülü $|x^2-1|<1$ iken geçerlidir; bu da $x\neq 0$ ve $|x|<\sqrt{2}$ demektir. $x = 0$ ve $x = \pm\sqrt{2}$'de payda sıfır olur.

### 7.5 Örnek 13: $y = \arcsin\big(\ln(x^2+x)\big)$

**Soru:** Türev fonksiyonunu bulun.

**Çözüm:** arcsin'in argümanı $u = \ln(x^2+x)$ alınır. $u' = \dfrac{2x+1}{x^2+x}$:

$$y' = \frac{u'}{\sqrt{1-u^2}} = \frac{\dfrac{2x+1}{x^2+x}}{\sqrt{1-\ln^2(x^2+x)}}.$$

Hoca sonucun sadeleştirilebileceğini söyledi.

## 8. arccos

### 8.1 Tanım

Hoca kosinüs grafiğini çizdi: $x=0$'da kosinüs 1'dir. Kosinüs bire bir değildir, ama $[0,\pi]$ yerel parçasıyla sınırlanırsa bire bir ve örten olur:

$$\cos: [0,\pi]\to[-1,1], \qquad \arccos: [-1,1]\to[0,\pi].$$

Ters fonksiyon kuralına göre $\cos(\arccos x) = x$ ve $\arccos(\cos x) = x$.

> **Hocanın vurgusu:** Bu çok bilinen formülleri lisede genelde ezberlersiniz, ama ezberlemenize gerek yok. $f\circ f^{-1}$'in birim fonksiyon olduğunu bilmek yeterlidir.

$y = \arccos x$ eşitliğinin iki tarafına kosinüs uygulanırsa $\cos y = x$ olur.

### 8.2 arccos'un Türevi

Hoca türevi iki yolla gösterdi.

<!-- BELİRSİZ: 01:33:33 - 01:34:30 arasında altyazıda döngü var; hocanın birinci yöntemde yazdığı adımlar okunmuyor. Altyazıda yalnızca sonuç ("minus 1 over square root of 1 minus x²") geçiyor. -->

İkinci yöntem arcsin'deki yöntemin aynısıdır:

$$\frac{dy}{dx} = \frac{1}{dx/dy} = \frac{1}{-\sin y}.$$

$\cos y = x$ olduğundan dik üçgenle $\sin y = \sqrt{1-x^2}$ bulunur (ara adım eklendi). Sonuç:

$$\frac{d}{dx}\arccos x = -\frac{1}{\sqrt{1-x^2}}.$$

Zincir kuralıyla:

$$\frac{d}{dx}\arccos u(x) = -\frac{u'(x)}{\sqrt{1-u(x)^2}}.$$

### 8.3 Örnek 14: $y = \arccos(\ln x - 1)$ Tanım Kümesi

**Soru:** $y = \arccos(\ln x - 1)$ fonksiyonunun tanım kümesini bulun.

**Çözüm:**

- $\ln x$'in anlamlı olması için $x > 0$ olmalıdır. Bu ön şarttır.
- arccos'un anlamlı olması için: $-1\le\ln x - 1\le 1 \Rightarrow 0\le\ln x\le 2$.
- Eşitsizliğin her tarafına üstel fonksiyon uygulanır: $e^0\le e^{\ln x}\le e^2$, yani $1\le x\le e^2$.
- Bu sonuç $x>0$ şartıyla çelişmez.
- Tanım kümesi: $[1, e^2]$.

Bu sırada hoca, ders anlatılırken iki üç hafta önceki konulardan soru sorulmamasını, onları soru çözüm zamanında sormalarını istedi.

## 9. arctan ve arccot

### 9.1 Gösterim Hakkında

Hoca, bazı kişilerin $\sin^{-1}x$ gösterimini kullandığını, ama bu gösterimin iyi olmadığını söyledi. $\dfrac{1}{\sin x}$ ile karıştırılabilir. Bu yüzden $\arcsin x$ yazmak tercih edilir.

### 9.2 arctan'ın Tanımı

Hoca tanjant grafiğini çizdi. $\tan 0 = 0$. $x = \pm\dfrac{\pi}{2}$'de düşey asimptot (vertical asymptote) vardır. $\dfrac{\pi}{2}$'ye yaklaştıkça tanjant sonsuza gider. Sağdan $-\dfrac{\pi}{2}$'ye yaklaştıkça eksi sonsuza iner.

<!-- BELİRSİZ: 01:42:05 - 01:42:35 arasında altyazıda döngü var; tanjantın periyodik parçaları hakkındaki anlatım okunmuyor. -->

Tanjant bire bir değildir. Ama tek bir yerel parça seçilip diğer kısımlar göz ardı edilirse, yatay doğru testine (horizontal line test) göre bu parça bire birdir:

$$\tan: \left(-\frac{\pi}{2}, \frac{\pi}{2}\right)\to\mathbb{R}, \qquad \arctan: \mathbb{R}\to\left(-\frac{\pi}{2}, \frac{\pi}{2}\right).$$

Hoca, uç noktaların dahil olmadığını vurguladı.

> **Hocanın vurgusu:** arctan'ın argümanı herhangi bir reel sayı olabilir.

### 9.3 arctan'ın Türevi

$y = \arctan x \iff \tan y = x$.

<!-- BELİRSİZ: 01:45:27 - 01:45:57 arasında altyazıda döngü var; türev adımlarının başı okunmuyor. -->

$$\frac{dy}{dx} = \frac{1}{dx/dy} = \frac{1}{1+\tan^2 y} = \frac{1}{1+x^2}.$$

Zincir kuralıyla:

$$\frac{d}{dx}\arctan u(x) = \frac{u'(x)}{1+u(x)^2}.$$

Hoca, bunu ezberlemeye gerek olmadığını, temel gerçekleri bilen birinin formülü doğrudan elde edebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** $\dfrac{d}{dy}\tan y = \sec^2 y$ ve $\sec^2 y = 1 + \tan^2 y$ özdeşliği kullanılır. Bu yüzden $\dfrac{dx}{dy}$, $x$ cinsinden üçgen çizmeye gerek kalmadan $1+x^2$ olarak yazılabilir.

### 9.4 Örnek 15: $y = \arctan\big(\ln(x^2-x)\big)$

**Soru:** (a) Tanım kümesini bulun. (b) $y' = \dfrac{dy}{dx}$'i bulun.

<!-- BELİRSİZ: Fonksiyonun tam yazımı altyazıda "r tangent ln" (01:47:28) ve "x² - x" (01:51:42) ifadelerinden kuruldu. -->

**Çözüm (a):** arctan'ın argümanında bir sınırlama yoktur. Kısıt yalnız logaritmadan gelir:

- $x^2 - x = x(x-1) > 0$ olmalıdır.
- Kökler $x = 0$ ve $x = 1$. İkisinin de kuvveti 1'dir.
- 1'in sağında bir değer, örneğin $x = 2$ denenirse ifade pozitiftir. Kuvvetler tek olduğu için her kökte işaret değişir.

| Aralık | $(-\infty, 0)$ | $(0, 1)$ | $(1, \infty)$ |
|---|---|---|---|
| $x(x-1)$ işareti | $+$ | $-$ | $+$ |

- Tanım kümesi: $(-\infty, 0)\cup(1,\infty)$. Eşitlik durumu yoktur, çünkü 0'da logaritma tanımsızdır.

**Çözüm (b):** arctan'ın argümanının türevi bölü $1 +$ argümanın karesi:

$$y' = \frac{\dfrac{2x-1}{x^2-x}}{1+\ln^2(x^2-x)}.$$

Sonuçlar sympy ile doğrulandı.

> **Hocanın vurgusu:** Bunlar basit sorular ama konuyu anlatıyor. Basit deyip küçümsemeyin. Günde 5-10 dakika, formüllere bakmadan kendi kendinize bu tarz sorular sorun ve formülleri çıkarmaya çalışın. İşin mantığını anlarsanız rahat edersiniz.

### 9.5 arccot

arctan'a benzer şekilde: $y = \operatorname{arccot}x \iff \cot y = x$.

$$\frac{dy}{dx} = \frac{1}{dx/dy} = -\frac{1}{1+x^2}.$$

arccot ile arctan türevleri arasındaki tek fark baştaki eksi işaretidir. Zincir kuralıyla:

$$\frac{d}{dx}\operatorname{arccot}u(x) = -\frac{u'(x)}{1+u(x)^2}.$$

Hoca, bu eksinin unutulmamasını istedi.

## 10. arcsec ve Ters Trigonometrik Türev Tablosu

### 10.1 arcsec

Hoca, ters fonksiyonun grafiğinin $f$'nin grafiğinin $y = x$ doğrusuna göre simetriği olduğunu hatırlattı. $y = \sec x$'in uygun bir yerel parçası alınır ve $y = x$'e göre yansıtılırsa $y = \operatorname{arcsec}x$ grafiği elde edilir. $y = \operatorname{arcsec}x$ eşitliğine sekant uygulanırsa $\sec y = x$ olur. Grafik iki parçadan oluşur.

> **Hocanın vurgusu:** arcsec'in anlamlı olması için argümanın mutlak değeri 1'den büyük ya da 1'e eşit olmalıdır: $|x|\ge 1$. Bu çok önemli.

<!-- BELİRSİZ: arcsec'in değer kümesi (hangi yerel parçanın seçildiği) altyazıda söylenmiyor. -->

### 10.2 arcsec'in Türevi

Eşdeğer yazım ve bir trigonometrik özdeşlik kullanılarak türev elde edilir. Tanım kümesi $|x|\ge 1$ olduğu için türev parçalı (piecewise) çıkar:

$$\frac{d}{dx}\operatorname{arcsec}x = \begin{cases}\dfrac{1}{x\sqrt{x^2-1}}, & x>1\\[2mm] -\dfrac{1}{x\sqrt{x^2-1}}, & x<-1\end{cases}$$

Hoca, türevde uç noktaların ($x = \pm 1$) çıkarıldığını vurguladı. Uç noktalarda tek bir teğet doğru yoktur, bu yüzden eşitlik durumu türevde yer almaz. Parçalı ifade daha kısa biçimde yazılabilir ve hoca bu yazımın daha iyi olduğunu söyledi:

$$\frac{d}{dx}\operatorname{arcsec}x = \frac{1}{|x|\sqrt{x^2-1}}, \qquad |x|>1.$$

> **Ek bilgi (derste anlatılmadı):** $x<-1$ için $|x| = -x$ olduğundan kısa yazımdaki mutlak değer, parçalı yazımdaki eksi işaretinin yerini tutar. Türev her iki parçada da pozitiftir; örneğin $x = 2$ ve $x = -2$'de aynı değeri verir.

### 10.3 Eşlenik Kuralı ve Genel Tablo

Hoca, liseden bilinen $\arcsin x + \arccos x = \dfrac{\pi}{2}$ eşitliğini hatırlattı. İki tarafın türevi alınırsa sağ taraf sabit olduğu için türevlerin toplamı 0 çıkar. Böylece arccos türevinin arcsin türevinin eksilisi olduğu kanıtlanabilir.

sin ile cos, tan ile cot, sec ile csc birbirinin eşleniğidir (conjugate). Eşlenik fonksiyonun ters fonksiyon türevine yalnız bir eksi gelir:

| Fonksiyon | Türev | Eşleniği | Türev |
|---|---|---|---|
| $\arcsin u$ | $\dfrac{u'}{\sqrt{1-u^2}}$ | $\arccos u$ | $-\dfrac{u'}{\sqrt{1-u^2}}$ |
| $\arctan u$ | $\dfrac{u'}{1+u^2}$ | $\operatorname{arccot}u$ | $-\dfrac{u'}{1+u^2}$ |
| $\operatorname{arcsec}u$ | $\dfrac{u'}{\lvert u\rvert\sqrt{u^2-1}}$ | $\operatorname{arccsc}u$ | $-\dfrac{u'}{\lvert u\rvert\sqrt{u^2-1}}$ |

> **Hocanın vurgusu:** Sadece sol sütunu bilmeniz, daha doğrusu çıkarabilmeniz yeterli. Sin yerine cos, tan yerine cot, sec yerine csc koyduğunuzda başa eksi getiriyorsunuz. Böylece 6 formülü 10-15 saniyede çıkarabilirsiniz. Hepsini tek tek ezberlemek zorunda değilsiniz.

## 11. Son Alıştırmalar: Çarpım ve Tablodan Türev

Hoca, bir işi olduğu için ara vermeden devam edeceğini ve dersi erken bitireceğini söyledi.

### 11.1 Örnek 16: $y = x\arctan\dfrac{x}{2}$

**Soru:** Fonksiyonun türevini alın ve verilen noktadaki türev değerini hesaplayın.

<!-- BELİRSİZ: Türev değerinin hesaplanacağı nokta altyazıda söylenmiyor ("at the point this"). -->

**Çözüm:** Çarpım kuralı uygulanır. Birinci terimin türevi 1 çarpı $\arctan\dfrac{x}{2}$, artı $x$ çarpı $\arctan\dfrac{x}{2}$'nin türevi. arctan'ın argümanının türevi $\dfrac{1}{2}$'dir:

$$y' = \arctan\frac{x}{2} + x\cdot\frac{1/2}{1+\dfrac{x^2}{4}}.$$

Hoca, verilen noktadaki değeri ve teğet doğru denklemini öğrencilere bıraktı; bunun daha önce paylaşılan notlarda bulunduğunu söyledi.

### 11.2 Örnek 17: Tablodan Türev Hesabı

Hoca bu sorunun test sınavında çıkabileceğini, biraz değiştirilerek sorulabileceğini söyledi. (a) şıkkının basit, (b) ve (c) şıklarının biraz zorlayıcı olduğunu belirtti.

> **Hocanın vurgusu:** Bu yapı çok önemli. Bu tarz sorular sınavda gelebilir.

**Soru:** $f$ ve $g$ fonksiyonlarının bazı noktalardaki değerleri ve türev değerleri bir tabloda veriliyor. Altyazıda geçen değerler şunlardır:

| | $x = 1$ | $x = 9$ |
|---|---|---|
| $f(x)$ | 3 | |
| $f'(x)$ | 7 | |
| $g(x)$ | 9 | 1 |
| $g'(x)$ | 5 | 7 |

<!-- BELİRSİZ: Tablonun geri kalanı (x = 3, 5, 7 sütunları ve diğer değerler) ile (a) şıkkındaki ifade altyazıda okunmuyor. Video ve kare olmadığı için doğrulanamadı. -->

**(a):** Hoca cevabın 27 olduğunu söyledi. Şıkkın ifadesi altyazıda geçmiyor.

**(b):** $\dfrac{d}{dx}\left[\dfrac{x f(x)}{g(x)}\right]$, $x = 1$'de. Bölüm kuralı ve paydaki çarpım için çarpım kuralı kullanılır:

$$\frac{d}{dx}\left[\frac{xf(x)}{g(x)}\right] = \frac{\big(f(x) + xf'(x)\big)g(x) - xf(x)g'(x)}{g(x)^2}.$$

$x = 1$ yazılır:

- $f(1) + 1\cdot f'(1) = 3 + 7 = 10$.
- $10\cdot g(1) = 10\cdot 9 = 90$.
- $1\cdot f(1)\cdot g'(1) = 3\cdot 5 = 15$.
- Pay: $90 - 15 = 75$. Payda: $g(1)^2 = 81$.
- Sonuç: $\dfrac{75}{81} = \dfrac{25}{27}$.

Hoca sadeleştirmeyi öğrencilere bıraktı.

**(c):** $\dfrac{d}{dx}f\big(g(x^2)\big)$, $x = 3$'te. Zincir kuralı iki kez uygulanır:

$$\frac{d}{dx}f\big(g(x^2)\big) = f'\big(g(x^2)\big)\cdot g'(x^2)\cdot 2x.$$

$x = 3$ yazılır: $x^2 = 9$, $g(9) = 1$, $f'(1) = 7$, $g'(9) = 7$, $2x = 6$:

$$7\cdot 7\cdot 6 = 294.$$

> **Ders sonrası not:** Altyazıda (02:09:07) sonuç "49 çarpı 2 ..." gibi anlaşılmayan bir ifadeyle geçiyor. Zincir kuralındaki $2x$ çarpanı $x = 3$'te 6'dır; doğru sonuç $49\cdot 6 = 294$'tür.

Hoca, soruların güzel olduğunu ve işlem hatası yapmamak gerektiğini söyledi. Ardından dersi bitirdi.

## Örnek Sorular

Bu derste video ve kare yoktur. Aşağıdaki sorular derste hocanın öğrencilere çözmeleri için sorduğu sorulardır. Çözümler yukarıdaki ilgili bölümlerdedir.

1. (derste sözlü, 00:09:00) $f$ ve $g$ türevlenebilir, $g(1) = 1$, $g'(1) = 4$. $F(x) = f\big(\ln|g(x)|\big)$ ise $F'(1)$ nedir? Cevap: $F'(1) = 4f'(0)$ (Bölüm 3.1).
2. (derste sözlü, 00:13:32) $f$, 2'de sürekli, $f(2) = 6$ ve 2'de türevlenemez. $g(x) = \sin\!\left(\dfrac{x-2}{3}\right)f(x)$ ise $g'(2)$ nedir? Cevap: $g'(2) = 2$ (Bölüm 3.2).
3. (derste sözlü, 00:19:00) $x + 2y - 5 = 0$ doğrusu, $y = f(x)$ grafiğine $x=1$'de normaldir. $(f^{-1})'(2)$ nedir? Cevap: $\dfrac{1}{2}$ (Bölüm 3.3).
4. (derste sözlü, 00:28:38) $f(x) = x^{\sin x}$. (a) $f'(x)$'i bulun. (b) $f'\!\left(\dfrac{\pi}{2}\right)$'yi hesaplayın. Cevap: (a) $x^{\sin x}\left(\cos x\ln x + \dfrac{\sin x}{x}\right)$, (b) 1 (Bölüm 4.1).
5. (derste sözlü, 00:38:31) $y = x^x$ ($x>0$) grafiğinin yatay teğeti var mıdır? Cevap: $x = \dfrac{1}{e}$'de (Bölüm 4.3).
6. (derste sözlü, 01:07:03) $y = \cos x\ln(\cos^2 x)$ grafiğinin 7 yatay teğetinin $x$ koordinatlarını bulun. Hoca yalnız türevin nasıl alınacağını gösterdi.

> **Çözüm (derste verilmedi):** Büyük olasılıkla aralık $[0,2\pi]$'dir. $y' = -\sin x\big(\ln(\cos^2 x) + 2\big) = 0$ denkleminden $x = 0,\ \pi,\ 2\pi$ ve $\cos x = \pm\dfrac{1}{e}$ olan dört nokta bulunur: $\arccos\dfrac{1}{e},\ \pi - \arccos\dfrac{1}{e},\ \pi + \arccos\dfrac{1}{e},\ 2\pi - \arccos\dfrac{1}{e}$ (sympy ile doğrulandı; Bölüm 6.3).

7. (derste sözlü, 01:24:00) $y = \arcsin(x^2-1)$. (a) Tanım kümesini bulun. (b) Türev fonksiyonunu bulun. Cevap: (a) $\left[-\sqrt{2},\sqrt{2}\right]$, (b) $\dfrac{2x}{\sqrt{1-(x^2-1)^2}}$ (Bölüm 7.4).
8. (derste sözlü, 01:26:41) $y = \arcsin\big(\ln(x^2+x)\big)$ fonksiyonunun türevini bulun. Cevap: $\dfrac{(2x+1)/(x^2+x)}{\sqrt{1-\ln^2(x^2+x)}}$ (Bölüm 7.5).
9. (derste sözlü, 01:36:23) $y = \arccos(\ln x - 1)$ fonksiyonunun tanım kümesini bulun. Cevap: $[1, e^2]$ (Bölüm 8.3).
10. (derste sözlü, 01:47:28) $y = \arctan\big(\ln(x^2-x)\big)$. (a) Tanım kümesini bulun. (b) $y'$'yi bulun. Cevap: (a) $(-\infty,0)\cup(1,\infty)$, (b) $\dfrac{(2x-1)/(x^2-x)}{1+\ln^2(x^2-x)}$ (Bölüm 9.4).
11. (derste sözlü, 02:02:41) Tablodan türev sorusu: (b) $\dfrac{d}{dx}\left[\dfrac{xf(x)}{g(x)}\right]_{x=1}$, (c) $\dfrac{d}{dx}f\big(g(x^2)\big)\Big|_{x=3}$. Cevap: (a) 27 (ifade altyazıda yok), (b) $\dfrac{25}{27}$, (c) 294 (Bölüm 11.2). <!-- BELİRSİZ: tablonun tamamı ve (a) şıkkının ifadesi altyazıda yok. -->

## Dersin Toparlaması

Bu derste önce doğal logaritmanın türevi $\ln u$ ve $\ln|x|$ biçimlerine genelleştirildi ve bölüm kuralının logaritma ile elde edilebileceği gösterildi. Bileşke, türev tanımı ve ters fonksiyon türevi üzerine sınav tipi alıştırmalar çözüldü. Ardından taban ve üssün ikisinin de değişken olduğu fonksiyonlar için logaritmik türev yöntemi anlatıldı: iki tarafa $\ln$ uygulanır, türev alınır, $y'$ çekilir. $x^x$'in türevinin ezberle yanlış alınmaması özellikle vurgulandı. $b$ tabanında logaritmanın türevi ve ödevlerden logaritmayla sadeleştirme örnekleri gösterildi.

Dersin ikinci yarısında, tersinirlik için bire bir ve örten olma şartından yola çıkılarak trigonometrik fonksiyonların yerel parçaları üzerinden arcsin, arccos, arctan, arccot ve arcsec tanımlandı. Türevleri $\dfrac{dy}{dx} = \dfrac{1}{dx/dy}$ kuralı ve dik üçgen yardımıyla elde edildi. Tanım kümesi soruları için argüman şartları ($[-1,1]$, $|x|\ge 1$, logaritmada pozitiflik) üzerinde duruldu. Eşlenik kuralıyla altı formülün yalnız üçünü bilmenin yeterli olduğu gösterildi. Ders, sınavda çıkabilecek bir tablodan türev sorusuyla bitti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
