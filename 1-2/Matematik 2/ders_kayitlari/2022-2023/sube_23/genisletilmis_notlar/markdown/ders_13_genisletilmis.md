# Ders 13 Genişletilmiş Notu: Teğet Düzlem, Lineerleştirme, Tam Diferansiyel, Ekstremumlar ve Kısıtlı Kısmi Türevler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Gradyan Vektörü
- 3. Teğet Düzlem ve Normal Doğru
- 4. İki Yüzeyin Kesişim Eğrisine Teğet Doğru
- 5. Lineerleştirme
- 6. Tam Diferansiyel ile Değişim Tahmini
- 7. Yerel Ekstremumlar, Kritik Nokta ve Eyer Noktası
- 8. Birinci Yöntem: Fark İfadesinin İşareti
- 9. İkinci Türev Testi
- 10. İki Değişkenli Fonksiyonlar için Taylor Formülü
- 11. Kısıtlanmış Değişkenlerle Kısmi Türevler
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Hoca yeni haftaya, çok değişkenli fonksiyonlarda kısmi türevin uygulamalarıyla başladı. Bu dersin konuları şunlardı:

- Teğet düzlem (tangent plane) ve normal doğru (normal line) denklemleri.
- Lineerleştirme (linearization) ile yaklaşık hesap.
- Tam diferansiyel (total differential).
- Maksimum, minimum ve eyer noktaları (ekstremumlar).
- İki değişkenli fonksiyonlar için Taylor açılımı.
- Kısıtlanmış değişkenlerle kısmi türevler (zincir kuralının bir uygulaması).

Hoca, ertesi gün yine bu konuların uygulamalarının çözüleceğini söyledi. Anlatım tablete yazılarak yapıldı; altyazıda yalnız sözlü kısım vardır.

## 2. Gradyan Vektörü

Hoca önce $\nabla F$ işaretini hatırlattı. Bu işaret "nabla $F$" ya da "gradyan $F$" diye okunur ve fonksiyonun bir tür türevidir. Üç değişkenli bir $F(x,y,z)$ fonksiyonu için gradyan, her değişkene göre kısmi türevlerden oluşan vektördür:

$$\nabla F=F_x\,\vec i+F_y\,\vec j+F_z\,\vec k.$$

Burada $x$'e göre kısmi türev $\vec i$ bileşenine, $y$'ye göre kısmi türev $\vec j$ bileşenine, $z$'ye göre kısmi türev $\vec k$ bileşenine yazılır. Bir $P_0(x_0,y_0,z_0)$ noktası verilirse, bu kısmi türevlerde $x,y,z$ yerine noktanın koordinatları konur.

**Örnek (gradyan hesabı).** $F(x,y,z)=x^2y+z$.

- $F_x$: $y$ ve $z$ sabit gibi düşünülür. $x^2y$'nin türevi $2xy$, $z$'nin türevi $0$'dır. $F_x=2xy$.
- $F_y$: $x^2y$'de $y$'nin türevi $1$'dir, $x^2$ aynen kalır. $F_y=x^2$.
- $F_z$: $z$'nin katsayısı $1$'dir. $F_z=1$.
- Sonuç: $\nabla F=2xy\,\vec i+x^2\,\vec j+\vec k$.

<!-- BELİRSİZ: Hoca önce tahtaya başka bir ifade (x^2 y i + x y j + x z k gibi) yazıp sildi; altyazıdan net değil. Nota yalnız silindikten sonraki x^2 y + z örneği alındı. -->

## 3. Teğet Düzlem ve Normal Doğru

$F(x,y,z)=c$ biçiminde kapalı bir fonksiyonla bir yüzey verilsin. Bu yüzeyin $P_0(x_0,y_0,z_0)$ noktasındaki teğet düzlemi ve normal doğrusu gradyan vektörüyle bulunur. Gradyan vektörü $\nabla F(P_0)$, teğet düzlemin normal vektörüdür ve normal doğruya paraleldir.

**Teğet düzlem denklemi:**

- $F_x(P_0)(x-x_0)+F_y(P_0)(y-y_0)+F_z(P_0)(z-z_0)=0$.

**Normal doğru denklemi:**

- Simetrik biçim: $\dfrac{x-x_0}{F_x(P_0)}=\dfrac{y-y_0}{F_y(P_0)}=\dfrac{z-z_0}{F_z(P_0)}=t$.
- Parametrik biçim: $x=x_0+F_x(P_0)\,t$, $y=y_0+F_y(P_0)\,t$, $z=z_0+F_z(P_0)\,t$.

Hoca simetrik biçimin geçen derste de yazıldığını hatırlattı. Her kesri bir $t$ parametresine (bazen $\lambda$ dedi) eşitleyip parametrik denklemlere geçiliyor.

Yüzey $z=f(x,y)$ gibi açık biçimde verilirse önce kapalı hale getirilir: $z$ bir tarafa atılır ve $F(x,y,z)=0$ yazılır.

> **Hocanın vurgusu:** Teğet düzlem ve normal doğru soruları gradyan vektörüyle bulunur; bunlarla ilgili sorular sınavda gelebilir.

### 3.1 Örnek 1: Paraboloide Teğet Düzlem ve Normal Doğru

**Soru.** $z=9-x^2-y^2$ yüzeyinin $P_0(1,2,4)$ noktasındaki teğet düzlemi ve normal doğrusu nedir?

Hoca önce yüzeyi çizdi. $x=0$ alınırsa $z=9-y^2$, $y=0$ alınırsa $z=9-x^2$ olur. İkisi de kolları aşağı doğru, tepesi $z=9$'da olan parabollerdir. Yüzey, kolları aşağı açılan bir paraboloittir ve aşağı doğru kesintisiz devam eder.

**Çözüm.**

- Kapalı hale getir: $z$'yi diğer tarafa at. $F(x,y,z)=z+x^2+y^2-9=0$.
- Kısmi türevler: $F_x=2x$, $F_y=2y$, $F_z=1$.
- $P_0(1,2,4)$'te: $F_x=2\cdot1=2$, $F_y=2\cdot2=4$, $F_z=1$.
- Gradyan: $\nabla F(P_0)=2\,\vec i+4\,\vec j+\vec k$, yani $(2,4,1)$.
- Teğet düzlem: $2(x-1)+4(y-2)+1(z-4)=0$. Açılırsa $2x+4y+z=14$.
- Normal doğru: $\dfrac{x-1}{2}=\dfrac{y-2}{4}=\dfrac{z-4}{1}=t$, yani $x=1+2t$, $y=2+4t$, $z=4+t$.

