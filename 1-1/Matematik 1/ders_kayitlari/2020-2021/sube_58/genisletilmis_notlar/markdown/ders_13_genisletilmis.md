# Ders 13 Genişletilmiş Notu: Vize Öncesi Tekrar: Türevlenebilirlik, Kapalı Türev, Tanım Kümesi, Ters Fonksiyonun Türevi ve Logaritmik Türev

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Genel Alıştırmalar (General Exercises)
- 2. Parçalı Fonksiyonlarda Türevlenebilirlik
- 3. Kapalı Türev (Implicit Differentiation)
- 4. Tanım Kümesi (Domain) Bulma
- 5. Bir Fonksiyonun Sabit Olduğunu Göstermek
- 6. Ters Fonksiyonun Türevi
- 7. Logaritmik Türev (Logarithmic Differentiation)
- 8. $1^\infty$ Belirsizliği İçeren Limitler
- 9. Kaynaklar ve Çalışma Önerileri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı: Genel Alıştırmalar (General Exercises)

Bu ders, ara sınavdan (vize) önceki bir tekrar ve soru çözümü dersidir. Hoca derse "Bugün genel alıştırmalar (general exercises) yapacağız" diyerek başladı. Önce klasik konular hatırlatıldı; hoca, ertesi derste geçmiş yılın test sınavı sorularının çözüleceğini söyledi.

Dersin düzeni şöyledir: Hoca soruyu tahtaya (ekran paylaşımlı tablete) yazar, öğrencilere birkaç dakika süre verir, cevap gelince çözümü birlikte yapar. Bazı soruları hoca o an "zihninden uydurdu"; bu sorularda sonucun "saçma" ya da "absürt" çıkabileceğini önceden söyledi. Hoca her adımı yazmadığını, ayrıntıların daha önceki derslerde anlatıldığını hatırlattı ve ders notlarının iyice çalışılmasını istedi.

> **Hocanın vurgusu:** Konuları önceki derslerden çalışmadan gelip temel adımları sormak dersi yavaşlatır. Önce ders notlarını ve ders videolarını çalışın; burada yalnız alıştırma yapıyoruz.

## 2. Parçalı Fonksiyonlarda Türevlenebilirlik

### 2.1 Doğrudan parça türevi ne zaman alınabilir?

Hoca önce temel bir gerçeği hatırlattı: **Süreklilik, türevlenebilirliğin gerekli koşuludur** (continuity is a necessary condition for differentiability). Yani bir noktada türevlenebilen fonksiyon orada süreklidir; tersi her zaman doğru değildir.

**Kural: Parçalı fonksiyonda parçaları doğrudan türevlemek**

- Parçalı tanımlı $f$, ayrım noktası $x_0$'da sürekli olmalı.
- Her parça (parçaların formülleri) her yerde türevlenebilir olmalı.
- Bu iki koşul sağlanırsa:

$$f'(x_0)\ \text{vardır} \iff \big(\text{1. parça}\big)'\Big|_{x_0} = \big(\text{2. parça}\big)'\Big|_{x_0}$$

- Koşullardan biri sağlanmazsa bu yöntem uygulanamaz; **türevin limit tanımı** (limit definition of derivative) kullanılmak zorundadır.

Hoca bu iki koşulun çok önemli olduğunu, bunlar olmadan bu yöntemin uygulanamayacağını özellikle söyledi. Sağdaki eşitlik doğruysa, mantık sembolü ($\iff$) gereği soldaki ifade de doğrudur.

### 2.2 Örnek 1: $\sin 2x$ ve $mx$

**Soru (00:04:52).** $f(x)$ parçalı tanımlıdır: bir parçası $\sin 2x$, öbür parçası $mx$. $f$, $x_0=0$ noktasında hangi $m$ değeri için türevlenebilirdir?

<!-- BELİRSİZ: Hangi parçanın x<0, hangisinin x≥0 için tanımlı olduğu altyazıda söylenmiyor; sonuç bundan etkilenmez. -->

**Çözüm.**

- Süreklilik: $x\to0$ iken $\sin 2x\to0$ ve $mx\to0$; ayrıca $f(0)=0$. Yani $f$, $0$'da açıkça süreklidir. Hoca bunu adım adım yazmaya gerek görmedi.
- $\sin 2x$ (trigonometrik fonksiyon) ve $mx$ her yerde türevlenebilir.
- İki koşul sağlandığı için parçalar doğrudan türevlenir:

$$(\sin 2x)'\Big|_{x=0} = 2\cos(2\cdot 0) = 2,\qquad (mx)'\Big|_{x=0} = m$$

- Eşitlikten $m=2$ bulunur.

> **Ders sonrası not:** Hoca bir yerde "$f'$, $0$ noktasında süreklidir" dedi (00:07:22). Kastedilen $f$'nin sürekliliğidir; türevlenebilirlik için gereken koşul $f$'nin sürekli olmasıdır.

### 2.3 Örnek 2: Türevin tanımını kullanmak zorunlu olduğunda

Hoca, iki koşul sağlanmadığında ne olacağını göstermek için o an bir soru üretti.

**Soru (00:10:12).** $f(x)$ parçalı tanımlıdır: bir parçası $\arcsin(x^2-m)$, öbür parçası $x-\sqrt m$. $f$, $x=\sqrt m$ noktasında türevlenebilir olsun. $m$ kaçtır?

Soruyu yazarken hoca önce parametreye "$a$" dedi. Bir öğrenci ikinci parçadaki ifadenin yanlış yazıldığını uyardı; hoca parametreyi $m$ olarak düzeltti.

<!-- BELİRSİZ: Parçaların hangi aralıkta tanımlı olduğu altyazıda tam söylenmiyor; hocanın anlatımına göre sağ taraf (x>√m) için arcsin parçası, sol taraf için doğrusal parça kullanılıyor. -->

**Neden doğrudan türev alınamaz?** Hocaya göre arksinüs her yerde türevlenebilir değildir. Bu yüzden birinci koşul (her parçanın her yerde türevlenebilir olması) sağlanmaz ve türevin limit tanımını kullanmak zorunludur.

**Çözüm.**

- Süreklilik: $x=\sqrt m$'de iki parça da $0$ olur, yani $f(\sqrt m)=0$ ve $f$ orada süreklidir.
- Sol taraftaki türev (doğrusal parça):

$$\lim_{x\to\sqrt m^-}\frac{(x-\sqrt m)-0}{x-\sqrt m}=1$$

- Sağ taraftaki türev (arksinüs parçası):

$$\lim_{x\to\sqrt m^+}\frac{\arcsin(x^2-m)-0}{x-\sqrt m}$$

- Arksinüsün argümanı $x^2-m$'dir, paydada ise $x-\sqrt m$ var. Argümanı paydada da elde etmek için pay ve payda eşleniğiyle, $x+\sqrt m$ ile çarpılır:

$$\lim_{x\to\sqrt m^+}\frac{\arcsin(x^2-m)}{x^2-m}\,(x+\sqrt m)$$

- $u=x^2-m$ denirse $x\to\sqrt m$ iken $u\to0$ olur. Problem şu limite dönüşür:

$$\lim_{u\to0}\frac{\arcsin u}{u}=\lim_{u\to0}\frac{\dfrac{1}{\sqrt{1-u^2}}}{1}=1\qquad\text{(L'Hôpital)}$$

- Geriye $(x+\sqrt m)\to 2\sqrt m$ kalır. Sağ türev $2\sqrt m$ olur.
- Sol ve sağ türev eşit olmalı: $2\sqrt m=1$, buradan $m=\dfrac14$.

Bir öğrenci de cevabı $\dfrac14$ olarak buldu. Hoca, $0$'ın nereden geldiğini de açıkladı: Paydaki $0$, fonksiyonun tanımından gelen $f(\sqrt m)$ değeridir.

> **Ders sonrası not:** Hoca 00:18:44 civarında limiti bir an "$\dfrac{\sin u}{u}$" diye söyledi; sonra 00:19:22'de doğru biçimde $\dfrac{\arcsin u}{u}$ dedi. Doğrusu arksinüs limitidir; değeri yine $1$'dir. Ayrıca 00:18:53'te sonuç "2²m" gibi okunuyor; doğru ifade $2\sqrt m=1$'dir (sympy ile doğrulandı: sağ türev $2\sqrt m$, $m=1/4$).

> **Ek bilgi (derste anlatılmadı):** $\arcsin$ yalnız $[-1,1]$ aralığında tanımlıdır ve uç noktalar $\pm1$'de türevlenemez; türevi $\dfrac{1}{\sqrt{1-u^2}}$ bu noktalarda sonsuza gider. Bu örnekte argüman $x^2-m$, $x=\sqrt m$ yakınında $0$ civarındadır. Bu yüzden zincir kuralıyla doğrudan alınan sağ türev de $\dfrac{2x}{\sqrt{1-(x^2-m)^2}}\Big|_{x=\sqrt m}=2\sqrt m$ verir ve sonuç değişmez. Hocanın tanımı kullanma tercihi, genel kuralı göstermek için güvenli yoldur.

> **Hocanın vurgusu:** Burada önemli olan sonucun kendisi değil, neden türevin tanımını kullanmak zorunda olduğumuzdur. Parçalardan biri her yerde türevlenebilir değilse parçaları doğrudan türevleyemezsiniz.

## 3. Kapalı Türev (Implicit Differentiation)

Kapalı (implicit) biçimde verilen bir denklemde $y$, $x$'e bağlı bir fonksiyon kabul edilir: $y=f(x)$ denklemde yerine konmuş gibi düşünülür. Bu durumda $y$'nin her kuvveti zincir kuralıyla (chain rule) türevlenir:

$$\frac{d}{dx}\,y^n = n\,y^{n-1}\,y'$$

Çünkü $y^n$, $y$'ye bağlıdır; $y$ de $x$'e bağlıdır.

### 3.1 Örnek 3: $\cos(x+y^2)=y^3$

**Soru (00:22:22).** $\cos(x+y^2)=y^3$ ise $\dfrac{dx}{dy}$ nedir?

**Çözüm.** Hoca önce $\dfrac{dy}{dx}$'i buldu. $y$ bağımlı, $x$ bağımsız değişkendir. İki taraf $x$'e göre türevlenir:

- Sol taraf: kosinüsün türevi çarpı argümanın türevi. Argüman $x+y^2$'nin türevi $1+2y\,y'$'dür ($y^2$ için zincir kuralı):

$$-\sin(x+y^2)\,\big(1+2y\,y'\big)$$

- Sağ taraf: $\dfrac{d}{dx}y^3=3y^2\,y'$.
- Eşitlik:

$$-\sin(x+y^2)-2y\sin(x+y^2)\,y'=3y^2\,y'$$

- $y'$ yalnız bırakılır:

$$\frac{dy}{dx}=\frac{-\sin(x+y^2)}{3y^2+2y\sin(x+y^2)}$$

- İstenen $\dfrac{dx}{dy}$, bunun tersidir:

$$\frac{dx}{dy}=-\,\frac{3y^2+2y\sin(x+y^2)}{\sin(x+y^2)}$$

Sonuç sympy ile doğrulandı.

**İkinci mertebe türev.** Hoca, ikinci mertebeden türev istenirse bu ifadenin bölüm kuralıyla (quotient rule) türevleneceğini söyledi: "payın türevi çarpı payda, eksi pay çarpı paydanın türevi, bölü paydanın karesi". Bunu ödev olarak bıraktı. Hocaya göre sonuçlar uzun çıktığı için bu tür sorular genelde sınavda doğrudan sorulmaz ama sorulabilir. Çözüm "Örnek Sorular" bölümünde verildi.

### 3.2 Örnek 4: Teğet ve normal doğru

Bu sorudan önce bir öğrenci $y^2$'nin neden zincir kuralıyla türevlendiğini sordu. Hoca bunun ders notlarında ayrıntılı anlatıldığını, $y^2$'nin $y$'ye, $y$'nin de $x$'e bağlı olduğunu, bu yüzden zincir kuralının uygulandığını tekrarladı ve önce dersin kendi videolarının izlenmesini önerdi. Öğrenci, zincir kuralının bu kadar basit bir ifadeye de uygulanması gerektiğini bilmediğini söyledi.

**Soru (00:29:33).** $x\sec(xy-y^2)+2y^3=x^2+2$ eğrisinin $P(1,1)$ noktasındaki teğet (tangent) ve normal doğru denklemlerini bulun.

**Çözüm.** Teğetin eğimi, $y$'nin $x$'e göre türevinin $P$'deki değeridir. $y$, $x$'e bağlıdır; iki taraf $x$'e göre türevlenir. Kolaylık için $u=xy-y^2$ denir.

- $x\sec u$ çarpımının türevi (çarpım kuralı): $1\cdot\sec u + x\cdot(\sec u\,\tan u)\cdot u'$.
- $u'=\dfrac{d}{dx}(xy-y^2)=\big(1\cdot y+x\,y'\big)-2y\,y'$. ($xy$ için çarpım kuralı, $y^2$ için zincir kuralı.)
- $\dfrac{d}{dx}(2y^3)=6y^2\,y'$.
- Sağ taraf: $\dfrac{d}{dx}(x^2+2)=2x$.

$$\sec u + x\sec u\tan u\,\big(y+x\,y'-2y\,y'\big)+6y^2\,y'=2x$$

- Şimdi $P(1,1)$ iki tarafa yerleştirilir. $u=1\cdot1-1^2=0$ olur. $\sec 0=\dfrac{1}{\cos0}=1$, $\tan 0=\dfrac{\sin0}{\cos0}=0$. Ortadaki terim $\tan 0$ çarpanı yüzünden sıfırlanır:

$$1+6\,y'=2 \;\Rightarrow\; m_T=y'\big|_P=\frac16$$

- Teğet doğrusu denklemi $y-y_0=m_T(x-x_0)$:

$$y-1=\frac16(x-1)$$

- Teğet ve normal doğruların eğimlerinin çarpımı $-1$'dir. Bu yüzden $m_N=-6$:

$$y-1=-6(x-1)$$

Nokta eğri üzerindedir ($1\cdot\sec0+2=3=1^2+2$) ve eğim $\dfrac16$ sympy ile doğrulandı. Hoca "Gördünüz mü, bu kadar basit; zor bir şey yok, türevi alırken dikkat edeceksiniz" dedi.

**Soru:** Bir öğrenci, bu tür soruların daha hızlı çözülmesi için "sıfır yapan değerin türevini alma" gibi bir kısa yol olduğunu, burada geçerli olup olmadığını sordu.

**Cevap:** Hoca geçerli olduğunu ama bu dönem anlatmadığını söyledi. Bu yöntemde bir $F$ fonksiyonu kurulur ve $\dfrac{dy}{dx}$ kısmi türevlerle (partial derivatives) bir formülle verilir. Bu formülün nasıl çıkarıldığını göstermek gerekir; o da kısmi türevlerle ve zincir kuralıyla ilgilidir. Bu yüzden konu gelecek dönemindir. Öğrenciler uygulayabiliyorsa uygulayabilir, ama bu dönem bundan sorumlu değildir.

> **Ek bilgi (derste anlatılmadı):** Öğrencinin sorduğu kısa yol, $F(x,y)=0$ biçimindeki kapalı denklem için $\dfrac{dy}{dx}=-\dfrac{F_x}{F_y}$ formülüdür. Burada $F_x$ ve $F_y$, $F$'nin $x$ ve $y$'ye göre kısmi türevleridir. Bu formül, iki değişkenli fonksiyonlarda zincir kuralından çıkar ve genelde ikinci dönemin kalkülüs dersinde görülür.

### 3.3 Örnek 5: İkinci mertebe kapalı türev

**Soru (00:39:44).** $x^3+y^3=1$ kapalı biçimi veriliyor. $\dfrac{d^2y}{dx^2}$ nedir?

<!-- BELİRSİZ: Altyazıda denklem 00:39:52'de "x kare artı 1" gibi geçiyor; çözümdeki türevler (3x² ve 3y²y') denklemin x³+y³=1 olduğunu gösteriyor. -->

Bu soru sırasında hoca, kısmi türevli formülü bu dönem anlatmadıklarını bir kez daha söyledi (00:41:22). Formülün ikinci mertebe türevde uygulanmasının da zor olduğunu belirtti; burada bölüm kuralı kullanılmalıdır.

**Çözüm.**

- Birinci türev: iki taraf $x$'e göre türevlenir. $y^3$ için zincir kuralı uygulanır, sabit $1$'in türevi $0$'dır:

$$3x^2+3y^2\,y'=0\;\Rightarrow\;y'=-\frac{x^2}{y^2}$$

- İkinci türev, bölüm kuralıyla. $x^2$'nin türevi $2x$, $y^2$'nin $x$'e göre türevi $2y\,y'$'dür:

$$y''=-\,\frac{2x\cdot y^2-x^2\cdot 2y\,y'}{y^4}=-\frac{2x}{y^2}+\frac{2x^2}{y^3}\,y'$$

- $y'$ yerine konur:

$$y''=-\frac{2x}{y^2}+\frac{2x^2}{y^3}\left(-\frac{x^2}{y^2}\right)=-\frac{2x}{y^2}-\frac{2x^4}{y^5}$$

Hoca dersi bu noktada bıraktı ve "Zor mu arkadaşlar?" diye sordu. Bu sonuç bir adım daha sadeleşir (ara adım eklendi):

$$y''=-\frac{2x\,y^3+2x^4}{y^5}=-\frac{2x\,(x^3+y^3)}{y^5}=-\frac{2x}{y^5}$$

Son adımda denklemdeki $x^3+y^3=1$ kullanıldı. Sonuç sympy ile doğrulandı.

### 3.4 Örnek 6: Farklı harflerle kapalı türev

**Soru (00:46:50).** $r\cos 2s+\sin^2 s=\pi$ ise $\dfrac{dr}{ds}$ nedir?

Hoca, bu tür ifadelerin sınavda doğrudan bu biçimde gelmeyeceğini, ama soruların içinde bunların kullanılacağını söyledi.

**Çözüm.** Burada $s$ bağımsız değişken, $r$ bağımlı değişkendir; $r$, $s$'nin fonksiyonudur. İki taraf $s$'ye göre türevlenir:

- $r\cos 2s$ için çarpım kuralı. $\cos 2s$'nin türevi, iç türev $2$ ile birlikte $-2\sin 2s$'dir:

$$r'\cos 2s-2r\sin 2s$$

- $\sin^2 s$'nin türevi: $2\sin s\cos s=\sin 2s$.
- $\pi$ sabittir, türevi $0$'dır.

$$r'\cos 2s-2r\sin 2s+\sin 2s=0$$

$$r'=\frac{(2r-1)\sin 2s}{\cos 2s}=(2r-1)\tan 2s$$

Derste hoca ilk denemede $\cos 2s$'nin iç türevini (2 çarpanını) unuttu ve $r'=(r-1)\tan 2s$ gibi bir sonuca ulaştı. "Hata mı yaptık?" diye sorunca bir öğrenci "Kosinüsün içinin türevini almadık" dedi. Hoca hatayı kabul etti, ilgili yeri düzeltti ve sonrasını öğrencilere bıraktı; "tanjantlı bir şey gelecek" dedi.

> **Ders sonrası not:** Hoca ilk çözümde $\dfrac{d}{ds}\cos 2s=-\sin 2s$ aldı ve $r'=(r-1)\tan 2s$ buldu. Doğrusu $\dfrac{d}{ds}\cos 2s=-2\sin 2s$ ve $r'=(2r-1)\tan 2s$'dir (sympy ile doğrulandı).

## 4. Tanım Kümesi (Domain) Bulma

Hoca, tanım kümesi sorularının test sınavında gelebileceğini, genellikle de vizede çıktığını söyledi. Kareköklü ve logaritmalı ifadeler toplam olarak ya da iç içe (bileşke, composition) olarak verilebilir.

**Kural: Tanım kümesi için temel koşullar**

- Karekök (radical) işaretinin argümanı negatif olmamalıdır: $\ge 0$ (pozitif ya da sıfır olabilir).
- Doğal logaritmanın ya da herhangi bir logaritmanın argümanı pozitif olmalıdır: $>0$.
- Toplam ya da bileşke fonksiyonda tüm koşullar birlikte ("ve") sağlanmalıdır; "ve" bağlacı kümelerin kesişimine karşılık gelir.

> **Hocanın vurgusu:** Tanım kümesi konusunu çalışmak çok önemli. Adım adım giderseniz hata en aza iner.

### 4.1 Örnek 7: Kök ve logaritma toplamı

**Soru (00:52:48).** $f(x)=\sqrt{x^2+2x}+\ln(x^2-2x)$ fonksiyonunun tanım kümesini bulun.

<!-- BELİRSİZ: Altyazıda kök içi "x square plus x" diye geçiyor; hocanın bulduğu kökler (0 ve -2) ifadenin x²+2x olduğunu gösteriyor. -->

**Çözüm.** $f_1=\sqrt{x^2+2x}$, $f_2=\ln(x^2-2x)$ denir.

- $f_1$ için $x^2+2x=x(x+2)\ge0$. Çarpanların kökleri $0$ ve $-2$'dir. İşaret tablosu: $0$'ın sağında ($x=1$ gibi) ifade pozitiftir; işaret kökler arasında değişir:

| aralık | $(-\infty,-2)$ | $(-2,0)$ | $(0,\infty)$ |
|---|---|---|---|
| $x(x+2)$ | $+$ | $-$ | $+$ |

$$D(f_1)=(-\infty,-2]\cup[0,\infty)$$

- $f_2$ için $x^2-2x=x(x-2)>0$. Kökler $0$ ve $2$'dir. $2$'den büyük bir değer konursa ifade pozitif çıkar:

| aralık | $(-\infty,0)$ | $(0,2)$ | $(2,\infty)$ |
|---|---|---|---|
| $x(x-2)$ | $+$ | $-$ | $+$ |

$$D(f_2)=(-\infty,0)\cup(2,\infty)$$

- Kesişim:

$$D(f)=D(f_1)\cap D(f_2)=(-\infty,-2]\cup(2,\infty)$$

Hoca uç noktaları ayrıca kontrol etti. $-2$ kümeye girer: kökün içi $0$ olur, logaritmanın içi $(-2)^2-2(-2)=8>0$ olur. $2$ kümeye girmez: logaritmanın içi $0$ olur ve $\ln 0$ tanımsızdır. Sonuç sympy ile doğrulandı.

> **Ders sonrası not:** Hoca $-2$'yi kontrol ederken logaritmanın içi için "artı 4" dedi (00:57:49). $x^2-2x$ ifadesinde $x=-2$ için değer $4+4=8$'dir; $4$ yalnız $x^2$ terimidir. Her iki durumda da değer pozitiftir, sonuç değişmez.

### 4.2 Örnek 8: İç içe logaritma

Bir öğrencinin isteği üzerine hoca, iç içe geçmiş (bileşke) bir örneği o an üretti ve "basit bir soru ama bize çok şey anlatıyor" dedi.

**Soru (00:58:24).** $f(x)=\ln\big(\ln(x^2-1)\big)$ fonksiyonunun tanım kümesini bulun.

<!-- BELİRSİZ: Fonksiyon altyazıda sesli okunmuyor; ifade hocanın çözüm adımlarından (iç ln'nin argümanı x²-1, dış ln'nin argümanı ln(x²-1)) kuruldu. -->

**Çözüm.** İki logaritmanın da argümanı pozitif olmalıdır.

- İç logaritma: $x^2-1>0$, yani $x^2>1$. Buradan $x\in(-\infty,-1)\cup(1,\infty)$ (açık aralıklar, uçlar dahil değil).
- Dış logaritma: $\ln(x^2-1)>0$. Eşitsizliğin iki tarafına doğal üstel fonksiyon $e^{(\cdot)}$ uygulanır. $e^x$ artan olduğu için eşitsizlik yön değiştirmez:

$$e^{\ln(x^2-1)}>e^0\;\Rightarrow\;x^2-1>1\;\Rightarrow\;x^2>2\;\Rightarrow\;|x|>\sqrt2$$

- İki koşul "ve" ile bağlıdır; bu kesişim demektir. İkinci küme birincinin alt kümesidir:

$$D(f)=(-\infty,-\sqrt2)\cup(\sqrt2,\infty)$$

Bir öğrenci hata olmadığını onayladı. Sonuç sympy ile doğrulandı.

Bu sorudan sonra derse 15 dakikalık bir ara verildi.

## 5. Bir Fonksiyonun Sabit Olduğunu Göstermek

**Kural: Sabit fonksiyon**

- Bir fonksiyonun sabit (constant) olduğunu göstermek için türevi alınır.
- Türev, tanım kümesindeki her $x$ için $0$ çıkarsa fonksiyon sabittir: $f(x)=C$.
- $C$'yi bulmak için tanım kümesinden özel bir $x$ değeri seçilip $f$'de yerine konur.

### 5.1 Örnek 9: $\arcsin$ ve $\arctan$ toplamı

**Soru (01:28:27).** $f(x)=\arcsin\dfrac{1-x}{1+x}+2\arctan\sqrt x$ fonksiyonunun sabit olduğunu gösterin.

**Çözüm.** Hoca önce kullanılacak türevleri hatırlattı. İkisi de zincir kuralıyla gösterilir:

$$(\arcsin u)'=\frac{u'}{\sqrt{1-u^2}},\qquad (\arctan u)'=\frac{u'}{1+u^2}$$

