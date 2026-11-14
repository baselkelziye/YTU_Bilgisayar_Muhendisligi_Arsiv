# Ders 4 Genişletilmiş Notu: Tekrarlama (Sabit Nokta) Yöntemi, Matris İşlemleri, Gauss-Jordan ile Ters Alma, Cramer ve Gauss Eliminasyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kısa Özet: Kapalı ve Açık Yöntemler
- 2. Tekrarlama (Sabit Nokta) Yöntemi
- 3. Tekrarlama Yöntemi Örnekleri
- 4. Doğrusal Denklem Takımları İçin Matris Bilgileri
- 5. Elementer Satır İşlemleri
- 6. Matrisin Tersini Almak: Gauss-Jordan
- 7. Doğrusal Denklem Takımları ve Yöntemlerin Sınıflandırılması
- 8. Cramer Yöntemi
- 9. Gauss Eliminasyon (Yok Etme) Yöntemi
- 10. Gauss-Jordan Yöntemi

## 1. Kısa Özet: Kapalı ve Açık Yöntemler

Hoca derse, geçen hafta başlanan üçüncü bölümü, yani doğrusal (lineer) olmayan denklemlerin çözümünü hatırlatarak başladı. Bilinmeyenin derecesi 2, 3 ve üzeriyse ya da denklemin içinde trigonometrik ifadeler veya $e$ üzeri gibi terimler varsa bu denklem doğrusal değildir. Bu denklemlerin çözümü çok kolay değildir. Burada görülen yöntemlerde bir tane bilinmeyen olur. Birden fazla bilinmeyen varsa onların çözümü ayrı bir konudur.

Doğrusal olmayan denklemlerin çözümü kapalı ve açık yöntemler diye ikiye ayrılmıştı:

- **Kapalı yöntemler:** $a$ ve $b$ diye iki değer verilir ve kök bu iki değerin arasında olmak zorundadır. Sınır değerleri fonksiyonda yerine konur. $f(a)$ ile $f(b)$ ters işaretliyse, yani çarpımları negatifse, bu aralıkta bir kök vardır. Bu yöntemler ıraksamaz, köke yakınsar. Ama iterasyon sayısı biraz uzun sürebilir.
- **Açık yöntemler:** İki değer verilebilir, ama kök bu iki değerin arasında olmak zorunda değildir. Iraksama ihtimali vardır. Kökten giderek uzaklaştığınızı görürseniz aralığı değiştirmeniz gerekir. Yakınsarlarsa kapalı yöntemlere göre köke çok daha hızlı ulaşırlar.

Açık yöntemlerden Newton-Raphson ve sekant (kiriş) yöntemleri görülmüştü. Bu dersin ilk bölümü, açık yöntemlerin üçüncüsü olan tekrarlama yöntemine ayrıldı. Hoca bu noktada hesap yapılacağı için yanınızda mutlaka hesap makinesi bulunması gerektiğini de hatırlattı.

## 2. Tekrarlama (Sabit Nokta) Yöntemi

Yöntemin İngilizce adı *fixed point iteration method*, Türkçeye çevrilmiş adı tekrarlama yöntemidir. Hocaya göre diğerlerinden biraz farklı ama kullanışlıdır ve iyi sonuç alınabilir. Yöntemin bir de kontrol kısmı vardır. Kontrol olumsuz çıkarsa işlem biraz uzayabilir. Bu yüzden anlatımı diğer yöntemlere göre uzun sürer.

### 2.1 Temel Fikir: $f(x) = 0$ Biçiminden $x = g(x)$ Biçimine

Yöntem, doğrusal olmayan ve analitik çözümü olmayan bir bilinmeyenli denklemlerin köklerini bulmada kullanılır. Kökü bulunacak $f(x)$ fonksiyonu, $x$ değişkeni sol tarafta tek başına kalacak şekilde $x = g(x)$ biçiminde parçalanır. Yani elimizdeki bir fonksiyon iki parçaya bölünür: biri $x$, diğeri $g(x)$. Aslında $g(x)$'i eşitliğin diğer tarafına geçirirsek

$$x - g(x) = 0$$

olur ve bu yine $f(x) = 0$ demektir. Çözülecek denklem sayısı birken ikiye çıkar. Hoca bunun işi zorlaştırmadığını, tersine denklemleri daha basite indirdiğini söyledi.

Slayttaki ilk örnekte $x$ eşitliğin sol tarafına alındı, sağ tarafta $-\sin x$ ile sabit terim kaldı. Sağ taraf $g(x)$, sol taraf $x$ oldu. Aynı fonksiyon aşağıda 3.1'de ayrıntılı çözülür.

<!-- BELİRSİZ: Slayttaki ilk örneğin denklemi altyazıda okunmadı. Sözlü anlatım 3.1'deki sin x + x - 1 = 0 denklemiyle uyumlu. -->

> **Ders sonrası not:** Altyazıda bu ilk örnek için sağ tarafta "eksi sinüs x, eksi 1" kaldığı söyleniyor. Denklem büyük olasılıkla $\sin x + x - 1 = 0$ olduğundan doğrusu $x = -\sin x + 1$'dir. Hoca aynı işlemi 3.1'deki örnekte "eksi 1, artı 1 olarak diğer tarafa geçti" diyerek doğru yaptı.

### 2.2 Bir $f$ İçin Birden Fazla $g$ Yazılabilir

$x$'in sol tarafta yalnız kalmasını sağlayan birden fazla $g(x)$ olabilir. Hocanın örneği $x^2 - 9x - 10 = 0$ denklemidir.

Birinci yol: $x^2$ sol tarafta bırakılır, $9x$ ve $10$ diğer tarafa geçer. $x$'i yalnız bırakmak için kare kök alınır:

$$x^2 = 9x + 10 \quad\Rightarrow\quad x = \sqrt{9x + 10}$$

İkinci yol: $9x$ içindeki $x$ sol tarafa alınır:

$$9x = x^2 - 10 \quad\Rightarrow\quad x = \frac{x^2 - 10}{9}$$

Böylece aynı fonksiyondan iki farklı $g(x)$ elde edildi. Hangisiyle devam edileceği bu aşamada bilinmez. İkisi de kullanılabilir, yalnız biri uygun olabilir ya da hiçbiri uygun olmayabilir. Buraya kadar yapılan iş, verilen fonksiyonu $x$ sol tarafta kalacak şekilde bölebildiğimiz kadar farklı $x$, $g(x)$ çiftine ayırmaktır. Hangi $g(x)$'in seçileceğinin kuralları aşağıda anlatılıyor.

### 2.3 Grafikle Yorum: Yakınsama ve Iraksama

Hoca yöntemin nasıl çalıştığını üç grafik üzerinden anlattı. $x = g(x)$ yazdığımızda sol taraf bir doğrudur: $y = x$ doğrusu. Sağ taraf ise bir eğridir: $y = g(x)$. Kök, bu ikisinin kesiştiği noktadır.

Birinci grafikte bir başlangıç noktası $x_0$ alınır ve $g(x)$'te yerine konur. Elde edilen değer doğru üzerinden yeni $x$ değeri olur. Bu yeni $x$ yine $g(x)$'te yerine konur, sonuç yine doğruya taşınır. Fonksiyondakini doğruya, doğrudakini fonksiyona taşıyarak ilerlenir ve en sonunda iki eğrinin kesiştiği noktaya, yani köke gelinir. Burada seçilen $g(x)$ yakınsıyor, yani doğru bir $g(x)$ alınmıştır.

İkinci grafikte farklı bir $g(x)$ alınır. Aynı işlem yapılır, adımlar yine köke yakınsar. Bu $g(x)$ de uygundur.

Üçüncü grafikte yine bir başlangıç noktası alınıp aynı işlem yapılır. Ancak her adımda kökten giderek uzaklaşılır. Yani yöntem ıraksar ve bu $g(x)$, yöntem için uygun değildir. Yapılacak kontroller birinci ve ikinci grafikteki $g(x)$'lere "evet, bununla yoluna devam edebilirsin", üçüncüye "hayır" der.

<!-- BELİRSİZ: Üç grafiğin çizimi slaytta. Altyazıda yalnız sözlü olarak anlatılıyor. -->

### 2.4 İşlem Adımları ve Durma Koşulu

Yöntemin işlem adımları şöyledir:

- **Adım 1:** $f(x) = 0$ denklemi $x = g(x)$ biçimine getirilir. Birden fazla $g(x)$ olabilir.
- **Adım 2:** $g(x)$'in $[a, b]$ aralığında gerekli şartları sağlayıp sağlamadığı kontrol edilir.
- **Adım 3:** Şartlar sağlanıyorsa başlangıç $x$ değeri $g(x)$'te yerine konur ve yeni bir $x$ elde edilir: $x_{i+1} = g(x_i)$.
- **Adım 4:** Bu yeni $x$ tekrar $g(x)$'te yerine konur. Durma noktasına gelene kadar devam edilir.
- **Adım 5:** Durulduğunda en son bulunan $x$, köktür.

Durma noktasında arka arkaya hesaplanan iki kök değerine bakılır. En son bulunan $x_{k+1}$ ile ondan önceki $x_k$'nın farkı mutlak değerce, belirlenen hatadan küçük veya eşitse durulur:

$$|x_{k+1} - x_k| \le \varepsilon$$

Başka durma koşulları da vardır. Gerçek kök değeri verilirse, bu değerle bulunan son $x$ arasındaki fark $\varepsilon$'dan küçük olunca durulabilir. Ya da belirli bir iterasyon sayısı verilir, örneğin 10.000 iterasyon sonra durulur.

> **Hocanın vurgusu:** Örneklerde farklı şeyler kullanılsa bile sizden isteneceği %95 oranında ardışık iki $x$ değerinin farkıyla durmaktır. Kağıt kalemle işlem yaparken bu çok daha hızlıdır.

### 2.5 Uygunluk Kontrolü

Bir fonksiyon, bir aralık ve fonksiyondan çıkarılmış $g(x)$'ler elimizde olsun. Sırayla şunlara bakılır:

- **Aralıkta kök var mı?** $a$ ve $b$ fonksiyonda yerine konur. $f(a) \cdot f(b) < 0$ ise bu aralıkta kök vardır.
- **Fonksiyonlar türevlenebilir mi?** $f(x)$ ve $g(x)$'in türevi alınabilir olmalı, yani tanımsız bir fonksiyon olmamalıdır. Buraya kadarki kısım önceki yöntemlerde de vardı.
- **Seçilen $g(x)$ doğru mu?** $g(x)$'in türevi alınır. Türevde önce $a$, sonra $b$ yerine konur. İkisinin de mutlak değeri 1'den küçük olmalıdır:

