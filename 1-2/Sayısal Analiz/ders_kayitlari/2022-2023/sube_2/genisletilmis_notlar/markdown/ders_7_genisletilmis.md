# Ders 7 Genişletilmiş Notu: Simpson Yöntemleri ve İki Katlı İntegralin Sayısal Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Sayısal Analizde Kullanılan İşlemler
- 2. Trapez Yönteminin Tekrarı
- 3. Simpson 1/3 Kuralı: Tek Parabol
- 4. Bileşik Simpson 1/3 Kuralı
- 5. Simpson 1/3 Örnekleri
- 6. Simpson 3/8 Kuralı
- 7. İki Katlı İntegralin Sayısal Çözümü
- 8. Simpson'da Parça Sayısı Üzerine Soru
- Örnek Sorular

## 1. Giriş: Sayısal Analizde Kullanılan İşlemler

Dersin başında hesap makinesi seçimi üzerine konuşulurken hoca, sayısal analizde yapılan işlemlerin niteliğine değindi. Bu derste kullanılan algoritmalar genel olarak toplama, çıkarma, çarpma ve bölmeden ibarettir. Bir fonksiyonun integrali alınacaksa integral kurallarıyla alınmaz; daha basit yollarla, yaklaşım yöntemleriyle hesaplanır.

Hoca, doğrusal denklem takımlarının başka derslerde nasıl karşınıza çıktığını da bir örnekle anlattı. Devre teorisinde çevre akımı (mesh current) ve düğüm (node) analizi yapılırken bir devrenin farklı kollarından geçen akımlar denklem olarak yazılır. Dört bilinmeyenli dört denklem elde edilir ve bu denklem takımı çözülerek akımlar bulunur. Bu, önceki derslerde görülen doğrusal denklem sistemlerinin uygulamadaki karşılığıdır.

## 2. Trapez Yönteminin Tekrarı

Önceki derste sayısal integrale giriş yapılmış ve trapez (yamuk) yönteminin çok basit bir yöntem olduğu söylenmişti. Yöntem şöyle işler:

- $[a,b]$ aralığı $h$ genişlikli parçalara bölünür ve fonksiyonun bu noktalardaki görüntü değerleri bir diziye yerleştirilir.
- Dizinin ilk ve son değeri bir kez, aradaki bütün değerler iki kez alınır.
- Bu toplam $h/2$ ile çarpılır.

$$\int_a^b f(x)\,dx \approx \frac{h}{2}\left[y_0 + y_n + 2\sum_{i=1}^{n-1} y_i\right]$$

Trapez yöntemi basit olmasına rağmen iyi sonuçlar verir. Bu derste ondan biraz daha karmaşık olan Simpson yöntemleri ele alındı.

## 3. Simpson 1/3 Kuralı: Tek Parabol

### 3.1 Fikir

Simpson kuralı iki biçimde verilir: 1/3 kuralı ve 3/8 kuralı. Herhangi bir $f(x)$ fonksiyonunun $a$ ile $b$ arasındaki integralini almak yine bir alan hesabı yapmaktır. Trapezde iki nokta arasına bir doğru çizilir. Simpson 1/3 kuralında ise "bu noktalardan geçen ikinci dereceden bir eğri çizsek hatayı daha da azaltabilir miyiz?" sorusundan yola çıkılır. Bunun için iki uç noktaya ek olarak bir üçüncü nokta gerekir.

Orijinal fonksiyon ne olursa olsun, yaklaşım için şu basit polinom kullanılır (ekrandan, 00:15:00):

$$f(x) = ax^2 + bx + c$$

Bu polinomun integrali kolaydır:

$$S = \int (ax^2+bx+c)\,dx = a\frac{x^3}{3} + b\frac{x^2}{2} + cx$$

### 3.2 Sınırları $-h$ ve $h$ seçmek

Sınırlar $a$ ve $b$ olarak bırakılırsa ifade karmaşıklaşır. Bunun yerine aralık, merkezi sıfırda olacak biçimde $a=-h$, $b=h$ alınır. Bir öğrenci $h$'nin nereden geldiğini sordu.

**Soru:** Bu $h$ nereden geldi? **Cevap:** Yapılan şey yalnızca $a$ ile $b$ arasını $h$ cinsinden ifade etmektir. Örneğin aralık $0$ ile $1$ arasıysa orta nokta $0{,}5$ olur ve bu değerler $h$'ye dönüştürülebilir. Değişkenlerin yerine $a$ ve $b$ verildiğinde daha karmaşık bir ifade çıkar, $h$'ye çevrildiğinde daha basit bir denklem elde edilir.

Sınırlar yerine konunca (ekrandan, 00:15:00):

$$S = a\frac{h^3}{3} + b\frac{h^2}{2} + ch - \left[-a\frac{h^3}{3} + b\frac{h^2}{2} - ch\right]$$

