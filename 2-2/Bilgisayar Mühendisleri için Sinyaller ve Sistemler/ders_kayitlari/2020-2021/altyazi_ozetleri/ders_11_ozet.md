# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin tarihi 28 Ağustos 2021 Cumartesi (yaz okulu, sabah oturumu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:04'te başlar. Kaydın başı bekleme kısmıdır.
  - Aynı gün öğleden sonra bir oturum (Laplace dönüşümü) ve quiz daha var.
- Fourier dönüşümü ile LTI sistem analizi
  - Sürekli zaman örneği: $\frac{dy}{dt}+2y(t)=x(t)$ sisteminin frekans cevabı ve $x(t)=e^{-t}u(t)$ girişine çıkışı.
  - Ayrık zaman örneği: $y[n]-\frac34y[n-1]+\frac18y[n-2]=x[n]$ sisteminin frekans cevabı ve birim darbe cevabı.
  - Ayrık zaman örneği: $y[n]-\frac12y[n-1]=x[n]+\frac12x[n-1]$ sistemi ve $\cos(\frac{\pi}{2}n)$ girişi.
- Frekans cevabı (frequency response): $H(\omega)=\frac{Y(\omega)}{X(\omega)}$.
- Fourier dönüşümünün uygulamaları (slayt)
  - RC devresi örneği, periyodik gürültünün görüntüden temizlenmesi.
  - Filtreler: alçak geçiren, yüksek geçiren, bant geçiren, bant durduran.
  - Faz kaydıran filtre örneği.
- Örnekleme (sampling) ve örtüşme (aliasing)
  - Nyquist şartı, normalize (dijital) frekans, örtüşmenin sebebi.
- FIR filtreler
  - Kayan ortalama (running average) filtresi, ağırlıklı ortalama filtresi.
  - Filtrenin konvolüsyon olarak yazılması, birinci fark (türev) filtresi.
  - Blok diyagram, frekans cevabı ve MATLAB'de `conv`, `freqz`.
- Ders planı ve quiz duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fourier dönüşümü sayesinde diferansiyel denklem çözmeden sistemin çıkışı bulunabilir.
  - Türev, $j\omega$ ile çarpmaya dönüşür. Denklem cebirsel hale gelir.
- Ayrık sistemlerde fark denklemi de aynı şekilde çözülür.
  - Zamanda bir birim gecikme, $e^{-j\Omega}$ ile çarpmaya dönüşür.
- Zamanda konvolüsyon yerine frekans düzleminde çarpma yapılır. Bu, işi çok kolaylaştırır.
- Fourier dönüşüm tablosunu ve özelliklerini (türev, zamanda öteleme) iyi bilin.
- Ayrık sinyalleri `stem` ile çizin.
  - Ödevlerde ayrık sinyali `plot` ile çizenlerden puan kesildi.
- Örnekleme frekansı en yüksek frekansın en az iki katı olmalı.
  - "$f_s$ büyük olsun" demek yetmez, $2f_{max}$ şartı bilinmeli.
- Basit kesirlere ayırmayı Laplace dönüşümünde ayrıntılı anlatacak. Burada sizi bununla uğraştırmak istemiyor.
- Aperiyodik sinyallerle ilgili slaytlardan soru sorulmayacak.
- Sınavlarda sizi ağır matematiğe boğmayacak.
- Blok diyagram verilirse, sistemin denklemini birim darbe cinsinden yazabilmelisiniz.

## Kısa Tekrar Notları

