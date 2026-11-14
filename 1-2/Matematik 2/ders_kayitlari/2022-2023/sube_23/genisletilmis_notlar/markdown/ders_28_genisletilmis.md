# Ders 28 Genişletilmiş Notu: Final Hazırlığı: İntegrasyon Sırası, Kutupsal Koordinatlar, Jacobian ve Ortalama Değer Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Genel Yöntem
- 2. İntegrasyon Sırasını Değiştirme
- 3. Kartezyen İntegrali Kutupsal Koordinatlara Çevirme
- 4. Alan Veren İntegraller
- 5. Kutupsal Koordinatlarla Hacim
- 6. Değişken Dönüşümü ve Jacobian
- 7. Bir Fonksiyonun Bölge Üzerindeki Ortalama Değeri
- 8. Öğrenci Soruları Üzerine Tekrarlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı ve Genel Yöntem

Bu ders dönemin son dersiydi. Hoca dersi tamamen çok katlı integral (multiple integral) soruları çözmeye ayırdı. Sorular çoktan seçmeli biçimdeydi ve hoca bunları ekrana yansıttı. Bazılarını boş bir tahta açıp sıfırdan yeniden çizerek çözdü. Altyazıda yalnız sözlü anlatım olduğu için formüller hocanın okuduğu biçimden kuruldu.

Bütün sorular için hocanın önerdiği yöntem aynıydı:

- Önce sınırlardan integrasyon bölgesini çiz.
- Bölgeyi doğru çizersen soru büyük ölçüde çözülür.
- Sonra istenen işlemi yap: sırayı değiştir, kutupsala çevir ya da yeni değişkenlere geç.
- Şıklar çoğu zaman yalnız sınırlarla ayrışır. Sınırları doğru bulmak yanlış şıkları eler.

> **Hocanın vurgusu:** "Bu şekli çizmek çok önemli." Şekil doğru çizilirse doğru cevaba gitme şansı yüksektir.

Hoca, soruların çoğunda integralin sayısal değerini hesaplamadı. Çoğu soruda yalnız "aşağıdaki integrallerden hangisidir?" diye sorulduğu için yeni integrali yazmak yetiyordu. Bu notta derste hesaplanmayan değerler `> **Çözüm (derste verilmedi):**` bloklarında verildi. Bu değerler sympy ile doğrulandı.

## 2. İntegrasyon Sırasını Değiştirme

Hoca bu konunun önemini dersin başında vurguladı.

> **Hocanın vurgusu:** İntegrasyon sırasını değiştirme sorusundan en az bir tane, belki iki üç tane gelir. Bölge dönüşümünden (Jacobian) de bir iki soru beklenir.

Yöntem şudur. Verilen integralin iç ve dış sınırları bir bölge tanımlar. Önce bu bölge çizilir. Sonra aynı bölge öbür değişkene göre yeniden okunur: dışarıdaki değişken artık sabit sayılar arasında, içerideki değişken ise eğriler arasında değişir.

Hoca sırayı değiştirmenin neden işe yaradığını da açıkladı. Bazı integrallerde içteki integral verilen sırada alınamaz. Örneğin $e^{x^2}$ ya da $e^{\cos x}$ fonksiyonunun $x$'e göre ilkeli temel fonksiyonlarla yazılamaz. Sıra değişince içteki integral sabit gibi davranan bir fonksiyonun integraline dönüşür ve dışarıya, değişken dönüşümüne uygun bir çarpan gelir.

### Örnek 1: Kök sınırlı integral

Soru: Aşağıdaki integralin integrasyon sırası değiştirilirse hangi integral elde edilir?

$$\int_0^1\int_{\sqrt y}^{1}\frac{dx\,dy}{\sqrt{1+3x^3}}$$

<!-- BELİRSİZ: Altyazıda integrand "kök içinde 1 artı 3x kare" diye duyuluyor (00:04:10, 00:06:47). Kısa notta $1+3x^3$ yazılı. İntegrali kolay alınabilir kılan biçim $1+3x^3$'tür; bu notta o biçim kullanıldı, ama tahtadaki üs altyazıdan kesinleşmiyor. -->

Hoca soruyu boş tahtada yeniden yazıp çözdü.

**Bölge.** Dıştaki değişken $y$ ve $0\le y\le1$. İçteki değişken $x$ ve $\sqrt y\le x\le1$. $x=\sqrt y$ eğrisi $y=x^2$ parabolüdür. $x=1$ dikey bir doğrudur. Bölge, parabolün altında, $x=1$ doğrusunun solunda ve $x$ ekseninin üstünde kalan parçadır.

**Yeni sıra.** Şimdi $dy$ içeride, $dx$ dışarıdadır. $x$ değerleri $0$'dan $1$'e kadar değişir. Her $x$ için $y$, $0$'dan parabole, yani $x^2$'ye kadar gider:

$$\int_0^1\int_0^{x^2}\frac{dy\,dx}{\sqrt{1+3x^3}}$$

Hoca, şıklarda bu biçimi bulmanın yettiğini söyledi. Integral hesaplanmak istenirse, içteki integralde integrand $x$'e bağlıdır, $y$'ye göre sabit sayılır. İntegral $y$ olur, sınırlar konunca $x^2$ gelir.

> **Çözüm (derste verilmedi):** $\displaystyle\int_0^1\frac{x^2}{\sqrt{1+3x^3}}\,dx$ integralinde $u=1+3x^3$, $du=9x^2\,dx$ alınır. Sonuç $\dfrac29\sqrt{1+3x^3}\Big|_0^1=\dfrac29(2-1)=\dfrac29$ olur. İntegrand $1+3x^2$ olsaydı sonuç $\dfrac13-\dfrac{\sqrt3}{18}\operatorname{arcsinh}\sqrt3\approx0{,}2066$ olurdu; bu, sorunun $x^3$ ile kurulduğunu büyük olasılıkla gösterir.

