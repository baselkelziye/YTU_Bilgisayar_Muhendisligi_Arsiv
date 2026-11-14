# Ders 6 Genişletilmiş Notu: Sayısal İntegral: Trapez (Yamuk) Yöntemi, Simpson 1/3 ve 3/8 Kuralları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayısal İntegrale Giriş
- 2. Newton-Cotes Formülleri ve Üç Yaklaşım
- 3. Trapez (Yamuk) Yönteminin Formülü
- 4. Trapez Yöntemiyle İlk Örnek
- 5. Simpson 1/3 Kuralının Formülü
- 6. Simpson 1/3 ile Alan Örneği: $y = x^3$
- 7. Sınıf Uygulaması: Şekli Çizmek ve Sınırları Bulmak
- 8. Simpson 3/8 Kuralı

## 1. Sayısal İntegrale Giriş

### 1.1 İntegral Bir Alandır

Hoca konuya, integralin lisede görülen ve matematik hocasına göre çok zevkli ya da çok zor gelebilen bir konu olduğunu söyleyerek girdi. Öyle ya da böyle hepimiz integralin ne olduğunu biliyoruz: İntegral alana karşılık gelir. Bu dersteki amaç, integral alma işlemini sayısal olarak nasıl gerçekleştireceğimizi görmektir.

Elimizde bir $f(x)$ fonksiyonu ve bir $[a, b]$ kapalı aralığı olsun. Bu fonksiyonun integrali, fonksiyon ile $Ox$ ekseni arasında, $a$ ve $b$ ile sınırlanmış kapalı alandır. Sınırları $a$ ve $b$ sabitleri olan bir integralin sonucu da sabittir. Sayısal integralde bu alan yaklaşık olarak hesaplanır. Bunun için hocanın sonradan eklediği bir şart vardır: Fonksiyon bu aralıkta sürekli olmalıdır.

Durum sayısal türevdekine benzer. Orada analitik türevi geri fark, ileri fark ve merkezi farkla yaklaşık hesaplamıştık. Hepsi analitik türeve yakın sonuçlar veriyordu, en yakını merkezi farktı. İntegralde de farklı yaklaşımlar ve farklı yöntemler vardır. Bu konuda üç yöntem görülecek, ayrıca iki katlı integral işlenecek. Hocaya göre iki katlı integralde de özel bir zorluk yoktur: Analitikte olduğu gibi önce birinci kat, sonra ikinci kat çözülür.

### 1.2 Alanı Bilinen Parçalara Bölmek

Hoca bir eğri çizip altında kalan bölgeyi gösterdi ve sordu: Bu alanı doğrudan hesaplayabilir miyim? Bölge ne kare, ne dörtgen, ne de daire. Koyup çarpıp bölerek alanını veren standart bir formül yoktur.

Sayısal yöntemlerin çözümü şudur: Fonksiyonla $x$ ekseni arasındaki bu alan, yöntemlerin birinde belirli geometrik parçalara bölünür, bazılarında ise belirli aralıklarla bölünüp parçalardan paraboller geçirilir. Böylece tanıdığımız şekillerle yalnız dört işlem yaparız. Ara sonuçlar toplanınca kapalı bölgenin alanı elde edilir.

Elbette küçük farklar oluşur. Hoca bunu bir dikdörtgenle gösterdi. Bölgeye bir dikdörtgen yerleştirip iki kenarını çarparsak, eğrinin dışında kalan bir kısım alana fazladan girer. Başka bir parçada ise alanın bir kısmı hesabın dışında kalır. Bir yerde fazla, bir yerde eksik hesaplanan bu alanların toplamına baktığımızda, analitik yolla bulunacak alana yakın bir değer elde ederiz.

## 2. Newton-Cotes Formülleri ve Üç Yaklaşım

### 2.1 Fonksiyonun Yerine Polinom Koymak

Sayısal analiz dersinde integral alırken Newton-Cotes formülleri kullanılır. Temel fikir şudur:

$$
\int_a^b f(x)\,dx \approx \int_a^b f_n(x)\,dx
$$

Buradaki $f_n$ bir polinomdur, $n$ de polinomun derecesini gösterir. Asıl $f(x)$ fonksiyonu polinom, trigonometrik ya da üstel olabilir. Formülleri çıkarırken ise $n.$ dereceden bir polinom düşünülür. Bu polinom bir doğru, parabol ya da kübik olabilir. Hocaya göre bazı sayısal analiz kitaplarında bunlar "Newton-Cotes formülleri" alt başlığında bulunur.

> **Ders sonrası not:** Hoca Newton-Cotes'u "ünlü bir matematikçi" diye tanıttı. Bu ad büyük olasılıkla tek bir kişiye değil, iki matematikçiye (Isaac Newton ve Roger Cotes) aittir.

### 2.2 Doğru, Parabol ve Kübik

Seçilen polinomun derecesi yöntemi belirler:

| Polinom | Derece | Yöntemin adı | Fonksiyonla ortak nokta |
|---|---|---|---|
| Doğru | 1 | Trapez kuralı (yamuk kuralı) | 2 |
| Parabol | 2 | Simpson 1/3 kuralı | 3 |
| Kübik | 3 | Simpson 3/8 kuralı | 4 |

Hoca adların gerekçesini şekiller üzerinden anlattı:

- **Trapez:** $a$ ve $b$ noktaları bir doğruyla birleştirilir. Karşımıza bir yamuk çıkar, bu yüzden kuralın adı yamuk kuralıdır. Eğrinin bir kısmı yamuğun dışında kalır, başka bir bölge ise aslında yokken yamuğun içine girer. Bu iki bölge birbirini yaklaşık olarak karşılar.
- **Simpson 1/3:** Verilen fonksiyondan bir sürü parabol geçirilebilir. Burada fonksiyonu 3 noktada kesen parabol seçilir. Hoca, 1/3 adını fonksiyonu 3 noktadan kesmesine bağladı.
- **Simpson 3/8:** Fonksiyondan kübik bir eğri geçirilir. Dört nokta vardır, iki ardışık nokta arasında toplam üç aralık oluşur. Hoca, 3/8 adını üç parçaya bölünmesine bağladı.

