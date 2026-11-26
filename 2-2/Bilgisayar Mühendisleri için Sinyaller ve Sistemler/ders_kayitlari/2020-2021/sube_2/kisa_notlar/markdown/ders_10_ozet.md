# Ders 10 Çalışma Özeti

## Genel Konular

- Frekans düzlemi analizinin sınıflandırması
  - İşaret önce sürekli mi ayrık mı, sonra periyodik mi periyodik değil mi diye incelenir. Dört durum için dört ayrı araç kullanılır (ekrandan, 00:15:00):
    - Sürekli ve periyodik: Fourier serisi (CTFS).
    - Ayrık ve periyodik: ayrık Fourier serisi (DFS) ya da DFT.
    - Sürekli ve periyodik olmayan: Fourier dönüşümü (FT).
    - Ayrık ve periyodik olmayan: ayrık zamanlı Fourier dönüşümü (DTFT).
  - Bütün yöntemlerde akış aynıdır: zaman düzlemindeki işaret bir dönüşümle ($T$) frekans düzlemine geçirilir, orada işlem (filtreleme vb.) yapılır, ters dönüşümle ($T^{-1}$) zamana dönülür.
  - En basit uygulama: zamanda konvolüsyon frekansta çarpmadır, $x(t)*y(t)\;\leftrightarrow\;X(\omega)\,Y(\omega)$ (ekrandan, 00:15:00). Diferansiyel denklemler de frekans düzleminde cebirsel denkleme dönüşür.
- Sinüzoitlerin toplamı ve spektrum
  - Periyodik bir işaret genlik, frekans ve faz bileşenleri olan kosinüslerin toplamı olarak yazılır: $x(t)=A_0+\sum_{k=1}^{N}A_k\cos(2\pi f_k t+\varphi_k)$ (ekrandan, 00:20:00).
  - Euler bağıntılarıyla her kosinüs iki karmaşık üstele ayrılır: $A\cos(\omega t+\varphi)=\frac{A}{2}e^{j\varphi}e^{j\omega t}+\frac{A}{2}e^{-j\varphi}e^{-j\omega t}$. Spektrumda her frekans için $\pm f$ noktalarında birer çizgi çıkar; çizginin yüksekliği $\frac{A}{2}$, açısı fazdır.
  - Sinüs örneği: $A\sin(7t)=\frac12 Ae^{-j0.5\pi}e^{j7t}+\frac12 Ae^{j0.5\pi}e^{-j7t}$; spektrumda $\omega=7$'de $\frac12Ae^{-j0.5\pi}$, $\omega=-7$'de $\frac12Ae^{j0.5\pi}$ vardır (ekrandan, 00:30:00).
  - Negatif frekansın fiziksel yorumu olarak polis radarındaki Doppler kayması örneği verildi (yaklaşan ve uzaklaşan araç).
- Temel frekans
  - Bileşen frekanslarının en büyük ortak böleni (OBEB) temel frekanstır. En küçük frekans temel frekans değildir.
  - $100$ ve $250$ Hz için $f_0=50$ Hz; $10, 30, 50$ Hz için $f_0=10$ Hz; bir sesli harf spektrumundaki $200, 400, 500, 1600, 1700$ Hz için $f_0=100$ Hz (ekrandan, 00:35:00); $648$ ve $672$ Hz için $f_0=24$ Hz.
  - Temel frekansın kendisi ya da bazı katları spektrumda görünmeyebilir; bunun nedeni o bileşenlerin genliğinin sıfır olmasıdır.
- Zaman-frekans analizi
  - Fourier dönüşümüyle frekansa geçerken zaman bilgisi kaybolur. Spektrogram işareti kısa zaman pencerelerine böler, her pencerede Fourier analizi yapar; hangi frekansın hangi zaman aralığında baskın olduğu görülür (ekrandan, 00:45:00).
  - Müzik notaları, telefon sinyali, kuş sesi (chirp, doğrusal frekans modülasyonu) örnekleri gösterildi. Aynı notayı farklı çalgıların farklı duyurmasını sağlayan ek bileşenlere tını (timbre) denir.
