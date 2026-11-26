# Ders 2 Genişletilmiş Notu: Analogdan Sayısala Dönüşüm, Nicemleme ve Sayısal Veri Temsili

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sinyal kavramı ve sayısal sistemler
- 2. Tipik bir ölçme sistemi
- 3. Analog sinyal ve bilgi kaybı
- 4. Sürekli sinyalden ayrık sinyale
- 5. Analogdan sayısala dönüşümün dört adımı ve filtreleme
- 6. Örnekleme
- 7. Nicemleme ve kodlama
- 8. Nicemleme hatası ve ADC örnekleri
- 9. Örneklemeyle ilgili kavramlar
- 10. Sayısal veri temsili
- 11. Sayısallaştırma bölümünden bilinmesi gerekenler
- 12. Sinyaller ve sistemler
- 13. Frekans domeni neden gerekli?
- Örnek Sorular
- Dersin Toparlaması

## 1. Sinyal kavramı ve sayısal sistemler

Ders, önceki haftada kalınan yerden, yani bir bilgisayar sisteminin bir sinyali nasıl işlediği sorusundan devam etti. Sinyal, fiziksel bir büyüklüğü ifade eden bir değişkendir. Bu büyüklük günlük hayatta ne ise odur: bir ses, bir görüntü ya da bir döviz kurunun gün içindeki anlık seyri sinyal olabilir. Sinyal ayrık zamanlarda, ayrık değerlerle saklanmışsa ayrık bir sinyaldir. Bilgisayarlar sinyali ayrık olarak ele alır, çünkü kendileri de ayrık zamanlı işlem yapan sistemlerdir.

Sayısal sistemlerde en çok ikili (binary) seviye kullanılır: 0 ve 1. Bu iki seviye farklı bağlamlarda on/off, low/high, false/true diye de adlandırılır; bunlar lojik devreler dersinden bilinen kavramlardır.

## 2. Tipik bir ölçme sistemi

Önceki derste bir fiziksel büyüklüğün bilgisayarda nasıl saklandığı özetlenmişti. Bu derste bu süreç slayttaki blok şeması üzerinden tek tek ele alındı (ekrandan, 00:15:00):

```text
Fizyolojik ya da dış enerji
  -> Transducer
  -> Amplifier / Detector
  -> Analog Signal Processing
  -> [Bilgisayar]
       Analog-to-Digital Converter
       -> Signal Storage or Buffering
       -> Signal Processing
       -> Display ->
```

### 2.1 Transdüser, sensör ve aktüatör

