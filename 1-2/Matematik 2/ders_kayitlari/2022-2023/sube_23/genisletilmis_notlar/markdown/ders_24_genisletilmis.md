# Ders 24 Genişletilmiş Notu: Parametrik Denklemler: Teğet, İkinci Türev, Alan ve Yay Uzunluğu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Parametrik Denklemlere Dönüş
- 2. Parametrik Eğri ve Parametreyi Yok Etme
- 3. Düzlem ile Silindirin Arakesitini Parametrize Etme
- 4. Bir Noktadan Geçen Doğrunun Parametrik Denklemi
- 5. Parametrik Denklemden Kartezyen Denkleme: Hiperbol
- 6. Parametrik Eğride Türev, Teğet ve Normal Doğru
- 7. Parametrik Eğride İkinci Türev
- 8. Parametrik Eğride Alan
- 9. Yay Uzunluğu Formülleri
- 10. Yay Uzunluğu ve Alan Örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: Parametrik Denklemlere Dönüş

Hoca, integral konusunun bir önceki derste tamamlandığını söyleyerek başladı. Bu derste parametrik denklemlere (parametric equations) geri dönüldü. Amaç, parametreye bağlı verilmiş fonksiyonların grafiklerini, teğetlerini, alanlarını ve yay uzunluklarını kısaca hatırlatmak ve finalde gelebilecek soru tiplerini çözmekti. Ekranda hocanın hazırladığı ders notu PDF'i kullanıldı. Bazı sorular ayrıca boş bir sayfada (tahtada) yeniden çözüldü.

## 2. Parametrik Eğri ve Parametreyi Yok Etme

### 2.1 Tanım

Bir eğride $x$ ve $y$ doğrudan birbirine bağlı olmak yerine üçüncü bir değişkene, $t$ parametresine bağlı verilebilir.

**Tanım (Parametrik eğri)**

- $x=f(t)$, $y=g(t)$, $a\le t\le b$ biçiminde verilen eğridir.
- Eğrinin başlangıç noktası $(f(a),\,g(a))$'dır.
- Eğrinin bitiş noktası $(f(b),\,g(b))$'dir.

Hoca, $t$'ye değerler verip karşılık gelen $(x,y)$ noktalarını işaretleyerek eğrinin "canlı canlı" çizilebileceğini söyledi. Böylece eğrinin nereden başlayıp nerede bittiği görülür.

### 2.2 Örnek 1: $x=t^2$, $y=t+1$

Verilen: $x=t^2$, $y=t+1$, $t$ bütün reel sayılarda değişiyor.

- İkinci denklemden $t=y-1$ çekilir.
- Bu, birinci denklemde yerine yazılır: $x=(y-1)^2$.

Sonuç, yatay eksene doğru açılan bir paraboldür. Hoca, $t$'nin aldığı değerlere karşılık $x=t^2$ ve $y=t+1$ değerlerinin yazılıp grafikte işaretlenmesini önerdi.

<!-- BELİRSİZ: 00:02:49'da $t$'nin aralığı altyazıda "x son son son son arasında" diye duyuluyor; büyük olasılıkla $-\infty<t<\infty$. -->

### 2.3 Örnek 2: Birim çember ve farklı parametrizasyonlar

Verilen: $x=\cos t$, $y=\sin t$, $0\le t\le 2\pi$. İki denklemin kareleri taraf tarafa toplanırsa:

$$x^2+y^2=\cos^2t+\sin^2t=1.$$

Bu birim çemberdir.

Ardından ekrandaki örnek: $x=\sin t$, $y=\cos t$, $-\tfrac{\pi}{2}\le t\le\tfrac{\pi}{2}$. Kareler yine toplanırsa $x^2+y^2=1$ çıkar. Hoca, farklı parametrizasyonların aynı eğriyi temsil edebileceğini vurguladı. Grafiği çizerken sinüs ve kosinüsün davranışını hatırlattı: $\cos$ sıfırda $1$'den başlar, $\sin$ sıfırda $0$'dan başlar. Sınır değerleri yerine koyunca: $t=-\tfrac{\pi}{2}$ için $x=-1$, $y=0$; $t=\tfrac{\pi}{2}$ için $x=1$, $y=0$ olur.

