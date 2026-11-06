# Ders 10 Genişletilmiş Notu: Gregory-Newton Enterpolasyonu (Genel Hâl ve Değişken Dönüşümü) ve Lagrange Enterpolasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Enterpolasyon Nedir?
- 2. Doğrusal Enterpolasyon
- 3. Doğrudan Polinom Uydurmanın Zahmeti
- 4. Gregory-Newton Enterpolasyonu ve En Basit Hâli
- 5. Gregory-Newton'un Genel Hâli: Başlangıç Sıfır, Artım Bir Değilse
- 6. Değişken Dönüşümü
- 7. Aynı Soru İki Yolla: Dönüşümsüz ve Dönüşümlü
- 8. Lagrange Enterpolasyonu

## 1. Enterpolasyon Nedir?

Hoca, enterpolasyonu anlatmaya başladığı dersin üzerinden iki hafta geçtiği için derse kısa bir tekrarla başladı. Enterpolasyonun başlı başına önemli bir konu olduğunu, ardından regresyonun geleceğini söyledi. Tekrarı soru-cevap biçiminde, sanki dersin üzerinden geçiyormuş gibi yaptı.

### 1.1 Ölçüm, Ara Değerler ve Fonksiyon Bulmak

Hoca tanımı öğrencilere sorarak başlattı.

**Soru:** Enterpolasyon deyince aklınıza ne geliyor? Kaba bir tarif yeter. **Cevap:** Öğrencilerden üç cevap geldi: "ortalama gibi bir şey", "eğri uydurma" ve "fonksiyonun tanımlı olmadığı bir noktada yaklaşık değerini bulmak". Hoca "ortalama" cevabını kabul etmedi, bunun tamamen farklı bir şey olduğunu söyledi. Diğer iki cevabın doğru yönde olduğunu belirtti.

Hocanın tarifi şöyledir: Bir ölçüm yapılmıştır. Verilen girdi (input) değerlerine karşılık bazı çıktı (output) değerleri alınmıştır. Ara girdi değerlerinde sonucun ne olduğunu bilmiyoruz. Verilen girdilerle onlara karşılık gelen çıktıları sağlayan fonksiyonu bulma işlemi enterpolasyondur. Böyle bir fonksiyon bulunabilirse bütün ara değerler için hiç ölçüm yapmadan, yaklaşık bir hatayla çıktı elde edilebilir.

Hocanın verdiği günlük örnek maliyetli ölçümdür. Ölçüm çok pahalı olsun ve elinizdeki bütçe yalnızca 10 ölçüme yetsin. Oysa size 100 farklı girdi değerinin sonucu gerekiyor. Bu durumda ilk 10 ölçümden fonksiyonu bulur, diğer girdileri bu fonksiyonda çalıştırarak sonuç alırsınız. Geri kalan 90 değeri ölçmeniz gerekmez.

Geçirilmek istenen fonksiyon bir doğru olabilir, ikinci, üçüncü, dördüncü dereceden bir polinom olabilir ya da doğrusal olmayan başka bir fonksiyon olabilir. Fonksiyon çeşitleri çok olduğu için farklı fonksiyonlar için ortaya atılmış farklı yöntemler vardır.

> **Hocanın vurgusu:** "Aşağıdakilerden hangisi enterpolasyonun tarifi değildir" ya da "hangisi enterpolasyonu anlatır" gibi bir soru geldiğinde enterpolasyonun ne olduğunu bilmeniz lazım. Akılda kalması gereken şey budur.

<!-- BELİRSİZ: Kayıtta yaklaşık 00:10:50 ile 00:15:43 arasında hocanın bağlantısı koptuğu için anlatım duyulmuyor. Hoca bağlantı dönünce aynı yerden yeniden başladı, bu yüzden aşağıdaki anlatımda bir içerik kaybı görünmüyor. -->

### 1.2 Gerçek Fonksiyon $f(x)$ ve Enterpolasyon Fonksiyonu $F(x)$

Elimizde $x$ değerleri ve bu değerlerde yapılmış ölçümler vardır. Bu ölçümleri sağlayan gerçek bir fonksiyon vardır, buna küçük harfle $f(x)$ diyoruz. Ama gerçek fonksiyonun ne olduğunu bilmiyoruz. Enterpolasyon yöntemleri, bu $f(x)$'i en yakın biçimde nasıl tahmin edebileceğimizi söyler. Yöntemin sonucunda çıkan tahmin fonksiyonuna da büyük harfle $F(x)$ diyoruz. Büyük $F$'nin anlamı, onun enterpolasyon sonucu çıkmış olmasıdır.

Amaç, gerçek $f(x)$ ile bulduğumuz $F(x)$ arasındaki farkı en aza indirmektir. Bu fark, belirlediğimiz hata miktarından küçük ya da ona eşit olmalıdır:

$$|F(x) - f(x)| \le \varepsilon$$

Peki nasıl bir $F(x)$ uydurabiliriz? Fonksiyon $[a, b]$ aralığında sürekliyse doğrusal enterpolasyon, Gregory-Newton enterpolasyonu ya da Lagrange enterpolasyonu kullanılabilir. Lagrange dışındakiler önceki haftalarda görülmüştü. Bazen de elimizdeki değerler sayısal değil trigonometrik olabilir. Değerler $[0, 2\pi]$ aralığında sürekliyse enterpolasyon fonksiyonu da trigonometrik bir fonksiyon olur. Burada da gerçek $f(x)$ ile enterpolasyon fonksiyonu arasındaki farka bakılır.

<!-- BELİRSİZ: Slaytta gösterilen trigonometrik enterpolasyon fonksiyonunun açık biçimi altyazıda söylenmiyor. -->

## 2. Doğrusal Enterpolasyon

Doğrusal enterpolasyonda bize bazı noktalar ve bu noktalardaki $f$ değerleri verilir ve bunlardan bir doğru geçirmemiz istenir. Bazen "doğru geçirin" diye açıkça söylenir. Bazen de $x$ değerleri öyle verilir ki çizdirdiğinizde noktaların bir doğru üzerinde olduğunu ya da doğrudan yalnızca hafif saptığını görürsünüz ve "buradan yaklaşık bir doğru geçirebilirim" dersiniz. İki yöntem vardır: eğimi kullanan yöntem ve doğru denklemini kullanan yöntem.

### 2.1 Eğim Yöntemi

Bir doğru üzerindeki herhangi iki nokta arasındaki eğim $\tan\alpha$'dır ve hangi iki noktayı alırsanız alın eğimler birbirine eşittir. Yöntem bu bilgiye dayanır.

$x_1, f(x_1)$ ve $x_2, f(x_2)$ noktaları verilmiş olsun. Eğim, karşı bölü komşudur. Karşı kenar $f(x_2) - f(x_1)$, komşu kenar $x_2 - x_1$'dir. Bunların hepsini bildiğimiz için buradan sayısal bir değer elde ederiz. Şimdi $f(x_3)$'ünü bilmediğimiz rastgele bir $x_3$ noktası alalım. $x_1$ ile $x_3$ arasındaki eğim de aynı olacağı için

$$\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_3) - f(x_1)}{x_3 - x_1}$$

yazılır. Bu eşitlikte tek bilinmeyen $f(x_3)$'tür, dolayısıyla rahatlıkla bulunur. İstenirse $x_1$ yerine $x_3$ ile $x_2$ çifti de kullanılabilir: $\frac{f(x_2) - f(x_3)}{x_2 - x_3}$ de aynı eğimi verir.

