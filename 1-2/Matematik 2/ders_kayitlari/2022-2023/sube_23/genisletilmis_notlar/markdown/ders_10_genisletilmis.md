# Ders 10 Genişletilmiş Notu: Temel Yüzeyler, Seviye Eğrileri ve Çok Değişkenli Fonksiyonlarda Limit ve Süreklilik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Çok Değişkenli Fonksiyon
- 2. Tanım Bölgesi Soruları
- 3. Temel Yüzeyler
- 4. Seviye Eğrisi ve Kontur Eğrisi
- 5. Üç Değişkenli Fonksiyonun Tanım Kümesi
- 6. Çok Değişkenli Fonksiyonlarda Limit
- 7. Limit Kuralları ve Belirsizlik Giderme Örnekleri
- 8. Sıkıştırma (Sandviç) Teoremi
- 9. Ardışık Limit ve Çift Yol Testi
- 10. Süreklilik
- 11. Kısmi Türevlere Giriş
- 12. Örnek Sorular
- 13. Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: Çok Değişkenli Fonksiyon

Ders 28 Mart 2023 Salı günü online yapıldı. Hoca önce bir önceki dersi özetledi: vektörler tekrar edilmiş, vektör değerli fonksiyonlar verilmiş, uzay geometrisi (iki düzlemin birbirine göre durumu, bir noktadan geçen ve bir düzleme dik olan düzlem) çalışılmış, vektör değerli fonksiyonların yay uzunluğu gösterilmiş ve çok değişkenli fonksiyonlara giriş yapılmıştı. Bu ders çok değişkenli fonksiyonlarla devam ediyor.

İki değişkenli bir fonksiyon, düzlemin bir $D$ alt kümesinden gerçel sayılara giden bir kuraldır:

$$f: D\subseteq\mathbb{R}^2\to\mathbb{R},\qquad z=f(x,y).$$

$D$ kümesine **tanım kümesi**, fonksiyonun aldığı değerlerin kümesine **değer kümesi** denir. Fonksiyon kapalı biçimde de yazılabilir: $F(x,y,z)=0$.

Geometrik olarak $z=f(x,y)$ uzayda bir yüzeydir. $(x,y)$ noktasındaki fonksiyon değeri, yüzey üzerindeki noktanın $z$ koordinatı olarak düşünülür.

Benzer biçimde $u=f(x,y,z)$ üç değişkenli bir fonksiyondur. Burada üç bağımsız değişken ($x$, $y$, $z$) ve bir bağımlı değişken ($u$) vardır. Genel olarak $n$ değişkenli fonksiyon şöyle yazılır:

$$u=f(x_1,x_2,\dots,x_n).$$

## 2. Tanım Bölgesi Soruları

Hoca sınavda çok değişkenli fonksiyonlardan mutlaka gelen soru tipinin tanım bölgesini bulup çizmek olduğunu söyledi.

> **Hocanın vurgusu:** Tanım bölgesiyle ilgili farklı tiplerde en az 30 soru çözün. Bunlar kolay ve kaçırılmaması gereken sorulardır.

Hatırlanacak kurallar:

- Köklü ifadenin içi $\ge 0$ olmalıdır.
- Kök paydadaysa içi $>0$ olmalıdır (payda sıfır olamaz).
- Logaritmanın ($\ln$) içi $>0$ olmalıdır.
- $\ln$ paydadaysa içi $1$'den farklı olmalıdır, çünkü $\ln 1=0$.

### 2.1 Örnek 1: Paydada kök

Fonksiyonun paydasında $\sqrt{1-x^2-y^2}$ biçiminde bir kök var. Kök paydada olduğu için eşitlik olamaz:

$$1-x^2-y^2>0\quad\Longrightarrow\quad x^2+y^2<1.$$

Bölge, merkezi orijin ve yarıçapı 1 olan çemberin iç kısmıdır. Çember sınır dahil olmadığı için kesik çizgiyle çizilir.

<!-- BELİRSİZ: 00:06:16 civarında fonksiyonun payı altyazıda okunmuyor; yalnız paydadaki kökün içi $1-x^2-y^2$ olarak anlaşılıyor. -->

Hoca şıklı sorularda aynı bölgenin hem içi taralı ve çemberi düz çizgili hem de kesik çizgili hâlinin verilebileceğini söyledi. Ayırt edici olan sınırın dahil olup olmadığıdır.

> **Hocanın vurgusu:** Test sınavında doğru cevap genelde A şıkkına konmaz; C ya da başka bir şıkka saklanır. Kapalı ve açık sınırlara (düz ya da kesik çizgi) alışık olmak gerekir.

### 2.2 Örnek 2: İki kökün birlikte tanımlı olması

Fonksiyon iki köklü ifade içeriyor. Birincisi payda değil, ikincisi paydada.

- Birinci koşul: $x^2+y^2-1\ge 0$, yani $x^2+y^2\ge 1$. Bu, birim çemberin dışıdır; çember dahildir.
- İkinci koşul (kök paydada): $4-x^2-y^2>0$, yani $x^2+y^2<4$. Bu, merkezi orijin ve yarıçapı 2 olan çemberin içidir; çember dahil değildir.

Fonksiyonun tanımlı olması için iki koşul birlikte sağlanmalıdır:

$$1\le x^2+y^2<4.$$

Bölge bir halkadır. İçteki çember (yarıçap 1) düz çizgiyle, dıştaki çember (yarıçap 2) kesik çizgiyle çizilir. Hoca bunu "içten kapalı, dıştan açık" diye özetledi.

<!-- BELİRSİZ: 00:07:41 ile 00:09:17 arası; fonksiyonun tam ifadesi altyazıda okunmuyor, yalnız iki kökün içleri anlaşılıyor. -->

### 2.3 Örnek 3: Çarpanlara ayrılan kök içi

Kök içi $(3x-y)(3x+y)$ biçiminde çarpanlara ayrılıyor ve kök yine paydada. Bu nedenle çarpım $>0$ olmalıdır. Çarpımın pozitif olması için:

- ya iki çarpan da pozitif: $3x-y>0$ ve $3x+y>0$,
- ya da iki çarpan da negatif: $3x-y<0$ ve $3x+y<0$.

