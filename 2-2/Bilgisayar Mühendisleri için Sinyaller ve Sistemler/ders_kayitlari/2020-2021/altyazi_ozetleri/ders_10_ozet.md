# Ders 10 Çalışma Özeti

## Genel Konular

- Dersin tarihi 25 Ağustos 2021 Çarşamba (yaz okulu). Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:04'te başlar. Kaydın başı bekleme kısmıdır.
  - Ders üç bölümden oluşur: ödev açıklaması, vize sorularının çözümü, yeni konu (ayrık zamanlı Fourier).
- Ödev açıklaması: Fourier sentezi
  - Ödev analiz değil, sentez üzerine. Tabloda bir sesin (A sesi) 17 frekans bileşeni için faz, $a_k$ katsayısı ve genlik verilmiş.
  - Bileşenler kosinüs olarak toplanınca dalga formu oluşur. Örnekleme frekansı 20 000 Hz.
- Vize sorularının çözümü
  - S1: ayrık ve sürekli işaretlerin çarpımı ve grafikleri.
  - S2: ayrık konvolüsyon ve sıfır noktasının bulunması.
  - S3: birim darbe gösterimi, işaret çarpımı, tek ve çift bileşenler, enerji.
  - S4: kare dalganın Fourier serisi ve frekans spektrumu.
- MATLAB ile Fourier sentezi
  - Kare dalga, tek harmoniklerin toplanmasıyla yeniden elde edildi. Harmonik sayısı arttıkça kare dalgaya yaklaşıldı (Gibbs olayı).
  - `sound` komutu ile işaretin seslendirilmesi gösterildi. İşitme testi (farklı frekanslarda sinüs sesleri) yapıldı.
- DFT ve FFT
  - Ayrık Fourier dönüşümü (DFT) ve hızlı Fourier dönüşümü (FFT).
  - MATLAB'de `fft` ve `fftshift` ile sentezlenen kare dalganın spektrumu çizildi.
- Ayrık zamanlı Fourier serisi ve ayrık zamanlı Fourier dönüşümü (DTFT)
  - Periyodik ayrık işaret için $c_k$ katsayıları.
  - Periyodik olmayan ayrık işaret için DTFT ve ters dönüşümü.
  - Örnekler: $x[n]=[0,1,2,3]$ ($N_0=4$) için Fourier katsayıları, $\delta[n]$ ve $a^n u[n]$ işaretlerinin DTFT'si.
  - DTFT özellikleri: zamanda öteleme, frekansta öteleme, doğrusallık, konvolüsyon.
- Laplace ve Z dönüşümüne giriş
  - Fourier dönüşümü yakınsamayan işaretler için Laplace (sürekli) ve Z dönüşümü (ayrık) kullanılır.
- Ders sonunda not durumu, quiz ve final hakkında bilgi verildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ayrık bir işaret sürekli çizilirse cevap yanlıştır.
  - Vizedeki S1a'da sürekli çizgi çizenler çok düşük puan aldı.
- Konvolüsyonda sınırlar ve sıfır noktası doğru bulunmalı.
  - Puan kaybı çoğunlukla burada oldu.
- Birim darbe (unit impulse) ile birim basamak (unit step) farklıdır.
  - Soruda birim darbe cinsinden yazılması istendi. Birim basamakla yazanlar puan kaybetti.
- Tek ve çift bileşen hesabında $x[n]$ ile $x[-n]$ aynı indisler üzerinden toplanmalı.
  - Uç değerleri (ör. 6 ile -1) birbiriyle toplamak yaygın hataydı.
- Soruda istenen işaretin enerjisi hesaplanmalı.
  - $y[n]$ yerine $x[n]$'in enerjisini hesaplayanlar tam puan alamadı.
- Ayrık işaretler MATLAB'de `plot` ile değil `stem` ile çizilmeli.
- `plot(y)` yazınca yatay eksen örnek numarası olur. Zamana göre çizmek için `plot(t, y)` yazılmalı.
- Bu dersin konuları makine öğrenmesi, görüntü işleme ve ses işleme için temeldir.
  - Hoca, konvolüsyon gibi işlemleri bilmeden hazır kod kullanmanın akademik çalışmada sorun çıkardığını söyledi.
