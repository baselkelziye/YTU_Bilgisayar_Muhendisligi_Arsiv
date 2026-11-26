# Ders 13 Genişletilmiş Notu: Vize Soruları Çözümü ve Laplace Dönüşümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Vize Sorularının Çözümü
- 2. Dönemin Konularına Kısa Bakış
- 3. İntegral Dönüşümler ve Fourier Dönüşüm Çifti
- 4. Fourier Dönüşümünün Uygulamaları
- 5. Fourier Dönüşümünün Eksiği ve Laplace Dönüşümü
- 6. Temel Laplace Dönüşümleri ve Özellikler
- 7. Sinyal Tarafı: Yakınsama Bölgesi (ROC)
- 8. Kutuplar, Sıfırlar ve ROC Kuralları
- 9. Ters Laplace Dönüşümü
- 10. Basit Kesirlere Ayırma
- 11. Konvolüsyon, Türev, İlk ve Son Değer Teoremleri
- 12. Tek Taraflı Laplace ve Diferansiyel Denklem Çözümü
- Örnek Sorular

## 1. Vize Sorularının Çözümü

Ders, bir önceki sınavın sorularının çözümüyle başladı. Hoca çözümleri cevap kâğıdı PDF'i üzerinden gösterdi, bazı adımları da çizim ekranında yeniden yaptı. Soruların tam metni ve çözümleri "Örnek Sorular" bölümündedir; burada anlatımın akışı ve hocanın açıklamaları verilir.

### 1.1 Sinüzoidal işaretin parametreleri

Kosinüs, birim çember üzerinde düşünüldüğünde, açı ne olursa olsun $-1$ ile $+1$ arasında değer alır. Grafikteki işaret $-20$ ile $+20$ arasında salındığına göre, $\cos(\cdot)$'ın önündeki genlik $A=20$ olmalıdır.

Periyot için işaretin kendini tekrar ettiği iki nokta bulunur. Grafikte işaret $-0.02$ s'de bir tepe noktasından geçer ve $0.02$ s'de aynı duruma döner; dolayısıyla $T=0.04$ s'dir. Hoca önce yanlışlıkla $1/0.02$ ile işlem yaptı, sonra grafiğe tekrar bakarak periyodun $0.04$ s olduğunu düzeltti. Frekans $f=1/T=25$ Hz'dir.

Faz, işaretin $t=0$ anındaki konumuyla ilgilidir. Grafikte $x(0)=0$'dır:

$$0=A\cos(2\pi f\cdot 0+\theta)\;\Rightarrow\;\cos\theta=0\;\Rightarrow\;\theta=\frac{\pi}{2}.$$

$A$'nın burada bir etkisi yoktur. Hangi açıda kosinüsün sıfır olduğu birim çemberden ya da hesap makinesinden bulunur. $3\pi/2$ ya da $\pi/2+2\pi$ gibi değerler de kosinüsü sıfır yapar, ama esas ölçü olarak $\pi/2$ (90°) yazılır.

> **Hocanın vurgusu:** Yalnız "$\theta=\pi/2$" yazmak beklenen cevap değildir; $x(0)=0$ koşulundan yapılan bu basit hesabın gösterilmesi beklenir, çünkü faz tam olarak sıfırıncı saniyedeki konumu anlatır.

Sonuç: $x(t)=20\cos(2\cdot25\pi t+\pi/2)=20\cos(50\pi t+\pi/2)$ (ekrandan, 00:15:00).

### 1.2 Zaman dönüşümleri

$x(t)$ üçgen biçimli bir işarettir: $t=-1$'de 0, $t=0$'da 2 (tepe), $t=2$'de 0 (ekrandan, 00:15:00).

- $x(-t/2)$: $-t$ işareti ters çevirir, $/2$ ise işareti iki kat genişletir (streç eder). Sonuç $t=-4$ ile $t=2$ arasında, tepesi $t=0$'da olan üçgendir.
- $x(2(t+2))$: İfade içeri açılıp $x(2t+4)$ yazılabilir; o zaman önce 4 birim öteleme, sonra 2 ile daraltma yapılır. Ya da önce $x(t+2)$ bulunup sonra daraltılır. Sonuç $t=-2.5$ ile $t=-1$ arasında, tepesi $t=-2$'de olan dar bir üçgendir.
- $x(-t+1)$: Önce bir birim öteleme ($x(t+1)$), sonra ters çevirme yapılır. Sonuç $t=-1$ ile $t=2$ arasında, tepesi $t=1$'de olan üçgendir.

### 1.3 Ayrık konvolüsyon

$x[n]=[2\ 3\ 2\ 1]$ dizisi $n=-1..2$, $h[n]=[2\ {-1}\ 1\ {-2}]$ dizisi $n=-2..1$ aralığındadır (ekrandan, 00:25:00). Önce her dizinin sıfır noktası belirlenir: $x$'te sıfırıncı eleman 3, $h$'te sıfırıncı eleman 1'dir.

Kaydırmalı yöntemde bir dizi aynen yazılır, diğeri ters çevrilir ($-2\ 1\ {-1}\ 2$) ve kaydırılarak örtüşen elemanların çarpımları toplanır:

- İlk örtüşme: $2\cdot2=4$.
- İkinci: $3\cdot2+2\cdot(-1)=4$.
- Üçüncü: $2\cdot2+3\cdot(-1)+2\cdot1=3$.
- Dördüncü: $1\cdot2+2\cdot(-1)+3\cdot1+2\cdot(-2)=-1$.
- Beşinci: $1\cdot(-1)+2\cdot1+3\cdot(-2)=-5$.
- Altıncı: $1\cdot1+2\cdot(-2)=-3$.
- Yedinci: $1\cdot(-2)=-2$.

Hoca beşinci terimde önce bir işaret hatası yaptı ($-7$ civarı buldu), sonra diziyi kontrol edip $-5$'e düzeltti. Bazı öğrenciler çarpım tablosu yöntemini kullanmıştı: her eleman her elemanla çarpılır, aynı indise düşen çarpımlar toplanır. Bu yöntem ve formülün doğrudan uygulanması da doğru kabul edildi. Sonucun başlangıç indisi $-1+(-2)=-3$'tür:

$$y[n]=[4\ 4\ 3\ {-1}\ {-5}\ {-3}\ {-2}],\quad n=-3..3\ \text{(ekrandan, 00:20:00)}.$$

### 1.4 Periyodik işaretin Fourier serisi katsayıları

İşaretin periyodu $T=2$ s'dir; $0<t<1$ aralığında $e^{-t}$, $1<t<2$ aralığında 0'dır. Formülde yerine yazmak için önce temel açısal frekans bulunur: $\omega_0=2\pi/T=\pi$ rad/s (ekrandan, 00:20:00).

$$c_k=\frac{1}{T}\int_{t_0}^{t_0+T}x(t)e^{-jk\omega_0t}dt=\frac12\left[\int_0^1e^{-t}e^{-jk\pi t}dt+\int_1^2 0\cdot e^{-jk\pi t}dt\right].$$

İkinci integral sıfırdır. Birinci integralde $t$ ortak parantezine alınır: $e^{-(1+jk\pi)t}$. Bu, $\int e^{-at}dt$ türünden kolay bir integraldir; derste yapılan örneklerde üsteki katsayı $a$ gibi kısa bir şeydi, burada aynısı $1+jk\pi$ ile biraz daha uzun yazılır:

$$c_k=\frac12\cdot\frac{-1}{1+jk\pi}\Big[e^{-(1+jk\pi)t}\Big]_0^1=\frac{1-e^{-1}e^{-jk\pi}}{2(1+jk\pi)}.$$

Son adım için $e^{jk\pi}$ birim çemberden hatırlanır: $e^{jk\pi}=\cos k\pi+j\sin k\pi$. $k$ tam sayı olduğundan $\sin k\pi=0$, $\cos k\pi=(-1)^k$ olur (tek $k$ için $-1$, çift $k$ için $+1$). Böylece:

$$c_k=\frac{1-e^{-1}(-1)^k}{2(1+jk\pi)}.$$

> **Hocanın vurgusu:** İntegral alındıktan sonra sonuçta $t$ kalmamalıdır; sınırlar yerine yazılmalıdır. Sonuçta yalnız $j$, $k$ ve $\pi$ bulunabilir. $k$ ile başlayan bir hesap sonunda $n$ gibi başka bir değişkene dönüşmemelidir.

