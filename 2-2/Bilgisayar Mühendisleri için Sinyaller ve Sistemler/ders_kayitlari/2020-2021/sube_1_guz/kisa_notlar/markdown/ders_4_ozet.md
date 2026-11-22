# Ders 4 Çalışma Özeti

## Genel Konular

- İşaret işlemlerinin tekrarı
  - Sürekli işaretler zamanın fonksiyonudur ve normal parantezle ($x(t)$), ayrık işaretler tam sayı indislerin fonksiyonudur ve köşeli parantezle ($x[n]$) yazılır. Ayrıklaştırmanın iki adımı vardır: zamanda ayrıklaştırma (örnekleme, sampling) ve genlik seviyelerinin ayrıklaştırılması (nicemleme, quantization).
  - Sistem, giriş işaretini ($x(t)$ ya da $x[n]$) alıp bir çıkış işaretine dönüştüren yapıdır ve $T[\cdot]$ (transform) ile gösterilir.
  - Genlik ölçekleme: işaret bir skalerle çarpılır, her noktadaki değer o oranda değişir.
  - Zamanda ölçekleme $x(at)$: $a>1$ ise işaret sıkışır (compress), $0<a<1$ ise yayılır. Ayrık zamanda $x[2n]$ her ikinci örneği alır; buna alt örnekleme, azaltım (downsampling, decimation) denir. $x[n/2]$ ise ara örnekleri tanımsız bırakır; bunlara 0 ya da komşu örneklerin ara değeri konur (üst örnekleme, interpolasyon) (ekrandan, 00:10:00).
  - Zamanda ters çevirme $x(-t)$, $x[-n]$: işaret düşey eksene göre yansır.
  - Zamanda öteleme: $n_1>0$ için $x[n-n_1]$ gecikmiş (delayed), $x[n+n_1]$ ilerlemiş (advanced) işarettir. Öteleme miktarı tam sayı örnek sayısıdır (ekrandan, 00:15:00).
- İşlem sırası
  - Ölçekleme, öteleme ve ters çevirme birleştirilebilir ama uygulama sırası sonucu değiştirir.
  - $x(2(t-1))$ örneği: önce 2 ile sıkıştırıp sonra 1 ötelemek doğrudur. Önce ötelemek isteniyorsa ifade $x(2t-2)$ diye açılır, önce 2 ötelenir, sonra 2 ile sıkıştırılır. Önce 1 öteleyip sonra 2 ile sıkıştırmak yanlış sonuç verir (ekrandan, 00:25:00 ve 00:30:00).
  - Emin olmak için argümana değer koyarak kontrol edilir: $t=0 \to x(-2)$, $t=1 \to x(0)$, $t=2 \to x(2)$, $t=3/4 \to x(-1/2)$.
- Periyodik işaretler
  - $x(t+T_0)=x(t)$; genel olarak her $k$ tam sayısı için $x(t+kT_0)=x(t)$. Örnekte periyodu 1 olan işaret 1 birim ötelenince aynı kalır (ekrandan, 00:20:00). En bilinen periyodik işaretler sinüs ve kosinüstür.
- Karmaşık sayılar
  - Kartezyen gösterim $z=a+jb$ (mühendislikte $j$, fizikte $i$ kullanılır), kutupsal gösterim $z=re^{j\theta}$; $r=\sqrt{a^2+b^2}$ modül (genlik), $\theta=\arctan(b/a)$ açı (faz) (ekrandan, 00:35:00).
  - Euler eşitliği: $e^{jx}=\cos x + j\sin x$. Buradan $e^{z}=e^{x+jy}=e^{x}(\cos y + j\sin y)$.
  - Haberleşme, radar, sonar ve ultrason gibi alanlarda işaretler karmaşık olarak ifade edilir.
- İşaretin enerjisi ve gücü
  - Dirençte harcanan enerji $E_R=\lim_{T\to\infty}\int_{-T}^{T} i^2(t)R\,dt$ (Joule). İşaret enerjisi $1\,\Omega$'luk direnç için tanımlanır: $E_x=\lim_{T\to\infty}\int_{-T}^{T}|x(t)|^2dt$ (ekrandan, 00:40:00).
  - Bu çoğu uygulamada gerçek bir fiziksel enerji değildir, tanımsaldır. Karmaşık işarette genliğin karesi $|x(t)|^2$ kullanılır.
  - Güç, enerjinin zamandaki ortalamasıdır: $P_x=\lim_{T\to\infty}\frac{1}{2T}\int_{-T}^{T}|x(t)|^2dt$.
  - Enerji işaretinin ($E_x<\infty$) gücü sıfırdır; güç işaretinin ($P_x>0$) enerjisi sonsuzdur (ekrandan, 00:45:00).