- Sınavda hız için pratik gerekir.
  - Hoca kendinize bir formül kağıdı hazırlamanızı önerdi. Euler formülü de işe yarar.
- Final konuları (Laplace, Z dönüşümü, Fourier özellikleri) problemleri daha kolay çözdüren konulardır.

## Kısa Tekrar Notları

- Ayrık konvolüsyonda sonucun başlangıç indisi, iki işaretin başlangıç indislerinin toplamıdır.
- Çift bileşen: $x_e[n]=\frac{x[n]+x[-n]}{2}$. Tek bileşen: $x_o[n]=\frac{x[n]-x[-n]}{2}$.
- Ayrık işaretin enerjisi: $E=\sum_{n=-\infty}^{\infty}|x[n]|^2$.
- Sürekli Fourier serisi: $c_k=\frac{1}{T_0}\int_{T_0}x(t)e^{-jk\omega_0 t}dt$, $\omega_0=\frac{2\pi}{T_0}$.
- Gerçel işaret için $a_k=2\,\mathrm{Re}(c_k)$, $b_k=-2\,\mathrm{Im}(c_k)$.
- $e^{jk\pi}=(-1)^k$.
- DFT karmaşıklığı $O(N^2)$, FFT karmaşıklığı $O(N\log N)$.
- Ayrık Fourier serisi: $c_k=\frac{1}{N_0}\sum_{n=0}^{N_0-1}x[n]e^{-jk\Omega_0 n}$, $\Omega_0=\frac{2\pi}{N_0}$.
- DTFT: $X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]e^{-j\Omega n}$.
- Ters DTFT: $x[n]=\frac{1}{2\pi}\int_{2\pi}X(\Omega)e^{j\Omega n}d\Omega$.
- $\delta[n]\leftrightarrow 1$.
- $a^n u[n]\leftrightarrow \frac{1}{1-ae^{-j\Omega}}$, şart: $|a|<1$.
- Zamanda öteleme: $x[n-n_0]\leftrightarrow e^{-j\Omega n_0}X(\Omega)$.
- Frekansta öteleme: $e^{j\Omega_0 n}x[n]\leftrightarrow X(\Omega-\Omega_0)$.
- Zamanda konvolüsyon, frekansta çarpmaya karşılık gelir. Zamanda çarpma, frekansta konvolüsyona karşılık gelir.

## Detaylı Açıklamalar

### Ödev: Fourier sentezi

- Fourier analizinde işaretin kosinüs ve sinüs bileşenleri ($a_k$ katsayıları) bulunur. Sentezde ise bu bileşenler toplanarak işaret yeniden oluşturulur.
- Ödevdeki tabloda 17 frekans bileşeni var. Bazı frekanslarda $a_k=0$; bu, o frekans bileşeninin olmadığı anlamına gelir.
- Bileşenler tek tek eklendikçe dalga formu değişir. Bütün bileşenler toplanınca A sesine karşılık gelen dalga elde edilir.
- Örnekleme frekansı 20 000 Hz seçilebilir.
- Dalga formu tablodaki değerlerle uyuşmuyorsa sinüzoid denklemi yanlış kurulmuştur.
- Ödevde tek bir rapor gönderilir. Ses dosyası istenmez.
  - Kodda `sound` komutunu kullanmak zorunlu değildir. Sesi duymak isteyen kullanabilir.
- Döngü (`for`) kullanmak zorunlu değildir. Bileşen sayısı az olduğu için ayrı değişkenlerle de yazılabilir.

### Vize S1: işaretlerin grafiği

- Soru: a) $x[n]=(3-n)\,(u[n]-u[n-3])$. b) $y(t)=v(t)\,[u(t)-u(t-1)]+v(t)\,\delta(t+1)$.
- a maddesi:
  - $u[n]-u[n-3]$ yalnızca $n=0,1,2$ için 1'dir.
  - $3-n$ bu noktalarda 3, 2, 1 değerini alır.
  - Sonuç: $x[n]=3\delta[n]+2\delta[n-1]+\delta[n-2]$. Grafik ayrık (stem) çizilmeli.