Hoca bu sonucun bir test sorusunda "aşağıdakilerden hangisi" biçiminde doğrudan seçileceğini söyledi.

### 3.2 Örnek 2: Orijinde Teğet Düzlem

**Soru.** $z=x\cos y-y\,e^x$ yüzeyinin $(0,0,0)$ noktasındaki teğet düzlemi nedir?

**Çözüm.** Hoca sağdaki ifadeyi $z$'nin yanına eksi olarak geçirdi:

- $F(x,y,z)=z-x\cos y+y\,e^x=0$.
- $F_x=-\cos y+y\,e^x$. $(0,0,0)$'da $F_x=-1$.
- $F_y=x\sin y+e^x$. $(0,0,0)$'da $F_y=1$.
- $F_z=1$.
- $\nabla F(0,0,0)=(-1,1,1)$.
- Teğet düzlem: $-1(x-0)+1(y-0)+1(z-0)=0$, yani $-x+y+z=0$, ya da $x-y-z=0$.

<!-- BELİRSİZ: Fonksiyonun tam yazımı altyazıda parça parça geçiyor ("kosinüs y", "y çarpı e üzeri x"); ifade kısa notla ve gradyan sonucu (-1,1,1) ile tutarlı. -->

## 4. İki Yüzeyin Kesişim Eğrisine Teğet Doğru

Hoca benzer ama farklı bir soru tipi gösterdi: iki yüzeyin kesişimi olan eğriye bir noktada teğet doğru.

### 4.1 Örnek 3: Silindir ve Düzlemin Kesişimi

**Soru.** $f(x,y,z)=x^2+y^2-2=0$ silindiri ile $g(x,y,z)=x+z-4=0$ düzlemi bir $E$ elipsi boyunca kesişir. $P_0(1,1,3)$ noktasında $E$'ye teğet olan doğrunun parametrik denklemini bulunuz.

<!-- BELİRSİZ: Düzlem denklemi ve P0 noktası altyazıda okunmuyor; değerler kısa nottan alındı. Nokta iki denklemi de sağlıyor (1+1=2, 1+3=4). -->

Hoca önce silindiri anlattı. $x^2+y^2=2$ denkleminde $z$ yoktur. Bu yüzden $z$ ne olursa olsun kesit aynı çemberdir: merkezi orijin, yarıçapı $\sqrt2$ olan çember. Bu çemberler $z$ ekseni boyunca yukarı ve aşağı kesintisiz devam eder ve bir silindir oluşur. Bu silindiri eğik bir düzlemle kestiğimizde kesişim eğrisi bir elips olur.

**Fikir.** Teğet doğru hem silindirin yüzeyinde hem de düzlemin içinde kalır. Bu yüzden $P_0$'da hem $\nabla f$'ye hem de $\nabla g$'ye diktir. İki vektörün vektörel çarpımı (cross product), ikisine de dik bir vektör verir. O halde teğet doğrunun doğrultu vektörü:

$$\vec v=\nabla f(P_0)\times\nabla g(P_0).$$

**Çözüm.**

- $\nabla f=(2x,\,2y,\,0)$, $P_0$'da $(2,2,0)$.
- $\nabla g=(1,0,1)$.
- $\vec v=(2,2,0)\times(1,0,1)=(2\cdot1-0\cdot0,\;0\cdot1-2\cdot1,\;2\cdot0-2\cdot1)=(2,-2,-2)$ (ara adım eklendi).
- Bir nokta ($P_0$) ve doğrultu belli olduğu için doğru yazılır: $x=1+2t$, $y=1-2t$, $z=3-2t$.

> **Ders sonrası not:** Hoca anlatırken vektörel çarpımın "düzlemin normalini" verdiğini söyledi. Burada bulunan vektör, kesişim eğrisine teğet olan doğrunun doğrultu vektörüdür; aranan bir düzlem değil, bir doğrudur.

## 5. Lineerleştirme

Hoca, birinci dönemde tek değişkenli fonksiyonlar için görülen lineerleştirmeyi hatırlattı. Lineerleştirme ve diferansiyel, yaklaşık hesaplarda kullanılan iki yöntemdir. Çok değişkenli fonksiyonlarda yöntem benzer, yalnız kısmi türevler devreye girer.

**Tanım (lineerleştirme):**

- Tek değişkende: $L(x)=f(x_0)+f'(x_0)(x-x_0)$.
- İki değişkende: $L(x,y)=f(x_0,y_0)+f_x(x_0,y_0)(x-x_0)+f_y(x_0,y_0)(y-y_0)$.
- Üç değişkende, $P_0(x_0,y_0,z_0)$ noktasında: sona $f_z(P_0)(z-z_0)$ terimi eklenir.
- $f(x,y)\approx L(x,y)$. Eşit değil, yaklaşık olarak eşittir.

### 5.1 Örnek 4: Bir Noktada Lineerleştirme

**Soru.** $f(x,y)=x^2-xy+\tfrac12y^2+3$ fonksiyonunun $(3,2)$ noktasındaki lineerleştirmesini bulunuz.

**Çözüm.**

- $f(3,2)=9-6+2+3=8$.
- $f_x=2x-y$. Hoca açıkladı: $x^2$'nin türevi $2x$; $-xy$'de $x$'in türevi $1$ olduğu için $-y$ kalır; geri kalan terimler sıfır olur. $f_x(3,2)=6-2=4$.
- $f_y=-x+y$. $-xy$'den $-x$ gelir; $\tfrac12y^2$'nin türevi $y$'dir (ikiler birbirini götürür). $f_y(3,2)=-3+2=-1$.
- $L(x,y)=8+4(x-3)-1(y-2)=4x-y-2$.

Hoca ardından yaklaşık bir değer sordu: $f(3{,}1;\;1{,}9)$ yaklaşık kaçtır?

- $L(3{,}1;\;1{,}9)=8+4(3{,}1-3)-(1{,}9-2)=8+4(0{,}1)-(-0{,}1)=8+0{,}4+0{,}1=8{,}5$.

> **Ders sonrası not:** Hoca $4\cdot0{,}1$'i $0{,}8$ diye hesapladı ve sonucu "$0{,}8+0{,}1$, yani $0{,}9$" diye söyledi. Doğrusu $4\cdot0{,}1=0{,}4$'tür; artış $0{,}5$, yaklaşık değer $8{,}5$'tir. Gerçek değer $f(3{,}1;\;1{,}9)=8{,}525$'tir.

