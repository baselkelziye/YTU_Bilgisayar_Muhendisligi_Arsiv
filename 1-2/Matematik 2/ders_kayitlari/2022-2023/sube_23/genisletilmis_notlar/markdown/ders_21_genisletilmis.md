# Ders 21 Genişletilmiş Notu: İntegrasyon Sırasını Değiştirme, Jacobian ve Kutupsal Koordinatlarla Değişken Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Tek ve Çift Katlı İntegralle Alan
- 2. Çift Katlı İntegral Alan mı Verir, Hacim mi?
- 3. İntegrasyon Sırasını Değiştirme
- 4. Jacobian ile Değişken Dönüşümü
- 5. Kutupsal Koordinatlar ve Jacobian'ın $r$ Çıkması
- 6. Hiperbollerle Sınırlı Bölgeler
- 7. Parabollerle Sınırlı Bölge
- 8. Kutupsal Koordinatlarla Bir Üçgen Bölge
- 9. İntegrasyon Sırasını Değiştirmeye Dönüş: Bölgeyi Parçalamak
- Örnek Sorular
- Dersin Toparlaması

## 1. Tekrar: Tek ve Çift Katlı İntegralle Alan

Ders 8 Mayıs 2023 Pazartesi günü online yapıldı. Hoca, geçen hafta başlanan çok katlı integrallere birkaç dakikalık bir tekrarla girdi.

Bir $y=f(x)$ fonksiyonu $a\le x\le b$ aralığında tanımlı olsun ve eğri $x$ ekseninin üstünde kalsın. Eğrinin altında kalan bölgenin alanı, Riemann integrali (Riemann integral) ile

$$A=\int_a^b f(x)\,dx$$

olarak bulunur. Aynı alan çift katlı integralle de yazılabilir. Bunun için $y$'nin hangi aralıkta değiştiğine bakılır: $y$, $y=0$ doğrusundan $y=f(x)$ eğrisine kadar değişir. Böylece

$$A=\int_a^b\!\int_0^{f(x)} dy\,dx$$

elde edilir. Hoca iki yazımın sonucunun aynı olduğunu, ikisinin de alanı verdiğini vurguladı. Tek katlı integral çok katlı biçimde de yazılabilir.

Hoca ayrıca daha önce Fubini teoremlerini verdiklerini hatırlattı.

### 1.1 Örnek 1: $e^x$ Eğrisinin Altındaki Alan

Hoca $y=e^x$ eğrisini çizdi. $x=0$ iken $e^0=1$'dir ve fonksiyon artandır. Bölge $B$: $1\le x\le2$, $0\le y\le e^x$.

$$A=\iint_B dA=\int_1^2\!\int_0^{e^x} dy\,dx$$

- İç integral: $\displaystyle\int_0^{e^x} dy=y\Big|_0^{e^x}=e^x-0=e^x$.
- Dış integral: $\displaystyle\int_1^2 e^x\,dx=e^x\Big|_1^2=e^2-e$.

Sonuç: $A=e^2-e\approx4{,}67$. İntegrand 1 olduğu için bu bir alandır.

> **Ders sonrası not:** Hoca iç integralde alt sınırı koyarken "$e^x$ eksi $e^0$" dedi ve iç integrali $e^x-1$ aldı. Sonra $\left[e^x-x\right]_1^2=(e^2-2)-(e-1)=e^2-e-1$ hesabına gitti. İç integralde integrand 1'dir, $y$ değişkeninin alt sınırı 0'dır. Bu yüzden iç integral $e^x-0=e^x$'tir. Doğru sonuç $e^2-e$'dir (sympy ile doğrulandı).

## 2. Çift Katlı İntegral Alan mı Verir, Hacim mi?

Hoca öğrencilere şunu sordu: $\displaystyle\iint_B f(x,y)\,dA$ integrali alanı mı verir, hacmi mi?

- $f(x,y)=1$ ise integral $B$ bölgesinin **alanını** verir.
- $f(x,y)\ne1$ ise (ve $f\ge0$ ise) integral, $B$ üzerinde $z=f(x,y)$ yüzeyinin altında kalan cismin **hacmini** verir.

Hocanın vurguladığı nokta, integralin aynı olduğu, yalnız içindeki fonksiyonun değiştiğidir. Dersin ilerleyen kısmında da sonucu "birim kare" ya da "birim küp" diye yorumlarken bu kuralı kullandı.

## 3. İntegrasyon Sırasını Değiştirme

### 3.1 Neden Gerekir?

Bazı integrallerde verilen sırayla iç integral alınamaz. İç integralin ilkeli elementer bir fonksiyon değildir. Bu durumda integrasyon sırasını değiştirme (change of order of integration) yöntemi kullanılır: $dy\,dx$ sırası $dx\,dy$ yapılır ya da tersi.

Hoca bunu bir benzetmeyle anlattı: İnsan uçaktan atlayınca paraşüte ihtiyaç duyar. Paraşüt açılmazsa iş biter. İntegralde de "paraşüt" görevi gören teknikler vardır. Bunlardan biri integrasyon sırasını değiştirmektir. Bu yöntem sayesinde çözülemeyen birçok soru çözülür hale gelir.

