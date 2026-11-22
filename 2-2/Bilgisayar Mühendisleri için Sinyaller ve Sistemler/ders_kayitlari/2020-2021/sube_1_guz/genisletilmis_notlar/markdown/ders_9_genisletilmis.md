# Ders 9 Genişletilmiş Notu: Konvolüsyon Tekrarı ve Sürekli Zamanlı Fourier Serisine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynakları ve Planı
- 2. Konvolüsyonun Tekrarı
- 3. Sürekli Zamanda Konvolüsyon Örneği
- 4. Ayrık Zamanda Konvolüsyon Örneği
- 5. Zaman Uzayından Frekans Uzayına
- 6. Sinüzoitler ve DC Bileşen
- 7. Karmaşık Sinüzoitler ve LTI Sistemin Cevabı
- 8. Karmaşık Sayılar ve Euler Eşitliği
- 9. Fourier Serisinin Kavramsal Anlatımı
- 10. Fourier Serisi Tanımı ve Harmonik Fonksiyon
- 11. Diklik (Ortogonallik) ve Katsayıların Bulunması
- 12. Gerçel Fonksiyonların Fourier Serisi
- 13. Kitaptaki Gösterim
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kaynakları ve Planı

Ders iki kaynak üzerinden ilerledi. Konvolüsyonun hatırlatılması için SaS-05 slaytlarının soru kısmı kullanıldı. Hoca, bu dosyanın konu anlatımı yerine soru çözümlerinden yararlandığını söyledi. Konvolüsyon konusunda daha iyi anlatım sunduğu için M. J. Roberts'ın slaytlarına geçilmişti; Fourier analizi için de aynı serinin "Continuous-Time Fourier Methods" başlıklı Lecture 6 slaytları açıldı (ekrandan, 00:45:00). Dersin sonunda Schaum serisinin "Signals and Systems" kitabının 5. bölümünden ("Fourier Analysis of Time Signals and Systems") bir özet yapıldı (ekrandan, 02:40:00).

Plan şöyleydi: önce sürekli zamanlı bir konvolüsyon sorusu, sonra ayrık zamanlı bir konvolüsyon sorusu, ardından frekans uzayına geçiş. Hoca bu kısmın matematiksel ağırlıklı olduğunu, temel kavramları olabildiğince sade anlatacağını belirtti.

## 2. Konvolüsyonun Tekrarı

Bir sistem düşünelim: girişine $x(t)$ verildiğinde çıkışında $y(t)$, girişine $x[n]$ verildiğinde çıkışında $y[n]$ oluşur. Normal parantez ve $t$ değişkeni sürekli zamanı, köşeli parantez ve $n$ indisi ayrık zamanı gösterir.

Temel fikir şudur: sürekli bir $x(t)$ işareti yaklaşık olarak çok dar impulsların toplamıdır; ayrık bir $x[n]$ işareti ise kaydırılmış ve genlikleri $x[k]$ ile çarpılmış birim impulsların toplamıdır. Sistemin girişine birim impuls verildiğinde oluşan cevap, yani impuls cevabı $h$ biliniyorsa, impulsların toplamından oluşan her girişin çıkışı hesaplanabilir. Bu hesap iki işaretin konvolüsyonudur.

Ayrık durumda adımlar şöyledir:

- $\delta[n]$ girişinin cevabı $h[n]$'dir (impuls cevabı).
- Sistem zamanla değişmez olduğundan girişi kaydırmak çıkışı da kaydırır: $\delta[n-k] \to h[n-k]$.
- Sistem doğrusal olduğundan girişi bir skalerle çarpmak çıkışı da aynı skalerle çarpar: $x[k]\delta[n-k] \to x[k]h[n-k]$. Örneğin $x[0]=2$ ise o impuls 2 ile, $x[1]=-1$ ise $-1$ ile çarpılmış olur.
- Toplamsallıktan dolayı impulsları önce toplayıp sisteme vermek ile ayrı ayrı verip çıkışları toplamak aynı şeydir.

Böylece

$$y[n] = \sum_{k=-\infty}^{\infty} x[k]\,h[n-k]$$

elde edilir. Sürekli durumda toplamın yerini integral alır:

$$y(t) = \int_{-\infty}^{\infty} x(\tau)\,h(t-\tau)\,d\tau .$$

Burada $\tau$ integral değişkenidir; $t$ ise çıkışını aradığımız anı, yani $h$'nin ne kadar kaydırıldığını gösterir.

Slaytta nedensellik durumları da gösterildi (ekrandan, 00:05:00). Sistem nedenselse $h(t)=0$ ($t<0$), dolayısıyla $\tau > t$ için $h(t-\tau)=0$ olur ve üst sınır $t$'ye iner. Giriş nedenselse $x(t)=0$ ($t<0$) olur ve alt sınır $0$'a çıkar. İkisi birden nedenselse:

$$y(t) = \int_{0}^{t} x(\tau)\,h(t-\tau)\,d\tau .$$

Grafiksel yöntemde fonksiyonlardan biri sabit tutulur, diğeri ters çevrilir (katlanır, "fold"), sonra adım adım kaydırılarak sabit fonksiyonun üzerinden geçirilir. Her konumda iki fonksiyonun çarpımının altındaki alan bulunur. Hangi fonksiyonun ters çevrildiği fark etmez; ikisi de aynı sonucu verir.

