# Ders 2 Genişletilmiş Notu: Örnekleme, Nyquist Teoremi, Nicemleme ve Temel Ayrık Zamanlı Diziler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi: Disiplinlerarası Bir Ders
- 2. Dış Dünya Verisi, Bilgisayar ve İşaretin Boyutu
- 3. Sürekli İşaretler ve Ayrıklaştırma İhtiyacı
- 4. Örnekleme ve Örnekleme Periyodu
- 5. Sinüzoidal İşaretler: Genlik, Frekans, Faz
- 6. DC ve AC İşaretler
- 7. Fourier Analizi ve Bant Sınırlı İşaretler
- 8. Nyquist Teoremi
- 9. Nicemleme ve İkili Kodlama
- 10. Ayrık Zamanlı İşaretler ve Karmaşık Diziler
- 11. Temel Diziler: Birim Dürtü ve Birim Basamak
- 12. Euler Eşitliği
- 13. Dizilerin Sınıflandırılması
- 14. İşaret Manipülasyonları
- 15. İşaret Ayrıştırma (Signal Decomposition)
- 16. Ders Sonu Soru-Cevap
- Örnek Sorular

## 1. Dersin Çerçevesi: Disiplinlerarası Bir Ders

Hoca dersi Microsoft Whiteboard üzerinde, bir kara tahta ortamı gibi anlatacağını, ara sıra PowerPoint sunumları da kullanacağını söyledi. Ders, sayısal işaret işleme (Digital Signal Processing, DSP), görüntü işleme (Image Processing) ve makine öğrenmesi ya da örüntü tanımayı (Pattern Recognition) bir araya getiren disiplinlerarası bir derstir. İlk haftalarda işaret işleme ve sayısal işaret işleme, ardından hızlı bir şekilde görüntü işleme ve makine öğrenmesinin temelleri anlatılacaktır.

Sonraki haftalardaki proje çalışmaları için Python ve MATLAB'in temel araçlar olduğunu belirtti. Projelerde MR, histopatoloji, BT (CT) ve röntgen gibi biyomedikal görüntüler ya da biyomedikal işaretler kullanılabilir; güncel makine öğrenmesi ve görüntü işleme teknikleriyle yenilikçi bir şey ortaya koymak hedeflenir.

## 2. Dış Dünya Verisi, Bilgisayar ve İşaretin Boyutu

Hocaya göre biyomedikal veri de olsa uzaktan algılama verisi de olsa yaptığımız iş aynıdır: dış dünyadan bir veri alırız ve onu işlem yapabilen bir birime aktarırız. Bu birime "bilgisayar" (computer) dememizin nedeni işlem ve hesaplama yapabilmesidir. Bilgisayar illa dizüstü, masaüstü ya da iş istasyonu olmak zorunda değildir. Mikrodenetleyici (µC) ya da mikroişlemci (µP) barındıran, giriş alıp çıkış üreten her birim bu anlamda bir bilgisayardır (ekrandan, 00:45:00):

- Cep telefonu.
- Sensörlerle donatılmış, dışarıdan veri alıp işleyen ve röleleri açıp kapatan bir otomasyon kartı.
- Otomobilin içindeki dış sensör verilerini alıp ana kartında işleyen ve karar veren kontrol birimi.

Tahtada çizilen $x(t)$ işareti, örneğin hocanın konuşma işareti ya da hastanın vücudundan alınan bir EKG işareti olabilir. Bu işaret yalnız bir bağımsız değişkene, $t$'ye bağlı olduğu için **bir boyutlu (1D)** bir işarettir.

İki boyutlu bir görüntüde fonksiyon $u(x, y)$ biçimindedir. Gri seviye bir görüntü, beyaz ile siyah arasında grinin tonlarını içerir. Renkli bir görüntü ise R, G ve B adlı üç adet iki boyutlu katmandan oluşur (ekrandan, 00:45:00). MR gibi vücudun kesitlerini alan sistemler çok katmanlı veri üretir; farklı öznitelikleri ayrı ayrı kaydettiğimiz $N$ boyutlu verilerimiz de olabilir. Hoca dersi genellikle bir boyutlu veri üzerinden anlatacağını söyledi.

## 3. Sürekli İşaretler ve Ayrıklaştırma İhtiyacı

Dış dünya verileri süreklidir. Hoca bunu üç örnekle anlattı:

- **Ses:** Sınıfta konuşsaydık, ses havada sürekli bir biçimde kulağa ulaşır ve beyin tarafından işlenirdi. Herhangi bir ayrık zamanda süreksizlik olmazdı; işaret zamanın her anında tanımlıdır.
- **Görme:** Bilgisayar ekranlarında, telefonlarda ve sayısal fotoğraf makinelerinde piksel kavramı vardır; resmi yaklaştırınca kare kare efektler görülür. Gözümüzde ise piksel diye bir şey yoktur.
- **Eski tip fotoğraf makinesi:** Mercekten geçen görüntü filmin üzerine düşer, ışığın şiddetine göre filmde kimyasal değişimler olur, sonra baskı yapılır. Burada da piksel kavramı yoktur.