Eksiler artıya döner, $b\frac{h^2}{2}$ terimleri birbirini götürür ve $ch$ iki kez gelir:

$$S = \frac{2}{3}ah^3 + 2ch = \frac{h}{3}\left(2ah^2 + 6c\right)$$

### 3.3 Katsayıları fonksiyon değerlerinden bulmak

Polinomun katsayıları bilinmez, ama fonksiyon elimizdedir. Fonksiyonun üç noktadaki değeri hesaplanarak katsayılar bulunur. Üç bilinmeyen ($a$, $b$, $c$) olduğundan üç denklem gerekir:

- $x=-h$ için: $y_0 = ah^2 - bh + c$
- $x=0$ için: $y_1 = c$ (sıfır koymak doğrudan sabit terimi verir)
- $x=h$ için: $y_2 = ah^2 + bh + c$

Birinci ve üçüncü denklem taraf tarafa toplanınca $y_0 + y_2 = 2ah^2 + 2c$ olur. $c=y_1$ yerine konunca

$$2ah^2 = y_0 - 2y_1 + y_2$$

bulunur. Bunu $S$ ifadesine yerleştirince:

$$S = \frac{h}{3}\left(y_0 - 2y_1 + y_2 + 6y_1\right) = \frac{h}{3}\left(y_0 + 4y_1 + y_2\right)$$

Burada $y_0$ integralin alt sınırındaki değer, $y_1$ tam ortadaki (sıfırdaki) değer, $y_2$ ise üst sınırdaki değerdir. Kuralın adındaki "1/3" bu formüldeki $h/3$'ten gelir.

Hoca bir öğrencinin "bir daha anlatabilir misiniz" isteği üzerine aynı akışı özetledi: $a$ ile $b$ arasında integral almak için bir parabol uydurulur. Parabolün $a$, $b$, $c$ katsayıları bulunursa integral hesabı çok basittir, çünkü doğrudan $x$ yerine sınırlar konur. Katsayılar, sınırlar $-h$ ve $+h$ alınıp fonksiyon değerleri yerine konarak bulunur ve sonuç $\frac{h}{3}(y_0+4y_1+y_2)$ formülüne varır.

## 4. Bileşik Simpson 1/3 Kuralı

### 4.1 Aralığı birden fazla parabole bölmek

Tek parabolle yetinmek yerine, trapezde olduğu gibi $[a,b]$ aralığı daha küçük parçalara bölünebilir. Örneğin $a$'dan $b$'ye 10 parçaya bölünürse ara noktalar $a+h$, $a+2h$, ..., $a+9h$ olur. Her iki parçaya bir parabol uydurulur ve her parabolün altındaki alan ($S_1$, $S_2$, ...) ayrı hesaplanıp toplanır. Bu, daha az hata içeren, gerçeğe daha yakın bir alan değeri verir.

Önemli gözlem şudur: bir parabolün üst sınırı, bir sonraki parabolün alt sınırıdır. Örneğin $y_2$, birinci parabolün en uç noktası iken ikinci parabolün başlangıç noktasıdır. Fonksiyon ne kadar karmaşık olursa olsun, bu noktalardaki değerlerini hesaplamak kolaydır.

Her parçanın alanı (ekrandan, 00:20:00):

$$S_1 = \frac{h}{3}(y_0 + 4y_1 + y_2)$$
$$S_2 = \frac{h}{3}(y_2 + 4y_3 + y_4)$$
$$\vdots$$
$$S_n = \frac{h}{3}(y_{2n-2} + 4y_{2n-1} + y_{2n})$$

İntegralin değeri bunların toplamıdır: $S=\sum S_i$.

### 4.2 Toplamadaki katsayı düzeni

Hoca üç parabol için toplamı tahtada yazdı (ekrandan, 00:25:00):

$$\frac{h}{3}\left[(y_0 + y_6) + 4y_1 + 4y_3 + 4y_5 + 2y_2 + 2y_4\right]$$

Baştaki $y_0$ ve sondaki $y_6$ birer kez geçer. Tek indisliler ($y_1$, $y_3$, $y_5$) dörder kez geçer. Aradaki çift indisliler ($y_2$, $y_4$) iki parabolde ortak olduğu için iki kez geçer. Bir dördüncü parabol ($y_6 + 4y_7 + y_8$) eklenirse $y_6$ artık son değer olmaz, o da iki kat alınan bir ara çifte dönüşür. Kısaca:

- Baş ve son değer: bir kat.
- Tek indisli değerler: dört kat.
- Baş ve son hariç çift indisli değerler: iki kat.
- Toplam $h/3$ ile çarpılır.

### 4.3 Genel formül

