# Ders 10 Genişletilmiş Notu: Regresyon ve En Küçük Kareler Yöntemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Enterpolasyondan Regresyona
- 2. Hata Ölçüleri ve En Küçük Kareler Yaklaşımı
- 3. Doğrusal Regresyon
- 4. Sabit Terimsiz Doğru: $y = ax$
- 5. Polinom Regresyonu
- 6. Doğrusal Olmayan Fonksiyonların Doğrusallaştırılması
- 7. Trigonometrik (Periyodik) Regresyon
- 8. Çoklu Regresyon
- Örnek Sorular

## 1. Enterpolasyondan Regresyona

Bu dersin konusu regresyondur. Hoca konuya enterpolasyonu hatırlatarak girer. Elimizde $x$ ve $y$ ikililerinden oluşan bir veri seti vardır ve $y = f(x)$ gibi bir ilişki olduğu düşünülür. Amaç $x$'lerle $y$'ler arasındaki ilişkiyi bulmaktır. Enterpolasyonda noktaların tamamından geçen bir doğru ya da eğri üretilir, sonra aradaki noktalar tahmin edilir. Bu bir "tayin" değil, tahmindir; yüzde yüz gerçeği bulmak anlamına gelmez.

Tahtada $x_1$, $x_2$, $x_3$ noktalarından geçen bir eğri çizilir (ekrandan, 00:20:00). Her noktada gerçek değer $y_i$, üretilen değer $\hat{y}_i$ ise hata

$$\varepsilon_i = y_i - \hat{y}_i$$

olarak tanımlanır. Hoca şapka (hat) işaretinin tahmin edilen değer için kullanıldığını belirtir ve sorar: $\sum_{i=1}^{3} \varepsilon_i$ ne olur?

**Soru:** Enterpolasyonla üretilen eğri noktalardan geçiyorsa gerçek değerlerle üretilen değerler arasındaki farkların toplamı ne olur? **Cevap:** Bir öğrenci sıfır olacağını söyler. Hoca onaylar: üretilen fonksiyon zaten bu noktaların üzerinden geçecek şekilde kurulur.

Doğrusal, kuadratik, Gregory-Newton ve son görülen Lagrange enterpolasyonunun hepsi noktaların üzerinden geçer. Bu, hata açısından güzeldir ve özgün veriyi bozmaz. Ancak veri sayısı çok olduğunda iş bozulur: bir sürü örnek (sample) varsa her birinin üzerinden geçen bir fonksiyon üretmek güçleşir. Doğrusal ya da kuadratik enterpolasyon artık uygun olmaz.

Bu durumda noktaları belli bir hata payıyla temsil eden bir doğru ya da eğri üretilir. Bir noktanın gerçek değeri yerine doğrunun gösterdiği değer kullanılır; aradaki sapmaya $\varepsilon_1$, $\varepsilon_2$, ... denir. $n$ nokta için $\sum_{i=1}^{n} |\varepsilon_i|$ kesinlikle sıfırdan farklı çıkar. İşte bu regresyondur: eğri noktaların üzerinden geçmek zorunda değildir. Bazı noktalardan geçebilir ama genel olarak geçmez.

Hoca enterpolasyon için nokta sayısının az olmasının istendiğini hatırlatır: bir polinomun derecesinin bir fazlası kadar nokta varsa polinom üretilebiliyordu. Çok sayıda veri olduğunda regresyonla uğraşmak gerekir. Bir başka seçenek veri kümesinin farklı kısımlarına farklı enterpolasyonlar yapıp parçalı bir fonksiyon üretmektir; ama bu da gerçek fonksiyondan çok farklı sonuçlar doğurabilir.

> **Hocanın vurgusu:** Regresyon mu iyidir, enterpolasyon mu, bunun tam bir ölçüsü yoktur. Örneğin geçen hafta anlatılan ses dosyasının ya da görüntünün kalitesini artırma gibi veri üretme işlerinde parçalı enterpolasyon yapılır; buna spline enterpolasyonu denir. Bazı durumlarda ise regresyon daha iyi sonuç verir.

Hoca regresyonun genellikle zamana göre değişen olaylarda kullanıldığını söyler. Bir deneyde $n$ ölçüm yapılmış olabilir ve bu $n$ üç beş değil, belki bin olabilir. Regresyon en çok burada işe yarar. Veri doğrusal bir değişim gösteriyorsa bir doğru çizilir; bu doğrunun belli bir hatası olur. Aynı noktalardan geçirilebilecek başka doğrular ya da eğriler de vardır; amaç hangisi çizilecekse onu en az hatayla çizmektir.

## 2. Hata Ölçüleri ve En Küçük Kareler Yaklaşımı

**Soru:** Hataların toplamı sıfır olmayacaksa ne olması gerekir? **Cevap:** En küçük yapılması (minimize edilmesi) gerekir.

Hoca türevdeki maksimum-minimum problemlerini hatırlatır: bir fonksiyonun türevi alınıp sıfıra eşitlenirse türevin sıfır olduğu, yani fonksiyonun durağan olduğu noktalar bulunur. Regresyonda da hata bir fonksiyon olarak yazılır, türevi alınıp sıfıra eşitlenir ve bazı parametreler tahmin edilir. Bu parametreler hatayı (maliyeti) en küçük yapan çözümü verir. Buna en küçük kareler yaklaşımı denir.

> **Ders sonrası not:** Hoca bir yerde "toplam hatanın maksimize edilmesi" dedi (00:23:00); bağlamdan ve hemen sonraki anlatımdan doğrusu "minimize edilmesi"dir.

### 2.1 Mutlak hata ve karesel hata

Hatalar pozitif ya da negatif olabilir. Toplarken birbirlerini götürmesinler diye iki yol vardır:

- Mutlak değer almak: hataların mutlak değerleri toplanır (sum of absolute error). Kullanılabilir, ama hata en küçük yapılacağı için türev almak gerekir ve mutlak değerin türevini almak zordur.
- Kare almak: $\sum (y_i - \hat{y}_i)^2$ (sum of squared error). Bu toplam $n$'ye bölünürse ortalama karesel hata (mean squared error) bulunur.

Hoca, karelerin toplamının karekökünün de alınabildiğini söyler. Hata fonksiyonu her durumda en küçük yapılacak bir fonksiyondur. Tablodaki $x$ ve $y$'ler sayıdır; ama $\hat{y}_i$ bir eşitliktir, örneğin $\hat{y}_i = a x_i + b$. Regresyon modeli bu toplamı en küçük yapan $a$ ve $b$ bulunarak kurulur.