$e^{(\cdot)}$'li biçimden ne kadar kurtulunursa o kadar iyidir, çünkü $c_k$'lar sinüs ve kosinüslerin katsayılarına dönüştürülecektir. Bir sonraki adım (soruda istenmemişti) $a_k=2\,\mathrm{Re}\{c_k\}$, $b_k=-2\,\mathrm{Im}\{c_k\}$ ve $c_0$ ile trigonometrik Fourier serisini yazmaktır.

## 2. Dönemin Konularına Kısa Bakış

Hoca yeni konuya geçmeden önce o haftaya kadar işlenenleri bir tabloda topladı (ekrandan, 00:30:00). Ders iki parçaya bölünür: sürekli zaman (Continuous Time, CT) ve ayrık zaman (Discrete Time, DT). Aynı kavramlar iki tarafta farklı biçimlerde karşımıza çıkar.

| Sürekli zaman (CT) | Ayrık zaman (DT) |
|---|---|
| Sinyal, ör. $\delta(t)$ | Sinyal, ör. $\delta[n]$ |
| Sistem | Sistem |
| Konvolüsyon | Konvolüsyon |
| Frekans: CTFS, CTFT | Frekans: DTFS (DFT, DFS), DTFT |

- Birim dürtü: sürekli zamanda $t=0$ anında, ayrık zamanda $n=0$ için 1 değerini veren temel işarettir.
- Sistemler için zamanla değişmezlik, doğrusallık, belleklilik, kararlılık gibi özelliklere bakıldı. Doğrusallık daha çok sistemle ilgili bir özelliktir.
- Ayrık zamanlı Fourier serisine bazı kitaplarda Discrete Fourier Transform (DFT) ya da Discrete Fourier Series (DFS) denir. Hoca bu başlıkları "ben böyle bir şey görmedim" denmesin diye andı.

Frekans düzlemine geçmenin en basit faydası konvolüsyonu kolaylaştırmasıdır. Sistemin birim dürtü cevabı $h(t)$ ya da $h[n]$, girişle konvolüsyona girerek sistemin davranışını verir; bir anlamda sistemin "röntgeni" gibidir. Zaman düzleminde konvolüsyon integralinin iki zorluğu vardır: gerçek işaretler parçalı olduğu için integral sınırlarını belirlemek zordur, ve $x(t)$ karmaşıksa integrali almak güçleşir. Ayrıca sınavdan önce diferansiyel denklemle verilen bir sistemin, diferansiyel denklem çözme yöntemlerine gerek kalmadan Fourier dönüşümüyle çözülebildiği görülmüştü.

## 3. İntegral Dönüşümler ve Fourier Dönüşüm Çifti

### 3.1 Genel integral dönüşüm

Burada sözü edilen dönüşümler integral dönüşümlerdir. Bir $f(t)$ işareti verilir ve $\alpha t$ gibi bir parametre içeren bir çekirdek fonksiyonla çarpılıp $t$'ye göre integral alınır:

$$F(\alpha)=\int_{-\infty}^{\infty}f(t)\,K(\alpha t)\,dt.$$

İntegralin sınırları $t$'nin yerine geçtiği için sonuçta $t$'ler kaybolur ve $\alpha$'ya bağlı bir sonuç kalır. Çekirdeğin yerine $e^{-j\omega t}$ yazılırsa Fourier dönüşümü elde edilir; başka bir çekirdek yazılırsa Hartley, Laplace, dalgacık (wavelet) gibi başka dönüşümler çıkar. Hepsinin mantığı aynıdır. Sinyal işlemede Fourier'in seçilmesinin nedeni, zaman düzlemindeki bir işareti doğrudan frekans düzlemine taşıyıp bazı işlemleri kolay yapabilmektir; diğer dönüşümler frekans düzlemine doğrudan geçmez ya da sinyal açısından işe yaramaz.

Ayrık tarafta aynı iş toplam ile yapılır: $N$ elemanlı bir $x[n]$ için $\sum_{n=0}^{N-1}x[n]e^{-j\omega n}$ alınır ve sonuç $\omega$'ya bağlı olur. Kitaplarda notasyon farklıdır ama arka planda yapılan iş aynıdır.

### 3.2 Fourier dönüşüm çifti

Periyodik olmayan sürekli işaretlerin analizi için iki formül vardır: biri Fourier dönüşümü, diğeri ters Fourier dönüşümü.

$$X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt,\qquad x(t)=\frac{1}{2\pi}\int_{-\infty}^{\infty}X(\omega)e^{j\omega t}d\omega.$$

Büyük harf, dönüşüm olduğu anlaşılsın diye kullanılır. İlkinde $t$'ler gider, yerine $\omega$ gelir; ikincisinde $\omega$'lar gider, yerine $t$ gelir.

Zaman düzleminde verilen $x(t)$ işaretine karşılık frekans düzleminde $X(\omega)$ elde edilir. $X(\omega)$'dan frekansa bağlı genlik değişimi ve faz bilgisi çıkarılabilir. Sınavdaki basit işarette faz doğrudan $\cos$'a 0 koyarak bulunabildi; ama bir ses sinyali gibi karmaşık bir işarette fazı zaman düzleminden bulmak zordur. Benzer şekilde işaretin hangi aralıklarda sonsuza ya da sıfıra gittiği, ya da hangi kosinüs bileşenlerini içerdiği zaman görüntüsünden anlaşılamaz.

## 4. Fourier Dönüşümünün Uygulamaları

### 4.1 Telefon tuşları (DTMF)

Telefon tuşlarına basınca farklı tonlarda sesler duyulur. Bu tonlar DTMF adlı bir standarda göre kodlanmıştır: her tuş iki sinüzoidal bileşenin toplamıdır. Örneğin 1 tuşu 697 Hz ve 1209 Hz bileşenlerini içerir. Problem şudur: elimizde tuş seslerinin kaydı (ör. bir ses dosyası) var; hangi tuşlara basıldığını bulmak istiyoruz.

Kaydın zaman grafiğinde yedi ayrı ton patlaması görülür (ekrandan, 00:45:00). Bu görüntüden hangi sinüs ve kosinüs bileşenlerinin olduğu anlaşılamaz. Sınav sorusunda frekansı $1/T$'den bulabildik, çünkü işaret periyodikti; burada işaret periyodik değildir, $T$ bulunamaz.

Çözüm şöyledir: kayıt yedi parçaya bölünür (elle de yapılabilir, diziyi parçalara ayırmak yeterlidir). Her parça periyodikmiş gibi düşünülüp Fourier dönüşümü alınır. MATLAB'daki karşılığı FFT (Fast Fourier Transform) fonksiyonudur.

- Kaydın tamamının FFT'si alınırsa frekans bileşenleri görülür (ör. 700'ler ve 800'e yakın tepeler), ama hangi frekansın hangi zaman aralığına ait olduğu bilinmez. Frekans elde edilirken zaman bilgisi kaybolur.
- Parçaların ayrı ayrı FFT'si alınırsa her parçada iki tepe görülür. İlk parçada tepeler yaklaşık 840-850 Hz ve 1300 küsur Hz'dedir; kod tablosunda 852 Hz ve 1336 Hz, 8 tuşuna karşılık gelir. İkinci parçada yaklaşık 770 Hz ve 1477 Hz civarı tepeler 6 tuşunu verir.
- Spektrogram, işareti frekans değişimine göre kendisi parçalara ayırıp her parçanın frekans içeriğini otomatik gösteren bir yöntemdir. Grafikteki parlak noktalar tepe frekanslarıdır.

> **Ek bilgi (derste anlatılmadı):** DTMF tablosunda satır frekansları büyük olasılıkla 697, 770, 852 ve 941 Hz, sütun frekansları 1209, 1336, 1477 ve 1633 Hz'dir. Her tuş bir satır ve bir sütun frekansının toplamıdır; örneğin 8 tuşu 852 Hz + 1336 Hz, 6 tuşu 770 Hz + 1477 Hz'dir.

**Soru:** Filmlerde konuşma sırasında arayan numaranın ya da yerin tespit edilmesi bununla aynı şey mi? **Cevap:** Hayır. Buradaki veri tuşlara basınca çıkan tonların kaydıdır. Arka planda tuş sesi geliyorsa bu yöntemle tespit edilebilir. Yer tespiti ise GPS gibi konum bilgisiyle ya da daha önceki ses kayıtlarından kişinin sesini tanıyarak yapılır. Bankaların ses tanıma sistemleri, Google'ın konuşmayı yazıya çeviren (speech to text) hizmeti ve konuşmacı tanıma da arka planda frekans analizi yapar; konuşma fonemlere, hecelere, harflere ya da kelimelere ayrılıp sözlükten bakar gibi eşleştirilir. Bu işlere makine öğrenmesi de girer. Kişinin sesinden yorgunluk ya da ruh hâli analizi (mod analizi) gibi uygulamaların arkasında da Fourier dönüşümü vardır.

