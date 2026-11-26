# Ders 11 Genişletilmiş Notu: Genel Tekrar ve Problem Çözümü: Sinyal İşlemleri, Sistemler, Konvolüsyon ve Fourier

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dönemin Kavram Haritası ve Fourier Kısaltmaları
- 2. Matematiksel Hatırlatmalar
- 3. Öteleme, Ters Çevirme ve İşlem Sırası
- 4. Zamanda ve Genlikte Çarpma, Örnekleme
- 5. Örneklenmiş Sinyalin Ayrık Denklemi ve Nyquist Şartı
- 6. Periyodiklik, Temel Periyot ve Temel Frekans
- 7. Enerji ve Güç Sinyalleri
- 8. Birim Basamak, Dürtü ve Türev ile İşlemler
- 9. Sistem Özellikleri: İki Örnek
- 10. Tek ve Çift Kısımlar
- 11. Sürekli Zamanda Analitik Konvolüsyon
- 12. Ayrık Zamanda Konvolüsyon
- 13. Fourier Serileri ve Kare Dalga Örneği
- 14. Fourier Dönüşümü, Özellikleri ve DTFT
- 15. Uygulamalar ve Diferansiyel Denklemden Dürtü Cevabı
- Örnek Sorular
- Dersin Toparlaması

## 1. Dönemin Kavram Haritası ve Fourier Kısaltmaları

Bu ders, dönem başından beri işlenen konuların toplu tekrarı ve bunlara yönelik çalışma sorularının çözümüyle geçti. Hoca önce tahtaya bir kavram haritası çizdi (ekrandan, 00:20:00):

- Sinyal işlemleri (signal operations) ve örnekleme (sampling)
- Sistem özellikleri ve sistem işlemleri
- Konvolüsyon
- Frekans uzayı: Fourier serileri (periyodik sinyaller) ve Fourier dönüşümü

Bu konuların her birinin iki kolu vardır: sürekli zaman ve ayrık zaman. Sinyal işlemlerinde tek/çift kısımlar, sistemlerde linearlik, zamanla değişmezlik ve kararlılık testleri, konvolüsyonda sürekli ve ayrık sürüm ayrı ayrı çalışılmıştı. Örnekleme konusu, sürekli bir sinyalin ayrık zamana nasıl geçirileceğini ve örnekleme hızının ne olduğunu göstermek için ele alınmıştı.

Frekans uzayına geçmekteki amaç, bir sinyali daha iyi bilinen temel sinyallerin, yani sinüs ve kosinüslerin toplamı olarak ifade etmektir:

$$x(t)=\sum_{i=0}^{\infty}A_i\cos(2\pi f_i t+\phi_i)$$

Ayrık zamanda $t$ yerine $n$ gelir ve parantezler köşeli olur; geri kalan her şey hemen hemen aynıdır. Fourier serisi periyodik sinyallere uygulanır. Sinyal periyodik değilse, eksi sonsuzdan artı sonsuza kadar olan bütün sinyal tek bir periyotmuş gibi düşünülüp Fourier dönüşümü yapılır.

Kitaplarda bazen yalnız kısaltmalar verildiği için hoca bunları bir tabloda topladı (ekrandan, 00:20:00):

| | Sürekli zaman | Ayrık zaman |
|---|---|---|
| Fourier serisi (periyodik) | FS, CTFS | DFS (bazı kaynaklarda DFT) |
| Fourier dönüşümü | FT, CTFT (sürekli zamanlı Fourier dönüşümü) | DTFT |
| Ters dönüşüm | IFT, ICTFT | IDTFT |

"Discrete Fourier Transform" (DFT) adı "Discrete Time Fourier Transform" (DTFT) ile karışabilir; ikisi farklı şeylerdir. Bir şeyin dönüşüm sayılabilmesi için ters dönüşümünün de olması gerekir. Serilerde ters işlem zaten bileşenleri toplayarak sinyali yeniden kurmaktır; dönüşümde ise ayrı bir ters dönüşüm integrali vardır. Dönem içinde bunların uygulaması olarak bir diferansiyel denklem de Fourier ile çözülmüştü.

## 2. Matematiksel Hatırlatmalar

Karmaşık düzlemde yatay eksen gerçel kısmı, dikey eksen sanal kısmı gösterir. Gerçel kısım için genellikle $\sigma$, sanal kısım için $j\omega$ kullanılır: $s=\sigma+j\omega$.

Örnek olarak $3+4j$ sayısı, vektörün boyu ve açısıyla da yazılabilir. Boy $r=\sqrt{3^2+4^2}=5$, açı $\tan\alpha=\frac43$ ile bulunur. Böylece

$$3+4j=5\,e^{j\alpha},\qquad \alpha=\arctan\frac43$$

Sık kullanılan integraller de bilinmelidir: $\int e^{at}dt=\frac{e^{at}}{a}$, $\int t^n dt=\frac{t^{n+1}}{n+1}$, sinüs ve kosinüs integralleri ve trigonometrik özdeşlikler. Hoca, bu formüllerin ve Fourier ile Laplace dönüşüm tablolarının bulunduğu bir kaynağı öğrencilerle paylaştığını hatırlattı.

## 3. Öteleme, Ters Çevirme ve İşlem Sırası

### 3.1 Örnek dizi

Hoca önce grafiği çizip sonra diziyi şöyle verdi (ekrandan, 00:25:00):

$$x[n]=\{0,\underline{0},1,2,3,3\}$$

Altı çizili eleman $n=0$'dır. Buna göre $x[-1]=0$, $x[0]=0$, $x[1]=1$, $x[2]=2$, $x[3]=3$, $x[4]=3$; diğer bütün değerler sıfırdır. İstenenler: (a) $x[-n+2]$, (b) $x[2n]$.

### 3.2 $x[-n+2]$: önce öteleme, sonra ters çevirme

Hoca önce diziyi ters çevirip sonra kaydırarak başladı. Bir öğrenci, önce öteleyip sonra ters çevirmek gerektiğini ve bu sıranın farklı sonuç verdiğini hatırlattı; hoca bunu doğruladı ve çözümü düzeltti.

**Adım 1: $x[n+2]$.** Argümana $+2$ eklemek, diziyi zaman ekseninde iki birim sola (negatif yöne) kaydırmaktır. Genliklerde hiçbir değişiklik olmaz. 4. örnek 2'ye, 3. örnek 1'e, 2. örnek 0'a, 1. örnek $-1$'e gelir:

| $n$ | $-1$ | $0$ | $1$ | $2$ |
|---|---|---|---|---|
| $x[n+2]$ | 1 | 2 | 3 | 3 |

**Adım 2: $n\to -n$.** Şimdi $n$ yerine $-n$ yazılır; bu, diziyi düşey eksene göre simetriğini almaktır:

| $n$ | $-2$ | $-1$ | $0$ | $1$ |
|---|---|---|---|---|
| $x[-n+2]$ | 3 | 3 | 2 | 1 |

(ekrandan, 00:35:00)

**Soru:** Son grafik $x[n-2]$'nin grafiği değil mi? **Cevap:** Hayır. $n-2$ zamanda ileri, yani sağa gitmek demektir; $n+2$ ise sola gitmektir. Burada önce $n+2$ ile sola kaydırdık.

**Soru:** $x[n+2]$'yi bulduktan sonra y eksenine göre simetri alınca içerisi eksiyle çarpılmış olmuyor mu? **Cevap:** Ters çevirmede genlikler eksiyle çarpılmaz. Yalnız $n$ yerine $-n$ konur. "Önce iki birim öteledik, sonra $n+2$'nin matematiksel tersini aldık" diye bir şey yoktur.

Bir öğrenci de sağlama yöntemi önerdi: orijinal dizide 2 değeri $n=2$'de olduğuna göre, yeni dizide bu değer $-n+2=2$ denklemini sağlayan $n=0$'da olmalıdır. Hoca bu kontrolün doğru olduğunu söyledi.

