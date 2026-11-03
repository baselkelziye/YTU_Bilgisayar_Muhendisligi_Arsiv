# Ders 23 Çalışma Özeti

> Tarih: 22 Aralık 2020 (Salı). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. Dersin ilk iki saati 2. vizeye hazırlık soru çözümü; son kısımda final konusu olan rasyonel fonksiyonların integraline (basit kesirlere ayırma) giriş yapıldı.

## Genel Konular

- Geçen hafta kalem bozuk olduğu için yarım kalan mazeret sınavı soruları.
- 2020 yaz okulu final mazeret sınavı (MAT1071) soruları:
  - Kısmi integrasyon (integration by parts) ile verilen integrallerden yeni integral bulma.
  - Değişken değiştirme (substitution) ile integral.
  - $f(cd) = f(c) + f(d)$ özelliği ve L'Hôpital ile türev değeri.
  - Tek fonksiyonun simetrik aralıkta integrali.
  - Temel teorem ile birleştirilmiş doğrusallaştırma (linearization).
  - Riemann toplamını belirli integrale çevirme.
  - Temel teorem ile kapalı (implicit) türev.
  - $\dfrac{\ln x}{x}$ fonksiyonunun bükülme noktası.
- Rasyonel fonksiyonların integrali: basit kesirlere ayırma (partial fractions) yöntemine giriş.

## Hocanın Özellikle Vurguladığı Kısımlar

- **2. vize beklentisi:** 1. vizede ortalama yüksek çıktığı için 2. vizenin daha zor olacağını tahmin ediyor ("%80 ihtimalle"). Sorular hem düşünme hem işlem gerektirecek. Mazeret sınavındaki soruların zorluğu, sınavda beklenebilecek en üst düzey.
- **2. vize konuları (hocanın özeti):**
  - Asimptotlar (1-2 soru).
  - Ekstremumlar (1-2 soru).
  - Temel teorem çok önemli; birçok konuyla birleştirilebilir.
  - Riemann toplamları.
  - Değişken değiştirme ve kısmi integrasyon gerektiren integral soruları. Doğrudan integral sorulmaz; düşündüren sorular gelir.
  - 1. vize konuları 2. vize konularıyla harmanlanabilir (ör. doğrusallaştırma + temel teorem).
- Rasyonel fonksiyonların integrali **final** konusu, 2. vizede sorumlu değilsiniz. Yay uzunluğu, trigonometrik dönüşüm ve parçacık hızı soruları da final konusu.
- Çok uzun bir integrant görürseniz içinde bir hile vardır: belirli integralin özelliklerini (tek/çift fonksiyon gibi) hatırlayın.
- Sonuca değil yönteme odaklanın. "Sonuca odaklanırsanız kaybedersiniz."
- Formül ezberlemeyin. Bir öğrencinin "arccos'un türevi mi?" sorusuna hoca, formülleri karıştırmamak için türevlerin nereden geldiğini bilmek gerektiğini söyledi.
- Ders videolarını izlemek ve işin mantığını kavramak gerekli.
- Final notu için "50 puanı geçme" şartı olmadığını söyledi.
- Hoca ertesi gün (ders 24) bir miktar konu işleyeceğini, vakit kalırsa soru çözeceğini, 12. haftanın konularını bitirmeleri gerektiğini söyledi.

## Kısa Tekrar Notları

