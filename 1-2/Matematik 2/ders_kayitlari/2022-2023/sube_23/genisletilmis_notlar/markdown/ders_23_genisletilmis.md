# Ders 23 Genişletilmiş Notu: Final Hazırlığı: Kuvvet Serileri, Kutupsal Alan, Yönlü Türev ve Çok Katlı İntegral Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Final Öncesi Soru Çözümü
- 2. Kuvvet Serisinin Yakınsaklık Aralığı
- 3. Serilerin Karakteri: Karşılaştırma ve İntegral Testi
- 4. Geometrik Seriden Arctan x'in Kuvvet Serisi
- 5. Kutupsal Koordinatlarda Bölge ve Alan
- 6. Parametrik ve Kapalı Tanımlı Eğride Teğet Eğimi
- 7. Yönlü Türev ve Uç Değerleri
- 8. İki Doğrunun Belirlediği Düzlem
- 9. Tanımla Kısmi Türev
- 10. Yakınsaklık Yarıçapından Parametre Bulma
- 11. Vektör Fonksiyonları: Yay Uzunluğu ve Konum-İvme Açısı
- 12. Tanım Kümesi, Limit ve Zincir Kuralı
- 13. Kapalı Fonksiyonlarda Kısmi Türev
- 14. Kutupsal Koordinatlarla İki Katlı İntegral
- 15. İntegrasyon Sırasını Değiştirme
- 16. Jacobian ile Bölge Dönüşümü
- 17. Örnek Sorular

## 1. Dersin Amacı: Final Öncesi Soru Çözümü

Konular bir önceki derslerde bitmişti. Hoca bu dersi tamamen final hazırlığına ayırdı. Ekranda geçmiş yıllarda çıkmış sınav sorularını ve uygulama föyündeki soruları paylaştı, sonra boş bir tahtada kendi kurduğu integral sorularını çözdü.

Hoca derse, sorunun "nasıl sorulabileceği" üzerinde durarak başladı. Aynı içerik klasik soru olarak da, test olarak da gelebilir: "aralığı bulunuz", "aşağıdakilerden hangileri doğrudur", "bu alanı veren integral hangisidir", "hangi adımlar izlenmelidir" gibi. Bu yüzden her soruda yalnız sonucu değil, sonucun arkasındaki mantığı kurmak gerekir.

> **Hocanın vurgusu:** Buradaki her sorunun ardında bir bilgi, bir tecrübe yatıyor. Mantığını anlarsanız soruyu kaçırma şansınız yok.

Ders iki molayla üç bölüme ayrıldı. Molalar 00:34:21-00:47:29 ve 01:29:01-01:39:06 arasındadır.

## 2. Kuvvet Serisinin Yakınsaklık Aralığı

### 2.1 Soru

Ekranda bir kuvvet serisi verildi. Hoca bunun daha önce sınavda çıkmış bir soru olduğunu söyledi. Serinin hangi $x$ değerleri için mutlak yakınsak, şartlı yakınsak (conditionally convergent) ya da ıraksak olduğu soruluyor. Altyazıdaki sözlü anlatıma göre seri şudur:

$$\sum_{n=1}^{\infty}(-1)^n\frac{(x-3)^n}{2^n\sqrt[3]{n^2+5}}$$

<!-- BELİRSİZ: Serinin tam yazımı altyazıda ekranda; (x-3)^n, 2^n, küp kök n kare artı 5 ve (-1)^n parçaları sözlü anlatımdan çıkıyor. -->

Hoca test sürümünü de örnekledi: A şıkkı "şu aralıkta mutlak yakınsaktır", B şıkkı "şu noktada şartlı yakınsaktır", C şıkkı "şu aralık dışında ıraksaktır" gibi ifadeler verilip hangilerinin doğru olduğu sorulabilir.

### 2.2 Oran testi

Toplamın içindeki ifadenin tamamına $u_n$ denir. Oran testinde (ratio test) $n$ gördüğümüz yere $n+1$ yazıp $\left|\dfrac{u_{n+1}}{u_n}\right|$ oranının limiti alınır. Bu limit $1$'den küçükse seri mutlak yakınsaktır.

$$\lim_{n\to\infty}\left|\frac{u_{n+1}}{u_n}\right|=\lim_{n\to\infty}\frac{|x-3|}{2}\sqrt[3]{\frac{n^2+5}{(n+1)^2+5}}=\frac{|x-3|}{2}<1$$

Paydadaki $2$ karşı tarafa çarpım olarak geçer: $|x-3|<2$, yani $1<x<5$. Bu aralıkta seri mutlak yakınsaktır. Yakınsaklık yarıçapı $2$'dir.

Oran testi uç noktalar hakkında bilgi vermez. Hoca dört olasılığı saydı: aralık iki taraftan açık, birden kapalı beşten açık, birden açık beşten kapalı ya da iki taraftan kapalı olabilir. Bu yüzden $x=1$ ve $x=5$ seriye ayrı ayrı konur.

### 2.3 Uç nokta $x=1$

$x=1$ için $(x-3)^n=(-2)^n=(-1)^n2^n$ olur. $2^n$'ler sadeleşir. Serinin başındaki $(-1)^n$ ile buradan gelen $(-1)^n$ çarpılınca $(-1)^{2n}=1$ olur. Geriye pozitif terimli seri kalır:

$$\sum_{n=1}^{\infty}\frac{1}{\sqrt[3]{n^2+5}}$$

Hoca bunu limit karşılaştırma testiyle $\sum\dfrac{1}{n^{2/3}}$ serisiyle karşılaştırdı:

$$\lim_{n\to\infty}\frac{1/\sqrt[3]{n^2+5}}{1/n^{2/3}}=1$$

Limit sonlu ve pozitif olduğu için iki seri aynı karakterdedir. $p$-testine göre $\sum\dfrac{1}{n^p}$ serisi $p>1$ ise yakınsak, $p\le1$ ise ıraksaktır. Burada $p=\tfrac23<1$, karşılaştırılan seri ıraksaktır. O hâlde verilen seri de $x=1$'de ıraksaktır. $1$ aralığa dahil değildir.

### 2.4 Uç nokta $x=5$

$x=5$ için $(x-3)^n=2^n$ olur, $2^n$'ler sadeleşir:

$$\sum_{n=1}^{\infty}\frac{(-1)^n}{\sqrt[3]{n^2+5}}$$

Bu bir alterne seridir (alternating series). Terimlerin mutlak değeri monoton azalarak sıfıra gider. Alterne seri testine göre seri yakınsaktır. Yani $5$ aralığa dahildir.

Hoca burada bir adım daha attı: $x=5$'teki yakınsaklık mutlak mıdır? Mutlak değerler alınınca yine $\sum\dfrac{1}{\sqrt[3]{n^2+5}}$ çıkar. Bu seri az önce gösterildiği gibi ıraksaktır. Seri yakınsak, mutlak değerlerinin serisi ıraksak olduğu için $x=5$'te seri **şartlı yakınsaktır**.

### 2.5 Sonuç

- $1<x<5$: mutlak yakınsak.
- $x=5$: şartlı yakınsak.
- Yakınsaklık aralığı: $(1,5]$.
- $x\le1$ veya $x>5$: ıraksak.

Hoca, test sürümünde bu dört ifadenin hepsinin doğru olduğunu, şıklara bunların yanında yanlış ifadelerin de konabileceğini söyledi.

## 3. Serilerin Karakteri: Karşılaştırma ve İntegral Testi

İkinci soruda iki serinin yakınsak mı ıraksak mı olduğu sebepleriyle soruluyor. Hoca bunun da "aşağıdakilerden hangileri doğrudur" biçiminde gelebileceğini söyledi.

