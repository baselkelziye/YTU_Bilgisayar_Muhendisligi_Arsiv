# Ders 18 Genişletilmiş Notu: BJT Kutuplama Soru Çözümleri (Devam) ve FET'lere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Gerilim Bölücülü Devrenin Hatırlatması ve DC/AC Bileşen
- 2. Gerilim Geri Beslemeli Kutuplama Sorusu
- 3. Kollektör Geri Beslemeli Kutuplama Sorusu
- 4. Çalışma Noktasından Direnç Tasarımı
- 5. FET'ler ve BJT'ler
- 6. FET Türleri
- 7. JFET'in Yapısı ve Uçları
- 8. JFET'in Çalışma Karakteristikleri
- 9. Shockley Denklemi ve Transfer Eğrisi
- 10. p Kanallı JFET ve Sembol Gösterimi
- 11. Kanal Ayarlamalı MOSFET (D-MOSFET)
- 12. Kanal Oluşturmalı MOSFET (E-MOSFET)
- 13. CMOS ve Özet Tablo
- Örnek Sorular
- Dersin Toparlaması

## 1. Gerilim Bölücülü Devrenin Hatırlatması ve DC/AC Bileşen

Ders, önceki derste kalınan BJT soru çözümlerinden devam etti. Önce gerilim bölücülü npn devresi hatırlatıldı (ekrandan, 00:15:00). Devrede $V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ ve $\beta = 140$'tır. Tabana düşen gerilim bir gerilim bölücüyle bulunur. Hoca bunu oranlarla anlattı: $R_2$ bir birimse $R_1$ on birimdir, toplam 11 birimdir ve 22 V'un 11'de biri, yani 2 V, $R_2$ üzerine düşer:

$$E_{Th} = \frac{3{,}9\,\text{k}\Omega}{39\,\text{k}\Omega + 3{,}9\,\text{k}\Omega} \cdot 22\,\text{V} = 2\,\text{V}$$

$R_{Th}$ bulunurken taban sanki 2 V'luk bir kaynağa bir $R_{Th}$ direnci üzerinden bağlanmış gibi düşünülür. $R_{Th}$, birbirine paralel iki direncin (3,9 kΩ ve 39 kΩ) eşdeğeridir: $R_{Th} = 39 \parallel 3{,}9 \approx 3{,}55$ kΩ (ekrandan, 00:15:00).

### 1.1 Kondansatörler ve DC kutuplamanın amacı

Hoca, bu devrelerin hepsinin transistörü kararlı çalıştırmak için kullanılan farklı DC besleme (kutuplama) yapıları olduğunu hatırlattı. Girişteki ve çıkıştaki kondansatörler işaretin DC bileşenini süzer. Bir giriş işareti iki parçadan oluşur: işaretin ortalaması olan bir DC bileşen ve onun üzerine binmiş bir AC bileşen. Kondansatör DC kısmı siler, yalnız AC işareti geçirir.

DC kutuplama, transistörü kesim ve doyum bölgelerinden uzak, güvenli bir bölgede çalışır hale getirir; $I_B$, $I_C$ ve $V_{CE}$ değerlerini sabitler. Transistör böyle şartlandıktan sonra AC bileşen işlenir. Bu yüzden sorular hep çalışma noktasındaki $I_B$, $I_C$, $V_{CE}$ ve çeşitli noktaların gerilimlerini sorar.

### 1.2 Gerilim gösterimleri

$V_C$ gibi tek indisli bir gerilim, o noktanın toprağa göre gerilimidir; toprak gizli olarak ikinci uçtur. $V_{AB}$ gibi iki indisli bir gerilim ise iki noktanın toprağa göre gerilimlerinin farkıdır: $V_{AB} = V_A - V_B$.

## 2. Gerilim Geri Beslemeli Kutuplama Sorusu

Bu soru Boylestad'ın Örnek 4.13'üdür (ekrandan, 00:20:00). Devrede $V_{CC} = 18$ V, kollektör direnci $R_C = 3{,}3$ kΩ, emitör direnci $R_E = 510$ Ω ve $\beta = 75$'tir. Kollektörden tabana giden geri besleme yolu iki dirençten oluşur: $R_1 = 91$ kΩ ve $R_2 = 110$ kΩ. İki direncin birleşim noktası 10 µF'lık bir kondansatörle toprağa bağlanır. Giriş $v_i$ 10 µF üzerinden tabana, çıkış $v_o$ 10 µF üzerinden kollektörden alınır; $R_E$'ye paralel 50 µF'lık bir kondansatör vardır. Soruda $I_B$ ve $V_C$ isteniyor.

### 2.1 Akımlar ve KVL

$R_C$'den geçen akım $I'_C$'dir. Bu akım kollektöre giren $I_C$ ile geri besleme direnci üzerinden tabana giden $I_B$'nin toplamıdır: $I'_C = I_C + I_B$. $I_B$ çok küçük olduğu için ihmal edilir ve $I'_C \approx I_C$ alınır. Aynı şekilde $I_E \approx I_C$ kabul edilir.

Beslemeden başlayıp $R_C$, geri besleme dirençleri, baz-emitör eklemi ve $R_E$ üzerinden toprağa giden yol için KVL yazılır:

$$V_{CC} = I_C R_C + I_B (R_1 + R_2) + V_{BE} + I_E R_E$$

