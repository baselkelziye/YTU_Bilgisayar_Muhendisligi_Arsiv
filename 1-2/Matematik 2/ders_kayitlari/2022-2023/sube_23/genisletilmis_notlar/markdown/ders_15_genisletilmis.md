# Ders 15 Genişletilmiş Notu: Yönlü Türev, Uzay Eğrileri, Tanım Kümesi ve Limit Üzerine Soru Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Şimdiye Kadar İşlenenler
- 2. Yönlü Türev: Formül, En Büyük ve En Küçük Değer
- 3. İki Doğrunun Belirlediği Düzlem
- 4. Bir Noktanın Bir Doğruya Uzaklığı
- 5. Yönlü Türev Üzerine Başka Sorular
- 6. Noktanın Düzleme Uzaklığı ve Dik İzdüşüm
- 7. En Hızlı Artış ve Azalış Yönleri
- 8. Kısmi Türevin Tanımla Hesabı
- 9. Kuvvet Serisinin Yakınsaklık Yarıçapı
- 10. Seviye Eğrisi, Teğet Vektör ve Gradyan
- 11. Bir Kesişim Eğrisinin Eğimi
- 12. Uzay Eğrileri: Teğet Doğru, Yay Uzunluğu, Açı
- 13. Tanım Kümesi
- 14. Çok Değişkenli Fonksiyonlarda Limit
- 15. Kısmi Türevin Tanımla Hesabı: İkinci Örnek
- 16. Kapalı Fonksiyon Sorusuna Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı ve Şimdiye Kadar İşlenenler

Hoca bu dersi yeni konuya, yani integrale, geçmeden önce soru çözümüne ayırdı. Önce şimdiye kadar işlenen konuları sıraladı:

- Seriler.
- Eğriler ve bu eğrilerin uzunlukları.
- Vektörler, ardından doğru ve düzlem ilişkileri.
- Çok değişkenli fonksiyonların tanım ve değer kümeleri.
- Çok değişkenli fonksiyonlarda limit, süreklilik ve kısmi türev.
- Kısmi türevin uygulamaları, maksimum ve minimum problemleri.

Öğrencilerden anlamadıkları bir konu ya da çözemedikleri bir soru olup olmadığını sordu. Gelen bir talep olmayınca, ekranda paylaştığı "çıkabilecek muhtemel sınav soruları" üzerinden soru çözümüne geçti. Hoca soruları ekranda hazır çözümlü olarak gösterdi ve üzerinden konuşarak, gerektiğinde kırmızı ya da mavi kalemle ekleyerek anlattı. Altyazıda yalnız sözlü kısım olduğu için bazı verilerin tamamı okunamadı; bu yerler ayrıca işaretlendi.

## 2. Yönlü Türev: Formül, En Büyük ve En Küçük Değer

### 2.1 Formül ve Birim Vektör Şartı

Bir $f$ fonksiyonunun $P$ noktasında $\vec u$ yönündeki türevi (directional derivative), gradyan vektörü ile $\vec u$ vektörünün skaler çarpımıdır:

$$D_{\vec u}f(P)=\nabla f(P)\cdot\vec u .$$

Burada gradyan, kısmi türevlerden oluşan vektördür:

$$\nabla f=\frac{\partial f}{\partial x}\,\vec i+\frac{\partial f}{\partial y}\,\vec j+\frac{\partial f}{\partial z}\,\vec k .$$

$\vec u=(u_1,u_2,u_3)$ mutlaka **birim vektör** olmalıdır. Verilen vektör birim değilse, kendi boyuna (normuna) bölünerek birim hale getirilir. Hoca bu birim vektöre $\vec v$ diyor ve formülde artık $\vec u$ yerine $\vec v$ kullanıyor.

> **Hocanın vurgusu:** Yönlü türevde vektörün birim olması "çok kıymetli". Birim değilse önce boyuna bölün.

Örneğin verilen vektör $3\vec i+4\vec j$ ise boyu $\sqrt{9+16}=5$'tir, birim değildir. Boyuna bölünce $\left(\tfrac35,\tfrac45\right)$ elde edilir. Hoca bunun gerçekten birim olduğunu kontrol etti: $\left(\tfrac35\right)^2+\left(\tfrac45\right)^2=1$.

### 2.2 En Büyük, En Küçük ve Sıfır Değer

Skaler çarpımı boy ve açı cinsinden yazarsak:

$$D_{\vec u}f(P)=|\nabla f(P)|\,|\vec u|\cos\theta=|\nabla f(P)|\cos\theta ,$$

çünkü $\vec u$ birim vektördür ve boyu 1'dir. $\theta$, $\nabla f$ ile $\vec u$ arasındaki açıdır. Kosinüs $[-1,1]$ aralığında değer aldığı için:

- **En büyük değer:** $\cos\theta=1$, yani $\theta=0$. Yönlü türev $|\nabla f(P)|$ olur. Yön, $\nabla f$ yönüdür.
- **En küçük değer:** $\cos\theta=-1$, yani $\theta=\pi$. Yönlü türev $-|\nabla f(P)|$ olur. Yön, $-\nabla f$ yönüdür.
- **Sıfır değer:** $\cos\theta=0$, yani $\theta=\tfrac{\pi}{2}$. $\vec u$ gradyana dik olmalıdır.

### 2.3 Örnek 1: En Büyük, En Küçük ve Sıfır Yönlü Türev

**Soru.** $f(x,y)=x^2-xy+y^2-y$ ve $P(1,-1)$ veriliyor. Aşağıdaki şartlarda $\vec u$ yönlerini ve $D_{\vec u}f(P)$ değerlerini bulunuz: (a) en büyük değer, (b) en küçük değer, (c) $D_{\vec u}f(P)=0$.

**Çözüm.** Önce gradyan:

- $f_x=2x-y$.
- $f_y=-x+2y-1$.
- $P(1,-1)$'de: $f_x=2+1=3$, $f_y=-1-2-1=-4$. Yani $\nabla f(P)=3\vec i-4\vec j$.

(a) En büyük değer gradyanın boyudur: $|\nabla f(P)|=\sqrt{3^2+(-4)^2}=5$. Yön, gradyan yönündeki birim vektördür: $\vec u=\left(\tfrac35,-\tfrac45\right)$ (ara adım eklendi).

(b) En küçük değer $-5$'tir. Yön, gradyanın tersidir: $\vec u=\left(-\tfrac35,\tfrac45\right)$ (ara adım eklendi).

Hoca, şıklı soruda "en küçük değer ile en büyük değer hangisidir" diye $-5$ ve $5$'in sorulabileceğini söyledi.

(c) Hoca bu şıkkın tek başına bile soru olabileceğini söyledi. $\vec u=a\vec i+b\vec j$ alınır. $a$ ve $b$ bilinmiyor, ama $\vec u$ birim olmalıdır:

$$a^2+b^2=1 .$$

Yönlü türev sıfır olmalıdır:

