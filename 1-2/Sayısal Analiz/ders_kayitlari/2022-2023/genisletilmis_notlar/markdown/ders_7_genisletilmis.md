# Ders 7 Genişletilmiş Notu: İntegral Tekrarı ve Alan Problemleri, İki Katlı İntegral, Sonlu Farklar ve Fark Tabloları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayısal İntegral Tekrarı
- 2. Sınıf Alıştırması: Parabol, Doğrular ve $Ox$ Ekseni
- 3. "$Ox$ Ekseni ile Sınırlı" Ne Demektir?
- 4. İki Katlı İntegral
- 5. Sonlu Farklara Giriş
- 6. Fark Operatörleri
- 7. Yüksek Dereceden Farklar
- 8. Fark Tabloları
- 9. Polinomlarda Sabit Fark
- 10. Fark Tablosunda Hatanın Yayılması

## 1. Sayısal İntegral Tekrarı

Hoca, integralin önemli bir konu olduğunu söyleyerek yeni konuya geçmeden önce geçen dersin kısa bir özetini yaptı, ardından sınıfa bir soru çözdürdü.

### 1.1 İntegral Bir Alan Hesabıdır

İntegral almak, belirli sınırlar arasında kalan bir bölgenin alanını bulmak demektir. $\int_a^b f(x)\,dx$, $f(x)$ eğrisinin altında kalan ve $x$ ekseniyle kapalı olan alandır. Bu bölge bildiğimiz bir geometrik şekil olmadığı için alanını doğrudan hesaplayamayız. Newton-Cotes formülleri burada devreye girer. Derste üç yöntem görülmüştü:

- **Trapez (yamuk) kuralı:** Fonksiyon yerine birinci dereceden bir polinom, yani $ax + b$ gibi bir doğru geçirilir. Alan yamuklara bölünür.
- **Simpson 1/3 kuralı:** Fonksiyon yerine ikinci dereceden bir polinom, yani parabol geçirilir. Parabol, fonksiyonu üç noktada keser.
- **Simpson 3/8 kuralı:** Fonksiyon yerine üçüncü dereceden (kübik) bir polinom geçirilir. Polinom, fonksiyonu dört noktada keser ve aralarda birbirine eşit üç parça vardır.

> **Ders sonrası not:** Hoca tekrar sırasında "$f(x)$ fonksiyonu bir polinom" ve "fonksiyon 3. dereceden bir polinomsa" gibi ifadeler kullandı. Polinom olan, $f(x)$'in kendisi değil, yerine geçirilen fonksiyondur. Geçen dersteki $\frac{1}{1 + x^4}$ örneği de polinom değildir, ama bu kurallarla hesaplanır.

### 1.2 Trapez Kuralı

Fonksiyon $[a, b]$ kapalı aralığında eşit parçalara bölünür ve dik çizgiler çizilir. $x_0$ ile $x_1$ arasındaki mesafe, $x_1$ ile $x_2$ arasındaki mesafeyle aynıdır. Bu mesafeye $h$ denir:

$$h = \frac{b - a}{n}$$

Dik çizgilerin eğriyi kestiği noktalar birleştirilince $n$ tane yamuk elde edilir. Her yamuğun alanı bilinir: alt taban ile üst tabanın toplamının yarısı çarpı yükseklik. Yamukların alanları arka arkaya toplanınca trapez formülü çıkar. $f(a)$ ile $f(b)$ toplanıp ikiye bölünür, geri kalan bütün $y$ değerleri eklenir ve sonuç $h$ ile çarpılır:

$$I \approx h\left[\frac{f(a) + f(b)}{2} + \sum_{i=1}^{n-1} f_i\right]$$

Örneklerde önce başlangıç ve bitiş değerleri alınmış, $x$ değerleri $h$ kadar artırılmış, $f(x)$ değerleri fonksiyonda yerine konmuş ve formül uygulanmıştı. Analitik sonuçla sayısal sonuç arasındaki mutlak değerce fark bize hatayı verir. $n$ büyüdükçe hata küçülür. Elle hesap yaparken $n$ küçük seçilebilir, ama program yazıldıysa $n$ yüksek seçilir.

### 1.3 Simpson 1/3 Kuralı

Bu kuralda eğrinin altındaki alan parabol parçalarına bölünür. Formül şöyle çıkmıştı: Sınırlar $-h$ ve $+h$ olsun, ortadaki nokta $x = 0$ olsun. Polinom $ax^2 + bx + c$'dir. İntegral analitik olarak açılır:

$$\int_{-h}^{h} (ax^2 + bx + c)\,dx = \frac{h}{3}\left(2ah^2 + 6c\right) \quad \text{(ara adım eklendi)}$$

Fonksiyonda $x$ yerine $-h$, $0$ ve $+h$ konunca üç değer bulunur:

$$y_0 = ah^2 - bh + c, \qquad y_1 = c, \qquad y_2 = ah^2 + bh + c$$

$y_0$ ile $y_2$ toplanınca $bh$'li terimler gider: $y_0 + y_2 = 2ah^2 + 2c$. Buradan $2ah^2 = y_0 + y_2 - 2y_1$ olur. Yukarıda yerine konunca bir parabolün altındaki alan $\frac{h}{3}(y_0 + 4y_1 + y_2)$ çıkar (son adım eklendi).

Trapezde fonksiyonu nasıl birçok yamuğa böldüysek, burada da üç noktadan geçen birçok parabole böleriz. Her parçanın alanı toplanınca baştaki ve sondaki değer tek kalır, tek indisliler 4 ile, çift indisliler 2 ile çarpılır, başta da $\frac{h}{3}$ bulunur:

$$I \approx \frac{h}{3}\left[f_0 + f_n + 4\sum_{\text{tek } i} f_i + 2\sum_{\text{çift } i} f_i\right]$$

> **Ders sonrası not:** Hoca, kuralın adını "3 parçaya bölüyorum, 3 tane noktam oluyor" diye açıkladı. Bir parabol 3 noktadan geçer ama aralığı 2 parçaya böler. $\frac{1}{3}$ adı büyük olasılıkla formülün başındaki $\frac{h}{3}$ çarpanından gelir. Aynı şekilde $\frac{3}{8}$ adı da büyük olasılıkla $h = \frac{b-a}{3}$ alınınca oluşan $\frac{3h}{8}$ çarpanından gelir.

### 1.4 Geçen Dersin Alan Örnekleri

Hoca, fonksiyon çizdirilen sorularda panik yapılmamasını istedi. $x$'e belirli değerler verip $y$'leri bulmak ya da eksenleri kestiği noktaları bulmak yeterlidir.

İlk örnek $y = x^3$ idi. $x = 0$ için $y = 0$, $x = 1$ için $y = 1$, $x = -1$ için $y = -1$, $x = -2$ için $y = -8$ bulunur. Sorulan, $x = -1$ ve $x = 2$ doğruları ile $Ox$ ekseni arasındaki bölgenin alanıydı. $Ox$ ile sınırlı iki bölge vardır: $[0, 2]$ aralığındaki parça ve $[-1, 0]$ aralığındaki parça. Her biri için ayrı integral yazılır, trapez ya da Simpson ile çözülür. $[-1, 0]$ parçası eksenin altında kaldığı için negatif çıkar. Alan negatif olamayacağı için sonuçlar mutlak değerce toplanır.

<!-- BELİRSİZ: Altyazıda sınırlar "eksi bir ... eksi iki" diye geçiyor. Hemen ardından integral 0'dan 2'ye kurulduğu ve Ders 6'da soru x = -1, x = 2 olduğu için x = 2 yazıldı. -->