- b maddesi:
  - $\alpha(t)=u(t)-u(t-1)$, $[0,1)$ aralığında 1'dir. $t=1$ noktası dahil değildir (açık nokta).
  - $v(t)\,\alpha(t)$, $v(t)$'nin $[0,1)$ aralığındaki değerlerini korur. Grafikte bu aralıkta $v(t)=3$.
  - $v(t)\,\delta(t+1)=v(-1)\,\delta(t+1)$. Grafikte $v(-1)=0$ olduğu için bu terim sıfırdır.
  - Sonuç: $y(t)$, $[0,1)$ aralığında 3, diğer yerlerde 0.

### Vize S2: ayrık konvolüsyon

- $x[n]=[2,\underline{3},2,1]$ ($n=-1$'den $2$'ye), $h[n]=[2,-1,\underline{1},-2]$ ($n=-2$'den $1$'e). Altı çizili değer $n=0$ noktasıdır.
- Sonucun indis aralığı: $-1+(-2)=-3$'ten $2+1=3$'e.
- Ters çevir, kaydır, çarp, topla yöntemiyle:

| $n$ | -3 | -2 | -1 | 0 | 1 | 2 | 3 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| $y[n]$ | 4 | 4 | 3 | -1 | -5 | -3 | -2 |

- Sıfır noktasını bulmanın en kolay yolu: başlangıç indisinden ($-3$) saymak. Böylece dördüncü değer ($-1$) $n=0$'dır.
- Diğer yol: iki işaretin sıfır noktalarının çarpıldığı adım, sonucun sıfır noktasını verir.
- İşaretler birim darbe cinsinden yazılarak da çözülebilir.

### Vize S3: birim darbe gösterimi, tek-çift bileşenler, enerji

- $x[n]=[-1,2,0,\underline{3},-7,6]$, yani $n=-3$'ten $2$'ye.
- a) Birim darbe cinsinden:
  - $x[n]=-\delta[n+3]+2\delta[n+2]+3\delta[n]-7\delta[n-1]+6\delta[n-2]$.
  - Genliği sıfır olan $\delta[n+1]$ terimini yazmaya gerek yok.
- b) $y[n]=x[n]\,(u[n]-u[n+2])$:
  - $u[n]-u[n+2]$, $n=-2$ ve $n=-1$'de $-1$, diğer yerlerde 0'dır.
  - Çarpım: $y[-2]=2\cdot(-1)=-2$, $y[-1]=0\cdot(-1)=0$.
  - Sonuç: $y[n]=-2\delta[n+2]$.
  - Yaygın hata: genliği $+2$ yazmak. Çarpım vektörel (eleman eleman) olduğu için işaret $-2$ olur.
- c) Tek ve çift bileşenler:
  - $x[-n]=[6,-7,\underline{3},0,2,-1]$, yani $n=-2$'den $3$'e. İndis aralığı $-3$'ten $3$'e genişler.
  - $x_e[n]=[-\tfrac12,\ 4,\ -\tfrac72,\ \underline{3},\ -\tfrac72,\ 4,\ -\tfrac12]$.
  - $x_o[n]=[-\tfrac12,\ -2,\ \tfrac72,\ \underline{0},\ -\tfrac72,\ 2,\ \tfrac12]$.
  - Kontrol: $x_e[n]+x_o[n]=x[n]$.
- d) Enerji:
  - $E_y=\sum|y[n]|^2=(-2)^2=4$ J.

### Vize S4: kare dalganın Fourier serisi

- İşaret: periyot $T_0=4$ s. $0<t<2$ aralığında $-1$, $2<t<4$ aralığında $4$.
- Temel frekans: $f_0=\frac{1}{4}=0.25$ Hz, $\omega_0=\frac{2\pi}{T_0}=\frac{\pi}{2}$ rad/s.
- DC bileşen:
  - $a_0=\frac{1}{4}\left[\int_0^2(-1)dt+\int_2^4 4\,dt\right]=\frac{1}{4}(-2+8)=\frac{3}{2}$.