$$\nabla f(P)\cdot\vec u=3a-4b=0\ \Rightarrow\ a=\tfrac43 b .$$

Bunu birim şartında yerine yazınca $\tfrac{16}{9}b^2+b^2=1$, yani $b^2=\tfrac{9}{25}$, $b=\pm\tfrac35$ ve $a=\pm\tfrac45$ olur (ara adım eklendi). İki yön bulunur:

$$\vec u_1=\tfrac45\,\vec i+\tfrac35\,\vec j,\qquad \vec u_2=-\tfrac45\,\vec i-\tfrac35\,\vec j .$$

Bu iki yönde $D_{\vec u_1}f=D_{\vec u_2}f=0$'dır.

> **Hocanın vurgusu:** Bu soru tipi "çok orijinal". Birinci vizede, ikinci vizede, finalde, hatta bütünlemede gelebilir.

Hoca sonra en büyük ve en küçük değer mantığını bir kez daha özetledi: Fonksiyon verilmese bile, en büyük değer gradyan yönünde ve gradyanın boyu kadardır, en küçük değer ise gradyanın tersi yönünde ve $-|\nabla f|$ kadardır.

## 3. İki Doğrunun Belirlediği Düzlem

### 3.1 Örnek 2: İki Doğrudan Düzlem Denklemi

**Soru.** $L_1:\ x=-1+t,\ y=2+t,\ z=1-t$ ve $L_2:\ x=1-4s,\ y=1+2s,\ z=2-2s$ doğrularının belirlediği düzlemi bulunuz.

**Çözüm.** Bir düzlemin denklemini yazmak için iki şey yeter: düzlemin **normal vektörü** ve düzlem üzerinde **herhangi bir nokta**.

Normal vektör, iki doğrunun doğrultman vektörlerine diktir. Bu yüzden iki doğrultman vektörünün vektörel çarpımıyla bulunur:

- $\vec v_1=(1,1,-1)$, $\vec v_2=(-4,2,-2)$.
- $\vec n=\vec v_1\times\vec v_2=(0,6,6)$.

Düzlem üzerinde nokta olarak $L_1$'in $t=0$ noktası alınır: $P_0(-1,2,1)$. Hoca $L_2$ üzerinde de $(1,1,2)$ noktasını gösterdi.

Düzlemi tarayan keyfi bir nokta $P(x,y,z)$ olsun. $\overrightarrow{P_0P}$ düzlemin içindedir, normal vektör de düzleme diktir. Öyleyse ikisinin skaler çarpımı sıfırdır:

$$\vec n\cdot\overrightarrow{P_0P}=0 .$$

$\overrightarrow{P_0P}=(x+1,\;y-2,\;z-1)$ olduğundan:

$$0\cdot(x+1)+6(y-2)+6(z-1)=0\ \Rightarrow\ y+z=3 .$$

Kontrol: $L_2$ üzerindeki $(1,1,2)$ noktası da $1+2=3$ ile düzlemi sağlar.

Hoca, düzlem denklemini $L_1$ üzerindeki ya da $L_2$ üzerindeki noktayla yazmanın aynı sonucu vereceğini söyledi.

> **Ders sonrası not:** Hoca tahtada yöntemi gösterirken $L_2$ için "rastgele" $(1,2,3)$ noktasını ve öğrencilerden duyduğu $(-1,1,2)$ normalini kullanıp $-(x-1)+(y-2)+2(z-3)=0$ denklemini yazdı. Bu nokta ve bu normal bu soruya ait değildir; yalnız yöntemi göstermek içindir. Bu sorunun doğru verileri $\vec n=(0,6,6)$ ve $P_0(-1,2,1)$, sonuç $y+z=3$'tür.

## 4. Bir Noktanın Bir Doğruya Uzaklığı

### 4.1 Örnek 3: Noktanın Doğruya Uzaklığı

**Soru.** $P(0,0,12)$ noktasının $L:\ x=4t,\ y=-2t,\ z=2t$ doğrusuna uzaklığını bulunuz.

**Çözüm.** İstenen, en kısa uzaklıktır. Önce doğru üzerinde bir nokta bulunur. $t=1$ için $Q(4,-2,2)$ elde edilir.

- $\overrightarrow{QP}=P-Q=(-4,2,10)$.
- Doğrunun doğrultman vektörü, $t$'nin katsayılarıdır: $\vec v=(4,-2,2)$.

$\overrightarrow{QP}$ ile $\vec v$ arasındaki açı $\theta$ olsun. Uzaklık, dik üçgende "karşı dik kenar"dır:

$$d=|\overrightarrow{QP}|\sin\theta=\frac{|\overrightarrow{QP}\times\vec v|}{|\vec v|} .$$

Hesap (ara adım eklendi):

- $\overrightarrow{QP}\times\vec v=(24,48,0)$, boyu $\sqrt{576+2304}=\sqrt{2880}=24\sqrt5$.
- $|\vec v|=\sqrt{16+4+4}=\sqrt{24}$.
- $d=\dfrac{24\sqrt5}{\sqrt{24}}=\sqrt{120}=2\sqrt{30}$.

Hoca bu sorunun "başka yönlü de" yapılabileceğini, sinüs ya da kosinüs ilişkisiyle çözülebileceğini söyledi. Düzlemde bir noktanın bir doğruya, uzayda bir noktanın bir düzleme uzaklığı için bilinen formülü de hatırlattı:

$$d=\frac{|ax_0+by_0+c|}{\sqrt{a^2+b^2}}\qquad(\text{düzlemde }ax+by+c=0\text{ doğrusu}) .$$

> **Hocanın vurgusu:** Test sınavında zamanla yarışıyorsunuz. Sadece tek bir yöntemle bulmaya çalışmayın. Hangi yöntemi daha iyi anlıyorsanız onunla gidin.

Hoca burada bayramın yaklaştığını ve zamanın az kaldığını, konuları ve soruları günlük olarak "hazmede hazmede" bitirmeyi, bol alıştırma yapmayı önerdi.

> **Ek bilgi (derste anlatılmadı):** $|\overrightarrow{QP}\times\vec v|=|\overrightarrow{QP}|\,|\vec v|\sin\theta$ olduğu için, vektörel çarpımın boyunu $|\vec v|$'ye bölmek doğrudan $|\overrightarrow{QP}|\sin\theta$'yı, yani dik uzaklığı verir. Bu yüzden açıyı ayrıca hesaplamaya gerek kalmaz.

## 5. Yönlü Türev Üzerine Başka Sorular

### 5.1 Örnek 4: Birim Olmayan Yön Vektörü

**Soru.** Bir fonksiyonun $P_0$ noktasında $\vec u=3\vec i+4\vec j$ yönündeki türevini bulunuz.

<!-- BELİRSİZ: Fonksiyon ve P0 noktası altyazıda okunmuyor. Altyazıda yalnız f_x = 2y ve f_y "2x eksi 6..." (büyük olasılıkla 2x-6y) geçiyor; sonuç "eksi 4" olarak duyuluyor. -->

