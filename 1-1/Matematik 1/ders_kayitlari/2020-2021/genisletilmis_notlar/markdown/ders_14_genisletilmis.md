# Ders 14 Genişletilmiş Notu: Geçmiş Yıl Vize Sorularının Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş
- 2. Örnek 1 (Soru 1-3): Türev Grafiğinden Artanlık ve Azalanlık
- 3. Örnek 2 (Soru 4): Hiperbolik Fonksiyonlu İfade
- 4. Örnek 3 (Soru 5): Tablo Verisiyle Ters Fonksiyonun Türevi
- 5. Örnek 4 (Soru 6): Tablo Verisiyle Teğet Doğru
- 6. Örnek 5 (Soru 7): Doğrusal Yaklaşım
- 7. Örnek 6 (Soru 8): Kapalı Türevle Bilinmeyen Sabiti Bulma
- 8. Örnek 7 (Soru 9): $0^0$ Belirsizliği
- 9. Örnek 8 (Soru 10): Sandviç Teoremi
- 10. Örnek 9 (Soru 11): L'Hôpital Kuralı ve Zincir Kuralı
- 11. Örnek 10 (Soru 13): Zincir ve Çarpım Kuralı
- 12. Soru 12 ve Soru 14: Çözülmeyen Sorular
- 13. Örnek 11 (Soru 15): Temel Limitle Sadeleştirme
- 14. Örnek 12 (Soru 16): Limitin Yokluğu
- 15. Örnek 13 (Soru 17): Hangi İfade Yanlış?
- 16. Örnek 14 (Soru 18): Kaldırılabilir Süreksizlik
- 17. Örnek 15 (Soru 19): Türevin Tanımı
- 18. Örnek 16 (Soru 20): Logaritmik Türev
- Örnek Sorular

## 1. Derse Giriş

Bu ders, birinci vizeden önceki son derstir. Hoca, geçmiş yıla ait bir vize (test) sınavının sorularını ekranda paylaştı ve sırayla çözdü. Soruların İngilizce sürümünü bulamadığı için Türkçe metni paylaştı, açıklamaları İngilizce yaptı. Hoca her soruda öğrencilere önce birkaç dakika çözme süresi verdi, sonra çözümü tablete yazarak birlikte yaptı.

Hoca bazı soruları ya da şıkları atladı. Bunlar ekstremum değerler, konkavlık (concavity), mutlak maksimum ve ortalama değer teoremi (mean value theorem) gibi final konularıydı. Hoca integralin de derste henüz anlatılmadığını hatırlattı.

Hocanın genel tespiti şudur: Bu sınavdaki soruların çoğu limit hesabıdır. Sorular "her şey hazır lokma" biçimindedir. Mantık, derste çözülen sorularla aynıdır. Derste çözülen sorular bunlardan daha zordur.

> **Hocanın vurgusu:** Derste çözdüğümüz soruları çözüme bakmadan yapabiliyorsanız başarılı olursunuz. Başka kaynaklara dağılmaya gerek yok. Önemli olan çok soru çözmek değil, her sorunun arkasındaki mantığı (philosophy behind each question) anlamaktır.

## 2. Örnek 1 (Soru 1-3): Türev Grafiğinden Artanlık ve Azalanlık

**Soru:** Bir aralıkta tanımlı bir $f$ fonksiyonunun türevi $f'$'nün grafiği veriliyor. Aşağıdaki ifadelerden hangisi söylenemez?

<!-- BELİRSİZ: Grafik ve şıkların tam metni altyazıda yok. Tanım aralığı ve aralık uçları yalnız sözlü anlatımdan alındı. -->

Hoca bu sorunun bir final konusu olduğunu, ama şıklarının bir kısmının birinci vize konusuna girdiğini söyledi. Temel kural şudur:

**Türevin işareti ve monotonluk**

- $f'>0$ olan aralıkta $f$ artandır (increasing).
- $f'<0$ olan aralıkta $f$ azalandır (decreasing).

Hoca bunu türevin anlık değişim hızı (instantaneous rate of change) olmasıyla açıkladı. Anlık değişim hızı negatifse fonksiyon azalır.

Şıklar şöyle incelendi:

- **Azalanlık şıkkı:** $f'$'nün negatif olduğu bölgede $f$ azalandır. Bu ifade doğrudur.
- **$(-2,1)$ aralığında artanlık:** Grafikte bu aralıkta $f'$ pozitiftir. Bu yüzden $f$ artandır. İfade doğrudur.
- **$(1,\infty)$ aralığında azalanlık:** Bu aralıkta türev negatiftir, $f$ azalandır. İfade doğrudur. <!-- BELİRSİZ: Bu kısımda altyazı döngüye giriyor (00:08:52); açıklamanın ayrıntısı anlaşılmıyor. -->
- **D ve E şıkları:** Yerel ekstremum değerlerle ilgilidir. Hoca bunların final konusu olduğunu söyleyip bakmadı.

**Soru:** D ve E şıkları sınava gelmeyecek mi? **Cevap:** Hoca, ekstremum ve yerel ekstremum değerlerin final konusu olduğunu, bu vize için çalışmaya gerek olmadığını söyledi.

> **Hocanın vurgusu:** Vizede artanlık ve azalanlıkla ilgili, şıkları A, B, C'ye benzeyen sorular gelebilir.

## 3. Örnek 2 (Soru 4): Hiperbolik Fonksiyonlu İfade

**Soru:** Aşağıdaki ifadeyi üstel fonksiyon cinsinden yazın.

$$\frac{1+\tanh x}{1-\tanh x}$$

Hoca önce hiperbolik fonksiyonların üstel fonksiyon cinsinden yazılışını hatırlattı:

**Hiperbolik fonksiyonlar (hyperbolic functions)**

- $\sinh x=\dfrac{e^x-e^{-x}}{2}$
- $\cosh x=\dfrac{e^x+e^{-x}}{2}$
- $\tanh x=\dfrac{\sinh x}{\cosh x}=\dfrac{e^x-e^{-x}}{e^x+e^{-x}}$

Hoca önce sonucu ($e^{2x}$) söyledi. Bir öğrenci işlem hatası yaptığını ve sonuca varamadığını söyleyince çözümü yazdı.

**Çözüm:**

- Pay: $1+\tanh x=\dfrac{(e^x+e^{-x})+(e^x-e^{-x})}{e^x+e^{-x}}=\dfrac{2e^x}{e^x+e^{-x}}$
- Payda: $1-\tanh x=\dfrac{(e^x+e^{-x})-(e^x-e^{-x})}{e^x+e^{-x}}=\dfrac{2e^{-x}}{e^x+e^{-x}}$
- Ortak paydalar sadeleşir:

$$\frac{1+\tanh x}{1-\tanh x}=\frac{2e^x}{2e^{-x}}=e^{2x}$$

Hoca payda sadeleştirmesinde eksi işaretlerine dikkat edilmesi gerektiğini söyledi: $e^x+e^{-x}-e^x+e^{-x}$ ifadesinde $e^x$'ler birbirini götürür, geriye $2e^{-x}$ kalır.

## 4. Örnek 3 (Soru 5): Tablo Verisiyle Ters Fonksiyonun Türevi

**Soru:** $f$ türevlenebilir ve tersinir bir fonksiyondur. Aşağıdaki tablo veriliyor. $(f^{-1})'(6)$ değeri nedir?

| $x$ | 1 | 2 | 3 |
|---|---|---|---|
| $f(x)$ | 6 | 4 | 1 |
| $f'(x)$ | -3 | 8 | -5 |

<!-- BELİRSİZ: Tablonun tamamı altyazıda okunmuyor. f(1)=6, f'(1)=-3, f'(2)=8, f(3)=1, f'(3)=-5 değerleri altyazıda geçiyor; f(2)=4 değeri kısa nottan alındı. -->

**Ters fonksiyonun türevi**

- $f(x_0)=y_0$ ise $(f^{-1})'(y_0)=\dfrac{1}{f'(x_0)}$.

**Çözüm:**

- İstenen $y_0=6$ değeridir. Tabloda $f(x_0)=6$ olan $x_0$ değeri $1$'dir.
- $f'(1)=-3$.
- $(f^{-1})'(6)=\dfrac{1}{f'(1)}=-\dfrac13$.

Şıklardan biri "tablodaki bilgiler bu değeri bulmaya yetmez" diyordu. Hoca bunun doğru olmadığını söyledi. Cevap C şıkkıdır.

> **Hocanın vurgusu:** Bu çok basit bir soru, herkesin çözmesi lazım. Sınavda büyük olasılıkla bundan daha zoru, zincir kuralıyla ters fonksiyon özelliğinin birlikte kullanıldığı bir soru gelir.

## 5. Örnek 4 (Soru 6): Tablo Verisiyle Teğet Doğru

**Soru:** Aynı türden bir tablo ile $f$ türevlenebilir ve tersinir fonksiyonu veriliyor. $f$'nin grafiğine $x=2$ noktasında teğet olan doğrunun denklemi nedir?

**Teğet doğru denklemi**

- $y-y_0=m(x-x_0)$, burada $m=f'(x_0)$ teğetin eğimidir.

Hoca çözümün ilk denemesinde $x=1$ sütunundaki değerleri ($6$ ve $-3$) kullandı ve $y=-3x$ gibi bir sonuca ulaştı. Bir öğrenci sorunun $x=2$ noktasını sorduğunu hatırlattı. Hoca dikkat dağınıklığından hata yaptığını söyleyip çözümü düzeltti.

**Doğru çözüm:**

- $x_0=2$, $y_0=f(2)=4$, $m=f'(2)=8$.
- $y-4=8(x-2)$.
- $y=8x-12$.

Cevap C şıkkıdır.

> **Ders sonrası not:** İlk denemede yazılan $y-6=-3x+3$ eşitliğinden $y=-3x+9$ çıkar; altyazıda geçen $y=-3x$ sonucu bu eşitlikle de uyuşmaz. Bu deneme zaten soru yanlış okunduğu için bırakıldı. Sorunun doğru cevabı $y=8x-12$'dir.

Bu sorudan sonra hoca, bu soruların geçmiş yılın soruları olduğunu, bu yılki sınavın biraz daha zor olabileceğini söyledi. Ona göre derste çözülen soruları bakmadan yapabilen öğrencinin stres yapmasına gerek yoktur.

## 6. Örnek 5 (Soru 7): Doğrusal Yaklaşım

**Soru:** Aynı tabloya göre $f(3.1)$'in yaklaşık değeri nedir?

**Doğrusal yaklaşım (linear approximation)**

- $x$, $a$'ya yakınsa $f(x)\approx f(a)+f'(a)(x-a)$.

Hoca formülü ezberletmediğini, nasıl çıkarıldığını derste gösterdiğini hatırlattı.

**Çözüm:**

- $3.1$ sayısı $3$'e yakındır. Bu yüzden $a=3$ seçilir.
- Tablodan $f(3)=1$, $f'(3)=-5$.
- $f(3.1)\approx 1+(-5)(3.1-3)=1-5\cdot\dfrac{1}{10}=0.5$.

<!-- BELİRSİZ: Şık harfi altyazıda "The answer is 8" olarak geçiyor; büyük olasılıkla "A" denmiştir. -->

