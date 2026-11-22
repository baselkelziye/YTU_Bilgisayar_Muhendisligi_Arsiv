# Ders 14 Genişletilmiş Notu: z-Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaynaklar ve dönüşümlerin genel tablosu
- 2. LTI sistem, impuls cevabı ve frekans cevabı tekrarı
- 3. z-dönüşümünün tanımı
- 4. Yakınsaklık bölgesi ve ilk örnekler
- 5. Kutup-sıfır grafiği ve z düzlemi
- 6. Türkçe slaytlardan tekrar: temel diziler ve iki taraflı dizi
- 7. Yakınsaklık bölgesinin özellikleri
- 8. z-dönüşümünün özellikleri
- 9. Kutup-sıfır gösterimi ve MATLAB uygulaması
- 10. Transfer fonksiyonu
- 11. Ters z-dönüşümü
- 12. Ters dönüşüm ve ROC örnekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Kaynaklar ve dönüşümlerin genel tablosu

Dersin konusu z-dönüşümüdür. Hoca iki kaynak kullandı. Önce Schaum serisinin Signals and Systems kitabının 4. bölümünden ("The z-Transform and Discrete-Time LTI Systems") anlattı. Hoca Laplace ve z-dönüşümünü en iyi bu kitabın anlattığını, hem özlü hem soru açısından zengin olduğunu söyledi. Sonra "İşaret ve Sistemler" başlıklı Türkçe z-dönüşümü slaytlarına geçti (SlideZtransform). Bu slaytlarda konu daha kısa ve özet biçimde verilir.

Ders bir tekrarla başladı. İşaretler iki grupta incelenir: sürekli zamanlı $x(t)$ ve ayrık zamanlı $x[n]$ (ekrandan, 00:10:00). Sürekli zamanlı işaretin frekans içeriği sürekli zamanlı Fourier dönüşümüyle (CTFT) $X(\omega)$ olarak, ayrık zamanlı işaretinki ayrık zamanlı Fourier dönüşümüyle (DTFT) $X(\Omega)$ ya da $X(e^{j\Omega})$ olarak bulunur. İki dönüşümde de frekans sürekli bir değişkendir, yani sonuç frekansın sürekli bir fonksiyonudur.

Sürekli zamanda frekans $0$'dan $\infty$'a uzanır. İşaret ayrıklaştırılınca sayısal frekans kavramı gelir; bu frekans $[0,2\pi)$ ya da $[-\pi,\pi)$ aralığında incelenir ve sonsuza gitmez. DTFT'deki $2\pi$ aralığı $N$ parçaya bölünürse hem zaman örnekleri hem frekans ayrık olur. Bu, ayrık Fourier dönüşümüdür (DFT), $X[k]$ ile gösterilir. Hoca DFT ve ilgili konuların sayısal işaret işleme dersinde ayrıntılı işleneceğini söyledi.

Fourier dönüşümünün daha genel biçimleri de vardır. Önceki derste görülen Laplace dönüşümü CTFT'nin genelleştirilmiş hâlidir. Bu derste görülecek z-dönüşümü de DTFT'nin genelleştirilmiş hâlidir (ekrandan, 00:20:00). Laplace dönüşümü integral-diferansiyel denklemleri cebirsel ifadelere çevirir. z-dönüşümü de fark denklemlerini cebirsel fonksiyonlara çevirir. Yani z-dönüşümü, Laplace dönüşümünün ayrık zamandaki karşılığıdır.

> **Ders sonrası not:** Hoca bir cümlede "Laplace'ın sürekli haldeki karşılığı z-dönüşümü" dedi; doğrusu, z-dönüşümü Laplace dönüşümünün ayrık zamandaki karşılığıdır. Hoca dersin başında da böyle tanımlamıştı.

## 2. LTI sistem, impuls cevabı ve frekans cevabı tekrarı

Bir sisteme $x(t)$ girer, $y(t)$ çıkar; ayrık zamanda $x[n]$ girer, $y[n]$ çıkar. Sistemin kutusu $h(t)$ ya da $h[n]$ ile gösterilir (ekrandan, 00:20:00). Ayrık zamanda giriş işareti ölçeklenmiş ve kaydırılmış birim impulsların toplamıdır. Sürekli zamanda ise aralıklar sonsuz küçüktür ve Dirac fonksiyonu kullanılır. Sistemin birim impulsa verdiği cevaba birim impuls cevabı denir: $h[n]$ ve $h(t)$.

Zaman domeninde çıkış konvolüsyonla bulunur:

$$y[n]=x[n]*h[n],\qquad y(t)=x(t)*h(t)$$

Ayrık konvolüsyonda toplamlar alınır. Sürekli konvolüsyonda $h(t)$ fonksiyonu $x(t)$'nin üzerinde kaydırılır ve çarpımın altında kalan alan hesaplanır.

Frekans domenine geçildiğinde işaret impulslara değil, karmaşık sinüzoidlere ayrılır. Herhangi bir işaret, farklı frekanslardaki sonsuz sayıda sinüsün toplamıdır. Bu yüzden sisteme bu sinüzoidler tek tek verilir:

$$e^{j\Omega n}=\cos\Omega n+j\sin\Omega n$$

Bunun sanal kısmı vardır, ama genel olarak sinüzoidal bir giriş gibi düşünülür. Sistemin bu girişe cevabı frekans cevabıyla belirlenir: sürekli zamanda $H(\omega)$, ayrık zamanda $H(e^{j\Omega})$ ya da $H(\Omega)$. Çıkış

$$y[n]=H(e^{j\Omega})\,e^{j\Omega n}$$

olur. Zaman domeninde sistem impuls cevabıyla, frekans domeninde frekans cevabıyla karakterize edilir. Aynı yaklaşımla herhangi bir işaretin frekans içeriği de $X(\omega)$ ya da $X(\Omega)$ ile bulunabilir; bu işaret impuls cevabının kendisi de olabilir.

## 3. z-dönüşümünün tanımı

### 3.1 Karmaşık üstel giriş ve $H(z)$

z-dönüşümünde $e^{j\Omega}$ yerine karmaşık bir $z$ değişkeni tanımlanır:

$$z=re^{j\Omega}=r(\cos\Omega+j\sin\Omega)$$

Gerçel kısım $r\cos\Omega$, sanal kısım $r\sin\Omega$ ile değişir. Önceden yalnız $e^{j\Omega}$ düşünülüyordu, yani genlik 1'di. $r$ genliği işin içine girince farklı genlikli işaretler de analiz edilebilir.

Sisteme $z^n=r^ne^{j\Omega n}$ biçiminde karmaşık üstel bir giriş uygulanırsa çıkış (ekrandan, 00:25:00):

$$y[n]=T\{z^n\}=H(z)\,z^n,\qquad H(z)=\sum_{n=-\infty}^{\infty}h[n]z^{-n}$$

### 3.2 Genel tanım

Herhangi bir ayrık zamanlı $x[n]$ işaretinin z-dönüşümü (ekrandan, 00:25:00):

