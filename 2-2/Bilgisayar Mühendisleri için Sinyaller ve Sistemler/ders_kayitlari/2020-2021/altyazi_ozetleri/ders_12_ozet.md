# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin tarihi 28 Ağustos 2021 Cumartesi. Bu kayıt günün öğleden sonraki oturumudur. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:05'te başlar. Kaydın başı bekleme kısmıdır.
  - Sabahki oturumda (ders 11) Fourier dönüşümü işlenmişti. Hoca bu kayıtta ona "öğleden önce" diye atıf yapıyor.
- Fourier dönüşümü konusunun kısa tekrarı
  - Sinüsün $e^{j\omega t}$ cinsinden yazılması ve negatif genlikli frekans spektrumu.
  - Gibbs olayı (süreksizlik noktalarında taşma).
  - Zaman kayması, frekans kayması, ölçekleme (daraltma ve genişletme), türev özelliği.
  - Modülasyon: $\cos(\omega_0 t)$ ile çarpma ve zamanda çarpmanın frekansta konvolüsyona karşılık gelmesi.
- Üç temel kavram
  - Dürtü cevabı (impulse response): $h(t)$ veya $h[n]$.
  - Frekans cevabı (frequency response): $H(\omega) = Y(\omega)/X(\omega)$.
  - Transfer fonksiyonu (transfer function): $H(s) = Y(s)/X(s)$.
- Sistem modelleme örnekleri
  - Maksimum güç transferi teoremi üzerinden "transfer" kavramı.
  - Sera sıcaklığı kontrolü: kontrol mühendisi modeli kurar, bilgisayar mühendisi model üzerinde analiz yapar.
- Laplace dönüşümü (Laplace transform)
  - İntegral dönüşüm (integral transform) kavramı.
  - Fourier dönüşümünün yakınsamadığı durumlar ve Laplace dönüşümünün bu sorunu nasıl çözdüğü.
  - $s = \sigma + j\omega$, s-düzlemi (s-plane).
  - İki taraflı (bilateral) ve tek taraflı (unilateral) Laplace dönüşümü.
  - Yakınsama bölgesi (ROC, region of convergence).
  - Laplace ile Fourier dönüşümü arasındaki ilişki.
  - Ters Laplace dönüşümü (inverse Laplace transform) ve tablo kullanımı.