İki durum ayrı ayrı incelenir. Bölge $y=3x$ ve $y=-3x$ doğrularıyla sınırlanır. Hoca bu soruyu bir önceki derste ayrıntılı çözdüğünü, bu derste kısaca üzerinden geçtiğini söyledi.

<!-- BELİRSİZ: 00:09:44 civarında fonksiyonun tamamı ve çizilen bölge altyazıda anlaşılmıyor. -->

> **Ders sonrası not:** İki durum birleştirilince koşul $9x^2-y^2>0$, yani $|y|<3|x|$ olur. Bölge, $y=\pm3x$ doğrularının arasında kalan ve $x$ eksenini içeren iki açık kamadır (büyük olasılıkla tahtadaki çizim budur).

### 2.4 Örnek 4: $f(x,y)=\ln\left[x\ln(y-x)\right]$

Dıştaki $\ln$'in tanımlı olması için içi pozitif olmalıdır: $x\ln(y-x)>0$. İçteki $\ln$ için $y-x>0$ gerekir. İki çarpanın çarpımı pozitif olacağı için iki durum vardır.

**1. durum: iki çarpan da pozitif.**

- $x>0$.
- $\ln(y-x)>0$, yani $y-x>1$, yani $y>x+1$.

Hoca burada $y-x=1$ olamayacağını vurguladı: $y-x=1$ olsaydı $\ln 1=0$ olurdu ve çarpım sıfır çıkardı. Oysa koşul katı eşitsizliktir. Bu yüzden $y=x+1$ doğrusu bölgeye dahil değildir.

> **Hocanın vurgusu:** $\ln 1=0$ olduğu için $y=x+1$ doğrusu dışarıda kalır. Bu koşul çok önemlidir.

Bölge: $y=x+1$ doğrusunun üst tarafı ile $x>0$ yarı düzleminin ortak kısmı.

**2. durum: iki çarpan da negatif.**

- $x<0$.
- $\ln(y-x)<0$. Hoca burada şunu hatırlattı: 0 ile 1 arasındaki sayıların logaritması negatiftir. O hâlde $0<y-x<1$, yani $x<y<x+1$.

Bölge: $y=x$ ile $y=x+1$ doğruları arasındaki şeridin $x<0$ tarafı. Her iki doğru da dahil değildir.

Sonuç olarak tanım bölgesi:

$$D=\{(x,y): x>0,\ y>x+1\}\ \cup\ \{(x,y): x<0,\ x<y<x+1\}.$$

Python ile birkaç nokta denendi: $(1,3)$ ve $(-1,-0.5)$ bölgededir; $(1,1.5)$, $(-1,1)$ ve $(2,3)$ (bu sonuncusu $y=x+1$ üzerinde) bölgede değildir.

## 3. Temel Yüzeyler

Hoca bir önceki derste başlanan temel yüzeylere (quadric surfaces) devam etti. Çizim yöntemi hep aynıdır: Bir değişkeni sıfır alıp ilgili koordinat düzlemindeki kesiti bulmak, sonra kesitleri uzayda birleştirmek.

> **Hocanın vurgusu:** Bu yüzeylerden "aşağıdakilerden hangisidir" biçiminde soru gelebilir. Çok değişkenli fonksiyonları çizemeyen öğrenci, ileride çok katlı integral alırken zorlanır.

> **Ek bilgi (derste anlatılmadı):** Bir yüzeyin koordinat düzlemlerine paralel düzlemlerle kesitlerine "iz" (trace) denir. Hocanın "bir değişkeni sıfırla" yöntemi, iz yöntemidir. $z=0$, $y=0$ ve $x=0$ izlerine bakmak çoğu temel yüzeyi tanımak için yeterlidir.

### 3.1 Küre

$$x^2+y^2+z^2=r^2.$$

$z=0$ alınırsa $x^2+y^2=r^2$ kalır. Bu, $xy$-düzleminde merkezi orijin, yarıçapı $r$ olan çemberdir. Benzer biçimde $y=0$ alınırsa $xz$-düzleminde $x^2+z^2=r^2$ çemberi çıkar. Bu kesitler uzayda birleşince yarıçapı $r$ olan bir küre (sphere) elde edilir.

Merkezi $(a,b,c)$ olan, yarıçapı $r$ olan küre:

$$(x-a)^2+(y-b)^2+(z-c)^2=r^2.$$

### 3.2 Elipsoid

$$\frac{x^2}{a^2}+\frac{y^2}{b^2}+\frac{z^2}{c^2}=1.$$

$z$ terimi kaldırılırsa $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}=1$ elipsi kalır. Bu elips $x$ eksenini $\pm a$'da, $y$ eksenini $\pm b$'de keser. $z^2/c^2$ terimi eklenince yüzey elipsoid (ellipsoid) olur.

### 3.3 Paraboloid

$$z=ax^2+by^2.$$

Hoca önce tek değişkenli hâli hatırlattı: $y=ax^2$, merkezi orijinde, kolları yukarı bakan bir paraboldür. Şimdi hem $x$ yönünden hem $y$ yönünden gelen paraboller vardır. Üç boyutlu uzayda bunlar birleşip paraboloide (paraboloid) dönüşür.

### 3.4 Silindir

$$x^2+y^2=r^2.$$

Düzlemde bu, merkezi orijin, yarıçapı $r$ olan çemberdir. Uzayda ise $z$ hiç kısıtlanmamıştır. Bu yüzden çember $z$ ekseni boyunca yukarı ve aşağı sınırsız uzar. Sonuç bir silindirdir (cylinder). Hoca "çemberler $z$'ye doğru gidiyor, bir sınırlandırma yok" dedi.

### 3.5 Dairesel koni ve eliptik koni

$$x^2+y^2=z^2.$$

Hoca bir değişkeni yok sayarak açıkladı. Düzlemde $y^2=x^2$ denkleminin çözümü $y=x$ ya da $y=-x$ doğrularıdır. Bunlar $\mathbb{R}^2$'de, tek değişkenli fonksiyon olarak çizilir. Üç boyutlu uzaya geçince bu doğrular dairesel koniye (circular cone) dönüşür. Koninin sınırı yoktur, iki yönde sonsuza gider.