Hoca bu yöntemle önceki derste bir örnek çözüldüğünü hatırlattı. Yöntemin sakıncası şudur: Her yeni $x$ değeri için oturup eğim formülünü yeniden yazmak, değerleri yerine koymak gerekir.

<!-- BELİRSİZ: Hocanın 00:25:00 civarında hatırlattığı eğim örneğinin sayıları slaytta kalmış, altyazıda söylenmiyor. -->

### 2.2 Doğru Denklemi Yöntemi

Daha pratik yol doğrudan bir doğru geçirmektir. Çünkü bize $x_3$ sorulduktan sonra $x_4$, $x_5$ ya da $x_1$'in solunda, $x_2$'nin sağında kalan başka değerler de sorulabilir. Ayrı ayrı eğimlerle uğraşmak yerine enterpolasyon fonksiyonunu bir kez buluruz:

$$F(x) = Ax + B$$

Bir doğrunun denklemi budur, doğru birinci dereceden bir polinomdur. $A$ ve $B$'yi bulup yerine koymamız gerekir. Örneğin $A = 5$, $B = 3$ çıkarsa fonksiyon $5x + 3$ olur.

Enterpolasyon fonksiyonunun gerçek fonksiyona minimum hatayla yaklaşmasını istiyorduk. Öyleyse $[a, b]$ kapalı aralığının uçlarında $F(a) \approx f(a)$ ve $F(b) \approx f(b)$ olmalıdır. $f(a)$ ve $f(b)$ ölçümleri zaten yapılmış ve bize verilmiştir. $x$ yerine önce $a$'yı, sonra $b$'yi koyarız:

$$Aa + B = f(a), \qquad Ab + B = f(b)$$

$a$, $b$, $f(a)$, $f(b)$ bilinir. Bilinmeyenler büyük $A$ ve büyük $B$'dir. İki bilinmeyenli iki denklemi çözünce (ara adım eklendi)

$$A = \frac{f(b) - f(a)}{b - a}, \qquad B = \frac{b\,f(a) - a\,f(b)}{b - a}$$

bulunur. Bunlar $F(x) = Ax + B$'de yerine konunca tek bilinmeyen $x$ kalır. Sonra sorulan her değeri $x$ yerine yazarak sonucu alırız. Örneğin sonuç $5x + 2$ çıkmış, aralık da 1 ile 5 olsun. Bu aralığın dışındaki $x = 7$ sorulduğunda $x$ yerine 7 yazılır. Hocanın ifadesiyle, ölçüm yapmış olsaydınız yaklaşık olarak bu değeri bulacaktınız.

<!-- BELİRSİZ: Slayttaki A ve B ifadelerinin yazılışı altyazıda söylenmiyor. Yukarıdaki biçim iki denklemin çözümünden kuruldu. -->

### 2.3 Tahtada Kurulan Örnek

Hoca slaytta sayısal örnek olmadığını görünce tahtada şu tabloyu kurdu ve $[1, 3]$ kapalı aralığında bu değerlerden geçen fonksiyonun bulunmasını istedi.

| $x$ | 1 | 2 | 3 |
|:---:|:---:|:---:|:---:|
| $f(x)$ | $-2$ | $-1$ | $4$ |

Burada $a = 1$, $f(a) = -2$, $b = 3$, $f(b) = 4$'tür. Hoca çözümü burada bıraktı ve bulunan değerleri $Ax + B$ biçiminde yazıp $x = 1.5$ ya da $x = 3.5$ için yerine koymayı söyledi. Hesabı tamamlayalım (ara adım eklendi):

$$A = \frac{4 - (-2)}{3 - 1} = 3, \qquad B = \frac{3 \cdot (-2) - 1 \cdot 4}{3 - 1} = -5, \qquad F(x) = 3x - 5$$

Kontrol: $F(1) = -2$, $F(3) = 4$. Sorulan değerler için $F(1.5) = -0.5$ ve $F(3.5) = 5.5$ çıkar.

> **Ders sonrası not:** Tablodaki $x = 2$ noktası bu doğrunun üzerinde değildir: Python hesabına göre $F(2) = 1$ iken tablodaki değer $-1$'dir. Yöntem yalnızca aralığın uç noktalarını kullandığı için ortadaki ölçümü sağlamaz. Hoca tabloyu anlık kurduğu için bu büyük olasılıkla örneğin amacıyla ilgili değildir. Üç noktanın hepsinden geçmek istenirse bir sonraki bölümdeki gibi ikinci dereceden polinom gerekir.

> **Ek bilgi (derste anlatılmadı):** Hocanın sorduğu $x = 3.5$ ya da "aralık 1 ile 5 iken 7 sorulursa" durumu verilen aralığın dışındadır. Aralık dışındaki tahmine kaynaklarda büyük olasılıkla ekstrapolasyon denir. Ara değerlere göre genellikle daha riskli olduğu belirtilir, çünkü o bölgede fonksiyonu sınırlayan bir ölçüm yoktur.

## 3. Doğrudan Polinom Uydurmanın Zahmeti

Noktalardan doğru değil de ikinci dereceden bir polinom geçirmek isteseydik, yani $F(x) = ax^2 + bx + c$ yazsaydık, başlangıçta mutlaka 3 değerimizin olması gerekirdi. Polinomu $x_0$, $x_1$, $x_2$ için ayrı ayrı yazıp sırasıyla $y_0$, $y_1$, $y_2$'ye eşitleriz. Üç bilinmeyen, üç denklem olur. $a$, $b$, $c$ bulunur ve yerine konur.

Hocaya göre bu kullanışlı bir yol değildir. Yedinci dereceden bir polinom geçirilecek olsa 8 değere ihtiyaç olur, çünkü 8 bilinmeyen vardır. 8 bilinmeyen için 8 denklem kurup çözmek gerekir. Derece arttıkça bu yol oldukça maliyetli ve yorucu olur.

Denklem takımı çözmek yerine çıkarılmış formüller de vardır. Hoca bunların nasıl çıkarıldığının uzun bir hikâye olduğunu söyleyip yalnızca biçimini gösterdi. İkinci derecede ifade üç terimlidir. Üçüncü dereceden polinom için sonuna $b_3(x - x_0)(x - x_1)(x - x_2)$ eklenir, dördüncü derece için de bir sonraki terim $x - x_3$ çarpanıyla birlikte eklenir:

$$F(x) = b_0 + b_1(x - x_0) + b_2(x - x_0)(x - x_1) + b_3(x - x_0)(x - x_1)(x - x_2) + b_4(x - x_0)\cdots(x - x_3) + \ldots$$

$b_0$, $b_1$, $b_2$ kendi formülleriyle hesaplanır, $b_3$ daha karmaşık bir ifade olur. Hocanın değerlendirmesi şudur: Elle çözerken bunların hepsi hayatınızı zorlaştırır. Kod yazsanız da derece arttıkça daha çok şey hesaplamanız gerekir. Böyle bir yol olduğunu bilin ama gerçek dünyada belirli yöntemler kullanılır. Bunlardan biri Gregory-Newton enterpolasyonudur.

