# Ders 3 Genişletilmiş Notu: Örnekleme, Nyquist Ölçütü, Nicemleme, Sensörler ve İdeal Diyot

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynağı ve İşlenecek Konular
- 2. Analog Dünyadan Bilgisayara
- 3. Örnekleme ve Örnekleme Periyodu
- 4. Fourier Analizi ve Sinüzoidal İşaret
- 5. En Yüksek Frekans ve Nyquist Ölçütü
- 6. Nicemleme (Quantization)
- 7. Analog ve Sayısal Sistemler: Bozulma ve Gürültü
- 8. Sensörler, Eyleyiciler ve Ölçüm
- 9. İdeal Diyot
- 10. Yarı İletkenler ve pn Eklemi
- Örnek Sorular

## 1. Dersin Kaynağı ve İşlenecek Konular

Dersin ana kaynağı Robert Boylestad ve Louis Nashelsky'nin *Electronic Devices and Circuit Theory* kitabıdır (ekrandan, 00:05:00). Hoca kitabın içindekiler kısmında işlenecek bölümleri işaretledi:

- Yarı iletken diyotlar
- Diyot uygulamaları
- Bipolar jonksiyonlu transistörler (BJT)
- BJT'lerde DC kutuplama (DC biasing)
- Alan etkili transistörler (FET)
- FET kutuplama
- İşlemsel yükselteçler (op-amp)

Kitabın 7. ve 8. bölümlerindeki AC davranış konuları bu derste işlenmez. Kitapta çok sayıda çözümlü soru vardır ve derste de bunlara benzer sorular çözülür; o ana kadar işlenen konuların toplu soru çözümüne ayrılan dersler de planlanmıştır.

Hoca, dersin neden önemli olduğunu da hatırlattı: Elektronik Devreler, gömülü sistemler, IoT sistem tasarımı ve sensör tasarımı üzerinde çalışacaklar için temel derslerden biridir. Mekatronik ve robotik alanlarında da temel çıkarımları yapabilmeyi sağlar.

## 2. Analog Dünyadan Bilgisayara

Önceki derste dış dünya verisinin elektronik sistemlere nasıl aktarıldığına giriş yapılmıştı. Hoca kısa bir tekrarla başladı.

Amaç, dış dünyadan alınan veriyi bir bilgisayarda işlemektir. Buradaki "bilgisayar" masaüstü makine ya da iş istasyonu olarak düşünülmemelidir. İçinde mikrodenetleyici (MC) ya da mikroişlemci (MP) bulunan, hafızadaki komutları belli bir döngüde adım adım işleyip sonuç üreten her yapı bu kapsamdadır: cep telefonları, kendi başına çalışan modemler gibi (ekrandan, 00:25:00).

Dış dünya **analogdur**, yani süreklidir. Bilgisayar tarafı ise **dijitaldir**, yani ayrıktır (ekrandan, 00:30:00). Hoca bunu iki örnekle açıkladı:

- Sınıfta konuşan hocanın sesi kulağınıza sürekli bir işaret olarak gelir. Bu bir boyutlu bir işarettir.
- Sınıfta hocayı gözünüzle izlerken piksel kavramı yoktur. Görüntüye ne kadar yaklaşırsanız yaklaşın noktalara ayrılmaz; beyniniz görüntüyü sürekli algılar.

Bilgisayardaki veri ise hafızada saklanır: RAM, ROM, manyetik teypler, bulut sistemleri. Bir boyutlu bir işareti (ders boyunca ses örneği kullanıldı) hafızaya göz göz yazmak gerekir ki mikroişlemcide çalışan algoritma bu verilerle hesap yapabilsin, sonucu bir hafıza bölgesine yazsın ya da ekranda göstersin. Sistemin ekranı olması da gerekmez; veriyi alıp işleyip buluta gönderebilir.

## 3. Örnekleme ve Örnekleme Periyodu

### 3.1 Örnekleme nedir?

Verinin hafızaya girebilmesi için ilk adım **örnekleme (sampling)**, yani ayrıklaştırmadır. İşaretin belli anlardaki değerleri alınır. Örnekler arasındaki süre sabittir ve $T_s$ ile gösterilir. Buna **örnekleme periyodu** denir; alt indis "s" sampling'den gelir (ekrandan, 00:30:00).

### 3.2 Seyrek örneklemenin sorunu

$T_s$ aralıklarla örnek alındığında, iki örnek arasında olan değişimler kaçırılır. Hoca bunu yalnız ses için değil, herhangi bir analog işaret için düşünmemizi istedi. Örneğin EKG (elektrokardiyogram) cihazları vücuda konan problarla kalbin atmasıyla değişen elektrik potansiyellerini ölçer. İki örnek arasında kaçırılan kısa bir artış, doktora hastalık hakkında çok şey söyleyen önemli bir bilgi olabilir (ekrandan, 00:30:00).

Çözüm daha sık örnek almak, yani $T_s$'yi küçültmektir.

### 3.3 Sık ve seyrek örneklemenin artı ve eksileri

Hoca öğrencilere sordu: $T_s$'yi küçültmenin avantajı ve dezavantajı nedir?

**Soru:** Daha dar aralıklarla örnek alırsam yararı ve zararı ne olur? **Cevap (bir öğrenci):** Orijinaline yaklaşırız, ama bellekte kapladığı alan artar. Hoca bunu doğruladı.

**Soru:** Tam tersini yapıp daha geniş aralıklarla örnek alırsam? **Cevap (başka bir öğrenci):** Bellek kullanımı azalır, ama orijinalden uzaklaşırız. Hoca bunu da doğruladı.