Hocanın özeti şudur: Bütün yöntemler bu üçü arasında gidip gelir.

> **Ders sonrası not:** Adların nokta sayısından geldiği açıklaması tam değildir. Kesirler büyük olasılıkla formüllerin önündeki katsayılardan gelir: 1/3 kuralında çarpan $\frac{h}{3}$'tür. 3/8 kuralında $h = \frac{b-a}{3}$ alınırsa $\frac{b-a}{8} = \frac{3h}{8}$ olur.

### 2.3 Neden Daha Fazla Parça?

Bütün eğriyi tek bir yamukla kaplarsak fazla ya da eksik kalan bölgeler büyük olur. Aralık kendi içinde daha küçük parçalara bölünüp her parça ayrı bir yamuk olarak alınırsa bu fazlalıklar gittikçe küçülür. Hoca bu fikri trapez yönteminde ayrıntılı olarak gösterdi.

## 3. Trapez (Yamuk) Yönteminin Formülü

### 3.1 Aralığı Eşit Parçalara Bölmek

Trapez yönteminde $y = f(x)$ eğrisinin altındaki bölge $n$ parçaya bölünür. $n$ ne kadar büyükse sonuç orijinale o kadar yakın olur, çünkü fazla ya da eksik kalan parçalar küçülür.

<!-- BELİRSİZ: Slaytta n parça için genel bir alan toplamı formülü var. Altyazıda yalnız "her parçanın yüksekliği ile fonksiyonun çarpımı toplanır" diye okunuyor, formülün tam yazımı doğrulanamadı. -->

Bütün parçaların genişliği eşittir, bu genişliğe $h$ denir. Başlangıcı sondan çıkarıp parça sayısına böleriz:

$$
h = \Delta x = \frac{b - a}{n} = x_{i+1} - x_i
$$

Yani $h$ aynı zamanda iki ardışık $x$ değeri arasındaki farktır. Noktalar $a = x_0$, $x_1$, $x_2$, ..., $x_{n-1}$, $x_n = b$ olur.

> **Ders sonrası not:** Hocanın anlatımında yöntem için "$n$ sayıda dikdörtgen" ve "dörtgen" ifadeleri geçti. Trapez yönteminde parçalar dikdörtgen değil yamuktur. $h$, hocanın da söylediği gibi yamuğun yüksekliğidir.

### 3.2 Yamukların Alanları

Her $x_i$ noktasından dikey bir çizgi çıkılır ve eğri üzerindeki ardışık noktalar doğrularla birleştirilir. Her aralıkta bir yamuk oluşur. Şekilde bazı bölgeler yamuğun dışında kalır, bazıları fazladan içine girer. Yamuğun alanını bilmediğimiz bir şey yoktur, teker teker hesaplayıp $n$ tanesini toplarız.

$x_0$ fonksiyonda yerine konunca $y_0$, $x_1$ konunca $y_1$ bulunur. Birinci yamuğun alt tabanı $y_0$, üst tabanı $y_1$, yüksekliği $h$'dir. Yamuk alanı "alt taban artı üst taban, bölü 2, çarpı yükseklik" olduğuna göre:

$$
S_1 = \frac{y_0 + y_1}{2}\,h, \qquad S_2 = \frac{y_1 + y_2}{2}\,h, \qquad \ldots, \qquad S_n = \frac{y_{n-1} + y_n}{2}\,h
$$

Bir yamuğun üst sınırı, bir sonrakinin alt sınırı olur.

### 3.3 Formülü Genelleştirmek

Toplam alan bütün $S$'lerin toplamıdır:

$$
S = \frac{y_0 + y_1}{2}h + \frac{y_1 + y_2}{2}h + \frac{y_2 + y_3}{2}h + \ldots + \frac{y_{n-1} + y_n}{2}h
$$

Hepsi için $\frac{h}{2}$ ortak parantezine alınırsa bir tane $y_0$, ikişer tane $y_1, y_2, \ldots, y_{n-1}$ ve bir tane $y_n$ kalır:

$$
S = \frac{h}{2}\left[y_0 + 2y_1 + 2y_2 + \ldots + 2y_{n-1} + y_n\right]
$$

Uçlardaki iki değer 2 ile çarpılmamıştır, içtekilerin hepsi 2 ile çarpılmıştır. Paydadaki 2'yi içeri dağıtınca içteki ikiler gider, uçlar ise 2'ye bölünmüş kalır:

$$
S = h\left[\frac{y_0 + y_n}{2} + \sum_{k=1}^{n-1} y_k\right]
$$

Burada $y$ dediğimiz şey fonksiyonun değeridir ve $h$ de $\Delta x$'tir. Toplamın içindeki terimler de $x_0$'a $\Delta x$ katları eklenerek yazılabilir. $k = 1$ için $x_0 + \Delta x = x_1$, $k = 2$ için $x_0 + 2\Delta x = x_2$, $k = 3$ için $x_3$ bulunur. Böylece formül şu hâli alır:

$$
\int_a^b f(x)\,dx \approx \Delta x\left[\frac{f(x_0) + f(x_n)}{2} + \sum_{k=1}^{n-1} f(x_0 + k\,\Delta x)\right]
$$

Bazen $h$ doğrudan verilir, bazen yalnız başlangıç, bitiş ve parça sayısı verilir ve $h$'yi kendimiz hesaplarız. Trapez yöntemi istendiğinde kullanılacak formül budur. Özeti şudur: başlangıç ve bitiş fonksiyon değerlerinin toplamının yarısı, artı aradaki bütün fonksiyon değerlerinin toplamı, hepsi çarpı $h$.

> **Hocanın vurgusu:** $n$ değerini ne kadar büyük alırsan hatalar o kadar azalır ve gerçek değere o kadar yakın bir sonuç elde edersin.

## 4. Trapez Yöntemiyle İlk Örnek

### 4.1 Çözüm ($n = 4$)

Hesaplanacak integral:

$$
\int_0^1 \frac{1}{1 + x^2}\,dx, \qquad n = 4
$$

Matematik dersinde bunun için integral cetvellerine bakılır ve sonucun arktanjant olduğu görülür. Hoca önce sayısal çözümü yaptı, sonra analitik çözümle karşılaştırdı.

