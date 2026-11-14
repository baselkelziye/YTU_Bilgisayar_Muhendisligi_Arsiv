# Ders 21 Çalışma Özeti

## Genel Konular

- İkinci vize duyurusu: tarih, saat, soru sayısı ve konuların ağırlığı.
- İndirgeme formülleri (reduction formulas):
  - $\int x^n e^x\,dx$
  - $\int \sin^n x\,dx$ ve $\int \cos^n x\,dx$; $\left[0, \tfrac{\pi}{2}\right]$ üzerindeki belirli integraller (Wallis formülleri)
  - $\int \tan^n x\,dx$ ve $\int \sec^n x\,dx$
  - $\int \sin^m x\cos^n x\,dx$ ve $\int e^{ax}\sin^n x\,dx$ (yalnız anılıyor)
- Geçmiş yıl uygulama soruları:
  - Ortalama değer teoremiyle $f(5)$'in alabileceği değerler ve eşitsizlik ispatı.
  - Yerel ekstremum, büküm noktası, Rolle ve ortalama değer teoremi.
  - Zincir kuralı.
  - Asimptotlar, mutlak ekstremum, grafik yorumlama.
  - Temel teorem 1. kısım, ortalama değer, logaritmik türev.

## Hocanın Özellikle Vurguladığı Kısımlar

- **İkinci vize: 25 Aralık 2020 Cuma, saat 16.00.**
  - 20 soru, test (çoktan seçmeli). Süre belli değil; hoca en az 80 dakika olacağını tahmin ediyor.
  - Soruların çoğu birinci vizeden sonraki konulardan gelecek.
- Hocanın tableti/kalemi bozuldu, internet de kesik kesik. Ders yaklaşık 55. dakikada başlıyor. Hoca bu yüzden başka hocaların ders notları üzerinden anlatıyor ve fareyle işaretliyor. Bunu tercih etmediğini söylüyor.
- **Tahminler (hocanın öngörüsü; soruları kendisi hazırlamıyor):**
  - **Temel teorem 1. kısım:** Gelme ihtimali %99,9. En az 3-4 soru bununla ilgili olabilir.
  - **Asimptotlar:** Birinci vizede asimptot sorusu yoktu. %90 ihtimalle en az 1-2 soru gelir. Asimptotlara iyi çalışın.
  - **İntegraller için ortalama değer teoremi:** Önümüzdeki vizede %60, finalde %40. İkisinden birinde neredeyse kesin.
  - **İndirgeme formülleri:** En az bir soru (vize veya final), en fazla 2. "İndirgeme formülü nedir?" diye sorulmaz. Formülün elde edilişini ve uygulamasını öğrenin; yoruma dayalı soru gelir.
  - **Ortalama değer teoremiyle eşitsizlik:** En fazla %10, belki daha az.
  - **Riemann toplamı formülünü bulma** tarzı sorular gelebilir; şıklar sadeleştirilmeden bırakılır.
- Sınav soruları hesap makinesi/araçlarla çözülebilecek tarzda gelmeyecek. Bunun yerine **yorum soruları** gelecek. Ders notlarındaki kuralları ve yorumları çok iyi bilin.
- Hoca ikinci vizenin zor olacağını, işin mantığını anlamayanların kötü performans göstereceğini söylüyor. Derse katılım düşük olduğu için endişeli.
- Videoyu tekrar izlerken önünüze kâğıt kalem alıp soruları kendiniz çözün. Çözebiliyorsanız konuyu öğrenmişsinizdir.
- 5 yıldızlı ve 3 yıldızlı sorulara ayrıca önem verin. 5 yıldızlı sorular birinci vize konularıyla harmanlanmış.
- İndirgeme formüllerinin dosyası ders sonrasında paylaşılacak. Benzer sorular hocanın AVESİS sayfasında da var.
- Ders 12.00'de bitiyor; bugün ve yarın 10 dakika uzatılabilir. Gelecek hafta soru çözümüne devam edilecek, belki final konularından biraz konu işlenecek.