- Sinüzoidal işaretler
  - $x(t)=A\cos(\omega t+\theta)=A\cos(2\pi f t+\theta)$. $f$ Hertz cinsinden frekans, $\omega=2\pi f$ radyan frekans (rad/s), $\theta$ faz açısıdır (ekrandan, 00:50:00).
  - Periyot $T=1/f=2\pi/\omega$ saniyedir. Faz işareti sağa ya da sola öteler.
  - Ayrık zamanda $t \to nT_s$ konur: $x[n]=A\cos(\omega nT_s+\theta)=A\cos\left(\frac{\omega}{f_s}n+\theta\right)$. $\Omega=\omega T_s=\omega/f_s$ sayısal frekanstır (ekrandan, 00:55:00).
  - Analog frekans küçük $\omega$, sayısal frekans büyük $\Omega$ ile gösterilir.
- Karmaşık sinüzoitler
  - $Ae^{j(\omega t+\theta)}=A\cos(\omega t+\theta)+jA\sin(\omega t+\theta)$. Gerçel sinüzoit karmaşık sinüzoidin gerçel kısmıdır: $\Re\{Ae^{j(\omega t+\theta)}\}=A\cos(\omega t+\theta)$ (ekrandan, 01:10:00).
- Üstel işaretler
  - $x(t)=e^{\sigma t}$: $\sigma<0$ ise üstel azalma (decay, zayıflama), $\sigma>0$ ise üstel büyüme (growth). $e^{-t}$ $t=0$'da 1, $t=1$'de $1/e$ değerini alır, $+\infty$'da sıfıra gider (ekrandan, 01:15:00).
  - Sönümlü ya da büyüyen sinüzoit: $x(t)=e^{\sigma t}\cos(\omega t+\theta)$. Üstel çarpan sinüzoidin zarfını belirler (ekrandan, 01:20:00).
  - Karmaşık üstel işaret: $e^{(\sigma+j\omega)t+j\theta}=e^{\sigma t}\left(\cos(\omega t+\theta)+j\sin(\omega t+\theta)\right)$. Üstel büyüme ya da azalmanın karmaşık sinüzoitle modüle edilmesidir; önceki bütün işaretleri özel durum olarak içerir (ekrandan, 01:25:00).
  - $s=\sigma+j\omega$ karmaşık frekanstır. $\sigma>0$ (düzlemin sağı) artan, $\sigma<0$ (düzlemin solu) azalan salınımlar verir.
- Sayı kümeleri (ara konu)
  - Doğal sayılar, tam sayılar, rasyonel ve irrasyonel sayılar, hepsini kapsayan gerçel sayılar. Rasyonel sayı iki tam sayının oranı olarak yazılabilir; irrasyonel sayı yazılamaz ($\pi$, $\sqrt{2}$). $22/7$ $\pi$'nin yalnız yaklaşığıdır.
- Temel işaretler
  - Birim basamak: $u(t)=1$ ($t\ge 0$), $0$ ($t<0$); Heaviside basamak fonksiyonu da denir. Ayrık hali $u[n]$. Başka işaretleri tanımlamada kullanılır: $e^{-t}u(t)$ işaretin yalnız $t\ge0$ kısmını bırakır.
  - Ötelenmiş dikdörtgen: $x(t)=u(t)-u(t-1)$, yani $0\le t<1$ aralığında 1 (ekrandan, 01:45:00).
  - Birim dikdörtgen: $|t|<1/2$ için 1, alanı 1.
  - Birim rampa: $r(t)=t$ ($t\ge0$), $0$ ($t<0$); birim basamağın integralidir: $r(t)=\int_{-\infty}^{t}u(\tau)d\tau$.
  - Birim üçgen: $\Delta(t)=1-|t|$ ($|t|<1$), aksi halde 0; alanı $2\cdot 1/2=1$ (ekrandan, 01:50:00).
  - Doppler RF darbe dizisi: zarf $\sum_{n=-2}^{2}A\,\mathrm{rect}\left((t-nT)/\tau\right)$, beş ötelenmiş dikdörtgen kopyadan oluşur; sonra $\cos(\omega t)$ RF taşıyıcısıyla çarpılır (ekrandan, 01:55:00).
