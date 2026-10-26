# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 4 Ağustos 2021 Çarşamba. Ders Zoom üzerinden, yaz okulunda yapıldı. Dönemin ilk dersi.
  - Asıl ders yaklaşık 00:02'de başlar. Öncesi bekleme kısmıdır.
  - Hoca kendini tanıttı: Dr. Öğr. Gör. Ahmet Elbir, Bilgisayar Mühendisliği Bölümü, Bilgisayar Bilimleri Anabilim Dalı.
  - Ders geçen yıl İngilizce açılmıştı. Bu yaz Türkçe anlatılıyor. Hoca, sonraki dönemlerde dersi Gökhan Bilgin hocayla birlikte Türkçe vereceklerini söyledi.
- Yaz okulunun düzeni
  - Ders 5 hafta sürer. Haftada iki gün yapılır: Çarşamba akşamı ve Cumartesi (sabah ve öğleden sonra).
  - Yönetmeliğe göre günde 6 saatten fazla ders verilemediği için dersler 3'er saatlik parçalara bölündü.
  - Bütün dokümanlar (slaytlar, örnek sorular, ek notlar, sınav sonuçları) ders duvarındaki sabit linkte. Ayrı bir grup açılmayacak.
  - Duyurular Online Yıldız e-postası ve ders duvarından yapılacak.
- Değerlendirme
  - 4 quiz: toplam %15. Genelde Cumartesi günü son derste yapılır.
  - 3-4 ödev: %20. Kağıt üzerinde işlem veya kısa program yazma.
  - 1 vize: %25. Final: %40.
  - Devam notu yok. Fazladan yapılan ödev işleri bonus olarak eklenebilir.
- Dersin içeriği ve yeri
  - Sinyallerin ve sistemlerin matematiksel tanımı, sinüzoidler, frekans düzleminde gösterim (spectrum representation).
  - Ders iki parçalıdır: sürekli zaman (continuous time) ve ayrık zaman (discrete time).
  - Doğrusal zamanla değişmeyen (LTI) sistemler: sürekli zamanda konvolüsyon integrali, ayrık zamanda konvolüsyon toplamı.
  - Diferansiyel denklemler (sürekli) ve fark denklemleri (difference equation, ayrık).
  - Dönüşümler: Fourier serisi, Fourier dönüşümü, Laplace (s düzlemi), z dönüşümü, DTFT, DFT ve FFT.
  - Ders bir geçiş dersidir: Devre teorisi ve bilgisayar bilimlerine giriş bilgisinden sayısal işaret işlemeye (DSP), görüntü ve video işlemeye, bilgisayarla görmeye ve yapay zekaya geçişin temelidir.
- Araçlar
  - MATLAB (Online MATLAB önerildi), Octave, Scilab, R veya Python. Hoca Python veya MATLAB öneriyor.
  - Python için Anaconda ortamı (Spyder, Jupyter, PyCharm) tanıtıldı.
- Kaynak kitaplar
  - Ana kitap: *Signal Processing First* (McClellan, Schafer, Yoder).
  - Ek kaynaklar: Oppenheim'ın *Signals and Systems* kitabı (MIT), *Signals and Systems for Dummies*, Michael Adams'ın ücretsiz kitabı ve slaytları.
- İlk bölüm: bilişim (informatik) kavramlarına giriş
  - Veri (data), bilgi (information), bilgi birikimi (knowledge), bilgelik (wisdom).
  - Sistem ve sinyal tanımları.
  - Ölçme sisteminin adımları: dönüştürücü (transducer), analog işleme, örnekleme (sampling), nicemleme (quantization), kodlama.
  - Analog-sayısal dönüşüm (ADC) ve tersi (DAC), Nyquist oranı.
  - Sayıların bilgisayarda gösterimi: bit, byte, ikilik sistem, ikiye tümleyen, kayan nokta, gerekli bit sayısı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yaz okulunda bütünleme yok.
  - Final sınavına girmek zorunludur. Yıl içi notu 100 bile olsa finale girmeyen FF alır.
  - Ortalama 40'ın altındaysa FF.
- Ödevler zamanında Online Yıldız'a yüklenmeli.
  - Son ana bırakılan ödev için mazeret kabul edilmez.
  - E-postayla gelen ödev çoğu zaman kabul edilmez. Kabul edilirse %40, çok geç gelirse %70-80'e kadar kesinti yapılır.
