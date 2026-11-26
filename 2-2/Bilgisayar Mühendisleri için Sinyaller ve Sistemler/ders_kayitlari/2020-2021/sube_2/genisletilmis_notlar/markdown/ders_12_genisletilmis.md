# Ders 12 Genişletilmiş Notu: Sinyaller ve Sistemlerin Müfredattaki Yeri ve Birinci Ara Sınav Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu kayıt birinci ara sınavın yapıldığı oturumdur ve yeni konu anlatılmamıştır. Notta yalnız iki akademik parça yer alır: hocanın sınav öncesinde dersin mühendislik müfredatındaki yerini anlattığı bölüm ve ekranda gösterilen sınav soruları. Sınav düzeni ve teslim ayrıntıları nota alınmamıştır.

## İçindekiler

- 1. Sınava hazırlık için hocanın akademik hatırlatmaları
- 2. Sinyaller ve Sistemler dersinin müfredattaki yeri
- 3. Disiplinler arası çalışma ve bilgisayar mühendisinin payı
- Örnek Sorular
- Dersin Toparlaması

## 1. Sınava hazırlık için hocanın akademik hatırlatmaları

Hoca, sınav sorularının derste anlatılan ve çözülen örneklere çok benzediğini söyledi. Fourier katsayısı sorusu için kısmi integrasyon ($u$ ve $v$ seçimi) bilmenin yeteceğini, hatta bu sınavda ona bile gerek kalmayabileceğini belirtti. Formül zaten verilmiştir; yapılacak iş değişkenleri formülde yerine koymaktır.

> **Hocanın vurgusu:** Bu ders formül ya da kural ezberletmeyi amaçlamaz. Formülü bilip doğru yerine koymak yeterlidir.

Çözümlerin nasıl yazılacağına dair akademik uyarılar da yaptı:

- Grafik okuma sorularında sonucu doğrudan yazmak yerine nasıl bulunduğu kısa bir açıklamayla gösterilmelidir.
- Konvolüsyon "analitik çözüm" biçiminde, adım adım yapılmalıdır: hangi örnekle hangi örneğin çarpıldığı ve toplandığı görünmelidir. Formül biçimi ya da tablo biçimi seçilebilir.
- Fourier katsayısı sorusunda doğrudan formülden başlanır.
- Uzun ve gereksiz açıklama doğru çözüm anlamına gelmez; kısa, sonucu açıklayan ve belirten açıklamalar yeterlidir.

## 2. Sinyaller ve Sistemler dersinin müfredattaki yeri

Hoca sınav başlamadan önce ekranda bir kavram haritası çizdi (ekrandan, 00:25:00). Haritanın ortasında "S.S" (Sinyaller ve Sistemler) kutusu vardır.

### 2.1 Ortak konu olarak sinyal

Kontrolcülerin, elektrikçilerin, elektronikçilerin, biyomedikal mühendislerinin, bilgisayar mühendislerinin ve hatta zaman serileriyle uğraşan iktisatçıların ortak konusu sinyaldir. Bu yüzden Sinyaller ve Sistemler dersi bu alanların tam ortasında durur; hocanın deyişiyle "birçok şeyin göbeği"dir, öncesi ve sonrası vardır.

### 2.2 Öncesindeki dersler

Haritada S.S kutusunun üstünde onu besleyen dersler yer alır: mühendislik matematiği, diferansiyel denklemler, lineer cebir ve olasılık; bunlardan önce de kalkülüs. Devre teorisi kısmen ilgilidir ama çok fazla değil.

### 2.3 Sonrasındaki dersler

S.S kutusunun altında üç kol vardır (ekrandan, 00:25:00):

| Kol | Dersler |
|---|---|
| Bilgisayar mühendisliği | DSP (sayısal işaret işleme), görüntü işleme, video işleme, konuşma işleme, makine öğrenmesi |
| Kontrol ve elektronik | Otomatik kontrol sistemleri (ACS), sayısal kontrol sistemleri (DCS), DSP |
| Haberleşme | DSP, analog ve sayısal haberleşme sistemleri |

Bilgisayar mühendisliği kolunda yol DSP ile başlar, görüntü işleme, video ve konuşma işleme ile makine öğrenmesine kadar gider. Bu derslerin başına "ileri" (advanced DSP, advanced image processing gibi) eklenmiş sürümleri de vardır.