- Birim dürtü (impuls, delta, Dirac) fonksiyonu
  - Genişliği $\epsilon$, yüksekliği $1/\epsilon$ olan ve $\epsilon\to0$ giden darbe gibi düşünülür; $t=0$ dışında sıfırdır ve alanı 1'dir.
  - $\int_{-\infty}^{\infty}f(t)\delta(t)dt=f(0)$, $\int f(t)\alpha\delta(t)dt=\alpha f(0)$, $f(t)\delta(t)=f(0)\delta(t)$.
  - Kaydırma (sifting) özelliği: $\int_{-\infty}^{\infty}f(t)\delta(t-T)dt=f(T)$; örneklemeyi modellemede önemlidir (ekrandan, 02:10:00).
  - İntegral sınırları: $a<0<b$ ise $\int_a^b\delta(t)dt=1$; $a>0$ ya da $b<0$ ise 0. Örn. $\int_{0^+}^{1}\delta=0$, $\int_{0^-}^{1}\delta=1$, $\int_{-1}^{0^-}\delta=0$, $\int_{-1}^{0^+}\delta=1$ (ekrandan, 02:15:00).
  - Süreksiz fonksiyonun türevi her sıçramada bir dürtü içerir; $u(t)$'nin türevi $\delta(t)$'dir (ekrandan, 02:20:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sürekli işaret normal parantezle, ayrık işaret köşeli parantezle yazılır; ders boyunca bu ayrıma dikkat edilmeli.
- Ölçekleme, öteleme ve ters çevirme işlemleri sıra bağımlıdır
  - Yanlış sırayla uygulanan işlem farklı bir işaret verir. Şüphede argümana değer koyarak kontrol edilmelidir.
- Euler eşitliği ders boyunca sürekli kullanılacak
  - $e^{jx}=\cos x + j\sin x$ iyice öğrenilmeli; karmaşık sinüzoit ve karmaşık üstel işaretin temelidir.
- Enerji ve güç tanımları tanımsaldır; enerji işaretinin gücü sıfır, güç işaretinin enerjisi sonsuzdur. Bu tanımları bilmek yeterlidir.
- Analog ve sayısal frekans ayrı sembollerle yazılmalı ($\omega$ ve $\Omega$).
- İşaret ve sistemler mühendislik açısından önemli bir derstir
  - Makine öğrenmesi, derin öğrenme ve değişkenlerin zamanla değiştiği her yerde karşılaşılır. Konular her hafta basit görünse de üst üste eklendiği için düzenli takip edilmeli.
- Dürtü fonksiyonu çok kullanılacak; kaydırma özelliği ileride örneklemenin modellenmesinde kullanılacak.

## Kısa Tekrar Notları

- $x(at)$: $a>1$ sıkışma (ayrıkta decimation), $0<a<1$ yayılma (ayrıkta interpolasyon).
- $x[n-n_1]$ gecikmiş, $x[n+n_1]$ ilerlemiş işaret ($n_1>0$).
- $x(2(t-1))=x(2t-2)$: önce 2 ile sıkıştır, sonra 1 ötele; ya da önce 2 ötele, sonra 2 ile sıkıştır.
- $z=a+jb=re^{j\theta}$, $r=\sqrt{a^2+b^2}$, $\theta=\arctan(b/a)$.
- $E_x=\int_{-\infty}^{\infty}|x(t)|^2dt$, $P_x=\lim\frac{1}{2T}\int_{-T}^{T}|x(t)|^2dt$.
- $T=1/f=2\pi/\omega$; ayrıkta $\Omega=\omega T_s=\omega/f_s$.
- $\Re\{Ae^{j(\omega t+\theta)}\}=A\cos(\omega t+\theta)$.
- $e^{\sigma t}$: $\sigma<0$ azalma, $\sigma>0$ büyüme; $s=\sigma+j\omega$ karmaşık frekans.
- $u(t)-u(t-1)$ = $[0,1)$ aralığında dikdörtgen; $r(t)=\int u$; birim dikdörtgen ve birim üçgenin alanı 1.
- $\int f(t)\delta(t-T)dt=f(T)$; integral sınırları 0'ı (ya da $T$'yi) kapsamıyorsa sonuç 0.

## Detaylı Açıklamalar

