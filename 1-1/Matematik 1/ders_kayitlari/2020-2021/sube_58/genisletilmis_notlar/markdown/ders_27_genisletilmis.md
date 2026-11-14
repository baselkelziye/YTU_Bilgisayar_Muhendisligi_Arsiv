# Ders 27 Genişletilmiş Notu: Yay Uzunluğu, Dönel Yüzey Alanı ve Has Olmayan İntegraller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Yay Uzunluğu
- 3. Dönel Yüzey Alanı
- 4. Birinci Tip Has Olmayan İntegraller
- 5. İkinci Tip Has Olmayan İntegraller
- 6. Genel Alıştırma: $x=y^2$ ve $y-x=-2$ Bölgesi
- 7. Simetrik Bölgenin $x$ Ekseni Etrafında Döndürülmesi
- 8. Geçmiş Yıl Sorusu: $y=2/x$ Bölgesi
- 9. Örnek Sorular
- 10. Dersin Toparlaması

## 1. Dersin Planı

Ders, dönemin son haftasında yapıldı. Hoca önceki hafta kabuk yönteminin (shell method) işlendiğini hatırlattı. Bu derste iki uygulama kaldığını söyledi: eğrilerin yay uzunluğu (arc length) ve dönel cisimlerin yüzey alanı (surface area of revolution). Bunlardan sonra has olmayan integraller (improper integrals) anlatılacak ve konular bitecekti. Dersin ikinci yarısı, alan ve hacim yöntemlerini bir arada kullanan genel alıştırmalara ayrıldı. Hoca bir sonraki derste geçmiş yılların sorularını çözüp analiz edeceklerini de söyledi.

## 2. Yay Uzunluğu

### 2.1 Felsefi Başlangıç: Nokta Nedir?

Hoca konuya bir gözlemle başladı: Noktanın kesin bir tanımı yoktur. Bu yüzden bir noktayı yeterince küçük herhangi bir nesne olarak düşünebiliriz. Örneğin yeterince küçük bir dik üçgen olarak. Bir eğri de düzlemdeki sonsuz sayıda, yeterince küçük noktanın birleşimidir.

$[a,b]$ aralığında sürekli bir $y=f(x)$ eğrisi alalım. Amacımız bu eğrinin toplam uzunluğu $L$'yi bulmak. Eğriyi oluşturan çok küçük bir parçayı dik üçgen olarak düşünürsek, dik kenarlarından biri $dx$, diğeri $dy$ olur. Hipotenüse $dL$ diyelim. Pisagor teoreminden:

$$dL=\sqrt{dx^2+dy^2}$$

### 2.2 Formülün Düzenlenmesi

$y$, $x$'e bağlı olduğu için $y$'nin $x$'e göre türevinden söz edebiliriz. Bu yüzden kök içinde $dx^2$ ortak paranteze alınır. $dx$ pozitif kabul edildiğinden kökün dışına aynen çıkar:

$$dL=\sqrt{1+\left(\frac{dy}{dx}\right)^2}\,dx$$

Eğer $x$, $y$'ye bağlı olsaydı ($x=g(y)$), bu kez kök içinde $dy^2$ ortak paranteze alınırdı.

Sonsuz sayıdaki $dL$ parçası $a$'dan $b$'ye integrallenince eğrinin toplam uzunluğu elde edilir:

**Tanım (Yay uzunluğu)**

