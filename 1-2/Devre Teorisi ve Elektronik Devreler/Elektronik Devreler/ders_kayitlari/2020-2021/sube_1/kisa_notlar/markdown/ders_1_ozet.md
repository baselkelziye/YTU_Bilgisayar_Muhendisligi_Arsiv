# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve kaynağı
  - Elektronik Devreler, bilgisayar mühendisliği için donanımın temel kavramlarını veren bir derstir. Elektronik mühendisliğindeki derin analizlere girmeden temel elemanlar ve devreler anlatılır.
  - İşlenecek konular: yarı iletken fiziği, diyot modelleri, doğrultucular, zener diyot ve diğer diyot uygulamaları <!-- BELİRSİZ: altyazıda "lojik diyotlar" geçiyor (00:12:20); kastedilen büyük olasılıkla özel amaçlı diyotlar ya da diyotlu lojik kapılar -->, bipolar jonksiyonlu transistörler (BJT) ve DC analizleri, FET transistörler, işlemsel yükselteçler (op-amp).
  - Ana kaynak Boylestad ve Nashelsky'nin *Electronic Devices and Circuit Theory* kitabıdır. Slaytlar bu kitaptan alınmıştır; kitabın Türkçe çevirisi de vardır. İçinde çok sayıda çözümlü soru bulunur.
  - Devre denemek için CircuitLab gibi kurulum gerektirmeyen çevrim içi simülatörler ve Proteus kullanılabilir.
- Donanım dersleri arasındaki yeri
  - Donanım zinciri: Devre Teorisi, Yarı İletken Fiziği, Elektronik Devreler, Lojik Devreler, Bilgisayar Donanımı, Bilgisayar Mimarisi, Mikroişlemciler, Gömülü Sistemler.
  - Donanımdan yazılıma geçiş işletim sistemleri üzerinden olur. Üstünde düşük seviyeli diller (Assembly, C) ve en üstte yüksek seviyeli diller (Python gibi) yer alır.
  - Bir transistörlü devrede girişe +5 V verildiğinde çıkışın 0 mı 1 mi olacağı gibi dijital bilgi elektrik sinyalleriyle taşınır (ekrandan, 00:25:00).
- Transistörün tarihsel önemi
  - 1950'li yıllarda bilgisayar mühendisliğinin doğuşunu hızlandıran buluş transistördür.
  - Transistörün iki temel kullanımı: gerilim yükseltici ve 1/0 mantığıyla çalışan ikili (binary) elektrik devreleri (ekrandan, 00:30:00).
  - Öncesinde cam gövdeli, ısınması beklenen tüplü yapılar (tüplü radyolar) vardı. Sıcaklıktan çok etkilenir, kararsız çalışır, çok ısı verirlerdi. Silisyum ve germanyum gibi yarı iletkenlerle bu yapılar ucuzladı ve küçüldü.
  - İkinci Dünya Savaşı haberleşme, istihbarat, işaret ve görüntü işleme, uydu teknolojilerinin hızla gelişmesini tetikledi: taşınabilir, farklı iklim şartlarında çalışan cihazlar gerekiyordu.
- Analog ve sayısal dünya
  - Dış dünya analogdur (süreklidir): ses $x(t)$ zamanın her anında tanımlıdır; göz ve analog fotoğraf filminde piksel kavramı yoktur.
  - Bilgisayar sayısaldır (ayrıktır): işlemci bilgiyi RAM ve ROM'dan alır; zaman $t$ yerine indis $n$ gelir (ekrandan, 00:40:00).
  - RAM benzetmesi: bir gözün genişliği (8, 16, 64 bit) dairenin oda sayısı, boyu (512 MB, 1 GB, 8 GB) binadaki daire sayısı gibidir.