> **Hocanın vurgusu:** Bu sorular basit ama dikkat gerektiriyor. İşlem hatası yapmamak gerekir.

## 7. Örnek 6 (Soru 8): Kapalı Türevle Bilinmeyen Sabiti Bulma

**Soru:** $c$ bir sabittir. $x^2-c\sin(xy)=x+\tan y$ kapalı (implicit) biçimde verilen eğrinin $(1,0)$ noktasındaki teğet doğrusu $y=-x+1$ ise $c$ kaçtır?

**Çözüm:**

Teğet doğrunun eğimi $-1$'dir. Bu, $y$'nin $x$'e göre türevinin $(1,0)$ noktasındaki değeridir: $y'(1)=-1$.

Eşitliğin iki tarafının $x$'e göre türevi alınır. $y$, $x$'e bağlı düşünülür.

- $x^2$'nin türevi $2x$'tir.
- $\sin(xy)$'nin türevi zincir kuralıyla $\cos(xy)\cdot(xy)'$'dir. Çarpım kuralıyla $(xy)'=1\cdot y+x\cdot y'$.
- $\tan y$'nin türevi $(1+\tan^2y)\,y'$'dür.

$$2x-c\cos(xy)\,(y+xy')=1+(1+\tan^2y)\,y'$$

$x=1$, $y=0$, $y'=-1$ yazılır:

- Sol taraf: $2-c\cdot\cos 0\cdot(0+1\cdot(-1))=2+c$.
- Sağ taraf: $1+(1+0)(-1)=0$.
- $2+c=0$, yani $c=-2$.

Cevap B şıkkıdır. Hoca bu sorunun derste çözülen sorulara göre çok kolay olduğunu söyledi.

### 7.1 Öğrenci sorusu: $\cos(xy)$'nin iç türevi

**Soru:** $\sin(xy)$ türevlenince içinin türevi neden $1\cdot y+x\cdot y'$ olarak yazılıyor? **Cevap:** Türevde bir bağımlı, bir bağımsız değişken vardır. Burada $y$, $x$'e bağlıdır, ama denklem kapalı verildiği için $y$ açıkça $x$ cinsinden yazılamaz. Bu yüzden $y$'yi $y=f(x)$ gibi düşünerek türev alırız. $\dfrac{dy}{dx}$ yazmak da "$y$, $x$'e bağlı" demektir.

Hoca ayrıntıyı şöyle gösterdi. Trigonometrik fonksiyonun içine $u=x\,f(x)$ denirse, zincir kuralıyla dış fonksiyonun $u$'ya göre türevi, $u$'nun $x$'e göre türeviyle çarpılır. $u$'nun türevi çarpım kuralıyla $1\cdot f(x)+x\cdot f'(x)$'tir. Sınavda $y$ yerine her seferinde $f(x)$ yazmaya gerek yoktur: $f'(x)$ dediğimiz şey aslında $y'$'dür. Bu yüzden doğrudan $(xy)'=y+xy'$ yazılır.

> **Ders sonrası not:** Hoca açıklamada örnek olarak "kosinüs $u$'nun türevi eksi sinüs $u$ çarpı $u'$" kuralını kullandı. Sorudaki ifade ise $\sin(xy)$'dir ve türevi $\cos(xy)\cdot(xy)'$'dir. İç türevin alınışı iki durumda da aynıdır.

Hoca bu soru üzerine bir çalışma önerisi de verdi. Öğrenciler konuları genellikle çok soru çözerek öğrenmeye çalışır. Bu, ezbere yönlendirir. Dersler dinlenip özümsenirse çok soru çözmeye gerek kalmaz.

## 8. Örnek 7 (Soru 9): $0^0$ Belirsizliği

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to0^+}\left(\sin x^2\right)^{1/\ln x}$$

Hoca cevabın $e^2$ olduğunu baştan söyledi ve genel yöntemi, yani doğal logaritmayı kullanmayı önerdi.

**Çözüm:**

- $A=(\sin x^2)^{1/\ln x}$ denir.
- İki tarafın doğal logaritması alınır: $\ln A=\dfrac{\ln(\sin x^2)}{\ln x}$.
- $x\to0^+$ iken pay ve payda $-\infty$'a gider. Bu $\dfrac{\infty}{\infty}$ belirsizliğidir. L'Hôpital kuralı uygulanabilir.

> **Hocanın vurgusu:** Burada bölümün türev kuralı (quotient rule) uygulanmaz. L'Hôpital kuralı, pay ve paydanın türevlerinin oranının limitini almak demektir. Öğrenciler bu ikisini karıştırıyor.

- Payın türevi: $\dfrac{\cos x^2\cdot 2x}{\sin x^2}$. Paydanın türevi: $\dfrac1x$.

$$\lim_{x\to0^+}\ln A=\lim_{x\to0^+}\frac{\dfrac{2x\cos x^2}{\sin x^2}}{\dfrac1x}=\lim_{x\to0^+}2\cos x^2\cdot\frac{x^2}{\sin x^2}$$

- $\cos x^2\to1$ ve $\dfrac{x^2}{\sin x^2}\to1$ olduğundan limit $2$'dir.
- $\ln A\to2$ olduğundan $A\to e^2$.

### 8.1 Öğrenci soruları

**Soru:** $x$ sıfıra sağdan yaklaşırken $\ln(\sin x^2)$ neden sonsuza gidiyor? **Cevap:** $x$ sıfıra sağdan yaklaşırken $\sin x^2$ pozitif değerler alır ve sıfıra yaklaşır. $\ln$ fonksiyonunun argümanına sıfıra çok yakın pozitif bir sayı konursa sonuç $-\infty$ gibi bir değer olur. $\ln$'in grafiği orada aşağı doğru iner. Paydadaki $\ln x$ de $-\infty$'a gider. Bu yüzden belirsizlik $\dfrac{\infty}{\infty}$ türündedir.

