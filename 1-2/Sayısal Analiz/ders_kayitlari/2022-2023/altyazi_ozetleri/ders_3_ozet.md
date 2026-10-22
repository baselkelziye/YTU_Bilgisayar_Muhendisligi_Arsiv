# Ders 3 Çalışma Özeti

## Genel Konular

- Ders, doğrusal olmayan denklemlerin kökünü bulma yöntemleriyle devam eder. Önce geçen haftanın kısa bir tekrarı yapılır. Ardından kapalı yöntemler (grafik, ikiye bölme, regula falsi) ve açık yöntemler (Newton-Raphson, sekant) örneklerle anlatılır. Basit iterasyon (sabit nokta) yöntemi gelecek haftaya bırakılır.
- Tekrar: doğrusal olmayan denklemler ve kök şartı
  - Bilinmeyenin derecesi 1'den büyükse veya denklemde $\sin x$, $e^{3x}$ gibi trigonometrik ya da üstel terimler varsa denklem doğrusal değildir. Örnek: $x^2 + \sin x + e^{3x}$.
  - Bu derste görülen yöntemler tek bilinmeyenli denklemler içindir. İki bilinmeyen varsa bu yöntemlerle bir yere varılamaz.
  - Fonksiyon $[a, b]$ aralığında sürekli olmalı ve $f(a)$ ile $f(b)$ ters işaretli olmalıdır ($f(a) \cdot f(b) < 0$). O zaman aralıkta en az bir kök vardır.
  - Ortalama değer teoreminde $c$ noktasındaki türev, $\frac{f(b) - f(a)}{b - a}$ ile bulunur. Türevi alınamayacak kadar karmaşık bir fonksiyonun bir noktadaki türevi böyle hesaplanabilir. Aralıktaki salınım sayısı kadar $c$ noktası olabilir.
  - Süreklilik: bir noktada soldan limit, sağdan limit ve fonksiyonun değeri eşitse fonksiyon o noktada süreklidir. Parçalı fonksiyonlar da sürekli olabilir. Süreksiz bir fonksiyonun kökü bu yöntemlerle bulunamaz.
- Durma ölçütleri
  - Gerçek kök genellikle bilinmez. Bu yüzden ardışık iki kök tahmininin mutlak farkına bakılır: $|x_k - x_{k-1}| \le \varepsilon$. Mutlak değer alınır, çünkü fark negatif çıkabilir.
  - Gerçek kök verilmişse bulunan değer ile gerçek değer arasındaki farka bakılabilir.
  - Kapalı yöntemlerde bir ölçüt daha vardır: $\frac{b - a}{2^n} \le \varepsilon$ ($n$: iterasyon sayısı).
  - Hata payı $\varepsilon$ ile adım büyüklüğü $\Delta x$ farklı şeylerdir. $\varepsilon$ sonucu ne kadar hatayla kabul edeceğinizdir. $\Delta x$ ise döngüde $x$'i ne kadar artıracağınızdır.
  - İşe başlarken kaç iterasyonda duracağınızı bilemezsiniz. $\varepsilon$ küçültülürse iterasyon sayısı artar. Başlangıç değeri köke uzaksa iterasyon da uzar. Kodda iterasyon sayısıyla durdurmak mümkündür ama o zaman sonucun hatası bilinmez.
