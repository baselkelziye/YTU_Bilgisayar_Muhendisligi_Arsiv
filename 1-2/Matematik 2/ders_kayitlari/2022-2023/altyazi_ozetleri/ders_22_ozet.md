# Ders 22 Çalışma Özeti

Tarih: 9 Mayıs 2023 (Salı). Ders, önceki günün (iki katlı integralde değişken dönüşümü) devamı olarak geçmiş yıl final ve bütünleme sorularının çözümüyle geçiyor.

## Genel Konular

- 2020 Matematik 2 final sorularının çözümü (ekranda `mat2final-2020.pdf`).
- İki katlı integralde değişken dönüşümü (change of variables) ve Jacobian ile çözüm.
- Parçalı tanımlı iki değişkenli fonksiyonda karışık kısmi türevin (mixed partial derivative) tanımla hesabı.
- Karışık kısmi türevlerin eşitliği (Clairaut / Schwarz koşulu).
- Kritik noktaların bulunması ve ikinci türev testiyle sınıflandırılması.
- Paralelkenar (kare) bölgede $u=x+y$, $v=y-x$ dönüşümü.
- Kutupsal koordinatlarla hacim integrali kurma (silindir ve düzlemlerle sınırlı cisim).
- Seri toplamı: genel terimi bulup terim terim türev yöntemiyle toplam hesaplama.
- Gradyan (gradient), en hızlı artış yönü ve teğet düzlemle ilgili bütünleme sorusu.
- Lineerleştirme (linearization) ile yönlü türevin yaklaşık hesabı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karmaşık görünen iki katlı integralde yalnız integrasyon sırasını değiştirmek yetmez. İntegrandın içindeki ifadeler ($x-2y$, $x+3y$ gibi) hangi dönüşümün yapılacağını "ipucu olarak verir".
- Dönüşümde önce bölge çizilir. Sonra sınır doğruları $u$ ve $v$ cinsinden yazılır. Bu adım "çok kıymetli".
- Jacobian'ı $\dfrac{\partial(x,y)}{\partial(u,v)}$ ile doğrudan hesaplamak zorsa ters çevrilir: $\dfrac{\partial(x,y)}{\partial(u,v)} = \dfrac{1}{\partial(u,v)/\partial(x,y)}$.
- Tek değişkenli fonksiyonda süreksizse türev yoktur. Çok değişkenli fonksiyonda kısmi türevler var olup fonksiyon süreksiz olabilir.
- $f_{xy}=f_{yx}$ her zaman doğru değildir. Kısmi türevler sürekli ise eşittir.
- Final bilgisi: yine test, 20 soru. Limit ve süreklilikten mutlaka soru gelecek. Tanım ve değer kümesi, vektör değerli fonksiyonlar, kapalı fonksiyon ve kısmi türevlerden mutlaka soru gelecek. İntegralin her yönteminden birer ikişer soru gelecek.
- Testte sorular klasik sınavdaki gibi uzun olmaz, daha kısa ("light") hale getirilir. Ama aynı mantık sorulur.

## Kısa Tekrar Notları

- Dönüşüm: $u=g(x,y)$, $v=h(x,y)$ ise $dx\,dy = |J|\,du\,dv$, $J=\dfrac{\partial(x,y)}{\partial(u,v)}$.
- $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}u_x & u_y\\ v_x & v_y\end{vmatrix}$, Jacobian bunun tersidir.
- İkinci türev testi: $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$, $\Delta=B^2-AC$.
  - $\Delta>0$: eyer noktası (saddle point).
  - $\Delta<0$, $A>0$: yerel minimum.
  - $\Delta<0$, $A<0$: yerel maksimum.
  - $\Delta=0$: test karar vermez.
- $f_{xy}(0,0)=\lim_{h\to0}\dfrac{f_x(0,h)-f_x(0,0)}{h}$.
- Lineerleştirme: $f(x,y)\approx f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)$.
- En hızlı artış yönü $\nabla f$ yönüdür. Bu yöndeki türev $|\nabla f|$'dir.

## Detaylı Açıklamalar

### Örnek 1 (2020 final, Soru 1): Değişken dönüşümü

- İntegral: $\displaystyle I=\int_0^1\int_{2y}^{5-3y}\frac{x-2y}{(x+3y)^2}\cos(x+3y)\,dx\,dy$.
- Bölge: $0\le y\le1$, $x=2y$ doğrusu ile $x=5-3y$ doğrusu arası.
- Dönüşüm: $u=x-2y$, $v=x+3y$.
  - $x=2y \Rightarrow u=0$.
  - $x=5-3y \Rightarrow v=5$.
  - $y=0 \Rightarrow u=v$.
  - Yeni bölge: $0\le v\le5$, $0\le u\le v$.
- Jacobian:
  $$\frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}1&-2\\1&3\end{vmatrix}=5 \Rightarrow dx\,dy=\frac15\,du\,dv$$
