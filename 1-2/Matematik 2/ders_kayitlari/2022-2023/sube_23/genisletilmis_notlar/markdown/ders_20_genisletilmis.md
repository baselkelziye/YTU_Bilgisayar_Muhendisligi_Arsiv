# Ders 20 Genişletilmiş Notu: 1. Vize Soruları ve İki Katlı İntegrallere Giriş: Fubini Teoremi ve İntegrasyon Sırası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Akışı
- 2. 1. Vize Soruları Üzerinden Tekrar
- 3. İki Katlı İntegrale Giriş ve Fubini Teoremleri
- 4. Tek Katlı ve İki Katlı İntegralle Alan; Alan ve Hacim Ayrımı
- 5. Problemler: Eşitliklerin Doğruluğunu Gösteriniz
- 6. Bir Bölge Üzerinde İntegral Yazmak
- 7. İntegrasyon Bölgesini Çizme ve İntegrasyon Sırasını Değiştirme
- 8. Sıra Değiştirmek Neden Gerekli?
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Akışı

Ders online yapıldı. Hoca derse "bugün yeni konuya başlayacağız" diyerek girdi, fakat ekranı paylaşınca önce 1. vizenin soruları açıldı. Dersin ilk yaklaşık yirmi dakikası bu soruların üzerinden hızlıca geçmekle geçti. Hoca soruların genel olarak basit ama dikkat isteyen sorular olduğunu söyledi.

