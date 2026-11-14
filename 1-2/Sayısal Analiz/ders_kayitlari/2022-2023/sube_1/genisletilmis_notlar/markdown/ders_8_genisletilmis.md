# Ders 8 Genişletilmiş Notu: Sonlu Farklar Tekrarı, Enterpolasyona Giriş: Doğrusal ve Eğrisel Enterpolasyon, Gregory-Newton Enterpolasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sonlu Farklar Tekrarı
- 2. Enterpolasyona Giriş
- 3. Doğrusal Enterpolasyon: Eğim Yöntemi
- 4. Doğrusal Enterpolasyon: Doğru Denklemi Yöntemi
- 5. Eğrisel (Kuadratik) Enterpolasyon
- 6. Gregory-Newton Enterpolasyonu

## 1. Sonlu Farklar Tekrarı

Bu dersin asıl konusu enterpolasyondur. Ancak enterpolasyon formüllerinde sonlu fark tablolarından gelen değerler kullanılacağı için hoca derse sonlu farkların kısa bir özetiyle başladı.

### 1.1 Sonlu Farklar Ne İşe Yarar?

Sonlu farklar matematiği, matematiğin önemli bir konusudur. Bir fonksiyonun ayrık noktalarından elde edilen değerlerle, fonksiyonun bilinmeyen bir noktadaki değerini tahmin etmek için kullanılır. Enterpolasyonda çıkaracağımız formüllerde bazı parametreler olacak. Bu parametrelerin ileri ya da geri fark olması mümkündür ve değerlerini sonlu fark tablosundan alacağız.

Elimizde $x$ değerleri ve bunlara karşılık gelen $f$ değerleri vardır. Burada iki noktayı baştan aklımızda tutmalıyız:

- **Artımlar her zaman eşit olmayabilir.** $x_0$ ile $x_1$ arasında $h$ kadar, $x_1$ ile $x_2$ arasında yine $h$ kadar artım olacak diye bir kural yoktur. $x$ değerleri arasındaki farklar birbirinden farklı olabilir. O zaman enterpolasyonda yapacağımız işlemler de değişir. En kolay durum, artımların eşit olmasıdır.
- **Başlangıç noktası sıfır olmayabilir.** $x$ değerlerinin sıfırdan başlayıp başlamaması da farklılık getirir.

Bu durumlar için ileride değişken dönüşümleri görülecek.

### 1.2 İleri Fark Operatörü ve Gösterim

Sonlu farklarda ileri, geri, ortalama ve merkezi fark operatörleri vardır. Kullanımı en kolay olan, kitaplarda genellikle tercih edilen ve hocanın da derste kullandığı operatör ileri fark operatörü $\Delta$'dır.

$x$ ekseninde bir $x$ noktasında durduğumuzu düşünelim. Bu noktanın ileri farkı sorulduğunda, fonksiyonun ilerisindeki değere bakarız. Aradaki mesafeye $h$ dersek ileri fark, fonksiyonun $x + h$'deki değeri ile $x$'teki değeri arasındaki farktır:

$$\Delta f(x) = f(x + h) - f(x)$$

Slaytlarda $f(x_0)$ yerine kısaca $f_0$, $f(x_1)$ yerine $f_1$ yazılır. İndis $i$ ise $0, 1, 2, \ldots$ diye gider. Bu gösterimle $i$. noktanın ileri farkı şöyle olur:

$$\Delta f_i = f_{i+1} - f_i$$

Örneğin $i = 0$ ise $\Delta f_0 = f_1 - f_0$'dır. Hoca bu gösterimlerin kafa karıştırmaması gerektiğini söyledi.

### 1.3 Yüksek Dereceli İleri Farklar

İkinci dereceden ileri farkı bulmak için birinci dereceden ileri farka yeniden $\Delta$ uygularız. $\Delta f_i$'nin ne olduğunu zaten biliyoruz:

$$\Delta^2 f_i = \Delta(\Delta f_i) = \Delta(f_{i+1} - f_i) = \Delta f_{i+1} - \Delta f_i$$

Burada $\Delta f_{i+1}$'in ilerisindeki değer $f_{i+2}$'dir. Yerine yazınca:

$$\Delta^2 f_i = (f_{i+2} - f_{i+1}) - (f_{i+1} - f_i) = f_{i+2} - 2f_{i+1} + f_i$$

Katsayılara bakınca binom açılımı görürüz: 1, 2, 1. İşaretler artı, eksi, artı diye gider. İndisler ise sondan başa doğru $i$, $i+1$, $i+2$ şeklinde dizilir.

> **Ders sonrası not:** Hoca burada ve fark tablosunu anlatırken birkaç kez "ikinci dereceden türev" dedi (00:11:22, 00:19:28). Söz konusu olan türev değil, ikinci dereceden ileri farktır. Hocanın "$\Delta$ ile çarpıyorum" demesi de gerçek bir çarpma değil, operatörü uygulamak anlamındadır.

Üçüncü dereceden ileri fark için ikinci dereceden ifadenin başına bir $\Delta$ daha koyar ve aynı işlemleri yaparız. Katsayılar yine binomdan gelir: 1, sonra $1 + 2 = 3$, sonra $2 + 1 = 3$, sonra 1. İşaretler artı, eksi, artı, eksidir:

$$\Delta^3 f_i = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i$$

Bu kural belli olduğu için dördüncü, beşinci ve altıncı dereceleri de rahatça yazabiliriz.

### 1.4 Geri Fark ve Merkezi Fark

Hoca geri farkı kullanmadığını, alışkanlık nedeniyle kalemin ona ters geldiğini söyledi, ama yine de hatırlattı. Bir $x$ noktasının geri farkını alırken geçmişindeki değeri, yani $x - h$'deki değeri kullanırız. Artımlar birer birer gittiği için indiste 1 çıkarılır:

$$\nabla f_i = f_i - f_{i-1}$$

Bunun ikinci ve üçüncü dereceleri de yazılabilir. Yine binom katsayıları vardır, işaretler yine artı eksi gider. Tek fark, $f_i$'nin en solda olmasıdır.

> **Ders sonrası not:** Hoca 00:12:16'da geri farkta indislerin "$i$'den başlayıp $i+1$, $i+2$ diye" gittiğini söyledi. Doğrusu, kendisinin 00:13:51-00:14:42 arasında anlattığı gibi $i$, $i-1$, $i-2$ şeklindedir.

Hoca, ileri ve geri farktaki sıralamayı tek cümleyle hatırlamanın bir yolunu verdi: **büyük olan solda**. Geri farkta $i$, $i-2$'den büyüktür ve başta yer alır. İleri farkta ise $i+3$, $i$'den büyüktür, ilerisinde olduğu için ilk sırada yazılır.

Merkezi farktan ayrıntılı bahsetmedi. Yalnızca, $x$'in iki yanından öyle noktalar alındığını söyledi ki aradaki mesafenin tamamı $h$ ise iki yandaki uzaklıklar $h/2$ olur.