## Kısa Tekrar Notları

- $I_n = \displaystyle\int x^n e^x\,dx = x^n e^x - n\,I_{n-1}$.
- $I_n = \displaystyle\int \sin^n x\,dx = -\frac{\sin^{n-1}x\cos x}{n} + \frac{n-1}{n}I_{n-2}$ ($n \ge 2$).
- $I_n = \displaystyle\int \cos^n x\,dx = \frac{\cos^{n-1}x\sin x}{n} + \frac{n-1}{n}I_{n-2}$ ($n \ge 2$).
- Wallis formülleri ($\sin$ ve $\cos$ için aynı):
  - $n$ tek, $n \ge 3$: $\displaystyle\int_0^{\pi/2}\sin^n x\,dx = \frac{2}{3}\cdot\frac{4}{5}\cdots\frac{n-1}{n}$.
  - $n$ çift, $n \ge 2$: $\displaystyle\int_0^{\pi/2}\sin^n x\,dx = \frac{1}{2}\cdot\frac{3}{4}\cdots\frac{n-1}{n}\cdot\frac{\pi}{2}$.
- $I_n = \displaystyle\int \tan^n x\,dx = \frac{\tan^{n-1}x}{n-1} - I_{n-2}$ ($n \ge 2$).
- $I_n = \displaystyle\int \sec^n x\,dx = \frac{\sec^{n-2}x\tan x}{n-1} + \frac{n-2}{n-1}I_{n-2}$ ($n \ge 2$).
- Ortalama değer teoremi: $f'(c) = \dfrac{f(b) - f(a)}{b - a}$ (ortalama değişim oranı).
- Rolle teoremi: $[a,b]$'de sürekli, $(a,b)$'de türevlenebilir ve $f(a) = f(b)$ ise $f'(c) = 0$ olan bir $c \in (a,b)$ vardır.
- Ortalama değer (integral): $f_{ort} = \dfrac{1}{b-a}\displaystyle\int_a^b f(x)\,dx$. Ortalama değişim oranıyla karıştırmayın.
- Kritik nokta: Tanım kümesinde olup türevi sıfır veya tanımsız yapan nokta.
- Düşey asimptot: Fonksiyonu tanımsız yapan noktaya sağdan veya soldan yaklaşırken $f(x) \to \pm\infty$ olmalı.
- Yatay asimptot: $x \to +\infty$ ve $x \to -\infty$ ayrı ayrı incelenir; birinde olup diğerinde olmayabilir.

## Detaylı Açıklamalar

### İndirgeme formüllerinin mantığı

- Neredeyse bütün indirgeme formülleri kısmi integrasyonla elde edilir.
- $I_n$, bir önceki ($I_{n-1}$ veya $I_{n-2}$) integrale bağlıdır. Bu bir ardışıklık (recursive) ilişkisidir.
- Formül tekrar tekrar uygulanarak $I_0$ veya $I_1$'e kadar inilir.
- Hoca: "İntegraller için indirgeme formülleri listesi" diye ararsanız hepsini bulursunuz. İşinize yarayanı seçersiniz.

### $\int x^n e^x\,dx$

- $u = x^n$, $dv = e^x\,dx$. $du = n x^{n-1}\,dx$, $v = e^x$.
- $I_n = x^n e^x - n\displaystyle\int x^{n-1}e^x\,dx = x^n e^x - n\,I_{n-1}$.
- Örnek: $\displaystyle\int x^4 e^x\,dx = I_4 = x^4 e^x - 4I_3$. $I_3$ yerine tekrar formül yazılır; $I_0 = \displaystyle\int e^x\,dx = e^x$'e kadar inilir.

### $\int \sin^n x\,dx$ (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor)