Kitap iki geri besleme direncini toplayıp $R_B = R_1 + R_2 = 201$ kΩ demiştir. $I_C$ terimleri parantezde toplanır ve $I_C = \beta I_B$ yazılır. Amaç her şeyi $I_B$ cinsinden yazıp $I_B$'yi yalnız bırakmaktır:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)} = \frac{18 - 0{,}7}{201\,\text{k}\Omega + 75 \cdot (3{,}3\,\text{k}\Omega + 0{,}51\,\text{k}\Omega)} = \frac{17{,}3}{486{,}75\,\text{k}\Omega} \approx 35{,}5\,\mu\text{A}$$

(ara adım eklendi: payda değeri). Mikro $10^{-6}$ demektir; çok düşük bir akımdır. $I_C$ için bu değer $\beta$ ile çarpılır:

$$I_C = \beta I_B = 75 \cdot 35{,}5\,\mu\text{A} \approx 2{,}66\,\text{mA}$$

> **Hocanın vurgusu:** $I_B$ genellikle $I_C$'ye ve $I_E$'ye göre çok düşük çıkar. Taban akımı mikroamper, kollektör akımı miliamper mertebesindedir.

### 2.2 Kollektör gerilimi

$V_C$, kollektör noktasının toprağa göre gerilimidir. Bunu bulmanın bir yolu emitörden yukarı çıkmaktır, ama $V_{CE}$ bilinmiyorsa daha kısa yol beslemeden aşağı inmektir: 18 V'tan $R_C$ üzerinde düşen gerilim çıkarılır.

$$V_C = V_{CC} - I_C R_C = 18 - 2{,}66\,\text{mA} \cdot 3{,}3\,\text{k}\Omega \approx 9{,}22\,\text{V}$$

> **Ders sonrası not:** Altyazıda geri besleme dirençleri "91 kilo, 92 kilo" diye geçiyor (00:19:08). Ekrandaki devrede $R_2 = 110$ kΩ'dur (ekrandan, 00:20:00); $35{,}5$ µA sonucu da 110 kΩ ile çıkar.

## 3. Kollektör Geri Beslemeli Kutuplama Sorusu

Bir sonraki soruda geri besleme direnci tek parçadır ve emitörde direnç yoktur (ekrandan, 00:30:00). Ekranda okunan değerler $V_{CC} = 20$ V, $R_B = 680$ kΩ, $R_C = 4{,}7$ kΩ ve $\beta = 120$'dir. <!-- BELİRSİZ: Karede devre şeklinin yalnız bir kısmı görünüyor; R_C = 4,7 kΩ değeri çözümdeki "(1.86 mA)(4.7..." ifadesinden ve sonuçla tutarlılıktan alındı. -->

Kollektöre bağlı kolda yine $I'_C = I_C + I_B$ akar ve $I'_C \approx I_C$ alınır. KVL:

$$V_{CC} = I_C R_C + I_B R_B + V_{BE}$$

Emitörde direnç olmadığı için $V_{BE}$'den sonra başka terim yoktur. $I_C$ yerine $\beta I_B$ yazılınca:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta R_C} = \frac{20 - 0{,}7}{680\,\text{k}\Omega + 120 \cdot 4{,}7\,\text{k}\Omega} = \frac{19{,}3\,\text{V}}{1{,}244\,\text{M}\Omega} \approx 15{,}51\,\mu\text{A}$$

$$I_{CQ} = \beta I_B = 120 \cdot 15{,}51\,\mu\text{A} \approx 1{,}86\,\text{mA}$$

Emitör doğrudan toprağa bağlı olduğundan $V_E = 0$'dır. Bu yüzden $V_{CE} = V_C - V_E = V_C$ olur. $V_C$ ise beslemeden $R_C$ üzerinde düşen gerilim çıkarılarak bulunur:

$$V_{CE} = V_C = V_{CC} - I_C R_C = 20 - 1{,}86\,\text{mA} \cdot 4{,}7\,\text{k}\Omega \approx 11{,}26\,\text{V}$$

Benzer şekilde $V_{BE} = V_B - V_E = V_B$ olur; iletimdeki baz-emitör gerilimi sabit $0{,}7$ V olduğundan $V_B = 0{,}7$ V'tur (ekrandan, 00:30:00). $V_B$ ve $V_C$ bilindikten sonra iki nokta arasındaki gerilim farkı istendiğinde yapılacak iş basit bir çıkarmadır; örneğin $V_{BC} = V_B - V_C$.

## 4. Çalışma Noktasından Direnç Tasarımı

Bu soru Boylestad'ın Örnek 4.20'sidir (ekrandan, 00:35:00). Bu kez çalışma noktası verilmiş, dirençler istenmiştir. Hoca "Q" harfinin İngilizce "quiescent" (durgun, sükûnet hali) kelimesinden geldiğini, yani kararlı çalışmadaki değerleri gösterdiğini hatırlattı. Verilenler: $I_{CQ} = 2$ mA, $V_{CEQ} = 10$ V, $V_{CC} = 18$ V, alt bölücü direnci $R_2 = 18$ kΩ ve $R_E = 1{,}2$ kΩ. $R_1$ ve $R_C$ bulunacak.

### 4.1 Emitör ve taban gerilimleri

$I_E \approx I_C$ kabul edilir. $R_E$ üzerinde düşen gerilim emitörün toprağa göre gerilimidir:

$$V_E = I_E R_E \approx I_C R_E = 2\,\text{mA} \cdot 1{,}2\,\text{k}\Omega = 2{,}4\,\text{V}$$

$V_{BE} = V_B - V_E$ olduğundan $V_B = V_{BE} + V_E = 0{,}7 + 2{,}4 = 3{,}1$ V bulunur.

### 4.2 $R_1$'in bulunması