### 1.5 İleri Fark İçin Genel Formül

Beşinci dereceden bir ileri fark istendiğinde $\Delta$'yı bulup tekrar tekrar uygulamakla uğraşmaya gerek yoktur. Formülün genelleştirilmiş hâli şudur:

$$\Delta^n f_i = \sum_{j=0}^{n} (-1)^j \binom{n}{j} f_{i+n-j}$$

İşaretleri $(-1)^j$ verir: $j = 0$ iken artı, $j = 1$ iken eksi diye gider. Katsayıları kombinasyon verir. $n = 5$, $i = 0$ için katsayılar 1, 5, 10, 10, 5, 1 olur. En büyük indis $i + n = 0 + 5 = 5$, en küçük indis ise $i$'dir:

$$\Delta^5 f_0 = f_5 - 5f_4 + 10f_3 - 10f_2 + 5f_1 - f_0$$

> **Ders sonrası not:** Hoca bu katsayılar için "Fibonacci sayısının katsayıları" dedi (00:16:27). Bunlar, hocanın az önce söylediği gibi binom katsayılarıdır.

### 1.6 Sonlu Fark Tabloları

"Sonlu" denmesinin sebebi tablonun bir yerde bitmesidir, sonsuza kadar gitmez. Elimizdeki $x$ girdileri ve bu girdilerle yapılan ölçümlerden alınan $f$ değerleriyle, hangi operatör olursa olsun bir fark tablosu kurarız. İleri fark için beş noktalı bir tablonun düzeni şöyledir:

| $i$ | $f_i$ | $\Delta f_i$ | $\Delta^2 f_i$ | $\Delta^3 f_i$ | $\Delta^4 f_i$ |
|---|---|---|---|---|---|
| 0 | $f_0$ | $f_1 - f_0$ | $\Delta f_1 - \Delta f_0$ | $\Delta^2 f_1 - \Delta^2 f_0$ | $\Delta^3 f_1 - \Delta^3 f_0$ |
| 1 | $f_1$ | $f_2 - f_1$ | $\Delta f_2 - \Delta f_1$ | $\Delta^2 f_2 - \Delta^2 f_1$ | |
| 2 | $f_2$ | $f_3 - f_2$ | $\Delta f_3 - \Delta f_2$ | | |
| 3 | $f_3$ | $f_4 - f_3$ | | | |
| 4 | $f_4$ | | | | |

Her sütun, bir önceki sütunda bir alttaki değerden üstteki değerin çıkarılmasıyla bulunur. Bu işleme, bir sütun sıfırlanana ya da sabit kalana kadar devam edilir. Örneğin bir sütunda hep 3 çıktıysa bir sonrakine geçmenin anlamı yoktur, çünkü 3'ten 3 çıkar 0 olur, sonrası da hep 0'dır. Bu değerler formülde çarpan olarak kullanılacağı ve sıfır çarpan terimi yok edeceği için tablo sabit sütunda bırakılabilir.

Hoca tablonun neden gerekli olduğunu bir örnekle bağladı. Bir deneyden gelen $x$ girdileri ve $f$ çıktıları olsun. "İleride $x = -2.5$'te fonksiyonun değeri ne olur?" sorulsun. Sonucun $-18$ ile $-2$ arasında bir sayı olacağını söyleyebiliriz, ama tam kaç olduğunu bilemeyiz. Bunu bulmak için bu verilerden bir fonksiyon uydurmaya çalışırız. Enterpolasyon buna yarar. Enterpolasyon yöntemlerinden Gregory-Newton'da birinci, ikinci, üçüncü, dördüncü dereceden ileri farkların başlangıç ($f_0$) değerlerine ihtiyaç vardır. Formülde $\Delta f_0$, $\Delta^2 f_0$, $\Delta^3 f_0$ geçtiğinde bunları tablonun ilk satırından alırız.

<!-- BELİRSİZ: 00:20:04 ve sonrasındaki slayt tablosunun x ve f değerleri altyazıda okunmuyor; yalnız -2.5, -18 ve -2 söyleniyor. Artımın 1 olduğu belirtiliyor. -->

Artım bu örnekteki gibi 1 olmak zorunda değildir. Sabit kalıp 5'er ya da 3'er de artabilir. Başlangıç değeri 0 olabilir de olmayabilir de. Bu şartlarda nasıl hareket edeceğimiz ileride görülecek.

### 1.7 Ölçüm Hatasının Tabloda Yayılması

Hoca son olarak, bir ölçümde yapılan $\varepsilon$ hatasının fark tablosunda nasıl yayıldığını gösterdi. Hatanın $f_3$ ölçümünde yapıldığını düşünelim. $\Delta f_2$ hesaplanırken $f_3$'ten $f_2$ çıkarıldığı için bu farkta $+\varepsilon$ fazlalık oluşur. $\Delta f_3$ hesaplanırken ise $f_4$'ten $f_3$ çıkarıldığı için $-\varepsilon$ gelir. Bu şekilde devam edince hata sütun sütun büyür ve tablonun sonunda $20\varepsilon$ kadar bir eksikliğe ulaşır.

Yedi noktalı bir tabloda hatanın yayılması aşağıdaki gibidir (ara adım eklendi). Her sütunda $\varepsilon$ katsayıları görülür, yani hata binom katsayılarıyla büyür:

| Sütun | Hata terimleri |
|---|---|
| $f_3$ | $+\varepsilon$ |
| $\Delta f_2,\ \Delta f_3$ | $+\varepsilon,\ -\varepsilon$ |
| $\Delta^2 f_1,\ \Delta^2 f_2,\ \Delta^2 f_3$ | $+\varepsilon,\ -2\varepsilon,\ +\varepsilon$ |
| $\Delta^3 f_0,\ \ldots,\ \Delta^3 f_3$ | $+\varepsilon,\ -3\varepsilon,\ +3\varepsilon,\ -\varepsilon$ |
| $\Delta^4 f_0,\ \Delta^4 f_1,\ \Delta^4 f_2$ | $-4\varepsilon,\ +6\varepsilon,\ -4\varepsilon$ |
| $\Delta^5 f_0,\ \Delta^5 f_1$ | $+10\varepsilon,\ -10\varepsilon$ |
| $\Delta^6 f_0$ | $-20\varepsilon$ |

<!-- BELİRSİZ: Slayttaki hata tablosunun boyutu altyazıda okunmuyor. Hatanın f3'te olması hocanın anlattığı +ε ve -ε adımlarından, yedi nokta varsayımı ise söylenen 20ε değerinden çıkarıldı. -->

Bu yüzden son sütun sıfıra gitmeyebilir. Bunun birkaç sebebi olabilir:

- Ölçüm sırasında yapılan bir hata.
- Ondalıklı sayılarla çalışırken noktadan sonra az basamak alıp hassasiyeti bozmak.
- Ara işlemlerde yapılan yanlışlar.

