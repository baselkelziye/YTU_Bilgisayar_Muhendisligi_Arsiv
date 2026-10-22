# Ders 2 Çalışma Özeti

## Genel Konular

- Ders önceki haftanın Taylor ve Maclaurin serisi konusuyla devam eder. Ardından kesme hatası, bağıl hata, mutlak hata ve yuvarlama hatası işlenir. İkinci bölüme (doğrusal olmayan denklemler) giriş yapılır: kapalı ve açık yöntemler, ortalama değer teoremi, ara değer teoremi, süreklilik ve iteratif yöntemlerde durma ölçütü.
- Hoca, dersi derste öğrenmenin ve ezberlemek yerine mantığı anlamanın önemini tekrar vurgular. Sınav soruları derste çözülen örneklerin "şekil değiştirmiş" hâlleridir, çoğu zaman daha basittir. Gelecek derslerde yanınızda kağıt, kalem ve hesap makinesi olsun. Bazı adımları öğrencilerin kendisinin yapması istenecek.
- Taylor serisinin kapalı (kompakt) gösterimi
  - $f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n$. Maclaurin için $x_0 = 0$: $f(x) = \sum_{n=0}^{\infty} \frac{f^{(n)}(0)}{n!} x^n$.
  - $n$. türev $x_0$ noktasında genel bir formülle yazılabilirse terimleri tek tek hesaplamaya gerek kalmaz. "5. dereceye kadar" denince toplamın üst sınırına 5 konur. Bu algoritmik bir düşünmedir: tekrar eden deseni genelleştirmek. Kodda bir `for` döngüsü ve çarpma-bölmeyle hesaplanır.
  - Örnek 1: $e^x$'in $x = 4$ noktasındaki Taylor serisi. Bütün türevler $e^x$'tir, $x = 4$'te $e^4$. $e^x = \sum_{n=0}^{\infty} \frac{e^4}{n!}(x - 4)^n$.
  - Örnek 2: $\frac{1}{x}$'in $x = 2$ noktasındaki Taylor serisi. Önce fonksiyonun seriye açılabildiği kontrol edilir: $x^{-1}$, $-x^{-2}$, $2x^{-3}$, $-6x^{-4}$… sonsuz kez türevlenebilir. İşaretler $(-1)^n$, katsayılar $n!$, üsler $-(n+1)$: $f^{(n)}(x) = (-1)^n n! \, x^{-(n+1)}$. $n!$'ler sadeleşince $\frac{1}{x} = \sum_{n=0}^{\infty} (-1)^n \frac{(x - 2)^n}{2^{n+1}}$.
  - Hoca, bir hocanın bile "seriye aç" demesine hemen inanmamak, önce fonksiyonun seriye açılabilir olduğunu kontrol etmek gerektiğini söyler.
  - Örnek 3: $e^{2x}$'in Maclaurin serisi. Türevler $2^n e^{2x}$, $x = 0$'da $2^n$. $e^{2x} = \sum_{n=0}^{\infty} \frac{2^n x^n}{n!}$.
- Kesme hatası (truncation error)
  - Bir değerin hesaplanması için sonsuz sayıda terim gerekirken sonlu sayıda terim alındığında oluşan hatadır. Belirli bir terimden sonra her yeni terim sonucu çok az değiştirdiği için (2, 2.5, 2.75, 2.77…) seri bir yerde kesilir ve bu hata kabul edilir.
  - Örnek: $e^{1.5}$, 3. dereceden Maclaurin açılımıyla: $1 + 1.5 + \frac{1.5^2}{2!} + \frac{1.5^3}{3!} = 4.1875$. Gerçek değer 4.4817. Kesme hatası yaklaşık 0.29. Bir terim daha eklenirse hata küçülür.
  - Hesap makineleri serinin kaç terimini kullandığını söylemez. Bir problemde "0.15 kesme hatasıyla bulun" denirse hata bu değerin altına inene kadar terim (iterasyon) eklenir.
  - Örnek: $f(x) = -0.1x^4 - 0.15x^3 - 0.5x^2 - 0.25x + 1.2$, $x_0 = 0$, $h = 1$ ($x_{i+1} = x_i + h$). $f(1)$, $f(0)$'dan başlayıp Taylor terimleri eklenerek 4. dereceye kadar hesaplanır. Gerçek değer $f(1) = 0.2$.
    - 0. derece: $f(1) \approx f(0) = 1.2$.
    - 1. derece: $f'(x) = -0.4x^3 - 0.45x^2 - x - 0.25$, $f'(0) = -0.25$. $f(1) \approx 1.2 - 0.25 = 0.95$.
    - 2. derece: $f''(x) = -1.2x^2 - 0.9x - 1$, $f''(0) = -1$. $\frac{-1}{2!} = -0.5$. $f(1) \approx 0.45$.
    - 3. derece: $f'''(x) = -2.4x - 0.9$, $f'''(0) = -0.9$. $\frac{-0.9}{3!} = -0.15$. $f(1) \approx 0.3$.
    - 4. derece: $f^{(4)} = -2.4$. $\frac{-2.4}{4!} = -0.1$. $f(1) \approx 0.2$. Hata sıfır olur, çünkü fonksiyon 4. dereceden bir polinomdur.
  - Örnek: $\cos\frac{\pi}{5}$, 4. dereceden Maclaurin açılımıyla: $1 - \frac{x^2}{2!} + \frac{x^4}{4!}$, $x = \frac{\pi}{5}$. Sonuç 0.809102, gerçek değer 0.809017. Kesme hatası çok küçüktür. Daha düşük dereceyle de az hatayla bulunabilir.
