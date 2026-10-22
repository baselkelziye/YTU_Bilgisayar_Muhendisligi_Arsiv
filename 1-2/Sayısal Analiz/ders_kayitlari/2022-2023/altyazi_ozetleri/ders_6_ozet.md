# Ders 6 Çalışma Özeti

## Genel Konular

- Duyurular
  - Derslikte ses ve kamera düzeni olmadığı için hibrit derste hoca laptopu masaya koyup yine PowerPoint üzerinden anlatacak. Tahtaya yazarsa online bağlananlar göremez.
  - Proje sunumlarına iki hafta ayrılmıştı ama sınıf 100 kişi. Bu yüzden sunumlar bir hafta öne çekiliyor: projesini önceden bitirenler 17 Mayıs haftasından itibaren gösterebilir. Projesini gösteren öğrenci başkalarının sunumlarını dinlemek zorunda değildir. 17 Mayıs haftası hibrit olacak. Ahmet Hoca bu konuda duyuru yapacak.
  - Vize iki parçalı olacak: bir kısmı test, bir kısmı klasik. Klasik bölümde normalde sorulan 4 sorudan daha az soru sorulacak. Ders kalem oynatmayı gerektirdiği için tamamı test olamaz.
  - Bölüm toplantısında vizelerin 8. hafta yapılmayacağı, 9. haftaya alınabileceği konuşuldu. Kesin tarih Ahmet Hoca ile konuşulduktan sonra bildirilecek.
  - İki grup şu an aynı yerde (integral). Online derste tahtaya yazma süresi olmadığı için konular daha hızlı ilerliyor.
- Sayısal integral
  - İntegral, $f(x)$ eğrisi ile $x$ ekseni arasında, $[a, b]$ aralığında kalan alandır. Fonksiyon bu aralıkta sürekli olmalıdır.
  - Sayısal integralde bu alan yaklaşık olarak hesaplanır. Alan bilinen geometrik şekillere (yamuk) bölünür veya parçalardan paraboller geçirilir. Parçaların alanları dört işlemle hesaplanıp toplanır. Bazı parçalar alana fazladan girer, bazıları eksik kalır. Bu farklar birbirini yaklaşık olarak dengeler.
  - Newton-Cotes formülleri kullanılır: $\int_a^b f(x)\,dx \approx \int_a^b f_n(x)\,dx$. $f_n$, $n$. dereceden bir polinomdur (doğru, parabol, kübik).
    - 1. derece (doğru): trapez (yamuk) kuralı. İki nokta.
    - 2. derece (parabol): Simpson 1/3 kuralı. Parabol fonksiyonu üç noktada keser.
    - 3. derece (kübik): Simpson 3/8 kuralı. Dört nokta, üç aralık.
  - Bir de iki katlı integral görülecek. Analitikte olduğu gibi önce iç integral, sonra dış integral çözülür.
- Trapez (yamuk) yöntemi
  - $[a, b]$ aralığı $n$ eşit parçaya bölünür. Parça genişliği $h = \Delta x = \frac{b - a}{n} = x_{i+1} - x_i$.
  - Her parçada $(x_i, y_i)$ ve $(x_{i+1}, y_{i+1})$ noktaları doğruyla birleştirilir ve bir yamuk oluşur. Yamuğun alanı $\frac{y_i + y_{i+1}}{2} \cdot h$ (alt taban + üst taban, bölü 2, çarpı yükseklik).
  - Bütün yamuklar toplanır: $S = \frac{y_0 + y_1}{2}h + \frac{y_1 + y_2}{2}h + \ldots + \frac{y_{n-1} + y_n}{2}h$. İç noktalar iki kez, uç noktalar bir kez geçer. Genel formül:
    - $I \approx h\left[\frac{f(x_0) + f(x_n)}{2} + \sum_{k=1}^{n-1} f(x_0 + kh)\right]$
  - $n$ ne kadar büyükse hata o kadar küçük olur. Bazen $h$ verilir, bazen $a$, $b$ ve $n$ verilir.
  - Örnek: $\int_0^1 \frac{1}{1 + x^2}dx$, $n = 4$.
    - $h = \frac{1 - 0}{4} = 0.25$. $x$: 0, 0.25, 0.5, 0.75, 1. $f(x)$: 1, 0.94, 0.8, 0.64, 0.5.
    - $I \approx 0.25\left[\frac{1 + 0.5}{2} + 0.94 + 0.8 + 0.64\right] = 0.78279$.
    - Analitik: $\arctan x \big|_0^1 = \arctan 1 - \arctan 0 = 45° = \frac{\pi}{4} = 0.78539$. Hata $|0.78539 - 0.78279| = 0.0026$.
    - $n = 9$ alınsaydı $I = 0.78488$, hata 0.00051 olurdu. $n$ arttıkça hata küçülür.
  - İntegral bir alan olduğu için birimi birim karedir (hacim hesaplanırsa birim küp).
  - Sınavda $n$ 4-5 gibi küçük verilir. Ama programda $n$'i 50, 60 gibi büyük verin ("elini korkak alıştırma").