Analog işaret zamanın her anında tanımlıdır. Örneğin 3. ve 4. saniye arasındaki genlik değerlerini kaydetmek istediğimizi düşünelim. Bir boyutlu işaretleri bir dizi olarak kaydederiz. 3. saniyedeki değeri kaydettik; bir sonraki değeri 3,01'de mi, 3,001'de mi alacağız? 3'ten sonra bir milyar sıfır ve ardından 1 gelen bir an bile 3'ten farklı bir genliğe sahiptir. Yani en küçük aralıkta bile sonsuz sayıda değer vardır. Bilgisayar sistemlerimizin amacı bu nedenle **sürekli sistemlerden ayrık (discrete) sistemlere geçmektir.** Sayısal işaret işleme tam olarak bununla ilgilenir.

## 4. Örnekleme ve Örnekleme Periyodu

Hoca tahtaya bir kalp atım işareti çizdi. Bu işareti bilgisayara koymak için hafızaya yazmamız gerekir; bunun için işaretten belirli aralıklarla örnekler alırız. Böylece $t$ ekseni ayrıklaşmış olur. Bu işlemin adı **örneklemedir (sampling).** Her örneğin genlik değeri hafızanın bir gözüne yazılır.

Bir örnek ile bir sonraki örnek arasında geçen süreye **örnekleme periyodu (sampling period)** denir ve $T_s$ ile gösterilir (ekrandan, 00:50:00). Tersi örnekleme frekansıdır: $F_s = 1/T_s$.

**Soru:** Analogdan ayrığa geçerken $T_s$ aralıklarla örnek alacağız. Bir mühendis olarak aklımıza ilk takılan soru ne olmalı? **Cevap:** Bir öğrenci periyot aralığına göre netlik ile işlem yükü arasındaki orandan söz etti. Hoca daha basit bir biçimde şöyle sordu: Bu örnekleri ne sıklıkta almalıyım?

Örnekleri çok gevşek alırsak işaretteki önemli değişimler yakalanamaz (hoca bunu tahtada kırmızıyla gösterdi). Çok sık alırsak sınır yoktur; aralığı epsilon kadar küçültebiliriz. İki durumun avantaj ve dezavantajları öğrencilerle birlikte şöyle toparlandı:

- **Sık örnekleme:** Avantajı, orijinal işarete iyi yaklaşmaktır (good approximation). Dezavantajı, işlem yükünün artması ve her noktanın hafızada yer kaplamasıdır.
- **Seyrek örnekleme:** Avantajı, işlem yükünün ve gereken hafızanın azalmasıdır. Dezavantajı, verideki bazı noktaların, yani bilginin kaybolmasıdır.

RAM, ROM, SSD, sabit disk ya da bulut, hangi ortamda saklanırsa saklansın kaynak sınırlıdır. Bu yüzden aralığı olabildiğince geniş seçmek isteriz; fakat bu genişlikte işaretin bilgi taşıyan ince özelliklerini kaybetmemeliyiz. Örneğin bir kalp verisindeki küçük bir azalma ya da titreşim bir hastalığa karşılık gelebilir. Asıl soru şudur: İşaretin özelliklerini kaybetmeden seçebileceğimiz en büyük $T_s$ nedir? Bunu yanıtlamak için Fourier analizine ihtiyaç vardır, ama önce sinüzoidal işaretleri tanımlamak gerekir.

## 5. Sinüzoidal İşaretler: Genlik, Frekans, Faz

Hoca öğrencilere, farklı sinüzoidal işaretleri birbirinden ayıran özellikleri sordu.

**Genlik:** Sinüzoid $-A$ ile $+A$ arasında salınır; $A$ genliktir (ekrandan, 01:00:00).

**Periyot ve frekans:** Bir çevrimin tamamlanması için geçen süre periyottur. Periyot kısaldıkça işaret birim zamanda daha çok tekrarlar. Periyot frekansın tersidir: $T = 1/f$.

**Soru:** Frekansı kim tanımlayabilir? **Cevap:** Bir öğrenci "bir hareketin kendini tekrar ettiği süre" dedi; hoca bunun periyodun tanımı olduğunu söyledi. Başka bir öğrenci "saniyedeki tekrar miktarı" dedi. Hoca bunu onayladı: Frekans, işaretin birim zamanda, örneğin bir saniyede, çevrimini kaç kez tamamladığıdır. Frekans arttıkça periyotlar sıkışır, yani kısalır.

**Soru:** Tahtadaki iki işaretten hangisinin frekansı daha yüksek? **Cevap:** Alttakinin. Aynı birim zaman içinde üstteki işaret ancak bir çevrim yaparken alttaki çok daha fazla çevrim yapmıştır (ekrandan, 01:00:00).

**Faz:** Sinüzoidlerin başlangıç noktası da önemlidir. Tahtada maviyle çizilen sinüs sıfırdan başlar; sarıyla çizilen kosinüs ise sıfırda tepe değerden başlar. Yani sinüs ile kosinüs arasındaki tek fark başlangıç koşuludur. Bir sinüzoid bu üç büyüklükle yazılır (ekrandan, 01:00:00):

$$f(t) = A\sin(\omega t + \varphi) = A\sin(2\pi f t + \varphi)$$

Burada $A$ genlik, $f$ frekans ($\omega = 2\pi f$) ve $\varphi$ fazdır. Faz, başlangıç noktasının sağa ya da sola ötelenmesiyle ilgilidir.