Simpson formülünde $h=(x_n-x_0)/n$ alınarak (burada $x_0=a$, $x_n=b$) toplam şu hale gelir (ekrandan, 00:30:00):

$$S = \frac{h}{3}\left(y_0 + 4y_1 + 2y_2 + 4y_3 + 2y_4 + \dots + 2y_{2n-2} + 4y_{2n-1} + y_{2n}\right)$$

$y_0$ ve son değer sabit olduğu için toplam sembolünün dışına çıkar. Sonuç formülü (ekrandan, 00:30:00):

$$S = \frac{h}{3}\left[f(x_0) + f(x_n) + 4\sum_{k=1,3,5}^{n-1} f(x_0 + k h) + 2\sum_{i=2,4,6}^{n-2} f(x_0 + i h)\right]$$

Slaytta ayrıca şu uyarı yer alır: Simpson yönteminde çubuklar ikişer ikişer alındığından aralık sayısı çift olmalıdır (ekrandan, 00:30:00). Hoca da genellikle $n$'nin çift seçildiğini, çünkü son elemanın $y_{2n}$ gibi çift indisli olması gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Slayttaki iki gösterimde $n$ farklı anlamda kullanılıyor. $h=(x_n-x_0)/n$ ve sonuç formülünde $n$ alt aralık sayısıdır; $S_1,\dots,S_n$ listesinde ise $n$ parabol sayısıdır ve alt aralık sayısı $2n$ olur. Sonuç formülünde $n$'nin çift olması gerekir.

## 5. Simpson 1/3 Örnekleri

### 5.1 $y=x^3$ eğrisiyle sınırlı alan

Önceki derste bir öğrenci, alan negatif çıktığında ne yapılacağını sormuştu. Bu örnek o soruya benzer ve Simpson 1/3 ile çözüldü.

Soru: $y=x^3$ eğrisinin $x=-1$, $x=2$ ve $Ox$ ekseni ile sınırlı bölgesinin alanı nedir (ekrandan, 00:35:00)?

Gerçek alan iki parçadan oluşur: $S_1$, $-1$'den $0$'a kadar eksen altında kalan parça; $S_2$, $0$'dan $2$'ye kadar eksen üstündeki parça. $S_1$'de integral negatif çıkacağından sonuç eksiyle çarpılır.

**$S_1$: $[-1, 0]$, $n=4$.** $h = (0-(-1))/4 = 0{,}25$. $x$ dizisi: $-1$, $-0{,}75$, $-0{,}5$, $-0{,}25$, $0$. Hoca bunların C'de bir dizi gibi kodlanacağını, $y$ dizisinin de fonksiyonda yerine koyarak doldurulacağını söyledi. Değerler (python ile hesaplandı): $y_0=-1$, $y_1=-0{,}421875$, $y_2=-0{,}125$, $y_3=-0{,}015625$, $y_4=0$.

$$S_1 = \frac{0{,}25}{3}\left[(-1) + 0 + 2(-0{,}125) + 4(-0{,}421875 - 0{,}015625)\right] = \frac{0{,}25}{3}(-3) = -0{,}25$$

Alan $0{,}25$ olur. Analitik kontrol: $\int_{-1}^{0}x^3dx = \left.\frac{x^4}{4}\right|_{-1}^{0} = -\frac14$, eksiyle çarpılınca $\frac14$.

> **Ders sonrası not:** Hoca bu aralık için yaklaşık $0{,}24$ bulunduğunu ve $0{,}25$'e yuvarlandığını söyledi. Python ile kontrol edildiğinde Simpson 1/3 burada tam $-0{,}25$ verir; Simpson 1/3 üçüncü dereceden polinomlar için hatasızdır. $0{,}24$ büyük olasılıkla ara değerlerin yuvarlanmasından ya da sözlü bir kaymadan kaynaklanır.

**$S_2$: $[0, 2]$, $n=4$.** $h$ soruda verilmez, sınırlardan üretilir: $h = (2-0)/4 = 0{,}5$. $x$ dizisi: $0$, $0{,}5$, $1$, $1{,}5$, $2$. Değerler: $0$, $0{,}125$, $1$, $3{,}375$, $8$ (python ile hesaplandı).

$$S_2 = \frac{0{,}5}{3}\left[0 + 8 + 2(1) + 4(0{,}125 + 3{,}375)\right] = \frac{0{,}5}{3}(24) = 4$$

Analitik: $\left.\frac{x^4}{4}\right|_0^2 = \frac{16}{4} = 4$. Hoca burada sonucun yüzde yüz doğrulukla bulunduğunu vurguladı.

**Toplam alan:** $S_1 + S_2 = 0{,}25 + 4 = 4{,}25$ birim kare.