### 5.2 Örnek 5: Hesap Makinesiz Yaklaşık Değer

**Soru.** $(1{,}1)^2+(2{,}5)^3$ değerini yaklaşık hesaplayınız.

Hoca, bunun elle tam hesaplanmasının zor olduğunu, yaklaşık hesabın mantığının öğrenilmesi gerektiğini söyledi.

**Çözüm.**

- Önce sayıları bir fonksiyona dönüştür: $1{,}1$ yerine $x$, $2{,}5$ yerine $y$. $f(x,y)=x^2+y^3$.
- Yakın ve kolay değerler: $x_0=1$, $y_0=2$.
- $f(1,2)=1+8=9$.
- $f_x=2x$, $f_x(1,2)=2$.
- $f_y=3y^2$, $f_y(1,2)=12$.
- $L(x,y)=9+2(x-1)+12(y-2)$.
- $L(1{,}1;\;2{,}5)=9+2(0{,}1)+12(0{,}5)=9+0{,}2+6=15{,}2$.

**Hocanın sorusu.** Hoca, $y_0$ için $2$ yerine $3$ alınsaydı ne olacağını sordu. Kendi cevabı şuydu: $2{,}9$ olsaydı $3$ alınırdı, ama $2{,}5$ tam ortada olduğu için $2$ de $3$ de alınabilir, sonuç değişmez.

> **Ders sonrası not:** Sonuç aynı çıkmaz. $y_0=3$ alınırsa $f(1,3)=28$, $f_y(1,3)=27$ olur ve $L=28+0{,}2+27(-0{,}5)=14{,}7$ çıkar. Gerçek değer $1{,}21+15{,}625=16{,}835$'tir. $2{,}5$ iki değere de eşit uzaklıkta olduğundan iki seçim de kaba bir yaklaşım verir; fakat sonuçlar farklıdır ($15{,}2$ ve $14{,}7$).

Ders 00:29 ile 00:46 arasında mola verildi.

### 5.3 Örnek 6: $x\,e^{x^2-y}$ için Yaklaşık Değer

**Soru.** $f(x,y)=x\,e^{x^2-y}$ için $f(2{,}05;\;3{,}9)$ değerinin yaklaşığı aşağıdakilerden hangisidir?

Hoca bunu sınavda gelebilecek türden bir soru olarak verdi. İfadede $2{,}05$, $2{,}05$'in karesi ve $3{,}9$ geçtiğini, bunlara $x$ ve $y$ deyip fonksiyonu kurmak gerektiğini söyledi.

<!-- BELİRSİZ: Fonksiyon altyazıda parça parça geçiyor ("x ... e üzeri ... x kare ... 3.9'a y"); ifade kısa notla ve hocanın 2,65 sonucuyla tutarlı. -->

**Çözüm (lineerleştirme ile).**

- En yakın kolay değerler: $x_0=2$, $y_0=4$.
- $f(2,4)=2\,e^{0}=2$.
- $f_x=e^{x^2-y}+x\cdot2x\,e^{x^2-y}=(1+2x^2)\,e^{x^2-y}$, $f_x(2,4)=9$ (ara adım eklendi).
- $f_y=-x\,e^{x^2-y}$, $f_y(2,4)=-2$.
- $L(x,y)=2+9(x-2)-2(y-4)$.
- $L(2{,}05;\;3{,}9)=2+9(0{,}05)-2(-0{,}1)=2+0{,}45+0{,}2=2{,}65$.

Hoca "hesap makinelerinin mantığı da budur" dedi. Aynı soru tam diferansiyelle de çözüldü; bkz. Bölüm 6.2.

> **Ek bilgi (derste anlatılmadı):** Gerçek değer $2{,}05\,e^{0{,}3025}\approx2{,}774$'tür. Lineer yaklaşım $2{,}65$, ikinci mertebe terimleri ihmal ettiği için gerçek değerden biraz uzaktır; $x$ ve $y$'deki değişim küçüldükçe yaklaşım iyileşir.

## 6. Tam Diferansiyel ile Değişim Tahmini

Hoca, diferansiyel hesabın yaklaşık hesapla ilgili önemli bir teknik olduğunu söyledi. Tek değişkenli $y=f(x)$ fonksiyonu için:

$$\frac{dy}{dx}=f'(x)\quad\Rightarrow\quad dy=f'(x)\,dx.$$

İki değişkenli $z=f(x,y)$ fonksiyonunda bunun karşılığı tam diferansiyeldir:

**Tanım (tam diferansiyel):**

- $df=dz=f_x\,dx+f_y\,dy$.
- $df$, fonksiyondaki artış ya da azalış miktarıdır. Pozitifse artış, negatifse azalış vardır.
- Yeni değer yaklaşık olarak $f(x_0,y_0)+df$'dir.

### 6.1 Örnek 7: Konserve Kutusunun Hacmindeki Değişim

**Soru.** Silindirik bir konserve kutusu 3 cm yarıçap ve 12 cm yükseklikle tasarlanmıştır. Yarıçap $dr=+0{,}08$, yükseklik $dh=-0{,}3$ kadar değişirse hacimdeki değişim ne olur?

<!-- BELİRSİZ: Hoca yükseklikteki değişimi altyazıda "eksi 0,03" diye okudu; hocanın 3,06π sonucu ve kısa notun kareden aldığı değer dh = -0,3'tür. -->

Hoca önce silindiri çizdi ve hacmi hesapladı:

- $V=\pi r^2h=\pi\cdot3^2\cdot12=108\pi\ \text{cm}^3$.

Hoca başta yanlışlıkla $2\pi rh$ yazdı, sonra taban alanı çarpı yükseklik formülüne ($\pi r^2h$) düzeltti.

**Çözüm (tam diferansiyel).**

- $dV=V_r\,dr+V_h\,dh$.
- $V_r=2\pi rh=2\pi\cdot3\cdot12=72\pi$.
- $V_h=\pi r^2=9\pi$.
- $dV=72\pi(0{,}08)+9\pi(-0{,}3)=5{,}76\pi-2{,}7\pi=3{,}06\pi$.
- $dV>0$ olduğu için hacim artar.
- Yeni hacim yaklaşık $V+dV=108\pi+3{,}06\pi=111{,}06\pi$ olur.

