# Ders 6 Genişletilmiş Notu: Frekans Düzlemi, Örnekleme ve Fourier Serisi: Gösterimler ve Kare Dalga Örneği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Haritası: Ayrık Taraf ve Sürekli Taraf
- 2. Frekans Düzlemine Geçiş
- 3. Periyodik ve Periyodik Olmayan İşaretler
- 4. Sinüzoidlerle Yazma Fikri ve Ses Sentezi
- 5. Shazam ve Kare Dalga Gösterimi
- 6. Örnekleme ve Örtüşme
- 7. Fourier Serisi mi, Fourier Dönüşümü mü?
- 8. Fourier Serisinin Temel Fikri
- 9. Temel Frekans, Harmonikler, Genlik ve Fazın Etkisi
- 10. DC Bileşen, Analiz ve Sentez
- 11. Fourier Serisinin Üç Gösterimi
- 12. Gösterimler Arasında Dönüşüm
- 13. Örnek: Üç Bileşenli İşaretin Gösterimleri
- 14. Katsayıları İntegralle Bulmak
- 15. Örnek: Kare Dalganın Fourier Serisi

## 1. Dersin Haritası: Ayrık Taraf ve Sürekli Taraf

Hoca yeni konuya girmeden önce "nereden geldik, ne yaptık" diye bir toparlama yaptı. Ders iki ana kısımdan oluşuyor: dijital (ayrık) kısım ve analog (sürekli) kısım. İki tarafta da sinyal ve sistem kavramlarından söz edilir. Araçlar birbirinin karşılığıdır:

| Konu | Dijital (ayrık) taraf | Analog (sürekli) taraf |
|---|---|---|
| Değişken | $n$ | $t$ |
| Gösterim | köşeli parantez, $x[n]$ | normal parantez, $x(t)$ |
| Konvolüsyon | konvolüsyon toplamı | konvolüsyon integrali |
| Sistem denklemi | fark denklemi (difference equation) | diferansiyel denklem (differential equation) |
| Dönüşüm | z dönüşümü | Laplace dönüşümü ($s$ dönüşümü) |
| Fourier | ayrık zamanlı Fourier dönüşümü (DTFT) | Fourier dönüşümü |

Ayrık tarafta toplam ($\Sigma$) varken sürekli tarafta onun yerini integral alır. Laplace dönüşümü de sürekli tarafta z dönüşümünün karşılığıdır.

## 2. Frekans Düzlemine Geçiş

Bir işaretin hem zaman bilgisi (bu zaman sürekli ya da ayrık olabilir) hem de frekans bilgisi vardır. Elimizde zamana bağlı, bir boyutlu bir $x(t)$ işareti olsun. Hoca bu geçişin önceki derslerdeki $t$ değişikliklerine benzemediğini, burada gerçekten düzlem değiştirdiğimizi vurguladı: $x(t)$'den $X(f)$ ya da $X(\omega)$ düzlemine geçeriz.

Zaman düzleminde zaman-genlik (time-amplitude) analizi yaparız. Frekans düzleminde ise işaretteki frekans bileşenlerini görür, frekans-genlik (frequency-amplitude) analizi yaparız. Bu geçiş işaret hakkında ek bilgi verir ve bazı işlemleri kolaylaştırır. Elimizdeki bir sistemse, sistemin bazı özelliklerini de daha rahat öğreniriz.

### 2.1 Frekans Bileşenleri ve Temel Frekans

Frekans ekseninde sıfır noktası, frekansın sıfır olduğu yeri gösterir. Sonra $f_1, f_2, f_3, \ldots, f_n$ gelir. Sonuncusuna $f_{max}$ da diyebiliriz. Bir işaretin frekans bileşenleri bu eksende eşit aralıklarla dizilir. Bu eşit aralıklı noktaların birinde genlik sıfırsa o frekansta bileşen yok demektir.

Buradan temel frekans (fundamental frequency) $f_0$ kavramı çıkar. Temel frekans, bileşenlerin en büyük ortak bölenidir (greatest common divisor, EBOB):

$$f_0 = \text{EBOB}(f_1, f_2, \ldots, f_n)$$

Bileşenler de temel frekansın tam katlarıdır:

$$f_1 = f_0, \quad f_2 = 2f_0, \quad f_3 = 3f_0, \quad \ldots, \quad f_n = n f_0$$

**Örnek.** Bir işaretin frekans bileşenleri 10, 20 ve 40 olsun.

- Verilen: bileşenler $10, 20, 40$.
- İşlem: $\text{EBOB}(10, 20, 40) = 10$, yani $f_0 = 10$.
- Ara sonuçlar: $10 = 1 \cdot f_0$ bileşeni $f_1$, $20 = 2 \cdot f_0$ bileşeni $f_2$, $40 = 4 \cdot f_0$ bileşeni $f_4$ olur.
- Sonuç: $f_3$ bileşeninin yeri vardır, ama genliği sıfırdır. Yani $f_3$ yoktur (absent).

### 2.2 Temel Periyot

Temel frekansı bulduktan sonra temel periyot (fundamental period) kolayca bulunur:

$$T_0 = \frac{1}{f_0}$$

Hoca burada bir ayrım yaptı: İşaretin periyodik olması ayrı bir konu, temel periyodu başka bir şeydir. İşaretin periyodik olmasına birazdan gelinecek.

### 2.3 Frekans Düzlemi Ne İşe Yarar? Gürültü Örneği

Bir işaretin belli bir noktasına gürültü eklendiğini düşünelim. Zaman düzleminde işaret bir dizidir ve bu diziye doğrudan girip gürültüyü yok etmek zordur. Ortalama filtresi gibi yumuşatma (smoothing) filtreleri kullanılabilir, ama orijinal işareti bozma ihtimali vardır. Orijinal bozulunca da işe yaramaz.

Bunun yerine işaretteki frekanslar analiz edilir. Çoğu işarette düşük frekanslı bileşenler baskındır. Frekans yükseldikçe genlik genellikle azalır ve bir süre sonra söner. Örneğin insan sesinde çok yüksek frekanslı bileşenler bir yerden sonra bulunmaz. Gürültü ise olağan dışı olduğu için bunların dışında bir yerde bileşen verir. Frekans düzlemine geçince bu bileşen görünür. Görüldüğü yerde genliği sıfıra çekilirse gürültü temizlenmiş olur. Hoca, fotoğraflardaki hareket bulanıklığı (motion blur) gibi bozulmaların da bununla ilgili olduğunu söyledi.

Asıl soru şudur: $x(t)$'den $X(f)$ ya da $X(\omega)$'ya nasıl geçeceğiz? Buna geçmeden önce işaretleri bir de başka açıdan ayırmak gerekiyor.

## 3. Periyodik ve Periyodik Olmayan İşaretler