Tabanda bir gerilim bölücü vardır ve $V_B$ alttaki 18 kΩ'luk direnç üzerinde düşer:

$$V_B = \frac{R_2 V_{CC}}{R_1 + R_2} \Rightarrow 3{,}1 = \frac{18\,\text{k}\Omega \cdot 18\,\text{V}}{R_1 + 18\,\text{k}\Omega}$$

$$324\,\text{k}\Omega = 3{,}1 R_1 + 55{,}8\,\text{k}\Omega \Rightarrow 3{,}1 R_1 = 268{,}2\,\text{k}\Omega \Rightarrow R_1 = 86{,}52\,\text{k}\Omega$$

(ekrandan, 00:35:00).

> **Ders sonrası not:** Hoca tahtaya bölücü formülünü $V_B = V_{CC} \cdot \dfrac{R_1}{R_1 + 18\,\text{k}\Omega}$ diye yazdı ve öyle söyledi (00:32:34). Doğrusu payda $V_B$'nin düştüğü alttaki direncin (18 kΩ) olmasıdır: $V_B = V_{CC} \cdot \dfrac{18\,\text{k}\Omega}{R_1 + 18\,\text{k}\Omega}$. Slayttaki çözüm böyledir ve $86{,}52$ kΩ sonucu bu formülden çıkar.

### 4.3 $R_C$'nin bulunması

Kitap önce kollektörün gerilimini bulmuştur: $V_C = V_{CE} + V_E = 10 + 2{,}4 = 12{,}4$ V. $R_C$ üzerindeki gerilim beslemeyle kollektör arasındaki farktır ve bu dirençten $I_C$ geçer:

$$R_C = \frac{V_{CC} - V_C}{I_C} = \frac{18 - 12{,}4}{2\,\text{mA}} = 2{,}8\,\text{k}\Omega$$

Hoca aynı sonuca götüren ikinci bir yol da gösterdi: kollektör kolunda KVL yazılır, $V_{CC} = I_C R_C + V_{CE} + I_E R_E$. $V_{CC} - V_{CE} = 18 - 10 = 8$ V eder ve $I_E \approx I_C$ ile $8\,\text{V} = 2\,\text{mA} \cdot (R_C + 1{,}2\,\text{k}\Omega)$ olur. Buradan $R_C + 1{,}2\,\text{k}\Omega = 4\,\text{k}\Omega$, yani $R_C = 2{,}8$ kΩ bulunur (ara adım eklendi).

### 4.4 pnp devreler

Önceki derste soruların hepsi npn tipinde çözülmüştü. pnp tipinde bir soru verilirse akım yönleri npn'dekinin tersi olur ve denklemler bu yönlere göre kurulur. Slaytlardaki bir op-amp sorusu geçildi; hoca transistörlerle ilgili anlatacaklarının bu kadar olduğunu söyledi.

> **Hocanın vurgusu:** Ders kolaydır ama son günlere bırakılırsa basit kavramlar bile karışır. Soru çözülmezse kalem hataları ve işlem hataları çok yapılır; hem soru çözülmeli hem de işin esası, yani çözüm yolları anlaşılmalıdır.

## 5. FET'ler ve BJT'ler

Hoca önce BJT'nin yapısını hatırlattı. pnp ya da npn olarak üç katmanlı bir yapıdır; çizilen şekil aslında yapının ortasından alınmış bir kesittir. "Bipolar" iki kutuplu, "junction" eklem demektir; n ve p tipi iki tür malzeme kullanılır. Gerilim uygulandığında eklemlerde geçiş bölgesi oluşur. Bu bölgenin daralması ya da genişlemesine göre $I_C$, $I_E$ ve $I_B$ akımlarının miktarı değişir.

FET, "Field Effect Transistor", yani alan etkili transistördür. Slayttaki karşılaştırma (ekrandan, 00:40:00):

- Benzerlikler:
  - Yükselteç (amplifier) olarak kullanılırlar.
  - Anahtarlama elemanı (switching device) olarak kullanılırlar; lojik seviyelerde çalışan VE, VEYA kapıları gibi devrelerin yapımında.
  - Empedans uydurma devrelerinde, yani giriş ve çıkışın uyumlu empedansa sahip olması gereken devrelerde kullanılırlar.
- Farklar:
  - FET gerilim kontrollü, BJT akım kontrollü bir elemandır.
  - FET'in giriş empedansı daha yüksektir; BJT'nin kazancı (gerilim kazancı) daha yüksektir.
  - FET sıcaklık değişimlerine daha az duyarlıdır ve entegre devrelere (IC) daha kolay uyarlanır.
  - FET, statik elektriğe BJT'den daha duyarlıdır.

Hoca akım kontrolünü şöyle açıkladı: BJT sorularında hep $I_B$'yi bulduk. $I_B$'nin varlığına ya da yokluğuna göre kollektör-emitör yolundan bir akım akışına izin veriyormuşuz gibi düşündük. Bu akım kontrolüdür. FET'lerde ise kontrolü gerilim yapar ve bu iki eleman arasındaki birinci ve en temel farktır.

Giriş empedansı için hoca girişe A ve B uçlarından (toprakla giriş arasından) bakıldığında görülen $Z_i$'yi gösterdi; FET'te bu direnç daha yüksektir. Sıcaklık konusunda BJT'nin $I_C$-$V_{CE}$ karakteristiğindeki farklı $I_B$ eğrilerinin sıcaklıkla sağa sola kayabildiğini hatırlattı. Statik elektrik duyarlılığını da FET'in gerilimle kontrol edilmesine bağladı: statik elektrikle oluşan gerilime eleman hemen tepki verir ve çıkıştaki değerler oynayabilir.