### 3.1 Birinci seri

<!-- BELİRSİZ: Serinin yazımı altyazıda yok; aşağıdaki ifade kısa nottan alındı. Hocanın anlatımındaki "n kare", "sinüs 1/n", "kök" parçaları bununla uyumlu. -->

$$\sum_{n=1}^{\infty}\frac{n^2\sin\frac1n}{\sqrt{n^2+n+1}}$$

Hoca payı şöyle düzenledi: $n^2\sin\frac1n=n\cdot\dfrac{\sin\frac1n}{\frac1n}$. $n\to\infty$ iken $\frac1n\to0$ olduğundan $\dfrac{\sin(1/n)}{1/n}\to1$ olur. Bu ifadeyi bildiğimizi, geri kalan kısma bakmak gerektiğini söyledi. Geri kalan $n$ çarpanı nedeniyle harmonik seri $\sum\frac1n$ ile karşılaştırınca oran sonsuza gider. $\sum\frac1n$ ıraksak olduğu için verilen seri de ıraksaktır.

> **Ders sonrası not:** Bu yazımla genel terimin kendisi de $1$'e gider: $\lim a_n=\lim\dfrac{n}{\sqrt{n^2+n+1}}=1\neq0$. Hocanın "sonsuza gidiyor" dediği büyüklük, büyük olasılıkla $a_n$'nin $\frac1n$'e oranıdır ($\lim n\,a_n=\infty$). Her iki yoldan da seri ıraksaktır; en kısa yol genel terim testidir (sympy ile doğrulandı).

### 3.2 Genel terim testi

Hoca ikinci seriye geçmeden önce genel kuralı hatırlattı:

**Genel terim testi**

- $\lim\limits_{n\to\infty}a_n\neq0$ ise $\sum a_n$ doğrudan ıraksaktır.
- $\lim\limits_{n\to\infty}a_n=0$ ise seri hakkında karar verilemez. Yakınsak da olabilir, ıraksak da. Başka bir test gerekir.

### 3.3 İkinci seri ve integral testi

$$\sum_{n=1}^{\infty}\frac{1}{n(1+\ln n)}$$

Genel terim sıfıra gider, bu yüzden başka test gerekir. Hoca integral testini hatırlattı:

**İntegral testi**

- $f$ fonksiyonu $[1,\infty)$ aralığında pozitif, sürekli ve monoton azalan olsun, $a_n=f(n)$.
- Bu durumda $\sum\limits_{n=1}^\infty a_n$ ile $\displaystyle\int_1^\infty f(x)\,dx$ aynı karakterdedir: integral yakınsaksa seri yakınsak, integral ıraksaksa seri ıraksaktır.
- Değerleri eşit değildir. Test yalnız serinin karakteri hakkında bilgi verir.

$n$ yerine $x$ yazılarak $f(x)=\dfrac{1}{x(1+\ln x)}$ kurulur. Bu fonksiyon $[1,\infty)$'da pozitif, sürekli ve azalandır. İntegral bir has olmayan integraldir (improper integral):

$$\int_1^\infty\frac{dx}{x(1+\ln x)}$$

Değişken değiştirme: $u=1+\ln x$ denirse $du=\dfrac{dx}{x}$ olur. $x=1$ için $u=1$, $x=b$ için $u=1+\ln b$:

$$\int_1^\infty\frac{dx}{x(1+\ln x)}=\lim_{b\to\infty}\int_1^{1+\ln b}\frac{du}{u}=\lim_{b\to\infty}\ln(1+\ln b)=\infty$$

İntegral ıraksak olduğundan seri de integral testine göre ıraksaktır. Hoca test sürümünde "ıraksaktır" ve "karakteri integral testiyle belirlenir" ifadelerinin doğru, "yakınsaktır" ifadesinin yanlış olacağını söyledi.

Hoca ardından ekranda, genel terimi $2$ ve $(-1)^n$ ile $2^n$ içeren bir geometrik seri sorusunu gösterdi. Bunu çözmedi; geometrik seri bilgisiyle çözüleceğini, basit olsa da el alışkanlığı için önemli olduğunu söyledi (bkz. Örnek Sorular).

## 4. Geometrik Seriden Arctan x'in Kuvvet Serisi

Hoca bu tip sorunun da gelme ihtimalinin yüksek olduğunu söyledi, çünkü serilerle türev ve integral gibi işlemleri yapabilmek çok kullanışlıdır. Temel kural geometrik seridir:

$$\frac{1}{1-x}=\sum_{n=0}^{\infty}x^n,\qquad |x|<1$$

Soru, bu seriden yararlanarak $f(x)=\arctan x$'in kuvvet serisini istiyor.

**Adım 1: Hangi işlemle $\arctan x$'e ulaşılır?** $\arctan x$'in türevi $\dfrac{1}{1+x^2}$'dir. O hâlde önce $\dfrac{1}{1+x^2}$'nin serisini bulup sonra integral alırsak $\arctan x$'i elde ederiz.

**Adım 2: Geometrik seriye benzetme.** $\dfrac{1}{1-x}$'te $x$ yerine $-x^2$ yazılırsa $\dfrac{1}{1+x^2}$ elde edilir. Aynı yerine yazma seride yapılır:

$$\frac{1}{1+x^2}=\sum_{n=0}^{\infty}(-x^2)^n=\sum_{n=0}^{\infty}(-1)^nx^{2n},\qquad |x|<1$$

**Adım 3: Terim terim integral.** Her iki taraf $x$'e göre integre edilir:

$$\arctan x+C=\sum_{n=0}^{\infty}(-1)^n\frac{x^{2n+1}}{2n+1}$$

**Adım 4: Sabitin bulunması.** $x=0$ konursa $\arctan0=0$ ve sağ taraf da $0$ olduğundan $C=0$ çıkar:

$$\arctan x=\sum_{n=0}^{\infty}(-1)^n\frac{x^{2n+1}}{2n+1}=x-\frac{x^3}{3}+\frac{x^5}{5}-\cdots$$

Bu açılım sympy ile doğrulandı.

<!-- BELİRSİZ: 00:18:52 civarında hoca "her tarafı ... x ile çarpmak suretiyle" benzeri bir manipülasyondan söz ediyor; ekrandaki ikinci bir şıkkın (örneğin bir x kuvvetiyle çarpılmış arctan serisi) ne olduğu altyazıdan anlaşılmıyor. -->

## 5. Kutupsal Koordinatlarda Bölge ve Alan

### 5.1 Kutupsal bölge çizimi

Soru: $\theta=-\dfrac{2\pi}{3}$ ve $-1\le r<2$ ile verilen nokta kümesi aşağıdaki grafiklerden hangisidir?

<!-- BELİRSİZ: Hoca önce "r eksi 1 ile artı 1 arasında" diye okuyor, sonra "R eksi bir ile artı iki arasında", "iki dahil değil", "bir dahil" diyor. Aralık kısa nottaki gibi -1 ≤ r < 2 alındı. -->

$\theta$ sabit olduğu için küme, başlangıç noktasından geçen $\theta=-\tfrac{2\pi}{3}$ doğrultusu üzerinde bir doğru parçasıdır. $r$ pozitifken nokta bu açı yönünde, $r$ negatifken ters yönde (açının $\pi$ fazlası yönünde) yer alır. Yani parça, başlangıçtan $-\tfrac{2\pi}3$ yönünde $2$ birime kadar uzanır, ters yönde de $1$ birim uzanır. Hoca uç noktaların durumuna dikkat çekti: $r=2$ dahil değil (açık uç), $r=-1$ dahil (kapalı uç).

