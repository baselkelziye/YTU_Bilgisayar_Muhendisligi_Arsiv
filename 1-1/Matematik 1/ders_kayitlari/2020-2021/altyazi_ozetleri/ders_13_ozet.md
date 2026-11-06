# Ders 13 Çalışma Özeti

## Genel Konular

- Ders, 21 Kasım 2020'deki 1. vize öncesi genel tekrar ve soru çözümüdür (general exercises).
- Parçalı fonksiyonda türevlenebilirlik (differentiability) ve parametre bulma.
- Türevin tanımını (limit definition of derivative) kullanmanın zorunlu olduğu durumlar.
- Kapalı türev (implicit differentiation): birinci ve ikinci mertebeden türev, teğet ve normal doğru.
- Tanım kümesi (domain) bulma: kök ve logaritma içeren, iç içe geçmiş fonksiyonlar.
- Bir fonksiyonun sabit olduğunu türevle göstermek.
- Ters fonksiyonun türevi (derivative of inverse function).
- Logaritmik türev (logarithmic differentiation).
- $1^\infty$ belirsizliği içeren limitler.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Vize tarihi:** 21 Kasım 2020 Cumartesi, saat 15.00. Sınav test (çoktan seçmeli) olacak. Süre en fazla 85-90 dakika, 120 dakika değil.
- **Sınav sistemi:** Sınava öğrenci sistemindeki sınav bağlantısından girilecek. Bağlantı sınava yakın aktif olacak.
- **Sınav konuları:** Logaritmik türev, limit, süreklilik, türevin tanımı, logaritmik limit, ters fonksiyonun türevi, kapalı fonksiyonun türevi, zincir kuralı (chain rule). İntegral sınavda yok.
- **Çıkma olasılıkları (hocanın tahmini):**
  - Ters fonksiyonun türevi: %85-95.
  - Logaritmik türev: %90.
  - Tanım kümesi soruları genelde vizede çıkar.
- **Çalışma önerisi:**
  - Ders notlarını ve ders videolarını çalışın.
  - Formül ezberlemeyin; formülün nereden geldiğini bilin.
  - Çok soru çözmek yerine mantığı kavrayın.
- **Ek kaynak:** Avesis'te paylaşılan, Pınar Hoca'nın derlediği geçmiş yıl soruları. Sorular Türkçe; İngilizce sürümü yok.
- **Ertesi ders (18 Kasım):** Geçen yılın test sınavı soruları çözülecek. Hoca bu derse mutlaka katılın diyor.

## Kısa Tekrar Notları

- Süreklilik, türevlenebilirliğin gerekli koşuludur.
- Parçalı fonksiyonda parçaları doğrudan türevlemek için iki koşul gerekir:
  - $f$, ayrım noktasında sürekli olmalı.
  - Her parça her yerde türevlenebilir olmalı.
