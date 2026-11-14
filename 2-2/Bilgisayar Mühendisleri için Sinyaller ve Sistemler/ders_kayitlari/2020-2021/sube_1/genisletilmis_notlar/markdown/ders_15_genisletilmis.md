# Ders 15 Genişletilmiş Notu: Ters z-Dönüşümü, Tek Taraflı Dönüşüm ve Başlangıç Koşulları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. z-Dönüşümü Tekrarı ve Yakınsaklık Bölgesi
- 2. Ters z-Dönüşümünün Tanımı ve Pratik Yolu
- 3. Kısmi Kesirler: $X(z)/z$ Yöntemi
- 4. z-Dönüşümüyle Konvolüsyon
- 5. Kapsamlı Örnek: Bir IIR Sistemin Çözümlenmesi
- 6. Gecikme İçeren İfadelerin Ters Dönüşümü
- 7. Tek Taraflı Dönüşüm ve Başlangıç Koşulları
- 8. Blok Diyagramdan Sistem Fonksiyonuna
- 9. Kutup-Sıfır Diyagramı Çizen Fonksiyonlar
- 10. FIR Filtreyi Dizi Üzerinde Gezdirmek

## 1. z-Dönüşümü Tekrarı ve Yakınsaklık Bölgesi

Hoca, z-dönüşümüyle ilgili kalan kısımları bitirip dönemi kapatacaklarını söyleyerek derse başladı. İlk uyarısı yakınsaklık bölgesi (ROC, region of convergence) üzerineydi.

> **Hocanın vurgusu:** Yakınsaklık bölgesiyle ilgili şartın farkında olun. Gelen soru hem normal dönüşüm hem ters dönüşüm olduğunda bu şart sizi yanıltabiliyor.

### 1.1 Yakınsaklık Şartı Nereden Gelir?

z-dönüşümünün tanımı şudur:

$$X(z)=\sum_{n=-\infty}^{\infty} x[n]\,z^{-n}$$

Bu toplamın değerini etkileyen şeylerden biri toplamın sınırlarıdır. Sinyallerimiz genelde sağ taraflı ya da sol taraflı olur, yani işarette $u[n]$ ya da $u[-n-1]$ gibi bir çarpan bulunur ve bu çarpan toplamın sınırlarını değiştirir. Örneğin $x[n]=a^n u[n]$ için toplam şuna dönüşür:

$$X(z)=\sum_{n=0}^{\infty}\left(a z^{-1}\right)^n$$

Bu toplamın sonsuzdan küçük olması gerekir. $n$ yerine sırayla $0,1,2,\dots$ yazıldığını düşünelim. Hocanın örneğiyle $az^{-1}$ çarpanı $5$ olsaydı, $n$ arttıkça terimler üstel bir fonksiyon gibi davranır ve toplam sonsuza giderdi. Demek ki ıraksama olmaması, yakınsama olması için $az^{-1}$ çarpanının büyüklüğü $1$'in altında kalmalıdır. Yakınsaklık bölgesi bu şarttan doğru biçimde bulunur.

### 1.2 Temel Dönüşüm Çiftleri

Hoca, sık kullanılan çiftleri tahtada yeniden yazdı. Birim darbeyle başladı: $\delta[n-5]$'in dönüşümü $z^{-5}$'tir, çünkü işaret 5 birim ötelenmiştir. $\delta[n+5]$ olsaydı dönüşüm $z^{5}$ olurdu. Bu tür işaretler polinom gibi düşünülebildiği için kolaydır.

<!-- BELİRSİZ: Hocanın sorduğu işaret slaytta yazılı, altyazıda yalnız "z-d-5" ve "artı 5 olsaydı" diye geçiyor. δ[n-5] ve δ[n+5] biçimi bu anlatımdan ve kısa nottan kuruldu. -->

Birim basamak için durum daha ilginçtir:

$$u[n]\;\longleftrightarrow\;\frac{1}{1-z^{-1}}=\frac{z}{z-1},\qquad |z|>1$$

$$-u[-n-1]\;\longleftrightarrow\;\frac{1}{1-z^{-1}}=\frac{z}{z-1},\qquad |z|<1$$

Hoca bunu "işin ilginç ve kötü tarafı" diye niteledi: Her iki işaretin cebirsel ifadesi aynıdır, soruyu zorlaştıran da budur. İkisini ayıran tek şey yakınsaklık bölgesidir. Aynı durum üstel işaret için de geçerlidir:

$$a^n u[n]\;\longleftrightarrow\;\frac{1}{1-az^{-1}}=\frac{z}{z-a},\qquad |z|>|a|$$

$$-a^n u[-n-1]\;\longleftrightarrow\;\frac{1}{1-az^{-1}}=\frac{z}{z-a},\qquad |z|<|a|$$

İkinci biçim, birinci biçimin payı ve paydası $z$ ile çarpılarak elde edilir.

### 1.3 $n$ ile Çarpma Özelliği

$n\,a^n$ biçimindeki işaretler çok kullanılır. Toplam uzun uzun açılarak da bulunabilir, ama z-dönüşümü özelliklerinden bulmak daha kolaydır. Sonuç hazır olarak şöyledir:

$$n a^n u[n]\;\longleftrightarrow\;\frac{az^{-1}}{\left(1-az^{-1}\right)^2}=\frac{az}{(z-a)^2},\qquad |z|>|a|$$

Sağdaki biçim, paydadaki $\left(1-\frac{a}{z}\right)^2$ ifadesinin $\frac{(z-a)^2}{z^2}$ olarak açılıp $z^2$'nin yukarıya yansıtılmasıyla çıkar.

Bu, daha genel bir özelliğin kısa yoludur (multiplication by $n$). $x[n]$'in dönüşümü $X(z)$ elimizdeyse, $n\,x[n]$'in dönüşümünü ayrıca hesaplamaya gerek yoktur:

$$n\,x[n]\;\longleftrightarrow\;-z\,\frac{dX(z)}{dz}$$

Yani z düzleminde bir kez türev alınır ve $-z$ ile çarpılır. Hoca bunu $a^n u[n]$ üzerinde adım adım gösterdi. Türev için pay ve paydanın türevi kuralı kullanılır: payın türevi $1$, paydanın türevi $1$'dir.

$$\frac{d}{dz}\left(\frac{z}{z-a}\right)=\frac{1\cdot(z-a)-1\cdot z}{(z-a)^2}=\frac{-a}{(z-a)^2}$$

$z$'ler birbirini götürür ve payda $-a$ kalır. Sonuç $-z$ ile çarpılır:

$$-z\cdot\frac{-a}{(z-a)^2}=\frac{az}{(z-a)^2}$$

