# Ders 3 Çalışma Özeti

## Genel Konular

- Doğrusal yaklaşım (linear approximation) ve Taylor serileri
  - Bir fonksiyonu bütünüyle doğrusal kabul etmek ile yalnız bir noktada doğrusal kabul etmek farklı varsayımlardır. Bir noktada doğrusal kabul etmek daha zayıf bir varsayımdır ve fonksiyonu o noktanın yakınında az bozar.
  - $x$ noktasındaki teğet doğru $L$ ile: $f(x+\Delta x) \approx L(x+\Delta x) = f(x) + \Delta x\, f'(x)$, çünkü $f'(x) = dy/dx$. $\Delta x \to 0$ iken $f(x+\Delta x) - L(x+\Delta x) \to 0$ olur (ekrandan, 00:05:00).
  - Bu birinci dereceden (first order) Taylor yaklaşımıdır. İkinci dereceden terim eklenince ikinci dereceden yaklaşım, $n$. dereceye kadar gidince $n$. dereceden Taylor açılımı elde edilir. Sonsuz kez türevlenebilen fonksiyonlarda $n \to \infty$ iken açılım fonksiyonun kendisine eşit olur.
  - Sıfırıncı dereceden yaklaşım fonksiyonu o noktadaki değerine eşit sabit bir doğru kabul eder.
  - Slaytlarda $e^x$ için 0'dan 5. dereceye, $\sin x$ için 15. dereceye kadar açılımlar gösterildi: derece arttıkça yaklaşım noktadan uzakta da gerçeğe yakın kalıyor, ama yeterince uzakta yine ayrışıyor.
  - Her noktadaki doğrusal yaklaşım farklıdır, çünkü her noktada türev farklıdır.
- Newton-Raphson ile kök bulma (birinci dereceden)
  - $f(x)=0$ problemini çözmek için rastgele bir noktadan başlanır; her adımda fonksiyon o noktada doğrusal kabul edilir ve teğetin x eksenini kestiği yere gidilir.
  - $f'(x_n) = f(x_n)/(x_n - x_{n+1})$ eşitliğinden $x_{n+1} = x_n - f(x_n)/f'(x_n)$, $n = 0,1,2,\dots$ elde edilir (ekrandan, 00:20:00).
  - Durma ölçütü: kök 6 ondalık basamağa kadar isteniyorsa $x_{n+1}$ ile $x_n$ 6. basamağa kadar aynı olunca durulur.
  - $\sqrt{2}$ irrasyonel olduğundan bilgisayarda tam değeriyle tutulamaz; $x^2-2=0$ ancak yaklaşık çözülebilir.
  - Döngü (cycle) sorunu: $f(x) = x^3 - 2x + 2$ için 0'dan başlanınca 1'e, 1'den başlanınca 0'a gidilir ve yöntem sonsuza kadar iki nokta arasında gidip gelir.
- Newton-Raphson ile en küçük değer bulma (ikinci dereceden)
  - En küçük değer için $f'(x)=0$ noktası aranır. Kök bulma formülünde $f$ yerine $f'$ konur: $x_{n+1} = x_n - f'(x_n)/f''(x_n)$.
  - Gradyan inişiyle amacı aynıdır, ama adım büyüklüğü (step size) parametresi yoktur. Slayt örneğinde gradyan inişi 200 iterasyonda, Newton-Raphson 20 iterasyonda vardı.
- Türevlerin sayısal hesabı
  - İleri fark $f'(x) \approx (f(x+\delta) - f(x))/\delta$, geri fark $f'(x) \approx (f(x) - f(x-\delta))/\delta$, merkezi fark $f'(x) \approx (f(x+\delta/2) - f(x-\delta/2))/\delta$. $\delta$ seçimi önemlidir (ekrandan, 00:30:00).
  - Türev alınamayan noktalarda ($1/x$ için $x=0$, $x^{1/3}$ için $x=0$) iterasyon sürdürülemez; sayısal türev büyük hatayla da olsa ilerlemeyi sağlar.