**Soru:** Payda $\sin x^2$ iken limit neden $2$'ye gidiyor? **Cevap:** Hoca şu temel limitleri hatırlattı:

$$\lim_{u\to0}\frac{\sin u}{u}=1,\qquad \lim_{u\to0}\frac{u}{\sin u}=1$$

İfade $\dfrac{2\cdot x\cdot x}{\sin x^2}$ biçimindedir. $u=x^2$ denirse $x\to0$ iken $u\to0$ olur. Problem $\dfrac{u}{\sin u}$ limitine dönüşür ve bu $1$'e gider. Sonuç $2$'dir.

> **Hocanın vurgusu:** Her zaman L'Hôpital uygulamak zorunda değilsiniz. L'Hôpital ile genel kurallar elde etmiştik; gerisi pratiktir.

Bu sorudan sonra hoca, sınavın büyük kısmının limit sorusu olduğunu söyledi. Bu yılki vizede bu sınavdakinden de daha çok limit sorusu beklenebilir. Bunun yanında türev, ters fonksiyonun türevi ve türevin tanımı da konular arasındadır.

## 9. Örnek 8 (Soru 10): Sandviç Teoremi

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to\infty}\frac{x\sin(x!)}{x^2+1}$$

<!-- BELİRSİZ: Çözümün ortası altyazıda döngüye giriyor (00:54:12); eşitsizlik zinciri altyazıda tam okunmuyor, sonucu ve sözlü anlatımı ile kuruldu. -->

**Çözüm:**

$x\to\infty$ iken $x!$ sonsuza gider. Sinüs fonksiyonu $-1$ ile $+1$ arasında salınır (oscillates). Sınırlı bir fonksiyon söz konusu olduğunda sandviç teoremi (sandwich theorem) uygulanır. Hoca bunu öğrencilere sordu, öğrenciler doğru cevabı verdi.

- $-1\le\sin(x!)\le1$.
- $x>0$ için iki taraf $\dfrac{x}{x^2+1}$ ile çarpılır (ara adım eklendi):

$$-\frac{x}{x^2+1}\le\frac{x\sin(x!)}{x^2+1}\le\frac{x}{x^2+1}$$

- $x\to\infty$ iken iki sınır da $0$'a gider.
- Sandviç teoremine göre ortadaki ifade de $0$'a gider.

> **Hocanın vurgusu:** "$\sin(\infty)$" biçimini gördüğünüzde sandviç teoremini uygulamanız gerekir.

## 10. Örnek 9 (Soru 11): L'Hôpital Kuralı ve Zincir Kuralı

**Soru:** $f'(3)=2$ ise aşağıdaki limit nedir?

$$\lim_{h\to2}\frac{f(h+1)-f(5-h)}{h-2}$$

**Çözüm:**

- $h=2$ konunca pay $f(3)-f(3)=0$, payda $0$ olur. $\dfrac00$ belirsizliği vardır. L'Hôpital kuralı uygulanır.
- Payın $h$'ye göre türevi zincir kuralıyla alınır: $f'(h+1)\cdot1-f'(5-h)\cdot(-1)$.
- Paydanın türevi $1$'dir.

$$\lim_{h\to2}\big[f'(h+1)+f'(5-h)\big]=f'(3)+f'(3)=2+2=4$$

Hoca bu sorunun basit olduğunu söyledi. Bu arada bir öğrencinin sorusu üzerine, bu yılki vizenin büyük olasılıkla 20 sorudan oluşacağını belirtti.

### 10.1 Hocanın uydurduğu daha zor soru

Hoca, daha zor bir sorunun nasıl olabileceğini göstermek için kafasından bir soru yazdı:

$$\lim_{a\to0}\frac{f\!\left(1-\dfrac{\sin a}{a}\right)-f\!\left(\dfrac{\arcsin a}{a}-1\right)}{a^2}$$

<!-- BELİRSİZ: Paydanın ifadesi altyazıda tam okunmuyor ("over a over a"). Hocanın sonraki "1 bölü 2A" çarpanından paydanın büyük olasılıkla a^2 olduğu çıkarıldı. -->

Hoca önce ikinci terimi farklı yazmıştı. Böyle olunca $\dfrac00$ belirsizliği çıkmadığını fark etti ve ifadeyi $\dfrac{\arcsin a}{a}-1$ olarak düzeltti. Hedef, sonucu $f'(0)$ cinsinden bulmaktı.

- $a\to0$ iken $\dfrac{\sin a}{a}\to1$ ve $\dfrac{\arcsin a}{a}\to1$. İki $f$'nin argümanı da $0$'a gider. $\dfrac00$ belirsizliği vardır.
- L'Hôpital uygulanır. Zincir kuralıyla payın türevi:

$$-f'\!\left(1-\frac{\sin a}{a}\right)\cdot\frac{a\cos a-\sin a}{a^2}-f'\!\left(\frac{\arcsin a}{a}-1\right)\cdot\frac{\dfrac{a}{\sqrt{1-a^2}}-\arcsin a}{a^2}$$

Hoca bu türevi ilk yazdığında birinci terimdeki eksi işaretini unuttu. Bir öğrenci "ilk fonksiyonda içinin türevini alırken eksi almadık" diye uyardı. Hoca işareti düzeltti.

Hoca paydanın türevinden gelen $\dfrac{1}{2a}$ çarpanını yazdı, ama tahtada yer kalmadığı için çözümü bitirmedi. Ona göre bu kadar uzun işlem isteyen bir soru test sınavında sorulmaz.

