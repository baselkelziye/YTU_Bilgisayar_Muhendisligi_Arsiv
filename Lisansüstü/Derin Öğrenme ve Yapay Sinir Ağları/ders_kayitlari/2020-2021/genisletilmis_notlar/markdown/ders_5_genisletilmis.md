# Ders 5 Genişletilmiş Notu: Gradyan Düşüm Algoritması: Durma Kriterleri ve En Dik Düşüm Örneği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tek Katmanlı Perceptron Uygulamasına Dair Notlar
- 2. Düşüm Algoritmalarının Genel Yapısı
- 3. Durma Kriterleri
- 4. Durma Kriterlerinin Türev ile İlişkisi
- 5. Gradyan ve Hessian ile Yakınsama Kriterleri
- 6. Düşüm Yönü ve En Dik Düşüm
- 7. Gradyan Düşüm Algoritmasının Adımları
- 8. Sayısal Örnek: En Dik Gradyan Düşüm
- 9. Adım Miktarı ve Öğrenme Oranı
- Örnek Sorular

## 1. Tek Katmanlı Perceptron Uygulamasına Dair Notlar

Dersin başında öğrenciler tek katmanlı perceptron (single layer perceptron) yapısını kurdukları uygulama hakkında sorular sordu. Hoca, Keras ya da TensorFlow gibi kütüphanelerin kullanılabileceğini, Keras ile işin daha kolay olacağını, programlama alışkanlığı az olanların MATLAB benzeri bir ortam da kullanabileceğini söyledi. Ancak hazır kütüphaneler yalnız temel işlemler (matris çarpımı gibi) için kullanılmalı, öğrenme algoritması elle yazılmalıdır.

Kodun mümkün olduğunca jenerik ve parametrik yazılması istendi: değişkenler tanımlanmalı, sonradan değişiklik yapılabilmelidir. Bunun nedeni, aynı uygulamanın üzerine ileride geri yayılım (backpropagation) algoritmasının eklenecek olmasıdır; her şeyi yeniden yazmak zorunda kalınmamalıdır.

Bipolar ve binary girdilerle ayrı denemeler yapılması da konuşuldu. Hoca, iki veri gösterimi arasında sonuçlarda bir fark olup olmadığının, hangisinin daha çabuk eğitildiğinin ya da birinin hiç başarılı olamayıp olamadığının karşılaştırılmasını istedi. İki gösterim aynı kod içinde seçilebilir biçimde tutulabilir.

## 2. Düşüm Algoritmalarının Genel Yapısı

Hoca, geçen haftayı kısaca tekrarlayıp gradyan düşüm algoritmasının neye benzediğini bir örnek üzerinden göstereceğini söyledi. Gradyan düşüm mantığı daha sonra geri yayılımda da kullanılacaktır. Buradaki örnek, yapay sinir ağındaki kullanıma göre daha basittir, çünkü daha az değişken ve daha düşük boyutlu bir problemdir; ama mantığı anlamak ve gradyanın nasıl hesaplandığını görmek için önemlidir.

Düşüm algoritmaları, hatayı minimize etmek için optimizasyon ve arama algoritmalarında genel olarak kullanılan yöntemlerdir. Maksimizasyon için de kullanılabilirler: tersini uyguladığımızda fonksiyonun bir maksimum noktasını buluruz. Ancak derste hedef, bir ağın sonunda oluşan hatayı küçültmek olduğu için anlatım minimizasyon üzerinden yürür.

Elimizde bir hata fonksiyonu (ya da genel olarak bir fonksiyon) ve bilinmeyen katsayılar vardır. Bu katsayılarla ilgili hiçbir fikrimiz yoksa fonksiyonun minimumunun nerede olacağını gözle ayırt edemeyiz. Bu yüzden fonksiyonun tanımlı olduğu uzaydan rastgele bir $x_0$ noktasıyla başlarız.

> **Hocanın vurgusu:** $x_0$ aslında bulmaya çalıştığımız bütün parametreleri içeren vektörel bir değişkendir. Artık hep çok boyutlu şeylerden bahsediyoruz; değişkenlerimiz vektörel değişkenlerdir.

