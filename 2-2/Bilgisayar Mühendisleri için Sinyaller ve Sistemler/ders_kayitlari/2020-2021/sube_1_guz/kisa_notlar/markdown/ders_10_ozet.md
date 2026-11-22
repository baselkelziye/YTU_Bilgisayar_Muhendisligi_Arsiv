# Ders 10 Çalışma Özeti

## Genel Konular

- Kaynaklar ve dersin yeri
  - Sürekli zamanda Fourier analizi M. J. Roberts slaytlarının Lecture 6 bölümünde, ayrık zamanda Fourier analizi Lecture 7 bölümünde yer alır. Hoca, slaytların ispatlara fazla girdiğini söyleyerek temel kavramları Schaum serisinin Signals and Systems kitabının 5. bölümünden (sürekli zaman) anlattı; 6. bölüm ayrık zamandır (ekrandan, 00:35:00).
  - Bu derste yalnız sürekli zaman işlendi; ayrık zamanlı Fourier serisi ve dönüşümü sonraki derse kaldı.
- Önceki dersin tekrarı: impulstan sinüzoide
  - Önceki konularda giriş işareti ölçeklenmiş ve kaydırılmış impulsların toplamı olarak yazılmış, çıkış $h(t)$ ya da $h[n]$ ile konvolüsyonla bulunmuştu.
  - Fourier yaklaşımında giriş, farklı frekanslardaki karmaşık sinüzoidlerin (karmaşık üstellerin) toplamı olarak yazılır: $e^{j\omega t}=\cos\omega t+j\sin\omega t$, $\omega=2\pi f$.
  - Üçgen dalga örneği: önce ortalama değer (DC bileşen, 0,5) yazılır, sonra temel frekanslı sinüs, ardından temel frekansın 2 katı eklenir. Bu örnekte 3. harmoniğin genliği sıfırdır, 4. harmonik eklenir. Terim eklendikçe toplam üçgene yaklaşır.
  - Slayttaki tanım: $x(t)=\sum_{k=-\infty}^{\infty}c_x[k]\,e^{j2\pi kt/T}$; $c_x[k]$ harmonik fonksiyon, $k$ harmonik sayısıdır. Harmonik fonksiyon diklik (orthogonality) ilkesiyle bulunur (ekrandan, 00:25:00).
- Periyodik işaret ve temel frekans
  - $x(t+T)=x(t)$ olan işaret periyodiktir. $T$'nin en küçük pozitif değeri temel periyot $T_0$'dır. Temel frekans $f_0=1/T_0$, temel açısal frekans $\omega_0=2\pi/T_0=2\pi f_0$'dır (ekrandan, 00:35:00).
  - İşaret 3 saniyede bir tekrar ediyorsa 6 saniyede de tekrar eder; temel periyot en küçüğü olan 3 saniyedir.
- Karmaşık üstel Fourier serisi
  - $x(t)=\sum_{k=-\infty}^{\infty}c_k e^{jk\omega_0 t}$, $\omega_0=2\pi/T_0$ (ekrandan, 00:35:00).
  - Karmaşık Fourier katsayıları: $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0 t}\,dt$. İntegral herhangi bir periyot boyuncadır; genelde $0$–$T_0$ ya da $-T_0/2$–$T_0/2$ alınır (ekrandan, 00:40:00).
  - $k=0$ için $c_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$, yani işaretin bir periyottaki ortalaması (DC bileşen).
  - $x(t)$ gerçel ise $c_{-k}=c_k^*$. Negatif ve pozitif indisli katsayıların genlikleri eşit, açıları ters işaretlidir.
- Karmaşık sayı hatırlatması
  - $z=a+jb$, $|z|=r=\sqrt{a^2+b^2}$, $\theta=\arctan(b/a)$; aynı sayı $z=re^{j\theta}$ diye de yazılır (ekrandan, 00:45:00). Eşleniğin açısı $\arctan(-b/a)$ olur.
