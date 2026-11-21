# Ders 6 Genişletilmiş Notu: Zaman-Frekans Analizi (STFT ve Dalgacık Dönüşümü) ve Görüntü İşlemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fourier Dönüşümüne Geri Dönüş: Temel Fonksiyonlar ve Tarihçe
- 2. Durağan ve Durağan Olmayan İşaretler
- 3. Fourier Dönüşümünün Kısıtı
- 4. Kısa Zamanlı Fourier Dönüşümü (STFT)
- 5. MATLAB'de STFT: Spektrogram Uygulamaları
- 6. Çok Çözünürlüklü Analiz ve Dalgacık Dönüşümü
- 7. Ayrık Dalgacık Dönüşümü ve MATLAB Wavelet 1-D Aracı
- 8. Görüntü İşlemeye Giriş
- Örnek Sorular

## 1. Fourier Dönüşümüne Geri Dönüş: Temel Fonksiyonlar ve Tarihçe

Hoca derse, önceki haftalarda görülen FFT ve DTFT gibi yöntemlerin kısıtlarını ve bu kısıtlara çözüm olarak geliştirilen yöntemleri birkaç uygulamayla göstereceğini söyleyerek başladı. Bu dersin slaytları "Introduction to Wavelet" başlıklı bir sunumdan alınmıştı.

### 1.1 Temel fonksiyonla çarpmanın anlamı

Fourier yöntemleri frekans analizi için kullanılır ve matematiksel temeli 1800'lerin başına dayanır. Fourier dönüşümünde işaret bir karmaşık üstelle çarpılır:

$$e^{-j\omega n}=\cos(\omega n)-j\sin(\omega n)$$

Bu karmaşık üstelin gerçel kısmı kosinüs, sanal kısmı eksi işaretli sinüs gibi davranır; ikisi birlikte sinüzoidal bir yapı oluşturur. Hoca bu çarpmanın neden yapıldığını şöyle açıkladı: özgün işaret ile temel fonksiyon (basis function) birbirine ne kadar benziyorsa çarpım o kadar büyük bir katsayı üretir. Bu bir tür iç çarpımdır; benzerlik arttıkça katsayı da artar.

Hoca bunu tahtada çizerek gösterdi. Bir işaret ile bir kosinüs aynı bölgelerde birlikte büyük değerler alıyorsa (ör. bir noktada ikisi de 2 ise çarpım 4 olur), altta kalan alan büyür ve katsayı yüksek çıkar. Benzemedikleri yerlerde küçük ve eksi değerlerin çarpımları toplamı eksi yönde etkiler. Aynı işareti daha yüksek frekanslı ve düşük genlikli bir fonksiyonla çarptığında bu kez işaretin yüksek frekanslı kısımlarından büyük katkı gelir. Yani bir fonksiyonu bir temel fonksiyon dizisiyle çarpmak, işaretin o frekanslardaki benzerliğini hesaplamaktır. Altta kalan alanın hesabı aynı zamanda fonksiyonun enerjisiyle ilgilidir.

### 1.2 Tarihçe

Slayttaki tarihçe şöyleydi (ekrandan, 00:20:00):

- 1930 öncesi: Joseph Fourier (1807) ve frekans analizi kuramı.
- 1930'lar: ölçeğe göre değişen temel fonksiyonların kullanılması; bir fonksiyonun enerjisinin hesaplanması.
- 1960-1980: Guido Weiss ve Ronald R. Coifman; Grossman ve Morlet.
- 1980 sonrası: Stephane Mallat, Y. Meyer, Ingrid Daubechies; günümüzdeki dalgacık uygulamaları.

Hoca 1930'lardaki fikri, sabit bir sinüs yerine frekansa göre değişen, sürekli değil sönümlü temel fonksiyonlar kullanmak diye özetledi. Dalgacıkların ilk adımları 1960-1980 arasında atılmış, 1980'den sonra yoğun biçimde kullanılmaya başlanmıştır.

### 1.3 Neden dönüşüm yapıyoruz?

Frekans temelli dönüşümlerin amacı, ham veride görünmeyen bilgiyi açık hale getirmektir. Ayrık örneklere zaman domeninde bakınca frekansla ilgili bir bilgi edinemeyiz. Hatırlatma olarak bu örnekler sürekli işaretten $t$ yerine $nT_s$ konarak elde edilmişti. İşaret işleme dediğimizde ise işaret FFT, dalgacık dönüşümü ya da kısa zamanlı Fourier dönüşümü gibi bir dönüşümle yorumlanabileceği başka bir uzaya aktarılır. En yaygın dönüşüm Fourier dönüşümü, pratikte de FFT'dir.

### 1.4 Sürekli ve ayrık Fourier dönüşümü

Slaytta iki form birlikte verildi (ekrandan, 00:25:00). Sürekli form:

$$X(f)=\int_{-\infty}^{\infty}x(t)\,e^{-j2\pi f t}\,dt,\qquad x(t)=\int_{-\infty}^{\infty}X(f)\,e^{j2\pi f t}\,df$$

Hoca bunun $e^{-j\omega t}$ biçiminde de yazılabileceğini belirtti. $\omega$ değiştikçe temel fonksiyon $\cos\omega t$ değişir; yani düşük frekanstan yüksek frekansa kadar farklı temel fonksiyonlar kullanılır. Sürekli form işaret sürdüğü sürece integral alır.

Ayrık form slaytta MATLAB'in 1'den başlayan indisleriyle yazılmıştı:

$$X(k+1)=\sum_{n=0}^{N-1}x(n+1)\,W_N^{kn},\qquad x(n+1)=\frac{1}{N}\sum_{k=0}^{N-1}X(k+1)\,W_N^{-kn},\qquad W_N=e^{-j\frac{2\pi}{N}}$$

Hoca bunu derslerde kullanılan biçimde $X[k]=\sum_{n=0}^{N-1}x[n]\,e^{-j\frac{2\pi}{N}nk}$ diye hatırlattı. Ayrık formda işaretten alınmış $0$ ile $N-1$ arasındaki belirli bir örnek kümesi üzerinde işlem yapılır.

Fourier dönüşümünün iki önemli özelliği vardır: işaretin frekans içeriğini bulur ve her frekansın işarette ne miktarda bulunduğunu, işaretin o temel fonksiyona benzerliği oranında hesaplar. Daha önce çizilen $|X(f)|$ grafiği simetriktir; ilgilendiğimiz yarısında frekans arttıkça hangi frekansların ne kadar bulunduğu görülür. Bu bir anlamda "frekansların histogramı" gibidir. Alçak frekanslarda genlik yüksekse işaretin alçak frekans bileşenlerinin baskın olduğu anlaşılır ve filtre tasarımı buna göre yapılır.

## 2. Durağan ve Durağan Olmayan İşaretler

Durağan işaret (stationary signal), frekans içeriği zamanla değişmeyen ve bütün frekans bileşenlerinin her an bulunduğu işarettir. Durağan olmayan işaretlerde ise frekans zamanla değişir; chirp işareti bunun tipik örneğidir.

### 2.1 Slayttaki örnek

Slaytta iki işaret karşılaştırıldı (ekrandan, 00:30:00). Durağan işaret 2 Hz, 10 Hz ve 20 Hz'lik üç kosinüsün toplamıdır. Hoca bunu tahtaya şöyle yazdı:

$$x(t)=\cos(2\pi\cdot 2t)+\cos(2\pi\cdot 10t)+\cos(2\pi\cdot 20t)$$