Çok büyük farklar oluşuyorsa hem ölçümler hem de adımlar kontrol edilmelidir. Küçük değerler ise o kadar önemsenmez, çünkü noktadan sonra yapılan yuvarlamalardan kaynaklanabilir.

<!-- BELİRSİZ: 00:23:29'da önemsenmeyecek değerler altyazıda "0-1" diye geçiyor; 0.1 mi 0.01 mi olduğu okunmuyor. -->

## 2. Enterpolasyona Giriş

### 2.1 Yoktan Bir Şeyi Var Etmek

Hoca enterpolasyonu ve regresyonu çok sevdiğini, çünkü bu yöntemlerde sanki yoktan bir şey var edildiğini söyledi. Slaytta bir şekil vardı: bir sürü nokta ve "bu noktalardan geçen en uygun fonksiyonu bulun" sorusu. Nokta sayısı o kadar çoktur ki her birinin üzerinden geçen bir fonksiyon bulmak mümkün değildir. Onun yerine, bu noktaları minimum hatayla sağlayan ve olabildiğince çok noktanın üzerinden geçen bir fonksiyon çıkarılır.

Şekilde bu amaçla çizilmiş birçok eğri görülüyordu. Doğrusal bir fonksiyon (kırmızı çizgilerden biri), logaritmik bir fonksiyon, üstel bir fonksiyon ya da bir polinom geçirilebilir. Bunların hepsi yaklaşık olarak birbirine benzer. Geçirilen fonksiyon bir doğru, bir parabol ya da çok dalgalanan 5., 6., 7. dereceden bir polinom olabilir.

> **Ek bilgi (derste anlatılmadı):** Hocanın bu şekil üzerinden anlattığı "her noktadan geçmek imkânsız, minimum hatayla geçen fonksiyon" durumu, kaynaklarda büyük olasılıkla regresyon ya da eğri uydurma adıyla geçer. Enterpolasyonda ise fonksiyon verilen noktaların tam üzerinden geçer, yani $F(x_i) = f_i$ olur. Bu dersteki doğru, kuadratik ve Gregory-Newton örnekleri bu ikinci türdendir.

### 2.2 Tanım

Enterpolasyon, **tablo hâlinde değerleri verilen bir değişkenin tabloda olmayan bir değerini bulma** olarak tanımlanabilir. "Tablo" sözüne takılmamak gerekir. Kastedilen, belli girdilere karşılık alınmış çıktıların elimizde olmasıdır. Hiç ölçümü yapılmamış bir $x$ değeri sorulduğunda, "ölçüm yapılsaydı hangi sonucu alırdım?" sorusunun cevabını eldeki verilerden çıkarırız.

Daha biçimsel söylersek, bir $f(x)$ fonksiyonunun $x_0, \ldots, x_n$ ayrık noktalarında alınmış $f_0, \ldots, f_n$ değerleri bilinir. Bu fonksiyonun daha basit ve bilinen bir $F(x)$ fonksiyonu ile ifade edilmesine enterpolasyon denir. $F(x)$'e de enterpolasyon fonksiyonu denir.

### 2.3 Gerçek Fonksiyon ve Enterpolasyon Fonksiyonu

Küçük $f(x)$ gerçekteki fonksiyondur. Hocanın örneği: değerler 2, 4, 6, 8, 10 diye geliyorsa gerçek fonksiyon $f(x) = 2x$'tir. $x$'e 1 verince 2, 2 verince 4, 5 verince 10 olur.

> **Ders sonrası not:** Hoca bu örnekte 2, 4, 6, 8, 10 için "$x$ değerleri" dedi (00:31:56). Devamındaki anlatıma göre bunlar $f$ değerleridir, çünkü $x = 1$ için 2, $x = 5$ için 10 elde ediliyor.

Büyük $F(x)$ ise enterpolasyonla bulduğumuz fonksiyondur. Amacımız ikisi arasındaki farkı en aza indirmektir. Fark ne kadar küçükse, uydurduğumuz fonksiyon gerçek fonksiyona o kadar yakındır. Gerçek değer ile enterpolasyon fonksiyonu arasındaki mutlak farkın, belirlediğimiz hata miktarından küçük ya da eşit olması gerekir:

$$|F(x) - f(x)| \le \varepsilon$$

### 2.4 Enterpolasyon Fonksiyonunu Seçmek

Enterpolasyon fonksiyonu kaçıncı dereceden uygun görülürse o dereceden bir polinom, $e$ üzeri bir terim içeren üstel bir ifade, trigonometrik bir fonksiyon ya da çok daha özel bir fonksiyon olabilir.

Peki hangisini seçeceğiz? İlk başta bunu bilemeyiz. Önce verinin dağılımına bakarız ve bize bir şey çağrıştırıp çağrıştırmadığını düşünürüz. Yakın hissettiğimiz fonksiyonu deneriz. Daha iyi sonuç alıp alamayacağımızı görmek için başka bir fonksiyon deneriz. En iyi sonucu hangisinde alırsak enterpolasyonu onun üzerinden yaparız.

Hocanın örneği sürekli ısı ölçen biriydi. İç ısının ve dış ısının nasıl artıp azaldığıyla sürekli ilgilenen biri zamanla bir fikir sahibi olur. İlk başlarda en başarılı sonucu hangi fonksiyondan aldıysa, ister doğru ister polinom olsun, önceliğini hep ona verir.

### 2.5 Polinom ve Trigonometrik Enterpolasyon Fonksiyonu

Hoca iki temel durumu ayırdı.

**Sürekli fonksiyon.** $f(x)$ fonksiyonu $[a, b]$ kapalı aralığında sürekli ise enterpolasyon fonksiyonu olarak bir polinom kullanılır. Yani veri bir $[a, b]$ kapalı aralığında verilmişse önceliğimiz polinomdur. Bu durumda da $|F(x) - f(x)| \le \varepsilon$ sağlanmalıdır.

> **Ek bilgi (derste anlatılmadı):** Polinom tercihinin arkasında büyük olasılıkla Weierstrass yaklaşım teoremi vardır. Bu teoreme göre kapalı bir aralıkta sürekli her fonksiyona, istenen $\varepsilon$ doğruluğunda yaklaşan bir polinom bulunabilir.

**Periyodik fonksiyon.** Periyodu $2\pi$ olan sürekli bir fonksiyon verildiyse polinom geçirmek anlamsızdır, zaten iyi bir sonuç da elde edilemez. Bu durumda kullanılacak enterpolasyon fonksiyonu şudur:

$$F(x) = \sum_{k=0}^{n} a_k \cos kx + \sum_{k=1}^{n} b_k \sin kx$$

Açılınca kosinüs tarafında $a_0$ katsayısı da vardır: $a_0 + a_1 \cos x + a_2 \cos 2x + \ldots$ Sinüs tarafında $b_0$ yoktur: $b_1 \sin x + b_2 \sin 2x + \ldots$ Amaç yine aynıdır: gerçek değerle enterpolasyon arasındaki mutlak farkın $\varepsilon$'dan küçük olması.