> **Ders sonrası not:** $-\tfrac{\pi}{2}\le t\le\tfrac{\pi}{2}$ aralığında $y=\cos t\ge 0$ olduğundan bu parametrizasyon tam çemberi değil, yalnız üst yarım çemberi çizer. Eğri $(-1,0)$'dan başlar, $(0,1)$'den geçer ve $(1,0)$'da biter.

<!-- BELİRSİZ: 00:06:02'de hoca "$t=0$ için $x=1,y=0$; $t=1$ için $x=0,y=1$; $t=2$ için $x=1,y=1$" diye bir değer tablosu okuyor. Bu değerlerin hangi parametrizasyona ait olduğu altyazıdan anlaşılmıyor. -->

### 2.4 Grafiğin önemi

> **Hocanın vurgusu:** Bu grafikleri mutlaka iyi çizmek lazım. Alan hesaplarında ve sınırları belirlenen integrallerde bölgeler karşımıza çıkar. Grafik çizimi integral sorularında "olmazsa olmaz"dır ve doğru sonuca yaklaşmanın en önemli adımlarından biridir.

Hoca çizimleri ilk dönem yaptıklarını, ama bu dönem daha önemli hale geldiğini söyledi. Bazı integrallerde gerekmese de çoğu alan sorusunda bölgeyi doğru çizmek gerekir.

## 3. Düzlem ile Silindirin Arakesitini Parametrize Etme

### 3.1 Örnek 3

Soru: $x+2y+4z=4$ düzlemi ile $x^2+4y^2=4$ silindirinin arakesit eğrisini parametrize ediniz.

Hoca çözüme silindir denklemini düzenleyerek başladı: her iki taraf $4$'e bölünür,

$$\frac{x^2}{4}+y^2=1.$$

Bu noktada (00:07:54) hocanın internet bağlantısı koptu. Bağlantı 00:09:40'ta geri geldi, ancak ekran paylaşımı yeniden açıldığında ders bir sonraki soruya geçmişti. Bu yüzden çözümün geri kalanı altyazıda yok. Aşağıdaki adımlar, hocanın başladığı düzenlemenin doğal devamıdır (ara adım eklendi):

- $\dfrac{x^2}{4}+y^2=1$ bir elipstir. Bunun için $x=2\cos t$, $y=\sin t$, $0\le t\le 2\pi$ alınır. Gerçekten $(2\cos t)^2+4\sin^2t=4$ sağlanır.
- Düzlemden $z$ çekilir: $z=\dfrac{4-x-2y}{4}=1-\dfrac{2\cos t+2\sin t}{4}=1-\dfrac{\cos t+\sin t}{2}$.
- Arakesit eğrisi: $\vec r(t)=\left\langle 2\cos t,\ \sin t,\ 1-\dfrac{\cos t+\sin t}{2}\right\rangle$, $0\le t\le 2\pi$.

<!-- BELİRSİZ: Altyazıda düzlem denklemi "x kare artı ikiye artı dört size eşittir dört" diye duyuluyor; kısa nottaki gibi $x+2y+4z=4$ alındı. Çözümün 00:07:54 sonrası kısmı altyazıda yok. -->

## 4. Bir Noktadan Geçen Doğrunun Parametrik Denklemi

### 4.1 Örnek 4

Soru: $(a,b)$ noktasından geçen ve eğimi $m$ olan doğruyu parametrize ediniz.

Önce bilinen doğru denklemi yazılır:

$$y-b=m(x-a).$$

Sonra $x-a=t$ denir. Buradan:

- $x=a+t$.
- $y-b=m\,t$ olduğundan $y=b+mt$.

Böylece doğru $x=a+t$, $y=b+mt$ biçiminde parametreye bağlı yazılmış olur.

## 5. Parametrik Denklemden Kartezyen Denkleme: Hiperbol

### 5.1 Örnek 5

Soru: $x=t+\dfrac{1}{t}$, $y=t-\dfrac{1}{t}$, $t>0$ eğrisinin kartezyen denklemini bulunuz.

- Taraf tarafa toplanırsa $\tfrac1t$'ler birbirini götürür: $x+y=2t$.
- Farkı alınırsa: $x-y=\dfrac{2}{t}$.
- Bu iki eşitlik taraf tarafa çarpılır: $(x+y)(x-y)=2t\cdot\dfrac{2}{t}=4$, yani $x^2-y^2=4$.

