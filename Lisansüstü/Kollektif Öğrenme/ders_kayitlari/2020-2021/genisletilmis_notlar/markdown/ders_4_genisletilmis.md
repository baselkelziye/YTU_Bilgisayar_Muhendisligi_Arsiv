# Ders 4 Genişletilmiş Notu: Doğrusal Olmayan Regresyon, Stokastik Gradyan İnişi, AdaGrad ve Adam

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Doğrusal Regresyonun Tekrarı
- 3. Doğrusal Olmayan Regresyon ve Yinelemeli Kestirim
- 4. Jacobian ile Gradyan İnişi ve Newton-Raphson
- 5. Örnek 1: Y = sin(b1 X)
- 6. Örnek 2: Gauss Eğrisi ve Hata Yüzeyi
- 7. Örnek Sayısının Hata Yüzeyine Etkisi
- 8. Sonlu Toplam Biçimindeki Amaç Fonksiyonları
- 9. Gradyan İnişi ve Büyük Ölçekli Problemler
- 10. Basit Bir Model ve R Bölgesi
- 11. Stokastik Gradyan İnişi
- 12. SGD'nin Kararlı Hale Getirilmesi
- 13. Quasi-Newton Yöntemler ve AdaGrad
- 14. Adam
- 15. Adam Güncellemesinin Özellikleri
- Örnek Sorular

## 1. Dersin Planı

Bu derste önceki haftadan kalan regresyon konusu tamamlanır, ardından stokastik gradyan inişi (Stochastic Gradient Descent, SGD) ve onun türevleri işlenir. Böylece dersin optimizasyon kısmı bitmiş olur. Slaytlar hocanın optimizasyon dersi notlarından alınmıştır: önce `reg_mfa.pptx` (regresyon), sonra `sgd_quasi.pptx` ("Stochastic Gradient Descent, AdaGrad, ADAM") kullanılır (ekrandan, 00:15:00 ve 01:20:00). Örneklerin MATLAB kodları dersin web sayfasında paylaşılmıştır; slaytlarda her deneyin kod dosyası adı yazılıdır.

## 2. Doğrusal Regresyonun Tekrarı

### 2.1 Doğrusallık ölçütü

Regresyonda elimizde veri noktaları vardır: her noktanın bir girdisi ve bir çıktısı. Amaç girdiye karşılık çıktıyı üreten bir model bulmaktır. Bir önceki derste modelin doğrusal olup olmadığının ölçütü verilmişti: bulunacak katsayılara göre türev alındığında türevde hâlâ katsayı varsa model doğrusal değildir, yoksa doğrusaldır.

Slayttaki ilk örnekte iki katsayı $\beta_1$ ve $\beta_2$ vardır. $\beta_1$'e göre türev alınınca kalan ifadede (sinüs $x$ gibi) hiçbir $\beta$ yoktur; $\beta_2$'ye göre türev de $\beta_2$'den bağımsızdır. Bu yüzden model doğrusaldır. <!-- BELİRSİZ: İlk örnek modelin tam yazımı karelerde görülmedi. --> İkinci örnek $\beta_1 + \cos(\beta_2 x)$ biçimindedir. $\beta_1$'e göre türevde katsayı kalmaz, ama $\beta_2$'ye göre türevde $\beta_2$ kalır. Bu model doğrusal değildir. Hoca slayttaki "B2" yazımının "beta 2" olması gerektiğini de belirtti.

### 2.2 Analitik çözüm

Doğrusal durumda model $Y = X\beta$ biçimindedir; boyut ne kadar fazla olursa olsun ya da girdilerin kareleri alınmış olsun, yapı aynıdır. Amaç $\beta$'yı yalnız bırakmaktır. Sezgisel olarak iki taraf $X$'e bölünmek istenir, ama matrislerde bölme yoktur; onun yerine ters matrisle çarpılır. Slayttaki adımlar şöyledir (ekrandan, 00:15:00):

- $X^{-1}Y = X^{-1}X\beta$, çünkü $X^{-1}X = I$.
- $\beta = X^{-1}Y$. Ama $X$ kare matris değilse tersi yoktur.
- $X^TY = X^TX\beta$. $X^TX$ her zaman kare matristir.
- $(X^TX)^{-1}(X^TY) = (X^TX)^{-1}(X^TX)\beta$, çünkü $(X^TX)^{-1}(X^TX) = I$.
- $\beta = (X^TX)^{-1}(X^TY)$.

Bu yöntem her doğrusal model için uygulanabilir. Hoca bunun sorununu sordu.

**Soru:** Bu çözümde sorun nedir? **Cevap:** Boyutlar çok büyükse (örneğin milyona milyon) tersini almak pratikte mümkün olmaz. Hem bellek sorunu hem hız sorunu çıkar. Önceki hafta gösterildiği gibi ters alma süresi matris boyutuyla çok hızlı artar: boyut iki katına çıkınca süre iki katından çok daha fazla artar. Örnek sayısı çok fazlaysa tek adımda çözüm teoride mümkündür ama pratikte zorlayıcıdır.

> **Ders sonrası not:** Hoca ters alma süresinin boyutla "eksponansiyel" arttığını söyledi. Standart yöntemlerle bu maliyet büyük olasılıkla $O(d^3)$'tür; yani üstel değil polinomsal, ama hızlı artan bir maliyettir.

## 3. Doğrusal Olmayan Regresyon ve Yinelemeli Kestirim

### 3.1 İki yol

Model doğrusal değilse iki seçenek vardır:

- **Dönüşümler:** Modeli doğrusal bir modele çevirmek. Uygulanabildiğinde sorun yoktur, ama her zaman uygulanamaz. Slaytlarda bu dönüşümler için standart kurallar listelenmiştir (logaritma vb.); hoca bunları geçti.
- **Yinelemeli kestirim (iterative estimation):** Tek adımda analitik çözüm yerine, başlangıçta rastgele bir tahmin yapılır ve bu tahmin adım adım iyileştirilir. Bu, standart gradyan inişinin yaptığı iştir.

Model doğrusal olsa bile büyük boyutlarda ters alma pahalı olduğu için yinelemeli kestirim kullanılabilir, hatta gerekebilir.

### 3.2 Kurulum

Slayttaki tanımlar şunlardır (ekrandan, 00:25:00):

- Veri $= \{x_i, y_i\}$, $i = 1..n$ ($n$ veri noktası sayısı). $x_i$ $d$ boyutlu bir vektör, $y_i$ bir sayıdır.
- $y = f(\beta, x)$: $x$ girdi, $\beta$ modelin öğreneceği parametreler.
- $x$ bir $n\times d$ matris, $y$ bir $n\times 1$ matristir.
- $r_i = y_i - f(\beta, x_i)$: artıklar (residuals), $r$ bir $n\times 1$ matristir. $f(\beta, x_i)$ o anki $\beta$'ya göre tahmindir; gerçek ile tahmin arasındaki fark hatadır.
- $\beta$: optimize edilecek parametreler.
- $E(\beta) = \sum_i (r_i)^2$, $i = 1..n$.
- $\min_\beta E(\beta)$.
- $dE(\beta)/d\beta = 0$ ($E$'yi $\beta$'ya göre optimize et).

Yani amaç, artıkların karelerinin toplamı olan kayıp fonksiyonunu minimize eden $\beta$'yı bulmaktır.

### 3.3 Türevin sıfır olduğu noktalar

**Soru:** Konveks bir fonksiyonda türevin sıfır olduğu yer nedir? **Cevap:** Global minimumdur.

**Soru:** Fonksiyon konveks değilse türevin sıfır olduğu yer ne olabilir? **Cevap:** Yerel minimum, yerel maksimum ya da eyer noktası (saddle point). Maksimumda da eyer noktasında da türev sıfırdır.

Gradyan inişi her zaman türevin sıfır olduğu yere, minimuma doğru gider. Newton'da bazen sorunlar çıkabildiği önceki hafta görülmüştü. Bunlar kontrollerle düzeltilebilir: amaç kaybın sürekli azalmasıdır; ikinci dereceden bir yöntemde kayıp bir adımda artıyorsa o güncelleme kabul edilmez. Bu tür ön ya da son kontrollerle Newton yine kullanılabilir.

