# Ders 12 Çalışma Özeti

## Genel Konular

- Kesikli olasılıktan sürekli olasılığa geçiş
  - Kesikli rastgele değişkenlerin değer kümesi sayılabilirdir. Sürekli bir rastgele değişkenin değer kümesi ise örneğin $[1,2]$ gibi bir aralıktır ve bu aralıkta sayılamayacak kadar çok gerçel sayı vardır.
  - Bu yüzden tek bir noktanın olasılığı sıfırdır: tek noktalara sıfırdan büyük olasılık verilseydi toplam olasılık 1'i aşardı.
  - Sürekli durumda tek değerlerin değil, aralıkların olasılığı hesaplanır (ör. $P(1 \le X \le 1{,}2)$).
- Sürekli kurallar kesikli kurallara benzer
  - Kesikli durumdaki toplamın yerini integral, olasılık kütle fonksiyonunun (PMF) yerini olasılık yoğunluk fonksiyonu (PDF) alır (ekrandan, 00:25:00):
    - Kesikli: $EX = \sum_x x\,P(x)$
    - Sürekli: $EX = \int_{-\infty}^{+\infty} x\,f(x)\,dx$
- Sürekli rastgele değişkenin tanımı (ekrandan, 00:25:00)
  - Birikimli dağılım fonksiyonu (CDF) $F_X(x)$ olan bir $X$, $F_X(x)$ her $x \in \mathbb{R}$ için sürekli bir fonksiyonsa süreklidir.
  - Ayrıca $F_X(x)$'in hemen her yerde türevlenebilir olduğu varsayılır.
- Örnek: $[a,b]$ aralığında düzgün (uniform) seçilen sayı
  - CDF (ekrandan, 00:35:00 ve 00:40:00):
    - $x < a$ için $F_X(x) = 0$
    - $a \le x \le b$ için $F_X(x) = \dfrac{x-a}{b-a}$
    - $x > b$ için $F_X(x) = 1$
  - Grafik: $a$'ya kadar 0, $a$ ile $b$ arasında doğrusal artış, $b$'den sonra 1 (ekrandan, 00:45:00).
  - PDF, CDF'nin her parçasının türevidir: $a \le x \le b$ için $f_X(x) = \dfrac{1}{b-a}$, dışarıda 0. Grafiği $a$ ile $b$ arasında sabit yükseklikte bir dikdörtgendir.
- Olasılık yoğunluk fonksiyonu (PDF) ve özellikleri (ekrandan, 01:10:00, 01:15:00, 01:20:00)
  - $f_X(x) = \dfrac{d}{dx} F_X(x)$, tersi $F_X(x) = \int_{-\infty}^{x} f_X(u)\,du$.
  - Bir aralığın olasılığı: $P(a < X \le b) = F_X(b) - F_X(a) = \int_a^b f_X(x)\,dx$, yani yoğunluk eğrisinin altındaki alan.
  - Bir kümenin olasılığı: $P(X \in A) = \int_A f_X(x)\,dx$. Örnek: $P(X \in [0,1] \cup [3,4])$.
  - Toplam olasılık 1'dir: $\int_{-\infty}^{+\infty} f_X(x)\,dx = 1$.
  - Yoğunluk hiçbir yerde negatif olmaz: $f_X(x) \ge 0$. Yoğunluk 1'den büyük olabilir.
- Sürekli rastgele değişkenin değer kümesi (ekrandan, 01:25:00)
  - $R_X = \{x \mid f_X(x) > 0\}$: yoğunluğun sıfırdan büyük olduğu gerçel sayılar.
- Örnek: elektronik bileşenin ömrü (ekrandan, 01:30:00)
  - $f_X(x) = k/x^3$ ($x \ge 1$), $0$ ($x < 1$). İstenenler: $k$, $F_X(x)$ ve grafiği, ömrün 5 yılı aşma olasılığı.
  - $k = 2$, $F_X(x) = 1 - 1/x^2$ ($x > 1$), $0$ ($x \le 1$).
