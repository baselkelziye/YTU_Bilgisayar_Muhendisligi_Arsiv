# Ders 13 Çalışma Özeti

## Genel Konular

- Vize sorularının çözümü (ekrandan, 00:10:00-00:25:00)
  - S1: Grafiği verilen sinüzoidal işaret $x(t)=A\cos(\omega t+\theta)$ biçiminde yazılır. Genlik grafikten $A=20$, periyot $T=0.04$ s, frekans $f=1/T=25$ Hz bulunur. Faz, $t=0$ anındaki değerden çıkar: $x(0)=0 \Rightarrow \cos\theta=0 \Rightarrow \theta=\pi/2$. Sonuç: $x(t)=20\cos(50\pi t+\pi/2)$.
  - S2: Zaman ölçekleme, ters çevirme ve öteleme ile $x(-t/2)$, $x(2(t+2))$ ve $x(-t+1)$ çizimleri.
  - S3: Ayrık konvolüsyon. $x[n]=[2\ 3\ 2\ 1]$ ($n=-1..2$), $h[n]=[2\ {-1}\ 1\ {-2}]$ ($n=-2..1$). Sonuç $y[n]=[4\ 4\ 3\ {-1}\ {-5}\ {-3}\ {-2}]$, $n=-3..3$.
  - S4: Periyodu $T=2$ olan, $0<t<1$ aralığında $e^{-t}$, $1<t<2$ aralığında $0$ olan işaretin Fourier serisi katsayıları: $c_k=\dfrac{1-e^{-1}(-1)^k}{2(1+jk\pi)}$.
- Dönemin konularının kısa özeti (ekrandan, 00:30:00)
  - Ders iki kola ayrılır: sürekli zaman (CT) ve ayrık zaman (DT). Her iki kolda sinyal, sistem, konvolüsyon ve frekans analizi vardır.
  - Frekans analizinde CT için CTFS ve CTFT, DT için DTFS (bazı kaynaklarda DFT ya da DFS) ve DTFT incelendi.
  - Frekans düzlemi konvolüsyonu kolaylaştırır ve diferansiyel/fark denklemlerini çözmeyi sağlar.
- İntegral dönüşümler
  - Genel kalıp: $F(\alpha)=\int f(t)\,K(\alpha,t)\,dt$. Çekirdek $e^{-j\omega t}$ olursa Fourier dönüşümü elde edilir; Laplace, Hartley, dalgacık (wavelet) gibi dönüşümler aynı mantıktadır.
  - Fourier dönüşüm çifti: $X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt$, $x(t)=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(\omega)e^{j\omega t}d\omega$.
  - $X(\omega)$ hem genlik hem faz bilgisini verir.
- Fourier dönüşümünün uygulamaları
  - DTMF telefon tuşları: her tuş iki frekansın toplamıdır (ör. 1 tuşu 697 Hz + 1209 Hz). Kayıt tuşlara bölünüp her parçanın FFT'si alınırsa basılan tuşlar bulunur. Tamamının FFT'si alınırsa frekanslar görülür ama hangi zamana ait oldukları kaybolur; spektrogram bu sorunu otomatik çözer.
  - Müzik: C6 notasının temel frekansı (pitch) yaklaşık 1047 Hz'dir. Obua ve klarnet aynı notayı çalınca baskın tepe yine 1047 Hz'dedir, ama çalgıya özgü ek bileşenler (tını) çalgıyı ayırt ettirir (ekrandan, 00:55:00).
  - İnsan kulağı yaklaşık 20 Hz - 20 kHz aralığını duyar.
- Laplace dönüşümü
  - Fourier dönüşümünün varlık şartı $\int_{-\infty}^{\infty}|x(t)|dt<\infty$'dur. $t\to-\infty$'da $e^{+j\omega\infty}$ gibi terimler sonsuza gittiği için bazı işaretlerin Fourier dönüşümü alınamaz.
  - Laplace dönüşümü $s=\sigma+j\omega$ kullanır: $X(s)=\int_{-\infty}^{\infty}x(t)e^{-st}dt$. $e^{-\sigma t}$ çarpanı işareti bastırarak integrali sonlu yapar. $\sigma=0$ alınırsa Fourier dönüşümü elde edilir (ekrandan, 01:05:00).
  - Temel dönüşümler: $\mathcal{L}\{a\}=a/s$, $\mathcal{L}\{t^n\}=n!/s^{n+1}$, $\mathcal{L}\{e^{at}\}=1/(s-a)$, $\mathcal{L}\{\sin at\}=a/(s^2+a^2)$, $\mathcal{L}\{\cos at\}=s/(s^2+a^2)$ (ekrandan, 01:35:00).
  - Özellikler: doğrusallık, $\mathcal{L}\{e^{at}f(t)\}=F(s-a)$, $\mathcal{L}\{t^nf(t)\}=(-1)^n\frac{d^n}{ds^n}F(s)$, zamanda öteleme $x(t-t_0)\leftrightarrow e^{-st_0}X(s)$.
