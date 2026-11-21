# Ders 2 Genişletilmiş Notu: Optimizasyona Giriş: Konvekslik, Gradient Descent ve Newton-Raphson

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Optimizasyon Bölümüne Giriş
- 2. Matematiksel Optimizasyon Problemi
- 3. Kısıtlı Optimizasyon Örneği: Çit Problemi
- 4. Türev Kullanan ve Kullanmayan Teknikler
- 5. Lineer, Afin ve Konveks Fonksiyonlar
- 6. İteratif Optimizasyonun Genel Algoritması
- 7. Gradient Descent: Yalnız Türevin İşaretiyle
- 8. Gradient Descent: Türevin Büyüklüğüyle
- 9. Başlangıç Noktasının Etkisi ve Yerel Minimum
- 10. Steepest Descent
- 11. Lineer Yaklaşım ve Taylor Serisi
- 12. Newton-Raphson Yöntemi
- 13. Sayısal Türev
- 14. Çok Boyutlu Fonksiyonlar, Gradyan ve Kuadratik Fonksiyonlar
- 15. İki Boyutta Optimizasyon Karşılaştırmaları
- Örnek Sorular
- Dersin Toparlaması

## 1. Optimizasyon Bölümüne Giriş

Bu ders, dersin yaklaşık üç haftasını kapsayacak olan optimizasyon bölümünün ilk dersidir. Slaytların başlığı "Optimization Techniques" ve ilk dosya "Section 1" adını taşıyor (ekrandan, 00:05:00). Hoca, anlatılan bütün kavram ve algoritmaların MATLAB kodlarının bulunduğunu, her slaytta ilgili kodun dosya adının yazdığını söyledi. Daha önce MATLAB kullanmamış olanların endişelenmemesini, başka programlama dillerini bilenlerin kodları rahatça okuyabileceğini belirtti. Üç haftada çok konu işleneceği için bazı kısımlardan kısa geçileceğini de ekledi.

## 2. Matematiksel Optimizasyon Problemi

Matematiksel optimizasyon probleminin temel biçimi slaytta şöyle verildi (ekrandan, 00:05:00):

$$
\begin{aligned}
\text{minimize}\quad & f_0(x)\\
\text{subject to}\quad & f_i(x)\le b_i,\quad i=1,\dots,m
\end{aligned}
$$

- $x=(x_1,\dots,x_n)$: optimizasyon değişkenleri. $x$ tek boyutlu olmak zorunda değildir, $n$ boyutlu bir vektördür.
- $f_0:\mathbb{R}^n\to\mathbb{R}$: amaç fonksiyonu (objective function), yani optimize edilmek istenen fonksiyon.
- $f_i:\mathbb{R}^n\to\mathbb{R}$, $i=1,\dots,m$: kısıt fonksiyonları (constraint functions).

Amaç, $f_0$'ı en küçük yapan $x$'i bulmaktır. Bu $x$ bulunursa fonksiyonun en küçük değeri de bulunmuş olur. Maksimizasyon problemleri de bir şekilde minimizasyona çevrilebildiği için genel olarak minimizasyon biçimi yazılır. "Subject to" kısmı $x$'in bulunmasını istediğimiz bölgeleri tanımlar; örneğin "şu aralığın içinde olsun, şu aralığın içinde olmasın" gibi. Bu kısım hiç olmayabilir; o zaman bütün uzay arama alanıdır ve probleme kısıtsız optimizasyon (unconstrained optimization) denir.

Optimal çözüm $x^*$ (x yıldız), kısıtları sağlayan bütün vektörler arasında $f_0$'ın en küçük değerini veren vektördür. Optimizasyon problemlerinde amaç bu $x^*$'ı bulmaktır; hoca bunun her zaman başarılamayabileceğini, bunun ilerleyen kısımlarda görüleceğini söyledi.

## 3. Kısıtlı Optimizasyon Örneği: Çit Problemi

Slayttaki örnek şuydu: "Find the largest possible rectangular area you can enclose, assuming you have $L$ meters of fencing." Elimizde $L$ metrelik bir çit var; bu çitle çevrilebilecek en büyük dikdörtgen tarla alanı nedir? Slayttaki fonksiyon $f(x)=x\cdot(L/2-x)$'tir (ekrandan, 00:05:00 karesindeki slayt listesi).

Çözüm şöyle kuruldu. Dikdörtgenin çevresi $L$ olduğundan iki komşu kenarın toplamı $L/2$'dir. Bir kenara $x$ dersek diğer kenar $L/2-x$ olur. Alan bu iki kenarın çarpımıdır:

$$f(x)=x\left(\frac{L}{2}-x\right)$$

Bu kez istenen maksimumdur ("largest possible area"). Bir öğrenci türev alıp sıfıra eşitleyerek ekstremum noktasını bulmayı önerdi:

$$f'(x)=\frac{L}{2}-2x=0 \;\Rightarrow\; x=\frac{L}{4}$$

Diğer kenar da $L/2-L/4=L/4$ olur. Hoca bunun anlamını sordu: sonuç, şeklin kare olması gerektiğini söyler.

Hoca, burada aslında kısıtlı bir problemin kısıtsız bir probleme dönüştürüldüğünü vurguladı: çevre kısıtı amaç fonksiyonunun içine gömüldü. Kısıtları amaç fonksiyonunun içine gömerek problemi kısıtsızmış gibi çözmek Lagrange denklemlerinin temel fikridir. Slaytta ayrıca bir veri noktaları kümesinden geçen en uygun modeli bulma ve bir parayı borsada en uygun biçimde dağıtma (portföy) gibi gündelik optimizasyon örnekleri de vardı.

## 4. Türev Kullanan ve Kullanmayan Teknikler

Optimizasyon teknikleri iki büyük gruba ayrıldı (ekrandan, 00:10:00):

- **Türev kullanan teknikler (derivative techniques):** gradient descent, Newton-Raphson, LM, BFGS.
- **Türev kullanmayan teknikler (non-derivative techniques):** hill climbing, genetik algoritmalar, simulated annealing.

Hoca ikinci gruba "türevi kullanamayan" demenin daha doğru olabileceğini söyledi. Sürekli bir uzayda türev tanımlıdır, ama ayrık (discrete) bir uzayda türev tanımlamak oldukça güçtür; orada daha sembolik işlemler yapılır. Amaç fonksiyonunun türevi alınamıyorsa türev kullanmayan tekniklere geçmek gerekir. Hill climbing türev kullanan tekniklerde de kullanılabilir, ama temelde türev kullanmayan bir teknik olarak geçer.

## 5. Lineer, Afin ve Konveks Fonksiyonlar

### 5.1 Lineer ve afin fonksiyonlar

$f:\mathbb{R}^n\to\mathbb{R}$ bir fonksiyon olsun. $\mathbb{R}^n$'deki bütün $x_1,x_2$ noktaları için şu iki koşul sağlanıyorsa $f$ lineerdir:

- **Toplamsallık:** $f(x_1+x_2)=f(x_1)+f(x_2)$. Değişkenleri toplayıp fonksiyona vermek ile fonksiyon değerlerini toplamak aynı sonucu verir.
- **Çarpımsallık:** $f(r\,x_1)=r\,f(x_1)$.

Örneğin $f(x)=2x$ hem lineer hem afindir. $f(x)=2x+3$ ise orijinden geçmeyen bir doğrudur; toplamsallık koşulunu sağlamaz, bu yüzden lineer değildir ama afindir. Lineer fonksiyonlar orijinden geçmek zorundadır. Orijinden geçen lineer bir fonksiyon yukarı ya da aşağı ötelenirse davranışı yine doğrusal görünen bir fonksiyon elde edilir; bunlara afin fonksiyonlar denir. Sabit fonksiyon $f(x)=3$ de $x$'e bağlı değildir, tek boyutta düz bir yatay çizgidir; orijinden geçmediği için lineer değil, afindir.

### 5.2 Konveks fonksiyon tanımı

Slayttaki tanım (ekrandan, 00:15:00):

$$\lambda f(x_1)+\beta f(x_2)\ \ge\ f(\lambda x_1+\beta x_2),\qquad \lambda+\beta=1,\ \lambda\ge0,\ \beta\ge0$$

$\beta$ yerine $1-\lambda$ yazılabilir. Slayttaki çizimde $x_1$ ile $x_2$ arasındaki herhangi bir nokta $t x_1+(1-t)x_2$ olarak yazılır. Hoca bu ifadeyi sınıfa sordu:

- $t=1$ için nokta $x_1$ olur.
- $t=0$ için nokta $x_2$ olur.
- $t=0.5$ için nokta $(x_1+x_2)/2$, yani tam orta nokta olur.

Bu noktanın fonksiyondaki karşılığı $f(t x_1+(1-t)x_2)$'dir (siyah eğri üzerindeki nokta). İki uç noktayı birleştiren düz doğrunun aynı yerdeki değeri ise $t f(x_1)+(1-t)f(x_2)$'dir (kırmızı doğru üzerindeki nokta). Tanım, kırmızı doğrunun her zaman siyah eğrinin üstünde ya da üzerinde olduğunu söyler. Bu bütün olası $x_1,x_2$ çiftleri için geçerliyse fonksiyon konvekstir.

Her fonksiyon konveks değildir. Hoca aşağı doğru kıvrılan bir fonksiyon çizdi: bu fonksiyonda iki noktayı birleştiren doğru, fonksiyonun her zaman altında kalır. Eşitsizlik ters çevrilirse (büyük eşit yerine küçük eşit) konkav fonksiyon tanımı elde edilir.

### 5.3 Örnekler

Slayttaki örnekler sırayla tartışıldı (ekrandan, 00:20:00):

- **$f(x_1)=3x_1+3$:** Afin bir fonksiyondur. Bir öğrenci "büyük eşit" koşulundaki eşitlik nedeniyle konveks olabileceğini söyledi; hoca doğruladı. Düz bir çizgi üzerinde alınan iki noktayı birleştiren doğru zaten fonksiyonun kendisidir, eşitlik her zaman sağlanır. Bu yüzden düz çizgilerden oluşan her afin fonksiyon konvekstir.
- **$f(x_1,x_2)=a x_1+b x_2+c$:** İki değişkenli bir fonksiyondur; her $(x_1,x_2)$ için bir değer ürettiği için bir çizgi değil, bir yüzey tanımlar. $x_1$ bir boyut, $x_2$ ikinci boyut, $f$ üçüncü boyut olmak üzere üç boyutlu uzayda bir düzlemdir. $a,b,c$'nin farklı değerleri farklı düzlemler verir. Bir doğru gibi düzlem de konvekstir.
- **$f(x_1,x_2)=x_2^2+x_1^2+3x_1$:** Bir öğrenci kare terimlerin pozitif olacağını, bu yüzden konveks olduğunu söyledi. Hoca araştırılmasını istedi. Dersin ikinci yarısında bir öğrenci fonksiyonu çevrimiçi bir araçla üç boyutta çizdirdiğini ve konveks çıktığını belirtti; hoca bir ve iki değişkenli fonksiyonların çizilerek rahatça incelenebileceğini, daha yüksek boyutta bunun zorlaştığını söyledi. Bir öğrencinin çember denklemi $x^2+y^2=r^2$ ile benzetmesine hoca, bunun çember fonksiyonu olmadığını söyleyerek karşılık verdi.
- **$f(x)=\sin x$:** Konveks değildir. Hoca iki nokta seçti: bir çiftte birleştiren doğru fonksiyonun altında kalıyor, başka bir çiftte üstünde kalıyor. Bu yüzden $\sin x$ ne konveks ne konkavdır; bazı bölgelerde konveks, bazı bölgelerde konkav olan bir fonksiyondur. Slayttaki soru "$\sin x$ hangi aralıkta konvekstir?" biçimindeydi.

> **Ders sonrası not:** Hoca $[0,\pi]$ aralığını konveks, $[-2\pi,-\pi]$ aralığını konkav diye örnekledi. $(\sin x)''=-\sin x$ olduğundan doğrusu tersidir: $\sin x\ge 0$ olan $[0,\pi]$ ve $[-2\pi,-\pi]$ aralıklarında fonksiyon konkav, $\sin x\le0$ olan $[-\pi,0]$ ve $[\pi,2\pi]$ aralıklarında konvekstir.

### 5.4 Konveks fonksiyonlar neden önemli?

Hoca konveks fonksiyonların optimizasyon açısından çok önemli bir özelliği olduğunu söyleyip sordu. Bir öğrenci bir minimum (dip) noktası olacağını söyledi. Hoca, konveks fonksiyonların optimal noktalarını bulmanın konveks olmayan fonksiyonlara göre çok daha kolay olduğunu belirtti; bunun nedeni ilerleyen bölümlerde (Bölüm 8 ve 9) netleşti.

## 6. İteratif Optimizasyonun Genel Algoritması

Elimizde bilinen bir fonksiyon var ve onu en küçük yapan $x$'i arıyoruz. Sağduyu türevi kullanmamızı söyler. Bir noktadan başlarız; çok şanslı değilsek başlangıçta minimumu bulamayız. Tek boyutta düşünürsek, bulunduğumuz noktadan sağa mı sola mı gideceğimize karar vermemiz gerekir. Bu yönü türev söyler: türevin işaretinin tersi yönde gitmek mantıklıdır. Ama ikinci bir soru daha vardır: o yönde ne büyüklükte bir adım atılacak?

Slayttaki genel algoritma (ekrandan, 00:30:00 karesindeki slayt listesi):

```text
Initial guess
While (improvement is significant) and (maximum number of iterations is not exceeded)
    - improve the result
```

- **Başlangıç tahmini (initial guess):** Rastgele bir noktadan başlanır.
- **Anlamlı iyileşme:** Sürekli uzay dijital bilgisayarda tam temsil edilemez, kesikli bir yapıda temsil edilir. Bu yüzden bir yakınlık tanımlanır: ardışık iki $x$ arasındaki fark (ya da $f$ değerleri arasındaki fark) bir eşik değerinden, örneğin $0.000001$ gibi bir değerden küçükse artık önemli bir iyileşme yapılamıyor demektir ve durulur. Problemlerin belli bir sürede çözülmesi gerektiği için bu koşul gereklidir.
- **En büyük iterasyon sayısı:** Eşik tanımlı olsa bile algoritma bir türlü o yakınlığa ulaşamayabilir. Sonsuza kadar dönmemesi için ikinci bir durma koşulu konur.

## 7. Gradient Descent: Yalnız Türevin İşaretiyle

Gradient descent bölümü slaytta şu başlıklarla açıldı: yalnız türevin işaretini kullanmak, türevin büyüklüğünü de kullanmak, adım büyüklüğünün etkisi, başlangıç noktasının etkisi ve yerel minimum problemi (ekrandan, 00:30:00).

### 7.1 Kod

İlk yaklaşımda yalnız türevin işareti kullanılır ve adım büyüklüğü sabittir. Slayttaki `gradient_desc_1.m` kodu (ekrandan, 00:35:00):

```matlab
% The gradient descent algorithm with constant stepsize
% f(x)=x^2, with derivative f'(x)=2x
clear all;
close all;
% plot objective function
x=-5:0.01:5;
y=zeros(1,length(x));
for i=1:length(x)
    y(i)=x(i)^2;
end
plot(x,y);
x_old = 0;
x_new = -4.9;   % The algorithm starts at x=-4.9
eps = 0.05;     % step size
precision = 0.00001;  % stopping condition1
max_iter=200;   % stopping condition2
Xs=zeros(1,max_iter);
Ys=zeros(1,max_iter);
i=1;
while abs(x_new - x_old) > precision && max_iter>=i
    Xs(i)=x_new;
    Ys(i)=x_new^2;
    hold on;
    plot(Xs(i),Ys(i),'r*');
    text(Xs(i),Ys(i),int2str(i));
    x_old = x_new;
    df= 2 * x_old;
    x_new = x_old - eps * sign(df); % gradient sign
    i=i+1;
end
figure;
plot(Xs(1:i-1));
xlabel('iteration');
ylabel('x values');
```

Amaç fonksiyonu $f(x)=x^2$'dir; minimumunun $0$ olduğunu biliyoruz, ama hoca bunun bilinmeyen bir fonksiyon da olabileceğini, yöntemin bunu bilmeden adım adım minimuma yaklaşmaya çalıştığını hatırlattı. Güncelleme kuralı:

$$x_{new}=x_{old}-eps\cdot\mathrm{sign}\big(f'(x_{old})\big)$$

### 7.2 Çalıştırma sonuçları

$-4.9$'dan başlanır. Bu bölgede türev $2x$ negatiftir, o halde $x$ artırılır, yani sağa doğru gidilir. Her adımda sabit $0.05$ kadar ilerlenir. Grafikte 1, 2, 3, ... numaralı noktalar adım adım minimuma yaklaşır, sonra sıfır çevresinde zikzak çizmeye başlar.

Döngü koşulu `abs(x_new - x_old) > precision` biçimindedir. Hoca sordu: ardışık iki nokta arasındaki fark her zaman nedir? Cevap $0.05$'tir. Bu değer hiçbir zaman precision değerinden küçük olamaz; bu yüzden döngüden yalnız en büyük iterasyon sayısına (200) ulaşınca çıkılır. Sıfıra yaklaşıldıktan sonra algoritma sıfırdan uzaklaşmaz ama "tık tık tık" iki değer arasında dolanıp durur. Optimum noktaya en fazla adım büyüklüğü kadar (ortalama olarak belki yarısı kadar) yaklaşılabilir, daha fazla yaklaşma şansı yoktur.

Kaç adımda varılacağı bu fonksiyon için önceden tahmin edilebilir: başlangıç ile sıfır arasında yaklaşık 5 birimlik mesafe vardır; $0.05$'lik adımlarla bu mesafe yaklaşık 100 adımda kapanır. Gerçekten de yaklaşık 100. iterasyonda sıfıra oturup sonra zikzak yapıyor.

- **$eps=0.1$:** Noktalar birbirinden daha uzaktır. Minimum yakınına yaklaşık 50. adımda varılır, sonra zikzak yine sürer. Adımı büyütmek ya da küçültmek asıl sorunu çözmez.
- **$eps=0.01$:** 200 iterasyonda minimuma varılamaz; varmak için yaklaşık 500 iterasyon gerekirdi. Algoritma en büyük iterasyon sayısı nedeniyle yolda kalır.

Hoca bunların sabit adım büyüklüğüyle ilerlemenin sıkıntıları olduğunu söyledi.

## 8. Gradient Descent: Türevin Büyüklüğüyle

### 8.1 Fikir

Asıl gradient descent algoritması, türevin yalnız hangi yöne gidileceğini değil, ne büyüklükte adım atılacağını da söylediğini kullanır. Türev büyükse optimum noktadan uzaktayızdır; türev sıfıra yakınsa optimuma yakınızdır, çünkü optimum türevin sıfır olduğu noktadır. Bu yüzden güncellemedeki işaret fonksiyonu kaldırılır (ekrandan, 00:40:00):

$$x_{new}=x_{old}-eps\cdot f'(x_{old})\qquad\text{(önceki: } x_{new}=x_{old}-eps\cdot \mathrm{sign}(f'(x_{old}))\text{)}$$

Slayttaki soru: "Gerekli iterasyon sayısını azaltabilir miyiz?"

### 8.2 Adım büyüklüğünün etkisi

`gradient_desc_2.m` ile slaytlarda şu sonuçlar gösterildi:

| Adım büyüklüğü ($eps$) | İterasyon | Davranış |
|---|---|---|
| 0.05 | 120 | Zikzak yok, precision koşuluyla duruyor |
| 0.1 | 60 | Daha hızlı yakınsıyor |
| 0.01 | 200 (sınır) | Henüz varamadı, daha fazla iterasyon gerekiyor |
| 0.7 | 16 | Zikzak var ama genliği hızla küçülüyor |
| 0.99 | 200 (sınır) | $-5$ ile $+5$ arasında sıçrıyor, aralık giderek daralıyor |
| 1 | 200 (sınır) | Yakınsamıyor (ekrandan, 00:45:00) |

$eps=0.05$ ile 200'e varılmadan 120. iterasyonda durulmasının nedenini bir öğrenci açıkladı: başta büyük büyük adımlar atılıyor, sonra adımlar küçülüyor. Ardışık iki $x$ arasındaki fark precision değeri olan $10^{-5}$'in altına düştüğü için döngü en büyük iterasyon sayısından değil, precision koşulundan çıkıyor. Bu kez sabit büyüklükte zikzak yoktur; $x$ minimuma tek taraftan yaklaşır. Daha büyük adımlarda öteki tarafa geçmek mümkündür, ama sabit büyüklükte zikzak olmaz. Hoca bunun güzel tarafının, maksimum iterasyona gitmek zorunda kalmadan optimum noktaya istenildiği kadar yaklaşabilmek olduğunu söyledi. Yine de adım büyüklüğünün etkisi tamamen ortadan kalkmaz.

$eps=0.7$'de 1. nokta bir tarafta, 2. nokta öteki tarafta, 3. nokta yine ilk tarafta olur; zikzak vardır ama giderek küçülür ve 16 adım sonra ardışık iki $x$ arasındaki fark $10^{-5}$'in altına iner. $eps=0.99$'da da bir zikzak vardır; $x$ değerleri $-5$ ile $+5$ arasında sıçrar ama aralık giderek daralır.

$eps=1$'de hoca "ne olmuş burada?" diye sordu. Öğrenciler önce minimumu ilk adımda bulduğunu ya da yan tarafa sıçradığını düşündü. Hoca grafiğin ölçeğine dikkat çekti: yatay eksen $10^{16}$, dikey eksen $10^{32}$ ölçeğindedir. Başlangıçtaki değerler bu ölçekte sıfır gibi görünse de aslında $x$ giderek büyümektedir. Algoritma zikzak yaparak optimum noktadan uzaklaşır, yani ıraksar (diverge eder).

> **Ders sonrası not:** $f(x)=x^2$ için güncelleme $x\leftarrow x-2\,eps\,x=(1-2\,eps)\,x$ biçimindedir. Bu yüzden $0<eps<1$ iken yakınsama olur, $eps=1$ iken $x$ yalnız işaret değiştirir ($x\to -x$, sabit genlikli salınım), $eps>1$ iken ıraksar. Görünen kod ayrıntılarıyla (başlangıç $-4.9$, precision $10^{-5}$) python ile yapılan benzetimde iterasyon sayıları $eps=0.05$ için 104, $eps=0.1$ için 53, $eps=0.7$ için 16 çıktı. Slayttaki 120 ve 60 değerleri ile $10^{16}$ ölçeğine çıkan grafik büyük olasılıkla kodun ekranda görünmeyen bir ayrıntısından (başlangıç noktası, durma eşiği ya da adım değeri) kaynaklanıyor.

### 8.3 Adım büyüklüğü seçimi

Adım büyüklüğü birçok algoritmada öğrenme oranı (learning rate) adıyla geçer ve iyi seçilmesi gerekir. Neye göre? Fonksiyona göre; fonksiyona göre denemek gerekir. Bir fonksiyonda büyük olan bir adım başka bir fonksiyonda küçük kalabilir. Bu yüzden adım büyüklüğünün seçimi kullanıcının başında bir iş yükü olarak durur.

> **Hocanın vurgusu:** "Büyük" ve "küçük" diye ifade ettiğimiz adım büyüklükleri amaç fonksiyonuna bağlıdır. $0.1$'in büyük mü küçük mü olduğuna dair genel bir şey söyleyemeyiz; bu, gradient descent'in kötü bir yanıdır.

## 9. Başlangıç Noktasının Etkisi ve Yerel Minimum

### 9.1 Konveks fonksiyonda

$f(x)=x^2$'de soldan başlanınca sağa, sağdan başlanınca sola doğru gidilir; büyük adımlarda zikzakların genliği küçülerek yine aynı noktaya varılır. Hoca sordu: nereden başlarsam başlayayım aynı optimum noktaya mı hareket ederim? Bir öğrenci, tek bir global minimum olduğu için türevin her zaman o noktayı göstereceğini söyledi. Hoca bunun konveks fonksiyonların özelliği olduğunu doğruladı: konveks fonksiyonlarda nereden başlanırsa başlansın aynı yere varılır. Başlangıç noktası varılacak yeri etkilemez; konveks fonksiyonlarla optimizasyonun güzelliği ve kolaylığı buradadır.