- $y=f(x)$, $[a,b]$ aralığında türevlenebilir olsun.
- Eğrinin bu aralıktaki uzunluğu: $L=\displaystyle\int_a^b\sqrt{1+[f'(x)]^2}\,dx$.
- $x=g(y)$, $c\le y\le d$ biçimindeki eğri için: $L=\displaystyle\int_c^d\sqrt{1+[g'(y)]^2}\,dy$.

> **Hocanın vurgusu:** Yay uzunluğu formülü Pisagor teoreminden başka bir şey değildir. Eğriyi oluşturan küçük noktayı dik üçgen olarak düşünürseniz formülü 5 saniyede bulursunuz. Formülü ezberlemeyin, mantığını anlayın.

**Soru:** Kök, yalnız $dy/dx$ için mi, yoksa ifadenin tamamı için mi? **Cevap:** Kök ifadenin tamamını kapsar. $dx$ küçük bir pozitif sayıdır; $dx^2$ ortak paranteze alınıp kökün dışına $dx$ olarak çıkarılır.

### 2.3 Örnek 1: $y=x^{3/2}$ Eğrisinin $[0,1]$ Aralığındaki Uzunluğu

Hoca grafiği bilmesek de formülü uygulayabileceğimizi söyledi. Formülü hatırlamak için önce $dL=\sqrt{dx^2+dy^2}$ yazıp $dx^2$'yi ortak paranteze almak yeterli.

- Türev: $f'(x)=\dfrac32\sqrt{x}$. Karesi: $[f'(x)]^2=\dfrac94x$.
- Yay elemanı: $dL=\sqrt{1+\dfrac94x}\,dx=\dfrac{\sqrt{4+9x}}{2}\,dx$.
- Uzunluk:

$$L=\int_0^1\frac{\sqrt{4+9x}}{2}\,dx$$

- Yerine koyma (substitution): $u=4+9x$, $du=9\,dx$, yani $dx=\frac19du$. Sınırlar: $x=0\Rightarrow u=4$, $x=1\Rightarrow u=13$.

$$L=\frac{1}{18}\int_4^{13}\sqrt{u}\,du=\frac{1}{18}\cdot\frac23\left[u^{3/2}\right]_4^{13}=\frac{1}{27}\left(13^{3/2}-4^{3/2}\right)=\frac{13\sqrt{13}-8}{27}$$

Hoca sonucu $\frac1{18}\cdot\frac23\left(13^{3/2}-4^{3/2}\right)$ olarak bırakıp sadeleştirmeyi öğrencilere bıraktı. Son sadeleştirme adımı eklendi (ara adım eklendi).

> **Ders sonrası not:** Altyazıda üst sınır bir yerde "30" diye geçiyor. Doğrusu $u=4+9\cdot1=13$'tür. Hoca da sonucu $13^{3/2}-4^{3/2}$ ile yazıyor; "30" büyük olasılıkla altyazı hatasıdır.

> **Hocanın vurgusu:** Önemli olan mantığı anlamak. Daha karmaşık örnekler de çözülecek; ama bu problemin arkasındaki fikri anlamak çok önemli.

## 3. Dönel Yüzey Alanı

### 3.1 Formülün Çıkarılışı

Bu kez bir bölge değil, bir eğri döndürülüyor. $y=f(x)$ eğrisi $x$ ekseni etrafında döndürülsün. Oluşan yüzeyin alanını bulmak istiyoruz.

Eğri üzerinde uzunluğu $dL$ olan yeterince küçük bir doğru parçası alalım. $dL$ çok küçük olduğundan bu parçayı $x$ eksenine paralel kabul edebiliriz. $dL$ parçası $x$ ekseni etrafında döndürülünce bir silindir yüzeyi oluşur. Silindirin yarıçapı, noktanın $x$ eksenine uzaklığı olan $y=f(x)$, yüksekliği ise $dL$'dir.

Bu silindir yüzeyini kesip açarsak bir dikdörtgen elde ederiz. Dikdörtgenin bir kenarı silindirin çevresi $2\pi f(x)$, diğer kenarı $dL$'dir. Bu küçük yüzey parçasının alanına $dS$ dersek:

$$dS=2\pi f(x)\,dL$$

$dL$'yi Pisagor teoreminden zaten biliyoruz. $a$'dan $b$'ye integrallenince formül çıkar.

**Tanım (Dönel yüzey alanı, $x$ ekseni etrafında)**

- $y=f(x)$, $a\le x\le b$ eğrisi $x$ ekseni etrafında döndürülsün.
- Yüzey alanı: $S=\displaystyle\int_a^b2\pi f(x)\sqrt{1+[f'(x)]^2}\,dx$.

<!-- BELİRSİZ: 00:16:26-00:16:51 arasında altyazı tekrar döngüsüne giriyor ("bu noktada var"). Bu aralıkta tahtaya çizilen şekil ve söylenenler altyazıdan okunmuyor; anlatım hocanın sonraki cümlelerinden kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Fonksiyon negatif değerler alıyorsa yarıçap $|f(x)|$ olarak alınır, çünkü yarıçap bir uzaklıktır. Derste yalnız $f(x)\ge0$ olan eğriler kullanıldı.

### 3.2 Örnek 2: $y=\sqrt{x}$, $0\le x\le1$ Eğrisinin Döndürülmesiyle Oluşan Yüzey

$y=\sqrt{x}$ eğrisi $x$ ekseni etrafında döndürülüyor; oluşan yüzeyin alanı soruluyor.

- $f(x)=\sqrt{x}$, $f'(x)=\dfrac{1}{2\sqrt{x}}$, $[f'(x)]^2=\dfrac{1}{4x}$.
- Formül:

$$S=\int_0^1 2\pi\sqrt{x}\sqrt{1+\frac{1}{4x}}\,dx$$

- $\sqrt{x}$ kökün içine dağıtılır: $\sqrt{x\left(1+\frac1{4x}\right)}=\sqrt{x+\frac14}=\dfrac{\sqrt{4x+1}}{2}$.

$$S=2\pi\int_0^1\frac{\sqrt{4x+1}}{2}\,dx=\pi\int_0^1\sqrt{4x+1}\,dx$$

- Yerine koyma: $u=4x+1$, $dx=\frac14du$, sınırlar $u:1\to5$.

$$S=\frac{\pi}{4}\int_1^5\sqrt{u}\,du=\frac{\pi}{4}\cdot\frac23\left(5^{3/2}-1\right)=\frac{\pi}{6}\left(5\sqrt5-1\right)$$

Hoca son integrali ödev olarak bıraktı. Son iki adım ve sonuç bu notta hesaplandı (ara adım eklendi).

> **Ders sonrası not:** Hoca dağıtımı yaparken önce "$x+4$ bölü 2" dedi, hemen ardından "burası $4x+1$ olacak" diye düzeltti. Doğrusu $\frac{\sqrt{4x+1}}{2}$'dir.

**Soru:** (Sohbet penceresinden) Bu bir hacim hesabı mı? **Cevap:** Hayır. Hacim hesaplamıyoruz; dönel yüzeyin alanını hesaplıyoruz.

> **Hocanın vurgusu:** Formülü unutsanız bile nasıl çıkaracağınızı biliyorsunuz. Silindirin yüzey alanından yola çıkıp formülü kısa sürede yeniden kurabilirsiniz.

## 4. Birinci Tip Has Olmayan İntegraller

> **Hocanın vurgusu:** Her tipin arkasındaki felsefeyi anlamak çok önemli.

### 4.1 Tanım ve Sezgi

Birinci tipte $f$, sınırsız (unbounded) bir aralıkta sürekli bir fonksiyondur. Aralık $[a,\infty)$, $(-\infty,a]$ ya da $(-\infty,\infty)$ olabilir.

Örneğin $\displaystyle\int_a^{\infty}f(x)\,dx$ integralini düşünelim. Hoca bunu sonsuz bir toplam gibi düşünmemizi istedi. Merak ettiğimiz soru şudur: Bu toplam sonlu bir değere yakınsar mı (converge), yoksa ıraksar mı (diverge)?

Hesap şöyle yapılır. Sayı doğrusunda $a$'nın sağına değişken bir $b$ noktası konur. Önce $[a,b]$ üzerinde integral hesaplanır. $f$ bu kapalı aralıkta sürekli olduğu için bu integral vardır. Sonra $b\to\infty$ limiti alınır.

**Tanım (1. tip has olmayan integral)**

- $\displaystyle\int_a^{\infty}f(x)\,dx=\lim_{b\to\infty}\int_a^b f(x)\,dx$.
- $\displaystyle\int_{-\infty}^{a}f(x)\,dx=\lim_{b\to-\infty}\int_b^a f(x)\,dx$.
- Limit varsa (sonlu bir sayıysa) has olmayan integral **yakınsaktır** (convergent). Aksi halde **ıraksaktır** (divergent).
- $\displaystyle\int_{-\infty}^{\infty}f(x)\,dx=\int_{-\infty}^{a}f(x)\,dx+\int_a^{\infty}f(x)\,dx$. Burada $a$ uygun bir gerçel sayıdır; seçimi problemin yapısına bağlıdır.
- Sağdaki iki integralin ikisi de yakınsaksa $\displaystyle\int_{-\infty}^{\infty}f\,dx$ yakınsaktır. Biri bile ıraksaksa ıraksaktır.

> **Hocanın vurgusu:** Fonksiyonun yakınsaklığından değil, integralin yakınsaklığından bahsediyoruz. İntegrali önce limit olarak ifade edin. Limitin var olduğunu gösterirseniz integral yakınsaktır, limit yoksa ıraksaktır.

### 4.2 Örnek 3: $y=\dfrac{1}{x^2+1}$ Altındaki Sınırsız Bölgenin Alanı

Soru: $y=\dfrac1{x^2+1}$ grafiğinin altında, $x$ ekseninin üstünde kalan sınırsız bölgenin alanını hesaplayın.

Bu bölgenin alanı $\displaystyle\int_{-\infty}^{\infty}\frac{dx}{x^2+1}$ has olmayan integraliyle ifade edilir. Fonksiyon çifttir (even) ve integral aralığı simetriktir. Bu yüzden integral $0$'dan $\infty$'a olan integralin iki katıdır:

$$A=\int_{-\infty}^{\infty}\frac{dx}{x^2+1}=2\int_0^{\infty}\frac{dx}{x^2+1}=2\lim_{a\to\infty}\int_0^{a}\frac{dx}{x^2+1}$$

$\frac{1}{x^2+1}$'in ters türevi $\arctan x$'tir:

$$A=2\lim_{a\to\infty}\left(\arctan a-\arctan 0\right)=2\cdot\frac{\pi}{2}=\pi$$

$a\to\infty$ iken $\arctan a\to\frac{\pi}{2}$ olduğu için sonuç $\pi$'dir. İntegral yakınsaktır.

**İstatistik bağlantısı.** Hoca bu tür fonksiyonların istatistikte çok önemli olduğunu söyledi. Fonksiyonu $\dfrac{1}{\pi(x^2+1)}$ olarak yazsaydık integral $1$ çıkacaktı. Altındaki toplam alan $1$ olan böyle bir fonksiyon, bir rastgele değişkenin (random variable) yoğunluk fonksiyonu (density function) olur. Hoca bunların ileride istatistik dersinde sık kullanılacağını söyledi.

> **Ders sonrası not:** Hoca $\dfrac1{\pi(x^2+1)}$ için "çan eğrisi" dedi. Bu yoğunluk büyük olasılıkla Cauchy dağılımı olarak bilinir; "çan eğrisi" adı genellikle normal dağılım için kullanılır. Ayrıca hoca yoğunluk fonksiyonunun değerlerinin $0$ ile $1$ arasında değişeceğini söyledi. Bu genel olarak doğru değildir: Yoğunluk fonksiyonunun negatif olmaması ve altındaki toplam alanın $1$ olması gerekir; fonksiyonun değeri $1$'i aşabilir.

### 4.3 Örnek 4: $\displaystyle\int_0^{\infty}x e^{-x}\,dx$

Hoca bu soruyu herkesin kendi başına çözmesini istedi ve birkaç dakika bekledi. Birkaç öğrenci integrali limit problemine dönüştürdüğünü, integrali hesaplamaya çalıştığını söyledi. Ardından hoca soruyu birlikte çözdü.

- Limit problemi: $\displaystyle\int_0^{\infty}x e^{-x}\,dx=\lim_{a\to\infty}\int_0^{a}x e^{-x}\,dx$.
- Belirsiz integral kısmi integrasyonla (integration by parts) bulunur: $u=x$, $dv=e^{-x}dx$ alınırsa $du=dx$, $v=-e^{-x}$ (ara adım eklendi).

$$\int x e^{-x}\,dx=-xe^{-x}+\int e^{-x}\,dx=-xe^{-x}-e^{-x}+C=-e^{-x}(x+1)+C$$

- Sınırlar yerleştirilir (temel teoremin 2. kısmı):

$$\lim_{a\to\infty}\left[-e^{-x}(x+1)\right]_0^a=\lim_{a\to\infty}\left[-e^{-a}(a+1)+1\right]=1-\lim_{a\to\infty}\frac{a+1}{e^{a}}$$

- Son limit $\frac{\infty}{\infty}$ belirsizliğidir. L'Hôpital kuralıyla pay ve paydanın türevi alınır: $\displaystyle\lim_{a\to\infty}\frac{1}{e^a}=0$.
- Sonuç: $\displaystyle\int_0^{\infty}x e^{-x}\,dx=1$. İntegral yakınsaktır.

<!-- BELİRSİZ: 00:45:37-00:46:11 arasında altyazı tekrar döngüsüne giriyor ("İnteklisi"). Kısmi integrasyonun tahtadaki ara adımları altyazıdan okunmuyor; hoca 00:46:11'de belirsiz integralin sonucunu $-e^{-x}(1+x)$ olarak söylüyor. -->

Hoca bu sonucun anlamını da söyledi: $x e^{-x}$ eğrisinin $0$'dan sonsuza altında kalan bölgenin alanı $1$'dir. Bu fonksiyon da ileride bir olasılık yoğunluk fonksiyonu (probability density function) olarak karşımıza çıkacak.

## 5. İkinci Tip Has Olmayan İntegraller

### 5.1 Tanım

İkinci tipte aralık sınırlıdır ama $f$, bu aralıkta bir noktada süreksizdir (discontinuous). Hoca üç durum ayırdı.

**Durum 1: Süreksizlik sağ uçta ($b$'de).** Araya bir $t$ noktası konur. $f$, $[a,t]$ üzerinde sürekli olduğu için bu aralıktaki integral kolayca hesaplanır. Sonra $t$ soldan $b$'ye yaklaştırılır.

**Durum 2: Süreksizlik sol uçta ($a$'da).** Bu kez $[t,b]$ üzerinde integral hesaplanır. $f$ bu aralıkta süreklidir. Sonra $t$ sağdan $a$'ya yaklaştırılır.

**Durum 3: Süreksizlik iç noktada ($c$'de).** İki değişken konur: $t_1$ soldan $c$'ye, $t_2$ sağdan $c$'ye yaklaşır. İntegral iki limitin toplamı olarak yazılır.

**Tanım (2. tip has olmayan integral)**

- $f$, $b$'de süreksiz: $\displaystyle\int_a^b f(x)\,dx=\lim_{t\to b^-}\int_a^t f(x)\,dx$.
- $f$, $a$'da süreksiz: $\displaystyle\int_a^b f(x)\,dx=\lim_{t\to a^+}\int_t^b f(x)\,dx$.
- $f$, $a<c<b$ noktasında süreksiz: $\displaystyle\int_a^b f(x)\,dx=\lim_{t_1\to c^-}\int_a^{t_1} f(x)\,dx+\lim_{t_2\to c^+}\int_{t_2}^{b} f(x)\,dx$.
- Limit (ya da üçüncü durumda iki limitin her biri) varsa integral yakınsak, yoksa ıraksaktır.

> **Ek bilgi (derste anlatılmadı):** Üçüncü durumda iki limitin her biri ayrı ayrı var olmalıdır. Biri bile yoksa integral ıraksaktır; iki limiti tek bir değişkenle birlikte almak ($t_1$ ve $t_2$'yi eşit uzaklıkta tutmak) genel olarak doğru sonuç vermez.

Hoca konuyu "mantığı gayet güzel, kolay bir konu" diye özetledi ve 15 dakikalık aradan sonra bir örnekle devam etti.

### 5.2 Örnek 5: $\displaystyle\int_1^{e}\frac{dx}{x\ln x}$

$x=1$ değeri integrandda yerine konunca $\ln1=0$ olduğundan payda sıfır olur; fonksiyon $x=1$'de tanımsızdır. Bu yüzden integral 2. tip has olmayan integraldir. Süreksizlik alt sınırda olduğu için alt sınıra değişken bir $a$ konur:

$$\int_1^{e}\frac{dx}{x\ln x}=\lim_{a\to1^+}\int_a^{e}\frac{dx}{x\ln x}$$

- Belirsiz integral: $u=\ln x$ dersek $du=\dfrac{dx}{x}$ olur.

$$\int\frac{dx}{x\ln x}=\int\frac{du}{u}=\ln|u|+C=\ln|\ln x|+C$$

- Sınırlar yerleştirilir. Üst sınırda $\ln(\ln e)=\ln1=0$:

$$\lim_{a\to1^+}\left[0-\ln(\ln a)\right]=-\lim_{a\to1^+}\ln(\ln a)$$

- Hoca $\ln$ grafiğini hatırlattı: $a\to1^+$ iken $\ln a\to0^+$. $\ln$ fonksiyonu sıfıra sağdan yaklaşırken $-\infty$'a gider. Yani $\ln(\ln a)\to-\infty$.
- Sonuç: $-(-\infty)=+\infty$. Limit sonlu değildir; integral **ıraksaktır**.

### 5.3 Örnek 6: $\displaystyle\int_0^{1}\frac{dx}{x(1+\ln^2x)}$

Hoca önce bunun alışıldık bir integral olmadığını, çünkü integrandın integral aralığında bir süreksizliği olduğunu söyledi. Süreksizlik noktası $x=0$'dır. Herkesin çözmesi için birkaç dakika bekledi ve sordu: İntegral yakınsak mı, ıraksak mı? Yakınsaksa hangi değere yakınsar?

**Soru:** (Hocadan bir öğrenciye) Limite dönüştürdün ama integrali hesaplayamadın; hangi yöntem? **Cevap:** Yerine koyma yöntemi. $\ln x=u$ dersek $\frac{dx}{x}=du$ olur ve integral $\int\frac{du}{1+u^2}$'ye dönüşür. Sonrası limit: üst sınırı ve alt sınırı yerleştir. Ama süreksizlik noktasına dikkat edin.

**Soru:** (Hocadan bir öğrenciye) Bu integrandın süreksizlik noktası hangisi? **Cevap:** Öğrenci "$\pi/2$" dedi. Hoca bunun integralin değeri olduğunu, süreksizlik noktasının ise $0$ olduğunu söyledi: $x=0$'da integrand süreksizdir.

Çözüm:

- Süreksizlik alt sınırda: $\displaystyle\int_0^1\frac{dx}{x(1+\ln^2x)}=\lim_{a\to0^+}\int_a^1\frac{dx}{x(1+\ln^2x)}$.
- Belirsiz integral: $u=\ln x$, $du=\dfrac{dx}{x}$.

$$\int\frac{dx}{x(1+\ln^2x)}=\int\frac{du}{1+u^2}=\arctan u+C=\arctan(\ln x)+C$$

- Hoca $\arctan u$'nun türevinin $\frac{1}{1+u^2}$ olduğunu hatırlattı.
- Sınırlar yerleştirilir. Üst sınırda $\arctan(\ln1)=\arctan0=0$:

$$\lim_{a\to0^+}\left[0-\arctan(\ln a)\right]$$

- $a\to0^+$ iken $\ln a\to-\infty$ ($\ln$ grafiği sıfıra yaklaşırken sonsuza kadar aşağı iner). $\arctan(-\infty)=-\frac{\pi}{2}$.
- Sonuç: $-\left(-\frac{\pi}{2}\right)=\frac{\pi}{2}$.

İntegral **yakınsaktır** ve $\frac{\pi}{2}$'ye yakınsar.

### 5.4 Has Olmayan İntegral Bir Limit Problemidir

Genel alıştırmalar sırasında bir öğrencinin takıldığı nokta üzerine hoca yakınsaklık tanımını yeniden özetledi: Has olmayan integral aslında bir tür limit problemidir. Önce integral problemi limit problemine dönüştürülür. Limit varsa integral yakınsak, limit yoksa ıraksaktır.

## 6. Genel Alıştırma: $x=y^2$ ve $y-x=-2$ Bölgesi

Hoca "bir soruyla bütün konuyu özetleyeceğim" diyerek alan ve hacim yöntemlerinin hepsini içeren bir soru yazdı. Sorularda yalnız integralin kurulması (state the integration) isteniyordu; hesaplamayı evde yapmalarını söyledi.

> **Hocanın vurgusu:** Bu tür sorularda integrali modelleyebiliyor olmanız çok önemli. Sadece integrali ifade edin; hesaplamayı evde kendiniz yaparsınız.

### 6.1 Soru

$R$, $x=y^2$ ve $y-x=-2$ ile sınırlı bölge olsun.

- a) $R$'nin alanını veren integrali yazın.
- b) $R$ bölgesi $y$ ekseni etrafında döndürülünce oluşan cismin hacmini veren integrali yazın.
- c) $R$ bölgesi $x$ ekseni etrafında döndürülünce oluşan cismin hacmini veren integrali yazın.
- d) $R$ bölgesi $x=-2$ doğrusu etrafında döndürülünce oluşan cismin hacmini veren integrali yazın.
- e) $R$ bölgesi $y=5$ doğrusu etrafında döndürülünce oluşan cismin hacmini veren integrali yazın.

### 6.2 Bölge ve Kesişim Noktaları

İkinci eğri $x=y+2$ doğrusudur ($x=0$ için $y=-2$). Kesişim için $x=y^2$ doğrunun denkleminde yerine konur:

$$y-y^2=-2\;\Rightarrow\;y^2-y-2=0\;\Rightarrow\;(y-2)(y+1)=0$$

Buradan $y_1=2$ ve $y_2=-1$ bulunur.

**Soru:** (Hocadan) Alan integralini yatay çubukla mı, dikey çubukla mı yazmak daha iyi? **Cevap:** Yatay çubukla (horizontal cross-section). Yatay çubukla bölge taranırken çubuğun sağ ucu her zaman $x_2=y+2$ doğrusunda, sol ucu her zaman $x_1=y^2$ parabolündedir.

### 6.3 a) Alan

Yatay çubuğun uzunluğu $x_2-x_1=(y+2)-y^2$, kalınlığı $dy$'dir:

$$dA=\left[(y+2)-y^2\right]dy,\qquad A=\int_{-1}^{2}\left[(y+2)-y^2\right]dy=\frac92$$

Hoca alanın hesaplanmasını istemedi; $\frac92$ değeri bu notta hesaplandı.

<!-- BELİRSİZ: 01:40:27-01:40:57 arasında altyazı tekrar döngüsüne giriyor ("y'nin y'nin"). Alan integralinin tahtadaki yazımı altyazıdan tam okunmuyor; integral hocanın önceki ve sonraki anlatımından kuruldu. -->

### 6.4 b) $y$ Ekseni Etrafında Hacim

Hoca hangi yöntemin avantajlı olduğunu sordu; cevap pul yöntemi (washer method) oldu. Yatay çubuk dönme eksenine diktir. Çubuk $y$ ekseni etrafında döndürülünce iç içe iki disk oluşur; içteki disk çıkarılınca pul elde edilir.

- Dış yarıçap $r_1=x_2=y+2$, iç yarıçap $r_2=x_1=y^2$.
- Bütün bilgi $y$ cinsinden yazılmalıdır, çünkü kalınlık $dy$'dir.

$$V=\pi\int_{-1}^{2}\left(r_1^2-r_2^2\right)dy=\pi\int_{-1}^{2}\left[(y+2)^2-(y^2)^2\right]dy=\frac{72\pi}{5}$$

### 6.5 c) $x$ Ekseni Etrafında Hacim

**Soru:** (Hocadan) Bu şık için neden kabuk yöntemi tercih ediliyor? Disk ya da pul yöntemini kullansak ne gibi bir engelle karşılaşırız? **Cevap:** Dikey çubuklarla bölge taranırsa çubuğun alt ve üst uçlarının üzerinde bulunduğu eğriler değişir. Bu durumda birden fazla, farklı tipte integral yazmak gerekir. Yatay çubukla taranırken ise sağ ve soldaki sınır eğrileri değişmez; tek bir integral yeter. Yatay çubuk $x$ ekseni etrafında döndürülünce bir kabuk oluşur.

> **Hocanın vurgusu:** Çubuğun nasıl konumlandığına bakarak hangi yöntemi kullanacağınızı biliyorsunuz. Ama bu yeterli değil. Öbür yöntemi seçseydiniz karşınıza çıkacak zorlukları da görebiliyor olmanız lazım.

**Simetri durumu.** Hoca şekli çizerken bunun alışıldık bir problem olmadığını fark etti. Bölgenin $x$ ekseninin altında kalan bir parçası var ($-1\le y\le0$). Bu parçanın $x$ eksenine göre yansıması, üst parçanın $0\le y\le1$ kısmının içine düşer. Döndürme sırasında iki parçanın yörüngeleri aynıdır: Alt parçanın döndürülmesiyle oluşan cisim, üst parçanınkinin içinde kalır. Bu yüzden integral $-1$'den değil, $0$'dan $2$'ye alınır.

- Kabuk yarıçapı $y$, kabuk yüksekliği $x_2-x_1=(y+2)-y^2$, kalınlık $dy$.

$$V=2\pi\int_0^{2}y\left[(y+2)-y^2\right]dy=\frac{16\pi}{3}$$

> **Hocanın vurgusu:** Böyle bir örneği şimdiye kadar görmedim. Böyle bir soru gelmez ama mantığı güzel.

**Soru:** Madem o kısım aynı, neden çıkarma ihtiyacı duyuyoruz? Çıkarmasak da aynı sonucu elde etmez miyiz? **Cevap:** Hoca öğrenciden integralleri yazıp denemesini istedi. Öğrenci denediğini, çıkarmadığında $\frac{9\pi}{2}$, çıkardığında $\frac{8\pi}{3}$ bulduğunu söyledi. Hoca integral hesaplarken dikkat etmek gerektiğini açıkladı: $-1$'den $0$'a olan kısım integrale fazladan bir terim getirir. $0$'dan $1$'e hesaplanan kısım pozitif gelir, $-1$'den $0$'a hesaplanan kısım ise farklı gelir; bu yüzden sonuç değişir. Doğru olan $0$'dan $2$'ye almaktır.

> **Ders sonrası not:** Hoca simetri durumunu "birbirini elimine ediyor" diye anlattı. Daha doğru açıklama: Alt parçanın döndürülmesiyle oluşan cisim üst parçanınkinin içinde kalır, yani hacme yeni bir şey eklemez. Hoca bir yerde "$0$'dan $1$'e yeterli" dedi; bu ifade simetrik kısım ($-1\le y\le1$) içindir, bütün integral $0$'dan $2$'ye alınır. Öğrencinin söylediği $\frac{9\pi}{2}$ değeri $-1$'den $2$'ye kabuk integralinin değeridir ve doğrudur, ama bu yanlış kurulmuş bir integraldir. Öğrencinin "çıkarınca" bulduğu $\frac{8\pi}{3}$ ise doğru değildir; $0$'dan $2$'ye kabuk integrali $\frac{16\pi}{3}$ verir. Fark büyük olasılıkla bir işlem hatasından gelir.

### 6.6 d) $x=-2$ Doğrusu Etrafında Hacim

Hoca önce "kabuk yöntemi" dedi, sonra düzeltti: Bölgeyi tarayan yatay çubuk dönme eksenine ($x=-2$) diktir; bu yüzden pul yöntemi en iyisidir.

- Dış yarıçap: Çubuğun sağ ucu $x_2=y+2$'dedir. Dönme eksenine uzaklık $r_1=(y+2)+2=y+4$.
- İç yarıçap: Çubuğun sol ucu $x_1=y^2$'dedir ($y^2\ge0$). Dönme eksenine uzaklık $r_2=y^2+2$.
- Bölge $y=-1$ seviyesinden $y=2$ seviyesine kadar taranır.

$$V=\pi\int_{-1}^{2}\left(r_1^2-r_2^2\right)dy=\pi\int_{-1}^{2}\left[(y+4)^2-(y^2+2)^2\right]dy=\frac{162\pi}{5}$$

### 6.7 e) $y=5$ Doğrusu Etrafında Hacim

Bölgeyi tarayan yatay çubuk $y=5$ doğrusuna paraleldir; bu yüzden kabuk yöntemi uygundur.

- Kabuk yarıçapı: Toplam uzaklık $5$'tir, çubuğun yüksekliği $y$; yarıçap $5-y$. Yarıçap pozitif olmalıdır; $-1\le y\le2$ için $5-y>0$.
- Kabuk yüksekliği: $x_2-x_1=(y+2)-y^2$.
- Kalınlık: $dy$.

$$V=2\pi\int_{-1}^{2}(5-y)\left[(y+2)-y^2\right]dy=\frac{81\pi}{2}$$

Bu şıkta simetri sorunu yoktur, çünkü dönme ekseni $y=5$ bölgenin tamamen dışında ve üstündedir. Bu yüzden integral $-1$'den $2$'ye alınır.

## 7. Simetrik Bölgenin $x$ Ekseni Etrafında Döndürülmesi

C şıkkındaki simetri durumunu daha açık görmek için hoca basit bir örnek verdi ve herkesin hesaplamasını istedi.

### 7.1 Soru

$x=y^2$ parabolü ile $x=1$ doğrusu arasındaki bölge $x$ eksenine göre simetriktir. Üst ve alt parçaların alanları eşittir ($S$ ve $S$; toplam $2S$). Alanı $2S$ olan bu bölge $x$ ekseni etrafında döndürülüyor. Hacim nedir?

### 7.2 Yanlış Yaklaşım

Dikey çubukla disk yöntemi kurulup üst uç $y=\sqrt{x}$, alt uç $y=-\sqrt{x}$ alınırsa:

$$\pi\int_0^1\left[(\sqrt{x})^2-(-\sqrt{x})^2\right]dx=0$$

Sonuç sıfır çıkar; bu anlamsızdır. Kabuk yönteminde de $y$ yarıçapı işaretli alınıp $-1$'den $1$'e integrallenirse $2\pi\displaystyle\int_{-1}^{1}y(1-y^2)\,dy=0$ çıkar.

<!-- BELİRSİZ: 02:22:47-02:23:57 arasında hocanın "yanlış yaklaşım" için tahtaya yazdığı integralin sınırları altyazıda karışık geçiyor ("eksi birden bire kök x karesi eksi eksi kök x'in karesi"). Disk integrali burada $x$ cinsinden $0$'dan $1$'e yazıldı. -->

### 7.3 Doğru Yaklaşım

$2S$ bölgesini $x$ ekseni etrafında döndürmekle elde edilen cisim, tek bir $S$ bölgesini döndürmekle elde edilen cisimle aynıdır. Bu yüzden yalnız üst parçaya odaklanılır.

- **Disk yöntemi:** Dikey çubuğun üst ucu $y=\sqrt{x}$'te, alt ucu $x$ ekseni ($y=0$) üzerindedir.

$$V=\pi\int_0^1(\sqrt{x})^2\,dx=\pi\int_0^1x\,dx=\pi\left[\frac{x^2}{2}\right]_0^1=\frac{\pi}{2}$$

- **Kabuk yöntemi:** Yatay çubuk, yarıçap $y$, yükseklik $x_2-x_1=1-y^2$, kalınlık $dy$.

$$V=2\pi\int_0^1y\left(1-y^2\right)dy=2\pi\left(\frac12-\frac14\right)=\frac{\pi}{2}$$

Kabuk integralinin hesabı bu notta yapıldı (ara adım eklendi). İki yöntem aynı sonucu verir. Hoca, "$-1$'den $1$'e" ve "$0$'dan $1$'e" kurulan iki kabuk integralinden hangisinin doğru olduğunu sordu; doğrusu ikincisidir. Burada alan değil hacim hesaplıyoruz: $2S$'yi döndürmek $S$'yi döndürmekle aynı cismi verir.

## 8. Geçmiş Yıl Sorusu: $y=2/x$ Bölgesi

### 8.1 Soru

Hoca bunun geçmiş yıllardan bir sınav sorusu olduğunu söyledi. $R$, $y=\dfrac2x$, $x=1$, $x=3$ ve $y=0$ ile sınırlı bölgedir.

- a) $R$, $x$ ekseni etrafında döndürülüyor. Hacmi disk yöntemiyle ifade edin.
- b) $R$, $x=4$ doğrusu etrafında döndürülüyor. Hacmi kabuk yöntemiyle ifade edin.
- c) $y=\dfrac2x$, $1\le x\le3$ eğrisinin yay uzunluğu formülünü ifade edin.
- d) Bu eğri $x$ ekseni etrafında döndürülüyor. Yüzey alanı formülünü ifade edin.