- Beklenen değer
  - $EX = \mu_X = \int_{-\infty}^{+\infty} x\,f_X(x)\,dx$.
  - Fonksiyonun beklenen değeri: $Y = g(X)$ için $EY = \int_{-\infty}^{+\infty} g(x)\,f_X(x)\,dx$.
  - Doğrusallık: $E(aX+b) = a\,EX + b$, $E(X_1+\dots+X_n) = EX_1+\dots+EX_n$.
- Varyans (ekrandan, 02:20:00)
  - Biçim I: $\mathrm{Var}(X) = E\big((X-\mu_X)^2\big) = \int_{-\infty}^{\infty} (x-\mu_X)^2 f_X(x)\,dx$.
  - Biçim II: $\mathrm{Var}(X) = EX^2 - \mu_X^2 = \int_{-\infty}^{\infty} x^2 f_X(x)\,dx - \mu_X^2$.
  - Özellikler: $\mathrm{Var}(aX+b) = a^2\,\mathrm{Var}(X)$; bağımsız $X$ ve $Y$ için $\mathrm{Var}(X+Y) = \mathrm{Var}(X)+\mathrm{Var}(Y)$.
- Sürekli rastgele değişkenin fonksiyonları (ekrandan, 02:30:00 ve 02:35:00)
  - $Y = g(X)$ de bir rastgele değişkendir; $F_Y$ ve $f_Y$ bulunabilir.
  - Yöntem: (1) $R_Y$'yi bul, (2) $F_Y(y) = P(Y \le y) = P(g(X) \le y)$, (3) $f_Y(y) = \dfrac{d}{dy}F_Y(y)$.
  - Örnek: $X \sim \mathrm{Uniform}(0,1)$, $Y = e^X$. $R_Y = [1, e]$; $1 \le y \le e$ için $F_Y(y) = P(X \le \ln y) = F_X(\ln y) = \ln y$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek noktanın olasılığı sıfırdır
  - Bu yüzden sürekli olasılıkta $<$ ile $\le$ arasında fark yoktur (ekrandan, 00:40:00). Eşitlik aralığa yalnız bir nokta ekler, o noktanın olasılığı da sıfırdır.
- Büyük $X$ ile küçük $x$ ayrımı
  - Büyük $X$ rastgele değişkeni, küçük $x$ onun aldığı belirli bir değeri gösterir: $F_X(x) = P(X \le x)$ (ekrandan, 00:35:00).
- İntegralde sınırlar yoğunluğun sıfırdan farklı olduğu yerden başlar
  - $-\infty$ ile $+\infty$ teorik sınırlardır; yoğunluğun sıfır olduğu kısım integrale bir şey katmaz. Ömür örneğinde integral 1'den başlar.
- Temel integral bilgisi gerekir
  - Polinom integrali: $\int x^n\,dx = \dfrac{x^{n+1}}{n+1} + C$ ($n \ne -1$); ayrıca $\int \dfrac{1}{x}\,dx = \ln x + C$ (ekrandan, 01:45:00 ve 02:10:00). Unutan temel integral formüllerini tekrar etmeli.
- Fonksiyon dönüşümünde önce değer kümesi bulunur
  - $R_Y$ bulunduktan sonra $F_Y$'nin aralık dışındaki değerleri (0 ve 1) hemen yazılır; asıl iş aradaki kısımdır.
- Varyansın iki biçimi
  - Biçim I varyansın ne olduğunu anlamak için (ortalamadan sapmanın karesinin beklenen değeri), biçim II hesap yapmak için daha kullanışlıdır.
- Beklenen değer ve varyans sonsuz olabilir
  - $f_X(x) = 2x^{-3}$ ($x \ge 1$) için $EX = 2$ ama $EX^2 = \infty$ ve $\mathrm{Var}(X) = \infty$.

## Kısa Tekrar Notları

