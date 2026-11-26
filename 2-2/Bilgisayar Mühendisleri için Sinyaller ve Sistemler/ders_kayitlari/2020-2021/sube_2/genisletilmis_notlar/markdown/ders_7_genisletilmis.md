# Ders 7 Genişletilmiş Notu: Sürekli ve Ayrık Zamanlı Konvolüsyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sürekli Zamanda Konvolüsyon İntegralinin Tekrarı
- 2. Analitik Örnek: $x(t)=t$ ve $y(t)=t^2$
- 3. Konvolüsyonun Yorumu: Benzerlik ve Örtüşme
- 4. Konvolüsyon İntegralinin Güçlükleri
- 5. Grafik Yöntem: İki Birim Dikdörtgen Darbe
- 6. Slayt Örneği: Bölgelere Ayırma Adımları
- 7. Sistem Modeli, Dürtü Cevabı ve Konvolüsyon Özellikleri
- 8. Dönüşümler Ne İşe Yarar
- 9. Ayrık Zamanda Konvolüsyon Toplamı
- 10. Ayrık Grafik Konvolüsyon Örnekleri
- 11. Fark Denklemleri ve Dürtü Cevabı
- 12. Konvolüsyon ve Polinom Çarpması
- 13. MATLAB'de Ayrık İşaret Çizimi ve Hazır Fonksiyonlar
- Örnek Sorular

## 1. Sürekli Zamanda Konvolüsyon İntegralinin Tekrarı

Önceki derste sinyal ve sistemlerin özellikleri işlenmiş, sürekli zamanda konvolüsyona başlanmıştı. Bu ders önce sürekli zamandaki konvolüsyonu kısaca tekrar etti, sonra ayrık zamana geçti. Hoca, sinyal ve sistemlerdeki kavramların hemen hepsinin bir sürekli zaman (continuous time) bir de ayrık zaman (discrete time) karşılığı olduğunu hatırlattı. Sürekli zamandaki konvolüsyon bir integraldir; ayrık zamandaki karşılığı toplam ($\Sigma$) sembolüyle yazılır (ekrandan, 00:20:00).

İki işaretin konvolüsyonu şöyle gösterilir (ekrandan, 00:20:00):

$$f(t)=x(t)*y(t)=\int x(\tau)\,y(t-\tau)\,d\tau$$

Konvolüsyonun önemli bir ön koşulu vardır: sistem doğrusal (linear) ve zamanla değişmez (time-invariant) olmalıdır. Bu iki koşulu sağlayan sistemlere LTI, Türkçe kaynaklarda DZD (doğrusal zamanla değişmez) sistem denir. Hoca sistemlerin pek çok açıdan sınıflandırıldığını, konvolüsyonun bu sınıfın bir alt kümesinde geçerli olduğunu, sistemi bir denklem gibi düşünmenin de sakıncası olmadığını söyledi.

### 1.1 $\tau$ Düzlemine Geçiş

İntegral hesaplanırken $t$ zaman ekseninden farklı bir eksene geçilir. Matematik kitapları bu değişkeni çoğunlukla başka bir harfle gösterir; elektronik ve bilgisayar kitapları $\tau$ kullanır. Amaç, periyodu gösteren $T$ ile karışmamasıdır. Hoca benzer bir örnek verdi: karmaşık sayılarda $i$ yerine $j$ kullanılır, çünkü $i$ elektrik akımıyla karışır.

Geçiş şöyle yapılır:

- Birinci işarette $t$ görülen yere $\tau$ yazılır: $x(\tau)$.
- İkinci işarette $t$ yerine $t-\tau$ yazılır: $y(t-\tau)$.
- İkisi çarpılır ve $\tau$'ya göre integral alınır.

İntegral $\tau$'ya göre alınsa da sonuç $t$'nin fonksiyonudur. $t$ bağımlılığı integralin sınırlarından (ör. $0$'dan $t$'ye) ve $y(t-\tau)$ teriminden gelir. Genel tanımda sınırlar $-\infty$ ile $+\infty$'dur.

## 2. Analitik Örnek: $x(t)=t$ ve $y(t)=t^2$

Soru: $x(t)=t$, $y(t)=t^2$ için $f(t)=x(t)*y(t)$'yi bulun (ekrandan, 00:20:00). Sınırlar şimdilik $0$'dan $t$'ye alındı.

### 2.1 Birinci Yol

$x(\tau)=\tau$ ve $y(t-\tau)=(t-\tau)^2$ yazılır:

$$f(t)=\int_0^t \tau\,(t-\tau)^2\,d\tau$$

Kare açılır: $(t-\tau)^2=t^2-2t\tau+\tau^2$. $\tau$ ile çarpılınca integrand $\tau^3-2t\tau^2+t^2\tau$ olur. $t$, $\tau$'ya göre sabittir ve integralin dışına çıkar:

$$f(t)=\left.\frac{\tau^4}{4}\right|_0^t-2t\left.\frac{\tau^3}{3}\right|_0^t+t^2\left.\frac{\tau^2}{2}\right|_0^t=\frac{t^4}{4}-\frac{2t^4}{3}+\frac{t^4}{2}$$

Payda 12'de toplanır: $\frac{3t^4-8t^4+6t^4}{12}=\frac{t^4}{12}$ (ekrandan, 00:25:00). Hoca ara adımda bir öğrencinin uyarısıyla üssü düzeltti ($t\cdot t^3=t^4$) ve bir an "$-2t^4/12$" dedikten sonra sonucu başka yoldan kontrol ederek $t^4/12$ olarak kesinleştirdi.

