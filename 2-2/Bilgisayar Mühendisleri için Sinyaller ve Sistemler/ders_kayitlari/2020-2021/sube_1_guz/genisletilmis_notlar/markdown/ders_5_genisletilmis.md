# Ders 5 Genişletilmiş Notu: Sistem Özellikleri ve Önceki Konulara Ait Örnek Sorular

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sistem Kavramı ve Gösterimi
- 2. Temel Sistem Örnekleri
- 3. Sistemlerin Birbirine Bağlanması
- 4. Doğrusallık
- 5. Hafıza
- 6. Zamanla Değişmezlik
- 7. Kararlılık ve Hız Sabitleyici Örneği
- 8. Terslenebilirlik
- 9. Doğrusal Sabit Katsayılı Diferansiyel ve Fark Denklemleri
- 10. Önceki Konuların Tekrarı: Örnek Soruların Çözümü
- Örnek Sorular
- Dersin Toparlaması

## 1. Sistem Kavramı ve Gösterimi

Önceki derslerde işaretlerin özellikleri hem sürekli zamanda (continuous time) hem ayrık zamanda (discrete time) incelenmişti. Bu derste sistemlerin özelliklerine geçildi ve dersin ikinci yarısında önceki konulara ait örnek sorular çözüldü. Dersin slaytları "Systems Properties" başlığını taşır (ekrandan, 00:15:00).

Sistem bir kara kutu gibi düşünülür: sürekli zamanda $x(t)$ girişi için $y(t)$ çıkışını, ayrık zamanda $x[n]$ girişi için $y[n]$ çıkışını üretir. Arada bir dönüşüm (transform) gerçekleşir. Slayttaki tanıma göre sistem giriş işaretlerini çıkış işaretlerine dönüştüren bir yapıdır. Başka bir tanımla, giriş işaretini çıkış işaretine eşleyen bir haritalama fonksiyonudur (function mapping). Bu derste yalnız tek girişli, tek çıkışlı (Single Input Single Output, SISO) sistemler ele alınır.

### 1.1 Gösterim: $y = S(x)$ ve $y = Sx$

Slaytta sistem $T$ (transform) yerine $S$ (system) harfiyle gösterilmiştir. İki gösterim kullanılır (ekrandan, 00:20:00):

- $y = S(x)$: $x$, sisteme verilen bir parametre gibidir; sistem bunu işleyip çıkışı oluşturur.
- $y = Sx$: Bu gösterim genel olarak çarpma anlamına gelmez ("does not (in general) mean multiplication"). $S$, $x$'i girdi olarak alan bir eşleme fonksiyonudur.

Hoca burada işaretin bilgisayarda nasıl saklandığını da hatırlattı. Ayrık bir işaret $x[n]$, her örneğin genlik değeri bir dizinin (array) bir elemanına yazılarak saklanabilir. Matematiksel gösterimde bu tür diziler küçük (kalın) harflerle gösterilir ve $1\times N$ ya da $N\times 1$ boyutlu bir vektör olarak kaydedilebilir. Görüntü gibi iki boyutlu işaretler ise büyük harfle gösterilir. Sistem de büyük harfle yazıldığı için $Sx$ gösteriminde $S$ büyük, yanındaki $x$ küçüktür; $x$ bir boyutlu bir işaret vektörüdür.

Dönüşüm bir matrisle ifade edilebiliyorsa $Sx$ gerçekten bir matris-vektör çarpımı olur. Örneğin $S$ matrisi $M\times N$, işaret $N\times 1$ boyutundaysa çıkış $M\times 1$ boyutunda olur. Bazen ise dönüşüm matris olmayan başka fonksiyonlarla tanımlanır; bu yüzden gösterim "genel olarak" çarpma değildir.

Sinyaller ve sistemler dersinde hem sürekli hem ayrık domende çalışıldığı için genel anlatımda yalnız $x$ ve $y$ yazılır. Sürekli fonksiyon normal parantezle ($x(t)$), ayrık fonksiyon köşeli parantezle ($x[n]$) gösterilir.

### 1.2 Blok diyagram

Sistemler çoğunlukla blok diyagramla gösterilir: $x$ okla $S$ kutusuna girer, $y$ okla çıkar (ekrandan, 00:20:00). Oklu çizgiler kablo değil, işaretlerdir; işaretin iletim yönünü gösterirler. Genel gösterimde kutular sistemleri, oklar giriş ve çıkışları gösterir. Bazı özel sistemler için özel semboller de kullanılabilir.

## 2. Temel Sistem Örnekleri

Slayttaki örneklerde giriş işareti $x$, çıkış işareti $y$ ile gösterilir (ekrandan, 00:25:00).

### 2.1 Ölçekleyen sistem (scaling system)

$$y(t) = a\,x(t)$$

Ölçekleyen sistem işareti bir sabitle çarpar: 2 ile çarpınca işaret iki katına çıkar, $1/2$ ile çarpınca yarıya iner. Sistem daha çok genlik üzerinde, yani işaretin dikey eksendeki değeri üzerinde çalışır (ekrandan, 00:25:00):

- $|a| > 1$ ise yükselteç (amplifier) denir; işaretin genliğini artırır.
- $|a| < 1$ ise zayıflatıcı (attenuator) denir; genliği azaltır.
- $a < 0$ ise tersleyen (inverting) sistem denir.
- $a$ kazanç (gain) ya da ölçekleme faktörü (scale factor) olarak adlandırılır.
- Blok diyagramda bazen kutu yerine üçgen ya da daireyle gösterilir; bunda kesin bir standart yoktur.

Hoca yükselteci müzik sistemleriyle açıkladı: elektro gitardan gelen ses işareti, örneğin $a = 2$ kazançlı bir yükselteçte güçlendirilir, sonra bir synthesizer gibi başka bir sisteme gönderilebilir.

Tanımda neden mutlak değer kullanıldığı da soruldu. İşareti $-2$ ile çarparsak işaret tam ters döner ama genliği yine iki katına çıkar; 1 değerini alan bir nokta $-2$ değerini alır. Yani eksi işaret işaretin ters yöne döndüğünü, 2 ise kaç kat güçlendiğini gösterir. $-1/2$ ya da $1/2$ için de aynısı geçerlidir: baştaki eksi tersleme (inverting) demektir.

