# Ders 12 Genişletilmiş Notu: Vektör ve Düzlem Tekrarı, Zincir Kuralı, Lineerleştirme ve Tam Diferansiyel

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ders Kaynağı: Çözümlü Problem Kitabı
- 2. Vektörler Tekrarı
- 3. Uzayda Doğru ve Düzlem Tekrarı
- 4. Vektör Değerli Fonksiyonlar
- 5. Çok Değişkenli Fonksiyonlar ve Yüzeyler
- 6. Kısmi Türev Tekrarı
- 7. Zincir Kuralı
- 8. Kapalı Fonksiyonların Türevi
- 9. Lineerleştirme ve Yaklaşık Hesap
- 10. Tam Diferansiyel
- Örnek Sorular
- Dersin Toparlaması

## 1. Ders Kaynağı: Çözümlü Problem Kitabı

Hoca derse bir önceki günün (kısmi türev ve katlı integral) konularıyla ilgili soru olup olmadığını sorarak başladı. Ardından ekranda bir kitabın PDF'ini paylaştı ve bu dersin büyük bölümünü bu kitap üzerinden tekrar yaparak geçirdi. <!-- BELİRSİZ: Kitabın adı ve yazarı altyazıda geçmiyor. Kısa notta kareden "Prof. Dr. Mustafa Balcı, Genel Matematik 2 Problemleri" olarak verilmiş. -->

Hocanın anlattığına göre kitap uzayda vektörlerle, doğru ve düzlem denklemleriyle başlıyor. Seriler kısmı kitapta yok. Ardından limit ve süreklilik, kısmi türevler, zincir kuralı, kapalı olarak tanımlanan fonksiyonların türevi, yönlü türevler, kısmi türevlerin geometrik anlamı, iki değişkenli fonksiyonlarda Taylor açılımı, maksimum-minimum problemleri, çok katlı integral ve eğrisel integral geliyor. Hoca dersin kapsamının eğrisel integrale kadar gitmediğini, kitabın yaklaşık 165. sayfasına kadar olan kısmın yeterli olduğunu söyledi.

Kitapta her konu için 10-15 kadar çözümlü örnek ve test soruları bulunuyor. Bazı çözümler şekilli verilmiş. Hoca hepsinin çözülmesinin gerekmediğini, ama belli başlı konuları anlamak için iyi bir kaynak olduğunu söyledi.

## 2. Vektörler Tekrarı

### 2.1 Vektör, Eşitlik ve Boy

Hoca kitabın vektör tanımıyla başladı. Kitap konuyu temelden alıyor: bir $\vec P$ vektörü, iki vektörün eşitliği, bir vektörün bir sayıyla çarpımı. İki vektörün eşit olması için birinci bileşenlerin birbirine, ikinci bileşenlerin birbirine eşit olması gerekir. Hoca bu kısımların basit gelebileceğini, hızlı geçilebileceğini söyledi.

Bir vektörün boyu (norm, uzunluk) bileşenlerin karelerinin toplamının kareköküdür. $\vec u=(a_1,a_2)$ için:

$$\|\vec u\|=\sqrt{a_1^2+a_2^2}.$$

Hoca önce "$a^2+b^2$" deyip sonra "$a_1$'in karesi, $a_2$'nin karesi" diye düzeltti.

**Tanım (Birim vektör).**

- Boyu $1$ olan vektöre birim vektör (unit vector) denir: $\|\vec u\|=1$.

### 2.2 Uzayda İki Nokta Arası Uzaklık

Uzayda noktalar üç bileşenlidir. İki nokta arasındaki uzaklık, karşılıklı bileşenlerin farklarının karelerinin toplamının kareköküdür:

$$d=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2+(z_2-z_1)^2}.$$

Üç boyutlu bir vektörün boyu da aynı şekilde, üç bileşenin karelerinin toplamının kareköküdür. Kitapta bunun yanında kürenin denklemi de veriliyor.

### 2.3 Skaler Çarpım ve Vektörel Çarpım

İki vektörün skaler çarpımı (dot product) bileşenler cinsinden "birinciyle birinci, ikinciyle ikinci" çarpılıp toplanarak bulunur. Açı cinsinden:

$$\vec u\cdot\vec v=\|\vec u\|\,\|\vec v\|\cos\theta.$$

Vektörel çarpımın (cross product) boyu ise aradaki açının sinüsüyle verilir:

$$\|\vec u\times\vec v\|=\|\vec u\|\,\|\vec v\|\sin\theta.$$

Hoca öğrencilere skaler çarpımdaki açı fonksiyonunu sordu (Örnek Sorular bölümüne bakın). Kendi cevabı şuydu: vektörel çarpımda iki vektör arasındaki açının sinüsü, skaler çarpımda kosinüsü vardır.

> **Ders sonrası not:** Hoca vektörel çarpımı anlatırken "çarpı şeklini gösteriyor, birincinin boyu, ikincinin boyu, aradaki açının sinüsü" dedi. $\vec u\times\vec v$ bir vektördür. $\|\vec u\|\|\vec v\|\sin\theta$ bu vektörün boyudur, vektörün kendisi değildir.

