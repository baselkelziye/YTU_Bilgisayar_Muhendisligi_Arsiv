# Ders 11 Genişletilmiş Notu: Regresyon: En Küçük Kareler, Doğru ve Polinom Uydurma, Doğrusal Olmayan ve Trigonometrik Fonksiyonlar, Çoklu Regresyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Regresyon ve Enterpolasyon
- 2. En Küçük Kareler Yaklaşımı
- 3. Doğru Uydurma
- 4. Ezber Tuzağı: $y = ax$ Doğrusu
- 5. Parabol ve Polinom Uydurma
- 6. Kullanılacak Fonksiyonun Seçimi
- 7. Doğrusal Olmayan Fonksiyonlar
- 8. Trigonometrik Fonksiyonlar
- 9. Çoklu Regresyon
- 10. Soru: Gauss-Seidel'de Köşegeni En Büyük Yapmak

## 1. Regresyon ve Enterpolasyon

Hoca konuya, regresyonun enterpolasyonla karşılaştırıldığında çok daha kolay ve zevkli geleceğini söyleyerek girdi. Bunun sebebi şudur: Verilen noktalardan ister bir doğru, ister bir polinom, ister doğrusal olmayan bir fonksiyon geçirelim, hepsinde yapılan işlem aynıdır. Hoca bunu "üstüne vura vura" anlatacağını, baştaki kısım anlaşılırsa sonrakilerin onun tekrarı olacağını söyledi.

### 1.1 Ortak Yanlar ve Farklar

Regresyonun enterpolasyondan aslında çok büyük bir farkı yoktur. İkisinde de bir takım ölçümler yapılır: $x$ değerleri ve bunlara karşılık gelen $y$ değerleri vardır. Amaç, bu $x$ değerlerine karşılık bu $y$ değerlerini verecek fonksiyonu bulmaktır. Fark şurada: Enterpolasyonda bulunan değerler daha gerçekçi olabilir, fonksiyon noktaların üzerinden geçirilebilir. Regresyonda ise daha yaklaşık değerler bulunur ve amaç gerçek değerle bulunan fonksiyon arasındaki farkı en küçük yapmaktır. Üstelik regresyonda bu noktalardan ne geçirileceği de baştan belli değildir: Bir doğru mu, doğrusal bir fonksiyon mu, doğrusal olmayan bir fonksiyon mu?

Slaydın maddelerini hoca "hikâye" diye niteledi ve bir kez okunmasını istedi. O maddeler şunları söylüyor:

- Enterpolasyon, ayrık noktalarda değerleri bilinen bir fonksiyonun bu noktalardan geçen bir polinom veya başka bir fonksiyon ile yaklaşık olarak hesaplanmasıdır.
- Enterpolasyonda polinomlar için alınan nokta sayısı, polinomun üssünden bir fazla olmalıdır.
- Çok sayıda değerin bilindiği bazı problemlerde, iyi bir çözüm için bu değerlerin tümünün kullanılması gerekir.
- Yaklaşık kullanılan $F(x)$ fonksiyonu, verilen $f(x)$ fonksiyonunu ancak belli bir aralıkta temsil eder. Verilen aralığın dışında ikisi birbirinden çok farklı olabilir.

> **Ek bilgi (derste anlatılmadı):** Hoca dersin tamamında uydurulan $F$ fonksiyonuna "interpolasyon fonksiyonu" dedi. Bu adlandırma büyük olasılıkla bir önceki konudan gelen bir alışkanlıktır; regresyon kaynaklarında aynı şey büyük olasılıkla "regresyon fonksiyonu" ya da "uydurulan fonksiyon" diye geçer. Bu notta "uydurulan fonksiyon" denildi. Enterpolasyon fonksiyonu verilen noktaların hepsinden geçer, regresyon fonksiyonunun geçmesi gerekmez.

### 1.2 Hata Terimi

Elimizde ölçülen noktalar var. Gerçek fonksiyonu bilsek iş kalmazdı, ama bilmiyoruz. Bu yüzden noktalara uyabilecek bir fonksiyon uydurmaya çalışıyoruz; buna büyük $F$ diyoruz. $y_i$ ile $F(x_i)$ eşitse hocanın deyişiyle "cuk diye oturmuş" bir fonksiyon bulunmuş demektir. Gerçek dünyada bunu bulmak zordur.

Hoca, derste çözülen örneklerde sonuçların neden tam çıktığını da açıkladı. Örnekler için önce özel bir fonksiyon belirlenir, $x$ değerleri verilip $y$ değerleri hesaplanır ve sonra fonksiyon bilinmiyormuş gibi "bunu hangi fonksiyon sağlar?" diye sorulur. Gerçek dünyada ise uydurulan fonksiyona artı ya da eksi olabilen bir $\varepsilon$ hata miktarı eklenince gerçek değer elde edilir:

$$y_i = F(x_i) + \varepsilon_i$$

Slaytta $\varepsilon_i$ için $i$'nci ölçümdeki toplam hata deniyor ve $x_i$'lerin tespitinde de hata yapılmışsa çözümün gittikçe zorlaştığı ekleniyor. Enterpolasyonda doğrusal olmayan fonksiyonlar geçirmiştik; regresyonda da doğrusal olmayan fonksiyonlar uydurabiliriz. Ama bunları çözebilmek için önce doğrusal hâle getireceğiz.

## 2. En Küçük Kareler Yaklaşımı

Regresyon deyince akla gelen en önemli şey en küçük kareler yaklaşımıdır (hoca İngilizce karşılık olarak "min square error" dedi). Oldukça kolaydır ve başarılı sonuç verir. Slayttaki çıkış noktası şudur: Fiziksel olayların çoğunda iki veya daha fazla birbirine bağlı değişken bulunur ve bir olayın analitik olarak incelenmesi, olayın formüle bağlanmasıyla mümkündür. Belirli $x$ değerleri için alınan $y$ değerleri verilir ve bu noktalardan geçen fonksiyon aranır.

### 2.1 Neden Farkların Kareleri?

> **Hocanın vurgusu:** "En küçük kareler yönteminin en önemli şeyi şudur. Lütfen burayı çok iyi dinleyin."

Hoca tahtaya birkaç nokta ve bir doğru çizdi. Altı veriden yalnız ikisi doğrunun üzerine düşüyor; onlarda fark sıfırdır. Diğerlerinde $x$ değeri verildiğinde gerçek $y$ başka yerde, doğrunun verdiği $y$ başka yerdedir. Farklar artı ya da eksi yönde olabilir. En küçük kareler yaklaşımı işte bu farkları en küçük yapmaya çalışır.

Sonra sayılarla gösterdi. Dört noktadaki farklar şunlar olsun: $+5$, $-4$, $-3$, $+3$. Bunları doğrudan toplarsak $+3$ ile $-3$ birbirini götürür, $5 - 4 = 1$ kalır. Hata 1 gibi görünür ve "çok güzel bir fonksiyon buldum" diye sevinebiliriz. Oysa 1 olan bir hata yoktur: Gerçek sapmalar $5 + 4 + 3 + 3 = 15$ birimdir. Artıların ve eksilerin birbirini götürmesi, hatayı küçülmüş gibi gösterir.

Bu yanılgıdan kurtulmanın yolu farkların karelerini almaktır. "Kareler" ile kastedilen budur:

$$5^2 + (-4)^2 + (-3)^2 + 3^2 = 25 + 16 + 9 + 9 = 59$$

Toplam 59'u hoca söylemedi, "işte bir şey çıktı" dedi (ara adım eklendi). Önemli olan artı ve eksilerin artık birbirini götürmemesi ve gerçekten bir hata olduğunun görülmesidir. Amaç, bu toplamı belirlenen hata miktarından küçük eşit yapabilmektir.

