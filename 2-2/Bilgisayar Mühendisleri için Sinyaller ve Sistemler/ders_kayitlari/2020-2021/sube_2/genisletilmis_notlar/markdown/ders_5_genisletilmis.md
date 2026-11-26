# Ders 5 Genişletilmiş Notu: Sistem Özellikleri, Diferansiyel Denklemle Tanımlanan Sistemler ve Soru Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sistem Kavramının Tekrarı ve Temel Sistemler
- 2. Türev Alıcı, İntegral Alıcı ve Ayrık Zamanda Türev
- 3. Öteleme ve Konvolüsyon Sistemleri
- 4. Çok Girişli Sistemler ve Bağlantı Biçimleri
- 5. Geri Beslemeli Sistemler
- 6. Doğrusallık
- 7. Bellek ve Nedensellik
- 8. Zamanla Değişmezlik
- 9. Kararlılık
- 10. Hız Sabitleyici Örneği ve Tersinir Sistemler
- 11. Diferansiyel Denklemle Tanımlanan Sistemler
- 12. Ayrık Zamanlı Sistemler
- 13. Soru Çözümü
- Örnek Sorular

## 1. Sistem Kavramının Tekrarı ve Temel Sistemler

Ders, "Systems Properties" başlıklı dördüncü slayt dizisinin kaldığı yerden devam etti. Hoca, sonraki bölümlerin (dürtü yanıtı, konvolüsyon) kaynakta çoğunlukla sürekli zaman üzerinden anlatıldığını, bilgisayar mühendisliği için önemli olan ayrık zaman tarafının ise ikinci planda kaldığını, bu yüzden ilerleyen haftalarda içerikte düzenlemeler yapılacağını söyledi. Devre teorisi bilmek analog giriş ve çıkışları anlamayı kolaylaştırır, ama dersin ön koşulu değildir.

Sistem, giriş işaretini alıp çıkış işaretine dönüştüren bir yapıdır. İşaret bir bilgi ya da veri olarak düşünülürse sistem bu veriyi dönüştüren bir "transformer"dır; matematikçi bakış açısıyla bir fonksiyondur. Derste çoğunlukla tek girişli, tek çıkışlı (Single Input Single Output, SISO) sistemler kullanılacak.

Blok diyagramında girişi bir katsayıyla çarpan sistem:

- Katsayı 1'den büyükse yükselteç (amplifier),
- 1'den küçükse zayıflatıcı/sönümlendirici (attenuator),
- negatifse tersleyici (inverter) olur. Örneğin $-5$ değerli bir işaret tersleyiciden geçince $+5$ olur. Tersleme ile yükseltme ya da zayıflatma birlikte de yapılabilir.

## 2. Türev Alıcı, İntegral Alıcı ve Ayrık Zamanda Türev

Slaytta türev alıcı $y(t) = x'(t)$, integral alıcı ise $y(t) = \int_a^t x(\tau)\,d\tau$ olarak verildi ($a$ çoğunlukla $0$ ya da $-\infty$); ikisi de $d/dt$ ve $\int$ bloklarıyla gösterilir (ekrandan, 00:20:00).

Hoca bunların sürekli zamana ait olduğunu, bilgisayar mühendisi olarak kodlamada daha çok ayrık zamanlı karşılıklarıyla karşılaşılacağını vurguladı. Ayrık zamanda türev, türevin tanımından kolayca elde edilir. Bir $x$ noktasına $h$ kadar artım verildiğinde fonksiyon değeri $f(x)$'ten $f(x+h)$'e değişir; türev bu değişimin $x$'teki değişime oranıdır:

$$\frac{f(x+h) - f(x)}{(x+h) - x}$$

Ayrık zamanda elimizde diziler vardır ve indis $n$ sınırlı adımlarla değişir; verilebilecek en küçük artım $h = 1$'dir. Payda $1$ olur ve dizinin birinci dereceden türevi (birinci fark)

$$x[n+1] - x[n]$$

