# Ders 2 Genişletilmiş Notu: Taylor Serisinin Genelleştirilmesi, Kesme-Bağıl-Mutlak Hata, Ortalama ve Ara Değer Teoremleri, Kök Bulmaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Haftanın Özeti: Taylor ve Maclaurin Serileri
- 2. Taylor Serisinin Kapalı Gösterimi
- 3. Türevleri Genelleştirmek: Üç Örnek
- 4. Kesme Hatası
- 5. Bağıl Hata
- 6. Mutlak Hata
- 7. Yuvarlama Hatası
- 8. Doğrusal Olmayan Denklemler
- 9. Kapalı ve Açık Yöntemler
- 10. Ortalama Değer Teoremi
- 11. Ara Değer Teoremi ve Köklerin Varlığı
- 12. Süreklilik, Parçalı Fonksiyonlar ve Limit
- 13. İteratif Yöntemlerde Durma Ölçütü
- 14. Dersin Sonundaki Sorular

## 1. Geçen Haftanın Özeti: Taylor ve Maclaurin Serileri

### 1.1 Seriye Neden İhtiyaç Duyuyoruz?

Geçen hafta bir öğrenci Taylor serisini neden gördüğümüzü sormuştu. Hoca aynı cevabı hatırlatarak başladı: İleride bir türevde, bir integralde ya da bir kök bulma probleminde bazı yöntemler Taylor serisine ihtiyaç duyar. Elimizde çözmekte zorlandığımız bir problem varsa onu seriye açabilir ve çözüme seri üzerinden gidebiliriz.

Hocaya göre bir fonksiyonun seriye açılabilmesi için sonsuz kez türevinin alınabilmesi gerekir. Slaytta önceki haftadan kalan bir fonksiyon gösterildi. Bu fonksiyonun türevi dördüncü derecede sonlanıyordu ve hoca bunu seriye açılamayan bir fonksiyon olarak andı. Buna karşılık $e^{2x}$ fonksiyonunun $n$. dereceden türevinde de ortada hâlâ bir değer vardır, yani bu fonksiyon seriye açılabilir.

<!-- BELİRSİZ: Türevi dördüncü derecede sonlanan fonksiyonun ifadesi slaytta kalıyor, altyazıda söylenmiyor. -->

> **Ders sonrası not:** Hoca, türevi sonlanan fonksiyonun seriye açılamayacağını söyledi. Bu fonksiyon büyük olasılıkla bir polinomdu. Polinomun türevleri belli bir dereceden sonra sıfır olur, ama yine de vardır. Bu durumda Taylor serisi büyük olasılıkla sonlu bir toplam olarak polinomun kendisini verir. Nitekim Bölüm 4.4'te hoca dördüncü dereceden bir polinomu Taylor serisiyle açıyor ve sıfır hatayla gerçek değeri buluyor. Sonsuz kez türevlenebilir olmak da seriye açılabilmek için büyük olasılıkla tek başına yeterli değildir, fonksiyonun serisinin ona yakınsaması da gerekir.

### 1.2 Taylor ve Maclaurin Açılımları

Taylor açılımında sırayla fonksiyonun $x_0$ noktasındaki değeri, yine o noktadaki birinci türevi çarpı $(x - x_0)$ bölü $1!$, ikinci türevi çarpı $(x - x_0)^2$ bölü $2!$ gelir. Genel terim, $n$. türev çarpı $(x - x_0)^n$ bölü $n!$'dir. Birinci terimde $1!$ etkisiz olduğu için yazılmaz:

$$f(x) = f(x_0) + f'(x_0)(x - x_0) + \frac{f''(x_0)}{2!}(x - x_0)^2 + \dots + \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n + \dots$$

Buradaki $x_0$ negatif de olabilir, pozitif de.

Maclaurin serisi Taylor serisinin özel bir durumudur. Tek fark $x_0 = 0$ alınmasıdır. Bu durumda $(x - x_0)$ çarpanları $x$, $x^2$, $x^3$ olur ve türevler hep $0$ noktasında hesaplanır. Yani iki seri birbirinden türetilir, başka bir fark yoktur.

Sinüs, kosinüs ve $e^x$ gibi fonksiyonların açılımları belirli bir desene (pattern) sahip olduğu için çoğu zaman ezberlenir. Hoca, aslında bu açılımların arka planda ilgili değerleri Taylor serisinde yerine koyup terimleri sırayla hesaplayarak elde edildiğini hatırlattı.

### 1.3 Bu Ders Nasıl Öğrenilir?

Hoca bu ders için yöntemlerin derste rahatça öğrenilebileceğini, sınavdan bir iki gün önce onca yöntemi akılda tutmanın ise zor olduğunu söyledi. Ayrıca çok fazla ezbere gitmemek gerektiğini vurguladı. Gerçek dünyada karşımıza her zaman yerine koyup sonuç alacağımız problemler çıkmaz. Elimizdeki yöntemleri bilirsek hangi problemin neresinde neyi kullanacağımıza rahatça karar verebiliriz.

> **Hocanın vurgusu:** Sorularda takılmanın sebebi, derste ne çözüldüyse birebir aynısını beklemektir. Sınavda çoğu zaman derste çözülen örneğin daha basiti sorulur, sadece görüntüsü değişiktir. Hocanın benzetmesiyle: Onu gözlüksüz görmüş olsanız da gözlük taktığında başka biri olmaz. Sorulardaki şekil değişikliği de budur.

## 2. Taylor Serisinin Kapalı Gösterimi

Şimdiye kadar bir fonksiyonu seriye açarken iki, üç ya da dört terim koyup hesap yapıyorduk. Peki biri "beşinci dereceden açılımın değeri nedir?" diye sorarsa ne olur? Bunu söyleyebilmek için bütün terimleri tek tek hesaplamak gerekir. Hoca bunun yerine daha kompakt düşünmeyi önerdi.

Sonsuza kadar giden terimleri tek bir toplamla özetleyebiliriz:

$$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n$$

Toplam $n = 0$'dan başlar. Çünkü ilk terim fonksiyonun kendisidir: $(x - x_0)^0$ ve $0!$ birer olduğu için bu terimde yazılacak başka bir şey yoktur. Buradaki $f^{(n)}$ gösterimindeki $n$ bir kuvvet değildir, türevin derecesidir: $n = 0$ ise fonksiyonun kendisi, $n = 1$ ise birinci türevi, $n = 2$ ise ikinci türevidir.

Maclaurin serisi için $x_0 = 0$ konur, $-x_0$ çarpanları gider:

$$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!} x^n$$

Bu gösterimin asıl gücü şuradadır: $f^{(n)}(x_0)$ değerini $n$'e bağlı genel bir ifade olarak yazabilirsek terimleri tek tek hesaplamamız gerekmez.

## 3. Türevleri Genelleştirmek: Üç Örnek

### 3.1 $e^x$ Fonksiyonunun $x = 4$ Noktasındaki Taylor Serisi

Önceki haftada $e^x$ fonksiyonunu $x = 1$ noktasında açıp yalnızca ilk dört terimini almıştık, çünkü soru bunu istiyordu. Bu kez soru, $x = 4$ noktasındaki Taylor serisini istiyor. Kapalı formülde $x_0$ yerine 4 koyarız:

$$e^x = \sum_{n=0}^{\infty} \frac{f^{(n)}(4)}{n!}(x - 4)^n$$

Bunu yazabilmek için $f^{(n)}(4)$ değerini bilmemiz gerekir. Sonsuza kadar türev alamayacağımıza göre bu değeri genelleştirmeliyiz. Sıfırıncı türev fonksiyonun kendisi $e^x$'tir, birinci türev yine $e^x$, ikinci türev yine $e^x$. Kaçıncı türevi alırsak alalım sonuç $e^x$ olur: işaret hep artı, $e$'nin önündeki katsayı hep 1, üs hep $x$. Demek ki $f^{(n)}(x) = e^x$ ve $x = 4$ için $f^{(n)}(4) = e^4$. Yerine koyarsak:

$$e^x = \sum_{n=0}^{\infty} \frac{e^4}{n!}(x - 4)^n$$

Bundan sonrası kolaydır. Beşinci dereceye kadar açılım sorulursa toplamın üst sınırına 5, yüzüncü dereceye kadar sorulursa 100 yazarız. Yüz terimi tek tek bulup toplamak yerine formülü kullanırız. İkinci derece sorulsaydı üst sınıra 2 koyardık ve sonuç, terimleri tek tek koyup toplamakla aynı çıkardı.