- Çok değişkenli fonksiyonlar: gradyan, kuadratik form, Hessian
  - Çok değişkenli fonksiyonun türevi gradyan vektörüdür: $\nabla f = [\partial f/\partial x_1, \dots, \partial f/\partial x_n]^T$. Boyut, değişken sayısıdır; üs değildir.
  - Gradyan fonksiyona yaklaşan (hiper)düzlemi tanımlar: $\Delta z = \frac{\partial f}{\partial x}\Delta x + \frac{\partial f}{\partial y}\Delta y$ (ekrandan, 00:35:00).
  - Bütün kuadratik fonksiyonlar $f(x) = \frac{1}{2}x^T Q x + b^T x + c$ biçiminde yazılır. $Q$ pozitif tanımlıysa (bütün özdeğerler pozitif) kase, negatif tanımlıysa ters kase, belirsizse (indefinite) eyer (saddle) biçimi oluşur (ekrandan, 00:40:00).
  - İkinci türev $n \times n$'lik simetrik Hessian matrisidir; kuadratik formdaki $Q$ Hessian'ın kendisidir.
  - Çok boyutlu Newton-Raphson: $x_{yeni} = x_{eski} - (\nabla^2 f)^{-1}\nabla f$. Matrislerde bölme olmadığı için ters matrisle çarpılır.
- Gradyan inişi ile Newton-Raphson karşılaştırması
  - Kuadratik fonksiyonda Newton-Raphson tek adımda en küçük noktaya varır. Slayttaki örnekte gradyan inişi (adım 0.1) 118. iterasyonda, Newton-Raphson 4. iterasyonda yakınsadı, $x_0 = [-0.5;\ 0.7]$ (ekrandan, 00:50:00).
  - Bedeli: her adımda Hessian hesaplanmalı ve tersi alınmalı. 100 bin boyutta $10^5 \times 10^5$'lik matris hem bellek hem işlem açısından uygulanamaz. Bu yüzden yüksek boyutta ikinci dereceden yöntemler kullanılmaz; hızlı birinci dereceden yöntemlere (Adagrad, Adam vb.) geçilir.
  - Yakınsama "epsilon yakınlık" ile tanımlanır: gerçek bilinmediği için ardışık iki adım arasındaki fark çok küçülünce durulur.
  - Newton-Raphson türevin sıfır olduğu her noktaya gidebilir, tepe noktasına da. $f'$ ile $f''$'nin işaretleri farklıysa yanlış yöne gider. Bunu yakalamak için her adımda $f$ değerinin azaldığı kontrol edilmelidir. Gradyan inişi (küçük adımla) zaten iniş yapan bir algoritmadır.
- Veri modelleme ve regresyon
  - Regresyon bir sayı tahmin etmektir. Model bir varsayımdır; veri bu modele uyar diye kabul edilir ve eğitim verisinden modelin parametreleri bulunur, test verisiyle başarısı ölçülür.
  - Doğrusal birinci dereceden model $Y = \beta_0 + \beta_1 X + \varepsilon$, ikinci dereceden $Y = \beta_0 + \beta_1 X + \beta_2 X^2 + \varepsilon$, $n$. dereceden $Y = \beta_0 + \beta_1 X + \dots + \beta_n X^n + \varepsilon$. "Doğrusal" sözcüğü $\beta_i$ parametrelerinde doğrusallığı, "derece" $X$'in en yüksek kuvvetini anlatır (ekrandan, 01:20:00).
  - $\varepsilon$ rastgele hatadır (ölçüm, rastlantı); modelin parametresi değildir.
  - Bütün popülasyona hiçbir zaman ulaşılamaz; örneklemden $\hat\beta_0, \hat\beta_1$ tahmin edilir (ekrandan, 01:25:00).
- En küçük kareler (least squares)
  - Gerçek ile tahmin arasındaki farkların kareleri toplamı (SSE) $\sum_{i=1}^n (Y_i - \hat Y_i)^2 = \sum \hat\varepsilon_i^2$ en küçük yapılır; MSE $= \frac{1}{n}\sum (Y_i - \hat Y_i)^2$ (ekrandan, 01:30:00).
  - Kare alınır, çünkü artı ve eksi hatalar birbirini götürmemelidir. Mutlak değer sıfırda türevlenemediği için tercih edilmez.
  - En küçük kareler modeli vermez; modeli dışarıdan biz veririz, yöntem yalnız parametreleri bulur.
  - $y = \beta$ (sıfırıncı dereceden) modelinde kayıp fonksiyonunun türevi sıfıra eşitlenince $\beta = \frac{1}{n}\sum y_i$, yani çıktıların ortalaması bulunur.