Önemli nokta şudur: Fonksiyon değişmez. Yalnız aynı bölge başka bir biçimde ifade edilir ve sınırlar ona göre yeniden yazılır.

### 3.2 Üç Adım

Hoca yöntemi üç adım olarak verdi:

1. İntegrasyon bölgesini çiz.
2. İntegrasyon sırasını değiştir.
3. İntegrali hesapla.

> **Hocanın vurgusu:** Soru "sırayı değiştirin" demese de bölge mutlaka çizilmelidir. Önce verilen sırayla denenir, olmuyorsa sıra değiştirilir.

### 3.3 Örnek 2: $\displaystyle\int_1^2\!\int_0^x e^{y^2}\,dy\,dx$

Hoca bu integrali tahtaya yazdı. $e^{y^2}$'nin $y$'ye göre ilkeli bulunamaz. Bu yüzden sıra değiştirilmelidir.

**Bölge:** $1\le x\le2$, $0\le y\le x$. Bölge $y=0$, $y=x$, $x=1$ ve $x=2$ doğrularıyla sınırlıdır.

**Hocanın anlatımı:** Hoca $dy$'yi dışarı aldı. $y=x$ doğrusu $x=2$'de $y=2$ olduğu için $y$'yi 0'dan 2'ye taradı. $x$ için önce "$x=2$ doğrusundan $y$'ye" dedi. Sonra bir parçanın dışarıda kaldığını, bölgeyi parçalara ayırmak gerektiğini ama ilk etapta bunu göstermeyeceğini söyledi. Ardından iç integrali $x$'e göre aldı: $e^{y^2}$ sabit gibi davranır ve $x\,e^{y^2}$ gelir. Sınırları "sıfır ve $y$" diye koydu ve şuna ulaştı:

$$\int_0^2 y\,e^{y^2}\,dy$$

Bu integralde $t=y^2$ dönüşümü yapılırsa türev de integralde hazır bulunur ve integral kolayca alınır:

$$\int_0^2 y\,e^{y^2}\,dy=\frac12 e^{y^2}\Big|_0^2=\frac{e^4-1}{2}\quad\text{(ara adım eklendi)}$$

> **Ders sonrası not:** Yazılan bölge ($1\le x\le2$, $0\le y\le x$) için sıra değişince iki parça çıkar:
> $$\int_0^1\!\int_1^2 e^{y^2}\,dx\,dy+\int_1^2\!\int_y^2 e^{y^2}\,dx\,dy=\int_0^1 e^{y^2}\,dy+\int_1^2(2-y)\,e^{y^2}\,dy\approx5{,}503$$
> İki parçada da $\int e^{y^2}dy$ kalır ve bu elementer değildir. Yani yazılan integral bu yolla kapalı biçimde çözülmez. Hocanın ulaştığı $\int_0^2 y\,e^{y^2}\,dy=\frac{e^4-1}{2}$ ifadesi, $\displaystyle\int_0^2\!\int_x^2 e^{y^2}\,dy\,dx$ integralinin (bölge: $y=x$ ile $y=2$ arası, $0\le x\le2$) sıra değiştirilmiş hâlidir. Tahtadaki soru büyük olasılıkla bu biçimde kurulmak istendi. Sonuçlar sympy ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** $e^{y^2}$, $\dfrac{\sin y}{y}$ ve $e^{x^2}$ gibi fonksiyonların ilkelleri sürekli olarak vardır ama sonlu sayıda elementer fonksiyonla (polinom, üstel, logaritma, trigonometrik) yazılamaz. Bu tür fonksiyonlar için özel fonksiyonlar tanımlanmıştır; örneğin $\int\frac{\sin y}{y}dy$ "sinüs integrali" $\mathrm{Si}(y)$ diye adlandırılır. Sıra değiştirme işe yarıyorsa, bunun nedeni yeni iç integralde zor fonksiyonun sabit gibi davranması ve dışarıda türevinin de belirmesidir.

### 3.4 Örnek 3: $\displaystyle\int_0^\pi\!\int_x^\pi \frac{\sin y}{y}\,dy\,dx$

Hoca bu soruyu bir kaynak kitaptan açtı.

<!-- BELİRSİZ: Kısa not kaynağı Mustafa Balcı'nın "Genel Matematik 2 Problemleri" kitabı olarak veriyor; altyazıda kitabın adı geçmiyor, yalnız soru numaraları geçiyor. -->

$\dfrac{\sin y}{y}$'nin $y$'ye göre integrali alınamaz. Sıra değiştirilmelidir.

**Bölge:** $0\le x\le\pi$, $x\le y\le\pi$. Yani $y=x$ doğrusunun üstü ile $y=\pi$ doğrusunun altı. Hoca önce "$y$ sıfırdan $\pi$'ye" diye okudu, sonra "$x$'ten $\pi$'ye" diye düzeltti.

**Sıra değişince:** $0\le y\le\pi$ ve $0\le x\le y$.

$$\int_0^\pi\!\int_0^y \frac{\sin y}{y}\,dx\,dy$$

- İç integral: $\dfrac{\sin y}{y}$ artık $x$'e göre sabittir. $\displaystyle\int_0^y \frac{\sin y}{y}\,dx=\frac{\sin y}{y}\cdot y=\sin y$. $y$'ler sadeleşir.
- Dış integral: $\displaystyle\int_0^\pi \sin y\,dy=-\cos y\Big|_0^\pi=-\cos\pi+\cos0=1+1=2$.