Ekrandaki slayt yaklaşımı şöyle özetler (ekrandan, 00:25:00): Fiziksel olayların çoğunda iki ya da daha fazla birbirine bağlı değişken bulunur; bir olayın deneysel sonucunun analitik olarak incelenmesi, olayın bir formüle bağlanmasıyla mümkündür. Bir sonraki slayta göre (ekrandan, 00:30:00) farklar negatif ya da pozitif olacağından farkların kendisi yerine karelerinin toplamını en küçük yapan fonksiyon aranır; bu da $A$ ve $B$ katsayılarının bulunmasıyla olur.

### 2.2 Neden karesel hata?

**Soru:** Her fonksiyonun türevi alınabilir mi, türevi alınamayan durumlar nelerdir? Bir şeyin türevli olması için ne gerekir? **Cevap:** Bir öğrenci fonksiyonun sürekli olması gerektiğini söyler. Hoca ekler: süreklilik şartı sağlanıyor, limit var ve bir kırılma ya da kopma noktası yoksa türev alınabilir.

Mutlak değer fonksiyonuyla kurulan hata bu açıdan sıkıntılıdır. Karesel ifadenin $a$'ya ya da $b$'ye göre türevi ise rahat alınır: 2 başa iner, içerinin kendisi yazılır ve içerinin türeviyle çarpılır. Hoca bu yüzden karesel hatanın "en uygun fonksiyon" olduğunu söyler.

> **Ek bilgi (derste anlatılmadı):** Mutlak değer fonksiyonu $|u|$ süreklidir ama $u = 0$ noktasında kırılma olduğu için orada türevlenemez. Bu yüzden mutlak hatayı en küçük yapan çözüm türevle doğrudan bulunamaz. Karesel hata her yerde türevlenebilir ve türevi doğrusal denklemler verir.

### 2.3 Kısmi türev

Bu yaklaşımda çok kullanılacak araç kısmi türevdir ($\partial$ işareti). Örneğin bir $t$ fonksiyonu $x$ ve $y$'ye bağlıysa, $x$'e göre kısmi türev $x$'teki değişimi, $y$'ye göre kısmi türev $y$'deki değişimi verir. Regresyonda bilinmeyen her parametreye göre ayrı bir kısmi türev alınır ve her biri sıfıra eşitlenir. Böylece bilinmeyen sayısı kadar doğrusal denklem çıkar. Bu denklem takımlarının çözümü dönemin ilk konularında görülmüştü.

> **Ders sonrası not:** Hoca türevi sıfıra eşitleyince "hatanın sıfıra yaklaşacağını varsaydığını" söyledi (00:31:00). Doğrusu, türevin sıfır olması hatanın sıfır olduğunu değil, hata fonksiyonunun en küçük değerine ulaştığını gösterir; regresyonda bu en küçük hata genelde sıfırdan büyüktür.

## 3. Doğrusal Regresyon

### 3.1 Normal denklemlerin türetilmesi

Doğru $y = ax + b$ biçiminde düşünülür; $a$ eğim, $b$ ise $x = 0$ noktasındaki $y$ değeridir. Slaytlarda aynı doğru $\hat{y}_i = A + Bx_i$ olarak yazılır (ekrandan, 00:35:00); burada $A$ sabit terim, $B$ eğimdir. Her nokta için gerçek değer ile doğrunun verdiği değer arasındaki uzaklık (distance) $d_i = y_i - A - Bx_i$'dir. Toplam karesel hata

$$S = \sum_{i=1}^{n} d_i^2 = d_1^2 + d_2^2 + \dots + d_n^2 = \sum_{i=1}^{n} (y_i - A - Bx_i)^2$$

olur (ekrandan, 00:30:00). $S$, $A$ ve $B$'nin değişkeni olarak değişir. $S$'nin $A$ ve $B$'ye göre türevleri alınıp sıfıra eşitlenirse $S$ en küçük değerine eşitlenmiş olur:

$$\frac{\partial S}{\partial A} = 0, \qquad \frac{\partial S}{\partial B} = 0$$

$A$'ya göre türevde 2 başa gelir, içerinin aynısı yazılır ve içerinin $A$'ya göre türevi alınır. $y_i$ ve $Bx_i$ sabittir, $-A$'nın türevi $-1$'dir. Bu $-1$ içeriye dağıtılınca:

$$\frac{\partial S}{\partial A} = \sum_{i=1}^{n} 2(A + Bx_i - y_i) = \sum 2A + \sum 2Bx_i - \sum 2y_i = 0$$

$B$'ye göre türevde içerinin türevi $-x_i$'dir:

$$\frac{\partial S}{\partial B} = \sum_{i=1}^{n} 2(A + Bx_i - y_i)\,x_i = \sum 2Ax_i + \sum 2Bx_i^2 - \sum 2x_i y_i = 0$$

Sağ taraf sıfır olduğu için 2'ler sadeleşir. $\sum_{i=1}^{n} A = nA$ ve $\sum_{i=1}^{n} Bx_i = B\sum_{i=1}^{n} x_i$ kullanılınca normal denklemler çıkar (ekrandan, 00:35:00):

$$nA + B\sum_{i=1}^{n} x_i = \sum_{i=1}^{n} y_i$$

$$A\sum_{i=1}^{n} x_i + B\sum_{i=1}^{n} x_i^2 = \sum_{i=1}^{n} x_i y_i$$

Hoca bunları "$A \pm B = C_1$, $A \pm B = C_2$" biçiminde iki bilinmeyenli iki denklem diye özetler. $n$, $\sum x_i$, $\sum y_i$, $\sum x_i^2$ ve $\sum x_i y_i$ verilerden hazır hesaplanır; geriye yalnız $A$ ile $B$'yi bulmak kalır. Bu tür sistemler genellikle matris biçimine dönüştürülür:

$$\begin{bmatrix} n & \sum x_i \\ \sum x_i & \sum x_i^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum x_i y_i \end{bmatrix}$$

Bu sistem determinantla ya da bilinen başka bir yolla çözülür. Bulunan doğru regresyon formülüdür; yeni değerler artık bunun üzerinden tahmin edilir.

### 3.2 Örnek: altı nokta

Altı noktadan geçen doğrusal regresyon istenir. $n = 6$'dır. Altyazıya göre $\sum x_i = 30$, $\sum x_i^2 = 220$, $\sum y_i = 66.1$, $\sum x_i y_i = 470.2$'dir. Hoca kareleri ayrı bir sütunda hesaplamanın iyi olacağını söyler. <!-- BELİRSİZ: Bu örneğin tablosu kare aralığına düşmedi; değerler altyazıdan alındı. $\sum x = 30$ ve $\sum x^2 = 220$, $x = 0, 2, 4, 6, 8, 10$ ile tutarlıdır ama tablo doğrulanamadı. -->

