# Ders 11 Genişletilmiş Notu: Limit ve Süreklilik Tekrarı, Kısmi Türevler, Zincir Kuralı ve Karışık Türevler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş ve Önceki Konuların Hatırlatılması
- 2. Tekrar: Çok Değişkenli Fonksiyonlar ve Tanım Bölgesi
- 3. Tekrar: Yüzeyler ve Seviye Eğrileri
- 4. Tekrar: Limit ve Süreklilik
- 5. Kısmi Türev
- 6. Kısmi Türevin Geometrik Anlamı
- 7. Basit Zincir Kuralı
- 8. İkiden Fazla Değişkenli Fonksiyonların Kısmi Türevleri
- 9. Yüksek Mertebeden Kısmi Türevler ve Karışık Türev Teoremi
- 10. Ders Sonu Örneği: Kısmi Türevleri Olan Ama Sürekli Olmayan Fonksiyon
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş ve Önceki Konuların Hatırlatılması

Hoca derse yeni dönemin hayırlı olmasını dileyerek başladı ve eğitimin bu günden itibaren hibrit (hybrid) olarak başladığını söyledi. Ders yine çevrim içi yürütüldü.

Hoca şimdiye kadar işlenen konuları kısaca saydı: seriler bitirildi, ardından eğriler, vektörler, düzlemler, doğrular ve düzlemlerin birbirine göre durumları görüldü. Son olarak çok değişkenli fonksiyonlara giriş yapıldı. Bu konuda biraz ilerlendi ama sorulara geçilmedi. Bu yüzden ders, kısa bir tekrarla başlayıp sorularla devam etti.

## 2. Tekrar: Çok Değişkenli Fonksiyonlar ve Tanım Bölgesi

### 2.1 İki ve Üç Değişkenli Fonksiyonlar

Çok değişkenli fonksiyonlar iki değişkenliden başlar. $z=f(x,y)$ yazdığımızda tanım kümesi $x$ ve $y$ değişkenlerinden oluşur, yani $\mathbb{R}^2$'nin bir alt kümesidir. Fonksiyon bu ikilileri $\mathbb{R}$'ye götürür; görüntülerin bulunduğu kümeye değer kümesi denir. İki değişkenli bir fonksiyon $F(x,y,z)=0$ biçiminde kapalı olarak da ifade edilebilir.

Hoca öğrencilere $u=f(x,y,z)$ fonksiyonunun kaç değişkenli olduğunu sordu. Cevap: üç bağımsız değişken vardır ($x$, $y$, $z$). Fonksiyon $\mathbb{R}^3$'ten $\mathbb{R}$'ye gider. Genel olarak $n$ değişkenli bir fonksiyon $u=f(x_1,x_2,\dots,x_n)$ biçiminde yazılır.

### 2.2 Tanım Bölgesi Soruları

**Örnek 1 (sınav sorusu).** $z=\dfrac{1}{\sqrt{1-x^2-y^2}}$ fonksiyonunun tanım kümesi ve şekli nedir?

- Kök içi negatif olamaz. Kök paydada olduğu için sıfır da olamaz.
- Koşul: $1-x^2-y^2>0$, yani $x^2+y^2<1$.
- Bölge: merkezi orijin, yarıçapı 1 olan açık daire. Hoca "çember değil daire diyelim, çünkü iç kısmı var" dedi.

> **Hocanın vurgusu:** Şıklarda sınırı dahil eden ($x^2+y^2\le1$) bir seçenek de verilebilir. Eşitlik olmadığı için sınır çemberi bölgeye dahil değildir; dikkat edin.

**Örnek 2.** İki ifadenin ortak olduğu bir soruda her birinin tanım bölgesi ayrı bulunur ve kesiştirilir. Birinin koşulu kök içinin sıfırdan büyük olması, diğerininki logaritma içinin sıfırdan büyük olmasıdır. Kesişim, yarıçapı 1 olan çemberin dışı ile yarıçapı 2 olan çemberin içi arasındaki halkadır: $1\le x^2+y^2<4$. Sınırdaki 1 dahil, 4 dahil değildir.

<!-- BELİRSİZ: Bu örnekteki iki ifadenin tam biçimi altyazıda okunmuyor; yalnız sonuç bölge ($1\le x^2+y^2<4$) sözlü olarak söyleniyor. -->

> **Hocanın vurgusu:** Tanım bölgesi soruları sınavda gelebilecek sorulardan biridir. Konular ilerleyip karışmadan bu tipten 20-25 soru çözülmeli, beyne yerleşmelidir.

**Örnek 3 (geçmiş yıl sınav sorusu).** $z=\ln\left[x\ln(y-x)\right]$ fonksiyonunun tanım bölgesi.

Dış logaritmanın içi pozitif olmalıdır: $x\ln(y-x)>0$. İki çarpanın çarpımının pozitif olması için iki durum vardır:

- **İkisi de pozitif:** $x>0$ ve $\ln(y-x)>0$. Logaritması pozitif olan sayılar 1'den büyük sayılardır, çünkü 0 ile 1 arasındaki sayıların logaritması negatiftir. O halde $y-x>1$, yani $y>x+1$. Bölge: $x>0$ iken $y=x+1$ doğrusunun üst tarafı.
- **İkisi de negatif:** $x<0$ ve $\ln(y-x)<0$. Bunun için iç ifade 0 ile 1 arasında olmalıdır: $0<y-x<1$, yani $x<y<x+1$. Bölge: $x<0$ iken $y=x$ ile $y=x+1$ doğruları arasındaki şerit.

