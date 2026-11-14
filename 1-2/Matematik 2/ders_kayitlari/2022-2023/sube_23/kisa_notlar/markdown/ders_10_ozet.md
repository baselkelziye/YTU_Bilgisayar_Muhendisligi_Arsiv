# Ders 10 Çalışma Özeti

## Genel Konular

- Ders 28 Mart 2023 Salı günü online yapıldı.
- Önceki dersin kısa tekrarı: çok değişkenli fonksiyonun tanımı, tanım bölgesi soruları.
- Temel yüzeyler (quadric surfaces): küre, elipsoid, paraboloid, silindir, dairesel ve eliptik koni.
- Seviye eğrisi (level curve) ve kontur eğrisi (contour curve).
- Üç değişkenli fonksiyonun tanım bölgesi.
- Çok değişkenli fonksiyonlarda limit (limit) ve süreklilik (continuity).
- Sıkıştırma (sandviç) teoremi, ardışık (iki katlı) limit, çift yol testi (two-path test).
- Kısmi türeve (partial derivative) giriş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tanım bölgesi sorusu sınavda mutlaka gelir. Hoca farklı tiplerde en az 30 soru çözülmesini istiyor.
- Test sınavında doğru şık genelde A'ya konmaz. Kapalı ve açık sınırlar (çizgi kesik mi, düz mü) şıklarda ayırt edicidir.
- Çok değişkenli fonksiyonlarda limit ve süreklilikten 2. vizede ve finalde en az iki soru gelir.
- Çok değişkenli fonksiyonları çizemeyen öğrenci çok katlı integralde zorlanır. Yüzeylerin çizimi önemli.
- Eksenler boyunca bulunan limitlerin eşit olması limitin varlığı için yeterli değildir. Farklı çıkması ise limitin yokluğunu kesin gösterir.
- $y=kx$ ya da $y=kx^2$ yolu boyunca bulunan limit $k$'ya bağlı çıkarsa limit yoktur.

## Kısa Tekrar Notları

- İki değişkenli fonksiyon: $f: D\subseteq\mathbb{R}^2\to\mathbb{R}$, $z=f(x,y)$. Kapalı biçim: $F(x,y,z)=0$.
- $n$ değişkenli fonksiyon: $u=f(x_1,x_2,\dots,x_n)$.
- Kök içi $\ge 0$; kök paydadaysa $>0$. Logaritmanın içi $>0$; $\ln$ paydadaysa içi $\ne 1$.
- Seviye eğrisi: $f(x,y)=c$ eşitliğini sağlayan noktaların kümesi. $xy$-düzlemindeki izdüşümdür.
- Kontur eğrisi: $z=c$ düzleminin $z=f(x,y)$ yüzeyini kestiği eğri.
- Süreklilik: $\lim_{(x,y)\to(a,b)}f(x,y)=f(a,b)$.
- Limit yoksa fonksiyon o noktada sürekli değildir.

## Detaylı Açıklamalar

### Tanım bölgesi örnekleri

**Örnek 1.** Kökü paydada olan ifade, $\sqrt{1-x^2-y^2}$.

- Kök paydada olduğu için $1-x^2-y^2>0$, yani $x^2+y^2<1$.
- Bölge: merkezi orijin, yarıçapı 1 olan çemberin içi. Çember kesik çizgiyle çizilir (sınır dahil değil).

**Örnek 2.** İki köklü ifadeden oluşan fonksiyon.

- Birinci koşul: $x^2+y^2-1\ge 0$, yani $x^2+y^2\ge 1$. Birim çemberin dışı, çember dahil.
- İkinci koşul (kök paydada): $4-x^2-y^2>0$, yani $x^2+y^2<4$.
- Bölge: $1\le x^2+y^2<4$. İçteki çember dahil (düz çizgi), dıştaki çember dahil değil (kesik çizgi).

**Örnek 3.** Kök içi $(3x-y)(3x+y)$ biçiminde çarpanlara ayrılan ifade.

- Çarpımın pozitif olması için iki çarpan da pozitif ya da iki çarpan da negatif olmalı.
- İki durum ayrı ayrı incelenir. Bölge $y=3x$ ve $y=-3x$ doğruları arasında kalan bölgelerden oluşur.
- Bu kısmın ayrıntısı altyazıda net anlaşılmıyor.

**Örnek 4.** $f(x,y)=\ln\left[x\ln(y-x)\right]$ fonksiyonunun tanım bölgesi.

