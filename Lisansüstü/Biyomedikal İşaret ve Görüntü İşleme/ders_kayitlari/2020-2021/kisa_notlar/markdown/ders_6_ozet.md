# Ders 6 Çalışma Özeti

## Genel Konular

- Fourier dönüşümünün temel fikri ve tarihçesi
  - Fourier dönüşümü işareti karmaşık üstel $e^{-j\omega t}=\cos\omega t - j\sin\omega t$ temel fonksiyonlarıyla (basis function) çarpıp toplar. İşaret bir temel fonksiyona ne kadar benziyorsa o frekansın katsayısı o kadar büyük çıkar; çarpım bir tür iç çarpım, yani benzerlik ölçüsüdür.
  - Slayttaki tarihçe (ekrandan, 00:20:00): 1930 öncesi Joseph Fourier (1807) ve frekans analizi; 1930'lar ölçeğe göre değişen temel fonksiyonlar ve bir fonksiyonun enerjisinin hesabı; 1960-1980 Guido Weiss ve Ronald R. Coifman, Grossman ve Morlet; 1980 sonrası Stephane Mallat, Y. Meyer, Ingrid Daubechies ve günümüz dalgacık uygulamaları.
  - Sürekli ve ayrık Fourier dönüşümü formülleri slaytta birlikte verildi (ekrandan, 00:25:00). Ayrık formül MATLAB'in 1'den başlayan indisleriyle yazılmış: $X(k+1)=\sum_{n=0}^{N-1}x(n+1)\,W_N^{kn}$, $W_N=e^{-j2\pi/N}$.
  - Fourier dönüşümü iki şey söyler: işarette hangi frekansların bulunduğu ve her frekansın ne miktarda bulunduğu. Genlik spektrumu bir tür "frekans histogramı" gibi okunur.
- Durağan ve durağan olmayan işaretler
  - Durağan (stationary) işarette frekans içeriği zamanla değişmez; bütün frekans bileşenleri her an vardır. Örnek: $x(t)=\cos(2\pi\cdot 2t)+\cos(2\pi\cdot 10t)+\cos(2\pi\cdot 20t)$ (ekrandan, 00:30:00).
  - Durağan olmayan işarette frekans zamanla değişir. Slayttaki örnek: 0,0-0,4 s arasında 2 Hz, 0,4-0,7 s arasında 10 Hz, 0,7-1,0 s arasında 20 Hz (ekrandan, 00:30:00).
  - İki işaretin FFT'sinde de 2, 10 ve 20 Hz tepeleri görünür. Durağan olmayan işaretin spektrumunda geçişlerden kaynaklanan dalgalanmalar vardır, ama hangi frekansın ne zaman oluştuğu spektrumdan okunamaz.
  - Chirp (cıvıltı) işareti: frekansı düşükten yükseğe ya da yüksekten düşüğe geçen işaret. 2 Hz'den 20 Hz'e çıkan ve 20 Hz'den 2 Hz'e inen iki chirp zamanda farklıdır, ama genlik spektrumları aynıdır.
- Fourier dönüşümünün kısıtı
  - Fourier dönüşümü yalnız işarette hangi frekans bileşenlerinin bulunduğunu verir; zaman ve frekans bilgisi aynı anda görülemez (ekrandan, 00:35:00).
  - Biyomedikal işaretlerin çoğu durağan değildir (ör. kalp atımında farklı bölümlerde farklı frekanslar). Bu yüzden zaman-frekans gösterimine ihtiyaç vardır.
- Kısa Zamanlı Fourier Dönüşümü (STFT)
  - Dennis Gabor (1946): işaretin yalnız küçük bir bölümü bir seferde incelenir; bu tekniğe işareti pencereleme (windowing) denir. Pencere içindeki parça durağan kabul edilir. Sonuç zaman ve frekansın fonksiyonudur (ekrandan, 00:40:00).
  - Formül (ekrandan, 00:40:00): $\mathrm{STFT}_x^{(\omega)}(t',f)=\int_t \left[x(t)\,\omega^*(t-t')\right] e^{-j2\pi f t}\,dt$, burada $\omega(t)$ pencere fonksiyonudur.
  - Geniş pencere: daha çok örnek ($N$ büyür), iyi frekans çözünürlüğü, kötü zaman çözünürlüğü. Dar pencere: iyi zaman çözünürlüğü, kötü frekans çözünürlüğü.
  - Dezavantajlar: pencere boyu baştan seçilir ve bütün analiz boyunca sabittir; çözünürlük ikilemi vardır. Hoca bunu Heisenberg belirsizlik ilkesine benzetti.