- $\sin^n x = \sin^{n-1}x\cdot\sin x$. $u = \sin^{n-1}x$, $dv = \sin x\,dx$.
- $du = (n-1)\sin^{n-2}x\cos x\,dx$, $v = -\cos x$.
- $I_n = -\sin^{n-1}x\cos x + (n-1)\displaystyle\int \sin^{n-2}x\cos^2 x\,dx$.
- $\cos^2 x = 1 - \sin^2 x$ yazılır: $I_n = -\sin^{n-1}x\cos x + (n-1)\left[I_{n-2} - I_n\right]$.
- $I_n$'ler bir tarafa toplanır: $n I_n = -\sin^{n-1}x\cos x + (n-1)I_{n-2}$.
- $n \ge 2$ olmalı; $I_{-1}$ diye bir şey yok, $I_0$ olabilir.

### Örnek 1: $\displaystyle\int_0^{\pi/2}\sin^5 x\,dx$

- Sınırlar yerine yazılınca $-\dfrac{\sin^{n-1}x\cos x}{n}$ terimi sıfır olur.
- $\displaystyle\int_0^{\pi/2}\sin^5 x\,dx = \frac{4}{5}\int_0^{\pi/2}\sin^3 x\,dx = \frac{4}{5}\cdot\frac{2}{3}\int_0^{\pi/2}\sin x\,dx = \frac{4}{5}\cdot\frac{2}{3}\cdot 1 = \frac{8}{15}$.
- Genel kural: Çarpanlar belli bir düzenle gelir. Pay ve paydayı birer artırarak yazarsınız; $n$ çiftse en sonda $\dfrac{\pi}{2}$ ile çarparsınız (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor).

### $\int \cos^n x\,dx$

- $\cos^n x = \cos^{n-1}x\cdot\cos x$. $u = \cos^{n-1}x$, $dv = \cos x\,dx$.
- $\sin^2 x = 1 - \cos^2 x$ yazılır ve aynı yolla: $I_n = \dfrac{\cos^{n-1}x\sin x}{n} + \dfrac{n-1}{n}I_{n-2}$.
- $\left[0, \tfrac{\pi}{2}\right]$ üzerinde $\sin^n$ ile aynı değeri verir.

### $\int \tan^n x\,dx$

- $\tan^n x = \tan^{n-2}x\cdot\tan^2 x$. $\tan x$'in türevinde $\sec^2 x$ olduğu için bu ayrıştırma seçilir.
- $\tan^2 x = \sec^2 x - 1$: $I_n = \displaystyle\int \tan^{n-2}x\sec^2 x\,dx - I_{n-2}$.
- İlk integralde $u = \tan x$, $du = \sec^2 x\,dx$: $\dfrac{\tan^{n-1}x}{n-1}$.
- $I_n = \dfrac{\tan^{n-1}x}{n-1} - I_{n-2}$.

### Örnek 2: $\displaystyle\int_0^{\pi/4}\tan^5 x\,dx$ (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor)

- $= \left[\dfrac{\tan^4 x}{4}\right]_0^{\pi/4} - \displaystyle\int_0^{\pi/4}\tan^3 x\,dx = \frac{1}{4} - \left(\left[\frac{\tan^2 x}{2}\right]_0^{\pi/4} - \int_0^{\pi/4}\tan x\,dx\right)$.
- $= \dfrac{1}{4} - \dfrac{1}{2} + \displaystyle\int_0^{\pi/4}\frac{\sin x}{\cos x}\,dx = -\frac{1}{4} + \left[-\ln(\cos x)\right]_0^{\pi/4}$.
- $= -\dfrac{1}{4} - \ln\dfrac{1}{\sqrt{2}} + \ln 1 = -\dfrac{1}{4} + \ln\sqrt{2} = -\dfrac{1}{4} + \dfrac{1}{2}\ln 2$.

### $\int \sec^n x\,dx$ ve Örnek 3: $\displaystyle\int_0^{\pi/4}\sec^6 x\,dx$

