# Ders 4 Çalışma Özeti

## Genel Konular

- Doğrusal regresyonun tekrarı ve sınırları
  - Model, bulunacak katsayılara göre türev alındığında türevde hâlâ katsayı kalıyorsa doğrusal değildir. Örneğin $\beta_1 + \cos(\beta_2 x)$ modelinde $\beta_2$'ye göre türevde $\beta_2$ kalır, bu yüzden model doğrusal değildir. <!-- BELİRSİZ: Slayttaki doğrusal örnek modelin tam yazımı karelerde görülmedi; altyazıda bir terimin "sinüs x" içerdiği söyleniyor. -->
  - Doğrusal durumda $Y = X\beta$ yazılır. Matrislerde bölme olmadığı ve $X$ her zaman kare olmadığı için iki taraf önce $X^T$ ile çarpılır ($X^TX$ her zaman karedir). Sonra $(X^TX)^{-1}$ ile çarpılır ve $\beta = (X^TX)^{-1}(X^TY)$ bulunur (ekrandan, 00:15:00).
  - Sorun: örnek sayısı çok büyükse bu ters alma işlemi hem bellek hem süre açısından zorlaşır. Ters alma maliyeti boyutla hızla artar.
- Doğrusal olmayan regresyon: iki yol
  - Dönüşümlerle modeli doğrusala çevirmek. Her zaman mümkün değildir.
  - Yinelemeli kestirim (iterative estimation): rastgele bir başlangıçtan başlayıp tahmini adım adım iyileştirmek. Model doğrusal olsa bile veri çok büyükse bu yol gerekebilir.
- Yinelemeli kestirimin kurulumu (ekrandan, 00:25:00)
  - Veri $\{x_i, y_i\}$, $i=1..n$; model $y = f(\beta, x)$; $x$ bir $n\times d$, $y$ bir $n\times 1$ matristir.
  - Artıklar (residuals): $r_i = y_i - f(\beta, x_i)$, $r$ bir $n\times 1$ vektördür.
  - Hata: $E(\beta) = \sum_i r_i^2$. Amaç $\min_\beta E(\beta)$, yani $dE(\beta)/d\beta = 0$.
  - Türevin sıfır olduğu yer konveks fonksiyonda global minimumdur. Konveks değilse yerel minimum, yerel maksimum ya da eyer noktası (saddle point) olabilir.