$$X(z)=\sum_{n=-\infty}^{\infty}x[n]z^{-n}$$

Bunu DTFT ile karşılaştırmak öğreticidir: $X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]e^{-j\Omega n}$. DTFT'de işaret farklı frekanslardaki $e^{-j\Omega n}$ ile çarpılıp toplanır. İşaret hangi frekansa daha çok benziyorsa o frekansta daha büyük sonuç çıkar ve $X(\Omega)$'nın şekli ortaya çıkar. $X(\Omega)$ karmaşıktır; genellikle $|X(\Omega)|$, $[-\pi,\pi]$ aralığında çizilir. Örneğin alçak frekanslarda yoğun, $\pi$'ye doğru sönen bir spektrum, işarette yüksek frekanslı bileşen olmadığını gösterir.

$\Omega=\pi$ en yüksek sayısal frekanstır ve örnekleme frekansının yarısına, $f_s/2$'ye karşılık gelir. Örneğin 4 kHz'lik bir konuşma işareti en az 8 kHz ile örneklenmelidir. 16 ya da 32 kHz ile de örneklenebilir ve örnekleme daha iyi olur, ama en düşük örnekleme frekansı işaretteki en yüksek frekansın iki katıdır. Bu iki kat sınırı $\pi$'ye denk gelir.

z-dönüşümünde $e^{j\Omega}$'nın yerine $z$ gelmiştir ve $z$, $r$ genliğini de katar. $r=1$ alınırsa $z=e^{j\Omega}$ olur ve z-dönüşümü DTFT'ye indirgenir.

### 3.3 Kutupsal gösterim, iki taraflı ve tek taraflı dönüşüm

$z=re^{j\Omega}$'da $r$, $z$'nin genliği, $\Omega$ ise açısıdır (ekrandan, 00:25:00). Karmaşık düzlemde yatay eksen $\mathrm{Re}(z)$, düşey eksen $\mathrm{Im}(z)$'dir. $z$ bir noktadır; orijine uzaklığı genliği, yatay eksenle yaptığı açı $\Omega$'yı verir.

Toplamın $-\infty$'dan $\infty$'a alındığı tanıma iki taraflı (bilateral, two-sided) z-dönüşümü denir. Toplam $n=0$'dan başlarsa tek taraflı (unilateral, one-sided) z-dönüşümü elde edilir. Derste çoğunlukla iki taraflı tanım kullanıldı.

Gösterim için $x[n]\overset{z}{\longleftrightarrow}X(z)$ ya da $X(z)=\mathcal{Z}\{x[n]\}$ yazılır. Kitapta süslü $\mathcal{Z}$ da kullanılır. Laplace'ta da benzer biçimde $\mathcal{L}\{x(t)\}$ yazılıyordu.

## 4. Yakınsaklık bölgesi ve ilk örnekler

### 4.1 ROC kavramı

Yakınsaklık bölgesi (Region of Convergence, ROC), bulunan $X(z)$ ifadesinin sonlu bir değere yakınsadığı, sonsuza gitmediği $z$ değerleri kümesidir. Laplace dönüşümünde sonuç bir $X(s)$ ifadesi ve $\mathrm{Re}(s)>a$ gibi bir tanım bölgesiyle birlikte verilirdi. z-dönüşümünde de sonuç bir çifttir: $X(z)$ ifadesi ve $z$'nin tanımlı olduğu ROC.

### 4.2 Sağ taraflı dizi: $x[n]=a^nu[n]$ (Schaum Örnek 4.1)

$u[n]$ diziyi $n=0$'dan başlatır; $n<0$ için $x[n]=0$'dır. Dizinin davranışı $a$'ya bağlıdır. $a=1/2$ ise değerler $1,\tfrac12,\tfrac14,\tfrac18,\dots$ olur ve azalır. $a=2$ ise $1,2,4,8,\dots$ olur ve sonsuza gider. Sonsuza giden dizinin toplamı yakınsamaz. Azalan dizide $1+\tfrac12+\tfrac14+\tfrac18+\dots$ toplamı bir değere yaklaşır. İşte toplamın değer alabildiği bölge ROC'dir.

Hesap (ekrandan, 00:35:00):

$$X(z)=\sum_{n=-\infty}^{\infty}a^nu[n]z^{-n}=\sum_{n=0}^{\infty}(az^{-1})^n$$

$u[n]$ alt sınırı $0$ yaptı; $a^n$ ve $z^{-n}$ aynı üs altında toplandı. Yakınsama için $\sum_{n=0}^{\infty}|az^{-1}|^n<\infty$ olmalıdır, yani $|az^{-1}|<1$. Bu $|a|/|z|<1$, yani $|z|>|a|$ demektir (ekrandan, 00:40:00). Sonuç:

$$X(z)=\frac{1}{1-az^{-1}}=\frac{z}{z-a},\qquad |z|>|a|$$

İkinci biçim, pay ve payda $z$ ile çarpılarak elde edilir. İki biçim de uygulamaya göre kullanışlıdır.

> **Hocanın vurgusu:** $|z|>|a|$ şartı hiç unutulmamalı. Bu şart geometrik serinin yakınsama koşulundan gelir.

### 4.3 Kullanılan seri toplamları

Hoca, kitaptaki dizi toplamları sayfasını açıp bunların not edilmesini istedi:

- $\displaystyle\sum_{n=0}^{\infty}\alpha^n=\frac{1}{1-\alpha}$, $|\alpha|<1$. ($\alpha=\tfrac12$ ya da $-\tfrac12$ için de geçerlidir.)
- $\displaystyle\sum_{n=0}^{N-1}\alpha^n=\frac{1-\alpha^N}{1-\alpha}$, $\alpha\neq1$. $\alpha=1$ ise $N$ tane 1 toplanır ve sonuç $N$'dir. $N\to\infty$ ve $|\alpha|<1$ iken $\alpha^N\to0$ olur, ilk formül elde edilir.
- $\displaystyle\sum_{n=0}^{\infty}n\alpha^n=\frac{\alpha}{(1-\alpha)^2}$, $|\alpha|<1$.

Hoca bu dersin kalkülüsle yakından ilgili olduğunu hatırlattı. $a^nu[n]$ örneğinde $\alpha=az^{-1}$'dir.

## 5. Kutup-sıfır grafiği ve z düzlemi

$\frac{z}{z-a}$ ifadesi $z$'nin rasyonel bir fonksiyonudur (ekrandan, 00:40:00). Laplace'ta olduğu gibi, pay ve payda polinom olarak düşünülür ve fonksiyon sıfırları ve kutuplarıyla tanımlanır. Sıfırlar payın, kutuplar paydanın kökleridir. Bu örnekte $z=0$'da bir sıfır, $z-a=0$'dan $z=a$'da bir kutup vardır.