Demek ki burada bir ikilem vardır. Ne kadar sık örnek alırsak o kadar iyi olur; sık örneklemenin bir alt sınırı yoktur, $T_s$ sıfıra, $\varepsilon$'a kadar yaklaşabilir. Ama bilgisayar mühendisi kısıtlı kaynaklarla çalışır:

- **Hafıza:** Örnek sayısı arttıkça yer ihtiyacı artar.
- **Mikrodenetleyici:** İşlemci sürekli değil, bir saat (clock) ritmine göre çalışır; $t$ anında bir işlem, $t+1$ anında bir işlem yapar. Veri arttıkça onu alıp işlemesi (blok halinde ya da teker teker) zorlaşır.
- **Hesapsal karmaşıklık (computational complexity):** Veri üzerinde çalışacak algoritmanın hesap yükü artar.

Bu yüzden $T_s$ için bir **üst sınır** aranır: kaynaklar kısıtlı olduğundan örneklerin arası olabildiğince açılmalı, ama işaretin kendi karakteristiğine ait değişimler kaçırılmamalıdır. Bu optimal üst sınırı bulmak için Fourier analizinden yararlanılır.

## 4. Fourier Analizi ve Sinüzoidal İşaret

### 4.1 Fourier'in fikri

Joseph Fourier 1800'lerin başında çalışmış bir bilim insanıdır (ekrandan, 00:35:00). Hoca, Fourier'in bu analizi "işaretler ve sistemler dersi için" geliştirmediğini, saf matematiksel bir soru sorduğunu vurguladı: Elimizde $t$'ye bağlı keyfi (arbitrary), yani belli bir aralıkta istediği şekli alabilen bir $x(t)$ fonksiyonu olsun. Tıpkı ses işareti gibi, bir sonraki anda ne olacağını bilmiyoruz. Maddenin yapı taşı atom olduğu gibi, bu fonksiyonun da temel bir yapı taşı var mıdır?

Fourier'in cevabı evettir: Herhangi bir keyfi işaret, kendisini oluşturan **sonsuz sayıda sinüzoidal bileşenin toplamı** olarak ifade edilebilir. Frekans sıfırdan başlayıp sonsuza kadar gider ve süreklidir; yani yalnız 1, 2, 3 gibi tam değerler değil, aradaki bütün değerler de vardır (ekrandan, 00:40:00).

> **Ders sonrası not:** Altyazıda Fourier'in 1786 ile 1830 arasında yaşadığı geçiyor. Fourier'in doğum yılı büyük olasılıkla 1768'dir; sesin ya da altyazının rakamları karıştırmış olması muhtemeldir.

### 4.2 Sinüzoidal işaretin parametreleri

Hoca, sinüzoidal işareti hatırlatarak üç parametresini tahtada tek tek kurdu (ekrandan, 00:45:00):

$$x(t) = A\sin(2\pi f t + \varphi)$$

- **Genlik (amplitude) $A$:** Saf sinüs $+1$ ile $-1$ arasında salınır. $A$ ile çarpılınca işaret $+A$ ile $-A$ arasında salınır.
- **Frekans $f$:** İşaretin bir periyodu (dalga boyu) vardır ve $T = 1/f$'dir. Dalga boyu küçüldükçe frekans büyür. Frekans işin içine $\omega t$ terimiyle girer; $\omega = 2\pi f$ açısal frekanstır.
- **Faz $\varphi$:** İşaret sıfır anında illa sıfırdan başlamak zorunda değildir; ileri ya da geri kaymış olabilir. Bu kaymaya faz denir.

Hoca, sinüs ve kosinüs fonksiyonlarının aslında aynı şey olduğunu, birbirinin kaydırılmış halleri olduğunu gösterdi. Tam bir çevrim 360° ya da $2\pi$ radyandır. Kosinüs, sinüsün periyodun dörtte biri, yani 90° kaydırılmış halidir.

> **Ders sonrası not:** Hocanın bu kısımdaki cümlesi altyazıda karışık geçiyor. Doğru ilişki şöyledir: $\cos(\omega t) = \sin(\omega t + 90°)$, yani sinüsün içine $+90°$ eklenirse kosinüs elde edilir; tersine $\sin(\omega t) = \cos(\omega t - 90°)$.

### 4.3 Frekansın tanımı

Hoca bir öğrenciden frekansı sözel olarak tanımlamasını istedi.

**Soru:** Frekans deyince ne anlıyorsun? **Cevap (bir öğrenci):** Bir sinyalin ya da fonksiyonun tekrarlanma sıklığı. Hoca bu yaklaşımı beğendi ve tanımı netleştirdi: Frekans, birim zamanda (genellikle bir saniyede) işaretin kaç kez başlayıp çevrimini tamamladığıdır.

Tahtadaki örnek (ekrandan, 00:40:00):

- İşaret bir saniyede bir çevrimini tamamlıyorsa $T = 1$ s, $f = 1/T = 1$ Hz'dir.
- Aynı bir saniyede iki çevrim sığıyorsa her çevrim $T = 0{,}5$ s sürer ve $f = 1/0{,}5 = 2$ Hz olur. Yani işaret saniyede iki kez titreşir.

Demek ki dalga boyu küçüldükçe frekans artar.

### 4.4 DC ve AC bileşenler

Fourier toplamında bir istisna vardır: $f = 0$. Frekansın sıfır olması, zaman içinde salınım olmadan ilerlemek demektir. Hoca örnek olarak 1,5 V'luk bir pili verdi: Pilin uçlarına bir voltmetre bağlayıp işareti zamanda çizdirirsek 1,5 V'ta sabit giden bir çizgi görürüz. Buna **DC işaret** denir (Direct Current, doğru akım). Salınım yapan bütün diğer işaretler **AC işaret**tir (Alternating Current, alternatif akım) (ekrandan, 00:45:00).