- Yakınsama bölgesi (ROC), kutup ve sıfırlar
  - $e^{-at}u(t)\leftrightarrow\frac{1}{s+a}$, ROC: $\mathrm{Re}\{s\}>-a$ (sağ yanlı).
  - $-e^{-at}u(-t)\leftrightarrow\frac{1}{s+a}$, ROC: $\mathrm{Re}\{s\}<-a$ (sol yanlı). İfade aynı, ROC farklıdır.
  - Paydayı sıfır yapan $s$ değerleri kutup (×), payı sıfır yapanlar sıfırdır (o). ROC kutup içermez, sıfır içerebilir.
  - ROC $j\omega$ eksenini içeriyorsa Fourier dönüşümü vardır.
  - Sağ yanlı işarette ROC en büyük kutbun sağında, sol yanlı işarette en küçük kutbun solundadır. İki yanlı işarette ROC iki kutup arasında bir şerittir.
- Ters Laplace dönüşümü
  - Tablo ve özelliklerle "kalıba uydurma" yapılır. Uymayan ifadeler basit kesirlere ayrılır; çarpanlarına ayrılmayan ikinci dereceden payda tam kareye tamamlanır.
- Konvolüsyon, türev, ilk ve son değer teoremleri, tek taraflı Laplace
  - $x_1(t)*x_2(t)\leftrightarrow X_1(s)X_2(s)$, $\frac{dx}{dt}\leftrightarrow sX(s)$ (çift taraflı).
  - İlk değer: $x(0^+)=\lim_{s\to\infty}sX(s)$. Son değer: $\lim_{t\to\infty}x(t)=\lim_{s\to0}sX(s)$.
  - Tek taraflı Laplace ($0^-$'dan $\infty$'a) başlangıç koşullarını içerir: $\frac{dx}{dt}\leftrightarrow sX(s)-x(0^-)$, $\frac{d^2x}{dt^2}\leftrightarrow s^2X(s)-sx(0^-)-x'(0^-)$.
  - Diferansiyel denklem örneği: $y''+3y'+2y=u(t)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Faz yalnız ezberden yazılmamalı
  - $\theta=\pi/2$ sonucunun $x(0)=0$ koşulundan nasıl çıktığı gösterilmelidir; faz, işaretin $t=0$ anındaki konumudur. Esas ölçü olarak $\pi/2$ (90°) yazılır.
- Fourier katsayısında son ifade yalnız $k$, $j$ ve $\pi$ içerir
  - İntegralden sonra sonuçta $t$ kalmamalıdır; sınırlar yerine yazılmalıdır. $k$ ile başlanan hesapta sonuçta başka bir değişken ($n$ gibi) olmamalıdır.
  - $e^{jk\pi}=\cos k\pi+j\sin k\pi=(-1)^k$ sadeleştirmesi yapılmalıdır.
- Laplace dönüşümüne neden ihtiyaç var?
  - Fourier dönüşümü varken Laplace'ın ortaya çıkış nedeni, $-\infty$ sınırında ıraksayan işaretlerdir. Hoca bu noktayı "önemli" diye işaretledi.
- İfade aynı, ROC farklı
  - $e^{-at}u(t)$ ile $-e^{-at}u(-t)$ aynı $X(s)$'i verir; ikisini ayıran ROC'tur. Ters dönüşümde doğru işareti seçmek için ROC gerekir.
- Kutsal kural: $e^{at}$ ile çarpım $s$'yi $s-a$'ya öteler
  - Ters dönüşümlerin çoğu bu kuralla çözülür.
- Uzun integral yerine kural
  - $t^n f(t)$ gibi çarpımların integrali (kısmi integrasyon, değişken dönüşümü) uzun sürer; bunun yerine $F(s)$'nin $n$. türevi alınır. Pratikte $n$ genelde 1 ya da 2 olur.

## Kısa Tekrar Notları

