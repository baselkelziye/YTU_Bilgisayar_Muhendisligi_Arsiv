# Ders 3 Genişletilmiş Notu: Taylor Yaklaşımı, Newton-Raphson ve Doğrusal Regresyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yeri: Optimizasyon ve Regresyon
- 2. Doğrusal Yaklaşım
- 3. Taylor Serileri ile Daha İyi Yaklaşım
- 4. Newton-Raphson ile Kök Bulma
- 5. Newton-Raphson ile En Küçük Değeri Bulma
- 6. Türevlerin Sayısal Hesabı
- 7. Çok Değişkenli Fonksiyonlar: Gradyan, Kuadratik Form ve Hessian
- 8. Çok Boyutta Gradyan İnişi ve Newton-Raphson
- 9. Yakınsama ve Newton-Raphson'un Tuzakları
- 10. Veri Modelleme ve Regresyon Modelleri
- 11. En Küçük Kareler Yöntemi
- 12. Matris Biçimi ve Kapalı Çözüm
- 13. Örneklem Büyüklüğü, Gürültü ve Model Derecesi
- 14. Aşırı Öğrenme, Yetersiz Öğrenme ve X-Hata Grafiği
- 15. Parametrelere Göre Doğrusallık
- 16. Analitik Çözümün Sınırı
- Örnek Sorular

## 1. Dersin Yeri: Optimizasyon ve Regresyon

Hoca derse, optimizasyona üç hafta ayrılacağını hatırlatarak başladı. Geçen hafta optimizasyona giriş yapılmıştı; bu hafta ve gelecek hafta devam edilecek. Optimizasyon slayt setleri bölümler hâlinde ilerliyor; dördüncü bölümde fazla bir şey olmadığı için hızlı geçilebilir. Bunlardan sonra gelen regresyon kısmı çok önemli: dersin asıl konusunda temel öğrenici (base learner) olarak kullanılacak en popüler yöntemlerden biri yapay sinir ağlarıdır ve ilerleyen haftalarda yapay sinir ağlarının hata ve parametre yüzeylerinde ensemble yöntemlerinin nasıl çalıştığı anlatılacak. Bu yüzden optimizasyon ve regresyonun iyi kavranması gerekiyor.

> **Hocanın vurgusu:** Lisansüstü dersler lisans derslerinden daha fazla iş yükü ister. Yalnız derse girip dinlemek yetmez; verilen kodları indirip çalıştırmak, üzerinde değişiklik yapıp oynamak konuları kavramak için gereklidir.

Ders, geçen haftanın son kısmının tekrarıyla başladı, çünkü konu önemli.

## 2. Doğrusal Yaklaşım

Elimizde bir fonksiyon olsun. Fonksiyonun kendisiyle uğraşmak yerine onun doğrusal bir yaklaşığıyla uğraşmak her zaman daha kolaydır: hesaplama açısından büyük kazanç sağlar, fonksiyonun en küçük değerini ya da sıfır olduğu yeri bulmayı da kolaylaştırır.

Burada iki farklı varsayımı ayırmak gerekir:

- **Fonksiyonu bütünüyle doğrusal kabul etmek:** Girişle çıkış arasındaki ilişkinin her yerde doğrusal olduğunu varsaymaktır. Bu, doğrusal bir model oturtmaktır ve regresyon kısmında görülecek. Fonksiyonu çok bozabilir.
- **Fonksiyonu bir noktada doğrusal kabul etmek:** Yalnız o noktanın çevresinde doğrusal olduğunu varsaymaktır. Bu daha zayıf bir varsayımdır; fonksiyonu yine bozar ama o kadar değil.

Bu derste yapılan ikincisidir.

### 2.1 Teğet doğru ile yaklaşım

Slayttaki çizimde (ekrandan, 00:05:00) mavi eğri $y = f(x)$, pembe doğru ise fonksiyonun $x$ noktasındaki doğrusal yaklaşığı $L$'dir. İkisi birbirinden oldukça farklı gider, ama $x$'in çevresinde birbirine çok yakındır; $x$'ten uzaklaştıkça aralarındaki fark açılır.

$x$ noktası $A$, oradan $\Delta x$ kadar uzaklaşınca gerçek fonksiyonun değeri $B = f(x+\Delta x)$, doğrusal yaklaşığın değeri ise $C = L(x+\Delta x)$ olur. Slayttaki ifadeler:

$$f(x+\Delta x) \approx L(x+\Delta x)$$

$$\lim_{\Delta x \to 0}\big(f(x+\Delta x) - L(x+\Delta x)\big) = 0$$

$$L(x+\Delta x) = f(x) + dy = f(x) + \Delta x\, f'(x), \quad \text{çünkü } f'(x) = dy/dx$$

Yeni nokta $x_{yeni} = x + \Delta x$ yazılırsa $\Delta x = x_{yeni} - x$ ve $f(x_{yeni}) \approx f(x) + (x_{yeni} - x) f'(x)$ olur.

$C$ değeri iki parçanın toplamıdır: $A$'nın yüksekliği olan $f(x)$ ve teğet boyunca çıkılan $dy$. Türev $dy/dx$ olduğundan $dy = \Delta x \cdot f'(x)$ yazılabilir. Böylece $f$'yi gerçekten hesaplamak pahalıysa, bir noktadaki değer ve türevle başka bir noktadaki değer tahmin edilebilir. Yapılan hatanın büyüklüğü $C$ ile $B$ arasındaki farktır.

### 2.2 Her noktanın doğrusal yaklaşığı farklıdır

Hoca bir noktadaki doğrusal yaklaşık ile başka bir noktadaki doğrusal yaklaşığın farklı olacağını ayrıca hatırlattı. $x$ noktasında elde edilen $L$ ile $x+\Delta x$ noktasında elde edilecek $L$ farklıdır, çünkü her noktada türev farklıdır.

## 3. Taylor Serileri ile Daha İyi Yaklaşım

Daha az hata yapmak için Taylor serileri kullanılır. Az önce yapılan şey birinci dereceden (first order) Taylor yaklaşımıdır:

$$f(x+\Delta x) \approx f(x) + \Delta x\, f'(x)$$

İkinci dereceden yaklaşımda buna ikinci türevle ilgili bir terim eklenir:

$$f(x+\Delta x) \approx f(x) + \Delta x\, f'(x) + \frac{(\Delta x)^2}{2} f''(x)$$

$n$. dereceye çıkıldığında genel biçim

$$f(x+\Delta x) \approx \sum_{i=0}^{n} \frac{f^{(i)}(x)}{i!}(\Delta x)^i$$

olur. $f$ sonsuz kez türevlenebiliyorsa $n \to \infty$ iken bulunan fonksiyon gerçek fonksiyonla aynı olur. Bu türetmelerin ayrıntısı internette bulunabilir.

Ancak çok yüksek dereceden türevler almak işi karmaşıklaştırır. Amaç $f$'nin kendisiyle uğraşmak yerine işi basitleştirmek olduğu için çok yüksek dereceler hesaplama açısından pek işe yaramaz.

### 3.1 Sıfırıncı dereceden yaklaşım

Birinci dereceden öncesi de vardır: sıfırıncı derece (zero order). Bu, fonksiyonu her yerde o noktadaki $f(x)$ değerine eşit kabul etmektir; yani $A$ noktasından geçen yatay bir doğrudur ve $x$'e bağlı değildir.

### 3.2 $e^x$ ve $\sin x$ örnekleri

Slaytta $f(x) = e^x$ (kırmızı, yukarı doğru çıkan eğri) için sıfırıncı dereceden beşinci dereceye kadar yaklaşımlar çizilmişti: en alttaki yatay doğru sıfırıncı derece, onun üstündeki eğik doğru birinci derece, sonra kuadratik, üçüncü, dördüncü ve beşinci derece (yeşil). Noktadan uzaklaştıkça fark açılır, ama derece arttıkça uzak yerlerde de gerçek değere yakın kalınabilir. Aynı fonksiyon başka bir noktada (0.25 civarı) açıldığında da yaklaşımlar giderek kırmızıya yaklaşıyor; uzak kısımlarda yine farklılıklar oluşabiliyor. Önemli olan, $x$'in yakınında işi doğru yapabilmektir.