Sonuç: $2$ (sympy ile doğrulandı).

> **Hocanın vurgusu:** İşlem hatası bilinen soruyu yanlışa götürür. Test sınavında tolerans yoktur. "Doğru yaptım ama yanlış sonuç buldum" işe yaramaz. Bol işlem yapmak gerekir.

### 3.5 Kaynaktaki Diğer Şıklar

Hoca aynı kaynaktan bir şıkkı daha gösterdi: $x$ 0'dan 1'e, $y$ 0'dan 1'e, iç integralde $x$ $y$'den 1'e değişiyor. Bölge çizilir, sıra değiştirilir ve sonuca ulaşılır. Dersin sonuna doğru ($01{:}41{:}24$) bir şıkta da $e^{x^2}$ benzeri bir integrandın $x$'e göre alınamadığını, $y$'ye göre alınınca kolaylaştığını söyledi.

<!-- BELİRSİZ: Bu iki şıkkın integrandı altyazıda okunmuyor. Kısa not bunları ∫_0^1∫_y^1 x²e^{xy} dx dy ve ∫_0^2∫_{y/2}^1 e^{x²} dx dy olarak veriyor; sonuçlar sırasıyla e/2 − 1 ve e − 1 çıkar (sympy). -->

### 3.6 Tek Katlı İntegral Bilgisi

> **Hocanın vurgusu:** Çok katlı integral sonunda tek katlı integrale indirgenir. Tek katlı integralde eksiği olan, onu tamamlamalıdır.

Hoca çok katlı integrallerden integrasyon sırası değiştirme, alan, hacim gibi soru tiplerinin geleceğini belirtti.

## 4. Jacobian ile Değişken Dönüşümü

### 4.1 Fikir

Bazı integraller ne doğrudan ne de sıra değiştirerek alınabilir. Hoca bunu "paraşüt açılmadığında başka bir yöntem" diye niteledi. Bu durumda değişken dönüşümü (change of variables) yapılır: kutupsal koordinatlara (polar coordinates), silindirik koordinatlara ya da başka bir dönüşümle yeni değişkenlere geçilir.

$x$ ve $y$, yeni değişkenler $u$ ve $v$'ye bağlı yazılır: $x=x(u,v)$, $y=y(u,v)$. $xy$ düzlemindeki $D$ bölgesi $uv$ düzleminde başka bir $D'$ bölgesine dönüşür. Fonksiyonda $x$ ve $y$'nin yerine karşılıkları yazılır. Ama bir şey daha gelir: dönüşümden kaynaklanan çarpan, yani Jacobian (Jacobian).

**Değişken dönüşümü formülü**