**Soru:** Newton'un, yani ikinci dereceden bilgiyi kullanmanın iyi yanı nedir? **Cevap:** Adım sayısı çok düşüktür. Gradyan inişi fonksiyonu o noktada doğrusal kabul eder; ikinci dereceden bilgi ise o noktaya kuadratik bir şey oturtur ve onun minimumunu bir sonraki adımda verir. Fonksiyonun kendisi kuadratikse tek adımda minimuma ulaşılır. Değilse tek adımda ulaşılmaz, ama birinci dereceden yöntemlerden çok daha hızlı yakınsar.

**Soru:** Kötü yanı nedir? **Cevap:** Kararsız olabilir; ayrıca yavaştır. Bir öğrenci, kodları denediğinde gradyan inişinin sonucu çok kısa sürede verdiğini, ikinci dereceden Newton-Raphson'un ise bilgisayarı uzun süre çalıştırdığını anlattı. Hoca şöyle açıkladı: Newton adım sayısı bakımından daha az adımda sonuca varır, ama her adımda Hessian matrisinin tersini almak gerekir. Bu matris örnek sayısına değil boyut sayısına bağlıdır ($d\times d$), yine de boyut büyükse işi çok yavaşlatır.

## 4. Jacobian ile Gradyan İnişi ve Newton-Raphson

### 4.1 Jacobian matrisi

$E = \sum r_i^2$ fonksiyonunun $\beta$'ya göre türevi alınır. $r^2$'nin türevi $2r\cdot dr/d\beta$'dır. $dr/d\beta$, yani artıkların $\beta$'ya göre türevi, $n\times d$ bir matristir: her satır bir örneğin artığına, her sütun bir parametreye karşılık gelir. Bu matrise **Jacobian matrisi** ($J$) denir.

Gradyan inişinde güncelleme $\epsilon$ çarpı o noktadaki türevdir. Türev $2J^Tr$'dir; 2 çarpanı $\epsilon$'a katılabileceği için önemli değildir. Böylece standart gradyan inişi $J^Tr$ ile yazılır. Boyut kontrolü: $J^T$ $d\times n$, $r$ $n\times 1$; sonuç $d\times 1$ bir vektördür.

### 4.2 Newton-Raphson ve $J^TJ$ yaklaşıklığı

Slayttaki formüller şunlardır (ekrandan, 00:30:00):

- $\beta_{k+1} = \beta_k - \text{eps}\cdot dE(\beta)/d\beta$ (gradyan inişi)
- $\beta_{k+1} = \beta_k - (dE(\beta)/d\beta)\,/\,(ddE(\beta)/dd\beta)$ (Newton-Raphson)
- $ddE(\beta)/dd\beta \approx J^T J$
- $\beta_{k+1} = \beta_k - (J^Tr)\,/\,(J^TJ)$
- $\beta_{k+1} = \beta_k - \text{inv}(J^TJ)\,(J^Tr)$
- $\text{pinv}(J) = \text{inv}(J^TJ)\,J^T$
- $\beta_{k+1} = \beta_k - \text{pinv}(J)\,r$ (Newton-Raphson)
- $\beta_{k+1} = \beta_k - \text{eps}\cdot J^Tr$ (gradyan inişi)

Newton-Raphson'da $k+1$. adımdaki $\beta$, $k$. adımdaki $\beta$'dan birinci türevin ikinci türeve bölümü çıkarılarak bulunur. İkinci türev yerine Jacobian'ın transpozu ile kendisinin çarpımı $J^TJ$ kullanılır. Hoca burada eşitlik değil yaklaşıklık olduğunu vurguladı: Jacobian birinci dereceden türevlerden oluşur; iki birinci türevi çarpınca ikinci türev elde edilmez. Yani bu yöntem yaklaşıktır, ama ikinci türev hesaplamayı ortadan kaldırır ve Newton kadar olmasa da gradyan inişinden daha hızlı yakınsama sağlar.

Bölme yerine ters ile çarpılır. $\text{inv}(J^TJ)J^T$ ifadesine **sözde ters (pseudo-inverse)** denir ve $\text{pinv}(J)$ diye yazılır. Böylece Newton-Raphson güncellemesi $\beta_{k+1} = \beta_k - \text{pinv}(J)\,r$ biçiminde çok sade görünür; ama sade görünmesi hesabın basit olduğu anlamına gelmez, çünkü $\text{pinv}$ içinde ters alma vardır.

> **Ek bilgi (derste anlatılmadı):** Artıkların kareler toplamını minimize ederken Hessian yerine $J^TJ$ kullanan bu yöntem literatürde Gauss-Newton yöntemi diye bilinir. Atlanan terim, artıklar ile artıkların ikinci türevlerinin çarpımıdır; artıklar küçükken bu terim de küçük olduğu için yaklaşıklık iyi çalışır.

## 5. Örnek 1: Y = sin(b1 X)

### 5.1 Problem

Model $y = \sin(\beta_1 x)$ olsun. Bize bir sürü $x$ ve her birine karşılık istenen $y$ verilir; modelin bu biçimde olduğu varsayılır ve verilere en uygun $\beta_1$ aranır. $\beta_1$ 0.2, 5, 6 gibi çok farklı değerler alabilir. $\beta_1$ bir yerden başlatılıp adım adım ilerletilir.

Slayttaki gösterimde (ekrandan, 00:40:00): mavi noktalar veridir, yeşil çizgi başlangıç tahmini, mavi çizgiler ara tahminler, kırmızı çizgi son tahmindir. Gerçek $b = -0.5$'tir; başlangıç $b = -1$ alındığında başlangıç modeli $y = \sin(-x)$ olur. Beklenen hareket $-1$'den $-0.5$'e doğrudur.

### 5.2 Newton-Raphson, başlangıç b = -1

Hoca önce bunu gradyan inişi diye anlattı, sonra bir öğrencinin uyarısıyla bu slaytın Newton-Raphson olduğunu düzeltti. Slaytta "Newton raphson, Real b=-0.5, initial b=-1", kod `Non_lin_reg0.m`; grafiğin başlığında "optimal MSE=0.010933 current MSE=0.0109 B=[-0.5] Bhat=[-0.50145]" yazılıdır (ekrandan, 00:35:00). Sağdaki grafik iterasyonlara göre MSE'yi gösterir: MSE yaklaşık 7. iterasyonda sıfıra çok yakın bir değere iner ve sonra değişmez. Yeşilden başlayan eğri her adımda biraz kayar ve sonunda veriye oturur.

**Soru:** MSE tamamen sıfır olabilir mi? **Cevap:** Bir öğrenci "sistem ezberlediğinde" dedi; hoca bu modelin ezberleyemeyeceğini, $\beta$'nın yerine ne konursa konsun bütün noktalardan geçemeyeceğini söyledi. Veriye gürültü eklenmiştir. MSE ancak bütün veri noktaları tam $y = \sin(-0.5x)$ eğrisinin üzerinde olsaydı sıfıra inebilirdi. Gürültülü veride sıfıra yakın bir yerde kalınır.

### 5.3 Gradyan inişi ve adım büyüklüğü

Gradyan inişi küçük adımlarla iyi çalışır. Adım büyüklüğü büyütüldüğünde MSE sıfıra yakın bir yere bile inemez: son kırmızı eğri veriye genel olarak uymaz, salınır. (Slayt küçük resimlerinde gradyan inişi için iki farklı Eps değeri görülüyor; küçüğü 0.0005, büyüğü 0.01 gibi okunuyor.) <!-- BELİRSİZ: Eps değerleri yalnız küçük slayt önizlemelerinden okundu. -->

### 5.4 Newton-Raphson, başlangıç b = -2

Aynı yöntem $b = -2$'den başlatıldığında istenen sonuç alınamaz; eğri veriye oturmaz, salınan bir eğride kalır.

