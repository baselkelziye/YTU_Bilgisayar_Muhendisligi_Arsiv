# Ders 13 Genişletilmiş Notu: Laplace Dönüşümü, Yakınsama Bölgesi ve Ters Laplace Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Frekans analizinde nerede kalmıştık?
- 2. Fourier dönüşümünün sınırları ve Laplace dönüşümüne ihtiyaç
- 3. Laplace dönüşümünün tanımı
- 4. İlk örnek: $e^{-bt}u(t)$ ve yakınsama bölgesi
- 5. Fourier dönüşümü ile Laplace dönüşümü arasındaki bağlantı
- 6. İki taraflı Laplace dönüşümünün özellikleri
- 7. Konvolüsyon ve transfer fonksiyonu
- 8. Ters Laplace dönüşümü ve kısmi kesirlere ayırma
- 9. Sıfırlar, kutuplar ve kutup-sıfır çizimi
- 10. İkinci slayt takımı ve kitaptan örnekler
- Örnek Sorular
- Dersin Toparlaması

## 1. Frekans analizinde nerede kalmıştık?

Ders, şimdiye kadar işlenen frekans analizi konularının bir haritasıyla başladı. Hoca slaydın kenarına iki sütun çizdi: bir yanda sürekli (continuous), öbür yanda ayrık (discrete) işaretler (ekrandan, 00:10:00). Frekans analizi bu iki koldan paralel ilerler ve her adımın öbür tarafta bir karşılığı vardır:

- Sürekli zamanlı Fourier serisi (CTFS) $\leftrightarrow$ ayrık zamanlı Fourier serisi (DTFS),
- Sürekli zamanlı Fourier dönüşümü (CTFT) $\leftrightarrow$ ayrık zamanlı Fourier dönüşümü (DTFT).

Sürekli tarafta işlemler integralle, ayrık tarafta toplamla (sigma) yapılır. Hoca, CTFS, CTFT ve DTFS'nin DTFT'ye ulaşmak için basamak olarak kullanıldığını hatırlattı. DTFT'de frekans hâlâ sürekli olduğu için bir adım daha atılmış, frekans da ayrıklaştırılarak ayrık Fourier dönüşümü (DFT) elde edilmişti. DFT'nin hızlı hesaplanan sürümleri (FFT gibi) ve bu yöndeki ayrıntılar sayısal işaret işleme dersinin konusudur.

Bu haftanın konusu Laplace dönüşümüdür ve CTFT'nin daha genel bir hâlidir: CTFT'nin yetersiz kaldığı durumlarda da kullanılabilir. Bir sonraki konu olan z dönüşümü de DTFT'nin aynı anlamda genelleştirilmesidir. Hoca bu ilişkiyi dersin sonunda bir kez daha yazdı: CTFT $\rightarrow$ LT, DTFT $\rightarrow$ ZT (ekrandan, 02:00:00). Bu derste yalnız sürekli zamanlı işaretler ele alındı.

## 2. Fourier dönüşümünün sınırları ve Laplace dönüşümüne ihtiyaç

### 2.1 Frekans cevabının üç koşulu

Fourier dönüşümü hem işaret analizi (işaretin yapısını anlamak) hem de sistem analizi ve tasarımı için yararlı bir araçtır. Ancak slayttaki çerçevede belirtildiği gibi frekans cevabı yalnız şu üç koşulda kullanılabilir (ekrandan, 00:05:00):

1. Sistem sıfır durumundadır (zero state), yani başlangıç koşulları sıfırdır.
2. İmpuls cevabı mutlak integrallenebilirdir: $\displaystyle\int_{-\infty}^{\infty}|h(t)|\,dt<\infty$.
3. Giriş mutlak integrallenebilirdir: $\displaystyle\int_{-\infty}^{\infty}|x(t)|\,dt<\infty$.

Bu koşulu sağlamayan ama yine de FT ile ele alınabilen birkaç işaret vardır; sinüzoitler ve birim basamak bunlardan ikisidir. Hoca bu işaretlerde altta kalan alanın zamanla sonsuza gittiğini, bu tür işaretlerde FT'nin istenen sonucu tam vermediğini söyledi.

> **Hocanın vurgusu:** "Laplace dönüşümü, CTFT'nin genelleştirilmiş hâlidir." Hoca bu cümleyi yıldızla işaretledi. Genelleştirilmiş olduğu için yukarıdaki üç koşul sağlanmadığında bile kullanılabilir.

### 2.2 Laplace dönüşümünün açtığı iki yol

Slayt, LT'nin iki analiz yöntemi sağladığını gösterir (ekrandan, 00:15:00):

- **Sıfır durumu (zero state):** LT ve transfer fonksiyonu. $x(t)$ ve $h(t)$ mutlak integrallenebilir olsun ya da olmasın, FT'nin yaptığının aynısı daha geniş bir işaret ve sistem sınıfı için yapılır.
- **Sıfır olmayan durum (non zero-state):** LT tabanlı diferansiyel denklem çözümü. Bu yol hem sıfır durumu hem de sıfır giriş çözümünü birlikte verir.

Hoca, sıfır olmayan durumun genellikle diferansiyel denklemlerle çözüldüğünü, bu derste diferansiyel denklemlerin işlenmediğini söyledi. Ders, sıfır durumu yolunu ve transfer fonksiyonunu izledi.

Bu noktada hoca temel sistem modelini hatırlattı: bir kutuya $x(t)$ girer, işlenir ve $y(t)$ çıkar. Kutunun içinde impuls cevabı $h(t)$ vardır; işaret impulslardan oluşmuş gibi düşünülürse çıkış bu impulsların cevaplarının toplamıdır. Frekansa geçildiğinde aynı kutunun frekansa göre davranışı $H(\omega)$ ile tanımlanır.