$$|g'(a)| < 1 \quad \text{ve} \quad |g'(b)| < 1$$

Bu iki şart aynı anda sağlanıyorsa, $x$ ile $g(x)$'in çakıştığı kökü aramaya $[a, b]$ aralığındaki her noktadan başlanabilir: $a$, $b$ ya da ikisi arasında herhangi bir sayı. Başlangıç değeri genelde verilir. Verilmezse ilk ya da son değerle başlanır. Hoca kitapların genelde böyle yaptığını, ama seçimde özgür olduğunuzu söyledi.

> **Ders sonrası not:** Altyazıda bir yerde türevin "$b$'den küçük", 3.2'deki örnekte de "negatiften küçük" olması gerektiği geçiyor. Kastedilen büyük olasılıkla her iki yerde de mutlak değerce 1'den küçük olmasıdır. Ayrıca iki uçta şartın sağlanması, kaynaklardaki yakınsama şartının büyük olasılıkla tamamı değildir. Bu şartlarda genellikle $|g'(x)| < 1$ eşitsizliğinin bütün aralıkta geçerli olması ve $g$'nin aralığı kendi içine taşıması istenir. Uç noktalara bakmak pratik bir kontroldür.

> **Ek bilgi (derste anlatılmadı):** Türevin neden 1 ile karşılaştırıldığı büyük olasılıkla en kolay ortalama değer teoremiyle görülür. Kök $r$ için $r = g(r)$ olduğundan $x_{i+1} - r = g(x_i) - g(r) = g'(\xi)(x_i - r)$ yazılır. Yani her adımda hata yaklaşık $|g'|$ ile çarpılır. $|g'| < 1$ ise hata küçülür, $|g'| > 1$ ise büyür. $|g'|$ 1'e ne kadar yakınsa yakınsama büyük olasılıkla o kadar yavaş olur.

### 2.6 Şart Sağlanmazsa Ne Yapılır?

Türevlerin ikisi de ya da biri 1'den küçük değilse hocanın "çok dikkatli dinleyin" diyerek anlattığı iki yol vardır.

**Birinci yol:** Bu $g(x)$ bırakılır. Elde başka $g(x)$'ler varsa onlardan biri seçilir ve aynı kontrol yapılır. Belki o $g(x)$ şartları sağlar ve kök oradan bulunur.

**İkinci yol:** Elde tek bir $g(x)$ vardır ve yenisi çıkarılamaz. Bu durumda şunu fark etmek gerekir:

> **Hocanın vurgusu:** Şartın $a$ ve $b$'de sağlanmaması, $a$ ile $b$ arasındaki hiçbir $x$ değerinin bu şartı sağlamadığı anlamına gelmez. Siz şu an yalnız $a$ ve $b$'yi kontrol ediyorsunuz. Örneğin $a = 10$, $b = 20$ ise arada belki 13.5 değeri şartı sağlar.

Bu yüzden aralıktan bir $x_i$ alınır, $x_{i+1} = g(x_i)$ hesaplanır ve şu oran kontrol edilir:

$$0 < \left| \frac{g(x_i) - g(x_{i+1})}{x_i - x_{i+1}} \right| < 1$$

Oran 0 ile 1 arasında kalıyorsa işleme bu $x_i$ ile başlanır. Kalmıyorsa aralıkta yeni bir $x$ alınıp aynı kontrol yapılır. Genelde büyük olandan başlanıp giderek küçültülür ya da küçükten başlanıp giderek artırılır.

Bunu elle yapmak elbette zordur. Ama algoritma yazıldığında bir $x_i$ verilir, $x$ örneğin 0.25 artımlarla değiştirilerek bu şartı sağlayan bir değer olup olmadığı aranır. $b$ sınırına kadar çıkılır ve bulunamazsa, bu $g(x)$'in aranan $g(x)$ olmadığına ikna olunur ve başka bir $g(x)$ ile devam edilir.

Sonuç olarak verilen bir $f(x)$ için kontrol sırası şudur:

- **Adım 1:** $g(x)$'lerden biri seçilir, türevi alınır, $a$ ve $b$ yerine konur.
- **Adım 2:** İkisi de mutlak değerce 1'den küçükse bu $g(x)$ ile çözüme geçilir.
- **Adım 3:** Değilse bir sonraki $g(x)$ aynı şekilde kontrol edilir.
- **Adım 4:** Hiçbiri sağlamıyorsa, şartı sağlamayan $g(x)$ için aralıkta teker teker yeni $x$ değerleri aranır.

## 3. Tekrarlama Yöntemi Örnekleri

### 3.1 Örnek 1: $\sin x + x - 1 = 0$, $[0, 1]$ Aralığı

Denklem doğrusal değildir, çünkü trigonometrik fonksiyon içerir. Tek değişken vardır: $x$. Aralık $a = 0$, $b = 1$'dir.

**Aralıkta kök var mı?** $x$ yerine 0 ve 1 konur:

$$f(0) = \sin 0 + 0 - 1 = -1, \qquad f(1) = \sin 1 + 1 - 1 = 0.84$$

Değerler ters işaretlidir, bu aralıkta bir kök vardır.

Burada hoca bir uyarı yaptı. $x$ yerine 0 konunca derece de radyan da 0'dır, sorun çıkmaz. Ama 1 gibi bir değer, doğrudan sinüsün içine yazılmadan önce doğru birime çevrilmelidir. Hesap makineniz derece modundaysa, $\pi$ radyan 180 derece olduğu için 1 radyan $\frac{180}{\pi}$ derecedir. $x$ yerine $x \cdot \frac{180}{\pi}$ yazılır ve değer öyle elde edilir.

> **Hocanın vurgusu:** Trigonometrik fonksiyonlarda türevi hesaplarken bile dereceye geçmeyi ya da radyanla işlem yapmayı unutmayın.

**$g(x)$'i bulma:** $x$ sol tarafta kalacak şekilde parçalanır. $\sin x$ eşitliğin diğer tarafına $-\sin x$, $-1$ de $+1$ olarak geçer:

$$x = 1 - \sin x, \qquad g(x) = 1 - \sin x$$

**Uygunluk kontrolü:** Türev alınır:

$$g'(x) = -\cos x$$

$$|g'(0)| = |-\cos 0| = 1, \qquad |g'(1)| = |-\cos 1| = 0.54$$

0.54, 1'den küçüktür ama 1, 1'den küçük değildir. İkisinin de şartı sağlaması gerektiği için şart sağlanmaz. Yani $[0, 1]$ aralığındaki her nokta başlangıç olarak seçilemez. Hoca ikinci bir $g(x)$ aradı, ama çıkaramadı.

**İkinci kontrol:** Öyleyse aralıktan bir $x_i$ alınıp 2.6'daki oran kontrol edilir. Büyük olandan başlanarak $x_i = 1$ seçildi. Önce sonraki değer bulunur:

$$x_{i+1} = g(1) = 1 - \sin 1 = 0.158529$$

Bu değer oranda yerine konur. $g(0.158529) = 0.842134$ olduğundan (ara adım eklendi):

$$\left| \frac{g(1) - g(0.158529)}{1 - 0.158529} \right| = \left| \frac{0.158529 - 0.842134}{0.841471} \right| = \frac{0.683605}{0.841471} = 0.81 < 1$$

Oran 0 ile 1 arasında kaldığı için şart sağlanır. Artık nereden başlanacağı bellidir: $x_0 = 1$.

<!-- BELİRSİZ: Hoca bu oranı slayttan okurken "0.58 nereden çıkmış, şu an bilmiyorum" dedi. Slayttaki değer altyazıda okunmuyor. -->

> **Ders sonrası not:** Hoca bu kontrolü okurken "$\cos 1$ radyan" dedi. Oranda $g(1) = 1 - \sin 1$ kullanılır, $\cos$ yalnız türevde geçer. Söylediği "0.58" de büyük olasılıkla bir sonraki satırdaki 0.158 değeridir.

**İterasyon:** $x_{i+1} = g(x_i)$ uygulanır. Hoca ilk üç değeri söyledi, 0.15, 0.84 ve 0.25. Sonraki değerler aynı işlemle bulunur (ara adım eklendi):

| $i$ | $x_i$ | $x_{i+1} = 1 - \sin x_i$ | $\lvert x_{i+1} - x_i \rvert$ |
|---:|---:|---:|---:|
| 0 | 1 | 0.158529 | 0.841471 |
| 1 | 0.158529 | 0.842134 | 0.683605 |
| 2 | 0.842134 | 0.253934 | 0.588200 |
| 3 | 0.253934 | 0.748786 | 0.494852 |
| 4 | 0.748786 | 0.319250 | 0.429536 |
| 5 | 0.319250 | 0.686146 | 0.366896 |

Ardışık iki kök değerinin mutlak farkı $\varepsilon$'dan küçük veya eşit olana kadar devam edilir.

**Soru:** Bu şart $x = 1$ için sağlanmasaydı ne olacaktı?

**Cevap:** Aralık $[0, 1]$ olduğuna göre başka bir $x$ denenir, örneğin 0.90. 0.90 değeri $g$'de yerine konup yeni $x$ bulunur ve ikisi oranda kullanılır. Şart yine sağlanmazsa örneğin 0.10 azaltılarak 0.80 alınır. Şart sağlandığı anda çözüm o noktadan yapılır ve ardışık kökler arasındaki farka bakılarak durulur. Yöntem budur. Elle çözüldüğünde biraz zahmetlidir, ama programı bir kez yazıldıktan sonra zahmeti kalmaz. Yazarken yorulursunuz, ondan sonra istediğiniz kadar çözersiniz.

> **Ders sonrası not:** Örneğin sonucu derste söylenmedi. Python hesabına göre kök $r \approx 0.51097$ ve $|g'(r)| \approx 0.872$'dir. Bu değer 1'e yakın olduğu için ardışık fark ölçütü $\varepsilon = 0.005$ ile büyük olasılıkla ancak 38. iterasyonda durur (bulunan değer 0.5131). Ayrıca $x_0 = 0$ alınırsa ilk adım 1'e gider ve aynı dizi çıkar. Uçta $|g'| = 1$ olması bu örnekte büyük olasılıkla yalnız şartın dışında kalmak anlamına gelir, yöntem yine yakınsar.