- Türev özelliği: $\frac{dy(t)}{dt}\leftrightarrow j\omega Y(\omega)$.
- Zamanda öteleme (sürekli): $y(t-t_0)\leftrightarrow e^{-j\omega t_0}Y(\omega)$.
- Zamanda öteleme (ayrık): $y[n-k]\leftrightarrow e^{-jk\Omega}Y(\Omega)$.
- $e^{-at}u(t)\leftrightarrow\frac{1}{a+j\omega}$, $a>0$.
- $a^n u[n]\leftrightarrow\frac{1}{1-ae^{-j\Omega}}$, $|a|<1$.
- Frekans cevabı: $H=\frac{Y}{X}$. Birim darbe cevabı: $h=\mathcal{F}^{-1}\{H\}$.
- Çıkış: $y=h*x$, yani $Y=H\cdot X$.
- LTI sisteme $\cos(\Omega_0 n)$ girerse çıkış $|H(\Omega_0)|\cos(\Omega_0 n+\angle H(\Omega_0))$ olur.
- Nyquist: $f_s\geq 2f_{max}$ (sinüs için tam olarak $f_s>2f_{max}$).
- Temel frekans: bileşen frekanslarının EBOB'u. $f_k=kf_0$.
- Normalize frekans: $\hat\omega=\omega T_s=\frac{2\pi f}{f_s}$.
- Örtüşme: $\cos(\hat\omega n)=\cos((\hat\omega+2\pi l)n)$. $f_0$, $f_0+f_s$, $f_0+2f_s$ ayırt edilemez.
- FIR filtre: $y[n]=\sum_{k=0}^{M}b_kx[n-k]$. Mertebe $M$, uzunluk $M+1$.
- Birinci fark filtresi: $y[n]=x[n]-x[n-1]$. $u[n]-u[n-1]=\delta[n]$.

## Detaylı Açıklamalar

### Sürekli zaman örneği: birinci dereceden sistem

- Sistem: $\frac{dy(t)}{dt}+2y(t)=x(t)$.
  - $t$'ye bağlı ve diferansiyel denklemle verildiği için sürekli zamanlı bir sistemdir.
- İki tarafın Fourier dönüşümü alınır:
  - $j\omega Y(\omega)+2Y(\omega)=X(\omega)$.
  - $H(\omega)=\frac{Y(\omega)}{X(\omega)}=\frac{1}{2+j\omega}$.
- Giriş $x(t)=e^{-t}u(t)$:
  - $X(\omega)=\int_0^{\infty}e^{-t}e^{-j\omega t}dt=\frac{1}{1+j\omega}$.
- Çıkış:
  - $Y(\omega)=H(\omega)X(\omega)=\frac{1}{(1+j\omega)(2+j\omega)}$.
  - Basit kesirlere ayırma: $Y(\omega)=\frac{1}{1+j\omega}-\frac{1}{2+j\omega}$.
  - Ters dönüşüm: $y(t)=\left(e^{-t}-e^{-2t}\right)u(t)$.
- $t=100$ anındaki çıkış için bu ifadede $t=100$ yazılır. Sonuç pratikte sıfırdır ($\approx e^{-100}$).
- Ödev olarak bırakılan madde: $x(t)=u(t)$ girişi için çıkışı bulun.
- $H(\omega)$'ya sistemin frekans cevabı denir. Laplace dönüşümünde çıkışın girişe oranına transfer fonksiyonu (sistem modeli) denir.
- Kontrol sistemlerinde sistem, çıkış/giriş oranı ile modellenir ve analiz edilir.

### Birim darbe cevabı ve frekans cevabı

- Sisteme birim darbe ($\delta$) uygulanınca elde edilen çıkışa birim darbe cevabı denir ve $h$ ile gösterilir.
  - Bu, sistemin "röntgeni" gibidir. Sistemin nasıl çalıştığını gösterir.
- Herhangi bir giriş için çıkış konvolüsyonla bulunur: $y=h*x$.
- Frekans düzleminde konvolüsyon çarpmaya dönüşür: $Y=H\cdot X$.
- Bu yüzden önce $X$ bulunur, $H$ ile çarpılır, sonra ters dönüşüm alınır.

### Ayrık zaman örneği 1

- Sistem: $y[n]-\frac34y[n-1]+\frac18y[n-2]=x[n]$.
- Ayrık zamanda Fourier dönüşümü toplamla, ters dönüşümü integralle alınır.
- Dönüşüm:
  - $Y(\Omega)\left(1-\frac34e^{-j\Omega}+\frac18e^{-j2\Omega}\right)=X(\Omega)$.
  - $H(\Omega)=\frac{1}{1-\frac34e^{-j\Omega}+\frac18e^{-j2\Omega}}$.
