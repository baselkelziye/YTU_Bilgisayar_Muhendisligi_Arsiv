# Ders 14 Çalışma Özeti

**Tarih:** 11 Nisan 2023 (Salı)

## Genel Konular

- Yönlü türev (directional derivative): limit tanımı ve gradyanla hesap.
- Birim vektör (unit vector) yapma.
- Gradyanın anlamı: en hızlı artış, en hızlı azalış ve sıfır değişim yönleri.
- Gradyan için cebirsel kurallar.
- Uygulama soruları: iki doğrunun belirlediği düzlem, noktanın doğruya uzaklığı, noktanın düzleme uzaklığı, izdüşüm (projection).
- Çıkmış sınav soruları: en hızlı değişim yönleri, kuvvet serisinin yakınsaklık yarıçapı, kısmi türevin tanımla hesabı, yay uzunluğu, çok değişkenli limit.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yönlü türevden önce vektörün birim olup olmadığına bakın. "Burası çok çok önemli." Birim değilse boyuna bölün.
- Pratikte en çok kullanılan formül: $D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u$.
- Fonksiyon en hızlı $\nabla f$ yönünde artar, $-\nabla f$ yönünde azalır. Gradyana dik yönde değişim sıfırdır. Bu bilgiler şıklı soru olarak gelebilir.
- Çok değişkenli fonksiyonlarda limit sorusu mutlaka geliyor. Eksenler boyunca ve $y=mx$ doğruları boyunca bakın. Sonuç $m$'ye bağlıysa limit yoktur.
- Her konudan 10, 20, 30 soru çözün. Okuduğunuzu soruya dönüştürmezseniz kalıcı olmaz.
- Bir öğrenci Bologna sayfasındaki vize konularının güncel olup olmadığını sordu. Hoca matematikte güncel olduğunu, değişiklik olursa bildirileceğini söyledi.

## Kısa Tekrar Notları

- Birim vektör: $|\vec u|=\sqrt{u_1^2+u_2^2}=1$. Değilse $\vec u=\dfrac{\vec v}{|\vec v|}$.
- Limit tanımı: $D_{\vec u}f(P_0)=\displaystyle\lim_{s\to0}\frac{f(x_0+su_1,\;y_0+su_2)-f(x_0,y_0)}{s}$.
- Gradyanla: $D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u=|\nabla f|\cos\theta$.
- $D_{\vec i}f=f_x$, $D_{\vec j}f=f_y$, $D_{\vec k}f=f_z$.
- En büyük değişim: $\vec u=\dfrac{\nabla f}{|\nabla f|}$, değer $|\nabla f|$.
- En küçük değişim: $\vec u=-\dfrac{\nabla f}{|\nabla f|}$, değer $-|\nabla f|$.
- Sıfır değişim: $\vec u\perp\nabla f$.
- Gradyan kuralları:
  - $\nabla(f\pm g)=\nabla f\pm\nabla g$
  - $\nabla(kf)=k\nabla f$
  - $\nabla(fg)=f\nabla g+g\nabla f$
  - $\nabla\left(\dfrac fg\right)=\dfrac{g\nabla f-f\nabla g}{g^2}$
- Noktanın doğruya uzaklığı: $d=\dfrac{|\overrightarrow{QP}\times\vec v|}{|\vec v|}$.
- İzdüşüm: $\text{proj}_{\vec v}\vec u=\dfrac{\vec u\cdot\vec v}{|\vec v|^2}\,\vec v$.

## Detaylı Açıklamalar

### 1. Yönlü türevin tanımı

**Tanım:**
- $\vec u=u_1\vec i+u_2\vec j$ birim vektör olsun.
- $P_0(x_0,y_0)$'dan $\vec u$ yönünde giden doğru: $x=x_0+su_1$, $y=y_0+su_2$.
- $f$'nin $P_0$'da $\vec u$ yönündeki türevi, varsa, şu limittir:
  $$D_{\vec u}f(P_0)=\lim_{s\to0}\frac{f(x_0+su_1,\;y_0+su_2)-f(x_0,y_0)}{s}$$
- $\vec u=\vec i$ ise $f_x$, $\vec u=\vec j$ ise $f_y$ elde edilir.