**Soru:** $-1$'den başlayınca istenen yere varılıyor, $-2$'den başlayınca varılamıyor. Newton-Raphson'da adım büyüklüğü yok; sorun ne? **Cevap:** Slaytta $b_1$'in farklı değerleri için MSE çizilmiştir ("b1 vs. error", `Non_lin_reg1.m`). Bu eğri konveks değildir. $-1$'den başlanınca eğri boyunca aşağı inilir ve iyi bir minimuma varılır. $-2$'den başlanınca yakındaki başka bir çukura, yerel minimuma inilir. Konveks olmayan bir fonksiyonda başlangıç noktası varılacak yeri büyük ölçüde belirler. Yaklaşık $-1$ ile $-0.3$/$-0.4$ arasındaki başlangıçlar iyi sonuca gider; bu aralığın dışındaki ilk değerlerde yerel, global olmayan bir minimum bulunur.

> **Ders sonrası not:** Python ile denendi: gürültülü $y = \sin(-0.5x)$ verisinde (200 nokta, $x \in [-8, 8]$) $\beta_{k+1} = \beta_k - \text{pinv}(J)\,r$ güncellemesi $b = -1$'den başlayınca $-0.499$'a (MSE ≈ 0.009), $b = -2$'den başlayınca yaklaşık $-2.34$'teki yerel minimuma (MSE ≈ 0.89) gidiyor. Derste gösterilen davranışla uyumludur.

Tek bir parametre olsa bile model doğrusal değilse bu tür sorunlar görülebilir.

## 6. Örnek 2: Gauss Eğrisi ve Hata Yüzeyi

### 6.1 Problem

Şimdi model yine doğrusal olmayan ama iki parametreli bir Gauss eğrisidir (ekrandan, 00:40:00):

$$Y = \exp\left(-\frac{(X - B_1)^2}{2B_2^2}\right)$$

Veride gürültü bu kez daha azdır. $B_1$ ve $B_2$ birlikte bulunmaya çalışılır. Slayttaki değerler: gerçek $B = [-0.2;\ 1.5]$, başlangıç $B = [-2;\ -0.2]$, kod `Non_lin_reg2.m`.

### 6.2 Gradyan inişi ve Newton-Raphson

Gradyan inişi Eps $= 0.1$ ile her adımda eğriyi kaydırır ve 3-4 adım sonra oldukça iyi bir yere oturur; son kırmızı eğri veriye uyar. Grafik başlığında "optimal MSE=1.5114e-005 current MSE=0.00016955 B=[-0.2 1.5] Bhat=[-0.2082 -1.4744]" yazılıdır (ekrandan, 00:40:00). Bulunan $B_2$ değerinin negatif olduğuna dikkat edin; bunun sebebi aşağıda simetri tartışmasında ortaya çıkar.

Adım büyüklüğü küçültülünce aynı başlangıçtan daha küçük adımlarla ilerlenir. Maksimum iterasyon 10 olduğu için 10. adımda henüz sonuca varılmamıştır.

**Soru:** Devam ettirilirse sonuca varır mı? **Cevap:** Varır. Önünde bir engel yoktur; yavaş yavaş kıvrılarak aşağı iner.

Newton-Raphson'a adım büyüklüğü verilmez; 8-9 iterasyonda birden istenen hale oturur.

### 6.3 Hata yüzeyi ve simetri

Slaytta $B_1$ ve $B_2$'nin $-4$ ile $+4$ arasındaki her değeri için 200 verinin artık kareleri toplamı çizilmiştir ("b vs. error", $N = 200$; $B = [-0.2;\ 1.5]$, `Non_lin_reg3.m`) (ekrandan, 00:45:00). Hem üç boyutlu yüzey hem yukarıdan görünüm verilmiştir.

**Soru:** Bu fonksiyon konveks mi? **Cevap:** Değil.

Yüzeyde iki minimum vardır ve ikisinin hata değeri aşağı yukarı aynıdır. Slaytta "Why symmetric?" diye sorulur.

**Soru:** Yüzey neden simetrik? **Cevap:** Bir öğrenci "$B_1$ ve $B_2$ birbirinin aynısı" dedi; hoca bunun doğru olmadığını söyledi. Başka bir öğrenci fonksiyonun $B_2$'ye göre çift olabileceğini önerdi. Hoca formüle bakmayı istedi: $B_2$ modelde kare olarak geçer. $B_2$'nin eksi ve artı değeri aynı çıktıyı üretir; 3 ile $-3$, 5 ile $-5$ hep aynı değeri verir. Bu yüzden yüzey $B_2 = 0$'a göre simetriktir.

> **Ders sonrası not:** Python ile kontrol edildi: $E(B_1, B_2) = E(B_1, -B_2)$ eşitliği her noktada sağlanıyor. Gradyan inişinin $B_2 \approx -1.47$ bulması da bu yüzden bir hata değildir; $-1.5$ ile $+1.5$ aynı modeli verir.

### 6.4 Sorunlu bölgeler

Bir çanağın içinden başlanırsa o çanağın minimumuna düşülür. Hangi minimuma düşüldüğü bu fonksiyon için sorun değildir, çünkü iki minimumun değeri aynıdır; $\sin$ örneğindeki gibi biri diğerinden çok kötü değildir. Sorunlu yerler iki çanağın arasındaki bölgelerdir: oradan başlanırsa aşağı inip öbür tarafa gidilebilir ve bir çanağa düşmek zorlaşır. Genel olarak, doğrusal olmamasına rağmen optimize etmesi çok zor bir fonksiyon değildir.

## 7. Örnek Sayısının Hata Yüzeyine Etkisi

Aynı model ve aynı parametrelerle bu kez yalnız 10 örnek kullanılır ("Sample size effect", $N = 10$; $B = [-0.2;\ 1.5]$; slaytta "It is more difficult. Why?") (ekrandan, 00:50:00).

**Soru:** İki yüzeyin farkı ne? **Cevap:** Bir öğrenci popülasyon, yani örnek sayısı dedi. $N = 200$ ile $N = 10$ arasındaki fark budur.

**Soru:** Hangi fonksiyonla uğraşmak daha kolay? **Cevap:** Bir öğrenci, 10 örnekli yüzeyle uğraşmanın daha zor olduğunu söyledi: 200 örnekte çanağın herhangi bir yerinden başlanınca minimuma düşmek kolaydır, burada ise düz bir yere inme ihtimali yüksektir.

Hoca düz alana dikkat çekti. Düz bir yerin türevi sıfırdır; optimizasyon orada durur, ilerlemesi için bir sebep kalmaz. 200 örnekli yüzeyde de küçük düz bölgeler olabilir, ama 10 örnekte kocaman bir düz bölge vardır.

**Soru:** Örnek sayısının büyük ya da küçük olması nasıl bir etki yapıyor? **Cevap:** Örnek çoksa modelleme kolaylaşır. Hoca bunu şöyle açıkladı: az örnek varken o örneklere uydurulabilecek ve benzer başarıda çok sayıda model vardır. Çok örnek varken "şuna da uysun, buna da uysun" diye çok daha fazla kısıt konur; uygun parametre ikililerinin sayısı azalır. Bu nedenle az örnekle elde edilen modelin varyansı yüksektir: farklı başlangıçlardan çok farklı yerlerde sonlanılır. Çok örnekte, kötü bölgeler sayılmazsa, sonuçlar iki çanaktan birinde biter ve varyans düşüktür.

Doğrusal bir modelde bu durum kötü değildir. Slayttaki örnekte $\beta_1 x + \beta_2 x^3$ modeli 10 örnekle optimize edilir; model parametrelerde doğrusal olduğu için hata yüzeyi konvekstir ve nereden başlanırsa başlansın sonuca varılır.

## 8. Sonlu Toplam Biçimindeki Amaç Fonksiyonları

Aradan sonra SGD slaytlarına geçilir. Makine öğrenmesindeki optimizasyon problemlerinde amaç fonksiyonu birçok $f_i$'nin toplamından oluşur ("Finite sum of functions"):

$$f(x) = \frac{1}{n}\sum_{i=1}^n f_i(x)$$

Burada $x$ optimize edilecek parametredir (önceki slaytlardaki $\beta$ gibi düşünülmeli), $f_i(x)$ o andaki $x$ için $i$. eğitim noktasının kaybıdır (örneğin tahmin ile gerçek arasındaki farkın karesi), $n$ eğitim kümesinin büyüklüğüdür. Yani kayıp, tek tek eğitim noktalarının kayıplarından oluşur. Hata yüzeyleri çizilirken her $\beta_1, \beta_2$ için bütün noktaların artıklarının toplanması da tam olarak buydu.