> **Ders sonrası not:** Hoca beşinci derece için "birden beşe kadar olan terimler" dedi. Toplam $n = 0$'dan başladığı için doğrusu büyük olasılıkla "sıfırdan beşe kadar", yani altı terimdir. Kendi yazdığı kapalı formül de sıfırdan başlıyor.

### 3.2 $\frac{1}{x}$ Fonksiyonunun $x = 2$ Noktasındaki Taylor Serisi

Hoca bu soruya şu uyarıyla başladı:

> **Hocanın vurgusu:** Biri size "seriye aç" dediğinde hemen inanmayın, bu hocanız da olsa. Belki sizi test ediyor. Önce fonksiyonun seriye açılıp açılamadığını, yani sonsuz kez türevinin alınıp alınamadığını kontrol edin.

**Seriye açılabiliyor mu?** $\frac{1}{x}$'i $x^{-1}$ olarak yazıp türev alalım. Her adımda üs öne düşer ve üstten 1 çıkar:

- $f(x) = x^{-1}$
- $f'(x) = -x^{-2}$
- $f''(x) = 2x^{-3}$
- $f'''(x) = -6x^{-4}$

Bunu sonsuza kadar sürdürebiliriz, öyleyse fonksiyon seriye açılabilir.

**Seriyi yazalım.** $x_0 = 2$ olduğu için:

$$\frac{1}{x} = \sum_{n=0}^{\infty} \frac{f^{(n)}(2)}{n!}(x - 2)^n$$

Bir önceki sorudan farkı, burada türevin her adımda değişmesidir. Birkaç türevi alıp bunları genelleştirip genelleştiremeyeceğimize bakarız. Üç parçaya ayrı ayrı bakılır:

- **İşaret:** Artı, eksi, artı, eksi diye gider. Türevin derecesi tek sayıyken eksi çıkması için $(-1)^n$ kullanırız. $n = 0$ için $+1$, $n = 1$ için $-1$, $n = 2$ için $+1$ olur.
- **Katsayı:** $n = 0$ iken 1, $n = 1$ iken 1, $n = 2$ iken 2, $n = 3$ iken 6. Acaba $n!$ bunu sağlar mı? $0! = 1$, $1! = 1$, $2! = 2$, $3! = 6$. Sağlıyor.
- **Üs:** Üssün mutlak değeri $n$'den bir fazladır ve üs negatiftir. Yani üs $-n - 1$'dir. $n = 3$ iken $-4$, $n = 2$ iken $-3$, $n = 1$ iken $-2$, $n = 0$ iken $-1$ verir.

Üçünü birleştirince genel türev bulunur:

$$f^{(n)}(x) = (-1)^n \, n! \, x^{-n-1}$$

Bunu seride yerine koyalım. Artık $n$ tane türevi ayrı ayrı almamız gerekmiyor:

$$\frac{1}{x} = \sum_{n=0}^{\infty} \frac{(-1)^n \, n! \, 2^{-n-1}}{n!}(x - 2)^n$$

Pay ve paydadaki $n!$ birbirini götürür ve $2^{-n-1} = \frac{1}{2^{n+1}}$ olur (ara adım eklendi):

$$\frac{1}{x} = \sum_{n=0}^{\infty} (-1)^n \frac{(x - 2)^n}{2^{n+1}}$$

Soru $x = 5$ noktasını isteseydi formülde $x_0$'ın geçtiği iki yere de 5 yazmak yeterli olurdu, başka bir şey değişmezdi. Üçüncü dereceye kadar değer sorulursa toplamın sınırı 0'dan 3'e alınır, $x$ yerine istenen değer konur ve terimler toplanır.

> **Ek bilgi (derste anlatılmadı):** Bir Taylor serisi her $x$ için fonksiyonun değerini vermeyebilir. Yukarıdaki seri büyük olasılıkla yalnız $0 < x < 4$ aralığında $\frac{1}{x}$'e yakınsar, çünkü bu bir geometrik seridir ve $|x - 2| < 2$ gerektirir. Bu yüzden $x_0$ seçilen noktanın, hesaplanmak istenen değere uygun olması gerekir.

### 3.3 $e^{2x}$ Fonksiyonunun Maclaurin Serisi

Maclaurin serisinde $x_0 = 0$ alırız, formülümüz hazırdır:

$$f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!} x^n$$

Genelleştirmeye türevlerle başlarız. Her türevde üs öne düşer:

- $f(x) = e^{2x}$
- $f'(x) = 2e^{2x}$
- $f''(x) = 4e^{2x}$
- $f'''(x) = 8e^{2x}$

İşaretlerin hepsi pozitif olduğu için işaretle uğraşmayız. Katsayılar 1, 2, 4, 8 diye gider: $n = 0$ iken $2^0 = 1$, $n = 1$ iken $2^1 = 2$, $n = 2$ iken $2^2 = 4$, $n = 3$ iken $2^3 = 8$. Demek ki katsayı $2^n$'dir. $e^{2x}$ kısmı hiç değişmez:

$$f^{(n)}(x) = 2^n e^{2x}$$

Maclaurin serisi için $x$ yerine 0 koyarız. $e^0 = 1$ olduğundan $f^{(n)}(0) = 2^n$ çıkar. Formüle koyalım:

$$e^{2x} = \sum_{n=0}^{\infty} \frac{2^n x^n}{n!}$$

### 3.4 Bu Düşüncenin Algoritmik Yanı

Hocaya göre burada yaptığımız şey tamamıyla algoritmik düşünmektir: Elimizde tekrar eden bir desen vardır ve onu nasıl genelleştireceğimizi ararız. "Bunun kodunu yaz" deseler $n$ tane türevi ayrı ayrı birer satır olarak yazmayız. Derece olarak 5 verilirse $n$ yerine 5'e kadar, 10 verilirse 10'a kadar hesaplarız. Geriye bir `for` döngüsü kalır: sıfırdan başlar, istenen dereceye kadar gider, gerisi çarpma ve bölmedir. Hoca, bir matematikçinin soruyu çözebileceğini ama "bunun algoritmasını yaz" denince bu genellemeyi her zaman düşünmeyebileceğini, bilgisayar mühendisinin ise bu bakışı edinmesi gerektiğini söyledi.

## 4. Kesme Hatası

### 4.1 Tanım

Hataları anlatırken daha önce sayılar üzerinde kesme (truncate) ve yuvarlamayı (round) görmüştük: Noktadan sonra üç basamak alınacaksa üç basamakta kesebiliriz ya da dördüncü basamağa bakıp 5 ve 5'ten büyükse yukarıya tamamlayabiliriz. Sayısal analizde kesme hatası ise şöyle tanımlanır:

Bir değerin hesaplanabilmesi için sonsuz sayıda terim alınması gerekirken sonlu sayıda terim alınıyorsa oluşan hataya **kesme hatası** denir.

Bir fonksiyonu seriye açtığımızda sonsuz tane terim vardır. Sonsuz terimle işlem yapamayacağımız için "ilk 10 terimi al, ilk 20 terimi al, gerisini at" deriz. Bu "gerisini at" dediğimiz şey kesme hatasına neden olur.

Bu hatayı kabul edebilmemizin sebebi şudur: Serilerde belirli bir terimden sonra her yeni terim sonucu çok az değiştirir. Hocanın temsilî örneğinde bir terim alınca sonuç 2, iki terimde 2.5, üç terimde 2.75, dört terimde belki 2.77 olur. Yani yeni terimlerin katkısı küçüldüğü için işlemi kısa sürede bitirmek adına belirli bir yerden sonra keseriz.

<!-- BELİRSİZ: Hocanın burada slaytta gösterdiği Maclaurin açılımının hangi fonksiyona ait olduğu altyazıda söylenmiyor. Altyazıda 00:30:53'te geçen "posyumüs" büyük olasılıkla "kosinüs" sözcüğünün yanlış yazımıdır. -->

### 4.2 Örnek: $e^{1.5}$, Üçüncü Dereceden Maclaurin Açılımı

Hoca bu noktada öğrencilerden yanlarında kağıt, kalem ve hesap makinesi bulundurmalarını istedi.

> **Hocanın vurgusu:** Hazır çözüme baktığınızda "anladım" dersiniz, ama kendiniz yapmaya kalkınca bir yerlerde takıldığınızı görürsünüz. Bazı örneklerde ilk adımları sizin yapmanız istenecek. İşlem pratiğini kazanmazsanız sınavda gerçekten zorlanırsınız.

**Verilen:** $e^{1.5}$ değeri üçüncü dereceden Maclaurin açılımıyla hesaplanacak. Üçüncü dereceden demek, üçüncü türevin bulunduğu terime kadar almak demektir, gerisini atarız. Yani burada bir kesme hatasını kabul ediyoruz.

