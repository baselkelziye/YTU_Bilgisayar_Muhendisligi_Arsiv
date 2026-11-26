# Ders 3 Genişletilmiş Notu: Analogdan Sayısala: Örnekleme, Nyquist Ölçütü, Nicemleme; Sensörler ve Aktüatörler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynak Kitabı
- 2. Analog Dünya ve Sayısal Dünya
- 3. Sensörden Örneklemeye
- 4. Sinüzoidal İşaretler
- 5. DC ve AC İşaretler
- 6. Fourier Analizi ve Bant Sınırı
- 7. Örnekleme Frekansının Seçimi: Nyquist Ölçütü
- 8. Nicemleme (Quantization)
- 9. Elektronik Devrelerin Yeri
- 10. Sensörler ve Aktüatörler
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kaynak Kitabı

Dersin ana kaynağı Robert Boylestad'ın *Electronic Devices and Circuit Theory* kitabıdır. Kitabın çeşitli baskıları vardır ve Türkçe çevirisi de bulunmaktadır. Derste bu kitabın slaytları ve sorular için ayrı slaytlar kullanılır. Bu ders, bir önceki haftadaki genel girişin devamıdır: Elektronik devrelere neden ihtiyaç duyulduğu sorusu, sinyallerin analog dünyadan sayısal dünyaya nasıl aktarıldığı üzerinden cevaplanır.

## 2. Analog Dünya ve Sayısal Dünya

Hoca tahtaya bir dünya çizip altına "Analog (sürekli)" yazdı, yanına da içinde mikroişlemci (µP) ve mikrodenetleyici (µC) olan bir bilgisayar ve bir hafıza bloğu çizdi (ekrandan, 00:15:00). Bu iki taraf dersin çatısını oluşturur.

### 2.1 Sürekli işaretler

Yaşadığımız dünya süreklidir. Bir sınıfta konuşan hocanın sesi öğrencinin kulağına zamanın her anında, kesintisiz gelir. Bu, bir boyutlu bir işarettir: $x(t)$, zamanın fonksiyonu.

İnsan görme sistemi ise iki boyutlu işaretlerle çalışır. Göz, standart piksellerden oluşmuş sayısal bir görüntü almaz; beyinde sürekli bir görüntü oluşur. Hoca burada "nokta demek bile yanlış" dedi: görüntü düzlemin her yerinde tanımlıdır. İki boyutlu düzlemdeki bu verilere mekânsal ya da uzamsal (spatial) veriler denir; bu düzlemde komşuluk ilişkileri vardır (ekrandan, 00:15:00).

Daha fazla boyut da olabilir. Bir MR cihazı vücudun her noktasında kesit alır; bu kez $x$ ve $y$'nin yanına $z$ eklenir. Bu tür işaretlere N boyutlu işaretler denir (ekrandan, 00:20:00). Termometre de benzer bir örnektir: Biz bakmasak bile sıcaklık zamanın her anında tanımlıdır.

### 2.2 Sayısal sistemler

Bu verileri işlemek için sayısal sistemlere ihtiyaç vardır. Burada sayısal sistemden kastedilen, işlem gücü olan (içinde mikroişlemci ya da mikrodenetleyici bulunan) ve bir hafıza birimine sahip yapıdır. Hoca bunun yalnız masaüstü ya da dizüstü bilgisayar olarak düşünülmemesini istedi: Cep telefonu, tablet ve içinde mikroişlemci bulunup hafızayla dış dünya verilerini işleyebilen, algoritma çalıştırabilen her cihaz bir "computer"dır. Hocaya göre İngilizce "compute" hesaplamak demek olduğundan "hesaplayıcı" çevirisi "bilgisayar"dan daha isabetlidir.

Bu sayısal dünyada bilgi artık ayrıktır (discrete): veriler ayrıklaştırılmıştır (ekrandan, 00:20:00).

## 3. Sensörden Örneklemeye

### 3.1 Sensör

Analog dünyadan sayısal dünyaya geçerken ilk ihtiyaç bir sensördür (algılayıcı). Bir ses işaretini bilgisayara kaydetmek için mikrofon gerekir. İki boyutlu veriler için fotoğraf makinesi örnek verildi: Analog makinede görüntü film şeridine kaydedilir, sonra tarayıcıyla sayısallaştırılır; sayısal fotoğraf makinesi ise bu iki adımı birlikte yapar, odağına gelen bilgiyi alıp piksellere çevirir. MR cihazı da aslında bir sensördür. Genel olarak, dış dünyadaki bir büyüklüğü alıp işleyen ve sayısallaştıran yapının ilk kısmı sensör kısmıdır.

### 3.2 Neden örnekleme gerekir?

Mikrofon sesi elektriksel bir işarete çevirir, ama bu işaret hâlâ süreklidir. Hoca tahtada $x(t)$ işaretini çizip 0, 0,5 ve 1 saniye noktalarını işaretledi (ekrandan, 00:20:00): 0 ile 1 saniye arasında sonsuz değer vardır; 0 ile 0,5 arasında da sonsuz değer vardır, çünkü işaret zamanın her anında tanımlıdır. Bu yüzden ayrık dünyaya geçmek için işaretten, olabildiğince asıla sadık kalarak, örnekler almak gerekir. Bu işleme örnekleme (sampling) denir.