Analitik çözümde $\int_{-1}^{2}x^3dx$ doğrudan alınırsa $4 - \frac14$ çıkar; alan için $-1$'deki kısmın eksiyle çarpılıp ayrı eklenmesi gerekir. Sayısal çözümde ise aynı sonuç döngülerle, toplama, çıkarma, çarpma ve bölmeyle bulunmuş olur.

> **Hocanın vurgusu:** Simpson kuralında integral hesabı yoktur. Sınavda bu tür sorularda integral hesabı yapılmamalıdır. Analitik integral yalnızca gerçek sonuçla karşılaştırmak, yani mutlak hatayı bulmak için alınır; o da $x^3$ gibi basit bir fonksiyonsa yapılabilir.

Hoca, $x^3$ fonksiyonunun burada ikinci dereceden fonksiyonlara indirgenerek çözüldüğünü, daha karmaşık bir fonksiyonun da aynı yolla çözülebileceğini ekledi.

### 5.2 $(x^2-1)(x+2)$ fonksiyonu: trapez ve Simpson karşılaştırması

Soru: $\int_{-2}^{-1}(x^2-1)(x+2)\,dx$ integralini $n=4$ ile önce trapez, sonra Simpson 1/3 yöntemiyle hesaplayınız (ekrandan, 00:40:00).

Analitik çözümde $(x^2-1)(x+2) = x^3 + 2x^2 - x - 2$ olur ve sonuç yaklaşık $0{,}41$'dir. Hoca slayttaki bir sınır yazımını düzeltti: istenen bölge $x$ ekseninin üstünde kalan $[-2,-1]$ aralığıdır, üst sınır $-1$ olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Tam değer $\left[\frac{x^4}{4} + \frac{2x^3}{3} - \frac{x^2}{2} - 2x\right]_{-2}^{-1} = \frac{5}{12} \approx 0{,}4167$'dir (python ile kontrol edildi).

$h = (-1-(-2))/4 = 0{,}25$. Tablo (ekrandan, 00:40:00):

| | $x$ | $f(x)$ |
|---|---|---|
| $x_0$ | $-2$ | $0$ |
| $x_1$ | $-1{,}75$ | $0{,}5156$ |
| $x_2$ | $-1{,}50$ | $0{,}625$ |
| $x_3$ | $-1{,}25$ | $0{,}4218$ |
| $x_4$ | $-1$ | $0$ |

**Trapez:** İlk ve son değer bir kat, aradakiler iki kat, toplam $h/2$ ile çarpılır. Slaytta aradakilerin iki katı $h/2$ ile çarpılmak yerine doğrudan $h$ ile çarpılmış; sonuç değişmez:

$$S_T = \frac{0{,}25}{2}(0+0) + 0{,}25(0{,}5156 + 0{,}625 + 0{,}4218) \approx 0{,}3906$$

Mutlak hata yaklaşık $0{,}4167 - 0{,}3906 \approx 0{,}026$'dır (python ile hesaplandı; derste hata değeri ekranda gösterildi).

**Simpson 1/3:** Tablo değişmez. Birincinin ve sonuncunun kendisi, teklerin ($x_1$, $x_3$) dört katı, çiftin ($x_2$) iki katı alınır, dışarıda $h/3$ vardır (ekrandan, 00:40:00):

$$S_S = \frac{0{,}25}{3}\left[(0+0) + 2\cdot 0{,}625 + 4(0{,}4218 + 0{,}5156)\right] = \frac{0{,}25}{3}(4{,}9996) \approx 0{,}4166 \text{ br}^2$$

> **Ders sonrası not:** Slayttaki işlem satırında $f(x_1)$ değeri $0{,}0156$ diye yazılmış. Tablodaki değer $0{,}5156$'dır ve $0{,}4166$ sonucu ancak $0{,}5156$ ile çıkar.

Simpson sonucu, trapezle bulunandan çok daha az hatalıdır. Hoca, $n$ sekiz ya da on gibi artırılırsa neredeyse sıfır hatayla sonuca ulaşılacağını söyledi.

## 6. Simpson 3/8 Kuralı

### 6.1 Fikir ve formül

Simpson 3/8 kuralı işi biraz daha ileri götürür: $[a,b]$ aralığında ikinci dereceden bir fonksiyon yerine üçüncü dereceden bir polinom yazılır (ekrandan, 00:45:00):

$$f_3(x) = ax^3 + bx^2 + cx + d$$

Bunun integrali $a\frac{x^4}{4} + b\frac{x^3}{3} + c\frac{x^2}{2} + dx$ olur ve alanı hesaplamak zor değildir. Katsayıların bulunması 1/3 kuralındaki mantıkla aynıdır; hoca ispatına girmedi ve formülü bilmenin yeterli olduğunu söyledi. Dört bilinmeyen ($a$, $b$, $c$, $d$) için dört denklem, yani dört nokta gerekir. Bu yüzden $[a,b]$ üç eşit parçaya bölünür: $a$, $x_1=a+\frac{b-a}{3}$, $x_2=a+2\frac{b-a}{3}$ ve $b$ (ekrandan, 00:45:00).

