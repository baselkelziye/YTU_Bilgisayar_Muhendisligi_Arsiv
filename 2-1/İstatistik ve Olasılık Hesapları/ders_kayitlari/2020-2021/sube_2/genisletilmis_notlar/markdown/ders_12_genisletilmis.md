# Ders 12 Genişletilmiş Notu: Histogram Şekilleri, Kutu, Saçılım ve Zaman Grafikleri; Momentler ve En Çok Olabilirlik Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: Histogram ve Göreli Frekans Histogramı
- 2. Sık Görülen Histogram Şekilleri
- 3. Karışım Dağılımları
- 4. Kutu Grafiği ve Paralel Kutu Grafikleri
- 5. Saçılım Grafiği
- 6. Zaman Grafiği
- 7. İstatistiksel Çıkarım ve Parametre Tahmini
- 8. Momentler
- 9. Momentler Yöntemi
- 10. En Çok Olabilirlik Yöntemi

## 1. Tekrar: Histogram ve Göreli Frekans Histogramı

Hoca derse bir önceki haftayı Türkçe olarak hatırlatarak başladı. Geçen hafta grafiksel istatistiklere başlanmış, çeşitli grafiklerin ilki olarak histogramlar görülmüştü.

Histogram şöyle kurulur: Verinin aralığı kovalara (bin) ayrılır, her kovada kaç gözlem olduğu sayılır ve bu sayılar çubuklardan oluşan bir grafiğe dökülür. Hocanın örneği, önceki derslerden tanıdığımız CPU verisiydi. Bu veri 9'dan başlıyordu. Aralık 14'lük kovalara ayrılınca $0$–$14$, $14$–$28$, $28$–$42$ gibi kovalar oluşuyordu. Hocanın okuduğu sayılar, ilk kovada 1, ikinci kovada 5, üçüncü kovada 9 gözlemdi.

> **Ders sonrası not:** Hoca ikinci kovayı önce "0–28 arası" diye okudu; doğrusu $14$–$28$'dir. Hocanın 00:08:29'daki "14 ile 28 arasında" ifadesi de bunu gösterir. Hoca verinin 135'e kadar gittiğini ve $28$–$42$ kovasında 9 gözlem olduğunu söyledi; kısa nota göre büyük olasılıkla en büyük değer 139, bu kovadaki gözlem sayısı ise 8'dir. Veri bu altyazıda listelenmediği için bu iki sayı burada doğrulanamadı.

### 1.1 Histogram Bize Ne Söyler?

Histogram birkaç bakımdan önemlidir. Verinin bir dağılımdan geldiğini varsayarsak, histogram bu veriyi üreten dağılımın şeklini "iyi kötü" gösterir. Çubukların üzerinden hayalen bir eğri geçirip "bu veri böyle bir grafiğe sahip bir dağılımdan gelmiş olabilir" diyebiliriz. Hoca bildiğimiz dağılımlar arasından CPU verisinin şekline benzeyen aday olarak gamayı gösterdi.

Aynı grafikten iki şey daha okunur:

- **Aykırı değer (outlier):** Bu grafikte bir aykırı değer olduğu görülüyordu.
- **Homojenlik:** Dağılım genel olarak homojendi, yani birden fazla dağılımın karışımı değildi. Karışımlar 3. bölümde görülecek.

<!-- BELİRSİZ: Hocanın histogramın üzerine hayalen çizdiği eğri ve aykırı değerin yeri altyazıda yalnız "şöyle bir şey" diye geçiyor. -->

### 1.2 Göreli Frekans Histogramı

Kovalardaki sayıları doğrudan yazmak yerine toplam gözlem sayısına bölebiliriz. CPU verisinde 30 gözlem vardır, bu yüzden kovalara $1/30$, $5/30$, $9/30$ gibi değerler yazılır. Kovalardaki sayıların toplamı 30 olduğu için bu kesirlerin toplamı 1 olur.

Bu histograma göreli frekans histogramı (relative frequency histogram) denir. Hoca bunun aslında bir nevi olasılık olduğunu vurguladı: Elimizde gözleme dayalı (empirical) bir olasılık dağılımı vardır. Buna göre $0$ ile $14$ arasında bir gözlem görme olasılığımız $1/30$, $14$ ile $28$ arasında bir gözlem görme olasılığımız $5/30$'dur.

> **Hocanın vurgusu:** Histogram bize bir olasılık dağılımı verir.

## 2. Sık Görülen Histogram Şekilleri

Hoca bundan sonra anlatıma İngilizce devam etti ve farklı örneklemlerde karşılaşabileceğimiz histogram şekillerini çizdi. Her şekil, verinin gelmiş olabileceği bir dağılımı düşündürür:

