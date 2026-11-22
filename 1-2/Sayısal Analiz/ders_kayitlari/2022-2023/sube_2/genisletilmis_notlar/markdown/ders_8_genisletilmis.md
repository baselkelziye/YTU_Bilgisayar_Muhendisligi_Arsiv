# Ders 8 Genişletilmiş Notu: Sonlu Farklar ve Doğrusal Enterpolasyona Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sonlu Farkların Çıkış Noktası: Örüntü Bulma
- 2. Veriden Fonksiyona: Sonlu Farklar Neden Gerekli?
- 3. Fark Aralığı ve Sonlu Fark Operatörleri
- 4. Yüksek Dereceden İleri, Geri ve Merkezi Farklar
- 5. Binom Katsayılarıyla Genel İleri Fark Formülü
- 6. Sonlu Fark Tabloları
- 7. Sonlu Farklarda Hatanın Yayılması
- 8. Enterpolasyona Giriş
- 9. Doğrusal Enterpolasyon
- Örnek Sorular
- Dersin Toparlaması

## 1. Sonlu Farkların Çıkış Noktası: Örüntü Bulma

Dersin konusu sonlu farklardır (finite differences). Hoca bunu, dersin son iki konusu olan enterpolasyon ve regresyonda da kullanılacak, kısa ve kolay bir konu olarak tanıttı.

Konunun çıkış noktası ortaokuldan bilinen örüntü bulma problemleridir. Hoca şu diziyi verdi ve sonraki terimi sordu:

$$1,\ 2,\ 4,\ 7,\ 11,\ 16,\ 22,\ \dots$$

Bir öğrenci $29$ cevabını verdi. Gerekçesi artışlara bakmaktı: terimler sırasıyla $1, 2, 3, 4, 5, 6$ artıyor, demek ki sonraki artış $7$'dir ve $22 + 7 = 29$ olur. Hoca bunun aslında ikinci terimden birinciyi, üçüncüden ikinciyi çıkarmak, yani ardışık farkları almak olduğunu vurguladı. Bu artışlar bir örüntü (patern) ortaya koyar.

Hoca aynı fikri $x^2$ fonksiyonuyla da gösterdi. $x = 1, 2, 3, 4$ için değerler $1, 4, 9, 16$'dır. Fonksiyon bize verilmese de yalnız bu sayılar verilmiş olsa, ardışık farkları alırız:

- Birinci farklar: $4-1 = 3$, $9-4 = 5$, $16-9 = 7$.
- İkinci farklar: $5-3 = 2$, $7-5 = 2$, yani sabit.

Birinci dereceden fark almak, birinci dereceden türev almaya benzer; sayısal türevde de buna benzer bir çıkarma yapılıyordu. $x^2$'nin birinci türevi $2x$, ikinci türevi sabit $2$'dir. Farklarda da bir türev daha alınca "$2, 2, 2, \dots$" diye sabit bir değere ulaşılır.

Sonlu farklar, normal farkı (türevi) yaklaşık bulmada ve ara değer problemleri gibi enterpolasyonlarda kullanılacaktır; bazı regresyon problemlerinde de işe yarar. Konunun genel adı sonlu farklar aritmetiğidir; derste bu geniş konunun yalnız gerekli kısmı işlendi.

## 2. Veriden Fonksiyona: Sonlu Farklar Neden Gerekli?

Gerçek hayatta yalnız veriler sunulur, fonksiyon verilmez. $f(x)$'in kuralı biliniyorsa istenen her $x$ için $f(x)$ kolayca hesaplanır. Ancak çoğu zaman yalnız $a$ ve $f(a)$, $b$ ve $f(b)$ gibi sayısal ikililer verilir, kural verilmez.

Amaç bu $(x, f(x))$ veri kümesinden $f(x)$'i tahmin etmektir. Tahmin edilen fonksiyonla ara değerler bulmak enterpolasyon, yeni değerleri tahmin etmek regresyon ile yapılacaktır. Hoca, yapay zekanın da bu alanda çözümleri olduğunu, ayrıca analitik yöntemlerle birlikte sayısal analiz yöntemlerinin geliştirildiğini söyledi. Özetle bazı durumlarda formül yoktur; verilerden formül üretilmeye çalışılır. Elimizde fonksiyonun ayrık noktaları vardır ve fonksiyonu tahmin etmeye çalışırız.

Ekrandaki giriş slaytında $y = f(x)$ eğrisi üzerinde, aralarında eşit $h$ uzaklığı bulunan $x_0, x_1, \dots, x_6$ noktaları gösterildi (ekrandan, 00:05:00).

## 3. Fark Aralığı ve Sonlu Fark Operatörleri

### 3.1 Fark aralığı

Sonlu farklarla ilgili işlemlerin temeli çıkarmadır. Birbirini takip eden iki ayrık nokta, örneğin $x_i$ ve $x_{i+1}$ vardır. Bu iki nokta arasındaki farka **fark aralığı** denir ve $h$ ile gösterilir (ekrandan, 00:10:00):

$$h = x_{k+1} - x_k$$

Sayısal integralde de bir $x_0 = a$ noktasından sonra $a + h$ noktası geliyordu; burada da aynı gösterim kullanılır. Bu $x$ değerleri sayı doğrusunda (x ekseninde) yer alır, her birine karşılık bir fonksiyon görüntüsü vardır. Slayttaki şekilde $x_0$, $x_1$, $x_2$ noktalarına karşılık $y_0 = f(x_0)$, $y_1 = f(x_0 + h)$, $y_2 = f(x_0 + 2h)$ gösterildi (ekrandan, 00:10:00).

### 3.2 Operatörler

Hoca dört gösterimi tanıttı:

- **İleri fark** $\Delta$ (yukarı doğru delta): ilerideki bir noktadan bulunulan nokta çıkarılır, yani bir $h$ ötedeki noktayla bulunulan nokta arasındaki farktır.
- **Geri fark** $\nabla$ (aşağı doğru delta): bunun tersidir; bulunulan noktadan gerideki nokta çıkarılır.
- **Merkezi fark** $\delta$ (Yunan alfabesindeki küçük delta): bulunulan noktanın $h/2$ ilerisi ile $h/2$ gerisindeki noktalara bakılır.
- **Ortalama operatörü** $\mu$ (mü): hoca bunu merkezi farkla ilişkilendirip "ikiye bölünmüş hali" olarak anlattı.

<!-- BELİRSİZ: Operatör tanımlarının yazılı olduğu slayt karelerde yok. μ operatörünün tam tanımı altyazıda yalnız "merkezi farkın ikiye bölümü" diye geçiyor. -->

> **Ek bilgi (derste anlatılmadı):** Ders kitaplarında ortalama operatörü genellikle $\mu f(x) = \frac{1}{2}\left[f\!\left(x + \frac{h}{2}\right) + f\!\left(x - \frac{h}{2}\right)\right]$ biçiminde tanımlanır; yani $h/2$ ileri ve gerideki değerlerin farkı değil ortalamasıdır.

Hoca, ileride bu farkların bir de $h$'a bölündüğü durumların geleceğini, şimdilik buna gerek olmadığını söyledi.

### 3.3 Kaydırma (shifting) operatörü

Bir de kaydırma işlemi vardır ve $E$ ile gösterilir. $E f(x)$, bulunulan $x$ noktasından $h$ kadar öteleme yapmak demektir:

$$E f(x) = f(x + h)$$

Bu, ileri fark cinsinden de yazılabilir: $f(x+h) = f(x) + \Delta f(x)$. İki kez kaydırmak için kaydırma bir daha uygulanır ve $E^2$ denir: $E^2 f(x) = f(x + 2h)$. $n$ kez kaydırmak $E^n f(x) = f(x + nh)$ demektir. Özetle bu operatör, bulunulan noktanın $n$ adım ötesine odaklanmayı mümkün kılar.

## 4. Yüksek Dereceden İleri, Geri ve Merkezi Farklar

Noktalar $x_0, x_0 + h, x_0 + 2h, \dots, x_0 + nh$ biçiminde, fonksiyon değerleri de bunlara karşılık gelecek şekilde verilir. Fonksiyonun verilmesi zorunlu değildir; örneğin $x = 2$ için $y = 10$ gibi değerler doğrudan tablo olarak verilebilir. Kural varsa $f_i = f(x_i)$ yazılır; kural yoksa $x_i$ ve $f_i$ değerleri tablo olarak verilmiştir (ekrandan, 00:15:00).

### 4.1 İleri farklar

**1. derece ileri fark** (ekrandan, 00:15:00):

$$\Delta f_i = f_{i+1} - f_i, \qquad i = 0, 1, \dots, n$$

**2. derece ileri fark** için ifade bir derece açılır. Önce dıştaki $\Delta$ içeri dağıtılır, sonra her terim açılır (ekrandan, 00:15:00):

$$\Delta^2 f_i = \Delta(\Delta f_i) = \Delta(f_{i+1} - f_i) = \Delta f_{i+1} - \Delta f_i$$

Burada $\Delta f_{i+1} = f_{i+2} - f_{i+1}$ ve $\Delta f_i = f_{i+1} - f_i$'dir. Yerine konunca:

$$\Delta^2 f_i = f_{i+2} - f_{i+1} - f_{i+1} + f_i = f_{i+2} - 2f_{i+1} + f_i$$

Hoca burada sınıfa bu katsayıların ($1, -2, 1$) başka bir yerden tanıdık gelip gelmediğini sordu. Cevap kombinasyon, yani binom katsayılarıdır. Pascal üçgeninin satırları $1$; $1, 1$; $1, 2, 1$; $1, 3, 3, 1$ biçimindedir. Üçüncü dereceden ileri farkta da katsayılar $1, 3, 3, 1$ olur ve işaretler birinci terim artı, ikinci eksi, üçüncü artı, dördüncü eksi diye değişir:

$$\Delta^3 f_i = f_{i+3} - 3f_{i+2} + 3f_{i+1} - f_i \quad \text{(ara adım eklendi)}$$

Bu, baştaki örüntü probleminde öğrencinin yaptığı işlemin aynısıdır: $1, 2, 4, 7, 11$ dizisinde birinci farklar, sonra onların farkları alınır ve bu fark değerleriyle fonksiyonun denklemi tahmin edilir.

### 4.2 Geri farklar

Geri farklar aynı mantıkla kurulur; yalnız $i$ noktasından $i-1$ noktası çıkarılır:

$$\nabla f_i = f_i - f_{i-1}$$

İkinci dereceden uygulanınca yine $1, -2, 1$ katsayıları çıkar; üçüncü derece de aynı mantıkla devam eder. Hoca bunları lise matematiğinden bilinen basit işlemler olduğu için uzun uzun yazmadı.

> **Ek bilgi (derste anlatılmadı):** Açık yazıldığında $\nabla^2 f_i = f_i - 2f_{i-1} + f_{i-2}$ ve $\nabla^3 f_i = f_i - 3f_{i-1} + 3f_{i-2} - f_{i-3}$ olur.

### 4.3 Merkezi farklar

Merkezi farklarda $i + 1/2$ gibi yarım indisler kullanılır. Normalde $i$ tam sayıdır (sıfırıncı, birinci, ikinci nokta); merkezi farkta bu yarım noktalar pek kullanılmasa da varmış gibi düşünülür. Birinci derece merkezi fark $f_{i+1/2} - f_{i-1/2}$'dir. İkinci derecesi alınınca $i+1$ ve $i-1$ noktaları devreye girer. Üçüncü derece merkezi fark slaytta adım adım açıldı (ekrandan, 00:20:00):