> **Hocanın vurgusu:** Herhangi bir işaretin DC bileşeni ($f = 0$ bileşeni) onun ortalamasını verir. AC bileşenler bu ortalamanın üstüne gelir.

Farklı genliklere, farklı frekanslara ve farklı fazlara sahip sinüzoidaller DC bileşenin üzerine eklenince keyfi işaret elde edilir.

Ders arasından sonra bir öğrenci, keyfi bir fonksiyonun bu toplamla oluşması için alttaki fonksiyonların hepsinin tamamının değil, belli kısımlarının alınması gerekip gerekmediğini sordu. Hoca, fonksiyonun öncelikle belli bir aralıkta tanımlanması gerektiğini, bileşenlerin farklı genliklerle katıldığını, faz bilgisinin toplamda kayma olarak yer aldığını ve bazı bileşenlerin belli noktalarda birbirini sönümlediğini söyledi. Ayrıntıların Sayısal İşaret İşleme (DSP) dersinde anlatıldığını belirtti. Bu derste bilinmesi gereken yalnızca şudur: Keyfi bir işaret, teorik olarak sonsuz sayıda sinüzoidal bileşenden oluşur (ekrandan, 01:15:00).

## 5. En Yüksek Frekans ve Nyquist Ölçütü

### 5.1 Hızlı ve yavaş değişimler

Bir işaretteki hızlı değişimleri **yüksek frekanslı** bileşenler, yumuşak geçişleri **alçak frekanslı** bileşenler oluşturur. Teoride sonsuz sayıda frekans bileşeni vardır, ama doğal bir dış dünya işaretinde belli bir frekanstan sonra bileşenlerin genlikleri sıfıra gider. Yani o frekanstan daha hızlı salınım yapan bir bileşen yoktur. Bu frekansa $f_{max}$ denir (ekrandan, 00:50:00):

$$T_{max} = \frac{1}{f_{max}}$$

Örnek olarak insan sesi verildi. Konuşurken ses tellerimiz yaklaşık 0 ile 4000 Hz arasında ses üretir. Kimimizde biraz geçer, kimimizde geçmez, ama 8-9 kHz'de bileşen bulunmaz. Ortak kabul, konuşmada 4 kHz'in üstünde bileşen olmadığıdır: $f_{max} = 4$ kHz.

### 5.2 En kötü durum: çevrim başına iki örnek

Amaç, olabildiğince geniş ama hızlı değişimleri kaçırmayan bir $T_s$ bulmaktı. Hoca en yüksek frekanslı bileşenin bir çevrimini büyüteçle büyütür gibi ayrı çizdi. Bu çevrimin periyodu $T_{max} = 1/f_{max}$'tır (ekrandan, 00:55:00).

Şöyle bir kural koydu: En yüksek frekanslı bileşenden yalnız tepe noktalarını, yani pozitif ve negatif tepeyi alalım. Aynı örnekleme anları diğer, daha düşük frekanslı bileşenlerin üzerinden de geçer. Düşük frekanslı bileşenlerin bir çevriminde çok sayıda örnek düşer; frekans azaldıkça çevrim başına örnek sayısı artar. En kötü durum en yüksek frekanslı bileşendedir, çünkü bir çevrimde yalnız iki örnek alınır.

**Soru:** $T_s$ ile $T_{max}$ arasındaki ilişki nedir? **Cevap (bir öğrenci):** $T_s$, $T_{max}$'ın yarısıdır. Hoca cevabı tahtaya yazdı (ekrandan, 00:55:00):

$$T_{max} = 2T_s \quad\Rightarrow\quad f_s = 2f_{max}$$

### 5.3 Daha sık örnekleme ve genel kural

Hoca daha kaliteli örnekleme için yalnız tepeleri değil, geçiş noktalarını da almayı önerdi. Bir çevrimde dört örnek alınırsa (ekrandan, 00:55:00):

$$T_{max} = 4T_s \quad\Rightarrow\quad f_s = 4f_{max}$$

$8T_s$, $16T_s$ yapmanın da önünde engel yoktur. Demek ki en kötü durum çevrim başına iki örnektir ve genel kural şudur:

$$f_s \geq 2f_{max}$$

Tahtada bu ifadenin altına "Nyquist Frequency" yazıldı (ekrandan, 00:55:00).

> **Hocanın vurgusu:** Örnekleme frekansı, işaretin içerisindeki en yüksek frekansın en az iki katı olmalıdır.

> **Ders sonrası not:** Literatürde $f_s \geq 2f_{max}$ koşulu büyük olasılıkla "Nyquist ölçütü" ya da Nyquist-Shannon örnekleme teoremi diye anılır. $2f_{max}$ değerine "Nyquist hızı", $f_s/2$ değerine de "Nyquist frekansı" denir. Tahtadaki "Nyquist Frequency" ifadesi bu kuralın adı olarak kullanılmıştır.

### 5.4 Örnekler

**Sınıf kaydı (ekrandan, 00:55:00).** Sınıfta bir kayıt cihazı ve ona bağlı bir mikrofon var. Cihaz, örnekleme frekansının ne olması gerektiğini soruyor. Konuşan kişi en yüksek 4 kHz çıkarıyorsa, sesinin karakteristiği kaybolmasın diye en az 8 kHz ile örneklemek gerekir:

- Verilen: $f_{max} = 4$ kHz
- $f_s = 2 \cdot 4 = 8$ kHz
- $T_s = 1/f_s = 1/8000$ s $= 125 \times 10^{-6}$ s $= 125\ \mu s$