### 4.2 Müzik, nota ve tını

Müzik türü sınıflandırma (pop, rock, klasik) ya da bir Türk müziği parçasının makamını bulma gibi işlerde de frekans analizi kullanılır. Aynı nota farklı çalgılarda farklı tınıda duyulur; tınılar arasındaki farkı yakalamak ayırt ediciliği verir.

Hoca bir müzik bilgi erişimi (Music Information Retrieval) sayfasındaki örneği açtı ve sesi paylaşarak çaldı (ekrandan, 00:55:00):

- Bilgisayarda sentezlenmiş C6 notasının spektrumunda yaklaşık 1047 Hz'de tek bir tepe vardır. Bu "temiz" notadır.
- Aynı notayı obua (flüte benzeyen bir çalgı) çaldığında 1047 Hz'deki tepe yine baskındır, ama çalgıya özgü ek frekans bileşenleri de vardır.
- Klarnette de ek detaylar görülür, ama 1047 Hz yine baskındır.

Sayfadaki kodda ses `librosa.load` ile yüklenip bir bölümünün spektrumu `scipy.fft` ile alınıyor ve genliği (`numpy.absolute`) çiziliyordu (ekrandan, 00:55:00):

```python
X = scipy.fft(x[10000:14096])
X_mag = numpy.absolute(X)
plt.figure(figsize=(14, 5))
plt.plot(f[:2000], X_mag[:2000]) # magnitude spectrum
plt.xlabel('Frequency (Hz)')
```

Baskın olan, sese karakterini veren bu frekansa pitch (perde) denir. Klarnetten, obuadan, bir insandan ya da makineden duyulsa da müzik kulağı olan biri bunun C6 notası olduğunu söyler. Nota tespit eden uygulamalar arka planda FFT alır, küçük bileşenleri bastırıp en baskın birkaç tepeye bakarak notayı bulur.

Son olarak bir işitme testi videosu açıldı. İnsan kulağı yaklaşık 20 Hz ile 20 kHz arasındaki frekansları duyar; test farklı frekanslarda üretilmiş sesler gönderir.

### 4.3 İki boyutlu konvolüsyon ve kaynaklar

Derin öğrenmede kullanılan konvolüsyon, derste görülen konvolüsyonun iki boyutlu hâlidir. Bir görüntü (matris) üzerinde $3\times3$'lük küçük bir filtre matrisi gezdirilir ve her konumda çarpımlar toplanır; burada ters çevirme yapılmaz. Uygun bir filtre görüntüdeki dikey çizgileri bulur; bu bir kenar bulma algoritmasıdır.

Telefon tuşu örneğinin elle parçalama yapılan hâli bu dersin düzeyindedir. Spektrogram ve daha ileri analizler dijital sinyal işleme dersinin konusudur.

Hoca ders hazırlığında beş altı kitaptan yararlandığını söyledi ve şu kaynakları andı: Schaum serisi kitabı, Signal Processing First (DSP First), M. J. Roberts'ın kitabı (çok ayrıntılı, elektrik/elektronikçiye anlatır gibi) ve Oppenheim'ın kitabı. Çalışmak için Schaum ve Oppenheim'ı önerdi. <!-- BELİRSİZ: altyazıda kitap adları bozuk yazılmış ("Xiaomi serisi", "Nesso", "Shams"); Schaum ve Oppenheim büyük olasılıkla doğru, "Nesso" anlaşılamadı. -->

## 5. Fourier Dönüşümünün Eksiği ve Laplace Dönüşümü

### 5.1 Fourier dönüşümünün eksiği

Fourier dönüşümünün formülüne tekrar bakalım: $X(\omega)=\int_{-\infty}^{\infty}x(t)e^{-j\omega t}dt$. Sınır olarak $t=+\infty$ yazıldığında üstel terim $e^{-j\omega\infty}$, hoca bunu $1/e^{(\cdot)\infty}$ gibi yorumlayarak sıfıra gittiğini söyledi. Ama $t=-\infty$ yazıldığında $e^{+j\omega\infty}$ gibi bir terim çıkar ve hocanın anlatımıyla bu sonsuza gider. Sonsuza giden bir şeyin enerjisi hesaplanamaz; dolayısıyla bazı işaretlerin Fourier dönüşümü alınamaz.

Fourier dönüşümünün var olma şartı tahtada şöyle yazıldı (ekrandan, 01:05:00):

$$\int_{-\infty}^{\infty}|x(t)|\,dt<\infty.$$

> **Ders sonrası not:** Hoca şartı sözlü olarak "eksi sonsuzdan artı sonsuza kadar sıfırdan küçük olması gerekir" diye söyledi; doğrusu tahtadaki gibi integralin sonlu ($<\infty$) olmasıdır. Ayrıca $|e^{\pm j\omega t}|=1$ olduğu için ıraksamaya asıl neden olan, büyük olasılıkla $e^{at}$ gibi büyüyen işaretlerin kendisidir; $e^{-\sigma t}$ çarpanı bu büyümeyi bastırır.

### 5.2 Laplace dönüşümü

Bu sorunun üstesinden gelmek için Fourier dönüşümünün genelleştirilmiş hâli olan Laplace dönüşümü kullanılır. $j\omega$ yerine karmaşık bir $s$ parametresi konur (ekrandan, 01:05:00):

$$s=\sigma+j\omega,\qquad X(s)=\int_{-\infty}^{\infty}x(t)e^{-st}dt.$$

$\mathrm{Re}\{s\}=\sigma$, $\mathrm{Im}\{s\}=\omega$ (tahtada $j\omega$ olarak yazıldı). $\sigma=0$ alınırsa doğrudan Fourier dönüşümüne dönülür.

> **Ders sonrası not:** Hoca $s$'yi "bir tam sayı bileşeni bir de karmaşık sayı bileşeni" olarak tarif etti; doğrusu $\sigma$'nın gerçel (reel) sayı olmasıdır, tam sayı olması gerekmez.

Sezgisel anlamı şudur: Altındaki alan sonsuza giden bir işaret düşünelim. Bu işaret, $t=0$'da genliği 1 olan ve sonsuzda sıfıra inen azalan bir üstelle çarpılırsa, yani "tepesine vurulup bastırılırsa", çarpım sıfıra doğru azalan ve enerjisi sınırlı bir işaret olur (ekrandan, 01:05:00). Laplace, sonsuz durumdaki bir işareti sonlu duruma çevirip sonra frekans analizi yapar.

Üstel terim ayrılarak bu açıkça görülür:

$$X(s)=\int_{-\infty}^{\infty}x(t)e^{-(\sigma+j\omega)t}dt=\int_{-\infty}^{\infty}\big[x(t)e^{-\sigma t}\big]e^{-j\omega t}dt.$$

Bu, $x(t)e^{-\sigma t}$ işaretinin Fourier dönüşümüdür. **Soru:** İşaret bozulmuş olmuyor mu? **Cevap:** Esasında işaretin aslı değişir; ama Fourier dönüşümündeki amaç işaretin içindeki sinüs ve kosinüsleri, temel frekansları bulmaktır. $e^{-\sigma t}$ çarpanı bu bileşenleri değiştirmez, yalnız işareti bastırıp sonlu hâle getirir.

> **Hocanın vurgusu:** Fourier dönüşümü varken neden Laplace dönüşümüne ihtiyaç duyulduğu önemlidir: Fourier dönüşümü alınamayan (ıraksayan) işaretler için.

Laplace dönüşümü de Fourier gibi doğrusaldır ve Fourier'deki konvolüsyon ve diferansiyel denklem kolaylıklarının hepsi burada da vardır. Ters Laplace dönüşümü integral üzerinden değil, tablolar ve özelliklerle daha kolay bir yoldan yapılacaktır.

## 6. Temel Laplace Dönüşümleri ve Özellikler

### 6.1 İntegral şartı ve bir sabitin dönüşümü