- Sistem: $6A + 30B = 66.1$, $30A + 220B = 470.2$.
- $\Delta = 6 \cdot 220 - 30^2 = 420$ (ara adım eklendi).
- $A = \dfrac{66.1 \cdot 220 - 30 \cdot 470.2}{420} = \dfrac{436}{420} \approx 1.038$ (ara adım eklendi).
- $B = \dfrac{6 \cdot 470.2 - 30 \cdot 66.1}{420} = \dfrac{838.2}{420} \approx 1.996$ (ara adım eklendi).

Sonuç $y \approx 1.038 + 1.996x$, yani yaklaşık $y = 2x + 1$ doğrusudur. Hoca $x$'in iki katı artı 1'in tablodaki değerlere yakın olduğunu, verinin aslında $2x$ gibi bir ilişkiye benzediğini, regresyonun ise yaklaşık bir sonuç verdiğini söyler. (Sayılar python ile doğrulandı.)

### 3.3 Örnek: on nokta

İkinci örnekte nokta sayısı artırılır (ekrandan, 00:40:00):

| $i$ | $x_i$ | $y_i$ | $x_i^2$ | $x_i y_i$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 1 | 2 | 8 | 4 | 16 |
| 2 | 3 | 10 | 9 | 30 |
| 3 | 4 | 14 | 16 | 56 |
| 4 | 5 | 17 | 25 | 85 |
| 5 | 7 | 22 | 49 | 154 |
| 6 | 8 | 26 | 64 | 208 |
| 7 | 9 | 29 | 81 | 261 |
| 8 | 10 | 32 | 100 | 320 |
| 9 | 12 | 35 | 144 | 420 |
| $\Sigma$ | 60 | 193 | 492 | 1550 |

(Karede 3. satırın $x_i y_i$ değeri önce yanlış yazılıp 56 olarak düzeltilmiştir.)

$$\begin{bmatrix} 10 & 60 \\ 60 & 492 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} 193 \\ 1550 \end{bmatrix}$$

- $\Delta = 10 \cdot 492 - 60 \cdot 60 = 4920 - 3600 = 1320$
- $\Delta A = \begin{vmatrix} 193 & 60 \\ 1550 & 492 \end{vmatrix} = 94956 - 93000 = 1956$
- $\Delta B = \begin{vmatrix} 10 & 193 \\ 60 & 1550 \end{vmatrix} = 15500 - 11580 = 3920$
- $A = 1956/1320 \approx 1.48$, $B = 3920/1320 \approx 2.97$

Sonuç $y = 1.48 + 2.97x$; hoca bunu yaklaşık $y = 3x + 1.5$ diye okur.

> **Ders sonrası not:** Karede $B = 2.96$ yazılmış; $3920/1320 = 2.9697$ olduğu için yuvarlanmış değer $2.97$'dir (python ile doğrulandı).

Hoca sonucu tablodaki bir satırla denerken önce indis değerini modele koyar, sonra düzeltir. $i$ burada yalnız indisi gösterir, bir değişken değildir; modele o satırdaki $x_i$ değeri konur. Örneğin $i = 8$ satırında $x = 10$'dur ve model $1.48 + 2.97 \cdot 10 \approx 31.2$ verir; gerçek değer $32$'dir (ara adım eklendi). Hoca ilk örnekte neredeyse sıfır hatalı, bu örnekte biraz daha hatalı bir doğru bulunduğunu söyler. Basit doğrusal regresyon budur.

### 3.4 Eğim ve kovaryans bağlantısı

Hoca iki noktası bilinen doğrunun eğimini hatırlatır: $m = \dfrac{y_2 - y_1}{x_2 - x_1}$. Regresyonda ise çok sayıda nokta vardır. Bu denklemin istatistiksel, kovaryansa dayanan bir çözümü de vardır: $y$'lerin toplam değişimi $x$'lerin toplam değişimine oranlanır ve benzer sonuç bulunur. Yani regresyon doğrusu, iki noktası bilinen doğru denkleminin genelleştirilmiş hâli gibi de görülebilir. Hoca konuyu en küçük karelerle anlatmasının sebebinin, ileride görülecek diğer yöntemlere iyi bir temel oluşturması olduğunu söyler.

## 4. Sabit Terimsiz Doğru: $y = ax$

İstenen doğru yalnız $y = ax$ ise, yani $b$ yoksa, tek bir parametre bulunur ve tek bir kısmi türev alınır:

$$S = \sum_{i=1}^{n} (y_i - a x_i)^2, \qquad \frac{\partial S}{\partial a} = \sum_{i=1}^{n} 2(y_i - a x_i)(-x_i) = 2\sum_{i=1}^{n} (a x_i^2 - x_i y_i) = 0$$

Toplam dağıtılınca $a\sum x_i^2 - \sum x_i y_i = 0$, yani

$$a\sum_{i=1}^{n} x_i^2 = \sum_{i=1}^{n} x_i y_i \quad\Rightarrow\quad a = \frac{\sum_{i=1}^{n} x_i y_i}{\sum_{i=1}^{n} x_i^2}$$

Karşı taraf sıfır olduğu için 2 doğrudan sadeleşir. Hoca bu oranın $y$'deki değişimin $x$'teki değişime oranlanması gibi olduğunu ve istatistikte kovaryans denen kavrama benzediğini anekdot olarak söyler.

> **Ek bilgi (derste anlatılmadı):** İstatistikte doğrusal regresyonun eğimi $B = \dfrac{\mathrm{Cov}(x,y)}{\mathrm{Var}(x)} = \dfrac{\sum (x_i - \bar{x})(y_i - \bar{y})}{\sum (x_i - \bar{x})^2}$ biçiminde de yazılır. $y = ax$ formülü, ortalamalar çıkarılmadan yazılmış benzer bir orandır.

Örnekte tablo $x = 3$ için $y = 2.25$, $x = 4$ için $y = 3$, $x = 5$ için $y = 3.75$ ile başlar. $\sum x_i y_i = 101.75$ ve $\sum x_i^2 = 135$ bulunur:

$$a = \frac{101.75}{135} \approx 0.7537$$

<!-- BELİRSİZ: Tablonun tamamı karelerde yok; yalnız ilk üç satır ve toplamlar altyazıdan alındı. -->

Hoca bu yolun pratik olduğunu söyler: zaman yoksa $x$'lerle $y$'leri çarpıp toplamak, $x$'lerin karelerini toplamak ve ikisini oranlamak yeterlidir; bulunan $a$ bir modeldir. Daha ayrıntılı bir model isteniyorsa, yani bir $b$ de eklenecekse, Bölüm 3'teki formül kullanılır. Hoca bu tür tahminlerin ileride meslekte, örneğin regresyonla tahmin yapılması gereken işlerde karşılarına çıkacağını ekler.

## 5. Polinom Regresyonu

### 5.1 Türetme

