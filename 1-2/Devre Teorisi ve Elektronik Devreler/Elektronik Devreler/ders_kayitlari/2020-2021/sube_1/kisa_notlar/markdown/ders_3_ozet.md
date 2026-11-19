# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin kaynağı ve kapsamı
  - Ana kaynak Boylestad ve Nashelsky'nin *Electronic Devices and Circuit Theory* kitabıdır (ekrandan, 00:05:00).
  - İşlenecek bölümler: yarı iletken diyotlar, diyot uygulamaları, bipolar jonksiyonlu transistörler (BJT), BJT DC kutuplama (DC biasing), FET transistörler, FET kutuplama ve işlemsel yükselteçler (op-amp). Kitabın 7. ve 8. bölümlerindeki AC davranış konuları işlenmez.
  - Kitapta çok sayıda çözümlü soru vardır; derste de benzer sorular çözülür.
- Analog dünyadan sayısal dünyaya geçiş (önceki dersin tekrarı)
  - Dış dünya analogdur, yani süreklidir. Ses işareti zamanın her anında tanımlıdır; gözün gördüğü görüntüde piksel kavramı yoktur (ekrandan, 00:25:00).
  - Bilgisayar sayısaldır (ayrıktır). Burada "bilgisayar", masaüstü makine değil, içinde mikrodenetleyici ya da mikroişlemci bulunan ve hafızadaki veriyi adım adım işleyen her yapıdır (cep telefonu, modem gibi).
  - Veri RAM, ROM, manyetik teyp ve bulut gibi hafıza birimlerinde saklanır. Ders bir boyutlu işaret (ses) üzerinden anlatılır.
- Örnekleme (sampling)
  - Analog işaretten $T_s$ aralıklarla örnek alınır. $T_s$ örnekleme periyodudur; alt indis "s" sampling'den gelir (ekrandan, 00:30:00).
  - $T_s$ büyükse iki örnek arasındaki değişimler kaçırılır. EKG işaretinde kaçırılan bir tepe, doktor için önemli bir bilgi olabilir.
  - $T_s$ küçültülürse işaret orijinaline yaklaşır ama hafıza ihtiyacı, mikrodenetleyicinin yükü ve hesapsal karmaşıklık (computational complexity) artar.
  - Sık örneklemenin alt sınırı yoktur ($T_s \to \varepsilon$). Kaynaklar kısıtlı olduğu için değişimleri kaçırmayan en büyük $T_s$ aranır. Bu üst sınırı Fourier analizi verir.