> **Çözüm (derste verilmedi):** Paydanın $a^2$ olduğu kabulüyle limit $f'(0)\cdot\lim\dfrac{\sin a-a\cos a}{2a^3}-f'(0)\cdot\lim\dfrac{\dfrac{a}{\sqrt{1-a^2}}-\arcsin a}{2a^3}$ biçimine gelir. İki limit de $\dfrac16$'dır (sympy ile doğrulandı). Sonuç $f'(0)\left(\dfrac16-\dfrac16\right)=0$'dır. Payda farklıysa sonuç değişir; bu yüzden bu sonuç büyük olasılıkla hocanın kurduğu sorunun sonucudur.

## 11. Örnek 10 (Soru 13): Zincir ve Çarpım Kuralı

**Soru:** $g$ fonksiyonu $1$ noktasında türevlenebilir, $g(1)=1$, $g'(1)=2$. $f(x)=x\arctan\big(g(x)^2\big)$ ise $f'(1)$ nedir?

**Çözüm:**

Çarpım kuralı ve zincir kuralı birlikte kullanılır. Hoca $\arctan u$'nun türevini hatırlattı: $(\arctan u)'=\dfrac{u'}{1+u^2}$. Burada $u=g(x)^2$ ve $u'=2g(x)g'(x)$'tir.

$$f'(x)=1\cdot\arctan\big(g(x)^2\big)+x\cdot\frac{2g(x)g'(x)}{1+g(x)^4}$$

$x=1$ yazılır:

- $\arctan\big(g(1)^2\big)=\arctan1=\dfrac\pi4$.
- $\dfrac{2\cdot g(1)\cdot g'(1)}{1+g(1)^4}=\dfrac{2\cdot1\cdot2}{2}=2$.
- $f'(1)=\dfrac\pi4+2$.

## 12. Soru 12 ve Soru 14: Çözülmeyen Sorular

**Soru 12** ortalama değer teoremiyle ilgiliydi. Hoca bunun final konusu olduğunu söyleyip çözmedi.

**Soru 14** bir fonksiyonun tanım kümesini soruyordu. Hoca bir ifadenin sıfırdan büyük ya da eşit olması gerektiğini söyledi. Üç durum ayrı ayrı incelenir, sonunda elde edilen aralıkların kesişimi alınır. Hoca bu soruyu ödev bıraktı.

<!-- BELİRSİZ: Soru 14'ün fonksiyonu altyazıda yok; anlatım da kısmen bozuk (01:11:37-01:12:24). -->

## 13. Örnek 11 (Soru 15): Temel Limitle Sadeleştirme

**Soru:** Aşağıdaki limiti hesaplayın.

$$\lim_{x\to0}\frac{(\sin x)^{100}}{x^{99}\sin 2x}$$

**Çözüm:**

- İfade $\left(\dfrac{\sin x}{x}\right)^{99}\cdot\dfrac{\sin x}{\sin 2x}$ olarak yazılır.
- $\sin 2x=2\sin x\cos x$ kullanılır. $\sin x$'ler sadeleşir: $\dfrac{\sin x}{2\sin x\cos x}=\dfrac{1}{2\cos x}$.
- $x\to0$ iken $\dfrac{\sin x}{x}\to1$ ve $\cos x\to1$.

$$\lim_{x\to0}\left(\frac{\sin x}{x}\right)^{99}\cdot\frac{1}{2\cos x}=\frac12$$

> **Hocanın vurgusu:** Burada L'Hôpital uygulamaya gerek yok. Doğrudan düzenlemeyle hemen çözülür.

## 14. Örnek 12 (Soru 16): Limitin Yokluğu

**Soru:** $f$ pozitif değerli bir fonksiyondur ve $\displaystyle\lim_{x\to0}x f(x)=3$'tür. Buna göre $\displaystyle\lim_{x\to0}\frac{f(x)}{|x|}$ nedir?

Cevap C şıkkı, yani "limit yoktur" seçeneğidir. Hoca öğrencilere bunun nasıl anlaşılacağını sordu.

Bir öğrenci sağdan ve soldan yaklaşarak sonuca varmaya çalıştı. Hoca bunun ispat olmadığını, verilen bilginin kullanılması gerektiğini söyledi. Bir başka öğrenci $x$'i paydaya atmayı önerdi. Hoca "$x$'i paydaya atmak $\dfrac{f(x)}{1/x}$ yazmak demektir" diye yönlendirdi. Sonunda bir öğrenci $x$ ile çarpıp bölmeyi önerdi. Hoca "aynen öyle" dedi.

**Çözüm:**

Pay ve payda $x$ ile çarpılır:

$$\lim_{x\to0}\frac{f(x)}{|x|}=\lim_{x\to0}\frac{x f(x)}{x\,|x|}$$

- Pay verilen bilgiye göre $3$'e gider.
- Payda $x|x|$, sağdan $0^+$'ya, soldan $0^-$'ya gider.
- Sonuç bir taraftan $+\infty$, öbür taraftan $-\infty$ olur.
- Sağ ve sol limit farklıdır. Limit yoktur.

**Soru:** Neden iki tarafı $x$ ile çarptık? **Cevap:** Pay ve paydayı aynı sayıyla çarpmak ifadenin özdeşliğini bozmaz. Özdeş ifadelerin limitleri eşittir. Bu, limitin en temel kurallarından biridir.

Bir öğrenci $f$'nin pozitif olmasının ne işe yaradığını sordu. Hoca soruyu hazırlayanın böyle hazırladığını, çözümde bu bilginin faydasını görmediklerini söyledi.

> **Ders sonrası not:** $f$ pozitif ise $x<0$ için $x f(x)<0$ olur. O zaman $\displaystyle\lim_{x\to0^-}x f(x)$ en fazla $0$ olabilir ve $3$'e eşit olamaz. Yani sorunun varsayımları kendi içinde tutarsızdır. Hocanın gösterdiği çözüm yolu yine de sınavda beklenen cevabı (limit yok) verir.

## 15. Örnek 13 (Soru 17): Hangi İfade Yanlış?

**Soru:** Aşağıdaki ifadelerden hangisi yanlıştır?

<!-- BELİRSİZ: Şıkların tam metni altyazıda yok. İkinci şıkkın büyük olasılıkla lim_{x->0} sin(1/x) olduğu çözümden çıkarıldı. E şıkkı derste incelenmedi. -->

**a) $\displaystyle\lim_{x\to\infty}x\sin\frac1x=1$.** İfade $\dfrac{\sin(1/x)}{1/x}$ olarak yazılır. $t=\dfrac1x$ dönüşümü yapılır. $x\to\infty$ iken $t\to0^+$. $\dfrac{\sin t}{t}\to1$. İfade doğrudur.

