# Ders 11 Genişletilmiş Notu: Fourier ile LTI Sistem Analizi, Filtreler, Örnekleme ve Örtüşme, FIR Filtreler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sürekli Zamanlı Bir Sistemin Fourier Dönüşümüyle Çözümü
- 2. Ayrık Zamanlı Sistem: İki Gecikmeli Fark Denklemi
- 3. Ayrık Zamanlı Sistem: Girişte de Gecikme Olan Fark Denklemi
- 4. Frekans Düzleminin Kullanım Alanları ve RC Devresi
- 5. Periyodik Gürültünün Temizlenmesi
- 6. Filtre Türleri
- 7. Faz Kaydıran Filtre Örneği
- 8. Örnekleme Şartı, En Yüksek Frekans ve Temel Frekans
- 9. Örtüşmenin Mantığı
- 10. Analog ve Dijital İşleme, Düzgün Örnekleme
- 11. Normalize (Dijital) Frekans
- 12. Örtüşmenin Spektrumda Görülmesi
- 13. FIR Filtrelere Giriş
- 14. Kayan Ortalama Filtresi
- 15. Genel FIR Filtre ve Ağırlıklı Ortalama
- 16. Filtre Bir Konvolüsyondur
- 17. Birinci Fark (Türev) Filtresi
- 18. Blok Diyagram ve Kaskad Sistemler
- 19. FIR Filtrenin Frekans Cevabı

## 1. Sürekli Zamanlı Bir Sistemin Fourier Dönüşümüyle Çözümü

Hoca derse, Fourier dönüşümü ve Fourier serileriyle ilgili hem örnek hem de bazı yeni konular göreceklerini söyleyerek başladı. Önce sürekli zamandan, sonra ayrık zamandan birer örnek yapıldı.

### 1.1 Problem

Doğrusal ve zamanla değişmeyen (Linear Time Invariant, LTI) bir sistem şu denklemle veriliyor:

$$\frac{dy(t)}{dt}+2y(t)=x(t)$$

Girişe $x(t)=e^{-t}u(t)$ uygulanırsa sistemin nasıl bir çıkış vereceği, örneğin $t=100$ anındaki değeri isteniyor. Hoca aynı sistem için $x(t)=u(t)$ girişini alıştırma olarak bıraktı.

**Soru:** Bu sistemin sürekli mi ayrık mı olduğunu nereden anlarız? **Cevap:** Bir öğrenci denklemin $t$'ye bağlı olduğunu söyledi. Hoca bunu doğruladı ve ekledi: Denklem bir diferansiyel denklemdir, birinci dereceden türev içerir ve $n$'ye bağlı hiçbir şey yoktur.

### 1.2 Neden Fourier Dönüşümü?

Çıkışı bulmak için önce sistemi $y(t)=\dots$ biçiminde, yani giriş cinsinden yazmamız gerekir. Sonrası $x(t)$'yi yerine koymaktan ibarettir. Fakat burada $x$ ve $y$ zamana göre değişen fonksiyonlardır, dolayısıyla önümüzde bir diferansiyel denklem çözme işi vardır. Bu ders için diferansiyel denklem bilgisi varsayılmadığından Fourier dönüşümü ya da ileride görülecek Laplace dönüşümü kullanılır.

Hoca denklemin, bir sistemin davranışını gösteren bir model olduğunu vurguladı. Bu sistem bir yerin sıcaklığının kontrolü olabilir, bir haberleşme sistemi olabilir. Sistemi model haline getirince böyle bir eşitlik elde edilir, giriş ve çıkış ilişkisine dair analizler de ancak ondan sonra yapılır.

### 1.3 Türev Özelliği

$y(t)$'nin Fourier dönüşümü $Y(\omega)$'dır. Türevin dönüşümü ise tablodaki türev özelliğinden gelir:

$$\frac{dy(t)}{dt}\ \longleftrightarrow\ j\omega\,Y(\omega)$$

**Soru:** Türevin dönüşümü için $e^{j\omega}$ ile mi çarpıyorduk? **Cevap:** Hayır. Bu, zamanda kaydırmayla ilgili özelliktir: $y(t-t_0)$ için geçerlidir. Türevde $j\omega$ ile çarpılır.

Denklemin iki tarafının dönüşümü alınır:

$$j\omega\,Y(\omega)+2Y(\omega)=X(\omega)$$

Hoca bu adımın değerini şöyle anlattı: Bu dönüşüm olmasaydı diferansiyel denklemin türüne göre bir çözüm üretmek zorunda kalacaktık. Şimdi ise elimizde cebirsel bir eşitlik vardır.

### 1.4 Birim Darbe Cevabı: Sistemin Röntgeni

Bir sisteme giriş olarak birim darbe (unit impulse) uygulanınca elde edilen çıktının özel bir adı vardır. Normalde bu da bir $y$'dir, ama $h$ ile gösterilir ve sistemin birim darbe (birim dürtü) tepkisi denir. Birim darbe zamanda ötelenmiş olarak sistemin içinde sürekli karşımıza çıktığı için, hocanın benzetmesiyle bu işlem sistemin **röntgenini çekmektir**. Bu sinyalle sistemin nasıl çalıştığını test etmiş oluruz. Bu, LTI sistemlerde geçerlidir.

Frekans düzlemindeki karşılığı büyük $H$ ile gösterilir ve $H(\omega)$ çıkışın girişe oranıdır:

$$H(\omega)=\frac{Y(\omega)}{X(\omega)}$$

> **Ders sonrası not:** Hoca bu bölümde $h$'yi bir yerde "birim basamak girişine karşılık gelen çıktı" diye andı (00:12:24) ve bir yerde "girişin çıkışa oranı" dedi (00:13:27). Doğrusu: $h$, birim darbe $\delta$ girişine karşılık gelen çıktıdır ve $H$, çıkışın girişe oranıdır. Hoca kendisi de hemen önce ve sonra bu doğru ifadeleri kullandı.

Cebirle devam edelim. $Y(\omega)$ parantezine alınır, iki taraf $X(\omega)$'ya ve $(2+j\omega)$'ya bölünür:

$$Y(\omega)\,(2+j\omega)=X(\omega)\quad\Rightarrow\quad H(\omega)=\frac{Y(\omega)}{X(\omega)}=\frac{1}{2+j\omega}$$

Sistemin frekans düzlemindeki davranışı budur. Bunun ters Fourier dönüşümü alınırsa sistemin nasıl çalıştığı zaman düzleminde de bulunur. Ancak soru bunu istemiyor: Girişin dönüşümünü alıp bu sisteme uygulamamızı ve sonucu hesaplamamızı istiyor.

### 1.5 Konvolüsyon Yerine Çarpma

Zaman düzleminde bir sisteme herhangi bir $x(t)$ uygulanınca çıkış nasıl bulunuyordu?

**Soru:** Bu işlemin adı neydi? **Cevap:** Konvolüsyon. $y(t)=h(t)*x(t)$, sırası değişse de sonuç aynıdır.

Fourier dönüşümünün özelliğinden, konvolüsyonun frekans düzleminde çarpmaya dönüştüğünü biliyoruz:

$$Y(\omega)=H(\omega)\,X(\omega)$$

Elimizde $H(\omega)$ var. Geriye $x(t)$'nin karşılığı $X(\omega)$'yı bulup çarpmak, sonra ters dönüşüm almak kalıyor.

### 1.6 Girişin Fourier Dönüşümü

$$X(\omega)=\int_{-\infty}^{\infty}e^{-t}u(t)\,e^{-j\omega t}\,dt=\int_{0}^{\infty}e^{-t(1+j\omega)}\,dt$$

İntegral normalde eksi sonsuzdan artı sonsuza alınır, ama $u(t)$ yüzünden sıfırdan sonsuza çalışır ve $u(t)$ bu aralıkta 1'dir. Üstteki $t$ parantezine alınınca $1+j\omega$ çıkar. İntegral açılır:

$$X(\omega)=\left[\frac{e^{-t(1+j\omega)}}{-(1+j\omega)}\right]_{0}^{\infty}=0-\frac{1}{-(1+j\omega)}=\frac{1}{1+j\omega}$$

Sonsuz yazıldığında üstel terim sıfır olur, sıfır yazıldığında $e^0=1$ olur. Hoca bu sonucun Fourier dönüşüm tablolarında zaten bulunduğunu söyledi. Bu hesabın amacı sonucun nereden geldiğini göstermekti.

> **Hocanın vurgusu:** Bir $x(t)$ ifadesinden $X(\omega)$'yı bulabilmek gerekir. Hoca buradaki girişin kolayca başka bir işaretle değiştirilebileceğini ve yöntemin aynı kalacağını söyledi.

### 1.7 Çıkış

$$Y(\omega)=H(\omega)X(\omega)=\frac{1}{(2+j\omega)(1+j\omega)}$$

