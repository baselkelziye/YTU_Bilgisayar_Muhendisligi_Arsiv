# Ders 2 Çalışma Özeti

## Genel Konular

- Matematiksel optimizasyon probleminin tanımı
  - Genel biçim: $\min f_0(x)$, kısıtlar $f_i(x) \le b_i,\ i=1,\dots,m$ (ekrandan, 00:05:00).
  - $x=(x_1,\dots,x_n)$ optimizasyon değişkeni, $f_0:\mathbb{R}^n\to\mathbb{R}$ amaç (objektif) fonksiyonu, $f_i$ kısıt fonksiyonlarıdır.
  - Optimal çözüm $x^*$: kısıtları sağlayan bütün vektörler arasında $f_0$'ı en küçük yapan noktadır.
  - Kısıt yoksa bütün uzay arama alanıdır ve problem kısıtsız (unconstrained) optimizasyon adını alır.
  - Maksimizasyon problemleri işaret değiştirilerek minimizasyona çevrilebilir.
- Kısıtlı optimizasyon örneği: çit problemi
  - $L$ metre çitle çevrilebilecek en büyük dikdörtgen alan sorulur. Bir kenar $x$ ise diğeri $L/2-x$ olur, alan $f(x)=x(L/2-x)$ (ekrandan, 00:05:00 karesindeki slayt listesi).
  - Türev sıfıra eşitlenerek $x=L/4$ bulunur; yani en büyük alan karede elde edilir.
  - Kısıt amaç fonksiyonunun içine gömülerek problem kısıtsız hale getirildi (Lagrange yaklaşımının temel fikri).
- Optimizasyon teknikleri (ekrandan, 00:10:00)
  - Türev kullanan teknikler: gradient descent, Newton-Raphson, LM, BFGS.
  - Türev kullanmayan (kullanamayan) teknikler: hill climbing, genetik algoritmalar, simulated annealing. Ayrık uzaylarda türev tanımlanamadığı için bunlar kullanılır.
- Lineer, afin ve konveks fonksiyonlar
  - Lineer: $f(x_1+x_2)=f(x_1)+f(x_2)$ ve $f(r x_1)=r f(x_1)$. Örneğin $2x$ hem lineer hem afindir.
  - Afin: lineer fonksiyonun ötelenmiş hali. $2x+3$ ve sabit $f(x)=3$ orijinden geçmediği için lineer değil, afindir.
  - Konveks: $\lambda f(x_1)+\beta f(x_2)\ge f(\lambda x_1+\beta x_2)$, $\lambda+\beta=1$, $\lambda,\beta\ge0$ (ekrandan, 00:15:00). Grafikte iki noktayı birleştiren doğru, fonksiyonun üstünde ya da üzerinde kalır.
  - $t x_1+(1-t)x_2$ ifadesi $t=1$ için $x_1$, $t=0$ için $x_2$, $t=0.5$ için orta noktayı verir.
  - Afin fonksiyonlar (doğrular, düzlemler) konvekstir. $\sin x$ ne konveks ne konkavdır; bazı aralıklarda konveks, bazılarında konkavdır.
- İteratif optimizasyonun genel algoritması
  - Bir başlangıç tahmini seçilir; iyileşme anlamlı olduğu ve en büyük iterasyon sayısı aşılmadığı sürece sonuç iyileştirilir.
  - Anlamlı iyileşme: ardışık iki $x$ arasındaki fark bir eşikten (precision) büyük olmalıdır. İterasyon sınırı sonsuz döngüyü önler.
  - Her adımda iki karar gerekir: yön (türevin işaretinin tersi) ve adım büyüklüğü.
- Gradient descent
  - Yalnız türevin işareti: $x_{new}=x_{old}-eps\cdot \mathrm{sign}(df)$ (ekrandan, 00:35:00). Sabit adımla minimuma en fazla adım büyüklüğü kadar yaklaşılır, sonra zikzak yapılır.
  - Türevin büyüklüğü de kullanılırsa: $x_{new}=x_{old}-eps\cdot df$ (ekrandan, 00:40:00). Minimuma yaklaştıkça türev küçüldüğü için adımlar da küçülür.
  - Adım büyüklüğü (learning rate) fonksiyona göre seçilmelidir: çok küçükse yavaş, büyükse zikzak, fazla büyükse ıraksama olur.
  - Başlangıç noktası konveks fonksiyonda sonucu değiştirmez; konveks olmayan $f(x)=x^4-3x^3+2$ fonksiyonunda değiştirir (ekrandan, 00:50:00).