**Örnek 1 (tanımla).** $f(x,y)=x^2+xy$, $P_0(1,2)$, $\vec u=\left(\tfrac{1}{\sqrt2},\tfrac{1}{\sqrt2}\right)$.
- $|\vec u|=1$, birim vektördür.
- $x=1+\tfrac{s}{\sqrt2}$, $y=2+\tfrac{s}{\sqrt2}$ yerine konup limit alınır.
- Sonuç: $D_{\vec u}f(1,2)=\dfrac{5}{\sqrt2}$.
- Kontrol: $\nabla f=(2x+y,\;x)=(4,1)$, $(4,1)\cdot\left(\tfrac1{\sqrt2},\tfrac1{\sqrt2}\right)=\tfrac5{\sqrt2}$.

**Birim vektör yapma.** $\vec v=\vec i+\vec j$ verilirse $|\vec v|=\sqrt2$ olur. Birim vektör: $\vec u=\tfrac1{\sqrt2}\vec i+\tfrac1{\sqrt2}\vec j$.

### 2. Gradyanla yönlü türev

**Teorem:** $f$, $P_0$'ı içeren bir bölgede türevlenebilirse
$$D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u.$$

**Örnek 2.** $f(x,y)=xy+x^2$, $P_0(1,2)$, $\vec v=3\vec i-4\vec j$.
- $|\vec v|=5$, birim değil. $\vec u=\left(\tfrac35,-\tfrac45\right)$.
- $f_x=y+2x=4$, $f_y=x=1$. $\nabla f(1,2)=(4,1)$.
- $D_{\vec u}f=4\cdot\tfrac35+1\cdot\left(-\tfrac45\right)=\tfrac{12}{5}-\tfrac45=\tfrac85$.

**Örnek 3 (kareden doğrulandı).** $f(x,y)=xe^y+\cos(xy)$, $(2,0)$ noktasında $\vec v=3\vec i-4\vec j$ yönünde türev.
- $\vec u=\tfrac35\vec i-\tfrac45\vec j$.
- $\nabla f=(e^y-y\sin xy)\,\vec i+(xe^y-x\sin xy)\,\vec j$.
- $\nabla f(2,0)=\vec i+2\vec j$.
- $D_{\vec u}f=\tfrac35-\tfrac85=-1$.

### 3. Gradyanın anlamı

**Özellikler:** $D_{\vec u}f=|\nabla f|\,|\vec u|\cos\theta=|\nabla f|\cos\theta$ ($|\vec u|=1$).
- $\theta=0$ ($\cos\theta=1$): $f$ en hızlı artar. Yön $\nabla f$, değer $|\nabla f|$.
- $\theta=\pi$ ($\cos\theta=-1$): $f$ en hızlı azalır. Yön $-\nabla f$, değer $-|\nabla f|$.
- $\theta=\pi/2$ ($\cos\theta=0$): değişim sıfırdır. $\nabla f\ne0$ ise gradyana dik her yön sıfır değişim yönüdür.
- Yönlü türev, o yöndeki artış ya da azalış hızıdır (değişim oranı).

**Örnek 4.** $f(x,y)=\tfrac{x^2}{2}+\tfrac{y^2}{2}$, $(1,1)$ noktası.
- $\nabla f=(x,y)=(1,1)$, $|\nabla f|=\sqrt2$.
- En çok artış: $\vec u=\left(\tfrac1{\sqrt2},\tfrac1{\sqrt2}\right)$, değer $\sqrt2$.
- En çok azalış: $\vec u=\left(-\tfrac1{\sqrt2},-\tfrac1{\sqrt2}\right)$, değer $-\sqrt2$.
- Sıfır değişim: $\vec u=\pm\left(\tfrac1{\sqrt2},-\tfrac1{\sqrt2}\right)$.

**Örnek 5.** $f(x,y,z)=x^3-xy^2-z$, $P_0(1,1,0)$, $\vec v=2\vec i-3\vec j+6\vec k$.
- $|\vec v|=\sqrt{4+9+36}=7$. $\vec u=\left(\tfrac27,-\tfrac37,\tfrac67\right)$.
- $\nabla f=(3x^2-y^2,\;-2xy,\;-1)=(2,-2,-1)$.
- $D_{\vec u}f=\tfrac47+\tfrac67-\tfrac67=\tfrac47$.
- En hızlı artış $\nabla f$ yönünde, hız $|\nabla f|=3$. En hızlı azalış $-\nabla f$ yönünde, hız $-3$.