Bu çarpım, zaman düzleminde konvolüsyon yapmakla aynı şeydir. Ters dönüşümü almak için basit kesirlere ayrılır. Bu örnek basit olduğu için doğrudan yazılabilir:

$$Y(\omega)=\frac{1}{1+j\omega}-\frac{1}{2+j\omega}$$

Payda eşitlenirse payda $1$ kaldığı görülür: $(2+j\omega)-(1+j\omega)=1$ (ara adım eklendi).

Fourier dönüşümü doğrusal bir dönüşüm olduğu için ters dönüşüm terim terim alınır:

$$y(t)=\mathcal{F}^{-1}\left\{\frac{1}{1+j\omega}\right\}-\mathcal{F}^{-1}\left\{\frac{1}{2+j\omega}\right\}$$

İlk terimin karşılığını biraz önce bulduk: $e^{-t}u(t)$. Burada $u(t)$ önemlidir, çünkü dönüşümdeki ıraksama durumu yüzünden işareti yalnız sıfır-sonsuz aralığında inceliyoruz.

**Soru:** Paydada 1 yerine 2 olursa ne olur? **Cevap:** $e^{-2t}$ olur. Aynı integral $e^{-2t}u(t)$ için yazılırsa, $t$ parantezinden $2+j\omega$ çıkar ve sonuç $\frac{1}{2+j\omega}$ bulunur. Yani ters dönüşüm $e^{-2t}u(t)$'dir.

Böylece çıkış:

$$y(t)=\left(e^{-t}-e^{-2t}\right)u(t)$$

$t=100$ anındaki değer için ifadede $t$ yerine $100$ yazılır.

> **Ders sonrası not:** Hoca sonucu toparlarken "$e^{-t}$ artı $e^{-2t}$" dedi (00:23:10). Basit kesirlerdeki eksi işareti korunmalıdır, doğrusu yukarıdaki gibidir. Python ile $Y(\omega)$ integrali birkaç frekansta sayısal alınıp kapalı biçimle karşılaştırıldı, denklem ayrıca adım adım sayısal olarak çözüldü, ikisi de bu sonucu verdi. Hoca sayısal değeri okumadı: $y(100)=e^{-100}-e^{-200}\approx3.72\times10^{-44}$, yani pratikte sıfır.

### 1.8 Frekans Cevabı ve Sistem Modeli

Çıkışın girişe oranına sistemin **frekans cevabı** (frequency response) denir. Laplace dönüşümünde bu orana sistemin modeli denecektir. Çünkü özellikle kontrol sistemlerinde bir sistem tasarlanırken giriş ve çıkış ilişkisi "çıkış bölü giriş" olarak yazılır, sistem böyle modellenir ve analizler buna göre yapılır.

Hoca örneği şöyle bağladı: Diferansiyel denklemlerle hiç uğraşmadık, Fourier dönüşümünü basit bir şekilde kullandık.

## 2. Ayrık Zamanlı Sistem: İki Gecikmeli Fark Denklemi

Aynı iş ayrık zamanda da yapılır. Ayrık zamanlı bir sistemin de girişi ve çıkışı vardır. Sistem şöyle veriliyor:

$$y[n]-\frac34y[n-1]+\frac18y[n-2]=x[n]$$

İstenen, frekans cevabıdır. Sistem ayrık zamanlı olduğu için artık büyük omega, $\Omega$, kullanılır. Hoca bu gösterimin önemli olduğunu belirtti.

**Soru:** Ayrık zamanda Fourier dönüşümü integralle mi, toplamla mı alınır? Ters dönüşüm nasıl alınır? **Cevap:** Dönüşüm toplam sembolüyle, ters dönüşüm integralle alınır.

### 2.1 Terim Terim Dönüşüm

$y[n]$'nin dönüşümü tanımdan gelir: $\sum y[n]\,e^{-j\Omega n}=Y(\Omega)$.

$y[n-1]$'de $n$ düzleminde bir birimlik öteleme vardır. Türev özelliğine benzer şekilde, $Y(\Omega)$ biliniyorsa bir birim ötelenmiş işaretin dönüşümü $e^{-j\Omega}$ ile çarpılarak bulunur. Sürekli zamandaki karşılığı da $y(t-t_0)\leftrightarrow e^{-j\omega t_0}Y(\omega)$ idi. Sabit katsayı $\frac34$ dışarı çıkar.

$y[n-2]$'yi de $Y(\Omega)$ cinsinden yazmamız gerekir, çünkü tek bir bilinmeyen kalmalıdır. İki birim öteleme, $e^{-j2\Omega}$ çarpanı demektir. Bu yazım, ifadelerin türdeş olmasını sağlar. $x[n]$'nin karşılığı da $X(\Omega)$'dır. Hepsi yerine konur:

$$Y(\Omega)-\frac34Y(\Omega)e^{-j\Omega}+\frac18Y(\Omega)e^{-j2\Omega}=X(\Omega)$$

$$Y(\Omega)\left(1-\frac34e^{-j\Omega}+\frac18e^{-j2\Omega}\right)=X(\Omega)$$

$$H(\Omega)=\frac{Y(\Omega)}{X(\Omega)}=\frac{1}{1-\frac34e^{-j\Omega}+\frac18e^{-j2\Omega}}$$

Hoca, fark denklemlerini doğrudan çözmenin ayrı yöntemleri olduğunu, bunların özyinelemeli (rekürsif) algoritmalar anlatılırken kısmen görüldüğünü ve bir yerden sonra çok zorlaştığını söyledi. Fourier dönüşümüyle ise iş dört işlem mantığına iner. Yeter ki dönüşüm özellikleri iyi bilinsin. Aynı yöntem z-dönüşümünde de görülecek, orada $Y(\Omega)$ yerine $z$'li ifadeler yazılacaktır.

### 2.2 Çarpanlara ve Basit Kesirlere Ayırma

Zaman düzlemine dönmek için ters dönüşüm gerekir. Payda çarpanlarına ayrılır. Çarpanların toplamı $\frac12+\frac14=\frac34$, çarpımı $\frac12\cdot\frac14=\frac18$'dir (ara adım eklendi):

$$H(\Omega)=\frac{1}{\left(1-\frac12e^{-j\Omega}\right)\left(1-\frac14e^{-j\Omega}\right)}$$

Doğrusallık özelliğini kullanabilmek için çarpımdan kurtulmak gerekir. Basit kesirlere ayrılır:

$$H(\Omega)=\frac{2}{1-\frac12e^{-j\Omega}}-\frac{1}{1-\frac14e^{-j\Omega}}$$

Sağlaması: $2\left(1-\frac14e^{-j\Omega}\right)-\left(1-\frac12e^{-j\Omega}\right)=1$ (ara adım eklendi).

> **Hocanın vurgusu:** Basit kesirlere ayırma yöntemi Laplace dönüşümünde birkaç farklı kuralla ayrıntılı anlatılacak. Hoca bu aşamada öğrencileri ağır matematikle uğraştırmak istemediğini söyledi.

### 2.3 Birim Darbe Cevabı

**Soru:** $H(\Omega)$'nın ters dönüşümünü alınca ne buluruz? **Cevap:** $h[n]$, yani sistemin $n$ düzlemindeki davranışı.

Tablodan, $2$ sabit olarak başa gelir, $\frac{1}{1-\frac12e^{-j\Omega}}$ terimi $\left(\frac12\right)^n$, diğeri $\left(\frac14\right)^n$ verir. Sistem $n\ge0$ için tanımlı olduğundan $u[n]$ eklenir:

$$h[n]=\left[2\left(\frac12\right)^n-\left(\frac14\right)^n\right]u[n]$$

> **Ders sonrası not:** Fark denklemi Python ile doğrudan çalıştırıldı: $h=[1,\ 0.75,\ 0.4375,\ 0.2344,\ 0.1211,\dots]$. Formül ilk 30 örnekte aynı değerleri verdi. Payda çarpanları ve basit kesirler de sayısal olarak doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Tablodaki $a^nu[n]\leftrightarrow\frac{1}{1-ae^{-j\Omega}}$ çifti bir geometrik seridir: $\sum_{n=0}^{\infty}a^ne^{-j\Omega n}=\sum_{n=0}^{\infty}\left(ae^{-j\Omega}\right)^n$. Seri $|a|<1$ iken yakınsar ve toplamı bu kesirdir. Bu çift, burada kullanılan $a=\frac12$ ve $a=\frac14$ için Python ile kısmi toplam alınarak doğrulandı.

### 2.4 Bir Giriş Uygularsak

Bu sisteme örneğin $x[n]=\{1,2,3\}$ girişi uygulansın:

$$x[n]=\delta[n]+2\delta[n-1]+3\delta[n-2]$$