İki boyutlu işaretlerde örnekler $x$ ve $y$ yönünde alınır. Bu örneklere piksel denir (ekrandan, 00:20:00, tahtadaki dikdörtgenin içindeki noktalar). Anlatımı kolaylaştırmak için ders bundan sonra ses işareti üzerinden ilerledi.

### 3.3 Sık ve seyrek örnekleme

Örnekler geniş aralıklarla da alınabilir, çok sık da alınabilir. Hoca bunun avantaj ve dezavantajlarını öğrencilere sordu.

**Soru:** Çok sık örnek almanın avantajı ve dezavantajı nedir? **Cevap:** Avantajı, işaret asıla daha yakın saklanır. Dezavantajı, daha çok nokta olduğu için hafızada daha fazla yer gerekir. Hoca buna bir dezavantaj daha ekledi: Mikroişlemci ya da mikrodenetleyici daha çok veri noktasıyla uğraşacağı için hesaplama karmaşıklığı (computational complexity) da artar.

**Soru:** Seyrek örnek almanın dezavantajı nedir? **Cevap:** Ayrıntı kaybolur, ama yerden tasarruf edilir. Hoca tahtada bunu gösterdi (ekrandan, 00:25:00): Seyrek örneklerde işaretin hızlı inip çıktığı bölgeler (tahtada daire içine alınmış bölgeler) arada kalır. Bu değişim noktaları kaybolunca sesin ya da işaretin önemli karakteristikleri de kaybolabilir.

Örnekler eşit $T$ aralıklarla alınır. Örnekleme yapıldığı için bu periyoda $T_s$ (sampling period, örnekleme periyodu) denir (ekrandan, 00:25:00).

### 3.4 Mühendislik sorusu: optimal $T_s$

Sensörle işaret elektriksel hale getirildi, ardından örneklendi; sonunda bilgisayarda 1'ler ve 0'lar saklanacak. Hoca "mühendislik açısından ilk sorumuz ne olur?" diye sordu. Bir öğrenci "periyodumuz en az ne olmalı?" dedi; hoca bunu doğruladı.

$T_s$ çok geniş seçilirse bilgi kaybolur, çok sık seçilirse hafıza ve işlem yükü artar. Amaç, $T_s$'yi olabildiğince geniş seçerken aradaki bilgi kaybını olabildiğince azaltmaktır; yani $T_s$'nin optimal seçimi (tahtada "optimal?", ekrandan 00:25:00). Fotoğrafta uygulamaya göre piksel sıklığının ne olacağı sorusu da aynı sorudur. Hocaya göre bu sorunun cevabı Fourier analizinden gelir. Fourier analizine geçmeden önce sinüzoidal işaretler incelendi.

## 4. Sinüzoidal İşaretler

### 4.1 Sinüsü belirleyen parametreler

Hoca "bir sinüsü diğer sinüsten ayıran değişkenler neler?" diye sordu ve genel ifadeyi tahtada adım adım kurdu (ekrandan, 00:30:00 ve 00:35:00):

$$x(t) = A \sin(2\pi f t + \varphi)$$

Burada $A$ genlik, $f$ frekans, $\varphi$ fazdır; bağımsız değişken zaman $t$'dir.

**Genlik.** Normalde $\sin$ fonksiyonu $-1$ ile $1$ arasında değer alır. Başına bir $A$ çarpanı konunca işaret $-A$ ile $A$ arasında salınır. Örneğin $A = 3$ ise işaret $-3$ ile $3$ arasında değer alır. Tahtada genliği $A$ olan bir sinüs ile genliği $B$ olan, daha küçük ve daha sık salınan bir sinüs yan yana çizildi (ekrandan, 00:30:00).

**Periyot ve frekans.** Sinüs kendini tekrar eder. Kendini tekrar ettiği bir aralığa çevrim (cycle) denir; bu çevrimin süresine periyot denir. Periyodun birimi zaman, yani saniyedir. Frekans ise bir saniyede tamamlanan çevrim sayısıdır; birimi Hz'dir. Periyot ile frekans ters orantılıdır:

$$T = \frac{1}{f}$$

Örneğin 5 Hz'lik bir işaret bir saniye içinde çevrimini 5 kez tamamlar; periyodu $1/5 = 0{,}2$ s'dir (ara adım eklendi). 100 Hz'lik bir işaret saniyede 100 kez salınır. Frekans ifadeye $2\pi f t$ olarak girer.

**Faz.** Bir sinüs illa sıfırdan başlamak zorunda değildir; başlangıçta kaydırılmış olabilir. Bu başlangıç kaymasına (offset) faz denir ve $\varphi$ ile gösterilip argümana toplamsal olarak eklenir. Faz açı cinsinden ifade edilir: Tam bir periyot $360^\circ$ ya da $2\pi$ radyandır.

### 4.2 Sinüs ve kosinüs aynı işarettir