> **Ders sonrası not:** Hoca bu sırada adım büyüklüğü birden küçük seçilirse ıraksama olmayacağını söyledi. Bu, $f(x)=x^2$ fonksiyonu için geçerlidir (bkz. Bölüm 8.2'deki not). Genel bir fonksiyon için güvenli adım aralığı büyük olasılıkla fonksiyonun eğriliğine bağlıdır, sabit bir "1" sınırı yoktur.

### 9.2 Konveks olmayan fonksiyonda

Slayttaki fonksiyon (ekrandan, 00:50:00):

$$f(x)=x^4-3x^3+2,\qquad f'(x)=4x^3-9x^2$$

Bu fonksiyonun iki ekstremum noktası, yani türevin sıfır olduğu iki noktası vardır: $x=0$ ve $x=9/4$. (Python kontrolü: $f'(x)=x^2(4x-9)=0$ kökleri $0$ ve $2.25$'tir.)

Ara sonrası hoca `gradient_desc_3.m` kodunu MATLAB'de açtı. Kodun yapısı öncekiyle aynıdır: precision $10^{-5}$, en büyük iterasyon 200, `Xs` ilerlenen $x$ değerlerini, `Ys` bunlara karşılık gelen $f$ değerlerini tutar. Döngüde mevcut nokta kaydedilir, $f$ değeri hesaplanır, kırmızı bir yıldızla işaretlenir, yanına `int2str` ile kaçıncı adım olduğu yazılır; sonra `df` eski noktadaki türev olarak hesaplanır ve `x_new = x_old - eps * df` uygulanır.

Soldan (yaklaşık $x=-1.9$'dan) başlatılan çalıştırmada 1. nokta, 2. nokta ve 3. nokta hızla aşağı iner, sonra noktalar $x=0$ çevresinde yığılır (ekrandan, 01:30:00). 200. iterasyona kadar ilerlenir ama $0$'ın ötesine geçilemez. Bu aralıkta fonksiyonun minimumu $9/4$ civarındadır; varmak istediğimiz yer orasıydı. Neden takıldı? Çünkü $0$'a yaklaştıkça türev sıfır oluyor (bir öğrencinin deyişiyle bir "plato"). Türev sıfır olunca güncellemede $x_{new}=x_{old}$ olur; algoritma orada takılıp kalır, diğer tarafa geçemez.

> **Ders sonrası not:** Hoca canlı çalıştırmada adım büyüklüğünün $0.1$ olduğunu söyledi. Python kontrolüne göre $-1.9$'dan $eps=0.1$ ile başlanırsa algoritma ıraksıyor; slayttaki karşılaştırmada (ekrandan, 02:15:00) aynı başlangıç için $eps=0.01$ yazıyor. Canlı çalıştırmadaki değer büyük olasılıkla $0.01$'dir. Python ile $-1.9$'dan $eps=0.01$ ile 200 iterasyon sonunda $x\approx-0.049$'da kalınıyor.

Başlangıç noktası $3.5$ yapılınca algoritma $2$ küsur bir noktaya, yani $9/4$'teki minimuma yakınsadı. Böylece başlangıç noktası varılan yeri etkiledi: bu fonksiyon konveks değildir. Konveks olsaydı nereden başlanırsa başlansın aynı yere gidilirdi.

Adım büyüklüğü $0.05$ yapılınca soldan başlayan algoritma 1'den 2'ye büyük bir sıçrama yaparak düzlük bölgesini atlayabildi ve minimuma çöktü. Hoca bunun bir şans işi olduğunu söyledi: bir ve iki boyutta bunu görebiliyoruz, ama yüksek boyutlarda neler olup bittiğini bu kadar net görmek mümkün değildir. Tersi de mümkündür: fonksiyonun küçük adımlarla gidilecek yerde daha derin bir çukuru olabilir; büyük adım atınca orası kaçırılır ve daha kötü bir yere yakınsanır. Bu, önceden bilinemeyen fonksiyon tipine bağlıdır. (Python kontrolü: $-1.9$'dan $eps=0.05$ ile 9 iterasyonda $2.25$'e varılıyor; $3.5$'ten $eps=0.01$ ile 42, $eps=0.05$ ile 14 iterasyonda $2.25$'e varılıyor.)

### 9.3 Soru-cevaplar

**Soru:** Bilmediğimiz bir fonksiyonun konveks olup olmadığını nasıl teyit edebiliriz? **Cevap:** Konvekslik eşitsizliğinin her $x_1,x_2$ çifti için geçerli olduğunu kanıtlayabilirseniz fonksiyona konveks diyebilirsiniz. Bir ve iki değişkenli fonksiyonlar çizilerek rahatça incelenebilir; daha yüksek boyutta fonksiyonun konveks olup olmadığını anlamak oldukça güçtür.

**Soru:** Konveks olmayan bir fonksiyonu konveks bir fonksiyona çevirmek mümkün mü? **Cevap:** Belli fonksiyonlar için mümkündür; problem başka şekilde ifade edilerek konveks hale getirilebilir. Ama her fonksiyon için mümkün olsaydı konveks olmayan optimizasyon diye bir alan olmazdı. Temelde problemi farklı biçimde ifade etmekten geçer; belli fonksiyon tipleri için prosedürler oluşturulabilir, ama genel geçer bir yöntem yapmak oldukça güçtür.

Hoca bu noktada dersin ilerleyen kısımlarına bağlantı kurdu: yapay sinir ağlarının hata-parametre uzayları (kayıp fonksiyonları) genelde konveks değildir. Belki tek bir perceptron için konvekstir, ama birden fazla katmandan oluşan yapılarda değildir. Yine de orada konveks optimizasyon teknikleri kullanılır ve işe yarar; bu, insanları şaşırtan, çeşitli açıklamalar getirilmeye çalışılan, çok araştırılan bir konudur. İlerleyen haftalarda bu uzayların nasıl anlaşılacağı, tanımlanacağı ve geometrisinin nasıl görüleceği üzerine çalışılacağı söylendi.

**Soru:** Noktaları belirlerken bir moment, bir hız verseydik, türevin sıfır olduğu yerden türevin sıfırdan farklı olduğu yere ötelenebilir ve gerçek minimuma ulaşırdık. Ayrıca "her yerden başlatınca gerçek minimuma ulaşıyorsa konvekstir" yaklaşımı doğru mu? **Cevap:** Hoca, sağa doğru inip çıkan, sonra tekrar inip çıkan bir fonksiyon çizdi ve bulunan yerin global minimum olduğundan emin olunup olunamayacağını sordu. Konveks fonksiyonların en temel özelliği, bulunan bir minimumun global minimum olmasıdır. Konveks olmayan fonksiyonlarda bulunan minimumun global olduğundan emin olunamaz. Bulunan çözüm yeterince iyi olabilir ve kullanılabilir, ama daha iyisi her zaman olabilir, çünkü bütün uzayı taramak mümkün değildir. Örneğin 100 bin parametreli bir yapay sinir ağının (günümüz için büyük bir sayı değil) hata-parametre uzayı 100 bin bir boyutludur; bu uzayda bütün noktaları deneyip bulunan noktanın gerçekten minimum olduğunu söylemek mümkün değildir. Ama fonksiyon konveksse, boyut 100 bin bir de olsa bulunan minimumun global olduğundan emin olunur.

> **Hocanın vurgusu:** Konveks fonksiyonda bulunan minimum global minimumdur. Konveks olmayan fonksiyonda bulunan minimum yeterince iyi olabilir ama global olduğu garanti edilemez.

## 10. Steepest Descent

İkinci slayt dosyasına (Section 2) geçildi. Hoca burada temel mantığı anlatıp ayrıntılara girmeyeceğini, ayrıntıların slaytlarda ve kodlarda olduğunu söyledi.

### 10.1 Adım büyüklüğünü hesaplamak

Steepest descent'te bir yön belirlendikten sonra o yönde ne kadar gidileceği dışarıdan verilmez, hesaplanır. Seçilen yön boyunca bir fonksiyon (bir kesit) oluşturulur ve bu fonksiyonun minimum noktası bulunur. "Bu yönde dümdüz devam edersem fonksiyonun en küçük olduğu noktayı nerede yakalarım?" sorusunun cevabı adım büyüklüğünü verir.

### 10.2 Eş değer eğrileri ve dik adımlar

Gösterilen şekil iki boyutlu, konveks bir fonksiyonun eş değer eğrilerini (sarı çizgiler) içeriyordu (ekrandan, 01:45:00). Hoca bir sarı çizgi üzerindeki noktaların ortak özelliğini sordu; bir öğrenci aynı düzeyde olduklarını söyledi. Hoca doğruladı: o noktaların hata değerleri aynıdır, coğrafyadaki izohips eğrileri gibi. Burada içeriye doğru aşağı inildiğini düşünmek gerekir.

$x_n$ noktasındaki türev (gradyan) mavi ok yönündedir: o noktada eğriye çizilen teğete dik ve dışarı doğrudur. Biz türevin tersine, yani kırmızı çizgi yönünde gitmek isteriz. Bu yön boyunca kesikli çizgiyle gösterilen fonksiyon, bir noktaya kadar azalır, sonra artmaya başlar; en küçük olduğu nokta $x_{n+1}$ olur. Slayttaki ifade:

$$x_{n+1}=x_n-\delta g_n,\qquad x_{n+2}=x_{n+1}-\delta g_{n+1}$$

Burada $g_n$, $x_n$'deki gradyandır. Yeni noktada türev yeniden hesaplanır ve aynı işlem tekrarlanır. Slaytın başlığı: "the new search direction will always be perpendicular to the previous direction". Birinci, ikinci, üçüncü, dördüncü adımlar birbirine diktir.

### 10.3 En iyi ve en kötü başlangıç

Sonraki slaytta "best initial guess" ve "worst initial guess" işaretliydi (ekrandan, 01:50:00). Rastgele bir yerden başlanırsa steepest descent zikzaklar çizerek ilerler. Ama başlangıç noktası, fonksiyonun bir özvektör doğrultusu üzerindeyse (hoca "eigen vektör" dedi), aşırı şanslı biri o noktadan tek adımda optimuma varabilir; çünkü o yön fonksiyonun minimum noktasından geçer. Genelde bu kadar şanslı olunmaz.

### 10.4 Değerlendirme

Steepest descent adım büyüklüğünü dışarıdan vermeye gerek bırakmadığı için iyi bir yöntemdir. Ama az sayıda adımla hızla yakınsayıp yakınsamayacağı tartışmalıdır. Her iterasyonda yön boyunca oluşturulan fonksiyonun minimumunu bulmak gerektiği için her iterasyon işlem ister; gradient descent kadar hızlı iterasyon ilerletilemez.

Hoca bu kesit fonksiyonunun minimumunun her zaman bulunup bulunamayacağını ve tek olup olmadığını sordu. Asıl fonksiyon konveksse, üzerinde oluşturulabilecek her kesit fonksiyonu da konveks olur ve tek bir minimumu vardır; bu durumda çözüm her zaman bulunabilir. Hoca steepest descent'in sıklıkla tercih edilen bir yöntem olmadığını belirtti.

## 11. Lineer Yaklaşım ve Taylor Serisi

### 11.1 Lineer yaklaşım

Lineer yaklaşım (linear approximation), birazdan görülecek Newton-Raphson yönteminin temelini oluşturur. Fonksiyon aslında lineer değildir, ama belli bir noktada lineermiş gibi kabul edilir.

Slayttaki şekilde mavi eğri asıl fonksiyondur. $x$ noktasından $\Delta x$ kadar ilerlenince asıl fonksiyonun değeri $f(x+\Delta x)$ (B noktası) olur. $x$ noktasındaki teğet doğrusu üzerindeki değer ise

$$L(x+\Delta x)=f(x)+dy$$

ile verilir. $x$ noktasındaki türev $f'(x)=dy/dx$ olduğundan $dy=\Delta x\, f'(x)$ yazılır. Hoca $L(x+\Delta x)$ ile $f(x+\Delta x)$'in birbirine yakın olup olmadığını, yakın olmaları için ne gerektiğini sordu: $\Delta x$ sıfıra çekildikçe aradaki fark da sıfıra gider,

$$\lim_{\Delta x\to0}\big[f(x+\Delta x)-L(x+\Delta x)\big]=0.$$

Böylece birinci derece yaklaşım elde edilir:

$$f(x+\Delta x)\approx f(x)+\Delta x\, f'(x)$$

Bu bir eşitlik değil, yaklaşıklıktır. Lineer yaklaşımla gerçek değer değil, teğet üzerindeki değer bulunur ve bir hata yapılır. Adım ($\Delta x$) ne kadar küçükse hata o kadar azdır.

### 11.2 Örnek: $(1.0002)^{50}$

Slayttaki örnek (ekrandan, 01:55:00):

- Soru: $(1.0002)^{50}\approx\,?$
- $f(x)=x^{50}$, $f(x+\Delta x)\approx f(x)+\Delta x\, f'(x)$.
- $\mathrm{dom}x=1.0002$, $x=1$, $\Delta x=0.0002$.
- $f'(x)=50x^{49}$ olduğundan $f(1+0.0002)\approx f(1)+0.0002\cdot50\cdot1^{49}$.
- Sonuç: $f(1.0002)\approx 1+0.0002\cdot50\cdot1=1.01$.

Böylece 50 kez üs almak yerine türev kullanılarak yaklaşık değer bulunur. (Python kontrolü: gerçek değer $1.0100491\ldots$; yaklaşım hatası yaklaşık $5\times10^{-5}$'tir.) Slaytta $\ln x$ için benzer bir ikinci örnek de vardı; hoca ona öğrencilerin bakmasını istedi. Fikir şudur: $x$'teki değeri biliyoruz, yakın bir noktadaki değer için kesin değil yaklaşık bir değer yetiyorsa fonksiyonun kendisini hesaplamak yerine türeviyle işimizi görebiliriz.

### 11.3 Daha iyi yaklaşım: yüksek dereceler

Birinci derece yerine ikinci derece yaklaşıma geçilirse o noktada lineer değil, kuadratik (ikinci dereceden) bir fonksiyon oturtulur. Slayttaki formüller (ekrandan, 02:05:00):

- Birinci derece Taylor (lineer yaklaşım): $f(x+\Delta x)\approx f(x)+\Delta x\, f'(x)$
- İkinci derece Taylor (lineer olmayan yaklaşım): $f(x+\Delta x)\approx f(x)+\Delta x\, f'(x)+\tfrac12 f''(x)\,\Delta x^2$
- $N$. derece Taylor: $f(x+\Delta x)\approx\displaystyle\sum_{i=0}^{N}\frac{f^{(i)}(x)\,\Delta x^i}{i!}$

Derece arttıkça asıl fonksiyona daha yakın bir şey bulunur ve hata azalır. Fonksiyon zaten örneğin dördüncü dereceden bir polinomsa, dördüncü derece Taylor fonksiyonun kendisini verir. Ama fonksiyonlar her zaman bu kadar düzgün değildir; o zaman hep daha yakın hale gelinir, ama tam aynısı bulunamaz.

### 11.4 `approx_taylor.m` örnekleri

Slaytta $f(x)=e^x$, $N=0{:}5$, $X=0.25$ için yaklaşımlar çizildi: kırmızı gerçek $f$, mavi ve yeşil yaklaşımlar, yeşil son (en yüksek dereceli) yaklaşımdır (ekrandan, 02:00:00). Bütün yaklaşımlar $(0.25, f(0.25))$ noktasından geçer. Sıfırıncı derece yaklaşım bütün noktalara aynı değeri, yani $f(0.25)$'i verir (yatay bir doğru). Birinci derece bir doğru, sonrakiler ikinci, üçüncü, ..., beşinci derecedir. Yeşil eğri $0.25$ civarında kırmızının tam üstünden geçer, orada kırmızı görünmez bile; ama uzaklaştıkça yeşil ile kırmızı ayrılır. Aynı şey $X=1.25$ için de gösterildi. $f(x)=\sin x$ için 15. dereceye kadar çıkıldı; yine belli bir yere kadar eğriler üst üste oturur, sonra birbirinden uzaklaşır.

Taylor açılımı türevi alınabilen her fonksiyona uygulanabilir. Birinci derecede birinci türev, ikinci derecede ikinci türev, $n$. derecede $n$. türev gerekir. Türevler kolay hesaplanamıyorsa, pahalıysa ya da uzun sürüyorsa yüksek derecelere gitmek istense de gidilemeyebilir.

## 12. Newton-Raphson Yöntemi

### 12.1 Birinci derece: kök bulma

Taylor yaklaşımından hareketle önce bir fonksiyonun minimumu değil, kökü bulunacak. Bir öğrenci kökün fonksiyonun sıfır olduğu değer olduğunu söyledi. Slayttaki başlık: "Finding a root of $f(x)$ iteratively (find a point $x$ where $f(x)=0$), Newton-Raphson 1st order".

Animasyonda (ekrandan, 02:10:00) bir noktadan başlanır, o noktada birinci derece Taylor ile bir lineer fonksiyon, yani teğet (tangent) oluşturulur. Teğetin $x$ eksenini kestiği nokta bulunur, oradan yukarı çıkılıp yeni noktada yeniden teğet çizilir ve adım adım köke yaklaşılır.

Formül şekilden kuruldu. $x_n$ noktasındaki türev, dik kenarın yatay kenara oranıdır. Dik kenar $f(x_n)$, yatay kenar $x_n-x_{n+1}$'dir:

$$f'(x_n)=\frac{f(x_n)}{x_n-x_{n+1}}$$

Paydalar yer değiştirilirse $x_n-x_{n+1}=f(x_n)/f'(x_n)$ olur, buradan

$$x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)},\qquad n=0,1,2,\dots$$

elde edilir. $n$. noktadaki değerler kullanılarak $n+1$. nokta bulunur.

> **Ders sonrası not:** Hoca şekli anlatırken yatay kenarı "$x_n-x_{n-1}$" diye okudu ve ara adımda $x_{n-1}$ yazdı; sonuç formülü $x_{n+1}=x_n-f(x_n)/f'(x_n)$ doğrudur. Doğru yazım yatay kenar için $x_n-x_{n+1}$'dir.

Hoca bunun gradient descent'ten farkını vurguladı. Gradient descent'te güncelleme $x_{new}=x_{old}-eps\cdot df$ idi; adım büyüklüğü çarpı türev vardı. Burada ise $f(x_n)/f'(x_n)$ vardır ve $eps$ yer almaz.

Slaytta bu yöntemle $\sqrt2$'nin, yani $x^2-2=0$ denkleminin kökünün nasıl bulunacağı da gösterildi; hoca bu örneğin ayrıntısına girmedi (ekrandan, 02:15:00 karesindeki slayt listesi). (Python kontrolü: $x_0=1$'den başlanınca $x_1=1.5$, $x_2=1.416667$, $x_3=1.414216$, $x_4=1.414214$ bulunuyor.)