> **Ders sonrası not:** Hoca değişimlerin birimi yazılmadığı için "herhalde milimetre olmalı" dedi ve sonucu $108\pi$ ile toplarken "milimetreye çevirip" toplanacağını söyledi. Birimler tutarlı olmalıdır. $3{,}06\pi$ sonucu, $dr$ ve $dh$ de cm alındığında geçerlidir. Değişimler mm alınırsa $dr=0{,}008$ cm, $dh=-0{,}03$ cm olur ve $dV=0{,}306\pi\ \text{cm}^3$ çıkar. Ayrıca hoca bir yerde "yarıçaptaki azalış, yükseklikteki artış" dedi; soruda yarıçap artıyor, yükseklik azalıyor.

> **Ek bilgi (derste anlatılmadı):** Gerçek değişim $\pi(3{,}08)^2(11{,}7)-108\pi\approx9{,}40\ \text{cm}^3$'tür. Tam diferansiyelin tahmini $3{,}06\pi\approx9{,}61\ \text{cm}^3$'tür. Fark, ikinci mertebe terimlerden gelir.

### 6.2 Örnek 6'nın Tam Diferansiyelle Çözümü

Hoca $f(2{,}05;\;3{,}9)$ sorusunu bu kez tam diferansiyelle çözdü.

- $x_0=2$, $dx=2{,}05-2=0{,}05$.
- $y_0=4$, $dy=3{,}9-4=-0{,}1$.
- $dz=f_x\,dx+f_y\,dy=9(0{,}05)+(-2)(-0{,}1)=0{,}45+0{,}2=0{,}65$.
- $f(2{,}05;\;3{,}9)\approx f(2,4)+dz=2+0{,}65=2{,}65$.

İki yöntem aynı sonucu verir. Çünkü $L(x,y)=f(x_0,y_0)+df$'dir.

## 7. Yerel Ekstremumlar, Kritik Nokta ve Eyer Noktası

Hoca yaklaşık hesaplardan sonra kısmi türevin başka bir uygulamasına, maksimum ve minimum değerlere geçti. Tek değişkenli fonksiyonlarda türev alınıp sıfıra eşitleniyordu. İki değişkenli fonksiyonlarda benzerlik olsa da teknikler farklıdır.

**Tanım (yerel maksimum ve minimum):** $f:D\subset\mathbb R^2\to\mathbb R$ ve $(a,b)\in D$ olsun.

- $(a,b)$'nin uygun bir komşuluğundaki tüm $(x,y)$ için $f(x,y)\le f(a,b)$ ise $f$, $(a,b)$'de yerel maksimuma sahiptir.
- Tüm $(x,y)$ için $f(x,y)\ge f(a,b)$ ise $f$, $(a,b)$'de yerel minimuma sahiptir.
- Yerel maksimum ya da yerel minimuma birlikte yerel ekstremum denir.

Hoca bunu grafikle anlattı. $(a,b)$ etrafında alınan bütün noktalardaki fonksiyon değerleri $f(a,b)$'nin altında kalıyorsa orada bir tepe, yani yerel maksimum vardır. Hepsi üstünde kalıyorsa bir çukur, yani yerel minimum vardır.

**Tanım (kritik nokta):** $f$'nin tanım kümesindeki bir $(a,b)$ noktasında

- $f_x(a,b)=0$ ve $f_y(a,b)=0$ ise, ya da
- $f_x$ ya da $f_y$ bu noktada mevcut değilse,

$(a,b)$ bir kritik noktadır.

**Teorem (yerel ekstremum için gerekli koşul):** $f$, $(a,b)$'de yerel ekstremuma sahipse ve birinci mertebe kısmi türevler varsa, $f_x(a,b)=0$ ve $f_y(a,b)=0$'dır.

**Tanım (eyer noktası):** Kritik nokta olduğu halde yerel ekstremum olmayan noktaya eyer noktası (saddle point) ya da semer noktası denir.

> **Ders sonrası not:** Hoca eyer noktası için bir yerde "sıfıra eşitleyen değerler yoksa eyer noktası deriz" gibi bir ifade kullandı. Doğrusu yukarıdaki tanımdır: eyer noktası bir kritik noktadır (kısmi türevler orada sıfırdır ya da yoktur), ama orada ne maksimum ne minimum vardır.

## 8. Birinci Yöntem: Fark İfadesinin İşareti

Hoca, geçmiş yıllarda sınav sorusunun bu biçimde geldiğini söyledi. $(a,b)$ bir kritik nokta olsun. Küçük $h$ ve $k$ değerleri için

$$\Delta=f(a+h,\,b+k)-f(a,b)$$

farkının işaretine bakılır:

- Tüm küçük $h,k$ için $\Delta>0$ ise $(a,b)$'de yerel minimum vardır.
- Tüm küçük $h,k$ için $\Delta<0$ ise yerel maksimum vardır.
- $\Delta$'nın işareti $h$ ve $k$'ya göre değişiyorsa $(a,b)$ eyer noktasıdır.

Hoca dersin ikinci yarısında bunu tek değişkenle karşılaştırdı. Tek değişkende $f(a+h)>f(a)$ ise $a$'da minimum, ters eşitsizlik varsa maksimum vardı. Tek değişkende ikinci bir yöntem olarak birinci türevin işaret tablosu kullanılıyordu: türev pozitiften negatife geçerse (artan, sonra azalan) maksimum, negatiften pozitife geçerse minimum vardı. Çok değişkende fark yönteminin karşılığı $f(a+h,b+k)-f(a,b)$ ifadesidir; tablo yönteminin karşılığı ise ikinci türev testidir (Bölüm 9).

### 8.1 Örnek 8: $f(x,y)=x^2+y^2$

**Soru.** Fonksiyonun kritik noktalarını bulup sınıflandırınız.

**Çözüm.**

- $f_x=2x=0$, $f_y=2y=0$. Kritik nokta $(0,0)$.
- $\Delta=f(0+h,\,0+k)-f(0,0)=h^2+k^2$.
- Kareler negatif olamaz; $(h,k)\ne(0,0)$ için $\Delta>0$.
- Sonuç: $(0,0)$'da yerel minimum vardır.

> **Ders sonrası not:** Hoca "$h$ ve $k$ pozitif olduğu için kareler pozitiftir" dedi. $h$ ve $k$ pozitif ya da negatif olabilen küçük sayılardır; $h^2+k^2>0$ olmasının sebebi karelerin işaretinin her zaman pozitif (sıfırdan farklıysa) olmasıdır.