<!-- BELİRSİZ: Slayttaki b0, b1, b2, b3 katsayılarının formülleri altyazıda söylenmiyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu biçim kaynaklarda büyük olasılıkla Newton'un bölünmüş farklar formülü olarak geçer. $b_i$ katsayıları da bölünmüş farklardır. Gregory-Newton'un ileri fark formülü, büyük olasılıkla bu formülün eşit aralıklı noktalar için sadeleşmiş hâlidir.

## 4. Gregory-Newton Enterpolasyonu ve En Basit Hâli

### 4.1 Formül

Gregory-Newton yönteminde belirli bir aralıkta $x$ değerleri ve onlara ait $y$ değerleri verilir ve buralardan geçen enterpolasyon fonksiyonu istenir. Bunun bir doğru mu, bir polinom mu olacağını önceden bilmeyiz. Formül şudur:

$$F(x) = f_0 + \sum_{i=1}^{n} \binom{k}{i} \Delta^i f_0$$

Burada $f_0$, başlangıç noktası $x_0$'da fonksiyonun aldığı ilk değerdir. Geriye kalan terimler 1'den $n$'e kadar gider. $\binom{k}{i}$, $k$'nın $i$'li kombinasyonudur. $\Delta$ ileri fark operatörüdür: üzerinde 1 varsa birinci dereceden, 2 varsa ikinci dereceden ileri fark demektir ve fark $f_0$ noktasında alınır.

Bu ileri farklar fark tablosundan çıkarılır. Hoca önceki derste ileri, geri ve merkezî farkların görüldüğünü, en kolay kullanılan ve akılda kalan biçimin ileri fark olduğunu, bu yüzden ileri farkın kullanılacağını hatırlattı. İleri farkta her değerden bir öncekini çıkarırız: $\Delta f_i = f_{i+1} - f_i$.

### 4.2 Formülün Açılımı

Toplamı açarsak

$$F(x) = f_0 + \binom{k}{1}\Delta f_0 + \binom{k}{2}\Delta^2 f_0 + \ldots + \binom{k}{n}\Delta^n f_0$$

olur. Kombinasyonu hatırlayalım:

$$\binom{k}{i} = \frac{k!}{i!\,(k - i)!}$$

Paydaki $k!$, $k(k-1)(k-2)\cdots$ diye bire kadar açılır. Paydadaki $(k - i)!$ ile aynı olan kısım sadeleşir. Yukarıda $(k - i)$'den bir önceki çarpana kadar olan kısım kalır, aşağıda da yalnızca $i!$ kalır:

$$\binom{k}{1} = \frac{k}{1!}, \qquad \binom{k}{2} = \frac{k(k-1)}{2!}, \qquad \binom{k}{3} = \frac{k(k-1)(k-2)}{3!}, \qquad \binom{k}{4} = \frac{k(k-1)(k-2)(k-3)}{4!}$$

Hocanın verdiği pratik kural şudur: Terim kaçıncı dereceden ileri farka aitse üstte o kadar çarpan bulunur ve altta o sayının faktöriyeli yer alır. Dördüncü dereceden farkta $k, k-1, k-2, k-3$ diye dört çarpan ve $4!$ vardır.

> **Ek bilgi (derste anlatılmadı):** $k$ genellikle tam sayı değildir, çünkü ara noktalarda da hesap yapılır. Bu durumda $k!$ alışılmış anlamıyla kullanılamaz. Bu yüzden Gregory-Newton'da büyük olasılıkla kombinasyonun asıl tanımı olarak yukarıdaki çarpımlı biçim alınır.

Burada $k$ şudur:

$$k = \frac{x - x_0}{h}$$

$h$, ardışık iki $x$ değeri arasındaki mesafedir. $x_1 - x_0$, $x_2 - x_1$, $x_3 - x_2$ mesafelerinin hepsinin eşit olması beklenir. Hoca bunun her zaman böyle olmayabileceğini, ama bu formül için eşit olmasını beklediğini söyledi.

> **Ders sonrası not:** Hoca $k$'yı anlatırken "ardışık iki değer arasındaki fark bölü $h$" dedi. Doğrusu, hocanın hemen sonra yerine koyduğu gibi, $x - x_0$ farkının $h$'ye bölünmesidir. Ardışık iki değer arasındaki fark $h$'nin kendisidir.

$k$ yerine bu ifade konup paydalar düzenlenince $k - 1 = \frac{x - x_0 - h}{h} = \frac{x - x_1}{h}$ olduğu için (ara adım eklendi) formül şu hâle gelir:

$$F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{2!\,h^2}\Delta^2 f_0 + \frac{(x - x_0)(x - x_1)(x - x_2)}{3!\,h^3}\Delta^3 f_0 + \ldots$$

Bu, formülün sadeleştirilmemiş hâlidir.

### 4.3 En Basit Hâl: $x_0 = 0$ ve $h = 1$

Formül daha da basitleştirilebilir. $x$ değerleri arasındaki artım hep 1 olsun. O zaman $h$, $h^2$, $h^3$ paydalarının hepsi 1 olur ve formülden çıkar. Başlangıç değeri $x_0$ de 0 olsun. Bu durumda $x - x_0$ yalnızca $x$ olur. Değerler 0, 1, 2, 3 diye gittiği için $x - x_1$, $x - 1$; $x - x_2$ de $x - 2$ olur. Elimizde formülün en basit hâli kalır:

$$F(x) = f_0 + x\,\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0 + \frac{x(x-1)(x-2)(x-3)}{4!}\Delta^4 f_0 + \ldots$$

Bu hâl yalnızca $x$ değerleri 0'dan başlıyorsa ve artım 1 ise kullanılır. Örneğin başlangıç 5 ise $x_0$ yerine her yere 5 yazmak gerekir, $x_0$'lar formülden kalkmaz. $h$ 1 değil de örneğin 3 ise $h$'ler de formülde kalır ve her yere 3 yazılır. Bir başka seçenek de birazdan göreceğimiz değişken dönüşümüdür.

### 4.4 Örnek: Başlangıcı 0, Artımı 1 Olan Veri

$x$ değerleri 0'dan başlayıp 6'ya kadar birer birer gidiyor. $f(x)$ değerleri aşağıdaki tablonun $f$ sütunundadır. Fonksiyonu bulmak isteniyor, yani gerçek fonksiyona çok yakın olan enterpolasyon fonksiyonunu arıyoruz. Başlangıç 0, artım 1 olduğu için en basit formülü kullanabiliriz.

İlk ihtiyacımız $f_0$'dır: $x_0$'daki değer $-4$. Ayrıca $\Delta f_0$ gerekir, bu da fark tablosunu kurmayı gerektirir. Her sütunda değerlerin sabitlenip sabitlenmediğine bakarak ilerleriz.

| $x$ | $f$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ |
|:---:|:---:|:---:|:---:|:---:|
| 0 | $-4$ | 2 | 14 | 18 |
| 1 | $-2$ | 16 | 32 | 18 |
| 2 | 14 | 48 | 50 | 18 |
| 3 | 62 | 98 | 68 | 18 |
| 4 | 160 | 166 | 86 | |
| 5 | 326 | 252 | | |
| 6 | 578 | | | |

<!-- BELİRSİZ: Altyazıda f değerlerinden -4, -2, 14 ve x=4 için 160 duyuluyor, 62 ise 48 farkından çıkıyor. x=5 ve x=6 değerleri (326, 578) slaytta kalmış, kısa nottan alındı ve bulunan fonksiyonla tutuyor. Tablonun alt satırları da bu nedenle sonradan tamamlandı (ara adım eklendi). -->