İkinci örnekte önemli olan, eğrinin $x$ eksenini hangi noktalarda kestiğini bulmaktı. Kökler $-1$, $+1$ ve $-2$ idi. $x = 0$ verilerek $y$ eksenini kestiği yer de kolayca bulunur. Soruda $Ox$ ekseninin üstünde kalan bölge istendiği için hesaplanacak yer yalnızca $[-2, -1]$ aralığındaki parçaydı. Hoca soruyu değiştirdi: "$y = -2$ ile sınırlandırılmış, $Ox$ ekseni arasında kalan alan" denseydi bu kez sınırlar $-1$'den $+1$'e gidecekti.

<!-- BELİRSİZ: Fonksiyon bu derste söylenmedi. Kökler Ders 6'daki f(x) = (x^2 - 1)(x + 2) örneğiyle uyuşuyor. [-2, -1] aralığı slayttaki şekilden çıkarıldı. -->

> **Ders sonrası not:** Bu fonksiyonun Ders 6'daki $f(x) = (x^2 - 1)(x + 2)$ olduğu varsayılırsa $f(0) = -2$'dir, ama Python hesabına göre $[-1, 1]$ aralığındaki en küçük değer $x \approx 0.215$'te yaklaşık $-2.11$'dir. Yani $y = -2$ doğrusu büyük olasılıkla eğrinin dibini tam içine almaz. Hocanın örneği büyük olasılıkla yalnız sınırlama fikrini göstermek içindir.

### 1.5 Simpson 3/8 Kuralı ve $n$ Değeri

Hoca bu formülün aslında akılda zor kalmayacağını söyledi. Elimizdeki eğriden dört noktada kesen bir polinom geçirilir. Noktalar rastgele seçilmez, aralarındaki üç mesafe birbirinin aynıdır. Burası $a$, burası $b$ ise üç bölge vardır. $b$'den $a$'yı çıkarıp 3'e bölersek bir bölgenin uzunluğunu buluruz. Bunun üzerine $a$ eklenince $x_1$, iki katı eklenince $x_2$ bulunur:

$$x_1 = a + \frac{b - a}{3}, \qquad x_2 = a + 2\,\frac{b - a}{3}$$

$$I \approx (b - a)\,\frac{f(a) + 3f(x_1) + 3f(x_2) + f(b)}{8}$$

Hoca formülü aklında böyle tuttuğunu söyledi. Matematiksel ispatı ise sayfalarca sürer. Matematik bölümünde okunsaydı bu ayrıntılar verilirdi.

Bu formül $n = 1$ alınarak yazılmıştır. $n = 2$ ne demektir? Eğri, her biri dört noktalı bir polinomla kesilecek iki parçaya bölünür: birincisi $[a, \frac{a+b}{2}]$, ikincisi $[\frac{a+b}{2}, b]$. $n = 3$ olsaydı üç parça olur, her parçadan yine dört noktadan geçen bir polinom geçirilirdi. Her parçada aynı formül kullanılır: $x_1$ hesaplanırken o parçanın üst sınırından alt sınırı çıkarılır, 3'e bölünür ve alt sınıra eklenir. $x_2$ için aynı uzunluk 2 ile çarpılarak eklenir.

> **Ders sonrası not:** Hoca $n = 3$ için sınırları anlatırken "$a$ artı $b$ bölü 2", sonra "$a$ artı $b$" dedi. Üç eşit parçanın sınırları $a$, $a + \frac{b-a}{3}$, $a + 2\frac{b-a}{3}$ ve $b$'dir. Hocanın hemen sonraki sayısal örneği ($6 - 0$ bölü 3, yani 2 birimlik parçalar) de buna uygundur.

**Örnek:** $\int_0^6 \frac{dx}{1 + x^4}$ integralini Simpson 3/8 ile $n = 1$ ve $n = 2$ için çözünüz. $f$ değerleri derste sözlü söylenmedi, aşağıdaki değerler Python ile hesaplandı.

**$n = 1$:** $b - a = 6$. $x_1 = 0 + \frac{6 - 0}{3} = 2$, $x_2 = 4$.

$$I \approx 6 \cdot \frac{f(0) + 3f(2) + 3f(4) + f(6)}{8} = 6 \cdot \frac{1 + 3(0.058824) + 3(0.003891) + 0.000771}{8} = 0.8917$$

**$n = 2$:** $6$'yı 2'ye böleriz, yani parçalar $[0, 3]$ ve $[3, 6]$ olur.

- $[0, 3]$ için $x_1 = 0 + \frac{3 - 0}{3} = 1$, $x_2 = 2$. Sonuç $3 \cdot \frac{1 + 3(0.5) + 3(0.058824) + 0.012195}{8} = 1.00825$.
- $[3, 6]$ için $x_1 = 3 + \frac{6 - 3}{3} = 4$, $x_2 = 5$. Sonuç $3 \cdot \frac{0.012195 + 3(0.003891) + 3(0.001597) + 0.000771}{8} = 0.01104$.

İki parça toplanınca $I \approx 1.0193$ bulunur.

Hoca burada canlı bir hata yaptı: İkinci parçanın $x_1$'ini önce $3 + \frac{6 - 3}{2} = 4.5$ buldu, "niye 4 çıkaramadık" diye durdu ve sonra hatasını gördü. Bölünen sayı parça sayısı olan 2 değil, her zaman 3'tür. Formülün kendi içindeki üç eşit bölgeyi unutmamak gerekir.

**$n = 3$ olsaydı:** $\frac{6 - 0}{3} = 2$ olduğu için parçalar $[0, 2]$, $[2, 4]$ ve $[4, 6]$ olurdu. İlk parçada $x_1 = 0 + \frac{2 - 0}{3} = \frac{2}{3}$, $x_2 = \frac{4}{3}$ olur ve bu şekilde devam edilir.

> **Ders sonrası not:** Python hesabına göre $n = 3$ için sonuç 1.1112, gerçek değer ise yaklaşık 1.10918'dir. Değerler Ders 6'nın notuyla aynıdır.

Hoca bu kısmı şöyle özetledi: 3/8 kuralı biraz daha matematik ağırlıklıdır, 1/3 kuralında alan parabol parçalarına, trapezde ise yamuklara bölünerek formül çıkarılmıştır.

## 2. Sınıf Alıştırması: Parabol, Doğrular ve $Ox$ Ekseni

Hoca, notlar açıkken çözülmesi için bir soru verdi. Amacı, nerede takıldığımızı görmekti. "Bakın, bu örneğin size çok büyük bir yararı olacak" dedi.

**Soru:** $y = x^2 - 5x + 4$ parabolü ile $y = 4$, $x_1 = 0$, $x_2 = 4$ doğruları ve $Ox$ ekseni ile sınırlı olan bölgenin alanını bulunuz.

**Soru:** $n$'yi kaç alıyoruz? **Cevap:** Hoca önce "acaba $n$'ye ihtiyacın var mı?" diye karşılık verdi.

**Soru:** 3/8 kuralını kullanmayacak mıyız? **Cevap:** Hoca, hangi yöntemle çözüleceğinin sorulmadığını, kendisinin de söylemeyi unuttuğunu belirtti. Soru hem trapez hem Simpson 1/3 ile, $n = 4$ alınarak çözülecek.

Hoca bu arada bir kuralı hatırlattı: Trapez ve Simpson 1/3 formüllerinde $n$ değeri gerekir, Simpson 3/8'in formülünde gerekmez. Simpson 1/3'te $n$ mutlaka çift olmalıdır, trapezde böyle bir kural yoktur.

### 2.1 Şekli Çizmek