- Temel Laplace dönüşüm çiftleri: sabit, $t^n$, $e^{at}$, $\sin$, $\cos$.
- Özellikler: doğrusallık, s-düzleminde öteleme ($e^{at}$ ile çarpma), $t^n$ ile çarpma (s'ye göre türev).
- Duyurular: Ödev 3 açıklaması ve Quiz 3.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu dersi geçen biri şunları bilmeli:
  - Fourier serisi nerede kullanılır?
  - Fourier dönüşümü nerede ve hangi şartlarda kullanılır?
  - Laplace dönüşümü nerede kullanılır?
- $s = j\omega$ demek her zaman doğru değildir.
  - Doğrusu $s = \sigma + j\omega$'dır.
  - Hoca bazı Türkçe kitaplarda doğrudan $s = j\omega$ yazıldığını, bunun yanlış olduğunu söyledi.
  - Yalnız $\sigma = 0$ olduğunda $s = j\omega$ olur. O zaman Laplace dönüşümü Fourier dönüşümüne eşittir.
- Laplace dönüşümü tablosunda iki bilgi bulunur: dönüşüm ve yakınsama bölgesi.
  - Ters dönüşüm, dönüşümün hangi şartlarda yapıldığına göre yapılır.
  - "$e^{3t}$'nin dönüşümü $\frac{1}{s-3}$" demek tek başına eksiktir. Yanına ROC yazılmalıdır.
- ROC $j\omega$ eksenini içeriyorsa Fourier dönüşümü vardır ve Laplace dönüşümüyle aynıdır.
- Detaylar önemlidir.
  - İntegralin sınırlarına dikkat edilmezse dönüşüm yanlış çıkar. Ters dönüşümle bulunan $y(t)$ da yanlış olur.
- Sınavda genellikle Laplace ve Fourier dönüşüm tabloları verilir.
  - Önemli olan dönüşüm kurallarını ve özelliklerini bilmektir.
- Ödevlerde istenen sayıya uyun.
  - "3 tane" denmişse 2 tane yapan puan kaybeder. Önceki ödevlerde bu yüzden puan kırıldı.

## Kısa Tekrar Notları

- Dürtü cevabı: LTI sisteme birim dürtü verildiğinde alınan çıkış. Sistemi "kara kutu" olmaktan çıkarır.
  - Şart: sistem doğrusal ve zamanla değişmez (LTI) olmalı.
- Frekans cevabı: $H(\omega) = \frac{Y(\omega)}{X(\omega)}$.
- Transfer fonksiyonu: $H(s) = \frac{Y(s)}{X(s)}$.
- Laplace dönüşümü: $X(s) = \int_{-\infty}^{\infty} x(t)\, e^{-st}\, dt$, $s = \sigma + j\omega$.
- Tek taraflı Laplace dönüşümü: integral $0$'dan $\infty$'a alınır.
- s-düzlemi: yatay eksen $\sigma$ (reel kısım), dikey eksen $j\omega$ (sanal kısım).
- $e^{-bt}u(t) \leftrightarrow \frac{1}{s+b}$, ROC: $\mathrm{Re}(s) > -b$.
  - $b > 0$ ise ROC $j\omega$ eksenini içerir. Fourier dönüşümü $\frac{1}{j\omega + b}$'dir.
  - $b < 0$ ise Fourier dönüşümü yoktur ama Laplace dönüşümü vardır.
- Temel dönüşüm çiftleri (sağ taraflı, $t > 0$):
  - $A \leftrightarrow \frac{A}{s}$
  - $t^n \leftrightarrow \frac{n!}{s^{n+1}}$
  - $e^{at} \leftrightarrow \frac{1}{s-a}$
  - $\sin(at) \leftrightarrow \frac{a}{s^2+a^2}$
  - $\cos(at) \leftrightarrow \frac{s}{s^2+a^2}$
- Özellikler:
  - Doğrusallık: $\mathcal{L}\{a f(t)\} = a F(s)$.
  - s-düzleminde öteleme: $\mathcal{L}\{e^{at} f(t)\} = F(s-a)$.
  - $t^n$ ile çarpma: $\mathcal{L}\{t^n f(t)\} = (-1)^n \frac{d^n F(s)}{ds^n}$.
- Ters dönüşümde ipuçları:
  - Payda $s^2 + a^2$ ve payda $s$ varsa kosinüs, payda sabit varsa sinüs aranır.
  - Paydada $(s-a)$ ötelemesi varsa sonuç $e^{at}$ ile çarpılır.
  - Paydada $(s^2+a^2)^2$ gibi bir kare varsa sinyal $t$ ile çarpılmıştır.

## Detaylı Açıklamalar

### Fourier dönüşümü tekrarı

- Sinüsün üstel yazımı: $\sin(\omega_0 t) = \frac{e^{j\omega_0 t} - e^{-j\omega_0 t}}{2j}$.
  - Spektrumda biri pozitif, biri negatif katsayılı iki bileşen görülür.
  - Genlik negatif olabilir. Önemli olan genliğin frekansa göre değişimini incelemektir.
- Zaman kayması: $x(t - t_0) \leftrightarrow e^{-j\omega t_0} X(\omega)$.
- Frekans kayması: $e^{j\omega_0 t} x(t) \leftrightarrow X(\omega - \omega_0)$.
- Ölçekleme: işaret zamanda daraltılırsa spektrum genişler. İşaret genişletilirse spektrum daralır.
- Notasyon: $X(\omega)$ ve $X(j\omega)$ ikisi de kullanılır. Anlamları aynıdır.
- Türev özelliği: türev, frekans düzleminde $j\omega$ ile çarpmaya karşılık gelir. Karmaşık işaretlerin Fourier dönüşümünü kısa yoldan bulmak için kullanılır.
- Modülasyon: bir işareti $\cos(\omega_0 t)$ ile çarpmak, spektrumu $\pm\omega_0$'a kaydırır.
- Zamanda çarpma frekansta konvolüsyona, zamanda konvolüsyon frekansta çarpmaya karşılık gelir.

### Dürtü cevabı, frekans cevabı ve transfer fonksiyonu

- Bir sistem giriş sinyalini alır ve başka bir çıkış sinyaline dönüştürür.
- Sistemin nasıl çalıştığını öğrenmek için girişe birim dürtü verilir.
  - $\delta[n]$ yalnız $n = 0$'da 1'dir. Kaydırılmış dürtülerle (her $k$ için $\delta[n-k]$) sistem tamamen tanımlanır.
  - Birim dürtü, çarpmadaki etkisiz eleman gibi davranır.
  - Elde edilen çıkış $h(t)$ veya $h[n]$'dir.
- Frekans cevabı, dürtü cevabının Fourier düzlemindeki karşılığıdır.
  - Zaman düzleminde $y(t)/x(t)$ oranı anlamlı değildir. Bu yüzden oran frekans düzleminde alınır.
- Transfer fonksiyonu aynı oranın s-düzlemindeki karşılığıdır.
  - Ayrık zamanda bunun karşılığı z-dönüşümündeki transfer fonksiyonudur.
- Amaç: sistemi modelleyip istenen girişe karşılık çıkışı bulmak, yani gelecek için tahmin yapmak.

### Maksimum güç transferi ve sistem modelleme

- Hoca "transfer" kavramını maksimum güç transferi teoremiyle açıkladı.
  - Yük direnci kaynağın Thevenin eşdeğer direncine eşit olduğunda yüke en fazla güç aktarılır.
  - Bu durumda verim %50'dir. Örnek: 100 W verirseniz yüke en fazla 50 W aktarılır.
  - Direnç arttıkça akım azalır. Güç ile direnç arasında bir ödünleşme (trade-off) vardır.
- Sera sıcaklığı kontrolü örneği:
  - Değişkenler: zaman, basınç, ortamın hacmi, dış etkenler.
  - Kontrol mühendisi bu değişkenlerle sistemin denklemini ve transfer fonksiyonunu kurar.
  - Bilgisayar mühendisi bu model üzerinde analiz yapar. Örnek: sistem kararlı mı (sınırlı giriş-sınırlı çıkış, BIBO)?
  - Aç-kapa kontrol yerine yapay zekâ içeren uyarlanabilir (adaptive) kontrolcü maliyeti düşürüp ürün kalitesini artırabilir.

### Laplace dönüşümüne giriş

- İntegral dönüşüm:
  - $X(\alpha) = \int_a^b x(t)\, K(\alpha, t)\, dt$. $K$ iki değişkenli çekirdek (kernel) fonksiyondur.
  - İntegral bir değişkene göre alınır. Sonuç diğer değişkenin düzlemine geçer.
  - Fourier dönüşümünde $t$'ye göre integral alınır. Sonuç yalnız $\omega$ içerir, $t$ içermez.
- Laplace dönüşümüne neden ihtiyaç var?
  - Fourier integrali bazı sinyallerde sonsuza gider (yakınsamaz). O zaman Fourier dönüşümü yoktur.
  - Laplace dönüşümü, $j\omega$ yerine $s = \sigma + j\omega$ koyarak bu sorunu azaltır (mitigate eder).
- Laplace dönüşümü: $X(s) = \int_{-\infty}^{\infty} x(t)\, e^{-st}\, dt$.
  - $e^{-st} = e^{-\sigma t}\, e^{-j\omega t}$ olarak açılır.
  - $e^{-\sigma t}$ çarpanı sinyali sönümlendirir. Sönümlenen sinyalin integrali yakınsar.
  - Örnek: $\sin(5t)\, e^{-6t}$ sıfırdan başlar, salınır ve sönümlenerek sıfıra gider.
- Laplace dönüşümünün kullanıldığı iki analiz:
  - Sıfır durum (zero state) analizi: transfer fonksiyonu ile.
  - Başlangıç koşullu diferansiyel denklem çözümü.
    - Örnek: telefon ilk alındığında şarjı yoktur, başlangıç koşulu sıfırdır. Kapatılıp açılan bir sistemde ise önceden kalan veri vardır; başlangıç koşulu sıfır değildir.
- Sürekli zamanda sistemler diferansiyel denklemlerle, ayrık zamanda fark denklemleriyle (difference equations) ifade edilir.
  - Laplace dönüşümü sürekli zamanda, z-dönüşümü ayrık zamanda kullanılır.

### İki taraflı ve tek taraflı Laplace dönüşümü

- İki taraflı (bilateral): integral $-\infty$'dan $+\infty$'a alınır.
- Tek taraflı (unilateral): integral $0$'dan $\infty$'a alınır.
  - Sağ taraflı integralde sıfırın sağındaki değerler kullanılır.
- s-düzlemi:
  - Yatay eksen $\sigma$, dikey eksen $j\omega$'dır.
  - Sistemlerin kararlılık analizi bu düzlemde yapılır.
  - Sol yarı düzlemde (left-half plane) $\mathrm{Re}(s) < 0$'dır.

### Yakınsama bölgesi (ROC)

- ROC, Laplace integralinin yakınsadığı $s$ değerlerinin kümesidir.
- Her sinyalin kendi dönüşümü ve kendi ROC'u vardır.
- Örnek: $x(t) = e^{-bt}u(t)$, $b$ reel sayı.
  - $X(s) = \int_0^{\infty} e^{-(s+b)t}\, dt = \frac{-1}{s+b}\left[\lim_{t\to\infty} e^{-(s+b)t} - 1\right]$
  - Limit yalnız $\mathrm{Re}(s+b) > 0$, yani $\sigma > -b$ ise sıfıra gider.
  - Sonuç: $X(s) = \frac{1}{s+b}$, ROC: $\sigma > -b$.
  - $\sigma < -b$ ise limit sonsuza gider. Dönüşüm yoktur.
- Fourier dönüşümünde $b > 0$ şartı gerekiyordu. Laplace dönüşümünde bu kısıt yoktur.
- $b > 0$ ise:
  - ROC $-b$ gibi negatif bir noktadan başlar ve $j\omega$ eksenini içerir.
  - Sinyal sönümlenen bir üsteldir.
  - Laplace dönüşümü Fourier dönüşümüne eşittir.
- $b < 0$ ise:
  - Sinyal artan bir üsteldir. ROC pozitif bir $\sigma$ değerinden başlar.
  - ROC $j\omega$ eksenini içermez. Fourier dönüşümü yoktur, Laplace dönüşümü vardır.
- Örnek: $e^{-6t}u(t) \leftrightarrow \frac{1}{s+6}$, $\sigma > -6$.
  - ROC $j\omega$ eksenini içerir. Fourier dönüşümü $\frac{1}{j\omega + 6}$'dır.

### Laplace dönüşümünün kullanım akışı

- Zaman düzleminde problem: diferansiyel denklem çözmek, kararlılığı incelemek gibi.
- Laplace dönüşümüyle s-düzlemine geçilir.
  - Dönüştürülmüş fonksiyon büyük harfle yazılır: $y(t) \to Y(s)$.
- s-düzleminde cebirsel işlemler yapılır: toplama, çıkarma, çarpma, bölme.
  - Zaman düzleminde zor olan konvolüsyon burada çarpma olur.
- Ters Laplace dönüşümüyle zaman düzlemine dönülür. Bu sırada ROC dikkate alınır.

### Ters Laplace dönüşümü

- Tanım: $x(t) = \frac{1}{2\pi j} \int_{c - j\infty}^{c + j\infty} X(s)\, e^{st}\, ds$. $c$, ROC içinde bir değerdir.
- Bu integral pratikte pek kullanılmaz. Tablolar kullanılır.
  - Örnek: $\frac{1}{s-5}$, $e^{5t}$'nin Laplace dönüşümüdür (ROC'a dikkat ederek).