Slayttaki örnekler (ekrandan, 01:20:00):

- Eğitim kümesi: $i = 1..n$, $a_i$: $i$. girdi, $b_i$: $i$. çıktı; $x$: eğitilecek modelin parametreleri.
- En küçük kareler: $\min_x \frac{1}{n}\sum_{i=1}^n (a_i^Tx - b_i)^2 = \min_x \frac{1}{n}\sum_{i=1}^n (f_i(x))^2$. $a_i^Tx$ tahmindir; ondan $b_i$ çıkarılınca artık bulunur.
- Lasso: $\min_x \frac{1}{n}\sum_{i=1}^n (a_i^Tx - b_i)^2 + \lambda\sum_{j=1}^d |x_j|$. Düzenlileştirme (regularization) için ikinci bir terim eklenir: parametrenin her boyuttaki mutlak değerlerinin toplamı, yani 1-norm. Amaç hem artıkları hem parametrelerin büyüklüğünü küçük tutmaktır. $\lambda$ iki terimin etkisini dengeler. Hoca minimize edilenin parantez içindeki ifadenin tamamı olduğunu vurguladı.
- Yapay sinir ağı: $\min_x \frac{1}{n}\sum_{i=1}^n \text{loss}(ANN(x, a_i), b_i)$. Burada $x$ ağın ağırlıkları, $a_i$ girdilerdir. $ANN(x, a_i)$ $i$. girdi için tahmindir; bu tahmin ve $b_i$ bir kayıp fonksiyonuna (softmax tabanlı vb.) verilir. Bütün örnekler için hesaplanıp toplanır.

Bunlar, makine öğrenmesindeki kayıp fonksiyonlarının çoğunun birçok fonksiyonun toplamı olduğunu gösteren örneklerdir.

## 9. Gradyan İnişi ve Büyük Ölçekli Problemler

Gradyan inişi slaytı (ekrandan, 01:25:00):

$$x_{t+1} = x_t - \eta_t\nabla f(x_t) = x_t - \eta_t\sum_{i=1}^n \nabla f_i(x_t)$$

- $f(x_1, x_2) = x_1^2 + 2x_2^2$
- Öğrenme oranı $\eta_t = 0.1$
- 40. adımda yakınsar (kod: `hessian_gradyan.m`)

Bu örnekte eğitim ya da test örneği yoktur, kayıp fonksiyonu doğrudan verilmiştir. Konveks fonksiyonlarda yakınsama ölçütü, hedefe uzaklığın ya da ardışık gradyanlar arasındaki farkın belirli bir $\epsilon$'dan küçük olmasıdır.

> **Ders sonrası not:** Altyazıda öğrenme oranı "1.1" diye geçiyor; slaytta $0.1$ yazılıdır.

Sorun şudur: $x_t$'den $x_{t+1}$'e geçmek için $n$ tane $f_i$ fonksiyonunun türevini hesaplamak gerekir. Bu, $n\times d$ boyutlu Jacobian matrisini hesaplamak gibidir. Bir milyon nokta varsa bir milyon fonksiyon değerlendirilmelidir. Slaytta "Large scale problems" başlığı altında "Zillions of parameters (d), Zillions of data points (n), Each GD iteration requires n*d calculations" yazılıdır. Bir adım için her boyutta $n$ tane, toplam $n\cdot d$ hesap gerekir; $n$ ve $d$ büyüdükçe her iterasyonun maliyeti artar. Günümüzdeki problemlerin çoğu bu büyük ölçekli hale gelmiştir.

## 10. Basit Bir Model ve R Bölgesi

### 10.1 Model

Slayttaki basit model (ekrandan, 01:30:00):

$$\min_x \frac{1}{2n}\sum_{i=1}^n (a_i^Tx - b_i)^2 = \min_x \frac{1}{2n}\sum_{i=1}^n (f_i(x))^2$$

- $a_i$, $b_i$, $x$ skaler (1 boyutlu), $n = 8$; kod `sgd_how.m`.
- Eğitim noktaları; gerçek model $b = 1\cdot a$, mevcut model $b = -10a$.
- Karşılık gelen $f_i(x)$'ler: $(a_ix - b_i)^2$.

$\frac{1}{2}$ çarpanı karenin türevinde sadeleşmek içindir; $\frac{1}{n}$ ortalama almaktır. Gerçek $x = 1$'dir; bu durumda girdi ile çıktı birbirine eşittir. Noktalara biraz gürültü eklenmiştir. Optimizasyon $x = -10$'dan başlar.

### 10.2 Tekil kayıplar ve ortalama kayıp

Grafikte $x$'in $-10$ ile $+10$ arasındaki her değeri için 8 örneğin her birinin kaybı ayrı ayrı çizilmiştir; kesikli çizgi hepsinin ortalamasıdır. Model doğrusal olduğu için her $f_i$ konvekstir ve konveks fonksiyonların toplamı da konvekstir. Yakınlaştırılmış grafikte kesikli eğrinin minimumu gerçekten $x = 1$'dedir, ama tekil eğrilerin minimumları farklı yerlerdedir.

Kesikli eğrinin minimumu sıfır değildir, çünkü noktalar tek bir doğru üzerinde olmadığı için hepsinden geçen tek bir doğru yoktur. Oysa her tekil eğri sıfırdan geçer, çünkü tek bir noktadan geçen sonsuz sayıda doğru vardır.

### 10.3 R bölgesi

Slayttaki tanımlar (ekrandan, 01:35:00):

- $f_i(x) = \frac{1}{2}(a_ix - b_i)^2$
- $f(x) = \frac{1}{2n}\sum_{i=1}^n (a_ix - b_i)^2$
- $x^* = \min_x \frac{1}{2n}\sum_{i=1}^n (a_ix - b_i)^2$
- Bölge $R = [\min_i b_i/a_i,\ \max_i b_i/a_i]$, $x^* \in R$
- "For all $i$, $\nabla f_i(x)$ and $\nabla f(x)$ have the same sign outside R. So, if we use $\nabla f_i(x)$, we guarantee the improvement outside R. In R, we get chaos."

Optimum $x^*$ her zaman R'nin içindedir. İlginç olan R'nin dışıdır.

**Soru:** R'nin dışında ortalama fonksiyonun türeviyle tekil fonksiyonların türevlerinin işaretleri nasıl? **Cevap:** Aynı. Sol dış bölgede hepsinin ortalaması kullanılırsa da tek biri seçilirse de aynı yöne gidilir. Sağ dış bölgede de durum aynıdır (öğrenciler "sola", "sağa" diye yanıtladı).

Bu çok değerlidir: tam gradyanı kullanmak için her adımda $n\cdot d$ hesap gerekir; tek bir örneğin gradyanı için ise yalnız $d$ hesap yeter (bu tek boyutlu örnekte 1). R'nin dışında tekil gradyan ile tam gradyan arasında yön bakımından fark yoktur.

R'nin içinde ise durum farklıdır. Örneğin bir noktada tam gradyan bir yöne iterken bazı örneklerin gradyanları ters yöne iter. İçeride kaos oluşur.

## 11. Stokastik Gradyan İnişi

### 11.1 Gürültülü gradyan simülasyonu

Slayttaki SGD deneyi (ekrandan, 01:40:00):

- $x_{t+1} = x_t - \eta_t\nabla f_i(x_t)$
- $f(x_1, x_2) = x_1^2 + 2x_2^2$
- Öğrenme oranı $\eta_t = 0.1$
- Yakınsamıyor ("it does not converge"); kod `sgd.m`

Hoca burada tam gradyanı hesaplayıp üzerine belirli bir gürültü ekleyerek tekil gradyanları simüle ettiğini açıkladı. Eş yükselti eğrileri (level set) üzerinde tam gradyan $\nabla f$ eğriye diktir. Tekil $\nabla f_i$'ler farklı yönlerde olabilir; ama R'nin dışındayken hepsi yine bir miktar azalma sağlar. Bunların beklenen değeri tam gradyana eşittir: $E[\nabla f_i] = \nabla f$. Yani tam gradyana benzeyen ama onunla aynı olmayan vektörler elde edilir; bu da tam gradyana gürültü eklemekle simüle edilebilir.