Polinom uydurulmak istenirse model $\hat{y}_i = A + Bx_i + Cx_i^2$ olur (ekrandan, 00:45:00). Slayt bunu şöyle verir: verilen noktalardan $F(x) = A + Bx + Cx^2$ parabolü geçirilmek istenirse hata kareleri toplamının en küçük olması için

$$S = \sum_{i=1}^{n} \left[(A + Bx_i + Cx_i^2) - y_i\right]^2$$

$A$, $B$ ve $C$'ye göre kısmi türevler alınıp sıfıra eşitlenir:

$$\frac{\partial S}{\partial A} = \sum_{i=1}^{n} 2\left[A + Bx_i + Cx_i^2 - y_i\right] = 0$$

$$\frac{\partial S}{\partial B} = \sum_{i=1}^{n} 2\,x_i\left[A + Bx_i + Cx_i^2 - y_i\right] = 0$$

$$\frac{\partial S}{\partial C} = \sum_{i=1}^{n} 2\,x_i^2\left[A + Bx_i + Cx_i^2 - y_i\right] = 0$$

$A$'ya göre türevde içerinin türevi 1'dir, bir şey değişmez. $B$'ye göre $x_i$, $C$'ye göre $x_i^2$ çarpanı gelir. 2'ler önce toplam sembolünün dışına çıkar, sonra sağ taraf sıfır olduğu için sadeleşir. Toplam sembolü dağıtılır ve $y$'li terimler karşıya atılır:

$$nA + B\sum x_i + C\sum x_i^2 = \sum y_i$$

$$A\sum x_i + B\sum x_i^2 + C\sum x_i^3 = \sum x_i y_i$$

$$A\sum x_i^2 + B\sum x_i^3 + C\sum x_i^4 = \sum x_i^2 y_i$$

Matris biçimi:

$$\begin{bmatrix} n & \sum x_i & \sum x_i^2 \\ \sum x_i & \sum x_i^2 & \sum x_i^3 \\ \sum x_i^2 & \sum x_i^3 & \sum x_i^4 \end{bmatrix}\begin{bmatrix} A \\ B \\ C \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum x_i y_i \\ \sum x_i^2 y_i \end{bmatrix}$$

Hoca burada bir örüntü yakalanmasını ister: üç bilinmeyen varsa kuvvetler dördüncü dereceye kadar toplanır. Sol üstte $n$ (yani $\sum x_i^0$) vardır; sağ alt köşe $\sum x_i^4$'tür, onun bir üstü ve bir yanı $\sum x_i^3$'tür, köşegene paralel olarak $\sum x_i^2$ gelir. Sağ taraf $\sum y_i$, $\sum x_i y_i$, $\sum x_i^2 y_i$'dir. Bulunan $A$, $B$, $C$ polinom yaklaşımını verir.

### 5.2 Örnek: $x = 2, 3, 5, 6, 8$

Ekrandaki örnek (ekrandan, 00:50:00):

| $x$ | $y$ | $x^2$ | $x^3$ | $x^4$ | $xy$ | $x^2 y$ |
|---|---|---|---|---|---|---|
| 2 | 1 | 4 | 8 | 16 | 2 | 4 |
| 3 | 6 | 9 | 27 | 81 | 18 | 54 |
| 5 | 22 | 25 | 125 | 625 | 110 | 550 |
| 6 | 33 | 36 | 216 | 1296 | 198 | 1188 |
| 8 | 61 | 64 | 512 | 4096 | 488 | 3904 |
| $\Sigma$ | 123 | 138 | 888 | 6114 | 816 | 5700 |

$\sum x = 24$, $n = 5$.

$$\begin{bmatrix} 5 & 24 & 138 \\ 24 & 138 & 888 \\ 138 & 888 & 6114 \end{bmatrix}\begin{bmatrix} A \\ B \\ C \end{bmatrix} = \begin{bmatrix} 123 \\ 816 \\ 5700 \end{bmatrix}$$

- $\Delta = 8316$
- $\Delta A = \begin{vmatrix} 123 & 24 & 138 \\ 816 & 138 & 888 \\ 5700 & 888 & 6114 \end{vmatrix} = -24948 \Rightarrow A = -3$
- $\Delta B = \begin{vmatrix} 5 & 123 & 138 \\ 24 & 816 & 888 \\ 138 & 5700 & 6114 \end{vmatrix} = 0 \Rightarrow B = 0$
- $\Delta C = \begin{vmatrix} 5 & 24 & 123 \\ 24 & 138 & 816 \\ 138 & 888 & 5700 \end{vmatrix} = 8316 \Rightarrow C = 1$

> **Ders sonrası not:** Karede $\Delta A = -24918$ yazılmış. Python ile hesaplanan değer $-24948$'dir ve $A = -24948/8316 = -3$ ancak bu değerle tam çıkar; $-24918$ yazım hatasıdır.

Sonuç $y = x^2 - 3$'tür. Hoca kontrol eder: $5^2 - 3 = 22$, tablodaki değerle birebir aynıdır; bu veri için regresyon sıfır hatayla sonuç verir. Tabloda olmayan $x = 4$ için tahmin

$$\hat{y} = \hat{f}(4) = 4^2 - 3 = 13$$

olur (ekrandan, 00:50:00). Hoca bunun bir tahmin olduğunu, gösterimde $y$ yerine $\hat{f}(x)$ yazmanın daha doğru olduğunu belirtir. En küçük kareler yöntemini "gayet şık bir yöntem" diye niteler; aynı yolla dördüncü ya da beşinci dereceden polinom da uydurulabilir.

## 6. Doğrusal Olmayan Fonksiyonların Doğrusallaştırılması

### 6.1 Veriye uygun fonksiyon seçmek

Bazı veriler polinomla iyi temsil edilemez. Hoca örnek olarak $2^x + 1$ fonksiyonunu modelleyen bir veri düşünür: $x = 1$ için 3, $x = 2$ için 5, $x = 3$ için 9 gibi. Gerçek fonksiyon bilinmese de veriler buna yaklaşıyorsa, üstel bir fonksiyonu polinomla temsil etmek hatayı çok artırır.

Bu yüzden önce verilen $x$ ve $y$'ler grafiğe çizdirilip neye benzediğine bakılır; bunun için çizim araçları vardır, Excel'de bile çizdirilebilir. Grafiğe göre:

- Üstel bir dağılım varsa polinom yapmaya gerek yoktur, üstel fonksiyon uydurulur.
- Çift bir fonksiyona ($x^2$, $x^4$, $\cos x$ gibi, $y$ eksenine göre simetrik) benziyorsa tek fonksiyon uydurmak anlamsızdır.
- Periyodikse sinüs ve kosinüse benzetilir.
- Logaritmik bir dağılım varsa logaritma fonksiyonuna benzetilir.

En küçük kareler yönteminde veri neye benziyorsa ona uygun bir fonksiyon uydurulmaya çalışılır.

### 6.2 Genel fikir