- **Yaklaşık sabit sayılar:** Sayılar biraz değişse de genel olarak sabitse veri büyük ihtimalle düzgün dağılımdan (uniform distribution) gelmiştir.
- **Büyük bir değerden başlayıp azalan sayılar:** Bu şekil üstel dağılıma (exponential distribution) benzer.
- **Simetrik, çan şeklinde görünüm:** Bu, normal dağılım olabilir.

Bunlar yalnızca olası adaylardır. Hoca her birinde "olabilir" diye konuştu: Histogram, verinin gelmiş olabileceği dağılımlar hakkında fikir verir.

## 3. Karışım Dağılımları

Hocanın ilginç bulduğu durum, homojen olmayan bir dağılımdır. Bunlara karışım dağılımları (mixture distributions) denir.

Histogramda normal görünümlü bir yapı ve onun yanında ikinci bir tümsek görebiliriz. Yani iki tepe (hump) vardır. Hoca "hump" sözcüğünün karşılığını "devenin hörgücü" diye verdi. İki hörgüç, bu örneklemde iki şeyin bir şekilde karışmış olduğunu gösterir. Hocanın saydığı olası gruplar şunlardı:

- Erkekler ve kadınlar.
- Lisans ve lisansüstü öğrencileri.
- Gündüz ve gece internet kullanımı.

Hoca örneği ağırlık üzerinden sürdürdü. Popülasyonun bir kısmının ağırlığı $\mu_1$ gibi bir değer, geri kalanının ağırlığı $\mu_2$ gibi bir değer etrafında toplanıyor olabilir. Bu durumda "iki normal dağılımın karışımı var" diyebiliriz.

### 3.1 Karışımı Olasılıkla İfade Etmek

Karışımı olasılıkla ifade etmek gerekir. Bir gözlem $p_1$ olasılıkla birinci dağılımdan, $p_2$ olasılıkla ikinci dağılımdan gelir. Birinci dağılımın birikimli dağılım fonksiyonu $F_1$, ikincininki $F_2$ olsun. $X$'in birikimli dağılım değerini yazmak istiyoruz:

- $p_1$ olasılıkla $X$ birinci dağılımdandır ve bu durumda birikimli olasılık değeri $F_1(x)$'tir.
- $p_2$ olasılıkla $X$ ikinci dağılımdandır ve bu durumda birikimli olasılık değeri $F_2(x)$'tir.

Bunlar toplanınca karışım dağılımının formülü elde edilir:

$$F(x) = p_1 F_1(x) + p_2 F_2(x)$$

$F_1$ ve $F_2$, histogramda hangi dağılımı gördüğünüzü düşündüğünüze göre seçilir. Hoca örnekte normal dağılımı kullansa da başka dağılımların da olabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Kısa notta ayrıca $p_1 + p_2 = 1$ koşulu yazılıdır; hoca bunu altyazıda söylemedi. Bir gözlemin iki dağılımdan birinden gelmesi varsayıldığı için bu koşul büyük olasılıkla karışımın doğal parçasıdır.

## 4. Kutu Grafiği ve Paralel Kutu Grafikleri

Histogramlar veriyi anlamamıza yardım eder. Histogramların yanında bir de kutu grafikleri (box plots) vardır.

### 4.1 Kutu Grafiğinin Parçaları

Hoca yatay bir $X$ ekseni çizip üzerine kutuyu yerleştirdi. Grafiğin parçaları şunlardır:

- **Kutu:** $Q_1$'den başlar, $Q_3$'te biter. $Q_1$ birinci çeyrektir, yani $0.25$-kantil. $Q_3$ ise $0.75$-kantildir.
- **Kutunun içindeki çizgi:** Medyanı, yani $Q_2$'yi gösterir.
- **Kutunun içindeki artı işareti:** Ortalamanın yerini gösterir.
- **Kutudan iki yana çıkan çizgiler:** Bir taraftaki çizgi en küçük değere ($\min X_i$), öbür taraftaki en büyük değere ($\max X_i$) kadar uzanır. Burada $X_i$ bütün veriyi temsil eder.
- **Uzaktaki ayrı noktalar:** Bunlar aykırı değerlerdir.

Hoca çizginin ucuna önce bir nokta çizdi, sonra bunu düzeltti: Çizginin ucunda nokta olması gerekmez, yalnızca çizgi vardır. Noktalar çizginin dışında kalan aykırı değerler içindir.

### 4.2 Aykırı Değerler ve IQR

Aykırı sayılan değerler artık en büyük değer olarak kabul edilmez. Bu yüzden çizginin ucundaki $\max X_i$, aslında aykırı olmayanlar içindeki en büyük değerdir.