### 12.2 İkinci derece: minimum bulma

Hoca sordu: bu güzel süreci bir fonksiyonun minimum noktasını bulmak için de kullanabilir miyiz? Kök $f(x)=0$ olan yerdir; minimum ise $f'(x)=0$ olan yerdir. İkisinin arasındaki fark budur. Gradient descent de aslında türevin sıfır olduğu yeri bulur.

Birinci derece Taylor'a göre $f(x+\Delta x)=0$ için $\Delta x=-f(x)/f'(x)$ idi. $f'(x+\Delta x)=0$ noktasını bulmak için Taylor eşitliğinin her iki tarafının türevi alınır: $f'(x+\Delta x)\approx f'(x)+\Delta x\, f''(x)$. Bunu sıfıra eşitleyince ikinci derece Newton-Raphson elde edilir:

$$x_{n+1}=x_n-\frac{f'(x_n)}{f''(x_n)}$$

Aynı mantık bu kez fonksiyonun kendisinin değil, türevinin sıfır olduğu yeri bulmak için kullanılır: $f$ yerine $df$, $df$ yerine $ddf$ (ikinci türev) gelir.

### 12.3 Gradient descent ile karşılaştırma

$f(x)=x^4-3x^3+2$ üzerinde iki yöntem aynı başlangıç noktasından ($-1.9$) çalıştırıldı (ekrandan, 02:15:00):

- Gradient descent, adım büyüklüğü $0.01$: 200 iterasyonda yakınsamadı ("Does not converge with 200 iterations").
- Newton-Raphson, ikinci derece: 20 iterasyonda yakınsadı ("Converged at 20 iterations").

Newton-Raphson'da adım büyüklüğü, yani öğrenme oranı yoktur; onu aramakla uğraşmak gerekmez. Grafikte mavi $f$, kırmızı $f'$, yeşil $f''$'dür. Diğer taraftan başlatılan çalıştırmada Newton-Raphson 5.-6. iterasyonda yakınsadı. Birinci derece sürümle fonksiyonun kendisinin sıfır olduğu nokta da çok hızlı bulunabildi.

> **Ders sonrası not:** Python kontrolüne göre $-1.9$'dan başlayan ikinci derece Newton-Raphson yaklaşık 19-20 iterasyonda $x=0$'a yakınsıyor. Bu nokta $f'(0)=0$ ve $f''(0)=0$ olan bir düzlük (dönüm) noktasıdır, $9/4$'teki minimum değildir. Yani Newton-Raphson burada hızlı yakınsamış, ama gradient descent'in takıldığı noktaya yakınsamıştır.

### 12.4 Newton-Raphson'ın maliyeti

İki yöntem aynı amaçla, yani $f'$'nün sıfır olduğu yeri bulmak için kullanılır. İkisinde de $df$ hesaplanır; $df$ bir vektördür, her boyut için türev hesaplanır. Ama $ddf$ ikinci dereceden türevdir: her boyutun her boyuta göre türevi alınır ve bu bir matristir. $D$ boyut varsa $D\times D$'lik bir matris hesaplanır; 10 parametre için $10\times10$, 100 parametre için $100\times100$.

Hoca bu matrisin adını sordu. Bir öğrenci Hessian dedi, başka biri Hessian'ın birinci, Jacobian'ın ikinci türev olduğunu düşündü. Hoca düzeltti: ikinci türevlerin matrisi Hessian matrisidir.

Formülde bir vektör bir matrise bölünüyor gibi görünür, ama matris bölmesi tanımlı değildir; ancak çarpma yapılabilir. Bu yüzden Hessian'ın tersi alınıp $df$ ile çarpılır:

$$x_{n+1}=x_n-H^{-1}(x_n)\,\nabla f(x_n)$$

Önce Hessian hesaplanır, sonra tersi alınır; matris tersi almak boyut sayısı arttıkça uzun süren bir işlemdir. Bu yüzden Newton-Raphson daha az adımla yakınsar, ama her adımı çok daha uzun sürer.

> **Hocanın vurgusu:** Yöntemleri yalnız iterasyon sayısıyla değerlendirmemek gerekir. Birinde 10 adımla, diğerinde 100 adımla sonuca varılmış olabilir; ama o 100 adımın toplam süresi belki daha kısadır. Arka taraftaki işlemin süresine de bakmak gerekir.

## 13. Sayısal Türev

Üçüncü slayt dosyasında (Section 3) önce türevlerin hesaplanmasına kısaca değinildi. Türev kurallarını kullanmak yerine fonksiyonun kendisini kullanarak yaklaşık türev hesaplanabilir:

$$f'(x)\approx\frac{f(x+\Delta x)-f(x)}{\Delta x}$$

Türev alınamıyorsa ya da alınmak istenmiyorsa böyle yaklaşık işlemler makul olabilir. İleri (forward) fark, geri (backward) fark ve ikisinin ortalaması olan merkezi (central) fark vardır; hoca en iyi çalışanın merkezi fark olduğunu söyledi. Birinci türevler fonksiyonun kendisiyle, ikinci türevler birinci türevlerle hesaplanabildiği için ikinci türevler de sonuçta fonksiyonun kendisiyle hesaplanabilir; daha yüksek dereceler de çıkarılabilir.

## 14. Çok Boyutlu Fonksiyonlar, Gradyan ve Kuadratik Fonksiyonlar

### 14.1 Gradyan

Şimdiye kadarki örneklerde fonksiyonlar tek boyutluydu. Slayttaki iki boyutlu yüzeyde işaretli kırmızı noktada iki türev vardır: $y$ boyutuna göre $\partial f(x,y)/\partial y$ ve $x$ boyutuna göre $\partial f(x,y)/\partial x$ (ekrandan, 02:35:00). Türeve uygun hareket etmek için iki doğrultuyu birleştiren bir yönde gitmek gerekir; ters yöne gidiliyorsa onun tersine. Yani bir yön, uzayın boyut sayısı kadar bileşenden oluşur. Herhangi bir fonksiyonun türevi, her bir boyutuna göre türevlerinden oluşur:

$$\nabla f(x_1,\dots,x_n)=\left(\frac{\partial f}{\partial x_1},\dots,\frac{\partial f}{\partial x_n}\right)^T$$

Genelde sütun vektörü olarak gösterilir; slaytta satırın transpozu yazılmıştır. Gradyan $\mathbb{R}^n$'den $\mathbb{R}^n$'e bir fonksiyondur.

### 14.2 Kuadratik fonksiyonlar

Kuadratik, ikinci dereceden demektir; hoca adın havalı göründüğünü ama ikinci dereceden fonksiyon demek olduğunu söyledi. Bütün kuadratik fonksiyonlar genel olarak şöyle yazılabilir (ekrandan, 02:45:00):

$$f(x)=\tfrac12\,x^T q\,x+b^T x+c$$

Burada $q$ bir matris, $b$ bir vektör, $c$ tek bir sayıdır.

Hoca pozitif tanımlı ve yarı tanımlı matrisleri hatırlatıp sordu; öğrencilerin hatırlamadığını görünce açıkladı: bütün özdeğerleri sıfıra eşit ya da sıfırdan büyük olan matrisler pozitif yarı tanımlı, hepsi sıfırdan büyük olanlar pozitif tanımlıdır. Bunun anlamı (ekrandan, 02:40:00):

- **$q$ pozitif tanımlı:** $f$ yukarı bakan parabolik bir kasedir. Öğrenciler "parabolik" ve "konveks" dedi; hoca asıl ilgilenilen kısmın konvekslik olduğunu söyledi. Bu durumda optimizasyon çok kolaydır; pozitif yarı tanımlı durum da fena değildir.
- **$q$ negatif tanımlı:** $f$ ters dönmüş bir kasedir. Bunda da optimizasyon kolaydır, çünkü fonksiyon kolayca ters çevrilebilir.
- **$q$ belirsiz (indefinite):** Bir özdeğer pozitif, bir özdeğer negatiftir. $f$ eyer (saddle) şeklini alır.

Eyer adı, at eyerine benzemesinden gelir: bir yanda atın başı vardır, binen kişi bacaklarını iki yana uzatır. Bu fonksiyonun kötü tarafı şudur: bir yöne gidince fonksiyon artar, bir yöne gidince azalır; ne tarafa gidileceği net görülemez. Ortada türevi sıfır olan bir nokta vardır, ama o nokta minimum değildir. Türev kullanan bir algoritma o noktaya gelirse oradan çıkamaz, takılır. Önceki örnekte başlangıca göre farklı yerlere varılmasında da böyle türevi sıfır olan bir nokta vardı. Yapay sinir ağlarının uzaylarında çok sayıda eyer noktası olduğu ve algoritmaların genelde böyle yerlere takıldığı söylenir; hoca bunu birinci elden deneyimlemediğini ekledi.

### 14.3 İki boyutlu kuadratik örnek ve Hessian

Slayttaki örnek (ekrandan, 02:45:00), $x=[x_1\ x_2]^T$:

```text
q=[1 0.5; 0.5 2];
b=[-0.5 ;-0.5];
c=0.5;
f(x)=(x1^2)/2+(x1*x2)/2+x2^2- 0.5*x1-0.5*x2+0.5
df/dx1 = x1+x2/2 -0.5
df/dx2 = x1/2+2*x2 -0.5
df=[df/dx1; df/dx2]
df/dx1x2=df/dx2x1=1/2
df/dx1x1=1
df/dx2x2=2
ddf=[df/dx1x1 df/dx1x2 ; df/dx2x1 df/dx2x2 ] = q
```

Gradyan bir vektör, Hessian bir matristir. Hessian simetriktir: önce $x_1$'e sonra $x_2$'ye göre türev almakla önce $x_2$'ye sonra $x_1$'e göre türev almak aynı sonucu verir. Hoca türev sırasının sonucu değiştirip değiştirmediğini sordu; öğrenciler "değişmez" dedi. Köşegende her boyuta göre iki kez türev, köşegen dışında karışık türevler bulunur. Tek değişkenli $3x^2$ gibi bir fonksiyonda iki kez türev alınınca tek bir sayı kalır; iki değişkenli kuadratik fonksiyonda ise $2\times2$'lik bir matris kalır. Kuadratik formdaki $q$, Hessian matrisine denk gelir. (Python kontrolü: $q$'nun özdeğerleri yaklaşık $0.79$ ve $2.21$, ikisi de pozitif; fonksiyon pozitif tanımlı, yani konveks bir kasedir.)