### 2.2 Bütün Regresyonların Üzerine Kurulu Olduğu Formül

$d$ (distance), gerçek $y$ değeri ile uydurulan fonksiyonun verdiği değer arasındaki farktır. $n$ tane nokta varsa her biri için böyle bir fark vardır:

$$d_i = y_i - F(x_i), \qquad S = \sum_{i=1}^{n} d_i^2 = \sum_{i=1}^{n}\left(y_i - F(x_i)\right)^2$$

> **Hocanın vurgusu:** "Her şey bunun üzerine kurulu." Parantezin içindeki $F$ bir doğru, bir polinom, trigonometrik bir fonksiyon ya da başka herhangi bir fonksiyon olabilir.

Yöntem, her fonksiyon için şu adımlardan oluşur:

1. Gerçek $y_i$'den uydurulacak $F(x_i)$ çıkarılır.
2. Farkların karesi alınır ve 1'den $n$'e kadar toplanır. Bu toplama $S$ denir.
3. $F$'te kaç bilinmeyen katsayı varsa $S$'nin her birine göre ayrı ayrı türevi alınıp sıfıra eşitlenir.
4. Bilinmeyen sayısı kadar denklem çıkar. Bunlar matris biçiminde yazılıp çözülür.
5. Bulunan katsayılar $F$'te yerine konur.

## 3. Doğru Uydurma

### 3.1 Türetme

Önce örnek olarak bir doğru alalım: $F(x) = A + Bx$. Parantezi açınca $-A$ ve $-Bx_i$ gelir:

$$S = \sum_{i=1}^{n}\left(y_i - A - Bx_i\right)^2$$

İki bilinmeyen vardır, $A$ ve $B$. Slaytta türev alınırken parantez işaretleri ters çevrilmiş, yani $(A + Bx_i - y_i)$ yazılmıştır. Hoca bunun hiçbir şeyi değiştirmediğini belirtti, çünkü kare alınıyor ve denklem sıfıra eşitleniyor. Türev alırken "üst düşer": 2 öne gelir, parantezin kendisi yazılır ve parantezin ilgili bilinmeyene göre türeviyle çarpılır.

$$\frac{\partial S}{\partial A} = \sum_{i=1}^{n} 2\left(A + Bx_i - y_i\right)\cdot 1 = 2\sum A + 2B\sum x_i - 2\sum y_i = 0$$

$$\frac{\partial S}{\partial B} = \sum_{i=1}^{n} 2\left(A + Bx_i - y_i\right)\cdot x_i = 2A\sum x_i + 2B\sum x_i^2 - 2\sum x_i y_i = 0$$

Her iki taraftaki 2'ler sadeleşir, $y$'li terimler eşitliğin diğer tarafına geçer. Sabit sayılar toplamın dışına çıkabilir. Burada dikkat edilecek tek yer $\sum_{i=1}^{n} A$ terimidir: Bu, $n$ tane $A$'yı arka arkaya toplamak demektir, yani $A$'yı $n$ ile çarpmaktır, $nA$ olur. Sonuçta iki bilinmeyenli iki denklem kalır:

$$nA + B\sum x_i = \sum y_i$$

$$A\sum x_i + B\sum x_i^2 = \sum x_i y_i$$

### 3.2 Matris Biçimi

Aynı denklemler katsayılar matrisi, bilinmeyenler ve çıktı matrisi olarak yazılır:

$$\begin{bmatrix} n & \sum x_i \\ \sum x_i & \sum x_i^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum x_i y_i \end{bmatrix}$$

Bir soruda "bu noktalardan bir doğru geçirin" dendiği an kullanılacak şey budur. Matrisin düzenine dikkat: $n$ ve $\sum x_i$ ile başlayan satırda değerler bir sonraki satırda bir kayar. Hoca, ikinci dereceden bir denklem geçirildiğinde bunun nasıl değişeceğini göstereceğini söyledi.

Hoca formülü unutan birinin ne yapacağını da tahtada gösterdi: Gerçek fonksiyon $y$, geçirilecek olan $A + Bx$, farkları, kareleri, sigma, sonra $A$'ya ve $B$'ye göre türev. $A$'ya göre türevde parantezin türevi $-1$, $B$'ye göre türevde $-x_i$ olur. Parantezi $y_i - A - Bx_i$ biçiminde bırakınca çıkan matris aynıdır. Yani matris ezberde kalmasa da birkaç satırda yeniden çıkarılabilir.

### 3.3 Örnek 1

Verilen noktalardan bir doğru geçirelim.

| $x$ | $y$ | $x^2$ | $xy$ |
|---:|---:|---:|---:|
| 0 | 1 | 0 | 0 |
| 2 | 5.1 | 4 | 10.2 |
| 4 | 9 | 16 | 36 |
| 6 | 13 | 36 | 78 |
| 8 | 17 | 64 | 136 |
| 10 | 21 | 100 | 210 |
| **Toplam: 30** | **66.1** | **220** | **470.2** |

Altı veri olduğu için $n = 6$'dır. $x$'lerin toplamı için hoca $10 + 8 + 6 + 4 + 2 = 30$ diye topladı. Matris:

$$\begin{bmatrix} 6 & 30 \\ 30 & 220 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} 66.1 \\ 470.2 \end{bmatrix}$$

Çözüm için önce katsayılar matrisinin determinantı bulunur. $A$ için birinci sütuna, $B$ için ikinci sütuna $y$ sütunu konur:

$$\Delta = 6 \cdot 220 - 30 \cdot 30 = 420$$

$$\Delta_A = \begin{vmatrix} 66.1 & 30 \\ 470.2 & 220 \end{vmatrix} = 14542 - 14106 = 436$$

$$\Delta_B = \begin{vmatrix} 6 & 66.1 \\ 30 & 470.2 \end{vmatrix} = 2821.2 - 1983 = 838.2$$

$$A = \frac{\Delta_A}{\Delta} = \frac{436}{420} = 1.038, \qquad B = \frac{\Delta_B}{\Delta} = \frac{838.2}{420} = 1.996$$

$$y = 1.038 + 1.996x$$

Hoca bu dersteki matris çözme yöntemlerinin de kullanılabileceğini, ama küçük sistemlerde bu yolun çok daha kolay ve pratik olduğunu söyledi.

> **Ders sonrası not:** Hoca $\Delta$ için "diskriminant" dedi; doğrusu **determinant**tır. Kullanılan yol Cramer kuralıdır.

Kontrol: $x = 0$ için $y = 1.038$ çıkar, gerçek değer 1'dir. Hoca aradaki farkı $+0.038$ diye söyledi; ikinci noktada da 5.1 yerine örneğin 5.3 bulunabileceğini ekledi. Bu farkların karelerinin toplamı küçük olduğu için fonksiyon kabul edilir.

> **Ders sonrası not:** Hocanın $+0.038$'i $F - y$ farkıdır; $d_i = y_i - F(x_i)$ tanımıyla işaret eksidir ($-0.038$). Karesi alındığı için sonuç değişmez. Python ile hesaplandı: Bu örnekte ikinci noktada $F(2) = 5.03$ çıkar ve kareler toplamı $S = 0.00705$'tir.

### 3.4 Örnek 2

İkinci soruda hoca, artık her şeyin rahatlıkla söylenebileceğini belirterek yalnız şunları sordu: Doğru geçirilecekse hangi matris kullanılır, nelere ihtiyaç vardır? Veri $x$: 0, 2, 3, 4, 5, 7, 8, 9, 10, 12 ve $y$: 0, 8, 10, 14, 17, 22, 26, 29, 32, 35 biçimindedir.