Ayrıntılı çözüm önceki derste yapılmıştı.

## 3. Tekrar: Yüzeyler ve Seviye Eğrileri

Hoca, limit ve türeve geçmeden üç boyutlu yüzeylerin iyi çizilebilmesi gerektiğini söyledi. İntegral almak için de bu çizimler gereklidir ve el çizimi pratiği ister.

**Örnek 4.** $z=x^2+y^2$ yüzeyinin çizimi.

- $z=0$ alınırsa $x^2+y^2=0$, yani yalnız orijin.
- $y=0$ alınırsa $z=x^2$: $xz$ düzleminde bir parabol.
- $x=0$ alınırsa $z=y^2$: $yz$ düzleminde bir parabol.
- Bunlar birleşince yüzey bir paraboloid olarak ortaya çıkar.

Silindir için de aynı yöntem kullanılır. Seviye eğrisi (level curve), yüzeyin $z=c$ yatay düzlemiyle kesişiminin $xy$ düzlemine izdüşümüdür. $z$ yerine bir sabit verilince o sabite ait seviye eğrisi elde edilir.

**Örnek 5.** $f(x,y)=100-x^2-y^2$ için $f=0$, $f=51$ ve $f=75$ seviye eğrileri.

- $f=0$: $x^2+y^2=100$, yarıçapı 10 olan çember.
- $f=51$: $x^2+y^2=49$, yarıçapı 7 olan çember.
- $f=75$: $x^2+y^2=25$, yarıçapı 5 olan çember.

Hoca üç değişkenli fonksiyonlar için de aynı şekilde seviye yüzeyleri (ör. küre) olduğunu hatırlattı.

## 4. Tekrar: Limit ve Süreklilik

### 4.1 Limit Kuralları

Limit kuralları tek değişkenli fonksiyonlardakine benzer. İki fonksiyonun toplamının ya da farkının limiti, limitlerin toplamına ya da farkına eşittir. Çarpım ve bölüm için de aynı kurallar yazılır. Ama çok değişkenli fonksiyonlarda farklı olan şeyler de vardır; bunlar aşağıda anlatıldı.

### 4.2 Cebirsel Yolla Limit

**Örnek 6.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x^2-xy}{\sqrt{x}-\sqrt{y}}$.

Doğrudan yerine koyunca $\dfrac00$ belirsizliği çıkar. Tek değişkenli fonksiyonlarda yaptığımız gibi eşleniğiyle çarparız:

- Pay: $x^2-xy=x(x-y)$.
- Pay ve payda $\sqrt x+\sqrt y$ ile çarpılır. Payda $(\sqrt x-\sqrt y)(\sqrt x+\sqrt y)=x-y$ olur.
- $\dfrac{x(x-y)(\sqrt x+\sqrt y)}{x-y}=x(\sqrt x+\sqrt y)$.
- $(x,y)\to(0,0)$ iken $x(\sqrt x+\sqrt y)\to0$. Limit 0'dır.

Hoca aynı soruyu sonra ardışık limitlerle de çözdü (bkz. 4.4) ve iki yoldan da 0 buldu. "Çözüm yolu bir tane değil; birden çok çözüm yolu olmalı, matematikte bu olmazsa olmaz" dedi.

### 4.3 Sıkıştırma (Sandviç) Teoremi

**Teorem (Sıkıştırma teoremi).**

- $(x,y)\ne(0,0)$ olan her nokta için $g(x,y)\le f(x,y)\le h(x,y)$ olsun.
- $\displaystyle\lim_{(x,y)\to(0,0)}g(x,y)=\lim_{(x,y)\to(0,0)}h(x,y)=L$ ise
- $\displaystyle\lim_{(x,y)\to(0,0)}f(x,y)=L$ olur.

**Örnek 7.** $f(x,y)=x^2\sin\dfrac1y$ fonksiyonunun $(0,0)$'daki limiti (parçalı verilmiş bir fonksiyon).

- Sinüs her zaman $-1$ ile $1$ arasındadır: $-1\le\sin\dfrac1y\le1$.
- Her taraf $x^2$ ile çarpılır: $-x^2\le x^2\sin\dfrac1y\le x^2$.
- $(x,y)\to(0,0)$ iken $-x^2\to0$ ve $x^2\to0$.
- Sıkıştırma teoremiyle limit 0'dır.

Hoca önce limitin bulunması gerektiğini, sürekliliğe ancak ondan sonra bakılacağını söyledi.

<!-- BELİRSİZ: Parçalı fonksiyonun $(0,0)$'daki tanımı altyazıda söylenmiyor. -->

### 4.4 Ardışık Limit (Eksenler Boyunca Yaklaşma)

İki değişkenli limitte $(a,b)$ noktasına bir $\delta$ komşuluğu içinden her yönden yaklaşılır. Tek değişkende yalnız sağ ve soldan yaklaşma vardı; burada ise noktanın etrafı bir yuvarlaktır. Limitin olması için sonucun yoldan bağımsız olması gerekir: eksenler boyunca, $y=kx$ doğruları boyunca, $y=kx^2$ parabolleri boyunca yaklaşınca hep aynı değer çıkmalıdır. Biri bile farklıysa limit yoktur, çünkü limit tektir.