- Koşullar: $x\ln(y-x)>0$, $y-x>0$, $y-x\ne 1$, $x\ne 0$.
- 1. durum: $x>0$ ve $\ln(y-x)>0$. Buradan $y-x>1$, yani $x>0$ ve $y>x+1$.
- 2. durum: $x<0$ ve $\ln(y-x)<0$. Buradan $0<y-x<1$, yani $x<0$ ve $x<y<x+1$.
- Hoca $\ln 1=0$ olduğu için $y-x=1$ doğrusunun dışarıda kaldığını vurguladı.

**Örnek 5.** $w=\sqrt{1-x^2-y^2-z^2}$ fonksiyonunun tanım kümesi.

- $1-x^2-y^2-z^2\ge 0$, yani $x^2+y^2+z^2\le 1$.
- Merkezi orijin, yarıçapı 1 olan kürenin içi ve yüzeyi.

### Temel yüzeyler

- **Küre (sphere):** $x^2+y^2+z^2=r^2$. $z=0$ alınınca $xy$-düzleminde yarıçapı $r$ olan çember çıkar. Merkezi $(a,b,c)$ olan küre: $(x-a)^2+(y-b)^2+(z-c)^2=r^2$.
- **Elipsoid (ellipsoid):** $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}+\dfrac{z^2}{c^2}=1$. $z=0$ kesiti elipstir; eksenleri $x$'te $a$'da, $y$'de $b$'de keser.
- **Paraboloid (paraboloid):** $z=ax^2+by^2$. $x$ ve $y$ yönündeki paraboller uzayda kolları yukarı bakan bir yüzeye dönüşür.
- **Silindir (cylinder):** $x^2+y^2=r^2$. Düzlemde çember olan eğri uzayda $z$ ekseni boyunca sınırsız uzar.
- **Dairesel koni (circular cone):** $x^2+y^2=z^2$. Düzlemde $y^2=x^2$, yani $y=\pm x$ doğruları uzayda koniye dönüşür.
- **Eliptik koni:** $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}=z^2$.

Hoca bu yüzeylerden "aşağıdakilerden hangisidir" biçiminde soru sorulabileceğini söyledi.

### Seviye eğrisi ve kontur eğrisi

**Tanım (Seviye eğrisi).**

- $f(x,y)$'nin sabit bir $c$ değerini aldığı noktaların kümesine $f$'nin seviye eğrisi denir: $f(x,y)=c$.

**Tanım (Kontur eğrisi).**

- Uzayda $z=c$ düzleminin $z=f(x,y)$ yüzeyini kestiği eğriye kontur eğrisi denir.

**Örnek 6.** $f(x,y)=100-x^2-y^2$ için $f=0$, $f=51$ ve $f=75$ seviye eğrileri.

- Yüzey kolları aşağı bakan bir paraboloid, tepe noktası $(0,0,100)$.
- $f=0$: $x^2+y^2=100$, yarıçapı 10 olan çember.
- $f=51$: $x^2+y^2=49$, yarıçapı 7 olan çember.
- $f=75$: $x^2+y^2=25$, yarıçapı 5 olan çember.
- Düzlem yukarı çıktıkça kesitteki çemberin yarıçapı küçülür.
- $f=75$ kontur eğrisi, $z=75$ düzleminde yarıçapı 5 olan çemberdir.

### Çok değişkenli fonksiyonlarda limit

**Tanım (Limit).**

- Her $\varepsilon>0$ için $0<\sqrt{(x-a)^2+(y-b)^2}<\delta$ iken $|f(x,y)-L|<\varepsilon$ olacak biçimde bir $\delta>0$ varsa $\lim_{(x,y)\to(a,b)}f(x,y)=L$ yazılır.
- Limit varsa tektir.

Tek değişkenli fonksiyonda bir noktaya yalnız sağdan ve soldan yaklaşılır. İki değişkenli fonksiyonda $(a,b)$'ye sonsuz farklı yoldan yaklaşılabilir: eksenler boyunca, $y=x$ doğrusu boyunca, $y=x^2$ eğrisi boyunca vb. Limitin var olması için bütün yollarda aynı değer çıkmalıdır.

**Limit kuralları.** Toplam, fark, çarpım ve bölümün limiti tek değişkenli fonksiyonlardaki gibidir.

**Örnek 7.** Doğrudan yerine koyma.

- $(x,y)\to(1,1)$ için verilen ifadede yerine koyunca sonuç 5.
- $(x,y)\to(2,1)$ için verilen ifadede yerine koyunca sonuç 3.
- Bu iki ifade altyazıda tam okunmuyor; yalnız sonuçlar söylendi.

**Örnek 8.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{4xy^2}{x^2+y^2}$.

- Yerine koyunca $0/0$ belirsizliği çıkar.
- $x$ ekseni boyunca ($y\to 0$ önce): $\dfrac{0}{x^2}=0$.
- $y$ ekseni boyunca ($x\to 0$ önce): $\dfrac{0}{y^2}=0$.
- Hoca iki sonuç da 0 olduğu için limitin 0 olduğunu söyledi. Bu adım tek başına yeterli değildir (bkz. ders sonrası notlar).