İlk seçilen noktanın fonksiyonu minimum yapan nokta olması ihtimali neredeyse yoktur. Bu, türev alınarak bazı kontrol koşullarıyla denetlenir. Nokta istenen bir yerel minimuma işaret etmiyorsa yeni bir nokta seçilir; ama artık rastgele değil. Gradyanın tersinin, yani birinci türevin tersi yönünün fonksiyonun değerini küçülten bir yön gösterdiği biliniyor. Böylece bir düşüm yönü belirlenir, o yönde yeni noktanın ne kadar uzakta olacağına (adım miktarına) karar verilir, yeni nokta için yine türev hesaplanır ve güncelleme yapılır. Yeni noktanın minimum olup olmadığı durma koşullarıyla kontrol edilir. Bu döngü en azından bir yerel minimum bulunana kadar ya da belirlenen epoch sayısına ulaşılana kadar sürer.

Slayttaki genel şema şöyledir (ekrandan, 00:05:00):

```text
Tahmini bir nokta ile (x0) başla
Repeat
    düşüm yönü belirle
    adım belirle
    update et
Until (durma kriteri sağlanana kadar)
```

Epoch sayısı bir tedbir olarak konur. Belki minimizasyon için tamamen yanlış bir yöntem seçilmiştir ve algoritma sonuca ulaşmayacaktır; ya da hesaplama süresiyle ilgili bir kısıt vardır. Algoritmanın sonsuz döngüye girmemesi için en çok iterasyon sayısı da bir durma koşulu olarak eklenir. Gradyan düşüm ve diğer yöntemlerin hepsinde mantık aynıdır: bir noktayla başla, gideceğin yönü belirle, o yönde yeni noktanı ne kadar uzakta seçeceğini belirle ve durma kriterlerini kontrol et.

## 3. Durma Kriterleri

Slaytta durma kriterleri şöyle verildi (ekrandan, 00:15:00). İdealde:

- Hatanın yeterince küçük olması: $\|e_k\| < \delta_1$.
- $f(x)$'in o anki değerinin minimuma çok yakın olması: $f(x_k) - f(x^*) < \delta_2$. Ancak $x^*$ ve $f(x^*)$ bilinmediğine göre bu pratikte kullanılamaz.

Bunun yerine yaklaşık değer kullanmak gerekir:

$$\|x_{k+1} - x_k\| < \epsilon_1 \quad \text{veya} \quad f(x_k) - f(x_{k+1}) < \epsilon_2$$

Bu koşulların küçük $\epsilon_1$ ve $\epsilon_2$ değerleri için sağlanması, $\|e_k\|$ ya da $f(x_k) - f(x^*)$ değerinin kesin küçük olduğu anlamına gelmez.

Hata için bir sınır belirlemek mümkündür: probleme göre örneğin yüzde 10 hata yeterli görülüyorsa hata hesaplanır ve bu değerin altında kalıp kalmadığına bakılır. Her adımda hata hesaplanırsa, adımlar arasında hatanın nasıl değiştiğine bakarak algoritmanın doğrusal mı, süperlineer mi yoksa kuadratik mi yakınsadığı da tespit edilebilir; yakınsama kavramı buradan çıkmıştı.

İkinci kriter, boşuna iterasyon çalıştırılıp çalıştırılmadığını anlamaya yarar. Fonksiyonun değeri fazla değişmiyorsa belki durağan bir düzlüğe gelinmiştir. $f(x_k) - f(x^*)$ ifadesinde $x^*$ gerçekte bilinmez, ama o anki nokta aday bir minimum gibi düşünülerek hesaplanabilir. Fark çok küçük bir $\delta_2$ değerinin altında kalıyor ve belli bir iterasyon boyunca böyle sürüyorsa, yani aynı düzlükte dolaşılıyormuş gibi görünüyorsa algoritma durdurulabilir. Hoca bunun pratikte çok kullanılmadığını, çünkü minimumla ilgisi olmayan bir düzlüğe girilmiş olabileceğini, yalnız buna bakarak karar vermenin doğru olmadığını söyledi.

Bu kriterlerin birkaçı bir arada uygulanabilir. $\epsilon$ değerleri birbirinden farklı da olabilir, aynı da olabilir; tamamen uygulamaya bağlı olarak seçilir. Kısacası durma koşulu olarak kullanılan büyüklükler şunlardır: noktalar arasındaki fark, fonksiyon değerleri arasındaki fark ve hata miktarı.

## 4. Durma Kriterlerinin Türev ile İlişkisi

Hoca, geçen hafta anlatılan türev tanımını hatırlattı (ekrandan, 00:15:00):

$$f'(x) = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$$

> **Ders sonrası not:** Slaytta limit altında $\Delta x \to 0$, paydada $n$ yazıyordu (ekrandan, 00:15:00). Payla tutarlı biçimi $h \to 0$ ve paydada $h$ olandır; yukarıda bu biçim kullanıldı.