- Karmaşık bir rasyonel $X(s)$, kısmi kesirlere ayırma (partial fraction expansion) ile basit kesirlere ayrılır. Bu konu sonraki derste anlatılacak.

### Temel dönüşümler ve örnekler

- Sabit: $\mathcal{L}\{A\} = \int_0^{\infty} A\, e^{-st}\, dt = \frac{A}{s}$.
  - Hoca önce sınırları $-\infty$'dan yazdı, sonra tek taraflı kabul edip sıfırdan yazdığını söyleyerek düzeltti.
- Polinom: $\mathcal{L}\{t^n\} = \frac{n!}{s^{n+1}}$.
  - $n = 0$ için $\frac{1}{s}$ çıkar. Sabit sonucuyla tutarlıdır.
  - $t^2 \leftrightarrow \frac{2!}{s^3}$.
- Ters dönüşüm örnekleri:
  - $\frac{6 \cdot 4!}{s^5} \to 6t^4$.
  - $\frac{6}{s^5} = \frac{6}{4!} \cdot \frac{4!}{s^5} \to \frac{6}{24} t^4 = \frac{t^4}{4}$.
  - Kural: eksik faktöriyeli çarpıp bölerek tamamlayın. Kalan sayı katsayı olur.
- Doğrusallık örneği: $\mathcal{L}\{5t - 6\} = \frac{5}{s^2} - \frac{6}{s}$.
  - Alıştırma: $\mathcal{L}\{3t^2 - 2t + 3\}$. Cevap: $\frac{6}{s^3} - \frac{2}{s^2} + \frac{3}{s}$.