Deneyde iterasyonlar başta düzgün biçimde optimuma doğru gider, ama optimum çevresinde yakınsamaz, bir "kaos" oluşur. Sebep: dışarıdayken R bölgesinin dışındaydık; içine girince bazı örnekler bir yöne, bazıları öbür yöne götürür. Her adımda bir örnek seçilir ve ona göre bir tarafa gidilir, bu yüzden yakınsama olmaz.

Bu yönteme **stokastik gradyan inişi** denir: fonksiyon tam $f$'ye göre değil, yalnız tek bir $i$. örneğe göre optimize edilir. Optimuma yaklaşır ama son noktayı koymakta zorlanır ve salınır.

### 11.2 Son değer yerine ortalama

Slayttaki açıklama:

- R bölgesi: bir alan (2 boyutta).
- R'nin dışında GD ve SGD birbirine çok benzer.
- R'nin içinde ($x^*$ yakınında) SGD dalgalanır.
- Son $x_t$ yerine $\text{mean}(x_t)$ ya da $\text{mean}(x_{t-k} \ldots x_t)$ kullanmak mantıklıdır.
- Burada son $x_t = [-0.2692,\ 0.3260]$, $\text{mean}(x_t) = [-0.1192,\ 0.0452]$.
- Her GD iterasyonu $d\cdot n$ hesap, her SGD iterasyonu $d$ hesap gerektirir.

Normal gradyan inişinde 10 iterasyon yapıldıysa çıktı olarak $x_{10}$ verilir. SGD'de bunun yerine ya baştan itibaren bütün değerlerin ya da son $k$ değerin ortalaması alınır. Hareket rastgeledir ama bu rastgele hareketin merkezi optimumdur; bu yüzden ortalama almak mantıklıdır. Bu örnekte optimum $(0, 0)$'dır ve yaklaşık 100 iterasyon yapılmıştır; ortalama, son değerden optimuma daha yakındır.

### 11.3 Öğrenme oranını azaltmak

Bu deneyde öğrenme oranı sabit $0.1$'dir. Standart SGD uygulamalarında öğrenme oranı bir değerden başlar ve adım adım azalır; amaç yakınsamayı sağlamaktır. Tam gradyanla ya da Newton-Raphson'la öğrenme oranı azaltılmasa da türev sıfırlandığı için kendiliğinden yakınsanır. Stokastik yapılarda ise belirli bir adım sonra mutlaka R bölgesine girilir ve oradan sonra kararlı bir yörünge yoktur. Bu zıplamaları durdurmak için öğrenme oranı adım adım sıfıra çok yakın bir değere düşürülür; örneğin her iterasyonda $0.99$ ile çarpılır. $\eta_t$ sıfıra yaklaşınca türev büyük olsa bile $x_{t+1}$ ile $x_t$ birbirine eşitlenir ve yakınsama olur (iyi ya da kötü bir yere, o ayrı mesele).

**Soru:** Örneğin 10 milyon parametreli bir yapay sinir ağında önceki değerlerin ortalamasını almanın sorunu ne olabilir? **Cevap:** Bir öğrenci, ortalama alınca optimumdan uzaklaşma ihtimali olabileceğini, özellikle boyut fazlayken, önerdi. Hoca bu örnekte ortalamanın son değerden daha iyi sonuç verdiğini hatırlattı ve soruyu üzerinde düşünülmek üzere açık bıraktı.

> **Ek bilgi (derste anlatılmadı):** Milyonlarca parametrede bütün ara parametre vektörlerinin ortalamasını tutmak ek bellek ister; ayrıca derin ağların kayıp yüzeyi konveks olmadığı için farklı bölgelerden geçen ağırlıkların ortalaması iyi bir nokta olmayabilir. Bu yüzden pratikte daha çok azalan öğrenme oranı kullanılır.

### 11.4 GD ile SGD'nin karşılaştırılması

Her GD iterasyonu $n\cdot d$ hesap, her SGD iterasyonu $d$ hesap gerektirir. Newton-Raphson ile gradyan inişi arasındaki ilişki burada da vardır: Newton-Raphson daha az adımda gider, gradyan inişi daha çok adım ister ama her adımı çok daha ucuzdur. Benzer şekilde SGD daha çok adıma ihtiyaç duyar ama her adımda çok daha az işlem yapar.

Hoca SGD'nin 1951'de yayımlanmış bir yöntem olduğunu, gradyan inişinin ise çok daha eski olduğunu (17.-18. yüzyıl civarı) söyledi. SGD'nin her adımda çok az hesap gerektirmesi, onu en çok kullanılan algoritma yapar.

> **Ders sonrası not:** Gradyan inişi büyük olasılıkla Cauchy'ye (1847) dayandırılır, yani 19. yüzyıla aittir. SGD'nin temeli olan Robbins-Monro makalesi gerçekten 1951 tarihlidir.

Stokastik algoritmaların temel özelliği, her iterasyonda bütün örnekleri kullanmak yerine örneklerden birini ya da bir kısmını kullanmaktır. Bu kısma **mini-batch** denir; derin öğrenme kütüphanelerinde verilen batch size budur. Böylece gürültülü gradyanlarla, yani tam gradyana benzeyen ama onun kadar doğru olmayan yönlerle ilerlenir. Gürültü gereksiz yere yanlış yöne saptırabilir ve zikzaklara yol açabilir. Daha çok adım gerekir, ama her adım tam gradyana göre çok daha ucuz olduğundan büyük ölçekli problemlerde en popüler algoritma SGD ve türevleridir.

## 12. SGD'nin Kararlı Hale Getirilmesi

Slayttaki iki yaklaşım (ekrandan, 01:50:00):

**Gradyan kırpma (gradient clipping):** Gradyanlar, normları en fazla önceden belirlenmiş bir $c$ değeri olacak şekilde yeniden ölçeklenir:

$$\text{if } \|\nabla f_i(x_t)\| \ge c \text{ then } \nabla f_i(x_t) = c\,\frac{\nabla f_i(x_t)}{\|\nabla f_i(x_t)\|}$$

Çok kötü bir örneğe denk gelinip türev çok yüksek çıkarsa çok büyük bir adım atılır ve süreç sapar. Kırpma ile gradyanın büyüklüğüne bir üst sınır konur; sapma olsa bile küçük olur. Tek satırlık bir işlemdir.

**Mini-batch:** Tek örnek yerine $k$ örnek kullanılır; $\nabla f_i(x_t)$'nin varyansı azalır:

$$x_{t+1} = x_t - \frac{\eta_t}{|K_t|}\sum_{j \in K_t}\nabla f_j(x_t)$$

Batch size 1 tam stokastiktir; $k$ alınca salınımlar azalır. Ama her iterasyon $k\cdot d$ işlem ister. Tam gradyanda bu $n\cdot d$ idi. $k$ büyüdükçe doğru gradyana o kadar yaklaşılır, ama hesap yükü ve bellek ihtiyacı da artar. Bu yüzden batch size çok büyük tutulamaz; çok büyük mimarilerde batch size küçültülünce model çalışabilir hale gelir.

## 13. Quasi-Newton Yöntemler ve AdaGrad

### 13.1 Motivasyon

Gradyan inişinin Newton-Raphson kadar hızlı olmadığı önceki hafta görülmüştü. Slayttaki örnekte $f(x_1, x_2) = x_1^2 + 8x_2^2$ fonksiyonunda, öğrenme oranı $0.1$ ile gradyan inişi zikzaklar çizerek ilerler. Hessian, yani ikinci dereceden bilgi kullanılınca bu gereksiz hareketler olmadan çok daha düzgün ve hızlı ilerlenir. <!-- BELİRSİZ: Fonksiyon altyazıdan "x1 kare artı 8 x2 kare" diye alındı; slayt küçük önizlemesinde de $x_1^2 + 8x_2^2$ gibi okunuyor, kare tam okunmadı. -->

Bundan sonraki algoritmalar Hessian'ı kullanmadan ona yakın davranış üreten yöntemlerdir. Jacobian'larla Hessian yerine yaklaşık bir değer kullanmak da bunlardan biriydi. Bu yöntemlere **quasi-Newton** denir: Newton ikinci dereceden yöntemdir, "quasi" ise "sanki öyleymiş gibi" demektir. Hessian'ı birebir değil, benzer biçimde simüle ederler. Amaç daha az adımda, sapmalar olmadan, düzgün biçimde ilerlemektir. Bu algoritmalar yalnız o anki gradyana değil, algoritmanın başından beri hesaplanan bütün gradyanlara bakar.