## 3. Sürekli Zamanda Konvolüsyon Örneği

Slayttaki örnekte (ekrandan, 00:20:00 ve 00:25:00) giriş ve impuls cevabı birer dikdörtgen darbedir:

- $x(t) = 2$, $0 \le t \le 2$; dışarıda $0$.
- $h(t) = 3$, $0 \le t \le 1$; dışarıda $0$.

Giriş sabit tutuldu, impuls cevabı ters çevrildi. $h(t-\tau)$, $\tau$ ekseninde $[t-1,\ t]$ aralığında duran, yüksekliği 3, genişliği 1 olan bir darbedir. $t$ arttıkça bu darbe sağa kayar. Çakışma durumuna göre beş bölge oluşur.

**Bölge I, $t<0$:** Darbenin sağ kenarı $t$ henüz $0$'a ulaşmadı. Çakışma yok: $y(t)=0$.

**Bölge II, $0 \le t \le 1$:** Darbe $x$'in içine girmeye başlar. Çakışma aralığı $[0, t]$'dir:

$$y(t) = \int_0^t 2\cdot 3\, d\tau = 6t .$$

Bu, eğimi 6 olan bir doğrudur. Darbe tamamen içeri girene kadar ($t=1$) alan doğrusal olarak artar.

**Bölge III, $1 < t \le 2$:** Darbenin sol kenarı $t-1 > 0$, sağ kenarı $t \le 2$; yani darbe tamamen $x$'in içindedir (slayttaki koşullar: $t-1>0 \Rightarrow t>1$, $t\le 2$). Çakışma uzunluğu 1'dir:

$$y(t) = 2\cdot 3\cdot 1 = 6 .$$

**Bölge IV, $2 < t \le 3$:** Darbe dışarı çıkmaya başlar. Çakışma aralığı $[t-1, 2]$'dir:

$$y(t) = \int_{t-1}^{2} 6\, d\tau = 6\big(2-(t-1)\big) = -6t + 18 .$$

Eğimi $-6$ olan, azalan bir doğru.

**Bölge V, $t>3$:** Darbenin sol kenarı $t-1 > 2$; çakışma yok: $y(t)=0$.

Sonuç olarak çıkış (ekrandan, 00:25:00):

$$y(t)=\begin{cases}0, & t<0\\ 6t, & 0\le t\le 1\\ 6, & 1<t\le 2\\ -6t+18, & 2<t\le 3\\ 0, & t>3\end{cases}$$

Çıkış, 0'dan 1'e kadar yükselen, 1 ile 2 arasında 6'da sabit kalan, 2'den 3'e kadar düşen bir yamuktur. Değerler sayısal integralle de doğrulandı (ajan kontrolü: $t=0{,}5$'te 3, $t=1{,}5$'te 6, $t=2{,}5$'te 3).

> **Hocanın vurgusu:** Sürekli konvolüsyonda her bölgenin sınırlarına, yani $t$'nin hangi aralıkta olduğuna dikkat edilmelidir.

Hoca bu işlemin ayrık konvolüsyonla aynı olduğunu hatırlattı: ayrıkta da biri ters çevrilip adım adım kaydırılıyordu. Fark, süreklide çakışma alanının kaydırmayla sürekli değişmesi, bu yüzden sonucun $6t$ gibi bir fonksiyon olarak çıkmasıdır.

## 4. Ayrık Zamanda Konvolüsyon Örneği

Ayrık konvolüsyon da süreklinin aynısıdır; yalnız gösterim değişir. Ayrık işaretler sürekli impulsların değil ayrık impulsların toplamıdır, integral yerine $\Sigma$ kullanılır ve $k$ tam sayı değerleri alır.

Hoca konvolüsyonun Türkçede evrişim diye de anıldığını söyledi. Derin öğrenmede çok kullanılan evrişimsel sinir ağları (Convolutional Neural Networks) görüntü işleme ve sınıflandırmada kullanılır. Bu yapılar, insan görme sistemindeki farklı filtrelerin cevaplarını birleştirerek nesneleri tanıdığı varsayımından yola çıkar. Buradaki filtre, aslında bir sistemin impuls cevabıdır. Görüntü işleme ve bilgisayarla görü derslerinde bu impuls cevapları filtre, çekirdek (kernel) ya da maske diye anılır.

### 4.1 Problem

Slayttaki örnek (ekrandan, 00:30:00): tüm tam sayı $n$ değerleri için $y[n] = x[n] * h[n]$'i bulun.

- $x[n]$: $x[0]=2$, $x[1]=2$, $x[2]=1$, diğerleri $0$. Uzunluğu 3, sınırları $0$ ile $2$ arası.
- $h[n]$: $h[0]=h[1]=h[2]=h[3]=h[4]=3$, diğerleri $0$. Uzunluğu 5, sınırları $0$ ile $4$ arası.

Slayttaki çözüm, daha az işlem gerektirdiği için kısa olan $x[n]$'i ters çevirmeyi seçmiştir. Hoca bunun yazarın kişisel tercihi olduğunu, iki diziden herhangi birinin ters çevrilebileceğini vurguladı.

### 4.2 Çözüm

$h$ sabit tutulur:

$$y[n] = \sum_{i=-\infty}^{\infty} h[i]\,x[n-i] .$$

