# Ders 16 Çalışma Özeti

## Genel Konular

- Bu ders 18 Nisan 2023 Salı günü yapıldı. Ramazan Bayramı öncesi son derstir.
- Yeni konuya geçilmedi. Önceki derslerin konuları sınav sorularıyla pekiştirildi.
- Tek değişkenli fonksiyonlarda maksimum ve minimum bulma yöntemleri hatırlatıldı.
- Çok değişkenli fonksiyonlarda kritik nokta (critical point), yerel ekstremum (local extremum) ve eyer noktası (saddle point) işlendi.
- İkinci türev testi (second derivative test) tablo ile uygulandı.
- İki değişkenli fonksiyonlarda Taylor açılımı (Taylor expansion) ikinci mertebeye kadar yazıldı.
- Kısıtlı değişkenlerle kısmi türev (partial derivative with constrained variables) soruları çözüldü.
- Zincir kuralı (chain rule) ile kutupsal dönüşüm ve kapalı fonksiyon (implicit function) soruları çözüldü.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ekstremum soruları vize ve finalde sık çıkıyor. Hoca bunları "tam sınav sorusu" diye niteledi.
- Bütün yöntemleri bilmek gerekir. Hoca bunu araba ve motosiklet benzetmesiyle anlattı: biri girmediği yere öbürü girer.
- İkinci türev testinde $B^2-AC=0$ ise test sonuç vermez. Başka yönteme geçilir.
- İki değişkenli Taylor açılımında sınavda en fazla ikinci mertebe terimler sorulur.
- Test sınavında hesap hatası lüksü yoktur. Şıklar birbirine yakın (2, 3, 4 gibi) verilir.
- Kısıtlı türev sorularında önce hangi değişkenlerin bağımsız, hangilerinin bağımlı olduğu belirlenmelidir.
- Taylor açılımında bazen ilk birkaç terim bile doğru şıkkı bulmaya yeter.
- Sınav konularının nereye kadar olduğunu Matematik bölümü sayfası ilan eder. Bölüm bunu hocalardan gelen bilgiye göre belirler.

## Kısa Tekrar Notları

- **Kritik nokta:** $f_x(a,b)=0$ ve $f_y(a,b)=0$ olan ya da kısmi türevlerin tanımsız olduğu nokta.
- **Yerel minimum:** küçük $h,k$ için $f(a+h,b+k)-f(a,b)\ge 0$.
- **Yerel maksimum:** küçük $h,k$ için $f(a+h,b+k)-f(a,b)\le 0$.
- **Eyer noktası:** kritik noktadır ama yerel maksimum da yerel minimum da değildir.
- **İkinci türev testi:** $A=f_{xx}(a,b)$, $B=f_{xy}(a,b)$, $C=f_{yy}(a,b)$.
  - $B^2-AC<0$ ve $A>0$ ise yerel minimum.
  - $B^2-AC<0$ ve $A<0$ ise yerel maksimum.
  - $B^2-AC>0$ ise eyer noktası.
  - $B^2-AC=0$ ise test sonuç vermez.
- **İki değişkenli Taylor açılımı ($(a,b)$ civarında, ikinci mertebeye kadar):**

$$f(x,y)\approx f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)+\frac{1}{2!}\Big[f_{xx}(a,b)(x-a)^2+2f_{xy}(a,b)(x-a)(y-b)+f_{yy}(a,b)(y-b)^2\Big]$$

- **Kapalı fonksiyonun türevi:** $F(x,y,z)=0$ ise $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$, $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}$.

## Detaylı Açıklamalar

### Tek Değişkenli Fonksiyonlarda Ekstremum (Hatırlatma)

Hoca tahtada üç yolu hatırlattı.

- **1. yol (tanım):** $f'(x)=0$ çözülür, kritik noktalar bulunur. Her $x$ için $f(a)\ge f(x)$ ise $a$'da maksimum, $f(a)\le f(x)$ ise minimum vardır.
- **2. yol (işaret tablosu):** Türevin işaretine bakılır. Türev artıdan eksiye geçiyorsa fonksiyon önce artar sonra azalır, o noktada maksimum vardır. Eksiden artıya geçiyorsa minimum vardır.
- **3. yol (ikinci türev):** Kritik noktada $f''(a)>0$ ise minimum, $f''(a)<0$ ise maksimum vardır.