- Hesap:
  $$I=\frac15\int_0^5\int_0^v \frac{u}{v^2}\cos v\,du\,dv=\frac15\int_0^5\frac{v^2}{2}\cdot\frac{\cos v}{v^2}\,dv=\frac1{10}\int_0^5\cos v\,dv=\frac{1}{10}\sin5$$
- Hoca: klasik sınavda her adım puanlanmıştı. Testte yalnız "dönüştürülmüş hali hangisidir" diye sorulabilir.

### Örnek 2 (2020 final, Soru 2): Karışık kısmi türev

- Fonksiyon:
  $$F(x,y)=\begin{cases}\dfrac{4y(2x^3-xy^2)}{4x^2+3y^2}, & (x,y)\ne(0,0)\\[4pt] 0, & (x,y)=(0,0)\end{cases}$$
- İstenen: $F_{xy}(0,0)$.
- $F_x(0,0)=\lim_{h\to0}\dfrac{F(h,0)-F(0,0)}{h}=\lim_{h\to0}\dfrac{0}{h}=0$.
- $(x,y)\ne(0,0)$ için $F_x$ bölüm kuralıyla bulunur. $F_x(0,h)=\dfrac{-12h^5}{9h^4}$.
- $F_{xy}(0,0)=\lim_{h\to0}\dfrac{F_x(0,h)-F_x(0,0)}{h}=\lim_{h\to0}\dfrac{-12h^5}{9h^5}=-\dfrac43$.
- Aynı fonksiyon için limit, süreklilik ve kısmi türev de sorulabilir.

**Karışık türevlerin eşitliği**

- $f_x$, $f_y$ (ve karışık türevler) bir bölgede sürekli ise $f_{xy}=f_{yx}$.
- Bu koşul sağlanmazsa eşitlik bozulabilir.

### Örnek 3 (2020 final, Soru 3): Kritik noktalar

- Fonksiyon: $f(x,y)=x^4-4xy-7x^2+4x+4y^2-8y+5$.
- $f_x=4x^3-4y-14x+4=0$, $f_y=-4x+8y-8=0$.
- İkinci denklemden $x=2y-2$. Birinciyle birleştirince $x(x^2-4)=0$.
- Kritik noktalar: $P(0,1)$, $Q(2,2)$, $R(-2,0)$.
- $A=f_{xx}=12x^2-14$, $B=f_{xy}=-4$, $C=f_{yy}=8$.

| Nokta | $A$ | $B$ | $C$ | $\Delta=B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $P(0,1)$ | $-14$ | $-4$ | $8$ | $16+112=128>0$ | Eyer noktası |
| $Q(2,2)$ | $34$ | $-4$ | $8$ | $16-272=-256<0$ | Yerel minimum |
| $R(-2,0)$ | $34$ | $-4$ | $8$ | $-256<0$ | Yerel minimum |

### Örnek 4 (2020 final): Kapalı fonksiyon ve teğet düzlem sorusu

- Soru metni okundu: $F(u,v)$ fonksiyonu ve $G(x,y,z)=F(3yz+x^2,\;2x+2y^2-z^2)$ verilmiş. $G=$ sabit yüzeyinin $(0,1,2)$ noktasındaki teğet düzlemi isteniyor. İkinci şıkta verilen bir $\vec r(t)$ eğrisinin bu düzleme paralel olduğu noktadaki teğet doğrusu isteniyor.
- Ara verildi. Aradan sonra bu soruya dönülmedi. Verilen değerler altyazıda tam anlaşılmıyor.
- Hoca: testte bu soru iki değişkenli, daha kısa haliyle gelir. Kapalı fonksiyon ve zincir kuralı çok önemli.

### Örnek 5: Kare bölgede dönüşüm

- Bölgenin köşeleri: $(0,0)$, $(-\tfrac\pi2,\tfrac\pi2)$, $(-\pi,0)$, $(-\tfrac\pi2,-\tfrac\pi2)$.
- İntegral: $\displaystyle\iint_D (x+y)^2\sin(y-x)\,dA$.
- Sınır doğruları: $x+y=0$, $x+y=-\pi$, $y-x=0$, $y-x=\pi$.
- Dönüşüm: $u=x+y$, $v=y-x$. Yeni bölge dikdörtgen: $-\pi\le u\le0$, $0\le v\le\pi$.
- Jacobian: $\dfrac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}1&1\\-1&1\end{vmatrix}=2 \Rightarrow dx\,dy=\dfrac12\,du\,dv$.
- İntegral: $\displaystyle\frac12\int_0^\pi\int_{-\pi}^0 u^2\sin v\,du\,dv$.
- Hoca sonucu derste hesaplamadı. Sonuç: $\dfrac12\cdot\dfrac{\pi^3}{3}\cdot2=\dfrac{\pi^3}{3}$.

### Örnek 6: Hacim, kutupsal koordinat