$$\int_a^b f(x)\,dx \approx \int_a^b f_3(x)\,dx = \frac{b-a}{8}\left[f(a) + 3f(x_1) + 3f(x_2) + f(b)\right]$$

İlk ve son noktanın kendisi, aradaki iki noktanın üç katı alınır ve $(b-a)/8$ ile çarpılır. Paydadaki 8, katsayıların bulunması sırasındaki integral hesabından gelir.

> **Ders sonrası not:** Hoca $h$ için ekrana $h=(b-a)/4$ yazdı ve "dört parçaya böleceğiz" dedi. Dört nokta üç parça oluşturur; doğrusu $h=(b-a)/3$'tür. Slayttaki $x_1$ ve $x_2$ ifadeleri de üç eşit parçayı gösterir.

### 6.2 Aralığı ikiye bölmek ($n=2$)

Yukarıdaki formül $[a,b]$ aralığında tek bir üçüncü dereceden polinomla bulunan sonuçtur ($n=1$). Aralık kendi içinde birden fazla polinomla değerlendirilirse sonuç gerçeğe daha çok yaklaşır. $n=2$ için alan, $a$'dan $\frac{a+b}{2}$'ye ve $\frac{a+b}{2}$'den $b$'ye iki integralin toplamıdır (ekrandan, 00:45:00):

$$\int_a^{\frac{a+b}{2}} f(x)\,dx + \int_{\frac{a+b}{2}}^{b} f(x)\,dx$$

Birinci parçada $b$ yerine $\frac{a+b}{2}$, ikinci parçada $a$ yerine $\frac{a+b}{2}$ konur ve formül her parçaya ayrı uygulanır. Örneğin birinci parçanın çarpanı $\frac{(a+b)/2 - a}{8}$ olur.

### 6.3 Örnek: $\int_0^6 \frac{1}{1+x^4}dx$

Soru: $\int_0^6 \frac{1}{1+x^4}dx$ integralini Simpson 3/8 kuralıyla $n=1$ ve $n=2$ için hesaplayınız (ekrandan, 00:50:00).

**$n=1$:** Sıfırdan altıya tek bir polinom varmış gibi düşünülür. $h = (6-0)/3 = 2$, gereken noktalar $0$, $2$, $4$, $6$:

- $f(0) = 1$
- $f(2) = \frac{1}{17}$
- $f(4) = \frac{1}{257}$
- $f(6) = \frac{1}{1297}$

$$S \approx \frac{6}{8}\left[1 + 3\cdot\frac{1}{17} + 3\cdot\frac{1}{257} + \frac{1}{1297}\right] \approx 0{,}8917$$

**$n=2$:** İntegral $[0,3]$ ve $[3,6]$ olarak ikiye ayrılır. Her parçada $h=(3-0)/3=1$, yani birer artışla noktalar alınır (ekrandan, 00:50:00):

$$\int_0^3 \approx 3\cdot\frac{f(0) + 3f(1) + 3f(2) + f(3)}{8} = 3\cdot\frac{1 + 3\cdot\frac12 + 3\cdot\frac{1}{17} + \frac{1}{82}}{8} \approx 1{,}0082$$

$$\int_3^6 \approx 3\cdot\frac{f(3) + 3f(4) + 3f(5) + f(6)}{8} = 3\cdot\frac{\frac{1}{82} + 3\cdot\frac{1}{257} + 3\cdot\frac{1}{626} + \frac{1}{1297}}{8} \approx 0{,}0110$$

$$S \approx 1{,}0082 + 0{,}0110 \approx 1{,}0192$$

Hoca bu hesapların hep dizilerle yapılacağını, yalnızca fonksiyon değerini hesaplayan bir yardımcı fonksiyona (evaluation) ihtiyaç olduğunu belirtti. $n=2$ sonucu gerçek sonuca $n=1$'e göre çok daha yakındır.

> **Ders sonrası not:** Gerçek değer derste hesaplanmadı. Çok ince bölmeli sayısal hesapla (python, Simpson 1/3, 6000 parça) $\int_0^6 \frac{dx}{1+x^4} \approx 1{,}1092$ bulundu. Bu derste bulunan değerler doğrulandı: $n=1$ için $0{,}8917$, $n=2$ için $1{,}0192$.

## 7. İki Katlı İntegralin Sayısal Çözümü

### 7.1 Kavram