Kitapta paralel ve dik vektörlerin koşulları da var. Paralel vektörlerin bileşenleri orantılıdır. Dik vektörlerin skaler çarpımı sıfırdır.

### 2.4 Karma Çarpım

Uzayda üç vektör $\vec a$, $\vec b$, $\vec c$ verilsin. Karma çarpım (scalar triple product) $\vec a\cdot(\vec b\times\vec c)$ biçimindedir. Önce $\vec b$ ile $\vec c$ vektörel çarpılır, sonra sonuç $\vec a$ ile skaler çarpılır. Hesapta üç vektör alt alta yazılır ve determinant alınır:

$$\vec a\cdot(\vec b\times\vec c)=\begin{vmatrix}a_1&a_2&a_3\\ b_1&b_2&b_3\\ c_1&c_2&c_3\end{vmatrix}.$$

Hoca karma çarpımın ne verdiğini sordu ve kitaptaki şekilden gösterdi: $\vec a$, $\vec b$, $\vec c$ vektörleri üzerine kurulan paralel yüzlünün hacmi. Hacim için mutlak değer alınır.

**Özellik.**

- $\vec a$, $\vec b$, $\vec c$ aynı düzlemdeyse paralel yüzlü yassılaşır, hacim sıfırdır. Bu durumda karma çarpım $0$ olur.

## 3. Uzayda Doğru ve Düzlem Tekrarı

### 3.1 Doğru Denklemleri

Kitapta uzayda doğrunun vektörel denklemi, kartezyen denklemi ve parametrik denklemi; iki noktası verilen doğrunun denklemi yer alıyor. Hoca bunları daha önce çözdüklerini, bu tip sorulardan sınavda soru gelebileceğini söyledi.

İki doğrunun paralellik ve diklik koşulları:

- $d_1$ ve $d_2$ doğruları paralelse doğrultu vektörlerinin bileşenleri orantılıdır: $\dfrac{a}{p}=\dfrac{b}{q}=\dfrac{c}{r}$.
- Diklerse doğrultu vektörlerinin skaler çarpımı sıfırdır, çünkü aradaki açının kosinüsü $\cos 90^\circ=0$'dır.

Kitapta bir noktanın bir doğruya uzaklığı da var.

> **Hocanın vurgusu:** Doğru ve düzlemin normali, doğrultusu gibi kavramlar mühendislikte altyapı olarak kullanılacak. Bunları ders için değil, öğrenmek için çalışırsanız daha faydalı olur.

### 3.2 Bir Noktanın Düzleme Uzaklığı

$A(x_0,y_0,z_0)$ noktasının $Ax+By+Cz+D=0$ düzlemine uzaklığı:

$$d=\frac{|Ax_0+By_0+Cz_0+D|}{\sqrt{A^2+B^2+C^2}}.$$

### 3.3 Paralel İki Düzlem Arasındaki Uzaklık

İki düzlemin $x$, $y$, $z$ katsayıları ($A$, $B$, $C$) aynıysa düzlemler paraleldir. Yalnız sabit terimler farklıdır: $D_1$ ve $D_2$. Bu durumda aradaki uzaklık:

$$\ell=\frac{|D_2-D_1|}{\sqrt{A^2+B^2+C^2}}.$$

Formül, katsayıların gerçekten aynı olması koşuluyla geçerlidir.

> **Hocanın vurgusu:** Sınavda bazen çeldirici olur. Düzlemlerden birinin katsayıları öbürünün iki katı verilir. Bu durumda doğrudan $D_2-D_1$ alınmaz. Önce o denklem $2$'ye bölünerek katsayılar eşitlenir, sonra sabit terimlerin farkı alınır.

**Örnek 1.** Paralel iki düzlem arasındaki uzaklık. <!-- BELİRSİZ: Düzlem denklemleri altyazıda tam okunmuyor. Altyazıda yalnız iki düzlemin normalinin de $(3,-4,12)$ olduğu ve paralel oldukları geçiyor (00:14:27-00:14:41). Denklemler kısa notta kareden alınmış: $3x-4y+12z-8=0$ ve $-6x+8y-24z-10=0$. -->

- Verilen: $3x-4y+12z-8=0$ ve $-6x+8y-24z-10=0$.
- İkinci denklemin katsayıları birincinin $-2$ katıdır. İkinci denklem $-2$'ye bölünür: $3x-4y+12z+5=0$ (ara adım eklendi).
- Şimdi $A=3$, $B=-4$, $C=12$, $D_1=-8$, $D_2=5$.
- $\sqrt{A^2+B^2+C^2}=\sqrt{9+16+144}=\sqrt{169}=13$.
- $\ell=\dfrac{|5-(-8)|}{13}=\dfrac{13}{13}=1$ birim.

### 3.4 İki Düzlem Arasındaki Açı

**Tanım.**

- İki düzlem arasındaki açı, normalleri arasındaki açıdır.

Normaller $\vec n_1$ ve $\vec n_2$ ise açı skaler çarpımdan bulunur:

$$\cos\theta=\frac{\vec n_1\cdot\vec n_2}{\|\vec n_1\|\,\|\vec n_2\|}.$$