Kısa bir aradan sonra yeni konu olan iki katlı (çift katlı) integrallere (double integrals) geçildi. Önce Fubini teoremi (Fubini's theorem) ile dikdörtgen bölge ve iki eğri arasındaki bölge üzerinde integral anlatıldı. Sonra çözümlü problemler üzerinden integral hesabı, bir bölge üzerinde integral yazma ve integrasyon sırasını değiştirme (change of order of integration) gösterildi.

> **Hocanın vurgusu:** Çok katlı integrallerden finalde en az 3, 4, 5 soru gelebilir. Final genelde integral ağırlıklıdır. Önceki konulardan, özellikle kısmi türevler ve maksimum-minimum hesaplarından da soru gelecektir.

Hoca kalan süre için de bir plan verdi: bu haftanın dışında 3 ya da 4 hafta kaldı. Çok değişkenli fonksiyonların integrali bitince dönemin başından itibaren genel soru çözülecek.

## 2. 1. Vize Soruları Üzerinden Tekrar

Hoca soruları sırayla okuyup kısa yorumlar yaptı. Bazı sorularda yalnız yöntemi söyledi, sonucu hesaplamadı. Altyazıda soruların tam metni her zaman okunmuyor; okunamayan yerler aşağıda işaretlidir.

### 2.1 Özyinelemeli Dizinin Limiti

İlk soruda özyinelemeli (recursive) tanımlı bir dizinin limiti soruldu. Hocanın kullandığı temel fikir şudur: $a_n$ dizisinin limiti $a$ ise $a_{n+1}$ dizisinin limiti de $a$'dır. Bu yüzden özyineleme bağıntısında $a_n$ ve $a_{n+1}$ yerine $a$ yazılır, çıkan denklem çözülür.

<!-- BELİRSİZ: dizinin bağıntısı altyazıda net değil ("1 artı A bölü 2 artı A", "N artı 3 bölü 2 N artı 1" geçiyor); soru çözülmedi -->

Hoca bunu "basit bir soru sormuşlar" diye geçti.

### 2.2 Eşlenikle Çarpma: $a_n=n-\sqrt{n^2-1}$

Soru, $a_n=n-\sqrt{n^2-1}$ dizisi için verilen ifadelerden (artan, azalan, monoton değil, ıraksak vb.) hangisinin doğru olduğunu soruyor.

$n\to\infty$ iken ifade $\infty-\infty$ belirsizliğindedir. Köklü ifadelerde yaptığımız gibi eşleniği $n+\sqrt{n^2-1}$ ile pay ve payda çarpılır:

$$a_n=\frac{(n-\sqrt{n^2-1})(n+\sqrt{n^2-1})}{n+\sqrt{n^2-1}}=\frac{n^2-(n^2-1)}{n+\sqrt{n^2-1}}=\frac{1}{n+\sqrt{n^2-1}}.$$

Payda sonsuza gittiği için $a_n\to0$ olur. Dizi yakınsaktır ve azalandır. Bu yüzden "limit 1'dir", "artandır", "monoton değildir", "ıraksaktır" ifadeleri yanlıştır; doğru olan "azalandır" ifadesidir.

### 2.3 Geometrik Serilere Ayırma

Soru şu serinin toplamını soruyor:

$$\sum_{n=2}^{\infty}\frac{(-1)^n+2^n+3^n}{4^n}.$$

Hoca seriyi üç geometrik seriye ayırdı. Seri $n=2$'den başladığı için her birinde ilk terim $n=2$ için hesaplanır ve toplam $\dfrac{\text{ilk terim}}{1-\text{ortak çarpan}}$ formülüyle bulunur:

- $\displaystyle\sum_{n=2}^{\infty}\left(-\tfrac14\right)^n$: ilk terim $\tfrac{1}{16}$, ortak çarpan $-\tfrac14$. Toplam $\dfrac{1}{16}\cdot\dfrac{1}{1+\frac14}=\dfrac{1}{20}$.
- $\displaystyle\sum_{n=2}^{\infty}\left(\tfrac12\right)^n$: ilk terim $\tfrac14$, ortak çarpan $\tfrac12$. Toplam $\dfrac14\cdot\dfrac{1}{1-\frac12}=\dfrac12$.
- $\displaystyle\sum_{n=2}^{\infty}\left(\tfrac34\right)^n$: ilk terim $\tfrac{9}{16}$, ortak çarpan $\tfrac34$. Toplam $\dfrac{9}{16}\cdot\dfrac{1}{1-\frac34}=\dfrac94$.

Hoca "toplarsanız zaten çıkar" deyip toplamı söylemedi. Toplam (ara adım eklendi):

$$\frac{1}{20}+\frac{10}{20}+\frac{45}{20}=\frac{56}{20}=\frac{14}{5}.$$

### 2.4 Limit Sorusu

Hoca bir limit sorusunun olduğunu söyledi ("limitin değerini sormuş"), fakat soruyu açmadan geçti.

<!-- BELİRSİZ: limitin ifadesi altyazıda geçmiyor; aşağıdaki ifade kısa nottan alındı -->

Kısa notta bu soru $\displaystyle\lim_{x\to0}\frac{(e^x-x-1)^2}{x^2-\ln(1+x^2)}$ olarak verilmiştir. Çözümü "Örnek Sorular" bölümündedir.

### 2.5 Eşleştirme Sorusu: $\sum a_n$ ve $\sum 1/a_n$

Bu soruda "$\sum a_n$ ıraksak iken $\sum 1/a_n$ ıraksaktır", "$\sum a_n$ ıraksak iken $\sum 1/a_n$ yakınsaktır" gibi ifadeler, verilen genel terimlerle (K, L, M gibi etiketlerle) eşleştiriliyor. Hoca her ifade için şıklardaki terimleri tek tek denedi:

- Genel terimi $1/n^5$ gibi olan bir seri yakınsaktır. Bu yüzden "kendisi ıraksak" şartını sağlamaz; bu eşleşme elendi.
- Genel terimi sonsuza giden bir terimde $\sum a_n$ ıraksaktır. Hocanın denediği bir terimde $\sum 1/a_n$ de ıraksak çıktı; bir başkasında ise $\sum 1/a_n$ yakınsak oldu.
- İki ifade eşleşince üçüncüsü "otomatik olarak" kaldı.

<!-- BELİRSİZ: genel terimlerin tam hâli ve hangi etikete karşılık geldikleri altyazıda okunmuyor -->

### 2.6 Serilerin Karakteri

Bu soruda birkaç serinin yakınsak mı ıraksak mı olduğu soruluyor. Hoca iki gözlemle şıkları eledi:

- Payın derecesi paydanın derecesinden büyükse (örneğin pay $n^2$, payda birinci dereceden) genel terim sıfıra gitmez. Genel terim sıfırdan farklı olduğu için seri ıraksaktır.
- Payda ile pay sadeleştirilince $\dfrac{1}{n^{4/3}}$ gibi bir $p$-serisi çıkıyorsa, $p=\tfrac43>1$ olduğu için seri yakınsaktır.

<!-- BELİRSİZ: serilerin tam ifadeleri altyazıda okunmuyor -->

### 2.7 Hangi Test Kullanılır: $\sum \frac{1}{n(\ln n)^5}$

Soru, $\displaystyle\sum_{n=2}^{\infty}\frac{1}{n(\ln n)^5}$ serisinin karakterini belirlemek için kullanılacak testi ve sonucu soruyor. Hoca $1/n$ ile karşılaştırmanın işe yaramadığını, integral testinin (integral test) mantıklı olduğunu söyledi. Fonksiyon $[2,\infty)$ üzerinde pozitif ve azalandır. Bu yüzden integral yakınsaksa seri de yakınsak, ıraksaksa seri de ıraksaktır.

$u=\ln x$ dönüşümü yapılır, $du=\dfrac{dx}{x}$ olur:

$$\int_2^\infty\frac{dx}{x(\ln x)^5}=\int u^{-5}\,du=\frac{u^{-4}}{-4}=-\frac{1}{4(\ln x)^4}\Bigg|_2^\infty.$$

$x\to\infty$ iken $\ln x\to\infty$ olur ve ilk terim sıfıra gider. Alt sınırdan gelen eksi işaretle artı olur:

$$\int_2^\infty\frac{dx}{x(\ln x)^5}=0-\left(-\frac{1}{4(\ln2)^4}\right)=\frac{1}{4(\ln2)^4}.$$

İntegral sonlu olduğu için seri yakınsaktır. Hoca bu testin soruyu "hemen oturttuğunu" söyledi.

### 2.8 Kuvvet Serisinin Yakınsaklık Aralığı

Hoca yakınsaklık aralığı sorusunun yöntemini hatırlattı. Genel terime $u_n$ denir ve oran testi uygulanır:

$$\lim_{n\to\infty}\left|\frac{u_{n+1}}{u_n}\right|<1.$$

Bu eşitsizlikten $x$ için bir aralık çıkar. Sonra uç noktalar ayrı ayrı seride $x$ yerine konur. Uçta seri yakınsaksa o uç aralığa dahil edilir, ıraksaksa dahil edilmez. Hoca bu soruyu kendisi çözmediğini, öğrencilerin bakabileceğini söyledi.

<!-- BELİRSİZ: kuvvet serisinin ifadesi altyazıda geçmiyor -->

### 2.9 Kutupsal Koordinatta Alan

Bir çemberin içinde ve bir kardiyoidin dışında kalan bölgenin alanını veren integral soruldu. Hoca "direkt integrali sormuşlar, çözüm bile istememişler" dedi.

<!-- BELİRSİZ: çember ve kardiyoidin denklemleri altyazıda geçmiyor -->

### 2.10 Limit ve Süreklilik: $f(x,y)=\frac{5xy^2}{x^2+y^4}$

Soru şu fonksiyon için üç ifadeden hangilerinin doğru olduğunu soruyor:

$$f(x,y)=\begin{cases}\dfrac{5xy^2}{x^2+y^4}, & (x,y)\ne(0,0)\\[4pt] 0, & (x,y)=(0,0)\end{cases}$$

- I. Fonksiyon bütün $\mathbb{R}^2$ üzerinde tanımlıdır.
- II. $(0,0)$ noktasında limit $0$'dır.
- III. $(0,0)$ noktasında süreklidir.

I doğrudur, çünkü $(0,0)$ dışında kural verilmiş, $(0,0)$'da da değer $0$ olarak tanımlanmıştır. Hoca önce "limit 0 ise süreklilik de gelir" diyerek II ve III'ün birlikte doğru ya da birlikte yanlış olacağını söyledi.

Limiti incelemek için önce $y=mx^2$ eğrisi boyunca yaklaşıldı. Bu yolda sonuç $0$ çıkar ve $m$'ye bağlı değildir. Bu, limitin varlığını göstermez. Sonra $x=my^2$ eğrisi boyunca yaklaşıldı:

$$\lim_{y\to0}\frac{5\,my^2\cdot y^2}{m^2y^4+y^4}=\lim_{y\to0}\frac{5m\,y^4}{(m^2+1)y^4}=\frac{5m}{1+m^2}.$$

Sonuç $m$'ye bağlıdır. Farklı eğriler boyunca farklı değerler çıktığı için limit yoktur. Limit olmadığından fonksiyon $(0,0)$'da sürekli de değildir. Yalnız I doğrudur.

> **Hocanın vurgusu:** Bu tip sorulardan 15 tane çözerseniz hangi dönüşümle yaklaşacağınızı hemen görürsünüz.

### 2.11 Diğer Sorular

Hoca kalan soruları hızlıca gösterdi. Alan sorusunu "çok kolay" buldu. Diziler ve seriler kısmında öğrencilerin iyi olduğunu, ama basit sorularda daha dikkatli olmak gerektiğini söyledi. Son sorulardan biri parametrik verilen bir eğrinin $(0,0)$ noktasındaki ikinci türevini soruyordu. Hoca bunun benzerinin derste çözüldüğünü, yalnız fonksiyonun biraz farklı olduğunu söyledi.

<!-- BELİRSİZ: parametrik eğrinin ifadesi altyazıda okunmuyor ("5t artı t, e üzeri t", "t kare eksi 3t" geçiyor) -->

## 3. İki Katlı İntegrale Giriş ve Fubini Teoremleri

### 3.1 Dikdörtgen Bölge: Birinci Fubini Teoremi

Hoca, tek katlı integralle yapılan bir işin iki katlı integralle de yapılabileceğini söyleyerek başladı. Ekranda $x$'lerin $a$'dan $b$'ye, $y$'lerin $c$'den $d$'ye değiştiği bir dikdörtgen $R=[a,b]\times[c,d]$ vardı. Birinci Fubini teoremine göre bu bölge üzerindeki integral iki sırayla da yazılabilir ve aynı sonuç çıkar:

**Birinci Fubini teoremi (dikdörtgen bölge)**

- $R=[a,b]\times[c,d]$ ise
- $\displaystyle\iint_R f(x,y)\,dA=\int_a^b\!\int_c^d f(x,y)\,dy\,dx=\int_c^d\!\int_a^b f(x,y)\,dx\,dy.$

Hesap her zaman içteki integralden başlar. İçteki integral alınırken öteki değişken sabit gibi düşünülür.

$f=1$ alınırsa dikdörtgenin alanı çıkar:

$$\int_a^b\!\int_c^d 1\,dy\,dx=\int_a^b \Big[y\Big]_c^d\,dx=\int_a^b(d-c)\,dx=(d-c)\Big[x\Big]_a^b=(d-c)(b-a).$$

Bu, tabanı $b-a$, yüksekliği $d-c$ olan dikdörtgenin alanıdır.

### 3.2 İki Eğri Arasındaki Bölge: İkinci Fubini Teoremi

İkinci teoremde bölge yukarıdan ve aşağıdan eğrilerle, soldan ve sağdan doğrularla sınırlıdır. Hoca bunu tek katlı integraldeki alan hesabına benzetti: "Üstteki eğriden alttaki eğriyi çıkarırsak aradaki alanı elde ediyoruz. Sağdaki doğrudan soldaki doğruyu çıkarıyoruz."

**İkinci Fubini teoremi (eğriler arası bölge)**

- $D=\{(x,y):\ a\le x\le b,\ \varphi_2(x)\le y\le\varphi_1(x)\}$, burada $y=\varphi_1(x)$ üstteki, $y=\varphi_2(x)$ alttaki eğridir.
- $\displaystyle\iint_D f(x,y)\,dA=\int_a^b\!\int_{\varphi_2(x)}^{\varphi_1(x)} f(x,y)\,dy\,dx.$
- Dıştaki değişkenin sınırları sabittir (doğrular). İçteki değişkenin sınırları dıştaki değişkene bağlı olabilir (eğriler).

### 3.3 Bölge Dönüşümü ve Jacobian (Ön Bilgi)

Üçüncü önemli konu olarak hoca, bölge dönüşümü yapıldığında Jacobian'ın geldiğini söyledi: $x$ ve $y$ değişkenleri $u$ ve $v$ değişkenlerine dönüştürülür, integrale fonksiyonla birlikte bir Jacobian çarpanı eklenir. Ayrıntıyı sonraki haftaya bıraktı.

> **Ek bilgi (derste anlatılmadı):** $x=x(u,v)$, $y=y(u,v)$ dönüşümünde Jacobian $J=\dfrac{\partial(x,y)}{\partial(u,v)}=\begin{vmatrix}x_u & x_v\\ y_u & y_v\end{vmatrix}$ determinantıdır. Bu durumda $\iint_D f(x,y)\,dx\,dy=\iint_{D'} f(x(u,v),y(u,v))\,|J|\,du\,dv$ olur. Kutupsal koordinatlarda $|J|=r$ çıkar.

## 4. Tek Katlı ve İki Katlı İntegralle Alan; Alan ve Hacim Ayrımı

### 4.1 Aynı Alanı İki Yoldan Bulmak

Hoca boş bir tahtada şu örneği çizdi: $y=d$ doğrusunun altında, $x=a$ ile $x=b$ doğruları arasında ve $x$ ekseninin üstünde kalan dikdörtgen bölge.

**Tek katlı integralle:**

$$A=\int_a^b d\,dx=d\Big[x\Big]_a^b=d(b-a).$$

Yüksekliği $d$, tabanı $b-a$ olduğu için bunun alan olduğunu zaten biliyoruz.

**İki katlı integralle:** $x$'ler $a$'dan $b$'ye, $y$'ler $y=0$ doğrusundan $y=d$ doğrusuna değişir.

$$A=\int_a^b\!\int_0^d dy\,dx=\int_a^b\Big[y\Big]_0^d\,dx=\int_a^b(d-0)\,dx=d\Big[x\Big]_a^b=d(b-a).$$

İki yol aynı sonucu verir. Hoca içteki integrali kırmızı kalemle, dıştakini başka renkle yaparak sırayı vurguladı.

### 4.2 İntegrand 1 İse Alan, Değilse Hacim

İşin mantığını anlamak için hoca şu ayrımı yaptı:

- $\displaystyle\iint_D 1\,dA$ bölgenin alanını verir.
- İntegrand 1'den farklı bir $f(x,y)$ fonksiyonu ise (ve $f\ge0$ ise) integral hacmi verir. Taban alanını bölge, yüksekliği fonksiyon verir.

Bunu bir örnekle gösterdi: $\displaystyle\int_1^2\!\int_3^4 x^2y\,dx\,dy$. Bu integral alan değil, hacim verir.

İçte $x$'e göre integral alınır, $y$ sabit gibi düşünülür:

$$\int_3^4 x^2y\,dx=y\left[\frac{x^3}{3}\right]_3^4=y\left(\frac{64}{3}-\frac{27}{3}\right)=\frac{37}{3}\,y.$$

Hoca bu sabit sayıya $A$ dedi ve dıştaki integrali yazdı:

$$\int_1^2 A\,y\,dy=A\left[\frac{y^2}{2}\right]_1^2=A\cdot\frac{4-1}{2}=\frac{37}{3}\cdot\frac32=\frac{37}{2}.$$

Hoca son sayıyı söylemedi, "sınırları koyunca çıkan sonuç bize hacmi veriyor" dedi. Sonuç $\tfrac{37}{2}$ birim küptür (ara adım eklendi).

### 4.3 Çok Katlı İntegralin Kullanım Alanları

Hoca çok katlı integralin uygulamalarını saydı:

- İntegrand 1 ise alan, fonksiyon ise hacim.
- Yoğunluk fonksiyonu konursa kütle.
- Bunlardan ağırlık merkezi.
- Yüzey alanı.

Hoca bir geminin ağırlık merkezini örnek verdi: geminin boyanmasından batmaması için gereken yüzey alanına kadar her şeyde integral hesabı yapılır. Küçük cisimler metreyle ölçülebilir, ama büyük cisimlerde bu mümkün değildir. Bu hesaplar tek katlı integralle değil, iki, üç ya da $n$ değişkenli fonksiyonların integraliyle yapılır.

## 5. Problemler: Eşitliklerin Doğruluğunu Gösteriniz

Hoca ekranda "aşağıdaki eşitliklerin doğruluğunu gösteriniz" başlıklı bir problem listesi açtı, "bu çok önemli" dedi ve öğrencilerden ilkini kendi başlarına yapmalarını istedi. Bir dakika bekledikten sonra çözdü.

### 5.1 Örnek 1: $\int_0^1\!\int_2^4 x^2y\,dy\,dx=2$

Önce $y$'ye göre integral alınır. $x^2$ sabit gibi davranır:

$$\int_2^4 x^2y\,dy=x^2\left[\frac{y^2}{2}\right]_2^4=x^2\left(\frac{16}{2}-\frac{4}{2}\right)=8x^2-2x^2=6x^2.$$

Sonra $x$'e göre:

$$\int_0^1 6x^2\,dx=6\cdot\frac{x^3}{3}\Big|_0^1=2x^3\Big|_0^1=2-0=2.$$

Sonuç 2 birim küptür. Hoca "burada fonksiyon olduğu için bunu hacim olarak görmüş olduk" dedi.

### 5.2 Örnek 2: $\int_0^1\!\int_0^1 \frac{x^2}{1+y^2}\,dy\,dx=\frac{\pi}{12}$

İçte $y$'ye göre integral alınır. $x^2$ sabit olduğu için dışarı çıkar:

$$\int_0^1\frac{x^2}{1+y^2}\,dy=x^2\int_0^1\frac{dy}{1+y^2}=x^2\Big[\arctan y\Big]_0^1.$$

$\arctan 1$, tanjantı 1 olan açıdır, yani $45^\circ=\tfrac{\pi}{4}$. $\arctan0=0$. Bu yüzden içteki integral $\tfrac{\pi}{4}x^2$ olur. Dışta:

$$\frac{\pi}{4}\int_0^1 x^2\,dx=\frac{\pi}{4}\cdot\frac{x^3}{3}\Big|_0^1=\frac{\pi}{4}\cdot\frac13=\frac{\pi}{12}.$$

### 5.3 Örnek 3: $\int_0^\pi\!\int_0^{\sin x} y\,dy\,dx=\frac{\pi}{4}$

Bu örnekte içteki integralin üst sınırı $x$'e bağlıdır. Hoca bu soruyu "ezberleyebilirsiniz" dedi ve tahtada çözdü.

İçte $y$'ye göre:

$$\int_0^{\sin x} y\,dy=\left[\frac{y^2}{2}\right]_0^{\sin x}=\frac{\sin^2x}{2}-0=\frac{\sin^2x}{2}.$$

Böylece iki katlı integral tek katlı integrale düşer:

$$\int_0^\pi\frac{\sin^2x}{2}\,dx.$$

Hoca $\sin^2x=\dfrac{1-\cos2x}{2}$ yazılacağını söyleyip gerisini öğrencilere bıraktı. Devamı (ara adım eklendi):

$$\int_0^\pi\frac{1-\cos2x}{4}\,dx=\frac14\left[x-\frac{\sin2x}{2}\right]_0^\pi=\frac14(\pi-0)=\frac{\pi}{4}.$$

> **Hocanın vurgusu:** Çift katlı integral sonunda tek katlı integrale indirgenerek çözülür. Tek katlı integralde sorunu olan konuları gözden geçirmelidir.

## 6. Bir Bölge Üzerinde İntegral Yazmak

### 6.1 Örnek 4: $f(x,y)=x+y$, $D=\{0\le x\le1,\ 0\le y\le x\}$

İkinci problem grubunda bir fonksiyon ve bir bölge veriliyor, fonksiyonun bu bölge üzerindeki integrali isteniyor. Hoca integrali şöyle kurdu:

- En dışa sabit sınırlı değişken yazılır: $x$, $0$'dan $1$'e değişir, dışta $dx$ vardır.
- İçte $y$, $0$'dan $x$'e değişir, içte $dy$ vardır.
- İntegrand fonksiyonun kendisidir.

$$\iint_D (x+y)\,dA=\int_0^1\!\int_0^x (x+y)\,dy\,dx.$$

Hoca yöntemi anlattı: içte $y$'ye göre integral alınır, $x$ sabit gibi düşünülür. $x$'in integrali $xy$, $y$'nin integrali $\tfrac{y^2}{2}$ olur. Sınırlar konur, sonra $x$'e göre integral alınır. Sonucu hesaplamadı. Hesap (ara adım eklendi):

$$\int_0^x (x+y)\,dy=\left[xy+\frac{y^2}{2}\right]_0^x=x^2+\frac{x^2}{2}=\frac{3x^2}{2},\qquad \int_0^1\frac{3x^2}{2}\,dx=\frac{x^3}{2}\Big|_0^1=\frac12.$$

## 7. İntegrasyon Bölgesini Çizme ve İntegrasyon Sırasını Değiştirme

### 7.1 Soru Tipi

Hoca dördüncü problem grubuna geçerken bunun "hayati öneme sahip" olduğunu söyledi. Soru kalıbı şudur:

- Aşağıdaki integralin integrasyon bölgesini çiziniz.
- İntegrasyon sırasını değiştiriniz.
- Değerini hesaplayınız.

> **Hocanın vurgusu:** Bu tipten mutlaka soru gelir. Hoca bunu İstanbul'dan Sivas'a giderken mutlaka Ankara'dan geçmek gerektiğine benzetti: bu konunun olmazsa olmaz geçiş noktası, "işin ana argümanı"dır.

İntegrasyon sırası, önce hangi değişkene göre integral alındığıdır. $\int\!\!\int \ldots\,dy\,dx$ yazılışında önce $y$'ye, sonra $x$'e göre integral alınır. Bu sıra yer değiştirebilir, ama bunun için bölgeyi görmek gerekir. Sıra değiştirmenin adımları:

- Bölgeyi sınırlardan çiz.
- Sınır eğrilerinin kesim noktalarını bul.
- Yeni dış değişkenin sınırlarını sabit sayılar olarak yaz.
- Yeni iç değişkenin sınırlarını, bölgeyi tarayacak şekilde eğriler cinsinden yaz: "sağdaki eğriden soldakini" ya da "üsttekinden alttakini".

<!-- BELİRSİZ: hoca önce listedeki ilk soruyu "0'dan 1'e kadar, x'den 2x'e kadar" diye okudu; integrand ve tam ifade altyazıda net değil. Tahtada bunun yerine daha basit olan aşağıdaki örneği çözdü. -->

### 7.2 Örnek 5: $\int_0^1\!\int_0^x dy\,dx$

Hoca görmesi kolay olsun diye integrand olarak 1 aldı.

**a) Bölgeyi çizme.** $x$'ler $0$'dan $1$'e, $y$'ler $0$'dan $x$'e değişir. Sınırlar $y=0$ doğrusu ($x$ ekseni), $y=x$ doğrusu ve $x=1$ doğrusudur. Bölge bunların arasında kalan üçgendir:

```
 y
 1 |        /|
   |      /  |
   |    / D  |
   |  /      |
 0 +---------+--- x
   0         1
```

**b) Sırayı değiştirme.** Artık dışa $dy$, içe $dx$ yazılacak. Dıştaki $y$'nin sabit sınırları gerekir. $y=x$ ile $x=1$ doğrularının kesim noktası: $x=1$ konunca $y=1$, yani $(1,1)$. Bu yüzden $y$, $0$'dan $1$'e değişir.