Bu girişi uygulamak, $y[n]$'yi hesaplamak demektir. $y[n]=h[n]*x[n]$ konvolüsyonu yapılabilir, ama iki böyle ifadenin $n$ düzleminde konvolüsyonu zor görünür. Onun yerine $x[n]$'nin $X(\Omega)$ karşılığı bulunur, $H(\Omega)$ ile çarpılır ve çarpımın ters dönüşümü alınır:

$$y[n]=\mathcal{F}^{-1}\{H(\Omega)X(\Omega)\}$$

> **Ders sonrası not:** Hoca bu örneğin sonucunu hesaplamadı, yalnız yöntemi anlattı. Konvolüsyon ve fark denklemi Python'da aynı değerleri verdi: $y=[1,\ 2.75,\ 4.9375,\ 3.3594,\ 1.9023,\dots]$.

### 2.5 Neden $u[n]$ Yazıyoruz?

**Soru:** Sıfırdan sonra çalıştığı için $u[n]$ eklendiğini nasıl anlayacağız? **Cevap:** Hoca iki gerekçe verdi.

Birincisi gerçek hayattır. Ayrık zamanlı sistemde elimizde bellek ve bilgisayar vardır. $n=-1$'inci örnek diye bir şey yoktur, sistem çalışmaya başladığında en az sıfırıncı örnek vardır. Verilen ifade sıfır ve sonrası için geçerlidir ve bunu $u[n]$ sağlar.

İkincisi yakınsaklıktır. Örneğin $2\left(\frac12\right)^nu[n]$ işaretinin dönüşümünde toplam, $u[n]$ yüzünden sıfırdan sonsuza alınır. $n$ büyüdükçe $\left(\frac12\right)^n$ küçülür, yani toplam yakınsar, ıraksamaz. Bu yüzden elde edilen dönüşüm kabul edilebilir bir sonuçtur.

## 3. Ayrık Zamanlı Sistem: Girişte de Gecikme Olan Fark Denklemi

Doğrusal ve zamanla değişmeyen bir sistem:

$$y[n]-\frac12y[n-1]=x[n]+\frac12x[n-1]$$

Üç şey isteniyor: frekans cevabı $H(\Omega)$, birim darbe cevabı $h[n]$ ve $x[n]=\cos\left(\frac{\pi}{2}n\right)$ girişine karşılık çıkış. Hoca son maddenin önemini şöyle belirtti: Sisteme her zaman birim darbe vermeyiz, gerçek sinyaller veririz.

### 3.1 Frekans Cevabı

Denklemde ne $Y(\Omega)$ ne $X(\Omega)$ görünüyor, ama Fourier dönüşümüyle elde edilirler:

$$Y(\Omega)-\frac12Y(\Omega)e^{-j\Omega}=X(\Omega)+\frac12X(\Omega)e^{-j\Omega}$$

$$Y(\Omega)\left(1-\frac12e^{-j\Omega}\right)=X(\Omega)\left(1+\frac12e^{-j\Omega}\right)$$

İki taraf $X(\Omega)$'ya ve $1-\frac12e^{-j\Omega}$'ya bölünür:

$$H(\Omega)=\frac{1+\frac12e^{-j\Omega}}{1-\frac12e^{-j\Omega}}$$

### 3.2 Birim Darbe Cevabı

Paydaki toplam açılarak basit kesirler biçimine getirilir:

$$H(\Omega)=\frac{1}{1-\frac12e^{-j\Omega}}+\frac12\cdot\frac{e^{-j\Omega}}{1-\frac12e^{-j\Omega}}$$

İlk terim, önceki örnekten bildiğimiz gibi $\left(\frac12\right)^nu[n]$'dir. İkinci terimde $\frac12$ dışarıda kalır. Geri kalan kısım, $e^{-j\Omega}$ çarpanı olmasaydı ilk terimin aynısı olurdu.

**Soru:** Bir Fourier dönüşümüne $e^{-j\Omega}$ çarpanı eklemek ne demektir? **Cevap:** Zamanda öteleme (time shift). Bir birimlik öteleme demektir, dolayısıyla $n$ yerine $n-1$ gelir ve $u[n]$ de $u[n-1]$ olur.

$$h[n]=\left(\frac12\right)^nu[n]+\frac12\left(\frac12\right)^{n-1}u[n-1]$$

### 3.3 Değerler

**Soru:** $n=0$'da sonuç $\frac12$ mi? **Cevap:** Hayır. $n=0$ iken $u[-1]=0$ olduğu için ikinci terim tamamen sıfırdır. İlk terimde $u[0]=1$ ve $\left(\frac12\right)^0=1$'dir. Sonuç $h[0]=1$'dir.

$n\ge1$ için her iki $u$ da 1'dir. Üslü sayılarda ortak parantez alınırsa:

$$h[n]=\left(\frac12\right)^n+\frac12\left(\frac12\right)^{n-1}=\left(\frac12\right)^{n-1},\qquad n\ge1$$

> **Ders sonrası not:** Fark denklemi Python ile doğrudan çalıştırıldı: $h=[1,\ 1,\ 0.5,\ 0.25,\ 0.125,\dots]$. Bu, formülle aynıdır.

### 3.4 Kosinüs Girişi

Hoca üçüncü maddeyi öğrencilere bıraktı ve yöntemi verdi: $x[n]$'nin Fourier dönüşümü alınır, $H(\Omega)$ ile çarpılır, çarpımın ters dönüşümü alınır. Hocanın verdiği sonuç:

$$y[n]=\cos\left(\frac{\pi}{2}n-2\tan^{-1}\frac12\right)$$

> **Ders sonrası not:** Giriş frekansı $\Omega=\frac{\pi}{2}$'de $e^{-j\pi/2}=-j$ olduğundan $H\left(\frac{\pi}{2}\right)=\frac{1-j/2}{1+j/2}=0.6-0.8j$ olur (ara adım eklendi). Genliği 1, fazı $-2\tan^{-1}\frac12\approx-0.927$ radyandır. Fark denklemi bu girişle Python'da çalıştırıldı, geçici kısım söndükten sonra çıkış hocanın verdiği ifadeyle aynı çıktı.

> **Ek bilgi (derste anlatılmadı):** Bir LTI sisteme $\cos(\Omega_0n)$ girerse çıkış $|H(\Omega_0)|\cos\left(\Omega_0n+\angle H(\Omega_0)\right)$ olur. Yani frekans değişmez, genlik $|H|$ ile çarpılır, faza $\angle H$ eklenir. Kosinüsün dönüşümü yalnız $\pm\Omega_0$'da dürtü içerdiğinden, çarpımda $H$'nin sadece bu iki noktadaki değeri rol oynar. Bu yüzden yukarıdaki sonuç tek bir $H$ hesabıyla bulunur.

## 4. Frekans Düzleminin Kullanım Alanları ve RC Devresi

Aradan sonra hoca slaytlara geçti. Slaytlar, az önce yapılan uygulamaların teorik tarafını anlatıyor. Fourier dönüşümü sayesinde sistemde doğrudan göremeyeceğimiz özellikler tespit edilir, zor işlemler kolay hale gelir. Bir sistemin frekans düzlemi analizinde, frekans cevabının hangi noktalarda sonsuza gittiği ve hangi noktalarda sıfırları olduğu da görülebilir. Hoca bunu, daha genel bir analiz sağladığı için Laplace dönüşümünde anlatacağını söyledi.

Her durumda mantık aynıdır. Bir sisteme $x(t)$ uygulandığında $y(t)$'yi bulmak için girişin dönüşümü ile sistemin dönüşümü kullanılır. Birim darbe cevabının Fourier dönüşümü frekans cevabıdır ve hesap çarpma ile yapılır.

### 4.1 RC Devresi

Slaytta bir direnç ve bir kapasitörden oluşan bir devre ve girişine uygulanan sinüzoidal bir işaret var. Hoca devreyi daha genel bir bakışla, bir sistem olarak ele aldı. $y(t)$'yi bulmanın iki yolu vardır:

- **Zaman düzleminde:** $h(t)$ belirlenir (girişe birim darbe uygulanarak ya da devrenin denkleminden) ve $x(t)$ ile konvolüsyon yapılır.
- **Frekans düzleminde:** Girişin ve sistemin Fourier dönüşümleri çarpılır, sonucun ters dönüşümü alınır.

> **Ders sonrası not:** Hoca burada "sonsuz uzunluklu bir birim darbe" dedi (01:05:00). Kendi verdiği ayrık tanıma göre $\delta[n]$ yalnız $n=0$'da 1, diğer yerlerde 0'dır, yani tek örnektir. Sürekli zamanda büyük olasılıkla kastedilen, sonsuz uzunluk değil, çok dar ve birim alanlı darbedir.

