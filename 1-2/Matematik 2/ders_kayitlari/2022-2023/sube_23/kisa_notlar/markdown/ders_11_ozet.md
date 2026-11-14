# Ders 11 Çalışma Özeti

## Genel Konular

- Ders 3 Nisan 2023 Pazartesi günü yapıldı. Hoca bu tarihten itibaren eğitimin hibrit (hybrid) olarak başladığını söyledi.
- Çok değişkenli fonksiyonlar, tanım bölgesi, temel yüzeyler ve seviye eğrileri için kısa tekrar.
- Limit ve süreklilik: eksenler boyunca yaklaşma, ardışık limit, çift yol testi, sıkıştırma teoremi.
- Kısmi türev (partial derivative): tanım, gösterimler, kurallar ve örnekler.
- Kısmi türevin geometrik anlamı.
- Basit zincir kuralı (chain rule).
- İkiden fazla değişkenli fonksiyonların kısmi türevleri.
- Yüksek mertebeden kısmi türevler ve karışık türev teoremi (Clairaut / Schwarz).

## Hocanın Özellikle Vurguladığı Kısımlar

- Tanım bölgesi sorusu sınavda mutlaka gelir. Hoca konular karışmadan 20-25 soru çözülmesini istiyor.
- 3 boyutlu yüzeyleri çizebilmek limit, türev ve özellikle integral için gerekli.
- Limit sorusunda önce eksenler boyunca yaklaşılır. Sonuçlar farklıysa limit yoktur, iş biter. Aynıysa $y=kx$, $y=kx^2$ gibi yollar denenir.
- Şıklarda 0, 1, 2 gibi sayılar verilip doğru cevap "limit yoktur" olabilir. $k$'ya bağlı sonuç çıkınca limit yoktur.
- Limit yoksa fonksiyon o noktada sürekli değildir.
- Kısmi türev alınırken diğer değişkenler sabit gibi düşünülür.
- $f_{xy}=f_{yx}$ eşitliği her zaman doğru değildir. Kısmi türevler sürekli olmalıdır.
- Zincir kuralı içeren "gösteriniz" soruları sınavlarda sık çıkıyor.
- Hoca konuyu anlamanın yetmediğini, bol soru çözerek "pişirmek" gerektiğini söyledi.

## Kısa Tekrar Notları

- $f_x(x,y)=\displaystyle\lim_{h\to0}\frac{f(x+h,y)-f(x,y)}{h}$, $f_y(x,y)=\displaystyle\lim_{h\to0}\frac{f(x,y+h)-f(x,y)}{h}$.
- Gösterimler: $\dfrac{\partial f}{\partial x}=f_x=f_1=\dfrac{\partial z}{\partial x}$; $\dfrac{\partial f}{\partial y}=f_y=f_2=\dfrac{\partial z}{\partial y}$.
- Toplam, çarpım ve bölüm için geçerli bütün türev kuralları kısmi türevler için de geçerlidir.
- Zincir kuralı: $z=f(g(x,y))$ ise $z_x=f'(g)\,g_x$, $z_y=f'(g)\,g_y$.
- İkinci mertebe: $f_{xx}=\dfrac{\partial^2 f}{\partial x^2}$, $f_{xy}=\dfrac{\partial}{\partial y}\left(\dfrac{\partial f}{\partial x}\right)$, $\dfrac{\partial^2 f}{\partial x\,\partial y}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial f}{\partial y}\right)$.
- Karışık türev teoremi: kısmi türevler bir bölgede sürekliyse $f_{xy}=f_{yx}$.

## Detaylı Açıklamalar

### Tekrar: tanım bölgesi ve yüzeyler

- $z=\dfrac{1}{\sqrt{1-x^2-y^2}}$ tipi soruda bölge $x^2+y^2<1$, açık daire. Şıklarda sınırı dahil gösteren seçenek de verilebilir; dikkat edilmeli.
- İki köklü örnekte bölge $1\le x^2+y^2<4$.
- $\ln\left[x\ln(y-x)\right]$ örneği: $x>0$, $y>x+1$ ya da $x<0$, $x<y<x+1$ (ayrıntı ders 10'da).
- $z=x^2+y^2$ çizimi: $z=0$ için orijin, $y=0$ için $z=x^2$ parabolü, $x=0$ için $z=y^2$ parabolü. Birleşince paraboloid.
- $f(x,y)=100-x^2-y^2$ için $f=0$, $51$, $75$ seviye eğrileri yarıçapı 10, 7 ve 5 olan çemberler.

### Tekrar: limit ve süreklilik

**Örnek 1.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x^2-xy}{\sqrt{x}-\sqrt{y}}$.

