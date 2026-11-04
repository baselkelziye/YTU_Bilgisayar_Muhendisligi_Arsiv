# Ders 13 Çalışma Özeti

**Tarih:** 10 Nisan 2023 (Pazartesi)

## Genel Konular

- Kısmi türevin uygulamaları: gradyan vektörü (gradient vector), teğet düzlem (tangent plane) ve normal doğru (normal line).
- İki yüzeyin kesişim eğrisine teğet doğru.
- Lineerleştirme (linearization) ve yaklaşık hesap.
- Tam diferansiyel (total differential) ile değişim tahmini.
- Yerel ekstremumlar (local extrema), kritik nokta (critical point), eyer noktası (saddle point).
- İkinci türev testi (second derivative test).
- İki değişkenli fonksiyonlar için Taylor formülü.
- Kısıtlanmış değişkenlerle kısmi türevler (partial derivatives with constrained variables).

## Hocanın Özellikle Vurguladığı Kısımlar

- Teğet düzlem ve normal doğru soruları gradyan vektörüyle çözülür. Bu tip sorular sınavda gelir.
- Maksimum, minimum ve eyer noktası soruları 1. vize, 2. vize ve finalde geliyor.
- İkinci türev testindeki tablo yöntemini öğrenin. Test sorusunda doğru şıkkı hemen bulmanızı sağlar.
- Taylor açılımında sınavda en fazla ikinci mertebeye kadar sorulur.
- Kısıtlanmış değişkenlerde önce hangi değişkenin bağımlı, hangisinin bağımsız olduğunu belirleyin. "Bunlar çok önemli."
- Hesap makinesinin mantığı lineerleştirmedir: $(1{,}1)^2+(2{,}5)^3$ gibi değerleri yaklaşık hesaplamak.
- "Zor iş, zamanında yapılmayan kolay işlerin toplamıdır." Günlük çalışın, biriktirmeyin.

## Kısa Tekrar Notları

- Gradyan: $\nabla F=F_x\,\vec i+F_y\,\vec j+F_z\,\vec k$.
- $F(x,y,z)=c$ yüzeyinin $P_0(x_0,y_0,z_0)$ noktasındaki teğet düzlemi:
  $$F_x(P_0)(x-x_0)+F_y(P_0)(y-y_0)+F_z(P_0)(z-z_0)=0$$
- Aynı noktadaki normal doğru: $x=x_0+F_x(P_0)\,t$, $y=y_0+F_y(P_0)\,t$, $z=z_0+F_z(P_0)\,t$.
- $z=f(x,y)$ verilirse önce kapalı hale getir: $F(x,y,z)=f(x,y)-z=0$.
- Lineerleştirme: $L(x,y)=f(x_0,y_0)+f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$.
- Tam diferansiyel: $df=f_x\,dx+f_y\,dy$. Değişim $\Delta f\approx df$.
- Kritik nokta: $f_x=f_y=0$ ya da kısmi türevlerden biri yok.
- İkinci türev testi: $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$ (kritik noktada).
  - $B^2-AC<0$ ve $A>0$: yerel minimum.
  - $B^2-AC<0$ ve $A<0$: yerel maksimum.
  - $B^2-AC>0$: eyer noktası.
  - $B^2-AC=0$: test sonuç vermez.
- Kısıtlı türev: $F(x,y,z)=0$ ise $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$, $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}$.

## Detaylı Açıklamalar

### 1. Gradyan, teğet düzlem ve normal doğru

**Tanım (gradyan):**
- $F(x,y,z)$ için $\nabla F=\left(F_x,F_y,F_z\right)$.
- Teğet düzlemin normal vektörü $\nabla F(P_0)$'dır.

**Örnek 1.** $z=9-x^2-y^2$ yüzeyi (aşağı açılan paraboloit), $P_0(1,2,4)$.
- Kapalı hale getir: $F=z+x^2+y^2-9=0$.
- $\nabla F=(2x,\,2y,\,1)$, $\nabla F(1,2,4)=(2,4,1)$.
- Teğet düzlem: $2(x-1)+4(y-2)+1(z-4)=0 \Rightarrow 2x+4y+z=14$.
- Normal doğru: $x=1+2t$, $y=2+4t$, $z=4+t$.

**Örnek 2.** $z=x\cos y-y\,e^x$ yüzeyine $(0,0,0)$ noktasında teğet düzlem.
- $F=x\cos y-y\,e^x-z=0$.
- $F_x=\cos y-y\,e^x$, $F_y=-x\sin y-e^x$, $F_z=-1$.
- $(0,0,0)$'da: $\nabla F=(1,-1,-1)$. Hoca işaretleri ters tarafa atarak $(-1,1,1)$ aldı; ikisi aynı düzlemi verir.
- Teğet düzlem: $x-y-z=0$.