Devre teorisi dersi olsaydı modelin kurulmasını uzun uzun anlatacağını söyleyen hoca, yalnız bileşenleri saydı: Bir direnç vardır, kapasitör $\frac{1}{j\omega C}$ gibi davranır, sinüzoidal işaret Euler bağıntısıyla üstel biçimde yazılabilir. Bunlar gerilim bölücü ya da Thevenin ve Norton eşdeğeri gibi devre teorisi araçlarıyla bir araya getirilince devrenin modeli, yani frekans cevabı ortaya çıkar.

Bundan sonra belli bir frekanstaki karşılık kolayca bulunur: Örneğin $H(100)$ için $\omega$ yerine $100$ yazılır. Ters Fourier dönüşümü alınırsa sistemin zaman düzlemindeki davranışı elde edilir.

<!-- BELİRSİZ: Slayttaki devrenin çıkışının nereden alındığı, H(omega) ifadesi, H(100) değeri ve giriş işareti altyazıda okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Çıkış kapasitör üzerinden alınıyorsa gerilim bölücüden $H(\omega)=\frac{1/(j\omega C)}{R+1/(j\omega C)}=\frac{1}{1+j\omega RC}$ bulunur. Bu ifade kaynakta geçmiyor; slayttaki devrenin de büyük olasılıkla bu standart biçim olduğu varsayılmıştır.

Hoca bu bakışın genel olduğunu ekledi. Gerçek sistemler çoğunlukla tek bir değişkene, yalnız $t$'ye bağlı değildir. Basınç, sıcaklık, nem gibi başka etmenler de vardır. O zaman değişken sayısı artar, ama yapılacak iş yine aynıdır: Parametrelerden bir model ve denklem kurulur, girişin etkisi bu denklemle incelenir.

Hoca, slayttaki periyodik sinyallerin özelliklerini Fourier serilerinde zaten gördükleri için geçti.

> **Hocanın vurgusu:** Slaytlardaki aperiyodik sinyal kısmından sorumlu değilsiniz.

## 5. Periyodik Gürültünün Temizlenmesi

Yaptığımız işlemler bir çeşit filtre olarak kullanılabilir. Bir işaretin istenen (good) ve istenmeyen (bad) kısımları vardır. Hoca bunu bir görüntü örneğiyle gösterdi (periodic noise removal):

Orijinal bir görüntüye periyodik bir gürültü eklenmiştir ve amaç orijinal görüntüye geri dönmektir. Bunun farklı teknikleri vardır. Burada görüntünün Fourier dönüşümü alınır. Dönüşümde gürültünün frekanslarında birkaç tepe (spike) görülür. Bu tepeler yok edilince, yani o frekansların genliği sıfır yapılınca, ters dönüşümden gürültüsü büyük ölçüde temizlenmiş görüntü elde edilir. Tepedeki beyaz noktalar sıfırlanınca ortada tek bir beyaz nokta kalır. Hoca gürültüyü tam yok etmenin her zaman mümkün olmadığını, daha iyi filtreler gerektiğini de ekledi.

Neden frekans düzlemi? Çünkü bir işaretin içindeki istenmeyen frekans bileşenini zaman düzleminde ya da $n$ düzleminde her zaman bulamayız. Frekans düzleminde ise düşük frekanslarda yüksek genlikler dururken, gürültü ayrı bir bileşen olarak görünür. Zaman düzleminde bunu konvolüsyonla yok etmek çok zordur, frekans düzleminde ise oldukça kolaydır. Yani sistemimiz öyle bir filtre olmalıdır ki, $x(t)$ girişinden istenen kısmı bırakıp diğerini yok etsin.

## 6. Filtre Türleri

Normal bir işaret genellikle $-\omega$ ile $+\omega$ arasında frekanslardan oluşur. Bunun dışındakiler yüksek frekanslardır ve düşük genlikli olsalar da etki gösterirler. Genelde bunlar gürültüdür.

Amaç bu aralığın alınıp diğerlerinin yok edilmesiyse, frekans düzleminde şöyle bir filtre kurulur: Aralığın içinde değeri 1, geri kalan yerlerde 0. Bu filtre ile işaretin dönüşümü çarpılınca yüksek frekans bileşenleri yok olur.

- **Geçirme bandı (passband):** Filtrenin geçirdiği aralık.
- **Durdurma bandı (stopband, suppression band):** Aralığın dışında kalan, baskılanan ve yok edilen frekanslar.

Sonuçta işaretin dönüşümü ile sistemin dönüşümü çarpılır, sistem her şeyi geçirmez ve geriye işaretin istenen kısmı kalır. Hoca, bu filtrelerin önceki sinüs ve kosinüs ifadeleri kadar karmaşık olmadığını, özel amaçlı filtreler olduğunu söyledi:

- **Alçak geçiren (low-pass):** Belli bir frekansa kadar olan bileşenleri geçirir, yüksek frekansları yok eder.
- **Yüksek geçiren (high-pass):** Belli bir frekansın altındaki düşük frekansları bastırır, yüksek frekansları alır.
- **Bant geçiren (band-pass):** $\alpha$ ile $\beta$ arasındaki frekanslar alınır, gerisi yok edilir.
- **Bant durduran (band-reject, band-stop, notch):** $\alpha$ ile $\beta$ arasındakiler yok edilir, dışındakiler alınır.

> **Ders sonrası not:** Hoca bant durdurma filtresini anlatırken "alfadan sonrakiler ve betadan sonraki alınsın" dedi (01:13:39). Devamındaki "alfa ile beta arasındakiler yok edilsin" tanımına göre doğrusu: $\alpha$'dan öncekiler ve $\beta$'dan sonrakiler alınır.

Hangisinin kullanılacağı tamamen problemin gereksinimine bağlıdır. Yüksek ve alçak geçiren filtreler görüntü ve sinyal işlemede yaygındır. Filtreler özelleştirilebilir, birkaç bandı birden geçiren ya da durduran genelleştirilmiş biçimleri de vardır. Hoca bir de filtre bankalarından söz etti: Çeşit çeşit filtre oluşturulur, sisteme uyarlanır ve hangisi daha başarılıysa o kullanılır. Bu konuyu haberleşmeciler, kontrolcüler, bazen de bilgisayarcılar görür.

> **Ders sonrası not:** Hoca burada "Kalman filtre bankası" dedi (01:14:56). Anlatılan fikir büyük olasılıkla genel filtre bankası kavramıdır; Kalman filtresi ise büyük olasılıkla ayrı bir durum tahmini yöntemi olarak kastedilmemiştir.

Yapılan iş yine aynıdır: Zaman düzleminde konvolüsyon, frekans düzleminde çarpma.

## 7. Faz Kaydıran Filtre Örneği

Hoca matematiğine girmeye gerek olmadığını söyleyerek slayttaki örneği gösterdi. İşaret, sabit bir terim ile kosinüslerin toplamıdır ve çizildiğinde kare dalgaya doğru giden bir görünüm verir.

<!-- BELİRSİZ: Altyazıda x(t) "9-5 cos2PT, 3 cos..." diye bozuk okunuyor. Katsayılar ve işaretler slayttan doğrulanamadı. 9 sabit terimi, 5 cos(2 pi t) terimi ve 3 katsayılı bir terim duyuluyor. -->

Bileşenleri $\cos(2\pi ft)$ kalıbından okuruz: 0 Hz, 1 Hz, 2 Hz ve 3 Hz. Fourier dönüşümünde bu frekanslarda tepeler görülür. Hoca genliklerin normalize edildiğini, bu yüzden 9 ve 5 gibi değerlerin doğrudan okunmadığını söyledi. Grafikte 4 Hz'de de küçük bir şey vardır, sonra azalıp gider. Bu gürültü gibi bir şey olabilir.

Amaç bu işareti, sabit terimi aynen bırakıp diğer bileşenlerin fazını kaydırarak $g(t)$'ye dönüştürmektir. Slayttaki faz kaymaları sırasıyla $\frac{\pi}{4}$, $\pi$ ve $\frac{\pi}{10}$'dur. Bunu yapan sistem fazı değiştiren bir filtredir. Giriş işaretinin dönüşümü ile filtrenin dönüşümü çarpılır, ters dönüşüm alınır ve kırmızıyla gösterilen çıkış elde edilir.

<!-- BELİRSİZ: Faz kaymalarının bileşenlere tam eşleşmesi ve işaretleri slayttan doğrulanamadı. -->

## 8. Örnekleme Şartı, En Yüksek Frekans ve Temel Frekans

Fourier dönüşümünün bir başka uygulaması örneklemedir.

**Soru:** Örnekleme frekansı için hangi şartı söylemiştik? **Cevap:** Bir öğrenci $f_s\ge f_{max}$ dedi. Hoca bunun yanlış olduğunu, en az iki katı olması gerektiğini söyledi; yalnız "büyük olması" yetmez:

$$f_s\ge2f_{max}$$

### 8.1 $f_{max}$ Nasıl Bulunur?