**İşlem:** Açarken $x_0$ yerine 0 koyarız, $x$ yerine 1.5'i en sonda yazarız. $e^x$'in bütün türevleri kendisidir, $x = 0$'da hepsi 1 olur:

$$e^x \approx 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!}$$

$x = 1.5$ için terimler sırayla şöyledir (ara adım eklendi):

$$1 + 1.5 + \frac{2.25}{2} + \frac{3.375}{6} = 1 + 1.5 + 1.125 + 0.5625 = 4.1875$$

**Sonuç:** Açılımdan 4.1875 bulunur. Bir hesap makinesiyle $e^{1.5} \approx 4.4817$ çıkar. Aradaki fark:

$$4.4817 - 4.1875 \approx 0.29$$

Yani "0.29 kesme hatasıyla bu sonuca ulaştım" diyebiliriz.

### 4.3 Hesap Makinesi ve Kesme Hatası

Hoca derste cep telefonunun hesap makinesini açıp $e^{1.5}$ değerini aldı ve 4.48 gördü. Elle yapılan açılım ise 4.18 civarında kalmıştı. Hesap makinemizin seriyi kaçıncı dereceye kadar alıp hesapladığını bilmeyiz. Bu terim sayısı, kullanılan makineye göre değişir. Hoca bu arada, tanımadığı bir hesap makinesinde üs almanın nasıl yapıldığını bulmakta kendisinin de bir süre zorlandığını göstererek kendi hesap makinemizi tanımamızı da hatırlattı.

### 4.4 Hatayı Düşürmek: İterasyon

Kesme hatası düşürülmek istenirse seriye bir terim daha eklenir. Bu örnekte dördüncü türevin bulunduğu terimi eklersek toplam değişir, gerçek değere yaklaşır ve hata küçülür.

Hoca bunu kod yazmaya bağladı, çünkü ileride yazacağımız yöntemlerde de aynı mantık geçerlidir. Size "sonuçları 0.15 kesme hatasıyla verin" dendiğini düşünelim. Bulduğunuz fark bu değerden büyükse bir iterasyon daha yaparsınız. Yine sağlanmıyorsa iterasyon sayısını artırıp daha hassas sonuç almaya çalışırsınız ve bu böyle devam eder.

### 4.5 Örnek: Polinomun Taylor Terimleriyle Adım Adım Hesabı

**Verilen:**

$$f(x) = -0.1x^4 - 0.15x^3 - 0.5x^2 - 0.25x + 1.2$$

$x = 0$'dan başlayarak, $h = 1$ ve $x_{i+1} = x_i + h$ alınarak $f(1)$ değeri, dördüncü dereceye kadar Taylor açılımıyla yaklaşık olarak hesaplanacak.

<!-- BELİRSİZ: Fonksiyonun tam ifadesi slaytta kalıyor. Yukarıdaki ifade kısa nottan alındı. Altyazıda söylenen türevler ve f(0) = 1.2 ile tutarlıdır. -->

Hoca "bu sorudan hiçbir şey anlamadınız" diye başladı, ama aslında basit bir şey isteniyor. $f(0)$'ı bulmak için $x$ yerine 0 koyarız. $f(1)$'i bulmak için de $x$ yerine 1 koyabiliriz. Soru ise diyor ki: $f(1)$'i böyle hesaplama, $f(0)$'a yeni terimler ekleye ekleye $f(1)$'i elde et.

Burada $h$ artım miktarıdır. Başlangıç $x_i = 0$ ise bir sonraki nokta $x_{i+1} = x_i + h = 1$, ondan sonraki $x_{i+2} = 2$ olur.

**Gerçek değerler:** $x = 0$ için $f(0) = 1.2$. $x = 1$ için toplamı adım adım alırsak $-0.1$, sonra $-0.25$, sonra $-0.75$, sonra $-1$, en sonda $1.2$ eklenince $f(1) = 0.2$. Hedefimiz bu 0.2'yi terim ekleyerek bulmaktır.

**Sıfırıncı derece:** Yalnızca fonksiyonun kendisi alınır:

$$f(1) \approx f(0) = 1.2$$

**Birinci derece:** Birinci türevi alıp $x = 0$ koyarız.

$$f'(x) = -0.4x^3 - 0.45x^2 - x - 0.25, \qquad f'(0) = -0.25$$

$$f(1) \approx 1.2 - 0.25x = 1.2 - 0.25 = 0.95$$

**İkinci derece:** Birinci türevden yola çıkarak ikinci türevi alırız.

$$f''(x) = -1.2x^2 - 0.9x - 1, \qquad f''(0) = -1, \qquad \frac{-1}{2!} = -0.5$$

$$f(1) \approx 1.2 - 0.25x - 0.5x^2 = 0.95 - 0.5 = 0.45$$

Bir terim eklenince sonuç hedefe nasıl yaklaştı, görülüyor.

**Üçüncü derece:**

$$f'''(x) = -2.4x - 0.9, \qquad f'''(0) = -0.9, \qquad \frac{-0.9}{3!} = -0.15$$

$$f(1) \approx 0.45 - 0.15 = 0.3$$

**Dördüncü derece:**

$$f^{(4)}(x) = -2.4, \qquad \frac{-2.4}{4!} = -0.1$$

$$f(1) \approx 0.3 - 0.1 = 0.2$$

Sonuç, gerçek değere eşit çıktı. Her derecedeki durum şöyle özetlenir:

| Derece | Yaklaşık değer | Gerçek değerle fark |
|---|---|---|
| 0 | 1.2 | 1.0 |
| 1 | 0.95 | 0.75 |
| 2 | 0.45 | 0.25 |
| 3 | 0.3 | 0.1 |
| 4 | 0.2 | 0 |

İşte kesme hatası budur: Her terim eklediğimizde yeni değer gerçeğe daha fazla yaklaşır.

> **Ders sonrası not:** Hoca toparlarken üçüncü derecedeki hatayı "0.3" diye okudu. 0.3 yaklaşık değerdir. Python ile yapılan kontrolde fark $|0.2 - 0.3| = 0.1$ çıktı, tablodaki değer budur. Hatanın dördüncü derecede tam sıfır olmasının sebebi büyük olasılıkla fonksiyonun kendisinin dördüncü dereceden bir polinom olmasıdır: Beşinci ve sonraki türevler sıfırdır, atılan terim kalmaz.

**Soru:** $x$ yerine 1 koyup sonucu hemen bulabilecekken neden bu kadar uğraştık? **Cevap:** Elbette doğrudan bulabilirsiniz. Amaç, kolayca yaptığımız bir şeyin arkasındaki matematiği göstermektir. Seri açıldığında sonsuz terimin belirli sayıda terimini alınca ne olduğunu, sürekli sözünü ettiğimiz hataların nasıl çıktığını görmek istiyoruz.

Hoca bu arada geçen haftaki bir ayrımı da hatırlattı. **Mistake** kullanıcı olarak bizim yaptığımız yanlıştır. **Error** ise burada olduğu gibi iki terim alarak hesapladığımızda çıkan farktır, yani yöntemin doğurduğu bir hatadır. Örneğimizde bu bir kesme hatasıdır.

> **Ek bilgi (derste anlatılmadı):** Kesilen terimlerin toplamı kalan terim olarak da ifade edilebilir. $n$. dereceden açılımda kalan terim büyük olasılıkla $R_n(x) = \frac{f^{(n+1)}(\xi)}{(n+1)!}(x - x_0)^{n+1}$ biçimindedir ve $\xi$, $x_0$ ile $x$ arasında bir noktadır. Bu gösterim büyük olasılıkla Lagrange kalan terimi diye anılır ve hatanın üst sınırını gerçek değeri bilmeden tahmin etmeye yarar.

### 4.6 Örnek: $\cos\frac{\pi}{5}$, Dördüncü Dereceden Maclaurin Açılımı

**Verilen:** $\cos\frac{\pi}{5}$ değeri dördüncü dereceden Maclaurin açılımıyla hesaplanacak ve kesme hatası bulunacak.

> **Ders sonrası not:** Altyazıda soru metni "Lagrange'in seri açılımı" diye geçiyor. Hoca hemen ardından Maclaurin açılımını anlattığı için bu büyük olasılıkla "Maclaurin" sözcüğünün yanlış yazımıdır.

Buradaki $\frac{\pi}{5}$ kafamızı karıştırmamalı. Aslında seriye açılacak fonksiyon $\cos x$'tir, $\frac{\pi}{5}$ en sonda yerine konacaktır. Dördüncü dereceden demek, dördüncü türevin bulunduğu terime kadar almak demektir. Maclaurin olduğu için açarken $x_0 = 0$ alınır.

