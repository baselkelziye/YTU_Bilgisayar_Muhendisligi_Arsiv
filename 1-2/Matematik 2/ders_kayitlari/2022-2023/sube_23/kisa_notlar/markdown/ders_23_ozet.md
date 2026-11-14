# Ders 23 Çalışma Özeti

Tarih: 15 Mayıs 2023 (Pazartesi). Konular bitti. Ders, final hazırlığı için geçmiş yıl sınav sorularının (2017-2018 sınavları, uygulama föyü) ve hocanın tahtada kurduğu integral sorularının çözümüyle geçiyor.

## Genel Konular

- Kuvvet serisinin yakınsaklık aralığı, mutlak ve şartlı yakınsaklık.
- Serilerde karşılaştırma testi ve integral testi.
- Geometrik seriden $\arctan x$'in kuvvet serisini elde etme.
- Kutupsal koordinatlarda bölge çizimi ve iki eğri arasındaki alan.
- Parametrik ve kapalı tanımlı eğride teğet eğimi.
- Yönlü türevin (directional derivative) en büyük, en küçük ve sıfır olduğu yönler.
- İki doğrunun belirlediği düzlem.
- Tanımla kısmi türev, kuvvet serisinde parametre bulma, tanım kümesi, limit.
- Kapalı fonksiyonlarda kısmi türev (implicit differentiation).
- Kutupsal koordinatla iki katlı integral, integrasyon sırasını değiştirme, Jacobian ile dönüşüm.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aynı soru testte farklı biçimlerde gelir: "aralığı bulunuz", "hangileri doğrudur", "hangi adımlar izlenmelidir", "integrasyon bölgesi hangisidir".
- Kutupsal-kartezyen dönüşümünü bilmek grafik çizimini çok kolaylaştırır. $r=4\sin\theta$ gibi eğriler mutlaka çizilebilmeli.
- Kutupsal koordinata geçerken Jacobian $r$'yi unutmayın.
- $e^{x^2}$ gibi integrali alınamayan fonksiyonlarda çıkış yolu integrasyon sırasını değiştirmektir.
- Final için: en az bir bölge dönüşümü (Jacobian) sorusu, bir kutupsal koordinat sorusu, bir integrasyon sırası değiştirme sorusu gelir. Ayrıca limit, kısmi türev ve zincir kuralından soru gelir.
- Ertesi ders: Taylor ile yaklaşık hesap, maksimum-minimum problemleri, kısmi türev uygulamaları.

## Kısa Tekrar Notları

- Oran testi: $\lim\left|\dfrac{u_{n+1}}{u_n}\right|<1$ ise yakınsak. Uç noktalar ayrıca denenir.
- $p$-serisi $\sum\dfrac{1}{n^p}$: $p>1$ yakınsak, $p\le1$ ıraksak.
- Seri yakınsak ama mutlak değerlerin serisi ıraksaksa: şartlı yakınsak (conditionally convergent).
- İntegral testi: $f$ pozitif, sürekli, azalan ise $\sum f(n)$ ile $\int_1^\infty f(x)\,dx$ aynı karakterdedir. Değerleri eşit değildir.
- $\dfrac{1}{1-x}=\sum x^n$, $|x|<1$.
- $D_{\vec u}f=\nabla f\cdot\vec u$ ($\vec u$ birim). En büyük değer $|\nabla f|$, en küçük $-|\nabla f|$, sıfır ise $\vec u\perp\nabla f$.
- Kapalı fonksiyon: $F(x,y,z)=0$ ise $z_x=-\dfrac{F_x}{F_z}$, $z_y=-\dfrac{F_y}{F_z}$.
- Kutupsal dönüşüm: $dA=r\,dr\,d\theta$.

## Detaylı Açıklamalar

### Örnek 1 (2017-2018 final): Kuvvet serisi

- Hoca 00:02:09'da bu sorunun "finalde çıkmış" olduğunu söylüyor.

- Seri: $\displaystyle\sum_{n=1}^\infty(-1)^n\frac{(x-3)^n}{2^n\sqrt[3]{n^2+5}}$. Hangi $x$ için mutlak yakınsak, şartlı yakınsak, ıraksak?
- Oran testi: $\lim\left|\dfrac{u_{n+1}}{u_n}\right|=\dfrac12|x-3|<1 \Rightarrow 1<x<5$.
- $x=1$: $(x-3)^n=(-2)^n$, işaretler sadeleşir: $\displaystyle\sum\frac{1}{\sqrt[3]{n^2+5}}$. $\sum\dfrac{1}{n^{2/3}}$ ile limit karşılaştırması: limit 1. $p=\tfrac23<1$ olduğu için ıraksak.
- $x=5$: $\displaystyle\sum\frac{(-1)^n}{\sqrt[3]{n^2+5}}$. Alterne seri, terimler azalarak sıfıra gidiyor: yakınsak. Mutlak değerlerin serisi ıraksak: şartlı yakınsak.
- Sonuç:
  - $1<x<5$: mutlak yakınsak.
  - $x=5$: şartlı yakınsak.
  - Yakınsaklık aralığı $(1,5]$.
  - $x\le1$ veya $x>5$: ıraksak.