Değişkenin adı ($m$ ya da $i$) önemli değildir. $x[-i]$, $x$'in $i$ ekseninde katlanmış hâlidir; pozitif $n$ sağa kaydırma demektir (ekrandan, 00:40:00).

- $n<0$: Katlanmış $x$, $h$'nin solunda kalır; çakışma yok, $y[n]=0$.
- $n=0$: Yalnız $i=0$ çakışır: $y[0] = 3\cdot 2 = 6$.
- $n=1$: $i=0,1$ çakışır: $y[1] = 3\cdot 2 + 3\cdot 2 = 12$ (ekrandan, 00:40:00).
- $n=2$: Katlanmış $x$ tamamen $h$'nin altına girer: $y[2] = 3\cdot 1 + 3\cdot 2 + 3\cdot 2 = 15$.
- $n=3$: Hâlâ tamamen içeride: $y[3] = 15$.
- $n=4$: Yine tamamen içeride: $y[4] = 15$.
- $n=5$: Bir eleman sıfırla çarpılır: $y[5] = 3\cdot 1 + 3\cdot 2 = 9$.
- $n=6$: Yalnız bir eleman kalır: $y[6] = 3\cdot 1 = 3$.
- $n\ge 7$: Hepsi sıfırla çarpılır: $y[n]=0$.

Hoca slayttaki bazı adımlarda indis etiketlerinin yanlış yazıldığını belirtti; örneğin $n=4$ ve $n=5$ adımlarında katlanmış dizi $x[4-i]$ ve $x[5-i]$ olmalıdır.

Sonuç:

$$y[n] = \{6,\ 12,\ 15,\ 15,\ 15,\ 9,\ 3\},\quad n = 0,1,\dots,6 .$$

Sonuç Python ile `numpy.convolve([2,2,1], [3,3,3,3,3])` hesaplanarak doğrulandı (ajan kontrolü).

### 4.3 Çıkışın sınırları

$x$'in sınırları $0$-$2$, $h$'nin sınırları $0$-$4$'tür. Çıkışın sınırları bunların toplamıdır: başlangıç $0+0=0$, bitiş $2+4=6$. Hoca, sınırlar örneğin $-1$ ve $-2$ olsaydı başlangıcın $-3$ olacağını, yani gerçekten sayısal değerlerin toplanması gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu kuraldan çıkışın uzunluğu da bulunur: uzunluklar $L_x$ ve $L_h$ ise çıkış uzunluğu $L_x + L_h - 1$'dir. Bu örnekte $3+5-1=7$ eleman.

## 5. Zaman Uzayından Frekans Uzayına

Şimdiye kadar yapılan işlemlerin hepsi (sürekli ve ayrık konvolüsyon, örnekleme) zaman uzayındaydı. Ayrık işaret de aslında zamandan alınan örneklerdir: $x(t)$'de $t$ yerine $nT_s$ konur, $x[n] = x(nT_s)$. Burada $T_s = 1/f_s$ örnekleme periyodu, $f_s$ örnekleme frekansıdır; $n = 0, 1, 2, \dots$ için her seferinde $T_s$ kadar ilerlenerek analog işaretten örnek alınır.

Bundan sonra işaretler farklı bir şekilde, frekans uzayında incelenecek. Slayttaki ifade (ekrandan, 00:50:00) iki yöntemi karşılaştırır:

- Konvolüsyon yöntemi, sistemin doğrusallık ve zamanla değişmezlik özelliğinden yararlanır; uyarımı (excitation) impulsların doğrusal birleşimi, cevabı da impuls cevaplarının doğrusal birleşimi olarak yazar.
- Fourier serisi ise bir işareti karmaşık sinüzoitlerin doğrusal birleşimi olarak yazar.

Yani konvolüsyonda sisteme impulslar verip cevaplarını topluyorduk; Fourier analizinde sisteme sinüzoitler verip onlara olan cevabı bulmaya çalışacağız.

Fourier'nin fikri basitçe şudur: belirli bir aralıkta tanımlı herhangi bir fonksiyon, değişik frekanslardaki sonsuz sayıda sinüzoidin toplamı olarak yazılabilir. Slaytta Jean Baptiste Joseph Fourier'nin portresi ve yaşam tarihleri (1768-1830) gösterildi (ekrandan, 00:55:00).

## 6. Sinüzoitler ve DC Bileşen

Bir sinüzoit $A\cos(\omega t + \theta)$ biçimindedir (ekrandan, 00:55:00):

- $A$: genlik katsayısı. Kosinüs $-1$ ile $+1$ arasında değişir; $A$ bu boyutu büyütür ya da küçültür.
- $\omega = 2\pi f$: açısal frekans. Sinüzoidin ne kadar hızlı salındığını anlatır. "Açısal" denmesinin nedeni $2\pi$ ile çarpılmasıdır.
- $\theta$: faz.

Kosinüs ile sinüs birbirinin faz kaymış hâlidir; örneğin $\theta = 90^\circ$ olursa kosinüs eksi sinüse döner.

Periyot ve frekans arasındaki ilişki $T = 1/f$'dir. Periyot azaldıkça frekans artar. Sinüzoitlerin en önemli özelliği periyodik olmaları, yani belli bir $T$ süresinde kendilerini tekrar etmeleridir.