Yani saniyenin milyonda birinin 125 katı aralıklarla örnek alınırsa ses karakteristiği kaybolmadan kaydedilir.

**EKG (derste sözlü, 01:15:16).** Bir EKG işaretindeki en yüksek frekans 500 Hz ise, sayısallaştırmak için en az $2 \cdot 500 = 1000$ Hz, yani 1 kHz ile örneklemek gerekir.

## 6. Nicemleme (Quantization)

### 6.1 Genlik ekseninde ayrıklaştırma

Örneklemeden sonra elimizde zaman ekseninde ayrık bir işaret vardır. Tahtada çubuklarla çizilse de aslında saklanan şey, her örnek anındaki genlik değeridir. Bu değerler sırayla hafızaya yazılır: birinci örnek bir göze, ikinci örnek sonraki göze.

**Soru:** Bu örnekleri hafızaya yazmanın önünde artık bir engel kaldı mı? Hoca cevabı açıkladı: Örneğin bir örneğin değeri 4,52 olsun. Yanındaki örnek 4,52325682... gibi virgülden sonra sonsuza kadar giden bir değer alabilir (ekrandan, 01:20:00). Hafıza ise 0 ve 1'leri tutar ve sınırlı sayıda bite sahiptir. Zaman ekseninde ayrıklaştırma yapıldı, ama genlik ekseninde (y ekseni) değerler hâlâ sonsuz sayıdadır. Bu yüzden genlik ekseninde de ayrıklaştırma yapılmalı: eksen küçük aralıklara bölünür ve her aralık 0 ve 1'lerle kodlanır.

### 6.2 Hafızanın iki boyutu

Hafızanın iki boyutu vardır:

- **Göz sayısı:** Örneğin 1024 göz 1 K eder; 1 GB gibi büyüklükler göz sayısını gösterir.
- **Bit derinliği:** Her göz 1, 2, 8, 16, 32 ya da 64 bitten oluşabilir. Göze yazılabilecek sayının büyüklüğünü bu belirler.

### 6.3 Bit eklendikçe daralan aralıklar

Hafıza gözü yalnız 1 bit olsaydı, genlik yalnız pozitif ve negatif diye ikiye ayrılabilirdi. Genlikleri birbirinden farklı olsa da örneklerin yalnız işaretleri görülebilirdi.

İkinci bit eklenince eksen dört parçaya bölünür ve aralıklar 00, 01, 10, 11 diye kodlanır (ekrandan, 01:25:00). Artık bazı örnekler birbirinden ayrılır, ama aynı aralığa düşen iki örnek (örneğin ikisi de 01) genlikleri farklı olsa bile ayrılamaz. Çözüm aralıkları daraltmaktır: her eklenen bit aralıkları yeniden böler. Hocanın anlattığı en basit biçimde en baştaki bit işaretin pozitif ya da negatif olduğunu, kalan bitler genliğin büyüklüğünü gösterir.

Bu aralıklara **kuanta aralıkları** denir. Hoca kimyadan bir benzetme yaptı: Atomun çevresindeki elektronlar arada değil, belli ayrık yörüngelerde bulunur; bunlara kuanta seviyeleri denir (ekrandan, 01:25:00). Aynı kuanta seviyesine denk gelen iki örnek aynı değerle kodlanır. Bit sayısı arttıkça onları ayırma şansı artar.

Zaman ekseninde yapılan ilk işlem **örnekleme (sampling)**, genlik ekseninde yapılan ikinci işlem **nicemleme (quantization)**'dir (ekrandan, 01:25:00).

### 6.4 Seviye sayısı ve gerilim karşılıkları

Kullanılan bit sayısı seviye sayısını belirler (ekrandan, 01:25:00):

- 8 bit: $2^8 = 256$ seviye. Hocanın anlatımıyla 127 seviye pozitif bölgede, bir sıfır seviyesi ve $-128$'e kadar negatif seviyeler.
- 16 bit: $2^{16} = 65.536$ seviye.

Bit sayısı arttıkça kuanta aralıkları daralır ve genlik daha kaliteli ifade edilir.

Bu kodlar belli gerilim seviyelerine karşılık gelir. Örneğin işaretin en yüksek genliği $+5$ V, en düşüğü $-5$ V olsun. Tahtada `0 1111111` kodu $+5$ V, `1 1111111` kodu $-5$ V'a karşılık yazıldı (ekrandan, 01:25:00). Toplam 10 V'luk aralık 8 bitle 256 parçaya bölünür; tahtada bu oran "10 V / ... = kuanta aralığı" diye gösterildi. Buna göre bir kuanta aralığı $10/256 \approx 0{,}039$ V, yani yaklaşık 39 mV olur (ara adım eklendi).

Ardından her örnek, düştüğü gerilime karşılık gelen ikili kodla hafızaya yazılır; tahtada birinci örnek için `010110`, ikincisi için `01101...` gibi kodlar gösterildi ve bu adım "Coding" diye işaretlendi (ekrandan, 01:25:00). Böylece analog bir büyüklük, 0 ve 1'lerle ifade edilebilen sayısal bir büyüklüğe dönüştürülmüş olur.