### 8.2 Benzer İkinci Örnek

Hoca hemen ardından bir örnek daha gösterdi. Kısmi türevler sıfıra eşitlenince yine $(0,0)$ kritik noktası çıktı. Fark ifadesi sıfırdan büyük çıktığı için yine yerel minimum vardı.

<!-- BELİRSİZ: Bu ikinci örneğin fonksiyonu altyazıda geçmiyor; yalnız sonucun (0,0)'da yerel minimum olduğu anlaşılıyor. -->

### 8.3 Örnek 9: Fark İfadesi $h^2-k^2$

Üçüncü örnekte yine $(0,0)$ kritik noktası bulundu ve fark ifadesi $\Delta=h^2-k^2$ çıktı.

<!-- BELİRSİZ: Bu örneğin fonksiyonu altyazıda geçmiyor; yalnız fark ifadesi h^2 - k^2 anlaşılıyor. -->

**Soru (hocanın sorusu).** $\Delta=h^2-k^2$ sıfırdan büyük müdür, küçük müdür?

**Cevap.** İkisi de olabilir. $|h|>|k|$ ise pozitif, $|h|<|k|$ ise negatiftir. İşaret değiştiği için $(0,0)$ eyer noktasıdır.

Hoca test sorusunun şıklarını örnek verdi: (A) maksimum noktasıdır, (B) minimum noktasıdır, (C) eyer noktasıdır, (D) hiçbiri. Doğru şık (C)'dir.

Ders 01:08 ile 01:26 arasında ikinci kez mola verildi.

## 9. İkinci Türev Testi

Molanın ardından hoca, ekstremum sorularının hem birinci vize, hem ikinci vize, hem de finalde geldiğini hatırlattı.

> **Hocanın vurgusu:** Maksimum, minimum ve eyer noktası soruları birinci vize, ikinci vize ve finalde geliyor; burası önemli. İkinci türev testinin tekniği çok önemlidir ve pratik yola götürür.

Hoca, farklı yöntemlerin birbirine üstün olmadığını, motosikletle arabanın ulaştığı yerlerin farklı olması gibi her yöntemin kendi işini gördüğünü, bu yüzden hepsinin bilinmesi gerektiğini söyledi.

**Teorem (ikinci türev testi):** $f(x,y)$, bir $D$ bölgesinde tanımlı olsun; birinci ve ikinci mertebe kısmi türevleri sürekli olsun. $(a,b)$ bir kritik nokta olsun: $f_x(a,b)=0$, $f_y(a,b)=0$. Şunları tanımlayalım:

- $A=f_{xx}(a,b)$,
- $B=f_{xy}(a,b)=f_{yx}(a,b)$ (türevler sürekli olduğu için sıra fark etmez),
- $C=f_{yy}(a,b)$.

O zaman:

- $B^2-AC<0$ ve $A>0$ ise $f$, $(a,b)$'de yerel minimuma sahiptir.
- $B^2-AC<0$ ve $A<0$ ise $f$, $(a,b)$'de yerel maksimuma sahiptir.
- $B^2-AC>0$ ise $(a,b)$ eyer noktasıdır.
- $B^2-AC=0$ ise test sonuç vermez. $(a,b)$'de maksimum, minimum ya da eyer noktası olabilir; başka bir yönteme bakılır.

Hoca bir an "$B^2-4AC$" dedi, sonra "4AC değil, $B^2-AC$" diye düzeltti.

> **Ek bilgi (derste anlatılmadı):** Birçok kitap aynı testi $D=f_{xx}f_{yy}-f_{xy}^2=AC-B^2$ ile yazar. O yazımda koşullar ters döner: $D>0$ ve $f_{xx}>0$ ise minimum, $D>0$ ve $f_{xx}<0$ ise maksimum, $D<0$ ise eyer noktası. Derste kullanılan $B^2-AC$, bunun eksi işaretlisidir.

### 9.1 Örnek 10: $f(x,y)=2x^3-6xy+3y^2$

**Soru.** Fonksiyonun kritik noktalarını bulup sınıflandırınız.

**Çözüm.**

- $f_x=6x^2-6y=0 \Rightarrow y=x^2$.
- $f_y=-6x+6y=0 \Rightarrow y=x$.
- Birlikte: $x^2=x \Rightarrow x=0$ ya da $x=1$.
- Kritik noktalar: $(0,0)$ ve $(1,1)$.
- İkinci türevler: $f_{xx}=12x$, $f_{xy}=-6$, $f_{yy}=6$.

Hoca sonucu bir tabloyla gösterdi:

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $0$ | $-6$ | $6$ | $36>0$ | eyer noktası |
| $(1,1)$ | $12$ | $-6$ | $6$ | $36-72=-36<0$, $A>0$ | yerel minimum |

Hoca, test sorusunda "hangisi doğrudur" diye sorulduğunda bu tablonun doğru ifadeyi hemen bulmayı sağladığını söyledi: "$(0,0)$ eyer noktasıdır" ya da "fonksiyon $(1,1)$'de yerel minimuma sahiptir" doğru ifadelerdir.

### 9.2 Örnek 11: $f(x,y)=x^3-3x^2+3xy^2-3y^2$

**Soru.** Fonksiyonun ekstremum noktalarını ve eyer noktalarını bulunuz.

**Çözüm.**

- $f_x=3x^2-6x+3y^2$.
- $f_y=6xy-6y=6y(x-1)$.
- $f_y=0$ ise ya $y=0$ ya da $x=1$.
- $x=1$ ise $f_x=3-6+3y^2=0 \Rightarrow y^2=1 \Rightarrow y=\pm1$. Noktalar: $(1,1)$, $(1,-1)$.
- $y=0$ ise $f_x=3x^2-6x=3x(x-2)=0 \Rightarrow x=0$ ya da $x=2$. Noktalar: $(0,0)$, $(2,0)$.
- Dört kritik nokta: $(0,0)$, $(1,1)$, $(1,-1)$, $(2,0)$.
- İkinci türevler: $f_{xx}=6x-6$, $f_{xy}=6y$, $f_{yy}=6x-6$.