- Simpson 1/3 kuralı
  - Her iki parçadan bir parabol $f(x) = ax^2 + bx + c$ geçirilir.
  - Formülün çıkarılışı: aralık $[-h, h]$ alınır ($a$, $b$ katsayılarıyla karışmasın diye).
    - $\int_{-h}^{h}(ax^2 + bx + c)\,dx = \frac{h}{3}(2ah^2 + 6c)$.
    - $y_0 = f(-h) = ah^2 - bh + c$, $y_1 = f(0) = c$, $y_2 = f(h) = ah^2 + bh + c$.
    - $y_0 + y_2 = 2ah^2 + 2c$, yani $2ah^2 = y_0 - 2y_1 + y_2$.
    - Yerine konunca tek bir parabol için: $S = \frac{h}{3}(y_0 + 4y_1 + y_2)$.
  - Parçalar ikişer ikişer alınır: $S_1 = \frac{h}{3}(y_0 + 4y_1 + y_2)$, $S_2 = \frac{h}{3}(y_2 + 4y_3 + y_4)$, … Toplanınca tek indisliler 4 ile, iç çift indisliler 2 ile çarpılır:
    - $I \approx \frac{h}{3}\left[f(x_0) + f(x_n) + 4\sum_{k=1,3,5,\ldots}^{n-1} f(x_0 + kh) + 2\sum_{i=2,4,6,\ldots}^{n-2} f(x_0 + ih)\right]$
  - **Uyarı:** Simpson'da çubuklar ikişer ikişer alındığı için aralık sayısı $n$ çift olmalıdır. Trapezde böyle bir şart yoktur.
  - Simpson trapezden daha hassas bir yöntemdir.
  - Örnek: $y = x^3$ eğrisi, $x = -1$, $x = 2$ ve $Ox$ ekseni ile sınırlı bölgenin alanı, $n = 4$.
    - Önce şekil çizilir: $x = -1$'de $y = -1$, $x = 0$'da $y = 0$, $x = 2$'de $y = 8$. Bölge iki parçadır: $[-1, 0]$'da eksenin altında, $[0, 2]$'de üstünde.
    - Alan negatif olamaz. Eksenin altındaki parçanın başına eksi konur veya mutlak değeri alınır. Ör. alanlar 3, 2 ve −2 bulunursa toplam 3 değil, 7'dir.
    - $S_1 = -\int_{-1}^{0} x^3 dx$, $h = 0.25$. $-x^3$ değerleri: 1, 0.4218, 0.125, 0.0156, 0. $S_1 = \frac{0.25}{3}[(1 + 0) + 2 \cdot 0.125 + 4(0.4218 + 0.0156)] = 0.2499$.
    - $S_2 = \int_0^2 x^3 dx$, $h = 0.5$. $f$: 0, 0.125, 1, 3.375, 8. $S_2 = \frac{0.5}{3}[(0 + 8) + 2 \cdot 1 + 4(0.125 + 3.375)] = 4$.
    - Toplam alan $\approx 4.25$ birim kare.
  - Sınıf alıştırması (eski vize sorusu): $f(x) = (x^2 - 1)(x + 2)$ eğrisinin altında ve $Ox$ ekseninin üstünde kalan bölgenin alanı, $n = 4$.
    - Kökler $-2$, $-1$, $1$. $x = 0$'da $f = -2$. Eğri yalnızca $[-2, -1]$ aralığında eksenin üstündedir. Bu yüzden integral sınırları $-2$ ve $-1$'dir.
    - $f(x) = x^3 + 2x^2 - x - 2$, $h = \frac{-1 - (-2)}{4} = 0.25$. $x$: −2, −1.75, −1.5, −1.25, −1.
    - Analitik: $\left[\frac{x^4}{4} + \frac{2x^3}{3} - \frac{x^2}{2} - 2x\right]_{-2}^{-1} = 0.41$ br². Trapez: 0.39. Simpson: 0.4166.
    - Hocanın mesajı: şekli kabaca çizmek için fonksiyonu sıfır yapan noktaları ve $x = 0$'daki değeri bulmak yeter. Sınırlar bu köklerdir. Bilinen şeyleri bir araya getirmekten korkmayın.
  - Sınavda kaç anlamlı basamak kullanılacağı söylenecek. Söylenmezse basamak sayısından kaynaklanan küçük farklar sorun değildir, önemli olan yöntemi doğru uygulamaktır.