**Örnek 3.** $f(x,y,z)=x^2+y^2-2=0$ silindiri ile $g(x,y,z)=x+z-4=0$ düzlemi bir elips boyunca kesişir. $P_0(1,1,3)$'te elipse teğet doğru:
- Teğet doğru hem $\nabla f$'ye hem $\nabla g$'ye diktir.
- Doğrultu vektörü: $\vec v=\nabla f\times\nabla g$.
- $\nabla f(1,1,3)=(2,2,0)$, $\nabla g=(1,0,1)$.
- $\vec v=(2,2,0)\times(1,0,1)=(2,-2,-2)$.
- Teğet doğru: $x=1+2t$, $y=1-2t$, $z=3-2t$.

### 2. Lineerleştirme

**Tanım:**
- Tek değişkende: $L(x)=f(x_0)+f'(x_0)(x-x_0)$.
- İki değişkende: $L(x,y)=f(x_0,y_0)+f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$.
- Üç değişkende $f_z(P_0)(z-z_0)$ terimi eklenir.
- $f(x,y)\approx L(x,y)$; eşit değil, yaklaşık eşittir.

**Örnek 4.** $f(x,y)=x^2-xy+\tfrac12y^2+3$, $(3,2)$ noktasında lineerleştirme.
- $f(3,2)=9-6+2+3=8$.
- $f_x=2x-y \Rightarrow f_x(3,2)=4$.
- $f_y=-x+y \Rightarrow f_y(3,2)=-1$.
- $L(x,y)=8+4(x-3)-(y-2)=4x-y-2$.
- Yaklaşık değer: $f(3{,}1;\,1{,}9)\approx 8+4(0{,}1)-(-0{,}1)=8{,}5$.

**Örnek 5.** $(1{,}1)^2+(2{,}5)^3$ için yaklaşık değer.
- $f(x,y)=x^2+y^3$, $(x_0,y_0)=(1,2)$.
- $f(1,2)=9$, $f_x=2x=2$, $f_y=3y^2=12$.
- $L=9+2(0{,}1)+12(0{,}5)=15{,}2$.

**Örnek 6.** $f(x,y)=x\,e^{x^2-y}$, $f(2{,}05;\,3{,}9)$ yaklaşık değeri (kareden doğrulandı).
- $x_0=2$, $y_0=4$ seçilir (en yakın kolay değerler).
- $f_x=(1+2x^2)e^{x^2-y}\Rightarrow f_x(2,4)=9$.
- $f_y=-x\,e^{x^2-y}\Rightarrow f_y(2,4)=-2$.
- $f(2,4)=2$.
- $L=2+9(x-2)-2(y-4)$.
- $f(2{,}05;\,3{,}9)\approx 2+9(0{,}05)-2(-0{,}1)=2+0{,}45+0{,}2=2{,}65$.
- Tam diferansiyelle de aynı sonuç: $dz=9(0{,}05)-2(-0{,}1)=0{,}65$, $f\approx 2+0{,}65=2{,}65$.

### 3. Tam diferansiyel ile değişim

**Tanım:**
- Tek değişkende $dy=f'(x)\,dx$.
- İki değişkende $df=f_x\,dx+f_y\,dy$.
- Yeni değer: $f(x_0,y_0)+df$.

**Örnek 7.** Silindirik konserve kutusu: yarıçap 3 cm, yükseklik 12 cm. Yarıçap $dr=0{,}08$, yükseklik $dh=-0{,}3$ değişiyor (kareden doğrulandı). Hacimdeki değişim?
- $V=\pi r^2h=\pi\cdot9\cdot12=108\pi\ \text{cm}^3$.
- $V_r=2\pi rh=72\pi$, $V_h=\pi r^2=9\pi$.
- $dV=72\pi(0{,}08)+9\pi(-0{,}3)=5{,}76\pi-2{,}7\pi=3{,}06\pi$.
- Yeni hacim yaklaşık $V+dV$.

### 4. Yerel ekstremumlar

**Tanım (yerel maksimum ve minimum):**
- $(a,b)$'nin bir komşuluğundaki tüm $(x,y)$ için $f(x,y)\le f(a,b)$ ise $f$, $(a,b)$'de yerel maksimuma sahiptir.
- $f(x,y)\ge f(a,b)$ ise yerel minimuma sahiptir.
- İkisine birden yerel ekstremum denir.