**Transdüser** (transducer), herhangi bir enerjiyi bir türden başka bir türe dönüştüren genel bir elemandır. Transdüserin alt kümeleri vardır; **sensör** bunlardan biridir. Sensör fiziksel bir büyüklüğü alıp elektriksel ya da sayısal (0 ve 1'lerden oluşan) bir büyüklüğe dönüştürür. Örneğin bir ortamın sıcaklığı ölçülür ve bilgisayarda işlenebilecek sayısal bir değer elde edilir. Sinyal işleme uygulamalarında transdüserler herhangi bir enerjinin elektrik enerjisine ya da sayısal bir duruma dönüştürülmesi için kullanılır.

- **Giriş transdüseri (sensör):** elektrik dışındaki bir enerjiyi elektrik enerjisine dönüştürür. Örnek: mikrofon.
- **Çıkış transdüseri (aktüatör):** bir elektrik işaretini sese, görüntüye ya da bir robotun hareketine dönüştürür. Örnek: hoparlör.

> **Hocanın vurgusu:** Transdüser, sensör ve aktüatör önemli kavramlardır; ne olduklarının bilinmesi gerekir.

### 2.2 Analog katlar

**Amplifier/Detector**, sinyaldeki zayıflıkları tespit edip sinyali güçlendiren, varsa hataları ve gürültüleri yok eden elemandır. Bunlar analog devrelerde gerçekleşen işlemlerdir; hoca, eskiden araçlarda kullanılan amfilerin devrelerinin bu mantıkla tasarlandığını hatırlattı.

Gerekirse başka **analog sinyal işlemcilerle** ek işlemler yapılır. Hoca buna optik örüntü tanımayı örnek verdi: bir hedef (örneğin bir tank) önce bir kare içine alınır, sonra hareket ettikçe izlenir; telefon kamerasının yüzü kare içine alıp yüz hareket edince onu izlemesi gibi. Algoritmik karmaşıklık yüzünden burada ince kenarlı mercek ve bir elektronik devreyle hedef önce optik olarak ön işlemden geçirilir; böylece izleme ve tespit algoritmik yoldan daha hızlı yapılır. Bunlar analog işaret işlemenin konusudur. Sayısal işaret işleme ise tamamen yazılan algoritmalarla yapılan işlemlerdir.

### 2.3 Bilgisayar içindeki bloklar

Ön işlemden geçmiş, temizlenmiş ve güçlendirilmiş sinyal bilgisayara geldiğinde **analogdan sayısala dönüştürücü** (ADC) ile sayısal hale getirilir. Burada iki işlem vardır: önce zaman ekseninde **örnekleme** (sampling) ile sonsuz zamandan sonlu sayıda örneğe geçilir ve elde bir dizi olur (bir, iki ya da daha çok boyutlu); sonra genlik ekseninde **nicemleme** (quantization) yapılır. Bundan sonra sinyal bir sabit disk ya da bellek biriminde saklanabilir.

Bellekteki dizi, bir diziyi sıralamak nasıl bir işlemse, herhangi bir algoritmayla işlenir. Bu algoritma bir sıralama algoritması da olabilir, yüz tespiti, sesteki gürültünün bastırılması ya da konuşma tanıma da olabilir; günlük hayattaki problemi çözen algoritma neyse odur.

Şemadaki **Display** yalnız görüntü anlamına gelmez, genel olarak çıkışı ifade eder. İşlenen sinyal, ADC'nin tersini yapan **sayısaldan analoğa dönüştürücülerle** (DAC) yeniden fiziksel bir büyüklük olarak dış dünyaya verilir. Dersin büyük kısmında sinyal işleme blokları, bir kısmında da çıkış blokları incelenecek.

## 3. Analog sinyal ve bilgi kaybı

Başlangıç noktası analog bir sinyaldir, yani gerçek dünyada var olan fiziksel bir büyüklük. Slayttaki tanıma göre analog sinyal **sonsuz hassasiyetle tanımlı sürekli bir değişkendir** (ekrandan, 00:25:00). Analog ve sürekli (continuous) kavramları burada birbirinin yerine kullanılabilir. "Sonsuz hassasiyet", zamanın en küçük biriminde bile sinyalin bir karşılığının bulunabilmesi demektir.

Sayısal uygulamalar için analog sinyal, sayısal olarak temsil edilen ayrık bir ölçüm dizisine (discrete sinyal, sayısal sinyal) dönüştürülür. Bu dönüşümde kayıp vardır: örnekleme yapılırken iki örnek arasında kalan değişimler kaybolabilir. Kaybı önlemek ya da en aza indirmek için yapılması gerekenler dersin konusudur.

Slayta göre analogdan sayısala geçişte bilgi şu nedenlerle kaybolur:

- **Ölçümdeki hatalar:** ölçme cihazındaki ya da blok şemadaki herhangi bir elemanın görevini tam yapmamasından doğan hatalar.
- **Zamanlamadaki belirsizlik:** zaman ekseninde yapılan örneklemedeki belirsizlik.
- **Ölçüm süresindeki sınırlar:** ölçümün gerekenden kısa sürede ya da çözünürlüğü kötü bir cihazla yapılması.

Slayt bu etkilerin hepsine birden **nicemleme hataları** (quantisation errors) diyor. Hoca, blok şema bilindiğinde bu hataların nereden kaynaklandığını çıkarmanın zor olmadığını söyledi.

## 4. Sürekli sinyalden ayrık sinyale

### 4.1 Gösterim

Slayttaki gösterim şudur (ekrandan, 00:30:00):

$$x(t)=f(t)\;\leftrightarrow\;\text{analogdan sayısala dönüşüm}\;\leftrightarrow\;x[n]=x[1],x[2],x[3],\dots$$

Sürekli sinyal $t$ (zaman) domenindedir; ayrık hale gelince $n$ domenine geçilir. Sayısal sinyal ile ayrık sinyal burada aynı anlamda kullanılıyor.

### 4.2 Ekrandaki eğri gerçek mi?

Hoca slayttaki sürekli eğrinin birinin sesi olduğunu varsayıp bunun gerçek olup olmadığını sordu (aşağıda Örnek Sorular). Ekranda görülen her şey aslında ayrıktır. Örneğin bu kayıt 10 saniye boyunca $f_s=1000$ Hz ile (saniyede 1000 örnek) alınmış olsun. Bu durumda bellekte 10 000 elemanlı bir dizi vardır; C ile yazılırsa $x[0]$'dan $x[9999]$'a kadar elemanlara ulaşılır (tahtadaki notlar: $f_s=1000$, $x[9999]$, $10000$; ekrandan, 00:30:00). $x[0]$ ile $x[1]$ arasında gerçek sinyalin aldığı değerler bilinmez. Çizim programları bu boşluğu kapatıp eğriyi sürekliymiş gibi gösterir; bu bir **interpolasyondur**. Bir ses kaydedilip çizdirildiğinde sürekli bir dalga görülür, ama bu asıl sesin yüzde yüz aynısı değildir.

### 4.3 Sayısallaştırma örneği

Slayttaki örnekte 0–10 saniyelik sürekli bir sinyal zaman ekseninde 10 örneğe, genlik ekseninde de (örneğin 0–10 V aralığı) 10 seviyeye bölünmüştür. Her örnek anında sinyale en yakın seviye alınır. Okunan değerler şöyledir (ekrandan, 00:30:00):

| $n$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| $x[n]$ | 0 | 2 | 3 | 2 | 1 | 0 | 1 | 2 | 5 | 8 |

Bu değerlerin basamaklı çizimi ayrık sinyaldir. Basamaklar arasındaki dikey çizgiler aslında yoktur; nicemlemeden ve $n$ domenindeki süreksizlikten doğan çizgilerdir. Bu basamakların boyu ne kadar küçükse örnekleme o kadar iyi yapılmış, sayısal kayıt o kadar başarılı demektir.

Zaman ekseninde 10 saniye 10 örnek yerine yarım saniyede bir örnekle 20 örneğe, ya da 100 örneğe bölünebilir. Aralar kısalır ve orijinale daha yakın değerler elde edilir. Genlik ekseni de 10 yerine 100 parçaya bölünürse aralıklar sıklaşır ve sonuç daha hassas olur. Örneğin $n=2$'deki gerçek değer 2,7 civarındadır ama 3 olarak saklanır; daha az hata için genlik aralığının sıklaştırılması gerekir.

### 4.4 C dizisi benzetmesi

Hoca bu iki sıklığın programlamada neye karşılık geldiğini sordu. Tahtaya `X d[y];` yazdı: bir veri tipi `X` ve `y` elemanlı bir dizi `d` (ekrandan, 00:35:00).

- **Zaman eksenindeki sıklık** (örnekleme hızı) dizinin eleman sayısı $y$'yi belirler. Tahtadaki not: örnekleme hızı $\propto y$. 10 yerine 1000 örnek alınırsa dizi uzar.
- **Genlik eksenindeki sıklık** dizinin veri tipi `X`'i belirler. `int32` ile genlik ekseni $2^{32}$ parçaya, `int64` ile $2^{64}$ parçaya bölünür. Her elemanın alabileceği değer kümesi büyür ve hata azalır.

İkisi de artarsa orijinale daha yakın bir sonuç elde edilir ve nicemleme hatası azalır.

### 4.5 Analog sinyalin tanımı

Hoca bu kavramlarla analog sinyalin nasıl tanımlanacağını sordu. Bir öğrencinin "sonsuz örnek" cevabı doğruya yakındı. Tanım şudur: **zamanda ve genlikte sonsuz kez örneklenmiş sinyal analog (sürekli, orijinal) sinyaldir.** Örnekleme işlemi zaman ekseninde sonsuz kez, nicemleme genlik ekseninde sonsuz kez yapılabilseydi orijinal sinyal elde edilirdi.

Bu, bilgisayarlar için mümkün değildir. Belleği sınırlı hiçbir sayısal sistem (hafızası terabaytlarca olsa bile, küme ya da bulut ortamı da dahil) bunu yapamaz. Bir sesi tam olarak orijinal haliyle kaydeden bir cihaz yoktur; her zaman veri kaybı vardır. Bu yüzden zaman ve genlik eksenindeki örnekleme miktarının seçimi kapasiteyi doğrudan etkileyen önemli bir karardır; ne kadar az ya da çok yapılacağı ileride ele alınacak.

**Soru:** Bu, yalnız bizim bilgisayarlarımız için mi imkânsız? **Cevap:** Hafızası sınırlı olan bütün sayısal sistemler için imkânsızdır.

## 5. Analogdan sayısala dönüşümün dört adımı ve filtreleme

Slayta göre ADC bir analog sinyali dört adımda sayısallaştırır (ekrandan, 00:40:00):

1. **Filtreleme** (filtering)
2. **Örnekleme** (sampling) – zaman ekseninde
3. **Nicemleme** (quantization) – genlik ekseninde
4. **İkili kodlama** (binary encoding)

### 5.1 Filtreleme ve kokteyl parti problemi

Gelen ses doğrudan örneklenmeden önce bir filtreden geçirilir. Gerekçe: bir konuşmacıyı tanımak isteyen bir sistem, yandan gelen başka bir sesi de duyar. Aradaki gürültülerin yok edilmesi gerekir; bu da bir filtreleme işlemidir. Slayta göre filtreleme bazı bozulmaları (distorsiyonları) gidermek için yapılır.

Hoca bu noktada **kokteyl parti problemini** ekranda bir örnek sayfa üzerinden gösterdi: aynı anda üç dört kişi konuşur ve tek bir kayıttan her konuşmacının sesi ayrı ayrı elde edilmek istenir. Gösterilen örnekte iki gerçek konuşma sinyali birbirine karışmıştı ve **bağımsız bileşen analizi** (Independent Component Analysis, ICA) ile kısa bir Python koduyla yeniden ayrıştırılıyordu. Hoca, dersin yalnız matematikten ibaret olmadığını, böyle güzel uygulamaları olduğunu vurguladı.

> **Ek bilgi (derste anlatılmadı):** ICA, gözlenen karışık sinyalleri birbirinden istatistiksel olarak bağımsız kaynakların doğrusal karışımı olarak modelleyip kaynakları kestiren bir yöntemdir. Kaç kaynak ayrılacaksa genellikle en az o kadar mikrofon (karışık kayıt) gerekir.

### 5.2 Kodlama

Nicemlemede genlik ekseni yatay çizgilerle bölünür, örneklemede zaman ekseni dikey çizgilerle bölünür. Her yatay bölgenin 0 ve 1'lerle yazılması kodlamadır (encoding). Örneğin 100 örnek alınmışsa dizi 100 elemanlıdır; elemanlar 32 bitlik tam sayıysa her biri $2^{32}$ farklı değerden birini alır ve bu değerin ikili yazılışı ikili kodlamadır.

## 6. Örnekleme

### 6.1 Tanımlar

Örnekleme, sinyalin ölçümlerini temsil eden ayrık bir sayılar kümesi üretir (ekrandan, 00:45:00). Zaman genellikle eşit aralıklarla bölünür. Örnekleme yapıldıktan sonra ne ölçüldüğünün bir önemi kalmaz; elde yalnızca zamanda ayrık bir sayılar dizisi vardır.

Slayttaki tanımlar (ekrandan, 00:50:00):

- Analog sinyal her $T_s$ saniyede bir örneklenir.
- $T_s$ **örnekleme aralığıdır** (sampling interval). Ne kadar küçükse o kadar iyidir.
- $f_s=1/T_s$ **örnekleme hızı** ya da **örnekleme frekansıdır** (sampling rate, sampling frequency).

Bilgi kaybının bir nedeni örneklemenin yetersiz olmasıdır. Örneklemenin gereğinden fazla olması da bazı durumlarda sorun çıkarır; bu konu ileride ayrı bir başlıkta görülecek.

### 6.2 Örnekleme frekansı ne kadar yüksek olmalı?

**Soru:** Örnekleme frekansı ne kadar yüksekse o kadar iyi midir? **Cevap:** Elde edilen verinin orijinale uygun olması ve hatanın kabul edilebilir düzeyde kalması gerekir; ama bu, harcanacak maliyetle ve gerçek gereksinimle orantılı olmalıdır. Gözün algıladığı bir renk aralığı vardır; bir fotoğraf makinesinin bunun dışındaki frekansları algılaması gereksizdir. Ses için de kulağın algıladığı kadarını almak yeterlidir. MP3 ve CD/DVD kalitesi bunun standartlarıdır. Standardın fazlası gereksizdir, çünkü kulak onu algılamaz; azı ise kulağa bozuk gelir.

Hoca buna bir günlük hayat örneği verdi: bir videoyu 2 kat hızda dinlerken bazı konuşmacılar rahatça anlaşılır, bazıları hiç anlaşılmaz. Hocaya göre bu örnekleme frekansıyla ilgilidir; 2 kat hızda dinlerken $f_s$ fiilen değiştirilmiş olur ve kulak sonucu iyi algılayamaz.

> **Ders sonrası not:** Hoca 2 kat hızda oynatmayı örnekleme frekansının yarıya inmesi olarak anlattı. Büyük olasılıkla daha doğru bir ifade şudur: aynı örnekler iki kat hızla çalınır (ya da oynatıcı zaman esnetme ile örnek atar); sonuçta saniyede kulağa ulaşan bilgi değişir, konuşma hızlı ve bazen bozuk algılanır. Benzetme kavramsal olarak örnekleme hızıyla algı arasındaki ilişkiyi göstermek içindir.

### 6.3 Üç örnekleme yöntemi

Slayta göre üç örnekleme yöntemi vardır (ekrandan, 00:50:00):

- **İdeal örnekleme:** her örnekleme anında bir impuls.
- **Doğal örnekleme (natural):** genliği değişen, kısa genişlikte bir darbe; darbe boyunca sinyalin değişimini izler.
- **Flat-top:** örnekle ve tut (sample and hold); doğal örneklemeye benzer, ama darbe boyunca tek bir genlik değeri vardır. Bir nokta alınır ve bir sonraki örneğe kadar bu değer korunur; aradaki fark hatadır ve örnekler sıklaştıkça azalır.

Bu sürece **darbe genlik modülasyonu** (PAM) denir; sonuç hâlâ tam sayı olmayan (analog) değerli bir sinyaldir. Çünkü yalnız zaman ekseninde örnekleme yapılmıştır; genlikte henüz ayrıklaştırma yapılmamıştır. Hoca derste daha çok ideal örneklemenin kullanılacağını, diğer ikisinin daha çok elektronikçilerin ilgi alanı olduğunu söyledi.

### 6.4 Geri dönüşüm ve örnekleme hızı

Bu derste ve sayısal işaret işlemede yapılan her dönüşümün geri dönüşümü olabilmelidir. Sayısal hale getirilen sinyal yeniden analog yapıldığında orijinaline yakın olmalıdır. Analogdan sayısala geçerken bir kayıp, sayısaldan analoğa geçerken başka bir kayıp vardır; ikisinin de en az olması için uygun bir örnekleme oranı seçilmelidir.

Slayt, frekansı $f$ olan bir sinüs dalgasının farklı örnekleme hızlarında nasıl geri kazanıldığını gösteriyor (ekrandan, 00:55:00):

- **a. Nyquist hızında örnekleme, $f_s=2f$:** örnekler tepe ve çukur noktalarına düşer; birleştirilince aynı frekansta üçgen benzeri bir dalga çıkar. Alt ve üst noktalar kaybolmaz, ama sonuç yine tam yeterli değildir.
- **b. Aşırı örnekleme (oversampling), $f_s=4f$:** her periyotta dört örnek alınır; geri çatılan dalga orijinale daha çok benzer.
- **c. Yetersiz örnekleme (undersampling), $f_s=f$:** her periyotta bir örnek alınır; noktalar birleştirildiğinde orijinal sinyalle çok ilgisi olmayan bir çizgi çıkar.

**Soru:** $f_s=f$ durumu ne demek? **Cevap:** Örneğin 1 kHz'lik bir sinüs için saniyede 1000 örnek almak, yani sinyalin kendi frekansıyla örneklemektir. Her periyotta bir örnek alınır; bunlar birleştirilince orijinalden çok farklı bir sinyal çıkar. Hoca slayttaki çizimde bir noktanın fazladan ya da yanlış yere konmuş olabileceğini, bunun kitabın çiziminden kaynaklanabileceğini belirtti.

### 6.5 Nyquist kuralı

Bir sinyalin en az hatayla eski haline döndürülebilmesi ve örtüşme (aliasing) oluşmaması için örnekleme frekansı, **sinyalin içerdiği en büyük frekansın en az iki katı** olmalıdır:

$$f_s \ge 2 f_{max}$$

Slayttaki ifade: "sampling rate must be at least two times the highest frequency content in the signal". Bir sinyal kendi içinde farklı frekans bileşenleri içerebilir; bunların en büyüğü $f_{max}$'tır.

- Önceki derste gösterilen, 1 kHz ve 2 kHz'lik iki sinüsün toplamı olan sinyal için $f_{max}=2$ kHz'dir; sinyali geri çatmak için en az 4 kHz ile örnekleme gerekir.
- Bileşenleri 1, 2, 3 ve 8 kHz olan bir sinyal için en az $2\times 8=16$ kHz gerekir.

> **Hocanın vurgusu:** Önemli olan sinyalin frekansının değil, sinyalin içindeki en büyük frekansın iki katını almaktır. İki katını almak kolaydır; asıl problem en büyük frekansı bulmaktır. Bu, Fourier serileri ve Fourier dönüşümü konusunda görülecek.

Bu kural **Nyquist teoremi** (Nyquist hızı) olarak bilinir ve örnekleme konusunda ayrıntılı işlenecek.

### 6.6 Ses örnekleri: CD ve MP3

**CD kalitesi** 44 100 Hz ile örneklenir. Bunun yarısı 22 050 Hz'dir. İnsan kulağının duyma aralığı yaklaşık 20 Hz ile 20 kHz arasındadır; 22 050 Hz bu üst sınırın üstünde kaldığından müzik rahatça duyulur. Tahtadaki notlar: CD = 44100, 22050, 20 kHz (ekrandan, 01:00:00).

Örnekleme frekansı arttıkça bir saniyelik sesin dizisi uzar. Hoca, MHz düzeyinde örneklenen bir kayıtta (örneğin 4 MHz) bir saniyelik müziğin yaklaşık 4 milyon elemanlı bir dizi olacağını söyledi. Bir MP3 dosyası ortalama 4–5 MB'tır; sıkıştırılmış olduğu için açılıp işlenmek üzere belleğe alındığında 4 dakikalık bir şarkı yaklaşık 50–60 MB'a çıkar (tahtadaki not: MP3: 4 MB – 60 MB).

> **Ders sonrası not:** Hoca DVD'lerin MHz düzeyinde örneklendiğini ve örnekleme frekansının "eskiden 44 milyon" olduğunu söyledi. Büyük olasılıkla kastedilen CD'nin 44,1 kHz'idir; DVD-Audio gibi biçimlerde örnekleme frekansı büyük olasılıkla en çok 192 kHz düzeyindedir. 4 dakikalık, 44,1 kHz, 16 bit, iki kanallı sıkıştırılmamış ses $4\times60\times44100\times2\times2\approx 42$ MB eder; bu, hocanın verdiği büyüklük mertebesiyle uyumludur.

<!-- BELİRSİZ: Altyazıda bir slayt örneği için "örnekleme frekansı 1024 kHz" deniyor; bu slaytın karesi yok, değer doğrulanamadı. -->

### 6.7 Filtreler ve örnekleme

Filtre, sinyaldeki belli frekansları koruyan, belli frekansları sıfırlayan bir algoritmadır. Hoca şu örneği verdi: sinyalde frekansı bilinen (örneğin 4 kHz'lik) bir gürültü vardır. Sinyal zaman domeninden frekans domenine götürülür, gürültünün frekansına karşılık gelen değer sıfırlanır ve yeniden zaman domenine dönülür; böylece gürültüsüz sinyal geri elde edilir. "Bastırmak", frekans domenindeki dizide ilgili değerleri sıfır yapmak demektir.

- **Alçak geçiren (low-pass):** frekans ekseninde bir eşik belirlenir; bu durumda örnekleme için $f_{max}$ olarak eşik alınır ve Nyquist kuralı uygulanır.
- **Yüksek geçiren (high-pass):** eşiğin bir tarafındaki frekanslar bastırılır.
- **Bant geçiren (band-pass):** yalnız belli bir aralıktaki frekanslar geçirilir; bir minimum ve bir maksimum verilir. Örnekleme için yine maksimumun iki katı alınır.

> **Ders sonrası not:** Hoca alçak geçiren filtrenin "eşiğin altındaki frekansları", yüksek geçirenin "eşiğin üstündekileri" bastırdığını söyledi; doğrusu tersidir. Alçak geçiren filtre eşiğin (kesim frekansının) altını geçirip üstünü bastırır, yüksek geçiren üstünü geçirip altını bastırır. Ayrıca tek bir gürültü frekansını sıfırlama örneğine "bant geçiren" dedi; tek bir bandı atan filtre bant durduran (band-stop, notch) filtredir.

## 7. Nicemleme ve kodlama

### 7.1 Nicemlemenin tanımı

Örnekleme sonunda genlikte sürekli, zamanda ayrık darbeler elde edilir. Bu değerlerin bilgisayarda saklanabilmesi için genlik ekseninde de bir tür örnekleme yapılması gerekir; buna **nicemleme** denir. Slayttaki açıklama (ekrandan, 01:05:00):

- Örnekleme, iki sınır (min ve max) arasında değişen genlikli bir darbe dizisi üretir.
- İki sınır arasındaki genlik değerleri sonsuzdur; gerçel sayılarla çalışılmaktadır.
- Bu sonsuz genlik değerleri sonlu, bilinen bir değer kümesine eşlenmelidir.
- Bu, min ile max arasındaki uzaklığın her biri $\Delta$ yüksekliğinde $L$ bölgeye bölünmesiyle yapılır:

$$\Delta=\frac{\max-\min}{L}$$

Örneğin 8 bit kullanılırsa aralık $2^8=256$ eşit parçaya bölünür (tahtadaki not: $2^8=256$). Bölge sayısı kullanılan bit sayısıyla belirlenir. Bilgisayardaki gerçel ya da tam sayı türleri sonsuz bitli olsaydı genlikte orijinal veri elde edilebilirdi. Bölgelere 0'dan $L-1$'e kadar numara verilir; her bölgedeki değerler bir temsilci değere yuvarlanır (approximation).

### 7.2 Bölgelere kod atama

Her bölgeye bir ikili kod atanır. Bölgeleri kodlamak için gereken bit sayısı, yani örnek başına bit sayısı (ekrandan, 01:10:00):

$$n_b=\log_2 L$$

$L$ ikinin kuvveti değilse sonuç üste yuvarlanır. Örneğin en az 20 bölge gerekiyorsa 20 bölge kurulamaz; 32 bölge alınır ve 5 bitle kodlanır.

Hoca burada veri aktarım protokollerine bir bağlantı kurdu (tahtadaki not: UDP – müzik, TCP). UDP genellikle müzik ve görüntü gibi akan (streaming) verilerin aktarımında kullanılır; birkaç bitlik hata insan kulağı tarafından pek fark edilmez. TCP'de ise indirilen bir dosyanın bütün bitleri eksiksiz gelmelidir, yoksa dosya açılamaz. Sayısallaştırılmış ses ve görüntü gibi işaretler de hataya bu ölçüde dayanıklı olduğundan böyle protokollerle aktarılabilir.

### 7.3 Örnek: ±20 V aralığında 8 seviyeli nicemleme

Sinyalin en büyük genliği $+20$ V, en küçük genliği $-20$ V'tur. Sinyal 2 kHz'lik olsun; Nyquist kuralına göre en az 4 kHz ile örneklenir, yani bir saniye için 4000 elemanlı bir dizi elde edilir. Her elemanın kaç bit tutacağını bulmak için 8 nicemleme seviyesi seçilsin.

- **Verilen:** $\max=20$ V, $\min=-20$ V, $L=8$.
- **Adım:** $\Delta=\dfrac{20-(-20)}{8}=\dfrac{40}{8}=5$ V. Genlik beşer voltluk adımlarla saklanır.
- **Bit sayısı:** $n_b=\log_2 8=3$ bit.
- **Bölgeler:** slayttaki atamaya göre 000 kodu $-20$ ile $-15$ V, 001 kodu $-15$ ile $-10$ V arasını temsil eder (ekrandan, 01:15:00). Diğer bölgeler aynı mantıkla devam eder (ara adım eklendi):

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

Her bölgenin sınır noktaları ve orta noktaları vardır. Kararsızlık olmasın diye her değer bulunduğu bölgenin orta noktasına yuvarlanır. Örneğin 7,8 V'luk bir örnek 5–10 V bölgesine düşer ve 7,5 V olarak saklanır (kod 101).

> **Ders sonrası not:** Hoca 7,8 V için "7,5'ten büyük olduğu için bir üst seviyeye, küçük olsaydı alt seviyeye yuvarlanır" dedi. Bölgeler 5'er voltluk olduğundan 5 ile 10 V arasındaki her değer aynı bölgededir ve bu bölgenin temsilcisi orta nokta olan 7,5 V'tur; 7,8 V de 7,2 V de 7,5 V'a eşlenir. Bir üst bölgeye geçiş 10 V sınırında olur.

- **Bellek:** 4000 örneğin her biri 3 bit olduğundan bir saniyelik kayıt $4000\times 3=12\,000$ bit, yani 1500 bayt tutar. Bu değer kilobayt ya da megabayta çevrilerek sinyalin bellekte kapladığı alan bulunur.

Slayttaki bir sonraki şekilde (nicemlenmiş ve kodlanmış örnek sinyal) her örneğin hangi bölgeye düştüğü, nicemlenmiş değeri ve kodu gösteriliyordu; örneğin yaklaşık 1,22 olan bir değer 1,50'ye yuvarlanıp o bölgenin koduyla saklanıyordu. <!-- BELİRSİZ: Bu slaytın (nicemleme ve kodlama tablosu) okunur bir karesi yok; tablodaki değerler doğrulanamadı. -->

**Soru:** 8'e ayırdığımız şey 8 bit mi? **Cevap:** Hayır, 8 bölge. 8 nicemleme seviyesi, genlik aralığının 8 eşit parçaya bölünmesi demektir; bunun için 3 bit gerekir.

## 8. Nicemleme hatası ve ADC örnekleri

### 8.1 Nicemleme hatası

Slayttaki tanım (ekrandan, 01:15:00):

- Bir sinyal nicemlendiğinde bir hata oluşur: kodlanmış sinyal, gerçek genlik değerinin bir yaklaşığıdır.
- Gerçek değer ile kodlanmış değer (orta nokta) arasındaki farka **nicemleme hatası** denir.
- Bölge sayısı arttıkça $\Delta$ küçülür; bu da daha küçük hatalar demektir.
- **Ama** bölge sayısı arttıkça örnekleri kodlamak için gereken bit sayısı artar; bu da daha yüksek bit hızı demektir.

Bu bir ödünleşimdir (trade-off): genlik eksenini 100, 1000 ya da 1024 parçaya bölmek hatayı azaltır ama daha çok bellek harcar.

### 8.2 ADC doğruluğu

Slayttaki örnek (ekrandan, 01:35:00): 12 bitlik bir ADC, en anlamsız bit (LSB) kadar $\pm$ doğruluk vaat ediyor. Giriş aralığı 0–10 V ise ADC'nin doğruluğu kaç volttur?

- **Verilen:** $V_{max}=10$ V, bit sayısı 12.
- **İşlem:** LSB'nin temsil ettiği gerilim

$$V_{LSB}=\frac{V_{max}}{2^{\text{bit sayısı}}}=\frac{10}{2^{12}}=\frac{10}{4096}\approx 0{,}0024\ \text{V}$$

- **Sonuç:** doğruluk $\pm 0{,}0024$ V'tur.

Bit sayısı artarsa bu değer küçülür ve doğruluk artar. Paydanın sonsuz olması, yani sonsuz bitle nicemleme yapılması durumunda hata sıfır olur.

### 8.3 Sınavda gelebilecek türden bellek hesabı

Hoca bu konudan nasıl soru gelebileceğini bir örnekle gösterdi: bir konuşmacının sesi 2 kHz, 6 kHz ve 12 kHz'lik bileşenler içeriyor. Sinyal 60 saniye boyunca kaydediliyor, genlik aralığı $-30$ ile $+30$ arasında ve en az 180 seviyeyle nicemleniyor. Sinyalin boyutu nedir?

- **En büyük frekans:** $f_{max}=12$ kHz.
- **Örnekleme frekansı:** $f_s\ge 2f_{max}=24$ kHz; saniyede 24 000 örnek.
- **Örnek sayısı:** $24\,000\times 60=1\,440\,000$.
- **Örnek başına bit:** 180 farklı değer gerekir; $2^7=128<180\le 256=2^8$ olduğundan $\lceil\log_2 180\rceil=8$ bit, yani 1 bayt. Genlik aralığının $\pm30$ olması sonucu değiştirmez; önemli olan seviye sayısıdır.
- **Sonuç:** $1\,440\,000$ bayt $=144\times 10^4$ B, yaklaşık 1,44 MB.

Aynı mantık görüntüye de uygulanır: yatayda 500, dikeyde 800 piksel olan ve her pikseli 180 farklı renkten birini alan bir görüntü için piksel başına 8 bit gerekir; toplam $500\times 800\times 8=3\,200\,000$ bit (400 000 bayt) olur.

> **Hocanın vurgusu:** Bu tür, basit dört işlemle sinyal işleme bilgisini birleştiren sorular gelebilir; akılda bulunsun.

## 9. Örneklemeyle ilgili kavramlar

Slaytta örneklemeyle ilgili şu kavramlar listelendi (ekrandan, 01:40:00):

- **Aşırı / tam / yetersiz örnekleme (over/exact/under sampling):** Nyquist hızından gereksiz yere fazla, tam Nyquist hızında ve Nyquist hızından az örnekleme.
- **Düzenli / düzensiz örnekleme (regular/irregular):** ileride ayrıntılı görülecek.
- **Doğrusal / logaritmik örnekleme (linear/logarithmic):** doğrusal örneklemede zaman ekseni eşit aralıklarla, logaritmik örneklemede logaritmik aralıklarla bölünür.
- **Örtüşme (aliasing):** sinyalin geri üretilmesi sırasında oluşan örtüşme.
- **Örtüşme önleyici filtre (anti-aliasing filter):** örtüşmeden kurtulmak için tasarlanan filtre. Bunun karşılığı olarak görüntü (image) ve görüntü önleyici (anti-image) filtreler de vardır.

Bu konular örnekleme bölümünde (yaklaşık üçüncü ya da dördüncü bölüm) ayrıntılı işlenecek. Bu aşamada bilinmesi gereken $f_s>2f_{max}$ koşulu ve nicemleme hatasıdır.

Analogdan sayısala dönüşümde frekans belirlenir (sinyalin bant genişliği, yani $f_{max}$'ın bulunması), örnekleme, nicemleme ve kodlama yapılır. Sayısaldan analoğa dönüşümde bu işlemlerin tersleri yapılır ve orijinal sinyale geri dönülür (reconstruction). Ayrık örneklerden orijinal sinyalin yeniden kurulması **interpolasyondur**; sayısal analiz dersinden bilinen bu konunun ileri düzeyi lisansüstü düzeyde işlenir.

## 10. Sayısal veri temsili

Hoca bu bölümün büyük kısmının lojik devreler, assembly, yapısal programlama ve ayrık matematik derslerinde görüldüğünü, bu yüzden hızlı geçeceğini ve bu kısımdan soru sormayacağını söyledi. Amaç, bir sinyalin bilgisayarda saklanmasını lojik seviyeye kadar izlemekti.

### 10.1 Bit ve elektrik seviyeleri

Bit, 1 ya da 0'ı ifade eder. Bu değerler bellek elemanındaki (RAM, diyot, transistör, kapasitör gibi yarı iletken elemanlar) elektriğin varlığından ya da yokluğundan gelir. Lojik elemanlarda bir eşik vardır: belli bir gerilimin altı 0, belli bir gerilimin üstü 1 olarak okunur, arada kararsız bir bölge bulunur. Hoca örnek olarak yaklaşık 2,2 V'a kadar 0, 3–5 V arası 1 bölgesi ve arada kararsızlık bölgesi verdi; değerler kullanılan elemana göre değişir.

4 bitlik gruba **nibble** denir; iki nibble bir **bayt** eder, baytlar da **word** gibi daha büyük birimleri oluşturur. Bu birimlerden tam sayılar, işaretli tam sayılar ve uzun tam sayılar kurulur.

Bir sesin bilgisayardaki yolculuğu baştan sona şöyledir: ses kaydedicisi sesi alır, filtreden ve ADC'den geçen ses 0 ve 1'lere dönüşür, bir sayısal işaret işleme algoritması bellekteki verileri alıp işler ve sonucu çıkışa verir; çıkış hoparlörden ses dalgası olarak dışarı yansıtılır.

### 10.2 Kapasite, frekans ve zaman birimleri

- Ondalık önekler: kilo $10^3$, mega $10^6$, giga $10^9$.
- Bellekte ikinin kuvvetleri kullanılır: $2^{10}=1024\approx 10^3$, $2^{20}$, $2^{30}$. Örneğin 4 GB RAM $=2^2\times 2^{30}=2^{32}$ bayttır.
- **Hertz**, saniyedeki çevrim sayısıdır. 1 MHz $=10^6$ Hz, 1 GHz $=10^9$ Hz; genellikle işlemci hızlarında kullanılır.
- Zaman birimleri: milisaniye ($10^{-3}$ s), mikrosaniye, nanosaniye, pikosaniye, femtosaniye.

### 10.3 Veri türleri

Bir problemle uğraşırken ilk bilinmesi gereken, verinin türüdür: ses mi, görüntü mü, video mu? Örneğin yüz tanıma uygulamasında bir görüntü ya da video vardır ve işlem onun üzerinde yapılır. Bilgisayardaki veri türleri sayılar, karakterler, görüntü, ses, mantıksal veriler ve komutlardır (instructions); hepsi sonunda 0 ve 1'lerle temsil edilir.

### 10.4 Sayı sistemleri ve sabit noktalı gösterim

Sayı sistemi, verilerin farklı tabanlarda ifade edilmesidir. Bir sayı rakam sembollerinin bir araya getirilmesiyle oluşur. Ondalık (decimal) sistemde on rakam vardır (ekrandan, 01:50:00). Tam sayı olmayan gerçel sayılar için ondalık nokta eklenir ve sabit noktalı (fixed point) gösterim elde edilir (ekrandan, 01:55:00):

$$3456.78=3\cdot10^3+4\cdot10^2+5\cdot10^1+6\cdot10^0+7\cdot10^{-1}+8\cdot10^{-2}$$

Negatif sayılar için ayrılan bitlerden biri işaret biti (sign bit) olarak kullanılır; kalan bitler sayının büyüklüğünü taşır.

### 10.5 Bire ve ikiye tümleme

Bir $A$ sayısından $-A$'yı elde etmek için bire tümleme ya da ikiye tümleme kullanılır; çıkarma işlemi böylece toplamaya çevrilir.

- **İkiye tümleme (uzun yol):** bitler ters çevrilir, sonra 1 eklenir.
- **İkiye tümleme (kısa yol):** sağdan başlayarak ilk 1'e kadar (o 1 dahil) bitler aynen yazılır, solundaki bitler ters çevrilir.

Hoca, bu konudan sorulabilecek en fazla şeyin "7 − 5'i ikiye tümleme yöntemiyle hesaplayınız" gibi bir soru olduğunu söyledi ve bunu 8 bit üzerinde çözdü (çözüm Örnek Sorular'da).

### 10.6 Kayan noktalı sayılar

Elektron yükü ($e=1{,}602\,176\,462\times10^{-19}$ C) ya da evrenin hacmi ($1\times10^{85}$ cm³) gibi çok büyük ya da çok küçük sayıları saklamak için kayan noktalı (floating point, bilimsel) gösterim kullanılır. Bu sayıların iki bileşenine **mantis** ve **üs** denir (ekrandan, 01:55:00). Standart gösterim IEEE 754'tür.

Hocanın 25,75 örneği:

1. Sayı ikili yazılır: tam kısım $25=11001_2$, kesir kısmı $0{,}75=0{,}11_2$; yani $25{,}75=11001{,}11_2$.
2. Bilimsel gösterime geçilir: noktadan önce tek basamak kalacak şekilde nokta 4 basamak sola kaydırılır: $1{,}100111_2\times 2^4$.
3. İşaret biti 0'dır (pozitif).
4. Üs, sapma (bias) eklenerek yazılır: $4+127=131=10000011_2$.
5. Mantis kısmına baştaki 1 dışındaki bitler yazılır: $10011100\dots0$ (23 bit).

Sonuç (ara adımlar eklendi; python ile doğrulandı): `0 10000011 10011100000000000000000`, onaltılık olarak `41CE0000`.

Tek duyarlıkta (32 bit) 1 işaret, 8 üs ve 23 mantis biti vardır; sapma 127'dir. Çift duyarlıkta (64 bit, double precision) hassasiyet artar ve sapma 1023'tür. Değer $(-1)^{s}\times 1.\text{mantis}\times 2^{(\text{üs}-\text{sapma})}$ ile bulunur.

> **Ders sonrası not:** Hoca sapma değerlerinin bit sayısından geldiğini söyledi ama formülü karışık ifade etti. $k$ bitlik üs alanı için sapma $2^{k-1}-1$'dir: tek duyarlıkta $2^7-1=127$, çift duyarlıkta (11 bitlik üs) $2^{10}-1=1023$.

### 10.7 Sayısal olmayan bilginin kodlanması

Renkler gibi sayısal olmayan bilgiler de kodlanarak saklanır. Örneğin 7 renk (kırmızı, turuncu, ...) saklanacaksa her birine bir ikili kod atanır; bunun için en az 3 bit gerekir. Bir kod kullanılmadan kalır.

$M$ elemanı ikili kodla temsil etmek için gereken en az bit sayısı $n$ şu ilişkiyi sağlar (ekrandan, 02:00:00):

$$2^{n}\ge M>2^{(n-1)},\qquad n=\lceil\log_2 M\rceil$$

Burada $\lceil x\rceil$, $x$'ten büyük ya da ona eşit en küçük tam sayıyı veren tavan (ceiling) fonksiyonudur. 7 eleman için $\log_2 7\approx 2{,}81$, tavanı 3'tür. Hoca pratikte bunun yerine $M$'den büyük en yakın ikinin kuvvetinin (7 için $8=2^3$) üssünün alındığını söyledi. Ondalık rakamlar (0–9, 10 eleman) için 4 bit gerekir.

Ters soru: $r$ tabanında $n$ basamakla $r^n$ farklı eleman temsil edilebilir. Örneğin 5 bitle $2^5=32$ farklı durum gösterilir.

### 10.8 Kodlama devreleri ve hata denetimi

**Kodlayıcı** (encoder) $N$ girişi alır ve $\log_2 N$ bitlik bir koda çevirir; örneğin 1024 giriş 10 bitle kodlanır. Tersini **kod çözücü** (decoder) yapar. Ondalık rakamları 4 bitle kodlayan **8-4-2-1** (BCD) kodu da bunun bir örneğidir.

Veri aktarımında **eşlik** (parity) gibi hata denetleme kodları kullanılır. Gönderilen bit dizisine bir eşlik biti eklenir; alıcı 1'lerin sayısını denetler. Denetim tutmazsa veri yolda bozulmuştur (örneğin elektriksel dönüşümler sırasında bir bit değişmiştir) ve yeniden gönderim istenir.

> **Ek bilgi (derste anlatılmadı):** Çift eşlikte (even parity) eşlik biti, eşlik biti dahil toplam 1 sayısını çift yapacak şekilde seçilir; tek eşlikte (odd parity) toplam 1 sayısı tek olur. Hocanın anlatımında tek ve çift eşliğin tanımı altyazıda karışık geçiyor; doğru tanım budur. Tek eşlik biti tek bitlik hataları yakalar ama düzeltemez.

### 10.9 ASCII ve Unicode

Büyük ve küçük harfler, rakamlar ve özel semboller ASCII ile kodlanır. Unicode 16 bitle 65 536 farklı karakteri temsil eder. ASCII'de 94 yazdırılabilir (grafik) ve 34 yazdırılamayan (kontrol) karakter vardır.

ASCII'nin ilginç özellikleri (ekrandan, 02:05:00):

- 0–9 rakamları onaltılık $30_{16}$ ile $39_{16}$ arasındadır, yani ondalık 48–57.
- Büyük harfler 65'ten ('A'), küçük harfler 97'den ('a') başlar.
- Aynı harfin büyük ve küçük biçimi arasında 32 fark vardır ($65=01000001_2$, $97=01100001_2$). Yalnız bir bit değişir; Shift ya da Caps Lock bu biti çevirerek büyük-küçük harf dönüşümünü sağlar.

> **Ders sonrası not:** Hoca 256 ASCII karakterinden ve büyük harflerin "65'ten 97'ye kadar" gittiğinden söz etti, sonra düzeltti. Standart ASCII 7 bitlik, 128 karakterlik bir koddur (94 + 34 = 128); 256 karakter 8 bitlik genişletilmiş ASCII'ye karşılık gelir. Büyük harfler 65–90 ('A'–'Z'), küçük harfler 97–122 ('a'–'z') arasındadır.

**Dönüşüm ve kodlama farkı:** Bir sayının başka tabanda yazılması bir **dönüşümdür** (conversion); bir karaktere ya da sembole bir kod atanması ise **kodlamadır** (coding). Doğrudan karşılık bulmak ile kod atamak farklı işlemlerdir.

### 10.10 Mantıksal işlemler

Bitler önermeler mantığı ve Boole cebiri için de kullanılır. NOT, AND, OR, XOR ve XNOR işlemlerinin doğruluk tabloları vardır; XOR, AND ve NOT cinsinden de yazılabilir. Ayrık matematikten bilinen "ise" (if) ve "ancak ve ancak" (if and only if) bağlaçları da bu gruptadır.

**Soru:** Bu konular ikinci sınıfın bu döneminde henüz lojik devreler dersini almamış öğrenciler için anlaşılır mı, bu derste bilinmeleri gerekiyor mu? **Cevap:** Bu dersin kapsamında bu ayrıntıları bilmek gerekmiyor; lojik devreler dersinde ayrıntılı görülecek. Bu dersten beklenen, aşağıdaki özetteki sayısallaştırma adımlarıdır.

## 11. Sayısallaştırma bölümünden bilinmesi gerekenler

Hoca bu bölümün özetini şöyle yaptı: elimizde bir müzik, bir veri ya da bir resim var ve bunu işlemek istiyoruz. Bu orijinal, sürekli bir veridir. Bunu sayısal hale getirmek için gereken adımlar bilinmelidir:

- Sayısallaştırma (digitization) nedir, adımları nelerdir?
- Örnekleme nasıl yapılır, nicemleme nasıl yapılır?
- Nicemleme hatası nedir?
- Bir görüntüyü saklamak için kaç bit gerekir (how many bits required to store the image)?
- Kodlama nedir, nicemleme aralığı nedir? Örneğin $+20$ ile $-20$ arası belli sayıda parçaya bölündüğünde $-3{,}8$'in hangi bölgeye düştüğü ve bit karşılığı nedir?

> **Hocanın vurgusu:** Bu iki slayt dosyası bilgisayar biliminin temel bir tekrarıdır; bu sorulara cevap verebilmek bu bölüm için yeterlidir. Küçük ayrıntılar önemlidir.

## 12. Sinyaller ve sistemler

Bu bölümle birlikte üçüncü slayt dosyasına geçildi ve sinyal ve sistemlerin özelliklerine girildi.

### 12.1 Sinyal

Haberleşme ve bilgi açısından sinyal, bir radyo ya da televizyon yayın sinyali, bir ses, bir elektrik gerilimi gibi büyüklüklerdir. Genel olarak fiziksel ya da soyut, ölçülebilen her büyüklük bir sinyal olarak ifade edilebilir: bir bisiklet fren kablosundaki gerilim, doların euro karşısındaki değeri, bir ülkenin bütçe açığı. Doların gün içindeki seyri öğlen, saat dörtte, akşam ve gece ölçülecekse yapılacak şey yine örnekleme ve nicemlemedir.

### 12.2 Sistem

Slayttaki tanım (ekrandan, 02:15:00): bir **sistem** (fiziksel, matematiksel ya da hesaplamalı), bir **giriş sinyalini** bir **çıkış sinyaline** dönüştürme biçimiyle tanımlanır.

```text
signal in --> [ system ] --> signal out
```

Radyo alıcısı, amplifikatör, modem, mikrofon, telefon ve bilgisayar birer sistemdir; hepsi bir sinyalden başka bir sinyal üretir. Bir sistem birden çok sinyal üzerinde işlem yapabilir ve birden çok sistem bir araya getirilebilir. Yazılan bir algoritma da kurulan bir devre de sistemdir. Hoca tahtada 4 girişli, 1 çıkışlı bir blok çizdi: ayrık matematikte sorulan "4 girişli, 1 çıkışlı bir devrenin blok şemasını çizin" sorusu, sistem açısından 4 girişli ve 1 çıkışlı bir sistem demektir.

### 12.3 Sinyaller matematiksel fonksiyonlardır

Slayttaki ifade (ekrandan, 02:20:00):

- **Bağımsız değişken** = zaman (ya da kuvvet gibi başka bir büyüklük); girişte kullanılan değişkendir.
- **Bağımlı değişken** = gerilim, akış hızı, ses basıncı; bağımsız değişkene bağlı olarak değişen çıkıştır.

Slayttaki üç örnek sistem:

| Giriş | Sistem | Çıkış |
|---|---|---|
| $x(t)$: sinüs biçimli kuvvet | kütle ve yay sistemi | $y(t)$: kaymış sinüs biçimli hareket |
| $r_0(t)$: kısa süreli dikdörtgen darbe (musluk açılıp kapanır) | tank sistemi | $r_2(t)$: yükselip yavaşça sönen akış |
| sound in | cep telefonu sistemi | sound out |

**Kütle-yay sistemi.** Bir yaya kuvvet uygulandığında oluşan uzama zamanla ölçülür. Bu sistemin bir fonksiyonu vardır: $F=kx$, $k$ yay sabitidir. Girişe verilen kuvvetle çıkıştaki uzama bulunur. Sistemler her zaman böyle basit doğrusal denklemlerle tanımlanmaz. Örneğin $y$'nin türevleri ile $x$ arasında $y''+y'=x$ türünden bir diferansiyel denklem verilip "sistemi bulun", yani $y$'yi $x$ cinsinden yazın denebilir. Bu diferansiyel denklem çözüldüğünde sistemin girişe karşı davranışı ifade edilir. Diferansiyel denklemlerin doğrudan çözümünden kaçınmak için Fourier ve Laplace dönüşümleri gibi daha kolay yollar kullanılacak.

**Tank sistemi.** Birbirine bağlı iki tank vardır; girişe $r_0(t)$ akışı verilir, çıkıştan $r_2(t)$ akışı alınır. "Musluk açıldıktan 3 saniye sonra şu tanktaki su miktarı nedir?" türünden bir soru, havuz problemlerine benzer; burada zorluk sürekliliği ayrık hale getirmektir.

**Cep telefonu sistemi.** Bir telefondan alınan ses en yakın baz istasyonuna (kuleye) gider, kuleler arasında yönlendirilir ve en son karşı telefona en yakın kuleden o telefona aktarılır. Bu süreç bilgi kaybını en aza indirecek biçimde tasarlanmıştır. Bütün bu işlem birçok **alt sistemden** (subsystem) oluşur; alt sistemleri içeren sistemlere **bileşik sistem** (composite system) denir.

Bu örnekler, sinyal ve sistem kavramlarının mekanik, akışkan ve haberleşme gibi farklı alanlara yayıldığını gösterir. Sinyal işleme algoritmaları da (örneğin yüz tespiti, bir tespit algoritması olarak) aynı mantıkla başka alanlarda başka şeyleri tespit etmek için kullanılabilir.

## 13. Frekans domeni neden gerekli?

### 13.1 Zaman domeninin sınırı

Şimdiye kadar yapılanların hepsi zaman domenindeydi: zamanın örneklenmesi, genliğin nicemlenmesi ve verinin saklanıp işlenmesi. Ama sinyalin içinde zaman bilgisinden doğrudan çıkarılamayan, gizli bilgiler vardır; bunlardan biri **frekanstır**.

Slaytta dört sinyal gösterildi ve hangisinin en hızlı değiştiği soruldu. <!-- BELİRSİZ: Dört sinyalin gösterildiği slaytın karesi yok; sinyallerin genlik değerleri ve hangisinin en hızlı olduğu altyazıdan net çıkarılamıyor. --> Tek bir sinüzoidin, örneğin genliği 0,1 olan bir sinyalin, kendine özgü bir frekansı vardır. Açısal frekans $\omega=2\pi f$ ile gösterilir; $2\pi$ sabit olduğundan $\omega_1$ ile $f_1$ aynı bilgiyi taşır. Sinyaller zaman düzleminde karşılaştırılınca hangisinin daha hızlı değiştiği görülebilir.

Fizikteki dalgalar konusundan bilindiği gibi tek bir sinüzoidin frekansı zaman grafiğinden bulunabilir: periyot $T$ ölçülür ve $f=1/T$ hesaplanır. Osiloskop da bunu yapar. Ama birkaç sinüzoidin toplamından oluşan bir sinyalin ayırt edici özellikleri bulunmak istendiğinde zaman domeni çoğu zaman işe yaramaz; **frekans domenine** geçmek gerekir. Günlük hayattaki EKG ve ses gibi karmaşık sinyallerin ayırt edici özellikleri frekans düzleminde daha kolay ortaya çıkar.

**Soru:** Grafiklerdeki 0,1 ve 0,2 değerleri frekans mı gösteriyor? **Cevap:** Hayır, bunlar genlik değerleridir. Frekanslar yalnız $\omega_1,\omega_2,\omega_3$ olarak verilmiştir. Çizimlerden göz kararı kıyas yapılabilir, ama doğrusu frekans değerlerinin verilmesidir (örneğin 300 Hz, 500 Hz, 800 Hz) ve kıyasın bunlar üzerinden yapılmasıdır.

### 13.2 Frekans domeni gösteriminin yararları

Slayttaki örnek sinyal büyük ölçüde $\omega_2$ frekanslı bir sinüzoiddir; $\omega_1$ ve $\omega_3$ frekanslı sinüzoidlerden küçük katkılar içerir (ekrandan, 02:25:00). Bu, bu durum için çok basit bir gösterimdir; ancak sinyalin herhangi bir andaki değeri bu gösterimden hemen görülmez.

Frekans domeni gösterimi neden kullanılır?

- Birçok sinyal türü için daha basittir (örneğin AM radyo sinyali).
- Birçok sistem bu bakış açısından daha kolay analiz edilir (doğrusal sistemler).
- Bir sistemin temel özelliklerini ortaya çıkarır.
- Kısa sürede dünyaya bakmanın alternatif bir yolu haline gelir.

Hocanın sayısal örneği: genliği 0,1 ve frekansı $\omega_1$ olan bir sinüzoid 100 saniye boyunca örneklenip bir dizi olarak karşı tarafa gönderilirse örneğin 1000 eleman, her birinin değeriyle birlikte gönderilir. Oysa yalnız frekans ve genlik, yani iki değer gönderilirse alıcı ters dönüşümle her andaki değeri hesaplayabilir. Bir tarafta 1000 değer, diğer tarafta 2 değer gönderilir. Bu sayede özellikle doğrusal sistemlerin bileşenleri ve sinyallerin ayırt edici özellikleri ortaya çıkarılabilir: bir yüzün, bir sesin ayırt edici özelliği nedir, notalar nasıl ayırt edilir, telefon tuşları nasıl tanınır?

### 13.3 Piyano akoru örneği

Bir piyano akoru 3,5 saniye kaydedilmiştir. Zaman grafiği akorun başladığı anı ve sönümünü gösterir, ama dalga biçiminden hangi notaların çalındığını anlamak zordur. Dalga biçimi farklı frekanslardaki sinüzoidlerin toplamı olarak yazılıp her frekanstaki genlik çizilirse grafik çok daha kolay anlaşılır (ekrandan, 02:30:00).

Slayttaki genlik spektrumu −5000 ile 5000 Hz arasında simetriktir; 0–1500 Hz aralığındaki yakın görünümde belirgin tepeler yaklaşık şöyledir (değerler grafikten okunmuştur):

| Frekans (yaklaşık, Hz) | Genlik (yaklaşık) |
|---|---|
| 330 | 38 |
| 400 | 13 |
| 525 | 24 |
| 660 | 11 |
| 780 | 33 |
| 990 | 6 |
| 1050 | 2 |
| 1180 | 3 |
| 1320 | 3 |

Toplam 9 frekans bileşeni vardır; yani sinyalin içinde 9 sinüzoid bulunur. Hoca da tepeleri sayarak 9 bileşen buldu (ilk ikisini yaklaşık 300 ve 400 Hz, genliklerini 38 ve 13 olarak okudu). Telefon tuşlarında her tuş iki frekanstan oluşurken notalarda 9 ile 12 arasında frekans bileşeni görülür. Bu bileşenler sayesinde hangi notanın çalındığı ya da müziğin türü gibi analizler yapılabilir.

Sinüzoidal bileşenler bulunarak doğrusal sistemler kolayca analiz edilir. Örneğin bir arabada frene basılması bir giriştir; arabanın dinamiği diferansiyel denklemlerle tanımlanır ve "frene bastıktan ne kadar sonra araç durur?" sorusunun cevabı sistem analiziyle, özellikle frekans analiziyle bulunur.

> **Ek bilgi (derste anlatılmadı):** Gerçel bir sinyalin genlik spektrumu sıfıra göre simetriktir; bu yüzden slayttaki −5000…5000 Hz grafiğinde her tepe negatif frekansta da görülür. Yakın görünümde yalnız pozitif frekanslar çizilmiştir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:01): Ekranda görülen ses dalgası çizimi gerçek midir?

> **Cevap (derste verildi):** Hayır. Kayıt belli bir örnekleme frekansıyla (örneğin $f_s=1000$ Hz, 10 saniye → 10 000 elemanlı dizi) alınmış ayrık bir dizidir. Ekrandaki süreklilik, örnekler arasını dolduran çizim programının interpolasyonudur; asıl ses yüzde yüz böyle değildir.

**Soru 2** (ekrandan, 00:35:00; derste sözlü, 00:32:20): Zaman eksenindeki örnek sıklığı ve genlik eksenindeki seviye sıklığı değiştirilirse `X d[y];` biçimindeki bir C dizisinde ne değişir?

> **Cevap (derste verildi):** Örnekleme hızı $y$'yi (dizinin eleman sayısını) belirler; örnekleme hızı arttıkça dizi uzar. Genlik seviyelerinin sayısı `X` veri tipini belirler: `int32` ile $2^{32}$, `int64` ile $2^{64}$ seviye. İkisi de arttıkça orijinale daha yakın bir sonuç ve daha küçük nicemleme hatası elde edilir.

**Soru 3** (derste sözlü, 00:36:42): Analog bir sinyali örnekleme kavramlarıyla nasıl tanımlarsınız?

> **Cevap (derste verildi):** Zamanda ve genlikte sonsuz kez örneklenmiş (nicemlenmiş) sinyal analog sinyaldir. Belleği sınırlı hiçbir sayısal sistem bunu gerçekleştiremez.

**Soru 4** (derste sözlü, 00:54:50): CD kalitesindeki ses kaç Hz ile örneklenir?

> **Cevap (derste verildi):** 44 100 Hz. Yarısı olan 22 050 Hz, insan kulağının üst sınırı olan yaklaşık 20 kHz'in üzerindedir; Nyquist kuralı sağlanır.

**Soru 5** (derste sözlü, 01:05:46; slayt ekrandan, 01:15:00): Genliği $-20$ ile $+20$ V arasında değişen 2 kHz'lik bir sinyal 8 seviyeyle nicemleniyor. $\Delta$, örnek başına bit sayısı, 7,8 V'luk örneğin karşılığı ve bir saniyelik kaydın boyutu nedir?

> **Cevap (derste verildi; bölüm 7.3):** $\Delta=40/8=5$ V; $n_b=\log_2 8=3$ bit. 7,8 V, 5–10 V bölgesine düşer, 7,5 V olarak saklanır (kod 101). $f_s=4$ kHz ile bir saniyede 4000 örnek, $4000\times3=12\,000$ bit (1500 bayt).

**Soru 6** (ekrandan, 01:35:00): 12 bitlik bir ADC en anlamsız bit kadar $\pm$ doğruluk vaat ediyor. Giriş aralığı 0–10 V ise doğruluk kaç volttur?

> **Cevap (derste verildi):** $V_{LSB}=10/2^{12}=10/4096\approx0{,}0024$ V; doğruluk $\pm0{,}0024$ V.

**Soru 7** (derste sözlü, 01:35:09): Bir ses 2 kHz, 6 kHz ve 12 kHz'lik bileşenler içeriyor; 60 saniye kaydediliyor ve $-30$ ile $+30$ arasındaki genlik en az 180 seviyeyle nicemleniyor. Sinyalin boyutu nedir?

> **Cevap (derste verildi):** $f_s\ge 2\times12=24$ kHz; örnek sayısı $24\,000\times60=1\,440\,000$; $\lceil\log_2180\rceil=8$ bit = 1 bayt; boyut $1\,440\,000$ bayt $\approx 1{,}44$ MB.

**Soru 8** (derste sözlü, 01:38:05): Yatayda 500, dikeyde 800 pikselden oluşan ve her pikseli 180 farklı renkten birini alan bir görüntü kaç bit tutar?

> **Cevap (derste verildi):** Piksel başına 8 bit; $500\times800\times8=3\,200\,000$ bit $=400\,000$ bayt.

**Soru 9** (derste sözlü, 01:53:04): $7-5$ işlemini 8 bit üzerinde ikiye tümleme yöntemiyle hesaplayınız.

> **Cevap (derste verildi; ara adımlar eklendi, python ile doğrulandı):**
> $7=00000111_2$, $5=00000101_2$.
> $-5$: kısa yolla sağdan ilk 1'e kadar aynen yazılır, gerisi ters çevrilir: $11111011_2$.
> $00000111+11111011=1\,00000010$. 8 biti aşan elde atılır; sonuç $00000010_2=2$.

**Soru 10** (derste sözlü, 02:01:11): Yalnız rakamlar kullanılarak üç basamaklı kaç sayı yazılabilir?

> **Cevap (derste verildi):** İlk basamak 0 olamayacağından 9, diğer iki basamak 10'ar seçenek: $9\times10\times10=900$.

**Soru 11** (ekrandan, 02:00:00): Ondalık rakamları ikili kodla temsil etmek için kaç bit gerekir?

> **Cevap (derste verildi):** 10 eleman için $\lceil\log_2 10\rceil=4$ bit.

**Soru 12** (derste sözlü, 02:10:31): $+20$ ile $-20$ arası 20 parçaya bölündüğünde $-3{,}8$ hangi bölgeye düşer ve bit karşılığı nedir?

> **Çözüm (derste verilmedi):** Bölgeler en alttan 0 numarayla başlayarak kodlanırsa: $\Delta=40/20=2$; bölge numarası $\lfloor(-3{,}8+20)/2\rfloor=\lfloor8{,}1\rfloor=8$, yani $-4$ ile $-2$ arasındaki bölge; orta noktası $-3$. 20 bölge için $\lceil\log_2 20\rceil=5$ bit gerekir; kod $01000$. (Bölge numaralandırma biçimi derste belirtilmedi; bu bir varsayımdır. Python ile doğrulandı.)

## Dersin Toparlaması

Bu derste bir fiziksel büyüklüğün bilgisayarda saklanıp işlenmesinin tam yolu izlendi: transdüserle elektrik işaretine çevirme, analog katlarda güçlendirme ve temizleme, ADC'de filtreleme, örnekleme, nicemleme ve kodlama; ardından bellekte saklama, algoritmayla işleme ve DAC ile dış dünyaya geri verme. Örneklemede $f_s\ge2f_{max}$ (Nyquist) kuralı, nicemlemede $\Delta=(\max-\min)/L$ ve $n_b=\lceil\log_2L\rceil$ ilişkileri ile nicemleme hatası ve bit hızı arasındaki ödünleşim öne çıktı. Bu ilişkilerle bir ses ya da görüntünün bellekte kaplayacağı alanın nasıl hesaplanacağı örneklerle gösterildi. Ardından bitten kayan noktalı sayılara ve ASCII'ye kadar sayısal veri temsili hızlıca tekrar edildi.

Dersin son kısmında sinyal ve sistem kavramlarına geçildi: sistem, giriş sinyalini çıkış sinyaline dönüştüren her şeydir ve çoğu zaman diferansiyel denklemlerle tanımlanır. Zaman domeninde görülemeyen frekans bilgisinin önemi piyano akoru örneğiyle gösterildi. Bir sonraki derste frekans domenine nasıl geçileceği, frekans domeninde nasıl analiz yapılacağı ve diferansiyel denklemlerle tanımlanan sistemlerin davranışının nasıl çözüleceği konularıyla devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