- Jacobian ile gradyan inişi ve Newton-Raphson yaklaşımı (ekrandan, 00:30:00)
  - $dr/d\beta$ bir $n\times d$ matristir ve Jacobian matrisi ($J$) diye adlandırılır.
  - Gradyan inişi: $\beta_{k+1} = \beta_k - \epsilon\, dE(\beta)/d\beta$, Jacobian ile $\beta_{k+1} = \beta_k - \epsilon\, J^T r$ (2 çarpanı $\epsilon$'a katılır). $J^T r$ bir $d\times 1$ vektördür.
  - Newton-Raphson: $\beta_{k+1} = \beta_k - \dfrac{dE/d\beta}{d^2E/d\beta^2}$.
  - İkinci türev yerine $d^2E/d\beta^2 \approx J^TJ$ kullanılır. Bu eşitlik değil, yaklaşıklıktır: iki birinci türevin çarpımı ikinci türev değildir.
  - Böylece $\beta_{k+1} = \beta_k - (J^TJ)^{-1}(J^Tr)$ elde edilir. $\text{pinv}(J) = (J^TJ)^{-1}J^T$ sözde ters (pseudo-inverse) olduğundan $\beta_{k+1} = \beta_k - \text{pinv}(J)\, r$ yazılır.
- Örnek 1: $Y = \sin(b_1 X)$ (ekrandan, 00:35:00)
  - Gerçek $b = -0.5$, veride gürültü var. Başlangıç $b=-1$ iken Newton-Raphson yaklaşık 7 adımda veriye oturur; MSE sıfıra yaklaşır ama gürültü yüzünden tam sıfır olamaz.
  - Gradyan inişinde adım büyüklüğü büyütülünce MSE sıfıra yakın bir yere bile inmiyor, son eğri salınıyor.
  - Başlangıç $b=-2$ iken Newton-Raphson da başarısız olur. Sebebi adım büyüklüğü değil, $b_1$-hata eğrisinin konveks olmamasıdır: başlangıç noktası varılacak yerel minimumu belirler.
- Örnek 2: Gauss eğrisi $Y = \exp(-(X-B_1)^2/(2B_2^2))$ (ekrandan, 00:40:00)
  - Gerçek $B = [-0.2;\ 1.5]$, başlangıç $B = [-2;\ -0.2]$. Gradyan inişi $\epsilon = 0.1$ ile 3-4 adımda oturur; daha küçük adımla 10 iterasyonda henüz varmaz ama doğru yönde ilerler. Newton-Raphson birkaç iterasyonda oturur.
  - $N=200$ için $B_1$-$B_2$ hata yüzeyi konveks değildir, iki eşit derinlikte minimum vardır ve $B_2=0$'a göre simetriktir. Sebep: $B_2$ modelde kare olarak geçer, $+B_2$ ve $-B_2$ aynı çıktıyı verir (ekrandan, 00:45:00).
  - Hangi minimuma düşüldüğü önemli değildir; sorunlu yerler iki çanak arasındaki bölgelerdir.
- Örnek sayısının etkisi (ekrandan, 00:50:00)
  - Aynı model $N=10$ örnekle çizilince hata yüzeyinde geniş düz bölgeler çıkar. Düz bölgede türev sıfırdır, optimizasyon orada durur.
  - Az örnekte veriye uyan, benzer başarıda çok sayıda parametre ikilisi vardır; sonuçların varyansı yüksektir. Çok örnek daha fazla kısıt koyar, uygun parametre sayısı azalır, varyans düşer.
  - $\beta_1 x + \beta_2 x^3$ gibi doğrusal bir modelde 10 örnekle bile hata yüzeyi konvekstir, başlangıç fark etmez.
- Sonlu toplam (finite sum) biçimindeki amaç fonksiyonları (ekrandan, 01:20:00)
  - Makine öğrenmesinde amaç fonksiyonu tek tek eğitim örneklerinin kayıplarının toplamıdır: $f(x) = \frac{1}{n}\sum_{i=1}^n f_i(x)$. Burada $x$ eğitilecek model parametresidir.
  - En küçük kareler: $\min_x \frac{1}{n}\sum_i (a_i^Tx - b_i)^2$.
  - Lasso: $\min_x \frac{1}{n}\sum_i (a_i^Tx - b_i)^2 + \lambda\sum_{j=1}^d |x_j|$. İkinci terim parametrelerin 1-normudur; parametrelerin küçük kalmasını ister. Minimize edilen ifadenin tamamıdır.
  - Yapay sinir ağı: $\min_x \frac{1}{n}\sum_i \text{loss}(ANN(x, a_i), b_i)$.
- Gradyan inişi ve büyük ölçekli problemler (ekrandan, 01:25:00)
  - $x_{t+1} = x_t - \eta_t\nabla f(x_t) = x_t - \eta_t\sum_{i=1}^n \nabla f_i(x_t)$.
  - $f(x_1,x_2) = x_1^2 + 2x_2^2$, öğrenme oranı $0.1$ ile 40. adımda yakınsar.
  - Her GD iterasyonu $n\cdot d$ hesap ister. Çok sayıda parametre ($d$) ve çok sayıda örnek ($n$) olunca her adım pahalılaşır.
- Basit model ve R bölgesi (ekrandan, 01:30:00 ve 01:35:00)
  - $a_i, b_i, x$ skaler, $n=8$; gerçek model $b = 1\cdot a$, başlangıç $b = -10a$.
  - $f_i(x) = \frac{1}{2}(a_ix - b_i)^2$, $f(x) = \frac{1}{2n}\sum_i (a_ix - b_i)^2$. Her $f_i$'nin minimumu 0'dır, ama noktalar tek doğru üzerinde olmadığı için ortalamanın minimumu 0 değildir.
  - R bölgesi $[\min_i b_i/a_i,\ \max_i b_i/a_i]$ aralığıdır ve optimum $x^* \in R$.
  - R'nin dışında bütün $\nabla f_i$ ile $\nabla f$ aynı işaretlidir; tek bir örneğin gradyanı da doğru yöne götürür. R'nin içinde işaretler karışır, "kaos" olur.
- Stokastik gradyan inişi (SGD) (ekrandan, 01:40:00)
  - $x_{t+1} = x_t - \eta_t\nabla f_i(x_t)$: tam gradyan yerine tek bir örneğin gradyanı kullanılır. $E[\nabla f_i] = \nabla f$.
  - $f = x_1^2 + 2x_2^2$, $\eta = 0.1$ ile SGD yakınsamaz: R dışında GD'ye çok benzer, R içinde (optimuma yakın) salınır.
  - Son $x_t$ yerine $\text{mean}(x_t)$ ya da son $k$ değerin ortalaması kullanmak mantıklıdır. Slayttaki örnekte son $x_t = [-0.2692,\ 0.3260]$, ortalama $[-0.1192,\ 0.0452]$; optimum $(0,0)$'a ortalama daha yakındır.
  - Diğer yol öğrenme oranını adım adım azaltmaktır (ör. her adımda $0.99$ ile çarpmak). $\eta_t \to 0$ olunca ardışık adımlar arasındaki fark da sıfıra gider.
  - Her GD iterasyonu $d\cdot n$, her SGD iterasyonu $d$ hesap ister. SGD daha çok adım gerektirir ama her adım çok ucuzdur. Bugün büyük ölçekli problemlerde en çok kullanılan yöntem SGD ve türevleridir.
- SGD'nin kararlı hale getirilmesi (ekrandan, 01:50:00)
  - Gradyan kırpma (gradient clipping): $\|\nabla f_i(x_t)\| \ge c$ ise $\nabla f_i(x_t) = c\,\nabla f_i(x_t)/\|\nabla f_i(x_t)\|$. Aşırı sapmaları engeller.
  - Mini-batch: tek örnek yerine $k$ örnek; $x_{t+1} = x_t - \frac{\eta_t}{|K_t|}\sum_{j\in K_t}\nabla f_j(x_t)$. Gradyanın varyansını azaltır, iterasyon başına $k\cdot d$ hesap ister. Batch boyutu bellek yüzünden çok büyütülemez.
- AdaGrad: bir quasi-Newton yöntemi (ekrandan, 01:55:00)
  - Quasi-Newton yöntemler Hessian'ı hesaplamadan onu taklit eden, daha az ve daha düzgün adımla ilerleyen yöntemlerdir. Önceki bütün gradyanları kullanırlar.
  - $G_t = \sum_{j=1}^t \nabla f(x_j)\nabla f(x_j)^T$: önceki gradyanların dış çarpımlarının toplamı, $d\times d$ matris, Hessian'ı taklit eder.
  - Tam matris sürümü: $x_{t+1} = x_t - \eta_t G_t^{-1/2}\nabla f(x_t)$, $d\cdot d$ hesap.
  - Köşegen sürüm: $x_{t+1} = x_t - \eta_t\,\text{diag}(G_t)^{-1/2}\nabla f(x_t)$, $d$ hesap. $G_t$'nin köşegeni her boyuttaki gradyan karelerinin toplamıdır.
  - Stokastik sürümde (ekrandan, 02:00:00) GD ($Lr=0.1$) zikzak çizer; köşegen ve tam $G_t$ ($Lr=1$) çok daha düzgün ilerler, sonunda yine optimum çevresinde salınır.
- Adam (ekrandan, 02:05:00 ve 02:10:00)
  - AdaGrad ve RMSProp'tan esinlenmiştir; yapay sinir ağlarında en çok kullanılan algoritmadır.
  - $m_t = \beta_1 m_{t-1} + (1-\beta_1)g_t$ (birinci moment, gradyanların hareketli ortalaması), $v_t = \beta_2 v_{t-1} + (1-\beta_2)g_t^2$ (ikinci moment, gradyan karelerinin ortalaması).
  - Düzeltmeler: $\hat m_t = m_t/(1-\beta_1^t)$, $\hat v_t = v_t/(1-\beta_2^t)$. $m_0 = v_0 = 0$ olduğu için ilk adımlardaki küçük kalma etkisini giderir; $t$ büyüdükçe etkisi kaybolur.
  - Güncelleme: $\theta_t = \theta_{t-1} - \alpha\,\hat m_t/(\sqrt{\hat v_t} + \epsilon)$. Önerilen varsayılanlar $\alpha = 0.001$, $\beta_1 = 0.9$, $\beta_2 = 0.999$, $\epsilon = 10^{-8}$.
  - $\beta_1$ büyükse geçmiş gradyanlar, küçükse son gradyan daha etkilidir. $g_t \sim N(2,1)$ deneyinde $\hat m_t$ ortalamaya $m_t$'den çok daha hızlı yaklaşır; $\beta_1 = 0.7$ daha hızlı ama daha gürültülüdür.
- Adam güncellemesinin özellikleri (ekrandan, 02:15:00 ve 02:20:00)
  - Gradyan büyüklüğüne karşı dayanıklıdır: gradyan 9'dan 3'e düşerken güncelleme oranı yaklaşık sabit kalır.
  - Gürültülü gradyanlarda $m_t$ gradyanlardan çok daha düzgündür.
  - Seyrek (sparse) gradyanlarda (gradyanların yarısı 0) güncelleme devam eder. Düz bir vadiye gelindiğinde önceki gradyanların etkisiyle ilerlemeyi sürdürür. NLP'deki terim-doküman matrisleri gibi çoğu sıfır olan verilerde avantajlıdır.
  - İki boyutta Adam sanki optimumu biliyormuş gibi doğrudan gider; gerçekte her boyutta eşit büyüklükte güncelleme yaptığı içindir. Kötü yanı: güncelleme gerekmeyen boyutta da güncelleme yapmaya devam eder, ama yine yakınsar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğrusal olmayan problemlerde başlangıç noktası sonucu belirler
  - $\sin(b_1 X)$ örneğinde $-1$'den başlayınca doğru sonuca, $-2$'den başlayınca yerel minimuma varılır. Newton-Raphson'da adım büyüklüğü yoktur; sorun hata eğrisinin konveks olmamasıdır.
- $J^TJ$ Hessian'a eşit değildir, onun yerine kullanılan bir yaklaşıklıktır
  - İkinci türev hesabından kurtarır; Newton kadar olmasa da gradyan inişinden hızlı yakınsar.
- Örnek sayısı azaldıkça hata yüzeyi bozulur
  - Düz bölgeler optimizasyonu durdurur; az örnek yüksek varyans demektir.
- SGD'nin neden yakınsamadığı
  - R bölgesi içinde tekil gradyanların yönleri çelişir. Çözüm: öğrenme oranını azaltmak ya da son değerlerin ortalamasını almak.
- SGD'nin bugünkü önemi
  - Adım başına çok az hesap gerektirdiği için büyük ölçekli problemlerde en çok kullanılan yöntemdir.
- Adam'ın üç özelliği
  - Gradyan büyüklüğünden bağımsız güncelleme, gürültülü gradyanlarda düzgün hareket, seyrek gradyanlarda ilerlemeyi sürdürme.

## Kısa Tekrar Notları

- Doğrusal regresyon: $\beta = (X^TX)^{-1}X^TY$; büyük veride ters alma pahalı.
- Doğrusal olmayan model: dönüşüm ya da yinelemeli kestirim.
- $r_i = y_i - f(\beta,x_i)$, $E(\beta) = \sum r_i^2$, Jacobian $J = dr/d\beta$ ($n\times d$).
- GD: $\beta_{k+1} = \beta_k - \epsilon J^Tr$.
- Newton yaklaşımı: $d^2E/d\beta^2 \approx J^TJ$, $\beta_{k+1} = \beta_k - \text{pinv}(J)\,r$, $\text{pinv}(J) = (J^TJ)^{-1}J^T$.
- Türev sıfır: minimum, maksimum ya da eyer noktası.
- Konveks olmayan hata yüzeyinde varılan nokta başlangıca bağlı.
- Gauss modelinde $B_2$ kare olarak geçtiği için hata yüzeyi $B_2$'ye göre simetrik.
- Az örnek: düz bölgeler, çok sayıda uygun model, yüksek varyans.
- Sonlu toplam: $f(x) = \frac{1}{n}\sum f_i(x)$ (en küçük kareler, Lasso, YSA).
- GD iterasyonu $n\cdot d$, SGD iterasyonu $d$, mini-batch $k\cdot d$ hesap.
- R bölgesi $[\min b_i/a_i, \max b_i/a_i]$: dışında tekil gradyan doğru yönü verir, içinde kaos.
- SGD: son değer yerine ortalama ya da azalan öğrenme oranı.
- Gradyan kırpma: norm $c$'yi aşarsa $c$'ye ölçekle.
- AdaGrad: $G_t$ = gradyan dış çarpımlarının toplamı; köşegen sürüm $d$ hesap.
- Adam: $m_t$, $v_t$, yanlılık düzeltmesi, $\theta_t = \theta_{t-1} - \alpha\hat m_t/(\sqrt{\hat v_t}+\epsilon)$.
- Adam: büyüklüğe dayanıklı, gürültüde düzgün, seyrek gradyanda ilerler.

## Detaylı Açıklamalar

- Neden $X^T$ ile çarpılır?
  - $X\beta = Y$ denkleminde $\beta$'yı yalnız bırakmak için iki taraf $X^{-1}$ ile çarpılmak istenir, ama ters yalnız kare matrislerde vardır. $X$ genelde $n\times d$'dir. İki taraf $X^T$ ile çarpılınca $X^TX$ bir $d\times d$ kare matris olur; onun tersiyle çarpınca sol taraf birim matris olur ve $\beta$ kalır. Bu tek adımlık analitik çözümdür. Örnek sayısı çok büyükse bellek ve süre sorunu çıkar; o zaman model doğrusal olsa bile yinelemeli çözüm tercih edilebilir.
  - Ders sonrası not: Hoca matris tersinin maliyetinin boyutla "eksponansiyel/üstel" arttığını söyledi. Standart yöntemlerle bu maliyet büyük olasılıkla $O(d^3)$'tür, yani polinomsal ama hızlı artan bir maliyettir.
- Jacobian ile gradyan
  - $E = \sum r_i^2$ olduğundan $dE/d\beta = 2\,J^Tr$ olur. $J$'nin her satırı bir örneğin artığının parametrelere göre türevidir. Gradyan inişinde 2 çarpanı adım büyüklüğü $\epsilon$'un içine katılır. Boyut kontrolü: $J^T$ $d\times n$, $r$ $n\times 1$, sonuç $d\times 1$.
- Newton-Raphson yaklaşımının kazancı
  - Newton'un iyi yanı az adımdır: fonksiyon kuadratikse tek adımda minimuma varır, çünkü her noktaya doğru değil parabol oturtur. Kötü yanları kararsızlık ve her adımda $d\times d$ Hessian'ın tersini alma maliyetidir. Bir öğrencinin kendi denemesinde gradyan inişi hızlı sonuç verirken ikinci dereceden yöntemin çok uzun sürdüğü örnek verildi. Hata artıyorsa o güncellemeyi kabul etmemek gibi ön ve son kontrollerle Newton yine kullanılabilir. $J^TJ$ yaklaşıklığı ikinci türev hesaplamayı ortadan kaldırır.
  - Ders sonrası not: Slaytta "Newton Raphson" diye geçen $\beta_{k+1} = \beta_k - \text{pinv}(J)\,r$ güncellemesi literatürde büyük olasılıkla Gauss-Newton yöntemi olarak bilinir.
  - Python ile kontrol edildi: gürültülü $y = \sin(-0.5x)$ verisinde (200 nokta, $x \in [-8,8]$) bu güncelleme $b=-1$'den başlayınca $-0.499$'a, $b=-2$'den başlayınca $-2.34$ civarındaki yerel minimuma gidiyor. Derste gösterilen davranışla uyumlu.
- MSE neden sıfır olmuyor?
  - Veriye gürültü eklendiği için hiçbir $b_1$ değeri bütün noktalardan geçemez. Model bu veriyi ezberleyemez. MSE ancak bütün noktalar tam eğri üzerinde olsaydı sıfır olabilirdi.
- R bölgesinin sezgisi
  - Tek boyutlu basit modelde her $f_i$ kendi minimumuna $b_i/a_i$'de ulaşır. Optimum bu minimumların arasında bir yerdedir. Bölgenin solunda bütün $f_i$'lerin türevi aynı işaretli olduğundan hangi örnek seçilirse seçilsin aynı yöne gidilir. Bu, tam gradyan için $n\cdot d$ hesap yerine tek örnekle $d$ hesap yapmanın gerekçesidir. Bölgenin içinde ise bazı örnekler sola, bazıları sağa iter; SGD optimumun çevresinde zıplar.
- Ortalama almak mı, öğrenme oranını azaltmak mı?
  - Sabit öğrenme oranıyla SGD optimum çevresinde rastgele hareket eder; bu hareketin merkezi optimum olduğu için ortalama mantıklıdır. Pratikte daha çok öğrenme oranı her adımda küçültülür. Hoca, milyonlarca parametreli bir ağda ortalama almanın neden sorunlu olabileceğini düşünmeyi öğrencilere bıraktı.
- Adam güncellemesinin büyüklüğü
  - $\hat m_t$ gradyanların ortalaması, $\sqrt{\hat v_t}$ gradyan karelerinin ortalamasının kareköküdür. İkisi aynı ölçektedir; oranları 1 civarında olur ve gradyanın büyüklüğünden bağımsızdır. Böylece adım büyüklüğünü esas olarak $\alpha$ belirler.
  - Ders sonrası not (python ile kontrol edildi): $g_t \sim N(2,1)$ için oran yaklaşık $E[g]/\sqrt{E[g^2]} = 2/\sqrt5 \approx 0.89$ civarında çıkıyor. Gürültü arttıkça oran 1'in altına iner; "1'e yakın" ifadesi gürültüsü düşük gradyanlar için geçerlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