> **Ders sonrası not:** Hoca bir anda frekansı "bir çevrimin tamamlanma süresi" diye tarif etti. Doğrusu: bir çevrimin tamamlanma süresi periyottur ($T$); frekans birim zamandaki çevrim sayısıdır ($f = 1/T$).

**Soru:** Toplamdaki ilk bileşende hiç dalga, hiç çevrim yok; o nedir? **Cevap:** O, $f=0$ bileşenidir. $f=0$ (ve $\theta=0$) için $A\cos(0) = A$ sabittir. Buna DC bileşen denir ve işaretin ortalamasını verir.

Bir işaret, sabit bir DC kısım ile onun üzerine binmiş sinüzoidal bir AC kısmın toplamı olabilir. DC seviyeye ofset de denir. Her AC işaret sıfır ortalamalı olmak zorunda değildir: sıfır etrafında salınan bir işaretin ortalaması sıfırdır, bir ofset üzerine binmiş işaretin ortalaması ise o DC seviyedir. Hoca bunun osiloskopta görülebileceğini söyledi.

## 7. Karmaşık Sinüzoitler ve LTI Sistemin Cevabı

İşaret sonsuz sayıda sinüzoitten oluşuyorsa, bu sinüzoitleri sisteme ayrı ayrı verip cevaplarını toplayarak çıkış bulunabilir. Ancak gerçel sinüzoitler yerine karmaşık sinüzoitler, yani $e^{j\omega t}$ biçimindeki karmaşık üsteller verilir (ekrandan, 01:15:00). Euler eşitliğiyle

$$e^{j\omega t} = \cos\omega t + j\sin\omega t$$

yazılır; kosinüslü kısım gerçel, sinüslü kısım sanal kısımdır. Karmaşık üstel, bir sinüzoidal fonksiyon gibi düşünülebilir. Kullanılmasının yararı sonraki derslerde daha iyi anlaşılacaktır.

Slayttaki "Linearity and Superposition" ilkesi şudur: bir uyarım karmaşık sinüzoitlerin toplamı olarak yazılabiliyorsa, LTI sistemin cevabı da karmaşık sinüzoitlere olan cevapların toplamıdır (ekrandan, 01:15:00 ve 01:25:00):

$$x(t) = A_1 e^{j2\pi t/T_1} + A_2 e^{j2\pi t/T_2} + A_3 e^{j2\pi t/T_3} \ \longrightarrow\ h(t) \ \longrightarrow\ y(t) .$$

Hoca bunu şöyle kurdu: $\cos(2\pi f_1 t) + \cos(2\pi f_2 t)$ gibi farklı frekanslı bileşenler karmaşık gösterimde $e^{j\omega_1 t} + e^{j\omega_2 t}$, yani $e^{j2\pi f_1 t} + e^{j2\pi f_2 t}$ olur. $f = 1/T$ olduğu için bu $e^{j2\pi t/T_1} + e^{j2\pi t/T_2}$ diye de yazılır. Başlardaki $A_1, A_2, A_3$ bu karmaşık üstellerin genlikleridir. Yani $x(t)$, değişik genlikli karmaşık üstellerin toplamıdır.

Her bileşen sisteme ayrı ayrı sokulduğunda çıkış $B_1 e^{j2\pi t/T_1}$, $B_2 e^{j2\pi t/T_2}$, $B_3 e^{j2\pi t/T_3}$ olur. Sistem bileşenin katsayısını değiştirir ama frekansını değiştirmez. Çıkışlar toplanarak $y(t)$ bulunur. Bu, kaydırılmış impulsları tek tek sisteme verip toplamaya benzer; burada impulslar yerine farklı frekanslı sinüzoitler vardır. Toplamsallık doğrusallıktan, kaydırma özelliği zamanla değişmezlikten geldiği için sistemin LTI olması gerekir.

Hoca gerçek işaretlerde bazı frekansların hiç bulunmayabileceğini, bulunan frekansların katkılarının da farklı olduğunu belirtti: biri 1, biri 0,1, biri 0,001 genlikle girebilir; genliği 0 olan frekans o işarette yok demektir. Rastgele (arbitrary) bir işaret düşük frekanslardan, ya da düşük ve bazı yüksek frekanslardan oluşabilir. İlk derslerde anlatıldığı gibi gerçek hayattaki işaretlerin bir en yüksek frekansı vardır.

## 8. Karmaşık Sayılar ve Euler Eşitliği

### 8.1 Kartezyen ve kutupsal gösterim

Karmaşık sayı $z = a + jb$ biçimindedir (ekrandan, 01:30:00). İki eksende gösterilir: gerçel eksende $a$, sanal eksende $b$. İkisinin birlikte belirlediği nokta $z$'dir. Gerçel bir sayı gibi tek bir değer değildir.

Aynı nokta kutupsal olarak da gösterilebilir: başlangıçtan noktaya olan uzaklık $r$ ve gerçel eksenle yapılan açı $\theta$:

$$r = |z| = \sqrt{a^2 + b^2}, \qquad \theta = \tan^{-1}\!\left(\frac{b}{a}\right).$$

$|z|$'ye $z$'nin normu, büyüklüğü (magnitude) ya da genliği (amplitude) denir. $\theta$, tanjantın ters fonksiyonu (arktanjant) ile bulunur. İki gösterim de aynı noktayı ifade eder.

