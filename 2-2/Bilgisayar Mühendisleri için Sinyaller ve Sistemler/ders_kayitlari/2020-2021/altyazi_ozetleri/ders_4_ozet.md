# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 11 Ağustos 2021 Çarşamba. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:04'te başlar.
  - Yaklaşık 00:56-01:06 ve 01:54-02:05 arasında ara verildi.
- Dersin işleyişi ve duyurular
  - 4. ve 5. bölüm PDF'leri ile yedek kaynak M. J. Roberts kitabı paylaşılan klasöre yüklendi. Michael D. Adams'ın kaynakları da ayrıca var.
  - 5. bölümün düzeltilmiş "versiyon 1" dosyası yüklendi. Örnekleme (sampling) bölümü büyük ölçüde atlanacak.
  - Cumartesi günü konvolüsyon bölümü biterse 7 günlük bir kodlama ödevi verilecek. Cumartesi öğleden sonra yine quiz var.
- Birinci quizin soru çözümleri (örnekleme frekansı, analog sinyaller, veri boyutu, nicemleme, tek/çift sinyal).
- Sinyal işlemlerinin birleştirilmesi: $x(-2t+6)$ üç farklı sırayla.
- Ayrık zamanda örnek: $x[-n+2]$.
- Slayt örneği: $x(t)u(1-t)$, $x(t)[u(t)-u(t-1)]$, $x(t/2)\delta(t-1.5)$.
- Bağımsız bileşen analizi (ICA) ve kokteyl partisi problemi (tanıtım).
- MATLAB ve Python (NumPy, Matplotlib) ile sinyal çizdirme: `plot`, `stem`, `hold on`, `figure`, `subplot`, eksen etiketleri, başlık, lejant.
- Sistemlere giriş: sistem tanımı, blok diyagramları.
- Temel sistem işlemleri: ölçekleme, türev, integral, zamanda öteleme, konvolüsyon, toplama, çarpma.
- Sistem bağlantıları: kaskat (seri), paralel, geri beslemeli.
- Sistem özellikleri: doğrusallık, belleklilik, nedensellik, zamanla değişmezlik, BIBO kararlılık, terslenebilirlik.
- Diferansiyel ve fark denklemleriyle tanımlanan sistemler (RLC devresi, yay-kütle sistemi).

## Hocanın Özellikle Vurguladığı Kısımlar

- Öteleme, ölçekleme ve tersleme her zaman bağımsız değişken ($t$ veya $n$) üzerinde yapılır. Genlik ekseninde yapılmaz.
  - Her adımda elde edilen yeni sinyal üzerinde $t$ yerine yeni ifade yazılır.
  - En sık hata: $x(2t)$'den $x(2t+6)$'ya geçerken 6 birim ötelemek. Doğrusu 3 birim ötelemektir.
- Kaynaklarda önerilen kolay sıra: önce öteleme, sonra ölçekleme ve tersleme (bu ikisi istenen sırada).
- Sınavda mutlaka bu tür bir sinyal dönüşümü sorusu gelir. Örnek çözerek pratik yapın.
- Ödevlerde raporlama önemlidir. Grafikleri özenle çizin.
  - Eksen etiketleri, başlık, lejant ve `subplot` kullanın. Raporlamadaki eksikler puan kaybettiriyor.
  - Ödevde bir sahnede 4 grafiği aynı pencerede çizmeniz istenecek.
- Bilgisayarda saklanan her sinyal ayrıktır. `plot` yalnızca örnekler arasını doldurup sürekli gibi gösterir; ayrık gösterim için `stem` kullanılır.
- Euler formülü $e^{j\omega t}=\cos\omega t+j\sin\omega t$ ezbere bilinmeli.
- Doğrusal ve zamanla değişmez (LTI) sistemler dersin geri kalanının temelidir. Konvolüsyon bunların üzerine kurulur.
- Nedensel (causal) ile gündelik (casual) kelimelerini karıştırmayın.
- Anlamadığınız yeri sormaktan çekinmeyin. Hoca bir derste bu soruyu 30-35 kez sorduğunu, çok az geri dönüş aldığını söyledi.
- İnsan öğrenmesi modelini (integratör + geri besleme) doğru yorumlayan öğrenciye (Kayra) bonus verildi.

## Kısa Tekrar Notları