**Örnek 6.** $f(x,y)=x^2-xy+y^2-y$, $(1,-1)$ noktası.
- $\nabla f=(2x-y,\;-x+2y-1)=(3,-4)$, $|\nabla f|=5$.
- En büyük yönlü türev 5, yön $\left(\tfrac35,-\tfrac45\right)$.
- En küçük yönlü türev $-5$, yön $\left(-\tfrac35,\tfrac45\right)$.
- Sıfır olması için $\vec u=(a,b)$: $3a-4b=0$ ve $a^2+b^2=1$. Sonuç $\vec u=\pm\left(\tfrac45,\tfrac35\right)$.

**Örnek 7 (kareden doğrulandı).** $f(x,y)=x^2y+e^{xy}\sin y$, $P_0(1,0)$'da en hızlı artış ve azalış yönleri.
- $\nabla f=(2xy+ye^{xy}\sin y)\,\vec i+(x^2+xe^{xy}\sin y+e^{xy}\cos y)\,\vec j$.
- $\nabla f(1,0)=2\vec j$.
- En hızlı artış: $\vec u=\vec j$. En hızlı azalış: $\vec u=-\vec j$.

**Örnek 8 (sınav sorusu, kareden doğrulandı).** $y\ne0$ için $f(x,y,z)=\dfrac xy-yz$. $f$, $P(4,1,1)$'de en hızlı hangi yönlerde değişir, hızları nedir?
- $\nabla f=\left(\tfrac1y,\;-\tfrac{x}{y^2}-z,\;-y\right)$.
- $\nabla f(P)=(1,-5,-1)$, $|\nabla f|=\sqrt{27}=3\sqrt3$.
- En hızlı artış $\vec i-5\vec j-\vec k$ yönünde, hız $3\sqrt3$.
- En hızlı azalış $-\nabla f$ yönünde, hız $-3\sqrt3$.

**Örnek 9 (fonksiyon verilmeden).** $f$'nin $P_0$'da $\vec i+\vec j$ yönündeki türevi $2\sqrt2$, $-2\vec j$ yönündeki türevi $-3$. $-\vec i-2\vec j$ yönündeki türevi nedir?
- $\nabla f(P_0)=(a,b)$ olsun.
- $\vec i+\vec j$ yönü: $\dfrac{a+b}{\sqrt2}=2\sqrt2\Rightarrow a+b=4$.
- $-2\vec j$ yönü: birim vektör $-\vec j$, $-b=-3\Rightarrow b=3$, $a=1$.
- $-\vec i-2\vec j$ yönü: $\vec u=\left(-\tfrac1{\sqrt5},-\tfrac2{\sqrt5}\right)$.
- $D_{\vec u}f=\dfrac{-1-6}{\sqrt5}=-\dfrac{7}{\sqrt5}$.

### 4. Gradyan kuralları

- Toplam ve fark: $\nabla(f\pm g)=\nabla f\pm\nabla g$.
- Sabitle çarpım: $\nabla(kf)=k\nabla f$.
- Çarpım: $\nabla(fg)=f\nabla g+g\nabla f$.
- Bölüm: $\nabla\left(\dfrac fg\right)=\dfrac{g\nabla f-f\nabla g}{g^2}$.
- Hoca bunları tek değişkenli türev kurallarına benzetti.
- Üç değişkende $\nabla f=f_x\vec i+f_y\vec j+f_z\vec k$ ve $D_{\vec u}f=f_xu_1+f_yu_2+f_zu_3$.

### 5. Vektör ve düzlem uygulamaları

**Örnek 10 (kareden doğrulandı).** $L_1:\ x=-1+t,\ y=2+t,\ z=1-t$ ve $L_2:\ x=1-4s,\ y=1+2s,\ z=2-2s$ doğrularının belirlediği düzlem.
- $\vec v_1=(1,1,-1)$, $\vec v_2=(-4,2,-2)$.
- Düzlemin normali iki vektöre de diktir: $\vec n=\vec v_1\times\vec v_2=(0,6,6)$.
- $(-1,2,1)$ noktası $L_1$ üzerindedir ($t=0$), dolayısıyla düzlem üzerindedir.
- Düzlem: $6(y-2)+6(z-1)=0\Rightarrow 6y+6z=18$, yani $y+z=3$.