Hoca, sınavda böyle bir parametrik ifadenin verilip kartezyen biçime dönüştürülmesinin istenebileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** $t>0$ olduğu için aritmetik-geometrik ortalama eşitsizliğinden $x=t+\tfrac1t\ge 2$ olur. Bu yüzden eğri, $x^2-y^2=4$ hiperbolünün tamamı değil, yalnız sağ koludur.

## 6. Parametrik Eğride Türev, Teğet ve Normal Doğru

### 6.1 Birinci türev

$x=f(t)$, $y=g(t)$ verildiğinde $y$ doğrudan $x$'e bağlı değildir; ikisi de $t$'ye bağlıdır. Hoca bunu zincir kuralı ile açıkladı: $y$, $x$'in fonksiyonu gibi düşünülürse

$$\frac{dy}{dt}=\frac{dy}{dx}\cdot\frac{dx}{dt}$$

olur. Buradan:

**Formül (Parametrik eğride birinci türev)**

- $\dfrac{dy}{dx}=\dfrac{dy/dt}{dx/dt}$, $\dfrac{dx}{dt}\ne 0$.

Hoca burada sınavda ikinci türevin geldiğini hatırlattı ve ikinci türeve ayrıca örnekle döneceğini söyledi.

### 6.2 Teğet ve normal doğru

$(x_0,y_0)$ noktasında eğim $m_T$ ise:

**Formül (Teğet ve normal)**

- Teğet doğru: $y-y_0=m_T\,(x-x_0)$.
- Normal doğru: $y-y_0=-\dfrac{1}{m_T}\,(x-x_0)$.

Parametrik eğride $m_T=\dfrac{dy}{dx}$, ilgili $t$ değerinde hesaplanır.

### 6.3 Örnek 6: $x=\sec t$, $y=\tan t$

Soru: $x=\sec t$, $y=\tan t$ eğrisinin $(\sqrt2,\,1)$ noktasındaki eğimini, teğet ve normal doğrusunun denklemini bulunuz. Hoca bunun "gelebilecek bir soru" olduğunu söyledi.

<!-- BELİRSİZ: $t$'nin verilen aralığı altyazıda okunmuyor; büyük olasılıkla $-\tfrac{\pi}{2}<t<\tfrac{\pi}{2}$. -->

**Adım 1: Noktaya karşılık gelen $t$.** $x_0=\sqrt2$, $y_0=1$.

- $\sqrt2=\sec t=\dfrac{1}{\cos t}$ ise içler-dışlar çarpımı ile $\cos t=\dfrac{1}{\sqrt2}=\dfrac{\sqrt2}{2}$. Buradan $t=\dfrac{\pi}{4}$ ($45^\circ$).
- $1=\tan t$ ise yine $t=\dfrac{\pi}{4}$ çıkar, çünkü $45^\circ$'nin tanjantı $1$'dir.

İki koordinat aynı $t$ değerini verdi.

**Adım 2: Türevler.**

- $\dfrac{dy}{dt}=(\tan t)'=\sec^2 t=\dfrac{1}{\cos^2t}$.
- $\dfrac{dx}{dt}=(\sec t)'=\sec t\tan t$. Hoca, isteyenin bunu $\dfrac{1}{\cos t}$'nin bölüm kuralıyla türevini alarak da bulabileceğini söyledi.

**Adım 3: Eğim.**

$$\frac{dy}{dx}=\frac{\sec^2t}{\sec t\tan t}=\frac{\sec t}{\tan t}=\frac{1}{\sin t}\quad\text{(ara adım eklendi)}.$$

$t=\tfrac{\pi}{4}$'te $m_T=\dfrac{1}{\sqrt2/2}=\sqrt2$.

**Adım 4: Teğet.** $y-1=\sqrt2\,(x-\sqrt2)$ düzenlenirse

$$y=\sqrt2\,x-1.$$

**Adım 5: Normal.** Eğim $-\dfrac{1}{\sqrt2}$ alınır:

$$y-1=-\frac{1}{\sqrt2}\,(x-\sqrt2)\ \Rightarrow\ y=-\frac{x}{\sqrt2}+2.$$

> **Ders sonrası not:** Hoca normal doğruyu söylerken "$x-2\sqrt2$" der gibi okuyor (00:21:20). Doğrusu $x-\sqrt2$'dir: $y-1=-\tfrac{1}{\sqrt2}(x-\sqrt2)$, yani $y=-\tfrac{x}{\sqrt2}+2$.