### 5.2 İki eğri arasındaki alan

Hoca bunu "çok orijinal, ama zor" bir soru olarak tanıttı.

**Soru:** $r=2$ çemberinin dışında, $r=4\sin\theta$ çemberinin içinde ve $r\sin\theta=3$ eşitliğiyle sınırlı bölgenin alanını veren integral hangisidir?

**$r=4\sin\theta$ eğrisinin tanınması.** Hoca bu eğrinin mutlaka çizilebilmesi gerektiğini söyledi ve kartezyen koordinatlara geçişi hatırlattı. $x=r\cos\theta$, $y=r\sin\theta$, $x^2+y^2=r^2$'dir. Denklemin iki tarafı $r$ ile çarpılır:

$$r^2=4r\sin\theta\ \Rightarrow\ x^2+y^2=4y\ \Rightarrow\ x^2+y^2-4y+4=4\ \Rightarrow\ x^2+(y-2)^2=4$$

Bu, merkezi $(0,2)$, yarıçapı $2$ olan çemberdir. Hoca genel bilgiyi de hatırlattı: $r=a\sin\theta$ türü eğriler ($r=2\sin\theta$, $r=3\sin\theta$ gibi) $x$ ekseninin üst tarafında çizilen çemberlerdir; $r=a\cos\theta$ türü eğriler ($r=5\cos\theta$ gibi) ise yana doğru çizilir. Çemberin büyüklüğü katsayıya göre değişir.

**Üçüncü sınır.** $r\sin\theta=y$ olduğu için $r\sin\theta=3$ denklemi $y=3$ doğrusudur. Kutupsal biçimde $r=\dfrac{3}{\sin\theta}$ yazılır.

**Kesişim noktaları.**

- $r=4\sin\theta$ ile $r=2$: $4\sin\theta=2\Rightarrow\sin\theta=\tfrac12\Rightarrow\theta=\tfrac\pi6$ (sağ yarıda).
- $r=4\sin\theta$ ile $y=3$: $4\sin\theta\cdot\sin\theta=3\Rightarrow\sin^2\theta=\tfrac34\Rightarrow\theta=\tfrac\pi3$ (sağ yarıda).

**İntegralin kurulması.** Bölge $y$ eksenine göre simetriktir. Hoca sağ yarıyı bulup $2$ ile çarpmayı önerdi. Sağ yarı da iki parçadır:

- $\tfrac\pi6\le\theta\le\tfrac\pi3$: dış sınır $r=4\sin\theta$, iç sınır $r=2$.
- $\tfrac\pi3\le\theta\le\tfrac\pi2$: dış sınır $y=3$ doğrusu, yani $r=\dfrac{3}{\sin\theta}$; iç sınır $r=2$.

Kutupsal alan formülü $A=\dfrac12\displaystyle\int_\alpha^\beta\left(r_{\text{dış}}^2-r_{\text{iç}}^2\right)d\theta$ olduğundan:

$$A=2\left[\frac12\int_{\pi/6}^{\pi/3}\left(16\sin^2\theta-4\right)d\theta+\frac12\int_{\pi/3}^{\pi/2}\left(\frac{9}{\sin^2\theta}-4\right)d\theta\right]$$

Hoca soruyu "bu alanı veren integral hangisidir" biçiminde ele aldı ve integrali kurmakla yetindi.

> **Ders sonrası not:** İntegral hesaplanırsa $A=3\sqrt3\approx5{,}196$ birim kare çıkar (sympy ile doğrulandı). Hoca derste sonucu hesaplamadı.

> **Ek bilgi (derste anlatılmadı):** $r=a\sin\theta$ çemberi $x$ eksenine başlangıç noktasında teğettir, $r=a\cos\theta$ çemberi ise $y$ eksenine başlangıç noktasında teğettir. Her ikisinin de yarıçapı $\tfrac{|a|}{2}$'dir.

## 6. Parametrik ve Kapalı Tanımlı Eğride Teğet Eğimi

**Soru:** Parametrik denklemleri

$$t^2\sin x+x^3=e^t,\qquad y=t\sin t-2t$$

ile verilen eğrinin $t=0$'daki teğet doğrusunun eğimi nedir?

<!-- BELİRSİZ: Denklemlerin yazımı ekranda; altyazıdaki türev adımları (2t sin x, t kare cos x, 3x kare, e üzeri t; sin t, t cos t, -2) bu yazımla uyumlu. -->

Teğet eğimi $\dfrac{dy}{dx}$'tir. $x$ de $y$ de $t$'ye bağlı olduğundan zincir kuralıyla

$$\frac{dy}{dx}=\frac{dy/dt}{dx/dt}$$

yazılır.

**Adım 1: $t=0$'daki nokta.** İlk denklemde $t=0$: $x^3=e^0=1\Rightarrow x=1$. İkinci denklemde $t=0$: $y=0$.

**Adım 2: $dx/dt$.** İlk denklem $x$ için kapalı biçimdedir. $t$'ye göre türev alınır; $x$, $t$'nin fonksiyonudur:

$$2t\sin x+t^2\cos x\,\frac{dx}{dt}+3x^2\frac{dx}{dt}=e^t$$

$t=0$, $x=1$ konursa: $0+0+3\dfrac{dx}{dt}=1\Rightarrow\dfrac{dx}{dt}=\dfrac13$.

**Adım 3: $dy/dt$.** $\dfrac{dy}{dt}=\sin t+t\cos t-2$. $t=0$'da $\dfrac{dy}{dt}=-2$.

**Adım 4: Eğim.**

$$\frac{dy}{dx}=\frac{-2}{1/3}=-6$$

Hoca son değeri sözlü okumadı, "oranladığımızda eğim çıkıyor" dedi. Sonuç $-6$'dır (sympy ile doğrulandı).

> **Hocanın vurgusu:** Soru, parametrik fonksiyonda türev alabiliyor musunuz, zincir kuralını biliyor musunuz, bunu ölçmek istiyor.

## 7. Yönlü Türev ve Uç Değerleri

### 7.1 Yönlü türevin hatırlatılması

İlk moladan sonra hoca uygulama föyünden yönlü türev (directional derivative) sorularına geçti. Önce tanımı hatırlattı.

**Yönlü türev**

- $f$ fonksiyonunun $P_0$ noktasında $\vec u$ yönündeki türevi $D_{\vec u}f(P_0)=\nabla f(P_0)\cdot\vec u$'dur.
- Burada $\vec u$ birim vektör olmalıdır. Verilen vektörün boyu $1$ değilse, vektör kendi boyuna bölünerek birim vektör $\vec v=\dfrac{\vec u}{|\vec u|}$ elde edilir ve onun yönünde türev alınır.
- Gradyan (gradient): $\nabla f=\langle f_x,f_y,f_z\rangle$. İki değişkenli fonksiyonda iki bileşen vardır.

İki vektörün skaler çarpımı, boylarının çarpımı ile aradaki açının kosinüsünün çarpımıdır. $\vec u$ birim vektör olduğundan

$$D_{\vec u}f=|\nabla f|\cos\theta$$

olur. Buradan uç değerler çıkar:

- $\cos\theta$'nın en büyük değeri $1$'dir ($\theta=0$). Yönlü türevin en büyük değeri $|\nabla f|$'dir ve $\nabla f$ yönünde alınır. Hoca bunu "tam gaz ileri" diye anlattı.
- $\cos\theta$'nın en küçük değeri $-1$'dir ($\theta=\pi$). Yönlü türevin en küçük değeri $-|\nabla f|$'dir ve $-\nabla f$ yönünde alınır.
- Yönlü türevin sıfır olması için aradaki açı $90^\circ$ olmalıdır: $\vec u\perp\nabla f$.