- $x(t)=A\cos(2\pi ft+\theta)$: $A$ genlik, $f=1/T$, $\theta$ fazı $x(0)$'dan bulunur.
- Ayrık konvolüsyonda önce sıfır noktaları belirlenir; sonucun başlangıç indisi iki başlangıç indisinin toplamıdır.
- $c_k=\frac{1}{T}\int_{T}x(t)e^{-jk\omega_0t}dt$, $\omega_0=2\pi/T$.
- $X(s)=\int x(t)e^{-st}dt$, $s=\sigma+j\omega$; $\sigma=0$ ise Fourier.
- Tablo: $a/s$, $n!/s^{n+1}$, $1/(s-a)$, $a/(s^2+a^2)$, $s/(s^2+a^2)$; $\delta(t)\leftrightarrow1$, $u(t)\leftrightarrow1/s$.
- $e^{at}f(t)\leftrightarrow F(s-a)$; $t^nf(t)\leftrightarrow(-1)^nF^{(n)}(s)$.
- ROC kutup içermez; sağ yanlı → en büyük kutbun sağı, sol yanlı → en küçük kutbun solu.
- ROC $j\omega$ eksenini içeriyorsa Fourier dönüşümü vardır.
- Basit kesirler: $(s-p)$ için $A/(s-p)$; $(s-p)^2$ için ayrıca $C/(s-p)^2$; $(s^2+b^2)$ için $(Bs+C)/(s^2+b^2)$.
- Tek taraflı Laplace'ta türev başlangıç koşullarını içerir: $s^2Y-sy(0)-y'(0)$.
- Laplace sürekli zamanda kullanılır; ayrık zamandaki karşılığı z dönüşümüdür.

## Detaylı Açıklamalar

- Vize S1 ve S2
  - S1'de grafikte işaret $-0.02$ s'de başlayıp $0.02$ s'de kendini tekrar eder, periyot $0.04$ s'dir. Genlik $\pm20$ arasında olduğundan $A=20$'dir, çünkü kosinüs her zaman $[-1,1]$ aralığında kalır. $x(t)=20\cos(2\cdot25\pi t+\pi/2)=20\cos(50\pi t+\pi/2)$ (ekrandan, 00:15:00).
  - S2'de $x(t)$, $t=-1$'de 0, $t=0$'da 2, $t=2$'de 0 olan üçgendir. $x(-t/2)$ ters çevrilip iki kat genişletilir ($-4$ ile $2$ arası). $x(2(t+2))=x(2t+4)$ için önce 4 birim sola öteleme, sonra 2 ile sıkıştırma yapılır (üçgen $-2.5$ ile $-1$ arası, tepe $-2$'de). $x(-t+1)$ için önce 1 birim sola öteleme, sonra ters çevirme yapılır (üçgen $-1$ ile $2$ arası, tepe $1$'de) (ekrandan, 00:15:00).
- Vize S3: konvolüsyon
  - $h$ ters çevrilir ($-2\ 1\ {-1}\ 2$) ve kaydırılarak örtüşen çarpımlar toplanır. Çarpım tablosu yöntemi (her elemanı her elemanla çarpıp köşegenleri toplama) de kabul edilir. Sonuç $y[n]=[4\ 4\ 3\ {-1}\ {-5}\ {-3}\ {-2}]$, $n=-3..3$ (ekrandan, 00:20:00).
- Vize S4: Fourier serisi
  - $T=2$, $\omega_0=\pi$. $c_k=\frac12\int_0^1e^{-t}e^{-jk\pi t}dt=\frac12\int_0^1e^{-(1+jk\pi)t}dt=\frac{1-e^{-(1+jk\pi)}}{2(1+jk\pi)}$. $e^{-jk\pi}=(-1)^k$ yazılınca $c_k=\frac{1-e^{-1}(-1)^k}{2(1+jk\pi)}$ (ekrandan, 00:20:00).
  - Sonraki adım (soruda istenmedi): $a_k=2\,\mathrm{Re}\{c_k\}$, $b_k=-2\,\mathrm{Im}\{c_k\}$ ile trigonometrik seri yazılır.
- Laplace dönüşümünün mantığı
  - Sonsuza büyüyen bir işaret, $t$ arttıkça sıfıra azalan bir üstelle çarpılırsa enerjisi sınırlı bir işarete dönüşür. Laplace, $x(t)e^{-\sigma t}$ işaretinin Fourier dönüşümünü almaktır: $X(s)=\int x(t)e^{-\sigma t}e^{-j\omega t}dt$. Bu işlem işaretin sinüs/kosinüs bileşenlerini bozmaz, yalnız işareti bastırır (ekrandan, 01:05:00).
  - Laplace da Fourier gibi doğrusal bir dönüşümdür; konvolüsyon ve diferansiyel denklem kolaylıkları burada da vardır.
