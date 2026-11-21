# Ders 5 Çalışma Özeti

## Genel Konular

- DTFT tekrarı ve gösterim kuralları
  - DTFT, ayrık örneklerden işaretin frekans içeriğini verir: $X(e^{j\Omega})=\sum_{n=-\infty}^{\infty} x[n]\,e^{-jn\Omega}$ (ekrandan, 00:30:00).
  - Sağ taraf ayrık zaman uzayıdır (küçük harf, köşeli parantez: $x[n]$). Sol taraf sürekli frekans uzayıdır (büyük harf, normal parantez: $X(e^{j\Omega})$).
- Fark denklemiyle verilen bir sistemin frekans cevabı
  - Örnek sistem: $y[n]=1.34\,y[n-1]-0.9\,y[n-2]+x[n]-1.41\,x[n-1]+x[n-2]$ (ekrandan, 00:35:00).
  - Sistem önceki çıkışları kullandığı için bir hafızaya ihtiyaç duyar.
  - $h[n]$ bilinmediği için konvolüsyon doğrudan yapılamaz. Bunun yerine DTFT'nin öteleme özelliği kullanılır: $x[n-n_0]\leftrightarrow X(e^{j\Omega})\,e^{-jn_0\Omega}$.
  - Zamandaki konvolüsyon frekansta çarpmaya dönüşür: $y[n]=h[n]*x[n] \leftrightarrow Y(e^{j\Omega})=H(e^{j\Omega})\,X(e^{j\Omega})$, yani $H(e^{j\Omega})=Y(e^{j\Omega})/X(e^{j\Omega})$ (ekrandan, 00:40:00).
  - Sonuç: $H(e^{j\Omega})=\dfrac{1-1.41e^{-j\Omega}+e^{-j2\Omega}}{1-1.34e^{-j\Omega}+0.9e^{-j2\Omega}}$.
  - Zaman karşılığı ters DTFT ile bulunur: $h[n]=\frac{1}{2\pi}\int_{-\pi}^{\pi}H(e^{j\Omega})e^{jn\Omega}\,d\Omega$.
- Örneklemenin frekans uzayındaki etkisi (özet şekil)
  - Sürekli $x(t)$ işaretinin spektrumu $X(f)$, $0$ ile $f_{max}$ arasındadır (ekrandan, 00:45:00).
  - Örneklenen $x[n]$'in spektrumu $X(e^{j\Omega})$ simetrik ve periyodik olur. Kopyaların merkezleri $f_s$'in katlarındadır.
  - Kopyaların birbirine girmemesi için $f_s \ge 2f_{max}$ gerekir (Nyquist koşulunun frekans uzayındaki karşılığı) (ekrandan, 00:50:00).
- Sayısal frekans ve $[-\pi,\pi]$ aralığı
  - $\cos(2\pi f t)$ işaretinde $t=nT_s$ konunca $\cos(2\pi f n/f_s)$ elde edilir. $\Omega=2\pi f/f_s$ sayısal frekanstır.
  - $f_s=2f_{max}$ iken en yüksek frekanslı bileşen $\cos(\pi n)$ olur, yani $f_s/2$ daima $\Omega=\pi$'ye denk gelir.
  - $X(e^{j\Omega})$ $2\pi$ periyotludur. $[-\pi,\pi]$ ya da $[0,2\pi]$ aralığı bir periyodu tam gösterir.
- Ayrık Fourier dönüşümü (DFT)
  - DTFT ayrıktan sürekliye, DFT ayrıktan ayrığa dönüşümdür. DFT sonlu uzunluklu diziler için tanımlıdır ve sayısal hesaplama ile sayısal donanım uygulamalarında çok kullanışlıdır (ekrandan, 01:00:00).
  - Tanım: $X[k]=\sum_{n=0}^{N-1}x[n]\,e^{-j\frac{2\pi}{N}kn}$, $k=0,\dots,N-1$ (ekrandan, 01:10:00).
  - DFT katsayıları DTFT'nin örnekleridir: $X[k]=X(e^{j\Omega})\big|_{\Omega=2\pi k/N}$.
  - $N$ örnek alınırsa $2\pi$'lik frekans aralığı da $N$ parçaya bölünür; ardışık örnekler arasındaki açı $2\pi/N$'dir.