## 6. DC ve AC İşaretler

Bir işaret salınım yapmıyor ve sabit bir değere sahipse ona **DC (Direct Current, doğru akım)** işareti denir. Belli bir salınım gösteriyorsa **AC (Alternating Current, alternatif akım)** işareti denir. Bu kavramlar güç iletimi çalışmalarından gelmiştir; güç iletiminde hem DC hem AC kullanılabilir.

**Soru:** Duvardaki prizden, örneğin şarj cihazını taktığımız yerden aldığımız güç işareti AC midir, DC midir? Genliği ve frekansı nedir? **Cevap:** AC'dir. Genliği (gerilimi) 220 V'tur. Frekansı 50 Hz'dir (ekrandan, 01:05:00).

Hoca bu soruyu uluslararası bir öğrenciye İngilizce de sordu; öğrenci 50–60 Hz arasında olduğunu söyledi. Hoca, Türkiye'nin Avrupa sistemini kullandığını açıkladı: Türkiye'de, Almanya ve İsveç gibi Avrupa ülkelerinin çoğunda şebeke 220 V ve 50 Hz'dir; yani gerilim saniyede 50 kez dalgalanır. ABD'de ise 110 V ve 60 Hz kullanılır.

Özetle: Frekans 0 ise işaret DC, frekans 0'dan büyükse AC'dir.

## 7. Fourier Analizi ve Bant Sınırlı İşaretler

Fourier 1800'lü yıllarda yaşamış bir matematikçidir. O dönemde "işaret" kavramı üzerine değil, keyfi değişen fonksiyonlar üzerine düşünüyordu. Fourier'in söylediği şudur: **Herhangi bir fonksiyon, kendisini oluşturan sonsuz sayıda farklı frekanslı sinüzoidin toplamı olarak yazılabilir.**

Hoca bunu tahtada şöyle gösterdi: Bir işaret, $f = 0$ bileşeni (işaretin ortalaması), ardından giderek artan frekanslara sahip sinüzoidler toplamına eşittir. Aşağı doğru indikçe frekans artar; aradaki noktalar, aradaki frekansların da tanımlı olduğunu gösterir. Bu bileşenlerin her birinin genliği farklıdır. Tahtadaki yazım (ekrandan, 01:10:00):

$$f(t) = \int_{0}^{\infty} A_f \sin(2\pi f t)\, df$$

Hoca burada fazı yazmadığını belirtti. $A_f$, $f$ frekansındaki bileşenin genliğidir. Bütün bileşenler aynı genlikte olsaydı $A_f = 1$ olurdu; ama işareti oluşturan bileşenler farklı genliklidir.

> **Ek bilgi (derste anlatılmadı):** Fazı da hesaba katan genel gösterimde her frekans için bir sinüs ve bir kosinüs bileşeni (ya da genlik ve faz) bulunur. Periyodik işaretler için bu toplam Fourier serisi, periyodik olmayan işaretler için Fourier dönüşümü olarak ifade edilir.

Teoride bileşenler sonsuza kadar gider; gerçekte ise işaretin bir kaynak tarafından üretilmesi gerekir. Örneğin hoca konuşurken ses telleri titreşir ve bu titreşim kulağımıza ses olarak gelir. Ses tellerinin üretebileceği bir **maksimum frekans** vardır; bunun üzerindeki bileşenlerin genlikleri sıfırdır ($A_f = 0$) (ekrandan, 01:15:00). Bu tür işaretlere **bant sınırlı (band limited) işaretler** denir. Ses ve EKG işaretleri bant sınırlıdır.

Ortalama bir insan konuşmasında $f_{max}$ yaklaşık 4 kHz'dir; daha tiz konuşan biri 5 kHz'e çıkabilir. $f_{max}$'ın altındaki bazı frekanslar işarette bulunmayabilir; örneğin konuşurken 3,2 kHz'lik bir bileşen üretmiyorsak onun genliği sıfırdır. Önemli olan, düşük frekanslardan başlayıp $f_{max}$'a kadar gidilmesidir.

## 8. Nyquist Teoremi

Hoca, örnekleme periyodu $T_s$ ile örnekleme frekansı $F_s$'nin birbirinin tersi olduğunu hatırlattı. Aranan şey, aralığı açabileceğimiz üst sınırdır.

İşaretin içindeki en yüksek frekanslı bileşenden yalnız tepe noktalarını aldığımızı düşünelim. Bu durumda bu bileşenin bir çevriminden yalnız iki örnek alınır: bir üst tepe ve bir alt tepe. Bu en kötü durumdur (worst case). Aynı $T_s$ ile daha düşük frekanslı bileşenlerden bir çevrimde çok daha fazla örnek alınır; tahtadaki örnekte bir çevrim tamamlanana kadar 4–5 örnek alındı. Demek ki örnekleme aralığını belirleyen, en yüksek frekanslı bileşendir.

Hoca en yüksek frekanslı bileşenin bir çevrimini büyüterek çizdi (ekrandan, 01:15:00). Bu çevrimin süresi $T_{max} = 1/f_{max}$'tır. Örnekler üst tepede ve alt tepede alınırsa aradaki mesafe $T_s$'dir.

