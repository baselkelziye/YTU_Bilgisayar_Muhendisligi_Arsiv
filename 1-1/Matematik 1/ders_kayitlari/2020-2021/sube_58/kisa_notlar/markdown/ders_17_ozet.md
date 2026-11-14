# Ders 17 Çalışma Özeti

## Genel Konular

- 1. vizeden sonraki ilk ders (1 Aralık 2020).
- Konkavlık (concavity): yukarı bükümlü (concave up, convex) ve aşağı bükümlü (concave down).
- Büküm noktası (inflection point) ve sık yapılan yanlış tanım.
- Eğik asimptot (slant / oblique asymptote).
- Ters türev (antiderivative) ve belirsiz integral (indefinite integral).
- Belirsiz integralin "parça-bütün" felsefesi.
- Temel integral formülleri ve özellikleri.
- Diferansiyel bağıntılar (differential relations).
- Değişken dönüşümü / yerine koyma yöntemi (substitution method, change of variable).

## Hocanın Özellikle Vurguladığı Kısımlar

- **Sınav düzeni:**
  - Bu yıl iki vize ve bir final var (geçen yıl bir vize vardı).
  - 2. vize, 1. vizeden belirgin biçimde daha zor olacak. Birinci vize notuna güvenmeyin.
  - 2. vizede baştan sona sorumlusunuz. Ağırlık 1. vizeden sonraki konularda.
  - Rolle teoremi, ortalama değer teoremi ve konkavlık 2. vizenin konuları arasında.
- **Konkavlık soruları:** Grafik üzerinden yorum soruları gelir. Konkavlıkla birinci ve ikinci türev ilişkisini iyi anlayan, 2. vizede en az bir iki soruyu yapar.
- **Büküm noktası:** "$f''(x_0)=0$ ise $x_0$ büküm noktasıdır" ifadesi yanlıştır. Hocaya göre bazı öğretmenler ve YouTuber'lar bu hatayı yapıyor.
- **Bilimsel yöntem:** Bir mantıksal ifade örnekle doğrulanamaz, ama örnekle çürütülebilir.
- **İntegral sabiti:** Belirsiz integralde $+C$'yi unutmayın. Belirsiz integral bir kümedir; kümeyi $C$ oluşturur.
- **İntegral ve çarpım:** İntegral toplama ve çıkarma üzerine dağılır, çarpım üzerine dağılmaz.
- **Ezber:** Formülü önce nasıl çıktığını anlayarak öğrenin, sonra ezberleyin.

## Kısa Tekrar Notları

- $I$ aralığında $f''>0$ ise $f$ yukarı bükümlüdür (convex). $f'$ artandır, teğetler grafiğin altında kalır.
- $I$ aralığında $f''<0$ ise $f$ aşağı bükümlüdür. $f'$ azalandır, teğetler grafiğin üstünde kalır.
- Konkavlık, artanlık ve azalanlıktan bağımsızdır.
- Büküm noktası, $f''$'nin işaret değiştirdiği (konkavlığın değiştiği) noktadır.
- Eğik asimptot $y=mx+n$:

$$m=\lim_{x\to\infty}\frac{f(x)}{x},\qquad n=\lim_{x\to\infty}\big(f(x)-mx\big)$$

- Yatay asimptot, $m=0$ olan özel bir eğik asimptottur.
- $F'=f$ ise $F$, $f$'nin bir ters türevidir: $\displaystyle\int f(x)\,dx=F(x)+C$.
- Diferansiyel: $dF=F'(x)\,dx$.
- Yerine koyma: $\displaystyle\int f(u(x))\,u'(x)\,dx=\int f(u)\,du$.

## Detaylı Açıklamalar

### Konkavlık

**Tanım.** $f$, açık bir $I$ aralığında ikinci mertebeden türevlenebilir olsun.

- **Yukarı bükümlü (concave up / convex):** Her $x\in I$ için $f''(x)>0$.
- **Aşağı bükümlü (concave down / concave):** Her $x\in I$ için $f''(x)<0$.

**Geometrik anlam:**

- $x_1<x_2$ iken teğetlerin eğimleri $m_1=f'(x_1)$ ve $m_2=f'(x_2)$ olsun.
- Yukarı bükümlüde $m_1\le m_2$ olur. Yani $f'$ artandır, bu da $f''>0$ demektir.
- Yukarı bükümlüde her teğet grafiğin altında kalır.
- Aşağı bükümlüde $m_1>m_2$ olur. $f'$ azalandır, $f''<0$'dır. Her teğet grafiğin üstünde kalır.
- Hoca "concave up" için "yukarı bükümlü" terimini tercih ediyor.

**Örnekler:**