- Sürekli rastgele değişkende $P(X = x) = 0$; olasılık aralıklar için hesaplanır.
- Toplam yerine integral, PMF yerine PDF.
- $f_X = F_X'$; $F_X(x) = \int_{-\infty}^{x} f_X(u)\,du$.
- $P(a < X \le b) = F_X(b) - F_X(a) = \int_a^b f_X$.
- $\int_{-\infty}^{\infty} f_X = 1$; $f_X \ge 0$; $f_X$ 1'i aşabilir.
- $R_X = \{x \mid f_X(x) > 0\}$.
- $\mathrm{Uniform}(a,b)$: $f = 1/(b-a)$, $F = (x-a)/(b-a)$ aralıkta.
- $EX = \int x f_X$, $E\,g(X) = \int g(x) f_X$.
- $\mathrm{Var}(X) = EX^2 - \mu_X^2$; $\mathrm{Var}(aX+b) = a^2\mathrm{Var}(X)$.
- $Y = g(X)$ için sıra: $R_Y$ → $F_Y$ → $f_Y$.

## Detaylı Açıklamalar

- Sürekli olasılığa geçiş
  - Kesikli rastgele değişkenlerde değer kümesi sayılabilir olduğu için her değere bir olasılık verilip toplanabiliyordu. Sürekli bir değişkenin değer kümesi bir aralık olduğunda aralıktaki her gerçel sayı olası bir değerdir. Bu değerlerin her birine pozitif olasılık verilirse toplam olasılık sonsuz olur, oysa toplam olasılık 1 olmalıdır. Sonuç olarak tek bir noktanın olasılığı sıfırdır ve sorular "$X$'in 1 ile 1,2 arasında olma olasılığı nedir" biçiminde aralıklar üzerinden sorulur.
  - Kesikli durumda öğrenilen kuralların çoğu sürekli durumda da geçerlidir. Fark, toplamın integrale, olasılık kütle fonksiyonunun olasılık yoğunluk fonksiyonuna dönüşmesi ve "bütün olası $x$ değerleri" ifadesinin $-\infty$ ile $+\infty$ arası integrale dönüşmesidir.
- Düzgün dağılım örneği
  - $[a,b]$ aralığından rastgele ve düzgün bir sayı seçilsin; aralıktaki bütün değerler eşit olasılıklıdır. $a$'dan küçük değerlerin olasılığı sıfır olduğu için $x < a$ iken CDF sıfırdır. $a$ ile $b$ arasındaki toplam olasılık 1'dir ve $b$'den sonra eklenecek bir şey yoktur, bu yüzden $x \ge b$ iken CDF 1'dir. Aradaki bir $x$ için $F_X(x) = P(X \in [a,x])$, düzgün dağılımda bu aralığın uzunluğunun toplam uzunluğa oranıdır: $(x-a)/(b-a)$.
  - Parçalı tanımlı CDF'nin türevi her parça için ayrı alınır. Sabit 0 ve 1 parçalarının türevi 0, ortadaki parçanın türevi $1/(b-a)$'dır. Böylece yoğunluk $a$ ile $b$ arasında sabit, dışarıda sıfırdır.
- Ömür örneği (ekrandan, 01:30:00 – 01:55:00)
  - (a) $\int_{-\infty}^{\infty} f_X = 1$ koşulu kullanılır. $x < 1$ kısmı 0 katkı yapar: $\int_1^{\infty} k x^{-3}\,dx = \left[-\dfrac{k}{2x^2}\right]_1^{\infty} = \dfrac{k}{2} = 1$, buradan $k = 2$. Hoca integrali "türevi $1/x^3$ olan fonksiyon hangisi?" sorusuyla da açıkladı: $-\tfrac{1}{2}x^{-2}$'nin türevi $x^{-3}$'tür.
  - (b) $x > 1$ için $F_X(x) = \int_1^x \dfrac{2}{u^3}\,du = 1 - \dfrac{1}{x^2}$; $x \le 1$ için 0. İntegral değişkeni olarak üst sınırdaki $x$ ile karışmasın diye $u$ kullanılır. Grafiği çizmek öğrenciye bırakıldı.
  - (c) $P(X > 5) = \int_5^{\infty} f_X(x)\,dx$ olarak kuruldu; sayısal sonuç derste yazılmadı. <!-- BELİRSİZ: Hoca sonucu sözlü söylemiş olabilir, altyazıda okunmuyor. --> Hesaplanırsa $P(X > 5) = 1 - F_X(5) = 1/25 = 0{,}04$ olur (derste verilmedi, ajan tarafından python ile kontrol edildi).