- $I_n = \dfrac{\sec^{n-2}x\tan x}{n-1} + \dfrac{n-2}{n-1}I_{n-2}$.
- Örnek (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor):
  - $\displaystyle\int_0^{\pi/4}\sec^6 x\,dx = \left[\frac{\sec^4 x\tan x}{5}\right]_0^{\pi/4} + \frac{4}{5}\int_0^{\pi/4}\sec^4 x\,dx$.
  - $= \dfrac{4}{5} + \dfrac{4}{5}\left(\left[\dfrac{\sec^2 x\tan x}{3}\right]_0^{\pi/4} + \dfrac{2}{3}\displaystyle\int_0^{\pi/4}\sec^2 x\,dx\right) = \frac{4}{5} + \frac{8}{15} + \frac{8}{15}\left[\tan x\right]_0^{\pi/4}$.
  - $= \dfrac{4}{5} + \dfrac{8}{15} + \dfrac{8}{15} = \dfrac{28}{15}$.
- Hoca $\sec^n$ için formülün ispatını kalemi olmadığı için yapamıyor, ödev olarak bırakıyor.

### Diğer indirgeme formülleri

- $\displaystyle\int \sin^m x\cos^n x\,dx$ için iki tamsayıya bağlı $I_{m,n}$ formülü var. $m \ne -1$ için yerine koyma yöntemiyle bir özel durum elde edilir. Hoca bunu ayrıntıya girmeden geçiyor; örnek olarak $m = 4$, $n = 6$ için $\left[0, \tfrac{\pi}{2}\right]$'de belirli integral gösteriliyor.
- $\displaystyle\int e^{ax}\sin^n x\,dx$ ($a$ reel sabit) için de indirgeme formülü var. Anlatılmadı.

### Geçmiş yıl sorusu 1: $f(5)$'in alabileceği değerler

- $f$, $[0,5]$'te sürekli, $(0,5)$'te türevlenebilir. $f(0) = 2$ ve $1 \le f'(x) \le 3$.
- Ortalama değer teoremi: $f'(c) = \dfrac{f(5) - f(0)}{5 - 0}$.
- $1 \le \dfrac{f(5) - 2}{5} \le 3$, yani $7 \le f(5) \le 17$.
- Ortalama değer teoremi: Grafiğin uç noktalarını birleştiren kirişe (secant line) paralel bir teğet bulunabilir.

### Geçmiş yıl sorusu 2: Eşitsizlik ispatı

- Amaç: $\sin 2x$ ile ilgili bir eşitsizliğin her $a, b$ için doğru olduğunu göstermek.
- $f(x) = \sin 2x$ her kapalı aralıkta sürekli, her açık aralıkta türevlenebilir.
- Ortalama değer teoremi: $2\cos 2c = \dfrac{\sin 2b - \sin 2a}{b - a}$.
- $|\cos 2c| \le 1$ olduğu için $|\sin 2b - \sin 2a| \le 2|b - a|$.
- Matematikteki birçok eşitsizlik ortalama değer teoremiyle gösterilebilir.
- Bir öğrenci sınavda böyle bir sorunun nasıl sorulacağını soruyor. Hoca: Test sınavının ruhuna uygun hazırlanır. Bir eşitsizliğin doğru olup olmadığı sorulursa ortalama değer teoremiyle hemen gösterebilirsiniz.

### Geçmiş yıl sorusu 3: Yerel ekstremum ve büküm noktaları

- Birinci türevin işaret tablosu yerel ekstremumları, ikinci türevin işaret tablosu konkavlığı verir.
- Bu soruda: $(-\infty, -\sqrt{3})$'te artan ve aşağı konkav, $(-\sqrt{3}, -1)$'de azalan ve aşağı konkav, $(-1, 0)$'da azalan ve yukarı konkav, $(0, 1)$'de artan ve yukarı konkav, $(1, \sqrt{3})$'te artan ve aşağı konkav.
- $x = -1$ ve $x = 1$ büküm noktaları: ikinci türev burada işaret değiştiriyor.
- $x = 0$'da yerel minimum var. Fonksiyonun kendisi altyazıda geçmiyor.