- Üstel: $\mathcal{L}\{e^{at}\} = \frac{1}{s-a}$.
  - $e^{-5t} \to \frac{1}{s+5}$, $e^{5t} \to \frac{1}{s-5}$.
- Sinüs: $\mathcal{L}\{B \sin(at)\} = \frac{Ba}{s^2+a^2}$.
  - $\sin(7t) \to \frac{7}{s^2+49}$.
  - $\frac{3}{s^2+25} = \frac{3}{5} \cdot \frac{5}{s^2+25} \to \frac{3}{5}\sin(5t)$.
  - İspat: $\sin(at)$ üstel biçimde yazılır, iki integral ayrı ayrı alınır.
- Kosinüs: $\mathcal{L}\{B \cos(at)\} = \frac{Bs}{s^2+a^2}$.
  - $\cos(3t) \to \frac{s}{s^2+9}$.
  - $\frac{5s}{s^2+9} \to 5\cos(3t)$.
- Pay ve payda aynı dereceden ise önce bölme yapılır:
  - $\frac{s^2}{s^2+9} = 1 - \frac{9}{s^2+9} \to \delta(t) - 3\sin(3t)$.
- $\cos(3t)$'nin dönüşümünü integralle bulmak için kısmi integrasyon (integration by parts) kullanılır.
  - $u$ seçim sırası (LAPTÜ): logaritmik, ters trigonometrik (arc), polinom, trigonometrik, üstel.

