# Ders 2 Çalışma Özeti

## Genel Konular

- Sinyal kavramı ve tipik ölçme sistemi
  - Sinyal, fiziksel bir büyüklüğü ifade eden değişkendir: ses, görüntü, bir döviz kurunun gün içindeki seyri, bir fren kablosundaki gerilim gibi. Ayrık olarak saklanmış sinyal ayrık sinyaldir; bilgisayarlar sinyali ayrık ele alır.
  - Tipik ölçme sisteminin blok şeması: fizyolojik ya da dış enerji → Transducer → Amplifier/Detector → Analog Signal Processing → (bilgisayar içinde) Analog-to-Digital Converter → Signal Storage or Buffering → Signal Processing → Display (ekrandan, 00:15:00).
  - Transdüser bir enerji türünü başka bir türe dönüştüren genel elemandır. Giriş transdüseri (sensör) elektrik dışı bir büyüklüğü elektrik işaretine çevirir (örnek: mikrofon). Çıkış transdüseri (aktüatör) elektrik işaretini fiziksel bir etkiye çevirir (örnek: hoparlör, robot hareketi).
  - Amplifier/detector sinyali güçlendirir, gürültüyü bastırır. Analog işaret işleme bloklarına örnek olarak optik örüntü tanıma (mercek ve elektronik devreyle hedefin önceden işlenmesi) verildi.
  - "Display" yalnız ekran değil, işlenmiş sinyalin dış dünyaya çıkışıdır; bu çıkış Digital-to-Analog Converter ile yeniden fiziksel büyüklüğe dönüştürülür.
- Analog sinyal ve bilgi kaybı
  - Analog (sürekli) sinyal sonsuz hassasiyetle tanımlı sürekli bir değişkendir. Sayısala çevrilirken ayrık bir ölçüm dizisine dönüştürülür (ekrandan, 00:25:00).
  - Bilgi kaybının kaynakları: ölçümdeki hatalar, zamanlamadaki belirsizlik, ölçüm süresindeki sınırlar. Slayt bu etkilerin tümüne "quantisation errors" diyor.
  - $x(t)=f(t) \leftrightarrow$ analogdan sayısala dönüşüm $\leftrightarrow x[n]$. Sürekli sinyal $t$ domeninde, ayrık sinyal $n$ domenindedir (ekrandan, 00:30:00).
- Örnekleme ve nicemleme sıklığının bellekteki karşılığı
  - Zaman eksenindeki sıklık (örnekleme hızı) dizinin eleman sayısını belirler. Genlik eksenindeki sıklık dizinin her elemanının veri tipini (bit sayısını) belirler. Tahtadaki gösterim: `X d[y];` ve örnekleme hızı $\propto y$ (ekrandan, 00:35:00).
  - 10 saniyelik bir kayıt $f_s=1000$ Hz ile örneklenirse 10 000 elemanlı bir dizi elde edilir.
  - Ekranda çizilen sürekli eğri gerçek sinyal değildir; ayrık örnekler arası çizim programı tarafından doldurulur (interpolasyon).
- Analogdan sayısala dönüşümün dört adımı
  - Filtreleme, örnekleme (zaman ekseni), nicemleme (genlik ekseni), ikili kodlama (ekrandan, 00:40:00).
  - Filtreleme, örneklemeden önce istenmeyen bileşenleri (gürültü, başka konuşmacı) atmak içindir. Kokteyl parti problemi ve bağımsız bileşen analizi (ICA) ile karışmış iki sesin ayrılması örnek gösterildi.
- Örnekleme
  - Analog sinyal her $T_s$ saniyede bir örneklenir; $T_s$ örnekleme aralığı, $f_s=1/T_s$ örnekleme frekansıdır (ekrandan, 00:50:00).
  - Üç örnekleme yöntemi: ideal (her örnek anında bir impuls), doğal (değişen genlikli kısa darbe), flat-top (örnekle ve tut; darbe boyunca tek genlik). Bu işleme darbe genlik modülasyonu (PAM) denir; sonuç hâlâ tam sayı olmayan, analog değerlidir.
  - Örnekleme hızının sinüs dalgasının geri kazanımına etkisi: $f_s=2f$ (Nyquist hızı), $f_s=4f$ (aşırı örnekleme), $f_s=f$ (yetersiz örnekleme; geri çatılan sinyal orijinale benzemez) (ekrandan, 00:55:00).
  - Nyquist kuralı: $f_s \ge 2 f_{max}$. $f_{max}$, sinyalin frekansı değil, içerdiği en büyük frekans bileşenidir. En büyük frekansın nasıl bulunacağı Fourier konusunda görülecek.
  - Alçak geçiren filtrede eşik üstü, bant geçiren filtrede belli bir aralığın dışı bastırılır (frekans domeninde ilgili değerler sıfırlanır). Yüksek geçiren filtre eşik altını bastırır. Bant geçiren filtreyle örneklemede de aralığın üst sınırı $f_{max}$ alınır.
  - Ders sonrası not: Hoca alçak geçiren filtreyi önce "eşiğin altındakileri bastırır", yüksek geçireni "eşiğin üstündekileri bastırır" diye anlattı; doğrusu tersidir. Ayrıca bilinen bir gürültü frekansını sıfırlayıp sinyali geri elde etme örneğine "bant geçiren" dedi; tek bir bandı atan bu filtre bant durduran (band-stop, notch) filtredir.