- $x=x(u,v)$, $y=y(u,v)$ dönüşümü $D'$ bölgesini $D$ bölgesine götürsün.
- Jacobian, kısmi türevlerden oluşan determinanttır:
$$J=\frac{\partial(x,y)}{\partial(u,v)}=\begin{vmatrix}x_u & x_v\\ y_u & y_v\end{vmatrix}$$
- İntegral şöyle dönüşür:
$$\iint_D f(x,y)\,dx\,dy=\iint_{D'} f\big(x(u,v),y(u,v)\big)\,|J|\,du\,dv$$

Hoca bölge adının değişmesini şakayla "Bolu'ydu, oradan Düzce'ye geliyoruz" diye anlattı: $B$ bölgesi dönüşümle $D$ adlı başka bir bölgeye geçer.

> **Hocanın vurgusu:** Bu yöntemin en önemli noktası Jacobian'dır. Hoca onu "tılsım" diye niteledi. Dönüşüm yapıp Jacobian'ı unutan yanlış sonuca ulaşır.

> **Ek bilgi (derste anlatılmadı):** $|J|$ yerel bir alan ölçeğidir. $uv$ düzleminde $du\times dv$ boyutundaki küçük bir dikdörtgen, $xy$ düzleminde yaklaşık $|J|\,du\,dv$ alanlı bir paralelkenara gider. Bu yüzden $dx\,dy$ yerine yalnız $du\,dv$ yazmak alanları yanlış ölçmek olur. Formülde mutlak değer kullanılır, çünkü alan negatif olamaz.

### 4.2 Ters Jacobian

Bazen $x$ ve $y$'yi $u,v$ cinsinden yazmak zordur. Ama $u$ ve $v$ zaten $x,y$ cinsinden verilmiştir ve onların türevleri kolaydır. Hoca bu durumda tersini kullanmayı gösterdi:

$$\frac{\partial(x,y)}{\partial(u,v)}=\frac{1}{\dfrac{\partial(u,v)}{\partial(x,y)}}=\frac{1}{\begin{vmatrix}u_x & u_y\\ v_x & v_y\end{vmatrix}}$$

Hoca bunun bir "manipülasyon" olduğunu, çünkü $u$'nun $x$'e göre türevini almanın $x$'in $u$'ya göre türevini almaktan çok daha kolay olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu eşitlik ters fonksiyon teoreminden gelir. $(u,v)\mapsto(x,y)$ ve $(x,y)\mapsto(u,v)$ birbirinin tersi olan dönüşümlerdir. Ters dönüşümlerin Jacobian matrisleri birbirinin tersidir, determinantları da birbirinin çarpmaya göre tersidir. Bu yüzden Jacobian'ın sıfır olmadığı yerlerde yazılabilir.

### 4.3 Ekrandaki Belirsiz Örnekler

Hoca bu kısımda ekranda iki örnek gösterdi. Birinde bölgeyi çizip $y$'ye göre, sonra $x$'e göre integral aldı. Diğerinde $u,v$ dönüşümü ile ters Jacobian'ı kullandı ve sonunda $v^2$ içeren bir integrale ulaştı.

<!-- BELİRSİZ: 00:31:41 civarındaki örnekte sınırlar altyazıda "kök, 2x-x, x kareden 2'ye kadar, x 0'dan 2'ye kadar" diye geçiyor; integral okunmuyor. -->
<!-- BELİRSİZ: 00:32:41–00:35:17 arasındaki dönüşüm örneğinde bölge "2x eksi y'nin karesi" diye geçiyor; u, v tanımı ve kısmi türevler ("1, 1, 2, ...") altyazıdan kurulamıyor. -->

## 5. Kutupsal Koordinatlar ve Jacobian'ın $r$ Çıkması

### 5.1 Jacobian'ın Hesabı

Çembersel bölgelerde kutupsal koordinatlara geçilir:

$$x=r\cos\theta,\qquad y=r\sin\theta$$

Jacobian:

$$J=\frac{\partial(x,y)}{\partial(r,\theta)}=\begin{vmatrix}x_r & x_\theta\\ y_r & y_\theta\end{vmatrix}=\begin{vmatrix}\cos\theta & -r\sin\theta\\ \sin\theta & r\cos\theta\end{vmatrix}=r\cos^2\theta+r\sin^2\theta=r$$

Son adımda $\sin^2\theta+\cos^2\theta=1$ kullanıldı. Yani $dx\,dy=r\,dr\,d\theta$ olur ve $x^2+y^2=r^2$'dir.

**Kutupsal koordinatlara geçiş**

- $x=r\cos\theta$, $y=r\sin\theta$.
- $J=r$.
- $\displaystyle\iint_D f(x,y)\,dx\,dy=\iint_{D'} f(r\cos\theta,r\sin\theta)\,r\,dr\,d\theta$.

> **Hocanın vurgusu:** Kutupsal dönüşümde Jacobian hep $r$'dir. Test sınavında hızlı çözmek gerekir. Her seferinde determinantı yeniden hesaplamaya gerek yoktur, doğrudan $r$ yazılır.

Hoca Jacobian'ı dersin ilk yarısında ve aradan sonra tekrar türetti. Altyazıda $\theta$ bazı yerlerde "fi" diye geçiyor. Hoca kaynaktaki dönüşümün yanlış yazıldığını söyleyip $x=r\cos\theta$, $y=r\sin\theta$ diye düzeltti.

### 5.2 Örnek 4: Halka Bölgede $(x^2+y^2)^{1/4}$

Kaynaktan bir soru: $\displaystyle\iint_B (x^2+y^2)^{1/4}\,dx\,dy$.

Hoca bu integralin doğrudan hesabının çok zor olduğunu, $x^2+y^2$ görülünce kutupsala geçmek gerektiğini söyledi. Bölge iki çember arasındaki halkadır: $r$ 1'den 4'e, $\theta$ 0'dan $2\pi$'ye değişir.

<!-- BELİRSİZ: Bölgenin denklemleri altyazıda okunmuyor; yalnız "r birden dörde kadar" ve "θ sıfırdan 2π'ye kadar" geçiyor. Kısa not bölgeyi x²+y²=1 ile x²+y²=16 arası diye veriyor. -->

**Dönüşüm:**
- $x^2+y^2=r^2\cos^2\theta+r^2\sin^2\theta=r^2$.
- $(x^2+y^2)^{1/4}=(r^2)^{1/4}=r^{1/2}$.

Hoca burada bilerek bir şeyi eksik bıraktı ve öğrencilere "Burada önemli bir şey eksik, ne var?" diye sordu. Eksik olan Jacobian'dır: $r$ eklenmelidir.

$$\int_0^{2\pi}\!\int_1^4 r^{1/2}\cdot r\,dr\,d\theta=\int_0^{2\pi}\!\int_1^4 r^{3/2}\,dr\,d\theta$$

- İç integral: $\displaystyle\frac25 r^{5/2}\Big|_1^4=\frac25(32-1)=\frac{62}{5}$ (ara adım eklendi).
- Dış integral: $\dfrac{62}{5}\cdot2\pi=\dfrac{124\pi}{5}$.

Sonuç: $\dfrac{124\pi}{5}$ (sympy ile doğrulandı). Hoca sonucu ekrandan gösterdi; altyazıda sayısal değer okunmuyor.

> **Ders sonrası not:** Hoca $x^2$'yi yazarken bir yerde "R kare artı kos kare teta" dedi. Doğrusu $x^2=r^2\cos^2\theta$, yani çarpımdır.

### 5.3 Örnek 5: Birim Diskte $\sqrt{x^2+y^2}$

Aradan sonra hoca kutupsal dönüşümü yeniden özetledi ve tahtada bir örnek yaptı.

<!-- BELİRSİZ: İntegrand altyazıda "x3, txt" diye bozuk; sonraki anlatımdan ("R olarak dışarı çıktı", Jacobian ile r²) integrandın √(x²+y²) olduğu anlaşılıyor. -->

$$\iint_D \sqrt{x^2+y^2}\,dA,\qquad D:\ 0\le r\le1,\ 0\le\theta\le2\pi$$

- $\sqrt{x^2+y^2}=\sqrt{r^2}=r$.
- Hoca yine "Eksik bir şey var mı?" diye sordu. Jacobian $r$ eklenince integrand $r\cdot r=r^2$ olur.

$$\int_0^{2\pi}\!\int_0^1 r^2\,dr\,d\theta=\int_0^{2\pi}\frac{r^3}{3}\Big|_0^1\,d\theta=\frac13\cdot2\pi=\frac{2\pi}{3}$$

Sonuç: $\dfrac{2\pi}{3}$ birim küp (sympy ile doğrulandı). Hoca bunun bir hacim olduğunu, çünkü integrandın 1'den farklı olduğunu belirtti.

## 6. Hiperbollerle Sınırlı Bölgeler

### 6.1 Örnek 6 (Tahtadan): $xy=2$, $xy=4$, $x^2-y^2=1$, $x^2-y^2=3$

Hoca bu dört eğriyle sınırlı bölgenin alanını sordu: $\displaystyle\iint_D dx\,dy$.

<!-- BELİRSİZ: Bölgenin birinci bölgede alındığı altyazıda söylenmiyor; aşağıdaki sayısal değer birinci bölge için hesaplandı. -->

Hoca bu bölgenin "köşeleriyle tuhaf" olduğunu, alanının doğrudan bulunamayacağını söyledi. Bölge düzgün bir bölgeye dönüştürülmelidir.

**Dönüşüm:** $u=xy$, $v=x^2-y^2$.
- $u$: 2'den 4'e.
- $v$: 1'den 3'e.

$uv$ düzleminde bölge bir dikdörtgendir: $2\le u\le4$, $1\le v\le3$. Hoca bu dikdörtgenin alanının $2\cdot2=4$ olduğunu, tuhaf bölgenin "bildiğimiz kareye" dönüştüğünü söyledi. Ama asıl alanı bulmak için Jacobian gerekir.

**Jacobian (ters yoldan):**

$$\frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}u_x & u_y\\ v_x & v_y\end{vmatrix}=\begin{vmatrix}y & x\\ 2x & -2y\end{vmatrix}=-2y^2-2x^2=-2(x^2+y^2)$$

Hoca önce $v_y$'yi yanlış söyledi, sonra "eksik bir şey yaptık" diyerek $-2y$'ye düzeltti ve determinantı $-2(x^2+y^2)$ buldu. Buradan

$$|J|=\left|\frac{\partial(x,y)}{\partial(u,v)}\right|=\frac{1}{2(x^2+y^2)}$$

olur.

> **Ders sonrası not:** Hoca Jacobian'ı bulduktan sonra onu "$-v^2$" diye yazdı ve "$v^2$'nin integralini alırız" dedi. Bu yanlıştır. $v=x^2-y^2$'dir, $x^2+y^2$ değildir. Doğrusu $(x^2+y^2)^2=(x^2-y^2)^2+4x^2y^2=v^2+4u^2$ olduğundan
> $$A=\int_1^3\!\int_2^4 \frac{1}{2\sqrt{v^2+4u^2}}\,du\,dv\approx0{,}3246$$
> çıkar (sympy/mpmath ile sayısal olarak hesaplandı). Bu integral elementer yoldan rahat alınmaz. Bu dönüşüm asıl olarak, Örnek 7'deki gibi integrandda $x^2+y^2$ bulunduğunda işe yarar. Hoca ayrıca sonucu "alansa birim kare, hacimse birim küp" diye yorumladı; integrand 1 olduğu için bu bir alandır.

### 6.2 Örnek 7 (Kaynak, Soru 10): $\displaystyle\iint_B (x^2+y^2)\,dA$

Hoca hemen ardından kaynaktaki benzer soruyu açtı ve az önce yaptığının benzeri olduğunu söyledi.

**Soru:** $B$ birinci bölgede, $x^2-y^2=1$, $x^2-y^2=9$, $xy=2$, $xy=4$ hiperbolleriyle sınırlı bölgedir. $\displaystyle I=\iint_B (x^2+y^2)\,dA$ integralini hesaplayın.

**Dönüşüm:** $u=x^2-y^2$ ($1\le u\le9$), $v=xy$ ($2\le v\le4$).

**Jacobian:**

$$\frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}2x & -2y\\ y & x\end{vmatrix}=2x^2+2y^2=2(x^2+y^2)$$

