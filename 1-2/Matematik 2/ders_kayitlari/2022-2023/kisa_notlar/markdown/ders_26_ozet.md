# Ders 26 Çalışma Özeti

## Genel Konular

- Ders 23 Mayıs 2023 Salı günü yapıldı. Final hazırlığı olarak çok değişkenli fonksiyonlar üzerine çalışma soruları çözüldü.
- Ekranda paylaşılan dosya: "8-çdf-çalışma soruları cevaplar" (9 sayfa).
- Konular:
  - Zincir kuralı (chain rule) ile kısmi türev (partial derivative) ve gradyan (gradient).
  - Teğet düzlem (tangent plane) ve normal doğru (normal line).
  - Lineerleştirme (linearization) ve diferansiyelle yaklaşık değer.
  - Tam diferansiyel (total differential) ile hacim değişimi.
  - Yönlü türev (directional derivative): yaklaşık değer, en büyük ve en küçük değer.
  - Yerel ekstremumlar (local extrema) ve eyer noktası (saddle point): ikinci türev testi.
  - İki yüzey arasındaki kesişim açısı.
- Dersin sonunda (yaklaşık 01:17-01:41) Eğitim Fakültesi'nden bir doçent (Hülya Hoca) ve yüksek lisans öğrencisi derse katıldı. Mühendislik öğrencilerinin matematiğe yönelik tutum ve motivasyonu üzerine bir tez anketi tanıttılar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu konulardan finalde mutlaka en az bir soru geliyor. Yerel maksimum ve minimum sorusu da kesin geliyor.
- Teğet düzlem ve normal doğru birlikte de, ayrı ayrı da sorulabilir. İkisini de bilmek gerekiyor.
- Önce yüzeyi kapalı biçime getirin: $F(x,y,z)=0$. $\nabla F$ yüzeye dik (normal) vektördür.
- Noktanın $z_0$ değerini fonksiyondan hesaplamayı unutmayın.
- Yönlü türevin en büyük değeri $|\nabla f|$, en küçük değeri $-|\nabla f|$'dir. İkisi tam zıt işaretli olmalı.
- Kritik nokta sayısında hata yapmayın. Örneğin 2 tane varken 3 bulmak yanlış şıkka götürür.
- "Burası bir bilim atölyesi. Takıldığınız yeri rahatça sorun."

## Kısa Tekrar Notları

- Zincir kuralı: $f(u,v)$, $u=u(x,y,z)$, $v=v(x,y,z)$ ise $\dfrac{\partial f}{\partial x}=f_u\,u_x+f_v\,v_x$.
- Gradyan: $\nabla F=\left\langle F_x,F_y,F_z\right\rangle$.
- Teğet düzlem: $F_x(P)(x-x_0)+F_y(P)(y-y_0)+F_z(P)(z-z_0)=0$.
- Normal doğru: $\dfrac{x-x_0}{F_x}=\dfrac{y-y_0}{F_y}=\dfrac{z-z_0}{F_z}$, ya da $x=x_0+F_x t$, $y=y_0+F_y t$, $z=z_0+F_z t$.
- Lineerleştirme: $L(x,y)=f(x_0,y_0)+f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$.
- Diferansiyel ile yaklaşık değer: $f(a+\Delta x,\,b+\Delta y)\approx f(a,b)+f_x\Delta x+f_y\Delta y$.
- Tam diferansiyel: $dV=V_x\,dx+V_y\,dy+V_z\,dz$.
- Yönlü türev: $D_{\vec u}f=\nabla f\cdot\vec u$, $\vec u$ birim vektör olmalı.
- İkinci türev testi: $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$.
  - $B^2-AC<0$ ve $A<0$: yerel maksimum.
  - $B^2-AC<0$ ve $A>0$: yerel minimum.
  - $B^2-AC>0$: eyer noktası.
  - $B^2-AC=0$: test karar vermez.
- İki yüzeyin kesişim açısı, gradyanları arasındaki açıdır: $\cos\theta=\dfrac{\nabla F\cdot\nabla G}{|\nabla F|\,|\nabla G|}$.

## Detaylı Açıklamalar

