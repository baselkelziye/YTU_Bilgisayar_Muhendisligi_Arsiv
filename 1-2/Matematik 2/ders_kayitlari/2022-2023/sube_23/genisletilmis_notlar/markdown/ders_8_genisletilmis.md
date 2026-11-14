# Ders 8 Genişletilmiş Notu: Parametrik Alan, Vektörler, Skaler ve Vektörel Çarpım, Uzayda Düzlem ve Doğru

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Parametrik Eğrilerde Türev ve Kutupsala Dönüşüm
- 2. Yay Uzunluğu: Kartezyen, Parametrik ve Kutupsal
- 3. Kardiyoidin Çevresi
- 4. Parametrik Olarak Verilen Eğride Alan
- 5. Vektörler ve Skaler Çarpım
- 6. Vektörel Çarpım
- 7. Üçgende Açı ve Karma Çarpım
- 8. Uzayda Düzlem Denklemi
- 9. Uzaklık Formülleri ve Düzlem Demeti
- 10. Uzayda Doğrunun Parametrik ve Simetrik Denklemi
- 11. Çıkmış Soru: İki Düzlem
- 12. Örnek Sorular
- 13. Dersin Toparlaması

## 1. Parametrik Eğrilerde Türev ve Kutupsala Dönüşüm

Ders online yapıldı. Hoca önceki gün (dünkü ders) kutupsal koordinatlara başladıklarını hatırlattı ve oradan devam etti. Tabletteki kalemin rengini "daha dikkat çeksin diye" kırmızıya aldı.

İlk konu, parametrik olarak verilen bir eğride türevdir. Eğri $x=x(t)$, $y=y(t)$ biçiminde verilmiş olsun. Hem $x$ hem $y$ aynı $t$ parametresine bağlıdır. Bu durumda $y$'nin $x$'e göre türevini doğrudan alamayız. Önce $y$'nin $t$'ye göre türevini, sonra $x$'in $t$'ye göre türevini alır ve birbirine böleriz:

$$\frac{dy}{dx}=\frac{dy/dt}{dx/dt}.$$

Hoca bunu "d bölü dt, dx bölü dt" diye okudu ve "bu şekilde devam edip gidiyoruz" dedi. Tahtadaki örnek fonksiyon altyazıda okunmuyor.

<!-- BELİRSİZ: 00:05:12 civarında tahtada parametrik türev için bir örnek fonksiyon var; altyazıda yalnız "y'nin t'ye göre türevi" deniyor, fonksiyonun kendisi anlaşılmıyor. -->

Ardından hoca, Kartezyen bir denklemin kutupsal denkleme nasıl çevrildiğini hatırlattı. Kural basittir:

- $x$ gördüğümüz yere $r\cos\theta$ yazılır.
- $y$ gördüğümüz yere $r\sin\theta$ yazılır.
- Sonra denklemden $r$ çekilir. Çıkan denklem kutupsal denklemdir.

Hoca sınavda bunun tersinin de sorulabileceğini söyledi: Kutupsal bir denklem verilir ve "Kartezyen denklemi aşağıdakilerden hangisidir?" diye sorulur. Bu da aynı dönüşümle, ters yönde yapılır.

<!-- BELİRSİZ: 00:06:22 civarında tahtada bir eğri denklemi verilip kutupsala çevriliyor; denklem altyazıda okunmuyor. -->

## 2. Yay Uzunluğu: Kartezyen, Parametrik ve Kutupsal

Hoca dün görülen yay uzunluğu formüllerini üç gösterim için tek tek hatırlattı.

**Kartezyen koordinatlarda yay uzunluğu:** $y=f(x)$ eğrisinin $x_1$ ile $x_2$ arasındaki uzunluğu

