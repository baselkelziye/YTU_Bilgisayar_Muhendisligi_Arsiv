# Ders 15 Çalışma Özeti

**Tarih:** 17 Nisan 2023 (Pazartesi)

## Genel Konular

- Yeni konuya (integral) geçmeden önce soru çözüm dersi.
- Hocanın özetine göre bu güne kadar işlenenler:
  - Seriler.
  - Eğriler ve uzunlukları.
  - Vektörler, doğru ve düzlem ilişkileri.
  - Çok değişkenli fonksiyonlarda tanım ve değer kümesi, limit, süreklilik, kısmi türev ve uygulamaları (maksimum ve minimum problemleri).
- Çözülen soru tipleri:
  - Yönlü türev ve en hızlı değişim.
  - İki doğrunun belirlediği düzlem, noktanın doğruya ve düzleme uzaklığı, izdüşüm.
  - Kısmi türevin tanımla hesabı.
  - Kuvvet serisinin yakınsaklık yarıçapı.
  - Seviye eğrisinin teğet vektörü ve gradyan.
  - Kesişim eğrisinin eğimi.
  - Uzay eğrisinin teğet doğrusu, yay uzunluğu, konum ve ivme arasındaki açı.
  - Tanım kümesi ve çok değişkenli limit.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yönlü türevde $\vec u$ mutlaka birim vektör olmalı. Değilse boyuna bölün. "Bu çok kıymetli."
- Yönlü türev soruları birinci vizede, ikinci vizede, finalde ve bütünlemede gelebilir.
- $\nabla f$ ile $|\nabla f|$ farklıdır. $\nabla f$ bir vektördür (yön). $|\nabla f|$ bir sayıdır (en büyük değişim hızı). Şıklarda bu ayrıma dikkat edin.
- Limit ve süreklilik sorusu hem vizede hem finalde "banko" geliyor.
- Test sınavında zamanla yarışılıyor. Hangi yöntemi iyi biliyorsanız onu kullanın.
- Bayram yaklaşıyor, zaman az. Konuları ve soruları günlük olarak bitirin.

## Kısa Tekrar Notları

- $D_{\vec u}f(P)=\nabla f(P)\cdot\vec u=|\nabla f|\cos\theta$.
- En büyük değer $|\nabla f|$ ($\theta=0$), en küçük değer $-|\nabla f|$ ($\theta=\pi$), sıfır değişim $\theta=\pi/2$.
- $|\nabla f|=\sqrt{f_x^2+f_y^2+f_z^2}$ (noktada hesaplanır).
- Düzlem: normal vektör + düzlemde bir nokta yeter. $\vec n\cdot\overrightarrow{P_0P}=0$.
- Noktanın düzleme uzaklığı: $d=\dfrac{|ax_0+by_0+cz_0+d|}{\sqrt{a^2+b^2+c^2}}$.
- Teğet vektör: $\vec r\,'(t)$. Teğet doğru: $x=x_0+at$, $y=y_0+bt$, $z=z_0+ct$, $(a,b,c)=\vec r\,'(t_0)$.
- Yay uzunluğu: $s=\displaystyle\int_a^b|\vec r\,'(t)|\,dt$.
- İki vektör arası açı: $\cos\theta=\dfrac{\vec u\cdot\vec v}{|\vec u||\vec v|}$.
- Limit yok testi: farklı yollar ($y=mx$, $y=mx^2$, eksenler) farklı sonuç veriyorsa limit yoktur.

## Detaylı Açıklamalar

### 1. Yönlü türev soruları

**Örnek 1.** $f(x,y)=x^2-xy+y^2-y$, $P(1,-1)$.
- $\nabla f=(2x-y,\;-x+2y-1)$, $\nabla f(1,-1)=(3,-4)$.
- (a) En büyük değer: $|\nabla f|=\sqrt{9+16}=5$. Yön $\vec u=\left(\tfrac35,-\tfrac45\right)$.
- (b) En küçük değer: $-5$. Yön $\vec u=\left(-\tfrac35,\tfrac45\right)$.
- (c) $D_{\vec u}f=0$ olan yönler. $\vec u=(a,b)$, $a^2+b^2=1$.
  - $3a-4b=0\Rightarrow a=\tfrac43b$.
  - $\tfrac{16}{9}b^2+b^2=1\Rightarrow b=\pm\tfrac35$, $a=\pm\tfrac45$.
  - $\vec u_1=\left(\tfrac45,\tfrac35\right)$, $\vec u_2=\left(-\tfrac45,-\tfrac35\right)$.