- Payda çarpanlarına ayrılır:
  - $H(\Omega)=\frac{1}{\left(1-\frac12e^{-j\Omega}\right)\left(1-\frac14e^{-j\Omega}\right)}$.
- Basit kesirler:
  - $H(\Omega)=\frac{2}{1-\frac12e^{-j\Omega}}-\frac{1}{1-\frac14e^{-j\Omega}}$.
- Tablodan ters dönüşüm:
  - $h[n]=\left[2\left(\tfrac12\right)^n-\left(\tfrac14\right)^n\right]u[n]$.
- $u[n]$'nin anlamı:
  - Gerçek bir sistem $n=0$'da çalışmaya başlar. $n=-1$ diye bir örnek yoktur.
  - Ayrıca $(\frac12)^n$ ve $(\frac14)^n$, $n\to\infty$ için sıfıra gider. Seri yakınsar ve dönüşüm geçerlidir.
- Bu sisteme $x[n]=\delta[n]+2\delta[n-1]+3\delta[n-2]$ girerse çıkış $y=h*x$ olur. Konvolüsyon yerine $X(\Omega)H(\Omega)$ çarpımının ters dönüşümü alınabilir.

### Ayrık zaman örneği 2

- Sistem: $y[n]-\frac12y[n-1]=x[n]+\frac12x[n-1]$.
- Frekans cevabı:
  - $Y(\Omega)\left(1-\frac12e^{-j\Omega}\right)=X(\Omega)\left(1+\frac12e^{-j\Omega}\right)$.
  - $H(\Omega)=\frac{1+\frac12e^{-j\Omega}}{1-\frac12e^{-j\Omega}}=\frac{1}{1-\frac12e^{-j\Omega}}+\frac12\cdot\frac{e^{-j\Omega}}{1-\frac12e^{-j\Omega}}$.
- Birim darbe cevabı:
  - İlk terim: $(\frac12)^n u[n]$.
  - İkinci terimdeki $e^{-j\Omega}$ çarpanı bir birim zaman ötelemesidir: $\frac12(\frac12)^{n-1}u[n-1]$.
  - $h[n]=\left(\tfrac12\right)^n u[n]+\tfrac12\left(\tfrac12\right)^{n-1}u[n-1]$.
- Değerler:
  - $n=0$: $h[0]=1$ (ikinci terim sıfır).
  - $n\geq1$: $h[n]=\left(\tfrac12\right)^{n-1}$.
- Ödev olarak bırakılan madde: $x[n]=\cos(\frac{\pi}{2}n)$ girişi için çıkış.
  - Hocanın verdiği cevap: $y[n]=\cos\left(\frac{\pi}{2}n-2\tan^{-1}\frac12\right)$.
  - Açıklama: $H(\frac{\pi}{2})=\frac{1-j/2}{1+j/2}$. Genliği 1, fazı $-2\tan^{-1}\frac12\approx-0.927$ rad.

### Fourier dönüşümünün uygulamaları

- Fourier dönüşümü, zaman düzleminde görülemeyen özellikleri ortaya çıkarır. Zor işlemleri kolaylaştırır.
- RC devresi örneği: Devrenin modeli kurulup frekans cevabı bulunur. Belli bir frekanstaki cevap için $\omega$ yerine o değer yazılır (ör. $H(100)$).
- Periyodik gürültünün temizlenmesi (görüntü örneği):
  - Gürültülü görüntünün Fourier dönüşümünde gürültü frekanslarında tepeler (spike) görülür.
  - Bu tepelerin genliği sıfırlanıp ters dönüşüm alınır. Görüntü büyük ölçüde temizlenir.
  - İstenmeyen frekansı zaman düzleminde bulmak zordur. Frekans düzleminde bu kolaydır.
- Filtre türleri:
  - Alçak geçiren (low-pass): kesim frekansının altındaki frekansları geçirir.
  - Yüksek geçiren (high-pass): düşük frekansları bastırır, yüksekleri geçirir.
  - Bant geçiren (band-pass): $\alpha$ ile $\beta$ arasındaki frekansları geçirir.
  - Bant durduran (band-reject/band-stop, notch): $\alpha$ ile $\beta$ arasındaki frekansları bastırır.
  - Geçirme bandı (passband) ve durdurma bandı (stopband).