- Grafik yöntemi (artımlı arama)
  - Bir başlangıç değeri $x_0$ ve bir artım miktarı $\Delta x$ seçilir. $x$, $\Delta x$ kadar artırılarak fonksiyonda yerine konur. Hesaplanan son iki fonksiyon değeri ters işaretli olana kadar devam edilir.
  - İşaret değişince kök bu iki $x$ arasındadır. $\Delta x$ yarıya indirilir ve aramaya bu aralığın sol ucundan tekrar başlanır.
  - Ardışık iki $x$ değerinin mutlak farkı $\varepsilon$'dan küçük veya eşit olunca durulur. Yalnızca fonksiyonun işaret değiştirdiği yerde bu kontrol yapılır.
  - Örnek: $f(x) = x^2 - 6x + 5$, $x_0 = 1.5$, $\Delta x = 0.75$. Gerçek kökler 1 ve 5.
    - 1. tarama: $f(1.5) = -1.75$, $f(2.25) = -3.4375$, $f(3) = -4$, $f(3.75) = -3.4375$, $f(4.5) = -1.75$, $f(5.25) = 1.0625$. İşaret değişti, kök $[4.5, 5.25]$ aralığında.
    - 2. tarama ($\Delta x = 0.375$): $f(4.875) = -0.484$, $f(5.25) > 0$. Kök $[4.875, 5.25]$ aralığında.
    - 3. tarama ($\Delta x = 0.1875$): $f(5.0625) = 0.2539$. Kök $[4.875, 5.0625]$ aralığında.
    - 4. tarama ($\Delta x = 0.09375$): $f(4.96875) = -0.124$, sonra $f(5.0625) > 0$.
    - 5. tarama ($\Delta x = 0.046875$): $f(5.015625) = 0.0627$. Kök $[4.96875, 5.015625]$ aralığında.
    - 6. tarama ($\Delta x = 0.0234$): $f(4.9921875) = -0.031$, $f(5.015625) > 0$. $|5.0156 - 4.9922| \approx 0.0234$. Durulur.
    - Son bulunan $x$ genellikle kök kabul edilir (5.016). İki değerin arasındaki bir sayı da kök kabul edilebilir. "2 anlamlı basamak" istenirse sonuç 5.0'dır.
    - Bulunan değeri fonksiyonda yerine koyunca tam 0 çıkmaz. Fonksiyon değeri sıfıra ne kadar yakınsa $x$ köke o kadar yakındır.
  - Hoca $x_0 = 1.5$'i köke yakın olsun diye seçtiğini söyler. Örneğin 3 seçilseydi iterasyon çok daha uzun sürerdi. Sınavlarda elle çözülebilsin diye az iterasyonda biten değerler verilir.
  - Projede $\Delta x$ ve $\varepsilon$ ne kadar küçük verilirse sonuç o kadar hassas olur.
- İkiye bölme yöntemi (bisection, aralık yarılama)
  - Kapalı aralık yöntemidir. Önce $f(a) \cdot f(b) < 0$ olduğu kontrol edilir.
  - $c = \frac{a + b}{2}$ hesaplanır ve $f(c)$'nin işaretine bakılır. $f(a)$ ile $f(c)$ ters işaretliyse yeni aralık $[a, c]$, değilse $[c, b]$ olur. Her adımda aralık yarıya iner.
  - Önemli olan, hep fonksiyonun ters işaretli olduğu iki noktanın arasını küçülterek köke yaklaşmaktır.
  - Örnek: $f(x) = x^3 - 7x^2 + 14x - 6$, $[0, 1]$, $\varepsilon = 0.01$. $f(0) = -6$, $f(1) = 2$, aralıkta kök var.
    - 1. iterasyon: $c = 0.5$, $f(0.5) = -0.625$. Yeni aralık $[0.5, 1]$.
    - 2. iterasyon: $c = 0.75$, $f(0.75) = 0.9844$. Yeni aralık $[0.5, 0.75]$.
    - 3. iterasyon: $c = 0.625$, $f(0.625) = 0.2598$. Yeni aralık $[0.5, 0.625]$.
    - 4. iterasyon: $c = 0.5625$, $f(0.5625) = -0.1619$. Yeni aralık $[0.5625, 0.625]$.
    - Durma kontrolü: $\frac{b - a}{2^n} \le \varepsilon$. Doğru iterasyon sayısı için "Ders sonrası notlar" bölümüne bakın.