- Matris biçimi ve kapalı çözüm
  - $d$ boyutlu $X$ için $Y_{n\times 1} = X_{n\times(d+1)}\beta_{(d+1)\times 1} + \varepsilon_{n\times 1}$. $X$'in ilk sütunu birlerden oluşur ve $\beta_0$'a karşılık gelir (ekrandan, 01:35:00).
  - İkinci dereceden modelde $X$ matrisine $x$'lerin kareleri ayrı sütun olarak eklenir.
  - $X$ kare olmadığı için tersi alınamaz; $X^T X$ her zaman karedir. Böylece $\beta = (X^T X)^{-1}(X^T Y)$ bulunur (ekrandan, 01:40:00).
  - Bu analitik (tek adımlı) bir çözümdür. Çok büyük problemlerde (milyonlarca boyut, örnek) ters matris pratikte alınamaz, bu yüzden doğrusal modeller bile iteratif optimizasyonla çözülür.
- Örneklem büyüklüğü, gürültü, aşırı ve yetersiz öğrenme
  - `lin_reg1.m` ile gerçek $\beta = [5;\ 0.8]$ modelinden gürültülü veri üretildi. $N=6$'da tahmin $[5.1713;\ 0.57024]$, $N=600$'de $[5.0025;\ 0.79611]$ çıktı; örnek arttıkça tahmin gerçeğe yaklaşır (ekrandan, 01:45:00). Gürültü büyüdükçe hata artar.
  - Gerçek model birinci dereceden iken birinci ve ikinci dereceden modeller oturtuldu (`Lin_reg4.m`): eğitim MSE'si birinci derecede 21.0596, ikinci derecede 18.4368 (ekrandan, 01:50:00). Gerçekten karmaşık model eğitim verisinde daha düşük hata verir.
  - Model karmaşıklığı arttıkça eğitim hatası düşer; bu eğitim verisine yapışmaktır (overfitting). Gerçekten basit model yetersiz öğrenmedir (underfitting).
  - X-hata grafiği: gerçek model üçüncü dereceden iken birinci, ikinci, üçüncü dereceden modellerin hataları çizildi (MSE 128.9716, 96.0218, 3.4312). Hatalarda örüntü varsa modellenmemiş bir şey vardır; derece yeterliyse hatalar $X$ boyunca aynı varyansta, rastgele görünür (ekrandan, 01:55:00).
  - Eğitim MSE'si model seçimi için güvenilir değildir. Test hatası bir noktaya kadar düşer, sonra artar; o nokta verinin gerçek derecesine işaret edebilir.
- Parametrelere göre doğrusallık
  - $\cos$, $\sin$, $\exp$ gibi terimler $x$'e uygulanıyorsa model $\beta$'ya göre doğrusaldır ve aynı formülle çözülür; $Y = b_1\sin(b_2 X)$, $Y = \exp(b_1 X)$, $Y = (b_1 X)/(b_2 + X)$ gibi modeller doğrusal değildir (ekrandan, 02:00:00).
  - Ölçüt: $f$'nin $\beta$'ya göre türevi hâlâ $\beta$'nın fonksiyonuysa parametre doğrusal olmayan biçimde yer alır. $\beta\sin x$'in türevi $\sin x$ (doğrusal), $\sin(\beta x)$'in türevi $x\cos(\beta x)$ (doğrusal değil).
  - Logaritma gibi dönüşümlerle bazı doğrusal olmayan modeller doğrusala çevrilebilir; çevrilemiyorsa doğrusal olmayan regresyon gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kodları indirip çalıştırmak ve üzerinde değişiklik yapmak
  - Lisansüstü ders yalnız dinleyerek takip edilemez; verilen MATLAB kodlarını (`.m` dosyaları düz metin olduğu için herhangi bir metin düzenleyicide de açılabilir) çalıştırmak konuları kavramayı sağlar.
- Regresyon ve optimizasyon, ensemble yöntemleri anlamanın temeli
  - Derste temel öğrenici olarak kullanılacak yapay sinir ağlarının hata/parametre yüzeylerindeki optimizasyon üzerinden ensemble yöntemlerinin nasıl çalıştığı anlatılacak; bu yüzden bu konuların iyi kavranması gerekiyor.