İçteki $x$ bölgeyi taramalıdır. Üst sınır $x=1$ doğrusu, alt sınır $x=y$ doğrusudur. Hoca bunu "$x=1$ doğrusunun altında kalan alandan $x=y$ doğrusunun altındaki alanı çıkarıyoruz" diye anlattı:

$$\int_0^1\!\int_0^x dy\,dx=\int_0^1\!\int_y^1 dx\,dy.$$

**c) Değeri hesaplama.** Hoca iki yoldan da hesaplayıp aynı sonucu gösterdi:

- İlk sıra: $\displaystyle\int_0^x dy=x$, sonra $\displaystyle\int_0^1 x\,dx=\frac{x^2}{2}\Big|_0^1=\frac12$.
- Yeni sıra: $\displaystyle\int_y^1 dx=1-y$, sonra $\displaystyle\int_0^1(1-y)\,dy=\left[y-\frac{y^2}{2}\right]_0^1=\frac12$ (son adım eklendi).

Sonuç $\tfrac12$ birim karedir; bu üçgenin alanıdır.

### 7.3 Örnek 6: Elips Bölgesi

Listedeki başka bir soruda sınırlar şöyleydi: $x$, $0$'dan $\sqrt2$'ye; $y$, $-\sqrt{4-2x^2}$'den $\sqrt{4-2x^2}$'ye.