### Örnek 2: $\arcsin$ sınırlı integral

Soru: Aşağıdaki integralin sırası değiştirilirse yeni integral hangisidir?

$$\int_0^1\int_{\arcsin y}^{\pi/2}e^{\cos x}\,dx\,dy$$

**Bölge.** $0\le y\le1$ ve $\arcsin y\le x\le\frac\pi2$. $x=\arcsin y$ eğrisinden $y$ çekilirse $y=\sin x$ bulunur. $x=\frac\pi2$ dikey doğrusu üst sınırdır. Bölge, $[0,\frac\pi2]$ aralığında $y=\sin x$ eğrisinin altında kalan parçadır.

Hoca burada bu tür bir soruda "integrasyon bölgesi aşağıdakilerden hangisidir?" diye de sorulabileceğini ekledi.

**Yeni sıra.** $x$, $0$'dan $\frac\pi2$'ye kadar değişir. Her $x$ için $y$, $0$'dan $\sin x$'e kadar gider:

$$\int_0^{\pi/2}\int_0^{\sin x}e^{\cos x}\,dy\,dx$$

**Neden kolaylaşır?** İlk sırada $e^{\cos x}$'in $x$'e göre integrali alınamaz. Hoca bunu şöyle anlattı: $\cos x$'e $u$ desek, türevi olan $-\sin x$ integrandda yoktur. Sıra değişince içteki integral $y$'ye göredir ve $e^{\cos x}$ sabit gibi düşünülür. İntegralden $y$ gelir, üst sınır konunca $\sin x$ olur:

$$\int_0^{\pi/2}\sin x\,e^{\cos x}\,dx$$

Hoca, burada $\cos x=u$ denirse $\sin x\,dx$'in de $-du$ olacağını ve tek katlı integralin değişken dönüşümüyle rahatça alınacağını söyledi.

> **Çözüm (derste verilmedi):** $u=\cos x$ ile sınırlar $1$'den $0$'a gider. $\displaystyle\int_1^0 e^u(-du)=\int_0^1e^u\,du=e-1$.

### Örnek 3: $e^{x^2}$ integrali

Soru: Aşağıdaki integralin sırası değiştirilince yeni integral hangisidir?

$$\int_0^1\int_{3y}^{3}e^{x^2}\,dx\,dy$$

Hoca önce bu integralin verilen sırada neden alınamadığını sordu. $x^2$'ye $u$ desek türevi olan $2x$ integrandda yoktur. Bu yüzden sıra değiştirilir.

**Bölge.** $0\le y\le1$ ve $3y\le x\le3$. $x=3y$ doğrusu, yani $y=\frac x3$, orijinden $(3,1)$ noktasına gider. $x=3$ dikey doğrusu sağ sınırdır. Bölge bu iki doğru ile $x$ ekseni arasındaki üçgendir.

> **Hocanın vurgusu:** "Bunu yazın arkadaşlar. Bu çok önemli bir şey."

**Yeni sıra.** $x$, $0$'dan $3$'e kadar değişir. Her $x$ için $y$, $0$'dan $\frac x3$'e kadar gider:

$$\int_0^3\int_0^{x/3}e^{x^2}\,dy\,dx$$

Hoca hesabı da başlattı. İçteki integralde $e^{x^2}$ sabit gibidir; sonuç $y\,e^{x^2}$ olur. Sınırlar konunca $\frac x3e^{x^2}$ kalır. Hoca, bundan sonrasının çözülmüş sayıldığını söyledi.

> **Ders sonrası not:** Hoca sınırları konuşurken üst sınırı bir yerde "$3y$" diye okudu (00:15:54 ve 00:16:24 civarı). Yeni sırada $y$'nin üst sınırı $x$'e bağlıdır ve doğrusu $\frac x3$'tür. Aynı yerde integrandı bir an "$e^{3x}$" diye okuyup hemen "$e^{x^2}$" diye düzeltti.

> **Çözüm (derste verilmedi):** $\displaystyle\int_0^3\frac x3e^{x^2}\,dx=\frac16e^{x^2}\Big|_0^3=\frac{e^9-1}{6}\approx1350{,}35$.

### Örnek 4: $\dfrac{e^y}{y+1}$ integrali

Soru: Aşağıdaki integralin sırası değiştirilince yeni integral hangisidir?

$$\int_1^4\int_{\sqrt x}^{2}\frac{e^y}{y+1}\,dy\,dx$$

Hoca, bu haliyle integrali almanın "şansımız yok gibi" durduğunu söyledi.

**Bölge.** $1\le x\le4$ ve $\sqrt x\le y\le2$. $y=\sqrt x$ eğrisi ile $y=2$ yatay doğrusu $x=4$'te kesişir. $x=1$ sol sınırdır. Bölge, $y=\sqrt x$ eğrisinin üstünde, $y=2$ doğrusunun altında, $x=1$ doğrusunun sağında kalan parçadır.

**Yeni sıra.** $y$, $1$'den $2$'ye kadar değişir. $y=\sqrt x$ eğrisinden $x$ çekilirse $x=y^2$ olur. Her $y$ için $x$, $1$'den $y^2$'ye kadar gider:

$$\int_1^2\int_1^{y^2}\frac{e^y}{y+1}\,dx\,dy$$

İçteki integralde integrand $x$'e göre sabittir. Hoca hesabı şöyle sürdürdü: integralden $x$ gelir, sınırlar konunca $y^2-1$ olur. $y^2-1=(y-1)(y+1)$ olduğundan $y+1$ ile sadeleşir ve geriye $(y-1)e^y$ kalır. Bundan sonra $y$'ye göre integral almak kolaydır.

> **Çözüm (derste verilmedi):** Kısmi integrasyonla $\displaystyle\int(y-1)e^y\,dy=(y-2)e^y$. Sınırlar konunca $0-(-e)=e$ bulunur.