- CD kalitesi: $f_s=44100$ Hz. Kaydedilebilecek en yüksek frekans $f_s/2=22050$ Hz.
- $256\times256$ piksel, 256 renk: $2^{16}$ örnek $\times$ 8 bit $=2^{16}$ bayt $=64$ KB.
- 10 dakika, CD kalitesi, 16 bit, stereo: $44100\times600\times16\times2=846\,720\,000$ bit $\approx 100.9$ MiB.
- $\pm20$ V aralık, 16 bit: $L=2^{16}=65536$ seviye, adım $\Delta=40/65536\approx0.00061$ V.
- $x(t)=t^2+2$: $x(-t)=x(t)$, çifttir ama tek değildir.
- $x(-2t+6)$ için üç yol:
  - $x(t+6)\to x(-t+6)\to x(-2t+6)$
  - $x(2t)\to x(2(t+3))=x(2t+6)\to x(-2t+6)$
  - $x(-t)\to x(-(t-6))=x(-t+6)\to x(-2t+6)$
- Doğrusallık: $S\{a x_1+b x_2\}=aS\{x_1\}+bS\{x_2\}$ (homojenlik + toplamsallık).
- Belleksiz: çıkış yalnızca o anki girişe bağlı. Nedensel: çıkış yalnızca şimdiki ve geçmiş girişlere bağlı.
- Zamanla değişmez: $x(t-t_0)\to y(t-t_0)$.
- BIBO kararlılık: sınırlı her giriş için çıkış sınırlıdır.
- Fark denklemi örneği: $y[n]=a\,y[n-1]+x[n-1]$ gibi geçmiş değerlere bağlı ayrık sistem.

## Detaylı Açıklamalar

### Quiz 1 çözümleri

- Soru: 4 dakikalık müzik CD kalitesinde (44100 Hz) saklanacak. Sağlıklı kayıt için en yüksek frekans bileşeni ne olmalı?
  - Cevap: 22050 Hz. Örnekleme frekansı en yüksek frekansın en az iki katı olmalıdır.
- Soru: Analog sinyallerle ilgili hangisi yanlıştır?
  - "Analog sinyal hem analog hem dijital sistemde işlenebilir" doğrudur. Analog sinyal ADC ile dijitale çevrilip işlenebilir.
  - "Teoride ve uygulamada analog sinyal sonsuz kez örneklenmiş sinyal olarak tanımlanabilir" yanlıştır. Teoride doğru, uygulamada sonsuz örnekleme mümkün değildir.
  - Bir öğrenci, analog sinyalin dijital sistemde işlenmesinin "hibrit sistem" olduğunu ileri sürdü. Hoca, şıkkın bir olasılıktan söz ettiğini ve doğru olduğunu söyledi.
- Soru: $256\times256$ çözünürlüklü, 256 renkli görüntü ne kadar yer kaplar?
  - Örnek sayısı $256\times256=2^{16}$. Her örnek $\log_2256=8$ bit $=1$ bayt.
  - Toplam $2^{16}$ bayt $=2^{6}\times2^{10}$ bayt $=64$ KB.
- Ek soru (derste soruldu): 10 dakikalık stereo müzik, 44100 Hz, 16 bit.
  - $44100\times60\times10$ örnek $\times16$ bit $\times2$ kanal.
  - Stereo, iki kanallı (iki mikrofonlu) kayıt demektir. Veri iki katına çıkar.
- Soru: $x(t)=100\sin(500\pi t+90^\circ)$ ile ilgili hangisi yanlıştır?
  - $f=250$ Hz, genlik 100, faz $90^\circ$. En az örnekleme frekansı 500 Hz.
  - 1000 Hz ile örneklenirse $t=n/f_s$ yazılır: $x[n]=100\sin(\pi n/2+90^\circ)$.
  - Yanlış şık: "$2t$ dönüşümü yapılırsa sinyal genlik ekseninde sıkıştırılır." Sıkıştırma zaman ekseninde olur.
- Soru: $x(t)=t^2+2$ tek mi, çift mi?
  - $x(-t)=t^2+2=x(t)$. Çifttir, tek değildir.
