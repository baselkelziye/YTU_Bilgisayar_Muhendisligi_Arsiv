# Ders 5 Çalışma Özeti

## Genel Konular

- Sistem kavramı ve gösterimi
  - Sistem, giriş işaretini çıkış işaretine dönüştüren yapıdır; giriş işaretini çıkış işaretine eşleyen bir haritalama (function mapping) olarak da tanımlanır.
  - Derste tek girişli, tek çıkışlı (SISO) sistemler ele alınır.
  - Gösterim: $y = S(x)$ ya da kısaca $y = Sx$. Buradaki $Sx$ genel olarak çarpma anlamına gelmez; yalnız dönüşüm bir matrisle gösterilebiliyorsa çarpmaya dönüşür (ekrandan, 00:20:00).
    - Ayrık işaret bir dizi (array) olarak saklanır: $1 \times N$ ya da $N \times 1$ boyutlu vektör. $S$ dönüşümü $M \times N$ boyutlu bir matrisse $N \times 1$ girişten $M \times 1$ çıkış üretir.
  - Sürekli işaret $x(t)$ normal parantezle, ayrık işaret $x[n]$ köşeli parantezle yazılır; genel anlatımda yalnız $x$ ve $y$ yazılır.
  - Blok diyagramda kutular sistemleri, oklar işaretleri gösterir. Oklar kablo değil, işaretin akış yönüdür (ekrandan, 00:20:00).
- Temel sistem örnekleri (ekrandan, 00:25:00 ve 00:30:00)
  - Ölçekleyen sistem: $y(t) = a\,x(t)$. $|a| > 1$ ise yükselteç (amplifier), $|a| < 1$ ise zayıflatıcı (attenuator), $a < 0$ ise tersleyen (inverting) sistemdir. $a$ kazanç ya da ölçekleme faktörüdür. Blok diyagramda kutu, üçgen ya da daireyle gösterilebilir.
  - Türev alıcı (differentiator): $y(t) = \dfrac{dx(t)}{dt}$.
  - İntegral alıcı (integrator): $y(t) = \displaystyle\int_{a}^{t} x(\tau)\,d\tau$; $a$ genelde $0$ ya da $-\infty$ alınır.
  - Zamanda öteleme sistemi: $y(t) = x(t - T)$. $T > 0$ ise gecikme (delay), $T < 0$ ise öngörücü (predictor) sistemdir.
  - Konvolüsyon sistemi: sistem $h$ işaretiyle tanımlanır, çıkış $h$ ile $x$'in integraliyle üretilir; ayrıntısı sonraki derslere bırakıldı.
  - Çok girişli sistemler: toplayıcı $y = x_1 + x_2$, fark alıcı $y = x_1 - x_2$, çarpıcı $y = x_1 x_2$.
- Sistemlerin bağlanması (ekrandan, 00:35:00)
  - Seri (kaskat) bağlama: $y = G(F(x))$.
  - Paralel bağlama: $y = F(x) + G(x)$.
  - Geri besleme (feedback): $y = F(x - G(y))$.
  - Blok diyagram, sistem bağlantılarını sembolik olarak gösterir; diyagramdan denkleme ve denklemden diyagrama geçilebilir.
  - Örnek: geri beslemeli integral alıcı. İntegral alıcının girişi $x - a y$ olduğundan $y(t) = \int_{-\infty}^{t} \big(x(\tau) - a\,y(\tau)\big)\,d\tau$, yani $\dot y = x - a y$ olur.
- Doğrusallık (linearity) (ekrandan, 00:40:00)
  - Homojenlik (ölçeklenebilirlik): $F(ax) = aF(x)$.
  - Süperpozisyon (toplamsallık): $F(x + \tilde x) = F(x) + F(\tilde x)$.
  - Sözle: ölçeklemeyi ya da toplamayı sistemden önce ya da sonra yapmak aynı sonucu verir.
  - Modülatör $y(t) = x(t)\cos(2\pi f t)$ doğrusaldır; kare alıcı $y(t) = x^2(t)$ doğrusal değildir, çünkü $ax$ girişi $a^2x^2$ verir (ekrandan, 00:45:00).
- Hafıza (memory)
  - Hafızasız sistemde çıkış yalnız o anki girişe bağlıdır (örnek: yükselteç $y = ax$).
  - Hafızalı sistemde çıkış girişin geçmiş ya da gelecek değerlerine de bağlıdır (örnek: $y[n] = x[n] + x[n-1]$). Kondansatör ve bobin gibi enerji depolayan elemanlar, yaylar ve hareketli kütleler hafızalı sistemlerdir.