Kontrol ve elektronik kolunda otomatik kontrol sistemleri sürekli zamanlı sistemleri inceler. Sayısal (dijital) kontrol sistemleri ise ayrık zamanlı sistemlerle uğraşır ve DSP ile birlikte kullanılır.

Haberleşme kolunda analog ve sayısal haberleşme sistemleri dersleri vardır. Burada da "sistem" kelimesi geçer.

### 2.4 Sistem bağlantısı: kontrol ve haberleşme farkı

Haritanın yanında hoca art arda bağlanmış kutular çizdi (ekrandan, 00:25:00). Derste sistemler art arda bağlanır; bu bağlantıda bir geri besleme (feedback) varsa konu kontrol sistemlerine girer. Haberleşme sistemlerinde ise sistem geri beslemeli değildir; art arda gelen elemanlar zinciri olarak düşünülür.

### 2.5 Kalan konular ve örnekleme

Hoca dersin kalan kısmında z-dönüşümü ve Laplace dönüşümünün işleneceğini söyledi. Biri ayrık zamanda, diğeri sürekli zamanda kullanılan tekniklerdir ve Fourier dönüşümünü tamamlarlar. Örnekleme (sampling) konusuna da kısaca değinilecektir; ama örnekleme daha çok sayısal işaret işlemenin konusudur.

> **Ek bilgi (derste anlatılmadı):** Laplace dönüşümü $X(s)=\int x(t)e^{-st}dt$, $s=\sigma+j\omega$ ile Fourier dönüşümünü genelleştirir; $\sigma=0$ alındığında Fourier dönüşümüne iner. z-dönüşümü $X(z)=\sum_n x[n]z^{-n}$ ise ayrık zamanda aynı rolü oynar; $z=e^{j\omega}$ birim çember üzerinde ayrık zamanlı Fourier dönüşümünü verir.

## 3. Disiplinler arası çalışma ve bilgisayar mühendisinin payı

Hocaya göre teorik çalışmak ya da farklı alanlara yönelmek isteyenlerin yolu bir şekilde sinyal ve sistemlerle kesişir. Web programlama, ön yüz ve arka yüz geliştirme gibi alanlar ayrı bir konudur; ama işin içine matematik girdiğinde sinyaller ve onlarla birlikte Fourier, Laplace gibi araçlar devreye girer, çünkü bir sistemle uğraşılmaktadır.

Çok disiplinli bir tasarım projesinde bir sistemin tasarlanması, girişlerinin ve çıkışlarının alınması gerekir. Bilgisayar mühendisinin orada yapacağı bir iş, kontrolcünün yapacağı başka bir iş vardır. Hoca burada ölçünün kaçırılmaması gerektiğini vurguladı: bilgisayar mühendisi bilgisayar mühendisi kadar, elektronikçi elektronikçi kadar bilmelidir. Herkes herkesin işine kalkıştığında kimse bir şey yapamaz. Kontrol sistemlerinde kararlılık, PID kontrolörler gibi çok sayıda konu vardır; bunların hepsini bilmek bilgisayar mühendisinden beklenmez.

## Örnek Sorular

Aşağıdaki dört soru ekranda gösterilen birinci ara sınav sorularıdır (ekrandan, 00:35:00). Çözümler derste verilmedi; ajan tarafından yazıldı ve python ile kontrol edildi.

### Soru 1

(ekrandan, 00:35:00) a) Grafiği verilen $x(t)$ işaretinin sinüzoidal ifadesini $x(t)=A\cos(\omega t+\theta)$ biçiminde yazınız ($A$, $\omega$ ve $\theta$ bulunacaktır). b) Bu işareti örneklemek istesek en düşük örnekleme frekansı ne olmalıdır?

Grafikten okunanlar: yatay eksen $-0.02$ s ile $0.06$ s arasıdır. İşaret $t=-0.02$ s'de 0'dan başlar, $t=-0.01$ s'de $+20$ tepe değerine, $t=0.01$ s'de $-20$ değerine iner, $t=0.03$ s'de yine $+20$, $t=0.05$ s'de $-20$ olur. $t=0$ anında 0'dır ve azalmaktadır.