### 7.2 Uç değerleri bulma sorusu

**Soru:** Verilen $f$ için $(1,-1)$ noktasında yönlü türevin en büyük, en küçük ve sıfır olduğu $\vec u$ yönlerini ve değerlerini bulunuz.

<!-- BELİRSİZ: Fonksiyonun tam ifadesi altyazıda yok. Hoca f_x = 2x - y diyor; gradyanın (1,-1)'deki değeri 3 ve 4 bileşenleriyle, boyu 5 olarak anlatılıyor. Kısa nota göre ∇f(1,-1) = ⟨3,-4⟩. -->

Gradyan hesaplanır: $f_x=2x-y$ olduğundan $f_x(1,-1)=3$. Kısa nottaki değerle $\nabla f(1,-1)=\langle3,-4\rangle$ alınır.

- Boy: $|\nabla f|=\sqrt{3^2+4^2}=5$.
- En büyük değer: $5$, yön $\vec u=\dfrac{\nabla f}{|\nabla f|}=\tfrac35\vec i-\tfrac45\vec j$.
- En küçük değer: $-5$, yön $-\tfrac35\vec i+\tfrac45\vec j$.

**Sıfır olduğu yönler.** $\vec u=a\vec i+b\vec j$ birim vektör olsun: $a^2+b^2=1$. Yönlü türevin sıfır olması için $\nabla f\cdot\vec u=3a-4b=0$ olmalıdır. Buradan $a=\tfrac43b$ (ara adım eklendi). Birim koşulunda yerine yazılırsa:

$$\frac{16}{9}b^2+b^2=1\ \Rightarrow\ \frac{25}{9}b^2=1\ \Rightarrow\ b=\pm\frac35,\quad a=\pm\frac45$$

İki vektör çıkar:

$$\vec u_1=\frac45\vec i+\frac35\vec j,\qquad \vec u_2=-\frac45\vec i-\frac35\vec j$$

(sympy ile doğrulandı.)

> **Ders sonrası not:** Kısa nota göre föydeki $\vec u_1$ yazımı "$-\tfrac35\vec j+\tfrac45\vec i$" gibi görünüyordu. $3a-4b=0$ koşulunda $a$ ile $b$ aynı işaretlidir; doğru vektörler $\pm\left(\tfrac45\vec i+\tfrac35\vec j\right)$'dir.

### 7.3 Birim olmayan vektör yönünde türev

Ders içinde benzer bir soru daha geçti: fonksiyonun verilen noktada $\vec u=\langle4,3\rangle$ yönündeki türevi. Hoca bu yönde doğrudan çalışılamayacağını vurguladı, çünkü $|\vec u|=\sqrt{4^2+3^2}=5\neq1$. Önce birim vektör kurulur:

$$\vec v=\frac{\vec u}{|\vec u|}=\left\langle\frac45,\frac35\right\rangle$$

Sonra $D_{\vec v}f(P_0)=f_x(P_0)\cdot\frac45+f_y(P_0)\cdot\frac35$ hesaplanır. Bu, fonksiyonun o doğrultuda gidildiğinde ne kadar değiştiğini verir.

<!-- BELİRSİZ: Bu sorudaki fonksiyon ve nokta altyazıda geçmiyor; sayısal sonuç verilemiyor. -->

Hoca ardından "en hızlı artan, en hızlı azalan yön" sorusunu kısaca geçti: fonksiyon en hızlı $\nabla f$ yönünde artar, en hızlı $-\nabla f$ yönünde azalır. Föydeki nokta-düzlem uzaklığı, nokta-doğru uzaklığı ve iz düşüm sorularını ise "basit, zaten yaptık" diyerek atladı.

## 8. İki Doğrunun Belirlediği Düzlem

**Soru:** Parametrik denklemleri verilen $L_1$ (parametre $t$) ve $L_2$ (parametre $s$) doğrularının belirlediği düzlem hangisidir?

Doğrunun parametrik biçimi $x=x_0+tv_1$, $y=y_0+tv_2$, $z=z_0+tv_3$'tür. Parametrenin katsayıları doğrultu vektörünü verir. Hoca katsayıları okudu:

- $L_1$: $t$'nin katsayıları $1,1,-1$, yani $\vec v_1=\langle1,1,-1\rangle$.
- $L_2$: $s$'nin katsayıları $-4,2,-2$, yani $\vec v_2=\langle-4,2,-2\rangle$.

İki vektörün vektörel çarpımı her ikisine de diktir, dolayısıyla düzlemin normal vektörünü verir:

$$\vec n=\vec v_1\times\vec v_2=\begin{vmatrix}\vec i&\vec j&\vec k\\1&1&-1\\-4&2&-2\end{vmatrix}=\langle0,6,6\rangle$$

Düzlem üzerinde bir nokta gerekir. Hoca $L_1$ üzerinden $P_0(-1,2,1)$ noktasını aldı (diğer doğrudan da alınabileceğini söyledi). Düzlemde dolaşan keyfi nokta $P(x,y,z)$ olsun. $\overrightarrow{P_0P}=\langle x+1,\,y-2,\,z-1\rangle$ vektörü düzlemdedir, normal vektöre diktir; skaler çarpımları sıfırdır:

$$0\cdot(x+1)+6(y-2)+6(z-1)=0\ \Rightarrow\ y+z=3$$

(sympy ile doğrulandı.)

> **Ders sonrası not:** Hoca vektörel çarpımın sonucunu önce "0, 0, 6" diye okudu, hemen ardından "0, 6, 6" dedi; doğrusu $\langle0,6,6\rangle$. $\overrightarrow{P_0P}$'nin ilk bileşenini de önce "$x+2$" dedi, sonra $x+1$ diye düzeltti.

## 9. Tanımla Kısmi Türev

Hoca bu tip sorunun "mutlaka gelir" dediği sorulardan olduğunu söyledi ve boş tahtada çözdü.

**Soru:** $f(x,y)=\sqrt[3]{x^4+y^2}$ için $f_x(0,0)$ ve $f_y(0,0)$ mevcutsa bulunuz.

Orijinde formülle türev alınamaz (köklü ifadenin türevi orada tanımsızdır), bu yüzden tanım kullanılır.

**$x$'e göre:**

$$f_x(0,0)=\lim_{h\to0}\frac{f(h,0)-f(0,0)}{h}=\lim_{h\to0}\frac{\sqrt[3]{h^4}}{h}=\lim_{h\to0}\frac{h^{4/3}}{h}=\lim_{h\to0}h^{1/3}=0$$

**$y$'ye göre:**

$$f_y(0,0)=\lim_{k\to0}\frac{f(0,k)-f(0,0)}{k}=\lim_{k\to0}\frac{\sqrt[3]{k^2}}{k}=\lim_{k\to0}\frac{1}{k^{1/3}}$$

Bu limit yoktur ($k\to0^+$ iken $+\infty$, $k\to0^-$ iken $-\infty$). Sonuç: $f_x(0,0)=0$, $f_y(0,0)$ mevcut değildir (sympy ile doğrulandı).

Hoca dersin ilerleyen kısmında, iki yıl sonra benzer bir sorunun ($x^2$ ve $y^4$ içeren bir fonksiyon) yine sorulduğunu gösterdi. Parçalı tanımlı fonksiyonlarda mutlaka tanımın kullanılacağını, çok soru çözdükçe bu melekenin gelişeceğini söyledi.