**Verilen:** $x_0 = a = 0$, $x_n = b = 1$, $n = 4$. $h$ verilmediği için hesaplanır: $h = \frac{1 - 0}{4} = 0.25$.

**Tablo:** Önce $x$ için bir kolon açılır. 0'dan başlanır ve 0.25'er artırılarak 1'e gelinir. Bu, $n = 4$ aralığa karşılık gelen $x_0, \ldots, x_4$ noktalarıdır. Sonra her $x$ fonksiyonda yerine konur.

| $i$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| $x_i$ | 0 | 0.25 | 0.5 | 0.75 | 1 |
| $f(x_i)$ | 1 | 0.94 | 0.8 | 0.64 | 0.5 |

**İşlem:** Değerler formülde yerine konur:

$$
I \approx 0.25\left[\frac{1 + 0.5}{2} + 0.94 + 0.8 + 0.64\right] = 0.78279
$$

Hoca bu sonuca yalnız dört işlemle ulaşıldığını özellikle belirtti.

> **Ders sonrası not:** Tablodaki iki basamaklı değerlerle işlem yapılırsa sonuç 0.7825 çıkar. Slayttaki 0.78279 için $f(0.25) = 0.941176$ yuvarlanmadan kullanılmalıdır. Python ile hesaplanan değer 0.782794'tür.

### 4.2 Birim

İntegral sonucunda bir birim gerekir. Burada ne ölçüldüğü bilinmiyor, ama integral bir alan hesabı olduğu için birim "birim kare"dir. Hacim hesaplasaydık birim "birim küp" olurdu.

### 4.3 Analitik Çözüm ve Hata

Matematik dersindeki gibi çözersek:

$$
\int_0^1 \frac{dx}{1 + x^2} = \arctan x \Big|_0^1 = \arctan 1 - \arctan 0 = 45^\circ = \frac{\pi}{4} = 0.78539
$$

Hata, analitik sonuç ile sayısal sonuç arasındaki mutlak değerce farktır:

$$
|0.78539 - 0.78279| = 0.0026
$$

Hoca bunun kabul edilebilir bir hata olduğunu söyledi. Simpson yöntemi trapeze göre daha hassas olduğu için, onu kullansaydık hata daha küçük olurdu.

> **Ders sonrası not:** Hoca bu farktan söz ederken "bağıl hata, gerçek hata" dedi. Mutlak değerce fark gerçek (mutlak) hatadır. Bağıl hata büyük olasılıkla bu farkın gerçek değere bölünmesiyle bulunan ayrı bir büyüklüktür. Python hesabına göre $\frac{\pi}{4} = 0.785398$, hata 0.002604'tür. Aynı tabloyla Simpson 1/3 kuralı 0.785392 verir, hata yaklaşık $6 \times 10^{-6}$'dır.

### 4.4 Parça Sayısını Artırmak

Soruda $n = 4$ değil de $n = 9$ verilseydi tek yapılacak şey aralığı 9'a bölmektir. Hoca hesap makinesiyle gösterdi: $h = \frac{1}{9} = 0.1111\ldots$ olur ve $x$ değerleri $0, 0.11, 0.22, 0.33, 0.44, \ldots$ diye ilerler. Noktadan sonra bir basamak kuralı konmadığında son değer 1 ya da 1'e çok yakın bir sayı çıkar. Daha çok $f$ değeri hesaplanır ve formüldeki toplamın terim sayısı artar, başka bir şey değişmez.

<!-- BELİRSİZ: n = 9 için sonuç ve hata slaytta gösteriliyor, altyazıda sayılar okunmuyor. Aşağıdaki değerler kısa nottaki slayt değerleri ve Python hesabıyla uyumludur. -->

Sonuç $I = 0.78488$ olur, hata da $|0.78539 - 0.78488| = 0.00051$'e iner. Hatanın küçüldüğü açıkça görülür. Hocaya göre $n = 29$ alınsaydı fark sıfıra çok daha fazla yaklaşırdı.

> **Ek bilgi (derste anlatılmadı):** Bileşik trapez kuralının hatası büyük olasılıkla $h^2$ ile orantılıdır. Bu örnek bununla uyumludur: $h$ oranı $\frac{9}{4}$ iken hata oranı $\frac{0.002604}{0.000514} \approx 5.06 = (9/4)^2$ çıkar. Python hesabına göre $n = 29$ için hata yaklaşık $5 \times 10^{-5}$'tir.

> **Hocanın vurgusu:** Elle çözülen bir soruda $n$ değeri 4 ya da 5 gibi verilir ve hemen işlem yapılır. Ama algoritmasını yazdığında $n$'e 3-5 gibi değerler verirsen gerçek sonuçtan uzak değerler alırsın. "Elini korkak alıştırma." $n$'i 50, 60 ver ki hata payını azaltabilesin.

### 4.5 Neden Soru Çözüyoruz?

Hoca Simpson'a geçmeden önce neden sınıfta soru çözdüreceğini açıkladı. Anlatılırken her şey çok güzel anlaşılır. Dinleyenlerin yüzde 80-90'ı her şeyi anlamış olabilir. Ama soru verilip "çöz" denince insan kalıverir: Nasıl çözülecekti, ne yapılacaktı? Tahtada olsaydı birlikte çözerlerdi ve herkes aynı sonucu elde edemezdi, çünkü anladım denen yerde takılınabiliyor. Hoca bu aşamayı öğrencilerin kendisinin yaşamasını ve nerede takıldıklarını söylemesini istedi.

## 5. Simpson 1/3 Kuralının Formülü

Simpson yönteminin hem 1/3 hem 3/8 kuralı vardır. Hoca bunu trapeze göre biraz daha karışık, ama aslında yine sonuca odaklı ve kolay bir yöntem olarak tanıttı. Karışık olan, formülün çıkarılmasıdır.

### 5.1 Tek Parabol İçin İntegral

Simpson 1/3 kuralında ikinci dereceden bir polinom geçirilir:

$$
f(x) = ax^2 + bx + c
$$