Fazlar hesaba katılmazsa her $t$ anındaki değer bu formülden bulunur; örneğin $t=0{,}6$ ya da $t=0{,}8$ s konarak o anki değer hesaplanabilir. Üç frekans da her an vardır.

Durağan olmayan işarette aynı frekanslar zaman aralıklarına bölünmüştür: 0,0-0,4 s arasında 2 Hz, 0,4-0,7 s arasında 10 Hz, 0,7-1,0 s arasında 20 Hz (ekrandan, 00:30:00).

<!-- BELİRSİZ: Slaytta zaman ekseni grafiğinde frekansın soldan sağa azaldığı görülüyor (yüksek frekans başta, en sonda yavaş bir dalga), tablo ise 0,0-0,4 s için 2 Hz diyor. Grafik ile tablonun sırası slaytta birbirini tutmuyor olabilir; not tablodaki değerleri izler. -->

### 2.2 FFT ile analiz

Hoca, öğrencilerin DTMF ödevinde verilen dosyaların durağan işaretler olduğunu hatırlattı: orada iki frekans matematiksel bir formülle zamanın her anında birlikte bulunuyordu. FFT alınıp tepe noktalarına bakılıyor ve örnekleme frekansı bilindiği için hangi frekansların kullanıldığı bulunuyordu.

Durağan işaretin FFT'sinde 2, 10 ve 20 Hz'de keskin tepeler vardır. Durağan olmayan işaretin FFT'si de bu üç frekansı aşağı yukarı gösterir; ancak geçişlerdeki süreksizlikler yüzünden tepeler o kadar keskin değildir ve arada dalgalanmalar oluşur. Hoca bu dalgalanmaların geçişlerdeki harmoniklerden kaynaklandığını, şimdilik hesaba katılmayabileceğini söyledi.

Asıl soru şudur: elimizde yalnız sağdaki spektrum olsaydı, işaretin zamandaki yapısına geri dönebilir miydik? Hayır. "Şu frekanslar var" deriz ama hangi frekansın hangi zamanda oluştuğunu bilemeyiz. Örneğin 20 Hz başta da, ortada da, sonda da oluşmuş olabilir.

### 2.3 Chirp örneği

Daha net bir örnek chirp işaretidir. Chirp, frekansın düşükten yükseğe ya da yüksekten düşüğe geçtiği işarettir. Bir saniye boyunca 2 Hz'den 20 Hz'e çıkan bir chirp ile 20 Hz'den 2 Hz'e inen bir chirp zaman domeninde birbirinden farklıdır. Fakat ikisinin DFT'si alınınca genlik gösterimleri birbirinin aynısıdır. Bu durumda yalnız spektruma bakarak hangi işarete geri dönüleceği bilinemez.

> **Ek bilgi (derste anlatılmadı):** Gerçel bir işaretin zamanda ters çevrilmiş halinin Fourier dönüşümü, özgün dönüşümün karmaşık eşleniğidir; genliği aynı kalır, yalnız faz değişir. İnen chirp yükselen chirp'in zamanda ters çevrilmiş hali olduğu için genlik spektrumları aynıdır. Fark faz spektrumundadır.

## 3. Fourier Dönüşümünün Kısıtı

Slayttaki sonuç (ekrandan, 00:35:00):

- Fourier dönüşümü yalnız işarette hangi frekans bileşenlerinin bulunduğunu verir.
- Zaman ve frekans bilgisi aynı anda görülemez.
- İşaretin zaman-frekans gösterimine ihtiyaç vardır.

Hoca bunun özellikle biyomedikal işaret işlemede önemli olduğunu vurguladı, çünkü biyomedikal işaretlerin çoğu durağan değildir. Örneğin bir kalp atımında bir bölümde oluşan frekanslar başka bir bölümde oluşanlardan farklıdır ve değişkenlik gösterebilir. Bir frekansın hem içeriğini hem de ne zaman oluştuğunu bilmek isteriz.

> **Hocanın vurgusu:** Fourier dönüşümü hangi frekans bileşeninin ne zaman oluştuğunu söyleyemez; yalnız işaretin frekans içeriği hakkında bilgi verir.

Slaytta bu kısıta karşı "ilk çözüm" olarak kısa zamanlı Fourier dönüşümü gösterilmişti (ekrandan, 00:35:00).

## 4. Kısa Zamanlı Fourier Dönüşümü (STFT)

### 4.1 Akla ilk gelen çözüm

Hoca öğrencilere, ellerinde yalnız frekans analizi yapabilen bir araç varken ilk ne düşüneceklerini sordu. İlk akla gelen, işaretin tamamının Fourier dönüşümünü almak yerine dar aralıklara bakmaktır. Önce bir aralıktaki frekans içeriğine bakılır, sonra bir sonraki aralığa geçilir. Böylece en azından $T_1$, $T_2$, $T_3$ gibi aralıkların hangi frekansları taşıdığı bilinir. Buna kısa zamanlı Fourier dönüşümü (Short-Time Fourier Transform, STFT) denir.

### 4.2 Gabor ve pencereleme

Slayttaki bilgi (ekrandan, 00:40:00):

- Dennis Gabor (1946) STFT'yi kullandı: işaretin bir seferde yalnız küçük bir bölümü analiz edilir. Bu tekniğe işareti pencereleme (windowing the signal) denir.
- İşaretin bu parçası durağan kabul edilir.
- STFT üç boyutlu bir dönüşümdür: sonuç zaman ve frekansın fonksiyonudur.

STFT'nin tanımı (ekrandan, 00:40:00):

$$\mathrm{STFT}_x^{(\omega)}(t',f)=\int_t \left[x(t)\cdot\omega^*(t-t')\right]\cdot e^{-j2\pi f t}\,dt$$

Burada $\omega(t)$ pencere fonksiyonudur, $t'$ pencerenin konumudur. İşaret pencere fonksiyonuyla çarpılınca yalnız ilgili bölge kalır ve yalnız o bölgenin Fourier dönüşümüne bakılmış olur. Sonuçta iki eksenli bir yapı oluşur: bir eksen zaman, diğer eksen frekans.

### 4.3 Pencere genişliği ve çözünürlük

Pencere genişletilirse ne olur? Ayrık dönüşümde $X[k]$, $n=0$'dan $N-1$'e kadar olan örneklerden hesaplanır ve $k$ de $0$'dan $N-1$'e kadar değişir. Pencereyi büyütmek işlenen örnek sayısı $N$'yi artırır; dolayısıyla frekans çözünürlüğü artar. Ancak pencere genişledikçe frekansın hangi zaman aralığında oluştuğu bilgisi zayıflar. "$T_1$ anında oldu" demek dar bir aralık verir; "$T_4$ aralığında oldu" demek çok daha geniş bir aralıktır. Yani pencereyi büyütünce frekans çözünürlüğü artarken zaman çözünürlüğü (zamandaki netlik) azalır.

Hoca STFT'nin en büyük sorununu öğrencilere sordu. Bir öğrenci zamansal çözünürlükte sıkıntı olacağını, zaman çözünürlüğü artırılırsa frekans çözünürlüğünün kötüleşeceğini söyledi. Hoca bunu onaylayıp sorunu şöyle özetledi: seçilecek pencere genişliği ne olmalıdır? İşaretin frekans içeriği hakkında hiçbir şey bilmeden keyfi bir işaret verildiğinde, seçilen pencerenin frekansları zamanda ayırıp ayırmayacağı bilinmez.