- Soru: $-20$ ile $+20$ V arasındaki sinyal 16 bit ile nicemlenirse seviye sayısı $L$ ve doğruluk $\Delta$ nedir?
  - $L=2^{16}=65536$. $\Delta=40/2^{16}$.
  - Bir öğrenci "doğruluk değil nicemleme hatası sorulmalı" dedi. Hoca slaytta ikisinin aynı kavram olarak geçtiğini söyledi.

### Sinyal işlemlerinin birleştirilmesi: $x(-2t+6)$

- Üç işlem var: tersleme, öteleme, ölçekleme. Her adımda yeni sinyal üzerinde $t$ yerine ifade yazılır.
- Yol 1:
  - 6 birim öne alma: $x(t+6)$.
  - Tersleme: $t\to-t$, $x(-t+6)$.
  - 2 ile sıkıştırma: $t\to2t$, $x(-2t+6)$.
- Yol 2:
  - 2 ile sıkıştırma: $x(2t)$.
  - Öne alma 6 değil 3 birimdir: $t\to t+3$, $x(2(t+3))=x(2t+6)$.
  - Tersleme: $x(-2t+6)$.
- Yol 3:
  - Tersleme: $x(-t)$.
  - Başta eksi olduğu için 6 birim gecikme gerekir: $t\to t-6$, $x(-(t-6))=x(-t+6)$.
  - 2 ile sıkıştırma: $x(-2t+6)$.
- Üç işlem 6 farklı sırayla yapılabilir. Kurallara uyulursa sonuç değişmez.
- Matematikteki fonksiyon bileşkesiyle karıştırmayın. Burada $y(t)=x(t+5)$ gibi ifadelerde değişen şey bağımsız değişkendir.

### Ayrık örnek: $x[-n+2]$

- Önce 2 birim öne alma: $x[n+2]$. $n=4$'teki örnek $n=2$'ye gelir.
- Sonra tersleme: $x[-n+2]$. $n=2$'deki örnek $n=-2$'ye gider.

### Slayt örneği: çarpma ve dürtü

- Verilen $x(t)$: $-1\le t\le0$ arasında 0'dan 1'e doğrusal artış, $0\le t\le1$ arasında 1, $1\le t\le2$ arasında 2, diğer yerlerde 0 (slayt karesinden).
- (a) $x(t)u(1-t)$: $u(1-t)$, $t\le1$ için 1'dir. Sinyalin $t>1$ kısmı silinir.
- (b) $x(t)[u(t)-u(t-1)]$: $[0,1)$ penceresi. Yalnızca $0\le t<1$ kısmı (değer 1) kalır.
- (c) $x(t/2)\delta(t-1.5)$:
  - $x(t/2)$, $x(t)$'nin 2 kat gerilmiş halidir. $x(t)$'nin 1'deki değeri 2'ye, 2'deki değeri 4'e gider.
  - Dürtü yalnızca $t=1.5$'teki değeri alır: $x(0.75)\,\delta(t-1.5)=1\cdot\delta(t-1.5)$.
  - Hoca, slayttaki cevapta dürtü ağırlığının 2 gösterildiğini, bunun $x(1.5)$ ile karıştırıldığını ve doğrusunun 1 olduğunu söyledi.
- $\sum_k\delta(t-k)$ bir örnekleme operatörüdür. Sinyalin yalnızca seçilen anlardaki değerlerini bırakır.

### Bağımsız bileşen analizi (ICA)

- Kokteyl partisi problemi: $n$ kişi konuşuyor, $n$ mikrofon kayıt yapıyor. Kimin ne söylediği ayrılmak isteniyor.
- Kör kaynak ayrıştırma (blind source separation) da denir.
- Kaydedilen sinyaller kaynakların karışımıdır (toplamı). ICA bu karışımdan kaynakları tahmin eder.
- Gösterilen örnekte sinüzoidal ve kare dalga karıştırıldı, ICA ile ayrıldı. Bir bileşende faz kayması oluştu.

### MATLAB ile sinyal çizdirme

- `t = 0:0.01:250;` ile bağımsız değişken oluşturulur.
- `plot(t, x)`: örnekler arasını doldurur, sürekli gibi gösterir.
- `stem(t, x)`: ayrık gösterim.
- `hold on`: aynı grafiğe üst üste çizim. `plot(t, y, 'r')` ile renk verilir.
- `figure`: yeni pencere açar. Yoksa yeni `plot` eskisini siler.
- `subplot(m, n, k)`: $m$ satır, $n$ sütunluk ızgaranın $k$. konumuna çizer.
- Örnek: sönümlü sinüzoid.