$$dA=\frac{du\,dv}{2(x^2+y^2)}$$

**İntegral:** İntegranddaki $x^2+y^2$, Jacobian'daki $\dfrac{1}{x^2+y^2}$ ile sadeleşir:

$$I=\int_2^4\!\int_1^9 (x^2+y^2)\cdot\frac{1}{2(x^2+y^2)}\,du\,dv=\int_2^4\!\int_1^9 \frac12\,du\,dv=\frac12\cdot8\cdot2=8$$

Sonuç: $8$ (ara adım eklendi; sympy ile doğrulandı). Hoca bu soruyu "çok enteresan, çok güzel" diye niteledi: fonksiyon Jacobian'la kendiliğinden gidiyor.

> **Ders sonrası not:** Hoca sadeleşmeyi anlatırken "birbirini götürüyor ve sıfır oluyor" dedi. Sadeleşince geriye 0 değil, $\frac12$ çarpanı kalır. Ayrıca sınırları koyarken $v$ için "2'den 5'e" dedi; soruda $xy=4$ olduğu için doğrusu 2'den 4'edir. Bu, büyük olasılıkla bir dil sürçmesi ya da altyazı hatasıdır.

## 7. Parabollerle Sınırlı Bölge

### 7.1 Örnek 8 (Kaynak, Soru 11): $\displaystyle\iint_B dx\,dy$