Tahtada önce şu yazıldı (ekrandan, 01:25:00): $X(s)=\int x(t)e^{-st}dt=\int x(t)e^{-(\sigma+j\omega)t}dt$. Üstteki ifadenin içeriğinin pozitif olması beklenir, öyle ki önündeki eksiyle çarpılınca sonuç negatif olsun ve sınır yerine yazılınca Fourier'deki sorun yaşanmasın. Kısaca $\mathrm{Re}\{s\}>0$ istenir. Bu şartı sağlayan bölgeye Region of Convergence (ROC), yani yakınsama bölgesi denir. İşaret belli bir noktada oturup sıfıra yaklaşır; bunu sağlayan $\sigma$ değerleri ROC'u verir.

**Soru:** Her seferinde bu integral mi hesaplanacak? **Cevap:** Hayır. Fourier dönüşüm tablolarında olduğu gibi Laplace dönüşüm tabloları vardır. Temelde 5-6 işaret ve birkaç özellikle bütün dönüşümler çözülebilir.

Bir kez ispat olarak sabit bir $a$'nın dönüşümü gösterildi. Zamanın negatif değerleri olmadığından integral $0$'dan $\infty$'a alınır:

$$\mathcal{L}\{a\}=a\int_0^{\infty}e^{-st}dt=a\left[\frac{e^{-st}}{-s}\right]_0^{\infty}=0+\frac{a}{s}=\frac{a}{s}.$$

$t=\infty$'da $e^{-s\infty}=1/e^{s\infty}\to0$, $t=0$'da $e^0=1$ gelir.

### 6.2 Dört temel dönüşüm

Tahtadaki tablo (ekrandan, 01:35:00):

| $f(t)$ | $F(s)$ |
|---|---|
| $a$ | $\dfrac{a}{s}$ |
| $t^n$ | $\dfrac{n!}{s^{n+1}}$ |
| $e^{at}$ | $\dfrac{1}{s-a}$ |
| $\sin at$ | $\dfrac{a}{s^2+a^2}$ |
| $\cos at$ | $\dfrac{s}{s^2+a^2}$ |

Sabit de aslında $t^0$'dır. Ters dönüşümde bu tablo tersten okunacaktır: paydada yalnız $s$ varsa sabit, $s^n$ varsa polinom, $s-a$ gibi bir şey varsa üstel, $s^2+a^2$ varsa sinüs ya da kosinüs akla gelir. "Kosinüsün $s$'si" payda $s$ bulunmasından hatırlanır.

Doğrusallık: $\mathcal{L}\{a f(t)\pm b g(t)\}=a\,\mathcal{L}\{f(t)\}\pm b\,\mathcal{L}\{g(t)\}$ (ekrandan, 01:35:00).

### 6.3 Örnekler

Tahtadaki örnekler (ekrandan, 01:35:00 ve 01:40:00):

- $\mathcal{L}\{5t-5\}=\mathcal{L}\{5t\}-\mathcal{L}\{5\}=5\cdot\frac{1!}{s^2}-\frac{5\cdot0!}{s^1}=\frac{5}{s^2}-\frac{5}{s}$. Sabit, sıfırıncı dereceden polinom gibi düşünülebilir ($0!=1$).
- $\mathcal{L}\{5t^3\}=5\cdot\frac{3!}{s^4}$. Hoca önce paydayı yanlışlıkla $t^4$ dedi, bir öğrencinin uyarısıyla $s^4$ olarak düzeltti.
- $\mathcal{L}\{e^{-3t}\}=\frac{1}{s-(-3)}=\frac{1}{s+3}$, $\mathcal{L}\{e^{3t}\}=\frac{1}{s-3}$. Üsteki eksi paydada artı, artı ise eksi olur.
- $\mathcal{L}\{2\sin5t\}=2\cdot\frac{5}{s^2+25}=\frac{10}{s^2+25}$.
- $\mathcal{L}\{6\cos3t\}=6\cdot\frac{s}{s^2+9}$.

Tersten düşünme örneği olarak $\frac{9}{s^2+2}$ ele alındı (ekrandan, 01:35:00). Payda $s^2+(\sqrt2)^2$ olarak yazılabilir; bu, $\sin(\sqrt2\,t)$'ye benzer. $\sin(\sqrt2\,t)$'nin dönüşümünde payda $\sqrt2$ olurdu; burada 9 var. Demek ki $\sqrt2$'ye bölünmüş ve 9 ile çarpılmıştır:

$$\frac{9}{s^2+2}=\frac{9}{\sqrt2}\cdot\frac{\sqrt2}{s^2+(\sqrt2)^2}\;\Rightarrow\;\frac{9}{\sqrt2}\sin(\sqrt2\,t).$$

### 6.4 Üstel ile çarpma (frekansta öteleme)

İşaretler çoğu zaman tek başına gelmez. Bir $f(t)$, $e^{at}$ ile çarpılırsa integrale gidip uzun hesap yapmak yerine şu kural kullanılır (ekrandan, 01:40:00):

$$\mathcal{L}\{e^{at}f(t)\}=F(s-a).$$

$s$ görülen her yere $s-a$ yazılır. İspatı basittir: integralde $e^{at}$ ile $e^{-st}$ birleşir ve $e^{-(s-a)t}$ olur.

- $5t^3e^{-5t}$: $5t^3$'ün dönüşümü $5\cdot3!/s^4$'tür. $a=-5$ olduğundan $s$ yerine $s+5$ yazılır: $\frac{5\cdot3!}{(s+5)^4}=\frac{30}{(s+5)^4}$ (ekrandan, 01:40:00).
- $2\sin(5t)e^{3t}$: $\frac{10}{s^2+25}$ ifadesinde $s$ yerine $s-3$ gelir: $\frac{10}{(s-3)^2+25}$. Böyle bir ifade görülünce $s$'nin yalnız başına karesi olmadığı için yanında bir üstel çarpan olduğu anlaşılır.

### 6.5 $t^n$ ile çarpma

$$\mathcal{L}\{t^nf(t)\}=(-1)^n\frac{d^n}{ds^n}F(s)\quad\text{(ekrandan, 01:40:00)}.$$

$f(t)$'nin dönüşümü biliniyorsa, $t^3$ ile çarpılmış hâli için $F(s)$'nin üçüncü türevi alınıp $(-1)^3$ ile çarpılır. $\cos$, $t^n$ ve $e^{-t}$'nin çarpımı gibi bir ifadenin integralini almak kısmi integrasyon ve değişken dönüşümleri gerektirir; bunun yerine türev almak çok daha kolaydır. Pratikte türev derecesi genelde 1 ya da 2 olur.

Örnek: $\mathcal{L}\{t\sin2t\}$. $\mathcal{L}\{\sin2t\}=\frac{2}{s^2+4}$. Bölümün türevi alınır: payın türevi sıfır olduğundan yalnız $-\frac{2\cdot2s}{(s^2+4)^2}$ kalır, önündeki $(-1)$ ile çarpılınca (ekrandan, 02:20:00):

$$\mathcal{L}\{t\sin2t\}=(-1)\frac{d}{ds}\left(\frac{2}{s^2+4}\right)=\frac{4s}{(s^2+4)^2}.$$

Bunun ters dönüşümü öncekiler kadar kolay değildir; ayrı bir teknik gerekir. Bilinmesi gerekenler dönüşüm tablosu ve şu özelliklerdir: doğrusallık, $e^{at}$ ile çarpma ve $t^n$ ile çarpma.

## 7. Sinyal Tarafı: Yakınsama Bölgesi (ROC)

### 7.1 $u(t)$ ve tablolardaki fark

İnternette Fourier ya da Laplace dönüşüm tablosu arandığında bazılarında $u(t)$ bulunur, bazılarında bulunmaz. $u(t)$'li tablolar sinyal işlemeyle uğraşanların hazırladığı kaynaklardır. Matematikçi ifadeyi normal bir integral gibi düşünür; sinyallerde ise özel durumlardan yararlanılır: zaman sıfırdan başlatılır, sistemlerde gelecek veriler değil geçmiş veriler işe yarar. Bu yüzden $u(t)$'nin bazı kaynaklarda görünüp bazılarında görünmemesi kafa karıştırmamalıdır.

### 7.2 Temel sinyallerin dönüşümleri

Tahtadaki liste (ekrandan, 01:50:00):

| İşaret | Dönüşüm | ROC |
|---|---|---|
| $\delta(t)$ | $1$ | tüm $s$ |
| $A\delta(t)$ | $A$ | tüm $s$ |
| $u(t)$ | $\dfrac1s$ | $\mathrm{Re}\{s\}>0$ |
| $-u(-t)$ | $\dfrac1s$ | $\mathrm{Re}\{s\}<0$ |
| $-e^{-at}u(-t)$ | $\dfrac{1}{s+a}$ | $\mathrm{Re}\{s\}<-\mathrm{Re}\{a\}$ |