İşaretleri daha önce dijital ve analog diye ayırmıştık. Şimdi periyodik ve periyodik olmayan (aperiodic, nonperiodic) diye de ayırıyoruz. Periyodik olmak, kendini belli aralıklarla tekrar etmek demektir. Her $t$ için

$$x(t) = x(t + T)$$

sağlayan bir $T$ varsa işaret periyodiktir. Ayrık zamanda da her $n$ için aynı koşul geçerlidir: $x[n] = x[n + N]$. Hoca ayrık durumda da periyodu sözlü olarak $T$ diye andı. Bu koşul sağlanmıyorsa işaret periyodik değildir.

Örneğin sinüzoidal bir işaret kendini belli aralıklarla tekrar eder. Bir genliği ve bir periyodu vardır, periyottan frekansı buluruz. Kendini sürekli tekrar ettiği için tamamını değil, bir periyodunu analiz etmek yeterlidir. Böylece tamamını analiz etmiş oluruz. Bu yüzden periyodik işaretleri analiz etmek daha kolaydır.

Buradan bir soru çıkar: Periyodik olmayan bir işareti periyodik hale getirebilir miyiz? Hocanın aktardığı düşünce şöyledir: Periyodik olmayan bir işaretin bir ucunu $-\infty$, öbür ucunu $+\infty$ gibi düşünün. Bu işaretin $-\infty$ ile $+\infty$ arasında bir periyodu olduğunu kabul ederek onu periyodik bir işaretmiş gibi analiz edebiliriz. Fourier serileri ve Fourier dönüşümü bu yoldan çıkar. Bunların daha genelleştirilmiş halleri olan Laplace ve z dönüşümleri de buradan türemiştir.

## 4. Sinüzoidlerle Yazma Fikri ve Ses Sentezi

İkinci soru şudur: Bu işareti periyodik işaretler cinsinden yazabilir miyiz? Burada temel doğal işaret dediğimiz sinüzoidler devreye girer, çünkü kendileri doğal olarak periyodiktir. "Herhangi bir işaret sonsuz sayıda sinüzoidal işaretin toplamından oluşur" düşüncesine Fourier analizi denir. Hoca bu düşüncenin Fourier'in ortaya attığı bir fikir olduğunu, kısmen doğru olduğunu, bazı yanlışları olsa da genel olarak doğru kabul edildiğini söyledi. Bu yanlışların ne olduğunu açmadı.

Sonsuz tane sinüzoidi toplayarak işareti yazarsak, sinüzoidler periyodik olduğu için analiz kolaylaşır. Bu, Taylor ya da MacLaurin serilerinde yapılana benzer. Hoca sayısal analiz tarafında da sinüs ve kosinüs cinsinden yazma konusunun bulunduğunu belirtti. <!-- BELİRSİZ: 00:19:58 altyazıda "sayısal alanında" geçiyor; "sayısal analiz" dersi kastedilmiş olabilir. -->

Buradaki amaç, işaret ne olursa olsun onun %90'ını, %95'ini temsil eden temel sinüzoidleri bulmak ve onları analiz etmektir. Bu, işaretin kendisini analiz etmek gibidir.

Bu fikir ses sentezinde ve ses analizinde çok kullanılır:

- **Otobüslerdeki durak anonsları:** Robot gibi konuşan elektronik seste bir sentez vardır. Her harf kendi frekansları cinsinden sentezlenir. Bu temel frekanslardaki sinüzoidler toplanır.
- **Telefon tuşları (DTMF):** Geçen konuşulan örnekte her tuşun iki sinüzoidal bileşeni vardı. Heceler, harfler ve müzikteki notalar için de durum benzerdir, hepsinin kendine ait frekans bileşenleri vardır.
- **Kare dalga:** Kare dalga fonksiyon jeneratöründe, devre teorisi gibi derslerde simülatörlerde üretilebilir. Hocaya göre bir bilgisayar sisteminde ideal bir kare dalgayı doğrudan üretmek mümkün değildir, belli bir kayıp olur ve köşelerde yuvarlanmalar görülür. Bunun yerine kare dalgayı çok iyi temsil eden 5-6 sinüzoidal bileşenle Fourier analizi yoluyla ona benzer bir işaret üretilebilir.

## 5. Shazam ve Kare Dalga Gösterimi

Hoca burada Shazam'ın nasıl çalıştığını anlatan bir sayfa gösterdi. Shazam, telefona dinletilen müziğin hangi parçaya ait olduğunu örneğin 20 saniyelik bir kesitten bulur. Dalga biçimindeki analog sinyalin dijitale çevrilmiş halini dinletirsiniz. Uygulama ses özelliklerinden veri tabanındaki müziğin parmak izini bulur, eşleştirir ve parçayı söyler.

Bir başka sürümde müziği dinletmeyip melodisini mırıldanırsınız. Yine aynı şekilde özellik çıkarılır. Çünkü müzik düzgün icra edildiğinde bir nota insan sesiyle de söylense, bir enstrümanla da çalınsa aynı notadır. Fark sadece ritimdedir, ritim de ayrı bir bileşendir.

Zaman düzleminde doğrudan eşleştirme yapmak mümkün değildir, çünkü çok sayıda girişim (interference) ve gürültü vardır. Bunun yerine frekans düzlemine geçilir, baskın frekans bilgileri ve başka ayırt edici özellikler çıkarılır, müzik bunlarla tespit edilir.

Sayfadaki gösterimler de şöyleydi:

- Frekansı 1 kHz olan sinüzoid frekans düzleminde incelendiğinde 1 kHz'de bir bilgi vardır, 2 kHz'de yoktur.
- Sıklık artırılınca 2 kHz'deki bilgi artar.
- İkisi toplanınca iki bileşenin birleşimi olan bir işaret elde edilir.

Aynı sayfada kırmızıyla bir kare dalga gösteriliyordu. Temel frekansı yaklaşık 1 Hz olan bu dalga; 1, 3, 5, 7, 9 Hz'lik sinüzoidlerin toplamıyla yaklaşık olarak elde ediliyordu. Süreksizlik noktalarında sivri bir kulak gibi bir taşma görülür. Buna Gibbs olayı (Gibbs phenomenon) denir. Hoca bunun kare dalganın süreksizlik noktalarından kaynaklandığını, normal olduğunu söyledi. Yani bu işaret 7-8 sinüzoidal bileşenle oluşturulabilir.

> **Ek bilgi (derste anlatılmadı):** Gibbs taşması terim sayısı artırılınca kaybolmaz. Bu dersin 15. bölümündeki kare dalganın kısmi toplamları sayısal olarak hesaplandığında, en büyük değer 99. harmoniğe kadarki toplamda da 1999. harmoniğe kadarki toplamda da yaklaşık $1.0895$ çıkar. Yani taşma, sıçrama yüksekliğinin ($1$) yaklaşık %9'u kadardır. Terim arttıkça taşma süreksizlik noktasına yaklaşır, ortalama karesel hata ise azalır.