Hoca sorunun özetini şöyle yaptı: Bilmemiz gereken en önemli şey $\dfrac{dy}{dx}$'tir; $y$ de $x$ de $t$'ye bağlı olduğu için iki türev birbirine bölünür. Sonra $x_0$ ve $y_0$ yerine konarak $t_0$ bulunur, türevde $t_0$ yazılarak eğim bulunur. Son olarak teğet ve normal denklemleri yazılır. "Başka da bir şey yok" dedi.

## 7. Parametrik Eğride İkinci Türev

### 7.1 Neden dikkat gerekir?

> **Hocanın vurgusu:** Bu soru önemli. Öğrencilerin yaklaşık %80'i birinci türevi alıyor ama ikinci türevi almakta zorlanıyor. Sınavda ikinci türev gelmişti.

Birinci türev $\dfrac{dy}{dx}$ bulunduğunda sonuç $t$'ye bağlı bir ifadedir. İkinci türev ise bu ifadenin $x$'e göre türevidir. Hocanın ifadesiyle: "Bu fonksiyon neye bağlı? $t$'ye bağlı. Ben neye göre türevini alacağım? $x$'e göre. Alabilir miyim? Alamam." Bu yüzden bir manipülasyon yapılır: birinci türeve $y'$ denir ve $y'$ de bir parametrik fonksiyon gibi düşünülür. Aynı birinci türev formülü $y'$'ye uygulanır:

**Formül (Parametrik eğride ikinci türev)**

- $\dfrac{d^2y}{dx^2}=\dfrac{d}{dx}\left(y'\right)=\dfrac{dy'/dt}{dx/dt}$, burada $y'=\dfrac{dy}{dx}$.
- Yani önce birinci türevin $t$'ye göre türevi alınır, sonra $\dfrac{dx}{dt}$'ye bölünür.

### 7.2 Örnek 7: $x=t-t^2$, $y=t-t^3$

Soru: $x=t-t^2$, $y=t-t^3$ ise $\dfrac{d^2y}{dx^2}$'yi bulunuz. Hoca bunun final sorusuna benzer bir soru olduğunu söyledi.

**Birinci türev.**

- $\dfrac{dy}{dt}=1-3t^2$, $\dfrac{dx}{dt}=1-2t$.
- $y'=\dfrac{dy}{dx}=\dfrac{1-3t^2}{1-2t}$.

**İkinci türev.** Bölüm kuralı ile (ara adım eklendi):

$$\frac{d}{dt}\left(\frac{1-3t^2}{1-2t}\right)=\frac{-6t(1-2t)-(1-3t^2)(-2)}{(1-2t)^2}=\frac{6t^2-6t+2}{(1-2t)^2}.$$

Bu sonuç $\dfrac{dx}{dt}=1-2t$'ye bölünür:

$$\frac{d^2y}{dx^2}=\frac{6t^2-6t+2}{(1-2t)^3}.$$

Bu soru ekranda çözülürken öğrenciler (00:26:11) ekranda yazılan sayfanın değil, "Matematik 2 ders notu hafta 5" PDF'inin göründüğünü haber verdi. Hoca paylaşımı düzeltti. Hocanın ekranda yazdığı son ifade sesli okunmadı; yukarıdaki sonuç hesapla kesinleştirildi.

### 7.3 Örnek 8: Tahtada çözülen varyasyon $x=t-t^2$, $y=t^3$

Aradan sonra hoca soruyu boş bir sayfada yeniden çözmeyi önerdi. "Başka bir soru çözmüş olalım" diyerek $y$'yi değiştirdi: $x=t-t^2$, $y=t^3$.

**Birinci türev.**

- $\dfrac{dy}{dt}=3t^2$, $\dfrac{dx}{dt}=1-2t$.
- $y'=\dfrac{3t^2}{1-2t}$.

**$y'$'nin $t$'ye göre türevi.** Hoca bölüm kuralını yüksek sesle uyguladı: "$6t$ çarpı $(1-2t)$, eksi altın türevi $-2$, o zaman artı $2$ oldu, çarpı $3t^2$, bölü paydanın karesi."

$$\frac{d}{dt}\left(\frac{3t^2}{1-2t}\right)=\frac{6t(1-2t)+2\cdot 3t^2}{(1-2t)^2}=\frac{6t-12t^2+6t^2}{(1-2t)^2}=\frac{6t-6t^2}{(1-2t)^2}.$$