- Regula falsi (yanlış nokta) yöntemi
  - İkiye bölmeden farkı: $c$ hesaplanırken yalnızca $a$ ve $b$ değil, $f(a)$ ve $f(b)$ değerleri de kullanılır.
  - $(a, f(a))$ ve $(b, f(b))$ noktaları bir doğruyla birleştirilir. Bu doğrunun x eksenini kestiği nokta $c$'dir. $c$ gerçek kök değildir ama ona yaklaşır.
  - Formülün çıkarılışı (benzer üçgenler): iki üçgende aynı açının tanjantı eşitlenir. $\frac{-f(a)}{c - a} = \frac{f(b)}{b - c}$. $c$ yalnız bırakılınca:
    - $c = \frac{a \cdot f(b) - b \cdot f(a)}{f(b) - f(a)}$
  - Formülü ezberlemeye gerek yok. Fonksiyonu çizin, iki noktayı doğruyla birleştirin, tanjantları eşitleyin ve $c$'yi çekin.
  - Sonra $f(c)$'nin işaretine bakılır. $f(a)$ ile ters işaretliyse yeni $b = c$, $f(b)$ ile ters işaretliyse yeni $a = c$ olur.
  - Örnek: $f(x) = x^3 - 2x^2 - 5$, $[2, 3]$, $\varepsilon = 0.01$. $f(2) = -5$, $f(3) = 4$.
    - 1. adım: $c = \frac{2 \cdot 4 - 3 \cdot (-5)}{4 + 5} = \frac{23}{9} = 2.556$. $f(2.556) = -1.37$. Kök $[2.556, 3]$ aralığında.
    - 2. adım: $c = 2.669$, $f(2.669) = -0.234$. Kök $[2.669, 3]$ aralığında.
    - 3. adım: $c = 2.6873$, $f(2.6873) = -0.0366$.
    - Sonuç: $x_{kök} \approx 2.69$.
  - Hoca uyarır: "Bu aralıkta kök olduğunu biliyoruz" demesine güvenmeyin. Önce $f(a)$ ve $f(b)$'nin ters işaretli olduğunu kontrol edin. Her ikisi de pozitifse hiçbir sonuç alamazsınız.
- Açık yöntemler
  - Bir veya iki başlangıç değeri ile başlanır. Fonksiyon üzerinde çizimler yapılarak (teğet, kiriş) köke yaklaşılır. Kapalı yöntemlerden genellikle daha hızlıdır ama ıraksayabilir.
- Newton-Raphson yöntemi
  - $x_0$ noktasından fonksiyona teğet çizilir. Teğetin x eksenini kestiği nokta $x_1$'dir. $f(x_1) \neq 0$ ise $x_1$'den yeni teğet çizilir ve $x_2$ bulunur. Böyle devam edilir.
  - Formülün çıkarılışı (teğet): teğetin denklemi $y - y_0 = m(x - x_0)$. Eğim $m = f'(x_0)$, $y_0 = f(x_0)$. $x_1$ noktasında $y = 0$ konur:
    - $x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}$
  - Aynı formül tanjant alfadan (karşı / komşu = eğim = türev) da çıkar.
  - Aynı formül Taylor serisinden de çıkar: $f(x_1) \approx f(x_0) + f'(x_0)(x_1 - x_0)$. Bu ifade sıfıra eşitlenir ve $x_1$ yalnız bırakılır. Grafikle bulunan formülle aynı sonuç elde edilir.
  - Durma: $|x_{k+1} - x_k| \le \varepsilon$. Gerçek kök verilmişse bulunan değerle gerçek değerin farkına bakılabilir.
  - Başlangıç değeri verilmezse, sadece aralık verilirse genellikle aralığın küçük ucu başlangıç değeri alınır. Büyük uç da alınabilir.
  - Örnek: $f(x) = x^3 - 7x^2 + 14x - 6$, $[0, 1]$, $\varepsilon = 10^{-6}$. $f'(x) = 3x^2 - 14x + 14$. $x_0 = 0$.
    - $x_1 = 0 - \frac{-6}{14} = 0.428571$. $|0.4286 - 0| > 10^{-6}$, devam.
    - $x_2 = 0.428571 - \frac{-1.20699}{8.55102} = 0.569724$. Fark 0.141, devam.
    - Ardışık iki değerin farkı $10^{-6}$'dan küçük olana kadar devam edilir.
  - Programda türev ne olacak? Türev kullanıcıdan alınabilir, kodda yazılabilir veya sayısal türev ile hesaplanabilir (ileride görülecek). Sekant yöntemi de türev zorluğundan kurtulmak için geliştirilmiştir.
  - Programda polinom nasıl girilir? String olarak yazıp ayrıştırmaya (parse) gerek yok. Fonksiyonun derecesi istenir, sonra her terim için derece ve katsayı girilir. Örnek $x^3 - 7x^2 + 14x - 6$ için: (3, 1), (2, −7), (1, 14), (0, −6). Olmayan terimin katsayısı 0'dır.
  - Newton-Raphson'un tek zor tarafı türevdir. Trigonometrik, üstel ifadeler içeren fonksiyonların türevini almak zor olabilir.