Slayt (ekrandan, 00:55:00): Bazı durumlarda deneylerden elde edilen değerlere bir polinom uyduramıyorsak fonksiyonları

$$F(x,a,b) = a\,e^{bx}, \qquad F(x,a,b) = a\,x^b$$

gibi katsayılar bakımından doğrusal olmayan başka şekillerde tanımlayabiliriz. Bu denklemlerin doğrudan çözümü güç olduğundan logaritmaları alınarak doğrusal yapılabilir.

Hoca doğal logaritmanın ($\ln$, $e$ tabanında) gerçek hayata daha uygun olduğu için genelde tercih edildiğini, ama logaritmanın başka bir tabanda da alınabileceğini söyler. Yöntem şudur: model logaritmayla $Y = A + Bx$ biçimine çevrilir, önce bu doğrusal regresyon çözülür, sonra büyük harfli katsayılar küçük harfli özgün katsayılara geri çevrilir.

### 6.3 $y = a\,b^x$ modeli

Her iki tarafın doğal logaritması alınır. Logaritmada çarpma toplamaya dönüşür, üs başa iner (ekrandan, 00:55:00):

$$y = a\,b^x \;\Rightarrow\; \ln y = \ln a + x\ln b \;\Rightarrow\; Y = A + Bx$$

Burada $Y = \ln y$, $A = \ln a$, $B = \ln b$'dir. Doğrusal regresyonla $A$ ve $B$ bulunduktan sonra her iki tarafın $e$ tabanında kuvveti alınarak logaritmadan kurtulunur:

$$a = e^{A}, \qquad b = e^{B}$$

Hoca anlatırken önce $a\,e^{bx}$ üzerinden başlar, sonra slaytta $e$ yerine sabit bir $b$ tabanı olduğunu fark edip düzeltir; ikisi de üstel fonksiyondur.

> **Hocanın vurgusu:** Matrise doğrudan $\sum y$ ve $\sum xy$ yazılmaz. Önce $y$'lerin $\ln$'i alınıp toplanır ($\sum \ln y$), sonra $x$ ile $\ln y$ çarpılıp toplanır ($\sum x\ln y$). $x$ tarafında değişiklik yoktur: $\sum x$ ve $\sum x^2$ aynen kalır.

**Örnek** (ekrandan, 01:05:00): $y = a\,b^x$ eğrisi geçirilecek.

| $x$ | $y$ | $\ln y$ | $x^2$ | $x\ln y$ |
|---|---|---|---|---|
| 0 | 5.2 | 1.649 | 0 | 0 |
| 2 | 56.628 | 4.037 | 4 | 8.074 |
| 3 | 186.872 | 5.230 | 9 | 15.690 |
| 4 | 616.679 | 6.424 | 16 | 25.696 |
| 5 | 2035.040 | 7.618 | 25 | 38.090 |
| $\Sigma$ 14 | | 24.958 | 54 | 87.550 |

$$\begin{bmatrix} 5 & 14 \\ 14 & 54 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} 24.958 \\ 87.550 \end{bmatrix}$$

- $\Delta = 5 \cdot 54 - 14^2 = 74$
- $\Delta A = 24.958 \cdot 54 - 14 \cdot 87.550 = 122.032$
- $\Delta B = 5 \cdot 87.550 - 14 \cdot 24.958 = 88.338$
- $A = 122.032/74 = 1.649081$, $B = 88.338/74 = 1.1937567$
- $a = e^{A} = 5.2021972$, $b = e^{B} = 3.2994532$

Sonuç $y \approx 5.202 \cdot 3.3^x$'tir (ekrandan, 01:05:00).

Hoca sonucu $x = 4$ ile denerken önce $3^4 = 81$'e 5 ekler, sonra karıştırdığını fark eder: işlem toplama değil çarpmadır ve taban 3 değil 3.3'tür. $3.3^4$ ile çarpınca tablodakine yakın, 600 civarında bir değer çıkacağını söyler ve regresyonda tablodaki değeri birebir bulmanın zorunlu olmadığını, hatanın sıfırdan farklı çıkabileceğini belirtir.

> **Ders sonrası not:** Python ile kontrol: $5.2 \cdot 3.3^4 = 616.68$, tablodaki $616.679$ ile aynıdır. Tablodaki bütün $y$ değerleri $5.2 \cdot 3.3^x$ ile üretilmiştir; bu yüzden bu veride regresyon hatası çok küçüktür ($5.202 \cdot 3.2995^4 \approx 616.5$).

### 6.4 $y = a\,x^b$ modeli

Bu kez taban değişkendir, üs sabittir. Logaritma alınınca (ekrandan, 01:15:00):

$$y = a\,x^b \;\Rightarrow\; \ln y = \ln a + b\ln x \;\Rightarrow\; Y = A + BX$$

Burada $Y = \ln y$, $X = \ln x$, $A = \ln a$, $B = b$'dir. Dolayısıyla $b$ doğrudan $B$'ye eşittir, $a = e^{A}$'dır. Hoca $Y = BX + A$ biçiminde yazmanın eşleştirmeyi kolaylaştıracağını söyler. Tek fark işin başındadır: matrise $x$'lerin toplamı yerine $\ln x$'lerin toplamı, $x^2$ toplamı yerine $(\ln x)^2$ toplamı, $y$ toplamı yerine $\ln y$ toplamı ve $xy$ toplamı yerine $\ln x \ln y$ toplamı yazılır:

$$\begin{bmatrix} n & \sum \ln x \\ \sum \ln x & \sum (\ln x)^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum \ln y \\ \sum \ln x \ln y \end{bmatrix}$$

**Örnek** (ekrandan, 01:15:00): $y = a\,x^b$ eğrisinin geçirilmesi.

| $x$ | $y$ | $\ln x$ | $\ln y$ | $(\ln x)^2$ | $\ln x \ln y$ |
|---|---|---|---|---|---|
| 1 | 3 | 0 | 1.099 | 0 | 0 |
| 3 | 15.588 | 1.099 | 2.747 | 1.208 | 3.019 |
| 5 | 33.541 | 1.609 | 3.513 | 2.589 | 5.652 |
| $\Sigma$ | | 2.708 | 7.359 | 3.797 | 8.671 |

$$\begin{bmatrix} 3 & 2.708 \\ 2.708 & 3.797 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} 7.359 \\ 8.671 \end{bmatrix}$$

Hoca hesaplanan $A$ ve $B$'yi slayttan okur; küçük $b$'nin $B$'ye eşit olduğunu, küçük $a$'nın ise "$e$ üzeri 1.099 falan" olacağını söyler. <!-- BELİRSİZ: Slayttaki sonuç değerleri karede görünmüyor. -->