**İkinci türev.** $\dfrac{dx}{dt}=1-2t$'ye bölünür; payda küp olur:

$$\frac{d^2y}{dx^2}=\frac{6t-6t^2}{(1-2t)^3}.$$

Hoca, soruda belirli bir $t$ değeri verilirse (örneğin $t=1$) bu değerin yerine konup sonucun bulunacağını söyledi. Ardından şunu ekledi: soruda "ivme vektörü" de denebilir, "ivme vektörü zaten ikinci türev demektir."

> **Ders sonrası not:** Büyük olasılıkla burada bir karışıklık var. İvme vektörü, konum vektörü $\vec r(t)=\langle x(t),y(t)\rangle$'nin $t$'ye göre ikinci türevidir: $\vec a(t)=\langle x''(t),\,y''(t)\rangle$. Bu, $\dfrac{d^2y}{dx^2}$ ile aynı şey değildir. Örnek 8'de $\vec a(t)=\langle -2,\ 6t\rangle$ olurdu.

## 8. Parametrik Eğride Alan

### 8.1 Formül

Kartezyen koordinatta alan $A=\displaystyle\int y\,dx$'tir. Eğri parametrik verildiğinde $y=g(t)$ ve $dx=f'(t)\,dt$ yazılır; $x$ sınırlarına karşılık gelen $t$ sınırları bulunur:

**Formül (Parametrik alan)**

- $A=\displaystyle\int y\,dx=\int_{t_1}^{t_2} g(t)\,f'(t)\,dt$.
- Eğri simetrikse bir parçanın (örneğin birinci bölgedeki parçanın) alanı bulunur ve parça sayısıyla çarpılır.

### 8.2 Örnek 9: Elipsin alanı

Soru: $x=a\cos t$, $y=b\sin t$, $0\le t\le 2\pi$ ile verilen elipsin alanını bulunuz.

Hoca önce eğrinin $\dfrac{x^2}{a^2}+\dfrac{y^2}{b^2}=1$ elipsi olduğunu söyledi. Elips dört bölgede simetrik olduğu için birinci bölgedeki alan bulunup $4$ ile çarpılır.

- Birinci bölgede $x$, $0$'dan $a$'ya gider. $x=0$ için $t=\tfrac{\pi}{2}$, $x=a$ için $t=0$'dır.
- $y=b\sin t$.
- $dx=-a\sin t\,dt$.

$$A=4\int_0^a y\,dx=4\int_{\pi/2}^{0} b\sin t\,(-a\sin t)\,dt=4ab\int_0^{\pi/2}\sin^2t\,dt.$$

Hoca, $\sin^2t$ için ilk dönemden bilinen yarım açı formülünü hatırlattı: $\sin^2t=\dfrac{1-\cos 2t}{2}$. Buna göre (ara adım eklendi):

$$\int_0^{\pi/2}\sin^2t\,dt=\left[\frac{t}{2}-\frac{\sin 2t}{4}\right]_0^{\pi/2}=\frac{\pi}{4},\qquad A=4ab\cdot\frac{\pi}{4}=\pi ab.$$

> **Ders sonrası not:** Hoca sınırları söylerken "pi bölü 2'den a'ya kadar" diyor (00:57:17). Doğrusu: $x$ için $0\to a$, $t$ için $\tfrac{\pi}{2}\to 0$. Sonucu ($\pi ab$) hoca sesli okumadı; sonuç sympy ile doğrulandı.

### 8.3 Örnek 10: Astroidin alanı

Soru: $x=\cos^3t$, $y=\sin^3t$, $0\le t\le 2\pi$ ile verilen astroid (astroid) eğrisinin sınırladığı alanı bulunuz.

> **Ders sonrası not:** Hoca soruya girerken "sikloid denen bir cisim" diyor (00:58:20), hemen ardından "astroid eğrisi" diyor. Bu eğri sikloid (cycloid) değil, astroiddir.

Hoca birinci bölgedeki alanı hesaplayıp $4$ ile çarptı. Birinci bölgede $x$, $0$'dan $1$'e gider; bu $t$ için $\tfrac{\pi}{2}\to 0$ demektir.

- $y=\sin^3t$.
- $dx=-3\cos^2t\,\sin t\,dt$.

$$A=4\int_0^1 y\,dx=4\int_{\pi/2}^{0}\sin^3t\,(-3\cos^2t\sin t)\,dt=12\int_0^{\pi/2}\sin^4t\cos^2t\,dt.$$