**Çözüm (altyazıdan okunabilen kadar).**

- $x$'e göre kısmi türev $2y$, $y$'ye göre kısmi türev $2x-6y$ olarak yazıldı. Gradyan $\nabla f=2y\,\vec i+(2x-6y)\,\vec j$ biçimindedir ve $P_0$'da hesaplandı.
- $\vec u=(3,4)$ birim değildir, boyu 5'tir. Birim vektör $\vec v=\left(\tfrac35,\tfrac45\right)$.
- $\nabla f(P_0)\cdot\vec v$ hesaplandı; hocanın okuduğu sonuç $-4$'tür.

> **Ders sonrası not:** Gradyan $2y\,\vec i+(2x-6y)\,\vec j$ ise fonksiyon büyük olasılıkla $f(x,y)=2xy-3y^2$'dir. Ders kitaplarında yaygın olan bu alıştırmada nokta $P_0(5,5)$ ve yön $4\vec i+3\vec j$ alınırsa sonuç gerçekten $-4$ çıkar. Aynı nokta için yön $3\vec i+4\vec j$ alınırsa sonuç $-10$ olur. Altyazıda nokta okunmadığı için hangi verinin kullanıldığı kesinleştirilemedi.

### 5.2 Örnek 5: Fonksiyon Verilmeden Yönlü Türev

**Soru.** Bir $f$ fonksiyonunun $P_0$ noktasında $\vec i+\vec j$ yönündeki türevi $2\sqrt2$, $-2\vec j$ yönündeki türevi $-3$'tür. $f$'nin $P_0$'da $-\vec i-2\vec j$ yönündeki türevi nedir?

Hoca bunun "çok güzel", "harika", "profesyonel" bir soru olduğunu, ancak konuyu anlayanların çözebileceğini söyledi. Fonksiyon verilmemiştir, "hayali" bir fonksiyondur. Fonksiyonu bulmamız da istenmez.

**Çözüm.** Gradyanın bileşenlerine isim verilir:

$$\nabla f(P_0)=a\,\vec i+b\,\vec j,\qquad a=f_x(P_0),\ b=f_y(P_0) .$$

İki bilinmeyen olduğu için iki denkleme ihtiyaç vardır. Soru tam olarak iki bilgi veriyor.

Birinci bilgi: $\vec i+\vec j$'nin boyu $\sqrt2$'dir, birim vektör $\tfrac1{\sqrt2}(1,1)$'dir.

$$\frac{a+b}{\sqrt2}=2\sqrt2\ \Rightarrow\ a+b=4 .$$

İkinci bilgi: $-2\vec j$ yönündeki birim vektör $(0,-1)$'dir.

$$a\cdot0+b\cdot(-1)=-3\ \Rightarrow\ b=3 .$$

Buradan $a=1$ bulunur. Yani $\nabla f(P_0)=\vec i+3\vec j$.

İstenen yön $-\vec i-2\vec j$'dir. Boyu $\sqrt{1+4}=\sqrt5$'tir, birim değildir. Birim vektör $\vec v=\left(-\tfrac1{\sqrt5},-\tfrac2{\sqrt5}\right)$'tir. Hoca, bulunan $a$ ve $b$'yi bu vektörle çarpmanın sonucu verdiğini söyledi:

$$D_{\vec v}f(P_0)=\frac{-1-6}{\sqrt5}=-\frac{7}{\sqrt5}\quad(\text{ara adım eklendi}).$$

Derste son değer sözlü olarak okunmadı; sonuç python ile doğrulandı.

Hoca, sınavda bu sorunun doğrudan "i yönündeki türev bu, j yönündeki türev bu, $-\vec i-2\vec j$ yönündeki türev nedir" diye sorulabileceğini söyledi.

Bu sorudan sonra dersin ilk molası verildi (yaklaşık 00:41 ile 00:54 arası).

## 6. Noktanın Düzleme Uzaklığı ve Dik İzdüşüm

### 6.1 Örnek 6: Noktanın Düzleme Uzaklığı

**Soru.** Bir $S$ noktasının $x+2y+2z=13$ düzlemine uzaklığını bulunuz.

<!-- BELİRSİZ: S noktasının koordinatları ve sayısal sonuç altyazıda okunmuyor. -->

**Çözüm (yöntem).**

- Düzlemin normali, değişkenlerin katsayılarıdır: $\vec n=(1,2,2)$.
- Düzlem üzerinde bir nokta: $y=z=0$ alınırsa $x=13$, yani $P(13,0,0)$.
- Uzaklık $d$, $\overrightarrow{PS}$ ile $\vec n$ arasındaki açı $\theta$ olmak üzere, dik üçgende "komşu dik kenar"dır: $d=|\overrightarrow{PS}|\cos\theta$. Bu da $\overrightarrow{PS}$'nin $\vec n$ üzerine izdüşümünün boyudur.

Bu, nokta-düzlem uzaklığı formülüne götürür:

$$d=\frac{|\overrightarrow{PS}\cdot\vec n|}{|\vec n|}=\frac{|x_0+2y_0+2z_0-13|}{\sqrt{1+4+4}}=\frac{|x_0+2y_0+2z_0-13|}{3} .$$

> **Ders sonrası not:** Altyazıda normal vektör bir yerde "1, 2, 4" diye geçiyor. Düzlem denkleminin katsayılarına göre normal $(1,2,2)$'dir.

### 6.2 Dik İzdüşüm

Hoca bir $\vec u$ vektörünün $\vec v$ vektörü üzerine dik izdüşümünü (orthogonal projection) soran bir soruyu kısaca gösterdi ve formülü hatırlattı:

$$\operatorname{proj}_{\vec v}\vec u=\frac{\vec u\cdot\vec v}{|\vec v|^2}\,\vec v .$$

Daha önce bu tip sorular çözüldüğü için verilerin yerine yazılması yeterli dedi.

<!-- BELİRSİZ: İzdüşüm sorusundaki u ve v vektörleri altyazıda okunmuyor. -->

## 7. En Hızlı Artış ve Azalış Yönleri

### 7.1 Örnek 7: İki Değişkenli Fonksiyonda En Hızlı Değişim

**Soru.** Kısa nottaki karelere göre fonksiyon $f(x,y)=x^2y+e^{xy}\sin y$, nokta $P_0(1,0)$'dır. Fonksiyonun $P_0$'da en hızlı arttığı ve en hızlı azaldığı yönleri bulunuz.

**Çözüm.**

- $f_x=2xy+ye^{xy}\sin y$, $P_0$'da $0$.
- $f_y=x^2+xe^{xy}\sin y+e^{xy}\cos y$, $P_0$'da $1+0+1=2$.
- $\nabla f(P_0)=2\vec j$ (ara adım eklendi).