- Filtreleme, frekans düzleminde girişin dönüşümü ile filtrenin dönüşümünün çarpılmasıdır.
- Slayttaki örnekte DC, 1, 2 ve 3 Hz bileşenli bir işaret, bileşenlerin fazını kaydıran bir filtreden geçirildi.

### Örnekleme ve örtüşme

- Nyquist şartı: $f_s\geq2f_{max}$.
- $f_{max}$, işaretin Fourier dönüşümünde görülen en yüksek frekanstır.
  - Toplam şeklindeki kosinüslerde frekanslar doğrudan okunur. Çarpımlarda veya karmaşık işaretlerde Fourier dönüşümüne bakmak gerekir.
- Temel frekans $f_0$, bileşen frekanslarının EBOB'udur (GCD).
- Düzgün örnekleme: $t=nT_s=\frac{n}{f_s}$.
  - Örnek: $T_s=125\ \mu s$ ise $f_s=8000$ Hz.
  - Örnek: $\cos(2\pi\cdot500t)$, $f_s=5000$ Hz ile örneklenirse $x[n]=\cos\left(\frac{\pi n}{5}\right)$.
- Normalize (dijital) frekans: $\hat\omega=\omega T_s=\frac{2\pi f}{f_s}$. Birimi radyandır, $0$ ile $2\pi$ arasında düşünülür.
  - Örnek: 100 Hz'lik işaret 1000 Hz ile örneklenirse $\hat\omega=0.2\pi$.
- Örtüşmenin sebebi:
  - Kosinüs $2\pi$ periyotludur. Tam sayı $n$ için $\cos(0.4\pi n)=\cos(2.4\pi n)$.
  - Yani örneklemeden sonra $f_0$, $f_0+f_s$ ve $f_0+2f_s$ frekansları aynı örnekleri verir.
  - $f_s<2f_{max}$ ise spektrum kopyaları üst üste biner. Orijinal işaret geri elde edilemez.
- Bu dersin bilinmesi gereken kısmı: $2f_{max}$ şartı ve $t$ düzleminden $n$ düzlemine geçiş.

### FIR filtreler

- Dijital filtre, $x[n]$'den $y[n]$ üreten bir algoritmadır. Yazılım veya donanım (FPGA, DSP yongası) olabilir.
- Kayan ortalama (running average) filtresi:
  - 3 noktalı, ileriye bakan: $y[n]=\frac13(x[n]+x[n+1]+x[n+2])$.
  - 3 noktalı, geçmişe bakan (nedensel): $y[n]=\frac13(x[n]+x[n-1]+x[n-2])$.
  - Ortalama, keskin geçişleri yumuşatır (smoothing). Ani gürültü tepeleri azalır, ama bir miktar bilgi kaybedilir.
  - Pencere boyutu genellikle tek sayıdır. Türeve göre pencere boyutunu değiştiren filtrelere uyarlamalı (adaptive) filtre denir.
- Genel FIR filtre: $y[n]=\sum_{k=0}^{M}b_kx[n-k]$.
  - Katsayılar farklı ise ağırlıklı ortalama filtresi olur.
  - Örnek: borsa verisine 50 noktalı ortalama filtresi uygulanması.
- Filtre konvolüsyondur:
  - Filtre katsayıları birim darbe cinsinden yazılır: $h[n]=\sum b_k\delta[n-k]$.
  - $y[n]=x[n]*h[n]$. Frekans düzleminde $Y=H\cdot X$.
  - MATLAB'de `conv(bb, xx)`. İki boyutlu konvolüsyon (`conv2`) görüntüye filtre uygular.
- Örnek: $x[n]$ tamamı 1 olan bir dizi, $h[n]=[1,-1,2,-1,1]$.
  - Sonuç: $y[n]=[1,0,2,1,2,2,2,\dots]$.
- Birinci fark (türev) filtresi:
  - Türev tanımı: $\lim_{h\to0}\frac{f(x+h)-f(x)}{h}$.
  - Bilgisayarda $h$ en küçük 1 olabilir: $y[n]=x[n]-x[n-1]$.
  - Örnek: $u[n]-u[n-1]=\delta[n]$.