- Trigonometrik Fourier serisi
  - $x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}(a_k\cos k\omega_0 t+b_k\sin k\omega_0 t)$.
  - $a_k=\frac{2}{T_0}\int_{T_0}x(t)\cos k\omega_0 t\,dt$, $b_k=\frac{2}{T_0}\int_{T_0}x(t)\sin k\omega_0 t\,dt$.
  - Karmaşık katsayılarla bağ: $\frac{a_0}{2}=c_0$, $a_k=c_k+c_{-k}$, $b_k=j(c_k-c_{-k})$; tersi $c_k=\frac12(a_k-jb_k)$, $c_{-k}=\frac12(a_k+jb_k)$ (ekrandan, 00:50:00).
  - $x(t)$ gerçel ise $a_k=2\,\mathrm{Re}[c_k]$, $b_k=-2\,\mathrm{Im}[c_k]$.
  - Çift işaretin ($x(-t)=x(t)$) serisinde yalnız kosinüs terimleri bulunur ($b_k=0$). Tek işaretin ($x(-t)=-x(t)$) serisinde yalnız sinüs terimleri bulunur ($a_k=0$).
- Harmonik form
  - Üçüncü gösterim: $x(t)=C_0+\sum_{k=1}^{\infty}C_k\cos(k\omega_0 t-\theta_k)$. Sinüs ve kosinüs tek bir fazlı kosinüste birleşir. Katsayıları $a_0,a_k,b_k$'dan bulunur. Hoca bu formun ayrıntısına girmedi.
- Dirichlet koşulları
  - Periyodik işaretin Fourier serisi açılımı için yeterli (gerekli değil) üç koşul: bir periyotta mutlak integrallenebilir olması ($\int_{T_0}|x(t)|\,dt<\infty$), her sonlu aralıkta sonlu sayıda maksimum ve minimum, sonlu sayıda ve sonlu büyüklükte süreksizlik (ekrandan, 00:55:00).
- Genlik ve faz spektrumu
  - $c_k=|c_k|e^{j\phi_k}$ yazılır. $|c_k|$'nın $\omega$'ya göre çizimi genlik spektrumu, $\phi_k$'nın çizimi faz spektrumudur. $k$ tam sayı olduğundan spektrumlar ayrıktır ($k\omega_0$ noktalarında).
  - Gerçel periyodik işarette genlik spektrumu $\omega$'nın çift, faz spektrumu tek fonksiyonudur (ekrandan, 01:00:00).
- Periyodik işaretin gücü ve Parseval teoremi
  - Ortalama güç: $P=\frac{1}{T_0}\int_{T_0}|x(t)|^2dt$. Parseval özdeşliği: $P=\sum_{k=-\infty}^{\infty}|c_k|^2$ (ekrandan, 01:00:00). Zaman domenindeki güç, frekans domenindeki katsayıların karelerinin toplamına eşittir.
  - Trigonometrik katsayılarla: $P=\frac14a_0^2+\frac12\sum_{n=1}^{\infty}(a_n^2+b_n^2)$. Bir sinüzoidin gücü $R=1$ alınınca $V_{rms}^2=V_p^2/2$, yani $A^2/2$'dir.
- Fourier serisinden Fourier dönüşümüne
  - Sonlu süreli, periyodik olmayan $x(t)$ ($|t|>T_1$ için $x(t)=0$) $T_0$ periyoduyla tekrar ettirilerek periyodik $x_{T_0}(t)$ elde edilir (ekrandan, 01:15:00). $T_1$ ile $T_0$ farklı büyüklüklerdir.
  - $c_k=\frac{1}{T_0}\int_{-\infty}^{\infty}x(t)e^{-jk\omega_0 t}dt$; $X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt$ tanımlanınca $c_k=\frac{1}{T_0}X(k\omega_0)$ olur.
  - $x_{T_0}(t)=\frac{1}{2\pi}\sum_k X(k\omega_0)e^{jk\omega_0 t}\omega_0$. $T_0\to\infty$ iken $\omega_0\to0$ (sonsuz küçük, $\Delta\omega$), periyodik işaret tek $x(t)$'ye iner ve toplam integrale dönüşür (ekrandan, 01:20:00).
- Fourier dönüşüm çifti ve spektrum
  - $X(\omega)=\mathcal{F}\{x(t)\}=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt$, $x(t)=\mathcal{F}^{-1}\{X(\omega)\}=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(\omega)e^{j\omega t}d\omega$, $x(t)\leftrightarrow X(\omega)$ (ekrandan, 01:25:00).
  - $X(\omega)=|X(\omega)|e^{j\phi(\omega)}$; $|X(\omega)|$ genlik (magnitude) spektrumu, $\phi(\omega)$ faz spektrumudur. Gerçel işarette $X(-\omega)=X^*(\omega)$; genlik spektrumu çift, faz spektrumu tektir.