| Nokta | $A$ | $B$ | $C$ | $B^2-AC$ | Sonuç |
|---|---|---|---|---|---|
| $(0,0)$ | $-6$ | $0$ | $-6$ | $-36<0$, $A<0$ | yerel maksimum |
| $(1,1)$ | $0$ | $6$ | $0$ | $36>0$ | eyer noktası |
| $(1,-1)$ | $0$ | $-6$ | $0$ | $36>0$ | eyer noktası |
| $(2,0)$ | $6$ | $0$ | $6$ | $-36<0$, $A>0$ | yerel minimum |

> **Hocanın vurgusu:** Bu tabloyu çizerseniz "aşağıdakilerden hangisi doğrudur/yanlıştır" sorusunda doğruları hemen bulursunuz; yanlışları çıkarmak da kolaydır. "Bir soruyu garantilemiş oluyoruz."

## 10. İki Değişkenli Fonksiyonlar için Taylor Formülü

Hoca önce tek değişkenli Taylor formülünü hatırlattı. $x_0$ noktasında:

$$f(x)=f(x_0)+f'(x_0)(x-x_0)+\frac{f''(x_0)}{2!}(x-x_0)^2+\cdots$$

Açılımın yapılabilmesi için fonksiyonun bu noktada yeterince türevlenebilir olması gerekir.

**Formül (iki değişkenli Taylor, $(a,b)$ noktasında, ikinci mertebeye kadar):**

$$f(x,y)\approx f(a,b)+f_x(x-a)+f_y(y-b)+\frac{1}{2!}\Big[f_{xx}(x-a)^2+2f_{xy}(x-a)(y-b)+f_{yy}(y-b)^2\Big]$$

- Bütün türevler $(a,b)$ noktasında hesaplanır.
- Formül $\frac{1}{3!}$'lü terimlerle sonsuza kadar devam eder.
- $(a,b)=(0,0)$ ise açılıma Maclaurin açılımı denir; tek değişkende $x_0=0$ için olduğu gibi.

> **Hocanın vurgusu:** Sınavlarda ya birinci mertebe açılım ya da ikinci mertebe açılım gelir; en fazla ikinci mertebeye kadar sorulur, üçüncü genelde sorulmaz.

### 10.1 Örnek 12: $f(x,y)=e^x\sin y$

**Soru.** $f(x,y)=e^x\sin y$ fonksiyonunun $(0,\pi/2)$ noktasındaki ikinci mertebeye kadar Taylor açılımı aşağıdakilerden hangisidir?

Hoca soruyu iki kez çözdü; ikincisinde öğrencilerden soruyu kendisine söylemelerini istedi.

**Çözüm.**

- $f(0,\pi/2)=e^0\sin\frac{\pi}{2}=1\cdot1=1$.
- $f_x=e^x\sin y$, $f_x(0,\pi/2)=1$.
- $f_y=e^x\cos y$, $f_y(0,\pi/2)=\cos90^\circ=0$.
- Birinci mertebe: $f(x,y)\approx1+1\cdot(x-0)+0\cdot(y-\tfrac{\pi}{2})=1+x$.

Hoca derste birinci mertebeyi yazdı ve "devam etsek $\frac12[f_{xx}(x-a)^2+2f_{xy}(x-a)(y-b)+f_{yy}(y-b)^2]$ eklenecek, yerlerine koyup devam ettireceğiz" dedi. İkinci mertebe terimler (ara adım eklendi):

- $f_{xx}=e^x\sin y$, $(0,\pi/2)$'de $1$.
- $f_{xy}=e^x\cos y$, $(0,\pi/2)$'de $0$.
- $f_{yy}=-e^x\sin y$, $(0,\pi/2)$'de $-1$.
- İkinci mertebe: $f(x,y)\approx1+x+\dfrac12\Big[x^2-\big(y-\tfrac{\pi}{2}\big)^2\Big]$.

## 11. Kısıtlanmış Değişkenlerle Kısmi Türevler

Hoca, kısmi türevlerin farklı bir versiyonuna geçti ve "matematiğin en güzel tarafı bu, çalıştıkça ilerliyor" dedi. Konu, değişkenler arasında bir kısıt denklemi olduğunda kısmi türevin nasıl alınacağıdır.

### 11.1 Bağımlı ve Bağımsız Değişken

Hoca önce en basit durumdan başladı. $y=f(x)$'te $x$ bağımsız, $y$ bağımlı değişkendir; $x$ değiştikçe $y$ değişir. $\dfrac{dy}{dx}$ yazıldığında paydadaki $x$ bağımsız değişkendir.

Çok değişkende de türev alınırken hangi değişkenlerin bağımsız olduğu belirlenmelidir. Bunun için özel bir notasyon kullanılır:

**Notasyon:** $\left(\dfrac{\partial w}{\partial x}\right)_y$

- Paydadaki $x$ ve alt indisteki $y$ bağımsız değişkenlerdir.
- Geri kalan değişkenler bağımlıdır.
- Örnek: $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}$ yazılırsa $x,y,z$ bağımsız, yalnız $w$ bağımlıdır.

Hoca $w=x^2+y^2+z^2$, $z=x^2+y^2$ örneğini notasyonu göstermek için açtı; bu örnek derste çözülmedi.

Hoca bir de dört değişkenli kapalı bir $g(x,y,z,w)=0$ fonksiyonu üzerinden şunu sordu: $\left(\dfrac{\partial x}{\partial z}\right)_w$ istenirse hangi değişkenler bağımlıdır? Cevap: $z$ ve $w$ bağımsızdır; $x$ ve $y$ bağımlıdır. $x$, $z$ ve $w$'ye bağlıdır.

<!-- BELİRSİZ: Bu dört değişkenli örnekte alt indisin tam yazımı altyazıdan net değil; "z ve omega bağımsız" cümlesinden (∂x/∂z)_w olduğu anlaşılıyor. -->

> **Hocanın vurgusu:** Önce hangi değişkenin bağımlı, hangisinin bağımsız olduğunu belirleyin. "Bunlar çok önemli." Bu notasyondan da soru gelebiliyor.

**Kural:**

- Bağımsız değişkenler birbirine göre sabittir; türevleri sıfırdır.
- Bağımlı değişkenin türevi zincir kuralıyla gelir.
- Kısıt $F(x,y,z)=0$ biçimindeyse ve $z$ bağımlıysa: $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$, $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}$. Hoca bu formülün daha önce gösterildiğini hatırlattı.

### 11.2 Örnek 13

**Soru.** $w=x^2+y^2+z^2$ ve $z^3-xy+yz+y^3=1$ olsun. $(x,y,z)=(2,-1,1)$ noktasında $\left(\dfrac{\partial w}{\partial x}\right)_y$'yi bulunuz.