olarak bulunur (ekrandan, 00:20:00). Bu bilgi verici bir işlemdir: fizikte hızdaki değişimin ivmeyi vermesi gibi, bir ses işaretinin zamana (ayrık zamanda $n$'e) göre nasıl değiştiği bu farkla incelenebilir.

Türeve "çıkarma" dersek integrale de "toplama" diyebiliriz. Sürekli zamanda integral eğrinin altında kalan alandır; ayrık zamanda elemanları toplaya toplaya gitmek, yani kümülatif toplamdır.

## 3. Öteleme ve Konvolüsyon Sistemleri

### 3.1 Zamanda Öteleme Sistemi

Bir işareti zamanda ötelemek, onu ileri ya da geri almaktır. Sisteme bu görev yüklenirse buna zamanda öteleme (time shifting) sistemi denir; $T$ gibi bir parametreyle belli bir gecikme ya da öne alma yapılır ve yeni bir işaret üretilir. İleride doğrusal sistemler konuşulurken toplamsallık özelliği zamanda ötelemeye göre de test edilecek.

### 3.2 Konvolüsyon Sisteminin Sezgisi

Hoca konvolüsyonu "bir anlamda korelasyon" diye tanıttı: iki veri arasında doğru ya da ters orantılı bir ilişki, bir benzerlik olup olmadığını bulmaya yarar. Büyük bir işaret (örneğin bir yüz fotoğrafı) ve onun içinde aranan küçük bir işaret (örneğin göz) vardır. Aranan küçük işarete kullanılan alana göre "mother function", "filtre" ya da "kernel" (çekirdek) denir.

Küçük işaret büyük işaretin başından sonuna kaydırılır; her konumda iki işaret çarpılıp toplanır (integral alınır). Benzerliğin az olduğu yerlerde sonuç küçük çıkar, benzer bir bölgeye gelince sonuç tepe (pik) yapar ve sonra yeniden azalır. Bu tepelerin zaman değerlerinden büyük işaretin neresinde aranan işarete benzeyen bir şey olduğu anlaşılır; bu yüzde yüz eşleşme anlamına gelmez. Hoca bu konuyla ilgili ileride çok şey duyulacağını ve buna daha çok $h$ adının verildiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Konvolüsyon ile korelasyon yakın işlemlerdir ama aynı değildir: konvolüsyonda kaydırılan işaret önce zamanda ters çevrilir ($h(t-\tau)$), korelasyonda ters çevrilmez. Simetrik bir çekirdek için ikisi aynı sonucu verir. LTI sistemlerde $h$, sistemin dürtü yanıtıdır.

## 4. Çok Girişli Sistemler ve Bağlantı Biçimleri

Girişleri $x_1(t)$, $x_2(t)$ ve çıkışı $y(t)$ olan sistemler (ekrandan, 00:25:00):

- Toplayıcı (summing system): $y(t) = x_1(t) + x_2(t)$
- Fark sistemi (difference system): $y(t) = x_1(t) - x_2(t)$
- Çarpıcı (multiplier system): $y(t) = x_1(t)\,x_2(t)$

Sistemler, bileşke fonksiyonlarda olduğu gibi birbirine kaskat (seri) ya da paralel bağlanabilir. Hoca bunu devre elemanlarına benzetti: seri bağlı iki direnç doğrudan toplanır, seri bağlı iki kapasitörde ise $\frac{1}{C_{\text{eş}}} = \frac{1}{C_1} + \frac{1}{C_2}$ kullanılır; yani bağlantının sonucu elemanların davranışına göre belirlenir. Kaskat bağlantı tek bir bileşke fonksiyon olarak yazılabilir ve çarpıma benzer; paralel bağlantı ise $f(x) + g(x)$ gibi toplamaya benzer.

## 5. Geri Beslemeli Sistemler

### 5.1 Geri Beslemenin Anlamı

Slayttaki geri beslemeli yapı $y = F(x - Gy)$ şeklindedir: çıkış $y$, $G$ bloğundan geçirilip toplama noktasında girişten çıkarılır ve sonuç $F$ bloğuna girer (ekrandan, 00:30:00). Slayttaki genel notlara göre blok diyagramları sistem bağlantılarını göstermenin sembolik bir yoludur; aynı bilgi işaretler arasındaki denklemlerle de yazılabilir ve iki gösterim arasında gidip gelinebilir.

Sistemden elde edilen çıktının beklenen çıktıyla ne kadar uyumlu olduğu sisteme geri yansıtılmak isteniyorsa geri besleme kullanılır. Hoca bunu sayısal analiz dersinde görülen regresyon ve interpolasyona benzetti: elde 100 (ya da 1000) veri vardır, bunlarla bir eğri uydurulur; her adımda oluşan hata sisteme geri yansıtılır. Sistem hatalarından arındıkça yeni bir veri geldiğinde onun beklenen (tahmin edilen) karşılığı bulunabilir. Hava durumu tahmininde de parametrelerle denklemler kurulur, hangi parametrelerde ne olduğu bilinir, hatası en aza indirilmiş sistem yarının havasını tahmin eder. Derin öğrenme ve bilgisayarla görme alanındaki çalışmalar da özünde geri besleme yapar.

### 5.2 Başarım Ölçütleri

Eğitilen bir sistemin kullanılabilir olup olmadığına ölçütlerle karar verilir. Hoca slayta accuracy, precision ve recall yazarak bunları bir hastalık tespiti örneğiyle açıkladı (ekrandan, 00:30:00):

- **Accuracy:** gerçek değer ile tahmin edilen değerin ne kadar eşleştiği. Örneğin 300 hastanın 300'ü hasta, 200 sağlam kişinin 200'ü sağlam bulunduysa eşleşme tamdır.
- **Recall:** gerçekte hasta olanların kaçının hasta olarak işaretlendiği. 300 gerçek hastadan 250'si bulunduysa recall $250/300$'dür.
- **Precision:** hasta olarak işaretlenenlerin kaçının gerçekten hasta olduğu; yani boş yere ilaç verilip verilmediği.

Hoca bu konunun derin öğrenmeye kadar uzanan kökünün sistem özellikleri olduğunu belirtti.

### 5.3 Geri Beslemeli İntegral Alıcı

Slayttaki örnekte (ekrandan, 00:35:00) integral alıcının girişi $x - ay$'dir; çıkış $a$ katsayılı bloktan geçirilip girişten çıkarılır. Buradan

$$\int^{t} \big(x(\tau) - a\,y(\tau)\big)\,d\tau = y(t)$$

yazılır. Slayttaki ikinci yol: integral alıcının girişi çıkışının türevidir, dolayısıyla

$$x - ay = y'.$$

Hoca bunu günlük hayattan bir benzetmeyle açıkladı: insanın ulaşmak istediği bir hedef (bir fonksiyonun ulaşması gereken değer) vardır. Girdilere karşılık çıktılar hemen istenen değeri vermez; sapmalar, yani hatalar olur. İntegral alıcı o ana kadarki verileri toplayarak bir "tecrübe birikimi" oluşturur, geri besleme ise hatayı çıkarır. Hatalardan ders çıkarıp aynı hataları tekrarlamayınca çıkış istenen değere yaklaşır; hoca tahtaya hedef değer etrafında salınıp ona yerleşen bir eğri çizdi (ekrandan, 00:35:00). Yapay sinir ağlarındaki geri yayılım (backpropagation) algoritması da hatanın geri yayılmasıyla ağ parametrelerinin hataya katkısını en aza indirerek sistemi eğitir; aynı mantık oradadır.

Bu sistemin denklemi diferansiyel denklem olarak çözülüp $y = f(t)$ biçiminde yazılırsa sistemin davranışını veren denklem bulunmuş olur.

## 6. Doğrusallık

### 6.1 Tanım

Slayttaki tanıma göre bir $F$ sistemi şu iki özelliği sağlıyorsa doğrusaldır (ekrandan, 00:40:00):

1. **Homojenlik (çarpımsallık):** $x$ herhangi bir işaret ve $a$ herhangi bir skaler ise $F(ax) = aF(x)$.
2. **Süperpozisyon (toplamsallık):** $x$ ve $\tilde{x}$ herhangi iki işaret ise $F(x + \tilde{x}) = F(x) + F(\tilde{x})$.

Sözle: sistemden önce ya da sonra ölçeklemek aynı sonucu verir; sistemden önce ya da sonra toplamak aynı sonucu verir. Blok diyagramıyla: girişi $a$ ile çarpıp sisteme vermek, girişi sisteme verip çıkışı $a$ ile çarpmakla aynı olmalıdır; iki işareti toplayıp sisteme vermek, ayrı ayrı verip çıkışları toplamakla aynı olmalıdır. Hoca çarpımsallığı işaretlerdeki ölçeklemeye, toplamayı da bir bakıma ötelemeye benzetti.

### 6.2 Homojenlik Örneği

Hoca tahtada iki sistemi karşılaştırdı (ekrandan, 00:40:00):

- $F(x) = x$: $F(ax) = ax$ ve $aF(x) = ax$ eşittir; sistem homojendir.
- $F(x) = (x+2)^2$: $F(ax) = (ax+2)^2 = a^2x^2 + 4ax + 4$, $aF(x) = a(x^2 + 4x + 4)$. $a^2$ teriminin karşılığı olmadığından $a \neq 1$ için eşitlik bozulur; sistem homojen değildir. ($a = 1$ iken eşitlik her zaman sağlanır, bu yüzden test $a$ herhangi bir sayı alınarak yapılır.)

Hoca ayrıca $2x + 5$ örneğini verdi ve bunun matematikte ve kriptolojide "afin" diye adlandırıldığını, $x$ yerine $ax$ ya da $x + k$ yazılınca farklı sonuçlar çıktığını söyledi.

> **Ders sonrası not:** Hoca $2x + 5$ için önce "lineerdir" dedi. Sistem özelliği açısından $y = 2x + 5$ doğrusal değildir: $F(ax) = 2ax + 5 \neq a(2x+5)$. Afin bir sistemdir; $b = 0$ olmadıkça homojenlik sağlanmaz.

### 6.3 Doğrusal ve Doğrusal Olmayan Sistem Örnekleri

Slayttaki listeye göre doğrusal sistemler: ölçekleme, türev alıcı, integral alıcı, kayan ortalama (running average), zamanda öteleme, konvolüsyon, modülatör ve örnekleyici. Kayan ortalama, işaretten 3, 4 ya da 5 elemanlık küçük parçalar alıp ortalamasını alarak ve pencereyi sona doğru kaydırarak işareti yumuşatır.

Doğrusal olmayan sistemler: işaret (sign) dedektörü, çarpma sistemleri, karşılaştırıcılar (comparator), nicemleyiciler (quantizer), uyarlamalı (adaptive) filtreler ve kare alma sistemi.

Modülatör $y(t) = x(t)\cos 2\pi f t$ doğrusaldır: $x(t)$ toplamsallık ve çarpımsallık testlerine sokulursa $y(t)$ iki şartı da sağlar.

## 7. Bellek ve Nedensellik

Slayttaki tanımlar (ekrandan, 00:45:00):

- **Belleksiz (memoryless) sistem:** çıkış yalnız o anki girişe bağlıdır. Örnekler: ideal yükselteç, mekanik sistemde ideal dişli, aktarma organı ya da kaldıraç.
- **Bellekli sistem:** çıkış geçmişteki ya da gelecekteki girişlere bağlıdır. Örnekler: enerji depolayan devre elemanları (kapasitör, bobin), mekanik sistemlerde yaylar ve hareketli kütleler.
- **Nedensel (causal) sistem:** çıkış yalnız geçmiş ya da şimdiki girişlere bağlıdır. Her gerçek fiziksel devre ya da mekanik sistem nedenseldir.

Geleceğe bağlı sistemler daha çok idealdir; pratikte çoğunlukla geçmişe bağlı sistemlerle çalışılır. Hoca $a_n = a_{n-5} + a_{n-3}$ gibi bir bağıntıyı ve Fibonacci sayılarının özyineleme bağıntısını (ayrık matematikte görülecek) örnek verdi: şu anki değer önceki değerlerden hesaplandığı için bu sistemler bellekli ve nedenseldir; $n-3$ ve $n-5$'teki değerlerdeki bir değişiklik $n$'deki değeri etkiler. Geri beslemeyle eğitilen tahmin sistemleri de geleceği şimdiki ve geçmiş durumlardan tahmin ettiği için nedenseldir.

> **Ders sonrası not:** Hoca nedensel sistemi "bellekli sistemin bir alt kümesi" diye anlattı. Doğrusu, belleksiz sistemler de (yalnız şimdiki girişe bağlı oldukları için) nedenseldir; bellek ve nedensellik ayrı özelliklerdir. Bellekli ama nedensel olmayan sistemler de vardır (geleceğe bağlı olanlar).

## 8. Zamanla Değişmezlik

Zamanda belli bir öteleme yapıldığında sistem aynı sonucu (ötelenmiş olarak) veriyorsa sisteme zamanla değişmez (time invariant) denir. Örneğin bir işaret belli bir noktada belli bir değer veriyorsa, 5 birim ötelenince aynı değeri 5 birim sonra vermelidir.

Test: $y(t) = F\{x(t)\}$ sisteminde girişe $t$ yerine $t - t_0$ yazılır; elde edilen çıkış $y(t - t_0)$'a eşitse sistem zamanla değişmezdir. Başka bir ifadeyle, girişe verilen bir gecikme ile, girişi geciktirmeden aynı gecikmenin çıkışa uygulanması aynı sonucu veriyorsa sistem zamanla değişmezdir (girişte gecikme ile sistemin sırası değiştirilebilir). Hoca zamanla değişmezliğin ileride çok kullanılacak bir özellik olduğunu söyledi.

## 9. Kararlılık

Mühendislik uygulamalarının çoğunda sistemler belli kısıtlar altında çalışır; girişler ve çıkışlar sınırlıdır. Slayttaki tanım (ekrandan, 00:50:00): sınırlı bir giriş

$$|x(t)| \le M_x < \infty$$

her zaman sınırlı bir çıkış

$$|y(t)| \le M_y < \infty$$

veriyorsa ($M_x$ ve $M_y$ sonlu pozitif sayılar) sistem sınırlı giriş sınırlı çıkış (Bounded Input Bounded Output, BIBO) kararlıdır.

Hoca sistemleri büyük bir evrensel küme olarak düşünüp alt kümelere ayırdı: doğrusal/doğrusal olmayan, zamanla değişen/değişmeyen vb. Bu derste daha çok doğrusallık ve zamanla değişmezlik özelliklerinin kesişimindeki sistemler (LTI sistemler) incelenecek.

## 10. Hız Sabitleyici Örneği ve Tersinir Sistemler

### 10.1 Hız Sabitleyici (Cruise Control)

İstenen hız $x$, gerçek hız $y$ olsun. Hata $x - y$ hesaplanır ve bir $K$ katsayısıyla çarpılarak $H$ sistemine (araca) giriş olarak verilir. Hata girişe "tersi yönünde" yansır: hızlı gidiliyorsa yavaşlamak, yavaş gidiliyorsa hızlanmak gerekir. Pozitif hata gazı artırır; gecikmeyle hız değişir ve hedefi aşma (overshoot) olur; sonra gaz kesilir, yine gecikmeyle hız değişir ve hedefin altında kalma (undershoot) olur. Bu adımlar tekrarlanarak sistem istenen hıza yerleşir; bu, geri beslemeli integral alıcıda çizilen salınımlı yaklaşma eğrisine benzer.

### 10.2 Tersinir Sistemler

Bir sistemin çıkışı, sistemin tersine verildiğinde giriş yeniden elde edilebiliyorsa sistem tersinirdir (invertible); sistemle tersinin bileşkesi birim (identity) operatörünü verir. Hoca bunun özellikle dönüşümlerde (Laplace, Fourier) önemli olduğunu belirtti: bir dönüşümden orijinal veri tekrar elde edilemiyorsa dönüşüm pek anlam ifade etmez.

## 11. Diferansiyel Denklemle Tanımlanan Sistemler

### 11.1 LCCODE

Sistem türev ve integral operatörleri içeren bir denklemle tanımlanıyorsa diferansiyel denklemle tanımlanan sistemdir. Diferansiyel denklemin içinde türevler, fonksiyonun kendisi ve giriş bulunur; amaç $y$'yi bulmaktır. Hoca tahtaya $y' = y'' + 2y + x$ gibi bir örnek yazdı (ekrandan, 00:55:00). Diferansiyel denklemler sabit katsayılı/değişken katsayılı, homojen/homojen olmayan gibi sınıflara ayrılır; bu derste doğrusal sabit katsayılı adi diferansiyel denklemlerle (linear constant coefficient ordinary differential equation, LCCODE) ilgilenilir (ekrandan, 00:55:00):

$$a_n y^{(n)}(t) + \dots + a_1 y'(t) + a_0 y(t) = b_m x^{(m)}(t) + \dots + b_1 x'(t) + b_0 x(t)$$

Başlangıç koşulları $y^{(n-1)}(0), \dots, y'(0), y(0)$ verilir; bunlar $x(t)$ verildiğinde $y(t)$'yi belirler. $n$ sistemin mertebesi, $b_0, \dots, b_m, a_0, \dots, a_n$ sistemin katsayılarıdır. Katsayılar sabittir; örneğin $a_n$ yerine $n$'e bağlı bir ifade olsaydı denklem sabit katsayılı olmazdı. Hoca bütün başlangıç koşulları sıfırsa bu tür denklemlerin doğrusal bir sistem tanımladığını belirtti.

> **Hocanın vurgusu:** Bu derste diferansiyel denklem çözmeye çok girilmeyecek; bunları daha kısa yoldan çözmek için Laplace dönüşümü kullanılacak.

### 11.2 Denklemin Mertebesi Nereden Gelir?

Hoca öğrencilere, bir sistemi modellerken ikinci ya da üçüncü mertebe türevin neye göre yazılması gerektiğini sordu. Cevabı bir önceki derste bir öğrencinin yazdığı $x = vt$ ilişkisi üzerinden verdi (ekrandan, 01:00:00): konumun (alınan yolun) zamana göre değişimi hızı, hızın değişimi ivmeyi, ivmenin değişimi sarsıntıyı (jerk) verir. Konumdan yola çıkılıp sarsıntıya kadar gidilecekse üçüncü mertebe türev, hızdan yola çıkılıp sarsıntıya gidilecekse ikinci mertebe türev gerekir. Yani problem en fazla kaçıncı mertebeden değişimi gerektiriyorsa diferansiyel denklem o mertebede kurulur. (Hoca "derece" yerine "mertebe" demenin doğru olduğunu ayrıca belirtti.)

### 11.3 Basit Örnekler

Slayttaki örnekler (ekrandan, 01:00:00):

| Sistem | Katsayılar | Denklem |
|---|---|---|
| Ölçekleme | $a_0 = 1,\ b_0 = a$ | $y = ax$ |
| İntegral alıcı | $a_1 = 1,\ b_0 = 1$ | $y' = x$ |
| Türev alıcı | $a_0 = 1,\ b_1 = 1$ | $y = x'$ |
| Geri beslemeli integral alıcı | $a_1 = 1,\ a_0 = a,\ b_0 = 1$ | $y' + ay = x$ |

İntegral alıcı için hoca $y' = x$ denklemini $\frac{dy}{dx} = x$ gibi yazıp iki tarafın integralini alarak $y = \frac{x^2}{2} + C$ biçiminde bir çözüm gösterdi; $C$ başlangıç koşulundan bulunur.

> **Ders sonrası not:** Slayttaki $y' = x$ ifadesinde türev zamana göredir: $y(t) = \int x(\tau)\,d\tau$. Hocanın $y = x^2/2 + C$ sonucu, giriş $x(t) = t$ alınırsa $y(t) = t^2/2 + C$ olarak okunmalıdır (büyük olasılıkla hoca $x$'i bağımsız değişken gibi kullandı).