En hızlı artış gradyan yönündedir; birim vektör $\vec u=\vec j$. En hızlı azalış tersi yöndedir: $\vec u=-\vec j$. Altyazıda hoca yalnız bu iki yönü ("$j$ yönde", "eksi $j$ yönde") söyledi.

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor; kısa nottaki ifadeyle verildi. Gradyanın değeri ve yönler bu fonksiyonla tutarlıdır. -->

Hoca bu tip soruları artık kavradığımızı, ama sınavda farklı farklı biçimlerde "habire" geldiğini söyledi.

### 7.2 Örnek 8: Üç Değişkenli Fonksiyonda Yönlü Türev

**Soru.** Bir $f(x,y,z)$ fonksiyonunun $P(1,-1,2)$ noktasında $\vec u=3\vec i+6\vec j-2\vec k$ yönündeki türevini bulunuz.

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor. P noktasında gradyan (1, 3, 0) olarak geçiyor. -->

**Çözüm.** Üç değişkende de yöntem aynıdır.

- İlk kontrol: $\vec u$ birim mi? $|\vec u|=\sqrt{9+36+4}=\sqrt{49}=7$. Birim değildir.
- Birim vektör: $\vec v=\left(\tfrac37,\tfrac67,-\tfrac27\right)$.
- Kısmi türevler alınıp $P$ noktası ($x=1$, $y=-1$, $z=2$) yerine yazılınca $\nabla f(P)=(1,3,0)$ bulundu.
- $D_{\vec v}f(P)=1\cdot\tfrac37+3\cdot\tfrac67+0\cdot\left(-\tfrac27\right)=\tfrac{21}{7}=3$.

Hoca birinci ile birinciyi, ikinci ile ikinciyi, üçüncü ile üçüncüyü çarpıp toplamayı vurguladı.

> **Ders sonrası not:** Hoca birim vektörün üçüncü bileşenini bir yerde "$2/7$" diye okudu; doğrusu $-\tfrac27$'dir. Gradyanın üçüncü bileşeni $0$ olduğu için sonuç değişmez, $3$'tür.

### 7.3 Örnek 9: Üç Değişkenli Sınav Sorusu

**Soru.** Kısa nottaki karelere göre $f(x,y,z)=\dfrac{x}{y}-yz$ ve $P(4,1,1)$. Fonksiyon $P$'de hangi yönlerde en hızlı değişir? Bu yönlerdeki değişim hızları nelerdir?

Hoca bu sorunun sınavda çıktığını söyledi.

**Çözüm.**

- $f_x=\dfrac1y=1$.
- $f_y=-\dfrac{x}{y^2}-z=-4-1=-5$.
- $f_z=-y=-1$.
- $\nabla f(P)=\vec i-5\vec j-\vec k$ (ara adım eklendi).
- $|\nabla f(P)|=\sqrt{1+25+1}=\sqrt{27}=3\sqrt3$.

Fonksiyon $\vec i-5\vec j-\vec k$ yönünde en hızlı artar, hız $3\sqrt3$'tür. $-(\vec i-5\vec j-\vec k)$ yönünde en hızlı azalır, hız $-3\sqrt3$'tür.

<!-- BELİRSİZ: Altyazıda gradyanın boyu "143" gibi bozuk duyuluyor; hesap 3√3 verir. -->

### 7.4 Gradyan ile Gradyanın Boyu Arasındaki Fark

Hoca sınavda şöyle bir tuzak şık gelebileceğini söyledi: "En büyük değeri $\nabla f$'de, en küçük değeri $-\nabla f$'de alır." Bu ifade yanlıştır, çünkü değer bir sayıdır, $\nabla f$ ise bir vektördür. Doğrusu, en büyük değer $|\nabla f|$, en küçük değer $-|\nabla f|$'dir.

- $\nabla f=f_x\,\vec i+f_y\,\vec j+f_z\,\vec k=(f_x,f_y,f_z)$ bir vektördür, yönü verir.
- $|\nabla f|=\sqrt{f_x^2+f_y^2+f_z^2}$ bir sayıdır, en büyük değişim hızını verir.
- İkisi de $P$ noktasında hesaplanır.

> **Hocanın vurgusu:** Gradyan ile gradyanın boyu arasındaki farka dikkat edin. Değer sorulduğunda mutlak değer (boy) almak "mecburiyetindeyiz".

## 8. Kısmi Türevin Tanımla Hesabı

### 8.1 Örnek 10: Küp Köklü Fonksiyon

**Soru.** Küp köklü bir fonksiyonun $(0,0)$'daki kısmi türevleri için aşağıdakilerden hangisi doğrudur?

<!-- BELİRSİZ: Fonksiyon altyazıda "küp kök x üzeri 4 artı y kare" diye geçiyor; büyük olasılıkla f(x,y) = (x^4 + y^2)^(1/3). -->

Fonksiyon $f(x,y)=\sqrt[3]{x^4+y^2}$ alınırsa:

**Birinci yol: türev formülüyle.** $x$'e göre türev alırken $y$ sabit, 3 ya da 5 gibi bir sayı gibi düşünülür. Kuvvet biçiminde yazılır:

$$f_x=\frac13\,(x^4+y^2)^{-2/3}\cdot4x^3=\frac{4x^3}{3\,\sqrt[3]{(x^4+y^2)^2}} .$$

Hoca, $(0,0)$'a yaklaşıldığında bunun $0$'a gittiğini söyledi. $y$'ye göre türevde ise:

$$f_y=\frac{2y}{3\,\sqrt[3]{(x^4+y^2)^2}}$$

ve hoca, sıfır paydaya düştüğü için $y$'ye göre türevin olmadığını söyledi.

**İkinci yol: tanımla.** Hoca bunun "çok kolay" olduğunu söyledi:

$$f_x(0,0)=\lim_{h\to0}\frac{f(h,0)-f(0,0)}{h}=\lim_{h\to0}\frac{h^{4/3}}{h}=\lim_{h\to0}h^{1/3}=0 .$$

$$f_y(0,0)=\lim_{k\to0}\frac{f(0,k)-f(0,0)}{k}=\lim_{k\to0}\frac{k^{2/3}}{k}=\lim_{k\to0}k^{-1/3} .$$

Bu son limit yoktur: $k\to0^+$ için $+\infty$, $k\to0^-$ için $-\infty$'a gider.

**Sonuç.** $f_x(0,0)=0$, $f_y(0,0)$ yoktur.

Hoca, fonksiyon parçalı tanımlı olmadığı için iki yoldan hangisi daha hızlıysa onun kullanılabileceğini söyledi.

> **Ders sonrası not:** $(0,0)$'da türev formülü $\tfrac00$ biçimine düşer; bu noktada formülün "paydası sıfır" diye tanımsız çıkması tek başına türevin yokluğunu kanıtlamaz. Kesin karar tanımdaki limitle verilir. Bu soruda iki yol da aynı sonuca götürür.