İşaret $\cos t+\cos4\pi t$ gibi bir toplamsa frekanslar doğrudan okunur, en yüksek olanı görürüz. Peki aralarında toplama yerine çarpma olsaydı, hatta birçok kosinüs bileşeni çarpılsaydı? Toplam çarpım formülleri işletilip bileşenler bulunabilir, ama iş zorlaşır. Ayrıca işaret her zaman kosinüslerden oluşmaz, üstel bileşenler de bulunabilir. İş giderek karışır.

Onun yerine işaretin Fourier dönüşümü alınır. Dönüşüm frekans ve genlik bilgisini verir. Görülen **en son**, yani en yüksek frekanslı bileşen $f_{max}$'tır. Bunun iki katı alınarak $f_s$ belirlenir. Demek ki Fourier dönüşümü burada da işe yarar.

> **Ders sonrası not:** Hoca $\cos4\pi t$ için "iki pi'lik frekans" dedi. $\cos(2\pi ft)$ kalıbına göre açısal frekansı $4\pi$ rad/s, frekansı $f=2$ Hz'dir.

### 8.2 Temel Frekans

**Soru:** $f_0$'ı nasıl buluyorduk? **Cevap:** Bileşen frekanslarının EBOB'u (GCD, greatest common divisor) ile.

Hoca burada bir düzeltme yaptı: Temel frekans, en küçük frekans ya da $f_{max}$ değildir. Bileşenlere $f_1,f_2,\dots$ demek daha doğrudur ve $f_0$ bunların EBOB'udur. Diğer frekanslar da onun katlarıdır:

$$f_k=k\,f_0$$

### 8.3 Örtüşmenin Sebebi

Örnekleme yapılırken istenmeyen bir yan etki doğabilir: **örtüşme (aliasing)**. Bunun sebebi $f_s\ge2f_{max}$ şartının sağlanmamasıdır. Hocanın örneği: $f_{max}=1000$ Hz iken $f_s=1990$ Hz veya $f_s=1000$ Hz seçerseniz örtüşme oluşma ihtimali vardır.

> **Ders sonrası not:** Sınır durumda bir uyarı: $f_s=2f$ iken $\sin\left(2\pi f\frac{n}{f_s}\right)=\sin(\pi n)=0$ olur, yani bütün örnekler sıfırdır. Aynı frekanstaki kosinüs ise $\cos(\pi n)=1,-1,1,\dots$ verir (Python ile doğrulandı). Yani $f_s=2f_{max}$ tam eşitliği sinüs için yetmeyebilir.

## 9. Örtüşmenin Mantığı

Örnekleme ile $x(t)$'den $x[n]$'ye geçilir ve normalize frekans ortaya çıkar. $\omega$ yerine $2\pi f$, $T_s$ yerine $\frac{1}{f_s}$ yazılırsa:

$$\hat\omega=\omega T_s=\frac{2\pi f}{f_s},\qquad\text{örtüşmeyle birlikte}\quad\frac{2\pi f}{f_s}+2\pi l$$

> **Ders sonrası not:** Hoca burada $T_s$'yi "işaretin periyodu" diye andı (01:23:50). Doğrusu örnekleme periyodudur: $T_s=\frac{1}{f_s}$.

Mantığı kosinüsün özelliğidir. Bir kosinüs açısına $2\pi$ eklersek ($360^\circ$) birim çemberde aynı noktaya döneriz, sonuç değişmez. Şimdi iki bileşen düşünelim: $\cos(0.4\pi)$ ve $\cos(2.4\pi)$. İkincisi $\cos(0.4\pi+2\pi)$ diye yazılabilir. Bir işaretin bileşenleri bunlarsa, kurala uygun örnekleme yapılmadığında $0.4\pi$ ile $2.4\pi$ örtüşür ve sinyal doğru şekilde orijinal haline geri dönüştürülemez. Eklenen miktar $2\pi$ yerine $4\pi$ da olabilir ($4.4\pi$ gibi). Formüldeki $2\pi l$ katsayısı buradan gelir.

> **Ders sonrası not:** Hoca bir yerde "$\cos 4\pi$'lik bileşen" dedi (01:26:06, ayrıca 01:25:21). Bağlam ve hesap $0.4\pi$ olduğunu gösterir. Ayrıca altyazıda 01:26:31'de "geri dönüştürülür" okunuyor; anlam gereği olumsuz biçim ("dönüştürülemez") kullanıldı, 01:41:20'deki anlatım da bunu destekliyor.

## 10. Analog ve Dijital İşleme, Düzgün Örnekleme

Genel tablo şudur: Bir sistem $x(t)$'den $y(t)$ üretir. Amaç örneğin sesten daha fazla bas elde etmek, görüntüdeki bulanıklığı gidermek (deblurring) ya da işaretten bir bilgi çıkarmak olabilir.

- **Analog elektronikte:** Bu işlemler direnç, opamp gibi devre elemanlarıyla yapılır. Örneğin opamplarla yükselteçler kurulur.
- **Dijital işlemcide:** $x(t)$ belleğe yazılacak sayılara dönüştürülür. Analog dijital dönüştürücü (ADC) ile $x[n]$ elde edilir, bilgisayarda işlenir, dijital analog dönüştürücü (DAC) ile $y(t)$ elde edilir.

Burada $n$ bir tam sayıdır: $0,1,2,3,\dots$ Bunu bir bellek adresi gibi düşünebiliriz. Düzgün (uniform) örneklemede $t$ yerine şu yazılır:

$$t=nT_s=\frac{n}{f_s}$$

**Örnek ($T_s$ ile $f_s$):** $T_s=125\ \mu\text{s}$ ise $f_s=\frac{1}{125\times10^{-6}}=8000$ Hz, yani saniyede 8000 örnek.

**Örnek (örneklenmiş işaret):** $x(t)=\cos(2\pi\cdot500\,t)$, $f_s=5000$ Hz. $t$ yerine $\frac{n}{5000}$ yazılır:

$$x[n]=\cos\left(2\pi\cdot500\cdot\frac{n}{5000}\right)=\cos\left(\frac{\pi n}{5}\right)$$

Sonuçta artık $t$ yoktur ve $n$'ye bağlı bir dizi elde edilmiştir.

Hoca sonra slayttaki grafikleri gösterdi. Periyot kullanmak, iki örnek arasındaki zaman farkını belirtmek demektir. Örnekler arası süre değiştikçe aynı dalgadan farklı aralıklarla örnekler alınır. Slaytta 2 kHz ve 500 Hz ile örnekleme için grafikler var.

<!-- BELİRSİZ: Slayttaki grafiklerin hangi işarete ait olduğu altyazıda net değil. "100 Hz'lik, 2 kHz'lik, 500 Hz'lik" ve "1 bölü 500, 1 bölü 2000" duyuluyor. -->

> **Ders sonrası not:** Hoca iki örnek arasındaki sürenin $0.0005$ olduğunu söyledi (01:30:00). $f_s=5000$ Hz için $T_s=\frac{1}{5000}=0.0002$ s'dir. $0.0005$ s, $\frac{1}{2000}$'e, yani hocanın az sonra andığı 2 kHz'e karşılık gelir. Hoca ayrıca "$T_s$'yi azaltırsak örnekler arasını açarız" dedi (01:30:28). Doğrusu tersidir: $T_s$ örnekler arasındaki süredir, örnek arası $T_s$ arttıkça açılır.

Bu örnekleme hızının sınırı Shannon-Nyquist teoremiyle belirlenmiştir. Amaç işareti doğru şekilde geri oluşturabilmek (reconstruction), yani örtüşmeden kurtulmaktır.

> **Hocanın vurgusu:** Teoremin mantığını haberleşmeciler çok daha uzun anlatır, ama $2f_{max}$'ı bilmek artık hepinizin görevidir.

### 10.1 Aynı Noktalardan Geçen İki Dalga

Slaytta iki sürekli dalga var ve belli noktalarda kesişiyorlar. Her ikisi örneklenince aynı biçime dönüyor. $n$ tam sayı olduğu için:

$$\cos(0.4\pi n)=\cos(2.4\pi n)$$

Aradaki $2\pi n$'lik fark, örnekleme sonrasında görünmez hale gelir.

### 10.2 CD Depolama Örneği

Slaytta bir ses dosyasını bir dakika kaydetmek için gereken alan hesabı var. Hesap: kanal sayısı (iki kanal) çarpı örnekleme hızı çarpı süre çarpı örnek başına bit (16 bit). Sonuç 8'e bölünerek bayta, oradan megabayta çevrilir.

<!-- BELİRSİZ: Slayttaki örnekleme hızı ve sonuç (MB) altyazıda söylenmiyor. -->

## 11. Normalize (Dijital) Frekans

Slayttaki işarette $t=nT_s$ yazılınca $\omega T_s$ çarpımı ayrı ele alınır ve $\hat\omega$ ile gösterilir:

$$\hat\omega=\omega T_s=\frac{\omega}{f_s}=\frac{2\pi f}{f_s}$$