**Teorem (gerekli koşul):**
- $f$, $(a,b)$'de yerel ekstremuma sahip ve birinci kısmi türevler varsa $f_x(a,b)=0$ ve $f_y(a,b)=0$.
- Kısmi türevlerin sıfır olduğu ya da var olmadığı noktalara kritik nokta denir.

**Tanım (eyer noktası):**
- Kritik nokta olup yerel ekstremum olmayan noktadır.
- Diğer adı semer noktası.

**Birinci yöntem (tanımdan):** $f(a+h,b+k)-f(a,b)$ farkının işaretine bakılır.
- Küçük her $h,k$ için fark $>0$: yerel minimum.
- Fark $<0$: yerel maksimum.
- İşareti değişiyorsa: eyer noktası.

**Örnek 8.** $f=x^2+y^2$. Kritik nokta $(0,0)$. $f(h,k)-f(0,0)=h^2+k^2>0$, yerel minimum.

**Örnek 9.** Farkın $h^2-k^2$ çıktığı örnekte işaret $h$ ve $k$'ya göre değişir. $(0,0)$ eyer noktasıdır.

### 5. İkinci türev testi

**Teorem:** $f$'nin birinci ve ikinci kısmi türevleri sürekli, $(a,b)$ kritik nokta olsun. $A=f_{xx}(a,b)$, $B=f_{xy}(a,b)$, $C=f_{yy}(a,b)$.
- $B^2-AC<0$, $A>0$: yerel minimum.
- $B^2-AC<0$, $A<0$: yerel maksimum.
- $B^2-AC>0$: eyer noktası.
- $B^2-AC=0$: test sonuç vermez.

**Örnek 10.** $f(x,y)=2x^3-6xy+3y^2$.
- $f_x=6x^2-6y=0$, $f_y=-6x+6y=0 \Rightarrow y=x$, $x^2=x$.
- Kritik noktalar: $(0,0)$ ve $(1,1)$.
- $f_{xx}=12x$, $f_{xy}=-6$, $f_{yy}=6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | 0 | $-6$ | 6 | $36>0$ | eyer noktası |
| $(1,1)$ | 12 | $-6$ | 6 | $-36<0$, $A>0$ | yerel minimum |

**Örnek 11.** $f(x,y)=x^3-3x^2+3xy^2-3y^2$.
- $f_x=3x^2-6x+3y^2$, $f_y=6xy-6y=6y(x-1)$.
- $y=0$ ise $x^2-2x=0$: $(0,0)$, $(2,0)$.
- $x=1$ ise $y^2=1$: $(1,1)$, $(1,-1)$.
- $f_{xx}=6x-6$, $f_{xy}=6y$, $f_{yy}=6x-6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $-6$ | 0 | $-6$ | $-36$ | yerel maksimum |
| $(1,1)$ | 0 | 6 | 0 | $36$ | eyer noktası |
| $(1,-1)$ | 0 | $-6$ | 0 | $36$ | eyer noktası |
| $(2,0)$ | 6 | 0 | 6 | $-36$ | yerel minimum |

### 6. İki değişkenli Taylor formülü

**Formül ($(a,b)$ noktasında, ikinci mertebeye kadar):**
$$f(x,y)\approx f(a,b)+f_x(x-a)+f_y(y-b)+\frac{1}{2!}\Big[f_{xx}(x-a)^2+2f_{xy}(x-a)(y-b)+f_{yy}(y-b)^2\Big]$$
- Türevler $(a,b)$'de hesaplanır.
- $(a,b)=(0,0)$ ise Maclaurin açılımı olur.

**Örnek 12.** $f(x,y)=e^x\sin y$, $(0,\pi/2)$ noktasında ikinci mertebeye kadar Taylor açılımı.
- $f(0,\pi/2)=1$.
- $f_x=e^x\sin y=1$, $f_y=e^x\cos y=0$.
- $f_{xx}=e^x\sin y=1$, $f_{xy}=e^x\cos y=0$, $f_{yy}=-e^x\sin y=-1$.
- Birinci mertebe: $f\approx 1+x$.
- İkinci mertebe: $f\approx 1+x+\tfrac12\big[x^2-(y-\tfrac{\pi}{2})^2\big]$.

### 7. Kısıtlanmış değişkenlerle kısmi türevler

**Notasyon:** $\left(\dfrac{\partial w}{\partial x}\right)_y$, $x$ ve $y$'nin bağımsız değişken olduğunu gösterir. Geri kalanlar bağımlıdır.

**Kural:**
- Önce bağımsız değişkenleri belirle.
- Bağımlı değişkenin türevi zincir kuralıyla gelir.
- $F(x,y,z)=0$ ise $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$.