$\sin x$ için açılım 15. dereceye kadar götürülmüş; yeşil açılım kırmızı fonksiyonun üstüne neredeyse tamamen oturmuş. Eksen biraz daha uzatılırsa açılımın yine ayrıştığı görülür.

> **Ek bilgi (derste anlatılmadı):** $e^x$'in bütün türevleri yine $e^x$ olduğu için $a$ noktasındaki Taylor açılımı $e^a\sum_k (x-a)^k/k!$ biçimindedir. Bu yüzden derece arttıkça yaklaşım düzenli olarak gerçek değere yaklaşır.

## 4. Newton-Raphson ile Kök Bulma

Bir fonksiyonu bir noktada doğrusal kabul etmenin kullanıldığı bir alan, fonksiyonun sıfır olduğu yeri bulmaktır, yani $f(x) = 0$ problemini çözmek.

### 4.1 Yöntem

Newton-Raphson'un önerisi şudur: rastgele bir noktadan başla, iteratif olarak ilerle. Her adımda bulunduğun noktada fonksiyonu doğrusal kabul et (ekrandan, 00:20:00).

$x_0$'da fonksiyon doğrusal kabul edilirse teğet doğrunun uzantısı fonksiyon yerine konur. Bu doğrunun x eksenini kestiği yer $x_1$'dir. $x_n$ noktasındaki türev, teğetin yüksekliği bölü yatay uzaklıktır:

$$f'(x_n) = \frac{f(x_n)}{x_n - x_{n+1}}$$

$$x_n - x_{n+1} = \frac{f(x_n)}{f'(x_n)}$$

$$x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}, \quad n = 0, 1, 2, \dots$$

Yalnız $n$. adımdaki değerler kullanılarak $(n+1)$. adım elde ediliyor. Rastgele bir yerden başlanıp adım adım köke yaklaşılıyor. Slayttaki durma ölçütü: kök 6 ondalık basamağa kadar doğru isteniyorsa $x_{n+1}$ ile $x_n$'nin basamakları 6. basamağa kadar aynı olunca durulur.

Fonksiyonun iki kökü varsa yöntem başlangıca yakın olana gider.

### 4.2 $\sqrt{2}$ bilgisayarda tutulabilir mi?

Hoca öğrencilere $x^2 - 2 = 0$ denkleminin bilgisayarla çözülüp çözülemeyeceğini sordu. $x^2 - 4$'ün kökleri kolayca bulunur, peki ya $x^2 - 2$?

**Soru:** Bilgisayarla bulunamaz mı? Taylor serisi uygulanırsa bulunur mu? **Cevap:** Taylor serisi uygulamanın burada anlamı yok. $x^2 = 2$ ise $x = \pm\sqrt{2}$'dir. Asıl soru, $\sqrt{2}$'nin değerinin bilgisayarda tam olarak tutulup tutulamayacağıdır. Sembolik olarak tutulabilir, ama değeri tutulamaz: hafıza ne kadar büyük olursa olsun $\sqrt{2}$ tam değeriyle saklanamaz.

**Soru:** Neden? **Cevap:** $\sqrt{2}$ rasyonel bir sayı değildir. Rasyonel sözcüğü "ratio" (oran) sözcüğünden gelir; iki tam sayının birbirine bölümü olarak yazılabilen sayılar rasyoneldir. $\sqrt{2}$ böyle yazılamaz, ondalık açılımı sonsuza kadar sürer. Bu yüzden yalnız belli bir hata payıyla yaklaşık tutulabilir.

> **Ders sonrası not:** Hoca $\sqrt{2}$ için "hesaplanabilir bir şey değil" dedi. Burada kastedilen büyük olasılıkla değerin sonlu bir bellekte tam olarak saklanamamasıdır. $\sqrt{2}$'nin istenen her basamağı bir algoritmayla (örneğin Newton-Raphson ile) üretilebilir; kuramsal anlamda "hesaplanabilir" bir sayıdır.

Bu yüzden kök bulma iteratif ve yaklaşık yapılır: birinci dereceden Taylor kullanılarak köke iteratif olarak yaklaşılır.

### 4.3 Döngü (cycle) sorunu

Slayttaki siyah eğri $f(x) = x^3 - 2x + 2$ fonksiyonudur. Bu fonksiyonun 1 noktasındaki doğrusal yaklaşığı kırmızı, 0 noktasındaki doğrusal yaklaşığı mavi doğru olarak çizilmiş.

0'dan başlanırsa mavi doğrunun x eksenini kestiği yer 1'dir; yani $x_0 = 0$ ise $x_1 = 1$ olur. 1 noktasında doğrusal kabul edilince kırmızı doğru x eksenini 0'da keser. Böylece 0'dan 1'e, 1'den 0'a, sonsuza kadar gidip gelinir; gerçek köke hiçbir zaman varılamaz. Bu döngü sorunudur.

Python ile kontrol (ara adım eklendi): $f(0) = 2$, $f'(0) = -2$, $x_1 = 0 - 2/(-2) = 1$; $f(1) = 1$, $f'(1) = 1$, $x_2 = 1 - 1/1 = 0$. Döngü doğrulandı.

## 5. Newton-Raphson ile En Küçük Değeri Bulma

Optimizasyonda istenen, fonksiyonun en küçük değeridir ve en küçük nokta kabaca türevin sıfır olduğu noktadır. Yani aranan $f$'nin değil $f'$'nün sıfır olduğu noktadır.

Bunun için yapılacak tek şey: elimizde sanki $f$ değil $f'$ varmış gibi düşünmek. Kök bulma formülünde $f$'lerin yerine türevleri konur:

$$x_{n+1} = x_n - \frac{f'(x_n)}{f''(x_n)}$$

Bu, Newton-Raphson'un ikinci dereceden (second order) biçimidir. Birinci dereceden biçim $f(x) = 0$'ı, ikinci dereceden biçim $f'(x) = 0$'ı bulur.

Daha önce görülen gradyan inişi (gradient descent) de $f'$'nün sıfır olduğu yeri arar; amaçları aynıdır. Newton-Raphson'un güzel tarafı, bir adım büyüklüğü (step size, eps) parametresinin olmamasıdır.

Slayttaki karşılaştırmada, 1.9 civarındaki bir başlangıç noktasından gradyan inişi en küçük noktaya 200 iterasyonda, Newton-Raphson ikinci dereceden 20 iterasyonda varmış; en azından o adım büyüklüğü için Newton-Raphson daha hızlı görünüyor. Başka bir örnekte yalnız 6-7 iterasyonda varılmış.

<!-- BELİRSİZ: Bu karşılaştırmanın fonksiyonu, adım büyüklüğü ve başlangıç noktası karelerde yok; değerler altyazıdan alındı. -->

Aynı slaytta birinci dereceden Newton-Raphson ile $f(x) = 0$ aranınca varılan noktanın farklı olduğu da gösterildi: bu kez en küçük nokta değil, eğrinin x eksenini kestiği nokta bulunuyor.

## 6. Türevlerin Sayısal Hesabı

Türevleri hesaplamak her zaman kolay olmayabilir. Bu durumda türevler sayısal olarak hesaplanabilir. Slayttaki üç yol (ekrandan, 00:30:00):

- **İleri fark (forward difference):** $f'(x) \approx \dfrac{f(x+\delta) - f(x)}{\delta}$
- **Geri fark (backward difference):** $f'(x) \approx \dfrac{f(x) - f(x-\delta)}{\delta}$
- **Merkezi fark (central difference):** $f'(x) \approx \dfrac{f(x+\delta/2) - f(x-\delta/2)}{\delta}$

$\delta$ seçimi önemlidir. Hoca merkezi farkın en makulü olduğunu söyledi.

Yukarıdaki bütün güncelleme formüllerinde türev vardır. Bir noktadan başka bir noktaya gitmek için fonksiyonun o noktada türevlenebilir olması gerekir; türevlenemiyorsa iterasyon sürdürülemez. Örneğin $y = 1/x$ her yerde türevlenebilir ama $x = 0$ yakınında değildir; $y = x^{1/3}$'ün türevi $x = 0$'da sonsuza gider. Böyle durumlarda büyük hatalarla da olsa sayısal türev kullanarak ilerlemeye devam etmek makul olabilir.

## 7. Çok Değişkenli Fonksiyonlar: Gradyan, Kuadratik Form ve Hessian

### 7.1 Gradyan vektörü

Şimdiye kadarki örnekler tek değişkenliydi. $x$ birden fazla boyutlu olabilir. Slayttaki yüzey $f(x_1, x_2)$ fonksiyonudur (eksenler $x$ ve $y$ diye yazılmış). Bir yüzeyin bir noktadaki türevi, her boyuta göre ayrı ayrı alınan türevlerdir; yani o noktada iki ayrı yönde iki vektör.

Birbirinden bağımsız ifade edilebilen kaç boyut varsa türev o kadar elemanlı bir vektördür: fonksiyon bir değişkenliyse türev bir boyutlu, on beş değişkenliyse türev on beş boyutludur. Bu vektöre gradyan vektörü denir ve genelde sütun olarak yazılır:

$$\nabla f(x) = \left[\frac{\partial f}{\partial x_1}, \frac{\partial f}{\partial x_2}, \dots, \frac{\partial f}{\partial x_n}\right]^T$$

Slayttaki çizimde yüzeyin yalnız $y$ yönünden kesiti aşağıdan yukarı çıkıp tekrar iniyor ve bulunulan nokta bir tepe; yalnız $x$ yönünden kesiti ise inip çıkıp tekrar iniyor.

Gradyan fonksiyona yaklaşan bir (hiper)düzlem tanımlar (ekrandan, 00:35:00):

$$\Delta z = \frac{\partial f}{\partial x}\cdot\Delta x + \frac{\partial f}{\partial y}\cdot\Delta y$$

**Soru:** Türevin boyutu $n-1$ olmamalı mı? Örneğin $x^2$'nin türevi $2x$; $x^2$ iki boyutluyken $2x$ tek boyutlu değil mi? **Cevap:** Hayır. Oradaki 2 boyut değil, üstür. Buradaki boyut kavramı fonksiyonun içindeki değişken sayısıdır. $x^2$, $2x$ ve $x^{79}$'un hepsi tek değişkenlidir.

### 7.2 Kuadratik fonksiyonlar

Kuadratik fonksiyon ikinci dereceden fonksiyon demektir. Bütün olası ikinci dereceden fonksiyonlar şu biçimde yazılabilir:

$$f(x) = \frac{1}{2}x^T Q x + b^T x + c$$

Burada $x$ tek bir sayı değil, $n$ boyutlu bir vektördür. Baştaki $1/2$, türev alınınca karenin getirdiği 2'yi sadeleştirmek için konmuştur. $Q$, $n \times n$'lik bir matristir; örneğin üç değişkenli bir fonksiyonda $3 \times 3$'tür ve terimlerin katsayılarını içerir.

Kuadratik fonksiyonların alabileceği üç biçim vardır (ekrandan, 00:40:00):

- **$Q$ pozitif tanımlı (bütün özdeğerleri pozitif):** Kase biçimi; bir en küçük noktası vardır ve kenarlara doğru yükselir. En sevilen durumdur, çünkü dışbükey fonksiyonda bulunan en küçük değerin global en küçük değer olduğundan emin olunur. Pozitif yarı tanımlı (özdeğerler $\geq 0$) durumda da büyük bir sıkıntı yoktur.
- **$Q$ negatif tanımlı (bütün özdeğerleri negatif):** Ters kase. Bu da sorun değildir, çünkü fonksiyonu ters çevirmek kolaydır.
- **$Q$ belirsiz (indefinite; özdeğerlerin bir kısmı pozitif, bir kısmı negatif):** Eyer (saddle) biçimi. Bir noktada türev sıfırdır, ama bu nokta en küçük nokta değildir. Türevin sıfır olduğu yeri arayan yöntemler burada takılabilir. Pek istenmeyen fonksiyonlardır, ama özellikle doğrusal olmayan yapılarda karşımıza çıkarlar.

Böylece yalnız $Q$'nun tanımlılık durumuna bakarak, iki boyutta çizilemese bile fonksiyonun şekli kolayca anlaşılır. Kontur çizgileri haritadaki izohips eğrilerine benzer: aynı çizgi üzerindeki bütün noktaların $f$ değeri eşittir. Slaytlarda (`quadratic_functions.m`) farklı $Q$, $b$, $c$ değerleri için çizilmiş kase ve eyer örnekleri vardı. $x_1 x_2$ gibi çarpım terimleri de ikinci dereceden olduğu için normal yazılabilen her ikinci dereceden fonksiyonun $Q$'su çıkarılabilir.

<!-- BELİRSİZ: quadratic_functions.m slaytlarındaki Q, b, c değerleri karelerde okunmuyor. -->

### 7.3 Hessian matrisi

Tek değişkenli bir fonksiyonun ikinci türevi tek bir sayıdır. $n$ değişkenli bir fonksiyonun birinci türevi $n \times 1$'lik gradyan vektörü, ikinci türevi ise $n \times n$'lik bir matristir; yani tıpkı $Q$ gibi. İki değişken için:

$$\nabla^2 f = \begin{bmatrix} \dfrac{\partial^2 f}{\partial x_1^2} & \dfrac{\partial^2 f}{\partial x_1 \partial x_2} \\[2mm] \dfrac{\partial^2 f}{\partial x_2 \partial x_1} & \dfrac{\partial^2 f}{\partial x_2^2} \end{bmatrix}$$

Türevlerin sırası sonucu etkilemediği için köşegen dışı elemanlar eşittir; matris simetriktir, transpozu kendisine eşittir. Bu matrise Hessian denir ve kuadratik formdaki $Q$'nun aslında Hessian olduğu ortaya çıkar.

## 8. Çok Boyutta Gradyan İnişi ve Newton-Raphson

### 8.1 Boyutlar

$n$ boyutta gradyan inişi $x_{yeni} = x_{eski} - \text{eps}\cdot\nabla f$ biçimindedir. $x_{yeni}$ ve $x_{eski}$ $n \times 1$'lik vektörlerdir, eps tek bir sayıdır, türev de $n \times 1$'liktir. $n \times 1$'den $n \times 1$ çıkarılıp yine $n \times 1$ elde edilir.

Newton-Raphson'da $f'/f''$ yazılamaz, çünkü matrislerde bölme yoktur; ters matrisle çarpılır:

$$x_{yeni} = x_{eski} - (\nabla^2 f)^{-1}\,\nabla f$$

Ters matrisin boyutu değişmez: $(\nabla^2 f)^{-1}$ $n \times n$, $\nabla f$ $n \times 1$, çarpımları $n \times 1$ olur ve $x_{eski}$'den çıkarılır.

### 8.2 Ters matrisin maliyeti

Hoca determinantın tanımı gibi kısımları öğrencilere bıraktı. `inversion_time.m` ile çizilen grafikte (ekrandan, 00:45:00) yatay eksen matris boyutu (0-500), dikey eksen saniye cinsinden süre; mavi ortalama süre, kırmızı standart sapma. Süre boyutla doğrusal değil, giderek dikleşen bir eğriyle artıyor; 500'lük matriste ortalama 0.7 saniyeyi geçiyor.

> **Ders sonrası not:** Hoca maliyetin boyutla "eksponansiyel" arttığını söyledi. Grafikteki artış doğrusal değildir, ama hocanın kastettiği büyük olasılıkla bu hızlı artıştır; standart ters alma yöntemlerinin (Gauss eliminasyonu, LU ayrışımı) maliyeti $O(n^3)$'tür, yani üstel değil polinomsaldır.

### 8.3 Kuadratik fonksiyonda tek adım

Kuadratik bir fonksiyonda gradyan inişi 0.1 adımla küçük küçük ilerleyip örneğin 50 adımda en küçük noktaya varırken Newton-Raphson tek adımda varır. Çünkü Newton-Raphson bulunduğu noktaya bir kuadratik fonksiyon oturtur; fonksiyon zaten kuadratikse bu oturttuğu fonksiyon gerçeğin kendisidir ve doğrudan onun en küçük noktasına iner. Kuadratik olmayan, daha yüksek dereceli fonksiyonlarda da Newton-Raphson adım sayısı açısından gradyan inişinden çok daha hızlıdır.

Python ile kontrol (derste sayısal örnek verilmedi; doğrulama amaçlı): $Q = \begin{bmatrix}4 & 1\\ 1 & 2\end{bmatrix}$, $b = [1, -1]^T$ için $[3, -2]^T$'den bir Newton adımı atıldığında gradyan $Qx + b$ makine hassasiyetinde sıfır oluyor; yani tek adımda en küçük noktaya varılıyor.

### 8.4 Bedeli: Hessian ve tersi

Newton-Raphson'u çalıştırmak için iki işlem gerekir: bulunulan noktadaki Hessian'ı hesaplamak (her noktada değişir) ve tersini almak. 100 bin boyutlu bir fonksiyonda Hessian $100\,000 \times 100\,000$'lik bir matristir; hem bellekte tutmak hem tersini almak çok pahalıdır. Daha az adımda bulur ama her adım çok pahalıdır. Bu nedenle çok yüksek boyutta ikinci dereceden yöntemler uygulanamaz; az boyutta makuldürler.

Gelecek hafta, birinci dereceden olup ikinci dereceden yöntemlere yakın hızda çalışan algoritmalar (Adagrad, Adam vb.) görülecek.

### 8.5 Zor bir fonksiyonda karşılaştırma

Geçen hafta konuşulan zor bir fonksiyonda (ekrandan, 00:50:00), $x_0 = [-0.5;\ 0.7]$ başlangıcıyla (`opt_Ndim_general.m`) gradyan inişi 0.1 adımla 118. iterasyonda, Newton-Raphson 4. iterasyonda yakınsadı. Başka bir başlangıç noktasında gradyan inişi 142 adımda en küçük noktaya varırken Newton-Raphson 5. adımda yakınsadı, ama istenen yere değil.

## 9. Yakınsama ve Newton-Raphson'un Tuzakları

### 9.1 Epsilon yakınlık

Optimizasyonda bir noktaya yakınsamak, o noktayı tam bulmak demek değildir; o noktaya epsilon kadar yakın bir yer bulmak demektir. Kullandığımız bilgisayarlar analog değil, ayrıktır; bir çözünürlükleri vardır. Örneğin aranan yer 2 ise iterasyonlar 2'ye 0.000001 kadar yaklaşınca durdurulabilir.

Ancak gerçek bilinmediği için gerçeğe ne kadar yaklaşıldığı hesaplanamaz (bilinseydi optimizasyona gerek kalmazdı). Hesaplanabilen, bir önceki adımla şimdiki adım arasındaki uzaklıktır. Adımlar çok küçüldüğünde artık bir yere yakınsanıyor demektir. Bu yüzden ardışık adımların büyüklüğüne bakılarak epsilon yakınlık tanımlanır ve iterasyonun devam edip etmeyeceğine karar verilir.

### 9.2 Newton-Raphson tepe noktasına gidebilir

Slaytta $\sin$ fonksiyonu üzerinde (mavi $f$, kırmızı $f'$, yeşil $f''$) bir başlangıç noktasından Newton-Raphson 1, 2, 3, 4, 5 adımda en küçük noktaya hızla yakınsıyor. Başka bir noktadan başlayınca ise tepe noktasına yakınsıyor. İstenen en küçük noktadır, ama Newton-Raphson türevin sıfır olduğu her noktaya gidebilir ve tepe noktasında da türev sıfırdır.

Kritik olan $f'$ ile $f''$'nin işaretleridir. Birinde işaretler aynı, ötekinde farklıdır; işaretler farklı olduğunda yöntem gitmesi gereken yönün tersine gider.

### 9.3 Bunu nasıl anlarız?

Ardışık adımlarda $f$ değerinin sürekli düşmesi beklenir. Tepeye giden durumda 1. noktadan 2. noktaya geçilince $f$ artar, 3. noktada daha da artar. Bu tür durumlar önceden engellenemez; ama adım atılmadan önce ya da sonra $f$ değerine bakılarak adım kabul edilir ya da edilmez. $f$ azaldığı sürece devam edilir. Bu kontrol Newton-Raphson içinde gereklidir.

Gradyan inişinde böyle bir kontrole gerek yoktur: iniş yapan bir algoritmadır ve dışbükey bir fonksiyonda adım büyüklüğü küçükse her adımda azalır. Adım büyüklüğü çok büyükse minimumun öbür tarafına atlanıp daha kötü bir yere varılabilir ve yakınsama olmaz.

<!-- BELİRSİZ: Hoca adım büyüklüğü için geçen hafta görülen bir üst sınırdan söz etti ("birden büyük olmaması", ardından altyazıda "9.99'dan küçük" diye geçen bir değer); hangi fonksiyon için verildiği ve değerin kendisi altyazıdan kesin çıkmıyor, kare yok. -->

Slayt setinin sonunda dışbükey olmayan çeşitli fonksiyonlar vardı; bu bölüm burada tamamlandı. Hoca bir sonraki optimizasyon bölümünü (yakınsama türleri) şimdilik atladı.

## 10. Veri Modelleme ve Regresyon Modelleri

Aradan sonra "Data Modeling and Regression Techniques" slaytına geçildi. Bilimsel yöntemle ilgili giriş slaytları atlandı.

### 10.1 Hangi ilişki daha mantıklı?

Slayttaki düşünme sorusu (ekrandan, 01:15:00): $X$ sınavdan önceki gece kaç saat çalışıldığı, $Y$ sınav notu. Yalnız $X$'e bakarak $Y$ değerlendirilirse dört grafikten hangisi daha mantıklıdır? Dört grafik: azalan doğru (kahverengi), önce yatay sonra azalan eğri (turkuaz), hızla yükselip sonra yavaşça düşen eğri (sarı), artan doğru (yeşil).

Öğrencilerden gelen cevaplar: yeşil (ne kadar çok çalışırsam o kadar yüksek not), turkuaz (uykuyu seven biri için), sarı (bir noktaya kadar öğrenir, sonra abartınca kafa karışır). Bir öğrenci başlangıçtaki bilgi düzeyinin de önemli olduğunu ekledi. Hoca, sınav notunu etkileyen tek etkenin bir gece önceki çalışma süresi olmadığını, burada yalnız bu $X$'e bakıldığında ne çıkacağının konuşulduğunu söyledi.

### 10.2 Doğrusal ve doğrusal olmayan ilişki

Doğrusal ilişki, iki değişken arasındaki ilişkinin bölgeden bölgeye değişmemesi demektir: herhangi iki an arasındaki fark, başka bir yerdeki herhangi iki an arasındaki farkla aynı oranda ilişkilidir. Doğrusal olmayan ilişkide değişkenler farklı bölgelerde (zaman ya da mekân olarak düşünülebilir) birbirleriyle farklı ilişkiler gösterir.

### 10.3 Regresyon ve model

Regresyon, tahmin olarak bir sayı üretmektir. Elinizde bir veri kümesi vardır ve bu verinin bir modele uyduğunu varsayarsınız; ardından verileri kullanarak o modelin parametrelerini bulursunuz. Örneğin verinin doğrusal bir modele uyduğu varsayılır ve doğrusal modelin veriye en uygun parametreleri bulunur.

> **Hocanın vurgusu:** Her model bir varsayımdır. Doğru da olabilir, yanlış da. Doğrusal, doğrusal olmayan, çok ya da az parametreli pek çok model varsayılabilir.

Klasik düzende eğitim kümesiyle varsayılan modelin parametreleri bulunur, test kümesiyle de başarısı ölçülür.

### 10.4 Regresyon modeli türleri

Slayttaki modeller (ekrandan, 01:20:00):

- Doğrusal birinci dereceden model: $Y = \beta_0 + \beta_1 X + \varepsilon$
- Doğrusal ikinci dereceden model: $Y = \beta_0 + \beta_1 X + \beta_2 X^2 + \varepsilon$
- Doğrusal $n$. dereceden model: $Y = \beta_0 + \beta_1 X + \beta_2 X^2 + \dots + \beta_n X^n + \varepsilon$

$\varepsilon$ rastgele hatadır. "Doğrusal" sözcüğü $\beta_i$ parametrelerindeki doğrusallığı anlatır. Modelin derecesi (order, degree) $X$'in en yüksek kuvvetidir. $X$ çok boyutlu olabilir, ama $Y$ tek bir sayıdır.

İkinci dereceden modelde $X^2$ olduğu hâlde modelin "doğrusal" olmasının sebebi budur: doğrusallık $\beta$'ların birbiriyle ilişkisine bakar. Slayttaki başka bir örnekte $\beta_0$, $\beta_1$, $\beta_2$, $\beta_3$ katsayılı ve $X$'in birinci dereceden göründüğü bir model doğrusaldır; buna karşılık $Y = \beta_0 X / (\beta_1 + X) + \varepsilon$ modelinde $X$ birinci dereceden olduğu hâlde parametreler bölüm hâlinde yer aldığı için model doğrusal değildir. Bölme yerine toplama olsaydı yine doğrusal olurdu.

<!-- BELİRSİZ: Bu iki örnek modelin slayttaki tam yazımı karelerde yok; altyazıdan kuruldu. -->

$\varepsilon$ rastgele gürültüdür; ölçümden, rastlantıdan gelir ve kaçınılamaz. Tahmin edilemediği için modele parametre olarak katılmaz; modelde sanki yalnız deterministik kısım varmış gibi davranılır.

### 10.5 Popülasyon ve örneklem

Gerçekte verinin $Y_i = \beta_0 + \beta_1 X_i + \varepsilon_i$ biçiminde bir modelden geldiği varsayılır; amaç $\beta_0$ ve $\beta_1$'i tahmin etmektir. Tahmin edilen değerler $\hat\beta_0$, $\hat\beta_1$ ile gösterilir ve modele konunca $\hat Y$ elde edilir. $Y$ ile $\hat Y$ arasındaki farkın en küçük olması istenir.

Slayttaki çizimde (ekrandan, 01:25:00) bilinmeyen ilişki $Y_i = \beta_0 + \beta_1 X_i + \varepsilon_i$ popülasyondadır; rastgele örneklemden $Y_i = \hat\beta_0 + \hat\beta_1 X_i + \hat\varepsilon_i$ tahmin edilir. Slayttaki not: çoğu zaman bütün popülasyona ulaşamazsınız.

Örneklem (sample) tek bir örnek için değil, örnek kümesi için kullanılır. Deney, anket, ölçüm yapılır ama bütün popülasyonu kapsayan bir örnekleme ulaşmak mümkün olmaz; ulaşılabilseydi modellemeye belki gerek kalmazdı. $(X_i, Y_i)$, $i$. eğitim örneğidir; $X_i$ giriş, $Y_i$ çıkıştır.

## 11. En Küçük Kareler Yöntemi

### 11.1 Hangi doğru?

Noktalara doğrusal bir model oturtulduğunda, noktaların doğruya olan dikey uzaklıkları hatalardır. Başka bir doğru seçilirse başka hatalar oluşur. Tek değişkenli birinci dereceden bir modelde doğru $\beta_0$ ve $\beta_1$ değiştirilerek sonsuz farklı yerden geçirilebilir; soru, en küçük hatayı veren doğrunun hangisi olduğudur. İki değişkende bu doğru bir düzleme, üç ve daha fazla değişkende bir hiperdüzleme dönüşür; hepsi doğrusal modeldir.

### 11.2 En küçük kareler

Parametreleri tahmin etmek için en yaygın yöntem en küçük kareler (least squares) yöntemidir. Uygulamak için iki şey gerekir: bir model (varsayım) ve bir eğitim verisi.

> **Hocanın vurgusu:** En küçük kareler yöntemi modeli vermez. Modeli veren bir algoritma yoktur; model birinden duyulur, akla gelir, önceki çalışmalardan esinlenilir ya da var olan kullanılır. Model her zaman dışarıdan verilir; yöntem yalnız o veride hatası en küçük parametreleri bulur.

Slayttaki tanım (ekrandan, 01:30:00): "En iyi uyum", gerçek $Y$ değerleriyle tahmin edilen $Y$ değerleri arasındaki farkın en küçük olması demektir; ama artı farklar eksi farkları götürür, bu yüzden hatalar karesi alınarak toplanır:

$$\text{SSE} = \sum_{i=1}^{n}(Y_i - \hat Y_i)^2 = \sum_{i=1}^{n}\hat\varepsilon_i^2$$

$$\text{MSE} = \frac{1}{n}\sum_{i=1}^{n}(Y_i - \hat Y_i)^2$$

Buradaki $\hat\varepsilon_i$'ler, modeldeki rastgele hata ile karıştırılmamalıdır; tahmin ile gerçek arasındaki farklardır.

**Soru:** Neden kare alınıyor? **Cevap:** Bir öğrenci "negatif değer çıkmasın diye" dedi. Hoca düzeltti: amaç negatif ile pozitif hataların birbirini götürmemesidir. Bir örnekte fark $+3$, başka bir örnekte $-3$ ise doğrudan toplanınca iki büyük hata birbirini sıfırlar.

**Soru:** Kare yerine mutlak değer alınamaz mı? **Cevap:** Mutlak değer fonksiyonu sıfır noktasında türevlenemez (aşağı doğru sivri bir "V"). Optimizasyonda türevi alınabilen fonksiyonlar kullanılır; kare fonksiyonu her yerde türevlenebilir.

Slayttaki dört noktalı örnekte mavi doğru oturtulunca her nokta için bir tahmin ve $\varepsilon_1, \varepsilon_2, \varepsilon_3, \varepsilon_4$ hataları oluşur; en küçük kareler bu hataların karelerinin toplamını en küçük yapar.

### 11.3 En basit model: $y = \beta$

Model $y = \beta$ olsun; örneğin $\beta = 2$ ise $x$ ne olursa olsun çıkış 2'dir. Bu sıfırıncı dereceden bir modeldir. Elimizde $n$ veri varken bu model için en az karesel hatayı veren $\beta$ nedir?

Bir öğrenci "ortalaması mı?" diye sordu; hoca mantıken öyle olması gerektiğini söyleyip türetmeyi gösterdi. Her örneğin hatası $\varepsilon_i = y_i - \beta$'dır, çünkü model her durumda $\beta$ çıkışını verir:

$$E(\beta) = \sum_{i=1}^{n}(y_i - \beta)^2$$

$\beta$'ya göre türev alınıp sıfıra eşitlenir:

$$\frac{dE}{d\beta} = -2\sum_{i=1}^{n}(y_i - \beta) = 0 \;\Rightarrow\; \sum_{i=1}^{n} y_i - n\beta = 0 \;\Rightarrow\; \beta = \frac{1}{n}\sum_{i=1}^{n} y_i$$

Toplamın içindeki $\beta$, $i$'ye bağlı olmadığı için $n\beta$ olarak dışarı çıkar. Sonuç: eldeki veriye göre en iyi $\beta$, $y$'lerin ortalamasıdır. Modeller her zaman bu kadar basit olmayacak, ama mantık hep aynıdır: kayıp fonksiyonunun parametreye göre türevi alınır ve sıfıra eşitlenir.

## 12. Matris Biçimi ve Kapalı Çözüm

### 12.1 Neden $\beta_0$?

Birinci dereceden modelde $\beta_0$ olmazsa model orijinden geçmek zorunda kalır: $y = mx$'e bir sabit eklenmezse hangi $m$ seçilirse seçilsin doğru orijinden geçer. Gerçekte modelin bu kadar kısıtlı olması istenmez; bu yüzden $\beta_0$ her zaman modele eklenir.

> **Ders sonrası not:** Altyazıda hoca bir yerde "beta 1 olmazsa model orijinden geçer" diyor; bağlamdan kastedilenin sabit terim $\beta_0$ olduğu açıktır.

### 12.2 Matris biçimi

Slayttaki "A new look" (ekrandan, 01:35:00): $X$ $d$ boyutlu olsun. Doğrusal birinci dereceden model

$$Y = \beta_0 + \beta_1 X_1 + \beta_2 X_2 + \dots + \beta_d X_d + \varepsilon$$

matris biçiminde

$$Y_{n\times 1} = X_{n\times(d+1)}\,\beta_{(d+1)\times 1} + \varepsilon_{n\times 1}$$

olarak yazılır; $n$ örneklem büyüklüğüdür. $X$ matrisinin $n$ satırı, $d+1$ sütunu vardır. Fazladan sütun, $\beta_0$'a karşılık gelen birlerden oluşan sütundur.

Tek boyutlu örnekte ($n = 4$, $d = 1$) her satırda bir ve $x_i$ bulunur:

$$\begin{bmatrix} y_1 \\ y_2 \\ y_3 \\ y_4 \end{bmatrix} = \begin{bmatrix} 1 & x_1 \\ 1 & x_2 \\ 1 & x_3 \\ 1 & x_4 \end{bmatrix} \begin{bmatrix} \beta_0 \\ \beta_1 \end{bmatrix} + \varepsilon$$

İlk satır açılınca $y_1 = 1\cdot\beta_0 + x_1\beta_1$, yani modelin kendisi çıkar. $d = 2$ olunca her satırda $1$, $x_{i1}$, $x_{i2}$ bulunur. İkinci dereceden model $\beta_0 + \beta_1 x + \beta_2 x^2$ varsayılırsa her satıra $1$, $x_i$ ve $x_i^2$ yazılır; $\beta$ vektörü $[\beta_0, \beta_1, \beta_2]^T$ olur.

<!-- BELİRSİZ: Slayttaki örnek matrislerin sayısal değerleri karelerde okunmuyor; altyazıda örnek değer olarak "x = 3.5, y = 7" ve "x = 2.49, y = 4.98" geçiyor. -->

### 12.3 $\beta$'yı yalnız bırakmak

$\varepsilon$ yok sayılınca $Y = X\beta$ biçimi kalır; $Y$ ve $X$ bilinir, $\beta$ bilinmez. Slayttaki adımlar (ekrandan, 01:40:00):

- Bütün örnekler şu biçimdedir: $Y = X\beta$. $\beta$ nasıl tahmin edilir?
- Matrislerde bölme yoktur; iki taraf $X^{-1}$ ile çarpılabilir: $X^{-1}Y = X^{-1}X\beta$ ($X^{-1}X = I$), yani $\beta = X^{-1}Y$. Fakat $X$ kare değilse?
- Ters alabilmek için matris kare olmalıdır. Slayttaki $X$'ler $4\times 3$ ve $4\times 2$'dir; kare değildir.
- $X^TX$ her zaman karedir: $4\times 2$'lik $X$'in transpozu $2\times 4$'tür, çarpımları $2\times 2$ olur. İki taraf $X^T$ ile çarpılır: $X^TY = X^TX\beta$.
- İki taraf $(X^TX)^{-1}$ ile çarpılır: $(X^TX)^{-1}(X^TY) = (X^TX)^{-1}(X^TX)\beta$ ve $(X^TX)^{-1}(X^TX) = I$.
- Sonuç:

$$\beta = (X^TX)^{-1}(X^TY)$$

Matris çarpımı ve ters alma biraz sorunlu olabilir, ama kuramsal olarak bu biçimde yazılabilen her model ve her veri için $\beta$ bu formülle bulunur.

## 13. Örneklem Büyüklüğü, Gürültü ve Model Derecesi

### 13.1 `lin_reg1.m` ve örneklem büyüklüğü

Kodda önce gerçek bir model oluşturuluyor: gerçek $\beta = [5;\ 0.8]$. Bu modelden örnekler üretilirken bir miktar gürültü ekleniyor ki hepsi kırmızı doğrunun üstüne düşmesin. Sonra yalnız mavi noktaların $x$ ve $y$ değerlerinden $X$ matrisi kuruluyor ve formülle $\beta$ tahmin ediliyor; tahmin edilen model yeşil doğru olarak çiziliyor. Gerçek modele oldukça yakın çıkıyor.

Örnek sayısı arttıkça tahmin gerçeğe yaklaşır. Slayttaki değerler (ekrandan, 01:45:00):

| Örneklem | Gerçek $\beta$ | Tahmin $\hat\beta$ | MSE |
| :---: | :---: | :---: | :---: |
| $N = 6$ | $[5;\ 0.8]$ | $[5.1713;\ 0.57024]$ | 0.0026644 |
| $N = 600$ | $[5;\ 0.8]$ | $[5.0025;\ 0.79611]$ | 0.0099418 |

$N = 6$'da yeşil ve kırmızı doğrular belirgin biçimde ayrışıyor; $N = 600$'de yeşil doğru kırmızının üstüne binmiş.

### 13.2 Gürültünün etkisi

Örneklem büyüklüğünün yanında eklenen gürültünün büyüklüğü de önemlidir. Kodda rastgele sayı büyük bir sayıya bölünerek küçük gürültü, daha küçük bir sayıya (örneğin 2'ye) bölünerek büyük gürültü üretiliyor. Gürültü artı ya da eksi yönde büyüdükçe gerçek ile tahmin arasındaki hata artar.

### 13.3 İkinci dereceden model oturtmak

Mavi noktalar eğri biçimindeyse aynı yaklaşımla ikinci dereceden model oturtulabilir: $Y = \beta_0 + \beta_1 x + \beta_2 x^2$. Altyazıya göre gerçek değerler $\beta_0 = 2$, $\beta_1 = 0.2$, $\beta_2 = 0.3$; tahminler sırasıyla 1.89, 0.167 ve 0.349 civarında çıkmış. Kodda ayrıca MSE de yazdırılıyor.

<!-- BELİRSİZ: İkinci dereceden örneğin tahmin değerleri ve MSE altyazıdan alındı (MSE altyazıda "24, 325" diye geçiyor); bu slaytın karesi yok. -->

### 13.4 Aynı veriye farklı modeller

Model önceden bilinemediği için aynı veriye farklı modeller uygulanabilir. Gerçek model ikinci dereceden olduğunda birinci dereceden (yeşil) ve ikinci dereceden (mavi) modeller oturtulmuş; ikinci dereceden model gerçek modelle çok uyumlu ve hatası çok daha küçük. Altyazıda bu durum için birinci dereceden modelin hatası 44-49, ikinci dereceden modelin hatası 3 civarında geçiyor.

<!-- BELİRSİZ: Gerçek modeli ikinci dereceden olan örneğin MSE değerleri karelerde yok; altyazıda "49 ve 3" ile "44 ve 3" diye iki farklı söyleyiş var. -->

Gerçek model birinci dereceden olduğunda (`Lin_reg4.m`) ise ilginç bir durum çıkıyor (ekrandan, 01:50:00): birinci dereceden modelin eğitim MSE'si 21.0596, ikinci dereceden modelin MSE'si 18.4368. Yani yanlış olan (gerçekten karmaşık) modelin eğitim hatası, doğru dereceli modelden daha düşük.

**Soru (hocanın sorusu):** Bu neden böyle, garip değil mi? Bir öğrencinin cevabı: eğitim verisinin aralığı genişletilirse durum değişir. **Cevap:** Doğru. Slayttaki "Bu bölgelerde ne olur?" okları da bunu soruyor. Eğitim kümesinin kapsadığı aralık genişletilirse doğrusal modelin hatası küçük kalır, ama ikinci dereceden model iki uçta da doğrusallıktan giderek uzaklaşır; gerçek değerler bir yöne giderken model başka yöne kıvrılır ve hatası çok büyür.

## 14. Aşırı Öğrenme, Yetersiz Öğrenme ve X-Hata Grafiği

### 14.1 Eğitim verisine yapışmak

İki durumu karşılaştırmak gerekir. Gerçekten daha basit bir model tahmin edildiğinde, gerçekle aynı dereceli model daha iyi çıkıyordu. Gerçekten daha karmaşık bir model tahmin edildiğinde ise bu model gerçek dereceli modelden bile başarılı göründü; ama yalnız eğitim verisi üzerinde.

> **Hocanın vurgusu:** Eğitim verisi üzerinde modelin parametre sayısını ne kadar artırırsanız eğitim kümesine o kadar yapışırsınız (ezberlersiniz). Model karmaşıklığı ne kadar yüksekse eğitim hatası o kadar düşüktür.

- **Aşırı öğrenme (overfitting):** Gerçekten daha karmaşık bir model oturtmak. Eğitim kümesinde fark anlaşılmaz; yüksek dereceli model daha düşük hata verir.
- **Yetersiz öğrenme (underfitting):** Gerçekten daha basit bir model oturtmak. Tahmin ile gerçek arasında büyük fark oluşur.

### 14.2 X-hata grafiği

Üçüncü dereceden bir veri üretilip birinci, ikinci ve üçüncü dereceden modeller oturtulmuş. X-hata grafiği, girişe karşılık hataların grafiğidir (ekrandan, 01:55:00). Tek boyutta bir çizgi gibi görünür; $x_1, x_2$ gibi birden fazla giriş olsaydı bir hata yüzeyi olurdu.

Grafiğin başlığındaki değerler: birinci dereceden MSE = 128.9716, ikinci dereceden MSE = 96.0218, üçüncü dereceden MSE = 3.4312. Kırmızı birinci dereceden, yeşil ikinci dereceden, mavi üçüncü dereceden modelin hatalarıdır.

Slayttaki kurallar:

- X-hata grafiğinde bir örüntü varsa modellenmemiş bir şey vardır. (Kastedilen, dışarıda kalan bir değişken değil, eksik kalan bir derecedir.)
- Model derecesi yeterliyse hatalar $X$ boyunca aynı varyansa sahiptir.

Gerçek model üçüncü dereceden olduğu için mavi hatalarda bir örüntü görünmüyor; tamamen rastgele bir sinyal gibi. Kırmızı ve yeşil ise gerçekten basit, yani yetersiz öğrenmiş modellerdir; hataları $x$'e göre düzenli dalgalanır. Bu grafikte aşırı öğrenme yoktur; olması için üçten yüksek dereceli bir model oturtmak gerekirdi.

Yetersiz öğrenmeyi bu grafikten anlamak kolaydır: "şöyle olduğunda böyle oluyor" diye bir örüntü görülüyorsa yetersiz öğrenme vardır. Aşırı öğrenmede (örneğin dördüncü dereceden model) maviye benzeyen, hatta daha küçük sıçramalı bir çizgi görülür; örüntü oluşmaz, bu yüzden bu grafikten anlaşılmaz.

### 14.3 Model doğrulama

Eğitim kümesindeki MSE model seçimi için güvenilir değildir. Model karmaşıklığı arttıkça eğitim hatası giderek azalır, ama test hatası bir noktaya kadar azalıp sonra artmaya başlar. Test hatasının en düşük olduğu nokta, verinin gerçek derecesine işaret edebilir; derece bilinmiyorsa onu bulmak için bu kullanılabilir. Slaytlarda eğitim ve test örnekleriyle birinci ve ikinci dereceden modellerin hataları da vardı; hoca bunları geçti.

> **Ek bilgi (derste anlatılmadı):** Test hatasının önce düşüp sonra yükselmesi, model karmaşıklığına göre sapma (bias) ile varyans arasındaki dengenin sonucudur. Basit model yüksek sapmalı (yetersiz öğrenme), karmaşık model yüksek varyanslı (aşırı öğrenme) olur.

## 15. Parametrelere Göre Doğrusallık

### 15.1 $\cos$, $\sin$ ve $\exp$ içeren doğrusal modeller

Doğrusal sistem kurulumunda $\cos$ gibi terimlerin bulunması modeli doğrusal olmaktan çıkarmaz. Doğrusallık $\beta$'ların birbiriyle ilişkisine göre tanımlanmıştı. Örneğin $\beta_1 x_1 + \beta_2\cos(x^2)$ modeli doğrusaldır ve aynı formülle çözülür; $X$ matrisinin sütunlarına $x_1$ ve $\cos(x^2)$ değerleri yazılır.

Çok değişkenli örnekte $x_1$, $x_2$ ve $f(x_1, x_2)$ var; mavi noktalar veri, yüzey tahmin edilen yüzey, kırmızı noktalar mavilerin yüzey üzerine izdüşümleri. Gerçek ve tahmin edilen $\beta$ değerleri slaytta karşılaştırılmış. Çok değişkenli ikinci dereceden modelde $x_1$, $x_2$, $x_1^2$, $x_2^2$ terimleri ve $\beta_0, \dots, \beta_4$ olmak üzere beş parametre var. "İkinci derece" karelerden, "çok değişkenli" iki giriş değişkeninden geliyor. Model yine doğrusal ve yüzey aynı yöntemle tahmin ediliyor.

<!-- BELİRSİZ: Çok değişkenli örneklerin gerçek ve tahmin edilen beta değerleri karelerde yok. -->

### 15.2 Doğrusal olmayan modeller

Slayttaki liste (ekrandan, 02:00:00):

$b$'ye göre doğrusal:

- $Y = b_1\sin(X)$
- $Y = X_1\, b_1 \sin(X_2)$
- $Y = b_1\sin(X) + b_2\cos(X)$
- $Y = b_1\exp(X) + b_2\cos(X)$
- $Y = b_1\exp(X_1) + b_2\cos(X_2) + b_3\cos(X_1)$

$b$'ye göre doğrusal olmayan:

- $Y = \sin(b_1 X)$
- $Y = b_1\sin(b_2 X)$
- $Y = \exp(b_1 X)$
- $Y = (b_1 X)/(b_2 + X)$
- $Y = b_1\exp\!\big(-(X - b_2)^2 / b_3^2\big)$

İkinci gruptakiler "$(X^TX)^{-1}X^TY$" ile tahmin edilemez, çünkü $Y$ ile $b$ arasındaki ilişki doğrusal değildir; $b$ başka bir fonksiyonun içinden gelir. Örneğin $\sin(b_1 X)$'te $b$'deki küçük bir değişiklik $Y$'de büyük değişikliklere yol açabilir.

### 15.3 Ayırt etme ölçütü

Slayttaki tanım: bir $f$ fonksiyonunun $\beta$ parametresi, $f$'nin $\beta$'ya göre türevi $\beta$'nın bir fonksiyonuysa doğrusal olmayan biçimde yer alır.

- $f(x) = \beta\sin x$: $\partial f/\partial\beta = \sin x$. Türev $\beta$'dan bağımsızdır; model doğrusaldır.
- $f(x) = \sin(\beta x)$: $\partial f/\partial\beta = x\cos(\beta x)$. Türev $\beta$'ya bağlıdır; model doğrusal değildir.

Önceki doğrusal örneklerde $\beta_1$'e göre türev alındığında sonuçta hiçbir yerde $\beta_1$ görünmez; $\beta_2$'ye göre türev alınınca örneğin yalnız $\cos(x_2^2)$ kalır.

### 15.4 Doğrusallığa dönüşüm

Doğrusal denklem yazılamıyorsa doğrusallığa ulaşmak için dönüşümler yapılabilir; örneğin $\ln x^r = r\ln x$ gibi klasik matematik kuralları. Bu kurallarla, mümkünse, doğrusal olmayan bir model doğrusala dönüştürülür. Mümkün değilse doğrusal olmayan regresyon yapılır (doğrusal olmayan regresyonun tek sebebi bu değildir).

> **Ek bilgi (derste anlatılmadı):** Örneğin $Y = b_1 e^{b_2 X}$ modelinde iki tarafın logaritması alınınca $\ln Y = \ln b_1 + b_2 X$ elde edilir; bu, $\ln b_1$ ve $b_2$ parametrelerinde doğrusaldır ve en küçük kareler formülüyle çözülebilir.

## 16. Analitik Çözümün Sınırı

$\beta = (X^TX)^{-1}(X^TY)$ analitik bir çözümdür: tek adımda bulunur. İteratif, adım adım ilerleyen bir süreç yoktur; yalnız matris çarpımı ve ters alma vardır.

Ancak bunun uygun olmadığı durumlar vardır, özellikle büyük ölçekli (large scale) problemlerde: örnek sayısının çok büyük olduğu ya da her örnekteki boyut (değişken) sayısının çok fazla olduğu durumlarda. Bir milyona bir milyonluk bir matrisi tutup tersini almak mümkün değildir. Bu yüzden doğrusal biçimde yazılabilen büyük ölçekli problemler bile günümüzde iteratif yöntemlerle, çok daha hızlı biçimde çözülüyor. Kuramsal olarak tek adımda çözülebilir, ama pratikte mümkün değildir.

> **Hocanın vurgusu:** İteratif optimizasyon iki yerde kullanılır: doğrusal modellerin büyük ölçekli hâllerinde ve doğrusal olmayan modellerde.

Gelecek hafta buradan devam edilecek ve asıl iteratif optimizasyon konusuna girilecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:34): $x^2 - 2 = 0$ denkleminin çözümünü bilgisayarla bulabilir miyiz? $\sqrt{2}$'nin değeri bilgisayarda tam olarak tutulabilir mi?

Derste verilen cevap: $x = \pm\sqrt{2}$'dir. $\sqrt{2}$ rasyonel değildir (iki tam sayının oranı olarak yazılamaz) ve ondalık açılımı sonsuzdur; bu yüzden bilgisayarda tam değeriyle tutulamaz, yalnız belli bir hata payıyla yaklaşık bulunabilir.

> **Çözüm (derste verilmedi):** Newton-Raphson ile yaklaşık değer: $f(x) = x^2 - 2$, $f'(x) = 2x$, $x_{n+1} = x_n - (x_n^2 - 2)/(2x_n)$. $x_0 = 1$'den başlanınca python ile $x_1 = 1.5$, $x_2 = 1.416667$, $x_3 = 1.414216$, $x_4 = 1.41421356237469$, $x_5 = 1.41421356237310$ bulunur. $x_4$ ile $x_3$ altıncı ondalık basamağa kadar aynı olduğu için slayttaki ölçüte göre 6 basamak doğruluk için $x_4$'te durulabilir.

**Soru 2** (ekrandan, 00:20:00 ve derste sözlü, 00:27:20): $f(x) = x^3 - 2x + 2$ fonksiyonuna birinci dereceden Newton-Raphson $x_0 = 0$'dan başlatılırsa ne olur?

Derste verilen cevap: 0 noktasındaki teğet x eksenini 1'de keser, 1 noktasındaki teğet x eksenini 0'da keser. İterasyon 0 ile 1 arasında sonsuza kadar gidip gelir (döngü sorunu) ve köke varılamaz. Python kontrolü: $x_1 = 0 - 2/(-2) = 1$, $x_2 = 1 - 1/1 = 0$, $x_3 = 1, \dots$

**Soru 3** (derste sözlü, 00:34:57): Bir öğrencinin sorusu: türevin boyutu fonksiyonun boyutundan bir eksik olmamalı mı? $x^2$ iki boyutluyken türevi $2x$ tek boyutlu değil mi?

Derste verilen cevap: Hayır. $x^2$'deki 2 boyut değil üstür. Boyut, fonksiyondaki değişken sayısıdır; $x^2$, $2x$ ve $x^{79}$ tek değişkenlidir. $n$ değişkenli bir fonksiyonun türevi (gradyanı) $n$ elemanlı bir vektördür.

**Soru 4** (ekrandan, 01:15:00): $X$ sınavdan önceki gece çalışılan saat, $Y$ sınav notu olsun. Yalnız $X$'e bakılırsa slayttaki dört ilişkiden (azalan doğru, yatay başlayıp azalan eğri, hızla yükselip yavaşça düşen eğri, artan doğru) hangisi daha mantıklıdır?

Derste tek doğru cevap verilmedi; öğrenciler yeşil (artan doğru), turkuaz ve sarı (bir noktaya kadar artıp sonra düşen) ilişkileri savundu. Hoca, sınav notunu etkileyen tek etkenin bir gece önceki çalışma süresi olmadığını vurguladı ve doğrusal ilişki (her bölgede aynı ilişki) ile doğrusal olmayan ilişki (bölgeye göre değişen ilişki) ayrımına geçti.

**Soru 5** (derste sözlü, 01:29:46): En küçük karelerde hatalar neden kareleri alınarak toplanır? Neden mutlak değer kullanılmaz?

Derste verilen cevap: Artı ve eksi hatalar birbirini götürmesin diye; örneğin $+3$ ve $-3$ doğrudan toplanınca iki büyük hata sıfırlanır. Mutlak değer sıfırda türevlenemediği için optimizasyonda tercih edilmez; kare fonksiyonu her yerde türevlenebilir.

**Soru 6** (derste sözlü, 01:31:58): Model $y = \beta$ (sıfırıncı dereceden) ise $n$ veri için en az karesel hatayı veren $\beta$ nedir?

Derste verilen cevap: $E(\beta) = \sum (y_i - \beta)^2$, $dE/d\beta = -2\sum(y_i - \beta) = 0$, buradan $\beta = \frac{1}{n}\sum y_i$; yani $y$'lerin ortalaması.

**Soru 7** (ekrandan, 01:40:00): $Y = X\beta$ biçimindeki bir modelde $X$ kare değilse $\beta$ nasıl tahmin edilir?

Derste verilen cevap: İki taraf $X^T$ ile çarpılır ($X^TX$ her zaman karedir): $X^TY = X^TX\beta$. Sonra $(X^TX)^{-1}$ ile çarpılarak $\beta = (X^TX)^{-1}(X^TY)$ bulunur.

**Soru 8** (ekrandan, 01:50:00): Gerçek model birinci dereceden iken ikinci dereceden modelin eğitim MSE'si (18.4368) birinci dereceden modelinkinden (21.0596) neden daha düşük çıkar?

Derste verilen cevap: Eğitim verisi üzerinde parametre sayısı arttıkça model eğitim kümesine daha çok yapışır (aşırı öğrenme). Daha karmaşık model eğitimde her zaman daha düşük hata verir; bu gerçek modelden daha iyi olduğu anlamına gelmez. Eğitim aralığının dışına çıkıldığında ikinci dereceden model doğrusallıktan uzaklaşır ve hatası büyür.

**Soru 9** (ekrandan, 02:00:00): Aşağıdaki modellerden hangileri parametrelere göre doğrusaldır: $Y = b_1\sin(X) + b_2\cos(X)$, $Y = \sin(b_1 X)$, $Y = b_1\exp(X_1) + b_2\cos(X_2) + b_3\cos(X_1)$, $Y = (b_1 X)/(b_2 + X)$?

Derste verilen ölçüt: parametreye göre türev parametreyi içermiyorsa doğrusaldır. $b_1\sin(X) + b_2\cos(X)$ ve $b_1\exp(X_1) + b_2\cos(X_2) + b_3\cos(X_1)$ doğrusaldır (slaytta "linear according to b" grubunda). $\sin(b_1 X)$ ve $(b_1 X)/(b_2 + X)$ doğrusal değildir (slaytta "non-linear according to b" grubunda); örneğin $\partial\sin(b_1 X)/\partial b_1 = X\cos(b_1 X)$, $b_1$'i içerir.

## Dersin Toparlaması

Ders iki parçadan oluştu. İlk parçada optimizasyonun temel araçları toparlandı: bir fonksiyonu bir noktada doğrusal kabul etmek (birinci dereceden Taylor), daha yüksek dereceli Taylor açılımları, bunun üzerine kurulan Newton-Raphson kök bulma yöntemi ve aynı fikrin türeve uygulanmasıyla elde edilen ikinci dereceden Newton-Raphson optimizasyonu. Çok boyutta türev gradyan vektörüne, ikinci türev Hessian matrisine dönüşür; kuadratik formdaki $Q$ matrisinin tanımlılığı fonksiyonun kase, ters kase ya da eyer biçiminde olduğunu söyler. Newton-Raphson adım sayısı bakımından gradyan inişinden çok hızlıdır, kuadratik fonksiyonda tek adımda varır. Ama Hessian'ın tersini almak yüksek boyutta uygulanamaz. Ayrıca yöntem döngüye girebilir ya da tepe noktasına gidebilir; bu yüzden her adımda $f$'nin azaldığı kontrol edilmelidir.

İkinci parçada regresyona geçildi. Model bir varsayımdır; en küçük kareler yöntemi yalnız bu varsayılan modelin parametrelerini, hata karelerinin toplamını en küçük yaparak bulur. Parametrelere göre doğrusal her model $\beta = (X^TX)^{-1}X^TY$ ile tek adımda çözülür. Örnek sayısı tahmini iyileştirir, gürültü kötüleştirir. Gerçekten karmaşık model eğitim verisine yapışır (aşırı öğrenme), gerçekten basit model yetersiz öğrenir; yetersiz öğrenme X-hata grafiğindeki örüntüden anlaşılır, aşırı öğrenme için test hatasına bakmak gerekir. Büyük ölçekli doğrusal problemlerde ve doğrusal olmayan modellerde analitik çözüm yerine iteratif optimizasyon kullanılır. Gelecek hafta bu iteratif optimizasyon yöntemleri (Adagrad, Adam gibi hızlı birinci dereceden yöntemler dahil) işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