- $0/0$ belirsizliği var.
- Pay $x(x-y)$, pay ve payda $\sqrt x+\sqrt y$ ile çarpılır. Payda $x-y$ olur ve sadeleşir.
- Kalan $x(\sqrt x+\sqrt y)\to 0$.
- Hoca ardışık limitlerle de baktı: iki sıra için de sonuç 0. "Çözüm yolu tek değil" dedi.

**Örnek 2.** $f(x,y)=x^2\sin\dfrac1y$ için sıkıştırma teoremi.

- $-x^2\le x^2\sin\dfrac1y\le x^2$, iki tarafın limiti 0. Limit 0.

**Örnek 3.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{2x^2y}{x^4+y^2}$.

- Eksenler boyunca: iki sıra için de 0. Aynı çıktığı için ikinci adıma geçilir.
- $y=kx$ boyunca: $\dfrac{2kx^3}{x^4+k^2x^2}=\dfrac{2kx}{x^2+k^2}\to 0$. Bu yol da 0 verir; karar vermeye yetmez.
- $y=kx^2$ boyunca: $\dfrac{2kx^4}{x^4(1+k^2)}=\dfrac{2k}{1+k^2}$. Sonuç $k$'ya bağlı. Limit yoktur.
- Hoca şıklarda 0 gibi bir sayı verilerek öğrencinin yanıltılabileceğini söyledi. Payda $x^4+y^2$ olduğu için doğrudan $y=kx^2$ ile başlamak işi kısaltır.