- Bütün faaliyetleri (quiz, ödev) sıfır olan öğrenci F0 alır.
- Dersin İngilizce olduğunu sanıp başka okuldan ders alan varsa durumu hemen kontrol etmeli. Ders Türkçedir.
- Sinyalin gösterimi önemli: Sürekli işaret $x(t)$ (yuvarlak parantez, $t$), ayrık işaret $x[n]$ (köşeli parantez, $n$).
- $n$ bit ile $2^n$ farklı durum gösterilir. Bunu bilmemek "anormal" kabul edilir.
- Gerekli bit sayısı: $\lceil \log_2(\text{durum sayısı}) \rceil$. Üste yuvarlama (ceil) unutulmamalı.
- Nicemlemede örnek başına bit sayısı ile örnek sayısını karıştırmayın. Bellek = örnek sayısı × bit sayısı.
- Analog sinyal doğrudan bilgisayarda saklanamaz. Önce zamanda (örnekleme), sonra genlikte (nicemleme) sonlu hale getirilmelidir.
- Bilgi informatik giriş slaytından doğrudan soru sorulmayacak, ama bit sayısı gibi dolaylı sorular gelebilir.
- İlk quiz Cumartesi günü son saatte yapılacak.

## Kısa Tekrar Notları

- Veri (data): işlenmemiş ham değerler. Bilgi (information): veriden yorumla elde edilen sonuç. Knowledge: bilgi, deneyim ve öngörülerin birikimi; karar ve tahmin sağlar.
- Sistem: Bir hedef için bir araya getirilmiş, birbirini etkileyen elemanların kümesi. Temel yapı: giriş, işlem, çıkış. Geri besleme (feedback) eklenirse kontrol sistemi olur.
- Sinyal: Fiziksel bir büyüklüğü taşıyan ve bir değişkene (genelde zamana) göre değişen bilgi değişkeni.
- Dönüştürücü (transducer): bir enerji biçimini başka bir biçime çevirir.
  - Giriş dönüştürücüsü = sensör. Örnek: mikrofon.
  - Çıkış dönüştürücüsü = eyleyici (actuator). Örnek: hoparlör.
- Ölçme zinciri: fiziksel büyüklük, sensör, analog işleme (filtre, yükseltme), örnekleme, nicemleme, kodlama, saklama ve işleme, DAC, eyleyici.
- ADC adımları: filtreleme, örnekleme, nicemleme, kodlama.
- Örnekleme periyodu: $T_s = \dfrac{1}{f_s}$.
- Nyquist ölçütü: $f_s > 2 f_{max}$.
  - $f_s > 2f$: aşırı örnekleme (oversampling).
  - $f_s = 2f$: Nyquist oranı.
  - $f_s < 2f$: yetersiz örnekleme (undersampling).
- Nicemleme adımı: $\Delta = \dfrac{V_{max} - V_{min}}{L}$, $L = 2^n$ seviye.
- Nicemleme hatası: gerçek değer ile kodlanan değer arasındaki fark. Bit sayısı artınca hata azalır, bellek ihtiyacı artar.
- CD kalitesi: saniyede 44 100 örnek, örnek başına 16 bit.
- İkiye tümleyende $n$ bit ile aralık: $-2^{n-1}$ ile $2^{n-1}-1$. İşaretsiz $n$ bit: 0 ile $2^n - 1$.
- Kayan noktalı sayılar IEEE 754 standardıyla saklanır (32 ve 64 bit).
- Dönüşüm (conversion) ile kodlama (coding) farklıdır. Örnek: 13'ün ikilik karşılığı 1101 bir dönüşümdür; BCD kodu 0001 0011 bir kodlamadır.

## Detaylı Açıklamalar

### Dersin büyük resmi

Ders iki ana dala ayrılır. Sürekli zamanda konvolüsyon integrali, diferansiyel denklemler, Fourier serisi ve dönüşümü ile Laplace dönüşümü (s düzlemi) incelenir. Ayrık zamanda konvolüsyon toplamı, fark denklemleri, DTFT, DFT, FFT ve z dönüşümü incelenir. Sürekli zamandan ayrık zamana geçiş örnekleme ile yapılır.

- Neden frekans düzlemi? Bir ses sinyalinin zaman düzlemindeki görüntüsü her zaman yeterli bilgi vermez. Sinyalin hangi frekansları içerdiğini görmek için frekans düzlemine geçilir.
- Hoca DTFT ile DFT'nin farklı şeyler olduğunu vurguladı.
  - DTFT (discrete time Fourier transform) sürekli bir frekans fonksiyonu üretir.
  - DFT (discrete Fourier transform) sonlu sayıda frekans noktası üretir.
  - FFT, DFT'yi hızlı hesaplayan algoritmadır.
- Diferansiyel denklem çözümüne girilmeyecek. Bilgisayar mühendisine daha yakın olan fark denklemleri üzerinde durulacak.
- Hoca sinyal-sistem ilişkisini şöyle örnekledi: $y(t) = A \cdot x(t)$. Burada $x(t)$ ve $y(t)$ sinyal, onları bağlayan kural sistemdir.

### Programlama araçları