Amaç, elimizdeki fonksiyonu yamuklara ayırır gibi küçük küçük parabollere ayırmaktır. Formül önce tek parabol için çıkarılır, sonra $n$ parçaya genişletilir.

Sınırlar için $a$ ve $b$ yerine $-h$ ve $+h$ kullanılır. Bazı kitaplarda da böyle geçer. Bunun iki sebebi vardır: İki taraf eşit uzunlukta olmalıdır, ayrıca polinomun katsayıları da $a$, $b$ olduğu için sınırlara $a$, $b$ dersek karışır.

Parabolün $-h$'deki değeri $y_0$, $0$'daki değeri $y_1$, $+h$'deki değeri $y_2$'dir. Trapezde iki $y$ değeri vardı, parabol olduğu için burada bir de orta noktadaki değer alınır.

Önce integral analitik olarak hesaplanır, çünkü formül bunun üzerinden çıkacak:

$$
\int_{-h}^{h}(ax^2 + bx + c)\,dx = \left[\frac{ax^3}{3} + \frac{bx^2}{2} + cx\right]_{-h}^{h}
$$

$h$ ve $-h$ yerine konur:

$$
= \left(\frac{ah^3}{3} + \frac{bh^2}{2} + ch\right) - \left(-\frac{ah^3}{3} + \frac{bh^2}{2} - ch\right)
$$

Parantez açılınca $\frac{ah^3}{3}$ terimleri toplanarak $\frac{2ah^3}{3}$ olur, $\frac{bh^2}{2}$ terimleri birbirini götürür, $ch$ terimleri de $2ch$ olur. $\frac{h}{3}$ ortak parantezine alınırsa:

$$
S = \frac{2ah^3}{3} + 2ch = \frac{h}{3}\left(2ah^2 + 6c\right)
$$

### 5.2 Bilinmeyenlerden Kurtulmak

Bu sonuçta $a$ ve $c$ katsayıları var, bunları bilmiyoruz. Bildiğimiz şey $y_0$, $y_1$, $y_2$ değerleridir, çünkü bunları fonksiyonda yerine koyarak hesaplayabiliriz. Öyleyse integrali bu değerler cinsinden yazmalıyız. Hoca bu noktada anlatımı "birazcık karışık oldu" diyerek baştan tekrar etti.

$x$ yerine sırasıyla $-h$, $0$ ve $h$ konur:

$$
y_0 = ah^2 - bh + c, \qquad y_1 = c, \qquad y_2 = ah^2 + bh + c
$$

$y_0$ ile $y_2$ toplanırsa $b$'li terimler birbirini götürür:

$$
y_0 + y_2 = 2ah^2 + 2c
$$

$c = y_1$ olduğundan $y_0 + y_2 = 2ah^2 + 2y_1$ yazılır. Geriye bilinmeyen olarak $2ah^2$ kalır ve onu sol tarafa alırız:

$$
2ah^2 = y_0 - 2y_1 + y_2
$$

İntegralde ihtiyacımız olan iki şey de artık elimizdedir: $2ah^2$ ve $c = y_1$. Yerlerine yazıp aynı indisli terimleri toplarız:

$$
S = \frac{h}{3}\left(y_0 - 2y_1 + y_2 + 6y_1\right) = \frac{h}{3}\left(y_0 + 4y_1 + y_2\right)
$$

Bu, yalnız bir parabolün ayırdığı kısmın alanıdır.

### 5.3 Parabolleri Toplamak

Şimdi fonksiyonun altındaki bölge parçalara bölünür ve her ikili parçadan bir parabol geçiyormuş gibi hareket edilir. Birinci parabol $y_0, y_1, y_2$ üzerinden, ikincisi $y_2, y_3, y_4$ üzerinden geçer. $y_2$ birinci parabolün sağ kenarı, ikincinin sol kenarıdır. $y_4$ de ikincinin sonu, üçüncünün başıdır.

$$
S_1 = \frac{h}{3}(y_0 + 4y_1 + y_2), \quad S_2 = \frac{h}{3}(y_2 + 4y_3 + y_4), \quad S_3 = \frac{h}{3}(y_4 + 4y_5 + y_6), \quad S_4 = \frac{h}{3}(y_6 + 4y_7 + y_8), \ldots
$$

Hoca bir önceki satırın nasıl bittiğine bakarak bir sonrakinin nasıl başladığını okuttu: $S_3$, $y_4$ ile başlar çünkü $S_2$ $y_4$ ile biter. Son parabolde slaytta $y_{2n-2}$, $y_{2n-1}$, $y_{2n}$ indisleri geçer:

$$
S_n = \frac{h}{3}(y_{2n-2} + 4y_{2n-1} + y_{2n})
$$

Trapezde bütün yamukları topluyorduk. Burada da farklı parabollerin altındaki alanlar toplanır.

> **Hocanın vurgusu:** Simpson yönteminde çubuklar ikişer ikişer alındığından aralık sayısı çift olmalıdır. Trapezde böyle bir şart yoktu, $n$ tek de olabilir çift de. Simpson yönteminde ise $n$'in mutlaka çift olması lazım.

### 5.4 Genel Formül

Bütün $S$'ler toplanıp $\frac{h}{3}$ parantezine alınır. $y_0$ tek başınadır. Bir $y_1$ için 4 katsayısı gelir. $y_2$ iki satırda geçtiği için $2y_2$ olur. Bunu $4y_3$, $2y_4$, $4y_5$, $2y_6$, $4y_7$ izler. Sonda $2y_{2n-2}$, $4y_{2n-1}$ ve tek bir $y_{2n}$ vardır.

Örüntü açıktır. En baştaki ve en sondaki değerler bir kez geçer. İndisi tek olanlar 4 ile, indisi çift olanlar 2 ile çarpılır. Bu yüzden iki ayrı toplam yazılır. Tek indisler için $k = 1, 3, 5, \ldots$ alınır. $k = 1$ için $x_0 + h = x_1$, $k = 3$ için $x_0 + 3h = x_3$, $k = 5$ için $x_5$ bulunur. Çift indisler için, karışmasın diye $i$ harfiyle, $i = 2, 4, 6, \ldots$ alınır. $i = 2$ için $x_0 + 2h = x_2$, $i = 4$ için $x_4$ bulunur.