$$\int_0^{\sqrt2}\!\int_{-\sqrt{4-2x^2}}^{\sqrt{4-2x^2}} (\ldots)\,dy\,dx$$

<!-- BELİRSİZ: integrand altyazıda okunmuyor -->

**a) Bölgeyi çizme.** Sınır eğrisi $y=\pm\sqrt{4-2x^2}$'dir. Her iki tarafın karesi alınır:

$$y^2=4-2x^2\ \Rightarrow\ 2x^2+y^2=4\ \Rightarrow\ \frac{x^2}{2}+\frac{y^2}{4}=1\ \Rightarrow\ \frac{x^2}{(\sqrt2)^2}+\frac{y^2}{2^2}=1.$$

Bu bir elipstir. $x$ eksenini $\pm\sqrt2$'de, $y$ eksenini $\pm2$'de keser. $x$, $0$ ile $\sqrt2$ arasında olduğu için bölge elipsin sağ yarısıdır. Üstteki $+\sqrt{4-2x^2}$ üst sınır, alttaki $-\sqrt{4-2x^2}$ alt sınırdır.

> **Ders sonrası not:** Hoca bir yerde elipsin $y$ eksenini "4'te kestiğini" söyledi; doğrusu $\pm2$'dir. Hoca birkaç cümle sonra sınırları zaten $-2$ ve $+2$ olarak kullandı.