$\delta(t)$ integralde yalnız sıfırda bir değere sahip olduğu için dönüşümü 1'dir. $u(t)$, sıfırdan başlayıp 1 değerinde devam ettiği için sabit gibi davranır ve $1/s$ verir. $u(t)$ pozitif zamanlarda tanımlı olduğu için şartı $\mathrm{Re}\{s\}>0$'dır. $-u(-t)$ ise tam ters davranır: integrali yine $1/s$ verir ama ROC'u $\mathrm{Re}\{s\}<0$ olan bölgedir.

$s$ düzlemi (s-plane) çizilirken yatay eksen $\sigma$ (gerçel kısım), dikey eksen $j\omega$ (sanal kısım) olarak alınır.

> **Ders sonrası not:** Tahtada $-u(t)$ yazılıp sonra $-u(-t)$'ye düzeltildi (ekrandan, 01:45:00 ve 01:50:00); tablodaki doğru işaret $-u(-t)$'dir.

### 7.3 Örnek: $x(t)=e^{-at}u(t)$

Bu örnek Schaum serisinin kitabında da vardır. İntegral yazılır (ekrandan, 01:50:00):

$$X(s)=\int_{-\infty}^{\infty}e^{-at}u(t)e^{-st}dt.$$

$u(t)$ sıfırda başladığı için sınırlar $0$ ile $\infty$ olur ve $u(t)$'nin etkisi kalmaz:

$$X(s)=\int_0^{\infty}e^{-(s+a)t}dt=\left[\frac{-1}{s+a}e^{-(s+a)t}\right]_0^{\infty}=0+\frac{1}{s+a}=\frac{1}{s+a}.$$

$\infty$ yerine yazıldığında sonucun sıfıra gitmesi için $s+a$'nın pozitif olması gerekir: $e^{-\infty}=1/e^{\infty}\to0$. Şart:

$$\mathrm{Re}\{s\}+a>0\;\Rightarrow\;\mathrm{Re}\{s\}>-a.$$

$a>0$ kabul edilirse $s$ düzleminde $-a$ noktası gerçel eksenin sol tarafındadır. ROC, $\sigma=-a$ doğrusunun sağında kalan bölgedir. Bu bilgi ters dönüşümde sonucun $e^{-at}u(t)$ mi yoksa başka bir şey mi olduğunu söyler.

$s=-a$ yazılırsa payda sıfır olur ve ifade tanımsızlaşır (sonsuza gider). Paydayı sıfır yapan bu değere kutup (pole) denir ve $s$ düzleminde × ile işaretlenir. Payı sıfır yapan değerler ise sıfırdır ve o ile gösterilir.

Ek bir özellik: ROC bölgesi $j\omega$ eksenini içeriyorsa Laplace dönüşümünün $s=j\omega$'daki değeri Fourier dönüşümüdür, yani Fourier dönüşümü vardır. Kararlılık analizleri de kutup ve sıfırlarla yapılır; karmaşık bir işaretin zaman düzleminde nereye gittiği görülemez, ama $s$ düzleminde payı ve paydayı sıfır yapan değerlerin özel anlamları vardır.

### 7.4 Örnek: $x(t)=-e^{-at}u(-t)$

Bu örnek de aynı kitaptandır. $u(-t)$ yüzünden sınırlar $-\infty$ ile $0$ olur:

$$X(s)=-\int_{-\infty}^{0}e^{-(s+a)t}dt=\left[\frac{1}{s+a}e^{-(s+a)t}\right]_{-\infty}^{0}=\frac{1}{s+a}-0=\frac{1}{s+a}.$$

Burada $t=-\infty$ yazıldığında sonucun sıfıra gitmesi için $s+a$'nın negatif olması gerekir; ancak o zaman eksi ile eksi çarpılır, $-\infty$ ile birlikte $e^{-\infty}$ elde edilir. Şart:

$$\mathrm{Re}\{s\}+a<0\;\Rightarrow\;\mathrm{Re}\{s\}<-a.$$

> **Hocanın vurgusu:** İki işaretin de Laplace dönüşümü $\frac{1}{s+a}$'dır. Farklı olan yalnız ROC'tur.

$a>0$ için ikinci işaretin ROC'u $-a$'nın solundadır ve $j\omega$ eksenini kesmez; bu yüzden Fourier dönüşümü yoktur. Gerçekten de Fourier integrali yazılınca $e^{-(a+j\omega)t}$ terimi $t=-\infty$'da sonsuza gider. Fourier'in alamadığı dönüşüm Laplace ile hallolmuş olur.

Özet:

| İşaret | $X(s)$ | ROC | Tür |
|---|---|---|---|
| $e^{-at}u(t)$ | $\dfrac{1}{s+a}$ | $\mathrm{Re}\{s\}>-a$ | sağ yanlı |
| $-e^{-at}u(-t)$ | $\dfrac{1}{s+a}$ | $\mathrm{Re}\{s\}<-a$ | sol yanlı |

ROC kutup içermez; yalnız kutbun bulunduğu noktadan başlayan bir sınırla tanımlanır.

## 8. Kutuplar, Sıfırlar ve ROC Kuralları

Tahtaya şu kural yazıldı (ekrandan, 02:05:00):

- $x(t)$ sol yanlıysa ROC en küçük kutbun solundadır.
- $x(t)$ sağ yanlıysa ROC en büyük kutbun sağındadır.

Bir işaretin Laplace dönüşümünde paydayı sıfır yapan birden fazla değer olabilir. İşaretin sağ ya da sol yanlı olduğuna bakılır ve buna göre uygun kutup seçilir.

### 8.1 Örnek: iki kutuplu sağ yanlı işaret

$$x(t)=3e^{-2t}u(t)-2e^{-t}u(t)\quad\text{(ekrandan, 02:05:00)}.$$

Artık integral yapmadan kurallarla gidilir. $3$'ün dönüşümü $3/s$'dir; $e^{-2t}$ ile çarpılınca $s+2$ olur: $\frac{3}{s+2}$, ROC $\mathrm{Re}\{s\}>-2$. İkinci terim $\frac{2}{s+1}$, ROC $\mathrm{Re}\{s\}>-1$. Kutuplar $-1$ ve $-2$'dedir.

İki terimde de $u(t)$ olduğundan işaret sağ yanlıdır. Kurala göre en büyük kutup olan $-1$'in sağı ROC'tur: $\mathrm{Re}\{s\}>-1$. Bu bölge $j\omega$ eksenini içerdiğinden Fourier dönüşümü vardır. ROC $-2$'nin solunda olsaydı Fourier dönüşümü alınamazdı.

Sıfırları bulmak için payda eşitlenir (ekrandan, 02:25:00):

$$X(s)=\frac{3(s+1)-2(s+2)}{(s+2)(s+1)}=\frac{s-1}{(s+2)(s+1)}.$$

Hoca payı önce yanlış hesaplayıp sonra $2(s+2)=2s+4$ olduğunu görerek düzeltti. Sistemin sıfırı $s=1$'dir: $s$ yerine $1$ verilirse ifade sıfır olur. $s$ düzlemine kutupların × ve sıfırların o ile çizildiği bu gösterime sıfır-kutup diyagramı denir.

Tahtaya ayrıca şu not düşüldü (ekrandan, 02:25:00): **ROC sıfır içerebilir, kutup içermez.**

### 8.2 $e^{-at}\cos(\omega_0t)u(t)$

$\cos\omega_0t$'nin dönüşümü $\frac{s}{s^2+\omega_0^2}$'dir. $e^{-at}$ ile çarpım $s$ yerine $s+a$ yazdırır (ekrandan, 02:20:00):

$$e^{-at}\cos(\omega_0t)u(t)\;\leftrightarrow\;\frac{s+a}{(s+a)^2+\omega_0^2},\qquad \mathrm{Re}\{s\}>-a.$$

$u(t)$'nin etkisi ROC'tadır: $e^{-(s+a)t}$ teriminin $t\to\infty$'da sıfıra gitmesi için $\mathrm{Re}\{s\}+a>0$ olmalıdır. Hoca kutbu $-a$ olarak anlattı ve "çift katlı" bir kutup gibi ele aldı; kutbun katlı olması ROC'u değiştirmez.