### s-düzleminde öteleme

- $\mathcal{L}\{e^{at} f(t)\} = F(s-a)$.
- Örnekler:
  - $t\, e^{3t} \to \frac{1}{(s-3)^2}$.
  - $t^4\, e^{-3t} \to \frac{4!}{(s+3)^5}$.
  - $\sin(5t)\, e^{at} \to \frac{5}{(s-a)^2 + 25}$.
  - $\cos(\sqrt{7}\, t)\, e^{-3t} \to \frac{s+3}{(s+3)^2 + 7} = \frac{s+3}{s^2+6s+16}$.
- Ters dönüşüm örneği: $\frac{4}{(s-2)^6}$.
  - $\frac{5!}{s^6} \leftrightarrow t^5$. Bu yüzden ifade $\frac{4}{5!} \cdot \frac{5!}{(s-2)^6}$ olarak yazılır.
  - Sonuç: $\frac{4}{120} t^5 e^{2t} = \frac{1}{30} t^5 e^{2t}$.
- Paydayı tam kareye tamamlama:
  - $\frac{s+4}{s^2+8s+20} = \frac{s+4}{(s+4)^2 + 4} \to e^{-4t}\cos(2t)$.
  - $\frac{s+5}{s^2+8s+19} = \frac{s+4}{(s+4)^2+3} + \frac{1}{(s+4)^2+3}$
  - Sonuç: $e^{-4t}\cos(\sqrt{3}\, t) + \frac{1}{\sqrt{3}} e^{-4t}\sin(\sqrt{3}\, t)$.
  - Pay $(s+4)$'e uymuyorsa fazlası ayrı bir kesir olarak yazılır. Bu kesir sinüse karşılık gelir.