Türevler ve $x = 0$'daki değerleri şöyledir:

- $f(x) = \cos x$, $f(0) = 1$
- $f'(x) = -\sin x$, $f'(0) = 0$
- $f''(x) = -\cos x$, $f''(0) = -1$
- $f'''(x) = \sin x$, $f'''(0) = 0$ (ara adım eklendi)
- $f^{(4)}(x) = \cos x$, $f^{(4)}(0) = 1$ (ara adım eklendi)

Sıfır çıkan terimler düşer ve şu kalır:

$$\cos x \approx 1 - \frac{x^2}{2!} + \frac{x^4}{4!}$$

$x = \frac{\pi}{5} \approx 0.628319$ için (ara adım eklendi):

$$1 - \frac{0.394784}{2} + \frac{0.155855}{24} = 1 - 0.197392 + 0.006494 = 0.809102$$

Gerçek değer bilgisayardan ya da hesap makinesinden $\cos\frac{\pi}{5} \approx 0.809017$ bulunur. Kesme hatası:

$$0.809017 - 0.809102 \approx -8.5 \times 10^{-5}$$

Bu oldukça küçük bir hatadır. Hocaya göre bu değer, üçüncü ya da ikinci dereceden açılımla da az bir hatayla bulunabilir.

<!-- BELİRSİZ: Slayttaki yaklaşık değer, gerçek değer ve kesme hatası altyazıda okunmuyor. Yukarıdaki sayılar Python ile hesaplandı ve kısa notla aynıdır. -->

Hoca seri konusunu burada kapattı. Taylor ve Maclaurin serisini, istenen dereceye kadar nasıl açılacağını, $n$. dereceden türevin nasıl genelleştirileceğini ve kesme hatasının nasıl bir hata olduğunu görmüş olduk.

## 5. Bağıl Hata

### 5.1 Tanım

Bağıl hata (relative error) ya da mutlak hata (absolute error) gibi adlar kulağa havalı gelse de hocaya göre arka planlarında zor bir şey yoktur. Bağıl hata, gerçek değerle hesaplanan değer arasındaki farkın gerçek değere oranıdır:

$$\varepsilon_r = \frac{\text{gerçek değer} - \text{hesaplanan değer}}{\text{gerçek değer}}$$

İstenirse yüzde olarak da yazılır. Hata ne kadar küçükse gerçek değere o kadar yakın bir sonuç almışız demektir. Sayısal yöntemlerde analitik çözüm yapmadığımız için hep yaklaşık değer buluruz, bu yüzden hatanın küçük olması gerekir. Hatanın ne kadar olacağı da bize söylenir: Örneğin "bağıl hata 0.001 olacak şekilde çözünüz" denir ve biz de bağıl hatayı sürekli hesaplarız.

> **Ders sonrası not:** Hoca, gerçek değere bölmenin hatayı daha da küçülttüğünü söyledi. Bu büyük olasılıkla yalnız gerçek değerin mutlak değeri 1'den büyük olduğu durumda geçerlidir. Gerçek değer 1'den küçükse bölme hatayı büyütür. Bağıl hatanın amacı hatayı küçültmek değil, onu gerçek değerin büyüklüğüyle karşılaştırmaktır.

### 5.2 İki Kısa Örnek

**Örnek 1.** $f(x) = x^3$ için $x = 2$'de gerçek değer 8'dir. Bir yanlışlık (mistake) yapıp 6 bulduğumuzu düşünelim:

$$\varepsilon_r = \frac{8 - 6}{8} = 0.25 = \%25$$

**Örnek 2.** $e$ sayısı için yaklaşık değer olarak 2.718 kullanılmış olsun:

$$\varepsilon_r = \frac{e - 2.718}{e} \approx 1.036 \times 10^{-4}$$

Hoca bu hataların genelde "0 virgül" ile başlatılarak yazıldığını söyledi ve sınıfa sordu.

**Soru:** $1.036 \times 10^{-4}$ sayısını $0.1036$ diye yazarsak on üzeri kaç olur? **Cevap:** $10^{-3}$ olur: $0.1036 \times 10^{-3}$.

> **Ders sonrası not:** Python ile hesaplandığında oran $1.03679 \times 10^{-4}$ çıktı. Yuvarlanınca $1.037 \times 10^{-4}$ olur. Derste geçen $1.036$ büyük olasılıkla kesilerek yazılmıştır. Hoca dönüşümü açıklarken üssün "eksi tarafa doğru" gideceğini söyledi. Sonucu doğrudur, ama çarpan 10 kat küçüldüğünde üs $-4$'ten $-3$'e, yani büyük olasılıkla artı yöne doğru bir adım gider.

### 5.3 Neden Bağıl Hata? Köprü ve Perçin

Bir köprü düşünelim, örneğin Boğaz Köprüsü'nü. Üzerindeki direkleri tutturan, vida gibi düşünebileceğimiz küçücük perçinler de vardır. İkisinde de ölçüm yapıyoruz:

- **Köprü:** Gerçek değer 10 000 cm, ölçülen 9 999 cm. Fark 1 cm.
- **Perçin:** Gerçek değer 10 cm, ölçülen 9 cm. Fark 1 cm.

Yalnızca farka bakarsak ikisinde de hata 1 cm'dir. Peki bu aynı hata mıdır? Değildir. On bin birimlik bir şeydeki bir birimlik hata ile on birimlik bir şeydeki bir birimlik hata aynı olamaz. Bağıl hataya bakalım:

$$\text{Köprü: } \frac{10000 - 9999}{10000} \times 100 = \%0.01 \qquad\qquad \text{Perçin: } \frac{10 - 9}{10} \times 100 = \%10$$

Perçindeki hata çok daha büyüktür. Yalnızca farka baksaydık ikisini aynı görür ve korkunç derecede yanılırdık. Hocanın sözleriyle, bir perçinin bir santim kayması ile köprünün bir santim sapması arasında insan canı ve maliyet açısından çok büyük bir fark vardır.

> **Hocanın vurgusu:** Problemde birimler konuşuluyorsa (kilometre, santim, saat, ne olursa olsun) yalnızca gerçek ile ölçülen arasındaki farka bakıp yola devam etmek büyük bir facia olur. Bu durumda mutlaka bağıl hata kullanılmalıdır.

> **Ders sonrası not:** Altyazıda hoca köprü ölçümünü önce "9 900 santim" diye söylüyor, sonraki bütün işlemlerde 9 999 kullanıyor. Fark 1 cm ve bağıl hata %0.01 ancak 9 999 ile çıkıyor (Python ile kontrol edildi), bu yüzden doğru değer büyük olasılıkla 9 999'dur.

## 6. Mutlak Hata

Bazen sonuçlarımız negatif çıkabilir ve negatif bir hata görmek istemeyebiliriz. Hoca bunu sıfır noktası üzerinde çizerek anlattı: Olması gereken nokta sıfır olsun. Değer iki birim yukarıda da çıksa iki birim aşağıda da çıksa iki durumda da iki birimlik bir hata vardır. Hatanın artı ya da eksi yönde olmasının bizim için önemi yoksa mutlak hata (absolute error) kullanırız. Hoca bunu "bağıl hatanın mutlak değerini alıyorum" diye özetledi:

$$\left| \frac{\text{gerçek değer} - \text{hesaplanan değer}}{\text{gerçek değer}} \right|$$

> **Ders sonrası not:** Hocanın verdiği ifade, kaynakların çoğunda büyük olasılıkla "mutlak bağıl hata" diye geçer. Mutlak hata adı genellikle bölme olmadan $|\text{gerçek} - \text{hesaplanan}|$ için kullanılır. Hoca da Bölüm 13'te "mutlak bağıl hata" adını kullanıyor.

**Örnek.** Bir fonksiyon $x = 2$ için hesaplanıyor. Doğrusu $4 - 6 = -2$'dir. Birisi ise sonucu yanlışlıkla 10 buluyor. Hata çok büyük ve bir değer pozitif, öbürü negatif. Bu karışıklıktan kurtulmak için mutlak değer alınır (ara adım eklendi):

$$\left| \frac{-2 - 10}{-2} \right| = 6$$

<!-- BELİRSİZ: Fonksiyonun tam ifadesi ve slayttaki hata değeri altyazıda söylenmiyor; yalnız "4, eksi 6, eksi 2" ve hesaplanan 10 değeri duyuluyor. Hocanın burada mutlak hatanın "ortalama bir hata" verdiği yönündeki cümlesi de net değil. -->

## 7. Yuvarlama Hatası