> **Ders sonrası not:** Hoca $|z|$ için "gücü manasında" dedi. $|z|$ büyüklüktür; güç büyük olasılıkla büyüklüğün karesiyle orantılı bir niceliktir.

### 8.2 Karmaşık üstelin görselleştirilmesi

$e^{j2\pi t}$ de bir karmaşık sayı üretir: $\cos 2\pi t + j\sin 2\pi t$. Gerçel kısmı kosinüs gibi, sanal kısmı sinüs gibi değişir. Gerçel eksen, sanal eksen ve zaman ekseniyle üç boyutlu düşünülürse: $t=0$'da $\sin 0 = 0$, $\cos 0 = 1$ olduğu için nokta gerçel eksende 1'dedir. $t$ büyüdükçe sanal bileşen de oluşur ve nokta zaman ekseni boyunca bir yay gibi sarmal çizer (ekrandan, 01:35:00). $e^{-j2\pi t}$ ise aynı sarmalı ters yönde çizer.

Bu iki sarmal toplanıp 2'ye bölünürse sanal kısımlar birbirini götürür ve gerçel düzlemde salınan $\cos(2\pi t)$ kalır. Biri diğerinden çıkarılıp $j2$'ye bölünürse gerçel kısım kaybolur ve sanal düzlemde salınan bir sinüzoit, yani $\sin(2\pi t)$ çıkar.

### 8.3 Çift ve tek fonksiyonlar, Euler'den kosinüs ve sinüs

Hoca bunu cebirsel olarak da gösterdi (ekrandan, 01:40:00):

$$e^{jx} = \cos x + j\sin x, \qquad e^{-jx} = \cos(-x) + j\sin(-x).$$

**Soru (hocadan):** $\cos(-x)$ nedir? **Cevap:** Kosinüste $x$ kadar da $-x$ kadar da gidilse aynı genlik değeri alınır; kosinüs çift (even) fonksiyondur: $\cos(-x) = \cos x$.

Sinüste ise $x$ ve $-x$ noktalarındaki değerlerin mutlak değerleri aynı, işaretleri terstir; sinüs tek (odd) fonksiyondur: $\sin(-x) = -\sin x$. Bu yüzden

$$e^{-jx} = \cos x - j\sin x .$$

İki eşitlik taraf tarafa toplanırsa $e^{jx} + e^{-jx} = 2\cos x$, çıkarılırsa $e^{jx} - e^{-jx} = 2j\sin x$ olur:

$$\cos x = \frac{e^{jx} + e^{-jx}}{2}, \qquad \sin x = \frac{e^{jx} - e^{-jx}}{j2}.$$

Yani gerçel kısmı (kosinüslü bileşeni) bulmak için artılı ve eksili karmaşık üsteller toplanıp 2'ye bölünür; sanal kısım (sinüslü bileşen) için biri diğerinden çıkarılıp $2j$'ye bölünür. Fourier'nin karmaşık üstel kullanmasının nedeni, işaretlerin daha genel bir biçimde anlatılabilmesidir.

## 9. Fourier Serisinin Kavramsal Anlatımı

Fourier serisi bir işareti sinüzoidal fonksiyonların toplamı olarak ifade eder. Önce periyodik bir işaret düşünülür: örneğin $t_0$ ile $t_0+T$ arasındaki parça kendini her iki yönde tekrar ediyor. Hoca tahtada $-T/2$ ile $T/2$ arasında tanımlı bir parçanın $T/2+T$'ye kadar tekrar ettiğini çizdi (ekrandan, 01:45:00).

Slayttaki örnek (ekrandan, 01:45:00), 0 ile 1 arasında gidip gelen periyodik bir üçgen dalgadır ("Exact $x(t)$", kesikli çizgi). Amaç, bu işarete adım adım yaklaşmaktır.

**Yalnız sabitle yaklaşım:** Elimizde yalnız bir sabit, yani sıfır frekanslı bir kosinüs varsa, en iyi yaklaşım işaretin ortalamasıdır. Bu işaret 0 ile 1 arasında gidip geldiği için ortalaması 0,5'tir.

**Sabit artı bir sinüzoit:** Ortalamanın üzerine, temel frekansı işaretinkiyle aynı olan bir sinüzoit eklenir (ekrandan, 01:50:00). Temel frekans (fundamental frequency), işareti oluşturan en temel sinüzoidin frekansıdır: $f_0 = 1/T_0$, burada $T_0$ işaretin tekrar periyodudur. Yaklaşım iyileşir ama üçgenle tam örtüşmez; demek ki başka sinüzoitler de vardır.

> **Hocanın vurgusu:** Temel frekansı yakalamak önemlidir. Yaklaşımda kullanılan temel periyot işaretin periyoduyla aynı olmalıdır ki işaret doğru yakalansın.

**Sabit artı iki sinüzoit:** Temel frekansın iki katı ($2f_0$) frekanslı bir sinüzoit daha eklenir; yaklaşım orijinal işarete daha da yaklaşır, ama hâlâ hafif dalgalanmalar vardır.