Hoca, burada işaret biti ve büyüklük mantığıyla anlattığını, ama negatif değerlerin gerçekte genellikle ikiye tümleyen (two's complement) biçiminde saklandığını belirtti. Lojik Devreler dersinde bunun sorulduğunu hatırlattı.

> **Ders sonrası not:** İşaret biti ve büyüklük gösteriminde 8 bit $-127$ ile $+127$ arasını kapsar ve iki ayrı sıfır kodu vardır. Hocanın söylediği $+127$, $0$, $-128$ aralığı ise ikiye tümleyen gösterimine aittir. Tahtadaki `1 1111111` = $-5$ V eşleşmesi işaret-büyüklük mantığına göredir.

Bundan sonra 0 ve 1'leri işleyen devreler gelir; bu, sayısal elektronik devrelerin ve lojik devrelerin girişidir.

## 7. Analog ve Sayısal Sistemler: Bozulma ve Gürültü

Hoca bu kısımdan sonra ders duvarına konan slaytlara geçti. İlk slayt dosyasında anlatılanlar özetle şunlardı: analog işaret, farklı kuanta seviyelerine ayrılmış dijital işaretler ve en sonunda 1 ve 0'ların saklandığı ikili (binary) işaretler. Analog işaret sayısallaştırıldığında, yani nicemlendiğinde artık sayısal işaret olarak adlandırılır.

**Analog ve sayısal sistem örneği.** Analog sistemde sürekli işaret (örneğin plaktan okunan ses) yalnızca yükseltilip hoparlöre verilir. CD mantığında ise hafıza bloklarından 1 ve 0'lar okunur, her biri belli bir genliğe karşılık getirilir ve orijinale benzer bir işaret oluşturulur. Sonra bu işaret yükseltilip (amplifier) hoparlöre verilir.

**Bozulma (distortion).** Elektriksel işaretlerde saf sinüs elde etmek zordur. Sinüzoidal bir işaret bazen tepesinden kırpılabilir ya da sıfır geçişlerinde bozulabilir. Bunların hepsi işareti işleyen elektronik sistemlerden kaynaklanır.

**Gürültü (noise).** Analog bir işaret bir hat üzerinden giderken sıcaklık ya da çevredeki başka elektronik ve manyetik kaynaklar gürültü ekleyebilir. Aynı hattan 0/1 bilgisi gitse de gürültü eklenebilir. Slayttaki bilgiler şunlardı (ekrandan, 01:30:00):

- Bütün sistemler içlerinden geçen işaretlere gürültü ekler.
- Bozulmadan farklı olarak gürültü **rastgeledir** ve tekrarlanamaz.
- Gürültü sayısal işaretlerden çoğu zaman temizlenebilir, ama analog işaretlerden temizlemek çoğu zaman imkânsızdır.

Hoca analog ve sayısal olmak üzere iki tür elektronik devre kurulabileceğini, bu konuların genel kültür için anlatıldığını söyledi. Gerçek sistemlerde gürültü olabildiğince bastırılır.

## 8. Sensörler, Eyleyiciler ve Ölçüm

### 8.1 Sensör ve eyleyici

**Sensör (algılayıcı):** Dış dünya bilgisini alıp elektriksel ya da başka bir büyüklüğe dönüştüren elemandır. **Eyleyici (actuator):** Sensörün tersine çalışır; aldığı elektriksel işareti hareket, ısı, ışık gibi fiziksel bir büyüklüğe dönüştürür. Örneğin bir step motora belli bir elektriksel işaret verilir ve motor belli bir oranda döner.

### 8.2 Ölçümde doğruluk ve netlik

Fiziksel büyüklükleri okumak için voltmetre, akım ölçer, osiloskop gibi aletler kullanılır. Ama bunlar da elektronik cihazlardır ve bir değeri tam olarak ölçemeyebilir; okumalar sapma gösterebilir.

- Ölçümler hep aynı değerin etrafında toplanıyor ama bu değer gerçek değerden farklıysa ölçümün **netliği (precision)** yüksek, **doğruluğu (accuracy)** düşüktür.
- İdeal durum, ölçümlerin hep gerçek değerin etrafında, aynı noktada toplanmasıdır.

Hoca bunu okçu benzetmesiyle anlattı: Okçu net atış yapıyor, okları hep aynı yere gidiyor, ama merkezi tutturamıyor. Bu hata oktan ya da hesaba katılmayan rüzgârdan kaynaklanıyor olabilir.

### 8.3 Sensör türleri

Mikrofon bir sensördür: havanın basıncından etkilenerek ses işaretini elektriksel işarete çevirir. Slayta göre bir malzemenin bir uyarıya göre değişen hemen her fiziksel özelliği sensör yapmak için kullanılabilir. Yaygın sensör türleri şunlardır (ekrandan, 01:35:00):

- rezistif (dirençsel)
- endüktif
- kapasitif
- piezoelektrik
- fotorezistif
- elastik
- termal

Hocanın verdiği örnekler:

- **Kapasitif:** Telefon ekranına dokunduğunuzda kapasite değeri değişir ve cihaz parmağınızın yerini anlar.
- **Rezistif:** Kalemle basılan yazı tabletlerinde basılan yerdeki direnç değişir, böylece konum bilgisi elde edilir.
- **Fotorezistif:** Sabah ışık gelmeye başladığında sokak lambalarını kapatan devreler.
- **Rezistif termometre ve termistör:** Direnci sıcaklıkla değiştiği için sıcaklık bilgisi başka bir büyüklüğe çevrilir.
- **pn eklemli yarı iletken sensörler ve fotovoltaik sensörler:** Bir penceresi olan fotovoltaik eleman, gelen ışığın şiddetine göre gerilim üretir. Bu gerilim sayısallaştırılarak karar destek sistemleri kurulabilir. Işık şiddetiyle iletkenliği değişen yapılar da vardır.
- **Basınç (kuvvet) sensörleri:** Uygulanan basınca göre direnci değişir.
- **Opto-anahtarlar (opto-switch):** Bir taraf ışık gönderir, karşı taraf alır. Eski mekanik farelerde ortasında delikli bir halka bulunan disk vardı. Biri x, biri y yönü için iki opto-anahtar kullanılır, ışık deliklerden geçtikçe hareketin yönü ve hızı anlaşılırdı. Fare 45° yönünde gidiyorsa iki disk de dönerdi. Sonra lazerli farelere geçildi.
- **Pozisyon kodlayıcıları (encoder):** Örneğin bir motorun hangi konumda olduğunu gösterir. Endüktif olanlar manyetik, optik olanlar ışıkla çalışır.
- **Ses sensörü:** Mikrofon; çıkışında bir gerilim üretir.

### 8.4 Rezistif sensörün devreye bağlanması

Slayttaki devrede sabit bir $V$ gerilimi ile $0$ V arasına bir $R_1$ direnci ve direnci ölçülen büyüklükle değişen sensör $R_s$ seri bağlanmıştır. Çıkış $V_o$ ikisinin birleşim noktasından alınır (ekrandan, 01:40:00). Böylece direnç değişimi bir gerilim bölücüyle gerilim işaretine çevrilir. Slayta göre bu düzenlemenin çıkışı direnç değişimiyle doğrusal olarak ilişkili değildir. Hoca bu kısmı ileriki derslerde ayrıntılı anlatacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu gerilim bölücüde çıkış $V_o = V \cdot \dfrac{R_s}{R_1 + R_s}$ olur. $R_s$ paydada da bulunduğu için $V_o$, $R_s$ ile doğrusal değişmez; slayttaki "doğrusal değildir" ifadesinin nedeni budur.

### 8.5 Eyleyici örnekleri

- **Rezistif ısıtıcı:** Elektriksel işaret verilir, ısı olarak geri döner.
- **Işık eyleyicileri:** Ampuller hem ışık hem ısı verir. En çok kullanılanlardan biri LED'dir (Light Emitting Diode, ışık yayan diyot).
- **Fiber optikler.**
- **Solenoidler:** Verilen elektriksel işarete göre konum değiştirir; otomatik kapı kilitleri gibi.
- **Ölçü aletleri (metreler):** Elektriksel işareti, onun miktarını gösteren bir harekete dönüştürür.
- **Motorlar:** AC, DC ve step motorlar.

**DC motor ile step motor farkı.** DC motora belli bir gerilim verildiğinde döner; gerilimin büyüklüğü değiştirilirse hızı değişir, düşük gerilimde daha yavaş döner. Step motorda ise belli açılar tanımlıdır. Motoru bir konumdan sonrakine geçirmek için uçlarına belli bir 0/1 dizisi verilir. Böylece iki birim ileri, bir birim geri gibi hassas hareketler ya da belli bir senkron hızla çalışma sayısal bilgiyle sağlanır.

## 9. İdeal Diyot

### 9.1 Diyot sembolü ve gerilimi

Elektronik devrelerde ilk görülecek eleman diyottur. Diyot **iki uçlu** (iki bacaklı) bir devre elemanıdır (ekrandan, 01:45:00). Sembolde üçgenin olduğu taraf artı ucu, dikine çizilen çizginin olduğu taraf eksi ucunu gösterir.

Bir elemanın üzerindeki gerilim, giriş ve çıkış uçlarındaki gerilimlerin farkıdır. Artı kabul edilen uç A, eksi kabul edilen uç B ise (ekrandan, 02:05:00):

$$V_D = V_A - V_B$$

### 9.2 İdeal diyotun davranışı

İdeal diyot akımı yalnız tek yönde geçirmek üzere tasarlanmıştır (ekrandan, 01:45:00):

- Artı uç (A) eksi uçtan (B) $\varepsilon$ kadar yüksek olduğunda, yani $V_D = 0 + \varepsilon$ olduğunda diyot **kısa devre** gibi davranır. Hiç direnç göstermediği için akım anında geçmeye başlar; akımın değerini diyot değil, dış devre sınırlar.
- Bunun dışında, yani $V_A \leq V_B$ iken diyot **açık devre** gibi davranır ve $I_D = 0$ olur.

> **Ders sonrası not:** Altyazıda bu kısım "eksi taraftan yüksek olduğu zaman" diye geçiyor. Bağlama ve slayta göre doğrusu, artı ucun (A) eksi uçtan yüksek olduğu durumdur.

Slayttaki iki bölge (ekrandan, 01:50:00):

| | İletim bölgesi (conduction) | İletim yapmayan bölge (non-conduction) |
|---|---|---|
| Diyot gerilimi | 0 V | Bütün gerilim diyotun üzerindedir |
| Akım | Sonsuz (dış devreyle sınırlı) | 0 A |
| Direnç | İleri yön direnci $R_F = V_F / I_F$ | Ters yön direnci $R_R = V_R / I_R$ |
| Davranış | Kısa devre | Açık devre |

Hoca karakteristikte $\varepsilon$'un çok küçük olduğunu, slaytta eğrinin tam sıfırdan dikildiğini, aslında $\varepsilon$ kadar sağdan dikilmesi gerektiğini ama bu farkın ihmal edilebileceğini söyledi.

### 9.3 İdeal karakteristik ve sayısal örnek

İki bölge birleştirilince ideal karakteristik elde edilir. Diyotun artı ucuna voltmetrenin artı ucu, eksi ucuna voltmetrenin eksi ucu bağlanmış gibi düşünülür. Yatay eksen $V_D$, dikey eksen diyottan geçen akım $I_D$'dir.

$V_D \leq 0$ bölgesinde diyot üzerinde ne gerilim düşüyorsa o ölçülür ve akım akmaz. Hoca bunu sayılarla gösterdi (derste sözlü, 01:50:27):

- B ucunda 5 V, A ucunda 4 V olsun: $V_D = V_A - V_B = 4 - 5 = -1$ V. Diyot açıktır, akım akmaz.
- B ucu 6 V olursa $V_D = 4 - 6 = -2$ V.
- B ucu 7 V olursa $V_D = 4 - 7 = -3$ V.

Daha önce de A ucu 0 V, B ucu 1 V olduğunda $V_D = -1$ V olduğu, ikisi de 0 V ise $V_D = 0$ olduğu söylendi. $V_B$, $V_A$'dan büyük olduğu sürece diyot iletmeyen bölgededir. $V_D$ sıfırı biraz geçince akım hızla akmaya başlar.

## 10. Yarı İletkenler ve pn Eklemi

### 10.1 Yarı iletken malzemeler ve katkılama

Bilgisayar mühendisliğinin doğuşu, yarı iletken teknolojilerinin gerçekleşmesi ve ucuzlamasıyla başlar. Temel yarı iletken malzemeler silisyum (Si), germanyum (Ge) ve galyum arsenittir (GaAs).

Hoca bu kısmı hızlı geçti ve ayrıntıları ders kitabının ilgili bölümünden okumaya bıraktı; konu, yarı iletken fiziği dersinin bir tekrarı niteliğindedir.

Temel adımlar şunlardır:

- Silisyum, germanyum ya da galyum arsenit saflaştırılır ve saf bloklar halinde elde edilir.
- **Katkılama (doping):** Saf malzemenin elektriksel karakteristiğini değiştirmek için içine başka malzemeler eklenir. Hoca bunu spordaki "doping" kelimesine benzetti.
- Katkılamayla yalnız iki tip malzeme elde edilir (ekrandan, 02:00:00):
  - **n tipi:** İletim bandında fazla elektron bulunur; malzeme fazladan eksi yük taşıyıcısına sahiptir.
  - **p tipi:** Valans bandında fazla delik (hole) bulunur.

### 10.2 pn eklemi ve geçiş bölgesi

p tipi ve n tipi malzeme birbirine yapıştırılınca **pn eklemi** (pn junction) oluşur; "junction" eklem demektir. Eklemde n tarafındaki elektronlar p tarafına geçer. Bunun sonucunda eklemin p tarafında negatif, n tarafında pozitif yük birikir ve bir **geçiş bölgesi** (depletion region) oluşur. Yükler arasındaki bu fark bir **potansiyel bariyeri** yaratır. Hoca, yüklenmemiş (dışarıdan gerilim uygulanmamış) durumda p tarafının potansiyelinin n tarafından düşük olduğunu, iletime geçmek için bu potansiyelin aşılması gerektiğini söyledi.

### 10.3 İleri ve ters kutuplama

Diyot iki uçlu olduğu için bir gerilim kaynağıyla beslenebilir; devre tamamlansın ve diyot yanmasın diye seri bir direnç eklenir (ekrandan, 02:05:00). $V_D = V_A - V_B$ tanımıyla:

- **İleri kutuplama (forward bias):** $V_D$ pozitif, yani $V_A > V_B$. p tarafına artı, n tarafına eksi verilir.
- **Ters kutuplama (reverse bias):** $V_B > V_A$; iletim yoktur.

İleri kutuplamada p tarafına artı verildiği için geçiş bölgesi daralır ve potansiyel bariyeri düşer. Slayttaki maddeler (ekrandan, 02:05:00):

- p tipi taraf n tipi tarafa göre pozitif yapılırsa bariyerin yüksekliği azalır.
- Daha fazla çoğunluk taşıyıcısı bariyeri aşacak enerjiye sahip olur.
- Difüzyon akımı artar, sürüklenme (drift) akımı aynı kalır.
- Böylece eklemden, uygulanan gerilimle artan net bir akım akar.

Hoca, akımın p'den n'ye doğru aktığını, bariyer indirildiği için taşıyıcıların daha rahat geçtiğini anlattı. <!-- BELİRSİZ: Altyazıda 02:06:06'da "P'den N'ye doğru bir akım akmıyor" geçiyor; bağlama göre büyük olasılıkla "akıyor" söylenmiştir. -->

Ters kutuplamada ise p tarafındaki eksi yükler artar, geçiş bölgesi kalınlaşır ve bariyer yükselir; iletim olmaz.

### 10.4 Gerçek diyot karakteristiği

İleri kutuplamada $V_A$, $V_B$'den ne kadar büyükse bariyer o kadar iner ve akım o kadar rahat akar. İdeal diyotta akım $\varepsilon$ geriliminde başlar. Gerçek diyotta ise bariyer gerilimi aşılmalıdır:

- Silisyum: yaklaşık 0,7 V
- Germanyum: yaklaşık 0,3 V

Silisyumda 0,7 V'a kadar akım çok küçüktür; 0,7 V civarında bir kırılma olur ve akım hızla artar.

> **Ders sonrası not:** Hoca galyum arsenit için değerin 0,9 V mu 1,3 V mu olduğundan emin olamadı ve sonra bakılacağını söyledi. Ders kitabında (Boylestad) bu değer büyük olasılıkla 1,2 V olarak verilir.

Gerçekte ters kutuplamada da akım tamamen sıfır değildir. Küçük bir **sızıntı akımı** akar, ama bu, diyotun akımı geçirdiği anlamına gelmez. Yani ideal karakteristikte ters yönde akım sıfır iken gerçek karakteristikte negatif yönde küçük bir akım vardır.

Hoca son olarak ders kitabının ilgili bölümünü ekranda gösterirken diyot direnç seviyelerine de değindi. Ekrandaki tabloda DC (statik) direnç $R_D = V_D / I_D$, AC (dinamik) direnç $r_d = \Delta V_d / \Delta I_d = 26\text{ mV} / I_D$ ve ortalama AC direnç $r_{av} = \Delta V_d / \Delta I_d$ (iki nokta arası) olarak verilmişti (ekrandan, 01:55:00). Diyotun üç çalışma koşulu (gerilim uygulanmamış, ileri kutuplama, ters kutuplama) bir sonraki derste ayrıntılı işlenecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:29:45): Örnekleme periyodu $T_s$'yi küçültmenin, yani daha sık örnek almanın avantajı ve dezavantajı nedir? Tersine $T_s$'yi büyütmenin?