<!-- BELİRSİZ: 00:35:10'da hoca periyodik duruma örnek olarak "π/2 ile 3π/2 arasında" gibi bir aralık söylüyor (altyazıda "P bölü 2 ile 3P bölü 2"). Bu aralığın uzunluğu π'dir; slayttaki ifadenin tam hâli altyazıda okunmuyor. -->

Enterpolasyonun doğrusal, kübik gibi çeşitleri vardır. Doğrusal enterpolasyonun kendisi de farklı şekillerde çözülebilir. Hoca bunları bir sıra içinde anlatacağını söyledi.

## 3. Doğrusal Enterpolasyon: Eğim Yöntemi

### 3.1 Yöntem

Elimizde iki nokta olsun: $x_1$ noktasındaki değer $f(x_1)$, $x_2$ noktasındaki değer $f(x_2)$. Bize "$x_3$ verilirse $f(x_3)$ ne olur?" diye soruluyor. Konumuz doğrusal enterpolasyon olduğu için bu iki noktadan bir doğru geçirdiğimizi düşünürüz. Doğrunun denklemini bulursak $x$ yerine $x_3$ koyduğumuzda değeri elde ederiz.

Bunun en kolay yolu eğimden geçer. Eğim, oluşan dik üçgende $\tan\alpha$'dır, yani karşı kenarın komşu kenara oranıdır. Karşı kenar $f(x_2) - f(x_1)$, komşu kenar $x_2 - x_1$'dir:

$$\tan\alpha = \frac{f(x_2) - f(x_1)}{x_2 - x_1}$$

Bu değerlerin hepsi elimizde vardır. Burada bilmemiz gereken temel bilgi şudur: **Bir doğru üzerindeki bütün nokta çiftlerinin eğimi birbirine eşittir.** $x_1$ ile $x_3$ arasındaki, $x_3$ ile $x_2$ arasındaki, hatta canımız isteyip doğru üzerine koyduğumuz bir $x_4$ ile $x_3$ arasındaki eğim aynıdır.

Öyleyse bilinen iki noktanın eğimini, bilinmeyen nokta ile bilinen noktalardan birinin eğimine eşitleriz:

$$\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_3) - f(x_1)}{x_3 - x_1}$$

$x_1$ yerine $x_2$'yi de kullanabiliriz. Sonuç değişmez:

$$\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_2) - f(x_3)}{x_2 - x_3}$$

Tek bilinmeyen $f(x_3)$ olduğu için buradan doğrudan bulunur.

### 3.2 Örnek: Tablodan $f(2)$'yi Bulmak

Bir $f(x)$ fonksiyonu için $[-2, 6]$ kapalı aralığında şu değerler verilmiştir. Artımlar ne 1'dir ne de sabittir.

| $x$ | $-2$ | $-1$ | $0$ | $1$ | $3$ | $4$ | $6$ |
|---|---|---|---|---|---|---|---|
| $f(x)$ | $-0.909297$ | $-0.841471$ | $0$ | $0.841471$ | $0.141120$ | $-0.756802$ | $-0.279415$ |

<!-- BELİRSİZ: Tablonun tamamı altyazıda okunmuyor. Değerler kısa nottan alındı. Altyazı yalnız f(1) ≈ 0.84, f(3) ≈ 0.14 ve -2 ile 6 noktalarındaki değerleri ("eksi 90", "eksi 27") doğruluyor. -->

Tabloda $x = 2$ yoktur. İstenen, $f(2)$'yi doğrusal enterpolasyonla iki farklı nokta çiftiyle bulmaktır:

- a) $x = 1$ ve $x = 3$ noktalarını kullanarak.
- b) $x = -2$ ve $x = 6$ noktalarını kullanarak.

Hoca öğrencilerden önce kendi kâğıtlarında denemelerini, doğru ya da yanlış bir şey yapmaya çalışmalarını istedi. Yol şudur: önce bildiğimiz noktalar için eğimi yazarız, sonra bilinmeyen noktanın bilinen noktalardan birine göre eğimini yazar ve eşitleriz.

**Soru:** Bir öğrenci sohbet bölümünden "$f$'leri çıkarıp $x$'lerin farkına bölmüyor muyuz?" diye sordu. **Cevap:** Hoca nasıl yapıldığının anlatıldığını, önce kâğıda kendilerinin yapmasını, sonucu açtığında karşılaştırmalarını, doğru çıkmazsa neresinin anlaşılmadığını o zaman sormalarını söyledi. Çözümde de $y$'lerin farkı $x$'lerin farkına bölündü.

**a) şıkkı.** Hoca bunu önce şekille gösterdi: $x = 1$'de değer yaklaşık 0.84, $x = 3$'te yaklaşık 0.14'tür ve bu iki noktayı birleştiren doğrunun eğimini alırız:

$$\frac{f(3) - f(1)}{3 - 1} = \frac{0.141120 - 0.841471}{2} = -0.3501755$$

$x = 2$'nin eğimini 1'e göre ya da 3'e göre almak serbesttir. 1'e göre alalım:

$$\frac{f(2) - f(1)}{2 - 1} = -0.3501755$$

$$f(2) = 0.841471 - 0.3501755 = 0.4912955$$

Yani $f(2) \approx 0.49$. Hoca sonucun "illa şu aralığa gelir" denemeyeceğini de ekledi, çünkü buradaki değerler bir küçülüp bir büyüyor.

**b) şıkkı.** $f(-2) = -0.909297$, $f(6) = -0.279415$'tir. Önce iki noktanın eğimini yazarız. Sonra 2'nin eğimini ya $-2$'ye ya da 6'ya göre alırız. Hoca 6'ya göre almıştı:

$$\frac{f(6) - f(-2)}{6 - (-2)} = \frac{f(2) - f(6)}{2 - 6}$$

$$\frac{-0.279415 + 0.909297}{8} = 0.07873525 = \frac{f(2) + 0.279415}{-4}$$

$$f(2) = -0.279415 - 4 \cdot 0.07873525 = -0.594356$$

Son iki satır hocanın kurduğu denklemden çözülmüştür (ara adım eklendi).

> **Ders sonrası not:** Hoca b) şıkkı için "sonuç yine aynı sonucu verecektir" ve "farklı sonuç çıkacak diye bir şey yok" dedi (00:47:45-00:47:59). Python ile yeniden hesaplandığında a) şıkkı 0.4913, b) şıkkı $-0.5944$ veriyor, yani iki sonuç aynı değildir. Altyazıda okunan yuvarlak değerlerle de b) şıkkı büyük olasılıkla negatif çıkar. Tablo değerleri radyan cinsinden $\sin x$'e aittir (python ile hesaplandı). Bu durumda gerçek değer $\sin 2 \approx 0.9093$'tür ve iki tahmin de ondan uzaktır. Doğrusal enterpolasyon büyük olasılıkla ancak noktalar birbirine yakınsa ve fonksiyon o aralıkta doğruya benziyorsa iyi sonuç verir. Bu nedenle istenen noktaya en yakın iki noktayı kullanmak büyük olasılıkla daha doğrudur.