$$L=\int_{x_1}^{x_2}\sqrt{1+(y')^2}\,dx.$$

Hoca alt ve üst sınırı bir ara $\alpha_1$, $\alpha_2$ diye de adlandırdı; "fark etmez" dedi.

**Parametrik koordinatlarda yay uzunluğu:** $x=x(t)$, $y=y(t)$ ise

$$L=\int_{t_1}^{t_2}\sqrt{\big(x'(t)\big)^2+\big(y'(t)\big)^2}\,dt.$$

Hoca bu formülün nereden geldiğinin de gösterilebileceğini söyledi, ama türetmeye girmedi.

**Kutupsal koordinatlarda yay uzunluğu:** Hoca bunu öğrencilere sordu. Kısa bir sessizlikten sonra kendisi yazdı: $r=r(\theta)$ ise

$$L=\int_{\theta_1}^{\theta_2}\sqrt{r^2+\big(r'\big)^2}\,d\theta.$$

| Gösterim | Eğri | Yay uzunluğu |
|---|---|---|
| Kartezyen | $y=f(x)$ | $\displaystyle\int_{x_1}^{x_2}\sqrt{1+(y')^2}\,dx$ |
| Parametrik | $x=x(t),\ y=y(t)$ | $\displaystyle\int_{t_1}^{t_2}\sqrt{(x')^2+(y')^2}\,dt$ |
| Kutupsal | $r=r(\theta)$ | $\displaystyle\int_{\theta_1}^{\theta_2}\sqrt{r^2+(r')^2}\,d\theta$ |

> **Ek bilgi (derste anlatılmadı):** Kutupsal formül, parametrik formülün özel bir hâlidir. $x=r(\theta)\cos\theta$, $y=r(\theta)\sin\theta$ alınıp $\theta$ parametre sayılırsa $(x')^2+(y')^2=r^2+(r')^2$ çıkar. Bu yüzden üç formül aslında aynı fikrin üç yazılışıdır.

## 3. Kardiyoidin Çevresi

### 3.1 Şeklin çizimi

Hoca soruyu şöyle verdi: Bir fonksiyon verilmiş; şeklini çizip çevresini hesaplayınız. Fonksiyon $r=1-\cos\theta$'dır. Hoca bu eğrinin adını hatırlattı: kardiyoid. Adı kardiyolojiden, yani kalpten gelir. $1+\cos\theta$, $1-\sin\theta$ gibi eğriler de aynı ailedendir; başta bir katsayı olması da şekli değiştirmez.

Çizim için dün görülen pratik yöntemler kullanıldı:

- **Simetri:** $\theta$ yerine $-\theta$ konur. $\cos(-\theta)=\cos\theta$ olduğu için fonksiyon çifttir. O hâlde eğri kutup eksenine göre simetriktir. Yalnız üst yarı çizilir, alt yarı simetriğidir.
- **Açı değerleri:** $0$, $\pi/2$, $\pi$ gibi açılar verilir. Hoca $\pi/3$'ün de verilebileceğini ama gerek olmadığını söyledi.
- **Türevin işareti:** Türevin işaretine bakılır. Pozitif olduğu için $r$ bu aralıkta artandır.

Değerler: $\theta=0$'da $r=0$, $\theta=\pi/2$'de $r=1$, $\theta=\pi$'de $r=2$. Üst yarı çizilir, sonra kutup eksenine göre simetriği alınır ve kalp şekli çıkar.

### 3.2 Açının katsayısı değişirse

Hoca bir soru sordu: Fonksiyon $r=1-\cos 2\theta$ olsaydı ne değişirdi? Bu sefer açı olarak $\pi/4$, $\pi/2$ gibi değerler alınır. Hoca değerleri tek tek yerine koydu:

- $\theta=0$: $\cos 0=1$, $r=1-1=0$.
- $\theta=\pi/4$: $2\theta=\pi/2$, $\cos(\pi/2)=0$, $r=1$.
- $\theta=\pi/2$: $2\theta=\pi$, $\cos\pi=-1$, $r=1-(-1)=2$.

Yani açının katsayısı değişince çizimde kullanılan açılar da değişir.

### 3.3 Örnek 1: $r=1-\cos\theta$ kardiyoidinin çevresi

Hoca "Bu kalbin çevresi nedir? Bana söyleyin." diye sordu ve formülü yazdı.

**Verilen:** $r=1-\cos\theta$.

**Adım 1 (türev):** $r'=\sin\theta$.

**Adım 2 (kök içi):** (ara adım eklendi)

$$r^2+(r')^2=(1-\cos\theta)^2+\sin^2\theta=1-2\cos\theta+\cos^2\theta+\sin^2\theta=2-2\cos\theta.$$

Yarım açı formülüyle $1-\cos\theta=2\sin^2(\theta/2)$ olduğundan $2-2\cos\theta=4\sin^2(\theta/2)$ olur. $0\le\theta\le\pi$ aralığında $\sin(\theta/2)\ge0$'dır, dolayısıyla kök $2\sin(\theta/2)$'dir.

**Adım 3 (simetri):** Eğri kutup eksenine göre simetrik olduğu için $0$ ile $\pi$ arası hesaplanır ve 2 ile çarpılır. Hoca bunu ayrıca vurguladı: "Niye iki tane yaptık? Sıfırdan $\pi$'ye kadar, çünkü üst ve alt yarı simetrik."

$$L=2\int_0^{\pi}2\sin\frac{\theta}{2}\,d\theta=4\Big[-2\cos\frac{\theta}{2}\Big]_0^{\pi}=4\,(0+2)=8.$$

**Sonuç:** $L=8$. Hoca "burada dönüşümler önemli" dedi; yani trigonometrik dönüşüm doğru yapılmazsa integral alınamaz. Sonuç sympy ile doğrulandı.

## 4. Parametrik Olarak Verilen Eğride Alan

### 4.1 Kartezyendeki alanı hatırlama

Hoca birinci dönemi (Matematik 1) hatırlattı. $y=f(x)$ eğrisinin altında, $a$ ile $b$ arasındaki alan

$$A=\int_a^b f(x)\,dx=\int_a^b y\,dx$$

dir. İki eğri arasındaki alan ise üstteki eğrinin altındaki alandan alttaki eğrinin altındaki alan çıkarılarak bulunur: $A=\int (y_2-y_1)\,dx$.

### 4.2 Parametrik alan formülü

Hoca bu kısmın "çok önemli" olduğunu söyledi. Eğri $x=x(t)$, $y=y(t)$ biçiminde verilmişse integralde $x$ yerine ne yazılacaktır?

- $y$ zaten $t$'ye bağlıdır: $y=y(t)$.
- $x=x(t)$ ise $dx=x'(t)\,dt$ olur.
- Sınırlar da $t$ cinsinden yazılır: $t_1$'den $t_2$'ye.

Hepsi yerine konunca:

$$A=\int_{t_1}^{t_2}y(t)\,x'(t)\,dt.$$

> **Hocanın vurgusu:** Parametrik verilen eğride alan formülü çok önemlidir: $dx$ yerine $x'(t)\,dt$ yazılır.

> **Ek bilgi (derste anlatılmadı):** $t$ arttıkça $x$ azalıyorsa (eğri sağdan sola çiziliyorsa) bu integral negatif çıkar. Bu durumda ya sınırlar ters çevrilir ya da sonucun mutlak değeri alınır. Alan her zaman pozitif bir büyüklüktür.

### 4.3 Dünkü kutupsal alan örneğinin hatırlatılması

Hoca dünkü dersteki ortak alan örneğini hatırlattı: $r=4\sin\theta$ ve $r=4\cos\theta$ çemberlerinin ortak (kesişim) alanı.

- Önce kesişme noktası bulunur: iki ifade eşitlenir, $4\sin\theta=4\cos\theta$.
- Buradan kesişme açısı bulunur.
- Kesişim bölgesi bu açıyla iki parçaya ayrılır. İki parçanın alanı toplanınca tüm ortak alan elde edilir.

Hoca kesişme açısının $\pi/4$ mü $\pi/6$ mı olduğunu bir an hatırlayamadı ("$\pi/4$ diyelim, ya da 6 hangisiyse").

> **Ders sonrası not:** $4\sin\theta=4\cos\theta$ ise $\tan\theta=1$, yani kesişme açısı $\theta=\pi/4$'tür ($\pi/6$ değil). Sympy ile doğrulandı.

Hoca bu sırada kutupsal alan formülünü de söylemeye başladı, ama yaklaşık 00:19 ile 00:21 arasında sesi kesildi. Öğrenciler o kısmı duymadıklarını söyledi.

<!-- BELİRSİZ: 00:19:10 - 00:20:53 arası hocanın sesi kesik; kutupsal alan formülü ve bu kısımda anlatılanlar altyazıda yok. -->

Ses gelince hoca böyle durumlarda hemen haber verilmesini istedi. Ardından soru sormanın önemine değindi: Sorularla pekişmeyen bilgi kullanılmaya müsait bir bilgi değildir. "Hocam anlamadım, tekrar eder misiniz?" demekten çekinmemek gerekir.

## 5. Vektörler ve Skaler Çarpım

### 5.1 Vektörün bileşenleri

Hoca vektörler konusuna geçti. İki boyutlu uzayda ($\mathbb{R}^2$) bir $\vec a$ vektörünün iki bileşeni vardır: biri $x$ ekseni, biri $y$ ekseni yönünde. Bu yüzden

$$\vec a=a_1\vec i+a_2\vec j$$

yazılır. Şu anda bulunduğumuz üç boyutlu uzayda ($\mathbb{R}^3$) ise vektörün üç bileşeni vardır:

$$\vec a=a_1\vec i+a_2\vec j+a_3\vec k=\langle a_1,a_2,a_3\rangle.$$

Hoca bunu "üç tane lineer bağımsız vektör" ($\vec i,\vec j,\vec k$) üzerinden yazılmış bir vektör olarak tanıttı. Vektörün boyu (normu) bileşenlerin kareleri toplamının kareköküdür: $|\vec a|=\sqrt{a_1^2+a_2^2+a_3^2}$.

### 5.2 Skaler çarpımın tanımı

**Tanım (Skaler çarpım, dot product):**

- $\vec a=\langle a_1,a_2,a_3\rangle$, $\vec b=\langle b_1,b_2,b_3\rangle$ ise $\vec a\cdot\vec b=a_1b_1+a_2b_2+a_3b_3$.
- Birinci bileşenler, ikinci bileşenler ve üçüncü bileşenler kendi aralarında çarpılıp toplanır.
- Sonuç bir **sayıdır** (skalerdir), vektör değildir.
- Hoca buna "iç çarpım" da dedi.

### 5.3 Örnek 2: İki vektörün skaler çarpımı

**Verilen:** $\vec a=2\vec i+3\vec j+4\vec k$, $\vec b=-\vec i-4\vec j+\vec k$.

**Çözüm:**

- Birinci bileşenler: $2\cdot(-1)=-2$.
- İkinci bileşenler: $3\cdot(-4)=-12$.
- Üçüncü bileşenler: $4\cdot1=4$.

$$\vec a\cdot\vec b=-2-12+4=-10.$$

Hoca önce $2\cdot(-1)$'i yanlışlıkla $+2$ alıp sonucu $-6$ buldu, sonra fark edip düzeltti: "$+2$ değil, $-2$; o zaman $-10$ olur." Sonuç sympy ile doğrulandı.

> **Hocanın vurgusu:** Bu tür basit sorularda işlem hatası yapılabiliyor. Bol bol alıştırma yapın. Soru basit ve doğru anlaşılmış olsa bile işlem hatası yüzünden yanlışa düşebilirsiniz.

### 5.4 Skaler çarpımın özellikleri

Hoca skaler çarpımın açıyla bağlantısını verdi:

$$\vec a\cdot\vec b=|\vec a|\,|\vec b|\cos\theta.$$

Burada $\theta$ iki vektör arasındaki açıdır. Bundan ve tanımdan şu özellikler çıkar:

- **Diklik:** $\vec a\perp\vec b$ ise $\theta=90^\circ$, $\cos 90^\circ=0$, dolayısıyla $\vec a\cdot\vec b=0$. Hoca bunun ezberlenecek bir özellik değil, formülden görülmesi gereken bir şey olduğunu söyledi.
- **Değişme:** $\vec a\cdot\vec b=\vec b\cdot\vec a$. Çünkü bileşenler sayı olarak çarpılır ve sayılarda çarpma değişmelidir.
- **Dağılma:** $\vec a\cdot(\vec b+\vec c)=\vec a\cdot\vec b+\vec a\cdot\vec c$. Hoca, tersten de yazılabileceğini ekledi: $(\vec b+\vec c)\cdot\vec a=\vec b\cdot\vec a+\vec c\cdot\vec a$.
- **Skalerle çarpım:** $(k\vec a)\cdot\vec b=k(\vec a\cdot\vec b)$.
- **Aynı yönde paralellik:** $\vec a$ ile $\vec b$ paralel ve aynı yönde ise aralarındaki açı $0$'dır. $\cos 0=1$ olduğu için $\vec a\cdot\vec b=|\vec a|\,|\vec b|$ olur.

### 5.5 Örnek 3: Skaler çarpım ve iki vektör arasındaki açı

Hoca basit olsun diye iki bileşenli iki vektör verdi ve iki soru sordu: (1) $\vec a\cdot\vec b$ nedir? (2) $\vec a$ ile $\vec b$ arasındaki açı nedir?

**Verilen:** $\vec a=3\vec i-4\vec j$, $\vec b=8\vec i-6\vec j$.

**(1) Skaler çarpım:**

$$\vec a\cdot\vec b=3\cdot8+(-4)(-6)=24+24=48.$$

**(2) Açı:** $\vec a\cdot\vec b=|\vec a|\,|\vec b|\cos\theta$ formülünden $\cos\theta$ çekilir.

- $|\vec a|=\sqrt{3^2+(-4)^2}=\sqrt{9+16}=5$.
- $|\vec b|=\sqrt{8^2+(-6)^2}=\sqrt{64+36}=10$.

$$\cos\theta=\frac{48}{5\cdot10}=\frac{48}{50}=\frac{24}{25}\quad\Rightarrow\quad\theta=\arccos\frac{24}{25}.$$

Hoca, rastgele değer verdiği için açının özel bir açı çıkmadığını söyledi. Cevap "kosinüsü $24/25$ olan açı", yani $\arccos(24/25)$ olarak bırakılır. Sonuç sympy ile doğrulandı ($\theta\approx16{,}26^\circ$).

> **Ders sonrası not:** Hoca soruyu yazarken $\vec b$'yi altyazıda "$6\vec i-6\vec j$" gibi söyledi, ama hesapta $8\vec i-6\vec j$ kullandı ($3\cdot8=24$, $|\vec b|=\sqrt{64+36}=10$). $48$, $10$ ve $24/25$ sonuçları ancak $\vec b=8\vec i-6\vec j$ ile tutar.

## 6. Vektörel Çarpım

### 6.1 Tanım ve özellikler

**Tanım (Vektörel çarpım, cross product):**

- $\vec a\times\vec b$ bir **vektördür**.
- Boyu $|\vec a\times\vec b|=|\vec a|\,|\vec b|\sin\theta$'dır.
- Determinantla hesaplanır:

$$\vec a\times\vec b=\begin{vmatrix}\vec i&\vec j&\vec k\\a_1&a_2&a_3\\b_1&b_2&b_3\end{vmatrix}.$$

- İlk satıra $\vec i,\vec j,\vec k$, ikinci satıra $\vec a$'nın, üçüncü satıra $\vec b$'nin bileşenleri yazılır. Determinant açılınca $(\ldots)\vec i+(\ldots)\vec j+(\ldots)\vec k$ biçiminde bir vektör çıkar.

Hoca tahtadaki yazımda boy (norm) işaretinin eksik olduğunu belirtti: Formülde $|\vec a\times\vec b|$ yazılmalıdır.

**Özellikler:**

- $\vec a\times\vec b=-(\vec b\times\vec a)$. Sıra değişince vektörün yönü ters döner.
- $\vec a\times(\vec b+\vec c)=\vec a\times\vec b+\vec a\times\vec c$.
- $\vec a\parallel\vec b$ ise $\vec a\times\vec b=\vec 0$.

### 6.2 Kosinüs mü sinüs mü?

Paralellik özelliğini açıklarken hoca önce şöyle dedi: "$\vec a\times\vec b$, $\vec a$'nın boyu, $\vec b$'nin boyu, aradaki açının kosinüsü; paralelse kosinüs sıfır olur." Sonra hemen düzeltti: Vektörel çarpımda sinüs vardır. Paralel vektörler arasındaki açı $0$'dır ve $\sin 0=0$ olduğu için çarpım sıfırdır. Hoca bu sırada skaler çarpım için de bir kez "sinüs" dedi, ardından onu da düzeltti.

> **Hocanın vurgusu:** Skaler çarpımda açının **kosinüsü**, vektörel çarpımda açının **sinüsü** vardır. Buraya dikkat edin.

> **Ders sonrası not:** Hoca konuşurken iki kez kosinüs ile sinüsü karıştırdı, sonra düzeltti. Doğrusu: $\vec a\cdot\vec b=|\vec a||\vec b|\cos\theta$, $|\vec a\times\vec b|=|\vec a||\vec b|\sin\theta$. Paralel vektörlerde vektörel çarpımın sıfır olmasının nedeni $\sin 0=0$'dır, "kosinüsün sıfır olması" değildir ($\cos 0=1$).

### 6.3 Vektörel çarpımın geometrik anlamı

Hoca tahtaya bir düzlem çizdi ve üzerinde $A$ noktasından çıkan iki vektör gösterdi. Bu iki vektörün vektörel çarpımı, ikisinin bulunduğu düzleme **dik** bir vektördür. Bu vektöre düzlemin **normali** denir.

Hoca bunu sonra genel harflerle de gösterdi: $\overrightarrow{AB}=\langle a,b,c\rangle$ ve $\overrightarrow{AC}=\langle d,e,f\rangle$ ise

$$\overrightarrow{AB}\times\overrightarrow{AC}=\begin{vmatrix}\vec i&\vec j&\vec k\\a&b&c\\d&e&f\end{vmatrix}=k\,\vec i+l\,\vec j+m\,\vec k$$

olur ve bulunan bu vektör, iki vektörün belirlediği düzleme diktir.

Hoca ayrıca vektörel çarpımın "şiddetinin alanı verdiğini" söyledi. Yani $|\vec a\times\vec b|$, iki vektörün oluşturduğu paralelkenarın alanıdır. Bir üçgende $\frac12|\overrightarrow{AB}\times\overrightarrow{AC}|$ üçgenin alanını verir. Hoca bunu bir örnekte göstermek istedi, ama "bir mola verelim, sonra soruları çözeriz" diyerek araya geçti.

### 6.4 Karma çarpım

Hoca karma çarpımın (triple product) özelliklerinin ekranda olduğunu, bunları not alabileceklerini söyledi; ayrıntıya girmedi. Kullandığı fikir şudur: $\overrightarrow{AC}\times\overrightarrow{AD}$ düzleme dik bir vektördür; bu vektör $\overrightarrow{AB}$ ile skaler çarpılınca bir **sayı** çıkar. Bu sayı, üç vektörün belirlediği paralelyüzün (hacmi ile ilgili) değeridir.

> **Ek bilgi (derste anlatılmadı):** $\vec a\cdot(\vec b\times\vec c)$ karma çarpımı, satırları $\vec a$, $\vec b$, $\vec c$'nin bileşenleri olan $3\times3$ determinanta eşittir. Mutlak değeri, bu üç vektörün kenar olduğu paralelyüzün hacmidir. Üç vektör aynı düzlemdeyse paralelyüz "yassılaşır", hacim ve dolayısıyla determinant sıfır olur.

Mola öncesinde bir öğrenci ders notlarını sordu. Hoca notları üniversitenin sistemine (AVES) yükleyeceğini, oradan alınabileceğini söyledi. Sonra yaklaşık 15 dakikalık bir ara verildi.

## 7. Üçgende Açı ve Karma Çarpım

### 7.1 Örnek 4: ABC üçgeninde $A$ açısı

Hoca ekrandaki bir soruyu gösterdi: $A$, $B$, $C$ (ve $D$) noktaları verilmiş; $ABC$ üçgeninin $A$ açısı bulunacak.

**Yöntem:** $A$ ve $B$ noktaları belli olduğu için $\overrightarrow{AB}$, $A$ ve $C$ belli olduğu için $\overrightarrow{AC}$ bulunur. $A$ açısı, bu iki vektör arasındaki açıdır:

$$\cos A=\frac{\overrightarrow{AB}\cdot\overrightarrow{AC}}{|\overrightarrow{AB}|\,|\overrightarrow{AC}|}.$$

**Verilen vektörler:** Altyazıda noktaların koordinatları okunmuyor. Hoca vektörlerin bileşenlerini söyledi: $\overrightarrow{AB}=\langle-1,-2,6\rangle$. $\overrightarrow{AC}$'nin bileşenleri bu kısımda tam okunmuyor; ancak aynı soru takımında $\overrightarrow{AC}$ "$-3,\ 3,\ 3$" diye okunuyor (01:02:44), ve aşağıdaki boy ile sonuç bununla tutuyor. Bu yüzden $\overrightarrow{AC}=\langle-3,3,3\rangle$ alındı.

<!-- BELİRSİZ: 00:39:45'te üçüncü bileşenlerin çarpımı "eksi üç" diye geçiyor; AC=<-3,3,3> ile bu çarpım 6·3=18 olmalı. Noktaların koordinatları altyazıda yok. -->

**Boylar:**

- $|\overrightarrow{AB}|=\sqrt{(-1)^2+(-2)^2+6^2}=\sqrt{1+4+36}=\sqrt{41}$.
- $|\overrightarrow{AC}|=\sqrt{9+9+9}=\sqrt{27}=3\sqrt3$.

**Skaler çarpım:** (ara adım eklendi: üçüncü çarpım)

$$\overrightarrow{AB}\cdot\overrightarrow{AC}=(-1)(-3)+(-2)(3)+6\cdot3=3-6+18=15.$$

**Açı:**

$$\cos A=\frac{15}{\sqrt{41}\cdot\sqrt{27}}=\frac{15}{\sqrt{1107}}=\frac{15}{3\sqrt{123}}=\frac{5}{\sqrt{123}}.$$

Aradan sonra hoca bu örneğe döndü ve sonucun "kosinüsü $5/\sqrt{123}$" olan açı çıktığını söyledi: $A=\arccos\dfrac{5}{\sqrt{123}}$. Şıklı bir soruda "aşağıdakilerden hangisidir?" denirse bu değer aranır. Sonuç sympy ile doğrulandı ($A\approx63{,}2^\circ$).

### 7.2 Örnek 5: Dört nokta aynı düzlemde ise $m$ kaçtır?

Hoca bir çıkmış soru tipini ekranda gösterdi. Dört nokta $A$, $B$, $C$, $D$ verilmiş; noktalardan birinin koordinatında bilinmeyen $m$ var. Dört nokta aynı düzlemde ise $m$ nedir?

**Fikir:** Dört noktadan $A$ başlangıçlı üç vektör elde edilir: $\overrightarrow{AB}$, $\overrightarrow{AC}$, $\overrightarrow{AD}$. Dört nokta aynı düzlemdeyse bu üç vektör de aynı düzlemdedir. Bu durumda belirledikleri paralelyüzün hacmi sıfırdır, yani karma çarpımları sıfırdır:

$$\overrightarrow{AB}\cdot\big(\overrightarrow{AC}\times\overrightarrow{AD}\big)=\begin{vmatrix}-1&-2&6\\-3&3&3\\m-1&5&7\end{vmatrix}=0.$$

**Verilen vektörler:** $\overrightarrow{AB}=\langle-1,-2,6\rangle$, $\overrightarrow{AC}=\langle-3,3,3\rangle$, $\overrightarrow{AD}=\langle m-1,5,7\rangle$.

**Çözüm:** (ara adım eklendi) Determinant birinci satıra göre açılır:

$$-1\,(3\cdot7-3\cdot5)-(-2)\big(-3\cdot7-3(m-1)\big)+6\big(-3\cdot5-3(m-1)\big)$$
$$=-6+2(-18-3m)+6(-12-3m)=-6-36-6m-72-18m=-24m-114.$$

$-24m-114=0$ ise $m=-\dfrac{114}{24}=-\dfrac{19}{4}$.

Hoca determinantı sıfıra eşitleyip $m$'yi buldu; ancak söylediği sonuç altyazıda anlaşılmıyor ("m ne oluyor, 5'tir, eksi 3 olarak").

<!-- BELİRSİZ: 01:02:44'te hocanın bulduğu m değeri altyazıda okunmuyor; AC vektörünün bileşenleri de "eksi 3 artı 3, 3" diye geçiyor. -->

> **Ders sonrası not:** Altyazıdan okunan vektörlerle ($\overrightarrow{AC}=\langle-3,3,3\rangle$) determinant $-24m-114$ çıkar ve $m=-19/4$ olur (sympy ile doğrulandı). Hocanın söylediği değer bundan farklıysa, büyük olasılıkla ekrandaki vektörlerden biri altyazıda yanlış okunmuştur. Kuralın kendisi değişmez: aynı düzlemdeki dört nokta için karma çarpım sıfırdır.

> **Hocanın vurgusu:** Bu kuralı (aynı düzlemdeki dört nokta için karma çarpım sıfır) bilirseniz soru çözülür; bilmezseniz çözülmez.

Hoca bu sırada öğrencilere determinantı bilip bilmediklerini sordu; bir öğrenci bildiklerini söyledi.

## 8. Uzayda Düzlem Denklemi

### 8.1 Düzlem denkleminin çıkarılışı

Hoca "vektörler bitti" diyerek uzayda düzleme geçti. Soru şudur: Bir $D$ düzleminin denklemini nasıl elde ederiz?

Bir düzlemi belirlemek için iki şey yeterlidir:

- Düzlemin geçtiği bir nokta: $P_0(x_0,y_0,z_0)$.
- Düzleme dik bir vektör, yani **normal**: $\vec n=a\vec i+b\vec j+c\vec k$.

Hoca bunu "bir noktadan geçen ve bir doğruya dik olan düzlem" diye de ifade etti; burada o doğru normal doğrultusudur.

**Türetme:**

1. Düzlem üzerinde keyfi (değişken) bir nokta $P(x,y,z)$ alınır. $P_0$ sabit, belli bir noktadır; $P$ ise düzlem üzerinde dolaşan, bilinmeyen bir noktadır.
2. $P_0$'ı $P$'ye birleştiren vektör yazılır:
$$\overrightarrow{P_0P}=(x-x_0)\vec i+(y-y_0)\vec j+(z-z_0)\vec k.$$
3. $\overrightarrow{P_0P}$ düzlemin içindedir. $\vec n$ düzleme diktir. Dolayısıyla aralarındaki açı $90^\circ$'dir ve skaler çarpımları sıfırdır:
$$\vec n\cdot\overrightarrow{P_0P}=0.$$
4. Skaler çarpım açılınca düzlem denklemi çıkar:

$$a(x-x_0)+b(y-y_0)+c(z-z_0)=0.$$

Parantezler açılırsa $ax+by+cz-(ax_0+by_0+cz_0)=0$ olur. Sabit terime $d$ denirse genel biçim

$$ax+by+cz+d=0$$

elde edilir.

**Teorem (Düzlemin normali):**

- $ax+by+cz+d=0$ düzleminin normali $\vec n=\langle a,b,c\rangle$'dir.
- Yani normal, $x$, $y$, $z$'nin katsayılarından doğrudan okunur.

Hoca bunu bir düzlem üzerinde gösterdi: $x$'in katsayısı $a$, $y$'nin katsayısı $-4$, $z$'nin katsayısı $-7$ olan bir düzlemin normali bu katsayılardan oluşur.

<!-- BELİRSİZ: 01:12:52'de hocanın normalini okuduğu düzlemin denklemi altyazıda tam okunmuyor; yalnız y katsayısı -4 ve z katsayısı -7 olarak geçiyor. -->

### 8.2 Örnek 6: Bir noktadan geçen ve bir vektöre dik düzlem

**Soru:** $P_0$ noktasından geçen ve $\vec v=3\vec i-2\vec j+4\vec k$ vektörüne dik olan düzlemin denklemini bulunuz.

**Çözüm:** $\vec v$ düzleme dik olduğu için düzlemin normalidir. Düzlemde değişken bir $P(x,y,z)$ noktası alınır. Hoca öğrencilere $\overrightarrow{P_0P}$'yi sordu ve şöyle yazdı:

$$\overrightarrow{P_0P}=(x-1)\vec i+(y+1)\vec j+(z-3)\vec k.$$

Buna göre $P_0=(1,-1,3)$'tür. $\vec v\perp\overrightarrow{P_0P}$ olduğu için $\vec v\cdot\overrightarrow{P_0P}=0$:

$$3(x-1)-2(y+1)+4(z-3)=0.$$

Düzenlenirse (ara adım eklendi): $3x-3-2y-2+4z-12=0$, yani

$$3x-2y+4z-17=0.$$

> **Ders sonrası not:** Hoca $\overrightarrow{P_0P}$'yi yazarken $z-3$ dedi, skaler çarpımı açarken ise "$4$ çarpı $z$ artı $3$" dedi. $P_0=(1,-1,3)$ ise doğrusu $4(z-3)$'tür ve düzlem $3x-2y+4z-17=0$ olur (sympy ile doğrulandı). Noktanın kendisi altyazıda ayrıca söylenmediği için büyük olasılıkla $P_0=(1,-1,3)$'tür.

### 8.3 Örnek 7: Üç noktadan geçen düzlem

**Soru:** $A$, $B$, $C$ noktaları verilmiş. Bu üç noktadan geçen düzlemin denklemini bulunuz.

**Yöntem:**

1. $\overrightarrow{AB}$ ve $\overrightarrow{AC}$ bulunur. İkisi de düzlemin içindedir.
2. $\overrightarrow{AB}\times\overrightarrow{AC}$ hesaplanır. Bu vektör iki vektöre de, dolayısıyla düzleme diktir: düzlemin normalidir.
3. Normal ve noktalardan biri (ör. $A$) ile $a(x-x_0)+b(y-y_0)+c(z-z_0)=0$ yazılır.

Hoca determinantı "sırayı tutarak" açıp normali bulduğunu söyledi. Noktaların koordinatları altyazıda geçmiyor.

<!-- BELİRSİZ: 01:13:58 - 01:14:40 arasındaki üç noktanın koordinatları ve bulunan düzlem altyazıda yok. -->

## 9. Uzaklık Formülleri ve Düzlem Demeti

### 9.1 Noktanın doğruya ve düzleme uzaklığı

Hoca iki uzaklık formülünü verdi.

**Düzlemde noktanın doğruya uzaklığı:** $(x_0,y_0)$ noktasının $ax+by+c=0$ doğrusuna uzaklığı

$$d=\frac{|ax_0+by_0+c|}{\sqrt{a^2+b^2}}.$$

**Uzayda noktanın düzleme uzaklığı:** $(x_0,y_0,z_0)$ noktasının $ax+by+cz+d=0$ düzlemine uzaklığı

$$\text{uzaklık}=\frac{|ax_0+by_0+cz_0+d|}{\sqrt{a^2+b^2+c^2}}.$$

İki formül aynı yapıdadır: Nokta, doğrunun ya da düzlemin denkleminde yerine konur; çıkan değerin mutlak değeri normalin boyuna bölünür. Hoca formülleri sözlü verirken mutlak değeri ayrıca söylemedi; uzaklık negatif olamayacağı için mutlak değer gereklidir.

### 9.2 İki düzlemin ara kesitinden geçen düzlem

**Teorem (Düzlem demeti):**

- $P_1=0$ ve $P_2=0$ iki düzlem olsun ($P_1$, $P_2$ düzlem denklemlerinin sol tarafları).
- Bu iki düzlemin ara kesit doğrusundan geçen her düzlem $P_1+\lambda P_2=0$ biçiminde yazılır.
- $\lambda$, düzlemin geçmesi istenen ek bir noktadan bulunur.

**Örnek 8:** Hoca iki düzlem ve bir nokta verdi. Nokta $(1,1,3)$ idi. İki düzlem denklemi $P_1+\lambda P_2=0$ biçiminde yazıldı, nokta yerine konup düzenlendi ve $\lambda$ bulundu. Bulunan $\lambda$ geri yerine yazılınca, iki düzlemin ara kesitinden ve verilen noktadan geçen üçüncü düzlem elde edildi.

<!-- BELİRSİZ: 01:17:00 - 01:17:29 arasında iki düzlemin denklemleri altyazıda yok; bulunan λ değeri "eksi bir bölü 4 olan 3" diye geçiyor, okunmuyor. -->

Hoca bunu bir çizimle de gösterdi: İki düzlem bir doğru boyunca kesişir. Bu doğrudan geçen sonsuz sayıda düzlem vardır; $\lambda$ değiştikçe bu düzlemlerden biri seçilir.

## 10. Uzayda Doğrunun Parametrik ve Simetrik Denklemi

### 10.1 Türetme

Uzayda bir doğruyu belirlemek için:

- Doğrunun geçtiği bir nokta: $P_0(x_0,y_0,z_0)$.
- Doğruya paralel bir vektör, yani **yön vektörü**: $\vec v=a\vec i+b\vec j+c\vec k$.

Doğru üzerinde değişken bir $P(x,y,z)$ noktası alınır. $\overrightarrow{P_0P}=(x-x_0)\vec i+(y-y_0)\vec j+(z-z_0)\vec k$ vektörü doğrunun üzerindedir, yani $\vec v$'ye paraleldir.

Hoca iki kuralı yan yana hatırlattı:

- İki vektör **dik** ise skaler çarpımları sıfırdır.
- İki vektör **paralel** ise bileşenleri orantılıdır; oranları bir sabittir.

Paralellikten:

$$\frac{x-x_0}{a}=\frac{y-y_0}{b}=\frac{z-z_0}{c}=k.$$

Bu, doğrunun **simetrik denklemidir**.

Her oran sabite eşitlenip çekilirse: $x-x_0=ak$, yani $x=x_0+ak$. Hoca sabite $k$ ya da $t$ denmesinin fark etmediğini söyledi ve $t$ ile yazdı:

$$x=x_0+at,\qquad y=y_0+bt,\qquad z=z_0+ct.$$

Bu da doğrunun **parametrik denklemidir**.

### 10.2 Örnek 9: Bir noktadan geçen ve bir vektöre paralel doğru

**Soru:** $P_0$ noktasından geçen ve $\vec v$ vektörüne paralel olan doğrunun parametrik ve simetrik denklemlerini bulunuz.

**Çözüm:** $\overrightarrow{P_0P}=(x-x_0)\vec i+(y-y_0)\vec j+(z-z_0)\vec k$ yazılır. $\overrightarrow{P_0P}\parallel\vec v$ olduğu için bileşenlerin $\vec v$'nin bileşenlerine oranı bir sabittir ($t$). Bu yazılınca simetrik denklem çıkar. Paydalar karşı tarafa çarpım olarak geçirilip $x$, $y$, $z$ yalnız bırakılınca parametrik denklem çıkar. Hoca bir bileşen için "$x$ eşittir $1$ artı ..." biçiminde yazdı.

<!-- BELİRSİZ: 01:20:48 - 01:22:23 arasındaki örnekte P0 noktası ve v vektörü altyazıda okunmuyor; yalnız "x = 1 artı ..." ve bir bileşende "2" katsayısı geçiyor. -->

Hoca konunun anlaşılıp anlaşılmadığını sordu; öğrenciler anlaşıldığını söyledi.

## 11. Çıkmış Soru: İki Düzlem

### 11.1 Soru

Hoca dersin sonunda, "gelebilecek şeyleri içinde barındıran" bir çıkmış soru çözdü. İki düzlem verilmiş:

- $D_1:\ 3x-y+z-1=0$.
- $D_2$: normali $\vec n_2=\langle1,2,-4\rangle$ olan düzlem.

Şıklar:

- **a)** $D_1$ ve $D_2$ düzlemlerini dik kesen ve $P$ noktasından geçen düzlemin denklemini bulunuz.
- **b)** $D_1$ ve $D_2$ düzlemlerinin ara kesit doğrusunu yazınız.
- **c)** Bu iki düzlemin ara kesitinden ve bir noktadan geçen düzlemin denklemini yazınız.
- **d)** $D_1$ ile $D_2$ arasındaki açıyı bulunuz.

<!-- BELİRSİZ: D2'nin denklemi altyazıda tam okunmuyor; yalnız normalinin 1, 2, -4 olduğu söyleniyor. c şıkkındaki noktanın koordinatları da yok. -->

Hoca önce şunu vurguladı: Düzlemlerle ilgili bütün bu sorularda düzlemlerin kendileriyle değil, **normalleriyle** çalışılır.

**Normaller:**

- $D_1$ için: $x$'in katsayısı $3$, $y$'nin katsayısı $-1$, $z$'nin katsayısı $1$. Yani $\vec n_1=\langle3,-1,1\rangle$.
- $D_2$ için: $\vec n_2=\langle1,2,-4\rangle$.

> **Ders sonrası not:** Hoca $\vec n_1$'i okurken "$y$'nin katsayısı $1$" dedi. Doğrusu $-1$'dir ($-y$ terimi). Hesapta $-1$ kullanılmıştır; aşağıdaki $\langle2,13,7\rangle$ sonucu ancak $-1$ ile çıkar.

### 11.2 a) İki düzlemi de dik kesen ve $P$'den geçen düzlem

İstenen düzlem hem $D_1$'i hem $D_2$'yi dik kesiyor. Bu, istenen düzlemin normalinin hem $\vec n_1$'e hem $\vec n_2$'ye dik olması demektir. İki vektöre birden dik vektör, vektörel çarpımla bulunur:

$$\vec n=\vec n_1\times\vec n_2=\begin{vmatrix}\vec i&\vec j&\vec k\\3&-1&1\\1&2&-4\end{vmatrix}.$$

Determinant açılır (ara adım eklendi):

- $\vec i$: $(-1)(-4)-(1)(2)=4-2=2$.
- $\vec j$: $-\big(3\cdot(-4)-1\cdot1\big)=-(-13)=13$.
- $\vec k$: $3\cdot2-(-1)\cdot1=6+1=7$.

$$\vec n=2\vec i+13\vec j+7\vec k.$$

Hoca bulunan vektörün $\vec n_1$'e dik olduğunu kontrol etmek için skaler çarpımın sıfır olması gerektiğini söyledi: dikse $\cos 90^\circ=0$ olduğu için skaler çarpım sıfırdır. Gerçekten (ara adım eklendi) $\vec n\cdot\vec n_1=6-13+7=0$ ve $\vec n\cdot\vec n_2=2+26-28=0$'dır.

Düzlemin geçtiği nokta $P=(1,0,3)$'tür (hocanın yazdığı denklemden). Düzlem denklemi:

$$2(x-1)+13(y-0)+7(z-3)=0\quad\Longrightarrow\quad2x+13y+7z-23=0.$$

> **Ders sonrası not:** Hoca denklemi okurken bir an "$18$ çarpı $y$" dedi. Doğrusu $13y$'dir. Sonuç $2x+13y+7z-23=0$ (sympy ile doğrulandı).

### 11.3 b) Ara kesit doğrusu

Ara kesit doğrusu her iki düzlemin içindedir. Bu yüzden iki normale de diktir. O hâlde yön vektörü yine $\vec n_1\times\vec n_2$'dir:

$$\vec v=2\vec i+13\vec j+7\vec k.$$

Bir yön vektörü ve bir nokta verilince doğrunun denklemi yazılabilir. İki düzlemi de sağlayan bir $P_0(x_0,y_0,z_0)$ noktası alınırsa:

$$\frac{x-x_0}{2}=\frac{y-y_0}{13}=\frac{z-z_0}{7}.$$

Hoca "nokta zaten belli, yerine koyuyoruz" dedi; noktanın koordinatları altyazıda geçmiyor.

### 11.4 c) Ara kesitten ve bir noktadan geçen düzlem

Bölüm 9.2'deki düzlem demeti kullanılır: $D_1+\lambda D_2=0$ yazılır, verilen nokta yerine konup $\lambda$ bulunur, sonra $\lambda$ geri yazılır. Hoca bu şıkkın ayrıntısına girmedi.

### 11.5 d) İki düzlem arasındaki açı

İki düzlem arasındaki açı, normalleri arasındaki açıdır. Skaler çarpım formülü kullanılır:

$$\vec n_1\cdot\vec n_2=3\cdot1+(-1)\cdot2+1\cdot(-4)=3-2-4=-3.$$

- $|\vec n_1|=\sqrt{9+1+1}=\sqrt{11}$.
- $|\vec n_2|=\sqrt{1+4+16}=\sqrt{21}$.

$$\cos\theta=\frac{|\vec n_1\cdot\vec n_2|}{|\vec n_1|\,|\vec n_2|}=\frac{3}{\sqrt{11}\sqrt{21}}=\frac{3}{\sqrt{231}}.$$

Hoca skaler çarpımı bileşen bileşen yaptı ("$3$ çarpı $1$, $-1$ ile $2$..."), ama sayısal sonucu söylemedi. Yukarıdaki değerler sympy ile doğrulandı ($\theta\approx78{,}6^\circ$).

<!-- BELİRSİZ: 01:27:33 civarında hocanın söylediği ara çarpımlar ("Altı, eksi iki yapıyor") tam okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Düzlemler arasındaki açı genellikle dar açı olarak verilir. Bu yüzden payda skaler çarpımın mutlak değeri alınır. Mutlak değer alınmazsa bütünler açı ($\approx101{,}4^\circ$) bulunur.

Hoca çözümleri paylaşacağını söyledi. Soru olursa bir sonraki derste bunlara bakılacağını, yoksa konuya devam edileceğini ekledi.

## 12. Örnek Sorular

Bu derste kare ya da video yoktur. Aşağıdaki sorular derste sözlü olarak sorulan ya da tahtada çözülen sorulardır.

**Soru 1** (derste sözlü, 00:13:22): $r=1-\cos\theta$ kardiyoidinin (kalbin) çevresi nedir?

> **Çözüm:** $r'=\sin\theta$, $r^2+r'^2=2-2\cos\theta=4\sin^2(\theta/2)$. Simetriden $L=2\int_0^{\pi}2\sin(\theta/2)\,d\theta=8$. Ayrıntı Bölüm 3.3'te.

**Soru 2** (derste sözlü, 00:12:20): Fonksiyon $r=1-\cos2\theta$ olsaydı çizimde ne değişirdi?

> **Çözüm:** Açı olarak $\pi/4$, $\pi/2$ alınır. $\theta=0$'da $r=0$, $\theta=\pi/4$'te $r=1$, $\theta=\pi/2$'de $r=2$.

**Soru 3** (derste sözlü, 00:23:43): $\vec a=2\vec i+3\vec j+4\vec k$ ve $\vec b=-\vec i-4\vec j+\vec k$ vektörlerinin skaler çarpımı nedir?

> **Çözüm:** $-2-12+4=-10$.

**Soru 4** (derste sözlü, 00:28:48): $\vec a=3\vec i-4\vec j$, $\vec b=8\vec i-6\vec j$ için $\vec a\cdot\vec b$ nedir? $\vec a$ ile $\vec b$ arasındaki açı nedir?

> **Çözüm:** $\vec a\cdot\vec b=48$; $|\vec a|=5$, $|\vec b|=10$; $\cos\theta=24/25$, $\theta=\arccos(24/25)$.

**Soru 5** (derste sözlü, 00:37:33): $\overrightarrow{AB}=\langle-1,-2,6\rangle$ ve $\overrightarrow{AC}=\langle-3,3,3\rangle$ ise $ABC$ üçgeninin $A$ açısını bulunuz.

> **Çözüm:** $\overrightarrow{AB}\cdot\overrightarrow{AC}=15$, $|\overrightarrow{AB}|=\sqrt{41}$, $|\overrightarrow{AC}|=\sqrt{27}$; $\cos A=5/\sqrt{123}$. Ayrıntı Bölüm 7.1'de.

**Soru 6** (derste sözlü, 01:01:27): $\overrightarrow{AB}=\langle-1,-2,6\rangle$, $\overrightarrow{AC}=\langle-3,3,3\rangle$, $\overrightarrow{AD}=\langle m-1,5,7\rangle$. $A$, $B$, $C$, $D$ noktaları aynı düzlemde ise $m$ kaçtır?

> **Çözüm:** Karma çarpım sıfırdır: determinant $-24m-114=0$, $m=-19/4$. Hocanın söylediği sonuç altyazıda okunmuyor; bkz. Bölüm 7.2'deki ders sonrası not.

**Soru 7** (derste sözlü, 01:10:48): $P_0(1,-1,3)$ noktasından geçen ve $\vec v=3\vec i-2\vec j+4\vec k$ vektörüne dik olan düzlemin denklemini bulunuz.

> **Çözüm:** $3(x-1)-2(y+1)+4(z-3)=0$, yani $3x-2y+4z-17=0$.

**Soru 8** (derste sözlü, 01:23:17): $D_1:\ 3x-y+z-1=0$ ve normali $\langle1,2,-4\rangle$ olan $D_2$ düzlemi veriliyor. a) İki düzlemi dik kesen ve $P(1,0,3)$'ten geçen düzlem; b) ara kesit doğrusu; c) ara kesitten ve bir noktadan geçen düzlem; d) iki düzlem arasındaki açı.

> **Çözüm:** a) $\vec n_1\times\vec n_2=\langle2,13,7\rangle$, düzlem $2x+13y+7z-23=0$. b) Yön vektörü $\langle2,13,7\rangle$. c) $D_1+\lambda D_2=0$. d) $\cos\theta=3/\sqrt{231}$. Ayrıntı Bölüm 11'de.

## Dersin Toparlaması

Bu derste önce parametrik ve kutupsal eğriler kapatıldı. Parametrik türev, Kartezyen-kutupsal dönüşüm ve üç gösterimde yay uzunluğu hatırlatıldı. Kardiyoidin çevresi simetriden yararlanarak $8$ bulundu. Parametrik verilen eğride alan için $A=\int y(t)\,x'(t)\,dt$ formülü elde edildi.

Ardından vektörlere geçildi. Skaler çarpımın bir sayı, vektörel çarpımın bir vektör verdiği; skalerde açının kosinüsü, vektörelde sinüsü bulunduğu vurgulandı. Vektörel çarpımın iki vektörün düzlemine dik normal vektörü verdiği, karma çarpımın ise üç vektörün aynı düzlemde olup olmadığını sınadığı gösterildi. Bu araçlarla uzayda düzlem ($a(x-x_0)+b(y-y_0)+c(z-z_0)=0$) ve doğru (parametrik ve simetrik denklem) denklemleri kuruldu, uzaklık formülleri ve düzlem demeti verildi, sonunda iki düzlemle ilgili çok şıklı bir çıkmış soru çözüldü. Hoca bu haftayla parametrik denklemler, kutupsal koordinatlar ve vektörlerin bittiğini, gelecek hafta çok değişkenli fonksiyonlara geçileceğini söyledi. Konuların biriktirilmeden, haftası haftasına çalışılmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