### 8.2 a) $x$ Ekseni Etrafında Hacim (Disk)

Bölge dikey çubukla taranır; çubuk $x$ eksenine diktir. Çubuğun üst ucu $y_2=\frac2x$'te, alt ucu $y_1=0$'dadır.

$$V=\pi\int_1^3\left(\frac{2}{x}\right)^2dx=\frac{8\pi}{3}$$

### 8.3 b) $x=4$ Doğrusu Etrafında Hacim (Kabuk)

Dikey çubuk $x=4$ doğrusuna paraleldir.

- Dikkat: İntegral $1$'den $4$'e değil, $1$'den $3$'e alınır, çünkü bölge orada.
- Kabuk yarıçapı: Toplam uzaklık $4$; yarıçap $4-x$ (pozitif).
- Kabuk yüksekliği: Tarayan çubuğun uzunluğu $\frac2x-0=\frac2x$.
- Kalınlık: $dx$.

$$V=2\pi\int_1^3(4-x)\frac{2}{x}\,dx=16\pi\ln3-8\pi$$

### 8.4 c) Yay Uzunluğu

Hoca formülü yine Pisagor teoreminden kurdu: $dL=\sqrt{dx^2+dy^2}$, $dx^2$ ortak paranteze alınır. $y=\frac2x$ için $\frac{dy}{dx}=-\frac{2}{x^2}$:

$$L=\int_1^3\sqrt{1+\left(-\frac{2}{x^2}\right)^2}\,dx=\int_1^3\sqrt{1+\frac{4}{x^4}}\,dx$$

Hoca bu integralin hesaplanmasının istenmediğini söyledi: Hesabı kolay değildir ve alışılmış sorulardan çok daha fazla zaman alır.

### 8.5 d) Dönel Yüzey Alanı

Hoca öğrencilerden formüle bakmadan çıkarmalarını istedi: Eğrinin küçük bir parçası dik üçgenin hipotenüsü $dL$ gibi düşünülür. $dL$, $x$ eksenine paralel kabul edilip $x$ ekseni etrafında döndürülünce yarıçapı $f(x)$, yüksekliği $dL$ olan bir silindir elde edilir. Silindir yüzeyi kesilip açılınca dikdörtgen olur; alanı $2\pi f(x)\,dL$'dir.

$$S=\int_1^3 2\pi\cdot\frac{2}{x}\sqrt{1+\left(-\frac{2}{x^2}\right)^2}\,dx=2\pi\int_1^3\frac{2}{x}\sqrt{1+\frac{4}{x^4}}\,dx$$

Bu integral de hesaplanmadan bu biçimde bırakılır.

> **Hocanın vurgusu:** Formülü ezberlemenize gerek yok. Silindirin yüzey alanı formülünü biliyorsunuz; formülü çıkarmak 10-15 saniyenizi almaz.