- MATLAB'de STFT uygulaması
  - `audioread` ile `.wav` okunur, `sound` ile dinlenir, `plot(abs(fft(y)))` ile spektrum, `spectrogram` ile STFT çizilir (ekrandan, 00:50:00).
  - `spectrogram(x,window,noverlap,nfft,fs)`: pencere boyu, örtüşme (overlap) miktarı, FFT noktası ve örnekleme frekansı verilir. Derste `spectrogram(y(:,1),256,128,256,Fs)` kullanıldı (ekrandan, 00:50:00).
  - Konuşma ("bir, iki, üç"), müzik (Windows açılış sesi) ve Gauss gürültüsü dosyalarının spektrogramları karşılaştırıldı. Gürültü her anda bütün frekansları içerir.
- Çok çözünürlüklü analiz ve dalgacık dönüşümü
  - Amaç farklı frekanslarda farklı çözünürlükle analiz etmektir: yüksek frekanslarda iyi zaman, kötü frekans çözünürlüğü; düşük frekanslarda iyi frekans, kötü zaman çözünürlüğü.
  - Sürekli dalgacık dönüşümü (CWT) (ekrandan, 01:35:00): $\mathrm{CWT}_x^{\psi}(\tau,s)=\frac{1}{\sqrt{|s|}}\int x(t)\,\psi^*\!\left(\frac{t-\tau}{s}\right)dt$. $\tau$ öteleme (pencerenin konumu), $s$ ölçek, $\psi$ ana dalgacıktır (mother wavelet).
  - Ölçek (ekrandan, 01:40:00): $s>1$ işareti genişletir ve düşük frekansları yakalar (genel, ayrıntısız görünüm); $s<1$ işareti sıkıştırır ve yüksek frekansları yakalar (kısa süren ayrıntılar).
  - Ayrık dalgacık dönüşümü alçak geçiren ve yüksek geçiren filtre çiftiyle yapılır; yaklaşıklık (approximation) ve detay (detail) katsayıları elde edilir.
- Görüntü işlemeye giriş
  - Görüntü, iki boyutlu ışık-yoğunluk fonksiyonu $f(x,y)$'dir. Gri seviye görüntü tek matris, renkli görüntü R, G, B için üç matris (düzlem, plane) ile tutulur.
  - Sayısallaştırma = örnekleme + nicemleme (ekrandan, 02:15:00). Örnekleme uzamsal çözünürlüğü, nicemleme gri seviye sayısını belirler.
  - Uzamsal çözünürlük piksel/inç (ppi) ya da dpi ile ölçülür. Nicemsel çözünürlükte $b$ bit $2^b$ seviye verir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fourier dönüşümünde zaman bilgisi yoktur
  - Aynı frekansları içeren durağan ve durağan olmayan işaretler, ya da yükselen ve inen chirp'ler, benzer veya aynı genlik spektrumu verir. Spektrum, frekansın ne zaman oluştuğunu söylemez.
- Pencere boyu ikilemi
  - STFT'nin temel sorunu pencere genişliğinin ne olacağıdır. İşaretin frekans içeriği önceden bilinmediğinden seçilen pencere frekansları zamanda ayırmayabilir. Dar pencere zamanı, geniş pencere frekansı iyi gösterir; ikisi birlikte iyileştirilemez.
- Dalgacığın mantığı
  - Biyomedikal işaretlerde yüksek frekanslı bileşenler kısa süreli ve seyrek oluşur, bu yüzden zamanda iyi yakalanmalıdır. İşaretin çoğunluğunu oluşturan alçak frekanslarda ise frekans çözünürlüğü önemlidir. Dalgacık dönüşümü bu dengeyi ölçek parametresiyle kurar.
- MATLAB'de matris indisleri
  - Görüntü $I(y,x)$ biçiminde tutulur: ilk indis satır, ikinci indis sütundur. Satırlar aşağı doğru artar; bu, alışılmış koordinat sisteminin tersidir.

## Kısa Tekrar Notları