### 13.2 AdaGrad

Slayttaki tanım (ekrandan, 01:55:00):

- $G_t = \sum_{j=1}^t \nabla f(x_j)\,\nabla f(x_j)^T$
- $G_t$ (önceki bütün gradyanların dış çarpımlarının toplamı) Hessian'ı taklit eder.
- $G_t$: $d\times d$ matris.
- İki sürüm:
  - $x_{t+1} = x_t - \eta_t G_t^{-1/2}\nabla f(x_t)$: tam matrisin tersi ve karekökü $d\cdot d$ hesap ister.
  - $x_{t+1} = x_t - \eta_t\,\text{diag}(G_t)^{-1/2}\nabla f(x_t)$: köşegen matrisin ($d$ boyutlu vektör) tersi ve karekökü $d$ hesap ister.

$j$. adımdaki türev $d\times 1$'dir; transpozu $1\times d$'dir. Bunların çarpımı $d\times d$ bir matristir. Her $j$ için böyle bir matris oluşur; $t$'ye kadar hepsi toplanınca yine $d\times d$ bir matris elde edilir. Bir vektörün kendi transpozuyla çarpımına dış çarpım (outer product) denir. Bu matrisin Hessian'ı birebir değil ama süreci hızlandıracak biçimde taklit ettiği gösterilmiştir. Bu, Jacobian'ın transpozuyla çarpımına çok benzer.

Güncellemede $G_t^{-1/2}$ kısmı kaldırılırsa geriye standart gradyan inişi kalır. AdaGrad oraya $G_t^{-1/2}$ koyar. $G_t$ türevlerin karesi gibi bir büyüklük olduğu için karekökü alınır.

**Soru:** $G_t$ matrisinin köşegeninde ne vardır? **Cevap:** Öğrenciler "kareleri" ve "ikinci dereceden bir şey" dedi. Doğrusu: her boyuttaki gradyanların karelerinin toplamı. Bir vektör kendi transpozuyla çarpılınca oluşan matrisin köşegeni her elemanın kendisiyle çarpımı, yani karesidir. Bu yüzden köşegen sürümün hesabı $d$ işlemdir; $d\times d$ matrise gerek kalmaz. Köşegen sürümün de oldukça iyi çalıştığı gösterilmiştir.

> **Ders sonrası not:** Python ile kontrol edildi: rastgele gradyanlarla $\sum_j g_jg_j^T$ matrisinin köşegeni, her boyuttaki gradyan karelerinin toplamına eşit çıkıyor.

Stokastik olmayan sürümde gradyan inişi zikzakla giderken köşegen $G_t$ ve tam $G_t$ aynı başlangıçtan çok daha düzgün ve hızlı ilerler. Stokastik sürümde (ekrandan, 02:00:00) GD ($Lr = 0.1$) yine zikzak çizer ve sonunda salınır; köşegen $G_t$ ($Lr = 1$) ve tam $G_t$ ($Lr = 1$) çok daha düzgün yaklaşır, ama onlar da optimum çevresinde rastgele salınmaya başlar.

AdaGrad'ın önemli sürümü köşegen olanıdır, çünkü hesap maliyeti düşüktür ve çok fazla işlem yapmadan gradyan inişinden çok daha hızlı yakınsama sağlar. İkinci dereceden yöntemler kadar hızlı değildir.

## 14. Adam

### 14.1 Algoritma

Türevlerin karelerini toplamak ve bunun Hessian'ı taklit ettiği fikri, bugün yapay sinir ağlarında en çok kullanılan **Adam** algoritmasını doğurmuştur. AdaGrad ve RMSProp, Adam'ın esin kaynaklarıdır. Slayttaki algoritma (Kingma ve Ba, "Adam: A method for stochastic optimization", ICLR 2015) şöyledir (ekrandan, 02:05:00):

```text
Gerekli: alpha: adım büyüklüğü
Gerekli: beta1, beta2 in [0, 1): moment kestirimleri için üstel azalma oranları
Gerekli: f(theta): theta parametreli stokastik amaç fonksiyonu
Gerekli: theta_0: başlangıç parametre vektörü
m_0 <- 0   (1. moment vektörü)
v_0 <- 0   (2. moment vektörü)
t <- 0
while theta_t yakınsamadı do
    t <- t + 1
    g_t <- grad f_t(theta_{t-1})                    (t anındaki stokastik gradyan)
    m_t <- beta1 * m_{t-1} + (1 - beta1) * g_t      (yanlı 1. moment)
    v_t <- beta2 * v_{t-1} + (1 - beta2) * g_t^2    (yanlı 2. ham moment)
    m_hat_t <- m_t / (1 - beta1^t)                  (yanlılığı düzeltilmiş 1. moment)
    v_hat_t <- v_t / (1 - beta2^t)                  (yanlılığı düzeltilmiş 2. moment)
    theta_t <- theta_{t-1} - alpha * m_hat_t / (sqrt(v_hat_t) + eps)
end while
return theta_t
```

Önerilen varsayılan değerler $\alpha = 0.001$, $\beta_1 = 0.9$, $\beta_2 = 0.999$, $\epsilon = 10^{-8}$'dir. $g_t^2$ eleman eleman karedir; bütün işlemler vektörlerde eleman eleman yapılır.

Optimize edilen parametreler $\theta$ ile gösterilir. Son satır güncellemedir; $\alpha$ adım büyüklüğüdür. $\beta_1$ ve $\beta_2$ hiperparametrelerdir. Hiperparametre, algoritmanın kendisinin bulamadığı, kullanıcının vermesi gereken değerdir.

### 14.2 Birinci ve ikinci moment

$g_t$, $t$. adımdaki stokastik amaç fonksiyonunun gradyanıdır. "Stokastik" burada batch size'a göre tek örnek ya da $k$ örnek alınması demektir.

$m_t$ gradyanları biriktirir: $m_{t-1}$'in bir kısmına yeni gradyanın bir kısmı eklenir (hoca $\beta_1$'i sezgi için $0.5$ gibi düşünmeyi önerdi). $\beta_1$ ne kadar büyükse önceki gradyanların etkisi o kadar büyük, ne kadar küçükse şimdiki gradyanın etkisi o kadar büyük olur.

$v_t$ ise gradyanların karelerini biriktirir; bu, AdaGrad'daki $G_t$'nin köşegenine karşılık gelir. $\beta_2$ için de aynı yorum geçerlidir: büyükse geçmiş kareler, küçükse son kareler önemlidir.

$m_t$ o ana kadarki gradyanların ortalamasıdır; istatistikte buna **birinci moment** denir. Karelerin ortalaması **ikinci moment**tir.

### 14.3 Yanlılık düzeltmesi

$m_0 = 0$ ve $v_0 = 0$ ile başlandığı için ilk adımlarda bu ortalamalar olduklarından küçük görünür. $\hat m_t = m_t/(1 - \beta_1^t)$ ve $\hat v_t = v_t/(1 - \beta_2^t)$ bunu düzeltir. $\beta_1$ 0 ile 1 arasında olduğundan $t$ büyüdükçe (örneğin 100. iterasyonda) $\beta_1^t$ sıfıra yaklaşır ve payda 1'e yaklaşır. Yani başta $m_t$ 1'den küçük bir sayıya bölünür, ilerleyen adımlarda 1'e çok yakın bir sayıya bölünür; düzeltmenin etkisi kaybolur. Amaç başlangıçtaki yanlışlığı gidermektir.

> **Ders sonrası not:** Python ile kontrol edildi: sabit $g_t = 2$ ve $\beta_1 = 0.9$ için ilk beş adımda $m_t$ = 0.2, 0.38, 0.542, 0.688, 0.819 iken $\hat m_t$ her adımda tam 2'dir. Düzeltme, sıfır başlangıcın yarattığı yanlılığı tamamen kaldırıyor.

### 14.4 Güncellemenin büyüklüğü