Çizimde kutuplar çarpı ("x"), sıfırlar yuvarlak ("o") ile gösterilir. $|z|=1$ çemberine birim çember (unit circle) denir; bazı çıkarımlarda kullanılacaktır. $0<a<1$ ise ROC, yarıçapı $|a|$ olan çemberin dışındaki taralı bölgedir. $a>1$ olsaydı da ROC yine $|z|>|a|$ olurdu, yani daha büyük çemberin dışı. $a$ negatif olsa da ($-1<a<0$ ya da $a<-1$) sonuç aynı biçimdedir, çünkü şart $|a|$ ile yazılır.

Bu düzleme z düzlemi denir. Laplace'ta $s=\sigma+j\omega$ idi; yatay eksen $\sigma$, düşey eksen $j\omega$ olan düzleme s düzlemi deniyordu. z düzleminde yatay eksen $\mathrm{Re}(z)$, düşey eksen $\mathrm{Im}(z)$'dir. Böylece Laplace'a benzer bir düzlemsel analiz yapılır.

$a^nu[n]$ sağ taraflı bir dizidir. $|z|>|a|$ olduğunda, $z^{-n}$ ile çarpılan dizi azalan bir diziye dönüşür ve toplam gerçekten yakınsar.

### 5.1 Sol taraflı dizi: $x[n]=-a^nu[-n-1]$ (Schaum Örnek 4.2 ve Problem 4.1a)

$u[-n-1]$'in nereden başladığını bulmak için içi sıfıra eşitlenir: $-n-1=0$, $n=-1$. Başında eksi işareti olduğu için dizi $n=-1$'den $-\infty$'a doğru uzanır; yani sol taraflıdır (ekrandan, 01:05:00). $u[n]$ ise $n=0$'dan sağa doğru gider.

Kitap sonucu Örnek 4.2'de doğrudan verir ve Problem 4.1'e gönderir. Hoca problemi yerinde çözdü (ekrandan, 00:50:00):

$$X(z)=-\sum_{n=-\infty}^{\infty}a^nu[-n-1]z^{-n}=-\sum_{n=-\infty}^{-1}a^nz^{-n}$$

$u[-n-1]$ toplamı $-\infty$'dan $-1$'e sınırladı. Şimdi $n\to-n$ ile toplamın yönü çevrilir; alt sınır $1$, üst sınır $\infty$ olur ve üslerin işareti değişir:

$$X(z)=-\sum_{n=1}^{\infty}(a^{-1}z)^n$$

Toplamı $n=0$'dan başlatmak için $n=0$ terimi eklenip çıkarılır. Bu terim $(a^{-1}z)^0=1$'dir:

$$X(z)=1-\sum_{n=0}^{\infty}(a^{-1}z)^n$$

Geometrik seri formülüyle, $\alpha=a^{-1}z$ ve $|a^{-1}z|<1$, yani $|z|<|a|$ iken:

$$X(z)=1-\frac{1}{1-a^{-1}z}=\frac{-a^{-1}z}{1-a^{-1}z}=\frac{z}{z-a}=\frac{1}{1-az^{-1}},\qquad |z|<|a|$$

Sağ taraflı dizide ROC $|z|>|a|$ idi; burada $|z|<|a|$ oldu. Yani işaret değişince ROC tanımı değişti, cebirsel ifade ise aynı kaldı (ekrandan, 01:05:00). Bu durumda ROC, yarıçapı $|a|$ olan çemberin içidir. Laplace dönüşümünde olduğu gibi, iki farklı dizinin cebirsel ifadesi aynı olabilir; onları ayıran ROC'dir.

### 5.2 Problem 4.1(b): $x[n]=a^{-n}u[-n-1]$

Bu dizide eksi işareti başta değil, üsse geçmiştir. Hesap (ekrandan, 00:55:00):

$$X(z)=\sum_{n=-\infty}^{-1}a^{-n}z^{-n}=\sum_{n=-\infty}^{-1}(az)^{-n}=\sum_{n=1}^{\infty}(az)^n=\sum_{n=0}^{\infty}(az)^n-1$$

Burada da $n=0$ terimi ($=1$) eklenip çıkarıldı. $|az|<1$, yani $|z|<1/|a|$ iken:

$$X(z)=\frac{1}{1-az}-1=\frac{az}{1-az}=-\frac{z}{z-1/a},\qquad |z|<\frac{1}{|a|}$$

Sıfır $z=0$'da, kutup $z=1/a$'dadır. ROC, yarıçapı $1/|a|$ olan çemberin içidir.

Bu iki diziden sonra derse 10 dakikalık ara verildi.

## 6. Türkçe slaytlardan tekrar: temel diziler ve iki taraflı dizi

Aradan sonra hoca Türkçe slaytlara geçti ve şimdiye kadar görülenleri bunlar üzerinden tekrar etti. Bölümün amacı, ayrık zamanlı işaret ve sistemlerin z-dönüşümüyle analizi, transfer fonksiyonu $H(z)$'nin tanıtılması ve işaretler ile sistemler için z-dönüşümünün tanımlanmasıdır.

z-dönüşümü Fourier dönüşümünün, daha doğrusu DTFT'nin genelleştirilmesidir. DTFT, sonsuza giden işaretler gibi pek çok işaret için hesaplanamaz. z-dönüşümü bu işaretlerin de tanım sınırlarını bulmayı sağlar.

Slaytlarda DTFT küçük $\omega$ ile $X(e^{j\omega})$ diye yazılmıştır. Hoca derste büyük $\Omega$'yı sayısal frekans, küçük $\omega$'yı sürekli frekans için kullandığını hatırlattı; slayttaki küçük $\omega$ sayısal frekans olarak, yani büyük $\Omega$ gibi okunmalıdır.

### 6.1 z düzlemi ve birim çember

z-dönüşümü karmaşık $z$ değişkeninin bir fonksiyonudur ve karmaşık z düzleminde gösterilmeye uygundur (ekrandan, 01:10:00). $\omega$, $0$'dan $2\pi$'ye giderken $z=e^{j\omega}$ çizilirse birim çember ($r=1$) elde edilir. DTFT'nin $0$-$2\pi$ aralığındaki değerleri, z düzleminde birim çemberin üzerindeki değerlere karşılık gelir. $|X(e^{j\Omega})|$ çizilirken $[0,2\pi)$ ya da $[-\pi,\pi)$ aralığı kullanılır; spektrum simetriktir ve $2\pi$ ile periyodik olarak tekrar eder.

### 6.2 Nedensel dizi ve tek taraflı dönüşüm

$x[n]$ nedensel ise, yani $n<0$ için $x[n]=0$ ise, toplam $n=0$'dan başlar: $X(z)=\sum_{n=0}^{\infty}x[n]z^{-n}$. Bu tek taraflı (unilateral) z-dönüşümüdür. $-\infty$'dan $\infty$'a giden tanım ise iki taraflı (bilateral) z-dönüşümüdür.

### 6.3 Temel diziler