- Fourier katsayısı = işaretin o frekanstaki temel fonksiyona benzerliği.
- Durağan işaret: frekans içeriği zamanla değişmez. Durağan olmayan: değişir (chirp, EKG).
- FT: "hangi frekans var" der, "ne zaman" demez.
- STFT: pencereleme + FFT. Geniş pencere → iyi frekans, kötü zaman çözünürlüğü; dar pencere → tersi. Pencere boyu sabit.
- `spectrogram(x,window,noverlap,nfft,fs)`; örtüşme, pencerelerin bir kısmının ortak olmasıdır.
- `fft(x,nfft)` işarete sıfır ekleyerek FFT nokta sayısını artırır.
- Örnek sayısı / örnekleme frekansı = kayıt süresi (ör. $139217/44100\approx3{,}16$ s).
- Gürültü her anda bütün frekansları içerir.
- CWT: $\tau$ öteleme, $s$ ölçek, $\psi$ ana dalgacık. $s>1$ düşük frekans, $s<1$ yüksek frekans.
- DWT: alçak geçiren → yaklaşıklık (A), yüksek geçiren → detay (D); her seviyede yalnız A tekrar ayrıştırılır. 0-1000 Hz, 512 örnek: D1 500-1000, D2 250-500, D3 125-250, A3 0-125 Hz (ekrandan, 02:00:00).
- Dalgacık uygulamaları: gürültü giderme, kırılma noktası bulma, sıkıştırma (JPEG 2000 DWT kullanır).
- Görüntü: gri seviye tek matris, renkli üç matris. Sayısallaştırma = örnekleme + nicemleme.
- 8 bit → 256, 16 bit → 65536, 5 bit → 32, 4 bit → 16, 1 bit → 2 seviye.

## Detaylı Açıklamalar

- **Temel fonksiyonla çarpma ne anlama gelir?** Fourier dönüşümünde işaret, frekansı değişen kosinüs ve sinüslerle çarpılıp toplanır. İşaret ile temel fonksiyon aynı yönlerde büyük değerler alıyorsa çarpımların toplamı büyük, birbirine benzemiyorsa pozitif ve negatif katkılar birbirini götürür ve toplam küçük çıkar. Hoca bunu tahtada önce düşük frekanslı, sonra yüksek frekanslı ve düşük genlikli bir fonksiyonla çarparak gösterdi: hangi temel fonksiyon işarete daha çok benziyorsa onun katsayısı en büyük çıkar. Altta kalan alanın hesabı aynı zamanda fonksiyonun enerjisiyle ilgilidir.

- **Durağan işaret örneği.** $x(t)=\cos(2\pi\cdot2t)+\cos(2\pi\cdot10t)+\cos(2\pi\cdot20t)$ işaretinde fazlar yok sayılırsa her $t$ anındaki değer formülden hesaplanabilir; üç frekans her an vardır. FFT'sinde 2, 10 ve 20 Hz'de keskin tepeler çıkar (ekrandan, 00:30:00). Aynı üç frekansın zaman aralıklarına bölündüğü durağan olmayan işaretin FFT'si de bu frekansları gösterir. Ancak geçişlerdeki süreksizlikler yüzünden tepeler daha az keskindir ve araya dalgalanmalar girer. Yalnız spektrum verilseydi 20 Hz'in başta mı, ortada mı, sonda mı oluştuğu söylenemezdi.

- **STFT nasıl çalışır?** İşaret bir pencere fonksiyonuyla çarpılır; pencere dışındaki kısım sıfırlanır ve yalnız pencere içindeki parçanın Fourier dönüşümü alınır. Pencere zaman ekseninde kaydırılarak işaret taranır. Böylece iki eksenli bir gösterim elde edilir: bir eksen zaman, diğeri frekans. Ayrık durumda pencere içindeki örnek sayısı $N$ ise $X[k]$, $k=0,\dots,N-1$ için hesaplanır. Pencereyi genişletmek $N$'yi artırır, frekans çözünürlüğü iyileşir, ama frekansın hangi zaman aralığında oluştuğu bilgisi bulanıklaşır. Slayttaki 3B çizimlerde dar pencerede tepeler zamanda ayrık ama frekans ekseninde Gauss gibi yayvan, geniş pencerede ise frekansta keskin ama zamanda iç içe geçmiş görünür (ekrandan, 00:45:00).