> **Çözüm (derste verilmedi):**
> - Genlik: $A=20$.
> - Ardışık iki tepe $t=-0.01$ s ve $t=0.03$ s'dedir, periyot $T=0.04$ s, frekans $f=25$ Hz, $\omega=2\pi f=50\pi$ rad/s.
> - Tepe $t=-0.01$ s'de olduğundan $x(t)=20\cos\big(50\pi(t+0.01)\big)=20\cos(50\pi t+\pi/2)$, yani $\theta=\pi/2$ rad. Kontrol: $x(0)=20\cos(\pi/2)=0$, $x(0.01)=20\cos(\pi)=-20$.
> - Eşdeğer biçim: $x(t)=-20\sin(50\pi t)$.
> - b) Nyquist ölçütüne göre $f_s\ge 2f_{max}=2\cdot 25=50$ Hz. En düşük örnekleme frekansı 50 Hz'dir.

> **Ek bilgi (derste anlatılmadı):** Saf bir sinüzoid tam $2f$ ile örneklenirse örnekler sıfır geçişlerine denk gelebilir (bu soruda $x(n/50)=-20\sin(\pi n)=0$). Bu yüzden uygulamada $f_s>2f_{max}$ alınır.

### Soru 2

(ekrandan, 00:35:00) Aşağıda verilen $x(t)$ işareti için $x(-t/2)$, $x(2(t+2))$ ve $x(-t+1)$ işaretlerini çiziniz.

Şekilden okunan $x(t)$: $t=-1$'de 0'dan başlayıp doğrusal olarak artar, $t=0$'da tepe değeri 1'e ulaşır, sonra doğrusal olarak azalıp $t=2$'de 0 olur; başka yerde 0'dır.

$$x(t)=\begin{cases} t+1, & -1\le t\le 0\\ 1-\dfrac{t}{2}, & 0\le t\le 2\\ 0, & \text{diğer}\end{cases}$$

> **Çözüm (derste verilmedi):** Her dönüşümde $x$'in köşe noktaları ($-1$, $0$, $2$) argümana eşitlenerek yeni $t$ değerleri bulunur.
>
> | İşaret | Argüman $=-1$ (değer 0) | Argüman $=0$ (değer 1) | Argüman $=2$ (değer 0) | Sıfırdan farklı aralık |
> |---|---|---|---|---|
> | $x(-t/2)$ | $t=2$ | $t=0$ | $t=-4$ | $-4\le t\le 2$ |
> | $x(2(t+2))=x(2t+4)$ | $t=-2.5$ | $t=-2$ | $t=-1$ | $-2.5\le t\le -1$ |
> | $x(-t+1)$ | $t=2$ | $t=1$ | $t=-1$ | $-1\le t\le 2$ |
>
> - $x(-t/2)$: ters çevrilmiş ve 2 kat genişletilmiş üçgen. $-4\le t\le 0$ aralığında $1+t/4$, $0\le t\le 2$ aralığında $1-t/2$.
> - $x(2t+4)$: 2 kat sıkıştırılmış ve 2 birim sola kaydırılmış üçgen. $-2.5\le t\le -2$ aralığında $2t+5$, $-2\le t\le -1$ aralığında $-t-1$.
> - $x(-t+1)$: ters çevrilmiş ve tepe noktası $t=1$'e kaydırılmış üçgen. $-1\le t\le 1$ aralığında $(1+t)/2$, $1\le t\le 2$ aralığında $2-t$.

### Soru 3

(ekrandan, 00:35:00) Aşağıda verilen $x[n]$ girişi ve $h[n]$ impuls cevabı için çıkışı ($y[n]$) konvolüsyon işlemi yaparak bulunuz: $y[n]=x[n]*h[n]=\sum_{k=-\infty}^{\infty}x[k]h[n-k]$.

Şekilden okunan değerler:

| $n$ | $-2$ | $-1$ | $0$ | $1$ | $2$ |
|---|---|---|---|---|---|
| $x[n]$ | 0 | 2 | 3 | 2 | 1 |
| $h[n]$ | 2 | $-1$ | 1 | $-2$ | 0 |