<!-- BELİRSİZ: 02:46:34 civarında altyazı tekrar döngüsüne giriyor ("bu bölümde"). Hocanın bu aralıktaki sözlü açıklaması okunmuyor; formül 02:47:04 sonrasındaki anlatımdan kuruldu. -->

## 9. Örnek Sorular

Bu derste ekran görüntüsü kullanılmadı. Aşağıdaki sorular, hocanın derste çözülmesini istediği ya da sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:40:29): $\displaystyle\int_0^{\infty}x e^{-x}\,dx$ integralini hesaplayın. Yakınsak mı?

> **Çözüm (derste verildi):** $\displaystyle\lim_{a\to\infty}\int_0^a xe^{-x}dx=\lim_{a\to\infty}\left[-e^{-a}(a+1)+1\right]=1$. Son limit L'Hôpital ile sıfırdır. İntegral yakınsaktır (bkz. Örnek 4).

**Soru 2** (derste sözlü, 01:17:19 ve 01:22:11): $\displaystyle\int_0^{1}\frac{dx}{x(1+\ln^2x)}$ yakınsak mı, ıraksak mı? Yakınsaksa değeri nedir? İntegrandın süreksizlik noktası hangisidir?

> **Çözüm (derste verildi):** Süreksizlik noktası $x=0$'dır. $u=\ln x$ ile ters türev $\arctan(\ln x)$ bulunur. $\displaystyle\lim_{a\to0^+}\left[0-\arctan(\ln a)\right]=\frac{\pi}{2}$. İntegral yakınsaktır (bkz. Örnek 6).