Hoca tahtada biri tepe noktasından (I), biri sıfırdan (II) başlayan iki işaret çizdi ve aralarındaki faz farkını sordu (ekrandan, 00:35:00). Aradaki kayma bir periyodun dörtte biridir:

$$\frac{360^\circ}{4} = 90^\circ, \qquad \frac{2\pi}{4} = \frac{\pi}{2}$$

360 derecelik bir fark olsaydı işaret kendisiyle çakışırdı; yarım periyotluk fark olsaydı işaret ters dönmüş görünürdü. I numaralı işaret kosinüs, II numaralı işaret sinüstür. Buradan önemli bir sonuç çıkar: Sinüs ve kosinüs birbirinden ayrı iki işaret değildir. Aynı sinüzoidal biçimin faz kaydırılmış halleridir.

> **Hocanın vurgusu:** Kosinüs ve sinüs, frekansları ve genlikleri aynı, faz farkları $90^\circ$ olan iki işarettir. Bu aklımızda kalsın.

### 4.3 Periyot ve frekans karşılaştırması

Hoca biri yavaş, biri hızlı salınan iki işaret çizip periyotları ve frekansları hakkında ne söylenebileceğini sordu (ekrandan, 00:40:00). Tahtada üstteki yavaş işaret için $T_1 = 1/F_1$, alttaki hızlı işaret için $T_2 = 1/F_2$ yazılıdır. Bir öğrenci ikincinin frekansının, birincinin periyodunun daha yüksek olduğunu söyledi. Hoca bunu şöyle yorumladı: Periyot büyükse frekans ($1/T$) küçüktür; periyot küçükse frekans yüksektir. Frekansın yüksek olması, aynı zaman aralığında işaretin daha çok titreşmesi, daha çok çevrim yapması demektir.

## 5. DC ve AC İşaretler

Hoca "genel kültür" diyerek evdeki prizlerden alınan güç işaretinin sabit mi yoksa salınan bir işaret mi olduğunu sordu. Cevabı Fourier anlatımındaki $f = 0$ durumuyla bağladı:

- $f = 0$ ise işaret salınım yapmaz. Bunlara DC (Direct Current, doğru akım) işaretler denir. DC işaret zamanla sabit bir değer alır.
- $f > 0$ olduğu andan itibaren işaret salınır. Bunlara AC (Alternating Current, alternatif akım) işaretler denir (ekrandan, 00:40:00).

DC örneği bir pildir: 1,5 V'luk bir pilin uçlarına voltmetre bağlanırsa zamanla sabit 1,5 V görülür. Pil zamanla zayıflar, ama hoca bunun ayrı bir konu olduğunu belirtti.

Prizden ise AC işaret alınır; adaptörler bunu cihazların kullandığı DC'ye çevirir. Hoca, telefon şarj aletlerinin, bilgisayar ve monitör adaptörlerinin üstünde bu değerlerin yazdığını hatırlattı. Türkiye'de prizdeki işaretin genliği 220 V, frekansı 50 Hz'dir. ABD'de ise 110 V ve 60 Hz kullanılır. Değerler ülkeden ülkeye değişir; Avrupa standardı genellikle 50 Hz'dir.

> **Ders sonrası not:** Hoca 220 V'u işaretin "genliği" olarak andı. Şebeke gerilimi için verilen 220 V (bugün büyük olasılıkla 230 V) etkin (RMS) değerdir; tepe genliği bunun $\sqrt{2}$ katı, yaklaşık $220\sqrt{2} \approx 311$ V'tur.

## 6. Fourier Analizi ve Bant Sınırı

### 6.1 Fourier'nin sorusu ve cevabı

Fourier 1800'lerin başında yaşamıştır ve o zaman işaret işlemeyle ilgilenmemiştir. Sorduğu soru matematikseldir: Keyfi (arbitrary) bir fonksiyon nasıl ayrıştırılabilir? Cevabı şudur: Keyfi bir fonksiyon, frekansı 0'dan sonsuza kadar değişen sinüzoidallerin toplamı olarak ifade edilebilir (ekrandan, 00:45:00).

Hoca tahtada keyfi bir $x(t)$ çizdi ve eşittir işaretinin altına bileşenleri sıraladı: önce $f = 0$ olan düz bir çizgi (DC), sonra düşük frekanslı bir sinüs, sonra daha yüksek frekanslı bir sinüs; aralarına ve sonuna "+ ... +" ve "$\infty$" koydu. $f$ sürekli bir değişkendir: Değerleri 1, 2, 3 diye gitmek zorunda değildir, 1,258 ya da 1,2581 olabilir. Bu yüzden aralara üç nokta konmuştur.

DC bileşen işaretin ortalamasıdır. AC bileşenlerin ortalaması sıfırdır; bunlar DC bileşenin üstüne binerek asıl işareti oluşturur. Her bileşenin kendi genliği ve fazı vardır. Frekans sürekli olduğu için toplam integrale dönüşür; hoca bunu sözlü olarak şöyle ifade etti:

$$x(t) = \int_{0}^{\infty} A(f)\, \sin\big(2\pi f t + \varphi(f)\big)\, df$$

<!-- BELİRSİZ: İntegral ifadesi altyazıda bozuk geçiyor ("Sinus 2PF T artı PF DF") ve bu anın karesi yok; yukarıdaki yazım hocanın sözlü anlatımından kurulmuştur. -->

Yani $x(t)$, frekansı 0'dan sonsuza kadar olan, her biri o frekansa ait genlik ve fazdaki bileşenlerden oluşur.

### 6.2 Gerçek işaretler bant sınırlıdır

**Soru:** Gerçek hayatta frekansın sonsuza gitmesi mümkün müdür? **Cevap:** Değildir. İnsan sesi, ses tellerinin titreşiminden kaynaklanan ve yaklaşık 0 ile 4 kHz arasında yer alan bileşenlerden oluşur. Kişiden kişiye değişir; kimisinde 5 kHz'e çıkar, kimisinde 3,5 kHz'e iner, ama sesin karakteristiği yaklaşık 0-4 kHz arasındadır. Hoca kalp işareti için de yaklaşık 0-360 Hz aralığını verdi. Yani insan sesinde 10 kHz'lik, kalp işaretinde 700 Hz'lik bir bileşen bulunmaz.

Kaynaktan gelen bu sınırlamalar yüzünden her gerçek işaretin bir bant sınırı, yani bir en yüksek frekansı $F_{max}$ vardır. $F_{max}$'tan sonraki frekanslarda bileşenlerin genliği sıfırdır.

### 6.3 Hızlı ve yavaş değişim

Hoca işaretin bir bölümüne "büyüteç tutarak" yeniden çizdi (ekrandan, 00:50:00). İşaretin içinde az değişen yerler genellikle düşük frekanslı bileşenlerden, hızlı değişen yerler yüksek frekanslı bileşenlerden gelir. Dolayısıyla örnekleme, işaretin hızlı değişen bölgelerindeki değerleri kaybetmemelidir. Örnekleme periyodu yüksek frekansları karşılıyorsa düşük frekansların karakteristiklerini zaten rahatça karşılar.

## 7. Örnekleme Frekansının Seçimi: Nyquist Ölçütü

### 7.1 En kötü durum: yalnız tepe noktaları

En yüksek frekanslı bileşenin periyodu tanımlanır (ekrandan, 00:55:00):

$$T_{max} = \frac{1}{F_{max}}$$

Hoca önce bu bileşenin yalnız tepe noktalarından (bir tepe, bir çukur) örnek alacak bir aralık seçti. İki ardışık örnek arası $T_s$'dir.

**Soru:** Bu çizime göre $T_s$ ile $T_{max}$ arasında nasıl bir ilişki var? **Cevap:** Bir öğrenci $T_{max}/2 = T_s$ dedi. Hoca bunu $T_{max} = 2T_s$ biçiminde yazdı, çünkü $T_s$ çevrimin yarısı kadardır. Frekans cinsinden:

$$T_{max} = 2T_s \;\Rightarrow\; F_s = 2F_{max}$$

Bu en kötü durum senaryosudur. $F_{max}$ bileşeninde bir periyot boyunca yalnız iki örnek alınır; daha düşük frekanslı bileşenlerde ise bir periyot boyunca çok daha fazla örnek alınmış olur. Yani en kötü durum $F_{max}$'ta oluşur. $F_{max}$ bileşeninin yalnız tepe noktaları işareti yeniden kurmak için yeterli görülürse (en azından üçgen biçiminde), bu bir alt sınır oluşturur.

### 7.2 Daha sık örnekleme

Tepe noktalarına ek olarak sıfır geçişlerinden de örnek alınırsa bir periyotta iki yerine dört örnek olur.

**Soru:** Geçiş noktaları da alınırsa $T_s$ ile $T_{max}$ ilişkisi ne olur? **Cevap:** Bir öğrenci "bölü 4" dedi. Hoca yazdı (ekrandan, 00:55:00):

$$T_{max} = 4T_s \;\Rightarrow\; F_s = 4F_{max}$$

Ara değerler de alınarak $8F_{max}$, $16F_{max}$ yapılabilir. Bunun üst sınırı yoktur; sıklaştıkça en yüksek frekanslı bileşen de daha iyi örneklenir. Ama en kötü durum $2F_{max}$'tır. Bu yüzden eşitlik yerine eşitsizlik yazılır:

$$F_s \geq 2F_{max}$$

Örnekleme frekansı (sampling frequency) $F_s = 1/T_s$, işaretin içindeki en yüksek frekansın en az iki katı olmalıdır. Hoca bu sınıra, onu bulan kişinin adından dolayı Nyquist frekansı denildiğini söyledi (ekrandan, 01:00:00).

> **Hocanın vurgusu:** Bir işareti örnekleyeceksek örnekleme frekansı, işaretin içindeki maksimum frekansın en az iki katı olmak zorundadır.