$$n = 10, \quad \sum x = 60, \quad \sum x^2 = 492, \quad \sum y = 193, \quad \sum xy = 1550$$

$$\begin{bmatrix} 10 & 60 \\ 60 & 492 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} 193 \\ 1550 \end{bmatrix}$$

$$\Delta = 4920 - 3600 = 1320, \quad \Delta_A = 94956 - 93000 = 1956, \quad \Delta_B = 15500 - 11580 = 3920$$

$$A = \frac{1956}{1320} = 1.48, \qquad B = \frac{3920}{1320} = 2.97$$

$$y = 1.48 + 2.97x$$

$x = 0$ için $y = 1.48$ çıkar, oysa gerçek $y$ 0'dır. Yani 1.48'lik bir sapma vardır ve diğer noktalarda sapmalar daha büyük olabilir.

> **Ders sonrası not:** Slaytta $B = 2.96$ yazıyor; python ile hesaplandı, $3920/1320 = 2.9697$'dir, yani yuvarlanınca 2.97 olur. Kareler toplamı $S = 9.98$ çıkar. Hoca bir sonraki paragraftaki ölçütü "sapmaların toplamı" diye söyledi; yöntemin baktığı büyüklük sapmaların **kareleri** toplamıdır.

### 3.5 Sapma Çok Büyükse

Sapmalar bir hata bedelinden çok büyük çıkıyorsa bu noktalardan bir doğru geçmiyor demektir. O zaman bir polinom ya da üstel bir fonksiyon denenir. Hoca, soru çözerken geçirilecek fonksiyonun genelde söyleneceğini belirtti. Gerçek dünyada ise verilen $x, y$ değerleri çizilip gözle bakılır: "Buradan doğru geçmesine olanak yok, bu parabole çok benziyor" denebilir.

Tahtada parabol biçiminde dizilmiş noktalar çizdi. Böyle noktalardan "doğru geçireceğim" diye inatlaşmanın anlamı yoktur. Doğru en fazla birkaç noktayı yakalar, kalanlar üzerinde kalmaz ve hata payları çok büyür. Bulunan değerler gerçek $y$'nin çok üstünde ya da altında kalır, sonuca yaklaştırmaz. Bu durumda başka bir fonksiyon denenir.

## 4. Ezber Tuzağı: $y = ax$ Doğrusu

Bu, daha önce bir vizede sorulmuş bir soruydu. Hoca sınıfın büyük çoğunluğunun çözemediğini, sebebinin de ezber olduğunu söyledi. Öğrenci "hoca bize doğru diye başka bir şey öğretti, bunun matrisini ne yazacağım?" diye kalmıştı. Oysa yapılacak şey her zamankinin aynısıdır.

Soru: Verilen noktalardan $y = ax$ doğrusunu geçiriniz. Burada uydurulacak $F$ fonksiyonu yalnız $ax$'tir:

$$S = \sum_{i=1}^{n}\left(y_i - ax_i\right)^2$$

Tek bilinmeyen $a$ olduğundan tek denklem yeter. $S$'nin $a$'ya göre türevi alınır. Üst düşer, parantez yazılır ve parantezin $a$'ya göre türevi olan $-x_i$ ile çarpılır:

$$\frac{\partial S}{\partial a} = -2\sum_{i=1}^{n} x_i\left(y_i - ax_i\right) = 0$$

$a$'yı eşitliğin sol tarafına bırakırsak:

$$a\sum x_i^2 = \sum x_i y_i \quad\Rightarrow\quad a = \frac{\sum x_i y_i}{\sum x_i^2}$$

| $x$ | $y$ | $x^2$ | $xy$ |
|---:|---:|---:|---:|
| 3 | 2.25 | 9 | 6.75 |
| 4 | 3 | 16 | 12 |
| 5 | 3.75 | 25 | 18.75 |
| 6 | 4 | 36 | 24 |
| 7 | 5.75 | 49 | 40.25 |
| **Toplam** | | **135** | **101.75** |

$$a = \frac{101.75}{135} = 0.7537, \qquad y = 0.7537x$$

Hoca değeri sözlü olarak yaklaşık 0.75 diye okudu. Slaytta bir yerde 0.7527 yazıyor; python ile hesaplandı, doğrusu 0.7537'dir.

Ardından hoca, bu çözüm akla gelmese de ezberlenen doğru matrisinden de çıkılabileceğini söyledi: Doğru matrisinde $A$ ve $B$ vardı, burada bir bilinmeyen eksiktir, ilgili kısım otomatik olarak sıfırdır. Geriye kalan denklemlerden $a$ bulunur.

> **Ders sonrası not:** Hoca burada "B yok, sıfırdır" dedi ve iki denklemin "bir tanesinden bile" $a$'nın bulunabileceğini söyledi; doğrusu farklıdır. $y = ax$'te sabit terim yoktur, yani sıfır olan $A$'dır ve $a$, matristeki $B$'nin yerindedir. Üstelik yalnız **ikinci** denklem geçerlidir: $a\sum x_i^2 = \sum x_i y_i$. Birinci denklem $\partial S/\partial A$'dan gelir ve modelde $A$ olmadığı için yazılamaz. Python ile hesaplandı: Birinci denklemden $a = 18.75/25 = 0.75$ çıkar ve $S = 0.5000$ olur; ikinci denklemden $a = 0.7537$ ve $S = 0.4981$ olur. En küçük kareler çözümü ikincisidir.

> **Hocanın vurgusu:** "Arkadaşlar ezberleme yok." Gerçek $y$ değerin bu, sana geçir dedikleri fonksiyon bu. Farklarını al, $n$ tane değer olduğu için sigma koy, artı ve eksiler birbirini götürmesin diye karesini al. Sonra bilinmeyen kaç taneyse her birine göre türev alıp sıfıra eşitle.

## 5. Parabol ve Polinom Uydurma

### 5.1 Parabolün Matrisi

Şimdi noktalardan doğru değil, parabol geçirilmesi istensin: $F(x) = A + Bx + Cx^2$. Hoca, bunun $Ax^2 + Bx + C$ biçiminde de verilebileceğini, nasıl verildiğinin hiç önemli olmadığını söyledi. Gerçek $y$'den fonksiyon çıkarılır, $n$ nokta için sigma konur ve farkların karesi alınır:

$$S = \sum_{i=1}^{n}\left(y_i - A - Bx_i - Cx_i^2\right)^2$$

Üç bilinmeyen olduğu için üç türev alınır. Parantezin $A$'ya göre türevi $-1$, $B$'ye göre $-x_i$, $C$'ye göre $-x_i^2$'dir:

$$\frac{\partial S}{\partial A} = -2\sum\left(y_i - A - Bx_i - Cx_i^2\right) = 0$$

$$\frac{\partial S}{\partial B} = -2\sum x_i\left(y_i - A - Bx_i - Cx_i^2\right) = 0$$

$$\frac{\partial S}{\partial C} = -2\sum x_i^2\left(y_i - A - Bx_i - Cx_i^2\right) = 0$$

Slaytta işaretler ters yazılmış, $F$'ten $y$ çıkarılmıştır. Hoca bunun değişen bir şey olmadığını tekrarladı. Aynı işlemler yapıldığında matris şöyledir:

$$\begin{bmatrix} n & \sum x_i & \sum x_i^2 \\ \sum x_i & \sum x_i^2 & \sum x_i^3 \\ \sum x_i^2 & \sum x_i^3 & \sum x_i^4 \end{bmatrix}\begin{bmatrix} A \\ B \\ C \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum x_i y_i \\ \sum x_i^2 y_i \end{bmatrix}$$