> **Ek bilgi (derste anlatılmadı):** Türev kuralları, fonksiyonun o noktanın çevresinde türevlenebilir olduğu durumda geçerlidir. Kökün içi sıfır olduğunda kuralların verdiği ifade tanımsız kalabilir. Bu durumda kısmi türev, tanımdaki $\lim\limits_{h\to0}\frac{f(x_0+h,y_0)-f(x_0,y_0)}{h}$ limitiyle hesaplanır.

## 9. Kuvvet Serisinin Yakınsaklık Yarıçapı

### 9.1 Örnek 11: Yarıçap Verilmiş, Sabit İsteniyor

**Soru.** $\displaystyle\sum_{n=2}^{\infty}\frac{b^n x^n}{\ln n}$ serisinin yakınsaklık yarıçapının $3$ olması için $b$ sabitinin alacağı değerleri bulunuz. (Şıklı soruda "değerler toplamı" da sorulabilir.)

Hoca, serinin $n=2$'den başladığına dikkat çekti: $n=1$'de $\ln 1=0$ paydaya düşer, soru anlamsız olur.

**Çözüm.** Genel terim $a_n=\dfrac{b^nx^n}{\ln n}$ olsun. Oran testi kullanılır; limit $1$'den küçükse seri yakınsaktır:

$$\lim_{n\to\infty}\left|\frac{a_{n+1}}{a_n}\right|=\lim_{n\to\infty}\left|\frac{b^{n+1}x^{n+1}}{\ln(n+1)}\cdot\frac{\ln n}{b^nx^n}\right|=|b|\,|x|\lim_{n\to\infty}\frac{\ln n}{\ln(n+1)}=|b|\,|x|<1 .$$

Sadeleştirmede $b^n$, $x^n$ gider; $\dfrac{\ln n}{\ln(n+1)}$ oranı $1$'e gider. Buradan:

$$|x|<\frac1{|b|}\ \Rightarrow\ R=\frac1{|b|}=3\ \Rightarrow\ b=\pm\frac13 .$$

$b$'nin alacağı değerler $-\tfrac13$ ve $\tfrac13$'tür. "Değerler toplamı" sorulursa cevap $0$'dır.

## 10. Seviye Eğrisi, Teğet Vektör ve Gradyan

### 10.1 Örnek 12: Teğet Vektör Gradyana Diktir

**Soru.** $f(x,y)=xy$, $x>0$, $y>0$ olarak tanımlanıyor. $f(x,y)=1$ seviye eğrisi $x=t$ ile parametrize ediliyor. Bu parametrizasyonla $t=2$'ye karşılık gelen noktada seviye eğrisinin teğet vektörünün gradyan vektörüne dik olduğunu gösteriniz.

Hoca şıklı soruda doğru cevabın "diktir" olduğunu, ama bunun yaparak bulunması gerektiğini söyledi.

**Çözüm.**

- Seviye eğrisi: $xy=1$. $x=t$ yazılınca $ty=1$, yani $y=\dfrac1t$.
- Eğri: $\vec r(t)=t\,\vec i+\dfrac1t\,\vec j$.
- Teğet vektör, eğrinin $t$'ye göre türevidir: $\vec r\,'(t)=\vec i-\dfrac1{t^2}\,\vec j$.
- $t=2$'de: $\vec r\,'(2)=\vec i-\tfrac14\,\vec j$. Nokta $\left(2,\tfrac12\right)$.
- Gradyan: $\nabla f=y\,\vec i+x\,\vec j$, bu noktada $\nabla f=\tfrac12\,\vec i+2\,\vec j$.
- Skaler çarpım: $1\cdot\tfrac12+\left(-\tfrac14\right)\cdot2=\tfrac12-\tfrac12=0$.

Skaler çarpım sıfır olduğu için seviye eğrisinin teğet vektörü ile gradyan vektörü birbirine diktir.

## 11. Bir Kesişim Eğrisinin Eğimi

### 11.1 Örnek 13: Düzlem ile Paraboloidin Kesişimi

**Soru.** Kısa nottaki kareye göre: $x=1$ düzlemi, $z=x^2+y^2$ paraboloidini bir parabolde keser. Parabolün $(1,2,5)$ noktasındaki teğetinin eğimini bulunuz.

Hoca önce "$x=1$"in ne olduğunu hatırlattı. İki boyutta $x=1$, $y$ eksenine paralel bir doğrudur. Üç boyutta ise $x$ eksenini $1$'de kesen bir **düzlemdir**, doğru değildir.

**Çözüm.** $x$ sabitlendiği için kesişim eğrisi boyunca yalnız $y$ değişir. Teğetin eğimi $z$'nin $y$'ye göre kısmi türevidir:

$$\frac{\partial z}{\partial y}=2y,\qquad (1,2,5)\text{'te } m=2\cdot2=4 .$$

Hoca bunun "çok basit ama önemli" bir bilgi olduğunu söyledi: $x$'i sabitleyince türev $y$'ye göre alınır ve noktaya konur.

## 12. Uzay Eğrileri: Teğet Doğru, Yay Uzunluğu, Açı

### 12.1 Teğet Doğrunun Parametrik Denklemi

Bir uzay eğrisi $\vec r(t)$ ile verilmişse, $t_0$'daki teğet doğru şöyle yazılır:

- Nokta: $\vec r(t_0)=(x_0,y_0,z_0)$.
- Doğrultman: $\vec r\,'(t_0)=(a,b,c)$.
- Parametrik denklemler: $x=x_0+at,\quad y=y_0+bt,\quad z=z_0+ct$.
- Simetrik biçim: $\dfrac{x-x_0}{a}=\dfrac{y-y_0}{b}=\dfrac{z-z_0}{c}=t$.

Hoca $a$, $b$, $c$'nin bileşen fonksiyonların türevleri olduğunu söyledi.

### 12.2 Örnek 14: Trigonometrik ve Üstel Bileşenli Eğri

**Soru.** $\vec r(t)=\sin t\,\vec i+(t^2-\cos t)\,\vec j+e^t\,\vec k$ eğrisinin $t=0$'daki teğet doğrusunun parametrik denklemleri nedir?

**Çözüm.**

- $\vec r\,'(t)=\cos t\,\vec i+(2t+\sin t)\,\vec j+e^t\,\vec k$.
- $\vec r\,'(0)=(1,0,1)$.
- $\vec r(0)=(\sin0,\;0-\cos0,\;e^0)=(0,-1,1)$.
- Teğet doğru: $x=t,\quad y=-1,\quad z=1+t$.

### 12.3 Örnek 15: Logaritmik Bileşenli Eğri

**Soru.** $\vec r(t)=\ln t\,\vec i+\dfrac{t-1}{t+2}\,\vec j+t\ln t\,\vec k$ eğrisinin $t=1$'deki teğet doğrusunu bulunuz.

**Çözüm.**

- $\vec r\,'(t)=\dfrac1t\,\vec i+\dfrac{3}{(t+2)^2}\,\vec j+(\ln t+1)\,\vec k$.
- $\vec r\,'(1)=\left(1,\tfrac13,1\right)$.
- $\vec r(1)=(0,0,0)$.
- Teğet doğru: $x=t,\quad y=\dfrac t3,\quad z=t$.

Bu sorudan sonra ikinci mola verildi (yaklaşık 01:30 ile 01:47 arası). Hoca moladan önce sınavlarda eğri uzunluğu ve alan sorularının sık geldiğini, 2017 yılındaki soruların benzerlerinin tekrar tekrar sorulabildiğini söyledi.

### 12.4 Örnek 16: Yay Uzunluğu (2017 Sınav Sorusu)

**Soru.** $\vec r(t)=(1+t^2)^{3/2}\,\vec i+(3-t^2)^{3/2}\,\vec j+4t^2\,\vec k$ eğrisinin $-1\le t\le1$ aralığında kalan kısmının yay uzunluğunu belirli integralle hesaplayınız.

Yay uzunluğu (arc length), eğrinin türevinin normunun integralidir:

$$s=\int_a^b|\vec r\,'(t)|\,dt .$$

Hoca bunun "bu kadar basit" olduğunu, ama türev alırken ve değerleri koyarken hata yapmamak gerektiğini söyledi.

**Çözüm.**

- $\vec r\,'(t)=\left(3t\sqrt{1+t^2},\;-3t\sqrt{3-t^2},\;8t\right)$.
- $|\vec r\,'(t)|^2=9t^2(1+t^2)+9t^2(3-t^2)+64t^2=9t^2+27t^2+64t^2=100t^2$ (ara adım eklendi).
- $|\vec r\,'(t)|=10|t|$.
- $s=\displaystyle\int_{-1}^{1}10|t|\,dt=10\int_{-1}^{0}(-t)\,dt+10\int_0^1t\,dt=5+5=10$ birim.

> **Ders sonrası not:** Altyazıda hoca sonucu "on bir" diye okuyor. Doğru sonuç $10$ birimdir.

### 12.5 Örnek 17: Konum ile İvme Arasındaki Açı (Sınav Sorusu)

**Soru.** Uzayda zamana bağlı hareket eden bir cismin konum fonksiyonu $\vec r(t)=\cos t\,\vec i+\sin t\,\vec j+\sqrt3\,t\,\vec k$'dir. Cismin konum fonksiyonu ile ivmesi arasındaki açı ne zaman $\tfrac{2\pi}{3}$ olur?

Hoca bunun "çok güzel bir soru" olduğunu söyledi ve tahtada yeniden çözdü.

**Çözüm.** Birinci türev hız (teğet) vektörünü, ikinci türev ivme vektörünü verir:

- $\vec r\,'(t)=-\sin t\,\vec i+\cos t\,\vec j+\sqrt3\,\vec k$.
- $\vec a(t)=\vec r\,''(t)=-\cos t\,\vec i-\sin t\,\vec j+0\,\vec k$.

İki vektör arasındaki açı skaler çarpımla bulunur:

$$\vec r\cdot\vec a=|\vec r|\,|\vec a|\cos\theta .$$

- $\vec r\cdot\vec a=-\cos^2t-\sin^2t+0=-1$.
- $|\vec r|=\sqrt{\cos^2t+\sin^2t+3t^2}=\sqrt{1+3t^2}$.
- $|\vec a|=\sqrt{\cos^2t+\sin^2t}=1$.

$\theta=\tfrac{2\pi}{3}$ için $\cos\theta=-\tfrac12$:

$$-\frac12=\frac{-1}{\sqrt{1+3t^2}}\ \Rightarrow\ \sqrt{1+3t^2}=2\ \Rightarrow\ 3t^2=3\ \Rightarrow\ t=\pm1 .$$

> **Ders sonrası not:** Hoca açı formülünü anlatırken vektörlere "$\vec u$" ve "$\vec v$" dedi ve önce birinci türevi (teğet vektörü) de buldu. Soru konum ile ivme arasındaki açıyı istediği için hesapta $\vec r\,'$ değil, konum vektörü $\vec r(t)$ kullanılır; yukarıdaki hesap budur.

## 13. Tanım Kümesi

### 13.1 Örnek 18: Ark Kosinüs ve Logaritma

**Soru.** $f(x,y)=\arccos\left(\dfrac{y}{x^2}\right)+\ln(1-x^2)$ fonksiyonunun tanım kümesini bulunuz ve şeklini çiziniz.

**Çözüm.** İki terimin de tanımlı olması gerekir.

Ark kosinüs terimi: $z=\arccos\left(\dfrac{y}{x^2}\right)$ dersek $\cos z=\dfrac{y}{x^2}$ olur. Kosinüs $[-1,1]$ aralığında değer aldığı için:

$$-1\le\frac{y}{x^2}\le1,\qquad x\ne0\ \Rightarrow\ -x^2\le y\le x^2 .$$

Yani bölge $y=-x^2$ ve $y=x^2$ parabollerinin arasıdır. $x=0$ kesirde paydayı sıfır yaptığı için dışarıda bırakılır.

Logaritma terimi: $\ln$ yalnız pozitif sayılarda tanımlıdır:

$$1-x^2>0\ \Rightarrow\ x^2<1\ \Rightarrow\ -1<x<1 .$$

Tanım kümesi:

$$D=\{(x,y):\ 0<|x|<1,\ -x^2\le y\le x^2\} .$$

Çizimde iki parabol arasındaki bölge, $x=-1$ ile $x=1$ doğruları arasında kalan kısımla sınırlanır. Bu doğrularda eşitlik olmadığı için $x=\pm1$ doğruları kesikli çizilir.

<!-- BELİRSİZ: 02:03:06 civarında hoca ekrandaki çözümde bir yerde "kosinüs" ve "sinüs" yazıldığını, bunların aralığının [-1, 1] olduğunu söylüyor; tam ne düzeltildiği altyazıda anlaşılmıyor. -->

## 14. Çok Değişkenli Fonksiyonlarda Limit

> **Hocanın vurgusu:** Limit ve süreklilik sorusu "olmazsa olmaz". Hem vizede hem finalde mutlaka soru var, "banko".

### 14.1 Örnek 19: Köklü İfade, Eşlenikle Çarpma (Sınav Sorusu)

**Soru.** $\displaystyle\lim_{(x,y)\to(1,1)}\frac{\sqrt{1+3x^2y^2}-2}{xy-1}$ limitini hesaplayınız.

**Çözüm.** $x=1$, $y=1$ yazılınca $\tfrac00$ belirsizliği çıkar. İfadede kök olduğu için, tek değişkenli fonksiyonlarda olduğu gibi eşlenikle çarpılır:

$$\frac{\sqrt{1+3x^2y^2}-2}{xy-1}\cdot\frac{\sqrt{1+3x^2y^2}+2}{\sqrt{1+3x^2y^2}+2}=\frac{3(x^2y^2-1)}{(xy-1)\left(\sqrt{1+3x^2y^2}+2\right)} .$$

$x^2y^2-1=(xy-1)(xy+1)$ olduğundan $xy\ne1$ için sadeleşir (ara adım eklendi):

$$\lim_{(x,y)\to(1,1)}\frac{3(xy+1)}{\sqrt{1+3x^2y^2}+2}=\frac{3\cdot2}{2+2}=\frac32 .$$

Hoca bu sorunun "komplike değil", çok basit olduğunu söyledi.

### 14.2 Örnek 20: Yola Bağlı Limit, Limit Yok

**Soru.** $(x,y)\to(0,0)$ için kökü olmayan bir kesirli ifadenin limiti soruluyor.

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor. -->

**Çözüm (yöntem).** $(0,0)$ yazılınca $\tfrac00$ belirsizliği çıkar. Hoca yöntemi şöyle anlattı:

- Önce eksenler boyunca yaklaşılır: $x$ ekseni ($y=0$) ve $y$ ekseni ($x=0$). Sonuçlar farklıysa limit yoktur.
- Sonuçlar aynıysa başka yollar denenir: $y=mx$ ya da $y=mx^2$ doğrultuları. Sonuç $m$'ye bağlı çıkıyorsa, $m$ yerine $2$, $3$, $4$ konunca farklı değerler elde edileceği için limit yoktur.

Bu soruda $y=mx$ ile yaklaşınca sonuç $m$'ye bağlı çıktı. Ekrandaki çözümde ayrıca $x$ ekseni boyunca bir değer ($0$'a giden), $y=x$ doğrusu boyunca ise $\tfrac12$ bulunmuş; farklı oldukları için de limit yoktur.