- Vize sorusu: maksimum hacim
  - Soru: kenarı 6 olan kare bir kartonun dört köşesinden $x$ uzunluğunda kareler kesilir. Kenarlar kaldırılınca üstü açık bir kutu olur. Hacmi en büyük yapan $x$'i Newton-Raphson ile bulun ($x_0 = 0$, $\varepsilon = 0.01$).
  - Taban kenarı $6 - 2x$, yükseklik $x$: $V = (6 - 2x)^2 x = 4x^3 - 24x^2 + 36x$. 4'e bölünür: $x^3 - 6x^2 + 9x$.
  - Maksimum ve minimum noktaları türevin sıfır olduğu yerlerdir. Bu yüzden Newton-Raphson'a girecek fonksiyon $f(x) = 3x^2 - 12x + 9$'dur. $f'(x) = 6x - 12$.
    - $x_1 = 0 - \frac{9}{-12} = 0.75$.
    - $x_2 = 0.975$, sonra 0.9997… Değerler 1'e yakınsar.
  - Kontrol: $x = 1$ için $V = 4^2 \cdot 1 = 16$ (maksimum). Diğer kök $x = 3$ için $V = 0$ (minimum).
  - Sınavda öğrencilerin çoğu hacim fonksiyonunun kendisini $f(x)$ alıp Newton-Raphson'a soktu. Bu yanlıştır. Hacmin kökü değil, türevinin kökü aranır.
  - Hoca bu soruyla şunu gösterir: gerçek hayatta "şu fonksiyonun kökünü bul" denmez. Önce problemi denkleme çevirmek gerekir. Sonra denklem dersin herhangi bir yöntemiyle çözülür.
- Sekant (kiriş) yöntemi
  - Newton-Raphson'daki türevi kaldırmak için geliştirilmiştir. Türev almak zorsa, zaman kaybettiriyorsa veya türev alınamıyorsa kullanılır.
  - $f'(x_k)$ yerine birbirine yakın iki noktadan geçen kirişin eğimi konur: $f'(x_k) \approx \frac{f(x_{k-1}) - f(x_k)}{x_{k-1} - x_k}$.
  - Bu ifade Newton-Raphson formülüne yerleştirilir:
    - $x_{k+1} = x_k - \frac{f(x_k)\,(x_{k-1} - x_k)}{f(x_{k-1}) - f(x_k)}$
  - Gerisi Newton-Raphson ile aynıdır. Fark, türevin dört işlemle hesaplanmasıdır.
  - Örnek: $f(x) = \frac{e^x}{x} - \frac{\sin x}{x^2} + 2x - 10$, $x_{-1} = 10$, $x_0 = 5$, $\varepsilon = 0.01$.
    - $f(5) = \frac{e^5}{5} - \frac{\sin 5}{25} + 10 - 10 = 29.7209$.
    - $x_1 = 5 - \frac{f(5)(10 - 5)}{f(10) - f(5)} = 4.931924$.
    - $x_2 = 3.813366$, $x_3 = 3.234929$, $x_4 = 2.754669$, $x_5 = 2.578048$, $x_6 = 2.544745$, $x_7 = 2.543023$, $x_8 = x_9 = 2.543009$.
    - Kök: 2.543009 ($\varepsilon = 0.01$ için 2.54).
  - Trigonometrik hesaplarda hesap makinesi radyan modunda olmalıdır. Değilse çevirme yapılır: $\pi$ radyan = 180°, yani 5 radyan = $\frac{900}{\pi}$ derece.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dersi derste öğrenin. Bir gece önceden slaytlara bakarsanız yöntemler karışır. Vizeye iki üç yöntemle değil, çok daha fazlasıyla gireceksiniz.