**Örnek 2.** Normalleri $\vec n_1=(1,1,0)$ ve $\vec n_2=(2,1,-2)$ olan iki düzlem arasındaki açı. <!-- BELİRSİZ: Düzlem denklemleri altyazıda geçmiyor; normaller hocanın skaler çarpım hesabından ($2\cdot1+1\cdot1+(-2)\cdot0$) kuruldu. -->

- Skaler çarpım: $\vec n_1\cdot\vec n_2=1\cdot2+1\cdot1+0\cdot(-2)=3$.
- $\|\vec n_1\|=\sqrt{1+1+0}=\sqrt2$.
- $\|\vec n_2\|=\sqrt{4+1+4}=\sqrt9=3$.
- $3=\sqrt2\cdot3\cdot\cos\theta$, buradan $\cos\theta=\dfrac{1}{\sqrt2}$.
- $\theta=45^\circ$ ($\pi/4$).

> **Ders sonrası not:** Hoca $\|\vec n_2\|$'yi hesaplarken "$2$'nin karesi $4$, $-2$'nin karesi $4$, $1$'in karesi $1$" deyip toplamı "$4$, $1$ daha $5$, kök $5$" olarak söyledi. Doğrusu $4+4+1=9$, $\|\vec n_2\|=3$'tür. Hocanın vardığı son ifade altyazıda net değil ("üç bölü ... kök al"). Doğru sonuç $\cos\theta=\frac{1}{\sqrt2}$, $\theta=45^\circ$'dir.

Hoca kitaptaki diğer örnekleri ekranda hızlıca gösterdi. Normallerin skaler çarpımı sıfır çıkarsa düzlemler birbirine diktir.

## 4. Vektör Değerli Fonksiyonlar

### 4.1 Tanım

**Tanım (Vektör değerli fonksiyon).**

- $D\subseteq\mathbb{R}$ olsun. $\vec F:D\to\mathbb{R}^3$, $t\mapsto\vec F(t)$ dönüşümüne reel değişkenli vektör değerli fonksiyon (vector-valued function) denir.
- $\vec F(t)=f(t)\,\vec i+g(t)\,\vec j+h(t)\,\vec k$ biçiminde yazılır.

Fonksiyon $D$'den bir $t$ alır ve onu uzayda bir vektöre götürür.

### 4.2 Boy, Limit ve Süreklilik

Vektör değerli fonksiyonun boyu, bileşenlerin karelerinin toplamının kareköküdür:

$$\|\vec F(t)\|=\sqrt{f(t)^2+g(t)^2+h(t)^2}.$$

Limit bileşen bileşen alınır. Üç bileşenin limiti ayrı ayrı varsa vektör fonksiyonun limiti, bu limitlerden oluşan vektördür. Bileşenlerden birinin limiti yoksa vektör fonksiyonun da limiti yoktur.

Süreklilik de bileşenler üzerinden incelenir. Hoca kitaptaki süreksizlik noktası örneklerini gösterdi. Bileşenler polinomsa fonksiyon bütün $\mathbb{R}$'de süreklidir. Rasyonel bileşenlerde paydayı sıfır yapan değerler süreksizlik noktalarıdır.

### 4.3 Türev ve Türev Kuralları

Vektör değerli fonksiyonun türevi bileşenlerin türevleri tek tek alınarak bulunur. Bu türevler mevcutsa fonksiyonun türevi elde edilir.

İki vektör değerli fonksiyonun çarpımlarının türevi, sıradan çarpım kuralına benzer:

$$(\vec u\cdot\vec v)'=\vec u\,'\cdot\vec v+\vec u\cdot\vec v\,',\qquad (\vec u\times\vec v)'=\vec u\,'\times\vec v+\vec u\times\vec v\,'.$$

> **Ek bilgi (derste anlatılmadı):** Vektörel çarpım değişmeli değildir: $\vec u\times\vec v=-\vec v\times\vec u$. Bu yüzden vektörel çarpımın türev kuralında çarpanların sırası korunmalıdır. Skaler çarpım ise değişmeli olduğundan sıra önemli değildir.

### 4.4 Uzay Eğrisinin Uzunluğu

$t$ parametresine bağlı bir uzay eğrisi $\vec r(t)=x(t)\,\vec i+y(t)\,\vec j+z(t)\,\vec k$, $a\le t\le b$ verilsin. Uzunluğu bulmak için eğrinin türevi alınır, türevin normu bulunur ve integrali alınır:

$$L=\int_a^b\|\vec r\,'(t)\|\,dt=\int_a^b\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2+\left(\frac{dz}{dt}\right)^2}\,dt.$$

> **Hocanın vurgusu:** Uzay eğrisinin uzunluğu sınavda gelebilecek sorulardan biridir.

İntegral de türev gibi bileşen bileşen alınır.

### 4.5 Birim Teğet Vektör

**Tanım (Birim teğet vektör).**

- $\vec T(t)=\dfrac{\vec r\,'(t)}{\|\vec r\,'(t)\|}$.