- Zamanla değişmezlik (time invariance) (ekrandan, 00:50:00)
  - Girişteki $\tau$ kadar öteleme çıkışı da $\tau$ kadar öteler: $F(x(t-\tau)) = y(t-\tau)$. Yani gecikme ile sistem yer değiştirebilir (commute).
  - Sistem analizini büyük ölçüde basitleştirir.
- Kararlılık (stability)
  - Sınırlı giriş, sınırlı çıkış (BIBO): $|x(t)| \le M_x$ olan her giriş için $|y(t)| \le M_y$ ise sistem kararlıdır; $M_x$ ve $M_y$ sonlu pozitif sayılardır.
  - Örnek: hız sabitleyici (cruise control). İstenen hız $x$, gerçek hız $y$, hata $e = x - y$, kazanç $k$, araba $H$: $y = H(k(x - y))$. $k$ çok büyükse sistem kararsız olabilir (ekrandan, 00:55:00).
- Terslenebilirlik (invertibility)
  - Çıkıştan giriş yeniden elde edilebiliyorsa sistem terslenebilirdir: $F^{-1}(F(x)) = x$; $F^{-1}$ ile $F$'nin seri bağlanması birim (identity) operatör gibi davranır.
- Doğrusal sabit katsayılı diferansiyel ve fark denklemleri
  - Birçok sürekli zamanlı sistem $a_n y^{(n)} + \dots + a_1 \dot y + a_0 y = b_m x^{(m)} + \dots + b_0 x$ biçimindedir; $n$ sistemin mertebesidir. Başlangıç koşulları sıfırsa bu sistemler doğrusaldır.
  - Basit örnekler (ekrandan, 01:00:00): ölçekleyen sistem ($a_0 = 1,\ b_0 = a$) $y = ax$; integral alıcı ($a_1 = 1,\ b_0 = 1$) $\dot y = x$; geri beslemeli integral alıcı ($a_1 = 1,\ a_0 = a$).
  - Elektrik (RLC devresi) ve mekanik (araba süspansiyonu: yay ve amortisör) sistemler de bu tür denklemlerle yazılır.
  - Ayrık zamanlı sistemlerin denklemleri fark denklemleridir (ekrandan, 01:05:00): $a_0 y[n] + a_1 y[n-1] + \dots = b_0 x[n] + b_1 x[n-1] + \dots$
  - Ayrık örnek (ekrandan, 01:25:00): gecikme bloğunun girişi $e[n] = x[n] - a\,y[n]$, çıkış $y[n] = e[n-1]$; sonuç $y[n] = x[n-1] - a\,y[n-1]$.
- Önceki konulara ait örnek sorular
  - Sürekli işarette öteleme, sıkıştırma/genişletme ve yansıma: $x(t-2)$, $x(2t)$, $x(t/2)$, $x(-t)$; aynı işlemler ayrık işarette $x[n-2]$, $x[2n]$, $x[-n]$, $x[-n+2]$.
  - Birim basamak ve dürtüyle işaret kesme: $x(t)u(1-t)$, $x(t)[u(t) - u(t-1)]$, $x(t/2)\delta(t-1.5)$.
  - Enerji ve güç hesapları: $e^{-2t}u(t)$, $A\cos\omega t$, $e^{-|t|}$.
  - Çift-tek ayrıştırma ve sinüzoidal işaretin parametreleri (genlik, frekans, periyot, faz, ilk maksimum zamanı), MATLAB ile çizim.

## Hocanın Özellikle Vurguladığı Kısımlar

- $y = Sx$ gösterimi çarpma değildir
  - $S$ girişi alıp işleyen bir dönüşümdür; yalnız matrisle gösterilebilen dönüşümlerde çarpma biçimine gelir.
- Mutlak değerin anlamı
  - $a = -2$ de işareti iki kat güçlendirir; eksi işaret yalnız işareti ters çevirir. Bu yüzden yükselteç/zayıflatıcı ayrımı $|a|$ ile yapılır.
- Zamanla değişmezlik özel bir özelliktir
  - Sistem analizini çok basitleştirdiği için sonraki konuların temelidir.
- Dürtüyle çarpımda genliği doğru argümandan okumak
  - $x(t/2)\delta(t-1.5)$ sorusunda dürtü $t = 1.5$'te durur, genliği $x(1.5/2) = x(0.75)$ belirler. Hoca çözüm slaytında bunun yerine $x(1.5)$ değerinin çizildiğini gösterdi ve doğru cevabın genliği 1 olan dürtü olduğunu söyledi.
- Temel kavramlar ve matematik altyapısı
  - Hoca basit sorularda küçük hatalarla çok puan kaybedildiğini söyledi; integral ve türev gibi temel matematik konularının tekrar edilmesini istedi.
- MATLAB ile sinüzoidal çizim
  - Sürekli bir işareti ekranda çizebilmek için zaman ekseni küçük adımlarla ($0.01$) örneklenir; bu alıştırmanın herkes tarafından yapılmasını istedi.