**Örnek 4.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{3x^2-y^2}{3y^2+x^2}$ (ders 10'daki soru).

- $y=kx$: $\dfrac{3-k^2}{3k^2+1}$, $k$'ya bağlı.
- $y=x$ boyunca $\dfrac12$, $y=x^2$ boyunca 3. Farklı.
- Ardışık limitler 3 ve $-\dfrac13$. Farklı. Limit yok.

**Örnek 5.** $f(x,y)=\dfrac{\sin(xy)}{x^2+y^2}$, $(x,y)\ne(0,0)$; $f(0,0)=0$. Süreklilik.

- $y=kx$ boyunca: $\dfrac{\sin(kx^2)}{x^2(1+k^2)}=k\cdot\dfrac{\sin(kx^2)}{kx^2}\cdot\dfrac{1}{1+k^2}\to\dfrac{k}{1+k^2}$.
- $k=1$ için $\dfrac12$, $k=2$ için $\dfrac25$. Sonuç $k$'ya bağlı, limit yok.
- Limit olmadığı için fonksiyon $(0,0)$'da sürekli değildir.
- Hoca $y=kx$ seçiminin nedeni olarak paydada $x^2$ parantezine alınabilmesini gösterdi.

### Kısmi türev

**Tanım (Kısmi türev).**

- $f$'nin $x$'e göre kısmi türevi: $y$ sabit tutulur, yalnız $x$ $h$ kadar artırılır. $f_x=\displaystyle\lim_{h\to0}\frac{f(x+h,y)-f(x,y)}{h}$.
- $f$'nin $y$'ye göre kısmi türevi: $x$ sabit tutulur. $f_y=\displaystyle\lim_{h\to0}\frac{f(x,y+h)-f(x,y)}{h}$.
- Limit mevcutsa kısmi türev vardır.
- Bir noktadaki değer: $\left.\dfrac{\partial z}{\partial x}\right|_{(a,b)}=f_x(a,b)=f_1(a,b)$, $\left.\dfrac{\partial z}{\partial y}\right|_{(a,b)}=f_y(a,b)=f_2(a,b)$.

**Örnek 6.** $z=x^3y^2+x^4y+4x^3y^4+y^2$ (büyük olasılıkla (ekrandan)).

- $\dfrac{\partial z}{\partial x}=3x^2y^2+4x^3y+12x^2y^4$. $y^2$ terimi $x$'e göre sabittir, türevi 0.
- $\dfrac{\partial z}{\partial y}=2x^3y+x^4+16x^3y^3+2y$.

**Örnek 7.** $f(x,y)=e^{xy}\cos(x+y)$, $f_1(0,\pi)=?$

- Çarpımın türevi kullanılır, $y$ sabit.
- $f_1(x,y)=y\,e^{xy}\cos(x+y)-e^{xy}\sin(x+y)$.
- $f_1(0,\pi)=\pi\cdot 1\cdot\cos\pi-1\cdot\sin\pi=-\pi$.
- Derste çözümde önce eksi işareti kaçtı; çarpım kuralı hatırlatılarak düzeltildi.

**Örnek 8.** $f(x,y)=x^2y$, tanımdan kısmi türevler.

- $f_x=\displaystyle\lim_{h\to0}\frac{(x+h)^2y-x^2y}{h}=\lim_{h\to0}\frac{2xhy+h^2y}{h}=2xy$.
- $f_y=\displaystyle\lim_{h\to0}\frac{x^2(y+h)-x^2y}{h}=x^2$.
- Kurallarla bulunan sonuçla aynıdır.

**Örnek 9.** $f(x,y)=(x^2+y^2)\sin\dfrac{1}{\sqrt{x^2+y^2}}$, $(x,y)\ne(0,0)$; $f(0,0)=0$ (büyük olasılıkla (ekrandan)).

- Süreklilik: $-(x^2+y^2)\le f(x,y)\le x^2+y^2$. İki tarafın limiti 0. Sıkıştırma teoremiyle limit 0. $f(0,0)=0$. Fonksiyon süreklidir.
- $f_x(0,0)=\displaystyle\lim_{h\to0}\frac{f(h,0)-f(0,0)}{h}=\lim_{h\to0}\frac{h^2\sin\frac{1}{\sqrt{h^2}}}{h}=\lim_{h\to0}h\sin\frac{1}{|h|}$.
- $-|h|\le h\sin\dfrac{1}{|h|}\le|h|$. Sonuç 0.
- $f_y(0,0)$ aynı yolla 0.
- Hoca bunu çoktan seçmeli soru gibi sordu: "sürekli mi, limit var mı, $f_x(0,0)$, $f_y(0,0)$ nedir?" Hepsinin cevabı: sürekli, limit 0, iki kısmi türev de 0.

### Kısmi türevin geometrik anlamı (büyük olasılıkla (ekrandan))

- $z=f(x,y)$ yüzeyi $y=y_0$ düzlemiyle kesilince $z=f(x,y_0)$ eğrisi oluşur.
- Bu eğrinin $P(x_0,y_0,f(x_0,y_0))$ noktasındaki eğimi $f_x(x_0,y_0)$'dır.
- Benzer şekilde $x=x_0$ düzlemindeki $z=f(x_0,y)$ eğrisinin eğimi $f_y(x_0,y_0)$'dır.
- Eğrinin $P$'deki teğet doğrusu bu eğimle $P$'den geçen doğrudur.

### Basit zincir kuralı

**Kural.** $z=f(g(x,y))$ ise:

- $\dfrac{\partial z}{\partial x}=f'(g)\cdot\dfrac{\partial g}{\partial x}$
- $\dfrac{\partial z}{\partial y}=f'(g)\cdot\dfrac{\partial g}{\partial y}$

**Örnek 10.** $z=f\left(\dfrac{x}{y}\right)$ ise $x\dfrac{\partial z}{\partial x}+y\dfrac{\partial z}{\partial y}=0$ olduğunu gösteriniz.

- $\dfrac{\partial z}{\partial x}=f'\left(\dfrac xy\right)\cdot\dfrac1y$.
- $\dfrac{\partial z}{\partial y}=f'\left(\dfrac xy\right)\cdot\left(-\dfrac{x}{y^2}\right)$.
- $x\cdot\dfrac1y f'-y\cdot\dfrac{x}{y^2}f'=\dfrac xy f'-\dfrac xy f'=0$.
- Hoca bu tip sorunun farklı sınavlarda çıktığını söyledi ve soruyu iki kez çözdü.

### İkiden fazla değişkenli fonksiyonlar

- $z=f(x_1,x_2,\dots,x_n)$ için her değişkene göre bir kısmi türev vardır: $f_1,f_2,\dots,f_n$.
- Örneğin üçüncü değişkene göre: $f_3=\displaystyle\lim_{h\to0}\frac{f(x_1,x_2,x_3+h,\dots,x_n)-f(x_1,\dots,x_n)}{h}$. Artış yalnız üçüncü değişkene verilir.

**Örnek 11.** $f(x,y,z)=\dfrac{2xy}{1+xz+y^2}$.

- $z$'ye göre: pay $z$ içermez, türevi 0. $f_z=\dfrac{0\cdot(1+xz+y^2)-x\cdot 2xy}{(1+xz+y^2)^2}=-\dfrac{2x^2y}{(1+xz+y^2)^2}$.
- $x$'e göre: $f_x=\dfrac{2y(1+xz+y^2)-z\cdot 2xy}{(1+xz+y^2)^2}=\dfrac{2y(1+y^2)}{(1+xz+y^2)^2}$.

### Yüksek mertebeden türevler

- $\dfrac{\partial^2 z}{\partial x^2}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial z}{\partial x}\right)$: önce birinci türev alınır, sonra yine $x$'e göre türev alınır. $f_{11}$ ya da $f_{xx}$ diye de yazılır.
- $\dfrac{\partial^2 z}{\partial x\,\partial y}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial z}{\partial y}\right)$: önce $y$'ye, sonra $x$'e göre.