**Soru:** $T_{max}$ ile $T_s$ arasındaki ilişki nedir? **Cevap:** $T_{max} = 2T_s$. Frekans cinsinden: $F_s = 2F_{max}$ (ekrandan, 01:20:00).

Örnekleri daha sık alırsak, örneğin tepe noktalarına ek olarak sıfır geçişlerini de alırsak, bir çevrimde dört örnek olur. Bu durumda $T_s$ kısalır:

**Soru:** Bir çevrimden dört örnek alınırsa $T_{max}$ nedir? **Cevap:** $T_{max} = 4T_s$, yani $F_s = 4F_{max}$ (ekrandan, 01:20:00).

Daha da sık örnekleyebiliriz: $8F_{max}$ gibi. Bu nedenle formül eşitlik olarak değil, eşitsizlik olarak yazılır. Alabileceğimiz en geniş aralık, en yüksek frekanslı bileşenin yalnız tepelerini aldığımız durumdur:

$$F_s \ge 2F_{max}$$

Buna **Nyquist teoremi** denir (ekrandan, 01:20:00). Bir işaret, içinde bulunan en yüksek frekansın en az iki katı ile örneklenmelidir.

> **Hocanın vurgusu:** 4 kHz'lik bir konuşma işaretini örneklemek istiyorsanız en az 8 kHz kullanmanız gerekir. 16, 32 ya da 64 kHz kullanırsanız sesin kalitesini artırmış, daha iyi örneklemiş olursunuz.

Hoca konuşma örneğini şöyle kurdu: Sınıfta bir öğrenci hocanın sesini mikrofonla bilgisayara kaydetmek istiyor. Sesin en yüksek frekansı 4 kHz olduğuna göre $F_s$ en az kaç olmalıdır? Bir öğrenci 8 kHz dedi; hoca, sesin özelliklerini kaybetmeden örneklemek için 8 kHz gerektiğini onayladı. 8 kHz yerine 16 kHz ile örneklemek iki kat, 32 kHz ile örneklemek dört kat daha fazla örnek almak demektir.

> **Ek bilgi (derste anlatılmadı):** $F_s < 2F_{max}$ seçilirse yüksek frekanslı bileşenler örneklenmiş işarette daha düşük bir frekansta görünür; bu bozulmaya örtüşme (aliasing) denir. Bu yüzden pratikte örneklemeden önce işaret, $F_s/2$ üzerindeki bileşenleri bastıran bir alçak geçiren filtreden geçirilir.

## 9. Nicemleme ve İkili Kodlama

Örneklemeden sonra işaret ayrık hale gelmiştir: $T_s$ aralıklarla alınmış örneklerimiz vardır (ekrandan, 01:45:00). Hoca, bu örnekleri hafızaya yazmanın önünde başka bir engel kalıp kalmadığını sordu. Tahtadaki örnekte hafızanın kelime boyu 16 bit, toplam boyutu 3 GB idi.

**Soru:** Hafıza yeterli. Örnekleri hafızaya yazmanın önünde bir engel var mı? **Cevap:** Hoca soruyu somutlaştırdı: İlk örneğin değeri 3, onu bir göze yazdık. İkinci örneğin değeri 5,14329875... diye gidiyor. Bunu 16 bitlik bir göze yazabilir miyiz? Öğrenci, değerin bir sınırı olması, 16 bite sığması gerektiğini söyledi. Hoca problemin tam olarak bu olduğunu belirtti: Zamanı ayrıklaştırdık ama genlik hâlâ istediği değeri alabiliyor; hafıza gözünün ise sınırlı bir kelime boyu var.

Bu nedenle genlik ekseni de belirli aralıklara bölünür (ekrandan, 01:50:00):

- 1 bit ile işaret iki bölgeye ayrılır (0 ve 1; örneğin pozitif ve negatif). Sınır çizgisi ortadan geçer.
- 2 bit ile dört bölge elde edilir: 00, 01, 10, 11.
- 3 bit ile her bölge tekrar ikiye bölünür ve 8 bölge elde edilir.

Her aralığa düşen değerlere o aralığı temsil eden tek bir değer verilir. Hocanın örneğinde 3,70 ile 3,80 arasına düşen bütün değerler 3,75 ile, 3,80 ile 3,90 arasına düşenler 3,85 ile gösterilir. Bu seviyelere **kuanta seviyeleri**, işleme **nicemleme (quantization)** denir.

Kuantalar ikili kodlama (binary encoding) ile ifade edilir. $L$ kuanta seviyemiz varsa gereken bit sayısı $\lceil \log_2 L \rceil$'dir; yani logaritmanın tavanı (üstteki tamsayı) alınır. Bit sayısı arttıkça kuanta sayısı artar. Bir bit eklemek bütün kuanta seviyelerini ikiye böler; böylece önceden aynı kuantaya düşen iki değer birbirinden ayrılmaya başlar (ekrandan, 01:50:00).

<!-- BELİRSİZ: Altyazıda (01:48:53) "3 bitle kaça ayırdık? 1, 2, 3, 4 tane" geçiyor; tahtada 00, 01, 10, 11 kodları var. Bu cümle büyük olasılıkla "2 bit" olarak söylendi ya da Whisper hatası; notta 2 bit = 4 seviye olarak yazıldı. -->