Bu sonuç ters dönüşümde de çok kullanılır. Bir ifadede payda $z-a$ biçiminde ama kareliyse, $a^n$ benzeri bir işaretin $n$ ile çarpılmış olduğunu görürüz. Hoca, paydada küp varsa bir derece daha türev alınacağını, bunun da $n^2$ ile çarpım anlamına geldiğini ekledi.

> **Ders sonrası not:** Paydadaki küp $n^2$ çarpanına işaret eder, ama pay yalnız $z$ değildir. Özellik bir kez daha uygulanınca $n^2a^nu[n]\leftrightarrow\dfrac{az(z+a)}{(z-a)^3}$, $|z|>|a|$ çıkar. Bu çift sayısal olarak doğrulandı.

## 2. Ters z-Dönüşümünün Tanımı ve Pratik Yolu

Ters dönüşümün tanımı bir kontür integralidir:

$$x[n]=\frac{1}{2\pi j}\oint_C X(z)\,z^{n-1}\,dz$$

Hoca, integralin içinde $z^{n-1}$ ve $dz$ bulunduğuna dikkat çekti: İntegral bittikten sonra dışarıda $n$'e bağlı olarak değişen bir ifade kalır. Bu, integral dönüşümü mantığıdır. Ancak kontür integralini çözmek uzun iştir ve kompleks değişkenli fonksiyonlar bilgisi gerektirir; bu konu için önceden ayrı dersler vardı. "Matematikçi olsaydık" diye başlayan bu anlatımın sonunda hoca bizim için kolay olan yolu söyledi: z-dönüşüm tablolarını, az önceki temel çiftleri ve z-dönüşümünün temel özelliklerini kullanmak.

> **Ek bilgi (derste anlatılmadı):** Tanımdaki $C$, yakınsaklık bölgesinin içinde kalan ve başlangıç noktasını çevreleyen, saat yönünün tersine dolaşılan kapalı bir eğridir. Bu yüzden aynı $X(z)$ için farklı ROC seçimi farklı kontür ve farklı $x[n]$ verir.

Pratikte en işe yarayan araç kısmi kesirlere, yani basit kesirlere açılımdır. Hoca, Laplace dönüşümünde gösterilen açılım kurallarının aynısının burada da geçerli olduğunu hatırlattı.

## 3. Kısmi Kesirler: $X(z)/z$ Yöntemi

### 3.1 Örnek 1: İki Basit Kutup, Sol Taraflı Çözüm

**Verilen:**

$$X(z)=\frac{z}{2z^2-3z+1},\qquad |z|<\frac12$$

<!-- BELİRSİZ: Altyazıda ifadenin başında "1, 3, z bölü" geçiyor. Ara sonuçlar X(z)=z/(2z²-3z+1) ile tutuyor, bu yüzden bu biçim alındı. -->

Önce payda çarpanlarına ayrılır:

$$X(z)=\frac{z}{2(z-1)\left(z-\frac12\right)}$$

Burada akla ilk gelen, katsayıları bulup doğrudan kısmi kesir yazmaktır. Fakat payda $z$ vardır ve böyle bir kural görmedik. Tablodaki biçimler paydası $z-a$ olan ve payında $z$ bulunan kesirlerdir; önünde katsayı olabilir, ama $\frac{c}{z-a}$ biçiminde bir çift yoktur. Hoca, geçen sene öğrencilerin farklı yollar denediğini, ama en kısa yolun şu işlem olduğunu söyledi: İfadeyi $X(z)/z$ biçiminde yazmak.

$$\frac{X(z)}{z}=\frac{1}{2(z-1)\left(z-\frac12\right)}=\frac{c_1}{z-1}+\frac{c_2}{z-\frac12}$$

Paydalar birinci dereceden olduğu için paylar sabit sayı alınır. Paydadaki $2$, $c_1$ ve $c_2$'nin içinde kalabilir. Payda eşitlemeye gerek kalmadan, her katsayı ilgili kutup yerine yazılarak bulunur:

$$c_1=\left.\frac{1}{2\left(z-\frac12\right)}\right|_{z=1}=\frac{1}{2\cdot\frac12}=1$$

$$c_2=\left.\frac{1}{2(z-1)}\right|_{z=\frac12}=\frac{1}{2\cdot\left(-\frac12\right)}=-1$$

Sonra $z$ yerine geri gönderilir:

$$X(z)=\frac{z}{z-1}-\frac{z}{z-\frac12}$$

Hoca bu işlemin gerekçesini şöyle özetledi: $z$'ye bağlı terim olmadan eşitleme yapmak, sonuçta zaman ötelemesi getirir ve ekstra işlem gerektirir. $z$ payda bırakılınca bu ötelemeden kaçınılır.

Şimdi yakınsaklık bölgesine bakılır. Hoca, bu şartın ders yaparken kolay unutulduğunu söyledi. $|z|<\frac12$ şartı, işaretin sol taraflı olduğunu gösterir. Dolayısıyla tablonun sol taraflı satırları kullanılır:

- $\dfrac{z}{z-1}$ terimi: $-u[-n-1]$.
- $-\dfrac{z}{z-\frac12}$ terimi: Sol taraflı çiftte kendiliğinden bir eksi gelir. Terimin önündeki eksiyle birleşince artı olur: $+\left(\frac12\right)^n u[-n-1]$.

**Sonuç:**

$$x[n]=-u[-n-1]+\left(\frac12\right)^n u[-n-1]$$

Hoca, benzer soruyu $|z|>\frac12$ şartıyla da çözmeyi önerdi.

> **Ders sonrası not:** Kutuplar $\frac12$ ve $1$ olduğu için $|z|>\frac12$ tek başına bir ROC değildir, çünkü ROC kutup içeremez. İki ayrı durum vardır. $\frac12<|z|<1$ için $x[n]=-u[-n-1]-\left(\frac12\right)^n u[n]$, $|z|>1$ için $x[n]=\left(1-\left(\frac12\right)^n\right)u[n]$ çıkar. Üç ROC için de sonuçlar toplam alınarak sayısal olarak doğrulandı.

### 3.2 Örnek 2: Katlı Kutup, Sağ Taraflı Çözüm

**Verilen:**

$$X(z)=\frac{z}{(z-1)(z-2)^2},\qquad |z|>2$$

Hoca önce paydaya fazladan bir $z$ yazdı, sonra bunun yanlış olduğunu fark edip sildi. Payda $z$ olduğu için aynı yol izlenir, çünkü tablodaki kurallara benzetmek gerekir:

$$\frac{X(z)}{z}=\frac{1}{(z-1)(z-2)^2}=\frac{c_1}{z-1}+\frac{c_2}{z-2}+\frac{c_3}{(z-2)^2}$$

İkinci dereceden çarpan olduğu için hem $z-2$ hem $(z-2)^2$ paydalı terim yazılır. Payda eşitlenir:

$$1=c_1(z-2)^2+c_2(z-2)(z-1)+c_3(z-1)$$

- $z=1$ verilirse diğer terimler gider: $c_1(1-2)^2=1$, yani $c_1=1$.
- $z=2$ verilirse: $c_3(2-1)=1$, yani $c_3=1$.
- $c_2$ için hoca önce $1$ dedi, sonra çözümün ortasında "şurasını eksi bir bulacağız" diyerek $c_2=-1$ olarak düzeltti. $z^2$ katsayılarını eşitlemek bunu verir: $c_1+c_2=0$, yani $c_2=-1$ (ara adım eklendi).

$z$ yerine geri gönderilince:

$$X(z)=\frac{z}{z-1}-\frac{z}{z-2}+\frac{z}{(z-2)^2}$$

$|z|>2$, en büyük kutbun dışı demektir. Kutuptan büyük olan taraf sağ taraflıdır, bu yüzden bütün terimlerde $u[n]$ gelir.

**Soru:** $\dfrac{z}{z-1}$ neyin ters dönüşümüdür, $u[n-1]$ mi? **Cevap:** Hayır, $n-1$ olmaz. Sağ taraflıyken bu doğrudan $u[n]$'dir; eksili biçim sol taraflı durumda çıkıyordu.

İkinci terim $z/(z-a)$ biçimindedir, $a=2$ olduğundan $2^n u[n]$ verir. Üçüncü terimde paydada kare vardır, yani bir $n$ çarpanı gelir. Hoca önce $n2^n$ yazdı, sonra yanlışlığı fark edip türevi yeniden aldı:

$$\frac{d}{dz}\left(\frac{z}{z-2}\right)=\frac{-2}{(z-2)^2},\qquad -z\cdot\frac{-2}{(z-2)^2}=\frac{2z}{(z-2)^2}$$

Yani $n2^n u[n]$'in dönüşümü $\dfrac{2z}{(z-2)^2}$'dir. Elimizdeki ifadede paydaki $2$ yoktur, dolayısıyla sonuç $\frac12$ ile çarpılır:

$$\frac{z}{(z-2)^2}\;\longleftrightarrow\;n\,2^{n-1}u[n]$$

**Sonuç:**

$$x[n]=\left(1-2^n+n\,2^{n-1}\right)u[n]$$

> **Ders sonrası not:** Sonuç sayısal olarak doğrulandı. İlk değerler $x[0],x[1],\dots$ için $0,0,1,5,17,49,129,321$'dir.

### 3.3 Çalışma Sorusu

Hoca, üzerinde uğraşmamız için şu ifadeyi bıraktı:

$$X(z)=\frac{2+z^{-2}+3z^{-4}}{z^2+4z+3}$$

Birazcık cebirsel düzenlemeyle bilinen bir forma getirmek gerektiğini, sonrasının çok kolay olduğunu söyledi. Ayrıca bir kitapta bununla ilgili çok örnek olduğunu belirtti.

<!-- BELİRSİZ: Soru tahtada yazılı. Altyazıda pay "2 artı z üzeri eksi 2, ... z üzeri eksi 2 artı 3 çarpı z üzeri eksi 4" diye araya başka söz girerek okunuyor. z⁻² teriminin bir kez yazıldığı kabul edildi, bu kısa notla aynı. ROC verilmedi. Kitap adı altyazıda "şans kitabı" diye bozuk geçiyor. -->

> **Ek bilgi (derste anlatılmadı):** Hoca çözümü vermedi; sağ taraflı kabul edilirse pay ve payda $z^{-2}$ ile çarpılarak $X(z)=\left(2z^{-2}+z^{-4}+3z^{-6}\right)G(z)$ yazılabilir. Burada $G(z)=\dfrac{1}{(1+z^{-1})(1+3z^{-1})}$ ve $g[n]=\left(-\frac12(-1)^n+\frac32(-3)^n\right)u[n]$'dir. Sonuç $x[n]=2g[n-2]+g[n-4]+3g[n-6]$ olur. Sayısal olarak doğrulandı; ilk değerler $0,0,2,-8,27,-84,\dots$ şeklindedir.

## 4. z-Dönüşümüyle Konvolüsyon

Hoca, sistem fonksiyonunun amacını hatırlattı: Ayrık zamanlı sistemleri z-dönüşümü formatına getirince konvolüsyon ve diğer işler kolaylaşır. En basit örnek olarak şunu aldı, iki dizi de $n=0$'dan başlıyor:

$$x[n]=\{1,1,1\},\qquad h[n]=\{1,1\}$$

Önce darbelerle yazılır:

$$x[n]=\delta[n]+\delta[n-1]+\delta[n-2],\qquad h[n]=\delta[n]+\delta[n-1]$$

z-dönüşümü doğrudan polinom gibi yazılır:

$$X(z)=1+z^{-1}+z^{-2},\qquad H(z)=1+z^{-1}$$

$x[n]*h[n]$ konvolüsyonu, bu iki polinomun çarpımına karşılık gelir. Terimler karşılıklı çarpılır:

$$\left(1+z^{-1}+z^{-2}\right)\left(1+z^{-1}\right)=1+z^{-1}+z^{-1}+z^{-2}+z^{-2}+z^{-3}$$

Bu yöntemle sonucun sınırları da kolay görülür: En büyük kuvvet $z^0$, en küçük kuvvet $z^{-3}$ olduğu için işaret $n=0$'dan başlayıp $n=3$'e kadar gider. Aynı terimler toplanır:

$$Y(z)=1+2z^{-1}+2z^{-2}+z^{-3}$$

Ters dönüşüm alınır:

$$y[n]=\delta[n]+2\delta[n-1]+2\delta[n-2]+\delta[n-3]$$

Sinyaller bu şekilde dizi olarak verilirse iş kolaydır. Bir bağıntı şeklinde verilirse doğrudan cebirsel işlem yapılır. Hoca bunu bir sonraki kapsamlı örnekle gösterdi.

## 5. Kapsamlı Örnek: Bir IIR Sistemin Çözümlenmesi

Hoca burada kayıttan dinleneceğini düşünerek olabildiğince fazla örnek çözdüğünü, anlaşılmayan yerde durdurulmasını söyledi. Sistem şudur:

$$y[n]-\frac34 y[n-1]+\frac18 y[n-2]=x[n]$$

<!-- BELİRSİZ: Altyazıda sistem "doğru tanılı" diye tanımlanıyor. Bozuk bir ifade; soruda nedensellik ayrıca belirtiliyor. Denklem altyazıda eksik okunuyor, katsayılar 00:35'teki dönüşüm adımından alındı. -->

### 5.1 FIR mi, IIR mi?