### 14.4 $n$ boyutta güncellemeler

Tek boyutta $x_{new}$, $x_{old}$, $eps$ ve $df$ birer sayıydı. $n$ boyutta $eps$ yine bir katsayıdır, ama $x_{new}$, $x_{old}$ ve $df$ birer $n\times1$ vektördür. Newton-Raphson'da $ddf$ $d\times d$'lik bir matristir; tersi $d\times1$'lik $df$ ile çarpılınca boyutlar uyumlu olur.

Slaytta determinantın geometrik anlamı ve matris tersinin ne demek olduğu da vardı; hoca bunların çok önemli olmadığını söyleyip geçti. İlgi çekici bulduğu kısım, matris tersi alma süresinin matris boyutuyla nasıl arttığını gösteren grafikti: matris büyüdükçe gereken süre hızla yükselir. Hoca bunun yalnız tersi almanın maliyeti olduğunu, Hessian'ın hesaplanması ve bellekte tutulmasının ayrıca pahalı olabileceğini vurguladı.

> **Ders sonrası not:** Hoca süre artışını "eksponansiyel" diye nitelendirdi. Standart yöntemlerle $d\times d$ bir matrisin tersini almanın maliyeti büyük olasılıkla $O(d^3)$ gibi polinom düzeyindedir; yani hızlı artar ama üstel değildir.