### 2.2 Değişme Özelliğiyle İkinci Yol

Konvolüsyonun değişme özelliği vardır: $x*y=y*x$. Bu kez $t^2$ sabit, $t$ kaydırılan işaret yapılırsa integral kısalır (ekrandan, 00:35:00):

$$f(t)=\int_0^t \tau^2\,(t-\tau)\,d\tau=t\frac{t^3}{3}-\frac{t^4}{4}=\frac{t^4}{3}-\frac{t^4}{4}=\frac{t^4}{12}$$

İki yol aynı sonucu verir. Hoca, değişme özelliğini baştan kullanmanın işlemi kolaylaştıracağını belirtti.

### 2.3 Sistem Yorumu

Hoca $y(t)$'yi bir sistem olarak yorumladı: davranışı $t^2$ olan bir sistem (1 verince 1, 2 verince 4, 3 verince 9 çıkaran) ya da zamana bağlı değişimi böyle olan bir RLC devresi, bir havuz. Bu doğrusal zamanla değişmez sisteme $x(t)=t$ girişi verilirse çıkış $t^4/12$ olur. Aynı zamanda iki işaret de birer sinyal olarak düşünülebilir ve konvolüsyon ikisi arasındaki benzerlik hakkında bilgi verir.

### 2.4 MATLAB Online ile Deneme

Hoca aynı örneği MATLAB Online'da gösterdi. Bir zaman vektörü (yaklaşık $1$'den $10$'a, $0{,}01$ adımla) oluşturuldu; $X$ bu vektörün kendisi, $Y$ karesi oldu. Komutlar ekranda şöyleydi (ekrandan, 00:30:00):

```matlab
C=conv(X,Y);
plot(X)
hold on
plot(Y,'r')
hold on
plot(C,'g')
```

Çalışma alanında $X$, $Y$ ve $t$ 901 elemanlı, $C$ ise 1801 elemanlıdır. Hoca, `conv` fonksiyonunun daha çok ayrık zamanda kullanıldığını, burada sürekli gibi düşünüldüğünü söyledi; gerçek sürekli işaretin iki sayı arasında bile sonsuz değer içerdiğini hatırlattı. Ardından analitik sonuç da `L=t.^4/12` biçiminde çizdirildi. İki eğri farklı göründü; hoca bunun MATLAB'in ayrık konvolüsyonuyla ilgili olduğunu, $C$'nin daha fazla veri içerdiğini ve konuya ayrık zamanda döneceğini söyledi.

> **Ders sonrası not:** `conv` örnekleri doğrudan çarpıp toplar; sürekli integrale yaklaşmak için sonucun örnekleme adımıyla ($dt=0{,}01$) çarpılması gerekir. $N$ ve $M$ uzunluklu iki dizinin konvolüsyonu $N+M-1$ elemanlıdır ($901+901-1=1801$). Ayrıca örneklenmiş vektör $0$'dan değil $1$'den başlıyorsa sonuç analitik $t^4/12$ ile birebir örtüşmez. Görülen farkın nedeni büyük olasılıkla bunlardır.

## 3. Konvolüsyonun Yorumu: Benzerlik ve Örtüşme

Hoca önceki derste gösterdiği bir konvolüsyon animasyonu sitesine döndü (ekrandan, 00:25:00). Bir örnekte bir üçgen ile üstel sönümlü bir darbe ($f_1$ üçgen, $f_2$ üstel) konvolüsyona sokuluyordu. Konvolüsyonun sırası önemli değildir, çünkü değişme özelliği vardır.

Konvolüsyon özünde bir alan hesabıdır: kaydırılan işaretle sabit işaretin çarpımının altındaki alan her kaydırma için hesaplanır. Bu alan iki işaretin birbirine ne kadar benzediğini, en büyük değeri ise en çok benzedikleri yeri söyler. Animasyonda iki dikdörtgen darbenin konvolüsyonu da gösterildi (ekrandan, 01:00:00): kaydırılan darbe sabit darbeye yaklaştıkça çarpımlar sıfırdan farklı olmaya başlar, örtüşen alan artar, tam örtüşmede en yüksek değere ulaşır, sonra azalır ve örtüşme bitince yeniden sıfır olur.

## 4. Konvolüsyon İntegralinin Güçlükleri

$x(t)=t$ ve $y(t)=t^2$ "güllük gülistanlık" fonksiyonlardır. Genel tanımda ($-\infty$'dan $+\infty$'a) iki tür güçlük çıkar:

- **İntegralin içini çözmek:** Değişken dönüşümü, kısmi integrasyon (by parts), kısmi kesirler, trigonometrik dönüşümler gerekebilir. Hoca, istenirse işin içinden çıkılamayacak kadar zor bir integral sorulabileceğini, ama derste temel işaretler üzerinden çalışıldığını söyledi.
- **Süreksizlikler:** $t$ ve $t^2$ her noktada süreklidir. Kare dalga gibi işaretlerde ani iniş ve çıkışların olduğu kritik noktalar (süreksizlik noktaları) vardır. Bu durumda integral tek seferde alınamaz; sınırlara göre parçalara bölünür ve her parçada içerideki çarpım ayrıca hesaplanır.

Temel işaretler olarak birim basamak $u$, dürtü (Dirac delta) ve üçgen işaret hatırlatıldı. Hoca, birim basamaktan bir birim ötelenmiş basamağı çıkarmanın ($u(t)-u(t-1)$) bir birimlik kare darbe verdiğini gösterdi.

## 5. Grafik Yöntem: İki Birim Dikdörtgen Darbe