### 2.2 Türev alıcı (differentiator)

$$y(t) = \frac{d\,x(t)}{dt}$$

Hoca örnek olarak bir noktaya kadar sıfır olan, sonra sabit eğimle artan bir işaret çizdi. Bu işaretin türevi, sıfır olan bölgede sıfır, artan bölgede ise sabittir. Eğim, dikey artışın yatay artışa oranıdır (çizimde $B/A$).

### 2.3 İntegral alıcı (integrator)

$$y(t) = \int_{a}^{t} x(\tau)\,d\tau$$

İntegral alıcı, belli bir $a$ anından bulunulan $t$ anına kadar işaretin integralini, yani eğrinin altında kalan alanı hesaplar. Hoca, $A$ ile $B$ arasında sabit değer alan bir işaret üzerinde $t$ anını soldan sağa ilerleterek anlattı. $t < A$ iken alan sıfırdır. $A$'dan itibaren altta kalan alan giderek artar. $B$'den sonra işaret sıfır olduğu için alan artık artmaz ve integral sabit kalır. Slayttaki $a$ genelde $0$ ya da $-\infty$ alınır; örnekte $-\infty$'dan gelinmiş, katkı ancak işaretin ilk değer aldığı $A$ noktasından başlamıştır.

### 2.4 Zamanda öteleme sistemi (time shift system)

$$y(t) = x(t - T)$$

Bu sistem giriş işaretini belli bir miktar sağa ya da sola kaydırır (ekrandan, 00:30:00):

- $T > 0$ ise gecikme sistemi (delay system) denir; işaret gecikir, sağa kayar.
- $T < 0$ ise öngörücü sistem (predictor system) denir; sanki gelecekteki işareti tahmin ediyormuş gibi işaret sola kayar.

### 2.5 Konvolüsyon sistemi

İki işaret düşünülür: biri sistemi tanımlayan $h(t)$, diğeri giriş $x(t)$. Çıkış, bu iki işaretin birbiri üzerinden alınan integraliyle üretilir; buna konvolüsyon sistemi denir. Aslında sistemin cevabı $h$ ile tanımlanır ve kutunun algoritmik ve süzgeç (filtre) özelliklerini $h$ belirler. Hoca konunun ileride ayrıntılı işleneceğini söyleyerek geçti.

> **Ek bilgi (derste anlatılmadı):** Sürekli zamanda konvolüsyon büyük olasılıkla slayttaki biçimiyle $y(t) = \int_{-\infty}^{\infty} h(\tau)\,x(t-\tau)\,d\tau$ olarak yazılır. Burada $h(t)$, sistemin birim dürtü cevabıdır. Doğrusal ve zamanla değişmez sistemlerin çıkışı her zaman bu integralle hesaplanabilir.

### 2.6 Çok girişli sistemler

Bazen çıkışı üretmek için birden fazla giriş gerekir:

- Toplayıcı (summing system): $y = x_1 + x_2$.
- Fark alıcı (difference system): $y = x_1 - x_2$.
- Çarpıcı (multiplier): $y = x_1 x_2$.

## 3. Sistemlerin Birbirine Bağlanması

Bir sistemin arkasından başka bir sistem gelebilir ya da işaret ikiye ayrılıp ayrı ayrı işlenebilir ve sonra toplanabilir. Hoca $F$ ve $G$ adlı iki sistem üzerinden üç bağlantı türünü anlattı.

### 3.1 Seri (kaskat) bağlama

Önce $x$ girişi $F$'de işlenir, ara sonuç $\tilde y = F(x)$ olur. Bu ara işaret $G$'ye girer ve asıl çıkış oluşur:

$$y = G(F(x))$$

Hoca, ara değer için kullanılan $\tilde y$ işaretindeki üst işaretin türev anlamına gelmediğini belirtti.

### 3.2 Paralel bağlama

$x$ işareti aynı anda $F$ ve $G$ sistemlerine girer; sonuçlar ayrı ayrı elde edilip toplanır:

$$y = F(x) + G(x)$$

Toplama yerine bazen çıkarma da yapılabilir; slayttaki "sum" genel anlamda kullanılmıştır.

### 3.3 Geri besleme (feedback)

Geri beslemeli sistemde $x$ girişi, $G$ sisteminin çıktısıyla birleştirilerek $F$'ye verilir; $G$'ye giren işaret ise $F$'nin çıkışıdır (ekrandan, 00:35:00). Sistem, istenen çıkışa ulaşabilmek için çıkıştan bilgi çeker. Toplama noktasından sonraki işaret $x - G(y)$ olduğundan:

$$y = F(x - G(y))$$

Slayttaki genel yoruma göre blok diyagramlar sistemlerin bağlanışını sembolik olarak açıklar; aynı bilgiyi işaretler arasındaki denklemlerle de yazabiliriz ve blok diyagram ile sistem denklemleri arasında gidip gelebiliriz (ekrandan, 00:35:00).

### 3.4 Örnek: geri beslemeli integral alıcı

Slayttaki örnekte geri besleme kolunda $a$ kazancı, ileri kolda integral alıcı vardır. Geri besleme kolunun çıkışı $a\,y$ olur. Toplama noktasında oluşan işaret $x - a\,y$'dir. Bu işaret integral alıcıya girdiği için:

$$y(t) = \int_{-\infty}^{t} \big(x(\tau) - a\,y(\tau)\big)\,d\tau$$

Slayttaki "yararlı bir yöntem" şudur: integral alıcının girişi, çıkışının türevidir ("the input to an integrator is the derivative of its output"). Buna göre:

$$x - a\,y = \dot y$$

İntegrali türevle kaldırınca girişten çıkışın (ölçeklenmiş halinin) çıkarılmasıyla oluşan işaretin, $y$'nin türevine eşit olduğu görülür.

## 4. Doğrusallık

Bir $F$ sistemi şu iki özelliği sağlıyorsa doğrusaldır (linear) (ekrandan, 00:40:00):

1. **Homojenlik (homogeneity), Türkçede ölçeklenebilirlik:** $x$ herhangi bir işaret, $a$ herhangi bir skaler olmak üzere
   $$F(ax) = a\,F(x)$$