$$\begin{aligned}
\delta^3 f_i &= \delta(\delta(\delta f_i)) = \delta(\delta(f_{i+1/2} - f_{i-1/2})) \\
&= \delta(\delta f_{i+1/2} - \delta f_{i-1/2}) = \delta\big(f_{i+1} - f_i - (f_i - f_{i-1})\big) \\
&= \delta(f_{i+1} - 2f_i + f_{i-1}) \\
&= f_{i+3/2} - f_{i+1/2} - 2(f_{i+1/2} - f_{i-1/2}) + (f_{i-1/2} - f_{i-3/2}) \\
&= f_{i+3/2} - 3f_{i+1/2} + 3f_{i-1/2} - f_{i-3/2}
\end{aligned}$$

Ara satırdan ikinci derece merkezi fark da okunur: $\delta^2 f_i = f_{i+1} - 2f_i + f_{i-1}$.

### 4.4 Farklar nereye gider?

Hoca, bu formüllerden çıkan sayısal sonuçların giderek neye ulaştığını sordu. Cevap sıfırdır. Tahtada $1, 2, 4, 7$ dizisi için birinci farklar $1, 2, 3$, ikinci farklar $1, 1$, üçüncü fark $0$ yazıldı (ekrandan, 00:20:00). Eşitlik olarak yazılırsa formül sonsuza kadar genelleştirilebilir; ama verilen veri kümesinde, verinin uzunluğuna göre farklar bir yerden sonra sıfırlanır.

Bunun nedeni türevle ilişkisidir. $f(x)$ üçüncü dereceden bir polinom ise üç kez türev alınınca sabite, dördüncü türevde sıfıra ulaşılır; beşinci dereceden olsa bir türev daha gerekir. Dolayısıyla bir yerden sonra sıfıra ulaşmak kesindir. Literatürde verilere uydurulurken en çok üçüncü derece polinom kullanılır. Bu yüzden sonlu farklarda en fazla dört fark alınır; sonrası zaten sıfır olduğu için etkisi yoktur.

## 5. Binom Katsayılarıyla Genel İleri Fark Formülü

İleri ya da geri fark katsayıları binom açılımından gelir. Hoca hatırlatma olarak $(x + y)^n$ açılımını anlattı: $n$ üssü $x$ ve $y$'ye farklı biçimlerde dağıtılır ($0$ ve $n$, $1$ ve $n-1$, $2$ ve $n-2$, ..., $k$ ve $n-k$). Bu dağılımın genel hali binom formülüdür:

$$(x + y)^n = \sum_{k=0}^{n} \binom{n}{k} x^{n-k} y^k$$

Aynı yapı ileri farkta da vardır. $k$. dereceden ileri fark, işaretleri artı-eksi değişen binom katsayılarıyla açılır (ekrandan, 00:25:00):

$$\Delta^k f_k = \sum_{i=0}^{k} (-1)^i \binom{k}{i} f_{k-i}$$

Burada $(-1)^i$ işaretin değişmesini, $\binom{k}{i}$ katsayıyı sağlar. Örneğin üçüncü dereceden açarken $\binom{3}{0} = 1$ ile $f_3$, sonra $f_2$, $f_1$, $f_0$ terimleri gelir.

Hoca $\binom{k}{i} = \binom{k}{k-i}$ eşitliğini de hatırlattı. $\binom{10}{8}$'i hesaplamak zahmetlidir, onun yerine $\binom{10}{2}$ hesaplanır. Mantığı şudur: 10 elemandan 8'ini seçmek yerine seçilmeyecek 2'sini seçebilirsiniz; seçmedikleriniz de bir seçimdir, durum sayısı aynıdır. Katsayılar daha kolay yoldan Pascal üçgeninden (Ömer Hayyam üçgeni diye de anılır) çıkarılabilir.

### 5.1 Örnek: $k = 5$ için ileri fark

Slayttaki soru: "$k=5$ için ileri fark formülünden 5. türevi alınız" (ekrandan, 00:25:00). Hoca yanına Pascal üçgenini $1$; $1, 1$; $1, 2, 1$; $1, 3, 3, 1$; $1, 4, 6, 4, 1$; $1, 5, 10, 10, 5, 1$ diye yazdı. $i = 0$'dan $5$'e altı terim vardır:

| $i$ | Terim | Değer |
|---|---|---|
| 0 | $(-1)^0 \binom{5}{0} f_5 = 1 \cdot \frac{5!}{0!\,5!} f_5$ | $f_5$ |
| 1 | $(-1)^1 \binom{5}{1} f_4 = -1 \cdot \frac{5!}{1!\,4!} f_4$ | $-5f_4$ |
| 2 | $(-1)^2 \binom{5}{2} f_3 = 1 \cdot \frac{5!}{2!\,3!} f_3$ | $10f_3$ |
| 3 | $(-1)^3 \binom{5}{3} f_2 = -1 \cdot \frac{5!}{3!\,2!} f_2$ | $-10f_2$ |
| 4 | $(-1)^4 \binom{5}{4} f_1 = 1 \cdot \frac{5!}{4!\,1!} f_1$ | $5f_1$ |
| 5 | $(-1)^5 \binom{5}{5} f_0 = -1 \cdot \frac{5!}{5!\,0!} f_0$ | $-f_0$ |

Toplam:

$$\Delta^5 f_5 = f_5 - 5f_4 + 10f_3 - 10f_2 + 5f_1 - f_0$$

Burada $f_0, \dots, f_5$, verilen tablodaki sayısal değerlerdir; yerine konunca beşinci ileri fark doğrudan bulunur. Farkları sütun sütun tekrar tekrar almak yerine bu formül işletilerek sonuca bir adımda ulaşılır. Katsayılar python ile kontrol edildi.