> **Ders sonrası not:** Hoca 00:20:14 civarında "parabol dairesel koniye dönüşüyor" dedi. Bu konuda dönüşen eğri parabol değil, $y=\pm x$ doğrularıdır.

$$\frac{x^2}{a^2}+\frac{y^2}{b^2}=z^2$$

denklemi ise eliptik konidir. Kesitler çember yerine elips olur. Hoca bunu "yumurta gibi" diye tarif etti.

> **Ders sonrası not:** Hoca bu yüzeye "elipsoid koni" dedi. Doğru ad "eliptik koni"dir (elliptic cone). Elipsoid kapalı bir yüzeydir (Bölüm 3.2), koni ise sınırsızdır.

## 4. Seviye Eğrisi ve Kontur Eğrisi

### 4.1 Seviye eğrisi

**Tanım (Seviye eğrisi, level curve).**

- $f(x,y)$ fonksiyonunun sabit bir $c$ değerini aldığı noktaların kümesine $f$'nin **seviye eğrisi** denir.
- Denklemi: $f(x,y)=c$.
- Bu eğri $xy$-düzlemindedir.

Hoca seviye eğrisini anlatırken hız benzetmesi kullandı: Hızın sürekli arttığı ya da azaldığı yerler vardır, bir de sabit olduğu yer vardır; sabitin türevi sıfırdır; "bu yüzden $c$ koymak zorundayız" dedi.

> **Ders sonrası not:** Seviye eğrisinin tanımı yalnız $f(x,y)=c$ eşitliğidir. Hız ve türevle doğrudan ilgisi yoktur. Benzetme sezgi içindir: eğri boyunca $f$ değişmez.

### 4.2 Örnek 5: $f(x,y)=100-x^2-y^2$

Soru: $f(x,y)=100-x^2-y^2$ fonksiyonunu çizip $f=0$, $f=51$ ve $f=75$ seviye eğrilerini gösteriniz.

**Yüzeyin şekli.** $x=0$, $y=0$ konunca $f=100$ olur. Tepe noktası $(0,0,100)$'dür. $-x^2-y^2$ terimleri nedeniyle kollar aşağı bakar. Yüzey, kolları aşağı bakan bir paraboloiddir.

**$f=0$ seviye eğrisi.** $f=0$ demek $z=0$ demektir, yani yüzeyin $xy$-düzlemiyle kesişimi:

$$100-x^2-y^2=0\ \Longrightarrow\ x^2+y^2=100.$$

Yarıçapı 10 olan çember.

**$f=51$ seviye eğrisi.** Yüzey $z=51$ düzlemiyle kesilir:

$$100-x^2-y^2=51\ \Longrightarrow\ x^2+y^2=49.$$

Merkezi orijin, yarıçapı 7 olan çember.

**$f=75$ seviye eğrisi.**

$$100-x^2-y^2=75\ \Longrightarrow\ x^2+y^2=25.$$

Yarıçapı 5 olan çember.

Hoca şunu gözlemledi: Kesen düzlem yükseldikçe çemberin yarıçapı küçülür; $z=51$'de 7 iken $z=75$'te 5'e düşer. Seviye eğrisi, bu kesitin $xy$-düzlemine düşen iz düşümüdür. Sympy ile üç denklem de doğrulandı: $100-c$ değerleri $100$, $49$, $25$; yarıçaplar $10$, $7$, $5$.

### 4.3 Kontur eğrisi

**Tanım (Kontur eğrisi, contour curve).**

- Uzayda $z=c$ düzleminin $z=f(x,y)$ yüzeyini kestiği eğriye $f(x,y)=c$ **kontur eğrisi** denir.
- Seviye eğrisinden farkı: kontur eğrisi uzayda, $z=c$ yüksekliğindedir; seviye eğrisi onun $xy$-düzlemine izdüşümüdür.

**Örnek 6.** $f(x,y)=100-x^2-y^2$ yüzeyinin $f=75$ kontur eğrisi nedir?

Cevap: $z=75$ düzleminde yer alan $x^2+y^2=25$ çemberi, yani yarıçapı 5 olan çember. Hoca aynı mantıkla $51$'e karşılık gelen kontur eğrisinin $z=51$ düzlemindeki $x^2+y^2=49$ çemberi olduğunu da söyledi.

> **Ek bilgi (derste anlatılmadı):** Haritalardaki eş yükselti eğrileri (topoğrafik haritalar) seviye eğrilerine günlük hayattan bir örnektir. Arazinin yüksekliği $f(x,y)$ ise aynı yükseklikteki noktaları birleştiren çizgiler $f(x,y)=c$ eğrileridir. Eğrilerin sık olduğu yerde yüzey diktir.

## 5. Üç Değişkenli Fonksiyonun Tanım Kümesi

**Örnek 7.** $w=\sqrt{1-x^2-y^2-z^2}$ fonksiyonunun tanım kümesini bulunuz.

Bu üç değişkenli bir fonksiyondur: $w=f(x,y,z)$. Kök içi negatif olamaz:

$$1-x^2-y^2-z^2\ge 0\ \Longrightarrow\ x^2+y^2+z^2\le 1.$$

Tanım kümesi, merkezi $(0,0,0)$ ve yarıçapı 1 olan kürenin içi ve yüzeyidir. Hoca "dışı da dahil, içi de dahil" diyerek kürenin yüzeyinin de kümeye girdiğini vurguladı.

Bu noktada derse yaklaşık beş dakikalık bir ara verildi.

## 6. Çok Değişkenli Fonksiyonlarda Limit

> **Hocanın vurgusu:** Çok değişkenli fonksiyonlarda limit ve süreklilikten sınavda en az iki soru gelir. İkinci vizede de finalde de mutlaka soru vardır.

### 6.1 Tek değişkenliden çok değişkenliye

