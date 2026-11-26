# Ders 4 Genişletilmiş Notu: Karmaşık İşaretler, Sinüzoitler, Temel İşaretler, Dürtü Fonksiyonu ve Sistemlere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: İşlem Sırası ve Periyodik İşaretler
- 2. Karmaşık İşaretler
- 3. Karmaşık Sayıların Gözden Geçirilmesi
- 4. Kutupsal Biçim ve Euler Bağıntısı
- 5. İşaretin Enerjisi ve Gücü
- 6. Sinüzoidal İşaretler
- 7. Karmaşık Sinüzoitler
- 8. Üstel İşaretler ve Sönümlü/Büyüyen Sinüzoitler
- 9. Ayrık Zamanlı Karmaşık Üstellerin Periyodikliği
- 10. Temel İşaretler: Basamak, Dikdörtgen, Rampa, Üçgen
- 11. Temel İşaretlerden Karmaşık İşaret Kurmak: Darbeli Doppler Dalga Biçimi
- 12. Dürtü (Delta) Fonksiyonu
- 13. Dürtülerin İntegrali ve Süreksiz Fonksiyonların Türevi
- 14. Sistemlere Giriş
- 15. MATLAB ile Karmaşık Üstel İşaretin Çizimi
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: İşlem Sırası ve Periyodik İşaretler

Ders, "Signals and Systems Properties" başlıklı üçüncü slayt dizisinin kaldığı yerden devam etti. Önce geçen haftanın konuları hatırlatıldı: işaretlerin sınıflandırılması, sürekli ve ayrık zamanlı işaretler, genlikte ölçekleme, zamanda ölçekleme, zamanda tersleme ($t \to -t$) ve zamanda öteleme ($n - n_1$, $n + n_1$ durumları).

### 1.1 Ölçekleme ve Ötelemenin Birlikte Uygulanması

Bu işlemler birleştirilebilir, ama sıraya dikkat etmek gerekir. Slayttaki örnek $x(2(t-1))$ idi (ekrandan, 00:10:00):

- **Önce öteleme, sonra ölçekleme (yanlış yol):** $x(t)$ önce 1 birim ötelenip $x(t-1)$ elde edilir, sonra 2 ile sıkıştırılırsa sonuç $x(2t-1)$ olur; bu $x(2(t-1))$ değildir. Slaytta bu yol "Incorrect" diye işaretli.
- **İfadeyi açıp öteleme, sonra ölçekleme (doğru yol):** $x(2(t-1)) = x(2t-2)$ yazılır. Önce 2 birim ötelenip $x(t-2)$, sonra 2 ile sıkıştırılıp $x(2t-2)$ elde edilir. Slaytta "Correct" diye işaretli.
- **Önce ölçekleme, sonra öteleme:** Önce $x(2t)$ elde edilir, sonra $t$ yerine $t-1$ konur; bu da doğru sonucu verir.

Slaytın sonundaki soru, $2(t-1)$ ifadesinin nerede sıfır olduğuydu; bu nokta, $x(t)$'nin tepe noktasının yeni işarette nereye taşındığını gösterir.

### 1.2 Periyodik İşaretlerde Tek Periyodun Yeterliliği

Bir işaret periyodikse onu $(-\infty, +\infty)$ aralığında incelemeye gerek yoktur; bir periyodunun incelenmesi işaretin tamamı hakkında bilgi verir ve gereksiz işlem yükünden kurtarır. Hoca bunun ileride dönüşümlerde çok karşımıza çıkacağını söyledi: integral ya da toplam sembolünün sınırları $-\infty$ ile $+\infty$ olarak yazılacak, ama işaret periyodikse (örneğin bir periyodu 2'de başlayıp 5'te bitiyorsa) yalnız o aralığın incelenmesi yetecek.

Benzer biçimde, işaretin belli bir aralıkta sıfır olduğu biliniyorsa o aralıkta integral almaya gerek yoktur. Ayrık zamanda toplam sembolü için de aynı şey geçerlidir: birazdan görülecek birim basamak $u[n]$, $n<0$ için 0, $n \ge 0$ için 1 değerini alır; bu yüzden toplam sınırları daralır ve çok daha basit bir toplam elde edilir.

> **Hocanın vurgusu:** Öğrenciler genelde $-\infty$ ile $+\infty$ sınırlarından korkar; oysa periyodiklik ve sıfır değerli aralıklar sınırları daraltır ve çözümü kolaylaştırır.

Periyodik olmayan işaretlerden periyodik işaret üretilip üretilemeyeceği sorusu ileriki haftaların konusu olarak bırakıldı.

## 2. Karmaşık İşaretler

Şu ana kadar görülen işaretlerin genlikleri gerçel (ya da tam sayı) değerliydi. Ama işaretler karmaşık da olabilir (ekrandan, 00:15:00):

$$z(t) = x(t) + j\,y(t)$$

Burada $x(t)$ ve $y(t)$ gerçel değerli işaretlerdir ve $j = \sqrt{-1}$'dir. Yani her an için bir dizi saklanır, ama dizinin iki elemanı vardır: bir gerçel değer, bir sanal değer.

Slayta göre karmaşık işaretler birçok problemde doğal olarak ortaya çıkar: sinüzoitlerin kullanışlı gösterimi, haberleşme, radar, sonar ve ultrason. Hoca, sinüzoidal işaretlerin de aslında karmaşık bileşenlerden oluştuğunu Euler formülüyle gösterdi:

$$e^{-j\omega_0 t} = \cos\omega_0 t - j\sin\omega_0 t, \qquad e^{j\omega_0 t} = \cos\omega_0 t + j\sin\omega_0 t$$

İki eşitlik taraf tarafa toplanırsa sanal kısımlar sadeleşir:

$$e^{j\omega_0 t} + e^{-j\omega_0 t} = 2\cos\omega_0 t \quad\Rightarrow\quad \cos\omega_0 t = \frac{e^{j\omega_0 t} + e^{-j\omega_0 t}}{2}$$

Yani herhangi bir kosinüs işareti karmaşık bileşenlerden oluşur.