- Formülleri ezberlemeyin. Hepsi birbirine çok yakındır ve çizimden (benzer üçgen, teğet, kiriş, tanjant alfa) kolayca çıkarılabilir.
- Kökü aramadan önce mutlaka fonksiyonun aralıkta sürekli olduğunu ve $f(a) \cdot f(b) < 0$ olduğunu kontrol edin. Soruda "kök olduğunu biliyoruz" denmesine güvenmeyin.
- $\Delta x$ (artım miktarı) ile $\varepsilon$ (hata payı) aynı şey değildir.
- Vize sorusu: maksimum/minimum sorularında Newton-Raphson'a fonksiyonun kendisi değil türevi girer. Öğrencilerin çoğu bunu yanlış yaptı.
- Hesap makinesinde trigonometrik hesaplar için radyan moduna dikkat edin. Yanınızda hesap makinesi olmasını alışkanlık hâline getirin.
- Sınavda ve projede hangi yöntem istenirse o kullanılmalıdır.

## Kısa Tekrar Notları

- Durma: $|x_k - x_{k-1}| \le \varepsilon$. İkiye bölmede ayrıca $\frac{b - a}{2^n} \le \varepsilon$.
- Grafik: $x$'i $\Delta x$ artır, işaret değişince $\Delta x$'i yarıya indir, aralığın solundan tekrar başla.
- İkiye bölme: $c = \frac{a + b}{2}$.
- Regula falsi: $c = \frac{a f(b) - b f(a)}{f(b) - f(a)}$.
- Newton-Raphson: $x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)}$.
- Sekant: $x_{k+1} = x_k - \frac{f(x_k)(x_{k-1} - x_k)}{f(x_{k-1}) - f(x_k)}$.
- Kapalı yöntemler: aralık ve işaret kontrolü gerekir, yakınsar ama yavaştır. Açık yöntemler: bir/iki başlangıç değeri, hızlıdır ama ıraksayabilir.
- Maksimum hacim: $V = (6 - 2x)^2 x$, $V' = 0$ için $3x^2 - 12x + 9 = 0$, $x = 1$, $V_{max} = 16$.

## Detaylı Açıklamalar

### Yöntemlerin karşılaştırması

- Grafik yöntemi en basit yöntemdir ama elle çözerken çok uzun sürer. Hız $\Delta x$ seçimine ve başlangıç noktasına bağlıdır.
- İkiye bölme her adımda aralığı kesin olarak yarıya indirir. Bu yüzden kaç adımda biteceği önceden hesaplanabilir. Ancak fonksiyon değerlerini kullanmadığı için yavaştır.
- Regula falsi fonksiyon değerlerini kullanır. Çoğu zaman ikiye bölmeden daha hızlı yakınsar.
- Newton-Raphson köke yakın başlandığında çok hızlı yakınsar. Türev gerektirir.
- Sekant türev gerektirmez. Newton-Raphson'dan biraz daha yavaş ama genellikle kapalı yöntemlerden hızlıdır.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile yeniden hesaplandı. Grafik yöntemi, regula falsi, Newton-Raphson ve sekant değerleri slaytlardakiyle aynıdır. Sekant örneğinde $x_1$'den $x_9$'a kadar bütün değerler slayttakiyle aynı çıktı.
- **Grafik yönteminde $f(1.5)$:** Derste $f(1.5) = 1.75$ söylendi. Doğrusu $1.5^2 - 6 \cdot 1.5 + 5 = -1.75$'tir. Benzer şekilde $f(4.5) = -1.75$ ve $f(4.875) = -0.484$'tür. İşaret değişimi $4.5$ ile $5.25$ arasında, $f(5.25) = 1.0625$'te olur.
- **Grafik yönteminde diğer kök:** $x_0 = 1.5$, köklerden biri olan 1'in sağındadır. Sağa doğru tarama yapıldığı için yöntem 1'i hiç görmez ve 5'i bulur. 1 kökünü bulmak için 1'den küçük bir başlangıç değeri seçilmelidir.
- **İkiye bölmede iterasyon sayısı:** Derste durma kontrolü karışık yapıldı. Ölçüt $\frac{b_0 - a_0}{2^n} \le \varepsilon$ ise başlangıç aralığı $[0, 1]$ ve $\varepsilon = 0.01$ için $\frac{1}{2^n} \le 0.01$, yani $n \ge 7$ gerekir ($\frac{1}{128} = 0.0078$). Doğru adımlar:

  | $n$ | $c$ | $f(c)$ | $\frac{1}{2^n}$ |
  |---|---|---|---|
  | 1 | 0.5 | −0.625 | 0.5 |
  | 2 | 0.75 | 0.9844 | 0.25 |
  | 3 | 0.625 | 0.2598 | 0.125 |
  | 4 | 0.5625 | −0.1619 | 0.0625 |
  | 5 | 0.59375 | 0.0540 | 0.03125 |
  | 6 | 0.578125 | −0.0526 | 0.0156 |
  | 7 | 0.5859375 | 0.0010 | 0.0078 |

  7. iterasyonda durulur, kök yaklaşık 0.586'dır. Bu fonksiyon $(x - 3)(x^2 - 4x + 2)$ olarak çarpanlarına ayrılır. $[0, 1]$ aralığındaki gerçek kök $2 - \sqrt{2} \approx 0.585786$'dır.