Herhangi bir ses dosyasının ya da sinyalin frekans bileşenleri ayırt edilip genlikleri analiz edilerek işaret hakkında bilgi çıkarılabilir. İşaret periyodikse bir periyodunu analiz etmek yeterlidir. Değilse daha ayrıntılı analiz gerekir. Orada da bazı darboğazlar vardır ve çözümleri üretilmiştir. Bu derste bunların kavramlarıyla ilgilenilecektir.

## 6. Örnekleme ve Örtüşme

Hoca, örnekleme (sampling) ve örtüşme (aliasing) konusunu dönem sonuna saklamayı düşündüğünü, ama temellerinin burada gerektiğini söyleyerek kısaca açtı.

**Soru:** Örnekleme ne için yapılıyordu?
**Cevap:** Analog sinyali dijitale dönüştürmek için, yani $x(t)$ gibi bir işaretten $x[n]$ gibi bir işaret elde etmek için.

**Soru:** Bu dönüşümde örnekleme frekansını nasıl seçiyorduk? Bir öğrenci "minimum frekansın iki katı" dedi.
**Cevap:** Hoca bunu düzeltti. Örnekleme frekansı en yüksek frekans bileşeninin en az iki katı olmalıdır:

$$f_s \ge 2 f_{max}$$

Buradaki $f_{max}$, 2.1'de frekans eksenindeki en yüksek bileşendir. İki katı olmasının sebebi, geri elde ederken frekansların birbirine karışmamasıdır. Hem sağlıklı geri çatma (reconstruction) için hem de örtüşmeyi önlemek için en az iki katı gerekir.

**Soru:** İki katını seçtikten sonra dönüşümü nasıl yapacağız? "$t$ gördüğümüz yere $1/f_s$ yazacağız" diye bir cevap geldi.
**Cevap:** Eksik. $t$ yerine yalnız $1/f_s$ yazarsak $n$'ye bağlı bir şey elde etmeyiz. Örneğin $f_s = 1000$ Hz seçtik, $t$ yerine $1/1000$ yazarsak ortada yalnız sayısal bir büyüklük kalır. Doğrusu $t$ yerine $n$ çarpı $T_s$ yazmaktır:

$$t = n T_s = \frac{n}{f_s}$$

$f_s = 1000$ Hz için $t = n/1000$ olur. Burada $f_s$ bir sayıdır, $n$ de yeni değişkenimizdir. Böylece $t$ düzleminden $n$ düzlemine geçeriz.

Örtüşmeyi önlemek için $f_{max}$'ı bilmek gerekir. $f_{max}$'ı bulmak için de frekans düzlemine bakmak lazımdır. Yani örnekleme de bir bakıma frekans düzlemine geçişten geçer. İşaret periyodikse ve tek sinüzoidal bileşen içeriyorsa bu belki doğrudan yapılabilir. Ama işaret periyodik değilse ve içinde çok sayıda frekans bileşeni varsa frekans analizi şarttır.

Günlük hayattaki ses dosyalarında 44100 değerini görürüz. Bu da aynı kuraldan gelir: $44100 / 2 = 22050$. Yani bu değer, yaklaşık 22050 Hz'e kadarki bileşenler için, cihazlar ve insan sesi dikkate alınarak verilmiştir. Hoca DVD kalitesinde bu oranın biraz daha yüksek olabileceğini de ekledi. <!-- BELİRSİZ: 00:29:08 DVD için söylenen değer altyazıda net değil ("1-2 versinden fazlayabilir"). -->

> **Ek bilgi (derste anlatılmadı):** $f_s \ge 2 f_{max}$ kuralı Nyquist örnekleme ölçütü olarak bilinir. CD kalitesi büyük olasılıkla $44.1$ kHz, DVD sesi ise büyük olasılıkla $48$ kHz ve üzeridir.

## 7. Fourier Serisi mi, Fourier Dönüşümü mü?

$x[n]$ örnekleme ile elde edilmiş ya da doğrudan kaydedilmiş olabilir, elimizde $x(t)$ de olabilir. Her iki durumda frekans düzlemine geçmek için Fourier yöntemlerini kullanırız. Burada iki strateji vardır ve ilk soru "işaret periyodik mi?" sorusudur:

- İşaret periyodikse Fourier serileri kullanılır.
- İşaret periyodik değilse Fourier dönüşümü kullanılır.

Her ikisinin sonucu da frekans analizidir.

> **Hocanın vurgusu:** Periyodik bir işarete Fourier dönüşümü uygulamak gereksiz iş yüküdür. Bir periyot boyunca çalışmak yeterlidir. Örneklemede bile frekans tarafı işimize yarıyor.

Fourier'in asıl ortaya attığı şey Fourier serileridir. Fourier dönüşümü ve integral dönüşümleri daha sonra serilerin genelleştirilmesinden çıkmıştır. Bu yüzden ders önce Fourier serileriyle devam ediyor. Slayttaki sırada bundan sonra sürekli zaman Fourier dönüşümü ve Laplace dönüşümü geliyor.

## 8. Fourier Serisinin Temel Fikri

Fourier analizi, herhangi bir periyodik sinyali sinüzoidlerin toplamı cinsinden yazmayı sağlar. Sinüzoidal bir işaretin genel hali şöyledir:

$$A \cos(2\pi f t + \theta)$$

Burada $A$ genlik, $f$ frekans, $\theta$ fazdır. Hoca fazı sözlü olarak çoğunlukla "fi" diye okudu. Bu notta faz için kısa notla uyumlu olarak $\theta$ kullanılıyor.

Her bileşenin kendi genliği, frekansı ve fazı olursa, bunları toplayarak işaretin kendisini buluruz:

$$x(t) = \sum_{i=0}^{\infty} A_i \cos(2\pi f_i t + \theta_i)$$

Ayrık zamanda da durum aynıdır. $t$ yerine $n$, $f$ yerine belki büyük omega ($\Omega$) koyulur, başka bir şey yapılmaz. Amacımız önce periyodik bir sinyal olacak, sonra daha ilerisine bakılacak. Bu aslında karmaşık bir işareti bilinen işaretler cinsinden yazmak, yani karmaşık bir olguyu bilinenlerle basitleştirmektir.

### 8.1 Neden Sinüzoidler?

Hoca sinüzoidlerin seçilme nedenlerini şöyle sıraladı:

- **Periyodiktirler.** Kare dalga da periyodiktir, bu tek başına ayırt edici değildir.
- **Sonsuz kez türevlenebilirler.** Kare dalgadan farkı budur.
- **Doğal işaretlere çok yakındırlar.** Bunu göstermek için hoca bir deney önerdi.
- **Genlik, frekans ve faz bilgisi çok rahat ifade edilir.**