> **Ders sonrası not:** Hoca paydayı $(s+a)^2$ üzerinden yorumlayıp $-a$'yı çift katlı kutup olarak söyledi. Paydanın tamamı $(s+a)^2+\omega_0^2$ olduğundan, $\omega_0\neq0$ için kutuplar büyük olasılıkla $s=-a\pm j\omega_0$'dır. İkisinin de gerçel kısmı $-a$ olduğundan ROC sonucu ($\mathrm{Re}\{s\}>-a$) aynıdır.

Hoca ayrıca ROC'un iki kutup arasında kalan bir şerit olabileceğini de çizdi (ekrandan, 02:25:00).

### 8.3 Örnek: iki yanlı işaret $e^{-a|t|}$

$$x(t)=e^{-a|t|}=e^{at}u(-t)+e^{-at}u(t)\quad\text{(ekrandan, 02:25:00)}.$$

Mutlak değer açılınca bir sol yanlı ve bir sağ yanlı parça çıkar. Tablodan:

- $e^{-at}u(t)\leftrightarrow\frac{1}{s+a}$, ROC $\mathrm{Re}\{s\}>-a$.
- $e^{at}u(-t)\leftrightarrow-\frac{1}{s-a}$, ROC $\mathrm{Re}\{s\}<a$ (sol yanlı tablodaki $-e^{-bt}u(-t)\leftrightarrow\frac{1}{s+b}$ kuralında $b=-a$ alınıp işaret değiştirilir).

$$X(s)=\frac{1}{s+a}-\frac{1}{s-a}=\frac{-2a}{(s+a)(s-a)},\qquad -a<\mathrm{Re}\{s\}<a.$$

Kutuplar $-a$ ve $a$'dır; ROC bu iki kutup arasındaki şerittir. Pay $-2a$ sabit olduğundan sıfır noktası yoktur.

### 8.4 Diğer özellikler

Zamanda öteleme: $x(t-t_0)\leftrightarrow e^{-st_0}X(s)$. Örneğin $t-3$ kayması $e^{-3s}$ çarpanı getirir. $x$ yerine sinüs ya da kosinüs konunca yalnız bu ek çarpan gelir.

**Soru:** Sayısal işaret işlemede Laplace dönüşümü doğrudan kullanılır mı? **Cevap:** Hayır. Laplace ve Fourier dönüşümü sürekli zamanlı işaret ve sistemlerde kullanılır. Ayrık tarafta ayrık Fourier dönüşümü ya da z dönüşümü kullanılır; z dönüşümü sonraki konudur. Laplace dönüşümünü daha çok kontrolcüler ve elektrikçiler kullanır.

## 9. Ters Laplace Dönüşümü

Ters Laplace dönüşümünün integralini bilmeye pek gerek yoktur; var olan çözüm yöntemleri daha çok işe yarar. Dört temel kural ($t^n$, $e^{at}$, $\sin at$, $\cos at$) tersten okunur (ekrandan, 02:35:00):

- $\mathcal{L}^{-1}\left\{\frac{4}{s^6}\right\}$: $s^6$ ancak $t^5$'ten gelir; $\mathcal{L}\{t^5\}=\frac{5!}{s^6}$. 5! ile bölünüp 4 ile çarpılmıştır: $\frac{4}{5!}t^5$.
- $\mathcal{L}^{-1}\left\{\frac{5}{s-4}\right\}=5e^{4t}$. $s-4$, $e^{+4t}$'yi hatırlatır; 5 katsayıdır.
- $\mathcal{L}^{-1}\left\{\frac{2}{s^2+4}\right\}=\sin2t$. Ne $e$'li ne $t^n$'li bir yapı var; payda sabit olduğu için sinüstür.
- $\mathcal{L}^{-1}\left\{\frac{3}{s^2+25}\right\}=\frac35\sin5t$. $\sin5t$ için payda 5 olmalıydı; 5'e bölünüp 3 ile çarpılmıştır.
- $\mathcal{L}^{-1}\left\{\frac{s}{s^2+16}\right\}=\cos4t$.
- $\mathcal{L}^{-1}\left\{\frac{6s}{s^2+49}\right\}=6\cos7t$. Bu soruyu hoca öğrencilere sordu; 6 başındaki genliktir.

> **Ders sonrası not:** Hoca $\frac{4}{s^6}$ örneğini anlatırken sözlü olarak "5! bölü $t^6$", "$4!$ bölü $5!$" gibi karışık ifadeler kullandı; tahtadaki doğru sonuç $\frac{4}{5!}t^5=\frac{t^5}{30}$'dur.

$e^{at}$ ile çarpma kuralının tersten kullanımı (ekrandan, 02:35:00):

- $\mathcal{L}^{-1}\left\{\frac{1}{(s-5)^2}\right\}$: $s$'li bir şeyin karesi var ama yanında sayı yok, yani sinüs/kosinüs değildir; açılınca da tanıdık bir şey çıkmaz. $\mathcal{L}\{t\}=\frac{1!}{s^2}$ olduğundan bu, $t$'nin $e^{5t}$ ile çarpılmış hâlidir: $te^{5t}$. Sağlaması: $\mathcal{L}\{t\}=1/s^2$, $s$ yerine $s-5$ yazılınca $1/(s-5)^2$.
- $\mathcal{L}^{-1}\left\{\frac{1}{(s+2)^3}\right\}$: $s^3$, $t^2$'den gelir ($\mathcal{L}\{t^2\}=\frac{2!}{s^3}$); $s+2$ ise $e^{-2t}$'den. Payda $2!$ olmadığına göre 2'ye bölünmüştür: $\frac{t^2}{2}e^{-2t}$.
- $\mathcal{L}^{-1}\left\{\frac{s+1}{(s+1)^2+16}\right\}=e^{-t}\cos4t$. Payda ve paydaki aynı $s+1$ kosinüsü gösterir.
- $\mathcal{L}^{-1}\left\{\frac{2}{(s-3)^2+9}\right\}=\frac23e^{3t}\sin3t$. $9=3^2$, $\sin3t$ için payda 3 olmalıydı; 3'e bölünüp 2 ile çarpılmıştır; $s-3$ ise $e^{3t}$'den gelir.

## 10. Basit Kesirlere Ayırma

Genel kurala uymayan ifadelerde amaç yine bilinen kurallara uydurmaktır. Bunun bir yöntemi basit kesirlere ayırmadır. Hoca bugünkü anlatımı slayt yerine yazarak yaptığını, video kaydını bu şekilde izleyip çeşitli örnekler çözmenin faydalı olacağını söyledi.

### 10.1 İki farklı birinci derece çarpan

$$\mathcal{L}^{-1}\left\{\frac{2s-3}{s^2+3s+2}\right\}\quad\text{(ekrandan, 02:40:00)}.$$

$s^2$ var ama $3s$ terimi ifadeyi sinüs/kosinüse uydurmayı bozar. Payda çarpanlarına ayrılır: $(s+2)(s+1)$.

$$\frac{2s-3}{(s+2)(s+1)}=\frac{A}{s+2}+\frac{B}{s+1}.$$

Bu kesirler $e$'li ifadelere benzer: $Ae^{-2t}+Be^{-t}$. $A$ ve $B$ için payda eşitlenir: $A(s+1)+B(s+2)=2s-3$. Hoca önce yanlışlıkla $s-1$ yazdı, sonra $s+1$ olarak düzeltti. Katsayılar karşılaştırılır (ekrandan, 02:45:00):

$$A+B=2,\qquad A+2B=-3\;\Rightarrow\;A=7,\;B=-5.$$

$$x(t)=7e^{-2t}-5e^{-t}.$$

### 10.2 Çarpanlarına ayrılmayan ikinci derece çarpan

$$\mathcal{L}^{-1}\left\{\frac{2s+1}{(s-2)(s^2+9)}\right\}=\frac{A}{s-2}+\frac{Bs+C}{s^2+9}\quad\text{(ekrandan, 02:45:00)}.$$

İkinci derece çarpan için payda birinci dereceden $Bs+C$ yazılır. Hoca hesabı uzatmamak için katsayıları kolay sayılar olarak varsaydı: $A=3$, $B=2$, $C=4$ ("bu sayılar hayalidir, hesaplarsanız farklı bulabilirsiniz"). Bu varsayımla:

$$\frac{3}{s-2}+\frac{2s}{s^2+9}+\frac{4}{s^2+9}\;\Rightarrow\;x(t)=3e^{2t}+2\cos3t+\frac43\sin3t.$$

Son terimde 3'e bölme ve 4 ile çarpma vardır.