Buna dijital frekans denir. İşaretin sürekli formdan ayrık forma geçmesi için gereken frekans bilgisidir. $f$, $0$ ile örnekleme frekansı arasında değişirken, $\hat\omega$, $0$ ile $2\pi$ arasında değişir. Birimi radyandır, radyan bölü saniye değildir.

**Örnek:** $f=100$ Hz, $f_s=1000$ Hz. Frekans düzleminde 100 Hz'de tepe görülür. $\hat\omega$ cinsinden:

$$\hat\omega=2\pi\cdot\frac{100}{1000}=2\pi\cdot0.1=0.2\pi$$

> **Ders sonrası not:** Hoca bu örnekte $f_s$'yi "5 katı kadar" diye okudu (01:34:37). $\frac{1000}{100}=10$ kattır. Hesaptaki $0.2\pi$ değeri doğrudur.

**Örnek (kendi frekansıyla örnekleme):** Aynı 100 Hz'lik işaret 100 Hz ile örneklenirse $\hat\omega=2\pi\cdot1$ olur, yani $2\pi$'nin bir katı. O zaman $x[n]=\cos(2\pi n)=1$, tüm $n$ için aynı. Hoca soruyu şöyle sordu: Bu $x[n]$ sıfır frekans mıdır acaba? 100'lük işareti 100 ile örnekledik, geri kurtarabilecek miyiz? Hayır: Örnekleme frekansının yetersizliği yüzünden işaret, sıfır frekanstaki bir işaretten ayırt edilemez. İşte bu olay örtüşmedir.

<!-- BELİRSİZ: Slaytta işaret karmaşık üstel olarak verilmiş olabilir ("kompleks eksponansiyel" duyuluyor); burada kosinüs biçimiyle yazıldı. -->

## 12. Örtüşmenin Spektrumda Görülmesi

Normalize frekansın formülünde $2\pi$ aralıklarla aynı nokta geri geldiği için spektrumda fazladan bileşenler görülür. Tek frekanslı bir işarette bu tek bir kopya gibidir. Birden fazla bileşen olursa hepsi birbirine karışır. Sebep yine kosinüsün $2\pi$ periyotlu olmasıdır.

### 12.1 $\cos(400\pi t)$ ve $\cos(2400\pi t)$

Slayttaki iki işaret aynı frekansla örnekleniyor. Sonuçlar $0.4\pi n$ ve $2.4\pi n$ olduğuna göre $f_s=1000$ Hz'dir (ara adım eklendi):

$$x_1[n]=\cos(0.4\pi n),\qquad x_2[n]=\cos(2.4\pi n)$$

İkincisi toplam formülüyle açılır:

$$\cos(2.4\pi n)=\cos(0.4\pi n+2\pi n)=\cos(0.4\pi n)\cos(2\pi n)-\sin(0.4\pi n)\sin(2\pi n)$$

$n$ tam sayı olduğu için $\cos(2\pi n)=1$, $\sin(2\pi n)=0$'dır. Sonuç $\cos(0.4\pi n)$ çıkar, hiçbir şey değişmez. İki işaretin örnekleme sonrasında aynı noktaya gelmesi örtüşmedir. Frekans olarak bunlar 200 Hz ve 1200 Hz'dir, aralarında tam $f_s$ fark vardır (ara adım eklendi).

> **Ders sonrası not:** Eşitlik Python ile $n=0,\dots,19$ için doğrulandı.

### 12.2 Genel İfade

Bir işaretin frekansına $f_s$, $2f_s$ ya da $f_s$'nin herhangi bir tam katını eklemek, $n$ düzleminde hiçbir şey değiştirmez. Çünkü $2\pi l$ kosinüste anlam ifade etmez:

$$\cos\left(2\pi\frac{f_0+lf_s}{f_s}n\right)=\cos\left(2\pi\frac{f_0}{f_s}n+2\pi ln\right)=\cos\left(2\pi\frac{f_0}{f_s}n\right)$$

Dolayısıyla $f_0$, $f_0+f_s$ ve $f_0+2f_s$ frekansları birbirinden ayırt edilemez. Bunu önlemenin yolu $f_s$'yi $2f_{max}$'tan küçük seçmemektir.

### 12.3 Yeterli ve Yetersiz Örnekleme

Slaytta önce frekansın 5 katı ile örneklenen bir işaret var. Bir bileşenin $2\pi$ sonraki kopyası ile eşleniğinin kopyası birbirinden uzaktır, karışmazlar.

Örnekleme 80 Hz ile yapılırsa ise durum değişir. 100 Hz'lik işaret için (ara adım eklendi):

$$\hat\omega=2\pi\cdot\frac{100}{80}=2.5\pi$$

Bir bileşen $2.5\pi$'de, öbürü $-2.5\pi$'dedir. $2.5\pi$'nin $2\pi$ önceki kopyası $0.5\pi$, ondan da $2\pi$ önceki $-1.5\pi$'dir. $-2.5\pi$'nin kopyaları da $-0.5\pi$ ve $1.5\pi$'dir. Hepsi birbirine karışır. Geri oluşturmak istediğimizde sinyali doğru elde edemeyiz. Zaman düzleminde de elimizdeki seyrek örneklerden geçen bir eğri çizebiliriz, ama aradaki bilgi kaybolmuştur.

Slayttaki bir başka örnekte bileşen $1.6\pi$'dedir ve $2\pi$ önceki kopyası $-0.4\pi$; $-1.6\pi$'deki bileşenin kopyası ise $0.4\pi$'dir. Yine birbirine karışırlar.

> **Ders sonrası not:** Altyazıda bu örneğin örnekleme frekansı "325" diye okunuyor. $f=100$ Hz için $2\pi\cdot\frac{100}{f_s}=1.6\pi$ eşitliği $f_s=125$ Hz'i verir; $f_s=325$ Hz $0.615\pi$ verirdi. Slaytta büyük olasılıkla 125 Hz yazıyor. $\cos(2.5\pi n)=\cos(0.5\pi n)$ ve $\cos(1.6\pi n)=\cos(0.4\pi n)$ Python ile doğrulandı.

<!-- BELİRSİZ: 12.3'teki işaretin 100 Hz olduğu altyazıda açıkça söylenmiyor; 2.5 pi ve 1.6 pi değerlerinden çıkarıldı. -->

> **Hocanın vurgusu:** Örnekleme frekansı en yüksek frekansın en az iki katı olmalıdır. Bir de $t$ düzleminden $n$ düzlemine geçişte elde edilen sonucu bulabilmek gerekir. Bu kısımdaki ayrıntılı türetmelere gerek yok.

## 13. FIR Filtrelere Giriş

Frekans cevabının ne olduğunu konuştuktan sonra filtreyle ilgili bir uygulamaya geçildi: sonlu dürtü cevaplı (Finite Impulse Response, FIR) filtreler. Amaç, $x[n]$ işaretine bir filtre uygulayıp $y[n]$'yi elde etmektir. Hoca bunu doğrudan bir program yazmak gibi düşünmemizi istedi ve yapısal programlamada anlattığı görüntü işleme örneğini hatırlattı: Bir matris üzerinde filtre gezdirilir ve bununla örneğin görüntünün kenarları bulunur.

Dijital filtrelemede sürekli işaret $x(t)$, $x[n]$ haline dönüştürülür, bilgisayarda bir algoritma çalıştırılır ve $y[n]$ elde edilir. Bu işlemi yapan blok dijital filtredir. Bir yazılım olabileceği gibi donanım da olabilir: VLSI, FPGA, DSP yongaları gibi. Dijital işaret işleme (DSP) ayrı bir alandır. Örneğin bir telefondaki DSP yongası gürültü giderme ya da frekanslar üzerinde değişiklik yapma gibi işler yapabilir.

Sistem analiz edilirken zaman ve frekans düzlemine bakılır, sentez yapılırken bu analiz sonuçları bir araya getirilir. Algoritmaya iki basit örnek: Bir vektörün her elemanının karesini alıp başka bir vektör üretmek ($y[n]=x^2[n]$) veya bir vektörde belli aralıklarla ortalama almak.

> **Hocanın vurgusu:** Ayrık sinyaller `stem` ile çizilir. $n$ ile indekslenmiş bir dizi görmemiz gerekir. Ayrık bir sinyali `plot` ile bitişik çizmek yanlıştır.

## 14. Kayan Ortalama Filtresi

### 14.1 Üç Noktalı, İleriye Bakan Filtre

Kayan ortalama (running average) filtresi önceki sistemlere çok benzer, yalnız adı filtredir:

$$y[n]=\frac13\left(x[n]+x[n+1]+x[n+2]\right)$$

Slayttaki işaret $n=0$'dan başlar: $2,4,6,4,\dots$ Hesap, $n+2$'nin ilk örneğe denk geldiği $n=-2$'den başlatılır. Olmayan örnekler sıfır sayılır:

- $n=-2$: $\frac{0+0+2}{3}=\frac23$
- $n=-1$: $\frac{0+2+4}{3}=2$
- $n=0$: $\frac{2+4+6}{3}=4$
- $n=1$: $\frac{4+6+4}{3}=\frac{14}{3}$

Bu şekilde pencere kaydırılarak bütün değerlerin ortalaması alınır.

<!-- BELİRSİZ: Slayttaki işaretin son örnekleri altyazıda net değil ("2-4, 6-2-4" duyuluyor). Dört örnek 2,4,6,4 hesapla tutuyor; beşincisi büyük olasılıkla 2'dir. x=[2,4,6,4,2] için tam çıkış [2/3, 2, 4, 14/3, 4, 2, 2/3] olur (Python). -->

**Soru:** Bu işlem sonucunda sivrilik artar mı, azalır mı? **Cevap:** Azalır. Girişte sıfırdan ikiye, ikiden dörde, dörtten altıya ikişer birimlik sıçramalar vardı. Çıkışta geçişler daha yumuşaktır. Filtre sivriliği azaltır.

### 14.2 Nerede Kullanılır?

Hoca kimyasal bir deney örneği verdi: Milyonlarca örnekli bir sinyalde küçük bir noktada ufak bir gürültü, ufak bir tepe (pik) oluşmuş olabilir. Bunu gidermek için sinyal baştan başlanarak filtrelenir. Sivrilik azalır. Bir miktar bilgi kaybedilir, ama oradaki yanıltıcı etki ortadan kalkar. Bu işleme yumuşatma (smoothing) denir.

**Soru:** Bu yumuşatmayı sürekli, sonsuza kadar yaparsak ne olur? **Cevap:** $y$ değerleri giderek küçülür ve sıfıra ulaşır. Her filtrelemede değerler aşağı çekilir, yumuşaklık artar.

> **Ders sonrası not:** Katsayı toplamı 1 olan bu filtre örneklerin toplamını korur. Python ile $[2,4,6,4,2]$ dizisine filtre 200 kez uygulandı: Toplam 18 olarak kaldı, en büyük değer $0.62$'ye indi, dizinin uzunluğu 405 oldu. Yani değerlerin küçülmesinin sebebi işaretin giderek yayılıp düzleşmesidir; toplam sıfıra gitmez.

### 14.3 Pencere ve Uyarlamalı Filtre

Filtrelemede 3 ya da 4 gibi bir pencere boyutu belirtilir. Genellikle tek sayılar kullanılır. Pencere baştan sona her noktada kaydırılır.

Bu düzgün (uniform) bir yaklaşımdır. Başka bir yaklaşımda 3 ile başlanır, ilerledikçe değerler arasındaki farka yani türeve bakılır. Türevin büyük olduğu yerlerde pencere boyutu örneğin 3'ten 5'e çıkarılabilir ya da azaltılabilir. Buna uyarlamalı (adaptive) filtre denir.

### 14.4 Geçmişe Bakan (Nedensel) Filtre

Üç noktalı ortalamanın diğer biçimi $x[n+1]$, $x[n+2]$ yerine önceki değerlere bakar:

$$y[n]=\frac13\left(x[n]+x[n-1]+x[n-2]\right)$$

Sonuçlar aynıdır, yalnız ötelenmiş olarak gelir. Bulunulan noktanın öncesi yoktur, bu yüzden $n=0$'dan başlanır.

<!-- BELİRSİZ: Hocanın okuduğu ara toplamlar altyazıda "6, 4, 10, 12, 12, 4" gibi bozuk geçiyor. Slayt görülmeden doğrulanamadı. -->

## 15. Genel FIR Filtre ve Ağırlıklı Ortalama

Genel hali şöyledir: Girişin ötelenmiş biçimleri $x[n-k]$, önünde katsayılar $b_k$ ile toplanır:

$$y[n]=\sum_{k=0}^{M}b_k\,x[n-k]$$

Kayan ortalamada bütün katsayılar $\frac13$'tür. Katsayılar farklı olursa buna ağırlıklı (ağırlıklandırılmış) filtre denir. Hocanın örneği, sırayla $3,-1,2,1$ katsayılarıdır:

$$y[n]=3x[n]-x[n-1]+2x[n-2]+x[n-3]$$

Denklemdeki $M$'ye filtrenin **mertebesi** (order), $M+1$'e **uzunluğu** (length) denir. Bulunulan noktada, penceredeki değerler katsayılarla çarpılıp toplanır. Hoca bunun ağırlıklı aritmetik ortalamadan farkı olmadığını söyledi.

**Örnek:** Slaytta bir finans verisi ve ona uygulanan filtre var. Pencere boyutu 50 (50 point) olan filtre, pembe renkle gösterilen yumuşatılmış eğriyi vermektedir.

> **Ek bilgi (derste anlatılmadı):** Bu filtrede çıkış yalnız girişten hesaplandığı için birim darbe cevabı en fazla $M+1$ örnektir, adındaki "sonlu" buradan gelir. Bölüm 2 ve 3'teki sistemlerde ise çıkışın geçmiş değerleri de denklemde yer alır, bu yüzden $h[n]$ sonsuza kadar sürer ($\left(\frac12\right)^n$ gibi). Yani o iki sistem FIR değildir.

## 16. Filtre Bir Konvolüsyondur

Birim darbe $\delta[n]$ için özelliği hatırlayalım: $n=0$'da 1, diğer yerlerde 0'dır. Herhangi bir işaret birim darbeler cinsinden yazılabilir, örneklerin sadece kaydırılmış toplamıdır:

$$x[n]=2\delta[n]+4\delta[n-1]+6\delta[n-2]+4\delta[n-3]+\dots$$

Filtreler de birim darbe cinsinden yazılabilir:

$$h[n]=\sum_{k=0}^{M}b_k\,\delta[n-k]$$

Hoca, 4 noktalı ortalama filtresini örnek verdi. Katsayıları $\frac14$ olan bir işarettir:

$$h[n]=\frac14\left(\delta[n]+\delta[n-1]+\delta[n-2]+\delta[n-3]\right)$$

$x[n]$ ile $h[n]$'nin konvolüsyonu filtrelenmiş sonucu verir. Bir noktadan başlanır, dört nokta alınır, bir kaydırılır, tekrar dört nokta alınır. Konvolüsyonla filtre arasındaki ilişki budur:

$$y[n]=x[n]*h[n]$$

