# Ders 6 Çalışma Özeti

## Genel Konular

- Chebyshev eşitsizliği
  - Herhangi bir $Y$ rastgele değişkeni ve $d > 0$ sabiti için $\Pr(|Y - E[Y]| \ge d) \le \dfrac{\mathrm{Var}(Y)}{d^2}$.
  - Sol taraf her zaman $[0,1]$ aralığındadır; sağ taraf 1'den büyük olabilir. Bu yüzden eşitsizlik $\mathrm{Var}(Y) \ll d^2$ olduğunda işe yarar (ekrandan, 00:10:00).
  - İspat: $X = (Y - E[Y])^2 \ge 0$ negatif olmayan bir rastgele değişkendir; Markov eşitsizliği $X$'e uygulanır, $\Pr(|Y - E[Y]|^2 \ge c) \le \mathrm{Var}(Y)/c$ bulunur, sonra $c = d^2$ konur (ekrandan, 00:15:00).
  - $d = k\sigma_Y$ ($\sigma_Y = \sqrt{\mathrm{Var}(Y)}$, standart sapma) alınırsa $\Pr(|Y - E[Y]| \ge k\sigma_Y) \le \dfrac{1}{k^2}$ (ekrandan, 00:20:00).
  - Üç sigma kuralı: $k = 3$ için $\Pr(|Y - E[Y]| \le 3\sigma_Y) \ge 8/9$; yani değerlerin yaklaşık %88,9'u ortalamadan en fazla $3\sigma$ uzaktadır.
  - Dağılım (PMF/PDF/CDF) bilinmese bile yalnız varyans biliniyorsa Chebyshev, yalnız ortalama biliniyorsa Markov eşitsizliğiyle olasılığa sınır konabilir.
- Bernoulli dağılımı
  - Bernoulli denemesi: iki sonuçlu deney (ör. para atma); sonuçlar 0 (başarısızlık, yazı) ve 1 (başarı, tura) diye etiketlenir.
  - $X \sim \mathrm{Bernoulli}(p)$: $\Pr(X=1) = p$, $\Pr(X=0) = 1-p$, $0 \le p \le 1$.
  - $E[X] = p$, $E[X^2] = p$, $\mathrm{Var}(X) = p - p^2 = p(1-p) \ge 0$.
  - CDF birim basamak fonksiyonu $u(x)$ ile yazılır: $F_X(x) = \sum_{\forall x_k} \Pr(X = x_k)\,u(x - x_k) = (1-p)\,u(x) + p\,u(x-1)$ (ekrandan, 00:40:00).
- Binom dağılımı
  - $n$ bağımsız Bernoulli denemesindeki (sabit başarı olasılığı $p$) toplam başarı sayısı: $X \sim \mathrm{Binomial}(n,p)$.
  - PMF: $\Pr(X = k) = \binom{n}{k} p^k (1-p)^{n-k}$, $k = 0, 1, \dots, n$; $\binom{n}{k} = \dfrac{n!}{k!(n-k)!}$ (kombinasyon).
  - Türev hilesi: $k = \frac{\partial}{\partial a} a^k \big|_{a=1}$ yazılır, toplam ile türevin yeri değiştirilir, binom açılımı $(ap + 1 - p)^n$ kullanılır; sonuç $E[X] = np$ (ekrandan, 00:50:00).
  - $k^2 = \frac{\partial^2}{\partial a\,\partial b}(ab)^k \big|_{a=b=1}$ ile $E[X^2] = np(1-p) + n^2p^2$, buradan $\mathrm{Var}(X) = np(1-p)$ (ekrandan, 00:55:00).