Aykırılık sınırı IQR ile belirlenir. $Q_3$ ile $Q_1$ arasındaki fark IQR'dir. $Q_3$'ten $1.5\,\mathrm{IQR}$ kadar gidince bir noktaya ulaşılır, bu noktanın ötesi aykırı değerdir:

$$\mathrm{IQR} = Q_3 - Q_1, \qquad \text{üst sınır} = Q_3 + 1.5\,\mathrm{IQR}$$

Kutu grafikleri veriyi kısa ve öz biçimde özetler.

> **Ek bilgi (derste anlatılmadı):** Hoca sınırı altyazıda yalnız üst taraf için söyledi. Kısa nota göre alt tarafta da büyük olasılıkla $Q_1 - 1.5\,\mathrm{IQR}$ kullanılır. Kısa notta kutudan çıkan çizgilere "bıyık" (whiskers) denir; hoca bu adı kullanmadı.

### 4.3 Paralel Kutu Grafikleri

Kutu grafikleri yan yana da çizilebilir. Bunlara paralel kutu grafikleri (parallel box plots) denir. Hocanın örneğinde kategoriler haftanın günleriydi ve ölçülen büyüklük internet kullanımıydı. Pazartesi, salı, çarşamba ve diğer günler için yan yana birer kutu çiziliyordu.

Grafikten şu eğilim okunuyordu: Cuma günleri internet kullanımı yüksektir, çünkü cuma tatilden hemen öncedir. Cumadan salıya doğru kullanım düşer, salıdan sonra yeniden artmaya başlar.

**Soru:** En küçük değerin altında da aykırı değerler olabilir mi? **Cevap:** Evet, olabilir. Yukarıda olduğu gibi aşağıda da aykırı değerler görülebilir.

Burada bütün veriye tek bir yerden bakmak yerine, veriyi önce güne göre kategorilere ayırıp verinin nasıl değiştiğini görmeye çalışıyoruz.

<!-- BELİRSİZ: 00:26:07'deki soru altyazıda hocanın ağzından geçiyor; öğrencinin sorusunu mu tekrarladığı, kendi kendine mi sorduğu net değil. -->

## 5. Saçılım Grafiği

Saçılım grafiği (scatter plot), birden fazla rastgele değişkenimiz olduğunda ve her iki değişken için de tam olarak aynı zamanda ya da aynı durumda toplanmış verimiz bulunduğunda kullanılır. Yani birbirine karşılık gelen $X$ ve $Y$ verileri vardır.

### 5.1 Antivirüs Örneği

Hoca kitaptaki bir örneği kullandı:

- $X$: Bir ayda antivirüs yazılımının kaç kez çalıştırıldığı.
- $Y$: O ay bulunan virüs sayısı.

Örneğin bir ay yazılım her gün çalıştırılmış ($x = 30$) ve hiç virüs bulunmamış ($y = 0$). Veri şöyle gidiyordu:

$$(30, 0),\ (30, 0),\ (30, 1),\ (15, 0),\ (15, 1),\ (10, 2),\ (6, 1),\ (6, 2),\ \ldots$$

Bir çiftteki iki sayı aynı ay içinde toplandığı için birbiriyle ilişkilidir.

Bu veriyi çizmek için yatay eksene $x$ değerleri ($10$, $15$, $30$ gibi), düşey eksene $y$ değerleri ($0$, $1$, $2$, $\ldots$) yazılır. Her çift için nokta, daire ya da üçgen gibi bir işaret konur. Hocanın belirttiği gibi çizim programlarında işaret için pek çok seçenek vardır.

Böyle bir grafikle veriye soru sorabiliriz. Hocanın sorusu, daha çok tarama yapınca daha çok virüs bulunup bulunmadığıydı. Eğer öyleyse, 30 kez yerine günde iki kez, yani 60 kez taramak daha iyi olabilir.

<!-- BELİRSİZ: 00:36:03–00:36:26 arasında altyazı kopuk ("until seconds, do you get more viruses"). Sorunun ilk kısmı anlatımın akışından kuruldu. -->

### 5.2 Aynı Çiftin Tekrarı Sorunu

Doğrudan nokta ya da daire koymanın bir sorunu vardır. $(30, 0)$ çifti iki kez gözlenmiştir, $(30, 1)$ çifti bir kez. Ama grafikte ikisinin yerinde de tek bir daire görünür, aralarında fark kalmaz. Hoca bu yüzden grafiğin biraz yanıltıcı olduğunu söyledi. Çözüm, gözlem sayılarını birbirinden ayıracak yollar bulmaktır:

- **Farklı semboller:** Kitapta 1 gözlem için A, 2 gözlem için B, 3 gözlem için C yazılır. Bu örnekte $(30, 0)$ noktasına B, hemen üstündeki $(30, 1)$ noktasına A yazılır. B, orada daha çok veri olduğunu söyler.
- **Farklı şekiller:** A, B, C yerine daire, üçgen, kare kullanılabilir. Örneğin daire 1, üçgen 2, kare 3 gözlem anlamına gelir.
- **Renkler:** Sayılar farklı renklerle de gösterilebilir.
- **Üç boyutlu grafik:** Eksenlere $x$ ve $y$, üçüncü eksene de sayı konur.
- **Yüzey:** Çok veri varsa üç boyutlu bir yüzey bile çizilebilir.

Python'da `matplotlib` kütüphanesi bu grafik türlerinin birçoğunu çizmeye yardım eder.

## 6. Zaman Grafiği

Zaman grafikleri (time plots) saçılım grafiklerine çok benzer, ama yatay eksen zamandır. Hocanın örneğinde düşey eksende dünya nüfusu vardı, yatay eksende yıllar: 1950'ler, 1970'ler, 2000'ler, 2020'ler.

Bu grafikler eğilimleri (trends) açıkça gösterir. Örnekte dünya nüfusunun artma eğilimi görülür. Ayrıca bu eğilim ileriye doğru uzatılarak dış değer kestirimi (extrapolation) yapılabilir: "2030'da dünya nüfusu aşağı yukarı şu kadar olacak" diyebiliriz. Hoca, böyle bir veriniz varsa bu grafiklerin çok yararlı olduğunu söyledi.

Grafikler burada bitti. Hocaya göre böylece Baron'un kitabının 8. bölümü tamamlanmış oldu.

## 7. İstatistiksel Çıkarım ve Parametre Tahmini

Kitabın 9. bölümü parametre tahminiyle (parameter estimation) ilgilidir. Daha genel adı istatistiksel çıkarımdır (statistical inference): Verimizden bilgi çıkarmaya çalışırız. İlk konu parametre tahminidir.

### 7.1 Senaryo

Elimizde bir veri olsun, örneğin CPU verisi ya da $3, 4, 5, 2, 6, \ldots$ gibi başka bir veri. Histogramını çiziyoruz ve şekle bakıp verinin üstel dağılımdan geldiğini düşünüyoruz. Şimdi o üstel dağılımı bulmak istiyoruz. Çünkü onu bulursak gelecek değerleri tahmin etmek gibi pek çok şey yapabiliriz.

Üstel dağılımın yoğunluğunu hatırlayalım:

$$f(x) = \lambda e^{-\lambda x}$$

"Üstel dağılım" dediğimizde aslında çok sayıda üstel dağılımdan söz ediyoruz. Her biri $\lambda$ parametresine göre değişir. O hâlde önemli soru şudur: Bu veri için $\lambda$ kaçtır? $\lambda$'yı bilirsek veriyi üreten üstel dağılımı biliriz. Sonra bugüne kadar öğrendiğimiz her hesabı yapabiliriz: ortalamasını ve medyanını bulabilir, pek çok farklı soruyu cevaplayabiliriz.

### 7.2 Parametre ve Değişken

Burada $\lambda$ bir parametredir, $x$ ise değişkendir. Herhangi bir veri için $\lambda$'nın sabit olduğunu düşünürüz ve $x$'in olasılığını ona göre buluruz. Bu konunun adı da buradan gelir: $\lambda$ parametresini tahmin etmek istiyoruz.

Üstel dağılım tek örnek değildir:

- Veri gama dağılımından geliyorsa parametreler $\alpha$ ve $\lambda$'dır.
- Veri normal dağılımdan geliyorsa parametreler $\mu$ ve $\sigma$'dır.

Bu parametreleri tahmin etmek için iki yöntem görülecek: momentler yöntemi (method of moments) ve en çok olabilirlik yöntemi (method of maximum likelihood).

## 8. Momentler

Momentler yöntemini kullanmadan önce momentin ne olduğunu öğrenmek gerekir.

### 8.1 Moment Nedir?

Moment, $X$'in kuvvetlerinin beklenen değeridir:

- $E[X]$, $X$'in birinci momentidir.
- $E[X^2]$, $X$'in ikinci momentidir.
- $E[X^3]$, $X$'in üçüncü momentidir.

Momentlerin iki türü vardır. Popülasyon momentleri gerçek momentlerdir ve hep parametreye bağlı ifadeler verir. Hoca bunlara önce "denklem" (equation) dedi, ileride "ifade" (expression) sözcüğünü de kullandı. Örneklem momentleri ise bunların veriden hesaplanan tahmin edicileridir (estimator). Veriye sahip olduğumuz için bunları doğrudan hesaplayabiliriz, sonuçları sayıdır.