**b) Sırayı değiştirme.** Dışa $y$ yazılır. Elipsin $y$ eksenini kestiği yerler $x=0$ konarak bulunur: $y^2=4$, yani $y=\pm2$. Bu yüzden $y$, $-2$'den $2$'ye değişir. İçteki $x$, $x=0$ doğrusundan elipsin sağ yayına kadar değişir. Elips denkleminden $x$ çekilir:

$$2x^2=4-y^2\ \Rightarrow\ x=\sqrt{\frac{4-y^2}{2}}.$$

$$\int_{-2}^{2}\!\int_0^{\sqrt{(4-y^2)/2}} (\ldots)\,dx\,dy.$$

Hoca ayrıca, bölge $x$ eksenine göre simetrik olduğu için üst yarıyı hesaplayıp iki katını almanın yeteceğini söyledi.

<!-- BELİRSİZ: hoca "3 tane parça almamız lazım" dedi; neyi kastettiği altyazıda net değil -->

İntegrand 1 alınırsa iki sıra da elipsin yarı alanını, yani $\tfrac12\pi\cdot\sqrt2\cdot2=\sqrt2\,\pi$ değerini verir (python ile doğrulandı). Derste değer hesaplanmadı.

## 8. Sıra Değiştirmek Neden Gerekli?