Son adımda $\hat m_t$, $\sqrt{\hat v_t}$'ye bölünür. $v_t$ karelerin ortalaması olduğundan karekökü yine gradyan ölçeğinde bir büyüklüktür. Gradyanların ortalaması gradyanların ölçeğindeki bu büyüklüğe bölününce birbirine oldukça yakın iki şey bölünmüş olur. Bu yüzden güncelleme büyük gradyan için büyük, küçük gradyan için küçük olmaz; farklı büyüklükteki gradyanlar için benzer büyüklükte güncellemeler yapılır ve adımı esas olarak $\alpha$ belirler.

### 14.5 Hareketli ortalama deneyi

Slayttaki deneyde (ekrandan, 02:10:00; kod `moving_avg.m`) AdaGrad karşılıkları da yazılıdır: $v_t = v_{t-1} + g_t^2$, $m_t = g_t$. Gradyan, ortalaması 2 ve standart sapması 1 olan bir rastgele değişken olarak modellenmiştir: $g_t \sim N(2, 1)$. Grafiklerde mavi çizgi gradyanları, diğer çizgiler $m$ ve düzeltilmiş $\hat m$'yi (grafikte "tm") gösterir.

- $\beta_1 = 0.9$ iken $m$ zamanla gradyanların ortalamasına yaklaşır; düzeltilmiş $\hat m$ ise bu ortalamaya çok daha hızlı, daha az adımda yaklaşır.
- $\beta_1 = 0.7$ alınınca ortalamaya daha da hızlı yaklaşılır, ama ortalama daha gürültülü olur, çünkü son değerlerin etkisi artar. $0.9$'da son değerlerin etkisi azalır, öncekilere daha çok bakılır. Bunlar hareketli ortalama almanın standart çeşitleridir.

Adam'ın temel amacı büyük ölçekli optimizasyondur. Büyük ölçekte yalnız SGD kullanılabiliyordu ve onun kötü yanı gürültülü gradyanlardı: bir o yana bir bu yana sapmalar üretiyorlardı. Bu deneyde $m_t$ gradyanların kendisine göre çok daha düzgündür; değerlerin ortalamasını almak doğal olarak daha düzgün bir sonuç verir. Adam, SGD'nin gürültülü gradyanlarının gereksiz sağa sola gitme etkisini önlemek için tasarlanmıştır ve bunu yalnız o anki gradyana göre değil, geçmiş gradyanları da kullanarak yapar. AdaGrad yalnız kareleri kullanırken Adam iki şeyi birden kullanır: ham ortalamalar (birinci moment) ve karelerin ortalamaları (ikinci moment).

## 15. Adam Güncellemesinin Özellikleri

### 15.1 Gradyan büyüklüğüne dayanıklılık

Slaytta "Robust to magnitude of gradients, noisy gradients (stochastic opt.), sparse gradients" yazılıdır (ekrandan, 02:15:00). Soldaki deneyde gradyan değerleri 9'dan 3'e kademeli ve gürültülü olarak düşürülmüştür; grafikte gradyan, $m$, $v$, düzeltilmiş $m$ ve $v$ ile Adam güncellemesi ("adam-up") çizilmiştir. Adam güncellemesi $\hat m_t/\sqrt{\hat v_t}$, gradyan 9 iken de 3 iken de benzer bir değerde kalır; hoca bunu "bire çok yakın" diye yorumladı. Güncelleme gradyanın büyüklüğünden (magnitude) bağımsızdır. Yönlerdeki küçük sapmalar dışında büyük sapmalar görülmez.

> **Ders sonrası not:** Python ile kontrol edildi: $g_t \sim N(2,1)$ için $\hat m_t/\sqrt{\hat v_t}$ oranı yaklaşık 0.87 çıkıyor; teorik karşılığı $E[g]/\sqrt{E[g^2]} = 2/\sqrt{5} \approx 0.89$'dur. Oran gürültü arttıkça 1'in altına iner, ama gradyanın ölçeğiyle doğrusal olarak değişmez.

### 15.2 Seyrek gradyanlar

Adam'ın bir diğer önemli özelliği seyrek (sparse) gradyanlarla da çalışmasıdır. Seyrek gradyan, gradyan vektörlerinin bir kısmının sıfır olması demektir. Sıfır gradyan o yönde güncelleme yapılmaması demektir. Adam ise seyrek durumda da güncellemeye devam eder.

**Soru:** Bunun avantaj sağlayabileceği yer neresi? **Cevap:** Bir önceki slayttaki düz bölge (plato). Düz bölgede türevler sıfırlandığı anda standart gradyan inişi takılır. Adam, momentum kullanımına benzer biçimde önceki gradyanları da güncellemede kullandığı için, örneğin dik bir yerden düz bir vadiye gelindiğinde önceki dik inişten kalan gradyanlarla o yönde ilerlemeyi sürdürür.

Sağdaki deneyde gradyanların yarısı sıfırlanmıştır ("Half of gradients are 0"). Adam güncellemesi bu durumda öncekine göre biraz sapmış olsa da oldukça yüksek bir değerde kalır; güncelleme devam eder. Gradyanların sıfır olması örneğin NLP'de sık görülür: metin vektörleştirildiğinde terim-doküman matrisinin büyük kısmı sıfırdır ve türevlerin de büyük kısmı sıfır olur. Böyle durumlarda gradyan inişi fazla güncelleme yapamazken Adam ilerlemeye devam eder.

### 15.3 İki boyutta Adam

Slayttaki deneyde (ekrandan, 02:20:00; kod `myADAM.m`) aynı fonksiyon üzerinde SGD zikzaklar çizerek sapar, Adam ise doğrudan optimuma gider. Slaytta "It directly goes to the optimal point. Does it know the optimum point? No. Its update values are equal for all dimensions" yazılıdır. Adam optimumu bilmez; her boyutta temelde eşit büyüklükte güncelleme yaptığı için, başlangıç noktası yaklaşık $(-2.5, 2.5)$ civarında olduğunda doğrudan optimuma gidiyormuş gibi görünür. Farklı bir noktadan başlatıldığında da düzgün bir yol izler, ama bu yol düz bir çizgi değildir.

**Soru:** Adam'ın kötü yanı var mı? **Cevap:** Var. Bir boyutta güncelleme gerekmese bile (o boyuttaki gradyan sıfır olsa bile) güncellemeye devam eder. Yine de yakınsar; bu çok büyük bir sorun değildir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $Y = X\beta$ modelinde $X$ kare matris değilken $\beta$ nasıl kestirilir?

> **Çözüm:** İki taraf $X^T$ ile çarpılır: $X^TY = X^TX\beta$. $X^TX$ kare olduğundan iki taraf $(X^TX)^{-1}$ ile çarpılır ve $\beta = (X^TX)^{-1}(X^TY)$ bulunur.

**Soru 2** (derste sözlü, 00:20:56): Türevin sıfır olduğu nokta konveks bir fonksiyonda nedir, konveks olmayan bir fonksiyonda ne olabilir?

> **Çözüm:** Konveks fonksiyonda global minimumdur. Konveks olmayan fonksiyonda yerel minimum, yerel maksimum ya da eyer noktası olabilir.

**Soru 3** (derste sözlü, 00:33:08): $Y = \sin(b_1X)$ örneğinde MSE tam sıfır olabilir mi?

> **Çözüm:** Bu gürültülü veriyle olamaz; hiçbir $b_1$ bütün noktalardan geçmez. Ancak bütün noktalar tam $y = \sin(-0.5x)$ eğrisi üzerinde olsaydı sıfır olabilirdi.

**Soru 4** (ekrandan, 00:35:00 ve derste sözlü, 00:37:53): Newton-Raphson $b = -1$'den başlayınca $b = -0.5$'e varıyor, $b = -2$'den başlayınca varamıyor. Adım büyüklüğü olmadığına göre sebep nedir?

> **Çözüm:** $b_1$-hata eğrisi konveks değildir. $-2$'den başlanınca yakındaki yerel minimuma inilir. Konveks olmayan fonksiyonda başlangıç noktası varılacak minimumu belirler.

**Soru 5** (ekrandan, 00:45:00): $Y = \exp(-(X - B_1)^2/(2B_2^2))$ modelinin $N = 200$ için $B_1$-$B_2$ hata yüzeyi neden simetriktir? İki minimumun değeri aynı mıdır?