> **Ders sonrası not:** Hoca $2F_{max}$ sınırına "Nyquist frekansı" dedi. Literatürde bu sınır büyük olasılıkla "Nyquist hızı" (Nyquist rate) olarak, $F_s/2$ değeri ise "Nyquist frekansı" olarak geçer. Ayrıca örnekleme kuramı tam yeniden oluşturma için kesin büyüklük ($F_s > 2F_{max}$) ister: Tam $2F_{max}$'ta örnekler en yüksek frekanslı bileşenin sıfır geçişlerine denk gelirse o bileşen hiç görülmez.

> **Ek bilgi (derste anlatılmadı):** $F_s < 2F_{max}$ seçilirse yüksek frekanslı bileşenler örneklendikten sonra daha düşük frekanslıymış gibi görünür; bu bozulmaya örtüşme (aliasing) denir. Bu yüzden pratikte örneklemeden önce işaret, $F_s/2$'nin üstündeki frekansları bastıran bir alçak geçiren filtreden (anti-aliasing filtresi) geçirilir.

### 7.3 Uygulamalar

Hoca bir soru sordu: Sınıftaki hocanın sesi mikrofonla kaydedilecek; insan sesi 0-4 kHz arasındaysa örnekleme frekansı en düşük ne seçilmelidir? Cevap en az $2 \times 4\text{ kHz} = 8\text{ kHz}$'tir (ekrandan, 01:00:00).

Hoca MP3 dosyalarının bilgilerinde görülen değerlere de değindi: Düşük örnekleme frekansında ses kalitesi biraz daha düşüktür; yüksek örneklemede kalite artar ama dosya boyutu büyür. Bu, dersin başında tartışılan sık örnekleme dengesinin aynısıdır. Cep telefonu görüşmelerinde ses, istasyona elektromanyetik olarak iletilmeden önce 8 kHz ile örneklenir.

> **Ders sonrası not:** Hoca MP3'lerde "8 kHz, 16 kHz, 128 kHz" örnekleme hızları görüldüğünü ve 128 kHz'in 8 kHz'in 16 katı olduğunu söyledi. MP3'te yaygın görülen 128 değeri büyük olasılıkla bit hızıdır (128 kbps); MP3 için yaygın örnekleme frekansları 44,1 kHz ve 48 kHz civarındadır.

## 8. Nicemleme (Quantization)

### 8.1 Hafızaya yazmanın önündeki engel

İşaret artık $T_s$ aralıklarla örneklenmiştir. Örnekler işlenmek üzere hafızaya gönderilecektir: birinci örnek bir göze, ikinci örnek bir sonrakine (ekrandan, 01:15:00). Hoca bunun önünde bir engel olup olmadığını sordu.

**Soru:** Ayrıklaştırılmış örnekleri hafızaya atarken bir sorun yaşar mıyız? **Cevap:** Bir öğrenci örneklerin kuantalanması, yani 0 ve 1'ler biçiminde depolanması gerektiğini söyledi; bir başkası dönüştürücüler kullanıldığını ekledi. Hoca sorunu şöyle açıkladı.

Zaman ekseni artık ayrıktır: Zaman, 0'ıncı, 1'inci, 2'nci örnek diye bir zaman indisi $n$ ile anılır (tahtada "n → zaman indisi", ekrandan 01:15:00). İlk örneğin değeri 4 olsaydı ikili olarak saklanabilirdi. Ama örnek değeri tam sayı olmak zorunda değildir; tahtadaki örnekte olduğu gibi 4,7821357... biçiminde virgülden sonra sonsuz basamak alabilir. Yani zaman ekseninde ayrıklaştırma yapılmış olsa da genlik ekseninde değerler hâlâ süreklidir. Bunların bir yere yuvarlanması gerekir.

Hafızada 1'den $N$'e kadar gözler vardır ve her gözün içeriği 8, 16 ya da 64 bit olabilir (ekrandan, 01:15:00). Bu bitlerle ifade edilebilecek sayılar sınırlıdır. Bu yüzden değerler belirli aralıklara konur; bu işleme nicemleme (kuantalama, quantization) denir.

### 8.2 Bit sayısı ve aralıklar

- **1 bit:** İşaretin ortasından geçen bir çizgi düşünülsün. 0 ve 1 ile yalnız örneğin pozitif mi negatif mi olduğu ayrılabilir; 2 durum.
- **2 bit:** 00, 01, 10, 11 olmak üzere 4 bölge tanımlanır. Artık farklı bölgelere düşen örnekler ayrılabilir; biri 00, diğeri 01 diye saklanır.
- **Sorun:** Genlikleri farklı olan iki örnek aynı bölgeye düşerse ikisi de 00 ile kodlanır ve aradaki fark kaybolur.
- **3 bit:** Bir bit daha eklenince bu iki örnek de ayrılabilir; biri 000, diğeri 001 olur. 3 bit 8 bölge verir.

Genel olarak $b$ bit $2^b$ farklı düzey tanımlar (ara adım eklendi: $2^1 = 2$, $2^2 = 4$, $2^3 = 8$). Hafıza gözündeki bit sayısı arttıkça daha sık aralıklarla ikili değerler atanabilir.