İşlemler şöyledir: $-2 - (-4) = 2$, $14 - (-2) = 16$. Birinci fark sütunu sabit değildir. İkinci farklar: $16 - 2 = 14$, $48 - 16 = 32$. Yine sabit değildir. Üçüncü fark: $32 - 14 = 18$ ve sütun 18'de sabitlenir. Sıfıra kadar da gidilebilir ama bir önemi yoktur, çünkü sıfır bir çarpan olduğu için o terimler zaten sıfır olur. Demek ki formülü üçüncü dereceye kadar yazmak yeter.

> **Ders sonrası not:** Altyazıda ilk fark için "eksi 4'ten eksi 4'ü çıkardım, 2" deniyor. Doğrusu $-2 - (-4) = 2$'dir. Sonuç doğru, söyleyiş büyük olasılıkla dil sürçmesidir.

Değerleri yerine koyarız: $f_0 = -4$, $\Delta f_0 = 2$, $\Delta^2 f_0 = 14$, $\Delta^3 f_0 = 18$, $2! = 2$, $3! = 6$.

$$F(x) = -4 + 2x + \frac{x(x-1)}{2}\cdot 14 + \frac{x(x-1)(x-2)}{6}\cdot 18 = -4 + 2x + 7x(x-1) + 3x(x-1)(x-2)$$

Çarpımları açınca (ara adım eklendi):

$$F(x) = -4 + 2x + 7x^2 - 7x + 3x^3 - 9x^2 + 6x = 3x^3 - 2x^2 + x - 4$$

Bu fonksiyon, tablodaki $x$ değerleri konduğunda aynı $f$ değerlerini verir. Örneğin hocanın kontrol ettiği gibi $x = 4$ için $192 - 32 + 4 - 4 = 160$ çıkar. Yani $f(x)$ ile enterpolasyon arasındaki mutlak fark burada sıfırdır.

Hoca bunun nedenini de açıkladı: Bu değerleri verirken kendisi böyle bir fonksiyon uyduruyor ve ona şu $x$'leri verince ne çıktığını yazıyor. Amaç elle çözerken fonksiyonun kolayca bulunmasıdır. Gerçek dünyada $-4$ yerine $-3.98$, 14 yerine $14.2$ çıkabilir, ama yaklaşık olarak o değerleri vereceğini biliriz. Ölçülmemiş bir değer sorulduğunda, örneğin $x = 7$ için, $x$ yerine 7 yazılır ve hiç ölçüm yapılmadan sonuç elde edilir: $F(7) = 934$ (ara adım eklendi).

**Soru:** Başlangıç 0 olsa ama aradaki farklar 2 olsaydı ne olurdu? **Cevap:** Hoca bunun az sonra ele alınacağını söyledi. Buraya kadarki durum şudur: Başlangıç 0 ve artım 1 ise en basit formül rahatlıkla kullanılır. Bu şartlar yoksa sonraki bölümlerdeki yollara başvurulur.

### 4.5 Fark Tablosu ve Polinomun Derecesi

Enterpolasyon fonksiyonunun derecesi 3 çıktı, çünkü fark tablosu üçüncü farkta sabitlendi.

> **Hocanın vurgusu:** Bu örnekte derecenin 4 ya da 2 çıkması, soruyu yanlış yaptığınızı gösterir. Tablonun kaçıncı farkta sabitlendiği aynı zamanda fonksiyonun derecesini gösterir. Bu önemli ayrıntıyı unutmayalım.

## 5. Gregory-Newton'un Genel Hâli: Başlangıç Sıfır, Artım Bir Değilse

Şimdi şu veri verilmiş olsun ve Gregory-Newton uygulanması istensin:

| $x$ | $f$ | $\Delta f$ | $\Delta^2 f$ |
|:---:|:---:|:---:|:---:|
| 2 | 10 | 40 | 32 |
| 4 | 50 | 72 | 32 |
| 6 | 122 | 104 | 32 |
| 8 | 226 | 136 | |
| 10 | 362 | | |

En basit formülü kullanabilir miyiz? $x_0$ sıfır değil, 2'dir. Artım 1 değil, 2'dir. Artım sabittir ama 1 değildir. Öyleyse en basit hâl kullanılamaz, bir üst hâlini kullanmamız gerekir.

Önce fark tablosunu kurarız: $50 - 10 = 40$, $122 - 50 = 72$, $226 - 122 = 104$, $362 - 226 = 136$. Sabit değildir. İkinci farklar: $72 - 40 = 32$, $104 - 72 = 32$, $136 - 104 = 32$. Sabitlendi. Demek ki ikinci dereceye kadar gitmek yeter.

Hoca burada sadeleştirmenin nereden geldiğini yeniden hatırlattı. En basit hâlde $x_0 = 0$ olduğu için $x - x_0$ yerine $x$ kalıyordu. $h = 1$ olduğu için $h$'ler atılıyordu. Değerler 0, 1, 2 diye gittiği için $x - x_1$ yerine $x - 1$ yazılıyordu. Bu örnekte bunların hiçbiri yoktur, $x_0$'lar, $x_1$'ler ve $h$'ler formülde kalır:

$$F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{2!\,h^2}\Delta^2 f_0$$

Değerler: $f_0 = 10$, $x_0 = 2$, $x_1 = 4$, $h = 2$, $h^2 = 4$, $\Delta f_0 = 40$, $\Delta^2 f_0 = 32$.

$$F(x) = 10 + \frac{x - 2}{2}\cdot 40 + \frac{(x - 2)(x - 4)}{2! \cdot 4}\cdot 32$$

Hoca değerleri okurken $\Delta f_0$ için önce 10 dedi, sonra 40 olduğunu düzeltti. Sadeleştirip açınca (ara adım eklendi):

$$F(x) = 10 + 20(x - 2) + 4(x - 2)(x - 4) = 10 + 20x - 40 + 4x^2 - 24x + 32 = 4x^2 - 4x + 2$$

Fonksiyon ikinci derecedendir, çünkü tablo ikinci farkta sabitlendi. Hocanın denemesi: $x = 8$ konunca $256 - 32 + 2 = 226$ çıkar. Ölçülmemiş bir değer, örneğin $x = 3$, sorulursa $x$ yerine 3 yazılır: $F(3) = 36 - 12 + 2 = 26$ (ara adım eklendi).

<!-- BELİRSİZ: Hoca sadeleşmiş sonucu sözle söylemedi ("çarptık, böldük, bunu elde ettik"). Slayttaki yazılışı görülemedi, sonuç yukarıdaki açılımdan kuruldu ve x=8 için hocanın söylediği 226 ile tutuyor. -->

Özetle başlangıç 0 değilse ve $h$ 1 değilse $h$'ler formülden çıkarılmaz. $h$'lerin hepsi burada 2 olduğu için üsleri ve faktöriyelleri rahatça yazılır. Bir sonraki terim olsaydı $(x - x_0)(x - x_1)(x - x_2)$ çarpımı ile devam edilirdi.

## 6. Değişken Dönüşümü

### 6.1 Neden Gerekli?

Hoca önceki örneğin ardından olası bir itirazı dile getirdi: Artımlar 2 olduğu için değerleri kolayca formüle koydunuz, ama $x$ değerleri 1, 5, 7, 21 gibi olsaydı ne yapacaktık? Burada artım önce 4'tür, sonra başka bir değerdir, sonra daha büyüktür. O zaman olayın rengi değişir. Artımlar birbirinden çok farklıysa çözümü kolaylaştırmak için değişken dönüşümü kullanılır.