2. **Süperpozisyon (superposition), Türkçede toplamsallık:** $x$ ve $\tilde x$ herhangi iki işaret olmak üzere
   $$F(x + \tilde x) = F(x) + F(\tilde x)$$

Sözle ifade edersek: sisteme işareti önce bir genlikle çarpıp vermek ile işareti verip çıkışı sonra çarpmak aynı sonucu veriyorsa sistem homojendir. İki işareti önce toplayıp sisteme vermek ile ayrı ayrı verip çıkışları toplamak aynı sonucu veriyorsa sistem toplamsaldır. Slayttaki ifadeyle, ölçeklemeyi ya da toplamayı sistemden önce ya da sonra yapmak aynıdır.

Hoca bunun blok diyagram karşılığını da gösterdi. Homojenlikte bir yolda işaret önce $a$ ile çarpılıp $F$'ye verilir ve $F(ax)$ oluşur; diğer yolda önce $F(x)$ oluşur, sonra $a$ ile çarpılarak $aF(x)$ elde edilir. İki çıkış eşitse homojenlik sağlanır. Toplamsallıkta bir yolda işaretler önce toplanır ve $F(x_1 + x_2)$ oluşur; diğer yolda $F(x_1)$ ve $F(x_2)$ ayrı ayrı oluşup toplanır. İkisi eşitse sistem toplamsaldır.

### 4.1 Doğrusal ve doğrusal olmayan sistem örnekleri

Hocanın slayttan okuduğu listeye göre ölçekleyen sistemler, zamanda ölçekleme, konvolüsyon, modülasyon yapan sistemler ve örnekleyiciler (sampler) doğrusaldır. İşaret detektörleri, çarpıcılar, nicemleyiciler (quantizer), uyarlamalı (adaptif) süzgeçler ve karşılaştırıcılar ise doğrusal olmayan sistemlerdir. Hoca bu terimlerin bazılarının şimdilik yabancı gelebileceğini, ilerleyen derslerde karşılaşıldıkça anlaşılacağını söyledi. <!-- BELİRSİZ: liste slayttan okunuyordu ama bu anın karesi yok; "işaret detektörü" büyük olasılıkla "sign detector" çevirisidir. -->

### 4.2 Modülatör doğrusaldır

Slayttaki ilk örnek, çarpıcının modülatör olarak kullanılmasıdır (ekrandan, 00:45:00):

$$y(t) = x(t)\cos(2\pi f t) \quad \text{doğrusaldır.}$$

Modülasyon, $x(t)$ işaretini $f$ frekansının çevresine taşır. Hoca bunu radyolarla açıkladı: farklı istasyonların hepsi havadan aynı ortamla gelir, ama her biri farklı bir frekansın çevresinde yayın yaptığı için ayrıştırılabilir. $\cos(2\pi f t)$ belli bir frekansta salınan bir işarettir; $x(t)$ ile çarpılınca $x(t)$'nin zarfını izleyen bir salınım ortaya çıkar. Sisteme verilen giriş bir katsayıyla çarpılırsa çıkış da aynı katsayıyla çarpılır; toplam girişin çıkışı da çıkışların toplamıdır. Bu yüzden sistem doğrusaldır.

### 4.3 Kare alıcı doğrusal değildir

İkinci örnek, çarpıcının kare alıcı olarak kullanılmasıdır:

$$y(t) = x^2(t) \quad \text{doğrusal değildir.}$$

Sisteme $x$ yerine $ax$ verilirse çıkış $a^2x^2(t)$ olur. Bu, $a\,y(t) = a\,x^2(t)$'ye eşit değildir. Homojenlik sağlanmadığı için sistem doğrusal değildir (ekrandan, 00:45:00).

## 5. Hafıza

Hafıza (system memory) özelliği şunu sorar: sistemin bir andaki çıkışı üretebilmesi için girişin geçmiş ya da gelecek değerlerine ihtiyacı var mı?

- **Hafızasız sistem (memoryless):** Çıkış yalnız o anki girişe bağlıdır. Örnek: yükselteç $y = a\,x$. Burada saklanması gereken bir değer yoktur.
- **Hafızalı sistem (system with memory):** Çıkış, girişin geçmiş ya da gelecek örneklerine ihtiyaç duyar. Örneğin $y[n] = x[n] + x[n-1]$ sisteminde girişin bir önceki örneğine ihtiyaç vardır; bu değerin bir yerde, yani hafızada saklanması gerekir.

Hafızalı sistemlere slayttaki örnekler: enerji depolayan devre elemanları (kondansatör ve bobin), yaylar ve hareketli kütleler. Mekanik bir sistemde, şu anki durumu hesaplayabilmek için yayın geçmişte ne kadar sıkıştığını bilmek gerekir. Hoca bu dersin yalnız elektriksel sistemlerle sınırlı olmadığını, mekanik ve mekatronik sistemlerde de aynı araçların kullanıldığını vurguladı: bir girişi çıkışa dönüştüren her yapı matematiksel olarak işaret ve sistem cinsinden ifade edilebilir.

## 6. Zamanla Değişmezlik

Zamanla değişmez (time invariant) bir sistemde girişteki bir öteleme çıkışı da aynı miktarda öteler. $x(t)$ girişi $y(t)$ çıkışını veriyorsa, $x(t - \tau)$ girişi $y(t - \tau)$ çıkışını verir:

$$F\big(x(t-\tau)\big) = y(t-\tau)$$

Hoca bunu iki yolla anlattı. Birinci yolda işaret önce $\tau$ kadar geciktirilir ve sonra sisteme verilir; çıkış $F(x - \tau)$ olur. İkinci yolda işaret önce sisteme verilir, $y$ elde edilir ve sonra $y$ geciktirilir. İki yol aynı sonucu veriyorsa sistem ötelemeyle değişmezdir.

Slayttaki ifadeyle bu, gecikme ile $F$ sisteminin yer değiştirebildiği (commute) anlamına gelir; "$\tau$ kadar geciktir, sonra $F$" ile "$F$, sonra $\tau$ kadar geciktir" blok diyagramları eşdeğerdir (ekrandan, 00:50:00).

> **Hocanın vurgusu:** Zamanla değişmezlik sistem özellikleri arasında özel bir yere sahiptir; sistemlerin analizini büyük ölçüde basitleştirir.

## 7. Kararlılık ve Hız Sabitleyici Örneği