$$
I \approx \frac{h}{3}\left[f(x_0) + f(x_n) + 4\sum_{k=1,3,5,\ldots}^{n-1} f(x_0 + kh) + 2\sum_{i=2,4,6,\ldots}^{n-2} f(x_0 + ih)\right]
$$

> **Ders sonrası not:** Türetmede ve bu formülde $n$ iki farklı şeyi gösterir. Satır satır toplamada $n$ parabol sayısıdır, bu yüzden son indis $2n$ olur. Genel formülde ise $n$ aralık sayısıdır ve son nokta $x_n$'dir. Hoca da son satırdaki indislerin slaytta değiştirilmediğini söyledi. Çift olması gereken $n$, genel formüldeki aralık sayısıdır.

## 6. Simpson 1/3 ile Alan Örneği: $y = x^3$

### 6.1 Şekli Çizmek

**Soru:** $y = x^3$ eğrisi, $x = -1$, $x = 2$ ve $Ox$ ekseni ile sınırlı bölgenin alanı nedir? $n = 4$ alınacak.

Hocaya göre bu tip sorularda öğrenci genellikle şekli çizemez. Çizemediği için de alanın neresi olduğunu bilemez. Oysa şekli kabaca çizmek zor değildir:

- $x = -1$ verilirse $y = -1$ olur. Fonksiyon bu noktadan geçer.
- $x = 2$ verilirse $y = 8$ olur. Fonksiyon bu noktadan da geçer.
- $x = 0$ verilirse $y = 0$ olur. Eğri ekseni bu noktada keser.

Eğriyi bu noktalardan biraz farklı geçirmek önemli değildir. Önemli olan, sınırlı alanın hangi aralıklarda ve nelerin arasında kaldığını çıkarabilmektir.

"$Ox$ ekseni ile sınırlı" ifadesi burada önemlidir. Eğrinin altında kalan bölge nerede bittiği bilinmeyen bir yer olabilir, bu yüzden "$Ox$ ekseniyle sınırlandırılan alan" denir. Bu örnekte iki alan bulmak gerekir: $[-1, 0]$ aralığında eksenin altında kalan parça ve $[0, 2]$ aralığında eksenin üstünde kalan parça. Trapez istenseydi önce birini, sonra öbürünü trapezle çözüp toplayacaktık. Simpson istenince de aynısı yapılır.

<!-- BELİRSİZ: Hoca şekil üzerinde "burası buraya eşittir" diyerek eksenin altındaki alanı bir başka bölgeyle eşleştiriyor ve ardından eğriyi farklı geçirerek alanın nasıl büyüyeceğini gösteriyor. Hangi bölgeleri gösterdiği altyazıdan anlaşılmıyor. -->

### 6.2 Alan Negatif Olamaz

Birden fazla alan hesaplanabilir ve hepsi hesaplanmalıdır. Yalnız eksenin altında kalan parça negatif çıkar.

Hocanın örneği: Parçaların değerlerini 3, 2 ve $-2$ bulduğunu düşün. Toplayıp 2 ile $-2$ birbirini götürdü, alan 3'tür diyemezsin. Mutlak değerce alınır: $3 + 2 + 2 = 7$.

> **Hocanın vurgusu:** Alan negatif olamaz. Eksenin altında kalan parçanın mutlak değeri alınmalıdır.

Bu yüzden birinci integralin önüne eksi konur: Negatif çıkacak sonuç eksiyle çarpılınca pozitif olur. Eksi konmazsa da sonuç mutlak değerle alınarak aynı şey sağlanır.

### 6.3 Birinci Parça: $S_1$

$$
S_1 = -\int_{-1}^{0} x^3\,dx, \qquad n = 4
$$

$n$ çift olduğu için Simpson uygulanabilir. $h$ verilmemiştir: $h = \frac{0 - (-1)}{4} = 0.25$. $x$ değerleri $-1$'den başlar ve 0.25'er artarak 0'a gelir.

| $i$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| $x_i$ | $-1$ | $-0.75$ | $-0.5$ | $-0.25$ | 0 |
| $-x_i^3$ | 1 | 0.4218 | 0.125 | 0.0156 | 0 |

Hoca, aynı tablo trapezde de kullanılacağı için trapez formülünü de gösterdi: Uçların yarısı $\frac{1 + 0}{2}$, artı içtekiler $0.4218 + 0.125 + 0.0156$, hepsi çarpı $h$. Görüldüğü gibi tablo aynıdır, yalnız formül değişir.

Simpson ile tek indisliler ($x_1, x_3$) 4 ile, çift indisli olan ($x_2$) 2 ile çarpılır:

$$
S_1 = \frac{0.25}{3}\left[(1 + 0) + 2(0.125) + 4(0.4218 + 0.0156)\right] = 0.2499
$$

> **Ders sonrası not:** Altyazıda son değer "0.156" diye geçiyor. Doğrusu $(-0.25)^3$'ün mutlak değeri olan 0.0156'dır. Python hesabına göre tablo tam değerlerle ($0.421875$ ve $0.015625$) kullanılırsa $S_1 = 0.25$ çıkar. 0.2499, yuvarlamadan kaynaklanır. Aynı parçada trapez 0.2656 verirdi.

### 6.4 İkinci Parça: $S_2$

$$
S_2 = \int_{0}^{2} x^3\,dx, \qquad n = 4
$$

Aralık değiştiği için $h$ de değişir: $h = \frac{2 - 0}{4} = 0.5$.

| $i$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| $x_i$ | 0 | 0.5 | 1 | 1.5 | 2 |
| $x_i^3$ | 0 | 0.125 | 1 | 3.375 | 8 |

$$
S_2 = \frac{0.5}{3}\left[(0 + 8) + 2(1) + 4(0.125 + 3.375)\right] = \frac{0.5}{3} \cdot 24 = 4
$$

### 6.5 Toplam Alan

$$
S = S_1 + S_2 = 0.2499 + 4 \approx 4.25 \text{ birim kare}
$$