## Kısa Tekrar Notları

- Sistem: $y = S(x)$; SISO sistemler; blok diyagramda kutu = sistem, ok = işaret.
- Ölçekleme $y = ax$: $|a|>1$ yükselteç, $|a|<1$ zayıflatıcı, $a<0$ tersleyen.
- $y(t) = x(t-T)$: $T>0$ gecikme, $T<0$ öngörücü.
- Seri $G(F(x))$, paralel $F(x)+G(x)$, geri besleme $F(x - G(y))$.
- Doğrusal = homojen + toplamsal. Modülatör doğrusal, kare alıcı doğrusal değil.
- Hafızasız: çıkış yalnız o anki girişe bağlı.
- Zamanla değişmez: gecikme ile sistemin sırası değişebilir.
- BIBO kararlılık: sınırlı giriş, sınırlı çıkış.
- Terslenebilir: $F^{-1}F = I$.
- Sabit katsayılı doğrusal diferansiyel/fark denklemleri, sıfır başlangıç koşulunda doğrusal sistem tanımlar.
- $x(at)$: $a>1$ sıkıştırır, $a<1$ genişletir; $x(-t)$ dikey eksene göre yansıtır.
- $u(t) - u(t-1)$, $[0,1)$ aralığında 1 olan kapı fonksiyonudur; çarpıldığı işaretin yalnız bu aralığını bırakır.
- $x(t)\delta(t-t_0) = x(t_0)\delta(t-t_0)$.
- Enerji: $E = \int |x(t)|^2 dt$; $e^{-2t}u(t)$ için $E = 1/4$, $e^{-|t|}$ için $E = 1$, $P = 0$.
- $A\cos\omega t$: bir periyottaki enerji $A^2T_0/2$, ortalama güç $A^2/2$.
- Çift bileşen $\frac{x(t)+x(-t)}{2}$, tek bileşen $\frac{x(t)-x(-t)}{2}$.
- $A\cos(\omega_0 t + \phi)$ için ilk maksimum $t_m = -\phi/\omega_0$.

## Detaylı Açıklamalar

- **Sistem gösterimi ve blok diyagram.** Sistem, bir kara kutu gibi düşünülür: sürekli zamanda $x(t)$ girişinden $y(t)$, ayrık zamanda $x[n]$ girişinden $y[n]$ üretir. Slaytta sistem $T$ yerine $S$ harfiyle gösterilir ve $y = S(x)$ ya da $y = Sx$ yazılır. Matematiksel gösterimde küçük harf bir boyutlu işareti (vektörü), büyük harf ise sistemi ya da iki boyutlu işaretleri (görüntü) gösterir. Ayrık bir işaret, her örneğin genlik değeri bir dizi elemanına yazılarak $1\times N$ ya da $N\times 1$ boyutlu bir vektör olarak saklanabilir. Dönüşüm bir $M\times N$ matrisle ifade edilebiliyorsa $y = Sx$ gerçek bir matris-vektör çarpımı olur ve $M\times 1$ boyutlu bir çıkış verir; genel durumda ise bu yalnız bir gösterimdir.

- **Ölçekleyen sistemler.** $y(t) = a\,x(t)$ sistemi işaretin genliği üzerinde çalışır. Hocanın benzetmesiyle, elektro gitardan gelen zayıf ses işaretini güçlendiren yükselteç $a = 2$ gibi bir kazançla çalışır. $a = -2$ alındığında işaret ters döner ama genliği yine iki katına çıkar; bu yüzden tanım $|a|$ ile yapılır ve eksi işaret ayrıca "tersleme" diye adlandırılır.

- **Türev ve integral alıcılar.** Türev alıcı işaretin eğimini verir: sıfırken sabit kalan, sonra sabit eğimle artan bir işaretin türevi, önce sıfır sonra sabit bir değerdir (eğim $B/A$ gibi). İntegral alıcı ise $t$ anına kadar işaretin altında kalan alanı hesaplar. Hocanın örneğinde $A$ ile $B$ arasında sabit olan bir işaretin integrali, $A$'dan itibaren doğrusal olarak artar ve $B$'den sonra sabit kalır.

- **Geri besleme.** Geri beslemeli sistemde çıkış bir $G$ sisteminden geçirilip girişten çıkarılır, fark $F$ sistemine verilir: $y = F(x - G(y))$. Sistem, istenen çıkışa ulaşabilmek için çıkıştan bilgi çeker. Geri beslemeli integral alıcıda $G$ yerine $a$ kazancı, $F$ yerine integral alıcı konur; integral alıcının girişi çıkışının türevi olduğu için $\dot y = x - a y$ elde edilir.