> **Ek bilgi (derste anlatılmadı):** MOSFET'lerde statik elektrik duyarlılığının başlıca nedeni, gate'i kanaldan ayıran oksit tabakasının çok ince olmasıdır. Küçük bir yükün yarattığı yüksek gerilim bu tabakayı delip elemanı kalıcı olarak bozabilir. Bu yüzden MOSFET'ler genellikle iletken ambalajlarda taşınır.

## 6. FET Türleri

FET'ler ikiye ayrılır (ekrandan, 00:45:00):

- JFET (Junction FET): eklemli FET.
- MOSFET (Metal-Oxide-Semiconductor FET): metal-oksit-yarıiletken FET. MOSFET'ler de kendi içinde ikiye ayrılır:
  - D-MOSFET (Depletion MOSFET): Türkçede kanal ayarlamalı MOSFET.
  - E-MOSFET (Enhancement MOSFET): Türkçede kanal oluşturmalı MOSFET.

Yapıları farklı olduğu için çalışma şekilleri de farklıdır. JFET'lerin ve her iki MOSFET türünün n kanallı ve p kanallı olmak üzere iki tipi vardır.

## 7. JFET'in Yapısı ve Uçları

### 7.1 Yapı

JFET için bir silindir düşünülür. Silindir ortasından bir bıçakla boylamasına kesilmiş gibi düşünülürse görülen şekil slayttaki kesittir. n kanallı JFET'te silindirin çoğunluğunu oluşturan ana malzeme n tipidir. Bu ana malzemenin çevresine belli bir derinliğe kadar kuşak gibi p tipi malzeme sarılmıştır. Arada görülen gri bölgeler geçiş bölgeleridir (depletion region).

Gate ucu bu p tipi kuşağa bağlıdır. Drain, n tipi kanalın üst ucuna, source alt ucuna bağlıdır. Bağlantılar omik kontaklarla, yani çok düşük dirençli kontaklarla yapılır. Akım drain ile source arasında, kanal boyunca geçer. Gate-source arasına gerilim uygulanınca geçiş bölgesi büyür ya da küçülür ve kanaldan geçecek akımın miktarı ayarlanır.

### 7.2 Uçların BJT karşılıkları

FET'te uçların adları değişir. Slayttaki su musluğu benzetmesi kullanıldı (ekrandan, 00:50:00):

- Source (kaynak): emitörün yerine geçer. Emitör "emit", yani yayan anlamındaydı; source da su basıncının kaynağıdır.
- Gate (kapı): bazın yerine geçer. Musluğun vanası gibi suyun miktarını kontrol eder. BJT'de baz akımıyla kontrol ettiğimiz gibi, burada gate ile kontrol ederiz.
- Drain (boşaltım): kollektörün yerine geçer. Kollektör toplayan demekti; drain ise Türkçedeki "drenaj" gibi bir boşaltım deliğidir.

BJT'de kontrolü $I_B$ ile yapıyorduk. FET'te bunun yerine gate ile source arasındaki gerilim $V_{GS}$ kullanılır.

## 8. JFET'in Çalışma Karakteristikleri

### 8.1 Sembol, akımlar ve gerilimler

n kanallı JFET sembolünde gate'teki ok içeri bakar (ekrandan, 01:05:00). Drain'den akan akım $I_D$, source'tan akan akım $I_S$'dir ve bunlar birbirine eşittir: $I_D = I_S$. Gate akımı sıfırdır ($I_G = 0$). Hoca bunun nedenini gate ile kanal arasında çok yüksek bir direnç bulunması, akımın gate'ten akmaması olarak açıkladı. Gate ile source arasına bir gerilim verilerek geçiş bölgesinin genişlemesi sağlanır.

> **Ek bilgi (derste anlatılmadı):** JFET'te gate ile kanal arasında yalıtkan bir tabaka yoktur; ikisi bir pn eklemi oluşturur. $V_{GS}$ negatif tutulduğunda bu eklem ters kutuplandığı için gate'ten yalnızca ihmal edilebilir bir sızıntı akımı akar. Gerçek yalıtkan tabaka (SiO₂) MOSFET'lerde bulunur.

Gate-source geriliminin durumuna göre üç çalışma şekli vardır:

- $V_{GS} = 0$ iken $V_{DS}$ belli bir pozitif değer alır ve en büyük akım akar.
- $V_{GS} < 0$ iken drain-source arasında değişken, pozitif bir gerilim oluşur ve akım azalır.
- Üçüncü çalışma şeklinde eleman gerilim kontrollü bir direnç gibi düşünülebilir.

### 8.2 $V_{GS} = 0$ durumu

Gate-source arasına hiçbir gerilim uygulanmadığında kanal en açık halindedir. Geçiş bölgesi sabit bir genişliktedir ve kanaldan belli bir akım akar. Elektronlar source'tan drain'e doğru akar; akımın yönü bunun tersidir.

### 8.3 Negatif $V_{GS}$ ve pinch-off

Gate-source arasına negatif gerilim uygulandığında n bölgesindeki geçiş bölgesi büyür ve kanaldan akımın geçmesi zorlaşır. Temel fikir budur. Slaytta önce $-1$ V uygulanmış ve geçiş bölgesi biraz genişlemiştir; negatif gerilim arttıkça iki taraftaki geçiş bölgeleri birbirine yaklaşır.