### Geçmiş yıl sorusu 4: Rolle teoremi (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor)

- Rolle için üç koşul: $[a,b]$'de süreklilik, $(a,b)$'de türevlenebilirlik, $f(a) = f(b)$.
- Fonksiyon $x = -2$ dışında türevlenebilir; bu nokta $[0,1]$'in dışında.
- $f'(c) = \dfrac{c^2 + 4c - 2}{(c+2)^2} = 0$, yani $c^2 + 4c - 2 = 0$.
- $c_{1,2} = -2 \mp \sqrt{6}$. Yalnız $c = -2 + \sqrt{6} \in (0,1)$ kabul edilir.
- Sorunun fonksiyonu altyazıda okunmuyor.

### Geçmiş yıl sorusu 5: Zincir kuralı (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor)

- $f$ ve $g$ türevlenebilir, $f'(2) = 3$, $g(1) = 2$, $g'(1) = 1$. $h(x) = f(g(x^2))$ ise $h'(1)$ nedir?
- $h'(x) = f'(g(x^2))\cdot g'(x^2)\cdot 2x$.
- $h'(1) = f'(g(1))\cdot g'(1)\cdot 2 = f'(2)\cdot 1\cdot 2 = 6$.
- Ardından ortalama değer teoremiyle bir eşitsizliğin doğruluğunu gösterme sorusu ödev olarak bırakıldı.

### Geçmiş yıl sorusu 6: $f(x) = x\sqrt{1-x}$, $[0,1]$, ortalama değer teoremi

- $f$, $[0,1]$'de sürekli, $(0,1)$'de türevlenebilir.
- $f(1) - f(0) = 0$, yani $f'(c) = 0$ aranıyor.
- $f'(x) = \sqrt{1-x} - \dfrac{x}{2\sqrt{1-x}} = \dfrac{2 - 3x}{2\sqrt{1-x}}$.
- $c = \dfrac{2}{3} \in (0,1)$.

### Asimptot soruları

- **Düşey asimptot:** Fonksiyonun kuralını tanımsız yapan noktalarda aranır. Her tanımsız nokta düşey asimptot değildir.
  - Bir soruda $x \to 0$ iken eşlenik yöntemiyle limit sonlu çıkıyor. Bu yüzden $x = 0$ düşey asimptot değil.
  - Örnek: $y = \dfrac{1}{x}$'te $x \to 0$ iken sağdan $+\infty$, soldan $-\infty$; $x = 0$ düşey asimptottur.
  - Limit sonlu bir değere gidiyorsa grafikte yalnız bir "delik" vardır, asimptot yoktur.
- **Yatay asimptot:** $x \to +\infty$ ve $x \to -\infty$ ayrı ayrı incelenir.
  - Aynı soruda $x \to +\infty$ iken $f(x) \to \infty$: yatay asimptot yok.
  - $x \to -\infty$ iken $\sqrt{x^2} = |x| = -x$ alınır ve limit $\dfrac{1}{2}$ çıkar: $y = \dfrac{1}{2}$ yatay asimptot.
- Başka bir soruda $x \to 0$ iken limit $1$ (sonlu), düşey asimptot yok. $x \to \pm\infty$ iken sınırlı bir terim sıkıştırma teoremiyle sıfıra gider; $y = 1$ yatay asimptottur.
- Bir öğrenci $x = 1$'in düşey asimptot olup olmadığını soruyor. Hoca: $x = 1$'de bir tanımsızlık yok. Düşey asimptot yalnız fonksiyonu tanımsız yapan noktalarda aranır.

### Geçmiş yıl sorusu 7: Mutlak ekstremum