- **İşlem sırası örneği.** Slayttaki $x(t)$, $t=0$'da tepe değeri 2 olan ve yaklaşık $[-1,1]$ aralığında tanımlı bir tümsektir. $x(2(t-1))$ istendiğinde önce $x(2t)$ (tümsek $[-1/2,1/2]$ aralığına sıkışır), sonra 1 öteleme yapılır ve tümsek $t=1$ civarına gelir. Önce $x(t-1)$ alınıp sonra 2 ile sıkıştırılırsa tümsek $t=1/2$ civarında kalır; bu yanlıştır. İfade $x(2t-2)$ diye açılırsa önce 2 birim öteleme ($x(t-2)$), sonra 2 ile sıkıştırma doğru sonucu verir (ekrandan, 00:25:00). Derste sağlama değer koyarak yapıldı: $t=0$ için argüman $-2$ (değer 0), $t=1$ için argüman 0 (tepe değeri 2), $t=2$ için argüman 2 (değer 0), $t=1/2$ ve $t=3/2$ için argüman $\mp1$ (yaklaşık 0), $t=3/4$ için argüman $-1/2$.
- **Enerji ve güç ilişkisi.** $E_x<\infty$ ise $P_x=\lim\frac{E_x}{2T}=0$ olur. $P_x>0$ ise $E_x=\lim 2T\cdot P_x=\infty$ olur (ekrandan, 00:45:00). Bu yüzden bir işaret aynı anda hem sonlu enerjili hem pozitif güçlü olamaz.
- **Ayrık sinüzoit.** Sürekli sinüzoitte $t$ yerine $nT_s$ konup $T_s$ yazılmadan yalnız indis kullanılır; frekans $\Omega=\omega/f_s$ olur. Slayt metnine göre $n$ yalnız tam sayı değerler aldığı için ayrık kosinüs ancak $2\pi/\omega$ rasyonel olduğunda periyodiktir (ekrandan, 00:55:00). Hoca slayttaki $A\cos(\omega n+\varphi)$ yazımında sayısal frekans için büyük $\Omega$ kullanılması gerektiğini belirtti.
- **Karmaşık üstel işaretin açılımı.** $e^{(\sigma+j\omega)t+j\theta}=e^{\sigma t}\cdot e^{j\omega t}\cdot e^{j\theta}$. $\theta$ sabitse $e^{j\theta}=\cos\theta+j\sin\theta$ sabit bir karmaşık sayıdır. $e^{j\omega t}$ salınımı, $e^{\sigma t}$ zarfı verir (ekrandan, 01:35:00). Slaytta sinüs teriminin önünde $i$ yazıyor; derste kullanılan gösterimle bu $j$'dir.
- **Doppler darbe dizisi.** Birim dikdörtgenin genişliği $\mathrm{rect}(t/\tau)$ ile $\tau$ yapılır; $\tau<1$ sıkıştırır, $\tau>1$ genişletir. $n=-2,\dots,2$ için $nT$ kadar ötelenmiş beş kopya toplanır ve zarf elde edilir; zarf $\cos(\omega t)$ ile çarpılınca işaret yalnız darbelerin olduğu aralıklarda var olur (ekrandan, 01:55:00).
- **Dürtü örneği.** $\int_{-2}^{3}f(t)\left(2+\delta(t+1)-3\delta(t-1)+2\delta(t+3)\right)dt = 2\int_{-2}^{3}f(t)dt+f(-1)-3f(1)$. $\delta(t+3)$ terimi $t=-3$'te olduğu ve bu nokta $[-2,3]$ aralığında olmadığı için sıfır verir (ekrandan, 02:15:00). (Ajan kontrolü: $f(t)=t^2+1$ için iki taraf da $88/3\approx29{,}33$ çıkıyor; numpy ile dar Gauss yaklaşımıyla doğrulandı.)
- **Dürtülerin integrali ve türev.** $x(t)=1+\delta(t-1)-2\delta(t-2)$ için $y(t)=\int_0^t x(\tau)d\tau$: $0\le t<1$ aralığında $y=t$ (1'e çıkar), $t=1$'de 1 birim sıçrar (2'ye), eğim 1 ile 3'e çıkar, $t=2$'de 2 birim düşer (1'e), sonra eğim 1 ile devam eder. Tersine $y'(t)=1+\delta(t-1)-2\delta(t-2)$ olur; her sıçrama türevde sıçrama büyüklüğünde bir dürtü verir (ekrandan, 02:20:00).
- **Ders sonrası not.** Hoca enerji formülünü anlatırken tahtaya $E=V\cdot i=i^2R$ yazdı. $V\cdot i=i^2R$ aslında anlık güçtür; enerji, gücün zamana göre integralidir ($E=\int i^2R\,dt$). Slayttaki formül bu integral biçimindedir (ekrandan, 00:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