Ardışık limit (iterated limit) şöyle alınır:

- $\displaystyle\lim_{x\to a}\left(\lim_{y\to b}f(x,y)\right)$: önce $y\to b$ limiti alınır, çıkan ifadenin $x\to a$ limiti alınır.
- $\displaystyle\lim_{y\to b}\left(\lim_{x\to a}f(x,y)\right)$: önce $x\to a$, sonra $y\to b$.

**Örnek 6'nın ardışık limitle çözümü.**

- $\displaystyle\lim_{x\to0}\lim_{y\to0}\frac{x^2-xy}{\sqrt x-\sqrt y}=\lim_{x\to0}\frac{x^2}{\sqrt x}=\lim_{x\to0}x\sqrt x=0$.
- $\displaystyle\lim_{y\to0}\lim_{x\to0}\frac{x^2-xy}{\sqrt x-\sqrt y}=\lim_{y\to0}\frac{0}{-\sqrt y}=0$.
- İki sıra da 0 verir.

### 4.5 Limitin Yokluğu İçin Çift Yol Testi

Hoca bu kısmı önemli bulduğunu ve soruların buradan geldiğini söyledi. Bir fonksiyon verilir ve limitinin olup olmadığı sorulur. Önce eksenler boyunca yaklaşılır. Sonuçlar farklıysa limit yoktur ve iş biter. Aynıysa ikinci adıma geçilir: $y=x$, $y=x^2$ ya da genel olarak $y=kx$, $y=kx^2$ boyunca yaklaşılır. Sonuç $k$'ya bağlı çıkarsa, yani $k$ değiştikçe değişiyorsa limit yoktur.

**Örnek 8.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{2x^2y}{x^4+y^2}$ var mı?

*Birinci adım, eksenler boyunca:*

- $\displaystyle\lim_{x\to0}\lim_{y\to0}\frac{2x^2y}{x^4+y^2}=\lim_{x\to0}\frac{0}{x^4}=0$.
- $\displaystyle\lim_{y\to0}\lim_{x\to0}\frac{2x^2y}{x^4+y^2}=\lim_{y\to0}\frac{0}{y^2}=0$.
- İkisi aynı çıktı. Farklı çıksaydı "limit yoktur" der ve bitirirdik. Aynı çıktığı için ikinci teste geçilir.

*İkinci adım, $y=kx$ boyunca:*

$$\lim_{x\to0}\frac{2x^2(kx)}{x^4+k^2x^2}=\lim_{x\to0}\frac{2kx^3}{x^2(x^2+k^2)}=\lim_{x\to0}\frac{2kx}{x^2+k^2}=0.$$

Payın derecesi 3, paydanınki daha küçük kuvvetten başlıyor; sonuç 0 çıkar. Hoca "Peki doğru mu? Hayır." diyerek bu sonucun karar vermeye yetmediğini belirtti.

*Üçüncü adım, $y=kx^2$ boyunca:*

$$\lim_{x\to0}\frac{2x^2(kx^2)}{x^4+k^2x^4}=\lim_{x\to0}\frac{2kx^4}{x^4(1+k^2)}=\frac{2k}{1+k^2}.$$

Sonuç $k$'ya bağlıdır. Örneğin $y=3x^2$ ile yaklaşınca bir değer, $y=4x^2$ ile yaklaşınca başka bir değer çıkar. Limit yoktur.

> **Hocanın vurgusu:** Şıklarda 0, 1, 2, 3, 4 gibi sayılar şaşırtmaca olarak verilir; özellikle 0 seçeneğine hemen düşülebilir. Doğru cevap "limit yoktur" olabilir, çünkü sonuç $k$'ya bağlıdır.

Hoca, paydada $x^4+y^2$ olduğunu görünce doğrudan $y=kx^2$ ile başlamanın işi tek hamlede bitirdiğini söyledi. Bu, soru çözdükçe kazanılan bir meleke. Ama öğrenme aşamasında bütün adımları denemekte fayda var.

**Örnek 9.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{3x^2-y^2}{3y^2+x^2}$ (önceki dersteki soru, üç yolla).

- *Birinci yol, $y=kx$:* $\dfrac{3x^2-k^2x^2}{3k^2x^2+x^2}=\dfrac{3-k^2}{3k^2+1}$. Sonuç $k$'ya bağlı, limit yok.
- *İkinci yol, iki farklı eğri:* $y=x$ boyunca $\dfrac{3-1}{3+1}=\dfrac12$; $y=x^2$ boyunca $\dfrac{3x^2-x^4}{3x^4+x^2}\to3$. Farklı, limit yok.
- *Üçüncü yol, eksenler boyunca:* $\displaystyle\lim_{x\to0}\lim_{y\to0}=\lim_{x\to0}\frac{3x^2}{x^2}=3$; $\displaystyle\lim_{y\to0}\lim_{x\to0}=\lim_{y\to0}\frac{-y^2}{3y^2}=-\frac13$. Farklı olduğu için limit yoktur. Hocaya göre bunu görmek tek başına yeterlidir.

### 4.6 Süreklilik

Bir fonksiyonun $(a,b)$ noktasında sürekli olması için iki şey gerekir: o noktada limitin olması ve bu limitin fonksiyonun o noktadaki değerine eşit olması. Limit yoksa fonksiyon zaten sürekli değildir.