- **$y=x^2$:**
  - $(-\infty,0)$'da azalan, $(0,\infty)$'da artandır.
  - Her yerde yukarı bükümlüdür ($f''=2>0$).
  - Konkavlık, artanlıktan bağımsızdır.
- **$y=x^3$:**
  - $f''(x)=6x$.
  - $(-\infty,0)$'da aşağı, $(0,\infty)$'da yukarı bükümlüdür.
  - Fonksiyon iki aralıkta da artandır.

### Büküm Noktası

**Tanım.** İkinci türevin işaret değiştirdiği noktaya büküm noktası denir. Konkavlık bu noktada aşağıdan yukarıya ya da yukarıdan aşağıya değişir. Bu, büküm noktası için yeterli koşuldur.

**Yanlış tanım:** "$f''(x_0)=0 \Rightarrow x_0$ büküm noktasıdır."

- **Karşı örnek:** $f(x)=x^4$.
  - $f''(x)=12x^2$ ve $f''(0)=0$.
  - $f''$, 0'ın iki yanında da pozitiftir; işaret değişmez.
  - Bu yüzden 0 büküm noktası değildir.
- $y=x^3$'te ise 0 gerçekten büküm noktasıdır: solda aşağı, sağda yukarı bükümlü.

**Örnek 1.** $f(x)=x^3-4x^2$ fonksiyonunun büküm noktaları (fonksiyon altyazıdan doğrulanmıyor; büyük olasılıkla (ekrandan)).

- $f'(x)=3x^2-8x$, $f''(x)=6x-8$.
- $f''=0$ için $x=\dfrac43$.
- $x<\dfrac43$'te $f''<0$: aşağı bükümlü. $x>\dfrac43$'te $f''>0$: yukarı bükümlü.
- Konkavlık değiştiği için $x=\dfrac43$ büküm noktasıdır.
- Tahtadaki fonksiyonun devamı (varsa ek terimler) kareden tam okunmuyor. $f''$ hesabı yukarıdaki gibidir.

**Hocanın benzetmesi:**

- Bir doğruyu bir noktasından sabitleyin.
- Sağ tarafını yukarı, sol tarafını aşağı bükün.
- Sağ taraf yukarı bükümlü, sol taraf aşağı bükümlü olur.
- Sabitlenen nokta büküm noktasıdır.

### Eğik Asimptot

- $f(x)\approx mx+n$ ($x\to\infty$ iken) ise $y=mx+n$, $f$'nin sonsuzdaki eğik asimptotudur.
- İki taraf $x$'e bölünüp limit alınır: $m=\displaystyle\lim_{x\to\infty}\frac{f(x)}{x}$.
- $m$, fonksiyonun sonsuzdaki eğimidir.
- $m$ varsa $n=\displaystyle\lim_{x\to\infty}\big(f(x)-mx\big)$ hesaplanır.
- İki limit de varsa eğik asimptot vardır.
- Polinom bölmesi yalnız rasyonel fonksiyonlarda işe yarar. Limitli genel yöntem üstel ve logaritmik fonksiyonlarda da çalışır.

**Örnek 2.** $f(x)=\dfrac{x^2+1}{x+1}$ fonksiyonunun eğik asimptotu.

- $m=\displaystyle\lim_{x\to\infty}\frac{x^2+1}{x^2+x}=1$.
- $n=\displaystyle\lim_{x\to\infty}\left(\frac{x^2+1}{x+1}-x\right)=\lim_{x\to\infty}\frac{1-x}{x+1}=-1$.
- Eğik asimptot: $y=x-1$.
- **Polinom bölmesiyle kontrol:** $x^2+1=(x+1)(x-1)+2$. Bölüm $x-1$, kalan 2. Sonuç aynıdır.

**Ödev:** $y=x\,e^{-x}$ fonksiyonunun asimptotlarını inceleyin (fonksiyon altyazıdan doğrulanmıyor; büyük olasılıkla (ekrandan)).

- Bir öğrenci "oblique asymptote" ile aynı şey olup olmadığını sordu. Hoca evet dedi.

### Ters Türev ve Belirsiz İntegral

**Tanım.** $F$ türevlenebilir ve $F'=f$ ise $F$'ye $f$'nin bir ters türevi denir.

- **Örnek:** $f(x)=2x$ için $F_1=x^2$ ve $F_2=x^2+1$ ikisi de ters türevdir.
- Her $C$ için $x^2+C$ bir ters türevdir; sonsuz tane ters türev vardır.

**Belirsiz integral** $f$'nin bütün ters türevlerinin kümesidir:

$$\int f(x)\,dx=F(x)+C,\qquad F'(x)=f(x)$$

- $x$ integral değişkeni, $f$ ise integrant fonksiyondur (integrand).

**Hocanın "parça-bütün" felsefesi:**