<!-- BELİRSİZ: Bu ikinci sorunun fonksiyonu altyazıda yalnız "x kare y üzeri 4" diye geçiyor; tam ifadesi anlaşılmıyor ve derste çözülmedi. -->

## 10. Yakınsaklık Yarıçapından Parametre Bulma

**Soru:** Bir kuvvet serisinin yakınsaklık yarıçapının $3$ olması için $b$ sabitinin alabileceği değerlerin toplamı nedir?

<!-- BELİRSİZ: Serinin genel terimi altyazıda yok. -->

Hoca soruyu "orijinal, mantığını anlayan rahat çözer" diye tanıttı. Yine oran testi uygulanır: $\left|\dfrac{a_{n+1}}{a_n}\right|$ oranında $n$'li kısmın limiti $1$'e gider ve geriye $|b|\,|x-x_0|<1$ türü bir koşul kalır. Buradan yakınsaklık yarıçapı

$$R=\frac{1}{|b|}$$

bulunur. $R=3$ olması için $|b|=\tfrac13$, yani $b=-\tfrac13$ ya da $b=\tfrac13$ olmalıdır. Değerlerin toplamı $-\tfrac13+\tfrac13=0$'dır.

## 11. Vektör Fonksiyonları: Yay Uzunluğu ve Konum-İvme Açısı

Hoca bir eğri verildiğinde teğet vektörünün eğrinin parametreye göre türevinden geldiğini kısaca hatırlattı, sonra iki sınav sorusuna geçti.

### 11.1 Yay uzunluğu

**Soru:** $\vec r(t)=(1+t^2)^{3/2}\vec i+(3-t^2)^{3/2}\vec j+4t^2\vec k$ eğrisinin $-1\le t\le1$ aralığındaki kısmının yay uzunluğu nedir?

Yay uzunluğu $s=\displaystyle\int_a^b|\vec r\,'(t)|\,dt$'dir. Hoca türevi alıp boyunu doğru düzenlemenin bu sorudaki asıl iş olduğunu söyledi. Ara adımlar (ara adım eklendi):

$$\vec r\,'(t)=3t(1+t^2)^{1/2}\vec i-3t(3-t^2)^{1/2}\vec j+8t\,\vec k$$

$$|\vec r\,'(t)|^2=9t^2(1+t^2)+9t^2(3-t^2)+64t^2=36t^2+64t^2=100t^2\ \Rightarrow\ |\vec r\,'(t)|=10|t|$$

$$s=\int_{-1}^{1}10|t|\,dt=2\int_0^1 10t\,dt=10$$

> **Ders sonrası not:** Hoca sonucu "11" diye okudu; doğrusu $10$ birimdir (sympy ile doğrulandı).

Hoca "alan isteseydi nasıl bulacaktık" diye sordu, ama bu soruyu açmadı.

### 11.2 Konum vektörü ile ivme arasındaki açı

**Soru:** Uzayda hareket eden bir cismin konum fonksiyonu verilmiş. Konum vektörü ile ivme vektörü arasındaki açı ne zaman $\tfrac{2\pi}{3}$ olur?