- **Hız sabitleyici örneği.** Sürücü istenen hızı (ör. 90) girer. Araba 88 ile gidiyorsa hata $e = x - y$ pozitiftir ve gaz artırılır; 92 ile gidiyorsa hata negatiftir ve gaz kesilir. Hız değişimi gecikmeli olduğundan hız hedefi aşar ya da altında kalır; süreç sürekli tekrar eder. Çıkış $y = H(k(x-y))$ ile yazılır ve $k$ kazancı $H$'ye göre çok büyükse sistem kararsızlaşabilir.

- **Doğrusallık örnekleri.** Modülatör $y(t) = x(t)\cos(2\pi f t)$, $x(t)$'yi taşıyıcı frekansın çevresine taşır; farklı frekanslarda yayın yapan radyo istasyonlarının ayrılabilmesi bu sayede olur. Girişi bir sabitle çarpmak çıkışı da aynı sabitle çarpar, toplam giriş toplam çıkış verir; bu yüzden doğrusaldır. Kare alıcıda ise $ax$ girişi $a^2x^2$ verir ve bu $a\,x^2$'ye eşit değildir. Hocanın okuduğu listeye göre ölçekleyiciler, zamanda ölçekleme, konvolüsyon, modülatörler ve örnekleyiciler doğrusal; işaret detektörleri, (kare alan) çarpıcılar, nicemleyiciler (quantizer), uyarlamalı süzgeçler ve karşılaştırıcılar doğrusal olmayan sistemlerdir. <!-- BELİRSİZ: liste slayttan okunuyordu ama karesi yok; "işaret detektörü" büyük olasılıkla "sign detector" çevirisidir. -->

- **Fiziksel sistemlerde diferansiyel denklemler.** Seri RLC devresinde Kirchhoff gerilim yasası $x - L\frac{di}{dt} - Ri - y = 0$ verir; kondansatör akımı $i = C\frac{dy}{dt}$ yerine konunca sabit katsayılı ikinci mertebeden bir denklem elde edilir: $LC\ddot y + RC\dot y + y = x$ (ara adım eklendi). Araba süspansiyonunda $x$ yolun dikey konumu, $y$ arabanın dikey konumudur; yay kuvveti $k(x-y)$, amortisör kuvveti $b(\dot x - \dot y)$ olur ve Newton yasasıyla $m\ddot y = k(x-y) + b(\dot x-\dot y)$ yazılır (ara adım eklendi). <!-- BELİRSİZ: devre ve süspansiyon slaytlarının karesi yok; denklemler hocanın sözlü anlatımından kuruldu. -->

- **Ayrık zamanlı sistem örneği.** Çıkış $a$ ile çarpılıp girişten çıkarılıyor ve sonuç bir birimlik gecikme bloğuna giriyor. Gecikmenin girişi $e[n] = x[n] - a\,y[n]$, çıkışı $y[n] = e[n-1]$ olduğundan $n$ yerine $n-1$ yazılarak $y[n] = x[n-1] - a\,y[n-1]$ bulunur. Hoca fark denklemlerinin çözümünün sinyal işleme (DSP) konusu olduğunu söyledi.

- **Sinüzoidal işaretin parametreleri.** $x(t) = 3\cos\left(\frac{\pi}{5}t - \frac{\pi}{4}\right)$ için $A = 3$, $\omega_0 = \pi/5$, $f = \omega_0/2\pi = 1/10$ Hz, $T = 10$ s, $\phi = -\pi/4$, $t_m = -\phi/\omega_0 = 1.25$ s ve $x(0) = 3\sqrt2/2 \approx 2.12$ olur (ekrandan, 02:10:00). İlk maksimum, kosinüsün argümanını sıfır yapan $t$ değeridir.

  ```matlab
  t = -10:0.01:20;
  x = 3*cos(pi/5*t - pi/4);
  plot(t, x)
  ```

  (Kod hocanın sözlü anlatımından ve ekrandaki `t=-10:0.01:20` yazısından alındı, 02:15:00; MATLAB'de çalıştırılmadı, numpy karşılığıyla aynı sonuç ve $t_m = 1.25$ doğrulandı.)

- **Ders sonrası not (periyodiklik).** Hoca $\omega/2\pi$ oranının rasyonel olması gerektiğini söyledi ve $\cos(2t + \pi/4)$ için periyodik olmayacağını belirtti. Bu koşul büyük olasılıkla ayrık zamanlı sinüzoidaller ($\cos(\Omega n)$, $\Omega/2\pi$ rasyonel olmalı) içindir; sürekli zamanda $\cos(\omega t + \phi)$ her $\omega \ne 0$ için $T = 2\pi/\omega$ periyoduyla periyodiktir ($\cos(2t+\pi/4)$ için $T = \pi$). Frekans değerleri de rasyonel sayılarla sınırlı değildir, gerçel sayıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
