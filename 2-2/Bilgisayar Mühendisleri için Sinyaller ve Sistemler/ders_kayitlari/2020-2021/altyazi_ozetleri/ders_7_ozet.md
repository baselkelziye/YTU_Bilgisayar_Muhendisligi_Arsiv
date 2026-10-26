# Ders 7 Çalışma Özeti

## Genel Konular

- Dersin tarihi 18 Ağustos 2021 Çarşamba (yaz okulu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:02:20'de başlar.
  - Hoca bu dersi sınav öncesi genel tekrar ve soru çözümü olarak planladı. Quiz soruları da çözüldü.
  - İki ara verildi: yaklaşık 00:53:45 - 01:03:20 ve 01:50:10 - 02:00:45.
  - Kaydın ikinci parçası (35 sn) sessizdir; içerik yoktur.
- Fourier serileri tekrarı
  - Periyodik bir işareti sinüzoidal işaretlerin toplamı olarak yazmak (decomposition).
  - $c_k$ katsayıları, $a_0$ (DC bileşen), $a_k$ (kosinüs) ve $b_k$ (sinüs) katsayıları.
  - Kare dalga örneği ve tek/çift simetri kısayolları.
  - Frekans spektrumu (genlik-frekans ve faz-frekans grafikleri).
  - Parseval teoremi ve ortalama güç.
- Fourier serisi örneği: $[0,1)$ aralığında $e^{-t}$, periyodu 2 olan işaret.
- Sınava hazırlık soruları
  - Ayrık işarette öteleme, ters çevirme ve $x[2n]$ işlemleri.
  - Sürekli işaretin örneklenmesi ($1-|t|$ işareti, $T_s = 0.25$ s).
  - Periyodiklik ve temel periyot (EKOK, EBOB).
  - Enerji ve güç işaretleri.
  - $u(t)$, $\delta(t)$ ile çarpma, türev ve $\mathrm{sgn}(t)$.
  - Sistem özellikleri: bellek, nedensellik, BIBO kararlılık, doğrusallık, zamanla değişmezlik.
  - Tek ve çift bileşenlere ayırma.
- Konvolüsyon tekrarı
  - Sürekli zamanda $t * t^2$ örneği.
  - İki birim darbenin konvolüsyonu (üçgen sonuç).
  - Ayrık zamanda $[1,1,1,1] * [1,1,1]$ ve dağılma özelliği ile çözüm.
- Quiz sorularının çözümü ve puan düzeltmeleri.
- Frekans spektrumundan işareti yazma örnekleri ve temel frekans (EBOB ile).

## Hocanın Özellikle Vurguladığı Kısımlar

- Temel frekans, frekans bileşenlerinin EBOB'u (GCD) ile bulunur.
  - En küçük frekans her zaman temel frekans değildir. Örnek: 100 Hz ve 250 Hz bileşenleri için $f_0 = 50$ Hz.
  - Temel periyot, periyotların EKOK'u (LCM) ile bulunur.
- Ayrık işareti sürekli gibi çizmek soruyu doğrudan yanlış yapar.
  - Ayrık işaret çubuklarla (stem) çizilir.
- Vektörel gösterimde sıfır noktası mutlaka belirtilmelidir.
  - Altını çizerek veya "kaçıncı örnek" diye yazarak gösterilebilir.
- Bir sabit sayıyla konvolüsyon, o sayıyla çarpmakla aynıdır.
  - İki işaret (vektör) söz konusuysa çarpma ve konvolüsyon aynı değildir.
- $e^{-j\theta} = \cos\theta - j\sin\theta$ ve $\cos(a-b)$ açılımı çok iyi bilinmeli.
  - Sınavda bu dönüşümler sık kullanılır.
- Fourier serisinde integrali çok parçalı yapmamak için başlangıç noktasını akıllıca seçin.
- Tek işarette $a_k$, çift işarette $b_k$ katsayıları sıfırdır. Bunu görürseniz hesaplamaya gerek yok.
- Sınav hakkında
  - 4 veya 5 soru, 90 dakika. Paylaşılan örneklerin benzerleri gelebilir.
  - Çok ağır integral sorulmayacak.
  - Konvolüsyon sorusunda adımlar gösterilmeli.

## Kısa Tekrar Notları

- Fourier serisi (karmaşık form): $x(t) = \sum_{k=-\infty}^{\infty} c_k e^{jk\omega_0 t}$, $c_k = \frac{1}{T}\int_{T} x(t)e^{-jk\omega_0 t}\,dt$.
- DC bileşen: $c_0 = \frac{1}{T}\int_T x(t)\,dt$ (bir periyottaki alanın periyoda oranı).
- Trigonometrik form: $a_k = 2\,\mathrm{Re}\{c_k\}$, $b_k = -2\,\mathrm{Im}\{c_k\}$.
- Kare dalga ($T=2$, $0\le t<1$ için 1): $c_0 = \tfrac12$, $c_k = \frac{-j}{k\pi}$ ($k$ tek), $c_k=0$ ($k$ çift).
  - $x(t) = \tfrac12 + \sum_{k\ \text{tek}} \frac{2}{k\pi}\sin(k\pi t)$.
- Temel frekans: $f_0 = \mathrm{EBOB}(f_1,\dots,f_n)$. Temel periyot: $T_0 = \mathrm{EKOK}(T_1,\dots,T_n)$.
- Sürekli zamanda iki sinüzoidin toplamı, $T_1/T_2$ rasyonel ise periyodiktir.
- Enerji: $E=\int |x(t)|^2dt$. $e^{-at}u(t)$ için $E = \frac{1}{2a}$ (enerji işareti).
- $t\,u(t)$: enerji de güç de sonsuz; ne enerji ne güç işaretidir.
- $\frac{d}{dt}u(t) = \delta(t)$; $\frac{d}{dt}\mathrm{sgn}(t) = 2\delta(t)$.
- Konvolüsyon: $(f*g)(t)=\int f(\tau)g(t-\tau)\,d\tau$. $t * t^2 = \frac{t^4}{12}$ ($t\ge0$).
- $[1,1,1,1]*[1,1,1] = [1,2,3,3,2,1]$.

## Detaylı Açıklamalar

### Fourier serisi tekrarı ve kare dalga

- Amaç, periyodik bir $x(t)$ işaretini sinüzoidal işaretler cinsinden yazmaktır.
  - Frekansı sıfır olan bileşen ayrı tutulur: $a_0$ (DC bileşen).
  - Diğer bileşenler temel frekansın katlarındadır: $\omega_0, 2\omega_0, 3\omega_0, \dots$
- Frekans işaretin periyodundan bulunur. Bilinmeyenler katsayılardır.
- Katsayılar, işareti bir periyot boyunca $e^{-jk\omega_0 t}$ ile çarpıp integral alarak bulunur.
  - Hoca bunu "işareti farklı frekanslı sinüzoidlerle karşılaştırmak" diye yorumladı. İşarette o frekansta bir bileşen varsa sonuç sıfırdan farklı çıkar.
- $k=0$ için $e^{0}=1$ olduğu için $c_0$ doğrudan işaretin ortalamasıdır.
- Kare dalga örneği ($T=2$, $\omega_0=\pi$):
  - $c_k = \frac12\int_0^1 e^{-jk\pi t}\,dt = \frac{j}{2k\pi}\left(e^{-jk\pi}-1\right)$.
  - $e^{-jk\pi} = \cos k\pi - j\sin k\pi = (-1)^k$.
  - $k$ çift: $c_k = 0$. $k$ tek: $c_k = \frac{-j}{k\pi}$.
  - $c_0 = \frac12$.
  - $c_k$'nın reel kısmı yok, bu yüzden $a_k = 0$. $b_k = -2\,\mathrm{Im}\{c_k\} = \frac{2}{k\pi}$.
  - Sonuç: $x(t) = \frac12 + \frac{2}{\pi}\sin(\pi t) + \frac{2}{3\pi}\sin(3\pi t) + \dots$
  - Faz bilgisi olarak her bileşende $-\pi/2$ vardır. $\cos(\theta - \pi/2) = \sin\theta$ olduğu için kosinüsler sinüse döner.
- Simetri kısayolları:
  - Çift işaret (y eksenine göre simetrik): yalnız kosinüs bileşenleri vardır, $b_k = 0$.
  - Tek işaret: yalnız sinüs bileşenleri vardır, $a_k = 0$.
  - Örnekteki kare dalga DC bileşen çıkarılınca tek işarettir; bu yüzden $a_k=0$ çıkar.

### Frekans spektrumu ve Parseval teoremi

- Spektrum, genliğin (ya da fazın) frekansa göre değişimini gösterir.
  - Zaman düzleminden frekans düzlemine geçilmiş olur.
- Gerçek işaretlerde genelde düşük frekanslarda genlik yüksek, yüksek frekanslarda düşüktür.
- Negatif frekanslar matematikte vardır. Hoca radar ve Doppler örneğini verdi. Bu ders kapsamında genelde pozitif taraf incelenir.
- "İlk 4 bileşeni çizin" gibi bir soruda önce temel frekans bulunur. Sonra bu frekansın katlarındaki genlikler çizilir. Örnek: $f_0 = 5$ ise 5, 10, 15, 20 Hz.
- Parseval teoremi: periyodik işaretin ortalama gücü, katsayıların karelerinin toplamına eşittir: $P = \frac1T\int_T |x(t)|^2dt = \sum_k |c_k|^2$.
- Hoca bir ödev fikrinden söz etti: bir sesin (örneğin "A" harfi) frekans, genlik ve faz bilgileriyle sinüzoidleri toplayıp MATLAB'de seslendirmek.

### Fourier serisi örneği: $e^{-t}$ parçalı işaret

- İşaret: $0\le t<1$ için $x(t)=e^{-t}$, $1\le t<2$ için $x(t)=0$. Periyot $T=2$, $\omega_0=\pi$ rad/s.
- $c_k = \frac12\int_0^1 e^{-t}e^{-jk\pi t}\,dt = \frac12\int_0^1 e^{-(1+jk\pi)t}\,dt$.
- Sonuç: $c_k = \frac{1 - e^{-1}(-1)^k}{2(1+jk\pi)}$.
  - $e^{-(1+jk\pi)} = e^{-1}e^{-jk\pi} = e^{-1}(-1)^k$ dönüşümü kullanıldı.
- İşaret ne tek ne çifttir. Hem sinüs hem kosinüs bileşenleri vardır.
  - $a_k$ ve $b_k$ için formül doğrudan uygulanmalıdır.
- Hoca spektrum grafiğini gösterdi. Frekans arttıkça genlik azalır. 30-40 bileşenle işaret büyük oranda elde edilir.

### Ayrık işaret işlemleri

- Verilen işaret: $x[n] = [0, \underline{0}, 1, 2, 3, 3]$ (altı çizili örnek $n=0$).
  - $x[1]=1$, $x[2]=2$, $x[3]=3$, $x[4]=3$.
- $x[n+2]$: işaret 2 birim sola kayar. $x[-1]=1$, $x[0]=2$, $x[1]=3$, $x[2]=3$.
- $x[-n+2]$: önce ötele, sonra ters çevir. Sonuç: $n=-2$ ve $n=-1$'de 3, $n=0$'da 2, $n=1$'de 1.
- $x[2n]$: yalnız çift indisli örnekler kalır. $n=0$'da 0, $n=1$'de $x[2]=2$, $n=2$'de $x[4]=3$.
  - $x[1]$ ve $x[3]$ kaybolur. Ayrık zamanda "1.5. örnek" diye bir şey yoktur.

### Sürekli işaretin örneklenmesi

- $x(t) = 1-|t|$ ($-1\le t\le 1$), diğer yerlerde 0. Bir üçgen işarettir.
- $T_s = 0.25$ s ile örnekleme: $x[n] = x(0.25n)$.
  - Sonuç: $[0,\ 0.25,\ 0.5,\ 0.75,\ \underline{1},\ 0.75,\ 0.5,\ 0.25,\ 0]$.
- $T_s = 0.5$ s ile örnekleme için aynı yöntem kullanılır: $[0,\ 0.5,\ \underline{1},\ 0.5,\ 0]$.

### Periyodiklik ve temel periyot

- $x(t) = \cos(t + \pi/4)$: $\omega_0 = 1$, $T_0 = 2\pi$. Sürekli zamanda tek bir sinüzoid her zaman periyodiktir.
- $x(t) = \cos(\frac{\pi}{3}t) + \sin(\frac{\pi}{4}t)$:
  - $T_1 = \frac{2\pi}{\pi/3} = 6$, $T_2 = \frac{2\pi}{\pi/4} = 8$.
  - $T_1/T_2 = 6/8$ rasyonel. İşaret periyodiktir.
  - Temel periyot $T_0 = \mathrm{EKOK}(6,8) = 24$.
  - Hoca bunu dairesel pistte farklı hızla koşan iki koşucunun başlangıçta buluşma sorusuna benzetti.
- $x(t) = \cos t + \sin(\sqrt2\,t)$:
  - $T_1 = 2\pi$, $T_2 = \sqrt2\,\pi$. $T_1/T_2 = \sqrt2$ irrasyonel. İşaret periyodik değildir.
- $x[n] = e^{j\pi n/4}$: $\Omega_0 = \pi/4$. $N_0 = \frac{2\pi}{\pi/4} = 8$ tam sayıdır. İşaret periyodiktir, $N_0 = 8$.

### Enerji ve güç

- $x(t) = e^{-at}u(t)$, $a>0$:
  - $E = \int_0^\infty e^{-2at}\,dt = \frac{1}{2a} < \infty$. Enerji işaretidir.
- $x(t) = t\,u(t)$:
  - $E = \lim_{T\to\infty}\int_0^{T/2} t^2\,dt = \lim \frac{(T/2)^3}{3} = \infty$.
  - $P = \lim_{T\to\infty}\frac1T\int_0^{T/2} t^2\,dt = \lim \frac{T^2}{24} = \infty$.
  - Ne enerji ne güç işaretidir.

### Basamak, darbe ve işaret fonksiyonları

- $x(t)\,\delta(t - 3/2)$: işaretin $t=3/2$ anındaki değerini örnekler; sonuç o noktada tek bir darbedir.
- $x(t)\,u(1-t)$: $u(1-t)$, $t\le1$ için 1'dir. İşaretin $t\le1$ kısmı kalır, gerisi silinir.
- $x(t)[u(t) - u(t-1)]$: yalnız $0\le t<1$ aralığı kalır. Bant geçiren bir pencere gibi davranır.
- Ayrık karşılıkları:
  - $x[n]u[1-n]$: $n\le1$ örnekleri kalır.
  - $x[n](u[n+2]-u[n])$: yalnız $n=-2$ ve $n=-1$ örnekleri kalır.
- $x(t) = u(t) - u(t-a)$, $a>0$: $0\le t<a$ aralığında 1 olan dikdörtgendir.
  - Türevi: $x'(t) = \delta(t) - \delta(t-a)$.
- $\mathrm{sgn}(t) = u(t) - u(-t)$. Türevi: $\delta(t) + \delta(-t) = 2\delta(t)$.

### Sistem özellikleri

- $y(t) = x(t)\cos(\omega_0 t)$ (modülatör):
  - Belleksiz: yalnız o anki girişe bağlı.
  - Nedensel.
  - BIBO kararlı: $|y(t)| \le |x(t)|$ çünkü $|\cos| \le 1$.
  - Doğrusal: hem çarpımsallık hem toplamsallık sağlanır.
  - Zamanla değişir: çıkışı ötelemek $x(t-t_0)\cos(\omega_0(t-t_0))$ verir. Girişi ötelemek $x(t-t_0)\cos(\omega_0 t)$ verir. İkisi eşit değildir.
  - $\cos(\omega_0 t)$ sistemin bir parçasıdır, giriş değildir. Doğrusallık testinde ölçek katsayısı yalnız $x(t)$'ye uygulanır.
- $y[n] = n\,x[n]$:
  - Belleksiz ve nedensel.
  - Doğrusal.
  - Zamanla değişir: $(n-n_0)x[n-n_0] \ne n\,x[n-n_0]$.
  - BIBO kararlı değildir (doğru gerekçe için ders sonrası notlara bakın).

### Tek ve çift bileşenler

- $x_e[n] = \frac{x[n]+x[-n]}{2}$, $x_o[n] = \frac{x[n]-x[-n]}{2}$.
- Örnek: $g[n] = \frac{\sin(2\pi n/7)}{1+n^2}$.
  - $\sin$ tek, $1+n^2$ çift fonksiyondur. Çarpım tektir.
  - Çift bileşen 0, tek bileşen $g[n]$'nin kendisidir.
- Hoca $\sin(2\pi n/7)$'yi $\sin(2\pi n)$ gibi sıfır sanmamak gerektiğini hatırlattı. Paydadaki 7 yüzünden sıfır değildir.

### Konvolüsyon tekrarı

- Konvolüsyon: işaretlerden biri ters çevrilir, kaydırılır, diğeriyle çarpılıp toplanır (integral alınır).
- $f(t) = t$, $g(t) = t^2$ ($t\ge0$):
  - $(f*g)(t) = \int_0^t (t-\tau)\tau^2\,d\tau = \frac{t^4}{3} - \frac{t^4}{4} = \frac{t^4}{12}$.
- İki birim darbe ($[0,1]$ aralığında 1):
  - $t<0$: örtüşme yok, sonuç 0.
  - $0\le t<1$: sonuç $t$.
  - $1\le t<2$: sonuç $2-t$.
  - $t\ge2$: sonuç 0.
  - Sonuç $t=1$'de tepe yapan bir üçgendir. Tepe noktası iki işaretin tam örtüştüğü andır.
- Ayrık örnek: $x[n] = [1,1,1,1]$, $y[n] = [1,1,1]$ (ikisi de $n=0$'dan başlar).
  - Kaydırarak çözüm: $[1,2,3,3,2,1]$.
  - Darbe gösterimi: $x[n] = \delta[n]+\delta[n-1]+\delta[n-2]+\delta[n-3]$.
  - Dağılma özelliği: $y[n]*x[n] = y[n] + y[n-1] + y[n-2] + y[n-3]$.
  - Ortak terimler toplanınca $\delta[n] + 2\delta[n-1] + 3\delta[n-2] + 3\delta[n-3] + 2\delta[n-4] + \delta[n-5]$ çıkar. Sonuç aynıdır.

### Quiz çözümü ve puan düzeltmeleri

- Soru 1: $x[n] = A\cos(\Omega_0 n + \theta)$ için yanlış ifade soruldu. Sistemdeki cevap D.
  - D: $\Omega_0 = 500$ için $T_0 = 1/250$ deniyordu. Hoca bunun yanlış olduğunu açıkladı.
  - Hoca B ve C seçeneklerinde $j$'nin yazımında hata olduğunu söyledi. B ve C işaretleyenler de puan alacak.
  - E ($\theta = -90^\circ$ için $A\sin(\Omega_0 n)$) doğrudur. $\cos(a - 90^\circ) = \sin a$.
- Soru 2: doğru ifade C (iki kanallı sesi hizalamak için öteleme).
  - A yanlış: $x[n+n_1]$, $n_1>0$ ise öne alma (advance) olur, gecikme değil.
  - B yanlış: piksel bit sayısı nicemleme seviye sayısıyla belirlenir.
  - D yanlış: $x[n/2]$ ile örnek sayısı artar ama kalite "kesinlikle" artmaz. İyi bir ara değerleme (interpolasyon) gerekir.
  - E yanlış: örnekleme frekansı $f_s \ge 2f_{max}$ ile belirlenir, nicemleme seviyesiyle değil.
- Bir başka soruda $e^{-t}\cos(2\pi t)$'nin sonsuzdaki değeri sorusu vardı. Değer 0'dır, sonsuz değil.
- Soru 4: yanlış ifade E (doğrusallık "veya" değil "ve" ister).
  - C seçeneğinde toplamın üst sınırına yanlışlıkla "$n$" yazılmıştı. C işaretleyenler de puan alacak.
- $x[n] = (0.5)^n u[n]$ işaretinin enerjisi $\sum (0.25)^n = 4/3$'tür. Enerji işaretidir.

### Spektrumdan işarete ve temel frekans örnekleri

- Spektrum: 0 Hz'de 10; $\pm100$ Hz'de $7e^{\mp j\pi/3}$; $\pm250$ Hz'de $4e^{\pm j\pi/2}$.
  - $x(t) = 10 + 14\cos(2\pi\,100\,t - \pi/3) + 8\cos(2\pi\,250\,t + \pi/2)$.
  - Eşlenik çiftler toplanınca genlik iki katına çıkar: $2\cdot7 = 14$, $2\cdot4 = 8$.
  - Temel frekans $\mathrm{EBOB}(100, 250) = 50$ Hz, temel periyot $1/50$ s. 50 Hz'de bileşen yoktur ama temel frekans yine 50 Hz'dir.
- Sentetik ses: 200, 400, 500, 1600, 1700 Hz bileşenleri. Temel frekans 100 Hz.
- 10, 30, 50 Hz bileşenleri için temel frekans 10 Hz.
- $e^{j\theta}$ ile ilgili hatırlatma: $e^{j\pi/2} = j$ ve $-1/j = j$.

### Ders sonrası notlar

- **$\pi$ rasyonel bir sayı değildir.** Hoca "$\pi = 22/7$, rasyoneldir" dedi. Bu yanlıştır. $\pi$ irrasyoneldir; $22/7$ yalnız yaklaşık değerdir.
  - $\cos(t+\pi/4)$'ün periyodik olduğu sonucu doğrudur, ama gerekçesi farklıdır. Sürekli zamanda tek bir sinüzoid her $\omega_0 \ne 0$ için periyodiktir. Periyodun rasyonel olması gerekmez.
  - Rasyonellik ölçütü iki durumda kullanılır. Sürekli zamanda birden fazla bileşen varsa $T_1/T_2$ rasyonel olmalıdır. Ayrık zamanda $\Omega_0/2\pi$ rasyonel olmalıdır.
  - Hoca ders 8'de ayrık zaman için bu konuyu kısmen düzeltti.
- **$x[n] = e^{j\pi n/4}$'ün periyodu 8'dir.** Derste ara adımlarda "4", "$8\pi$" ve "$1/8$" değerleri karıştı. Doğrusu: $N_0 = 2\pi/\Omega_0 = 2\pi/(\pi/4) = 8$.
- **$y[n] = n\,x[n]$ sisteminin kararsız olma nedeni bellek taşması değildir.** Hoca gerekçe olarak tamsayı taşmasını ve "NaN"ı anlattı. Matematiksel gerekçe: sınırlı bir giriş seçilir, örneğin $x[n] = 1$. Çıkış $y[n] = n$ olur ve $n\to\infty$ iken sınırsız büyür. Bu yüzden BIBO kararlı değildir.
- **Quiz soru 1:** Ayrık zamanda $\Omega_0 = 500$ rad/örnek için periyot sorusu kafa karıştırıcıdır.
  - $\Omega_0/2\pi = 500/2\pi$ irrasyonel olduğu için bu işaret aslında hiç periyodik değildir.
  - Hoca $T_0 = \pi/250$ hesabını sürekli zaman mantığıyla yaptı. $D$'nin yanlış olduğu sonucu değişmez.
  - "A: işaret ayrık zamanlı ve periyodiktir" ifadesi ancak $\Omega_0/2\pi$ rasyonel ise doğrudur.
- **Üçgen işaretin örneklenmesi:** Altyazıda $x[2] = 0.55$ geçiyor. Doğrusu $x(0.5) = 0.5$.
- **$u(t)-u(t-a)$'nın türevi:** Derste "ötelenmiş delta fonksiyonunun türevi" gibi ifadeler geçti. Doğrusu: $u(t-a)$'nın türevi $\delta(t-a)$'dır. Sonuç $\delta(t) - \delta(t-a)$; $t=a$'da aşağı yönlü bir darbe vardır.
- **Parseval teoremi işareti yeniden oluşturmak için kullanılmaz.** Derste "işaretin kendisini inşa etmek için kullanılan teorem" dendi. Parseval yalnız gücün zaman ve frekans düzleminde aynı olduğunu söyler. İşareti yeniden oluşturan, Fourier serisi sentez denklemidir.
- **Spektrum örneğinde genlik:** Derste bir yerde "17 çarpı kosinüs" dendi. Doğrusu $2\cdot7 = 14$'tür.
- **$[1,1,1,1]*[1,1,1]$:** Altyazıda sonuç "1, 2, 3, 3, 3, 3, 3, 2, 1" gibi geçiyor. Doğru sonuç $[1,2,3,3,2,1]$, yani 6 örnektir.
- Sayısal sonuçlar Python ile doğrulandı. Bunlar: $e^{-t}$ örneğinin $c_k$ formülü ($c_0 \approx 0.316$, $c_1 \approx 0.063 - 0.198j$), kare dalga katsayıları, $t*t^2 = t^4/12$, konvolüsyon dizileri, örnekleme sonuçları, $4/3$ enerjisi, EKOK 24 ve EBOB değerleri (50, 100, 10).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