Yuvarlama hatasını (rounding error) daha önce görmüştük. Elimizde $27.35254316$ gibi bir sayı olsun ve "2D" verilmiş olsun, yani noktadan sonra iki basamak alınacak. Üçüncü basamak olan 2'ye bakarız. 5'ten küçük olduğu için sayı $27.35$ olarak alınır. Bu basamak 5 ya da 5'ten büyük olsaydı yukarı yuvarlardık. Yuvarlanmış değer ile asıl sayı arasındaki fark yuvarlama hatasıdır.

Hoca bu arada kesme ile yuvarlama arasında da 0.01'lik bir fark oluşabileceğini söyledi.

> **Ders sonrası not:** Bu sayıda kesme de yuvarlama da 27.35 verir, yani ikisi arasında fark yoktur. Python ile yuvarlama hatası $27.35254316 - 27.35 = 0.00254316$ çıktı. Hocanın sözünü ettiği 0.01 büyük olasılıkla slayttaki başka bir sayı içindir.

Hoca ardından birkaç sayıyı sınıfa sordu. Hocanın amacı katılım olduğu için "yanlış söyleyebilirsiniz, hiç problem değil" dedi.

**Soru:** Birinci sayı üç ondalık basamağa yuvarlanırsa ne olur? **Cevap:** Virgülden sonra üç basamak alınır: $1.352$. Asıl sayıdan bunu çıkarınca yuvarlama hatası bulunur.

**Soru:** Bir sonraki sayı için üç basamak? **Cevap:** $3.576$ olur. Bir sonraki basamak 1 olduğu için sayı yukarı yuvarlanmaz. Asıl sayıdan bunu çıkarırsak yuvarlama hatası bulunur.

<!-- BELİRSİZ: Bu iki alıştırma sayısının tamamı slaytta. Altyazıda yalnız 1,352 ve 3576 duyuluyor; ikincisinin tam değeri ve virgülün yeri net değil. -->

## 8. Doğrusal Olmayan Denklemler

Hoca burada ikinci bölüme geçti: doğrusal (lineer) olmayan denklemlerin çözümü. Yöntemlere geçmeden önce doğrusal olmayan denklemin, ortalama değerin ve benzeri kavramların ne olduğunu görmemiz gerekiyor.

### 8.1 Tanım

Doğrusal olmayan **bir bilinmeyenli** denklemde, adı üstünde, yalnızca bir bilinmeyen vardır: $x$. İki bilinmeyenli denklemleri ayrıca çözeceğiz.

Sayısal analizde analitik çözümü olmayan problemleri sayısal yöntemlerle çözmeye çalışırız. Bu problemler diferansiyel denklemler, integraller, doğrusal olmayan bir ya da iki bilinmeyenli denklemler olabilir.

Bir denklemin derecesi 1 ise denklem doğrusaldır. Derecesi birden fazlaysa (kare, küp, dördüncü kuvvet) ya da $e^x$ gibi başka türden ifadeler içeriyorsa doğrusal değildir. Yine tek değişken varsa buna doğrusal olmayan bir bilinmeyenli denklem deriz.

Doğrusal denklemler için genelde sayısal yöntemle uğraşmayız. Doğrusal olmayanları sayısal yöntemlerle çözeriz. Ama bu, doğrusal olmayan her denklemin analitik olarak çözülemeyeceği anlamına gelmez. Örneğin:

$$x^2 - 4x = 0 \quad \Rightarrow \quad x(x - 4) = 0 \quad \Rightarrow \quad x = 0, \; x = 4$$

Bu denklem doğrusal değildir ama analitik olarak çözülebilir. Sayısal yöntemle çözmemize de engel yoktur.

Slaytta bir de derecesi birden fazla olan ve analitik çözümü oldukça zor bir denklem, bir de $e$ üzeri sinüslü ve kareli ifadeler içeren bir denklem gösterildi. Hoca bunlara "diskriminantla çözebiliyorsan çöz" diye takıldı, ama çözülemez. Bu tür denklemleri sayısal yöntemlerle çok hızlı çözeriz. Yalnız analitik yöntemdeki tam sonucu alamayız, yaklaşık bir sonuç alırız. Ne kadar yaklaşık olduğunu da "bağıl hataya göre, mutlak hataya göre şu kadar" diye belirtiriz.

<!-- BELİRSİZ: Bu slayttaki denklemlerin tam ifadesi altyazıda okunmuyor. -->

### 8.2 Kökün Varlığı İçin Teorem

Teorem şöyle der: $f(x)$ fonksiyonu $[a, b]$ aralığında sürekli olsun. $f(a)$ ile $f(b)$ ters işaretliyse $[a, b]$ aralığında en az bir gerçek kök vardır.

Hoca bunu çizerek gösterdi: $a$'yı fonksiyonda yerine koyunca pozitif, $b$'yi koyunca negatif bir değer çıkıyorsa ve fonksiyon sürekliyse, bu aralıkta bir kök vardır.

Fonksiyonun $x$ eksenini tek noktadan keseceği diye bir kural yoktur. Hoca bunu "yılan gibi" kıvrılan bir fonksiyon üzerinde gösterdi: Ters işaret koşulu sağlanır, aralıkta kök vardır, ama birden fazla kök olabilir. Yöntem bunlardan yalnızca birini bulur ve hangisini bulacağımızı önceden bilemeyiz. Diğer kökleri bulmak için $a$ ve $b$ değerlerini sağa ya da sola kaydırırız.

Fonksiyon aralıkta sürekli değilse, $x$ eksenini kesiyor gibi görünse de hoca bu yöntemlerden sonuç alamayacağımızı söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu teorem, Bölüm 11'deki ara değer teoreminin kök için özel hâlidir. Kısa notta da geçtiği gibi büyük olasılıkla Bolzano teoremi adıyla anılır.

### 8.3 Yöntem Nasıl Seçilir? Iraksama

Karşımıza bazen tek bir denklem, bazen bir denklem takımı çıkar. Çözüm için çok sayıda yöntem vardır. Yöntem şunlara bakılarak seçilir:

- Tek bir denklem mi, denklem takımı mı çözülüyor?
- Bir kök mü, kökler mi aranıyor?
- Kökler gerçek mi, sanal mı? Bu konuda bilgi verilmiş mi?
- Kökler için yaklaşık değerler biliniyor mu, yaklaşık değer bulunması mı isteniyor?

Bazı yöntemler tek denklemin, bazıları denklem takımlarının çözümüne daha uygundur.

Bazen seçilen yöntem iyi sonuç vermez ve gittikçe kökten uzaklaşır. Buna **ıraksama** denir: İteratif olarak bulduğumuz değerler birbirinden gittikçe uzaklaşır. Yakınsayan bir yöntemde ise ardışık değerler arasındaki fark gittikçe küçülür, sıfıra yaklaşır ve kök bulunur. Fark büyüyorsa ya yanlış yoldayız ya da seçtiğimiz aralık yanlıştır, bunlarla oynamamız gerekir. Algoritma yazarken böyle bir durumla karşılaşırsak kullanıcıdan $a$ ve $b$ başlangıç değerlerini yeniden girmesini isteyebilir, aralığı değiştirebilir, iterasyon sayısını artırabiliriz.

## 9. Kapalı ve Açık Yöntemler

Doğrusal olmayan denklemlerin çözüm yöntemleri ikiye ayrılır: kapalı yöntemler ve açık yöntemler. Hoca, sayısal analiz konusunda onlarca kitap olduğunu, bazı yöntemlerin her kitapta bulunduğunu, bazılarının ise yazarın ilgi alanına göre öne çıktığını belirtti.

### 9.1 Kapalı Yöntemler

Kapalı yöntemlerde kök, bir alt ve bir üst sınırla belirlenen aralığın içindedir. Yani kökün olması gerektiğini tahmin ettiğimiz değeri $a$ ve $b$ aralarına almalıdır.

Yöntem tekrarlandıkça kökün gerçek değerine yaklaşılır. Bazen $b$ noktası her iterasyonda köke yanaşır, bazen $a$ soldan, $b$ sağdan gelir, bazen de $b$ sabit kalır ve $a$ soldan gelerek kökü sıkıştırır. Sonunda sıfıra ulaşılır.

İterasyon sayısı arttıkça gerçek değere daha fazla yaklaşıldığı için bu yöntemlere **yakınsak** yöntemler denir. Hoca bunu örnekledi: Bulmamız gereken değer 5 olsun. Sırayla 10, 8, 7, 6, 5.5, 5.4, 5.2, 5.15 buluyoruz. Her adımda bir önceki değerle aradaki fark küçülüyorsa yöntem yakınsaktır.

Dersin kapalı yöntemleri şunlardır:

- Grafik yöntemi
- İkiye bölme (bisection)
- Regula falsi (false position, doğrusal interpolasyon, yanlış nokta)

### 9.2 Açık Yöntemler

Açık yöntemlerin kapalılardan farkı, $x$ için yalnızca tek bir başlangıç değeri ya da kökü kıskaca almayan iki başlangıç değeri gerektirmeleridir. Yani başlangıç noktası kökün bir tarafında bir yerdedir. İki nokta verilse bile ikisi de kökün solunda ya da ikisi de sağında olabilir.

Bu yöntemleri çalıştırırken noktaların köke yanaştığını görmemiz gerekir. Ama bazen farkına varmadan noktalar kökten gittikçe uzaklaşır. O zaman kökü bulma imkânımız kalmaz ve yöntem ıraksamış olur. Bu durumda başlangıç koşullarını değiştirmemiz gerekir.

Dersin açık yöntemleri şunlardır:

- Newton-Raphson
- Sekant (Türkçesi kiriş)
- Tekrarlama metodu (fixed point iteration)

### 9.3 Karşılaştırma

| Özellik | Kapalı yöntemler | Açık yöntemler |
|---|---|---|
| Başlangıç | Kökü içine alan $a$, $b$ aralığı | Tek değer ya da kökü kıskaca almayan iki değer |
| Iraksama | Söz konusu değil, eninde sonunda yakınsar | Söz konusu olabilir |
| Hız | İterasyon sayısı daha uzun sürer | Yakınsarsa daha hızlıdır |

Hocanın örneğinde kapalı yöntemin 100 iterasyonda bulduğu sonucu açık yöntem belki 40 iterasyonda bulabilir.

## 10. Ortalama Değer Teoremi

Yöntemlere geçmeden önce, bu yöntemlerin içinde kullanacağımız ama ne olduğunu çoğu zaman bilmeden kullandığımız birkaç kavramı görüyoruz. Hoca, "biz bunu zaten biliyorduk" diyebileceğimizi, ama bunların matematikte bir adı olduğunu söyledi. İlki ortalama değer teoremidir (mean value theorem).

### 10.1 Teorem ve Geometrik Anlamı

$a$ ile $b$ arasında bir fonksiyon çizelim. Dalgalı olabilir, hiperbol gibi olabilir, doğru gibi olabilir. Şeklinin önemi yoktur, önemli olan bu fonksiyonun $[a, b]$ aralığında sürekli olmasıdır. Teorem, bu aralıkta öyle bir $c$ noktası olduğunu söyler ki:

$$f'(c) = \frac{f(b) - f(a)}{b - a}$$

Hoca bunu şöyle aklımızda tutmamızı önerdi: $f(a)$ ve $f(b)$ noktalarını bir doğruyla birleştirelim. Düşeydeki fark $f(b) - f(a)$, yataydaki fark $b - a$'dır. Bu doğrunun yatayla yaptığı açıya $\alpha$ dersek, tanjant karşının komşuya oranıdır:

$$\tan \alpha = \frac{f(b) - f(a)}{b - a}$$

Bir fonksiyonun bir noktadaki teğetinin açısının tanjantı, fonksiyonun o noktadaki türevini verir. Yani sağ taraftaki oran, fonksiyonun $c$ noktasındaki türevine eşittir. Geometrik olarak $c$, fonksiyonun $a$ ve $b$ noktalarını birleştiren doğruya paralel teğetinin değdiği noktadır. Pratik sonucu da şudur: Oranı hesaplarız, sonra fonksiyonun türevini alıp bu orana eşitleriz ve $c$'yi buluruz.

> **Ders sonrası not:** Hoca bu kısımda birkaç kez "$c$ değeri $\frac{f(b) - f(a)}{b - a}$'dır" ve "ortalama değer 6'dır" dedi. Bu oran $c$'nin kendisi değil, büyük olasılıkla $c$ noktasındaki türevin (eğimin) değeridir: Aşağıdaki ilk örnekte oran 6, $c$ ise 3'tür. Hoca ayrıca bir yerde "$b$, $a$'dan sağda olduğu için $f(b)$ daha büyüktür" dedi. Bu büyük olasılıkla yalnız artan fonksiyonlar için doğrudur, genelde gerekmez. Teoremin tam ifadesinde büyük olasılıkla fonksiyonun $(a, b)$ açık aralığında türevlenebilir olması da gerekir ve $c$ bu açık aralıktadır. Hoca yalnız sürekliliği söyledi.

### 10.2 Örnek: $f(x) = x^2 + 5$, $[1, 5]$

**Verilen:** $f(x) = x^2 + 5$, $a = 1$, $b = 5$. Teoremi sağlayan $c$ değeri bulunacak.

**Oran:** $f(5) = 25 + 5 = 30$, $f(1) = 6$.

$$\frac{f(5) - f(1)}{5 - 1} = \frac{30 - 6}{4} = 6$$

**$c$:** Türevi alıp bu değere eşitleriz:

$$f'(x) = 2x, \qquad 2c = 6, \qquad c = 3$$

**Sonuç:** $c = 3$ değeri 1 ile 5 arasındadır, yani koşulu sağlar.

### 10.3 Kaç Tane $c$ Vardır?

Hoca bunun "neden bir tane var, neden iki, üç, dört tane yok?" sorusuyla grafiğe döndü. Slayttaki mavi, dalgalı fonksiyonda üç teğet noktası vardır, yani üç tane $c$ değeri bulunur. Kırmızı eğride ya da parabolde ise bir teğet noktası vardır, yani bir tane $c$ değeri bulunur.

> **Hocanın vurgusu:** Bir fonksiyonda kaç tane böyle teğet noktası varsa o kadar $c$ değeri vardır. Bu çok önemli bir bilgidir: Fonksiyondaki dalgalanma sayısı, kaç tane ortalama değer noktası olduğunu söyler.

### 10.4 Örnek: $f(x) = x^3 + 2x - 5$, $[-1, 1]$

**Verilen:** $f(x) = x^3 + 2x - 5$, $a = -1$, $b = 1$.

**Oran:** $f(1) = 1 + 2 - 5 = -2$, $f(-1) = -1 - 2 - 5 = -8$ (ara adım eklendi).

$$\frac{f(1) - f(-1)}{1 - (-1)} = \frac{-2 - (-8)}{2} = 3$$

**$c$:** Türevi alıp 3'e eşitleriz:

$$f'(x) = 3x^2 + 2, \qquad 3c^2 + 2 = 3, \qquad c^2 = \frac{1}{3}, \qquad c = \pm\frac{1}{\sqrt{3}}$$

**Sonuç:** $c \approx \pm 0.577$ değerlerinin ikisi de $[-1, 1]$ aralığındadır. Hoca fonksiyonu çizince bu iki noktayı "iki dalgalanma noktası" olarak gösterdi.

> **Ders sonrası not:** Bu fonksiyonun türevi $3x^2 + 2$ her yerde pozitiftir, yani fonksiyon büyük olasılıkla sürekli artar ve yerel tepe ya da çukuru yoktur. Dolayısıyla "dalgalanma sayısı" kesin bir sayma kuralı olarak değil, büyük olasılıkla sezgi olarak anlaşılmalıdır. Kesin sayı, $f'(c)$ denkleminin aralıktaki çözüm sayısıdır. Burada bu sayı ikidir.

## 11. Ara Değer Teoremi ve Köklerin Varlığı

### 11.1 Teorem

$f(x)$ fonksiyonu $[a, b]$ kapalı aralığında sürekli olsun ve $f(a) \ne f(b)$ olsun. O zaman iki durum vardır: $f(a) < f(b)$ ya da $f(a) > f(b)$. Aralıktan bir ara değer $c$ aldığımızda hocanın çizdiği artan ve azalan eğrilerde $f(c)$ ilgili iki değerin arasında kalır:

- $f(a) < f(b)$ ise $f(a) < f(c) < f(b)$
- $f(a) > f(b)$ ise $f(a) > f(c) > f(b)$

> **Ders sonrası not:** Hocanın bu sıralamayı her $c$ için yazması büyük olasılıkla yalnız aralıkta tek yönlü (monoton) gidiş için geçerlidir. Teoremin genel ifadesi büyük olasılıkla tersi yöndedir: $f(a)$ ile $f(b)$ arasındaki her değer, aralıktaki en az bir $c$ noktasında alınır. Hocanın "$f(a) < f(b)$ ise $a$, $b$'nin solundadır" cümlesi de büyük olasılıkla genel değildir, çünkü $a < b$ zaten aralığın tanımından gelir.

### 11.2 Kök İçin Kullanımı