## 15. İki Boyutta Optimizasyon Karşılaştırmaları

### 15.1 Konveks kuadratik fonksiyonda

Yukarıdaki kuadratik fonksiyon üzerinde:

- **Gradient descent ($eps=0.1$):** 1, 2, 3 diye düzgün (smooth) biçimde minimuma yaklaştı.
- **Newton-Raphson:** Tek adımda minimuma ulaştı.

Hoca bunun başlangıç noktasının özel bir özelliğinden kaynaklanmadığını söyledi. Hessian matrisiyle işlem yapmak o noktaya ikinci dereceden bir fonksiyon oturtmak demektir; fonksiyonun kendisi de ikinci dereceden ise tam kendisi yakalanır ve minimum tek adımda hesaplanır. Bu, dördüncü dereceden bir fonksiyona dördüncü derece Taylor yaklaşımının tam oturmasıyla aynı fikirdir. (Python kontrolü: bu fonksiyonda tek Newton adımı, başlangıç noktasından bağımsız olarak tam minimum $x^*=-q^{-1}b=(3/7,\ 1/7)$'yi veriyor.)

Ayrıca gradient descent ($eps=0.05$) ile steepest descent iki boyutta karşılaştırıldı (ekrandan, 02:50:00, `steepest_desc_2dim.m`): gradient descent 50 iterasyonda yakınsamadı; steepest descent 12. iterasyonda yakınsadı. Slaytta "Attention to orthogonal updates" yazıyordu: steepest descent'te ardışık yönler birbirine diktir ve yol zikzak biçiminde ilerler.

### 15.2 Konveks olmayan fonksiyonda

Sonraki slayttaki fonksiyon (slayt listesinde "Griewank function") ne konveks ne konkavdır (ekrandan, 02:50:00 karesindeki slayt listesi). Öğrenciler önce "konkav" dedi; hoca konkavın ne demek olduğunu hatırlattı: bu fonksiyon belli bölgelerde konveks, belli bölgelerde konkavdır, tamamen şudur diyemeyiz. Yerel minimumlar olduğu için optimizasyon açısından iyi bir fonksiyon değildir.

- Bir başlangıç noktasından gradient descent 118. adımda bir minimuma vardı; Newton-Raphson aynı yerden 4 adımda vardı.
- Başka bir başlangıç noktasından gradient descent 142. adımda minimuma geldi. Newton-Raphson ise aynı yerden başlatılınca 4.-5. adımda bir yere yakınsadı, ama orası yerel minimum değil, türevin sıfır olduğu bir eyer noktasıydı.

Hoca, gradient descent aynı noktadan eyer noktasına takılmazken Newton-Raphson'ın takılmasının garip olup olmadığını sordu. Bir öğrenci adım büyüklüğüyle ilgili olabileceğini söyledi; hoca Newton-Raphson'da adım büyüklüğü olmadığını hatırlattı. Başka bir öğrenci oraya ikinci dereceden bir fonksiyon oturttuğunu söyledi; hoca bunu onayladı ve Newton-Raphson'ın fonksiyon değerini azaltmak yerine artırdığına dikkat çekti: aşağı inmesi gerekirken yukarıya, bulunduğu yerden daha kötü bir yere gidiyor.

Hoca nedenin slaytlarda anlatıldığını, ama şimdilik öğrencilere bıraktığını söyledi. Temel ders şudur: ikinci dereceden (Hessian kullanan) yöntemler aşırı derecede kararlı değildir; gradient descent çok daha kararlı ve çok daha yavaştır.

### 15.3 Tek boyutlu $\sin x$ örneği

Son olarak $f(x)=\sin x$ üzerinde (mavi $f$, kırmızı $f'$, yeşil $f''$) Newton-Raphson'ın davranışı gösterildi (`newton_raphson_2.m`). Bir başlangıç noktasından istenen minimuma varılırken başka bir başlangıç noktasından istenmeyen bir noktaya yakınsandı. <!-- BELİRSİZ: Altyazıda iki başlangıç noktası da "0.5" diye geçiyor (02:53:59); büyük olasılıkla biri -0.5, diğeri 0.5'tir, ama karede başlangıç değerleri okunamadı. --> Gradient descent'te ($eps=0.05$, yalnız $f'$ kullanılır, $f''$ kullanılmaz) böyle bir sorun olmaz; iki başlangıçtan da aşağı, minimuma iner (ekrandan, 02:55:00).

> **Ek bilgi (derste anlatılmadı):** İkinci derece Newton-Raphson, $f'(x)=0$ denkleminin kökünü arar ve kökün minimum, maksimum ya da eyer noktası olmasını ayırt etmez. $f''(x)<0$ olan bir bölgede (fonksiyonun konkav olduğu yerde) Newton adımı fonksiyonu artıran yöne gider ve algoritma bir maksimuma ya da eyer noktasına yakınsayabilir. Çok boyutta bu durum Hessian'ın pozitif tanımlı olmadığı bölgelerde ortaya çıkar.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00 karesindeki slayt listesi; derste sözlü, 00:06:15): $L$ metre çitle çevrilebilecek en büyük dikdörtgen alan nedir?

**Çözüm (derste verildi):** Kenarlar $x$ ve $L/2-x$, alan $f(x)=x(L/2-x)$. $f'(x)=L/2-2x=0\Rightarrow x=L/4$. Diğer kenar da $L/4$'tür; en büyük alan $L^2/16$ ile karede elde edilir.

**Soru 2** (derste sözlü, 00:15:27): $t x_1+(1-t)x_2$ ifadesi $t=1$, $t=0$ ve $t=0.5$ için hangi noktayı verir?

**Çözüm (derste verildi):** Sırasıyla $x_1$, $x_2$ ve orta nokta $(x_1+x_2)/2$.

**Soru 3** (ekrandan, 00:20:00): Aşağıdaki fonksiyonlar konveks midir? (a) $f(x_1)=3x_1+3$, (b) $f(x_1,x_2)=a x_1+b x_2+c$, (c) $f(x_1,x_2)=x_2^2+x_1^2+3x_1$, (d) $\sin x$ hangi aralıkta konvekstir? (e) Konkav mıdır?

**Çözüm:** (a) ve (b) derste verildi: afin fonksiyonlar (doğru ve düzlem) konvekstir. (c) için derste öğrencinin cevabı "konveks" idi ve hoca araştırılmasını istedi.

> **Çözüm (derste verilmedi):** (c) Hessian $\begin{bmatrix}2&0\\0&2\end{bmatrix}$'dir, özdeğerleri pozitiftir; fonksiyon konvekstir (minimumu $(-1.5,\ 0)$'dadır). (d) $(\sin x)''=-\sin x\ge0$ koşulu $\sin x\le0$ demektir; $\sin x$, $[\pi,2\pi]$ aralığında (ve $2\pi$'nin katlarıyla ötelenmişlerinde, örneğin $[-\pi,0]$) konvekstir. (e) Bütün tanım kümesinde konkav değildir; yalnız $\sin x\ge0$ olan $[0,\pi]$ gibi aralıklarda konkavdır.

**Soru 4** (derste sözlü, 00:36:47): $f(x)=x^2$ için yalnız türevin işaretini kullanan gradient descent $-4.9$ (yaklaşık $-5$) civarından $0.05$'lik sabit adımla başlarsa minimum yakınına yaklaşık kaç adımda varır? Neden precision koşuluyla duramaz?

**Çözüm (derste verildi):** Yaklaşık 5 birimlik mesafe $0.05$'lik adımlarla yaklaşık 100 adımda kapanır. Ardışık iki $x$ arasındaki fark her zaman $0.05$ olduğu için precision ($10^{-5}$) koşulu hiç sağlanmaz; döngü yalnız 200 iterasyon sınırıyla biter.

**Soru 5** (ekrandan, 00:45:00): `gradient_desc_2.m` ile $f(x)=x^2$'de adım büyüklüğü 1 yapılırsa ne olur?

**Çözüm (derste verildi):** 200 iterasyon sınırına ulaşılır ve yöntem yakınsamaz; $x$ zikzak yaparak optimumdan uzaklaşır (slayttaki grafikte $10^{16}$ ölçeğine çıkılıyor).

> **Ders sonrası not:** Kapalı biçimde $x\leftarrow(1-2\,eps)x$ olduğundan $eps=1$ için $x$ büyük olasılıkla yalnız işaret değiştirir (sabit genlik); büyüme $eps>1$ için beklenir. Her iki durumda da yöntem yakınsamaz.

**Soru 6** (ekrandan, 00:50:00): $f(x)=x^4-3x^3+2$ için başlangıç noktası önemli midir?

**Çözüm (derste verildi):** $f'(x)=4x^3-9x^2$ sıfırları $x=0$ ve $x=9/4$'tür. Soldan küçük adımla başlanınca gradient descent $x=0$'daki düzlükte takılır; $3.5$'ten başlanınca $9/4$'e yakınsar. Başlangıç noktası sonucu etkilediği için fonksiyon konveks değildir.

**Soru 7** (ekrandan, 01:55:00): $(1.0002)^{50}$'yi lineer yaklaşımla hesaplayın.

**Çözüm (derste verildi):** $f(x)=x^{50}$, $x=1$, $\Delta x=0.0002$: $f(1.0002)\approx1+0.0002\cdot50\cdot1^{49}=1.01$. (Python ile gerçek değer $1.0100491\ldots$.)

**Soru 8** (derste sözlü, 02:18:03): İkinci dereceden türevlerin değerlerini gösteren matrisin adı nedir?

**Çözüm (derste verildi):** Hessian matrisi.

**Soru 9** (derste sözlü, 02:52:05; ekrandan, 02:55:00 karesindeki slayt listesi): Aynı başlangıç noktasından gradient descent minimuma giderken Newton-Raphson neden eyer noktasına takılır?

> **Çözüm (derste verilmedi):** İkinci derece Newton-Raphson $f'(x)=0$ (çok boyutta $\nabla f=0$) denklemini çözer ve bulduğu durağan noktanın türünü ayırt etmez. Bulunulan bölgede Hessian pozitif tanımlı değilse oturtulan ikinci dereceden model bir kase değil, eyer ya da ters kase olur ve Newton adımı bu modelin durağan noktasına, yani fonksiyon değerini artıran yöne gider. Gradient descent ise her zaman gradyanın tersine, fonksiyonun azaldığı yöne adım attığı için eyer noktasından uzaklaşabilir.

## Dersin Toparlaması

Bu derste optimizasyonun temel kavramları kuruldu: amaç fonksiyonu, kısıtlar ve optimal çözüm; lineer, afin ve konveks fonksiyonlar; iteratif optimizasyonun "yön ve adım büyüklüğü" mantığı. Gradient descent önce yalnız türevin işaretiyle, sonra türevin büyüklüğüyle anlatıldı. Adım büyüklüğünün (öğrenme oranının) fonksiyona bağlı olduğu ve küçükken yavaşlığa, büyükken zikzağa ya da ıraksamaya yol açtığı görüldü. Konveks fonksiyonlarda başlangıç noktasının sonucu değiştirmediği ve bulunan minimumun global olduğu, konveks olmayan fonksiyonlarda ise algoritmanın düzlüklere, eyer noktalarına ya da yerel minimumlara takılabildiği vurgulandı.

Ardından adım büyüklüğünü kendisi hesaplayan steepest descent, Taylor yaklaşımı ve buna dayanan Newton-Raphson yöntemi anlatıldı. Newton-Raphson ikinci türev (Hessian) kullandığı için az iterasyonla, kuadratik fonksiyonlarda tek adımda yakınsar; ama Hessian'ın hesaplanması ve tersinin alınması pahalıdır ve yöntem kararsızdır, eyer noktalarına yakınsayabilir. Hoca, Newton-Raphson'ın neden bu sorunları yaşadığına bir sonraki derste tekrar dönebileceğini ve bu temel kavramların sonraki derslerin üzerine kurulacağını söyledi; kavramları oturtmak için slaytlardaki MATLAB kodlarını incelemeyi önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