- $\dfrac{d}{dx}\ln|f(x)| = \dfrac{f'(x)}{f(x)}$: mutlak değer varken de türev, mutlak değer yokmuş gibi alınır.
- **Kısmi integrasyon (belirli integral):** $\displaystyle\int_a^b u\,dv = \big[uv\big]_a^b - \int_a^b v\,du$.
- **Değişken değiştirmede sınırlar da değişir:** $u = 3x^2$ ise $x=1 \Rightarrow u=3$, $x=2 \Rightarrow u=12$.
- **Tek fonksiyon:** $f(-x) = -f(x)$ ise $\displaystyle\int_{-a}^{a} f(x)\,dx = 0$.
  - tek × tek = çift, çift × çift = çift, tek × çift = tek.
- **Doğrusallaştırma:** $L(x) = h(a) + h'(a)(x-a)$.
- **Riemann toplamı → integral:** $\displaystyle\int_a^b f(x)\,dx = \lim_{n\to\infty}\sum_{k=1}^{n} f(x_k)\,\Delta x$, $\Delta x = \dfrac{b-a}{n}$, $x_k = a + k\,\Delta x$.
- **Basit kesirlere ayırma kuralları:**
  - Katsız reel kök $(x-a)$: $\dfrac{A}{x-a}$.
  - Katlı reel kök $(x-a)^m$: $\dfrac{A_1}{x-a} + \dfrac{A_2}{(x-a)^2} + \dots + \dfrac{A_m}{(x-a)^m}$.
  - Reel kökü olmayan (karmaşık kökü olan) ikinci derece çarpan $(x^2+bx+c)$: payda bir derece düşük polinom, $\dfrac{Bx+C}{x^2+bx+c}$.
  - Katlı karmaşık kök $(x^2+1)^2$: her kat için ayrı terim, $\dfrac{Dx+E}{x^2+1} + \dfrac{Fx+G}{(x^2+1)^2}$.
  - Genel kural: çarpanın derecesi $d$ ise paya derecesi $d-1$ olan polinom yazılır (ör. $x^4+1$ için $Bx^3+Cx^2+Dx+E$).

## Detaylı Açıklamalar

### Mazeret sınavı Soru 7: $f(x) = \ln|x^2-1|$ için hangisi doğru? (Anahtar: B)

Şıklar:
- A) $f$'nin $(0,0)$'da yerel minimumu var.
- B) Grafiği tanım kümesinde yukarı içbükey.
- C) $f$ tanım kümesinde artan.
- D) $f$'nin görüntü kümesi tüm reel sayılar.
- E) $f$ tanım kümesinde azalan.

Çözüm:
- $f'(x) = \dfrac{2x}{x^2-1} = \dfrac{2x}{(x-1)(x+1)}$. İşareti belirleyen üç çarpan var: $-1$, $0$, $1$.
- $(-1,0)$'da $f$ artan, $(0,1)$'de azalan. $x = 0$'da yerel **maksimum** var: A yanlış.
- $$f''(x) = \frac{2(x^2-1) - 2x\cdot 2x}{(x^2-1)^2} = \frac{-2(x^2+1)}{(x^2-1)^2} < 0$$
  $f'' $ her yerde negatif: grafik tanım kümesinde **aşağı** içbükey.
- Hoca "işlem hatası yapmadıysak B şıkkı concave down olmalı; bu sınavın son hâli değil" dedi.
- C ve E yanlış (işaret tablosu artan ve azalan aralıkları gösteriyor). D'yi de yanlış saydı.

### Mazeret sınavı: ekstremum değerleri (Cevap A)

- Fonksiyon $f(x) = \dfrac{x^2-x-1}{x-2}$ ($x \ne 2$).
- $$f'(x) = \frac{(2x-1)(x-2) - (x^2-x-1)}{(x-2)^2} = \frac{x^2-4x+3}{(x-2)^2} = \frac{(x-1)(x-3)}{(x-2)^2}$$
- Payda çift kuvvetli, işareti hep pozitif; yok sayılır. Kritik noktalar $x=1$ ve $x=3$. $x = 2$ tanım kümesinde değil.
- İşaret: $+,\ -,\ +$. $x = 1$'de yerel maksimum, $x = 3$'te yerel minimum.
- Uç değerler: $f(1) = 1$, $f(3) = 5$.

### Mazeret sınavı Soru 19 (kiriş ve teğet) tekrar

- $y = x^2 - 8x$, $x=1$ ve $x=10$: $\dfrac{f(10)-f(1)}{9} = \dfrac{20-(-7)}{9} = 3$.
- $2c - 8 = 3 \Rightarrow c = \dfrac{11}{2}$. Hoca anahtardaki cevabın yanlış olduğunu kabul etti ve doğru $c$'nin $\tfrac{11}{2}$ olduğunu söyledi.

