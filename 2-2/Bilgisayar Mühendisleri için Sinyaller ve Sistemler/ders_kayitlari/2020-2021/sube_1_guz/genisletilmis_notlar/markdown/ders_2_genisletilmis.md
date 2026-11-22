# Ders 2 Genişletilmiş Notu: Örnekleme, Nicemleme ve Sayısal Veri Temsili

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kaynak kitaplar ve dersin çıkış noktası
- 2. Sinüzoidal işaretler, frekans ve periyot
- 3. DC ve AC işaretler
- 4. Fourier analizi ve işaretin frekans bileşenleri
- 5. Örnekleme ve Nyquist teoremi
- 6. Nicemleme ve kodlama
- 7. Bilgi, veri ve sistem kavramları (slaytlar)
- 8. Analogdan sayısala dönüşüm zinciri (slaytlar)
- 9. Sayısal veri temsili
- 10. Örnek Sorular
- Dersin Toparlaması

## 1. Kaynak kitaplar ve dersin çıkış noktası

Dersin ana kitabı McClellan, Schafer ve Yoder'in *Signal Processing First* kitabıdır; derste kullanılan slaytlar da büyük ölçüde bu kitabın slaytlarına dayanır (ekrandan, 00:05:00). Yardımcı kaynak olarak Mark Wickert'in *Signals and Systems for Dummies* (John Wiley & Sons, 2013) ve Oppenheim, Willsky ve Nawab'ın *Signals and Systems* (2. baskı, Prentice Hall, 1997) kitapları slaytta gösterildi. Hoca ayrıca Sarp Ertürk'ün *Sayısal İşaret İşleme* kitabını, ileride Sayısal İşaret İşleme dersini alacaklar için önerdi. <!-- BELİRSİZ: Altyazıda "Richard Brinick'un kitabı" olarak geçen kaynağın yazarı karelerde görünmüyor; ad doğrulanamadı. --> Uygulamalar için MATLAB (üniversite e-postasıyla MATLAB Online kullanılabilir) ve Python kullanılacağı söylendi.

Dersin çıkış noktası şuydu: Gerçek dünyadaki bilgi taşıyan bir işaret, örneğin $x(t)$, süreklidir (analog). Zamanın her anında tanımlıdır; hoca "sonsuz sayıda noktadan oluşur" demenin bile tam doğru olmadığını, işaretin sürekli zamanın her anında bir değeri olduğunu vurguladı. Amaç bu işareti bilgisayarda işlenebilir hale getirmektir. Bilgisayar burada mikrodenetleyici ya da mikroişlemci içeren, hesaplama yapabilen bir birimdir ve yanında **sınırlı** bir hafıza vardır (ekrandan, 00:20:00). İşaretler bir boyutlu, iki boyutlu, üç boyutlu ya da genel olarak $n$ boyutlu olabilir.

Bu kısıt altında ilk adım **örneklemedir** (sampling): zamanın her anında tanımlı işaretten belli aralıklarla örnekler alıp bunları hafıza gözlerine yerleştirmek. İki örnek arasındaki süre **örnekleme periyodu** $T_s$'dir (sampling period). $T_s$ istenildiği kadar küçültülebilir, ama her örnek bir hafıza gözü harcar. $T_s$ çok büyük seçilirse de iki örnek arasında kalan önemli değişimler kaçırılır. Bu yüzden aranan şey şudur: işaretin bilgi taşıyan kısımlarını kaybetmeden $T_s$'yi mümkün olan en geniş haliyle seçmek. Bunun hesabı için Fourier analizine ihtiyaç vardır.

## 2. Sinüzoidal işaretler, frekans ve periyot

Fourier analizine geçmeden önce hoca sinüzoidal işareti tanımladı (ekrandan, 00:15:00):

$$x(t) = A \sin(\omega t + \varphi)$$

- $A$: genlik. İşaret $A$ ile $-A$ arasında salınır.
- $T$: periyot. Bir çevrimin tamamlanması için geçen süre.
- $\varphi$: faz. İşaretin başlangıç durumunu, yani zaman ekseninde ne kadar kaydığını gösterir.
- $\omega = 2\pi f$: açısal frekans (ekrandan, 00:20:00).

Faz 90 derece olduğunda elde edilen fonksiyona kosinüs denir; yani sinüs ile kosinüs aslında aynı fonksiyondur, aralarında yalnız faz farkı vardır.

Frekans periyodun tersidir: $T = 1/f$. Frekans, işaretin birim zamanda (bir saniyede) kaç çevrim tamamladığını gösterir ve birimi Hz'dir. 100 Hz'lik bir işaret bir saniyede 100 kez başlayıp biten bir çevrim yapar. Periyot küçüldükçe frekans büyür; yüksek frekanslı işaretler birim zamanda daha çok salınım yapan işaretlerdir.

## 3. DC ve AC işaretler

Frekansı sıfır olan, yani hiç salınım yapmayan işarete **DC** (Direct Current) işaret denir. Zamanla değişmez; örneğin sabit 5 V. Hoca sohbet ekranından sabit gerilim kaynaklarına örnek istedi; pil (1,5 V) ve adaptör cevapları doğru kabul edildi.

Artı ve eksi arasında değişerek salınım yapan işarete **AC** işaret (alternatif akım) denir; sinüzoidal dalga bunun tipik örneğidir. Bu adlar, işaretlerin elektrik telleri üzerinden akım olarak iletilmesinden gelir.

Hoca mühendislerin bilmesi gereken bir örnek olarak şehir şebekesini verdi: duvardaki prizden alınan güç işareti sinüzoidal bir AC işarettir, frekansı 50 Hz'dir, yani saniyede 50 çevrim tamamlar. 110 V kullanılan yerlerde frekans 60 Hz'dir.

> **Ders sonrası not:** Hoca şebeke işaretinin +220 V ile −220 V arasında salındığını söyledi. 220 V şebekenin etkin (RMS) değeridir; tepe genliği yaklaşık $220\sqrt{2} \approx 311$ V'tur.

> **Ek bilgi (derste anlatılmadı):** "AC" kısaltması İngilizcede *alternating current* (alternatif akım) anlamına gelir; altyazıda geçen "alternative" ifadesi büyük olasılıkla bu terimin söylenişidir.

## 4. Fourier analizi ve işaretin frekans bileşenleri