**Soru:** Bir mikrofonu hoparlöre yaklaştırırsanız ne duyarsınız?
**Cevap:** Yankı yapar, kötü, tiz bir ses çıkar. Hoca bu tiz sesi çizdirmeye kalkarsanız doğal bir sinüzoidal işaret, kosinüs ya da sinüs biçiminde bir işaret elde edeceğinizi söyledi.

### 8.2 Sistem Analizinde Sinüzoidler

Örneğin bir RL devresinde giriş $A \cos(\ldots)$ biçimindeyse devrede belli bir işlem gerçekleşir, çıkışta da benzer biçimde bir işaret elde edilir. Bunu analiz etmek kolaydır.

Bir diferansiyel denklemle tanımlı bir sistem düşünelim. Girişe sinüzoidal bir işaret verdiniz ve çıkışın da sinüzoidal biçimde olduğunu kabul ediyorsunuz. Giriş ile çıkış arasındaki bağıntı, yani transfer fonksiyonu, sinüzoidler cinsinden çok rahat ifade edilir ve sistemin karakteristiği kolayca analiz edilir. Fourier serisinin ve dönüşümünün özelliğinden diferansiyel denklem çözmeye gerek kalmadan, denklem $\omega_0$ ve katsayıları içeren normal cebirsel bir denkleme dönüşür. Bu denklem çözülüp ters dönüşüm yapılarak $y(t)$ ile $x(t)$ arasındaki bağıntı bulunur ve diferansiyel denklemden kurtulunur. <!-- BELİRSİZ: 00:35:23-00:35:46 slayttaki diferansiyel denklem ve cebirsel karşılığı altyazıda okunmuyor ("omega 0 kare A1 çarpı omega 0"). Kare yok. -->

> **Ek bilgi (derste anlatılmadı):** Cebirsel denkleme dönüşmenin nedeni türevin etkisidir. $\dfrac{d}{dt} e^{j\omega t} = j\omega\, e^{j\omega t}$ olduğu için, üstel biçimde yazılan bir bileşenin her türevi yalnız $j\omega$ çarpanı getirir. Böylece denklemdeki türevler $\omega$'lı çarpanlara dönüşür.

Nihai hedef, herhangi bir işareti sinüzoidlerin doğrusal kombinasyonu olarak yazmaktır. Her bileşenin kendi $A_i$, $\omega_i$ ve $\theta_i$ değeri vardır. Doğrusallık (linearity) özelliği sayesinde her bileşen ayrı bir sinyal gibi düşünülebilir. Çıkış için de aynısı geçerlidir. Bu, diferansiyel denklem çözmeyi, analizi ve hatta sentezi kolaylaştırır.

## 9. Temel Frekans, Harmonikler, Genlik ve Fazın Etkisi

$\omega_0$ işaretin temel frekansı olsun. Diğer bileşenler bunun katlarıdır: 1 katı, 2 katı, 3 katı. Slaytta frekans rad/s cinsinden veriliyordu:

- Temel frekans 30 rad/s ise bileşenler $0, 30, 60, 90, \ldots$ diye gider.
- Temel frekans $2\pi$ rad/s ise birinci bileşen $2\pi t$, sonra $2 \cdot 2\pi t$, $3 \cdot 2\pi t$ diye gider.

Genliklerden biri sıfırsa o frekans bileşeni yok demektir. İşaretin sinüzoidal bileşenleri bu şekilde bulunur.

### 9.1 Genliğin ve Fazın Etkisi

Slaytta üç sinüzoidin toplamı gösterildi. Genlikler $1.0$, $0.5$, $0.5$; fazlar sırasıyla $0$, $\pi/4$, $\pi/2$ idi. <!-- BELİRSİZ: 00:37:50-00:39:05 slayttaki formül ve grafikler kare olmadığı için görülemedi. Değiştirilen genlik ve faz değerleri altyazıda söylenmedi. -->

- **Fazlar sabit, genlikler değişince:** Fazlar aynı tutulup genliklerden biri artırılıp biri azaltıldığında farklı bir işaret elde edildi. Yani genliği değiştirerek işaret değişiyor.
- **Genlikler sabit, fazlar değişince:** İşaret çok benzer görünüyor, ama dalgalanmada farklılıklar ve bazı yerlerde ters dönmeler görülüyor.

Hoca bu analizlerin çok işe yarayacağını söyledi.

Slaytta bu işaretlerin hepsinin periyodunun 1 saniye olduğu ve düşeyde sıfıra göre konumlandığı (eğrinin altındaki ve üstündeki alanların ilişkisi) söyleniyordu. Periyot 1 saniyedir, çünkü frekansların EBOB'u alınır: biri kendini 1 saniyede, biri $1/2$ saniyede, biri $1/3$ saniyede tekrar eder. Ortak tekrar süresi temel periyottur.

> **Ders sonrası not:** Hoca burada sözlü olarak önce "en küçük ortak kat", sonra "en büyük ortak kat, EBOB" dedi. Doğrusu en büyük ortak bölendir (EBOB, greatest common divisor).

Temel frekans $\omega_0$ cinsinden verilmişse temel periyot şöyledir:

$$T_0 = \frac{2\pi}{\omega_0}$$

Nihai hedef, herhangi bir işareti bu bileşenler cinsinden oluşturmaktır. Bu Taylor ve MacLaurin serileri gibidir, sadece karakteristik farklıdır. O halde bize gereken $x(t)$'den $A_k$ katsayılarını, temel frekansı ve faz bilgilerini bulmaktır. $k$ zaten birden başlayan tam sayılardır. $A_k$'ları bulmamızı sağlayacak bir dönüşüme ihtiyaç vardır. Faz da aynı yerden bulunur. İşaret periyodik olduğu için temel frekans doğrudan çıkar. Periyodik olmasaydı en yüksek frekans ya da temel frekans gibi bilgilere doğrudan erişemezdik ve başka araçlar gerekecekti.

Slayttaki frekans ekseninde bileşenler sıfır merkez alınarak yazılıyordu.

> **Hocanın vurgusu:** Bu ifadelerin ispatları elektronikçileri ilgilendiriyor, bize o kadar gerekmiyor. Bize asıl lazım olan $A_i$ kümesini, $\theta_i$ kümesini ve frekans bilgisini bulmaktır.

Ses sentezi de bu bilgilerle yapılır. Elimizde $A_i$ ve $\theta_i$ değerleri olan beş altı frekans bileşeni olur. Hepsi toplanınca bir ses elde edilir ve onun karakteristik analizi yapılır.

## 10. DC Bileşen, Analiz ve Sentez