> **Çözüm (python ile hesaplandı):** $A \approx 1.099$, $B \approx 1.4996$; $a = e^{1.099} \approx 3.00$, $b \approx 1.5$. Sonuç $y \approx 3\,x^{1.5}$'tir. Gerçekten $3 \cdot 3^{1.5} = 15.588$ ve $3 \cdot 5^{1.5} = 33.541$'dir.

Hoca bulunan fonksiyonun ne tam üstel ne de polinom olduğunu, çünkü üssün tam sayı olmadığını söyler; bu bir $f(x)$ yaklaşımıdır.

### 6.5 $y = a\,e^{bx}$ modeli

Logaritma alınınca $\ln e = 1$ olduğundan:

$$y = a\,e^{bx} \;\Rightarrow\; \ln y = \ln a + bx \;\Rightarrow\; Y = A + Bx$$

Burada $Y = \ln y$, $A = \ln a$, $B = b$'dir; yani $a = e^{A}$, $b = B$. Bu modelde $x$ tarafı değişmez. Hoca örnekte $\sum x = 3$ ve $\sum x^2 = 5$ olduğunu, $y$'lerin $\ln$'lerinin toplanıp $x$ ile $\ln y$ çarpımlarının toplanacağını söyler. Büyük $A$ ve $B$ bulunduktan sonra $b = B$, $a = e^{A}$ yazılarak denklem elde edilir ve tahminler bunun üzerinden yapılır. <!-- BELİRSİZ: Bu örneğin tablosu ve sonucu karelerde yok. -->

### 6.6 Özet

> **Hocanın vurgusu:** Bu üç yöntem genel yöntemlerdir ve ileride (örneğin veri madenciliği gibi derslerde) birçok yerde karşılarına çıkacaktır. Yaklaşım basittir: en küçük kareler yöntemi doğrusal regresyona uyarlanır, sonra katsayılar uygulanan dönüşüme göre geri çevrilir. Her yaklaşımda neyin $\ln$'inin alınıp neyin alınmayacağı eşitlikten çıkarılmalıdır; matrise doğrudan $\sum x$, $\sum y$ yazılmaz.

Hoca $b\,a^x$ ya da $b\,x^a$ biçiminde bir eşitlik istenirse de aynı yolun izleneceğini söyler: doğal logaritma alınarak $Y = AX + B$ formuna çevrilir. Doğrusal regresyonda özgün $x$'ler kullanılırken dönüştürülmüş modelde bunların $\ln$'leri kullanılır.

| Model | Doğrusal biçim | Matrise girenler | Geri dönüşüm |
|---|---|---|---|
| $y = a\,b^x$ | $\ln y = \ln a + x\ln b$ | $\sum x$, $\sum x^2$, $\sum \ln y$, $\sum x\ln y$ | $a = e^A$, $b = e^B$ |
| $y = a\,x^b$ | $\ln y = \ln a + b\ln x$ | $\sum \ln x$, $\sum (\ln x)^2$, $\sum \ln y$, $\sum \ln x\ln y$ | $a = e^A$, $b = B$ |
| $y = a\,e^{bx}$ | $\ln y = \ln a + bx$ | $\sum x$, $\sum x^2$, $\sum \ln y$, $\sum x\ln y$ | $a = e^A$, $b = B$ |

## 7. Trigonometrik (Periyodik) Regresyon

Veri çizdirildiğinde periyodik bir görünüm varsa sinüs ya da kosinüse benzetilebilir. Sinüs ve kosinüs ifadelerinin önünde bir katsayı ($a_1$), açının önünde de bir katsayı ($b_1$) bulunur; örneğin $a_1\sin(b_1 x)$, $a_2\sin(b_2 x)$ gibi. Herhangi bir veri dağılımı sinüs ve kosinüslerin toplamı, yalnız sinüslerin ya da yalnız kosinüslerin toplamı olarak yazılabilir. Hoca bunun Fourier analizinin temeli olduğunu söyler.

En genel biçim (ekrandan, 01:25:00):

$$F(x) = a_0 + a_1\cos x + b_1\sin x + a_2\cos 2x + b_2\sin 2x + \dots + a_n\cos nx + b_n\sin nx$$

$a_0$ sabit terimdir. Kosinüslerin önünde $a_k$, sinüslerin önünde $b_k$ katsayıları vardır. Bunlar bulunursa periyodik dağılan bir veri sinüs ve kosinüslerin toplamı olarak yazılabilir. Kaç terim kullanılacağının verilmesi gerekir; örneğin "üç terimli ve yalnız kosinüslü" denirse ona göre yazılır.

### 7.1 Üç terimli model

Özel olarak $F(x_i) = a_0 + a_1\cos x_i + b_1\sin x_i$ alınsın. Hata yine en küçük kareler ile tanımlanır: $M = \sum (y_i - \hat{y}_i)^2$, $\hat{y}_i = a_0 + a_1\cos x_i + b_1\sin x_i$. Her bilinmeyene göre türev alınır (ekrandan, 01:25:00):

$$\frac{\partial M}{\partial a_0} = 2\sum (a_0 + a_1\cos x_i + b_1\sin x_i - y_i)$$

$$\frac{\partial M}{\partial a_1} = 2\sum (a_0 + a_1\cos x_i + b_1\sin x_i - y_i)\cos x_i$$

$$\frac{\partial M}{\partial b_1} = 2\sum (a_0 + a_1\cos x_i + b_1\sin x_i - y_i)\sin x_i$$

İçerisi hemen hemen aynıdır; $a_0$'a göre türevde 1, $a_1$'e göre $\cos x_i$, $b_1$'e göre $\sin x_i$ çarpanı gelir. Hepsi sıfıra eşitlenip toplam sembolleri dağıtılınca matris biçimi çıkar. Matriste $n$, $\cos$'ların toplamı, $\cos$ karelerinin toplamı, sinüslerin toplamları vb. yer alır; sağ tarafta $y$'li toplamlar vardır. Her şey bilinir, yalnız $a_0$, $a_1$, $b_1$ bilinmez.

> **Hocanın vurgusu:** Bir terim grubu daha eklenirse ($a_2$, $b_2$) beş bilinmeyenli beş denklem çıkar ve iş "korkunç" görünür. Ama $\sum \cos x_i$ ve $\sum \sin x_i$ gibi toplamlar sıfıra gittiği için matris genellikle sıfırlardan oluşan, çözümü çok daha kolay bir biçime gelir.

> **Ek bilgi (derste anlatılmadı):** $x_i$ değerleri bir tam periyoda eşit aralıklarla yayıldığında $\sum \cos x_i$, $\sum \sin x_i$ ve $\sum \sin x_i \cos x_i$ tam olarak sıfır olur; $\sum \cos^2 x_i = \sum \sin^2 x_i = n/2$ olur. Bu yüzden matris köşegen hâle gelir. Veri böyle dağılmamışsa bu toplamlar yalnız yaklaşık olarak sıfırdır.