> **Ders sonrası not:** Hoca bu dizide ikinci artım için 3 dedi. Doğrusu $7 - 5 = 2$'dir, üçüncü artım da $21 - 7 = 14$'tür.

Fikir şudur: Başlangıç 0 değilse, artımlar 1 değilse, hatta sabit bir $h$ bile değilse formülü kullanmak çok zorlaşır. Öyleyse veriyi başlangıcı 0, artımları 1 olacak biçime dönüştürmeye çalışalım. Hocaya göre bu yolu kullanmak aslında en idealidir, çünkü karşımıza her zaman başlangıcı sıfır ya da artımları sabit değerler çıkmayabilir.

> **Hocanın vurgusu:** Burası çok önemli, çok iyi dinleyin. En azından finalde mutlaka sorarız.

Bu değerler size gerçek dünyayla ilgili bir hikâye anlatılarak da verilebilir: bir ölçümün girdileri ve çıktıları. Bu değerleri bir eksene çizmeye çalışsanız bile bir kâğıda sığdırmanız ve buradan doğru mu polinom mu geçtiğini anlamanız çok zordur. "Şunu geçirin" denmemişse her şey olabilir. Sırayla şunu deneyeyim, bunu deneyeyim demeye de gerek yoktur.

### 6.2 Yöntemin Adımları

Elimizde aşağıdaki veri olsun. Başlangıç 0 değildir, artımlar da sabit değildir.

| $x$ | $-1$ | 0 | 3 | 8 | 15 | 24 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| $f(x)$ | 2 | 1 | 10 | 65 | 226 | 577 |

<!-- BELİRSİZ: Altyazıda son f değeri (577) ile 351 ve sonrasındaki fark değerleri söylenmiyor. Bu değerler kısa nottan alındı, x^2+1 sonucuyla tutuyor. -->

Yöntem iki kez aynı işi yapmaktan ibarettir:

1. $z$ diye yeni bir değişken uydurulur. 0'dan başlar, birer artar, veri sayısı kadar değer alır. Burada 6 veri olduğu için $z = 0, 1, \ldots, 5$'tir.
2. $z$ uydurulmuş sahte bir girdi olduğu için çıktısı yoktur. Çıktı olarak orijinal $x$ değerleri yazılır. Yani $F(z) = x$ alınır.
3. Bu tablonun fark tablosu çıkarılır ($\Delta x$, $\Delta^2 x$, ...). $z$ 0'dan başlayıp birer arttığı için en basit formül uygulanır. Formülde $x$ yerine $z$, $f_0$ yerine $x_0$, $\Delta f_0$ yerine $\Delta x_0$ yazılır.
4. Çıkan ifadeden $z$, $x$ cinsinden çekilir ve bir kenara konur.
5. Orijinal $f$ değerlerine dönülür. Sanki $x$ hiç yokmuş, girdi $z$ imiş gibi fark tablosu çıkarılır ve en basit formülle $z$'ye bağlı bir **ara enterpolasyon fonksiyonu** $F(z)$ yazılır.
6. $F(z)$'de görülen her $z$ yerine 4. adımda bulunan ifade konur. Çıkan $F(x)$ aranan fonksiyondur.

### 6.3 Örneğin Çözümü

**Birinci aşama: $z$'yi $x$ cinsinden bulmak.** Sahte tablo ve farkları şöyledir:

| $z$ | $F(z) = x$ | $\Delta x$ | $\Delta^2 x$ |
|:---:|:---:|:---:|:---:|
| 0 | $-1$ | 1 | 2 |
| 1 | 0 | 3 | 2 |
| 2 | 3 | 5 | 2 |
| 3 | 8 | 7 | 2 |
| 4 | 15 | 9 | |
| 5 | 24 | | |

$0 - (-1) = 1$, $3 - 0 = 3$, $8 - 3 = 5$, $15 - 8 = 7$, $24 - 15 = 9$. Sabit değildir. İkinci farklar hep 2'dir. Ara enterpolasyon ikinci dereceden olacaktır.

Hoca formülün nasıl dönüştüğünü dikkatle gösterdi. En basit formül $x$ cinsindendi:

$$F(x) = f_0 + x\,\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0$$

Değişkenimiz artık $x$ değil $z$'dir. Çıktımız da $f$ değil $x$'tir. Bu yüzden her $x$ yerine $z$, her $f$ yerine $x$ yazılır:

$$F(z) = x = x_0 + z\,\Delta x_0 + \frac{z(z-1)}{2!}\Delta^2 x_0$$

Değerler: $x_0 = -1$, $\Delta x_0 = 1$, $\Delta^2 x_0 = 2$.

$$x = -1 + z \cdot 1 + \frac{z^2 - z}{2}\cdot 2 = -1 + z + z^2 - z = z^2 - 1$$

Artı ve eksi $z$'ler birbirini götürür. $z$'yi çekersek:

$$z = \pm\sqrt{x + 1}$$

Böylece $z$, $x$'e bağlı olarak yazılmış olur. Bu sonuç bir kenara konur.

**İkinci aşama: Orijinal $f$ değerlerinin tablosu.** Artık değişkenimiz $x$ değil $z$'dir, $z$ de 0'dan 5'e gider.

| $z$ | $f$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 2 | $-1$ | 10 | 36 | 24 |
| 1 | 1 | 9 | 46 | 60 | 24 |
| 2 | 10 | 55 | 106 | 84 | |
| 3 | 65 | 161 | 190 | | |
| 4 | 226 | 351 | | | |
| 5 | 577 | | | | |

Birinci farklar: $1 - 2 = -1$, $10 - 1 = 9$, $65 - 10 = 55$, $226 - 65 = 161$. İkinci farklar: $9 - (-1) = 10$, $55 - 9 = 46$. Üçüncü farklar 36, 60, ... Dördüncü dereceden farkta tablo 24'te sabitlenir.

> **Ders sonrası not:** Hoca tekrar sırasında $\Delta f_0$ için bir kez 1 dedi, ilk anlatımda ise doğru olarak $-1$ aldı. Doğrusu $-1$'dir. Aynı şekilde "9'dan 1'i çıkardım, 10" sözündeki işlem $9 - (-1)$'dir.

Dördüncü dereceye kadar yazarız. Burada $x$ yok, her şey $z$ cinsindendir:

$$F(z) = 2 + z(-1) + \frac{z(z-1)}{2}\cdot 10 + \frac{z(z-1)(z-2)}{6}\cdot 36 + \frac{z(z-1)(z-2)(z-3)}{24}\cdot 24$$

Çarpımları açınca (ara adım eklendi):

$$F(z) = 2 - z + 5(z^2 - z) + 6(z^3 - 3z^2 + 2z) + (z^4 - 6z^3 + 11z^2 - 6z) = z^4 - 2z^2 + 2$$

Hoca bunun bir ara enterpolasyon fonksiyonu olduğunu ve büyük $F$ ile gösterilmesi gerektiğini belirtti.

**Üçüncü aşama: $z$ yerine $x$ cinsinden ifadeyi koymak.** Girdimiz $x$ olduğu için $z$'leri $x$ cinsinden yazmalıyız. Hocaya göre artılı ya da eksili hâlden biri konabilir. $z^2 = x + 1$ olduğu için (ara adım eklendi)