- Kod yazarken algoritmayı sıfırdan yazmak gerekmez. Hazır fonksiyonları (örneğin konvolüsyon, Fourier dönüşümü) kullanıp sonuçları yorumlamak hedeflenir.
- Bazı ödevlerde bir algoritmayı (örneğin konvolüsyonu) hem kendiniz yazıp hem hazır fonksiyonla hesaplayıp sonuçları karşılaştırmanız istenebilir.
- MATLAB ile Octave'ın dosya uzantısı aynıdır (`.m`). Octave, MATLAB'ın açık kaynak karşılığı gibidir.
- MATLAB'ın üniversite lisansı var ama kurulumu yaklaşık 7 GB. Online MATLAB önerildi.
- Ödevlerde genellikle grafik çizdirmeniz istenecek.

### Veri, bilgi ve sistem kavramları

- Veriden bilgiye: Ham satış fiyatları veridir. Bunlardan hazırlanan satış raporu bilgidir. Fiyat artırma veya azaltma kararı bilgi birikimine dayanır.
- Faydalı verinin özellikleri: amaca uygun, eksiksiz, doğru (accuracy), zamanında, doğru formatta, makul maliyetle elde edilmiş.
- Bilgi sistemi bileşenleri: donanım, yazılım, insan, kurallar, veri ve veri tabanları.
- Sayısal sistemde girişler, iç durumlar (state) ve çıkışlar ayrıktır. Sayısal bilgisayar bunun örneğidir.
  - Bellek, işlem birimi (CPU) ve veri yolları vardır.
  - Komut döngüsü (pipeline): getir (fetch), çöz (decode), yürüt (execute), geri yaz (write back).

### Ölçme ve örnekleme

- Hoca İzmir'deki sıcaklık örneğini verdi. Bir sitede 38 °C yazması sıcaklığın 38 °C olduğu anlamına gelmez. Değer bir ölçme sisteminden gelir ve hata içerir.
- Sensör fiziksel büyüklüğü elektriksel büyüklüğe (gerilim veya akım) çevirir. Bu aşamada sinyal hâlâ analogdur.
- Bir saatlik ölçümde sonsuz sayıda değer vardır. Bunları saklamak için:
  - Zaman ekseninde belirli aralıklarla örnek alınır (örnekleme). Örnek sayısı belirlenir.
  - Her örneğin genliği $2^n$ seviyeden en yakınına yuvarlanır (nicemleme).
- Ölçümün kalitesi iki şeyle artar: örnek sayısı (büyük $N$) ve örnek başına bit sayısı (küçük $n$).
- Mikrofonla konuşma ve kulaklıktan dinleme arasında en az iki kayıp olur:
  - Kayıt sırasında örnekleme ve nicemleme hatası.
  - Geri çalmada eyleyicinin örnekler arasını doldururken yaptığı ara değerleme (interpolation) hatası.
- Örnekleme öncesi filtreleme yapılır. Amaçlar:
  - Gürültüyü ve girişimleri (interference) temizlemek.
  - Sinyaldeki en yüksek frekansı sınırlamak, böylece gereksiz örneklemeden kaçınmak.
- Düşük frekans bileşenleri sinyali en çok tanımlayan kısımdır. Yüksek frekanslar çoğunlukla ayrıntı veya gürültüdür.
- Örnekleme yöntemleri: ideal örnekleme (impuls dizisi), doğal örnekleme (natural sampling) ve düz tepeli örnekleme (flat-top). Örneklenen ama henüz nicemlenmemiş sinyale PAM (pulse amplitude modulation) denir.
- Örnek: 1000 Hz en yüksek frekanslı bir sinyal için saniyede en az 2000 örnek gerekir.
- Örnekleme frekansı 1024 Hz olan bir osiloskop örneği gösterildi.
- Telefonda fotoğraf çekerken oluşan hareket bulanıklığı (motion blur), kaymanın frekans bilgisi bulunarak geri alınabilir (deblurring).

### Nicemleme örnekleri

**Örnek 1:** $V_{max} = 24$ V, $V_{min} = -12$ V, 2 bit.

- Seviye sayısı $L = 2^2 = 4$, adım $\Delta = \dfrac{24 - (-12)}{4} = 9$ V.
- Bölgeler: $[-12, -3)$ → 00, $[-3, 6)$ → 01, $[6, 15)$ → 10, $[15, 24]$ → 11.
- 18 V son bölgeye düşer ve 11 ile saklanır.

**Örnek 2:** $-20$ V ile $+20$ V arası 8 bölge.

- Adım $\Delta = 40/8 = 5$ V. Gerekli bit: $\log_2 8 = 3$.
- Bellek: her örnek 3 bit tutar. Toplam bellek = örnek sayısı × 3 bit.
  - Öğrencilerden "8 × 3 = 24" ve "5 × 3 = 15" gibi cevaplar geldi. Hoca ikisini de düzeltti.
  - Bölge sayısı veya bölge genişliği belleği belirlemez. Belleği örnek sayısı belirler.