- Simpson 3/8 kuralı
  - Fonksiyondan dört noktada kesen kübik bir polinom geçirilir. $[a, b]$ üç eşit parçaya bölünür:
    - $x_1 = a + \frac{b - a}{3}$, $x_2 = a + 2\frac{b - a}{3}$.
    - $\int_a^b f(x)\,dx \approx (b - a)\frac{f(a) + 3f(x_1) + 3f(x_2) + f(b)}{8}$
  - Formülün ispatı sayfalar sürer, sayısal analiz kitaplarında genellikle verilmez. Aklınızda kalsın: iç noktalar 3 ile çarpılır, toplam 8'e bölünür.
  - $n = 2$ ise $[a, b]$ ortadan ikiye bölünür, her yarıya formül ayrı ayrı uygulanıp toplanır. $n$ arttıkça sonuç daha hassas olur.
  - Örnek: $\int_0^6 \frac{1}{1 + x^4}dx$.
    - $n = 1$: $x_1 = 2$, $x_2 = 4$. $6 \cdot \frac{1 + 3 \cdot \frac{1}{17} + 3 \cdot \frac{1}{257} + \frac{1}{1297}}{8} \approx 0.8917$.
    - $n = 2$: $\int_0^3 + \int_3^6$, her parçanın genişliği 3, iç noktalar 1, 2 ve 4, 5. $1.0082 + 0.0110 \approx 1.0192$.
  - Ödev: aynı integrali trapez ve Simpson 1/3 ile çözün. Mümkünse analitik değeri de bulun ve hataları karşılaştırın. Gelecek ders bununla ilgili sorularla başlanacak.
- Ders planı: gelecek hafta iki katlı integral, ardından farklar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Simpson'da $n$ mutlaka çift olmalıdır.
- Alan negatif olamaz. Eksenin altında kalan parçaları ayrı hesaplayıp mutlak değerle toplayın.
- Alan sorularında önce şekli kabaca çizin: kökleri ve birkaç değeri bulmak yeter. Öğrencilerin en çok takıldığı yer şekli çizememek ve sınırları belirleyememektir.
- Anlatırken her şey anlaşılmış gibi gelir, ama soruyu kendiniz çözünce takıldığınız yerleri görürsünüz. Derste çözdürmenin amacı budur.
- Formüller bir iki örnekle akılda kalır: trapezde $h \times$ (uçların yarısı + iç noktalar), Simpson 1/3'te $\frac{h}{3} \times$ (uçlar + 4·tekler + 2·çiftler).
- Hata yapmak ayıp değildir. Hatayı görüp düzeltin ve aynı hataya tekrar düşmeyin.
- Programda $n$'i büyük seçin.

## Kısa Tekrar Notları

- $h = \frac{b - a}{n}$.
- Trapez: $I \approx h\left[\frac{f_0 + f_n}{2} + \sum_{k=1}^{n-1} f_k\right]$.
- Simpson 1/3: $I \approx \frac{h}{3}\left[f_0 + f_n + 4(f_1 + f_3 + \ldots) + 2(f_2 + f_4 + \ldots)\right]$, $n$ çift.
- Simpson 3/8 (tek parça): $I \approx (b - a)\frac{f(a) + 3f(x_1) + 3f(x_2) + f(b)}{8}$, $x_1 = a + \frac{b-a}{3}$, $x_2 = a + \frac{2(b-a)}{3}$.
- $\int_0^1 \frac{dx}{1+x^2} = \frac{\pi}{4} = 0.78539$. Trapez $n = 4$: 0.78279.