Hoca "pinch" kelimesini bir tutam tuz alırken işaret parmağı ile başparmağın birbirine kapanması hareketine benzetti. Geçiş bölgeleri genişleyip birleşince parmak uçları kapanmış gibi kanal kapanır ve akımı engeller. Örnekte $V_{GS} = -4$ V'ta kanalın tamamen kapandığı düşünülür. Kanalın kapandığı bu $V_{GS}$ değerine pinch-off gerilimi ($V_P$) denir.

> **Ders sonrası not:** Hoca pinch-off ile kanal kapanınca $I_D$ ve $I_S$'nin birbirine eşit ve sıfır olduğunu söyledi (01:09:44). Ekrandaki slayt ise başka bir durumu gösteriyor (ekrandan, 01:10:00): $V_{GS} = 0$ iken $V_{DS}$, $V_P$ değerine kadar artırılınca geçiş bölgesi kanalı "pinch off" eder, ama slaytın da belirttiği gibi akım 0 A'e düşmez; $V_{DS}$ arttıkça $I_D$ artar ve sonra $I_{DSS}$ düzeyinde doyuma gider. Akımın gerçekten sıfır olduğu durum $V_{GS} = V_P$ ($V_{GS(off)}$) olduğu durumdur.

### 8.4 $I_D$-$V_{DS}$ karakteristiği

$I_D$-$V_{DS}$ grafiklerinde her eğri bir $V_{GS}$ değerine karşılık gelir. $V_{GS} = 0$ iken kanaldan akabilecek en büyük akım akar. $V_{GS}$ negatif yönde büyüdükçe eğriler aşağı iner ve en alttaki eğride $I_D$ sıfırlanır. Bu, örnekteki $-4$ V'luk $V_P$ değeridir.

## 9. Shockley Denklemi ve Transfer Eğrisi

### 9.1 Denklem

n kanallı JFET'te akım drain'den girer, source'tan çıkar; p kanallıda tersidir. Drain akımı şu denklemle hesaplanır:

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

$I_{DSS}$, $V_{GS}$'ye hiçbir gerilim uygulanmadığında akan en büyük akımdır. O durumda geçiş bölgesi en dar halindedir ve kanal en açıktır. Hoca bunu doyumdaki maksimum akım olarak tanımladı; sabit bir değerdir. $V_P$ de o transistöre özgü sabit bir pinch-off gerilimidir. Geriye tek değişken olarak uygulanan $V_{GS}$ kalır. Yani $I_D$, $V_{GS}$'nin bir fonksiyonudur.

### 9.2 $I_D$-$V_{GS}$ transfer eğrisi

Hoca bu grafiğin en çok kullanılacak grafiklerden biri olduğunu söyledi. Asıl lazım olan $I_D$ ile değişken $V_{GS}$ arasındaki ilişkidir ve bu ilişki $I_D$-$V_{DS}$ grafiğinden elde edilir. $V_{GS} = 0$ iken akan akım $I_{DSS}$ eksenine karşılık gelir. $V_{GS}$ negatife doğru gittikçe $I_D$ azalır ve $V_{GS} = V_P$ olduğunda sıfır olur. Denklemdeki kare terim yüzünden bu iki nokta arasında bir eğri (parabol parçası) oluşur.

Slayttaki üç adım (ekrandan, 01:20:00):

- Adım 1, $V_{GS} = 0$: $I_D = I_{DSS}(1 - 0)^2 = I_{DSS}$.
- Adım 2, $V_{GS} = V_P$ ($V_{GS(off)}$): $I_D = I_{DSS}(1 - 1)^2 = 0$ A.
- Adım 3, $V_{GS}$ 0 ile $V_P$ arasında: $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ formülü kullanılır.

> **Hocanın vurgusu:** $V_{GS} = 0$ iken $I_D = I_{DSS}$, $V_{GS} = V_P$ iken $I_D = 0$. Bunların dışındaki her yerde Shockley formülü kullanılır.

### 9.3 Kılıf

JFET'ler de transistörlere benzer kılıflarla satılır. Slayttaki örneğin bacak sırası: 1 drain, 2 source, 3 gate. Aynı bir transistör gibi devrede kullanılabilir.

## 10. p Kanallı JFET ve Sembol Gösterimi

p kanallı JFET'te durum n kanallının tam tersidir. Ana gövde (silindirin içi) p tipi, çevresindeki kuşak n tipidir. Gate akımı ok yönüne göre dışarı doğru gösterilir ama zaten 0 A'dir. Gate ile source arasına bir gerilim uygulanır; pilin iki ucu omik kontaklara bağlanıyormuş gibi düşünülebilir ve bu gerilimle geçiş bölgesi kontrol edilir. Hoca, gate ile kanal arasında temas olmadan bir alanla kontrol yapılmasının elemana "alan etkili" denmesinin nedeni olduğunu söyledi. p kanallıda akım yönleri de terstir: $I_D$ dışarı çıkar, $I_S$ içeri girer.

Sembolde gate'teki ok iç malzemenin, yani kanalın tipini gösterir. BJT'lerde de FET'lerde de ok, gösterdiği bölgenin tipini belirtir. Ok içeri bakıyorsa iç silindir (kanal) n tipidir; ok dışarı bakıyorsa iç malzeme p, kuşak n tipidir.

## 11. Kanal Ayarlamalı MOSFET (D-MOSFET)

### 11.1 Genel bakış