- Bir nesnenin ölçülebilir bir niceliği $u$ olsun (kütle, ağırlık gibi). $u$ bütünü temsil eder.
- $du$, nesnenin yeterince küçük bir parçasının niceliğidir; $u$ ekseni boyunca yeterince küçük bir farktır.
- Türev / diferansiyel almak parçalamaktır: bütünden parçaya gidilir.
- İntegral almak parçaları toplamaktır: $\displaystyle\int du=u+C$. Parçalardan bütüne gidilir.
- $C$ bir öteleme parametresidir. Nesneyi ötelemek ölçülen niceliği değiştirmez. $u+C$'nin diferansiyeli yine $du$'dur.

### Temel Ters Türev Formülleri

- $\displaystyle\int u^n\,du=\frac{u^{n+1}}{n+1}+C$, $n\ne-1$.
- $\displaystyle\int\frac{du}{u}=\ln|u|+C$.
- $\displaystyle\int\cos u\,du=\sin u+C$.
- $\displaystyle\int\sin u\,du=-\cos u+C$.
- $\displaystyle\int\frac{du}{1+u^2}=\arctan u+C$, $\displaystyle\int\frac{-du}{1+u^2}=\operatorname{arccot}u+C$.
- $\displaystyle\int\frac{du}{\sqrt{1-u^2}}=\arcsin u+C$, $\displaystyle\int\frac{-du}{\sqrt{1-u^2}}=\arccos u+C$.
- $\displaystyle\int\frac{du}{u\sqrt{u^2-1}}=\operatorname{arcsec}u+C$ (kök içi pozitif olmalı: $u^2-1>0$).
- $\displaystyle\int\frac{-du}{u\sqrt{u^2-1}}=\operatorname{arccsc}u+C$.
- $\displaystyle\int e^u\,du=e^u+C$.
- $\displaystyle\int a^u\,du=\frac{a^u}{\ln a}+C$, $a>0$ ve $a\ne1$.

**Özellikler:**

- $\displaystyle\int (f\pm g)\,dx=\int f\,dx\pm\int g\,dx$.
- $\displaystyle\int c\,f(x)\,dx=c\int f(x)\,dx$, $c$ sabit.
- $\displaystyle\int f g\,dx\ne\int f\,dx\cdot\int g\,dx$. İntegral çarpım üzerine dağılmaz.

### Diferansiyel Bağıntılar

- $\dfrac{dF}{dx}=F'(x)$ olduğundan $dF=F'(x)\,dx$.
- Diferansiyellerin oranı türevi verir. Türev, yeterince küçük farkların oranıdır.

**Örnek 3.** $u=(x^2+10x)^{10}$ için diferansiyel bağıntı:

$$du=10(x^2+10x)^9(2x+10)\,dx$$

- Sol tarafın tam biçimi altyazıda bozuk geçiyor. Mantık aynıdır: sol taraf kendi değişkenine göre türevlenip $du$ ile, sağ taraf $x$'e göre türevlenip $dx$ ile çarpılır.
- Hoca önce iç türevi ($2x+10$) unuttu, bir öğrencinin uyarısıyla düzeltti.

**Örnek 4.** $\cos(t^2)+\sin t=x^2+10x$ için:

$$\big(-2t\sin(t^2)+\cos t\big)\,dt=(2x+10)\,dx$$

- Bir öğrenci türevden sonra neden $dt$, $dx$ yazıldığını sordu.
- Hocanın cevabı: İntegralde parçalarla ($dx$, $du$) çalışılır. Bütünün küçük parçası $dF=F'(x)\,dx$'tir.

### Yerine Koyma Yöntemi

$$\int f(u(x))\,u'(x)\,dx=\int f(u)\,du,\qquad du=u'(x)\,dx$$

- Sorulacak soru: "İntegrantın hangi parçasına $u$ dersem, diferansiyel bağıntı da integralin içinde bulunur?"
- Dönüşüm sonrası integral tamamen $u$ cinsinden yazılabiliyorsa dönüşüm doğrudur. Yazılamıyorsa ya işlem hatası vardır ya da dönüşüm yanlıştır.
- Yöntem her integrale doğrudan uygulanamaz. Bazen önce integrant uygun çarpanla genişletilmelidir.

**Örnek 5.** $\displaystyle\int (x^2+x)^{10}(2x+1)\,dx$

- $u=x^2+x$ ise $du=(2x+1)\,dx$.
- $\displaystyle\int u^{10}\,du=\frac{u^{11}}{11}+C=\frac{(x^2+x)^{11}}{11}+C$.
- $2x+1$'e $u$ denseydi işe yaramazdı.

**Örnek 6.** $\displaystyle\int\frac{\cos(\sqrt x+1)}{\sqrt x}\,dx$