**Örnek 3.** Kitaptaki bir eğrinin birim teğet vektörü. <!-- BELİRSİZ: Eğrinin tam ifadesi altyazıda okunmuyor. Hocanın sözlü hesabında $a^2\sin^2t$, $a^2\cos^2t$ ve $b^2$ terimleri geçiyor; bu, eğrinin $\vec r(t)=a\cos t\,\vec i+a\sin t\,\vec j+bt\,\vec k$ tipinde olduğunu düşündürüyor, ama doğrulanamadı. -->

- Önce türev alınır, sonra türevin boyu bulunur.
- Hoca türevin normunu "kök içinde $a^2\sin^2t+\dots+a^2\cos^2t$" diye okudu. $a^2$ ortak paranteze alınınca $\sin^2t+\cos^2t=1$ kullanılır.
- Bulunan $\vec r\,'(t)$, boyuna bölünerek $\vec T(t)$ elde edilir.

> **Ders sonrası not:** Eğri büyük olasılıkla $\vec r(t)=a\cos t\,\vec i+a\sin t\,\vec j+bt\,\vec k$ helisidir. Öyleyse $\vec r\,'(t)=(-a\sin t,\,a\cos t,\,b)$, $\|\vec r\,'(t)\|=\sqrt{a^2+b^2}$ ve $\vec T(t)=\dfrac{(-a\sin t,\,a\cos t,\,b)}{\sqrt{a^2+b^2}}$ olur.

## 5. Çok Değişkenli Fonksiyonlar ve Yüzeyler

### 5.1 Limit Özellikleri

Hoca bir önceki derste kısmi türeve ve katlı integrale giriş yapıldığını hatırlattı. Çok değişkenli fonksiyonlarda tanım kümesinin çok önemli olduğunu söyledi. Tek değişkenli fonksiyonlardaki limit özellikleri burada da geçerlidir. İki fonksiyonun limitleri $L_1$ ve $L_2$ ise toplamın limiti $L_1+L_2$, farkın limiti $L_1-L_2$, çarpımın limiti $L_1L_2$'dir.

### 5.2 Yüzeyler

Hoca kitaptaki yüzey grafiklerini gösterdi:

- Küre: merkezi orijin, yarıçapı $a$ olan küre.
- Elipsoit: $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}+\dfrac{z^2}{c^2}=1$. $x$ eksenini $a$'da, $y$ eksenini $b$'de, $z$ eksenini $c$'de keser.
- Dairesel silindir.
- $z=ax^2$: Düzlemde bu normal bir paraboldür. Uzayda ise denklemde $y$ olmadığı için eğri $y$ yönünde sınırsız devam eder. Ortaya parabolik bir silindir çıkar.

### 5.3 Tanım Bölgesi

**Örnek 4.** $f(x,y)=\ln(x^2+y^2-4)$ fonksiyonunun tanım bölgesi.

- $\ln$ fonksiyonunun tanımlı olması için içindeki ifade sıfırdan büyük olmalıdır: $x^2+y^2-4>0$.
- Buradan $x^2+y^2>4$.
- Bu, merkezi orijin, yarıçapı $2$ olan çemberin dış bölgesidir.
- Eşitlik olmadığı için çemberin kendisi tanım bölgesine dahil değildir. Kitaptaki şekilde çember kesikli çizilmiş, dış bölge boyanmış.

> **Hocanın vurgusu:** Tanım bölgesiyle ilgili bol soru çözün. Kitapta çözümlü çok örnek var.

## 6. Kısmi Türev Tekrarı

### 6.1 Tanım

**Tanım (Kısmi türev).**

- $A\subseteq\mathbb{R}^2$, $f:A\to\mathbb{R}$, $z=f(x,y)$ ve $(a,b)\in A$ olsun.
- $f_x(a,b)=\displaystyle\lim_{h\to0}\frac{f(a+h,b)-f(a,b)}{h}$ limiti mevcutsa, buna $f$'nin $x$ değişkenine göre $(a,b)$ noktasındaki kısmi türevi denir. $\dfrac{\partial f}{\partial x}(a,b)$ ile de gösterilir.
- $f_y(a,b)=\displaystyle\lim_{k\to0}\frac{f(a,b+k)-f(a,b)}{k}$ limiti mevcutsa, buna $f$'nin $y$'ye göre kısmi türevi denir.

Hoca artışın nerede olduğuna dikkat çekti. $f_x$'te artış yalnız birinci bileşendedir ($h$ kadar), ikinci bileşen $b$ olarak sabit kalır. $f_y$'de ise artış ikinci bileşendedir.

**Geometrik anlam.** $y=b$ düzlemi $z=f(x,y)$ yüzeyini bir eğri boyunca keser. Bu eğrinin $(a,b)$'deki teğetinin eğimi $f_x(a,b)$'dir. $f_y$ için $x$ sabit tutulur ve aynı şey $y$ yönünde yapılır.

### 6.2 Yüksek Mertebeden Kısmi Türevler

Hoca gösterimde sıraya dikkat çekti. $f_{xy}$ yazıldığında önce $x$'e göre, sonra çıkan ifadenin $y$'ye göre türevi alınır. Kesirli gösterimde sıra sağdan sola okunur:

$$f_{xy}=\frac{\partial^2 f}{\partial y\,\partial x}=\frac{\partial}{\partial y}\left(\frac{\partial f}{\partial x}\right).$$

**Teorem (Karışık türevlerin eşitliği).**

- $f$, $f_x$, $f_y$, $f_{xy}$, $f_{yx}$ bir bölgede sürekliyse o bölgede $f_{xy}=f_{yx}$'tir.
- Yani önce $x$'e sonra $y$'ye göre türev almakla, önce $y$'ye sonra $x$'e göre almak arasında fark yoktur.

Kitaptaki örneklerde bir fonksiyonun $f_{xy}$ ve $f_{yx}$ türevleri ayrı ayrı hesaplanıp eşit çıktığı gösteriliyor. Hoca bu eşitliğin nedeninin fonksiyonun ve kısmi türevlerinin sürekliliği olduğunu söyledi.

> **Hocanın vurgusu:** İşlem hatası yapmamak için bol işlem yapın.

**Örnek 5.** $f(x,y)=x^3y+xy^3-3x^2y^2$ için $f_x(1,1)$. <!-- BELİRSİZ: Fonksiyon altyazıda tam okunmuyor; hocanın türev adımlarından ve kısa nottaki kare bilgisinden kuruldu. -->

- $y$ sabit gibi düşünülerek $x$'e göre türev alınır.
- $x^3y$'nin türevi $3x^2y$.
- $xy^3$'ün türevi $y^3$ ($x$'in türevi $1$).
- $-3x^2y^2$'nin türevi $-6xy^2$.
- $f_x(x,y)=3x^2y+y^3-6xy^2$.
- $x=1$, $y=1$ konur: $f_x(1,1)=3+1-6=-2$.

Hoca hesap sırasında önce "eksi dokuz", sonra "eksi üç" deyip "eksi iki" diye düzeltti. Doğru sonuç $-2$'dir.

### 6.3 Laplace Denklemi

**Tanım (Laplace denklemi).**

- $z_{xx}+z_{yy}=0$ denklemine Laplace denklemi denir.
- Bir fonksiyonun ikinci kısmi türevlerinin toplamı sıfırsa fonksiyon Laplace denklemini sağlar.

**Örnek 6.** $z=x^2-y^2$ fonksiyonunun Laplace denklemini sağladığını gösterin. <!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor; $z_x=2x$, $z_{xx}=2$ adımları duyuluyor, fonksiyon kısa nottaki kare bilgisinden alındı. -->

- $z_x=2x$, $z_{xx}=2$.
- $z_y=-2y$, $z_{yy}=-2$.
- $z_{xx}+z_{yy}=2+(-2)=0$. Fonksiyon denklemi sağlar.

> **Ders sonrası not:** Altyazıda $z_y$ ve $z_{yy}$ için "x2" gibi bozuk ifadeler geçiyor. Doğrusu $z_y=-2y$, $z_{yy}=-2$'dir.

> **Ek bilgi (derste anlatılmadı):** Laplace denklemini sağlayan ve ikinci kısmi türevleri sürekli olan fonksiyonlara harmonik fonksiyon (harmonic function) denir. Bu denklem ısı iletimi, elektrostatik ve akışkanlar mekaniğinde denge durumlarını tanımlar.

Hoca bu noktada kitapta parametrik olarak verilen fonksiyonların kısmi türevlerine ve zincir kuralına geçileceğini söyledi ve derse ara verdi.

## 7. Zincir Kuralı

### 7.1 Fikir

Aradan sonra hoca çok değişkenli fonksiyonlarda zincir kuralına (chain rule) geçti. Bazen değişkenler zincirleme olarak birbirine bağlıdır. $z=f(x,y)$ fonksiyonu $x$ ve $y$'ye bağlıdır. $x=g(u,v)$ ve $y=h(u,v)$ ise kendileri $u$ ve $v$'ye bağlıdır. Böylece $z$ dolaylı olarak $u$ ve $v$'ye bağlı olur.

Hoca bunu doğadaki olaylara benzetti. Havanın sıcaklığı, iç sıcaklık, dış sıcaklık, aradaki malzemenin kalitesi gibi bütün faktörler birbirine bağlıdır ve sonuca karışır.

### 7.2 Kural 1: İki Ara Değişken, İki Bağımsız Değişken

$z=f(x,y)$, $x=g(u,v)$, $y=h(u,v)$ olsun. $f$ doğrudan $u$'ya bağlı değildir; $x$ ve $y$ üzerinden bağlıdır. $z$'nin $u$'ya göre türevi için her iki yol toplanır:

$$\frac{\partial z}{\partial u}=\frac{\partial z}{\partial x}\frac{\partial x}{\partial u}+\frac{\partial z}{\partial y}\frac{\partial y}{\partial u}.$$

Hoca bu formülü öğrencilerle birlikte kurdu: "$f$ neye bağlı? $x$'e. $x$ neye bağlı? $u$'ya. Başka? $y$'ye..." $v$ için de aynı yapı yazılır:

$$\frac{\partial z}{\partial v}=\frac{\partial z}{\partial x}\frac{\partial x}{\partial v}+\frac{\partial z}{\partial y}\frac{\partial y}{\partial v}.$$