Bunun pratik yararı ileride Fourier ve Laplace dönüşümlerinde görülecek. Orada $\int f(t)\,e^{-st}\,dt$ gibi integraller alınacak (Fourier'de $s = j\omega$). $f(t)$ bir sinüs ise, sinüsü üstel bir ifadeyle çarpıp integralini almak kısmi integrasyon (integration by parts) gerektirir. Sinüs Euler bağıntısıyla üstel biçimde yazılırsa kısmi integrasyona gerek kalmaz; doğrudan üstel fonksiyonun integrali alınarak sonuca ulaşılır.

## 3. Karmaşık Sayıların Gözden Geçirilmesi

Kartezyen biçimde karmaşık sayı $z = x + jy$ olarak yazılır (ekrandan, 00:20:00):

- $x = \Re z$: $z$'nin gerçel kısmı.
- $y = \Im z$: $z$'nin sanal kısmı.
- $x$ ve $y$'ye sırasıyla eş fazlı (in-phase) ve dik (quadrature) bileşen de denir.
- $j = \sqrt{-1}$ mühendislik gösterimidir; $i = \sqrt{-1}$ fizik, kimya ve matematikte kullanılır.

Karmaşık sayılar, gerçel sayılarda tanımlı olmayan $\sqrt{-4}$ gibi ifadelerden doğar. Hoca ekranda şöyle yazdı:

$$\sqrt{-4} = \sqrt{4}\cdot\sqrt{-1} = 2\sqrt{-1} = 2j$$

Hoca, bir sayının iki "özelliği" (gerçel ve sanal) olmasını programlamadaki iki alanlı bir yapıya (struct) benzetti.

### 3.1 Karmaşık Sayı Ne Anlama Gelir?

**Soru:** Karmaşık sayı nedir, ne anlam ifade eder, amacı nedir?

**Cevap:** Hoca ikinci dereceden denklemle açıkladı. $ax^2 + bx + c = 0$ denkleminin kökleri bulunurken diskriminant $\Delta = b^2 - 4ac$ hesaplanır. $\Delta \ge 0$ ise gerçel kök vardır, $\Delta < 0$ ise gerçel kök yoktur. Kökler $x_{1,2} = \dfrac{-b \pm \sqrt{\Delta}}{2a}$ formülüyle bulunur. $\Delta<0$ iken örneğin $2 \pm 2\sqrt{-1}$ gibi bir sonuç çıkar. $\sqrt{-1}$'in gerçel sayılarda karşılığı yoktur, ama bu yine de denklemin bir köküdür. Burada sayı kümesi genişletilir: gerçel sayıların dışında başka tür sayılar olduğu kabul edilir ve $\sqrt{-1}$ yerine $j$ yazılır. Bu bir gösterimdir, tıpkı kök işaretinin bir gösterim olması gibi. İleride çözümde bu kökün karesi ya da dördüncü kuvveti alınırsa $j$ ortadan kalkar ve gerçel bir sayıya ulaşılır ($j^2 = -1$, $j^4 = 1$).

Bazı uygulamalarda bu gösterim olduğu haliyle de anlam taşır. Hoca örnek olarak RLC devrelerindeki faz bilgisini verdi: sanal kısım faz açısını ifade eder ve sonuç "şu genlikte, şu derecelik faz farkıyla" diye yorumlanır. Radar örneğinde yoldaki bir cihaz sürekli işaret gönderir; işaret yaklaşan bir araca çarpıp güçlenerek, uzaklaşan bir araçtan ise zayıflayarak geri döner. Bu dönen işaretin analizinde karmaşık işaretler kullanılır. Ultrason görüntülemede de gönderilen ses işaretinin gerçel ve sanal bileşenleri vardır; geri yansıyan işaretlerden görüntü elde edilir. Damardaki kan akışının sesinden pıhtı (emboli) tespiti de karmaşık işaretlerin kullanıldığı bir uygulama olarak anıldı. Hoca, bu dersin kapsamında karmaşık sayıların bu kadarının bilinmesinin yeterli olduğunu söyledi.

## 4. Kutupsal Biçim ve Euler Bağıntısı

Karmaşık sayı kutupsal biçimde $z = re^{j\phi}$ olarak yazılır (ekrandan, 00:30:00):

- $r$: $z$'nin modülü ya da genliği, $r = \sqrt{x^2 + y^2}$.
- $\phi$: $z$'nin açısı ya da fazı.
- $\exp(j\phi) = \cos\phi + j\sin\phi$.

Karmaşık düzlemde yatay eksen gerçel kısmı ($Re$), düşey eksen sanal kısmı ($Im$) gösterir. $z = x + jy$ noktasına çizilen vektörün uzunluğu $r$, gerçel eksenle yaptığı açı $\phi$'dir.

Hocanın örneği $3 + 4j$ idi (ekranda $3+4i$ olarak yazıldı). Gerçel eksende 3, sanal eksende 4 birim gidilir. Hipotenüs Pisagor bağıntısından (3-4-5 üçgeni) $r = 5$, açı yaklaşık $53^\circ$'dir (arktanjant ile bulunabilir). Bu durumda aynı sayı

$$z = 5\,e^{j\,53^\circ}$$

olarak yazılabilir. Hoca, değişen şeyin yalnız gösterim olduğunu vurguladı.

Euler bağıntısında açı herhangi bir değişken olabilir; $\omega_0 t$ yerine $\alpha$ yazılırsa $e^{j\alpha} = \cos\alpha + j\sin\alpha$ olur. Ekranda $e^{j\omega_0 t} = \cos\omega_0 t + j\sin\omega_0 t$ yazıldı.

<!-- BELİRSİZ: Ekrandaki el yazısında sinüs teriminin önündeki j eksik yazılmış; hoca konuşmada eksikliği fark edip düzeltti. -->

Karmaşık üstel için slayttaki bağıntı:

$$e^{z} = e^{x + jy} = e^{x}e^{jy} = e^{x}(\cos y + j\sin y)$$

Slaytta karmaşık sayılarda toplama, çarpma ve bölmenin bilinmesi ve gösterimler arasında rahatça geçilebilmesi gerektiği yazıyor. Hoca ayrıca $\cos\theta + i\sin\theta$ ifadesi için kullanılan "cis" kısaltmasına ($\mathrm{cis}\,\theta$) değindi.

## 5. İşaretin Enerjisi ve Gücü

Slayttaki tanımlar şöyle (ekrandan, 00:35:00). Bir dirençten geçen akım $i(t)$ ise dirençte harcanan enerji

$$E_R = \lim_{T\to\infty}\int_{-T}^{T} i^2(t)\,R\,dt$$

olur ve birimi Joule'dür. $i(t)$ işaretinin enerjisi, $1\,\Omega$'luk dirençte harcanan enerji olarak tanımlanır:

$$E_i = \lim_{T\to\infty}\int_{-T}^{T} i^2(t)\,dt$$

Genel olarak (karmaşık olabilen) bir $x(t)$ işaretinin enerjisi:

$$E_x = \lim_{T\to\infty}\int_{-T}^{T} |x(t)|^2\,dt$$

Karenin yerine mutlak değerin karesi alınır; böylece karmaşık işaretler de kapsanır. Çoğu uygulamada bu gerçek bir enerji değildir, çünkü işaretlerin çoğu gerçekten $1\,\Omega$'luk bir dirence uygulanmaz. İşaret enerjisinin zamana göre ortalaması işaretin gücüdür (signal power).

- **Enerji işareti:** Enerjisi sonlu, gücü sıfırdır.
- **Güç işareti:** Gücü sonlu, enerjisi sonsuzdur.

Hoca, bir işaretin enerji işareti mi güç işareti mi olduğuna dair örneklerin ilerideki konularda yapılacağını söyledi.

## 6. Sinüzoidal İşaretler

Sinyaller ve sistemlerde, özellikle bilgisayar mühendisliği kapsamında en çok kullanılan işaretler sinüzoidal işaretlerdir. Bunun nedeni Fourier ile ortaya çıkan fikirdir: her işaret, sonsuz sayıda bilinen sinüzoidal işaretin toplamından oluşur. Bu fikirden yola çıkılarak işaret sinüzoidal bileşenlerine ayrılırsa, işaretteki frekans bileşenleri bulunabilir.

Sinüzoitler doğal işaretlerdir. Hoca örnek olarak konuşma sentezini (text-to-speech) verdi: her sesin olması gereken hali sinüzoidal işaretler cinsinden yazılıp toplanarak oluşturulabilir. Toplu taşımadaki otomatik anonsların bir kısmı kaydedilmiş seslerdir, bir kısmı ise metinden sentezlenir; sentez kısmı sinüzoitlerin kombinasyonlarıyla yapılır.

### 6.1 Genel Biçim ve Birimler

Slayttaki tanım (ekrandan, 00:40:00):

$$x(t) = \cos(\omega t + \theta)$$

Burada $\omega$ açısal (radyan) frekanstır ve birimi rad/s'dir; $\theta$ fazdır. Aynı işaret çok sık şu biçimde yazılır:

$$x(t) = A\cos(2\pi f t + \theta)$$

Burada $f$ Hertz cinsinden frekanstır, yani $\omega = 2\pi f$. Slaytta, $\omega$'ya sık sık "frekans" denileceği ama bunun aslında açısal frekans olduğu, gerçek frekansın $f$ olduğu hatırlatılıyor.

> **Hocanın vurgusu:** Bu derste birimler önemlidir; birimlere sadık kalınmalı.

### 6.2 Periyot ve Faz

Sinüzoidin periyodu (ekrandan, 00:45:00):

$$T = \frac{1}{f} = \frac{2\pi}{\omega}$$

ve birimi saniyedir. Faz ya da faz açısı $\theta$ radyan cinsinden verilir.

Hocanın örneği: $\cos(500\pi t)$ işaretinin frekansı ve periyodu.

- Verilen: $\cos(500\pi t)$.
- İşlem: $2\pi f t = 500\pi t$ eşitlenir, $f = 250$ Hz bulunur.
- Periyot: $T\cdot f = 1$ olduğundan $T = \dfrac{1}{250\ \text{Hz}} = \dfrac{4}{1000\ \text{Hz}} = 4\cdot 10^{-3}$ s.
- Sonuç: $T = 4$ ms.
- Aynı sonuç formülle: $T = \dfrac{2\pi}{\omega} = \dfrac{2\pi}{500\pi} = \dfrac{1}{250}$ s.

> **Ders sonrası not:** Hoca örneğe önce $\cos(500t)$ diye başlayıp "$\pi$'yi yaklaşık 1 kabul edelim" diyerek $f = 250$ Hz buldu, sonra ifadeyi $\cos(500\pi t)$ olarak düzeltti. $\cos(500t)$ için doğrusu $f = 500/(2\pi) \approx 79{,}6$ Hz ve $T = 2\pi/500 \approx 12{,}6$ ms'dir. $f = 250$ Hz ve $T = 4$ ms yalnız $\cos(500\pi t)$ için geçerlidir.

> **Hocanın vurgusu:** Periyot formülünü ezberlemek gerekmez; argümanı $2\pi f t$ ile eşitleyip $f$'i bulmak ve $T = 1/f$ kullanmak yeterlidir.

Faz, $t = 0$ anında işaretin hangi genlik değerinden başladığını, yani tepe noktasının ne kadar kaydığını söyler. Slayttaki iki grafikte $\cos(\omega t)$ tepe noktası $t=0$'dadır; $\cos(\omega t - \theta)$ ise sağa kaymıştır ve $t=0$'daki değeri tepe değerinden küçüktür (ekrandan, 00:45:00). Hoca, genlik, frekans ve faz olmak üzere bu üç değerin analizinin işaret hakkında özellik çıkarmak için çok bilgi verdiğini söyledi.

### 6.3 Ayrık Zamanlı Sinüzoitler

Ayrık zamanda $t$ yerine $n$ gelir:

$$x[n] = A\cos(\omega n + \phi)$$

$A$ genlik, $\omega$ frekans, $\phi$ fazdır. $n$ tam sayıdır; yani elimizde bir dizi vardır ve işaret bu diziyle ifade edilir.

## 7. Karmaşık Sinüzoitler

Euler bağıntısı $e^{j\phi} = \cos\phi + j\sin\phi$ tanımına göre karmaşık sinüzoit (ekrandan, 00:50:00):

$$Ae^{j(\omega t + \theta)} = A\cos(\omega t + \theta) + jA\sin(\omega t + \theta)$$

Slayttaki grafikte $e^{j\omega t}$'nin gerçel kısmı düz çizgiyle, sanal kısmı kesikli çizgiyle gösteriliyor; iki eğri birbirine göre kaymış.

Hoca bunu önceki haftalarda gösterilen FFT uygulamasıyla ilişkilendirdi. Gerçel değerli bir $x(t)$ işareti

$$\int_{-\infty}^{+\infty} x(t)\,e^{-j\omega t}\,dt$$

ile integre edildiğinde, işaret sonsuz sayıda sinüzoitten oluşan bir "sinüzoit bankası" ile çarpılmış olur. Bu çarpım ve integral sayesinde işaretteki sinüzoidal bileşenler, yani hangi bileşenlerin baskın olduğu bulunur. Hoca bunu, ilk haftada gösterilen bir yüz görüntüsünde göz bölgesini arama örneğine benzetti. Çarpılan ifade karmaşık olduğu için integralin sonucu gerçel ve sanal kısımlı çıkar (ekranda "= ℝ + i", yanında "FFT" yazılı).

> **Ek bilgi (derste anlatılmadı):** Hoca bu çarpma-integral işlemi için "ileride buna konvolüsyon da diyeceğiz" dedi. Kesin olarak bu integral, işaretin karmaşık üstelle iç çarpımıdır (Fourier dönüşümü); konvolüsyonla yakından ilişkilidir, ama konvolüsyon tanımındaki zamanda ters çevirip kaydırma burada yoktur.

Slaytta gerçel sinüzoidin karmaşık sinüzoidin gerçel kısmı olarak gösterilebileceği yazıyor:

$$\Re\{Ae^{j(\omega t + \theta)}\} = A\cos(\omega t + \theta)$$

Hoca, bu ders kapsamında Fourier ve Laplace dönüşümlerinde karmaşık işaretlerin inceleneceğini, ama sonunda genellikle gerçel kısmın kullanılacağını söyledi. Sanal kısmın kullanıldığı teknikler daha çok yüksek lisans ve doktora seviyesindedir; gerçel kısım bile birçok bilgi verir.

## 8. Üstel İşaretler ve Sönümlü/Büyüyen Sinüzoitler

Üstel işaret $x(t) = e^{\sigma t}$ biçimindedir. Üs negatifse işaret azalan (sönümlenen), pozitifse artan (büyüyen) bir işarettir.

Sinüzoidal bir işaret üstel bir işaretle çarpılırsa sönümlü ya da büyüyen sinüzoit elde edilir (ekrandan, 00:55:00):

$$x(t) = e^{\sigma t}\cos(\omega t + \theta)$$

- $\sigma > 0$: üstel büyüme; kosinüsün genliği zamanla artar.
- $\sigma < 0$: üstel sönüm; kosinüsün genliği zamanla azalır.

Slayttaki iki grafikte noktalı çizgiler zarfı gösteriyor: $\sigma<0$ için zarf sağa doğru daralıyor, $\sigma>0$ için genişliyor. Bu tür işaretlere sönümlü işaret denir; bir sinüzoidal ve bir üstel bileşenleri vardır ve ikisi de zamana bağlıdır.

> **Ders sonrası not:** Hoca $t=0$ ve $t=\infty$ durumlarını düşünürken bir an "$\sigma>0$ için $e^{\sigma t}$ 1'den 0'a gider" dedi. Doğrusu, $\sigma>0$ için $e^{\sigma t}$ 1'den başlayıp sonsuza büyür; 1'den 0'a giden durum $\sigma<0$'dır. Hoca da sonra $\sigma>0$ için genişleme, $\sigma<0$ için sönüm olduğunu söyledi.

### 8.1 Bilgisayar Mühendisi Açısından

Hoca $\int e^{t}\cos t\,dt$ integralini ele aldı. İki çarpan da $t$'ye göre değiştiği için integral iki ifadeyi birlikte dikkate almayı gerektirir. Bunu ayrık zamanda yazmaya kalkınca ekranda iç içe iki toplam ($\sum_{t=0}^{N}\sum_{t=0}^{N} e^{t}\cos t$) yazıldı: bir döngü $e^{t}$ ile, öbürü $e^{t}\cos t$ ile ilgilenir. Bu iç içe iki `for` döngüsü demektir ve algoritmik karmaşıklık $N^2$ olur (ekrandan, 00:55:00).

> **Hocanın vurgusu:** Böyle bir integral ifadesi kodlanmak istendiğinde iç içe iki döngüye dönüşür; bilgisayar mühendisi açısından önemli olan budur.

<!-- BELİRSİZ: İç içe iki toplam gösterimi hocanın sezgisel bir yorumudur; tek değişkenli bir integralin standart ayrık karşılığı tek bir toplamdır. Hocanın tam olarak hangi hesabı kastettiği altyazıdan net değil. -->

### 8.2 Karmaşık Üstel İşaretler

Üstteki $\sigma$ yerine karmaşık bir üs olursa, üstel çarpan hem gerçel hem sanal bileşeni etkiler; böylece hem gerçel hem sanal bileşeni sönümlenen ya da büyüyen bir işaret elde edilir. Karmaşık düzlem düşünüldüğünde, üssün gerçel kısmına göre düzlemin bir yarısında artan, öbür yarısında azalan işaretler bulunur. Hoca bu derste daha çok gerçel değerli işaretlerin kullanılacağını söyledi.

<!-- BELİRSİZ: Karmaşık düzlemde sağ yarı/sol yarı ayrımını gösteren slaytın karesi okunmadı; hangi yarının artan, hangisinin azalan işarete karşılık geldiği altyazıdan net değil. -->

## 9. Ayrık Zamanlı Karmaşık Üstellerin Periyodikliği

Aradan sonra hoca, slaytlarda olmayan bir konuyu OneNote'ta yazarak anlattı: ayrık zamanlı karmaşık üstel ve sinüzoidal işaretlerin periyodikliği (ekrandan, 01:15:00).

İşaretler:

$$x[n] = e^{j\omega_0 n} \qquad \text{ve} \qquad x[n] = \cos\omega_0 n$$

Ayrık işaretlerde köşeli parantez kullanılır; ekranda $x(n)$ yazımının üstü çizilmişti. Bazı kitaplarda ayrık zamanlı açısal frekans büyük omega ile, $e^{j\Omega_0 n}$ olarak yazılır.

Periyodiklik ölçütü (ekrandan, 01:15:00):

- $\dfrac{2\pi}{\omega_0}$ rasyonel ise $x[n]$ periyodiktir.
- Rasyonel değilse $x[n]$ periyodik değildir.
- Oran sadeleştirilemeyen $\dfrac{N}{m}$ biçiminde yazılırsa periyot $N$'dir.

> **Ek bilgi (derste anlatılmadı):** Ders kitaplarında bu ölçüt genellikle $\dfrac{\omega_0}{2\pi} = \dfrac{m}{N}$ rasyonel olmalı diye yazılır. $\dfrac{2\pi}{\omega_0} = \dfrac{N}{m}$ ile aynı şeydir; temel periyot, kesir sadeleştirildikten sonraki $N$'dir. Hocanın ekranda "$= 1/f$" diye yazdığı oran, sürekli zamandaki $T = 1/f$ ile benzerlik kurmak içindir.

İki örnek çözüldü; sorular "Örnek Sorular" bölümünde adım adım verildi. Kısaca: $x[n] = e^{j\pi n/6}$ için $\dfrac{2\pi}{\pi/6} = 12$, periyot $N=12$; $x[n] = \cos\!\left(2\pi\frac{6}{30}n\right)$ için $\omega_0 = \frac{12\pi}{30}$, $\dfrac{2\pi}{\omega_0} = \dfrac{30}{6} = 5$, periyot $N = 5$.

## 10. Temel İşaretler: Basamak, Dikdörtgen, Rampa, Üçgen

Sinüzoitler ve üstellerden sonra daha basit, özel işaretlere geçildi.

### 10.1 Birim Basamak Fonksiyonu

Slayttaki tanım (ekrandan, 01:20:00):

$$u(t) = \begin{cases} 1, & t \ge 0 \\ 0, & t < 0 \end{cases}$$

Heaviside basamak fonksiyonu olarak da bilinir. Slaytta, tam sıfırdaki değer için $1/2$ gibi farklı tanımlar da olduğu yazıyor; hoca bunu şimdilik geçti. Ayrık zamandaki karşılığı ayrık zamanlı birim basamaktır: $n \ge 0$ için 1, $n<0$ için 0.

Birim basamak diğer işaretlerin tanımlanmasında ve test edilmesinde kullanılır; diğer işaretler birim basamak cinsinden yazılabilir. Farklı zamanlarda ötelenmiş basamaklar bir işaretle çarpılarak işaretin belli bir parçası seçilir, geri kalanı sıfırlanır. Bu, konvolüsyonda ve bir işareti diğeri cinsinden ifade ederken kullanılır.

Örnek: $e^{-t}$ işaretinin $t<0$ kısmı bastırılmak isteniyor. İşaret zaman düzleminde doğrudan $u(t)$ ile çarpılır. $u(t)$, $t<0$ için 0 olduğundan o kısım sıfırlanır; $t\ge 0$ için 1 (etkisiz eleman) olduğundan değerler korunur. Sonuç $u(t)\,e^{-t}$'dir. Hoca bunun frekans düzleminde de yapılabileceğini, ama bu kadar basit bir işaret için zaman düzleminin yeterli olduğunu söyledi.

### 10.2 Basamaklardan Dikdörtgen Darbe

$t<0$ için 0, $0 \le t < 1$ için 1, $t \ge 1$ için 0 olan bir işaret kurulmak isteniyor. $u(t)$ bir birim ötelenirse $u(t-1)$ elde edilir; bu $t \ge 1$ için 1'dir. $u(t)$'den $u(t-1)$ çıkarılınca $t \ge 1$ için birler birbirini götürür:

$$u(t) - u(t-1)$$

Hoca bunu kare dalga ya da işlemcilerdeki, flip-floplardaki anahtarlama gibi düşünülebilecek bir darbe olarak anlattı.

> **Ders sonrası not:** Hoca bu işarete "impuls fonksiyonu" dedi; doğrusu bu bir dikdörtgen darbedir (rectangular pulse). Dürtü (impulse, $\delta$) fonksiyonu 12. bölümde anlatılan, ayrı bir kavramdır.

### 10.3 Birim Dikdörtgen

Slayttaki tanım (ekrandan, 01:25:00):

$$\mathrm{rect}(t) = \begin{cases} 1, & |t| \le 1/2 \\ 0, & \text{diğer durumlarda} \end{cases}$$

Hoca bunun bir filtre ya da maske olduğunu söyledi (ekranda "= filtre", "mask" yazılı). Bir ses işareti bununla çarpılırsa $-1/2$ ile $1/2$ arasındaki parça alınır, geri kalanı sıfırlanır. Çarpan aralık içinde 1 (etkisiz eleman) olduğu için işarete başka bir etki yapmaz; buna dikdörtgen filtre denir. Aralık $1/2$ olmak zorunda değildir; $-1$ ile $1$ ya da $0$ ile $1$ de olabilir.

Hoca bunun frekans düzleminde daha kullanışlı olduğunu söyledi: eksen frekans olarak düşünülür ve örneğin 4 Hz ile 8 Hz arasındaki frekanslar olduğu gibi alınıp diğerleri sıfırlanır. Böylece istenen frekanslar ön plana çıkar, istenmeyenler yok olur.

### 10.4 Birim Rampa

Slayttaki tanım (ekrandan, 01:30:00):

$$r(t) = \begin{cases} t, & t \ge 0 \\ 0, & t < 0 \end{cases} \qquad r(t) = \int_{-\infty}^{t} u(\tau)\,d\tau$$

Birim rampa, birim basamağın integralidir. Hoca bunu lise fiziğindeki hareket denklemleriyle ilişkilendirdi: $x = vt$. $u(t)$ sabit hızla hareket eden bir sistemin hızı gibi düşünülürse, integrali alındığında yol elde edilir. Ekranda ivme, hız ve yol arasında integral yönünde ileri, türev yönünde geri gidildiği bir şema çizildi (ekrandan, 01:30:00). Sabit hızın türevi sıfırdır (ivme yok); integrali ise eğrinin altında kalan alandır. $t_1, t_2, t_3, \dots$ anlarına kadar alan biriktikçe alan doğrusal olarak artar; bu da rampayı verir.

Hoca ivmenin türevinin de fizikte bir adı olduğunu hatırlattı: sarsıntı (jerk).

### 10.5 Ayrık Türev ve Özellik Çıkarma

Hoca, "bilgisayar mühendisi olarak fizikteki bu kavramlar ne işimize yarar" sorusuna bir örnekle cevap verdi. Bir işaretin zaman-frekans analizi yapıldığında işaret küçük zaman aralıklarına bölünür ve her aralıkta hangi frekansların bulunduğu ve genlikleri çıkarılır. Sonuç iki boyutlu bir dizi (matris) olur; örneğin 0-3 s aralığında 4, 8, 12 Hz, 3-6 s aralığında 8, 6, 3 Hz gibi.

Her aralıktaki frekansların ortalaması alınırsa tek boyutlu bir dizi elde edilir; eksen hâlâ zamandır, dizinin elemanları ise ortalama frekanslardır. Bu dizinin türevi, frekansın zamana göre değişimidir. Türev tanımı

$$f'(x) = \lim_{h\to 0}\frac{f(x+h) - f(x)}{h}$$

ayrık zamanda $h = 1$ alınarak

$$f[x+1] - f[x]$$

biçimine gelir; yani dizinin her elemanından bir öncekini çıkarmak.

Hocanın örneğindeki ortalama frekans dizisi $3, 6, 8, 12, 2, 4$ için:

- $6-3 = 3$
- $8-6 = 2$
- $12-8 = 4$
- $2-12 = -10$
- $4-2 = 2$

İlk eleman için bir önceki değer olmadığından hoca oraya 0 yazdı. Birinci türev yerel minimum ve maksimum noktalarını bulmakta kullanılır; frekansın nerede arttığı, nerede azaldığı görülür. Bir kez daha türev alınırsa frekansın değişiminin değişimi (ivmesi) elde edilir. Bu diziler görüntüde ya da seste özellik vektörü olarak kullanılabilir.

<!-- BELİRSİZ: Hoca dizideki dördüncü değeri önce 10 diye söyledi, hesapta ise 12 kullandı; farklar 12'ye göre verildi. -->

> **Hocanın vurgusu:** Bu konular bilgisayar mühendisleri için boş konular değil; işin algoritmik tarafına (if'ler, for'lar) geçmeden önce bunların incelenmesi gerekir.

### 10.6 Birim Üçgen

Slayttaki tanım (ekrandan, 01:35:00):

$$\Delta(t) = \begin{cases} 1 - |t|, & |t| < 1 \\ 0, & \text{diğer durumlarda} \end{cases}$$

Grafiği $-1$ ile $1$ arasında, tepe noktası $t=0$'da 1 olan bir üçgendir.

## 11. Temel İşaretlerden Karmaşık İşaret Kurmak: Darbeli Doppler Dalga Biçimi

Basit işaretlerin bir araya gelmesiyle çok daha karmaşık işaretler oluşur. Slayttaki örnek bir radyo frekansı (RF) darbeli Doppler dalga biçimiydi: zamanın belli aralıklarında kosinüs bileşenleri içeren, diğer aralıklarda sıfır olan ve periyodik tekrar eden bir işaret. Hoca bunu kalp ritmine benzetti: düzenli çalışan kalpte belli periyotlarla tekrar eden dalgalar görülür; araya anormal bir şekil girerse bir sorun olduğu anlaşılır.

İşaretin kuruluşu aşama aşama anlatıldı:

- $-1/2$ ile $1/2$ arasında tanımlı dikdörtgen darbe alınır.
- Darbe pozitif bir $a$ sayısıyla ölçeklenerek sıkıştırılır.
- Sıkıştırılmış darbenin belli bir $T$ aralığıyla ötelenmiş kopyaları alınır ve hepsi toplanarak periyodik bir kare darbe dizisi elde edilir. Bu, işaretin zarfıdır (envelope). Hoca, Türkçe "zarf" karşılığının pek oturmadığını, "envelope" teriminin daha doğru olduğunu söyledi.
- Zarf, bir yerden bir yere iletilmek üzere $\cos\omega t$ taşıyıcı işaretiyle çarpılır. Zarfın sıfır olduğu yerlerde çarpım sıfırlanır; darbenin olduğu yerlerde sinüzoidal durum aynen kalır.
- Sonuç darbeli Doppler dalga biçimidir.

Hoca, bu aşamaların tersine de gidilebileceğini söyledi: elde edilen işaretten önce taşıyıcı, sonra kopyalar çıkarılarak en sonda tek dikdörtgen darbeye ulaşılır.

<!-- BELİRSİZ: Doppler slaytlarının kareleri okunmadı; zarfın tam formülü (ölçek, öteleme ve tekrar sayısı) ve slayttaki mikrosaniye cinsinden değerler altyazıdan net değil. -->

## 12. Dürtü (Delta) Fonksiyonu

### 12.1 Ani Değişimler ve Dürtü İşaretleri

Dürtü işaretleri çok hızlı yükselip belli bir değere ulaştıktan sonra çok hızlı düşen darbe işaretleridir; bu tür ani değişimlere "abrupt changes" denir. Süreksizlik noktaları ve ani değişimler yüzünden, özellikle işaret periyodik değilse, bu tür işaretlerin kosinüs ve sinüs bileşenlerini ayırt etmek zorlaşır. Bu yüzden ani değişim içeren basit işaretler gerçek işaretlerin içinden ayrıca çıkarılıp analiz edilir.

### 12.2 Dirac Delta Fonksiyonu

Slayttaki tanım (ekrandan, 01:40:00): Dirac'ın delta fonksiyonu ya da dürtü $\delta$, şu özellikleri olan bir işaretin idealleştirmesidir:

- $t = 0$ yakınında çok büyüktür.
- $t = 0$'dan uzakta çok küçüktür.
- İntegrali 1'dir.

Slayttaki örnekler: genişliği $\epsilon$, yüksekliği $1/\epsilon$ olan dikdörtgen; tabanı $2\epsilon$, yüksekliği $1/\epsilon$ olan üçgen. Fonksiyonun tam şekli önemli değildir; $\epsilon$ küçüktür ve ne kadar küçük olduğu bağlama bağlıdır. Hoca, kâğıt üzerinde ideal dürtünün dik bir okla gösterildiğini, ama osiloskopta ya da MATLAB'de gerçek bir veride bakıldığında küçük bir $\epsilon$ süresinde yükseliş ve düşüş görüleceğini söyledi.

Hoca algoritmik olarak dürtüyü "$t = 0$ ise 1, $t \neq 0$ ise 0" diye yazdı.

> **Ders sonrası not:** Hoca sürekli zamanlı $\delta(t)$ için "$t=0$ anında 1'dir" dedi. Bu ayrık zamanlı birim dürtü $\delta[n]$ için doğrudur. Sürekli zamanlı Dirac deltanın $t=0$'daki değeri 1 değildir (yüksekliği $1/\epsilon$ ile sonsuza gider); 1 olan, integralidir (alanı). Slayttaki tanım da "integrali 1" der.

Örnek olarak $x(t) = (t+1) + \delta(t)$ gibi bir işaret düşünüldü: $t=0$ anında $t+1$ terimi 1 verir, üzerine dürtü eklendiği için o noktada ani bir yükseliş ve düşüş görülür.

<!-- BELİRSİZ: Örnek işaretin tam ifadesi altyazıda "T artı 1 artı t" diye bozuk geçiyor; dürtülü terimin ve genliğin karede doğrulanması gerekir. -->

### 12.3 Ayrık Zamanlı Birim Dürtü

Ayrık zamanda dürtünün karşılığı birim dürtüdür (unit impulse): $n = 0$ anında 1, diğer bütün $n$ değerlerinde 0 olan bir dizi.

### 12.4 Bir Fonksiyonun Dürtüyle Çarpımı

Bir fonksiyon $t=0$'daki dürtüyle çarpılırsa yalnız $t=0$'daki değeri kalır; hoca bunu dikdörtgen filtrenin "anlık" hali olarak yorumladı. Sonuçta $f(0)$ ile ölçeklenmiş bir dürtü elde edilir. Dürtü bir katsayıyla çarpılarak o noktadaki etki güçlendirilebilir.

Hoca ayrıca bir üstel işaretin dürtüler cinsinden nasıl yazılabileceği sorusunu sordu ve fikri şöyle verdi: dürtü yalnız bir noktada değer verdiği için işaretin her noktası için ötelenmiş bir dürtü ($t - k$) kullanılır, her biri o noktadaki değerle çarpılır ve hepsi bir toplam ya da integralle birleştirilir. Ayrıntıların ileride görüleceğini söyledi.

### 12.5 Eleme (Sifting) Özelliği

Slayttaki ifade (ekrandan, 01:50:00): $x(t) = \delta(t - T)$ işareti dürtüsü $t = T$'de olan bir dürtü fonksiyonudur. $f$, $t = T$'de sürekliyse:

$$\int_{-\infty}^{\infty} f(t)\,\delta(t - T)\,dt = f(T)$$

Bir $f(t)$ fonksiyonunu $T$ anındaki bir dürtüyle çarpıp integre etmek, $f(T)$ değerini çıkarır. Slayta göre bu, ileride örneklemenin modellenmesinde önemli olacak.

Hocanın sezgisel açıklaması: $f(t) = 2t$ ve $T = 5$ alınsın. İntegral, $t$'nin her değeri için $f(t)\,\delta(t-5)$ çarpımlarını toplamak gibi düşünülebilir:

- $t = 0$: $f(0)\,\delta(-5) = 0$
- $t = 1$: $f(1)\,\delta(-4) = 0$
- $t = 2$: $f(2)\,\delta(-3) = 0$
- ...
- $t = 5$: $\delta(0)$ devreye girer, $f(5)$ değeri gelir.
- $t > 5$: yine 0.

Sonuç $f(5)$'tir; bu örnekte $f(5) = 10$ (ara adım eklendi).

**Soru (hocanın kendi sorusu):** Fonksiyonun 5 anındaki değeri isteniyorsa neden doğrudan $f(5)$ hesaplanmıyor?

**Cevap:** Doğru, ama bu ifadenin örnekleme (sampling) konusunda önemli bir yeri var. Ayrıca bu integral bir anlamda konvolüsyon integralidir: dürtü bir filtre gibi davranır ve işaretin içinde "nerede 1 var" diye bir benzerlik (similarity) aranır.

> **Hocanın vurgusu:** $\int f(t)\delta(t-T)\,dt = f(T)$ çok önemli bir integraldir.

Ekranda ayrıca öteleme yazıldı: $t=0$'da 1 veren bir dürtü, $t - a$ biçiminde ötelenirse $t = a$ noktasında değer verir.

### 12.6 İntegralin Sınırları

Bir dürtünün integrali yalnız dürtü integral aralığının içindeyse sıfırdan farklıdır (ekrandan, 01:55:00):

- $a < 0$ ve $b > 0$ ise $\displaystyle\int_a^b \delta(t)\,dt = 1$, çünkü dürtü sınırların içindedir.
- $a > 0$ ya da $b < 0$ ise (ve $a < b$) $\displaystyle\int_a^b \delta(t)\,dt = 0$, çünkü dürtü integral aralığının dışındadır.
- $a = 0$ ya da $b = 0$ ise belirsizdir (ambiguous).

Hocanın örneği: $a = -3$, $b = 5$ alınırsa $-3, -2, -1$ için 0, $0$ için 1, sonra yine 0 gelir; sonuç 1'dir. Belirsizlikten kurtulmak için sınır sıfırın biraz sağında ($0^+$) ya da biraz solunda ($0^-$) alınır: $0^+$ alınırsa 0 dahil değildir ve sonuç 0 olur; $0^-$ alınırsa 0 dahildir ve sonuç 1 olur.

> **Hocanın vurgusu:** Bu aralık kuralları ileride gelecek integrallerin çok daha hızlı çözülmesini sağlayacak.

Ardından içinde birden fazla ötelenmiş dürtü bulunan bir integral örneği çözüldü. İntegrand $f(t)$ ile $2$ ve $t=-1$, $t=+1$, $t=-3$ noktalarındaki dürtülerin bir kombinasyonunun çarpımıydı. Çözüm yolu şuydu: parantez açılarak integral terimlere ayrılır; her dürtü teriminde dürtünün olduğu noktanın integral aralığında olup olmadığına bakılır. Aralıktaki dürtüler eleme özelliğiyle $f$'in o noktadaki değerini (katsayısıyla) verir, aralık dışındaki dürtü 0 verir. Bir öğrencinin belirttiği gibi $-3$ noktası aralıkta olmadığı için o terim düşer. $f(t)$ yerine somut bir fonksiyon (örneğin $2t + 3$) yazılarak sayısal sonuç bulunur.

<!-- BELİRSİZ: Bu örneğin slaytı karede okunmadı; integralin sınırları (altyazıda "eksi ikiden üçe" geçiyor) ve dürtülerin katsayıları altyazıdan kesin çıkmıyor. Bu yüzden sayısal sonuç verilmedi. -->

### 12.7 Fiziksel Yorum

Dürtü fonksiyonları kısa zaman aralığında etki eden ve etkisi işaretin integraline bağlı olan fiziksel işaretleri modellemek için kullanılır (ekrandan, 02:00:00). Slayttaki örnek: $t = 2$ anında çekiç darbesi ya da sopanın topa vurması.

- $f$ kuvveti, $m$ kütleli cisme $t = 1{,}999$ s ile $t = 2{,}001$ s arasında etki ediyor.
- $\displaystyle\int_{1{,}999}^{2{,}001} f(t)\,dt = I$ (mekanik impuls, N·s).
- Darbenin yol açtığı hız değişimi:

$$v(2{,}001) - v(1{,}999) = \frac{1}{m}\int_{1{,}999}^{2{,}001} f(\tau)\,d\tau = \frac{I}{m}$$

- Çoğu uygulamada kuvvet, $t = 2$'de genliği $I$ olan bir dürtü olarak modellenir.

Hoca ikinci örnek olarak bir kondansatörün hızlı şarj edilmesini anlattı: anahtar çok kısa süre kapatılıp açılarak ani bir darbe uygulanır. $t = 0$'da gerilimin 0 olduğu kabul edilir; $0$ ile $\epsilon$ arasındaki çok kısa sürede akım $i(t)$ çok büyük olur. Aktarılan toplam yük $Q = \int i(t)\,dt$'dir; bu aralıkta gerilim farkı 1'e yaklaşır. Sonuç olarak akım, $t=0$'da genliği 1 olan bir dürtüye yaklaşır. Hoca bu örneklerin bilgisayar mühendisliğiyle doğrudan ilgili olmadığını, üzerinde fazla durmaya gerek olmadığını söyledi.

<!-- BELİRSİZ: Kondansatör örneğinin slaytı karede okunmadı; devre elemanlarının değerleri ve formüller altyazıdan net değil. -->

## 13. Dürtülerin İntegrali ve Süreksiz Fonksiyonların Türevi

### 13.1 Dürtü İçeren Bir İşaretin İntegrali

Slayttaki işaret $x(t) = 1 + \delta(t-1) - 2\delta(t-2)$ idi ($t \ge 0$ için). Hoca, integralini daha önce konuşulan $x = vt$ ilişkisi gibi düşünmeyi önerdi. $y(t) = \int_0^t x(\tau)\,d\tau$ hesaplanırsa:

- $0 < t < 1$: sabit 1'in integrali doğrusal artış verir, $y(t) = t$.
- $t = 1$: dürtü işarete anlık olarak 1 birim ekler; $y$ 1'den 2'ye sıçrar.
- $1 < t < 2$: doğrusal artış devam eder, $y(t) = t + 1$.
- $t = 2$: $-2$ katsayılı dürtü yüzünden $y$ 2 birim düşer (3'ten 1'e).
- $t > 2$: yine aynı eğimle artar, $y(t) = t - 1$.

Ara değerler (ara adım eklendi): $y(1^-) = 1$, $y(1^+) = 2$, $y(2^-) = 3$, $y(2^+) = 1$. Bu, slayttaki $y(t)$ grafiğiyle uyumludur (ekrandan, 02:05:00).

### 13.2 Süreksiz Fonksiyonların Türevi

Tersine, süreksizlikleri olan bir fonksiyonun türevi her sıçramada bir dürtü içerir (ekrandan, 02:05:00):

- Birim basamak $u(t)$'nin türevi $\delta(t)$'dir.
- Önceki sayfadaki $y$ işaretinin türevi:

$$y'(t) = 1 + \delta(t-1) - 2\delta(t-2)$$

Yani türev alınınca tekrar $x(t)$ bulunur. Doğrusal kısımların eğimi 1 olduğu için türev oralarda sabit 1'dir; $t=1$'deki yukarı sıçrama $+\delta(t-1)$, $t=2$'deki 2 birimlik aşağı sıçrama $-2\delta(t-2)$ verir. Hoca, iki doğrusal parçanın eğimi aynı olduğu için türevin her iki tarafta da aynı sabit değeri verdiğini; eğimler farklı olsaydı farklı sabitler görüleceğini söyledi.

### 13.3 Öğrenci Sorusu

**Soru:** Slaytta (eleme özelliği) iki farklı fonksiyon var gibi; aralarındaki farkı anlamadım.

**Cevap:** $f$ herhangi bir fonksiyondur; dürtü ise bir filtre gibidir. Fonksiyon dürtüyle çarpılıp integre edilerek, fonksiyonun dürtünün bulunduğu andaki (örneğin $t=0$) değeri bulunur. Konvolüsyonda da benzerliğine bakılan fonksiyon bir filtre gibi davranır. Hoca, konu soyut kaldığı için konvolüsyon konusuna gelindiğinde daha iyi anlaşılacağını söyledi.

## 14. Sistemlere Giriş

Ders, dördüncü slayt dizisine ("Systems Properties") geçti. Sinyallerde görülen öteleme, ölçekleme gibi özelliklerin benzerleri sistemlerde de vardır; sistemlerde ek kavramlar da bulunur.

### 14.1 Sistem Nedir?

Sistem, giriş işaretini alıp çıkış işaretine dönüştüren bir dönüşümdür. Aynı zamanda bir fonksiyondur: giriş işaretini çıkış işaretine eşler (map). Matematikçi açısından bir fonksiyon, elektronikçi açısından bir sistemdir.

> **Hocanın vurgusu:** Bilgisayar mühendisleri için önemli olan sistemin modelini, yani fonksiyon denklemini ortaya çıkarmaktır. Elimizde girdiler ve onlara karşılık gelen çıktılar varsa ve sistemin modeli elde edilebilirse, geleceğe yönelik tahminler yapılabilir ve tahminlerin gerçekle ne kadar uyumlu olduğu analiz edilebilir.

Bu derste tek girişli, tek çıkışlı (single input, single output, SISO) sistemlerle uğraşılacak. $y = S(x)$ ya da $y = Sx$ gösterimi, $S$ sisteminin $x$ girişine uygulanmasıdır; $Sx$ bir çarpma değildir. Slaytta $S$'nin kalın yazıldığına dikkat edilmeli.

Blok diyagramda $x$ işareti sisteme girer, $y$ işareti çıkar. Oklar işaretleri gösterir, kablo değildir; kutu sistemin kendisidir.

### 14.2 Ölçekleme Sistemi

Blok diyagram sembollerinin (kare, üçgen, daire) farklı anlamları vardır. Ölçekleme yapan sistem $y = Ax$ için üç durum vardır:

- $|A| > 1$: yükselteç (amplifier), güçlendirir; örneğin 3 verilince 6 çıkar.
- $|A| < 1$: zayıflatıcı (attenuator); örneğin yarısını ya da üçte birini alır.
- $A < 0$: evirici (inverter); örneğin 2 verilince $-2$ çıkar. $A = -1/2$ gibi bir değer hem işareti değiştirir hem ölçekler.

$A$'ya kazanç (gain) ya da ölçek faktörü denir. Bu sistemler blok diyagramda üçgen ya da daire gibi farklı sembollerle gösterilebilir.

### 14.3 Türev ve İntegral Alan Sistemler

Sistem bağımsız değişkene göre türev alıyorsa içine türev operatörü, integral alıyorsa integral operatörü yazılır. Girişteki $x$ verisinin zamana göre türevi alınır ve yine zamana bağlı olan $y$ çıkışını oluşturur; integral için de aynısı geçerlidir.

### 14.4 Zamanda Öteleme Sistemi

Slayttaki tanım (ekrandan, 02:15:00):

$$y(t) = x(t - T)$$

- $T > 0$ ise geciktirme (delay) sistemi denir.
- $T < 0$ ise öngörücü (predictor) sistem denir.

Hoca ekrana $u(t-3)$ ve $\delta(t-3)$ yazdı: normalde $t=0$'da 1 vermeye başlayan basamak ya da $t=0$'da dürtü veren işaret, $t = 3$'te vermeye başlar; yani sistem geciktirme yapar.

<!-- BELİRSİZ: Öngörücü sistem için hocanın verdiği ifade altyazıda karışık ("t-3 olduğu durumu düşünün"); slayta göre öngörücü sistem T<0 durumudur, yani örneğin x(t+3). -->

### 14.5 Konvolüsyon Sistemi

Konvolüsyon sistemi, verilen bir işaretin başka bir işaretle benzerliğine bakar. Bir fotoğraftan göz bölgesi kesilip bütün fotoğraf üzerinde gezdirilebilir; ya da bir işaret üzerinde $1, 2, 1$ gibi üç elemanlı bir parça baştan sona kaydırılarak gezdirilebilir. Benzerlik bulunan noktada çıkış bir tepe (pik) verir; tespit (detection) böyle yapılır.

Hoca ekranda bir iris tespiti görseli açtı. Görüntü 0-255 arası değerler olarak düşünülürse, yuvarlak bir pencere (filtre) görüntü üzerinde gezdirilir ve pencere içindeki renk değerleri toplanır. Sıfıra yakın (karanlık) değerlerin en çok toplandığı nokta irisin olduğu yerdir; pencere o noktadan uzaklaştıkça toplam karanlık azalır.

**Soru:** Az önceki integraldeki fonksiyon, buradaki irisin karşılığı mı oluyor?

**Cevap:** Evet. Pencere bir kare matris gibi düşünülür; içindeki sayısal değerler toplanır. Sıfıra yakın değerler çoğaldıkça orada bir iris olabileceği anlaşılır; başka yerlerde toplam çok daha büyük çıkar. Daha ilginç bir uygulamada gözün bir parçası (patch) kesilir, bütün fotoğrafta gezdirilir ve benzerliğin en yüksek olduğu yer, yani gözün olduğu yer bulunur.

Bu basit bir konvolüsyondur. Benzeri korelasyondur; o da çok benzer ve onda da integral vardır. Ayrıntıları ileride görülecek.

### 14.6 İşlem Sistemleri ve Bağlantılar

- **Toplama sistemi:** İki girişin ($x_1$, $x_2$) değerleri toplanarak $y$ elde edilir.
- **Fark sistemi:** $x_2$'nin negatifi alınarak fark bulunur.
- **Çarpma sistemi (multiplier):** Girişler çarpılır.

Sistemler birbirine bağlanarak yeni sistemler kurulabilir (ekrandan, 02:20:00):

- **Seri (kaskat) bağlantı:** $y = G(F(x)) = GFx$. $x$ önce $F$'ye girer, $F$'nin çıktısı $G$'ye verilir. Bu, bileşke fonksiyon ($G \circ F$) gibidir. Slayta göre blok diyagramdaki sıra ile cebirdeki yazım sırası terstir.
- **Paralel (toplam) bağlantı:** $y = Fx + Gx$. $x$ iki sisteme birden girer, çıkışlar toplanır.

Bu bağlantılar sadeleştirilebilir; ileride görülecek.

### 14.7 Geri Besleme

$F$ sisteminin çıktısı $G$'ye giriş olarak veriliyor ve $G$ de $F$'ye tekrar bilgi veriyorsa buna geri besleme (feedback) denir. Hocanın sezgisel örneği: sisteme 3 girildi, beklenen gerçek değer 6, sistem ise 7 buldu. Aradaki $-1$'lik hata geri yansıtılır ve sistem kendini buna göre günceller. Yapay sinir ağları ve derin öğrenme de gerçek (actual) çıktı ile tahmin edilen (predicted) çıktı arasındaki hatayı hesaba katarak eğitilir.

Blok diyagramlar sistemlerin birbirine bağlanmasını gösteren sembolik bir yöntemdir. Blok diyagramlardan sistemlerin denklemleri bulunur; bu denklemlerle de sistemin kararlı mı, periyodik mi çalıştığı ve nasıl eğitildiği gibi özellikleri incelenecek.

### 14.8 İntegral Alan ve Geri Beslemeli Sistem Örneği

$x(t)$ girişi bir toplayıcıya gelir; çıkış $y(t)$ bir $a$ katsayısıyla çarpılıp geri beslenir ve girişten çıkarılır. Fark integral alıcıdan geçerek $y(t)$'yi verir:

$$y(t) = \int_{-\infty}^{t} \big(x(\tau) - a\,y(\tau)\big)\,d\tau$$

Bu, türev alma ile ifade edilirse

$$\frac{dy(t)}{dt} = x(t) - a\,y(t)$$

diferansiyel denklemine karşılık gelir. Bu diferansiyel denklem çözülerek türevli ifadeden kurtulunur ve sistemin genel modeli, yani $y(t)$ bulunur. Bu sistemde hem integral, hem geri besleme, hem de toplama-çıkarma işlemi vardır.

<!-- BELİRSİZ: Bu örneğin slaytı karede okunmadı; denklem hocanın sözlü anlatımından ("X eksi AY ... Y türev gibi") kuruldu. İntegralin alt sınırı altyazıdan net değil. -->

Sistemlerin özellikleri (doğrusallık, hafıza, nedensellik, zamanla değişmezlik, kararlılık) bir sonraki derse bırakıldı.

## 15. MATLAB ile Karmaşık Üstel İşaretin Çizimi

Dersin sonunda, 9. bölümdeki $x[n] = e^{j\pi n/6}$ işareti MATLAB Online'da oluşturulup çizildi. İşaret karmaşık olduğu için gerçel ve sanal kısımları ayrı ayrı çizildi.

Önce bağımsız değişken olarak ayrık zamanlı bir $n$ vektörü oluşturuldu (0'dan $20\pi$'ye kadar tam sayılar; Workspace'te $n$ 1×63 boyutlu görünüyor). Sonra işaret yazıldı. Komut penceresindeki komutlar (ekrandan, 02:35:00):

```matlab
n = 0:20*pi;            % bu satır karede görünmüyor; söylenene ve 1x63 boyutuna göre yazıldı
x1 = exp(j*pi/6.*n);
subplot(2,1,1);
whos
stem(n, real(x1));
title('Real part'); xlabel('n');
subplot(2,1,2);
stem(n, imag(x1));
title('imag part'); xlabel('n');
```

Hocanın açıklamaları:

- MATLAB'de sanal birim için `j` kullanılabilir. Bir öğrencinin "`i` mi `j` mi kullanılmalı" sorusuna hoca, kodlama yaparken dile bakmak gerektiğini söyledi.
- `.*` iki vektörü karşılıklı (eleman eleman) çarpar; burada skaler ile $n$ vektörü çarpılıyor.
- Satır sonundaki noktalı virgül, sonucun komut penceresine yazdırılmasını engeller.
- Hoca bir yerde fazladan bir çarpı yazdı ve MATLAB "Invalid use of operator" hatası verdi; fazla çarpı silinerek düzeltildi (ekrandan, 02:35:00).
- `subplot(2,1,1)` iki satır, bir sütunluk çizim alanının ilk kısmını seçer.
- `stem` ayrık zamanlı çizim yapar (sürekli çizim için `plot` kullanılır).
- `whos` değişkenlerin boyutunu ve türünü gösterir: $n$ 1×63 `double`, `x1` 1×63 `double` ve `complex` özellikli. Workspace'te `x1`'e çift tıklanınca değerlerin "1 + 0i" gibi karmaşık biçimde saklandığı görülür.
- `real` ve `imag` fonksiyonlarıyla gerçel ve sanal kısımlar alınır.

Çizimlerde gerçel kısım ile sanal kısım arasında bir faz farkı görülüyor; ikisi de yaklaşık 12 örnekte bir tekrar ediyor (ekrandan, 02:35:00).

**Soru (hocanın sorusu):** Gerçel kısmın değerleri ile sanal kısmın değerleri neden farklı?

**Cevap:** İşaret Euler bağıntısıyla yazılırsa

$$e^{j\pi n/6} = \cos\!\left(\frac{\pi}{6}n\right) + j\sin\!\left(\frac{\pi}{6}n\right)$$

olur. $n = 0$ için $\cos 0 + j\sin 0 = 1 + 0j$; $n = 1$ için $\cos 30^\circ + j\sin 30^\circ = \frac{\sqrt{3}}{2} + j\frac{1}{2} \approx 0{,}866 + 0{,}5j$. Gerçel kısım kosinüsü, sanal kısım sinüsü izler; kosinüs ile sinüs arasında $90^\circ$ faz farkı vardır. Bu yüzden iki kısım kendi içinde farklı ilerler.

> **Ders sonrası not:** Hoca faz farkını açıklarken "$\cos(\theta + 90^\circ)$, $\sin\theta$'ya eşit değil mi?" dedi. Doğrusu $\cos(\theta + 90^\circ) = -\sin\theta$ ve $\cos(\theta - 90^\circ) = \sin\theta$'dır. $90^\circ$ faz farkı olduğu sonucu doğrudur, yalnız işaret yönü değişir.

### 15.1 Karmaşık Sayıların Bu Dersteki Yeri

Ders sonunda bir öğrenci karmaşık sayılar kısmını anlamakta zorlandığını söyledi. Hoca, bu dersin içeriğinde karmaşık işaretlerin değil daha çok gerçel işaretlerin kullanılacağını açıkladı. Fourier dönüşümünde incelenen işaretin kendisi karmaşık değildir; işaretin çarpıldığı filtre ($e^{-j\omega t}$) karmaşıktır:

$$F(\omega) = \int_{-\infty}^{\infty} f(t)\,e^{-j\omega t}\,dt$$

Burada $e^{-j\omega t}$, yüz görüntüsündeki göz parçası gibi işaret üzerinde benzerlik aranan şablondur. Hoca, bu derste $F(\omega)$'nın gerçel kısmının kullanılacağını, sanal kısmın kullanılmayacağını söyledi; örneğin bir kare dalga sinüzoidal bileşenlerine ayrılırken gerçel kısım dikkate alınacak. Karmaşık sayı için $x + jy$ biçimini bilmek yeterlidir.

> **Ek bilgi (derste anlatılmadı):** Fourier dönüşümünde genlik spektrumu $|F(\omega)|$ hem gerçel hem sanal kısımdan hesaplanır; yalnız gerçel kısmı kullanmak, hocanın bu ders için yaptığı bir sadeleştirmedir.

## Örnek Sorular

### Soru 1

(ekrandan, 00:10:00) $x(2(t-1))$ işaretinde $2(t-1)$ ifadesi nerede sıfır olur?

> **Çözüm (derste verilmedi):** $2(t-1) = 0 \Rightarrow t = 1$. Yani $x(t)$'nin $t=0$'daki tepe noktası, $x(2(t-1))$ işaretinde $t = 1$'e taşınır. Bu, slayttaki doğru grafikle uyumludur (tepe $t=1$'de).

### Soru 2

(ekrandan, 00:30:00) $3 + 4j$ karmaşık sayısını kutupsal biçimde yazınız.

Derste verilen çözüm: $r = \sqrt{3^2 + 4^2} = 5$; $\phi = \arctan(4/3) \approx 53{,}13^\circ$. Sonuç: $z = 5e^{j\,53^\circ}$ (python ile doğrulandı).

### Soru 3

(ekrandan, 00:45:00) $\cos(500\pi t)$ işaretinin frekansı ve periyodu nedir?

Derste verilen çözüm: $2\pi f t = 500\pi t \Rightarrow f = 250$ Hz. $T = 1/f = 1/250$ s $= 4$ ms. Formülle de $T = 2\pi/\omega = 2\pi/(500\pi) = 4$ ms (python ile doğrulandı).

### Soru 4

(derste sözlü, 01:15:07) $x[n] = e^{j\frac{\pi}{6}n}$ periyodik midir? Periyodikse periyodu nedir?

Derste verilen çözüm: $\omega_0 = \pi/6$. $\dfrac{2\pi}{\omega_0} = \dfrac{2\pi}{\pi/6} = 2\pi\cdot\dfrac{6}{\pi} = \dfrac{12}{1}$. Rasyonel ve sadeleşmiş durumda; işaret periyodiktir ve periyodu $N = 12$'dir. MATLAB çiziminde de gerçel ve sanal kısımların 12 örnekte bir tekrar ettiği görülüyor (ekrandan, 02:35:00).

### Soru 5

(derste sözlü, 01:16:39) $x[n] = \cos\!\left(2\pi\,\dfrac{6}{30}\,n\right)$ periyodik midir? Periyodikse periyodu nedir?

Derste verilen çözüm: $\omega_0 = 2\pi\cdot\dfrac{6}{30} = \dfrac{12\pi}{30}$. Hoca önce $\omega_0$ yerine $6/30$ yazdı, sonra düzeltti. $\dfrac{2\pi}{\omega_0} = 2\pi\cdot\dfrac{30}{12\pi} = \dfrac{30}{6} = \dfrac{5}{1}$. Rasyoneldir; işaret periyodiktir ve periyodu $N = 5$'tir (python ile doğrulandı).

### Soru 6

(ekrandan, 02:05:00) $x(t) = 1 + \delta(t-1) - 2\delta(t-2)$ ($t \ge 0$) için $y(t) = \int_0^t x(\tau)\,d\tau$ işaretini bulunuz ve $y'(t)$'yi yazınız.

Derste verilen çözüm (grafikten, ara değerler eklendi):

$$y(t) = \begin{cases} t, & 0 \le t < 1 \\ t + 1, & 1 < t < 2 \\ t - 1, & t > 2 \end{cases}$$

$t = 1$'de 1 birim yukarı, $t = 2$'de 2 birim aşağı sıçrama vardır. Türev alınınca her sıçramada bir dürtü çıkar:

$$y'(t) = 1 + \delta(t-1) - 2\delta(t-2) = x(t)$$

### Soru 7

(ekrandan, 02:35:00) $x[n] = e^{j\pi n/6}$ işaretini MATLAB'de oluşturup gerçel ve sanal kısımlarını ayrık zamanlı olarak çiziniz. İki kısmın değerleri neden farklıdır?

Derste verilen çözüm: Kod 15. bölümdedir. $e^{j\pi n/6} = \cos(\pi n/6) + j\sin(\pi n/6)$ olduğundan gerçel kısım kosinüsü, sanal kısım sinüsü izler; aralarında $90^\circ$ faz farkı vardır. $n=1$ için gerçel kısım $\sqrt{3}/2 \approx 0{,}866$, sanal kısım $0{,}5$'tir.

## Dersin Toparlaması

Bu derste "Signals and Systems Properties" slayt dizisi tamamlandı. Önce işlem sırası ve periyodik işaretlerin tek periyotta incelenebilmesi hatırlatıldı. Ardından karmaşık işaretler, kartezyen ve kutupsal gösterim ile Euler bağıntısı işlendi; kosinüsün iki karmaşık üstelin ortalaması olarak yazılabilmesinin Fourier ve Laplace dönüşümlerinde integrali kolaylaştıracağı vurgulandı. İşaretin enerjisi ve gücü tanımlandı. Sinüzoitlerin frekans, açısal frekans, periyot ve faz kavramları birimleriyle birlikte $\cos(500\pi t)$ örneğiyle hesaplandı. Karmaşık sinüzoitler, sönümlü ve büyüyen sinüzoitler, ayrık zamanlı üstellerin periyodiklik ölçütü ($2\pi/\omega_0$ rasyonel olmalı) ve temel işaretler (basamak, dikdörtgen, rampa, üçgen) görüldü. Dirac delta fonksiyonu, eleme özelliği, integral sınırları kuralı ve süreksiz fonksiyonların türevinde ortaya çıkan dürtüler anlatıldı.

Son bölümde "Systems Properties" dizisine geçilerek sistem kavramı, blok diyagramlar, ölçekleme, türev, integral, öteleme, konvolüsyon, toplama ve çarpma sistemleri, seri ve paralel bağlantılar ile geri besleme tanıtıldı. Ders, karmaşık üstel bir işaretin MATLAB'de çizilmesiyle bitti. Bir sonraki derste sistemlerin özelliklerine (doğrusallık, hafıza, zamanla değişmezlik, kararlılık) geçilecek; eleme özelliğinin örnekleme ve konvolüsyon konularında yeniden kullanılacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