**Örnek 2.** Bir fonksiyonun gradyanı $\nabla f=2y\,\vec i+(2x-6y)\,\vec j$ biçiminde bulundu. $\vec v=3\vec i+4\vec j$ yönünde türev istendi.
- $|\vec v|=5$, birim vektör $\left(\tfrac35,\tfrac45\right)$.
- Sonuç altyazıda "$-4$" olarak geçiyor. Fonksiyon ve nokta altyazıda net değil.

**Örnek 3 (fonksiyon verilmeden).** $P_0$'da $\vec i+\vec j$ yönündeki türev $2\sqrt2$, $-2\vec j$ yönündeki türev $-3$. $-\vec i-2\vec j$ yönündeki türev?
- $\nabla f(P_0)=(a,b)$.
- $\dfrac{a+b}{\sqrt2}=2\sqrt2\Rightarrow a+b=4$.
- $-2\vec j$ yönünde birim vektör $(0,-1)$: $-b=-3\Rightarrow b=3$, $a=1$.
- $-\vec i-2\vec j$ yönünde: $\vec u=\left(-\tfrac1{\sqrt5},-\tfrac2{\sqrt5}\right)$, $D_{\vec u}f=\dfrac{-1-6}{\sqrt5}=-\dfrac7{\sqrt5}$.

**Örnek 4 (üç değişken).** $P(1,-1,2)$'de $\nabla f=(1,3,0)$ bulundu. $\vec v=(3,6,-2)$ yönünde türev.
- $|\vec v|=\sqrt{9+36+4}=7$, $\vec u=\left(\tfrac37,\tfrac67,-\tfrac27\right)$.
- $D_{\vec u}f=\tfrac37+\tfrac{18}7+0=3$.

**Örnek 5 (sınav sorusu).** $f(x,y,z)=\dfrac xy-yz$, $P(4,1,1)$.
- $\nabla f(P)=\vec i-5\vec j-\vec k$, $|\nabla f|=3\sqrt3$.
- En hızlı artış $\nabla f$ yönünde, hız $3\sqrt3$. En hızlı azalış $-\nabla f$ yönünde, hız $-3\sqrt3$.

**Örnek 6.** $f(x,y)=x^2y+e^{xy}\sin y$, $P_0(1,0)$: $\nabla f=2\vec j$. En hızlı artış $\vec j$, en hızlı azalış $-\vec j$ yönünde.

### 2. Doğru, düzlem ve uzaklık

**Örnek 7.** $L_1:\ x=-1+t,\ y=2+t,\ z=1-t$ ve $L_2:\ x=1-4s,\ y=1+2s,\ z=2-2s$ doğrularının belirlediği düzlem.
- $\vec n=\vec v_1\times\vec v_2=(1,1,-1)\times(-4,2,-2)=(0,6,6)$.
- $L_1$ üzerinde nokta: $(-1,2,1)$.
- $\vec n\cdot\overrightarrow{P_0P}=0$: $6(y-2)+6(z-1)=0\Rightarrow y+z=3$.

**Örnek 8.** $P(0,0,12)$ noktasının $L:\ x=4t,\ y=-2t,\ z=2t$ doğrusuna uzaklığı.
- $t=1$: $Q(4,-2,2)$. $\overrightarrow{QP}=(-4,2,10)$, $\vec v=(4,-2,2)$.
- $d=\dfrac{|\overrightarrow{QP}\times\vec v|}{|\vec v|}=\dfrac{24\sqrt5}{\sqrt{24}}=2\sqrt{30}$.
- Hoca, $d=|\overrightarrow{QP}|\sin\theta$ ile de hesaplanabileceğini söyledi.

**Örnek 9.** Bir $S$ noktasının $x+2y+2z=13$ düzlemine uzaklığı.
- Normal $\vec n=(1,2,2)$. Düzlemde nokta: $y=z=0$ için $(13,0,0)$.
- $d=|\overrightarrow{PS}|\cos\theta$, yani $\overrightarrow{PS}$'nin $\vec n$ üzerine izdüşümünün boyu.
- Formül: $d=\dfrac{|ax_0+by_0+cz_0-13|}{\sqrt{1+4+4}}$.
- $S$'nin koordinatları altyazıda anlaşılmıyor.

**İzdüşüm:** $\text{proj}_{\vec v}\vec u=\dfrac{\vec u\cdot\vec v}{|\vec v|^2}\vec v$. Derste sayısal veri okunmadı.

### 3. Kısmi türevin tanımla hesabı

**Tanım:**
- $f_x(0,0)=\displaystyle\lim_{h\to0}\frac{f(h,0)-f(0,0)}{h}$.
- $f_y(0,0)=\displaystyle\lim_{k\to0}\frac{f(0,k)-f(0,0)}{k}$.