- Sürekli zamanlı Fourier serisi
  - Üstel biçim (ekrandan, 00:55:00): $x(t)=\sum_{k=-\infty}^{\infty}c_k e^{jk\omega_0 t}$, $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0 t}\,dt$ ($k\neq0$), $c_0=\frac{1}{T_0}\int_{T_0}x(t)\,dt$.
  - Gerçel işaret için $c_{-k}=c_k^{*}$.
  - Trigonometrik biçim: $x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}\left(a_k\cos k\omega_0 t+b_k\sin k\omega_0 t\right)$; $a_k=\frac{2}{T_0}\int_{T_0}x(t)\cos k\omega_0 t\,dt$, $b_k=\frac{2}{T_0}\int_{T_0}x(t)\sin k\omega_0 t\,dt$.
  - İki biçim arasındaki ilişki: $c_k=\frac12(a_k-jb_k)$, $a_k=2\,\mathrm{Re}\{c_k\}$, $b_k=-2\,\mathrm{Im}\{c_k\}$, $a_0=2c_0$.
  - Katsayı bulmak, işareti bir periyot boyunca sinüs ve kosinüslerle çarpıp integral almaktır; büyük çıkan katsayılar işaretteki frekansları gösterir.
- Kare dalga örneği (ekrandan, 01:00:00 ve 01:10:00)
  - $f(t)=1$ ($0<t<1$), $f(t)=0$ ($1<t<2$), $T=2$, $f_0=0.5$ Hz, $\omega_0=\pi$.
  - $a_0=1$, $a_n=0$, $b_n=\frac{1-(-1)^n}{n\pi}$, yani tek $n$ için $\frac{2}{n\pi}$, çift $n$ için $0$.
  - $f(t)=\frac12+\frac{2}{\pi}\sin\pi t+\frac{2}{3\pi}\sin3\pi t+\frac{2}{5\pi}\sin5\pi t+\dots$ (ekrandan, 01:25:00).
  - Üstel biçimde $c_0=\frac12$, tek $n$ için $c_n=\frac{-j}{n\pi}$, çift $n$ için $0$. Buradan $a_n=2\,\mathrm{Re}\{c_n\}=0$, $b_n=-2\,\mathrm{Im}\{c_n\}=\frac{2}{n\pi}$ bulunur ve trigonometrik sonuçla aynıdır.
  - Terim eklendikçe toplam kare dalgaya yaklaşır; süreksizlik noktalarında Gibbs olayı denen taşmalar kalır.
- Ayrık zamanlı Fourier serisi
  - $x[n]=\sum_{k=0}^{N_0-1}c_k e^{jk\Omega_0 n}$, $c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]e^{-jk\Omega_0 n}$, $\Omega_0=\frac{2\pi}{N_0}$ (ekrandan, 01:45:00). İntegral yerine toplam vardır.
  - Örnek: bir periyotta 5 tane 1 ve 5 tane 0 olan dizi, $N_0=10$ (5 değil). $c_k=\frac{1}{10}\sum_{n=0}^{4}e^{-jk\pi n/5}=\frac{1}{10}e^{-j2\pi k/5}\frac{\sin(k\pi/2)}{\sin(k\pi/10)}$, $c_0=\frac12$.
  - Önerilen alıştırma: $x[n]=\sum_k\delta[n-4k]$ için $N_0=4$ ve bütün $c_k=\frac14$.