## Detaylı Açıklamalar

### Yöntemlerin hata mertebeleri

- Bileşik trapez kuralının hatası $h^2$ ile orantılıdır. $h$ yarıya inince hata yaklaşık dörtte birine iner. Örnekte $n = 4$'ten $n = 9$'a geçince hata 0.0026'dan 0.00051'e düştü.
- Bileşik Simpson 1/3 ve 3/8 kurallarının hatası $h^4$ ile orantılıdır. Bu yüzden aynı $n$ ile genellikle çok daha iyi sonuç verirler.
- Simpson kuralları 3. dereceye kadar polinomları **tam** hesaplar. Bu yüzden $x^3$ ve $(x^2 - 1)(x + 2)$ örneklerinde Simpson analitik sonucun aynısını verdi.

### Ders sonrası notlar

- **Örneklerin kontrolü:** Bütün örnekler ders sonrasında Python ile yeniden hesaplandı. Trapez ($n = 4$: 0.78279, $n = 9$: 0.78488), $x^3$ alanı, sınıf alıştırması ve 3/8 kuralı sonuçları slaytlarla aynıdır.
- **$\int_0^1 \frac{dx}{1+x^2}$ için Simpson:** Aynı tabloyla ($n = 4$) Simpson 1/3, 0.785392 verir. Hata yaklaşık $6 \times 10^{-6}$'dır. Trapezin hatası 0.0026 idi. Hocanın "Simpson ile hata daha küçük olurdu" sözünün sayısal karşılığı budur.
- **$x^3$ örneğinde tam sonuç:** Analitik olarak $S_1 = \frac{1}{4} = 0.25$, $S_2 = \frac{2^4}{4} = 4$, toplam 4.25'tir. Simpson polinomu tam hesapladığı için $S_1$'in doğru değeri 0.25'tir, slayttaki 0.2499 tablo değerlerinin (0.4218, 0.0156) yuvarlanmasından kaynaklanır. Bu örnekte trapez $S_1$ için 0.2656 verirdi.
- **Sınıf alıştırmasının tam değerleri:** Analitik sonuç $\frac{5}{12} = 0.41667$, Simpson ($n = 4$) 0.41667 (tam), trapez ($n = 4$) 0.39063. Şekildeki tepe değeri 0.625 aslında $x = -1.5$'teki değerdir. Gerçek maksimum $x \approx -1.549$'da yaklaşık 0.631'dir.
- **Simpson 3/8 örneğinde $n$ büyüdükçe:** $\int_0^6 \frac{dx}{1+x^4}$'ün gerçek değeri yaklaşık 1.10918'dir. Simpson 3/8 ile $n = 1$: 0.8917, $n = 2$: 1.0193, $n = 4$: 1.1202, $n = 10$: 1.1090. Fonksiyon $x = 0$ ile $x = 1$ arasında hızla düştüğü için az parçayla bu bölge iyi yakalanamıyor. $n$ arttıkça sonuç gerçek değere yaklaşıyor.
- **Ödevin cevabı (kontrol için, önce kendiniz çözün):** 3/8 kuralının $n = 2$ hâliyle aynı noktaları ($h = 1$, $x = 0, 1, \ldots, 6$) kullanırsak trapez 1.0769, Simpson 1/3 ($n = 6$) 1.0605 verir. Gerçek değer 1.1092'dir. Bu örnekte az sayıda nokta ile trapez, Simpson'dan daha yakın çıkmıştır. "Simpson her zaman daha iyidir" kuralı $h$ yeterince küçükken geçerlidir. Fonksiyon kaba bir ızgarada iyi temsil edilemiyorsa bu sıralama bozulabilir.
- **3/8 kuralında "n":** Slayttaki $n$, 3/8 kuralının kaç kez uygulandığını (alt aralık sayısını) gösterir. Her alt aralık kendi içinde 3 parçaya bölünür. Yani $n = 2$ için toplam 6 parça, 7 nokta kullanılır. Simpson 1/3'teki $n$ ise doğrudan parça sayısıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