Popülasyon momentleri $\mu_1, \mu_2, \mu_3$ ile gösterilir. Birinci örneklem momenti $\mu_1$'in tahmin edicisidir:

$$m_1 = \frac{1}{n}\sum_{i=1}^{n} X_i$$

Üçüncü örneklem momenti de benzerdir:

$$m_3 = \frac{1}{n}\sum_{i=1}^{n} X_i^3$$

Fark şudur: Beklenen değer almak yerine ortalama alırız.

> **Ders sonrası not:** Hoca üçüncü örneklem momentini anlatırken "$X_i$'nin karesi" dedi; doğrusu $m_3 = \frac{1}{n}\sum X_i^3$'tür. Üçüncü momentin tanımı, hocanın az sonra verdiği genel $m_k$ formülünden de böyle çıkar.

Genel tanımlar şöyledir:

$$\mu_k = E\left[X^k\right], \qquad m_k = \frac{1}{n}\sum_{i=1}^{n} X_i^k$$

Burada $\mu_k$, $k$. popülasyon momenti, $m_k$ ise $k$. örneklem momentidir.

<!-- BELİRSİZ: 01:08:03'te altyazıda birinci örneklem momenti için "mu one" geçiyor. Hemen ardından örneklem momenti M3 diye yazıldığı için burada m1 kabul edildi. -->

### 8.2 Merkezi Momentler

Merkezi momentler (central moments) bunlara çok benzer, ama önce ortalama çıkarılır. Böylece ortalama sıfıra çekilir, yani veri merkezlenir. Merkezi momentleri üst işaretle (prime) yazarız:

$$\mu'_k = E\left[(X - \mu)^k\right], \qquad m'_k = \frac{1}{n}\sum_{i=1}^{n} \left(X_i - \bar{X}\right)^k$$

Burada $\mu'_k$, $k$. popülasyon merkezi momenti, $m'_k$ ise $k$. örneklem merkezi momentidir. Örneklemde popülasyon ortalaması $\mu$'yü bilmeyiz, ama onun tahmin edicisini biliriz: örneklem ortalaması $\bar{X}$. Bu yüzden örneklem formülünde $\bar{X}$ çıkarılır.

Hoca formülleri ilk yazdığında üs $k$ yalnız $X$'in üzerindeydi. Sonra bunu kendisi düzeltti: Üs parantezin dışındadır.

### 8.3 Bildiğimiz İki Moment

Bu momentlerden bazılarını başka adlarla zaten öğrenmiştik:

- Birinci moment $E[X]$ ortalamadır.
- İkinci merkezi moment $E[(X - \mu)^2]$ varyanstır.

Bunları pek çok dağılım için daha önce hesaplamıştık.

> **Ders sonrası not:** Hoca üstel dağılımın birinci momentini "$\lambda$", varyansını da emin olmadığını belirterek "$\lambda^2$" olarak söyledi; doğrusu $E[X] = 1/\lambda$ ve $\mathrm{Var}(X) = 1/\lambda^2$'dir. Bu iki sonuç, yoğunluk $\lambda e^{-\lambda x}$ üzerinden sayısal integralle python ile hesaplandı.

## 9. Momentler Yöntemi

Momentler yöntemi, popülasyon momentleri ile örneklem momentlerini birbirine eşitleyip denklem elde etmektir:

$$\mu_1 = m_1, \qquad \mu'_2 = m'_2, \qquad \mu_3 = m_3, \ \ldots$$

Sol taraf parametreye bağlı bir ifade, sağ taraf ise veriden hesaplanabilen bir sayıdır. İfade bir sayıya eşit olunca denklem elde edilir. Kaç denkleme ihtiyacınız olduğunu düşünür, o kadar eşitlik yazar ve denklemleri bilinmeyenler için çözersiniz.

### 9.1 Örnek: Gama Dağılımı

**Verilen:** Veri $4, 6, 2$ olsun. Verinin gama dağılımından geldiğini varsayıyoruz. Bu gama dağılımını üreten $\alpha$ ve $\lambda$ parametrelerini bulmak istiyoruz.

**Kaç denklem?** İki bilinmeyen olduğu için iki denklem gerekir.

**Hangi momentler?** Gama dağılımının ortalaması ve varyansı zaten biliniyor:

$$E[X] = \frac{\alpha}{\lambda}, \qquad \mathrm{Var}(X) = \frac{\alpha}{\lambda^2}$$

Ortalama birinci moment, varyans ikinci merkezi momenttir. Hoca, bunları bildiğimiz için bu örnekte bu iki momenti kullandığını söyledi. Bilmeseydik hesaplardık. Böylece eşitlikler şöyle olur:

$$\mu_1 = m_1, \qquad \mu'_2 = m'_2$$

**Birinci denklem:**

$$\frac{\alpha}{\lambda} = \frac{1}{n}\sum_{i=1}^{n} X_i = \frac{4 + 6 + 2}{3} = 4$$

**İkinci denklem:** Sağ tarafta örneklem ortalaması gerekir. O da az önce bulundu: $\bar{X} = 4$.

$$\frac{\alpha}{\lambda^2} = \frac{1}{n}\sum_{i=1}^{n}\left(X_i - \bar{X}\right)^2 = \frac{(4-4)^2 + (6-4)^2 + (2-4)^2}{3} = \frac{0 + 4 + 4}{3} = \frac{8}{3}$$

**Çözüm:** Elimizde iki denklem var:

$$\frac{\alpha}{\lambda} = 4, \qquad \frac{\alpha}{\lambda^2} = \frac{8}{3}$$

İkinci denklemde $\alpha/\lambda$ yerine 4 yazılır. Hoca, farklı yollardan gidilebileceğini, ama bu yolu seçtiğini söyledi:

$$4 \cdot \frac{1}{\lambda} = \frac{8}{3} \quad\Rightarrow\quad \hat{\lambda} = \frac{4 \cdot 3}{8} = \frac{3}{2}$$

Hoca buradan $\alpha$'nın da bulunabileceğini söyleyip devam etmedi. Birinci denklemden (ara adım eklendi):

$$\hat{\alpha} = 4\hat{\lambda} = 4 \cdot \frac{3}{2} = 6$$

> **Ders sonrası not:** Derste yapılmayan kontrol: $\hat{\alpha}/\hat{\lambda} = 6/(3/2) = 4$ ve $\hat{\alpha}/\hat{\lambda}^2 = 6/(9/4) = 8/3$ olur. Bu sonuçlar python ile hesaplandı.

### 9.2 Gama İçin Genel Formül

Sayısal örnek yapmak yerine çoğu zaman, özellikle gama ve üstel gibi dağılımlarda, genel bir formül bulmak istersiniz. Bunun için aynı iki denklem bu kez sayı koymadan yazılır:

$$\frac{\alpha}{\lambda} = \frac{1}{n}\sum_{i=1}^{n} X_i = \bar{X}, \qquad \frac{\alpha}{\lambda^2} = \frac{1}{n}\sum_{i=1}^{n}\left(X_i - \bar{X}\right)^2$$

İkinci denklemde $\alpha/\lambda$ yerine $\bar{X}$ konur:

$$\frac{\bar{X}}{\lambda} = \frac{1}{n}\sum_{i=1}^{n}\left(X_i - \bar{X}\right)^2$$

Sağ taraf neredeyse örneklem varyansıdır, yalnız önünde $\frac{1}{n-1}$ olmalıydı. Bunu elde etmek için ifade $n-1$ ile çarpılıp bölünür:

$$\frac{1}{n}\sum_{i=1}^{n}\left(X_i - \bar{X}\right)^2 = \frac{n-1}{n}\cdot\underbrace{\frac{1}{n-1}\sum_{i=1}^{n}\left(X_i - \bar{X}\right)^2}_{s^2} = \frac{n-1}{n}\,s^2$$

Burada $s$ örneklem standart sapması, $s^2$ örneklem varyansıdır. Şimdi $\lambda$ bir tarafa, diğerleri öbür tarafa alınır:

$$\hat{\lambda} = \frac{n}{n-1}\cdot\frac{\bar{X}}{s^2}$$

Bu formülün güzelliği şudur: Artık her gama verisi için aynı formülü kullanabilirsiniz, hesabı baştan yapmanız gerekmez.

$\hat{\alpha}$ için de birinci denklemden $\hat{\alpha} = \hat{\lambda}\bar{X}$ yazılır (ara adım eklendi).

> **Ders sonrası not:** Derste yapılmayan kontrol: 9.1'deki veride $n = 3$, $\bar{X} = 4$, $s^2 = 8/2 = 4$'tür. Formül $\hat{\lambda} = \frac{3}{2}\cdot\frac{4}{4} = \frac{3}{2}$ verir. Bu, 9.1'deki sonuçla aynıdır ve python ile hesaplandı.

Hoca ayrıca gösterim konusunda uyardı: Bulduklarımız tahmindir, bu yüzden üzerlerine şapka koymalıyız. $\lambda$ değil $\hat{\lambda}$ yazılır. İsterseniz şapkayı denklemlerin en başından itibaren de kullanabilirsiniz.

