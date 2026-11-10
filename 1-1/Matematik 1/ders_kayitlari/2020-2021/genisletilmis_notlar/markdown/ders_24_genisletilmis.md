# Ders 24 Genişletilmiş Notu: Rasyonel Fonksiyonların İntegrali ve Trigonometrik Dönüşümler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Başı: Logaritmik Bir Fonksiyonun Monotonluğu ve Konkavlığı
- 2. Parçalı Tanımlı Fonksiyonun Belirli İntegrali
- 3. Payın Derecesi Paydanınkinden Küçük Olmayan Rasyonel Fonksiyonlar: Polinom Bölmesi
- 4. Üstel İfadeleri Rasyonel Fonksiyona Çevirme
- 5. Paydası Reel Kökü Olmayan İkinci Derece Polinom
- 6. Trigonometrik İfadeyi Rasyonel Fonksiyona Çevirme
- 7. Polinom Bölmesi ve Tam Kare: Birleşik Örnek
- 8. Trigonometrik Dönüşümler (Trigonometric Substitutions)
- 9. $\sqrt{x^2-a^2}$ İçin Sekant Dönüşümü
- Örnek Sorular

Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. Hoca geçen hafta kalemi bozulduğu için çözemediği işlemli soruları çözerek başladı, sonra rasyonel fonksiyonların integraline devam etti ve dersin son bölümünde trigonometrik dönüşümlere geçti. Hoca bu derste tablet kalemiyle bir beyaz tahta (whiteboard) uygulaması üzerinde yazdı. Altyazıda yalnız sözlü kısım olduğu için formüller sözlü anlatımdan kuruldu.

## 1. Dersin Başı: Logaritmik Bir Fonksiyonun Monotonluğu ve Konkavlığı

Hoca önce geçen haftadan kalan soruları kısaca gözden geçirdi. Bunların bir kısmı birinci vize konularıydı: zincir kuralı (chain rule) ile birlikte temel teoremin birinci kısmı (fundamental theorem, part one), süreksizlik türleri (sıçrama süreksizliği ve sonsuz süreksizlik tanımları), limit, türevin tanımının uygulanması ve L'Hospital kuralı. Hoca bunların bir kısmını daha önce çözdüklerini söyleyerek geçti.

> **Hocanın vurgusu:** Temel teoremin birinci kısmı çok önemli bir konu; bu konuyu çalışmalısınız.

Ardından ikinci vize konusu olan bir soruyu çözdü: konkavlık (concavity) ve yerel ekstremum (local extremum) değerleri. Fonksiyon $f(x) = \ln|x^2-1|$ idi.

<!-- BELİRSİZ: Sorunun şıkları ekranda yazılıydı; altyazıdan yalnız "konkavlık" ve "yerel maksimum" ile ilgili şıklar ve doğru cevabın B şıkkı olduğu anlaşılıyor. -->