> **Ders sonrası not:** Slaytın $i = 5$ satırında kombinasyon $\binom{5}{4}$ diye yazılmış; doğrusu $\binom{5}{5}$'tir. Aynı satırdaki $\frac{5!}{5!\,0!} = 1$ hesabı ve $-f_0$ sonucu doğrudur.

## 6. Sonlu Fark Tabloları

Hoca, konunun asıl işe yarayan kısmının sonlu fark tabloları olduğunu söyledi. Bu tablolar sayesinde veri kümesindeki değişime, düzene, örüntüye bakılır ve bu örüntüyle denklem tahmin edilir.

### 6.1 Tablonun kurulması

$x_i$ ve $f_i$ sütunları verilmiştir. Yeni bir sütun eklenir. İleri farkta $f_0$'dan $f_{-1}$ çıkarılamayacağı için (slayt düzeninde) ilk satır boş kalır; ikinci satıra $f_1 - f_0$, üçüncü satıra $f_2 - f_1$ yazılır ve böyle devam edilir. Her yeni sütun bir öncekinin ardışık farklarından oluşur. Beş nokta varsa en fazla dördüncü farka kadar açılabilir, sonrasında açılacak bir şey kalmaz. Ardışık terimler eşitse fark sıfır olur; bir sütun $2, 2, 2$ ise sonraki sütun $0, 0$ olur.

Genel olarak noktalar $x_0, x_0 + h, x_0 + 2h, x_0 + 3h, \dots$ biçiminde sabit aralıklı olup fonksiyon görüntüleri sayısal olarak verilir; tabloda birinci, ikinci, üçüncü, dördüncü mertebeden ileri farklar sütunlar halinde gösterilir. Bunlara **sonlu fark tabloları** denir. Özellikle tablonun başlangıç değerleri (ilk satırlardaki farklar) çok önemlidir, çünkü ilerleyen derslerde fonksiyon tahmin edilirken, üçüncü ya da dördüncü mertebeden polinom üretilirken bu değerler kullanılacaktır.

Geri fark tablosu da aynı biçimde kurulur: her değerden bir öncekini çıkarıp yanındaki sütuna yazarak ilerlenir. Merkezi fark tablosunda ise iki değerin farkı ikisinin arasına (yarım indisli yere) yazılır; hoca bunun pek kullanılmadığını belirtti.

### 6.2 Örnek: $F(x) = x^3 - 3x$ için ileri fark tablosu

Slayttaki soru: "$F(x) = x^3 - 3x$ fonksiyonu için $h=1$ ve $[-3, 2]$ aralığında ileri fark tablosunu çıkarınız" (ekrandan, 00:30:00). Hoca, sonraki konularda fonksiyonun verilmeyeceğini, burada yöntemin işe yaradığını göstermek için bir sağlama yapıldığını söyledi.

**Verilen:** $x$ değerleri $-3$'ten başlayıp $h = 1$ adımla artar: $-3, -2, -1, 0, 1, 2$.

**Fonksiyon değerleri:** $f(-3) = -27 + 9 = -18$, $f(-2) = -8 + 6 = -2$, $f(-1) = -1 + 3 = 2$, $f(0) = 0$, $f(1) = 1 - 3 = -2$, $f(2) = 8 - 6 = 2$ (ara adım eklendi).

**Farklar** (ekrandan, 00:30:00):

- $\Delta f$: $-2 - (-18) = 16$, $2 - (-2) = 4$, $0 - 2 = -2$, $-2 - 0 = -2$, $2 - (-2) = 4$.
- $\Delta^2 f$: $4 - 16 = -12$, $-2 - 4 = -6$, $-2 - (-2) = 0$, $4 - (-2) = 6$.
- $\Delta^3 f$: $-6 - (-12) = 6$, $0 - (-6) = 6$, $6 - 0 = 6$.
- $\Delta^4 f$: $0$, $0$.

| $x_i$ | $f(x_i)$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
|---|---|---|---|---|---|
| $-3$ | $-18$ | | | | |
| $-2$ | $-2$ | $16$ | $-12$ | | |
| $-1$ | $2$ | $4$ | $-6$ | $6$ | |
| $0$ | $0$ | $-2$ | $0$ | $6$ | $0$ |
| $1$ | $-2$ | $-2$ | $6$ | $6$ | $0$ |
| $2$ | $2$ | $4$ | | | |

Tablo slayttaki düzende verilmiştir; hoca fark sütunlarının biraz aşağıda (iki değerin arasında) olması gerektiğini, bunun önemli olmadığını söyledi. Değerler python ile kontrol edildi.

**Yorum:** Üçüncü farklar sabit $6$'ya ulaştı, dördüncü farklar sıfır oldu. Genel olarak **$n$. dereceden bir polinomun $n$. dereceden farkı sabit bir sayıya eşittir**; $(n+1)$. fark sıfırdır (ekrandan, 00:30:00). Nedeni yine türevdir: $x^3$'ün birinci türevi $3x^2$, ikincisi $6x$, üçüncüsü $6$'dır (ekrandan, 00:35:00). İkinci fark sütununda da $6$'nın katları ($-12, -6, 0, 6$) görülür.

Genel bir polinom $P_n(x) = a_0 x^n + a_1 x^{n-1} + \dots + a_{n-1} x + a_n$ biçiminde gösterilirse, üçüncü dereceden bir polinom için üçüncü fark

$$\Delta^3 P_3(x) = 6 a_0 h^3$$