**Soru:** $B$; $y=x^2$, $4y=x^2$, $2x=y^2$, $3x=y^2$ parabolleriyle sınırlı bölgedir. $\displaystyle\iint_B dx\,dy$ integralini hesaplayın.

Hoca öğrencilere "$u$ ve $v$ neye diyeceğiz?" diye sordu. Parabol denklemleri sabit bir oran verecek biçimde düzenlenir:

- $y=x^2$ ve $4y=x^2$ eğrileri için $\dfrac{x^2}{y}$ sırasıyla 1 ve 4 olur. $u=\dfrac{x^2}{y}$, $1\le u\le4$.
- $2x=y^2$ ve $3x=y^2$ eğrileri için $\dfrac{y^2}{x}$ sırasıyla 2 ve 3 olur. $v=\dfrac{y^2}{x}$, $2\le v\le3$.

Hoca "burada en önemli şey bu, bundan sonrası çok kolay" dedi. Ardından aynı soruyu boş tahtada yeniden çözdü.

**Jacobian (ters yoldan):**

$$\frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}u_x & u_y\\ v_x & v_y\end{vmatrix}=\begin{vmatrix}\dfrac{2x}{y} & -\dfrac{x^2}{y^2}\\[6pt] -\dfrac{y^2}{x^2} & \dfrac{2y}{x}\end{vmatrix}=\frac{2x}{y}\cdot\frac{2y}{x}-\frac{x^2}{y^2}\cdot\frac{y^2}{x^2}=4-1=3$$