Bu aralıklara kuanta aralıkları denir. Hoca adın kökenini kimyadan bir benzetmeyle açıkladı: Atomun çevresindeki elektronlar belirli, ayrık enerji seviyelerinde bulunur ve bu seviyelere kuanta denir. Genlik ekseni de aynı şekilde ayrık seviyelere bölünür.

### 8.3 Geri oluşturma

Bir aralığa iki farklı değer düşerse ikisi de aynı kodla saklanır. İşaret geri oluşturulurken hafızadaki kodlar sırayla okunur ve her örneğin yerine kendi kuanta aralığının ortalama değeri konur. Bunun için $T_s$ aralığının da bilinmesi, yani dosyada saklanması gerekir. Böylece işaret yaklaşık olarak yeniden kurulur; aynı aralığa düşen örnekler arasındaki fark kaybolmuştur. Daha sık kuanta aralığı alınırsa bu farklar da korunur.

Özetle analogdan sayısala geçişin iki adımı vardır: birinci adım örnekleme (sampling), ikinci adım nicemleme (quantization).

> **Ek bilgi (derste anlatılmadı):** Gerçek değer ile atandığı kuanta düzeyi arasındaki farka nicemleme hatası (gürültüsü) denir. Düzgün nicemlemede, aralık genişliği $\Delta$ ise bu hata en fazla $\Delta/2$ olur; her ek bit aralık sayısını iki katına çıkarıp $\Delta$'yı yarıya indirir.

## 9. Elektronik Devrelerin Yeri

Analog-sayısal dönüşüm (ADC, analog to digital converter) gibi işlemler elektronik devrelerle gerçekleştirilir. Hocaya göre elektronik devreler ADC'lerden bilgisayarın içindeki lojik elemanlara ve transistörlü yapılara kadar her alanda kullanılır. Gömülü (embedded) sistemler ve mikrodenetleyici sistemlerinin çevresindeki çevre birimleri de elektronik sistemlerdir. Bu derste diyotlar ve transistörler gibi temel elemanlarla bu çevre birimlerinin nasıl tasarlandığı görülecektir.

## 10. Sensörler ve Aktüatörler

Dersin son bölümü sensör ve aktüatör slaytlarıyla işlendi (ekrandan, 01:20:00; slayt destesinin kapağı "Electronic Circuits").

### 10.1 Tanımlar

Sensörler bir bilginin alınıp elektriksel işarete dönüştürüldüğü elemanlardır. Aktüatörler (actuator) ise tersini yapar: Elektriksel sinyali fiziksel, analog bir etkiye dönüştürür. Mikrofon bir sensör, hoparlör bir aktüatördür.

### 10.2 Sensör performansı: doğruluk ve netlik

Sensör performansı değerlendirilirken çalışma aralığı, çözünürlük (ayrıştırıcılık), hata, doğruluk ve belirsizlik gibi kavramlara bakılır. Bunlara doğrusallık ve hassasiyet de eklenir.

Hoca doğruluk ve netlik farkını bir sıvının sıcaklığını ölçme örneğiyle açıkladı. Sensör tekrar tekrar ölçüm yaptığında farklı değerler okuyabilir.

- **Netlik (precision):** Sensörün hep aynı ya da birbirine yakın değerleri ölçme eğilimidir. Ölçümler birbirine yakın ama gerçek değerden uzak olabilir; bu durumda netlik yüksek, doğruluk düşüktür.
- **Doğruluk (accuracy):** Ölçümlerin gerçek değere yakınlığıdır. Yüksek netlik ve yüksek doğrulukta ölçümler, ölçülmek istenen değerin etrafında toplanır.

### 10.3 Sensör türleri

Sensörler çalışma ilkelerine göre rezistif, indüktif, kapasitif, piezoelektrik, fotorezistif (ışıkla değişen), elastik ve termal (ısıyla değişen) olarak sınıflanır.