Bir denklemin kökünü bulmak, fonksiyonu sıfır yapan değeri bulmak demektir. Sıfır yapan birden fazla değer de olabilir.

$[a, b]$ aralığında sürekli bir fonksiyon için aralıkta kök olması için $f(a)$ ile $f(b)$'nin çarpımı negatif olmalıdır:

$$f(a) \cdot f(b) < 0$$

Hoca bunu çizerek gösterdi. $f(a)$ da $f(b)$ de pozitifse çarpım pozitiftir ve çizilen aralıkta kök yoktur. İkisi de negatifse çarpım yine pozitiftir ve yine çizilen aralıkta kök yoktur. Çarpımın negatif olması için biri pozitif, biri negatif olmalıdır. Bu durumda aralıkta en az bir kök vardır.

Aralıkta 3-4 kök de olabilir. Hocanın gösterdiği şekilde $a$ ve $b$ arasında üç kök var, biz bunlardan yalnızca birini bulabiliriz. Diğerleri için $a$ ve $b$ değiştirilir.

> **Ders sonrası not:** Hoca, kök olması için çarpımın negatif "olması gerektiğini" söyledi. Bu koşul büyük olasılıkla yeterlidir ama gerekli değildir: $f(a) \cdot f(b) > 0$ iken de fonksiyon aralıkta $x$ eksenini çift sayıda kesebilir. Bu yüzden çarpım pozitifse "kök yok" diyemeyiz, yalnız teorem bir şey söylemez.

### 11.3 Örnek: $f(x) = x^3 - 5x + 1$, $[1, 3]$

**Soru:** Bu fonksiyonun $[1, 3]$ aralığında en az bir kökü olduğunu gösteriniz.

> **Hocanın vurgusu:** Böyle bir soruda önce fonksiyonun bu aralıkta sürekli olduğunu göstermeniz gerekir. Süreklilik varsa kök var diyebilirsiniz.

**1. adım, süreklilik:** Tanımsız bir durum var mı, örneğin paydası sıfır olan bir yer? Yok. Parçalı bir fonksiyon olarak mı verilmiş? Hayır. O hâlde fonksiyon $[1, 3]$ aralığında süreklidir.

**2. adım, işaret:** $f(1) = 1 - 5 + 1 = -3$ ve $f(3) = 27 - 15 + 1 = 13$ (ara adım eklendi). Biri negatif, biri pozitif:

$$f(1) \cdot f(3) = (-3)(13) = -39 < 0$$

**Sonuç:** Fonksiyon $[1, 3]$ aralığında süreklidir ve çarpım sıfırdan küçüktür, öyleyse bu aralıkta en az bir gerçek kök vardır. Ardından bir yöntem seçilip bu kök aranır.

Yöntem sonucunda bulunan $c$ değerini fonksiyonda yerine koyduğumuzda sıfır çıkmayabilir. O zaman aradaki farkın (bağıl ya da mutlak hatanın) istenen sınırda olup olmadığına bakarız. Örneğin hatanın 0.001 olması isteniyor, ama 0.1 çıktıysa aralıkla ya da iterasyon sayısıyla oynayarak hatayı bu sınıra indiririz.

## 12. Süreklilik, Parçalı Fonksiyonlar ve Limit

### 12.1 Parçalı Fonksiyonlar

Parçalı fonksiyonda ifade iki ya da daha fazla parçada verilir. Örneğin $x > 3$ için bir ifade, $x \le 3$ için başka bir ifade kullanılır. $x = 0$ için $x \le 3$ tarafındaki ifadeye, $x = 4$ için $x > 3$ tarafındaki ifadeye gideriz. Hoca, kullanılan ifadeler farklı olduğu için bu fonksiyonları sürekli saymadı.

> **Ders sonrası not:** Hoca "parçalı bir fonksiyonsa süreklilik olmaz" dedi. Bu büyük olasılıkla genel bir kural değildir. Parçalar birleşme noktasında aynı değere ulaşıyorsa parçalı fonksiyon da sürekli olabilir. Süreklilik, birleşme noktasındaki soldan ve sağdan limitlere bakılarak kontrol edilir.

### 12.2 Süreklilik ve Limit

Hoca sürekliliğin aslında limitle ilgili olduğunu söyledi ve üç grafik üzerinden anlattı: Birinci grafikte fonksiyon kesintisizdir, sürekli ve $a$ noktasında limiti vardır. İkinci grafikte fonksiyon bir noktada kopmuştur. Üçüncü grafikte fonksiyon iki parçadan oluşur, bir parçanın o noktada değeri yokken öbürünün vardır.

Hocanın ana cümlesi şudur: Bir fonksiyon sürekliyse mutlaka limiti vardır, ama limitin olması fonksiyonun sürekli olmasını gerektirmez. Bir noktada soldan ve sağdan limitler birbirine eşit değilse o noktada limit yoktur ve fonksiyon orada süreksizdir.

<!-- BELİRSİZ: Altyazıda 02:12:46 ile 02:13:16 arasında 30 saniyelik boşluk var. Hocanın "bunların üçü de eşitse" dediği üç büyüklük ve grafiklerin kendisi bu nedenle net değil. -->

> **Ders sonrası not:** Hoca "soldan ve sağdan yaklaşımlar fonksiyonun o noktadaki değerini veriyorsa fonksiyon süreksiz olsa da limit vardır" dedi. Büyük olasılıkla doğrusu şudur: Limit için soldan ve sağdan limitlerin birbirine eşit olması yeterlidir, fonksiyonun o noktadaki değeri farklı olabilir ya da hiç tanımlı olmayabilir. Üç büyüklük de (soldan limit, sağdan limit, $f(a)$) eşitse fonksiyon o noktada süreklidir, süreksiz değil. Hoca ayrıca "bu noktada fonksiyon olmadığı için limit de yok" dedi. Fonksiyonun bir noktada tanımsız olması büyük olasılıkla tek başına limiti ortadan kaldırmaz.

### 12.3 Özet: Süreksizlik Durumları

Hoca sürekliliği iki durumla özetledi:

- **Tanımsızlık:** Örneğin bir fonksiyon $x = 3$ noktasında tanımsız olabilir (paydası sıfır olabilir). Bu noktada süreksizdir.
- **Parçalı fonksiyon:** Soldan gelince bir değer (hocanın örneğinde 9), sağdan gelince başka bir değer (6) bulunuyorsa limit yoktur ve fonksiyon orada süreksizdir.

<!-- BELİRSİZ: Hoca bu parçalı örnekte iki yandan da "5 koydum" diyor; fonksiyonun ifadesi ve kırılma noktası slaytta kalıyor. Altyazıda yalnız 9 ve 6 sonuçları duyuluyor. -->

Hoca, böyle süreksiz bir fonksiyonun kökünün anlatacağımız yöntemlerle bulunamayacağını söyledi. Bölüm 11.3'teki gibi tanımsızlığı olmayan, parçalı verilmemiş, her yerde sürekli bir fonksiyonda ise aralıktaki kökü rahatça bulabiliriz.

## 13. İteratif Yöntemlerde Durma Ölçütü

Sayısal yöntemlerimizin hemen hepsi iteratiftir: Bir adım atarız, bulduğumuz sonucu bir sonraki adıma veririz, her adım bir öncekinden yararlanır. Peki nerede duracağız? Hoca durma noktasını belirleyen iki durum verdi.

### 13.1 Gerçek Kök Biliniyorsa

Gerçek değer bellidir. Örneğin yapılan işlemin 10 çıkması gerektiği söylenmiştir. Sayısal yöntemle 100 adım ilerleyip bir değer bulduğumuzda durup durmayacağımızı kontrol ederiz. Bunun için bağıl hatayı hesaplarız. İstenirse mutlak değeri de alınır, o zaman mutlak bağıl hata olur:

$$\left| \frac{x_{\text{gerçek}} - x_n}{x_{\text{gerçek}}} \right| \le \varepsilon$$

Akış şöyledir:

- Adım 1: Belirlenen iterasyon sayısı kadar işlem yapılır.
- Adım 2: Hata hesaplanır ve verilen $\varepsilon$ ile karşılaştırılır.
- Adım 3: Koşul sağlanıyorsa durulur, bulunan değer yaklaşık kök olarak kabul edilir.
- Adım 4: Sağlanmıyorsa iterasyon artırılır (ör. 100'den 150'ye) ve Adım 2'ye dönülür.

### 13.2 Gerçek Kök Bilinmiyorsa

Bu kez işlemin sonucunun ne olması gerektiği bilgisi yoktur. İşlem 10, 100 ya da 1000 kez yapılır. Hocanın verdiği ölçüt şudur:

$$\frac{|b - a|}{2^n} \le \varepsilon$$