İşaretin içinde temel frekansın katlarından başka, frekansı sıfır olan bir bileşen de bulunabilir. Buna DC bileşen (DC component) denir. Bu bileşen ayrı yazılır, çünkü $k = 0$ için kosinüsün içi sıfıra gider ve geriye sabit bir değer kalır. Frekansı da fazı da sıfırdır. Böylece seri şu biçimi alır:

$$x(t) = A_0 + \sum_{k=1}^{\infty} A_k \cos(k\omega_0 t + \theta_k), \qquad T_0 = \frac{2\pi}{\omega_0}$$

$A_0$'ı bulmak basit bir integraldir, buna 14. bölümde gelinecek.

Hoca bunu şöyle özetledi: Gerçek dünyadaki herhangi bir periyodik sinyal, temel frekansı $\omega_0$ olan ve bunun katlarını içeren sinüzoidlerin toplamından oluşabilir. Bu aslında Taylor açılımının biraz farklı halidir.

Temel frekans, $A_k$ katsayıları ve faz bilgileri verilirse orijinal sinyali elde etmek zor değildir. Yani sentez çok kolaydır, doğrudan yerine koymaktır. Analiz ise daha çok iş gerektirir, verilen periyodik sinyalden bu değerleri bulmak gerekir.

Analiz özellikle sinyal süreksizlik noktaları içeriyorsa zorlaşır. Hoca üçgen dalgayı örnek gösterdi: dalganın köşe noktasında çok sayıda sinüzoidal bileşen toplanır. Bir yerde kesmek gerekir. İşareti %90 ya da %95 oranında sağlıyorsa bu bizim için yeterlidir, o noktayı da hafif oval bırakabiliriz.

> **Ders sonrası not:** Üçgen dalganın değeri süreklidir, köşesinde süreksiz olan türevidir (sayısal denetimde kare dalganın sıçraması $1$ iken üçgen dalganın adımı örnekleme aralığıyla birlikte sıfıra gider). Değerin süreksiz olduğu örnek kare dalgadır. Köşede çok terim gerektiği gözlemi ise yine geçerlidir.

## 11. Fourier Serisinin Üç Gösterimi

Fourier serisinin üç formu vardır. Formül aslında aynıdır, yazımları farklıdır ve birbirinden türerler. Hoca YouTube'da bunların ispatlarını anlatan bir kanal olduğunu söyledi ve ispatlara girmedi. Sinüs ve kosinüs bileşenleri de her zaman açıkça görünmez, faza bağlı olarak değişir. Hangi formun kullanılacağı tercihe ve uygulamaya bağlıdır.

### 11.1 Genlik-Faz Formu

Yukarıdaki gösterimdir:

$$x(t) = A_0 + \sum_{k=1}^{\infty} A_k \cos(k\omega_0 t + \theta_k)$$

Genlik ve faz burada doğrudan görünür. Kosinüsler görünür, sinüsler görünmez.

### 11.2 Karmaşık Üstel Form

Euler formülünden yola çıkılır:

$$e^{j\omega t} = \cos \omega t + j \sin \omega t, \qquad e^{-j\omega t} = \cos \omega t - j \sin \omega t$$

Bu iki eşitlikten $\cos \omega t$ ve $\sin \omega t$ üstel ifadeler cinsinden yazılır. Taraf tarafa toplayınca kosinüs, çıkarınca sinüs bulunur (çıkarma adımı eklendi):

$$\cos \omega t = \frac{e^{j\omega t} + e^{-j\omega t}}{2}, \qquad \sin \omega t = \frac{e^{j\omega t} - e^{-j\omega t}}{2j}$$

Şimdi seriyi açalım:

$$x(t) = A_0 + A_1 \cos(1 \cdot \omega_0 t + \theta_1) + A_2 \cos(2\omega_0 t + \theta_2) + \cdots$$

Birinci bileşene yukarıdaki kosinüs ifadesini uygulayalım. Toplamın üsteli, üstellerin çarpımı olarak yazılır:

$$A_1 \cos(\omega_0 t + \theta_1) = \frac{A_1}{2} e^{j\theta_1} e^{j \cdot 1 \cdot \omega_0 t} + \frac{A_1}{2} e^{-j\theta_1} e^{-j \cdot 1 \cdot \omega_0 t}$$

Faz ve genlik bilgisini saklayan parçaya $c$ katsayısı denir:

$$c_k = \frac{A_k}{2} e^{j\theta_k}, \qquad c_{-k} = \frac{A_k}{2} e^{-j\theta_k}$$

Geri kalan $e^{jk\omega_0 t}$ çarpanında yalnız frekans bilgisi vardır. Baştaki $A_0$ ise doğrudan $c_0$'a eşittir. Yani genlik ve fazı $c$'nin içine kapatıp sadece frekans bilgisini gösteren karmaşık bir forma geçmiş olduk:

$$x(t) = \sum_{k=-\infty}^{\infty} c_k\, e^{jk\omega_0 t}$$

Bu formdan öbürüne geçmek de mümkündür. Bazen biri, bazen öteki işimize yarar.

### 11.3 Sinüs-Kosinüs Formu

Genlik-faz formunda sinüsler görünmüyordu. Onları da görmek istersek kosinüsün toplam formülünü kullanırız:

$$\cos(\alpha + \beta) = \cos\alpha \cos\beta - \sin\alpha \sin\beta$$

$A_0$ aynen kalır. Birinci bileşen şöyle açılır:

$$A_1 \cos(\omega_0 t + \theta_1) = A_1 \cos\theta_1 \cos(\omega_0 t) - A_1 \sin\theta_1 \sin(\omega_0 t)$$

İlk terimin katsayısında ve ikinci terimin katsayısında faz ile genlik birlikte saklıdır. Fark, birinin kosinüsün, ötekinin sinüsün önünde olmasıdır. Kosinüslü olana $a$, sinüslü olana $b$ deriz. İkinci ve sonraki bileşenlerde de aynısı yapılır. Geri kalan taraf yalnız frekans bilgisi içerir. Toplam sembolüyle yazarsak:

$$x(t) = a_0 + \sum_{k=1}^{\infty} \left[ a_k \cos(k\omega_0 t) + b_k \sin(k\omega_0 t) \right]$$

Burada $a_k = A_k \cos\theta_k$ ve $b_k = -A_k \sin\theta_k$ olur.

Hoca literatürde çoğunlukla $a_k$, $b_k$ ya da $c_k$ bulunduğunu, $c_k$ bulunup $a_k$, $b_k$'ya geçildiğini söyledi. Biz de daha çok bu iki eşitliği, yani karmaşık üstel ve sinüs-kosinüs formlarını kullanacağız.

## 12. Gösterimler Arasında Dönüşüm