> **Hocanın vurgusu:** $x[-n+2]$ elde ederken "önce iki birim öteleyip sonra eksiyle çarpma" diye bir işlem yoktur; yalnız $n$'nin yerine $-n$ konur. İçeriği eksiyle çarpmak gibi düşünmek çok yanlıştır.

(b) şıkkı $x[2n]$ derste çözülmedi.

### 3.3 Genel işlem sırası

Hoca bir kitapta bulduğu genel kuralı paylaştı (ekrandan, 00:35:00). $g(t)$'den $A\,g\!\left(\frac{t-t_0}{a}\right)$ elde edilmek istenirse sıra şöyledir:

$$g(t)\xrightarrow{\;\times A\;}A\,g(t)\xrightarrow{\;t\to t/a\;}A\,g\!\left(\frac ta\right)\xrightarrow{\;t\to t-t_0\;}A\,g\!\left(\frac{t-t_0}{a}\right)$$

Yani önce genlik çarpımı, sonra zaman ölçekleme, en son öteleme yapılır. Sıra önemlidir; ölçeklemeden sonra $t$ yerine $t-t_0$ yazıldığı için öteleme otomatik olarak $t_0/a$ değil $t_0$ kadar olur.

## 4. Zamanda ve Genlikte Çarpma, Örnekleme

### 4.1 Üçgen sinyal

Hoca şu sinyali verdi (ekrandan, 00:45:00):

$$x(t)=\begin{cases}1-|t|, & -1\le t\le 1\\ 0, & \text{diğer}\end{cases}$$

Pozitif $t$ için $1-t$ gibi azalan, negatif $t$ için $1+t$ gibi artan bir doğrudur: $t=0$'da 1, $t=\pm1$'de 0 olan bir üçgen.

### 4.2 "2 ile çarpın" sorusundaki belirsizlik

Hoca "bu sinyali 2 ile çarpın" sorusunda bir yanlışlık olduğunu, bunu bulmak gerektiğini söyledi. İki ayrı anlam vardır:

- **Zamanda çarpma**, $x(2t)=1-2|t|$: sinyal sıkışır; $t=\pm1$'deki uçlar $t=\pm0.5$'e gelir. Bir müziği iki kat hızlı dinlemek gibidir; örnek sayısı azaltılmış olur (downsampling).
- **Genlikte çarpma**, $2x(t)=2(1-|t|)$: tepe 2'ye çıkar, sinyalin süresi değişmez. Müziğin sesini açmak gibidir.

**Soru:** Parçalı fonksiyonda "2 ile çarp" denince x eksenine göre mi y eksenine göre mi çarpacağımız sorulmalı değil mi? **Cevap:** Evet. Soruyu soran "zamanda iki kat" ya da "genliği iki katına çıkarın" gibi açık bir ifade kullanmalıdır.

### 4.3 $T_s=0.25$ s ile örnekleme

İstenen: $x(t)$, $0.25$ s aralıklarla örneklenirse oluşan ayrık sinyal. Ayrık sinyalde $t$ yerine $nT_s$ konur: $n=0$ sıfırıncı örnek ($t=0$), $n=1$ birinci örnek ($t=0.25$ s), $n=2$ ikinci örnek ($t=0.5$ s) ve böyle devam eder. Ayrık eksende $0.25$ diye bir değer yoktur; indisler $0,\pm1,\pm2,\dots$ diye gider.

$$x[n]=x(0.25\,n)=1-\frac{|n|}{4},\quad |n|\le4$$

| $n$ | 0 | $\pm1$ | $\pm2$ | $\pm3$ | $\pm4$ |
|---|---|---|---|---|---|
| $x[n]$ | 1 | 0.75 | 0.5 | 0.25 | 0 |

(ekrandan, 00:55:00)