Hoca öğrencilere $y'' + y' + y$ gibi denklemleri daha önce görüp görmediklerini sordu; öğrenciler kalkülüste görmediklerini söyledi. Hoca bu yüzden derste bu tür denklemlerin çözümüyle fazla uğraştırılmayacağını belirtti. Ayrıca $y_n$, $y_{n+1}$, $y_{n-1}$, $y_{n-2}$ gibi önceki çıktılara bakan geri beslemeli sistemlerin ikinci, üçüncü mertebe denklemlere yol açtığını söyledi.

### 11.4 RLC Devresi

Slayttaki ikinci mertebe devre örneği (ekrandan, 01:05:00): kaynak $x(t)$, seri bağlı $L$, $R$ ve $C$; çıkış $y(t)$ kapasitör gerilimidir, akım $i$'dir.

- Kirchhoff gerilim yasası: $x - Li' - Ri - y = 0$
- $i = Cy'$ konunca: $x - LCy'' - RCy' - y = 0$
- Ya da: $LCy'' + RCy' + y = x$

Bu bir LCCODE'dur ve sistem doğrusaldır; katsayılar zamana bağlı değil, sabittir. Denklem çözülürse örneğin $L = 5$, $R = 2$, $C = 3$ gibi değerler için $t = 10$ anındaki akım ya da gerilim bulunabilir; sistemle ilgili bütün parametreler bu çözümden çıkar.