Hoca, bundan sonrasının ilk dönemin konusu olduğunu söyledi: kosinüsün ve sinüsün kuvvetleri çift olduğu için yarım açı formülleriyle ($\sin^2t=\tfrac{1-\cos2t}{2}$, $\cos^2t=\tfrac{1+\cos2t}{2}$) kare gördüğümüz yerde $2t$'ye geçilip düzenleme yapılır. Sonuç:

$$A=\frac{3\pi}{8}\ \text{birim kare}.$$

> **Ders sonrası not:** Hoca $dx$'i "$3\cos^2t\sin t\,dt$" diye işaretsiz okuyor (00:59:35). Türev $-3\cos^2t\sin t\,dt$'dir. Eksi işaret, sınırların $\tfrac{\pi}{2}\to0$ yerine $0\to\tfrac{\pi}{2}$ yazılmasıyla götürülür. Sonuç $\tfrac{3\pi}{8}$ sympy ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** $\int_0^{\pi/2}\sin^4t\cos^2t\,dt$ gibi integraller için Wallis formülü de kullanılabilir. Bu integralin değeri $\tfrac{\pi}{32}$'dir; $12\cdot\tfrac{\pi}{32}=\tfrac{3\pi}{8}$ olur.

## 9. Yay Uzunluğu Formülleri

### 9.1 Kartezyen koordinatta yay uzunluğu

Hoca formülün nereden geldiğini kısaca gösterdi. Bir eğri parçasının uzunluğu $L$ olsun. Eğri üzerinde küçük bir parça $\Delta L$ alınır. Bu parçaya karşılık $x$'te $\Delta x$, $y$'de $\Delta y$ değişim olur. Pisagor ile:

$$\Delta L=\sqrt{(\Delta x)^2+(\Delta y)^2}.$$

Kök içi $(\Delta x)^2$'ye bölünür, dışarı $\Delta x$ çarpanı çıkar. Limitte $\dfrac{\Delta y}{\Delta x}\to f'(x)$ olur. Her taraf $a$'dan $b$'ye integre edilirse yayın uzunluğu elde edilir:

**Formül (Kartezyen yay uzunluğu)**