**Örnek 10.** $f(x,y)=\begin{cases}\dfrac{\sin(xy)}{x^2+y^2}, & (x,y)\ne(0,0)\\[2mm] 0, & (x,y)=(0,0)\end{cases}$ fonksiyonunun $(0,0)$'daki sürekliliği ve nedeni.

Hoca $y=kx$ yolunu seçti. Nedeni: $y=kx$ yazınca paydada $x^2+k^2x^2$ olur ve $x^2$ parantezine alınabilir; iş kolaylaşır.

$$\lim_{x\to0}\frac{\sin(kx^2)}{x^2(1+k^2)}.$$

Hoca kırmızı kalemle pay ve paydayı $k$ ile genişletti:

$$\lim_{x\to0}k\cdot\frac{\sin(kx^2)}{kx^2}\cdot\frac{1}{1+k^2}=k\cdot1\cdot\frac{1}{1+k^2}=\frac{k}{1+k^2}.$$

Burada $\dfrac{\sin u}{u}\to1$ limiti kullanıldı. Sonuç $k$'ya bağlıdır:

- $k=1$ ($y=x$): $\dfrac12$.
- $k=2$ ($y=2x$): $\dfrac{2}{1+4}=\dfrac25$.

Farklı yollarda farklı sonuç çıktığı için limit yoktur. Limit olmadığı için fonksiyon $(0,0)$'da sürekli değildir.

**Soru:** Şimdi sürekliliğe bakmamız gerekmiyor mu? **Cevap:** Limit yoksa sürekli değildir diyebiliriz, çünkü süreklilik için limit olmalı ve o noktadaki değere eşit olmalıydı.

## 5. Kısmi Türev

Moladan sonra hoca kısmi türevlere (partial derivative) geçti.

### 5.1 Tanım ve Gösterimler

Tek değişkenli fonksiyonlarda yalnız "$z$'nin $x$'e göre türevi" vardı. Çok değişkenli $z=f(x,y)$ fonksiyonunda ise hem $x$'e hem $y$'ye göre türev vardır. Bu yüzden kısmi türev denir ve kıvrık d ($\partial$) ile yazılır.

**Tanım (Kısmi türev).**

- $x$'e göre: $y$ sabit tutulur, yalnız $x$ $h$ kadar artırılır.
$$f_x(x,y)=\lim_{h\to0}\frac{f(x+h,y)-f(x,y)}{h}$$
- $y$'ye göre: $x$ sabit tutulur, yalnız $y$ $h$ kadar artırılır.
$$f_y(x,y)=\lim_{h\to0}\frac{f(x,y+h)-f(x,y)}{h}$$
- Bu limitler mevcutsa ilgili kısmi türev vardır.

Gösterimler:

- $x$'e göre: $\dfrac{\partial f}{\partial x}=\dfrac{\partial z}{\partial x}=f_x=f_1$ ($f$'nin birinci değişkene göre türevi).
- $y$'ye göre: $\dfrac{\partial f}{\partial y}=\dfrac{\partial z}{\partial y}=f_y=f_2$ ($f$'nin ikinci değişkene göre türevi).
- Bir noktada: $\left.\dfrac{\partial z}{\partial x}\right|_{(a,b)}=f_x(a,b)=f_1(a,b)$, $\left.\dfrac{\partial z}{\partial y}\right|_{(a,b)}=f_y(a,b)=f_2(a,b)$.

Pratikte: $f$'nin $x$'e göre kısmi türevi, $y$ sabit sayılarak $f$'nin yalnız $x$'in fonksiyonu gibi türevidir. $y$'ye göre kısmi türevde ise $x$ sabit tutulur. Toplam, çarpım ve bölüm için bilinen bütün türev kuralları geçerlidir.

### 5.2 Kurallarla Kısmi Türev

**Örnek 11.** $z=x^3y^2+x^4y+4x^3y^4+y^2$ için $\dfrac{\partial z}{\partial x}$ ve $\dfrac{\partial z}{\partial y}$.

<!-- BELİRSİZ: Fonksiyon altyazıda sesli okunmuyor; terimler hocanın tek tek türev alışından ve kısa nottaki ekran okumasından kuruldu. -->

$x$'e göre türevde $y$'yi 3, 5 gibi sabit bir sayı gibi düşünürüz:

- $x^3y^2\to3x^2y^2$.
- $x^4y\to4x^3y$.
- $4x^3y^4\to12x^2y^4$.
- $y^2$ terimi $x$'e göre sabittir, türevi 0'dır.

$$\frac{\partial z}{\partial x}=3x^2y^2+4x^3y+12x^2y^4.$$

$y$'ye göre türevde bu kez $x$ sabit sayılır:

$$\frac{\partial z}{\partial y}=2x^3y+x^4+16x^3y^3+2y.$$

**Örnek 12.** $f(x,y)=e^{xy}\cos(x+y)$ ise $f_1(0,\pi)$ nedir?