### 3.2 Örnek 2: $x^5 + x - 3 = 0$, $[1, 3]$ Aralığı

Bu slayt, aynı işlem sırasının özeti olarak geçildi. Aralık sınırları fonksiyonda yerine konur: $f(1) = -1$, $f(3) = 243$ (ara adım eklendi). Değerler zıt işaretli olduğu için aralıkta kök vardır.

Fonksiyon iki şekilde parçalanır:

- $x$ sol tarafa alınır: $x = 3 - x^5$. Bu birinci $g(x)$'tir.
- $x^5$ sol tarafa alınır ve beşinci dereceden kök alınır: $x = \sqrt[5]{3 - x}$. Bu ikinci $g(x)$'tir.

Hangisinin şartı sağlayacağına sırayla bakılır. Önce birincinin türevi alınır, 1 ve 3 yerine konur. İkisi de mutlak değerce 1'den küçükse bu $g(x)$ ile devam edilir. Değilse ikinci $g(x)$ kontrol edilir. O da sağlamazsa, $g(x)$'lerden birinin içinde aralıktan teker teker yeni $x$ değerleri aranır. Slaytta "diyelim ki şart sağlandı" denerek çözüme geçildi. Bulunan $x$ değeri $g$'de yerine konur, çıkan yeni değer tekrar $g$'ye konur ve son iki değerin mutlak farkı hatadan küçük veya eşit olana kadar devam edilir.

> **Ders sonrası not:** Altyazıda ikinci $g(x)$ için kökün içi "$x - 3$" diye geçiyor. $x^5 = 3 - x$ olduğundan doğrusu $3 - x$'tir. Şart da derste atlandı. Python hesabına göre $g(x) = 3 - x^5$ için $|g'(1)| = 5$ ve $|g'(3)| = 405$ çıkar, bu $g$ büyük olasılıkla ıraksar. $g(x) = \sqrt[5]{3 - x}$ için kök $r \approx 1.1330$ ve $|g'(r)| \approx 0.12$'dir. Ancak $x = 3$'te türev tanımsızdır. Bu yüzden başlangıç için büyük olasılıkla $x = 1$ gibi bir nokta seçilmelidir.

### 3.3 Örnek 3: $f(x) = x^2 - 2x - 3$, $x_0 = 4$

Hocanın "aynı zamanda siz de gözünüzde yapmaya çalışın" diyerek çözdüğü son örnektir. Başlangıç değeri 4 verilmiştir ve $\varepsilon = 0.005$'tir. Hoca bazen başlangıç değeri, bazen kapalı aralık verildiğini, genelde aralığın verilmesi gerektiğini söyledi. Bu örnekte aralığı yazmamıştı, bunu kendi hatası olarak belirtti ve sözlü olarak önce $[4, 5]$ dedi, sonra "1 ile 4 arasında olsun" diye düzeltti. Fonksiyonun bu aralıkta ters işaretli olduğu görülür: $f(1) = -4$, $f(4) = 5$ (ara adım eklendi).

<!-- BELİRSİZ: Denklem ve ε = 0.005 slaytta. Altyazıda fonksiyon ve hata sayısal olarak okunmuyor, kısa nottan ve sözlü anlatımdaki g(x) ile köklerden alındı. -->

Fonksiyondan üç farklı $g(x)$ çıkarılır:

- $x^2$ sol tarafta bırakılır ve kök alınır: $g_1(x) = \sqrt{2x + 3}$.
- $x^2 - 2x$ sol tarafa geçirilir, $x$ ortak parantezine alınır: $x(x - 2) = 3$. Buradan $g_2(x) = \frac{3}{x - 2}$.
- $2x$ sol tarafa alınır: $g_3(x) = \frac{x^2 - 3}{2}$.

Elde üç $g(x)$ vardır, hangisiyle yola çıkılacağına türevlerle bakılır. Her ikisi de 1'den küçükse o $g(x)$ ile gönül rahatlığıyla devam edilir. Değilse ya ara değerler kontrol edilir ya da en kolay yol seçilip öteki $g(x)$'e bakılır. Hoca türev değerlerini söylemedi, $[1, 4]$ için şöyledir (ara adım eklendi):

| $g(x)$ | $g'(x)$ | $\lvert g'(1) \rvert$ | $\lvert g'(4) \rvert$ |
|:---|:---|---:|---:|
| $g_1 = \sqrt{2x + 3}$ | $\frac{1}{\sqrt{2x + 3}}$ | 0.447 | 0.302 |
| $g_2 = \frac{3}{x - 2}$ | $\frac{-3}{(x - 2)^2}$ | 3 | 0.75 |
| $g_3 = \frac{x^2 - 3}{2}$ | $x$ | 1 | 4 |

Üç $g(x)$ ile de $x_0 = 4$'ten başlanarak aşağıdaki tablo bulunur:

| $i$ | $g_1$: $x_i$ | Fark | $g_2$: $x_i$ | Fark | $g_3$: $x_i$ | Fark |
|---:|---:|---:|---:|---:|---:|---:|
| 0 | 4 | | 4 | | 4 | |
| 1 | 3.31662 | 0.68338 | 1.5 | 2.5 | 6.5 | 2.5 |
| 2 | 3.10375 | 0.21288 | $-6$ | 7.5 | 19.625 | 13.125 |
| 3 | 3.03439 | 0.06936 | $-0.375$ | 5.625 | 191.07 | 171.45 |
| 4 | 3.01144 | 0.02295 | $-1.26316$ | 0.88816 | 18252.43 | 18061.36 |
| 5 | 3.00381 | 0.00763 | $-0.91935$ | 0.34380 | | |
| 6 | 3.00127 | 0.00254 | $-1.02762$ | 0.10827 | | |
| 7 | | | $-0.99088$ | 0.03675 | | |
| 8 | | | $-1.00305$ | 0.01217 | | |
| 9 | | | $-0.99898$ | 0.00407 | | |

**$g_1$ ile çözüm:** $x_0 = 4$ fonksiyonda yerine konur, yeni $x$ bulunur. Bu yine fonksiyonda yerine konur ve böyle devam edilir. Her adımda $x$ değerlerinin farkına bakılır: $\varepsilon$'dan küçük mü? Değilse devam. Altıncı adımda fark $0.00254 \le 0.005$ olur ve durulur. Bulunan kök yaklaşık 3'tür. Zaten fonksiyonun köklerinden biri de 3'tür.

**$g_2$ ile çözüm:** Burada ayrı bir şeyle karşılaşılır. Yine başlangıç 4'tür, aynı işlemler yapılır, farklara bakılır. Fark $\varepsilon$'dan küçük olduğunda bulunan kök yaklaşık $-1$'dir. Fonksiyonun kökleri 3 ve $-1$'dir. Yani **farklı $g(x)$'ler farklı kökleri verebilir**. Üç anlamlı basamak istenseydi otomatik olarak $-1$ denilebilirdi.

**$g_3$ ile çözüm:** Hoca uygunluk kontrolünü bilerek yapmadan bu $g(x)$ ile devam etti. 4 verildi, 6.5 bulundu. 6.5 yeni $x$ oldu, 19 civarı bulundu, sonra 191, sonra 18252. Bulunan $x$ değerleri arasındaki fark gittikçe büyür, $\varepsilon$'dan çok uzaklaşır. Farkın büyüdüğünü görünce buradan bir çıkış olmadığı anlaşılır. Bu aynı zamanda $g_3$'ün türevinin $a$ ve $b$ için 1'den küçük olmadığını gösterir. Bu $g(x)$ ile bu yöntem ıraksar.

Diğer iki $g(x)$'te ise iki kök değeri arasındaki farklar gittikçe küçülür. İterasyon sayısı tamamıyla $\varepsilon$'un kaç verildiğine bağlı olarak değişir. Burada ikisinde de hata aynıdır, ama $g_1$ 6 adımda, $g_2$ daha fazla adımda köke ulaşır. Hocanın açıklaması şudur: Başlangıç değeri 4'tür. 3 olan kök 4'e daha yakındır, bu yüzden daha az adımda bulunur. $-1$ kökü 4'ten daha uzakta olduğu için iterasyon sayısı artar. Hoca bu tür ilişkilerin böyle kurulabileceğini söyledi.

> **Ders sonrası not:** Hoca kökleri önce "$-3$ ile $+1$" diye söyledi, sonra "3 ile $-1$" dedi. Doğrusu 3 ve $-1$'dir. Altyazıda $g_1$'in ilk adımı "3.16", $g_3$'ün değerleri "19", "141" ve "18250" olarak geçiyor. Python hesabına göre doğru değerler 3.317, 19.625, 191.07 ve 18252.43'tür. Söylenen sayılar büyük olasılıkla sözlü sürçme ya da yuvarlamadır.

> **Ders sonrası not:** Slaytta $g_2$ tablosu büyük olasılıkla 4. adımdan itibaren hatalıdır. Kısa nottaki slayt değerleri $-1.29032$, $-0.91176$, $-1.03030$, $-0.98999$, $-1.00335$, $-0.99888$, $-1.00037$ şeklindedir. Oysa $\frac{3}{-0.375 - 2} = -1.26316$'dır. Slayttaki sonraki değerler ise $-1.29032$'den doğru türetilmiştir. Yukarıdaki tablo Python ile hesaplandı. Bu değerlerle ölçüt 9. adımda sağlanır ($0.00407 \le 0.005$). Hocanın saydığı 10 adım büyük olasılıkla slayttaki bir fazla satırdan gelir, sonuç yine yaklaşık $-1$'dir.

> **Ders sonrası not:** $g_2$, $[1, 4]$ içinde $x = 2$'de tanımsızdır, $|g_2'(1)| = 3$ ile uç şartı da sağlamaz ve bulduğu $-1$ kökü aralığın dışındadır. Yani bu örnek açık yöntemin aralık dışına çıkabildiğini gösterir ve bu aralık için $g_2$ büyük olasılıkla "uygun" sayılmaz. $g_3$ için 3 kökünde $|g'| = 3$, $-1$ kökünde $|g'| = 1$'dir. Ayrıca köklerin etrafında $|g_1'(3)| = |g_2'(-1)| = \frac{1}{3}$ olduğundan iki dizinin kuyruk hızı aynıdır. Adım sayısındaki fark büyük olasılıkla gerçekten başlangıç noktasının uzaklığından gelir.