> **Hocanın vurgusu:** Momentler yöntemi çok kolaydır. Kaç bilinmeyeniniz olduğuna bakın, o kadar denklem yazın ve çözün.

## 10. En Çok Olabilirlik Yöntemi

İkinci yöntem en çok olabilirlik yöntemidir (method of maximum likelihood). Önce olabilirliğin ne olduğunu görüp sonra onu en büyük yapan parametreleri bulacağız.

### 10.1 Kesikli Durumda Olabilirlik

Kesikli durumda olabilirlik (likelihood) $L$, verinin olasılığıdır:

$$L = P(x_1, x_2, \ldots, x_n)$$

Normalde veriler arasındaki bağımlılıkları da hesaba katmamız gerekir. Zincir kuralıyla şöyle yazılır:

$$L = P(x_1)\,P(x_2 \mid x_1)\,P(x_3 \mid x_1, x_2)\cdots$$

> **Ders sonrası not:** Altyazıda çarpanlar arasında bir yerde "plus" geçiyor; olabilirlik zincir kuralıyla bir çarpımdır, toplam değildir. Hoca da hemen ardından aynı ifadeyi "times" ile sürdürüyor.

Fakat bu örnekte böyle yazmamız gerekmez. Verinin yakın zamanda öğrendiğimiz basit rastgele örneklemeyle (simple random sampling) toplandığını varsayıyoruz. Bu yüzden veri i.i.d.'dir, yani bağımsız ve özdeş dağılmıştır (independent, identically distributed):

- $x_1, x_2, \ldots, x_n$ aynı dağılımdan gelir.
- Daha da önemlisi, birbirinden bağımsızdır.

Bağımsızlık sayesinde koşullar kalkar:

$$L = P(x_1)\,P(x_2)\,P(x_3)\cdots P(x_n) = \prod_{i=1}^{n} P(x_i)$$

Büyük çarpım simgesi toplam simgesine benzer, ama çarpma içindir. Kesikli durumda burada olasılık kütle fonksiyonları (PMF) vardır. Bu yüzden büyük $P$ kullanılır.

### 10.2 Sürekli Durumda Olabilirlik

Sürekli durumda olabilirlik de çok basittir. Verimiz için ortak yoğunluğu hesaplarız. Veriler bağımsız olduğu için bu yoğunluk, tek tek yoğunlukların çarpımıdır:

$$L = f(x_1, x_2, \ldots, x_n) = \prod_{i=1}^{n} f(x_i)$$

### 10.3 Yöntem: Bir Optimizasyon Problemi

En çok olabilirlik yöntemi, olabilirliği en büyük yapan parametreleri bulmaktır. Bu artık bir optimizasyon problemidir. Yollardan biri şudur:

1. Olabilirliğin parametreye göre türevini al ve sıfıra eşitle: $dL/d\hat{\theta} = 0$.
2. Bu denklemi çöz. Çözümler kritik değerleri verir.
3. Sınır noktalarını da kritik değer olarak ekle.
4. Kritik değerlerden hangisinin olabilirliği en büyük yaptığını bul.

### 10.4 Kritik Noktalar ve Sınırlar

Hoca $L$'nin $\hat{\theta}$'ya göre grafiğini tepeleri ve çukurlarıyla çizdi ve türevin sıfır olduğu yerleri işaretledi. Türevin sıfır olması, noktanın maksimum olduğunu göstermez:

- **Maksimum:** Bizim ilgilendiğimiz noktalar. Grafikte iki tane maksimum vardı.
- **Minimum:** Türev burada da sıfırdır, ama aradığımız şey değildir.
- **Büküm noktası (inflection point):** Türev yine sıfırdır, ama maksimum değildir.

Bir de sınır noktaları vardır. Parametreyi $a$'dan $b$'ye bir aralıkta arıyorsak $a$ ve $b$ de kritik değerdir. Çünkü sınırda türev sıfır olmayabilir, ama orada olabilirlik çok büyük bir değer alıyor olabilir. Hocanın çiziminde $a$ noktasında çok büyük bir değer vardı.

Özetle kritik noktalar iki türlüdür:

- Türevi alıp sıfıra eşitleyince bulunan çözümler.
- Sınır noktaları.

Bütün kritik noktalar bulunur ve olabilirliği en büyük yapıp yapmadıkları kontrol edilir.

<!-- BELİRSİZ: 01:40:56'da altyazıda "inflation, several points" geçiyor. "Inflection" olduğu sonraki cümleden belli; "several points" büyük olasılıkla "saddle points" (eyer noktaları) olabilir, net değil. Hocanın eğri çizimi altyazıda yalnız "here" diye geçiyor. -->

### 10.5 Logaritma Hilesi