```matlab
t  = 0:0.01:250;
x1 = exp(-0.02*t);          % sönen üstel
x2 = sin(10*pi*t/250);      % sinüzoid
x  = x1 .* x2;              % eleman eleman çarpım (.*)

subplot(3,1,1); plot(t, x1, 'r'); axis auto; grid on;
xlabel('Time (s)'); ylabel('Amplitude');
legend('Exponential Signal'); title('Signal Plotting Using MATLAB');

subplot(3,1,2); plot(t, x2, 'b'); grid on;
xlabel('Time (s)'); ylabel('Amplitude'); title('Sinusoidal Signal');

subplot(3,1,3); plot(t, x, 'g'); grid on;
xlabel('Time (s)'); ylabel('Amplitude');
```

- Vektörlerin çarpımında `*` değil `.*` kullanılır.
- Komutlar bir `.m` betiğine (script) yazılıp tek seferde çalıştırılabilir. Grafik PNG olarak dışa aktarılabilir.
- `clear` değişkenleri, `clc` komut penceresini temizler.

### Python ile sinyal çizdirme

- NumPy ve Matplotlib gerekir.

```python
import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(-0.02, 0.05, 1000)
plt.plot(t, 325*np.sin(2*np.pi*50*t))
plt.xlabel('t'); plt.ylabel('Amplitude')
plt.title('Signal Plotting Using Python NumPy and Matplotlib')
plt.xlim(-0.02, 0.05)
plt.show()
```

- `matplotlib` yerine `matplotlib.pyplot` içe aktarılmalıdır. Derste ilk denemedeki hata buydu.
- Ayrık gösterim için `plt.stem` kullanılır.
- Örnek sayısı azaltılınca (ör. 30-40 örnek) sinüs dalgasının biçimi bozulur, faz kayması gibi görünür. Bu, örnekleme teoremine aykırı yetersiz örneklemenin etkisidir.
- Karmaşık sinyal örneği: $x(t)=e^{j100\pi t}=e^{j2\pi50t}$.

```python
t = np.linspace(-0.02, 0.05, 1000)
x = np.exp(2j*np.pi*50*t)

plt.subplot(2,1,1)
plt.plot(t, np.real(x))
plt.title(r'Real part of $x(t)=e^{j100\pi t}$')

plt.subplot(2,1,2)
plt.plot(t, np.imag(x))
plt.title(r'Imaginary part of $x(t)=e^{j100\pi t}$')
plt.show()
```

- Gerçel kısım kosinüs ($t=0$'da 1), sanal kısım sinüstür ($t=0$'da 0). Aralarında $90^\circ$ faz farkı vardır.
- Başlıklarda `$...$` arasına LaTeX yazılabilir.
- Fourier dönüşümünde gerçel giriş verilir, karmaşık çıkış alınır. Bu yüzden `real` ve `imag` fonksiyonları çok kullanılır.
- Yedek kaynakta "Meksika şapkası" (Mexican hat) sinyali gösterildi: Gauss eğrisinin ikinci türevinin negatifi.

### Sistem kavramı ve blok diyagramları

- Sistem, giriş sinyalini çıkış sinyaline dönüştüren bir eşlemedir: $y=S\{x\}$.
  - $Sx$ yazımı çarpma değildir.
- Ders tek girişli tek çıkışlı (SISO) sistemlerle ilgilenir.
- Blok diyagramlarında oklu çizgiler sinyalleri, kutular sistemleri gösterir. Kablo anlamına gelmez.
- Temel sistemler:
  - Ölçekleyici: $y=Ax$. $|A|>1$ yükselteç (amplifier), $0<|A|<1$ zayıflatıcı (attenuator), $A<0$ evirici (inverter). Üçgen veya daire ile çizilir.
  - Türev alıcı: $y=\frac{dx}{dt}$. Hızın türevi ivmedir.
  - İntegratör: $y=\int_{-\infty}^{t}x(\tau)d\tau$.
  - Zamanda öteleme: $y=x(t-t_0)$ (gecikme) veya $x(t+t_0)$ (öngörü).
  - Toplayıcı ve çarpıcı.
  - Konvolüsyon: $y(t)=x(t)*h(t)=\int_{-\infty}^{\infty}x(\tau)h(t-\tau)d\tau$. $*$ işareti çarpma değildir.