- Fourier dönüşümünün özellikleri
  - Doğrusallık: $a_1x_1(t)+a_2x_2(t)\leftrightarrow a_1X_1(\omega)+a_2X_2(\omega)$.
  - Zamanda kaydırma: $x(t-t_0)\leftrightarrow e^{-j\omega t_0}X(\omega)$.
  - Frekansta kaydırma (karmaşık modülasyon): $e^{j\omega_0 t}x(t)\leftrightarrow X(\omega-\omega_0)$. Radyo yayınlarının farklı frekans bantlarına kaydırılması bu ilkeye dayanır.
  - Zamanda ölçekleme: $x(at)\leftrightarrow\frac{1}{|a|}X(\omega/a)$. Zamanda ters çevirme: $x(-t)\leftrightarrow X(-\omega)$; genlik değişmez, fazın işareti değişir.
  - Dualite: $X(t)\leftrightarrow2\pi x(-\omega)$ (ekrandan, 01:35:00). Hoca ayrıntısına girmedi.
  - Zamanda türev: $\frac{dx(t)}{dt}\leftrightarrow j\omega X(\omega)$; frekansta türev: $(-jt)x(t)\leftrightarrow\frac{dX(\omega)}{d\omega}$; zamanda integral: $\int_{-\infty}^{t}x(\tau)d\tau\leftrightarrow\pi X(0)\delta(\omega)+\frac{1}{j\omega}X(\omega)$ (ekrandan, 01:35:00).
  - Konvolüsyon: $x_1(t)*x_2(t)\leftrightarrow X_1(\omega)X_2(\omega)$. Zamandaki çarpma da frekansta konvolüsyona karşılık gelir.
  - Parseval: $\int_{-\infty}^{\infty}|x(t)|^2dt=\frac{1}{2\pi}\int_{-\infty}^{\infty}|X(\omega)|^2d\omega$; iki domende enerji korunur.
- Yaygın Fourier dönüşüm çiftleri (Tablo 5-2, ekrandan, 01:40:00)
  - $\delta(t)\leftrightarrow1$, $\delta(t-t_0)\leftrightarrow e^{-j\omega t_0}$, $1\leftrightarrow2\pi\delta(\omega)$, $e^{j\omega_0 t}\leftrightarrow2\pi\delta(\omega-\omega_0)$.
  - $\cos\omega_0 t\leftrightarrow\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$, $\sin\omega_0 t\leftrightarrow-j\pi[\delta(\omega-\omega_0)-\delta(\omega+\omega_0)]$.
  - $u(t)\leftrightarrow\pi\delta(\omega)+\frac{1}{j\omega}$, $e^{-at}u(t)\leftrightarrow\frac{1}{j\omega+a}$ ($a>0$), $te^{-at}u(t)\leftrightarrow\frac{1}{(j\omega+a)^2}$, $e^{-a|t|}\leftrightarrow\frac{2a}{a^2+\omega^2}$.
  - Yorum: impulsun bütün frekanslarda bileşeni vardır. Sabit (DC) işaretin yalnız sıfır frekansında bileşeni vardır. Kosinüsün $\pm\omega_0$'da genliği $\pi$ olan iki impulsu vardır.
- Frekans cevabı
  - LTI sistemde $y(t)=x(t)*h(t)$ iken frekans domeninde $Y(\omega)=X(\omega)H(\omega)$. Konvolüsyon yerine çarpma yapılır, $y(t)$ ters dönüşümle bulunur (ekrandan, 01:45:00).
  - $x(t)=e^{j\omega_0 t}$ için $X(\omega)=2\pi\delta(\omega-\omega_0)$, $Y(\omega)=2\pi H(\omega_0)\delta(\omega-\omega_0)$, $y(t)=H(\omega_0)e^{j\omega_0 t}$. Karmaşık üstel, LTI sistemin öz fonksiyonudur; öz değeri $H(\omega_0)$'dır.
  - Giriş $\sum_k c_ke^{jk\omega_0 t}$ ise çıkış $\sum_k c_kH(k\omega_0)e^{jk\omega_0 t}$ olur. Karmaşık üstel tek bir (pozitif) frekansta impuls ürettiği için, kosinüsün iki impulsuna göre işlemleri basitleştirir.