> **Ek bilgi (derste anlatılmadı):** Simpson 1/3 kuralı parabol üzerinden çıkarılsa da üçüncü dereceye kadar polinomları büyük olasılıkla tam hesaplar. Bu örnek bununla uyumludur: Analitik sonuçlar $\frac{1}{4}$ ve $\frac{2^4}{4} = 4$'tür ve Python hesabıyla Simpson bunların aynısını verir. Bileşik Simpson hatası da büyük olasılıkla $h^4$ ile orantılıdır, bu yüzden trapezden daha hassas çıkması beklenir.

## 7. Sınıf Uygulaması: Şekli Çizmek ve Sınırları Bulmak

### 7.1 Soru ve Sınıftan Gelen Sonuçlar

Hoca slaytlara bakılmamasını, telefondaki hesap makinesinin kullanılabileceğini söyleyip şu soruyu verdi:

**Soru:** $f(x) = (x^2 - 1)(x + 2)$ eğrisinin altında ve $Ox$ ekseninin üstünde kalan bölgenin alanını $n = 4$ alarak bulun.

$n$ çift olduğu için iki yöntem de kullanılabilir. Çıkarılan $x$ değerleri, artım ve $f(x)$ değerleri ortaktır, yalnız formüller değişir. Beş altı dakika sonra çok farklı sonuçlar geldi: 28.85, 0.38, $-9$, 2.25, 0.351 gibi. Hoca, böyle farklı sonuçlara hem üzüldüğünü hem de sevindiğini, çünkü konuşacak şeyler çıktığını söyledi. Negatif bir sonucu ise reddetti: Daha yeni konuştuğumuz gibi alan negatif olamaz, $-9$ denemez.

### 7.2 Şekil Nasıl Çizilir?

Hoca bu soruda fonksiyonu çizemeyenler olduğunu hatırladı ve şöyle bir yol gösterdi: Fonksiyonu sıfır yapan noktaları bulun.

- $x + 2 = 0$ ise $x = -2$. Fonksiyon bu noktadan geçer.
- $x^2 - 1 = 0$ ise $x = -1$ ve $x = +1$. Fonksiyon bu noktalardan da geçer.
- İfade $x^3$'lüdür ve üç kökü vardır.
- Daha iyi bir şekil isteniyorsa $x = 0$ verilir: $y = -2$.
- Tepe noktası da bulunabilir, örneğin $x = -1.5$ verilebilir. Ama buna gerek bile yoktur.

Eğrinin tam olarak nasıl çizildiği önemli değildir. Fonksiyonu çok düzgün çizmek gerekmez. Gereken şey, integralin sınırlarını kabaca bulmaktır.

> **Ders sonrası not:** Python hesabına göre $f(-1.5) = 0.625$'tir. Gerçek tepe $x \approx -1.549$ noktasındadır ve değeri yaklaşık $0.631$'dir. Kabaca çizim için hocanın dediği gibi fark önemli değildir.

Sonra soru tekrar okunur. "Eğrinin altında" ifadesi bir bölge gösterir, "$Ox$ ekseninin üstünde" ifadesi ise bunu daraltır. Eğrinin $Ox$ ekseni üstünde kalan ve eğrinin altında sınırlanan tek bölge $[-2, -1]$ aralığındadır. Bu yüzden sınırlar bu köklerdir.

Hoca bir de karşılaştırma yaptı: Şekilde ayrıca bir sınır, örneğin 5 verilmiş olsaydı o bölgeyi de hesaplamak gerekirdi. Burada ise eğrinin $x = 1$'den sonraki kısmı "almış gidiyor", nerede bittiği bilinmiyor ve bu yüzden hesaba katılamaz. Sıkıştırılmış, yani sınırlı alanlar hesaplanır.

<!-- BELİRSİZ: Bu karşılaştırmada hoca dördüncü dereceden bir polinomdan da söz ediyor ve şekil üzerinde gösteriyor. Hangi bölgeyi kastettiği altyazıdan tam anlaşılmıyor. -->

> **Hocanın vurgusu:** Bu soruda absürt ya da çizilemeyen bir taraf yok. Her zaman "$x^2 + 5$ fonksiyonunun şu aralıktaki alanı" gibi gösterilmiş şeyler gelmeyebilir. Birçok şeyi biliyoruz, ama bazen bir araya getirip kullanamıyoruz. Hemen paniğe girmek yanlış bir yola sokar.

### 7.3 Çözüm

Çarpım açılırsa:

$$
f(x) = (x^2 - 1)(x + 2) = x^3 + 2x^2 - x - 2
$$

Sınırlar $a = -2$, $b = -1$ olduğuna göre:

$$
h = \frac{-1 - (-2)}{4} = \frac{1}{4} = 0.25
$$

$x$ değerleri $-2$'den başlar ve 0.25'er artar. Hoca $f(x)$ değerlerini söylemeden formüllere yerleştirme aşamasına geçti, tablo aşağıda tamamlandı (ara adım eklendi).

| $i$ | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| $x_i$ | $-2$ | $-1.75$ | $-1.5$ | $-1.25$ | $-1$ |
| $f(x_i)$ | 0 | 0.515625 | 0.625 | 0.421875 | 0 |

**Analitik çözüm** (ara adım eklendi):

$$
\int_{-2}^{-1}(x^3 + 2x^2 - x - 2)\,dx = \left[\frac{x^4}{4} + \frac{2x^3}{3} - \frac{x^2}{2} - 2x\right]_{-2}^{-1} = \frac{13}{12} - \frac{2}{3} = \frac{5}{12} \approx 0.41 \text{ birim kare}
$$

**Trapez** (ara adım eklendi):

$$
S_T = 0.25\left[\frac{0 + 0}{2} + 0.515625 + 0.625 + 0.421875\right] = 0.25 \cdot 1.5625 = 0.390625 \approx 0.39
$$

**Simpson 1/3** (ara adım eklendi): Tablo aynıdır, $h$ da aynıdır. Hoca bunu "şu aynı tablo, hiçbir şey değişmiyor" diye vurguladı. Tek indisliler 4 ile, çift indisli 2 ile çarpılır:

$$
S_S = \frac{0.25}{3}\left[(0 + 0) + 4(0.515625 + 0.421875) + 2(0.625)\right] = \frac{0.25}{3} \cdot 5 = 0.41667
$$