- Örtüşme (aliasing) örneği (S1)
  - $x_a(t)=\cos(2\pi5600t)+\cos(2\pi8400t)+\cos(2\pi11200t)+\cos(2\pi16800t)+\cos(2\pi25200t)$, $F_s=33600$ Hz (ekrandan, 01:30:00).
  - $x[n]=\cos(\frac{\pi}{3}n)+\cos(\frac{\pi}{2}n)+\cos(\frac{2\pi}{3}n)+\cos(\pi n)+\cos(\frac{3\pi}{2}n)$ (ekrandan, 01:35:00).
  - $33600<2\times25200$ olduğundan 25200 Hz bileşeni için örtüşme olur. $3\pi/2$'deki bileşen $2\pi$ merkezli kopyada $\pi/2$'ye düşer ve 8400 Hz ile üst üste biner ($33600-25200=8400$).
  - Örtüşme olmaması için minimum örnekleme frekansı $f_s=2\times25200=50400$ Hz'dir (ekrandan, 01:45:00).
  - $f_s=50400$ Hz ile: $x[n]=\cos(\frac{2\pi}{9}n)+\cos(\frac{\pi}{3}n)+\cos(\frac{4\pi}{9}n)+\cos(\frac{2\pi}{3}n)+\cos(\pi n)$; tüm bileşenler $[-\pi,\pi]$ içinde kalır (ekrandan, 01:50:00).
- DFT indisi ile analog frekans eşlemesi (S2)
  - 15 kHz ile bant sınırlı işaret $f_s=30$ kHz ile örnekleniyor, DFT $N=2000$ nokta (ekrandan, 01:55:00).
  - $k=0\dots999$ pozitif frekanslar, $k=1000$ civarı $\pi$ ($f_s/2=15$ kHz), $k=1000\dots1999$ negatif frekanslardır.
  - $k=200 \Rightarrow 200\cdot\frac{15\text{ kHz}}{1000}=3$ kHz. $k=1200 \Rightarrow -15+3=-12$ kHz (ekrandan, 02:00:00 ve 02:05:00).
- MATLAB'de FFT
  - `fft`, DFT'yi hızlı hesaplayan algoritmadır. 256 örneklik bir EKG parçasının `X=fft(x)` sonucu `1x256 complex double` olur (ekrandan, 02:10:00).
  - Karmaşık değer doğrudan çizilemez; `plot(abs(X))` ile genlik çizilir. `fftshift` sıfır frekansı ortaya alır, yani gösterimi $[-\pi,\pi]$ aralığına taşır (ekrandan, 02:15:00 ve 02:30:00).