İlk iş parabolün $x$ eksenini kestiği noktaları bulmaktır. Çarpımları 4, toplamları $-5$ olan iki sayı $-4$ ve $-1$'dir, yani kökler $4$ ve $1$'dir. $x = 0$ verilirse $y = 4$ olur. Parabol $(0, 4)$ noktasından iner, $x = 1$'de ekseni keser, altından geçer ve $x = 4$'te yeniden keser.

Sonra sınırlar çizilir: $y = 4$ yatay doğrusu, $x = 0$ ve $x = 4$ dikey doğruları. Bunlar ile $Ox$ ekseni arasında, parabolün üst tarafında kalan bölge istenen alandır.

<!-- BELİRSİZ: Şekil tahtada çizildi. Bölgenin "kırmızı" ve "yeşil" diye gösterilen sınırları altyazıdaki sözlü anlatımdan kuruldu. -->

**Soru:** Bu bölge bir trapezoid (yamuk) değil mi? **Cevap:** Hayır. Tahtadaki çizim düz gibi görünse de kenarlardan biri parabol parçasıdır, kavislidir. Bu yüzden ne üçgen, ne kare, ne dikdörtgen, ne de yamuktur. Bu şekli bilmiyoruz.

### 2.2 Bilinen Şekli Görmek

Hocanın ipucu şuydu: $x = 0$, $x = 4$, $y = 4$ ve $Ox$ ekseni bir kare oluşturur. Kenarı 4 olduğu için alanı $4^2 = 16$'dır. İstenen bölge bu karenin içindedir, ama karenin tamamı değildir. İstenmeyen parça $[0, 1]$ aralığında parabolün altında ve $Ox$ ekseninin üstünde kalan parçadır. Burası da üçgen değildir, çünkü kenarlarından biri fonksiyondur. Ama bu parçanın alanını integralle bulabiliriz. Sonuç olarak:

$$S = 16 - \int_0^1 (x^2 - 5x + 4)\,dx$$

Hoca bu çözümü bulmayı "çok ileri görüşlüyüm" diye şakayla anlattı. Burada önemli olan, integrali trapez, 1/3 ya da 3/8, hangi yöntem istenmişse onunla çözüp sayısal bir değer elde etmektir.

### 2.3 Sayısal Çözüm

Hoca yalnızca sonucu söyledi ve dersten sonra çözülmesini istedi. Aşağıdaki ara adımlar eklendi.

$h = \frac{1 - 0}{4} = 0.25$ alınır:

| $i$ | $x_i$ | $f(x_i)$ |
|---|---|---|
| 0 | 0 | 4 |
| 1 | 0.25 | 2.8125 |
| 2 | 0.50 | 1.75 |
| 3 | 0.75 | 0.8125 |
| 4 | 1 | 0 |

**Trapez:**

$$I \approx 0.25\left[\frac{4 + 0}{2} + (2.8125 + 1.75 + 0.8125)\right] = 0.25 \cdot 7.375 = 1.84375$$

$$S \approx 16 - 1.84375 = 14.15625$$

**Simpson 1/3:**

$$I \approx \frac{0.25}{3}\left[(4 + 0) + 4(2.8125 + 0.8125) + 2(1.75)\right] = \frac{0.25}{3} \cdot 22 = 1.83333$$

$$S \approx 16 - 1.83333 = 14.16667$$

Hocanın verdiği sonuç 14.16 birim karedir. Hoca, noktadan sonra kaç basamak alındığına bağlı olarak 14.13 ya da 14.20 gibi değerlerin de bulunabileceğini, $n$ büyütülüp örneğin 20 alınırsa daha küçük aralıklara bölündüğü için değerin daha hassas olacağını söyledi.

> **Ders sonrası not:** Python hesabına göre analitik değer $\int_0^1 (x^2 - 5x + 4)\,dx = \frac{1}{3} - \frac{5}{2} + 4 = 1.83333$, alan $14.16667$'dir. Trapez $n = 20$ ile $14.16625$ verir, yani hocanın dediği gibi $n$ büyüdükçe trapez sonucu analitik değere yaklaşır.

> **Ek bilgi (derste anlatılmadı):** Simpson 1/3'ün analitik sonucu tam vermesinin nedeni büyük olasılıkla fonksiyonun kendisinin parabol olmasıdır. Bu durumda yerine geçirilen parabol, fonksiyonla aynı olur.

### 2.4 Soru-Cevap

**Soru:** 0'dan 4'e $n = 4$ ile trapez uygulayıp bulduğumuz parçayı $4 \times 4$'lük kareden doğrudan çıkarabilir miyiz? **Cevap:** 0'dan 4'e integral almak, eğrinin altında kalan alanı almak demektir. Bu, istenen bölgeyi vermez.

**Soru:** Peki 0'dan 1'e trapez yöntemiyle alsak? **Cevap:** 0'dan 1'e trapez alınırsa yalnızca o bölge bulunur. Burada alanın $Ox$ ile sınırlandırıldığı önemlidir. Denmezse şekle bir çizgi daha çizdiğinizde onun altında kalan yerler de işe karışır. Bu yüzden hep "$Ox$ ile sınırlandırılmış" denir.

## 3. "$Ox$ Ekseni ile Sınırlı" Ne Demektir?

Hoca, sorunun üzerine bu ifadeyi başka şekillerle de açıkladı.

Bir fonksiyon düşünelim, $x = 3$'te ekseni kessin. 0'dan 3'e integral almak, fonksiyonun altında kalan alanı almak demektir. Fakat 3'ten sonra eğri nokta nokta sonsuza gidebilir. Bir yerde sınırlandırmak gerekir. $Ox$ ile sınırlandırılınca yalnızca eğri ile eksen arasındaki bölge alınır.

$y = -4$ gibi bir sınır daha verilseydi bu kez bölge, eksenin altında $y = -4$ doğrusuna kadar uzanan bir yer olurdu. O zaman kesişim noktaları arasında integral alınır. Gerekirse bölge bir kareye ya da dikdörtgene tamamlanır, integrali bulunan parça bu bilinen alandan çıkarılır. Hoca "Başka türlü olmaz" dedi.

<!-- BELİRSİZ: y = -4 örneği tahtadaki şekle bağlı anlatıldı. Fonksiyonun formülü ve kesişim noktaları altyazıda geçmiyor. -->

Aynı konu kökleri $-2$, $-1$ ve $1$ olan eğri üzerinde de konuşuldu:

- "$Ox$ ekseniyle sınırlı alan" denirse iki bölge alınır: $[-2, -1]$ ve $[-1, 1]$. $x = 1$'den sonraki kol alınamaz, çünkü nereye kadar gittiği bilinmez.
- "$Ox$ ile sınırlı, altında kalan alan" denirse yalnızca $[-1, 1]$ bölgesi alınır.
- "$Ox$ ile sınırlı, üstünde kalan alan" denirse yalnızca $[-2, -1]$ bölgesi alınır.
- "$-2$ ile $-1.5$ arasında $Ox$ ile sınırlı alan" denirse yalnızca o parça için integral yazılır.

Alan için $-2$'den $+1$'e tek integral alınamaz, parçalamak gerekir: Önce $-2$'den $-1$'e, sonra $-1$'den $+1$'e. Eğri bir kez daha dönseydi üçüncü bir integral gerekirdi. Eksenin altında kalan alan negatif çıkacağı için mutlak değeri alınır, sonra hepsi toplanır.

Hoca son bir örnek verdi: Yine kökleri 1 ve 4 olan parabol olsun, $x = 5$ ve $y = 4$ sınırları verilsin, $y = 4$ doğrusunun altında kalan alan sorulsun. Bu kez üç ayrı integral yazılır: $[0, 1]$, $[1, 4]$ ve $[4, 5]$ aralıkları için. Sonra sonuçlar toplanır.