### 5.2 Desen

Doğrunun matrisi ile yan yana konunca desen görülür. Her satırda $x$'in kuvveti bir artarak sağa, bir alt satırda da bir kayarak devam eder. Sağ tarafta ise $y$, $xy$, $x^2y$ sırası vardır.

Hoca 3. derece için ne ekleneceğini tek tek söyledi: İlk satıra $\sum x^3$, ikinci satıra $\sum x^4$, üçüncü satıra $\sum x^5$; bilinmeyenlere $D$, sağ tarafa $\sum x^3y$ gelir. Dördüncü satır aynı kaymayla yazılır (ara adım eklendi):

$$\begin{bmatrix} n & \sum x & \sum x^2 & \sum x^3 \\ \sum x & \sum x^2 & \sum x^3 & \sum x^4 \\ \sum x^2 & \sum x^3 & \sum x^4 & \sum x^5 \\ \sum x^3 & \sum x^4 & \sum x^5 & \sum x^6 \end{bmatrix}\begin{bmatrix} A \\ B \\ C \\ D \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum xy \\ \sum x^2y \\ \sum x^3y \end{bmatrix}$$

> **Ders sonrası not:** Hoca "beşinci dereceden olsaydı" diyerek bilinmeyen olarak $E$'yi ve sağ tarafa $\sum x^4y$'yi söyledi. Bunlar **dördüncü** dereceye aittir ($A$'dan $E$'ye beş bilinmeyen). Beşinci derecede bilinmeyen $F$, sağ taraftaki terim $\sum x^5y$ olur.

Değişen bir şey yoktur: Hep $y$'den geçirilmek istenen fonksiyonun farkının kareleri toplanır, bilinmeyenlere göre türev alınıp sıfıra eşitlenir. Bunları matris biçiminde yazmak çok daha kolaydır. Örneğin elinizde matris çözümü için yazılmış bir kütüphane varsa bu matrisi ve çıktıları verirsiniz, o da $A$, $B$, $C$ katsayılarını çözer.

### 5.3 Örnek

Verilen noktalardan $F(x) = A + Bx + Cx^2$ geçirelim. Gerekenler: $\sum x$, $\sum x^2$, $\sum x^3$, $\sum x^4$, $\sum y$, $\sum xy$, $\sum x^2y$.

| $x$ | $y$ | $x^2$ | $x^3$ | $x^4$ | $xy$ | $x^2y$ |
|---:|---:|---:|---:|---:|---:|---:|
| 2 | 1 | 4 | 8 | 16 | 2 | 4 |
| 3 | 6 | 9 | 27 | 81 | 18 | 54 |
| 5 | 22 | 25 | 125 | 625 | 110 | 550 |
| 6 | 33 | 36 | 216 | 1296 | 198 | 1188 |
| 8 | 61 | 64 | 512 | 4096 | 488 | 3904 |
| **24** | **123** | **138** | **888** | **6114** | **816** | **5700** |

$$\begin{bmatrix} 5 & 24 & 138 \\ 24 & 138 & 888 \\ 138 & 888 & 6114 \end{bmatrix}\begin{bmatrix} A \\ B \\ C \end{bmatrix} = \begin{bmatrix} 123 \\ 816 \\ 5700 \end{bmatrix}$$

Determinantlarla çözülürse $\Delta = 8316$, $\Delta_A = -24948$, $\Delta_B = 0$, $\Delta_C = 8316$ çıkar. Buradan $A = -3$, $B = 0$, $C = 1$ olur. $B$'nin katsayısı sıfır çıktığı için geçirilmesi gereken fonksiyon:

$$y = x^2 - 3$$

Hoca kontrol etti: $x = 2$ için $4 - 3 = 1$, $x = 3$ için $9 - 3 = 6$, $x = 5$ için $25 - 3 = 22$. "Cuk cuk" çıkıyor, çünkü veriler bu fonksiyondan üretilmiş ve fonksiyon bilinmiyormuş gibi sorulmuştur.

> **Ders sonrası not:** Slayttaki tabloda $x = 6$ satırında $x^2y$ değeri 1118 yazılıdır; python ile hesaplandı, doğrusu $36 \cdot 33 = 1188$'dir. Toplam 5700 doğru değerle tutar.

## 6. Kullanılacak Fonksiyonun Seçimi

Aradan sonra hoca, en küçük kareler yönteminde kullanılacak fonksiyonun nasıl seçileceğine geçti. Slayttaki maddeler ve hocanın anlatımı şöyledir:

1. **Fark tablosu:** Enterpolasyonda olduğu gibi bir fark tablosu çıkarılır. Fark kaçıncı dereceden sabitlendiyse o dereceden bir polinom geçirilebilir.
2. **Simetri:** Grafik çizilir ve simetri aranır. Noktalar $y$ eksenine göre simetrikse $F(x) = \sum_{k} C_k x^{2k+2}$ gibi bir polinom kullanılabilir.
3. **Periyodiklik:** Verilen değerler periyodik olarak değişiyorsa sinüs ve kosinüs terimlerinden oluşan bir fonksiyon kullanılır.
4. **Logaritmik kâğıt:** Slayta göre logaritmik kâğıt üzerine çizilen grafik, kullanılacak logaritmik veya üstel fonksiyon hakkında bilgi verebilir. Hoca bu maddeye değinmedi.
5. **Parçalara ayırma:** Bazen değerler birbirinden çok ayrık olur. Grafik parçalara ayrılır ve her parçaya ayrı bir eğri uydurulur. Hocanın tahtadaki örneğinde bir bölgeye simetrik bir eğri, diğer bölgeye bir doğru geçiriliyordu.

<!-- BELİRSİZ: Slayttaki simetri formülünde toplamın üst sınırı el yazısında net okunmuyor, altyazıda da söylenmiyor; bu yüzden üst sınır yazılmadı. -->

## 7. Doğrusal Olmayan Fonksiyonlar

### 7.1 Doğrusal Olmak Ne Demek?

Buraya kadar hep doğrusal fonksiyonlar kullanıldı: $A + Bx$, $A + Bx + Cx^2$. Ama bazen verilen değerlere bir polinom uydurulamaz. Örneğin $ae^{bx}$ ya da $ax^b$ geçirilmek istenebilir. Hocanın ölçütü şudur: Bir şeylerin üzerinde (üssünde) başka bir bilinmeyen varsa fonksiyon doğrusal olmaz. $ax^2$ doğrusaldır, $x$'in üssü bilinen bir sayıdır. Ama $e$ üzeri bilinmeyen içeren ifadeler doğrusal değildir.

> **Ek bilgi (derste anlatılmadı):** Hocanın $ax^2$'ye doğrusal demesinin sebebi, buradaki doğrusallığın büyük olasılıkla $x$'e göre değil **bilinmeyen katsayılara göre** düşünülmesidir. $A + Bx + Cx^2$, $x$'e göre eğri olsa da $A$, $B$, $C$'ye göre doğrusaldır. Bu yüzden türevleri alınca doğrusal bir denklem takımı çıkar. $ae^{bx}$'te ise $b$ üste çıktığı için türev denklemleri $b$'ye göre doğrusal olmaz.

Yol şudur: Doğrusal olmayan fonksiyon doğrusal hâle getirilir ve bildiğimiz yoldan gidilir. Doğrusal hâle getirmek için eşitliğin her iki tarafının logaritması alınır ve sonuç $Y = A + BX$ biçimine benzetilir.

### 7.2 Üç Dönüşüm