### $t^n$ ile çarpma özelliği

- $\mathcal{L}\{t^n f(t)\} = (-1)^n \frac{d^n F(s)}{ds^n}$.
- Örnek: $\mathcal{L}\{t \sin(2t)\}$.
  - $\sin(2t) \to \frac{2}{s^2+4}$.
  - $-\frac{d}{ds}\left(\frac{2}{s^2+4}\right) = \frac{4s}{(s^2+4)^2}$.
- Paydada $(s^2+a^2)^2$ gibi bir kare görürseniz sinyal $t$ ile çarpılmıştır.

### Temel frekans sorusu (öğrenci sorusu)

- $\sin(5\pi t) + \sin(7\pi t)$:
  - Açısal frekanslar $5\pi$ ve $7\pi$. Ortak bölenleri $\omega_0 = \pi$ rad/s.
- $\sin(6\pi t) + \sin(8\pi t)$:
  - Frekanslar $f_1 = 3$ Hz ve $f_2 = 4$ Hz. Temel frekans $f_0 = 1$ Hz.
  - $\omega_0 = 2\pi f_0 = 2\pi$ rad/s.
- $\omega_0$ yazmak için ifadede $\pi$ bulunmalıdır. Normal frekans ($f_0$) Hz cinsindendir.

### Ödev 3 ve quiz duyuruları

- Ödev 3: son teslim 3 Eylül 2021 Cuma 23.59. Online Yıldız sistemine yüklenecek. E-postayla gönderilen ödev kabul edilmez.
  - Frekans gösterimi verilen ayrık zamanlı kare dalganın (dikdörtgen spektrum) ters DTFT'si bulunacak.
    - $X(\Omega) = 1$, $|\Omega| \le W$; $X(\Omega) = 0$, $W < |\Omega| \le \pi$.
  - Analitik çözüm el yazısıyla yapılacak, fotoğrafı rapora eklenecek.
  - MATLAB veya Python ile 3 farklı $W$ değeri için $x[n]$ çizdirilecek ve yorumlanacak.
  - Raporda analitik çözüm, simülasyon sonuçları ve sonda kaynak kod bulunacak.
- Quiz 3: aynı gün saat 15.30'da. 6 soru, yaklaşık yarım saat.
  - Sorular rastgele gelir. Görülen soruya geri dönülemez.
- Son quiz: z-dönüşümü ve sıfır-kutup diyagramı ile ilgili basit bir Python veya MATLAB kodu yazıp yorumlamak.
  - Test olmayacak. Süresi daha uzun olacak (yaklaşık 3 saat).
  - Gelecek Cumartesi, dersin son günü, konu bittikten sonra yayınlanacak.
- Notlar: hoca not girişinde USİS kaynaklı bir sorun yaşadığını, notları başka yoldan açıklamaya devam edeceğini söyledi.

### Ders sonrası notlar