Hoca dersin amacının mühendislere sistemlerin analizini ve tasarımını öğretmek olduğunu söyledi. Analizde verilen devre çözülür. Sentezde (elektronikte devre sentezi) "şu özellikleri sağlayan devreyi yap" denir; önce analiz mantığıyla denklem kurulur, sonra istenen davranışa uygun parametreler belirlenerek sistem tasarlanır.

### 11.5 Mekanik Sistem (Kütle-Yay-Sönümleyici)

Slayttaki mekanik örnek (ekrandan, 01:10:00): $m$ kütlesi, $k$ sabitli bir yay ve $b$ katsayılı bir sönümleyiciyle tabana bağlıdır.

- $x(t)$ tabanın, $y(t)$ kütlenin yer değiştirmesidir.
- Yay kuvveti $k(x-y)$, sönüm kuvveti $b(x-y)'$.
- Newton denklemi: $my'' = b(x-y)' + k(x-y)$.
- İkinci mertebe LCCODE olarak: $my'' + by' + ky = bx' + kx$.

Bu model bir arabanın süspansiyon sistemine ya da deprem sırasında bir binanın davranışına uygulanabilir.

Hoca ayrıca Newton'un soğuma yasasını örnek verdi: bir cismin sıcaklığı bir anda (örneğin $t = 5$'te) $40\,^\circ$C, bir süre sonra $35\,^\circ$C ölçülürse, kurulan sistem denklemiyle cismin normal vücut sıcaklığında olduğu an, yani tahmini ölüm zamanı geriye doğru hesaplanabilir (adli tıp uygulaması). Lise ve üniversite sınavlarındaki havuz ve işçi problemlerinde de aslında sistem denklemi kurulur; ancak orada hızlar (örneğin musluk için 5 birim) sabit kabul edilir. Gerçekte hız zamana göre değişebilir (4.8, 5.0, 5.2 gibi); bu değişkenliği hesaba katmak diferansiyel denklemlerin devreye girdiği yerdir.