Sinyal iki taraflı olduğu için pozitif ve negatif $n$ değerleri simetrik çıkar. (b) şıkkı olarak $0.5$ s aralıklı örnekleme öğrencilere bırakıldı (Örnek Sorular'a bakın).

## 5. Örneklenmiş Sinyalin Ayrık Denklemi ve Nyquist Şartı

### 5.1 Genel yöntem

Hoca bunun sınav dışında da lazım olacak bir beceri olduğunu söyledi. $A=\cos(2\pi f t)$ sinyalinin frekansı $f$'dir. Ayrık zamana geçmek için örnekleme frekansı Nyquist şartını sağlamalıdır:

$$f_s\ge 2f_{signal}$$

Örneğin sinyal 100 Hz ise en az 200 Hz ile örneklenmelidir. $f_s=2f$ alınırsa örnekleme periyodu $T_s=\frac1{2f}$ olur ($T_sf_s=1$). Sonra sinyalde $t$ yerine $n\,T_s$ yazılır (frekansın yerine değil, zamanın yerine):

$$A[n]=\cos(2\pi f\,nT_s)=\cos\!\left(2\pi f\,n\,\frac{1}{2f}\right)=\cos(\pi n)$$

$f$'ler ve 2'ler sadeleşir (ekrandan, 00:55:00). Hoca, $f=100$ Hz ve $f_s=200$ Hz için sürekli sinyali `plot` ile, örneklenmiş sinyali `stem` ile MATLAB'de çizdirip karşılaştırmayı önerdi.

### 5.2 İki bileşenli örnek

$$A=\cos(2\pi\,300\,t)+\cos(2\pi\,500\,t)$$

Örnekleme frekansı en büyük frekans bileşeninin en az iki katı olmalıdır; aksi hâlde örtüşme (aliasing) olur. $f_{max}=500$ Hz olduğundan $f_s\ge1000$ Hz; $f_s=1000$ Hz seçilir, $T_s=\frac1{1000}$ s. $t$ yerine $n/f_s$ yazılırsa:

$$A[n]=\cos\!\left(2\pi\cdot300\cdot\frac{n}{1000}\right)+\cos\!\left(2\pi\cdot500\cdot\frac{n}{1000}\right)=\cos\!\left(\frac{3\pi n}{5}\right)+\cos(\pi n)$$

(ekrandan, 00:55:00)

Bazı kitaplar $t=nT_s$, bazıları $t=n/f_s$ yazar. $T_sf_s=1$ olduğu için ikisi aynıdır; bunu gözden kaçırmamak gerekir.

Sinyal her zaman frekansı açıkça görünecek biçimde verilmez. Örneğin $A=\cos(600\pi t)$ verilirse $600\pi t=2\pi\cdot300\,t$ biçiminde açılıp frekansın 300 Hz olduğu bulunur.

Hoca, neden tam iki kat seçildiğinin arkasında bir ispat olduğunu, bunun Fourier dönüşümünden sonra gelen örnekleme konusunda ve daha çok sayısal sinyal işleme (DSP) dersinde ele alındığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Tam $f_s=2f$ seçimi sınır durumdur. $\cos(2\pi ft)$ bu hızla örneklenince $\cos(\pi n)=(-1)^n$ elde edilir; ama aynı frekanstaki $\sin(2\pi ft)$ örnekleri $\sin(\pi n)=0$ olur ve sinyal tamamen kaybolur. Bu yüzden uygulamada büyük olasılıkla $f_s>2f_{max}$ (kesin büyük) seçilir.

## 6. Periyodiklik, Temel Periyot ve Temel Frekans

### 6.1 Tek bileşen

$x(t)=\cos(t+\pi/4)$ (ekrandan, 01:00:00). $\pi/4$ fazdır, periyodu etkilemez. $t$'nin katsayısı açısal frekanstır: $\omega_0=1$. Periyot:

$$T_0=\frac{2\pi}{\omega_0}=2\pi$$

### 6.2 İki bileşen, sürekli zaman

$$x(t)=\cos\!\left(\frac{\pi}{3}t\right)+\sin\!\left(\frac{\pi}{4}t\right)$$

$\omega_1=\pi/3$, $\omega_2=\pi/4$. Periyotlar: $T_1=\frac{2\pi}{\pi/3}=6$, $T_2=\frac{2\pi}{\pi/4}=8$. Oran $6/8$ rasyonel olduğu için sinyal periyodiktir. Temel periyot EKOK ile bulunur (ekrandan, 01:05:00):

$$T_0=\mathrm{EKOK}(6,8)=24$$

Temel frekans bulunurken EBOB (GCD), temel periyot bulunurken EKOK (LCM) alınır.

### 6.3 İki bileşen, ayrık zaman

$$x[n]=\cos n+\sin(\sqrt2\,n)$$

$N_1=\frac{2\pi}{1}=2\pi$, $N_2=\frac{2\pi}{\sqrt2}=\sqrt2\,\pi$. Oran $\frac{2\pi}{\sqrt2\pi}=\sqrt2$ rasyonel olmadığı için sinyal periyodik değildir (ekrandan, 01:05:00).

> **Ders sonrası not:** Ayrık zamanda periyot bir tam sayı olmak zorundadır. $\cos n$ bileşeninin kendisi de periyodik değildir, çünkü $2\pi/\Omega=2\pi$ rasyonel bir sayı değildir. Dolayısıyla sonuç (periyodik değil) doğrudur, ama bunun için oranın irrasyonel olmasına bakmak bile gerekmez.

### 6.4 Temel frekans ve örnekleme frekansı

Ara sırasında tahtaya yazılan örnek (ekrandan, 01:20:00 ve 01:25:00): iki kosinüs bileşeni, frekansları $f_1=150$ Hz ve $f_2=400$ Hz.

- Temel frekans: $f_0=\mathrm{EBOB}(150,400)=50$ Hz. Frekans ekseninde $0, 50, 100, 150,\dots,400$ noktaları vardır; yalnız 150 ve 400 Hz'de bileşen bulunur, diğerlerinin genliği sıfır olduğu için "hükmü yoktur".
- Örnekleme frekansı: $f_s\ge2f_{max}=800$ Hz.

> **Ders sonrası not:** Tahtada sinyal $\cos(300t)+\cos(800t)$ olarak yazıldı. Bu yazımda açısal frekanslar 300 ve 800 rad/s olur ve frekanslar yaklaşık 47.7 Hz ile 127.3 Hz çıkar. Derste söylenen 150 Hz ve 400 Hz ancak $\cos(300\pi t)+\cos(800\pi t)$ için doğrudur; $\pi$ büyük olasılıkla yazılırken unutuldu.

## 7. Enerji ve Güç Sinyalleri

Tanımlar (ekrandan, 01:05:00):

$$E=\int_{-\infty}^{\infty}|x(t)|^2dt<\infty\ \Rightarrow\ \text{enerji sinyali}$$

$$P=\frac1{T_0}\int_{0}^{T_0}|x(t)|^2dt<\infty\ \Rightarrow\ \text{güç sinyali}$$

Ayrık zamanda integral yerine toplam kullanılır. Hoca sezgi için iki şekil çizdi: sonsuza doğru büyüyen bir sinyalin enerjisi sonsuz çıkar, bu bir enerji sinyali değildir; belirli bir yerden sonra sönen bir sinyalin alanı sonludur, bu bir enerji sinyalidir. Güç, bir periyot boyunca ortalama enerjiye bakmaktır.

### 7.1 Örnek: rampa $x(t)=t\,u(t)$

$u(t)$, $t\ge0$ için 1, $t<0$ için 0'dır (ekrandan, 01:05:00). $u(t)$ yüzünden negatif zamana bakmaya gerek yoktur.

**Enerji:**

$$E=\lim_{T\to\infty}\int_0^{T/2}t^2\,dt=\lim_{T\to\infty}\frac{(T/2)^3}{3}=\infty$$

**Güç:**

$$P=\lim_{T\to\infty}\frac1T\int_{-T/2}^{T/2}t^2u(t)\,dt=\lim_{T\to\infty}\frac1T\cdot\frac{(T/2)^3}{3}=\lim_{T\to\infty}\frac{T^2}{24}=\infty$$

(ekrandan, 01:10:00)

Hoca güç limitinde "sıfır çarpı sonsuz" belirsizliğinden söz edip türev alarak sonucun yine sonsuz olduğunu gösterdi; ifade sadeleştirilince doğrudan $T^2/24$ kalır ve sonsuza gider. İkisi de sonsuz olduğu için rampa ne enerji ne de güç sinyalidir.

## 8. Birim Basamak, Dürtü ve Türev ile İşlemler

### 8.1 Sürekli zaman

Verilen sinyal (ekrandan, 01:20:00): $-1\le t\le0$ aralığında 0'dan 1'e doğrusal artan, $0\le t\le1$ aralığında 1, $1<t\le2$ aralığında 2 olan parçalı bir $x(t)$. İstenenler:

- **$x(t)\,u(1-t)$:** Hoca önce $u(t-1)$ yazmış, sonra $1-t$ olarak düzeltti. $u(1-t)$, $t\le1$ için 1'dir; yani zamanda ters çevrilmiş bir basamaktır. Çarpım, sinyalin $t\le1$ kısmını (rampa ve $0$–$1$ arası düz kısım) bırakır, gerisini sıfırlar (ekrandan, 01:25:00).
- **$x(t)[u(t)-u(t-1)]$:** $u(t)$ ile $u(t-1)$ farkı yalnız $0\le t\le1$ aralığında 1'dir. Bu çarpım belli bir zaman aralığını geçiren bir süzgeç gibidir: sinyalin yalnız $0$–$1$ arasını olduğu gibi bırakır.
- **$x(t)\,\delta(t-3/2)$:** Dürtü $t=0$'da tanımlı, başka yerde sıfırdır; burada $3/2$ kadar ötelenmiştir. Dürtü aslında bir **örnekleme elemanıdır**: $t=1.5$'teki değeri alır. $x(1.5)=2$ olduğundan sonuç $2\,\delta(t-1.5)$ olur.

Hoca, dürtüyü sinyal üzerinde sonsuz defa gezdirmenin sinyalin bütün değerlerini tek tek almak, sistemin bir anlamda "röntgenini çekmek" olduğunu; dürtü cevabının (impulse response) bu fikirle bulunduğunu hatırlattı.

### 8.2 Ayrık zaman

Ayrık bir $x[n]$ dizisi için (ekrandan, 01:25:00):

- **$x[n]\,u[1-n]$:** $u[1-n]$, $n\le1$ için 1'dir. $n\le1$'deki örnekler yerinde kalır, $n\ge2$'deki örnekler yok edilir.
- **$x[n](u[n+2]-u[n])$:** $u[n+2]$, $n=-2$'den başlar; $u[n]$, $n=0$'dan başlar. Farkı yalnız $n=-2$ ve $n=-1$ için 1'dir; bu iki örnek kalır.
- **$x[n]\,\delta[n-1]$:** Yalnız $n=1$'deki örnek kalır, diğerleri sıfırlanır. Bu da ayrık zamanda örnekleme gibidir.

<!-- BELİRSİZ: ayrık x[n] dizisinin tek tek genlik değerleri karede ve altyazıda net değil (01:20:00, 01:27:00); ikinci işlemde tahtada u[n+1] mi u[n+2] mi yazıldığı da tam okunamadı, altyazıdaki "n artı 2" esas alındı. -->

### 8.3 Türev

**Dikdörtgen darbe** (ekrandan, 01:30:00): $0$ ile $a$ arasında 1 olan $x(t)$, birim basamak cinsinden

$$x(t)=u(t)-u(t-a)$$

Türevi:

$$x'(t)=\delta(t)-\delta(t-a)$$

Sabitin türevi sıfır olduğu için yalnız değişim noktalarında dürtü çıkar. $t=0$'da yukarı yönlü bir sıçrama vardır ($+\delta(t)$), $t=a$'da aşağı yönlü ($-\delta(t-a)$).

Hoca ek olarak, darbenin önüne $-1$ ile $0$ arasında artan bir doğru eklenirse türevin o aralıkta sabit pozitif bir değer çıkacağını söyledi; doğrunun eğimi türevin değeridir.

**İşaret (signum) fonksiyonu** (ekrandan, 01:35:00): $\mathrm{sgn}(t)$, $t>0$ için $+1$, $t<0$ için $-1$'dir. $t>0$'da $u(t)$ gibi, $t<0$'da $-u(-t)$ gibi davranır:

$$\mathrm{sgn}(t)=u(t)-u(-t)$$

Türevi:

$$\frac{d}{dt}\mathrm{sgn}(t)=\delta(t)+\delta(t)=2\,\delta(t)$$

$-1$'den $+1$'e iki birimlik bir sıçrama olduğu için dürtünün ağırlığı 2'dir.

> **Hocanın vurgusu:** Türevin fark, yani değişim demek olduğunu unutmayın. Çok kullanılan bir kavramdır.

## 9. Sistem Özellikleri: İki Örnek

### 9.1 $y(t)=x(t)\cos\omega t$

Sistem, girişi bir kosinüs kaynağıyla çarpan bir çarpıcıdır (ekrandan, 01:30:00 ve 01:35:00):

$$y(t)=x(t)\cdot\cos\omega t$$

Burada $\cos\omega t$, yalnız zamana bağlı değişen ayrı bir sinyaldir. Sistemin girişi $x(t)$'dir. İstenen: bellekli mi, nedensel mi, lineer mi, zamanla değişmez mi, kararlı (BIBO) mı?

**Bellek:** Çıkış yalnız girişin şimdiki değerine bağlıdır; ekstra bir hafıza gerekmez. **Belleksiz.**

**Nedensellik:** Nedensellik, çıkışın geleceğe bağlı olmamasıdır. Çıkış yalnız şimdiki $t$'ye bağlı. **Nedensel.**

**Linearlik** (ekrandan, 01:40:00): Hoca linearlik, zamanla değişmezlik ve kararlılığı "mahşerin üç atlısı" diye andı; bunlar tek tek kontrol edilmelidir.

- Toplamsallık: $y_1(t)=x_1(t)\cos\omega t$, $y_2(t)=x_2(t)\cos\omega t$; $y_1+y_2=\cos\omega t\,(x_1+x_2)$. Girişe $x_1+x_2$ verilirse $y_3(t)=(x_1+x_2)\cos\omega t$. İkisi eşittir.
- Çarpımsallık: $A\,y_1(t)=A\,x_1(t)\cos\omega t$; girişe $A\,x_1$ verilirse $(A\,x_1(t))\cos\omega t$. İkisi eşittir.
- Toplamsallık ve çarpımsallık birlikte süperpozisyondur. **Lineer.**

> **Hocanın vurgusu:** Bazı öğrenciler burada $\cos$'un içine $x_1+x_2$ yazıyor. $\cos x_1(t)$ olsaydı öyle yazılırdı; ama burada $\cos\omega t$ yalnız $t$'ye bağlıdır, ayrı bir sinyaldir. Girişe sinyal verilir, $t$'nin yerine bir şey konmaz.

**Zamanla değişmezlik:** Çıkışı $\tau$ kadar geciktirince

$$y(t-\tau)=x(t-\tau)\cos\omega(t-\tau)$$

Girişi $\tau$ kadar geciktirip sisteme verince

$$x(t-\tau)\cos\omega t$$

Gecikme yalnız $x$'i etkiler, kosinüsün zamanını etkilemez. İkisi eşit olmadığı için sistem **zamanla değişendir** (time variant) (ekrandan, 01:40:00).

**Kararlılık:** Giriş sınırlıysa ve $|\cos\omega t|\le1$ olduğundan çıkış en fazla girişin kendisi kadar olur; sonsuza gitme durumu yoktur. Sınırlı giriş sınırlı çıkış verir: **kararlı.**

### 9.2 $y[n]=n\,x[n]$ (çalışma sorusu)

Hoca sonuçlarını verdi:

- Çıkış yalnız şimdiki $n$ değerine bağlı: **belleksiz**, geleceğe bağlı değil: **nedensel.**
- Toplamsallık ve çarpımsallık sağlanır: **lineer**; bunun ispatı yapılmalıdır.
- Gecikmeli girişin çıkışı $n\,x[n-n_0]$, gecikmeli çıkış $(n-n_0)x[n-n_0]$; eşit değil: **zamanla değişen.**
- Giriş sınırlı olsa bile $n$ çarpanı büyük $n$ değerlerinde çıkışı sınırsız yapar: **kararsız.** Bir önceki örnekte kosinüs çıkışı sınırlı tutuyordu.

> **Ders sonrası not:** Altyazıda bu sistemin zamanla değişmezlik sonucu bozuk biçimde ("zamanla değişim yok") geçiyor. Doğrusu: $n$ katsayısı zamana bağlı olduğu için sistem zamanla değişendir.

## 10. Tek ve Çift Kısımlar

Formüller (ekrandan, 01:45:00):

$$g_e[n]=\frac{g[n]+g[-n]}{2},\qquad g_o[n]=\frac{g[n]-g[-n]}{2}$$

Örnek:

$$g[n]=\sin\!\left(\frac{2\pi n}{7}\right)(1+n^2)$$

$g[-n]$ bulunurken $n$ görülen her yere $-n$ yazılır: $g[-n]=\sin\!\left(-\frac{2\pi n}{7}\right)(1+(-n)^2)=-\sin\!\left(\frac{2\pi n}{7}\right)(1+n^2)$, çünkü sinüs tek, $n^2$ çifttir.

**Çift kısım:**

$$g_e[n]=\frac{\sin(2\pi n/7)(1+n^2)-\sin(2\pi n/7)(1+n^2)}{2}=0$$

**Tek kısım:**

$$g_o[n]=\frac{\sin(2\pi n/7)(1+n^2)+\sin(2\pi n/7)(1+n^2)}{2}=\sin\!\left(\frac{2\pi n}{7}\right)(1+n^2)$$

Sonuç: çift kısım sıfır, tek kısım sinyalin kendisidir; sinyal **tektir**.

Hoca çözüm sırasında $\sin(2\pi n/7)$'yi birim çemberden doğrudan sıfır yapmaya çalıştı, sonra bunun yanlış olduğunu fark edip düzeltti: $2\pi$, $n/7$ ile çarpıldığı için birim çemberden doğrudan sıfır denemez; sadeleşme yalnız sinüsün tek fonksiyon olmasından gelir.

**Soru:** Tek ya da ne tek ne çift olma hâlleri var; çift olma hâli de var mı? **Cevap:** Evet. Tek kısım sıfır, çift kısım sıfırdan farklı çıkarsa sinyal çifttir; çift kısım sıfır, tek kısım sıfırdan farklı çıkarsa tektir; ikisi de sıfırdan farklıysa ne tek ne çifttir.

## 11. Sürekli Zamanda Analitik Konvolüsyon

### 11.1 Soru

Verilen sinyaller (ekrandan, 01:50:00 ve 02:00:00): $x(t)$, $0$ ile $3$ arasında 1 olan bir dikdörtgen; $h(t)$, $0$ ile $2$ arasında 1 olan bir dikdörtgen. Konvolüsyon analitik olarak bulunacak. Grafikle yapmak (birini ters çevirip örtüştüğü bölgelerde integral almak) daha kolaydır; burada basamak fonksiyonlarıyla analitik yol izlendi.

$$x(t)=u(t)-u(t-3),\qquad h(t)=u(t)-u(t-2)$$

### 11.2 Kurulum

Konvolüsyonda $t$ düzleminden $\tau$ düzlemine geçilir ($\tau$, periyotla karışmasın diye kullanılır); sinyallerden biri ters çevrilip ötelenir (hangisi olduğu fark etmez):

$$y(t)=\int_{-\infty}^{\infty}x(\tau)\,h(t-\tau)\,d\tau=\int_{-\infty}^{\infty}[u(\tau)-u(\tau-3)]\,[u(t-\tau)-u(t-\tau-2)]\,d\tau$$

Çarpım dağıtılınca dört terim çıkar (ekrandan, 02:00:00):

$$y(t)=\int\underbrace{u(\tau)u(t-\tau)}_{1}-\underbrace{u(\tau)u(t-\tau-2)}_{2}-\underbrace{u(\tau-3)u(t-\tau)}_{3}+\underbrace{u(\tau-3)u(t-\tau-2)}_{4}\,d\tau$$

### 11.3 Her terimin sınırları

Her terimde iki basamağın çarpımı yalnız belli bir $\tau$ aralığında 1'dir:

1. $u(\tau)u(t-\tau)=1$ için $0<\tau<t$ (ve $t>0$): $\int_0^t d\tau=t$ → $t\,u(t)$
2. $u(\tau)u(t-\tau-2)=1$ için $0<\tau<t-2$: $\int_0^{t-2}d\tau=t-2$ → $(t-2)\,u(t-2)$
3. $u(\tau-3)u(t-\tau)=1$ için $3<\tau<t$: $\int_3^{t}d\tau=t-3$ → $(t-3)\,u(t-3)$
4. $u(\tau-3)u(t-\tau-2)=1$ için $3<\tau<t-2$ (yani $t>5$): $\int_3^{t-2}d\tau=t-5$ → $(t-5)\,u(t-5)$

İntegrandın 1 olması, sinyallerin genliğinin 1 olmasındandır; genlik 2 ya da 3 olsaydı integralin önüne o katsayı gelirdi. Hoca önce sonuçları $u(t)$ ile çarptı, sonra her terimin kendi başlangıç noktasından itibaren geçerli olduğunu belirtmek için $u(t-2)$, $u(t-3)$, $u(t-5)$ olarak düzeltti; aksi hâlde önceki değerler de etkilenirdi.

### 11.4 Sonuç ve yorum

$$y(t)=t\,u(t)-(t-2)\,u(t-2)-(t-3)\,u(t-3)+(t-5)\,u(t-5)$$

Grafik:

- $0\le t\le2$: $y=t$, doğrusal artış (0'dan 2'ye).
- $2\le t\le3$: $t-(t-2)=2$, sabit plato.
- $3\le t\le5$: $2-(t-3)=5-t$, doğrusal azalış (2'den 0'a).
- $t\ge5$: $5-t+(t-5)=0$.

Hoca, $-(t-2)u(t-2)$ ve $-(t-3)u(t-3)$ terimlerinin artışı durdurup düşüşü başlatan, $+(t-5)u(t-5)$ teriminin de düşüşü nötrleyen bir "baskılama" (suppression) işlevi gördüğünü anlattı. Grafik yöntemle de aynı şey görülür: ters çevrilen darbe diğerinin üzerine girerken çarpım iki birime kadar artar, tam örtüşme bölgesinde sabit kalır, sonra çıkarken azalır ve 5'te sıfıra ulaşır.

## 12. Ayrık Zamanda Konvolüsyon

### 12.1 Soru

İki dizi verildi; bütün değerleri 1'dir (ekrandan, 02:15:00):

$$x[n]=\delta[n]+\delta[n-1]+\delta[n-2]+\delta[n-3]$$

$$y[n]=\delta[n]+\delta[n-1]+\delta[n-2]$$

Hoca ayrık konvolüsyonun çoğu kişiye daha kolay geldiğini, bir `for` döngüsü mantığıyla izlenebildiğini söyledi. Tablo yöntemi de kullanılabilir; burada dürtülerle analitik çözüm yapıldı.

### 12.2 Dağılma özelliğiyle çözüm

Konvolüsyonun dağılma özelliği ve $x[n]*\delta[n-k]=x[n-k]$ kuralı kullanılır. Bir diziyi $\delta[n-k]$ ile konvole etmek, o diziyi $k$ birim kaydırmak demektir:

$$x[n]*y[n]=x[n]*\delta[n]+x[n]*\delta[n-1]+x[n]*\delta[n-2]=x[n]+x[n-1]+x[n-2]$$

Açılım:

- $x[n]=\delta[n]+\delta[n-1]+\delta[n-2]+\delta[n-3]$
- $x[n-1]=\delta[n-1]+\delta[n-2]+\delta[n-3]+\delta[n-4]$
- $x[n-2]=\delta[n-2]+\delta[n-3]+\delta[n-4]+\delta[n-5]$

Aynı gecikmeli terimler toplanır (ekrandan, 02:15:00):

$$x[n]*y[n]=\delta[n]+2\delta[n-1]+3\delta[n-2]+3\delta[n-3]+2\delta[n-4]+\delta[n-5]$$

Yani sonuç dizisi $\{1,2,3,3,2,1\}$'dir.

### 12.3 Kaydır-çarp-topla ile sağlama

Bir dizi ters çevrilip diğerinin üzerinde kaydırılır; her konumda üst üste gelen elemanlar çarpılıp toplanır:

- Bir eleman örtüşür: $1\cdot1=1$
- İki eleman: $1+1=2$
- Üç eleman: $3$
- Yine üç eleman: $3$
- İki eleman: $2$
- Bir eleman: $1$

İki yöntem aynı sonucu verir. Hoca ters çevirmenin nedenini polinom çarpmasına benzetti: polinom çarpmasında nasıl en büyük dereceden başlanıyorsa, burada da birinci dizinin ilk örneği ikincinin ilk örneğiyle çarpılarak başlanır.

## 13. Fourier Serileri ve Kare Dalga Örneği

### 13.1 Euler formülü

Hoca bu formülün bilinmesinin çok önemli olduğunu söyledi (ekrandan, 02:20:00):

$$e^{jk\omega_0t}=\cos k\omega_0t+j\sin k\omega_0t$$

Daha kısa ezberlemek için: $e^{jt}=\cos t+j\sin t$, $e^{-jt}=\cos t-j\sin t$. Bu ikisi taraf tarafa toplanıp çıkarılarak sinüs ve kosinüs üstel biçimde yazılabilir.

### 13.2 Üstel ve trigonometrik biçimler

Fourier serileri periyodik sinyallere uygulanır. **Üstel biçim** (ekrandan, 02:20:00):

$$x(t)=\sum_{k=-\infty}^{\infty}c_k\,e^{jk\omega_0t},\qquad c_k=\frac1{T_0}\int_{T_0}x(t)\,e^{-jk\omega_0t}\,dt,\qquad \omega_0=\frac{2\pi}{T_0}$$

$c_0$ özel bir durumdur ve sinyalin DC bileşenini verir: sinyalin bir periyot boyunca integrali, yani bir periyodunun alanı, periyoda bölünür:

$$c_0=\frac1{T_0}\int_{T_0}x(t)\,dt$$

**Trigonometrik biçim:**

$$x(t)=\frac{a_0}{2}+\sum_{k=1}^{\infty}\left(a_k\cos k\omega_0t+b_k\sin k\omega_0t\right)$$

$$a_k=\frac2{T_0}\int_{T_0}x(t)\cos k\omega_0t\,dt,\qquad b_k=\frac2{T_0}\int_{T_0}x(t)\sin k\omega_0t\,dt$$

Hoca $a_k$'nın kosinüslerle, $b_k$'nın sinüslerle bir tür benzerlik (konvolüsyon benzeri) hesabı olduğunu, sinyalde hangi frekans bileşenlerinin ağırlıkta olduğunu bulduğunu söyledi. Üstel biçim tek integral, trigonometrik biçim iki integral gerektirir. Pratik yol: önce $c_k$'yı hesaplayıp

$$a_0=2c_0,\qquad a_k=2\,\mathrm{Re}\{c_k\},\qquad b_k=-2\,\mathrm{Im}\{c_k\}$$

bağıntılarıyla $a_k$ ve $b_k$'yı yazmak (ekrandan, 02:20:00).

Ayrık zamandaki Fourier serisi daha çok programlamayla hesaplandığı ve toplam sembollerinde seri açılımlarını iyi bilmeyi gerektirdiği için derste sürekli zamanlı örnek tercih edildi.

### 13.3 Kare dalga örneği

Sinyal (ekrandan, 02:30:00): periyodu $T_0$, genliği $A$ olan bir kare dalga; $-T_0/4<t<T_0/4$ aralığında $A$, periyodun geri kalanında 0. Yani her periyotta $T_0/2$ süre boyunca $A$ değerindedir. $\omega_0=\frac{2\pi}{T_0}$.

**$c_k$:** İntegral yalnız sinyalin sıfırdan farklı olduğu aralıkta alınır:

$$c_k=\frac1{T_0}\int_{-T_0/4}^{T_0/4}A\,e^{-jk\omega_0t}\,dt=\frac{A}{-jk\omega_0T_0}\Big[e^{-jk\omega_0t}\Big]_{-T_0/4}^{T_0/4}$$

$\omega_0=2\pi/T_0$ yazılınca $\omega_0T_0=2\pi$ ve $\omega_0\cdot\frac{T_0}{4}=\frac{\pi}{2}$:

$$c_k=\frac{A}{-jk2\pi}\left(e^{-jk\pi/2}-e^{jk\pi/2}\right)$$

Euler'den $e^{-j\theta}-e^{j\theta}=-2j\sin\theta$ olduğundan (ara adım eklendi):

$$c_k=\frac{A}{-jk2\pi}\cdot(-2j)\sin\frac{k\pi}{2}=\frac{A}{k\pi}\sin\!\left(\frac{k\pi}{2}\right)$$

(ekrandan, 02:30:00). Hoca derste $2j$ ile çarpma geçişini o an hatırlayamadığını söyledi; yukarıdaki ara adım bu geçiştir.

**$c_0$:** Ayrı bir integraldir:

$$c_0=\frac1{T_0}\int_{-T_0/4}^{T_0/4}A\,dt=\frac{A}{T_0}\cdot\frac{T_0}{2}=\frac{A}{2}$$

Sinyal periyodun yarısında $A$ olduğu için ortalaması $A/2$'dir.

Katsayıların değerleri $\sin(k\pi/2)$'ye bağlıdır: $k=1$ için 1, $k=2$ için 0, $k=3$ için $-1$, $k=4$ için 0. Çift $k$'lar sıfırdır.

> **Ders sonrası not:** Hoca $\sin(k\pi/2)$ değerlerini "1, 1, 1, 0" diye saydı; doğrusu $k=1,2,3,4$ için $1,0,-1,0$'dır.

> **Ders sonrası not:** Hoca $a_k$'ların sıfır çıkacağını, çünkü sinyalin tek olduğunu söyledi ve $b_k=(-1)^k\frac{2A}{(2k+1)\pi}$ yazdı. Doğrusu: $t=0$ etrafında simetrik bu kare dalga **çift** bir sinyaldir. Bu yüzden $c_k$ gerçeldir, $b_k=-2\,\mathrm{Im}\{c_k\}=0$ olur ve yalnız kosinüs terimleri kalır: $a_k=2c_k=\frac{2A}{k\pi}\sin\frac{k\pi}{2}$. Tek $k=2m+1$ için $a_{2m+1}=(-1)^m\frac{2A}{(2m+1)\pi}$. Hocanın verdiği $(-1)^m\frac{2A}{(2m+1)\pi}$ biçimindeki katsayı büyük olasılıkla bu kosinüs katsayısıdır.

Böylece kare dalga $x(t)=\frac{A}{2}+\frac{2A}{\pi}\left(\cos\omega_0t-\frac13\cos3\omega_0t+\frac15\cos5\omega_0t-\dots\right)$ biçiminde modellenir.

## 14. Fourier Dönüşümü, Özellikleri ve DTFT

### 14.1 Dönüşüm ve ters dönüşüm

Sinyal periyodik değilse tamamı bir periyotmuş gibi düşünülür ve integral alınarak analiz yapılır (ekrandan, 02:35:00):

$$X(\omega)=\int_{-\infty}^{\infty}x(t)\,e^{-j\omega t}\,dt,\qquad x(t)=\frac1{2\pi}\int_{-\infty}^{\infty}X(\omega)\,e^{j\omega t}\,d\omega$$

Hoca, Fourier serisinde iki yöntem (trigonometrik ya da üstel), Fourier dönüşümünde ise tek bir integral olduğunu; ayrıca bir çözüm yöntemi araştırmaya gerek olmadığını, kare dalga ve üçgen dalga gibi bilinen basit sinyallerin dönüşümlerinin yeterli olacağını söyledi.

### 14.2 Sık kullanılan özellikler

(ekrandan, 02:45:00)

- **Türev:** $\frac{d\,x(t)}{dt}\leftrightarrow j\omega\,X(\omega)$. Önce türev alıp sonra yeniden Fourier dönüşümü almaya gerek kalmaz; $X(\omega)$'yı $j\omega$ ile çarpmak yeter.
- **Öteleme:** $x(t-t_0)\leftrightarrow X(\omega)\,e^{-j\omega t_0}$. Sinyali öteleyip yeniden dönüşüm almaya gerek yoktur.
- **Konvolüsyon:** $x(t)*y(t)\leftrightarrow X(\omega)\,Y(\omega)$. Zamanda konvolüsyon yerine frekansta çarpım yeterlidir.
- **Frekans cevabı:** $H(\omega)=\frac{Y(\omega)}{X(\omega)}$.
- **Dürtü cevabı:** $h(t)=\mathcal F^{-1}\{H(\omega)\}$.

> **Ders sonrası not:** Tahtada öteleme özelliği $x(t-t_0)\leftrightarrow X(\omega)\,e^{j\omega_0t}$ biçiminde yazıldı. Doğrusu $x(t-t_0)\leftrightarrow X(\omega)\,e^{-j\omega t_0}$'dır: üstelde zaman değil öteleme miktarı $t_0$ ve eksi işaret bulunur.

Hoca, dürtü cevabını doğrudan bulmakta zorlanılırsa giriş ve çıkışın Fourier dönüşümlerini alıp oranlayarak frekans cevabının, onun ters dönüşümüyle de dürtü cevabının bulunabileceğini anlattı. Bu iki özellik (türev ve öteleme) sistem modellemede diferansiyel denklem çözmek yerine çok kullanılır.

### 14.3 Ayrık zamanlı Fourier dönüşümü (DTFT)

Ayrık zamanda elimizdeki veri $x[n]$ örneklerinden oluştuğu için integral yerine toplam kullanılır (ekrandan, 02:45:00):

$$X(\Omega)=\sum_{n=-\infty}^{\infty}x[n]\,e^{-j\Omega n}$$

Ters dönüşüm, frekans düzleminden ayrık zamana geçiştir ve bir $2\pi$ aralığı boyunca integral içerir:

$$x[n]=\frac1{2\pi}\int_{2\pi}X(\Omega)\,e^{j\Omega n}\,d\Omega$$

Ödev sorusu bu ters dönüşümle ilgilidir (Örnek Sorular'a bakın).

## 15. Uygulamalar ve Diferansiyel Denklemden Dürtü Cevabı

### 15.1 Radyo ve bant geçiren filtre

Havada çok sayıda frekans bandı vardır ve her bandın içinde ayrı bir veri akışı bulunur. Radyo ya da telefon belli bir frekansa (ör. 87.50 gibi bir kanal değerine) ayarlandığında bir **bant geçiren filtre** kullanılır: yalnız o kanalın bandı alınır, geri kalan her şey bastırılır ve o banttan gelen veri çözülür. Bu, Fourier dönüşümünün en bilinen uygulamasıdır.

### 15.2 Kontrol sistemleri ve transfer fonksiyonu

İkinci örnek kontrolcülerin alanından: akıllı bir seranın sıcaklık modeli. Dış ortam sıcaklığı, iç sıcaklık, içerideki ısı gibi parametrelerden bir denklem kurulur ve bu denklemin diferansiyel denklemi bulunur. Sonra Laplace (ya da Fourier) dönüşümüyle sistemin **transfer fonksiyonu** elde edilir. Transfer fonksiyonu, girişe verilen şeyin çıkışta ne olarak geleceğini söyler; Fourier'deki $H(\omega)=Y(\omega)/X(\omega)$'nın Laplace'taki karşılığıdır ($\omega$ yerine $s$ konur). Transfer fonksiyonu bilinince her girişin çıkışı tahmin edilebilir ve sistemin ne kadar performanslı, hatasız çalıştığı değerlendirilebilir. Hoca, bilgisayar mühendisleri için sinyaller dersinde görülen bu araçların kontrolcüler için Laplace ve Fourier dönüşümü olarak karşılarına çıktığını söyledi.

### 15.3 Örnek: $y'(t)+2y(t)=x(t)+x'(t)$

(ekrandan, 02:50:00 ve 02:55:00)

$x(t)$ giriş, $y(t)$ çıkıştır. $y(t)$'nin kendisi bilinmediği için türevi de doğrudan bulunamaz. İki yol vardır: diferansiyel denklemi çözmek ya da Fourier dönüşümünü kullanmak.

**Adım 1: Her iki tarafın Fourier dönüşümü.** Türev özelliği ($\frac{d}{dt}\leftrightarrow j\omega$) ve dönüşümün doğrusallığı kullanılır:

$$j\omega\,Y(\omega)+2\,Y(\omega)=X(\omega)+j\omega\,X(\omega)$$

**Adım 2: Ortak parantez.**

$$Y(\omega)(2+j\omega)=X(\omega)(1+j\omega)$$

**Adım 3: Frekans cevabı.**

$$H(\omega)=\frac{Y(\omega)}{X(\omega)}=\frac{1+j\omega}{2+j\omega}$$

**Adım 4: Kısmi kesirler.** Paya bir ekleyip bir çıkarılır:

$$H(\omega)=\frac{(2+j\omega)-1}{2+j\omega}=1-\frac{1}{2+j\omega}$$

**Adım 5: Ters Fourier dönüşümü (tablodan).** $\mathcal F\{\delta(t)\}=1$ ve $\mathcal F\{e^{-2t}u(t)\}=\frac1{2+j\omega}$ olduğundan:

$$h(t)=\delta(t)-e^{-2t}\,u(t)$$

> **Ders sonrası not:** Tahtada sonuç $h(t)=\delta(t)-e^{2t}u(t)$ olarak yazıldı. Doğrusu $h(t)=\delta(t)-e^{-2t}u(t)$'dir; $e^{2t}u(t)$ sonsuza büyür ve Fourier dönüşümü yoktur.

Hoca, bu sonucun sistemin davranışını gösterdiğini, artık girişe herhangi bir $x(t)$ verildiğinde çıkışın bulunabileceğini söyledi.

### 15.4 Ayrık zamandaki karşılığı ve özyineleme

Hoca bir sonraki örneğin bunun ayrık zamanlı sürümü olacağını söyledi: bu kez diferansiyel değil, fark denklemi (ör. $y[n]-\frac34y[n-1]$ terimleri içeren) verilecek. Çözüm aynı yoldan gider: DTFT alınır, $Y(\Omega)/X(\Omega)$ bulunur, ters dönüşümle $h[n]$ elde edilir. Sonuç $a^n$ biçiminde üstel terimler içerir; ayrık matematikteki özyineleme bağıntılarının (recurrence relation) çözümüne benzer. Bu örnek derste çözülmedi.

Hoca bu benzerliği açmak için Fibonacci örneğini verdi: $f(n)$ fonksiyonu kendini $f(n-1)$ ve $f(n-2)$ ile çağırırsa her adımda iki dala ayrılır ve boyut bir azalır; karmaşıklık yaklaşık $2^n$ mertebesine çıkar. Daha kesin olarak "bir virgül küsur üzeri $n$"dir.

> **Ek bilgi (derste anlatılmadı):** Fibonacci özyinelemesinin karmaşıklığı büyük olasılıkla $\varphi^n$ mertebesindedir; $\varphi=\frac{1+\sqrt5}{2}\approx1.618$ altın orandır. Bu, $f(n)=f(n-1)+f(n-2)$ fark denkleminin karakteristik kökü olarak çıkar; doğrusal fark denklemlerinin çözümünün $a^n$ biçimli terimler içermesinin bir örneğidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $x[n]=\{0,\underline{0},1,2,3,3\}$ ($n=0$ altı çizili) veriliyor. (a) $x[-n+2]$'yi bulun. (b) $x[2n]$'yi bulun.

> **Çözüm (a, derste verildi):** Önce $x[n+2]$ (iki birim sola kaydırma): $n=-1,0,1,2$'de $1,2,3,3$. Sonra $n\to-n$: $x[-n+2]$, $n=1,0,-1,-2$'de sırasıyla $1,2,3,3$; diğer yerlerde 0.

> **Çözüm (b, derste verilmedi):** $x[2n]$ yalnız çift indisli örnekleri tutar: $x[2\cdot0]=x[0]=0$, $x[2\cdot1]=x[2]=2$, $x[2\cdot2]=x[4]=3$, $x[2\cdot(-1)]=x[-2]=0$. Sonuç: $n=0$'da 0, $n=1$'de 2, $n=2$'de 3, diğer yerlerde 0.

**Soru 2** (ekrandan, 00:45:00): $x(t)=1-|t|$, $-1\le t\le1$ (başka yerde 0). (a) $0.25$ s aralıklarla örneklenirse ayrık sinyal nedir? (b) $0.5$ s aralıklarla örneklenirse?

> **Çözüm (a, derste verildi):** $x[n]=1-|n|/4$, $|n|\le4$: $x[0]=1$, $x[\pm1]=0.75$, $x[\pm2]=0.5$, $x[\pm3]=0.25$, $x[\pm4]=0$.

> **Çözüm (b, derste verilmedi):** $x[n]=x(0.5n)=1-|n|/2$, $|n|\le2$: $x[0]=1$, $x[\pm1]=0.5$, $x[\pm2]=0$. Örnekleme aralığı büyüdüğü için üçgen daha az örnekle temsil edilir.

**Soru 3** (ekrandan, 00:55:00): $A=\cos(2\pi\,300\,t)+\cos(2\pi\,500\,t)$ sinyali için gereken en küçük örnekleme frekansını ve örneklenmiş sinyalin ayrık denklemini bulun.

> **Çözüm (derste verildi):** $f_s\ge2\cdot500=1000$ Hz. $t=n/f_s$ ile $A[n]=\cos(3\pi n/5)+\cos(\pi n)$.

**Soru 4** (ekrandan, 01:00:00 ve 01:05:00): Aşağıdaki sinyallerin periyodik olup olmadığını ve temel periyotlarını bulun: (a) $x(t)=\cos(t+\pi/4)$; (b) $x(t)=\cos(\pi t/3)+\sin(\pi t/4)$; (c) $x[n]=\cos n+\sin(\sqrt2\,n)$.

> **Çözüm (derste verildi):** (a) $\omega_0=1$, $T_0=2\pi$. (b) $T_1=6$, $T_2=8$, oran rasyonel, $T_0=\mathrm{EKOK}(6,8)=24$. (c) $N_1=2\pi$, $N_2=\sqrt2\pi$, oran $\sqrt2$ irrasyonel: periyodik değil.

**Soru 5** (ekrandan, 01:05:00): $x(t)=t\,u(t)$ sinyalinin enerji ya da güç sinyali olup olmadığını belirleyin.

> **Çözüm (derste verildi):** $E=\lim\frac{(T/2)^3}{3}=\infty$, $P=\lim\frac{T^2}{24}=\infty$. Ne enerji ne güç sinyalidir.

**Soru 6** (ekrandan, 01:20:00): Parçalı $x(t)$ ($-1$–$0$ arası 0'dan 1'e artan doğru, $0$–$1$ arası 1, $1$–$2$ arası 2) için $x(t)u(1-t)$, $x(t)[u(t)-u(t-1)]$ ve $x(t)\delta(t-3/2)$'yi çizin. Ayrık bir $x[n]$ için $x[n]u[1-n]$, $x[n](u[n+2]-u[n])$ ve $x[n]\delta[n-1]$'i bulun.

> **Çözüm (derste verildi):** $x(t)u(1-t)$: $t\le1$ kısmı kalır. $x(t)[u(t)-u(t-1)]$: yalnız $0\le t\le1$ arası (değeri 1) kalır. $x(t)\delta(t-3/2)=x(1.5)\delta(t-1.5)=2\delta(t-1.5)$. Ayrık sürümde sırasıyla $n\le1$ örnekleri, yalnız $n=-2,-1$ örnekleri ve yalnız $x[1]$ kalır.

**Soru 7** (ekrandan, 01:30:00): (a) $0$ ile $a$ arasında 1 olan $x(t)$'yi birim basamak cinsinden yazın ve türevini bulun. (b) $x(t)=\mathrm{sgn}(t)$ için $x'(t)$ nedir?

> **Çözüm (derste verildi):** (a) $x(t)=u(t)-u(t-a)$, $x'(t)=\delta(t)-\delta(t-a)$. (b) $\mathrm{sgn}(t)=u(t)-u(-t)$, $x'(t)=2\delta(t)$.

**Soru 8** (ekrandan, 01:30:00): $y(t)=x(t)\cos\omega t$ sistemi bellekli mi, nedensel mi, lineer mi, zamanla değişmez mi, kararlı mı?

> **Çözüm (derste verildi):** Belleksiz, nedensel, lineer, zamanla değişen, BIBO kararlı.

**Soru 9** (derste sözlü, 01:41:14): $y[n]=n\,x[n]$ sistemi için aynı özellikleri inceleyin.

> **Çözüm (derste verildi):** Belleksiz, nedensel, lineer, zamanla değişen, kararsız ($n$ büyüdükçe çıkış sınırsızlaşır).

**Soru 10** (ekrandan, 01:45:00): $g[n]=\sin(2\pi n/7)(1+n^2)$ sinyalinin tek ve çift kısımlarını bulun.

> **Çözüm (derste verildi):** $g_e[n]=0$, $g_o[n]=\sin(2\pi n/7)(1+n^2)$; sinyal tektir.

**Soru 11** (ekrandan, 01:50:00): $x(t)=u(t)-u(t-3)$ ve $h(t)=u(t)-u(t-2)$ için $y(t)=x(t)*h(t)$'yi analitik olarak bulun ve çizin.

> **Çözüm (derste verildi):** $y(t)=t\,u(t)-(t-2)u(t-2)-(t-3)u(t-3)+(t-5)u(t-5)$; $0$–$2$ artan, $2$–$3$ arası 2'de sabit, $3$–$5$ azalan, $t\ge5$ için 0.

**Soru 12** (ekrandan, 02:15:00): $x[n]=\delta[n]+\delta[n-1]+\delta[n-2]+\delta[n-3]$ ve $y[n]=\delta[n]+\delta[n-1]+\delta[n-2]$ için $x[n]*y[n]$'yi bulun.

> **Çözüm (derste verildi):** $\delta[n]+2\delta[n-1]+3\delta[n-2]+3\delta[n-3]+2\delta[n-4]+\delta[n-5]$, yani $\{1,2,3,3,2,1\}$.

**Soru 13** (ekrandan, 02:30:00): Periyodu $T_0$, genliği $A$ olan ve $|t|<T_0/4$'te $A$, periyodun geri kalanında 0 olan kare dalganın Fourier serisi katsayılarını bulun.

> **Çözüm (derste verildi, düzeltmeli):** $c_k=\frac{A}{k\pi}\sin\frac{k\pi}{2}$, $c_0=\frac A2$. Sinyal çift olduğu için $b_k=0$, $a_k=\frac{2A}{k\pi}\sin\frac{k\pi}{2}$ (bkz. Bölüm 13.3'teki ders sonrası not).

**Soru 14** (ekrandan, 02:40:00; ödev sorusu): $X(\Omega)=1$, $|\Omega|\le W$; $X(\Omega)=0$, $W<|\Omega|\le\pi$ biçiminde tanımlı ($2\pi$ periyotlu) dikdörtgen spektrumun ters Fourier dönüşümü $x[n]$'yi bulun ve $W=\pi/4$ için $x[n]$'yi çizin. Ödevde integral elle çözülecek, sonuç üç farklı $W$ değeri için MATLAB ya da Python'da `stem` ile çizdirilecekti. Ekrandaki beklenen grafikte $W=\pi/4$ için $x[0]=1/4$ tepe değeri ve iki yana doğru salınarak sönen örnekler görülüyor.

> **Çözüm (derste verilmedi):** $x[n]=\frac1{2\pi}\int_{-W}^{W}e^{j\Omega n}d\Omega=\frac{1}{2\pi}\cdot\frac{e^{jWn}-e^{-jWn}}{jn}=\frac{\sin(Wn)}{\pi n}$, $n\ne0$; $x[0]=\frac{W}{\pi}$. $W=\pi/4$ için $x[0]=0.25$, $x[\pm1]\approx0.2251$, $x[\pm2]\approx0.1592$, $x[\pm3]\approx0.0750$, $x[\pm4]=0$ (python ile sayısal integralle doğrulandı). Sıfırlar $n=\pm4,\pm8,\dots$ noktalarındadır.

**Soru 15** (ekrandan, 02:50:00): $y'(t)+2y(t)=x(t)+x'(t)$ ile tanımlı sistemin frekans cevabını ve dürtü cevabını bulun.

> **Çözüm (derste verildi, düzeltmeli):** $H(\omega)=\frac{1+j\omega}{2+j\omega}=1-\frac1{2+j\omega}$, $h(t)=\delta(t)-e^{-2t}u(t)$.

## Dersin Toparlaması

Bu derste dönemin bütün ana konuları soru çözümüyle tekrar edildi. Sinyal işlemlerinde öteleme ile ters çevirmenin sırası (önce öteleme, sonra $n\to-n$), genlikte çarpma ile zamanda çarpmanın farkı ve $A\,g((t-t_0)/a)$ için genel işlem sırası vurgulandı. Örnekleme konusunda $t$ yerine $nT_s$ (ya da $n/f_s$) yazılarak ayrık denklemin nasıl elde edildiği, Nyquist şartı ve EBOB/EKOK ile temel frekans ve periyot hesabı gösterildi. Enerji/güç sınıflandırması, basamak ve dürtüyle pencereleme ve örnekleme, türevin dürtü üretmesi ve sistem özelliklerinin (bellek, nedensellik, linearlik, zamanla değişmezlik, kararlılık) adım adım test edilmesi çalışıldı.

İkinci yarıda tek/çift kısım ayrıştırması, analitik ve ayrık konvolüsyon, Fourier serisinin üstel ve trigonometrik biçimleri (kare dalga örneğiyle) ve Fourier dönüşümünün türev, öteleme ve konvolüsyon özellikleri ele alındı. Bu özelliklerle bir diferansiyel denklemin frekans cevabı ve dürtü cevabı doğrudan bulundu. Ayrık zamanlı karşılığı olan fark denkleminin DTFT ile çözümü ve dikdörtgen spektrumun ters DTFT'si (ödev) bir sonraki çalışmaya bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