**Üçüncü sinüzoit:** Slayttaki bu özel örnekte üçüncü sinüzoidin genliği sıfırdır. Yani o frekanstaki bileşen bu işaretin içinde bulunmaz. Hoca bunun genel bir durum olmadığını, bu işarete özgü olduğunu belirtti. Ekranda gözle tahmin edilen genlikler, temel sinüzoit için yaklaşık 0,5, sonraki için yaklaşık 0,1 civarındaydı. <!-- BELİRSİZ: Hoca bir yerde genliği sıfır olan bileşeni "3f0" diye andı; slaytta yalnız "üçüncü sinüzoit" yazıyor, harmonik numarası karelerden kesinleşmedi. -->

**Dört sinüzoit:** Bir sinüzoit daha eklenince yaklaşım iyice üçgene benzer (ekrandan, 01:55:00). Slayttaki ifadeye göre bu iyi bir yaklaşımdır ve temel frekansın daha yüksek tam katlarındaki sinüzoitler eklendikçe daha da iyileşir.

## 10. Fourier Serisi Tanımı ve Harmonik Fonksiyon

Kavramsal anlatımın genel ifadesi şudur (ekrandan, 02:00:00): $x(t)$ işaretinin $t_0 < t < t_0+T$ aralığındaki Fourier serisi gösterimi

$$x(t) = \sum_{k=-\infty}^{\infty} c_x[k]\, e^{j2\pi k t / T}$$

biçimindedir. Hoca üsteki ifadeyi şöyle açıkladı: $e^{j2\pi (k f) t}$ yazılırsa $k$, temel frekansın kaç katı olduğunu gösterir; temel frekans $f = 1/T$ olduğundan bu $e^{j2\pi kt/T}$ olur. $k = 0, 1, 2, 3, \dots$ için sırasıyla sabit, temel frekans, iki katı, üç katı... elde edilir.

- $c_x[k]$ (kısaca $c_k$): harmonik fonksiyon. Her harmoniğin genlik katsayısıdır; önceki örnekte bir bileşenin genliği yaklaşık 0,5, birininki yaklaşık 0,1, birininki 0'dı. Bu katsayılar ilgili karmaşık sinüzoitlerle çarpılıp toplandığında ana işaret elde edilir.
- $k$: harmonik numarası. Temel sinüzoidin tam sayı katlarına harmonik denir.

Harmonik fonksiyon işaretten diklik (ortogonallik) ilkesiyle bulunur.

## 11. Diklik (Ortogonallik) ve Katsayıların Bulunması

### 11.1 İç çarpım

İki fonksiyonun iç çarpımı (inner product) şöyle tanımlanır (ekrandan, 02:15:00):

$$\big(x_1(t), x_2(t)\big) = \int_{t_0}^{t_0+T} x_1(t)\, x_2^*(t)\, dt .$$

İkinci fonksiyon karmaşıksa onun eşleniği alınır. Bu iç çarpım sıfırsa iki fonksiyon $t_0 < t < t_0+T$ aralığında diktir (ortogonaldir). Genelde aralık $0$ ile $T$ arası verilir; $t_0$ yazılması, fonksiyonun kendini tekrar ettiği herhangi bir periyot aralığında hesap yapılabileceğini genel olarak göstermek içindir.

### 11.2 Eşlenik

$z = a + jb$ ise eşleniği $z^* = a - jb$'dir. Karmaşık üstel için:

$$\big(e^{j\omega t}\big)^* = \big(\cos\omega t + j\sin\omega t\big)^* = \cos\omega t - j\sin\omega t = e^{-j\omega t}.$$

Yani $e^{jx}$'in eşleniğini almak üsteki işareti eksi yapmaktır: kosinüs çift olduğu için değişmez, sinüslü (sanal) kısmın işareti döner.

**Soru:** Çarpım için devriğini de (transpoz) almamız gerekiyor mu? Matrislerde öyle yapılıyor. **Cevap:** Şu anda matrislerle değil, sürekli zamanda skaler değerli fonksiyonlarla çalışıyoruz; bu yüzden yalnız eşlenik alınır. Matris durumunu şimdilik karıştırmamak gerekir.

### 11.3 İki karmaşık sinüzoidin iç çarpımı

$k$ ve $q$ tam sayı olmak üzere $e^{j2\pi kt/T}$ ve $e^{j2\pi qt/T}$ alınsın (frekansları $kf$ ve $qf$). İkincinin eşleniğiyle çarpılınca üsler birleşir:

$$\big(e^{j2\pi kt/T}, e^{j2\pi qt/T}\big) = \int_{t_0}^{t_0+T} e^{j2\pi kt/T} e^{-j2\pi qt/T}\, dt = \int_{t_0}^{t_0+T} e^{j2\pi (k-q)t/T}\, dt .$$

İki durum vardır:

- $k = q$: Üs sıfırdır; $\cos 0 + j\sin 0 = 1$. İntegral $\int_{t_0}^{t_0+T} 1\, dt = T$ olur.
- $k \ne q$: Aradaki fark sıfırdan farklı bir tam sayıdır. Aralıkta tam sayıda çevrim oluştuğu için kosinüs ve sinüslerin integrali sıfırdır.

Demek ki $k \ne q$ olduğunda $e^{j2\pi kt/T}$ ile $e^{j2\pi qt/T}$ diktir.

### 11.4 Katsayıların türetilmesi

Fourier serisi ifadesinin iki tarafı $e^{-j2\pi qt/T}$ ile çarpılıp ($q$ tam sayı) $[t_0, t_0+T]$ üzerinde integrali alınır. $k$ ile $t$ bağımsız değişkenler olduğu için (ekrandan, 02:25:00):