Hoca FET ağacını yeniden çizdi: JFET (n kanal ve p kanal, birbirinin tersi mantıkla çalışır) ve MOSFET. MOSFET'ler depletion (D-type, kanal ayarlamalı) ve enhancement (E-type, kanal oluşturmalı) olarak ikiye ayrılır; her birinin n ve p kanallı tipi vardır. JFET ile kanal ayarlamalı MOSFET'in karakteristikleri ve formülleri hemen hemen aynıdır; kanal oluşturmalı MOSFET'in ise apayrı bir yapısı vardır. n kanallı JFET'in $I_D$-$V_{GS}$ eğrisi pozitif $V_{GS}$ bölgesine geçmiyordu; D-MOSFET'te eğrinin bir miktar pozitif bölgeye de geçtiği görülecektir.

### 11.2 Yapı

Slayttaki n kanallı D-MOSFET (ekrandan, 01:25:00): drain ve source, metal kontaklar üzerinden n katkılı bölgelere bağlanır. Metal kontaklar yarıiletken malzemeyle temas sağlamak içindir. Bu n bölgeleri bir n kanalıyla birbirine bağlıdır. Yapı p tipi bir altlık (substrate) üzerinde durur; altlığın SS adlı ek bir ucu olabilir. Gate ile kanal arasında ince bir SiO₂ (silisyum oksit) tabakası vardır. Bu yalıtkandır, bu yüzden gate n tipi malzemeye değmez bile.

JFET'te kanal tamamen silindirin içindeydi. Burada ise drain'e ve source'a bağlı n tipi bölgelerin arasına n tipi bir kanal oluşturulmuştur. "n kanallı D-MOSFET" denince drain ve source'un gerçekten değdiği yarıiletkenlerin n tipinde olduğu anlaşılır. Hoca $V_{GS}$'nin oluşturduğu alanın bir mıknatıs gibi n bölgesini daraltıp genişlettiğini söyledi. <!-- BELİRSİZ: Hoca bu alanı "elektromanyetik alan" diye adlandırdı (01:25:55); MOSFET'te kontrol gate geriliminin oluşturduğu elektrik alanla yapılır. -->

### 11.3 Çalışma

$V_{GS} = 0$ iken kanal olduğu gibi durur ve akım bir uçtan öbürüne geçer. Negatif gerilim uygulanınca n tipi bölge içeri itilir ve kanal gittikçe daralır, sonunda tabakaya kadar kapanır. Burada da kanalı yok eden negatif gerilime pinch-off gerilimi denir.

JFET'ten farkı şudur: pozitif gerilim verildiğinde kanal genişlemeye başlar ve daha fazla akım akabilir. JFET'te pozitif $V_{GS}$ verilemiyordu. D-MOSFET'te pozitif gerilim artırıldıkça akım artmaya devam eder; negatif gerilimde ise $V_P$'de kanalı tamamen yok etmek mümkündür. p kanallı tipte n'lerin yerine p tipi malzeme gelir ve yapı n tipi bir altlık üzerinde durur.

### 11.4 İki çalışma modu

Slayt, D-MOSFET'in iki modda çalışabildiğini söyler (ekrandan, 01:30:00):

- Depletion mode: transfer eğrisinin sol tarafı, yani negatif $V_{GS}$ bölgesi. Karakteristik aynı JFET gibidir.
- Enhancement mode: pozitif $V_{GS}$ bölgesi. "Enhancement" zenginleştirme demektir; kanal normal halinden daha büyük hale getirilir ve akım artırılır. Eğri hızla yükselmeye devam eder.

Her iki bölge de aynı formülle hesaplanır. Demek ki Shockley denklemi JFET ve D-MOSFET için ortaktır:

$$I_D = I_{DSS}\left(1 - \frac{V_{GS}}{V_P}\right)^2$$

Slayttaki örnek eğride $I_{DSS} = 8$ mA ve $V_P = -6$ V'tur; eğri $V_{GS} = V_P/2 = -3$ V'ta 2 mA'den ($I_{DSS}/4$), $V_{GS} \approx 0{,}3V_P$'de yaklaşık 4 mA'den ($I_{DSS}/2$), $V_{GS} = 0$'da 8 mA'den ve $V_{GS} = +1$ V'ta $10{,}9$ mA'den geçer (ekrandan, 01:30:00). $+1$ V için formül $8 \cdot (1 + 1/6)^2 \approx 10{,}89$ mA verir (ara adım eklendi). Sağdaki $I_D$-$V_{DS}$ eğrileri de $V_{GS} = +1, 0, -1, \dots, -6$ V için çizilmiştir.

Bu MOSFET'e kanal ayarlamalı denmesinin nedeni, zaten var olan bir kanalın genişletilip büzüştürülmesidir.

### 11.5 p kanal ve semboller

p kanallı D-MOSFET'te drain ve source p tipi malzemeye değer, aradaki kanal p tipindedir ve akım ters yönde akar. p kanallı JFET'te olduğu gibi transfer eğrisi pozitif $V_{GS}$'den başlar, $V_{GS} = 0$'da $I_{DSS}$'ye ulaşır; D-MOSFET'te eğri negatif $V_{GS}$ bölgesinde de artmaya devam eder.

Sembolde (ekrandan, 01:35:00) gate'in kanala değmediği, arada bir boşluk bırakılarak gösterilir; bu boşluk alan etkisini gösterir. Kanala doğru bakan ok kanalın n tipinde olduğunu gösterir: n kanallı D-MOSFET. Kanaldan uzaklaşan ok ise kanalın p, altlığın n tipinde olduğunu gösterir: p kanallı D-MOSFET. Slaytta altlık ucunun (SS) ayrı gösterildiği ve source'a bağlandığı iki gösterim vardır; derste daha çok altlığın source'a bağlı olduğu alttaki gösterim kullanılır.

## 12. Kanal Oluşturmalı MOSFET (E-MOSFET)

### 12.1 Yapı

