# Ders 3 Genişletilmiş Notu: Açık Yöntemler (Newton-Raphson, Sekant, Tekrarlama), Fonksiyonların Bilgisayarda Gösterimi ve Matris İşlemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kapalı Yöntemlerden Açık Yöntemlere
- 2. Newton-Raphson Yöntemi
- 3. Sekant (Kiriş) Yöntemi
- 4. Tekrarlama (Sabit Nokta) Yöntemi
- 5. Fonksiyonların Bilgisayarda Gösterimi
- 6. Doğrusal Denklem Takımlarına Giriş: Matrisler
- 7. Elementer Satır İşlemleri ve Ters Matris
- 8. Gauss-Jordan Eliminasyonu ile Ters Matris
- Örnek Sorular
- Dersin Toparlaması

## 1. Kapalı Yöntemlerden Açık Yöntemlere

Önceki derste doğrusal olmayan eşitliklerin çözümüne başlanmış, yöntemler kapalı ve açık diye ikiye ayrılmıştı. Kapalı yöntemlerden üç algoritma görülmüştü. Hoca bunlardan son ikisinin (ikiye bölme ve regula falsi) birbirine çok benzediğini hatırlattı: ikiye bölmede aralık doğrudan orta noktadan bölünür, regula falsi ise $(a, f(a))$ ve $(b, f(b))$ noktalarından geçen doğruyu kullandığı için hedefe daha hızlı yaklaşır. Bu algoritmalar tarihsel olarak birbirinin eksiklerini kapatacak şekilde geliştirilmiştir.

Kapalı yöntemlerde iki nokta arasında çalışılır: önce $a$ ile $b$ arasında bir kökün varlığı doğrulanır. Bunun bedeli, gerçek köke ulaşmanın çok uzayabilmesi ve algoritmanın geç yanıt vermesidir. Açık yöntemler gerçek köke daha hızlı yaklaşabilen yöntemlerdir. Derste üç örneği işlendi: Newton-Raphson, onun türev gerektirmeyen bir biçimi olan sekant yöntemi ve biraz farklı bir mantıkla çalışan tekrarlama (fixed point) yöntemi (ekrandan, 00:30:00).

Açık aralık metodunda bir noktadan başlanır ve başka bir noktayı referans almadan ilerlenir: $x_i$ noktasından $x_{i+1}$ noktasına geçilir. Bu geçişte bir iyileşme oluyorsa çözüme yaklaşıyoruz demektir. Çözümden uzaklaşma olasılığı da vardır; uzaklaşıyorsak yanlış bir şey yapıyoruz demektir ve yöntemi ya da başlangıcı değiştirmek gerekir. Bu kontrolü kolaylaştırmak için yine bir $[a,b]$ aralığı verilebilir: $a$'dan başlanıp değerler $b$'ye doğru ilerliyorsa iş yolunda, $b$'den uzaklaşıyorsa bir şeyler ters gidiyor demektir. Hoca bu iki durumu yakınsama (convergence) ve ıraksama (divergence) diye adlandırdı.

## 2. Newton-Raphson Yöntemi

### 2.1 Yöntemin özellikleri

Slaytta yöntemin özellikleri şöyle sıralandı (ekrandan, 00:10:00):

- Lineer olmayan ve analitik çözümü olmayan bir bilinmeyenli denklemlerin (gerçek) köklerini bulmada kullanılır.
- Açık aralık metodudur.
- Yine $[a,b]$ aralığı verilir, ama kökü bulma sırasında hesaplanan değerler bu aralığın dışına çıkabilir.
- Bazen sonuçlar ıraksayabilir; ancak yakınsadığı zaman kökü en hızlı bulan yöntemdir.
- Köke türev ile yaklaşım mantığını kullanır.
- İşleme bir başlangıç değeri ile başlanır. Başlangıç değeri verilmezse en doğrusu küçük olan aralık değerinden başlamaktır.

Hoca, yöntemin kullanışlı ve kolay olduğunu, tek sıkıntısının türev olduğunu söyledi. Elimizde bir $f(x)$ fonksiyonu vardır ve bunun türevini de almak gerekir. Fonksiyon üstel, sinüzoidal, logaritmik fonksiyonların iç içe girdiği karmaşık bir yapıdaysa, sembolik (analitik) türev almak zorlaşır. Bu zorluğun çözümü ikinci yöntem olan sekantta görülecektir.

Durma için bir hata değeri belirlenir. Bulunan kök belirli bir noktadan sonra çok fazla değişmez: $|x_{i+1} - x_i|$ belirli bir $\varepsilon$ değerinin altına inince algoritma durdurulabilir. Fark büyüyorsa bazı şeyleri gözden geçirmek gerekir.

### 2.2 Geometrik fikir: teğetle yaklaşmak

Regula falsi iki noktası bilinen doğru denklemiyle, ikiye bölme ise orta noktayla ilerliyordu. Newton-Raphson'da ise fonksiyonun bir noktadaki türevi, yani o noktadan çizilen teğet kullanılır. Şekilde $P_0 = (x_0, f(x_0))$ noktasından çizilen teğet $x$ eksenini $x_1$'de keser; $P_1 = (x_1, f(x_1))$ noktasından çizilen yeni teğet $x_2$'yi verir ve böylece köke hızla yaklaşılır (ekrandan, 00:15:00). Ardışık adımlar arasındaki değişim gittikçe azalır.

Hoca, yöntemin diğer yöntemlere göre çoğu durumda daha hızlı olduğunun, kodları yazılıp süreleri ölçülerek istatistiksel olarak gösterildiğini anlattı. Uygulama örneği olarak $\sqrt{7}$'nin yaklaşık değerini verdi: $x = \sqrt{7}$ ise $x^2 = 7$, yani $x^2 - 7 = 0$ denkleminin kökü aranır. Bu yöntem kodlandığında yaklaşık değer diğer yöntemlere göre çok daha hızlı bulunur.

### 2.3 Formülün türetilmesi (teğet doğrusu ile)

Bir noktası ve eğimi bilinen doğru denklemi $y - y_0 = m(x - x_0)$'dır. Burada iki nokta olmadığı için eğim mecburen türevden gelir: $m = f'(x_0)$. Noktamız $(x_0, f(x_0))$ olduğundan

$$y - f(x_0) = f'(x_0)\,(x - x_0).$$

Teğetin $x$ eksenini kestiği $x_1$ noktasında $y = 0$'dır. Bunu yerine koyup bilinenleri bir tarafa toplarsak