**$y = ae^{bx}$.** Her iki tarafın doğal logaritması alınır. Çarpım toplama döner, $bx$ öne düşer ve $\ln e = 1$'dir:

$$\ln y = \ln a + bx$$

$Y = \ln y$, $A = \ln a$, $B = b$, $X = x$ denirse $Y = A + BX$ olur.

**$y = ax^b$.** Yine logaritma alınır:

$$\ln y = \ln a + b\ln x$$

$Y = \ln y$, $A = \ln a$, $B = b$, $X = \ln x$. Hoca bunu şöyle söyledi: Matriste $y$ olan her yere $\ln y$, $x$ olan her yere $\ln x$ yazılır.

**$y = ab^x$.** Bu kez $x$ üstten düşer:

$$\ln y = \ln a + x\ln b$$

$Y = \ln y$, $A = \ln a$, $B = \ln b$, $X = x$. Dikkat: Fonksiyonda bize küçük $a$ ve küçük $b$ lazımdır. Bu yüzden büyük $A$ ve $B$ bulunduktan sonra geri dönüşüm yapılır: $a = e^A$, $b = e^B$.

| Fonksiyon | $Y$ | $X$ | $A$ | $B$ | Geri dönüşüm |
|---|---|---|---|---|---|
| $y = ae^{bx}$ | $\ln y$ | $x$ | $\ln a$ | $b$ | $a = e^A$, $b = B$ |
| $y = ax^b$ | $\ln y$ | $\ln x$ | $\ln a$ | $b$ | $a = e^A$, $b = B$ |
| $y = ab^x$ | $\ln y$ | $x$ | $\ln a$ | $\ln b$ | $a = e^A$, $b = e^B$ |

> **Ek bilgi (derste anlatılmadı):** Logaritma alındıktan sonra en küçük kareler büyük olasılıkla $y$ üzerindeki hataları değil, $\ln y$ üzerindeki hataları en küçük yapar. Bu yüzden bulunan katsayılar, hatayı doğrudan $y$ üzerinde küçültmeye çalışan bir çözümden biraz farklı olabilir. Ders kapsamında bu fark önemsenmedi.

### 7.3 Örnek: $y = ab^x$

Önce doğrusal hâle getirilir: $\ln y = \ln a + x\ln b$. Doğru matrisinde $n$ aynı kalır, $x$'ler zaten $x$'tir, $y$ yerine $\ln y$ konur.

| $x$ | $y$ | $\ln y$ | $x^2$ | $x\ln y$ |
|---:|---:|---:|---:|---:|
| 0 | 5.2 | 1.649 | 0 | 0 |
| 2 | 56.628 | 4.037 | 4 | 8.073 |
| 3 | 186.872 | 5.230 | 9 | 15.691 |
| 4 | 616.679 | 6.424 | 16 | 25.697 |
| 5 | 2035.04 | 7.618 | 25 | 38.091 |
| **14** | | **24.958** | **54** | **87.550** |

$$\begin{bmatrix} 5 & 14 \\ 14 & 54 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} 24.958 \\ 87.550 \end{bmatrix}$$

$$\Delta = 5 \cdot 54 - 14^2 = 74, \quad \Delta_A = 122.032, \quad \Delta_B = 88.338$$

$$A = 1.649, \qquad B = 1.1938$$

Geri dönüşüm: $a = e^{1.649} = 5.202$, $b = e^{1.1938} = 3.2995$. Fonksiyonda yerine yazılırsa:

$$y = 5.202 \cdot 3.2995^{\,x}$$

Hoca burada büyük $B$'nin değerini önce yanlışlıkla 3.29 okudu, hemen düzeltti: $e^{1.19}$ alınmış ve 3.29 bulunmuştur.

> **Ders sonrası not:** $\sum x\ln y$ değerini slayt 87.550 alıyor, satır toplamından yuvarlama farkı var. Python ile tam değerlerle hesaplandı: $A = 1.64866$, $B = 1.19392$, buradan $a = 5.2000$, $b = 3.3000$ çıkar. Yani veriler $y = 5.2 \cdot 3.3^x$'ten üretilmiştir; slayttaki 5.202 ve 3.2995 ara adımlardaki yuvarlamadan gelir.

### 7.4 Sınıf Alıştırması: $y = ax^b$

Hoca çözüme bakmadan beş dakikada kendimizin çözmesini istedi ki nerede takıldığımızı görelim. Veri: $x$: 1, 3, 5 ve $y$: 3, 15.588, 33.541. Doğru matrisi hatırlatıldı ve soru şuydu: Bu matriste neler değişecek?

Çözüm: $\ln y = \ln a + b\ln x$. $y$ gördüğümüz her yere $\ln y$, $x$ gördüğümüz her yere $\ln x$ yazılır. $\sum x^2$ yerine de $\sum(\ln x)^2$ gelir:

$$\begin{bmatrix} n & \sum \ln x \\ \sum \ln x & \sum (\ln x)^2 \end{bmatrix}\begin{bmatrix} A \\ B \end{bmatrix} = \begin{bmatrix} \sum \ln y \\ \sum \ln x\ln y \end{bmatrix}$$

| $x$ | $y$ | $\ln x$ | $(\ln x)^2$ | $\ln y$ | $\ln x\ln y$ |
|---:|---:|---:|---:|---:|---:|
| 1 | 3 | 0 | 0 | 1.099 | 0 |
| 3 | 15.588 | 1.099 | 1.207 | 2.747 | 3.017 |
| 5 | 33.541 | 1.609 | 2.590 | 3.513 | 5.654 |
| | | **2.708** | **3.797** | **7.359** | **8.671** |

$$\Delta = 3 \cdot 3.797 - 2.708^2 = 4.0577, \quad \Delta_A = 4.4611, \quad \Delta_B = 6.0848$$

$$A = 1.0994, \qquad B = 1.4996$$

Bize küçük $a$ ve küçük $b$ lazımdır. $\ln a = A$ olduğu için $a = e^A \approx 3$'tür. $b$'de hiçbir değişiklik yoktur, $b = B \approx 1.5$. Sonuç:

$$y = 3x^{1.5}$$

Kontrol: $x = 1$ için $3 \cdot 1 = 3$. $x = 3$ için $3 \cdot 3^{1.5}$ yaklaşık olarak tablodaki değere gelir; python ile hesaplandı, $15.588$'dir.

### 7.5 Örnek: $y = ae^{bx}$

Veri: $x$: 0, 1, 2 ve $y$: 1, 2, 6. $\ln y = \ln a + bx$ olduğundan $Y = \ln y$, $A = \ln a$; $b$ ve $x$ orijinal hâlindedir.

$$n = 3, \quad \sum x = 3, \quad \sum x^2 = 5, \quad \sum \ln y = 2.4849, \quad \sum x\ln y = 4.2767$$

$$\Delta = 3 \cdot 5 - 3^2 = 6, \quad \Delta_A = -0.4055, \quad \Delta_B = 5.3753$$

$$A = -0.06758, \qquad B = 0.89588$$

$a = e^A = 0.9347$ ve $b = B$ olur:

$$y = 0.9347e^{0.8959x}$$

$x = 0$ koyarsak $e^0 = 1$, $y = 0.93$ kalır. Gerçek değer 1 iken yaklaşık 0.93 bulunmuştur, yani sapma vardır. Diğer noktalarda da sapma vardır. Hoca bu sapmalar çok çok büyükse yanlış bir fonksiyon geçirilmeye çalışıldığını, farklı bir fonksiyon denemek gerektiğini söyledi.