### Mazeret sınavı: $g$'nin $x=4$'te yerel maksimumu varsa

- $g$'nin birinci ve ikinci türevi var, $x=4$'te yerel maksimumu var. $f(x) = e^{-g(x^2)}$ gibi tanımlı bir $f$ için hangi ifade doğru soruluyor.
- Zincir kuralı: $f'(x) = e^{-g(x^2)}\cdot\big(-g'(x^2)\big)\cdot 2x$.
- $x = 4$ yakınında $x^2 \approx 16$ olur. $g'$'nin 16 civarındaki işareti bilinmiyor. Bu yüzden $f$'nin $x=4$'teki davranışı hakkında kesin bir şey söylenemez.
- $x = 2$ yakınında $x^2 \approx 4$ olur. $g'$, 4'ün solunda pozitif, sağında negatif.
  - $x$, 2'nin hemen sağında: $g'(x^2) < 0$, yani $-g'(x^2) > 0$; $e^{(\dots)} > 0$, $2x > 0$. Sonuç: $f' > 0$.
  - $x$, 2'nin hemen solunda: $f' < 0$.
  - Birinci türev testinden $f$'nin $x = 2$'de **yerel minimumu** var. Doğru cevap bu.
- Hoca bunun yorum gerektiren güzel bir soru olduğunu söyledi.

### 2020 Yaz Final Mazeret Soru 2 (Cevap E)

$$\int_1^3 f'(x)\,dx = 1,\quad \int_1^3 f(x)f'(x)\,dx = 1,\quad \int_1^3 x^2 f'(x)\,dx = 1 \quad\Rightarrow\quad \int_1^3 x f(x)\,dx = ?$$

1. $\int_1^3 f'(x)\,dx = f(3) - f(1) = 1$.
2. $u = f(x)$ ile $\int_1^3 f f'\,dx = \dfrac{f(3)^2 - f(1)^2}{2} = 1$. Buradan $\dfrac{(f(3)-f(1))(f(3)+f(1))}{2} = 1$, yani $f(3) + f(1) = 2$.
3. İki denklemden: $f(3) = \dfrac32$, $f(1) = \dfrac12$.
4. Üçüncü integrale kısmi integrasyon: $u = x^2$, $dv = f'(x)\,dx$, $du = 2x\,dx$, $v = f(x)$:
   $$1 = \big[x^2 f(x)\big]_1^3 - 2\int_1^3 x f(x)\,dx = 9f(3) - f(1) - 2\int_1^3 x f(x)\,dx$$
5. $9\cdot\frac32 - \frac12 = 13$. Buradan $\displaystyle\int_1^3 x f(x)\,dx = \frac{13 - 1}{2} = 6$.

- $f(3)$ ve $f(1)$'i bir öğrenci $u = f(x)$ dönüşümüyle buldu; hoca bu yaklaşımı derste birlikte tamamladı.
- Hoca bu tip sorudan sınavda en fazla bir tane çıkabileceğini söyledi.

### Soru 4 (Cevap B)

$$\int_0^3 g(x)\,dx = 7,\quad \int_0^6 g(2x)\,dx = 5 \quad\Rightarrow\quad \int_1^2 x\,g(3x^2)\,dx = ?$$

1. $u = 3x^2$, $du = 6x\,dx$. Sınırlar: $x=1 \Rightarrow u=3$, $x=2 \Rightarrow u=12$.
   $$\int_1^2 x\,g(3x^2)\,dx = \frac16\int_3^{12} g(u)\,du$$
2. $t = 2x$, $dx = \tfrac12 dt$. Sınırlar $0$ ve $12$:
   $$5 = \int_0^6 g(2x)\,dx = \frac12\int_0^{12} g(t)\,dt \Rightarrow \int_0^{12} g = 10$$