- Bağlantılar:
  - Kaskat (seri): $y=G(F(x))$.
  - Paralel: $y=F(x)+G(x)$.
  - Geri besleme: çıkış bir sistemden geçirilip girişten çıkarılır, hata $x-G(y)$ elde edilir.

### İnsan öğrenmesi modeli ve PID

- İntegratör + geri besleme: yaşadıklarımızın hatalarını topluyoruz. Bu birikim tecrübedir.
- Eksik parça türevdir: bugünkü durumu dünküyle karşılaştırmak.
- Kontrol sistemlerindeki PID (oransal, integral, türev) denetleyici bu yapıdadır.
- Aç-kapa (on-off) denetleyici: oda sıcaklığı 20-30 °C arasında salınır (osilasyon). Bu iyi bir yöntem değildir.
- PID ile sistem referansa yaklaşırken hata giderek azalır ve kararlı hale gelir. Örnek: çamaşır makinesinin devrine yavaşça çıkması.

### Doğrusallık

- İki özellik birlikte sağlanmalı:
  - Homojenlik (çarpımsallık): $S\{ax\}=aS\{x\}$.
  - Toplamsallık (süperpozisyon): $S\{x_1+x_2\}=S\{x_1\}+S\{x_2\}$.
- İkisi tek testte birleştirilebilir: $S\{ax_1+bx_2\}=aS\{x_1\}+bS\{x_2\}$.
- Örnek: $y(t)=2x(t)$ doğrusaldır.
- Örnek: $y(t)=2x(t)+5$ doğrusal değildir.
  - $S\{ax\}=2ax+5$, ama $aS\{x\}=2ax+5a$. Eşit değil.
  - Fonksiyon olarak $2x+5$ bir doğru olsa da sistem olarak doğrusal değildir (afin sistem).
- Alıştırma: $y(t)=x^2(t)+5$'in doğrusal olmadığını gösterin.
- Doğrusal sistem örnekleri: ölçekleyici, türev alıcı, integratör, hareketli ortalama (running average), zamanda öteleme, konvolüsyon, modülasyon.
  - Hareketli ortalama: pencere içindeki değerlerin ortalaması alınıp pencere kaydırılır.
- Doğrusal olmayan örnekler: kare alıcı ($y=x^2$), karşılaştırıcılar, nicemleyiciler, uyarlamalı (adaptive) filtreler.
- Modülasyon: sinyal bir taşıyıcı kosinüsle çarpılır, $y(t)=x(t)\cos(\omega_c t)$. Sinyalin frekans bandı kanala uygun banda taşınır.

### Belleklilik ve nedensellik

- Belleksiz sistem: çıkış yalnızca o anki girişe bağlı. Örnek: ideal yükselteç, dişli, kaldıraç.
- Bellekli sistem: çıkış geçmiş veya gelecek girişlere de bağlı. Örnek: $y(t)=x(t)+x(t-1)$; kondansatör, bobin, yay, hareketli kütle.
- Nedensel sistem: çıkış yalnızca şimdiki ve geçmiş girişlere bağlı. Gelecekteki girişe bağlı sistemler gerçek zamanda uygulanamaz, ancak gecikmeyle gerçeklenir.
- Fiziksel devreler ve mekanik sistemler nedenseldir.

### Zamanla değişmezlik

- Algoritma:
  - Girişi geciktirip sisteme verin: $y_1(t)=S\{x(t-t_0)\}$.
  - Sistemin çıkışını geciktirin: $y_2(t)=y(t-t_0)$.
  - $y_1=y_2$ ise sistem zamanla değişmezdir.
- Doğrusal ve zamanla değişmez (LTI) sistemler, dersin geri kalanındaki konuların (özellikle konvolüsyon) temelidir.

### Kararlılık

- BIBO (bounded input bounded output): her $|x(t)|\le M_x<\infty$ girişi için $|y(t)|\le M_y<\infty$ ise sistem kararlıdır.
- Zaman düzleminde test etmek zordur. Frekans veya z-düzleminde daha kolay test edilir.
- Örnek: hız sabitleyici (cruise control). İstenen hız ile ölçülen hız farkı (hata) bir $K$ katsayısıyla çarpılıp gaz ayarlanır: $K(x-y)$.