Aradan sonra hoca üç gösterimi bir arada topladı. $A_0$ DC bileşendir, geri kalanlar sinüzoidal bileşenlerdir ve bu bizim gerçek dünya için ideal modelimizdir. Dönüşümlerin uzun ispatları vardır, hoca onlara girmedi ve isteyene kaynak paylaşabileceğini söyledi.

Bir formu biliyorsak öbürünü şöyle buluruz:

$$c_0 = a_0 = A_0$$

$$c_k = \frac{1}{2} A_k e^{j\theta_k}, \qquad c_{-k} = \frac{1}{2} A_k e^{-j\theta_k}$$

$$a_k = 2\,\text{Re}\{c_k\}, \qquad b_k = -2\,\text{Im}\{c_k\}$$

$$A_k = \sqrt{a_k^2 + b_k^2}, \qquad \theta_k = \arctan\!\left(\frac{-b_k}{a_k}\right)$$

$A_k$ bir büyüklük (magnitude), $\theta_k$ ise açı değeridir. Hoca, fazör gösteriminin elektronikçiler ve haberleşmeciler tarafından çok kullanıldığını, bizim hepsini kullanmayacağımızı söyledi.

> **Hocanın vurgusu:** Bu formülleri bir kenara not edin, size lazım olacak. Gidip slayttan bulmak yerine buradan çekmek daha kolay olur. Özellikle $a_k = 2\,\text{Re}\{c_k\}$ ve $b_k = -2\,\text{Im}\{c_k\}$ daha çok işimize yarayacak. Örneklerde önce $c_k$'ları bulup sonra $a_k$, $b_k$'ya geçeceğiz.

## 13. Örnek: Üç Bileşenli İşaretin Gösterimleri

Slaytta bileşenlerine ayrılmış şu sinyal verildi:

$$x(t) = \cos(t) + 0.5 \cos\!\left(4t + \frac{\pi}{3}\right) + 0.25 \cos\!\left(8t + \frac{\pi}{2}\right)$$

<!-- BELİRSİZ: 01:09:28 hoca üçüncü genliği sözlü "0.3" diye okudu; 0.25 değeri kısa nottan alındı, kare olmadığı için slaytla doğrulanamadı. -->

**Temel frekans.** Frekanslar $1$, $4$ ve $8$'dir. EBOB'ları $1$ olduğu için $\omega_0 = 1$.

**Genlik ve faz.** İkinci bileşen 4. kat, üçüncü bileşen 8. kat olduğu için:

- $A_1 = 1$, $\theta_1 = 0$.
- $A_4 = 0.5$, $\theta_4 = \pi/3$.
- $A_8 = 0.25$, $\theta_8 = \pi/2$.

Diğer bütün $A_k$'lar sıfırdır, sonsuz tane katsayının yalnız üçü sıfırdan farklıdır. $A_0$ da yoktur, yani $c_0 = 0$.

**Karmaşık üstel form.** $c_k = \frac{1}{2} A_k e^{j\theta_k}$ kuralı kullanılır:

- $c_{\pm 1} = \frac{1}{2} \cdot 1 \cdot e^{\pm j \cdot 0} = 0.5$
- $c_{\pm 4} = \frac{1}{2} \cdot 0.5 \cdot e^{\pm j\pi/3} = 0.25\, e^{\pm j\pi/3}$
- $c_{\pm 8} = \frac{1}{2} \cdot 0.25 \cdot e^{\pm j\pi/2} = 0.125\, e^{\pm j\pi/2}$

$c_k e^{jk\omega_0 t}$ biçiminde yazıp $\omega_0 = 1$ koyarsak:

$$x(t) = 0.5\, e^{jt} + 0.5\, e^{-jt} + 0.25\, e^{j\pi/3} e^{j4t} + 0.25\, e^{-j\pi/3} e^{-j4t} + 0.125\, e^{j\pi/2} e^{j8t} + 0.125\, e^{-j\pi/2} e^{-j8t}$$

**Sinüs-kosinüs form.** $a_k = 2\,\text{Re}\{c_k\}$ ve $b_k = -2\,\text{Im}\{c_k\}$ uygulanır. Bunun için $c_k$'yı önce gerçel ve sanal kısmına ayırmak gerekir (ara adım eklendi):

- $c_1 = 0.5$: $a_1 = 1$, $b_1 = 0$.
- $c_4 = 0.25(\cos\frac{\pi}{3} + j \sin\frac{\pi}{3}) = 0.125 + j\,0.2165$: $a_4 = 0.25$, $b_4 = -0.433$.
- $c_8 = 0.125(\cos\frac{\pi}{2} + j \sin\frac{\pi}{2}) = j\,0.125$: $a_8 = 0$, $b_8 = -0.25$.

Sonuç:

$$x(t) = \cos t + 0.25 \cos 4t - 0.433 \sin 4t - 0.25 \sin 8t$$

Üç gösterimin aynı işareti verdiği python ile sayısal olarak doğrulandı. Fark, kayan nokta hata düzeyindedir ($10^{-15}$ mertebesi).

> **Ders sonrası not:** Hoca $A_8$'i sözlü olarak "0.3" diye okudu. Kısa nota göre slaytta büyük olasılıkla $0.25$ yazıyordu. Değer gerçekten $0.3$ olsaydı $c_{\pm 8} = 0.15\, e^{\pm j\pi/2}$ ve $b_8 = -0.3$ olurdu. Kısa nota göre slayttaki son satırlarda da büyük olasılıkla $b_4 = 0.43$ ve $b_8 = 0.25$ biçiminde işaret hataları vardı. Yukarıdaki formüllerle doğrusu hesapla kesinleşmiştir: $b_4 = -0.433$ ve $b_8 = -0.25$, çünkü $0.25 \cos(8t + \pi/2) = -0.25 \sin 8t$.

Hoca bu örneğin analitik kısmının kolay olduğunu, çünkü işaretin zaten bileşenlerine ayrılmış verildiğini söyledi. Asıl iş analizdir.

## 14. Katsayıları İntegralle Bulmak

Bulmamız gereken şeyler bellidir. $\omega_0$ kolay bulunur, $k$ tam sayıdır, $t$ değişkendir, $j$ sabittir. Geriye $c_k$'lar ya da $a_0$, $a_k$, $b_k$ kalır. Hoca bu işi $c_k$'lar üzerinden yapmanın mantıklı olduğunu söyledi.

İşaret periyodik olduğu için bir periyot boyunca integral almak yeterlidir. Herhangi bir $t_0$ noktasından başlayıp $t_0 + T$'ye kadar gideriz ve ortalamasını alırız:

$$c_k = \frac{1}{T} \int_{t_0}^{t_0 + T} x(t)\, e^{-jk\omega_0 t}\, dt$$