$f_1$, birinci değişkene ($x$'e) göre türevdir; $y$ sabittir. İki fonksiyonun çarpımı olduğu için çarpım kuralı uygulanır: birincinin türevi çarpı ikinci, artı ikincinin türevi çarpı birinci.

- $\dfrac{\partial}{\partial x}e^{xy}=y\,e^{xy}$.
- $\dfrac{\partial}{\partial x}\cos(x+y)=-\sin(x+y)\cdot1$ (iç türev: $x$'in türevi 1, $y$'nin türevi 0).
- $f_1(x,y)=y\,e^{xy}\cos(x+y)-e^{xy}\sin(x+y)$.
- $f_1(0,\pi)=\pi\cdot e^0\cdot\cos\pi-e^0\cdot\sin\pi=\pi\cdot(-1)-0=-\pi$.

Hoca ilk yazımında sinüslü terimi eksik ve işaretsiz yazdı, sonra "Gençler, nerede hata yaptık?" diye sordu. Sınıftan ses gelmeyince çarpım kuralını hatırlatıp kosinüsün türevinden gelen eksi işaretini ekledi.

### 5.3 Tanımdan Kısmi Türev

**Örnek 13.** $f(x,y)=x^2y$ için kısmi türevleri tanımdan bulunuz.

$x$'e göre: $x$ yerine $x+h$ yazılır, $y$ aynen kalır.

$$f_x=\lim_{h\to0}\frac{(x+h)^2y-x^2y}{h}=\lim_{h\to0}\frac{x^2y+2xhy+h^2y-x^2y}{h}=\lim_{h\to0}\frac{h(2xy+hy)}{h}=\lim_{h\to0}(2xy+hy)=2xy.$$

$y$'ye göre: $x$ sabit kalır, $y$ yerine $y+h$ yazılır.

$$f_y=\lim_{h\to0}\frac{x^2(y+h)-x^2y}{h}=\lim_{h\to0}\frac{x^2h}{h}=x^2.$$

Kurallarla da aynı sonuç çıkar: $y$ sabitken $x^2y$'nin $x$'e göre türevi $2xy$; $x$ sabitken $y$'ye göre türevi $x^2$.

### 5.4 Parçalı Fonksiyonda Süreklilik ve Kısmi Türev

**Örnek 14.** $f(x,y)=\begin{cases}(x^2+y^2)\sin\dfrac{1}{\sqrt{x^2+y^2}}, & (x,y)\ne(0,0)\\[2mm] 0, & (x,y)=(0,0)\end{cases}$

<!-- BELİRSİZ: Altyazıda sinüsün içi bir yerde "bir bölü x kare artı y kare", başka bir yerde "bir bölü y kare" diye geçiyor; hoca $f(h,0)$ için $\sin\frac1h$ yazıyor. Kökün olduğu biçim kısa nottaki ekran okumasından alındı. Hangi biçim olursa olsun aşağıdaki sonuçlar değişmez. -->

Hoca bu soruyu çoktan seçmeli bir soru gibi kurdu: (1) Fonksiyon $(0,0)$'da sürekli mi? (2) Limit var mı? (3) $f_x(0,0)$ nedir? (4) $f_y(0,0)$ nedir? Hangi ifade yanlıştır?

*Süreklilik ve limit:*

- $-1\le\sin\dfrac{1}{\sqrt{x^2+y^2}}\le1$. Her taraf $x^2+y^2$ ile çarpılır:
$$-(x^2+y^2)\le f(x,y)\le x^2+y^2.$$
- $(x,y)\to(0,0)$ iken iki tarafın limiti de 0'dır. Sıkıştırma teoremiyle limit 0'dır.
- $f(0,0)=0$. Limit, noktadaki değere eşit. Fonksiyon süreklidir.

*$x$'e göre kısmi türev:*

$$f_x(0,0)=\lim_{h\to0}\frac{f(0+h,0)-f(0,0)}{h}=\lim_{h\to0}\frac{h^2\sin\frac{1}{|h|}-0}{h}=\lim_{h\to0}h\sin\frac{1}{|h|}.$$

Sinüs $-1$ ile $1$ arasında olduğundan her taraf $h$ ile çarpılınca $-|h|\le h\sin\dfrac{1}{|h|}\le|h|$ olur. İki tarafın limiti 0'dır, ortadaki limit de 0'dır. $f_x(0,0)=0$.

*$y$'ye göre kısmi türev:* Aynı yolla $f_y(0,0)=0$.

Sonuç: Fonksiyon $(0,0)$'da süreklidir, limit vardır ve 0'dır, iki kısmi türev de 0'dır.

## 6. Kısmi Türevin Geometrik Anlamı

Son moladan sonra hoca kısmi türevin geometrik anlamını ekranda bir şekil üzerinden gösterdi. Bu kısım altyazıda büyük ölçüde anlaşılmıyor; aşağıdaki maddeler kısa nottaki ekran okumasına dayanır.

- $z=f(x,y)$ yüzeyi $y=y_0$ düzlemiyle kesilince $z=f(x,y_0)$ eğrisi oluşur.
- Bu eğrinin $P(x_0,y_0,f(x_0,y_0))$ noktasındaki eğimi $f_x(x_0,y_0)$'dır.
- Benzer şekilde $x=x_0$ düzlemindeki $z=f(x_0,y)$ eğrisinin eğimi $f_y(x_0,y_0)$'dır.
- Eğrinin $P$'deki teğet doğrusu bu eğimle $P$'den geçen doğrudur.

<!-- BELİRSİZ: 01:41:43-01:42:24 arasındaki anlatım altyazıda kopuk ("tarafı sıfır ediyor", "t düzlem"); şeklin ayrıntısı okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu yorum, tek değişkenli fonksiyonda türevin teğet eğimi olmasının doğrudan genellemesidir. $f_x(x_0,y_0)$, $y$ sabitken fonksiyonun $x$ yönünde ne hızla değiştiğini; $f_y(x_0,y_0)$ ise $x$ sabitken $y$ yönündeki değişim hızını verir.

## 7. Basit Zincir Kuralı

Bileşke fonksiyonun türevi tek değişkenli fonksiyonlardaki gibidir; çok değişkenlilerde de aynı özellik tekrar eder.

**Kural (Basit zincir kuralı).** $z=f\big(g(x,y)\big)$ olsun. $f$ yalnız $g$'ye bağlı, $g$ ise hem $x$'e hem $y$'ye bağlıdır.

- $\dfrac{\partial z}{\partial x}=f'(g)\cdot\dfrac{\partial g}{\partial x}$: dışın türevi çarpı içinin $x$'e göre türevi.
- $\dfrac{\partial z}{\partial y}=f'(g)\cdot\dfrac{\partial g}{\partial y}$: dışın türevi çarpı içinin $y$'ye göre türevi.

> **Hocanın vurgusu:** Sınavlarda genelde bu tip sorular çıkıyor; aşağıdaki soru farklı sınavlarda birkaç kez gelmiş.

**Örnek 15.** $z=f\left(\dfrac xy\right)$ ise $x\dfrac{\partial z}{\partial x}+y\dfrac{\partial z}{\partial y}=0$ olduğunu gösteriniz.

- İç fonksiyon $g=\dfrac xy$. $\dfrac{\partial g}{\partial x}=\dfrac1y$, $\dfrac{\partial g}{\partial y}=-\dfrac{x}{y^2}$.
- $\dfrac{\partial z}{\partial x}=\dfrac1y\,f'\!\left(\dfrac xy\right)$.
- $\dfrac{\partial z}{\partial y}=-\dfrac{x}{y^2}\,f'\!\left(\dfrac xy\right)$.
- Yerine yazılır:
$$x\cdot\frac1y f'-y\cdot\frac{x}{y^2}f'=\frac xy f'-\frac xy f'=0.$$

Hoca soruyu anlaşılmayan bir yer olup olmadığını sorduktan sonra ikinci kez baştan çözdü.

## 8. İkiden Fazla Değişkenli Fonksiyonların Kısmi Türevleri

$z=f(x_1,x_2,\dots,x_n)$ biçiminde $n$ değişkenli bir fonksiyon için her değişkene göre bir kısmi türev vardır: $f_1,f_2,\dots,f_n$. Bir değişkene göre türev alınırken diğerleri sabit sayılır.

Hoca tanımı üçüncü değişken için yazdı. Artış yalnız üçüncü değişkene verilir, diğerleri aynı kalır:

$$f_3(x_1,\dots,x_n)=\frac{\partial f}{\partial x_3}=\lim_{h\to0}\frac{f(x_1,x_2,x_3+h,x_4,\dots,x_n)-f(x_1,x_2,x_3,x_4,\dots,x_n)}{h}.$$

**Örnek 16.** $f(x,y,z)=\dfrac{2xy}{1+xz+y^2}$.

Bölümün türevi: payın türevi çarpı payda, eksi paydanın türevi çarpı pay, bölü paydanın karesi.

*$z$'ye göre:* Payda $z$ yok, payın türevi 0'dır. Paydanın $z$'ye göre türevi $x$'tir.

$$f_z=\frac{0\cdot(1+xz+y^2)-x\cdot2xy}{(1+xz+y^2)^2}=-\frac{2x^2y}{(1+xz+y^2)^2}.$$

*$x$'e göre:* Payın türevi $2y$, paydanın türevi $z$ (1'in ve $y^2$'nin türevi 0).

$$f_x=\frac{2y(1+xz+y^2)-z\cdot2xy}{(1+xz+y^2)^2}=\frac{2y(1+y^2)}{(1+xz+y^2)^2}.$$

## 9. Yüksek Mertebeden Kısmi Türevler ve Karışık Türev Teoremi

### 9.1 İkinci Mertebe Türevler

Tek değişkenli fonksiyonlarda olduğu gibi önce birinci türev alınır, sonra çıkan ifadenin tekrar türevi alınır.

- $\dfrac{\partial^2 z}{\partial x^2}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial z}{\partial x}\right)=f_{xx}=f_{11}$: iki kez $x$'e göre türev.
- $\dfrac{\partial^2 z}{\partial x\,\partial y}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial z}{\partial y}\right)$: önce $y$'ye, sonra $x$'e göre türev. İç kısımdan başlanır.