> **Çözüm (derste verildi):** $T_s$ küçülünce işaret orijinaline yaklaşır, ama bellekte kapladığı alan, işlemci yükü ve hesapsal karmaşıklık artar. $T_s$ büyüyünce bellek kullanımı azalır, ama örnekler arasındaki değişimler kaçırılır ve işaret orijinalden uzaklaşır.

**Soru 2** (derste sözlü, 00:38:07): Frekansı sözel olarak tanımlayınız.

> **Çözüm (derste verildi):** Frekans, birim zamanda (genellikle bir saniyede) işaretin kaç kez başlayıp çevrimini tamamladığıdır; $f = 1/T$.

**Soru 3** (ekrandan, 00:40:00): Bir sinüzoidal işaretin periyodu $T = 1$ s ise frekansı nedir? Aynı sürede iki çevrim tamamlanıyorsa ($T = 0{,}5$ s) frekans ne olur?

> **Çözüm (derste verildi):** $f = 1/1 = 1$ Hz; $f = 1/0{,}5 = 2$ Hz.

**Soru 4** (derste sözlü, 00:50:34): En yüksek frekanslı bileşenden yalnız pozitif ve negatif tepe noktalarında örnek alınıyorsa $T_s$ ile $T_{max}$ arasındaki ilişki nedir?