- Nicemleme ve kodlama
  - Örnekleme sonucu min ile max arasında değişen genlikli darbeler çıkar. Sonsuz genlik değeri sonlu bir kümeye eşlenir: aralık her biri $\Delta$ yüksekliğinde $L$ bölgeye bölünür, $\Delta=(\max-\min)/L$ (ekrandan, 01:05:00).
  - Her bölgeye bir ikili kod atanır; örnek başına bit sayısı $n_b=\log_2 L$ (ekrandan, 01:10:00). $L$ ikinin kuvveti değilse üste yuvarlanır.
  - Nicemleme hatası: kodlanmış değer (bölge orta noktası) ile gerçek değer arasındaki farktır. Bölge sayısı artarsa $\Delta$ ve hata küçülür, ama örnek başına bit ve bit hızı artar (ekrandan, 01:15:00).
- Sayısal veri temsili (Lojik ve programlama derslerinden tekrar)
  - Bit, nibble (4 bit), bayt, word; kapasite birimleri ($2^{10}$, $2^{20}$, $2^{30}$); Hertz ve zaman birimleri.
  - Sayı sistemleri, sabit noktalı gösterim ($3456.78=3\cdot10^3+4\cdot10^2+5\cdot10^1+6\cdot10^0+7\cdot10^{-1}+8\cdot10^{-2}$), işaret biti, bire ve ikiye tümleme (ekrandan, 01:55:00).
  - IEEE 754 kayan nokta: tek duyarlıkta 1 işaret, 8 üs, 23 mantis biti, sapma 127; çift duyarlıkta sapma 1023.
  - $M$ elemanı kodlamak için gereken en az bit sayısı $n=\lceil \log_2 M \rceil$ (ekrandan, 02:00:00).
  - Kodlayıcı (encoder) ve kod çözücü, BCD 8-4-2-1 kodu, eşlik (parity) biti, ASCII ve Unicode, kodlama ile dönüşüm (conversion) farkı, mantıksal işlemler (NOT, AND, OR, XOR, XNOR).
- Sinyaller ve sistemler
  - Sistem (fiziksel, matematiksel ya da hesaplamalı) bir giriş sinyalini çıkış sinyaline dönüştürme biçimiyle tanımlanır (ekrandan, 02:15:00). Yazılan bir algoritma da kurulan bir devre de sistemdir.
  - Sinyaller matematiksel fonksiyonlardır: bağımsız değişken çoğunlukla zaman, bağımlı değişken gerilim, akış hızı, ses basıncı gibi büyüklüklerdir. Örnek sistemler: kütle-yay sistemi, tank sistemi, cep telefonu sistemi (ekrandan, 02:20:00).
  - Alt sistemlerden oluşan sistemlere bileşik (composite) sistem denir.
  - Sistemler çoğu zaman diferansiyel denklemlerle tanımlanır; bunların çözümünü kolaylaştırmak için Fourier ve Laplace dönüşümleri kullanılacak.