$$F(x) = (x + 1)^2 - 2(x + 1) + 2 = x^2 + 2x + 1 - 2x - 2 + 2 = x^2 + 1$$

Kontrol: $x = -1$ için $1 + 1 = 2$; $x = 0$ için $0 + 1 = 1$; $x = 3$ için $9 + 1 = 10$. Sorulan başka bir değer için, örneğin $x = 18$, yine $x$ yerine 18 yazılır: $F(18) = 325$ (ara adım eklendi).

> **Ders sonrası not:** Hocanın "artılı ya da eksili fark etmez" sözü bu örnekte doğrudur, çünkü $F(z)$'de yalnızca $z$'nin çift kuvvetleri vardır. Bu genel bir kural değildir. Verideki $z$ değerleri 0 ve pozitif olduğu için güvenli seçim büyük olasılıkla artılı köktür. Bölüm 8.3'teki veride Python hesabına göre eksili kök verilen noktaları sağlamaz.

### 6.4 Sonuç Neden Dördüncü Dereceden Değil?

Ara fonksiyon dördüncü dereceden çıktığı hâlde son fonksiyon ikinci derecedendir. Hoca bunu değişken dönüşümüyle açıkladı: Çözüm $z$'ye bağlı yapılmıştır ve $z$ ile $x$ arasındaki bağıntıda ikinci derece vardır. $z^4$ ve $z^2$ terimleri $x + 1$ üzerinden yazılınca ikinci dereceden bir fonksiyon kalır.

### 6.5 Hocanın Özeti

Hoca adımları bir kez daha, yalnızca $x$ ve $f(x)$ verilmiş gibi baştan anlattı. Gregory'yi kullanmak isterim ama $x$'in başlangıcı sıfır değil, artımlar da sabit değil. Öyleyse bir $z$ değişkeni uydururum, 0'dan başlar, veri sayısı kadar birer artar. Bu girdi sahte olduğu için çıktısı olarak gerçek girdiler olan $x$'leri veririm. Bu tablonun enterpolasyonundan $z$'yi $x$ cinsinden bulur ve bir kenara koyarım. Çünkü artık $x$ diye bir değişkenim yoktur, $z$ vardır. Sonra orijinal verilere dönerim, ara enterpolasyonu $z$ cinsinden yazarım ve her $z$ yerine bulduğum ifadeyi koyarım. Karşıma çıkan $F(x)$ aradığım fonksiyondur.

> **Ders sonrası not:** Hoca bu yolun artımlar birbirinden çok farklı olduğunda da kullanılacağını söyledi. Bunun iki sınırı büyük olasılıkla göz önünde tutulmalıdır. Birincisi, $x(z)$ üçüncü dereceden çıkarsa $z$'yi çekmek elle zorlaşır: 1, 5, 7, 21 dizisinin farkları 4, 2, 14; sonra $-2$, 12; sonra 14'tür, yani dizi ancak üçüncü derecede sabitlenir. İkincisi, $x(z)$ doğrusal değilse sonuç her zaman polinom olmayabilir. Bölüm 8.3'te bunun bu dersin verisindeki bir örneği var.

## 7. Aynı Soru İki Yolla: Dönüşümsüz ve Dönüşümlü

Hoca şu veriyi verdi ve soruyu hem değişken dönüşümü kullanmadan hem de kullanarak çözmeyi istedi. İki yolun aynı sonucu vermesi gerekir.

| $x$ | 2 | 4 | 6 | 8 | 10 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| $f(x)$ | 3 | 7 | 19 | 39 | 67 |

Başlangıç 0 olmadığı ve artımlar 1 olmadığı için en basit formül kullanılamaz. Değişken dönüşümü kullanılabilir. Başlangıç sıfır olmasa bile artımlar sabit olduğu için sadeleştirilmemiş formül de kullanılabilir.

Fark tablosu iki yolda da aynıdır: $7 - 3 = 4$, $19 - 7 = 12$, $39 - 19 = 20$, $67 - 39 = 28$. İkinci farklar $12 - 4 = 8$, $20 - 12 = 8$ diye sabitlenir.

| $f$ | $\Delta f$ | $\Delta^2 f$ |
|:---:|:---:|:---:|
| 3 | 4 | 8 |
| 7 | 12 | 8 |
| 19 | 20 | 8 |
| 39 | 28 | |
| 67 | | |

### 7.1 Birinci Yol: Değişken Dönüşümü Olmadan

Sıfırdan başlamıyor ama $h$'ler hep 2. Sadeleştirilmemiş formül:

$$F(x) = f_0 + \frac{x - x_0}{h^1}\cdot\frac{\Delta f_0}{1!} + \frac{(x - x_0)(x - x_1)}{h^2}\cdot\frac{\Delta^2 f_0}{2!}$$

Değerler: $f_0 = 3$, $x_0 = 2$, $x_1 = 4$, $h = 2$, $\Delta f_0 = 4$, $\Delta^2 f_0 = 8$.

$$F(x) = 3 + \frac{x - 2}{2}\cdot 4 + \frac{(x - 2)(x - 4)}{4}\cdot\frac{8}{2} = 3 + 2(x - 2) + (x - 2)(x - 4)$$

$$F(x) = 3 + 2x - 4 + x^2 - 6x + 8 = x^2 - 4x + 7$$

Hoca tahtada açarken önce baştaki 3'ü toplamayı unuttu. $x = 2$ koyunca 3 yerine 0 çıkınca hatasını aradı ve eksik terimi buldu.

Kontrol: $x = 2$ için $4 - 8 + 7 = 3$; $x = 4$ için $16 - 16 + 7 = 7$. Hoca artımlar sabit olmasaydı bu formülün de kullanılamayacağını hatırlattı.

### 7.2 İkinci Yol: Değişken Dönüşümü ile

Hoca burada öğrencilere birkaç dakika vererek birinci aşamayı kendilerinin yapmasını istedi: $z$'yi alın, $F(z)$ olarak $x$'i alın ve $z$'yi $x$ cinsinden bulun.

**Birinci aşama.** $z = 0, 1, 2, 3, 4$ alınır, $F(z) = x$ değerleri 2, 4, 6, 8, 10'dur. Farklar: $4 - 2 = 2$, $6 - 4 = 2$, $8 - 6 = 2$, $10 - 8 = 2$. Sütun hemen sabitlenir, birinci dereceden fark yeter. En basit formülde $f_0$ yerine $x_0$, $x$ yerine $z$, $\Delta f_0$ yerine $\Delta x_0$ yazılır:

$$F(z) = x = x_0 + z\,\Delta x_0 = 2 + 2z$$

Buradan $z$ çekilir:

$$z = \frac{x - 2}{2}$$

**İkinci aşama.** Sanki $x$ hiç yokmuş, girdi $z$ imiş gibi orijinal $f$ değerleriyle ara enterpolasyon yazılır:

$$F(z) = f_0 + z\,\Delta f_0 + \frac{z(z-1)}{2!}\Delta^2 f_0 = 3 + 4z + \frac{z^2 - z}{2}\cdot 8 = 3 + 4z + 4z^2 - 4z = 4z^2 + 3$$

**Üçüncü aşama.** Her $z$ yerine $\frac{x - 2}{2}$ konur:

$$F(x) = 4\left(\frac{x - 2}{2}\right)^2 + 3 = (x - 2)^2 + 3 = x^2 - 4x + 7$$