- Kökün içi $4 - x^2 \ge 0$ olmalı, tanım kümesi $[-2, 2]$. $\pm 2$ uç noktalardır.
- Türevin kökleri $\pm\sqrt{2}$, tanım kümesinde oldukları için kritik noktalardır.
- $x = \pm 2$'de türev tanımsız, ama bu noktalar tanım kümesinde. Bu yüzden onlar da kritik noktadır.
- Değerler: $f(\pm 2) = 0$, $f(\sqrt{2}) = 2$ (mutlak maksimum), $f(-\sqrt{2}) = -2$ (mutlak minimum).
- Bu değerler $f(x) = x\sqrt{4 - x^2}$ ile uyumlu; fonksiyonun kendisi altyazıda geçmiyor.
- Benzer bir soruda türevin kökleri $x = 0$ ve $x = 4$; $x = 5$ uç nokta. $x = 0$'da yerel minimum, $x = 4$'te yerel maksimum, $x = 5$'te minimum değer.

### Grafik yorumlama (eğri çizimi)

- Test sınavında grafik çizdirilmez, ama grafiği yorumlamanız istenebilir. Eğri çizimi klasik sınavın ruhuna uygundur.
- Örnek: $x = 2$ düşey asimptot. Asimptotun solunda grafik aşağı konkav olmalı. Yukarı konkav olsaydı $x = 2$ doğrusunu keserdi; bu, asimptot olmasıyla çelişirdi. Sağında yukarı konkav olmalı.
- Örnek: $x = -1$ düşey asimptot; solunda grafik yukarı konkav.
- Eğik asimptot $y = x - 1$ ise $x$'ler yeterince büyükken grafik aşağı konkav olur.
- $y = 1$ yatay asimptotsa, $x \to -\infty$ tarafında grafik yukarı konkav olmak zorunda (soruya göre).
- Eğik asimptot polinom bölmesiyle bulunur. Genel yöntem önceki derslerde anlatıldı.

### Geçmiş yıl sorusu 8: $f(x) = \displaystyle\int_0^{x}\frac{t - t^2}{1 + t^4}\,dt$, max/min (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor)

- Temel teorem 1. kısım: $f'(x) = \dfrac{x - x^2}{1 + x^4}$.
- $f'(x) = 0$: $x = 0$ ve $x = 1$.
- İşaret tablosu: $x < 0$'da $-$, $0 < x < 1$'de $+$, $x > 1$'de $-$.
- $x = 0$ yerel minimum, $x = 1$ yerel maksimum. $f(0) = \displaystyle\int_0^0 = 0$.

### Geçmiş yıl sorusu 9: $f(x) = \cos x$, $[0, \pi]$, ortalama değer

- $f_{ort} = \dfrac{1}{\pi}\displaystyle\int_0^{\pi}\cos x\,dx = 0$.
- Ortalama değer teoremi: $f(c) = \cos c = 0$, $c \in [0, \pi]$ için $c = \dfrac{\pi}{2}$.
- $\cos c = 0$'ı sağlayan çok $c$ var, ama aralıkta olanı seçilir.
- Bu soruyu anlamak için ortalama değer ve integraller için ortalama değer teoreminin tanımlarını bilmek gerekir.

### Geçmiş yıl sorusu 10: $F'(1)$

- Sınırları $x$'e bağlı bir integralle verilen $F$'nin $x = 1$'deki türevi isteniyor.
- Genelleştirilmiş temel teorem: Üst sınır integranda yerine yazılır, türeviyle çarpılır; alt sınır için aynısı yapılıp çıkarılır. Alt sınır sabitse türevi sıfırdır.
- Sonuç: $F'(1) = 2$. Hoca bu soruyu herkesin en fazla 2 dakikada çözmesi gerektiğini söylüyor.

### Geçmiş yıl sorusu 11: $f(x) = \displaystyle\int_0^{x^2 - 2x}\frac{dt}{1+t^2}$, yerel max/min (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor)