Örneğin 8 bitlik bir yapıda pozitif tarafta 127, sıfır ve negatif tarafta 128 seviye olmak üzere toplam $2^8 = 256$ seviye kodlanabilir. Bir bit daha eklenip 9 bit yapılırsa bütün seviyeler ikiye bölünür.

> **Ders sonrası not:** Altyazıda 9 bit için "259" sayısı geçiyor. Hocanın gerekçesi ("$2^8$'in iki katı") doğrudur; doğru değer $2^9 = 512$'dir.

### 9.1 Nicemleme hatası

Hoca bir kuanta aralığı çizdi. Aralığın temsil değeri 3,75'tir. Gerçek örneklerden biri 3,73, diğeri 3,78 olsun. İkisi de aynı aralıkta olduğu için ikisi de 3,75 olarak kaydedilir. Bu durumda bir hata oluşur. Mutlak değerlerle toplam hata (ara adım eklendi):

$$|3{,}75 - 3{,}73| + |3{,}78 - 3{,}75| = 0{,}02 + 0{,}03 = 0{,}05$$

Bit sayısı arttıkça kuanta seviyeleri arasındaki $\Delta$ mesafesi azalır; dolayısıyla hata miktarı da azalır.

### 9.2 Analogdan sayısala zincir

Hoca bu bölümü şöyle toparladı: Analog dünyadaki işaret önce **örneklenir** (zamanda ayrıklaşır), sonra **nicemlenir** (genlik belli seviyelere oturur), en son **ikili kodlanır** ve hafızada 0 ve 1'lerden oluşan sayılara dönüşür.

> **Ek bilgi (derste anlatılmadı):** Bu üç adımı birlikte yapan donanıma analog-sayısal dönüştürücü (ADC) denir. Düzgün nicemlemede aralık genişliği $\Delta$ ise yuvarlama hatası en fazla $\Delta/2$ olur.

## 10. Ayrık Zamanlı İşaretler ve Karmaşık Diziler

### 10.1 Gösterim

Hoca yeni başlığı "Ayrık zamanlı işaretler" olarak yazdırdı. Sürekli işaret $x_a(t)$ biçiminde normal parantezle yazılır, çünkü $t$ süreklidir. Ayrık işarete geçince $t$, $n$ indisine dönüşür ve köşeli parantez kullanılır: $x[n]$. Köşeli parantez işaretin ayrık (discrete) olduğunu gösterir; $n$ bir tamsayıdır (integer), yani 0, 1, 2, 3, 4 diye giden bir indistir (ekrandan, 01:55:00).

Analog işarette $t$ yerine $nT_s$ konur:

$$x[n] = x_a(t)\big|_{t = nT_s}$$

İlk örnek $t = 0$'da, ikinci örnek $T_s$ kadar sonra, üçüncü örnek $2T_s$, dördüncü örnek $3T_s$ kadar sonra alınır (ekrandan, 01:55:00). $n = 0$ koyunca $x_a(0)$ değeri $x[0]$'a kaydedilir; $n = 1$ koyunca $T_s$ anındaki değer $x[1]$'e kaydedilir. Böylece sürekli işaretin ayrık parçaları teker teker çekilerek ayrık dizi oluşturulur.

Sayısal örnek: 4 kHz'lik işaret 8 kHz ile örnekleniyorsa

$$T_s = \frac{1}{8\ \text{kHz}} = 125\ \mu s$$

olur; yani saniyenin milyonda birinin 125 katı. Örnekler $0, 125, 250, 375\ \mu s$ anlarında alınır.

> **Ders sonrası not:** Hoca sayarken bir an "üçüncü, 750 mikrosaniye" dedi ve hemen 375 olarak düzeltti. $n = 3$ için doğru değer $3 \times 125 = 375\ \mu s$'dir.

### 10.2 Karmaşık diziler

$x[n]$ dediğimizde genellikle 3,255 ya da 7,885 gibi gerçel değerler düşünürüz; ama sayısal işaret işlemede genel olarak $x[n]$ dizisinin karmaşık değerler alabildiği kabul edilir. Karmaşık değerli işaretler $z[n]$ ile gösterilir ve bir gerçel, bir sanal kısmı vardır.

Kartezyen düzlemde karmaşık sayı $z = a + jb$ biçimindedir; yatay eksen gerçel, dikey eksen sanal eksendir. $a$ gerçel kısımdaki, $b$ sanal kısımdaki uzaklıktır. Sayının genliği Pisagor teoreminden, açısı arktanjanttan bulunur (ekrandan, 02:00:00):

$$|z| = \sqrt{a^2 + b^2}, \qquad \varphi = \arctan\frac{b}{a}$$

Böylece karmaşık sayı iki türlü ifade edilebilir: $a + jb$ (kartezyen) ya da $|z|\,e^{j\varphi}$ (genlik ve açı).

## 11. Temel Diziler: Birim Dürtü ve Birim Basamak

### 11.1 Birim dürtü (impulse)

Dürtü işareti Dirac ($\delta$) ile gösterilir:

$$\delta[n] = \begin{cases} 1, & n = 0 \\ 0, & \text{diğer} \end{cases}$$