- Newton-Raphson hızlı ama pahalı
  - Adım sayısı açısından gradyan inişinden çok daha hızlıdır, kuadratik fonksiyonda tek adımda varır; ama Hessian'ı hesaplamak ve tersini almak yüksek boyutta uygulanamaz.
- Newton-Raphson'da $f$ değerinin azaldığı kontrol edilmeli
  - Türevin sıfır olduğu bir tepe noktasına gidebilir; adım sonrası $f$ artıyorsa adım kabul edilmemelidir.
- Model bir varsayımdır
  - En küçük kareler modeli vermez; modeli kuran sizsiniz. Doğru ya da yanlış olabilir.
- Eğitim hatası yanıltıcıdır
  - Daha karmaşık model eğitimde her zaman daha düşük hata verir; bu gerçek modelden daha iyi olduğu anlamına gelmez, aşırı öğrenmedir.
- Analitik çözüm ile iteratif çözüm
  - $\beta = (X^TX)^{-1}X^TY$ tek adımlı çözümdür, ama büyük ölçekli problemlerde pratikte kullanılamaz; iteratif optimizasyon hem büyük doğrusal modellerde hem doğrusal olmayan modellerde kullanılır.

## Kısa Tekrar Notları

- Birinci dereceden Taylor: $f(x+\Delta x) \approx f(x) + \Delta x f'(x)$; derece arttıkça yaklaşım uzağa kadar iyileşir.
- Newton-Raphson kök: $x_{n+1} = x_n - f(x_n)/f'(x_n)$; en küçük değer: $x_{n+1} = x_n - f'(x_n)/f''(x_n)$.
- $x^3 - 2x + 2$ için 0 ve 1 arasında döngü oluşur.
- Sayısal türev: ileri, geri, merkezi fark; merkezi fark en makulü.
- Gradyan $n\times 1$, Hessian $n\times n$ simetrik; kuadratik formda $Q$ = Hessian.
- $Q$ pozitif tanımlı → kase, negatif tanımlı → ters kase, belirsiz → eyer.
- Çok boyutlu Newton: $x \leftarrow x - H^{-1}\nabla f$; kuadratikte tek adım; yüksek boyutta uygulanamaz.
- Yakınsama: ardışık adımlar arası fark $\epsilon$'dan küçük.
- Doğrusal model = parametrelerde doğrusal; derece = $X$'in en yüksek kuvveti.
- SSE ve MSE; kare, artı/eksi hataların birbirini götürmemesi ve türevlenebilirlik için.
- $y=\beta$ modelinde en iyi $\beta$ ortalamadır.
- $\beta = (X^TX)^{-1}X^TY$; $X$'in ilk sütunu birler.
- Örnek arttıkça tahmin gerçeğe yaklaşır; gürültü arttıkça hata büyür.
- Karmaşık model eğitimde düşük hata → aşırı öğrenme; basit model → yetersiz öğrenme.
- X-hata grafiğinde örüntü varsa model eksik.
- Türev $\beta$ içeriyorsa model $\beta$'ya göre doğrusal değildir.

## Detaylı Açıklamalar

- Doğrusal yaklaşımın hesaplama kazancı
  - Bir fonksiyonun değerini hesaplamak pahalıysa, bilinen bir $x$ noktasındaki değer ve türevle $x+\Delta x$ noktasındaki değer tahmin edilebilir. Slayttaki çizimde $A$ noktası $(x, f(x))$, $B$ gerçek değer $f(x+\Delta x)$, $C$ ise teğet üzerindeki $L(x+\Delta x)$'tir. $C$ ile $B$ arasındaki fark yapılan hatadır ve $\Delta x$ küçüldükçe sıfıra gider. Hata azaltılmak istenirse yüksek dereceli Taylor terimleri eklenir, ama çok yüksek dereceli türevler hesaplamayı ağırlaştırdığı için amacına ters düşer.