### 7.3 Kural 2: Tek Parametreye Bağlı Ara Değişkenler

$z=f(x,y)$, $x=x(t)$, $y=y(t)$ ise $z$ sonunda yalnız $t$'ye bağlıdır. Bu yüzden sol tarafta adi türev yazılır:

$$\frac{dz}{dt}=\frac{\partial z}{\partial x}\frac{dx}{dt}+\frac{\partial z}{\partial y}\frac{dy}{dt}.$$

Hoca kitapta bu kuralın kimyasal maddeler arasındaki ilişkiler gibi uygulamalarda da kullanıldığını gösterdi.

### 7.4 Kural 3: Üç Ara Değişken

$u=f(x,y,z)$ ve $x$, $y$, $z$'nin her biri $t$'ye bağlı ise:

$$\frac{du}{dt}=\frac{\partial u}{\partial x}\frac{dx}{dt}+\frac{\partial u}{\partial y}\frac{dy}{dt}+\frac{\partial u}{\partial z}\frac{dz}{dt}.$$

Her ara değişken için bir terim eklenir.

### 7.5 Kural 4: Tek Ara Değişken

$y=f(x)$, $x=g(u,v)$ ise $y$ yalnız $x$ üzerinden $u$ ve $v$'ye bağlıdır:

$$\frac{\partial y}{\partial u}=\frac{dy}{dx}\frac{\partial x}{\partial u},\qquad \frac{\partial y}{\partial v}=\frac{dy}{dx}\frac{\partial x}{\partial v}.$$

Altyazıda $t$, $u$ ve $v$ harfleri yer yer "Trabzon", "Urfa", "Van" diye yanlış yazılmış; içerik bu harflerdir.

## 8. Kapalı Fonksiyonların Türevi

Hoca tek değişkenli kapalı fonksiyonların türevinin ilk dönem görüldüğünü hatırlattı. Çok değişkenli durumda $F(x,y,z)=0$ denklemi $z$'yi $x$ ve $y$'nin fonksiyonu olarak kapalı biçimde tanımlar. O zaman:

$$\frac{\partial z}{\partial x}=-\frac{F_x}{F_z},\qquad \frac{\partial z}{\partial y}=-\frac{F_y}{F_z}.$$

$F_x$ hesaplanırken $y$ ve $z$ sabit gibi düşünülür. Diğerleri de aynı şekilde.

> **Ek bilgi (derste anlatılmadı):** Bu formül zincir kuralından çıkar. $F(x,y,z(x,y))=0$ ifadesinin $x$'e göre türevi alınırsa $F_x+F_z\,\dfrac{\partial z}{\partial x}=0$ bulunur. Buradan $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$ gelir. Formül $F_z\neq0$ olan noktalarda geçerlidir.

## 9. Lineerleştirme ve Yaklaşık Hesap

### 9.1 Tanım

**Tanım (Lineerleştirme).**

- $f$ fonksiyonu $(a,b)$ noktasında türevlenebilir olsun.
- $L(x,y)=f(a,b)+f_x(a,b)(x-a)+f_y(a,b)(y-b)$ fonksiyonuna $f$'nin $(a,b)$ noktasındaki lineerleştirmesi (linearization) denir.
- $f(x,y)\approx L(x,y)$ yaklaşımına $f$'nin $(a,b)$'deki lineer yaklaşımı (linear approximation) denir.

### 9.2 Sezgi

Hoca bunu açıklamak için ekran paylaşımını bırakıp boş bir tahta açtı. Lineerleştirmenin bir yaklaşık hesaplama yöntemi olduğunu ve türevden faydalanıldığını söyledi.

Uzayda $x$, $y$, $z$ eksenleri ve $z=f(x,y)$ yüzeyi çizilsin. Fonksiyonun bir noktadaki değeri doğrudan bilinmiyor olabilir. Tek değişkenli fonksiyonlarda böyle bir değere teğet doğrularla yaklaşılıyordu. İki değişkenli fonksiyonlarda ise düzlemlerle, yani teğet düzlemle yaklaşılır. Bulunan değer yaklaşık değerdir.

Hesap için gerekenler:

- Fonksiyonun $(a,b)$'deki değeri $f(a,b)$.
- $x$'e göre kısmi türev $f_x(a,b)$; bu $(x-a)$ ile çarpılır.
- $y$'ye göre kısmi türev $f_y(a,b)$; bu $(y-b)$ ile çarpılır.

Bunlar toplanınca $L(x,y)$ bulunur ve istenen noktadaki değer yaklaşık olarak hesaplanır. Hoca örneklerin kitapta olduğunu söyledi.

## 10. Tam Diferansiyel

### 10.1 Tanım

Hoca tam diferansiyelin (total differential) de ilk dönem tek değişkenli fonksiyonlar için görüldüğünü hatırlattı. Çok değişkenli fonksiyonda $z$'deki artış iki değişkendeki artışlardan gelir.

**Tanım (Tam diferansiyel).**

- Birinci mertebe: $dz=f_x\,dx+f_y\,dy$.
- İkinci mertebe: $d^2z=z_{xx}\,dx^2+2z_{xy}\,dx\,dy+z_{yy}\,dy^2$.