> **Ders sonrası not:** Slaydın son satırında üs $0.5958797$ yazılıdır; python ile hesaplandı, doğrusu $b = 0.8958797$'dir. Tam değerlerle uydurulan fonksiyon $x = 1$ için $2.29$ (gerçek 2), $x = 2$ için $5.61$ (gerçek 6) verir.

## 8. Trigonometrik Fonksiyonlar

### 8.1 En Genel Hâl

Bazen geçirilecek fonksiyon trigonometriktir. En geniş hâliyle şöyle yazılır:

$$F(x) = a_0 + a_1\cos x + a_2\cos 2x + \cdots + a_n\cos nx + b_1\sin x + b_2\sin 2x + \cdots + b_n\sin nx$$

Sinüs tarafında $b_0$ katsayısı yoktur. Soruda bunun bir alt kümesi istenebilir: $y = a_0 + a_1\cos x$, ya da $y = b_1\sin x + b_2\sin 2x$, ya da $y = a_0 + a_1\cos x + b_3\sin 3x$ gibi. Hoca, fonksiyonun ne olduğunun önemli olmadığını söyledi. Gerçek $y_i$ ile fonksiyonun farkı alınır, karesi alınır, $n$ nokta üzerinden toplanır. Sonra kaç bilinmeyen varsa her birine göre türev alınır.

### 8.2 Türev Alırken Dikkat

$y = a_0 + a_1\cos x$ geçirilecekse iki bilinmeyen vardır, $a_0$ ve $a_1$. $a_0$'a göre türevde parantezin türevi $-1$, $a_1$'e göre türevde $-\cos x_i$ olur.

> **Ders sonrası not:** Hoca bu ilk anlatımda $a_1$'e göre türev için "cos x'in türevi eksi sin x, onu sin x ile çarpacağım" dedi; doğrusu $-\cos x_i$'dir. Türev $x$'e göre değil $a_1$'e göre alınır, $\cos x_i$ burada bilinen bir sayıdır. Hoca hemen sonraki slaytta doğrusunu yaptı: "$a_1$'e göre türev alırsan $\cos x_i$ yazacağız."

### 8.3 Üç Terimli Durum

Genel fonksiyonun bir alt kümesi olan $F(x) = a_0 + a_1\cos x + b_1\sin x$ için: Fonksiyondan $y_i$ ya da $y_i$'den fonksiyon çıkarılabilir, hiç fark etmez. Üst düşer, parantezin kendisi yazılır ve sırayla 1, $\cos x_i$ ve $\sin x_i$ ile çarpılır. $y$'ler bir tarafa, diğerleri öbür tarafa alınınca matris çıkar:

$$\begin{bmatrix} n & \sum\cos x_i & \sum\sin x_i \\ \sum\cos x_i & \sum\cos^2 x_i & \sum\sin x_i\cos x_i \\ \sum\sin x_i & \sum\sin x_i\cos x_i & \sum\sin^2 x_i \end{bmatrix}\begin{bmatrix} a_0 \\ a_1 \\ b_1 \end{bmatrix} = \begin{bmatrix} \sum y_i \\ \sum y_i\cos x_i \\ \sum y_i\sin x_i \end{bmatrix}$$

Matrisin köşegene göre simetrik olduğuna dikkat edin. Fonksiyonda bir de $b_2\sin 2x$ olsaydı yalnız $b_2$'ye göre bir türev daha alınırdı; dört bilinmeyen, dört denklem olurdu.

Sinüs ve kosinüsleri hesaplarken açının birimine dikkat etmek gerekir. Açılar derece verilmişse derece, radyan verilmişse radyan olarak hesaplanır.

### 8.4 Çok Terimlide Kısaltma

Slaytta $F(x) = a_0 + a_1\cos x + a_2\cos 2x + b_1\sin x + b_2\sin 2x$ eğrisi için işi kolaylaştıran bir yazım vardır. Sinüs ve kosinüslerle uğraşmamak için $\cos x = c_1$, $\cos 2x = c_2$, $\sin x = s_1$, $\sin 2x = s_2$ denir. Formül basitleşir, $a_0$, $a_1$, $a_2$, $b_1$, $b_2$'ye göre türev alınıp sıfıra eşitlenir. Sonra $c_1$ olan yere $\cos x$, $c_2$ olan yere $\cos 2x$ konarak çözülür. Hoca bu kadarının sorulmadığını, ama mantığın aynı olduğunu söyledi.

### 8.5 Örnek: $y = a_0 + a_1\sin x$

Açılar derece verilmiştir, derece olarak hesaplanır. $S = \sum(y_i - a_0 - a_1\sin x_i)^2$ yazılıp $a_0$'a ve $a_1$'e göre türev alınınca:

$$na_0 + a_1\sum\sin x = \sum y, \qquad a_0\sum\sin x + a_1\sum\sin^2 x = \sum y\sin x$$

Burada $x$'lerin kendi toplamına hiç ihtiyaç yoktur. Hoca bu noktayı özellikle söyledi. Gerekenler $\sin x$, $\sin^2 x$, $y\sin x$ ve $y$ toplamlarıdır.

| $x$ | $y$ | $\sin x$ | $\sin^2 x$ | $y\sin x$ |
|---:|---:|---:|---:|---:|
| 0° | 2.5 | 0 | 0 | 0 |
| 20° | 3.526 | 0.342 | 0.117 | 1.206 |
| 40° | 4.428 | 0.643 | 0.413 | 2.846 |
| 60° | 5.098 | 0.866 | 0.750 | 4.415 |
| 80° | 5.454 | 0.985 | 0.970 | 5.371 |
| **Toplam** | **21.006** | **2.836** | **2.25** | **13.838** |

Tablodaki son sütun python ile hesaplandı; slayttaki değerlerden farkı aşağıdaki notta açıklanıyor. Sistem:

$$5a_0 + 2.836a_1 = 21.006, \qquad 2.836a_0 + 2.25a_1 = 13.838$$

$$a_0 = 2.5, \qquad a_1 = 3.0, \qquad y = 2.5 + 3\sin x$$

Kontrol: $x = 20^\circ$ için $2.5 + 3 \cdot 0.342 = 3.526$, tablodaki değerin aynısıdır.

> **Ders sonrası not:** Slaytta sonuç $y = 2.571 + 2.874\sin x$ yazılıdır; doğrusu $y = 2.5 + 3\sin x$'tir. Hatanın kaynağı $x = 80^\circ$ satırıdır: $y\sin x$ orada 5.290 yazılmış, doğrusu $5.454 \cdot \sin 80^\circ = 5.371$'dir. Bu yüzden toplam 13.838 yerine 13.758 olmuştur. Python ile hesaplandı: 2.571 ve 2.874, doğru sol taraf ile bu yanlış 13.758'in çözümüdür. Ayrıca slaytta sistemin ilk satırında $a_1$'in katsayısı 2.25 yazılı, doğrusu 2.836'dır; yazıldığı gibi çözülse $a_0 = 3.349$, $a_1 = 1.893$ çıkardı. Hoca sözlü anlatımda sağ taraf için "$y$ çarpı $\sin y$" dedi; doğrusu $y\sin x$'tir.

### 8.6 Kosinüslü Örnek

<!-- BELİRSİZ: Bu derste kare yok. Tablolar repodaki 1-2/Sayısal Analiz/slaytlar_notlar/2026/bolum_8_regresyon.pdf dosyasından alındı; PDF 2022-04-26 tarihli, bu dönemin slaydı olduğu kanıtlı değil. Anlatımla ve kısa nottaki sayılarla uyuşuyor. -->

Hoca, slaytta kosinüslü bir örnek de bulunduğunu, aynı şeylerin yapıldığını söyleyip çözmeden geçti. Slayttaki $y = a_0 + a_1\cos x$ örneği:

| $x$ | $y$ | $\cos x$ | $\cos^2 x$ | $y\cos x$ |
|---:|---:|---:|---:|---:|
| 0° | −0.400 | 1 | 1 | −0.400 |
| 15° | −0.332 | 0.966 | 0.933 | −0.321 |
| 30° | −0.132 | 0.866 | 0.750 | −0.114 |
| 45° | 0.186 | 0.707 | 0.500 | 0.132 |
| 60° | 0.600 | 0.500 | 0.250 | 0.300 |
| 75° | 1.082 | 0.259 | 0.067 | 0.280 |
| **Toplam** | **1.004** | **4.298** | **3.5** | **−0.123** |

$$6a_0 + 4.298a_1 = 1.004, \qquad 4.298a_0 + 3.5a_1 = -0.123$$

$$a_0 = 1.6, \qquad a_1 = -2, \qquad y = 1.6 - 2\cos x$$

Python ile hesaplandı, sonuç doğrudur: $x = 0^\circ$ için $1.6 - 2 = -0.4$.

> **Hocanın vurgusu:** "Defalarca söylüyorum, hata görmek istemiyorum." Yapılacak tek şey vardır: $y$'den geçirilmesi istenen fonksiyon çıkarılır, işaretten kurtulmak için kareleri alınır, her bilinmeyene göre ayrı ayrı türev alınıp sıfıra eşitlenir, matrise yerleştirilir, çözülür ve fonksiyonda yerine konur. Doğrusal değilse önce her iki tarafın logaritması alınır. "Bu işin başka bir yolu yok."

## 9. Çoklu Regresyon

### 9.1 Girdi Sayısı Birden Fazla

Son konu çoklu regresyondur. Hoca hiç zor olmadığını, öncekilere benzediğini söyledi. Tek farkı değişken sayısının birden fazla olmasıdır. Şimdiye kadar bir $x$ girdisi ve ona karşılık $y$ çıktısı vardı. Şimdi birden fazla girdi var.

Örnek: Kanal içindeki akışa ilişkin bir düzenekte borudaki akışkanın miktarı, borunun çapı ve eğimi verilmiştir. Girdiler çap $D$ ve eğim $S$, çıktı ise akış miktarı $Q$'dur (m³/s). İstenen fonksiyon:

$$Q = a_0 D^{a_1} S^{a_2}$$

$a_0$, $a_1$, $a_2$ katsayıları bulunacaktır. İlk bakışta farklı görünür, ama başa dönelim. Bu fonksiyon doğrusal değildir, her iki tarafın logaritması alınır:

$$\log Q = \log a_0 + a_1\log D + a_2\log S$$

İşlem kolaylığı için $y = \log Q$, $a_0' = \log a_0$, $x_1 = \log D$, $x_2 = \log S$ denir. Hocanın dediği gibi bunlara başka isimler de verilebilirdi:

$$y = a_0' + a_1x_1 + a_2x_2$$

### 9.2 Matris

Yöntem aynıdır. Gerçek $y$'den fonksiyon çıkarılır, kareleri toplanır ve üç bilinmeyene göre türev alınır:

$$S_{\text{hata}} = \sum_{i=1}^{n}\left(y_i - a_0' - a_1x_{1i} - a_2x_{2i}\right)^2$$

$$\frac{\partial S_{\text{hata}}}{\partial a_0'} = 0, \quad \frac{\partial S_{\text{hata}}}{\partial a_1} = 0, \quad \frac{\partial S_{\text{hata}}}{\partial a_2} = 0$$

Hoca hata toplamına da $S$ dedi; burada eğim $S$ ile karışmasın diye $S_{\text{hata}}$ yazıldı. Parantezin türevi sırayla $-1$, $-x_{1i}$, $-x_{2i}$ olur. Düzenleyince:

$$\begin{bmatrix} n & \sum x_1 & \sum x_2 \\ \sum x_1 & \sum x_1^2 & \sum x_1x_2 \\ \sum x_2 & \sum x_1x_2 & \sum x_2^2 \end{bmatrix}\begin{bmatrix} a_0' \\ a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} \sum y \\ \sum x_1y \\ \sum x_2y \end{bmatrix}$$

$x_1$ demek $\log D$ demek olduğundan verilen $D$'lerin logaritmaları alınıp toplanır ve $\sum x_1$ yerine yazılır. Diğerleri de aynıdır.

### 9.3 Sayısal Çözüm

Slayttaki deney tablosu ve logaritmaları (10 tabanında):

| Deney | $D$ (m) | $S$ | $Q$ (m³/s) | $y = \log Q$ | $x_1 = \log D$ | $x_2 = \log S$ |
|---:|---:|---:|---:|---:|---:|---:|
| 1 | 1 | 0.001 | 1.4 | 0.146 | 0 | −3 |
| 2 | 2 | 0.001 | 8.3 | 0.919 | 0.301 | −3 |
| 3 | 3 | 0.001 | 24.2 | 1.384 | 0.477 | −3 |
| 4 | 1 | 0.01 | 4.7 | 0.672 | 0 | −2 |
| 5 | 2 | 0.01 | 28.9 | 1.461 | 0.301 | −2 |
| 6 | 3 | 0.01 | 84.0 | 1.924 | 0.477 | −2 |
| 7 | 1 | 0.05 | 11.1 | 1.045 | 0 | −1.301 |
| 8 | 2 | 0.05 | 69.0 | 1.839 | 0.301 | −1.301 |
| 9 | 3 | 0.05 | 200 | 2.301 | 0.477 | −1.301 |
| **Toplam** | | | | **11.691** | **2.334** | **−18.903** |

Çarpımlar ve kareler (python ile hesaplandı):

| Deney | $x_1^2$ | $x_1y$ | $x_1x_2$ | $x_2^2$ | $x_2y$ |
|---:|---:|---:|---:|---:|---:|
| 1 | 0 | 0 | 0 | 9 | −0.438 |
| 2 | 0.091 | 0.277 | −0.903 | 9 | −2.757 |
| 3 | 0.228 | 0.660 | −1.431 | 9 | −4.151 |
| 4 | 0 | 0 | 0 | 4 | −1.344 |
| 5 | 0.091 | 0.440 | −0.602 | 4 | −2.922 |
| 6 | 0.228 | 0.918 | −0.954 | 4 | −3.849 |
| 7 | 0 | 0 | 0 | 1.693 | −1.360 |
| 8 | 0.091 | 0.554 | −0.392 | 1.693 | −2.392 |
| 9 | 0.228 | 1.098 | −0.621 | 1.693 | −2.994 |
| **Toplam** | **0.955** | **3.946** | **−4.903** | **44.078** | **−22.208** |

Slayttaki matris:

$$\begin{bmatrix} 9 & 2.334 & -18.903 \\ 2.334 & 0.954 & -4.903 \\ -18.903 & -4.903 & 44.075 \end{bmatrix}\begin{bmatrix} a_0' \\ a_1 \\ a_2 \end{bmatrix} = \begin{bmatrix} 11.691 \\ 3.945 \\ -22.207 \end{bmatrix}$$

Çözüm slayta göre $a_0' = 1.7475$, $a_1 = 2.62$, $a_2 = 0.54$'tür. Doğrusal hâldeki denklem:

$$\log Q = 1.7475 + 2.62\log D + 0.54\log S$$

Geri dönüş için ters işlem yapılır. Logaritmada üs öne düşüyordu: $0.54\log S$, $S^{0.54}$'ün logaritmasıdır; $2.62\log D$ de $D^{2.62}$'nin. $a_0$ için de $\log a_0 = 1.7475$'ten $a_0 = 55.9$ bulunur. Sonuç:

$$Q = 55.9\,D^{2.62}S^{0.54}$$

> **Ders sonrası not:** Hoca sözlü olarak "$a_0 = e^{1.74}$" ve "$D = e^{x_1}$" dedi; doğrusu 10 tabanıdır, çünkü tablodaki değerler 10 tabanlı logaritmadır ($\log 2 = 0.301$). Python ile hesaplandı: $10^{1.7475} = 55.9$, oysa $e^{1.7475} = 5.74$ olur. Logaritma hangi tabanda alındıysa geri dönüş de o tabanla yapılır. Ayrıca $D$ ve $S$ soruda verilmiştir, geri dönüşle bulunacak olan yalnız $a_0$'dır. Hoca $S$ için bir yerde "derinlik" dedi; $S$ eğimdir.

> **Ders sonrası not:** Slaydın iki yerinde sayı hatası vardır. Matrisin $\sum x_1^2$ hücresinde 0.924 yazılıdır, tabloda 0.954'tür ve python ile hesaplanan tam değer 0.955'tir; yukarıdaki matriste 0.954 kullanıldı. 0.924 ile çözülürse $a_0' = 1.685$, $a_1 = 2.87$ çıkardı, yani slayttaki sonuç 0.924'le üretilmiş olamaz. İlk tabloda 9. deneyin $Q$ değeri 2000 yazılıdır, ikinci tablodaki 200 ve $\log Q = 2.301$ doğrudur. Tam değerlerle çözüm: $a_0' = 1.7480$, $a_1 = 2.616$, $a_2 = 0.537$, $a_0 = 55.97$. Kontrol olarak $D = 2$, $S = 0.001$ için $55.9 \cdot 2^{2.62} \cdot 0.001^{0.54} = 8.24$ çıkar, ölçülen değer 8.3'tür.

Hoca konuyu şöyle bağladı: Girdi bir değil birden fazlaysa adı çoklu regresyon olur. Hesaplanacak toplamlar biraz artar, başka da bir şey değişmez.

## 10. Soru: Gauss-Seidel'de Köşegeni En Büyük Yapmak

Ders bittikten sonra bir öğrenci daha önceki bir konudan soru sordu.

**Soru:** Gauss-Seidel yöntemini kodlarken köşegenin çarpımı en büyük olacak şekilde denklemleri dizmek gerekiyor. Bunun için bir sürü `for` gerekiyor gibi düşündüm. Daha kısa bir yöntem var mı?

**Cevap:** Matris kaç boyutluysa o kadar fazla kontrol gerekir, ama en kolay yol şudur:

1. Birinci sütundaki en büyük katsayıyı bul, o denklemi ilk sıraya taşı.
2. İkinci sütunda, yeri değiştirilmemiş denklemler arasından en büyüğü bul, o denklemi ikinci sıraya taşı.
3. Üçüncü sütunda aynı şekilde devam et. Yeri değiştirilen bir denklem bir daha değiştirilmez.

Hoca bunu tahtada bir örnekle gösterdi. Denklemlerin sol tarafları şunlar olsun:

$$x_1 + x_2 + 3x_3, \qquad 5x_1 + 3x_2 + 2x_3, \qquad x_1 + 6x_2 + x_3$$

Birinci sütunda en büyük katsayı 5'tir, ikinci denklem ilk sıraya gelir. İkinci sütunda kalanlar arasında en büyük 6'dır, üçüncü denklem ikinci sıraya gelir. Üçüncü sıraya geriye kalan denklem gelir (ara adım eklendi):

$$\begin{bmatrix} 5 & 3 & 2 \\ 1 & 6 & 1 \\ 1 & 1 & 3 \end{bmatrix}$$

Python ile hesaplandı: Üç denklemin $3! = 6$ dizilimi içinde köşegen çarpımı en büyük olan budur, $5 \cdot 6 \cdot 3 = 90$.

**Soru:** Ben de öyle hatırlıyorum, ama bu yöntem bazen doğru sonucu vermiyor. **Cevap:** Evet, bazen çıkmayabilir. Hoca, bir denklemi taşıdıktan sonra sıradaki sütunda yine aynı denklemin büyük çıkıp yer değiştirmesi durumunda köşegene en büyük değil en küçük değerin gelebileceğini anlattı. Böyle durumlarda kuralın uygulanmadığı bir koşul olduğunu, ama o an hatırlayamadığını söyledi. Kendi örneklerinde birkaç deneme yapılırsa bunun görüleceğini, "maksimum diyagonal" diye aratılmasını ve hazır kod bulunursa analiz edilip nasıl çalıştığının anlaşılmasını önerdi. Bir başka seçenek de kullanıcıdan denklemleri köşegeni büyük olacak biçimde girmesini istemektir.

<!-- BELİRSİZ: Hocanın kuralın işlemediği durum için verdiği açıklama altyazıda yarım kalıyor ("bilmem nereye gelen katsayının başı bilmem ne oluyorsa"); koşulun kendisi derste söylenmedi. -->

> **Ek bilgi (derste anlatılmadı):** Hocanın hatırlayamadığı konu büyük olasılıkla köşegen baskınlığıyla ilgilidir. Her satırda köşegen elemanının mutlak değeri, o satırdaki diğer elemanların mutlak değerleri toplamından büyükse Gauss-Seidel büyük olasılıkla yakınsar. Sütun sütun en büyüğü seçmek bu koşulu garanti etmez. Yukarıdaki örnekte ilk satırda $5 = 3 + 2$ olduğu için eşitlik vardır.

Öğrencinin ilk aklına gelen yol, bütün dizilimleri tek tek denemektir. Hoca bunun $n!$ durum demek olduğunu söyledi. Üçe üçlük matriste bu yapılabilir, ama elli katsayılı bir matriste bütün durumlara bakılamaz. Bunu optimize eden yöntemler var, ama o kadar derine girmek gerekmez. Bilgisayarda $100 \times 100$ bir matrisle işlem yaptırmak da çok uzun sürer. Kodu sınamak için makul sınır 10-20 boyuttur. Bir uyarı daha ekledi: Tanımlanan değişken tipi (`byte`, `integer`) yetmeyebilir, bunu baştan bilmek zor olabilir.

## Dersin Toparlaması

Bu derste regresyonun tek bir fikre dayandığı görüldü: Gerçek $y$ ile uydurulan fonksiyonun farkı alınır, artı ve eksiler birbirini götürmesin diye kareleri toplanır, bu toplamın her bilinmeyene göre türevi sıfıra eşitlenir ve çıkan denklem takımı matris biçiminde çözülür. Doğru, $y = ax$, parabol, trigonometrik fonksiyon ve çoklu regresyon hep bu kalıbın uygulamalarıdır; değişen yalnız hesaplanan toplamlardır. Doğrusal olmayan $ae^{bx}$, $ax^b$, $ab^x$ ve $a_0D^{a_1}S^{a_2}$ gibi fonksiyonlar logaritmayla önce doğrusal hâle getirilir, matriste neyin yerine ne konduğu takip edilir ve sonunda geri dönüşüm yapılır.

Hoca regresyonla konuların bittiğini söyledi. Fonksiyon seçimi için fark tablosu, simetri ve periyodiklik ipuçlarını verdi, seçilen fonksiyonun sapması büyükse başka bir fonksiyon denenmesini istedi. Ana mesajı "ezberleme yok" oldu: Matris akılda kalmasa da $S = \sum(y_i - F(x_i))^2$ yazılınca her şey yeniden çıkarılabilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