- Frekans domeni neden gerekli?
  - Bazı bilgiler zaman domeninden doğrudan çıkarılamaz. Tek bir sinüzoidin frekansı periyodundan bulunur, ama birkaç sinüzoidin toplamının bileşenleri zaman grafiğinden zor anlaşılır.
  - Frekans domeni gösterimi birçok sinyal için daha basittir (örnek: AM radyo sinyali), doğrusal sistemlerin analizini kolaylaştırır ve sistemin temel özelliklerini ortaya koyar (ekrandan, 02:25:00).
  - Piyano akoru örneği: zaman grafiği akorun başlangıcını ve sönümünü gösterir, notaları göstermez; genlik spektrumunda yaklaşık 9 belirgin frekans bileşeni görülür (ekrandan, 02:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Transdüser, sensör ve aktüatör kavramları
  - Hoca bu üç kavramı bilinmesi gereken önemli kavramlar olarak saydı.
- Analog sinyalin tanımı
  - Analog sinyal, zamanda ve genlikte sonsuz kez örneklenmiş sinyal gibi düşünülebilir. Belleği sınırlı hiçbir sayısal sistem bunu yapamaz; bu yüzden sayısallaştırmada her zaman bilgi kaybı vardır.
- Nyquist kuralı
  - $f_s \ge 2 f_{max}$ mutlaka bilinmeli. Kritik nokta, sinyalin içindeki en büyük frekansın iki katının alınmasıdır.
- Hesap soruları
  - Örnekleme frekansı, süre ve seviye sayısından sinyalin bellekte kapladığı alanı bulmak; görüntü boyutu ve renk sayısından gereken bit sayısını bulmak; bir değerin hangi nicemleme bölgesine düştüğünü ve kodunu bulmak.
- Ders konusu dışında kalanlar
  - Sayı sistemleri, kayan nokta ayrıntıları, ASCII ve mantıksal işlemler genel kültür olarak tekrar edildi; hoca bunların bu dersin asıl konusu olmadığını söyledi.
- Sayısallaştırma adımları
  - Sürekli bir veriyi (müzik, resim) sayısala çevirmenin adımları, nicemleme hatası, nicemleme aralığı ve gereken bit sayısı bu bölümden bilinmesi gerekenlerdir.

## Kısa Tekrar Notları

- Sayısallaştırma: filtreleme → örnekleme (zaman) → nicemleme (genlik) → ikili kodlama.
- $T_s$ örnekleme aralığı, $f_s=1/T_s$ örnekleme frekansı.
- Örnekleme hızı ↑ → dizi uzunluğu ↑. Nicemleme seviyesi ↑ → eleman başına bit ↑.
- Nyquist: $f_s \ge 2f_{max}$; 2, 6 ve 12 kHz bileşenli sinyal için $f_s \ge 24$ kHz.
- $f_s=f$ yetersiz örneklemedir; geri çatılan sinyal orijinalle ilgisiz olur.
- CD kalitesi 44 100 Hz; yarısı 22 050 Hz, insan kulağının üst sınırı (yaklaşık 20 kHz) üstündedir.
- $\Delta=(\max-\min)/L$, $n_b=\lceil\log_2 L\rceil$.
- Nicemleme hatası = gerçek değer − bölge orta noktası; daha çok bölge → daha az hata, daha çok bit.
- 12 bit ADC, 0–10 V: $V_{LSB}=10/2^{12}\approx 0{,}0024$ V.
- Bellek = örnek sayısı × örnek başına bit; 60 s, 24 kHz, 180 seviye → $1\,440\,000$ bayt.
- $M$ eleman için $\lceil\log_2 M\rceil$ bit: 7 renk → 3 bit, 10 rakam → 4 bit.
- ASCII: '0' = $30_{16}$ = 48, 'A' = 65, 'a' = 97; büyük ve küçük harf arasındaki fark 32'dir (tek bit).
- Sistem: giriş sinyalini çıkış sinyaline dönüştüren her şey.
- Frekans domeni karmaşık sinyallerin bileşenlerini ortaya çıkarır.

## Detaylı Açıklamalar

- **Ölçme zinciri.** Bir sinyal önce transdüserle elektrik işaretine çevrilir, analog katlarda güçlendirilip temizlenir, sonra bilgisayara girerken ADC ile sayısallaştırılır. Bilgisayarda bellekte (RAM, disk) bir dizi olarak saklanır ve herhangi bir algoritmayla (sıralama, yüz tanıma, gürültü bastırma, konuşma tanıma) işlenir. Sonuç DAC ile yeniden fiziksel büyüklüğe dönüştürülüp dış dünyaya verilir. Dersin büyük kısmı sinyal işleme bloklarıyla, bir kısmı da çıkış bloklarıyla ilgilidir.

- **Sürekli çizim neden gerçek değildir?** 10 saniyelik bir ses $f_s=1000$ Hz ile kaydedilirse bellekte 10 000 elemanlı bir dizi vardır. Ekranda görülen pürüzsüz eğri, ardışık örneklerin arasını çizim programının doldurmasıyla (interpolasyon) oluşur. Kaydedilen ve çizilen sinyal asıl sesle yüzde yüz aynı değildir.

- **Sayısallaştırma örneği (slayt).** 0–10 s aralığında tanımlı sürekli bir sinyal 10 örneğe bölünmüş, genlik ekseni de 0–10 arasında 1 birimlik seviyelere ayrılmıştır. Örnek numarası $n=0,1,\dots,9$ için okunan değerler $0, 2, 3, 2, 1, 0, 1, 2, 5, 8$'dir; ayrık sinyal bu değerlerden oluşan basamaklı bir grafiktir (ekrandan, 00:30:00). Gerçek değer örneğin 2,7 iken 3 saklanır; daha az hata için genlik seviyeleri sıklaştırılmalıdır. Zaman ekseninde 10 yerine 100 örnek alınırsa aralar kısalır ve orijinale daha yakın bir dizi elde edilir. Bir C dizisiyle düşünülürse örnekleme hızı dizinin eleman sayısını, nicemleme seviyesi de veri tipini belirler: `int32` genliği $2^{32}$, `int64` ise $2^{64}$ seviyeye böler.

- **Nyquist kuralının uygulanması.** Önceki derste gösterilen 1 kHz ve 2 kHz bileşenli sinyal için $f_{max}=2$ kHz, dolayısıyla $f_s \ge 4$ kHz gerekir. 1, 2, 3 ve 8 kHz bileşenli bir sinyal için $f_s \ge 16$ kHz gerekir. İnsan kulağı yaklaşık 20 Hz–20 kHz aralığını duyar. CD kalitesi bu yüzden 44 100 Hz ile örneklenir; bu değerin yarısı olan 22 050 Hz, 20 kHz'in üstündedir.

- **Nicemleme örneği: ±20 V, 8 seviye.** Aralık $40$ V, $L=8$ olduğundan $\Delta=5$ V'tur. Bölgeler ve kodlar (slayttaki ilk iki atama ekrandan, 01:15:00; tamamı hesapla):

  | Bölge (V) | Orta nokta (V) | Kod |
  |---|---|---|
  | −20 … −15 | −17,5 | 000 |
  | −15 … −10 | −12,5 | 001 |
  | −10 … −5 | −7,5 | 010 |
  | −5 … 0 | −2,5 | 011 |
  | 0 … 5 | 2,5 | 100 |
  | 5 … 10 | 7,5 | 101 |
  | 10 … 15 | 12,5 | 110 |
  | 15 … 20 | 17,5 | 111 |

  Örnek başına $n_b=\log_2 8=3$ bit gerekir. 7,8 V değeri 5–10 V bölgesine düşer ve 7,5 V olarak saklanır (kod 101). Sinyal 2 kHz ise $f_s=4$ kHz ile bir saniyede 4000 örnek alınır; $4000\times 3=12\,000$ bit (1500 bayt) gerekir. En az 20 bölge isteniyorsa 20 ikinin kuvveti olmadığından 32 bölge alınır ve 5 bit kullanılır.
  - Ders sonrası not: Hoca 7,8 için "7,5'ten büyük olduğu için bir üst seviyeye yuvarlanır" dedi. Bölgeler 5'er voltluk olduğundan 7,8 V, 5–10 V bölgesindedir ve bu bölgenin temsilcisi orta nokta 7,5 V'tur; yani değer 7,5 V'a eşlenir.

- **ADC doğruluğu.** 12 bitlik, 0–10 V girişli bir ADC'nin en anlamsız bitine karşılık gelen gerilim $V_{LSB}=V_{max}/2^{12}=10/4096\approx 0{,}0024$ V'tur; doğruluk $\pm 0{,}0024$ V'tur (ekrandan, 01:35:00). Bit sayısı arttıkça bu değer küçülür; sıfır olması için sonsuz bit gerekir.

- **Frekans domeni.** Genliği 0,1 ve açısal frekansı $\omega_1=2\pi f_1$ olan bir sinüzoid 100 saniye boyunca örneklenip karşıya bir dizi olarak gönderilirse binlerce değer iletilir. Yalnız genliği ve frekansı göndermek iki değer demektir; alıcı ters dönüşümle her andaki değeri hesaplayabilir. Notalar, telefon tuşları ve yüz gibi örüntülerin ayırt edici özellikleri frekans bileşenleriyle bulunur. Bir piyano akorunun spektrumunda yaklaşık 330, 400, 525, 660 ve 780 Hz civarında büyük, daha yukarıda küçük tepeler vardır; toplam 9 kadar frekans bileşeni görülür (ekrandan, 02:30:00). Telefon tuşlarında her tuş için iki frekans varken notalarda 9–12 bileşen görülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