- **Sıcaklık sensörleri:** Rezistif sensörlerde direnç sıcaklıkla değişir. $V = IR$ olduğundan, $R$ değişince ölçülen gerilim de değişir; gerilim sıcaklıkla orantılanarak elektriksel bir sinyal elde edilir. Termistörler çok kullanılır. Transistörlerden yararlanan yarı iletken sıcaklık sensörleri de vardır.
- **Işık sensörleri:** Hoca, ışık miktarına göre elektriksel değer üreten yapının bir fotoğraf makinesindeki temel pikselin yaptığı iş olduğunu anlattı. Işık lenslerden geçip bu elemanlara düşer ve ışık miktarına göre elektriksel değerler oluşur. Bu her piksel için yapılır ve piksel dizisinin parlaklık değerleri kaydedilirse siyah-beyaz görüntü oluşur. Kırmızı, yeşil ve mavi (R, G, B) için ayrı parlaklık seviyeleri kaydedilirse renkli fotoğraf elde edilir. Işıkla direnci değişen yapıların yanında ışıkla kapasitesi değişen yapılar da vardır.
- **Fotoiletken (photoconductive) elemanlar** (ekrandan, 01:25:00): Bu elemanlar elektrik üretmez, yalnız dirençlerini değiştirir. Fotodiyotlar bu şekilde kullanılarak doğrusal elemanlar elde edilebilir. Fototransistörler fotodiyotlar gibi davranır ama daha hassastır. Işık bağımlı dirençler (LDR, light-dependent resistor) yavaştır ama insan gözüne benzer tepki verir.
- **Kuvvet sensörleri:** Uygulanan kuvvete göre değişen sensörlerdir. Slayttaki örnek gerinim ölçerdir (strain gauge): Bir yönde gerilmesi elemanın direncini artırır (ekrandan, 01:25:00).
- **Yer değiştirme sensörleri:** Örneğin potansiyometre. Kol hangi konuma getirilirse buna karşılık bir gerilim elde edilir: bir uçta en yüksek, diğer uçta en düşük değer. Ara değerlerden kolun nerede olduğu bulunur.
- **Endüktif yakınlık (inductive proximity) sensörleri:** Özellikle sanayide çok kullanılır. Bir verici ve bir algılayıcı vardır; aradaki ilişki kesildiğinde araya bir nesne (örneğin el) girdiği anlaşılır.
- **Anahtarlar (switch) ve opto-anahtarlar:** Hareketi algılamak için kullanılır. Opto-anahtarda bir ışık kaynağı ve karşısında bir sensör bulunur; ışığın geçtiği ve geçmediği anlar elektriksel sinyale dönüşür. Bir tekerleğin üzerine delikler açılırsa, ışığın geçip geçmemesinden tekerleğin dönüş hızı (frekansı) çıkarılabilir. Lazerle çalışan farelerden önce fareler $x$ ve $y$ yönündeki hareketi bu opto-anahtarlarla algılardı.
- **Konum sensörleri ve enkoderler:** Motorlarda, özellikle adım motorlarında çok kullanılır.
- **Ses sensörleri:** Mikrofonlar.

Hoca, sensör yapılarının dersin ilerleyen kısımlarında görülecek gerilim bölücü devreler üzerinden de gerçekleştirilebileceğini belirtti.

> **Ek bilgi (derste anlatılmadı):** Rezistif bir sensör sabit bir dirençle seri bağlanıp bir gerilim bölücü kurulursa çıkış gerilimi $V_{out} = V_{in}\,\dfrac{R_{\text{sensör}}}{R_{\text{sabit}} + R_{\text{sensör}}}$ olur. Sensörün direnci sıcaklık ya da ışıkla değiştikçe $V_{out}$ de değişir ve bu gerilim bir ADC ile ölçülebilir.

### 10.4 Aktüatörler

Aktüatörler elektriksel işareti ısı, ses, ışık ya da hareket gibi fiziksel büyüklüklere dönüştürür.

- **Işık aktüatörleri:** Gelen elektriksel işarete göre ışık miktarı artıp azalan yapılardır. Bunlardan biri LED'dir; televizyonlardan telefonlara kadar her yerde kullanılır. LED 1-0 mantığıyla yanıp sönebilir ya da üzerindeki gerilime göre farklı parlaklık seviyeleri verebilir. Sıvı kristal ekranlar (LCD) da bu gruptadır.
- **Solenoidler ve röleler:** Elektriğin varlığına ya da yokluğuna göre fiziksel olarak hareket eden yapılardır. Açıp kapama ya da hareket gerektiren yerlerde, arabalardan sanayiye kadar çok kullanılır.
- **Ölçü aletleri:** İçlerindeki bobinler, üzerlerinden geçen akım ya da gerilimin miktarına göre farklı yerlere saparak akımın ya da gerilimin şiddetini gösterir. Hocaya göre ölçü aletleri de elektriksel işareti bize gösteren bir tür aktüatördür.
- **Motorlar:** AC ve DC motorlar, adım (step) motorları. Slaytta adım motoru akım dalga biçimleri ve tipik bir adım motoru gösterildi (ekrandan, 01:30:00).
- **Ses aktüatörleri** (ekrandan, 01:30:00):
  - Hoparlörler genellikle sabit bir mıknatıs ve bir diyaframa bağlı hareketli bir bobin kullanır. Giriş sinyali bobinde akım oluşturur ve bobin mıknatısa göre hareket eder.
  - Ultrasonik dönüştürücüler: Yüksek frekanslarda hoparlörlerin yerini genellikle piezoelektrik aktüatörler alır. Bunlar dar bir frekans aralığında çalışır.

Hoca son olarak dijital osiloskopların kullanımının laboratuvar kapsamında anlatılacağını belirtti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:27): Ses işaretinden zaman ekseninde örnekler alındığı gibi, iki boyutlu gerçek görüntülerden de $x$ ve $y$ yönünde örnekler alınır. Bu örneklere ne ad verilir?

> **Cevap (derste verildi):** Piksel.

**Soru 2** (derste sözlü, 00:20:36 ve 00:21:28): Bir işareti sayısal sisteme aktarırken (a) çok sık, (b) seyrek örnek almanın avantaj ve dezavantajları nelerdir?