$$\int_{t_0}^{t_0+T} x(t)\, e^{-j2\pi qt/T}\, dt = \sum_{k=-\infty}^{\infty} c_x[k] \int_{t_0}^{t_0+T} e^{j2\pi(k-q)t/T}\, dt .$$

Sağdaki integral $k\ne q$ için $0$, $k=q$ için $T$'dir. Toplamda yalnız $k=q$ terimi kalır:

$$\int_{t_0}^{t_0+T} x(t)\, e^{-j2\pi qt/T}\, dt = c_x[q]\,T \quad\Rightarrow\quad c_x[q] = \frac{1}{T}\int_{t_0}^{t_0+T} x(t)\, e^{-j2\pi qt/T}\, dt .$$

$q$ yerine yeniden $k$ yazılırsa:

$$c_x[k] = \frac{1}{T}\int_{t_0}^{t_0+T} x(t)\, e^{-j2\pi kt/T}\, dt .$$

İşaret ile harmonik fonksiyonu bir Fourier serisi çifti oluşturur; biri diğerinden elde edilebilir. $c_x[k]$ biliniyorsa her biri $e^{j2\pi kt/T}$ ile çarpılıp $k = -\infty$'dan $\infty$'a toplanarak $x(t)$ bulunur. Katsayıları bulmak için ise $x(t)$, $e^{-j2\pi kt/T}$ ile çarpılıp periyot boyunca integrali alınır ve $T$'ye bölünür.

### 11.5 Temsil süresi

$T$, gösterimin temsil süresidir (representation time). $T$, $x(t)$'nin temel periyoduyla aynıysa bulunan katsayılar periyodik fonksiyon için bütün zamanlarda geçerlidir. $T$, $x(t)$'nin periyodu değilse gösterim yalnız o aralıkta geçerlidir. Hoca bunun mühendislik uygulamalarındaki frekans kavramına yaklaşmanın başlangıcı olduğunu söyledi.

## 12. Gerçel Fonksiyonların Fourier Serisi

Gerçel değerli herhangi bir $x(t)$ fonksiyonunun sürekli zamanlı Fourier serisi (CTFS) harmonik fonksiyonu şu özelliğe sahiptir (ekrandan, 02:30:00):

$$c_x[k] = c_x^*[-k] .$$

Yani $k$ için bulunan katsayı, $-k$ için bulunan katsayının eşleniğidir: $k$ için $a+jb$ bulunduysa $-k$ için $a-jb$ bulunur. Bunun sonucu olarak gerçel fonksiyonlarda harmonik fonksiyonun büyüklüğü çift, fazı tek fonksiyondur.

Hoca bunun ileride frekans gösteriminde görüleceğini söyledi: gerçel bir işaretin frekans gösteriminde negatif frekanslar pozitif frekanslarla simetriktir.

## 13. Kitaptaki Gösterim

Son kısımda Schaum serisinin "Signals and Systems" kitabının 5. bölümüne geçildi (ekrandan, 02:40:00). Hoca bu kitabın LTI sistemlerden sonra 3. ve 4. bölümlerde önce Laplace ve z dönüşümüne geçtiğini, bu derste ise önce frekans kavramlarının gösterilmesinin tercih edildiğini, bu yüzden doğrudan 5. bölüme (s. 211) geçildiğini anlattı.

Periyodik işaret, bir $T$ için

$$x(t+T) = x(t)$$

eşitliğini sağlayan işarettir; belli bir süreden sonra aynı değerleri tekrar alır. Temel periyot $T_0$, bu eşitliği sağlayan en küçük pozitif $T$ değeridir; $f_0 = 1/T_0$ temel frekanstır. Periyodik işaretlere iki temel örnek gerçel sinüzoit $x(t) = \cos(\omega_0 t + \phi)$ ve karmaşık üstel $x(t) = e^{j\omega_0 t}$'dir. Burada

$$\omega_0 = \frac{2\pi}{T_0} = 2\pi f_0$$

temel açısal frekanstır. Hoca, temel frekansın üzerine başka frekansların da binebileceğini $\cos(\omega_0 t) + \cos(2\omega_0 t) + \tfrac{1}{2}\cos(5\omega_0 t)$ gibi bir ifadeyle gösterdi.

Temel periyodu $T_0$ olan periyodik bir işaretin karmaşık üstel Fourier serisi gösterimi:

$$x(t) = \sum_{k=-\infty}^{\infty} c_k\, e^{jk\omega_0 t}, \qquad \omega_0 = \frac{2\pi}{T_0} .$$