### 3.3 Bu Yöntemin Sınırı

> **Hocanın vurgusu:** Burası önemli. Size "bu $x$ değerlerini sağlayan $f(x)$ fonksiyonu nedir?" diye sorulursa bu yöntemi kullanamazsınız, çünkü ortada bir fonksiyon yoktur. Bu yöntem yalnızca eğim bilgisini kullanarak, merak edilen $x$ noktasında fonksiyonun alabileceği değeri tahmin eder. O kadar.

## 4. Doğrusal Enterpolasyon: Doğru Denklemi Yöntemi

### 4.1 Yöntem

Doğrunun kendisine ihtiyacımız varsa izleyeceğimiz yol farklıdır. Bu da bir doğrusal enterpolasyon yöntemidir. $x$ değişkeni $[a, b]$ kapalı aralığındadır. Enterpolasyon fonksiyonu büyük $F$ ile gösterilir ve bir doğru geçirmek istediğimiz için birinci derecedendir:

$$F(x) = Ax + B$$

Mantık şudur: Gerçek fonksiyonda $x$ yerine $a$ koyunca $f(a)$ elde ediliyorsa, enterpolasyon fonksiyonunda da $a$ koyunca bu değeri ya da buna yakın bir değeri elde etmeliyiz. $b$ için de aynısı geçerlidir. Amaç ikisinin birbirine çok çok yakın olmasıdır.

Aralığın iki ucunu yerine koyarız:

$$Aa + B = f(a), \qquad Ab + B = f(b)$$

Hoca neden büyük $F(a)$'ya değil küçük $f(a)$'ya eşitlediğimizi de açıkladı: Büyük $F$ zaten bulmaya çalıştığımız şeydir. $F(a)$'yı bilmek için $A$ ve $B$ katsayılarını bilmek gerekir. Oysa küçük $f(a)$ ve $f(b)$ elimizdedir ve $F$'in bunlara yaklaşık eşit olacağını biliyoruz.

İki bilinmeyen ($A$, $B$) ve iki denklem vardır. İkinci denklemi birincisinden çıkarınca $B$'ler gider:

$$A(a - b) = f(a) - f(b) \quad\Rightarrow\quad A = \frac{f(a) - f(b)}{a - b}$$

$A$'yı denklemlerden herhangi birinde yerine koyunca $B$ bulunur:

$$B = f(a) - a \cdot \frac{f(a) - f(b)}{a - b} = \frac{b\,f(a) - a\,f(b)}{b - a}$$

Bu sadeleştirme adımı hocanın örnekte kullandığı formüle göre yazılmıştır (ara adım eklendi). Küçük $a$, $b$, $f(a)$, $f(b)$ bilindiği için iki katsayı da hesaplanır ve elimizde örneğin $5x + 3$ gibi bir enterpolasyon fonksiyonu olur. Verilen girdileri bu fonksiyonda yerine koyduğumuzda elde edilen değerler gerçek $f$ değerlerine yaklaşık olarak eşit çıkar.

Önceki yöntemle fark burada ortaya çıkar. Artık "şu noktada değer ne olur?" sorusuna tek tek cevap vermiyoruz. Elimizde bir fonksiyon var, $x$ yerine 3, 5, 7, 113, 500, 702, ne koyarsak koyalım sonucu buluruz. Tabii bu, o noktalardan gerçekten bir doğru geçiyorsa geçerlidir.

**Soru:** Noktalardan doğru geçip geçmediğini nereden bileceğiz? **Cevap:** Elbette bilemezsiniz. İlk başta doğru, parabol, üstel ya da trigonometrik fonksiyon geçirilir. En az hatayı hangisi veriyorsa onunla yola devam edilir. Çözdüğümüz sorularda ise hangi fonksiyonun geçirileceği belirtilir, çünkü hepsini denemeye zaman yetmez.

### 4.2 Örnek: $(2, 5)$ ve $(6, 13)$ Noktaları

Hoca slaytta örnek bulunmadığı için bu örneği derste kendi kurdu. Gerçek fonksiyon $f(x) = 2x + 1$ olsun, ama bunu bilmiyormuşuz gibi davranalım. Bize yalnızca ölçümler verilmiş olsun:

| $x$ | 2 | 4 | 6 |
|---|---|---|---|
| $f(x)$ | 5 | 9 | 13 |

<!-- BELİRSİZ: 01:10:38-01:10:50 arasında hoca değerleri tahtaya yazarken altyazıda "4, 5, 9, 12 ve 13" geçiyor. Tablo, söylenen x değerleri (2, 4, 6) ve 2x+1 ile kuruldu; çözümde kullanılan 5 ve 13 altyazıda net. -->

Aralık $[a, b] = [2, 6]$'dır, yani $a = 2$, $b = 6$, $f(a) = 5$, $f(b) = 13$.

$$A = \frac{f(a) - f(b)}{a - b} = \frac{5 - 13}{2 - 6} = \frac{-8}{-4} = 2$$

$$B = \frac{b\,f(a) - a\,f(b)}{b - a} = \frac{6 \cdot 5 - 2 \cdot 13}{6 - 2} = \frac{30 - 26}{4} = 1$$

Enterpolasyon fonksiyonumuz $F(x) = 2x + 1$ çıktı. Gerçek fonksiyon da buydu. Koyduğumuz her değerde aynı sonucu elde ettiğimiz için $F(x)$ ile $f(x)$ arasındaki fark sıfırdır, yani $\varepsilon$ hatasından bile küçüktür. Hata diye bir şey yoktur.

Bundan sonra "10 nedir?" diye sorulursa $x$ yerine 10 koyarız: $F(10) = 21$. "$-5$ ise ne olur?" diye sorulursa $F(-5) = -9$ buluruz.

## 5. Eğrisel (Kuadratik) Enterpolasyon

### 5.1 Kuadratik Ne Demektir?

Kuadratik, ikinci dereceden bir fonksiyon demektir. Türkçeye "eğrisel" diye çevriliyor, ama burada kastedilen ikinci dereceden bir polinomdur:

$$y = ax^2 + bx + c$$

Kuadratik enterpolasyon için **üç nokta** gerekir. Verilen noktalar $(x_0, y_0)$, $(x_1, y_1)$, $(x_2, y_2)$ olsun. Bu üç noktadan ikinci dereceden bir polinom geçireceğiz. Fonksiyonun ne olduğunu bilmiyoruz. Sorulan da aralıktaki bir $x_3$ için $f(x_3)$'tür.

### 5.2 Birinci Yol: Denklem Sistemi