<!-- BELİRSİZ: İkinci mertebe formül altyazıda bozuk ("ZXX, DX kare, ZY, D kare ... iki tane Z ... DXD"); standart biçimi yazıldı. -->

Hoca ikinci mertebeyi "bir kez daha türev alarak" elde ettiklerini söyledi. Mantığı birinci kuvvet, ikinci kuvvet şeklinde ilerlemektir.

**Örnek 7.** $f(x,y)=x^3-5xy^2+3xy+4x-3y+5$ fonksiyonunun birinci mertebeden tam diferansiyeli. <!-- BELİRSİZ: Fonksiyonun $-3y+5$ kısmı altyazıda duyulmuyor; kısa nottaki kare bilgisinden alındı. Hocanın sözlü türev adımları $3x^2$, $-5y^2$, $+3y$, $+4$ ile uyumlu. -->

- $f_x$ hesaplanırken $y$ sabittir: $x^3\to3x^2$, $-5xy^2\to-5y^2$, $3xy\to3y$, $4x\to4$. $y$'li ve sabit terimlerin türevi $0$'dır.
- $f_x=3x^2-5y^2+3y+4$.
- $f_y$ hesaplanırken $x$ sabittir: $f_y=-10xy+3x-3$ (ara adım eklendi).
- $df=(3x^2-5y^2+3y+4)\,dx+(-10xy+3x-3)\,dy$.

Soru birinci ve ikinci mertebeyi istiyordu; hoca derste yalnız birinciyi yaptı. İkinci mertebe Örnek Sorular bölümündedir.

### 10.2 Uygulama: Koninin Hacmindeki Değişim

**Örnek 8.** Taban yarıçapı $10$ cm, yüksekliği $30$ cm olan bir koninin yüksekliği $3$ mm artırılır, taban yarıçapı $1$ mm azaltılırsa hacmi kaç cm³ değişir?

Hoca soruyu "çok orijinal bir soru" diye tanıttı ve koninin hacim formülünü öğrencilere sordu (Örnek Sorular bölümüne bakın).

- Hacim formülü: $V=\dfrac{\pi r^2h}{3}$. $V$, $r$ ve $h$'ye bağlıdır.
- Başlangıç hacmi: $V=\dfrac{\pi\cdot10^2\cdot30}{3}=1000\pi$ cm³.
- Artışlar: $dh=+3$ mm, $dr=-1$ mm. Yarıçap azaldığı için $dr$ negatiftir.
- Birimler eşitlenir: $dh=0{,}3$ cm, $dr=-0{,}1$ cm.
- Tam diferansiyel: $dV=\dfrac{\partial V}{\partial r}dr+\dfrac{\partial V}{\partial h}dh$.
- $\dfrac{\partial V}{\partial r}=\dfrac{2\pi rh}{3}$, $\dfrac{\partial V}{\partial h}=\dfrac{\pi r^2}{3}$ ($h$'nin türevi $1$, gerisi sabit).
- $dV=\dfrac{2\pi\cdot10\cdot30}{3}(-0{,}1)+\dfrac{\pi\cdot100}{3}(0{,}3)=-20\pi+10\pi=-10\pi$ cm³ (ara adım eklendi).
- Hacim yaklaşık $10\pi\approx31{,}4$ cm³ azalır. Son hacim yaklaşık $1000\pi-10\pi=990\pi$ cm³.

> **Hocanın vurgusu:** Birimler aynı olmalıdır. Biri santimetre, diğeri milimetreyse hepsi aynı birime çevrilir. Yoksa sağlıklı sonuç bulunmaz.

Hoca sonucun yorumunu da verdi. $dV$ pozitif çıkarsa hacim artmış, negatif çıkarsa azalmıştır. Son durumdaki hacim sorulursa ilk hacme $dV$ eklenir: $V+dV$.

> **Ders sonrası not:** Hoca sayısal sonucu derste hesaplamadı; kitaptaki çözümü gösterdi. Doğru sonuç $dV=-10\pi\approx-31{,}4$ cm³'tür. Gerçek değişim $\frac{\pi}{3}(9{,}9^2\cdot30{,}3)-1000\pi\approx-31{,}7$ cm³'tür; tam diferansiyel bunun iyi bir yaklaşığıdır.

Hoca kitaptaki benzer örneklerin hem lineerleştirmeyle hem tam diferansiyelle çözülebileceğini söyledi. Kitapta zincir kuralından sonra limit örnekleri de var.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:04:43). Bir vektörün birim vektör olması için ne gerekir?

- Cevap (derste verildi): Boyu $1$ olmalıdır, $\|\vec u\|=1$.

**Soru 2** (derste sözlü, 00:07:11-00:07:33). Skaler çarpımda $\vec u\cdot\vec v=\|\vec u\|\|\vec v\|\cdot(\;?\;)$; aradaki açının hangi fonksiyonu gelir? Vektörel çarpımda hangisi?

- Cevap (derste verildi): Skaler çarpımda $\cos\theta$, vektörel çarpımın boyunda $\sin\theta$.