- Fourier dönüşümü
  - Periyodik olmayan işaret, periyodu sonsuz olan bir işaret gibi düşünülür: $X(j\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt$, $x(t)=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(j\omega)e^{j\omega t}d\omega$.
  - $x(t)=e^{-at}u(t)$ ($a>0$) için $X(j\omega)=\frac{1}{a+j\omega}$ (ekrandan, 02:00:00). Genliği $\frac{1}{\sqrt{a^2+\omega^2}}$, fazı $-\arctan(\omega/a)$.
  - Dikdörtgen darbenin dönüşümü $\sin$ içeren bir ifadedir. Ters yönde, $|\omega|<\omega_b$ için 1 olan ideal alçak geçiren filtrenin zaman karşılığı $x(t)=\frac{\sin\omega_b t}{\pi t}$'dir (ekrandan, 02:05:00).
  - $\delta(t)\leftrightarrow 1$; $e^{j\omega_0 t}$ ve $\cos\omega_0 t$ dönüşümleri kendi frekanslarında tepe verir. Hoca bunu bir görüntüde Fourier tabanlı eşleştirmede tepe noktasının aranan bölgeyi göstermesi örneğiyle anlattı.
- Fourier dönüşümü özellikleri
  - Doğrusallık, zamanda öteleme ($x(t-t_d)\leftrightarrow e^{-j\omega t_d}X(j\omega)$), ölçekleme (zamanda sıkışma frekansta genişleme), zamanda konvolüsyon ↔ frekansta çarpma, zamanda çarpma ↔ frekansta konvolüsyon, modülasyon (frekansta öteleme), türev ($\frac{dx}{dt}\leftrightarrow j\omega X(j\omega)$).
  - Konvolüsyon örneği: $\frac{\sin100\pi t}{\pi t}*\frac{\sin200\pi t}{\pi t}=\frac{\sin100\pi t}{\pi t}$; frekansta iki dikdörtgenin çarpımı dar olanı verir.
  - Laplace dönüşümü $j\omega$ yerine $s$, z dönüşümü $e^{j\omega}$ yerine $z$ yazılarak elde edilir.
- Ayrık zamanlı Fourier dönüşümü (DTFT)
  - $X(e^{j\omega})=\sum_{n}x[n]e^{-j\omega n}$; z dönüşümü $X(z)=\sum_n x[n]z^{-n}$ (ekrandan, 02:40:00).
  - $x[n]=u[n]-u[n-N]$ için $X(e^{j\omega})=\frac{1-e^{-j\omega N}}{1-e^{-j\omega}}=e^{-j\omega(N-1)/2}\frac{\sin(\omega N/2)}{\sin(\omega/2)}$.
- Frekans cevabı ile fark ve diferansiyel denklem çözümü
  - Ayrık örnek (ekrandan, 02:50:00 ve 02:55:00): $y[n]-\frac34y[n-1]+\frac18y[n-2]=x[n]$ için $H(e^{j\omega})=\frac{1}{1-\frac34e^{-j\omega}+\frac18e^{-j2\omega}}=\frac{2}{1-\frac12e^{-j\omega}}-\frac{1}{1-\frac14e^{-j\omega}}$, $h[n]=\left[2\left(\frac12\right)^n-\left(\frac14\right)^n\right]u[n]$.
  - Sürekli örnek (ekrandan, 03:00:00): $\frac{dy}{dt}+2y(t)=x(t)$ için $H(j\omega)=\frac{1}{2+j\omega}$. $x(t)=e^{-t}u(t)$ girişinde $Y(j\omega)=\frac{1}{(1+j\omega)(2+j\omega)}=\frac{1}{1+j\omega}-\frac{1}{2+j\omega}$, $y(t)=(e^{-t}-e^{-2t})u(t)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sinüzoitleri Euler bağıntılarıyla üstellere ayırıp spektrumunu yazmak
  - Hoca bunun sınavda büyük olasılıkla geleceğini, iki yerine üç bileşenli bir işaret verilebileceğini söyledi.
- Temel frekans OBEB'dir
  - Birçok kaynakta en küçük frekansın temel frekans diye verildiğini, bunun yanlış olduğunu vurguladı.
- Katsayıları bulmak için integral, bir periyot boyunca alınır
  - Başlangıç noktası serbesttir ($0$–$2$, $1$–$3$, $0.5$–$2.5$ aynı sonucu verir).
- Birim çember değerleri
  - $\sin n\pi=0$, $\cos n\pi=(-1)^n$, $e^{-jn\pi}=(-1)^n$, $\sin(-a)=-\sin a$, $\cos(-a)=\cos a$ gibi değerlerin bilinmesi gerekir.
- Konvolüsyon ↔ çarpma ve türev ↔ $j\omega$ ile çarpma özellikleri
  - En çok kullanılacak özellikler bunlardır; diferansiyel ya da fark denklemi bu özelliklerle cebirsel işleme dönüşür.
- Bilgisayar mühendisi açısından Fourier
  - Asıl kullanım alanı spektrogram, ses ve görüntüde zaman-frekans analizi ve özellik çıkarmadır; Python ve MATLAB'de FFT birkaç satırla uygulanır.

## Kısa Tekrar Notları

- Dört araç: CTFS (sürekli, periyodik), DFS/DFT (ayrık, periyodik), FT (sürekli, periyodik olmayan), DTFT (ayrık, periyodik olmayan).
- $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0t}dt$; $a_k=2\,\mathrm{Re}\{c_k\}$, $b_k=-2\,\mathrm{Im}\{c_k\}$, $a_0=2c_0$.
- Kare dalga ($0$–$1$ arası 1, $T=2$): $\frac12+\frac{2}{\pi}\sum_{n\ \text{tek}}\frac{\sin n\pi t}{n}$.
- Temel frekans = bileşen frekanslarının OBEB'i.
- Ayrık seri: $c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]e^{-jk(2\pi/N_0)n}$.
- $e^{-at}u(t)\leftrightarrow\frac{1}{a+j\omega}$; $\delta(t)\leftrightarrow1$; ideal alçak geçiren ↔ $\frac{\sin\omega_bt}{\pi t}$.
- $x*h\leftrightarrow XH$, $\frac{dx}{dt}\leftrightarrow j\omega X$, $x(t-t_d)\leftrightarrow e^{-j\omega t_d}X$.
- $H=\frac{Y}{X}$; basit kesirlere ayır, tablodan ters dönüşüm al.
- Spektrogram zaman ve frekansı birlikte gösterir; Gibbs olayı süreksizlikte kalan taşmadır.