**Soru 3** (derste sözlü, 01:35:37): $x=y^2$ ve $y-x=-2$ bölgesinin alan integralini yazmak için yatay çubuk mu, dikey çubuk mu daha uygundur?

> **Çözüm (derste verildi):** Yatay çubuk. Sağ uç her zaman $x=y+2$'de, sol uç her zaman $x=y^2$'dedir; tek integral yeter: $\displaystyle A=\int_{-1}^{2}\left[(y+2)-y^2\right]dy$.

**Soru 4** (derste sözlü, 01:46:38): Aynı bölge $x$ ekseni etrafında döndürülürken neden kabuk yöntemi tercih edilir? Disk ya da pul yöntemi seçilirse ne gibi bir zorlukla karşılaşılır?

> **Çözüm (derste verildi):** Dikey çubukla taranırsa çubuğun alt ve üst uçlarının bulunduğu eğriler değişir; birden fazla integral yazmak gerekir. Yatay çubukla sınır eğrileri değişmez ve tek integral yeter (bkz. Bölüm 6.5).

**Soru 5** (derste sözlü, 01:28:17-01:33:05): $R$, $x=y^2$ ve $y-x=-2$ ile sınırlı bölge. a) Alan; b) $y$ ekseni; c) $x$ ekseni; d) $x=-2$; e) $y=5$ etrafında dönmede hacim integrallerini yazın.

