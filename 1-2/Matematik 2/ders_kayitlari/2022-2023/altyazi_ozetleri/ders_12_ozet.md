# Ders 12 Çalışma Özeti

## Genel Konular

- Ders 4 Nisan 2023 Salı günü yapıldı.
- Hoca kaynak olarak Prof. Dr. Mustafa Balcı'nın "Genel Matematik 2 Problemleri" (çözümlü) kitabının PDF'ini tanıttı ve kitap üzerinden tekrar yaptı.
- Vektörler, skaler, vektörel ve karma çarpım; uzayda doğru ve düzlem; iki düzlem arasındaki uzaklık ve açı.
- Vektör değerli fonksiyonlar: uzunluk, limit, türev, integral, eğri uzunluğu, birim teğet vektör.
- Çok değişkenli fonksiyonlar: tanım bölgesi, yüzeyler, kısmi türev tekrarı, Laplace denklemi, karışık türevler.
- Çok değişkenli fonksiyonlarda zincir kuralı, kapalı fonksiyonların türevi.
- Lineerleştirme (linearization) ve tam diferansiyel (total differential), koni hacmi uygulaması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kitapta her konuda 10-15 çözümlü örnek var. Hepsini çözmek gerekmez, ama ana konular için faydalı.
- Vektör, doğru ve düzlem konuları mühendislikte altyapı olarak kullanılacak. Ders için değil öğrenmek için çalışılmalı.
- Paralel iki düzlem arasındaki uzaklık sorusunda sınavda çeldirici olur: denklemlerden birinin katsayıları 2 katı verilebilir. Önce katsayılar eşitlenmelidir.
- Uzay eğrisinin uzunluğu sınavda gelebilecek sorulardan.
- Tanım bölgesi sorularından bol bol çözülmeli.
- $f_{xy}=f_{yx}$ eşitliği kısmi türevler sürekliyse geçerlidir.
- Tam diferansiyel sorusunda birimler (mm, cm) aynı birime çevrilmelidir.
- Birikmeden, konu konu, planlı çalışılmalı.

## Kısa Tekrar Notları

- $\vec u=(a_1,a_2)$ için $\|\vec u\|=\sqrt{a_1^2+a_2^2}$. Birim vektörün boyu 1'dir.
- Skaler çarpım: $\vec u\cdot\vec v=\|\vec u\|\|\vec v\|\cos\theta$. Vektörel çarpım: $\|\vec u\times\vec v\|=\|\vec u\|\|\vec v\|\sin\theta$.
- Karma çarpım $\vec a\cdot(\vec b\times\vec c)$: üç vektörün oluşturduğu determinant. Mutlak değeri paralel yüzlünün hacmidir. Vektörler aynı düzlemdeyse 0.
- Uzayda iki nokta arası uzaklık: $\sqrt{(x_2-x_1)^2+(y_2-y_1)^2+(z_2-z_1)^2}$.
- İki doğru paralelse doğrultu vektörlerinin bileşenleri orantılıdır. Dikse skaler çarpım 0.
- Noktanın düzleme uzaklığı: $d=\dfrac{|Ax_0+By_0+Cz_0+D|}{\sqrt{A^2+B^2+C^2}}$.
- Paralel düzlemler arası uzaklık: $\ell=\dfrac{|D_2-D_1|}{\sqrt{A^2+B^2+C^2}}$ (katsayılar aynı olmalı).
- Düzlemler arasındaki açı, normalleri arasındaki açıdır.
- Uzay eğrisinin uzunluğu: $L=\displaystyle\int_a^b\sqrt{x'(t)^2+y'(t)^2+z'(t)^2}\,dt$.
- Lineerleştirme: $L(x,y)=f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)$.
- Tam diferansiyel: $dz=f_x\,dx+f_y\,dy$.

## Detaylı Açıklamalar

### Vektörler ve düzlemler (kitaptan tekrar)

**Örnek 1.** Paralel iki düzlem arası uzaklık (kareden).

- $3x-4y+12z-8=0$ ve $-6x+8y-24z-10=0$.
- İkinci denklem $-2$'ye bölünür: $3x-4y+12z+5=0$.
- $\ell=\dfrac{|-8-5|}{\sqrt{9+16+144}}=\dfrac{13}{13}=1$ birim.
- Hoca, katsayılar eşitlenmeden $D$'ler çıkarılırsa yanlış sonuç bulunacağını vurguladı.

**Örnek 2.** İki düzlem arasındaki açı (kareden).

- $\vec n_1=(1,1,0)$, $\vec n_2=(2,1,-2)$.
- $\vec n_1\cdot\vec n_2=2+1+0=3$.
- $\|\vec n_1\|=\sqrt2$, $\|\vec n_2\|=\sqrt{4+1+4}=3$.
- $\cos\theta=\dfrac{3}{3\sqrt2}=\dfrac{1}{\sqrt2}$, $\theta=45^\circ$.
- Kitaptaki ikinci örnekte normallerin skaler çarpımı 0, düzlemler dik ($\theta=90^\circ$).