- Ayrıklaştırma ve örnekleme
  - Soru 1: Nasıl ayrıklaştırılır? Ölçüt: en az bilgi kaybı ve orijinal bilgiye sadakat (ekrandan, 00:45:00).
  - Bir boyutlu işaret (ses) dizi (array), iki boyutlu işaret (görüntü) matris olarak saklanır.
  - İşaretten belli $T_s$ aralıklarıyla örnek alınır; $T_s$ örnekleme periyodudur. Örnekler sırayla RAM'e yazılır.
  - Soru 2: $T_s$'nin genişliği ne olmalı? Seyrek örnekleme az yer kaplar ama aradaki değişimleri kaçırır; sık örnekleme orijinale yakındır ama çok yer kaplar. Bu bir ödünleşimdir (trade-off).
  - Sık örneklemenin alt sınırı yoktur ($T_s \to \varepsilon$). Hafıza kısıtlı olduğu için $T_s$ değişimleri kaçırmayacak kadar geniş seçilmelidir. Bunun ölçüsünü Fourier analizi verir.
- Fourier analizine giriş ve sinüzoidal işaret
  - Fourier'e göre herhangi bir (keyfi) işaret, ideal olarak sonsuz sayıda sinüzoidal işaretin toplamıdır; frekans 0'dan sonsuza uzanan sürekli bir kavramdır (ekrandan, 00:50:00).
  - Sinüzoidal işaret: $x(t) = A\sin(2\pi f t + \varphi)$, $\omega = 2\pi f$ (ekrandan, 00:55:00).
  - Üç temel özellik: genlik $A$ (işaret $-A$ ile $A$ arasında salınır), frekans $f$, faz $\varphi$.
  - Periyot ile frekans ters orantılıdır: $T = 1/f$. $T = 1$ s ise $f = 1$ Hz, $T = 0{,}5$ s ise $f = 2$ Hz.
  - Sinüs ve kosinüs aynı fonksiyonun 90° kaydırılmış halidir: $A\sin(2\pi f t + \pi/2) = A\cos(2\pi f t)$ (ekrandan, 00:55:00).
  - Frekansı sıfır olan, salınım yapmayan bileşen DC bileşendir. Şehir şebekesi AC, yani sinüzoidal bir işarettir.
  - Her işaretin bir üst frekans sınırı vardır. İnsan sesi temel kabulle 0-4 kHz bandındadır; düşük frekanslar daha baskındır, sesin karakterini ses telinin oluşturduğu bileşenler belirler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgisayar mühendisi ile programcı farkı
  - Bilgisayar mühendisi programcının yaptığını yapabilir, ama sistemi bir üst seviyeden görür. Elektronik, lojik ve sistem bilgisi özellikle savunma sanayi ve biyomedikal gibi alanlarda avantaj sağlar.
- Transistörün önemi
  - Bilgisayar mühendisliğini mümkün kılan buluş transistördür. Ucuz, küçük ve farklı iklim şartlarında kararlı çalışan ikili devreler onunla yapılabildi.
- Örnekleme periyodu seçimi
  - $T_s$ ne çok geniş (bilgi kaybı) ne gereksiz dar (hafıza israfı) olmalıdır. Doğru ölçüyü işaretin frekans içeriği verir; bu yüzden Fourier analizi gerekir.
- Sinüzoidal işaretin üç parametresi
  - Her sinüzoidal fonksiyon genlik, frekans ve faz ile tanımlanır.

## Kısa Tekrar Notları

- Analog = sürekli, $x(t)$; sayısal = ayrık, $x[n]$.
- Ayrıklaştırma ölçütleri: en az bilgi kaybı, orijinale sadakat.
- $T_s$: örnekleme periyodu; küçük $T_s$ çok örnek ve çok hafıza, büyük $T_s$ bilgi kaybı demektir.
- Fourier: her işaret sinüzoidallerin toplamıdır.
- $x(t) = A\sin(2\pi f t + \varphi)$; $\omega = 2\pi f$; $T = 1/f$.
- Faz $\pi/2$ (90°) olunca sinüs kosinüse dönüşür.
- DC: $f = 0$ olan, salınmayan bileşen. Şebeke AC'dir.
- İnsan sesi yaklaşık 0-4 kHz bandındadır.
- Transistör: gerilim yükseltici ve ikili anahtar olarak kullanılır.

## Detaylı Açıklamalar