### Terslenebilirlik

- Sistem ile tersinin kaskat bağlantısı birim (identity) operatörü veriyorsa sistem terslenebilirdir.

### Diferansiyel ve fark denklemleri

- Sürekli zamanlı sistemler diferansiyel denklemlerle tanımlanabilir:
  - $\sum_k a_k\frac{d^k y}{dt^k}=\sum_k b_k\frac{d^k x}{dt^k}$, $a_k$, $b_k$ sabit.
  - En yüksek türevin derecesi sistemin mertebesidir. Başlangıç koşulları $y(0), y'(0),\dots$ olarak verilir.
  - Sabit katsayılı ve başlangıç koşulları sıfır olan sistemler doğrusaldır.
- Örnek: seri RLC devresi, Kirchhoff gerilim yasasından ikinci mertebeden denklem verir.
  - $LC\,\frac{d^2y}{dt^2}+RC\,\frac{dy}{dt}+y=x$
- Örnek: yay-kütle sistemi.
- Ayrık zamanlı sistemler fark denklemleriyle (difference equation) tanımlanır.
  - Örnek: $y[n]=a\,y[n-1]+x[n-1]$ gibi geçmiş değerlere bağlı sistem.
- Bu denklemler ileride dönüşümlerle (Laplace, z) daha kolay çözülecek.

### Ders sonrası notlar

- Hoca "bu üç işlem komütatiftir, işlem önceliği yoktur" dedi. Daha doğrusu: işlemler herhangi bir sırayla yapılabilir, ama öteleme miktarı seçilen sıraya göre değişir.
  - $x(2t+6)$ için önce öteleme yapılırsa 6 birim, önce sıkıştırma yapılırsa 3 birim öteleme gerekir. Bu yüzden işlemler aynı parametrelerle yer değiştirilemez.
- Doğrusallık testinde derste $f(at)$ ile $a f(t)$ karşılaştırıldı. Bu, girişi değil zamanı ölçekler. Doğru test girişi ölçekler: $S\{a\,x(t)\}$ ile $a\,S\{x(t)\}$ karşılaştırılır.
  - $y=2x+5$ için sonuç değişmez: sistem doğrusal değildir.
- Zamanla değişmezlik örneğinde ($y=2t$ gibi yazıldı) hangi sistemin kastedildiği kayıtta net değil.
  - $y(t)=2x(t)$ zamanla değişmezdir: $S\{x(t-t_0)\}=2x(t-t_0)=y(t-t_0)$.
  - $y(t)=x(2t)$ zamanla değişendir: $S\{x(t-t_0)\}=x(2t-t_0)$, ama $y(t-t_0)=x(2t-2t_0)$.
  - Derste bulunan $2t-2t_0$ ile $2t-t_0$ farkı ikinci sisteme karşılık gelir.
- Nicemleme adımı $40/2^{16}\approx0.00061$ V'tur (Python ile doğrulandı). Derste "0.006 herhalde" diye geçti; büyüklük mertebesine dikkat edin. Bazı kaynaklar en büyük nicemleme hatasını $\Delta/2\approx0.0003$ V olarak verir.
- Modülasyon için derste "kablolar bu aralıkta çalışmaz, daha küçük aralığa çevrilir" dendi. Modülasyon sinyali genelde taşıyıcı frekansı çevresindeki daha yüksek bir banda taşır. Amaç bandı kanala uygun hale getirmektir.
- Modülatör $y(t)=x(t)\cos(\omega_c t)$ doğrusaldır ama zamanla değişendir.
- Gözü yüzde arama örneği teknik olarak korelasyondur. Konvolüsyonda kayan sinyal ters çevrilir, korelasyonda çevrilmez.
- Meksika şapkası, Gauss eğrisinin ikinci türevinin negatifidir (Ricker dalgacığı). Derste yalnızca "ikinci türevi" dendi.
- Hız sabitleyici örneğinde "aslında türev alıyoruz" dendi. Şekildeki yapı hata ile orantılı (oransal, P) bir denetleyicidir.
- Kayıtta quiz sorusunun 1000 Hz örnekleme şıkkı tam okunamıyor. Doğru ayrık ifade $x[n]=100\sin(\pi n/2+\pi/2)$'dir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