### Vektör değerli fonksiyonlar

**Tanım.** $D\subseteq\mathbb{R}$ olmak üzere $\vec F:D\to\mathbb{R}^3$, $\vec F(t)=f(t)\,\vec i+g(t)\,\vec j+h(t)\,\vec k$.

- Boyu: $\|\vec F(t)\|=\sqrt{f(t)^2+g(t)^2+h(t)^2}$.
- Limit: bileşenlerin limitleri ayrı ayrı alınır. Birinin limiti yoksa vektör fonksiyonun limiti yoktur.
- Süreklilik: bütün bileşenler sürekliyse süreklidir. Polinom bileşenler her yerde süreklidir. Rasyonel bileşenlerde paydayı sıfır yapan noktalar süreksizlik noktasıdır.
- Türev: bileşenlerin türevleri ayrı ayrı alınır.
- $(\vec u\cdot\vec v)'=\vec u'\cdot\vec v+\vec u\cdot\vec v'$.
- $(\vec u\times\vec v)'=\vec u'\times\vec v+\vec u\times\vec v'$.
- İntegral: bileşenlerin integralleri ayrı ayrı alınır.
- Birim teğet vektör: $\vec T(t)=\dfrac{\vec r\,'(t)}{\|\vec r\,'(t)\|}$.

**Örnek 3.** $\vec r(t)=a\cos t\,\vec i+a\sin t\,\vec j+\dots$ tipindeki eğri için birim teğet.

- $\|\vec r\,'(t)\|=\sqrt{a^2\sin^2t+a^2\cos^2t+\dots}$; $\sin^2t+\cos^2t=1$ kullanılır.
- Eğrinin tam ifadesi altyazıda net değil.

### Çok değişkenli fonksiyonlar (tekrar)

**Örnek 4.** $f(x,y)=\ln(x^2+y^2-4)$ fonksiyonunun tanım bölgesi.

- $x^2+y^2-4>0$, yani $x^2+y^2>4$.
- Merkezi orijin, yarıçapı 2 olan çemberin dışı. Eşitlik olmadığı için çember dahil değil.

**Yüzeyler.** Küre, elipsoid ($x$'i $a$'da, $y$'yi $b$'de, $z$'yi $c$'de keser), dairesel silindir, $z=ax^2$ parabolik silindiri (düzlemde parabol olan eğri uzayda $y$ yönünde sınırsız uzar).

### Kısmi türev (tekrar)

- $f_x(a,b)=\displaystyle\lim_{h\to0}\frac{f(a+h,b)-f(a,b)}{h}$: artış yalnız birinci bileşende.
- $f_y(a,b)=\displaystyle\lim_{k\to0}\frac{f(a,b+k)-f(a,b)}{k}$: artış yalnız ikinci bileşende.
- Geometrik anlam: $y=b$ düzleminin $z=f(x,y)$ yüzeyini kestiği eğrinin teğetinin eğimi $f_x(a,b)$'dir.
- $f_{xy}$: önce $x$'e, sonra $y$'ye göre türev. $\dfrac{\partial^2 f}{\partial y\,\partial x}=\dfrac{\partial}{\partial y}\left(\dfrac{\partial f}{\partial x}\right)$.

**Örnek 5.** $f(x,y)=x^3y+xy^3-3x^2y^2$, $f_x(1,1)$ (kareden).

- $f_x(x,y)=3x^2y+y^3-6xy^2$.
- $f_x(1,1)=3+1-6=-2$.

**Örnek 6.** Laplace denklemi: $z=x^2-y^2$ için $z_{xx}+z_{yy}=0$ (kareden).

- $z_x=2x$, $z_{xx}=2$.
- $z_y=-2y$, $z_{yy}=-2$.
- $z_{xx}+z_{yy}=0$. Denklemi sağlayan fonksiyonlara harmonik fonksiyon (harmonic function) denir.

**Karışık türevler.** Kitaptaki örneklerde $f_{xy}$ ve $f_{yx}$ ayrı ayrı hesaplanıp eşit olduğu gösteriliyor. Eşitliğin nedeni, fonksiyonun ve kısmi türevlerinin sürekli olmasıdır.

### Zincir kuralı

**Kural 1.** $z=f(x,y)$, $x=g(u,v)$, $y=h(u,v)$ ise:

$$\frac{\partial z}{\partial u}=\frac{\partial z}{\partial x}\frac{\partial x}{\partial u}+\frac{\partial z}{\partial y}\frac{\partial y}{\partial u},\qquad \frac{\partial z}{\partial v}=\frac{\partial z}{\partial x}\frac{\partial x}{\partial v}+\frac{\partial z}{\partial y}\frac{\partial y}{\partial v}$$

**Kural 2.** $z=f(x,y)$, $x=x(t)$, $y=y(t)$ ise:

$$\frac{dz}{dt}=\frac{\partial z}{\partial x}\frac{dx}{dt}+\frac{\partial z}{\partial y}\frac{dy}{dt}$$