### Örnek 2 (2017-2018 1. vize, 2-a): Serilerin karakteri

- (i) Büyük olasılıkla (ekrandan) $\displaystyle\sum\frac{n^2\sin\frac1n}{\sqrt{n^2+n+1}}$: harmonik seri $\sum\frac1n$ ile karşılaştırma. $\lim\dfrac{a_n}{1/n}=\infty$ ve $\sum\frac1n$ ıraksak, verilen seri ıraksak.
- (ii) $\displaystyle\sum\frac{1}{n(1+\ln n)}$: integral testi. $u=1+\ln x$ ile $\displaystyle\int_1^\infty\frac{dx}{x(1+\ln x)}=\lim_{b\to\infty}\ln(1+\ln b)=\infty$. Seri ıraksak.
- Hoca: genel terimin limiti sıfırdan farklıysa seri doğrudan ıraksaktır. Limit sıfırsa başka test gerekir.

### Örnek 3: $\arctan x$'in kuvvet serisi

- $(\arctan x)'=\dfrac{1}{1+x^2}$.
- $\dfrac{1}{1-x}=\sum x^n$ serisinde $x$ yerine $-x^2$: $\dfrac{1}{1+x^2}=\sum(-1)^n x^{2n}$.
- Terim terim integral: $\arctan x=\sum\dfrac{(-1)^n x^{2n+1}}{2n+1}+C$. $x=0$ koyunca $C=0$.

### Örnek 4: Kutupsal bölge

- $\theta=-\tfrac{2\pi}{3}$, $-1\le r<2$ kümesi: başlangıçtan geçen doğru parçası. $r$ negatifken nokta ters yöne düşer.
- Hoca: 2 dahil değil, $-1$ dahil.

### Örnek 5: İki eğri arasındaki alan (kutupsal)

- Bölge: $r=2$ çemberinin dışında, $r=4\sin\theta$ çemberinin içinde, $r\sin\theta=3$ ($y=3$ doğrusu) ile sınırlı.
- $r=4\sin\theta$: $x^2+(y-2)^2=4$, merkez $(0,2)$, yarıçap 2.
- Kesişimler: $4\sin\theta=2 \Rightarrow \theta=\tfrac\pi6$. $4\sin^2\theta=3 \Rightarrow \theta=\tfrac\pi3$.
- Simetri ile sağ yarı alınıp 2 ile çarpılır:
  $$A=2\left[\frac12\int_{\pi/6}^{\pi/3}\left(16\sin^2\theta-4\right)d\theta+\frac12\int_{\pi/3}^{\pi/2}\left(\frac{9}{\sin^2\theta}-4\right)d\theta\right]$$
- Hoca integrali kurdu, sonucu hesaplamadı. Sonuç: $A=3\sqrt3$.

### Örnek 6 (2017-2018 1. vize, 4-b): Parametrik eğim

- $t^2\sin x+x^3=e^t$, $y=t\sin t-2t$. $t=0$'daki teğet eğimi.
- $t=0 \Rightarrow x=1$, $y=0$.
- Türev: $2t\sin x+t^2\cos x\,\dfrac{dx}{dt}+3x^2\dfrac{dx}{dt}=e^t \Rightarrow 3\dfrac{dx}{dt}=1 \Rightarrow \dfrac{dx}{dt}=\tfrac13$.
- $\dfrac{dy}{dt}=\sin t+t\cos t-2 \Rightarrow -2$.
- $\dfrac{dy}{dx}=\dfrac{-2}{1/3}=-6$.

### Örnek 7 (7. uygulama föyü): Yönlü türevin uç değerleri

- $(1,-1)$ noktasında büyük olasılıkla (ekrandan) $\nabla f=\langle3,-4\rangle$, $|\nabla f|=5$.
- En büyük yönlü türev $5$ ($\nabla f$ yönünde). En küçük $-5$ (ters yönde).
- Sıfır olması için $\vec u=a\vec i+b\vec j$, $a^2+b^2=1$ ve $3a-4b=0$.
- $a=\tfrac43b \Rightarrow \tfrac{25}{9}b^2=1 \Rightarrow b=\pm\tfrac35$, $a=\pm\tfrac45$.
- $\vec u_1=\tfrac45\vec i+\tfrac35\vec j$, $\vec u_2=-\tfrac45\vec i-\tfrac35\vec j$.