- Birinci terim, $u=\dfrac{1-x}{1+x}$. Bölüm kuralıyla:

$$u'=\frac{(-1)(1+x)-(1-x)(1)}{(1+x)^2}=\frac{-2}{(1+x)^2}$$

- Kökün içi (ara adım eklendi):

$$1-u^2=\frac{(1+x)^2-(1-x)^2}{(1+x)^2}=\frac{(1+2x+x^2)-(1-2x+x^2)}{(1+x)^2}=\frac{4x}{(1+x)^2}$$

- Birinci terimin türevi:

$$\frac{-2}{(1+x)^2}\cdot\frac{1+x}{2\sqrt x}=-\frac{1}{(1+x)\sqrt x}$$

- İkinci terim, $u=\sqrt x$, $u'=\dfrac{1}{2\sqrt x}$, $1+u^2=1+x$:

$$2\cdot\frac{\dfrac{1}{2\sqrt x}}{1+x}=\frac{1}{(1+x)\sqrt x}$$

- Toplam: $f'(x)=-\dfrac{1}{(1+x)\sqrt x}+\dfrac{1}{(1+x)\sqrt x}=0$. Demek ki $f(x)=C$.

Sadeleştirme sırasında hoca bir paydayı önce yanlış yazdı ve "bu $1+x$'in karesi olmalı" diyerek düzeltti.