### 7.2 Dereceyle verilen örnekler

Derste değerleri derece cinsinden verilen bir veriyle $y = a_0 + a_1\sin x$ modeli kısaca gösterilir. $a_0$ ve $a_1$'e göre kısmi türevler alınınca

$$na_0 + a_1\sum \sin x_i = \sum y_i, \qquad a_0\sum \sin x_i + a_1\sum \sin^2 x_i = \sum y_i\sin x_i$$

denklemleri bulunur (ara adım eklendi; hoca bu iki denklemin içeriğini, yani $\sum y$, $\sum \sin x$, $\sum \sin^2 x$ ve $\sum y\sin x$ toplamlarının gerektiğini sözlü olarak söyler). Benzer bir örnek $\cos$ ile de yapılır. Hoca sonucu kullanarak örneğin 50 derecenin karşılığının, bulunan ifadede $\cos 50^\circ$ yerine konarak tahmin edileceğini söyler. <!-- BELİRSİZ: İki örneğin tabloları ve sonuçları karelerde yok; cos örneğinin sonucu altyazıda yaklaşık "1.6 eksi 2 çarpı cos x" diye geçiyor. -->

> **Hocanın vurgusu:** Bu işin anahtar kelimesi kısmi türevdir. En küçük kareler yaklaşımıyla hangi türden regresyon yapılacaksa, uydurulacak denklemin bilinmeyen parametrelerine göre türev alınıp denklemler çıkarılır. $\sin x$ gibi terimler veriden hesaplanan sabitlerdir.

## 8. Çoklu Regresyon

Şimdiye kadar bütün durumlar tek değişkenliydi: $\hat{y} = \hat{f}(x)$ biçiminde doğru ya da eğri üretildi. Birden fazla bağımsız değişken varsa buna çoklu regresyon denir. Slayt (ekrandan, 01:30:00): Temelde diğer eğri uydurma yöntemlerine benzer; farkı değişken sayısının birden fazla olmasıdır. Aranan katsayıların

$$Q = a_0\,D^{a_1}\,S^{a_2}$$

eşitliğinde gösterilen yapıda olduğunu düşünerek yöntem uygulanır. Burada $Q$, $D$ ve $S$ adlı iki değişkenle kontrol edilen bir fonksiyondur.

Üstel bir yapı olduğu için her iki tarafın logaritması alınır. Çarpım toplamaya dönüşür (ekrandan, 01:30:00):

$$\log Q = \log a_0 + a_1\log D + a_2\log S$$

$\log Q$'ya $Y$, $\log D$'ye $x_1$, $\log S$'ye $x_2$ denir; $\log a_0$ da bir sabit olarak yazılır. Böylece iki değişkenli doğrusal regresyon modeli elde edilir:

$$Y = a_0' + a_1 x_1 + a_2 x_2, \qquad a_0' = \log a_0$$

Hoca ikinci bir değişkenin çok şey değiştirmediğini, yalnız $x_2$'nin önüne bir katsayı geldiğini söyler. Bulunacaklar $a_0'$, $a_1$, $a_2$'dir. Her birine göre türev alınıp sıfıra eşitlenir: $a_0'$'a göre türevde 1, $a_1$'e göre $x_1$, $a_2$'ye göre $x_2$ çarpanı gelir. Burada $x_1^2$ ile $x_2$ gibi kuvvetler değil, iki ayrı değişken vardır. Hocanın benzetmesiyle iki boyutlu bir düzlem, "dümdüz bıçak gibi" bir şey tahmin edilir.

> **Ek bilgi (derste anlatılmadı):** Türevler sıfıra eşitlenince çıkan sistem $\begin{bmatrix} n & \sum x_1 & \sum x_2 \\ \sum x_1 & \sum x_1^2 & \sum x_1 x_2 \\ \sum x_2 & \sum x_1 x_2 & \sum x_2^2 \end{bmatrix}\begin{bmatrix} a_0' \\ a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} \sum Y \\ \sum x_1 Y \\ \sum x_2 Y \end{bmatrix}$ biçimindedir. Örnekteki matris bu yapıya uyar.

### 8.1 Örnek: kanal akışı

Kanal içindeki akışa ilişkin bir düzenekte boru içindeki akışkanın miktarı (quantity, $Q$), borunun çapı (diameter, $D$) ve eğimi (slope, $S$) ile verilir. $a_0$, $a_1$ ve $a_2$ isteniyor (ekrandan, 01:35:00). Logaritma 10 tabanındadır.

| $Q$ | $Y = \log Q$ | $D$ | $S$ | $x_1 = \log D$ | $x_2 = \log S$ |
|---|---|---|---|---|---|
| 1.4 | 0.146 | 1 | 0.001 | 0 | $-3$ |
| 8.3 | 0.919 | 2 | 0.001 | 0.301 | $-3$ |
| 24.2 | 1.384 | 3 | 0.001 | 0.477 | $-3$ |
| 4.7 | 0.672 | 1 | 0.01 | 0 | $-2$ |
| 28.9 | 1.461 | 2 | 0.01 | 0.301 | $-2$ |
| 84.0 | 1.924 | 3 | 0.01 | 0.477 | $-2$ |
| 11.1 | 1.045 | 1 | 0.05 | 0 | $-1.301$ |
| 69.0 | 1.839 | 2 | 0.05 | 0.301 | $-1.301$ |
| 200 | 2.301 | 3 | 0.05 | 0.477 | $-1.301$ |

Karedeki toplamlar: $\sum Y = 11.691$, $\sum x_1 = 2.334$, $\sum x_2 = -18.903$, $\sum x_1^2 = 0.954$, $\sum x_1 Y = 3.945$, $\sum x_1 x_2 = -4.903$, $\sum x_2^2 = 44.079$, $\sum x_2 Y = -22.207$.

$$\begin{bmatrix} 9 & 2.334 & -18.903 \\ 2.334 & 0.954 & -4.903 \\ -18.903 & -4.903 & 44.079 \end{bmatrix}\begin{bmatrix} a_0' \\ a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 11.691 \\ 3.945 \\ -22.207 \end{bmatrix}$$

Çözüm (ekrandan, 01:35:00): $a_0' = 1.7475$, $a_1 = 2.62$, $a_2 = 0.54$. Yani

$$\log Q = 1.7475 + 2.62\log D + 0.54\log S$$

$a_1$ ve $a_2$ doğrudan üslerdir, ama $a_0'$ logaritmadır: $\log a_0 = 1.7475$, $a_0 = 10^{1.7475} \approx 55.9$. Sonuç

$$Q = 55.9\,D^{2.62}\,S^{0.54}$$

olur. Hoca bu formülle, tabloda olmayan yeni bir $D$ ve $S$ değeri için akacak suyun miktarının tahmin edilebileceğini söyler.