### Örnek 8: İki doğrunun belirlediği düzlem

- Doğrultu vektörleri $\vec v_1=\langle1,1,-1\rangle$, $\vec v_2=\langle-4,2,-2\rangle$.
- Normal: $\vec n=\vec v_1\times\vec v_2=\langle0,6,6\rangle$.
- Nokta $P(-1,2,1)$: $6(y-2)+6(z-1)=0 \Rightarrow y+z=3$.

### Örnek 9: Yönlü türev, birim olmayan vektör

- $\vec u=\langle4,3\rangle$, $|\vec u|=5\ne1$. Birim vektör $\vec v=\langle\tfrac45,\tfrac35\rangle$.
- $D_{\vec v}f=f_x\cdot\tfrac45+f_y\cdot\tfrac35$ (fonksiyon altyazıda anlaşılmıyor).
- En hızlı artış $\nabla f$, en hızlı azalış $-\nabla f$ yönündedir.

### Örnek 10: Tanımla kısmi türev

- $f(x,y)=\sqrt[3]{x^4+y^2}$.
- $f_x(0,0)=\lim_{h\to0}\dfrac{\sqrt[3]{h^4}}{h}=\lim h^{1/3}=0$.
- $f_y(0,0)=\lim_{k\to0}\dfrac{\sqrt[3]{k^2}}{k}=\lim k^{-1/3}$: limit yok, $f_y(0,0)$ mevcut değil.

### Örnek 11: Yakınsaklık yarıçapı ile parametre

- Oran testinden yakınsaklık yarıçapı $R=\dfrac{1}{|b|}$ bulunuyor (seri altyazıda tam anlaşılmıyor).
- $R=3 \Rightarrow |b|=\tfrac13 \Rightarrow b=\pm\tfrac13$. Değerler toplamı 0.

### Örnek 12: Yay uzunluğu ve konum-ivme açısı

- Yay uzunluğu (eğri büyük olasılıkla (ekrandan)): $\vec r(t)=(1+t^2)^{3/2}\vec i+(3-t^2)^{3/2}\vec j+4t^2\vec k$, $-1\le t\le1$.
  - $|\vec r\,'(t)|=10|t|$, $s=10$ birim.
- Konum-ivme açısı (eğri büyük olasılıkla (ekrandan)): $\vec r(t)=\cos t\,\vec i+\sin t\,\vec j+\sqrt3\,t\,\vec k$.
  - $\vec r\cdot\vec a=-1$, $|\vec r|=\sqrt{1+3t^2}$, $|\vec a|=1$.
  - $\cos\tfrac{2\pi}3=-\tfrac12 \Rightarrow \sqrt{1+3t^2}=2 \Rightarrow t=\pm1$.
- Bu iki soru ders 15'te de çözülmüştü. Değerler oradaki sonuçlarla aynıdır; ifadeler büyük olasılıkla (ekrandan).

### Örnek 13: Tanım kümesi

- $f(x,y)=\arccos\dfrac{y}{x^2}+\ln(1-x^2)$.
- $\arccos$ için $-1\le\dfrac{y}{x^2}\le1$, yani $-x^2\le y\le x^2$ ($x\ne0$).
- $\ln$ için $1-x^2>0$, yani $-1<x<1$.
- Tanım kümesi: $\{(x,y): -1<x<1,\ x\ne0,\ -x^2\le y\le x^2\}$. Grafik iki parabol arasında, $x=\pm1$ ile sınırlı.

### Örnek 14: Limit

- Köklü ifadede $\tfrac00$ belirsizliği: pay ve payda eşlenikle çarpılır, sadeleşir.
- İki değişkenli limitte eksenler boyunca yaklaşmak yetmez. $y=mx$ veya $y=mx^2$ boyunca yaklaşılır. Sonuç $m$'ye bağlıysa limit yok, değilse limit adayıdır.

### Örnek 15: Kapalı fonksiyon