Burada ilk ders saati bitti. Hoca aradan sonra denklem takımlarına geçileceğini, bu takımları çözerken elimizdeki denklemleri matris gibi düşüneceğini ve önce bazı matris işlemlerini anlatacağını söyledi.

## 4. Doğrusal Denklem Takımları İçin Matris Bilgileri

Doğrusal denklem takımlarını çözebilmek için takımı matris formuna indirgememiz ve matrisler üzerinde bir takım işlemler yapmamız gerekir. Bazen "bu matrisi alt veya üst üçgen matris yapın", bazen "katsayılar matrisi birim matris olsun", bazen "bant matris yapın", bazen "tersini alın" denir. Hoca kimin ne durumda olduğunu bilmediği için bunları kısaca hatırlattı.

Matris, satırlardan ve sütunlardan oluşan iki boyutlu bir dizidir. Bu konuda her satır bir denkleme, her sütun denklemdeki bir terime karşılık gelir.

### 4.1 Üçgen, Birim, Köşegen ve Bant Matrisler

Bir yöntem gereği katsayılar matrisini alt veya üst üçgen matrise çevirmemiz istenebilir.

- **Alt üçgen matris:** Köşegenin üzerindeki bütün değerler sıfırdır. Sayılar köşegen ve altındadır. Bu hale getirmek için köşegenin üzerini sıfır yapacak bir dizi işlem uygulanır. İşlemler sırasında köşegen ve altındaki sayılar da değişir, ama amaç üstü sıfırlamaktır.
- **Üst üçgen matris:** Köşegenin altı sıfırdır. Sayılar nerede kaldıysa matris o adı alır.
- **Birim matris:** Yalnız köşegen 1, geri kalan her şey sıfırdır.
- **Köşegen matris:** Köşegenin dışındaki bütün katsayılar sıfırdır.
- **Bant matris:** Köşegen çevresindeki bir şerit sayılarla doludur, bu bandın altı ve üstü sıfırdır. Bandın genişliğinin ne olacağı için hoca kesin bir şey söylemedi. Slayttaki örnekte bir kaydırılarak üçer değerin geldiği bir bant gösterildi.

Bunların hepsine bir dizi dönüşüm işlemiyle ulaşılır. Hoca sıfıra dönüştürmenin çok farklı yolları olduğunu, kendisinin bir yol izleyip yöntemlerde hep onu kullanacağını söyledi.

<!-- BELİRSİZ: Bant matris çizimi kalemle yapıldı, altyazıda okunmuyor. -->

### 4.2 Transpoz ve Simetrik Matris

Satır ve sütunların yerleri değiştirilirse matrisin transpozu alınmış olur. Bir matrisin kendisi ile transpozu birbirinin aynısıysa bu matrise simetrik matris denir. Yani bir $A$ matrisinin simetrik olup olmadığını anlamak için transpozu alınır, aynıysa simetriktir: $A = A^T$.

### 4.3 Kofaktör Matrisi

Elimizde bir katsayılar matrisi varsa, buradaki her terimin kofaktörü hesaplanabilir. $a_{11}$'in kofaktörü $\alpha_{11}$, $a_{33}$'ün kofaktörü $\alpha_{33}$ gibi. Bu değerlerden oluşan matrise kofaktör matrisi denir.

$a_{ij}$'nin kofaktörünü hesaplamak için bulunduğu satır ve sütun silinir, ortada kalan değerlerin determinantı alınır ve $(-1)^{i+j}$ ile çarpılır.

- $a_{11}$ için birinci satır ve birinci sütun silinir. Üs $1 + 1 = 2$ olduğundan $(-1)^2 = +1$ ile çarpılır.
- $a_{33}$ için üçüncü satır ve üçüncü sütun silinir, kalan dörtlünün determinantı alınır. Üs $3 + 3 = 6$ olduğundan yine $+1$ ile çarpılır.

Hoca "matematik dersinde burada 3, 5, 7, 8 diye sayılar görüyoruz, ama ne olmuş o sayılar?" sorusuna gerçek dünyadan örnekler verdi. Bunu, kofaktörün ileride veri biliminde, veri madenciliğinde ve görüntü işlemede kullanılan yöntemlerin içinde karşınıza çıkacağını anlatmak için söyledi.

- **Doküman-kelime matrisi:** Matrisin bir ekseni dokümanlar, diğer ekseni kelimeler olsun. Bir kelime birinci dokümanda 5 kez, ikincide hiç, üçüncüde 10 kez geçiyor olabilir. Matrisin içindeki sayılar bu sayımlardır. Bu bilginin içinden önemli özellikler, yani hangi kelimelerin daha ayırt edici olduğu çıkarılmak istenir. Bir kelimenin hangi dokümanlarda ne kadar göründüğünden yola çıkılarak yeni değerler elde edilir.
- **Görüntü:** Her satır resmin bir tarama çizgisi (scanline), her eleman o çizgideki bir pikselin renk kodu olsun. Resimden ayırt edici özellikler çıkarılırken arka planda kofaktör işlemi kullanan yöntemler vardır.

Sayısal analizde bunlar yalnız sayılardan oluşan matrislerdir, ama gerçek dünyada karşılıkları vardır.

> **Ders sonrası not:** Altyazıda $a_{33}$ için sonuç bir yerde "alfa bir üç" diye geçiyor, doğrusu $\alpha_{33}$'tür. Doküman-kelime ve görüntü matrislerinden özellik çıkarırken kaynaklarda büyük olasılıkla daha çok kovaryans matrisi ve tekil değer ayrışımı gibi araçlar geçer. Hocanın burada büyük olasılıkla bu tür matris işlemlerini kastettiğini, kofaktörün bu alanların temel aracı olmadığını akılda tutun.

### 4.4 Adjoint Matris, Matrisin Tersi ve Ortogonal Matris

Kofaktör matrisinin transpozu alınırsa adjoint (ek) matris elde edilir. Adjoint matris, matrisin tersini almak için kullanılır. Adjoint matris, $A$'nın determinantına oranlanırsa matrisin tersi bulunur:

$$A^{-1} = \frac{\text{adj}(A)}{|A|}$$

Bir programlama dilinde kod yazarken kütüphanedeki ters alma fonksiyonuna matrisi parametre olarak gönderirsiniz, o size hemen sonucu verir. Hoca arka planda bu işlemlerin yapıldığını söyledi. Peki biz bunları niye görüyoruz? Çünkü bir matrisin tersini kendimiz yazmak istesek nasıl kodlayacağımızı, yani tersi sayısal yöntemlerle nasıl alacağımızı bu derste göreceğiz.

Ortogonal matris için de iki vektörün birbirine dik olması gerektiğini söyledi.

> **Ders sonrası not:** Hoca "bir matrisin kendisi tersine eşitse ortogonaldir" dedi. Doğrusu $A^T = A^{-1}$, yani $A^T A = I$'dir. Ayrıca kütüphanelerdeki ters alma fonksiyonları büyük olasılıkla adjoint yerine LU ayrıştırması gibi eliminasyon temelli yöntemler kullanır, adjoint yöntemi büyük matrislerde çok yavaş kalır.

### 4.5 Matrislerde Dört İşlem

- **Toplama ve çıkarma:** Karşılıklı gözlerdeki değerler toplanır veya çıkarılır.
- **Çarpma:** $m \times n$ ve $i \times j$ boyutlu iki matrisi çarpabilmek için $n$ ile $i$ aynı olmalıdır. Yoksa çarpılamaz. İlk matrisin birinci satırı ile ikinci matrisin birinci sütunu çarpılıp yeni matrisin ilk gözüne yazılır, diğerleri de böyle devam eder.
- **Bölme:** Bir matris başka bir matrise bölünemez. Ama bir matris bir sayıya bölünebilir. Bir matrisi 5'e bölmek, her elemanını 5'e bölmek demektir.

## 5. Elementer Satır İşlemleri

Bize bir problem sonucu elde edilmiş matrisler verilecek. Denklem takımlarının katsayıları matrislere indirgenecek ve bu matrisler üst üçgen, alt üçgen gibi biçimlere getirilecek. Bunun için yapılan temel işlemlere elementer işlemler denir.

### 5.1 Genişletilmiş Katsayılar Matrisi

Elimizde üç denklem ve üç bilinmeyen olsun:

$$\begin{aligned} x + 3y - z &= 10 \\ 3x - y + 2z &= 5 \\ x + 5y - 2z &= -3 \end{aligned}$$

Bu takım $AX = C$ biçiminde yazılır. $A$ katsayılar matrisi, $X$ bilinmeyenler matrisi, $C$ sağ taraf matrisidir. Bilinmeyenler $x_1, x_2, x_3$ de olabilir, $x, y, z$ de. Katsayılar ile $C$'nin yan yana yazılmasıyla oluşan matrise genişletilmiş (İngilizcesiyle *augmented*) katsayılar matrisi denir:

$$[A \mid C] = \left[\begin{array}{ccc|c} 1 & 3 & -1 & 10 \\ 3 & -1 & 2 & 5 \\ 1 & 5 & -2 & -3 \end{array}\right]$$

<!-- BELİRSİZ: Altyazıda matris elemanları işaretsiz okunuyor ("1, 5, 2" ve "15, 3"). Denklemler ve üçüncü satır kısa nottan alındı. -->

### 5.2 İşlemler

Bu matris üzerinde yapılabilecek satır işlemleri şunlardır:

- **Bir satırı bir sayıyla çarpmak.** Birinci satır 2 ile çarpılır: $2S_1 \to S_1$. Yeni birinci satır $2, 6, -2, 20$ olur.
- **İki satırın yerini değiştirmek.** $S_1 \leftrightarrow S_2$ yapılınca birinci satır $3, -1, 2, 5$, ikinci satır $1, 3, -1, 10$ olur.
- **İki satırı toplayıp bir satıra yazmak.** $S_1 + S_2 \to S_1$ için terim terim toplanır: $1 + 3 = 4$, $3 - 1 = 2$, $-1 + 2 = 1$, $10 + 5 = 15$. Yeni birinci satır $4, 2, 1, 15$ olur.
- **Bir satırı bir sayıyla çarpıp başka bir satıra eklemek.** Slaytta bir önceki sonuçtaki birinci satır 3 ile çarpılıp üçüncü satıra yazıldı: $3 \cdot (4, 2, 1, 15) = (12, 6, 3, 45)$.