- **Birim impuls:** $x[n]=\delta[n]$ yalnız $n=0$'da değer alır. Toplamda $z^{0}=1$ kalır, yani $X(z)=1$. Sabit bir değer olduğu için ROC tüm z düzlemidir.
- **Birim basamak:** $u[n]$ için $X(z)=\sum_{n=0}^{\infty}(z^{-1})^n=1+z^{-1}+z^{-2}+\dots$. $r=z^{-1}$ denirse yakınsama için $|r|<1$, yani $|z^{-1}|<1$, $|z|>1$ olmalıdır. Sonuç $\frac{1}{1-z^{-1}}=\frac{z}{z-1}$, $|z|>1$. $z=0$'da bir sıfır, $z=1$'de bir kutup vardır. Sıfırda ifade $0$ değerini alır; kutupta sonsuza gider ve ifade orada tanımlı değildir.
- **$a^nu[n]$:** $\frac{z}{z-a}$, $|z|>|a|$. ROC, yarıçapı $|a|$ olan çemberin dışıdır.
- **$-b^nu[-n-1]$:** $\frac{z}{z-b}$, $|z|<|b|$. ROC çemberin içidir. Bu ROC'nin birim çemberi kapsayıp kapsamaması önemli bir kavramdır.

ROC karmaşık düzlemde çemberlerle sınırlanır: kimi zaman bir çemberin dışında, kimi zaman içinde, kimi zaman da iki taraftan sınırlı olarak çıkar (ekrandan, 01:15:00). Bir işaretin z-dönüşümünün sonlu olması için

$$|X(z)|=\left|\sum_{n=-\infty}^{\infty}x[n]z^{-n}\right|\le\sum_{n=-\infty}^{\infty}|x[n]|\,|z^{-n}|<\infty$$

olmalıdır.

### 6.4 İki taraflı dizi

$$x[n]=\begin{cases}a^n, & n\ge0\\ -b^n, & n<0\end{cases}$$

Toplam iki parçaya ayrılır: $n=0$'dan $\infty$'a $a^nz^{-n}$ ve $-\infty$'dan $-1$'e $-b^nz^{-n}$. İki parça ayrı ayrı daha önce çözülmüştü:

$$X(z)=\frac{z}{z-a}+\frac{z}{z-b}=\frac{z\,\big(2z-(a+b)\big)}{(z-a)(z-b)}$$

Sıfırlar $z=0$ ve $z=\frac{a+b}{2}$'de, kutuplar $z=a$ ve $z=b$'dedir. İlk parça $|z|>|a|$, ikinci parça $|z|<|b|$ şartını verir. ROC bu ikisinin kesişimidir:

$$|a|<|z|<|b|$$

Bu halka biçimli taralı bölgedeki bir $z$ için $X(z)$ bir değere yakınsar.

## 7. Yakınsaklık bölgesinin özellikleri

Hoca slayttaki özellikleri tek tek okudu ve açıkladı (ekrandan, 01:20:00):