- $f'(x) = \dfrac{1}{1 + (x^2 - 2x)^2}\cdot(2x - 2)$.
- $f'(x) = 0$: $x = 1$.
- $x < 1$'de $f' < 0$, $x > 1$'de $f' > 0$: $x = 1$ yerel minimum noktası. Yerel maksimum yok.
- Minimum değer: $f(1) = \displaystyle\int_0^{-1}\frac{dt}{1+t^2} = \arctan(-1) = -\frac{\pi}{4}$.
- Üst sınırın işareti üzerine öğrenciyle kısa bir konuşma oluyor (öğrenci "artı bir değil mi" diye soruyor; altyazıda kimin hangi işareti önerdiği tam net değil). Doğru üst sınır $1 - 2 = -1$.
- Hoca bu soruya 5 yıldız veriyor.

### Geçmiş yıl sorusu 12: Logaritmik türev ve temel teorem

- $f(x) = (1 + \ln x)^x$. $g(x)$, alt sınırı $x$, üst sınırı $f(x)$ olan bir belirli integral.
- $f$ aşkın bir fonksiyondur: hem taban hem üs $x$'e bağlı. İki tarafın logaritması alınır:
  - $\ln f(x) = x\ln(1 + \ln x)$.
  - Türev: $\dfrac{f'(x)}{f(x)} = \ln(1 + \ln x) + x\cdot\dfrac{1/x}{1 + \ln x}$.
- $x = 1$: $f(1) = 1^0 = 1$ ve $f'(1) = 1\cdot(0 + 1) = 1$.
- $g'(x) = h(f(x))\,f'(x) - h(x)\cdot 1$ ($h$, integrand).
- $g'(1) = h(1)\cdot 1 - h(1) = 0$.
- Hoca bu tarz soruların hesap araçlarıyla çözülebildiği için büyük ihtimalle gelmeyeceğini, yerine yorum sorusu geleceğini söylüyor. Yine de 3 yıldız veriyor.

### Riemann toplamı

- Bir fonksiyon için $x_0$'dan $x_1$'e Riemann toplamı formülünü bulma sorusu gelebilir.
- Şıklar uzun uzun sadeleştirilmez, toplam formülü olarak bırakılır.
- Bir sonraki derste Riemann toplamlarıyla ilgili başka tip sorular çözülecek.

### Ders sonrası notlar

- **Örnek 2'de ders notunda hata var.** Notta son satır "$-\tfrac{1}{4}\ln\sqrt{2}$" gibi okunuyor, ikinci satırda da "$\tfrac{\tan^2 x}{x}$" yazıyor (büyük olasılıkla ekrandan; altyazıdan doğrulanmıyor). Doğrusu $\tfrac{\tan^2 x}{2}$ ve sonuç $-\dfrac{1}{4} + \ln\sqrt{2} = -\dfrac{1}{4} + \dfrac{1}{2}\ln 2 \approx 0{,}097$.
- **Soru 11'de ders notunda yazım hatası var.** Notta türevin paydası $1 + (x^2 - 2x)$ yazılmış. Doğrusu $1 + (x^2 - 2x)^2$. Sonuç değişmez.
- **Soru 2'nin tam eşitsizliği** altyazıda okunmuyor. Burada $|\sin 2b - \sin 2a| \le 2|b - a|$ olarak verildi; ispat yolu aynı.
- **Soru 1'in sonucu** altyazıda söylenmiyor. $7 \le f(5) \le 17$ verilen bilgilerden hesaplandı.
- Asimptot sorularının ve soru 3, 10'un fonksiyonları altyazıda geçmiyor; ekranda ders notu üzerinden gösterildi.
- 00:17:41 ile 00:55:21 arası ders yapılamadı (kalem ve internet sorunu). 01:58:11 ile 02:10:45 arası ara verilmiş.
- 01:46:44 civarında hoca yoklama alıyor. Bu kısım derse ait bilgi içermiyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