1800'lü yıllarda yaşamış matematikçi Fourier'nin yaklaşımına göre herhangi bir işaret (o dönem için matematiksel bir fonksiyon), kendini oluşturan sonsuz sayıda sinüzoidalin toplamı olarak yazılabilir. Hoca bunu tahtada şöyle gösterdi (ekrandan, 00:20:00): en üstte $f = 0$ olan DC bileşen, altında $f = 1$ Hz'lik bir sinüs, daha aşağıda frekansı giderek artan sinüsler. Aşağı indikçe frekans artar. Frekans sürekli bir değişken olduğu için arada da sonsuz sayıda bileşen vardır (0,5 Hz, 0,625 Hz gibi).

Her bileşenin işarete katkısı farklıdır: bir frekans $B$ genliğinde, bir başkası $C$ genliğinde bulunabilir; genliği sıfır olan bir frekans işarete hiç katılmaz. Bütün bileşenler toplandığında işaretin kendisi elde edilir.

Pratikte bir işaretin sonsuz sayıda frekans bileşeni olmaz. İşaret bir kaynaktan üretilir ve bu kaynağın belli bir bant genişliği vardır. Hocanın örneği kendi sesiydi: sınıf ortamında konuşurken havadaki titreşimler süreklidir ve bir insanın üretebileceği en yüksek frekans ortalama 4000 Hz (4 kHz) civarındadır; kimi 4500, kimi 5000 Hz'e çıkabilir (ekrandan, 00:30:00). Seslerimizi birbirinden ayıran da ses tellerinin farklı frekanslarda titreşebilmesidir; özellikle tiz frekanslardaki farklar konuşma karakteristiğini belirler.

**Soru:** Kaynak belli frekanslar ürettiğine göre, çizdiğimiz frekans fonksiyonunun da ayrık olması gerekmez mi? **Cevap:** Hayır. $f_{max}$, kaynağın ürettiği en yüksek frekanslı sinüzoidaldir; ondan sonra genlik yoktur. Ama 0 ile $f_{max}$ arasında sonsuz sayıda frekans vardır; frekanslar $f_1, f_2, \dots$ diye ayrık gitmez. Bu yüzden toplam bir $\sum$ ile değil, integral ile yazılır. Hoca bunu kabaca $x(t)$'nin $0$ ile $f_{max}$ arasındaki frekanslarda, her biri $A_f$ genliğinde sinüzoidallerden oluştuğu biçiminde gösterdi; Fourier dönüşümüne ileride gelinecek. <!-- BELİRSİZ: Tahtada yazılan integral ifadesinin tam biçimi karelerde görünmüyor. -->

**Soru:** Periyodik ve düzenli sinüs dalgalarının toplamıyla periyodik olmayan, düzensiz bir işaret nasıl elde ediliyor? **Cevap:** Fourier analizi bunu söyler. Bileşenler toplandığında bazı yerlerde birbirlerini söndürür, bazı yerlerde güçlendirir. Belli bir sabit aralıkta herhangi bir işaret sinüzoidal bileşenlerine ayrılabilir; aralık sonsuza gittikçe bunun sağlanması zorlaşır.

## 5. Örnekleme ve Nyquist teoremi

### 5.1 En kötü durum: en yüksek frekansın tepe noktaları

Bir işaretin en yüksek frekanslı bileşenine $f_{max}$ diyelim. Hocanın yaklaşımı şuydu: Bu bileşenin bir periyodunda yalnız tepe ve çukur noktalarını alacak sıklıkta örnekleme yapılırsa ne olur?

- En yüksek frekanslı (en hızlı salınan) bileşende bir periyotta yalnız iki örnek alınır: biri tepede, biri çukurda. Bu en kötü durumdur.
- Daha düşük frekanslı bileşenlerde aynı $T_s$ ile bir periyotta çok daha fazla örnek alınır. Dolayısıyla alt frekanslar için sorun yoktur; sorun yalnız $f_{max}$'tadır.

En yüksek frekanslı bileşenin periyodu $T_{max} = 1/f_{max}$'tır (ekrandan, 00:40:00). Yalnız tepe noktaları alındığında iki örnek arası $T_s$ olur ve şekilden açıkça görüldüğü gibi:

$$T_{max} = 2T_s$$

Bu ilişkiyi hoca öğrencilere sordu; doğru cevap sohbetten geldi. Frekans cinsinden ($f_s = 1/T_s$):

$$f_s = 2 f_{max}$$

Bu, işareti örneklemek için işaretin içindeki en yüksek frekansın iki katı kadar sıklıkla örnek almak gerektiği anlamına gelir.

### 5.2 Daha sık örnekleme ve eşitsizliğe geçiş

Tepe noktalarının yanında aradaki sıfır geçişleri de alınırsa örnekler sıklaşır. Yeni örnekleme periyodu $T_{s,new}$ ile $T_{max} = 4T_s$ ve $f_s = 4f_{max}$ olur (ekrandan, 00:35:00). Hafıza yetiyorsa $8T_s$, $16T_s$ diye daha da sıklaştırılabilir. Tepe noktalarının alındığı durum en kötü durum olduğu için eşitlik bir alt sınıra dönüşür:

$$f_s \geq 2 f_{max} \qquad \text{(Nyquist teoremi)}$$

Nyquist teoremi şunu söyler: Bir işareti örnekleyecekseniz, örnekleme frekansınız işaretin içindeki en yüksek frekansın **en az** iki katı olmak zorundadır.

### 5.3 Sayısal örnek: ses işareti

(ekrandan, 00:40:00)

- **Verilen:** Konuşma sesinin en yüksek frekansı $f_{max} = 4$ kHz.
- **Soru:** Bu sesi mikrofonla örnekleyip kaydetmek için en az kaç Hz gerekir?
- **İşlem:** $f_s \geq 2 \times 4\ \text{kHz} = 8\ \text{kHz}$.
- **Örnekleme periyodu:** $T_s = 1/f_s = 1/8000\ \text{s} = 125\ \mu s$. Burada $\mu = 10^{-6}$, yani saniyenin milyonda biri.
- **Sonuç:** Sesi en az 125 µs'de bir örneklemek, onu yeterli kalitede kaydetmek için gereken en seyrek örneklemedir.

> **Ders sonrası not:** Altyazıda bir yerde "125 ms" geçiyor; tahtada yazan ve doğru olan değer 125 µs'dir ($1/8000$ s).

Ardından aralık daraltıldı:

- **Verilen:** $T_s = 62{,}5\ \mu s$.
- **İşlem:** $f_s = 1/(62{,}5 \times 10^{-6}) = 16\,000$ Hz.
- **Sonuç:** $f_s = 16$ kHz $= 4 \times 4$ kHz. Bu sefer $f_{max}$ iki ile değil dört ile çarpılmış olur; daha iyi bir örnekleme yapılır ve örneklerin genlikleri orijinal işarete daha çok yaklaşır.