**Örnek 13.** $w=x^2+y^2+z^2$, $z^3-xy+yz+y^3=1$. $(2,-1,1)$'de $\left(\dfrac{\partial w}{\partial x}\right)_y$.
- $x,y$ bağımsız; $z$ ve $w$ bağımlı.
- $\dfrac{\partial w}{\partial x}=2x+2z\,\dfrac{\partial z}{\partial x}$.
- $F=z^3-xy+yz+y^3-1$: $F_x=-y$, $F_z=3z^2+y$.
- $\dfrac{\partial z}{\partial x}=\dfrac{y}{3z^2+y}=\dfrac{-1}{3-1}=-\dfrac12$.
- $\dfrac{\partial w}{\partial x}=4+2(1)\left(-\tfrac12\right)=3$.

**Örnek 14.** $w=x^2+y-z+\sin t$, $x+y=t$. $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}$.
- $x,y,z$ bağımsız, $t$ bağımlı ($t=x+y$).
- $\dfrac{\partial w}{\partial x}=2x+\cos t\cdot\dfrac{\partial t}{\partial x}=2x+\cos(x+y)$.

**Örnek 15.** $w=x^2+y^2+z^2$, $y\sin z+z\sin x=0$. $(0,1,\pi)$'de $\left(\dfrac{\partial w}{\partial y}\right)_x$.
- $x,y$ bağımsız.
- $\dfrac{\partial z}{\partial y}=-\dfrac{\sin z}{y\cos z+\sin x}=-\dfrac{0}{-1}=0$.
- $\dfrac{\partial w}{\partial y}=2y+2z\cdot0=2$.

**Örnek 16 (hocanın derste kurduğu örnek).** $w=x^2+y^2+z^2$, $x\sin y+z\cos x=0$, nokta $x=0$, $y=\pi$. $\left(\dfrac{\partial w}{\partial x}\right)_y$.
- Denklemden $x=0$, $y=\pi$ için $z=0$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{\sin y-z\sin x}{\cos x}=-\dfrac{0}{1}=0$.
- $\dfrac{\partial w}{\partial x}=2x+2z\cdot0=2x=0$.

### Ders sonrası notlar

- **Örnek 4, yaklaşık değer:** Hoca $f(3{,}1;\,1{,}9)$ için sonucu "0,9" gibi söyledi. Doğrusu $L=8+0{,}4+0{,}1=8{,}5$. Hoca $4\cdot0{,}1$'i 0,8 diye okumuş olabilir.
- **Örnek 5, $y_0$ seçimi:** Hoca "$y_0$ için 2 de 3 de seçilebilir, sonuç aynı çıkar" dedi. Sonuç aynı çıkmaz. $y_0=3$ alınırsa $L=28+0{,}2+27(-0{,}5)=14{,}7$ olur. Gerçek değer $1{,}21+15{,}625=16{,}835$. Lineerleştirmede noktaya en yakın kolay değer seçilir. İki seçenek de kaba bir yaklaşımdır.
- **Örnek 7, birim:** Notta $dr=0{,}08$ ve $dh=-0{,}3$ "mm" yazıyor, $r$ ve $h$ ise cm. Birimler aynı olmalı. mm alınırsa $dr=0{,}008$ cm, $dh=-0{,}03$ cm olur ve $dV=0{,}306\pi\ \text{cm}^3$ çıkar. Notun $3{,}06\pi$ sonucu, değişimler de cm alındığında geçerlidir. Altyazıda yükseklik değişimi "0,03" diye de geçiyor; kareye göre $-0{,}3$.
- **Örnek 2:** Hoca $F$'yi $z-x\cos y+y\,e^x$ diye kurdu. Gradyan $(-1,1,1)$ çıkar. Düzlem $-x+y+z=0$, yani $x-y-z=0$; aynı düzlemdir.
- **Örnek 14:** Altyazıda sonuç bozuk ("kökünüz 2 artı y"). Doğru sonuç $2x+\cos(x+y)$.
- **Örnek 15:** Bu soru kitapta $\left(\dfrac{\partial w}{\partial x}\right)_y$ olarak da geçer. O durumda $\dfrac{\partial z}{\partial x}=-\dfrac{z\cos x}{y\cos z+\sin x}=\pi$, sonuç $2\pi^2$ olur. Hoca $y$'ye göre türevi çözdü.
- Örnek 8 ve 9'daki ikinci fonksiyon altyazıda net değil. Yalnız fark ifadesi ($h^2-k^2$) anlaşılıyor.
- Ders 00:29 ile 00:46 ve 01:08 ile 01:26 arasında mola var.

---

İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