3. $\int_0^{12} g = \int_0^3 g + \int_3^{12} g$, yani $\int_3^{12} g = 10 - 7 = 3$.
4. Cevap: $\dfrac16 \cdot 3 = \dfrac12$.

- Hoca bu tip sorulara "5-6 yıldız" verdi; sınavda bekliyor.

### Soru 6 (Cevap B)

- Her $c, d > 0$ için $f(cd) = f(c) + f(d)$ ve $\displaystyle\lim_{x\to2}\frac{f(x)}{x-2} = 4$ ise $f'(8) = ?$
- Limitin var olması için pay da sıfıra gitmeli: $f(2) = 0$. O zaman limit L'Hôpital ile $f'(2) = 4$ verir.
- Özellikten: $f(x^3) = f(x) + f(x) + f(x) = 3f(x)$.
- Türev: $3x^2 f'(x^3) = 3 f'(x)$, yani $x^2 f'(x^3) = f'(x)$.
- $x = 2$: $4\,f'(8) = f'(2) = 4 \Rightarrow f'(8) = 1$.

### Soru 7 (Cevap A)

$$\int_{-2}^{2}\left(x^3\cos^3 x - x - x^5\sin^2 x + x^2\sin x + 3\right)dx = ?$$

- $x^3\cos^3 x$ (tek × çift), $x$ (tek), $x^5\sin^2 x$ (tek × çift), $x^2 \sin x$ (çift × tek) terimlerinin hepsi tek fonksiyon. Simetrik aralıkta integralleri sıfır.
- Geriye yalnız $\int_{-2}^{2} 3\,dx = 12$ kalır.
- Hoca önce 3'ü görmeden "cevap sıfır" dedi, sonra düzeltti: cevap 12.

### Soru 9 (Cevap A): Doğrusallaştırma

$$h(x) = 1 + x + (x-2)\int_{-2}^{x}\left[(\sin t)^{2019}(\cos t)^{2020} - 1\right]dt, \quad a = 2$$

- $h(2) = 1 + 2 + 0 = 3$.
- Çarpım kuralı ve temel teorem: $h'(x) = 1 + \displaystyle\int_{-2}^{x}[\dots]\,dt + (x-2)\left[(\sin x)^{2019}(\cos x)^{2020} - 1\right]$.
- $x = 2$: son terim sıfır. $(\sin t)^{2019}(\cos t)^{2020}$ tek fonksiyon olduğundan $[-2,2]$ integrali sıfır. Geriye $\int_{-2}^{2}(-1)\,dt = -4$ kalır.
- $h'(2) = 1 - 4 = -3$.
- $L(x) = 3 - 3(x-2) = -3x + 9$.

### Soru 11: Riemann toplamı

$$\lim_{n\to\infty}\sum_{k=1}^{n}\frac{n}{n^2+k^2} = ?$$

1. Payda $n^2$ parantezine alınır: $\dfrac{n}{n^2\left(1 + \left(\frac{k}{n}\right)^2\right)} = \dfrac{1}{1+\left(\frac kn\right)^2}\cdot\dfrac1n$.
2. $\Delta x = \dfrac1n$ seçilir. En basit seçim $a = 0$, $b = 1$; o zaman $x_k = \dfrac kn$. ($a=1$, $b=2$ de seçilebilir ama işi zorlaştırır.)
3. $f(x_k) = \dfrac{1}{1+x_k^2}$, yani $f(x) = \dfrac{1}{1+x^2}$.
4. $$\int_0^1 \frac{dx}{1+x^2} = \arctan 1 - \arctan 0 = \frac{\pi}{4}$$
- Hoca bu tip sorunun 2. vizede ya da finalde gelme olasılığını "çok yüksek" gördü.

### Kapalı türev ve temel teorem