## 3. Laplace dönüşümünün tanımı

### 3.1 CTFT'nin hatırlatılması

Sürekli zamanlı Fourier dönüşümü (ekrandan, 00:20:00):

$$X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}\,dt$$

Hoca bunun arkasındaki fikri şöyle anlattı: kutuya $e^{j\omega t}=\cos\omega t+j\sin\omega t$ biçiminde bir karmaşık üstel, yani aslında sinüzoidal bir giriş verilir. $\omega=2\pi f$ değiştirilerek farklı frekanslarda sinüzoitler verilir ve sistemin her birine cevabı bulunur. Bunun nedeni, bir işaretin farklı frekanslı sinüzoitlerin toplamı olarak modellenebilmesidir. Sistemin her saf sinüzoide verdiği cevap biliniyorsa sistemin frekansa cevabı, yani frekans cevabı $H(\omega)$ bilinir. Zamandaki impuls cevabı $h(t)$'nin frekans domenindeki karşılığı $H(\omega)$'dır. Aynı dönüşümle giriş işaretinin frekans içeriği de çıkarılabilir.

$x(t)$ ile $e^{-j\omega t}$ çarpılıp integrali alındığında, o frekansta işaretin o sinüzoide ne kadar benzediği, yani genlik ve faz bilgisi elde edilir.

### 3.2 $e^{-j\omega t}$ yerine $e^{-st}$

Slayttaki ifadeye göre CTFT bazı işaretler için yakınsamaz; LT bu sorunu dönüşüme bir sönüm terimi ekleyerek hafifletir (ekrandan, 00:20:00):

$$e^{-j\omega t}\quad\text{yerine}\quad e^{-st}=e^{-(\sigma+j\omega)t}=e^{-\sigma t}e^{-j\omega t}$$

Burada $s=\sigma+j\omega$ karmaşık bir değişkendir ve neredeyse her zaman bu dikdörtgen (kartezyen) biçimde düşünülür. Eskiden üstte yalnız sanal kısım ($j\omega$) vardı; şimdi başına bir gerçel kısım $\sigma$ eklendi. $e^{-j\omega t}$ terimi aynen durur. Başa gelen $e^{-\sigma t}$ çarpanı ise integrandın sönümünü kontrol eder: integral alınırken işaretin sonsuz bir toplam vermesini engeller.

### 3.3 İki taraflı ve tek taraflı Laplace dönüşümü

LT'nin iki türü vardır (ekrandan, 00:25:00):

- **İki taraflı (bilateral, two-sided) LT:**
$$X(s)=\int_{-\infty}^{\infty}x(t)e^{-st}\,dt,\qquad s=\sigma+j\omega$$
İşaret $-\infty$'dan $+\infty$'a kadar toplanır. Derste ağırlıklı olarak bu tür kullanıldı.
- **Tek taraflı (unilateral, one-sided) LT:** Aynı formül, ama integral $0$'dan başlar. İşaretin $t=0$'dan önce hiç oluşmadığı varsayılır.

$X(s)$, CTFT'deki gibi karmaşık değerli bir çıktıdır.

### 3.4 s düzlemi

FT'de $|X(\omega)|$ tek bir eksen ($\omega$) üzerinde çiziliyordu. LT'de hem $\sigma$ hem $j\omega$ değişkeni olduğu için yatay eksende $\sigma$, dikey eksende $j\omega$ olan bir düzlem oluşur. Bu düzleme **s düzlemi** (s-plane) denir. $|X(s)|$ bu düzlemin üzerinde üçüncü bir eksende çizilir; işaretler artık iki boyutlu değil üç boyutlu düşünülür. Genelleştirmeyi sağlayan da bu üçüncü değişkenin, yani $s$'nin gerçel kısmının çizime girmesidir.

### 3.5 Yakınsama bölgesi kavramı

Her dönüşüm yalnız belli bir bölgede tanımlıdır. İşaretin dönüşümünün sonlu bir değere yakınsadığı, yani sonucun bulunabildiği bölgeye **yakınsama bölgesi** (Region of Convergence, ROC) denir. Hoca kavramın ilk örnekte netleşeceğini söyledi.

Hoca bu arada dersin standart bilgisayar mühendisliği derslerinden biraz daha matematik içerdiğini, ilk duyulan kavramlar yüzünden zor görünebileceğini, ama temel kavramlar oturunca zorluk kalmayacağını söyledi. Burada öğrenilen yöntemlerin makine öğrenmesinde ve görüntü işlemede çok işe yarayacağını, sistemin nasıl davrandığını anlayan bir bilgisayar mühendisi olmak için önemli olduğunu ekledi.

## 4. İlk örnek: $e^{-bt}u(t)$ ve yakınsama bölgesi

### 4.1 İşaret

Slayttaki örnek (ekrandan, 00:30:00):

$$x(t)=e^{-bt}u(t),\qquad b\in\mathbb{R}$$

$u(t)$, çarpıldığı fonksiyonun $t<0$ kısmını siler ve işareti $t=0$'dan başlatır. Bu yüzden işaret nedenseldir. $e^{-bt}$ kısmı $b$'nin değerine göre sönümlenerek de artarak da gidebilir. Slayttaki baloncukta belirtildiği gibi FT çalışılırken $b>0$ kısıtı gerekiyordu, çünkü işaretin sönümlenmesi ve altta kalan alanın sonlu olması gerekiyordu. LT'de bu kısıt gerekmez.

### 4.2 Hesap

Tanımda yerine konursa, $u(t)$ yüzünden $t<0$ kısmı sıfırdır ve integralin alt sınırı $0$ olur:

$$X(s)=\int_0^\infty e^{-bt}e^{-st}\,dt=\int_0^\infty e^{-(s+b)t}\,dt$$

Hoca bunun kolay bir integral olduğunu söyledi: üsteki $t$'nin katsayısının tersi dışarı çıkar.

$$X(s)=\frac{-1}{s+b}\Big[e^{-(s+b)t}\Big]_{t=0}^{t=\infty}=\frac{-1}{s+b}\Big[\lim_{t\to\infty}e^{-(s+b)t}-1\Big]$$

$t=0$ konduğunda üstel 1 olur. Asıl soru $t\to\infty$ limitidir. Slayttaki uyarıya göre bu limit yakınsamıyorsa integral "yoktur"; bu yüzden integralin hangi koşulda var olduğunu bulmak gerekir.

### 4.3 Limitin incelenmesi

Limitin içindeki ifade açılır (ekrandan, 00:35:00):

$$e^{-(s+b)t}=e^{-[(\sigma+b)+j\omega]t}=e^{-(\sigma+b)t}\,e^{-j\omega t}$$

$e^{-j\omega t}$ kısmı karmaşık bir sinüzoittir. Hoca bu kısmın ortalamasının sıfır olduğunu, bu yüzden dikkatin $e^{-(\sigma+b)t}$ kısmına çevrilmesi gerektiğini söyledi. Slayttaki iki davranış:

- $\sigma+b>0$, yani $\sigma>-b$ ise üstel giderek sönümlenir; limit sıfırdır ve altta kalan alan toplanabilir.
- $\sigma+b<0$, yani $\sigma<-b$ ise üstün başındaki eksiyle birlikte üs pozitif olur; ifade $t$ ilerledikçe büyür ve integral yoktur.

> **Ders sonrası not:** Belirleyici olan, $e^{-j\omega t}$'nin ortalamasının sıfır olması değil, büyüklüğünün her $t$ için $|e^{-j\omega t}|=1$ olmasıdır. Bu yüzden $|e^{-(s+b)t}|=e^{-(\sigma+b)t}$ olur ve limitin sıfıra gidip gitmediğini yalnız $\sigma+b$'nin işareti belirler.

### 4.4 Sonuç ve ROC

Böylece (ekrandan, 00:40:00):

$$x(t)=e^{-bt}u(t)\quad\Longrightarrow\quad X(s)=\frac{1}{s+b},\qquad \operatorname{Re}\{s\}>-b$$

$\operatorname{Re}\{s\}$, $s$'nin gerçel kısmı yani $\sigma$'dır. Hoca, Laplace dönüşümü verilirken sonucun yanına mutlaka bir şart da yazılması gerektiğini vurguladı: bir dönüşüm sonucu, bir de onun nerede yakınsadığını gösteren belirteç. Bu belirteç yakınsama bölgesinin tanımıdır. Slayttaki notta ROC için şimdilik çok endişelenmemek gerektiği, bu düzeyde kendiliğinden hallolduğu yazıyordu. Slayt ayrıca bu sonucun ve birçok benzerinin Laplace dönüşüm tablosunda bulunduğunu belirtir; hoca gerektiğinde tabloya bakılabileceğini söyledi.

### 4.5 $b>0$ ve $b<0$ durumları

Slayt iki durumu s düzleminde gösterir (ekrandan, 00:40:00 ve 00:45:00):

- **$b>0$:** $x(t)$ kendiliğinden sönümlenir. $-b$ negatiftir (örneğin $b=3$ ise $-b=-3$ ve işaret $e^{-3t}$). ROC, $\sigma=-b$ dikey çizgisinin sağında kalan bölgedir ve $j\omega$ eksenini içerir. Bu durumu FT de LT de çözebilir.
- **$b<0$:** $x(t)$ "patlar", yani üstel olarak büyür. $-b$ pozitiftir. ROC yine $\sigma=-b$ çizgisinin sağıdır, ama bu çizgi artık sanal eksenin sağında olduğu için ROC $j\omega$ eksenini içermez. Bu durumu FT çözemez; LT ise yalnız ROC içindeki $s$ değerlerine odaklanarak çözer.

> **Ders sonrası not:** Hoca s düzlemindeki çizimi anlatırken (00:43:00 civarı) "$\sigma$'nın $-b$'den küçük olduğu kısımlar çözümün olduğu kısımlardır" dedi. Hesaptan ve slayttan çıkan sonuç $\sigma>-b$'dir; ROC, $\sigma=-b$ çizgisinin sağındaki bölgedir.

## 5. Fourier dönüşümü ile Laplace dönüşümü arasındaki bağlantı

FT'de $e^{-j\omega t}$, LT'de $e^{-st}$ vardır. $s=\sigma+j\omega$'da $\sigma=0$ konursa iki tanım aynı olur. Ancak bunun geçerli olması için ROC'un $j\omega$ eksenini, yani $\sigma=0$ doğrusunu içermesi gerekir. ROC bu ekseni içermiyorsa $\sigma=0$ koymak FT'yi vermez; iki dönüşüm o durumda eşit değildir.

ROC $j\omega$ eksenini içerdiğinde FT, LT'nin içine gömülüdür. Hoca bunu üç boyutlu $|X(s)|$ çiziminin bir bıçakla $j\omega$ ekseni boyunca kesilmesine benzetti: bu kesit tam olarak FT'de bulunan eğridir. $\sigma=1$ gibi başka bir değerde kesit alınsaydı daha basık, tepe noktası farklı bir eğri elde edilirdi.

Ara verildikten sonra hoca ilk örneğe döndü (ekrandan, 00:50:00):