Hoca $\dfrac{\partial^2 z}{\partial x\,\partial y}$ ile $\dfrac{\partial^2 z}{\partial y\,\partial x}$'in her zaman eşit olmadığını, kısmi türevler sürekliyse eşit olduğunu vurguladı.

**Örnek 17 (sınav sorusu).** $f(x,y)=x\cos y+y\,e^x$ için $\dfrac{\partial^2 f}{\partial x^2}$, $\dfrac{\partial^2 f}{\partial y^2}$ ve $\dfrac{\partial^2 f}{\partial x\,\partial y}$.

*Birinci türevler:*

- $x$'e göre: $x\cos y$ çarpımında $x$'in türevi 1, $\cos y$ ise sabit; terim $\cos y$ olur. $y\,e^x$'in türevi $y\,e^x$. $f_x=\cos y+y\,e^x$.
- $y$'ye göre: $x\cos y\to-x\sin y$; $y\,e^x\to e^x$. $f_y=-x\sin y+e^x$.

*İkinci türevler:*

- $\dfrac{\partial^2 f}{\partial x^2}=\dfrac{\partial}{\partial x}(\cos y+y\,e^x)=y\,e^x$ ($\cos y$, $x$'e göre sabit, gider).
- $\dfrac{\partial^2 f}{\partial y^2}=\dfrac{\partial}{\partial y}(-x\sin y+e^x)=-x\cos y$.
- $\dfrac{\partial^2 f}{\partial x\,\partial y}=\dfrac{\partial}{\partial x}\left(\dfrac{\partial f}{\partial y}\right)=\dfrac{\partial}{\partial x}(-x\sin y+e^x)=-\sin y+e^x$.

**Örnek 18.** $z=\ln(x^2+y^2)$ ise $\dfrac{\partial^2 z}{\partial x^2}+\dfrac{\partial^2 z}{\partial y^2}=0$ olduğunu gösteriniz.

Logaritmanın türevi: içinin türevi bölü kendisi.

- $z_x=\dfrac{2x}{x^2+y^2}$, $z_y=\dfrac{2y}{x^2+y^2}$.
- Tekrar türev alınır (ara adım eklendi):
$$z_{xx}=\frac{2(x^2+y^2)-2x\cdot2x}{(x^2+y^2)^2}=\frac{2(y^2-x^2)}{(x^2+y^2)^2},\qquad z_{yy}=\frac{2(x^2-y^2)}{(x^2+y^2)^2}.$$
- Toplam: $\dfrac{2(y^2-x^2)+2(x^2-y^2)}{(x^2+y^2)^2}=0$.

Hoca ikinci türevleri sesli okumadı; yalnız toplamın 0 çıktığını söyledi.

> **Ek bilgi (derste anlatılmadı):** $z_{xx}+z_{yy}=0$ denklemine Laplace denklemi, bu denklemi sağlayan fonksiyonlara harmonik fonksiyon denir. $\ln(x^2+y^2)$, orijin dışında harmonik bir fonksiyondur.

### 9.2 Karışık Türev Teoremi

**Teorem (Karışık türev teoremi).**

- $f(x,y)$ ve kısmi türevleri $f_x$, $f_y$, $f_{xy}$, $f_{yx}$, $(a,b)$ noktasını içeren bir açık bölgede tanımlı olsun.
- Bunlar $(a,b)$'de sürekliyse $f_{xy}(a,b)=f_{yx}(a,b)$ olur.
- Yani "önce $x$ sonra $y$" ile "önce $y$ sonra $x$" sırası, kısmi türevler sürekli olduğunda sonucu değiştirmez.

> **Hocanın vurgusu:** Bu çok önemli bir kural. Karışık türevlerin eşit olması için kısmi türevlerin de sürekli olması gerekir.

Hoca bir örnek fonksiyonda iki karışık türevi aldığını ve eşit bulduğunu, bunun nedeninin kısmi türevlerin her yerde sürekli olması olduğunu söyledi. Kısmi türevler sürekli değilse sıra değişimi fark yaratabilir.

<!-- BELİRSİZ: 01:53:39'da gösterilen örnek fonksiyonun ifadesi altyazıda okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu teorem Clairaut ya da Schwarz teoremi olarak da bilinir. Süreklilik koşulu eşitlik için yeterlidir ama gerekli değildir. Kısmi türevler sürekli olmayan bazı fonksiyonlarda da karışık türevler eşit çıkabilir.

## 10. Ders Sonu Örneği: Kısmi Türevleri Olan Ama Sürekli Olmayan Fonksiyon

Hoca zincir kuralının devamına geçmeden önce dersi şu örnekle bitirdi.

**Örnek 19.** $f(x,y)=\begin{cases}0, & xy\ne0\\ 1, & xy=0\end{cases}$

- a) $y=x$ doğrusu boyunca $(0,0)$'daki limiti bulunuz.
- b) $f$'nin $(0,0)$'da sürekli olmadığını gösteriniz.
- c) $f_x(0,0)$ ve $f_y(0,0)$'ın mevcut olduğunu gösteriniz.