## 3. Kartezyen İntegrali Kutupsal Koordinatlara Çevirme

Hoca, kutupsal dönüşümden de bir soru geleceğini söyledi. İntegrandda ya da bölgede $x^2+y^2$ görülüyorsa bölge çember parçasıdır ve kartezyen haliyle integral çoğu zaman alınamaz. Bu durumda kutupsal koordinatlara (polar coordinates) geçilir.

**Kutupsal dönüşüm**

- $x=r\cos\theta$, $y=r\sin\theta$.
- $x^2+y^2=r^2$.
- $dx\,dy=r\,dr\,d\theta$. Buradaki $r$, dönüşümün Jacobian'ıdır.
- $\dfrac yx=\tan\theta$, yani $\arctan\dfrac yx=\theta$.

> **Hocanın vurgusu:** Kutupsal koordinatlarda en önemli şey Jacobian'dan gelen $r$'dir. $dx\,dy$ yerine mutlaka $r\,dr\,d\theta$ yazılır.

### Örnek 5: Üçüncü çeyrekte kutupsal dönüşüm

Soru: Verilen kartezyen integral kutupsal dönüşümle yazılınca hangi integral oluşur? Sınırlar şöyle okundu: $-1\le x\le0$, $-\sqrt{1-x^2}\le y\le0$.

<!-- BELİRSİZ: İntegrandın tam ifadesi altyazıda okunmuyor. Hoca yalnız içinde $x^2+y^2$ bulunduğunu ve bunun yerine $r$ geldiğini söylüyor (00:13:01). Kısa nottaki $\frac{2}{1+\sqrt{x^2+y^2}}$ ifadesi altyazıdan doğrulanamadı. -->

**Bölge.** $y=-\sqrt{1-x^2}$ ifadesinin karesi alınırsa $x^2+y^2=1$ bulunur; eksi işaret çemberin alt yarısını verir. $x$ değerleri $-1$ ile $0$ arasında olduğundan bölge, birim çemberin sol alt çeyreğidir (üçüncü çeyrek).

**Dönüşüm.** $x$ yerine $r\cos\theta$, $y$ yerine $r\sin\theta$ yazılır. $x^2+y^2$ görülen her yere $r^2$ gelir. $dx\,dy$ yerine $r\,dr\,d\theta$ yazılır. Üçüncü çeyrekte açı $\pi$'den $\frac{3\pi}{2}$'ye, $r$ ise $0$'dan $1$'e değişir (ara adım eklendi; hoca bu sınırları sözlü okumadı):

$$\int_{\pi}^{3\pi/2}\int_0^1 f(r\cos\theta,r\sin\theta)\,r\,dr\,d\theta$$

> **Çözüm (derste verilmedi):** İntegrand kısa nottaki gibi $\frac{2}{1+\sqrt{x^2+y^2}}$ ise integral $\displaystyle\int_\pi^{3\pi/2}\int_0^1\frac{2r}{1+r}\,dr\,d\theta=\frac\pi2\cdot2(1-\ln2)=\pi(1-\ln2)$ olur. İntegrand altyazıdan doğrulanamadığı için bu sonuç büyük olasılıkla doğru olan biçime aittir.

### Örnek 6: Kaydırılmış çember

Soru: $D$ bölgesi $x^2+y^2=2x$ çemberinin içi ve $f(x,y)=x^2+y^2$ olsun. $\iint_D f\,dA$ integrali kutupsal koordinatlarda hangisidir?

Hoca bunu "çok güzel bir soru" diye niteledi.

**Bölge.** $x^2-2x+y^2=0$ ifadesine $1$ ekleyip çıkarınca $(x-1)^2+y^2=1$ bulunur. Bu, merkezi $(1,0)$, yarıçapı $1$ olan çemberdir. Çember orijinden geçer ve sağ yarı düzlemde kalır.

**İntegrand.** $f=x^2+y^2=r^2$. $dx\,dy$ yerine Jacobian'dan gelen $r$ ile $r\,dr\,d\theta$ yazılır.

**$r$'nin sınırı.** Çember denkleminde $x=r\cos\theta$ yazılırsa:

$$r^2-2r\cos\theta=0\quad\Rightarrow\quad r\,(r-2\cos\theta)=0$$

Ya $r=0$ ya da $r=2\cos\theta$ olur. Yani $r$, $0$'dan $2\cos\theta$'ya kadar tarar.

**Açının sınırı.** Çember sağ yarı düzlemde olduğundan $\theta$, $-\frac\pi2$'den $\frac\pi2$'ye değişir.

$$\iint_D(x^2+y^2)\,dA=\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}r^2\cdot r\,dr\,d\theta=\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}r^3\,dr\,d\theta$$

Hoca son olarak $r^3$'ün nereden geldiğini toparladı: $r^2$ fonksiyondan, bir $r$ de Jacobian'dan gelir.

> **Ders sonrası not:** Altyazıda açı sınırları "eksi 1 bölü 2'den artı 1 bölü 2'ye" diye duyuluyor (00:20:17). Hoca hemen ardından (00:21:43) "eksi $\pi$ bölü 2'den artı $\pi$ bölü 2'ye" diye netleştirdi. Doğrusu $-\frac\pi2\le\theta\le\frac\pi2$.

> **Çözüm (derste verilmedi):** İç integral $\frac{(2\cos\theta)^4}{4}=4\cos^4\theta$. $\displaystyle\int_{-\pi/2}^{\pi/2}4\cos^4\theta\,d\theta=4\cdot\frac{3\pi}{8}=\frac{3\pi}{2}$. Kartezyen hesapla da aynı değer çıkar.

### Örnek 7: Halka dilimi ve $\arctan\frac yx$