- **Örtüşme ve nfft.** `spectrogram(y(:,1),256,128,256,Fs)` çağrısında pencere 256 örnek, örtüşme 128 örnektir. Yani ikinci pencere birincinin son 128 örneğini ve 128 yeni örneği alır. Dördüncü parametre 256 noktalı FFT, beşinci parametre örnekleme frekansıdır. `Fs` verilince eksenler örnek ve normalize frekans yerine saniye ve Hz olarak çizilir (ekrandan, 00:50:00 ve 01:00:00). `fft(x,256)` gibi bir çağrı 128 örneklik işarete sıfır ekleyerek 256 noktalı FFT hesaplar; bu sayede spektrum daha sık frekans noktalarında görülür.

- **Ses örnekleri.** "Bir, iki, üç" kaydı 44100 Hz'te örneklenmiş, iki kanallı 139217 örnektir (ekrandan, 00:50:00). Süresi yaklaşık $139217/44100\approx3{,}16$ s'dir. Spektrumda en yüksek frekans 22050 Hz olup örnek sayısının yarısına karşılık gelir. Spektrogramda "bir" denirken alçak frekanslar yoğunlaşır, kelimeler arasındaki sessizlikte hemen hiç frekans yoktur, "üç" denirken yüksek frekanslı bir bileşen belirir. Windows açılış sesi (22050 Hz, yaklaşık 3 s) başta az alçak frekans içerir, sona doğru alçak frekanslar yayılır, bazı yüksek frekanslı izler zamanla alçalarak kaybolur. Gauss dağılımından üretilen gürültünün spektrogramında bütün frekanslar her anda vardır.

- **Dalgacık dönüşümü.** STFT'de pencere sabittir; dalgacık dönüşümünde ise temel fonksiyonun kendisi sönümlü, sonlu uzunlukta bir "küçük dalga"dır. Bu yüzden ayrıca pencere fonksiyonuyla çarpmaya gerek yoktur: pencereleme dönüşümün içinde doğal olarak yapılır. Ana dalgacık $\psi$ bir prototiptir; kullanılan bütün pencereler onun genişletilmiş ya da sıkıştırılmış ve ötelenmiş kopyalarıdır (ekrandan, 01:35:00). Dalgacık işaret boyunca adım adım kaydırılır ve işarete en çok benzediği yerde büyük katsayı üretir. Zaman-frekans düzleminin bölünmesinde yüksek frekanslarda kutular zamanda dar, frekansta geniş; düşük frekanslarda zamanda geniş, frekansta dardır (ekrandan, 01:50:00).

- **Ayrık dalgacık dönüşümü ve MATLAB Wavelet 1-D aracı.** Her seviyede işaret alçak geçiren ve yüksek geçiren filtreden geçirilir. Alçak geçiren çıkış yaklaşıklık (A), yüksek geçiren çıkış detaydır (D). Bir sonraki seviyede yalnız yaklaşıklık yeniden ayrıştırılır, detaylar aynı kalır. Slayttaki örnekte 0-1000 Hz bandında 512 örneklik $x[n]$ için: D1 500-1000 Hz (256 örnek), A1 0-500 Hz; D2 250-500 Hz (128 örnek); D3 125-250 Hz (64 örnek) ve A3 0-125 Hz (64 örnek) (ekrandan, 02:00:00). Hoca MATLAB'in Wavelet 1-D arayüzünde bir kalp işaretine 1 ve 2 seviyeli dönüşüm uyguladı. Yaklaşıklık işaretin alçak frekanslı genel biçimini korur, detay ise yüksek frekanslı bileşenlerin olduğu tepe noktalarında büyük değer alır. Yaklaşıklık ile detay birleşince özgün işaret geri elde edilir.

- **Sayısal görüntü.** Gözde ve film fotoğraf makinesinde görüntü analogdur, piksel kavramı yoktur. Sayısal makinede önce örnekleme yapılır (piksel sıklığı), sonra her pikselin parlaklığı belirli sayıda bitle nicemlenir; elektronik olarak örnekle-tut devresi ve analog-sayısal dönüştürücü kullanılır. Aynı alan 256x256, 128x128, 64x64 ve 32x32 piksel ile çekildiğinde piksel sayısı azaldıkça ayrıntılar kaybolur ve karelenme görünür hale gelir (ekrandan, 02:20:00 ve 02:25:00). Nicemlemede bit sayısı azaldıkça özellikle gökyüzü gibi yumuşak geçişlerde bantlaşma başlar (5 bit ve 4 bit); 1 bitte görüntü yalnız siyah ve beyazdan oluşur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