Soru: $x(t)$ ve $y(t)$, $0$–$1$ aralığında genliği 1 olan dikdörtgen darbelerdir. $f(t)=x(t)*y(t)$'yi bulun (ekrandan, 00:40:00).

### 5.1 Katlama ve Öteleme

$y(t-\tau)$'yu elde etmek için $t-\tau=-\tau+t$ biçiminde düşünülür (ekrandan, 00:45:00):

- Önce $y(-\tau)$ alınır: işaret dikey eksene göre katlanır ve $-1$ ile $0$ arasına gelir.
- Sonra $+t$ kadar ötelenir. Darbenin sağ kenarı $t$, sol kenarı $t-1$ noktasındadır.

$x(\tau)$ sabit kalır, katlanmış darbe $-\infty$'dan $+\infty$'a doğru gezdirilir ve her konumda iki işaretin karşılıklı çarpımı integrallenir. $t$'nin değerine göre farklı senaryolar ortaya çıkar.

### 5.2 Bölge 1: $t\le 0$

Katlanmış darbenin tamamı negatif taraftadır. Darbenin 1 olduğu yerlerde $x(\tau)=0$, $x(\tau)=1$ olduğu yerlerde ise $y(t-\tau)=0$'dır. Örtüşme (overlap) yoktur, çarpımlar hep sıfırdır (ekrandan, 00:50:00):

$$f(t)=\int_{-\infty}^{0}x(\tau)\,y(t-\tau)\,d\tau=0$$

### 5.3 Bölge 2: $0<t\le 1$

Darbenin sağ kenarı $x$'in içine $t$ kadar girmiştir. Örtüşme $[0,t]$ aralığındadır ve orada iki işaret de 1'dir (ekrandan, 00:55:00):

$$f(t)=\int_0^t 1\cdot 1\,d\tau=\tau\Big|_0^t=t$$

Hoca önce üst sınırı 1 yazdı, sonra tam örtüşmenin ancak $t=1$'de olacağını, ondan önceki bir $t$ anında örtüşmenin $0$–$t$ arası olduğunu söyleyerek düzeltti.

### 5.4 Bölge 3: $1<t<2$

Darbe $x$'i geçmeye başlar. Sağ kenar $t$, sol kenar $t-1$'dir; $x$ ise $1$'de biter. Bu yüzden integral $t-1$'den $t$'ye değil, $t-1$'den $1$'e alınmalıdır; yoksa integral yeniden bölünmek zorunda kalır (ekrandan, 01:15:00):

$$f(t)=\int_{t-1}^{1}1\cdot 1\,d\tau=1-(t-1)=2-t$$

### 5.5 Bölge 4: $t\ge 2$

Örtüşme kalmaz, $f(t)=0$.

### 5.6 Sonuç

$$f(t)=\begin{cases}0, & t\le 0 \text{ veya } t\ge 2\\ t, & 0<t\le 1\\ 2-t, & 1<t<2\end{cases}$$

(ekrandan, 01:15:00). Bir öğrenci tahtadaki eşitsizliğin yönünü sordu; hoca son satırın sınırını düzeltti ve sınır noktalarının ($t=1$, $t=2$) hangi bölgeye dahil edildiğinin süreksizlik nedeniyle önemli olmadığını söyledi.

Grafik, $0$'dan başlayıp $t=1$'de 1 değerine çıkan, $t=2$'de yeniden sıfıra inen bir üçgendir. $t=1$ anında iki darbe yüzde yüz örtüşür; konvolüsyonun en yüksek olduğu nokta iki işaretin en çok benzediği noktadır.

Hoca, sonraki derste çalışılmak üzere iki üçgen işaretin konvolüsyonunu önerdi: bu kez birlerin değil, $t$ ile $-t$ gibi değerlerin çarpılacağını, yine tam örtüşmede en yüksek değerin elde edileceğini söyledi.

## 6. Slayt Örneği: Bölgelere Ayırma Adımları

Hoca önceki derste anlatılan slayt örneğini adım adım tekrar etti (ekrandan, 01:05:00). Girişler şunlardır:

- $x(\tau)$: $0\le\tau\le 2$ aralığında genliği 2.
- $h(\tau)$: $0\le\tau\le 1$ aralığında genliği 3.

$h(t)$ sistem, $x(t)$ o sisteme verilen giriştir. Adımlar:

- **Adım 1:** İki işaret $\tau$ değişkeniyle yazılır.
- **Adım 2:** İkinci işaret katlanır: $h(-\tau)$.
- **Adım 3:** Katlanmış işaretin kenarları bulunur ($-1$ ve $0$).
- **Adım 4:** $t$ kadar ötelenir. Kenarlar $\tau_{L,t}=t-1$ ve $\tau_{R,t}=t$ olur. Negatif $t$ sola ($-\infty$'a doğru), pozitif $t$ sağa kaydırır.
- **Adım 5:** Örtüşme bölgeleri bulunur, her bölgede integral alınır.

Bölgeler (ekrandan, 01:05:00):

- **Bölge I ($t<0$):** Örtüşme yok, çünkü $\tau_{R,t}<0$. Sonuç 0.
- **Bölge II ($0\le t\le 1$):** Kısmi örtüşme; koşullar $\tau_{L,t}\le 0$ ($t\le 1$) ve $\tau_{R,t}\ge 0$ ($t\ge 0$). $\int_0^t 2\cdot 3\,d\tau=6t$.
- **Bölge III ($1\le t\le 2$):** $h$'nin bir birimlik darbesi tamamen $x$'in içindedir. Sonuç $6$ (plato).
- **Bölge IV ($2\le t\le 3$):** Darbe $x$'ten çıkmaya başlar. $\int_{t-1}^{2}6\,d\tau=6(3-t)=-6t+18$.
- **Bölge V ($t>3$):** Örtüşme yok, 0.

Hoca bunu bir trenin tünele girip çıkmasına benzetti: tünele girerken örtüşme artar, içerideyken sabit kalır, çıkarken azalır. Önceki örnekten farkı, $x$ daha uzun olduğu için tam örtüşmenin bir süre devam etmesi ve sonucun üçgen yerine yamuk olmasıdır.

Sonuç python ile sayısal konvolüsyonla doğrulandı ($t=0{,}5$'te 3, $t=1{,}5$'te 6, $t=2{,}5$'te 3).

Slayt dizisinin başka bir sayfasında konvolüsyonla $y(t)$ bulma süreci farklı $t$ değerleri ($-1$, $-0{,}5$, $0$, $0{,}5$, $1$, $1{,}5$, $2$) için gösterilmiştir. Sonuç $t=-1$'de başlayıp yükselen, $0$ ile $1$ arasında 2 değerinde platoda kalan ve $t=2$'de sıfıra inen bir eğridir (ekrandan, 01:10:00). Hoca bu eğrinin önce logaritmik gibi arttığını, kaydırılan dikdörtgen darbe tamamen içeride kaldığı sürece çarpımın değişmediğini, sonra azaldığını yorumladı.

## 7. Sistem Modeli, Dürtü Cevabı ve Konvolüsyon Özellikleri

### 7.1 Diferansiyel Denklemle Tanımlanan Sistemler

Bir sistem $n$. dereceden türevler içeren bir diferansiyel denklemle tanımlanabilir. Slayttaki örnekte sistem, $y$'nin türevi ile $3y$'nin toplamının $x(t)$'ye eşit olduğu bir denklemdir. Bu denklem çözülürse sistemin modeli bulunur; sonra modele istenen giriş verilir ve çıkış hesaplanır. Çıkışı bulmak için önce modeli bulmak gerekir.

Modeli bulmanın bir yolu dürtü cevabıdır (impulse response): sisteme birim dürtü uygulanırsa elde edilen cevap sistemin modelidir. Ardından konvolüsyon integraliyle herhangi bir girişin çıkışı bulunur. Slaytta süperpozisyon integrali ile konvolüsyon integrali birlikte verilmiştir; biri dürtü, diğeri başka bir fonksiyonla yazılır ve biri diğerinin özel halidir.

Hoca slayttan bir RC devresi örneğine kısaca değindi: devreye birim basamak (DC) giriş verildiğinde kondansatör geriliminin zamana göre değişimi konvolüsyonla bulunur; $t=0$'dan itibaren giriş 1 ile çarpılır ve çıkış $R$ ve $C$ değerlerine bağlı olarak yükselir. Hoca bu sayısal değerleri ezbere bilmediğini, diferansiyel denklem çözümünü bu derste anlatmayacağını, slayttaki örneklere bakılabileceğini söyledi. Slaytta Gauss eğrisine benzeyen bir konvolüsyon sonucu da gösterildi.

### 7.2 İki Boyutlu Konvolüsyon

İki boyutlu konvolüsyon görüntü üzerinde uygulanır. Bir yüz görüntüsünde göz aramak, konvolüsyonun örtüşme bilgisinin bir uygulamasıdır: sonucun tepe yaptığı yer aranan desenin bulunduğu yerdir.

### 7.3 Özellikler

- **Değişme:** $x*h=h*x$; işaretlerin sırası değişebilir.
- **Birleşme:** Seri (kaskat) bağlı sistemlerde $x$'i önce $h_1$ sonra $h_2$ ile konvolüsyona sokmak yerine önce $h_2$ sonra $h_1$ kullanılabilir (ekrandan, 01:40:00).
- **Dağılma:** Paralel bağlı iki sistem için $x*h_1+x*h_2=x*(h_1+h_2)$; iki sistemin toplamı tek bir sistem gibi alınabilir.

Hoca birim üçgen fonksiyonu üzerindeki slayt örneklerine de bakılmasını önerdi.

## 8. Dönüşümler Ne İşe Yarar

Hoca, öğrencilerin sık sık "dönüşüm yaptık da ne işimize yaradı" diye sorduğunu söyledi. Cevabın bir parçası konvolüsyondur. Örneğin z dönüşümünden elde edilen bir dizi olsun. $X(\Omega)$ ve $H(\Omega)$ ya da $X(z)$ ve $H(z)$ bulunursa konvolüsyon uzun uzun yapılmaz; doğrudan çarpma yapılır.

Slayttaki konvolüsyon özelliği (ekrandan, 01:35:00):

$$Y(\Omega)=H(\Omega)X(\Omega)\ \leftrightarrow\ y[n]=\mathrm{DTFT}^{-1}\{H(\Omega)X(\Omega)\}$$

$$Y(z)=H(z)X(z)\ \leftrightarrow\ y[n]=\mathcal{Z}^{-1}\{H(z)X(z)\}$$

$$\mathrm{DTFT}^{-1}\{X(\Omega)H(\Omega)\}=\mathcal{Z}^{-1}\{X(z)H(z)\}=x[n]*h[n]=\sum_{m=-\infty}^{\infty}x[m]\,h[n-m]$$

Algoritmik açıdan konvolüsyon çarpmadan daha maliyetlidir: her $n$ değeri için örtüşmeleri dikkate alarak çarpıp toplamak iç içe iki döngü gerektirir. Hoca, dürtü cevabının da sistemin z dönüşümü ile girişin z dönüşümü çarpılıp ters z dönüşümü alınarak bulunabileceğini söyledi. İleride $\tau$ düzlemine benzer şekilde $z$, $s$ ve $\Omega$ düzlemlerine geçilecektir.

## 9. Ayrık Zamanda Konvolüsyon Toplamı

### 9.1 Birim Dürtü

Ayrık birim dürtü (unit impulse) şöyle tanımlanır (ekrandan, 01:30:00):

$$\delta[n]=\begin{cases}1, & n=0\\ 0, & n\ne 0\end{cases}$$

Değişken $t$ ise sürekli, $n$ ise ayrık zamanlı gösterimdir.

### 9.2 İşaretin Dürtülerle Yazılması

Bir işaretin $\delta[n]$ ile konvolüsyonu, $n=0$'daki değeri 1 ile çarpıp diğerlerini bastırmak demektir. Herhangi bir ayrık işaret, her örneğin değeri kadar ölçeklenmiş ve o örneğin konumuna ötelenmiş dürtülerin toplamı olarak yazılır:

$$x[n]=\sum_{k=-\infty}^{\infty}x[k]\,\delta[n-k]$$

Hoca tahtaya bir dizi çizdi (ekrandan, 01:25:00) ve terimleri tek tek yazdı. Örneğin $x[-1]=2$ ise bu terim $2\,\delta[n-(-1)]=2\,\delta[n+1]$'dir; $x[2]=1$ ise $1\cdot\delta[n-2]$'dir. <!-- BELİRSİZ: Tahtadaki dizinin n=0 değeri altyazıda 3 olarak geçiyor, karede n=0'da çizgi görünmüyor; değerler n=-1:2, n=2:1, n=3:1, n=4:3 gibi okunuyor. --> Sistemin dürtülerle yazılmış bu haline, ayrık zamanlı bir sistem için birim dürtü cevabı $h[n]$ denir.

**Soru:** İlk yazılan ifadede katsayı $x[n]$ mi, $x[k]$ mi olmalı? **Cevap:** $x[k]$ olmalı. Sürekli zamandaki $\tau$ yerine $k$, $t$ yerine $n$ gelir; integral yerine toplam kullanılır.

### 9.3 Konvolüsyon Toplamı

Girişi dürtülerin toplamı olarak yazıp her ötelenmiş dürtünün cevabının ötelenmiş $h$ olduğunu kullanınca konvolüsyon toplamı elde edilir:

$$y[n]=x[n]*h[n]=\sum_{m=-\infty}^{\infty}x[m]\,h[n-m]$$

Sürekli zamanda bu işlem konvolüsyon integrali, ayrık zamanda konvolüsyon toplamıdır. Hoca, eski ders notlarında "causal" (nedensel) sözcüğünün yanlış yazıldığını, bunun "because" sözcüğünden hatırlanabileceğini söyledi.

### 9.4 Çözüm Yolları

Ayrık konvolüsyon iki yolla çözülür: grafik mantığıyla (görsel) ya da analitik. Ayrık zamanda integral, süreklilik, süreksizlik ve kritik nokta sorunları olmadığı için analitik çözüm daha kolaydır. Hoca sürekli zamanın integrallerinin çok uğraştırıcı olabileceğini söyledi.

Algoritma (ekrandan, 01:45:00):

- İki işaret yeni bir değişkenle ($i$, $k$ ya da $m$) yazılır.
- Biri katlanır.
- Her $n$ için katlanmış işaret $n$ kadar ötelenir; negatif $n$ sola, pozitif $n$ sağa öteleme demektir.
- Örtüşen örnekler karşılıklı çarpılır ve toplanır; sonuç $y[n]$'dir.

## 10. Ayrık Grafik Konvolüsyon Örnekleri

### 10.1 Birinci Örnek

Soru: Tüm $n$ için $y[n]=x[n]*h[n]$'yi bulun (ekrandan, 01:40:00).

- $x[0]=2,\ x[1]=2,\ x[2]=1$, diğer değerler 0.
- $h[n]=3$ ($n=0,1,2,3,4$), diğer değerler 0.

Hoca önce $h$'yi katlayarak anlattı, sonra slaytın $x$'i katladığını gösterdi. Slayttaki açıklamaya göre kısa olan işareti katlamak tercih edilir; çünkü daha az terim içeren işareti kaydırmak daha az işlem gerektirir. Hoca, sürekli zamanda $t$ ile $t^2$ örneğinde de aynı tercihin işlemi kısalttığını hatırlattı.

Adımlar:

- $n<0$: Katlanmış $x[-i]$ ötelenince $h$ ile örtüşme olmaz. $y[n]=0$ (ekrandan, 01:45:00).
- $n=0$: Yalnız bir örtüşme: $x[0]h[0]=2\cdot 3=6$. $y[0]=6$ (ekrandan, 00:05:00).
- $n=1$: İki örtüşme: $2\cdot 3+2\cdot 3=12$.
- $n=2$: Üç örtüşme: $2\cdot 3+2\cdot 3+1\cdot 3=15$.
- $n=3$ ve $n=4$: Yine üç örtüşme, $15$.
- $n=5$: $x[1]h[4]+x[2]h[3]=3\cdot 2+3\cdot 1=9$.
- $n=6$: $x[2]h[4]=3$.
- $n\ge 7$: $0$.

Sonuç: $y[n]=\{6,\ 12,\ 15,\ 15,\ 15,\ 9,\ 3\}$ ($n=0,\dots,6$). Python ile doğrulandı.

Slayttaki notta belirtildiği gibi bu tür işaretlerin konvolüsyonu önce yukarı doğru bir rampa (ramp up), sonra bir plato, sonra aşağı doğru bir rampa (ramp down) üretir. İşaretlerin kendisinde rampa olmasa da konvolüsyon dolaylı olarak bu biçimi verir. Bulunan tepe, en çok benzeyen noktayı söyler. Hoca bunun bir yüz görüntüsünde göz ya da burun aramak, mağaza raflarındaki ürün logolarını bularak ürünlerin düzenli dizilip dizilmediğini denetlemek gibi uygulamalara dayanak olduğunu anlattı.

### 10.2 İkinci Örnek

Slaytta bir konvolüsyon toplamı örneği daha gösterildi (ekrandan, 01:55:00):

- $x[-1]=2,\ x[0]=2,\ x[1]=2$.
- $h[0]=1,\ h[1]=2$.

$h[m]$ katlanır ($h[-m]$: $m=-1$'de 2, $m=0$'da 1), sonra $n$ kadar ötelenir ($h[n-m]$). Hesap:

- $n=-1$: $x[-1]h[0]=2\cdot 1=2$.
- $n=0$: $x[-1]h[1]+x[0]h[0]=2\cdot 2+2\cdot 1=6$.
- $n=1$: $x[0]h[1]+x[1]h[0]=4+2=6$.
- $n=2$: $x[1]h[1]=4$.

Sonuç: $y[n]=\{2,\ 6,\ 6,\ 4\}$ ($n=-1,\dots,2$). Hoca önce $n=-1$'de 4 dedi, sonra düzeltip ilk değerin 2, ardından 6, 6, 4 geldiğini söyledi. Sonuç python ile doğrulandı. Bu örnekte de rampa benzeri bir biçim görülür.

## 11. Fark Denklemleri ve Dürtü Cevabı

### 11.1 Diferansiyel ve Fark Denklemleri

Hoca sürekli ve ayrık zaman arasındaki karşılıkları özetledi:

| Sürekli zaman | Ayrık zaman |
|---|---|
| Konvolüsyon integrali | Konvolüsyon toplamı |
| Diferansiyel denklem (differential equation) | Fark denklemi (difference equation) |

Diferansiyel denklemler sürekli zamanı ifade eder; örnek olarak $y''+y'-2y^2=5$ gibi bir denklemin çözümünün zor olabileceğini söyledi. Diferansiyel denklemlerin homojen, sabit katsayılı gibi pek çok türü vardır ve bu uzun bir konudur. Hoca temel çözüm yöntemlerine ilerleyen haftalarda değinebileceğini ve MATLAB ile diferansiyel denklemin hızlıca nasıl çözüldüğünü göstereceğini söyledi.

Fark denklemleri rekürsif denklemlerdir, diziler üzerinde tanımlanır (ör. $a_n$'in önceki terimlerle ifade edilmesi). Rekürsif algoritmaların analizinde ayrık matematikte çözülürler. Diferansiyel denklemlere göre daha kolaydır, ama kendi güçlükleri vardır.

### 11.2 Slayt Örneği

Slaytta bir sistem şu fark denklemiyle tanımlanır (ekrandan, 01:50:00):

$$3y[n]+2y[n-1]+y[n-2]=x[n]$$

Hoca bunun sürekli zamandaki karşılığının ikinci türev, birinci türevin iki katı ve fonksiyonun kendisini içeren bir diferansiyel denklem olacağını, çözümünün daha zor olduğunu söyledi. Birim dürtü uygulanınca:

$$3h[n]+2h[n-1]+h[n-2]=\delta[n]$$

$n<0$ için $h[n]=0$ alınarak başlangıç değerleri bulunur:

- $n=0$: $3h[0]+2\cdot 0+0=1\Rightarrow h[0]=1/3$.
- $n=1$: $3h[1]+2\cdot\frac13+0=0\Rightarrow h[1]=-2/9$.

Homojen çözümün karakteristik kökleri $-0{,}333\pm j0{,}4714$'tür. $h[0]=K_1+K_2=1/3$ ve $h[1]=-2/9$ koşullarından $K_1=0{,}1665+j0{,}1181$, $K_2=0{,}1665-j0{,}1181$ bulunur (ekrandan, 01:50:00). Bu değerler python ile kontrol edildi (kökler $-\frac13\pm j\frac{\sqrt2}{3}$, katsayılar yaklaşık $0{,}1667\pm j0{,}1179$; slayttaki değerler yuvarlamayla uyumludur).

Hoca bu ayrıntılara girmedi. Fark denklemlerinin z dönüşümüyle cebirsel işlemlere (toplama, çıkarma, çarpma, bölme) indirgenebileceğini, bunun sonraki konularda işleneceğini söyledi.

### 11.3 Dürtü Cevabının Sezgisi

Hoca dürtü cevabını bir kara kutu benzetmesiyle anlattı. Sisteme $\delta[n-k]$ biçiminde ötelenmiş birim dürtüler uygulanır. Dürtünün sistemin sıfırdan farklı olduğu bir noktaya denk geldiği yerde sistemin o noktadaki değeri çıkışta görünür; örneğin sistemin 4. örneği 3 ise $3\cdot 1=3$ gelir. Bu, bir anlamda sistemin röntgenini çekmektir. Radar sinyalleri de böyledir: bir işaret gönderilir ve karşılığında gelen işaret, çarpım ve toplam işleminin sonucudur. Slaytlarda sinüzoidal ve üstel sistemlerle daha karmaşık sistem cevabı örnekleri de vardır.

Hoca slaytların fark denklemleri, z dönüşümü ve frekans cevabı kısımlarının sonraki konular olduğunu, o kısımların şimdilik atlanabileceğini söyledi. Kaynak olarak MIT'nin Signals and Systems ders notlarını ve video derslerini, ayrıca M. J. Roberts'ın 5. bölüm slaytlarını önerdi. Sonraki derslerde frekans düzlemine geçileceğini belirtti.

## 12. Konvolüsyon ve Polinom Çarpması

Ayrık zamanlı konvolüsyon aslında bir polinom çarpmasıdır. Tahtadaki örnek (ekrandan, 02:00:00):

$$(x^2+3x)\cdot(x^7-x^3)$$

Polinomların katsayıları dizi olarak yazılır: $x^2+3x$ için en büyük dereceden başlayarak $[1,\ 3]$; $x^7-x^3$ için $x^7$'nin katsayısı 1, $x^6$, $x^5$, $x^4$ yok, $x^3$'ün katsayısı var: $[1,\ 0,\ 0,\ 0,\ \pm1]$. Sıfırıncı dereceli terimler de istenirse eklenebilir.

Terim terim çarpınca $x^2\cdot x^7=x^9$, $3x\cdot x^7=3x^8$ gibi terimler gelir. Hoca baştaki terimlerin bir rampa gibi oluştuğunu, araya sıfırlar girdiğini gösterdi. Bir öğrenci katsayının eksi bir olup olmadığını sordu; hoca işareti artı alarak devam etti. Ardından katlama yöntemini denedi: dizilerden biri ters çevrilir ($[3,\ 1]$), önüne ve arkasına yeterince sıfır konur, her kaydırmada örtüşen katsayılar çarpılıp toplanır. Tahtada $1,\ 3,\ 1,\ 3$ değerleri (aradaki sıfırlarla) elde edildi (ekrandan, 02:05:00). Hoca örneği tam oturtamadığını, gerekirse sonraki derste döneceğini söyledi.

> **Ders sonrası not:** Katsayı dizilerinin konvolüsyonu $[1,3]*[1,0,0,0,1]=[1,3,0,0,1,3]$'tür. Bu, $(x^2+3x)(x^7+x^3)=x^9+3x^8+x^5+3x^4$ demektir. Tahtadaki ilk biçim olan $(x^2+3x)(x^7-x^3)$ için sonuç $x^9+3x^8-x^5-3x^4$'tür. İki sonuç python ile doğrulandı.

## 13. MATLAB'de Ayrık İşaret Çizimi ve Hazır Fonksiyonlar

Bir öğrenci MATLAB ve Python'u daha önce görmediklerini, konvolüsyonu C'de yazabileceklerini ama grafiğini çizdirmeyi bilmediklerini söyledi. Hoca MATLAB Online'da kısa bir gösterim yaptı (ekrandan, 02:10:00):

```matlab
T = 1:10;
x = 2*T;
stem(T, x)   % ayrık zamanlı çizim
plot(T, x)   % sürekli gibi görünen çizim
```

Çalışma alanında `T` $[1,2,3,\dots,10]$, `x` $[2,4,6,8,10,\dots]$ olarak görünür (ekrandan, 02:10:00). `stem` ayrık zamanlı işareti çubuklarla gösterir; `plot` noktaları birleştirir ve sürekliymiş gibi gösterir, ama gerçek anlamda sürekli değildir. Hoca bu çizim için döngü bilgisine gerek olmadığını söyledi.

Hazır konvolüsyon fonksiyonu `conv`'dur. `help conv` ya da `doc conv` ile belgeler açılır; belgede `u` ve `v` vektörlerinin konvolüsyonu gibi örnekler, parametreler ve çizim seçenekleri bulunur. İki boyutlu konvolüsyon için de ayrı bir fonksiyon vardır. Hoca Python'un MATLAB'in açık kaynak karşılığı gibi düşünülebileceğini, akademide ikisinin de kullanıldığını, Python'da hazır kütüphanenin daha fazla olduğunu ve kendisinin Python'u tercih ettiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Python'da aynı çizimler `matplotlib.pyplot.stem` ve `matplotlib.pyplot.plot` ile, hazır konvolüsyon ise `numpy.convolve` ile yapılır. `numpy.convolve(x, h)` varsayılan olarak tam ($N+M-1$ uzunluklu) konvolüsyonu verir.

## Örnek Sorular

### Soru 1 (ekrandan, 00:20:00)

$x(t)=t$ ve $y(t)=t^2$ için $f(t)=x(t)*y(t)=\int_0^t x(\tau)\,y(t-\tau)\,d\tau$'yu bulun.

> **Çözüm (derste verildi):** $\int_0^t\tau(t-\tau)^2d\tau=\frac{t^4}{4}-\frac{2t^4}{3}+\frac{t^4}{2}=\frac{t^4}{12}$. Değişme özelliğiyle $\int_0^t\tau^2(t-\tau)d\tau=\frac{t^4}{3}-\frac{t^4}{4}=\frac{t^4}{12}$ (ekrandan, 00:35:00). Sayısal integralle doğrulandı ($t=2$ için $16/12$).

### Soru 2 (ekrandan, 00:40:00)

$x(t)$ ve $y(t)$, $0\le t\le 1$ aralığında 1, başka yerde 0 olan dikdörtgen darbelerdir. $f(t)=x(t)*y(t)$'yi bulun ve çizin.

> **Çözüm (derste verildi):** $t\le 0$ veya $t\ge 2$ için $0$; $0<t\le 1$ için $\int_0^t d\tau=t$; $1<t<2$ için $\int_{t-1}^1 d\tau=2-t$. Grafik, tepesi $t=1$'de (değer 1) olan üçgendir (ekrandan, 01:15:00).

### Soru 3 (ekrandan, 01:05:00)

$x(\tau)$, $0$–$2$ aralığında genliği 2; $h(\tau)$, $0$–$1$ aralığında genliği 3 olan darbelerdir. $y(t)=x(t)*h(t)$'yi bölgelere ayırarak bulun.

> **Çözüm (derste verildi):** $t<0$: $0$; $0\le t\le 1$: $6t$; $1\le t\le 2$: $6$; $2\le t\le 3$: $-6t+18$; $t>3$: $0$. Python ile sayısal olarak doğrulandı.

### Soru 4 (ekrandan, 01:40:00)

$x[n]=\{2,2,1\}$ ($n=0,1,2$) ve $h[n]=3$ ($n=0,\dots,4$) için tüm $n$ değerlerinde $y[n]=x[n]*h[n]$'yi bulun.

> **Çözüm (derste verildi):** $y[n]=\{6,12,15,15,15,9,3\}$ ($n=0,\dots,6$), diğer $n$ için $0$. Python ile doğrulandı.

### Soru 5 (ekrandan, 01:55:00)

$x[-1]=x[0]=x[1]=2$, $h[0]=1$, $h[1]=2$ için $y[n]=\sum_m x[m]h[n-m]$'yi bulun.

> **Çözüm (derste verildi):** $y[-1]=2,\ y[0]=6,\ y[1]=6,\ y[2]=4$, diğer $n$ için $0$. Python ile doğrulandı.

### Soru 6 (ekrandan, 01:50:00)

$3h[n]+2h[n-1]+h[n-2]=\delta[n]$ ile tanımlanan sistemin $h[0]$ ve $h[1]$ değerlerini bulun ($n<0$ için $h[n]=0$).

> **Çözüm (slaytta verildi):** $h[0]=1/3$, $h[1]=-2/9$. Python ile özyinelemeli hesapla doğrulandı.

### Soru 7 (ekrandan, 02:00:00)

$(x^2+3x)(x^7-x^3)$ çarpımını katsayı dizilerinin konvolüsyonu olarak hesaplayın.

> **Çözüm (derste tamamlanmadı):** Katsayılar $[1,3]$ ve $[1,0,0,0,-1]$; konvolüsyon $[1,3,0,0,-1,-3]$, yani $x^9+3x^8-x^5-3x^4$. Derste işaret artı alınınca $[1,3,0,0,1,3]$, yani $x^9+3x^8+x^5+3x^4$ bulunur. Python ile doğrulandı.

### Soru 8 (derste sözlü, 02:02:17)

İki ayrık zamanlı diziyi (ör. 5 ve 3 elemanlı) alan ve konvolüsyonlarını hesaplayan bir fonksiyonu MATLAB ya da Python'da kendi algoritmanızla yazın. Üç farklı $(x,h)$ ikilisi için $x[n]$, $h[n]$ ve sonucu çizdirin, sonuçlarınızı hazır fonksiyonun (`conv`) sonucuyla karşılaştırın.

> **Çözüm (derste verilmedi):** İç içe iki döngüyle doğrudan tanım uygulanır; sonuç uzunluğu $N+M-1$'dir. Aşağıdaki kod yukarıdaki üç örnekle (Soru 4, 5 ve 7) denendi ve `numpy.convolve` ile aynı sonucu verdi.

```python
import numpy as np
import matplotlib.pyplot as plt

def konvolusyon(x, h):
    N, M = len(x), len(h)
    y = [0] * (N + M - 1)
    for n in range(N + M - 1):
        for k in range(N):
            if 0 <= n - k < M:
                y[n] += x[k] * h[n - k]
    return y

x = [2, 2, 1]
h = [3, 3, 3, 3, 3]
y = konvolusyon(x, h)          # [6, 12, 15, 15, 15, 9, 3]
print(y, list(np.convolve(x, h)) == y)

for i, (ad, d) in enumerate([("x[n]", x), ("h[n]", h), ("y[n]", y)]):
    plt.subplot(3, 1, i + 1)
    plt.stem(range(len(d)), d)
    plt.title(ad)
plt.tight_layout()
plt.show()
```

## Dersin Toparlaması

Bu derste konvolüsyonun sürekli ve ayrık zamandaki iki biçimi bir arada işlendi. Sürekli zamanda konvolüsyon, $\tau$ düzlemine geçip bir işareti katlayarak ve $t$ kadar öteleyerek kurulan bir integraldir. Sürekli ve pürüzsüz işaretlerde integral tek parçada alınabilir ($t*t^2=t^4/12$). Dikdörtgen darbe gibi süreksiz işaretlerde ise örtüşme bölgelerine ayırmak gerekir; sonuç üçgen ya da yamuk gibi parçalı bir fonksiyondur. Konvolüsyonun tepe noktası iki işaretin en çok benzediği yeri gösterir. Ayrık zamanda aynı fikir, ölçeklenmiş ve ötelenmiş dürtülerin toplamından türetilen konvolüsyon toplamıyla ifade edilir. Hesap integral gerektirmediği için daha kolaydır ve polinom çarpmasıyla aynı yapıdadır.

Hoca, dönüşüm düzlemlerinde (Fourier, Laplace, z) konvolüsyonun çarpmaya dönüştüğünü ve bundan sonraki derslerde frekans düzlemine geçileceğini söyledi. Fark denklemleri ve z dönüşümü de bu bağlamda ileride ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