olur. $h = 1$ ve $a_0 = 1$ için $\Delta^3 f(x) = 6 \cdot 1 \cdot 1^3 = 6$ çıkar ve fark tablosundan da aynı sonuca ulaşılmıştır (ekrandan, 00:30:00). Hoca, ilerleyen derste anlamlı olacak değerlerin tablonun ilk değerleri olduğunu ve $x^3 - 3x$ gibi bir fonksiyonu tahmin ederken bunlardan yararlanılarak polinom üretileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Genel olarak $n$. dereceden polinom için $\Delta^n P_n(x) = a_0\, n!\, h^n$'dir; $n = 3$ için $3! = 6$ olduğundan slayttaki $6 a_0 h^3$ formülü bunun özel halidir.

## 7. Sonlu Farklarda Hatanın Yayılması

### 7.1 Geriye doğru izleme

Hoca tablodaki $-6$ değerini neyin etkilediğini sordu. $-6$, $-2$'den $4$'ün çıkarılmasıyla bulunur. $-2$, solundaki $0$ ile $2$'den; $4$ ise $2$ ile $-2$'den gelir (ekrandan, 00:35:00). Buna geriye doğru izleme (backtracking) denir: $-6$'yı hesaplamak için önce iki değere, onlar için üç değere, sonra dört değere ulaşılır. Her kademe geriye gidildikçe bir değer daha işe karışır.

Bunun sonucu şudur: Tablonun bir yerinde yapılan bir hata sonraki tek bir değeri değil, birden fazla değeri etkiler. Buna **sonlu farklarda hatanın yayılması** denir.

### 7.2 Hatanın binom katsayılarıyla yayılması

Fonksiyon değerleri hesaplanırken $x_3$ için küçük bir hata yapıldığını ve $f_3$'ün gerçeğinden $\varepsilon$ kadar farklı, yani $f_3 + \varepsilon$ hesaplandığını varsayalım.

- **Birinci farklar:** $f_3 + \varepsilon - f_2$ farkı olması gerekenden $\varepsilon$ fazla, $f_4 - (f_3 + \varepsilon)$ farkı $\varepsilon$ eksik çıkar. Hata katsayıları $1, -1$.
- **İkinci farklar:** hata katsayıları $1, -2, 1$.
- **Üçüncü farklar:** hata katsayıları $1, -3, 3, -1$.

Yani hata yine binom dağılımı gibi yayılır: başta yapılan ufak bir hata, sonraki sütunlarda büyüyerek sonucu ciddi biçimde etkileyebilir. Hoca, buradaki katsayıların binom katsayıları olduğuna tekrar dikkat çekti ve sonlu fark tablolarının hazırlanmasının bir ön işlem olduğunu söyledi.

## 8. Enterpolasyona Giriş

### 8.1 Tanım ve temel fikir

Elimizde bir fonksiyon değil, $x$ değerleri ve bunlara karşılık gelen $y = f(x)$ değerleri vardır. Hoca tahtada $x = 8$ için $y = 18$, $x = 9$ için $y = 29$ yazdı (ekrandan, 00:40:00). Enterpolasyon yapmak, örneğin $8$ ile $9$ arasındaki $8{,}25$'in değerini bulmak demektir.

Bunun için verilen bütün $(x, y)$ noktalarından geçen bir doğru ya da eğri üretilir. Enterpolasyonda anahtar nokta budur: üretilen fonksiyon **bütün noktaların üzerinden geçmek zorundadır**. Sonra herhangi bir ara değer seçilip değeri bu fonksiyondan tahmin edilir.

> **Hocanın vurgusu:** Bu bir tahmindir; bir şeyi kesin olarak belirlemek (tayin etmek) değildir. Mutlaka bir hata olur. Üretilen fonksiyonun gerçek verilere uyumu ve seçilen parametreler hatayı etkiler.

Elde az nokta varsa enterpolasyon yapmak mantıklıdır. Ekrandaki "Interpolasyon Örnekleri" grafiğindeki gibi çok sayıda dağınık nokta varsa bütün noktalardan geçen bir fonksiyon üretmek çok güçtür (ekrandan, 00:40:00). Bir yerden sonra ortaya çıkan eğri fonksiyon bile olmaz, çünkü fonksiyonda her $x$ değerinin tek bir görüntüsü olmalıdır. Bu durumda regresyona başvurulur; o konu ilerleyen derste işlenecektir.

### 8.2 İki yaklaşım

- **Tek fonksiyon:** Üretilecek fonksiyon bir doğru, logaritmik, üstel, polinom ya da ortogonal polinom olabilir. Ekrandaki grafikte aynı veriye lineer, logaritmik, eksponansiyel, polinom ve ortogonal polinom enterpolasyonu uydurulmuştu (ekrandan, 00:40:00).
- **Parçalı fonksiyon (spline):** Sayısal integralde olduğu gibi, veri kümesini baştan sona tek bir fonksiyona uydurmak yerine her bölgeye ayrı bir fonksiyon üretilir. Buna spline denir, Türkçede "şerit" diye çevrilmiştir. Bu parçaların bileşkesi parçalı fonksiyon gibi kullanılarak daha gerçeğe yakın sonuçlar elde edilir. Örneğin $0$ ile $8$ arası bir $P(x)$ polinomu, $9$ ile $18$ arası bir logaritma fonksiyonu olabilir; dağılım neyi gerektiriyorsa o seçilir.

Enterpolasyon, tablo halinde verilen bir değişkenin tabloda olmayan bir değerini bulmak olarak tanımlanabilir; aranan değer verilenlerin arasında olmalıdır. Verilenlerin dışında, örneğin $x_{n+1}$ gibi bir noktada tahmin yapılırsa buna **ekstrapolasyon** denir; o da bir tahmin türüdür.

### 8.3 Fonksiyon seçimi

Üretilecek fonksiyon polinom, üstel, trigonometrik ya da özel tanımlı bir fonksiyon olabilir; tek bir fonksiyon ya da parçalı fonksiyon şeklinde ifade edilebilir.