**b) Sinüsün salınımı.** $t=\dfrac1x$ dönüşümü yapılır. $x\to0$ iken $t$, $+\infty$ ya da $-\infty$'a gider. $t\to\pm\infty$ iken $\sin t$, $-1$ ile $+1$ arasında salınır. Limiti yoktur. "Limit yoktur" diyen ifade doğrudur.

**c) $\displaystyle\lim_{x\to0^-}e^{1/x}=0$.** $x\to0^-$ iken $\dfrac1x\to-\infty$ olur. $e^{-\infty}=\dfrac{1}{e^{\infty}}=\dfrac1\infty$, yani sonuç sağdan $0$'a yaklaşır ($0^+$). İfade doğrudur.

**d) $\displaystyle\lim_{x\to0}\left(\frac12\right)^{1/x}=0$.** İki taraf ayrı incelenir:

- $x\to0^+$: $\dfrac1x\to+\infty$, $\left(\dfrac12\right)^{+\infty}\to0$.
- $x\to0^-$: $\dfrac1x\to-\infty$, $\left(\dfrac12\right)^{-\infty}=2^{+\infty}\to\infty$.
- Sağdan $0$, soldan $\infty$ çıkar. Limit $0$ değildir. Bu ifade yanlıştır.

Cevap D şıkkıdır. Hoca şıklardan giderek cevabın D olduğunu gördüğünü, ama yine de diğer şıkları gösterdiğini söyledi.

> **Hocanın vurgusu:** $0$ ile $1$ arasındaki bir sayının yeterince büyük kuvveti limit durumunda $0$'dır. Aynı sayının $-\infty$'uncu kuvveti limit durumunda sonsuzdur. Bunlar belirsizlik değildir.

**Soru:** a şıkkında sandviç teoremi uygulanabilir mi? **Cevap:** Uygulanamaz. Sandviç teoremini uygulamak için sinüsün ya da kosinüsün argümanının sonsuza gitmesi gerekir. Burada $x\to\infty$ iken argüman $\dfrac1x\to0$ olur. Bu sorunun sandviçle ilgisi yoktur. $x$ paydaya $\dfrac1x$ olarak atılır, $\dfrac1x=t$ denir ve $\dfrac{\sin t}{t}$ elde edilir.

Hoca bu sorunun birden fazla bilgiyi ölçtüğünü vurguladı: belirsizlik tipleri ve limitin temel kuralları.

## 16. Örnek 14 (Soru 18): Kaldırılabilir Süreksizlik

**Soru:** Aşağıdaki fonksiyonlardan hangisinin $x=2$ noktasında kaldırılabilir süreksizliği (removable discontinuity) vardır?

<!-- BELİRSİZ: Şıklardaki fonksiyonların tam biçimi altyazıda yok. ln, sin, tan ve rasyonel şıklar sözlü çözümden kuruldu. -->

**Kaldırılabilir süreksizlik**

- Fonksiyonun noktada sağdan ve soldan limiti vardır, bu limitler aynı ve sonludur.
- Ama fonksiyonun o noktadaki değeri bu limitten farklıdır (ya da tanımlı değildir).
- Limit sonsuz çıkarsa kaldırılabilir süreksizlikten söz edilemez.

Şıklar şöyle incelendi:

- **$\ln$ içeren şık:** $x\to2^+$ iken $\ln(0^+)=-\infty$. Bu sonsuz süreksizliktir (infinite discontinuity).
- **$\sin\dfrac{2}{2-x}$ şıkkı:** $x\to2^+$ iken $\dfrac{2}{0^-}\to-\infty$, soldan ise $+\infty$. $\sin(\pm\infty)$, $-1$ ile $+1$ arasında salınır. Limit yoktur. Kaldırılabilir süreksizlik değildir.
- **Tanjant içeren şık:** $x\to2$ iken tanjantın argümanı $\dfrac\pi2$'ye gider. Sonuç $+\infty$ ya da $-\infty$ olur. Bu da sonsuz süreksizliktir. <!-- BELİRSİZ: tanjantlı şıkkın tam ifadesi altyazıda bozuk ("tan pi'ı 2'ye"). -->
- **Rasyonel şık:** Pay ve payda çarpanlarına ayrılır. $(x-2)$ çarpanı sadeleşir ve geriye $\dfrac{x+3}{x+2}$ kalır. Sağdan ve soldan limit $\dfrac{2+3}{2+2}=\dfrac54$'tür. Limit sonlu ve iki taraftan aynıdır. Fonksiyon $x=2$'de tanımlı değildir. Kaldırılabilir süreksizlik budur.