> **Ders sonrası not:** Altyazıda "1'i 3 ile çarptım, 12" geçiyor, çarpılan 4'tür. Üçüncü satırın yerine yalnız $3S_1$ yazmak üçüncü satırdaki bilgiyi siler ve elementer işlem olmaz. Doğrusu çarpımın üçüncü satıra eklenmesidir: $3S_1 + S_3 \to S_3$. Slaytta büyük olasılıkla yalnız çarpımın sonucu gösterilmiştir. Slayttaki matriste $z$ katsayısı büyük olasılıkla $+2$ yazılıydı, denklemdeki ise $-2$'dir. Python hesabına göre denklemlerdeki hâliyle determinant 0'dır, yani sistem tekildir. Örnek yalnız satır işlemlerini göstermek içindir.

### 5.3 Bilgi Değişmez

Hoca bu işlemlerin en önemli özelliğini bir kesir benzetmesiyle anlattı. Ne ile çarparsak, ne ile toplarsak toplayalım, matrisin içindeki sayılar değişir, ama matrisin taşıdığı bilgi değişmez. $\frac{2}{10}$ ile $\frac{1}{5}$ iki farklı yazılıştır, ama ikisinin taşıdığı bilgi aynıdır. Her ikisine $\frac{3}{5}$ eklense de oranladığımızda bir şey değişmediğini görürüz.

Elementer işlemleri yapmamızın sebebi matrisi istediğimiz forma getirmektir.

> **Hocanın vurgusu:** Orijinal matris ile üzerinde elementer satır işlemi yapılmış genişletilmiş matrisin çözümleri aynıdır.

Buraya kadar olanlar lineer cebirdeki matris bilgilerinin kısa özetiydi.

## 6. Matrisin Tersini Almak: Gauss-Jordan

### 6.1 Fikir: $[A \mid I]$ Biçiminden $[I \mid A^{-1}]$ Biçimine

Matrisin tersini adjoint bölü determinant olarak alabiliyorduk. Ama sayısal analizde bununla uğraşmak yerine kod yazmak isteriz. Öyle bir algoritma olmalı ki tekrar eden, basit, dört işleme benzeyen işlemlerden oluşsun. Her ne kadar çok iteratif gözükse de kodlaması kolay olsun.

Ortaya atılan yöntemlerden biri şunu der: $A$ katsayılar matrisi ile birim matris $I$ yan yana yazılır. $A$'yı birim matrise çevirmek için elementer işlemler yapılır ve aynı işlemler aynı anda $I$'ya da uygulanır. $A$, $I$'ya dönüştüğünde $I$'nın dönüştüğü yeni matris $A$'nın tersi olur:

$$[A \mid I] \quad \longrightarrow \quad [I \mid A^{-1}]$$

Hoca bunu "çok enteresan" diye niteledi. Hep $A$'yı birim matrise nasıl çevireceğimizi düşünürüz, aynı işlemleri yan taraftaki birim matrise de yaparız, bir bakarız ters alınmış olur.

> **Ek bilgi (derste anlatılmadı):** Bunun nedeni büyük olasılıkla şöyle görülür. Her elementer işlem, soldan bir elementer matrisle çarpmaya denktir. $A$'yı $I$'ya çeviren işlemlerin çarpımına $E$ dersek $EA = I$ olur, yani $E = A^{-1}$'dir. Aynı işlemler $I$'ya uygulanınca $EI = E = A^{-1}$ elde edilir. Bu yüzden sol taraf $I$ olduğunda sağ tarafta ters kalır.

### 6.2 Dikkat Edilecekler

> **Hocanın vurgusu:** Yalnız kare matrislerin tersi alınır. Her kare matrisin de tersi alınamayabilir. $A$'yı birim matrise getirirken bir satır tamamen sıfır oluyorsa o matrisin tersi alınamaz.

Matris kare değilse ters almadan önce bir ön işlem gerekir. Hoca bunun detayına girmedi, hep kare matris verildiğini düşüneceğimizi söyledi. Ancak aşağıda 6.4'te fikir olması için kısaca gösterdi.

Bir başka not da şudur: Birim matrise çevirirken $(1, 1)$ gözünde sıfır varsa bu gözü sıfırdan kurtarmak gerekir. Yoksa tersi bu yöntemle almakta zorlanırsınız. Kurtulmanın yolu, satırların yerini değiştiren bir elementer işlemdir.

### 6.3 $2 \times 2$ Örnek

$A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \end{bmatrix}$ matrisinin tersi isteniyor. Birim matrise çevirmek için köşegenin 1, kalanın 0 olması gerekir. Slaytta önce $a_{21}$ sıfırlanır, sonra köşegen 1 yapılır, sonra $a_{12}$ sıfırlanır.

$$\left[\begin{array}{cc|cc} 1 & 2 & 1 & 0 \\ 3 & 4 & 0 & 1 \end{array}\right]$$

**1. işlem: $-3S_1 + S_2 \to S_2$.** Birinci satır, alttaki 3'ün negatifiyle çarpılır ve ikinci satırla toplanır. $1 \cdot (-3) = -3$, $3$ ile toplanınca 0. $2 \cdot (-3) = -6$, $4$ ile toplanınca $-2$. $1 \cdot (-3) = -3$, $0$ ile toplanınca $-3$. $0 \cdot (-3) = 0$, $1$ ile toplanınca 1.

$$\left[\begin{array}{cc|cc} 1 & 2 & 1 & 0 \\ 0 & -2 & -3 & 1 \end{array}\right]$$

**2. işlem: $-\frac{1}{2} S_2 \to S_2$.** Köşegendeki $-2$'yi 1 yapmak için ikinci satır $-\frac{1}{2}$ ile çarpılır. $0$, $1$, $\frac{3}{2}$, $-\frac{1}{2}$ bulunur.

$$\left[\begin{array}{cc|cc} 1 & 2 & 1 & 0 \\ 0 & 1 & \frac{3}{2} & -\frac{1}{2} \end{array}\right]$$

**3. işlem: $-2S_2 + S_1 \to S_1$.** İkinci satır $-2$ ile çarpılıp birinci satırla toplanır. $0 + 1 = 1$, $-2 + 2 = 0$, $-3 + 1 = -2$, $1 + 0 = 1$.

$$\left[\begin{array}{cc|cc} 1 & 0 & -2 & 1 \\ 0 & 1 & \frac{3}{2} & -\frac{1}{2} \end{array}\right] \quad\Rightarrow\quad A^{-1} = \begin{bmatrix} -2 & 1 \\ \frac{3}{2} & -\frac{1}{2} \end{bmatrix}$$

> **Ders sonrası not:** Hoca 3. işlemi okurken "$S_2$'yi ikiyle çarp" dedi, işlemi $-2$ ile yaptı. Kastedilen büyük olasılıkla $-2$'dir. Python hesabına göre $A A^{-1} = I$ sağlanır.

Hoca "siz bu temel dönüşümleri kafanızdan mı attınız?" sorusunu kendisi sorup cevapladı. Bunları kafadan atmıyoruz. Her birimiz farklı dönüşümler bulabiliriz, ama birkaç tane yaptıktan sonra rutine biner. Bir yol bulunur ve birim matrise çevirmek gerektiğinde hep aynı yöntem kullanılır. Birden fazla işlem kombinasyonu vardır, her kitapta farklı olabilir. Kendiniz de türetebilirsiniz, yeter ki doğru türetin.

### 6.4 Kare Olmayan Matrisin Tersi

Hoca bunu lineer cebirden genel kültür olarak verdi ve anlatılan konunun dışında tuttu. Slayttaki matris:

$$A = \begin{bmatrix} 1 & 2 \\ 3 & 4 \\ 2 & 1 \end{bmatrix}_{3 \times 2}$$

Transpozu $2 \times 3$, kendisi $3 \times 2$ olduğu için $A^T A$ çarpımı $2 \times 2$ boyutunda kare bir matristir. Buna $C$ denir. Sonra $C$'nin tersi $A^T$ ile çarpılır ve buna soldan ters denir.

- **Satır sayısı sütun sayısından büyükse:** $C = A^T A$, soldan ters $A^{-L} = C^{-1} A^T$'dir. $A^{-L} A = I$ verir.
- **Sütun sayısı satır sayısından büyükse:** $C = A A^T$, sağdan ters $A^T C^{-1}$'dir.

Bu matris için sayılar şöyledir (ara adım eklendi):

$$C = A^T A = \begin{bmatrix} 14 & 16 \\ 16 & 21 \end{bmatrix}, \qquad |C| = 38, \qquad A^{-L} = C^{-1} A^T = \frac{1}{38} \begin{bmatrix} -11 & -1 & 26 \\ 12 & 8 & -18 \end{bmatrix}$$

Hoca bunun taşıdığı bilgi açısından bir şey değiştirmediğini, yalnızca bir bilgi olarak kenarda durması gerektiğini söyledi.

> **Ders sonrası not:** Hoca "ister soldan ister sağdan" dedi. Python hesabına göre bu $3 \times 2$ matris için $A^{-L} A = I_{2 \times 2}$ sağlanır, ama $A A^{-L}$ birim matris çıkmaz. Yani satır sayısı büyükken büyük olasılıkla yalnız soldan ters vardır, sağdan ters ise yalnız sütun sayısı büyükken vardır. Her iki durumda $C$'nin tersinin var olması da gerekir.

### 6.5 $3 \times 3$ Örnek

Yöntemin adı Gauss-Jordan eliminasyon yöntemidir. Hoca bu örneğin bir öncekine göre daha güzel anlatıldığını, slayttaki mavi başlıkların birbirini tekrar ettiğini ve bir algoritma yazacaksak bunlara dikkat etmemiz gerektiğini söyledi.

$$A = \begin{bmatrix} 5 & 2 & -4 \\ 1 & 4 & 2 \\ 2 & 3 & 6 \end{bmatrix}, \qquad [A \mid I] = \left[\begin{array}{ccc|ccc} 5 & 2 & -4 & 1 & 0 & 0 \\ 1 & 4 & 2 & 0 & 1 & 0 \\ 2 & 3 & 6 & 0 & 0 & 1 \end{array}\right]$$

Aşağıda ara değerler dört basamakla verilmiştir. Hocanın slaytta okuduğu değerler iki basamaklıdır (0.78, 5.88 gibi).

**1. işlem: 1. satırı $a_{11}$'e böl.** $a_{11}$'in 1 olması gerekir, bütün satır 5'e bölünür: $1, 0.4, -0.8, 0.2, 0, 0$.