> **Çözüm (derste verildi):** $T_s = T_{max}/2$, yani $T_{max} = 2T_s$ ve $f_s = 2f_{max}$. Çevrim başına dört örnek alınırsa $T_{max} = 4T_s$ ve $f_s = 4f_{max}$ olur (ekrandan, 00:55:00).

**Soru 5** (ekrandan, 00:55:00): Sınıftaki bir kayıt cihazı konuşmayı kaydedecektir. Konuşan kişinin sesi en yüksek 4 kHz frekans içeriyorsa örnekleme frekansı ve örnekleme periyodu ne olmalıdır?

> **Çözüm (derste verildi):** $f_s \geq 2 \cdot 4 = 8$ kHz. $T_s = 1/8000$ s $= 125\ \mu s$.

**Soru 6** (derste sözlü, 01:15:16): Bir EKG işaretinde en yüksek frekans 500 Hz'dir. Bu işaret en az hangi frekansla örneklenmelidir?

> **Çözüm (derste verildi):** $f_s \geq 2 \cdot 500 = 1000$ Hz $= 1$ kHz.

**Soru 7** (derste sözlü, 01:16:37): Örnekleme yapıldıktan sonra örneklerin genlik değerlerini hafızaya yazmanın önünde bir engel var mıdır?

> **Çözüm (derste verildi):** Evet. Genlik ekseninde değerler hâlâ süreklidir (örneğin 4,52325682...), ama hafıza gözü sınırlı sayıda bit tutar. Bu yüzden genlik ekseni de kuanta aralıklarına bölünmeli (nicemleme) ve her aralık ikili bir kodla ifade edilmelidir.