> **Ders sonrası not:** Hoca bu konvolüsyonun sonucunu okumadı. Giriş $[2,4,6,4,2]$ alınırsa (Bölüm 14.1'deki belirsizliğe bakınız) Python'da sonuç $[0.5,\ 1.5,\ 3,\ 4,\ 4,\ 3,\ 1.5,\ 0.5]$ çıktı.

Konvolüsyon devreye girince Fourier dönüşümü de karşımıza çıkar. Filtrenin dönüşümü ile işaretin dönüşümü çarpılırsa frekans düzleminde filtrelenmiş işaret bulunur: $Y=H\cdot X$.

### 16.1 Pencere Boyutunun Etkisi

Slaytta aynı işarete 3 noktalı ve 7 noktalı ortalama uygulanmış. 3 noktalı ortalamada değişim küçüktür: Az değişen bölgelerde ufak kaymalar olur, 2 civarındaki tepe biraz uzaklaşır, sıçrama olan yerlerde ise ciddi değişiklik görülür. Genel düzlem aynı kalır. 7 noktalıda dalga biçimi belirgin şekilde düzleşir, pencere daha da büyürse dümdüz hale gelir.

Hoca amacı özetledi: $x[n]$'yi filtreden geçirip $y[n]$'yi bulmak. Sayısal sistemler ne kadar karmaşık olursa olsun mantık hep aynıdır.

### 16.2 MATLAB'de Konvolüsyon

MATLAB'de bu işlem için konvolüsyon komutu yeterlidir. `bb` filtre katsayılarını, `xx` işareti tutar:

```matlab
yy = conv(bb, xx);
```

`bb` olarak örneğin $\frac14,\frac13,\frac18$ verilirse filtre 3 elemanlıdır ve komut bu katsayılarla çarpıp toplar. `conv2` ise iki boyutlu konvolüsyon yapar ve az önceki görüntü örneğindeki işi görür.

> **Ders sonrası not:** Altyazıda filtre katsayıları için "yer değiştirmesi çok önemli" geçiyor (01:58:13). Konvolüsyon değişmelidir ve Python'daki `np.convolve` iki sırada aynı sonucu verdi. Yani `conv` argümanlarının sırası sonucu değiştirmez.

### 16.3 Örnek: Birler Dizisi ile Konvolüsyon

$x[n]=1,1,1,1,1,1,1$ ve $h[n]=[1,-1,2,-1,1]$, yani $n=0,1,2,3,4$ noktalarında bu değerler. Filtre kaydırılarak konvolüsyon yapılır. Giriş hep 1 olduğu için her adımdaki sonuç, $h$'nin o ana kadarki toplamıdır (ara adım eklendi):

- $y[0]=1$
- $y[1]=1-1=0$
- $y[2]=1-1+2=2$
- $y[3]=1-1+2-1=1$
- $y[4]=1-1+2-1+1=2$
- $y[5]=2$, $y[6]=2$

Hocanın verdiği sonuç: $y[n]=[1,0,2,1,2,2,2]$.

> **Ders sonrası not:** Python ile doğrulandı. Giriş tam 7 örnekse konvolüsyon sonraki adımlarda $1,2,0,1$ ile biter. Yani hocanın okuduğu yedi değer sonucun ilk yedi örneğidir.

## 17. Birinci Fark (Türev) Filtresi

Bir başka filtre, birinci dereceden türev alan filtredir. Türevin tanımı:

$$\frac{df}{dx}=\lim_{h\to0}\frac{f(x+h)-f(x)}{h}$$

Bilgisayarda, sayısal sistemlerde $h$'yi sıfıra götüremeyiz, çünkü bellekte tam sayılı indisler vardır. $h$ en küçük 1 olur ve payda 1 kalır. O zaman türev, $x+1$'inci örnekten $x$'inci örneği çıkarmaktır ya da geri farkla $x$'inci örnekten $x-1$'inci örneği çıkarmak:

$$y[n]=x[n]-x[n-1]$$

Bu da bir filtredir.

**Örnek:** Giriş birim basamak $u[n]$ ise:

$$y[n]=u[n]-u[n-1]=\delta[n]$$

Yani birim basamağın türevi birim darbedir. Basamağın sadece sıçrama noktasında fark vardır, düz kısımlarda fark sıfırdır. Sonuca filtre yoluyla da ulaşılır. Python ile sonuç $[1,0,0,0,\dots]$ olarak doğrulandı.

## 18. Blok Diyagram ve Kaskad Sistemler

Filtrelerde temel işlemler toplama, çıkarma, çarpma ve geciktirmedir. Bunları sistemler konusunda da görmüştük. Bir filtre aslında bir sisteme giriş verilmesidir.

Filtre sistemi şu yapıdadır: $y[n]$, $x[n]$'nin belli miktarda geciktirilmiş hallerinden oluşur (bir önceki örnek, ondan önceki örnek, onun da öncesi). Bunlar $b_0,b_1,b_2,b_3$ katsayılarıyla çarpılır ve hepsi toplanır. Blok diyagramı budur.

> **Hocanın vurgusu:** Bir blok diyagram verilirse, genel formül akla getirilip sistemin birim darbe cinsinden ifadesi yazılabilmelidir.

> **Ders sonrası not:** Hoca burada "birim basamak cinsinden" dedi (02:02:39, 02:02:46). Önceki anlatımı ($h[n]=\sum b_k\delta[n-k]$, 01:54:26) ve "biraz önceki şekilde" ifadesi, doğrusunun birim darbe olduğunu gösteriyor.

Slaytlarda zamanla değişmezlik, doğrusallık ve nedensellik özellikleri tekrar edilmiş. Bunları sistemler konusunda görmüştük.

**Kaskad sistemler:** Bir sistemin çıkışı başka bir sisteme giriş olur. Burada aslında iki sistemin konvolüsyonu vardır ve $x$ bu sonuca uygulanarak $y$ elde edilir. Sıra değiştirilebilir mi? Evet, konvolüsyonun özelliğinden dolayı değiştirilebilir. Bunlar LTI sistemlerdir.

## 19. FIR Filtrenin Frekans Cevabı

Filtre katsayılarından frekans cevabı doğrudan yazılır. Örnek filtre:

$$h[n]=\delta[n]+2\delta[n-1]+\delta[n-2]$$

$\delta[n]$'nin dönüşümü 1, $\delta[n-1]$'inki $e^{-j\hat\omega}$, $\delta[n-2]$'ninki $e^{-j2\hat\omega}$'dır. Katsayılar önlerinde aynen gelir:

$$H(\hat\omega)=1+2e^{-j\hat\omega}+e^{-j2\hat\omega}$$

Hoca buradaki $\hat\omega$'nın az önceki örnekleme konusundaki şapkalı omega olmadığını, frekans düzleminin bazen böyle gösterildiğini, bunun gösterim farkı olduğunu söyledi.

> **Ders sonrası not:** Hesap açısından fark yoktur: Ayrık zaman frekansı, $\Omega$ ya da $\hat\omega$ diye yazılsın, $e^{-j\hat\omega n}$ içindeki değişkendir ve örneklenmiş bir işarette $\hat\omega=\omega T_s$ değerini alır. Örneğin Bölüm 10'daki $\cos\left(\frac{\pi n}{5}\right)$ dizisinin ayrık frekansı $\frac{\pi}{5}$'tir ve $\frac{2\pi\cdot500}{5000}$ ile aynıdır.

Bu ifade kosinüsle yazılır. Slayttaki biçim şudur (ortak $e^{-j\hat\omega}$ parantezine alınarak, ara adım eklendi):

$$H(\hat\omega)=e^{-j\hat\omega}\left(e^{j\hat\omega}+2+e^{-j\hat\omega}\right)=\left(2+2\cos\hat\omega\right)e^{-j\hat\omega}$$

Sonrasında genlik ve faz analizi yapılır. Kosinüslü ifade sıfırdan büyük olduğu sürece genlik $2+2\cos\hat\omega$'dır. Çizildiğinde bir tarafı geçirip diğerini bastıran bir filtre görülür. Hoca buna kosinüs filtresi dedi ve ses işlemede çok kullanıldığını söyledi.

> **Ders sonrası not:** Python ile doğrulandı: İki biçim $[-\pi,\pi]$ boyunca eşittir. Genlik $\hat\omega=0$'da 4, $\hat\omega=\pm\frac{\pi}{2}$'de 2, $\hat\omega=\pm\pi$'de 0'dır. Yani bu bir alçak geçiren filtredir.

Slaytta bir de bu filtreye uygulanan bir $x[n]$ var. Yöntem aynıdır: $x[n]$'nin dönüşümü alınır, $H$ ile çarpılır, sonuç kosinüslü bir işaret olarak ters dönüştürülür. Hoca, sistemi ağır matematikle anlatmayacağını belirterek ayrıntıya girmedi.

<!-- BELİRSİZ: Slayttaki x[n] ve y[n] ifadeleri altyazıda söylenmiyor. -->

> **Ders sonrası not:** Hoca burada $H(\hat\omega)$ için "basamak responsu" dedi (02:06:09). Doğru adı frekans cevabıdır.

MATLAB'de bunun karşılığı `freqz` komutudur. Katsayılar ve frekans noktaları verilir, komut az önceki sonucu döndürür:

```matlab
HH = freqz(bb, 1, ww);
```

<!-- BELİRSİZ: Komutun tam yazımı slaytta. Altyazıda katsayılar, "bir" ve frekans değerleri duyuluyor. Ortadaki 1 hakkında hocanın açıklaması ("işaretin başlangıç ve bitiş noktalarıyla alakalı") net değil. Büyük olasılıkla paydaya ait katsayıdır. -->

> **Hocanın vurgusu:** FIR filtrelerde de Fourier dönüşümünü doğrudan kullandık. Fourier dönüşümünün türev ve zamanda öteleme başta olmak üzere özelliklerini bilmek çok işimize yarayacaktır.

## Dersin Toparlaması

Bu derste Fourier dönüşümünün neden işe yaradığı üç farklı yerde görüldü. İlk olarak LTI sistem analizinde: Diferansiyel ve fark denklemleri, türevin $j\omega$ ile ve gecikmenin $e^{-j\Omega}$ ile çarpmaya dönüşmesi sayesinde cebirsel hale geldi. $H=\frac{Y}{X}$ frekans cevabı bulundu, konvolüsyon yerine çarpma yapılarak çıkış hesaplandı. İkinci olarak filtrelemede: İstenmeyen bileşenler frekans düzleminde görülüp baskılandı, alçak, yüksek, bant geçiren ve bant durduran filtreler tanındı. Üçüncü olarak örneklemede: En yüksek frekans dönüşümden okundu, $f_s\ge2f_{max}$ şartının ve örtüşmenin kosinüsün $2\pi$ periyodundan geldiği görüldü.

Son bölümde bu fikirler FIR filtrelerde birleşti: $y[n]=\sum b_kx[n-k]$ bir konvolüsyondur, katsayılar birim darbe cinsinden yazılır, frekans cevabı doğrudan bulunur. Sonraki bağlantı: Öğleden sonraki oturumda Laplace dönüşümü ve Fourier dönüşümüyle ilişkisi, ardından z-dönüşümü görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