> **Çözüm (derste verilmedi):** $x[n]$, $n=-1..2$; $h[n]$, $n=-2..1$ aralığındadır. Çıkış $n=-3$'ten $n=3$'e kadar $4+4-1=7$ örnek uzunluğundadır.
>
> - $y[-3]=x[-1]h[-2]=2\cdot2=4$
> - $y[-2]=x[-1]h[-1]+x[0]h[-2]=-2+6=4$
> - $y[-1]=x[-1]h[0]+x[0]h[-1]+x[1]h[-2]=2-3+4=3$
> - $y[0]=x[-1]h[1]+x[0]h[0]+x[1]h[-1]+x[2]h[-2]=-4+3-2+2=-1$
> - $y[1]=x[0]h[1]+x[1]h[0]+x[2]h[-1]=-6+2-1=-5$
> - $y[2]=x[1]h[1]+x[2]h[0]=-4+1=-3$
> - $y[3]=x[2]h[1]=-2$
>
> Sonuç: $y[n]=\{4,\,4,\,3,\,\underline{-1},\,-5,\,-3,\,-2\}$ (altı çizili örnek $n=0$). Kontrol: $\sum y=0=\left(\sum x\right)\left(\sum h\right)=8\cdot 0$.

### Soru 4

(ekrandan, 00:35:00) Aşağıda verilen periyodik fonksiyonun karmaşık (kompleks) üstel formdaki Fourier katsayılarını ($c_k$) bulunuz:

$$c_k=\frac{1}{T}\int_{t_0}^{t_0+T}x(t)\,e^{-jk\omega_0 t}\,dt$$

Şekilde $x(t)$, her periyodun başında 1 değerinden başlayıp $e^{-t}$ biçiminde azalan darbelerden oluşur; darbeler arasında sinyal sıfırdır. <!-- BELİRSİZ: Karede şeklin alt kısmı ve zaman ekseni kesik; periyot $T$ ve darbe süresi okunamadı. Çözüm genel $T$ ve darbe süresi $a$ ile verildi. -->

> **Çözüm (derste verilmedi):** Bir periyotta $x(t)=e^{-t}$, $0\le t<a$; $a\le t<T$ aralığında $x(t)=0$ alınsın, $\omega_0=2\pi/T$.
>
> $$c_k=\frac{1}{T}\int_0^a e^{-t}e^{-jk\omega_0 t}\,dt=\frac{1}{T}\int_0^a e^{-(1+jk\omega_0)t}\,dt=\frac{1-e^{-(1+jk\omega_0)a}}{T\,(1+jk\omega_0)}$$
>
> - $k=0$ için ortalama değer: $c_0=\dfrac{1-e^{-a}}{T}$.
> - Darbe periyodun yarısını kaplıyorsa ($a=T/2$), $e^{-jk\omega_0 T/2}=e^{-jk\pi}=(-1)^k$ olduğundan $c_k=\dfrac{1-(-1)^k e^{-T/2}}{T\,(1+jk\omega_0)}$.
> - Darbeler arasında boşluk yoksa ($a=T$), $c_k=\dfrac{1-e^{-T}}{T\,(1+jk\omega_0)}$.
>
> Genel formül $a=1$, $T=2$, $k=3$ için sayısal integralle python'da kontrol edildi.

Hocanın bu soru için söylediği gibi integral kısmi integrasyon gerektirmez; üstel çarpanlar birleştirilip tek bir üstel fonksiyonun integrali alınır.

## Dersin Toparlaması

Bu oturumda yeni konu işlenmedi. Hoca, Sinyaller ve Sistemler dersinin mühendislik matematiği, lineer cebir ve diferansiyel denklemler gibi temel derslerin üzerine kurulduğunu; bilgisayar mühendisliğinde DSP, görüntü, video ve konuşma işleme ile makine öğrenmesine, kontrol ve elektronikte otomatik ve sayısal kontrol sistemlerine, haberleşmede analog ve sayısal haberleşme sistemlerine uzanan yolların ortak başlangıcı olduğunu gösterdi. Ara sınav soruları dönemin ilk yarısının dört ana başlığını yokladı: sinüzoid parametreleri ve örnekleme, sürekli zamanlı sinyal dönüşümleri, ayrık zamanlı konvolüsyon ve Fourier serisi katsayıları.

Dersin kalan haftalarında ayrık zaman için z-dönüşümü, sürekli zaman için Laplace dönüşümü işlenecek ve örnekleme konusuna kısaca değinilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