- Beklenen değer ve varyans örneği (ekrandan, 02:10:00 ve 02:25:00)
  - Aynı yoğunluk $f_X(x) = 2x^{-3}$ ($x \ge 1$) için $EX = \int_1^{\infty} x \cdot 2x^{-3}\,dx = 2\int_1^{\infty} x^{-2}\,dx = \left[-2x^{-1}\right]_1^{\infty} = 2$.
  - $EX^2 = \int_1^{\infty} x^2 \cdot 2x^{-3}\,dx = \int_1^{\infty} 2x^{-1}\,dx = \left[2\ln x\right]_1^{\infty} = \infty$.
  - Biçim II ile $\mathrm{Var}(X) = EX^2 - \mu_X^2 = \infty - 2^2 = \infty$. Beklenen değerin sonlu, varyansın sonsuz olması mümkündür.
- Doğrusallığın kullanımı
  - Bir dağılım başka dağılımların toplamı olarak yazılabiliyorsa toplamın beklenen değeri terimlerin beklenen değerlerinin toplamıdır. Hoca bunun gamma ve negatif binom dağılımlarının beklenen değerini bulmakta işe yarayacağını, gamma dağılımının üstel dağılımların toplamı olduğunu söyledi (bu dağılımlar sonraki derslerde işlenecek).
- Varyans özellikleri
  - $\mathrm{Var}(aX+b) = a^2\mathrm{Var}(X)$: sabitin varyansı sıfır olduğu için $b$ ifadede görünmez. $\mathrm{Var}(X+Y) = \mathrm{Var}(X)+\mathrm{Var}(Y)$ genelde doğru değildir; $X$ ile $Y$ bağımsızsa geçerlidir.
- Fonksiyon dönüşümü örneği: $Y = e^X$, $X \sim \mathrm{Uniform}(0,1)$ (ekrandan, 02:35:00 – 02:50:00)
  - $X$ için $a = 0$, $b = 1$: $f_X(x) = 1$ ($0 \le x \le 1$), $F_X(x) = x$ ($0 \le x \le 1$).
  - $R_Y = [g(0), g(1)] = [e^0, e^1] = [1, e]$. Buna göre $y < 1$ için $F_Y(y) = 0$, $y > e$ için $F_Y(y) = 1$.
  - $1 \le y \le e$ için $F_Y(y) = P(e^X \le y)$. Bu doğrudan hesaplanamaz çünkü elimizde $X$ için olasılıklar vardır. İki tarafın logaritması alınır (yani $g$'nin tersi uygulanır): $P(X \le \ln y) = F_X(\ln y) = \ln y$.
  - Sonuç: $F_Y(y) = 0$ ($y < 1$), $\ln y$ ($1 \le y \le e$), $1$ ($y > e$).
  - Ekranda (b) $f_Y(y)$ ve (c) $EY$ de soruldu; hoca bunları eve bıraktı. Türev alınırsa $f_Y(y) = 1/y$ ($1 \le y \le e$) ve $EY = \int_1^e y \cdot \tfrac{1}{y}\,dy = e - 1$ olur (derste verilmedi, ajan tarafından python ile kontrol edildi).
- Ders sonrası not
  - Ekranda $R_Y$ için $\{g(x) \mid f(x) \ge 0\}$ yazıldı (ekrandan, 02:30:00); hoca sözlü olarak "sıfırdan büyük" dedi ve değer kümesini daha önce $f_X(x) > 0$ ile tanımlamıştı. Doğrusu büyük olasılıkla $f_X(x) > 0$'dır; $\ge 0$ bütün gerçel sayıları kapsar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