- $L=\displaystyle\int_a^b\sqrt{1+\left(f'(x)\right)^2}\,dx$.

### 9.2 Parametrik yay uzunluğu

Bu kez kök içi $(\Delta x)^2$'ye değil $(\Delta t)^2$'ye bölünür ve dışarı $dt$ çıkar:

**Formül (Parametrik yay uzunluğu)**

- $L=\displaystyle\int_{t_1}^{t_2}\sqrt{\left(\frac{dx}{dt}\right)^2+\left(\frac{dy}{dt}\right)^2}\,dt$.

### 9.3 Kutupsal yay uzunluğu

Hoca kutupsal koordinatta verilen bir eğri için formülü de hatırlattı:

**Formül (Kutupsal yay uzunluğu)**

- $r=f(\theta)$, $\alpha\le\theta\le\beta$ için $L=\displaystyle\int_\alpha^\beta\sqrt{r^2+\left(\frac{dr}{d\theta}\right)^2}\,d\theta$.

## 10. Yay Uzunluğu ve Alan Örnekleri

### 10.1 Örnek 11: Çemberin uzunluğu

Soru: $x=r\cos t$, $y=r\sin t$, $0\le t\le 2\pi$ ile verilen çemberin uzunluğu nedir?

- $\dfrac{dx}{dt}=-r\sin t$, $\dfrac{dy}{dt}=r\cos t$.
- Kareler toplamı: $r^2\sin^2t+r^2\cos^2t=r^2$.

$$L=\int_0^{2\pi}\sqrt{r^2\sin^2t+r^2\cos^2t}\,dt=\int_0^{2\pi}r\,dt=2\pi r.$$

Hoca bunun zaten bilinen çevre formülü olduğunu, "malumun ilanı" olduğunu söyledi.

### 10.2 Örnek 12: Aynı çemberin alanı

Hoca öğrencilere sordu: "Aynı soruda alan deseydi nasıl yapacaktık?" Ve kendisi cevapladı: Birinci bölgedeki alan bulunup $4$ ile çarpılır.

- $y=r\sin t$, $dx=-r\sin t\,dt$.
- $A=4\displaystyle\int y\,dx$, içeride $r^2\sin^2t$ kalır.
- $\sin^2t$'nin integrali alınınca $A=\pi r^2$ çıkar.

> **Ders sonrası not:** Hoca integrali "sıfırdan pi bölü ikiye kadar" ve $dx=-r\sin t\,dt$ ile yazıyor (01:07:44). Bu haliyle sonuç $-\pi r^2$ çıkar. $x:0\to r$ için doğru sınır $t:\tfrac{\pi}{2}\to0$'dır: $A=4\displaystyle\int_{\pi/2}^{0}r\sin t\,(-r\sin t)\,dt=4r^2\int_0^{\pi/2}\sin^2t\,dt=\pi r^2$. Bu sonuç sympy ile doğrulandı.

### 10.3 Örnek 13: $y=x^3$ altındaki alan (parametrik)

Soru: $[0,1]$ aralığında $y=x^3$ eğrisinin altında kalan bölgenin alanını bulunuz. Eğri parametrik olarak $x=t^2$, $y=t^6$, $-\infty<t<\infty$ verilmiş.

Hoca bunun normalde kartezyen koordinatta yapılan bir soru olduğunu, farkın parametrik verilmesi olduğunu söyledi.

- $x$, $0$'dan $1$'e giderken $t=\sqrt{x}$ alınırsa $t$ de $0$'dan $1$'e gider (ara adım eklendi).
- $y=t^6$, $dx=2t\,dt$.

$$A=\int_0^1 y\,dx=\int_0^1 t^6\cdot 2t\,dt=2\int_0^1t^7\,dt=\frac{2}{8}=\frac14.$$

Kontrol (ara adım eklendi): kartezyende $\displaystyle\int_0^1x^3\,dx=\tfrac14$ olur; iki yol aynı sonucu verir.

### 10.4 Örnek 14: Astroidin uzunluğu

Soru: $x=\cos^3t$, $y=\sin^3t$, $0\le t\le 2\pi$ astroid eğrisinin uzunluğunu bulunuz.

- $\dfrac{dx}{dt}=-3\cos^2t\sin t$, $\dfrac{dy}{dt}=3\sin^2t\cos t$.
- Kareler toplamı: $9\cos^4t\sin^2t+9\sin^4t\cos^2t=9\sin^2t\cos^2t(\cos^2t+\sin^2t)=9\sin^2t\cos^2t$ (ara adım eklendi).
- Birinci bölgede ($0\le t\le\tfrac{\pi}{2}$) $\sin t\cos t\ge0$ olduğundan kök $3\sin t\cos t$ olur.

Hoca bir bölgede uzunluğu alıp $4$ ile çarptı. Sadeleştirince "çok basit bir integral" çıktı:

$$L=4\int_0^{\pi/2}3\sin t\cos t\,dt=12\int_0^{\pi/2}\frac{\sin2t}{2}\,dt=6\left[-\frac{\cos2t}{2}\right]_0^{\pi/2}=-3(\cos\pi-1)=6.$$

> **Ders sonrası not:** Hoca sonucu sesli okumadı; yalnız "pozitif bir değer elde etmiş olduk" dedi (01:11:17). Sonuç $6$'dır; sympy ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Astroidin uzunluğunu doğrudan $0$'dan $2\pi$'ye integre etmek doğru değildir, çünkü $\sin t\cos t$ bazı bölgelerde negatiftir ve kök $3|\sin t\cos t|$'dir. Bu yüzden simetriden bir bölge alınıp $4$ ile çarpmak hem kolay hem güvenlidir.

### 10.5 Finalde gelebilecek tipler

Hoca dersi şöyle bağladı: parametrik olarak verildiğinde alan bulma, hacim bulma ve iki eğri arasındaki alanı bulma finalde gelebilecek soru tipleridir.

## Örnek Sorular

Bu derste kare yok. Sorular hocanın ekrandaki ders notundan sesli okuduğu ve çözdüğü sorulardır. Çözümler yukarıdaki bölümlerde adım adım verildi.

- **Soru 1** (derste sözlü, 00:07:10): $x+2y+4z=4$ düzlemi ile $x^2+4y^2=4$ silindirinin arakesitini parametrize ediniz.
  - Çözüm (çözüm bağlantı kopması nedeniyle altyazıda yarım kaldı; kalan adımlar Bölüm 3'te tamamlandı): $\vec r(t)=\left\langle 2\cos t,\ \sin t,\ 1-\tfrac{\cos t+\sin t}{2}\right\rangle$.
- **Soru 2** (derste sözlü, 00:10:52): $(a,b)$ noktasından geçen, eğimi $m$ olan doğruyu parametrize ediniz.
  - Çözüm: $x=a+t$, $y=b+mt$.
- **Soru 3** (derste sözlü, 00:12:24): $x=t+\tfrac1t$, $y=t-\tfrac1t$, $t>0$ eğrisini kartezyen denkleme dönüştürünüz.
  - Çözüm: $x^2-y^2=4$.
- **Soru 4** (derste sözlü, 00:15:23): $x=\sec t$, $y=\tan t$ eğrisinin $(\sqrt2,1)$ noktasındaki eğimini, teğet ve normal doğrusunu bulunuz.
  - Çözüm: $m=\sqrt2$; teğet $y=\sqrt2\,x-1$; normal $y=-\tfrac{x}{\sqrt2}+2$.
- **Soru 5** (derste sözlü, 00:24:15 ve 00:27:01): $x=t-t^2$, $y=t-t^3$ ise $\dfrac{d^2y}{dx^2}$ nedir?
  - Çözüm: $\dfrac{d^2y}{dx^2}=\dfrac{6t^2-6t+2}{(1-2t)^3}$.
- **Soru 6** (derste sözlü, 00:51:54): $x=t-t^2$, $y=t^3$ ise $\dfrac{d^2y}{dx^2}$ nedir?
  - Çözüm: $\dfrac{d^2y}{dx^2}=\dfrac{6t-6t^2}{(1-2t)^3}$.
- **Soru 7** (derste sözlü, 00:55:51): $x=a\cos t$, $y=b\sin t$, $0\le t\le2\pi$ elipsinin alanını bulunuz.
  - Çözüm: $A=\pi ab$.
- **Soru 8** (derste sözlü, 00:58:15): $x=\cos^3t$, $y=\sin^3t$, $0\le t\le2\pi$ astroidinin alanını bulunuz.
  - Çözüm: $A=\tfrac{3\pi}{8}$ birim kare.
- **Soru 9** (derste sözlü, 01:05:53): $x=r\cos t$, $y=r\sin t$, $0\le t\le2\pi$ çemberinin uzunluğu nedir? Aynı soruda alan istenseydi nasıl yapılırdı? (01:07:36)
  - Çözüm: $L=2\pi r$, $A=\pi r^2$.
- **Soru 10** (derste sözlü, 01:09:05): $x=t^2$, $y=t^6$ parametrizasyonuyla $[0,1]$ aralığında $y=x^3$ eğrisinin altında kalan alanı bulunuz.
  - Çözüm: $A=\tfrac14$.
- **Soru 11** (derste sözlü, 01:10:17): $x=\cos^3t$, $y=\sin^3t$, $0\le t\le2\pi$ astroidinin uzunluğunu bulunuz.
  - Çözüm: $L=6$.

## Dersin Toparlaması

Bu derste parametrik eğriler final öncesi soru çözümüyle tekrar edildi. Parametrik eğrinin başlangıç ve bitiş noktası, parametreyi yok ederek kartezyen denkleme geçiş ve aynı eğrinin farklı parametrizasyonları hatırlatıldı. Düzlem ile silindirin arakesiti ve bir noktadan geçen doğru parametrize edildi. Türev tarafında $\dfrac{dy}{dx}=\dfrac{dy/dt}{dx/dt}$ formülüyle teğet ve normal doğru bulundu. İkinci türevde birinci türevin $t$'ye bağlı olduğu, bu yüzden önce $t$'ye göre türev alınıp $\dfrac{dx}{dt}$'ye bölünmesi gerektiği vurgulandı.

İntegral tarafında alan $\int y\,dx$ ifadesinde $y$ ve $dx$'in $t$ cinsinden yazılmasıyla hesaplandı; simetrik eğrilerde bir bölge alınıp çarpıldı. Yay uzunluğu formülünün $\Delta L=\sqrt{(\Delta x)^2+(\Delta y)^2}$'den geldiği gösterildi ve kartezyen, parametrik, kutupsal biçimleri verildi. Hoca, parametrik alan, hacim ve iki eğri arası alanın finalde gelebilecek tipler olduğunu söyledi ve dersi "haftaya" diyerek bitirdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