- Cisim: $y^2+(z-1)^2=1$ silindiri, $x=2$ ve $x+z=5$ düzlemleri arasında.
- Yükseklik: $(5-z)-2=3-z$.
- Taban bölgesi $yz$-düzleminde $y^2+(z-1)^2\le1$ dairesi.
- Kutupsal: $z=r\cos\theta$, $y=r\sin\theta$, daire $r=2\cos\theta$, $-\tfrac\pi2\le\theta\le\tfrac\pi2$.
- Hacim: $\displaystyle V=\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}(3-r\cos\theta)\,r\,dr\,d\theta$.
- Testte "hacmi veren integral hangisidir" diye sorulur. Sonuç derste hesaplanmadı. Sonuç $2\pi$ (dairenin alanı $\pi$, $z$'nin ortalaması 1, yani $3\pi-\pi$).

### Örnek 7: Seri toplamı

- Seri: $\dfrac34+\dfrac58+\dfrac7{16}+\dfrac9{32}+\cdots$
- Genel terim: $a_n=\dfrac{2n+1}{2^{n+1}}$, $n\ge1$.
- Ayırma: $\displaystyle\sum\frac{2n+1}{2^{n+1}}=\sum\frac{n}{2^n}+\sum\frac{1}{2^{n+1}}$.
- İkinci kısım geometrik seri: toplamı $\tfrac12$.
- Birinci kısım: $\sum x^n=\dfrac{1}{1-x}$ serisinin terim terim türevi alınır, $x$ ile çarpılır: $\sum n x^n=\dfrac{x}{(1-x)^2}$. $x=\tfrac12$ için 2.
- Toplam: $2+\tfrac12=\tfrac52$.

### Örnek 8: Seri karakteri

- Bir serinin karakteri harmonik seriyle limit karşılaştırma testi (limit comparison test) uygulanarak bulunuyor. Limit sıfırdan ve sonsuzdan farklı çıktığı için iki seri aynı karakterde: ıraksak.
- Serinin genel terimi altyazıda anlaşılmıyor.
- Hoca: paydada $n$ yerine $n^2$ veya $n^3$ olsaydı seri yakınsak olurdu.

### Örnek 9 (2020 bütünleme): Gradyan ve teğet düzlem

- $f(P)=2$, $g(P)=5$, $g_x(P)=-1$.
- $f$'nin $P$'deki en hızlı artış yönü $\vec u=\langle1,-8,4\rangle$. Bu yöndeki türev 6.
- $\nabla f(P)=k\langle1,-8,4\rangle$, $|\nabla f(P)|=9k=6 \Rightarrow k=\tfrac23$.
- $\nabla f(P)=\langle\tfrac23,-\tfrac{16}3,\tfrac83\rangle$.
- $H: f+2g-12=0$ yüzeyinin $P$'deki normali $\langle4,2,3\rangle$'e paralel: $\nabla H(P)=\langle4c,2c,3c\rangle$.
- $f_x+2g_x=4c$: $\tfrac23+2(-1)=4c \Rightarrow c=-\tfrac13$.
- İstenen $g_y(P)$: $f_y+2g_y=2c \Rightarrow -\tfrac{16}3+2g_y=-\tfrac23 \Rightarrow g_y(P)=\tfrac73$.

### Örnek 10 (2020 bütünleme, Soru 6): Lineerleştirme

- $f(1,3)=-2$, $f(1{,}02;\,2{,}99)=-1{,}98$. $P(1,3)$'te $\vec v=-4\vec i+2\vec j$ yönündeki türevin yaklaşık değeri isteniyor.
- $-1{,}98\approx-2+f_x(0{,}02)+f_y(-0{,}01) \Rightarrow 2f_x-f_y\approx2$.
- Yönlü türev: $D_{\vec u}f=\nabla f\cdot\dfrac{\vec v}{|\vec v|}=\dfrac{-4f_x+2f_y}{\sqrt{20}}=-\dfrac{2f_x-f_y}{\sqrt5}\approx-\dfrac{2}{\sqrt5}$.
- Son adım derste ekranda kaldı, sesli okunmadı. Sonuç hesaplanarak eklendi.

### Ders sonrası notlar

- Hoca ikinci türev testini anlatırken bir yerde "küçükse maksimum" diyor. Doğrusu: $\Delta<0$ ve $A<0$ ise yerel maksimum, $\Delta<0$ ve $A>0$ ise yerel minimum.
- Örnek 5'te hoca Jacobian determinantındaki tüm türevleri 1 aldı. $v=y-x$ için $v_x=-1$ olur. Determinant 2, Jacobian $\tfrac12$. Hocanın sonucu ($\tfrac12$) doğru.
- Örnek 5'te altyazıda $u$ için "sıfırdan eksi pi'ye" deniyor. Bu, $-\pi\le u\le0$ aralığıdır.
- 00:58:46-00:59:44 arasında hocanın sesi gitmiş. Seri sorusunun bu kısmı altyazıda yok.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