**Örnek 9.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x^2-xy}{\sqrt{x}-\sqrt{y}}$.

- $0/0$ belirsizliği var.
- Pay ve payda $\sqrt{x}+\sqrt{y}$ ile çarpılır. Payda $x-y$ olur.
- Pay $x(x-y)$ biçiminde yazılır. $x-y$ sadeleşir.
- Kalan ifade $x(\sqrt{x}+\sqrt{y})$, limit 0.

**Örnek 10.** $\dfrac{1-\cos(xy)}{xy}$ biçiminde bir limit, $(x,y)\to(0,0)$.

- $1-\cos u=2\sin^2(u/2)$ yazılır ve sadeleştirilir. Sonuç 0.
- Pay ve payda $1+\cos(xy)$ ile çarpılarak da aynı sonuç bulunur.
- Hoca birden çok yöntem olduğunu, çok soru çözmenin önemli olduğunu söyledi.

### Sıkıştırma teoremi

**Teorem (Sandviç / sıkıştırma teoremi, squeeze theorem).**

- Merkezi $(0,0)$ olan bir dairenin içindeki $(x,y)\ne(0,0)$ noktalarında $g(x,y)\le f(x,y)\le h(x,y)$ olsun.
- $(x,y)\to(0,0)$ iken $g$ ve $h$ aynı $L$ limitine gidiyorsa, $f$ de $L$'ye gider.

**Örnek 11.** $f(x,y)=x^2\sin\dfrac1y$ ($y\ne 0$), $(0,0)$'daki limit.

- $-1\le\sin\dfrac1y\le 1$.
- Her taraf $x^2$ ile çarpılır: $-x^2\le x^2\sin\dfrac1y\le x^2$.
- İki tarafın da limiti 0. Ortadaki fonksiyonun limiti de 0.
- Fonksiyonun $(0,0)$'daki değeri de 0 verildiği için hoca fonksiyonun sürekli olduğunu söyledi.

### Ardışık (iki katlı) limit ve çift yol testi

**Tanım (Ardışık limitler).**

- $L_1=\lim_{x\to a}\left[\lim_{y\to b}f(x,y)\right]$, $L_2=\lim_{y\to b}\left[\lim_{x\to a}f(x,y)\right]$.
- $L_1\ne L_2$ ise $(a,b)$'de limit kesinlikle yoktur.
- $L_1=L_2$ ise iki katlı limit vardır, ama bu $f$'nin $(a,b)$'de limiti olduğunu söylemeye yetmez.

**Test (Çift yol testi).**

- $f$'nin $(a,b)$'ye iki farklı yol boyunca yaklaşırken farklı limitleri varsa, $\lim_{(x,y)\to(a,b)}f(x,y)$ yoktur.
- Kullanılan yollar: $y=x$, $y=x^2$, $y=x^3$, ya da $y=kx$, $y=kx^2$ gibi yol aileleri.
- Yol ailesi boyunca bulunan limit $k$'ya bağlıysa limit yoktur.

**Örnek 12.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{2x^2y}{x^4+y^2}$.

- $y=kx^2$ yolu boyunca: $\dfrac{2kx^4}{x^4+k^2x^4}=\dfrac{2k}{1+k^2}$.
- Sonuç $k$'ya bağlı. Limit yoktur.
- Hoca bu soruda $y=kx$ yolunun işe yaramadığını, $y=kx^2$ denenmesi gerektiğini söyledi.

**Örnek 13.** $\displaystyle\lim_{(x,y)\to(0,0)}\frac{3x^2-y^2}{3y^2+x^2}$ limitinin varlığı (büyük olasılıkla (ekrandan)).

- 1. yol, $y=kx$: $\dfrac{3x^2-k^2x^2}{3k^2x^2+x^2}=\dfrac{3-k^2}{3k^2+1}$. Sonuç $k$'ya bağlı, limit yok.
- 2. yol: $y=x$ boyunca $\dfrac{3x^2-x^2}{3x^2+x^2}=\dfrac12$. $y=x^2$ boyunca $\dfrac{3x^2-x^4}{x^2+3x^4}=\dfrac{x^2(3-x^2)}{x^2(1+3x^2)}\to 3$. İki sonuç farklı, limit yok.
- 3. yol, ardışık limitler: $\lim_{x\to0}\left[\lim_{y\to0}\dfrac{3x^2-y^2}{3y^2+x^2}\right]=\lim_{x\to0}\dfrac{3x^2}{x^2}=3$. $\lim_{y\to0}\left[\lim_{x\to0}\dfrac{3x^2-y^2}{3y^2+x^2}\right]=\lim_{y\to0}\dfrac{-y^2}{3y^2}=-\dfrac13$. İki katlı limitler farklı, limit mevcut değil.
- Hoca önce eksenler boyunca bakmanın pratik olduğunu söyledi. Orada farklı çıkarsa başka yönteme gerek yoktur.