Hoca örnekleri çubuk şeklinde çizse de aslında saklanan şeyin her örneğin genlik değeri olduğunu hatırlattı.

### 5.4 $f_s$ ve $f_{max}$'ın rolü

**Soru:** $f_{max}$'ı seçerken neye bakıyoruz? **Cevap:** $f_{max}$ işaretin içindeki en yüksek frekanslı bileşendir; ondan sonraki frekansların genliği yoktur, yani kaynak daha yüksek bir frekans üretmez.

**Soru:** Hafızayı bilmeden mi $f_s$'yi artırıp azaltıyoruz? **Cevap:** $f_s$ hafızadan bağımsız olarak, saklanmak istenen işaretin maksimum frekansıyla belirlenir. $f_{max}$'ı biz seçmeyiz; işaret kaynağının doğası belirler. $f_s = 2f_{max}$ seçmek $T_s$'yi en büyük yapar, yani örnekler arasını olabildiğince açar (4 kHz için 8 kHz ve 125 µs). $f_s$ artırıldıkça işaret daha sık örneklenir, $T_s$ daralır. Hafıza miktarı ise saklanacak örneklere göre belirlenir.

Hocanın ikinci örneği bir kalp işaretiydi: içindeki en yüksek frekans 360 Hz ise, değişimleri kaçırmamak için örnekleme frekansı en az 720 Hz olmalıdır. Ama 2000 Hz de seçilebilir; daha sık örneklemek orijinal işarete daha çok yaklaşmak demektir.

MP3 dosyaları da bunun günlük hayattaki örneğidir. Bir müzik parçası 8, 16, 32 ya da 64 kHz ile örneklenebilir. 64 kHz ile oluşturulan dosya (kulak ayırt edebiliyorsa) daha kalitelidir; 8 kHz'in tam 8 katı örnek içerir. Ne kadar çok örnek alınırsa işarete sadakat o kadar artar ama dosya boyutu, yani hafıza ihtiyacı da büyür. Buradaki hafıza RAM, ROM ya da sabit disk olabilir; önemli olan örneklerin bir yerde saklanmasıdır.

> **Hocanın vurgusu:** Varmak istenen yer Nyquist teoremidir: $f_s \geq 2f_{max}$.

### 5.5 Ayrık işaret gösterimi

Örnekleme sonucunda sürekli $t$ değişkeni bir $n$ indisine dönüşür: birinci örnek, ikinci örnek, üçüncü örnek... İşaret artık ayrık (discrete) bir işarettir ve $x[n]$ ile gösterilir (ekrandan, 00:50:00 ve 01:00:00). Ayrık işaretler, ayrıklaştırılmış oldukları belli olsun diye çubuklar (stem) şeklinde çizilir; çubuklar arası $T_s$ kadardır.

> **Hocanın vurgusu:** Sürekli işaret normal parantezle, $x(t)$; ayrık işaret köşeli parantezle, $x[n]$ yazılır. İçerideki $t$ sürekli bir değişken, $n$ ise bir indistir.

## 6. Nicemleme ve kodlama

### 6.1 Örneklenmiş işaret doğrudan hafızaya atılabilir mi?

Hoca bu soruyu birkaç kez sordu: İşaret ayrıklaştırıldıktan sonra örnekleri hafıza gözlerine yazmanın önünde bir engel kalır mı? Bir öğrenci, örnekleme aralığını bilmemenin ya da hafızanın yetmemesinin sorun olup olmayacağını sordu. Hocanın cevabı şuydu: Grafiği bir y ekseni, bir x ekseni olarak düşünürsek, örnekleme yalnız **x eksenini** (zamanı) belli aralıklarla ayrıklaştırdı. Y ekseni (genlik) ayrıklaştırılmadı. Bir örneğin genliği 3,5 olabilir, bir sonraki 3,758923… diye sonsuz hassasiyette gidebilir (ekrandan, 00:50:00). Nasıl x'in alabileceği değerler sonsuzsa, y'nin alabileceği değerler de sonsuzdur.

Hafıza ise bitlerden oluşur. 8 bit bir byte'tır; hafızanın bir gözünün kelime uzunluğu (word length) önemlidir. int, long int, float gibi tipler 8, 16, 32 ya da 64 bitlik alanlara karşılık gelir (ekrandan, 00:55:00). Demek ki hafıza bu yönden de sınırlıdır: bir göze konabilecek farklı değer sayısı bellidir.

### 6.2 Bit sayısı ve seviyeler

- 1 bitlik bir göze yalnız iki değer yazılabilir: 0 ya da 1. Bu durumda genlik ekseni yalnız artı ve eksi diye ikiye ayrılabilir.
- 2 bit ile dört kod vardır: 00, 01, 10, 11. Hoca bunları tahtada eksenin dört bölgesine atadı (ekrandan, 01:00:00): üstteki iki bölge 01 ve 00, alttaki iki bölge 10 ve 11. Bir örnek hangi aralığa düşerse o kodla saklanır.
- Bu kaba bölmede büyük bir hata vardır: aynı aralığa düşen ama aralarında ciddi fark olan iki örnek aynı kodla saklanır.
- Bit sayısı 3'e çıkarılırsa bölge sayısı sekize çıkar. Her ek bit, her aralığı ikiye böler; önceden aynı aralıkta kalan yakın değerler artık ayrışabilir.

Genel olarak $b$ bit ile $2^b$ seviye elde edilir. Kelime uzunluğu ne kadar büyükse genlik ekseni o kadar dar aralıklara bölünür.

### 6.3 Nicemleme (quantization)

Y ekseninin ayrık hale getirilmesine **nicemleme** (quantization) denir (ekrandan, 00:55:00). Hoca "kuanta" kavramını atom modeline benzetti: elektronlar atomun etrafında belli enerji seviyelerinde bulunur, aralarında bir ayrıklık vardır. Burada da genlik ekseni belli seviyelere bölünür.

Hocanın örneği (ekrandan, 00:55:00 ve 01:00:00): 3,7 ile 3,8 arasına düşen bütün örnekler bu aralığın ortası olan **3,75** ile, 3,8 ile 3,9 arasındakiler **3,85** ile saklanır. Her seviyeye bir ikili kod karşılık gelir ve bir üst seviyeye çıkıldığında kodun değeri bir artar. <!-- BELİRSİZ: Tahtada 3,75 için yazılan ikili kodun tam bit dizisi karelerde net okunmuyor ("0110001…"); kod örnek amaçlıdır. -->