Yalnız $n = 0$'da değer alan bir fonksiyondur. $\delta[n-1]$'in nerede olduğunu bulmak için köşeli parantezin içini sıfır yapan değere bakılır: $n - 1 = 0 \Rightarrow n = 1$. Yani dürtü $n = 1$'e kayar. $\delta[n+1]$ olsaydı dürtü $n = -1$'de olurdu.

### 11.2 Birim basamak (unit step)

$$u[n] = \begin{cases} 1, & n \ge 0 \\ 0, & \text{diğer} \end{cases}$$

$n \ge 0$ için 1 değerini alan, sağ yanlı bir dizidir.

- $u[-n]$: $n = -1$ koyunca $u[1] = 1$ olur; dizi ters döner ve sola doğru gider.
- $u[n-1]$: parantezin içini sıfır yapan değer $n = 1$'dir; dizi 1'den başlar, yani bir sağa kayar.
- $-u[n-1]$: genlikler aşağı doğru çevrilir.

### 11.3 Dürtüyü basamak cinsinden yazmak

$u[n]$ ile $-u[n-1]$ toplandığında $n \ge 1$ için örnekler birbirini götürür; geriye yalnız $n = 0$'daki örnek kalır (ekrandan, 02:05:00):

$$\delta[n] = u[n] - u[n-1]$$

## 12. Euler Eşitliği

Derste en çok kullanılacak eşitliklerden biri Euler eşitliğidir:

$$e^{jx} = \cos x + j\sin x$$

$e^{jx}$ gördüğümüzde bunun bir gerçel kısmı ($\cos x$) ve bir sanal kısmı ($\sin x$) olduğunu bilmeliyiz; $j$ sanal kısmı gösterir. Bu fonksiyon karmaşık bir değerdir ve **karmaşık üstel** olarak adlandırılır. (Hoca önce "karmaşık eşlenik" dedi, hemen "karmaşık üstel" olarak düzeltti.)

## 13. Dizilerin Sınıflandırılması

### 13.1 Süreye göre

- **Sonlu süreli diziler:** Yalnız $N_1 \le n \le N_2$ aralığında değer alır.
- **Sonsuz uzunluklu diziler:** İkiye ayrılır.
  - **Sağ yanlı:** Örneğin $u[n]$, sağa doğru sonsuza kadar gider.
  - **Sol yanlı:** Örneğin $u[-n]$, sola doğru sonsuza kadar gider.

### 13.2 Periyodik ve aperiyodik diziler

Bir dizi belli bir $N$ değeri sonra kendini tekrar etmeye başlıyorsa periyodiktir (ekrandan, 02:10:00):

$$x[n] = x[n + N], \qquad N \text{ pozitif tamsayı}$$

Tahtadaki örnekte dizi üç örnekte bir kendini tekrar ediyordu; hoca önce $N = 2$ dedi, sonra 3 olarak düzeltti. Yani $N = 3$'tür (ekrandan, 02:10:00).

$x_1[n]$ dizisi $N_1$ ile, $x_2[n]$ dizisi $N_2$ ile periyodikse, bunların toplamından ya da çarpımından oluşan yeni dizi de periyodiktir ve periyodu

$$N = \frac{N_1 N_2}{\gcd(N_1, N_2)}$$

olur; burada $\gcd$ (Greatest Common Divisor) ortak bölenlerin en büyüğüdür.

Hoca, periyodik bir dizinin genel olarak bir temel periyodun ötelenmiş kopyalarının toplamı olarak yazılabileceğini de belirtti:

$$y[n] = \sum_{k=-\infty}^{\infty} x[n - kN]$$

<!-- BELİRSİZ: Altyazıda (02:11:05) "Xn-Kn" geçiyor; formül büyük olasılıkla x[n-kN] olarak yazıldı, ilgili an karede görülmedi. -->

### 13.3 Simetrik diziler

Gerçel dizilerde çift ve tek diziler ayrılır:

- **Çift dizi:** $x[n] = x[-n]$. 1'deki değer $-1$'deki değerle, 2'deki değer $-2$'dekiyle aynıdır; dizi dikey eksene göre simetriktir. Örnek: kosinüs (ekrandan, 02:15:00).
- **Tek dizi:** $x[n] = -x[-n]$. 1'deki değer $-1$'deki değerin ters işaretlisidir. Örnek: sinüs (ekrandan, 02:15:00).

Karmaşık dizilerde eşlenik kullanılır. $z = a + jb$ ise eşleniği $z^* = a - jb$'dir; üzerinde eşlenik işareti görülen bir ifadede sanal kısım ters işaret almıştır. Karmaşık çift ve tek diziler için eşitlikler eşlenikle yazılır.

<!-- BELİRSİZ: Altyazıda (02:13:44–02:13:56) karmaşık diziler için yazılan eşitlikler net değil ("Xn eşitti X eksi n ... eksi x eksi n"); eşlenik simetri ifadeleri tahtada görülmedi. -->

> **Ek bilgi (derste anlatılmadı):** Karmaşık dizilerde standart tanımlar eşlenik simetri $x[n] = x^*[-n]$ ve eşlenik antisimetri $x[n] = -x^*[-n]$ biçimindedir.

## 14. İşaret Manipülasyonları