> **Çözüm:** $B_2$ modelde yalnız $B_2^2$ olarak geçer; $B_2$ ile $-B_2$ aynı çıktıyı verir. Yüzey $B_2 = 0$'a göre simetriktir ve iki minimumun hata değeri aynıdır.

**Soru 6** (ekrandan, 00:50:00): Aynı model $N = 10$ örnekle çizilince optimizasyon neden daha zordur?

> **Çözüm:** Yüzeyde geniş düz bölgeler oluşur; türev orada sıfır olduğu için optimizasyon durur. Az örnekte veriye uyan çok sayıda parametre ikilisi vardır; sonuçların varyansı yüksektir.

**Soru 7** (ekrandan, 01:35:00): Basit modelde $f_i(x) = \frac{1}{2}(a_ix - b_i)^2$ ve $R = [\min b_i/a_i, \max b_i/a_i]$. R'nin dışında ve içinde tekil gradyan $\nabla f_i$ ile tam gradyan $\nabla f$ arasındaki ilişki nedir?

> **Çözüm:** R'nin dışında bütün $\nabla f_i$'ler $\nabla f$ ile aynı işaretlidir; tek bir örnekle de iyileşme garanti edilir. R'nin içinde işaretler karışır; SGD optimum çevresinde salınır.

**Soru 8** (derste sözlü, 01:34:19): Tam gradyan yerine tek bir örneğin gradyanını kullanmak için her adımda kaç hesap gerekir?

> **Çözüm:** Tam gradyan için $n\cdot d$, tek örnek için $d$ hesap (bu tek boyutlu örnekte 1).

**Soru 9** (ekrandan, 01:40:00): SGD sabit öğrenme oranıyla neden yakınsamaz ve ne yapılabilir?

> **Çözüm:** R bölgesine girildikten sonra tekil gradyanlar farklı yönlere iter, kararlı bir yörünge yoktur. Son $x_t$ yerine son $k$ değerin ya da bütün değerlerin ortalaması alınabilir (slaytta son $x_t = [-0.2692, 0.3260]$, ortalama $[-0.1192, 0.0452]$, optimum $(0,0)$) ya da öğrenme oranı adım adım sıfıra doğru azaltılabilir.

**Soru 10** (derste sözlü, 01:42:57): 10 milyon parametreli bir yapay sinir ağında önceki değerlerin ortalamasını almak neden sorunlu olabilir?

> **Çözüm (derste verilmedi):** Hoca soruyu düşünülmek üzere açık bıraktı. Ek bilgi bloğundaki gibi, büyük olasılıkla ek bellek ihtiyacı ve konveks olmayan kayıp yüzeyinde farklı bölgelerdeki ağırlıkların ortalamasının iyi bir nokta olmaması sayılabilir.

**Soru 11** (derste sözlü, 01:56:58): AdaGrad'daki $G_t = \sum_j \nabla f(x_j)\nabla f(x_j)^T$ matrisinin köşegeninde ne vardır? Köşegen sürüm kaç hesap gerektirir?

> **Çözüm:** Her boyuttaki gradyan karelerinin toplamı. Köşegen sürüm $d$ hesap, tam matris sürümü $d\cdot d$ hesap gerektirir.

**Soru 12** (derste sözlü, 02:12:31): Adam güncellemesi $\hat m_t/\sqrt{\hat v_t}$ neden gradyanın büyüklüğünden etkilenmez?

> **Çözüm:** Pay gradyanların ortalaması, payda gradyan karelerinin ortalamasının kareköküdür; ikisi aynı ölçektedir ve oran 1 civarında kalır. Adım büyüklüğünü esas olarak $\alpha$ belirler.

**Soru 13** (derste sözlü, 02:13:50): Adam'ın seyrek gradyanlarda güncellemeye devam etmesi nerede avantaj sağlar?

> **Çözüm:** Türevin sıfır olduğu düz bölgelerde (plato). Önceki gradyanların etkisi sürdüğü için takılıp kalmadan ilerlenir. NLP'deki terim-doküman matrisleri gibi çoğu sıfır olan verilerde de avantajlıdır.

**Soru 14** (ekrandan, 02:30:00; ödev metni): Gradient Descent, Adam ve Coordinate Descent algoritmalarını kendi tanımladığınız 4 kayıp fonksiyonu (2 konveks, 2 konveks olmayan; en az 10 boyutlu) üzerinde karşılaştırın. 5 farklı başlangıç noktası ($w_0$) belirleyip bütün algoritmaları buralardan başlatın. Hiperparametrelerin etkisini araştırıp optimize edin; sonra $3\cdot 4\cdot 5 = 60$ optimizasyon sürecini çalıştırıp sonuç tablosu oluşturun. Yörüngeleri t-SNE ve PCA ile 2 boyutta görselleştirin (4 kayıp için 4 t-SNE, 4 PCA grafiği). Süre-kayıp ve epoch-kayıp grafiklerini çizin ve bulguları beklentilerle karşılaştırarak yorumlayın. Ek olarak üç algoritmanın stokastik sürümleri de karşılaştırılabilir.

> **Derste verilen ipuçları:** Gradyan inişinde adım büyüklüğü, Adam'da adım büyüklüğü optimize edilebilir; Adam'ın $\beta_1$, $\beta_2$ değerleri varsayılan bırakılabilir. Stokastik sürüm için ya eğitim kümesinden tek ya da $k$ örnek seçilir, ya da derste yapıldığı gibi tam gradyana rastgele gürültü eklenir; süresi tam gradyanın örnek sayısına göre bir kesri olarak düşünülebilir. Hazır kütüphaneler kullanılabilir; MATLAB yerine Python da kullanılabilir.
>
> **Soru (derste soruldu):** Tek boyutlu konveks bir fonksiyonu 10 boyuta genişletmek için $a_1x_1^2 + a_2x_2^2 + \dots$ yazılsa konveks olur mu? **Cevap:** Olur, en basit konveks fonksiyonlardan biridir. Ama değişkenler arasında korelasyon olmadığı için gradyan inişi doğrudan sonuca gider ve algoritmalar arasında fark görülmez. Biraz eğik, bükük, değişkenleri arasında korelasyon olan konveks fonksiyonlar seçilmelidir. Önemli olan algoritmaların farkının görülebileceği fonksiyonlar seçmektir.

## Dersin Toparlaması

Bu derste regresyon konusu yinelemeli kestirimle tamamlandı. Doğrusal modellerde tek adımlık analitik çözüm $\beta = (X^TX)^{-1}X^TY$ büyük veride pahalılaşır; doğrusal olmayan modellerde ise artıklar ve Jacobian matrisi üzerinden gradyan inişi ($\beta - \epsilon J^Tr$) ya da $J^TJ$ yaklaşıklığına dayanan Newton-Raphson ($\beta - \text{pinv}(J)\,r$) kullanılır. $\sin$ ve Gauss örnekleri, konveks olmayan hata yüzeylerinde başlangıç noktasının belirleyici olduğunu, simetrinin modelin yapısından gelebileceğini ve az örnekle hata yüzeyinin düz bölgelerle bozulup varyansın arttığını gösterdi.

İkinci bölümde makine öğrenmesi kayıplarının sonlu toplam yapısından yola çıkılarak SGD'ye geçildi. Tekil gradyanlar R bölgesinin dışında doğru yönü gösterir, içinde çelişir; bu yüzden SGD ucuz ama gürültülüdür. Ortalama alma, azalan öğrenme oranı, gradyan kırpma ve mini-batch bu gürültüyü yönetmenin yollarıdır. AdaGrad, gradyan dış çarpımlarının toplamıyla Hessian'ı taklit eden bir quasi-Newton yöntemidir; Adam ise birinci ve ikinci momentleri yanlılık düzeltmesiyle birleştirerek gradyan büyüklüğüne dayanıklı, gürültüde düzgün ve seyrek gradyanlarda ilerleyebilen bir güncelleme verir. Sonraki derste karar ağaçlarına ve kollektif öğrenmenin klasik algoritmalarına geçilecek, dönem sonuna doğru derin öğrenmedeki ensemble yöntemlerine dönülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