**Soru 3** (derste sözlü, 00:08:30). $\vec a$, $\vec b$, $\vec c$ vektörlerinin karma çarpımı geometrik olarak neyi verir?

- Cevap (derste verildi): Bu vektörler üzerine kurulan paralel yüzlünün hacmini. Vektörler aynı düzlemdeyse $0$.

**Soru 4** (derste çözüldü, 00:12:49-00:13:57). Paralel iki düzlem $3x-4y+12z-8=0$ ve $-6x+8y-24z-10=0$ arasındaki uzaklık. <!-- BELİRSİZ: Denklemler altyazıda okunmuyor, kısa nottaki kareden alındı. -->

- Çözüm Örnek 1'de: $\ell=1$ birim.

**Soru 5** (derste çözüldü, 00:16:38-00:18:05). Normalleri $(1,1,0)$ ve $(2,1,-2)$ olan iki düzlem arasındaki açı.

- Çözüm Örnek 2'de: $\theta=45^\circ$.

**Soru 6** (derste çözüldü, 00:28:40). $f(x,y)=\ln(x^2+y^2-4)$ fonksiyonunun tanım bölgesi.

- Çözüm Örnek 4'te: $x^2+y^2>4$, yarıçapı $2$ olan çemberin dışı.

**Soru 7** (derste çözüldü, 00:33:36). Kısmi türevin tanımından yararlanarak $f(x,y)=x^3y+xy^3-3x^2y^2$ için $f_x(1,1)$'i hesaplayın.

- Çözüm Örnek 5'te: $f_x(1,1)=-2$. Hoca türevi kurallarla aldı; tanımdan (limitle) hesap derste yapılmadı.

> **Çözüm (derste verilmedi):** Tanımdan: $f(1+h,1)=(1+h)^3+(1+h)-3(1+h)^2$, $f(1,1)=-1$. $f(1+h,1)-f(1,1)=h^3-2h$ çıkar. $\displaystyle\lim_{h\to0}\frac{h^3-2h}{h}=\lim_{h\to0}(h^2-2)=-2$.

**Soru 8** (derste çözüldü, 00:35:05). $z=x^2-y^2$ fonksiyonunun Laplace denklemini sağladığını gösterin.

- Çözüm Örnek 6'da: $z_{xx}+z_{yy}=2-2=0$.

**Soru 9** (derste kısmen çözüldü, 01:11:00). $f(x,y)=x^3-5xy^2+3xy+4x-3y+5$ fonksiyonunun birinci ve ikinci mertebeden tam diferansiyelini hesaplayın.

- Birinci mertebe Örnek 7'de: $df=(3x^2-5y^2+3y+4)\,dx+(-10xy+3x-3)\,dy$.

> **Çözüm (derste verilmedi):** İkinci mertebe için $f_{xx}=6x$, $f_{xy}=-10y+3$, $f_{yy}=-10x$. O halde $d^2f=6x\,dx^2+2(3-10y)\,dx\,dy-10x\,dy^2$.

**Soru 10** (derste sözlü, 01:14:10). Koninin hacim formülü nedir?

- Cevap (bir öğrenci verdi, hoca onayladı): $V=\dfrac{\pi r^2h}{3}$.

**Soru 11** (derste çözüldü, 01:12:33-01:21:03). Taban yarıçapı $10$ cm, yüksekliği $30$ cm olan bir koninin yüksekliği $3$ mm artırılır, taban yarıçapı $1$ mm azaltılırsa hacmi kaç cm³ değişir?

- Çözüm Örnek 8'de: $dV=-10\pi\approx-31{,}4$ cm³, hacim azalır.

## Dersin Toparlaması

Bu derste hoca çözümlü bir problem kitabı üzerinden dönemin çok değişkenli konularını tekrar etti. Vektörlerde boy, birim vektör, skaler, vektörel ve karma çarpım; uzayda doğru ve düzlemlerde paralellik, diklik, noktanın düzleme uzaklığı, paralel düzlemler arası uzaklık ve düzlemler arasındaki açı hatırlatıldı. Vektör değerli fonksiyonlarda limit, süreklilik, türev, integral, eğri uzunluğu ve birim teğet vektör bileşen bileşen işlendi. Çok değişkenli fonksiyonlarda yüzeyler, tanım bölgesi, kısmi türevin tanımı ve geometrik anlamı, karışık türevlerin eşitliği ve Laplace denklemi örneklerle tekrar edildi.

Dersin ikinci yarısında yeni araçlar geldi: değişkenler zincirleme bağlı olduğunda kullanılan zincir kuralının dört biçimi, kapalı fonksiyonların türevi, bir fonksiyona teğet düzlemle yaklaşan lineerleştirme ve değişkenlerdeki küçük değişimlerin fonksiyona etkisini veren tam diferansiyel. Koni hacmi örneği tam diferansiyelin uygulamasını gösterdi. Hoca bir sonraki derste kısmi türevle ilgili sorular ve geçmiş yılların sınav sorularını çözeceklerini, öğrencilerin çözemedikleri soruları getirmelerini istedi. Konuların birikmeden, planlı çalışılması gerektiğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