### 7.1 BIBO kararlılık

Kararlılık (stability, Türkçede duranlık da denir) çoğu mühendislik uygulamasında önemli bir kavramdır. Tanım şöyledir: giriş sınırlıysa, yani her $t$ anında $|x(t)| \le M_x$ ise, çıkış da sınırlı olmalıdır: $|y(t)| \le M_y$. Burada $M_x$ ve $M_y$ sonlu pozitif sayılardır. Bu özelliği sağlayan sistemlere sınırlı giriş, sınırlı çıkış (Bounded Input Bounded Output, BIBO) kararlı sistemler denir.

Sınırlı olmayan bir işarete örnek olarak hoca $a > 0$ (örneğin $a = 1$) için $e^{at}$ işaretini verdi: $t$ ilerledikçe sonsuza gider. Kararlı bir sistemde ise sınırlı bir giriş verildiğinde çıkış hiçbir anda sonsuza gitmez.

### 7.2 Hız sabitleyici (cruise control)

Slayttaki örnek, arabanın sabit hızla gitmesini sağlayan hız sabitleyicidir (ekrandan, 00:55:00). Sürücü ayağını pedaldan çeker ve istenen hızı (örneğin 90) girer. Yol yokuş yukarı ya da aşağı gittikçe gazın artırılıp azaltılması gerekir.

- $x$: sürücünün girdiği istenen hız (requested speed).
- $y$: arabanın gerçek hızı (speed); $H$ sistemi arabadır.
- $e = x - y$: hata (error), bir karşılaştırıcıda (toplama noktası) oluşur.
- $k$: hatayı gaz miktarına çeviren kazanç.

Arabanın hızı geri beslenip istenen hızdan çıkarılır. Örneğin istenen hız 90 iken araba 88 ile gidiyorsa hata pozitiftir ve biraz daha gaza basılması gerekir. Araba 92 ile gidiyorsa hata negatiftir ve gaz kesilir. Slayttaki maddelere göre: pozitif hata gaz ekler; hız değişimi gecikmeli olduğu için hız hedefi aşar (overshoot); negatif hata gazı keser; yine gecikme nedeniyle hız hedefin altına düşer (undershoot); süreç tekrar eder. Çıkış:

$$y = H\big(k(x - y)\big)$$