**Örnek 11 (kareden doğrulandı).** $P(0,0,12)$ noktasının $L:\ x=4t,\ y=-2t,\ z=2t$ doğrusuna uzaklığı.
- $t=1$ için doğru üzerinde $Q(4,-2,2)$.
- $\overrightarrow{QP}=(-4,2,10)$, $\vec v=(4,-2,2)$.
- $d=|\overrightarrow{QP}|\sin\theta=\dfrac{|\overrightarrow{QP}\times\vec v|}{|\vec v|}$.
- $\overrightarrow{QP}\times\vec v=(24,48,0)$, $|\cdot|=24\sqrt5$, $|\vec v|=\sqrt{24}$.
- $d=\dfrac{24\sqrt5}{\sqrt{24}}=\sqrt{120}=2\sqrt{30}$.

**Örnek 12.** Bir $S$ noktasının $x+2y+2z=13$ düzlemine uzaklığı.
- Düzlemin normali $\vec n=(1,2,2)$.
- $y=z=0$ alınırsa düzlemde $(13,0,0)$ noktası bulunur.
- Uzaklık, bu noktadan $S$'ye giden vektörün $\vec n$ üzerine izdüşümünün boyudur.
- $S$ noktasının koordinatları altyazıda anlaşılmıyor; sayısal sonuç verilemedi.

**İzdüşüm.** $\vec u$'nun $\vec v$ üzerine izdüşümü: $\text{proj}_{\vec v}\vec u=\dfrac{\vec u\cdot\vec v}{|\vec v|^2}\vec v$. Derste çözülen sorunun vektörleri altyazıda geçmiyor.

### 6. Çıkmış sınav soruları

**Örnek 13 (2016 final, kareden doğrulandı).** $\displaystyle\sum_{n=2}^{\infty}\frac{b^nx^n}{\ln n}$ kuvvet serisinin yakınsaklık yarıçapının 3 olması için $b$?
- Genel terim $a_n=\dfrac{b^nx^n}{\ln n}$.
- Oran testi: $\displaystyle\lim_{n\to\infty}\left|\frac{a_{n+1}}{a_n}\right|=\lim_{n\to\infty}\frac{\ln n}{\ln(n+1)}\,|b|\,|x|=|b|\,|x|$.
- Yakınsaklık için $|b|\,|x|<1\Rightarrow|x|<\dfrac1{|b|}$.
- Yarıçap 3 ise $|b|=\tfrac13$, yani $b=\pm\tfrac13$.

**Örnek 14 (kısmi türev tanımla).** Bir parçalı fonksiyonun $(0,0)$'daki kısmi türevleri tanımdan hesaplandı.
- Sonuç: $f_x(0,0)=0$, $f_y(0,0)$ yok (limit $\tfrac10$ biçiminde tanımsız).
- Fonksiyonun kendisi altyazıda anlaşılmıyor.

**Diğer kısa sorular:**
- Hız soruları: üç değişkenli bir fonksiyonun yönlü türevi $\nabla f\cdot\vec u$ ile hesaplandı, sonuç 3. Fonksiyon altyazıda anlaşılmıyor.
- Yay uzunluğu (parametrik eğri, $-1\le t\le1$): $L=\displaystyle\int\sqrt{x'(t)^2+y'(t)^2}\,dt$ formülü hatırlatıldı. Eğri altyazıda anlaşılmıyor.
- Çok değişkenli limit: eksenler boyunca ve $y=mx$ boyunca yaklaşılır. Sonuç $m$'ye bağlıysa limit yoktur.

### Ders sonrası notlar

- **Örnek 8:** Hoca $|\nabla f|$ değerini sözlü olarak "3,43" ve "3,3" diye okudu. Doğrusu $3\sqrt3\approx5{,}196$; kareden doğrulandı.
- **Örnek 3:** Hoca bu örneği tahtada farklı bir fonksiyonla ($f=xy+x^2$, $(1,2)$ noktası, Örnek 2) yeniden çözdü. İki örnek ayrıdır: notta $f=xe^y+\cos(xy)$ ve sonuç $-1$, tahtadaki örnekte sonuç $\tfrac85$.
- **Örnek 10:** İki doğru $(-1,2,1)$ noktasında kesişir ($t=0$, $s=\tfrac12$). Bu yüzden tek bir düzlem belirlerler.
- **Örnek 11:** Doğru zaten orijinden geçer ($t=0$). $Q=(0,0,0)$ alınsa da aynı sonuç çıkar.
- 00:13 ile 00:20 arasında hoca boş tahtada çözüm yaptı; altyazıda bu kısım parçalı.
- Ders 00:33 ile 00:52 arasında mola var.

---

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