### 8.1 Örnek 7: $e^{y^2}$ İçeren İntegral

Hoca sıra değiştirmenin nerede işe yaradığını bir örnekle gösterdi. İntegrand $e^{y^2}$, bölge $0\le x\le1$, $0\le y\le x$ olarak yazıldı:

$$\int_0^1\!\int_0^x e^{y^2}\,dy\,dx.$$

Bu sırayla integral alınamaz, çünkü $e^{y^2}$'nin $y$'ye göre ilkeli (integrali) elementer fonksiyonlarla bulunamaz. Hoca "integrandın yanında $y$ olsaydı, türevi burada var deyip $e^{u}$ ile çözerdik, ama yok" dedi. Bu yüzden sıra değiştirilir.

Bölge Örnek 5'teki üçgendir. Hoca dışa $y$'yi ($0$'dan $1$'e), içe $x$'i yazdı. İç sınırları "$x=1$ doğrusunun altındaki alandan $x=y$ doğrusunun altındakini çıkarıyoruz" diye kurdu. Sonra iç integral alınınca $x$ geleceğini, sınırlar konunca bir $y$ çarpanı oluşacağını, $u=y^2$ denince türevin integralde bulunacağını ve integralin kolaylaşacağını söyledi.

> **Ders sonrası not:** Tahtadaki bölge ($0\le y\le x$) ile hocanın vardığı sonuç uyuşmuyor. Bu bölgede sıra değişince $\displaystyle\int_0^1\!\int_y^1 e^{y^2}\,dx\,dy=\int_0^1(1-y)\,e^{y^2}\,dy$ çıkar. Bu integralde $e^{y^2}$ terimi yine elementer olarak alınamaz (python ile değeri yaklaşık $0{,}6035$ bulundu, ancak kapalı biçim hata fonksiyonu türünden bir terim içerir). Hocanın anlattığı "$y$ çarpanı gelir, $u=y^2$ ile çözülür" yolu, sınırları $x\le y\le1$ olan standart örnekte işler:
> $$\int_0^1\!\int_x^1 e^{y^2}\,dy\,dx=\int_0^1\!\int_0^y e^{y^2}\,dx\,dy=\int_0^1 y\,e^{y^2}\,dy=\frac{e^{y^2}}{2}\Big|_0^1=\frac{e-1}{2}.$$
> Tahtadaki sınırların büyük olasılıkla bu standart örnek için düşünüldüğü, ama yanlış yazıldığı anlaşılıyor.

