# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin tarihi 7 Ağustos 2021 Cumartesi. Ders Zoom üzerinden yapıldı. Bu kayıt, aynı günün ikinci oturumudur.
  - Asıl ders yaklaşık 00:03'te başlar.
  - Yaklaşık 00:57 ile 01:11 arasında ara verildi.
  - Kaydın sonunda (yaklaşık 02:18'den sonra) 6 soruluk ilk quiz başlatıldı.
- Dersin işleyişi ve duyurular
  - Quiz: test usulü, 6 soru, 30 dakika. Görülen soruya geri dönülemiyor. Dönem boyunca 3-4 quiz daha olacak.
  - Yaz okulunda ödev süreleri kısa olacak (en fazla 5-7 gün). Ödevler MATLAB veya Python ile, en fazla yaklaşık 50 satırlık kodlardır.
  - Konvolüsyon konusu bitince ilk ödev (konvolüsyon kodu) verilecek.
- Bellek birimleri hatırlatması: büyük B (byte) ile küçük b (bit) farkı.
- Zamanda ölçekleme (time scaling): germe (expansion/stretching) ve sıkıştırma (compression), upsampling ve interpolasyon.
- Zamanda tersleme (time reversal): $x(-t)$, $x[-n]$.
- Zamanda öteleme (time shifting): gecikme (delay) ve öne alma (advance).
- İşlemlerin birleştirilmesi: $x(2t-1)$ gibi ifadelerde doğru sıra.
- Periyodik sinyaller, temel periyot ve temel frekans.
- Karmaşık sayılar: kartezyen ve kutupsal gösterim, Euler formülü.
- Sinyallerde enerji ve güç; enerji sinyali ve güç sinyali.
- Temel sinyaller: sinüzoidler, üstel (exponential) sinyaller, sönümlü ve büyüyen sinüzoidler, karmaşık üstel sinyaller.
- Birim basamak $u(t)$, birim dikdörtgen (rect), rampa $r(t)$, birim üçgen, işaret (signum) fonksiyonu.
- Birim dürtü (unit impulse) $\delta(t)$, $\delta[n]$ ve özellikleri (örnekleme/eleme özelliği).
- Dürtü içeren integraller ve türevler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Euler formülü ve ondan türeyen iki eşitlik mutlaka bilinmeli.
  - $e^{j\alpha}=\cos\alpha+j\sin\alpha$
  - $\cos\alpha=\dfrac{e^{j\alpha}+e^{-j\alpha}}{2}$, $\sin\alpha=\dfrac{e^{j\alpha}-e^{-j\alpha}}{2j}$
  - Bu eşitlikler integrallerde kısmi integrasyon yükünü kaldırır.
- Birimler önemlidir.
  - Açısal frekans rad/s, frekans Hz, faz radyan cinsinden yazılır.
  - Birim yazılmazsa 10 puanlık sorudan 3-4 puan gidebilir.
- Enerji sinyali, güç sinyali ve "ne enerji ne güç" kavramları anahtar kelime gibi bilinmeli.
- Periyodik sinyallerde bir periyodu incelemek yeterlidir.
  - Temel periyodu zaman düzleminde aramak zordur. Frekans düzlemine geçmek (FFT, $O(n\log n)$) bu işi kolaylaştırır.
- Öteleme ve ölçekleme işlemleri birleştirilirken işlem sırasına dikkat edin.
  - $x(2t-1)$ elde edilirken $x(2t)$'yi 1 birim değil $\tfrac12$ birim ötelemek gerekir.
- Mühendislikte sanal birim $i$ değil $j$ ile gösterilir. Çünkü $i$ akımı gösterir.
- Quizlerin telafisi yok. Yaz okulunda bütünleme de yok.
  - Yalnızca hastaneye yatacak düzeyde ciddi bir durumda kalan quizlerin ortalaması alınabilir.
- Hoca devamsızlıktan kimseyi bırakmıyor. Yalnızca görünmek için derse girmeyin; dersi takip etmek önemli.
- Quiz sonuçlarıyla ilgili soruları e-posta ile değil, çarşamba günkü derste sorun. Cevaplar o derste açıklanacak.
- Quiz sırasında sistem saatine güvenmeyin. Kendi saatinizi tutun, F5'e basmayın.

## Kısa Tekrar Notları

- Ölçekleme: $x(at)$, $|a|>1$ ise sıkıştırma; $0<|a|<1$ ise germe.
- Tersleme: $x(-t)$. $[-4,2]$ aralığındaki ayrık sinyal terslenince $[-2,4]$ aralığına geçer.
- Öteleme: $x(t-t_0)$, $t_0>0$ ise gecikme (sağa kayma); $x(t+t_0)$ ise öne alma (sola kayma).
- Ayrık sinyalde ok işareti ($\uparrow$) $n=0$ örneğini gösterir.
- Periyodiklik: her $t$ için $x(t)=x(t+T_0)$. En küçük $T_0$ temel periyottur. $f_0=1/T_0$.
- Ayrık sinüzoid $\cos(\Omega n)$ periyodiktir ancak $\Omega/2\pi$ rasyonel ise.
- Karmaşık sayı: $z=x+jy=re^{j\varphi}$, $r=\sqrt{x^2+y^2}$, $\varphi=\arctan(y/x)$.
- Enerji: $E=\int_{-\infty}^{\infty}|x(t)|^2dt$, $E=\sum_{n=-\infty}^{\infty}|x[n]|^2$.
- Güç: $P=\lim_{T\to\infty}\frac{1}{2T}\int_{-T}^{T}|x(t)|^2dt$, $P=\lim_{N\to\infty}\frac{1}{2N+1}\sum_{n=-N}^{N}|x[n]|^2$.
- $0<E<\infty$ ise enerji sinyali ve $P=0$. $0<P<\infty$ ise güç sinyali ve $E=\infty$.
- $\int_{-\infty}^{t}u(\tau)d\tau=r(t)=t\,u(t)$.
- Eleme özelliği: $\int f(t)\delta(t-t_0)dt=f(t_0)$; $f(t)\delta(t-t_0)=f(t_0)\delta(t-t_0)$.

## Detaylı Açıklamalar

### Zamanda ölçekleme, tersleme ve öteleme

- Ölçekleme bağımsız değişken ($t$ veya $n$) üzerinde yapılır.
  - 0 ile 1 arasında bir sayıyla çarpmak germedir. Arada yeni örnekler oluşur (upsampling).
  - Boş kalan örnekler sıfır bırakılmaz. Komşu değerlerin ortalaması, ağırlıklı ortalaması veya kuadratik/kübik interpolasyon ile doldurulur.
  - Hoca bunu yoldaki çukurun dolgu malzemesiyle doldurulmasına benzetti.
- Tersleme $-1$ ile ölçeklemedir. $t$ noktasındaki değer $-t$ noktasına gider.
- Öteleme:
  - $x(t-1)$: sinyal 1 birim sağa kayar (gecikme).
  - $x(t+1)$: sinyal 1 birim sola kayar (öne alma, "in advance").
  - Pratik yöntem: parantez içini sıfır yapan $t$ değerini bulun. Yeni sinyal o noktadan başlar.
- Yan örnek: yaya trafik ışıkları arasında asfaltın altına gömülü kablo, geçen araçların bozduğu manyetik alanı ölçer. Sistem bu sinyalin şimdiki ve önceki değerlerine ($x[n]$, $x[n-1]$) bakarak trafik akışını izler.

### İşlemlerin birleştirilmesi: $x(2t-1)$

- Yöntem 1: önce öteleme, sonra ölçekleme.
  - $x(t)\to x(t-1)$ (1 birim gecikme) $\to x(2t-1)$ (2 ile sıkıştırma).
- Yöntem 2: önce ölçekleme, sonra öteleme.
  - $x(t)\to x(2t)$. Sonra $t$ yerine $t-\tfrac12$ yazılır: $x(2(t-\tfrac12))=x(2t-1)$.
  - Yani sıkıştırmadan sonra öteleme miktarı $\tfrac12$'dir.
- Sık yapılan hata: $x(2t)$'yi 1 birim ötelemek. Bu $x(2(t-1))=x(2t-2)$ verir.
- Önerilen alıştırmalar: verilen $x(t)$ için $x(-t/2)$, $x(2t+2)$, $x(-t+1)$ dalga biçimlerini çizin.

### Periyodik sinyaller

- $x(t)=x(t+T_0)$ eşitliği bütün $t$ değerleri için sağlanmalıdır. Tek bir $t$ bile eşitliği bozarsa sinyal o $T_0$ ile periyodik değildir.
- Ayrık durumda $x[n]=x[n+N_0]$, $N_0$ pozitif tam sayıdır.
- Temel frekans: $f_0=1/T_0$ veya $f_0=1/N_0$.
- Temel periyodu bulmak neden zor?
  - $N_0=1,2,3,\dots$ değerlerini tek tek denemek gerekir. Uzun sinyallerde bu çok sayıda deneme demektir.
  - Frekans düzleminde sinyalin frekans bileşenleri bulunur. Buradan $f_0$, sonra $T_0=1/f_0$ elde edilir.
- Periyodik genişletme: bir periyotluk parça uç uca eklenerek periyodik sinyal elde edilir. Müzik çalarlardaki "döngüde çal" seçeneği buna örnektir.
- Periyodik olmayan bir sinyal, Fourier analizinde tamamı tek bir periyotmuş gibi kabul edilerek incelenir.

### Karmaşık sinyaller ve karmaşık sayılar

- Karmaşık sinyal: gerçel (real) ve sanal (imaginary) iki bileşeni olan sinyal. Örnekler: radar, sonar, ultrason, haberleşme sinyalleri.
- Fourier dönüşümü bir integral dönüşümüdür:
  - $F(\omega)=\int_{-\infty}^{\infty}f(t)e^{-j\omega t}dt$, $\omega=2\pi f$.
  - $e^{-j\omega t}$ karmaşık olduğu için sonuç da karmaşıktır.
  - Genel integral dönüşümü: $F(\alpha)=\int f(\varphi)\,K(\alpha,\varphi)\,d\varphi$. Sonuç yeni değişken $\alpha$'ya bağlıdır.
- Kartezyen gösterim: $z=x+jy$.
- Kutupsal gösterim: $z=re^{j\varphi}=r\cos\varphi+jr\sin\varphi$.
  - $r=\sqrt{x^2+y^2}$, $\varphi=\arctan(y/x)$.
- Toplama/çıkarma kartezyen formda, çarpma/bölme kutupsal formda daha kolaydır.
- Karmaşık üstel: $e^{z}=e^{x+jy}=e^{x}(\cos y+j\sin y)$.

### Enerji ve güç

- Fiziksel örnek: $R$ direncinden geçen $i(t)$ akımının enerjisi $E=\int i^2(t)R\,dt$ (joule).
- $R=1\,\Omega$ alınınca sinyal işlemede kullanılan tanım çıkar: $E=\int|x(t)|^2dt$.
- Güç, birim zamandaki ortalama enerjidir.
- Ayrık örnek: $x[n]=\{1,2,3\}$ için $E=1^2+2^2+3^2=14$.
- $-T$ ile $T$ arasındaki aralık için $\frac{1}{2T}$, $-T/2$ ile $T/2$ arası için $\frac1T$ kullanılır. İkisi aynı sonucu verir.
- Ayrık durumda $-N$ ile $N$ arasında $2N+1$ örnek vardır. Bu yüzden $\frac{1}{2N+1}$ ile bölünür.
- Sınıflandırma:
  - $0<E<\infty$: enerji sinyali, $P=0$.
  - $0<P<\infty$: güç sinyali, $E=\infty$.
  - İkisi de değilse: ne enerji ne güç sinyali.
- Periyodik sinyallerde bir periyot üzerinden inceleme yeterlidir. Sıfırdan farklı periyodik sinyaller güç sinyalidir.
- Sınırlarda süreksizlik olan integrallerde $a^{+}$ ve $b^{-}$ limitleri kullanılır.

### Sinüzoidler

- $x(t)=A\cos(\omega t+\varphi)$.
  - $A$: genlik. $\omega=2\pi f$: açısal frekans (rad/s). $f$: frekans (Hz). $\varphi$: faz (radyan).
  - $T=2\pi/\omega$ (saniye).
- Faz $\pm90^\circ$ olunca kosinüs sinüse dönüşür. Bu yüzden "sinüzoid" kosinüs üzerinden tanımlanır.
- Ayrık sinüzoid: $x[n]=A\cos(\Omega n+\varphi)$, $n$ tam sayı.
- Örnek: $x(t)=\cos(2500\pi t)$, $f_s=500$ Hz ile örnekleniyor.
  - $t=n/500$ yazılır: $x[n]=\cos(5\pi n)$.
  - $\Omega/2\pi=5/2$ rasyoneldir. Sinyal periyodiktir.
  - Yanlış örnekleme periyodikliği bozabilir.
- Karmaşık sinüzoid: $Ae^{j(\omega t+\varphi)}=A\cos(\omega t+\varphi)+jA\sin(\omega t+\varphi)$.

### Üstel ve sönümlü sinyaller

- $e^{at}$, $a>0$ ise büyür (growth), $a<0$ ise söner (decay).
- $e^{t}$ sonsuza ıraksar. $(-\infty,\infty)$ üzerinde integrali yoktur. Fourier dönüşümünün bu tür sinyallerde "aksadığı" yer budur.
- Sönümlü sinüzoid: $e^{-at}\cos(\omega t)$, $a>0$. Zamanla sıfıra gider. RL ve RC devrelerinde bu karakteristik görülür.
- Karmaşık üstel: $e^{st}$, $s=\sigma+j\omega$.
  - $\sigma<0$ (sol yarı düzlem): sönen sinyaller.
  - $\sigma>0$ (sağ yarı düzlem): büyüyen sinyaller.

### Basamak, rampa, dikdörtgen ve üçgen

- Birim basamak: $u(t)=1$ ($t\ge0$), $u(t)=0$ ($t<0$). Ayrık hali $u[n]$.
- $u(-t)$: $t\le0$ için 1, $t>0$ için 0.
- $-u(t)$: genlik ekseninde işlemdir. $t\ge0$ için $-1$ olur.
- $u(t+3)$: basamak 3 birim sola kayar, $t=-3$'ten başlar.
- Parçalı fonksiyondan kurtulma: $e^{-t}u(t)$, $t<0$ için sıfır olan üstel sinyali tek ifadeyle verir.
- Saat darbesi parçası: $u(t)-u(t-1)$, $0\le t<1$ aralığında 1, başka yerde 0.
- Birim dikdörtgen $\mathrm{rect}(t)$: $|t|<\tfrac12$ için 1. Genişliği $\mathrm{rect}(t/T_0)$ ile ayarlanır.
- Rampa: $r(t)=t\,u(t)$.
  - $\int_{-\infty}^{t}u(\tau)d\tau=\int_0^t1\,d\tau=t$, $t\ge0$.
  - $3r(2t)$: eğim $2$'den $6$'ya çıkar.
- Birim üçgen: $|t|<1$ için $1-|t|$, başka yerde 0.
- İşaret fonksiyonu: $\mathrm{sgn}(t)$, $t>0$ için 1, $t<0$ için $-1$, $t=0$ için 0.
- Sistemi tanımak: girişe basamak/dürtü uygulanınca çıkış, sistemin "röntgenini" verir. Buna birim dürtü cevabı $h[n]$ denir.

### Birim dürtü

- $\delta(t)$: sıfır genişlikli, alanı 1 olan ideal darbe. Ayrık hali: $\delta[0]=1$, diğer yerlerde 0.
- Fiziksel karşılığı: devreyi anlık açıp kapatmak, çekiç darbesi, sopanın topa vuruşu, kondansatörün anlık şarjı.
- Eleme (sifting) özelliği: $\int f(t)\delta(t)dt=f(0)$ ($f$, $t=0$'da sürekli ise).
  - $\alpha\,\delta(t-2)$ ile çarpım $\alpha f(2)$ verir.
- $\sum_k\delta[n-k]$: istenen noktalarda birim örnekler. Örnekleme operatörü olarak kullanılır.
- Konvolüsyonun temeli: sinyal, ötelenmiş dürtülerin ağırlıklı toplamı olarak yazılır.

### Dürtü içeren integral örneği (slayt 50)

- Sınır kuralı:
  - $\int_{0^+}^{1}\delta(t)dt=0$, $\int_{0^-}^{1}\delta(t)dt=1$.
  - $\int_{-1}^{0^-}\delta(t)dt=0$, $\int_{-1}^{0^+}\delta(t)dt=1$.
- Örnek:

$$\int_{-2}^{3}f(t)\big(2+\delta(t+1)-3\delta(t-1)+2\delta(t+3)\big)dt=2\int_{-2}^{3}f(t)dt+f(-1)-3f(1)$$

- $\delta(t+3)$ dürtüsü $t=-3$'tedir. Bu nokta $[-2,3]$ aralığının dışında kalır. Bu terim sıfırdır.

### Dürtü ile integral ve türev

- Slayttaki örnek: sabit 1 değerli parçalar ile $t=1$'de pozitif, $t=2$'de negatif yönlü dürtüler içeren bir sinyal.
- İntegral alınırken:
  - Sabit 1 olan bölgede integral $t$ gibi doğrusal artar.
  - Dürtü noktasında integral, dürtünün ağırlığı kadar sıçrar (yukarı veya aşağı).
- Türev alınırken:
  - Doğrusal artan parçanın türevi sabittir.
  - Ani sıçramanın türevi, sıçrama miktarı ağırlıklı bir dürtüdür.
- Slayttaki şeklin tam değerleri altyazıdan kesin okunamıyor; mantığı yukarıdaki gibidir.

### Ders sonrası notlar

- Karmaşık sinyalin enerjisinde "real kısmın karesi" alınmaz. Doğrusu genliğin karesidir: $|x(t)|^2=x(t)x^*(t)$.
- Fourier dönüşümünün sonucu karmaşıktır. Yalnız gerçel kısım kullanılmaz. Genelde genlik $|X(\omega)|$ ve faz $\angle X(\omega)$ birlikte incelenir.
- $r=\sqrt{x^2+y^2}$ olmalıdır. Derste bir yerde karekök söylenmedi.
  - $\varphi=\arctan(y/x)$ yalnızca birinci ve dördüncü bölgede doğrudan doğrudur. Genel durumda `atan2(y, x)` kullanılmalıdır.
- Ayrık sinüzoidin periyodiklik şartı "$2\pi/\omega$ doğal sayı" değildir. Şart, $\Omega/2\pi$ oranının rasyonel olmasıdır.
  - $\Omega/2\pi=m/N$ (sadeleşmiş) ise temel periyot $N$'dir.
  - Örnek $\cos(5\pi n)$: $5\pi/2\pi=5/2$, temel periyot $N=2$. Gerçekten $\cos(5\pi n)=(-1)^n$ (Python ile doğrulandı).
- $e^{-t}$ de $(-\infty,\infty)$ üzerinde integrallenemez; $t\to-\infty$ iken ıraksar. Sönümlü sinyalin integrallenebilmesi için $u(t)$ ile çarpılması gerekir: $e^{-at}u(t)$, $a>0$.
- Derste $u[n]+u[-n]$ için "her noktada 1" dendi. Doğrusu $n=0$'da iki terim de 1'dir:
  - $u[n]+u[-n]=1+\delta[n]$. $n=0$'da değer 2'dir.
- Birim üçgenin ifadesi $1-|t|$ olmalıdır. Derste $1-t$ diye okundu.
- Konvolüsyon işaretini çarpma ile karıştırmayın. $x(t)*h(t)=\int x(\tau)h(t-\tau)d\tau$.
- Derste anlatılan "gözü yüz üzerinde arama" örneği teknik olarak korelasyondur (template matching). Konvolüsyondan farkı, kayan sinyalin ters çevrilmemesidir.
- Altyazıda bazı karmaşık sayı örnekleri (ör. "3 artı 6j") ve "Psevur bağıntısı" (Pisagor bağıntısı) anlaşılmıyor. Tahtadaki örnek kayıtta tam okunamıyor.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