Sonuçları karşılaştıralım: Analitik sonuç 0.41, trapez 0.39, Simpson 0.4166. Hocanın dediği gibi Simpson yöntemi trapezden daha iyi sonuç verir. Hoca analitik sonucun küsuratını o anda hatırlamadı. Sınıftan gelen 0.38 civarındaki sonuçlar için de birkaç kişi aynı cevabı verdiğine göre doğru olabileceğini, ama trapezle bulunup bulunmadığını bilmediğini söyledi.

> **Ders sonrası not:** Python hesabına göre analitik sonuç tam olarak $\frac{5}{12} = 0.41667$'dir ve bu örnekte Simpson bu değerin aynısını verir. Trapezin tam değeri 0.390625'tir.

### 7.4 Soru-Cevap

**Soru:** Formüller aklımızda kalmıyor. **Cevap:** Formüllerin akılda kalmaması diye bir şey olamaz, bir iki örnek yapınca zaten kalır. Simpson 1/3 için $\frac{h}{3}$ çarpanı, sonra $f_0$ ve $f_n$, geri kalanda çift indisler 2, tek indisler 4 ile çarpılıp toplanır. Trapezde $h$ çarpanı vardır, uçlar 2'ye bölünür, geri kalan bütün fonksiyon değerleri toplanır. Uçların 2'ye bölünmesinin sebebi, diğer terimlerin iki adet olmasıdır. Formülleri çıkarmak da çok zor değildi.

**Soru:** Bir öğrenci önce fonksiyonla $Ox$ arasındaki bütün bölgeyi bulmaya çalıştığını, sonra yalnız üstte kalan alanın sorulduğunu fark ettiğini, ama yine yanlış bulduğunu söyledi. **Cevap:** Yanlış olduğunu anlaman önemlidir. Bir şeyi hatalı yapabiliriz, hata yapmak ayıp değildir.

Hoca burada bir benzetme yaptı: Aynı hataya sürekli düşmek, insan ilişkilerinde sürekli kazık yemeye benzer. Bir kere boş bulunursun, ikincisini de anlarım. Ama üç, dört, beş olunca kendine "niye hep yiyorum?" diye sorman gerekir.

> **Hocanın vurgusu:** Hatanı gör, düzelt ve bir daha aynı hataya düşme.

**Soru:** İşlem yaparken kaç anlamlı basamağa kadar yazmalıyız? Ben 0.388 buldum, herhalde eksik basamak yazdığım için daha düşük çıktı. **Cevap:** Soruda anlamlı basamak ya da ondalık basamak sayısı söylenir. Söylenmezse, biri iki basamak biri bir basamak aldığında sonuçların birebir aynı çıkması beklenmez. Basamak sayısından kaynaklanan fark problem değildir, önemli olan yöntemi doğru yapmaktır.

## 8. Simpson 3/8 Kuralı

### 8.1 Kural

Hoca, 3/8 kuralının formülünün ezberlenmesi gerektiğini, çıkarmanın ve ispatlamanın sayfalar süren bir iş olduğunu söyledi. Kendisi de oturup bunu ispatlayamayacağını belirtti. Ama kuralın özü anlaşılabilir.

$$
\int_a^b f(x)\,dx \approx \int_a^b f_3(x)\,dx
$$

Şekildeki mor eğri $y = f(x)$ fonksiyonudur. Buradan öyle bir polinom geçirilir ki fonksiyonu dört noktada kessin. Noktalardan biri başlangıç $a$, biri bitiş $b$, diğer ikisi de aradaki $x_1$ ve $x_2$'dir. Aralık üç eşit parçaya bölündüğü için:

$$
x_1 = a + \frac{b - a}{3}, \qquad x_2 = a + 2\,\frac{b - a}{3}
$$

$a$'ya bir parça eklenince $x_1$, iki parça eklenince $x_2$ bulunur. Mesafeler eşit olduğu için ikincisinin başında 2 vardır.

Formül şudur:

$$
\int_a^b f(x)\,dx \approx (b - a)\,\frac{f(a) + 3f(x_1) + 3f(x_2) + f(b)}{8}
$$

Hocanın akılda tutma önerisi: İçteki $x_1$ ve $x_2$ fonksiyon değerleri 3 ile çarpılır, toplam 8'e bölünür. Hoca ayrıca bu formülün çıkarılışını sayısal analiz kitaplarında göremeyeceğimizi, kitapların yalnız formülü verdiğini söyledi.

> **Ders sonrası not:** "Sayısal analiz kitaplarında çıkarılışı yoktur" sözü büyük olasılıkla genel olarak geçerli değildir. Formül büyük olasılıkla bazı kaynaklarda polinom interpolasyonunun integraliyle kısaca çıkarılır. Şekildeki $f_3$ adını hoca "3 parçaya bölündüğü için" diye açıkladı. Dersin başındaki $f_n$ gösterimine göre buradaki 3 aynı zamanda polinomun derecesidir.

### 8.2 $n$ Değeri Ne Demektir?

Bu formül $n = 1$ içindir. Simpson 1/3'te bir parabol için yazıp sonra $n$ tanesini topladığımız gibi, burada da formül önce bir parça için yazılır.

$n = 2$ olsaydı $[a, b]$ aralığı iki parçaya bölünürdü. Orta nokta $\frac{a + b}{2}$'dir:

$$
\int_a^b f(x)\,dx = \int_a^{\frac{a+b}{2}} f(x)\,dx + \int_{\frac{a+b}{2}}^{b} f(x)\,dx
$$

Her iki integralde fonksiyon aynıdır, yalnız sınırlar farklıdır. Bu yüzden her parça için yeni bir $x_1$, $x_2$ hesaplanır. $n = 3$ olsaydı üç integral olurdu ve her biri kendi içinde üç parçaya bölünürdü. Hoca bunu "rekürsif gibi" iç içe devam eden bir yapıya benzetti. Sebep, daha hassas sonuç bulmaktır.