- Dönüşüm örnekleri (ekrandan, 01:35:00 ve 02:20:00)
  - $\mathcal{L}\{5t-5\}=\frac{5}{s^2}-\frac{5}{s}$; $\mathcal{L}\{5t^3\}=\frac{5\cdot3!}{s^4}=\frac{30}{s^4}$.
  - $\mathcal{L}\{e^{-3t}\}=\frac{1}{s+3}$, $\mathcal{L}\{e^{3t}\}=\frac{1}{s-3}$.
  - $\mathcal{L}\{2\sin5t\}=\frac{10}{s^2+25}$, $\mathcal{L}\{6\cos3t\}=\frac{6s}{s^2+9}$.
  - $\frac{9}{s^2+2}=\frac{9}{\sqrt2}\cdot\frac{\sqrt2}{s^2+(\sqrt2)^2}\Rightarrow\frac{9}{\sqrt2}\sin(\sqrt2\,t)$.
  - $\mathcal{L}\{5t^3e^{-5t}\}=\frac{30}{(s+5)^4}$; $\mathcal{L}\{2\sin(5t)e^{3t}\}=\frac{10}{(s-3)^2+25}$.
  - $\mathcal{L}\{t\sin2t\}=(-1)\frac{d}{ds}\frac{2}{s^2+4}=\frac{4s}{(s^2+4)^2}$.
  - $\mathcal{L}\{e^{-at}\cos(\omega_0t)u(t)\}=\frac{s+a}{(s+a)^2+\omega_0^2}$, ROC $\mathrm{Re}\{s\}>-a$.
- Kutup-sıfır örnekleri (ekrandan, 02:05:00 ve 02:25:00)
  - $x(t)=3e^{-2t}u(t)-2e^{-t}u(t)$: $X(s)=\frac{3}{s+2}-\frac{2}{s+1}=\frac{s-1}{(s+2)(s+1)}$. Kutuplar $-2$ ve $-1$, sıfır $+1$. İşaret sağ yanlı olduğu için ROC en büyük kutbun sağı: $\mathrm{Re}\{s\}>-1$. ROC $j\omega$ eksenini içerdiği için Fourier dönüşümü vardır.
  - $x(t)=e^{-a|t|}=e^{at}u(-t)+e^{-at}u(t)$: $X(s)=\frac{1}{s+a}-\frac{1}{s-a}=\frac{-2a}{(s+a)(s-a)}$, ROC $-a<\mathrm{Re}\{s\}<a$. Sıfırı yoktur.
- Ters dönüşüm örnekleri (ekrandan, 02:35:00 ve 02:45:00)
  - $\frac{4}{s^6}\to\frac{4}{5!}t^5$; $\frac{5}{s-4}\to5e^{4t}$; $\frac{2}{s^2+4}\to\sin2t$; $\frac{3}{s^2+25}\to\frac35\sin5t$; $\frac{s}{s^2+16}\to\cos4t$; $\frac{6s}{s^2+49}\to6\cos7t$.
  - $\frac{1}{(s-5)^2}\to te^{5t}$; $\frac{1}{(s+2)^3}\to\frac{t^2}{2}e^{-2t}$; $\frac{s+1}{(s+1)^2+16}\to e^{-t}\cos4t$; $\frac{2}{(s-3)^2+9}\to\frac23e^{3t}\sin3t$.
  - Basit kesir: $\frac{2s-3}{s^2+3s+2}=\frac{7}{s+2}-\frac{5}{s+1}\to7e^{-2t}-5e^{-t}$.
  - Tam kareye tamamlama: $\frac{1}{s^2+2s+2}=\frac{1}{(s+1)^2+1}\to e^{-t}\sin t$.
- Diferansiyel denklem örneği (ekrandan, 03:00:00)
  - $y''+3y'+2y=x(t)$, $x(t)=u(t)$. Çift taraflı (başlangıç koşulsuz) çözüm: $Y(s)=\frac{1}{s(s+1)(s+2)}=\frac{1/2}{s}-\frac{1}{s+1}+\frac{1/2}{s+2}$, $y(t)=\frac12u(t)-e^{-t}u(t)+\frac12e^{-2t}u(t)$.
  - Tek taraflı çözümde $y(0)=1$, $y'(0)=2$ verildi. Denklem $s^2Y-s-2+3(sY-1)+2Y=\frac1s$ olur. Hoca $Y(s)$'yi iki parçaya ayırıp çözümü sonraki derse bıraktı.
  - Ders sonrası not (derste tamamlanmadı, ajan tarafından hesaplandı): $Y(s)=\frac{1}{s(s+1)(s+2)}+\frac{s+5}{(s+1)(s+2)}$ ve $y(t)=\left(\frac12+3e^{-t}-\frac52e^{-2t}\right)u(t)$. Bu sonuç $y(0)=1$ ve $y'(0)=2$ koşullarını sağlar.
  - Benzer uygulama: RC devresinin diferansiyel denklemi Laplace ile çözülünce devre teorisindeki $e^{-t/RC}$ biçimli sonuç elde edilir (ekrandan, 03:05:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