Tek değişkenli fonksiyonda $\lim_{x\to a}f(x)=f(a)$ ise fonksiyon $a$'da hem limitlidir hem süreklidir. Limit bir $L$ sayısına eşitse limit vardır denir. Hoca bir farkı hatırlattı: Sürekli olmak için fonksiyonun $a$'da tanımlı olması gerekir; limitin var olması için gerekmez. Tek değişkenli fonksiyonda $a$'ya yalnız iki yönden, sağdan ve soldan yaklaşılır. Bu iki limit eşitse limit vardır.

İki değişkenli fonksiyonda yazım şöyledir:

$$\lim_{(x,y)\to(a,b)}f(x,y)=L.$$

$L=f(a,b)$ ise fonksiyon $(a,b)$'de süreklidir.

Hoca boş bir sayfa açıp $x$, $y$, $z$ eksenlerini çizdi. $xy$-düzleminde $(a,b)$ noktasını işaretledi: $x$ eksenini $a$'da, $y$ eksenini $b$'de kesen doğruların kesişimi. Önemli olan şudur: $(a,b)$'nin komşuluğundaki noktalardan $(a,b)$'ye sonsuz farklı yoldan yaklaşılabilir:

- $x$ ekseni boyunca,
- $y$ ekseni boyunca,
- $y=x$ doğrusu boyunca,
- $y=x^2$ eğrisi boyunca, $y=x^3$ eğrisi boyunca,
- başka herhangi bir eğri boyunca.

Limitin var olması için bütün bu yollarda aynı sonuç çıkmalıdır. Bir tanesi bile farklı çıkarsa limit yoktur, dolayısıyla fonksiyon sürekli de değildir.

> **Hocanın vurgusu:** İki değişkenli fonksiyonda yalnız $x$ ve $y$ eksenleri boyunca bakmak yetmez. Değişik yollardan yaklaşınca da aynı limit çıkmalıdır.

### 6.2 Limitin tanımı

**Tanım (Limit, $\varepsilon$-$\delta$).**

- Her $\varepsilon>0$ sayısı için öyle bir $\delta>0$ bulunabiliyorsa ki
- $0<\sqrt{(x-a)^2+(y-b)^2}<\delta$ olduğunda $|f(x,y)-L|<\varepsilon$ oluyor,
- o zaman $\lim_{(x,y)\to(a,b)}f(x,y)=L$ yazılır.
- Limit varsa tektir.

Hoca $(x,y)$'nin $(a,b)$'nin $\delta$ komşuluğunda olmasını, $f(x,y)$'nin de $L$'nin $\varepsilon$ komşuluğuna düşmesini vurguladı.

## 7. Limit Kuralları ve Belirsizlik Giderme Örnekleri

**Limit kuralları.** $\lim f=L$, $\lim g=M$ ise toplamın, farkın, çarpımın limiti limitlerin toplamı, farkı, çarpımıdır. $M\ne0$ ise bölümün limiti $L/M$'dir. Bunlar tek değişkenli fonksiyonlardaki kurallarla aynıdır. Hoca, tek değişkenli fonksiyonlarda kullanılan tekniklerin (eşlenikle çarpma, trigonometrik özdeşlik vb.) burada da aynen geçerli olduğunu söyledi.

### 7.1 Örnek 8: Doğrudan yerine koyma

Fonksiyon $(a,b)$'de tanımlı ve "güzel" ise $x$ yerine $a$, $y$ yerine $b$ yazılır.

- $(x,y)\to(1,1)$ için verilen ifadede yerine koyunca sonuç $5$ çıktı.
- $(x,y)\to(2,1)$ için verilen ifadede yerine koyunca sonuç $3$ çıktı.

<!-- BELİRSİZ: 00:58:42 ile 00:59:05 arası; iki limitin ifadeleri altyazıda okunmuyor ("4 çarpı 1 ... artı 1 ... 5" gibi parçalar var), yalnız sonuçlar (5 ve 3) anlaşılıyor. -->

### 7.2 Örnek 9: $\displaystyle\lim_{(x,y)\to(0,0)}\frac{4xy^2}{x^2+y^2}=0$ olduğunu gösteriniz

Yerine koyunca $0/0$ belirsizliği çıkar.

<!-- BELİRSİZ: 00:59:19 ile 01:00:00 arası; hoca önce bir sadeleştirme deniyor ("$y^2$ parantezine alırsanız ... $x^2+y^2$ ... artı 1 ... 2"), ama adımlar altyazıda anlaşılmıyor. Sonra yöntemi değiştirip eksenler boyunca baktı. -->

**Hocanın çözümü (eksenler boyunca).**

$x$ ekseni boyunca ($y\to0$ önce):

$$\lim_{x\to0}\left[\lim_{y\to0}\frac{4xy^2}{x^2+y^2}\right]=\lim_{x\to0}\frac{0}{x^2}=0.$$

$y$ ekseni boyunca ($x\to0$ önce):

$$\lim_{y\to0}\left[\lim_{x\to0}\frac{4xy^2}{x^2+y^2}\right]=\lim_{y\to0}\frac{0}{y^2}=0.$$

Hoca iki sonuç da 0 olduğu için limitin 0 olduğunu söyledi.

> **Ders sonrası not:** Eksenler boyunca limitlerin eşit çıkması, limitin var olduğunu göstermez; hoca da dersin ilerleyen kısmında (Bölüm 9) bunun yetmediğini söyledi. Sonuç doğrudur, ama doğru gerekçe şudur: $\dfrac{y^2}{x^2+y^2}\le1$ olduğundan $\left|\dfrac{4xy^2}{x^2+y^2}\right|\le4|x|\to0$. Sıkıştırma teoremiyle limit 0'dır. Sympy ile kutupsal koordinatta ifade $4r\sin^2\theta\cos\theta$ çıkar; $|\,\cdot\,|\le4r\to0$.

### 7.3 Örnek 10: $\displaystyle\lim_{(x,y)\to(0,0)}\frac{x^2-xy}{\sqrt{x}-\sqrt{y}}$

Yerine koyunca $0/0$ belirsizliği çıkar. Hoca iki yol gösterdi; ikisi de geçerlidir.