> **Ders sonrası not:** Derste katsayılar yöntem gösterilsin diye uydurma alındı. Gerçek ayrıştırma (ajan tarafından python ile hesaplandı) $A=\frac{5}{13}$, $B=-\frac{5}{13}$, $C=\frac{16}{13}$'tür ve $x(t)=\frac{5}{13}e^{2t}-\frac{5}{13}\cos3t+\frac{16}{39}\sin3t$ olur.

Üçüncü derece bir çarpan olursa paya ikinci dereceden bir ifade yazılır; hoca bunun soru olarak sorulmayacağını, isteyenlerin alıştırma olarak çözebileceğini söyledi.

### 10.3 Katlı kök

$$\frac{2s-3}{(s+4)(s-2)^2}=\frac{A}{s+4}+\frac{B}{s-2}+\frac{C}{(s-2)^2}.$$

Paydada üç kök vardır ($s+4$'ten bir, $(s-2)^2$'den iki), bu yüzden üç basit kesir yazılır. Katsayılar yine hayali alındı: $A=2$, $B=3$, $C=4$. O zaman $2e^{-4t}+3e^{2t}+\dots$ gelir. Son terim için "kutsal kural" kullanılır: $\frac{4}{(s-2)^2}$, $t$'li bir terimin ($\mathcal{L}\{t\}=1!/s^2$) $e^{2t}$ ile ötelenmiş hâlidir: $4te^{2t}$.

> **Ders sonrası not:** Gerçek katsayılar (ajan tarafından python ile hesaplandı) $A=-\frac{11}{36}$, $B=\frac{11}{36}$, $C=\frac16$'dır; $x(t)=-\frac{11}{36}e^{-4t}+\frac{11}{36}e^{2t}+\frac16te^{2t}$. Pay derste sözlü olarak "$2s-3$" diye söylendi; bu ifade karede görülmedi.

### 10.4 Tam kareye tamamlama

Payda çarpanlarına ayrılamıyorsa ayrılabilir bir biçimde yazılır:

$$\mathcal{L}^{-1}\left\{\frac{1}{s^2+2s+2}\right\}=\mathcal{L}^{-1}\left\{\frac{1}{(s+1)^2+1}\right\}=e^{-t}\sin t.$$

$\frac{1}{s^2+1}$, $\sin t$'nin dönüşümüdür; $s$ yerine $s+1$ ötelemesi $e^{-t}$ çarpanından gelir.

## 11. Konvolüsyon, Türev, İlk ve Son Değer Teoremleri

Sinyalle ilgili özellikler tahtaya şöyle yazıldı (ekrandan, 02:50:00):

$$x_1(t)*x_2(t)\;\leftrightarrow\;X_1(s)X_2(s),\qquad \frac{dx(t)}{dt}\;\leftrightarrow\;sX(s).$$

Konvolüsyon, Fourier'de olduğu gibi Laplace'ta da çarpmaya karşılık gelir. Fourier'de türev $j\omega X(j\omega)$ ile yazılıyordu; Laplace'ta $j\omega$'nın karşılığı $s$'dir. Bunlar çift taraflı (eksi sonsuzdan artı sonsuza) Laplace dönüşümü için geçerlidir.

**İlk değer teoremi:** Sistem açıldığında hangi değerden başlar? Zaman düzleminde denklemde $t$ yerine $0^+$ yazılır. Bunun yerine Laplace dönüşümü alınmış bir sistemde $sX(s)$ hesaplanıp $s$ yerine sonsuz yazılır:

$$x(0^+)=\lim_{s\to\infty}sX(s).$$

**Son değer teoremi:** $t\to\infty$'da sistemin ya da sinyalin değeri normalde limitle bulunur. Bunun yerine:

$$\lim_{t\to\infty}x(t)=\lim_{s\to0}sX(s).$$

**Soru:** $s=0$ yazılınca sonuç doğrudan sıfır olmaz mı? **Cevap:** Hayır, önce $s$ ile $X(s)$ çarpılır ve ifade sadeleştirilir, sonra $s=0$ konur. Belirsizlik çıkarsa L'Hôpital kuralı gibi yöntemlerle giderilir.

Ters Laplace dönüşümünün integrali de yine bir integral dönüşümüdür; $s$'ler kaybolur, $t$ kalır:

$$x(t)=\frac{1}{2\pi j}\int_{\sigma-j\infty}^{\sigma+j\infty}X(s)e^{st}ds.$$

> **Ders sonrası not:** Hoca sınırları "sigma eksi $j\omega$, sigma artı $j\omega$" diye söyledi; standart formülde sınırlar büyük olasılıkla $\sigma-j\infty$ ile $\sigma+j\infty$'dur.

## 12. Tek Taraflı Laplace ve Diferansiyel Denklem Çözümü

### 12.1 Tek taraflı Laplace

Gerçek zamanlı sistemlerde bir devre eksi bir zamanda çalıştırılamaz; $t=0$ anında çalıştırılır (nedensellik). Ayrıca çıkışı bilip girişi ona göre vermek mümkün değildir; $t+1$ anındaki çıkışı alıp şu anki giriş olarak veremeyiz. Bu yüzden tek taraflı Laplace dönüşümü kullanılır:

$$X(s)=\int_{0^-}^{\infty}x(t)e^{-st}dt.$$

Tek taraflıda türev kuralı başlangıç koşullarını içerir. Diferansiyel denklem çözümlerinde ve özyinelemeli (rekürsif) algoritmalarda başlangıç koşulları verilir (ör. $y(0)$, $y'(0)$):

$$\frac{dx}{dt}\;\leftrightarrow\;sX(s)-x(0^-),$$

$$\frac{d^2x}{dt^2}\;\leftrightarrow\;s\big[sX(s)-x(0^-)\big]-x'(0^-)=s^2X(s)-sx(0^-)-x'(0^-).$$

İkinci türevde hem $x$'in başlangıç değeri hem de türevinin başlangıç değeri çıkarılır.

### 12.2 Çift taraflı çözüm

Bir sistemin diferansiyel denklemi (ekrandan, 03:00:00):

$$\frac{d^2y(t)}{dt^2}+3\frac{dy(t)}{dt}+2y(t)=x(t),\qquad x(t)=u(t).$$

Girişe $u(t)$ verilirse çıkışta ne görülür? $y(t)$ bilinmeden türevleri de bilinemez; denklem çözülmelidir. Laplace formuna geçilir ($y(t)\leftrightarrow Y(s)$, $u(t)\leftrightarrow1/s$):

$$s^2Y(s)+3sY(s)+2Y(s)=\frac1s\;\Rightarrow\;Y(s)=\frac{1}{s(s^2+3s+2)}=\frac{1}{s(s+1)(s+2)}.$$

Basit kesirler: $\frac{A}{s}+\frac{B}{s+1}+\frac{C}{s+2}$, $A=\frac12$, $B=-1$, $C=\frac12$ (ekrandan, 03:00:00). Bu katsayılar gerçek değerlerdir:

$$y(t)=\frac12u(t)-e^{-t}u(t)+\frac12e^{-2t}u(t).$$

$1/s$ sabit gibi davranır ($1$); ama gerçek zamanlı bir sistemde çalışıldığı için $u(t)$ eklenir. Örneğin sisteme birim basamak giriş verildiğinde 10. saniyede ne okunacağı sorulursa $t=10$ yazılır; devre ise ölçülen gerilim ya da akım bulunur.

### 12.3 Başlangıç koşullu (tek taraflı) çözüm

Başlangıç koşulları $y(0)=1$, $y'(0)=2$ verilsin (ekrandan, 03:00:00). İkinci türev $s^2Y(s)-sy(0)-y'(0)$, birinci türev $sY(s)-y(0)$ olarak yazılır:

$$s^2Y(s)-s-2+3\big(sY(s)-1\big)+2Y(s)=\frac1s.$$

Hoca yazarken bir işaret hatası yapıp düzeltti. $Y(s)$ yalnız bırakılınca:

$$Y(s)(s^2+3s+2)-s-5=\frac1s\;\Rightarrow\;Y(s)=\frac{1}{s(s^2+3s+2)}+\frac{s+5}{s^2+3s+2}.$$

İlk parça az önceki çift taraflı çözümün aynısıdır. İkinci parça $\frac{s}{s^2+3s+2}+\frac{5}{s^2+3s+2}$ diye ayrılıp aynı mantıkla bulunur. Hoca çözümü burada bıraktı.

<!-- BELİRSİZ: Altyazıda ikinci parça bir yerde "S artı 5 bölü S çarpı S kare artı 3S artı 2" diye geçiyor; hemen ardından iki parçaya ayırma $s/(s^2+3s+2)+5/(s^2+3s+2)$ olarak söylendiği için doğru ifade büyük olasılıkla $(s+5)/(s^2+3s+2)$'dir. -->

> **Çözüm (derste verilmedi):** $\frac{s+5}{(s+1)(s+2)}=\frac{4}{s+1}-\frac{3}{s+2}$. İlk parçayla birlikte $y(t)=\left(\frac12+3e^{-t}-\frac52e^{-2t}\right)u(t)$. Kontrol: $y(0)=\frac12+3-\frac52=1$, $y'(0)=-3+5=2$ (python ile doğrulandı).

Gerçek bir sisteme ait diferansiyel denklemde ve başlangıç koşulları verildiğinde sonuca $u(t)$ eklenir; tamamen matematiksel bir çözümde $-\infty$'dan $+\infty$'a düşünülür. Dikkat edilecek nokta sistemin sağ ya da sol yanlı olduğudur; burada $t\ge0$'a bakıldığı için sağ yanlıdır, daha teorik bir durumda $u(-t)$'li terimler de olabilir.

### 12.4 RC devresi uygulaması

Devre teorisinde RC devrelerinin türev ve integrallerle çözüldüğü görülmüştür. Hoca paylaştığı bir bağlantıda bir RC devresinin diferansiyel denkleminin (yük $q$ üzerinden yazılmış; $q$ yerine $y$ düşünülebilir) Laplace ile adım adım çözüldüğünü gösterdi. Çözüm sonunda devre teorisindeki $e^{-t/RC}$ biçimli sonuç Laplace ile de bulunur; örneğin 5. saniyedeki gerilim $t=5$ yazılarak hesaplanır. Son değer, $Y(s)$ bulunduktan sonra son değer teoremiyle de elde edilebilir. Gösterilen bir başka kaynakta direncin $s$ düzlemindeki karşılığı $V(s)=R\cdot I(s)$, bobininki $V(s)=L[sI(s)-I_0]=sL\,I(s)-LI_0$ olarak verilmişti; buradaki $I_0$ başlangıç akımıdır (ekrandan, 03:05:00).

## Örnek Sorular

### Soru 1 (ekrandan, 00:10:00)

a) Grafiği verilen $x(t)$ işaretinin sinüzoidal ifadesini $x(t)=A\cos(\omega t+\theta)$ şeklinde yazınız ($A$, $\omega$ ve $\theta$ bulunacaktır). b) Bu işareti örneklemek istesek en düşük örnekleme frekansı ne olmalıdır?