> **Ders sonrası not:** Karedeki matriste ikinci satır ikinci sütun elemanı $0.924$ yazılmış, tablodaki toplam ise $0.954$'tür ($3 \cdot (0 + 0.0906 + 0.228) \approx 0.955$). Doğrusu $0.954$'tür: bu değerle çözüm $a_0' \approx 1.7475$, $a_1 \approx 2.620$, $a_2 \approx 0.537$ çıkar; $0.924$ ile $a_1 \approx 2.87$ olurdu. Ham veriyle doğrudan en küçük kareler çözümü de $a_0' \approx 1.748$, $a_1 \approx 2.616$, $a_2 \approx 0.537$ verir (python ile doğrulandı).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:23): Enterpolasyonla üretilen eğri $x_1, x_2, x_3$ noktalarının üzerinden geçiyorsa $\sum_{i=1}^{3} \varepsilon_i = \sum (y_i - \hat{y}_i)$ ne olur?

> **Cevap (derste verildi):** Sıfır olur. Enterpolasyon fonksiyonu bu noktaların üzerinden geçecek şekilde üretildiği için her noktada $\hat{y}_i = y_i$'dir.

**Soru 2** (derste sözlü, 00:22:00): Regresyonda hataların toplamı sıfır olmayacaksa ne olması gerekir?

> **Cevap (derste verildi):** En küçük yapılması gerekir. Hata fonksiyonunun parametrelere göre türevi alınıp sıfıra eşitlenir (en küçük kareler yaklaşımı).

**Soru 3** (derste sözlü, 00:28:47): Bir fonksiyonun türevli olması için ne gerekir? Hata ölçüsü olarak neden mutlak değer yerine kare tercih edilir?

> **Cevap (derste verildi):** Fonksiyonun sürekli olması, kırılma ya da kopma noktası olmaması gerekir. Mutlak değer fonksiyonu türev açısından sıkıntılıdır; karesel ifadenin türevi ise rahatça alınır.

**Soru 4** (ekrandan, 00:40:00): $x = 0, 2, 3, 4, 5, 7, 8, 9, 10, 12$ ve $y = 0, 8, 10, 14, 17, 22, 26, 29, 32, 35$ verilerine $y = A + Bx$ doğrusunu en küçük kareler yöntemiyle uydurunuz.

> **Çözüm (derste verildi):** $\sum x = 60$, $\sum y = 193$, $\sum x^2 = 492$, $\sum xy = 1550$. $\Delta = 1320$, $\Delta A = 1956$, $\Delta B = 3920$. $A \approx 1.48$, $B \approx 2.97$; $y = 1.48 + 2.97x \approx 3x + 1.5$.

**Soru 5** (ekrandan, 00:50:00): $x = 2, 3, 5, 6, 8$ ve $y = 1, 6, 22, 33, 61$ verilerine $y = A + Bx + Cx^2$ parabolünü uydurunuz ve $x = 4$ için değeri tahmin ediniz.

> **Çözüm (derste verildi):** $\sum x = 24$, $\sum x^2 = 138$, $\sum x^3 = 888$, $\sum x^4 = 6114$, $\sum y = 123$, $\sum xy = 816$, $\sum x^2 y = 5700$. $\Delta = 8316$; $A = -3$, $B = 0$, $C = 1$. $y = x^2 - 3$, $\hat{f}(4) = 13$.

**Soru 6** (ekrandan, 01:05:00): $x = 0, 2, 3, 4, 5$ ve $y = 5.2, 56.628, 186.872, 616.679, 2035.040$ verilerine $y = a\,b^x$ eğrisini uydurunuz.

> **Çözüm (derste verildi):** $\ln y = \ln a + x\ln b$. $\sum x = 14$, $\sum x^2 = 54$, $\sum \ln y = 24.958$, $\sum x\ln y = 87.550$. $\Delta = 74$, $A = 1.649081$, $B = 1.1937567$; $a = e^A \approx 5.202$, $b = e^B \approx 3.299$. $y \approx 5.202 \cdot 3.3^x$.

**Soru 7** (ekrandan, 01:15:00): $x = 1, 3, 5$ ve $y = 3, 15.588, 33.541$ verilerine $y = a\,x^b$ eğrisini uydurunuz.

> **Çözüm (derste kısmen verildi):** $\ln y = \ln a + b\ln x$. $\sum \ln x = 2.708$, $\sum (\ln x)^2 = 3.797$, $\sum \ln y = 7.359$, $\sum \ln x\ln y = 8.671$ (derste verildi). Sistem $3A + 2.708B = 7.359$, $2.708A + 3.797B = 8.671$ çözülünce $A \approx 1.099$, $B \approx 1.50$; $a = e^{A} \approx 3$, $b = 1.5$. $y \approx 3x^{1.5}$ (son adım python ile hesaplandı).

**Soru 8** (ekrandan, 01:35:00): Bir kanalda akış miktarı $Q$, boru çapı $D$ ve eğim $S$ ile Bölüm 8.1'deki tabloda verilmiştir. $Q = a_0 D^{a_1} S^{a_2}$ modelinin katsayılarını bulunuz.

> **Çözüm (derste verildi):** $\log Q = \log a_0 + a_1\log D + a_2\log S$ ile üç bilinmeyenli doğrusal sistem kurulur. $\log a_0 = 1.7475$, $a_1 = 2.62$, $a_2 = 0.54$; $a_0 \approx 55.9$. $Q = 55.9\,D^{2.62} S^{0.54}$.

## Dersin Toparlaması

Bu derste enterpolasyondan regresyona geçildi. Enterpolasyon bütün noktalardan geçen bir fonksiyon üretirken, regresyon çok sayıda veriyi en az hatayla temsil eden bir fonksiyon arar. Hata ölçüsü olarak türevi kolay alındığı için karelerin toplamı kullanılır. Uydurulacak modelin her bilinmeyen parametresine göre kısmi türev alınıp sıfıra eşitlenir ve çıkan doğrusal denklem sistemi (genelde matris biçiminde, determinantla) çözülür. Bu yolla doğrusal regresyon ($y = A + Bx$), sabit terimsiz doğru ($y = ax$) ve ikinci dereceden polinom regresyonu türetildi ve örneklerle çözüldü.

Doğrusal olmayan $a\,b^x$, $a\,x^b$ ve $a\,e^{bx}$ modelleri logaritma alınarak doğrusal regresyona indirgendi; burada hangi toplamlarda $\ln$ kullanılacağına dikkat etmek gerekir. Periyodik veriler için sinüs ve kosinüs terimli (Fourier temelli) regresyon, birden fazla bağımsız değişken için de logaritmayla doğrusallaştırılan çoklu regresyon gösterildi. Hoca bu konuyla dersin konularının bittiğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