Hoca bir an "kanal ayarlamalı" dedi, sonra düzeltti: E-MOSFET kanal oluşturmalı MOSFET'tir. D-MOSFET JFET'e çok benzerken E-MOSFET bambaşka bir yapıdır, ama fiziksel olarak D-MOSFET'e çok benzer. Gate yine SiO₂ tabakasıyla p tipi altlığa değmez; drain ve source metal kontaklarla n tipi bölgelere bağlanır. Fark şudur: drain ve source arasında kanal yoktur. Kanalı uygulanan gerilimle biz oluştururuz. Hiçbir şey yapılmazsa kanal olmadığı için $V_{GS} = 0$ iken $I_D = I_S = 0$'dır.

### 12.2 Çalışma ve eşik gerilimi

n kanallı tipte gate'e pozitif $V_{GS}$ uygulanınca gate altında elektronlar toplanmaya başlar; $V_{GS}$ ne kadar pozitif olursa o kadar çok elektron toplanır. Ancak belli bir gerilime kadar kanal tam oluşmaz ve akım akmaz. Eşik gerilimi ($V_T$, threshold) aşılınca kanal oluşur ve $I_D$ sıfırdan ayrılıp yükselmeye başlar. Kanal genişledikçe akım artar. Hoca slayttaki örnekte eşiğin 2 V civarında olduğunu, 2 V'a kadar elektronların kanala çekildiği ama kanalın tam oluşmadığını söyledi.

> **Ders sonrası not:** Hoca eşikten sonra $V_{GS}$ arttıkça akımın "eksponansiyel" arttığını söyledi (01:38:25). Slayttaki formüle göre artış üstel değil, kareseldir: $I_D = k(V_{GS} - V_T)^2$.

### 12.3 Formül

E-MOSFET'in formülü diğerlerinden farklıdır (ekrandan, 01:40:00):

$$I_D = k\,(V_{GS} - V_T)^2, \qquad k = \frac{I_{D(on)}}{(V_{GS(on)} - V_T)^2}$$

Bu eleman da $V_{GS}$ ile kontrol edilir. $V_T$ transistöre özgü sabit bir eşik değeridir. $k$ da bir sabittir; elemanın belirli bir çalışma noktasındaki $I_{D(on)}$ ve $V_{GS(on)}$ değerlerinden hesaplanır. Aynı slaytta doyma gerilimi $V_{DS(sat)} = V_{GS} - V_T$ olarak verilir.

### 12.4 p kanallı E-MOSFET ve karakteristiklerin karşılaştırılması

Hoca dört karakteristiği yan yana koydu:

- n kanallı JFET ve D-MOSFET: eğri negatif $V_{GS}$'den başlayıp sağa doğru yükselir; D-MOSFET pozitif bölgeye de geçer.
- n kanallı E-MOSFET: eğri pozitif $V_{GS}$'de, $V_T$'den sonra yükselir.
- p kanallı JFET ve D-MOSFET: eğri sağ taraftadır (pozitif $V_P$).
- p kanallı E-MOSFET: eğri sol taraftadır. p tipi kanalın oluşması için gate'e negatif gerilim uygulanmalıdır; akım negatif yöndeki eşik geriliminden sonra artar. Slayttaki örnekte eğriler $V_{GS} = -4, -5, -6$ V için çizilmiştir (ekrandan, 01:40:00).

Yani E-MOSFET, kanal tipine göre diğerlerinin tam tersi tarafta çalışır.

### 12.5 Sembol

E-MOSFET sembolü kanal ayarlamalının sembolüne çok benzer, ama gate'in karşısındaki kanal çizgisi kesiklidir. Bu boşluklar kanalın henüz oluşmadığını gösterir; kanal uygulanan $V_{GS}$ ile oluşturulacaktır. Ok oluşacak kanalın tipini gösterir: kanala doğru bakan ok n kanallı E-MOSFET, sırtını dönmüş (dışarı bakan) ok p kanallı E-MOSFET'tir. p kanallıda altlık n, oluşacak kanal p tipindedir.

## 13. CMOS ve Özet Tablo

### 13.1 Gelişmiş MOSFET yapıları ve CMOS

MOSFET'ler zamanla daha da geliştirilmiştir; örneğin dikey (vertical) MOSFET'ler. Yarıiletken mühendisleri daha az akım çeken, daha kararlı çalışan, daha az güç tüketen yapılar geliştirmektedir. En bilinen örnek CMOS'tur: fotoğraf makinelerinde, ekranlarda, dokunmatik ekranlarda, RAM'lerde ve yarıiletken içeren pek çok üründe bu ad duyulur. CMOS bir transistör hücresidir.

CMOS lojik devre tasarımında çok kullanılır. Giriş empedansı yüksektir, yani çok akım çekmez. Anahtarlaması hızlıdır: 1'den 0'a geçişin eğimli değil keskin olması istenir ve ideale ne kadar yaklaşılırsa o kadar iyidir. Ayrıca düşük güç seviyelerinde çalışır.

> **Ek bilgi (derste anlatılmadı):** CMOS, "Complementary MOS" (tümleyen MOS) demektir. Bir n kanallı ve bir p kanallı E-MOSFET'in birbirini tamamlayacak şekilde bağlanmasıyla kurulur. Kararlı durumda transistörlerden biri her zaman kesimde olduğu için besleme ile toprak arasında neredeyse akım akmaz; düşük güç tüketiminin nedeni budur.

### 13.2 Özet tablo

Slayttaki özet tablo n kanallı elemanlar içindir (ekrandan, 01:45:00):

