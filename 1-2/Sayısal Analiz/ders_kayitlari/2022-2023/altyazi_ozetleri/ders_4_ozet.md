# Ders 4 Çalışma Özeti

## Genel Konular

- Duyurular
  - Diğer grubun hocası Ahmet Hoca bir Google Classroom sınıfı açtı ve bu grup da eklendi. İki grubun proje konuları aynıdır. Proje ilanlarını Classroom'dan takip edin.
  - Proje dönem sonundadır. Konular biterse son iki hafta proje gösterimine ayrılır. Projede belirli yöntemlerin kodlanması istenecek, istediğiniz programlama dilini kullanabilirsiniz. Baştaki yöntemler kolay olduğu için şimdiden yazmaya başlayın, dönem sonunda ödevler birikir.
  - Yanınızda mutlaka hesap makinesi olsun.
- Kısa tekrar: doğrusal olmayan denklemler
  - Kapalı yöntemlerde kök $[a, b]$ aralığındadır ve $f(a) \cdot f(b) < 0$ olmalıdır. Bu yöntemler ıraksamaz ama iterasyon sayısı uzun sürebilir.
  - Açık yöntemlerde verilen değerler kökü çevrelemek zorunda değildir. Yöntem ıraksayabilir. Iraksarsa başlangıç değeri veya aralık değiştirilir. Yakınsarsa kapalı yöntemlerden çok daha hızlı köke ulaşır.