**Kural 3.** $u=f(x,y,z)$, $x$, $y$, $z$ yalnız $t$'ye bağlıysa:

$$\frac{du}{dt}=\frac{\partial u}{\partial x}\frac{dx}{dt}+\frac{\partial u}{\partial y}\frac{dy}{dt}+\frac{\partial u}{\partial z}\frac{dz}{dt}$$

**Kural 4.** $y=f(x)$, $x=g(u,v)$ ise $\dfrac{\partial y}{\partial u}=\dfrac{dy}{dx}\dfrac{\partial x}{\partial u}$, $\dfrac{\partial y}{\partial v}=\dfrac{dy}{dx}\dfrac{\partial x}{\partial v}$.

Hoca zinciri doğadaki birbirine bağlı olaylara (iç ve dış sıcaklık, malzeme kalitesi) benzetti.

### Kapalı fonksiyonların türevi

- $F(x,y,z)=0$ ile tanımlanan $z=z(x,y)$ için:

$$\frac{\partial z}{\partial x}=-\frac{F_x}{F_z},\qquad \frac{\partial z}{\partial y}=-\frac{F_y}{F_z}$$

### Lineerleştirme ve yaklaşık hesap

**Tanım (Lineerleştirme).**

- $f$, $(a,b)$'de türevlenebilir olsun. $L(x,y)=f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)$ fonksiyonuna $f$'nin $(a,b)$'deki lineerleştirmesi denir.
- $f(x,y)\approx L(x,y)$ yaklaşımına $f$'nin $(a,b)$'deki lineer yaklaşımı denir.

Hoca bunu ayrı bir tahtada çizerek açıkladı. Tek değişkenli fonksiyonlarda bir noktadaki değere teğet doğruyla yaklaşılır. İki değişkenli fonksiyonda teğet düzlemle yaklaşılır.

### Tam diferansiyel

**Tanım.**

- Birinci mertebe: $dz=f_x\,dx+f_y\,dy$.
- İkinci mertebe: $d^2z=z_{xx}\,dx^2+2z_{xy}\,dx\,dy+z_{yy}\,dy^2$.

**Örnek 7.** $f(x,y)=x^3-5xy^2+3xy+4x-3y+5$, birinci mertebe tam diferansiyel (kareden).

- $f_x=3x^2-5y^2+3y+4$.
- $f_y=-10xy+3x-3$.
- $df=(3x^2-5y^2+3y+4)\,dx+(-10xy+3x-3)\,dy$.

**Örnek 8.** Taban yarıçapı 10 cm, yüksekliği 30 cm olan bir koninin yüksekliği 3 mm artırılır, taban yarıçapı 1 mm azaltılırsa hacmi kaç cm³ değişir?

- $V=\dfrac{\pi r^2h}{3}$. $V$, $r$ ve $h$'ye bağlı.
- Başlangıç hacmi: $V=\dfrac{\pi\cdot100\cdot30}{3}=1000\pi$ cm³.
- Birimler cm'ye çevrilir: $dh=0{,}3$ cm, $dr=-0{,}1$ cm.
- $dV=\dfrac{\partial V}{\partial r}dr+\dfrac{\partial V}{\partial h}dh=\dfrac{2\pi rh}{3}dr+\dfrac{\pi r^2}{3}dh$.
- $dV=\dfrac{2\pi\cdot10\cdot30}{3}(-0{,}1)+\dfrac{\pi\cdot100}{3}(0{,}3)=-20\pi+10\pi=-10\pi$ cm³.
- Hacim yaklaşık $10\pi\approx31{,}4$ cm³ azalır. Son hacim yaklaşık $990\pi$ cm³.
- Hoca sayısal sonucu derste hesaplamadı. $dV$ pozitifse artış, negatifse azalış olduğunu; son hacmin $V+dV$ ile bulunduğunu söyledi.

### Ders sonrası notlar

- **Örnek 2:** Hoca $\|\vec n_2\|$'yi "$4+4+1$... kök 5" diye söyledi. $\vec n_2=(2,1,-2)$ için $\|\vec n_2\|=\sqrt{4+1+4}=3$'tür. Sonuç $\theta=45^\circ$.
- **Örnek 5:** Hoca önce "eksi üç" dedi, sonra "eksi iki" diye düzeltti. Doğru sonuç $-2$.
- **Örnek 8:** Derste sayısal sonuç verilmedi. Doğru sonuç $dV=-10\pi$ cm³.
- **Vektörel çarpım:** Hoca bir yerde "vektörel çarpım çarpı şeklini gösteriyor" dedi. $\vec u\times\vec v$ bir vektördür; boyu $\|\vec u\|\|\vec v\|\sin\theta$'dır.
- **Laplace denklemi:** Altyazıda $z_y$ için "$x2$" gibi bozuk bir ifade geçiyor. Doğrusu $z_y=-2y$, $z_{yy}=-2$.

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