- Geometrik dağılım
  - İlk başarı dahil, ilk başarıya kadar yapılan deneme sayısı: $X \sim \mathrm{Geom}(p)$.
  - PMF: $\Pr(X = k) = (1-p)^{k-1} p$, $k = 1, 2, 3, \dots$ (ilk $k-1$ deneme başarısız, $k$'ıncı başarılı) (ekrandan, 01:15:00).
  - $E[X] = 1/p$, $\mathrm{Var}(X) = (1-p)/p^2$; türetmede geometrik seri $\sum_{k=0}^{\infty} r^k = \frac{1}{1-r}$ ($|r| < 1$) kullanılır.
- Negatif binom dağılımı
  - $r$'inci başarı dahil, ona kadar yapılan toplam deneme sayısı: $X \sim \mathrm{NB}(r,p)$ (ekrandan, 01:20:00).
  - PMF: $\Pr(X = k) = \binom{k-1}{r-1} p^r (1-p)^{k-r}$, $k = r, r+1, \dots$
  - $E[X] = r/p$, $\mathrm{Var}(X) = r(1-p)/p^2$ (ekrandan, 01:25:00).
  - Geometrik dağılım $r = 1$ durumudur.
- Poisson dağılımı
  - Kısa bir sürede gerçekleşmesi çok olası olmayan nadir olaylarla ilgilidir: iş gelişleri, telefon çağrıları, e-posta mesajları, virüs saldırıları, trafik kazaları, ağ ve yazılım hataları, sel, deprem.
  - Sabit bir zaman aralığındaki nadir olay sayısı $X \sim \mathrm{Poisson}(\lambda)$; $\lambda$ ortalama olay sayısı (frekans) (ekrandan, 01:30:00).
  - PMF: $\Pr(X = k) = \dfrac{\lambda^k}{k!} e^{-\lambda}$, $k = 0, 1, 2, \dots$
  - $E[X] = \lambda$, $\mathrm{Var}(X) = \lambda$; türetmede $e^x = \sum_{k=0}^{\infty} \frac{x^k}{k!}$ serisi kullanılır (ekrandan, 01:40:00).
  - $X \sim \mathrm{Poisson}(\lambda)$, $Y \sim \mathrm{Poisson}(\nu)$ ise $Z = X + Y \sim \mathrm{Poisson}(\lambda + \nu)$.
  - Binom yaklaşımı: $n \to \infty$, $p \to 0$, $np = \lambda$ sabitken $\binom{n}{k}p^k(1-p)^{n-k} \to \frac{\lambda^k}{k!}e^{-\lambda}$.
- Hipergeometrik dağılım
  - Derste anlatılmadı; ders kitabında iyi açıklandığı, binom ve negatif binomdan sonra kolay anlaşılacağı söylendi.
- Çok terimli (multinomial) dağılım
  - $n$ bağımsız denemenin her biri $k$ sonuçtan birini verir; sonuç olasılıkları $p_1, \dots, p_k$, $p_1 + \dots + p_k = 1$.
  - $X_i$: $i$'inci sonucun görülme sayısı. Ortak PMF: $\Pr(X_1 = n_1 \cap \dots \cap X_k = n_k) = \dfrac{n!}{n_1!\,n_2!\cdots n_k!} p_1^{n_1} p_2^{n_2}\cdots p_k^{n_k}$, $n_1 + \dots + n_k = n$ (ekrandan, 01:50:00).
  - Her $X_i$ tek başına binomdur: $E[X_i] = np_i$, $\mathrm{Var}(X_i) = np_i(1-p_i)$.
  - $X_1, \dots, X_k$ bağımsız değildir.
- Sürekli rastgele değişkenler (Baron, Bölüm 4)
  - Sayılamayacak kadar sonsuz değer alabilen rastgele değişken süreklidir. CDF'i $F_X(x) = \Pr(X \le x)$ süreklidir, basamak biçiminde değildir.
  - Örnek: CDF'i üç basamaklı olan $Y$ yalnız $y_1, y_2, y_3$ değerlerini alır, kesiklidir; CDF'i düzgün artan $X$ süreklidir (ekrandan, 02:15:00). Belirleyici olan grafiğin biçimi değil, alınabilecek değer sayısıdır.
  - PDF, CDF'in türevidir: $f_X(x) = \frac{d}{dx}F_X(x)$. Türetme: $\int_x^{x+\Delta x} f_X(t)\,dt = \Pr(x < X \le x + \Delta x) = F_X(x+\Delta x) - F_X(x) \approx f_X(x)\Delta x$ (ekrandan, 02:20:00 ve 02:25:00).
  - Özellikler: $f_X(x) \ge 0$; $F_X(x) = \int_{-\infty}^{x} f_X(t)\,dt$ artan bir fonksiyondur; $\Pr(a < X \le b) = F_X(b) - F_X(a) = \int_a^b f_X(x)\,dx$; sürekli $X$ ve sabit $c$ için $\Pr(X = c) = 0$.
- Ortak ve marjinal yoğunluklar
  - Ortak CDF: $F_{X,Y}(x,y) = \Pr(X \le x \cap Y \le y)$; ortak PDF: $f_{X,Y}(x,y) = \frac{\partial^2}{\partial x\,\partial y}F_{X,Y}(x,y)$.
  - Marjinal yoğunluklar: $f_X(x) = \int_{-\infty}^{\infty} f_{X,Y}(x,y)\,dy$, $f_Y(y) = \int_{-\infty}^{\infty} f_{X,Y}(x,y)\,dx$.
  - Olasılık hesabı: $\Pr((X,Y) \in A) = \iint_A f_{X,Y}(x,y)\,dx\,dy$ (ekrandan, 02:35:00).
  - Marjinal CDF'ler: $F_X(x) = F_{X,Y}(x, \infty)$, $F_Y(y) = F_{X,Y}(\infty, y)$.
  - $F_{X,Y}(\infty,\infty) = 1$, $F_{X,Y}(-\infty,-\infty) = 0$, $F_{X,Y}(-\infty,\infty) = F_X(-\infty) = 0$, $F_{X,Y}(\infty,-\infty) = F_Y(-\infty) = 0$ (ekrandan, 02:40:00).
- Beklenen değer, varyans, kovaryans (sürekli)
  - $E[X] = \int_{-\infty}^{\infty} x f_X(x)\,dx$ (kesiklideki toplamın yerini integral alır).
  - $\mathrm{Var}(X) = E[(X - E[X])^2] = \int_{-\infty}^{\infty}(x - E[X])^2 f_X(x)\,dx = E[X^2] - E[X]^2$.
  - $\mathrm{Cov}(X,Y) = E[(X - E[X])(Y - E[Y])] = \iint xy\,f_{X,Y}(x,y)\,dx\,dy - E[X]E[Y]$ (ekrandan, 02:50:00).
  - Bağımsız $X, Y$ için $f_{X,Y}(x,y) = f_X(x)f_Y(y)$, bu durumda $\mathrm{Cov}(X,Y) = 0$: $X$ ve $Y$ ilişkisizdir (uncorrelated).
  - Korelasyon katsayısı $\rho_{X,Y} = \dfrac{\mathrm{Cov}(X,Y)}{\sqrt{\mathrm{Var}(X)\mathrm{Var}(Y)}}$, $-1 \le \rho_{X,Y} \le 1$; $\rho_{X,Y} = 0$ ise ilişkisizdir (ekrandan, 02:55:00).
  - İlişkisizlik bağımsızlık demek değildir; bağımsızlık ilişkisizlik demektir. Gauss (normal) dağılımlı değişkenlerde ilişkisizlik bağımsızlık anlamına gelir.
- Sürekli düzgün (uniform) dağılım
  - $[a,b]$ aralığından eşit olabilirlikle (equally likely) rastgele bir reel sayı seçme deneyi.
  - PDF: $f_X(x) = \frac{1}{b-a}$, $x \in [a,b]$; aksi hâlde 0. Toplam alan $\int_a^b \frac{1}{b-a}dx = 1$ (ekrandan, 03:10:00).
  - CDF: $x < a$ için 0; $a \le x \le b$ için $\frac{x-a}{b-a}$; $x > b$ için 1.
  - $E[X] = \frac{a+b}{2}$, $E[X^2] = \frac{a^2 + ab + b^2}{3}$, $\mathrm{Var}(X) = \frac{(b-a)^2}{12}$ (ekrandan, 03:15:00 ve 03:20:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Gauss değişkenlerde ilişkisizlik ile bağımsızlık
  - "Çok önemli not" diye kırmızıyla yazıldı: $X$ ve $Y$ Gauss ise ilişkisizlik bağımsızlık demektir. Biri bile Gauss değilse ilişkisizlikten bağımsızlık çıkarılamaz. Bağımsızlık ise her durumda ilişkisizlik demektir.
- Matematik temelleri
  - $e^x$'in Taylor serisi ve geometrik seri toplamları gibi temel açılımlar bilinmeden beklenen değer ve varyans türetilemez; hoca bu tür serilere hazır olunmasını istedi.
- Basamak fonksiyonuyla CDF
  - $\sum_{x_k \le x}\Pr(X = x_k) = \sum_{\forall x_k}\Pr(X = x_k)\,u(x - x_k)$ eşitliğinin iyi anlaşılmasını istedi.
- Chebyshev ve Markov'un kullanım yeri
  - Dağılım bilinmeden yalnız ortalama (Markov) ya da yalnız varyans (Chebyshev) ile olasılığa sınır konabilmesi.
- Çok soru çözmek
  - Ekrana yazdı: olasılık ve istatistik dersini öğrenmek için çok soru çözmek gerekir. Ders kitabının ilk dört bölümünün sonundaki soruların çözülmesini önerdi.

## Kısa Tekrar Notları

- Chebyshev: $\Pr(|Y - E[Y]| \ge k\sigma) \le 1/k^2$; $k=3$ için en az $8/9$ olasılıkla değer $3\sigma$ içindedir.
- Bernoulli: $E = p$, $\mathrm{Var} = p(1-p)$.
- Binom: $\binom{n}{k}p^k(1-p)^{n-k}$, $E = np$, $\mathrm{Var} = np(1-p)$.
- Geometrik: $(1-p)^{k-1}p$, $k \ge 1$, $E = 1/p$, $\mathrm{Var} = (1-p)/p^2$.
- Negatif binom: $\binom{k-1}{r-1}p^r(1-p)^{k-r}$, $k \ge r$, $E = r/p$, $\mathrm{Var} = r(1-p)/p^2$.
- Poisson: $\frac{\lambda^k}{k!}e^{-\lambda}$, $E = \mathrm{Var} = \lambda$; bağımsız Poisson'ların toplamı Poisson'dur; binomun $n\to\infty$, $p\to0$, $np=\lambda$ limitidir.
- Multinomial: $\frac{n!}{\prod n_i!}\prod p_i^{n_i}$; her $X_i$ binomdur, $X_i$'ler bağımsız değildir.
- Sürekli: $f_X = F_X'$, $\Pr(X = c) = 0$, $\Pr(a < X \le b) = \int_a^b f_X$.
- Marjinal PDF: ortak PDF'i istenmeyen değişkene göre integrallemek; marjinal CDF: o değişkene $\infty$ koymak.
- Bağımsız ⇒ ilişkisiz; ilişkisiz ⇏ bağımsız (Gauss hariç).
- Uniform$[a,b]$: $E = \frac{a+b}{2}$, $\mathrm{Var} = \frac{(b-a)^2}{12}$.

## Detaylı Açıklamalar

- **Chebyshev eşitsizliği ve ispatı.** Ders bir önceki derste başlanan Markov ve Chebyshev eşitsizlikleriyle açıldı. Chebyshev eşitsizliği, bir rastgele değişkenin ortalamasından en az $d$ kadar sapma olasılığını varyans cinsinden sınırlar. Hoca bunu bir PMF çizimi üzerinde gösterdi: $E[Y] - d$ ve $E[Y] + d$ noktalarının dışında kalan kütlelerin toplamı, sol taraftaki olasılıktır. İspatta $X = (Y - E[Y])^2$ tanımlanır; kare olduğu için $X$ negatif olmayan bir rastgele değişkendir ve Markov eşitsizliği uygulanabilir: $\Pr(X \ge c) \le E[X]/c = \mathrm{Var}(Y)/c$. Her iki taraf da pozitif olduğundan karekök alınınca olay değişmez: $\Pr(|Y - E[Y]|^2 \ge c) = \Pr(|Y - E[Y]| \ge \sqrt{c})$. $c = d^2$ konunca eşitsizlik elde edilir. $d = k\sigma_Y$ seçilince standart sapma cinsinden biçim, $k = 3$ seçilince üç sigma kuralı çıkar: $\Pr(|Y - E[Y]| \le 3\sigma_Y) \ge 1 - 1/9 = 8/9$.
- **Bernoulli dağılımının CDF'i.** CDF tanımdaki $x_k \le x$ koşullu toplam, bütün $x_k$'lar üzerinden alınan ve her terimi $u(x - x_k)$ ile çarpılan bir toplama dönüştürülür; $u(x)$, $x \ge 0$ için 1, $x < 0$ için 0'dır. Bernoulli için $x_0 = 0$, $x_1 = 1$ olduğundan $F_X(x) = (1-p)u(x) + p\,u(x-1)$ bulunur. Grafik $x < 0$ için 0, $0 \le x < 1$ için $1-p$, $x \ge 1$ için 1 olan bir basamak fonksiyonudur; $x = 1$'deki sıçrama $p$ kadardır.
- **Binom momentleri için türev hilesi.** $E[X] = \sum_k k\binom{n}{k}p^k(1-p)^{n-k}$ toplamında $k$, $\frac{\partial}{\partial a}a^k$'nın $a = 1$'deki değeri olarak yazılır. Türev ve toplam doğrusal işlemler olduğundan yer değiştirir; içteki toplam binom açılımıdır: $\sum_k \binom{n}{k}(ap)^k(1-p)^{n-k} = (ap + 1 - p)^n$. Türev $n(ap + 1 - p)^{n-1}p$, $a = 1$'de $np$ olur. İkinci moment için $k^2 = k\cdot k$, iki ayrı değişkene göre karışık ikinci türev $\frac{\partial^2}{\partial a\,\partial b}(ab)^k$ ile yazılır; sonuç $E[X^2] = np(1-p) + n^2p^2$, buradan $\mathrm{Var}(X) = E[X^2] - (np)^2 = np(1-p)$.
- **Poisson beklenen değeri.** Aynı teknikle $E[X] = e^{-\lambda}\frac{\partial}{\partial a}\sum_k \frac{(a\lambda)^k}{k!}\big|_{a=1}$ yazılır. İçteki seri $e^{a\lambda}$'dır; türevi $\lambda e^{a\lambda}$, $a = 1$'de $\lambda e^{\lambda}$ olur ve $e^{-\lambda}$ ile çarpılınca $E[X] = \lambda$ çıkar. Varyansın da $\lambda$ olduğu ayrıca gösterilebilir.
- **Kesikliden sürekliye.** Sürekli rastgele değişkende örnek uzay sayılamayacak kadar sonsuzdur, bu yüzden tek bir noktanın olasılığı sıfırdır ve olasılık aralıklar üzerinden PDF'in integraliyle hesaplanır. PDF'in CDF'in türevi olduğu, küçük bir $[x, x+\Delta x]$ aralığında PDF'in yaklaşık sabit kalması ve integralin $f_X(x)\Delta x$'e yaklaşmasıyla gösterildi. Beklenen değer, varyans ve kovaryans tanımları kesikli durumdakinin aynısıdır; toplamın yerini integral alır.
- **İlişkisizlik ve bağımsızlık.** Bağımsız değişkenlerde ortak PDF marjinallerin çarpımına ayrılır, çift integral iki tek integralin çarpımına dönüşür ve $E[XY] = E[X]E[Y]$ olduğundan kovaryans sıfır olur. Tersi genelde doğru değildir; Gauss değişkenler bu kuralın istisnasıdır.
- **Uniform dağılım örneği.** Ders sonunda bir örnek olarak $[a,b]$ üzerindeki düzgün dağılımın PDF, CDF, ortalama ve varyansı türetildi. $E[X] = \frac{b^2 - a^2}{2(b-a)} = \frac{a+b}{2}$, $E[X^2] = \frac{b^3 - a^3}{3(b-a)} = \frac{a^2 + ab + b^2}{3}$; farkları $\frac{(b-a)^2}{12}$ verir.
- Ders sonrası not: Hoca üç sigma kuralında yüzdeyi %88,8 diye söyledi; $8/9 = 0{,}8889$ olduğundan yuvarlanmış doğru değer %88,9'dur.
- Ders sonrası not: Hoca $X \sim \mathrm{Poisson}(\lambda)$ ve $Y \sim \mathrm{Poisson}(\nu)$ toplamının $\mathrm{Poisson}(\lambda + \nu)$ olduğunu söylerken bağımsızlık koşulunu yazmadı; bu sonuç $X$ ile $Y$ bağımsızken geçerlidir.
- Ders sonrası not: Gauss değişkenlerde ilişkisizliğin bağımsızlık anlamına gelmesi için $X$ ile $Y$'nin ortak (jointly) Gauss olması gerekir; her birinin ayrı ayrı Gauss olması yetmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