<!-- BELİRSİZ: Rasyonel fonksiyonun çarpanlara ayrılmış hali altyazıda karışık ("x minus x plus 3 ... x minus 3"); sonuç 5/4 ile uyumlu biçim (x+3)(x-2)/((x-2)(x+2)) olarak yazıldı. -->

**Soru:** B şıkkındaki "sinüs salınıyor" ne demek? **Cevap:** $x$ ekseni üzerinde yürüdükçe grafik $-1$ ile $+1$ arasında gidip gelir. Hiçbir değere yaklaşmaz, hiçbir yatay doğruya yaklaşmaz. Bu yüzden limit yoktur.

## 17. Örnek 15 (Soru 19): Türevin Tanımı

**Soru:** $g(0)=0$, $g'(0)=0$, $g''(0)=16$ veriliyor. $f(x)=\dfrac{g(x)}{x}$ ($x\ne0$) ve $f(0)=0$ ise $f'(0)$ nedir?

Hoca bu sorunun türevin tanımını uygulamakla ilgili olduğunu söyledi.

> **Hocanın vurgusu:** Türevin tanımını kullanmak zorundasınız. Sakın doğrudan türev almaya çalışmayın; $\dfrac00$ belirsizliği çıkar, zaman kaybedersiniz. Türevin tanımı çok önemlidir.

**Çözüm:**

Türevin tanımı yazılır. $x\to0$ iken $x$ hep $0$'dan farklıdır ama sürekli $0$'a yaklaşır. Bu yüzden $f(x)$ yerine $\dfrac{g(x)}{x}$ yazılabilir.

$$f'(0)=\lim_{x\to0}\frac{f(x)-f(0)}{x-0}=\lim_{x\to0}\frac{\dfrac{g(x)}{x}-0}{x}=\lim_{x\to0}\frac{g(x)}{x^2}$$

- $g(0)=0$ olduğundan $\dfrac00$ belirsizliği vardır. L'Hôpital uygulanır: $\displaystyle\lim_{x\to0}\frac{g'(x)}{2x}$.
- $g'(0)=0$ olduğundan yine $\dfrac00$ çıkar. L'Hôpital tekrar uygulanır: $\displaystyle\lim_{x\to0}\frac{g''(x)}{2}$.
- $g''(0)=16$ olduğundan sonuç $\dfrac{16}{2}=8$'dir.

Hoca bu soruyu "çok güzel, klas bir soru" diye niteledi. Çok işlem gerektirmez, konuyu bilip bilmediğinizi ölçer. Hoca bir önceki derste de bununla ilgili bir soru çözdüklerini hatırlattı.

## 18. Örnek 16 (Soru 20): Logaritmik Türev

**Soru:** Aşağıdaki fonksiyon için $y'(1)$ nedir?

$$y=\sqrt[3]{\frac{(x+1)(x^2+1)}{(x^3+1)(x^4+1)}}$$

Hoca bu tarz sorularda doğrudan türev alınmadığını, doğal logaritma uygulanarak problemin basitleştirildiğini hatırlattı.

**Çözüm:**

İki tarafın doğal logaritması alınır. $\ln$'in özellikleri kullanılır:

$$\ln y=\frac13\Big[\ln(x+1)+\ln(x^2+1)-\ln(x^3+1)-\ln(x^4+1)\Big]$$

İki taraf $x$'e göre türetilir. $\ln y$, $y$'ye bağlıdır; $y$ de $x$'e bağlıdır. Zincir kuralıyla $\ln y$'nin $x$'e göre türevi $\dfrac{y'}{y}$'dir.