Hoca önce bunun hangi filtre türüne benzediğini sordu. Denklemin görüntüsünden söylenebilir: FIR filtreler yalnız $x$'in farklı zamanlardaki değerlerine bağlıdır, IIR filtreler ise $y$'nin farklı zamanlardaki değerlerine de bağlıdır. Burada $y[n-1]$ ve $y[n-2]$ olduğu için bu bir IIR filtredir.

### 5.2 Sistem Fonksiyonu

İlk madde sistem fonksiyonunu bulmaktır (find system function). Bu, sistem bağıntısının z-dönüşümü demektir. $y[n-1]$'in dönüşümü $z^{-1}Y(z)$, $y[n-2]$'nin dönüşümü $z^{-2}Y(z)$'dir:

$$Y(z)-\frac34 z^{-1}Y(z)+\frac18 z^{-2}Y(z)=X(z)$$

$Y(z)$ paranteze alınır ve bulmamız gereken $Y(z)$ ile $X(z)$ arasındaki oran yazılır. Bu oranın özel adı $H(z)$'dir:

$$H(z)=\frac{Y(z)}{X(z)}=\frac{1}{1-\frac34 z^{-1}+\frac18 z^{-2}}$$

İki taraf $z^2$ ile çarpılırsa pozitif kuvvetli biçim elde edilir. İkisi de bu sistemin fonksiyonudur:

$$H(z)=\frac{z^2}{z^2-\frac34 z+\frac18}$$

### 5.3 Kutuplar ve Sıfırlar

Kutup ve sıfırları bulmak için payda çarpanlarına ayrılır veya sıfıra eşitlenir. Çarpımı $\frac18$, toplamı $\frac34$ olan iki sayı $\frac12$ ve $\frac14$'tür. Hoca önce $z-\frac34$ yazdı, sonra düzeltti:

$$H(z)=\frac{z^2}{\left(z-\frac12\right)\left(z-\frac14\right)}$$

Kutuplar $p_1=\frac12$ ve $p_2=\frac14$'tür. Sıfır da vardır: Pay $z^2$ olduğu için $z=0$'da sıfır görülür. $z^{-1}$'li biçimde bu sıfır görünmeyebilir, pozitif kuvvetli biçime geçince görünür. Bu yüzden bir biçimden diğerine geçmek bazen faydalıdır.

> **Ders sonrası not:** Hoca "bir sıfır" dedi. Pay $z^2$ olduğu için $z=0$'daki sıfır çift katlıdır.

### 5.4 Dürtü Tepkisi

Sonraki madde sistemin dürtü tepkisidir (impulse response). Sembolü $h[n]$'dir. $H(z)$ elimizdeyken $h[n]$ ters z-dönüşümüyle bulunur. Aynı işlem uygulanır, $z$'nin birisi aşağıya alınır:

$$\frac{H(z)}{z}=\frac{z}{\left(z-\frac12\right)\left(z-\frac14\right)}=\frac{A}{z-\frac12}+\frac{B}{z-\frac14}$$

Hoca bu kez ikinci paydayı yanlış yazdı, bir öğrenci $\frac14$ olması gerektiğini söyledi. $z^2$ bırakılsaydı işe yaramazdı, çünkü $z^2$ bölü birinci derece gibi bir çift yoktur. Bu yüzden $z$ saklanır, $A$ ve $B$ sabit bulunur, $z$ geri gönderilir.

$z=\frac12$ yazılırsa $A=\dfrac{\frac12}{\frac12-\frac14}=2$, $z=\frac14$ yazılırsa $B=\dfrac{\frac14}{\frac14-\frac12}=-1$ bulunur. Böylece:

$$H(z)=2\,\frac{z}{z-\frac12}-\frac{z}{z-\frac14}$$

Yakınsaklık bölgesine bakılır. Soru sistemin nedensel olduğunu söylüyor ve buradan çıkarım yapılır.

**Soru:** Nedensellik ne anlama geliyordu? **Cevap:** Sıfırdan büyük değerler için tanımlı olması, yani sistemin içinde $u[n]$'ler bulunması. Sistem nedenselse sağ taraflıdır.

İki kutup olduğuna göre sağ taraflı işarette ROC büyük kutbun dışında kalır:

$$|z|>\frac12$$

$\dfrac{z}{z-\frac12}$, $\left(\frac12\right)^n u[n]$'nin; $\dfrac{z}{z-\frac14}$ ise $\left(\frac14\right)^n u[n]$'nin dönüşümüdür. Önlerindeki katsayılar yalnızca çarpandır:

$$h[n]=\left(2\left(\frac12\right)^n-\left(\frac14\right)^n\right)u[n]$$

> **Ders sonrası not:** Hoca sonucu okurken ikinci terimi "eksi $\frac14$ çarpı $\left(\frac14\right)^n$" dedi. $B=-1$ olduğu için doğrusu $-\left(\frac14\right)^n$'dir. Bu sonuç, fark denklemi özyinelemeyle çalıştırılarak doğrulandı.

### 5.5 Katsayı mı, $n$ Çarpanı mı?

Burada bir öğrenci soru sordu.

**Soru:** Yukarıda $z$ varken bunu yapabiliyor muyuz? $n$ ile çarpım olmayacak mıydı? **Cevap:** Paydaları eşitleyince $z$'li terim gelmediğinde sayılar doğrudan bulunabiliyor. $z^2$'li terim olduğunda ise bir birim gecikme de işin içine girer ve sonuçlar karmaşıklaşır. Bu yüzden $z$'nin birini ayırıp saklıyoruz, sonra geri getiriyoruz. Çünkü elimizde $\dfrac{2}{z-\frac12}$ diye bir kural yok; kesirde $z$'li bir şey bulunması gerekiyor.

**Soru:** En sondaki $\dfrac{2z}{z-\frac12}$ ifadesinin dönüşümü $n\,a^n u[n]$ değil miydi? **Cevap:** Hayır. Buradaki $2$ doğrudan bir genlik gibi katsayıdır ve dışarı alınır. Sen paydanın kareli olduğu durumla karıştırdın. $\dfrac{z}{(z-2)^2}$ olsaydı $n$ çarpanı gelirdi. Orada $n2^n$ için payda $2$ gerektiğinden, $2$ olmadığı için $\frac12$ ile çarpılmış gibi olur ve $n2^{n-1}$ yazılır.

### 5.6 Birim Basamak Tepkisi

Son madde sistemin basamak tepkisidir, yani birim basamağa (unit step) cevabı. Hoca "basamak" yerine "adım tepkisi" denildiğini de söyledi. Sisteme giriş olarak $x[n]=u[n]$ uygulanırsa sonuç ne olur? Normalde bulunan $h[n]$ ile konvolüsyon yapmak gerekirdi ve bu zor bir iştir. z-dönüşümünün faydası burada görülür:

$$Y(z)=X(z)H(z),\qquad X(z)=\frac{z}{z-1}$$

$$Y(z)=\frac{z}{z-1}\cdot\frac{z^2}{\left(z-\frac12\right)\left(z-\frac14\right)}=\frac{z^3}{(z-1)\left(z-\frac12\right)\left(z-\frac14\right)}$$

Bir $z$ aşağıya alınır:

$$\frac{Y(z)}{z}=\frac{z^2}{(z-1)\left(z-\frac12\right)\left(z-\frac14\right)}$$

Hoca katsayıları doğrudan söyledi: $\frac83$, $-2$, $\frac13$. Ara hesap şöyledir (ara adım eklendi):

- $z=1$: $\dfrac{1}{\frac12\cdot\frac34}=\dfrac83$.
- $z=\frac12$: $\dfrac{\frac14}{\left(-\frac12\right)\cdot\frac14}=-2$.
- $z=\frac14$: $\dfrac{\frac1{16}}{\left(-\frac34\right)\left(-\frac14\right)}=\dfrac13$.

$$Y(z)=\frac83\cdot\frac{z}{z-1}-2\cdot\frac{z}{z-\frac12}+\frac13\cdot\frac{z}{z-\frac14}$$

<!-- BELİRSİZ: 00:50:34'te altyazı "Y, N de biraz önce bulduk" diyor. Bağlamdan kastın h[n] olduğu anlaşılıyor. -->

$x[n]$ sağ taraflı, biraz önce bulduğumuz $h[n]$ de sağ taraflıdır, dolayısıyla sonuç da sağ taraflıdır. Hoca ikinci terimi önce $\left(\frac14\right)^n$ diye okudu, bir öğrencinin uyarısıyla $\left(\frac12\right)^n$ olarak düzeltti:

$$y[n]=\left(\frac83-2\left(\frac12\right)^n+\frac13\left(\frac14\right)^n\right)u[n]$$

Bu eşitlik, sisteme bu giriş uygulandığında sistemin davranışını gösterir. Örneğin $n=8$ anındaki çıktı sorulursa, ifadede $n$ yerine $8$ yazılır:

$$y[8]=\frac83-\frac{2}{2^8}+\frac{1}{3\cdot 4^8}=\frac{174251}{65536}\approx 2{,}65886\quad\text{(ara adım eklendi)}$$

> **Ders sonrası not:** $y[n]$ ifadesi, fark denklemi $u[n]$ girişiyle özyinelemeyle çalıştırılarak doğrulandı. İlk değerler $1;\;1{,}75;\;2{,}1875;\;2{,}421875$ şeklindedir.

## 6. Gecikme İçeren İfadelerin Ters Dönüşümü

Aradan sonra hoca, bu tür sorularda öğrencilerin sık yanıldığını söyleyerek gecikme içeren ifadelere geçti.

### 6.1 $H(z)=\dfrac{1+z^{-1}}{1-0.3z^{-1}}$

İfade iki kesrin toplamı olarak yazılabilir:

$$H(z)=\frac{1}{1-0.3z^{-1}}+\frac{z^{-1}}{1-0.3z^{-1}}$$

**Soru:** Sol taraftaki kesir neye benziyor? **Cevap (öğrenci):** $\left(\frac{3}{10}\right)^n u[n]$. **Hoca:** Evet, tek taraflı dersek doğru. Bu $\dfrac{1}{1-az^{-1}}$, yani $\dfrac{z}{z-a}$ biçimidir. Yakınsaklık bölgesine dikkat etmek gerekir.

Yandaki kesir de ona çok benzer, tek farkı yukarıdaki $z^{-1}$'dir. Payı ve paydayı $z$ ile çarparsak $\dfrac{1}{z-0.3}$ olur. Bu birinci kesirle aynı değildir, aynı olsaydı ikisini toplayıp tek kesir yazardık. Buradaki anahtar, zaman kaydırma kuralıdır:

$$x[n-k]\;\longleftrightarrow\;z^{-k}X(z)$$

Bir birim gecikme, doğrudan polinomla çarpar gibi $z^{-1}$ ile çarpmaktır. O halde ikinci kesir, birinci kesrin $z^{-1}$ ile çarpılmış halidir. Sonuç $0.3^n$ değil, bir birim geciktirilmiş halidir ve $u[n]$ de $u[n-1]$ olur:

$$h[n]=0.3^n u[n]+0.3^{\,n-1}u[n-1]$$

> **Ders sonrası not:** Altyazıda bir yerde "0.33" geçiyor. Soruda verilen ve öğrencinin okuduğu değer $0.3=\frac{3}{10}$'dur. $h[n]$ sonucu sayısal olarak doğrulandı.

**Soru:** $0.3^{n-1}$'deki eksi bir nereden geldi? **Cevap:** $x[n]$'in dönüşümü $X(z)$ ise $x[n-1]$'in dönüşümü $z^{-1}X(z)$'dir. $\dfrac{1}{1-0.3z^{-1}}$ birinci kesrin aynısıdır, başındaki $z^{-1}$ ise $n$'de bir birim geciktirme yaptırır.

Genel kuralı hoca şöyle özetledi: $\dfrac{z^{-1}}{1-az^{-1}}$ gibi bir şey görürseniz önce $a^n$'i bulun, sonra $z^{-1}$'den dolayı $a^{n-1}$ diye düşünün. $z^{-2}$ olsaydı iki birim öteleme olurdu. Soruda ROC sağ taraflı verildiyse doğrudan $u[n]$ yazılabilir; hoca bu örnekte sağ taraflı mı sol taraflı mı olduğunu belirtmediğini, soruyu yalnızca bu yolu göstermek için çözdüğünü söyledi.

### 6.2 $X(z)=\dfrac{z^{-4}}{z-1}+z^{-6}+\dfrac{z^{-3}}{z+0.5}$

Hoca bu soruyu internette bulduğunu, gördüklerimizi pekiştirdiğini söyledi. Bu ifade $H(z)$ olsaydı onu kapalı kutu içinde böyle bir işlem yapan bir sistemin fonksiyonu olarak düşünebilirdik. Üç parça ayrı ayrı ters dönüşüme tabi tutulur.

**Birinci parça:** $\dfrac{1}{z-1}$ diye bir kuralımız yoktur. $z$ ile çarpıp $\dfrac{z^{-1}}{1-z^{-1}}$ yazmak da tablodaki bir satırı doğrudan vermez. Bildiğimiz format, paydası $z-1$ olanın payında $z$ bulunmasıdır. O halde dışarıya $z^{-5}$ yazılır:

$$\frac{z^{-4}}{z-1}=z^{-5}\cdot\frac{z}{z-1}$$

