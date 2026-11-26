# Ders 12 Çalışma Özeti

## Genel Konular

- Bu kaydın niteliği
  - Kayıt, birinci ara sınavın yapıldığı oturumdur; konu anlatımı yoktur. Akademik içerik iki parçadan oluşur: hocanın Sinyaller ve Sistemler dersinin mühendislik müfredatındaki yerini anlattığı kısa bölüm ve ekranda gösterilen dört sınav sorusu (ekrandan, 00:35:00).
- Sinyaller ve Sistemler dersinin müfredattaki yeri (ekrandan, 00:25:00)
  - Sinyal; kontrol, elektrik, elektronik, biyomedikal ve bilgisayar mühendislerinin, hatta zaman serileriyle uğraşan iktisatçıların ortak konusudur. Sinyaller ve Sistemler bu alanların tam ortasında durur.
  - Öncesindeki dersler: mühendislik matematiği, lineer cebir, diferansiyel denklemler, olasılık; daha önce de kalkülüs. Kısmen devre teorisi.
  - Bilgisayar mühendisliği kolu: sayısal işaret işleme (DSP), ardından görüntü işleme, video işleme, konuşma işleme ve makine öğrenmesine uzanan bir yol. Bunların "ileri" (advanced) sürümleri de vardır.
  - Kontrol ve elektronik kolu: otomatik kontrol sistemleri (sürekli zamanlı sistemler) ve sayısal (dijital) kontrol sistemleri (ayrık zamanlı sistemler), yanında yine DSP.
  - Haberleşme kolu: analog ve sayısal haberleşme sistemleri, yine DSP ile birlikte.
- Kontrol sistemi ile sinyal-sistem bağlantısı
  - Sistemler art arda bağlandığında, bağlantıda geri besleme (feedback) varsa konu kontrol sistemlerine girer. Haberleşme sistemlerinde ise sistem, geri beslemesiz, art arda gelen elemanlar zinciridir.
- Sınav sorularının konuları (ekrandan, 00:35:00)
  - Grafiği verilen bir sinüzoidin $x(t)=A\cos(\omega t+\theta)$ biçiminde yazılması ve en düşük örnekleme frekansı.
  - Sürekli zamanlı bir sinyalin ölçekleme, öteleme ve ters çevirme ile dönüştürülmesi.
  - Ayrık zamanlı konvolüsyon $y[n]=\sum_k x[k]h[n-k]$.
  - Periyodik bir sinyalin karmaşık üstel Fourier serisi katsayıları $c_k=\frac{1}{T}\int_{t_0}^{t_0+T}x(t)e^{-jk\omega_0 t}\,dt$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Formül ezberi gerekmez
  - Hoca bu derste formül ya da kural ezberletmeyi amaçlamadığını, formülü bilip değişkenleri yerine koymanın yeterli olduğunu söyledi.
  - Fourier katsayısı sorusunda kısmi integrasyon gerektiren zor bir integral sorulmayacağını belirtti.
- Çözüm adım adım gösterilmeli
  - Konvolüsyon "analitik çözüm" gibi yapılmalıdır: hangi terimle hangi terimin çarpıldığı adım adım yazılır. Formül biçimi ya da tablo biçimi seçilebilir; sonucu doğrudan yazmak yetmez.
  - Sinyal dönüşümü sorularında her sonucun nasıl elde edildiği kısa açıklamalarla verilmelidir. Çok yazmak doğru yazmak demek değildir; kısa ve sonucu açıklayan anlatım yeterlidir.
- Disiplinler arası denge
  - Bilgisayar mühendisi sinyal ve sistem bilgisini kendi işine yetecek kadar bilmelidir; haberleşmecinin ya da kontrolcünün alanına fazla girmek ortak projelerde verimi düşürür.

## Kısa Tekrar Notları

- Sinyaller ve Sistemler; DSP, görüntü/video/konuşma işleme, kontrol ve haberleşme derslerinin ortak temelidir.
- Geri beslemeli sistem bağlantısı kontrol sistemlerinin konusudur.
- Sinüzoid okuma: genlik tepe değerinden, periyot ardışık tepeler arasından, faz $t=0$ anındaki değerden bulunur.
- Nyquist: en düşük örnekleme frekansı sinyaldeki en yüksek frekansın iki katıdır.
- $x(at+b)$ türü dönüşümlerde önce öteleme, sonra ölçekleme/ters çevirme ya da doğrudan uç noktalarının yerine konması kullanılabilir.
- Ayrık konvolüsyonda çıkışın uzunluğu $L_x+L_h-1$, başlangıç indisi iki başlangıç indisinin toplamıdır.
- Fourier katsayısı: $c_k=\frac{1}{T}\int_T x(t)e^{-jk\omega_0 t}dt$, $\omega_0=2\pi/T$.

## Detaylı Açıklamalar

- Hoca sınav başlamadan önce dersin genel resmini ekranda bir kavram haritasıyla çizdi. Ortada "S.S" (Sinyaller ve Sistemler) kutusu, üstünde onu besleyen dersler (mühendislik matematiği, diferansiyel denklemler, lineer cebir ve diğerleri), altında ise üç kol vardır: bilgisayar mühendisliği için DSP, görüntü işleme, video ve konuşma işleme, makine öğrenmesi; kontrol ve elektronik için otomatik kontrol sistemleri, sayısal kontrol sistemleri ve DSP; haberleşme için DSP, analog ve sayısal haberleşme sistemleri (ekrandan, 00:25:00). Hoca örneklemenin (sampling) daha çok sayısal işaret işlemenin konusu olduğunu, bu derste kısaca değinileceğini söyledi; z-dönüşümünü ayrık zaman, Laplace dönüşümünü sürekli zaman tekniği olarak Fourier dönüşümünün tamamlayıcıları diye andı.
- Hocaya göre teorik çalışmak ya da matematiksel ağırlığı olan bir alana yönelmek isteyen herkesin yolu bir noktada sinyal ve sistemlerle kesişir. Web programlama gibi alanlar ayrı bir konudur, ama işin içine matematik girdiğinde sinyaller, Fourier ve Laplace gibi araçlar ve sistem kavramı devreye girer. Çok disiplinli bir tasarım projesinde bir sistemin tasarlanması, giriş ve çıkışlarının alınması gerekir; burada bilgisayar mühendisinin, kontrolcünün ve elektronikçinin ayrı görevleri vardır.
- Sınav soruları ekranda gösterildi; çözümleri derste verilmedi. Soruların metni ve ajan tarafından kontrol edilmiş çözümleri genişletilmiş notun "Örnek Sorular" bölümündedir. Kısaca sonuçlar: S1'de $x(t)=20\cos(50\pi t+\pi/2)$, en düşük örnekleme frekansı 50 Hz; S3'te $y[n]=\{4,4,3,\underline{-1},-5,-3,-2\}$ ($n=-3,\dots,3$; altı çizili $n=0$). S4'te periyot şekilde tam okunamadı. <!-- BELİRSİZ: S4 şeklinin alt kısmı ve periyodu karede kesik; katsayılar genel periyotla verildi. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