## Detaylı Açıklamalar

- **Neden frekans düzlemi?** Diferansiyel denklemle tanımlanan bir sistemin cevabını zamanda bulmak zordur; konvolüsyon integrali de çoğu zaman uzun sürer. Fourier dönüşümü konvolüsyonu çarpmaya, türevi $j\omega$ ile çarpmaya çevirdiği için problem cebirsel bir probleme dönüşür. İşlem frekansta yapılır, sonuç ters dönüşümle zamana getirilir. Hoca ders boyunca bu akışı "dönüşüm, işlem, ters dönüşüm" diye özetledi.

- **Fourier serisi katsayılarının anlamı.** Bir periyodik işaretin hangi frekansları içerdiğini bulmak için işaret bir periyot boyunca $e^{-jk\omega_0t}$ (ya da $\cos$ ve $\sin$) ile çarpılıp integrali alınır. Bu, işaretin o frekanstaki sinüzoide ne kadar benzediğini ölçer. $c_0$ ayrıca hesaplanır, çünkü genel formülde $k=0$ için bölme sıfıra gider; $c_0$ işaretin bir periyottaki ortalamasıdır (DC bileşen). Trigonometrik biçimde üç integral ($a_0$, $a_k$, $b_k$) gerekir; üstel biçimde tek integral yeter, bu yüzden genelde üstel biçim tercih edilir.

- **Kare dalga örneğinin adımları.** $T=2$ olduğundan $\omega_0=\pi$'dir. İşaret $1<t<2$ aralığında sıfır olduğu için bütün integraller $0$–$1$ aralığına iner. $a_0=\frac{2}{2}\int_0^1dt=1$; bu bir periyottaki alanın $\frac{2}{T}$ katıdır. $a_n=\int_0^1\cos n\pi t\,dt=\frac{\sin n\pi}{n\pi}=0$. $b_n=\int_0^1\sin n\pi t\,dt=\frac{1-\cos n\pi}{n\pi}=\frac{1-(-1)^n}{n\pi}$. Sonuçta işaret yalnız sinüslü bileşenlerden ve bir DC terimden oluşur. Üstel biçimde $c_n=\frac12\int_0^1e^{-jn\pi t}dt=\frac{j\left(e^{-jn\pi}-1\right)}{2n\pi}$ bulunur; $e^{-jn\pi}=(-1)^n$ yazılınca tek $n$ için $c_n=\frac{-j}{n\pi}$ çıkar. Python ile sayısal integralle $b_1\approx0.6366=\frac{2}{\pi}$, $b_3\approx0.2122=\frac{2}{3\pi}$ doğrulandı.

- **Ayrık seri örneği.** $N_0=10$, $\Omega_0=\frac{\pi}{5}$. Toplam yalnız $n=0,\dots,4$ için sıfırdan farklıdır. Geometrik seri toplamı $\sum_{n=0}^{4}r^n=\frac{1-r^5}{1-r}$ ile ve $e^{-jk\pi/2}$, $e^{-jk\pi/10}$ ortak paranteze alınarak $c_k=\frac{1}{10}e^{-j2\pi k/5}\frac{\sin(k\pi/2)}{\sin(k\pi/10)}$ elde edilir. $k=0$ için limit $\frac12$'dir; çift $k$ ($k\ne0$) için $c_k=0$'dır. Değerler Python'da doğrudan toplamla karşılaştırıldı.

- **Frekans cevabıyla sistem çözümü.** Fark denkleminin iki yanının DTFT'si alınır; $y[n-1]\to e^{-j\omega}Y$, $y[n-2]\to e^{-j2\omega}Y$. $H=\frac{Y}{X}$ basit kesirlere ayrılır ve her terim $a^nu[n]\leftrightarrow\frac{1}{1-ae^{-j\omega}}$ çiftiyle zamana döndürülür. Sürekli örnekte $\frac{dy}{dt}\to j\omega Y$ kullanılır; giriş dönüşümüyle $H$ çarpılır, basit kesirlere ayrılır ve $e^{-at}u(t)\leftrightarrow\frac{1}{a+j\omega}$ ile sonuç bulunur. İki sonuç Python'da (özyinelemeyle $h[n]$ ve türevle $y(t)$) doğrulandı.

- **Fourier'in pratikteki yeri.** Hoca, kağıt üzerindeki bu analitik çözümlerin yanında bilgisayar mühendisliğinde asıl kullanımın spektrogram, ses ve görüntüde frekans bileşenlerinden özellik çıkarma olduğunu, kodda FFT ve ters FFT'nin hazır fonksiyonlarla birkaç satırda uygulandığını söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