- Bu koşullardan biri sağlanmazsa türevin tanımı kullanılır.
- Kapalı türevde $y$, $x$'e bağlıdır. $y^n$ türevlenirken zincir kuralı uygulanır: $\frac{d}{dx}y^n = n y^{n-1} y'$.
- Teğet doğru: $y-y_0=m_T(x-x_0)$. Normal doğrunun eğimi $m_N=-\frac{1}{m_T}$.
- Kök içi $\ge 0$, logaritma içi $>0$ olmalı.
- Sabit fonksiyonu göstermek için $f'(x)=0$ gösterilir. Sabit, özel bir $x$ değeri yerine koyularak bulunur.
- Ters fonksiyonun türevi: $(f^{-1})'(f(x_0))=\dfrac{1}{f'(x_0)}$.
- Logaritmik türev: iki tarafa $\ln$ uygula, sonra türev al: $\dfrac{y'}{y}=\dots$
- Taban da değişkense ($x^x$ gibi) mutlaka logaritmik türev kullanılır.
- Temel limit: $\displaystyle\lim_{u\to\infty}\left(1+\frac{a}{u}\right)^u=e^a$.

## Detaylı Açıklamalar

### Türevlenebilirlik ve Parametre Bulma

**Örnek 1.** $f(x)$ parçalı tanımlı: bir parçası $\sin 2x$, diğer parçası $mx$. $f$, $x=0$'da hangi $m$ için türevlenebilir?

- $f$, $x=0$'da süreklidir.
- $\sin 2x$ ve $mx$ her yerde türevlenebilir.
- Bu iki koşul sağlandığı için parçalar doğrudan türevlenebilir:

$$f'(0)\ \text{var} \iff (\sin 2x)'\big|_{x=0}=(mx)'\big|_{x=0}$$

- $2\cos 0 = m$. Sonuç: $m=2$.

**Örnek 2 (hocanın o an ürettiği soru).** $f(x)$ parçalı tanımlı: bir parçası $\arcsin(x^2-m)$, diğer parçası $x-\sqrt{m}$. $f$, $x=\sqrt{m}$'de türevlenebilir olsun. $m$ kaçtır?

- Arcsinüs her yerde türevlenebilir değildir. Bu yüzden parçalar doğrudan türevlenemez.
- Türevin tanımı kullanılır. $f(\sqrt m)=0$ alınır.
- Doğrusal parça tarafındaki türev 1'dir:

$$\lim \frac{x-\sqrt m-0}{x-\sqrt m}=1$$

- Arcsinüs parçası için pay ve payda $x+\sqrt m$ ile çarpılır (eşleniğiyle genişletme):

$$\lim_{x\to\sqrt m}\frac{\arcsin(x^2-m)}{x-\sqrt m}=\lim_{x\to\sqrt m}\frac{\arcsin(x^2-m)}{x^2-m}\,(x+\sqrt m)$$

- $u=x^2-m$ denirse $u\to 0$ ve $\dfrac{\arcsin u}{u}\to 1$ olur (L'Hôpital ile).
- Sonuç: $2\sqrt m = 1$, yani $m=\dfrac14$.

### Kapalı Türev

**Örnek 3.** $\cos(x+y^2)=y^3$ ise $\dfrac{dx}{dy}$ nedir?

- İki taraf $x$'e göre türevlenir:

$$-\sin(x+y^2)\,(1+2y\,y')=3y^2y'$$

- Buradan:

$$\frac{dy}{dx}=\frac{-\sin(x+y^2)}{3y^2+2y\sin(x+y^2)},\qquad \frac{dx}{dy}=-\frac{3y^2+2y\sin(x+y^2)}{\sin(x+y^2)}$$

- İkinci türev bölüm kuralıyla (quotient rule) bulunur. Hoca bunu ödev olarak bıraktı.

**Örnek 4.** $x\sec(xy-y^2)+2y^3=x^2+2$ eğrisinin $(1,1)$ noktasındaki teğet ve normal doğruları.

- $u=xy-y^2$ olsun. İki taraf $x$'e göre türevlenir:

$$\sec u + x\sec u\tan u\,(y+xy'-2yy')+6y^2y'=2x$$

- $(1,1)$'de $u=0$, $\sec 0=1$, $\tan 0=0$ olur: $1+6y'=2$.
- Teğetin eğimi $m_T=\dfrac16$, normalin eğimi $m_N=-6$.
- Teğet: $y-1=\dfrac16(x-1)$. Normal: $y-1=-6(x-1)$.
- Bir öğrenci kısmi türevli kısa yolu sordu. Hoca bunun gelecek dönemin (kısmi türevler) konusu olduğunu, bu dönem sorumlu olunmadığını söyledi.

**Örnek 5.** $x^3+y^3=1$ ise $\dfrac{d^2y}{dx^2}$ nedir?

- Birinci türev: $3x^2+3y^2y'=0$, yani $y'=-\dfrac{x^2}{y^2}$.
- Bölüm kuralı:

$$y''=-\frac{2x\,y^2-x^2\cdot 2y\,y'}{y^4}=-\frac{2x}{y^2}+\frac{2x^2}{y^3}\,y'$$

- $y'$ yerine konursa:

$$y''=-\frac{2x}{y^2}-\frac{2x^4}{y^5}=-\frac{2x(x^3+y^3)}{y^5}=-\frac{2x}{y^5}$$

- Son sadeleştirme $x^3+y^3=1$ kullanılarak yapıldı (hoca dersi sadeleştirmeden bıraktı).

**Örnek 6.** $r\cos 2s+\sin^2 s=\pi$ ise $\dfrac{dr}{ds}$ nedir?

- Burada $s$ bağımsız, $r$ bağımlı değişkendir.
- İki taraf $s$'ye göre türevlenir:

$$r'\cos 2s-2r\sin 2s+2\sin s\cos s=0$$

- $2\sin s\cos s=\sin 2s$ olduğundan:

$$r'=\frac{(2r-1)\sin 2s}{\cos 2s}=(2r-1)\tan 2s$$

### Tanım Kümesi

**Örnek 7.** $f(x)=\sqrt{x^2+2x}+\ln(x^2-2x)$ fonksiyonunun tanım kümesi.

- Kök için $x(x+2)\ge 0$: $D(f_1)=(-\infty,-2]\cup[0,\infty)$.
- Logaritma için $x(x-2)>0$: $D(f_2)=(-\infty,0)\cup(2,\infty)$.
- $D(f)=D(f_1)\cap D(f_2)=(-\infty,-2]\cup(2,\infty)$.
- $-2$ kümeye dahildir (kök sıfır olabilir). $2$ dahil değildir ($\ln 0$ tanımsız).

**Örnek 8.** $f(x)=\ln(\ln(x^2-1))$ fonksiyonunun tanım kümesi.

- İç logaritma için $x^2-1>0$: $(-\infty,-1)\cup(1,\infty)$.
- Dış logaritma için $\ln(x^2-1)>0$. İki tarafa $e^x$ uygulanır: $x^2-1>1$, yani $|x|>\sqrt2$.
- "Ve" bağlacı kesişim demektir: $D(f)=(-\infty,-\sqrt2)\cup(\sqrt2,\infty)$.

### Sabit Fonksiyon

**Örnek 9.** $f(x)=\arcsin\dfrac{1-x}{1+x}+2\arctan\sqrt x$ fonksiyonunun sabit olduğunu gösterin.

- Kullanılan türevler:
  - $(\arcsin u)'=\dfrac{u'}{\sqrt{1-u^2}}$
  - $(\arctan u)'=\dfrac{u'}{1+u^2}$
- $\left(\dfrac{1-x}{1+x}\right)'=\dfrac{-2}{(1+x)^2}$ ve $1-\left(\dfrac{1-x}{1+x}\right)^2=\dfrac{4x}{(1+x)^2}$.
- Birinci terimin türevi: $\dfrac{-2}{(1+x)^2}\cdot\dfrac{1+x}{2\sqrt x}=-\dfrac{1}{(1+x)\sqrt x}$.
- İkinci terimin türevi: $2\cdot\dfrac{1/(2\sqrt x)}{1+x}=\dfrac{1}{(1+x)\sqrt x}$.
- Toplam: $f'(x)=0$. Demek ki $f(x)=C$.
- Sabiti bulmak için $x=0$ konur: $f(0)=\arcsin 1+2\arctan 0=\dfrac{\pi}{2}$.

### Ters Fonksiyonun Türevi

**Örnek 10.** $f(x)=e^{\arctan x}$ ise $(f^{-1})'(e^{\pi/3})$ nedir?

- Formül: $(f^{-1})'(f(x_0))=\dfrac{1}{f'(x_0)}$. Bu formül ters fonksiyon özelliği ve zincir kuralından gelir.
- $f(x_0)=e^{\pi/3}$ ise $\arctan x_0=\dfrac{\pi}{3}$, yani $x_0=\tan\dfrac{\pi}{3}=\sqrt3$.
- $f'(x)=e^{\arctan x}\cdot\dfrac{1}{1+x^2}$, yani $f'(\sqrt3)=\dfrac{e^{\pi/3}}{4}$.
- Sonuç: $(f^{-1})'(e^{\pi/3})=\dfrac{4}{e^{\pi/3}}$.

### Logaritmik Türev

**Örnek 11.** $y=\sqrt{x+3}\,\sin x\,(x^2+2)$ ise $y'$ nedir?

- $\ln y=\dfrac12\ln(x+3)+\ln(\sin x)+\ln(x^2+2)$.
- Türev:

$$\frac{y'}{y}=\frac12\cdot\frac{1}{x+3}+\frac{\cos x}{\sin x}+\frac{2x}{x^2+2}=A,\qquad y'=y\cdot A$$

- **Ödev:** $y=\sqrt[3]{x^3+x}\cdot\sec(x^2+x)\cdot\arctan(\sqrt x+1)\cdot\arccos(\dots)$ için $\dfrac{dy}{dx}$. Son çarpanın argümanı tahtada tam okunmuyor ($x^4+1$ gibi duruyor).

**Örnek 12.** $y=(1+\ln x)^x$ ise $y'$ nedir?

- $\ln y=x\ln(1+\ln x)$.
- Türev:

$$\frac{y'}{y}=\ln(1+\ln x)+x\cdot\frac{1/x}{1+\ln x},\qquad y'=y\left[\ln(1+\ln x)+\frac{1}{1+\ln x}\right]$$

**Hocanın uyarısı (bir öğrencinin sorusu üzerine):**

- $a$ sabitse $y=a^x$ için $y'=a^x\ln a$.
- $y=x^x$'te taban değişkendir. "$y'=x^x\ln x$" yazmak büyük hatadır.
- Doğrusu: $\ln y=x\ln x$, buradan $y'=x^x(\ln x+1)$.

**Örnek 13.** $y=\sqrt[3]{\dfrac{x(x-2)}{x^2+1}}$ ise $y'$ nedir?

$$\frac{y'}{y}=\frac13\left[\frac1x+\frac{1}{x-2}-\frac{2x}{x^2+1}\right]$$

- Doğrudan türev almak (bölüm kuralı) çok uzun işlem getirir. Logaritma işi basitleştirir.

**Örnek 14 (hocanın ürettiği soru).** $\log_x(x^2+y)=y$ ise $y'$ nedir?

- Logaritmanın tanımından: $x^y=x^2+y$.
- İki tarafa $\ln$ uygulanır: $y\ln x=\ln(x^2+y)$.
- $x$'e göre türev:

$$y'\ln x+\frac{y}{x}=\frac{2x+y'}{x^2+y}$$

- Düzenlenirse:

$$y'\left(\ln x-\frac{1}{x^2+y}\right)=\frac{2x}{x^2+y}-\frac yx$$

- Sınavda genelde sadeleştirme istenmez. Belli bir noktadaki türev değeri, teğet ya da normal doğru sorulur.
- Hocaya göre logaritma için şu üç temel bilgi yeter:
  - $\log_a b=c \iff a^c=b$
  - $\ln(ab)=\ln a+\ln b$
  - $\ln\dfrac ab=\ln a-\ln b$

### $1^\infty$ Belirsizliği

**Örnek 15.** $\displaystyle\lim_{x\to\infty}\left(\frac{x+7}{x+3}\right)^{2x+3}$

- **1. yol (genel yöntem):**
  - $A$ ifadesine $\ln$ uygulanır.
  - $\ln A$'nın limiti $\dfrac00$ biçimine getirilir ve L'Hôpital uygulanır.
  - $\ln A\to 8$ bulunur, yani limit $e^8$.
- **2. yol (temel formül):**

$$\frac{x+7}{x+3}=1+\frac{4}{x+3},\qquad u=x+3$$

$$\left(1+\frac4u\right)^{u\cdot\frac{2x+3}{x+3}}\to \left(e^4\right)^2=e^8$$

**Örnek 16.** $\displaystyle\lim_{x\to\infty}\left(\frac{x}{x+3}\right)^{3x}$

- $\dfrac{x}{x+3}=1-\dfrac{3}{x+3}$ ve $u=x+3$ alınır.
- $\left(1-\dfrac3u\right)^u\to e^{-3}$ ve $\dfrac{3x}{x+3}\to 3$.
- Sonuç: $e^{-9}$.

### Ders sonrası notlar

- **Örnek 2:** Hoca $\dfrac{\arcsin u}{u}\to1$ için bir yerde "$\dfrac{\sin u}{u}$" dedi. Doğrusu arcsinüs limitidir; sonuç yine 1'dir.
- **Örnek 6:** Hoca önce $\cos 2s$'nin iç türevini (2 çarpanını) unuttu, öğrenci uyardı. Hoca düzeltmeyi öğrencilere bıraktı. Doğru sonuç yukarıdaki $r'=(2r-1)\tan 2s$'dir.
- **Örnek 10:** Hoca önce "$\arctan x_0=\dfrac\pi2$" dedi, sonra $x_0=\tan\dfrac\pi3=\sqrt3$ ile devam etti. Doğrusu $\dfrac\pi3$'tür.
- **Örnek 15:** Hoca 2. yolun sonunda önce "$e^4$" dedi, hemen "$e^8$" diye düzeltti. Doğru cevap $e^8$'dir.
- **Belirsizlik adı:** Altyazıda "indeterminate form" sık sık "in the terminat form" diye bozuk geçiyor. Aynı kavramdır.
- **Yoklama:** Ders sırasında hoca yoklama aldı (01:40-01:43). Öğrenci adları özete alınmadı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