- $c_k$ katsayıları:
  - $c_k=\frac{1}{4}\left[\int_0^2 -e^{-jk\frac{\pi}{2}t}dt+\int_2^4 4e^{-jk\frac{\pi}{2}t}dt\right]$.
  - $e^{-jk2\pi}=1$ ve $e^{-jk\pi}=(-1)^k$ kullanılınca: $c_k=\frac{5j}{2k\pi}\left(1-(-1)^k\right)$.
  - Çift $k$ için ($k\neq0$) $c_k=0$. Tek $k$ için $c_k=\frac{5j}{k\pi}$.
  - İşaretin DC dışındaki kısmı tek fonksiyon olduğu için kosinüs bileşeni yoktur.
- $a_k$ ve $b_k$:
  - $a_k=2\,\mathrm{Re}(c_k)=0$.
  - $b_k=-2\,\mathrm{Im}(c_k)=-\frac{10}{k\pi}$ (tek $k$ için).
- Spektrum:
  - $f=\pm0.25,\ \pm0.5,\ \pm0.75$ Hz noktalarına bakılır.
  - $|c_{\pm1}|=\frac{5}{\pi}$, $c_{\pm2}=0$, $|c_{\pm3}|=\frac{5}{3\pi}$. Frekans arttıkça genlik azalır.

### MATLAB ile kare dalganın sentezi

- Kare dalga, DC bileşen ve tek harmoniklerin toplamıdır:
  - $x(t)=\frac{3}{2}+\sum_{k\ \text{tek}}\frac{10}{k\pi}\cos\left(2\pi k f_0 t+\frac{\pi}{2}\right)$.
  - $\cos(\theta+\frac{\pi}{2})=-\sin\theta$ olduğu için bu ifade $b_k\sin(k\omega_0 t)$ toplamına eşittir.
- Dersteki koda benzer bir sürüm:

```matlab
clear; clc;
f  = 0.25;          % temel frekans
fs = 100;           % örnekleme frekansı
t  = 0:1/fs:5-1/fs;
y  = 3/2;           % DC bileşen
for v = 1:2:15      % yalnızca tek harmonikler
    x = 10/(v*pi) * cos(2*pi*f*v*t + pi/2);
    y = y + x;
end
plot(t, y)          % plot(y) yazılırsa yatay eksen örnek numarası olur
```

- Harmonik sayısı 5'ten 15'e, sonra 155'e çıkarıldı. Sonuç kare dalgaya çok yaklaştı. Köşelerdeki salınımlar Gibbs olayıdır.
- Sentezle elde edilen dalganın orijinal işarete benzemesi, analizin doğru yapıldığını gösterir.
- Uygulama alanı: ses tanıma, biyometri, duygu ve yorgunluk analizi. Frekans ve genlik bilgisi ayırt edici özellik (feature) olarak kullanılır.

### Sesle deneme ve işitme testi

- `sound(y)` veya `sound(y, fs)` bir vektörü sese dönüştürür. Örnekleme frekansı verilmezse varsayılan değer kullanılır. 22 050 veya 44 100 Hz verilebilir.
- MATLAB Online, tarayıcı izin vermediği için derste ses çalmadı. Hoca bunu kendi bilgisayarınızda denemenizi söyledi.
- Derste farklı frekanslarda sinüs sesleri dinletilerek işitme testi yapıldı. Odyometri testleri de bu mantıkla çalışır.
- İki kosinüs toplanarak bir nota sentezlenebilir. Hoca 1047 Hz (C6 notası) örneğini verdi.

### DFT ve FFT

- Şimdiye kadar Fourier serisi ve dönüşümü sürekli işaretlerde çalışıldı. Bilgisayarda ise veriler ayrıktır.
- DFT (Discrete Fourier Transform), Fourier dönüşümünün algoritmik karşılığıdır. Karmaşıklığı $O(N^2)$'dir.
- FFT (Fast Fourier Transform), DFT'yi $O(N\log N)$ işlemle hesaplar. Detayları sayısal işaret işleme dersinde anlatılır.
- MATLAB demosu:
  - Sentezlenen işaretin `fft` ile spektrumu alındı. DC ve 1, 3, 5. harmonikler olmak üzere 4 tepe görüldü.
  - `fftshift` ile pozitif ve negatif frekanslar ortalanarak çizildi.
  - 75. harmoniğe kadar sentez yapılınca son tepe yaklaşık $75\times0.25=18.75$ Hz'de görüldü.