**Sabitin bulunması.** $f(x)=C$ eşitliği tanım kümesindeki her $x$ için doğrudur. Bu yüzden özel bir değer koymak yeter. Hoca önce $x=1$'i düşündü, sonra $x=0$'ın daha iyi olduğunu söyledi:

$$f(0)=\arcsin 1+2\arctan 0=\frac{\pi}{2}+0=\frac{\pi}{2}$$

Yani $f(x)=\dfrac{\pi}{2}$'dir. Türevin sıfır olduğu ve $f(0)=f(1)=\dfrac\pi2$ sympy ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** $\sqrt x$ yüzünden $f$'nin tanım kümesi $x\ge0$'dır. $f'(x)$ formülünde $\sqrt x$ paydada olduğu için türev hesabı $x>0$ için geçerlidir. $f$, $x=0$'da sürekli olduğundan sabit değer $x=0$'da da geçerlidir.

## 6. Ters Fonksiyonun Türevi

**Kural: Ters fonksiyonun türevi**

$$(f^{-1})'\big(f(x_0)\big)=\frac{1}{f'(x_0)}$$

- Hoca bu formülün ters fonksiyon özelliğinden ve zincir kuralından geldiğini hatırlattı.
- Kullanım: önce $f(x_0)$ verilen değere eşitlenip $x_0$ bulunur, sonra $f'(x_0)$ hesaplanır.