Buraya kadar kullanılan fonksiyonlar tek boyutluydu: bağımsız değişken $x$, ona karşılık $y=f(x)$. Gerçek hayatta integral hesaplarında her zaman tek değişken olmak zorunda değildir; iki ve üç boyutlu durumlar da vardır. İki boyutlu bir sistemin ($x$ ve $y$) üçüncü boyutta bir görüntüsü olur: $z=f(x,y)$. Tek değişkenli integral bir eğrinin altında kalan alanı verirken, iki değişkenli integral bir düzlemin (yüzeyin) altında kalan kısmı verir. Bu yüzden çift katlı integral gerekir: $f(x,y)$ hem $dx$'e hem $dy$'ye göre, yatay ve düşey eksen boyunca $a$, $b$, $c$, $d$ gibi sınırlarla entegre edilir. Buna iki katlı integralin sayısal çözümü denir.

Sayısal çözümde iki katlı integral tek katlı integrallere indirgenir. Simpson ya da trapez, hangisi kullanılırsa kullanılsın, iç integral ve dış integral için ayrı tablolar oluşturulur.

### 7.2 Örnek

Soru (ekrandan, 01:10:00):

$$I = \int_2^3 \int_x^{2x^3} (x^2 + y)\,dy\,dx$$

Önce içteki integral $y$'ye göre alınır; bu sırada $x$ sabit gibi davranır. İç integralin sonucu $x$'e bağlı bir ifadedir, buna $g(x)$ denir:

$$I = \int_2^3 g(x)\,dx, \qquad g(x) = \int_x^{2x^3}(x^2+y)\,dy$$

**Dış integralin tablosu:** $n=4$, $h=(b-a)/n=(3-2)/4=0{,}25$. $x$ değerleri $x_0=2$, $x_1=2{,}25$, $x_2=2{,}5$, $x_3=2{,}75$, $x_4=3$; her biri için bir $g_i$ hesaplanacaktır (ekrandan, 01:10:00).

**1. adım, $x_0=2$ için:** İç integralin sınırları $x_0=2$ ile $2x_0^3=16$ olur:

$$g_0 = \int_2^{16}(x_0^2 + y)\,dy = \int_2^{16}(4+y)\,dy$$

Bu aralık da 4 parçaya bölünür: $h=(16-2)/4=3{,}5$. $y$ değerleri $2$; $5{,}5$; $9$; $12{,}5$; $16$. Fonksiyon değerleri $x_0^2=4$'e $y$ eklenerek bulunur: $4+2=6$, $4+5{,}5=9{,}5$, $4+9=13$, $4+12{,}5=16{,}5$, $4+16=20$ (ekrandan, 01:10:00).

| | $y$ | $f(y)$ |
|---|---|---|
| $y_0$ | $2$ | $6$ |
| $y_1$ | $5{,}5$ | $9{,}5$ |
| $y_2$ | $9$ | $13$ |
| $y_3$ | $12{,}5$ | $16{,}5$ |
| $y_4$ | $16$ | $20$ |

Hoca sınıfa bu adımda hangi yöntemin uygulandığını sordu: teklerin dört katı, çiftin iki katı alınmıştı. Cevap Simpson 1/3'tü (ekrandan, 01:10:00):

$$g_0 = \frac{3{,}5}{3}\left[(6+20) + 2\cdot 13 + 4(9{,}5 + 16{,}5)\right] = 182$$

**Diğer $x$ değerleri:** Aynı işlem $x_1=2{,}25$ için yapılır: iç sınırlar $2{,}25$ ile $2\cdot 2{,}25^3 \approx 22{,}78$, iç adım $h\approx 5{,}13$. $x_2=2{,}5$ için sınırlar $2{,}5$ ile $31{,}25$, adım $h\approx 7{,}19$. $x_4=3$ için sınırlar $3$ ile $54$'tür. Üst sınır $2x^3$ büyüdükçe iç adım genişliği de sürekli artar. Bu yapı iç içe iki `for` döngüsü gibidir: dış döngü $x_i$ üzerinde, iç döngü her $x_i$ için $y$ üzerinde döner.

Python ile Simpson 1/3 uygulanarak bulunan iç sonuçlar:

| $i$ | $x_i$ | iç aralık | iç $h$ | $g_i$ |
|---|---|---|---|---|
| 0 | $2$ | $[2;\,16]$ | $3{,}5$ | $182$ |
| 1 | $2{,}25$ | $[2{,}25;\,22{,}78]$ | $5{,}13$ | $360{,}90$ |
| 2 | $2{,}5$ | $[2{,}5;\,31{,}25]$ | $7{,}19$ | $664{,}84$ |
| 3 | $2{,}75$ | $[2{,}75;\,41{,}59]$ | $9{,}71$ | $1155{,}0$ |
| 4 | $3$ | $[3;\,54]$ | $12{,}75$ | $1912{,}5$ |

Derste $g_0=182$, $g_2\approx 665$ ve $g_4\approx 1912$ değerleri sözlü olarak da geçti.