İlk yöntem doğrudandır. Noktaları denklemde sırayla yerine koyarız:

$$a x_0^2 + b x_0 + c = y_0$$

$$a x_1^2 + b x_1 + c = y_1$$

$$a x_2^2 + b x_2 + c = y_2$$

Üç denklem, üç bilinmeyen çıkar. $a$, $b$, $c$ hesaplanır ve fonksiyonda yerine konur.

Hoca bu yolu kullanmadığımızı söyledi. Sebebi derecenin artmasıdır. Onuncu dereceden bir fonksiyon için oturup denklem sistemi yazmak ve çözmek çok uzun sürer. Bunlarla uğraşılmaz. Bu yüzden başka yöntemler geliştirilmiştir.

> **Ders sonrası not:** Hoca onuncu derece için "10 denklem, 10 bilinmeyen" dedi (01:17:32, 01:18:23). İkinci derecede 3 katsayı olduğuna göre, onuncu derecede 11 katsayı, yani 11 denklem ve 11 bilinmeyen vardır.

### 5.3 İkinci Yol: $b_0, b_1, b_2$ Katsayıları

İkinci yol biraz daha karışıktır. Fonksiyon şu biçimde yazılır:

$$f(x) = b_0 + b_1(x - x_0) + b_2(x - x_0)(x - x_1)$$

Üçüncü dereceden olsaydı $b_3(x - x_0)(x - x_1)(x - x_2)$ terimi de eklenecekti. Dereceyle birlikte yeni terimler durmadan eklenir. Katsayılar şöyle hesaplanır:

- $b_0 = f(x_0)$.
- $b_1$, $x_0$ ile $x_1$ arasındaki eğimdir:

$$b_1 = \frac{f(x_1) - f(x_0)}{x_1 - x_0}$$

- $b_2$ için $x_2$ ile $x_1$ arasındaki ve $x_1$ ile $x_0$ arasındaki eğimler yazılır, farkları alınır ve $x_2 - x_0$'a bölünür:

$$b_2 = \frac{\dfrac{f(x_2) - f(x_1)}{x_2 - x_1} - \dfrac{f(x_1) - f(x_0)}{x_1 - x_0}}{x_2 - x_0}$$

> **Ders sonrası not:** Hoca 01:19:21'de "dördüncü dereceden olsaydı burası $b_3$ olacaktı" dedi. Üç çarpanlı $b_3$ terimi üçüncü dereceye karşılık gelir. Hoca da 01:23:47-01:23:56 arasında üçüncü derece için $b_3$ terimini söylüyor.

$b_3$ katsayısı olsaydı işlem daha da büyüyecekti. Ardışık eğimlerin farkları alınacak, bunların da farkı alınıp bir payda daha eklenecekti. $b_4$ geldiğinde bunlara yenileri eklenecekti. Hoca bunların akılda tutulmasının da problem olduğunu, kodunu yazsak bile aynı şeylerin defalarca hesaplanacağını söyledi. Bu külfetten kurtulmak için Gregory-Newton enterpolasyon yöntemi geliştirilmiştir.

<!-- BELİRSİZ: 01:20:28-01:21:05 arasında b3'ün açılımı sözlü ve parça parça anlatılıyor, tam formül altyazıda okunmuyor. Bu yüzden formül yazılmadı. -->

> **Ek bilgi (derste anlatılmadı):** $b_1, b_2, \ldots$ katsayıları kaynaklarda büyük olasılıkla Newton'un bölünmüş farkları adıyla geçer. Paydalarda $x$ farkları kullanıldığı için bu formüller noktalar eşit aralıklı olmasa da çalışır. Noktalar eşit aralıklıysa bu katsayılar $\dfrac{\Delta^i f_0}{i!\,h^i}$ değerine eşit olur ve formül Gregory-Newton'a dönüşür.

### 5.4 Örnek: $(1, -2)$, $(2, -1)$, $(3, 4)$ Noktaları

Bu üç noktayı kullanarak eğrisel enterpolasyon yöntemiyle ikinci dereceden polinomu bulun ve $x = 2.5$'e karşılık gelen $y$ değerini hesaplayın.

<!-- BELİRSİZ: Nokta değerleri altyazıda okunmuyor, kısa nottan alındı. Altyazı yalnız x - 1, x - 2 çarpanlarını (x0 = 1, x1 = 2) ve x = 2.5'i doğruluyor. Ara hesaplar altyazıda söylenmedi, formüllere göre eklendi. -->

Formülde $x_0 = 1$, $x_1 = 2$ yazılır:

$$f(x) = b_0 + b_1(x - 1) + b_2(x - 1)(x - 2)$$

Katsayılar (ara adım eklendi):

$$b_0 = f(x_0) = -2$$

$$b_1 = \frac{-1 - (-2)}{2 - 1} = 1$$

$$b_2 = \frac{\dfrac{4 - (-1)}{3 - 2} - \dfrac{-1 - (-2)}{2 - 1}}{3 - 1} = \frac{5 - 1}{2} = 2$$

Bulunan katsayıları yerine koyup düzenleyelim:

$$f(x) = -2 + (x - 1) + 2(x - 1)(x - 2) = 2x^2 - 5x + 1$$

Son olarak $x = 2.5$ koyarız:

$$f(2.5) = 2 \cdot 6.25 - 5 \cdot 2.5 + 1 = 12.5 - 12.5 + 1 = 1$$

Hoca bu çözümü fonksiyonu bulmak için ne kadar zahmet gerektiğini göstermek için yaptı. Burada ikinci derece yerine üçüncü derece olsaydı $b_3(x - x_0)(x - x_1)(x - x_2)$ eklenecek, bir üst derecede $b_4$ de hesaplanacak ve iş çok karışacaktı. Birazdan göreceğimiz formüllerin çıkarılışı zor gibi görünse de sonuç çok daha kolay ve etkilidir.

## 6. Gregory-Newton Enterpolasyonu

### 6.1 Ana Formül

Gregory-Newton enterpolasyon fonksiyonu şöyle başlar:

$$F(x) = f_0 + \sum_{i=1}^{n} \binom{k}{i} \Delta^i f_0$$

Toplamı açınca:

$$F(x) = f_0 + \binom{k}{1}\Delta f_0 + \binom{k}{2}\Delta^2 f_0 + \cdots + \binom{k}{n}\Delta^n f_0$$

> **Ders sonrası not:** Hoca $n$ için "kaç tane input verisi varsa o" dedi (01:24:58). Kendi örneğinde noktalar $x_0$'dan $x_6$'ya kadar yedi tanedir, yani $n$ son noktanın indisidir. Hoca ayrıca $\binom{k}{i}$ için bir yerden sonra "$k$'nın $i$. faktöriyeli" dedi (01:27:00, 01:29:28). Doğrusu, kendisinin başta söylediği gibi $k$'nın $i$'li kombinasyonudur.

Bu formülde bilmemiz gereken üç şey var:

- $f_0$: Bize verilen tablodan doğrudan alınır.
- $\Delta f_0, \Delta^2 f_0, \ldots, \Delta^n f_0$: Verilen değerlerden bir fark tablosu kurarız ve bu değerleri tablonun ilk satırından alırız.
- $\binom{k}{i}$ ve $k$: Aşağıda açılıyor.

### 6.2 Kombinasyonun Açılması

Kombinasyon şöyle tanımlanıyordu:

$$\binom{k}{i} = \frac{k!}{i!\,(k - i)!}$$

Paydaki $k!$'i, $(k - i)!$ çarpanına kadar açarsak paydadaki $(k - i)!$ ile sadeleşir. Altta yalnızca $i!$ kalır:

$$\binom{k}{i} = \frac{k(k-1)(k-2)\cdots(k-i+1)}{i!}$$

Örneğin $i = 5$ ise son çarpan $k - 5 + 1$'dir. İlk birkaç terim şöyle olur:

$$\binom{k}{1} = k$$

$$\binom{k}{2} = \frac{k(k-1)(k-2)!}{2!\,(k-2)!} = \frac{k(k-1)}{2!}$$

$$\binom{k}{3} = \frac{k(k-1)(k-2)}{3!}$$

### 6.3 $k$ Değeri ve En Genel Formül

$k$ şöyle tanımlanır:

$$k = \frac{x - x_0}{h}$$

Hoca bunu önce tablo noktaları için $k = (x_i - x_0)/h$ biçiminde yazdı, sonra $x_i$ yerine genel olarak $x$ dedi. $h$, ardışık iki $x$ arasındaki değerdir. $h = 1$ ise payda 1 olur. $h$ 2 ise 2'ye bölünür. $x$'in her adımında $h$ değişiyorsa formül çok karışır, bu durum aşağıda ele alınacak. Şimdilik artımların eşit olduğunu kabul ediyoruz.

$k$ yerine bu değeri koyalım:

$$F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{\frac{x - x_0}{h}\left(\frac{x - x_0}{h} - 1\right)}{2!}\Delta^2 f_0 + \frac{\frac{x - x_0}{h}\left(\frac{x - x_0}{h} - 1\right)\left(\frac{x - x_0}{h} - 2\right)}{3!}\Delta^3 f_0 + \cdots$$

Parantez içlerinde paydaları eşitleriz. $h$'ler paydaya iner, yani ikinci terimde $h^2$, üçüncü terimde $h^3$ olur. Paylara da $h$ ve $2h$ gelir:

$$F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_0 - h)}{2!\,h^2}\Delta^2 f_0 + \frac{(x - x_0)(x - x_0 - h)(x - x_0 - 2h)}{3!\,h^3}\Delta^3 f_0 + \cdots$$

Şimdi eksi parantezine alalım: $x - x_0 - h = x - (x_0 + h)$. $x_0 + h$ değeri $x_1$'dir. Aynı şekilde $x_0 + 2h = x_2$'dir. Böylece formülün en genel hâli çıkar:

$$F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{2!\,h^2}\Delta^2 f_0 + \frac{(x - x_0)(x - x_1)(x - x_2)}{3!\,h^3}\Delta^3 f_0 + \cdots$$

Hoca "esas gerçek formül budur" dedi, çünkü başlangıçta $x_0$'ın değerini ve $h$ artımını bilmiyoruz. Bu formülün iki parametresi şöyle davranır:

- **$x_0 \ne 0$ ise** formüldeki $x_0$'lar kaldırılamaz. Tabloda $x_0$ 5 verilmişse her yere 5 yazılır.
- **$h \ne 1$ ise** $h$'ler kaldırılamaz. Bütün artımlar 3 ise paydalara sırayla $3$, $3^2$, $3^3$, $3^4$ gelir.

### 6.4 En Basit Hâl: $x_0 = 0$ ve $h = 1$

Eğer $h = 1$ ve $x_0 = 0$ ise $h$'ler yerine 1, $x_0$ yerine 0 koyarız. $x_1 = 1$, $x_2 = 2$ olacağından formül şu hâle gelir:

$$F(x) = f_0 + x\,\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0 + \frac{x(x-1)(x-2)(x-3)}{4!}\Delta^4 f_0 + \cdots$$

Hoca bu formülü ezberlemenin ve anlamanın çok kolay olduğunu söyledi. Polinomun derecesi ne olursa olsun enterpolasyon fonksiyonu böyle yazılır. İlk çarpan grubu $x$ ile başlar, her terimde bir çarpan ($x - 1$, $x - 2$, ...) ve paydada bir faktöriyel daha eklenir.

> **Ders sonrası not:** Altyazıda bu formülün ikinci terimi "$x$ eksi $x_1$" diye geçiyor (01:36:00). Bu özel durumda $x_1 = 1$ olduğu için terim, hocanın devamda söylediği gibi $x(x - 1)$'dir.

> **Hocanın vurgusu:** Gregory-Newton enterpolasyonu çalışırken formülün nasıl çıkarıldığını bilelim, ama asıl gerekli olan son hâlidir. Başlangıç değeri sıfır ve artımlar 1 ise formülün en basit hâli kullanılır.

$h \ne 1$ ya da $x_0 \ne 0$ ise hoca karmaşık formülü kullanmak yerine bir ara işlem yapmayı tercih ediyor. Bu değişken dönüşümü tabloyu $x_0 = 0$ ve artım 1 olacak şekilde hazırlar ve basit formül kullanılır. Bu konu sonraki derslerde anlatılacak.

### 6.5 Artımlar Farklıysa

**Soru:** $h$'ler aynı değilse ne olacak? Örneğin $x$ değerleri 2, 7, 15, 16 ise farklar 5, 8, ... diye değişiyor. **Cevap:** Hoca, fark neyse ilgili yere onun yazılması gerektiğini söyledi: Fark 2 ise oraya 2, 5 ise oraya 5 yazılır. Ama bu işi çok karıştırdığı ve hataya sürüklediği için elindeki değerlere bir ara işlem yaparak $x_0$'ı 0'a, artımı da 1'e dönüştüreceğini ve en basit formülü kullanacağını ekledi.

> **Ders sonrası not:** Bu cevap dikkatle okunmalıdır. Yukarıdaki türetmede $x_0 + h = x_1$, $x_0 + 2h = x_2$ yazılabilmesi ve aynı $h$'nin kuvvetlerinin paydaya inmesi artımların eşit olmasına dayanır. Bu yüzden Gregory-Newton formülü, farklı artımları ilgili yere yazarak doğrudan kullanılamaz. $t = (x - x_0)/h$ biçimindeki doğrusal bir dönüşüm de yalnızca artımlar eşitken $x_0 = 0$, $h = 1$ tablosu verir. Eşit olmayan aralıklar için büyük olasılıkla 5.3'teki $b_i$ katsayıları ya da hocanın sonraki derste anlatacağı Lagrange enterpolasyonu gerekir.