- Newton-Raphson'un türetilmesi
  - $x_n$ noktasında teğetin eğimi $f'(x_n)$, teğetin yüksekliği $f(x_n)$ ve teğetin x eksenini kestiği yer $x_{n+1}$'dir. Eğim = yükseklik / yatay uzaklık olduğundan $f'(x_n) = f(x_n)/(x_n - x_{n+1})$ yazılır ve düzenlenince güncelleme formülü çıkar. Yalnız $n$. adımdaki bilgiyle $(n+1)$. adım bulunur. Fonksiyonun birden çok kökü varsa başlangıca en yakın köke gidilir.
- İkinci dereceden Newton-Raphson ve gradyan inişi
  - Optimizasyonda aranan, türevin sıfır olduğu noktadır. Elimizde sanki $f$ değil $f'$ varmış gibi düşünülüp kök bulma formülü $f'$'ye uygulanır. Böylece ikinci türev işe girer. Gradyan inişinin adım büyüklüğü seçimi gerekirken burada böyle bir parametre yoktur.
  - Çok boyutta $f'$ gradyan vektörü ($n\times 1$), $f''$ Hessian matrisi ($n\times n$) olur. Boyutlar: $(n\times n)^{-1}$ çarpı $(n\times 1)$ yine $n\times 1$ verir; bu da $x$'ten çıkarılır.
  - Ters matris maliyeti boyutla hızla artar (slayttaki `inversion_time.m` grafiğinde 500'lük matrise kadar süre giderek dikleşiyor). Bu nedenle çok yüksek boyutta ikinci dereceden yöntemler uygulanamaz.
  - Ders sonrası not: Hoca matris tersi almanın maliyetinin boyutla "eksponansiyel" arttığını söyledi; büyük olasılıkla kastedilen hızlı (doğrusal olmayan) artıştır. Standart yöntemlerle (Gauss eliminasyonu) maliyet $O(n^3)$, yani polinomsaldır.
- Newton-Raphson'un tepe noktasına gitmesi
  - $\sin$ fonksiyonu örneğinde (mavi $f$, kırmızı $f'$, yeşil $f''$) bir başlangıç noktasından en küçük değere, başka bir başlangıçtan tepe noktasına gidiliyor. Fark, $f'$ ile $f''$'nin işaretlerinin aynı ya da farklı olmasından geliyor. Tepeye giderken ardışık noktalarda $f$ değeri artıyor; bu kontrol edilerek adım reddedilebilir.
  - Gradyan inişinde adım büyüklüğü uygun seçilirse dışbükey fonksiyonda $f$ her adımda azalır; adım çok büyükse minimumun öbür tarafına atlayıp ıraksayabilir. <!-- BELİRSİZ: Hoca adım büyüklüğü için bir üst sınırdan söz etti ("birden büyük olmaması", "9.99'dan küçük" olarak yazıya geçmiş); büyük olasılıkla geçen haftaki belirli bir fonksiyon için verilen sınırdır, kare yok. -->
- En küçük karelerin matris çözümü
  - $Y = X\beta$ denkleminde $\beta$'yı yalnız bırakmak için iki taraf $X$'e bölünemez. $X$ kare değilse tersi de yoktur. İki taraf soldan $X^T$ ile çarpılır: $X^TY = X^TX\beta$. $X^TX$, $(d+1)\times(d+1)$'lik kare matristir; iki taraf $(X^TX)^{-1}$ ile çarpılınca $\beta = (X^TX)^{-1}X^TY$ bulunur.
  - Aynı formül $\beta$'ya göre doğrusal her modelde kullanılır: çok değişkenli ($x_1, x_2$), çok değişkenli ikinci dereceden ($x_1, x_2, x_1^2, x_2^2$; beş parametre) ya da $\cos$, $\exp$ içeren modeller. Yalnız $X$ matrisinin sütunları değişir.
- Aşırı öğrenme ve X-hata grafiği
  - Gerçek model ikinci dereceden iken ikinci dereceden model çok düşük hata verir, birinci dereceden model büyük hata verir (yetersiz öğrenme). Gerçek birinci dereceden iken ikinci dereceden model eğitimde daha düşük hata verir, ama eğitim aralığının dışına çıkıldığında doğrusallıktan uzaklaşır ve hatası büyür.
  - Yetersiz öğrenmeyi X-hata grafiğinden anlamak kolaydır: hatalar $x$'e göre düzenli bir örüntü çizer. Aşırı öğrenmede böyle bir örüntü görülmez; bunu anlamak için test verisi gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