> **Cevap (derste verildi):** (a) Avantaj: İşaret asıla daha yakın saklanır. Dezavantaj: Daha çok veri noktası olduğundan hafıza ihtiyacı ve hesaplama karmaşıklığı artar. (b) Avantaj: Yer kazanılır. Dezavantaj: Aradaki önemli değişimler kaybolur, işaretin karakteristikleri bozulabilir.

**Soru 3** (ekrandan, 00:35:00; derste sözlü, 00:33:18): Tahtadaki iki sinüzoidal işaretten biri tepe noktasından (I), diğeri sıfırdan (II) başlıyor; frekansları ve genlikleri aynı. Tam periyot $360^\circ$ ise aralarındaki faz farkı kaç derece ve kaç radyandır?

> **Cevap (derste verildi):** Kayma bir periyodun dörtte biridir: $360^\circ/4 = 90^\circ$, radyan olarak $2\pi/4 = \pi/2$. I kosinüs, II sinüstür.

**Soru 4** (ekrandan, 00:40:00; derste sözlü, 00:35:32): Periyotları $T_1 = 1/F_1$ (yavaş salınan) ve $T_2 = 1/F_2$ (hızlı salınan) olan iki işaretin periyotları ve frekansları hakkında ne söylenebilir?

> **Cevap (derste verildi):** $T_1 > T_2$ olduğundan $F_1 < F_2$'dir. Periyodu büyük olanın frekansı küçüktür; frekansı yüksek olan aynı sürede daha çok çevrim yapar.

**Soru 5** (derste sözlü, 00:38:33, 00:42:07 ve 00:43:11): Evdeki prizden alınan güç işareti sabit (DC) mi, salınan (AC) bir işaret mi? Türkiye'de genliği ve frekansı nedir?

> **Cevap (derste verildi):** AC'dir; Türkiye'de 220 V ve 50 Hz (ABD'de 110 V, 60 Hz). Bkz. Bölüm 5'teki ders sonrası not: 220 V etkin değerdir.

**Soru 6** (ekrandan, 00:55:00; derste sözlü, 00:50:27): En yüksek frekanslı bileşenden yalnız tepe noktalarında örnek alınıyor. $T_s$ ile $T_{max}$ arasındaki ilişki nedir? Sıfır geçişlerinden de örnek alınırsa ilişki nasıl değişir?

> **Cevap (derste verildi):** Yalnız tepe noktalarında $T_{max} = 2T_s$, yani $F_s = 2F_{max}$. Geçişler de alınırsa $T_{max} = 4T_s$, yani $F_s = 4F_{max}$. Genel kural $F_s \geq 2F_{max}$'tır.

**Soru 7** (ekrandan, 01:00:00; derste sözlü, 00:55:51): İnsan sesi 0-4 kHz arasında yer alıyorsa, mikrofonla kaydedilen sesi örneklemek için en düşük örnekleme frekansı ne olmalıdır?

> **Cevap (derste verildi):** $F_s \geq 2F_{max} = 2 \times 4\text{ kHz} = 8\text{ kHz}$.

**Soru 8** (derste sözlü, 01:11:48): Zaman ekseninde ayrıklaştırılmış örnekler hafızaya doğrudan atılabilir mi? Sorun nedir?

> **Cevap (derste verildi):** Atılamaz. Örneklerin genlikleri hâlâ süreklidir (virgülden sonra sonsuz basamak alabilir), hafıza gözleri ise sınırlı sayıda bit içerir. Genlikler sınırlı sayıda kuanta aralığına yuvarlanmalı (nicemleme) ve ikili kodlarla saklanmalıdır; $b$ bit ile $2^b$ aralık ayrılabilir.

## Dersin Toparlaması

Bu derste elektronik devrelerin neden gerekli olduğu, sürekli dış dünya ile ayrık sayısal sistemler arasındaki köprü üzerinden anlatıldı. Bir işaret önce bir sensörle elektriksel hale getirilir, sonra $T_s$ aralıklarla örneklenir ve en son genlikleri sınırlı sayıda düzeye yuvarlanarak (nicemleme) ikili sayılar olarak hafızaya yazılır. $T_s$'nin nasıl seçileceği sorusu için önce sinüzoidal işaretin genlik, frekans ve faz parametreleri, DC/AC ayrımı ve Fourier analizi incelendi. Gerçek işaretler bant sınırlı olduğu için en yüksek frekans $F_{max}$ üzerinden $F_s \geq 2F_{max}$ kuralına ulaşıldı; insan sesi için bu en az 8 kHz demektir. Nicemlemede bit sayısı arttıkça kuanta aralıkları daralır ve işaret daha iyi temsil edilir.

Dersin sonunda sensörler (fiziksel → elektriksel) ve aktüatörler (elektriksel → fiziksel) türleriyle tanıtıldı; doğruluk ile netlik arasındaki fark açıklandı. Hoca bir sonraki derste diyotlara ve diyotların oluşturulmasına geçileceğini söyledi. Sensör yapılarının bir kısmının ileride görülecek gerilim bölücü devrelerle kurulabileceği de belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