- Fourier serisi soru çözümleri (Sorular 2, Fourier Serileri)
  - Kare dalga, $f(t)=t$ testere dişi, parçalı doğrusal işaret, tek simetrili işaret ve $e^t$ işaretinin trigonometrik ve karmaşık Fourier serileri bulundu. Ayrıntılar aşağıdaki Detaylı Açıklamalar bölümündedir.
  - Simetri kuralları: çift fonksiyonda $\int_{-A}^{A}f\,dt=2\int_0^Af\,dt$; tek fonksiyonda $\int_{-A}^{A}f\,dt=0$ (ekrandan, 02:25:00). Çift × çift = çift, tek × tek = çift, çift × tek = tek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bütün anlatımın temeli $x(t)=\sum c_ke^{jk\omega_0 t}$ ifadesidir.
  - $c_k$, $k\omega_0$ frekanslı bileşenin toplama hangi genlikle katıldığını gösterir. $c_k=0$ ise o frekans işarette yoktur.
- Karmaşık üstel ve trigonometrik seri yaklaşımları Fourier analizinde bilinmesi gereken iki temel çözümdür.
  - Hangisiyle integral daha kolay alınıyorsa o kullanılır. Karmaşık katsayılar çoğu zaman daha kolay bulunur.
- $c_0$'ı ayrıca hesaplamak gerekir.
  - Genel $c_n$ ifadesinde $n=0$ konunca her zaman doğru sonuç çıkmaz. Kare dalga örneğinde genel ifade $n=0$ için $0$ verir, oysa $c_0=1/2$'dir (ekrandan, 02:45:00).
- Fourier serisi ile Fourier dönüşümü arasındaki fark
  - Fourier serisi işaretin periyodik olduğu varsayımına dayanır. Fourier dönüşümü $T_0\to\infty$ limitiyle periyodik olmayan herhangi bir işarete genişletilmiş hâlidir.
- Frekans domeninin asıl kazancı konvolüsyonun çarpmaya dönüşmesidir.
  - Uzun işaretlerde konvolüsyon zahmetlidir. Dönüşüm, çarpma ve ters dönüşüm daha kolay olabilir.
- $\sin n\pi=0$ ve $\cos n\pi=(-1)^n$ ($n$ tam sayı) eşitlikleri çözümlerde sürekli kullanılır; temel integral kuralları (kısmi integrasyon dahil) tekrar edilmelidir.
- Ders matematik ağırlıklıdır; konular biriktirilmeden, örnek sorular çözülerek çalışılmalıdır.

## Kısa Tekrar Notları

- $f_0=1/T_0$, $\omega_0=2\pi/T_0$.
- $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0t}dt$, $c_0$ = ortalama, gerçel $x$ için $c_{-k}=c_k^*$.
- $a_0/2=c_0$, $a_k=c_k+c_{-k}$, $b_k=j(c_k-c_{-k})$, $c_k=(a_k-jb_k)/2$.
- Çift işaret: yalnız kosinüs ($b_k=0$); tek işaret: yalnız sinüs ($a_k=0$, $a_0=0$).
- Dirichlet: mutlak integrallenebilir, sonlu ekstremum, sonlu süreksizlik (yeterli koşul).
- Genlik spektrumu çift, faz spektrumu tek.
- Parseval (seri): $P=\sum|c_k|^2=\frac14a_0^2+\frac12\sum(a_n^2+b_n^2)$.
- $X(\omega)=\int x(t)e^{-j\omega t}dt$, $x(t)=\frac{1}{2\pi}\int X(\omega)e^{j\omega t}d\omega$, $c_k=X(k\omega_0)/T_0$.
- Kaydırma $\to e^{-j\omega t_0}$; modülasyon $\to X(\omega-\omega_0)$; türev $\to j\omega$; konvolüsyon $\to$ çarpma.
- $\delta(t)\leftrightarrow1$, $1\leftrightarrow2\pi\delta(\omega)$, $e^{j\omega_0t}\leftrightarrow2\pi\delta(\omega-\omega_0)$, $\cos\omega_0t\leftrightarrow\pi[\delta(\omega-\omega_0)+\delta(\omega+\omega_0)]$.
- $Y(\omega)=H(\omega)X(\omega)$; $e^{j\omega_0t}\to H(\omega_0)e^{j\omega_0t}$.