### 6.6 Örnek: Fark Tablosu ve Üçüncü Dereceden Polinom

Bir ölçüm sonucunda şu değerler alınmıştır. Gregory-Newton enterpolasyonuyla uygun fonksiyonu bulun.

| $x$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| $f(x)$ | $-4$ | $-2$ | 14 | 62 | 160 | 326 | 578 |

**1. adım: Formülü seçmek.** Noktalar $x_0, \ldots, x_6$, değerler $f_0, \ldots, f_6$'dır. $x$'in başlangıç değeri 0, artımların hepsi 1'dir, yani $h = 1$. O hâlde formülün en basit hâlini kullanabiliriz. Bu formülde $f_0$ biliniyor, $x$ zaten fonksiyonun değişkeni. Eksik olan ileri farklardır.

**2. adım: Fark tablosu.** Birinci dereceden ileri farklar:

- $-2 - (-4) = 2$
- $14 - (-2) = 16$
- $62 - 14 = 48$
- $160 - 62 = 98$
- $326 - 160 = 166$
- $578 - 326 = 252$

Sütun sabitlenmedi ya da sıfırlanmadı, ikinci dereceye geçeriz: $16 - 2 = 14$, $48 - 16 = 32$, $98 - 48 = 50$, $166 - 98 = 68$, $252 - 166 = 86$. Yine sabit değil. Üçüncü dereceye geçeriz: $32 - 14 = 18$, $50 - 32 = 18$, $68 - 50 = 18$, $86 - 68 = 18$. Hepsi sabittir. Devam etmeye gerek yoktur, çünkü bundan sonraki sütunlar hep sıfır olur.

| $x$ | $f$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ |
|---|---|---|---|---|
| 0 | $-4$ | **2** | **14** | **18** |
| 1 | $-2$ | 16 | 32 | 18 |
| 2 | 14 | 48 | 50 | 18 |
| 3 | 62 | 98 | 68 | 18 |
| 4 | 160 | 166 | 86 | |
| 5 | 326 | 252 | | |
| 6 | 578 | | | |

İlk satırdan $f_0 = -4$, $\Delta f_0 = 2$, $\Delta^2 f_0 = 14$, $\Delta^3 f_0 = 18$ alınır.

**3. adım: Formülde yerine koymak.** Üçüncü farkta bittiği için formülü daha fazla uzatmaya gerek yoktur:

$$F(x) = f_0 + x\,\Delta f_0 + \frac{x(x-1)}{2!}\Delta^2 f_0 + \frac{x(x-1)(x-2)}{3!}\Delta^3 f_0$$

$$F(x) = -4 + 2x + \frac{x(x-1)}{2} \cdot 14 + \frac{x(x-1)(x-2)}{6} \cdot 18$$

**4. adım: Düzenlemek.** Hoca "çarptık, böldük" diyerek sonucu verdi. Ara işlemler şöyledir (ara adım eklendi):

$$F(x) = -4 + 2x + 7(x^2 - x) + 3(x^3 - 3x^2 + 2x)$$

$$F(x) = 3x^3 - 2x^2 + x - 4$$

> **Ders sonrası not:** Altyazıda sonuç "3x küp eksi 2x kare artı 4 eksi 4" diye geçiyor (01:45:09). Hocanın hemen sonraki $x = 1$ kontrolünden ve yeniden yapılan hesaptan görüldüğü gibi doğru ifade $+x$ terimini içerir: $3x^3 - 2x^2 + x - 4$.

**5. adım: Kontrol.** $x = 0$ için $-4$ çıkar. $x = 1$ için $3 - 2 + 1 - 4 = -2$ çıkar. $x = 6$ için de 578 çıkar. Hata sıfırdır. Bunun sebebi, hocanın tabloyu düzgün bir sonuç çıksın diye özellikle böyle bir fonksiyondan üretmiş olmasıdır.

> **Hocanın vurgusu:** Üçüncü sütunda ileri fark sabitlendiyse fonksiyon üçüncü dereceden olmak zorundadır. Fark tablosu bize polinomun derecesini de söyler.

> **Ek bilgi (derste anlatılmadı):** $n$. dereceden bir polinomun $n$. ileri farkı sabittir ve sonraki farkları sıfırdır, hocanın söylediği kuralın sebebi budur. Ayrıca $n + 1$ noktadan geçen en fazla $n$. dereceden polinom tektir. Bu nedenle aynı noktalara denklem sistemi, $b_i$ katsayıları ya da Gregory-Newton ile gidilse de aynı polinom bulunur.

**6. adım: Tabloda olmayan bir değer.** Hoca, biri gelip "$x = 3.5$ ise $f$ ne olur?" diye sorarsa $x$ yerine 3.5 koymak yeterlidir dedi ve bu sonuca güvenilebileceğini söyledi. Değer derste hesaplanmadı. Formülde yerine koyunca şu çıkar (ara adım eklendi):

$$F(3.5) = 3(42.875) - 2(12.25) + 3.5 - 4 = 128.625 - 24.5 + 3.5 - 4 = 103.625$$

Hoca bir kez daha hatırlattı: Başlangıç değeri sıfır ve artımlar 1 ise en basit formül kullanılır, değilse karmaşık hâli gerekir. Bunu istemiyorsak değişken dönüşümü yaparız. Bu dönüşüm $x$'i sıfırdan başlıyormuş ve değerleri arasındaki fark 1'miş gibi hazırlar, sonrasında aynı yoldan devam edilir.

## Dersin Toparlaması

Bu derste önce ileri ve geri farklar, genel formül, fark tablosu ve ölçüm hatasının tabloda binom katsayılarıyla yayılması hatırlatıldı. Ardından enterpolasyon, tabloda olmayan bir değeri eldeki ölçümlerden bulmak olarak tanımlandı. Doğrusal enterpolasyonun iki yolu görüldü: eğim yöntemi yalnızca istenen noktadaki değeri tahmin eder, doğru denklemi yöntemi ise $F(x) = Ax + B$ fonksiyonunu verir. Kuadratik enterpolasyonda denklem sistemi ve $b_0, b_1, b_2$ katsayıları incelendi. Derece arttıkça bu yolların külfetli hâle geldiği görüldü. Son olarak Gregory-Newton formülü $\binom{k}{i}$ ve $k = (x - x_0)/h$ üzerinden çıkarıldı. $x_0 = 0$, $h = 1$ durumundaki en basit hâli fark tablosuyla birlikte bir örnekte uygulandı ve üçüncü dereceden bir polinom elde edildi.

Sonraki derste Gregory-Newton'a bir örnekle devam edilecek, değişken dönüşümü ve özel durumlar anlatılacak. Ardından Lagrange enterpolasyonu ile enterpolasyon konusu bitirilecek ve regresyona geçilecek. Hoca o derse gelmeden konuya bir göz atılmasını istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