<!-- BELİRSİZ: Altyazıda kısıt "z küp eksi x y artı y z artı y küp artı bir" diye geçiyor; nokta (2,-1,1) denklemi "= 1" biçiminde sağlıyor, bu yüzden kısa nottaki yazım alındı. -->

**Çözüm.**

- $x,y$ bağımsız; $z$ ve $w$ bağımlı.
- $w$'nin $x$'e göre türevi: $x^2$'den $2x$; $y^2$'den $0$ ($y$ bağımsız); $z^2$'den zincir kuralıyla $2z\,\dfrac{\partial z}{\partial x}$.
- $\dfrac{\partial w}{\partial x}=2x+2z\,\dfrac{\partial z}{\partial x}$.
- $F=z^3-xy+yz+y^3-1$: $F_x=-y$, $F_z=3z^2+y$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}=\dfrac{y}{3z^2+y}$.

Hoca derste "değerleri yerine yazıp işlemi yapıyoruz" dedi; sayısal sonucu söylemedi. Sonuç (ara adım eklendi):

- $(2,-1,1)$'de: $\dfrac{\partial z}{\partial x}=\dfrac{-1}{3-1}=-\dfrac12$.
- $\left(\dfrac{\partial w}{\partial x}\right)_y=2\cdot2+2\cdot1\cdot\left(-\dfrac12\right)=4-1=3$.

### 11.3 Örnek 14

**Soru.** $w=x^2+y-z+\sin t$ ve $x+y=t$ olsun. $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}$'yi bulunuz.

**Çözüm.**

- $x,y,z$ bağımsız; $w$ ve $t$ bağımlı ($t=x+y$).
- $x^2$'den $2x$; $y$ ve $-z$ bağımsız olduğu için $0$.
- $\sin t$'den zincir kuralıyla $\cos t\cdot\dfrac{\partial t}{\partial x}$.
- $\dfrac{\partial t}{\partial x}=1$.
- $\left(\dfrac{\partial w}{\partial x}\right)_{y,z}=2x+\cos t=2x+\cos(x+y)$.

Hoca yazarken önce "çarpı" dedi, sonra "pardon, artı" diye düzeltti. Sonda $t$ yerine $x+y$ yazılmalıdır, çünkü sonuç bağımsız değişkenlerle ifade edilir.

> **Ders sonrası not:** Altyazıda sonuç bozuk geçiyor ("2x çarpı kökünüz 2 artı y"). Doğru sonuç $2x+\cos(x+y)$'dir.

### 11.4 Örnek 15

**Soru.** $w=x^2+y^2+z^2$ ve $y\sin z+z\sin x=0$ olsun. $(x,y,z)=(0,1,\pi)$ noktasında $\left(\dfrac{\partial w}{\partial y}\right)_x$'i bulunuz.

Hoca bunu "çok güzel bir soru" diye tanıttı. Soruda birden fazla kısım vardı; hoca "sadece şunu alalım" diyerek $y$'ye göre olanı seçti.

**Çözüm.**

- $x,y$ bağımsız; $w$ ve $z$ bağımlı.
- $\dfrac{\partial w}{\partial y}=0+2y+2z\,\dfrac{\partial z}{\partial y}$.
- $F=y\sin z+z\sin x$: $F_y=\sin z$, $F_z=y\cos z+\sin x$.
- $\dfrac{\partial z}{\partial y}=-\dfrac{\sin z}{y\cos z+\sin x}$.
- $(0,1,\pi)$'de: $\sin\pi=0$, $\cos\pi=-1$, $\sin0=0$. $\dfrac{\partial z}{\partial y}=-\dfrac{0}{-1}=0$ (ara adım eklendi).
- $\left(\dfrac{\partial w}{\partial y}\right)_x=2\cdot1+2\pi\cdot0=2$.

<!-- BELİRSİZ: Hoca şıkları "2, 3, 5, 3 artı 1, 2, 2, 2" gibi okudu; şıkların tam metni altyazıdan çıkmıyor. -->

> **Ek bilgi (derste anlatılmadı):** Aynı soruda $\left(\dfrac{\partial w}{\partial x}\right)_y$ istenirse $\dfrac{\partial z}{\partial x}=-\dfrac{z\cos x}{y\cos z+\sin x}=\pi$ olur ve sonuç $2x+2z\pi=2\pi^2$ çıkar.

### 11.5 Örnek 16: Hocanın Derste Kurduğu Örnek

Hoca, öğrencilerden Örnek 13'ü kendisine ezberden söylemelerini istedi. Cevap gelmeyince yeni bir soruyu kendisi kurdu.

**Soru.** $w=x^2+y^2+z^2$ ve $x\sin y+z\cos x=0$ olsun. $x=0$, $y=\pi$ noktasında $\left(\dfrac{\partial w}{\partial x}\right)_y$'yi bulunuz.

Hoca önce kısıtı $x\sin y+y\cos x=0$ diye yazdı. Türevi alırken kısıtta $z$ olmadığını fark etti ("bir tane $z$ koysaydık bari") ve ikinci terimdeki $y$'yi $z$ yaptı.

**Çözüm.**

- $x,y$ bağımsız; $w$ ve $z$ bağımlı.
- $\dfrac{\partial w}{\partial x}=2x+0+2z\,\dfrac{\partial z}{\partial x}$.
- $F=x\sin y+z\cos x$: $F_x=\sin y-z\sin x$, $F_z=\cos x$.
- $\dfrac{\partial z}{\partial x}=-\dfrac{\sin y-z\sin x}{\cos x}$.
- Noktada: kısıttan $0\cdot\sin\pi+z\cos0=0\Rightarrow z=0$ (ara adım eklendi). $\sin\pi=0$, $\sin0=0$. Pay sıfır olur, $\dfrac{\partial z}{\partial x}=0$.
- $\left(\dfrac{\partial w}{\partial x}\right)_y=2x$; $x=0$'da değeri $0$'dır.

Hoca sonucu "$2x$'e eşit oluyor" diye bıraktı.

> **Ders sonrası not:** Hoca $F_x$'i söylerken kısıt henüz $x\sin y+y\cos x$ idi ve "$-y\sin x$" dedi. $z$'li kısıtta doğrusu $F_x=\sin y-z\sin x$'tir. Bu noktada iki ifade de sıfır olduğundan sonuç değişmez.

## Örnek Sorular