Soru: $R$ bölgesi $1\le x^2+y^2\le4$ ve $0\le y\le x$ ile verilsin. Verilen integral kutupsal koordinatlarda hangisidir?

<!-- BELİRSİZ: İntegrandın tamamı altyazıda okunmuyor. Hoca yalnız içinde $\frac yx$'in arktanjantının bulunduğunu ve bunun $\theta$ olduğunu söylüyor (00:27:06). -->

**Bölge.** $x^2+y^2=1$ ve $x^2+y^2=4$ yarıçapı $1$ ve $2$ olan iki çemberdir; bölge aralarındaki halkadır. $y=x$ doğrusu ile $y\ge0$ koşulu ayrıca sınırlar. $0\le y\le x$ olduğundan bölge, $x$ ekseni ile $y=x$ doğrusu arasında kalan halka dilimidir.

**Sınırlar.** $1\le r\le2$. $y=x$ doğrusunda $\tan\theta=1$, yani $\theta=\frac\pi4$. Böylece $0\le\theta\le\frac\pi4$.

**İntegrand.** $\frac yx=\tan\theta$ olduğundan $\arctan\frac yx=\theta$ olur. $dx\,dy$ yerine yine $r\,dr\,d\theta$ gelir.

> **Ders sonrası not:** Hoca önce açının üst sınırını $\frac\pi2$ diye okudu, sonra kendisi düzeltti: "Bu $\pi$ bölü 2 yanlış", doğrusu $\frac\pi4$.

## 4. Alan Veren İntegraller

Bir $D$ bölgesinin alanı $\iint_D dA$ integralidir. Bu sorularda integralin içinde fonksiyon yoktur; yalnız sınırlar doğru yazılmalıdır.

### Örnek 8: $y=\ln(1+x)$ ile sınırlı bölge

Soru: $y=\ln(1+x)$, $x=0$ ve $y=2$ ile sınırlı bölgenin alanını veren integral hangisidir?

**Bölge.** $x=0$ iken $y=\ln1=0$ olur. $x$ arttıkça $y$ artar; fonksiyon artandır. $x=0$ doğrusu $y$ eksenidir. $y=2$ yatay doğrudur. İstenen bölge, $y$ ekseni, $y=2$ doğrusu ve $y=\ln(1+x)$ eğrisi arasında, eğrinin solunda kalan parçadır.

**İntegral.** $y=\ln(1+x)$ eğrisinden $x$ çekilir: $1+x=e^y$, yani $x=e^y-1$. $y$, $0$'dan $2$'ye değişir. Her $y$ için $x$, $y$ ekseninden ($x=0$) eğriye ($x=e^y-1$) kadar gider:

$$A=\int_0^2\int_0^{e^y-1}dx\,dy$$

Hoca şıkları tek tek eledi. $x$'in üst sınırı $e^y$ ya da $e^2-1$ olan şıkların yanlış olduğunu, eğriden çekilen ifadenin $e^y-1$ olması gerektiğini gösterdi.

> **Ders sonrası not:** Hoca bir an sınırı "bu eğriden sıfıra kadar" diye ters okudu, sonra "sıfırdan buraya kadar olması lazım" diye düzeltti. Doğrusu $0\le x\le e^y-1$.

> **Çözüm (derste verilmedi):** $A=\displaystyle\int_0^2(e^y-1)\,dy=e^2-1-2=e^2-3$.

### Örnek 9: Halkanın alt yarısının alanı

Soru: $1\le x^2+y^2\le e^2$ ve $y\le0$ bölgesinin alanını veren kutupsal integral hangisidir?

**Bölge.** Yarıçapı $1$ ve $e$ olan iki çember arasındaki halkanın alt yarısıdır.

**Sınırlar.** Alt yarı olduğu için açı $\pi$'den başlar, $2\pi$'ye kadar döner. $r$, $1$'den $e$'ye değişir. $dx\,dy$ yerine $r\,dr\,d\theta$ gelir:

$$A=\int_\pi^{2\pi}\int_1^e r\,dr\,d\theta$$

> **Hocanın vurgusu:** $dx\,dy$ yerine $dr\,d\theta$ yazarken en önemli şey kutupsal koordinatlarda $r$'nin gelmesidir.

> **Çözüm (derste verilmedi):** $A=\pi\cdot\dfrac{e^2-1}{2}$.

## 5. Kutupsal Koordinatlarla Hacim

Hoca, hacim sorularında integralin içinde mutlaka bir fonksiyon olacağını hatırlattı. Bir $D$ bölgesi üzerinde, alt yüzeyden üst yüzeye kadar olan cismin hacmi:

$$V=\iint_D(\text{yükseklik})\,dx\,dy$$

Yükseklik genelde üst yüzeyin $z$ değeridir (alt yüzey $z=0$ ise). Kutupsala geçince yine $dx\,dy=r\,dr\,d\theta$ yazılır.

### Örnek 10: Paraboloidin altındaki hacim

Soru: $z=4-x^2-y^2$ ve $z=0$ yüzeylerinin sınırladığı cismin hacmini veren integral hangisidir? Soru integrali çözmeyi değil, hacmi veren integrali istiyor.

**Yükseklik.** $z=4-(x^2+y^2)=4-r^2$.

**Bölge.** $z=0$ yazılırsa $x^2+y^2=4$ çıkar. Bu, merkezi orijin, yarıçapı $2$ olan çemberdir. Bu yüzden $0\le r\le2$ ve açı tam tur döner: $0\le\theta\le2\pi$.

$$V=\int_0^{2\pi}\int_0^2(4-r^2)\,r\,dr\,d\theta$$

Hoca şıkların inceliğine dikkat çekti: beş şıkta da açı sınırları, integrand ve $r\,dr\,d\theta$ aynıydı. Şıklar yalnız $r$'nin üst sınırında ayrışıyordu; birinde $2$, birinde $1$. Bu yüzden çemberi doğru bulmak yeterliydi.