> **Ders sonrası not:** Altyazıda $n = 3$ için ilk parçanın sınırı "$a$ artı $b$ bölü 3" diye geçiyor. Eşit parçalar için doğrusu $a + \frac{b - a}{3}$'tür. İkisi yalnız $a = 0$ iken aynı çıkar.

> **Ders sonrası not:** Bu kullanımda $n$, 3/8 formülünün kaç kez uygulandığını gösterir ve her uygulama kendi içinde 3 parça kullanır. Yani $n = 2$ için toplam 6 parça ve 7 nokta olur. Simpson 1/3'teki $n$ ise doğrudan aralık sayısıdır.

### 8.3 Örnek: $n = 1$

$$
\int_0^6 \frac{1}{1 + x^4}\,dx
$$

integralinin sayısal çözümü Simpson 3/8 kuralıyla $n = 1$ ve $n = 2$ için istenir. Önce $n = 1$:

**Verilen:** $a = 0$, $b = 6$, $f(x) = \frac{1}{1 + x^4}$.

**Ara noktalar:**

$$
x_1 = 0 + \frac{6 - 0}{3} = 2, \qquad x_2 = 0 + 2 \cdot \frac{6 - 0}{3} = 4
$$

**Fonksiyon değerleri:**

- $f(0) = 1$
- $f(6) = \frac{1}{1 + 6^4} = \frac{1}{1297}$
- $f(2) = \frac{1}{1 + 16} = \frac{1}{17}$
- $f(4) = \frac{1}{1 + 4^4} = \frac{1}{257}$

**İşlem:**

$$
I \approx 6 \cdot \frac{1 + 3\cdot\frac{1}{17} + 3\cdot\frac{1}{257} + \frac{1}{1297}}{8} = 0.8917
$$

### 8.4 Örnek: $n = 2$

Aralık ikiye bölünür: $\frac{0 + 6}{2} = 3$. Yani $\int_0^3$ ve $\int_3^6$ ayrı ayrı hesaplanır.

$[0, 3]$ için $x_1 = 1$, $x_2 = 2$; $[3, 6]$ için $x_1 = 4$, $x_2 = 5$ olur (ara adım eklendi).

$$
I_1 \approx 3 \cdot \frac{1 + 3(0.5) + 3(0.058824) + 0.012195}{8} = 1.0082
$$

$$
I_2 \approx 3 \cdot \frac{0.012195 + 3(0.003891) + 3(0.001597) + 0.000771}{8} = 0.0110
$$

$$
I \approx 1.0082 + 0.0110 = 1.0193
$$

Altyazıda hoca sonucu 1.01 diye okudu ve 0.89'dan bayağı bir değişim olduğunu söyledi. Demek ki $n$ arttığında gerçeğe daha yakın sonuçlar elde edilebilir.

> **Ders sonrası not:** Hoca analitik sonucu derste vermedi. Python hesabına göre $\int_0^6 \frac{dx}{1 + x^4} \approx 1.10918$'dir. Simpson 3/8 ile $n = 1$: 0.8917, $n = 2$: 1.0193, $n = 3$: 1.1112, $n = 4$: 1.1202, $n = 10$: 1.1090 bulunur. Genel eğilim hocanın dediği gibi gerçek değere yaklaşmaktır, ama her adımda iyileşme olmayabilir: $n = 3$'ün hatası (0.0020), $n = 4$'ünkinden (0.0110) küçüktür.

### 8.5 Karşılaştırma İsteği

Hoca aynı integralin Simpson 1/3 ve trapez ile de çözülmesini, analitik integral alınabiliyorsa hataların karşılaştırılmasını istedi. Kendisinin bunu çözmediğini, sonucun 0.89'dan ne kadar uzak çıkacağının merak konusu olduğunu ve bir sonraki derste buna dair sorularla başlayacağını söyledi.

> **Ders sonrası not:** Önce kendiniz çözün. Hoca bu karşılaştırma için $n$ belirtmedi. Simpson 1/3 için $n$ çift olmalıdır, bu yüzden aşağıda 3/8 kuralının $n = 2$ hâliyle aynı noktalar ($h = 1$, $n = 6$ aralık) kullanıldı. Python hesabına göre trapez 1.0769, Simpson 1/3 1.0605 verir, gerçek değer 1.1092'dir. Burada az nokta nedeniyle trapez daha yakındır, yani "Simpson trapezden daha iyidir" sözü her kaba ızgarada geçerli değildir. $n = 50$ alınırsa ikisi de 1.10918'e çok yaklaşır (trapez 1.109177, Simpson 1.109178).

### 8.6 Programda Nasıl Görünür?

Hoca bu işlemlerin karışık görünebileceğini, ama programını yazınca çok basit olduğunu söyledi. Bir parça için yapılacaklar her seferinde aynıdır:

1. $x_1$ ve $x_2$'yi hesapla.
2. $a$, $b$, $x_1$, $x_2$ değerlerini aynı fonksiyona gönder.
3. Formüldeki katsayılarla çarpıp sonucu elde et.

## Dersin Toparlaması

Bu derste integralin bir alan olduğundan yola çıkıldı. Alanı bilinen şekillerle yaklaşık hesaplama fikri, $f(x)$ yerine bir polinom koyan Newton-Cotes formülleriyle kuruldu. Polinom doğru olunca trapez kuralı, parabol olunca Simpson 1/3 kuralı, kübik olunca Simpson 3/8 kuralı elde edilir. Trapez ve Simpson 1/3 formülleri adım adım çıkarıldı, 3/8 formülü ise verildi. Üç yöntemde de aynı tablo mantığı kullanılır: $h$'yi bul, $x$ değerlerini ve $f(x)$ değerlerini tabloya yaz, formüle yerleştir. Trapezde $n$ tek de çift de olabilir, Simpson 1/3'te $n$ çift olmalıdır. $n$ büyüdükçe sonuç genellikle gerçeğe yaklaşır.

Alan sorularında önce şekil kabaca çizilir. Bunun için kökleri ve birkaç noktayı bulmak yeter. Sınırlar köklerden çıkar. Eksenin altında kalan parçalar ayrı hesaplanır ve mutlak değerce toplanır, çünkü alan negatif olamaz. Bir sonraki derste iki katlı integral işlenecek, ardından farklara geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