## Detaylı Açıklamalar

- Fourier serisinin fikri, periyodik bir işareti DC bileşen ile temel frekansın tam katlarındaki (harmoniklerdeki) sinüzoidlerin ağırlıklı toplamı olarak yazmaktır. Gerçek işaretlerde sonsuz sayıda frekans bulunmaz; belli bir harmonikten sonra katsayılar ihmal edilebilecek kadar küçülür. Katsayıların bulunması işaretin "çözümlenmesi"dir; bu yüzden Fourier serisi hesabına harmonik analiz de denir.
- Karmaşık üstel gösterimde negatif frekanslar da yer alır. Gerçel bir işarette $c_{-k}$ ile $c_k$ birbirinin eşleniğidir. Bu yüzden $|c_k|$ çizimi (genlik spektrumu) eksene göre simetrik (çift), açı çizimi (faz spektrumu) tek simetriktir. Aynı özellik Fourier dönüşümünde $X(-\omega)=X^*(\omega)$ olarak sürer.
- Fourier dönüşümünün türetilmesi: sonlu süreli bir darbe, periyodu $T_0$ olan bir dizi olarak tekrarlanır ve bu periyodik işaretin serisi yazılır. $c_k$'daki integral sınırları $\pm\infty$'a genişletilebilir, çünkü bir periyot dışında $x(t)=0$'dır. $X(\omega)$ tanımıyla $c_k=X(k\omega_0)/T_0$ olur. $T_0$ büyüdükçe harmonikler arası uzaklık $\omega_0$ küçülür. Limitte tekrarlar sonsuza itilir, yalnız tek darbe kalır ve $\sum X(k\Delta\omega)e^{jk\Delta\omega t}\Delta\omega$ toplamı $\int X(\omega)e^{j\omega t}d\omega$ integraline dönüşür. Böylece ayrık çizgi spektrumu sürekli bir spektruma geçer.
- **Örnek 1 (kare dalga, ekrandan, 02:00:00):** $T=2$, $0<t<1$ için $f(t)=1$, $1<t<2$ için $f(t)=0$; $\omega=2\pi/T=\pi$.
  - $a_0=\frac22\int_0^1 1\,dt=1$.
  - $a_n=\int_0^1\cos n\pi t\,dt=\left[\frac{\sin n\pi t}{n\pi}\right]_0^1=\frac{\sin n\pi}{n\pi}=0$.
  - $b_n=\int_0^1\sin n\pi t\,dt=\left[-\frac{\cos n\pi t}{n\pi}\right]_0^1=\frac{1-\cos n\pi}{n\pi}=\frac{1-(-1)^n}{n\pi}$. Tek $n$ için $\frac{2}{n\pi}$, çift $n$ için $0$.
  - Sonuç: $f(t)=\frac12+\frac{2}{\pi}\sin\pi t+\frac{2}{3\pi}\sin3\pi t+\frac{2}{5\pi}\sin5\pi t+\dots$ Terim sayısı arttıkça (slaytta 23. harmoniğe kadar) toplam kare dalgaya yaklaşır. Değerler python ile doğrulandı.
- **Örnek 2 (ekrandan, 02:15:00):** $-1\le t\le1$ için $f(t)=t$, $f(t+2)=f(t)$.
  - Ortalama sıfırdır: $a_0=0$. İşaret tek olduğundan $a_n=0$.
  - $b_n=\int_{-1}^{1}t\sin n\pi t\,dt$ kısmi integrasyonla $\frac{2(-1)^{n+1}}{n\pi}$ çıkar.
  - Sonuç (ekrandan, 02:20:00): $f(t)=\sum_{n=1}^{\infty}\frac{2(-1)^{n+1}}{n\pi}\sin n\pi t=\frac{2}{\pi}\sin\pi t-\frac{2}{2\pi}\sin2\pi t+\frac{2}{3\pi}\sin3\pi t-\dots$ (python ile doğrulandı).