Türev başka biçimlerde de tanımlanabilir. Bir derleyici ya da hazır kütüphane kullanırken bu formüllerin uygulandığının farkına varılmaz, ama kod elle yazılırken daha iyi türev tanımlarına ihtiyaç olabilir. Taylor serisi açıldığında da $f'(x)$ benzer bir farkla yazılabilir.

Durma koşuluyla bağlantı şudur: $f(x+h)$ ile $f(x)$ arasındaki fark çok küçüldüğünde türev sıfıra yaklaşır. İkinci durma koşulundaki $f(x_k) - f(x_{k+1})$ farkını türev formülünün payı gibi düşünmek gerekir. Bu fark küçülüyorsa türev sıfıra gidiyor, yani bir minimuma yaklaşılıyor demektir. Fark sıfır olursa minimuma ulaşılmıştır; sıfır olmasa bile çok küçüldüyse minimuma yaklaşıldığı bilinir ve daha fazla iterasyon çalıştırmadan durma kararı verilebilir. Bu kriterin bir durma koşulu olarak kullanılmasının matematiksel gerekçesi budur.

## 5. Gradyan ve Hessian ile Yakınsama Kriterleri

Diğer tip yakınsama kriteri doğrudan türeve bakar (ekrandan, 00:20:00):

$$\|f'(x_k)\| < \epsilon_3$$

Bu, türevin sıfıra yaklaşmasını temsil eder ve pek çok düşüm yönteminin gerçeklenmesinde kullanılır. Bunun için türev hesaplamak gerekir.

Daha iyisi Hessian matrisine bakmaktır. Fonksiyonun Taylor açılımı yazıldığında ikinci terimdeki ikinci türev, kısmi türevlerden oluşuyorsa Hessian matrisi adını alır. Hessian'ın pozitif ya da negatif olması bir minimumda mı yoksa maksimumda mı olunduğunu söyler. Slayttaki ifadeler şöyledir (ekrandan, 00:20:00). $x^*$ noktasında $f$ fonksiyonunun Taylor açılımı:

$$f(x_k) \cong f(x^*) + (x_k - x^*)^T f'(x^*) + \frac{1}{2}(x_k - x^*)^T f''(x^*)(x_k - x^*)$$

$$f'(x^*) = 0, \qquad H^* \equiv f''(x^*) \ \text{kesin/yarı kesin pozitif}$$

> **Ders sonrası not:** Slaytta ikinci terim $(x_k - x^*)^T$ olarak, $f'(x^*)$ çarpanı olmadan yazılmıştı (ekrandan, 00:20:00). Taylor açılımında bu terim $(x_k - x^*)^T f'(x^*)$ olmalıdır; minimumda $f'(x^*) = 0$ olduğu için terim zaten sıfırlanır ve aşağıdaki durma koşulu değişmez.

Buradan durma koşulu:

$$f(x_k) - f(x^*) \cong \frac{1}{2}(x_k - x^*)^T H^* (x_k - x^*) < \epsilon_4, \qquad x_k \cong x^*$$

$x^*$ bilinmediği için burada $x_k - x^*$ yerine yaklaşık olarak $x_{k+1} - x_k$, $H^*$ yerine de $H_k = f''(x_k)$ kullanılır.

İkinci türev alma lüksü varsa ve hesaplama yükü fazla gelmiyorsa Hessian'a göre karar verilebilir. Gradyan düşüm algoritması yalnız birinci türeve bakar; Newton algoritması gibi ikinci türeve de bakan yöntemler vardır.

## 6. Düşüm Yönü ve En Dik Düşüm

Hangi yönde gidileceğine Taylor açılımından yararlanarak karar verilmişti. Yalnız ilk terimler tutulup diğerleri ihmal edildiğinde

$$f(x + \alpha h) \approx f(x) + \alpha h^T f'(x)$$

yazılır. İstenen, fonksiyonun değerinin küçülmesi olduğuna göre ikinci terimin, $\alpha h^T f'(x)$'in negatif olması gerekir. Bu da türevin tersi yönünde gidilirse $f(x)$'i küçültecek bir yöne gidileceği anlamına gelir. Türevin pozitif olduğu yön fonksiyonun büyüdüğü, arttığı yönü gösterir, yani maksimuma götürür. Türevin negatif olduğu yön fonksiyonun azaldığı yönü gösterir. Minimuma gitmek istediğimize göre her zaman gradyanın negatifi yönünde gitmek bizi minimuma yaklaştırır; gradyan düşüm yöntemi bu mantıkla oluşmuştur ve Taylor serisi bunun bir tür matematiksel ispatıdır.