> **Hocanın vurgusu:** İntegrasyon sırasını değiştirmek, integrali alınamayan fonksiyonlarda işimize yarar. Bu yüzden çok önemlidir.

### 8.2 Listedeki Benzer Soru

Dersin sonunda hoca ekrandaki çözümlü listeden bir soruyu daha gösterdi:

$$I=\int_{-1}^{0}\!\int_{-y}^{1} e^{x^2}\,dx\,dy.$$

Burada da $e^{x^2}$'nin $x$'e göre ilkeli elementer değildir. Hoca "bu teknikler bize yeni bir bakış açısı kazandırıyor" dedi, çözümü ayrıntılı vermedi. Çözüm "Örnek Sorular" bölümündedir.

## Örnek Sorular

Bu derste kare yoktur. Aşağıdaki sorular derste ekranda okunan ya da tahtada çözülen sorulardır. Ayrıntılı çözümler yukarıdaki bölümlerdedir. Soru metni altyazıdan tam çıkmayanlar bu listeye alınmadı.

- **Soru 1** (derste sözlü, 00:02:48). $a_n=n-\sqrt{n^2-1}$ dizisi için hangisi doğrudur: limiti 1'dir, artandır, azalandır, monoton değildir, ıraksaktır?
  - Cevap: $a_n=\dfrac{1}{n+\sqrt{n^2-1}}\to0$; dizi azalandır.
- **Soru 2** (derste sözlü, 00:03:42). $\displaystyle\sum_{n=2}^{\infty}\frac{(-1)^n+2^n+3^n}{4^n}$ serisinin toplamı?
  - Cevap: $\dfrac{1}{20}+\dfrac12+\dfrac94=\dfrac{14}{5}$.
- **Soru 3** (derste sözlü, 00:05:30). Limit sorusu. <!-- BELİRSİZ: ifade altyazıda geçmiyor; kısa nottan alındı -->
  $\displaystyle\lim_{x\to0}\frac{(e^x-x-1)^2}{x^2-\ln(1+x^2)}$
  > **Çözüm (derste verilmedi):** $e^x-x-1=\dfrac{x^2}{2}+O(x^3)$ olduğundan pay $\dfrac{x^4}{4}+O(x^5)$ olur. $\ln(1+x^2)=x^2-\dfrac{x^4}{2}+O(x^6)$ olduğundan payda $\dfrac{x^4}{2}+O(x^6)$ olur. Limit $\dfrac{1/4}{1/2}=\dfrac12$ (sympy ile doğrulandı).
- **Soru 4** (derste sözlü, 00:10:30). $\displaystyle\sum_{n=2}^{\infty}\frac{1}{n(\ln n)^5}$ serisinin karakteri ve kullanılacak test?
  - Cevap: integral testi; $\displaystyle\int_2^\infty\frac{dx}{x(\ln x)^5}=\frac{1}{4(\ln2)^4}$ sonlu, seri yakınsak.