### Zincir Kuralı Soruları

**Örnek 1.** $f(x-y,\;y-z,\;z-x)$ için $f_x+f_y$ nedir?

- $u=x-y$, $v=y-z$, $w=z-x$ de.
- $u_x=1$, $v_x=0$, $w_x=-1$, bu yüzden $f_x=f_u-f_w$.
- $u_y=-1$, $v_y=1$, $w_y=0$, bu yüzden $f_y=-f_u+f_v$.
- Topla: $f_x+f_y=f_v-f_w$. Cevap D şıkkı.

**Örnek 2 (soru 18).** Büyük olasılıkla (ekrandan) $f(4,2)=2023$, $f_u(4,2)=4$, $f_v(4,2)=2$ veriliyor. $g(x,y,z)=f\left(y^2+zx,\;2y-2z^2+3x\right)$ için $\nabla g(0,2,1)$ nedir?

- $u=y^2+zx$, $v=2y-2z^2+3x$. $(0,2,1)$ noktasında $u=4$, $v=2$, yani $f$'nin türevleri $(4,2)$'de alınır.
- Kısmi türevler:

  | Türev | Zincir kuralı | $(0,2,1)$'deki değer |
  |---|---|---|
  | $g_x$ | $f_u\cdot z+f_v\cdot3$ | $4\cdot1+2\cdot3=10$ |
  | $g_y$ | $f_u\cdot2y+f_v\cdot2$ | $4\cdot4+2\cdot2=20$ |
  | $g_z$ | $f_u\cdot x+f_v\cdot(-4z)$ | $4\cdot0-2\cdot4=-8$ |

- Cevap: $\nabla g(0,2,1)=\langle10,20,-8\rangle$, A şıkkı.

### Teğet Düzlem ve Normal Doğru

**Örnek 3.** $(1,1)$ noktasında $\ln$ içeren bir yüzey.

- Hoca yüzeyi kapalı biçime getirdi ve kısmi türevleri hesapladı: $F_x=F_y=\frac13$, $F_z=-1$.
- Teğet düzlem: $\frac13(x-1)+\frac13(y-1)-(z-z_0)=0$.
- Normal doğru: $\dfrac{x-1}{1/3}=\dfrac{y-1}{1/3}=\dfrac{z-z_0}{-1}$.
- Fonksiyon altyazıda net değil ("$z=\ln$ … $x^2+y^2+1$"). Hoca $z_0=\ln3$ aldı. Ancak bulunan $\frac13$ değerleri $z=\ln\sqrt{1+x^2+y^2}$ ile uyumlu. Bu durumda büyük olasılıkla $z_0=\frac12\ln3$ olur.

**Örnek 4.** $z=\tan(x^2-xy)$ yüzeyinin $(0,-1)$ noktasındaki teğet düzlemi.

- $z_0=\tan0=0$, nokta $(0,-1,0)$.
- $F=\tan(x^2-xy)-z$:
  - $F_x=\sec^2(x^2-xy)(2x-y)=1$.
  - $F_y=\sec^2(x^2-xy)(-x)=0$.
  - $F_z=-1$.
- Düzlem: $1\cdot(x-0)+0-(z-0)=0 \Rightarrow x-z=0$, yani $x=z$. Cevap A.

**Örnek 5.** $z=\sin(x+y^2)$ yüzeyinin $(\pi,0)$ noktasındaki teğet düzlemi ve normal doğrusu.

- $z_0=\sin\pi=0$, nokta $(\pi,0,0)$.
- $F=\sin(x+y^2)-z$:
  - $F_x=\cos(x+y^2)=\cos\pi=-1$.
  - $F_y=2y\cos(x+y^2)=0$.
  - $F_z=-1$.
- Teğet düzlem: $-(x-\pi)-z=0 \Rightarrow x+z=\pi$.
- Normal doğru: $x=\pi-t$, $y=0$, $z=-t$.

### Lineerleştirme ve Yaklaşık Değer

**Örnek 6.** $f(x,y)=\sqrt{2x^2+e^{2y}}$ için $f(2{,}2;\,-0{,}2)$ yaklaşık değeri.