| Eleman | Sabitler | Formül | Çalışma bölgesi |
|---|---|---|---|
| n kanallı JFET | $I_{DSS}$, $V_P$ | $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ | Negatif $V_{GS}$ (0 ile $V_P$ arası) |
| n kanallı D-MOSFET | $I_{DSS}$, $V_P$ | $I_D = I_{DSS}(1 - V_{GS}/V_P)^2$ | Negatif $V_{GS}$ ve biraz pozitif (enhancement mode) |
| n kanallı E-MOSFET | $V_T$, $I_{D(on)}$, $V_{GS(on)}$ | $I_D = k(V_{GS} - V_T)^2$ | Pozitif $V_{GS}$, $V_T$'den sonra |

Üçünde de $I_G = 0$ A ve $I_D = I_S$'dir. JFET ile D-MOSFET'in formülü aynıdır; tek fark D-MOSFET'in enhancement modunda kanalın daha da genişletilebilmesidir. E-MOSFET'in formülü ikisinden tamamen farklıdır.

> **Hocanın vurgusu:** Bu üç elemanın formüllerini ve eğrilerini kafanızda oturtmanız yeterli olacaktır.

## Örnek Sorular

### Soru 1: Gerilim geri beslemeli devre (ekrandan, 00:20:00)

$V_{CC} = 18$ V, $R_1 = 91$ kΩ, $R_2 = 110$ kΩ (birleşim noktası 10 µF ile toprağa), $R_C = 3{,}3$ kΩ, $R_E = 510$ Ω (50 µF ile köprülü), $\beta = 75$ olan devrede $I_B$ ve $V_C$'nin DC değerlerini bulun.

Çözüm (derste verildi): $R_B = R_1 + R_2 = 201$ kΩ.

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta(R_C + R_E)} = \frac{17{,}3}{201\,\text{k} + 75 \cdot 3{,}81\,\text{k}} \approx 35{,}5\,\mu\text{A}$$

$I_C = \beta I_B \approx 2{,}66$ mA, $V_C = V_{CC} - I_C R_C = 18 - 2{,}66 \cdot 3{,}3 \approx 9{,}22$ V.

### Soru 2: Kollektör geri beslemeli devre (ekrandan, 00:30:00)

$V_{CC} = 20$ V, $R_B = 680$ kΩ, $R_C = 4{,}7$ kΩ, $\beta = 120$, emitör doğrudan toprakta. $I_B$, $I_{CQ}$, $V_{CEQ}$, $V_B$, $V_C$, $V_E$'yi bulun.

Çözüm (derste verildi):

$$I_B = \frac{20 - 0{,}7}{680\,\text{k} + 120 \cdot 4{,}7\,\text{k}} = \frac{19{,}3}{1{,}244\,\text{M}} \approx 15{,}51\,\mu\text{A}$$

$I_{CQ} = 120 \cdot 15{,}51\,\mu\text{A} \approx 1{,}86$ mA; $V_{CEQ} = V_C = 20 - 1{,}86 \cdot 4{,}7 \approx 11{,}26$ V; $V_B = V_{BE} = 0{,}7$ V; $V_E = 0$ V.

### Soru 3: Çalışma noktasından dirençlerin bulunması (ekrandan, 00:35:00)

Gerilim bölücülü bir npn devrede $V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ'dur. Çalışma noktası $I_{CQ} = 2$ mA, $V_{CEQ} = 10$ V olacak şekilde $R_1$ ve $R_C$'yi bulun.

Çözüm (derste verildi): $V_E \approx I_C R_E = 2{,}4$ V, $V_B = 0{,}7 + 2{,}4 = 3{,}1$ V.

$$3{,}1 = \frac{18\,\text{k} \cdot 18}{R_1 + 18\,\text{k}} \Rightarrow R_1 = \frac{268{,}2\,\text{k}}{3{,}1} \approx 86{,}52\,\text{k}\Omega$$

$V_C = V_{CE} + V_E = 12{,}4$ V, $R_C = (18 - 12{,}4)/2\,\text{mA} = 2{,}8$ kΩ. Kontrol: $18 - 10 = 2\,\text{mA} \cdot (R_C + 1{,}2\,\text{k})$ ⇒ $R_C = 2{,}8$ kΩ.

## Dersin Toparlaması

Dersin ilk yarısında BJT DC kutuplama soruları tamamlandı. Gerilim geri beslemeli ve kollektör geri beslemeli devrelerde ortak yöntem, $I'_C \approx I_C$ ve $I_E \approx I_C$ kabulleriyle KVL yazıp $I_C = \beta I_B$ koyarak $I_B$'yi yalnız bırakmaktı. Tasarım sorusunda bu yol tersine işletildi: verilen çalışma noktasından $V_E$, $V_B$ ve $V_C$ bulunup dirençler hesaplandı.

İkinci yarıda gerilim kontrollü elemanlar olan FET'lere giriş yapıldı. JFET'te $V_{GS}$ geçiş bölgesini genişletip kanalı daraltır; akım Shockley denklemiyle $I_{DSS}$'den ($V_{GS} = 0$) sıfıra ($V_{GS} = V_P$) iner. D-MOSFET aynı denklemi kullanır ama yalıtılmış gate sayesinde pozitif $V_{GS}$ ile kanalı genişletebilir. E-MOSFET'te ise kanal yoktur, $V_T$'yi aşan bir $V_{GS}$ ile oluşturulur ve akım $k(V_{GS} - V_T)^2$ ile verilir. Hoca FET'lerle ilgili kalan kısımların ve soru çözümlerinin sonraki derslerde işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