- Blok diyagram:
  - $x[n]$ gecikme blokları ($z^{-1}$) ile geciktirilir. Her gecikmiş örnek $b_k$ ile çarpılır ve toplanır.
  - Temel işlemler: toplama, çarpma, gecikme.
- Kaskad sistemler: Bir sistemin çıkışı diğerine girer. LTI sistemlerde sıra değiştirilebilir (konvolüsyonun değişme özelliği).
- Frekans cevabı örneği: $h[n]=\delta[n]+2\delta[n-1]+\delta[n-2]$.
  - $H(\hat\omega)=1+2e^{-j\hat\omega}+e^{-j2\hat\omega}=(2+2\cos\hat\omega)\,e^{-j\hat\omega}$.
  - Genliği $\hat\omega=0$'da en büyük, $\hat\omega=\pi$'de sıfırdır. Alçak geçiren bir filtredir.
  - MATLAB'de `freqz` ile frekans cevabı çizilir.

### Ders planı ve duyurular

- Hoca sohbet penceresinden bir formül kağıdı paylaştı.
- Aynı günün öğleden sonra oturumunda Laplace dönüşümü ve Fourier ile ilişkisi anlatılacak.
- Gelecek hafta Z dönüşümü, ardından sınava yönelik soru çözümü yapılacak.
- Quiz 28 Ağustos'ta 15:30-16:00 arasında. Sistemde ilan edilecek.
- Vize notuna itirazı olanlar hocayla görüşebilir.

### Ders sonrası notlar

- Sürekli zaman örneğinde hoca sonucu "$e^{-t}$ artı $e^{-2t}$" diye okudu. Basit kesirlerde ikinci terim eksi işaretlidir. Doğrusu: $y(t)=\left(e^{-t}-e^{-2t}\right)u(t)$.
- Hoca birim darbe cevabını anlatırken bir yerde "birim basamak girişine karşılık gelen çıktı" dedi. $h$, birim darbe ($\delta$) girişine karşılık gelen çıktıdır. Birim basamak girişine karşılık gelen çıktıya basamak cevabı (step response) denir.
- Bir öğrenci türev özelliği için "$e^{j\omega}$ ile çarpma" dedi. Hoca bunun zamanda öteleme özelliği olduğunu ve türevin $j\omega$ ile çarpma olduğunu söyledi. Bu düzeltme doğrudur.
- Hoca Nyquist şartını önce "$f_s\geq f_{max}$" diye söyledi, sonra $2f_{max}$ olarak düzeltti. Doğrusu $f_s\geq2f_{max}$. Tam $f_{max}$ frekansındaki bir sinüs için $f_s=2f_{max}$ yetmeyebilir; bu yüzden pratikte $f_s>2f_{max}$ seçilir.
- Hoca filtre bankalarından bahsederken "Kalman filtre bankası" dedi. Filtre bankası (filter bank) ile Kalman filtresi farklı kavramlardır. Kalman filtresi, gürültülü ölçümlerden durum tahmini yapan bir yöntemdir.
- Hoca kayan ortalama filtresi sonsuz kez uygulanırsa işaretin sıfıra gideceğini söyledi. Katsayıları toplamı 1 olan bir ortalama filtresi örneklerin toplamını (DC bileşeni) korur. İşaret giderek yayılır ve düzleşir; tepe değerleri bu yüzden küçülür.
- Ayrık zaman örneklerinin birim darbe cevapları, fark denklemleri doğrudan çalıştırılarak Python ile doğrulandı:
  - Örnek 1: $h=[1,\ 0.75,\ 0.4375,\ 0.2344,\dots]$, formülle aynı.
  - Örnek 2: $h=[1,\ 1,\ 0.5,\ 0.25,\dots]$, formülle aynı.
- $H(\frac{\pi}{2})$'nin genliği 1, fazı $-0.927$ rad ($=-2\tan^{-1}\frac12$) olarak doğrulandı.
- $[1,1,1,\dots]$ ile $[1,-1,2,-1,1]$ konvolüsyonu Python ile doğrulandı: $[1,0,2,1,2,2,2]$.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