Hoca, sonucu yol yol karşılaştırmak yerine $y=mx$ ya da $y=mx^2$ ile bakmanın daha kestirme olduğunu söyledi. Hangisinin kullanılacağı fonksiyonun yapısına göre değişir; bazı sorularda $y=mx^3$ bile gerekebilir. Kutupsal koordinatlara geçmek de bir yöntemdir.

> **Ek bilgi (derste anlatılmadı):** Farklı iki yolda farklı limit bulmak, limitin olmadığını kesin olarak gösterir. Tersi doğru değildir: Denenen bütün yollarda aynı değerin çıkması limitin var olduğunu kanıtlamaz. Varlığı göstermek için kutupsal koordinat ya da sıkıştırma gibi bir sınırlama gerekir.

## 15. Kısmi Türevin Tanımla Hesabı: İkinci Örnek

### 15.1 Örnek 21: $f(x,y)=\sin\sqrt{x^2+y^4}$

**Soru (sınav sorusu).** $f(x,y)=\sin\sqrt{x^2+y^4}$ fonksiyonunun $(0,0)$ noktasındaki kısmi türevlerini tanımdan bulunuz.

Hoca ekrandaki çözümü kapatıp tahtada yeniden çözdü ve "çok önemli, güzel bir soru" dedi.

**$x$'e göre kısmi türev.**

$$f_x(0,0)=\lim_{h\to0}\frac{f(0+h,0)-f(0,0)}{h}=\lim_{h\to0}\frac{\sin\sqrt{h^2}-0}{h}=\lim_{h\to0}\frac{\sin|h|}{h} .$$

$\sqrt{h^2}=|h|$'dir. $h$ pozitif de olabilir, negatif de:

- $h\to0^+$: $\dfrac{\sin h}{h}\to1$.
- $h\to0^-$: $\dfrac{\sin(-h)}{h}\to-1$.

Sağ ve sol limitler farklı olduğu için $f_x(0,0)$ yoktur.

> **Ders sonrası not:** Hoca bir yerde "sağdan yaklaşınca $-1$, soldan yaklaşınca $+1$" dedi. Doğrusu tersidir: sağdan $+1$, soldan $-1$. Sonuç aynıdır, $f_x(0,0)$ yoktur.

**$y$'ye göre kısmi türev.** Bu kez kök içinde $y^4$ olduğu için "iş değişiyor":

$$f_y(0,0)=\lim_{k\to0}\frac{f(0,k)-f(0,0)}{k}=\lim_{k\to0}\frac{\sin\sqrt{k^4}}{k}=\lim_{k\to0}\frac{\sin(k^2)}{k} .$$

$\sqrt{k^4}=k^2$'dir, işaret sorunu yoktur. Hoca pay ve paydayı $k$ ile genişletti:

$$\frac{\sin(k^2)}{k}=k\cdot\frac{\sin(k^2)}{k^2}\ \longrightarrow\ 0\cdot1=0 .$$

**Sonuç.** $f_y(0,0)=0$ vardır; $f_x(0,0)$ yoktur.

## 16. Kapalı Fonksiyon Sorusuna Giriş

Dersin sonunda hoca kısmi türevleri mevcut, sabit olmayan bir fonksiyonla kurulmuş bir denklemin "alacağı şekli" soran bir soruya başladı. Şıklarda sonucun $x$, $y$, $z$ ve $z$'nin kısmi türevleri arasında sıfıra eşit bir bağıntı ya da bunun bir tarafa geçirilmiş biçimi olarak verilebileceğini söyledi.

<!-- BELİRSİZ: Sorunun fonksiyonu ve elde edilen bağıntı altyazıda okunmuyor ("x y çarpı z'nin ... kısmi türevi artı ... eşit sıfır" gibi bozuk geçiyor). -->

Hoca, $z$'nin $x$ ve $y$'ye bağlı olduğu bu tarzdaki soruları ertesi gün çözeceklerini söyleyerek dersi bitirdi.

## Örnek Sorular

Bu dersin tamamı soru çözümüdür. Aşağıda, derste ekranda gösterilip sözlü okunan soruların listesi kısa cevaplarıyla verilmiştir. Ayrıntılı çözümler yukarıdaki bölümlerdedir.

- **Soru 1** (derste sözlü, 00:03:54). $f(x,y)=x^2-xy+y^2-y$, $P(1,-1)$. $D_{\vec u}f(P)$'nin en büyük, en küçük ve sıfır olduğu yönler ve değerler.
  - Cevap: en büyük $5$, yön $\left(\tfrac35,-\tfrac45\right)$; en küçük $-5$, yön $\left(-\tfrac35,\tfrac45\right)$; sıfır olduğu yönler $\pm\left(\tfrac45,\tfrac35\right)$.
- **Soru 2** (derste sözlü, 00:22:36). $L_1:\ x=-1+t,\ y=2+t,\ z=1-t$ ve $L_2:\ x=1-4s,\ y=1+2s,\ z=2-2s$ doğrularının belirlediği düzlem.
  - Cevap: $y+z=3$.
- **Soru 3** (derste sözlü, 00:30:14). $P(0,0,12)$ noktasının $x=4t,\ y=-2t,\ z=2t$ doğrusuna uzaklığı.
  - Cevap: $2\sqrt{30}$.
- **Soru 4** (derste sözlü, 00:34:15). Bir fonksiyonun $P_0$'da $3\vec i+4\vec j$ yönündeki türevi. <!-- BELİRSİZ: fonksiyon ve nokta okunmuyor -->
  - Hocanın okuduğu cevap: $-4$.