<!-- BELİRSİZ: g1..g4 ve sonuç slaytlarının karesi yok. Altyazıda g1 için "360.417", dış Simpson sonucu için "790.450", analitik sonuç için "790.55" duyuluyor; aşağıdaki değerler python ile hesaplandı. -->

**2. adım, dış integral:** İç integrallerin her biri ayrı ayrı Simpson ile bulunduktan sonra, elde edilen $g_i$ değerlerine bir kez daha Simpson uygulanır; birincisi $dy$'nin, ikincisi $dx$'in Simpson'ıdır. Baştaki ve sondaki kendisi, teklerin dört katı, çiftin iki katı alınır ve $h/3=0{,}25/3$ ile çarpılır:

$$I \approx \frac{0{,}25}{3}\left[(g_0 + g_4) + 4(g_1 + g_3) + 2g_2\right] = \frac{0{,}25}{3}\left[(182 + 1912{,}5) + 4(360{,}90 + 1155{,}0) + 2\cdot 664{,}84\right] \approx 790{,}65$$

### 7.3 Analitik kontrol

Hoca analitik çözümü hızlıca gösterdi. İçteki integral, $x$ sabit tutularak:

$$\int (x^2 + y)\,dy = x^2 y + \frac{y^2}{2}$$

Sınırlar $2x^3$ ve $x$ yerine konur. Hoca önce $x^2\cdot 2x^3$ terimini $2x^6$ yazdı; bir öğrenci $x^5$ olması gerektiğini söyledi ve hoca düzeltti. Doğru sonuç:

$$g(x) = 2x^5 + \frac{(2x^3)^2}{2} - x^3 - \frac{x^2}{2} = 2x^5 + 2x^6 - x^3 - \frac{x^2}{2}$$

Ardından $dx$'e göre integral alınıp $3$ ve $2$ sınırları yerine konur:

$$I = \left[\frac{x^6}{3} + \frac{2x^7}{7} - \frac{x^4}{4} - \frac{x^3}{6}\right]_2^3 \approx 790{,}54$$

> **Ders sonrası not:** Hoca ekrana ikinci terimi $4x^6$ yazdı ve dış integralde $\frac{4x^7}{7}$ dedi. $(2x^3)^2/2 = 2x^6$ olduğundan doğrusu $2x^6$ ve $\frac{2x^7}{7}$'dir. Hoca sonucu hesaplamayı öğrencilere bıraktı; python ile doğru ifadeden bulunan değer yaklaşık $790{,}54$'tür, Simpson sonucu ($\approx 790{,}65$) buna çok yakındır.

Üç katlı bir integralde iç içe üç döngü olur ve bu böyle uzar gider. Hoca, bu ders için mantığı öğrenmenin yeterli olduğunu söyledi.

## 8. Simpson'da Parça Sayısı Üzerine Soru

**Soru:** $n$ sayısını çift seçmek iyi olur dendi. Bu bir zorunluluk mu, yoksa tek de olabilir mi? **Cevap:** Hoca Simpson 1/3 üzerinden açıkladı: buradaki $n$ aslında kaç tane alan ($S_1$, $S_2$, $S_3$, ...) olacağıyla ilgilidir. $n=3$ almak aralığı üç parçaya bölmek demektir ve her parça kendi içinde yine iki alt parçaya bölünür; bu durumda bir sıkıntı olmaz, yalnızca $h$ hesaplarında virgüllü sayılar artabilir. Geleneksel olarak çift sayı alınır ama kesin bir kayıt yoktur. $n$ ne olursa olsun Simpson 1/3'te baştaki ve sondaki değer bir kat alınır ve $2n$'e kadar bir genişletme yapılmış olur.

> **Ders sonrası not:** Hocanın cevabı $n$'yi parabol sayısı olarak ele alıyor; bu sayı tek de olabilir. Alt aralık sayısı ise ($2n$) her zaman çift olmalıdır. Slayttaki "aralık sayısı ÇİFT olmalıdır" uyarısı ve $h=(x_n-x_0)/n$ ile yazılan sonuç formülü alt aralık sayısına göredir; bu formülü kullanırken $n$ çift seçilmelidir.

> **Hocanın vurgusu:** Bir integral sorusunda mutlak hata ya da göreceli (relatif) hata da sorulabilir. İlk konudaki hata kavramları ve anlamlı basamak sayısı gibi temel konular basit görünse de ayrıntı içerir ve tekrar edilmelidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): $y=x^3$ eğrisinin $x=-1$, $x=2$ ve $Ox$ ekseni ile sınırlı bölgesinin alanını Simpson 1/3 kuralıyla ($n=4$) hesaplayınız.