Hocanın önemli olduğunu söylediği bir hile vardır: Olabilirliği değil, olabilirliğin logaritmasını en büyük yapın. Bunun iki gerekçesi vardır.

**Maksimumun yeri değişmez.** Hoca $L$ ve $\log L$ eğrilerini üst üste çizdi. $L$'nin maksimum olduğu noktada $\log L$ de maksimumdur. Yani aynı çözümleri bulursunuz.

**Türev kolaylaşır.** Olabilirliğin kendisinin türevi, $\prod_{i=1}^{n} P(x_i)$ gibi bir çarpımın türevidir. Çarpanları çok olan tek ve karmaşık bir ifadenin türevini almanız gerekir. Logaritma alınca çarpım toplama döner:

$$\log \prod_{i=1}^{n} P(x_i) = \sum_{i=1}^{n} \log P(x_i) = \log P(x_1) + \log P(x_2) + \cdots$$

Türev alırken her terimin türevi ayrı ayrı alınır, bu da çok daha kolaydır.

> **Hocanın vurgusu:** Olabilirliği en büyük yapmak yerine olabilirliğin logaritmasını en büyük yapın.

> **Ek bilgi (derste anlatılmadı):** Logaritma artan bir fonksiyon olduğu için büyük olasılıkla hocanın çizdiği iki eğrinin aynı noktada tepe yapmasının nedeni budur. Aşağıdaki Poisson örneğinde iki eğrinin en büyük değerini aynı $\lambda$'da aldığı python ile hesaplandı.

### 10.6 Örnek: Poisson Dağılımı

**Verilen:** İşleri basit tutmak için veri $4, 6, 4, 2$ olsun ve bu verinin Poisson dağılımından geldiğini düşünelim. Poisson dağılımının PMF'si şöyledir:

$$P(x) = \frac{e^{-\lambda}\lambda^{x}}{x!}$$

Tek parametre vardır: $\lambda$.

**Kurulum:** Log-olabilirliğin $\hat{\lambda}$'ya göre türevini alıp sıfıra eşitleyeceğiz:

$$\frac{d}{d\hat{\lambda}}\ \ln \prod_{i=1}^{n} \frac{e^{-\lambda}\lambda^{x_i}}{x_i!} = 0$$

Hoca kurulumu burada bıraktı ve çözümü alıştırma olarak dinleyiciye verdi.

<!-- BELİRSİZ: Veri altyazıda "464 to" diye geçiyor. Slayt görülmediği için 4, 6, 4, 2 mi yoksa önceki örnekteki 4, 6, 2 mi olduğu kesin değil. Aşağıdaki sonuç iki okumada da aynıdır. -->

> **Ders sonrası not:** Derste yapılmayan çözüm, kısa nottaki kontrolle aynı biçimde şöyledir (ara adımlar eklendi). Logaritma çarpımı toplama çevirir: $\ln L = -n\lambda + \left(\sum x_i\right)\ln\lambda - \sum \ln(x_i!)$. Türev alınır ve sıfıra eşitlenir: $-n + \frac{\sum x_i}{\lambda} = 0$, buradan $\hat{\lambda} = \frac{1}{n}\sum x_i = \bar{X}$. İkinci türev $-\sum x_i/\lambda^2 < 0$ olduğu için bu nokta maksimumdur. Hocanın verisinde $\hat{\lambda} = 4$ çıkar; hem $4, 6, 4, 2$ hem de $4, 6, 2$ okumasında sonuç aynıdır ve python ile hesaplandı.

## Dersin Toparlaması

Dersin ilk yarısında verinin grafikle nasıl özetleneceği tamamlandı. Histogramın şekli, veriyi üreten dağılım ailesi ve karışım olup olmadığı hakkında fikir verir. Kutu grafiği çeyrekleri, medyanı, ortalamayı ve aykırı değerleri kısaca gösterir; paralel kutu grafikleri kategoriler arasında karşılaştırma sağlar. Saçılım grafiği aynı anda ölçülen iki değişkeni, zaman grafiği ise bir büyüklüğün zamanla değişimini ve eğilimini gösterir.

İkinci yarıda 9. bölüme geçildi: Histogramla bir dağılım ailesi seçtikten sonra o ailenin parametrelerini veriden tahmin etmek. Momentler yönteminde popülasyon ve örneklem momentleri eşitlenip bilinmeyen sayısı kadar denklem çözülür. Gama örneğinde $\hat{\lambda} = 3/2$ ve $\hat{\alpha} = 6$ bulundu. En çok olabilirlik yönteminde ise i.i.d. verinin olabilirliği yazılır, logaritması alınır ve sınırlar da gözetilerek en büyük yapılır. Poisson örneği kurulup çözümü alıştırma olarak bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