> **Hocanın vurgusu:** Şekli doğru çizmek önemlidir. Dikkat edilecek uçlar $r$'nin ve açının gideceği yerlerdir.

> **Çözüm (derste verilmedi):** $\displaystyle\int_0^2(4r-r^3)\,dr=8-4=4$, $V=2\pi\cdot4=8\pi$.

### Örnek 11: Silindir ve $z=4$ ile sınırlı hacim

Soru: $x^2+y^2=1$ ve $z=4$ yüzeyleriyle sınırlı cismin hacmini veren integral hangisidir?

<!-- BELİRSİZ: Yüzeylerin tamamı altyazıda net değil. Hoca "Z eşittir 4, Z eşittir 1 eksi x kare eksi y kare" gibi okuyor ve cismi "kolları aşağı doğru çevrilmiş bir tas" ile $z=4$ düzleminin arasındaki parça diye anlatıyor (01:10:51-01:12:07). Bu yüzden yükseklik fonksiyonu kesinleşmiyor. -->

**Bölge ve sınırlar.** $x^2+y^2=1$, merkezi orijin, yarıçapı $1$ olan çemberdir. Bu yüzden $0\le r\le1$, $0\le\theta\le2\pi$. Hacim yine $\iint_D(\text{yükseklik})\,dx\,dy$ ile yazılır. Yükseklik fonksiyonunda $x^2+y^2$ yerine $r^2$ yazılır ve $dx\,dy$ yerine $r\,dr\,d\theta$ gelir.

### Örnek 12: İki silindir arasındaki hacim

Soru: $z=5-y$ düzleminin altında, $z=0$ düzleminin üstünde, $x^2+y^2=1$ ile $x^2+y^2=2$ silindirleri arasında kalan cismin hacmini veren integral hangisidir?

Hoca, soruda düzlemin "$5=z+y$" biçiminde verildiğini okudu.

**Yükseklik.** $z=5-y$. Kutupsalda $5-r\sin\theta$.

**Bölge.** İki silindir arasında kalan kısımdır; hoca bunu "ortadaki boşluk boş" diye anlattı. Yani taban bir halkadır.

$$V=\int_0^{2\pi}\int_1^{\sqrt2}(5-r\sin\theta)\,r\,dr\,d\theta$$

Hoca, $dx\,dy$ yerine $r\,dr\,d\theta$ yazmanın yanlış şıkların yarısını elediğini, sınırları doğru koymanın da doğru cevaba götürdüğünü söyledi. Açı tam tur döner: $0\le\theta\le2\pi$.

> **Ders sonrası not:** $r$'nin sınırları okunurken altyazıda "sıfırdan nereye kadar? Kök 2'ye kadar" duyuluyor (01:14:55). Cismin ortası boş olduğundan doğru alt sınır $0$ değil $1$'dir: $1\le r\le\sqrt2$. Altyazıdaki "sıfır" sözünün hocanın sözü mü yoksa altyazı hatası mı olduğu kesinleşmiyor.

> **Çözüm (derste verilmedi):** $\sin\theta$'lı terim $[0,2\pi]$ üzerinde sıfır verir. $V=5\cdot2\pi\cdot\dfrac{(\sqrt2)^2-1^2}{2}=5\pi$.

### Örnek 13: Kaydırılmış silindir ve $r=4\sin\theta$

Soru: $x^2+y^2-4y=0$ silindiri, $z=0$ düzlemi ve bir üst yüzey arasındaki cismin hacmini veren integral hangisidir?

<!-- BELİRSİZ: Üst yüzey altyazıda "Z işte Q, X kareye, y kareye" diye duyuluyor (01:16:01). Hocanın "y'yi sıfır yazarsanız z eşittir x olur, doğru" açıklaması, yüzeyin büyük olasılıkla $z=\sqrt{x^2+y^2}$ konisi olduğunu düşündürüyor; ancak kesin değil. -->

Hoca önce üst yüzeyin kesitlerine baktı: $y=0$ yazılınca $z=x$ gibi bir doğru, $x=0$ yazılınca $z=y$ gibi bir doğru çıkıyordu. Sonra tabandaki bölgeyi kutupsala çevirdi.

**$r$'nin sınırı.** $x^2+y^2-4y=0$ denkleminde $x^2+y^2=r^2$ ve $y=r\sin\theta$ yazılır:

$$r^2-4r\sin\theta=0\quad\Rightarrow\quad r\,(r-4\sin\theta)=0$$

Ya $r=0$ ya da $r=4\sin\theta$. Yani $0\le r\le4\sin\theta$. Bu çember $x^2+(y-2)^2=4$ olup üst yarı düzlemde kalır; bu yüzden $0\le\theta\le\pi$ (ara adım eklendi).

Hoca, şıklarda yalnız bu $r$ sınırını bulmanın bile yanlışları elediğini gösterdi: $r$'nin $0$'dan $2$'ye gittiğini söyleyen şıklar hemen düşüyordu.

> **Hocanın vurgusu:** Şıklarda doğruya ulaşmanın pratik yolu sınırları bulmaktır. Burada $r$ sınırı önemli bir ipucudur.

> **Çözüm (derste verilmedi):** Üst yüzey $z=\sqrt{x^2+y^2}=r$ ise $V=\displaystyle\int_0^\pi\int_0^{4\sin\theta}r\cdot r\,dr\,d\theta=\int_0^\pi\frac{64}{3}\sin^3\theta\,d\theta=\frac{64}{3}\cdot\frac43=\frac{256}{9}$. Üst yüzey kesin olmadığından bu değer büyük olasılıkla doğru olan biçime aittir.

## 6. Değişken Dönüşümü ve Jacobian

Hoca bu tipten de mutlaka bir soru geleceğini, belki iki tane geleceğini söyledi.