1. ROC, z düzleminde bir halka ya da disk şeklindedir.
2. $x[n]$'in Fourier dönüşümü (DTFT, $X(e^{j\Omega})$) yalnız ROC birim çemberi ($|z|=1$) kapsıyorsa hesaplanabilir.
3. ROC kutup içeremez.
4. $x[n]$ sonlu uzunluklu bir diziyse, yani $N_1\le n\le N_2$ aralığının dışında sıfırsa, ROC tüm z düzlemidir. $N_1$ ve $N_2$ pozitif ya da negatif olabilir. Sonlu sayıda terimin toplamı mutlaka bir değere yakınsar.
5. $x[n]$ sağ taraflı bir diziyse (bir $N_1$'den küçük $n$ değerleri için sıfırsa), ROC en dıştaki kutuptan dışarıya doğrudur. $z=\infty$ dahil olabilir.
6. $x[n]$ sol taraflı bir diziyse (bir $N_2$'den büyük $n$ değerleri için sıfırsa), ROC en içteki kutuptan içeriye doğrudur. $z=0$ dahil olabilir.
7. $x[n]$ iki taraflı, yani her iki yönde sonsuz uzunluklu bir diziyse, ROC içten ve dıştan birer kutupla sınırlanmış bir halkadır. Bölüm 6.4'teki örnek buna uyar.
8. ROC bağlantılı olmalıdır; birbirinden kopuk bölgelerden oluşamaz.

Hoca bu özellikleri soru çözerken kendiliğinden göreceğimizi söyledi.

> **Ek bilgi (derste anlatılmadı):** 4. özellikte $z=0$ ve $z=\infty$ istisna olabilir. Dizide $n>0$ için sıfır olmayan değer varsa $z^{-n}$ terimleri $z=0$'da, $n<0$ için değer varsa $z^{|n|}$ terimleri $z=\infty$'da sonsuza gider. Schaum Problem 4.2 bu durumu inceler; problemin başlığı ve ilgili sonuç metni derste ekranda kısmen görüldü (ekrandan, 00:55:00 ve 02:25:00).

## 8. z-dönüşümünün özellikleri

### 8.1 Doğrusallık

$x_1[n]$ ve $x_2[n]$ iki dizi, $\mathcal{Z}\{x_1[n]\}=X_1(z)$ ve $\mathcal{Z}\{x_2[n]\}=X_2(z)$ olsun. $a$ ve $b$ iki sabit katsayı ise (ekrandan, 01:25:00):

$$X_3(z)=\mathcal{Z}\{ax_1[n]+bx_2[n]\}=aX_1(z)+bX_2(z),\qquad \mathrm{ROC}\supseteq R_1\cap R_2$$

İspat doğrudan tanımdan gelir: $\sum[ax_1[n]+bx_2[n]]z^{-n}=a\sum x_1[n]z^{-n}+b\sum x_2[n]z^{-n}$. Ortak ROC, iki ROC'nin kesişimidir.

**Örnek 12.5:** $x[n]=(0{,}5^n+2)\,u[n]$. Dizi iki dizinin doğrusal birleşimidir: $x[n]=0{,}5^nu[n]+2u[n]$. Bilinen çiftlerden:

$$0{,}5^nu[n]\leftrightarrow\frac{1}{1-0{,}5z^{-1}},\ |z|>0{,}5;\qquad 2u[n]\leftrightarrow\frac{2}{1-z^{-1}},\ |z|>1$$

İki dönüşüm toplanır. Ortak ROC iki şartın kesişimidir; biri $|z|>0{,}5$, diğeri $|z|>1$ dediği için kesişim büyük olandır: $|z|>1$. Yani yarıçapı 1 olan çemberin dışı.

<!-- BELİRSİZ: Örnek 12.5 slaydı karelerde görünmüyor; dizinin yazımı ve ikinci terimin katsayısı altyazıdan kuruldu (altyazıda bir yerde "1 bölü 2" geçiyor, hoca aynı anda "2 yazmamız lazım" diyor). -->

### 8.2 Öteleme

$x[n]$ sağ taraflı ise ($n<0$ için $x[n]=0$) ve $m$ pozitif bir tam sayı ise, $m$ birim sola ilerletilmiş dizi için

$$x[n+m]\leftrightarrow z^{m}\left[X(z)-\sum_{k=0}^{m-1}x[k]z^{-k}\right]$$

yazılabilir. $m$ birim sağa ötelenmiş (geciktirilmiş) dizi için ise

$$x[n-m]\leftrightarrow z^{-m}X(z)$$

<!-- BELİRSİZ: İlerletme formülünün slayttaki tam biçimi karelerde görünmüyor; altyazıdaki okumadan ve tek taraflı dönüşümün bilinen biçiminden kuruldu. -->

Bu, DTFT'deki öteleme özelliğinin karşılığıdır: $x[n-n_0]\leftrightarrow e^{-j\Omega n_0}X(\Omega)$. Aynı yapı z domeninde $z^{-m}X(z)$ olarak görülür.

**Örnek 12.6:** Geciktirilmiş impuls dizisi $x[n]=\delta[n-m]$ için, $\mathcal{Z}\{\delta[n]\}=1$ olduğundan (ekrandan, 01:30:00):

$$X(z)=\mathcal{Z}\{\delta[n-m]\}=z^{-m},\qquad 0<|z|\le\infty$$

$z=0$'da yakınsamaz. İlerletilmiş impuls dizisi $x[n]=\delta[n+m]$ için

$$X(z)=\mathcal{Z}\{\delta[n+m]\}=z^{m},\qquad 0\le|z|<\infty$$

$z=\infty$'da yakınsamaz. Yani impuls, $m$'nin işaretine göre sağa ya da sola kaydırılabilir.

### 8.3 Karmaşık türev

Zaman düzleminde diziyi $n$ indisiyle çarpmak, z düzleminde türeve karşılık gelir. Hoca slayttaki ispata girmedi.

> **Ek bilgi (derste anlatılmadı):** Bu özelliğin bilinen biçimi $n\,x[n]\leftrightarrow -z\dfrac{dX(z)}{dz}$'dir ve ROC değişmez. Örneğin $a^nu[n]$'e uygulanınca kitabın tablosundaki $na^nu[n]\leftrightarrow\dfrac{az^{-1}}{(1-az^{-1})^2}$, $|z|>|a|$ çifti elde edilir (tablo ekrandan, 02:20:00).

### 8.4 Dönüşüm tablosu

Slaytta bazı diziler, z-dönüşümleri ve ROC'leri tablo hâlinde verilmişti; kosinüslü ve sinüslü diziler de vardı. Hoca $u[n]\leftrightarrow\frac{1}{1-z^{-1}}=\frac{z}{z-1}$ çiftini tekrar gösterdi: bir sıfır ve bir kutup vardır; ifadenin yakınsaması için $|z^{-1}|<1$, yani $|z|>1$ olmalıdır. Laplace'ta da z-dönüşümünde de hem dönüşüm yapılır hem ROC belirlenir.

## 9. Kutup-sıfır gösterimi ve MATLAB uygulaması

### 9.1 Sıfır polinomu ve karakteristik polinom

Bulunan $X(z)$ iki polinomun oranı biçimindeyse, paydaki polinoma sıfır polinomu, paydadakine karakteristik polinom denir. $X(z)$'yi bu biçimde yazmak, işaret ve sistemlerin analiz ve sentezini kolaylaştırır ve ROC daha rahat gösterilir.

Kutuplar karakteristik polinomun, sıfırlar sıfır polinomunun kökleridir. Kutuplar $X(z)$'nin sonsuz olduğu $z$ değerleri olduğu için ROC tanım gereği hiçbir kutbu içermez. Sıfırların ve kutupların karmaşık düzlemde gösterildiği grafiğe kutup-sıfır grafiği (pole-zero graph, pole-zero diagram) denir; kutuplar "x", sıfırlar "o" ile gösterilir (ekrandan, 01:35:00).

### 9.2 Kutup-sıfır grafiği örneği

Slaytta pay ve paydası $z^{-1}$ cinsinden ikinci dereceden polinomlar olan bir $X(z)$ verildi ve kutup-sıfır grafiği istendi. Sıfırları ve kutupları bulmak için pay ve payda çarpanlarına ayrılır. Pay $(1-0{,}8z^{-1})(1+0{,}8z^{-1})$ olarak yazıldı. Her çarpan sıfıra eşitlenir: $1-0{,}8z^{-1}=0$ ise $1=0{,}8z^{-1}$, yani $z=0{,}8$. Diğer çarpandan $z=-0{,}8$ bulunur. Payda da aynı yolla çarpanlarına ayrılarak iki kutup bulundu; sonuçta iki sıfır ve iki kutup vardır.

<!-- BELİRSİZ: Bu örneğin paydası ve kutupların yeri karelerde görünmüyor; altyazıda "0.4" ve "0.2" değerleri geçiyor, işaretleri ve hangi çarpana ait oldukları çıkarılamadı. -->

### 9.3 MATLAB ile kutup-sıfır çizimi

Hoca, verilen bir $X(z)$'nin sıfır ve kutuplarını bulup çizmek için MATLAB'deki iki fonksiyonu tanıttı:

- `tf2zp` (transfer function to zero-pole): pay (sıfır polinomu) ve payda (karakteristik polinom) katsayı vektörlerini alır, sıfırları `z`, kutupları `p` ve kazancı `k` olarak döndürür: `[z,p,k] = tf2zp(b,a)`.
- `zplane`: bulunan sıfırları ve kutupları z düzleminde, birim çemberle birlikte çizer: `zplane(z,p)`.

Hoca bunu bir uygulama olarak verdi. Örnek olarak tahtaya şu biçimi yazdı (ekrandan, 01:40:00):

$$X(z)=\frac{a+bz^{-1}+cz^{-2}+dz^{-3}}{1-ez^{-1}+fz^{-2}-gz^{-3}}$$

$a$'dan $g$'ye kadar katsayılar $[-1,1]$ aralığında rastgele üretilir (örneğin $0{,}18$, $-0{,}87$ gibi). Pay katsayıları bir vektöre (sıfır polinomu), payda katsayıları başka bir vektöre (karakteristik polinom) atanır, `tf2zp` ile sıfırlar ve kutuplar bulunur, `zplane` ile çizilir. Hoca sonra uygulamayı genelleştirdi: pay ve paydanın uzunluğu da 2 ile 10 arasında rastgele seçilsin. Örneğin pay 5 uzunluklu çıkarsa $a+bz^{-1}+cz^{-2}+dz^{-3}+ez^{-4}$, payda 6 uzunluklu çıkarsa $z^{-5}$'e kadar terim olur. Uzunluk değiştikçe üretilecek katsayı sayısı da değişir.

**Soru:** Uzunluk tam olarak neyi ifade ediyor? **Cevap:** Polinomdaki terim sayısını. Uzunluk 4 ise $a+bz^{-1}+cz^{-2}+dz^{-3}$, 5 ise bir de $z^{-4}$'lü terim gelir; pay ve payda için ayrı ayrı rastgele seçilir.

**Soru:** O zaman paydadaki sabit 1 de bir değişken olacak mı? **Cevap:** Evet, o da rastgele üretilen bir katsayı olsun.

> **Ek bilgi (derste anlatılmadı):** `tf2zp` büyük olasılıkla katsayıları $s$'nin azalan kuvvetleri gibi yorumlar; bu durumda pay ve paydanın uzunluğu farklı olan $z^{-1}$ polinomlarında $z=0$'daki sıfır ya da kutuplar eksik çıkabilir. MATLAB'de $z^{-1}$ cinsinden yazılmış ayrık sistemler için büyük olasılıkla `tf2zpk` önerilir. `zplane(b,a)` biçimi de katsayılardan doğrudan çizim yapar.

## 10. Transfer fonksiyonu

Şimdiye kadar hep $X(z)$, yani $\mathcal{Z}\{x[n]\}$ görüldü. $x[n]$ yerine sistemin impuls cevabı $h[n]$ konursa transfer fonksiyonu elde edilir.

Doğrusal zamanla değişmez bir sistemin dürtü yanıtı $h[n]$ ile gösterilir. Sisteme $x[n]=z^n$ biçiminde daimi bir üstel giriş uygulandığında çıkış (ekrandan, 01:50:00):

$$y[n]=x[n]*h[n]=\sum_{k=-\infty}^{\infty}h[k]\,x[n-k]=\sum_{k=-\infty}^{\infty}h[k]\,z^{n-k}=z^n\sum_{k=-\infty}^{\infty}h[k]\,z^{-k}$$

olarak bulunur. $\sum_k h[k]z^{-k}$ toplamı bağımsız değişken $n$'ye bağlı değildir; yalnız sistemin dürtü yanıtı ve girişin $z$ değeriyle belirlenen bir katsayıdır. Bu katsayı $H(z)$ ile gösterilir ve transfer fonksiyonu adını alır:

$$H(z)=\sum_{k=-\infty}^{\infty}h[k]z^{-k},\qquad y[n]=H(z)\,z^n$$

Yani transfer fonksiyonu biliniyorsa, hangi karmaşık üstel uygulanırsa uygulansın çıkışta o değer için ne çıkacağı bilinir.

Zaman domeninde $y[n]$, $x[n]$ ile $h[n]$'nin konvolüsyonudur. DTFT'de olduğu gibi z domenine geçildiğinde, her birinin z-dönüşümü biliniyorsa, bu işlem basit bir çarpmaya dönüşür: $Y(z)=X(z)H(z)$. Bu, sistemi değerlendirmeyi kolaylaştırır.

## 11. Ters z-dönüşümü

Ters z-dönüşümü $\mathcal{Z}^{-1}\{X(z)\}$, verilen $z$'li bir ifadeyi zaman domenine geri çevirir. Bunun için tek bir formül yoktur. Genel yaklaşım, $X(z)$'yi dönüşümü bilinen biçimlere getirip oradan $x[n]$'ye geçmektir.

### 11.1 Kısmi kesirlere açılım

En kolay yöntemlerden biridir. $X(z)$ iki polinomun oranı biçiminde, yani rasyonel olduğunda kullanılır: sıfır polinomu üstte, karakteristik polinom altta. Pay polinomunun derecesi paydanınkinden küçükse ve kutupların tamamı birinci dereceden ise (ekrandan, 01:55:00)

$$X(z)=\frac{A(z)}{B(z)}=X_1(z)+X_2(z)+\dots=\sum_{k=1}^{N}X_k(z),\qquad x[n]=x_1[n]+x_2[n]+\dots=\sum_{k=1}^{N}x_k[n]$$

yazılabilir. "Kutupların birinci dereceden olması", paydada $(z-p)^2$ gibi katlı bir çarpan olmaması, her kutbun bir kez bulunması demektir. Dönüşüm doğrusal olduğu için toplamın tersi, terimlerin terslerinin toplamıdır.

$p_k$, $X(z)$'nin tek katlı kutupları olmak üzere

$$X(z)=\sum_{k=1}^{N}\frac{r_k}{1-p_kz^{-1}}$$

biçimine getirilirse, her terimin tersi bir üstel dizi olduğundan (sağ taraflı durumda)

$$x[n]=\sum_{k=1}^{N}r_k\,p_k^n\,u[n]$$

olur.

### 11.2 Seri açılımı

z-dönüşümünün tanımından yola çıkılır. $X(z)$ bir seri olarak açıldığında

$$X(z)=\dots+x[-2]z^{2}+x[-1]z+x[0]+x[1]z^{-1}+x[2]z^{-2}+\dots$$

biçimindedir; bu $\sum x[n]z^{-n}$'nin açık yazılışıdır. Ters dönüşüm bunun tersidir: $z^{-k}$'nın katsayısı $x[k]$'dır. $x[n]$ impulsların toplamı olduğu için dizi $\sum_k x[k]\delta[n-k]$ olarak okunur.

## 12. Ters dönüşüm ve ROC örnekleri

### 12.1 Örnek 12.9: öteleme ile ters dönüşüm

Verilen (ekrandan, 02:00:00):

$$X(z)=\frac{z^{-4}}{z-1}+z^{-6}+\frac{z^{-3}}{z+0{,}5}$$

Amaç, her terimi bilinen $\frac{z}{z-a}$ biçimine getirmektir. Birinci terimin payına bir $z$ çıkarmak için $z^{-4}=z^{-5}\cdot z$ yazılır: $\frac{z^{-4}}{z-1}=z^{-5}\frac{z}{z-1}$. Üçüncü terimde de $z^{-3}=z^{-4}\cdot z$ yazılır: $\frac{z^{-3}}{z+0{,}5}=z^{-4}\frac{z}{z+0{,}5}$. Böylece

$$x[n]=\mathcal{Z}^{-1}\left\{z^{-5}\frac{z}{z-1}\right\}+\mathcal{Z}^{-1}\{z^{-6}\cdot1\}+\mathcal{Z}^{-1}\left\{z^{-4}\frac{z}{z+0{,}5}\right\}$$

Bilinen çiftler: $\frac{z}{z-1}\leftrightarrow u[n]$, $1\leftrightarrow\delta[n]$, $\frac{z}{z+0{,}5}\leftrightarrow(-0{,}5)^nu[n]$ (payda $z-a$ biçiminde olduğu için $a=-0{,}5$). Öndeki $z^{-m}$ çarpanları öteleme parametreleridir; zamanda $m$ birim gecikme yapar. Sonuç (ekrandan, 02:00:00):

$$x[n]=u[n-5]+\delta[n-6]+(-0{,}5)^{n-4}u[n-4]$$

> **Hocanın vurgusu:** Öteleme özelliğini kullanan bu tür ters dönüşüm önemli bir soru tipidir; $z^{-m}$ çarpanı zamanda $m$ birim kaydırma demektir.

Ara kontrol (ara adım eklendi): $z=2$'de kapalı ifade $\frac{2^{-4}}{1}+2^{-6}+\frac{2^{-3}}{2{,}5}=0{,}0625+0{,}015625+0{,}05=0{,}128125$'tir; bulunan $x[n]$ dizisinin $\sum x[n]2^{-n}$ toplamı da aynı değeri verir.

### 12.2 Örnek 12.10: kısmi kesirler

Verilen (ekrandan, 02:05:00):

$$F(z)=\frac{10\,z\,(z+5)}{(z-1)(z-2)(z+3)},\qquad f[n]=?$$

Üç kutup ($1$, $2$, $-3$) ve pay polinomunda $z$ dışında bir sıfır ($-5$) vardır. Önce bir $z$ dışarı alınır, köşeli parantezin içi kısmi kesirlere açılır:

$$F(z)=z\left[\frac{10(z+5)}{(z-1)(z-2)(z+3)}\right]=z\left[\frac{-15}{z-1}+\frac{14}{z-2}+\frac{1}{z+3}\right]$$

Katsayılar her kutupta kalan kesrin değeriyle bulunur (ara adım eklendi): $z=1$'de $\frac{10\cdot6}{(-1)(4)}=-15$; $z=2$'de $\frac{10\cdot7}{(1)(5)}=14$; $z=-3$'te $\frac{10\cdot2}{(-4)(-5)}=1$. Dışarıdaki $z$ içeri dağıtılır:

$$F(z)=\frac{z}{z+3}+14\frac{z}{z-2}-15\frac{z}{z-1}$$

$\mathcal{Z}^{-1}\left\{\frac{z}{z-a}\right\}=a^nu[n]$ olduğundan $\frac{z}{z+3}\leftrightarrow(-3)^nu[n]$, $\frac{z}{z-2}\leftrightarrow2^nu[n]$, $\frac{z}{z-1}\leftrightarrow u[n]$. Katsayılar başlarına gelir:

$$f[n]=(-3)^nu[n]+14\cdot2^nu[n]-15\,u[n]$$

### 12.3 Örnek 12.11: iki taraflı dizi, kutup-sıfır ve ROC

Verilen (ekrandan, 02:10:00):

$$x[n]=7\left(-\tfrac13\right)^nu[n]-\left(\tfrac12\right)^nu[-n-1],\qquad X(z)=?$$

Kutup-sıfır diyagramı ve yakınsaklık bölgesi istenir. Tanımda yerine konur:

$$X(z)=7\sum_{n=0}^{\infty}\left(-\tfrac13\right)^nz^{-n}-\sum_{n=-\infty}^{-1}\left(\tfrac12\right)^nz^{-n}$$

Birinci toplam bilinen biçimdedir: $7\frac{z}{z+1/3}$, $|z|>\tfrac13$.

İkinci toplamda derste bir tartışma yaşandı. Hoca önce slayttaki çözümde "$+1$" teriminin nereden gelip nereye gittiğini sorguladı, çözümde bir hata olabileceğini düşündü. Bir öğrenci, kitaptaki $-a^nu[-n-1]$ çiftinin bu ifadeyle uyuştuğunu, toplamın sınırları ters çevrildiği için ifadenin $z^{n}$'li biçime geldiğini hatırlattı. Hoca toplamı ters çevirince öğrencinin haklı olduğunu gördü.

**Soru:** $u[-n-1]$'li ifadeden bu sonuç neden doğrudan çıkarılamasın? Kitaptaki $-a^nu[-n-1]$ çifti burada yazılanla uyuşuyor. **Cevap:** Hoca, toplam ters çevrildiğinde $-\sum_{n=-\infty}^{-1}a^nz^{-n}$ ifadesinin $-\sum_{n=1}^{\infty}a^{-n}z^{n}$'ye döndüğünü, bunu gözden kaçırdığını söyledi; öğrencinin dediği doğrudur.

Ters çevirme adım adım şöyledir:

$$-\sum_{n=-\infty}^{-1}\left(\tfrac12\right)^nz^{-n}=-\sum_{n=1}^{\infty}\left(\tfrac12\right)^{-n}z^{n}=-\sum_{n=1}^{\infty}(2z)^n=1-\sum_{n=0}^{\infty}(2z)^n$$

Son adımda $n=0$ terimi ($=1$) eklenip çıkarıldı. Yakınsama için $|2z|<1$, yani $|z|<\tfrac12$ olmalıdır. Hoca da $\sum(2z)^n$ için $\frac{1}{1-2z}$ ve $|z|<\tfrac12$ sınırını bulmuştu. Devam edilirse

$$1-\frac{1}{1-2z}=\frac{-2z}{1-2z}=\frac{z}{z-\tfrac12},\qquad |z|<\tfrac12$$

Bu, $-a^nu[-n-1]\leftrightarrow\frac{z}{z-a}$, $|z|<|a|$ çiftiyle ($a=\tfrac12$) aynıdır. İki parça toplanır ve paydalar eşitlenir (ekrandan, 02:10:00):

$$X(z)=7\frac{z}{z+\tfrac13}+\frac{z}{z-\tfrac12}=\frac{z\left(8z-\tfrac{19}{6}\right)}{\left(z+\tfrac13\right)\left(z-\tfrac12\right)}$$

Pay hesabı (ara adım eklendi): $7\left(z-\tfrac12\right)+\left(z+\tfrac13\right)=8z-\tfrac72+\tfrac13=8z-\tfrac{19}{6}$.

- Kutuplar: $z=-\tfrac13$ ve $z=\tfrac12$.
- Sıfırlar: $z=0$ ve $8z=\tfrac{19}{6}$'dan $z=\tfrac{19}{48}$.
- ROC: birinci parça $|z|>\tfrac13$, ikinci parça $|z|<\tfrac12$ verir. Kesişim $\tfrac13<|z|<\tfrac12$ halkasıdır.

Python ile kontrol (ara adım eklendi): $z=0{,}4$ (ROC içinde) için iki toplamın sayısal değeri ve kapalı ifade aynı sonucu ($\approx-0{,}1818$) verir.

### 12.4 Hangi çiftten hangi ROC?

Hoca ters dönüşümde kullanılacak iki temel çifti yan yana gösterdi (tablo ekrandan, 02:20:00):

- $a^nu[n]\leftrightarrow\dfrac{1}{1-az^{-1}}=\dfrac{z}{z-a}$, $|z|>|a|$
- $-a^nu[-n-1]\leftrightarrow\dfrac{1}{1-az^{-1}}=\dfrac{z}{z-a}$, $|z|<|a|$

İfadeler aynıdır; ayıran ROC'dir. Ters dönüşümde $\frac{z}{z-a}$ biçimine getirilen her terim için ROC'ye bakılır: ROC kutbun dışındaysa sağ taraflı, içindeyse sol taraflı dizi seçilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00 ve 00:55:00; Schaum Problem 4.1). Aşağıdaki dizilerin z-dönüşümünü bulunuz: (a) $x[n]=-a^nu[-n-1]$, (b) $x[n]=a^{-n}u[-n-1]$.

> **Çözüm:** (a) $X(z)=-\sum_{n=1}^{\infty}(a^{-1}z)^n=1-\frac{1}{1-a^{-1}z}=\frac{z}{z-a}$, $|z|<|a|$. (b) $X(z)=\sum_{n=1}^{\infty}(az)^n=\frac{1}{1-az}-1=-\frac{z}{z-1/a}$, $|z|<\frac{1}{|a|}$. (Ayrıntı: Bölüm 5.1 ve 5.2.)

**Soru 2** (derste sözlü, 01:17:10). $x[n]=a^n$ ($n\ge0$), $x[n]=-b^n$ ($n<0$) dizisinin z-dönüşümünü, kutup ve sıfırlarını ve ROC'sini bulunuz.

> **Çözüm:** $X(z)=\frac{z}{z-a}+\frac{z}{z-b}=\frac{z(2z-(a+b))}{(z-a)(z-b)}$. Sıfırlar $0$ ve $\frac{a+b}{2}$, kutuplar $a$ ve $b$, ROC $|a|<|z|<|b|$.

**Soru 3** (derste sözlü, 01:25:28; Örnek 12.5). $x[n]=(0{,}5^n+2)u[n]$ dizisinin z-dönüşümünü ve ROC'sini bulunuz. <!-- BELİRSİZ: slayt karelerde görünmüyor. -->

> **Çözüm:** $X(z)=\frac{1}{1-0{,}5z^{-1}}+\frac{2}{1-z^{-1}}$, ROC $|z|>1$.

**Soru 4** (ekrandan, 02:00:00; Örnek 12.9). $X(z)=\frac{z^{-4}}{z-1}+z^{-6}+\frac{z^{-3}}{z+0{,}5}$ ise $x[n]$ nedir?

> **Çözüm:** $x[n]=u[n-5]+\delta[n-6]+(-0{,}5)^{n-4}u[n-4]$.

**Soru 5** (ekrandan, 02:05:00; Örnek 12.10). $F(z)=\frac{10z(z+5)}{(z-1)(z-2)(z+3)}$ ise $f[n]$ nedir?

> **Çözüm:** $f[n]=(-3)^nu[n]+14\cdot2^nu[n]-15u[n]$.

**Soru 6** (ekrandan, 02:10:00; Örnek 12.11). $x[n]=7\left(-\tfrac13\right)^nu[n]-\left(\tfrac12\right)^nu[-n-1]$ için $X(z)$'yi bulunuz, kutup-sıfır diyagramını ve yakınsaklık bölgesini çiziniz.

> **Çözüm:** $X(z)=\frac{z(8z-19/6)}{(z+1/3)(z-1/2)}$; kutuplar $-\tfrac13$ ve $\tfrac12$, sıfırlar $0$ ve $\tfrac{19}{48}$; ROC $\tfrac13<|z|<\tfrac12$.

**Soru 7** (derste sözlü, 01:38:17; MATLAB uygulaması). $X(z)=\dfrac{a+bz^{-1}+cz^{-2}+\dots}{e+fz^{-1}+gz^{-2}+\dots}$ biçiminde, pay ve payda uzunlukları 2 ile 10 arasında ve bütün katsayıları $[-1,1]$ aralığında rastgele seçilen üç farklı transfer fonksiyonu için `tf2zp` ile sıfır ve kutupları bulunuz, `zplane` ile kutup-sıfır grafiğini çiziniz; iki fonksiyonun ne işe yaradığını açıklayınız.

> **Çözüm (derste verilmedi):** Katsayılar rastgele olduğu için sayısal sonuç her çalıştırmada değişir. Yol: pay katsayılarını `b`, payda katsayılarını `a` vektörüne atayın; `[z,p,k] = tf2zp(b,a)` ile sıfırları, kutupları ve kazancı bulun; `zplane(z,p)` ile çizin. Kutupların birim çemberin içinde ya da dışında kalması grafikte doğrudan görülür. Bölüm 9.3'teki ek bilgiye göre farklı uzunluklu $z^{-1}$ polinomlarında `tf2zpk` daha uygundur.

**Soru 8** (ekrandan, 02:25:00; Schaum Problem 4.6, hocanın önerdiği bölüm sonu sorularından). Aşağıdaki dizilerin z-dönüşümünü bulunuz ve ROC ile birlikte kutup-sıfır grafiğini çiziniz: (a) $x[n]=(\tfrac12)^nu[n]+(\tfrac13)^nu[n]$, (b) $x[n]=(\tfrac13)^nu[n]+(\tfrac12)^nu[-n-1]$, (c) $x[n]=(\tfrac12)^nu[n]+(\tfrac13)^nu[-n-1]$.

> **Çözüm (derste verilmedi):** (a) $X(z)=\frac{z}{z-1/2}+\frac{z}{z-1/3}=\frac{z(2z-5/6)}{(z-1/2)(z-1/3)}$; sıfırlar $0$ ve $\tfrac{5}{12}$, kutuplar $\tfrac12$ ve $\tfrac13$; ROC $|z|>\tfrac12$. (b) $(\tfrac12)^nu[-n-1]\leftrightarrow-\frac{z}{z-1/2}$, $|z|<\tfrac12$; $X(z)=\frac{z}{z-1/3}-\frac{z}{z-1/2}=\frac{-\tfrac16z}{(z-1/3)(z-1/2)}$; sıfır $0$'da, kutuplar $\tfrac13$ ve $\tfrac12$; ROC $\tfrac13<|z|<\tfrac12$. (c) Birinci parça $|z|>\tfrac12$, ikinci parça $|z|<\tfrac13$ ister; kesişim boştur, dolayısıyla $X(z)$ yoktur. (a) ve (b) Python ile $z=1$ ve $z=0{,}4$ noktalarında sayısal toplamla doğrulandı.

## Dersin Toparlaması

Bu derste z-dönüşümü, DTFT'nin genelleştirilmiş hâli ve Laplace dönüşümünün ayrık zamandaki karşılığı olarak tanıtıldı. $X(z)=\sum x[n]z^{-n}$ tanımında $z=re^{j\Omega}$ karmaşık değişkendir; $r=1$ iken dönüşüm DTFT'ye indirgenir. Sonucun her zaman bir yakınsaklık bölgesiyle birlikte verilmesi gerektiği, $a^nu[n]$ ile $-a^nu[-n-1]$ örneğinde görüldü: ikisi de $\frac{z}{z-a}$ verir, ama biri $|z|>|a|$, diğeri $|z|<|a|$ bölgesinde geçerlidir. ROC'nin özellikleri (halka ya da disk biçimi, kutup içermemesi, sağ ve sol taraflı dizilerde dışa ya da içe uzanması, DTFT için birim çemberi kapsaması), doğrusallık ve öteleme özellikleri, kutup-sıfır grafiği, transfer fonksiyonu $H(z)$ ve konvolüsyonun z domeninde çarpmaya dönüşmesi işlendi.

Dersin son bölümünde ters z-dönüşümü kısmi kesirlere açılım ve seri açılımı yöntemleriyle ele alındı; öteleme özelliği, kısmi kesirler ve iki taraflı dizi ROC'si üzerine örnekler çözüldü. Hoca $X(z)$'nin bulunması, kutup-sıfır çizimi ve basit ters dönüşümler üzerine Schaum kitabının z-dönüşümü bölümündeki soruların çalışılmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