**Örnek 10.** Küp köklü bir fonksiyon (altyazıdan büyük olasılıkla $f=\sqrt[3]{x^4+y^2}$).
- $f_x(0,0)=\lim\limits_{h\to0}\dfrac{h^{4/3}}{h}=\lim h^{1/3}=0$.
- $f_y(0,0)=\lim\limits_{k\to0}\dfrac{k^{2/3}}{k}=\lim k^{-1/3}$: yok.
- Sonuç: $f_x(0,0)=0$, $f_y(0,0)$ yok.
- Hoca, üslü yazıp türev almanın da mümkün olduğunu, ama paydaya düşen ifadelerde tanımla bakmak gerektiğini gösterdi.

**Örnek 11.** $f(x,y)=\sin\sqrt{x^2+y^4}$, $(0,0)$.
- $f_x(0,0)=\lim\limits_{h\to0}\dfrac{\sin|h|}{h}$. Sağdan $+1$, soldan $-1$. Limit yok, $f_x(0,0)$ yoktur.
- $f_y(0,0)=\lim\limits_{k\to0}\dfrac{\sin(k^2)}{k}=\lim\limits_{k\to0}k\cdot\dfrac{\sin(k^2)}{k^2}=0$.

### 4. Kuvvet serisi (2016 final)

**Örnek 12.** $\displaystyle\sum_{n=2}^{\infty}\frac{b^nx^n}{\ln n}$ serisinin yakınsaklık yarıçapı 3 ise $b$?
- Oran testi: $\lim\left|\dfrac{a_{n+1}}{a_n}\right|=|b|\,|x|<1\Rightarrow|x|<\dfrac1{|b|}$.
- $\dfrac1{|b|}=3\Rightarrow b=\pm\tfrac13$.
- Seri $n=2$'den başlar; $n=1$'de $\ln1=0$ payda olur.
- "Değerler toplamı" sorulursa cevap $0$.

### 5. Seviye eğrisi ve gradyan

**Örnek 13.** $f(x,y)=xy$ ($x,y>0$), $f=1$ seviye eğrisi $x=t$ ile parametrize ediliyor. $t=2$'de teğet vektörün gradyana dik olduğunu gösterin.
- $y=\tfrac1t$, $\vec r(t)=t\,\vec i+\tfrac1t\,\vec j$.
- Teğet: $\vec r\,'(t)=\vec i-\tfrac1{t^2}\vec j$, $\vec r\,'(2)=\vec i-\tfrac14\vec j$.
- Nokta $(2,\tfrac12)$. $\nabla f=(y,x)=\left(\tfrac12,2\right)$.
- $\vec r\,'(2)\cdot\nabla f=\tfrac12-\tfrac12=0$. Diktir.

**Örnek 14 (kareden doğrulandı).** $x=1$ düzlemi, $z=x^2+y^2$ paraboloidini bir parabolde keser. $(1,2,5)$'te parabolün teğetinin eğimi?
- $x$ sabit olduğu için eğim $\dfrac{\partial z}{\partial y}$'dir.
- $\dfrac{\partial z}{\partial y}=2y$, $(1,2,5)$'te $m=4$.
- Hoca, üç boyutta $x=1$'in bir doğru değil, bir düzlem olduğunu hatırlattı.

### 6. Uzay eğrileri

**Örnek 15 (kareden doğrulandı).** $\vec r(t)=\sin t\,\vec i+(t^2-\cos t)\,\vec j+e^t\,\vec k$, $t=0$'daki teğet doğru.
- $\vec r\,'(t)=\cos t\,\vec i+(2t+\sin t)\,\vec j+e^t\,\vec k$, $\vec r\,'(0)=(1,0,1)$.
- $t=0$'da nokta: $(0,-1,1)$.
- Teğet doğru: $x=t$, $y=-1$, $z=1+t$.

**Örnek 16 (kareden doğrulandı).** $\vec r(t)=\ln t\,\vec i+\dfrac{t-1}{t+2}\,\vec j+t\ln t\,\vec k$, $t=1$'deki teğet doğru.
- $\vec r\,'(t)=\tfrac1t\,\vec i+\dfrac{3}{(t+2)^2}\,\vec j+(\ln t+1)\,\vec k$.
- $\vec r\,'(1)=\left(1,\tfrac13,1\right)$. Nokta $(0,0,0)$.
- Teğet doğru: $x=t$, $y=\tfrac t3$, $z=t$.

**Örnek 17 (13.05.2017 2. vize, kareden doğrulandı).** $\vec r(t)=(1+t^2)^{3/2}\,\vec i+(3-t^2)^{3/2}\,\vec j+4t^2\,\vec k$ eğrisinin $-1\le t\le1$ arasındaki yay uzunluğu.
- $\vec r\,'(t)=\left(3t\sqrt{1+t^2},\;-3t\sqrt{3-t^2},\;8t\right)$.
- $|\vec r\,'(t)|=\sqrt{9t^2(1+t^2)+9t^2(3-t^2)+64t^2}=\sqrt{100t^2}=10|t|$.
- $s=10\displaystyle\int_{-1}^{0}(-t)\,dt+10\int_0^1t\,dt=5+5=10$ birim.