> **Hocanın vurgusu:** Bir fonksiyonun tersinin türevini hesaplama soruları sınavlarda büyük ihtimalle gelir; bu kural önemlidir.

### 6.1 Örnek 10: $f(x)=e^{\arctan x}$

**Soru (01:38:49).** $f(x)=e^{\arctan x}$ veriliyor. $(f^{-1})'$'in $e^{\pi/3}$ noktasındaki değerini hesaplayın.

**Çözüm.**

- $f(x_0)=e^{\pi/3}$ olmalı: $e^{\arctan x_0}=e^{\pi/3}$, yani $\arctan x_0=\dfrac\pi3$.
- İki tarafa tanjant uygulanır: $x_0=\tan\dfrac\pi3=\tan 60^\circ=\sqrt3$.
- Türev. $(e^u)'=e^u\,u'$ (zincir kuralı) ve $(\arctan u)'=\dfrac{u'}{1+u^2}$:

$$f'(x)=e^{\arctan x}\cdot\frac{1}{1+x^2}$$

- $x_0=\sqrt3$'te: $f'(\sqrt3)=e^{\pi/3}\cdot\dfrac{1}{1+3}=\dfrac{e^{\pi/3}}{4}$.
- Formüle konur:

$$(f^{-1})'\big(e^{\pi/3}\big)=\frac{1}{f'(\sqrt3)}=\frac{4}{e^{\pi/3}}=4e^{-\pi/3}$$

Sonuç sympy ile doğrulandı. Hoca bu soruyu beklerken yoklama aldı.

> **Ders sonrası not:** Hoca 01:44:36'da "$\arctan x_0=\dfrac\pi2$" dedi, hemen ardından $x_0=\tan\dfrac\pi3$ ile devam etti. Doğrusu $\arctan x_0=\dfrac\pi3$'tür; $\arctan$ hiçbir zaman $\dfrac\pi2$ değerini almaz.

## 7. Logaritmik Türev (Logarithmic Differentiation)

Çarpım, bölüm ve kök içeren karmaşık ifadelerde $y$'yi doğrudan türevlemek uzun işlem getirir. Hocanın önerisi: türev almadan önce eşitliğin iki tarafına doğal logaritma uygulamak. Böylece çarpımlar toplama, bölümler çıkarmaya, kuvvetler katsayıya dönüşür.

**Kural: Logaritmik türev**

- İki tarafa $\ln$ uygulanır: $\ln y=\dots$
- Kullanılan özellikler: $\ln(ab)=\ln a+\ln b$, $\ln\dfrac ab=\ln a-\ln b$, $\ln a^c=c\ln a$.
- İki taraf $x$'e göre türevlenir. Sol taraf zincir kuralıyla: $\dfrac{d}{dx}\ln y=\dfrac{y'}{y}$.
- Sonuç: $y'=y\cdot(\text{sağ tarafın türevi})$.

> **Hocanın vurgusu:** Logaritmik türev çok önemlidir; sınavda karşınıza çıkma olasılığı çok yüksektir.

### 7.1 Örnek 11: Üç çarpanlı ifade

**Soru (01:48:51 civarı).** $y=\sqrt{x+3}\,\sin x\,(x^2+2)$ ise $y'$ nedir?

**Çözüm.**

- $\ln$ uygulanır:

$$\ln y=\frac12\ln(x+3)+\ln(\sin x)+\ln(x^2+2)$$