- DTMF (tuşlu telefon) örneği
  - Her tuş iki sinüsün toplamıdır. Düşük grup: 697, 770, 852, 941 Hz; yüksek grup: 1209, 1336, 1477, 1633 Hz (ekrandan, 02:25:00).
  - En yüksek bileşen 1633 Hz olduğundan $f_s\ge 3266$ Hz gerekir; örneklerde güvenlik payıyla $f_s=4$ kHz ve 256 örnek kullanılmıştır.
  - `g.data` dosyasında genlik spektrumunda tepeler 46. ve 87. örnekte görülmüş, orantıyla yaklaşık 718 Hz ve 1359 Hz bulunmuş, en yakın frekanslar 697 Hz ve 1336 Hz olarak eşlenmiştir (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Konvolüsyon yerine frekans uzayında çarpma
  - Sistem karmaşıklaştıkça zamandaki konvolüsyonun hesap yükü artar. Frekans uzayına geçince işlem basit bir çarpma olur; fark denklemi verilen sistemde $H(e^{j\Omega})$, $Y$ ve $X$ terimleri ayrı taraflarda toplanarak bulunur.
- Örnekleme frekansının önemi
  - $f_s<2f_{max}$ olursa kopyalar birbirinin içine girer; yüksek frekanslar toplanarak özgün içeriği bozar ve özgün işaret geri elde edilemez. Bu olaya örtüşme (aliasing) denir.
- $f_s/2$ daima $\pi$'dedir
  - Sayısal frekansta en yüksek temsil edilebilen frekans $\pi$'dir. $\pi$'yi aşan bileşen başka bir frekansın yerine düşer.
- DTFT ile DFT farkı
  - DTFT matematiksel bir ara formdur; frekans sürekli olduğu için bilgisayarda doğrudan işlenemez. DFT her iki uzayı da ayrık yaptığı için bilgisayarda çalışılabilir.
- $[0,2\pi]$ aralığında negatif frekanslar
  - DFT indisleri $0\dots N-1$ olduğu için $N/2$'den büyük indisler negatif frekansları gösterir. İndisi frekansa çevirirken bu ayrım unutulmamalıdır.
- FFT çıktısı karmaşıktır
  - Çizimde genlik (`abs`) kullanılır. Faz (açı) çizilecekse ona ayrıca dikkat edilmelidir.

## Kısa Tekrar Notları

- DTFT: $X(e^{j\Omega})=\sum_n x[n]e^{-jn\Omega}$; $2\pi$ periyotlu, sürekli frekans.
- Öteleme: $x[n-n_0]\leftrightarrow e^{-jn_0\Omega}X(e^{j\Omega})$.
- $H(e^{j\Omega})=Y(e^{j\Omega})/X(e^{j\Omega})$.
- $y[n]=1.34y[n-1]-0.9y[n-2]+x[n]-1.41x[n-1]+x[n-2]$ için $H(e^{j\Omega})=\frac{1-1.41e^{-j\Omega}+e^{-j2\Omega}}{1-1.34e^{-j\Omega}+0.9e^{-j2\Omega}}$.
- Sayısal frekans $\Omega=2\pi f/f_s$; $f_s/2 \leftrightarrow \pi$, $f_s\leftrightarrow 2\pi$.
- Nyquist: $f_s\ge 2f_{max}$; sağlanmazsa örtüşme.
- S1: $F_s=33600$ Hz'de 25200 Hz, 8400 Hz ile örtüşür; minimum $f_s=50400$ Hz.
- DFT: $X[k]=\sum_{n=0}^{N-1}x[n]e^{-j2\pi kn/N}$, $X[k]=X(e^{j\Omega})|_{\Omega=2\pi k/N}$.
- İndis-frekans: $f_k=k\,f_s/N$ ($k<N/2$), $k>N/2$ için $f_k=(k-N)\,f_s/N$.
- S2: $f_s=30$ kHz, $N=2000$: $k=200\to3$ kHz, $k=1200\to-12$ kHz.
- MATLAB: `X=fft(x)`, `plot(abs(X))`, `Xshifted=fftshift(X)`.
- DTMF: tuş = düşük grup + yüksek grup sinüs; $f_s=4$ kHz, $N=256$.

## Detaylı Açıklamalar

- Fark denklemiyle tanımlanan sistemlerde $h[n]$ çoğu zaman bilinmez; sistem yalnız giriş ve çıkış örnekleri cinsinden verilir. Böyle bir sistemin frekans cevabını bulmak için denklemin iki tarafının DTFT'si alınır. Doğrusallık sayesinde katsayılar aynen kalır; her gecikmiş örnek, öteleme özelliği nedeniyle bir karmaşık üstelle çarpılır. Derste örnek sistem için $Y(e^{j\Omega})=1.34\,Y(e^{j\Omega})e^{-j\Omega}-0.9\,Y(e^{j\Omega})e^{-j2\Omega}+X(e^{j\Omega})-1.41\,X(e^{j\Omega})e^{-j\Omega}+X(e^{j\Omega})e^{-j2\Omega}$ yazıldı (ekrandan, 00:40:00). $Y$'li terimler bir tarafa, $X$'li terimler diğer tarafa toplanıp ortak parantezlere alınınca oran doğrudan $H(e^{j\Omega})$'yı verir. Gerekirse ters DTFT ile $h[n]$ elde edilir.
- Örneklemenin frekans uzayındaki etkisi derste tek bir özet şekille toparlandı. Sürekli işaretin $0$ ile $f_{max}$ arasındaki spektrumu, örneklemeyle simetrik hale gelir ve $f_s$ aralıklarla kendini tekrar eder. $f_s=2f_{max}$ olduğunda kopyalar uç uca değer; $f_s$ büyüdükçe kopyalar birbirinden uzaklaşır. $f_s<2f_{max}$ olduğunda $f_s/2$ çevresinde kopyalar birbirinin içine girer; toplanan yüksek frekanslar özgün içeriği ezer ve özgün spektrum ayrılamaz.
- DFT'ye geçiş şöyle kurulur: $X(e^{j\Omega})$ sürekli olduğu için bilgisayar hafızasına konamaz. $2\pi$'lik bir periyot $N$ eşit parçaya bölünür ve $\Omega$ yerine $2\pi k/N$ konur. Böylece $N$ örneklik sonlu bir diziden $N$ tane frekans örneği elde edilir. Örneğin 128 örneklik bir işaretin frekans ekseni de tanım gereği 128 parçaya bölünür. MATLAB'deki `fft` aynı DFT'yi daha hızlı hesaplayan algoritmadır.
- S1 örneğinde her bileşenin sayısal frekansı $2\pi f/F_s$ ile bulundu: 5600, 8400, 11200, 16800 ve 25200 Hz sırasıyla $\pi/3$, $\pi/2$, $2\pi/3$, $\pi$ ve $3\pi/2$'ye düşer. $3\pi/2$, $\pi$'yi $\pi/2$ kadar aştığı için $2\pi$ merkezli kopyada $2\pi-3\pi/2=\pi/2$'ye gelir ve 8400 Hz bileşeniyle çakışır. $f_s=50400$ Hz seçilince sayısal frekanslar $2\pi/9$, $\pi/3$, $4\pi/9$, $2\pi/3$ ve $\pi$ olur; en yüksek bileşen tam sınırdadır ve farklı frekanslar birbirini ezmez.
- S2 örneğinde işaret tam sınırda ($f_s=2f_{max}$) örneklendiği için örtüşme yoktur. $2000$ noktalı DFT'de $2\pi$ aralığı 2000 parçaya bölünür; $[0,\pi]$ aralığına 1000 örnek düşer ve 1000. örnek 15 kHz'e denk gelir. $k=200$, orantıyla 3 kHz'dir. $k=1200$ ise $\pi$'yi geçtiği için negatif frekans bölgesindedir: $k=800$'ün (12 kHz) simetrik karşılığı olarak $-12$ kHz'e denk gelir.
- MATLAB uygulamasında 256 örneklik bir EKG parçasının FFT'si alındı. Sonuç karmaşık olduğu için `plot(X)` anlamsız bir şekil verdi; `plot(abs(X))` ile genlik spektrumu çizildi. Enerji alçak frekanslarda toplandı ve spektrum simetrik çıktı. `fftshift` ile sıfır frekansı 128. örneğe, yani ortaya taşındı; sağa doğru pozitif, sola doğru negatif frekanslar yer aldı. Örnekleme frekansı bilinmeden indislerin hangi analog frekansa denk geldiği söylenemez.
- DTMF örneğinde iki sinüsün toplamı olan 256 örneklik bir tuş sesi (`g.data`) yüklendi, `sound` ile dinletildi ve FFT'si alındı. $[0,2\pi]$ aralığında dört tepe görüldü (iki kosinüs ve negatif karşılıkları). 128. örnek $f_s/2=2$ kHz kabul edilip orantı kuruldu: $46\cdot2000/128\approx718$ Hz ve $87\cdot2000/128\approx1359$ Hz. En yakın DTMF frekansları 697 Hz ve 1336 Hz olduğu için bu iki frekansın tuşuna basıldığı sonucuna varıldı (ekrandan, 02:35:00).
  - Ders sonrası not: MATLAB indisleri 1'den başlar; $i$. dizi elemanı $k=i-1$ frekans indisine karşılık gelir. Doğru eşleme $f=(i-1)\,f_s/N$ olur: $45\cdot4000/256\approx703$ Hz ve $86\cdot4000/256\approx1344$ Hz. Python ile 697 Hz + 1336 Hz, $f_s=4$ kHz, $N=256$ işaretinin genlik tepeleri gerçekten 46. ve 87. elemanda çıktı. Sonuç (697 Hz ve 1336 Hz) değişmez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