**Yol 1: Eşlenikle çarpma.** Pay ve payda $\sqrt{x}+\sqrt{y}$ ile çarpılır. Payda $(\sqrt x-\sqrt y)(\sqrt x+\sqrt y)=x-y$ olur:

$$\frac{(x^2-xy)(\sqrt{x}+\sqrt{y})}{x-y}.$$

Pay ortak çarpan parantezine alınır: $x^2-xy=x(x-y)$. Böylece

$$\frac{x(x-y)(\sqrt{x}+\sqrt{y})}{x-y}=x(\sqrt{x}+\sqrt{y}).$$

$x-y$ sadeleşti. Şimdi $(0,0)$ konabilir:

$$\lim_{(x,y)\to(0,0)}x(\sqrt{x}+\sqrt{y})=0\cdot(0+0)=0.$$

**Yol 2.** Hoca "üsttekini alttakine benzetmek" de dedi: pay $x(x-y)=x(\sqrt x-\sqrt y)(\sqrt x+\sqrt y)$ yazılırsa paydadaki $\sqrt x-\sqrt y$ doğrudan sadeleşir ve aynı sonuç çıkar (ara adım eklendi).

Sympy ile $\dfrac{x^2-xy}{\sqrt x-\sqrt y}-x(\sqrt x+\sqrt y)=0$ doğrulandı ($x,y>0$, $x\ne y$ için).

### 7.4 Örnek 11: $\dfrac{1-\cos(xy)}{xy}$, $(x,y)\to(0,0)$

<!-- BELİRSİZ: 01:04:35 civarında altyazıda "bir eksi kosinüs x bölü x ... kosinüs x'ye bölü x'ye" deniyor; ifadenin $\dfrac{1-\cos(xy)}{xy}$ olduğu kısa nottan alındı, altyazıdan tam okunmuyor. -->

Yerine koyunca $0/0$ çıkar. Hoca yarım açı özdeşliğini kullandı:

$$1-\cos(xy)=2\sin^2\frac{xy}{2}.$$

Böylece ($u=xy$ dersek)

$$\frac{1-\cos u}{u}=\frac{2\sin^2(u/2)}{u}=\sin\frac{u}{2}\cdot\frac{\sin(u/2)}{u/2}.$$

$(x,y)\to(0,0)$ iken $u\to0$; birinci çarpan 0'a, ikinci çarpan 1'e gider. Sonuç $0$ (ara adım eklendi).

Hoca başka bir yolu da söyledi: pay ve payda $1+\cos(xy)$ ile çarpılırsa pay $1-\cos^2(xy)=\sin^2(xy)$ olur ve yine aynı sonuç çıkar.

Hoca bu sırada matematiğin sürekli gelişen, sınırı olmayan bir bilim olduğunu, her adımın bir üst kademeyi açtığını söyledi.

> **Hocanın vurgusu:** Tek bir yöntem yoktur. Ne kadar çok soru çözerseniz, sınavda karşılaştığınızda çözme olasılığınız o kadar artar.

Sympy: $\lim_{u\to0}\dfrac{1-\cos u}{u}=0$ ve $1-\cos u-2\sin^2(u/2)=0$ doğrulandı.

## 8. Sıkıştırma (Sandviç) Teoremi

Tek değişkenli fonksiyonlardaki sandviç teoremi çok değişkenli fonksiyonlarda da vardır.

**Teorem (Sıkıştırma teoremi, squeeze theorem).**

- Merkezi $(0,0)$ olan bir dairenin içindeki bütün $(x,y)\ne(0,0)$ noktaları için $g(x,y)\le f(x,y)\le h(x,y)$ olsun.
- $(x,y)\to(0,0)$ iken $g$ ve $h$ aynı $L$ limitine gidiyorsa,
- $f$ de aynı $L$ limitine gider.

### 8.1 Örnek 12: $f(x,y)=x^2\sin\dfrac1y$

Soru: $y\ne0$ için $f(x,y)=x^2\sin\dfrac1y$ olarak verilen fonksiyonun $(0,0)$ noktasındaki limitini bulunuz.

<!-- BELİRSİZ: 01:06:37 civarında fonksiyonun $y=0$ için tanımı altyazıda "y sıfır ... sıfır" diye geçiyor; büyük olasılıkla $y=0$ iken $f=0$ tanımlanmış. -->

**Çözüm.** Sinüs fonksiyonu her zaman $-1$ ile $1$ arasındadır:

$$-1\le\sin\frac1y\le1\qquad(y\ne0).$$

Her taraf $x^2\ge0$ ile çarpılır (eşitsizlik yön değiştirmez):

$$-x^2\le x^2\sin\frac1y\le x^2.$$

Sol tarafın limiti: $\lim_{(x,y)\to(0,0)}(-x^2)=0$. Sağ tarafın limiti: $\lim_{(x,y)\to(0,0)}x^2=0$. Sandviç teoremine göre ortadaki fonksiyonun limiti de 0'dır:

$$\lim_{(x,y)\to(0,0)}x^2\sin\frac1y=0.$$

Hoca fonksiyonun $(0,0)$'daki değerinin de 0 olduğunu, limit ile değer eşit olduğu için fonksiyonun $(0,0)$'da sürekli olduğunu söyledi.