Burada $T$ temel periyot, $\omega_0$ temel frekans, $t_0$ işaret üzerinde seçilen herhangi bir nokta, $k$ ise tam sayıdır. Örneklerdeki işaretler kare dalga gibi basit olacak, integralin içindeki değer $1$, $0$ ya da $t$ gibi bir şey olacaktır.

### 14.1 İntegralin Yorumu

İşaretin neden $e^{-jk\omega_0 t}$ ile çarpıldığına bakalım. Euler formülüyle açarsak:

$$e^{-jk\omega_0 t} = \cos(k\omega_0 t) - j \sin(k\omega_0 t)$$

$x(t)$'yi dağıtınca iki integral çıkar: biri $x(t)$ çarpı kosinüs, öbürü $x(t)$ çarpı sinüs. Birincisi işaretin içindeki kosinüs bileşenlerini, ikincisi sinüs bileşenlerini bulur. Yani kosinüslerin katsayılarını ($a_k$) ve sinüslerin katsayılarını ($b_k$) buluyoruz. Üstel işaretle çarpmak arka planda zaten kosinüs ve sinüsleri bulur.

Hoca bu işlemi konvolüsyona benzetti. Bu sayede işaretin içinde olabilecek bütün kosinüs ve sinüs bileşenlerinin değerleri bulunur. Konvolüsyonda iki kare üst üste geldiğinde değerin tepe yapması gibi, bir şey ararken benzerlik olan yerde tepe oluşması gibi, burada da tepe noktaları bu integral sayesinde bulunur. İşaretin içinde o frekans yoksa integral sıfıra gider.

> **Ders sonrası not:** Hoca bu integrale "konvolüsyon" dedi. Yazılan işlemde ters çevirme ve kaydırma yoktur. Bu, işaretin $e^{-jk\omega_0 t}$ ile bir periyot boyunca çarpılıp integre edilmesidir, yani bir iç çarpım (korelasyon) işlemidir. Benzerlik sezgisi yine geçerlidir. Altyazıda açılım $\cos - \sin$ diye geçiyor, doğrusunda sinüsün önünde $j$ vardır.

> **Ek bilgi (derste anlatılmadı):** Başka frekansların sıfıra gitmesinin nedeni karmaşık üstellerin dikliğidir: $\frac{1}{T}\int_T e^{jm\omega_0 t} e^{-jk\omega_0 t} dt$ değeri $m = k$ için $1$, $m \ne k$ için $0$'dır. Seri $c_k$ integraline yerleştirilince yalnız aynı frekanslı terim kalır. Bu sonuç sayısal olarak doğrulandı.

### 14.2 DC Bileşen

$c_k$ formülünde $k = 0$ koyunca üstel $1$ olur. DC değerini bulmak için işareti bir periyot boyunca integre etmek yeterlidir:

$$c_0 = \frac{1}{T} \int_{t_0}^{t_0 + T} x(t)\, dt$$

Bu, işaretin bir periyotta kapladığı alanla ilgilidir. Örneğin sinüs işaretinin bir periyodu boyunca integrali sıfırdır, dolayısıyla DC bileşeni yoktur. Sinüs tek bir sinyaldir ve yalnız sinüzoidal bileşenler içerir.

### 14.3 $a_k$ ve $b_k$ Doğrudan

$c_k$'yı bulduktan sonra diğerlerine geçmek kolaydır. Ama isterseniz doğrudan da gidebilirsiniz. $a_0$ zaten $c_0$ ile aynıdır, formül değişmez. $a_k$ için işaret bir periyot boyunca kosinüsle, $b_k$ için sinüsle integre edilir:

$$a_k = \frac{2}{T} \int_{T} x(t) \cos(k\omega_0 t)\, dt, \qquad b_k = \frac{2}{T} \int_{T} x(t) \sin(k\omega_0 t)\, dt$$

$c_k$ integrali aynı anda hem kosinüsle hem sinüsle integral almaktır. Açınca kendi içinden iki integral çıkar. İkisi aslında aynı şeydir, biri bir adım daha açılmıştır. $2/T$ çarpanı, $c_k$'nın açılımından ve $a_k = 2\,\text{Re}\{c_k\}$, $b_k = -2\,\text{Im}\{c_k\}$ ilişkisinden gelir (ara adım eklendi).

Küçük $a_k$, $b_k$ bulunduktan sonra istenirse $A_k$ ve faz da 12. bölümdeki eşitliklerle bulunur.

## 15. Örnek: Kare Dalganın Fourier Serisi

Slaytta bir kare dalga verildi ve içindeki sinüzoidal bileşenlerin analizi istendi. İki formülden biriyle yapılabilir.

**Periyot ve temel frekans.** Önce sinyalin periyodik olup olmadığına bakılır. Sinyal periyodiktir, kendini 2 saniyede bir tekrar eder:

$$x(t) = \begin{cases} 1, & 0 \le t < 1 \\ 0, & 1 \le t < 2 \end{cases}, \qquad T = 2$$

<!-- BELİRSİZ: 01:18:49-01:20:39 sinyalin grafiği görülemedi; tanım hocanın "0'dan 1'e bir, 1'den 2'ye sıfır" anlatımından kuruldu. -->

$T$'den $f$'ye, $f$'den $\omega$'ya geçeriz:

$$f = \frac{1}{T} = \frac{1}{2}, \qquad \omega_0 = 2\pi f = \pi \text{ rad/s}$$

**Katsayı integrali.** Bir periyodu analiz etmek yeterlidir. $t_0 = 0$ seçilir, integral $0$'dan $2$'ye gider:

$$c_k = \frac{1}{2} \int_0^2 x(t)\, e^{-jk\pi t}\, dt$$

Fonksiyon parçalı olduğu için integral iki parçaya bölünür. $0$'dan $1$'e $x(t) = 1$, $1$'den $2$'ye $x(t) = 0$'dır, ikinci parça doğrudan gider:

$$c_k = \frac{1}{2} \int_0^1 e^{-jk\pi t}\, dt$$

Hoca burada $e^{at}$'nin integralini hatırlattı: $e^{at}$ aynen yazılır, $t$'nin önündeki $a$ altına yazılır. Burada $a = -jk\pi$ olduğu için:

$$c_k = \frac{1}{2} \cdot \frac{e^{-jk\pi t}}{-jk\pi} \Bigg|_0^1 = \frac{j}{2k\pi} \left( e^{-jk\pi} - 1 \right)$$

Son adımda $t = 1$ için $e^{-jk\pi}$, $t = 0$ için $e^0 = 1$ gelir ve $\frac{1}{-j} = j$ olur.

**$e^{-jk\pi}$'nin değeri.** Euler ile açalım:

$$e^{-jk\pi} = \cos(k\pi) - j \sin(k\pi)$$