### Süreklilik

**Tanım (Süreklilik).**

- $f$, $(a,b)$'de tanımlı olmalı.
- $\lim_{(x,y)\to(a,b)}f(x,y)$ var olmalı.
- Bu limit $f(a,b)$'ye eşit olmalı.
- Tanım kümesinin her noktasında sürekli olan fonksiyona sürekli fonksiyon denir.

**Örnek 14.** $f(x,y)=\dfrac{x^3-xy^2}{x^2+y^2}$, $(x,y)\ne(0,0)$; $f(0,0)=0$. $(0,0)$'da süreklilik (büyük olasılıkla (ekrandan)).

- $\left|\dfrac{x^3-xy^2}{x^2+y^2}\right|=\dfrac{|x|\,|x^2-y^2|}{x^2+y^2}\le\dfrac{|x|(x^2+y^2)}{x^2+y^2}=|x|$.
- $|x|=\sqrt{x^2}\le\sqrt{x^2+y^2}<\delta$. $\delta=\varepsilon$ seçilir.
- Böyle bir $\delta>0$ bulunabildiği için limit 0'dır ve fonksiyon süreklidir.
- Hoca derste önce eksenler boyunca limitlerin 0 çıktığını gösterdi. $\varepsilon$-$\delta$ yönteminin matematik bölümündeki analiz derslerinde kullanıldığını, sınavda pek gerekmeyeceğini söyledi.

**Örnek 15.** $f(x,y)=\dfrac{\sin(xy)}{x^2+y^2}$, $(x,y)\ne(0,0)$; $f(0,0)=0$. $(0,0)$'da süreklilik (büyük olasılıkla (ekrandan)).

- Fonksiyon $(0,0)$'da tanımlı.
- $y=mx$ boyunca: $\dfrac{\sin(mx^2)}{x^2+m^2x^2}=m\cdot\dfrac{\sin(mx^2)}{mx^2}\cdot\dfrac{1}{1+m^2}\to\dfrac{m}{1+m^2}$.
- Sonuç $m$'ye bağlı. Limit yok. Fonksiyon $(0,0)$'da sürekli değildir.

### Kısmi türevlere giriş

**Tanım (Birinci mertebe kısmi türevler).**

- $x$'e göre: $\dfrac{\partial f}{\partial x}=f_x=f_1=\displaystyle\lim_{h\to0}\frac{f(x+h,y)-f(x,y)}{h}$.
- $y$'ye göre: $\dfrac{\partial f}{\partial y}=f_y=f_2=\displaystyle\lim_{h\to0}\frac{f(x,y+h)-f(x,y)}{h}$.
- $\dfrac{\partial z}{\partial x}$, $\dfrac{\partial z}{\partial y}$ gösterimleri de kullanılır.
- Bu limitler varsa kısmi türevler vardır.

Kısmi türevlere sonraki derste devam edilecek.

### Ders sonrası notlar

- **Örnek 8:** Eksenler boyunca limitlerin 0 çıkması limitin 0 olduğunu göstermez. Doğru gerekçe: $\left|\dfrac{4xy^2}{x^2+y^2}\right|\le 4|x|\cdot\dfrac{y^2}{x^2+y^2}\le 4|x|\to 0$. Sıkıştırma teoremiyle limit gerçekten 0'dır.
- **Örnek 11:** Hoca fonksiyonun sürekli olduğunu söyledi. Bunun için $f(0,0)=0$ tanımlı olmalı. Ayrıca $x^2\sin(1/y)$, $y=0$ doğrusu üzerinde tanımsızdır. Limit, fonksiyonun tanımlı olduğu noktalar üzerinden alınır.
- **Seviye eğrisi anlatımı:** Hoca seviye eğrisini anlatırken "hız sabit, türev sıfır" benzetmesini kullandı. Seviye eğrisinin tanımı yalnız $f(x,y)=c$ eşitliğidir; türevle ilgisi yoktur.
- **Ardışık limit:** Hoca "$L_1=L_2$ ise iki katlı limit vardır" dedi. Doğru ifade: iki ardışık limit eşittir. Bu, limitin varlığını garanti etmez.
- **Örnek 3:** Kök içindeki ifade ve bölgenin çizimi altyazıda net anlaşılmıyor.

İsterseniz bu özeti Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