Hoca bunu durağan olmayan örnek üzerinden anlattı. Pencere dar seçilirse "burada 20 Hz, burada 10 Hz, burada 2 Hz oluşmuş" denebilir. Geniş seçilirse ve işaret iki parçaya bölünürse bir parçada hem 20 hem 10 Hz, diğerinde hem 10 hem 2 Hz görülür, ama bunların ne zaman oluştuğu bilinmez. Sabit frekanslı bir işarette geniş pencere seçmenin bir zararı yoktur; çok değişen bir işarette ise geniş pencere zaman bilgisinde belirsizlik yaratır.

Slayttaki dezavantajlar (ekrandan, 00:45:00):

- Pencere boyu değişmez ve baştan belirlenmesi gerekir.
- Çözünürlük ikilemi: dar pencere → kötü frekans çözünürlüğü, iyi zaman çözünürlüğü; geniş pencere → kötü zaman çözünürlüğü, iyi frekans çözünürlüğü.
- Heisenberg belirsizlik ilkesi: hangi frekansın hangi zaman aralığında bulunduğu kesin olarak bilinemez.

Hoca bunu fizikteki Heisenberg belirsizlik ilkesine benzetti: bir elektronun yeri belirlendiğinde hızı, hızı belirlendiğinde yeri belirlenemez ve bir bulut oluşur. Pencere boyutu ile frekans çözünürlüğü arasında da benzer bir ters ilişki vardır.

### 4.4 Dar ve geniş pencere örneği

Slaytta aynı işaretin dar pencere ve geniş pencere ile elde edilmiş 3B STFT çizimleri vardı (ekrandan, 00:45:00). Hoca frekans ekseninde 256 örneklik simetrik bir yapı olduğunu gösterdi. Dar pencerede tepelerin zamandaki sınırları bellidir; hangi frekansın ne zaman oluştuğu bulunabilir. Ancak frekans yönünden bakınca tepeler Gauss eğrisi gibi yayvandır. Bunun nedeni dar pencerede az örnek alınmasıdır: 10 örnekle 1000 örnek arasında fark vardır ve 10 örnekle frekanslar ancak Gauss benzeri kaba bir tahminle bulunur.

Geniş pencerede $N$ arttığı için frekans yönünde tepeler daha net görünür; Gauss benzeri yayvanlık kaybolur. Fakat bu kez zaman yönünde tepeler birbirinin içine girer ve hangi frekansın ne zaman oluştuğu bilgisi kaybolmaya başlar. Hoca buna çözüm olarak çok çözünürlüklü analize (multi-resolution analysis, MRA) geçileceğini söyledi.

## 5. MATLAB'de STFT: Spektrogram Uygulamaları

Hoca derste kullanmak üzere üç `.wav` dosyası hazırlamıştı: konuşma (`ses.wav`), müzik (`music.wav`) ve gürültü (`noise.wav`). Kullanılan betik şuydu (ekrandan, 00:50:00):

```matlab
% Speech Processing

[y, Fs] = audioread('ses.wav');

sound(y,Fs)

plot(abs(fft(y)))

% STFT
% S = spectrogram(x,window,noverlap,nfft,fs)

spectrogram(y);

spectrogram(y(:,1),256,128,256,Fs);
```

### 5.1 Konuşma kaydını okuma ve süresini bulma

`audioread` (ya da eski sürümlerde `wavread`) `.wav` dosyasını okur, örnekleri ve örnekleme frekansını döndürür. Örnekleme frekansı `.wav` dosyasının başlığında (header) saklıdır. Kayıtta "bir, iki, üç" deniyordu. Çalışma alanında `Fs = 44100` ve `y` için `139217x2 double` görünüyordu (ekrandan, 00:50:00). Kayıt iki kanallı okunmuştu; stereo bir kayıt olmadığı için iki kanalda da aynı ses vardır ve değerlendirme için bir kanal yeterlidir. `plot(y(:,1))` ile birinci kanal çizildi ve üç kelimenin zamandaki örnekleri görüldü.

44100 Hz, saniyede 44100 örnek alındığı anlamına gelir. Hoca bu bilgilerle kaydın süresinin bulunup bulunamayacağını sordu; cevap örnek sayısını örnekleme frekansına bölmektir. Ayrıntılı çözüm Örnek Sorular bölümündedir.

### 5.2 Spektrum ve spektrogram

`plot(abs(fft(y)))` ile çizilen spektrum simetriktir. Hoca yaklaşık 140000 örneğin yarısı olan 70000 civarının $\pi$'ye, yani en yüksek frekans olan 22050 Hz'e karşılık geldiğini belirtti (örnekleme frekansı 44100 Hz olduğu için). Spektrumda enerji alçak frekanslarda yoğunlaşmıştı. Farklı frekanslar vardı, ama neyin ne zaman oluştuğu bilinmiyordu.

Bunun için `spectrogram` fonksiyonu kullanıldı; bu fonksiyon kısa zamanlı Fourier dönüşümünü hesaplar. `spectrogram(y)` iki kanallı veriyle çalışmadı; MATLAB "X must be a vector (either row or column)" hatası verdi (ekrandan, 01:00:00). Hoca bu hatayı beklediğini söyleyip yalnız birinci kanalın bütün örneklerini alan `y(:,1)` ile çalıştırdı.

Varsayılan değerlerle çıkan spektrogramda bir eksen örnek numarası, diğer eksen normalize frekans ($\times\pi$ rad/örnek) idi; sarı renk yüksek, mavi renk düşük değerleri gösteriyordu (ekrandan, 00:55:00). "Bir" dendikten sonra konuşmacı sustuğu için o bölgede alçak frekanslı bilgi yoktur; "iki" denirken alçak frekanslar artar; "üç" denirken yüksek frekanslı bir bileşen gelir.

### 5.3 spectrogram parametreleri

Hoca MATLAB belgelerinden `spectrogram` fonksiyonunu açtı ("Spectrogram using short-time Fourier transform"). Fonksiyonun aldığı parametreler:

- `x`: işaret.
- `window`: kullanılacak pencere genişliği.
- `noverlap`: örtüşme miktarı.
- `nfft`: FFT nokta sayısı.
- `fs`: örnekleme frekansı.

**Örtüşme (overlap).** Pencereler uç uca alınabileceği gibi, geçişlerdeki kötü dalgalanmaları azaltmak için üst üste bindirilerek de alınabilir. İkinci pencere alınırken birinci pencerenin örneklerinin bir kısmı da kullanılır. Bu, STFT'nin örtüşme özelliğidir.

**nfft ve sıfır ekleme.** Hoca FFT'nin bir özelliğini hatırlattı. 128 uzunluklu bir işaretin FFT'si 128 frekans noktası verir. Frekans çözünürlüğü artırılmak istenirse işarete sıfırlar eklenerek uzunluk 256'ya çıkarılabilir. Bu durumda $X[k]$ 128 yerine 256 noktada hesaplanır ve incelenen frekans aralıkları küçülür. `fft` fonksiyonuna nokta sayısı verildiğinde (ör. 256 noktalı FFT) bu doldurma (padding) işlemi otomatik yapılır.

> **Ders sonrası not:** Hoca sıfırların başa ve sona eklendiğini söyledi. MATLAB'in `fft(x,n)` fonksiyonu büyük olasılıkla sıfırları yalnız işaretin sonuna ekler. Ayrıca sıfır ekleme spektrumu daha sık noktalarda örnekler, yani mevcut spektrumu ara değerlerle gösterir; pencere içinde yeni bilgi oluşmadığı için birbirine yakın iki frekansı ayırma yeteneği büyük olasılıkla değişmez. Bu ayırma yeteneği pencere süresine bağlıdır.