**Türev.** Hoca önce şu kuralı hatırlattı: Mutlak değer içinde olsa bile
$$\frac{d}{dx}\ln|u(x)| = \frac{u'(x)}{u(x)}.$$
Buradan
$$f'(x) = \frac{2x}{x^2-1} = \frac{2x}{(x-1)(x+1)}.$$

**İşaret tablosu.** Yerel ekstremumları bulmak için türevin işaret tablosu incelenir. Türevin üç farklı çarpanı vardır: $x$ (kökü $0$), $x-1$ (kökü $1$) ve $x+1$ (kökü $-1$). $x>1$ için (ör. $x=2$) türev pozitiftir; $0<x<1$ için negatiftir; işaretler sırayla değişir:

| Aralık | $x<-1$ | $-1<x<0$ | $0<x<1$ | $x>1$ |
|---|---|---|---|---|
| $f'$ | $-$ | $+$ | $-$ | $+$ |
| $f$ | azalan | artan | azalan | artan |

Bu yüzden $x=0$ noktasında yerel maksimum vardır.

**İkinci türev.** Hoca ikinci türevi şöyle yorumladı: Pay kısmında $-2$ çarpanı negatif, $x^2+1$ ve paydadaki $(x^2-1)^2$ her zaman pozitiftir:
$$f''(x) = \frac{-2(x^2+1)}{(x^2-1)^2} < 0.$$
Yani $f$'nin grafiği tanım kümesinin her yerinde aşağı konkavdır (concave down). Hoca şıklardan birinde "yukarı konkav" yazmasının hata olduğunu, orasının "aşağı konkav" olarak düzeltilmesi gerektiğini söyledi; doğru cevap B şıkkıydı.

<!-- BELİRSİZ: 00:05:05-00:06:20 arası altyazı bozuk; ikinci türevin hesaplanma adımları altyazıda anlaşılmıyor. Yukarıdaki ifade hocanın yorumundan ve hesapla kuruldu. -->

> **Ders sonrası not:** Hoca $\ln|x^2-1|$ ifadesinin $0$, $1$ ve $-1$ noktalarında anlamsız olduğunu söyledi. Doğrusu: Fonksiyon yalnız $x=\pm1$ noktalarında tanımsızdır. $x=0$'da $f(0)=\ln|{-1}| = \ln 1 = 0$ tanımlıdır; zaten yerel maksimum da bu noktadadır.

Hoca daha sonra bu sorunun bu grupla önceki gün çözüldüğünü, iki grubu karıştırdığını fark etti ve yeni konulara geçti.

## 2. Parçalı Tanımlı Fonksiyonun Belirli İntegrali

Hoca önceki gün rasyonel fonksiyonların integraline (integration of rational functions) giriş yaptıklarını hatırlattı ve konuyu hatırlatmak için öğrencilere bir soru verdi.

### Örnek 1

$$f(x) = \begin{cases} \dfrac{x}{x^2+1}, & -\pi < x < \dfrac{\pi}{2} \\[3mm] \dfrac{1}{x(x^2+1)}, & \dfrac{\pi}{2} \le x < \pi \end{cases} \qquad \int_{-\pi}^{\pi} f(x)\,dx = \;?$$

> **Hocanın vurgusu:** Bu tarz sorular finalde gelebilir. Belirli integral, ama parçalı tanımlı fonksiyonların integrali. Hoca bu soruya üç yıldız verdi. Çıkan değerler absürt görünebilir; değerlere değil, gidişata odaklanın.

Hoca soruyu aklından yazdığını, sonucun garip görünmesinin sorunun yanlış olduğu anlamına gelmediğini söyledi.

**Çözüm.** $-\pi$'den $\pi/2$'ye kadar birinci kural, $\pi/2$'den $\pi$'ye kadar ikinci kural kullanılır:
$$I = I_1 + I_2 = \int_{-\pi}^{\pi/2}\frac{x\,dx}{x^2+1} + \int_{\pi/2}^{\pi}\frac{dx}{x(x^2+1)}.$$

**$I_1$:** $\frac12\ln(x^2+1)$'in türevi integranttır. Sınırlar yerine konur:
$$I_1 = \frac12\ln(x^2+1)\Big|_{-\pi}^{\pi/2} = \frac12\left[\ln\left(\frac{\pi^2}{4}+1\right) - \ln(\pi^2+1)\right].$$

**$I_2$:** Rasyonel fonksiyon basit kesirlere (basic fractions) ayrılır. Paydada iki çarpan var:

- $x$ çarpanının reel kökü var ve katlı değil; bu yüzden $\dfrac{A}{x}$ yazılır.
- $x^2+1$'in reel kökü yok (kökleri karmaşık), kuvveti 1 olduğu için katlı karmaşık kök de yok. İkinci derece olduğu için payına bir derece düşük, birinci derece bir polinom yazılır: $\dfrac{Bx+C}{x^2+1}$.

$$\frac{1}{x(x^2+1)} = \frac{A}{x} + \frac{Bx+C}{x^2+1}.$$

$x$'in reel ve katsız kökü olduğu için $A$ kısa yoldan bulunur: Sol tarafta $x$ çarpanı göz ardı edilir ve kökü $x=0$ yerine konur: $A = \dfrac{1}{0+1} = 1$.

$B$ ve $C$ için kesirler açılır:
$$1 = A(x^2+1) + Bx^2 + Cx = (A+B)x^2 + Cx + A.$$
Sol tarafta $x^2$ katsayısı $0$ olduğundan $A+B=0$, yani $B=-1$. Sabit terimden $A=1$ (tutarlı), $x$ katsayısından $C=0$.

$$I_2 = \left[\ln|x| - \frac12\ln(x^2+1)\right]_{\pi/2}^{\pi}.$$

$I_2$ hesaplanıp $I_1$'e eklenince $I$ bulunur. Hoca son toplamı yapmadı.

> **Ders sonrası not:** Toplam derste yapılmadı; sympy ile doğrulanan sonuç: $I_2 = I_1 + \ln 2$ çıkar, bu yüzden
> $$I = \ln\frac{\pi^2/4+1}{\pi^2+1} + \ln 2 \approx -0{,}4494.$$

## 3. Payın Derecesi Paydanınkinden Küçük Olmayan Rasyonel Fonksiyonlar: Polinom Bölmesi

Hoca ekran paylaşımındaki bir sorunu çözdükten sonra ikinci tip rasyonel fonksiyonu tanıttı: payın derecesinin paydanın derecesinden büyük ya da ona eşit olduğu durum. (Altyazıda "denominator ... denominator" geçiyor; kastedilen pay ile paydanın karşılaştırılmasıdır.)

**Kural**

- Payın derecesi paydanınkinden küçük değilse önce polinom bölmesi (polynomial division) yapılır.
- Kalanın derecesi paydanın derecesinden küçük olunca bölme durdurulur.
- Sonuç "bölüm + kalan/payda" biçiminde yazılır; ikinci kısım artık basit kesirlere ayrılabilir.

<!-- BELİRSİZ: 00:25:10-00:26:39 ve 00:27:20-00:28:08 arası altyazı döngüye girmiş; ilk bölme işleminin adımları altyazıda anlaşılmıyor. -->

### Örnek 2: $\displaystyle\int\frac{x^2}{x^2+1}\,dx$

Bölmede kalan $-1$ olur; derecesi paydanınkinden küçük olduğu için durulur:
$$x^2 = 1\cdot(x^2+1) - 1 \quad\Longrightarrow\quad \frac{x^2}{x^2+1} = 1 - \frac{1}{x^2+1}.$$
Hoca bunun $\dfrac{x^2}{x^2+1}$'i basit kesirlerle yazmanın genel yöntemi olduğunu söyledi. Buradan (ara adım eklendi)
$$\int\frac{x^2}{x^2+1}\,dx = x - \arctan x + C.$$

### Örnek 3: $\displaystyle\int\frac{x^3}{x^2+1}\,dx$

Payın derecesi 3, paydanınki 2. Bölmede kalan $-x$'tir; derecesi 1, paydanınki 2 olduğu için durulur:
$$x^3 = x(x^2+1) - x \quad\Longrightarrow\quad \frac{x^3}{x^2+1} = x - \frac{x}{x^2+1}.$$
Bu doğrusal ayrışım sayesinde integral iki kolay integrale dönüşür. İkinci integralde $u = x^2+1$ değişken dönüşümü yapılır:
$$\int\frac{x^3}{x^2+1}\,dx = \frac{x^2}{2} - \frac12\ln(x^2+1) + C.$$

## 4. Üstel İfadeleri Rasyonel Fonksiyona Çevirme

### Örnek 4: $\displaystyle\int\frac{dt}{e^{2t}+2e^t+1}$

Hoca bunun bir rasyonel fonksiyon olmadığını, ama değişken dönüşümü ve integrant üzerinde bazı düzenlemelerle rasyonel fonksiyona çevrilebileceğini söyledi.

> **Hocanın vurgusu:** Sınavda "Bu integrali çözmek için aşağıdaki adımlardan hangileri doğrudur?" tipinde bir test sorusu gelebilir.

**Adım 1.** Pay ve payda $e^t$ ile çarpılır; hiçbir şey değişmez:
$$\int\frac{e^t\,dt}{e^t\left(e^{2t}+2e^t+1\right)}.$$

**Adım 2.** $u = e^t$, $du = e^t\,dt$:
$$\int\frac{du}{u(u^2+2u+1)} = \int\frac{du}{u(u+1)^2}.$$
Böylece integrant bir rasyonel fonksiyona dönüşür.

**Adım 3.** Basit kesirler: $u$ çarpanının reel ve katsız kökü var; $u+1$'in reel kökü var ve iki katlı, bu yüzden her katmana bir sabit yazılır:
$$\frac{1}{u(u+1)^2} = \frac{A}{u} + \frac{B}{u+1} + \frac{C}{(u+1)^2}.$$

<!-- BELİRSİZ: 00:34:24-00:35:53 arası altyazı döngüye girmiş; A, B, C'nin bulunma adımları altyazıda anlaşılmıyor. -->

**Adım 4.** $A$, $B$, $C$ bulunduktan sonra basit kesirlerin integralleri bilindiği için:
$$I = A\ln|u| + B\ln|u+1| - \frac{C}{u+1} + c.$$
Son olarak $u = e^t$ yerine yazılır.

> **Ders sonrası not:** Katsayılar altyazıda duyulmuyor. sympy ile doğrulanan değerler: $A=1$, $B=-1$, $C=-1$. Buna göre
> $$\int\frac{dt}{e^{2t}+2e^t+1} = t - \ln(e^t+1) + \frac{1}{e^t+1} + c.$$

### Örnek 5: $u=e^t$ ile $\displaystyle\int\frac{u^2\,du}{u^2-2u+1}$

Hoca "bunlar basit olanlar, ilerleyen haftalarda daha zorlarını çözeriz" diyerek bir üstel integral daha verdi.

> **Hocanın vurgusu:** Bu konu final konusudur, unutmayın.

<!-- BELİRSİZ: Asıl integrant altyazıda okunmuyor. Altyazıdan anlaşılan: üstel bir ifade önce çarpanlarına ayrılıyor, sonra $u=e^t$, $du=e^t\,dt$ dönüşümüyle $\int\frac{u^2\,du}{u^2-2u+1}$ elde ediliyor. Bu da büyük olasılıkla $\int\frac{e^{3t}\,dt}{e^{2t}-2e^t+1}$ gibi bir integrale karşılık gelir. -->

Bir öğrenci polinom bölmesi önerdi. Hoca polinom bölmesinin ya da değişken dönüşümünün kullanılabileceğini, hangisi kolay geliyorsa onun seçilebileceğini söyledi; bazen polinom bölmesinin işe yaramayabileceğini de ekledi.

**Polinom bölmesi.** $u^2$'yi yok etmek için $u^2-2u+1$ ile $1$ çarpılır ve fark alınır: $u^2 - (u^2-2u+1) = 2u-1$. Kalan birinci derece, payda ikinci derece; durulur:
$$\frac{u^2}{u^2-2u+1} = 1 + \frac{2u-1}{u^2-2u+1}.$$

> **Ders sonrası not:** Altyazıda bu eşitlik "1 eksi $\frac{2u-1}{u^2-2u+1}$" olarak duyuluyor. Doğrusu artıdır: $1 + \frac{2u-1}{(u-1)^2}$ (sympy ile doğrulandı).

Şimdi payın derecesi paydanınkinden küçük olan
$$J = \int\frac{(2u-1)\,du}{u^2-2u+1}$$
integrali için iki yöntem var.

**Birinci yöntem: basit kesirler.** Payda $(u-1)^2$'dir, yani katlı reel kök var. Birinci katman için $\frac{A}{u-1}$, ikinci katman için $\frac{B}{(u-1)^2}$ yazılır:
$$\frac{2u-1}{(u-1)^2} = \frac{A}{u-1} + \frac{B}{(u-1)^2}.$$
Kesirler açılarak $A$ ve $B$ bulunur. Bu ödev olarak bırakıldı.

> **Hocanın vurgusu:** Burada ikinci katmanın payına $Bu + C$ yazmak hatadır. $u-1$'in reel kökü olduğu için her katmana yalnız sabit yazılır.

**İkinci yöntem: payda paydanın türevini oluşturmak (özel durum).** Bu yöntem her zaman uygulanamaz. $2u-1$ yazılırken $-1+1$ eklenir; hiçbir şey değişmez: $2u - 1 = (2u-2) + 1$. Böylece
$$J = \int\frac{(2u-2)\,du}{u^2-2u+1} + \int\frac{du}{(u-1)^2}.$$
Birinci integralde $t = u^2-2u+1$ denirse $dt = (2u-2)\,du$ olur ve integral $\int\frac{dt}{t} = \ln|t|$'ye dönüşür. İkinci integral $-\frac{1}{u-1}$'dir (ara adım eklendi):
$$J = \ln(u^2-2u+1) - \frac{1}{u-1} + C.$$

<!-- BELİRSİZ: 00:44:26-00:45:01 arası altyazı bozuk; ikinci integralin hesaplandığı kısım duyulmuyor. -->

Sonuç $I = u + J$ olur. Hoca sonunda ilk değişkene dönmeyi, yani $u = e^t$ yazmayı unutmamak gerektiğini hatırlattı.

## 5. Paydası Reel Kökü Olmayan İkinci Derece Polinom

### Örnek 6: $\displaystyle\int\frac{x\,dx}{x^2+x+1}$

Hoca bunun için iki temel yöntem olduğunu söyledi. Önce diskriminanta bakılır: $b^2-4ac = 1-4 < 0$. Yani $x^2+x+1$'in reel kökü yoktur.

#### Birinci yöntem: tam kareye tamamlama

$x^2+x$'i elde etmek için $\left(x+\frac12\right)^2$ yazılır; açılınca $x^2 + x + \frac14$ gelir. Sabit terimin $1$ olması için $\frac34$ eklenir:
$$x^2+x+1 = \left(x+\frac12\right)^2 + \frac34.$$

$u = x+\frac12$ dönüşümüyle $x = u - \frac12$, $dx = du$ olur (ara adım eklendi):
$$\int\frac{x\,dx}{x^2+x+1} = \int\frac{u\,du}{u^2+\frac34} - \frac12\int\frac{du}{u^2+\left(\frac{\sqrt3}{2}\right)^2}.$$

<!-- BELİRSİZ: 00:48:43-00:49:13 arası altyazı bozuk; dönüşümün yazıldığı kısım bağlamdan kuruldu. -->

Birinci integralde $t = u^2+\frac34$, $2u\,du = dt$, yani $u\,du = \frac12 dt$:
$$\int\frac{u\,du}{u^2+\frac34} = \frac12\int\frac{dt}{t} = \frac12\ln\left(u^2+\frac34\right).$$
Hoca burada mutlak değer yazmaya gerek olmadığını, içerinin zaten pozitif olduğunu söyledi.

İkinci integral için önceki derste ispatlanan formül hatırlatıldı:
$$\int\frac{dx}{x^2+a^2} = \frac1a\arctan\frac xa + C.$$
Burada $a = \frac{\sqrt3}{2}$:
$$-\frac12\int\frac{du}{u^2+\left(\frac{\sqrt3}{2}\right)^2} = -\frac12\cdot\frac{1}{\sqrt3/2}\arctan\frac{u}{\sqrt3/2}.$$
Son olarak $u = x+\frac12$ yerine yazılır.

#### İkinci yöntem: payda paydanın türevini oluşturmak

Hoca bunu önce Türkçe açıkladı: $x^2+x+1$'in türevi $2x+1$'dir; diferansiyeli $(2x+1)\,dx$'tir. Payda yalnız $x\,dx$ var. $2x+1$'i payda, eşitliği bozmadan oluşturmaya çalışırız. Önce $2$ ile çarpıp $\frac12$ ile dengeleriz, sonra $1$ ekleyip $1$ çıkarırız:
$$x = \frac12\big[(2x+1) - 1\big].$$
Böylece
$$\int\frac{x\,dx}{x^2+x+1} = \frac12\left[\int\frac{(2x+1)\,dx}{x^2+x+1} - \int\frac{dx}{x^2+x+1}\right].$$
Birinci integral, $x^2+x+1$ dönüşümüyle $\ln|x^2+x+1|$ olur. İkinci integralde payda tam kareye tamamlanır ve arctan formülü kullanılır:
$$\int\frac{x\,dx}{x^2+x+1} = \frac12\ln(x^2+x+1) - \frac{1}{\sqrt3}\arctan\frac{2x+1}{\sqrt3} + C.$$

Hoca son ifadeyi "$\frac{1}{\sqrt3/2}\arctan\frac{x+\frac12}{\sqrt3/2}$" biçiminde, yukarıdaki birinci yöntemdeki hesaba başvurarak yazdı. $t = x+\frac12$ denirse $dx = dt$ olduğu için doğrudan bu biçimde yazılabileceğini de söyledi. Hoca bu yöntemin birçok soruda uygulanabileceğini, ama hepsinde uygulanamayacağını; hangisi kolay geliyorsa onun kullanılabileceğini ekledi.

> **Ders sonrası not:** Hoca aradan önce ikinci integralin paydasını $(x+1)^2$ gibi düşünüp sonucu $\frac{1}{x+1}$ biçiminde yazdı. Aradan hemen sonra hatayı kendisi düzeltti: "2 varmış gibi düşündüm, $x$'in katsayısında 2 yok." Yani payda $x^2+2x+1$ değil, $x^2+x+1 = \left(x+\frac12\right)^2+\frac34$'tür ve integral $\int\frac{du}{u^2+a^2}$ tipine dönüşür. Doğru sonuç yukarıdaki arctan'lı ifadedir (sympy ile doğrulandı).

## 6. Trigonometrik İfadeyi Rasyonel Fonksiyona Çevirme

### Örnek 7: $\displaystyle\int\frac{\cos^3 t\,dt}{\sin^3 t - \sin^2 t - 6\sin t}$

Hoca önce değişken dönüşümünün hangi parçaya uygulanacağını sordu. Açıktır ki $u = \sin t$ olmalıdır. Ama bunun için $\cos^3 t$ üzerinde düzenleme gerekir.

**Adım 1.** $u = \sin t$, $du = \cos t\,dt$. $\cos^3 t\,dt = \cos^2 t\cdot\cos t\,dt = (1-\sin^2 t)\cos t\,dt = (1-u^2)\,du$:
$$\int\frac{(1-u^2)\,du}{u^3-u^2-6u}.$$

**Adım 2.** Payda çarpanlarına ayrılır: $u$ ortak çarpan parantezine alınır, $u^2-u-6 = (u-3)(u+2)$:
$$\frac{1-u^2}{u(u-3)(u+2)} = \frac{A}{u} + \frac{B}{u-3} + \frac{C}{u+2}.$$

Paydadaki her çarpanın reel kökü var ve katlı kök yok. Hoca bunun "çok iyi" olduğunu, çünkü bilinmeyenlerin kısa yoldan kolayca bulunacağını söyledi.

**Adım 3.** Kısa yol: Her seferinde bir çarpan sol tarafta göz ardı edilir ve o çarpanın kökü yerine konur.

- $A$ ($u=0$): $A = \dfrac{1}{(-3)(2)} = -\dfrac16$.
- $B$ ($u=3$): $B = \dfrac{1-9}{3\cdot5} = -\dfrac{8}{15}$.
- $C$ ($u=-2$): $C = \dfrac{1-4}{(-2)(-5)} = -\dfrac{3}{10}$.

**Adım 4.**
$$I = -\frac16\ln|\sin t| - \frac{8}{15}\ln|\sin t - 3| - \frac{3}{10}\ln|\sin t + 2| + C.$$

> **Ders sonrası not:** Hoca $A$'yı hesaplarken paydayı doğru olarak "$-6$" söyledi, ama integrali yazarken katsayıyı "$-\frac13$" okudu; $C$ için de "$\frac32$" dedi. sympy ile doğrulanan katsayılar: $A = -\frac16$, $B = -\frac{8}{15}$, $C = -\frac{3}{10}$. Kontrol: $u^2$ katsayısı $A+B+C = -\frac{5+16+9}{30} = -1$, paydaki $-u^2$ ile tutarlı.

Hoca bunun tam sınavdan gelebilecek bir soru tipi olduğunu, ama işlemi çok uzun olduğu için test sınavında sorulmayabileceğini söyledi.

## 7. Polinom Bölmesi ve Tam Kare: Birleşik Örnek

### Örnek 8: $\displaystyle\int\frac{x^3+x^2}{x^2+x+1}\,dx$

Hoca bu soruyu "aklımdan yazıyorum, kolay bir şekilde gelmeyebilir" diyerek verdi.

**Adım 1: polinom bölmesi.** Payın derecesi paydanınkinden büyük. $x^3$'ü yok etmek için payda $x$ ile çarpılır: $x^3+x^2+x$. Fark alınınca kalan $-x$ olur. Kalanın derecesi paydanınkinden küçük; durulur:
$$\frac{x^3+x^2}{x^2+x+1} = x - \frac{x}{x^2+x+1}.$$

**Adım 2.**
$$I = \frac{x^2}{2} - J, \qquad J = \int\frac{x\,dx}{x^2+x+1}.$$

$J$, Örnek 6'daki integralin aynısıdır. Hoca hatırlatmak için ikinci yöntemi (2 ile çarpıp bölmek, $1$ ekleyip çıkarmak) tekrar uyguladı. Buna göre (ara adım eklendi)
$$I = \frac{x^2}{2} - \frac12\ln(x^2+x+1) + \frac{1}{\sqrt3}\arctan\frac{2x+1}{\sqrt3} + C.$$

Hoca bu örnekle rasyonel fonksiyonların integralinin nasıl hesaplandığını görmüş olduklarını söyleyerek konuyu kapattı.

## 8. Trigonometrik Dönüşümler (Trigonometric Substitutions)

### 8.1 Giriş: $\displaystyle\int\frac{du}{\sqrt{4-u^2}}$

Hoca bilinen temel formülden başladı:
$$\int\frac{du}{\sqrt{1-u^2}} = \arcsin u + C,$$
çünkü $\arcsin u$'nun $u$'ya göre türevi $\frac{1}{\sqrt{1-u^2}}$'dir.

Peki $\int\frac{du}{\sqrt{4-u^2}}$ nasıl hesaplanır? Kök içinde $4$ ortak çarpan parantezine alınır:
$$\sqrt{4-u^2} = \sqrt{4\left(1-\left(\tfrac u2\right)^2\right)} = 2\sqrt{1-\left(\tfrac u2\right)^2}.$$
$t = \frac u2$, $du = 2\,dt$:
$$\int\frac{2\,dt}{2\sqrt{1-t^2}} = \arcsin t + C = \arcsin\frac u2 + C.$$

**Genelleme**

$$\int\frac{du}{\sqrt{a^2-u^2}} = \arcsin\frac ua + C.$$

> **Ders sonrası not:** Hoca genellemeyi "$\arcsin\frac xa$" diye söyledi; değişken $u$ olduğu için doğrusu $\arcsin\frac ua$'dır.

### 8.2 İkinci yöntem: $u = a\sin t$

Hoca aynı sonucu doğrulamak için ikinci bir yöntem gösterdi. Amaç, kök içindeki $a^2$'yi ortak çarpan yapıp integrali trigonometrik bir integrale dönüştürmektir. Bunun için $u = a\sin t$ trigonometrik dönüşümü yapılır:
$$du = a\cos t\,dt, \qquad \sqrt{a^2-a^2\sin^2 t} = a\sqrt{1-\sin^2 t} = a\sqrt{\cos^2 t} = a|\cos t|.$$
$a$'nın pozitif olduğu ve $\cos t$'nin pozitif olduğu bir aralıkta çalışıldığı varsayılır. Böylece
$$I = \int\frac{a\cos t\,dt}{a\cos t} = \int dt = t + C.$$
$u = a\sin t$ olduğundan $t = \arcsin\frac ua$; yani birinci yöntemle aynı sonuç (ara adım eklendi).

Hoca bu kısımda iki yazım hatasını kendisi düzeltti: önce "$u = a\arcsin t$" dedi, sonra "$\sin t$" olarak düzeltti; kök içinde önce $a^2\sin^2 t - a^2$ yazdı, sonra sırayı $a^2 - a^2\sin^2 t$ olarak düzeltti.

**Genel kural: $\sqrt{a^2-x^2}$ için dönüşüm**

- Kök içinde $a^2 - x^2$ biçiminde bir ifade görülürse $x = a\sin t$ dönüşümü yapılır.
- $dx = a\cos t\,dt$.
- $\sqrt{a^2-x^2} = a|\cos t|$; $a>0$ ve $\cos t>0$ olan bir aralıkta $a\cos t$ olur.
- Problem trigonometrik bir integrale dönüşür.

> **Hocanın vurgusu:** Kök içinde $a^2 - x^2$'li bir ifade görürseniz $x = a\sin t$ dönüşümü işimizi kolaylaştırır.

### 8.3 Örnek 9: $\displaystyle\int\sqrt{1-x^2}\,dx$

Burada $a = 1$.

**Adım 1.** $x = \sin t$, $dx = \cos t\,dt$, $\sqrt{1-x^2} = \cos t$. Hoca burada da aslında mutlak değer yazılması gerektiğini, ama $\cos t$'nin pozitif olduğu bir aralıkta çalışıldığını varsaydığını söyledi.

**Adım 2.**
$$\int\cos t\cdot\cos t\,dt = \int\cos^2 t\,dt = \int\frac{1+\cos 2t}{2}\,dt = \frac12\left(t + \frac12\sin 2t\right) + C.$$

**Adım 3: Sonucu $x$ cinsinden yazmak.** $x = \sin t$ olduğu için sonuç $x$ cinsinden ifade edilmelidir. Bunun için bir dik üçgen çizilir: $t$ açısı için $\sin t = x$; karşı kenar $x$, hipotenüs $1$, komşu kenar $\sqrt{1-x^2}$.

- $\sin 2t = 2\sin t\cos t = 2x\sqrt{1-x^2}$.
- $t = \arcsin x$.

**Adım 4.**
$$\int\sqrt{1-x^2}\,dx = \frac12\arcsin x + \frac12 x\sqrt{1-x^2} + C.$$
(sympy ile doğrulandı.)

<!-- BELİRSİZ: 01:29:38 civarında altyazıda "cosine squared t is equal to 1 minus 1 plus cosine 2t over" geçiyor; ifade bozuk. Yukarıdaki $\cos^2 t = \frac{1+\cos 2t}{2}$ özdeşliği bağlamdan alındı. -->

### 8.4 Ödev: $\displaystyle\int x^2\sqrt{1-x^2}\,dx$

Hoca bunun $x^2$ ile kökün birleşimi olduğunu, kök içinde $a^2-x^2$ görüldüğü için trigonometrik dönüşüm yapmanın daha iyi olduğunu söyledi ve "çok güzel bir soru" dedi. $x = \sin t$ ($a=1$) ile:
$$dx = \cos t\,dt, \quad x^2 = \sin^2 t, \quad \sqrt{1-x^2} = \cos t,$$
$$\int\sin^2 t\cos^2 t\,dt = \int\left(\frac12\sin 2t\right)^2 dt = \frac14\int\sin^2 2t\,dt.$$
Buradan $\sin^2 a = \frac{1-\cos 2a}{2}$ özdeşliği kullanılır: $\sin^2 2t = \frac{1-\cos 4t}{2}$. Kalan kısım ödev olarak bırakıldı. Çözüm Örnek Sorular bölümündedir.

### 8.5 Örnek 10: $\displaystyle\int\sqrt{3-4x^2}\,dx$

Hoca öğrencilere hangi trigonometrik dönüşümün bunu basitleştireceğini sordu. Bir öğrencinin "bir ekleyip bir çıkararak $\sin t$ ile bir şey yakalayabilir miyiz?" önerisine hoca, ortak çarpan parantezine almak ya da daha doğrudan bir değişken dönüşümü yapmak gerektiğini söyledi.

**Adım 1.** $x = \dfrac{\sqrt3}{2}\sin t$, $dx = \dfrac{\sqrt3}{2}\cos t\,dt$. Bu dönüşümle problem doğrudan trigonometrik bir probleme dönüşür.

**Adım 2.** $4x^2 = 4\cdot\frac34\sin^2 t = 3\sin^2 t$. $3$ ortak çarpan yapılır:
$$\sqrt{3-3\sin^2 t} = \sqrt3\sqrt{1-\sin^2 t} = \sqrt3\cos t.$$

**Adım 3.**
$$\int\sqrt3\cos t\cdot\frac{\sqrt3}{2}\cos t\,dt = \frac32\int\cos^2 t\,dt = \frac32\int\frac{1+\cos 2t}{2}\,dt = \frac34\left(t + \frac12\sin 2t\right) + C.$$

**Adım 4.** Sonucu $x$ cinsinden yazmak için bir dik üçgen kurulması ödev olarak bırakıldı: Önce üçgenin kenarlarını belirleyin, sonra $\sin 2t$'yi ve $t$'yi $x$ cinsinden yazın. Çözüm Örnek Sorular bölümündedir.

Hoca üniversiteye giriş sınavlarında (AYT) bu tarz trigonometri sorularının gelebildiğini hatırlattı; örneğin "$x = \frac{\sqrt3}{2}\sin t$ ise $\sin 2t$'nin $x$ cinsinden yazılışı nedir?" tarzında.

## 9. $\sqrt{x^2-a^2}$ İçin Sekant Dönüşümü

### 9.1 Çıkış noktası: arksekant türevi

Hoca arksekantın türevini hatırlattı:
$$\frac{d}{du}\operatorname{arcsec} u = \frac{1}{|u|\sqrt{u^2-1}}.$$
Buradaki $\sqrt{u^2-1}$ terimine odaklanın. Böyle bir ifade, yani $\sqrt{u^2-a^2}$ görüldüğünde problemi kolay bir trigonometrik probleme dönüştürmek için $u = a\sec t$ dönüşümü yapılır.

> **Ders sonrası not:** Hoca bir yerde bu ifadenin "$a^2-u^2$'ye çok benzediğini" söyledi; bağlamdan kastedilen $u^2-a^2$'dir. $a^2-u^2$ için sinüs dönüşümü kullanılır.

**Genel kural: $\sqrt{u^2-a^2}$ için dönüşüm**

- $u = a\sec t$.
- $du = a\sec t\tan t\,dt$.
- $\sqrt{a^2\sec^2 t - a^2} = |a|\sqrt{\sec^2 t - 1} = |a|\sqrt{\tan^2 t} = a|\tan t|$ ($a>0$ varsayılır).
- $\sec^2 t - 1 = \tan^2 t$ özdeşliği kullanılır.

| İfade | Dönüşüm | Kök neye dönüşür |
|---|---|---|
| $\sqrt{a^2-x^2}$ | $x = a\sin t$ | $a\cos t$ |
| $\sqrt{x^2-a^2}$ | $x = a\sec t$ | $a\tan t$ |

Tablodaki sadeleşmeler, $a>0$ ve $\cos t$, $\tan t$'nin pozitif olduğu bir aralıkta çalışıldığı varsayımıyla geçerlidir.

### 9.2 Örnek 11: $\displaystyle\int\frac{dx}{\sqrt{x^2-1}}$

> **Hocanın vurgusu:** Dikkat, bu $\arcsin x$ değildir.

**Adım 1.** $a = 1$: $x = \sec t$, $dx = \sec t\tan t\,dt$, $\sqrt{x^2-1} = \tan t$.

**Adım 2.**
$$\int\frac{\sec t\tan t\,dt}{\tan t} = \int\sec t\,dt.$$

**Adım 3: $\int\sec t\,dt$.** Hoca bunun ezberlenmesine gerek olmadığını söyledi. $\sec t$'nin türevinde $\sec t\tan t$ bulunduğunu bildiğimiz için pay ve payda $\sec t + \tan t$ ile çarpılır (ara adım eklendi):
$$\int\sec t\,dt = \int\frac{\sec t(\sec t + \tan t)}{\sec t + \tan t}\,dt = \int\frac{(\sec^2 t + \sec t\tan t)\,dt}{\sec t + \tan t}.$$
$u = \sec t + \tan t$ denirse pay tam $du$ olur:
$$\int\frac{du}{u} = \ln|u| = \ln|\sec t + \tan t| + C.$$

**Adım 4: $x$ cinsinden yazmak.** Bir dik üçgen çizilir. $\sec t = \frac{1}{\cos t} = x$, yani $\cos t = \frac1x$: komşu kenar $1$, hipotenüs $x$, karşı kenar $\sqrt{x^2-1}$. Buradan $\sec t = x$ ve $\tan t = \sqrt{x^2-1}$:
$$\int\frac{dx}{\sqrt{x^2-1}} = \ln\left|x + \sqrt{x^2-1}\right| + C.$$
(sympy ile doğrulandı.)

> **Ders sonrası not:** Altyazıda $\tan t$ için "x square, square root of $x^2-1$" gibi bir ifade geçiyor. Üçgene göre doğrusu $\tan t = \sqrt{x^2-1}$'dir.

### 9.3 Ödev: $\displaystyle\int\frac{x\,dx}{\sqrt{4x^2-9}}$

Hoca hangi trigonometrik dönüşümün en uygun olduğunu sordu ve iki önceki örneği (Örnek 10) hatırlattı: Katsayılar farklı olunca ona uygun bir trigonometrik dönüşüm yapılıyordu. Kök içinde $9$ ortak çarpan parantezine alınır ve uygun dönüşüm yapılınca kök ifadesi $\tan t$'nin bir katına dönüşür.

<!-- BELİRSİZ: 01:47:47-01:48:03 arası altyazıda dönüşüm yazılmıyor. Kökün $\tan t$'nin katına dönüşmesi için büyük olasılıkla $x = \frac32\sec t$ dönüşümü tahtaya yazıldı. -->

Ders süresi dolduğu için bu soru ödev olarak bırakıldı. Çözüm Örnek Sorular bölümündedir.

### 9.4 Dersin sonundaki çalışma önerileri

> **Hocanın vurgusu:** Ağırlığı birinci vizeden sonra işlenen konulara verin. Ama birinci vize konularını küçümsemeyin; birinci vize konularıyla sonraki konular harmanlanıp birlikte sorulabilir. Bütün konuları baştan sona çalışın. Temel teorem önemli, asimptotlar da var. Birinci vizeden sonra dört beş hafta işlendiyse, her haftadan üç dört soru gelecekmiş gibi çalışın.

## Örnek Sorular

Bu derste video karesi yok. Sorular yalnız derste çözülen ya da sözlü sorulan sorulardan alındı.

**Soru 1** (derste sözlü, 00:02:52): $f(x) = \ln|x^2-1|$ fonksiyonunun yerel ekstremum ve konkavlığı ile ilgili doğru seçenek hangisidir?

<!-- BELİRSİZ: Şıklar altyazıda okunmuyor; yalnız doğru cevabın B şıkkı olduğu ve bir şıktaki "yukarı konkav" ifadesinin "aşağı konkav" olarak düzeltildiği anlaşılıyor. -->

> **Çözüm (derste verildi):** $f'(x) = \frac{2x}{x^2-1}$. İşaret: $(-\infty,-1)$ azalan, $(-1,0)$ artan, $(0,1)$ azalan, $(1,\infty)$ artan. $x=0$'da yerel maksimum. $f''(x) = \frac{-2(x^2+1)}{(x^2-1)^2} < 0$; grafik tanım kümesinde her yerde aşağı konkav.

**Soru 2** (derste sözlü, 00:10:15): Örnek 1'deki parçalı fonksiyon için $\int_{-\pi}^{\pi} f(x)\,dx$'i hesaplayın.

> **Çözüm (derste verildi, son toplam derste verilmedi):** $I_1 = \frac12\left[\ln\left(\frac{\pi^2}{4}+1\right) - \ln(\pi^2+1)\right]$, $I_2 = \left[\ln|x| - \frac12\ln(x^2+1)\right]_{\pi/2}^{\pi}$. Toplam (sympy ile): $I = \ln\frac{\pi^2/4+1}{\pi^2+1} + \ln 2 \approx -0{,}4494$.

**Soru 3** (derste sözlü, 00:31:49): $\displaystyle\int\frac{dt}{e^{2t}+2e^t+1}$ integralini çözmek için hangi adımlar gerekir? Hoca bunun "aşağıdaki adımlardan hangileri doğrudur?" tipinde bir test sorusu olabileceğini söyledi.

> **Çözüm (derste verildi; katsayılar derste verilmedi):** Pay ve payda $e^t$ ile çarpılır; $u = e^t$ ile $\int\frac{du}{u(u+1)^2}$ elde edilir; $\frac{A}{u} + \frac{B}{u+1} + \frac{C}{(u+1)^2}$ ayrışımı yapılır. sympy ile $A=1$, $B=-1$, $C=-1$; sonuç $t - \ln(e^t+1) + \frac{1}{e^t+1} + c$.

**Soru 4** (derste sözlü, 00:42:30, ödev): $\dfrac{2u-1}{(u-1)^2} = \dfrac{A}{u-1} + \dfrac{B}{(u-1)^2}$ ayrışımında $A$ ve $B$'yi bulun.

> **Çözüm (derste verilmedi):** $2u-1 = A(u-1) + B$. $u=1$ için $B=1$; $u$ katsayısından $A=2$. Yani $\frac{2u-1}{(u-1)^2} = \frac{2}{u-1} + \frac{1}{(u-1)^2}$ ve $J = 2\ln|u-1| - \frac{1}{u-1} + C$. Bu, ikinci yöntemin sonucu $\ln(u^2-2u+1) - \frac{1}{u-1}$ ile aynıdır, çünkü $\ln(u-1)^2 = 2\ln|u-1|$ (sympy ile doğrulandı).

**Soru 5** (derste sözlü, 00:46:27): $\displaystyle\int\frac{x\,dx}{x^2+x+1}$ nasıl çözülür?

> **Çözüm (derste verildi, aradan sonra düzeltildi):** $\frac12\ln(x^2+x+1) - \frac{1}{\sqrt3}\arctan\frac{2x+1}{\sqrt3} + C$.

**Soru 6** (derste sözlü, 01:09:55): $\displaystyle\int\frac{\cos^3 t\,dt}{\sin^3 t - \sin^2 t - 6\sin t}$ integralinde hangi parçaya değişken dönüşümü uygulanmalı ve sonuç nedir?

> **Çözüm (derste verildi, katsayılar düzeltildi):** $u = \sin t$; $-\frac16\ln|\sin t| - \frac{8}{15}\ln|\sin t - 3| - \frac{3}{10}\ln|\sin t + 2| + C$.

**Soru 7** (derste sözlü, 01:32:50, ödev): $\displaystyle\int x^2\sqrt{1-x^2}\,dx$ integralini hesaplayın.

> **Çözüm (derste verilmedi):** $x = \sin t$ ile $\frac14\int\sin^2 2t\,dt = \frac18\int(1-\cos 4t)\,dt = \frac18\left(t - \frac14\sin 4t\right) + C$. $\sin 4t = 2\sin 2t\cos 2t = 4x\sqrt{1-x^2}\,(1-2x^2)$ olduğundan
> $$\int x^2\sqrt{1-x^2}\,dx = \frac18\arcsin x - \frac18 x\sqrt{1-x^2}\,(1-2x^2) + C.$$
> (Türev alınarak sympy ile doğrulandı.)

**Soru 8** (derste sözlü, 01:35:22): $\displaystyle\int\sqrt{3-4x^2}\,dx$ için hangi trigonometrik dönüşüm uygundur? Sonucu $x$ cinsinden yazın (son kısım ödev).

> **Çözüm (dönüşüm derste verildi; $x$ cinsinden yazılış derste verilmedi):** $x = \frac{\sqrt3}{2}\sin t$ ile $\frac34\left(t + \frac12\sin 2t\right) + C$. Üçgen: $\sin t = \frac{2x}{\sqrt3}$, $\cos t = \frac{\sqrt{3-4x^2}}{\sqrt3}$, $\sin 2t = \frac{4x\sqrt{3-4x^2}}{3}$. Sonuç:
> $$\int\sqrt{3-4x^2}\,dx = \frac34\arcsin\frac{2x}{\sqrt3} + \frac x2\sqrt{3-4x^2} + C.$$
> (Türev alınarak sympy ile doğrulandı.)

**Soru 9** (derste sözlü, 01:46:49, ödev): $\displaystyle\int\frac{x\,dx}{\sqrt{4x^2-9}}$ için hangi trigonometrik dönüşüm en uygundur? İntegrali hesaplayın.

> **Çözüm (derste verilmedi):** $x = \frac32\sec t$, $dx = \frac32\sec t\tan t\,dt$, $\sqrt{4x^2-9} = \sqrt{9\sec^2 t - 9} = 3\tan t$. İntegral $\int\frac{\frac32\sec t\cdot\frac32\sec t\tan t}{3\tan t}\,dt = \frac34\int\sec^2 t\,dt = \frac34\tan t + C$. Üçgen: $\sec t = \frac{2x}{3}$, $\tan t = \frac{\sqrt{4x^2-9}}{3}$. Sonuç:
> $$\int\frac{x\,dx}{\sqrt{4x^2-9}} = \frac14\sqrt{4x^2-9} + C.$$
> (Türev alınarak sympy ile doğrulandı.)

> **Ek bilgi (derste anlatılmadı):** Soru 9'daki integral, $w = 4x^2-9$, $dw = 8x\,dx$ basit değişken dönüşümüyle de aynı sonucu verir. Paydaki $x\,dx$, kök içindekinin türevine orantılı olduğunda trigonometrik dönüşüme gerek kalmaz.

## Dersin Toparlaması

Bu derste rasyonel fonksiyonların integrali tamamlandı. Payın derecesi paydanınkinden küçük değilse önce polinom bölmesi yapılır. Paydada reel kökü olmayan ikinci derece bir çarpan varsa iki yol vardır: tam kareye tamamlayıp $\int\frac{du}{u^2+a^2} = \frac1a\arctan\frac ua$ formülünü kullanmak ya da payda paydanın türevini oluşturmak. Katlı reel kökte her katmana yalnız sabit yazılır. Üstel ($u = e^t$) ve trigonometrik ($u = \sin t$) ifadeler de uygun dönüşümle rasyonel fonksiyona çevrilebilir. Parçalı tanımlı fonksiyonların belirli integrali, her parçanın kendi aralığında ayrı ayrı integre edilmesiyle bulunur.

Dersin son bölümünde trigonometrik dönüşümler başladı. $\sqrt{a^2-x^2}$ için $x = a\sin t$, $\sqrt{x^2-a^2}$ için $x = a\sec t$ dönüşümü kökü ortadan kaldırır ve integrali trigonometrik bir integrale çevirir. Sonuç her zaman bir dik üçgen yardımıyla ilk değişken $x$ cinsinden yazılmalıdır. Hoca $x^2\sqrt{1-x^2}$, $\sqrt{3-4x^2}$ ve $\frac{x}{\sqrt{4x^2-9}}$ integrallerini ödev olarak bıraktı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