**Soru:** Örnek iki seviyenin arasına düşerse en yakın seviyeye mi yuvarlanır? Örneğin 3,84 gelirse 3,75 mi olur? **Cevap:** Hayır. 3,84, 3,8'in üstünde olduğu için bir üstteki kuanta aralığına düşer ve o aralığın ortalaması olan 3,85 ile saklanır. Örnek hangi kuanta aralığına düşüyorsa o aralığın ortalama değerine gönderilir.

### 6.4 Nicemleme hatası

Aynı aralığa düşen iki farklı örnek $x_1$ ve $x_2$, aynı $A$ değeriyle (aynı ikili kodla) saklanır. Hata, gerçek değerlerle saklanan değer arasındaki farkların mutlak değerlerinin toplamı olarak düşünülebilir:

$$e = |x_1 - A| + |x_2 - A| + \dots$$

Mutlak değer kullanılır, çünkü farklar negatif de çıkabilir. Hocanın sayısal örneğinde 3,84 değeri 3,85'e gönderildiğinde 0,01, 3,73 değeri 3,75'e gönderildiğinde 0,02 hata oluşur; bunların toplamı hata fonksiyonunu verir. Bit sayısı artırıldıkça kuanta aralıkları bölünür; 3,73 ile 3,71 gibi değerler artık birbirinden ayrılabilir ve hata azalır. Bedeli ise hafızadır: bit sayısını artırmak kapasiteyi artırmak demektir.

**Soru:** Genlik ekseni ayrıklaştırılırken oluşan hata payını hesaplamamızı sağlayacak bir yöntem var mı? **Cevap:** Bütün işaret için bu yapılamaz. Hata bit sayısına bağlıdır: bit sayısı arttıkça hata oranı düşer ama kapasiteyi artırmak gerekir.

### 6.5 Yaklaşıklık

Örnekleme ve nicemleme yapıldığında ister istemez belli bir hata göze alınır. Örnekler arasındaki değerler bilinmez; elde yalnız örnek noktaları vardır ve bunlar birleştirilirken orijinal işaretteki gibi düzgün bir eğri elde edilemez, noktalar düz çizgilerle birleştirilir. Ne zaman (x) yönünde ne de genlik (y) yönünde orijinal işaret birebir geri elde edilebilir. Hafızaya konan şey işaretin bir yaklaşığıdır; hoca bunu $\tilde{x}[n]$ gibi bir gösterimle belirtti. Bir ses işaretinde bu yaklaşıklık çoğu zaman fark edilmez. Önemli olan $T_s$'nin ve kuanta aralığının işareti inceleyebilecek kadar küçük olmasıdır.

### 6.6 Kodlama ve bütün zincir

Son adımda nicemlenmiş her seviyeye karşılık gelen ikili değer hafıza gözlerine yazılır. Böylece tamamen analog, sürekli bir dünyadan önce x ve y yönünde ayrık hale gelinmiş, en son 0 ve 1'lerle ifade edilen ikili forma geçilmiş olur.

```text
x(t) (sürekli)
  -> örnekleme   : zaman ekseni ayrıklaşır, x[n]
  -> nicemleme   : genlik ekseni seviyelere bölünür
  -> kodlama     : her seviye ikili koda çevrilir
  -> hafıza      : bitler kelime uzunluğundaki gözlere yazılır
```

## 7. Bilgi, veri ve sistem kavramları (slaytlar)

Aradan sonra hoca "Information Systems: Fundamentals" başlıklı ilk sunuma geçti (ekrandan, 01:15:00). İşaretler bir bilgi (enformasyon) kaynağıdır: ses işareti, kalp işareti gibi.

### 7.1 İşaretin boyutu

Zamana bağlı $x(t)$ bir boyutlu (1D) bir işarettir. Gri seviye bir görüntü ise iki uzamsal (spatial) koordinata bağlı bir fonksiyondur: $x(u, v)$ (ekrandan, 01:20:00). Analog siyah beyaz fotoğrafta mercekten geçen ışığın parlaklık seviyeleri filmin üzerine kimyasal olarak kaydedilir.

**Soru:** Resim üç boyutlu değil mi? **Cevap:** Renkli resim RGB katmanlarından oluşur; her biri iki boyutlu üç katman düşünüldüğünde üç boyutlu olur. Bu yüzden iki boyut örneği için özellikle gri seviye resim seçildi. Ayrıca RGB katmanları da aslında ayrık katmanlardır: yaklaşık 400–500 nm dalga boyu mavi, 500–600 nm yeşil, 600–700 nm kırmızı bant olarak alınır. Bu da bir tür nicemlemedir; bu yüzden resimler tam anlamıyla analog sayılmaz.

MR kesitleri de bir örnektir: hasta taranırken her taramadan iki boyutlu bir görüntü elde edilir, kesitler arasında da bir ayrıklaştırma vardır. Ders boyunca genellikle bir boyutlu işaretler anlatılacak; sonuçlar $n$ boyuta genelleştirilebilir.

### 7.2 Enformasyon ve veri

Enformasyon, bir bilginin oluşturulması, saklanması, bulunması, üzerinde işlem yapılması ve dağıtılmasıyla ilgili bütün eylemleri kapsar. Slaytta "informatik" teriminin kökeninden ve farklı bilim dallarıyla ilişkisinden söz edildi; hoca bu kısmı hızla geçti.

> **Ek bilgi (derste anlatılmadı):** Altyazıda "Karl Schenbach" olarak geçen ad büyük olasılıkla, Almanca "Informatik" terimini 1957'de kullanan Karl Steinbuch'tur.

Yapılandırılmamış (unstructured) veriden, belli bir amaca ulaşmak için bilgi çıkarılır. Hocanın örneği kalp işaretiydi: problardan çok sayıda veri gelir; bu veriden QRS kompleksi ve atımlar çıkarılarak enformasyon elde edilir. Bir adım sonra, sağlıklı bir insanda belli tepe noktaları arasındaki oranların ve eğimlerin belli aralıklarda olması gerektiği bilgisi kullanılarak hastalık tespiti yapılabilir. Slayta göre veri toplamak pahalıdır; neden gerektiği ve nasıl kullanılacağı açık olmalıdır, veriler performansı gerçekten etkileyen göstergeler üzerinden, güvenilir ve düzenli toplanmalı ve gereken bilgiye dönüştürülebilmelidir (ekrandan, 01:25:00).

### 7.3 Sistem

Sistem, belirli bir amaca ya da ortak bir sonuca ulaşmak için bir araya getirilmiş, birlikte çalışan bileşenlerin kümesidir. Sistemler girişler, yapılan işlemler ve çıkışlar ile tanımlanır; bir sistem modelinde ayrıca geri besleme (feedback) bulunur ve girişler bu geri beslemeyle ayarlanarak süreç iyileştirilir.