> **Ders sonrası not:** Süreklilik sonucu yalnız $f(0,0)=0$ (ve $y=0$ doğrusu üzerinde $f$'nin bir değeri) tanımlıysa geçerlidir; $x^2\sin(1/y)$ ifadesi $y=0$'da tanımsızdır. Büyük olasılıkla soruda $y=0$ için $f=0$ verilmişti; o zaman $|f(x,y)|\le x^2$ her yerde sağlanır ve sonuç doğrudur.

## 9. Ardışık Limit ve Çift Yol Testi

### 9.1 Ardışık (iki katlı) limitler

**Tanım (Ardışık limitler, iterated limits).**

- $L_1=\displaystyle\lim_{x\to a}\left[\lim_{y\to b}f(x,y)\right]$: önce $y\to b$, sonra $x\to a$.
- $L_2=\displaystyle\lim_{y\to b}\left[\lim_{x\to a}f(x,y)\right]$: önce $x\to a$, sonra $y\to b$.

Hoca $L_1$'i "$x$ ekseni boyunca yaklaşmak", $L_2$'yi "$y$ ekseni boyunca yaklaşmak" diye adlandırdı.

**Sonuçlar.**

- $L_1\ne L_2$ ise $(a,b)$'de limit kesinlikle yoktur.
- $L_1=L_2$ ise fonksiyonun $(a,b)$'de "iki katlı limiti vardır" denir. Ama bu, $\lim_{(x,y)\to(a,b)}f(x,y)$'nin var olduğunu söylemeye yetmez. Limit olabilir de olmayabilir de; başka yöntemlerle kontrol etmek gerekir.

> **Hocanın vurgusu:** Eksenler boyunca bulunan limitler eşit çıktı diye "limit vardır" diyemeyiz. Farklı çıkarsa ise kesinlikle limit yoktur.

### 9.2 Çift yol testi

**Test (Çift yol testi, two-path test).**

- $f$, $(a,b)$'ye iki farklı yol boyunca yaklaşırken iki farklı limite gidiyorsa $\lim_{(x,y)\to(a,b)}f(x,y)$ mevcut değildir.

$(0,0)$ noktası için kullanılan yollar:

- Tek yollar: $y=x$ doğrusu, $y=x^2$ eğrisi, $y=x^3$ eğrisi. Bu yollarda bulunan limitler farklıysa limit yoktur.
- Yol aileleri: $y=kx$, $y=kx^2$, $y=kx^3$. Bu yollar boyunca bulunan limit $k$'ya bağlı çıkarsa limit yoktur.

> **Hocanın vurgusu:** $y=kx$ ya da $y=kx^2$ yolu boyunca bulunan limit $k$'ya bağlıysa limit yoktur. Bu çok önemli.

> **Ek bilgi (derste anlatılmadı):** Tersi doğru değildir: Bütün doğrular ($y=kx$) boyunca aynı limit çıkması da limitin varlığını kanıtlamaz. Limitin varlığını göstermek için sıkıştırma teoremi ya da kutupsal koordinatlar ($x=r\cos\theta$, $y=r\sin\theta$) kullanılır: $|f(x,y)-L|$, $\theta$'dan bağımsız ve $r\to0$ iken sıfıra giden bir ifadeyle sınırlanabiliyorsa limit $L$'dir.

### 9.3 Örnek 13: $\displaystyle\lim_{(x,y)\to(0,0)}\frac{2x^2y}{x^4+y^2}$

Soru: Fonksiyonun $(0,0)$'daki limitinin varlığını araştırınız.

**Çözüm.** $y=kx^2$ yolu boyunca yaklaşılır. $y$ gördüğümüz yere $kx^2$ yazılır:

$$\frac{2x^2\cdot kx^2}{x^4+(kx^2)^2}=\frac{2kx^4}{x^4+k^2x^4}=\frac{2kx^4}{x^4(1+k^2)}=\frac{2k}{1+k^2}.$$

$x^4$'ler sadeleşti ve sonuç $k$'ya bağlı çıktı. Örneğin $k=3$ için $\dfrac{6}{10}=\dfrac35$, $k=4$ için $\dfrac{8}{17}$ olur. Farklı parabollerden yaklaşınca farklı sonuçlar çıkar. Bu yüzden limit yoktur.

Hoca bu soruda $y=kx$ yolunun işe yaramadığını söyledi: $y=kx$ alınca her $k$ için limit 0 çıkar ve bir şey anlaşılmaz. Bu yüzden önce $y=kx$, sonra $y=kx^2$ denenmelidir.

Sympy: $y=kx^2$ boyunca ifade $\dfrac{2k}{k^2+1}$; $y=kx$ boyunca limit $0$. Hocanın sonucu doğru.

### 9.4 Örnek 14: $\displaystyle\lim_{(x,y)\to(0,0)}\frac{3x^2-y^2}{3y^2+x^2}$

Soru: Limitin varlığını araştırınız.

<!-- BELİRSİZ: 01:12:27 civarında fonksiyonun ifadesi altyazıda okunmuyor; ifade kısa nottan alındı. Altyazıdaki sonuçlar ($y=x$ boyunca 1/2, $y=x^2$ boyunca 3, eksenler boyunca 3 ve $-1/3$) bu ifadeyle tutarlı. -->

Hoca aynı soruyu üç yolla çözdü.

**1. yol: $y=kx$ ailesi.**

$$\frac{3x^2-k^2x^2}{3k^2x^2+x^2}=\frac{x^2(3-k^2)}{x^2(3k^2+1)}=\frac{3-k^2}{3k^2+1}.$$

Sonuç $k$'ya bağlı. Limit yoktur.

**2. yol: İki farklı yol.**

$y=x$ doğrusu boyunca:

$$\frac{3x^2-x^2}{3x^2+x^2}=\frac{2x^2}{4x^2}=\frac12.$$

$y=x^2$ eğrisi boyunca:

$$\frac{3x^2-x^4}{3x^4+x^2}=\frac{x^2(3-x^2)}{x^2(1+3x^2)}=\frac{3-x^2}{1+3x^2}\ \xrightarrow{x\to0}\ 3.$$

$\dfrac12\ne3$. Limit yoktur.

**3. yol: Ardışık limitler.**

$$L_1=\lim_{x\to0}\left[\lim_{y\to0}\frac{3x^2-y^2}{3y^2+x^2}\right]=\lim_{x\to0}\frac{3x^2}{x^2}=3,$$

$$L_2=\lim_{y\to0}\left[\lim_{x\to0}\frac{3x^2-y^2}{3y^2+x^2}\right]=\lim_{y\to0}\frac{-y^2}{3y^2}=-\frac13.$$

$L_1\ne L_2$. Limit kesinlikle yoktur.

Hoca, şıklı soruda bu açıklamaların her birinin ayrı bir şıkta yer alabileceğini söyledi. Pratik sıra şudur: önce eksenler boyunca bakılır; farklı çıkarsa başka yönteme gerek kalmaz. Aynı çıkarsa $y=kx$, $y=kx^2$ gibi yollar denenir.

Sympy: $y=kx$ boyunca $\dfrac{3-k^2}{3k^2+1}$; $y=x$ boyunca $\dfrac12$; $y=x^2$ boyunca $3$; ardışık limitler $3$ ve $-\dfrac13$. Hepsi hocanın sonuçlarıyla aynı.

## 10. Süreklilik

**Tanım (Süreklilik, continuity).** $f$ fonksiyonu $(a,b)$ noktasında süreklidir, eğer:

- $f$, $(a,b)$'de tanımlıysa,
- $\lim_{(x,y)\to(a,b)}f(x,y)$ limiti varsa,
- bu limit $f(a,b)$'ye eşitse.

Tanım kümesinin her noktasında sürekli olan fonksiyona **sürekli fonksiyon** denir. Limit yoksa fonksiyon o noktada sürekli değildir.

### 10.1 Örnek 15 (sınav sorusu): Sürekli olduğunu gösteriniz

$$f(x,y)=\begin{cases}\dfrac{x^3-xy^2}{x^2+y^2}, & (x,y)\ne(0,0)\\[2mm] 0, & (x,y)=(0,0)\end{cases}$$

Soru: Fonksiyonun $(0,0)$'da sürekli olduğunu gösteriniz.

<!-- BELİRSİZ: 01:14:48 civarında altyazıda ifade "x y kare ile x kare y kare" diye geçiyor; tam ifade kısa nottan alındı. -->

Hoca bunu örnek bir sınav sorusu olarak verdi. $(0,0)$'daki değer $0$'dır. Limit de $0$ çıkarsa fonksiyon süreklidir.

**Hocanın çözümü (eksenler boyunca).**

- $x$ ekseni boyunca ($y\to0$ önce): $\dfrac{x^3}{x^2}=x\to0$.
- $y$ ekseni boyunca ($x\to0$ önce): pay $0$, payda $y^2$; $\dfrac{0}{y^2}=0$.

İki yönden de $0$ çıktı. Hoca "sıfırda fonksiyon sürekli" dedi.

Hoca $\varepsilon$-$\delta$ tekniğiyle yapılan gösterimin matematik bölümündeki analiz derslerinde gösterilen yöntem olduğunu, sınavda bununla pek uğraşılmayacağını söyledi.

> **Ders sonrası not:** Eksenler boyunca limitlerin $0$ çıkması sürekliliği kanıtlamaz (Bölüm 9.1). Doğru gerekçe: $|x^2-y^2|\le x^2+y^2$ olduğundan
> $$\left|\frac{x^3-xy^2}{x^2+y^2}\right|=\frac{|x|\,|x^2-y^2|}{x^2+y^2}\le|x|\le\sqrt{x^2+y^2}.$$
> $\sqrt{x^2+y^2}<\delta=\varepsilon$ seçilirse $|f(x,y)-0|<\varepsilon$ olur. Limit $0=f(0,0)$, fonksiyon süreklidir. Sympy ile kutupsal koordinatta $f=r\cos\theta\cos2\theta$, yani $|f|\le r$ doğrulandı. Büyük olasılıkla tahtada da bu $\varepsilon$-$\delta$ gösterimi yazılıydı.

### 10.2 Örnek 16: Sürekliliği inceleyiniz

$$f(x,y)=\begin{cases}\dfrac{\sin(xy)}{x^2+y^2}, & (x,y)\ne(0,0)\\[2mm] 0, & (x,y)=(0,0)\end{cases}$$

<!-- BELİRSİZ: 01:16:25 civarında fonksiyonun ifadesi altyazıda okunmuyor; ifade kısa nottan alındı. Altyazıdaki sonuç ($m/(1+m^2)$) bu ifadeyle tutarlı. -->

**Çözüm.**

1. $(0,0)$'da tanımlı mı? Evet, $f(0,0)=0$.
2. $(x,y)\ne(0,0)$ için limite bakılır. $y=mx$ doğrusu boyunca yaklaşılır:

$$\frac{\sin(mx^2)}{x^2+m^2x^2}=\frac{\sin(mx^2)}{x^2(1+m^2)}=m\cdot\frac{\sin(mx^2)}{mx^2}\cdot\frac{1}{1+m^2}\ \xrightarrow{x\to0}\ \frac{m}{1+m^2}.$$

(Ara adım eklendi: $\dfrac{\sin u}{u}\to1$ kullanıldı, $u=mx^2$.)

3. Sonuç $m$'ye bağlı. Örneğin $y=3x$ boyunca $\dfrac{3}{10}$, $y=4x$ boyunca $\dfrac{4}{17}$ çıkar. Limit yoktur.
4. Limit olmadığı için fonksiyon $(0,0)$'da sürekli değildir.

Sympy: $y=mx$ boyunca limit $\dfrac{m}{m^2+1}$. Hocanın sonucu doğru.

## 11. Kısmi Türevlere Giriş

Dersin son dakikalarında hoca kısmi türevlerin (partial derivative) tanımını verdi. Çok değişkenli fonksiyonlarda artık "normal türev" değil, bir değişkene göre kısmi türev alınır.

**Tanım (Birinci mertebe kısmi türevler).** $z=f(x,y)$ için:

- $x$'e göre kısmi türev:
$$\frac{\partial f}{\partial x}=f_x=f_1=\frac{\partial z}{\partial x}=\lim_{h\to0}\frac{f(x+h,y)-f(x,y)}{h}.$$
- $y$'ye göre kısmi türev:
$$\frac{\partial f}{\partial y}=f_y=f_2=\frac{\partial z}{\partial y}=\lim_{h\to0}\frac{f(x,y+h)-f(x,y)}{h}.$$
- Bu limitler varsa kısmi türevler vardır.

Gösterimler hakkında hoca şunları söyledi:

- $\partial$ işareti "kırık d" gibi yazılır.
- Alt indis $1$, birinci değişkene ($x$'e) göre; alt indis $2$, ikinci değişkene ($y$'ye) göre türev demektir.
- $f_x$, $\dfrac{\partial z}{\partial x}$ gibi gösterimlerin hepsi geçerlidir ve aynı şeyi anlatır.

Hoca iki değişkenli fonksiyonun üç boyutlu uzayda çalıştığını hatırlattı. Kısmi türevlere sonraki derste (Pazartesi) devam edilecek.

> **Ek bilgi (derste anlatılmadı):** $f_x$, $y$ sabit tutulduğunda $f$'nin $x$'e göre değişim hızıdır. Geometrik olarak, yüzeyin $y=b$ düzlemiyle kesişiminden çıkan eğrinin $x=a$ noktasındaki teğetinin eğimidir. Pratikte $f_x$ bulunurken $y$ sabit sayı gibi düşünülüp tek değişkenli türev kuralları uygulanır.

## 12. Örnek Sorular

Bu derste kare ya da video yoktur. Aşağıdaki sorular derste sözlü olarak sorulan ya da tahtada çözülen sorulardır.

**Soru 1** (derste sözlü, 00:10:42): $f(x,y)=\ln\left[x\ln(y-x)\right]$ fonksiyonunun tanım bölgesi nedir?

> **Çözüm:** $x>0$ ve $y>x+1$ ya da $x<0$ ve $x<y<x+1$. $y=x+1$ doğrusu $\ln1=0$ olduğu için dahil değildir. Ayrıntı Bölüm 2.4'te.

**Soru 2** (derste sözlü, 00:22:24): $f(x,y)=100-x^2-y^2$ fonksiyonunu çizip $f=0$, $f=51$ ve $f=75$ seviye eğrilerini gösteriniz.

> **Çözüm:** Kolları aşağı bakan paraboloid, tepe $(0,0,100)$. Seviye eğrileri $x^2+y^2=100$, $x^2+y^2=49$, $x^2+y^2=25$; yarıçaplar 10, 7, 5. Ayrıntı Bölüm 4.2'de.

**Soru 3** (derste sözlü, 00:26:02): Aynı yüzeyin $f=75$ kontur eğrisi nedir?

> **Çözüm:** $z=75$ düzlemindeki $x^2+y^2=25$ çemberi (yarıçap 5).

**Soru 4** (derste sözlü, 00:26:38): $w=\sqrt{1-x^2-y^2-z^2}$ fonksiyonunun tanım kümesini bulunuz.

> **Çözüm:** $x^2+y^2+z^2\le1$; merkezi orijin, yarıçapı 1 olan kürenin içi ve yüzeyi.

**Soru 5** (derste sözlü, 00:59:08): $\displaystyle\lim_{(x,y)\to(0,0)}\frac{4xy^2}{x^2+y^2}=0$ olduğunu gösteriniz.

> **Çözüm:** $\left|\dfrac{4xy^2}{x^2+y^2}\right|\le4|x|\to0$; sıkıştırma teoremiyle limit 0. Hoca eksenler boyunca bakıp 0 buldu. Ayrıntı Bölüm 7.2'de.

**Soru 6** (derste sözlü, 01:06:37): $y\ne0$ için $f(x,y)=x^2\sin\dfrac1y$ fonksiyonunun $(0,0)$'daki limitini bulunuz.

> **Çözüm:** $-x^2\le x^2\sin(1/y)\le x^2$; iki taraf da 0'a gider, limit 0. Ayrıntı Bölüm 8.1'de.

**Soru 7** (derste sözlü, 01:11:01): $f(x,y)=\dfrac{2x^2y}{x^4+y^2}$ fonksiyonunun $(0,0)$'daki limitinin varlığını araştırınız.

> **Çözüm:** $y=kx^2$ boyunca limit $\dfrac{2k}{1+k^2}$, $k$'ya bağlı; limit yoktur. Ayrıntı Bölüm 9.3'te.

**Soru 8** (derste sözlü, 01:14:48, hocanın "örnek sınav sorusu" dediği soru): $(x,y)\ne(0,0)$ için $f(x,y)=\dfrac{x^3-xy^2}{x^2+y^2}$, $f(0,0)=0$ fonksiyonunun $(0,0)$'da sürekli olduğunu gösteriniz.

> **Çözüm:** $|f(x,y)|\le|x|\le\sqrt{x^2+y^2}$; $\delta=\varepsilon$ seçilir. Limit $0=f(0,0)$, süreklidir. Ayrıntı Bölüm 10.1'de.

**Soru 9** (derste sözlü, 01:16:25): $(x,y)\ne(0,0)$ için $f(x,y)=\dfrac{\sin(xy)}{x^2+y^2}$, $f(0,0)=0$ fonksiyonunun $(0,0)$'da sürekliliğini inceleyiniz.

> **Çözüm:** $y=mx$ boyunca limit $\dfrac{m}{1+m^2}$, $m$'ye bağlı; limit yok, sürekli değil. Ayrıntı Bölüm 10.2'de.

## Dersin Toparlaması

Bu derste önce tanım bölgesi soruları tekrar edildi: kökün, paydadaki kökün ve logaritmanın koşulları, sınırların dahil olup olmadığı (düz ya da kesik çizgi). Ardından temel yüzeyler (küre, elipsoid, paraboloid, silindir, dairesel ve eliptik koni) bir değişkeni sıfırlayarak kesit alma yöntemiyle tanıtıldı. Seviye eğrisi $f(x,y)=c$ olarak, kontur eğrisi ise $z=c$ düzleminin yüzeyi kestiği eğri olarak tanımlandı ve $100-x^2-y^2$ paraboloidi üzerinde gösterildi.

Dersin ikinci yarısı çok değişkenli fonksiyonlarda limit ve sürekliliğe ayrıldı. Bir noktaya sonsuz farklı yoldan yaklaşılabildiği için limitin bütün yollarda aynı olması gerekir. Limitin varlığı için sıkıştırma teoremi, yokluğu için ardışık limitler ve çift yol testi ($y=kx$, $y=kx^2$ yolları) kullanılır. Süreklilik, limitin var olması ve fonksiyon değerine eşit olmasıdır. Son olarak birinci mertebe kısmi türevlerin limit tanımı verildi. Hoca öğrencilerden bu hafta limit sorularıyla çalışmalarını istedi; sonraki derste kısmi türevlere devam edilecek ve soru çözülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