- **Regula falsi'de durma ölçütü:** Slaytta regula falsi için de $\frac{b - a}{2^n} \le \varepsilon$ kullanıldı. Bu ölçüt ikiye bölmeye özgüdür. Regula falsi'de aralık her adımda yarıya inmez. Bu örnekte $b = 3$ hep sabit kaldı. Bu yöntemde ardışık iki $c$ değerinin farkına bakmak daha doğrudur: $|c_k - c_{k-1}| \le \varepsilon$. Bu ölçütle $c_3 = 2.6873$ ve $c_4 = 2.6901$ arasındaki fark 0.0028'dir, 4. adımda durulur. Ayrıca slaytın 4. adımında "0.019542 < 0.01" yazıyor. Bu eşitsizlik yanlıştır, hoca da derste "hatamdan küçük çıkmadı" dedi. Gerçek kök 2.690647'dir, sonuç 2.69 doğrudur.
- **Regula falsi'nin hızı:** Regula falsi genellikle ikiye bölmeden hızlıdır ama her zaman değil. Fonksiyon aralıkta çok eğriyse bir uç (bu örnekte $b = 3$) hiç değişmez ve yakınsama yavaşlar.
- **Newton-Raphson örneğinin sonu:** Derste $x_2$'den sonrası hesaplanmadı. Devamı: $x_3 = 0.585592$, $x_4 = 0.5857864$, $x_5 = 0.5857864$. $|x_5 - x_4| \approx 2.9 \times 10^{-8} \le 10^{-6}$ olduğu için 5. iterasyonda durulur. Kök 0.585786'dır. İkiye bölmeyle aynı fonksiyon için yalnızca 5 adım gerekir.
- **Newton-Raphson'un ıraksadığı durumlar:** $f'(x_k) = 0$ olursa formülde sıfıra bölme olur. Teğet yataydır ve x eksenini kesmez. Türev sıfıra yakınsa yeni değer çok uzağa fırlar. Başlangıç değeri kökten uzaksa veya fonksiyon salınımlıysa yöntem ıraksayabilir. Bu durumda başlangıç değeri değiştirilir.
- **Vize sorusunda diğer kök:** Derste "$x_0 = 1.5$ verirsem diğer kökü (3) bulurum" denildi. Hesaplandığında $f(1.5) = -2.25$, $f'(1.5) = -3$, $x_1 = 0.75$ çıkar ve yöntem yine 1'e yakınsar. $f'(x) = 6x - 12$, $x = 2$'de sıfırdır. Bu yüzden 3 kökünü bulmak için başlangıç değeri 2'den büyük seçilmelidir (ör. $x_0 = 2.5$ ile 3'e yakınsar).
- **Vize sorusunda maksimum kontrolü:** Bulunan noktanın maksimum mu minimum mu olduğu ikinci türevle de anlaşılır. $V$'nin 4'e bölünmüş hâlinin ikinci türevi $6x - 12$'dir. $x = 1$'de $-6 < 0$ (maksimum), $x = 3$'te $6 > 0$ (minimum).
- **Radyan-derece:** Slayttaki "$\sin 5 \to \frac{900}{\pi}$" notu, hesap makinesi derece modundaysa 5 radyanın dereceye çevrilmesidir: $5 \cdot \frac{180}{\pi} = \frac{900}{\pi} \approx 286.48°$. Hesap makinesi radyan modundaysa doğrudan $\sin 5 = -0.9589$ hesaplanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