> **Ders sonrası not:** Hoca normal vücut sıcaklığı için "47 derece" dedi; doğrusu yaklaşık $37\,^\circ$C'dir (büyük olasılıkla dil sürçmesi ya da Whisper hatası). Ayrıca Newton'un soğuma yasası birinci mertebe bir diferansiyel denklemdir: $\frac{dT}{dt} = -k(T - T_{ortam})$.

## 12. Ayrık Zamanlı Sistemler

Sistemde kullanılan giriş ve çıkışlar sürekli zamanlıysa sistem sürekli zamanlı, ayrık zamanda elde edilmiş verilerse ayrık zamanlı sistemdir. Ayrık zamanlı sistemler de ölçekleme, gecikme gibi aynı özellikleri sağlar; $t$'ler gider, yerine köşeli parantez içinde $n$ gelir. $x[n]$ girişler, $y[n]$ çıkışlardır. Şu anki durum ile bir önceki durum arasındaki fark, diferansiyelin ayrık karşılığını (fark denklemini) verir.

> **Hocanın vurgusu:** Mühendis için önemli olan olayların gidişatından yola çıkıp arkadaki mantığı anlayarak sistemin denklemini kurabilmektir. Denklem kurulduktan sonra katsayılar, mertebeler ve girişler verilince MATLAB ya da Python denklemi zaten çözer; ilerleyen haftalarda MATLAB ile diferansiyel denklem çözümü gösterilecek.

Slayttaki ayrık zamanlı sistem örneği (ekrandan, 01:15:00): giriş $x[n]$, çıkış $a$ katsayısıyla ölçeklenip girişten çıkarılır, sonuç $T$ kadar geciktiren bir bloktan geçer.

- Gecikme bloğunun girişi: $e[n] = x[n] - a\,y[n]$
- Çıkış: $y[n] = e[n-1]$
- Dolayısıyla: $y[n] = x[n-1] - a\,y[n-1]$

Gecikme 1 alındığında şu anki çıkış, girişin ve çıkışın bir önceki değerleriyle ilişkilidir. $a = 1$ alınırsa çarpanın ölçekleme etkisi olmaz; 2 ya da 3 alınırsa geri beslenen değerin etkisi artar.

## 13. Soru Çözümü

Aradan sonra hoca geçmiş yıllarda sorulmuş ve kendi önemli gördüğü bazı soruları çözdü. Örnekler İngilizce bir örnek soru dosyasından (BLM2041 Signals and Systems) gösterildi; ayrıntılar aşağıdaki "Örnek Sorular" bölümündedir. Buradaki kısa özet:

- Sürekli ve ayrık işaretlerde öteleme, ölçekleme ve ters çevirme; ayrık zamanda $x[2n]$ işleminde aradaki örneklerin kaybolması (aşağı örnekleme).
- Basamak ve dürtü fonksiyonlarıyla çarpım: işaretin bir kısmını söndüren pencereler, $\delta$ ile örnekleme.
- Enerji ve güç hesabı; enerji işaretinin sonlu enerjisi ve sıfır gücü.
- Tek ve çift bileşenler.
- Doğrusallık ve zamanla değişmezlik testleri.

Hoca enerji ve gücün yalnız sayısal özellikler olduğunu da vurguladı: ayrık bir işaret $\{1, 2, 3\}$ ise enerjisi $1^2 + 2^2 + 3^2$ toplamıdır; bu sayılar sayısal işaret işlemede ve yapay zekada özellik olarak kullanılır (iki müzikten ya da iki kişinin sesinden hangisinin daha güçlü olduğu gibi). Önemli olan sonucun sonlu mu sonsuz mu çıktığıdır.

## Örnek Sorular

### Soru 1: Sürekli zamanda işaret işlemleri (ekrandan, 01:30:00)