Slayta göre $k$ çok büyükse ($H$'ye bağlı olarak) bu sistem kararsız hale gelebilir; bu ileride görülecektir (ekrandan, 00:55:00).

## 8. Terslenebilirlik

Çıkış işaretinden giriş işareti yeniden elde edilebiliyorsa sistem terslenebilirdir (invertible). $y = F(x)$ için, $y$ verildiğinde $x$'i üreten bir ters sistem $F^{-1}$ kurulabiliyorsa sistem terslenebilirdir:

$$F^{-1}(y) = F^{-1}\big(F(x)\big) = x$$

$F$ ile $F^{-1}$ seri (kaskat) bağlandığında yeniden $x$ elde ediliyorsa, yani $F^{-1}F$ birim (identity) operatör gibi davranıyorsa sistem terslenebilirdir.

> **Ders sonrası not:** Hoca bu noktada "$F^{-1} = 1/F$ ise" ifadesini kullandı. Ters sistem genel olarak $F$'nin tersi (çarpmaya göre tersi) değil, $F$'nin yaptığı dönüşümü geri alan operatördür. $1/F$ yorumu büyük olasılıkla yalnız ölçekleyen sistem gibi çarpma biçimindeki sistemler için geçerlidir; örneğin $y = ax$ ($a \ne 0$) için ters sistem $x = y/a$'dır.

## 9. Doğrusal Sabit Katsayılı Diferansiyel ve Fark Denklemleri

### 9.1 Sürekli zamanda

Birçok sistem doğrusal, sabit katsayılı sıradan diferansiyel denklemlerle ifade edilebilir:

$$a_n y^{(n)} + \dots + a_1 \dot y + a_0 y = b_m x^{(m)} + \dots + b_1 \dot x + b_0 x$$

Burada $y^{(n)}$, $y$'nin $n$. türevidir. $n$ sistemin mertebesini (order), yani kaçıncı dereceden olduğunu gösterir. $a$ ve $b$ katsayıları sabitse bu sistemlere doğrusal sabit katsayılı (LCCODE) sistemler denir. Denklemi çözebilmek için başlangıç koşullarının verilmesi gerekir. Bu biçimde ifade edilen sistemler, başlangıç koşulları sıfır olduğunda doğrusaldır. Slayttaki notlara göre bu denklem $y(t)$'yi $x(t)$ cinsinden açıkça vermez; bu açık ifade ileride elde edilecektir (ekrandan, 01:00:00).

Hocanın dikkat çektiği gibi $x$'in katsayıları $b$'ler, $y$'nin katsayıları $a$'lardır. Slayttaki basit örnekler (ekrandan, 01:00:00):

- **Ölçekleyen sistem** ($a_0 = 1,\ b_0 = a$): $y = a\,x$.
- **İntegral alıcı** ($a_1 = 1,\ b_0 = 1$, $a_0 = 0$): $\dot y = x$; türevi girişe eşit olan bir sistem, yani integral alıcı.
- **Türev alıcı:** girişin türevini alan sistem.
- **Geri beslemeli integral alıcı** ($a_1 = 1,\ a_0 = a$): $\dot y + a\,y = x$; bu, 3.4'te blok diyagramdan bulunan $\dot y = x - a y$ denklemiyle aynıdır.

### 9.2 Fiziksel örnekler: RLC devresi ve araba süspansiyonu

Hoca devreler dersinden bir örnek verdi: girişi $x$, çıkışı (kondansatör gerilimi) $y$ olan seri bir RLC devresi. Kirchhoff'un gerilim yasasına göre

$$x - L\frac{di}{dt} - R\,i - y = 0$$

olur; bobin üzerinde akımın değişimiyle bir gerilim oluşur. Kondansatör akımı, üzerindeki gerilimin değişimiyle tanımlanır: $i = C\dfrac{dy}{dt}$. Hepsi yerine konduğunda doğrusal, sabit katsayılı bir denklem elde edilir:

$$LC\,\ddot y + RC\,\dot y + y = x \quad \text{(ara adım eklendi)}$$

Aynı yapı mekanik bir sistemde de kurulabilir. Arabanın gövdesi bir yay ve bir amortisörle (şok emici) tekerleğe bağlıdır. $x$ yolun (tabanın) dikey konumu, yani yoldaki tümsek ve çukurlar; $y$ ise ana kütlenin, yani arabanın dikey konumudur. $x - y$ yol ile araba arasındaki mesafedir; $k$ ile çarpılınca yay kuvveti elde edilir. Amortisördeki hidrolik sıvının oluşturduğu sönüm kuvveti ise bu farkın türevinin $b$ katsayısıyla çarpımıdır. Bunlar Newton'un ikinci yasasına konur:

$$m\,\ddot y = k\,(x - y) + b\,(\dot x - \dot y) \quad \text{(ara adım eklendi)}$$

<!-- BELİRSİZ: RLC devresi ve süspansiyon slaytlarının karesi yok; denklemler hocanın sözlü anlatımından kuruldu, slayttaki yazım farklı olabilir. -->

### 9.3 Ayrık zamanda: fark denklemleri

Ayrık zamanlı sistemlerde de büyük ölçüde aynı blok diyagram elemanları kullanılır; ölçekleme ve gecikme blokları yaygındır. Sistem denklemleri fark denklemleridir (ekrandan, 01:05:00):

$$a_0 y[n] + a_1 y[n-1] + \dots = b_0 x[n] + b_1 x[n-1] + \dots$$

Burada $x[n]$ giriş, $y[n]$ çıkıştır. $y[n-1]$, $x[n-1]$ gibi terimler gecikmiş çıkış ve girişleri gösterir. Şu anki çıkış $y[n]$ ve şu anki giriş $x[n]$'nin katsayıları $a_0$ ve $b_0$'dır; sistem çıkışını üretirken hem geçmiş girişlerden hem geçmiş çıkışlardan yararlanır. Hoca bu fark denklemlerinin çözümünün sayısal işaret işleme (DSP) konusu olduğunu söyledi.

### 9.4 Ayrık zamanlı sistem örneği

Slayttaki örnekte (ekrandan, 01:25:00) çıkış $a$ ile çarpılıp girişten çıkarılıyor; fark, $T = 1$ birimlik bir gecikme bloğuna giriyor ve gecikme bloğunun çıkışı sistem çıkışı oluyor.

Verilenler:

- Gecikmenin girişi: $e[n] = x[n] - a\,y[n]$
- Gecikmenin çıkışı: $y[n] = e[n-1]$

İşlem: $e[n]$ ifadesinde $n$ yerine $n-1$ yazılır. Bu yalnız $e$'nin değil, içindeki $x$ ve $y$'nin argümanını da değiştirir:

$$e[n-1] = x[n-1] - a\,y[n-1]$$

Sonuç:

$$y[n] = x[n-1] - a\,y[n-1]$$

Yani çıkış, girişin gecikmiş hali ile çıkışın gecikmiş halinin $a$ ile çarpılmış halinin farkıdır. Bu denklemle çıkış, önceki çıkış ve giriş değerlerinden adım adım hesaplanabilir.

## 10. Önceki Konuların Tekrarı: Örnek Soruların Çözümü

Hoca ders panosuna önceki konulara ait bir örnek soru dosyası yükledi ve dersin ikinci yarısında bunları çözdü. Kaynak kitap olarak "DSP First"i, ayrıca Türkçe çevirisi bulunan iki "Sinyaller ve Sistemler" kitabını (Oppenheim'in kitabı ve Schaum serisinin kitabı) önerdi. <!-- BELİRSİZ: altyazıda "Xiaomi serisi" geçiyor; büyük olasılıkla "Schaum serisi"dir. -->

Soruların tam metni ve çözümleri "Örnek Sorular" bölümündedir. Burada hocanın anlatım sırasıyla kavramsal noktalar özetlenir.

### 10.1 Öteleme, ölçekleme ve yansıma

Örnek işaret $x(t)$, $t = 0$'da 0'dan başlayıp $t = 4$'te 3'e kadar doğrusal artan ve $t = 4$'te sıfıra düşen bir üçgen dalgadır (ekrandan, 01:30:00). Hocanın genel kuralları:

- $x(t - t_0)$, $t_0 > 0$ için işareti $t_0$ birim sağa kaydırır.
- $x(at)$, $a > 1$ ise işareti sıkıştırır (compress), $0 < a < 1$ ise genişletir. En güvenilir yol, $t$ yerine değerler koyup $x$'in hangi noktadaki değerini aldığına bakmaktır.
- $x(-t)$, işareti dikey eksene göre aynalar: ana değişken $t$'nin başına gelen eksi işaret yansımayı yapar.

Ayrık işarette de mantık aynıdır. $x[2n]$, her iki örnekten birini alarak işareti sıkıştırır ve arada kalan örnekler atlanır. $x[-n+2]$ için $n = 0$ konulunca orijinal işaretin $2$'deki değeri, $n = -2$ konulunca $4$'teki değeri elde edilir. Hoca, deneme yanılmayla orijinal işaretten yararlanarak bu tür manipülasyonların rahatça yapılabileceğini söyledi.

### 10.2 Birim basamakla işaret kesme

Birim basamak $u(t)$, $t < 0$ için 0, $t \ge 0$ için 1'dir ve sonsuza kadar sürer. Hoca birim basamak fonksiyonunun daha çok fonksiyonların sınırlarını belirlemek için kullanıldığını hatırlattı.

- $u(1 - t)$: İçerideki ifade sıfıra eşitlenerek ($1 - t = 0$) başlangıç noktası $t = 1$ bulunur. $-t$ nedeniyle işaret ters dönmüştür: $t \le 1$ için 1, $t > 1$ için 0'dır. Bununla çarpmak işaretin yalnız $t \le 1$ kısmını bırakır.
- $u(t) - u(t-1)$: $u(t-1)$ birden başlayan basamaktır; başındaki eksi onu aşağı alır. İkisi toplandığında $t \ge 1$ kısımları birbirini götürür ve geriye $0 \le t < 1$ aralığında 1 olan bir kare (kapı) fonksiyonu kalır. Bununla çarpmak işaretin yalnız bu aralıktaki kısmını bırakır.

### 10.3 Dürtüyle çarpım

$\delta(t)$ yalnız $t = 0$'da değer alır; $\delta(t-1)$ bir birim, $\delta(t-1.5)$ bir buçuk birim sağa kaymıştır. Bir işaret dürtüyle çarpılınca yalnız dürtünün bulunduğu noktadaki değeri kalır ve bu değer dürtünün genliğini (ağırlığını) belirler.

**Soru:** (Bir öğrenci) $\delta(t - 1.5)$, 0,5 ile 2,5 arasında mı değer alır?
**Cevap:** Hayır; delta yalnız $t = 1.5$ noktasında değer alır. Öğrenci, grafikte $-1$ ile $1$ arasında görülen dikdörtgen biçimden yola çıkarak bir aralık bulmaya çalıştığını söyledi; hoca $\delta(t-1)$'in bir birim, $\delta(t-1.5)$'in bir buçuk birim sağa kaymış tek bir dürtü olduğunu gösterdi.

## Örnek Sorular

**Soru 1** (ekrandan, 01:30:00): Şekildeki sürekli zamanlı $x(t)$ işareti verilmiştir: $0 \le t \le 4$ aralığında $x(t) = \frac{3}{4}t$ (0'dan 3'e doğrusal artış), diğer yerlerde $x(t) = 0$. Aşağıdaki işaretleri çiziniz: (a) $x(t-2)$, (b) $x(2t)$, (c) $x(t/2)$, (d) $x(-t)$.

Çözüm (derste verildi):

- (a) $x(t-2)$: İşaret 2 birim sağa kayar. $t = 2$'de 0'dan başlar, $t = 6$'da 3'e ulaşır ve orada sıfıra düşer.
- (b) $x(2t)$: $t = 1$ konunca $x(2)$, $t = 2$ konunca $x(4) = 3$, $t = 3$ konunca $x(6) = 0$ elde edilir. İşaret sıkışır: $0 \le t \le 2$ aralığında 0'dan 3'e çıkar.
- (c) $x(t/2)$: $t = 0$ konunca $x(0)$, $t = 1$ konunca $x(1/2)$, $t = 8$ konunca $x(4) = 3$ elde edilir. İşaret iki kat genişler: $0 \le t \le 8$ aralığında 0'dan 3'e çıkar.
- (d) $x(-t)$: $t = 1$ konunca $x(-1) = 0$; pozitif $t$ değerlerinde işaret sıfırdır. $t = -1$ konunca $x(1)$ elde edilir. İşaret dikey eksene göre aynalanır: $-4 \le t \le 0$ aralığında yer alır, $t = -4$'te 3 değerini alır.

> **Ders sonrası not:** Hoca (b) şıkkında $x(2)$ değerini "yaklaşık 1.3" diye okudu. Şekildeki doğru $(0,0)$ ile $(4,3)$ noktalarından geçtiği için $x(2) = \frac{3}{4}\cdot 2 = 1.5$'tir (python ile kontrol edildi).

**Soru 2** (derste sözlü, 01:36:47): Dört örnekten oluşan bir ayrık işaret $x[n]$ için $x[n-2]$, $x[2n]$, $x[-n]$ ve $x[-n+2]$ işaretlerini çiziniz. <!-- BELİRSİZ: ayrık işaretin örnek değerleri ve konumu karede görülmedi; çözüm yalnız sözlü anlatımdan yazıldı. -->

Çözüm (derste verildi):

- $x[n-2]$: İşaret iki örnek sağa kayar.
- $x[2n]$: $n = 0$ için $x[0]$, $n = 1$ için $x[2]$, $n = 2$ için $x[4]$ alınır. İşaret hem sıkışır hem de bir örnek atlanarak alınır.
- $x[-n]$: Orijinal işaretin dikey eksene göre aynalanmasıdır; değerler negatif $n$'lerde yer alır.
- $x[-n+2]$: $n = 0$ için $x[2]$, $n = -2$ için $x[4]$ alınır; aynalanmış işaret iki örnek sağa kaymıştır.

**Soru 3** (ekrandan, 01:40:00): Şekildeki $x(t)$ işareti verilmiştir: $-1 \le t \le 0$ aralığında 0'dan 1'e doğrusal artar, $0 \le t < 1$ aralığında 1, $1 \le t \le 2$ aralığında 2, diğer yerlerde 0'dır. Aşağıdaki işaretleri çiziniz: (a) $x(t)\,u(1-t)$, (b) $x(t)\,[u(t) - u(t-1)]$, (c) $x(t/2)\,\delta(t-1.5)$.

Çözüm (derste verildi, ekrandan, 01:45:00):

- (a) $u(1-t)$, $t \le 1$ için 1, $t > 1$ için 0'dır. Çarpım, işaretin $t > 1$ kısmını (2 değerli bölümü) siler: geriye $-1 \le t \le 0$'daki rampa ve $0 \le t < 1$'deki 1 değerli bölüm kalır.
- (b) $u(t) - u(t-1)$, $0 \le t < 1$ aralığında 1 olan kapı fonksiyonudur. Çarpım yalnız bu aralığı bırakır: $0 \le t < 1$ için $x(t) = 1$, diğer yerlerde 0.
- (c) Dürtü $t = 1.5$'te durur. Genliği $x(t/2)$'nin $t = 1.5$'teki değeridir: $x(1.5/2) = x(0.75) = 1$. Sonuç: $x(t/2)\,\delta(t-1.5) = \delta(t-1.5)$, yani $t = 1.5$'te genliği 1 olan bir dürtü.

> **Hocanın vurgusu:** Hoca, cevap slaytında bu şıkkın yanlış çizildiğini gösterdi. Slayttaki çizim $x(t)\,\delta(t - 1.5)$'e, yani $x(1.5) = 2$ genlikli dürtüye karşılık gelir. Soruda $x(t/2)$ verildiği için doğru cevap genliği 1 olan dürtüdür.

**Soru 4** (ekrandan, 01:50:00): Üstel olarak azalan $x(t) = e^{-2t}$ ($t \ge 0$), $x(t) = 0$ ($t < 0$) işaretinin enerjisini bulunuz.

Çözüm (derste verildi):

- $t = 0$'da $x(0) = e^{0} = 1$'dir; $t$ arttıkça işaret azalır ve sonsuzda sıfıra gider. Bu yüzden karesinin altında kalan alanın sonlu olması beklenir.
- $|x(t)|^2 = e^{-4t}$ ($t \ge 0$). İşaret $t < 0$'da sıfır olduğu için integralin alt sınırı $-\infty$ yerine 0 alınır:
  $$E = \int_{0}^{\infty} e^{-4t}\,dt = \left[-\frac{1}{4}e^{-4t}\right]_{0}^{\infty} = 0 - \left(-\frac14\right) = \frac14$$
- Enerji sonlu olduğu için $x(t)$ bir enerji işaretidir (python ile kontrol edildi).

**Soru 5** (ekrandan, 01:55:00): $x(t) = A\cos\omega t$ veriliyor; $A$ pozitif gerçel bir sabittir. (a) İşaretin bir periyottaki enerjisini, (b) ortalama gücünü bulunuz.

Çözüm (derste verildi):

- Periyot $T_0 = 1/f$, $\omega = 2\pi f = 2\pi/T_0$'dır. Bir periyot $[-T_0/2,\ T_0/2]$ aralığı olarak alınır; genel enerji formülündeki $\pm\infty$ sınırları yerine bu sınırlar yazılır.
- Yan bilgi olarak verilen özdeşlik: $\cos^2\theta = \dfrac{1 + \cos 2\theta}{2}$.
  $$E_0 = \int_{-T_0/2}^{T_0/2} A^2\cos^2(\omega t)\,dt = \frac{A^2}{2}\int_{-T_0/2}^{T_0/2} dt + \frac{A^2}{2}\int_{-T_0/2}^{T_0/2}\cos(2\omega t)\,dt$$
- Birinci terim: $\dfrac{A^2}{2}T_0$.
- İkinci terim: $\dfrac{A^2}{2}\cdot\dfrac{1}{2\omega}\big[\sin(\omega T_0) - \sin(-\omega T_0)\big] = \dfrac{A^2}{2\omega}\sin(\omega T_0)$. Sinüs tek fonksiyon olduğu için eksi işaret dışarı çıkar ve iki terim toplanır (ara adım eklendi). $\omega T_0 = \frac{2\pi}{T_0}T_0 = 2\pi$ ve $\sin 2\pi = 0$ olduğundan bu terim sıfırdır.
- Sonuç: $E_0 = \dfrac{A^2 T_0}{2}$.
- (b) Ortalama güç, bir periyottaki enerjinin periyoda bölümüdür: $P = \dfrac{E_0}{T_0} = \dfrac{A^2}{2}$.

> **Ders sonrası not:** Hoca enerjiyi bir yerde "$A^2$ bölü 2 bölü $T_0$" diye söyledi. Doğrusu $E_0 = A^2T_0/2$'dir; ortalama gücün $A^2/2$ çıkması da bunu doğrular (python ile sayısal olarak kontrol edildi).

**Soru 6** (ekrandan, 02:00:00): $x(t) = e^{-|t|}$ işaretinin enerji ve güç içeriğini bulunuz.

Çözüm (derste verildi, ekrandan, 02:05:00):

- $|x(t)|^2 = e^{-2|t|}$: $t < 0$ için $e^{2t}$, $t > 0$ için $e^{-2t}$.
- İntegral iki parçaya bölünür; negatif kısımda değişken değiştirilince iki parça eşit olur:
  $$E = \int_{-\infty}^{0} e^{2t}\,dt + \int_{0}^{\infty} e^{-2t}\,dt = 2\int_{0}^{\infty} e^{-2t}\,dt = 1$$
- Enerji sonlu olduğu için bu bir enerji işaretidir.
- Ortalama güç için $[-T/2,\ T/2]$ aralığındaki enerji $T$'ye bölünür ve $T \to \infty$ alınır:
  $$P = \lim_{T\to\infty}\frac{1}{T}\int_{-T/2}^{T/2} e^{-2|t|}\,dt = \lim_{T\to\infty}\frac{2}{T}\int_{0}^{T/2} e^{-2t}\,dt = \lim_{T\to\infty}\frac{1}{T}\left(1 - e^{-T}\right)$$
- Bu limit iki terime ayrılır: $\lim \frac{1}{T} - \lim \frac{e^{-T}}{T}$. Birinci terim $T \to \infty$ iken sıfıra gider. İkinci terimde $e^{-T} \to 0$ olduğu için o da sıfırdır. Sonuç $P = 0$; bir enerji işareti için beklendiği gibi gücü sıfırdır (python ile kontrol edildi).

**Soru 7** (ekrandan, 02:05:00): $x(t) = 2\cos t - \sin t + 3\sin t\cos t$ işaretinin çift ve tek bileşenlerini bulunuz. Hatırlatma: $x_e(t) = \dfrac{x(t) + x(-t)}{2}$, $x_o(t) = \dfrac{x(t) - x(-t)}{2}$.

Çözüm (derste verildi, ekrandan, 02:15:00):

- Önce $x(-t)$ bulunur. Kosinüs çift fonksiyondur, içindeki eksi kaybolur: $\cos(-t) = \cos t$. Sinüs tek fonksiyondur, eksi dışarı çıkar: $\sin(-t) = -\sin t$.
  $$x(-t) = 2\cos t + \sin t - 3\sin t\cos t$$
- Çift bileşen: $x_e(t) = \dfrac{4\cos t}{2} = 2\cos t$.
- Tek bileşen: $x_o(t) = \dfrac{-2\sin t + 6\sin t\cos t}{2} = -\sin t + 3\sin t\cos t$.
- Kontrol: $x_e + x_o = x(t)$ (python ile kontrol edildi).

**Soru 8** (ekrandan, 02:15:00): $x(t) = 3\cos\left(\frac{\pi}{5}t - \frac{\pi}{4}\right)$ işaretini $-10 \le t \le 20$ s aralığında çiziniz. Genliği ($A$), frekansı ($f$), periyodu ($T$), fazı ($\phi$) ve bir maksimumun zamanını ($t_m$) belirleyiniz.

Çözüm (derste verildi, ekrandan, 02:10:00):

- Genel biçim $A\cos(\omega_0 t + \phi)$ ile karşılaştırılır: $A = 3$, $\phi = -\pi/4$.
- $\omega_0 = 2\pi f = \pi/5$ olduğundan $f = \dfrac{\pi/5}{2\pi} = \dfrac{1}{10}$ Hz.
- $T = 1/f = 10$ s; ardışık iki tepe arasında 10 saniye geçer.
- İlk maksimum, kosinüsün argümanını sıfır yapan andır ($\cos 0 = 1$): $\omega_0 t_m + \phi = 0 \Rightarrow t_m = -\dfrac{\phi}{\omega_0} = \dfrac{\pi/4}{\pi/5} = 1.25$ s. Sıfırdan önce ve sonra da maksimumlar vardır; bu formül sıfırdan sonraki ilkini verir.
- $t = 0$'da $x(0) = 3\cos(-\pi/4) = \dfrac{3\sqrt2}{2} \approx 2.12$.
- $-10$ ile $20$ arasındaki 30 saniyelik aralıkta işaret üç periyot tamamlar.

Hocanın tahtaya yazdığı MATLAB çizim komutları (ekrandan, 02:15:00; geri kalanı sözlü anlatımdan):

```matlab
t = -10:0.01:20;          % -10'dan 20'ye 0.01 adımlı zaman ekseni
x = 3*cos(pi/5*t - pi/4); % t ile aynı uzunlukta x üretir
plot(t, x)
```

Hoca 0.01 adımının nedenini şöyle açıkladı: işaret sürekli olsa da bilgisayar ayrık değerlerle çalışır; küçük adımlarla örneklenince ekranda sürekli bir fonksiyon gibi görünür. Kod MATLAB'de çalıştırılmadı; numpy karşılığıyla 3001 örnek üretildiği ve $t \ge 0$ için ilk maksimumun $t = 1.25$ s'de olduğu doğrulandı.

**Soru:** (Bir öğrenci, 02:19:13) $t_m$ formülü nereden geliyor?
**Cevap:** Kosinüslü ifadenin içi $\omega_0 t + \phi$'dir. İlk maksimumun yeri için bu ifade sıfıra eşitlenir, çünkü $\cos 0 = 1$ maksimum değerdir. Buradan $t = -\phi/\omega_0$ bulunur. $\phi = -\pi/4$ ve $\omega_0 = 2\pi/10 = \pi/5$ yerine konunca $t_m = 1.25$ s elde edilir.

**Soru 9** (derste sözlü, 02:13:01): $\cos 5t$ ve $\cos 5\pi t$ işaretlerinden hangisinde $\omega/2\pi$ oranı rasyonel bir sayıdır?

Çözüm (derste verildi): $\cos 5\pi t$ için $\dfrac{5\pi}{2\pi} = \dfrac{5}{2}$ rasyoneldir. $\cos 5t$ için $\dfrac{5}{2\pi}$ irrasyoneldir. Bir öğrencinin cevabıyla: rasyonel sayılar kesir olarak yazılabilen, irrasyonel sayılar kesir olarak yazılamayan ve virgülden sonraki kısmı tahmin edilemeyen sayılardır. Hoca aynı soruyu $\cos(2t + \pi/4)$ için de sordu ($2/2\pi = 1/\pi$, irrasyonel).

> **Ders sonrası not:** Hoca $\omega/2\pi$ (ya da $2\pi/\omega$) rasyonel değilse işaretin periyodik olmayacağını söyledi ve $\cos(2t + \pi/4)$'ün periyodik olmadığını belirtti. Bu koşul büyük olasılıkla ayrık zamanlı sinüzoidaller içindir: $\cos(\Omega n)$ ancak $\Omega/2\pi$ rasyonelse periyodiktir. Sürekli zamanda $\cos(\omega t + \phi)$ her $\omega \ne 0$ için $T = 2\pi/\omega$ periyoduyla periyodiktir; $\cos 5t$'nin periyodu $2\pi/5$, $\cos(2t+\pi/4)$'ün periyodu $\pi$'dir. Hocanın "frekanslar rasyonel sayılar alır" ifadesi de büyük olasılıkla bir dil sürçmesidir; frekans herhangi bir gerçel sayı olabilir.

> **Ek bilgi (derste anlatılmadı):** Sürekli zamanlı iki sinüzoidalin toplamının periyodik olup olmadığı sorulduğunda oran koşulu yeniden ortaya çıkar: $\cos\omega_1 t + \cos\omega_2 t$ ancak $\omega_1/\omega_2$ rasyonelse periyodiktir. Hocanın hatırlattığı oran koşulu büyük olasılıkla önceki derste bu iki bağlamdan birinde anlatılmıştı.

**Soru 10** (ekrandan, 01:25:00): Şekildeki ayrık zamanlı sistemde giriş $x[n]$, toplama noktasında çıkışın $a$ katı çıkarılıyor ve sonuç $T = 1$ gecikme bloğundan geçerek $y[n]$ oluyor. Sistemin fark denklemini yazınız.

Çözüm (derste verildi): $e[n] = x[n] - a\,y[n]$ ve $y[n] = e[n-1]$ olduğundan $y[n] = x[n-1] - a\,y[n-1]$ (ayrıntı 9.4'te).

## Dersin Toparlaması

Bu derste sistem kavramı tanımlandı ve sistemlerin temel özellikleri işlendi. Ölçekleyen, türev ve integral alan, öteleyen, konvolüsyon yapan ve çok girişli sistemler örnek olarak verildi. Seri, paralel ve geri beslemeli bağlantılar blok diyagram ve denklemlerle ifade edildi. Ardından doğrusallık (homojenlik ve toplamsallık), hafıza, zamanla değişmezlik, BIBO kararlılık ve terslenebilirlik tanımlandı. Doğrusal sabit katsayılı diferansiyel ve fark denklemlerinin, RLC devresi ve araba süspansiyonu gibi fiziksel sistemleri nasıl tanımladığı gösterildi ve bir ayrık zamanlı sistemin fark denklemi blok diyagramdan çıkarıldı.

Dersin ikinci yarısında önceki konular örnek sorularla tekrar edildi: zamanda öteleme, ölçekleme ve yansıma; birim basamak ve dürtüyle işaret kesme; enerji ve güç hesapları; çift-tek ayrıştırma ve sinüzoidal işaretin parametreleri. Hoca böylece frekans öncesi konuların tamamlandığını, bir sonraki derste Fourier ve frekans analizine geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