**2. işlem: 2. satırdan $a_{21} \cdot (1.\ \text{satır})$ çıkar.** $a_{11}$ artık 1 olduğundan, $a_{21}$ ile çarpınca $a_{21}$'in kendisi çıkar ve kendisinden çıkarınca o göz sıfırlanır. $a_{21} = 1$: $1 - 1 \cdot 1 = 0$, $4 - 1 \cdot 0.4 = 3.6$, $2 - 1 \cdot (-0.8) = 2.8$, $0 - 1 \cdot 0.2 = -0.2$, $1 - 0 = 1$, $0 - 0 = 0$.

**3. işlem: 3. satırdan $a_{31} \cdot (1.\ \text{satır})$ çıkar.** $a_{31} = 2$: $2 - 2 = 0$, $3 - 0.8 = 2.2$, $6 + 1.6 = 7.6$, $0 - 0.4 = -0.4$, $0$, $1$ (ara adım eklendi).

$$\left[\begin{array}{ccc|ccc} 1 & 0.4 & -0.8 & 0.2 & 0 & 0 \\ 0 & 3.6 & 2.8 & -0.2 & 1 & 0 \\ 0 & 2.2 & 7.6 & -0.4 & 0 & 1 \end{array}\right]$$

Hoca birinci sütundaki kalıbı özetledi: 1. satırı $a_{11}$'e böl, sonra $a_{21}$'i 1. satırla çarp ve 2. satırdan çıkar, $a_{31}$'i 1. satırla çarp ve 3. satırdan çıkar. Dördüncü satır olsaydı $a_{41}$'i 1. satırla çarpıp 4. satırdan çıkarırdık.

**4. işlem: 2. satırı $a_{22}$'ye böl.** $3.6$'ya bölünür: $0, 1, 0.7778, -0.0556, 0.2778, 0$.

**5. işlem: 1. satırdan $a_{12} \cdot (2.\ \text{satır})$ çıkar.** $a_{12} = 0.4$. Bu kez köşegenin üstündeki de sıfırlanır: $0.4 - 0.4 \cdot 1 = 0$, $-0.8 - 0.4 \cdot 0.7778 = -1.1111$. Sağ taraf: $0.2222, -0.1111, 0$ (ara adım eklendi).

**6. işlem: 3. satırdan $a_{32} \cdot (2.\ \text{satır})$ çıkar.** $a_{32} = 2.2$: $0, 0, 5.8889, -0.2778, -0.6111, 1$ (ara adım eklendi).

$$\left[\begin{array}{ccc|ccc} 1 & 0 & -1.1111 & 0.2222 & -0.1111 & 0 \\ 0 & 1 & 0.7778 & -0.0556 & 0.2778 & 0 \\ 0 & 0 & 5.8889 & -0.2778 & -0.6111 & 1 \end{array}\right]$$

**7. işlem: 3. satırı $a_{33}$'e böl.** $5.8889$'a bölünür: $0, 0, 1, -0.0472, -0.1038, 0.1698$. Hoca burada öğrencilere "yedinci işlem ne olacak?" diye sordu, cevabı buydu.

**8. işlem: 1. satırdan $a_{13} \cdot (3.\ \text{satır})$ çıkar.** $a_{13} = -1.1111$: $1, 0, 0, 0.1698, -0.2264, 0.1887$ (ara adım eklendi).

**9. işlem: 2. satırdan $a_{23} \cdot (3.\ \text{satır})$ çıkar.** $a_{23} = 0.7778$: $0, 1, 0, -0.0189, 0.3585, -0.1321$ (ara adım eklendi).

$$\left[\begin{array}{ccc|ccc} 1 & 0 & 0 & 0.1698 & -0.2264 & 0.1887 \\ 0 & 1 & 0 & -0.0189 & 0.3585 & -0.1321 \\ 0 & 0 & 1 & -0.0472 & -0.1038 & 0.1698 \end{array}\right]$$

$A$ birim matrise dönüştü, sağ taraf da başlangıçtaki $A$'nın tersi oldu.

> **Ders sonrası not:** Slayttaki sonuç büyük olasılıkla $\begin{bmatrix} 0.16 & -0.23 & 0.19 \\ -0.02 & 0.36 & -0.13 \\ -0.05 & -0.11 & 0.17 \end{bmatrix}$'dir. Python hesabına göre $|A| = 106$'dır ve yukarıdaki dört basamaklı tablo doğrudur. Doğru yuvarlamayla 0.16 yerine 0.17, $-0.11$ yerine $-0.10$ çıkar. Aradaki fark, ara adımlarda iki basamakla yuvarlamadan gelir, Python'da iki basamaklı hesap da 0.16 ve $-0.11$ verdi. Slayttaki 9. işlem başlığında $a_{22}$ yazıyorsa, büyük olasılıkla yazım hatasıdır ve doğrusu yukarıdaki gibi $a_{23}$'tür. Slayttaki 6. işlem başlığında büyük harfle yazılmış $A_{32}$ de küçük harf olmalıdır, bunu hoca kendisi söyledi.

### 6.6 Algoritmaya Bakış

Hoca lineer cebirde ters almayı hatırlattı: determinant hesaplanır, adjoint alınır, bunlardan bir işlem elde edilir. Burada ise sayısal yöntemle yapılır ve bir algoritma yazılır. Algoritmada iki iç içe `for` döngüsü görünür:

- **Dış döngü** köşegen satırını dolaşır. Önce 1. satırla, sonra 2. satırla, sonra 3. satırla çalışılır. Her turda o satır, köşegen elemanına bölünür.
- **İç döngü** diğer satırları dolaşır ve o sütundaki değerleri sıfırlar. Dış döngü 1 iken $a_{21}$ ve $a_{31}$, 2 iken $a_{12}$ ve $a_{32}$, 3 iken $a_{13}$ ve $a_{23}$ sıfırlanır.

Yalnız başlangıç ve bitiş değerlerine dikkat etmek gerekir. Kodlandığında matrisin tersi çok hızlı alınır.

> **Hocanın vurgusu:** Gauss-Jordan yöntemi, en hızlı ve en kolay ters alabileceğiniz yöntemdir. Tersi için başka bir algoritmaya gerek yoktur. Başka kaynakta farklı elementer dönüşümler görebilirsiniz, kendiniz de türetebilirsiniz, ama doğru çevirip çevirmediğinizi kontrol etmeniz gerekir.

> **Ek bilgi (derste anlatılmadı):** Hocanın $(1, 1)$ gözündeki sıfır için söylediği satır değiştirme, kaynaklarda büyük olasılıkla kısmi pivotlama adıyla geçer. Her sütunda mutlak değerce en büyük elemanın bulunduğu satır köşegene getirilir. Böylece hem sıfıra bölme önlenir hem de yuvarlama hatası azalır. Köşegende sıfır yalnız $(1, 1)$ gözünde değil, işlem sırasında sonraki köşegen gözlerinde de ortaya çıkabilir.

## 7. Doğrusal Denklem Takımları ve Yöntemlerin Sınıflandırılması

Bütün bunlar denklem takımlarını çözmek için görüldü. Elimizde $n$ bilinmeyen varsa $n$ tane de denklem olmalıdır. Slaytta denklem sayısı $m$, bilinmeyen sayısı $n$ yazılıdır, ama bunların eşit olması gerekir, yoksa katsayılar matrisi kare olmaz. Her denklem bir satırdır. Katsayılardan oluşan matris $A$ katsayılar matrisi, $X$ bilinmeyenler matrisi, $C$ eşitliğin sağ tarafındaki değerlerin matrisidir:

$$AX = C$$

### 7.1 Homojen ve Homojen Olmayan Takımlar

$C$ vektörü sıfır olabilir. Bu, eşitliklerin her birinin sıfıra eşit olması demektir. $C$'nin bütün elemanları sıfırsa takım **homojendir**. Biri bile sıfırdan farklıysa takım **homojen olmayan** bir takımdır. Örneğin biri 0, diğerleri 3 ve 5 olabilir. Dersin konusu homojen olmayan takımların çözümüdür.

### 7.2 Dolaysız ve Dolaylı Yöntemler

Homojen olmayan takımların çözümü ikiye ayrılır:

- **Dolaylı (iteratif) yöntemler:** Sonuca çok hızlı ulaşır, kolaydır, ama iteratiftir. Bir önceki adım, bir sonraki adımda mutlaka kullanılır. Hocaya göre en kolayları bunlardır.
- **Dolaysız (direkt) yöntemler:** Adı üstünde, doğrudan başlanıp sonuçlandırılır. Birbirine iteratif olarak bağlı işlemler yapılmaz. Biraz daha komplikedir. Elle işlem yapılırken hata olasılığı biraz daha yüksektir.

Her iki grupta da hesap makinesini çok iyi kullanmak gerekir.

Bazı yöntemler birbirine benzer. Bir $A$ yöntemindeki modül, $B$ yönteminin içinde de yer alır. Bu modüller ayrı ayrı yazılıp kenara konursa, hem $A$ hem $B$ yöntemini yazarken o kütüphane kullanılabilir.

Görülecek yöntemler şunlardır:

- **Dolaysız yöntemler:**
  - Cramer yöntemi.
  - Eliminasyon (yok etme) yöntemleri: Gauss eliminasyon ve Gauss-Jordan. Jordan, Gauss eliminasyonunda bir değişiklik yaparak başka bir yöntem ortaya çıkarır.
  - Cholesky yöntemi. Kompakt eliminasyon olarak geçtiği için eliminasyon yöntemlerinin içinde verilir.
- **Dolaylı yöntemler:**
  - Jacobi yöntemi.
  - Gauss-Seidel yöntemi. Jacobi üzerinde ufak bir değişiklik yapılarak ortaya atılmıştır.

### 7.3 Neden Bu Kadar Çok Yöntem Var?

Hoca bir işi yapan yöntem varken neden başka yöntemlerin geliştirildiği sorusunu programlama dilleri benzetmesiyle cevapladı. Bir dille kod yazabiliyorsak neden onlarca dil var? Hepsiyle ekrana "hello" yazılır, birinde `write`, birinde `printf` kullanılır. Ama daha kullanıcı dostu bir şey mi yazacağınıza, nasıl bir sözdizimi istediğinize, daha çok kütüphaneye ihtiyacınız olup olmadığına göre kullanacağınız dil değişir. Matematikçiler de benzer biçimde "bir şeyi daha hızlı, daha az işlemle nasıl yaparım, bu böyle de olur mu?" diye kendilerine sorular sorar ve bunları çözer. Hocaya göre biz de çok farklı bir durumda değiliz.