Çözüm (derste verildi): Alan $[-1,0]$ ve $[0,2]$ diye ikiye ayrılır. $[-1,0]$ için $h=0{,}25$ ve Simpson sonucu $-0{,}25$ olur; eksen altında olduğu için eksiyle çarpılır, alan $0{,}25$. $[0,2]$ için $h=0{,}5$ ve sonuç $4$. Toplam alan $4{,}25$ birim karedir. (Hoca birinci parça için yaklaşık $0{,}24$ dedi; python kontrolü tam $0{,}25$ verir.)

**Soru 2** (ekrandan, 00:40:00): $\int_{-2}^{-1}(x^2-1)(x+2)\,dx$ integralini $n=4$ ile trapez ve Simpson 1/3 yöntemleriyle hesaplayınız.

Çözüm (derste verildi): $h=0{,}25$; $f$ değerleri $0$; $0{,}5156$; $0{,}625$; $0{,}4218$; $0$. Trapez: $0{,}25(0{,}5156+0{,}625+0{,}4218)\approx 0{,}3906$. Simpson: $\frac{0{,}25}{3}[2\cdot0{,}625 + 4(0{,}5156+0{,}4218)]\approx 0{,}4166$. Gerçek değer $5/12\approx0{,}4167$.

**Soru 3** (ekrandan, 00:50:00): $\int_0^6\frac{1}{1+x^4}dx$ integralini Simpson 3/8 kuralıyla $n=1$ ve $n=2$ için hesaplayınız.

Çözüm (derste verildi): $n=1$: $h=2$, $\frac{6}{8}[1 + \frac{3}{17} + \frac{3}{257} + \frac{1}{1297}]\approx 0{,}8917$. $n=2$: $[0,3]$ için $\approx1{,}0082$, $[3,6]$ için $\approx0{,}0110$, toplam $\approx1{,}0192$.

**Soru 4** (ekrandan, 01:10:00): $I=\int_2^3\int_x^{2x^3}(x^2+y)\,dy\,dx$ integralini her iki adımda Simpson 1/3 ve $n=4$ kullanarak hesaplayınız.

Çözüm (derste $g_0$ adımı gösterildi): $x$ için $h=0{,}25$. $x_0=2$ için iç integralde $h=3{,}5$, $f$ değerleri $6$; $9{,}5$; $13$; $16{,}5$; $20$ ve $g_0=182$.

> **Çözüm (derste verilmedi):** Kalan iç integraller python ile Simpson 1/3 kullanılarak hesaplandı: $g_1\approx360{,}90$, $g_2\approx664{,}84$, $g_3\approx1155{,}0$, $g_4=1912{,}5$. Dış Simpson: $I\approx\frac{0{,}25}{3}[(182+1912{,}5)+4(360{,}90+1155{,}0)+2\cdot664{,}84]\approx790{,}65$. Analitik değer $\left[\frac{x^6}{3}+\frac{2x^7}{7}-\frac{x^4}{4}-\frac{x^3}{6}\right]_2^3\approx790{,}54$.

**Soru 5** (derste sözlü, 01:15:59): Simpson 1/3 kuralında $n$'nin çift seçilmesi zorunlu mudur?

Çözüm (derste verildi): $n$ parabol (alan) sayısı olarak düşünülürse tek de olabilir; her parabol iki alt parçaya bölünür. Alt aralık sayısı ise her zaman çift olur; $h=(b-a)/n$ ile yazılan formülde $n$ alt aralık sayısı olduğundan çift seçilmelidir.

## Dersin Toparlaması

Bu derste sayısal integral konusu tamamlandı. Trapez yönteminin kısa tekrarından sonra Simpson 1/3 kuralı, aralığa doğru yerine parabol uydurma fikrinden türetildi: sınırlar $-h$ ve $h$ alınarak $S=\frac{h}{3}(y_0+4y_1+y_2)$ formülüne varıldı ve aralık birden fazla parabole bölünerek bileşik formül (baş ve son bir kat, tekler dört kat, aradaki çiftler iki kat) elde edildi. $x^3$ ve $(x^2-1)(x+2)$ örnekleri Simpson'ın trapezden çok daha az hata verdiğini gösterdi. Ardından üçüncü dereceden polinoma dayanan Simpson 3/8 kuralı ve aralığı ikiye bölerek ($n=2$) doğruluğun nasıl arttığı $\int_0^6\frac{dx}{1+x^4}$ örneğiyle görüldü. Son olarak iki katlı integralin, iç integralin her $x_i$ için ayrı çözülüp elde edilen $g_i$ değerlerine yeniden tek katlı yöntem uygulanmasıyla, iç içe iki döngü mantığında sayısal olarak hesaplanabileceği gösterildi.

Bu yöntemlerin ortak noktası, integral kuralı kullanmadan yalnızca dört işlem ve döngülerle sonuç üretmeleridir. Hoca bir sonraki derste sonlu farklar konusuna geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