### Çok Değişkenli Fonksiyonlarda Ekstremum

**Tanım (yerel ekstremum):**
- $(a,b)$ civarındaki her $(x,y)$ için $f(x,y)\le f(a,b)$ ise $f$, $(a,b)$'de yerel maksimuma sahiptir.
- $f(x,y)\ge f(a,b)$ ise yerel minimuma sahiptir.
- Yerel maksimum ya da yerel minimum varsa o noktada ekstremum vardır.

**Teorem (kritik nokta):** $(a,b)$ tanım kümesinde olsun. Aşağıdakilerden biri sağlanıyorsa $(a,b)$ kritik noktadır:
- $f_x(a,b)=0$ ve $f_y(a,b)=0$.
- $f_x(a,b)$ ya da $f_y(a,b)$ mevcut değil.

**Eyer noktası:** Kritik nokta olup yerel maksimum ya da yerel minimum olmayan noktadır. Hoca, şıklı sorularda "aşağıdakilerden hangisi doğrudur" diye sorulabileceğini söyledi.

**Örnek 1 (sınav sorusu, Ç.02B):** $f(x,y)=x^2+y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırın.
- $f_x=2x=0$, $f_y=2y=0$. Kritik nokta $(0,0)$.
- $f(0+h,0+k)-f(0,0)=h^2+k^2\ge 0$.
- Sonuç: $(0,0)$ yerel minimum noktası.

**Örnek 2:** $f(x,y)=(x+y)^2+y^4$.
- $f_x=2x+2y=0$, $f_y=2x+2y+4y^3=0$.
- İki denklemden $4y^3=0$, yani $y=0$, $x=0$. Kritik nokta $(0,0)$.
- $f(0+h,0+k)-f(0,0)=(h+k)^2+k^4\ge 0$.
- Sonuç: $(0,0)$ yerel minimum.

**Örnek 3:** Kritik noktası $(0,0)$ olan bir fonksiyonda fark $h^2-k^2$ çıkıyor. Fonksiyon altyazıda okunmuyor; büyük olasılıkla $f(x,y)=x^2-y^2$.
- $h^2-k^2$ ifadesinin işareti belli değil. Bazı $(h,k)$ için pozitif, bazıları için negatif.
- Sonuç: $(0,0)$ eyer noktası.

**İkinci türev testi:** Fonksiyonun birinci ve ikinci mertebe kısmi türevleri sürekli olsun. $(a,b)$ kritik nokta olsun.
- $A=f_{xx}(a,b)$, $B=f_{xy}(a,b)$, $C=f_{yy}(a,b)$ alınır.
- $B^2-AC<0$ ise $A$'nın işaretine bakılır. $A>0$ ise yerel minimum, $A<0$ ise yerel maksimum.
- $B^2-AC>0$ ise eyer noktası.
- $B^2-AC=0$ ise test sonuç vermez.

**Örnek 4:** Kısmi türevleri $f_x=6x^2-6y$ ve $f_y=-6x+6y$ olan fonksiyon, yani $f(x,y)=2x^3-6xy+3y^2$.
- $f_y=0$'dan $x=y$. Bunu $f_x=0$'a koyunca $6x^2-6x=0$, yani $x=0$ ya da $x=1$.
- Kritik noktalar: $(0,0)$ ve $(1,1)$.
- $A=12x$, $B=-6$, $C=6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $0$ | $-6$ | $6$ | $36>0$ | Eyer noktası |
| $(1,1)$ | $12$ | $-6$ | $6$ | $36-72=-36<0$ | $A>0$, yerel minimum |

**Örnek 5 (tahtadan):** $f(x,y)=x^3-3x^2+3xy^2-3y^2$.
- $f_x=3x^2-6x+3y^2=0$ (1), $f_y=6xy-6y=6y(x-1)=0$ (2).
- (2)'den $y=0$ ya da $x=1$.
- $x=1$ ise (1)'den $y^2=1$, yani $y=\pm1$. Noktalar $(1,1)$, $(1,-1)$.
- $y=0$ ise (1)'den $3x^2-6x=0$, yani $x=0$ ya da $x=2$. Noktalar $(0,0)$, $(2,0)$.
- $A=f_{xx}=6x-6$, $B=f_{xy}=6y$, $C=f_{yy}=6x-6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $-6$ | $0$ | $-6$ | $-36<0$ | $A<0$, yerel maksimum |
| $(1,1)$ | $0$ | $6$ | $0$ | $36>0$ | Eyer noktası |
| $(1,-1)$ | $0$ | $-6$ | $0$ | $36>0$ | Eyer noktası |
| $(2,0)$ | $6$ | $0$ | $6$ | $-36<0$ | $A>0$, yerel minimum |