- **Örnek 3:** $0<t<2$ için $f(t)=2-t$, $2<t<4$ için $f(t)=0$, $T=4$, $\omega=\pi/2$.
  - $a_0=\frac24\int_0^2(2-t)\,dt=1$.
  - Ders sonrası not: Hoca $a_0$ için "işaretin ortalaması 1" dedi; işaretin ortalaması $a_0/2=c_0=1/2$'dir, $a_0$ ise ortalamanın iki katıdır.
  - Derste $b_n=\frac{2}{n\pi}$ okundu. Hoca slayttaki $\sin 2n\pi$ yazımının bir yazım hatası olabileceğini söyledi ($\sin2n\pi=0$).
  - <!-- BELİRSİZ: Slayttaki a_n ifadesi kareden okunamadı; python ile a_n = 2(1-(-1)^n)/(n pi)^2 bulundu. -->
  - Python ile: $a_n=\frac{2[1-(-1)^n]}{n^2\pi^2}$, $b_n=\frac{2}{n\pi}$.
- **Örnek 4 (tek simetri, ekrandan, 02:30:00):** $T=4$; $-2<t<-1$ için $-1$, $-1<t<1$ için $t$, $1<t<2$ için $1$. İşaret tek olduğundan $a_0=a_n=0$ ve $b_n=\frac{4}{T}\int_0^{2}f(t)\sin\frac{n\pi t}{2}dt$.
  - Slayttaki sonuç: $f(t)=2\sum_{n=1}^{\infty}\frac{(-1)^{n+1}}{n\pi}\sin\frac{n\pi t}{2}$; burada $-\cos n\pi=(-1)^{n+1}$ yazılmıştır.
  - Ders sonrası not: Hoca $T=4$ için temel frekansın 4 olduğunu söyledi; doğrusu $\omega=2\pi/4=\pi/2$'dir. Ayrıca python ile hesaplanan katsayı $b_n=\frac{4\sin(n\pi/2)}{n^2\pi^2}-\frac{2\cos n\pi}{n\pi}$'dir. Slayttaki sonuçta $\frac{4\sin(n\pi/2)}{n^2\pi^2}$ terimi eksiktir (örneğin $b_1\approx1{,}042$, slayttaki formül $0{,}637$ verir).
- **$e^t$ işaretinin karmaşık serisi (ekrandan, 02:40:00):** $0<t<2\pi$ için $f(t)=e^t$, $T=2\pi$, $\omega=1$.
  - $c_n=\frac{1}{2\pi}\int_0^{2\pi}e^{(1-jn)t}dt=\frac{e^{2\pi(1-jn)}-1}{2\pi(1-jn)}$. $e^{-j2n\pi}=\cos2n\pi-j\sin2n\pi=1$ olduğundan $c_n=\frac{e^{2\pi}-1}{2\pi(1-jn)}$.
  - $c_0=\frac{e^{2\pi}-1}{2\pi}$; sonuç $f(t)=\sum_{n=-\infty}^{\infty}\frac{e^{2\pi}-1}{2\pi(1-jn)}e^{jnt}$ (ekrandan, 02:45:00).
  - $c_n$ karmaşıktır ve $n\omega$'ya bağlıdır; $|c_n|$, $n\omega$'ya karşı çizilir. Çizim çifttir ve frekans arttıkça azalır; işaretin ağırlığı düşük frekanslardadır.
  - Ders sonrası not: Hoca $c_0$ değerini "0,85" diye okudu; $\frac{e^{2\pi}-1}{2\pi}\approx85{,}07$'dir. $|c_1|\approx60{,}15$, $|c_2|\approx38{,}04$ (python ile hesaplandı).
- **Örnek 1'in karmaşık serisi:** $T=2$, $\omega=\pi$.
  - $c_0=\frac12$ (ortalama).
  - $c_n=\frac12\int_0^1e^{-jn\pi t}dt=\frac{1-e^{-jn\pi}}{2jn\pi}=\frac{1-(-1)^n}{2jn\pi}$. Tek $n$ için $c_n=\frac{1}{jn\pi}=-\frac{j}{n\pi}$, çift $n$ için $0$.
  - Genel ifade $n=0$ için $c_0$'ı vermez; bu yüzden $f(t)=\frac12+\sum_{n\ \text{tek}}\frac{1}{jn\pi}e^{jn\pi t}$ yazılır. $|c_n|$'ın çizimi işaretin genlik spektrumudur; tek harmoniklerde değer vardır, çiftlerde yoktur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