- **Soru 5** (derste sözlü, 00:15:13). $f(x,y)=\dfrac{5xy^2}{x^2+y^4}$, $f(0,0)=0$. I. $\mathbb{R}^2$'de tanımlı; II. $(0,0)$'da limit 0; III. $(0,0)$'da sürekli. Hangileri doğru?
  - Cevap: $x=my^2$ boyunca limit $\dfrac{5m}{1+m^2}$, $m$'ye bağlı; limit yok, sürekli değil. Yalnız I doğru.
- **Soru 6** (derste sözlü, 00:44:30). $\displaystyle\int_1^2\!\int_3^4 x^2y\,dx\,dy$.
  - Cevap: $\dfrac{37}{3}\cdot\dfrac32=\dfrac{37}{2}$ birim küp (sayı derste söylenmedi; sympy ile hesaplandı).
- **Soru 7** (derste sözlü, 00:51:34). $\displaystyle\int_0^1\!\int_2^4 x^2y\,dy\,dx=2$ olduğunu gösteriniz.
  - Cevap: iç integral $6x^2$, dış integral $2$.
- **Soru 8** (derste sözlü, 00:56:12). $\displaystyle\int_0^1\!\int_0^1 \frac{x^2}{1+y^2}\,dy\,dx=\frac{\pi}{12}$ olduğunu gösteriniz.
  - Cevap: iç integral $\tfrac{\pi}{4}x^2$, dış integral $\tfrac{\pi}{12}$.
- **Soru 9** (derste sözlü, 00:58:31). $\displaystyle\int_0^\pi\!\int_0^{\sin x} y\,dy\,dx=\frac{\pi}{4}$ olduğunu gösteriniz.
  - Cevap: iç integral $\tfrac{\sin^2x}{2}$, dış integral $\tfrac{\pi}{4}$.
- **Soru 10** (derste sözlü, 01:01:25). $f(x,y)=x+y$ fonksiyonunun $0\le x\le1$, $0\le y\le x$ bölgesi üzerindeki integrali.
  - Cevap: $\displaystyle\int_0^1\!\int_0^x (x+y)\,dy\,dx=\frac12$ (sonuç derste hesaplanmadı; sympy ile doğrulandı).
- **Soru 11** (derste sözlü, 01:05:59). $\displaystyle\int_0^1\!\int_0^x dy\,dx$ için bölgeyi çiziniz, sırayı değiştiriniz, değerini hesaplayınız.
  - Cevap: $\displaystyle\int_0^1\!\int_y^1 dx\,dy=\frac12$.
- **Soru 12** (derste sözlü, 01:11:09). $x$, $0$'dan $\sqrt2$'ye; $y$, $-\sqrt{4-2x^2}$'den $\sqrt{4-2x^2}$'ye sınırlı integralde bölgeyi çiziniz ve sırayı değiştiriniz. <!-- BELİRSİZ: integrand okunmuyor -->
  - Cevap: bölge $\tfrac{x^2}{2}+\tfrac{y^2}{4}=1$ elipsinin sağ yarısı; yeni sınırlar $-2\le y\le2$, $0\le x\le\sqrt{(4-y^2)/2}$.
- **Soru 13** (derste sözlü, 01:26:36). $\displaystyle I=\int_{-1}^{0}\!\int_{-y}^{1} e^{x^2}\,dx\,dy$.
  > **Çözüm (derste verilmedi):** Bölge $-1\le y\le0$, $-y\le x\le1$'dir. Sınır doğruları $x=-y$, $x=1$ ve $y=0$; köşeleri $(0,0)$, $(1,0)$, $(1,-1)$ olan üçgendir. Sıra değişince $x$, $0$'dan $1$'e; $y$, $-x$'ten $0$'a değişir:
  > $$I=\int_0^1\!\int_{-x}^{0} e^{x^2}\,dy\,dx=\int_0^1 x\,e^{x^2}\,dx=\frac{e^{x^2}}{2}\Big|_0^1=\frac{e-1}{2}.$$
  > Sonuç sympy ile doğrulandı.

## Dersin Toparlaması

Dersin ilk kısmında 1. vize soruları üzerinden diziler, geometrik seriler, yakınsaklık testleri, kuvvet serisi, kutupsal alan ve çok değişkenli limit tekrar edildi. Hoca soruların elementer olduğunu, ama içine çeldiriciler konduğunu, basit sorularda daha dikkatli olmak gerektiğini söyledi.

İkinci kısımda iki katlı integrale giriş yapıldı. Fubini teoremiyle dikdörtgen ve eğriler arası bölgelerde integralin iki tek katlı integrale ayrıldığı görüldü. İçteki integral alınırken öteki değişken sabit tutulur. İntegrand 1 ise sonuç alan, fonksiyon ise hacimdir. Bölge üzerinde integral yazılırken dıştaki değişkenin sınırları sabit sayılar, içtekinin sınırları eğrilerdir. İntegrasyon sırasını değiştirmek için bölge çizilir, kesim noktaları bulunur ve sınırlar yeniden yazılır. Bu teknik, $e^{y^2}$ gibi ilkeli elementer olmayan fonksiyonlarda integrali alınabilir hâle getirir.

Hoca tek katlı integral bilgisi eksik olanların tekrar etmesini, kendi başına soru çözmenin verimi "%50'den %99'a" çıkaracağını söyledi. Bir sonraki derste Jacobian ve bölge dönüşümlerine geçilecek. Hocanın tahminine göre integral konusu iki haftada biter, sonra genel soru çözümü yapılır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