<!-- BELİRSİZ: Fonksiyonun tanımı altyazıda "x'e sıfır da farklı iken sıfır, sıfır sıfır eşitken bir" diye geçiyor; $xy\ne0$ / $xy=0$ biçimi kısa nottaki ekran okumasından alındı. -->

*a)* $y=x$ boyunca, orijin hariç $xy=x^2\ne0$'dır. Bu yol üzerinde fonksiyon özdeş olarak 0'dır. Limit 0'dır.

*b)* $f(0,0)=1$ (çünkü $0\cdot0=0$). $y=x$ boyunca limit 0, noktadaki değer 1. Fonksiyon $(0,0)$'da sürekli değildir.

*c)* Eksenler üzerinde $xy=0$ olduğundan $f=1$'dir.

$$f_x(0,0)=\lim_{h\to0}\frac{f(h,0)-f(0,0)}{h}=\lim_{h\to0}\frac{1-1}{h}=0,\qquad f_y(0,0)=\lim_{h\to0}\frac{f(0,h)-f(0,0)}{h}=0.$$

İki kısmi türev de mevcuttur ve 0'dır.

> **Ders sonrası not:** Hoca b) şıkkında "limit var, sıfır çıktı" dedi. Doğrusu: $y=x$ boyunca limit 0, ama eksenler boyunca $f=1$ olduğundan limit 1'dir. Farklı yollarda farklı değer çıktığı için $(0,0)$'da iki değişkenli limit yoktur. Varılan sonuç yine aynıdır: fonksiyon $(0,0)$'da sürekli değildir.