$$\frac{y'}{y}=\frac13\left[\frac{1}{x+1}+\frac{2x}{x^2+1}-\frac{3x^2}{x^3+1}-\frac{4x^3}{x^4+1}\right]$$

$y'=y\cdot(\ldots)$ olduğundan $y(1)$ değeri de gerekir:

- $y(1)=\sqrt[3]{\dfrac{2\cdot2}{2\cdot2}}=1$.
- Köşeli parantez $x=1$'de: $\dfrac12+1-\dfrac32-2=-2$.
- $y'(1)=1\cdot\dfrac13\cdot(-2)=-\dfrac23$.

Cevap B şıkkıdır.

Ders sonunda hoca genel bir değerlendirme yaptı. Bu sınavın ilk 10-12 sorusu çok kolaydı, sonrakiler orta zorluktaydı. Soru 19 için yalnız türevin tanımını bilmek yeter. Soru 18 için kaldırılabilir süreksizliğin tanımını ve belirsizlik tiplerini bilmek yeter. Soru 17 için belirsizlik tipleri ve temel limit kuralları yeter. Soru 16'da yalnız limitin temel kurallarıyla özdeş bir ifade elde edilip verilen bilgi kullanıldı.

> **Hocanın vurgusu:** Çok soru çözmek önemli değildir. Her sorunun arkasındaki felsefeyi anlamak başarının anahtarıdır. Sınav konusu dışındaki kaynaklardan çalışırsanız kafanız karışır.

## Örnek Sorular

Bu derste video ve kare yoktur. Aşağıdaki sorular derste ekranda paylaşılıp hocanın öğrencilere çözdürdüğü geçmiş yıl vize sorularıdır. Soru metinleri hocanın sözlü okumasından kurulmuştur. Çözümler yukarıdaki ilgili bölümlerdedir.

1. (derste sözlü, 00:12:29) $\dfrac{1+\tanh x}{1-\tanh x}$ ifadesini üstel fonksiyon cinsinden yazın. Cevap: $e^{2x}$ (Bölüm 3).
2. (derste sözlü, 00:18:20) Tablo verisine göre ($f(1)=6$, $f'(1)=-3$) $(f^{-1})'(6)$ nedir? Cevap: $-\dfrac13$ (Bölüm 4).
3. (derste sözlü, 00:22:05) Aynı tabloya göre $f$'nin grafiğine $x=2$ noktasında teğet olan doğrunun denklemi nedir? Cevap: $y=8x-12$ (Bölüm 5). <!-- BELİRSİZ: f(2)=4 değeri altyazıda geçmiyor. -->
4. (derste sözlü, 00:27:03) Aynı tabloya göre ($f(3)=1$, $f'(3)=-5$) $f(3.1)$'in yaklaşık değeri nedir? Cevap: $0.5$ (Bölüm 6).
5. (derste sözlü, 00:32:09) $x^2-c\sin(xy)=x+\tan y$ eğrisinin $(1,0)$ noktasındaki teğeti $y=-x+1$ ise $c$ kaçtır? Cevap: $-2$ (Bölüm 7).
6. (derste sözlü, 00:40:50) $\displaystyle\lim_{x\to0^+}\left(\sin x^2\right)^{1/\ln x}$ limitini hesaplayın. Cevap: $e^2$ (Bölüm 8).
7. (derste sözlü, 00:52:33) $\displaystyle\lim_{x\to\infty}\frac{x\sin(x!)}{x^2+1}$ limitini hesaplayın. Cevap: $0$ (Bölüm 9).
8. (derste sözlü, 00:55:07) $f'(3)=2$ ise $\displaystyle\lim_{h\to2}\frac{f(h+1)-f(5-h)}{h-2}$ nedir? Cevap: $4$ (Bölüm 10).
9. (derste sözlü, 00:58:50) Hocanın uydurduğu soru: $\displaystyle\lim_{a\to0}\frac{f\!\left(1-\frac{\sin a}{a}\right)-f\!\left(\frac{\arcsin a}{a}-1\right)}{a^2}$ limitini $f'(0)$ cinsinden bulun. Derste bitirilmedi; payda $a^2$ ise cevap $0$ (Bölüm 10.1). <!-- BELİRSİZ: payda altyazıda tam okunmuyor. -->
10. (derste sözlü, 01:08:04) $g(1)=1$, $g'(1)=2$ ve $f(x)=x\arctan\big(g(x)^2\big)$ ise $f'(1)$ nedir? Cevap: $\dfrac\pi4+2$ (Bölüm 11).
11. (derste sözlü, 01:12:59) $\displaystyle\lim_{x\to0}\frac{(\sin x)^{100}}{x^{99}\sin 2x}$ limitini hesaplayın. Cevap: $\dfrac12$ (Bölüm 13).
12. (derste sözlü, 01:14:15) $f$ pozitif değerli ve $\displaystyle\lim_{x\to0}x f(x)=3$ ise $\displaystyle\lim_{x\to0}\frac{f(x)}{|x|}$ nedir? Cevap: limit yoktur (Bölüm 14).
13. (derste sözlü, 01:20:44) Limitlerle ilgili ifadelerden hangisi yanlıştır? Cevap: $\displaystyle\lim_{x\to0}\left(\tfrac12\right)^{1/x}=0$ ifadesi (Bölüm 15). <!-- BELİRSİZ: şıkların tam metni altyazıda yok. -->
14. (derste sözlü, 01:29:25) Verilen fonksiyonlardan hangisinin $x=2$'de kaldırılabilir süreksizliği vardır? Cevap: sadeleşince $\dfrac{x+3}{x+2}$ kalan rasyonel fonksiyon (Bölüm 16). <!-- BELİRSİZ: şıkların tam metni altyazıda yok. -->
15. (derste sözlü, 01:35:30) $g(0)=0$, $g'(0)=0$, $g''(0)=16$, $f(x)=\dfrac{g(x)}{x}$ ($x\ne0$), $f(0)=0$ ise $f'(0)$ nedir? Cevap: $8$ (Bölüm 17).
16. (derste sözlü, 01:40:25) $y=\sqrt[3]{\dfrac{(x+1)(x^2+1)}{(x^3+1)(x^4+1)}}$ ise $y'(1)$ nedir? Cevap: $-\dfrac23$ (Bölüm 18).

## Dersin Toparlaması

Bu ders, birinci vizeye hazırlık olarak geçmiş yılın bir vize sınavının çözümüne ayrıldı. Sorular dersin ilk yarısının bütün konularını taradı: türevin işaretiyle artanlık ve azalanlık, hiperbolik fonksiyonlar, tablo verisiyle ters fonksiyonun türevi, teğet doğru ve doğrusal yaklaşım, kapalı türev, $0^0$ ve $\dfrac\infty\infty$ belirsizlikleri, sandviç teoremi, L'Hôpital kuralı, zincir ve çarpım kuralları, temel trigonometrik limitler, tek taraflı limitlerle limitin yokluğu, kaldırılabilir süreksizlik, türevin tanımı ve logaritmik türev.

Hocanın her soruda öne çıkardığı fikir aynıydı: Soruyu çözmek için tanımı ve temel kuralı bilmek yeter. Sandviç teoremi yalnız trigonometrik fonksiyonun argümanı sonsuza gittiğinde gerekir. $\dfrac{\sin u}{u}$ türü temel limitler L'Hôpital'e gerek bırakmaz. $0$ ile $1$ arasındaki bir sayının $\pm\infty$'uncu kuvveti belirsizlik değildir. Türevin tanımını isteyen sorularda doğrudan türev almak yerine tanım yazılır. Ekstremum değerler, konkavlık, ortalama değer teoremi ve integral ise finalin konularıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