**Derste kullanılan çağrı.** `spectrogram(y(:,1),256,128,256,Fs)` çağrısında pencere 256 örnektir. Bir sonraki 256 örnek seçilirken önceki pencerenin yarısı, yani 128 örnek yeniden kullanılır ve 128 yeni örnek alınır. Örneğin ilk pencere 0-255 numaralı örnekleri kapsıyorsa ikinci pencere bunların son 128'ini ve 128 yeni örneği kapsar. FFT 256 noktalıdır ve örnekleme frekansı da verilmiştir (ekrandan, 01:00:00).

Örnekleme frekansı verilince eksenler örnek numarası yerine saniye cinsinden zamanı gösterir. Yaklaşık 3 saniyelik kayıtta 0,5. saniye civarında "bir" denir ve 0-0,5 s arasında alçak frekanslar yoğunlaşır, yüksek frekanslı bileşenler de vardır. Ardından bir sessizlik gelir; bu sırada mavi bölgede hemen hiç frekans yoktur. "İki" kelimesi iki parçalı görünür ("i", boşluk, "ki"). "Üç" denirken farklı bir frekans bileşeni ortaya çıkar. Böylece saniyeler ilerledikçe hangi frekans bileşeninin nasıl oluştuğu görülebilir.

### 5.4 Müzik dosyası

İkinci dosya 22050 Hz'te örneklenmiş, yaklaşık 66000 örnekli bir müzik kaydıydı; hoca süresinin yine yaklaşık 3 saniye olduğunu söyledi. Bu bir Windows açılış sesiydi. Spektrogramında başlangıçta alçak frekanslar azdır; 3. saniyeye doğru alçak frekanslar yayılmaya başlar. Bazı frekanslarda üç tane "tırmık izi" gibi çizgiler görülür. Bazı yüksek frekanslı bileşenler zamanla alçak frekansa kayarak yok olur. Bu seste yüksek frekanslı bileşenler daha fazladır.

### 5.5 Gürültü dosyası

Üçüncü dosya hocanın Gauss dağılımından rastgele sayılar üreterek oluşturduğu gürültüydü (`noise.wav`, `Fs = 22050`, `y` için `66150x1 double`; ekrandan, 01:05:00). Rastgele üretilmiş genlik değerleri hiçbir bilgi taşımaz ve arka plan gürültüsü gibi duyulur. Hoca öğrencilere bunun frekans bileşenlerinin ne olacağını sordu. Spektrogramda frekanslar dağılmıştı: zamanın her anında bütün frekanslar vardı. Buradan şu çıkarım yapıldı: gürültü bütün frekansları içeren karmaşık bir yapıdır.

> **Ek bilgi (derste anlatılmadı):** Birbirinden bağımsız rastgele örneklerden oluşan gürültüye beyaz gürültü denir. Güç spektral yoğunluğu bütün frekanslarda ortalama olarak sabittir; adını bütün renkleri (frekansları) içeren beyaz ışıktan alır.

### 5.6 Kendi kaydının spektrogramı

Derste bir öğrenci kendi kaydettiği "a, b, c" sesinin biri poşet hışırtılı, biri hışırtısız iki spektrogramını hocaya gösterdi. Hoca bu tür deneylerde spektrogramın farklı olayları (konuşma, arka plan sesi, vuruş) zamanda nasıl ayırdığının gözlendiğini belirtti. Ayrıca aynı kaydın farklı örnekleme frekanslarında spektrogramlarının karşılaştırılmasını önerdi. Bu uygulamanın metni Örnek Sorular bölümündedir.

## 6. Çok Çözünürlüklü Analiz ve Dalgacık Dönüşümü

### 6.1 Neden çok çözünürlük?

Zaman-frekans analiz yöntemlerinin en basiti ve ilki STFT'dir. Bunun dışında çok çözünürlüklü analiz (multi-resolution analysis) yaklaşımı ortaya çıkar; en önemli yöntemi dalgacık dönüşümüdür (wavelet transform). Dalgacık dönüşümü STFT'nin çözünürlük problemine alternatif olarak geliştirilmiştir: STFT'de tek bir çözünürlükle, yani sabit pencere genişliğiyle çalışılır ve bu aşılmak istenir.

STFT ile benzer yanı, işaretin bir temel fonksiyonla çarpılmasıdır. DFT ya da FFT'de temel fonksiyonlar sürekli sinüzoidal yapılardır. Dalgacıkta amaç farklı frekanslarda farklı çözünürlükle analiz yapmaktır. Bazı yerlerde zaman çözünürlüğü yükseltilip frekans çözünürlüğü düşürülür, bazı yerlerde ise tersi yapılır.

Genel yaklaşım şudur:

- Yüksek frekanslarda iyi zaman çözünürlüğü, kötü frekans çözünürlüğü hedeflenir. Yüksek frekanslı bileşenler biyomedikal işaretlerde her zaman oluşmaz; oluştuğunda zamanda iyi yakalanmaları gerekir. Bunun için pencerenin dar olması gerekir.
- Düşük frekanslarda iyi frekans çözünürlüğü, kötü zaman çözünürlüğü hedeflenir. İşaretin çoğunluğunu oluşturan alçak frekansların frekans analizi iyi yapılmalıdır; zaman çözünürlüğünün düşük olması kabul edilebilir.

Bu bir ödünleşimdir (trade-off): biri artınca diğeri azalır. Hoca bu yaklaşımın özellikle kısa süreli yüksek frekanslı bileşenler üreten ve uzun süreli alçak frekanslı bileşenlerle devam eden işaretler için önemli olduğunu, biyomedikal işaretlerin çoğunun da böyle olduğunu söyledi. Dalgacık dönüşümü aynı işareti farklı frekans bantlarıyla analiz eder ve hangi frekans bantlarının hangi zaman aralıklarında oluştuğunu verir.

### 6.2 Sürekli dalgacık dönüşümü (CWT)

Slayttaki tanım (ekrandan, 01:35:00):

$$\mathrm{CWT}_x^{\psi}(\tau,s)=\Psi_x^{\psi}(\tau,s)=\frac{1}{\sqrt{|s|}}\int x(t)\,\psi^*\!\left(\frac{t-\tau}{s}\right)dt$$

- $\tau$: öteleme (translation), yani pencerenin işaret üzerindeki konumu.
- $s$: ölçek (scale), pencerenin darlığını ya da genişliğini ayarlar.
- $\psi$: ana dalgacık (mother wavelet).

Hoca bunu sürekli Fourier dönüşümüyle yan yana koydu: $X(f)=\int_{-\infty}^{\infty}x(t)\,e^{-j\omega t}\,dt$. İki formül çok benzer. Fark şudur: Fourier'de temel fonksiyon sinüzoidaldir ve sonsuza kadar sürer; dalgacıkta ise ana dalgacık sönümlü bir işarettir, belli bir yerden sonra yok olur. Bu sayede pencereleme dönüşümün içinde doğal olarak yapılır. STFT'de işaret ayrıca bir pencere fonksiyonuyla çarpılıyordu; burada buna gerek yoktur, çünkü dalgacığın kendi genişliği yalnız o bölgedeki işaretle uğraşılmasını sağlar. Dalgacık işaret boyunca adım adım kaydırılır; ölçek de değişken olduğu için farklı ölçeklerde farklı frekans katsayıları yakalanır.