**Değişken dönüşümü (change of variables)**

- Yeni değişkenler $u=u(x,y)$, $v=v(x,y)$ seçilir. Amaç eğri sınırlı bölgeyi dikdörtgene çevirmektir.
- $dx\,dy=|J|\,du\,dv$, burada $J=\dfrac{\partial(x,y)}{\partial(u,v)}$.
- $u$ ve $v$, $x$ ve $y$ cinsinden verildiyse ters Jacobian hesaplamak daha kolaydır: $J=\dfrac{1}{\dfrac{\partial(u,v)}{\partial(x,y)}}$, yani $1$ bölü $\begin{vmatrix}u_x&u_y\\v_x&v_y\end{vmatrix}$.
- Kutupsal koordinatlarda Jacobian $r$ idi. Burada yerine bulunan değer gelir.

> **Hocanın vurgusu:** En önemli şey Jacobian'dır. Jacobian yazılmazsa sonuç yanlış olur.

### Örnek 14: Paralel doğrularla sınırlı bölge

Soru: $R$ bölgesi $x+y=1$, $x+y=3$, $x-y=0$, $x-y=1$ doğrularıyla sınırlı olsun. $u=x-y$, $v=x+y$ dönüşümüyle

$$\iint_R\frac{x^2-y^2}{\sqrt{1+(x-y)^2}}\,dA$$

integrali hangi biçimde yazılır?

<!-- BELİRSİZ: İntegrandın paydası altyazıda yalnız "1 artı u kare" diye geçiyor (01:22:01). Kısa nottaki $\sqrt{1+(x-y)^2}$ biçimindeki karekök altyazıdan kesinleşmiyor. -->

Hoca, soruda dönüşümün de verildiğini, bunun işi kolaylaştırdığını söyledi.

**Yeni bölge.** $u=x-y$, $0$'dan $1$'e değişir. $v=x+y$, $1$'den $3$'e değişir. Yeni bölge bir dikdörtgendir.

**Jacobian.** Ters Jacobian hesaplanır:

$$\frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}u_x&u_y\\v_x&v_y\end{vmatrix}=\begin{vmatrix}1&-1\\1&1\end{vmatrix}=1\cdot1-(-1)\cdot1=2$$

Buradan $J=\frac12$ ve $dx\,dy=\frac12\,du\,dv$ olur. Hoca bunu kutupsalla karşılaştırdı: orada $r$ geliyordu, burada $\frac12$ geliyor.

**İntegrand.** $x^2-y^2=(x-y)(x+y)=uv$. Paydadaki $x-y$ yerine $u$ yazılır.

$$\int_1^3\int_0^1\frac{uv}{\sqrt{1+u^2}}\cdot\frac12\,du\,dv$$

Hoca doğru cevabın A şıkkı olduğunu söyledi.

> **Çözüm (derste verilmedi):** $\displaystyle\int_0^1\frac{u}{\sqrt{1+u^2}}\,du=\sqrt2-1$, $\displaystyle\int_1^3v\,dv=4$. Sonuç $\frac12\cdot4\cdot(\sqrt2-1)=2(\sqrt2-1)$.

### Örnek 15: Parabollerle sınırlı bölgenin alanı

Soru: $y=x^2$, $y=2x^2$, $x=y^2$, $x=3y^2$ eğrileriyle sınırlı bölgenin alanı, uygun bir dönüşümle hangi integralle verilir?

Hoca, ekrandaki soruda dönüşümün verildiğini, ama sınavda verilmeyebileceğini söyledi ve dönüşümü kendisi kurdu.

**Dönüşümün seçimi.** İlk iki eğride $\frac{y}{x^2}$ ya da $\frac{x^2}{y}$ sabittir. Hoca $u=\frac{x^2}{y}$ seçti. Son iki eğride $\frac{y^2}{x}$ sabittir; $v=\frac{y^2}{x}$ seçildi.

**Yeni sınırlar.**

- $y=x^2$ üzerinde $u=1$; $y=2x^2$ üzerinde $u=\frac12$. Yani $\frac12\le u\le1$.
- $x=y^2$ üzerinde $v=1$; $x=3y^2$ üzerinde $v=\frac13$. Yani $\frac13\le v\le1$.

**Jacobian.** $x$'in $u$'ya göre türevini doğrudan almak zordur; $u$'nun $x$'e göre türevi kolaydır. Bu yüzden ters Jacobian alınır:

$$\frac{\partial(u,v)}{\partial(x,y)}=\begin{vmatrix}\dfrac{2x}{y}&-\dfrac{x^2}{y^2}\\[2mm]-\dfrac{y^2}{x^2}&\dfrac{2y}{x}\end{vmatrix}=\frac{2x}{y}\cdot\frac{2y}{x}-\frac{x^2}{y^2}\cdot\frac{y^2}{x^2}=4-1=3$$

Buradan $dx\,dy=\frac13\,du\,dv$ (ara adım eklendi; hoca determinantın değerini sözlü söylemedi).

$$A=\int_{1/3}^{1}\int_{1/2}^{1}\frac13\,du\,dv$$

> **Ders sonrası not:** Hoca son adımda "$u$ nereden? 2'ye kadar. $v$ nereden? 2'ye kadar" dedi (01:31:47). Bu, az önce bulduğu sınırlarla çelişir. Doğrusu $\frac12\le u\le1$, $\frac13\le v\le1$.

> **Çözüm (derste verilmedi):** $A=\frac13\cdot\frac12\cdot\frac23=\frac19$. Sayısal kontrol de yaklaşık $0{,}111$ verir.

## 7. Bir Fonksiyonun Bölge Üzerindeki Ortalama Değeri

**Ortalama değer (average value)**