Hoca İşaretler ve Sistemler dersinin Sayısal İşaret İşleme, Görüntü İşleme, Makine Öğrenmesi ve Örüntü Tanıma derslerine doğru genişlediğini söyledi. Bu yapıda analog dünyadan sayısal dünyaya geçiren bir donanım, bu donanım üzerinde koşan bir yazılım, bunları yazan insanlar ve verinin saklanıp işlenmesi vardır. İşaret ise fiziksel bir büyüklüğü temsil eden bir enformasyon değişkeni olarak tanımlandı.

## 8. Analogdan sayısala dönüşüm zinciri (slaytlar)

### 8.1 Tipik ölçüm sistemi

Slayttaki tipik ölçüm sisteminde fiziksel bir işaret (örneğin ses) bir algılayıcıyla alınır, analog olarak yükseltilir, analog işaret işleme ile gürültü giderme ya da kazanç gibi işlemler yapılır. Ardından analogdan sayısala çevirici (ADC) örnekleme ve nicemleme yapar, işaretler hafızada saklanır, işaret işleme algoritmaları çalışır ve sonuçlar verilir. Sayısal işaretlerin işlenmesi analog işaretlere göre daha kolaydır: ikili forma getirilebilir, hata denetimi kolaydır, genlikler üzerinde işlem yapmak kolaydır.

### 8.2 Tutma ve saat işareti

Slayta göre sürekli analog işaret örneklenmeden önce tutulmalıdır (ekrandan, 01:30:00): işaret bir saat işaretine göre ölçülür, her saat darbesinde önce tutulur, sonra örneklenir. Aksi halde işaret ölçüm sırasında değişirdi; ancak tutulduktan sonra ölçülüp sayısal değere çevrilebilir. Örnekleme anları için genellikle bir saat darbesi kullanılır ve örnekler bu darbelerin yükselen kenarlarında tetiklenerek alınır. Sonuçta $x[n]$ işareti elde edilir.

Slaytta gösterilen zincir: filtreleme (gürültü giderme), örnekleme, nicemleme ve ikili kodlama (binary encoding). Hoca bunu "örnekleme (Nyquist), nicemleme ve kodlama" diye üç ana kısma ayırdı: örnekleme x (zaman) yönünde, nicemleme y (genlik) yönünde ayrıklaştırma yapar; kodlama ise ayrışmış genlikleri hafızaya yazılabilecek ikili dizilere çevirir.

### 8.3 Örneklerin birleştirilmesi

Yalnız örnek noktaları bilindiği için bir örnekten sonrakine ya düz çizgiyle geçilir, ya matematiksel eğrilerle doğal bir birleştirme yapılır, ya da alınan değer bir sonraki örneğe kadar tutulur. Değerin bir sonraki örneğe kadar tutulduğu örneklere düz tepeli (flat-top) örnekler denir; slaytta bir de doğal örnekleme (natural sampling) gösterildi. <!-- BELİRSİZ: Doğal örnekleme ile düz tepeli örneklemenin slayttaki tanımları ilgili karede görünmüyor. -->

### 8.4 Örnekleme türleri

Slayttaki karşılaştırma (ekrandan, 01:35:00):

- $f_s = 2f_{max}$: yalnız tepeler korunur; işaret tepelerden oluşan bir şekle dönüşür ama özü (en azından üçgen bir yapı olarak) korunur.
- Aşırı örnekleme (oversampling), $f_s > 2f_{max}$: ara değerler de alınır.
- Eksik örnekleme (undersampling), örneğin $f_s = f_{max}$: her çevrimde yalnız bir örnek alınır; örnekler orijinal sinüsten tamamen farklı, çok daha yavaş bir işaret çizer ve işaretin özü kaybolur.

Slaytta ayrıca ölçümün yalnız belli bir süre boyunca yapıldığı (bu yüzden yavaş değişimlerin kaçabileceği), yalnız belli bir hassasiyette yapıldığı (küçük değişimlerin kaçabileceği) ve saatte küçük hatalar olabileceği belirtildi (ekrandan, 01:35:00).

> **Ek bilgi (derste anlatılmadı):** Eksik örneklemede yüksek frekanslı bir bileşenin örnekleri daha düşük frekanslı bir işaretin örnekleriyle aynı çıkar; bu olaya örtüşme (aliasing) denir.

### 8.5 Alçak geçiren ve bant geçiren işaretler

Alçak geçiren (low pass) işaretin frekansları sıfırdan başlayıp $f_{max}$'a kadar gider. Bant geçiren (band pass) işaret ise belli bir minimum ve maksimum frekans arasındadır; düşük frekanslar yoktur. Hoca her iki durumda da Nyquist oranının en yüksek frekansın iki katı olduğunu söyledi, çünkü bütün akıl yürütme en yüksek frekansa göre yapılmıştı.

### 8.6 Kuanta aralığı $\Delta$

Nicemlemede her kuanta aralığının genişliğine $\Delta$ denir. Bir $\Delta$ aralığına düşen örneğin yeni değeri o aralığın ortasıdır. Kodlama kelimesinin uzunluğu kuanta sayısını belirler: 1 bit ile iki, 2 bit ile dört, 3 bit ile sekiz bölge oluşur. Bit sayısının artması $\Delta$'nın küçülmesi ve hatanın azalması demektir.

## 9. Sayısal veri temsili

### 9.1 Bit, nibble, byte, word

- **Bit:** Elektronik olarak (transistörlerle) 0 ya da 1 saklayabilen en küçük birim.
- **Nibble:** 4 bit.
- **Byte:** 8 bit; yüksek dörtlü (higher nibble) ve alçak dörtlü (lower nibble) olmak üzere iki nibble'dan oluşur.
- **Word:** Slaytta 16 bit denmiş, ama bu sisteme bağlıdır; 32 bit de olabilir. 2 byte'lık integer'lar olduğu gibi 4 byte'lık integer'lar da vardır.

### 9.2 Ön ekler, Hertz ve saat

Günlük ölçülerde kilo $10^3$, mega $10^6$, giga $10^9$, tera $10^{12}$ ile çarpmak demektir. Bilgisayarda ise ikili mantık nedeniyle 1 kilo $2^{10}$, 1 mega $2^{20}$ ile çarpılır: 1 KB $= 2^{10} = 1024$ byte, 1 MB $= 2^{20} = 1\,048\,576$ byte (ekrandan, 01:40:00). Slayta göre işlemci hızları MHz ya da GHz ile, ana hafıza MB ile, disk kapasitesi küçük sistemlerde GB, büyük sistemlerde TB ile ölçülür. Zaman tarafında 1 ms saniyenin binde biri, 1 µs milyonda biri, 1 ns milyarda biridir; uzunlukta milimetre, mikrometre, nanometre, pikometre diye gider.