**Polinomların tercih edilme nedeni:** Sonlu farklar açısından basit, temiz fonksiyonlardır. Türevleri ve integralleri rahat alınır, modellemeleri kolaydır.

**Trigonometrik fonksiyonlar:** Veride periyodik bir durum, yani değerlerin belli bir yerden sonra kendini tekrar ettiği görülüyorsa sinüs ve kosinüs tercih edilebilir; çünkü bunlar (dalgalar fiziğinden hatırlanacağı gibi) kendini tekrar eden fonksiyonlardır.

Hoca enterpolasyon fonksiyonu seçiminde iki teorem olduğunu söyledi:

- $f(x)$ fonksiyonu $[a, b]$ aralığında sürekli ise bu aralıkta bir polinom kullanılabilir. Elde edilen polinom ile gerçek fonksiyon arasındaki farkın mutlak değeri küçük bir $\varepsilon$'dan az olmalıdır. Hocanın örneği: $x = 1, 2, 3$ için gerçek değerler $4, 8, 18$ olsun; üretilen fonksiyon bunlar için $4$, $8{,}3$ ve çok farklı bir değer verirse hatalar $0$, $0{,}3$ ve büyük bir değer olur. Hata bir noktada bozuluyorsa başka bir polinom üretmek gerekir.
- Fonksiyon $2\pi$ periyotlu ve sürekli ise sinüs ve kosinüslerin toplamı biçiminde yazmak daha kolaydır. Kosinüslerin katsayılarına $a_k$, sinüslerin katsayılarına $b_k$ denir. Bu durumda da üretilen fonksiyonla gerçek değerler arasındaki fark belli bir $\varepsilon$ içinde kalmalıdır.

<!-- BELİRSİZ: Hocanın polinom hata örneğinde üçüncü noktanın tahmini değeri ve hatası altyazıda tutarsız ("on sekizde on sekiz buldu" ama "bunda on hata var"); kare yok. -->

$a_k$ ve $b_k$ katsayılarının bulunması ayrı ve ayrıntılı bir konudur (Fourier serileri); hoca bunun sonraki dönem sinyaller ve sistemler dersinde işleneceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Birinci teorem literatürde Weierstrass yaklaşım teoremi olarak bilinir. İkincisi ise sürekli periyodik fonksiyonların trigonometrik polinomlarla istenen hassasiyette yaklaşılabileceğini söyler; biçimi $\frac{a_0}{2} + \sum_k (a_k \cos kx + b_k \sin kx)$'tir.

## 9. Doğrusal Enterpolasyon

### 9.1 İki noktası bilinen doğru

Doğrusal enterpolasyon, aslında iki noktası bilinen doğrunun denklemini bulmaktır. Bir $x_1$ noktası ve $f(x_1)$ değeri, bir $x_2$ noktası ve $f(x_2)$ değeri sayısal olarak verilmişse bu iki noktadan bir doğru çizilir. Üçüncü nokta $x_3$, ara değeri bulunmak istenen yeni noktadır (ekrandan, 00:45:00).

Slayttaki "eğim üzerinden doğru denklemini bulmak" formülü (ekrandan, 00:45:00):

$$\frac{f(x_2) - f(x_1)}{x_2 - x_1} = \frac{f(x_3) - f(x_1)}{x_3 - x_1}$$

Sol taraf iki bilinen noktadan bulunan eğimdir. Hoca bunu iki noktası bilinen doğru denkleminin genel haliyle ilişkilendirdi: $(x_1, y_1)$ ve $(x_2, y_2)$ noktalarından geçen doğru için $\frac{y - y_1}{x - x_1} = \frac{y_2 - y_1}{x_2 - x_1}$ yazılır. Burada $y_2 = f(x_2)$, $y_1 = f(x_1)$'dir; $x_3$ değişken $x$, $f(x_3)$ de aranan $y$'dir. Aradaki herhangi bir değer yerine konarak görüntüsü tahmin edilir.

### 9.2 Train ve test

Hoca bu kurguyu makine öğrenmesindeki eğitim-test ayrımıyla ilişkilendirdi. Doğruyu üretmek için kullanılan iki noktaya **train**, üretilen modeli denemek için ayrılan noktaya **test** denir. Örneğin $A$, $B$, $C$ diye üç nokta verildiyse ikisi (üçün ikili kombinasyonlarından herhangi biri: $A$-$B$, $A$-$C$ ya da $B$-$C$) doğruyu üretmek için seçilir, seçilmeyen nokta ile model test edilir.

### 9.3 Örnek: Tablodan $f(2)$ tahmini

Slayttaki soru (ekrandan, 00:50:00): Bir $f(x)$ fonksiyonu için bazı değerler verilmiştir:

| $x$ | $f(x)$ |
|---|---|
| $-2$ | $-0{,}909297$ |
| $-1$ | $-0{,}841471$ |
| $0$ | $0$ |
| $1$ | $0{,}841471$ |
| $3$ | $0{,}141120$ |
| $4$ | $-0{,}756802$ |
| $6$ | $-0{,}279415$ |

a) $f(2)$ değerini $x = 1$ ve $x = 3$ kullanarak doğrusal enterpolasyon metoduyla bulunuz.

b) $f(2)$ değerini $x = -2$ ve $x = 6$ kullanarak doğrusal enterpolasyon metoduyla bulunuz.

Hoca, $-2$'den $6$'ya yedi nokta olduğunu, yedi noktayla doğru değil neredeyse polinom üretileceğini, doğrusal enterpolasyon için iki nokta seçmek gerektiğini ve nokta seçiminin hatayı etkilediğini belirtti. (a)'da $1$ ve $3$ seçilmesinin nedeni, $2$'ye en yakın noktalar olmalarıdır. Bir görüntünün en net halini görmek için yakınlaştırma (zoom) yapılması gibi, $1$ ile $3$ arasına bakılır; $-2$ ya da $6$ gibi uzak noktalar $2$'yi pek ilgilendirmeyebilir.