Grafik: işaret $-20$ ile $20$ arasında salınır; $t=-0.02$ s ve $t=0.02$ s'de $+20$ tepesi, $t=0$'da sıfırdan aşağı iniş vardır; zaman ekseni $-0.02$ ile $0.06$ s arasıdır.

**Çözüm (a)** (ekrandan, 00:15:00): $A=20$, $T=0.04$ s, $f=1/T=25$ Hz, $\omega=2\pi f=50\pi$ rad/s. $x(0)=0\Rightarrow\cos\theta=0\Rightarrow\theta=\pi/2$. Sonuç: $x(t)=20\cos(50\pi t+\pi/2)$.

> **Çözüm (derste verilmedi):** (b) İşaret tek frekanslı olduğu için en yüksek frekans $f_{max}=25$ Hz'dir. Nyquist şartına göre $f_s\ge2f_{max}=50$ Hz olmalıdır; en düşük örnekleme frekansı 50 Hz'dir.

> **Ek bilgi (derste anlatılmadı):** Tam $f_s=2f_{max}$ ile örneklemede örnekler sinüsün sıfır geçişlerine denk gelebilir; bu yüzden pratikte örnekleme frekansı büyük olasılıkla Nyquist sınırından biraz büyük seçilir.

### Soru 2 (ekrandan, 00:10:00)

Aşağıda verilen $x(t)$ işareti için $x(-t/2)$, $x(2(t+2))$ ve $x(-t+1)$ işaretlerini çiziniz. $x(t)$: $t=-1$'de 0, $t=0$'da 2, $t=2$'de 0 olan üçgen (ekrandan, 00:15:00).

**Çözüm** (ekrandan, 00:15:00):

| İşaret | Başlangıç | Tepe (değer 2) | Bitiş |
|---|---|---|---|
| $x(-t/2)$ | $t=-4$ | $t=0$ | $t=2$ |
| $x(2(t+2))$ | $t=-2.5$ | $t=-2$ | $t=-1$ |
| $x(-t+1)$ | $t=-1$ | $t=1$ | $t=2$ |

### Soru 3 (ekrandan, 00:15:00 ve 00:25:00)

$x[n]=[2\ 3\ 2\ 1]$ ($n=-1..2$) ve $h[n]=[2\ {-1}\ 1\ {-2}]$ ($n=-2..1$) için $y[n]=x[n]*h[n]$ konvolüsyonunu bulunuz.

**Çözüm** (ekrandan, 00:20:00): $y[n]=[4\ 4\ 3\ {-1}\ {-5}\ {-3}\ {-2}]$, $n=-3..3$. Yani $y[-3]=4$, $y[-2]=4$, $y[-1]=3$, $y[0]=-1$, $y[1]=-5$, $y[2]=-3$, $y[3]=-2$ (python ile doğrulandı).

### Soru 4 (ekrandan, 00:20:00)

Periyodu $T=2$ s olan, $0<t<1$ aralığında $x(t)=e^{-t}$, $1<t<2$ aralığında $x(t)=0$ olan periyodik işaretin Fourier serisi katsayılarını bulunuz. <!-- BELİRSİZ: sorunun tam metni karede görülmedi; tanım çözümden ve anlatımdan kuruldu. -->

**Çözüm** (ekrandan, 00:20:00): $\omega_0=\pi$ rad/s.

$$c_k=\frac12\int_0^1e^{-(1+jk\pi)t}dt=\frac{1-e^{-(1+jk\pi)}}{2(1+jk\pi)}=\frac{1-e^{-1}(-1)^k}{2(1+jk\pi)}.$$

### Soru 5 (derste sözlü, 02:32:51)

$\mathcal{L}^{-1}\left\{\dfrac{6s}{s^2+49}\right\}$ nedir?

**Çözüm** (derste verildi, 02:33:12): $\frac{s}{s^2+49}$, $\cos7t$'yi gösterir; 6 genliktir: $6\cos7t$ (ekrandan, 02:35:00).

### Soru 6 (derste sözlü, 02:39:56)

$\dfrac{A}{s+2}+\dfrac{B}{s+1}$ biçimindeki bir ifadenin ters Laplace dönüşümü neye benzer?

**Çözüm** (derste verildi, 02:40:11): Üstel ifadelere: $Ae^{-2t}+Be^{-t}$.

## Dersin Toparlaması

Bu derste önce sınav soruları çözüldü: sinüzoidal işaretin genlik, frekans ve fazının grafikten bulunması, zaman dönüşümleri, ayrık konvolüsyon ve periyodik bir işaretin Fourier serisi katsayıları. Ardından dönemin konuları CT/DT tablosuyla özetlendi ve integral dönüşüm mantığı üzerinden Fourier dönüşümü hatırlatıldı. Telefon tuşları (DTMF), nota ve tını örnekleri Fourier dönüşümünün pratik gücünü gösterdi; tüm kaydın FFT'sinin zaman bilgisini kaybettiği, parçalama ya da spektrogramla bunun aşıldığı görüldü.

Dersin ikinci yarısında Fourier dönüşümünün ıraksayan işaretlerdeki eksiği üzerinden Laplace dönüşümü tanıtıldı: $s=\sigma+j\omega$, $e^{-\sigma t}$ ile bastırma, temel dönüşüm tablosu, doğrusallık, $e^{at}$ ve $t^n$ ile çarpma kuralları, yakınsama bölgesi, kutup-sıfır diyagramı ve sağ/sol yanlı işaretler için ROC kuralları. Ters dönüşüm tabloya uydurma, basit kesirlere ayırma ve tam kareye tamamlama ile yapıldı. Son olarak konvolüsyon, türev, ilk/son değer teoremleri ve tek taraflı Laplace ile ikinci dereceden bir diferansiyel denklem çözüldü. Hoca, başlangıç koşullu çözümün kalan kısmına ve ayrık zamandaki karşılık olan z dönüşümüne sonraki derste devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