Sonuç birinci yolla aynıdır. Kontrol: $x = 2$ için $4 - 8 + 7 = 3$; $x = 4$ için 7; $x = 10$ için $100 - 40 + 7 = 67$.

> **Hocanın vurgusu:** Bu iki örneği slaytlara hiç bakmadan kendiniz çözün. Hiçbir zor tarafı yok, iki kez aynı işlemi yapıyorsunuz. Birinde $z$ değerlerine çıktı olarak $x$'i koyup bir polinom elde ediyor ve $z$'yi $x$ cinsinden yazıyorsunuz. Diğerinde her şey $z$'ymiş gibi verilen çıktılarla enterpolasyonu yazıyorsunuz. Son aşamada da ilkinde bulduğunuz ifadeyi yerine koyuyorsunuz.

## 8. Lagrange Enterpolasyonu

Hoca Lagrange'a geçmeden önce kendi görüşünü de söyledi: Bu yöntem çok daha basittir ama ona göre elle çözerken hata yapmaya daha yatkındır. Kodunu yazarsak hiçbirinde hata olmaz, elle çözdüğümüzde ise bunda hata yapma olasılığımız daha yüksektir. Örneklerde dört beş girdi varken her şey kolay görünür, ama gerçekte örnek sayısı her zaman o kadar az olmaz.

### 8.1 Formül

Lagrange de bir matematikçinin soyadıdır. Durum yine aynıdır: Bilmediğimiz bir $f(x)$ fonksiyonunun $x_0, \ldots, x_n$ gibi ayrı noktalarda ölçülmüş $y_0, \ldots, y_n$ değerleri vardır.

> **Hocanın vurgusu:** Bu noktaların aralıkları eşit olsun ya da olmasın hiçbir önemi yoktur. $x$ değerleri arasındaki fark 1 olmuş, hep eşit olmuş ya da farklı olmuş, hep aynı şey kullanılır. Bu çok önemli.

Lagrange'ta enterpolasyon fonksiyonuna $g(x)$ diyoruz, Gregory-Newton'dakine $F(x)$ diyorduk:

$$g(x) = \sum_{i=0}^{n} L_i(x)\,y_i$$

$y_i$, $x_i$'ye karşılık ölçülmüş değerdir. $L$ harfi Lagrange'ın L'sidir. Her girdi için ayrı bir **Lagrange katsayısı** vardır. Önce bu katsayılar bulunur, sonra her örneğin katsayısı kendi $y_i$'siyle çarpılır, bunların toplamı da enterpolasyon fonksiyonunu verir. $y_i$'ler elimizde olduğuna göre hesaplanması gereken $L_i$'lerdir:

$$L_i(x) = \prod_{\substack{j=0 \\ j \ne i}}^{n} \frac{x - x_j}{x_i - x_j}$$

Sıfırdan başlandığı için $n + 1$ tane veri vardır ve toplam $n$'e kadar gider. Örneğin $n = 3$ ise $L_0$, $L_1$, $L_2$, $L_3$ hesaplanır.

### 8.2 $j \ne i$ Şartı

Hoca şartın anlamını $n = 2$ için çarpımı açarak gösterdi. Şartı bir an unutup $j$'yi 0'dan 2'ye kadar yazarsak:

$$\frac{x - x_0}{x_i - x_0} \cdot \frac{x - x_1}{x_i - x_1} \cdot \frac{x - x_2}{x_i - x_2}$$

Diyelim ki $L_1$'i hesaplıyoruz, yani $i = 1$. $j = 1$ olan çarpanın paydası $x_1 - x_1 = 0$ olur. Bu yüzden $j$'nin $i$'ye eşit olduğu çarpan alınmaz. $L_1$'de orta çarpan atılır, $L_0$'da ilk çarpan, $L_2$'de son çarpan.

> **Ders sonrası not:** Hoca bir yerde paydanın sıfır olması durumunda "bütün çarpan sıfır olur" dedi, sonra sebebin "paydanın sıfır olmaması" olduğunu söyledi. Doğrusu ikincisidir: Payda sıfır olursa çarpım sıfır olmaz, bölme tanımsız olur.

Hesabı yaparken formülü şöyle hatırlamak gerekir: Üstte $x - x_j$, altta $x_i - x_j$ vardır. $x_i$, Lagrange katsayısının kaçıncısını hesapladığımızı, $x_j$ de sırayla diğer örnekleri gösterir.

> **Hocanın vurgusu:** Lagrange'ın el yormak dışında zor bir tarafı yok. Önemli olan bunları yazarken sırayı şaşırmamaktır.

### 8.3 Örnek 1: Üç Nokta

Fonksiyonun ne olduğu bilinmiyor. Değerler şöyle:

| $x$ | 0 | 1 | 3 |
|:---:|:---:|:---:|:---:|
| $y$ | $-5$ | 1 | 25 |

Üç veri olduğu için $i$ 0'dan başlar, $n = 2$'dir.

$$g(x) = \sum_{i=0}^{2} L_i(x)\,y_i$$

$y_i$'ler bilindiği için $L_i$'leri hesaplarız. $x_0 = 0$, $x_1 = 1$, $x_2 = 3$.

$i = 0$ için ilk çarpan atılır:

$$L_0(x) = \frac{x - x_1}{x_0 - x_1}\cdot\frac{x - x_2}{x_0 - x_2} = \frac{(x - 1)(x - 3)}{(0 - 1)(0 - 3)} = \frac{1}{3}(x - 1)(x - 3)$$

$i = 1$ için ikinci çarpan atılır:

$$L_1(x) = \frac{x - x_0}{x_1 - x_0}\cdot\frac{x - x_2}{x_1 - x_2} = \frac{(x - 0)(x - 3)}{(1 - 0)(1 - 3)} = -\frac{1}{2}(x^2 - 3x)$$

$i = 2$ için son çarpan atılır:

$$L_2(x) = \frac{x - x_0}{x_2 - x_0}\cdot\frac{x - x_1}{x_2 - x_1} = \frac{(x - 0)(x - 1)}{(3 - 0)(3 - 1)} = \frac{1}{6}(x^2 - x)$$

Bunları kendi $y_i$'leriyle çarpıp toplarız:

$$g(x) = \frac{1}{3}(x - 1)(x - 3)(-5) - \frac{1}{2}(x^2 - 3x)(1) + \frac{1}{6}(x^2 - x)(25)$$

Terimleri topladığımızda (ara adım eklendi) $x^2$ katsayısı $-\frac{5}{3} - \frac{1}{2} + \frac{25}{6} = 2$, $x$ katsayısı $\frac{20}{3} + \frac{3}{2} - \frac{25}{6} = 4$, sabit terim $-5$ olur:

$$g(x) = 2x^2 + 4x - 5$$

Tabloda $x = 2$ yok. "2 ne olur?" diye sorulduğunda $x$ yerine 2 koyarız: $8 + 8 - 5 = 11$.

> **Ders sonrası not:** Hoca, bu veri Gregory-Newton ile sorulsaydı "ya değişken dönüşümünü kullanırdın ya da başlangıç 0, artımlar 2 olduğu için orijinal formülü kullanırdın" dedi. Burada $x$ değerleri 0, 1, 3'tür, artımlar 1 ve 2'dir, yani sabit değildir. Bu yüzden sabit $h$ isteyen formül doğrudan kullanılamaz.