- $x = \displaystyle\int_0^{y}\frac{dt}{\sqrt{1+4t^2}}$ biçiminde kapalı tanımlı $y$ için $\dfrac{d^2y}{dx^2}$ soruluyor.
- Her iki tarafın $x$'e göre türevi: $1 = \dfrac{1}{\sqrt{1+4y^2}}\cdot y'$, yani $y' = \sqrt{1+4y^2}$.
- Tekrar türev: $y'' = \dfrac{8y\,y'}{2\sqrt{1+4y^2}} = 4y$.

### $y = \dfrac{\ln x}{x}$ fonksiyonunun bükülme noktası

- $y' = \dfrac{1 - \ln x}{x^2}$.
- $y'' = \dfrac{-\frac1x\cdot x^2 - (1-\ln x)\cdot 2x}{x^4} = \dfrac{2\ln x - 3}{x^3}$.
- Tanım kümesi $x > 0$, bu yüzden $x^3 > 0$.
- $2\ln x = 3 \Rightarrow x = e^{3/2}$. Bu noktanın solunda $y'' < 0$, sağında $y'' > 0$.
- Bükülme noktası $x = e^{3/2}$.

### Rasyonel fonksiyonların integrali (final konusu)

**Tanım:** $P(x)$ ve $Q(x)$ polinom ise $\dfrac{P(x)}{Q(x)}$ rasyonel fonksiyondur. Örnekler: $\dfrac1x$, $\dfrac{1}{x^2+1}$, $\dfrac{x+1}{x^2+1}$, $\dfrac{x}{(x-1)^2}$.

**Temel kesirlerin integralleri:**
- $\displaystyle\int\frac{dx}{x+a} = \ln|x+a| + C$ ($u = x+a$).
- $\displaystyle\int\frac{dx}{x^2+a^2}$: $a^2$ parantezine alınıp $u = \frac xa$ dönüşümü yapılır, sonuç $\dfrac1a\arctan\dfrac xa + C$. Hoca formülü ezberletmediğini, dönüşümle bulunması gerektiğini vurguladı.
- $\displaystyle\int\frac{x\,dx}{x^2+b} = \frac12\ln|x^2+b| + C$ ($u = x^2+b$).

**Örnek 1:** $\displaystyle\int\frac{dx}{x^2-1}$
- $x^2 - 1 = (x-1)(x+1)$: iki katsız reel kök.
- $\dfrac{1}{(x-1)(x+1)} = \dfrac{A}{x-1} + \dfrac{B}{x+1}$.
- Payda eşitlenir: $1 = A(x+1) + B(x-1) = (A+B)x + (A-B)$. Katsayı eşitliğinden $A + B = 0$, $A - B = 1$. Çözüm: $A = \tfrac12$, $B = -\tfrac12$.
- **Kısa yol (katsız reel kök için):** $A$'yı bulmak için $(x-1)$ çarpanını kapatıp kalan ifadeye $x = 1$ yazılır: $A = \frac{1}{1+1} = \frac12$. $B$ için $(x+1)$ kapatılıp $x=-1$ yazılır: $B = \frac{1}{-1-1} = -\frac12$. Bu yöntem yalnız katsız reel köklerde çalışır.
- $$\int\frac{dx}{x^2-1} = \frac12\ln|x-1| - \frac12\ln|x+1| + C = \frac12\ln\left|\frac{x-1}{x+1}\right| + C$$

**Örnek 2:** $\displaystyle\int\frac{x\,dx}{(x-1)^2}$
- $x = 1$ katlı reel kök: $\dfrac{x}{(x-1)^2} = \dfrac{A}{x-1} + \dfrac{B}{(x-1)^2}$.
- $x = A(x-1) + B$: $A = 1$, $B - A = 0 \Rightarrow B = 1$.
- Katlı kökte kısa yol kullanılamaz; katsayılar denklem sistemiyle bulunur.
- $$\int\frac{x\,dx}{(x-1)^2} = \ln|x-1| - \frac{1}{x-1} + C$$
- İkinci yöntem: $u = x-1$, $x = u+1$ dönüşümüyle $\int\frac{u+1}{u^2}\,du$. Hoca bunun da doğru olduğunu ama burada genel yöntemi gösterdiğini söyledi.

**Basit kesir gerekmeyen örnekler:** $\displaystyle\int\frac{x\,dx}{x^2-1} = \frac12\ln|x^2-1| + C$ ve $\displaystyle\int\frac{x\,dx}{x^2+1}$ doğrudan $u$ dönüşümüyle çözülür.

**Örnek 3:** $\displaystyle\int\frac{dx}{x(x^2+1)}$
- $x$: katsız reel kök, $\dfrac Ax$. $x^2+1$: reel kökü yok, ikinci dereceden, $\dfrac{Bx+C}{x^2+1}$.
- Kısa yolla $A = \dfrac{1}{0+1} = 1$.
- $1 = A(x^2+1) + (Bx+C)x$: $x^2$ katsayısı $A + B = 0 \Rightarrow B = -1$; $x$ katsayısı $C = 0$.
- $$\int\frac{dx}{x(x^2+1)} = \ln|x| - \frac12\ln(x^2+1) + C$$
- Hoca önce $B$'yi $+1$ yazdı, sonra $-1$ olarak düzeltti.

**Katlı karmaşık kök örneği:** $\dfrac{\dots}{x^3(x^2+1)^2}$
- $x^3$ için üç katman: $\dfrac Ax + \dfrac B{x^2} + \dfrac C{x^3}$.
- $(x^2+1)^2$ için iki katman: $\dfrac{Dx+E}{x^2+1} + \dfrac{Fx+G}{(x^2+1)^2}$.
- Sınavda katsayıları bulmanız istenmez. "Bu integral aşağıdakilerden hangisine özdeştir?" gibi bir soru gelir.

**Final sorusu örneği (Cevap A):** Rasyonel fonksiyon önce sadeleştiriliyor: $x$ parantezine alınıp $(x-1)$ çarpanları sadeleşince payda $(x^2+1)(x-1)$ kalıyor. Bu durumda yazılacak biçim:
$$\frac{A}{x-1} + \frac{Bx+C}{x^2+1}$$

**Son örnek:** $\dfrac{\dots}{(x+1)^2(x^4+1)}$
- $(x+1)^2$: $\dfrac{A}{x+1} + \dfrac{B}{(x+1)^2}$.
- $x^4+1$ (karmaşık kökler, katsız): $\dfrac{Cx^3+Dx^2+Ex+F}{x^4+1}$.
- $(x^4+1)^2$ olsaydı ikinci katman da yazılırdı: $\dfrac{Gx^3+Hx^2+Ix+J}{(x^4+1)^2}$.

### Ders sonrası notlar

- **Soru 7 ($\ln|x^2-1|$):** Hocanın tespiti doğru. $f'' < 0$ olduğundan grafik tanım kümesinde aşağı içbükey. Anahtardaki B ("yukarı içbükey") yazıldığı hâliyle yanlış. Ayrıca $x=0$'da yerel maksimum olduğundan A da yanlış. Taslak sınavda B şıkkı büyük olasılıkla "concave down" olacaktı.
- **Soru 4'ün sınırları:** Hoca çözerken önce "$x = 0$ ve $x = 1$" dedi. Sorudaki doğru sınırlar $1$ ve $2$, dönüşümde $u$ sınırları $3$ ve $12$. Hocanın sonucu ($\tfrac12$) doğru sınırlarla çıkıyor.
- **Soru 9:** Hoca altyazıda $h'(2)$ hesabını karışık anlattı ("8-3"). Doğru değer $h'(2) = 1 + 0 - 4 = -3$; cevap A ile tutarlı.
- **Tek-çift çarpımı:** Hoca bir an "iki tek fonksiyonun çarpımı... tek" dedi, hemen düzeltti. Doğrusu: tek × tek = çift, tek × çift = tek.
- Altyazının bazı yerleri döngüye girmiş ya da bozuk (ör. 02:14:52, 02:21:29 civarı). Bu kısımlar altyazıda anlaşılmıyor; içerik tahta anlatımından ve bağlamdan kuruldu.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