- Bağıl hata (relative error)
  - $\varepsilon_r = \frac{\text{gerçek} - \text{hesaplanan}}{\text{gerçek}}$. Yüzde olarak da verilir. Problemde istenen hata sınırı (ör. 0.001) çoğunlukla bağıl hata cinsindendir.
  - Örnek: $x^3$, $x = 2$ için gerçek değer 8. 6 bulunursa bağıl hata %25.
  - Örnek: $e \approx 2.718$ alınırsa bağıl hata $1.036 \times 10^{-4}$ (yani $0.1036 \times 10^{-3}$).
  - Neden gerekli? Köprü ve perçin örneği: köprüde 10.000 cm yerine 9.999 cm, perçinde 10 cm yerine 9 cm ölçülür. İkisinde de hata 1 cm'dir. Ama bağıl hata köprüde %0.01, perçinde %10'dur. Yalnızca farka bakmak büyük felaketlere yol açabilir. Birimlerle çalışırken bağıl hata kullanılmalıdır.
- Mutlak hata (absolute error)
  - Hatanın pozitif veya negatif olmasının önemi yoksa mutlak değer alınır. Hoca bunu bağıl hatanın mutlak değeri olarak anlatır.
  - Örnek: bir fonksiyonun $x = 2$'deki gerçek değeri -2, biri 10 hesaplamış. Pozitif-negatif karışıklığından kurtulmak için mutlak değer alınır.