Hertz, saniyedeki saat çevrimi (clock cycles per second) olarak tanımlanır; 1 MHz $= 1\,000\,000$ Hz. Saat işareti sinüs değil kare dalgadır. Bilgisayarda saat kavramı önemlidir, çünkü işlemler saat darbelerinin yükselen kenarında (sisteme göre düşen kenarında ya da yüksek/alçak seviyesinde) yapılır; saat, bilgisayarın senkron çalışması için tetikleme darbeleri üretir.

### 9.3 Veri tipleri

Hafızaya yazılan ikili değerlerin anlamlandırılması için bir organizasyon gerekir. Örneğin bir ses dosyasında hafızanın hangi bölgesinin genliklere karşılık geldiği bilinmelidir; dosyanın başında MP3 mi ham (raw) ses mi olduğunu söyleyen bir başlık (header) bulunur. Buna kabaca veri tipi denir. Hafızada sayılar, metinler, görüntüler, ses, mantıksal değerler (true/false) ve komutlar (instruction) tutulabilir.

### 9.4 Bit sayısı ve temsil edilebilen değerler

Her eklenen bit temsil edilebilen durum sayısını iki katına çıkarır: 1 bit ile $2^1 = 2$ durum (0, 1), 2 bit ile $2^2 = 4$ durum (00, 01, 10, 11; yani 0, 1, 2, 3) (ekrandan, 01:45:00). Bu kodlar bir durumu da bir sayıyı da gösterebilir.

8 bit ile $2^8 = 256$ durum vardır; işaret biti kullanılmazsa 0 ile 255 arasındaki sayılar temsil edilir. 257 gibi bir sayı için 16 bit, onu da aşan sayılar için 32 bit gerekir.

Ondalık sistemde bir sayının basamak değerleri slaytta şöyle gösterildi (ekrandan, 01:45:00):

$$3546 = 3 \times 10^3 + 5 \times 10^2 + 4 \times 10^1 + 6 \times 10^0$$

### 9.5 İşaret biti gösterimi ve sorunu

Negatif sayılar için bitlerden biri işarete ayrılır: genellikle 0 pozitif, 1 negatif demektir. 8 bitin biri işaret olunca 7 bit kalır ve aralık −128 ile +127 arasına gelir: −128 ile −1 arasında 128, 0 ile 127 arasında 128 sayı, toplam 256 sayı.

Ama baştaki biti yalnız işaret olarak kullanmanın bir kaybı vardır (ekrandan, 01:55:00): $0\,0000000$ "+0", $1\,0000000$ ise "−0" olur. Aynı değer (sıfır) için iki ayrı kod harcanmış olur.

### 9.6 İkinin tümleyeni