> **Ders sonrası not:** Hoca bu örnekte önce "$x = 1$ ile $x = 5$" dedi ve orta parça için "1'den 5'e" integralini söyledi. Ama $\int_0^1$'i de hesaba kattığı için sol sınır büyük olasılıkla $x = 0$'dır. Orta parça da büyük olasılıkla $\int_1^4$'tür, çünkü $\int_4^5$ ayrıca yazıldı ve 1'den 5'e yazılırsa bu parça iki kez sayılırdı.

> **Hocanın vurgusu:** Şekil nasıl verildiyse grafiğin üstüne çizin. Kalan alanları gerekirse üç dört parçaya bölün ya da kare, dikdörtgen gibi bilinen alanları bulun. Dışarıda kalan parçaları integralle hesaplayıp ekleyerek ya da çıkararak sonuca ulaşın.

## 4. İki Katlı İntegral

Hoca, "Bir katlısı eksikti, şimdi iki katlısı çıktı" diyerek şu integrali gösterdi ve $n = 4$ alındığını söyledi:

$$I = \int_2^3 \int_x^{2x^3} (x^2 + y)\,dy\,dx$$

**Soru:** Bunu analitik olarak rahatça alabilir misiniz? **Cevap:** Sınıftan, bu konunun matematik dersinde henüz görülmediği söylendi. Hoca, buradaki derdimizin zaten bunu sayısal yolla çözmek olduğunu belirtti.

### 4.1 İç İntegrali Kapalı Kutu Gibi Düşünmek

Yöntemleri biliyoruz, ama bunu nasıl uygulayacağız? Hoca "mühendis gibi" düşünmeyi önerdi. İntegralin içinde bilinmeyenler var, ama $x$'ler sonuçta 3, 5, 7 gibi bir sayı olacak. $x$ değeri ne ise yerine konunca içeride yalnızca bilinmeyen $y$ ve $dy$ kalır.

Bu yüzden iç integralin tamamına $g(x)$ adı verilir:

$$g(x) = \int_x^{2x^3} (x^2 + y)\,dy, \qquad I = \int_2^3 g(x)\,dx$$

Bu artık sıradan bildiğimiz bir integraldir. $f(x)$ neyse $g(x)$ de bize verilmiş bir fonksiyon gibidir. Sınırlar ve $n$ bellidir. Sorunu zor gösteren şey, içerideki bilinmeyen karışıklığıdır. Hoca bunu "kapalı kutu" diye adlandırdı.

İşlem şu adımlarla yürür:

1. Dış sınırlardan $h$ hesaplanır ve $x_0, \ldots, x_n$ değerleri yazılır.
2. Her $x_i$ iç integralde yerine konur. İç sınırlar ve fonksiyon bu $x_i$'ye göre sayısal hâle gelir. İntegral yalnızca $y$'ye bağlı kalır.
3. Her iç integral için yeni bir $h$ hesaplanır, çünkü sınırlar değişmiştir. $y$ ve fonksiyon tablosu çıkarılır, seçilen yöntem uygulanır. Sonuç $g_i$'dir.
4. Bulunan $g_0, \ldots, g_n$ değerleri, dış integralde $f$ değerleri gibi kullanılır. Dış $h$ ile aynı yöntem uygulanır.

### 4.2 Dış Tablo

$$h = \frac{3 - 2}{4} = 0.25$$

$x$ değerleri 2, 2.25, 2.5, 2.75 ve 3 olur. Her biri için bir $g_i$ gerekir, yani beş ayrı tek katlı integral çözülecektir.

### 4.3 İç İntegraller

**$x_0 = 2$:** Üst sınır $2 \cdot 2^3 = 16$, fonksiyon $2^2 + y = 4 + y$ olur:

$$g_0 = \int_2^{16} (4 + y)\,dy, \qquad h = \frac{16 - 2}{4} = 3.5$$

| $y$ | 2 | 5.5 | 9 | 12.5 | 16 |
|---|---|---|---|---|---|
| $4 + y$ | 6 | 9.5 | 13 | 16.5 | 20 |

$$g_0 = \frac{3.5}{3}\left[(6 + 20) + 4(9.5 + 16.5) + 2(13)\right] = \frac{3.5}{3} \cdot 156 = 182$$

> **Ders sonrası not:** Hoca bu adımda "Hangi kuralı koymuşuz? Trapezi" dedi. Hemen ardından kullandığı $\frac{h}{3}$ çarpanı ve 4 ile 2 katsayıları Simpson 1/3 formülüne aittir. Sonraki adımlarda hoca da "Simpson" dedi.

**$x_1 = 2.25$:** Üst sınır $2 \cdot 2.25^3$, fonksiyon $2.25^2 + y$ olur. Sınırlar değiştiği için yeni $h$ hesaplanır. Hoca $h$'yi 5.13 alarak tabloyu yaptı ve "Burada birazcık sınırda taşma oldu" dedi. Slayttaki sonuç $g_1 = 360.417$'dir.

**$x_2 = 2.5$:** Üst sınır $2 \cdot 2.5^3$, fonksiyon $2.5^2 + y$ olur. Hoca $h = 7.19$ ile tabloyu yaptı ve $g_2 = 665.22$ buldu.

**$x_3 = 2.75$:** Aynı şekilde sınırlar ve fonksiyon yazılır, yeni $h$ ile tablo oluşturulur ve Simpson ile $g_3$ hesaplanır.

**$x_4 = 3$:** Üst sınır $2 \cdot 3^3 = 54$, fonksiyon $9 + y$ olur. $h = \frac{54 - 3}{4} = 12.75$. Hoca 3'ten başlayıp 12.75 ekleyerek 54'e geldi ve Simpson ile $g_4$'ü buldu.

<!-- BELİRSİZ: g3 ve g4 altyazıda sözlü söylenmedi, slaytta kaldı. Kısa nottaki 1154.7 ve 1912.5 değerleri aşağıda kullanıldı. Bu değerler dış Simpson sonucu olan 790.451 ile tutarlıdır. -->

### 4.4 Dış İntegral

Şimdi başa döneriz. $\int_2^3 g(x)\,dx$ için $f$ değerleri yerine $g$ değerleri kullanılır. Burada $h = 0.25$'tir, çünkü dış sınırlar 2 ve 3'tür:

$$I \approx \frac{0.25}{3}\left[(182 + 1912.5) + 4(360.417 + 1154.7) + 2(665.22)\right] = 790.451$$

Hoca, analitik çözümde 790.550 bulunacağını ve gerçek hatanın $|790.550 - 790.451| = 0.099$ olduğunu söyledi.

> **Ders sonrası not:** Python hesabına göre iç integraller kesin $h$ ile şöyledir. Slayttaki değerler bunlardan biraz farklıdır.

| $x_i$ | Üst sınır | $h$ | Python $g_i$ | Slayt $g_i$ |
|---|---|---|---|---|
| 2 | 16 | 3.5 | 182 | 182 |
| 2.25 | 22.78125 | 5.13281 | 360.901 | 360.417 |
| 2.5 | 31.25 | 7.1875 | 664.844 | 665.22 |
| 2.75 | 41.59375 | 9.71094 | 1154.995 | 1154.7 |
| 3 | 54 | 12.75 | 1912.5 | 1912.5 |