- **Soru 5** (derste sözlü, 00:36:13). $P_0$'da $\vec i+\vec j$ yönündeki türev $2\sqrt2$, $-2\vec j$ yönündeki türev $-3$. $-\vec i-2\vec j$ yönündeki türev?
  - Cevap: $\nabla f(P_0)=\vec i+3\vec j$, türev $-\tfrac{7}{\sqrt5}$.

> **Çözüm (derste verilmedi):** Soru 5'in son değeri derste sözlü okunmadı. $\nabla f(P_0)\cdot\left(-\tfrac1{\sqrt5},-\tfrac2{\sqrt5}\right)=\tfrac{-1-6}{\sqrt5}=-\tfrac{7}{\sqrt5}=-\tfrac{7\sqrt5}{5}$; python ile doğrulandı.

- **Soru 6** (derste sözlü, 00:55:47). Bir $S$ noktasının $x+2y+2z=13$ düzlemine uzaklığı. <!-- BELİRSİZ: S noktası okunmuyor -->
  - Yöntem: $d=\dfrac{|x_0+2y_0+2z_0-13|}{3}$.
- **Soru 7** (derste sözlü, 00:59:44). $P(1,-1,2)$'de $\nabla f=(1,3,0)$; $3\vec i+6\vec j-2\vec k$ yönündeki türev.
  - Cevap: $3$.
- **Soru 8** (derste sözlü, 01:03:08). $f(x,y,z)=\tfrac xy-yz$, $P(4,1,1)$: en hızlı değişim yönleri ve hızları.
  - Cevap: $\vec i-5\vec j-\vec k$ yönünde artış, hız $3\sqrt3$; ters yönde azalış, hız $-3\sqrt3$.
- **Soru 9** (derste sözlü, 01:07:18). $f=\sqrt[3]{x^4+y^2}$ için $(0,0)$'daki kısmi türevler. <!-- BELİRSİZ: fonksiyon altyazıdan büyük olasılıkla böyle -->
  - Cevap: $f_x(0,0)=0$, $f_y(0,0)$ yok.
- **Soru 10** (derste sözlü, 01:13:26). $\sum_{n\ge2}\dfrac{b^nx^n}{\ln n}$ serisinin yakınsaklık yarıçapı $3$ ise $b$ değerleri ve toplamları.
  - Cevap: $b=\pm\tfrac13$, toplam $0$.
- **Soru 11** (derste sözlü, 01:19:11). $f=xy$'nin $f=1$ seviye eğrisi, $x=t$; $t=2$'de teğet vektör gradyana dik mi?
  - Cevap: $\left(1,-\tfrac14\right)\cdot\left(\tfrac12,2\right)=0$, diktir.
- **Soru 12** (derste sözlü, 01:23:12). $x=1$ düzlemi ile $z=x^2+y^2$ paraboloidinin kesişim parabolünün $(1,2,5)$'teki teğetinin eğimi.
  - Cevap: $4$.
- **Soru 13** (derste sözlü, 01:25:38). $\vec r(t)=\sin t\,\vec i+(t^2-\cos t)\,\vec j+e^t\,\vec k$, $t=0$'daki teğet doğru.
  - Cevap: $x=t,\ y=-1,\ z=1+t$.
- **Soru 14** (derste sözlü, 01:28:18). $\vec r(t)=\ln t\,\vec i+\tfrac{t-1}{t+2}\,\vec j+t\ln t\,\vec k$, $t=1$'deki teğet doğru.
  - Cevap: $x=t,\ y=\tfrac t3,\ z=t$.
- **Soru 15** (derste sözlü, 01:48:44). $\vec r(t)=(1+t^2)^{3/2}\,\vec i+(3-t^2)^{3/2}\,\vec j+4t^2\,\vec k$, $-1\le t\le1$ yay uzunluğu.
  - Cevap: $10$ birim.
- **Soru 16** (derste sözlü, 01:50:30). $\vec r(t)=\cos t\,\vec i+\sin t\,\vec j+\sqrt3\,t\,\vec k$; konum ile ivme arasındaki açı ne zaman $\tfrac{2\pi}{3}$?
  - Cevap: $t=\pm1$.
- **Soru 17** (derste sözlü, 01:57:46). $f(x,y)=\arccos\left(\tfrac{y}{x^2}\right)+\ln(1-x^2)$'nin tanım kümesi.
  - Cevap: $\{(x,y):\ 0<|x|<1,\ -x^2\le y\le x^2\}$.
- **Soru 18** (derste sözlü, 02:03:36). $\displaystyle\lim_{(x,y)\to(1,1)}\frac{\sqrt{1+3x^2y^2}-2}{xy-1}$.
  - Cevap: $\tfrac32$.
- **Soru 19** (derste sözlü, 02:04:28). $(0,0)$'da $\tfrac00$ belirsizliği olan kesirli bir limit. <!-- BELİRSİZ: fonksiyon okunmuyor -->
  - Cevap: $y=mx$ yolunda sonuç $m$'ye bağlı; limit yok.
- **Soru 20** (derste sözlü, 02:07:05). $f(x,y)=\sin\sqrt{x^2+y^4}$'ün $(0,0)$'daki kısmi türevleri.
  - Cevap: $f_x(0,0)$ yok, $f_y(0,0)=0$.

## Dersin Toparlaması

Bu ders, integrale geçmeden önce çok değişkenli fonksiyonlar, vektörler ve uzay eğrileri üzerine sınav tipi soru çözümüne ayrıldı. Yönlü türevde ana fikir $D_{\vec u}f=\nabla f\cdot\vec u=|\nabla f|\cos\theta$ formülüdür: $\vec u$ birim olmalı, en büyük değer $|\nabla f|$, en küçük değer $-|\nabla f|$, sıfır değer gradyana dik yönlerdedir. Gradyan bir vektördür ve yönü verir; boyu bir sayıdır ve en büyük değişim hızını verir. Doğru ve düzlem sorularında normal vektör vektörel çarpımla, uzaklıklar ise vektörel çarpım ya da izdüşümle bulunur. Uzay eğrilerinde teğet doğru $\vec r(t_0)$ ve $\vec r\,'(t_0)$ ile kurulur, yay uzunluğu $\int|\vec r\,'(t)|\,dt$ ile hesaplanır.

Kısmi türevin bir noktada türev formülüyle bulunamadığı durumlarda tanımdaki limite dönülür; $\sqrt{h^2}=|h|$ gibi ifadelerde sağ ve sol limitlere ayrı bakılır. Çok değişkenli limitte belirsizlik köklü ifadelerde eşlenikle giderilir; limitin yokluğu ise eksenler ve $y=mx$, $y=mx^2$ gibi yollarla gösterilir. Hoca, kapalı fonksiyonlarla ilgili yarım kalan soruyu ve benzerlerini bir sonraki derste çözeceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