- Kodlar: 000 → $[-20, -15)$, 001 → $[-15, -10)$, … , 111 → $[15, 20]$.

**Örnek 3:** 12 bitlik ADC, giriş aralığı 0-10 V.

- $\Delta = 10/2^{12} \approx 0{,}00244$ V.

**Gerekli bit sayısı:**

- 68 durum: $\log_2 68 \approx 6{,}09$, üste yuvarlanınca 7 bit.
- 88 durum: $\log_2 88 \approx 6{,}46$, 7 bit. 6 bit yalnız 64 durum gösterir, yetmez.
- 9 durum (örneğin rakamlar): $\log_2 9 \approx 3{,}17$, 4 bit.
- 20 renk: 4 bit yetmez (16 durum), 5 bit gerekir.

### Ses dosyasının boyutu

- CD kalitesinde 1 dakikalık tek kanallı ses: $44\,100 \times 60 = 2\,646\,000$ örnek.
- Örnek başına 16 bit: $2\,646\,000 \times 16 = 42\,336\,000$ bit.
- 8'e bölünce $5\,292\,000$ bayt, yaklaşık 5,05 MB.

### Sayıların gösterimi

- Bit, nibble (4 bit), bayt (8 bit), word (16 bit).
- Konumsal sayı sistemi: $R$ tabanında 0 ile $R-1$ arası rakamlar kullanılır. Kesir kısmı $R$'nin negatif kuvvetleriyle ifade edilir.
- 10 bit işaretsiz: 0-1023.
- 5 bit ikiye tümleyen: $-16$ ile $+15$.
- İşaret-büyüklük (sign-magnitude) ve bire tümleyende (one's complement) $+0$ ve $-0$ belirsizliği vardır. İkiye tümleyende sıfır tektir; işlemlerde ek kontrol gerekmez.
- Önekler: kilo, mega, giga, tera, peta. Mili, mikro, nano, piko, femto.
- Veri tipleri: metin bir karakter dizisidir. Görüntü iki boyutlu bir matristir. Video, matrislerin zaman boyunca dizisidir.

### Ders sonrası notlar

- **İdeal örnekleme:** Derste "dip dibe impulslar" diye anlatıldı. İdeal örneklemede impulslar sıfır genişliklidir ve aralarında $T_s$ kadar mesafe vardır. Sinyal, $T_s$ aralıklı bir impuls dizisiyle çarpılır.
- **Çarpma mı konvolüsyon mu:** Derste "aslında tam bir çarpma değil konvolüsyon" dendi. Örnekleme zaman düzleminde çarpmadır. Frekans düzleminde konvolüsyona karşılık gelir.
- **Nyquist sınırı:** Derste "iki kat ve sonrasında sorun yok" dendi. Doğru koşul $f_s > 2 f_{max}$'tır. Tam $2f$'de örneklemede sorun çıkabilir. Örneğin $\sin(2\pi f t)$ tam $2f$ ile örneklenirse bütün örnekler sıfıra düşebilir.
- **Nicemleme hatası:** Derste ölçme sürecindeki bütün hatalara nicemleme hatası dendi. Nicemleme hatası yalnızca genlik yuvarlamasından doğan hatadır. Örnekleme ve sensör hataları ayrı hata kaynaklarıdır.
- **17 V örneği:** $-20$/$+20$ V, 3 bit, $\Delta = 5$ V örneğinde derste "17 V, 17,5'in altında olduğu için 110 ile saklanır" dendi.
  - Bölge kodlamasında 17 V $[15, 20]$ bölgesine düşer ve 111 ile kodlanır. Bu bölgenin temsil değeri orta noktası olan 17,5 V'tur.
  - 110 kodu $[10, 15)$ bölgesine aittir.
  - Orta nokta kuralı, değer en yakın seviyeye yuvarlandığında kullanılır. Bu durumda 8 sınır değeri 3 bitle bire bir kodlanamaz.
- **12 bit ADC hatası:** Derste nicemleme hatası $\pm 0{,}0024$ V dendi.
  - Bu değer 1 adıma (1 LSB) eşittir.
  - En yakın seviyeye yuvarlamada en büyük hata yarım adımdır: $\pm \Delta/2 \approx \pm 0{,}00122$ V.
  - Yalnızca kesme (truncation) yapılırsa hata 0 ile $\Delta$ arasında olur.
- **IEEE 754:** Derste "IEEE 744" dendi. Standardın doğru adı IEEE 754'tür.
- **Ses dosyası boyutu:** Yukarıdaki 5,05 MB hesabı tek kanal (mono) içindir ve Python ile doğrulandı. Stereo kayıtta boyut iki katına çıkar.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