> Bu değerlerle dış Simpson 790.647 verir. Analitik değer ise $\int_2^3 \left(2x^6 + 2x^5 - x^3 - \frac{x^2}{2}\right)dx = \frac{22135}{28} \approx 790.536$'dır. Yani slayttaki analitik değer (790.550) büyük olasılıkla yuvarlama içerir. Kesin ara değerlerle hata yaklaşık 0.112'dir. $h = 7.19$ yuvarlaması $g_2 = 665.22$'yi tam olarak verir, bu yüzden farklar büyük olasılıkla $h$'nin yuvarlanmasından gelir. $g_1$ ise $h = 5.13$ ile de 360.59 çıkar, slayttaki 360.417'nin tam kaynağı netleşmedi. Altyazıda $g_1$ tablosunun "22.25'e kadar" gittiği geçiyor. Kesin üst sınır 22.78'dir.

### 4.5 Program Açısından

Hocanın bu örnekten çıkardığı sonuç şuydu: Trapez ve Simpson bir kez yazılıp kenara konduysa, iki katlı integral geldiğinde tek yapılacak şey $x$ değerlerini belirlemek, her $x_i$ için içteki fonksiyonu yerine koyup Simpson değerini hesaplamak ve dışta aynı yöntemi çalıştırmaktır. Hoca, bu ders kapsamında iki katlı integralin beklenmediğini, tek katlının yeterli olduğunu, ama görüldüğü gibi çözmenin zor olmadığını da ekledi.

## 5. Sonlu Farklara Giriş

Aradan sonra yeni bir başlığa geçildi. Sonlu farklar tek başına kullanılmayacak. İleride enterpolasyon görüldüğünde, enterpolasyon fonksiyonundaki belirli katsayılar tablo değerlerinden sonlu farklarla belirlenecek.

### 5.1 Neden Gerekir?

Hocanın slaytında şu tanım vardı: Matematik ve fizikteki problemlerin çoğu sürekli ve çok değişkenlidir. Fonksiyonlar bir formül şeklinde verilebilir ve değişkenlerin belli değerleri için fonksiyonun değeri hızlıca bulunabilir. Bazen de bir fonksiyon yalnızca birtakım ayrık noktalarda belirlenmiş olabilir. Bu durumda sonlu farklar matematiği kullanılarak bilinmeyen noktada fonksiyonun değeri için tahmin yapılabilir.

Hocanın örneği oda sıcaklığıydı. Odanın sıcaklığını yalnızca belirli saatlerde ölçtüğümüzü düşünelim. Dersin sonunda bu örneği saat 9, 12, 14, 16 ve 18 için yeniden verdi. Bu ölçümleri kullanarak saat 10'da ya da 17'de odanın kaç derece olduğunu tahmin etmek istiyoruz. Bunun için ölçüm noktalarından geçen bir fonksiyon uydurmaya çalışırız. Fonksiyon bu noktalardan geçerse, ara değerleri yerine koyup yaklaşık sonucu buluruz. Bu işlem enterpolasyondur.

<!-- BELİRSİZ: Hoca örneği ilk anlatışında saatleri "10, 1, 3, 15, 18" gibi söyledi ve "dört tane" dedi, ara saat olarak da 13.30 ile 15.15'i verdi. Sonraki anlatımda saatler 9, 12, 14, 16, 18, sıcaklıklar "5, 6, 5, 4, 1" gibi geçiyor. Altyazı bu kısımda net değil. -->

> **Ders sonrası not:** Örnekteki 9, 12, 14, 16 ve 18 saatleri eşit aralıklı değildir (ilk aralık 3 saat, diğerleri 2 saat). Burada anlatılan fark tabloları ise eşit aralıklı $x$ değerleri varsayar. Örnek büyük olasılıkla yalnız enterpolasyon fikrini anlatmak içindir.

Gregory-Newton enterpolasyon formülünün başında sonlu fark tabloları kullanılır. $ax^2 + bx + c$'deki $a$, $b$, $c$ gibi bilinmeyen katsayıları bu tablolardan alıp fonksiyonda yerine koyacağız, bir fonksiyon elde edeceğiz, ara değerleri de onunla tahmin edeceğiz. Bu yüzden sonlu farklar önce öğrenilir.

### 5.2 Gösterim

Eğri üzerinde $x_0$, $x_1$, $x_2$ noktalarında ölçümlerimiz olsun. Noktalar arası uzunluk sabittir ve $h$ ile gösterilir:

$$x_1 = x_0 + h, \quad x_2 = x_0 + 2h, \quad x_3 = x_0 + 3h, \quad \ldots, \quad x_n = x_0 + nh$$

$h$, ardışık iki $x$ değeri arasındaki farktır: $x_1 - x_0$ de $x_2 - x_1$ de aynı $h$'yi verir, $\frac{x_2 - x_0}{2}$ de.

Kısaltma olarak $f_0 = f(x_0)$, $f_1 = f(x_1)$, genel olarak $f_i = f(x_i)$ yazılır.

> **Hocanın vurgusu:** $f(x_0)$ diye uzun uzun yazmak yerine $f_0$ yazıyoruz, ama bunu görünce ne olduğunu bilin: Fonksiyonda $x$ yerine $x_0$ değerini koymak demektir.

## 6. Fark Operatörleri

Fark tablolarında ileri, geri veya merkezi fark kullanılabilir. Fakat derste, uygulamalarda ve kitapların çoğunda ileri fark kullanılır. Hoca bu yüzden ileri farkı ayrıntılı anlattı, diğerlerini de benzer şekilde aktardı. Türevde gördüğümüz ileri, geri ve merkezi türevde de aynı semboller kullanılmıştı.

Şekilde $x$ noktasının bir $h$ ilerisinde $x + h$, bir $h$ gerisinde $x - h$ vardır.

- **İleri fark ($\Delta$):** İlerideki $x + h$ noktasının fonksiyon değerinden $f(x)$ çıkarılır:

  $$\Delta f(x) = f(x + h) - f(x)$$

  Bu şu demektir: $f(x)$'e $\Delta f(x)$ eklenirse $f(x + h)$ elde edilir.

- **Geri fark ($\nabla$):** Bu kez büyük olan $f(x)$'ten geride kalan $f(x - h)$ çıkarılır:

  $$\nabla f(x) = f(x) - f(x - h)$$

- **Merkezi fark ($\delta$):** Genelde çok kullanılmaz. $x$'in iki yanında $h/2$ uzaklığındaki değerlerin farkı alınır. İki yarım aralığın toplamı yine $h$ eder:

  $$\delta f(x) = f\left(x + \frac{h}{2}\right) - f\left(x - \frac{h}{2}\right)$$

- **Ortalama operatörü ($\mu$):** Merkezi farktaki iki değerin farkı yerine toplamının yarısı alınır. Örneklerde çok kullanılmayacak:

  $$\mu f(x) = \frac{1}{2}\left[f\left(x + \frac{h}{2}\right) + f\left(x - \frac{h}{2}\right)\right]$$

- **Kaydırma operatörü ($E$):** Fonksiyona kaydırma uygulamak, $x$'i $h$ kadar ileri atıp fonksiyonun oradaki değerini almak demektir:

  $$E f(x) = f(x + h)$$

<!-- BELİRSİZ: Altyazıda merkezi fark sembolü "role" ve "Rho" diye geçiyor, slaydın kendisi okunamıyor. Kısa nottaki gibi delta (küçük) yazıldı. -->

$f(x + h)$, $f(x)$'e $\Delta f(x)$ eklenmiş hâlidir. $f(x)$ ortak paranteze alınırsa:

$$E f(x) = f(x) + \Delta f(x) = (1 + \Delta) f(x) \quad \Rightarrow \quad E = 1 + \Delta$$

Hoca burada ileri farkı kullandığını, geri veya merkezi farkın da kullanılabileceğini söyledi. İki kez kaydırmak için $E$ bir daha uygulanır: $E^2 f(x) = E\,f(x + h) = f(x + 2h)$. Üç kaydırmada $3h$ eklenir. Genel olarak fonksiyon kaçıncı dereceden kaydırılıyorsa $x$'e o kadar $h$ eklenir:

$$E^n f(x) = f(x + nh)$$

## 7. Yüksek Dereceden Farklar

İkinci, üçüncü, dördüncü dereceden fark ne demektir? Sonlu fark tablosu yapıldığında birinci kolon birinci dereceden ileri farklar, ikinci kolon ikinci dereceden ileri farklar olur ve bu, sabit bir değer elde edilene kadar sürer. Hoca bunun göründüğü kadar zor olmadığını söyledi. Bundan sonra kullanılacak indisli yazım şudur:

$$\Delta f_i = f_{i+1} - f_i$$

Yani ilerisindeki değerden kendisi çıkarılır.

### 7.1 İleri Farklar

İkinci derece, operatörü bir kez daha uygulamak demektir:

$$\Delta^2 f_i = \Delta(\Delta f_i) = \Delta(f_{i+1} - f_i) = \Delta f_{i+1} - \Delta f_i$$

$\Delta f_{i+1}$ de bir fazlasından kendisini çıkarmak olduğu için $f_{i+2} - f_{i+1}$'dir:

$$\Delta^2 f_i = (f_{i+2} - f_{i+1}) - (f_{i+1} - f_i) = f_{i+2} - 2f_{i+1} + f_i$$

> **Ders sonrası not:** Hoca "$\Delta$ çarpı $\Delta f_i$" dedi. Burada sayı çarpımı yoktur, $\Delta$ operatörü iki kez uygulanır.

Hoca burada binom açılımını gösterdi: Katsayılar Pascal üçgeninden gelir, bir önceki satırdaki komşular toplanır. Birinci derecede 1, 1 iken ikinci derecede 1, 2, 1 olur. İşaretler artı ve eksi sırasıyla gelir. Önemli olan katsayıları ve işaretleri çıkarabilmek, sonra indisleri belirlemektir. İleri farkta formül hep $f_i$ ile biter, sola doğru indis birer birer artar.

**Soru:** Üçüncü dereceden ileri fark ne olur? **Cevap:** Sınıftan $f_{i+3}$ cevabı geldi. Katsayılar binom açılımından: 1, 3, 3, 1 (1 ile 2 toplanır 3, 2 ile 1 toplanır 3). İşaretler artı, eksi, artı, eksi. $f_i$ ile biter, sola doğru $i+1$, $i+2$, $i+3$ olur:

$$\Delta^3 f_i = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i$$

Aynı sonucu açarak da buluruz:

$$\Delta^3 f_i = \Delta(\Delta^2 f_i) = \Delta^2 f_{i+1} - \Delta^2 f_i$$

$$= (f_{i+3} - 2f_{i+2} + f_{i+1}) - (f_{i+2} - 2f_{i+1} + f_i) = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i$$

Hocanın dediği gibi, bundan sonra dördüncü, beşinci, altıncı derece ne istenirse rahatça yazılabilir.

### 7.2 Geri Farklar

Mantık aynıdır. Birinci derece $\nabla f_i = f_i - f_{i-1}$'dir. İkinci derecede:

$$\nabla^2 f_i = \nabla(f_i - f_{i-1}) = (f_i - f_{i-1}) - (f_{i-1} - f_{i-2}) = f_i - 2f_{i-1} + f_{i-2}$$

Yine 1, 2, 1 binom katsayıları, yine artı, eksi, artı işaretleri vardır. Fark, indislerdedir: Geri farkta $f_i$ ile başlanır ve indis azalarak gider.

**Soru:** Üçüncü dereceden geri fark ne olur? **Cevap:** Katsayılar 1, 3, 3, 1, işaretler artı, eksi, artı, eksi. $f_i$ ile başlar, indis birer azalır:

$$\nabla^3 f_i = f_i - 3f_{i-1} + 3f_{i-2} - f_{i-3}$$

Hoca bunun da $\nabla^2$'nin önüne bir $\nabla$ daha koyup dağıtılarak aynı şekilde çıktığını gösterdi. Özetle ileri farkta sondan başlanıp bir artarak, geri farkta $f_i$'den başlanıp bir azalarak gidilir.

### 7.3 Merkezi Farklar

Merkezi fark çok kullanılmaz, ama hoca ikinci ve üçüncü dereceyi de gösterdi. $h$ burada 1 alınır, böylece $h/2$ yerine $\frac{1}{2}$ yazılır:

$$\delta f_i = f_{i + \frac{1}{2}} - f_{i - \frac{1}{2}}$$

Bir kez daha uygulanınca yine 1, 2, 1 katsayıları çıkar:

$$\delta^2 f_i = f_{i+1} - 2f_i + f_{i-1}$$

Hoca alt uçtaki indisin nasıl değiştiğine baktı: Birinci derecede $i - \frac{1}{2}$, ikinci derecede $i - 1$, üçüncü derecede $i - \frac{3}{2}$, dördüncü derecede $i - 2$. Her derecede $\frac{1}{2}$ daha kayar. Ama bunu kullanmayacağımız için hoca çok kafaya takılmamasını söyledi.

> **Ders sonrası not:** Hoca dördüncü dereceyi anlatırken "$\frac{1}{2}$ azalarak gidecek" dedi. Python ile yapılan açılıma göre $\frac{1}{2}$'lik kayma, derece artarken alt ucun kaymasıdır. Aynı formülün içinde ardışık terimlerin indisi 1 fark eder. Örneğin $\delta^3 f_i = f_{i+\frac{3}{2}} - 3f_{i+\frac{1}{2}} + 3f_{i-\frac{1}{2}} - f_{i-\frac{3}{2}}$ (ara adım eklendi).

### 7.4 Operatörler Arasındaki İlişki

Üç operatör aynı fonksiyon değerlerinden gider, yalnızca indisler kayar. Birinci derecede $\Delta f_i = \nabla f_{i+1} = \delta f_{i+\frac{1}{2}}$'dir. $r$. derece için genelleştirilince:

$$\Delta^r f_i = \nabla^r f_{i+r} = \delta^r f_{i+\frac{r}{2}}$$

Hoca $r = 2$ örneğini verdi: $\Delta^2 f_i = \nabla^2 f_{i+2} = \delta^2 f_{i+1}$. Her üçü de $f_{i+2} - 2f_{i+1} + f_i$'yi verir.

> **Ders sonrası not:** Hoca önce "$\frac{r}{2} = \frac{2}{2}$, yani artı 1" dedi. Hemen sonra örneği yazarken "$i$ artı 1 bölü 2" dedi. Doğrusu $i + 1$'dir.

Hoca ileri farkın kullanılma nedenini de söyledi: İleri fark işlem yapmaya daha uygundur. Merkezi farkta ise hata yapmaya daha çok meyillidir.

<!-- BELİRSİZ: Altyazıda "merkezi fark çok hata yapmama meyili" diye geçiyor. Anlam, elle işlemde hataya açık olması gibi görünüyor. Kesme hatası anlamında söylenmediği varsayıldı, çünkü Ders 6'da merkezi farkın analitik türeve en yakın sonucu verdiği anlatılmıştı. -->

### 7.5 Genel İleri Fark Formülü

Hoca ileri farkta şu formülün unutulmamasını istedi:

$$\Delta^k f_0 = \sum_{i=0}^{k} (-1)^i \binom{k}{i} f_{k-i}, \qquad \binom{k}{i} = \frac{k!}{i!\,(k-i)!}$$

Formüldeki her parçanın görevi vardır:

- $(-1)^i$ işaretleri sağlar: $i = 0$ iken artı, $i = 1$ iken eksi, $i = 2$ iken artı, $i = 3$ iken eksi.
- $\binom{k}{i}$ binom katsayılarını verir.
- $f_{k-i}$ fonksiyonun aldığı değerleri gösterir.

**Örnek:** $k = 5$ için ileri fark formülünü yazınız.

- $i = 0$: $(-1)^0 \frac{5!}{0!\,5!} f_5 = f_5$
- $i = 1$: $(-1)^1 \frac{5!}{1!\,4!} f_4 = -5f_4$
- $i = 2$: $+10f_3$
- $i = 3$: $-10f_2$
- $i = 4$: $+5f_1$
- $i = 5$: $-f_0$

$$\Delta^5 f_0 = f_5 - 5f_4 + 10f_3 - 10f_2 + 5f_1 - f_0$$

Bu sonuç, hocanın "hileli yol" dediği kısa yoldan da aynı çıkar: İşaretler artı, eksi, artı, eksi, artı, eksi. Katsayılar 1, 5, 10, 10, 5, 1. İndisler 5'ten 0'a iner. Fonksiyonda $x_0, \ldots, x_5$ yerine konup değerler toplanınca sonuç bulunur.

> **Ders sonrası not:** Hoca bu örneği "5. türevi alınız" diye okudu ve sonucu 5. dereceden türev diye anlattı. Burada hesaplanan 5. ileri farktır, türevin kendisi değildir. Hoca yazımı da "$\Delta^5 f_5$" gibi okudu, formüle göre doğrusu $\Delta^5 f_0$'dır. Başlangıç noktası $f_i$ ise bütün indisler $i$ kadar kayar.

> **Ek bilgi (derste anlatılmadı):** Fark ile türev arasındaki bağ büyük olasılıkla $f^{(k)}(x_0) \approx \frac{\Delta^k f_0}{h^k}$ biçimindedir. Yani $h = 1$ alınırsa ikisi sayısal olarak yakın olur, ama yine de aynı şey değildir.

## 8. Fark Tabloları

Farkları tek tek formülle hesaplamak çok vakit alır. Fark tabloları bu işi kolaylaştırır.

### 8.1 İleri Fark Tablosu (Genel)

Elimizde $x$ değerleri (saatler) ve fonksiyon değerleri (odanın ısısı) olsun. Birinci dereceden ileri farklar için her satırda önündeki değerden kendisi çıkarılır: $\Delta f_0 = f_1 - f_0$, $\Delta f_1 = f_2 - f_1$ ve böyle devam eder. İkinci derece için aynı işlem bir önceki kolona uygulanır: $\Delta^2 f_0 = \Delta f_1 - \Delta f_0$. Tablo bir kolon sabitleninceye kadar sürer. Sabitlenmek, kolondaki değerlerin hepsinin aynı sayıyı vermesidir. Sonraki kolon zaten sıfır olur.

| $x$ | $f$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
|---|---|---|---|---|---|
| $x_0$ | $f_0$ | $\Delta f_0$ | $\Delta^2 f_0$ | $\Delta^3 f_0$ | $\Delta^4 f_0$ |
| $x_1$ | $f_1$ | $\Delta f_1$ | $\Delta^2 f_1$ | $\Delta^3 f_1$ | |
| $x_2$ | $f_2$ | $\Delta f_2$ | $\Delta^2 f_2$ | | |
| $x_3$ | $f_3$ | $\Delta f_3$ | | | |
| $x_4$ | $f_4$ | | | | |

Geri fark tablosunda aynı sayılar bulunur, yalnızca etiketler değişir: Birinci kolon $\nabla f_1, \ldots, \nabla f_4$, ikinci kolon $\nabla^2 f_2, \nabla^2 f_3, \nabla^2 f_4$, üçüncü kolon $\nabla^3 f_3, \nabla^3 f_4$, dördüncü kolon $\nabla^4 f_4$ olur. Merkezi fark tablosu daha karmaşıktır ve maliyetlidir, hoca bununla uğraşmadı.

### 8.2 Sayısal Örnek

**Soru:** $f(x) = x^3 - 3x$ fonksiyonu için $h = 1$ alarak $[-3, 2]$ aralığındaki ileri fark tablosunu çıkarınız.

$x$ değerleri $-3$, $-2$, $-1$, $0$, $1$, $2$'dir. Fonksiyonda yerine konunca örneğin $x = 0$ için $0$, $x = 1$ için $1 - 3 = -2$, $x = -1$ için $-1 + 3 = 2$ bulunur.

| $x_i$ | $f(x_i)$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
|---|---|---|---|---|---|
| $-3$ | $-18$ | $16$ | $-12$ | $6$ | $0$ |
| $-2$ | $-2$ | $4$ | $-6$ | $6$ | $0$ |
| $-1$ | $2$ | $-2$ | $0$ | $6$ | |
| $0$ | $0$ | $-2$ | $6$ | | |
| $1$ | $-2$ | $4$ | | | |
| $2$ | $2$ | | | | |

Birinci kolon: $-2 - (-18) = 16$, $2 - (-2) = 4$, $0 - 2 = -2$, $-2 - 0 = -2$, $2 - (-2) = 4$. Sabitlenmedi. İkinci kolon: $4 - 16 = -12$, $-2 - 4 = -6$, $-2 - (-2) = 0$, $4 - (-2) = 6$. Sabitlenmedi. Üçüncü kolon: $-6 - (-12) = 6$, $0 - (-6) = 6$, $6 - 0 = 6$. Sabitlendi.

Hoca burada durulabileceğini söyledi, çünkü sonraki kolonlar 0 olacaktır. Bu katsayılar sıfır olduğu için ne ile çarpılırsa çarpılsın sonuç sıfırdır, onlarla uğraşmanın anlamı yoktur. İşleme sabit bir sayıya ulaşılıncaya kadar devam edilir.

### 8.3 Aynı Tablo, Geri Farkla

Hoca, slaytta örneği olmayan geri farkı tahtada denedi. Önce karıştırdı, geriye hiç alışkın olmadığını söyledi. İkinci denemede her satırda üstteki değerden alttakini çıkardı:

- Birinci kolon: $-16$, $-4$, $2$, $2$, $-4$.
- İkinci kolon: $-12$, $-6$, $0$, $6$.

Hoca buradan ister ileri ister geri yapılsın aynı şeye gelindiğini, bu yüzden ileri farkın kullanıldığını söyledi.

> **Ders sonrası not:** Hocanın tahtadaki işlemi geri fark tanımıyla uyuşmuyor. $\nabla f_1 = f_1 - f_0 = -2 - (-18) = 16$'dır, $-16$ değildir. Üstteki değerden alttakini çıkarmak, tek dereceli kolonların işaretini ters çevirir. İkinci kolon bu yüzden aynı çıktı, aynı işlem sürdürülseydi üçüncü kolon $-6$ olurdu. Python hesabına göre doğru geri fark tablosu, ileri fark tablosuyla aynı sayıları içerir: Birinci kolon $16, 4, -2, -2, 4$, ikinci kolon $-12, -6, 0, 6$, üçüncü kolon $6, 6, 6$. Yalnızca etiketler değişir: $\nabla f_1 = \Delta f_0$, $\nabla^2 f_2 = \Delta^2 f_0$, $\nabla^3 f_3 = \Delta^3 f_0$. Bu, Bölüm 7.4'teki ilişkidir ve hocanın vardığı sonuç doğrudur.

## 9. Polinomlarda Sabit Fark