## 8. Cramer Yöntemi

Hocaya göre çok basit bir yöntemdir. Denklem sayısı az olmalıdır. Genelde 3-4 bilinmeyen ve 3-4 denklem varsa kullanılır, fazlası uzun sürebilir.

$A$ katsayılar matrisi ve $C$ verilsin. $C$ değerleri $A$'nın birinci sütununun yerine konur ve bu matrisin determinantı, orijinal $A$'nın determinantına oranlanırsa $x_1$ bulunur. $x_2$ için $C$ ikinci sütuna, $x_3$ için üçüncü sütuna konur:

$$x_k = \frac{|A_k|}{|A|}, \qquad A_k: A\text{'nın } k\text{. sütunu yerine } C \text{ konmuş matris}$$

Hoca "insanın inanası gelmiyor, nasıl oluyor da böyle bulunuyor?" dedi. Bunun ispatı matematikçilerin işidir. Bizim için kodu çok kolaydır: Bir determinant fonksiyonu yazılır, iki matris gönderilir, sonuçlar birbirine bölünür. Elementer hale getirme, matrisi şuna çevirme gibi işler yoktur.

> **Ek bilgi (derste anlatılmadı):** "Fazlası uzun sürer" sözünün sebebi büyük olasılıkla işlem sayısıdır. $n$ bilinmeyen için $n + 1$ determinant gerekir ve determinant kofaktör açılımıyla hesaplanırsa işlem sayısı yaklaşık $n!$ gibi büyür. Eliminasyon yöntemlerinde ise işlem sayısı büyük olasılıkla $n^3$ mertebesindedir.

### 8.1 Örnek

$$\begin{aligned} 2x_1 - 3x_2 + 2x_3 &= -11 \\ x_1 + x_2 - 2x_3 &= 8 \\ 3x_1 - 2x_2 - x_3 &= -1 \end{aligned}$$

$$A = \begin{bmatrix} 2 & -3 & 2 \\ 1 & 1 & -2 \\ 3 & -2 & -1 \end{bmatrix}, \qquad C = \begin{bmatrix} -11 \\ 8 \\ -1 \end{bmatrix}$$

**$|A|$ hesabı:** Birinci satır boyunca açılır. İşaretler sırasıyla artı, eksi, artıdır. Her elemanın satır ve sütunu silinip kalan determinant alınır:

$$|A| = 2\big[(1)(-1) - (-2)(-2)\big] - (-3)\big[(1)(-1) - (-2)(3)\big] + 2\big[(1)(-2) - (1)(3)\big]$$

$$|A| = 2(-1 - 4) + 3(-1 + 6) + 2(-2 - 3) = -10 + 15 - 10 = -5$$

**Bilinmeyenler:** Hoca devamını sözlü özetledi. $C$ birinci sütuna konur, determinantı hesaplanır, $-5$'e bölünür, $x_1$ bulunur. Sonra ikinci ve üçüncü sütun için aynısı yapılır. Determinantlar şöyledir (ara adım eklendi):

$$|A_1| = \begin{vmatrix} -11 & -3 & 2 \\ 8 & 1 & -2 \\ -1 & -2 & -1 \end{vmatrix} = -5, \quad |A_2| = \begin{vmatrix} 2 & -11 & 2 \\ 1 & 8 & -2 \\ 3 & -1 & -1 \end{vmatrix} = -15, \quad |A_3| = \begin{vmatrix} 2 & -3 & -11 \\ 1 & 1 & 8 \\ 3 & -2 & -1 \end{vmatrix} = 10$$

$$x_1 = \frac{-5}{-5} = 1, \qquad x_2 = \frac{-15}{-5} = 3, \qquad x_3 = \frac{10}{-5} = -2$$

> **Ders sonrası not:** Slayttaki matris gösteriminde $C$'nin son elemanı büyük olasılıkla $1$ yazılıydı, denklemdeki değer ise $-1$'dir. Python hesabına göre $x_1 = 1$, $x_2 = 3$, $x_3 = -2$ sonucu $-1$ ile elde edilir ve üç denklemi de sağlar.

## 9. Gauss Eliminasyon (Yok Etme) Yöntemi

Hoca eliminasyon yöntemlerini dolaysız yöntemlerin en zor, el oyalayan ve yorucu olanlarından sayıyor. Doğrusal denklem sistemlerini çözer, ama denklem sayısı ile bilinmeyen sayısının eşit olması, yani katsayılar matrisinin kare olması gerekir.

Sistem genişletilmiş katsayılar matrisi üzerinde çalışır, yani $A$ ile $C$ yan yana yazılır. Elementer satır işlemleri uygulanır. En önemli nokta şudur: $A$ katsayılar matrisi **üst üçgen matris** haline getirilir. Üst üçgen matris, köşegen ve üstünün sayılardan, altının sıfırlardan oluştuğu matristir. Aynı işlemler $C$'ye de uygulanır.

### 9.1 Neden Üst Üçgen Matris?

Gauss yok etme yönteminde matris, $i$ satır ve $j$ sütun olmak üzere birden $n$'e giden iki döngü gibi düşünülür: Dıştaki döngü satırları, içteki döngü sütunları dolaşır. Üst üçgen matris elde edildiğinde her satırda yalnız köşegen ve sağındaki katsayılar kalır:

$$a_{ii} x_i + a_{i,i+1} x_{i+1} + \cdots + a_{in} x_n = c_i$$

<!-- BELİRSİZ: Slayttaki genel gösterim altyazıda indisler sözlü okunduğu için tam okunmuyor. -->

Bunun faydası hocanın küçük örneğinde görülür:

$$\begin{bmatrix} 2 & -3 & 2 \\ 0 & 1 & -2 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 5 \\ 8 \\ 2 \end{bmatrix}$$

Çözüm sondan başa doğru yapılır:

- Son satır: $0 \cdot x + 0 \cdot y + 1 \cdot z = 2$, yani $z = 2$.
- Orta satır: $0 \cdot x + 1 \cdot y - 2 \cdot z = 8$. $z = 2$ olduğundan $y - 4 = 8$, buradan $y = 12$ (ara adım eklendi).
- İlk satır: $2x - 3y + 2z = 5$. Değerler konursa $2x - 36 + 4 = 5$, buradan $x = 18.5$ (ara adım eklendi).

Sondan yukarıya doğru çıkarak bütün değişkenler bulunmuş olur.

### 9.2 Örnek: Üst Üçgen Matrise Getirme

$$\begin{aligned} 3.6x + 2.4y - 1.8z &= 6.3 \\ 4.2x - 5.8y + 2.1z &= 7.5 \\ 0.8x + 3.5y + 6.5z &= 3.7 \end{aligned}$$

$$[A \mid C] = \left[\begin{array}{ccc|c} 3.6 & 2.4 & -1.8 & 6.3 \\ 4.2 & -5.8 & 2.1 & 7.5 \\ 0.8 & 3.5 & 6.5 & 3.7 \end{array}\right]$$

Değişkenler artık yazılmaz, hoca "hiç kalabalık yapmasın" dedi. Amaç, $a_{21}$, $a_{31}$ ve $a_{32}$'yi kesinlikle sıfır yapmaktır. Üstteki sayılar da işlem sırasında değişir. Farklı kaynaklarda farklı elementer işlemler görülebilir. Burada uygulanan kalıp aşağıdadır. Sayılar dört basamakla verilmiştir (ara adım eklendi).

**1. işlem: 1. satırı $a_{11}$'e böl.** Bütün satır 3.6'ya bölünür:

$$S_1 = (1,\ 0.6667,\ -0.5,\ 1.75)$$

**2. işlem: 2. satırı $a_{21}$'e böl, 1. satırı çıkar, sonucu $a_{21}$ ile çarp.** $a_{21} = 4.2$.

- 4.2'ye bölünür: $(1,\ -1.3810,\ 0.5,\ 1.7857)$. Böylece ilk göz 1 olur.
- **Adım 1:** satır çıkarılır: $(0,\ -2.0476,\ 1,\ 0.0357)$. İlk göz 0 olur.
- 4.2 ile çarpılır: $S_2 = (0,\ -8.6,\ 4.2,\ 0.15)$.

Hoca burada kendisine bir soru sordu: "Zaten 4.2'ye bölüp 1. satırı çıkarınca o göz sıfır oluyor, niye bir de çarpma yapıyorum?" Cevabı: "Yöntemi yapan böyle kullanmış, sen farklı bir şey kullan. Bunları sorgulamayalım, yeter ki doğru işlemleri yap."

> **Ders sonrası not:** Hoca çarpılacak $a_{21}$ için "artık sıfır olacak" dedi. Çarpımda satırın ilk gözünün yeni değeri değil, başta bölünen 4.2 kullanılır, aksi hâlde bütün satır sıfırlanırdı. Üç adımın toplamı Python hesabına göre $S_2 - a_{21} S_1$ ile aynıdır. Çarpmanın kazancı da büyük olasılıkla buradadır: $S_2$ bölünmüş hâlde kalmaz ve sonuç bu kısa işlemle doğrudan elde edilebilir. Ayrıca $a_{21}$ baştan 0 ise o satıra bölme yapılamaz, ama zaten o gözün sıfırlanması gerekmez.

**3. işlem: 3. satırı $a_{31}$'e böl, 1. satırı çıkar, sonucu $a_{31}$ ile çarp.** $a_{31} = 0.8$. Yalnız indisler değişir.

- 0.8'e bölünür: $(1,\ 4.375,\ 8.125,\ 4.625)$.
- **Adım 1:** satır çıkarılır: $(0,\ 3.7083,\ 8.625,\ 2.875)$.
- 0.8 ile çarpılır: $S_3 = (0,\ 2.9667,\ 6.9,\ 2.3)$.

$$\left[\begin{array}{ccc|c} 1 & 0.6667 & -0.5 & 1.75 \\ 0 & -8.6 & 4.2 & 0.15 \\ 0 & 2.9667 & 6.9 & 2.3 \end{array}\right]$$

**4. işlem: 2. satırı $a_{22}$'ye böl.** $-8.6$'ya bölünür:

$$S_2 = (0,\ 1,\ -0.4884,\ -0.0174)$$

**5. işlem: 3. satırı $a_{32}$'ye böl, 2. satırı çıkar, sonucu $a_{32}$ ile çarp.** $a_{32} = 2.9667$.

- 2.9667'ye bölünür: $(0,\ 1,\ 2.3258,\ 0.7753)$.
- **Adım 2:** satır çıkarılır: $(0,\ 0,\ 2.8142,\ 0.7927)$.
- 2.9667 ile çarpılır: $S_3 = (0,\ 0,\ 8.3488,\ 2.3517)$.

**6. işlem: 3. satırı $a_{33}$'e böl.** $8.3488$'e bölünür: $S_3 = (0,\ 0,\ 1,\ 0.2817)$.

Üç basamakla son durum şöyledir:

$$\begin{bmatrix} 1 & 0.667 & -0.5 \\ 0 & 1 & -0.489 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 1.75 \\ -0.017 \\ 0.281 \end{bmatrix}$$

### 9.3 Geri Yerine Koyma

Değişkenler $x$, $y$, $z$ yazılır ve sondan başa çıkılır:

- $0 \cdot x + 0 \cdot y + 1 \cdot z = 0.281$, yani $z = 0.281$.
- $0 \cdot x + 1 \cdot y - 0.489 \cdot z = -0.017$, yani $y = -0.017 + 0.489 \cdot 0.281 = 0.120$.
- $1 \cdot x + 0.667 \cdot y - 0.5 \cdot z = 1.75$, yani $x = 1.75 - 0.667 \cdot 0.120 + 0.5 \cdot 0.281 = 1.81$.

Slayttaki genel formül şudur:

$$x_i = \frac{1}{a_{ii}} \left[ c_i - \sum_{j=i+1}^{n} a_{ij} x_j \right], \qquad i = n, n-1, \ldots, 1$$

Hoca formülü örnek üzerinde çalıştırdı:

- $i = 3$ için: $x_3 = \frac{1}{a_{33}} c_3$. Toplamın alt sınırı $3 + 1 = 4$, üst sınırı 3 olduğu için toplam hiç çalışmaz. $x_3$ aslında $z$'dir.
- $i = 2$ için: $x_2 = \frac{1}{a_{22}} [c_2 - a_{23} x_3]$. $a_{22} = 1$, $c_2 = -0.017$, $a_{23} = -0.489$ alınır. $j$, 3'ten 3'e kadar gittiği için toplamda tek terim vardır ve $x_3$ yerine yukarıda bulunan $z$ yazılır. Çıkan değer $y$'dir.
- $i = 1$ için: Aynı işlem yapılır ve $x$ bulunur.

Formül, elle yapılanın aynısını yapar, ama hocaya göre elle yapmak daha temizdir: $z$ bulunur, $z$ ile çarpılıp $y$ bulunur, sonra $y$ ve $z$ kullanılarak $x$ bulunur.

> **Ders sonrası not:** Altyazıda hoca $z$ için "2.81", bir yerde "burası 0.281 değil, şurası 2.81" diyor, $c_2$ için "0.17", $a_{23}$ için "0.289" okuyor. Python hesabına göre doğrusu $z = 0.281$, $c_2 = -0.017$, $a_{23} = -0.489$'dur. Tam çözüm $x = 1.81076$, $y = 0.12013$, $z = 0.28169$'dur ve üç denklemi de sağlar. $z = 2.81$ alınsaydı $y = 1.357$ çıkardı. Hoca dersin sonundaki Gauss-Jordan slaytında da $z = 0.281$ okudu, yani 2.81 büyük olasılıkla o slayta aktarılmış bir yazım hatasıdır.

### 9.4 Tekrar Eden Kalıp

Hocanın üzerinde en çok durduğu şey, işlemlerin kalıp oluşturmasıdır. Köşegene gelince: 1. satırı $a_{11}$'e, 2. satırı $a_{22}$'ye, 3. satırı $a_{33}$'e böl. Köşegenin altına gelince: 2. satırı $a_{21}$'e böl, 1. satırı çıkar, $a_{21}$ ile çarp. Sonraki adımda 3. satırı $a_{31}$'e böl, 1. satırı çıkar, $a_{31}$ ile çarp. Yalnız indisler, yani iç döngüdeki değişkenin dönüş biçimi değişir.

> **Hocanın vurgusu:** Üst üçgen matrise geçerken yapılan elementer işlemler kitaplarda farklı olabilir, siz de farklı bir şekilde getirebilirsiniz. Burada gösterilen kalıp çok bariz olduğu için algoritmasını yazmak çok kolaydır.

## 10. Gauss-Jordan Yöntemi

Hoca yöntemi şakayla anlattı ve aralarında böyle bir konuşma geçip geçmediğini bilmediğini ekledi: Jordan Gauss'a gidip "önce sen bir çalışma yapmıştın, $A$ katsayılar matrisini üst üçgen matris haline getirmiştin ve sondan başlayarak çözmüştün. Ben bunun üzerinde farklı bir şey yaptım" der. Önerisi şudur: Elde edilen üst üçgen matrisi birim matris haline getir, bu sırada yaptığın işlemleri $C$'ye de uygula. Bu durumda sol taraf birim matris, sağ taraf sayısal değerler olur ve her satır doğrudan bir değişkenin değerini verir. Sonuç aynı örnekte $x = 1.81$, $y = 0.12$, $z = 0.281$'dir.

Bir matrisi birim matris haline getirmeyi, ters almada zaten yapmıştık. Oradaki yöntem burada da kullanılır. Birim matris yapan bir fonksiyon yazdıysak burada onu çağırırız, işlem biter.

### 10.1 Üst Üçgenden Birim Matrise

Slaytta üst üçgen matrisin elemanları için $\alpha$, sağ taraf için $\beta$ harfleri kullanılır:

$$\left[\begin{array}{ccc|c} 1 & \alpha_{12} & \alpha_{13} & \beta_1 \\ 0 & 1 & \alpha_{23} & \beta_2 \\ 0 & 0 & 1 & \beta_3 \end{array}\right]$$

Sondan başlanır:

**1. işlem: $\alpha_{23}$'ü sıfırla.** $\alpha_{23}$, 3. satırla çarpılır ($a_{33} = 1$ olduğu için 3. sütunda yine $\alpha_{23}$ çıkar) ve 2. satırdan çıkarılır. Aynı şey $C$ tarafına da uygulanır:

$$\gamma_2 = \beta_2 - \alpha_{23} \beta_3$$

Uzun uzun yazılmasın diye sonuca $\gamma_2$ adı verilir.

**2. işlem: $\alpha_{13}$'ü sıfırla.** $\alpha_{13}$, 3. satırla çarpılıp 1. satırdan çıkarılır:

$$\beta_1^* = \beta_1 - \alpha_{13} \beta_3$$

**3. işlem: $\alpha_{12}$'yi sıfırla.** $\alpha_{12}$, 2. satırla çarpılıp 1. satırdan çıkarılır:

$$\gamma_1 = \beta_1^* - \alpha_{12} \gamma_2$$

Sonuç:

$$\left[\begin{array}{ccc|c} 1 & 0 & 0 & \gamma_1 \\ 0 & 1 & 0 & \gamma_2 \\ 0 & 0 & 1 & \beta_3 \end{array}\right] \quad\Rightarrow\quad x = \gamma_1,\ y = \gamma_2,\ z = \beta_3$$

Örnekteki sayılarla (ara adım eklendi):

$$\gamma_2 = -0.017 - (-0.489)(0.281) = 0.120$$

$$\beta_1^* = 1.75 - (-0.5)(0.281) = 1.89$$

$$\gamma_1 = 1.89 - (0.667)(0.120) = 1.81$$

> **Ders sonrası not:** Hoca son işlemi anlatırken "alfa 2-2" dedi, sıfırlanan ve çarpılan eleman $\alpha_{12}$'dir. Slaytta $\beta$ ve $\gamma$ adlarının yerleri altyazıdan tam okunmuyor, yukarıdaki yazım büyük olasılıkla slayttaki gösterimle uyumludur.

### 10.2 Gauss ile Gauss-Jordan Farkı

Her iki yöntem de önce katsayılar matrisini üst üçgen matris haline getirir. Gauss eliminasyon yöntemi bundan sonra sondan başlayarak değişkenleri çözer. Gauss-Jordan yöntemi ise üst üçgen matrisi birim matris haline getirir ve her satırı kendi değişkeninin değerine eşitler.

> **Ders sonrası not:** Altyazıda "Gauss-Seidel yöntemi sondan başlayarak çözüyor" diye geçiyor. Kastedilen büyük olasılıkla Gauss eliminasyonudur, çünkü Gauss-Seidel bu derste dolaylı yöntemler arasında sayıldı. Altyazıdaki "Şaloski" adı da büyük olasılıkla Cholesky'dir. Ayrıca 7.2'de dolaylı yöntemler anlatılırken bir yerde "dolaysız yöntem ama iteratiftir" geçiyor, kastedilen dolaylı yöntemlerdir.

<!-- BELİRSİZ: Son slaytta hocanın "bu örneği siz çözebilirsiniz" diyerek geçtiği bir örnek daha var. Altyazıda sayıları okunmuyor. -->

## Dersin Toparlaması

Bu derste önce açık yöntemlerin üçüncüsü olan tekrarlama yöntemi tamamlandı. $f(x) = 0$ denklemi $x = g(x)$ biçimine getirilir, $|g'(a)| < 1$ ve $|g'(b)| < 1$ kontrol edilir, sağlanırsa $x_{i+1} = g(x_i)$ ile $|x_{i+1} - x_i| \le \varepsilon$ olana kadar devam edilir. Şart sağlanmazsa ya başka bir $g(x)$ aranır ya da aralıkta şartı sağlayan bir başlangıç değeri aranır. $x^2 - 2x - 3$ örneği, aynı fonksiyondan çıkan $g(x)$'lerin farklı köklere götürebildiğini ya da ıraksayabildiğini gösterdi.

Sonra doğrusal denklem takımlarına geçildi. Matris türleri, kofaktör ve adjoint hatırlatıldı. Elementer satır işlemlerinin sayıları değiştirip bilgiyi değiştirmediği görüldü. Bu işlemlerle Gauss-Jordan yöntemiyle matrisin tersi alındı. Dolaysız yöntemlerden Cramer, Gauss eliminasyon ve Gauss-Jordan işlendi. Cholesky yöntemi uzun olduğu için gelecek haftaya kaldı. Ardından dolaylı yöntemler (Jacobi, Gauss-Seidel), sonra sayısal integral ve türev, fark tabloları ve interpolasyon gelecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