İkinin tümleyeni (two's complement) gösteriminde sayılar bir çember üzerinde düşünülür (ekrandan, 01:50:00 ve 01:55:00): $0000\,0000$'dan başlayıp $0000\,0001$, … diye artarak $0111\,1111$'e (+127) gelinir; bir sonraki kod $1000\,0000$'dır ve −128'i gösterir. Çember $1111\,1111$ (−1) ile tamamlanıp yeniden $0000\,0000$'a döner.

Okuma kuralı:

- Sayı 0 ile başlıyorsa geri kalan bitler basamak değerleriyle aynen okunur. $0111\,1111 = 2^0 + 2^1 + \dots + 2^6 = +127$.
- Sayı 1 ile başlıyorsa negatiftir; büyüklüğünü bulmak için ikinin tümleyeni alınır.

İkinin tümleyenini almak için bütün bitler ters çevrilir ve 1 eklenir. Tahtadaki örnek (ekrandan, 01:55:00):

- **Verilen:** $1000\,1011$
- **Tümleme (bitleri ters çevirme):** $0111\,0100$
- **1 ekleme:** $0111\,0100 + 1 = 0111\,0101$
- **Sonuç:** $0111\,0101 = 64 + 32 + 16 + 4 + 1 = 117$; sayı 1 ile başladığı için değeri −117'dir (ara adım eklendi; sonuç python ile kontrol edildi).

Daha kısa bir yol da gösterildi: sayının sağından başlayarak ilk 1'e kadar (o 1 dahil) bitler aynen yazılır, ondan sonraki bütün bitler ters çevrilir.

Özel durumlar:

- $1000\,0000$: kısa yolla ilk 1 en soldadır, sayı değişmez; büyüklük 128'dir, yani bu kod −128'dir. +127'den sonra −128 gelir.
- $1111\,1111$: negatif; ikinin tümleyeni $0000\,0001 = 1$, yani bu kod −1'dir.

İkinin tümleyeninde artık iki ayrı sıfır yoktur; işaret biti gösteriminde −0'a giden $1000\,0000$ kodu burada −128'i gösterir.

### 9.7 Sabit noktalı gösterim

Tam sayı olmayan sayılar için farklı yöntemler vardır. Sabit noktalı (fixed point) gösterimde virgül hep aynı yerdedir. Ondalık sistemde virgülün solundaki basamaklar $10^0, 10^1, 10^2, \dots$, sağındakiler $10^{-1}, 10^{-2}, \dots$ ağırlığındadır (3456,78 örneği). Aynısı ikili sisteme uyarlanır: solda $2^0, 2^1, 2^2, \dots$, sağda $2^{-1}, 2^{-2}, \dots$. Hoca slayttaki üs değerlerinin yanlış yazıldığını söyleyip kendisi düzeltti.

Derste çözülen örnek:

- **Verilen:** $11001{,}11_2$
- **Tam kısım:** $1 \cdot 2^4 + 1 \cdot 2^3 + 0 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 = 16 + 8 + 1 = 25$
- **Kesir kısmı:** $1 \cdot 2^{-1} + 1 \cdot 2^{-2} = 0{,}5 + 0{,}25 = 0{,}75$
- **Sonuç:** $25{,}75$

Sabit noktalı gösterimin sınırı şudur: kesir için örneğin 3 bit ayrılmışsa, hepsi 1 olduğunda bile en büyük kesir $0{,}5 + 0{,}25 + 0{,}125 = 0{,}875$'tir. Virgülden sonraki kısım ayrılan bit sayısıyla sınırlanır.

### 9.8 IEEE-754 kayan noktalı gösterim

Kayan noktalı (floating point) gösterimde virgülün yeri sabit değildir. 32 bitlik IEEE-754 standardında alanlar şöyledir (ekrandan, 02:00:00):

| Alan | Bit sayısı |
|---|---|
| İşaret ($s$) | 1 |
| Kaydırılmış üs (biased exponent) | 8 |
| Kesir (fraction, mantis) | 23 |

$$N = (-1)^s \times 1.\text{kesir} \times 2^{(\text{kaydırılmış üs} - 127)}$$

$s = 0$ ise sayı pozitif, $s = 1$ ise negatiftir. Mantis "normalize" edilir: baştaki 1 atılır, yalnız kesir kısmı saklanır. Üs alanına gerçek üsse 127 eklenmiş değer yazılır, böylece hem pozitif hem negatif üsler temsil edilir. Slayttaki örnekler:

- $2^{-127}$ → kaydırılmış üs $0000\,0000$ (= 0)
- $2^{0}$ → kaydırılmış üs $0111\,1111$ (= 127)
- $2^{+127}$ → kaydırılmış üs $1111\,1110$ (= 254)

Derste çözülen örnek, 25,75:

- **İşaret biti:** Sayı pozitif, $s = 0$.
- **Normalizasyon:** $11001{,}11_2$'de virgül, baştaki 1'in hemen sağına gelene kadar 4 basamak sola kaydırılır: $1{,}100111 \times 2^4$.
- **Üs:** $4 + 127 = 131$ üs alanına yazılır. Okunurken $131 - 127 = 4$ basamak kaydırıldığı anlaşılır.
- **Neden 127?** Hocaya göre 0'dan 254'e kadar olan alanı kullanarak aralığı genişletmek için.

> **Ders sonrası not:** Derste 32 bitin tamamı yazılmadı. Python ile yapılan kontrole göre 25,75'in IEEE-754 tek duyarlıklı karşılığı `0 10000011 10011100000000000000000`, onaltılık olarak `41CE0000`'dır ($131 = 10000011_2$).

Sabit noktalıda virgül hep aynı yerde kaldığı için kesir hassasiyeti sınırlıdır. Kayan noktalıda sayı istenildiği kadar kaydırılıp ölçeklenebildiği için çok daha geniş bir aralık temsil edilebilir.

### 9.9 Durum sayısı ve gereken bit sayısı

Slaytta 7 rengin ikili olarak kodlanması istendi. $k$ farklı durum için gereken bit sayısı:

$$b = \lceil \log_2 k \rceil$$

$\lceil \cdot \rceil$ üste yuvarlama (tavan, ceiling) işlemidir. 4 durum için 2, 8 durum için 3 bit yeter. Dolayısıyla 7 ve 8 durum için 3 bit, 9 durum için 4 bit gerekir. On rakamı (0–9) ikili ifade etmek için de $\lceil \log_2 10 \rceil = 4$ bit gerekir (ekrandan, 02:05:00).

### 9.10 BCD

8421 BCD (Binary Coded Decimal, ikili kodlanmış ondalık) gösteriminde her ondalık rakam kendi 4 bitlik ikili karşılığına çevrilir (ekrandan, 02:05:00). $0000$ sıfıra, $1001$ dokuza karşılık gelir; geri kalan kodlar kullanılmaz.

- **Örnek:** $(57)_{10}$
- 5 → $0101$ ($4 + 1$), 7 → $0111$ ($4 + 2 + 1$)
- **Sonuç:** $(0101\ 0111)_{BCD}$

Slayta göre ASCII karakter kodları ve eşlik (parity) bitleri gibi sayıları ikili ifade etmeye yarayan başka sistemler de vardır.

### 9.11 Onaltılık sistem ve ASCII

İkili sistemde 2 rakam (0, 1), sekizli (oktal) sistemde 8 rakam (0–7), onaltılık (hexadecimal) sistemde 16 rakam vardır: 0–9 ve ardından A, B, C, D, E, F (F = 15). Her hex rakamı 4 bite karşılık geldiği için dönüşüm, rakamları ayrı ayrı 4 bite çevirerek yapılır:

- $41_{16}$: 4 → $0100$, 1 → $0001$; sonuç $0100\,0001$.
- $5A_{16}$: 5 → $0101$ ($4 + 1$), A = 10 → $1010$ ($8 + 2$); sonuç $0101\,1010$.

Bu kodlar bir tabloyla harflere de karşılık getirilebilir. 8 bitlik ASCII'de $41_{16}$ "A" harfidir; slayta göre küçük harfler $61_{16}$ ile $7A_{16}$ arasındaki kodlarla ifade edilir.

### 9.12 Dönüştürme ve kodlama farkı

Slayttaki uyarı: Bir ondalık sayının ikili sayıya **dönüştürülmesi** (conversion) ile bir ondalık sayının ikili bir kodla **kodlanması** (coding) karıştırılmamalıdır (ekrandan, 02:10:00).

- $13_{10} = 1101_2$ bir dönüştürmedir: $2^3 + 2^2 + 2^0 = 8 + 4 + 1 = 13$.
- $13 \Leftrightarrow (0001\ 0011)_{BCD}$ bir kodlamadır: 1 ve 3 rakamları ayrı ayrı kodlanır.
- Bu BCD dizisi düz ikili sayı gibi okunursa $2^4 + 2^1 + 2^0 = 16 + 2 + 1 = 19$ elde edilir. Dönüştürme yapılmamış, sayının rakamları ayrı ayrı kodlanmıştır.

**Soru:** BCD olduğunu belirtmek zorunlu mu? **Cevap:** Evet; BCD kullanıldığının bilinmesi gerekir, yoksa dizi yanlış (örneğin 19 olarak) okunur.

Sunumun kalanındaki mantıksal değişkenler, Boole cebiri ve temel mantık işlemleri (NOT, AND, OR, XOR doğruluk tabloları) Lojik dersinde anlatılacağı için hızla geçildi (ekrandan, 02:15:00).

## 10. Örnek Sorular

**Soru 1** (derste sözlü, 00:31:01): Yalnız en yüksek frekanslı bileşenin tepe noktalarının örneklendiği en kötü durumda $T_{max}$ ile $T_s$ arasındaki ilişki nedir? Bunu frekans cinsinden yazınız.

> **Çözüm:** Bir periyotta iki örnek alındığı için $T_{max} = 2T_s$. $f = 1/T$ olduğundan $f_s = 2f_{max}$. Daha sık örnekleme de olabileceği için genel koşul $f_s \geq 2f_{max}$'tır (Nyquist).

**Soru 2** (derste sözlü, 00:35:00): Konuşmada üretilen en yüksek frekans 4 kHz ise bu ses en az kaç Hz ile örneklenmelidir? Örnekleme periyodu kaçtır?

> **Çözüm:** $f_s \geq 2 \times 4 = 8$ kHz. $T_s = 1/8000 = 125\ \mu s$.

**Soru 3** (ekrandan, 00:40:00): Örnekleme aralığı 62,5 µs'ye daraltılırsa $f_s$ kaç olur?

> **Çözüm:** $f_s = 1/(62{,}5 \times 10^{-6}\ \text{s}) = 16$ kHz. Bu, $4f_{max}$'a karşılık gelir.

**Soru 4** (derste sözlü, 00:25:51): Sabit gerilim veren (DC) kaynaklara örnek veriniz.

> **Çözüm:** Pil (örneğin 1,5 V'luk pil), adaptör. Bu kaynakların çıkışı zamanla değişmez.

**Soru 5** (derste sözlü, 00:45:32 ve 00:49:07): Örneklenerek ayrıklaştırılmış işaret doğrudan hafızaya yazılabilir mi? Önünde bir engel var mı?

> **Çözüm:** Hayır. Örnekleme yalnız zaman eksenini ayrıklaştırır; genlik hâlâ sonsuz hassasiyette değer alabilir. Hafıza gözleri ise sınırlı sayıda bitten oluşur. Genlik ekseni seviyelere bölünmeli (nicemleme) ve her seviye ikili koda çevrilmelidir (kodlama).

**Soru 6** (derste sözlü, 01:00:07): Kuanta aralıkları 3,7–3,8 (orta değer 3,75) ve 3,8–3,9 (orta değer 3,85) ise 3,84 genlikli örnek hangi değerle saklanır? 3,73 için hata ne olur?

> **Çözüm:** 3,84, 3,8–3,9 aralığına düştüğü için 3,85 ile saklanır; hata $|3{,}84 - 3{,}85| = 0{,}01$. 3,73, 3,7–3,8 aralığında olduğu için 3,75 ile saklanır; hata $|3{,}73 - 3{,}75| = 0{,}02$.

**Soru 7** (derste sözlü, 01:44:16 ve 01:45:59): 8 bit ile kaç farklı durum ifade edilir? İşaretsiz ve işaretli aralıklar nedir?

> **Çözüm:** $2^8 = 256$ durum. İşaretsiz: 0–255. Bir bit işarete ayrılırsa: −128…+127.

**Soru 8** (ekrandan, 01:45:00): 3546 sayısı ondalık sistemde nasıl ifade edilir?

> **Çözüm:** $3546 = 3 \times 10^3 + 5 \times 10^2 + 4 \times 10^1 + 6 \times 10^0$: üç binlik, beş yüzlük, dört onluk, altı birlik.

**Soru 9** (ekrandan, 01:55:00): İkinin tümleyeni gösteriminde $1000\,1011$ hangi sayıdır?

> **Çözüm:** Baştaki bit 1 olduğu için sayı negatiftir. Bitler ters çevrilir: $0111\,0100$; 1 eklenir: $0111\,0101 = 117$. Sayı −117'dir. Derste tümleme ve +1 adımları tahtada gösterildi; ondalık sonuç python ile kontrol edildi.

**Soru 10** (ekrandan, 02:00:00 ve derste sözlü, 02:00:09): 25,75 sayısının IEEE-754 tek duyarlıklı gösteriminde işaret biti ve kaydırılmış üs nedir?

> **Çözüm:** $25{,}75 = 11001{,}11_2 = 1{,}100111 \times 2^4$. İşaret biti 0, kaydırılmış üs $4 + 127 = 131 = 1000\,0011_2$.

> **Çözüm (derste verilmedi):** Kesir alanı $1001\,1100\,0000\,0000\,0000\,000$ (23 bit); 32 bitin tamamı $0\ 10000011\ 10011100000000000000000$ = `41CE0000` (python ile kontrol edildi).

**Soru 11** (derste sözlü, 02:03:00): 7 farklı rengi ikili kodlamak için kaç bit gerekir?

> **Çözüm:** $\lceil \log_2 7 \rceil = 3$ bit. 8 durum için de 3 bit, 9 ve 10 durum için 4 bit gerekir.

**Soru 12** (ekrandan, 02:05:00): $(57)_{10}$ sayısının BCD karşılığı nedir?

> **Çözüm:** 5 → $0101$, 7 → $0111$; $(57)_{10} = (0101\ 0111)_{BCD}$.

**Soru 13** (ekrandan, 02:10:00): $13_{10} = 1101_2$ ile $13 \Leftrightarrow (0001\ 0011)_{BCD}$ arasındaki fark nedir? BCD dizisi düz ikili sayı gibi okunursa ne elde edilir?

> **Çözüm:** İlki dönüştürmedir ($8 + 4 + 1 = 13$), ikincisi rakamların ayrı ayrı kodlanmasıdır. $0001\,0011$ düz ikili okunursa $16 + 2 + 1 = 19$ elde edilir.

## Dersin Toparlaması

Bu derste sürekli bir işaretin bilgisayarda nasıl saklanabileceği adım adım kuruldu. Sinüzoidal işaretin genlik, frekans, periyot ve faz parametreleri hatırlatıldı; Fourier analiziyle her işaretin sinüzoidallerin toplamı olduğu, pratikte işaretlerin bir en yüksek frekansa ($f_{max}$) sahip olduğu anlatıldı. En kötü durum olan tepe noktası örneklemesinden Nyquist teoremine ($f_s \geq 2f_{max}$) ulaşıldı. Örneklemenin yalnız zaman eksenini ayrıklaştırdığı, genlik ekseninin de nicemlenip ikili koda çevrilmesi gerektiği, her iki adımın da bir hata getirdiği ve sonucun orijinal işaretin bir yaklaşığı olduğu gösterildi. Örnekleme frekansı ve bit sayısı arttıkça kalite artar, hafıza ihtiyacı da büyür.

İkinci bölümde ilk sunumla bilgi, veri ve sistem kavramları, tipik ölçüm sistemi, tutma ve saat işareti, örnekleme türleri ve sayısal veri temsili ele alındı: bit/nibble/byte/word, $2^{10}$ tabanlı ön ekler, işaret biti ve ikinin tümleyeni, sabit ve kayan noktalı (IEEE-754) gösterim, gereken bit sayısı, BCD, onaltılık sistem ve dönüştürme ile kodlama farkı. Hoca ilk haftalarda temel konular işlendiği için MATLAB ve Python'a zaman ayrılmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