> **Hocanın vurgusu:** Gradyan düşüm yöntemi bir minimum varsa, yerel bir minimum bile olsa, eninde sonunda oraya ulaştıran, bir nevi garantili bir yöntemdir. Dezavantajı oraya giderken yavaş ilerlemesi, adım miktarlarını küçük seçmesidir. Bu yüzden çok yaygın kullanılır.

Slayttaki tanımlar şunlardır (ekrandan, 00:25:00):

- $-f'(x)$ vektörü düşüm uzayını gösteren bir vektördür.
- Bu uzayda $h$, $x$'ten bir düşüm yönüdür $\Leftrightarrow h^T f'(x) < 0$.
- $h$ ile $-f'(x)$ arasındaki açı $\theta = \angle(h, -f'(x))$ ve

$$\cos\theta = \frac{-h^T f'(x)}{\|h\|\,\|f'(x)\|}$$

- Mutlak düşüm yöntemi, $\theta < \frac{\pi}{2} - \mu$ koşulunu tüm $k$ değerleri ve $\mu > 0$ ($k$'dan bağımsız) olmak üzere sağlayan $h_k$ arama yönlerine sahiptir.
- Global yakınsama için $\mu$ tüm adımlar için sabit olmalıdır.

Böylece $-f'(x)$, yani eksi gradyan yönü bir arama yönü olur. Mutlak düşüm, her $k$ için arama yönü ile eksi gradyan arasındaki açının küçük tutulduğu bir yön seçmek demektir; bunun için açının kosinüsüne bakılır. $\mu$ bütün adımlar için, ya da belli bir noktadan sonraki her adım için sabit kalıyorsa global yakınsamadan söz edilebilir.

Hoca bunun bir çıkarım olduğunu, algoritmanın normalde böyle bir kontrol yapmayacağını belirtti. Algoritmanın çalışma mantığı yerel de olsa bir minimum bulmaktır. Global minimuma ulaşılıp ulaşılmayacağı tamamen başlangıçta rastgele seçilen noktayla ilgilidir. Yerel minimumlar pas geçilip algoritma çalıştırılmaya devam edilirse bir gün global minimum bulunur; ama genelde o kadar uzun çalıştırmaya değmediği için yerel minimumla yetinilir.

## 7. Gradyan Düşüm Algoritmasının Adımları

Algoritma şu sırayla işler:

1. Rastgele bir $x_0$ noktasından aramayı başlat. Gradyanı genel (değişkenli) olarak yaz. İterasyon sayacı $k$ ve en çok iterasyon (epoch) sayısı $M$ belirle.
2. $x_0$ noktasında gradyanın değerini hesapla. Gradyanın normunun bir $\epsilon$ değerinden küçük olup olmadığını kontrol et; belki kazara minimuma yakın bir yerden başlanmıştır. En çok iterasyona ulaşılıp ulaşılmadığına bak.
3. Koşullar sağlanmıyorsa $x_0$ işimizi görecek bir minimum değildir. Bir $d_0$ yönünde ve $t_0$ adım uzaklığında yeni $x_1$ noktasını hesapla.
4. Artık iki nokta olduğundan $\|x_1 - x_0\|$ normunun ve iki noktadaki fonksiyon değerlerinin farkının $\epsilon$'dan küçük olup olmadığına bak.
5. Sağlanmıyorsa $x_1$ için gradyanı hesapla, normunu kontrol et. Hâlâ sağlanmıyorsa ve en çok iterasyona ulaşılmadıysa yeni arama yönü, yeni adım miktarı ve $x_2$ noktasını hesapla; durma koşulları sağlanana kadar böyle devam et.

İlk adımda tek nokta olduğu için durma koşulları daha kısıtlıdır: yalnız gradyanın değeri ve en çok iterasyon kontrol edilebilir. Sonraki adımlarda bunlara noktalar arasındaki fark ve fonksiyon değerleri arasındaki fark eklenir.

Arama yönü ve adım miktarı için kullanılan denklem de Taylor serisinden gelir. Gradyanın tersi yönünde $t_k$ kadar gidildiğinde daha küçük bir değere ulaşılmalıdır; yani $x_k$ ile $t_k$ adım ötesindeki nokta arasındaki fonksiyon değeri farkı küçülmelidir. Yeni nokta $t_k$ adım ötede bir $d$ arama yönünde seçilir:

$$x^{k+1} = x^k + t_k d^k$$

Hoca, arama yönünün daha çok işaret, yani $x_k$'dan eksiltme mi artırma mı yapılacağını, $t_k$'nın ise mesafeyi sağladığını anlattı; $d$'nin değeri de bir çarpan olarak etki eder.

## 8. Sayısal Örnek: En Dik Gradyan Düşüm

### 8.1 Problemin tanımı

Örnek fonksiyon bir hata fonksiyonu gibi düşünülmelidir. Değişken iki bileşenlidir ($x_1$, $x_2$). Slayttaki tanım (ekrandan, 00:30:00):

$$f(x) = 2x_1^2 + x_1x_2 + x_2^2$$

fonksiyonunun minimumu aranıyor.

- Başlangıç değeri: $x^0 = \begin{bmatrix} 0{,}5 \\ 1 \end{bmatrix}$.
- Gradyanın normu için $\|\nabla\| < \epsilon_1$, $\epsilon_1 = 0{,}1$.
- $\|x^{k+1} - x^k\|$ ve $|f(x^{k+1}) - f(x^k)|$ kontrolü için $\epsilon_2 = 0{,}15$.
- En çok iterasyon sayısı $M = 10$.

> **Ders sonrası not:** Sonraki slaytta en çok iterasyon sayısı $\mu = 10$ olarak yazılmıştı (ekrandan, 00:35:00); bu, önceki slayttaki $M = 10$ ile aynı büyüklüktür ve büyük olasılıkla bir yazım farkıdır. Mutlak düşüm koşulundaki $\mu$ ile karıştırılmamalıdır.

### 8.2 Gradyan ve normu

İki bileşen olduğu için gradyan $\left[\frac{\partial f}{\partial x_1};\ \frac{\partial f}{\partial x_2}\right]$ biçiminde iki bileşenli bir vektördür. Norm, bileşenlerin kareleri toplamının kareköküdür: bir $x$ vektörü için $\sqrt{x_1^2 + x_2^2}$, gradyan için

$$\|\nabla f\| = \sqrt{\left(\frac{\partial f}{\partial x_1}\right)^2 + \left(\frac{\partial f}{\partial x_2}\right)^2}$$

Türevler: $x_1$'e göre türevde $2x_1^2$ teriminden $4x_1$, $x_1x_2$ teriminden $x_2$ gelir; $x_2^2$ teriminde $x_1$ olmadığı için türevi sıfırdır. $x_2$'ye göre türev $x_1 + 2x_2$'dir (ekrandan, 00:35:00):

$$\nabla f(x) = \begin{bmatrix} 4x_1 + x_2 \\ x_1 + 2x_2 \end{bmatrix}$$

Hoca anlatırken önce $x_1$'e göre türevi "$4x_1 + 1$" dedi, sonra kendisi düzelterek $4x_1 + x_2$ olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu fonksiyonun Hessian matrisi sabittir: $H = \begin{bmatrix} 4 & 1 \\ 1 & 2 \end{bmatrix}$. Özdeğerleri pozitif olduğu için kesin pozitiftir ve fonksiyonun tek minimumu $x^* = [0;\ 0]^T$ noktasındadır. Kuadratik bir fonksiyonda tam doğru araması (exact line search) adımı $t_k = \dfrac{\nabla f^T \nabla f}{\nabla f^T H \nabla f}$ formülüyle de bulunabilir.

### 8.3 İlk iterasyon

Gradyanın formülü oluştuktan sonra sayaç $k = 0$ olarak ayarlanır ve rastgele seçilen $x^0$ noktasında gradyan hesaplanır (ekrandan, 00:35:00). $x_1 = 0{,}5$, $x_2 = 1$ konursa:

$$\nabla f(x^0) = \begin{bmatrix} 4(0{,}5) + 1 \\ 0{,}5 + 2(1) \end{bmatrix} = \begin{bmatrix} 3 \\ 2{,}5 \end{bmatrix}$$

Gradyanın normu (ara adım eklendi):

$$\|\nabla f(x^0)\| = \sqrt{3^2 + 2{,}5^2} = \sqrt{15{,}25} \approx 3{,}905$$

> **Ders sonrası not:** Hoca norm hesabını anlatırken gradyanın ikinci bileşenini bir yerde "üç" dedi. Slayttaki değer $2{,}5$'tir ve hesap yukarıdaki gibidir.

Bu değer $\epsilon_1 = 0{,}1$'den büyük olduğu için koşul sağlanmaz. $k = 0 < M$ olduğu için en çok iterasyona da ulaşılmamıştır. Algoritma sürer ve gradyanın tersi yönünde bir arama yönü seçilir:

$$d^0 = -\nabla f(x^0) = \begin{bmatrix} -3 \\ -2{,}5 \end{bmatrix}$$

Hoca bunun bir vektör olmasının şaşırtıcı olmadığını, yön zaten vektörel bir şey olduğu için bunun gerektiğini söyledi.

### 8.4 Adım uzunluğunun bulunması

Adım uzunluğu için bir $\ell$ fonksiyonu kurulur (ekrandan, 00:40:00):

$$\ell(t_k) = f\left(x^k - t_k \nabla f(x^k)\right)$$

Burada $x^k = x^0$, $t_k = t_0$ ve $\nabla f(x^k) = \nabla f(x^0)$ alınır. Esas soru, $f$'e $x_1$ ve $x_2$ olarak ne konacağıdır: bir önceki noktanın her bileşeninden, adım miktarı çarpı gradyanın o bileşeni çıkarılır:

$$x_1 = 0{,}5 - 3t_0, \qquad x_2 = 1 - 2{,}5t_0$$

Bunlar orijinal $f(x) = 2x_1^2 + x_1x_2 + x_2^2$ fonksiyonuna konur:

$$\ell(t_0) = 2(0{,}5 - 3t_0)^2 + (0{,}5 - 3t_0)(1 - 2{,}5t_0) + (1 - 2{,}5t_0)^2$$

$\ell$ fonksiyonunu minimize eden $t$ değeri adım miktarı olacaktır: yeni nokta, fonksiyonu mümkün olduğunca küçülten uzaklıkta seçilir. Tek değişken olduğu için $\ell$'nin adi türevi sıfıra eşitlenir; bu tek bilinmeyenli denklem $t_0$'ı verir:

$$\frac{d\ell(t_0)}{dt_0} = -15{,}25 + 63{,}25\,t_0 = 0 \ \Rightarrow\ t_0^* = 0{,}24$$

> **Ders sonrası not:** Slayttaki türev ifadesi yukarıdaki gibiydi (ekrandan, 00:40:00). Python ile açılım yapıldığında $\ell(t_0) = 2 - 15{,}25\,t_0 + 31{,}75\,t_0^2$, dolayısıyla $\frac{d\ell}{dt_0} = -15{,}25 + 63{,}5\,t_0$ ve $t_0^* = 15{,}25 / 63{,}5 \approx 0{,}2402$ çıkar. Yuvarlanmış sonuç $0{,}24$ değişmez.

### 8.5 Yeni nokta ve durma koşulları

Yeni nokta, bulunulan nokta artı adım miktarı çarpı arama yönüdür:

$$x^1 = x^0 + t_0^* d^0 = \begin{bmatrix} 0{,}5 \\ 1 \end{bmatrix} + 0{,}24 \begin{bmatrix} -3 \\ -2{,}5 \end{bmatrix} = \begin{bmatrix} 0{,}5 - 0{,}72 \\ 1 - 0{,}6 \end{bmatrix} = \begin{bmatrix} -0{,}22 \\ 0{,}4 \end{bmatrix}$$

Hoca bu sırada slaytta bir işaret hatası gördü ve arama yönü gradyanın tersi seçildiği için "kesinlikle burada bir eksi olacak" dedi. $x^0 + t_0 d^0$ ile $d^0 = -\nabla f(x^0)$ birlikte kullanıldığında yukarıdaki sonuç çıkar. <!-- BELİRSİZ: 00:42:07 civarında hocanın düzelttiği slayt satırı karelerde görünmüyor; eksi işaretinin hangi ifadede eksik olduğu doğrulanamadı. --> Hoca sonucu sözlü olarak "0,22; 0,4" diye okudu; ilk bileşen $-0{,}22$'dir (yukarıdaki işlem).

Ardından iki nokta arasındaki mesafenin normu hesaplanır; noktalar birbirine çok yaklaşıyorsa bu minimuma yaklaşıldığının işaretidir. Fark vektörü $x^1 - x^0 = [-0{,}72;\ -0{,}6]^T$'dir ve (ara adım eklendi)

$$\|x^1 - x^0\| = \sqrt{0{,}72^2 + 0{,}6^2} \approx 0{,}937 > 0{,}15 = \epsilon_2$$

Noktalar henüz istenen kadar yakın değildir, birkaç iterasyon daha gitmek gerekir. Fonksiyon değerleri açısından da (ara adım eklendi) $f(x^0) = 2$, $f(x^1) \approx 0{,}169$ ve fark $0{,}15$'ten büyüktür; bu durma koşulu da sağlanmaz.

### 8.6 İkinci iterasyon

Algoritma $x^1$ ile devam eder: gradyan hesaplanır, normunun durma koşulunu sağlayıp sağlamadığına ve iterasyon sınırına bakılır; ikisi de sağlanmaz. Yeni arama yönü gradyanın tersi seçilir, $\ell$ fonksiyonunun türevi sıfıra eşitlenerek yeni adım miktarı bulunur ve yeni nokta seçilir. Gradyan (ara adım eklendi):

$$\nabla f(x^1) = \begin{bmatrix} 4(-0{,}22) + 0{,}4 \\ -0{,}22 + 2(0{,}4) \end{bmatrix} = \begin{bmatrix} -0{,}48 \\ 0{,}58 \end{bmatrix}, \qquad \|\nabla f(x^1)\| \approx 0{,}753 > 0{,}1$$

Slayttaki son adımlar (ekrandan, 00:45:00):

- 17. $d^1 = \begin{bmatrix} 0{,}48 \\ -0{,}58 \end{bmatrix}$ ve $t_1^* = 0{,}546$ değerlerini kullanarak bir sonraki noktayı belirleyelim:

$$x^2 = x^1 + t_1^* d^1 = \begin{bmatrix} -0{,}22 \\ 0{,}4 \end{bmatrix} + 0{,}546 \begin{bmatrix} 0{,}48 \\ -0{,}58 \end{bmatrix} = \begin{bmatrix} 0{,}04 \\ 0{,}08 \end{bmatrix}$$

- 18. Durma koşullarını kontrol et: $\|x^2 - x^1\| = 0{,}41 > 0{,}15 = \epsilon_2$ ve $|f(x^2) - f(x^1)| = 0{,}156 > 0{,}15 = \epsilon_2$.
- 19. Koşullar sağlanmadı, sonraki iterasyona geçelim: $k = k + 1 = 2$.

Bu değerler python ile kontrol edildi: $x^1 + 0{,}546\,d^1 \approx [0{,}042;\ 0{,}083]^T$, $\|x^2 - x^1\| \approx 0{,}411$, $|f(x^2) - f(x^1)| \approx 0{,}155$. Tam doğru aramasıyla $t_1^* \approx 0{,}5446$ çıkar; slayttaki $0{,}546$ yuvarlanmış değerdir.

İterasyonlar, belirlenen $\epsilon$ değerlerinin altına düşülene kadar bu şekilde sürer.

## 9. Adım Miktarı ve Öğrenme Oranı

**Soru:** Adım miktarı ile öğrenme oranı (learning rate) aynı şey mi?

**Cevap:** Çıkış noktaları bakımından birebir aynı değiller ama aynı amaca hizmet ediyorlar: ikisi de ne kadar uzağa gidileceğini söyler. Öğrenme oranı çoğunlukla sabit kullanılır; örneğin $0{,}1$ seçildiyse her adımda o kadar gidilir. Burada hesaplanan adım miktarı ise her iterasyonda farklı çıkar, bazen yavaşlayan bazen hızlanan bir büyüklüktür. Öğrenme oranının çıkış noktası burasıdır: adım miktarını her seferinde $\ell$ fonksiyonunu minimize ederek hesaplamak işlem gerektirdiği için sabit bir adım almak, yani öğrenme oranı kullanmak daha pratik bulunmuştur. Değişken öğrenme oranı kullanılan durumlar da vardır ve bu mantığa daha yakındır: öğrenme hızlandıysa öğrenme katsayısı azaltılır, yavaşladıysa artırılır. Burada anlatılan yöntemde bu mekanizma matematiksel olarak daha doğru biçimde işler; mantık aynıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $f(x) = 2x_1^2 + x_1x_2 + x_2^2$ fonksiyonunun minimumunu en dik gradyan düşüm yöntemiyle arayın. Başlangıç $x^0 = [0{,}5;\ 1]^T$, $\epsilon_1 = 0{,}1$ (gradyan normu), $\epsilon_2 = 0{,}15$ (nokta farkı ve fonksiyon değeri farkı), $M = 10$.

**Çözüm (derste verilen, ilk iki iterasyon):** $\nabla f = [4x_1 + x_2;\ x_1 + 2x_2]^T$. $\nabla f(x^0) = [3;\ 2{,}5]^T$, normu $\approx 3{,}905 > 0{,}1$. $d^0 = [-3;\ -2{,}5]^T$, $t_0^* = 0{,}24$, $x^1 = [-0{,}22;\ 0{,}4]^T$. $d^1 = [0{,}48;\ -0{,}58]^T$, $t_1^* = 0{,}546$, $x^2 = [0{,}04;\ 0{,}08]^T$; $\|x^2 - x^1\| = 0{,}41$ ve $|f(x^2) - f(x^1)| = 0{,}156$ değerleri $0{,}15$'ten büyük olduğu için $k = 2$ ile devam edilir (bölüm 8).

**Soru 2** (derste sözlü, 00:47:34): Kalınan $x^2$ noktasından bir iterasyon daha işletin: $x^3$ noktasını bulun, $x^3$'teki gradyanı ve durma koşullarını kontrol edin. Gradyan, norm ve $\ell$ fonksiyonunu elle kurup çözmek pratik için istendi.

> **Çözüm (derste verilmedi):** Slayttaki yuvarlanmış $x^2 = [0{,}04;\ 0{,}08]^T$ ile, python ile kontrol edilerek:
>
> - $\nabla f(x^2) = [4(0{,}04) + 0{,}08;\ 0{,}04 + 2(0{,}08)]^T = [0{,}24;\ 0{,}2]^T$, $\|\nabla f(x^2)\| = \sqrt{0{,}0976} \approx 0{,}312 > 0{,}1$; $k = 2 < 10$. Durma yok.
> - $d^2 = [-0{,}24;\ -0{,}2]^T$. $x_1 = 0{,}04 - 0{,}24t_2$, $x_2 = 0{,}08 - 0{,}2t_2$ konarak $\ell(t_2) = 2(0{,}04 - 0{,}24t_2)^2 + (0{,}04 - 0{,}24t_2)(0{,}08 - 0{,}2t_2) + (0{,}08 - 0{,}2t_2)^2$.
> - $\frac{d\ell}{dt_2} = -0{,}0976 + 0{,}4064\,t_2 = 0 \Rightarrow t_2^* \approx 0{,}2402$.
> - $x^3 = x^2 + t_2^* d^2 \approx [0{,}04 - 0{,}0576;\ 0{,}08 - 0{,}048]^T = [-0{,}0176;\ 0{,}032]^T$.
> - $\|x^3 - x^2\| = \sqrt{0{,}0576^2 + 0{,}048^2} \approx 0{,}075 < 0{,}15$ ve $|f(x^3) - f(x^2)| \approx |0{,}0011 - 0{,}0128| \approx 0{,}0117 < 0{,}15$: iki koşul da sağlanır.
> - $\nabla f(x^3) \approx [-0{,}0386;\ 0{,}0463]^T$, normu $\approx 0{,}060 < 0{,}1$: gradyan koşulu da sağlanır. Algoritma $x^3 \approx [-0{,}018;\ 0{,}032]^T$ noktasında durur; gerçek minimum $[0;\ 0]^T$'dir.

**Soru 3** (derste sözlü, 00:45:29): Adım miktarı ile öğrenme oranı aynı şey midir? Cevap bölüm 9'dadır.

## Dersin Toparlaması

Bu derste düşüm algoritmalarının genel yapısı (başla, yön belirle, adım belirle, güncelle, durma kriterine bak) tekrarlandı ve durma kriterleri ayrıntılı ele alındı: ideal ama pratikte kullanılamayan hata ve $f(x^*)$ kriterleri, onların yerine kullanılan ardışık nokta farkı ve ardışık fonksiyon değeri farkı, gradyan normu kriteri ve Hessian'a dayalı kriter. Ardışık fonksiyon değeri farkının türev tanımının payına karşılık geldiği, bu yüzden küçülmesinin türevin sıfıra, yani bir minimuma yaklaşıldığını gösterdiği vurgulandı. Taylor açılımından düşüm yönü koşulu $h^T f'(x) < 0$ çıkarıldı ve gradyanın tersi yönünün her zaman fonksiyonu azalttığı, gradyan düşümün garantili ama yavaş bir yöntem olduğu anlatıldı.

$f(x) = 2x_1^2 + x_1x_2 + x_2^2$ örneğinde gradyan, gradyan normu, $\ell(t)$ fonksiyonuyla adım uzunluğu ve yeni noktalar adım adım hesaplandı. Son olarak sabit öğrenme oranının, her adımda hesaplanan adım miktarının pratik karşılığı olduğu açıklandı. Gradyan düşüm mantığı ilerleyen derslerde geri yayılım algoritmasında kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