$e^{jk\omega_0 t} = e^{jk2\pi f_0 t} = e^{j2\pi kt/T_0}$ olduğu için bu, Roberts'ın gösterimiyle aynıdır. $c_k$'lar karmaşık Fourier katsayılarıdır (Roberts'taki $c_x[k]$). Hoca $c_x[k]$ gösteriminin, $x$ işaretinin $k$. harmoniğinin katsayısı olduğunu daha açık gösterdiği için daha mantıklı bulduğunu söyledi. Katsayılar daha önce türetildiği gibi

$$c_k = \frac{1}{T_0}\int_{T_0} x(t)\, e^{-jk\omega_0 t}\, dt$$

ile bulunur. İntegral $[0, T_0]$ aralığında alınabileceği gibi $[-T_0/2, T_0/2]$ aralığında da alınabilir.

## Örnek Sorular

### Soru 1: Sürekli zamanlı konvolüsyon

(ekrandan, 00:20:00 ve 00:25:00)

$x(t) = 2$ ($0 \le t \le 2$), $h(t) = 3$ ($0 \le t \le 1$), dışarıda ikisi de sıfır. $y(t) = x(t) * h(t)$'yi bulun.

> **Çözüm (derste verildi):** $h(t-\tau)$, $[t-1, t]$ aralığında yüksekliği 3 olan bir darbedir. $t<0$: $y=0$. $0\le t\le 1$: $y = \int_0^t 6\,d\tau = 6t$. $1<t\le 2$: $y = 6$. $2<t\le 3$: $y = \int_{t-1}^{2} 6\,d\tau = -6t+18$. $t>3$: $y=0$. Çıkış, tepesi 6 olan bir yamuktur.

### Soru 2: Ayrık zamanlı grafiksel konvolüsyon

(ekrandan, 00:30:00)

$x[n] = \{2, 2, 1\}$ ($n = 0, 1, 2$), $h[n] = \{3, 3, 3, 3, 3\}$ ($n = 0, \dots, 4$), diğer indislerde sıfır. Tüm tam sayı $n$ değerleri için $y[n] = x[n]*h[n]$'yi bulun.

> **Çözüm (derste verildi):** $y[n] = \sum_i h[i]x[n-i]$, kısa olan $x$ ters çevrilir. $y[0]=6$, $y[1]=6+6=12$, $y[2]=y[3]=y[4]=3+6+6=15$, $y[5]=3+6=9$, $y[6]=3$; $n<0$ ve $n\ge 7$ için $y[n]=0$. Çıkışın sınırları $0+0=0$ ile $2+4=6$ arasıdır.

### Soru 3: Sabit bileşenin anlamı

(derste sözlü, 00:56:08)

Bir işareti oluşturan sinüzoitlerin toplamındaki $f=0$ bileşeni neyi ifade eder?

> **Çözüm (derste verildi):** $f=0$ için $A\cos(2\pi\cdot 0\cdot t) = A$ sabittir; çevrim yoktur. Bu DC bileşendir ve işaretin ortalamasını verir.

### Soru 4: Kosinüs ve sinüsün çift/tek olması

(derste sözlü, 01:36:02 ve 01:38:13)

$\cos(-x)$ nedir? $e^{-jx} = \cos(-x) + j\sin(-x)$ ifadesi sadeleştirilirken sinüslü terimin önüne artı mı, eksi mi gelir?

> **Çözüm (derste verildi):** Kosinüs çift fonksiyondur, $\cos(-x) = \cos x$. Sinüs tek fonksiyondur, $\sin(-x) = -\sin x$; bu yüzden eksi gelir: $e^{-jx} = \cos x - j\sin x$. Buradan $\cos x = (e^{jx}+e^{-jx})/2$ ve $\sin x = (e^{jx}-e^{-jx})/(j2)$ bulunur.

### Soru 5: Üçgen dalgaya sabitle yaklaşım

(ekrandan, 01:45:00; derste sözlü, 01:45:45)

0 ile 1 arasında gidip gelen periyodik üçgen dalgaya yalnız bir sabitle yaklaşılacaksa hangi sabit kullanılır?

> **Çözüm (derste verildi):** İşaretin ortalaması kullanılır. 0 ile 1 arasında gidip gelen bu üçgen dalganın ortalaması 0,5'tir.

## Dersin Toparlaması

Ders konvolüsyonun hatırlatılmasıyla başladı. LTI sistemin çıkışı, girişin kaydırılmış ve ölçeklenmiş impulslara ayrılması ve impuls cevabının kullanılmasıyla bulunur. Sürekli örnekte iki dikdörtgen darbenin konvolüsyonu beş bölgede hesaplandı ve yamuk biçimli bir çıkış elde edildi. Ayrık örnekte $\{2,2,1\}$ ile $\{3,3,3,3,3\}$'ün konvolüsyonu $\{6,12,15,15,15,9,3\}$ olarak bulundu ve çıkış sınırlarının giriş sınırlarının toplamı olduğu gösterildi.

İkinci kısımda frekans uzayına geçildi. İmpulslar yerine karmaşık sinüzoitler kullanılırsa, LTI sistemin cevabı her sinüzoide olan cevapların toplamı olur ve sistem frekansı değiştirmez. Karmaşık sayılar, Euler eşitliği ve kosinüs ile sinüsün karmaşık üstellerle yazılışı hatırlatıldı. Üçgen dalga örneğiyle Fourier serisinin sabit ve harmoniklerle adım adım yaklaşma fikri gösterildi. Diklik ilkesiyle katsayıların $c_x[k] = \frac{1}{T}\int_{t_0}^{t_0+T} x(t)e^{-j2\pi kt/T}dt$ formülü türetildi ve gerçel işaretlerde $c_x[k] = c_x^*[-k]$ olduğu görüldü. Ders, kitaptaki $\omega_0$ gösterimiyle kapandı. Hoca, sonraki derste kitabın bu kısmından, trigonometrik Fourier serisiyle devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