Hoca kısmi türevleri tek tek buldu ($u_x$'i önce "$2xy$" dedi, sonra "$2x$ bölü $y$" diye düzeltti), ama determinantın değerini söylemedi. Determinant hesabı ara adım olarak eklendi.

$$dx\,dy=\frac{1}{3}\,du\,dv$$

$$\iint_B dx\,dy=\int_2^3\!\int_1^4 \frac13\,du\,dv=\frac13\cdot3\cdot1=1$$

Sonuç: $1$ birim kare (derste söylenmedi; sympy ile doğrulandı). Hoca bu noktada "diyelim ki integrand $u+v$ olsun, buna göre integre ediyoruz ve rahatça sonucu çıkarıyoruz" diyerek yöntemin genel olduğunu belirtti.

> **Ders sonrası not:** Hoca tahtada yeniden yazarken bir denklemi "$y^2=4x$" diye okudu, sonra "$y^2=2x$" dedi. Kaynaktaki soru $2x=y^2$ ve $3x=y^2$'dir. Ayrıca $v$'nin aralığını bir yerde "2'den 4'e", sınırları koyarken de "biri ikiden dörde, diğeri birden üçe" diye söyledi. Doğru aralıklar $1\le u\le4$ ve $2\le v\le3$'tür.

> **Hocanın vurgusu:** Bu dönüşümlerde en önemli şey, integrale yazılacak Jacobian'dır. $du\,dv$ olur ya da başka değişkenler olur, ama Jacobian unutulmaz.

## 8. Kutupsal Koordinatlarla Bir Üçgen Bölge

### 8.1 Örnek 9 (Kaynak): $B=\{1\le x\le2,\ 0\le y\le x\}$

**Soru:** $B$ bölgesinde $\displaystyle\iint_B \frac{y\sqrt{x^2+y^2}}{x}\,dx\,dy$ integralini kutupsal koordinatlar yardımıyla hesaplayın.

<!-- BELİRSİZ: İntegrand altyazıda tam okunmuyor; "kökten kurtuluyor", "y bölü x" ve "R kare dışarıya R olarak çıkar" anlatımından ve kısa nottan kuruldu. -->

Hoca, kökün içinde $x^2+y^2$ olduğu için kutupsala geçmenin zorunlu olduğunu söyledi.

- $x=r\cos\theta$, $y=r\sin\theta$ yazılınca kök kalkar: $\sqrt{x^2+y^2}=r$.
- $\dfrac{y}{x}=\dfrac{\sin\theta}{\cos\theta}=\tan\theta$. $r$'ler sadeleşir.
- Jacobian'dan bir $r$ daha gelir. İntegrand $r\cdot r\cdot\tan\theta=r^2\tan\theta$ olur.

Hoca ardından bölgenin mutlaka çizilmesi gerektiğini söyledi: $x$ 1 ile 2 arasında, $y$ 0'dan $x$'e. Bölgeyi çizdi ama sınırları tamamlamadı.

> **Ders sonrası not:** Hoca $\theta$ için "sıfırdan $2\pi$'ye" dedi. Bölge bir disk değil, $y=0$, $y=x$, $x=1$, $x=2$ ile sınırlı bir yamuktur. Doğru sınırlar:
> - $0\le\theta\le\dfrac{\pi}{4}$ ($y=0$'dan $y=x$'e).
> - $x=1$ doğrusu $r\cos\theta=1$, yani $r=\sec\theta$; $x=2$ doğrusu $r=2\sec\theta$.
> $$\int_0^{\pi/4}\!\int_{\sec\theta}^{2\sec\theta} r^2\tan\theta\,dr\,d\theta=\frac73\int_0^{\pi/4}\sec^3\theta\tan\theta\,d\theta=\frac73\cdot\frac{\sec^3\theta}{3}\Big|_0^{\pi/4}=\frac79\left(2\sqrt2-1\right)\approx1{,}422$$
> Sonuç sympy ile ve kartezyen biçimin sayısal integraliyle doğrulandı.

## 9. İntegrasyon Sırasını Değiştirmeye Dönüş: Bölgeyi Parçalamak

Hoca dersin son kısmında yeniden integrasyon sırasını değiştirmeye döndü. Daha önce yaptığı soruları kısaca hatırlattı: verilen sırayla integral alınamıyorsa bölge çizilir, sıra değiştirilir; içteki zor fonksiyon sabit gibi davranır ve soru çözülür. Bu tip sorularda "sırayı değiştirin" denmeyebilir; bunu fark etmek öğrenciye kalır.

### 9.1 Örnek 10: $\displaystyle\int_0^1\!\int_x^{2x} f\,dy\,dx$

Hoca bunu "elementer ama çok kıymetli bir soru" diye tanıttı.

**Bölge:** $0\le x\le1$, $x\le y\le2x$. Yani $y=x$ ve $y=2x$ doğruları arası, $x=1$'e kadar. $y$, 0'dan 2'ye değişir.

**Sıra değişince:** $y=1$ yatay çizgisi bölgeyi iki parçaya ayırır.

- $0\le y\le1$: Sol sınır $y=2x$ doğrusu, yani $x=y/2$. Sağ sınır $y=x$ doğrusu, yani $x=y$.
- $1\le y\le2$: Sol sınır $x=y/2$, sağ sınır $x=1$ doğrusu.

$$\int_0^1\!\int_x^{2x} f\,dy\,dx=\int_0^1\!\int_{y/2}^{y} f\,dx\,dy+\int_1^2\!\int_{y/2}^{1} f\,dx\,dy$$

Hoca bunu şöyle açıkladı: Bir eğrinin altındaki alandan diğerinin altındaki alan çıkarılınca aradaki alan elde edilir. İkinci parça için 1'in altındaki alandan $y/2$'nin altındaki alan çıkarılır.

> **Hocanın vurgusu:** Burada bölge mecburen iki parçaya ayrılır. Sıra değiştirilirken tek integralle doğrudan yazılamaz.

> **Ders sonrası not:** Hoca ilk parçanın iç sınırını "$y$'den $y/2$'ye" diye söyledi. Bölgede $y/2\le x\le y$ olduğundan doğru sıra alt sınır $y/2$, üst sınır $y$'dir. Parçalı yazımın doğruluğu sympy ile örnek bir $f$ için ($f=xy+1$, iki yazım da $7/8$) denetlendi.

### 9.2 Örnek 11: $\displaystyle\int_0^1\!\int_{\sqrt y}^1 f\,dx\,dy$

**Bölge:** $0\le y\le1$, $\sqrt y\le x\le1$.

- $x=\sqrt y$ eğrisinin iki tarafının karesi alınınca $y=x^2$ elde edilir.
- $y$ negatif olamaz, $x=\sqrt y$ olduğu için $x$ de negatif olamaz. Yalnız parabolün sağ kolu alınır.
- İstenen bölge parabolün altında, $x=1$ doğrusunun solunda kalan kısımdır.

**Sıra değişince:** $x$ 0'dan 1'e, $y$ ise $y=0$'dan $y=x^2$'ye değişir.

$$\int_0^1\!\int_{\sqrt y}^1 f\,dx\,dy=\int_0^1\!\int_0^{x^2} f\,dy\,dx$$

Doğruluğu sympy ile örnek bir $f$ için ($f=xy+1$, iki yazım da $5/12$) denetlendi.

### 9.3 Örnek 12: $\displaystyle\int_2^3\!\int_x^{2x} dy\,dx$

Hoca bu integrali önce verilen sırayla hesapladı:

- İç integral: $\displaystyle\int_x^{2x} dy=2x-x=x$.
- Dış integral: $\displaystyle\int_2^3 x\,dx=\frac{x^2}{2}\Big|_2^3=\frac92-\frac42=\frac52$.

Sonuç: $\dfrac52$ (sympy ile doğrulandı).

> **Ders sonrası not:** Hoca dış integrali "3'ün karesi 9 bölü 3, eksi 2'nin karesi 4 bölü 3" diye söyledi. İlkel $\frac{x^2}{2}$ olduğu için payda 2'dir. Doğrusu $\frac92-\frac42=\frac52$.

Hoca bu soru için sırayı değiştirmeye gerek olmadığını, ama değiştirmek istenirse nasıl yapılacağına bakmak gerektiğini söyledi. Bölgeyi çizdi: $x$ 2'den 3'e, $y$ ise $y=x$ doğrusundan biraz daha yukarıdaki $y=2x$ doğrusuna kadar. Sırayı değiştirmeyi öğrencilere bıraktı. Çözüm aşağıda "Örnek Sorular" bölümündedir.

### 9.4 Kapanış Vurgusu

Hoca çok zor görünen soruların bile yöntem bilinince çok basit çözüldüğünü söyledi. Doğru teknik yerine konunca sonuç tek satırda çıkar. Önemli olan işin özünü anlamak ve üzerinde zaman geçirmektir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:04:57): $\displaystyle\iint_B f(x,y)\,dA$ integrali alanı mı verir, hacmi mi?