Haftanın son konusu, bir işareti başka bir işarete dönüştüren işlemlerdir. Genel gösterim $y[n] = x[f[n]]$'dir; $f[n]$'in biçimi işlemi belirler.

### 14.1 Öteleme (shifting)

$f[n] = n - n_0$ alınır: $y[n] = x[n - n_0]$. $n_0$ pozitifse dizi sağa, negatifse sola kayar.

Hocanın örneğinde $x[n]$ dizisi $n = 0, 1, 2, 3$'te tanımlı olsun. $x[n-2]$'de sıfırıncı eleman $n - 2 = 0$, yani $n = 2$'de oluşur; birinci eleman $n = 3$'te oluşur ve dizi bu şekilde sağa kayar.

### 14.2 Ters çevirme (reversal)

$f[n] = -n$ alınır: $y[n] = x[-n]$. İşaret dikey eksen etrafında katlanır. Örneğin $u[n]$ sağ yanlıyken $u[-n]$ sol yanlı olur.

### 14.3 Zamanda ölçekleme (time scaling)

$f[n]$ iki biçimde olabilir (ekrandan, 02:20:00):

- $f[n] = Mn$: **alt örnekleme (downsampling).**
- $f[n] = n/N$: **üst örnekleme (upsampling).**

Tahtadaki dizi: $x[-1] = 1$, $x[0] = 3$, $x[1] = 2$, $x[2] = 1$; diğer yerlerde 0 (ekrandan, 02:20:00).

**Alt örnekleme, $x[2n]$:**

- $n = 0$: $x[0] = 3$.
- $n = 1$: $x[2] = 1$.
- $n = 2$: $x[4] = 0$.
- $n = -1$: $x[-2] = 0$.

Sonuç: $n = 0$'da 3, $n = 1$'de 1. Yalnız çift indisli örnekler alındı; işaret sıkıştı (ekrandan, 02:25:00).

**Üst örnekleme, $x[n/2]$:**

- $n = 0$: $x[0] = 3$.
- $n = 1$: $x[1/2]$ tanımlı değil, 0.
- $n = 2$: $x[1] = 2$.
- $n = 3$: $x[3/2]$ tanımlı değil, 0.
- $n = 4$: $x[2] = 1$.
- $n = -1$: $x[-1/2]$, 0.
- $n = -2$: $x[-1] = 1$.

Sonuç: $n = -2$'de 1, $n = 0$'da 3, $n = 2$'de 2, $n = 4$'te 1; aradaki tek indisler 0. İşaret genişledi (ekrandan, 02:25:00).

### 14.4 İşlemler sıra bağımlıdır

Hoca bir not yazdırdı: **Öteleme (shifting), ters çevirme (reversal) ve zamanda ölçekleme işlemleri sıra bağımlıdır** (ekrandan, 02:25:00).

$$x[n] \xrightarrow{T_{n_0}} x[n - n_0] \xrightarrow{T_r} x[-n - n_0]$$

$$x[n] \xrightarrow{T_r} x[-n] \xrightarrow{T_{n_0}} x[-n + n_0]$$

Ters çevirme yalnız ana değişkenin işaretini değiştirir. Önce öteleme sonra ters çevirme $x[-n-n_0]$ verirken, önce ters çevirme sonra aynı yönde öteleme $x[-n+n_0]$ verir. İkisi eşit değildir.

## 15. İşaret Ayrıştırma (Signal Decomposition)

Herhangi bir $x[n]$ işareti, ötelenmiş ve ağırlıklandırılmış dürtülerin toplamı olarak yazılabilir (ekrandan, 02:30:00):

$$x[n] = \sum_{k=-\infty}^{\infty} x[k]\,\delta[n-k]$$

Burada $k$ ötelemeyi belirler, $x[k]$ ise katsayı olarak denkleme girer.

Hocanın örneği: $x[0] = 3$, $x[1] = 2$, $x[2] = 1$ olan bir dizi. Bu dizi aslında üç dürtüden oluşur: $n = 0$'da genliği 3, $n = 1$'de genliği 2, $n = 2$'de genliği 1 olan dürtüler.

- $n = 0$'daki bileşen: $3\delta[n]$.
- $n = 1$'deki bileşen: $2\delta[n-1]$.
- $n = 2$'deki bileşen: $1\cdot\delta[n-2]$.

Kapalı formda $k = 0, 1, 2$ dışındaki katsayılar sıfırdır:

$$x[n] = x[0]\delta[n] + x[1]\delta[n-1] + x[2]\delta[n-2] = 3\delta[n] + 2\delta[n-1] + 1\cdot\delta[n-2]$$

## 16. Ders Sonu Soru-Cevap

**Soru:** Bir ses dalgasını kaydetmek için örnekleme frekansının $f_{max}$'ın iki katı olması gerektiğini gördük. Elde edilen verileri RAM'e yazabilmek için gereken en az bit sayısını da hesaplayabiliyor muyuz? **Cevap:** Hayır; bu tamamen kullanılan sistemle ilgilidir. RAM ve ROM'ların kelime boyu eskiden 16 bitti, sonra 32 ve 64 bite geçildi. Bu, hafızanın genişliğiyle ve ne kadar RAM kullanılacağıyla ilgilidir; ayrıca veriler hafızaya genellikle saf haliyle değil, sıkıştırılarak yazılır. RAM miktarı ile gereken örnekleme frekansı ayrı kavramlardır. En kaba haliyle, sıkıştırma yapmadan: 8 kHz'de bir saniyelik ses için 8000 örnek alınır. 16 bin hücre 2 saniyelik, 32 bin hücre 4 saniyelik ses saklar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:50:00): Sürekli bir işaretten $T_s$ aralıklarla örnek alınacak. Örnekleri çok sık ve çok seyrek almanın avantaj ve dezavantajları nelerdir?