> **Çözüm (derste integraller verildi; sayısal değerler derste hesaplanmadı):** a) $\displaystyle\int_{-1}^{2}\left[(y+2)-y^2\right]dy=\frac92$. b) $\displaystyle\pi\int_{-1}^{2}\left[(y+2)^2-y^4\right]dy=\frac{72\pi}{5}$. c) $\displaystyle2\pi\int_0^2y\left[(y+2)-y^2\right]dy=\frac{16\pi}{3}$. d) $\displaystyle\pi\int_{-1}^{2}\left[(y+4)^2-(y^2+2)^2\right]dy=\frac{162\pi}{5}$. e) $\displaystyle2\pi\int_{-1}^{2}(5-y)\left[(y+2)-y^2\right]dy=\frac{81\pi}{2}$. Değerler sympy ile doğrulandı.

**Soru 6** (derste sözlü, 01:58:02): C şıkkında $-1\le y\le0$ kısmını neden dışarıda bırakıyoruz? Dahil etsek aynı sonucu bulmaz mıyız?

> **Çözüm (derste verildi):** Hayır. $-1$'den $2$'ye kurulan kabuk integrali $\frac{9\pi}{2}$ verir; bu, cismin hacmi değildir. Alt parçanın döndürülmesiyle oluşan cisim üst parçanınkinin içinde kalır; doğru integral $0$'dan $2$'ye kurulur ve $\frac{16\pi}{3}$ verir.