- **Yakınsama bölgesi yönü:** Hoca bir yerde "sigma'nın eksi b'den küçük olduğunu gösteren bir şey olacak tablomuzda" dedi. Doğrusu: $e^{-bt}u(t)$ için ROC $\sigma > -b$'dir. Hoca hemen sonra doğru şartı ($\sigma > -b$) kullandı.
- **$b = 0$ durumu:** Hoca $b = 0$'ın dışarıda bırakılma sebebini "$e^{0t}$ zaten Dirac delta'dır" diye açıkladı. Bu yanlış.
  - $e^{0 \cdot t} u(t) = u(t)$'dir, yani birim basamaktır.
  - $\mathcal{L}\{u(t)\} = \frac{1}{s}$, ROC: $\sigma > 0$.
  - $b = 0$'da ROC'un sınırı tam $j\omega$ ekseni olur. Eksen ROC'a dahil değildir. Bu yüzden Fourier dönüşümü $\frac{1}{j\omega}$ olarak yazılamaz; $u(t)$'nin Fourier dönüşümü $\pi\delta(\omega) + \frac{1}{j\omega}$'dır.
  - Dirac delta'nın Laplace dönüşümü 1'dir.
- **Modülasyon:** Hoca "$\cos(\omega_0 t)$ ile çarpma yapmak tek bir skaler sayıyla çarpma demektir" dedi. Bu doğru değil.
  - $\cos(\omega_0 t)$ zamanla değişen bir çarpandır.
  - $x(t)\cos(\omega_0 t) \leftrightarrow \frac{1}{2}\left[X(\omega - \omega_0) + X(\omega + \omega_0)\right]$. Spektrum $\pm\omega_0$'a kayar ve yarıya iner.
- **Çarpma ve konvolüsyon:** Doğru eşleşmeler:
  - Zamanda konvolüsyon: $x(t) * h(t) \leftrightarrow X(\omega) H(\omega)$.
  - Zamanda çarpma: $x(t)\, p(t) \leftrightarrow \frac{1}{2\pi} X(\omega) * P(\omega)$.
- **Maksimum güç ve verim:** Hoca "maksimum olabilecek verim %50" dedi. Daha doğru ifade:
  - Maksimum güç transferi anında verim %50'dir.
  - Verim, yük direnci büyüdükçe %100'e yaklaşır. Ama o zaman yüke aktarılan güç azalır.
  - Yani "maksimum güç" ile "maksimum verim" aynı şey değildir.
- **Hartley dönüşümü:** Hoca Hartley dönüşümünü Laplace dönüşümündeki bir sorunu gideren bir çalışma olarak andı. Hartley dönüşümü aslında Fourier dönüşümünün reel değerli bir alternatifidir. Çekirdeği $\cos(\omega t) + \sin(\omega t)$'dir.
- **$\frac{4}{(s-2)^6}$ örneği:** Bir öğrenci önce $\frac{4}{6!}$ dedi. Doğrusu $\frac{4}{5!} = \frac{1}{30}$'dur, çünkü $\frac{n!}{s^{n+1}}$'de $n + 1 = 6$ ise $n = 5$'tir. Hoca bunu düzeltti.
- **Laplace ile Fourier ilişkisi:** "Laplace dönüşümünde $j\omega$ yerine $s$ yazılır" sözü ancak ROC $j\omega$ eksenini içeriyorsa tersine çevrilebilir. Yani Fourier dönüşümünü Laplace dönüşümünden $s = j\omega$ koyarak bulmak için ROC $j\omega$ eksenini içermelidir.
- Bu özetteki dönüşüm sonuçları ($\frac{4s}{(s^2+4)^2}$, $\frac{s+5}{s^2+8s+19}$ ayrıştırması, $\frac{s^2}{s^2+9}$ ayrıştırması) Python ile sayısal olarak kontrol edildi.
- Kayıtta geçen ödev metni ve "Laplace Transform Definition" slaytı ekran karelerinden okundu.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