> **Ders sonrası not:** Aynı veriye değişken dönüşümü uygulanırsa Python hesabına göre $x = \frac{z^2 + z}{2}$ ve $F(z) = 9z^2 - 3z - 5$ çıkar. Artılı kök $z = \frac{-1 + \sqrt{1 + 8x}}{2}$ konunca sonuç $F(x) = 18x + 1 - 6\sqrt{1 + 8x}$ olur. Bu fonksiyon 0, 1, 3 noktalarında $-5$, 1, 25 verir, ama polinom değildir ve $x = 2$ için yaklaşık $12.26$ verir, $g(2) = 11$ ile aynı değildir. Yani dönüşüm, $x(z)$ doğrusal değilse büyük olasılıkla aynı polinomu vermez. Bölüm 6'daki $x^2 + 1$ örneğinde polinom çıkması, $F(z)$'nin yalnız çift kuvvetler içermesindendir.

### 8.4 Neden Zahmetli?

Hoca yöntemin zahmetini şöyle anlattı: 10 değeriniz varsa 10 tane $L$ hesaplarsınız ve her birini çarparsınız. 50 elemanlıysa 50 tane yaparsınız. Oysa Gregory-Newton'da 50 girdi olsa bile belki üçüncü dereceden farkta tablo sabitlenir ve çok fazla işlem gerekmez. Lagrange'ta ise verilen girdi sayısı kadar $L$ hesaplanır, bunlar sayılarla çarpılır, sonra kendi aralarında çarpılıp toplanarak $g$ elde edilir.

Hoca buna "belki de ben hep hata yapıyorum" diye ekleyerek, Gregory'nin daha yakın sonuç verdiğini ve kendisine göre daha hızlı çözüme ulaştırdığını söyledi.

> **Ders sonrası not:** "Gregory daha yakın sonuç verir" ifadesi hesap kolaylığı açısından anlaşılmalıdır. Aynı noktaların tamamı kullanılırsa iki yöntem aynı polinomu bulur: Python hesabına göre Bölüm 7'deki veriye Lagrange uygulanınca yine $x^2 - 4x + 7$ çıkar. Fark büyük olasılıkla elle hesapta yapılan hatalardan gelir. Hocanın kendi sözü de buna işaret ediyor: Kod yazıldığında bu hatalar olmaz.

> **Ek bilgi (derste anlatılmadı):** $n + 1$ farklı noktadan geçen ve derecesi en fazla $n$ olan polinom büyük olasılıkla kaynaklarda "tek" olarak verilir. Gregory-Newton ve Lagrange aynı polinomun iki ayrı yazılışıdır. Farklar sonuçta değil, hesabın düzenindedir. Bölüm 8.3'te değişken dönüşümünden çıkan polinom dışı sonuç bu tekliğin kapsamına girmez.

### 8.5 Örnek 2: Dört Nokta

Hoca ikinci örneği slayttan gösterdi ve ayrıntılarına girmedi.

| $x$ | 3 | 7 | 15 | 22 |
|:---:|:---:|:---:|:---:|:---:|
| $y$ | 1 | $-8$ | $-22$ | $-9$ |

<!-- BELİRSİZ: Bu örneğin x ve y değerleri altyazıda söylenmiyor, yalnızca n=3 olduğu ve dört L hesaplandığı duyuluyor. Değerler ile x=4 ve x=10 noktaları kısa nottan alındı. -->

Dört örnek vardır: indisler 0, 1, 2, 3 olduğu için $n = 3$'tür.

$$g(x) = \sum_{i=0}^{3} L_i(x)\,y_i$$

Her $L_i$'de $j = i$ çarpanı atılır. Paydalar (ara adım eklendi):

- $L_0$ için $(3-7)(3-15)(3-22) = -912$
- $L_1$ için $(7-3)(7-15)(7-22) = 480$
- $L_2$ için $(15-3)(15-7)(15-22) = -672$
- $L_3$ için $(22-3)(22-7)(22-15) = 1995$

Buradan:

$$L_0(x) = -\frac{(x-7)(x-15)(x-22)}{912}, \qquad L_1(x) = \frac{(x-3)(x-15)(x-22)}{480}$$

$$L_2(x) = -\frac{(x-3)(x-7)(x-22)}{672}, \qquad L_3(x) = \frac{(x-3)(x-7)(x-15)}{1995}$$

ve $g(x) = L_0(x) \cdot 1 + L_1(x) \cdot (-8) + L_2(x) \cdot (-22) + L_3(x) \cdot (-9)$ bulunur.

> **Hocanın vurgusu:** Bunu elle yapmaya kalkarsak kesinlikle hata yaparız, ben de hata yaparım. Yanlış bir tuşa basın, bir şeyi yanlış toplayın, bulacağınız $g$ fonksiyonu hatalı çıkar ve sonra hangi değeri verirseniz verin hep hatalı sonuç döner. Kodunu yazarsam bu hatalar olmaz, ama elle yaparken çok dikkatli olmamız gerekir.

Python hesabına göre $x = 4$ için katsayılar $L_0 = 0.651316$, $L_1 = 0.4125$, $L_2 = -0.080357$, $L_3 = 0.016541$'dir ve $g(4) = -1.029699$ çıkar. $x = 10$ için katsayılar $-0.197368$, $0.875$, $0.375$, $-0.052632$'dir ve $g(10) = -14.973684$ olur.

> **Ders sonrası not:** Kısa nota göre slaytta $g(4)$ için $-1.0296854$ yazıyor. Python hesabına göre kesin değer $-\frac{2739}{2660} = -1.0296992\ldots$'dir. Fark büyük olasılıkla ara yuvarlamadan gelir. Slayttaki değer altyazıda doğrulanamadı.

## Dersin Toparlaması

Enterpolasyon, belirli $x$ değerlerine karşılık yapılmış ölçümlerden yola çıkarak ölçüm dışındaki değerleri tahmin etmektir. Ne kadar uygun bir eğri uydurulursa o kadar yakın sonuç elde edilir. Bu derste doğru geçirmenin iki yolunu gördük: noktaların eğiminden bilinmeyen noktadaki $y$'yi bulmak ya da doğrunun $A$ ve $B$ katsayılarını bulmak. Polinom geçirirken Gregory-Newton kullanılır: Başlangıç 0 ve artım 1 ise en basit formül, artımlar sabitse sadeleştirilmemiş formül, değilse değişken dönüşümü. Son olarak $x$ aralıklarının hiçbir önemi olmayan Lagrange enterpolasyonunu gördük.

> **Ders sonrası not:** Hoca son özette en basit hâl için "başlangıç sıfır ve artım iki" dedi. Doğrusu, dersin geri kalanında söylediği gibi, başlangıç sıfır ve artım birdir.

Önümüzdeki hafta regresyon görülecektir. Regresyon da bir eğri uydurur, ama enterpolasyona göre daha yaklaşık uydurur: $f(x)$ ile $F(x)$ arasındaki fark daha fazla olabilir. Hoca ayrıca bu derste doğrusal olmayan bir fonksiyon çıkarmadığını, regresyonda doğrusal olmayan fonksiyonların da uydurulabileceğini söyledi.

> **Ders sonrası not:** $x^2 + 1$ gibi polinomlar $x$'e göre doğrusal değildir. Hocanın "doğrusal olmayan" derken burada büyük olasılıkla polinom dışındaki, üstel ya da logaritmik türden fonksiyonları kastettiği düşünülebilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