**a) Çözüm** (ekrandan, 00:50:00): $f(1) = 0{,}841471$, $f(3) = 0{,}141120$.

$$\frac{f(3) - f(1)}{3 - 1} = \frac{f(2) - f(1)}{2 - 1} \;\Rightarrow\; \frac{0{,}141120 - 0{,}841471}{2} = \frac{f(2) - 0{,}841471}{1}$$

$\frac{-0{,}700351}{2} = -0{,}3501755$ olduğundan (ara adım eklendi):

$$f(2) = 0{,}841471 - 0{,}3501755 = 0{,}4912955$$

**b) Kurulum** (ekrandan, 00:50:00): $f(-2) = -0{,}909297$, $f(6) = -0{,}279415$.

$$\frac{f(6) - f(-2)}{6 - (-2)} = \frac{f(2) - f(6)}{2 - 6}$$

Hoca bu sonucu derste hesaplamadı.

> **Çözüm (derste verilmedi):** Eğim $\frac{-0{,}279415 + 0{,}909297}{8} = \frac{0{,}629882}{8} = 0{,}07873525$'tir. $f(2) = f(6) + 0{,}07873525 \cdot (2 - 6) = -0{,}279415 - 0{,}314941 = -0{,}594356$ bulunur (python ile hesaplandı).

**Soru:** Bu iki sonuçtan hangisi doğru olabilir? **Cevap:** Bir öğrenci birincinin daha yakın olabileceğini söyledi. Hoca "olabilir" ifadesinin doğru olduğunu, kesin bilinemeyeceğini, yalnız tahmin yürütülebileceğini vurguladı. Birincinin daha yakın çıkması beklenir, çünkü aranan noktaya daha çok yaklaşılmıştır. Fonksiyon sürekli ise ve $1$ ile $3$ arasında ciddi bir sürpriz (ani bir sıçrama ya da garip bir davranış) yoksa, $2$'nin değeri bu ikisinin arasında bir yerdedir. Bu yüzden $-2$ ile $6$ arasına bakmaktansa $1$ ile $3$ arasına bakmak daha doğru olabilir, ama yine de kesin bir şey söylenemez.

> **Ders sonrası not:** Tablodaki değerler $\sin x$'in değerleriyle birebir aynıdır (python ile karşılaştırıldı); veri büyük olasılıkla $\sin x$ fonksiyonundan alınmıştır. Bu durumda gerçek değer $\sin 2 \approx 0{,}909297$'dir. (a) sonucu ($0{,}4913$) gerçeğe (b) sonucundan ($-0{,}5944$) çok daha yakındır, ama ikisi de büyük hata taşır; aralık geniş olduğunda doğrusal enterpolasyonun sınırlı kaldığı görülür.

### 9.4 Parça parça doğrusal enterpolasyon ve ground truth

Bu yüzden bu tür problemlerde ya doğrusal enterpolasyon hiç yapılmaz ya da **parça parça doğrusal enterpolasyon** yapılır. Tek bir kural söylenmez; her aralık için ayrı bir doğru üretilir ve değerlendirme hangi aralıkta yapılacaksa o aralığın doğrusu kullanılır, diğerleri dikkate alınmaz. Buna spline (şerit modeli) denir.

Hoca yüksek çözünürlüklü veri örneği verdi: $x$ değerleri $0$'dan başlayıp $0{,}001$, $0{,}002$, ... diye çok hassas artarak $5$'e kadar gidiyor olsun; bu yaklaşık $5000$ veri demektir. $5000$ verinin hepsini kullanmak yerine örneğin $0$ ve $0{,}01$ noktalarından bir doğru üretilir ve bu doğru aradaki noktalarda test edilir. Aradaki noktaların gerçek değerleri elimizde olduğu için, doğrunun verdiği değerlerle gerçek değerler arasındaki fark kabul edilebilir bir hatanın altındaysa bu doğru kullanılabilir. Sonra bir sonraki aralığa ($0{,}01$ ile $0{,}02$) geçilir ya da aralık genişletilerek doğru güncellenir; her seferinde $\varepsilon$'a bakılarak en doğru model aranır.

Bu gerçek değerlere literatürde **ground truth** denir. Hoca görüntü işlemeden örnek verdi: bir görüntüde araba tespit edilmeye çalışılır; tahmin edilen konum ile arabanın gerçek konumunun işaretlendiği ground truth görüntüsü karşılaştırılır. Aradaki fark sıfıra yakınsa doğru bir tahmin yapılmıştır. Aynı kavram burada tek boyutlu veri için kullanılabilir.

### 9.5 $F(x) = Ax + B$ biçiminde doğrusal enterpolasyon

Enterpolasyon fonksiyonu olarak birinci dereceden bir polinom (doğru) kullanılıyorsa buna **doğrusal (lineer) enterpolasyon** denir (ekrandan, 00:55:00). $x$ değişkeni $[a, b]$ aralığında bir $f(x)$'e aitse enterpolasyon fonksiyonu olarak

$$F(x) = Ax + B$$

seçilirse $f(a) = F(a)$ ve $f(b) = F(b)$ bağıntılarının sağlanması gerekir (ekrandan, 00:55:00). Hoca bunu $y = mx + n$ doğrusuyla eşleştirdi: $A$ eğim ($m$), $B$ ise sabit terimdir ($n$).

- $A$, iki noktadan eğim olarak bulunur: $A = \dfrac{f(b) - f(a)}{b - a}$ (ara adım eklendi).
- $B$, noktalardan biri yerine konarak bulunur: $f(a) = Aa + B \Rightarrow B = f(a) - Aa$ (ara adım eklendi).