- $G(2x-z^2)=y-\dfrac{z^3}{3}$ ($z$, $x$ ve $y$'nin sabit olmayan fonksiyonu). İstenen: $z_x+z\,z_y$.
- $F(x,y,z)=G(2x-z^2)-y+\dfrac{z^3}{3}=0$.
- $F_x=2G'$, $F_y=-1$, $F_z=-2zG'+z^2$.
- $z_x=-\dfrac{2G'}{z^2-2zG'}$, $z_y=\dfrac{1}{z^2-2zG'}$.
- $z_x+z\,z_y=\dfrac{z-2G'}{z(z-2G')}=\dfrac1z$.

### Örnek 16: Kutupsal koordinatla integral

- $D$: $x^2+y^2=16$ çemberi, $y=x$ ve $y=0$ ile sınırlı birinci bölge parçası.
- $\displaystyle\iint_D\frac{1}{\sqrt{x^2+y^2}}\,dA=\int_0^{\pi/4}\int_0^4\frac1r\,r\,dr\,d\theta=4\cdot\frac\pi4=\pi$.
- Varyasyonlar:
  - $2\le r\le4$ alınırsa (iki çember arası halka parçası) sonuç $\tfrac\pi2$.
  - $0\le\theta\le\arctan\tfrac43$, $\tfrac{3}{\cos\theta}\le r\le5$: $x=3$ doğrusu ile $r=5$ çemberi arasındaki bölge.

### Örnek 17: İntegrasyon sırasını değiştirme

- Tahtadaki integral: $\displaystyle\int_0^3\int_0^{3y}e^{x^2}\,dx\,dy$.
- $\int e^{x^2}\,dx$ temel fonksiyonlarla alınamaz. Sıra değiştirilir.
- Bölge: $0\le y\le3$, $0\le x\le3y$. Sıra değişince: $0\le x\le9$, $\tfrac x3\le y\le3$.
- Hoca: aynı soru üç biçimde gelebilir: integrali hesaplayınız, integrasyon bölgesi hangisidir, hangi adımlar izlenmelidir.

### Örnek 18: Jacobian ile dönüşüm

- Bölge birinci bölgede: $x^2-y^2=1$, $x^2-y^2=3$, $xy=1$, $xy=2$ eğrileri arası.
- $u=x^2-y^2$ ($1\le u\le3$), $v=xy$ ($1\le v\le2$). Yeni bölge dikdörtgen.
- $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}2x&-2y\\y&x\end{vmatrix}=2(x^2+y^2)$, yani $dA=\dfrac{du\,dv}{2(x^2+y^2)}$.
- İntegrand $x^2+y^2$ olursa sadeleşir: $\displaystyle\iint_D(x^2+y^2)\,dA=\int_1^3\int_1^2\frac12\,dv\,du=1$.

### Ders sonrası notlar

- Örnek 7'de föyde $\vec u_1$ yazımı büyük olasılıkla (ekrandan) "$-\tfrac35\vec j+\tfrac45\vec i$" gibi görünüyor. $3a-4b=0$ koşulundan $a$ ile $b$ aynı işaretlidir. Doğru vektörler $\pm\left(\tfrac45\vec i+\tfrac35\vec j\right)$.
- Örnek 8'de hoca $\overrightarrow{P_0P}$'yi önce "$x+2$" diye yazdı, sonra $x+1$ diye düzeltti.
- Örnek 12'de hoca yay uzunluğunu "11" gibi okudu. Doğrusu 10 birim.
- Örnek 13'te $x\ne0$ koşulu derste söylenmedi. $\dfrac{y}{x^2}$ ifadesi $x=0$'da tanımsız olduğu için bu koşul da gerekir.
- Örnek 17'de tahtadaki sınırlarla sıra değişince $\int_0^9\left(3-\tfrac x3\right)e^{x^2}dx$ çıkar. $3e^{x^2}$ kısmı yine temel fonksiyonlarla alınamaz. Soru $\displaystyle\int_0^3\int_{3y}^{9}e^{x^2}\,dx\,dy$ olmalıdır. O zaman $\displaystyle\int_0^9\frac x3e^{x^2}\,dx=\frac{e^{81}-1}{6}$ çıkar.
- Örnek 18'de hoca integrandı bir yerde "$\tfrac{1}{x^2-y^2}$", tahtada "$\tfrac{1}{x^2+y^2}$" olarak söylüyor ve sonucu "5" gibi okuyor. Jacobian $\dfrac{1}{2(x^2+y^2)}$ olduğu için $\tfrac{1}{x^2+y^2}$ integrandı sadeleşmez. Sadeleşen ve standart olan soru $\iint(x^2+y^2)\,dA=1$'dir.
- Örnek 15'te soru $G$ fonksiyonu ile kapalı tanımlı. Hocanın tahtada bulduğu $\dfrac1z$ sonucu doğrudur.
- 00:34:21-00:47:29 ve 01:29:01-01:39:06 arası mola.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