- Tek değişkenli fonksiyonlarda olduğu gibi tanımlanır.
- $f_{ort}=\dfrac{1}{\text{Alan}(D)}\displaystyle\iint_D f\,dA$.
- Eşdeğer biçim: $\displaystyle\iint_D f\,dA=f_{ort}\cdot\text{Alan}(D)$.

### Örnek 16: Üçgen üzerinde ortalama değer

Soru: Köşeleri $(0,0)$, $(2,0)$, $(2,2)$ olan üçgen bölgede $f(x,y)=x$ fonksiyonunun ortalama değeri kaçtır?

Hoca bunu "gerçekten sorulması gereken güzel bir soru" diye niteledi.

**Alan.** Dik üçgenin dik kenarları $2$ ve $2$'dir. Alan $\frac{2\cdot2}{2}=2$.

**İntegral.** Üçgenin üst kenarı $(0,0)$ ile $(2,2)$ arasındaki $y=x$ doğrusudur. $x$, $0$'dan $2$'ye; $y$, $0$'dan $x$'e değişir:

$$\iint_D x\,dA=\int_0^2\int_0^x x\,dy\,dx=\int_0^2x^2\,dx=\frac83$$

**Ortalama.** Hoca, şıklarda $\frac83$'ün de bulunabileceğini ama doğru cevap olmadığını söyledi:

$$f_{ort}=\frac{1}{2}\cdot\frac83=\frac43$$

> **Ders sonrası not:** Hoca önce integrali alanla çarpıp $\frac{16}{3}$ dedi. Hemen ardından kendisi düzeltti: alana bölünür, yani $\frac12$ ile çarpılır. Doğru sonuç $\frac43$.

## 8. Öğrenci Soruları Üzerine Tekrarlar

Dersin sonunda hoca, öğrencilerin istediği soruları yeniden çözmeyi önerdi.

**Soru:** Bir öğrenci, yüzeyler arasındaki cismin hacmini veren integralin nasıl seçildiğini sordu. **Cevap:** Hoca yöntemi tekrarladı. Hacim $\iint_D(\text{yükseklik})\,dx\,dy$'dir. Yükseklik soruda verilmiş yüzeyden alınır. Kutupsala geçerken Jacobian'dan gelen $r$ unutulmaz ve $dx\,dy$ yerine $r\,dr\,d\theta$ yazılır. Sonra sınırlar yerine konur.

Hoca ayrıca listedeki benzer sorulardan bir dönüşüm sorusunu ($u=x-y$, $v=x+y$) andı. Bu sorunun Örnek 14'teki ile aynı olduğunu, Jacobian'ın yine $\frac12$ çıktığını söyledi.

<!-- BELİRSİZ: Hoca bu soruyu "x-y, u, x-y, v" diye okuyor (01:28:14); ikinci dönüşümün $x+y$ olduğu, Jacobian'ın $\frac12$ çıktığı sözünden çıkarıldı. -->

## Örnek Sorular

Bu derste video ve kare yoktur. Aşağıdaki sorular hocanın ekrandaki listeden okuyup derste çözdüğü sorulardır. Kaynak saatleri altyazıdandır. Çözümlerin ayrıntısı yukarıdaki ilgili örnekte verildi.

1. (derste sözlü, 00:02:39) $\displaystyle\int_0^1\int_{\sqrt y}^1\frac{dx\,dy}{\sqrt{1+3x^3}}$ integralinin sırası değiştirilirse hangi integral elde edilir? <!-- BELİRSİZ: İntegranddaki üs (x kare / x küp) kesin değil. -->
   - Çözüm (derste): $\displaystyle\int_0^1\int_0^{x^2}\frac{dy\,dx}{\sqrt{1+3x^3}}$. Değeri $\frac29$ (derste verilmedi).
2. (derste sözlü, 00:07:57) $\displaystyle\int_0^1\int_{\arcsin y}^{\pi/2}e^{\cos x}\,dx\,dy$ integralinin sırası değiştirilirse yeni integral hangisidir?
   - Çözüm (derste): $\displaystyle\int_0^{\pi/2}\int_0^{\sin x}e^{\cos x}\,dy\,dx=\int_0^{\pi/2}\sin x\,e^{\cos x}\,dx$. Değeri $e-1$ (derste verilmedi).
3. (derste sözlü, 00:11:15) $-1\le x\le0$, $-\sqrt{1-x^2}\le y\le0$ bölgesindeki integral kutupsal dönüşümle hangi integrale dönüşür? <!-- BELİRSİZ: İntegrand altyazıda yok. -->
   - Çözüm (derste): Bölge birim çemberin üçüncü çeyreği; $x^2+y^2\to r^2$, $dx\,dy\to r\,dr\,d\theta$.
4. (derste sözlü, 00:14:16) $\displaystyle\int_0^1\int_{3y}^3e^{x^2}\,dx\,dy$ integralinin sırası değiştirilince yeni integral hangisidir?
   - Çözüm (derste): $\displaystyle\int_0^3\int_0^{x/3}e^{x^2}\,dy\,dx$. Değeri $\frac{e^9-1}{6}$ (derste verilmedi).
5. (derste sözlü, 00:17:28) $x^2+y^2=2x$ bölgesinde $f=x^2+y^2$ fonksiyonunun iki katlı integrali kutupsal koordinatlarda hangisidir?
   - Çözüm (derste): $\displaystyle\int_{-\pi/2}^{\pi/2}\int_0^{2\cos\theta}r^3\,dr\,d\theta$. Değeri $\frac{3\pi}{2}$ (derste verilmedi).
6. (derste sözlü, 00:23:31) $1\le x^2+y^2\le4$, $0\le y\le x$ bölgesinde içinde $\arctan\frac yx$ bulunan integral kutupsal koordinatlarda hangisidir? <!-- BELİRSİZ: İntegrandın tamamı altyazıda yok. -->
   - Çözüm (derste): $1\le r\le2$, $0\le\theta\le\frac\pi4$, $\arctan\frac yx=\theta$, $dx\,dy\to r\,dr\,d\theta$.