Bu derste video karesi yok; sorular derste sözlü sorulan ve çözülen sorulardan alındı.

**Soru 1** (derste sözlü, 00:09:37). $z=9-x^2-y^2$ yüzeyinin $P_0(1,2,4)$ noktasındaki teğet düzlemi ve normal doğrusu aşağıdakilerden hangisidir?

> **Çözüm:** $F=z+x^2+y^2-9$, $\nabla F(P_0)=(2,4,1)$. Teğet düzlem $2x+4y+z=14$. Normal doğru $x=1+2t$, $y=2+4t$, $z=4+t$.

**Soru 2** (derste sözlü, 00:25:49). $f(x,y)=x^2-xy+\tfrac12y^2+3$ için $f(3{,}1;\;1{,}9)$ yaklaşık kaçtır?

> **Çözüm:** $L(x,y)=4x-y-2$. $L(3{,}1;\;1{,}9)=8+0{,}4+0{,}1=8{,}5$. (Hoca derste $0{,}9$ dedi; bkz. Bölüm 5.1.)

**Soru 3** (derste sözlü, 00:28:49). $(1{,}1)^2+(2{,}5)^3$ yaklaşık hesabında $y_0=2$ yerine $y_0=3$ alınsaydı ne olurdu?

> **Çözüm:** Hoca "fark etmez, sonuç aynı çıkar" dedi. Doğrusu: $y_0=2$ ile $15{,}2$, $y_0=3$ ile $14{,}7$ bulunur; sonuçlar farklıdır. Gerçek değer $16{,}835$'tir.

**Soru 4** (derste sözlü, 00:54:56). $f(x,y)=x\,e^{x^2-y}$ için $f(2{,}05;\;3{,}9)$'un yaklaşık değeri aşağıdakilerden hangisidir? (Hoca: "sınavda gelebilecek türde bir soru".)

> **Çözüm:** $(2,4)$ noktasında $f=2$, $f_x=9$, $f_y=-2$. $2+9(0{,}05)-2(-0{,}1)=2{,}65$.

**Soru 5** (derste sözlü, 01:07:27). Kritik nokta $(0,0)$'da fark ifadesi $h^2-k^2$ çıkmıştır. Bu ifade sıfırdan büyük müdür, küçük müdür? $(0,0)$ ne tür bir noktadır? Şıklar: (A) maksimum noktası, (B) minimum noktası, (C) eyer noktası, (D) hiçbiri.

> **Çözüm:** $h$ ve $k$'ya göre ikisi de olabilir; işaret değiştiği için $(0,0)$ eyer noktasıdır. Cevap (C).

**Soru 6** (derste sözlü, 01:33:46). $f(x,y)=2x^3-6xy+3y^2$ fonksiyonunun kritik noktalarını bulup sınıflandırınız.

> **Çözüm:** $(0,0)$: $B^2-AC=36>0$, eyer noktası. $(1,1)$: $B^2-AC=-36<0$, $A=12>0$, yerel minimum.

**Soru 7** (derste sözlü, 01:37:32). $f(x,y)=x^3-3x^2+3xy^2-3y^2$ fonksiyonunun ekstremum noktalarını bulunuz; aşağıdakilerden hangisi doğrudur?

> **Çözüm:** $(0,0)$ yerel maksimum, $(2,0)$ yerel minimum, $(1,1)$ ve $(1,-1)$ eyer noktası.

**Soru 8** (derste sözlü, 01:43:22). $f(x,y)=e^x\sin y$ fonksiyonunun $(0,\pi/2)$ noktasındaki ikinci mertebeye kadar Taylor açılımı aşağıdakilerden hangisidir?

> **Çözüm:** Birinci mertebe $1+x$ (derste yazıldı). İkinci mertebe $1+x+\tfrac12\big[x^2-(y-\tfrac{\pi}{2})^2\big]$ (ikinci mertebe terimler derste hesaplanmadı; sympy ile doğrulandı).

**Soru 9** (derste sözlü, 02:02:02). $w=x^2+y^2+z^2$, $y\sin z+z\sin x=0$ ise $(0,1,\pi)$'de $\left(\dfrac{\partial w}{\partial y}\right)_x$ kaçtır?

> **Çözüm:** $\dfrac{\partial z}{\partial y}=0$, sonuç $2$.

**Soru 10** (derste sözlü, 02:06:05). Hoca öğrencilerden Örnek 13'ü ($w=x^2+y^2+z^2$, $z^3-xy+yz+y^3=1$, $(2,-1,1)$, $\left(\dfrac{\partial w}{\partial x}\right)_y$) ezberden söylemelerini istedi.

> **Çözüm (derste verilmedi):** $\dfrac{\partial z}{\partial x}=\dfrac{y}{3z^2+y}=-\dfrac12$; $\left(\dfrac{\partial w}{\partial x}\right)_y=4+2(1)(-\tfrac12)=3$. Sympy ile doğrulandı.

## Dersin Toparlaması

Bu derste kısmi türevin çok değişkenli fonksiyonlardaki uygulamaları işlendi. Gradyan vektörü, bir yüzeyin teğet düzleminin normalidir; teğet düzlem ve normal doğru doğrudan $\nabla F(P_0)$ ile yazılır. İki yüzeyin kesişim eğrisine teğet doğrunun doğrultusu ise iki gradyanın vektörel çarpımıdır. Lineerleştirme ve tam diferansiyel aynı fikrin iki yüzüdür: $f(x_0,y_0)+f_x\,dx+f_y\,dy$ ile bir fonksiyonun yakın bir noktadaki değeri ya da değişimi yaklaşık hesaplanır.

İkinci bölümde yerel ekstremumlar ele alındı. Kritik noktalar $f_x=f_y=0$ ile bulunur; sınıflandırma için ya $f(a+h,b+k)-f(a,b)$ farkının işaretine bakılır ya da $A=f_{xx}$, $B=f_{xy}$, $C=f_{yy}$ ile $B^2-AC$'nin işaretine bakılır. Ardından iki değişkenli Taylor formülü ikinci mertebeye kadar yazıldı. Son olarak kısıtlı değişkenlerde, $\left(\dfrac{\partial w}{\partial x}\right)_y$ notasyonuyla önce bağımsız değişkenler belirlenip, bağımlı değişkenin türevinin zincir kuralı ve $-F_x/F_z$ formülüyle bulunduğu görüldü. Hoca ertesi günkü derste bu konuların uygulamalarına devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