> **Çözüm:** Sık örnekleme orijinal işarete iyi yaklaşır, ama işlem yükü ve hafıza ihtiyacı artar. Seyrek örnekleme kaynak tasarrufu sağlar, ama işaretteki önemli değişimler kaybolur. Amaç, bilgi kaybetmeden seçilebilecek en büyük $T_s$'yi bulmaktır.

**Soru 2** (derste sözlü, 01:01:02; ekrandan, 01:05:00): Duvardaki prizden alınan güç işareti AC midir, DC midir? Genliği ve frekansı nedir?

> **Çözüm:** AC'dir. Türkiye'de 220 V ve 50 Hz'dir. ABD'de 110 V ve 60 Hz kullanılır.

**Soru 3** (derste sözlü, 01:14:42; ekrandan, 01:20:00): En yüksek frekanslı bileşenin bir çevriminden yalnız üst ve alt tepe örnekleniyor. $T_{max}$ ile $T_s$ arasındaki ilişki nedir? Bir çevrimden dört örnek alınırsa ne olur?

> **Çözüm:** İki örnek: $T_{max} = 2T_s$, yani $F_s = 2F_{max}$. Dört örnek: $T_{max} = 4T_s$, yani $F_s = 4F_{max}$. Genel koşul $F_s \ge 2F_{max}$'tır (Nyquist teoremi).

**Soru 4** (derste sözlü, 01:15:15): Konuşma sesinde en yüksek frekans yaklaşık 4 kHz'dir. Ses bilgisayara kaydedilecekse örnekleme frekansı en az kaç olmalıdır? Bu durumda örnekleme periyodu nedir?

> **Çözüm:** $F_s \ge 2 \times 4 = 8$ kHz. $T_s = 1/8000\ s = 125\ \mu s$; örnekler 0, 125, 250, 375 µs anlarında alınır (python ile doğrulandı).

**Soru 5** (derste sözlü, 01:45:12): Bir örneğin değeri 5,14329875... diye gidiyor. Bu değeri 16 bitlik bir hafıza gözüne yazabilir miyiz?

> **Çözüm:** Hayır, değer sınırlı bir bit sayısına sığmalıdır. Bu yüzden genlik ekseni kuanta seviyelerine bölünür (nicemleme) ve her değer bulunduğu aralığın temsil değeriyle ikili kodlanır.

**Soru 6** (ekrandan, 02:20:00): $x[-1] = 1$, $x[0] = 3$, $x[1] = 2$, $x[2] = 1$ dizisi için $x[2n]$ ve $x[n/2]$ dizilerini bulun.

> **Çözüm:** $x[2n]$: $n = 0 \to 3$, $n = 1 \to 1$, diğerleri 0 (alt örnekleme). $x[n/2]$: $n = -2 \to 1$, $n = 0 \to 3$, $n = 2 \to 2$, $n = 4 \to 1$, tek $n$'lerde 0 (üst örnekleme) (ekrandan, 02:25:00; python ile doğrulandı).

**Soru 7** (ekrandan, 02:30:00): $x[0] = 3$, $x[1] = 2$, $x[2] = 1$ dizisini birim dürtüler cinsinden yazın.

> **Çözüm:** $x[n] = 3\delta[n] + 2\delta[n-1] + 1\cdot\delta[n-2]$.

## Dersin Toparlaması

Bu derste biyomedikal ve diğer dış dünya işaretlerinin neden ve nasıl sayısal hale getirildiği anlatıldı. Dış dünya işaretleri süreklidir ve en küçük zaman aralığında bile sonsuz değer içerir; sınırlı kaynaklı bilgisayarlarda işlenebilmeleri için önce zaman ekseni örneklenir, sonra genlik nicemlenir ve ikili kodlanır. Örnekleme aralığının üst sınırı Fourier analizinden gelen bant sınırlılık fikriyle belirlenir: İşaret, içindeki en yüksek frekansın en az iki katıyla örneklenmelidir (Nyquist teoremi, $F_s \ge 2F_{max}$). Nicemlemede bit sayısı seviye sayısını ve dolayısıyla hata miktarını belirler.

Dersin ikinci yarısında ayrık zamanlı işaretlerin gösterimi ($x[n] = x_a(nT_s)$), karmaşık diziler, birim dürtü ve birim basamak, Euler eşitliği, dizilerin süre, periyodiklik ve simetriye göre sınıflandırılması, öteleme, ters çevirme ve zamanda ölçekleme işlemleri ile her dizinin ağırlıklı dürtüler toplamı olarak yazılabileceği gösterildi. Bu temel kavramlar, sonraki haftalarda görülecek sayısal işaret işleme konularının zeminini oluşturur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