**Örnek 12.** $f(x,y)=x\cos y+y\,e^x$ (sınav sorusu).

- $f_x=\cos y+y\,e^x$, $f_y=-x\sin y+e^x$.
- $\dfrac{\partial^2 f}{\partial x^2}=y\,e^x$.
- $\dfrac{\partial^2 f}{\partial y^2}=-x\cos y$.
- $\dfrac{\partial^2 f}{\partial x\,\partial y}=\dfrac{\partial}{\partial x}\left(-x\sin y+e^x\right)=-\sin y+e^x$.

**Örnek 13.** $z=\ln(x^2+y^2)$ için $\dfrac{\partial^2 z}{\partial x^2}+\dfrac{\partial^2 z}{\partial y^2}=0$.

- $z_x=\dfrac{2x}{x^2+y^2}$, $z_y=\dfrac{2y}{x^2+y^2}$.
- $z_{xx}=\dfrac{2(y^2-x^2)}{(x^2+y^2)^2}$, $z_{yy}=\dfrac{2(x^2-y^2)}{(x^2+y^2)^2}$.
- Toplam 0. Derste ikinci türevler sesli okunmadı; sonuçlar bu yolla bulunur.

**Teorem (Karışık türev teoremi).**

- $f$, $f_x$, $f_y$, $f_{xy}$ ve $f_{yx}$, $(a,b)$'yi içeren bir açık bölgede tanımlı ve $(a,b)$'de sürekliyse $f_{xy}(a,b)=f_{yx}(a,b)$.
- Kısmi türevler sürekli değilse türev alma sırası sonucu değiştirebilir.

**Örnek 14.** Ders sonu örneği (büyük olasılıkla (ekrandan)): $f(x,y)=0$ ($xy\ne0$), $f(x,y)=1$ ($xy=0$).

- a) $y=x$ boyunca, orijin hariç $xy\ne0$'dır. Bu yol boyunca limit 0.
- b) $f(0,0)=1$. $y=x$ boyunca limit 0, $f(0,0)$'dan farklı. Fonksiyon $(0,0)$'da sürekli değil.
- c) Eksenler üzerinde $f=1$. $f_x(0,0)=\displaystyle\lim_{h\to0}\frac{f(h,0)-f(0,0)}{h}=\frac{1-1}{h}=0$. Aynı şekilde $f_y(0,0)=0$. Kısmi türevler mevcut.
- Bu örnek, kısmi türevleri olan bir fonksiyonun sürekli olmayabileceğini gösterir.

### Ders sonrası notlar

- **Örnek 14:** Hoca "limit var, sıfır çıktı" dedi. Doğrusu: $y=x$ boyunca limit 0, eksenler boyunca ise $f=1$ olduğu için limit 1. $(0,0)$'da iki değişkenli limit yoktur. Sonuç yine aynıdır: fonksiyon sürekli değildir.
- **Örnek 6:** Hocanın ekrana elle yazdığı satırda $12x^2$ teriminden sonra $y^4$ eksik kaldı. Basılı çözümdeki $12x^2y^4$ doğrudur.
- **Örnek 3:** $y=kx$ boyunca sonuç $k$'ya bağlı değil, 0 çıkar. Bu, limitin var olduğunu göstermez. Limitin yokluğunu $y=kx^2$ yolu gösterir.
- **Karışık türev:** Hoca teoremi "sürekliyse eşittir, yoksa değildir" diye özetledi. Doğru ifade: süreklilik eşitlik için yeterli koşuldur. Süreklilik yoksa eşitlik bozulabilir, ama her zaman bozulmaz.

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