$\dfrac{z}{z-1}$, $u[n]$'dir. $z^{-5}$ ile çarpmak 5 birim ötelemektir, dolayısıyla sonuç $u[n-5]$ olur. Hoca bir uyarı ekledi: "$u[n]\cdot z^{-5}$" gibi bir çarpım gerçekte yazılmaz, çünkü bir tarafı $n$'li bir tarafı $z$'li bir çarpım yoktur; bu yalnızca düşünme biçimidir.

> **Hocanın vurgusu:** Bu kuralı anlarsanız ters dönüşümlerde çok fazla sıkıntı yaşamazsınız. Önemli olan, payından paydasından oynayıp ifadeyi bilindik formata çevirmektir.

**İkinci parça:** $z^{-6}=z^{-6}\cdot 1$ bir polinomdur ve doğrudan $\delta[n-6]$'ya karşılık gelir.

**Üçüncü parça:** Birinci parçaya benzer. Paydada $z+0.5$ varsa payda $z$ gerekir, bu yüzden $z^{-4}$ dışarı alınır:

$$\frac{z^{-3}}{z+0.5}=z^{-4}\cdot\frac{z}{z-(-0.5)}$$

Burada işarete dikkat edilir. Tabloda $z/(z+a)$ diye bir satır yoktur, hep $z-a$ vardır. Demek ki buradaki $+0.5$, $-(-0.5)$'ten gelmektedir ve taban $-0.5$'tir. $z^{-4}$ de $n-4$ kuvvetini ve $u[n-4]$'ü getirir: $(-0.5)^{n-4}u[n-4]$.

> **Hocanın vurgusu:** Payda $+0.5$ varsa doğrudan $+0.5$ yazılmaz. Bu tür işaret hataları sık yapılıyor.

**Sonuç (sağ taraflı):**

$$x[n]=u[n-5]+\delta[n-6]+(-0.5)^{n-4}u[n-4]$$

> **Ders sonrası not:** Sonuç, sağ taraflı toplam alınarak sayısal olarak doğrulandı.

### 6.3 $F(z)=\dfrac{10z(z+5)}{(z-1)(z-2)(z+3)}$

Paydalar tanıdıktır, ama yukarıda iki $z$ çarpanı vardır; oysa kesirlerin payında $z$'den başkası olmamalıdır. Bu yüzden $z$'lerden biri aşağı alınıp kenara ayrılır (rezerve edilir):

$$\frac{F(z)}{z}=\frac{10(z+5)}{(z-1)(z-2)(z+3)}=\frac{A}{z-1}+\frac{B}{z-2}+\frac{C}{z+3}$$

Payda eşitlenir:

$$10(z+5)=A(z-2)(z+3)+B(z-1)(z+3)+C(z-1)(z-2)$$

- $z=2$: $5B=70$, yani $B=14$.
- $z=-3$: $(-4)(-5)C=20$, yani $C=1$.
- $z=1$: $(-1)(4)A=60$, yani $A=-15$.

Kenara ayrılan $z$ geri getirilir:

$$F(z)=-15\,\frac{z}{z-1}+14\,\frac{z}{z-2}+\frac{z}{z+3}$$

Terimler sırayla $u[n]$, $2^n u[n]$ ve $(-3)^n u[n]$ verir. Son terimde yine aynı işaret kuralı geçerlidir:

$$f[n]=\left(-15+14\cdot 2^n+(-3)^n\right)u[n]$$

> **Ders sonrası not:** Soruda ROC söylenmedi, hoca $u[n]$ kullanarak sağ taraflı çözdü. Bu durumda ROC en büyük kutbun dışı, yani $|z|>3$'tür. Sonuç sayısal olarak doğrulandı.

## 7. Tek Taraflı Dönüşüm ve Başlangıç Koşulları

### 7.1 Laplace'ta Hatırlatma

Hoca Laplace'taki türev özelliğini hatırlattı. $y(t)$'nin dönüşümü $Y(s)$ ise $y'(t)$'nin dönüşümü iki farklı şekilde yazılıyordu: $sY(s)$ veya $sY(s)-y(0)$.

**Soru:** Bu ikisinin farkı neydi? **Cevap:** Biri tek taraflı (unilateral), biri çift taraflı (bilateral). Sınıfta hangisinin hangisi olduğu kısa bir süre karıştı, sonunda şu sonuca varıldı:

$$\text{Çift taraflı: } y'(t)\leftrightarrow sY(s),\qquad \text{Tek taraflı: } y'(t)\leftrightarrow sY(s)-y(0^-)$$

Tek taraflıda neden böyle bir terim var? Hocanın örneği bir elektrik devresidir. Devreyi $t=0$ anında bir anda açarsınız, düğmeye bastığınızda sistem çalışmaya başlar. Sistem kapalıyken içinde bazı değerler bulunur. Sistem kapalıyken sistemde bulunan bu değer, $y$'nin sıfırdaki başlangıç koşulu değeridir ve dönüşümde ayrıca hesaba katılır.

### 7.2 Ayrık Zamanda Başlangıç Koşulu

Aynı fikir z-dönüşümünde uygulanır. Elimizde $x(t)$ yerine $x[n]$ vardır ve $x[n]$'in z-dönüşümü $X(z)$'dir. Hoca, türev almanın ayrık zamanda aslında $x[n]-x[n-1]$ almak demek olduğunu söyledi. İki taraflı dönüşümde gecikme kuralı sıkıntısız uygulanır. Fakat sistem sağ taraflı, tek taraflı çalışıyorsa başlangıç koşullarını gözetmek gerekir.

<!-- BELİRSİZ: 01:22:12 civarında altyazı "sayısal sistemlerde iki taraf gerçek hayatta bir uygulamalarda böyle bir şey olduğunu" diye yarım kalıyor. Gerçek sistemlerin belli bir anda başladığı kastediliyor gibi. -->

$n=0$ sağ tarafa dahil olduğu için başlangıç koşulu sıfırın bir önceki değeridir. Ayrık zamanda bu $n=-1$'dir. Hoca önce "$z$ ile çarpma" dedi ve ardından düzeltti: Bir birim geciktirme uygulandığı için çarpan $z^{-1}$'dir. $x[-1]$ için de önce "çıkarıyoruz" dedi, sonra "çıkarmıyoruz, ekliyoruz" diye düzeltti. Kural şudur:

$$x[n-1]\;\longleftrightarrow\;z^{-1}X(z)+x[-1]$$

$x[n-2]$ için aynı adım bir kez daha uygulanır. Yani önceki ifade $z^{-1}$ ile çarpılır, parantezden sonra $x[-2]$ eklenir:

$$x[n-2]\;\longleftrightarrow\;z^{-1}\left(z^{-1}X(z)+x[-1]\right)+x[-2]=z^{-2}X(z)+z^{-1}x[-1]+x[-2]$$