**Soru 7** (derste sözlü, 02:20:52): $x=y^2$ ile $x=1$ arasındaki, alanı $2S$ olan simetrik bölge $x$ ekseni etrafında döndürülüyor. Hacim nedir? $-1$'den $1$'e mi, $0$'dan $1$'e mi integral alınmalıdır?

> **Çözüm (derste verildi):** $0$'dan $1$'e. Disk: $\displaystyle\pi\int_0^1x\,dx=\frac{\pi}{2}$. Kabuk: $\displaystyle2\pi\int_0^1y(1-y^2)\,dy=\frac{\pi}{2}$. $-1$'den $1$'e kurulan integraller $0$ verir ve yanlıştır.

**Soru 8** (derste sözlü, geçmiş yıl sorusu, 02:31:05-02:42:46): $R$, $y=\frac2x$, $x=1$, $x=3$, $y=0$ ile sınırlı. a) $x$ ekseni etrafında hacim (disk); b) $x=4$ etrafında hacim (kabuk); c) $1\le x\le3$ için yay uzunluğu; d) eğrinin $x$ ekseni etrafında döndürülmesiyle oluşan yüzey alanı integrallerini yazın.

> **Çözüm (derste integraller verildi):** a) $\displaystyle\pi\int_1^3\frac{4}{x^2}dx=\frac{8\pi}{3}$. b) $\displaystyle2\pi\int_1^3(4-x)\frac2x\,dx=16\pi\ln3-8\pi$. c) $\displaystyle\int_1^3\sqrt{1+\frac4{x^4}}\,dx$. d) $\displaystyle2\pi\int_1^3\frac2x\sqrt{1+\frac4{x^4}}\,dx$. a ve b değerleri derste hesaplanmadı, sympy ile bulundu.

> **Çözüm (derste verilmedi):** c ve d integralleri temel fonksiyonlarla kolay hesaplanmaz. Sayısal değerleri sympy ile yaklaşık olarak $L\approx2{,}4979$ ve $S\approx18{,}4714$'tür.

## Dersin Toparlaması

Bu derste belirli integralin son iki geometrik uygulaması ve has olmayan integraller işlendi. Yay uzunluğu formülü, eğrinin küçük bir parçasını dik üçgen olarak düşünüp Pisagor teoremini uygulamaktan çıktı: $dL=\sqrt{dx^2+dy^2}$. Dönel yüzey alanı da bu $dL$ parçasının döndürülmesiyle oluşan silindirin yüzey alanından geldi: $dS=2\pi f(x)\,dL$. Hoca her iki formülün de ezberlenmemesi, gerektiğinde birkaç saniyede yeniden kurulması gerektiğini vurguladı.

Has olmayan integrallerde temel fikir, integrali bir limit problemine dönüştürmekti. Birinci tipte aralık sınırsızdır; ikinci tipte aralık sınırlıdır ama integrand bir noktada süreksizdir. Limit varsa integral yakınsak, yoksa ıraksaktır. Hoca bu integrallerin ileride istatistik dersinde yoğunluk fonksiyonlarıyla sık kullanılacağını söyledi. Dersin son bölümünde alan, disk, pul ve kabuk yöntemleri, yay uzunluğu ve yüzey alanı tek tek sorularla tekrar edildi. Simetrik bölgelerin $x$ ekseni etrafında döndürülmesinde iki parçanın yörüngelerinin çakıştığı ve yalnız bir parçanın alınması gerektiği gösterildi. Bir sonraki derste geçmiş yılların soruları çözülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