Slayttaki tanımlar (ekrandan, 01:35:00):

- Wavelet: küçük dalga (small wave); pencere fonksiyonunun sonlu uzunlukta olması demektir. Türkçedeki "dalgacık" adı da "-cık" ekiyle bu küçüklüğü anlatır.
- Ana dalgacık: diğer pencere fonksiyonlarını üretmek için kullanılan prototiptir. Kullanılan bütün pencereler onun genişletilmiş ya da sıkıştırılmış ve ötelenmiş kopyalarıdır. Farklı dalgacık tipleri vardır.

### 6.3 Ölçek parametresi

Slayttaki bilgi (ekrandan, 01:40:00):

- $s>1$: işareti genişletir (dilate).
- $s<1$: işareti sıkıştırır (compress).
- Düşük frekans → yüksek ölçek → ayrıntısız, genel görünüm → bütün işarete yayılır.
- Yüksek frekans → düşük ölçek → ayrıntılı görünüm → kısa sürer.
- Yalnız sınırlı bir ölçek aralığı gereklidir.

Ölçek büyüdükçe ana dalgacık genişler; küçük olduğunda hemen sönümlenir. Birden büyük $s$ değerlerinde geniş dalgacık düşük frekansları yakalar. Birden küçük $s$ değerlerinde daraltılmış dalgacık hızlı değişimleri, yani yüksek frekansları yakalar. Bunun nedeni yine benzerliktir: $x(t)$ ile temel fonksiyonun çarpımı, temel fonksiyon $x(t)$'ye ne kadar benziyorsa o kadar yüksek değer üretir.

### 6.4 Zaman-frekans düzleminin bölünmesi

Hoca, dalgacık dönüşümünün işaret üzerinde nasıl gezdiğini gösteren slaytları anlattı. Ardından zaman-frekans çözünürlüğünü gösteren kutu diyagramına geçti (ekrandan, 01:50:00). Diyagramda yatay eksen zaman, dikey eksen frekanstır. En alttaki düşük frekans bandında kutular frekans yönünde dar, zaman yönünde geniştir: frekans aralığı bellidir, ama olayın zamanın hangi kısmında olduğu belirsizdir. Frekans arttıkça kutular frekans yönünde büyür, zaman yönünde daralır (2 kutu, 4 kutu, 8 kutu). En üstteki yüksek frekans bandında frekans aralığı belirsizleşir, ama zamanda nerede olunduğu bilinir. Slayttaki etiketler: yukarıda "daha iyi zaman çözünürlüğü, kötü frekans çözünürlüğü", aşağıda "daha iyi frekans çözünürlüğü, kötü zaman çözünürlüğü".

### 6.5 Dönüşümlerin karşılaştırılması

Hoca dört gösterimi karşılaştıran bir slaytı da anlattı:

- Zaman serisi: hangi değerin ne zaman oluştuğu bilinir; zaman çözünürlüğü iyidir, frekansla ilgili bilgi yoktur.
- Fourier dönüşümü: işaretin frekansıyla ilgili bilgi vardır, zamanla ilgili bilgi yoktur.
- STFT: pencere aralıkları sabittir; bu aralıklarda hangi frekansların oluştuğu bilinir. Pencere daraldıkça frekans çözünürlüğü düşer, genişledikçe zaman çözünürlüğü düşer.
- Dalgacık dönüşümü: düşük frekanslarda iyi frekans, kötü zaman çözünürlüğü; yüksek frekanslarda iyi zaman, kötü frekans çözünürlüğü. Pencere boyunu ölçek ayarlar.

> **Ders sonrası not:** Hoca dalgacık dönüşümünü özetlerken düşük frekanslar için "iyi zaman rezolüsyonu, kötü zaman rezolüsyonu" dedi. Bu bir dil sürçmesidir; doğrusu, düşük frekanslarda iyi frekans çözünürlüğü ve kötü zaman çözünürlüğüdür. Hoca hemen ardından $s>1$ için pencerenin genişlediğini ve frekans çözünürlüğünün iyileştiğini söyleyerek doğrusunu verdi.

### 6.6 Önerilen kaynak

Hoca konuyu iyi özetleyen kaynak olarak Robi Polikar'ın "The Wavelet Tutorial" adlı çevrimiçi anlatımını gösterdi (ekrandan, 01:45:00). Kaynak dört bölümden oluşur:

- Part 1: Genel bakış, neden dalgacık dönüşümü?
- Part 2: Temeller; Fourier dönüşümü, kısa zamanlı Fourier dönüşümü ve çözünürlük problemleri.
- Part 3: Çok çözünürlüklü analiz; sürekli dalgacık dönüşümü.
- Part 4: Çok çözünürlüklü analiz; ayrık dalgacık dönüşümü.

Hoca bu kaynağın yalnız dalgacığı değil Fourier dönüşümünün temel özelliklerini de anlattığını, dilinin kolay olduğunu ve konuları daha çok görseller üzerinden işlediğini söyledi.

## 7. Ayrık Dalgacık Dönüşümü ve MATLAB Wavelet 1-D Aracı

### 7.1 Filtre bankası yaklaşımı

Hoca ayrıntısına girmeden ayrık dalgacık dönüşümünün nasıl yapıldığını anlattı ve öğrencilerin bundan yalnız genel bilgi düzeyinde sorumlu olduğunu belirtti. Dalgacık dönüşümü iki tür filtreyle uygulanır: alçak geçiren filtre işaretin düşük frekanslarını, yani yaklaşıklığını (approximation) bulur; yüksek geçiren filtre ise yüksek frekanslarını, yani detayını (detail) bulur. Her seviyede yalnız alçak frekanslı kısım yeniden ayrıştırılarak ilerlenir.

### 7.2 MATLAB Wavelet 1-D arayüzü

Hoca MATLAB'in hazır dalgacık arayüzünü (Wavelet 1-D) açtı (ekrandan, 01:55:00) ve hazır örnekler arasından bir kalp işareti yükledi.

**1 seviyeli dönüşüm.** "Analyze" düğmesiyle tek seviyeli dönüşüm uygulandı. Alçak geçiren filtreden elde edilen yaklaşıklık işaretin düşük frekanslı bileşenlerini korur; değerleri özgün işaretin ortalaması civarındadır (hoca 2300-2900 aralığını gösterdi). Yüksek geçiren filtreden elde edilen detay ise işaretin yüksek frekanslı bileşenlerinin bulunduğu yerlerde, özellikle tepe noktalarında, büyük değerler alır. Hoca bir yerde detay seviyesinin 60'larda, başka bir yerde 260'larda olduğunu göstererek orada yüksek frekanslı içeriğin arttığını söyledi. Yaklaşıklık ve detay birleşince yukarıdaki özgün işaret elde edilir.

Hoca bunu şöyle yorumladı: alçak geçiren filtre, zamandaki yer bilgisinin çok önemli olmadığı düşük frekanslı bilgiyi koparır. Yüksek frekanslı bileşenlerde ise zamanın ve yerin tam olarak belirlenmesi gerekir; burada frekans çözünürlüğü kötüdür ama yer tam olarak bulunabilir.

**2 seviyeli dönüşüm.** İkinci seviyede önceki seviyenin yaklaşıklığına bir kez daha dalgacık dönüşümü uygulandı. Birinci seviyenin detayı aynı kaldı; yalnız alçak geçiren bileşen yeniden ayrıştırıldı. Böylece bir seviye daha alçak frekanslı bir yaklaşıklık ve alçak frekansların detayları elde edildi.