$$x(t)=e^{-bt}u(t)\leftrightarrow X(s)=\frac{1}{s+b},\quad \operatorname{Re}\{s\}>-b$$

$b>0$ ise ROC $j\omega$ eksenini içerir ve

$$X(s)\Big|_{s=j\omega}=\left[\frac{1}{s+b}\right]_{s=j\omega}=\frac{1}{j\omega+b}$$

bulunur. Bu, Fourier dönüşüm tablosundaki sonucun aynısıdır.

Ardından ters Laplace dönüşümüne kısa bir giriş yapıldı. Tanımdaki ters dönüşüm $s$ karmaşık olduğu için karmaşık bir çizgi integrali gerektirir; hoca bunun matematikte ayrı ve zor bir konu olduğunu söyledi. Bunun yerine $X(s)$ belli bir biçimde, payı $M$'inci, paydası $N$'inci dereceden iki polinomun oranı olarak verilmişse, kısmi kesirlere ayırıp bilinen dönüşüm çiftlerini tersinden kullanarak $x(t)$'ye geçilir. Bu konuya özelliklerden sonra dönüldü (Bölüm 8).

## 6. İki taraflı Laplace dönüşümünün özellikleri

FT ile LT arasındaki bağlantı nedeniyle FT özelliklerinin çoğu burada da korunur. Slaytta, diğer özelliklerin Laplace dönüşümü özellikleri tablosunda listelendiği belirtilir (ekrandan, 01:05:00 ve 01:10:00).

### 6.1 Doğrusallık

$$ax(t)+by(t)\leftrightarrow aX(s)+bY(s)$$

İşaretler katsayılarla çarpılıp toplandığında dönüşümleri de aynı katsayılarla toplanır.

### 6.2 Zamanda öteleme

Slayttaki şekiller nedensel bir işaret için çizilmiştir, ama sonuç geneldir:

$$x(t-c)\leftrightarrow e^{-cs}X(s)$$

$\sigma$ sıfırlanırsa çarpan $e^{-j\omega c}$ olur; FT'deki öteleme özelliğinde gelen çarpan budur.

### 6.3 Zamanda türev ve integral

Zamanda türev almak ($\frac{d}{dt}x(t)$) Laplace domeninde $X(s)$'i $s$ ile çarpmak demektir. Zamanda integral almak ise $X(s)$'i $1/s$ ile çarpmaya, yani $s$'ye bölmeye karşılık gelir. Hoca bunun özellikle devre teorisindeki analizlerde ve sistem blok diyagramlarının hazırlanmasında işe yaradığını, ama bu dersin kapsamına alınmadığını söyledi.

### 6.4 Zamanda ölçekleme

$$x(at)\leftrightarrow\frac{1}{a}X\!\left(\frac{s}{a}\right),\qquad a>0$$

Ölçekleme ile işaret sıkıştırılıp genişletilebilir (hoca bunu aşağı ve yukarı örneklemeye benzetti). $1/a$ çarpanı genliği etkiler. Slayttaki nota göre $a<0$ olursa, örneğin $a=-1$ için $x(-t)$, işaretin negatif zamana taşınması nedeniyle $x(at)$ nedensel olmayan bir işaret olur; bu yüzden $a>0$ ile sınırlanır.

### 6.5 $t^n$ ile çarpma

$$t^n x(t)\leftrightarrow(-1)^n\frac{d^n}{ds^n}X(s)$$

### 6.6 Üstelle çarpma

$$e^{at}x(t)\leftrightarrow X(s-a),\qquad a\ \text{gerçel ya da karmaşık}$$

Bir üstelle çarpmak s düzleminde ötelemeye yol açar.

### 6.7 Sinüzoitle çarpma

$$x(t)\sin(\omega_0 t)\leftrightarrow\frac{j}{2}\Big[X(s+j\omega_0)-X(s-j\omega_0)\Big]$$

Kosinüsle çarpma da benzer bir ifade verir (slaytta altta kısmen görünüyor). Saf bir sinüs ya da kosinüsle çarpmak, $X(s)$'te $j\omega$ yönünde frekans kaydırmalarına yol açar.

## 7. Konvolüsyon ve transfer fonksiyonu

Hoca sistem modeline geri döndü: $x(t)$ bir kutudan geçer ve $y(t)$ oluşur; kutuda $h(t)$ vardır. Sürekli zamanda çıkış konvolüsyon integraliyle, ayrık zamanda ayrık konvolüsyonla bulunuyordu. Fourier tarafında zamandaki konvolüsyon frekansta çarpmaya dönüşüyordu:

$$Y(\omega)=H(\omega)X(\omega),\qquad H(\omega)=\frac{Y(\omega)}{X(\omega)}$$

Zamanda konvolüsyon işlemsel olarak çok zaman alabilir. Frekansa geçip basit bir çarpma yapmak, sonra zamana dönmek daha kolaydır. $h(t)$'nin frekanstaki karşılığı $H(\omega)$, sistemin frekans cevabıdır.

Laplace tarafında da aynısı geçerlidir: zamandaki konvolüsyon s düzleminde basit bir çarpmaya dönüşür.

$$Y(s)=H(s)X(s)$$

Buradaki $H(s)$'ye **transfer fonksiyonu** denir.

> **Hocanın vurgusu:** Transfer fonksiyonu, frekans cevabının genelleştirilmiş hâlidir.

Slaytlarda bundan sonra diferansiyel denklemlerle tanımlanan sistemlerin ve devre teorisine uyarlanmış hâlinin anlatıldığı bir bölüm vardı. Hoca bu kısmı atladı ve dersin kapsamı dışında bıraktı.

## 8. Ters Laplace dönüşümü ve kısmi kesirlere ayırma

### 8.1 Fikir