Tablonun neden sabitlendiğini hoca genel polinomla bağladı. $P_n(x)$, $a_0 x^n + \ldots$ biçiminde bir polinom olsun. Üçüncü dereceden bir polinom düşünelim: üsler 3, 2, 1 diye iner. Slaytta bu polinom için üçüncü derece ileri farkın değeri, $h = 1$ ve $a_0 = 1$ için sorulmuştu.

Bizim örneğimizde $f(x) = x^3 - 3x$'te $a_0 = 1$, $h = 1$'dir. Tablodaki $\Delta^3 f$ kolonunda gördüğümüz 6, işte bu sabit değerdir. Hoca bu değerlerin, gerçek enterpolasyonda kullanıldığında daha iyi anlaşılacağını söyledi.

<!-- BELİRSİZ: Slayttaki genel ifade altyazıda okunmadı. Kısa notta Δ³P₃ = 6a₀h³ diye geçiyor, hoca yalnız h = 1 ve a₀ = 1 durumundaki 6'yı söyledi. -->

> **Ek bilgi (derste anlatılmadı):** Genel ifade büyük olasılıkla $\Delta^n P_n = n!\,a_0 h^n$ biçimindedir. Örnekte $3! \cdot 1 \cdot 1^3 = 6$ eder. Bu değer sabit olduğu için bir sonraki farklar sıfırdır.

## 10. Fark Tablosunda Hatanın Yayılması

Hoca, tablodaki bir değerin yanlış olması durumunda ne olacağını sordu. Örneğin $-2$ yerine yanlışlıkla $-1$ yazılmış olsun. Bu hata tabloda nasıl ilerler?

Bir ölçüm örneğiyle düşünelim: $x$ değerleri saatler, $f$ değerleri odanın sıcaklıkları olsun. Saat $x_3$'teki sıcaklık yanlış görülmüş olsun, örneğin 18 yerine 13 yazılmış olsun. Yani $f_3$ yerine $f_3 + \varepsilon$ kullanılmış olsun. Yedi noktalı tabloda hata şöyle ilerler:

| $f$ | $\Delta$ | $\Delta^2$ | $\Delta^3$ | $\Delta^4$ | $\Delta^5$ | $\Delta^6$ |
|---|---|---|---|---|---|---|
| $f_0$ | $\Delta f_0$ | $\Delta^2 f_0$ | $\Delta^3 f_0 + \varepsilon$ | $\Delta^4 f_0 - 4\varepsilon$ | $\Delta^5 f_0 + 10\varepsilon$ | $\Delta^6 f_0 - 20\varepsilon$ |
| $f_1$ | $\Delta f_1$ | $\Delta^2 f_1 + \varepsilon$ | $\Delta^3 f_1 - 3\varepsilon$ | $\Delta^4 f_1 + 6\varepsilon$ | $\Delta^5 f_1 - 10\varepsilon$ | |
| $f_2$ | $\Delta f_2 + \varepsilon$ | $\Delta^2 f_2 - 2\varepsilon$ | $\Delta^3 f_2 + 3\varepsilon$ | $\Delta^4 f_2 - 4\varepsilon$ | | |
| $f_3 + \varepsilon$ | $\Delta f_3 - \varepsilon$ | $\Delta^2 f_3 + \varepsilon$ | $\Delta^3 f_3 - \varepsilon$ | | | |
| $f_4$ | $\Delta f_4$ | $\Delta^2 f_4$ | | | | |
| $f_5$ | $\Delta f_5$ | | | | | |
| $f_6$ | | | | | | |

Adım adım gidelim:

- **Birinci derece:** $\Delta f_2$ hesaplanırken $(f_3 + \varepsilon) - f_2$ yazılır, yani $+\varepsilon$ gelir. $\Delta f_3$ hesaplanırken $f_4 - (f_3 + \varepsilon)$ yazılır, yani $-\varepsilon$ gelir.
- **İkinci derece:** Hatalı kolonlardan farklar alınır: $+\varepsilon$, sonra $-\varepsilon - \varepsilon = -2\varepsilon$, sonra $+\varepsilon$.
- **Üçüncü derece:** $+\varepsilon$, $-3\varepsilon$, $+3\varepsilon$, $-\varepsilon$.
- **Dördüncü derece:** $-4\varepsilon$, $+6\varepsilon$, $-4\varepsilon$.
- **Beşinci derece:** $+10\varepsilon$, $-10\varepsilon$.
- **Altıncı derece:** $-20\varepsilon$.

Hatanın katsayılarına bakınca yine binom açılımı görülür. Komşu katsayılar toplanarak gider: 1 ile 2 toplanır 3, 3 ile 3 toplanır 6, 4 ile 6 toplanır 10, 10 ile 10 toplanır 20. İşaretler de sırayla değişir.

Burada sıfırlanması gereken yer, hata yüzünden sıfırlanmaz. İlk baştaki hata $\varepsilon = 0.1$ olsa bile 20 ile çarpılıp son kolona eklenince sıfırdan belirgin biçimde farklı bir değer çıkar: $20 \cdot 0.1 = 2$ (ara adım eklendi).

> **Hocanın vurgusu:** Son farklarda değer sıfıra gitmiyorsa, bir yerde sabitlenmiyorsa bir ölçümde hata yapılmıştır. Çok küçük değerler (hoca "sıfır sıfır sıfır bir" gibi bir örnek verdi) sıfır kabul edilebilir, bu bir hata payıdır. Ama sonuç 5 ya da 20 gibi sıfırdan çok büyük bir sayıysa mutlaka bir yerde hata vardır.

> **Ek bilgi (derste anlatılmadı):** Bu sınama büyük olasılıkla verinin düşük dereceli bir polinoma yakın davrandığı durumlar için anlamlıdır. Polinom olmayan bir fonksiyonun farkları hatasız ölçümde de tam olarak sıfıra inmeyebilir.

Son olarak hoca üç farkı bir cümleyle özetledi: İleri farkta önündeki değerden kendisi, geri farkta kendisinden gerisi çıkarılır. Merkezi farkta ise önündeki ve arkasındaki değerlerin orta değerlerinin farkı alınır. Başka bir şey yoktur.

Bu değerler neden gerekli? Enterpolasyon formülündeki katsayılar bu farklardır. Bunları uzun uzun formüllerle hesaplamak yerine fark tablosundan alıp denklemde kullanacağız.

## Dersin Toparlaması

Dersin ilk yarısı sayısal integralin tekrarıydı. Trapez, Simpson 1/3 ve Simpson 3/8 kuralları hatırlatıldı. Sınıf alıştırması, alan sorularında yöntemden önce şeklin çizilmesi gerektiğini gösterdi: Bölge çizilir, bilinen alanlar görülür, kalan parçalar integralle bulunup eklenir ya da çıkarılır. "$Ox$ ile sınırlı" gibi ifadeler bölgeyi belirlediği için önemlidir, kökleri geçen bir bölge de parçalara ayrılır. İki katlı integral yeni bir yöntem gerektirmez. İç integral bir $g(x)$ kutusu sayılır, her $x_i$ için tek katlı integral çözülür, sonuçlar dış integralde kullanılır.

İkinci yarıda sonlu farklar anlatıldı. $\Delta$, $\nabla$, $\delta$, $\mu$ ve $E$ operatörleri tanımlandı, yüksek dereceli farkların binom katsayılarıyla yazılabildiği görüldü. Fark tablosu bir kolon sabitlenince durur. Üçüncü dereceden polinom örneğinde üçüncü fark 6'da sabitlendi. Tablodaki tek bir hata ise binom katsayılarıyla büyüyerek yayılır. Bu yüzden sıfırlanmayan bir kolon, verilerde hata olduğunu gösterir. Gelecek derste enterpolasyona başlanacak, fark tablolarındaki değerler Gregory-Newton formülünün katsayıları olarak kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