### 7.3 Frekans bantlarının ayrışması

Slayttaki örnek (ekrandan, 02:00:00): 512 örnekten oluşan ve 0-1000 Hz bandını kapsayan bir $x[n]$ işareti üç seviyede ayrıştırılıyor. Slaytın başında "yalnız yarı sayıda örnek elde edilir" ve "frekans çözünürlüğü iki katına çıkar, kapsanan frekans bandı yarıya iner" ifadeleri vardır.

| Seviye | Çıkış | Frekans bandı | Örnek sayısı |
|---|---|---|---|
| 1 | D1 (detay) | 500-1000 Hz | 256 |
| 1 | A1 (yaklaşıklık) | 0-500 Hz | 256 |
| 2 | D2 | 250-500 Hz | 128 |
| 2 | A2 | 0-250 Hz | 128 |
| 3 | D3 | 125-250 Hz | 64 |
| 3 | A3 | 0-125 Hz | 64 |

Adım adım:

- Verilen: $x[n]$, 512 örnek, 0-1000 Hz.
- Seviye 1: bant ortadan ikiye bölünür. Yüksek yarı D1 = 500-1000 Hz, alçak yarı A1 = 0-500 Hz; her biri 256 örnek.
- Seviye 2: yalnız A1 ayrıştırılır. D2 = 250-500 Hz, A2 = 0-250 Hz; her biri 128 örnek.
- Seviye 3: yalnız A2 ayrıştırılır. D3 = 125-250 Hz, A3 = 0-125 Hz; her biri 64 örnek.
- Sonuç: işaret D1, D2, D3 ve A3 ile temsil edilir; toplam $256+128+64+64=512$ örnek (ara adım eklendi).

Bunun faydası şudur: yüksek frekanslı detay katsayılarında hangi olayın ne zaman oluştuğu bilgisi korunur. Yaklaşıklıklar ise düşük frekanslardaki yüksek frekans çözünürlüğü sayesinde yeniden oluşturulmuş işaretleri verir. Hoca konunun ayrıntısının önerilen kaynak okundukça daha iyi anlaşılacağını söyledi.

### 7.4 Kullanım alanları

Dalgacıklar hemen bütün bilimsel alanlarda kullanılır:

- Görüntü işleme.
- Saf frekansları tanımlama.
- Gürültü giderme (denoising).
- Görüntülerdeki süreksizlikleri ve kırılma noktalarını bulma.
- Benzerlik analizi.
- Görüntü sıkıştırma: JPEG sıkıştırmada DCT kullanılırken JPEG 2000 standardı ayrık dalgacık dönüşümü katsayılarını kullanır.

### 7.5 İşaret işleme bölümünün özeti

Hoca, dersin işaret işleme kısmında anlatacaklarının bunlar olduğunu söyledi: bir işaretin ayrıklaştırılması, Nyquist frekansı ve dikkat edilmesi gerekenler, ayrık zamanda işlemenin nasıl yapıldığı, standart frekans analizi yöntemlerinin eksiklikleri ve bunlara çare olarak geliştirilen zaman-frekans yöntemleri. Sonraki kısım görüntü işlemedir.

## 8. Görüntü İşlemeye Giriş

### 8.1 İmge kavramı

Şimdiye kadar hep bir boyutlu işaretlerle, $x(t)$ ile uğraşıldı ve temel değişken $t$ idi. Görüntü işlemede değişkenler zaman yerine uzamsal (spatial) parametrelerdir: $u$ ve $v$ yönleri. Yani artık bir matrisle uğraşılır.

Gri seviye bir resim tek bir matrisle ifade edilir; her piksel beyazdan siyaha kadar grinin bir tonunu tutar. Renkli bir resim için ise kırmızı (red), yeşil (green) ve mavi (blue) bileşenlerini saklayan üç matrise ihtiyaç vardır. Her katmana düzlem (plane) denir. Her durumda görüntü iki boyutlu matrislerden oluşur: bir boyutlu işaretler dizi (array) olarak tutulurken görüntüler matris olarak tutulur.

### 8.2 Uygulama alanları

Slayttaki "İmge İşleme ve Uygulama Alanları" listesi (ekrandan, 02:05:00):

- Tıp ve biyoloji (x-ışınları, biyomedikal görüntüler).
- Coğrafi bilimler (jeodezi, hava ve uydu görüntülerinden hava tahmini).
- Restorasyon (eski, hasar görmüş fotoğrafların onarılması).
- Fizik (elektron mikroskobu görüntüleri, spektrometreler).
- Uzay bilimleri (uydu, mikrodalga radar görüntüleri).
- Savunma sanayi (gece görüş, akıllı roket sistemleri).
- Endüstriyel uygulamalar (süreç, ürün denetimi).
- Tüketici elektroniği (VCD, DVD, video kayıt cihazları, cep telefonları).
- Güvenlik sistemleri (iris-parmak izi tanıma, güvenlik-kamera uygulamaları).

Hoca uzaktan algılamada SAR, multispektral ve hiperspektral görüntüleri; savunmada nesne ya da hedef tespitini; endüstride hata tespitini ve süreçlerin düzgün işleyip işlemediğinin denetimini örnek verdi.

Video, renkli ya da siyah beyaz çerçevelerin (frame) arka arkaya oynatılmasıdır; örneğin saniyede 25 çerçeve (25 fps) gösterilince hareketli görüntü elde edilir. Her çerçeve bir imge olduğu için video da görüntü işlemenin konusudur. Hoca "image processing" karşılığı olarak hem "görüntü işleme" hem "imge işleme" dendiğini, bazılarının "görüntü" kelimesini videoyu da kapsayacak biçimde kullandığını belirtti. Derste alışılageldiği üzere "görüntü işleme" denir. Video işaretleri ve televizyon iletimi başka bir dersin konusudur.

### 8.3 Görüntünün oluşumu

Bir görüntünün oluşması için önce doğal ya da yapay bir ışık kaynağı nesneyi aydınlatır. Nesnede soğurulan (absorbe edilen) ışık yansımaz; yansıyan ışık bir sensör (kamera ya da göz) tarafından algılanır ve kaydedilerek matris yapısı oluşturulur. Buna görüntü uzayı ya da uzamsal domen (spatial domain) denir.

### 8.4 Sayısal imge ve koordinatlar

Slayttaki tanım (ekrandan, 02:10:00): "İmge iki boyutlu ışık-yoğunluk fonksiyonu olarak adlandırılabilir ve $f(x,y)$ ile gösterilir. $(x,y)$ koordinatları belirtmekte, $f(x,y)$ fonksiyonunun değeri ise $(x,y)$ noktasındaki pikselin ışıklılık (intensity) değerini ifade etmektedir."

Matrisin her gözündeki değer o piksele düşen ışık yoğunluğudur. Çok ışık yansımayan yerler karanlık (dark), çok yansıyan yerler aydınlık (light) bölgelerdir.

MATLAB'de ve Python'da dikkat edilmesi gereken bir nokta vardır: görüntü kavramsal olarak $I(x,y)$ diye düşünülse de matris olarak $I(y,x)$ biçiminde tutulur; ilk indis satır, ikinci indis sütundur (ekrandan, 02:10:00). Başlangıç noktası sol üst köşedir ve $y$ aşağı doğru artar. Hoca tahtada $I(10,0)$'ın 10. satırı, $I(0,10)$'un ise 10. sütunu gösterdiğini işaretledi. Alışılmış koordinat sisteminde yukarı doğru çıkılırken burada mantık terstir; programlama dillerine göre de farklılık olabilir.