7. (derste sözlü, 00:28:46) $\displaystyle\int_1^4\int_{\sqrt x}^2\frac{e^y}{y+1}\,dy\,dx$ integralinin sırası değiştirilince yeni integral hangisidir?
   - Çözüm (derste): $\displaystyle\int_1^2\int_1^{y^2}\frac{e^y}{y+1}\,dx\,dy$, içteki integral $(y-1)e^y$ verir. Değeri $e$ (derste verilmedi).
8. (derste sözlü, 00:32:52) $y=\ln(1+x)$, $x=0$, $y=2$ ile sınırlı bölgenin alanını veren integral hangisidir?
   - Çözüm (derste): $\displaystyle\int_0^2\int_0^{e^y-1}dx\,dy$. Değeri $e^2-3$ (derste verilmedi).
9. (derste sözlü, 01:04:09) $1\le x^2+y^2\le e^2$, $y\le0$ bölgesinin alanını veren kutupsal integral hangisidir?
   - Çözüm (derste): $\displaystyle\int_\pi^{2\pi}\int_1^e r\,dr\,d\theta$. Değeri $\frac{\pi(e^2-1)}{2}$ (derste verilmedi).
10. (derste sözlü, 01:07:04) $z=4-x^2-y^2$ ve $z=0$ yüzeylerinin sınırladığı cismin hacmini veren integral hangisidir?
    - Çözüm (derste): $\displaystyle\int_0^{2\pi}\int_0^2(4-r^2)\,r\,dr\,d\theta$. Değeri $8\pi$ (derste verilmedi).
11. (derste sözlü, 01:10:22) $x^2+y^2=1$ ve $z=4$ yüzeyleriyle sınırlı cismin hacmini veren integral hangisidir? <!-- BELİRSİZ: Öbür yüzey altyazıdan kesinleşmiyor. -->
    - Çözüm (derste): $0\le\theta\le2\pi$, $0\le r\le1$, yükseklik kutupsala çevrilir, $r\,dr\,d\theta$ yazılır.
12. (derste sözlü, 01:13:13) $z=5-y$ düzleminin altında, $z=0$ düzleminin üstünde, $x^2+y^2=1$ ile $x^2+y^2=2$ silindirleri arasında kalan cismin hacmini veren integral hangisidir?
    - Çözüm (derste, sınır düzeltilmiş): $\displaystyle\int_0^{2\pi}\int_1^{\sqrt2}(5-r\sin\theta)\,r\,dr\,d\theta$. Değeri $5\pi$ (derste verilmedi).
13. (derste sözlü, 01:15:16) $x^2+y^2-4y=0$ silindiri ile $z=0$ ve bir üst yüzey arasındaki cismin hacmini veren integral hangisidir? <!-- BELİRSİZ: Üst yüzey büyük olasılıkla $z=\sqrt{x^2+y^2}$. -->
    - Çözüm (derste): $0\le r\le4\sin\theta$; açı $0\le\theta\le\pi$ (ara adım eklendi).
14. (derste sözlü, 01:19:38) $x+y=1$, $x+y=3$, $x-y=0$, $x-y=1$ bölgesinde $\iint_R\frac{x^2-y^2}{\sqrt{1+(x-y)^2}}\,dA$ integrali $u=x-y$, $v=x+y$ dönüşümüyle hangi biçimde yazılır?
    - Çözüm (derste): $\displaystyle\int_1^3\int_0^1\frac{uv}{\sqrt{1+u^2}}\cdot\frac12\,du\,dv$. Değeri $2(\sqrt2-1)$ (derste verilmedi).
15. (derste sözlü, 01:22:25) $y=x^2$, $y=2x^2$, $x=y^2$, $x=3y^2$ ile sınırlı bölgenin alanı dönüşümle hangi integralle verilir?
    - Çözüm (derste, sınır düzeltilmiş): $u=\frac{x^2}{y}\in[\frac12,1]$, $v=\frac{y^2}{x}\in[\frac13,1]$, $dx\,dy=\frac13\,du\,dv$. Alan $\frac19$ (derste verilmedi).
16. (derste sözlü, 01:24:09) Köşeleri $(0,0)$, $(2,0)$, $(2,2)$ olan üçgende $f(x,y)=x$ fonksiyonunun ortalama değeri kaçtır?
    - Çözüm (derste): $\frac{1}{2}\cdot\frac83=\frac43$.

## Dersin Toparlaması

Bu derste dönemin son konusu olan çok katlı integraller soru çözerek tekrar edildi. Bütün soruların ortak adımı bölgeyi çizmekti. İntegrasyon sırasını değiştirme sorularında bölge çizilip öbür değişkene göre yeniden okundu. Bu, $e^{x^2}$, $e^{\cos x}$ gibi verilen sırada alınamayan integralleri hesaplanabilir yaptı. Kutupsal koordinat sorularında $x^2+y^2=r^2$ yazıldı, çember denkleminden $r$'nin sınırı ($r=2\cos\theta$, $r=4\sin\theta$ gibi) bulundu ve Jacobian'dan gelen $r$ ile $dx\,dy=r\,dr\,d\theta$ kullanıldı. Hacim sorularında integrand yükseklik fonksiyonuydu; alan sorularında integrand $1$'di.

Değişken dönüşümünde amaç bölgeyi dikdörtgene çevirmekti. Jacobian, ters determinant üzerinden hesaplandı: paralel doğrular için $\frac12$, parabol ailesi için $\frac13$ bulundu. Son olarak bir fonksiyonun bölge üzerindeki ortalama değeri, integralin bölgenin alanına bölünmesiyle bulundu. Hoca, bu ders ile dönemin konularının hemen hemen tamamının taranmış olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