- $u=\sqrt x+1$ ise $\dfrac{dx}{2\sqrt x}=du$, yani $\dfrac{dx}{\sqrt x}=2\,du$.
- $\displaystyle\int 2\cos u\,du=2\sin u+C=2\sin(\sqrt x+1)+C$.

**Örnek 7.** $\displaystyle\int\frac{\sqrt{\ln x+2}}{x}\,dx$

- $u=\ln x+2$ ise $du=\dfrac{dx}{x}$.
- $\displaystyle\int\sqrt u\,du=\frac23u^{3/2}+C=\frac23(\ln x+2)^{3/2}+C$.

**Örnek 8.** $\displaystyle\int\cos^{3/2}(e^x+1)\,\sin(e^x+1)\,e^x\,dx$

- **1. dönüşüm:** $u=e^x+1$, $du=e^x\,dx$. Sonuç: $\displaystyle\int\cos^{3/2}u\,\sin u\,du$.
- **2. dönüşüm:** $t=\cos u$, $dt=-\sin u\,du$. Sonuç: $\displaystyle-\int t^{3/2}\,dt$.
- **Sonuç:** $-\dfrac25t^{5/2}+C=-\dfrac25\cos^{5/2}(e^x+1)+C$.
- Bir öğrenci neden $\sin u=a$ seçilmediğini sordu. Hoca denetti: o dönüşüm daha karmaşık bir ifade verir, sadeleştirmez.

**Örnek 9.** $\displaystyle\int\tan x\,dx$

- $\tan x=\dfrac{\sin x}{\cos x}$ yazılır.
- $u=\cos x$ ise $du=-\sin x\,dx$.
- $\displaystyle-\int\frac{du}{u}=-\ln|\cos x|+C$.
- **Ödev:** $\displaystyle\int\cot x\,dx$.

**Örnek 10.** $\displaystyle\int\sec x\,dx$

- Doğrudan yerine koyma işe yaramaz. $u=x$ demek hiçbir şeyi değiştirmez.
- Pay ve payda $\sec x+\tan x$ ile çarpılır (genişletme):

$$\int\frac{\sec x(\sec x+\tan x)}{\sec x+\tan x}\,dx$$

- $u=\sec x+\tan x$ ise $du=(\sec x\tan x+\sec^2x)\,dx$. Bu tam paydır.
- Sonuç: $\displaystyle\int\frac{du}{u}=\ln|\sec x+\tan x|+C$.
- **Ödev:** $\displaystyle\int\csc x\,dx$. İpucu: $(\csc x)'=-\csc x\cot x$.

**Örnek 11.** $\displaystyle\int\frac{dx}{2x-3}$

- $u=2x-3$ ise $dx=\dfrac12du$.
- Sonuç: $\dfrac12\ln|2x-3|+C$.

**Örnek 12.** $\displaystyle\int\frac{dx}{\sqrt x\,\big(3-e^{-\sqrt x}\big)}$

- **1. dönüşüm:** $u=\sqrt x$, $\dfrac{dx}{\sqrt x}=2\,du$. Sonuç: $\displaystyle\int\frac{2\,du}{3-e^{-u}}$.
- **Genişletme:** Pay ve payda $e^u$ ile çarpılır. Sonuç: $\displaystyle\int\frac{2e^u\,du}{3e^u-1}$.
- **2. dönüşüm:** $t=e^u$, $dt=e^u\,du$. Sonuç: $\displaystyle\int\frac{2\,dt}{3t-1}$.
- **Sonuç:** $\dfrac23\ln|3t-1|+C=\dfrac23\ln\left|3e^{\sqrt x}-1\right|+C$.

### Ders sonrası notlar

- **Örnek 12:** Hoca bir ara "$2\cdot\frac12\ln|3t-1|$" yazdı, bir öğrenci katsayıyı sordu. $\displaystyle\int\frac{dt}{3t-1}=\frac13\ln|3t-1|$ olduğundan doğru katsayı $\dfrac23$'tür. Hoca da sonucu $\dfrac23$ olarak verdi.
- **Arccot:** Altyazıda $\displaystyle\int\frac{-du}{1+u^2}$ için sonuç bozuk geçiyor ("arctan u plus u"). Doğrusu $\operatorname{arccot}u+C$'dir. Bu, $-\arctan u+C$ ile aynı kümedir.
- **Arcsec:** Bazı kaynaklar $\displaystyle\int\frac{du}{|u|\sqrt{u^2-1}}=\operatorname{arcsec}|u|+C$ biçimini kullanır. Hocanın yazdığı biçim $u>1$ için geçerlidir.
- **Altyazı:** Büküm noktası ve yerine koyma bölümlerinde (yaklaşık 00:30, 01:58, 02:19) altyazı döngüye giriyor ya da Türkçe-İngilizce karışık bozuluyor. Bu yerler tahtadan tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