### Ayrık zamanlı Fourier serisi

- Periyodik ayrık işarette temel periyot $N_0$ bulunur. Katsayılar bir periyot üzerinden toplanarak hesaplanır.
- Örnek: $x[n]=[0,1,2,3]$, $N_0=4$, $\Omega_0=\frac{\pi}{2}$.
  - $e^{-j\frac{\pi}{2}kn}=(-j)^{kn}$ yazılırsa hesap kolaylaşır.
  - $c_0=\frac{0+1+2+3}{4}=\frac{3}{2}$. Bu, bir periyottaki ortalamadır.
  - $c_1=-\frac12+\frac{j}{2}$.
  - $c_2=-\frac12$. Bu katsayıda sanal kısım yoktur.
  - $c_3=-\frac12-\frac{j}{2}$.
- Hoca çalışma için şunu önerdi: $x[n]=[1,1,1,1,1,0,0,0,0,0]$ periyodik işaretinin Fourier katsayılarını bulun.

### Ayrık zamanlı Fourier dönüşümü (DTFT)

- Periyodik olmayan ayrık işaret için kullanılır. Kaynaklarda DTFT, Türkçe kaynaklarda AZFD olarak geçer.
- Ayrık işaretin DTFT'si $\Omega$'ya göre sürekli ve $2\pi$ periyotlu bir fonksiyondur. Bu yüzden ters dönüşüm integralle yapılır.
- Örnek 1: $x[n]=\delta[n]$.
  - Toplamda yalnızca $n=0$ terimi kalır: $X(\Omega)=1$.
- Örnek 2: $x[n]=a^n u[n]$.
  - $u[n]$ yüzünden toplam $n=0$'dan başlar: $X(\Omega)=\sum_{n=0}^{\infty}(ae^{-j\Omega})^n$.
  - Geometrik seri formülü: $\sum_{n=0}^{\infty}r^n=\frac{1}{1-r}$, şart: $|r|<1$.
  - Sonuç: $X(\Omega)=\frac{1}{1-ae^{-j\Omega}}$, şart: $|a|<1$.
  - $|a|\geq1$ ise seri ıraksar ve DTFT yoktur.
- DTFT özellikleri, sürekli Fourier dönüşümündekilerle aynı mantıktadır:
  - Zamanda öteleme, frekansta öteleme, doğrusallık, ölçekleme.
  - Konvolüsyon: $x_1[n]*x_2[n]\leftrightarrow X_1(\Omega)X_2(\Omega)$.
- Fark denklemleri de DTFT ile çözülebilir. Hoca bunu bir sonraki derste göstereceğini söyledi.

### Laplace ve Z dönüşümüne geçiş

- Fourier dönüşümü yalnızca belli şartlarda (yakınsama varsa) alınabilir.
- İşaret sonsuza gidiyorsa (ıraksama, divergence):
  - Sürekli işaretlerde Laplace dönüşümü kullanılır: $\int f(t)e^{-st}dt$.
  - Ayrık işaretlerde Z dönüşümü kullanılır.
- $e^{-st}$ çarpanı işaretin sonsuza gitmesini engeller. Bu yüzden Laplace ve Z dönüşümleri Fourier dönüşümünün daha genel halidir.

### Sınav ve ders duyuruları

- Vizeye 50 kayıtlı öğrenciden 38'i katıldı. Ortalama fena değil.
- Vize itirazları için cumartesi günü talepte bulunulacak. Hoca e-posta veya ders sonrası görüşme istedi.
- Cumartesi öğleden sonra bir quiz var.
  - Kapsam: Fourier serileri, Fourier dönüşümü ve konvolüsyon. 6 soru hazırlandı.
- Dördüncü quiz test yerine iki-üç saatlik basit bir kodlama ödevi olabilir. Hoca henüz karar vermedi.
- İkinci ödev bu hafta gelecek. Konusu DTFT: basit bir örnek üzerinde analitik çözüm ve ters dönüşüm.
- Finalde 4 veya 5 soru olacak.
  - Hoca sınav kağıdına formül yazmıyor. Kendinize formül kağıdı hazırlayın.