- Yuvarlama hatası (rounding error)
  - Örnek: 27.35254316, 2D yuvarlama: üçüncü basamak 2 (5'ten küçük) olduğu için 27.35. Yuvarlanmış ve gerçek değer arasındaki fark yuvarlama hatasıdır. Öğrencilerle birkaç örnek daha yapıldı.
- Doğrusal olmayan denklemler
  - Tek bilinmeyenli bir denklemde derece 1 ise denklem doğrusaldır. Derece 1'den büyükse veya $e^x$, $\sin x$ gibi ifadeler içeriyorsa doğrusal değildir.
  - Doğrusal olmayan her denklem analitik olarak çözülemez değildir: $x^2 - 4x = 0$ kolayca çözülür. $e^{\sin x} \ldots$ gibi denklemler ise analitik olarak çok zordur, sayısal yöntemlerle hızlıca ve yaklaşık olarak çözülür. Ne kadar yaklaşık bulunduğu bir hata ölçütüyle belirtilir.
  - Kök için teorem: $f$, $[a, b]$ aralığında sürekli ve $f(a)$ ile $f(b)$ ters işaretliyse bu aralıkta en az bir gerçek kök vardır. Aralıkta birden fazla kök varsa yöntem bunlardan yalnızca birini bulur. Diğer kökler için $a$ ve $b$ değiştirilir. Fonksiyon aralıkta süreksizse yöntemler sonuç vermez.
  - Yöntem seçimi, tek denklem mi denklem takımı mı olduğuna, kökün gerçek mi sanal mı olduğuna ve yaklaşık değer bilinip bilinmediğine göre yapılır.
  - Iraksama (divergence): iteratif olarak bulunan değerler birbirinden giderek uzaklaşıyorsa yöntem ıraksıyordur. O zaman başlangıç değerleri veya aralık değiştirilir, iterasyon sayısı artırılır. Kod yazarken kullanıcıdan yeni değerler istenebilir.
- Kapalı ve açık yöntemler
  - Kapalı yöntemler: kök, alt ve üst sınırla belirlenen bir aralığın içindedir. Her iterasyonda $a$, $b$ veya ikisi köke yaklaşır. İterasyon arttıkça gerçek değere yaklaşıldığı için yakınsaktırlar (convergent): ardışık sonuçlar arasındaki fark küçülür (10, 8, 7, 6, 5.5, 5.4…). Iraksamazlar ama daha çok iterasyon gerektirirler. Bu derste: grafik yöntemi, ikiye bölme (bisection), regula falsi (false position, doğrusal interpolasyon, yanlış nokta).
  - Açık yöntemler: tek bir başlangıç değeri veya kökü kıskaca almayan iki başlangıç değeri kullanır (ikisi de kökün aynı tarafında olabilir). Iraksayabilirler, ama yakınsarlarsa kapalı yöntemlerden daha hızlıdır (100 yerine 40 iterasyon gibi). Bu derste: Newton-Raphson, sekant (kiriş), basit iterasyon (sabit nokta, fixed point iteration).
- Ortalama değer teoremi (mean value theorem)
  - $f$, $[a, b]$ aralığında sürekli ve türevlenebilirse aralıkta $f'(c) = \frac{f(b) - f(a)}{b - a}$ eşitliğini sağlayan bir $c$ noktası vardır. Sağ taraf, $a$ ve $b$'deki noktaları birleştiren doğrunun eğimidir (tan α). $c$, fonksiyonun bu doğruya paralel teğetinin değdiği noktadır.
  - Örnek: $f(x) = x^2 + 5$, $[1, 5]$. $\frac{f(5) - f(1)}{5 - 1} = \frac{30 - 6}{4} = 6$. $f'(x) = 2x = 6$, $c = 3$.
  - Fonksiyonda kaç tane böyle teğet noktası varsa o kadar $c$ değeri vardır. Fonksiyonun dalgalanma sayısı bunu belirler.
  - Örnek: $f(x) = x^3 + 2x - 5$, $[-1, 1]$. $\frac{f(1) - f(-1)}{2} = \frac{-2 - (-8)}{2} = 3$. $f'(x) = 3x^2 + 2 = 3$, $c = \pm\frac{1}{\sqrt{3}}$. İki değer de aralıktadır.
  - Neden işe yarar? Bir fonksiyonun türevini almak zorsa, aralıktaki bir noktadaki türevin değeri fonksiyon değerlerinden hesaplanabilir. Minimum-maksimum problemlerinde türevle uğraşmadan sonuca ulaşmayı sağlar.
- Ara değer teoremi (intermediate value theorem)
  - $f$, $[a, b]$ aralığında sürekli ve $f(a) \ne f(b)$ ise $f(a)$ ile $f(b)$ arasındaki her değer, aralıktaki bir $c$ noktasında alınır.
  - Kök için kullanımı: $f(a) \cdot f(b) < 0$ ise aralıkta en az bir kök vardır. İki değer de pozitif veya ikisi de negatifse çarpım pozitiftir.
  - Örnek: $x^3 - 5x + 1$, $[1, 3]$. Önce süreklilik gösterilir: tanımsız olduğu bir nokta yok (paydası sıfır olan bir terim yok), parçalı değil, her yerde sürekli. Sonra $f(1) = -3$, $f(3) = 13$, çarpım negatif. Bu aralıkta en az bir kök vardır.
  - Bulunan kök fonksiyonda yerine konunca tam sıfır vermeyebilir. Fark istenen hata sınırının üstündeyse aralık veya iterasyon sayısıyla oynanır.
- Süreklilik ve limit
  - Parçalı fonksiyonlar (ör. $x > 3$ ve $x \le 3$ için farklı ifadeler) ve tanımsız noktası olan fonksiyonlar (ör. $x = 3$'te paydası sıfır olan) o noktalarda sürekli olmayabilir.
  - Fonksiyon bir noktada sürekliyse orada limiti vardır. Ama limitin olması sürekliliği gerektirmez: sağdan ve soldan limitler eşitse limit vardır, fonksiyonun o noktadaki değeri farklı olsa bile. Sağdan ve soldan limitler farklıysa (ör. 9 ve 6) limit yoktur.
  - Süreksiz bir fonksiyonun kökü bu yöntemlerle bulunamaz.
- İteratif yöntemlerde durma ölçütü
  - Gerçek kök biliniyorsa: bağıl hata $\left|\frac{x_{gerçek} - x_n}{x_{gerçek}}\right| \le \varepsilon$ olunca durulur. Sağlanmazsa iterasyon artırılır.
  - Gerçek kök bilinmiyorsa: hoca $\frac{|b - a|}{2^n} \le \varepsilon$ ölçütünü verir. Elle çözerken $|b - a| \le \varepsilon$'a bakmak daha pratiktir. Burada $b$ son bulunan, $a$ bir önceki değerdir.
  - $\varepsilon$ uygulamaya göre belirlenir. Ameliyat, inşaat veya bankacılık gibi alanlarda büyük hata kabul edilemez. Sınavda 0.1 gibi büyük hatalar verilebilir ki iterasyon sayısı az olsun. Kod yazarken en az $10^{-3}$ alın.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir fonksiyonu seriye açmadan önce sonsuz kez türevlenebilir olduğunu kontrol edin.
- Türevlerdeki deseni genelleştirin. Böylece $n$. dereceye kadar açılımı terimleri tek tek hesaplamadan yazabilirsiniz.
- Birimlerle çalışırken yalnızca farka değil, bağıl hataya bakın.
- Kök aramadan önce fonksiyonun aralıkta sürekli olduğunu ve $f(a) \cdot f(b) < 0$ olduğunu gösterin.
- Kapalı yöntemler ıraksamaz ama yavaştır. Açık yöntemler hızlıdır ama ıraksayabilir.
- Kağıt kalemle pratik yapmazsanız sınavda süre yetmez.

## Kısa Tekrar Notları

- $e^{2x} = \sum \frac{2^n x^n}{n!}$, $\frac{1}{x}$ ($x_0 = 2$) $= \sum (-1)^n \frac{(x-2)^n}{2^{n+1}}$.
- Kesme hatası: serinin sonlu terimle kesilmesinden doğar. $e^{1.5}$ (3. derece) $= 4.1875$, hata 0.29.
- Bağıl hata: $\frac{\text{gerçek} - \text{yaklaşık}}{\text{gerçek}}$.
- Bolzano: sürekli $f$ ve $f(a) f(b) < 0$ ise $(a, b)$'de kök var.
- Ortalama değer: $f'(c) = \frac{f(b) - f(a)}{b - a}$.
- Kapalı: grafik, ikiye bölme, regula falsi. Açık: Newton-Raphson, sekant, basit iterasyon.

## Detaylı Açıklamalar

### Ders sonrası notlar

- **Örneklerin kontrolü:** Ders sonrasında hesaplandı. $e^{1.5}$ için 3. dereceden açılım 4.1875, gerçek değer 4.48169, kesme hatası 0.2942. $\cos\frac{\pi}{5}$ için 4. dereceden açılım 0.809102, gerçek değer 0.809017, kesme hatası yaklaşık $-8.5 \times 10^{-5}$. $e \approx 2.718$ için bağıl hata $1.0368 \times 10^{-4}$. Polinom örneğinde $f(0) = 1.2$ ve $f(1) = 0.2$. Hepsi derste söylenenlerle aynıdır.
- **Mutlak hata ve bağıl hatanın tanımı:** Hoca mutlak hatayı "bağıl hatanın mutlak değeri" olarak anlattı. Kaynakların çoğunda mutlak hata $|\text{gerçek} - \text{yaklaşık}|$, bağıl hata $\frac{|\text{gerçek} - \text{yaklaşık}|}{|\text{gerçek}|}$ olarak tanımlanır. Yani mutlak hatada gerçek değere bölme yoktur. Bağıl hatanın mutlak değerine "mutlak bağıl hata" denir. Sınavda hangi tanımın beklendiğine dikkat edin.
- **Ortalama değer teoreminde $c$ ile eğim:** Derste bir an "$c$ değeri $\frac{f(b) - f(a)}{b - a}$'dır" denildi. Bu oran $c$'nin kendisi değil, $c$ noktasındaki türevin (eğimin) değeridir. İlk örnekte oran 6, $c = 3$'tür. Teorem ayrıca fonksiyonun $(a, b)$ aralığında türevlenebilir olmasını gerektirir.
- **$f(a) \cdot f(b) > 0$ durumu:** Çarpım pozitifse aralıkta kök olmadığı kesin değildir. Fonksiyon aralıkta x eksenini çift sayıda kesebilir (ör. iki kök). Bu yüzden teorem yalnızca "$f(a) f(b) < 0$ ise kök vardır" der, tersini söylemez.
- **Durma ölçütü:** $\frac{|b - a|}{2^n} \le \varepsilon$ ölçütü ikiye bölme yöntemine özgüdür: $n$ adım sonunda kökü içeren aralığın uzunluğu $\frac{b - a}{2^n}$ olur. Burada $a$ ve $b$ başlangıç aralığının uçlarıdır. Diğer yöntemlerde genellikle ardışık iki yaklaşımın farkına bakılır: $|x_n - x_{n-1}| \le \varepsilon$ veya $\left|\frac{x_n - x_{n-1}}{x_n}\right| \le \varepsilon$.
- **Polinom örneğinde hatanın sıfır olması:** 4. dereceden polinomun 4. dereceden Taylor açılımı polinomun kendisidir. Bu yüzden 4. terimde hata tam sıfır oldu. Ders 1 notlarında belirtildiği gibi polinomlar sonlu bir Taylor serisine açılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