- **Dersin yeri.** Elektronik Devreler, Devre Teorisi'nde öğrenilen analiz yöntemlerinin üzerine gerçek elemanlarla analog devre kurmayı ekler. Diyot, BJT ve FET transistörlerin yapıları ve devre analizleri, ardından işlemsel yükselteçler işlenecektir. Hoca Lojik Devreler'in bu dersten sonra alınmasının daha mantıklı olacağını belirtti, çünkü lojik kapıların içinde bu derste anlatılan transistörler vardır. Tahtaya çizilen örnekte girişe direnç üzerinden +5 V (kare dalga) uygulanan bir transistörün kolektörü bir dirençle $V_{CC}$'ye bağlıdır; çıkış $V_{out}$ 0 ya da 1 değerini alır (ekrandan, 00:25:00). Bu devre ilerleyen haftalarda ayrıntılı anlatılacaktır.
- **Tüpten transistöre.** Tüplü radyo ve eski televizyonlar açıldıktan sonra kararlı çalışma sıcaklığına gelmeleri beklenirdi. Cam gövdeli bu yapılar sıcak ve soğuktan çok etkilenir, aşırı ısınınca özelliklerini kaybeder ve yan yana çok sayıda kullanıldığında büyük ısı yayardı. Yarı iletken transistörler bu sorunları çözdü; elde taşınabilir radyolar büyük bir devrim oldu. Bugün bir telefonun içindeki küçük bir çip eski büyük radyonun bütün işini görür.
- **Analogdan sayısala.** Dış dünyadan gelen bilgi bilgisayarda işlenir. Bilgisayar aslında bir hesaplayıcıdır (compute). Dış dünyanın bilgisi süreklidir, bilgisayarın hafızası ise sınırlı sayıda bitten oluşur. Bu yüzden işaret önce ayrıklaştırılır. İlk adım örneklemedir: işaretten $T_s$ aralıklarla değer alınır ve bu değerler sırayla RAM'e yazılır (ekrandan, 00:45:00). Aralar arasında önemli bir değişim varsa ve $T_s$ büyükse bu değişim kaybolur. İşaret bir ses olabileceği gibi biyomedikal ya da gizli bir askeri veri de olabilir; kaybın önemi buradan gelir.
- **Ödünleşim.** Derste bir öğrencinin cevabıyla özetlendiği gibi, seyrek örnekleme hafızada daha az yer kaplar; yer sınırı yoksa sık örnekleyip orijinale daha yakın bir sonuç elde edilir. Sık örneklemenin alt sınırı yoktur, $T_s$ neredeyse sıfıra indirilebilir. Asıl soru, değişimleri kaçırmadan $T_s$'nin en fazla ne kadar geniş olabileceğidir.
- **Fourier ve sinüzoidal işaret.** Fourier, 1800'lerde keyfi bir matematiksel fonksiyonun bileşenlerine ayrılabileceğini gösterdi: her işaret farklı frekanslı sinüzoidallerin toplamıdır (ekrandan, 00:50:00). Sinüzoidal işaret $x(t) = A\sin(2\pi f t + \varphi)$ biçimindedir; $2\pi f$ yerine $\omega$ da yazılır (ekrandan, 00:55:00). $A$ genliktir, işaret $-A$ ile $+A$ arasında salınır. $T$ periyot, yani dalganın kendini tamamladığı süredir ve $T = 1/f$'dir: periyot uzadıkça frekans düşer. $\varphi$ faz kaymasıdır; tam periyot $2\pi$ ya da 360°'dir, çeyrek periyot $\pi/2$ ya da 90°'dir. $\varphi = \pi/2$ için sinüs $A\cos(2\pi f t)$ olur.
  - Ders sonrası not: Hoca 00:53:45 civarında 90° ileri kaymanın sinüsü "eksi kosinüse" dönüştürdüğünü söyledi, hemen ardından tahtaya doğru biçimi $A\cos(2\pi f t)$ yazdı. Doğrusu $\sin(\theta + \pi/2) = \cos\theta$, $\sin(\theta - \pi/2) = -\cos\theta$'dır (python ile kontrol edildi).
- **DC ve frekans bandı.** Frekansı sıfır olan, hiç salınmayan bileşene DC bileşen denir. Şehir şebekesi süreklidir ve AC'dir. Fourier'e göre frekanslar 0'dan sonsuza uzanır, ama gerçek işaretlerin bir üst sınırı vardır. İnsan konuşması temel kabulle 0-4 kHz arasındadır; bu bantta düşük frekanslar daha güçlüdür. Bir sonraki derste Fourier serileriyle devam edilecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