- Fourier analizi ve sinüzoidal işaret
  - Joseph Fourier (1800'lerin başında çalışmış bir bilim insanı) herhangi bir keyfi (arbitrary) fonksiyonun sonsuz sayıda sinüzoidal bileşenin toplamı olarak yazılabileceğini gösterdi (ekrandan, 00:35:00).
    - Ders sonrası not: Altyazıda Fourier'in 1786-1830 yılları arasında yaşadığı geçiyor; doğum yılı büyük olasılıkla 1768'dir.
  - Sinüzoidal işaret: $x(t) = A\sin(2\pi f t + \varphi)$. Üç parametresi genlik $A$, frekans $f$ ve faz $\varphi$'dir; $\omega = 2\pi f$ açısal frekanstır (ekrandan, 00:45:00).
  - Periyot ile frekans ters orantılıdır: $T = 1/f$. $T = 1$ s ise $f = 1$ Hz, $T = 0{,}5$ s ise $f = 2$ Hz (ekrandan, 00:40:00).
  - Frekans, birim zamanda (genellikle bir saniyede) işaretin kaç çevrim tamamladığıdır.
  - Sinüs ve kosinüs aynı fonksiyonun 90° kaydırılmış halleridir. Tam çevrim 360° ya da $2\pi$ radyandır.
  - $f = 0$ bileşeni salınım yapmaz; buna DC (Direct Current) işaret denir. Örnek: 1,5 V'luk pilin voltmetrede sabit görünen gerilimi. Salınım yapan bileşenler AC (Alternating Current) işarettir.
  - Bir işaretin DC bileşeni onun ortalamasıdır. AC bileşenler bu ortalamanın üstüne eklenir.
  - Hızlı değişimleri yüksek frekanslı bileşenler, yumuşak geçişleri alçak frekanslı bileşenler oluşturur.
- En yüksek frekans ve Nyquist ölçütü
  - Teoride sonsuz sayıda frekans vardır, ama belli bir frekanstan sonra bileşenlerin genliği sıfıra gider. Bu frekansa $f_{max}$ denir; $T_{max} = 1/f_{max}$ (ekrandan, 00:50:00).
  - İnsan sesi konuşurken yaklaşık 0-4 kHz arasındadır; ortak kabul $f_{max} = 4$ kHz'dir.
  - En kötü durum en yüksek frekanslı bileşende oluşur: bir çevrimden yalnız iki örnek (pozitif ve negatif tepe) alınır. Bu durumda $T_{max} = 2T_s$, yani $f_s = 2f_{max}$ olur (ekrandan, 00:55:00).
  - Çevrim başına dört örnek alınırsa $T_{max} = 4T_s$, $f_s = 4f_{max}$ olur. 8, 16 kat da alınabilir.
  - Genel kural: $f_s \geq 2f_{max}$. Tahtada "Nyquist Frequency" diye yazılmıştır (ekrandan, 00:55:00).
- Nicemleme (quantization)
  - Örnekleme zaman ekseninde ayrıklaştırma yapar; genlik ise hâlâ sonsuz değer alabilir (örneğin 4,52325682...). Hafıza gözü sınırlı bit tuttuğu için genlik de ayrıklaştırılmalıdır (ekrandan, 01:20:00).
  - Hafızanın iki boyutu vardır: göz sayısı (örneğin 1024 göz = 1 K) ve gözün bit derinliği (1, 2, 8, 16, 32, 64 bit).
  - 1 bitle yalnız pozitif/negatif ayrımı yapılır. Her eklenen bit aralıkları ikiye böler; 2 bitle dört aralık (00, 01, 10, 11) elde edilir.
  - Bu aralıklara kuanta aralıkları (seviyeleri) denir. Aynı kuanta aralığına düşen farklı genlikler aynı kodla saklanır.
  - 8 bit 256 seviye verir (+127, 0, -128); 16 bit 65.536 seviye verir (ekrandan, 01:25:00).
  - Örnek: işaret -5 V ile +5 V arasındaysa toplam 10 V aralık 8 bitle 256 parçaya bölünür. Tahtada `0 1111111` için 5 V, `1 1111111` için -5 V yazılıdır (ekrandan, 01:25:00).
  - Sıra: (1) örnekleme, (2) nicemleme, ardından her örneğin ikili kodu hafızaya yazılır (coding). Böylece analog büyüklük 0 ve 1'lerle ifade edilen sayısal büyüklüğe dönüşür.
- Analog ve sayısal sistemler, bozulma ve gürültü
  - Analog sistemde (plak) sürekli işaret yükseltilip hoparlöre verilir. CD'de hafızadan okunan 0/1 değerleri genliğe çevrilerek orijinale benzer işaret oluşturulur, sonra yükseltilir.
  - Analog işarette bozulma (distortion) olur: tepeden kırpılma, sıfır geçişlerinde bozulma.
  - Bütün sistemler geçen işarete gürültü ekler (sıcaklık, çevredeki elektromanyetik kaynaklar). Gürültü bozulmanın aksine rastgeledir ve tekrarlanmaz. Sayısal işaretten çoğu zaman temizlenebilir, analog işaretten çoğu zaman temizlenemez (ekrandan, 01:30:00).
- Sensörler ve eyleyiciler (actuators)
  - Sensör dış dünya bilgisini alıp elektriksel büyüklüğe dönüştürür. Örnek: mikrofon havanın basıncından etkilenerek ses işareti üretir.
  - Yaygın sensör türleri: rezistif, endüktif, kapasitif, piezoelektrik, fotorezistif, elastik ve termal (ekrandan, 01:35:00).
  - Örnekler: kapasitif dokunmatik ekran, rezistif kalem tableti, sabah ışık gelince lambayı kapatan fotorezistif devre, rezistif termometre, termistör, fotovoltaik sensör, basınç sensörü, opto-anahtar (eski mekanik farelerde delikli diskle hareket algılama), pozisyon kodlayıcıları (encoder), mikrofon.
  - Rezistif sensör bir gerilim bölücüyle gerilime çevrilir: $R_1$ ile sensör direnci $R_s$ seri bağlanır, çıkış $V_o$ ortalarından alınır. Bu çıkış direnç değişimiyle doğrusal değildir (ekrandan, 01:40:00).
  - Eyleyici, sensörün tersine elektriksel işareti fiziksel büyüklüğe dönüştürür: rezistif ısıtıcı, ampul, LED (Light Emitting Diode), solenoid (otomatik kilitler), ölçü aletleri, DC ve step motorlar.
  - DC motor verilen gerilimin büyüklüğüne göre döner. Step motor 0/1 dizileriyle belli açılarda adım adım hareket ettirilir; daha hassastır.
- Ölçümde doğruluk ve netlik
  - Ölçü aletleri de elektronik cihazlardır; okumalar sapma gösterebilir.
  - Ölçümler hep aynı değerin etrafında toplanıyor ama gerçek değerden uzaksa netlik (precision) yüksek, doğruluk (accuracy) düşüktür. İdeal olan, ölçümlerin gerçek değerin etrafında sıkı toplanmasıdır.
- İdeal diyot
  - Diyot iki uçlu bir devre elemanıdır. Üçgen tarafı artı (anot), dik çizgi tarafı eksi (katot) ucudur (ekrandan, 01:45:00).
  - Diyot gerilimi uçlar arasındaki farktır: $V_D = V_A - V_B$ (ekrandan, 02:05:00).
  - İdeal diyot akımı tek yönde iletir. $V_D = 0 + \varepsilon$ olunca kısa devre gibi davranır, akımı dış devre sınırlar. $V_D \leq 0$ iken açık devre gibi davranır, $I_D = 0$ olur.
  - İletim bölgesinde diyot üzerindeki gerilim 0 V'tur; ileri yön direnci $R_F = V_F / I_F$. İletim yapmayan bölgede bütün gerilim diyot üzerindedir, akım 0 A'dır; ters yön direnci $R_R = V_R / I_R$ (ekrandan, 01:50:00).
- Yarı iletken malzemeler ve pn eklemi
  - Temel yarı iletkenler silisyum, germanyum ve galyum arsenittir. Malzeme saflaştırılır, sonra katkılama (doping) ile elektriksel özellikleri değiştirilir.
  - n tipi malzemede iletim bandında fazla elektron, p tipi malzemede valans bandında fazla delik (hole) vardır (ekrandan, 02:00:00).
  - p ve n tipi malzeme birleştirilince pn eklemi (junction) oluşur. Eklemde yükler yer değiştirir ve bir geçiş (fakirleşmiş) bölgesi (depletion region) ile potansiyel bariyeri oluşur.
  - İleri kutuplama (forward bias): p tarafı n tarafına göre pozitif yapılır, bariyer alçalır, geçiş bölgesi daralır ve uygulanan gerilimle artan net akım akar (ekrandan, 02:05:00).
  - Ters kutuplama (reverse bias): geçiş bölgesi genişler, bariyer yükselir, iletim olmaz; yalnız küçük bir sızıntı akımı akar.
  - Gerçek diyotta iletim için bariyer geriliminin aşılması gerekir: silisyumda yaklaşık 0,7 V, germanyumda yaklaşık 0,3 V.

## Hocanın Özellikle Vurguladığı Kısımlar

- Örnekleme periyodu bir ödünleşimdir
  - Sık örnekleme orijinale yaklaştırır ama hafıza, işlem yükü ve hesapsal karmaşıklığı artırır. Bilgisayar mühendisi kısıtlı kaynakla çalışır, bu yüzden değişimleri kaçırmayan en geniş $T_s$ seçilir.
- $f_s \geq 2f_{max}$
  - En kötü durum en yüksek frekanslı bileşende çevrim başına iki örnektir. Bu yüzden örnekleme frekansı işaretteki en yüksek frekansın en az iki katı olmalıdır.
- Bit sayısı ve kuanta aralığı
  - Bit sayısı arttıkça kuanta aralıkları daralır ve genlik daha kaliteli ifade edilir.
- Diyot gerilimi bir farktır
  - Bir elemanın gerilimi, artı kabul edilen uçla eksi kabul edilen uç arasındaki farktır: $V_D = V_A - V_B$. İşaret bu tanıma göre okunur.
- Elektronik Devreler gömülü sistemler, IoT, sensör tasarımı, mekatronik ve robotik için temel derslerdendir.

## Kısa Tekrar Notları

- Analog = sürekli; sayısal = ayrık.
- Örnekleme: zaman ekseninde ayrıklaştırma, $T_s$ aralıkla. Nicemleme: genlik ekseninde ayrıklaştırma.
- $x(t) = A\sin(2\pi f t + \varphi)$; $\omega = 2\pi f$; $T = 1/f$.
- DC: $f = 0$, işaretin ortalaması. AC: salınan bileşenler.
- $T_{max} = 1/f_{max}$; en kötü durumda $T_{max} = 2T_s$.
- $f_s \geq 2f_{max}$. 4 kHz ses için $f_s = 8$ kHz, $T_s = 125\ \mu s$.
- $n$ bit $\Rightarrow 2^n$ seviye: 8 bit 256, 16 bit 65.536.
- Gürültü rastgeledir; sayısal işaretten temizlenebilir, analogdan çoğu zaman temizlenemez.
- Sensör: fiziksel → elektriksel. Eyleyici: elektriksel → fiziksel.
- Precision = netlik (tekrarlanabilirlik); accuracy = doğruluk (gerçek değere yakınlık).
- İdeal diyot: $V_D > 0$ kısa devre, $V_D \leq 0$ açık devre.
- $V_D = V_A - V_B$.
- n tipi: fazla elektron; p tipi: fazla delik. pn ekleminde geçiş bölgesi ve potansiyel bariyeri oluşur.
- İleri kutuplama bariyeri alçaltır, ters kutuplama yükseltir.
- Eşik: Si ≈ 0,7 V, Ge ≈ 0,3 V.

## Detaylı Açıklamalar

- **Örnekleme ve $T_s$ seçimi.** Dış dünyadaki işaret süreklidir. Onu hafızaya yazabilmek için önce zaman ekseninde ayrıklaştırmak gerekir: işaretin değeri her $T_s$ saniyede bir okunur. $T_s$ büyük seçilirse iki örnek arasında olan bir tepe kaybolur. Hoca bunu EKG işaretiyle anlattı: kaçırılan kısa bir tepe hastalık hakkında önemli bilgi taşıyabilir. Bir öğrenci sık örneklemenin orijinale yaklaştırdığını ama bellekte daha çok yer kapladığını, başka bir öğrenci de seyrek örneklemenin belleği azalttığını ama orijinalden uzaklaştırdığını söyledi; hoca iki cevabı da doğruladı. Ayrıca mikrodenetleyici bir saat (clock) ritmiyle çalışır; veri arttıkça hem işlemcinin yükü hem algoritmanın hesapsal karmaşıklığı artar. Bu yüzden $T_s$'nin alt sınırı olmasa da pratikte bir üst sınır aranır.

- **Fourier analizi.** Fourier'e göre keyfi bir işaret, frekansı sıfırdan sonsuza kadar sürekli değişen sinüzoidallerin toplamıdır. Bu bileşenlerin genlikleri, frekansları ve fazları farklıdır. $f = 0$ bileşeni DC'dir ve işaretin ortalamasını verir; diğerleri AC bileşenlerdir. Hızlı değişimler yüksek frekanslı, yumuşak geçişler alçak frekanslı bileşenlerden gelir. Doğal işaretlerde belli bir frekanstan sonra bileşenlerin genliği sıfıra gider; bu en yüksek frekans $f_{max}$'tır.

- **Nyquist ölçütüne varış.** Hoca en yüksek frekanslı bileşenin bir çevrimini büyüterek çizdi. Yalnız pozitif ve negatif tepelerden örnek alınırsa bir çevrimde iki örnek olur; bu en kötü durumdur, çünkü daha düşük frekanslı bileşenlerin bir çevriminde çok daha fazla örnek düşer. İki örnek arası $T_s$ olduğuna göre $T_{max} = 2T_s$, yani $f_s = 2f_{max}$ bulunur. Aralara geçiş noktaları da eklenirse $T_{max} = 4T_s$ ve $f_s = 4f_{max}$ olur. Daha sık örneklemenin önünde engel olmadığından genel kural $f_s \geq 2f_{max}$ biçimindedir (ekrandan, 00:55:00).
  - Sınıf örneği: konuşan kişinin sesi en fazla 4 kHz ise kayıt cihazı en az 8 kHz ile örneklemelidir. $T_s = 1/8000 = 125\ \mu s$ (ekrandan, 00:55:00).
  - EKG örneği: işaretteki en yüksek frekans 500 Hz ise en az 1 kHz ile örneklenmelidir (derste sözlü, 01:15:16).

- **Nicemleme.** Örneklenen değer, örneğin 4,52325682..., virgülden sonra sonsuza kadar gidebilir. Hafıza gözü ise sınırlı sayıda bit tutar. Bu yüzden genlik ekseni de aralıklara bölünür ve her aralığa bir ikili kod verilir. 1 bitle yalnız işaretin pozitif mi negatif mi olduğu bilinir. 2 bitle dört aralık olur ve bazı farklı genlikler ayrılabilir, ama aynı aralığa düşen iki örnek yine aynı kodu alır. Her yeni bit aralıkları daraltır. Hocanın anlattığı en basit biçimde ilk bit işareti, kalan bitler büyüklüğü gösterir; gerçek sistemlerde negatif sayılar genellikle ikiye tümleyen biçiminde saklanır. -5 V ile +5 V arasındaki işaret 8 bitle 256 seviyeye bölünür (ekrandan, 01:25:00).

- **Gürültü ve bozulma.** Saf sinüs elde etmek zordur. Bozulma işaretin biçimini sistematik olarak değiştirir (kırpılma, sıfır geçişinde bozulma). Gürültü ise sıcaklık ve çevredeki elektromanyetik kaynaklardan gelen rastgele bir eklemedir. Sayısal hatta 0/1 bilgisi gürültüyle bozulsa bile seviyeler ayırt edilebildiği sürece temizlenebilir.

- **Sensörler.** Malzemenin bir uyarıya göre değişen hemen her fiziksel özelliği sensör yapmak için kullanılabilir. Rezistif sensörde direnç ölçülen büyüklükle değişir; bu değişim $R_1$ ile seri bağlı bir gerilim bölücüyle gerilime çevrilir. Opto-anahtarda bir taraf ışık gönderir, karşı taraf alır; arada dönen delikli disk eski farelerde hareket yönünü ve hızını verirdi.

- **İdeal diyot.** Diyotun ideal karakteristiğinde $V_D \leq 0$ iken akım sıfırdır, $V_D$ sıfırı $\varepsilon$ kadar geçince akım dikey olarak artar. Hoca bunu sayılarla gösterdi: B ucunda 5 V, A ucunda 4 V varsa $V_D = 4 - 5 = -1$ V olur ve diyot iletmez; B ucu 6 V olursa $-2$ V, 7 V olursa $-3$ V olur (derste sözlü, 01:50:27).

- **pn eklemi ve gerçek diyot.** p ve n malzemeleri birleşince eklemde p tarafında negatif, n tarafında pozitif yük birikir ve bir potansiyel bariyeri oluşur. İleri kutuplamada bariyer alçalır ve çoğunluk taşıyıcıları bariyeri aşar; difüzyon akımı artar, net akım uygulanan gerilimle büyür (ekrandan, 02:05:00). Ters kutuplamada bariyer yükselir. Gerçek diyot silisyumda yaklaşık 0,7 V'tan sonra hızla iletime geçer; ters yönde küçük bir sızıntı akımı vardır.
  - Ders sonrası not: Hoca galyum arsenit için eşik değerinin 0,9 V mu 1,3 V mu olduğundan emin olamadı. Ders kitabında (Boylestad) bu değer büyük olasılıkla 1,2 V olarak verilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