- En yakın kolay nokta $(2,0)$: $f(2,0)=\sqrt{8+1}=3$.
- $f_x=\dfrac{4x}{2\sqrt{2x^2+e^{2y}}}$, $f_x(2,0)=\frac43$.
- $f_y=\dfrac{2e^{2y}}{2\sqrt{2x^2+e^{2y}}}$, $f_y(2,0)=\frac13$.
- $L(x,y)=3+\frac43(x-2)+\frac13y$.
- $L(2{,}2;\,-0{,}2)=3+\frac43(0{,}2)-\frac13(0{,}2)=3{,}2$.
- Soru "lineer denklem hangisidir" diye de sorulabilir.

**Örnek 7.** $\sqrt{(2{,}06)^2+5(0{,}97)^4}$ yaklaşık değeri.

- Fonksiyonu kur: $f(x,y)=\sqrt{x^2+5y^4}$, $(a,b)=(2,1)$, $f(2,1)=3$.
- $\Delta x=0{,}06$, $\Delta y=-0{,}03$.
- $f_x=\dfrac{x}{\sqrt{x^2+5y^4}}=\frac23$, $f_y=\dfrac{10y^3}{\sqrt{x^2+5y^4}}=\frac{10}{3}$.
- $f\approx3+\frac23(0{,}06)+\frac{10}{3}(-0{,}03)=3+0{,}04-0{,}1=2{,}94$.
- Lineerleştirme ile diferansiyel yöntemi aynıdır: $x-x_0=\Delta x$, $y-y_0=\Delta y$.

**Örnek 8 (hacim değişimi).** Kenarları 2 cm, 3 cm ve 4 cm olan dikdörtgenler prizmasının her kenarı 0,02 cm artırılıyor.

- $V=xyz$, $dV=yz\,dx+xz\,dy+xy\,dz$.
- $V_x=12$, $V_y=8$, $V_z=6$, $dx=dy=dz=0{,}02$.
- $dV=(12+8+6)(0{,}02)=0{,}52=\frac{52}{100}$ cm³ artış.
- Yeni hacim sorulursa: $24+0{,}52=24{,}52$ cm³.
- Kenarlar azaltılsaydı hacim $0{,}52$ cm³ azalırdı.

**Örnek 9 (yönlü türevle yaklaşık değer).** $f(1,2)=5$ ve $f$'nin $(1,2)$'de $\vec i+\vec j$ yönündeki türevi $3\sqrt2$. $f(1{,}1;\,2{,}1)$ yaklaşık değeri nedir?

- Birim vektör: $\vec u=\frac{1}{\sqrt2}(1,1)$.
- $D_{\vec u}f=\frac{f_x+f_y}{\sqrt2}=3\sqrt2 \Rightarrow f_x+f_y=6$.
- $f(1{,}1;\,2{,}1)\approx5+f_x(0{,}1)+f_y(0{,}1)=5+0{,}1\cdot6=5{,}6$.
- $f$'nin kendisi bilinmeden de çözülüyor.

### Yönlü Türevin En Büyük ve En Küçük Değeri

**Örnek 10 (soru 10).** $f(x,y,z)=\dfrac xy-yz$, $P(4,1,1)$.

- $\nabla f=\left\langle\frac1y,\;-\frac{x}{y^2}-z,\;-y\right\rangle$, $\nabla f(P)=\langle1,-5,-1\rangle$.
- $|\nabla f|=\sqrt{1+25+1}=\sqrt{27}=3\sqrt3$.
- En büyük değer $A=\sqrt{27}$, en küçük değer $B=-\sqrt{27}$. Cevap B.

### Yerel Ekstremumlar

**Örnek 11 (soru 12).** Büyük olasılıkla (ekrandan) $f(x,y)=xy-x^2-y^2-2x-2y+4$.

- $f_x=y-2x-2=0$ ve $f_y=x-2y-2=0$, buradan $x=y=-2$. Kritik nokta $(-2,-2)$.
- $A=f_{xx}=-2$, $B=f_{xy}=1$, $C=f_{yy}=-2$.
- $B^2-AC=1-4=-3<0$ ve $A<0$: yerel maksimum.
- Bir tane yerel maksimum var. Cevap C. "2 yerel maksimum" şıkkı çeldirici.