### Taylor Açılımı

**Tek değişkenli hatırlatma:**

$$f(x)=\sum_{k=0}^{\infty}\frac{f^{(k)}(x_0)}{k!}(x-x_0)^k$$

- Sonsuz yerine $n$'e kadar alınırsa Taylor polinomu elde edilir.
- $x_0=0$ ise açılıma Maclaurin açılımı denir.
- Hoca, fonksiyonu seriyle yaklaşık yazmanın mekatronik, uçak ve diğer uygulamalı alanlarda çok kullanıldığını söyledi.

**İki değişkenli Taylor açılımı:** Formül "Kısa Tekrar Notları"ndadır. Hoca sınavda en fazla ikinci mertebe terimlerin sorulacağını söyledi.

**Örnek 6 (sınav sorusu):** $f(x,y)=e^x\sin y$ fonksiyonunun $(0,\pi/2)$ noktasında ikinci mertebe türevlerin bulunduğu terime kadar Taylor açılımını yazın.
- $f(0,\pi/2)=1$.
- $f_x=e^x\sin y$, $f_x(0,\pi/2)=1$.
- $f_y=e^x\cos y$, $f_y(0,\pi/2)=0$.
- $f_{xx}=e^x\sin y$, değeri $1$.
- $f_{xy}=e^x\cos y$, değeri $0$.
- $f_{yy}=-e^x\sin y$, değeri $-1$.
- Sonuç:

$$f(x,y)\approx 1+x+\frac{x^2}{2}-\frac{1}{2}\left(y-\frac{\pi}{2}\right)^2$$

### Kısıtlı Değişkenlerle Kısmi Türev

- $\left(\dfrac{\partial w}{\partial x}\right)_y$ gösterimi: $x$ ve $y$ bağımsız değişkendir. Geri kalan değişkenler bağımlıdır.
- Bağımlı değişken türevde zincir kuralıyla türetilir. Kapalı denklemden gelen türev $-F_x/F_z$ formülüyle bulunur.

**Örnek 7 (sınav sorusu):** $w=x^2+y^2+z^2$, $z^3-xy+yz+y^3=1$. $(2,-1,1)$ noktasında $\left(\dfrac{\partial w}{\partial x}\right)_y$ nedir?
- Bağımsız: $x,y$. Bağımlı: $w,z$.
- $\dfrac{\partial w}{\partial x}=2x+2z\dfrac{\partial z}{\partial x}$.
- $F=z^3-xy+yz+y^3-1=0$ alınır. $F_x=-y$, $F_z=3z^2+y$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}=\dfrac{y}{3z^2+y}$.
- $(2,-1,1)$'de: $2\cdot2+2\cdot1\cdot\dfrac{-1}{3-1}=4-1=3$.

**Örnek 8:** $w=x^2+y-z+\sin t$ ve $t=x+y$ ise $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}$ nedir?
- Bağımsız: $x,y,z$. Bağımlı: $w,t$.
- $\dfrac{\partial w}{\partial x}=2x+\cos t\cdot\dfrac{\partial t}{\partial x}=2x+\cos(x+y)$.
- Altyazıda $t$ harfi "Trabzon" diye geçiyor.

**Örnek 9:** $w=x^2+y^2+z^2$, $y\sin z+z\sin x=0$. $(0,1,\pi)$ noktasında $\left(\dfrac{\partial w}{\partial y}\right)_x$ nedir?
- Bağımsız: $x,y$. Bağımlı: $w,z$.
- $\dfrac{\partial w}{\partial y}=2y+2z\dfrac{\partial z}{\partial y}$.
- $F_y=\sin z$, $F_z=y\cos z+\sin x$. Yani $\dfrac{\partial z}{\partial y}=-\dfrac{\sin z}{y\cos z+\sin x}$.
- $(0,1,\pi)$'de $\sin\pi=0$ olduğu için ikinci terim sıfır. Sonuç: $2\cdot1=2$.
- Aynı sorunun $\left(\dfrac{\partial w}{\partial y}\right)_z$ kısmı tahtada başlatıldı, derste çözülmedi.