- Steepest descent
  - Adım büyüklüğü dışarıdan verilmez; seçilen yön boyunca fonksiyonun minimumu bulunur ve oraya gidilir.
  - Ardışık arama yönleri birbirine diktir (ekrandan, 01:45:00). Her iterasyon daha pahalıdır.
- Lineer yaklaşım ve Taylor serisi
  - $f(x+\Delta x)\approx f(x)+\Delta x\, f'(x)$; $\Delta x$ küçüldükçe hata azalır.
  - Örnek: $(1.0002)^{50}\approx 1+0.0002\cdot 50\cdot 1=1.01$ (ekrandan, 01:55:00).
  - İkinci derece: $f(x+\Delta x)\approx f(x)+\Delta x f'(x)+\tfrac12 f''(x)\Delta x^2$; $N$. derece: $f(x+\Delta x)\approx\sum_{i=0}^{N} f^{(i)}(x)\Delta x^i/i!$ (ekrandan, 02:05:00).
  - Derece arttıkça yaklaşım, yaklaşım noktasının çevresinde gerçek fonksiyona daha iyi oturur; uzaklaştıkça ayrılır.
- Newton-Raphson
  - Birinci derece (kök bulma, $f(x)=0$): $x_{n+1}=x_n-f(x_n)/f'(x_n)$. Teğetin $x$ eksenini kestiği noktaya gidilir.
  - İkinci derece (minimum bulma, $f'(x)=0$): $x_{n+1}=x_n-f'(x_n)/f''(x_n)$. Adım büyüklüğü parametresi yoktur.
  - Çok boyutta $f''$ yerine Hessian matrisi gelir, bölme yerine Hessian'ın tersiyle çarpılır. Daha az iterasyon, ama her iterasyon pahalıdır.
- Çok boyutlu fonksiyonlar ve kuadratik fonksiyonlar
  - Gradyan: her boyuta göre kısmi türevlerden oluşan vektör.
  - Kuadratik fonksiyon: $f(x)=\tfrac12 x^T q x+b^T x+c$ (ekrandan, 02:45:00). $q$ pozitif tanımlı ise kase (konveks), negatif tanımlı ise ters kase, belirsiz (indefinite) ise eyer (saddle) şeklindedir (ekrandan, 02:40:00).
  - Kuadratik fonksiyonun Hessian'ı $q$'dur; Newton-Raphson kuadratik fonksiyonda minimuma tek adımda ulaşır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Konveks fonksiyonların önemi
  - Konveks fonksiyonda nereden başlanırsa başlansın aynı noktaya varılır ve bulunan minimum global minimumdur. Boyut sayısı çok büyük olsa da bu güvence geçerlidir.
  - Konveks olmayan fonksiyonda bulunan minimumun global olduğundan emin olunamaz; yüksek boyutlu uzayda bütün noktaları denemek mümkün değildir.
- Adım büyüklüğü seçimi
  - "Büyük" ya da "küçük" adım kavramı amaç fonksiyonuna bağlıdır; aynı değer bir fonksiyonda büyük, diğerinde küçük olabilir. Bu, gradient descent'in bir iş yüküdür.
- Türevin sıfır olduğu noktalar
  - Türev sıfır olunca güncelleme durur; minimum olmayan düzlük ve eyer noktalarında algoritma takılır.
  - Yapay sinir ağlarının hata-parametre uzaylarında çok sayıda eyer noktası olduğu söylenir; bu uzaylar genelde konveks değildir, yine de konveks optimizasyon teknikleri işe yarar.
- İterasyon sayısı tek ölçüt değildir
  - Newton-Raphson az iterasyonla yakınsar, ama Hessian'ı hesaplamak ve tersini almak boyut arttıkça çok pahalılaşır. Karşılaştırmada her adımın süresi de hesaba katılmalıdır.
- Kodları incelemek
  - Kavramların en iyi kodları inceleyip üzerinde düşünerek oturacağı söylendi; slaytlardaki her kavramın MATLAB kodu vardır.

## Kısa Tekrar Notları

- Optimizasyon: $f_0$'ı kısıtlar altında en küçük yapan $x^*$'ı bulmak.
- Çit problemi: alan $x(L/2-x)$, en iyi $x=L/4$ (kare).
- Lineer $\Rightarrow$ toplamsallık + çarpımsallık; afin = ötelenmiş lineer.
- Konveks: $\lambda f(x_1)+(1-\lambda)f(x_2)\ge f(\lambda x_1+(1-\lambda)x_2)$.
- Gradient descent (işaret): $x \leftarrow x-eps\cdot\mathrm{sign}(f'(x))$; sabit adım, minimum çevresinde zikzak.
- Gradient descent (büyüklük): $x\leftarrow x-eps\cdot f'(x)$; adımlar kendiliğinden küçülür.
- $f(x)=x^2$ için $eps=1$ olunca yakınsama olmaz; $eps$ seçimi kritiktir.
- $f(x)=x^4-3x^3+2$: $f'(x)=4x^3-9x^2$, ekstremumlar $x=0$ ve $x=9/4$; başlangıç noktası sonucu etkiler.
- Steepest descent: yön boyunca tam minimum, ardışık yönler dik.
- Taylor: derece arttıkça yaklaşım noktası çevresinde hata azalır.
- Newton-Raphson 1. derece: $x_{n+1}=x_n-f(x_n)/f'(x_n)$ (kök).
- Newton-Raphson 2. derece: $x_{n+1}=x_n-f'(x_n)/f''(x_n)$ (minimum); çok boyutta $x_{n+1}=x_n-H^{-1}\nabla f$.
- Kuadratik form: $q$ pozitif tanımlı $\Rightarrow$ konveks kase; belirsiz $\Rightarrow$ eyer.
- Newton-Raphson kuadratik fonksiyonda tek adımda minimuma gider, ama eyer noktasına da yakınsayabilir.

## Detaylı Açıklamalar

- **Optimizasyon problemi ve çit örneği.** Bir optimizasyon probleminde amaç fonksiyonunun ($f_0$) en küçük değerini veren $x$ aranır. $x$ tek boyutlu olmak zorunda değildir, $n$ boyutlu bir vektördür. "Subject to" kısmındaki kısıtlar $x$'in bulunabileceği bölgeyi sınırlar. Çit örneğinde dikdörtgenin çevresi $L$ olduğundan iki komşu kenarın toplamı $L/2$'dir. Bir kenara $x$ denirse alan $x(L/2-x)$ olur. Bu fonksiyonun türevi $L/2-2x$ sıfıra eşitlenince $x=L/4$ bulunur, diğer kenar da $L/4$'tür; yani en büyük alan kare ile elde edilir. Burada kısıt, alan fonksiyonunun içine yerleştirilerek problem tek değişkenli kısıtsız bir probleme dönüştürüldü.

- **Konvekslik.** Konveks fonksiyonda $x_1$ ile $x_2$ arasındaki herhangi bir nokta $t x_1+(1-t)x_2$ biçiminde yazılır. Bu noktada fonksiyonun değeri $f(t x_1+(1-t)x_2)$, iki uç noktayı birleştiren doğrunun değeri $t f(x_1)+(1-t)f(x_2)$'dir. Bütün $x_1,x_2$ çiftleri için doğru fonksiyonun üstünde ya da üzerinde kalıyorsa fonksiyon konvekstir. Doğru ve düzlem gibi afin fonksiyonlarda iki noktayı birleştiren doğru fonksiyonun kendi üzerindedir, bu yüzden eşitlik sağlanır ve bunlar konvekstir. $\sin x$ fonksiyonunda bazı nokta çiftleri için doğru fonksiyonun üstünde, bazıları için altında kalır; bu yüzden fonksiyon bütün tanım kümesinde ne konveks ne de konkavdır. Bir fonksiyonun konveks olduğunu göstermek için eşitsizliğin her $x_1,x_2$ çifti için geçerli olduğunu kanıtlamak gerekir; bir ve iki değişkenli fonksiyonlar çizilerek incelenebilir, daha yüksek boyutlarda bu zorlaşır.
  - Ders sonrası not: Hoca $\sin x$ için $[0,\pi]$ aralığını konveks, $[-2\pi,-\pi]$ aralığını konkav diye örnekledi. $(\sin x)''=-\sin x$ olduğundan doğrusu: $\sin x$, $\sin x\ge0$ olan $[0,\pi]$ ve $[-2\pi,-\pi]$ aralıklarında konkav, $\sin x\le0$ olan $[-\pi,0]$ ve $[\pi,2\pi]$ aralıklarında konvekstir.

- **Gradient descent, yalnız işaretle.** Gösterilen `gradient_desc_1.m` kodunda $f(x)=x^2$, $f'(x)=2x$, başlangıç $x=-4.9$, $eps=0.05$, precision $=0.00001$, en fazla 200 iterasyon kullanıldı (ekrandan, 00:35:00). Döngü `while abs(x_new - x_old) > precision && max_iter>=i` koşuluyla döner ve her adımda `x_new = x_old - eps * sign(df)` uygulanır. Ardışık iki nokta arasındaki fark her zaman $0.05$ olduğundan precision koşulu hiçbir zaman sağlanmaz; döngü yalnız iterasyon sınırıyla biter. Yaklaşık 100 adımda (5 birimlik mesafe / 0.05) sıfır çevresine varılır, sonra iki komşu değer arasında zikzak yapılır. $eps=0.1$ olunca yaklaşık 50. adımda varılır ama zikzak sürer; $eps=0.01$ olunca 200 iterasyon yetmez (yaklaşık 500 gerekir).

- **Gradient descent, büyüklükle.** Güncelleme `x_new = x_old - eps * df` olunca türevin büyüklüğü adımı belirler: optimumdan uzakta türev büyük, adım büyük; optimuma yakın türev küçük, adım küçüktür. `gradient_desc_2.m` ile slaytlarda şu sonuçlar gösterildi: $eps=0.05$ için 120 iterasyon, $eps=0.1$ için 60 iterasyon, $eps=0.7$ için 16 iterasyon (zikzak var ama genliği küçülüyor), $eps=0.99$ için 200 iterasyon (büyük ama sönen zikzak), $eps=0.01$ için 200 iterasyon yetmiyor. $eps=1$ olunca 200 iterasyona ulaşıldı ve yöntem yakınsamadı (ekrandan, 00:45:00).
  - Ders sonrası not: Görünen kod ayrıntılarıyla (başlangıç $-4.9$, precision $10^{-5}$) python ile yapılan benzetimde iterasyon sayıları $eps=0.05$ için 104, $eps=0.1$ için 53, $eps=0.7$ için 16 çıktı. Slayttaki 120 ve 60 değerleri büyük olasılıkla kodun ekranda görünmeyen bir ayrıntısından (başlangıç noktası ya da durma eşiği) kaynaklanıyor. $f(x)=x^2$ için güncelleme $x\leftarrow(1-2\,eps)x$ olduğundan $0<eps<1$ iken yakınsama olur, $eps=1$ iken $x$ yalnız işaret değiştirir, $eps>1$ iken ıraksar. Slayttaki $10^{16}$ ölçeğine çıkan grafik büyük olasılıkla $eps$'nin 1'den biraz büyük olduğu ya da kodun farklı olduğu bir çalıştırmaya aittir.

- **Başlangıç noktasının etkisi.** $f(x)=x^4-3x^3+2$, $f'(x)=4x^3-9x^2$ fonksiyonunun türevi $x=0$ ve $x=9/4$'te sıfırdır (ekrandan, 00:50:00). $x=-1.9$ civarından küçük adımla başlatılan gradient descent, türevin sıfır olduğu $x=0$ düzlüğüne yaklaşıp orada takıldı (ekrandan, 01:30:00); $x=3.5$'ten başlatılınca $9/4$'teki minimuma gitti. Adım büyüklüğü $0.05$ yapılınca soldan başlayan algoritma düzlüğü atlayıp minimuma ulaşabildi; hoca bunun bir şans işi olduğunu, büyük adımın başka fonksiyonlarda daha derin bir minimumu kaçırmaya da yol açabileceğini söyledi. Python kontrolü: $-1.9$'dan $eps=0.01$ ile 200 iterasyonda $x\approx-0.049$'da kalınıyor; $eps=0.05$ ile 9 iterasyonda $2.25$'e varılıyor; $3.5$'ten $eps=0.01$ ile 42, $eps=0.05$ ile 14 iterasyonda $2.25$'e varılıyor.

- **Taylor yaklaşımı.** Bir fonksiyonun belli bir noktada lineer kabul edilmesi birinci derece Taylor yaklaşımıdır. $f(x)=x^{50}$ için $x=1$, $\Delta x=0.0002$ alınırsa $f(1.0002)\approx 1+0.0002\cdot50\cdot1^{49}=1.01$ bulunur (ekrandan, 01:55:00); python ile gerçek değer $1.0100491\ldots$'dir. `approx_taylor.m` ile $e^x$ fonksiyonuna $x=0.25$ noktasında 0'dan 5'e kadar derecelerle yaklaşıldı; bütün yaklaşımlar $(0.25, f(0.25))$ noktasından geçer, derece arttıkça bu noktanın çevresinde gerçek eğriye daha iyi oturur, uzaklaştıkça ayrılır (ekrandan, 02:00:00). Fonksiyonun kendisi $k$. dereceden bir polinom ise $k$. derece Taylor yaklaşımı fonksiyonun kendisini verir.

- **Newton-Raphson ve gradient descent karşılaştırması.** Birinci derece Newton-Raphson, teğet doğrusunun $x$ eksenini kestiği yere giderek $f(x)=0$ kökünü bulur. Aynı fikir $f'(x)=0$ noktasını bulmaya uygulanınca ikinci derece Newton-Raphson elde edilir. $x=-1.9$'dan başlatılan gradient descent ($eps=0.01$) 200 iterasyonda yakınsamazken ikinci derece Newton-Raphson 20 iterasyonda yakınsadı (ekrandan, 02:15:00). Newton-Raphson'da adım büyüklüğü parametresi yoktur, ama Hessian matrisinin hesaplanması ve tersinin alınması gerekir.
  - Ders sonrası not: Python kontrolüne göre $-1.9$'dan başlayan ikinci derece Newton-Raphson yaklaşık 19-20 iterasyonda $x=0$'a yakınsıyor. Bu nokta $f'(0)=0$ ve $f''(0)=0$ olan bir düzlük (dönüm) noktasıdır, $9/4$'teki minimum değildir.

- **Kuadratik fonksiyonlar.** İki boyutlu örnekte $q=\begin{bmatrix}1&0.5\\0.5&2\end{bmatrix}$, $b=[-0.5;-0.5]$, $c=0.5$ ile $f(x)=x_1^2/2+x_1x_2/2+x_2^2-0.5x_1-0.5x_2+0.5$ yazıldı; ikinci türevler matrisinin $q$'ya eşit olduğu gösterildi (ekrandan, 02:45:00). $q$'nun özdeğerleri pozitif olduğundan fonksiyon konveks bir kasedir. Newton-Raphson bu fonksiyonda minimuma tek adımda gitti; python kontrolü de bu fonksiyonda tek Newton adımının başlangıç noktasından bağımsız olarak tam minimum $x^*=-q^{-1}b=(3/7,\ 1/7)$'yi verdiğini doğruluyor. Konveks olmayan bir fonksiyonda ise Newton-Raphson bir başlangıç noktasından birkaç adımda eyer noktasına yakınsadı, gradient descent ise aynı noktadan minimuma gitti; ikinci dereceden yöntemlerin daha hızlı ama daha az kararlı olduğu vurgulandı.
  - Ders sonrası not: Hoca matris tersi alma süresinin boyutla "eksponansiyel" arttığını söyledi. Standart yöntemlerle $d\times d$ matrisin tersini almanın maliyeti büyük olasılıkla $O(d^3)$ gibi polinom düzeyindedir; yani hızlı artar ama üstel değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