$X(s)$ verildiğinde $x(t)$'yi bulmak istenir. Slayttaki açıklamaya göre ters Laplace dönüşümü bulunurken iki polinomun karmaşık bir oranını, Laplace dönüşüm tablosunda bulunan biçimlere ayırabilmek çok yararlıdır (ekrandan, 01:15:00). Örnek:

$$\mathcal{L}^{-1}\left\{\frac{1/RC}{(s+1/RC)s}\right\}=\mathcal{L}^{-1}\left\{\frac{1}{s}-\frac{1}{s+1/RC}\right\}=\mathcal{L}^{-1}\left\{\frac1s\right\}-\mathcal{L}^{-1}\left\{\frac{1}{s+1/RC}\right\}=u(t)-e^{-t/RC}u(t)$$

İlk adım dönüşümü daha basit biçimlere ayırmak, ikincisi LT'nin doğrusallığını kullanmaktır. Bu örnekte ayırma göz kararıyla yapılabiliyor; genelde ise "kısmi kesirlere ayırma" (partial fraction expansion, PFE) yöntemi kullanılır.

### 8.2 Ters yönden bakış: doğrudan terim

Slayt önce tersini gösterir (ekrandan, 01:20:00):

$$Y(s)=\frac{2}{s+3}+\frac{4}{s+5}+2$$

Bu ifadenin kutupları $s=-3$ ve $s=-5$'tir. Sondaki sabit $2$ gibi bir terime **doğrudan terim** (direct term) denir. Ortak paydada birleştirilirse tek bir polinom oranı elde edilir; payda $s^2+8s+15$'tir. Amaç, bu birleşik hâlden başlayıp toplamlı hâle geri dönmektir. Hoca genel biçimi slayta yazdı: pay $b_Ms^M+b_{M-1}s^{M-1}+\dots$, payda $a_Ns^N+a_{N-1}s^{N-1}+\dots$ Böyle bir oran $Y(s)$, $X(s)$ ya da $H(s)$ olabilir ve sırasıyla $y(t)$, $x(t)$, $h(t)$'ye götürür.

> **Ders sonrası not:** Slayttaki birleşik ifadenin payı $2s^2+22s+47$ olarak yazılıydı. Açılınca $2(s+5)+4(s+3)+2(s+3)(s+5)=2s^2+22s+52$ çıkar (python ile kontrol edildi). Slayttaki 47 büyük olasılıkla yazım hatasıdır; payda $s^2+8s+15$ doğrudur.

Hoca, kısmi kesirlere ayırmanın amacını şöyle özetledi: polinomları olabildiğince basit toplamlı biçimlere getirmek, çünkü örneğin $\dfrac{1}{s+a}$'nın tersinin $e^{-at}u(t)$ olduğu bilinir. Ters dönüşümü bilinen çiftlerden yararlanılır. Paydanın derecesi payınkinden büyükse doğrudan terim oluşmaz.

### 8.3 Basit kutuplu örnek

Derste çözülen örnekte (paydası ekranda $(s+1)(s+2)$ olarak görünen, payı altyazıda $3s-1$ olarak geçen) ifade:

$$Y(s)=\frac{3s-1}{(s+1)(s+2)}=\frac{R_1}{s+1}+\frac{R_2}{s+2}$$

$R_1$ ve $R_2$ sabitlerine **rezidü** denir. Hoca bulma yolunu adım adım gösterdi:

- $R_1$ için iki taraf $(s+1)$ ile çarpılır. Sol tarafta $(s+1)$ sadeleşir: $\dfrac{3s-1}{s+2}=R_1+R_2\dfrac{s+1}{s+2}$. $s=-1$ konursa sağdaki ikinci terim sıfır olur: $R_1=\dfrac{3(-1)-1}{-1+2}=-4$.
- $R_2$ için iki taraf $(s+2)$ ile çarpılır ve $s=-2$ konur: $R_2=\dfrac{3(-2)-1}{-2+1}=\dfrac{-7}{-1}=7$ (ara adım eklendi).

Sonra her terim tablodan geri çevrilir. Dersin başındaki örnekte $b=1$ alınırsa $e^{-t}u(t)\leftrightarrow\dfrac{1}{s+1}$ olur; benzer biçimde $e^{-2t}u(t)\leftrightarrow\dfrac{1}{s+2}$. Doğrusallık nedeniyle katsayılar önlerine aynen gelir (ekrandan, 01:25:00):

$$y(t)=\mathcal{L}^{-1}\left\{\frac{-4}{s+1}\right\}+\mathcal{L}^{-1}\left\{\frac{7}{s+2}\right\}=-4e^{-t}u(t)+7e^{-2t}u(t)$$

Rezidüler python ile kontrol edildi: $R_1=-4$, $R_2=7$.

## 9. Sıfırlar, kutuplar ve kutup-sıfır çizimi

### 9.1 Tanımlar

Transfer fonksiyonu genel olarak iki polinomun oranıdır:

$$H(s)=\frac{B(s)}{A(s)}=\frac{b_Ms^M+\dots+b_1s+b_0}{a_Ns^N+\dots+a_1s+a_0}$$

Paydadaki $A(s)$'ye **karakteristik polinom** denir. Amaç, oranı çarpanlarına ayrılmış biçime getirmektir:

$$H(s)=b_M\frac{(s-z_1)(s-z_2)\cdots(s-z_M)}{(s-p_1)(s-p_2)\cdots(s-p_N)}$$