Hoca, bu kuralın uzun bir ispatı olduğunu söyledi ve göstermedi. Daha yüksek dereceli gecikmelere çok fazla ihtiyaç olmadığını ekledi.

> **Ek bilgi (derste anlatılmadı):** Tek taraflı dönüşüm $X^+(z)=\sum_{n=0}^{\infty}x[n]z^{-n}$ olarak tanımlıdır. $x[n-1]$ için toplamın $n=0$ terimi $x[-1]$'dir, kalan terimler $k=n-1$ yazılınca $z^{-1}\sum_{k=0}^{\infty}x[k]z^{-k}$ verir. Kuraldaki artı işareti buradan gelir. Bu iki kural, $n<0$ değerleri sıfırdan farklı seçilen bir dizide toplam alınarak sayısal olarak da doğrulandı.

> **Ders sonrası not:** Hoca, başlangıç koşullarının "devre dışı bırakılması" gerektiğini söyledi ve gecikmeleri "birinci, ikinci dereceden türev" diye adlandırdı. Kuralın gösterdiği gibi başlangıç koşulları atılmaz, dönüşüme eklenir. Ayrıca $x[n-1]$ ve $x[n-2]$ gecikmedir; türevin ayrık karşılığı $x[n]-x[n-1]$ farkıdır, ikinci türevin karşılığı $x[n]-2x[n-1]+x[n-2]$'dir.

Peki bu nerede kullanılır? Bir sistem üzerinde analiz yapıp sistem fonksiyonunu elde edeceksek ve fark denklemi tek taraflı verilmişse başlangıç koşullarını dikkate almak gerekir.

> **Hocanın vurgusu:** Size bir başlangıç koşulu veriliyorsa bu kuralı işletmeniz gerekir.

### 7.3 Örnek: Bir Başlangıç Koşullu Fark Denklemi

**Verilen:**

$$y[n]-\frac12 y[n-1]=x[n],\qquad x[n]=\left(\frac13\right)^n u[n],\qquad y[-1]=1$$

Giriş için:

$$X(z)=\frac{z}{z-\frac13},\qquad |z|>\frac13$$

Denklemin dönüşümü alınır. $y[n-1]$ terimine başlangıç koşulu dahil edilir, dışarıdaki $\frac12$ iki terimi de etkiler:

$$Y(z)-\frac12\left(z^{-1}Y(z)+y[-1]\right)=X(z)$$

$y[-1]=1$ yazılır, $Y(z)$ bir tarafa toplanır:

$$Y(z)\left(1-\frac12 z^{-1}\right)=\frac12+X(z)\quad\text{(ara adım eklendi)}$$

Hoca dört işlemi hızlıca yapıp şu sonucu yazdı:

$$Y(z)=\frac12\cdot\frac{z}{z-\frac12}+\frac{z^2}{\left(z-\frac12\right)\left(z-\frac13\right)}$$

İkinci terim basit kesirlere açılır. Hoca bu adımları çalışmak için bize bıraktı (ara adım eklendi):

$$\frac{z}{\left(z-\frac12\right)\left(z-\frac13\right)}=\frac{3}{z-\frac12}-\frac{2}{z-\frac13}$$

$z$ geri getirilir ve aynı terimler toplanır: $\frac12+3=\frac72$.

$$Y(z)=\frac72\cdot\frac{z}{z-\frac12}-2\cdot\frac{z}{z-\frac13}$$

**Sonuç:**

$$y[n]=7\left(\frac12\right)^{n+1}-2\left(\frac13\right)^n=\frac72\left(\frac12\right)^n-2\left(\frac13\right)^n,\qquad n\ge 0$$

> **Ders sonrası not:** Hoca $7\left(\frac12\right)^{n+1}$ yazımındaki $n+1$'i "bir birim ön alma" olarak niteledi ve bunu türevle ilişkilendirdi. Bu yazım yalnızca $\frac72=7\cdot\frac12$ eşitliğinden gelir, ayrı bir öteleme yoktur. İki yazım aynıdır. Sonuç, kesirli sayılarla özyineleme yapılarak doğrulandı: $y[0]=\frac32$, $y[1]=\frac{13}{12}$, $y[2]=\frac{47}{72}$. İfade $n=-1$'de de $1$ verir, yani başlangıç koşuluyla tutarlıdır.

Hoca bu örneğin ardından şu sezgiyi tekrarladı: Fark denklemi bir anlamda türev demektir. $y[n]$'den $y[n-1]$'e geçmek, bir anlamda türev işlemi yapmaktır.

### 7.4 Çalışma Sorusu: İki Başlangıç Koşullu Denklem

$$3y[n]-4y[n-1]+y[n-2]=x[n],\qquad x[n]=\left(\frac12\right)^n,\qquad y[-1]=1,\qquad y[-2]=2$$

Hoca bu soruyu iki yoldan çözmemizi önerdi:

- **Tek taraflı çözüm:** Başlangıç koşulları dikkate alınır.
- **Çift taraflı çözüm:** Başlangıç koşulları dikkate alınmaz. Doğrudan z-dönüşümleri alınır, $h[n]$ bulunabilir, $x[n]$ yerine konup $y[n]$ çekilir.

Hocanın verdiği tek taraflı sonuç şudur:

$$y[n]=\frac32-\left(\frac12\right)^n+\frac12\left(\frac13\right)^n,\qquad n\ge -2$$

Ara adımları kurarsak (ara adım eklendi), 7.2'deki kurallarla:

$$3Y(z)-4\left(z^{-1}Y(z)+1\right)+\left(z^{-2}Y(z)+z^{-1}+2\right)=X(z)$$

$$Y(z)\left(3-4z^{-1}+z^{-2}\right)=X(z)+2-z^{-1}$$

Payda $z^2$ ile çarpılınca $3z^2-4z+1=3(z-1)\left(z-\frac13\right)$ olur. Başlangıç koşullarından gelen kısım ve girişten gelen kısım ayrı ayrı açılırsa şu ikisi çıkar:

$$\frac12+\frac16\left(\frac13\right)^n,\qquad 1-\left(\frac12\right)^n+\frac13\left(\frac13\right)^n$$

Toplamları hocanın sonucudur, çünkü $\frac12+1=\frac32$ ve $\frac16+\frac13=\frac12$'dir.

> **Ders sonrası not:** Hocanın sonucu, özyineleme ile $n=-2$'den itibaren doğrulandı. $y[-2]=2$, $y[-1]=1$, $y[0]=1$, $y[1]=\frac76$, $y[2]=\frac{47}{36}$.

> **Ek bilgi (derste anlatılmadı):** Hoca çift taraflı sonucun "biraz daha farklı" olacağını söyledi ama yazmadı. Giriş sağ taraflı ve sistem nedensel kabul edilirse, başlangıç koşulları dahil edilmeden yapılan çözüm yukarıdaki ikinci ifadedir: $y[n]=\left(1-\left(\frac12\right)^n+\frac13\left(\frac13\right)^n\right)u[n]$. Bu sonuç sıfır başlangıç koşullu özyinelemeyle doğrulandı.