Burada hoca $b$ için en son bulunan değeri, $a$ için bir önceki bulunan değeri söyledi. Bilgisayarda bunu yapmak kolaydır, ama elle işlem yaparken durmadan $2^n$'e bölmek zaman kaybettirir. Hoca elle çözerken $|b - a| \le \varepsilon$ kontrolünün yeterli olacağını, kod yazarken ise $2^n$'e bölmenin daha mantıklı olduğunu söyledi.

> **Ders sonrası not:** $\frac{|b - a|}{2^n}$ ölçütü büyük olasılıkla ikiye bölme yöntemine özgüdür. Orada $a$ ve $b$ başlangıç aralığının uçlarıdır ve $n$ adım sonunda kökü içeren aralığın uzunluğu $\frac{b - a}{2^n}$ olur. Ardışık iki yaklaşımın farkını ayrıca $2^n$'e bölmek büyük olasılıkla yanıltıcıdır: Bölüm 14.1'deki sayılarla Python'da $\frac{29 - 20}{2^{100}} \approx 7.1 \times 10^{-30}$ çıkıyor, yani fark 9 birimken bile her $\varepsilon$ sağlanmış görünür. Ardışık değerlerle çalışırken büyük olasılıkla $|x_n - x_{n-1}| \le \varepsilon$ ya da $\left| \frac{x_n - x_{n-1}}{x_n} \right| \le \varepsilon$ kullanılmalıdır.

### 13.3 Hata Ne Kadar Olmalı?

Sınavda $\varepsilon = 0.1$ gibi büyük değerler verilebilir, böylece iterasyon sayısı az olur ve çözüme hemen ulaşırız. Ama kod yazarken 0.1 hata almamalıyız, çünkü gerçekçi bir değer bulamayız.

> **Hocanın vurgusu:** Kod yazarken hata olarak en az $0.001$, yani $10^{-3}$ gibi bir değeri kabul edin.

## 14. Dersin Sonundaki Sorular

Genel bilgileri bitirdikten sonra hoca sorulara geçti. Bu kavramlara bir daha ayrıca dönülmeyecek, ama yöntemler anlatılırken bağıl hata, kesme hatası gibi sözler artık bu anlamlarıyla kullanılacak.

### 14.1 Hata Nedir, Neye Göre Bulunur?

**Soru:** Son slayttaki hata kısmını anlamadım. "Hata küçüktür" yazıyoruz, hatayı neye göre buluyoruz? Hata bize mi veriliyor? **Cevap:** Hata çoğunlukla soruda verilir ve $\varepsilon$ ile gösterilir. Örneğin "$\varepsilon = 0.01$ bağıl hatasıyla sonuç bulun" denir. Yani problemi ne kadar yaklaşık bulacağımız söylenir: yüzde bir mi, binde bir mi, yüz binde bir mi?

Hoca bunu üç benzetmeyle anlattı:

- **Doktor:** Böbrek ameliyatı yapıyorsunuz. Neşteri karnın ortasına vurup "böbreğe kadar yürürüm" mü dersiniz, yoksa neşteri böbreğin olduğu noktaya mı indirirsiniz? Göbekten vurursanız çok büyük hatayla işlem yapmış olursunuz ve bunun bedeli hastayı kaybetmek olabilir.
- **İnşaat mühendisi:** Çok büyük bir hatayı kabul ederseniz bina yıkılır.
- **Bankacılık uygulaması:** Büyük hata yaparsanız insanların hesaplarından her işlemde para çıkıp gider.

Bu yüzden hata, uygulamanın türüne bağlı olarak verilir ya da ne kadar hata kabul edeceğinizi siz bilirsiniz.

**Gerçek değer verildiğinde: beton örneği.** İnşaat mühendisisiniz, betonun ideal ısısının 30 olması gerektiği söyleniyor. Çeşitli formüllerle bir $x_n$ değeri elde ediyorsunuz:

- İlk hesapta 20 buldunuz. Fark $30 - 20 = 10$. İstenenden büyük, yanlış bir şey yapıyorsunuz, hesaba dönersiniz.
- Sonra 29 buldunuz. Fark 1. Hâlâ yeterli değil, işleme devam edersiniz.
- Sonra 29.99 civarında bir değer buldunuz. Fark artık verilen hatanın altında. "Tamam, bunu kabul edebilirim" diyorsunuz.

Bağıl hatada farkı bir de gerçek değere böleriz, mantık aynıdır.

<!-- BELİRSİZ: Son değer altyazıda "29,900 bilmem ne 8", sonra "29,99998" ve "29,998" diye farklı duyuluyor. -->

**Gerçek değer verilmediğinde.** Aynı örnekte önce 20, sonra 29 ölçtüğümüzü düşünelim. Hocanın anlatımıyla, 29'a 100. iterasyonda gelindiyse fark $2^{100}$'e bölünür ve hatayla karşılaştırılır. Değer yeterli değilse işlem sürer: 160. iterasyonda 29.99998 bulunmuşsa bu kez üst sınıra son değer, alt sınıra bir önceki değer olan 29 yazılır ve $2^{160}$'a bölünür. Sonuç hatadan küçükse işlem kabul edilir. Ölçütle ilgili düzeltme Bölüm 13.2'deki nottadır.

**Soru:** Formüldeki $n$'ler farklı mı? Aynı değişkenle nasıl hem üst sınır hem alt sınır oluyor? **Cevap:** Yazılışa takılma. Bu işlemde $n$ 160 ise üst sınır bu değerdir. İşlem 165'te yapılırsa üst sınır o değer olur, alt sınır da bir önceki değer olur. Yani bulunan en son değer üst sınır, ondan bir önce bulunan değer alt sınırdır.

### 14.2 Ortalama Değer Teoremi Ne İşe Yarar?

**Soru:** Ortalama değer teoremini anladım, ama ne işimize yaradığını anlamadım. **Cevap:** Bazen bir problemin minimum ya da maksimum noktasını bulmanız gerekir. Hocanın örneği fabrikadandı: İstenen renk tonunu yakalamak için boyadan en az ne kadar koymalıyım? Bir sistemin minimum ve maksimum noktalarını bulmak, fonksiyonun türevini alıp sıfıra eşitlemek demektir.

Hoca teoremin faydasını şöyle anlattı: Türev almak her zaman kolay değildir. Elimizde fonksiyon ve aralık varsa, $\frac{f(b) - f(a)}{b - a}$ değerini hiç türev almadan fonksiyonda yerine koyarak buluruz ve bu değerin aralıktaki bir noktanın türevine eşit olduğunu biliriz. "Şu fonksiyonun ortalama değerini bul" demek belki bir test sorusudur, ama gerçek dünyada bir problem çözerken size bunu bul diye denmez. Aradaki ilişkiyi biliyorsanız "bu teoremi kullanarak sonuca ulaşabilirim" diyebilirsiniz.

> **Ders sonrası not:** Teorem türevin istenen bir noktadaki değerini değil, aralıkta adı bilinmeyen bir $c$ noktasındaki değerini verir. Dolayısıyla büyük olasılıkla minimum-maksimum noktasını tek başına bulmaya yetmez. Hocanın "türevini alamayacağın fonksiyon" örneği de dikkatle okunmalıdır: Teorem büyük olasılıkla türevin var olmasını gerektirir, yalnız türevi formül olarak yazmayı gerektirmez.

## Dersin Toparlaması

Bu derste önce Taylor ve Maclaurin serilerinin kapalı gösterimini ve $n$. türevi genelleştirerek $e^x$, $\frac{1}{x}$ ve $e^{2x}$ serilerini terim terim hesaplamadan yazmayı gördük. Ardından seriyi sonlu terimde kesmenin doğurduğu kesme hatasını, gerçek değere oranlanan bağıl hatayı, işareti önemsizleştiren mutlak hatayı ve yuvarlama hatasını sayısal örneklerle işledik. Köprü ve perçin örneği, birimlerle çalışırken yalnız farka bakmanın neden yanıltıcı olduğunu gösterdi.

İkinci bölümde doğrusal olmayan denklemlere, kapalı ve açık yöntem ayrımına, ortalama değer ve ara değer teoremlerine, süreklilik ile limit ilişkisine ve iteratif yöntemlerde durma ölçütüne giriş yaptık. Hoca önümüzdeki hafta kapalı yöntemlere (grafik, ikiye bölme, regula falsi) geçileceğini, süre kalırsa açık yöntemlere başlanabileceğini söyledi. Bu dersler için yanımızda kağıt, kalem ve hesap makinesi bulundurmamızı istedi, çünkü işlem pratiği olmadan süre yetmez.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