- İki taraf $x$'e göre türevlenir. $(\ln u)'=\dfrac{u'}{u}$:

$$\frac{y'}{y}=\frac12\cdot\frac{1}{x+3}+\frac{\cos x}{\sin x}+\frac{2x}{x^2+2}$$

- $\dfrac{\cos x}{\sin x}=\cot x$'tir. Sağ taraf $A$ ile gösterilirse:

$$y'=y\cdot A=\sqrt{x+3}\,\sin x\,(x^2+2)\left[\frac{1}{2(x+3)}+\cot x+\frac{2x}{x^2+2}\right]$$

Sonuç sympy ile doğrulandı. Hoca, $y$ zaten bilindiği için yerine yazılmasının yeterli olduğunu söyledi.

**Ödev.** Hoca ardından dört çarpanlı bir fonksiyonun $\dfrac{dy}{dx}$ türevini ödev olarak verdi. <!-- BELİRSİZ: Ödev fonksiyonu altyazıda okunmuyor (01:54:34-01:55:17 arası sessiz yazım). Kısa nota göre ∛(x³+x)·sec(x²+x)·arctan(√x+1)·arccos(...) biçimindedir; son çarpanın argümanı orada da tam okunamamış. --> Hocaya göre yöntem aynıdır: logaritmik türevle iş basitleşir.

Bu arada bir öğrenci problem tarzı soruları (örneğin dairenin yarıçapıyla ilgili soruları) sordu. Hoca bunların maksimum-minimum problemleri olduğunu, ekstremum değerlerle birlikte daha sonra işleneceğini söyledi.

### 7.2 Örnek 12: Taban ve üs değişken

**Soru (02:00:06 civarı).** $y=(1+\ln x)^x$ ise $y'$ nedir?

**Çözüm.**

- $\ln$ uygulanır: $\ln y=x\,\ln(1+\ln x)$.
- Sol taraf: $\ln y$, $y$'ye; $y$ de $x$'e bağlıdır. Zincir kuralıyla $\dfrac1y\cdot y'$.
- Sağ taraf çarpım kuralıyla: $x$'in türevi $1$ çarpı ikinci terim, artı $x$ çarpı $\ln(1+\ln x)$'in türevi. $(\ln u)'=\dfrac{u'}{u}$ ve $u=1+\ln x$ için $u'=\dfrac1x$:

$$\frac{y'}{y}=\ln(1+\ln x)+x\cdot\frac{1/x}{1+\ln x}$$

$$y'=(1+\ln x)^x\left[\ln(1+\ln x)+\frac{1}{1+\ln x}\right]$$

Sonuç sympy ile doğrulandı.

### 7.3 $a^x$ ile $x^x$ arasındaki fark

**Soru:** Bir öğrenci, $a^x$'in türev formülünü ($x$'in türevi çarpı $a^x$ çarpı $\ln a$) burada da uygulayıp uygulayamayacağını sordu.

**Cevap:** Hoca karıştırılmaması gerektiğini söyledi ve iki durumu ayırdı:

- $y=a^x$, $a$ sabit. $\ln y=x\ln a$. Türev: $\dfrac{y'}{y}=\ln a$, yani $y'=a^x\ln a$.
- $y=x^x$. Burada taban da değişkendir; bu "olağan" bir üstel fonksiyon değildir. Mutlaka iki tarafa $\ln$ uygulanır: $\ln y=x\ln x$. Türev:

$$\frac{y'}{y}=\ln x+x\cdot\frac1x=\ln x+1\;\Rightarrow\;y'=x^x(\ln x+1)$$

- "$y'=x^x\ln x$" yazmak büyük bir hatadır. Hoca bunu "copy paste mantık" diye eleştirdi.

> **Hocanın vurgusu:** Formül ezberlemeyin. Ben de formülü ezbere yazıyorum ama nasıl çıkarıldığını biliyorum. Unutursanız formülü nasıl çıkaracağınızı bilmeniz lazım; böylece mantık hatası yapmazsınız.

$x^x$ türevi sympy ile doğrulandı.

### 7.4 Örnek 13: Küpkök içinde bölüm

**Soru (02:04:29).** $y=\sqrt[3]{\dfrac{x(x-2)}{x^2+1}}$ ise $\dfrac{dy}{dx}$ nedir?

Hoca, fonksiyonun doğrudan da türevlenebileceğini ama bölüm kuralı yüzünden karmaşık işlemler çıkacağını söyledi. Logaritma uygulamak daha iyidir.

**Çözüm.**

$$\ln y=\frac13\Big[\ln x+\ln(x-2)-\ln(x^2+1)\Big]$$

$$\frac{y'}{y}=\frac13\left[\frac1x+\frac{1}{x-2}-\frac{2x}{x^2+1}\right]$$

$$y'=\sqrt[3]{\frac{x(x-2)}{x^2+1}}\cdot\frac13\left[\frac1x+\frac{1}{x-2}-\frac{2x}{x^2+1}\right]$$

Sonuç sympy ile doğrulandı.

### 7.5 Örnek 14: Tabanı değişken olan logaritma

Hoca "logaritmik türevle ilgili ilginç bir problem" diyerek bu soruyu o an üretti. Burada logaritmanın tabanı sabit değil, $x$ değişkenidir.

**Soru (02:10:34 civarı).** $\log_x(x^2+y)=y$ ise $y'$ nedir?

**Çözüm.**

- Logaritmanın tanımından (tabanı $x$ olan log fonksiyonunun tersini uygulayarak):

$$x^y=x^2+y$$

- İki tarafa doğal logaritma uygulanır:

$$y\ln x=\ln(x^2+y)$$

- $y$, $x$'e bağlıdır. İki taraf $x$'e göre türevlenir. Sol tarafta çarpım kuralı, sağda $(\ln u)'=\dfrac{u'}{u}$:

$$y'\ln x+\frac{y}{x}=\frac{2x+y'}{x^2+y}$$

- Hoca önce sağ taraftaki $y'$'yi gözden kaçırdı, sonra "Şurada $y'$ varmış, görmedim" diyerek düzeltti. $y'$ içeren terimler bir tarafa toplanır:

$$y'\left(\ln x-\frac{1}{x^2+y}\right)=\frac{2x}{x^2+y}-\frac{y}{x}$$

- Hoca sonrasını öğrencilere bıraktı. Açık biçimi (ara adım eklendi):

$$y'=\frac{\dfrac{2x}{x^2+y}-\dfrac yx}{\ln x-\dfrac{1}{x^2+y}}=\frac{2x^2-y(x^2+y)}{x\big[(x^2+y)\ln x-1\big]}$$

Sonuç sympy ile doğrulandı. Hocaya göre sınavda genelde bu ifadenin sadeleştirilmesi istenmez; bunun yerine belli bir noktadaki türev değeri (örneğin $y'(1)$ gibi), ya da o noktadaki teğet veya normal doğru sorulur. Elbette fonksiyonun o noktada tanımlı olması gerekir.

**Soru:** Bir öğrenci, $\log_x(x^2+y)$ ifadesini taban değiştirerek $\dfrac{\ln(x^2+y)}{\ln x}$ diye yazarsa sağ taraftaki $y$'ye de $\ln$ uygulamak zorunda olup olmadığını sordu. Başka bir öğrenci de $\dfrac{\ln(x^2+y)}{\ln x}=y$ yazıp doğrudan türev aldığını söyledi.

**Cevap:** Hoca o detaya girmek istemediğini söyledi. Kendi yolu şudur: logaritmanın tanımını (ters fonksiyon özelliğini) uygula, sonra iki tarafa doğal logaritmayı uygula. Aynı sonucu elde eden yol doğrudur. Hocaya göre lise bilgisindeki çok sayıda kural yerine şu üç temel bilgi ("üç yıldız") yeter; diğer özellikler bunlardan çıkar:

- $\log_a b=c \iff a^c=b$
- $\log(ab)=\log a+\log b$ (yalnız $\ln$ değil, her logaritma için)
- $\log\dfrac ab=\log a-\log b$

> **Ek bilgi (derste anlatılmadı):** Taban değiştirme yolu da aynı sonucu verir. $\dfrac{\ln(x^2+y)}{\ln x}=y$ eşitliği, paydalar kaldırılınca $y\ln x=\ln(x^2+y)$ eşitliğinin aynısıdır; bu yüzden kapalı türev aynı $y'$'yi verir (sympy ile eğri üzerinde eşit oldukları doğrulandı). Sağ taraftaki $y$'ye ayrıca $\ln$ uygulanmaz; eşitlik olduğu gibi türevlenir.

## 8. $1^\infty$ Belirsizliği İçeren Limitler

Hoca, logaritmik türevden sonra logaritmanın limitlerde kullanımına geçti. $x\to\infty$ iken taban $1$'e, üs $\infty$'a gidiyorsa $1^\infty$ belirsizliği (indeterminate form) vardır. İki yol gösterildi.

**Kural: Temel limit**

$$\lim_{u\to\infty}\left(1+\frac{a}{u}\right)^{u}=e^{a}$$

- Hoca bu formülün L'Hôpital kuralıyla gösterilebileceğini söyledi.

### 8.1 Örnek 15: İki yolla çözüm

**Soru (02:18:14).** $\displaystyle\lim_{x\to\infty}\left(\frac{x+7}{x+3}\right)^{2x+3}$ limitini hesaplayın.

Öğrencilerin hepsi cevabı $e^8$ buldu.

**1. yol (genel yöntem: logaritma).** İfadeye $A$ denir ve iki tarafa $\ln$ uygulanır:

$$\ln A=(2x+3)\,\ln\frac{x+7}{x+3}=\frac{\ln\dfrac{x+7}{x+3}}{\dfrac{1}{2x+3}}$$

- $x\to\infty$ iken bu $\dfrac00$ belirsizliğidir. L'Hôpital kuralı uygulanır. Paydanın türevi $-2(2x+3)^{-2}$'dir. Payın türevi (ara adım eklendi):

$$\frac{d}{dx}\ln\frac{x+7}{x+3}=\frac{1}{x+7}-\frac{1}{x+3}=\frac{-4}{(x+7)(x+3)}$$

$$\lim_{x\to\infty}\ln A=\lim_{x\to\infty}\frac{-4/\big((x+7)(x+3)\big)}{-2/(2x+3)^2}=\lim_{x\to\infty}\frac{2(2x+3)^2}{(x+7)(x+3)}=8$$

- Demek ki $\ln A\to8$ ve $A\to e^8$.

**2. yol (temel formül).** Taban, $1+\dfrac{a}{u}$ biçimine getirilir:

$$\frac{x+7}{x+3}=\frac{(x+3)+4}{x+3}=1+\frac{4}{x+3}$$

- $u=x+3$ denir; $x\to\infty$ iken $u\to\infty$. Ama asıl üs $u$ değil, $2x+3$'tür. Bu yüzden üs $u\cdot\dfrac{2x+3}{x+3}$ biçiminde yazılır:

$$\left[\left(1+\frac{4}{x+3}\right)^{x+3}\right]^{\frac{2x+3}{x+3}}$$

- Köşeli parantez içindeki "kutu" temel formüle göre $e^4$'e gider. Üsteki $\dfrac{2x+3}{x+3}$, $x$'in katsayılarının oranı olarak $2$'ye gider.
- Sonuç: $\left(e^4\right)^2=e^8$.

Hoca, temel formülleri bilmenin bazen avantaj sağladığını ve işi hızlandırdığını söyledi. Sonuç sympy ile doğrulandı ($\ln A\to8$, limit $e^8$).

> **Ders sonrası not:** Hoca 2. yolun sonunda önce "cevap $e^4$" dedi, hemen "$e^8$" diye düzeltti (02:26:11). Doğru cevap $e^8$'dir.

### 8.2 Örnek 16: Eksi işaretli durum

**Soru (02:27:12).** $\displaystyle\lim_{x\to\infty}\left(\frac{x}{x+3}\right)^{3x}$ limitini hesaplayın.

**Çözüm (temel formülle).**

- Pay, paydaya benzetilir:

$$\frac{x}{x+3}=\frac{(x+3)-3}{x+3}=1-\frac{3}{x+3}=1+\frac{-3}{x+3}$$

- $x\to\infty$ iken $1^\infty$ belirsizliği vardır. $u=x+3$ denir ve üs $u\cdot\dfrac{3x}{x+3}$ biçiminde yazılır:

$$\left[\left(1+\frac{-3}{u}\right)^{u}\right]^{\frac{3x}{x+3}}$$

- Kutu temel formüle göre ($a=-3$) $e^{-3}$'e gider. Üs $\dfrac{3x}{x+3}\to3$.
- Sonuç: $\left(e^{-3}\right)^3=e^{-9}$.

Hoca ikinci yolun yine doğal logaritma uygulamak olduğunu söyledi ama bu soruda o yolu yapmadı. Sonuç sympy ile doğrulandı.

## 9. Kaynaklar ve Çalışma Önerileri

Dersin sonunda hoca çözülecek başka soru kalmadığını söyledi ve şu önerileri verdi:

- Avesis'te paylaşılan, Pınar Hoca'nın geçmiş yıllarda çıkan sorulardan derlediği notlar çözülebilir. Bir öğrenci bunların İngilizce sürümünü sordu; hoca İngilizce sürümünün olmadığını, ama soruların çoğunun derste görüldüğünü söyledi. Tanım kümesi (domain), türev (derivative), süreklilik (continuity) gibi temel kavramlar bilinirse sorular anlaşılır. Hocaya göre "matematik evrensel bir dildir".
- Bir öğrenci Thomas' Calculus kitabındaki alıştırmaların çözümlerini sordu. Hocada çözümler yoktu; ona göre bu alıştırmaları çalışmak gerekmiyor, ertesi derste çözülecek geçmiş yıl soruları yeterli.
- Bir öğrenci integral sorusu olup olmayacağını sordu. Hoca integralin bu derslerde henüz anlatılmadığını, yalnız derste anlatılan konulara odaklanılması gerektiğini söyledi.
- Bir öğrenci test sorusu çözmek için İngilizce kaynak bulamadığını söyledi. Hoca çok soru çözmeye gerek olmadığını, derste çözülenleri çözebilenlerin işin mantığını kavradığını söyledi.

> **Hocanın vurgusu:** Eski usul ezber çalışma stilini bırakın; işin mantığını kavrayın. Bazen yorum soruları gelir; bunları çözmek için derste anlatılan mantığı kavramış olmanız gerekir. Logaritmik türev, limit, süreklilik, türevin tanımı, logaritmik limit, ters fonksiyonun türevi, kapalı fonksiyonun türevi ve zincir kuralının mantığını öğrenmeniz yeterlidir.

## Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular derste hocanın sözlü okuyup tahtada çözdüğü sorulardır. Çözümler yukarıdaki bölümlerde adım adım verilmiştir; burada soru ve sonuç özetlenir.

**Soru 1** (derste sözlü, 00:04:52). Parçalı $f$: bir parçası $\sin 2x$, öbürü $mx$. $f$, $x=0$'da hangi $m$ için türevlenebilir?

- Cevap: $m=2$ (Örnek 1).

**Soru 2** (derste sözlü, 00:10:12). Parçalı $f$: bir parçası $\arcsin(x^2-m)$, öbürü $x-\sqrt m$. $f$, $x=\sqrt m$'de türevlenebilir ise $m$ kaçtır?

- Cevap: $m=\dfrac14$ (Örnek 2).

**Soru 3** (derste sözlü, 00:22:22). $\cos(x+y^2)=y^3$ ise $\dfrac{dx}{dy}$ nedir?

- Cevap: $\dfrac{dx}{dy}=-\dfrac{3y^2+2y\sin(x+y^2)}{\sin(x+y^2)}$ (Örnek 3).

**Soru 4** (derste sözlü, ödev, 00:27:46). Aynı denklemde ikinci mertebe türevi bölüm kuralıyla bulun. <!-- BELİRSİZ: Altyazıdan hangi ikinci türevin (d²x/dy² mi d²y/dx² mi) istendiği net değil; hoca "derivation of this" diyerek bulunan dx/dy ifadesini gösteriyor, bu yüzden d²x/dy² alındı. -->

> **Çözüm (derste verilmedi):** $x$, $y$'nin fonksiyonu kabul edilir ve $\dfrac{dx}{dy}$ ifadesi $y$'ye göre türevlenir; $x$ içeren yerlerde $\dfrac{dx}{dy}$ çarpanı gelir. Sadeleşmiş sonuç (sympy ile hesaplandı):
>
> $$\frac{d^2x}{dy^2}=-2-\frac{6y}{\sin(x+y^2)}-\frac{9y^4\cos(x+y^2)}{\sin^3(x+y^2)}$$

**Soru 5** (derste sözlü, 00:29:33). $x\sec(xy-y^2)+2y^3=x^2+2$ eğrisinin $(1,1)$ noktasındaki teğet ve normal doğruları nedir?

- Cevap: Teğet $y-1=\dfrac16(x-1)$, normal $y-1=-6(x-1)$ (Örnek 4).

**Soru 6** (derste sözlü, 00:39:44). $x^3+y^3=1$ ise $\dfrac{d^2y}{dx^2}$ nedir?

- Cevap: $-\dfrac{2x}{y^2}-\dfrac{2x^4}{y^5}=-\dfrac{2x}{y^5}$ (Örnek 5).

**Soru 7** (derste sözlü, 00:46:50). $r\cos 2s+\sin^2 s=\pi$ ise $\dfrac{dr}{ds}$ nedir?

- Cevap: $(2r-1)\tan 2s$ (Örnek 6; derste son adım öğrencilere bırakıldı).

**Soru 8** (derste sözlü, 00:52:48). $f(x)=\sqrt{x^2+2x}+\ln(x^2-2x)$ fonksiyonunun tanım kümesi nedir?

- Cevap: $(-\infty,-2]\cup(2,\infty)$ (Örnek 7).

**Soru 9** (derste sözlü, 00:58:24). $f(x)=\ln(\ln(x^2-1))$ fonksiyonunun tanım kümesi nedir? <!-- BELİRSİZ: fonksiyon çözüm adımlarından kuruldu. -->

- Cevap: $(-\infty,-\sqrt2)\cup(\sqrt2,\infty)$ (Örnek 8).

**Soru 10** (derste sözlü, 01:28:27). $f(x)=\arcsin\dfrac{1-x}{1+x}+2\arctan\sqrt x$ fonksiyonunun sabit olduğunu gösterin.

- Cevap: $f'(x)=0$, $f(x)=\dfrac\pi2$ (Örnek 9).

**Soru 11** (derste sözlü, 01:38:49). $f(x)=e^{\arctan x}$ ise $(f^{-1})'(e^{\pi/3})$ nedir?

- Cevap: $\dfrac{4}{e^{\pi/3}}$ (Örnek 10).

**Soru 12** (derste sözlü, 01:48:51 civarı). $y=\sqrt{x+3}\,\sin x\,(x^2+2)$ ise $y'$ nedir?

- Cevap: $y'=y\left[\dfrac{1}{2(x+3)}+\cot x+\dfrac{2x}{x^2+2}\right]$ (Örnek 11).

**Soru 13** (derste sözlü, 02:00:06 civarı). $y=(1+\ln x)^x$ ise $y'$ nedir?

- Cevap: $y'=(1+\ln x)^x\left[\ln(1+\ln x)+\dfrac{1}{1+\ln x}\right]$ (Örnek 12).

**Soru 14** (derste sözlü, öğrenci sorusu, 02:01:56). $y=x^x$ için $y'=x^x\ln x$ yazılabilir mi?

- Cevap: Hayır. $y'=x^x(\ln x+1)$ (Bölüm 7.3).

**Soru 15** (derste sözlü, 02:04:29). $y=\sqrt[3]{\dfrac{x(x-2)}{x^2+1}}$ ise $\dfrac{dy}{dx}$ nedir?

- Cevap: $y'=\dfrac y3\left[\dfrac1x+\dfrac{1}{x-2}-\dfrac{2x}{x^2+1}\right]$ (Örnek 13).

**Soru 16** (derste sözlü, 02:10:34 civarı). $\log_x(x^2+y)=y$ ise $y'$ nedir?

- Cevap: $y'=\dfrac{2x^2-y(x^2+y)}{x\big[(x^2+y)\ln x-1\big]}$ (Örnek 14; derste son sadeleştirme öğrencilere bırakıldı).

**Soru 17** (derste sözlü, 02:18:14). $\displaystyle\lim_{x\to\infty}\left(\frac{x+7}{x+3}\right)^{2x+3}$ nedir?

- Cevap: $e^8$ (Örnek 15).

**Soru 18** (derste sözlü, 02:27:12). $\displaystyle\lim_{x\to\infty}\left(\frac{x}{x+3}\right)^{3x}$ nedir?

- Cevap: $e^{-9}$ (Örnek 16).

## Dersin Toparlaması

Bu ders, ara sınav öncesinde birinci dönem konularının soru üzerinden tekrarıydı. Parçalı fonksiyonlarda türevlenebilirlikte iki koşul (ayrım noktasında süreklilik ve parçaların her yerde türevlenebilir olması) sağlanırsa parçaların doğrudan türevlenebildiği, sağlanmazsa türevin limit tanımının kullanılması gerektiği görüldü. Kapalı türevde $y$'nin $x$'e bağlı olduğu unutulmadan zincir kuralı uygulandı; birinci ve ikinci mertebe türevler, teğet ve normal doğrular bulundu. Tanım kümesinde kök için $\ge0$, logaritma için $>0$ koşulları ve "ve" bağlacının kesişim anlamı vurgulandı. Türevi sıfır olan bir fonksiyonun sabit olduğu, sabitin özel bir $x$ değeriyle bulunduğu gösterildi.

İkinci yarıda ters fonksiyonun türevi formülü $(f^{-1})'(f(x_0))=1/f'(x_0)$, logaritmik türev ve $1^\infty$ belirsizliği işlendi. Hocanın ana mesajı formül ezberlemek yerine formülün nereden geldiğini bilmekti: $x^x$ gibi tabanı değişken ifadelerde $a^x$ formülünü kopyalamak büyük hatadır; logaritmanın üç temel özelliği bilinirse gerisi bunlardan çıkar. Ertesi derste geçmiş yılın test sınavı soruları çözülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