<!-- BELİRSİZ: Konum fonksiyonu altyazıda geçmiyor. Kısa nota göre r(t) = cos t i + sin t j + √3 t k (ders 15'te çözülen soru). -->

Kısa nottaki fonksiyonla: $\vec r(t)=\cos t\,\vec i+\sin t\,\vec j+\sqrt3\,t\,\vec k$. İvme, konumun iki kez türevidir:

$$\vec a(t)=\vec r\,''(t)=-\cos t\,\vec i-\sin t\,\vec j$$

- $\vec r\cdot\vec a=-\cos^2t-\sin^2t=-1$.
- $|\vec r|=\sqrt{1+3t^2}$, $|\vec a|=1$.

İki vektör arasındaki açı için $\cos\theta=\dfrac{\vec r\cdot\vec a}{|\vec r|\,|\vec a|}$ ve $\cos\tfrac{2\pi}3=-\tfrac12$:

$$\frac{-1}{\sqrt{1+3t^2}}=-\frac12\ \Rightarrow\ \sqrt{1+3t^2}=2\ \Rightarrow\ t^2=1\ \Rightarrow\ t=\pm1$$

Zaman $t\ge0$ alınırsa $t=1$ (sympy ile doğrulandı).

## 12. Tanım Kümesi, Limit ve Zincir Kuralı

### 12.1 Tanım kümesi

**Soru:** $f(x,y)=\arccos\dfrac{y}{x^2}+\ln(1-x^2)$ fonksiyonunun tanım kümesini bulup çiziniz.

Hoca soruyu tahtaya yazdı. İki parça ayrı ayrı incelenir ve kesişim alınır.

**Arccos kısmı.** $z=\arccos\dfrac{y}{x^2}$ denirse $\cos z=\dfrac{y}{x^2}$ olur. Kosinüs $[-1,1]$ aralığında değer aldığı için

$$-1\le\frac{y}{x^2}\le1\ \Rightarrow\ -x^2\le y\le x^2$$

Bu, $y=x^2$ ve $y=-x^2$ parabolleri arasındaki bölgedir.

**Logaritma kısmı.** $\ln$'in tanımlı olması için $1-x^2>0$, yani $x^2<1$, $-1<x<1$ olmalıdır.

**Tanım kümesi.** İki koşulun kesişimi:

$$D_f=\{(x,y):\ -1<x<1,\ -x^2\le y\le x^2\}$$

Grafik, iki parabol arasında kalan ve $x=\pm1$ dikey doğrularıyla sınırlanan bölgedir.

> **Ders sonrası not:** $\dfrac{y}{x^2}$ ifadesi $x=0$'da tanımsızdır, bu yüzden $x\neq0$ koşulu da gerekir: $D_f=\{(x,y):\ -1<x<1,\ x\neq0,\ -x^2\le y\le x^2\}$. Derste bu koşul söylenmedi.

### 12.2 Limit

Hoca limit sorularının "kaçırılmaz", sürekli gelen sorular olduğunu söyledi. İki tip gösterdi:

- **Köklü ifade:** Değerler yerine konunca $\tfrac00$ belirsizliği çıkıyor. Tek değişkenli fonksiyonlardaki gibi pay ve payda eşlenikle çarpılır, sadeleştirme yapılır ve sonuç doğrudan bulunur.
- **İki değişkenli $\tfrac00$ belirsizliği:** Eksenler boyunca yaklaşmak aynı sonucu verebilir, ama bu yetmez. "Üçüncü yol" çok önemlidir: $y=mx$ doğrusu ya da $y=mx^2$ eğrisi boyunca yaklaşılır. Sonuç $m$'ye bağlı çıkarsa, farklı yollarda farklı limit değerleri çıktığı için limit yoktur. $m$'den bağımsız çıkarsa limit bu değerdir (aday).

<!-- BELİRSİZ: Bu iki limit sorusunun ifadeleri altyazıda geçmiyor. -->

> **Ek bilgi (derste anlatılmadı):** Yollar boyunca hep aynı değerin çıkması limitin varlığını kanıtlamaz; varlığı göstermek için genellikle sıkıştırma (örneğin kutupsal koordinata geçip $r\to0$'a bakma) gerekir. Farklı iki yolda farklı değer çıkması ise limitin olmadığını kesin olarak gösterir.

### 12.3 Zincir kuralı

Föyde $z=f(x,y)$, $x$ ve $y$ de $r$ ile $\theta$'ya bağlı olan bir soru vardı; belirli bir ifadenin sıfır olduğunu göstermek isteniyor. Hoca çözmedi, yöntemi anlattı: $z$'nin $\theta$'ya göre türevi alınırken önce $z$'nin $x$'e göre türevi ile $x$'in $\theta$'ya göre türevi çarpılır, buna $z$'nin $y$'ye göre türevi ile $y$'nin $\theta$'ya göre türevinin çarpımı eklenir:

$$\frac{\partial z}{\partial\theta}=\frac{\partial z}{\partial x}\frac{\partial x}{\partial\theta}+\frac{\partial z}{\partial y}\frac{\partial y}{\partial\theta}$$

Test sürümünde "bu ifade neye eşittir" ya da işaret değiştirilmiş şıklar biçiminde gelebileceğini söyledi.

<!-- BELİRSİZ: Zincir kuralı sorusunun tam ifadesi (x ve y'nin r, θ cinsinden tanımı ve sıfır olduğu gösterilecek ifade) altyazıda anlaşılmıyor. -->

## 13. Kapalı Fonksiyonlarda Kısmi Türev

Hoca bunu "girebilecek soru tiplerinden biri, güzel bir soru" diye tanıttı ve tahtada çözdü.

**Soru:** $z$, $x$ ile $y$'nin sabit olmayan bir fonksiyonu olmak üzere

$$G\!\left(2x-z^2\right)=y-\frac{z^3}{3}$$

denklemiyle kapalı olarak tanımlanmış olsun. $\dfrac{\partial z}{\partial x}+z\dfrac{\partial z}{\partial y}$ neye eşittir?

<!-- BELİRSİZ: Hoca soruyu önce "G, iki x eksi z kare, y eksi bir bölü üç z küp, eşittir sıfır" diye okuyor; çözümde y - z³/3 = G(2x - z²) biçimini kullanıyor. Aşağıdaki çözüm bu biçime göredir; ek bilgi bloğunda diğer okumanın da aynı sonucu verdiği gösterildi. -->

Hoca iki yöntem olduğunu söyledi, birini gösterdi. Her şey bir tarafa toplanıp tek bir fonksiyon kurulur:

$$F(x,y,z)=G\!\left(2x-z^2\right)-y+\frac{z^3}{3}=0$$

**Kapalı fonksiyon türevi**

- $F(x,y,z)=0$ ile $z=z(x,y)$ tanımlanıyorsa $\dfrac{\partial z}{\partial x}=-\dfrac{F_x}{F_z}$, $\dfrac{\partial z}{\partial y}=-\dfrac{F_y}{F_z}$.

Kısmi türevler ($G'$, $G$'nin $2x-z^2$ noktasındaki türevidir):

- $F_x=2G'$ (iç türev $2$).
- $F_y=-1$.
- $F_z=-2z\,G'+z^2$ ($G$'nin iç türevi $-2z$; $\tfrac{z^3}{3}$'ün türevi $z^2$).

Buradan:

$$z_x=-\frac{2G'}{z^2-2zG'},\qquad z_y=\frac{1}{z^2-2zG'}$$

$$z_x+z\,z_y=\frac{-2G'+z}{z^2-2zG'}=\frac{z-2G'}{z(z-2G')}=\frac1z$$

Hocanın bulduğu sonuç $\dfrac1z$'dir ve doğrudur (sympy ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Soru $\Phi\!\left(2x-z^2,\ y-\tfrac{z^3}{3}\right)=0$ biçiminde, iki değişkenli keyfi bir $\Phi$ ile verilmiş olsaydı da sonuç değişmezdi. $\Phi_x=2\Phi_u$, $\Phi_y=\Phi_v$, $\Phi_z=-2z\Phi_u-z^2\Phi_v$ olur ve $z_x+z\,z_y=\dfrac{2\Phi_u+z\Phi_v}{z(2\Phi_u+z\Phi_v)}=\dfrac1z$ çıkar (sympy ile doğrulandı).

## 14. Kutupsal Koordinatlarla İki Katlı İntegral

İkinci moladan sonra hoca "güzel integral sorularını" çözdü.

### 14.1 Kutupsal dönüşümün hatırlatılması

$\displaystyle\iint_D f(x,y)\,dx\,dy$ integralinde bölge kutupsal koordinatlara geçirilir: $x=r\cos\theta$, $y=r\sin\theta$. Dönüşümün Jacobian'ı

$$\frac{\partial(x,y)}{\partial(r,\theta)}=\begin{vmatrix}\cos\theta&-r\sin\theta\\\sin\theta&r\cos\theta\end{vmatrix}=r$$

olduğundan

$$\iint_D f(x,y)\,dx\,dy=\iint_{D'} f(r\cos\theta,r\sin\theta)\,r\,dr\,d\theta$$

yazılır. Hoca bunu daha önce gösterdiğini, tekrar türetmeye gerek olmadığını söyledi.

> **Hocanın vurgusu:** Kutupsal koordinata geçerken Jacobian olan $r$'yi unutmayın. Burası çok önemli.

### 14.2 Örnek

**Soru:** $D$, birinci bölgede $x^2+y^2=16$ çemberi, $y=x$ ve $y=0$ doğrularıyla sınırlı bölge olmak üzere

$$\iint_D\frac{1}{\sqrt{x^2+y^2}}\,dA$$

integrali neye eşittir?

**Bölgenin çizimi.** $x^2+y^2=16$, yarıçapı $4$ olan çemberdir. $y=0$ ($x$ ekseni) ile $y=x$ doğrusu arasındaki dilim alınır. $y=x$ doğrusunun açısı $\tfrac\pi4$'tür (dik açının yarısı).

**Sınırlar.** $0\le\theta\le\tfrac\pi4$, $0\le r\le4$. $x^2+y^2=r^2$ olduğundan:

$$\int_0^{\pi/4}\!\!\int_0^4\frac{1}{r}\,r\,dr\,d\theta=\int_0^{\pi/4}\!\!\int_0^4dr\,d\theta=\int_0^{\pi/4}4\,d\theta=4\cdot\frac\pi4=\pi$$

$r$'ler sadeleşir ve sonuç $\pi$ birim küp çıkar. Hoca integrandın bir fonksiyon olduğu iki katlı integralin bir cismin hacmini verdiğini hatırlattı.

> **Ders sonrası not:** Hoca soruyu yazarken integrandı "$\tfrac{1}{x^2+y^2}$" diye okudu, ama çözümde "kök içinde $r^2$" yazdı ve $r$'leri sadeleştirdi. Sadeleşme ve $\pi$ sonucu ancak $\tfrac{1}{\sqrt{x^2+y^2}}$ ile mümkündür. $\tfrac{1}{x^2+y^2}$ olsaydı $\int_0^4\tfrac{dr}{r}$ ıraksardı (orijinde has olmayan integral). Sonuç sympy ile doğrulandı.

### 14.3 Aynı sorunun varyasyonları

Hoca aynı soruyu bölgeyi değiştirerek iki kez daha kurdu.

**Varyasyon 1: Halka parçası.** $0\le\theta\le\tfrac\pi4$, $2\le r\le4$. Bu, $r=2$ çemberinin dışında, $r=4$ çemberinin içinde, $y=0$ ile $y=x$ arasındaki bölgedir. İntegral aynı biçimde kurulur, yalnız $r$ alt sınırı $2$ olur. Hoca hesabı tamamlamadı; sonuç $\displaystyle\int_0^{\pi/4}\!\!\int_2^4dr\,d\theta=2\cdot\frac\pi4=\frac\pi2$'dir (sympy ile doğrulandı).

**Varyasyon 2: Doğru ile çember arası.** $0\le\theta\le\arctan\tfrac43$, $\dfrac{3}{\cos\theta}\le r\le5$. Hoca burada da grafik çizmenin önemini vurguladı. $r=\dfrac{3}{\cos\theta}$ demek $r\cos\theta=3$, yani $x=3$ doğrusudur. $r=5$ çemberidir. Bölge, $x=3$ doğrusu ile $r=5$ çemberi arasında, $x$ ekseninin üstünde kalan parçadır. Doğru ile çember $(3,4)$ noktasında kesişir.

> **Hocanın vurgusu:** Kartezyen koordinatlardan kutupsala ya da kutupsaldan kartezyene dönüşümü bilmek şekil çizimini çok kolaylaştırır.

> **Ders sonrası not:** Hoca açı sınırını önce "$\arctan\tfrac34$" dedi, sonra "$\tfrac43$ diyelim, değişen bir şey yok" dedi. Değişir: $x=3$ doğrusu ile $r=5$ çemberi $(3,4)$'te kesiştiği için doğru sınır $\theta=\arctan\tfrac43$'tür. Hoca bu varyasyonun sonucunu hesaplamadı (çözüm Örnek Sorular bölümünde).

## 15. İntegrasyon Sırasını Değiştirme

**Soru:** Tahtadaki integral:

$$\int_0^3\!\!\int_0^{3y}e^{x^2}\,dx\,dy$$

<!-- BELİRSİZ: Hoca integrali yazarken sınırları birkaç kez değiştirdi ("0'dan x bölü 3'e kadar", "0'dan 3y'ye kadar"); sınırlar, hocanın çizdiği bölgeden (0 ≤ y ≤ 3, 0 ≤ x ≤ 3y) kuruldu. -->

**Neden sıra değişmeli?** İç integral $\int e^{x^2}\,dx$'tir. Hoca bu integralin bildiğimiz yollarla alınamadığını söyledi. Çok değişkenli integralde çıkış yolu integrasyon sırasını değiştirmektir.

> **Hocanın vurgusu:** $e^{x^2}$ gibi integrali alınamayan fonksiyonlarda yapılacak şey, bölgeyi çizip integrasyon sırasını değiştirmektir.

**Bölgenin çizimi.** $0\le y\le3$, $0\le x\le3y$. Sınır doğrusu $x=3y$, yani $y=\tfrac x3$'tür. $y=3$ konunca $x=9$ olur.

**Sıranın değiştirilmesi.** $dx$ dışarı alınır. $x$, $0$'dan $9$'a değişir. Her $x$ için $y$, alttaki $y=\tfrac x3$ doğrusundan üstteki $y=3$ doğrusuna kadar gider:

$$\int_0^9\!\!\int_{x/3}^{3}e^{x^2}\,dy\,dx$$

Artık iç integral $y$'ye göredir ve $e^{x^2}$ sabit gibi davranır: $\displaystyle\int_{x/3}^3e^{x^2}dy=\left(3-\frac x3\right)e^{x^2}$. Hoca sınırları yerine koyup integralin "rahat bir şekilde" alındığını söyledi.

> **Ders sonrası not:** Tahtadaki sınırlarla sıra değişince $\displaystyle\int_0^9\left(3-\frac x3\right)e^{x^2}dx$ çıkar. $\tfrac x3e^{x^2}$ kısmı alınır, ama $3e^{x^2}$ kısmı yine temel fonksiyonlarla alınamaz. Soru büyük olasılıkla $\displaystyle\int_0^3\!\!\int_{3y}^{9}e^{x^2}\,dx\,dy$ olmalıdır. O zaman bölge $0\le y\le\tfrac x3$, $0\le x\le9$ olur ve $\displaystyle\int_0^9\frac x3e^{x^2}\,dx=\frac{e^{81}-1}{6}$ çıkar (sympy ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Hoca $\int e^{x^2}dx$ için "gama fonksiyonlarıyla çok uzun bir yol" olduğundan söz etti. Bu integralin belirsiz hâli temel fonksiyonlarla yazılamaz; özel bir fonksiyon (sanal hata fonksiyonu, $\operatorname{erfi}$) ile ifade edilir.

**Sorunun üç biçimi.** Hoca aynı sorunun üç farklı şekilde gelebileceğini söyledi:

- İntegrali hesaplayınız. (Bölge çizilip sıra değiştirilmeden yapılamaz.)
- İntegrasyon bölgesi ya da sırası değiştirilmiş hâli aşağıdakilerden hangisidir?
- Bu soruyu çözmek için hangi adımlar izlenmelidir? Doğru cevap: önce integrasyon bölgesi çizilmeli, ardından integrasyon sırası değiştirilmelidir. "Kutupsal koordinatlara geçilmelidir" gibi şıklar yanlıştır.

## 16. Jacobian ile Bölge Dönüşümü

Son soru bölgesel dönüşüm (değişken değiştirme) üzerineydi.

**Soru:** $D$, birinci bölgede $x^2-y^2=1$, $x^2-y^2=3$, $xy=1$ ve $xy=2$ eğrileriyle sınırlı bölge olsun. $\iint_D(\ldots)\,dA$ integralini bulunuz.

<!-- BELİRSİZ: İntegrand altyazıda bir yerde "bir bölü x kare, x y kare", başka yerde "1 bölü x kare eksi y kare" diye geçiyor. Hocanın "x kare artı y kare geliyor, başında 2 var, bunlar sadeleşiyor" demesi integrandda x²+y² çarpanı olduğunu düşündürüyor; aşağıda kısa nottaki gibi x²+y² alındı. -->

**Neden dönüşüm?** Bölge bildiğimiz şekillerle (doğru, çember) sınırlı değil, integrali $x$-$y$ ile yazmak kolay değildir. Bu yüzden bölgeyi basitleştiren yeni değişkenler seçilir:

$$u=x^2-y^2,\qquad v=xy$$

- $u$, $1$'den $3$'e değişir.
- $v$, $1$'den $2$'ye değişir.

$xy$ düzlemindeki karmaşık bölge, $uv$ düzleminde $[1,3]\times[1,2]$ dikdörtgenine dönüşür.

**Jacobian.** $x$ ve $y$, $u$ ve $v$ cinsinden açıkça yazılmamıştır; elimizde ters yöndeki dönüşüm vardır. Bu yüzden ters Jacobian kullanılır:

$$\frac{\partial(x,y)}{\partial(u,v)}=\frac{1}{\dfrac{\partial(u,v)}{\partial(x,y)}},\qquad \frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}u_x&u_y\\v_x&v_y\end{vmatrix}=\begin{vmatrix}2x&-2y\\y&x\end{vmatrix}=2x^2+2y^2=2(x^2+y^2)$$

Dolayısıyla $dA=dx\,dy=\dfrac{du\,dv}{2(x^2+y^2)}$.

> **Hocanın vurgusu:** En önemli şey buradaki Jacobian.

**İntegral.** İntegrand $x^2+y^2$ ise:

$$\iint_D(x^2+y^2)\,dA=\int_1^3\!\!\int_1^2(x^2+y^2)\frac{1}{2(x^2+y^2)}\,dv\,du=\int_1^3\!\!\int_1^2\frac12\,dv\,du=\frac12\cdot2\cdot1=1$$

Hoca bunu "en karmaşık integralin çok sade bir hâle gelmesi" diye özetledi: tek bilinmesi gereken teknik.

> **Ders sonrası not:** Hoca determinantı önce "$2x^2-2y^2$" diye söyledi, sonra "artı" diye düzeltti; doğrusu $2(x^2+y^2)$. Sonucu "5 birim küp" diye söyleyip hemen "hesaplamadım" dedi. Jacobian $\tfrac{1}{2(x^2+y^2)}$ olduğundan $\tfrac{1}{x^2+y^2}$ ya da $\tfrac{1}{x^2-y^2}$ integrandı sadeleşmez (sayısal değerleri sırasıyla yaklaşık $0{,}081$ ve $0{,}159$; hiçbiri 5 değil). Sadeleşen ve büyük olasılıkla kastedilen soru $\iint_D(x^2+y^2)\,dA=1$'dir (sympy ile doğrulandı).

> **Hocanın vurgusu:** Finalde en az bir bölge dönüşümü (Jacobian) sorusu, bir kutupsal koordinat sorusu ve bir integrasyon sırası değiştirme sorusu beklenir. Limit, kısmi türev ve zincir kuralından da soru gelir.

## 17. Örnek Sorular

Bu dersin tamamı soru çözümü olduğu için derste çözülen sorular yukarıdaki bölümlerde adım adım verilmiştir. Burada önce o soruların listesi, sonra derste gösterilip çözülmeyen soruların çözümü yer alır.

**Derste çözülen sorular (çözümler ilgili bölümlerde):**

- (derste sözlü, 00:02:18) $\sum(-1)^n\dfrac{(x-3)^n}{2^n\sqrt[3]{n^2+5}}$ serisi hangi $x$ için mutlak yakınsak, şartlı yakınsak, ıraksaktır? Bölüm 2.
- (derste sözlü, 00:10:03) $\sum\dfrac{n^2\sin(1/n)}{\sqrt{n^2+n+1}}$ ve $\sum\dfrac{1}{n(1+\ln n)}$ serilerinin karakteri. Bölüm 3.
- (derste sözlü, 00:16:01) Geometrik seriden $\arctan x$'in kuvvet serisi. Bölüm 4.
- (derste sözlü, 00:19:33) $\theta=-\tfrac{2\pi}3$, $-1\le r<2$ kümesinin grafiği. Bölüm 5.1.
- (derste sözlü, 00:21:07) $r=2$ dışında, $r=4\sin\theta$ içinde, $r\sin\theta=3$ ile sınırlı alanı veren integral. Bölüm 5.2.
- (derste sözlü, 00:30:31) Parametrik eğrinin $t=0$'daki teğet eğimi. Bölüm 6.
- (derste sözlü, 00:48:26) Yönlü türevin en büyük, en küçük ve sıfır olduğu yönler. Bölüm 7.2.
- (derste sözlü, 00:56:27) İki doğrunun belirlediği düzlem. Bölüm 8.
- (derste sözlü, 01:03:59) $f(x,y)=\sqrt[3]{x^4+y^2}$ için tanımla $f_x(0,0)$, $f_y(0,0)$. Bölüm 9.
- (derste sözlü, 01:07:35) Yakınsaklık yarıçapı $3$ olacak $b$ değerlerinin toplamı. Bölüm 10.
- (derste sözlü, 01:10:10 ve 01:12:02) Yay uzunluğu ve konum-ivme açısı. Bölüm 11.
- (derste sözlü, 01:13:16) $\arccos\dfrac{y}{x^2}+\ln(1-x^2)$'nin tanım kümesi. Bölüm 12.1.
- (derste sözlü, 01:23:00) $z_x+z\,z_y$ (kapalı fonksiyon). Bölüm 13.
- (derste sözlü, 01:42:20) Kutupsal koordinatla $\iint_D\dfrac{dA}{\sqrt{x^2+y^2}}$ ve varyasyonları. Bölüm 14.
- (derste sözlü, 01:50:21) $e^{x^2}$ içeren integralde sıra değiştirme. Bölüm 15.
- (derste sözlü, 01:56:18) $u=x^2-y^2$, $v=xy$ dönüşümüyle iki katlı integral. Bölüm 16.

**Soru A** (derste sözlü, 00:15:39) Genel terimi $2$, $(-1)^n$ ve $2^n$ içeren geometrik tip bir serinin toplamı ya da karakteri.

<!-- BELİRSİZ: Hoca seriyi "y'den sonsuza kadar 2 artı, eksi 1 üzere, n bölü 2 üzere" diye okuyor. Başlangıç indisi ve ifadenin (2+(-1)^n)/2^n mi, 2 + (-1)^n/2^n mi olduğu altyazıdan kesin çıkmıyor. -->

> **Çözüm (derste verilmedi):** Seri $\displaystyle\sum_{n=1}^{\infty}\frac{2+(-1)^n}{2^n}$ olarak okunursa iki geometrik seriye ayrılır: $\displaystyle\sum_{n=1}^\infty\frac{2}{2^n}=2$ ve $\displaystyle\sum_{n=1}^\infty\left(-\frac12\right)^n=\frac{-1/2}{1+1/2}=-\frac13$. Toplam $2-\tfrac13=\tfrac53$'tür. Toplam $n=0$'dan başlıyorsa sonuç $\tfrac{14}{3}$ olur. İfade $2+\tfrac{(-1)^n}{2^n}$ ise genel terim $2$'ye gider ve seri ıraksaktır (sympy ile doğrulandı).

**Soru B** (derste sözlü, 01:48:17) $D$: $0\le\theta\le\arctan\tfrac43$, $\dfrac{3}{\cos\theta}\le r\le5$ bölgesi için $\displaystyle\iint_D\frac{1}{\sqrt{x^2+y^2}}\,dA$ nedir?

> **Çözüm (derste verilmedi):** Kutupsala geçince integrand $\tfrac1r\cdot r=1$ olur:
> $$\int_0^{\arctan(4/3)}\!\!\int_{3/\cos\theta}^{5}dr\,d\theta=\int_0^{\arctan(4/3)}\left(5-\frac{3}{\cos\theta}\right)d\theta=5\arctan\frac43-3\ln\left(\sec\theta+\tan\theta\right)\Big|_0^{\arctan(4/3)}$$
> $\theta=\arctan\tfrac43$'te $\sec\theta=\tfrac53$, $\tan\theta=\tfrac43$, toplamları $3$'tür. Sonuç $5\arctan\dfrac43-3\ln3\approx1{,}341$ (sympy ile doğrulandı).

## Dersin Toparlaması

Bu ders final öncesi bir soru çözüm dersiydi. Seriler tarafında oran testiyle yakınsaklık aralığı bulunup uç noktaların ayrıca incelenmesi, mutlak ve şartlı yakınsaklık ayrımı, karşılaştırma ve integral testleri ile geometrik seriden terim terim integralle $\arctan x$ serisinin elde edilmesi tekrar edildi. Kutupsal koordinatlarda eğrileri kartezyene çevirerek çizmenin ve iki eğri arasındaki alanı parçalara ayırarak kurmanın önemi gösterildi. Çok değişkenli fonksiyonlarda yönlü türevin uç değerleri, düzlem denklemi, tanımla kısmi türev, tanım kümesi, limit ve kapalı fonksiyon türevi soruları çözüldü.

Son bölümde iki katlı integralin üç temel tekniği bir arada görüldü: kutupsal koordinata geçiş (Jacobian $r$), integrali alınamayan fonksiyonlarda integrasyon sırasını değiştirme ve uygun $u$, $v$ seçimiyle bölgeyi dikdörtgene çeviren Jacobian dönüşümü. Hoca bir sonraki derste çok değişkenli fonksiyonlar için Taylor ile yaklaşık hesap, maksimum-minimum problemleri ve kısmi türevin uygulamalarına dair sorular çözüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