- Tekrarlama (basit iterasyon, sabit nokta) yöntemi (fixed point iteration)
  - Açık yöntemlerin üçüncüsüdür. Kullanışlıdır, iyi sonuç verir. Yalnızca bir uygunluk kontrolü vardır. Kontrol sağlanmazsa işlem uzayabilir.
  - 1. adım: $f(x) = 0$ denklemi $x = g(x)$ biçimine getirilir: $x$ sol tarafta tek başına kalır, geri kalan $g(x)$ olur. $x - g(x) = 0$ yine $f(x) = 0$ demektir.
  - Bir $f$ için birden fazla $g$ yazılabilir. Örnek: $x^2 - 9x - 10 = 0$ için $x = \sqrt{9x + 10}$ veya $x = \frac{x^2 - 10}{9}$. Bunlardan hepsi, bazısı veya hiçbiri uygun olabilir.
  - Grafik yorumu: $y = x$ doğrusu ve $y = g(x)$ eğrisi çizilir. $x_0$ alınır, $g(x_0)$ hesaplanır, bu değer doğru üzerinden yeni $x$ olur, tekrar $g$'ye konur. Uygun bir $g$ seçildiyse adımlar iki eğrinin kesişim noktasına (köke) yakınsar. Uygun değilse kökten giderek uzaklaşır (ıraksar).
  - 2. adım (uygunluk kontrolü):
    - $f(a) \cdot f(b) < 0$ olmalı (aralıkta kök var).
    - $f(x)$ ve $g(x)$ türevlenebilir olmalı.
    - $|g'(a)| < 1$ ve $|g'(b)| < 1$ olmalı. İki şart birlikte sağlanırsa $[a, b]$ aralığındaki her nokta başlangıç değeri olarak seçilebilir.
  - Başlangıç değeri genelde verilir. Verilmezse aralığın ilk veya son değeriyle başlanır.
  - İterasyon: $x_{i+1} = g(x_i)$. Durma: $|x_{i+1} - x_i| \le \varepsilon$. Hocanın sınavlarda istediği durma koşulu %95 bu ölçüttür. Başka koşullar da vardır: gerçek kök verilirse onunla fark, ya da belirli bir iterasyon sayısı.
  - Şart sağlanmazsa (ikisi de veya biri 1'den küçük değilse) iki yol vardır:
    - Yeni bir $x = g(x)$ biçimi aranır.
    - Başka $g$ yoksa aralıktan bir $x_i$ seçilir ve $x_{i+1} = g(x_i)$ hesaplanır. $0 < \left|\frac{g(x_i) - g(x_{i+1})}{x_i - x_{i+1}}\right| < 1$ ise bu $x_i$ ile başlanır. Sağlanmazsa aralıkta başka bir $x_i$ denenir (ör. 1, 0.90, 0.80…). Uçlarda şartın sağlanmaması, aralığın içinde hiçbir noktanın sağlamadığı anlamına gelmez.
    - Elle yapmak zahmetlidir. Programda $x$ belirli bir artımla (ör. 0.25) değiştirilerek şartı sağlayan nokta aranır. Aralığın sonuna kadar bulunamazsa başka bir $g$ seçilir.
  - Örnek 1: $\sin x + x - 1 = 0$, $[0, 1]$.
    - $f(0) = -1$, $f(1) = 0.84$, aralıkta kök var. Trigonometrik hesapta radyan kullanılır. Hesap makinesi derece modundaysa $x$ yerine $x \cdot \frac{180}{\pi}$ yazılır.
    - $g(x) = 1 - \sin x$, $g'(x) = -\cos x$. $|g'(0)| = 1$ (1'den küçük değil), $|g'(1)| = 0.54$. Şart sağlanmıyor, aralıktaki her nokta başlangıç olamaz. Başka $g$ de çıkarılamıyor.
    - İkinci kontrol $x_i = 1$ ile yapılır: $x_{i+1} = g(1) = 0.158529$. $\left|\frac{g(1) - g(0.158529)}{1 - 0.158529}\right| = \frac{0.6836}{0.842} \approx 0.81 < 1$. Şart sağlanır, $x_0 = 1$ ile devam edilir.
    - $x_1 = 0.158529$, $x_2 = 0.842134$, $x_3 = 0.253934$… Ardışık iki değerin farkı $\varepsilon$'dan küçük olana kadar devam edilir.
  - Örnek 2: $x^5 + x - 3 = 0$, $[1, 3]$. $f(1) \cdot f(3) < 0$. $g$ için iki seçenek: $x = 3 - x^5$ veya $x = \sqrt[5]{3 - x}$. Slaytta "uygun olduğunu ispatladık diyelim" denerek kontrol atlandı.
  - Örnek 3: $f(x) = x^2 - 2x - 3$, $x_0 = 4$, $\varepsilon = 0.005$. Gerçek kökler 3 ve −1. Hoca derste aralığı önce $[4, 5]$, sonra "1 ile 4 arası olsun" diye düzeltti. Üç $g$ yazıldı:
    - $g_1(x) = \sqrt{2x + 3}$: 4, 3.316, 3.104, 3.034, 3.011, 3.004, 3.001. Son fark 0.003 < 0.005. Kök 3.001.
    - $g_2(x) = \frac{3}{x - 2}$: 4, 1.5, −6, −0.375, −1.29032, −0.91176, −1.03030, −0.98999, −1.00335, −0.99888, −1.00037. Kök yaklaşık −1.
    - $g_3(x) = \frac{x^2 - 3}{2}$: 4, 6.5, 19.625, 191.07, 18252.43. Farklar giderek büyür, yöntem ıraksar. Bu, $g_3$'ün türevinin aralıkta 1'den küçük olmadığını da gösterir.
    - Farklı $g$'ler farklı köklere götürebilir. $g_1$, başlangıç değerine (4) daha yakın olan 3'ü az adımda buldu. $g_2$ daha uzaktaki −1'i daha çok adımda buldu. İterasyon sayısı $\varepsilon$'a da bağlıdır.
- Doğrusal denklem takımlarının çözümü: matris bilgileri
  - Denklem takımları matris biçimine getirilir ve matrisler üzerinde işlemler yapılır: alt/üst üçgen, birim, köşegen veya bant matrise çevirme, ters alma.
  - Matris: satırlar ve sütunlardan oluşan iki boyutlu dizi. Her satır bir denkleme, her sütun bir değişkene karşılık gelir.
  - Alt üçgen matris: köşegenin üstü sıfır. Üst üçgen matris: köşegenin altı sıfır. Birim matris: köşegen 1, geri kalan 0. Köşegen matris: köşegen dışı 0. Bant matris: köşegen çevresindeki bir şerit dolu, şeridin altı ve üstü 0.
  - Transpoz: satırlar ve sütunlar yer değiştirir. Simetrik matris: $A = A^T$.
  - Kofaktör: $a_{ij}$'nin bulunduğu satır ve sütun silinir, kalan matrisin determinantı $(-1)^{i+j}$ ile çarpılır. Kofaktör matrisi bu değerlerden oluşur. Hoca, belge-kelime sayım matrisi ve görüntü pikselleri örnekleriyle kofaktörün ileride veri madenciliği ve görüntü işlemede karşınıza çıkacağını söyler.
  - Adjoint (ek) matris: kofaktör matrisinin transpozu. $A^{-1} = \frac{\text{adj}(A)}{|A|}$. Kütüphanelerdeki ters alma fonksiyonu arka planda bu tür işlemleri yapar. Bu derste tersin sayısal yöntemle nasıl alınacağı görülür.
  - Toplama/çıkarma karşılıklı elemanlarla yapılır. $m \times n$ ile $i \times j$ matrisleri çarpmak için $n = i$ olmalıdır. Matrisler birbirine bölünmez, ama bir matris bir sayıya bölünebilir (her eleman bölünür).
- Elementer (temel) satır işlemleri
  - Genişletilmiş (augmented) katsayılar matrisi: $[A \mid C]$. $AX = C$'de $A$ katsayılar, $X$ bilinmeyenler, $C$ sağ taraf matrisidir. Örnek: $x + 3y - z = 10$, $3x - y + 2z = 5$, $x + 5y - 2z = -3$.
  - İşlemler:
    - Bir satırı bir sayıyla çarpmak (ör. $2S_1$: 2, 6, −2, 20).
    - İki satırın yerini değiştirmek ($S_1 \leftrightarrow S_2$).
    - İki satırı toplayıp bir satıra yazmak ($S_1 + S_2 \to S_1$: 4, 2, 1, 15).
    - Bir satırın katını başka bir satıra eklemek.
  - Bu işlemlerle sayılar değişir ama matrisin taşıdığı bilgi değişmez. $\frac{2}{10}$ ile $\frac{1}{5}$ gibi. Orijinal sistemle işlem görmüş sistemin çözümü aynıdır.
- Matrisin tersi (Gauss-Jordan ile)
  - $[A \mid I]$ yan yana yazılır. $A$'yı birim matrise çeviren elementer işlemler aynı anda $I$'ya da uygulanır. $A$, $I$'ya dönüştüğünde $I$'nın yerinde $A^{-1}$ oluşur.
  - Yalnızca kare matrislerin tersi alınır. Her kare matrisin tersi yoktur: işlem sırasında bir satır tamamen sıfır olursa ters alınamaz.
  - $(1,1)$ gözünde 0 varsa önce satırların yeri değiştirilerek sıfırdan kurtulunur.
  - 2×2 örnek: $A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$.
    - $-3S_1 + S_2 \to S_2$: $\begin{bmatrix} 1 & 2 & 1 & 0 \\ 0 & -2 & -3 & 1 \end{bmatrix}$.
    - $-\frac{1}{2}S_2 \to S_2$: $\begin{bmatrix} 1 & 2 & 1 & 0 \\ 0 & 1 & \frac{3}{2} & -\frac{1}{2} \end{bmatrix}$.
    - $-2S_2 + S_1 \to S_1$: $A^{-1} = \begin{bmatrix} -2 & 1 \\ \frac{3}{2} & -\frac{1}{2} \end{bmatrix}$.
  - 3×3 örnek: $A = \begin{bmatrix} 5 & 2 & -4 \\ 1 & 4 & 2 \\ 2 & 3 & 6 \end{bmatrix}$. Her sütun için aynı kalıp tekrarlanır:
    - $i$. satırı $a_{ii}$'ye böl (köşegen 1 olur). İlk adımda 1. satır 5'e bölünür: 1, 0.4, −0.8 | 0.2, 0, 0.
    - Diğer her $k$ satırından $a_{ki} \cdot (i.\ \text{satır})$ çıkar (o sütunun geri kalanı 0 olur). Örneğin 2. satırdan $1 \cdot S_1$ çıkarılır: 0, 3.6, 2.8 | −0.2, 1, 0.
    - Sonra 2. satır $a_{22} = 3.6$'ya bölünür, 1. ve 3. satırlardaki 2. sütun sıfırlanır. Ardından 3. satır $a_{33}$'e bölünür ve 3. sütun sıfırlanır.
    - Sonuç (slayt): $A^{-1} = \begin{bmatrix} 0.16 & -0.23 & 0.19 \\ -0.02 & 0.36 & -0.13 \\ -0.05 & -0.11 & 0.17 \end{bmatrix}$.
  - Algoritma iki iç içe `for` döngüsüdür: dış döngü satırları (köşegen elemanı), iç döngü diğer satırları dolaşır. Hoca Gauss-Jordan'ı ters almanın en hızlı ve en kolay yolu olarak tanıtır. Farklı kaynaklarda farklı elementer işlem sıraları görülebilir, doğru oldukları sürece hepsi kullanılabilir.
  - Kare olmayan matrisin tersi (genel kültür): satır sayısı > sütun sayısı ise $C = A^T A$ ($n \times n$ kare) hesaplanır, $A^{-L} = C^{-1} A^T$ soldan terstir ve $A^{-L} A = I$ verir. Sütun sayısı > satır sayısı ise $C = A A^T$ ile sağdan ters $A^T C^{-1}$ bulunur. Örnek: $A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \\ 2 & 1 \end{bmatrix}_{3 \times 2}$.
- Doğrusal denklem takımları
  - $n$ bilinmeyen için $n$ denklem gerekir. Katsayılar matrisi kare olmalıdır.
  - $C = 0$ ise sistem homojendir. $C \neq 0$ ise homojen değildir. Dersin konusu homojen olmayan sistemlerdir.
  - Dolaysız (direkt) yöntemler: işlem belirli adımlarda biter, adımlar birbirine iteratif olarak bağlı değildir. Cramer, eliminasyon (Gauss, Gauss-Jordan) ve Cholesky (kompakt eliminasyon). Elle yapıldığında hata olasılığı biraz daha yüksektir.
  - Dolaylı (iteratif) yöntemler: her adım bir öncekini kullanır. Jacobi ve Gauss-Seidel (Jacobi üzerinde küçük bir değişiklik). Hocaya göre en kolayları bunlardır.
  - Bazı yöntemler diğerlerinin bir modülünü kullanır. Bunları ayrı fonksiyonlar olarak yazarsanız başka yöntemlerde tekrar kullanabilirsiniz.
- Cramer yöntemi
  - Az sayıda bilinmeyen (3-4) için uygundur, fazlası uzun sürer.
  - $x_k = \frac{|A_k|}{|A|}$. $A_k$: $A$'nın $k$. sütunu yerine $C$ konmuş matris.
  - Kodlaması çok kolaydır: tek gereken bir determinant fonksiyonudur. Arkasındaki ispat matematikçilerin işidir.
  - Örnek: $2x_1 - 3x_2 + 2x_3 = -11$, $x_1 + x_2 - 2x_3 = 8$, $3x_1 - 2x_2 - x_3 = -1$. $|A| = 2(-1-4) + 3(-1+6) + 2(-2-3) = -5$. Sonuç: $x_1 = 1$, $x_2 = 3$, $x_3 = -2$.
- Gauss eliminasyon (yok etme) yöntemi
  - Yalnızca kare sistemler için. Genişletilmiş matris üzerinde çalışır. Katsayılar matrisi elementer işlemlerle üst üçgen matrise (köşegen 1) çevrilir, aynı işlemler $C$'ye de uygulanır.
  - Sonra sondan başa doğru geri yerine koyma yapılır: son denklemden $z$, onun üstündekinden $y$, en üsttekinden $x$ bulunur.
    - $x_i = \frac{1}{a_{ii}}\left[c_i - \sum_{j=i+1}^{n} a_{ij} x_j\right]$, $i = n, n-1, \ldots, 1$.
  - Kullanılan işlem kalıbı: 1. satırı $a_{11}$'e böl. 2. satırı $a_{21}$'e böl, 1. satırı çıkar, sonucu $a_{21}$ ile çarp (yani $S_2 - a_{21} S_1$). 3. satır için aynısı $a_{31}$ ile. Sonra 2. satırı $a_{22}$'ye böl, 3. satır için $a_{32}$ ile aynı işlem. En son 3. satırı $a_{33}$'e böl. Yalnızca indisler değişir, kalıp aynıdır.
  - Örnek: $3.6x + 2.4y - 1.8z = 6.3$, $4.2x - 5.8y + 2.1z = 7.5$, $0.8x + 3.5y + 6.5z = 3.7$.
    - Üst üçgen biçim: $\begin{bmatrix} 1 & 0.667 & -0.5 \\ 0 & 1 & -0.489 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 1.75 \\ -0.017 \\ 0.281 \end{bmatrix}$.
    - Geri yerine koyma: $z = 0.281$, $y = -0.017 + 0.489 \cdot 0.281 = 0.120$, $x = 1.75 - 0.667 \cdot 0.120 + 0.5 \cdot 0.281 = 1.81$.
- Gauss-Jordan yöntemi
  - Gauss'un elde ettiği üst üçgen matris birim matrise çevrilir. Aynı işlemler $C$'ye uygulanır. Sonunda her satır doğrudan bir değişkenin değerini verir, geri yerine koymaya gerek kalmaz.
  - Sondan başlanır: önce $a_{23}$ ve $a_{13}$ sıfırlanır (3. satırın katları çıkarılır), sonra $a_{12}$ sıfırlanır (2. satırın katı çıkarılır).
  - Aynı örnek: $\begin{bmatrix} 1.75 + 0.5 \cdot 0.281 \\ -0.017 + 0.489 \cdot 0.281 \\ 0.281 \end{bmatrix} = \begin{bmatrix} 1.89 \\ 0.12 \\ 0.281 \end{bmatrix}$, sonra $x = 1.89 - 0.12 \cdot 0.667 = 1.81$. Sonuç $x = 1.81$, $y = 0.120$, $z = 0.281$.
  - Ters almada yazdığınız "birim matrise çevirme" fonksiyonunu burada da kullanabilirsiniz.
- Ders planı: Cholesky yöntemi gelecek haftaya kaldı. Sonra dolaylı yöntemler (Jacobi, Gauss-Seidel), ardından sayısal integral ve türev, fark tabloları ve vizeye kadar enterpolasyon. Vizelerin nasıl yapılacağı henüz belli değil.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tekrarlama yönteminde $g(x)$ seçimi en önemli adımdır. $|g'(a)| < 1$ ve $|g'(b)| < 1$ kontrolünü yapmadan başlamayın. Yanlış $g$ ile değerler kökten uzaklaşır.
- Ardışık farklar giderek büyüyorsa yöntem ıraksıyordur. Başka bir $g$ deneyin.
- Uç noktalarda şartın sağlanmaması aralığın tamamında sağlanmadığı anlamına gelmez. Aralık içinde başka bir başlangıç noktası arayın.
- Trigonometrik fonksiyonlarda radyan/derece dönüşümüne dikkat edin.
- Elementer işlemler sayıları değiştirir ama matrisin bilgisini ve sistemin çözümünü değiştirmez.
- Ters alma ve eliminasyon algoritmaları hep aynı kalıbı tekrar eder, yalnızca indisler değişir. Bu yüzden iki iç içe döngüyle kolayca kodlanır.
- Yalnızca kare matrislerin tersi alınır. Elementer işlem sırasında bir satır tamamen sıfır olursa ters yoktur. $(1,1)$ gözündeki 0'dan satır değiştirerek kurtulun.
- Proje için yöntemleri şimdiden kodlamaya başlayın.

## Kısa Tekrar Notları

- Tekrarlama yöntemi: $f(x) = 0 \Rightarrow x = g(x)$, $x_{i+1} = g(x_i)$, dur: $|x_{i+1} - x_i| \le \varepsilon$.
- Uygunluk: $f(a) f(b) < 0$, $f$ ve $g$ türevlenebilir, $|g'(a)| < 1$ ve $|g'(b)| < 1$.
- Şart sağlanmazsa: yeni $g$ veya $0 < \left|\frac{g(x_i) - g(x_{i+1})}{x_i - x_{i+1}}\right| < 1$ sağlayan bir $x_i$.
- Elementer işlemler: satırı sayıyla çarp, satırları değiştir, satırları topla, satırın katını başka satıra ekle.
- Ters: $[A \mid I] \to [I \mid A^{-1}]$.
- Cramer: $x_k = \frac{|A_k|}{|A|}$.
- Gauss: üst üçgen + geri yerine koyma. Gauss-Jordan: birim matris, sonuç doğrudan okunur.
- Dolaysız: Cramer, Gauss, Gauss-Jordan, Cholesky. Dolaylı: Jacobi, Gauss-Seidel.

## Detaylı Açıklamalar

### Tekrarlama yönteminin neden çalıştığı

- Kök $r$ için $r = g(r)$'dir. Ortalama değer teoremine göre $x_{i+1} - r = g(x_i) - g(r) = g'(\xi)(x_i - r)$. Yani her adımda hata yaklaşık $|g'|$ ile çarpılır.
- $|g'| < 1$ ise hata her adımda küçülür (yakınsama). $|g'| > 1$ ise büyür (ıraksama). İkinci kontroldeki $\left|\frac{g(x_i) - g(x_{i+1})}{x_i - x_{i+1}}\right|$ oranı, $g'$'nin bu iki nokta arasındaki ortalama değeridir.
- $g'$ negatifse değerler kökün iki yanında salınarak yakınsar (Örnek 1'deki 0.16, 0.84, 0.25… ve Örnek 3'teki $g_2$). $g'$ pozitifse tek yönden yaklaşır ($g_1$: 3.316, 3.104, 3.034…).
- $|g'|$ 1'e ne kadar yakınsa yakınsama o kadar yavaştır.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile yeniden hesaplandı. Tekrarlama yöntemi tabloları, 2×2 ters, Cramer ve Gauss/Gauss-Jordan sonuçları slaytlarla aynıdır. Derste sözlü olarak "3.16" ($g_1$'in ilk adımı) ve "141" ($g_3$'ün üçüncü adımı) denildi. Slayttaki doğru değerler 3.316 ve 191.07'dir.
- **Örnek 1'in devamı:** $g(x) = 1 - \sin x$ ile yöntem yakınsar ama çok yavaştır. Kök $r \approx 0.51097$ ve $|g'(r)| = \cos r \approx 0.872$. 1'e yakın olduğu için hata her adımda yalnızca %13 kadar küçülür. $\varepsilon = 0.005$ ile ardışık fark ölçütü 38. iterasyonda durur ve 0.5131'i verir. Gerçek kökten farkı yaklaşık 0.002'dir. Bu örnekte Newton-Raphson veya ikiye bölme çok daha hızlı olurdu.
- **Örnek 2'deki $g$ seçimleri:** Slaytta iki $g$'nin de uygun olduğu varsayıldı. Aslında $g(x) = 3 - x^5$ için $|g'(x)| = 5x^4 \ge 5$ olur ($[1, 3]$ aralığında). Bu $g$ uygun değildir ve ıraksar. $g(x) = \sqrt[5]{3 - x}$ ise kök çevresinde uygundur: kök $r \approx 1.1330$, $|g'(r)| \approx 0.12$. Ancak $x = 3$'te $3 - x = 0$ olduğu için $g'(3)$ tanımsızdır. Yani uç nokta kontrolü burada da sağlanmaz. Başlangıç için $x = 1$ gibi bir nokta seçilmelidir.
- **Örnek 3'te durma:** $g_2$ tablosunda $|-0.99888 - (-1.00335)| = 0.00446 < 0.005$ olduğu için bu satırda durulabilirdi. Slayt bir adım daha (fark 0.00149) gitmiştir. Sonuç yine yaklaşık −1'dir. Ayrıca $g_2(x) = \frac{3}{x - 2}$, $x = 2$'de tanımsızdır. Hocanın sözlü olarak düzelttiği $[1, 4]$ aralığında bu fonksiyon sürekli değildir. $g_2$'nin bulduğu −1 kökü de bu aralığın dışındadır.
- **$g_3$'ün uygunsuzluğu:** $g_3(x) = \frac{x^2 - 3}{2}$ için $g_3'(x) = x$. 3 kökü çevresinde $|g'| = 3 > 1$, −1 kökü çevresinde $|g'| = 1$. Bu yüzden iki kök için de uygun değildir.
- **Elementer işlem örneğindeki tutarsızlık:** Slayttaki denklemlerde üçüncü denklem $x + 5y - 2z = -3$, genişletilmiş matriste ise $z$ katsayısı $+2$ yazılmış. Ayrıca denklemlerdeki hâliyle ($-2$) bu sistemin determinantı 0'dır: $1(2 - 10) - 3(-6 - 2) - 1(15 + 1) = 0$. Yani bu sistem tekil, tek çözümü yoktur. Örnek yalnızca satır işlemlerini göstermek için kullanıldı.
- **Cramer örneğindeki $C$:** Denklemlerde üçüncü eşitlik $-1$, matris gösteriminde ise $1$ yazılmış. Doğrusu $-1$'dir. $x_1 = 1$, $x_2 = 3$, $x_3 = -2$ sonucu $-1$ ile elde edilir ($|A_1| = -5$, $|A_2| = -15$, $|A_3| = 10$).
- **3×3 tersin yuvarlaması:** $|A| = 106$ ve tam ters $\frac{\text{adj}(A)}{106}$'dır. Dört basamakla: $\begin{bmatrix} 0.1698 & -0.2264 & 0.1887 \\ -0.0189 & 0.3585 & -0.1321 \\ -0.0472 & -0.1038 & 0.1698 \end{bmatrix}$. Slayttaki 0.16 ve −0.11, ara adımlarda iki basamakla yuvarlama yapıldığı için çıkmıştır. Doğru yuvarlanmış hâlleri 0.17 ve −0.10'dur. Ara adımlarda daha fazla basamak tutmak yuvarlama hatasını azaltır.
- **Slayttaki 9. işlem başlığı:** "2. satırdan $(a_{22} \cdot 3.\ \text{satır})$ çıkar" yazıyor. Bu adımda sıfırlanan eleman $a_{23}$'tür, doğrusu "2. satırdan $a_{23} \cdot (3.\ \text{satır})$ çıkar" olmalıdır.
- **Gauss örneğinde $z$:** Hoca bir slaytta $z = 2.81$ yazdığını fark edip düzeltti. Doğru değer $z = 0.281$'dir (tam değer 0.28169). Tam çözüm $x = 1.81076$, $y = 0.12013$, $z = 0.28169$.
- **Ortogonal matris tanımı:** Derste "bir matris tersine eşitse ortogonaldir" denildi. Doğrusu $A^T = A^{-1}$, yani $A^T A = I$'dir. Sütunları (ve satırları) birbirine dik birim vektörlerdir.
- **Gauss-Seidel sürçmesi:** Ders sonunda "Gauss-Seidel yöntemi sondan başlayarak çözüyor" denildi. Kastedilen Gauss eliminasyonudur. Gauss-Seidel dolaylı (iteratif) bir yöntemdir ve sonraki derslerde işlenecektir.
- **Kısmi pivotlama:** Hocanın "$(1,1)$ gözündeki 0'dan satır değiştirerek kurtul" uyarısının genel hâli kısmi pivotlamadır. Her sütunda mutlak değerce en büyük elemanı olan satır köşegene getirilir. Böylece sıfıra bölme önlenir ve yuvarlama hataları azalır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