> **Ders sonrası not:** Hoca başlangıç noktasını $(0,0)$ diye anlattı. Bu Python (NumPy) için doğrudur; MATLAB'de matris indisleri büyük olasılıkla 1'den başlar, yani sol üst piksel MATLAB'de `I(1,1)`'dir.

### 8.5 Analogdan sayısala

Gözümüzle gördüğümüz görüntü analogdur. Gözde gelen ışık koni ve çubuk hücreler tarafından algılanır, beyinde bir imge oluşur ve burada piksel kavramı yoktur. Film kullanan fotoğraf makinelerinde de ışık mercekten geçip filme düşer; filmin kimyasal yapısı her noktada o bölgenin parlaklığını piksel kavramı olmadan kaydeder.

> **Ders sonrası not:** Hoca konilerin parlaklık, çubukların renk bilgisini taşıdığını söyledi. Doğrusu tersidir: koni hücreler renk görmeyi sağlar, çubuk hücreler ise düşük ışıkta parlaklığa (ışık şiddetine) duyarlıdır.

Sayısal makinelerde (ör. DSLR) piksel kavramı vardır. Tek boyutlu analog işareti örneklediğimiz gibi burada da örnek alınır, ama örnekler hem $x$ hem $y$ yönündedir. Sayısallaştırma iki adımdan oluşur (ekrandan, 02:15:00):

$$\text{Sayısallaştırma}=\text{Örnekleme}+\text{Nicemleme}$$

- Örnekleme: işaretten belirli zaman anlarında örnek alınmasıdır. İki boyutlu imgelerde uzamsal düzlemin sayısallaştırılmasına karşılık gelir; piksel sıklığını belirler.
- Nicemleme (kuantalama): genlik seviyelerinin yalnız belirli değerleri almasıdır; genlik değerlerinin sayısallaştırılmasına karşılık gelir.

Hoca bir boyutlu durumu hatırlattı: önce işaret örneklenir; sonra sonsuz değer alabilen seviyeler, kullanılan bit sayısına göre belirli aralıklara (kuantalara) çekilir. Bit sayısı arttıkça daha ince ayrıntıya girilebilir. Görüntüde de her pikselin parlaklık seviyesi 8 bit kullanılırsa 256 seviyeyle, 16 bit kullanılırsa 65536 seviyeyle saklanır (ekrandan, 02:15:00). Yani her göze 0-255 arası mı, 0-65535 arası mı değer yazılacağı nicemlemeyle belirlenir. Elektronik olarak bu iş örnekle-tut devresiyle yapılır: bir pikselin parlaklık değeri alınıp tutulur, matris gözleri sırayla dolaşılır ve analog-sayısal dönüştürücüyle sayısal değere çevrilir.

### 8.6 Piksel

Slaytta 200x200 piksellik bir görüntünün büyütülmüş bir bölgesi ve o bölgenin piksel değerleri tablo halinde gösterildi (ekrandan, 02:25:00). Örneklenen her elemana resim elemanı (picture element), piksel ya da pel denir. Tablodaki değerler 0-255 aralığındadır (ör. ilk satır 202, 215, 203, 179, ...); parlak bölgelerde değerler 255'e yakın, karanlık bölgelerde küçüktür (ör. 37, 41, 42).

Görüntü özgün sahne gibi sürekli değildir. Ancak pikseller çok küçük bir alanda çok sık taranırsa belli bir çözünürlük yeterli olur. Tıbbi görüntüler ve uzay görüntüleri gibi çok ayrıntı isteyen uygulamalarda piksel sayısı çok daha önemli hale gelir. Hoca örnek görüntüde horozun ibiği ile arka planın aynı pikselde ortak bir parlaklık değeri aldığını gösterdi; bunları ayırmak için çözünürlüğün artırılması gerekir. Görüntüye çok yaklaşıldığında her pikselin karesel etkisi görünür hale gelir.

### 8.7 Uzamsal çözünürlük

Aynı alan farklı piksel sayılarıyla çekildiğinde (256x256, 128x128, 64x64, 32x32 piksel) birim alana düşen parlaklık kaydı sayısı değişir (ekrandan, 02:20:00 ve 02:25:00). Piksel sayısı azaldıkça ayrıntılar, ön plan ile arka plan arasındaki ayrım kaybolur ve karelenme belirginleşir. Hoca 256x256 görüntünün 72 piksel/inç'e karşılık geldiğini, 32x32 görüntüde ise slaytta 9 ppi yazdığını gösterdi (ekrandan, 02:20:00). Çekilen alan ve fiziksel boyut aynı, yalnız çözünürlük farklıdır.

Çözünürlük, imgenin piksel sayısının birim fiziksel boyuta bölünmesiyle bulunur. Birimi genellikle piksel/inç (ppi) ya da nokta/inç (dpi, dot per inch) olur; 1 inç yaklaşık 2,54 cm'dir.

Verilen değerlerden fiziksel boyut kontrol edilebilir (ara adım eklendi):

- 256 piksel / 72 ppi ≈ 3,56 inç.
- 32 piksel / 9 ppi ≈ 3,56 inç.
- Fiziksel boyut her iki görüntüde de yaklaşık 3,6 inç × 3,6 inç'tir.
- Aynı boyutta 128x128 için yaklaşık 36 ppi, 64x64 için yaklaşık 18 ppi düşer (ara adım eklendi).

> **Ders sonrası not:** Hoca fiziksel boyutu söylerken "3,6 inç'e 3,6 fut" dedi. Yukarıdaki hesap fiziksel boyutun büyük olasılıkla 3,6 inç × 3,6 inç olduğunu gösterir; "fut" bir sürçmedir.

### 8.8 Nicemsel çözünürlük

Pikseller belirlendikten sonra her pikselin değerinin kaç bitle saklanacağı nicemsel çözünürlüğü belirler. Gri seviye bir görüntüde (renkli resimler şimdilik düşünülmüyor) 8 bit kullanılırsa 0 tam karanlık, 255 tam aydınlık olmak üzere 256 seviye vardır. Bit sayısı $b$ ise seviye sayısı $2^b$'dir:

| Bit | Seviye sayısı | Değer aralığı |
|---|---|---|
| 8 | 256 | 0-255 |
| 7 | 128 | 0-127 |
| 5 | 32 | 0-31 |
| 4 | 16 | 0-15 |
| 1 | 2 | 0-1 |

Hoca slayttaki örnekte 8 ve 7 bit arasında farkın gözle pek belli olmadığını, 5 bitte gökyüzü geçişlerinde bantlaşmanın başladığını, 4 bitte ise geçişlerin çok keskinleştiğini gösterdi. 1 bitte görüntü yalnız siyah (0) ve beyazdan (1) oluşur; buna siyah beyaz (black and white) resim denir. Bit sayısı azaldıkça ayrıntılar ve gri ton geçişleri kaybolur.

### 8.9 Soru-cevap

**Soru:** Görüntü işlemede resmi neden gri seviye olarak ele alıyoruz?