$$x_1 = x_0 - \frac{f(x_0)}{f'(x_0)}$$

bulunur. Genelleştirildiğinde

$$x_{i+1} = x_i - \frac{f(x_i)}{f'(x_i)}$$

olur ve $x_i$ ile $x_{i+1}$ belirli bir değere oturana kadar devam edilir.

Durma koşulu olarak, yöntemi test etmek için gerçek kök biliniyorsa gerçek köke yakınlığa bakılabilir; gerçek kök yoksa ardışık köklerin değişimine bakılır.

Ardından slaytta $[0,1]$ aralığında kökü olduğu bilinen bir fonksiyonla örnek gösterildi. Başlangıç verilmediği için $x_0 = 0$ alındı; fonksiyonda $0$ yerine konunca $-6$, türevde $14$ geldi ve $x_1 = 6/14 = 3/7 \approx 0{,}43$ bulundu. Fark henüz $\varepsilon$'u geçmediği için iterasyona devam edildi. <!-- BELİRSİZ: bu örneğin fonksiyonu ve sonraki ara değerleri incelenen karelerde görünmüyor; altyazıda "0.42", "0.056", "0.56" gibi değerler geçiyor -->

Hoca iterasyonlar arasındaki farkın normalde gittikçe azaldığını tahtada bir grafikle gösterdi. Algoritmayı çalıştırırken fark gittikçe artıyorsa kökten uzaklaşılıyor demektir; bu bir dezavantajdır ve algoritmayı hemen durdurmak gerekir.

**Soru:** Uzaklaşma, fonksiyonun artan ya da azalan olmasından mı kaynaklanır? **Cevap:** Hayır, fonksiyonun artan-azalanlığıyla ilgili değildir; fonksiyonlar çok daha karmaşık olabilir. Başlangıç noktasında öyle bir teğet çizilmiş olabilir ki bizi köke değil, $x_0$'ın ötesine götürür; sonraki teğetler de daha kötü noktalara götürür. Bu genelde başlangıç noktasının yanlış seçilmesinden kaynaklanır.

### 2.4 Kutu (konteyner) problemi

Slayttaki soru (ekrandan, 00:20:00): Kenar uzunluğu $a = 6$ olan bir karenin dört köşesinden $x$ uzunluğunda kareler kesilerek üstü açık bir kutu yapılıyor. Kutunun hacmini maksimum yapan $x$ Newton-Raphson ile bulunacak; başlangıç değeri 0, kabul edilebilir hata $0{,}001$.

Kenarlardan $x$ kesildiği için tabanın kenarı $6 - 2x$, yükseklik $x$ olur. Hacim (ekrandan, 00:25:00):

$$V = (6-2x)^2 x = (36 - 24x + 4x^2)x = 4x^3 - 24x^2 + 36x.$$

Slaytta ifade 4'e bölünerek $V = f(x) = x^3 - 6x^2 + 9x$ olarak alındı. Bir sistemin minimum ve maksimum noktalarını bulmak için türev alınıp sıfıra eşitlenir:

$$V' = 3x^2 - 12x + 9 \;\Rightarrow\; x^2 - 4x + 3 = 0.$$

> **Hocanın vurgusu:** Kökü aranacak ifade hacmin kendisi değil, türevidir. Newton-Raphson bu ifadeye uygulanacağı için onun da türevi alınır.

Newton-Raphson için $f(x) = x^2 - 4x + 3$ ve $f'(x) = 2x - 4$ kullanılır. Kökler $(x-3)(x-1)$'den 1 ve 3'tür. $x = 3$ hacmi sıfır yaptığı için çözüm 1'e yakınsamalıdır. Ekrandaki tablo (ekrandan, 00:25:00):

| $x_k$ | $x_{k+1}$ |
|---|---|
| 0 | $0 - 3/(-4) = 0{,}75$ |
| 0,75 | $0{,}75 - (0{,}5625 / -2{,}5) = 0{,}975$ |
| 0,975 | $0{,}975 - (0{,}050625 / -2{,}05) = 0{,}9996$ |
| 0,9996 | $0{,}9996 - (9{,}903\cdot10^{-4} / -2{,}00008) = 1{,}000095$ |

Birkaç iterasyon sonra değerin 1'e oturduğu görülür; $x = 1$ birimdir. Hacim $V = (6-2)^2 \cdot 1 = 16$ birim küptür.

> **Ders sonrası not:** Tablonun son satırı tutarsız. Python ile kontrolde $f(0{,}9996) \approx 8{,}0\cdot10^{-4}$ ve $f'(0{,}9996) = -2{,}0008$ çıkıyor; sonuç $\approx 1{,}0000006$ olur. Yuvarlamasız zincirde $x_3 = 0{,}999695$, $x_4 \approx 0{,}99999995$'tir. Kök 1 olduğu için cevap değişmez.

> **Ders sonrası not:** Slayttaki $V = x^3 - 6x^2 + 9x$ gerçek hacmin 4'te biridir. Maksimumun yeri ($x = 1$) değişmez, ama hacim değeri asıl formülden ($16$) hesaplanmalıdır.

Bir öğrenciye cevap verirken hoca, aynı problemin örneğin regula falsi ile çözülmesinin de istenebileceğini, soruda hangi yöntemin ve hangi değerlerin kullanılacağının özellikle belirtileceğini söyledi. <!-- BELİRSİZ: öğrencinin sorusu kayıtta duyulmuyor -->

### 2.5 Taylor serisinden türetme

Hoca formülün Taylor serisinden de türetilebileceğini gösterdi. Amaç $f(x) = 0$ yapan değeri bulmaktır. $x_1 = x_0 + h$ alınırsa

$$f(x_0 + h) = f(x_0) + f'(x_0)\,h + \frac{f''(x_0)}{2!}h^2 + \dots$$

Küçük değerler oldukları için ilk iki terim dışındakiler ihmal edilir ve $f(x_0+h) = 0$ yazılır: $f(x_0) + f'(x_0)h = 0$, buradan $h = -f(x_0)/f'(x_0)$ ve yine $x_1 = x_0 - f(x_0)/f'(x_0)$ bulunur. Genel hâlde $x_{k+1} = x_k - f(x_k)/f'(x_k)$. Hoca asıl ispatın teğet doğrusu üzerinden yapılan ispat olduğunu, Taylor yolunun da aynı sonuca götürdüğünü söyledi.

Yöntem çok kullanışlıdır; birçok programlama dilinin kütüphanesinde görülür. Örneğin Java'daki karekök (`sqrt`) fonksiyonunun iç yapısına bakıldığında Newton-Raphson görülebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Kütüphanelerin karekök gerçeklemeleri büyük olasılıkla donanım komutu ya da başka yaklaşımlar da kullanır; Newton-Raphson ise $\sqrt{c}$ için $x_{k+1} = \tfrac12\left(x_k + c/x_k\right)$ biçimini alan klasik bir yöntemdir. Bu formül, $f(x) = x^2 - c$ için Newton-Raphson formülünün sadeleşmiş hâlidir.

## 3. Sekant (Kiriş) Yöntemi

### 3.1 Fikir

Newton-Raphson'da her şey güzeldir, ama fonksiyon çok zorsa türevi daha da zor olabilir: toplamın, çarpımın, trigonometrik, parametrik ve üstel fonksiyonların türev kuralları iç içe geçtikçe çözüm güçleşir. Sekant yönteminde türev farklı düşünülür.

$x_0$ biliniyorsa $f(x_0)$ hesaplanabilir. Teğet çizmek yerine, $x_0$'a çok yakın ikinci bir nokta seçilir; örneğin $x_0 = 1$ ise $x_1 = 1{,}3$ (tahtada, ekrandan, 00:30:00). $f(x_1)$ de hesaplanır ve $(x_0, f(x_0))$ ile $(x_1, f(x_1))$ noktalarından geçen doğru çizilir. Bu doğru uzatıldığında $x$ eksenini kestiği yer bir sonraki kök adayı $x_2$'dir.

Hoca derste öğrencilere bu doğrunun nasıl çizileceğini sordu; cevap iki noktası bilinen doğru denklemidir:

$$\frac{y - y_1}{y_1 - y_0} = \frac{x - x_1}{x_1 - x_0}.$$

$x_2$ noktasında $y = 0$ olduğu için $y$ yerine 0 konur, $x$ yerine aranan $x_2$ gelir. Geri kalan her şey bilinen değerlerdir; bilinenler bir tarafa toplanınca $x_2$ bulunur. Böylece türev almanın maliyetinden kaçılmış olur.

### 3.2 Formül

Genel hâlde $x_{k-1}$ ve $x_k$ noktalarından yeni nokta (ekrandan, 00:35:00):

$$x_{k+1} = x_k - \frac{f(x_k)\,\left[x_{k-1} - x_k\right]}{f(x_{k-1}) - f(x_k)}.$$

Hoca bu formülün Newton-Raphson formülüne benzediğini, türevin yerini iki nokta arasındaki eğimin aldığını gösterdi. Formülü ezberlemeye gerek olmadığını, iki noktası bilinen doğru denkleminden çıkarılabileceğini söyledi.

Bir sonraki adımda yeni bir başlangıç noktası seçmeye gerek yoktur: elimizde $x_{-1}$, $x_0$, $x_1$ vardır. Bu kez $x_{-1}$ ile $x_0$ arasında değil, $x_0$ ile $x_1$ arasında doğru çizilir ve $x_2$ bulunur; sonra $x_1$ ile $x_2$'den $x_3$, $x_2$ ile $x_3$'ten $x_4$ bulunur.

### 3.3 Sayısal örnek

Örnekte $x_{-1} = 10$ ve $x_0 = 5$ alındı; $(10, f(10))$ ve $(5, f(5))$ noktalarından geçen doğrudan $x_1 = 4{,}93$ bulundu. Fonksiyon sinüs içerdiği için, hesap makinesinde sinüs hesaplanırken birime dikkat etmek gerektiği söylendi: $\pi$ radyan $180^\circ$ olduğundan 5 radyan $5 \cdot 180/\pi$ derecedir. <!-- BELİRSİZ: örneğin fonksiyonu incelenen karelerde görünmüyor ve altyazıdan çıkarılamıyor -->

Ekrandaki ikinci iterasyon (ekrandan, 00:35:00):

$$x_2 = x_1 - \frac{f(x_1)\,[x_0 - x_1]}{f(x_0) - f(x_1)} = 4{,}931924 - \frac{f(4{,}93\ldots)\,[5 - 4{,}93\ldots]}{f(5) - f(4{,}93\ldots)} = 3{,}813366.$$

Sonraki değerler: $x_3 = 3{,}234929$, $x_4 = 2{,}754669$, $x_5 = 2{,}578048$, $x_6 = 2{,}544745$, $x_7 = 2{,}543023$, $x_8 = 2{,}543009$, $x_9 = 2{,}543009$. Kök $\approx 2{,}543009$ olarak belli bir değere oturur. Hoca, Desmos ile çizildiğinde de kökün yaklaşık 2,54 civarında görüleceğini söyledi.

### 3.4 Adım ($h$) ile verilen biçim

Sorularda bazen $x_{k-1}$ yerine bir $h$ adımı verilir: $x_{k-1} = x_k - h$ (ya da $+h$). Bu iki nokta arasındaki değere bakılır, sonra $h$ küçültülerek (örneğin $h/2$) ilerlenir. Hoca bunu ikiye bölme ile Newton-Raphson'un bir tür melezi gibi düşünülebileceğini söyledi.

### 3.5 Neden programlanabilir bir yöntem?

Newton-Raphson kodlanırken türevin bilgisayarda sembolik olarak gösterilmesi gerekir. Örneğin $f(x) = 3x^2$ ise $f'(x) = 6x$'tir; kolay fonksiyonlarda bu gösterilebilir, zor fonksiyonlarda zordur. Bu yüzden arka planda ya sekant yöntemi kullanılır ya da ileride görülecek sayısal türev kullanılır; bir fonksiyonun sayısal türevi çok küçük bir hatayla hesaplanabilir.

## 4. Tekrarlama (Sabit Nokta) Yöntemi

### 4.1 Fikir

Bu yöntem de doğrusal olmayan, analitik çözümü olmayan denklemlerin köklerini bulmada kullanılır. $f(x) = 0$ denklemi $x = g(x)$ biçimine getirilir (ekrandan, 00:40:00):

$$f(x) = 0,\qquad x = g(x),\qquad f(x) = x - g(x) = 0.$$

Denklemde hiçbir şey değişmez; yalnız arama $g(x)$ üzerinden yapılır. Bu fikir, iki denklemin ortak çözümünün kesişim noktası olmasına dayanır: $f(x) = 0$ yapan nokta, $y = g(x)$ ile $y = x$ doğrusunun kesiştiği noktadır (ekrandan, 00:40:00). Newton-Raphson'a benzer olarak

$$x_k = g(x_{k-1})$$

iterasyonu yapılır. Çözüme yaklaşma da uzaklaşma da mümkündür. Aynı $f(x)$'ten birden fazla $g(x)$ çıkarılabilir; bunların bazıları yakınsar, bazıları ıraksar. Durma kriterleri diğer yöntemlerdeki gibidir. Iraksamayı kontrol etmek için bir $[a,b]$ aralığı verilerek yöntem bir kapalı aralık yaklaşımıyla birleştirilebilir.

Örnek: $\sin x + x + 1 = 0$ için $x$ yalnız bırakılırsa $x = -\sin x - 1$, yani $g(x) = -\sin x - 1$ olur (ekrandan, 00:40:00). Hoca, $\sin x = -x + 1$ gibi bir biçimde $x$'i yalnız bırakmak için arksinüs almanın da bir yol olduğunu, ama yakınsamaya dikkat etmek gerektiğini söyledi.

### 4.2 Grafiksel yorum

Hoca bir web sayfasındaki animasyonla yöntemi gösterdi: $x_0$'da $g(x_0)$ bulunur, bu değer $y = x$ doğrusu üzerinden yeni $x$'e taşınır ve iki eğrinin kesişimine doğru yaklaşılır. Örnekte $x = \cos x$ denkleminin çözümü yaklaşık 0,73'e yaklaşıyordu. Başlangıç noktası kötü seçilirse merdiven ya da örümcek ağı biçiminde kesişimden uzaklaşan bir yol da oluşabilir. Gösterilen başka bir örnekte $x^2 - 1$'in kökü için iki farklı $g(x)$ kullanılmış; birinde yakınsama, diğerinde sonsuza giden ıraksama görülüyordu. <!-- BELİRSİZ: web örneğindeki g(x) ifadeleri altyazıdan net çıkmıyor -->

> **Ek bilgi (derste anlatılmadı):** $x = \cos x$ denkleminin kökü büyük olasılıkla $0{,}739085\ldots$'tir (Dottie sayısı olarak bilinir); derste söylenen "0,73 civarı" bununla uyumludur.

### 4.3 $x^2 - 9x - 10 = 0$ için farklı $g(x)$'ler

Ekrandaki ilk iki aday (ekrandan, 00:45:00):

- $x^2 = 9x + 10 \Rightarrow x = (9x + 10)^{1/2}$.
- $x^2 - 10 = 9x \Rightarrow x = (x^2 - 10)/9$.

İlkinde $x_0 = 0$'dan başlanırsa $x_1 = \sqrt{10}$, $x_2 = \sqrt{9\sqrt{10} + 10}$ olur ve böyle devam edilir. İkincisinde $0$'dan başlanınca $x_1 = -10/9$ bulunur, sonra bu değer yerine yazılır. Hoca üçüncü bir aday daha türetti: $x$ parantezine alınırsa $x(x - 9) - 10 = 0$, yani $x(x-9) = 10$ ve her iki taraf $x - 9$'a bölünürse

$$g(x) = \frac{10}{x - 9}.$$

Burada da $0$'dan başlanınca önce $-10/9$ bulunur.

Python ile kontrol (ara adım eklendi): $\sqrt{9x+10}$ ile $3{,}162;\ 6{,}202;\ 8{,}113;\ 9{,}111;\ \dots$ diye 10'a, $(x^2-10)/9$ ile $-1{,}111;\ -0{,}974;\ -1{,}006;\ \dots$ diye $-1$'e, $10/(x-9)$ ile $-1{,}111;\ -0{,}989;\ -1{,}001;\ \dots$ diye $-1$'e yakınsar.

> **Ders sonrası not:** Hoca bu denklemin köklerini "eksi 10 ve artı 1" diye söyledi. $x^2 - 9x - 10 = (x - 10)(x + 1)$ olduğu için doğru kökler $10$ ve $-1$'dir; yukarıdaki iterasyonlar da bu değerlere gider.

### 4.4 Uygunluk (yakınsama) testi

Hoca, tekrarlama yöntemi için önerilen bir kontrolü anlattı; bunun her zaman çalışmadığını, istisnaları olduğunu da belirtti:

- Açık aralık yöntemi olsa da kökün varlığını test etmek için kapalı aralık gibi düşünülür: $[a,b]$ aralığında kök olmalıdır, yani $f(a)f(b) < 0$.
- $f(x)$ ve $g(x)$ bu aralıkta türevlenebilir olmalıdır.
- $|g'(a)| < 1$ ve $|g'(b)| < 1$ olmalıdır.

Bu şartlar sağlanırsa o $g(x)$ kullanılabilir; sağlanmazsa yeni bir $g(x)$ aranır ve aynı kontroller onun için yapılır. Hoca bunu, aralıktaki değişimlerin $0$ ile $1$ arasında kalması gerektiği, bu aralığa sığılabiliyorsa yakınsama olacağı diye özetledi.

> **Ek bilgi (derste anlatılmadı):** Bu testin dayandığı genel koşul büyük olasılıkla şudur: $g$, $[a,b]$'yi kendi içine götürüyorsa ve aralığın tamamında $|g'(x)| \le L < 1$ ise sabit nokta tektir ve iterasyon her başlangıç noktasından yakınsar. Yalnız uç noktalarda bakmak bu koşulun pratik bir kısaltmasıdır.

### 4.5 Örnek: $\sin x + x - 1 = 0$, $[0,1]$

Ekrandaki soru: $\sin x + x - 1 = 0$ denkleminin $[0,1]$ aralığındaki yaklaşık kökünü bulunuz (ekrandan, 00:50:00). Çözüm adımları:

- 1. adım: $x = g(x)$ elde edilmeli. $x = -\sin x + 1$, yani $g(x) = -\sin x + 1$.
- 2. adım: $x = -\sin x + 1$ tekrarlama metodu için uygun mu? $f(0) = -1$, $f(1) = 0{,}84\ldots$, $f(0)f(1) < 0$; kök vardır. $f(x)$ ve $g(x)$ $[0,1]$'de türevlenebilir (sonsuz defa türevlenebilir).
- Türev testi: $g'(x) = -\cos x$. $|g'(0)| = 1$, yani "$1 < 1$" sağlanmaz. $|g'(1)| \approx 0{,}54 < 1$ sağlanır.

Sıfırdaki şart sağlanmadığı için başlangıç değeri olarak 0 seçmek uygun olmadı; hoca 0 yerine 1'den başlanabileceğini söyledi. $x_0 = 1$ alınınca $x_1 = g(1)$, $x_2 = g(x_1)$, … hesaplanır ve değerler belli bir sayıya oturarak köke ulaşır. Hoca sınavda bu kadar karmaşık sorular sormadıklarını da ekledi.

Python ile kontrol (ara adım eklendi): $x_0 = 1$'den $0{,}1585;\ 0{,}8421;\ 0{,}2539;\ 0{,}7488;\ \dots$ diye salınarak ve yavaşça yakınsar; kök $\approx 0{,}510973$'tür.

Ekranda bu örnek için yöntemin 4. adımı ve durma koşulları da yazılıydı (ekrandan, 00:55:00): $x_{i+1} = g(x_i)$, yani $x_1 = g(x_0)$, $x_2 = g(x_1)$, $x_3 = g(x_2)$, … ve "kökü $10^{-3}$'ten az hata ile bulmak isteyelim".

### 4.6 Durma koşulları

Ekrandaki üç durum (ekrandan, 00:55:00):

- 1. durum: $N$ iterasyon yapılır ve $x_N$ kök kabul edilir. Çok iyi değildir ama yine yaklaşılabilir.
- 2. durum: $p$ gerçek kök ise $|p - x_{i+1}| <$ tolerans olunca durulur. Hoca bunun gerçekçi olmadığını, gerçek kök biliniyorsa zaten aranmayacağını söyleyerek bu durumu tahtada çizdi.
- 3. durum: gerçek kök verilmemişse $|x_{i+1} - x_i| < \text{TOL}$ olunca durulur. Tolerans $\varepsilon$ ile gösterilir.

### 4.7 Örnek: $x^5 + x - 3 = 0$

Hoca bir örnekte daha birden fazla $g(x)$ çıkarılabileceğini gösterdi. $x = 3 - x^5$ yazılabilir; $x^5 = 3 - x$ yazılıp beşinci dereceden kök alınabilir; ya da $x(x^4 + 1) - 3 = 0$'dan her iki taraf $x^4 + 1$'e bölünerek $x = 3/(x^4+1)$ elde edilebilir. Önce aralıkta kök olup olmadığına bakıldı: $f(1)$ ve $f(3)$'ten biri pozitif, biri negatif olduğu için kök vardır. Sonra adaylar test edilip biri seçildi ve 1'den başlanarak değerin oturduğu görüldü. <!-- BELİRSİZ: denklemin tam biçimi ve hangi g(x)'in seçildiği karelerde görünmüyor; f(x) = x^5 + x - 3 altyazıdaki "x(x^4+1) - 3 = 0" ifadesinden kuruldu -->

Python ile kontrol (ara adım eklendi): $f(1) = -1$, $f(3) = 243$. $g(x) = (3-x)^{1/5}$ ile $1 \to 1{,}1487 \to 1{,}1311 \to 1{,}1332 \to \dots \to 1{,}1330$ yakınsar; $g(x) = 3/(x^4+1)$ ile $1 \to 1{,}5 \to 0{,}495 \to 2{,}830 \to \dots$ salınır ve yakınsamaz.

**Soru:** Kökü bilmiyorum; köke yeterince yaklaştığımı nasıl anlayacağım? **Cevap:** $(i+1)$'inci iterasyonda bulunan kök ile $i$'inci iterasyondaki kökün farkının mutlak değerine bakılır. Köklerin değişimi azala azala gider; fark her iterasyonda azalıyor ve belli bir $\varepsilon$ seviyesine geliyorsa orada durulur.

### 4.8 Örnek: $x^2 - 2x - 3 = 0$, $x_0 = 4$

Ekrandaki soru: $f(x) = x^2 - 2x - 3$ fonksiyonunun köklerini $x_0 = 4$ başlangıç noktası ve $0{,}005$ hata ile bulunuz (ekrandan, 01:00:00). Gerçek kökler $3$ ve $-1$'dir; 4'ten başlanınca muhtemelen 3'e gelinmesi beklenir. Üç farklı $g(x)$ türetildi (ekrandan, 01:20:00):

- $x^2 = 2x + 3 \Rightarrow g(x) = (2x+3)^{1/2}$
- $x(x-2) = 3 \Rightarrow g(x) = 3/(x-2)$
- $2x = x^2 - 3 \Rightarrow g(x) = (x^2-3)/2$

Birinci $g(x)$ için tablo:

| $x_i$ | $g(x_i)$ | $\lvert x_{i+1} - x_i\rvert$ |
|---|---|---|
| 4 | 3,316 | 0,684 |
| 3,316 | 3,104 | 0,212 |
| 3,104 | 3,034 | 0,07 |
| 3,034 | 3,011 | 0,023 |
| 3,011 | 3,004 | 0,007 |
| 3,004 | 3,001 | 0,003 |

Fark azaldığı için doğru yolda olunduğu görülür. $0{,}003 <$ hata olduğundan durulur ve $x_{\text{kök}} = 3{,}001$ alınır. Python ile kontrol edildi, değerler tutuyor.

İkinci $g(x) = 3/(x-2)$ için tablo:

| $x_i$ | $g(x_i)$ | $\lvert x_{i+1} - x_i\rvert$ |
|---|---|---|
| 4 | 1,5 | 2,5 |
| 1,5 | -6 | 7,5 |
| -6 | -0,375 | 5,625 |
| -0,375 | -1,29032 | 0,91532 |
| -1,29032 | -0,91176 | 0,37856 |
| -0,91176 | -1,03030 | 0,11854 |
| -1,03030 | -0,98999 | 0,04031 |
| -0,98999 | -1,00335 | 0,0133 |
| -1,00335 | -0,99888 | 0,00446 |
| -0,99888 | -1,00037 | 0,00149 |

Hoca farkın önce arttığını (2,5'ten 7,5'e), sonra azalarak yakınsamaya geçtiğini ve bu $g(x)$ ile diğer kök olan $-1$'e ulaşıldığını vurguladı.

> **Ders sonrası not:** Tablonun dördüncü satırında $g(-0{,}375) = 3/(-2{,}375) = -1{,}26316$ olmalıdır, slaytta $-1{,}29032$ yazıyor. Sonraki satırlar bu hatalı değerden tutarlı biçimde hesaplanmış; doğru zincir de $-1$'e yakınsar ($-1{,}26316;\ -0{,}91935;\ -1{,}02762;\ -0{,}99088;\ -1{,}00305;\ -0{,}99898;\ -1{,}00034$).

Üçüncü $g(x) = (x^2-3)/2$ ile $4 \to 6{,}5 \to 19{,}625 \to \dots$ diye ciddi bir ıraksama vardır. Hoca bunu grafikle açıkladı: fonksiyonun kendisi bir paraboldür, bu $g(x)$ de bir paraboldür; iki parabolün ortak çözümü bu şekilde aranınca sürekli uzaklaşılır ve kök bulunamaz. Bu durum türev testiyle de görülebilir: $g'(x) = x$ olduğundan $|g'(4)| = 4 > 1$'dir.

Hoca alıştırma için karmaşık fonksiyonlar yazıp Desmos'ta çizmeyi, bu yöntemi ya da diğer yöntemleri uygulayıp sonuçları karşılaştırmayı önerdi.

## 5. Fonksiyonların Bilgisayarda Gösterimi

### 5.1 Polinomun diziyle gösterimi

Bu kısım dersin projesine hazırlıktı: kök bulma yöntemlerinin bazıları kodlanacaktır. Polinom (ekrandan, 01:25:00)

$$P(x) = a_0x^n + a_1x^{n-1} + a_2x^{n-2} + \dots + a_nx^0$$

biçimindedir. Kuvvetler tam sayı, katsayılar gerçek sayı olabilir. $P(x)$ hesaplanırken kullanıcıdan $x$ alınır, kuvvetler hesaplanır ve katsayılarla çarpılır. Önemli olan katsayılardır. Dereceler tam sayı olduğu için dizi indisi gibi düşünülebilir: 20 terim varsa 20 elemanlı bir dizi açılır, derece 19'a kadar gider. Katsayılar ondalıklı olduğu için `double array[20];` yazılır; örneğin `array[3]` derecesi 3 olan terimin katsayısıdır ve ona $0{,}8$ gibi bir değer atanır (ekrandan, 01:30:00).

Hoca bilgisayar mühendisi olarak gerçek hayattaki bir nesnenin (polinom, insan ya da başka bir şey) bilgisayardaki değişkenler cinsinden modellenmesinin önemli olduğunu vurguladı.

### 5.2 Dizinin dezavantajı ve alternatifler

Hoca bir öğrenciden bütün terimleri olmayan bir polinom istedi; $x^4 + 6x^2$ yazıldı. Derecesi 4 olduğu için 5 elemanlı yer açılır, ama $x^3$, $x^1$ ve $x^0$ terimleri yoktur. Bu yerlere katsayı olarak 0 girilebilir (etkisi olmaz), ama gereksiz yer işgal edilir.

Alternatif olarak iki sütunlu bir matris kullanılabilir: bir sütun katsayı, diğeri kuvvet. $x^4 + 6x^2$ için satırlar $(1, 4)$ ve $(6, 2)$ olur (ekrandan, 01:30:00).

**Soru:** Bunun öncekinden farkı ne? **Cevap:** 20. dereceden $6x^{20} - x^{19}$ polinomu dizide 21 yer ister; matris yaklaşımında iki terim için $2 \times 2 = 4$ değer yeterlidir (ekrandan, 01:35:00). **Soru:** Matriste de boyut belirtmek gerekmiyor mu? Dizide de iki terimlik yer açamaz mıyız? **Cevap:** Matrisin boyutu dereceye göre değil terim sayısına göre belirlenir. Dizide ise yalnız katsayılar saklanır; derecenin 20 olduğunu indisle söylemek gerektiği için 21 uzunluk gerekir.

Matris yaklaşımının da sorunları vardır:

- Normal matrislerde boyut çalışma zamanında kullanıcıdan alınamaz; en üst seviye baştan verilir, daha azı kullanılır. Bunu aşmanın yolu dinamik bellek yönetimidir (ileride görülecek).
- Program çalışırken terim sayısını artırmak ekstra kontrol ister.
- Kuvvet tam sayı (`int`, 4 byte) olduğu hâlde `double` matriste saklanır; fazladan yer işgal edilir ve $4$ yerine $4{,}0$ tutulduğu için tam sayıya dönüştürmek gerekir.

Daha düzgün bir yaklaşım iki ayrı dizidir: katsayılar için `double` bir dizi, kuvvetler için `int` bir dizi. $6x^{20} - x^{19}$ için katsayılar $\{6, -1\}$, kuvvetler $\{20, 19\}$ olur (ekrandan, 01:35:00). Hoca proje kapsamında terim sayısı için bir üst sınır (örneğin en fazla 10 terim) konup daha azının kullanılabileceğini söyledi.

Hoca alıştırma olarak iki polinomu toplama (aynı dereceli terimlerin katsayılarını karşılıklı toplama) ve çarpma algoritmalarını yazmayı önerdi.

### 5.3 Trigonometrik, üstel ve logaritmik terimler

Trigonometrik terim $A\cos(x)$ biçimindedir: bir değişken dıştaki katsayı $A$, biri içteki açı için tutulur. İç içe yapılar da olabilir: $A\cos(P(x))$ gibi içte bir polinom bulunabilir (ekrandan, 01:35:00). Üstel fonksiyonlarda $a^x$, $a^{P(x)}$, $a^{\cos x}$ ya da $(\cos x)^{P(x)}$ gibi melez biçimler kurulabilir. Logaritmik terimde önde bir katsayı, bir taban ve bir argüman vardır; argüman yine bir polinom olabilir. Katsayı (ör. `a1`), taban (ör. `base`) ve argüman ayrı değişkenlerde tutulur. Örneğin $\log_2(3x) + \sin x = 0$ denklemi bir logaritmik ve bir sinüzoidal terimin toplamı olarak gösterilip kökü aranabilir.

### 5.4 C'de struct ile terim türü

Bu yaklaşımlar yeterince dinamik değildir. C'de `struct` (yapı) ile kendi veri türümüzü tanımlayabiliriz. Derste anlatılan iskelet şöyleydi (ekranda yazılmadı, sözlü anlatımdan kuruldu):

```c
typedef struct {
    double coefficient; /* katsayı */
    int exponent;       /* kuvvet */
} POLY;

POLY p1, p2;            /* iki polinom terimi */
```

Bir `struct` içine bir `int`, bir `char`, bir `float`, belirli boyutlu bir dizi ya da işaretçi konabilir; bu yapı artık yeni bir değişken türü gibi kullanılır. Hoca projede dizi, matris ya da `struct` yaklaşımlarından istenenin kullanılabileceğini söyledi; kök bulma yöntemleri polinomlar üzerinden test edilir.

## 6. Doğrusal Denklem Takımlarına Giriş: Matrisler

### 6.1 Neden doğrusal denklem takımları?

Yeni konu doğrusal denklem takımlarının çözümüdür (ekrandan, 01:40:00). Şimdiye kadar $y = f(x)$ biçimindeki tek değişkenli denklemlerin kökü bulundu. Ama iki ya da üç bilinmeyenli doğrusal olmayan denklemler de olabilir (ör. $x^3 + 3y^2 = 0$ ile birlikte ikinci bir denklem). Bunları çözmek için önce doğrusal denklem takımları, sonra doğrusal olmayanlar ele alınacaktır.

Doğrusal denklem bir doğruyu ifade eder: $y = 2x + 3$ gibi. İki bilinmeyenli iki denklemden $x$ ve $y$ bulunur. Lineer cebirde analitik yöntemler vardır, ama değişken sayısı arttıkça güçleşir; hesap makineleri genellikle üç değişkene kadar çözer.

### 6.2 Matrislerin bellekte yerleşimi

Matris iki boyutlu dizidir; tek satır ya da tek sütunlu olanlara vektör denir. C ya da Java'da $\left[\begin{smallmatrix}1&2\\3&4\end{smallmatrix}\right]$ matrisi bellekte satır satır ve ardışık adreslerde yerleşir: önce birinci satır, sonra ikinci satır. `int` için hücreler arasında genellikle 4 byte fark vardır.

Hoca bunu bir C koduyla gösterdi (ekrandan, 01:45:00):

```c
#include <stdio.h>
#define MAX 5
int main(){
    double polinom[MAX][3];
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<3;j++){
            printf("%p \n",&polinom[i][j]);
        }
    }
    return 0;
}
```

Kodun ekranda görünen kısmı 8. satıra kadardır; kapanış parantezleri ve `return 0;` eklendi (ara adım eklendi). Çıktıda 15 adres 8'er byte artarak ardışık gelir (ör. `...FDA0`, `...FDA8`, `...FDB0`); `double` 8 byte olduğu için adresler onaltılık tabanda 8'er artar. Kod ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı; uyarısız derlendi ve 15 ardışık, 8 byte aralıklı adres yazdırdı. Üç boyutlu dizi de olsa bellekte yine ardışık yerleşir. C'de indisler 0'dan başlar, matematikte ise 1'den ($a_{1,1}$).

### 6.3 Matris türleri

- Köşegen: satır ve sütun numarasının eşit olduğu elemanlar.
- Alt üçgen matris: köşegenin üstündeki elemanların hepsi sıfır. Üst üçgen matris: köşegenin altındakiler sıfır. Denklem takımlarını çözerken çok kullanılır.
- Birim matris: köşegendeki bütün değerler 1, diğerleri 0.
- Köşegen matris: köşegen dışındaki değerler 0, köşegende sıfırdan farklı değerler var.
- Band matris: köşegen ve köşegene belirli uzaklıktaki elemanlar sıfırdan farklı, diğerleri sıfır. Kısmi türevli diferansiyel denklemlerin çözümünde kullanılır.
- Transpoz: satırlar ile sütunların yer değiştirmesi; $[1\ 2\ 3]$ satırı birinci sütun olur.
- Simetrik matris: $A = A^T$.

**Soru:** (hoca sordu) Kendisi ile transpozu eşit olan matrise ne denir? **Cevap:** (bir öğrenci) Simetrik matris. Slayttaki örnekte $[1\ 2\ 3]$, $[2\ 5\ 6]$, $[3\ 6\ 9]$ satırlı matrisin transpozu kendisine eşittir.

### 6.4 Matris eşitliği

$A$ $m \times n$, $B$ $k \times l$ ise $A = B$ olması için $k = m$, $l = n$ ve bütün $i, j$ için $a_{i,j} = b_{i,j}$ olmalıdır. Hoca bunun kodunun nasıl yazılacağını sordu: önce boyutlara bakılır (`if (m == k)`, ardından `if (n == l)`); boyut şartı sağlanmazsa elemanlara bakmaya gerek yoktur. Sonra iki `for` döngüsüyle bütün elemanlar karşılaştırılır.

### 6.5 Kofaktör, adjoint ve ters matris

Bir elemanın kofaktörü, o elemanın satır ve sütunu silinerek elde edilen matrisin işaretli determinantıdır; bütün elemanlar için yapılınca kofaktör matrisi elde edilir (ekrandan, 01:50:00):

$$\alpha_{1,1} = (-1)^{1+1}\begin{vmatrix} a_{2,2} & a_{2,3} \\ a_{3,2} & a_{3,3}\end{vmatrix},\qquad \alpha_{2,1} = (-1)^{2+1}\begin{vmatrix} a_{1,2} & a_{1,3} \\ a_{3,2} & a_{3,3}\end{vmatrix}.$$

Kofaktör matrisinin transpozu adjoint matristir. Ters matris, adjoint matrisin orijinal matrisin determinantına bölünmesiyle elde edilir:

$$A^{-1} = \frac{\operatorname{adj}(A)}{\det A}.$$

Hoca ters matris ve matris çarpımının robotik ve bilgisayar grafiği gibi alanlarda çok gerektiğini anlattı. Örnek olarak üretim bantlarındaki robot kol (manipülatör) verdi: insan koluna benzer; omuz, dirsek ve bilek eklemleri hareket edince parmak ucunun üç boyutlu koordinat sisteminde nereye gideceği matris işlemleriyle hesaplanır. Problem tersten düşünülünce (parmak ucunu belirli bir yere götürmek için eklemlerin ne kadar dönmesi gerektiği) ters matris gerekir.

İki matrisin eşitliği iki, çarpımı üç iç içe döngü ister ve çarpım $O(n^3)$ karmaşıklıktadır. Ters alma da pahalıdır; bu yüzden bu işlemlerin algoritmik iyileştirmeleri ya da yaklaşık çözümleri bilgisayar mühendisleri için güzel problemlerdir.

Hoca ortogonal matrisi de tanımladı.

> **Ders sonrası not:** Hoca ortogonal matrisi "kendisi ve tersi birbirine eşit olan matris" diye tanımladı. Doğrusu, transpozu tersine eşit olan matristir: $A^T = A^{-1}$, yani $A^TA = I$.

### 6.6 Toplama, çıkarma ve bölme

Aynı boyuttaki matrislerin toplamı aynı konumdaki elemanlar toplanarak bulunur (ekrandan, 01:55:00):

$$\begin{bmatrix}1&2\\3&4\end{bmatrix} + \begin{bmatrix}5&6\\7&8\end{bmatrix} = \begin{bmatrix}6&8\\10&12\end{bmatrix}.$$

Matris çarpımı birinci matrisin satırlarıyla ikinci matrisin sütunlarının çarpımıyla bulunur; $A[i,j]$ ile $B[m,n]$ çarpımı için $j = m$ olmalıdır. Matrislerde bölme işlemi yoktur, ancak matris bir sayıya bölünebilir. Bazı programlama dillerinde matrisin 2'ye bölünmesi, bütün elemanların 2'ye bölünmesi demektir; MATLAB gibi dillerde eleman eleman işlem için noktalı operatörler vardır.

> **Ders sonrası not:** Hoca noktalı bölme operatörünü "dot product" ile ilişkilendirdi. MATLAB'deki `./` operatörü eleman eleman bölmedir; "dot product" (iç çarpım) farklı bir işlemdir.

## 7. Elementer Satır İşlemleri ve Ters Matris

### 7.1 Denklem sisteminin matris formu

Basit denklemler yok etme ya da yerine koyma yöntemiyle çözülür. Bilinmeyen sayısı arttıkça denklem sayısı da artar ve hangi satırı neyle çarpacağımızı görmek zorlaşır. Bunu sistematik yapmanın yolu, denklemleri matris formuna alıp elementer satır işlemleri uygulamaktır. Bilinmeyen sayısı kadar satır ve sütun olur; katsayılar seçilen sırayla (genelde $x, y, z$) yazılır, çizginin sağına sabitler konur. Amaç matrisi alt ya da üst üçgen biçime getirip sıfırların sayısını artırmak ve bilinmeyenleri kolayca bulmaktır.

### 7.2 Üç elementer satır işlemi

- I. Bir satır sıfırdan farklı bir sabitle çarpılabilir. Örneğin $S_1 \leftarrow 2S_1$ ile $[1\ 3\ -1 \mid 10]$ satırı $[2\ 6\ -2 \mid 20]$ olur. Bu genelde köşe elemanını 1 yapmak için kullanılır: 2 varsa $1/2$ ile, $0{,}5$ varsa 2 ile çarpılır.
- II. Herhangi iki satırın yeri değiştirilebilir ($S_1 \leftrightarrow S_2$).
- III. Bir satır başka bir satıra eklenebilir ya da bir sayıyla çarpılıp başka bir satıra eklenebilir.

Üçüncü işlem için ekrandaki örnek (ekrandan, 02:00:00):

$$\left[\begin{array}{ccc|c} 1 & 3 & -1 & 10 \\ 3 & -1 & 2 & 5 \\ 1 & 5 & 2 & -3 \end{array}\right] \xrightarrow{S_1 \leftarrow S_1 + S_2} \left[\begin{array}{ccc|c} 4 & 2 & 1 & 15 \\ 3 & -1 & 2 & 5 \\ 12 & 6 & 3 & 45 \end{array}\right]$$

Burada sağdaki matrisin üçüncü satırı, slaytta yazan "$3 \cdot S_1 \to S_3$" işleminin de uygulanmış hâlidir: $S_1$'in 3 katı ($[12\ 6\ 3 \mid 45]$) üçüncü satıra yazılmıştır.

> **Ders sonrası not:** Slayttaki "$S_3 \leftarrow 3S_1$" işlemi üçüncü satırı tamamen silip yerine $3S_1$ yazar; bu, sistemi değiştirir (iki satır orantılı olur). Üçüncü elementer işlem büyük olasılıkla $S_3 \leftarrow S_3 + 3S_1$ biçiminde kastedilmiştir; bu durumda satır $[13\ 11\ 5 \mid 42]$ olurdu.

Hoca bu işlemlerin geri alınabildiğini, yani çözümü değiştirmediğini, aslında sadeleştirmenin daha sistematik hâli olduğunu söyledi. Örneğin $2x + 3y$ ve $-x - 8y$ içeren iki denklemde ikinci satır 2 ile çarpılıp toplanırsa $x$'li terimler birbirini götürür.

### 7.3 Satır işlemleriyle ters matris

Adjoint ve determinant ile ters almak zor olabilir. Bunun yerine $A$ ile birim matris yan yana yazılır ($[A \mid I]$) ve satır işlemleriyle $A$ birim matrise çevrilir; bu sırada sağ taraf $A^{-1}$ olur. Çünkü $A \cdot A^{-1} = I$'dır.

> **Hocanın vurgusu:** Yalnız kare matrislerin tersi alınabilir ve her kare matrisin tersi yoktur. $\det A = 0$ ise $\operatorname{adj}(A)/\det A$ tanımsızdır. Örneğin bir satırı tamamen sıfır olan $\left[\begin{smallmatrix}0&0&0\\4&8&3\\2&6&8\end{smallmatrix}\right]$ matrisinde Sarrus kuralındaki bütün çarpımlar sıfır olur; determinant sıfırdır ve tersi alınamaz.

Ekrandaki $2\times2$ örnek (ekrandan, 02:05:00): $A = \left[\begin{smallmatrix}1&2\\3&4\end{smallmatrix}\right]$. Sıra şöyledir: önce birinci sütunda sıfır yapılır (1. satır), sonra köşegendekiler 1 yapılır, en son ikinci sütundaki köşegen dışı eleman sıfırlanır.

$$\left[\begin{array}{cc|cc} 1 & 2 & 1 & 0 \\ 3 & 4 & 0 & 1 \end{array}\right] \xrightarrow{-3S_1 + S_2 \to S_2} \left[\begin{array}{cc|cc} 1 & 2 & 1 & 0 \\ 0 & -2 & -3 & 1 \end{array}\right] \xrightarrow{-\frac12 S_2 \to S_2} \left[\begin{array}{cc|cc} 1 & 2 & 1 & 0 \\ 0 & 1 & \frac32 & -\frac12 \end{array}\right] \xrightarrow{-2S_2 + S_1 \to S_1} \left[\begin{array}{cc|cc} 1 & 0 & -2 & 1 \\ 0 & 1 & \frac32 & -\frac12 \end{array}\right]$$

Sonuç $A^{-1} = \left[\begin{smallmatrix}-2&1\\ 3/2&-1/2\end{smallmatrix}\right]$ (Python ile doğrulandı). $(1,1)$ elemanı 1 olduğu için onunla uğraşılmadı. Hoca, $(2,2)$ elemanı 1 yapılmadan üstündeki elemanın sıfırlanamayacağını vurguladı. Ekrandaki not: matrisin $(1,1)$ gözündeki değer 0 olmamalıdır; sıfır ise ilk iş onu sıfırdan kurtarmaktır, bu yüzden satırların yeri değiştirilir.

Hoca $3\times3$ matrislerde de aynı yaklaşımın sarmal bir sırayla uygulandığını anlattı: önce köşe 1 yapılır, altındakiler sıfırlanır, sonra bir sonraki köşegen elemanına geçilir ve sıfırlar adım adım artırılır.

### 7.4 Kare olmayan matrisin yaklaşık tersi

Kare olmayan matrisin gerçek tersi yoktur, yaklaşık (pseudo) tersi bulunur. Satır sayısı sütun sayısından büyükse (ör. $3\times2$) önce transpoz alınır ve $A^T A$ çarpılır; $2\times3$ ile $3\times2$'nin çarpımı $2\times2$ bir kare matris verir. Bu matrisin tersi alınabilir ve transpozla çarpılınca soldan ters bulunur: $(A^TA)^{-1}A^T$. Diğer yol $AA^T$ ile kare matris elde etmektir; birine soldan, diğerine sağdan ters denir.

> **Ders sonrası not:** Hoca $3\times2$ bir matris için $AA^T$ ($3\times3$) yolunun da kullanılabileceğini söyledi. $A$ $3\times2$ ise $AA^T$'nin rankı en fazla 2'dir, yani $3\times3$ matris tekildir ve tersi alınamaz. Satır sayısı fazla olan matriste soldan ters $(A^TA)^{-1}A^T$, sütun sayısı fazla olanda sağdan ters $A^T(AA^T)^{-1}$ kullanılır.

## 8. Gauss-Jordan Eliminasyonu ile Ters Matris

Ters almanın algoritmik yolu Gauss-Jordan eliminasyonudur; bir önceki yaklaşıma çok benzer. Ekrandaki örnek (ekrandan, 02:10:00):

$$A = \begin{bmatrix} 5 & 2 & -4 \\ 1 & 4 & 2 \\ 2 & 3 & 6 \end{bmatrix}.$$

1. işlem: 1. satır $a_{11} = 5$'e bölünür:

$$\left[\begin{array}{ccc|ccc} 1 & 0{,}4 & -0{,}8 & 0{,}2 & 0 & 0 \\ 1 & 4 & 2 & 0 & 1 & 0 \\ 2 & 3 & 6 & 0 & 0 & 1 \end{array}\right]$$

2. işlem: ikinci satırdan $a_{21} \cdot S_1$ çıkarılır ($a_{21} = 1$). Hoca, $a_{21}$ 2 olsaydı 2 ile, 3 olsaydı 3 ile çarpılacağını söyledi. Sonuç $[0;\ 3{,}6;\ 2{,}8 \mid -0{,}2;\ 1;\ 0]$. Aynı şekilde üçüncü satırdan $a_{31} \cdot S_1$ ($a_{31} = 2$) çıkarılır: $[0;\ 2{,}2;\ 7{,}6 \mid -0{,}4;\ 0;\ 1]$ (ara adım eklendi, Python ile hesaplandı). Dördüncü, beşinci satır olsaydı aynı işlem onlara da uygulanırdı.

3. işlem: bir sonraki köşegen elemanına ($a_{22} = 3{,}6$) geçilir; ikinci satır $3{,}6$'ya bölünür. Sonra bu satırın katları diğer satırlardan çıkarılarak ikinci sütun temizlenir. Python ile ara durum:

$$\left[\begin{array}{ccc|ccc} 1 & 0 & -1{,}11 & 0{,}222 & -0{,}111 & 0 \\ 0 & 1 & 0{,}78 & -0{,}056 & 0{,}278 & 0 \\ 0 & 0 & 5{,}89 & -0{,}278 & -0{,}611 & 1 \end{array}\right]$$

Altyazıdaki $-1{,}11$ ve $0{,}78$ değerleri bu tabloyla tutuyor.

4. işlem: üçüncü satır kendi köşegen değerine bölünerek $(3,3)$ elemanı 1 yapılır. Son olarak $-1{,}11$ ve $0{,}78$'i sıfırlamak için birinci satırdan $a_{13} \cdot S_3$, ikinci satırdan $a_{23} \cdot S_3$ çıkarılır. Sol taraf birim matris olur, sağ taraf $A^{-1}$'dir.

Python ile bulunan sonuç (derste son matrisin değerleri incelenen karelerde görünmüyor):

$$A^{-1} \approx \begin{bmatrix} 0{,}1698 & -0{,}2264 & 0{,}1887 \\ -0{,}0189 & 0{,}3585 & -0{,}1321 \\ -0{,}0472 & -0{,}1038 & 0{,}1698 \end{bmatrix},\qquad \det A = 106.$$

Hoca doğrusal denklem takımlarının çözüm yöntemlerinin, bugün anlatılanların adım adım tekrarıyla birlikte gelecek derste işleneceğini söyledi. Ders kitabındaki örneklerin çözülmesini, matris tersinin nasıl alındığının farklı kaynaklardan araştırılmasını ve kodlanmasını önerdi.

### 8.1 Ders sonundaki soru: `scanf` ve `&`

**Soru:** C kodunda adres yazdırmak için matris elemanının önüne `&` koyduk. Matrisler zaten işaretçi yerine geçmiyor muydu? `&` koymayınca farklı sonuçlar çıktı. **Cevap:** Bir elemanın bellekteki fiziksel adresini yazdırmak için `&polinom[i][j]` yazmak gerekir. Kullanıcıdan değer alırken de `scanf` adres ister: `scanf("%lf", &polinom[i][j]);`. Elemanın sayısal değerini yazdırmak için ise `&` kullanılmaz. `scanf`'te `&` yazılmazsa, örneğin hücredeki değer 18 ise bilgisayar 18 numaralı adrese erişmeye çalışır; bu adres programın erişimine açık olmadığı için program genellikle işletim sistemi tarafından kapatılır. Karakter dizilerinde (`char str[10]`) `scanf("%s", str);` yeterlidir, çünkü dizinin adı zaten bir adres tutar. İndis işin içine girince adresten değere geçilir; tekrar adrese dönmek için `&` gerekir. Bu konular işaretçi aritmetiğinde daha ayrıntılı görülecektir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:20:00)

Kenar uzunluğu $a = 6$ olan bir karenin dört köşesinden $x$ uzunluğunda kesilerek üstü açık bir kutu yapılmaktadır. Bu kutunun hacmini maksimum yapan $x$ değerini Newton-Raphson yöntemi ile bulunuz. Başlangıç değerini 0, kabul edilebilir hatayı $0{,}001$ alınız.

**Çözüm (derste verildi):** $V = (6-2x)^2x$, $V' \propto x^2 - 4x + 3$. $f(x) = x^2 - 4x + 3$, $f'(x) = 2x - 4$. $x_0 = 0 \to 0{,}75 \to 0{,}975 \to 0{,}9997 \to 1{,}0000$. $x = 1$, $V_{\max} = 16$ birim küp (ayrıntı Bölüm 2.4'te).

### Soru 2 (ekrandan, 00:45:00)

$x^2 - 9x - 10 = 0$ denklemi için tekrarlama yöntemine uygun $g(x)$ fonksiyonları yazınız ve $x_0 = 0$'dan iterasyona başlayınız.

**Çözüm (derste kısmen verildi):** $g_1(x) = \sqrt{9x+10}$: $x_1 = \sqrt{10}$, $x_2 = \sqrt{9\sqrt{10}+10}$, … $g_2(x) = (x^2-10)/9$ ve $g_3(x) = 10/(x-9)$: $x_1 = -10/9$.

> **Çözüm (derste verilmedi):** Python ile: $g_1$ ile $3{,}162;\ 6{,}202;\ 8{,}113;\ 9{,}111;\ 9{,}592;\ \dots \to 10$. $g_2$ ile $-1{,}111;\ -0{,}974;\ -1{,}006;\ -0{,}999;\ \dots \to -1$. $g_3$ ile $-1{,}111;\ -0{,}989;\ -1{,}001;\ \dots \to -1$. Kökler $10$ ve $-1$'dir.

### Soru 3 (ekrandan, 00:50:00)

$\sin x + x - 1 = 0$ denkleminin $[0,1]$ aralığındaki yaklaşık kökünü tekrarlama yöntemiyle bulunuz (kökü $10^{-3}$'ten az hata ile bulmak isteyelim).

**Çözüm (derste kısmen verildi):** $g(x) = 1 - \sin x$. $f(0) = -1$, $f(1) \approx 0{,}84$; kök vardır. $g'(x) = -\cos x$, $|g'(0)| = 1$ (şart sağlanmaz), $|g'(1)| \approx 0{,}54 < 1$. Bu yüzden $x_0 = 1$ alınır.

> **Çözüm (derste verilmedi):** Python ile $x_0 = 1$'den $|x_{i+1} - x_i| < 10^{-3}$ olana kadar iterasyon yapıldığında değerler kökün iki yanında salınarak yavaşça daralır ($0{,}1585;\ 0{,}8421;\ 0{,}2539;\ 0{,}7488;\ 0{,}3193;\ 0{,}6861;\ \dots$) ve $0{,}511$ civarına oturur. Kök $x \approx 0{,}5110$'dur ($0{,}510973$).

### Soru 4 (ekrandan, 01:00:00)

$f(x) = x^2 - 2x - 3$ fonksiyonunun köklerini $x_0 = 4$ başlangıç noktası ve $0{,}005$ hata ile bulunuz.

**Çözüm (derste verildi):** $g(x) = \sqrt{2x+3}$ ile $4 \to 3{,}316 \to 3{,}104 \to 3{,}034 \to 3{,}011 \to 3{,}004 \to 3{,}001$; son fark $0{,}003 < 0{,}005$, kök $3{,}001$. $g(x) = 3/(x-2)$ ile önce fark büyür, sonra $-1$'e yakınsar. $g(x) = (x^2-3)/2$ ıraksar (ayrıntı Bölüm 4.8'de; slayttaki $-1{,}29032$ değerine ilişkin düzeltme orada).

### Soru 5 (ekrandan, 02:05:00)

$A = \left[\begin{smallmatrix}1&2\\3&4\end{smallmatrix}\right]$ matrisinin tersini elementer satır işlemleriyle bulunuz.

**Çözüm (derste verildi):** $-3S_1 + S_2 \to S_2$, $-\frac12 S_2 \to S_2$, $-2S_2 + S_1 \to S_1$. $A^{-1} = \left[\begin{smallmatrix}-2&1\\3/2&-1/2\end{smallmatrix}\right]$.

### Soru 6 (ekrandan, 02:10:00)

$A = \left[\begin{smallmatrix}5&2&-4\\1&4&2\\2&3&6\end{smallmatrix}\right]$ matrisinin tersini Gauss-Jordan eliminasyon yöntemiyle bulunuz.

**Çözüm (derste adımları verildi, son matris karelerde görünmüyor):** Bölüm 8'deki adımlarla $[A \mid I] \to [I \mid A^{-1}]$.

> **Çözüm (derste verilmedi):** Python ile $A^{-1} = \frac{1}{106}\left[\begin{smallmatrix}18&-24&20\\-2&38&-14\\-5&-11&18\end{smallmatrix}\right] \approx \left[\begin{smallmatrix}0{,}1698&-0{,}2264&0{,}1887\\-0{,}0189&0{,}3585&-0{,}1321\\-0{,}0472&-0{,}1038&0{,}1698\end{smallmatrix}\right]$.

### Soru 7 (derste sözlü, 01:48:44)

İki matrisin eşit olup olmadığını kontrol eden bir kod nasıl yazılır?

**Cevap (derste verildi):** Önce boyutlar karşılaştırılır ($m = k$ ve $n = l$). Boyutlar farklıysa matrisler eşit değildir. Eşitse iki iç içe `for` döngüsüyle bütün $a_{i,j}$ ve $b_{i,j}$ karşılaştırılır.

### Soru 8 (derste sözlü, 01:34:05)

İki polinomu toplayan algoritmayı yazınız (alıştırma olarak önerildi).

> **Çözüm (derste verilmedi):** Polinom, indisi derece olan bir `double` dizide tutulursa toplama aynı indisli katsayıların toplanmasıdır. Aşağıdaki kod ajan tarafından yazıldı ve `gcc -Wall` ile uyarısız derlenip çalıştırıldı; $p(x) = x^4 + 6x^2$ ile $q(x) = 2x^3 - x^2 + 3$ için çıktı `+1.0 x^4 +2.0 x^3 +5.0 x^2 +3.0 x^0` oldu.

```c
#include <stdio.h>
#define MAX 10
int main(){
    double p[MAX] = {0}, q[MAX] = {0}, t[MAX];
    int i;
    /* p(x) = 6x^2 + x^4, q(x) = 3 - x^2 + 2x^3 ; dizi indisi = derece */
    p[4] = 1; p[2] = 6;
    q[0] = 3; q[2] = -1; q[3] = 2;
    for(i=0;i<MAX;i++)
        t[i] = p[i] + q[i];
    for(i=MAX-1;i>=0;i--)
        if(t[i] != 0)
            printf("%+.1f x^%d ", t[i], i);
    printf("\n");
    return 0;
}
```

## Dersin Toparlaması

Bu derste doğrusal olmayan denklemlerin köklerini bulan açık yöntemler tamamlandı. Newton-Raphson teğet doğrusuyla (ya da Taylor serisinin ilk iki terimiyle) türetildi ve kutu problemiyle uygulandı. Sekant yöntemi türev yerine iki yakın noktadan geçen kirişi kullanarak türev maliyetinden kurtardı. Tekrarlama yöntemi $x = g(x)$ dönüşümüne dayanır; aynı denklemden çıkan farklı $g(x)$'lerin bazılarının yakınsayıp bazılarının ıraksadığı, $|g'(a)| < 1$ ve $|g'(b)| < 1$ testiyle uygunluğun kontrol edilebileceği görüldü. Bütün açık yöntemlerde ortak durma ölçütü ardışık kökler arasındaki farkın bir toleransın altına inmesidir; fark büyüyorsa algoritma durdurulmalıdır.

Ardından proje için fonksiyonların bilgisayarda gösterimi (dizi, matris, ayrı diziler ve `struct`) tartışıldı ve doğrusal denklem takımlarına giriş yapıldı: matrislerin bellekte yerleşimi, matris türleri, kofaktör, adjoint ve ters matris, elementer satır işlemleri, satır işlemleri ve Gauss-Jordan eliminasyonu ile ters alma. Gelecek derste doğrusal denklem takımlarının çözüm yöntemleri bu temeller üzerine adım adım işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