- Yaz okulunda bütünleme yok.
- Hoca, USİS'e not girişi yapılamadığını ve USİS'in yerine yeni bir sistem geleceğini duyduğunu söyledi.
- Örnek sorular Google Drive'daki klasörde var. Örnekleme (sampling) ve filtre soruları bu dersin kapsamı dışında.

### Ders sonrası notlar

- Hoca S3a'da birim darbe ifadesini söylerken "$n-3$", "$n-2$" dedi ve sonra düzeltmeye çalıştı. Sıfır noktasından önceki örnekler (sola) $\delta[n+3]$, $\delta[n+2]$ şeklinde yazılır. Doğru ifade: $x[n]=-\delta[n+3]+2\delta[n+2]+3\delta[n]-7\delta[n-1]+6\delta[n-2]$.
- Hoca enerji formülünü önce "$n=0$'dan sonsuza" diye söyledi. Doğru tanımda toplam $-\infty$'dan $+\infty$'a alınır. Hoca hesapta da bunu kullandı.
- S4'te hoca "$\omega_0=2\pi/f_0$" dedi. Doğrusu $\omega_0=2\pi f_0=2\pi/T_0$. Hesaptaki $\pi/2$ değeri doğrudur.
- S4'te $c_k$ katsayısı saf sanaldır: tek $k$ için $c_k=\frac{5j}{k\pi}$. Derste spektrumda $\mp\frac{5}{\pi}$ gibi gerçel değerler çizildi. Genlik spektrumu için $|c_k|=\frac{5}{k\pi}$ çizilmelidir.
- S4'te hoca $b_k$ için "$-\frac{5}{k\pi}$" dedi. $b_k=-2\,\mathrm{Im}(c_k)$ formülüne göre doğrusu $b_k=-\frac{10}{k\pi}$'dir. Hoca MATLAB sentezinde doğru genliği ($\frac{10}{k\pi}$) kullandı.
- S4 sonuçları Python ile sayısal integral alınarak doğrulandı: $c_0=1.5$, $c_{\pm1}=\pm1.5915j$, $c_{\pm2}=0$, $c_{\pm3}=\pm0.5305j$.
- S2'nin konvolüsyon sonucu Python (`numpy.convolve`) ile doğrulandı: $[4,4,3,-1,-5,-3,-2]$.
- Ayrık Fourier serisi örneği ($x[n]=[0,1,2,3]$) Python ile doğrulandı: $c_0=1.5$, $c_1=-0.5+0.5j$, $c_2=-0.5$, $c_3=-0.5-0.5j$.
- $a^n u[n]$ örneğinde hoca grafik için $a=2$ seçti ve üstel artan bir işaret çizdi. Bu işaretin DTFT'si yoktur, çünkü şart $|a|<1$'dir. Grafiği $0<a<1$ için düşünmek gerekir (üstel azalan).
- Hoca $\Omega$ arttıkça $|X(\Omega)|$'nın sıfıra gittiğini söyledi. Bu doğru değildir. $|e^{-j\Omega}|=1$ olduğu için $X(\Omega)$, $2\pi$ periyotlu bir fonksiyondur. $0<a<1$ için genlik $\Omega=0$'da en büyük ($\frac{1}{1-a}$), $\Omega=\pi$'de en küçüktür ($\frac{1}{1+a}$).
- Hoca FFT demosunda "FFT olduğu için kayıp var, DFT olsa daha doğru olurdu" dedi. FFT, DFT ile aynı sonucu verir; yalnızca daha hızlıdır. Tepe konumundaki küçük sapma, frekans çözünürlüğünden (örnek sayısına bağlı bin aralığından) kaynaklanır.
- Hoca DFT maliyetini anlatırken 4 dakikalık CD kalitesinde müzik için "240 milyon örnek" dedi. Doğru hesap: $4\times60\times44\,100\approx10.6$ milyon örnek (tek kanal). Ana fikir değişmez: $N^2$ işlem çok büyüktür.
- Altyazıdaki "Şans'ın kitabı" büyük ihtimalle Schaum serisi (Hsu, *Signals and Systems*) kitabıdır.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