$k$ tam sayıdır. Birim çember üzerinde $\cos(1\pi) = -1$, $\cos(2\pi) = +1$, yani kosinüs bir $-1$ bir $+1$ olur. Sinüs ise $\pi$'nin bütün katlarında sıfırdır. Dolayısıyla $e^{-jk\pi} = (-1)^k$.

- $k$ çift ve sıfırdan farklıysa: $c_k = \frac{j}{2k\pi}(1 - 1) = 0$.
- $k$ tekse: $c_k = \frac{j}{2k\pi}(-1 - 1) = -\dfrac{j}{k\pi}$.

**DC bileşen.** $k = 0$ için ayrıca hesaplanır. Üstel $1$ olur:

$$c_0 = \frac{1}{2} \int_0^1 1\, dt = \frac{1}{2} \cdot t \Big|_0^1 = \frac{1}{2}$$

> **Ders sonrası not:** Hoca $k = 0$ için de "$1 - 1 = 0$ olur" dedi. Ancak $k = 0$'da kapalı formülün paydası da sıfırdır ($0/0$), bu yüzden formül $k = 0$ için kullanılmaz. Doğru değer, hocanın ayrıca hesapladığı $c_0 = 1/2$'dir.

Toplu halde:

$$c_k = \begin{cases} \dfrac{1}{2}, & k = 0 \\[2mm] 0, & k \text{ çift ve } k \ne 0 \\[2mm] -\dfrac{j}{k\pi}, & k \text{ tek} \end{cases}$$

**Sinüs-kosinüs forma geçiş.** Gerçel kısmın 2 katı $a_k$'yı, sanal kısmın $-2$ katı $b_k$'yı verir. Tek ve çift ayrı ayrı bakılır:

- $a_0 = c_0 = 1/2$. Başka $a_k$ yoktur, $k \ne 0$ için $c_k$'nın gerçel kısmı sıfırdır.
- $k$ çift için $b_k = 0$.
- $k$ tek için $\text{Im}\{c_k\} = -\dfrac{1}{k\pi}$, $-2$ ile çarpınca $b_k = \dfrac{2}{k\pi}$.

Yani bu işarette DC bileşen ve sinüsler vardır, kosinüs bileşeni yoktur.

**Karmaşık üstel form.** Terimler $k = \pm 1, \pm 3, \pm 5, \ldots$ için yazılır:

$$x(t) = \frac{1}{2} + \sum_{k \text{ tek}} \left( -\frac{j}{k\pi} \right) e^{jk\pi t}$$

Yani $-j/\pi$, $-j/(-\pi) = j/\pi$, $-j/(3\pi)$ ve $5\pi$, $7\pi$ diye tek sayılarla devam eder.

**Sinüs-kosinüs sonucu.** $a_k$, $b_k$ formülde yerine yazılınca ve $\omega_0 = \pi$ koyulunca:

$$x(t) = \frac{1}{2} + \frac{2}{\pi} \left[ \sin(\pi t) + \frac{1}{3} \sin(3\pi t) + \frac{1}{5} \sin(5\pi t) + \cdots \right]$$

Sayısal integralle $k = -7, \ldots, 7$ için $c_k$, $a_k$ ve $b_k$ değerleri bu sonuçlarla aynı çıktı: $b_1 = 0.6366$, $b_3 = 0.2122$, $b_5 = 0.1273$, $b_7 = 0.0909$.

Hoca sadece sinüs çıkmasını işaretin tek fonksiyon olmasına bağladı. Kosinüs çift, sinüs tek fonksiyondur. Tek fonksiyonların toplamı da tek fonksiyondur.

> **Ders sonrası not:** $x(t)$'nin kendisi tek değildir, ortalaması $1/2$'dir. Tek olan $x(t) - \frac{1}{2}$'dir (sayısal olarak doğrulandı). Bu yüzden $1/2$ DC terimini ayırınca geriye yalnız sinüsler kalır.

**Genlik-faz formu.** Faz analizi yapılacaksa büyük $A_k$ ve $\theta_k$ da formüle yerleştirilir: DC bileşen, sonra birinci, ikinci, üçüncü bileşen faz farkıyla birlikte yazılır. Bu örnekte $k$ tek için $A_k = \frac{2}{k\pi}$ ve $a_k = 0$ olduğu için $\theta_k = -\frac{\pi}{2}$'dir:

$$x(t) = \frac{1}{2} + \sum_{k \text{ tek}} \frac{2}{k\pi} \cos\!\left( k\pi t - \frac{\pi}{2} \right)$$

Hocanın dediği gibi, kosinüse bu kadar faz farkı verirseniz sinüs elde edersiniz. Bu form ile sinüslü formun aynı olduğu sayısal olarak doğrulandı.

Hoca bir sonraki derste bu değerleri MATLAB'de kullanıp üç beş sinüzoidal bileşeni toplayarak kare dalgaya yakın bir sonuç elde edeceğini söyledi. Çift ve tek fonksiyon örnekleri ve birkaç ayrıntı da sonraya kaldı.

## Dersin Toparlaması

Bu derste frekans düzleminin ne işe yaradığı görüldü: temel frekans bileşenlerin EBOB'u ile bulunur, gürültü temizleme ve müzik tanıma gibi işler frekans bilgisiyle kolaylaşır, örnekleme bile $f_{max}$'ı bilmeyi gerektirir. Periyodik işaretler için Fourier serisi, periyodik olmayanlar için Fourier dönüşümü kullanılır. Fourier serisinin genlik-faz, karmaşık üstel ve sinüs-kosinüs olmak üzere üç gösterimi vardır ve aralarında geçiş formülleri bellidir. Asıl iş, işaretten katsayıları bulmaktır. Bunun için $c_k$ integrali bir periyot üzerinde alınır, sonra $a_k$ ve $b_k$'ya geçilir. Kare dalga örneğinde $c_0 = 1/2$ ve tek $k$ için $b_k = 2/(k\pi)$ bulundu.

Hoca formüllerin karmaşık görünebileceğini, ama hepsinin yerine koyarak, biraz da lise matematiğiyle yürüdüğünü söyledi. Birkaç kez üzerinden geçip örneklere ek olarak alıştırma yapmak yeterlidir. Fourier dönüşümünün bundan aslında daha kolay olduğunu, orada $a$, $b$, $k$ olmadığını, integral alınıp sürekli zaman üzerinde çalışıldığını da ekledi. Sonraki konular Fourier dönüşümü, z ve Laplace dönüşümleridir, uygulamalarına da bakılacaktır.

> **Hocanın vurgusu:** Bu ders katlana katlana gidiyor. Fourier serilerini anlarsanız dönüşümü anlarsınız, dönüşümü anlarsanız Laplace'ı anlarsınız. Hepsi birbiriyle uyumlu ilerliyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