**Örnek 18 (sınav sorusu, kareden doğrulandı).** Cismin konumu $\vec r(t)=\cos t\,\vec i+\sin t\,\vec j+\sqrt3\,t\,\vec k$. Konum fonksiyonu ile ivme arasındaki açı ne zaman $\tfrac{2\pi}{3}$ olur?
- $\vec a(t)=\vec r\,''(t)=(-\cos t,\,-\sin t,\,0)$.
- $\vec r\cdot\vec a=-\cos^2t-\sin^2t=-1$.
- $|\vec r|=\sqrt{1+3t^2}$, $|\vec a|=1$.
- $\cos\tfrac{2\pi}{3}=-\tfrac12=\dfrac{-1}{\sqrt{1+3t^2}}\Rightarrow\sqrt{1+3t^2}=2\Rightarrow t=\pm1$.

### 7. Tanım kümesi ve limit

**Örnek 19.** $f(x,y)=\arccos\left(\dfrac{y}{x^2}\right)+\ln(1-x^2)$ fonksiyonunun tanım kümesi.
- $\arccos$ için $-1\le\dfrac{y}{x^2}\le1$ ve $x\ne0$: $-x^2\le y\le x^2$.
- $\ln$ için $1-x^2>0$: $-1<x<1$.
- Tanım kümesi: $\{(x,y):\ 0<|x|<1,\ -x^2\le y\le x^2\}$.
- Çizimde $y=x^2$ ve $y=-x^2$ parabolleri arasındaki bölge alınır. $x=\pm1$ doğruları kesikli çizilir (dahil değil).

**Örnek 20 (sınav sorusu, kareden doğrulandı).** $\displaystyle\lim_{(x,y)\to(1,1)}\frac{\sqrt{1+3x^2y^2}-2}{xy-1}$.
- $\tfrac00$ belirsizliği var. Eşleniğiyle çarp.
- Pay: $(1+3x^2y^2)-4=3(x^2y^2-1)=3(xy-1)(xy+1)$.
- Sadeleştir ($xy\ne1$): $\displaystyle\lim\frac{3(xy+1)}{\sqrt{1+3x^2y^2}+2}=\frac{3\cdot2}{4}=\frac32$.

**Örnek 21.** $(0,0)$'da $\tfrac00$ belirsizliği olan bir limit.
- $y=mx$ yolunda sonuç $m$'ye bağlı çıktı: limit yoktur.
- Eksenler boyunca ve $y=x$ boyunca farklı değerler ($\tfrac12$ gibi) de aynı sonucu verir.
- Fonksiyon altyazıda anlaşılmıyor.

**Yöntem:** Önce eksenler boyunca bakın. Aynı çıkarsa $y=mx$, $y=mx^2$ (gerekirse $y=mx^3$) yollarını deneyin. Sonuç $m$'ye bağlıysa limit yoktur. Kutupsal koordinatlar da kullanılabilir.

### Ders sonrası notlar

- **Örnek 7, derste yeniden çözüm:** Hoca düzlem denklemini tahtada yeniden kurarken "rastgele" bir nokta, $(1,2,3)$, ve öğrencilerden duyduğu bir normal, $(-1,1,2)$, kullandı. Bu nokta ve normal bu düzleme ait değildir. Doğru veriler $\vec n=(0,6,6)$ ve $(-1,2,1)$; sonuç $y+z=3$.
- **Örnek 18:** Notta $\vec r\,'(t)$ "$\vec u$" diye işaretlenmiş, ama hesap $\vec r(t)$ (konum) ile yapılmış. Soru konum ile ivme arasındaki açıyı istediği için hesap doğrudur.
- **Örnek 17:** Hoca sonucu "on bir" gibi okudu. Notta ve hesapta sonuç 10 birimdir.
- **Örnek 10:** Fonksiyon altyazıda bozuk geçiyor ("küp kök $x$ üzeri 4 artı $y$ kare"). Verilen sonuçlar ($f_x=0$, $f_y$ yok) bu fonksiyonla tutarlıdır.
- Dersin sonunda kapalı fonksiyon ve zincir kuralıyla "denklemin alacağı şekil" türü bir soruya başlandı. Hoca bunları ertesi gün çözeceğini söyledi.
- Ders 00:41 ile 00:53 ve 01:29 ile 01:47 arasında mola var.

---

İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