Bu biçimde pay ve paydadaki ortak çarpanlar sadeleşebilir. $s$ yerine $z_i$'lerden biri konursa pay sıfırlanır ve $H(s)=0$ olur; bu yüzden $B(s)$'nin kökleri olan $z_i$'lere **sıfırlar** (zeros) denir ve $M$ tane olabilir. $s$ yerine $p_i$'lerden biri konursa $H(s)$ sonsuza gider; karakteristik polinomun kökleri olan $p_i$'lere **kutuplar** (poles) denir. Önde kalan $b_M$ katsayısı bir kazanç (yükseltme) gibi davranır. Hoca birinci dereceden bir pay örneğinde de aynı mantığı gösterdi: $b_1s+b_0$'ı $b_1$'e bölünce $s+b_0/b_1$ kalır ve sıfır $-b_0/b_1$ olur.

Sıfırlar ve kutuplar biliniyorsa $H(s)$'in nasıl davranacağı bilinir.

### 9.2 Kutup-sıfır çizimi

Kutup-sıfır çizimi (pole-zero plot) sistemin davranışının grafik bir görünümüdür. Slayttaki örnek (ekrandan, 01:30:00):

$$H(s)=\frac{2s^2+12s+20}{s^3+6s^2+10s+8}=\frac{2(s+3-j)(s+3+j)}{(s+4)(s+1-j)(s+1+j)}$$

- Sıfırlar: $s=-3+j$ ve $s=-3-j$.
- Kutuplar: $s=-4$, $s=-1+j$ ve $s=-1-j$.

Katsayılar gerçel olduğu için karmaşık kökler eşlenik çiftler hâlinde gelir. Çizimde sıfırlar yuvarlak (o), kutuplar çarpı (×) ile gösterilir. $-4$'teki kutup gerçel eksen üzerinde, diğerleri ondan yukarıda ve aşağıda yer alır. Kökler python ile kontrol edildi.

Hoca, s düzleminde aslında $|H(s)|$ değerlerinin çizildiğini hatırlattı. Üç boyutlu çizimde $|H(s)|$ yüzeyi sıfırlarda sıfıra iner, kutuplarda ise sonsuza yükselir. Bu çizim sistemin matematiksel modelini gözde canlandırmayı sağlar. ROC $j\omega$ eksenini içeriyorsa, bu yüzeyden $j\omega$ boyunca alınan kesit frekans cevabını verir.

Ardından hoca bu slayt takımının sonundaki Laplace dönüşüm tablosunu gösterdi: $u(t)\leftrightarrow\dfrac{1}{s}$, $e^{-bt}u(t)\leftrightarrow\dfrac{1}{s+b}$ ($b$ gerçel ya da karmaşık), $\delta(t)\leftrightarrow1$, $u(t)-u(t-c)$ ve sinüsle çarpılmış işaretlerin dönüşümleri ve özellikler tablosu.

## 10. İkinci slayt takımı ve kitaptan örnekler

### 10.1 M. J. Roberts slaytları

Hoca, Laplace dönüşümünü farklı bir tarzda anlatan ikinci bir slayt takımını (M. J. Roberts) da gösterdi. Bu slaytlar $e^{-\sigma t}$ teriminin işareti nasıl sönümlendirip integrallenebilir hâle getirdiğini ve yakınsama bölgesini daha ayrıntılı anlatır. Dönüşüme adını veren Pierre-Simon Laplace bir Fransız matematikçidir.

Bu slaytlardaki örnek (ekrandan, 01:35:00): $x(t)=e^{-t}u(t)+e^{2t}u(-t)$.

- $e^{-t}u(t)\leftrightarrow\dfrac{1}{s+1}$, $\sigma>-1$. Burada $b=1$'dir.
- $e^{2t}u(-t)\leftrightarrow-\dfrac{1}{s-2}$, $\sigma<2$. İşaret ters çevrildiği için ($u(-t)$) dönüşümün önüne eksi gelir ve ROC'un yönü değişir. Hoca bunun henüz türetilmediğini, tablodan bakılabileceğini söyledi.
- Toplam: $\dfrac{1}{s+1}-\dfrac{1}{s-2}$, ROC $-1<\sigma<2$. İki ROC'un kesişimi slaytta gri gösterilen dikey şerittir.

Ortak paydaya getirilince $s$'ler sadeleşir:

$$X(s)=\frac{(s-2)-(s+1)}{(s+1)(s-2)}=\frac{-3}{(s+1)(s-2)}$$

Bu ifadenin sıfırı yoktur, iki kutbu vardır. Kutuplar dışında, ROC içinde dönüşüm belli bir değere yakınsar.

> **Ders sonrası not:** Hoca kutupları "$-1$'de ve $-2$'de" diye söyledi. Paydadaki $(s+1)(s-2)$ çarpanlarından kutuplar $s=-1$ ve $s=2$'dir; slaytta da $s=-1$ ve $s=2$ işaretlidir. Sonuç, sayısal integralle ($s=0{,}5$ için) python'da kontrol edildi.

Slaytların devamında ROC'ların nasıl çizildiği, kutup ve sıfırların nasıl bulunduğu, özelliklerin ispatlı ve şekilli anlatımı ve kısmi kesir yöntemleri vardır. Hoca özellikle ters dönüşüm yöntemlerinin gözden geçirilmesini tavsiye etti. Slaytta unilateral (tek taraflı) Laplace dönüşümü de vardı; hoca buna çok girmedi, yalnız integralin sıfırdan sonsuza alındığını ve özellikle nedensel sistemlerde kullanıldığını hatırlattı.

Bu slaytlardaki temel çiftler:

- Birim impuls: $\mathcal{L}\{\delta(t)\}=\displaystyle\int_{-\infty}^{\infty}\delta(t)e^{-st}dt=1$. İmpuls yalnız $t=0$'da değer aldığı için $e^{-s\cdot0}=1$ olur. ROC bütün $s$ değerleridir.
- Birim basamak: $\mathcal{L}\{u(t)\}=\displaystyle\int_0^\infty e^{-st}dt=\frac{1}{s}$, $\operatorname{Re}\{s\}>0$.
- Ters çevrilmiş basamak: $-u(-t)\leftrightarrow\dfrac1s$, $\operatorname{Re}\{s\}<0$.
- $t$ ile çarpılmış basamak: $tu(t)\leftrightarrow\dfrac{1}{s^2}$.

Gösterim: Laplace dönüşümü $\mathcal{L}\{x(t)\}=X(s)$, tersi $\mathcal{L}^{-1}\{X(s)\}=x(t)$ biçiminde yazılır.

Kısmi kesir yöntemlerinde basit kutuplu (simple pole) durumun yanında, paydada $(s-p)^2$ gibi tekrarlanan bir çarpan bulunan katlı kutuplu (multiple pole) durum için ayrı bir formül vardır. Hoca bu kadar derinlemesine bir çözüm beklemediğini, basit polinomsal çözümlerin yeterli olduğunu söyledi.

### 10.2 Schaum kitabından örnekler

Hoca son olarak Schaum serisinin "Signals and Systems" kitabının Laplace dönüşümü bölümünü açtı (ekrandan, 01:40:00). Kitapta $x(t)=e^{-at}u(t)$ ($a$ gerçel) için

$$X(s)=\int_{0^+}^{\infty}e^{-(s+a)t}dt=\frac{1}{s+a},\qquad\operatorname{Re}\{s\}>-a$$

bulunur, çünkü $\lim_{t\to\infty}e^{-(s+a)t}=0$ ancak $\operatorname{Re}\{s+a\}>0$ iken sağlanır. ROC, $\operatorname{Re}\{s\}=-a$ çizgisinin sağındaki taralı alandır. Örnek 3.2'de ise $x(t)=-e^{-at}u(-t)$ için $X(s)=\dfrac{1}{s+a}$, $\operatorname{Re}\{s\}<-a$ bulunur. İki işaretin cebirsel ifadeleri aynıdır, yalnız ROC'ları farklıdır. Bu yüzden kitabın vurguladığı gibi Laplace dönüşümünün her işaret için tek olması için ROC dönüşümün bir parçası olarak verilmelidir.

Hoca sol taraflı işaretin dönüşümünü tahtada tanım formülünden başlayarak türetti (ekrandan, 01:45:00 ve 01:55:00). Tanım hatırlatıldı: $X(s)=\int_{-\infty}^{\infty}x(t)e^{-st}dt$; "Laplace denince akla gelmesi gereken formül budur." Ayrıntılı çözüm Örnek Sorular bölümündedir (Soru 1 ve Soru 2). Çözümden çıkan kural şudur: üstelin sınırda ($t\to\infty$ ya da $t\to-\infty$) sonsuza gitmemesi için gereken koşul ROC'u belirler.

> **Hocanın vurgusu:** Laplace dönüşümünde bir dönüşüm değeri vardır, bir de onun nerede yakınsadığı vardır; ikincisi de mutlaka belirtilmelidir. Hoca sağ taraflı ve sol taraflı iki çözümün herkes tarafından mutlaka yapılmasını istedi.

Ardından kitabın 3.5 numaralı problemine geçildi (ekrandan, 01:50:00). Bunlar da Örnek Sorular bölümündedir (Soru 3).

Hoca bilinmesini istediği soru tiplerini şöyle sıraladı: temel işaretlerin dönüşümünü bilmek, ROC sınırlarını tablodan bulmak, ayrı ayrı bulunan dönüşümleri birleştirip ROC bölgesini, sıfırları ve kutupları s düzleminde çizmek, ters Laplace dönüşümüyle $x(t)$'yi bulmak. Kitabın ilgili bölümünün sonunda çok sayıda çözümlü soru olduğunu, ters dönüşüm sorularına da bakılmasını önerdi.

## Örnek Sorular

**Soru 1** (ekrandan, 01:45:00 ve 01:55:00): $x(t)=-e^{-at}u(-t)$ işaretinin Laplace dönüşümünü ve ROC'unu bulun (Schaum 3.1(a)).

$u(-t)$, işareti $t\le0$ ile sınırlar; integral $-\infty$'dan $0$'a alınır:

$$X(s)=-\int_{-\infty}^{0}e^{-at}e^{-st}dt=-\int_{-\infty}^{0}e^{-(s+a)t}dt=\frac{1}{s+a}\Big[e^{-(s+a)t}\Big]_{-\infty}^{0}$$

Hoca ilkel fonksiyonu $-\dfrac{1}{s+a}e^{-(s+a)t}$ olarak yazdı; önündeki eksi, integralin önündeki eksiyi götürür. $t=0$ konduğunda üstel 1 olur. $t\to-\infty$'da $-(s+a)t=(s+a)\cdot\infty$ biçimindedir; bunun sıfıra gitmesi için $\operatorname{Re}\{s+a\}<0$ olmalıdır. Sonuç:

$$-e^{-at}u(-t)\leftrightarrow\frac{1}{s+a},\qquad\operatorname{Re}\{s\}<-a$$

**Soru 2** (ekrandan, 01:45:00 ve 01:55:00): $x(t)=e^{at}u(-t)$ işaretinin Laplace dönüşümünü ve ROC'unu bulun (Schaum 3.1(b)).

$$X(s)=\int_{-\infty}^{0}e^{at}e^{-st}dt=\int_{-\infty}^{0}e^{-(s-a)t}dt=-\frac{1}{s-a}\Big[e^{-(s-a)t}\Big]_{-\infty}^{0}$$