## 8. Blok Diyagramdan Sistem Fonksiyonuna

Hoca bu kez denklem yerine grafiği verilmiş bir sistem gösterdi ve verilen sorularda da buna benzer bir şey olması gerektiğini söyledi. Diyagramda iki toplama noktası görünüyor. $y[n]$ bir birim gecikmeyle sisteme dahil olur, önce gecikme alınır, sonra $\frac12$ ile çarpılır ve $x[n]$ ile toplanır.

<!-- BELİRSİZ: Blok diyagram slaytta. Altyazıda iki toplama noktasından söz ediliyor, ama yalnız y[n]=½y[n-1]+x[n] ilişkisi okunuyor. -->

Gösterim şöyledir: $z^{-1}$ yazan kutu bir birim gecikmedir. $z^{+1}$ olsaydı bir birim öne alma olurdu. Buna göre fark denklemi:

$$y[n]=\frac12 y[n-1]+x[n]$$

Bu sistem için $z$-dönüşümü alınıp giriş-çıkış ilişkisi doğrudan oranlanır:

$$H(z)=\frac{Y(z)}{X(z)}=\frac{1}{1-\frac12 z^{-1}},\qquad h[n]=\left(\frac12\right)^n u[n]$$

Hoca, daha karmaşık sistemler de olduğunu, ancak baktığı haberleşme kaynaklarında da konunun bu seviyede anlatıldığını, bize de bunun yeterli olduğunu söyledi.

## 9. Kutup-Sıfır Diyagramı Çizen Fonksiyonlar

Quiz 4'ün konusu, Laplace ve z-dönüşümünde incelediğimiz sistemlerin sıfır ve kutuplarıdır. MATLAB ve Python'da bunun için hazır fonksiyonlar vardır. Hoca, MATLAB için transfer fonksiyonundan sıfır-kutba geçen `tf2zp` ile `pzmap` ve `zplane` fonksiyonlarını saydı. Python'da aynısının belki biraz değişik isimlerle bulunduğunu, başka dillerin de kullanılabileceğini söyledi.

Mantık şudur: Pay ve payda polinom olarak, yani katsayıları girdi olarak verilir; fonksiyon sıfır-kutup diyagramını çizer. Hocanın örneği:

$$\frac{s^2+3s}{(s+1)(s-2)}$$

Pay ikinci dereceden bir polinomdur, katsayıları $1$, $3$, $0$'dır. Payda açılınca o da ikinci dereceden bir polinomdur. Aynı işlem z-dönüşümü için de geçerlidir.

Grafikte görülenler polinomla uyumlu olmalıdır. Hocanın örneği $\dfrac{1}{(z-1)(z-2)}$'dir: Bunun diyagramında $1$ ve $2$ noktalarında kutup görülür; payda hiçbir şey olmadığı için sıfır görülmez. Kutup ve sıfırların diyagramdaki çarpı ve yuvarlak işaretleri doğru yerlerde olmalıdır.

> **Ders sonrası not:** Hocanın $s$ düzlemi örneğinde payda $s^2-s-2$, yani katsayılar $1,-1,-2$'dir. Numpy ile kökler alındığında sıfırlar $0$ ve $-3$, kutuplar $-1$ ve $2$ çıkar. $z$ düzlemi örneğinde de kutuplar $1$ ve $2$ çıkar.

## 10. FIR Filtreyi Dizi Üzerinde Gezdirmek

Hoca dersin sonunda FIR filtrenin zaman düzleminde nasıl çalıştığını küçük bir örnekle hatırlattı. Ayrık zamanlı sinyalde üç eleman belirlenir: $x[n-1]$, $x[n]$, $x[n+1]$. Bir filtrenin önündeki katsayılar $1,2,1$ olsun. Elimizde şu dizi bulunsun:

$$1,\;2,\;3,\;4,\;5,\;6,\;7$$

$3\times 3$'lük bu filtre diziyi gezer ve yeni dizinin değerleri bulunur. Hoca ilk üç eleman için hesabı gösterdi: $1\cdot 1+2\cdot 2+1\cdot 3=8$. Bunu $3$'e bölerek $\frac83$ yazdı. Dizinin ilk elemanının öncesi olmadığı için onun olduğu gibi bırakılabileceğini ya da eldeki elemanlarla hesap yapılabileceğini söyledi ve $\frac53$ değerini verdi.

<!-- BELİRSİZ: Kenar hesabı altyazıda "1 ile çarpıp 4, 5, 5 bölü 3" diye geçiyor. Hangi elemanın hangi katsayıyla çarpıldığı net okunmuyor. -->

> **Ders sonrası not:** Hoca toplamı $3$'e böldü. Ağırlıklı ortalamada bölen, katsayıların toplamı olan $4$'tür; böylece $\frac84=2$ çıkar ve dizi tam örtüşen konumlarda $2,3,4,5,6$ olur. Numpy ile doğrulandı. Hocanın kenar değerindeki $5=1\cdot 1+2\cdot 2$ hesabı merkez katsayıyla uyuşmaz: Merkez katsayı ilk elemana gelirse $2\cdot 1+1\cdot 2=4$ olur. Hangi normalizasyonun istendiğine bakmak gerekir.

## Dersin Toparlaması

Bu ders, z-dönüşümü konusunu ve dönemi kapattı. Temel fikir, aynı cebirsel ifadenin ROC'a göre farklı işaretlere karşılık gelmesidir: $|z|$ en büyük kutbun dışındaysa işaret sağ taraflı, en küçük kutbun içindeyse sol taraflıdır. Ters dönüşümün tanımı kontür integrali olsa da pratik yol tablo, özellikler ve kısmi kesirlerdir. Payda $z$ varken önce $X(z)/z$ açılır, sonra $z$ geri getirilir. Paydadaki kare $n$ çarpanına, dışarıdaki $z^{-k}$ ise $k$ birim gecikmeye işaret eder. Paydadaki artı işareti tabanı negatif yapar.

Aynı araçlarla bir IIR sistem baştan sona çözümlendi: fark denkleminden sistem fonksiyonu, kutup ve sıfırlar, nedensellikten ROC, dürtü tepkisi ve konvolüsyona girmeden basamak tepkisi. Son olarak başlangıç koşulu verildiğinde tek taraflı dönüşümün gecikme kuralının kullanılması gerektiği görüldü: $y[n-1]\leftrightarrow z^{-1}Y(z)+y[-1]$. Bu, dönemin son dersiydi; sonraki derse dair akademik bir bağlantı verilmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