**Soru 8** (derste sözlü, 01:50:27): Bir diyotun A (artı) ucunda 4 V, B (eksi) ucunda 5 V vardır. $V_D$ nedir, diyot iletir mi? B ucu 6 V ve 7 V olursa?

> **Çözüm (derste verildi):** $V_D = V_A - V_B = 4 - 5 = -1$ V; diyot açık devredir, akım akmaz. B ucu 6 V olursa $V_D = -2$ V, 7 V olursa $V_D = -3$ V; her iki durumda da diyot iletmez.

## Dersin Toparlaması

Bu derste analog bir işaretin sayısal hale getirilmesinin iki adımı ayrıntılı işlendi. Önce zaman ekseninde örnekleme yapılır. Örnekleme periyodunun seçimi, kaynak kısıtları ile bilgi kaybı arasındaki bir ödünleşimdir. Fourier analizine göre her işaret sinüzoidallerin toplamı olduğu ve doğal işaretlerin bir en yüksek frekansı bulunduğu için, en kötü durum en yüksek frekanslı bileşende çevrim başına iki örnektir. Buradan $f_s \geq 2f_{max}$ kuralına varıldı. Ardından genlik ekseninde nicemleme yapılır: bit sayısı kuanta aralıklarının sayısını belirler (8 bit 256, 16 bit 65.536 seviye) ve her örnek ikili kodla hafızaya yazılır.

Dersin ikinci yarısında slaytlar üzerinden bozulma ve gürültü, sensör ve eyleyici türleri ile ölçümde doğruluk ve netlik kavramları genel bilgi olarak anlatıldı. Son kısımda dersin asıl konularına geçildi: ideal diyotun tek yönlü iletimi, $V_D = V_A - V_B$ tanımı, katkılama, pn eklemi, ileri ve ters kutuplama ile silisyum ve germanyum için eşik gerilimleri. Bir sonraki derste diyotun çalışma koşulları ile devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