Bu örnek önemli bir farkı gösterir: Tek değişkende türevlenebilen fonksiyon süreklidir. İki değişkende ise bir noktada kısmi türevlerin var olması, fonksiyonun o noktada sürekli olmasını gerektirmez.

> **Ek bilgi (derste anlatılmadı):** Kısmi türevler yalnız eksenlere paralel iki yöndeki davranışa bakar. Bu örnekte fonksiyon eksenler üzerinde sabit 1 olduğu için kısmi türevler 0 çıkar; eksenler dışındaki noktalardaki ani düşüş kısmi türevlere yansımaz.

> **Ders sonrası not:** Hoca karışık türev teoremini "sürekliyse eşittir, yoksa değildir" diye özetledi. Süreklilik eşitlik için yeterli koşuldur. Süreklilik olmadığında eşitlik bozulabilir, ama her zaman bozulmaz.

## Örnek Sorular

Bu derste kare ve video kullanılmadı; aşağıdaki sorular derste sözlü sorulan ya da tahtada çözülen sorulardır.

**Soru 1** (derste sözlü, 00:04:08). $u=f(x,y,z)$ kaç değişkenli bir fonksiyondur, hangi kümeden hangi kümeye gider?

> **Çözüm:** Üç değişkenli; $\mathbb{R}^3$'ten $\mathbb{R}$'ye gider (bkz. 2.1).

**Soru 2** (derste sözlü, 00:09:30). Hangi aralıktaki sayıların logaritması pozitiftir?

> **Çözüm:** 1'den büyük sayıların. 0 ile 1 arasındaki sayıların logaritması negatiftir (bkz. Örnek 3).

**Soru 3** (derste sözlü, 00:25:22). $\displaystyle\lim_{(x,y)\to(0,0)}\frac{2x^2y}{x^4+y^2}$ var mı?

> **Çözüm:** Yok. $y=kx^2$ boyunca sonuç $\dfrac{2k}{1+k^2}$, $k$'ya bağlı (bkz. Örnek 8).

**Soru 4** (derste sözlü, 00:35:37). $f(x,y)=\dfrac{\sin(xy)}{x^2+y^2}$, $f(0,0)=0$ için $(0,0)$'da limit var mı, fonksiyon sürekli mi?

> **Çözüm:** $y=kx$ boyunca sonuç $\dfrac{k}{1+k^2}$. Limit yok, sürekli değil (bkz. Örnek 10).

**Soru 5** (derste sözlü, 01:16:55). Örnek 14'teki fonksiyon için: (1) $(0,0)$'da sürekli mi? (2) Limit var mı? (3) $f_x(0,0)$? (4) $f_y(0,0)$? Hangisi yanlıştır?

> **Çözüm:** Sürekli; limit var ve 0; $f_x(0,0)=0$; $f_y(0,0)=0$ (bkz. Örnek 14).

<!-- BELİRSİZ: Soru 5'in şıklarının tam metni altyazıda okunmuyor. -->

**Soru 6** (derste sözlü, 01:51:27). $z=\ln(x^2+y^2)$ için $z_{xx}+z_{yy}$ nedir?

> **Çözüm:** 0 (bkz. Örnek 18).

**Soru 7** (derste sözlü, 01:54:19). Örnek 19'daki fonksiyon için $y=x$ boyunca limit, $(0,0)$'da süreklilik ve kısmi türevlerin varlığı.

> **Çözüm:** Limit 0; sürekli değil; $f_x(0,0)=f_y(0,0)=0$ (bkz. Örnek 19).

## Dersin Toparlaması

Ders, çok değişkenli fonksiyonlarla ilgili önceki derslerin tekrarıyla başladı: tanım bölgesi bulma, $z=x^2+y^2$ gibi yüzeylerin çizimi ve seviye eğrileri. Ardından limit konusu sorularla pekiştirildi. Cebirsel sadeleştirme, sıkıştırma teoremi, eksenler boyunca ardışık limit ve $y=kx$, $y=kx^2$ yollarıyla çift yol testi kullanıldı. Ana fikir: farklı yollarda farklı ya da $k$'ya bağlı sonuç çıkıyorsa limit yoktur, limit yoksa fonksiyon sürekli değildir.

İkinci yarıda kısmi türev tanımlandı: bir değişkene göre türev alınırken diğerleri sabit tutulur. Kısmi türevler hem kurallarla hem tanımdan hesaplandı. Basit zincir kuralı $z=f(x/y)$ tipi "gösteriniz" sorusuyla, ikiden fazla değişkenli fonksiyonlar bölüm kuralıyla, yüksek mertebeden türevler de $x\cos y+y\,e^x$ ve $\ln(x^2+y^2)$ örnekleriyle işlendi. Karışık türev teoremi, kısmi türevler sürekliyse türev alma sırasının önemli olmadığını söyler. Son örnek, kısmi türevleri olan bir fonksiyonun sürekli olmayabileceğini gösterdi. Hoca bir sonraki derste limit, süreklilik ve kısmi türevlerle ilgili çıkmış sınav sorularının birlikte çözüleceğini söyledi ve konuyu bol soru çözerek "pişirmek" gerektiğini vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