$x(t)$, $0 \le t \le 4$ aralığında $0$'dan $3$'e doğrusal artan, bu aralık dışında sıfır olan bir işarettir ($t = 4$'te $3$'ten $0$'a düşer). Şunları çizin: (a) $x(t-2)$, (b) $x(2t)$, (c) $x(t/2)$, (d) $x(-t)$.

**Çözüm (derste sözlü):**

- (a) $t - 2$ zamanda 2 birim sağa ötelemedir; rampa $[2, 6]$ aralığına kayar, şekil değişmez.
- (b) $2t$ zamanda sıkıştırmadır; $t = 4$'teki değer ($3$) $t = 2$'ye, $t = 2$'deki değer ($1.5$) $t = 1$'e gelir. Rampa $[0, 2]$ aralığında $0$'dan $3$'e çıkar.
- (c) $t/2$ genişletmedir; $t = 4$'teki değer $t = 8$'e gider. Rampa $[0, 8]$ aralığında $0$'dan $3$'e çıkar.
- (d) $-t$ ters çevirmedir; rampa $[-4, 0]$ aralığına gelir, $t = -4$'te $3$, $t = 0$'da $0$ olur.

Genlik hiçbirinde değişmez.

### Soru 2: Ayrık zamanda işaret işlemleri (ekrandan, 01:35:00)

$x[n]$: $x[0] = 0$, $x[1] = 1$, $x[2] = 2$, $x[3] = 3$, $x[4] = 3$, diğer $n$'lerde $0$. Şunları çizin: (a) $x[n-2]$, (b) $x[2n]$, (c) $x[-n]$, (d) $x[-n+2]$.

<!-- BELİRSİZ: Soru slaytı karede görünmüyor; dizi değerleri hocanın anlatımından ve cevap slaytındaki grafiklerden (ekrandan, 01:35:00) çıkarıldı. -->

**Çözüm (derste verildi, python ile doğrulandı):**

| İşaret | Sıfırdan farklı değerler |
|---|---|
| $x[n-2]$ | $n = 3, 4, 5, 6$ için $1, 2, 3, 3$ |
| $x[2n]$ | $n = 1, 2$ için $2, 3$ ($n = 0$'da $0$) |
| $x[-n]$ | $n = -4, -3, -2, -1$ için $3, 3, 2, 1$ |
| $x[-n+2]$ | $n = -2, -1, 0, 1$ için $3, 3, 2, 1$ |

$x[2n]$'de yalnız çift indisli örnekler alınır; $x[1]$ ve $x[3]$ kaybolur ve geri yazılmaz, çünkü $n = 0.5$ ya da $n = 1.5$ diye bir indis yoktur. Bu, veriyi yarıya indiren aşağı örneklemedir (downsampling). $x[-n+2]$ için önce ters çevrilip sonra $-n$ yönünde (sola) 2 birim kaydırılır.

### Soru 3: Basamak ve dürtüyle çarpım (ekrandan, 01:35:00 ve 01:40:00)

$x(t)$: $-1 \le t \le 0$ aralığında $0$'dan $1$'e doğrusal artar, $0 \le t < 1$ aralığında $1$, $1 \le t < 2$ aralığında $2$, diğer yerlerde $0$'dır. Şunları çizin: (a) $x(t)\,u(1-t)$, (b) $x(t)\,[u(t) - u(t-1)]$, (c) $x(t/2)\,\delta(t - 1.5)$.

**Çözüm (derste sözlü, (c) için düzeltmeli):**

- (a) $u(1-t)$, $t \le 1$ için $1$, $t > 1$ için $0$'dır ($u(-t)$'nin 1 birim sağa ötelenmişi). Çarpım $t \le 1$ kısmını aynen korur, $1 < t < 2$ aralığındaki 2 değerli kısım sıfırlanır: $[-1, 0]$ rampa, $[0, 1]$ aralığında $1$.
- (b) $u(t) - u(t-1)$, $0 \le t < 1$ aralığında $1$, diğer yerlerde $0$ olan bir penceredir: $u(t)$'nin birlerinden $u(t-1)$'in sıfırları çıkarılınca $[0,1)$ aralığında $1$ kalır, $t \ge 1$ için birlerden birler çıkarılınca $0$ kalır. Bu pencereyle çarpım yalnız $[0, 1)$ aralığını geçirir; sonuç bu aralıkta $1$ değerli dikdörtgendir. Hoca bunu cevap seçeneklerinden B ile eşleştirdi.
- (c) Önce $x(t/2)$ çizilir: işaret iki kat genişler; rampa $[-2, 0]$, $[0, 2)$ aralığında $1$, $[2, 4)$ aralığında $2$ olur (ekrandan, 01:40:00). $\delta(t - 1.5)$ yalnız $t = 1.5$'te sıfırdan farklıdır; çarpım $x(t/2)$'nin o noktadaki değerini ağırlık olarak alan tek bir dürtü verir.

> **Ders sonrası not:** Hoca önce sonucu genliği 1 olan dürtü olarak buldu, sonra "1.5 zamanı 3'e denk gelir" diyerek 2'ye düzeltti. Doğrusu: $x(t/2)$'nin $t = 1.5$'teki değeri $x(0.75) = 1$'dir (genişletilmiş işarette $1.5$, $[0, 2)$ aralığındadır). Sonuç $x(t/2)\,\delta(t-1.5) = \delta(t - 1.5)$, yani hocanın ilk bulduğu 1 genlikli dürtüdür. Düzeltmede $1.5$ yanlışlıkla $3$'e eşlenmiştir (python ile doğrulandı).

### Soru 4: Üstel azalan işaretin enerjisi (ekrandan, 01:45:00)

$x(t) = e^{-2t}u(t)$ işaretinin enerjisini bulun ve enerji işareti olup olmadığını belirleyin.

<!-- BELİRSİZ: Soru slaytı karede görünmüyor; işaret cevap slaytındaki $|x(t)|^2 = (e^{-2t})^2$ ve "t < 0 için sıfır" ifadesinden çıkarıldı. -->

**Çözüm (derste verildi):** Önce kare alınır: $|x(t)|^2 = (e^{-2t})^2 = e^{-4t}$. İşaret $t < 0$ için sıfır olduğundan integralin alt sınırı $0$'a çekilir:

$$E = \int_0^\infty e^{-4t}\,dt = -\frac{1}{4}e^{-4t}\Big|_0^\infty = \left[-\frac{1}{4}e^{-4\cdot\infty} + \frac{1}{4}e^{-4\cdot 0}\right] = -\frac{1}{4}\cdot 0 + \frac{1}{4}\cdot 1 = \frac{1}{4}$$

Enerji sonludur; bu bir enerji işaretidir.

### Soru 5: Sinüzoidin bir periyottaki enerjisi ve ortalama gücü (ekrandan, 01:45:00 ve 01:50:00)

$x(t) = A\cos\omega t$, $A$ pozitif gerçel bir sabit. (a) Bir periyottaki enerjiyi, (b) ortalama gücü bulun.

**Çözüm (derste verildi):** İşaret periyodik olduğundan $-\infty$ ile $+\infty$ arasında değil, bir periyot boyunca incelemek yeter. $\omega = 2\pi f$, $f = \omega / 2\pi$, $T_0 = 1/f = 2\pi/\omega$; bir periyot $[-T_0/2, T_0/2]$ alınır. $\cos^2 x = \frac{1 + \cos 2x}{2}$ özdeşliği kullanılır (hoca bu tür özdeşliklerin soruda verileceğini söyledi):

$$E_0 = \int_{-T_0/2}^{T_0/2} |A\cos\omega t|^2\,dt = A^2\int_{-T_0/2}^{T_0/2}\frac{1+\cos 2\omega t}{2}\,dt = \frac{A^2}{2}\int_{-T_0/2}^{T_0/2}dt + \frac{A^2}{2}\int_{-T_0/2}^{T_0/2}\cos 2\omega t\,dt$$

- Birinci terim: $\frac{A^2}{2}\,t\,\Big|_{-T_0/2}^{T_0/2} = \frac{A^2}{2}T_0$.
- İkinci terim: $\int_{-T_0/2}^{T_0/2}\cos 2\omega t\,dt = \frac{1}{2\omega}\sin 2\omega t\,\Big|_{-T_0/2}^{T_0/2} = \frac{1}{2\omega}[\sin(\omega T_0) - \sin(-\omega T_0)] = \frac{\sin(\omega T_0)}{\omega} = \frac{\sin 2\pi}{\omega} = 0$.

Böylece $E_0 = \frac{A^2}{2}T_0$ ve ortalama güç

$$P = \frac{E_0}{T_0} = \frac{A^2 T_0/2}{T_0} = \frac{A^2}{2}.$$

**Soru (derste sözlü, 01:50:54):** İkinci integral neden sıfır geldi? **Cevap:** $\omega T_0 = 2\pi$ olduğundan $\sin(2\pi) = 0$'dır.

### Soru 6: $e^{-|t|}$ işaretinin enerjisi ve gücü (ekrandan, 01:55:00)

$x(t) = e^{-|t|}$ işaretinin enerji ve güç bileşenlerini bulun.

<!-- BELİRSİZ: Soru slaytı karede görünmüyor; işaret cevap slaytındaki $|x(t)|^2 = e^{-2|t|}$ ifadesinden çıkarıldı. Enerji hesabının yapıldığı cevap slaytı karede yok; sonuç altyazıdan ve python kontrolünden. -->

**Çözüm (derste verildi):** $|x(t)|^2 = e^{-2|t|}$; işaret $t < 0$ için $e^{2t}$, $t > 0$ için $e^{-2t}$ gibi davrandığından integral iki parçaya bölünür:

$$E = \int_{-\infty}^{0} e^{2t}\,dt + \int_0^\infty e^{-2t}\,dt = \frac{1}{2} + \frac{1}{2} = 1.$$

Enerji sonlu olduğundan enerji işaretidir. Ortalama güç için (ekrandan, 01:55:00):

$$\frac{1}{T}\int_{-T/2}^{T/2} e^{-2|t|}\,dt = \frac{2}{T}\int_0^{T/2} e^{-2t}\,dt = \frac{1}{T}\left(1 - e^{-T}\right)$$

$$P = \lim_{T\to\infty}\frac{1}{T}\left(1 - e^{-T}\right) = \lim_{T\to\infty}\frac{1}{T} - \lim_{T\to\infty}\frac{e^{-T}}{T} = 0$$

İlk terim sıfıra gider; ikinci terimde $T \to \infty$ iken $e^{-T} \to 0$ olduğundan o da sıfıra gider. Enerji işareti için beklendiği gibi $P = 0$'dır. Hoca $e^{-\infty}/\infty$ gibi limitlerde L'Hôpital kuralı kullanılabileceğini, gerekli formüllerin soruda verileceğini söyledi.

### Soru 7: Tek ve çift bileşenler (ekrandan, 01:55:00)

$x(t) = 2\cos t - \sin t + 3\sin t\cos t$ işaretinin çift ve tek bileşenlerini bulun. Hatırlatma: $x_e(t) = \frac{x(t) + x(-t)}{2}$, $x_o(t) = \frac{x(t) - x(-t)}{2}$.

**Çözüm (derste verildi, python ile doğrulandı):** $x(-t) = 2\cos t + \sin t - 3\sin t\cos t$.

- $x_e(t) = \frac{x(t) + x(-t)}{2} = \frac{4\cos t}{2} = 2\cos t$
- $x_o(t) = \frac{x(t) - x(-t)}{2} = -\sin t + 3\sin t\cos t$

Sonuç gözle de görülebilir: kosinüs çift, sinüs tek bir işarettir; $\sin t\cos t$ çarpımında kosinüs olsa da sinüs çarpımı tek yapar.

### Soru 8: $y[n] = 8x^2[n-2]$ doğrusal mı? (ekrandan, 02:00:00)

**Çözüm (derste verildi):** Çarpımsallık testi: $x$ yerine $ax$ yazılırsa $F\{ax\} = 8a^2x^2[n-2]$; $aF\{x\} = a\cdot 8x^2[n-2]$. $a^2$ terimi yüzünden $a \neq 1$ için eşit değildir; sistem doğrusal değildir.

### Soru 9: $y[n] = n^3 x[n+1]$ doğrusal mı? (ekrandan, 02:05:00)

**Çözüm (derste verildi):** Toplamsallık ve çarpımsallık birlikte test edilir: $x[n]$ yerine $a x_1[n] + b x_2[n]$ yazılır ve sonucun $aF\{x_1[n]\} + bF\{x_2[n]\}$'ye eşit olup olmadığına bakılır:

$$F\{a x_1 + b x_2\} = n^3\big(a x_1[n+1] + b x_2[n+1]\big) = a\,n^3 x_1[n+1] + b\,n^3 x_2[n+1] = aF\{x_1\} + bF\{x_2\}$$

İki taraf terim terim eşittir; sistem doğrusaldır.

**Soru (derste sözlü):** Bu örnekte neden $x_1$ ve $x_2$ ayrı alındı? **Cevap:** Toplamsallık için iki ayrı işaret seçmek gerekir; $a$ ve $b$ katsayıları da çarpımsallığı test eder. Böylece iki özellik aynı anda gösterilmiş olur. İstenirse yukarıdaki örnekte olduğu gibi ayrı ayrı da test edilebilir.

### Soru 10: $y[n] = 4n\,x[n]$ zamanla değişmez mi? (ekrandan, 02:10:00)

**Çözüm (derste verildi):** Zamanla değişmezlik için $F\{x[n-k]\} = y[n-k]$ olmalıdır.

- Girişi ötelemek: $x[n]$ yerine $x[n-k]$ yazılırsa $F\{x[n-k]\} = 4n\,x[n-k]$.
- Çıkışı ötelemek: $y[n-k] = 4(n-k)\,x[n-k]$.

$k \neq 0$ için (örneğin $k = 1$) iki ifade eşit değildir; sistem zamanla değişir (time variant).

### Soru 11: $y[n] = x[n] + 2x[n-1]$ zamanla değişmez mi? (ekrandan, 02:15:00)

**Çözüm (derste verildi):**

- $F\{x[n-k]\} = x[n-k] + 2x[n-1-k]$
- $y[n-k] = x[n-k] + 2x[n-k-1]$

İki ifade eşittir; sistem zamanla değişmezdir (time invariant). Fonksiyonlara benzer şekilde: çıkışta yapılan öteleme, girişe verilen değişkende yapılan ötelemeyle aynı sonucu veriyorsa sistem zamanla değişmezdir.

### Soru 12: Ayrık sinüzoidin parametreleri (ekrandan, 02:20:00)

(a) $a = \left\{\frac{1}{\sqrt{2}},\ 1,\ \frac{1}{\sqrt{2}},\ 0,\ -\frac{1}{\sqrt{2}},\ -1,\ -\frac{1}{\sqrt{2}},\ 0\right\}$ dizisi ($n = 0$'dan başlayarak) $A\cos(\Omega_0 n + \varphi)$ biçimindedir. $A$, $\Omega_0$ ve $\varphi$'yi bulun.

(b) $b = \{-3,\ 0,\ 3,\ 0\}$ ($n = 0, 1, 2, 3$) için $A$, $\Omega_0$ ve $\varphi$'yi bulun.

<!-- BELİRSİZ: Karede (a) dizisinin son elemanı tam okunmuyor; hoca sözlü olarak 8 değer saydı ve son elemanı 0 olarak okudu. -->

> **Çözüm (derste verilmedi):** (a) $n = 1$'de en büyük değer $1$ olduğundan $A = 1$ ve $\Omega_0 + \varphi = 0$; $n = 0$'da $\cos\varphi = 1/\sqrt{2}$. Değerler her adımda $\pi/4$ ilerleyen bir kosinüse uyar: $A = 1$, $\Omega_0 = \pi/4$, $\varphi = -\pi/4$. Kontrol: $\cos(\pi n/4 - \pi/4)$, $n = 0..7$ için $0.707, 1, 0.707, 0, -0.707, -1, -0.707, 0$ verir. (b) Değerler 4 adımda bir tekrar eder ve en büyük mutlak değer 3'tür: $A = 3$, $\Omega_0 = \pi/2$, $\varphi = \pi$; $3\cos(\pi n/2 + \pi)$, $n = 0..3$ için $-3, 0, 3, 0$ verir (python ile doğrulandı). $\Omega_0$ yerine $2\pi$'nin katları eklenmiş ya da işareti değiştirilmiş eşdeğer çözümler de vardır.

### Soru 13: Sistem özellikleri (ekrandan, 02:20:00)

Aşağıdaki sistemlerin nedensel, kararlı, doğrusal ve zamanla değişmez olup olmadığını belirleyin: (a) $y[n] = a\,x[n] + b$, (b) $y[n] = x[n] - x[n-2]$.

<!-- BELİRSİZ: (b) şıkkında iki terim arasındaki işaret karede kalın bir lekeyle yazılmış (eksi ya da çarpma olabilir); gecikme altyazıda "n-1", karede "n-2" (üzerine yazılmış). Çözüm, karede okunan n-2 ve eksi işaretiyle verildi. -->

> **Çözüm (derste verilmedi):** (a) Çıkış yalnız $x[n]$'e bağlı olduğundan belleksiz ve nedenseldir; sınırlı giriş için $|y| \le |a|M_x + |b|$ sınırlı olduğundan kararlıdır; katsayılar $n$'e bağlı olmadığından zamanla değişmezdir; $b \neq 0$ ise $F\{0\} = b \neq 0$ olduğundan doğrusal değildir (afin). (b) $y[n] = x[n] - x[n-2]$: yalnız şimdiki ve geçmiş girişlere bağlı olduğundan nedenseldir (bellekli); $|y| \le 2M_x$ olduğundan kararlıdır; doğrusaldır; zamanla değişmezdir. İşaret çarpma ise ($y[n] = x[n]\,x[n-2]$) sistem nedensel, kararlı ve zamanla değişmez kalır, ama doğrusal olmaz.

### Soru 14: $f(x) = 2x + 3$ (derste sözlü, 02:21:50)

Hoca kapanışta $f(x) = 2x + 3$ sisteminin doğrusal olup olmadığını ve zamanla değişip değişmediğini kendi başınıza düşünmenizi istedi.

> **Çözüm (derste verilmedi):** $f(ax) = 2ax + 3 \neq a(2x+3)$ olduğundan doğrusal değildir (afin). Katsayılar zamana bağlı olmadığından $y[n] = 2x[n] + 3$ biçiminde düşünülürse zamanla değişmezdir.

## Dersin Toparlaması

Bu derste sistemlerin temel özellikleri tamamlandı. Türev ve integral alıcıların ayrık zamandaki karşılıkları (fark ve kümülatif toplam), toplayıcı/fark/çarpıcı sistemler, kaskat ve paralel bağlantı, geri besleme ve geri beslemeli integral alıcı görüldü. Ardından doğrusallık (homojenlik ve süperpozisyon), bellek, nedensellik, zamanla değişmezlik, BIBO kararlılık ve tersinirlik tanımlandı; dersin asıl ilgileneceği sınıfın doğrusal ve zamanla değişmeyen (LTI) sistemler olduğu belirtildi. Doğrusal sabit katsayılı adi diferansiyel denklemlerle tanımlanan sistemler RLC devresi ve kütle-yay-sönümleyici örnekleriyle, ayrık zamanlı karşılıkları da gecikmeli geri besleme örneğiyle gösterildi.

Soru çözümü bölümünde işaret dönüşümleri, basamak ve dürtüyle çarpım, enerji ve güç, tek/çift bileşenler ile doğrusallık ve zamanla değişmezlik testleri çalışıldı. Hoca ileride diferansiyel denklemlerin elle çözümü yerine Laplace dönüşümünün kullanılacağını ve MATLAB ile diferansiyel denklem çözümünün gösterileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