<!-- BELİRSİZ: Slaytın "Buradan;" sonrasındaki A ve B formülleri karede görünmüyor; yukarıdaki ifadeler hocanın sözlü anlatımından kuruldu. -->

$A$ ve $B$ yerine yazıldığında doğrusal enterpolasyon denklemi elde edilir. Hoca bunun zaten bilinen iki noktası bilinen doğru denklemi olduğunu, yalnız adının doğrusal enterpolasyon olduğunun belki şimdiye kadar bilinmediğini söyledi. Sonraki konu eğri (doğrusal olmayan) enterpolasyon yöntemleridir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:05:59): $1, 2, 4, 7, 11, 16, 22$ dizisinde sonraki sayı nedir?

Çözüm (derste verildi): Ardışık farklar $1, 2, 3, 4, 5, 6$'dır; sonraki fark $7$ olacağından sonraki terim $22 + 7 = 29$'dur. Farkların farkı sabit $1$'dir.

**Soru 2** (derste sözlü, 00:15:16): $\Delta^2 f_i = f_{i+2} - 2f_{i+1} + f_i$ formülündeki katsayılar size neyi hatırlatıyor?

Çözüm (derste verildi): Binom (kombinasyon) katsayılarını, yani Pascal üçgenini. İkinci farkta $1, 2, 1$, üçüncü farkta $1, 3, 3, 1$ katsayıları işaretleri değişerek gelir.

**Soru 3** (derste sözlü, 00:18:53): Merkezi (ve genel olarak sonlu) farklar derece arttıkça hangi değere ulaşır?

Çözüm (derste verildi): Sıfıra. Örneğin $1, 2, 4, 7$ için farklar $1, 2, 3$; sonra $1, 1$; sonra $0$ olur. Veri bir polinomdan geliyorsa polinomun derecesi kadar fark alınınca sabite, bir fazlasında sıfıra ulaşılır.

**Soru 4** (ekrandan, 00:25:00): $k=5$ için ileri fark formülünden 5. türevi alınız: $\Delta^5 f_5 = \sum_{i=0}^{5} (-1)^i \binom{5}{i} f_{5-i}$.

Çözüm (derste verildi): $\Delta^5 f_5 = f_5 - 5f_4 + 10f_3 - 10f_2 + 5f_1 - f_0$. Ayrıntı Bölüm 5.1'dedir.

**Soru 5** (ekrandan, 00:30:00): $F(x) = x^3 - 3x$ fonksiyonu için $h = 1$ ve $[-3, 2]$ aralığında ileri fark tablosunu çıkarınız.

Çözüm (derste verildi): $f$: $-18, -2, 2, 0, -2, 2$; $\Delta f$: $16, 4, -2, -2, 4$; $\Delta^2 f$: $-12, -6, 0, 6$; $\Delta^3 f$: $6, 6, 6$; $\Delta^4 f$: $0, 0$. Üçüncü fark $6 a_0 h^3 = 6$ ile uyumludur. Ayrıntı Bölüm 6.2'dedir.

**Soru 6** (derste sözlü, 00:33:33): Tablodaki $-6$ değerini hangi değerler etkiler?

Çözüm (derste verildi): $-6 = -2 - 4$'tür. $-2$, $0$ ile $2$'den; $4$, $2$ ile $-2$'den gelir. Geriye gidildikçe her kademede bir değer daha işe karışır; bu yüzden bir değerdeki hata ileriye binom katsayılarıyla yayılır.

**Soru 7** (ekrandan, 00:50:00): Tablodaki değerlere göre (a) $f(2)$'yi $x=1$ ve $x=3$ kullanarak, (b) $f(2)$'yi $x=-2$ ve $x=6$ kullanarak doğrusal enterpolasyonla bulunuz. Hangisi daha doğru olabilir?

Çözüm: (a) derste verildi: $f(2) = 0{,}4912955$. (b) için kurulum derste yapıldı, sonuç hesaplanmadı.

> **Çözüm (derste verilmedi):** (b) $f(2) = -0{,}279415 + \frac{0{,}629882}{8}(2 - 6) = -0{,}594356$ (python ile hesaplandı). Derste aranan noktaya yakın noktaları kullanan (a) seçeneğinin daha doğru olabileceği, ama kesin bilinemeyeceği söylendi.

## Dersin Toparlaması

Bu derste, verilerden fonksiyon tahmin etmenin temeli olan sonlu farklar işlendi. Fark aralığı $h$ tanımlandı; ileri ($\Delta$), geri ($\nabla$), merkezi ($\delta$), ortalama ($\mu$) ve kaydırma ($E$) operatörleri tanıtıldı. Yüksek dereceden farkların katsayılarının işaretleri değişen binom katsayıları olduğu gösterildi ve $\Delta^k f_k = \sum (-1)^i \binom{k}{i} f_{k-i}$ genel formülüyle $k=5$ örneği çözüldü. $x^3 - 3x$ için kurulan sonlu fark tablosunda üçüncü farkın sabit $6 = 6a_0h^3$, dördüncü farkın sıfır olduğu görüldü. Tablodaki bir hatanın sonraki sütunlara binom katsayılarıyla yayıldığı açıklandı.

Dersin ikinci kısmında enterpolasyona giriş yapıldı: ara değer bulma, ekstrapolasyon, polinom ve trigonometrik fonksiyon seçimi, spline yaklaşımı ve doğrusal enterpolasyon. Doğrusal enterpolasyonun iki noktası bilinen doğru denklemi olduğu ve nokta seçiminin sonucu güçlü biçimde etkilediği bir tablo örneğiyle gösterildi. Sonraki derste eğri enterpolasyonu ve diğer enterpolasyon yöntemlerine geçilecek; sonlu fark tablolarının başlangıç değerleri bu yöntemlerde polinom üretmek için kullanılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