$t=0$ için üstel 1'dir ve ilk terim $-\dfrac{1}{s-a}$ olur. $t\to-\infty$'da üs $+(s-a)\infty$ biçimindedir. $\operatorname{Re}\{s-a\}>0$ olsaydı ifade sonsuza giderdi ve belli bir toplam olmazdı; bu yüzden $\operatorname{Re}\{s\}-a<0$ olmalıdır. Sonuç:

$$e^{at}u(-t)\leftrightarrow-\frac{1}{s-a},\qquad\operatorname{Re}\{s\}<a$$

**Soru 3** (ekrandan, 01:50:00): Aşağıdaki işaretlerin $X(s)$ dönüşümünü bulun ve kutup-sıfır çizimini ROC ile birlikte çizin (Schaum 3.5).

(a) $x(t)=e^{-2t}u(t)+e^{-3t}u(t)$

Tablodan $e^{-2t}u(t)\leftrightarrow\dfrac{1}{s+2}$, $\operatorname{Re}\{s\}>-2$ ve $e^{-3t}u(t)\leftrightarrow\dfrac{1}{s+3}$, $\operatorname{Re}\{s\}>-3$. Toplam:

$$X(s)=\frac{1}{s+2}+\frac{1}{s+3}=\frac{2s+5}{(s+2)(s+3)}=\frac{2\left(s+\frac52\right)}{(s+2)(s+3)}$$

Hoca baştaki $2$'nin genel biçimdeki $b_M$ katsayısı olduğunu gösterdi. ROC iki bölgenin kesişimidir: $\operatorname{Re}\{s\}>-2$. Sıfır $s=-2{,}5$'te, kutuplar $s=-2$ ve $s=-3$'tedir. Hoca bunu "sizden çizmenizi istediğim karakteristik bu" diye vurguladı. Sonuç sayısal integralle kontrol edildi.

(b) $x(t)=e^{-3t}u(t)+e^{2t}u(-t)$

Hoca bu şıkta ROC'u ve kutupları kısaca gösterdi; ayrıntılı birleştirme ekrandaki kitabın çözümündeydi.

<!-- BELİRSİZ: 01:51:57-01:56:06 arası altyazı bozuk; hocanın bu şıkta söylediği sınır ve kutup değerleri ("2'den büyük, eksi 3'den küçük", "eksi 2 ve 3") net değil. Aşağıdaki değerler kitaptaki tanımdan ve hesaptan alındı. -->

> **Çözüm (derste verilmedi):** $e^{-3t}u(t)\leftrightarrow\dfrac{1}{s+3}$, $\operatorname{Re}\{s\}>-3$; $e^{2t}u(-t)\leftrightarrow-\dfrac{1}{s-2}$, $\operatorname{Re}\{s\}<2$ (Soru 2'de $a=2$). Toplam $X(s)=\dfrac{1}{s+3}-\dfrac{1}{s-2}=\dfrac{-5}{(s+3)(s-2)}$, ROC $-3<\operatorname{Re}\{s\}<2$. Sıfır yoktur; kutuplar $s=-3$ ve $s=2$'dir. Sonuç $s=0$ için sayısal integralle python'da kontrol edildi.

(c) $x(t)=e^{2t}u(t)+e^{-3t}u(-t)$

> **Çözüm (derste verilmedi):** $e^{2t}u(t)\leftrightarrow\dfrac{1}{s-2}$ için $\operatorname{Re}\{s\}>2$, $e^{-3t}u(-t)\leftrightarrow-\dfrac{1}{s+3}$ için $\operatorname{Re}\{s\}<-3$ gerekir. Bu iki bölgenin kesişimi boştur; bu yüzden $x(t)$'nin Laplace dönüşümü yoktur.

**Soru 4** (ekrandan, 01:25:00): $Y(s)=\dfrac{3s-1}{(s+1)(s+2)}$ ise $y(t)$'yi bulun.

Çözüm derste verildi (Bölüm 8.3): $R_1=-4$, $R_2=7$ ve $y(t)=-4e^{-t}u(t)+7e^{-2t}u(t)$.

## Dersin Toparlaması

Bu derste Laplace dönüşümü, sürekli zamanlı Fourier dönüşümünün genelleştirilmiş hâli olarak tanıtıldı. $e^{-j\omega t}$ yerine $e^{-st}$, $s=\sigma+j\omega$ kullanılınca eklenen $e^{-\sigma t}$ çarpanı integrandı sönümlendirir. Böylece mutlak integrallenebilir olmayan, hatta üstel olarak büyüyen işaretler de incelenebilir. Bunun karşılığında her dönüşüm, integralin var olduğu $s$ değerlerini gösteren yakınsama bölgesiyle birlikte verilmelidir. Sağ taraflı işaretlerde ROC bir sınırın sağında, sol taraflı işaretlerde solundadır; iki taraflı işaretlerde ise iki bölgenin kesişimi olan dikey bir şerittir. ROC $j\omega$ eksenini içeriyorsa $s=j\omega$ konarak Fourier dönüşümü elde edilir. Özellikler (doğrusallık, öteleme, türev/integral, ölçekleme, üstelle ve sinüzoitle çarpma) FT'dekilere benzer. Zamandaki konvolüsyon s düzleminde çarpmaya dönüşür ve $H(s)$ transfer fonksiyonu frekans cevabını genelleştirir. Ters dönüşüm, rasyonel $X(s)$ kısmi kesirlere ayrılıp tablo çiftleri tersinden kullanılarak bulunur. Sıfırlar ve kutuplar da kutup-sıfır çiziminde gösterilir.

Bir sonraki derste aynı genelleştirme ayrık zaman tarafında yapılacak: DTFT'nin genelleştirilmiş hâli olan z dönüşümü işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