**Örnek 12.** Fonksiyon büyük olasılıkla (ekrandan) okunabiliyor; bir başka fonksiyonda kritik noktalar $(0,0)$ ve $(1,2)$ çıktı. $A=48x$, $B=-12$, $C=6y$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | 0 | $-12$ | 0 | $144>0$ | eyer noktası |
| $(1,2)$ | 48 | $-12$ | 12 | $144-576<0$, $A>0$ | yerel minimum |

**Örnek 13 (soru 14).** $f(x,y)=4+x^3+y^3-3xy$ için yerel maksimum sayısı $a$, yerel minimum sayısı $b$, eyer noktası sayısı $c$.

- $f_x=3x^2-3y=0$, $f_y=3y^2-3x=0$. Buradan $y=x^2$ ve $x=y^2$, yani $x^4=x$. Kritik noktalar $(0,0)$ ve $(1,1)$.
- $A=6x$, $B=-3$, $C=6y$.
  - $(0,0)$: $B^2-AC=9>0$, eyer noktası.
  - $(1,1)$: $9-36<0$ ve $A=6>0$, yerel minimum.
- $a=0$, $b=1$, $c=1$.

**Örnek 14 (soru 16).** $f(x,y)=x+y\sin x$, $0\le x\le\pi$ için kritik nokta sayısı.

- $f_y=\sin x=0 \Rightarrow x=0$ veya $x=\pi$.
- $f_x=1+y\cos x=0$:
  - $x=0$ için $y=-1$.
  - $x=\pi$ için $y=1$.
- İki kritik nokta: $(0,-1)$ ve $(\pi,1)$.
- İkisinde de $A=C=0$, $B=\cos x=\pm1$, $B^2-AC=1>0$. İkisi de eyer noktası.

### Yüzeyler Arasındaki Açı

**Örnek 15 (soru 15).** Büyük olasılıkla (ekrandan) $x^2+y^2+z^2=4y+2z+5$ ile $3x^2+2y^2-2z=3$ yüzeyleri $P(1,2,4)$'te kesişiyor. Kesişim açısı nedir?

- $F=x^2+y^2+z^2-4y-2z-5$, $\nabla F=\langle2x,\,2y-4,\,2z-2\rangle$, $\nabla F(P)=\langle2,0,6\rangle$.
- $G=3x^2+2y^2-2z-3$, $\nabla G=\langle6x,\,4y,\,-2\rangle$, $\nabla G(P)=\langle6,8,-2\rangle$.
- $\nabla F\cdot\nabla G=12+0-12=0 \Rightarrow \cos\theta=0 \Rightarrow \theta=\frac\pi2$. Cevap C.

### Ders sonrası notlar

- Örnek 2: hoca sonucu sözlü olarak "10, 20, 8" diye okudu. Tahtadaki doğru sonuç $\langle10,20,-8\rangle$.
- Örnek 3: fonksiyonun tam biçimi altyazıda anlaşılmıyor. $z_0$ değeri buna bağlı ($\ln3$ ya da $\frac12\ln3$).
- Örnek 11: altyazıda kritik nokta "$(-2,2)$" diye geçiyor (tahta doğrulanamaz). Denklemlerden $x=y=-2$ çıkıyor. Doğru nokta $(-2,-2)$, sonuç (yerel maksimum) değişmiyor.
- Örnek 12'deki fonksiyonun tamamı altyazıda yok. Büyük olasılıkla (ekrandan) okunan $f_x$ ifadesi ile $A=48x$ birbiriyle tam uyumlu değil. Tablo derste verilen hâliyle verildi.
- Örnek 14'te hoca yalnız kritik nokta sayısını sordu. Eyer noktası analizini ben ekledim.
- 00:31-00:45 arasında mola var. 00:28 civarında hocanın internet bağlantısı kısa süre koptu.
- Final tarihi bu derste verilmedi. Hoca haftaya da final soruları çözüleceğini söyledi.
- Hoca kayıtların paylaşılmasına itiraz etmedi.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