> **Çözüm:** $f(x,y)=1$ ise $B$'nin alanını verir. $f\ne1$ ve $f\ge0$ ise $B$ üzerinde $z=f(x,y)$ altındaki cismin hacmini verir. (Bkz. Bölüm 2.)

**Soru 2** (derste sözlü, 00:38:39 ve 01:14:35): Kutupsal koordinatlara geçerken $x$ ve $y$'nin yerine $r\cos\theta$ ve $r\sin\theta$ yazıldı, $dx\,dy$ yerine $dr\,d\theta$ yazıldı. Eksik olan nedir?

> **Çözüm:** Jacobian eksiktir. Kutupsal dönüşümde $J=r$'dir ve integrand $r$ ile çarpılmalıdır: $dx\,dy=r\,dr\,d\theta$. (Bkz. Örnek 4 ve Örnek 5.)

**Soru 3** (derste sözlü, 01:18:17): $u=xy$, $v=x^2-y^2$ dönüşümünde, $xy=2$, $xy=4$, $x^2-y^2=1$, $x^2-y^2=3$ ile sınırlı bölge için $u$ ve $v$ nereden nereye değişir?

> **Çözüm:** $2\le u\le4$, $1\le v\le3$. Bölge $uv$ düzleminde bir dikdörtgene dönüşür. (Bkz. Örnek 6.)

**Soru 4** (derste sözlü, 01:29:50): $y=x^2$, $4y=x^2$, $2x=y^2$, $3x=y^2$ parabolleriyle sınırlı bölgede $u$ ve $v$ neye denmeli?

> **Çözüm:** $u=\dfrac{x^2}{y}$ ($1\le u\le4$), $v=\dfrac{y^2}{x}$ ($2\le v\le3$). Bu durumda $\dfrac{\partial(u,v)}{\partial(x,y)}=3$ ve bölgenin alanı $1$'dir. (Bkz. Örnek 8.)

**Soru 5** (derste sözlü, 01:53:36): $\displaystyle\int_2^3\!\int_x^{2x} dy\,dx$ integralinde integrasyon sırası nasıl değiştirilir?

> **Çözüm (derste verilmedi):** Bölge $2\le x\le3$, $x\le y\le2x$'tir ve $y$ 2'den 6'ya değişir. Sol sınır $x=\max(2,\,y/2)$, sağ sınır $x=\min(3,\,y)$'dir. Kırılma noktaları $y=3$ ve $y=4$'tür, bu yüzden bölge üç parçaya ayrılır:
> $$\int_2^3\!\int_2^{y} dx\,dy+\int_3^4\!\int_2^{3} dx\,dy+\int_4^6\!\int_{y/2}^{3} dx\,dy=\frac12+1+1=\frac52$$
> Sonuç verilen sırayla bulunan $\frac52$ ile aynıdır (sympy ile doğrulandı; parçalı yazım $f=xy+1$ için de iki sırada $215/8$ verdi).

## Dersin Toparlaması

Bu derste çok katlı integrali hesaplamanın üç tekniği işlendi. Birincisi integrasyon sırasını değiştirmektir: bölge çizilir, aynı bölge öbür sırayla yazılır ve gerekirse parçalara ayrılır. $\frac{\sin y}{y}$ ya da $e^{y^2}$ gibi ilkeli elementer olmayan fonksiyonlar bu yolla iç integralde sabit gibi davranır. İkincisi Jacobian ile değişken dönüşümüdür: $x,y$ yeni değişkenlere bağlanır, bölge dikdörtgen gibi düzgün bir bölgeye dönüşür ve integrale $|J|$ çarpanı eklenir. $x,y$'yi yeni değişkenlerle yazmak zorsa ters Jacobian kullanılır. Hiperbol ve parabollerle sınırlı bölgeler bu yöntemin tipik örnekleridir. Üçüncüsü bunun özel bir hâli olan kutupsal koordinatlardır: $x=r\cos\theta$, $y=r\sin\theta$ ve $J=r$.

Hocanın bütün ders boyunca tekrarladığı iki ilke şunlardır: bölge mutlaka çizilmeli ve dönüşümde Jacobian asla unutulmamalı. Ders "yarın görüşmek üzere" sözleriyle bitti; bir sonraki ders 9 Mayıs 2023 Salı günüdür.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