**Cevap:** Hoca en basit durumdan başladıklarını söyledi. Önce bir boyutlu işaretler işlendi; iki boyutlu bir matriste her göze tek bir değer yazılırsa bu gri seviye resme karşılık gelir. Renkli resimlerde kırmızı, yeşil ve mavi bantlarda çekilmiş üç matris vardır. Gri seviye için anlatılanların hepsi bu renk bantlarının her biri için de geçerlidir. Renk bantlarının nasıl oluştuğu ileride anlatılacaktır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:50:15; değerler ekrandan, 00:50:00 ve 01:00:00): Bir ses kaydında 139217 örnek vardır ve örnekleme frekansı 44100 Hz'tir. Bu bilgilerle kaydın ne kadar sürdüğü bulunabilir mi?

Çözüm (derste verildi): Örnekleme frekansı saniyede alınan örnek sayısıdır. Süre, toplam örnek sayısının örnekleme frekansına bölünmesiyle bulunur. Derste örnek sayısı yuvarlanarak yaklaşık 140000 alındı ve MATLAB'de hesaplanan sonuç `ans = 3.1746` olarak göründü (ekrandan, 01:00:00):

$$\frac{140000}{44100}\approx 3{,}17\ \text{s}$$

Tam örnek sayısıyla:

$$T=\frac{N}{f_s}=\frac{139217}{44100}\approx 3{,}16\ \text{s}$$

Kayıt yaklaşık 3 saniye sürer. Spektrogramın zaman ekseni de bunu doğrular.

**Soru 2** (derste sözlü, 01:02:59; değerler ekrandan, 01:05:00): 22050 Hz'te örneklenmiş, yaklaşık 66000 örnekli bir müzik kaydı ne kadar sürer?

Çözüm (derste verildi): $66000/22050\approx 2{,}99$ s, yani yaklaşık 3 saniye. Aynı örnekleme frekansındaki gürültü dosyası için çalışma alanında 66150 örnek görünüyordu; $66150/22050=3$ s'dir.

**Soru 3** (derste sözlü, 00:40:38): Kısa zamanlı Fourier dönüşümünde en büyük sorun ne olabilir?

Çözüm (derste verildi): Pencere genişliğinin seçimidir. Dar pencere iyi zaman ve kötü frekans çözünürlüğü, geniş pencere iyi frekans ve kötü zaman çözünürlüğü verir. Pencere baştan seçilir ve bütün analiz boyunca sabittir. İşaretin frekans içeriği önceden bilinmediği için seçilen pencerenin frekansları zamanda ayırıp ayırmayacağı bilinemez.

**Soru 4** (derste sözlü, 00:58:08): 128 uzunluklu bir işaretin FFT'si 128 frekans noktası verir. Frekans çözünürlüğünü artırmak için ne yapılabilir?

Çözüm (derste verildi): İşarete sıfırlar eklenerek uzunluk örneğin 256'ya çıkarılır; MATLAB'de `fft(x,256)` bunu otomatik yapar. Bu durumda $X[k]$ 256 noktada hesaplanır ve frekans noktaları arasındaki aralık yarıya iner. (Bu yöntemin sınırı için bölüm 5.3'teki ders sonrası nota bakın.)

**Soru 5** (derste sözlü, 01:04:55): Gauss dağılımından rastgele üretilmiş bir gürültü sinyalinin spektrogramında frekans bileşenleri nasıl görünür?

Çözüm (derste verildi): Bütün frekanslar zamanın her anında bulunur; spektrogram her yerde dağınık bir enerji gösterir. Gürültü bütün frekansları içeren karmaşık bir yapıdır.

**Soru 6** (derste sözlü, 00:33:35): Bir saniyede 2 Hz'den 20 Hz'e çıkan bir chirp ile 20 Hz'den 2 Hz'e inen bir chirp'in DFT genlikleri karşılaştırılırsa ne görülür? Yalnız genlik spektrumuna bakarak hangisinin hangisi olduğu söylenebilir mi?

Çözüm (derste verildi): Genlik gösterimleri aynıdır; bu yüzden yalnız spektruma bakarak hangi işaret olduğu söylenemez. Fourier dönüşümü frekansın ne zaman oluştuğu bilgisini vermez. Ajan tarafından Python ile kontrol edildi: 1000 Hz'te örneklenmiş 1 saniyelik doğrusal bir chirp ile onun zamanda ters çevrilmiş hali için $|X[k]|$ değerleri arasındaki en büyük fark yaklaşık $6\times10^{-14}$, yani sayısal hata düzeyindedir.

**Soru 7** (derste verilen uygulama, 01:05:51): Kendi ses kaydınızı (`.wav`) oluşturun ve MATLAB'in `spectrogram` fonksiyonuyla STFT'sini çıkarıp yorumlayın. Kayıtlar 3-5 saniye olsun ve 22 kHz civarında örneklensin. Farklı zamanlarda frekans değişikliği yaratacak olaylar ekleyin: konuşurken arka planda müzik açmak, kağıt ya da poşet hışırdatmak, iki camı birbirine vurmak, masaya hızlıca vurmak gibi. 3-4 farklı kayıt için hangi olayın yapıldığını spektrogram üzerinde yorumlayın. Bazı kayıtları farklı örnekleme frekanslarında da alıp spektrogramın nasıl değiştiğini inceleyin.

> **Çözüm (derste verilmedi):** Kayıt kişiye özgü olduğu için tek bir cevap yoktur. Derste gösterilen örneklere göre beklenen gözlemler şunlardır. Konuşma bölümleri alçak frekanslarda yoğunlaşır, kelime aralarındaki sessizlikte enerji hemen hiç yoktur. Hışırtı ve vuruş gibi gürültüye benzeyen olaylar, oluştukları kısa zaman aralığında geniş bir frekans bandına yayılır (gürültü dosyasının spektrogramına benzer). Örnekleme frekansı düşürülünce spektrogramın gösterebildiği en yüksek frekans $f_s/2$'ye iner.

## Dersin Toparlaması

Bu derste Fourier dönüşümünün temel bir kısıtı ele alındı: işaretin hangi frekansları içerdiğini söyler, ama bu frekansların ne zaman oluştuğunu söylemez. Durağan işaretlerde bu sorun yaratmaz. Ancak biyomedikal işaretlerin çoğu gibi durağan olmayan işaretlerde zaman-frekans gösterimine ihtiyaç vardır. İlk çözüm olan STFT işareti pencerelere bölüp her pencerenin Fourier dönüşümünü alır. Pencere genişliği sabit olduğu için zaman ve frekans çözünürlüğü arasında bir ikilem doğar. MATLAB'de `spectrogram` ile konuşma, müzik ve gürültü kayıtlarının STFT'leri incelendi; pencere, örtüşme ve `nfft` parametrelerinin anlamı gösterildi. Dalgacık dönüşümü bu ikilemi ölçek parametresiyle aşar. Yüksek frekanslarda dar pencere ile iyi zaman çözünürlüğü, düşük frekanslarda geniş pencere ile iyi frekans çözünürlüğü sağlar. Ayrık dalgacık dönüşümü alçak ve yüksek geçiren filtrelerle işareti yaklaşıklık ve detay bantlarına ayırır.

Dersin son kısmında görüntü işlemeye giriş yapıldı. Görüntü iki boyutlu bir ışık-yoğunluk fonksiyonudur ve matris olarak tutulur: gri seviye görüntü tek, renkli görüntü üç matrisle gösterilir. Sayısallaştırma örnekleme ve nicemlemeden oluşur; örnekleme uzamsal çözünürlüğü (ppi/dpi), nicemleme ise gri seviye sayısını ($2^b$) belirler. Hoca sonraki derste görüntü işlemeye devam edileceğini ve renk bantlarının oluşumuna da değinileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