### Zincir Kuralı Soruları

**Örnek 10 (7. uygulama, S.4-a, 12 puan):** $f$, birinci mertebe kısmi türevleri mevcut iki değişkenli bir fonksiyon ve $z=f(x,y)$ olsun. $x=r\cos\theta$, $y=r\sin\theta$ dönüşümü yapılırsa $y\dfrac{\partial z}{\partial x}-x\dfrac{\partial z}{\partial y}=0$ denklemi hangi şekli alır?
- $\dfrac{\partial z}{\partial\theta}=\dfrac{\partial z}{\partial x}\dfrac{\partial x}{\partial\theta}+\dfrac{\partial z}{\partial y}\dfrac{\partial y}{\partial\theta}$.
- $\dfrac{\partial x}{\partial\theta}=-r\sin\theta=-y$, $\dfrac{\partial y}{\partial\theta}=r\cos\theta=x$.
- $\dfrac{\partial z}{\partial\theta}=-y\dfrac{\partial z}{\partial x}+x\dfrac{\partial z}{\partial y}=-\left(y\dfrac{\partial z}{\partial x}-x\dfrac{\partial z}{\partial y}\right)=0$.
- Sonuç: denklem $\dfrac{\partial z}{\partial\theta}=0$ olur.
- Notta ikinci yol ($r=\sqrt{x^2+y^2}$, $\theta=\arctan(y/x)$) da var. Hoca bunu daha karışık bulduğu için anlatmadı.

**Örnek 11 (sınav sorusu):** $z=z(x,y)$ sabit olmayan bir fonksiyon. $\varphi\!\left(2x-z^2,\;y-\dfrac{z^3}{3}\right)=0$ denklemiyle kapalı olarak tanımlanıyor. $\dfrac{\partial z}{\partial x}+z\dfrac{\partial z}{\partial y}$ nedir?
- Hocanın yöntemi: İkinci bileşen birincinin fonksiyonu olarak yazılır: $y-\dfrac{z^3}{3}=g(2x-z^2)$.
- Böylece $F(x,y,z)=g(2x-z^2)-y+\dfrac{z^3}{3}=0$ olur.
- $F_x=2g'$, $F_y=-1$, $F_z=-2z\,g'+z^2$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{2g'}{z^2-2zg'}$, $\dfrac{\partial z}{\partial y}=\dfrac{1}{z^2-2zg'}$.
- $\dfrac{\partial z}{\partial x}+z\dfrac{\partial z}{\partial y}=\dfrac{-2g'+z}{z(z-2g')}=\dfrac{1}{z}$.
- Sonuç: $\dfrac{1}{z}$.

### Ders sonrası notlar

- Hoca yerel minimum tanımını "pozitif $h$ ve $k$ için" diye okudu. Doğrusu: $h$ ve $k$, sıfıra yakın **her işaretten** değer alır. Örnek 3'te $h^2-k^2$'nin işareti tam da bu yüzden belirsizdir: $k=0$ alınırsa pozitif, $h=0$ alınırsa negatif olur.
- İkinci türev testi anlatılırken önce "$c^2$ eksi $a$ çarpı $b$", sonra "$B^2-4AC$, pardon $B^2-AC$" dendi. Doğru ifade $f_{xy}^2-f_{xx}f_{yy}$, yani $B^2-AC$ ($A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$).
- Örnek 4'te hoca $(0,0)$'ı önce "minimum" gibi söyledi, tabloda doğru olarak eyer noktası çıktı.
- Altyazıda "eğer noktası" ve "E'ye noktası" diye geçen terim **eyer noktası**dır.
- Örnek 9'un $(\partial w/\partial y)_z$ kısmı derste bitmedi. Bu durumda $y,z$ bağımsızdır, $x$ bağımlıdır: $\dfrac{\partial x}{\partial y}=-\dfrac{F_y}{F_x}=-\dfrac{\sin z}{z\cos x}$. $(0,1,\pi)$'de $\sin\pi=0$ olduğu için bu sıfırdır ve $\left(\dfrac{\partial w}{\partial y}\right)_z=2y=2$.
- Ders "Bayramdan sonra görüşmek üzere" diye bitti.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
