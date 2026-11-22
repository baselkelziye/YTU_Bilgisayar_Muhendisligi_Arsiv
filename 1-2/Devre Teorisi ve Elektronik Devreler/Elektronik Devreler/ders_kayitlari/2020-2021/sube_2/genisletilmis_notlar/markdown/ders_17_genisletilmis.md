# Ders 17 Genişletilmiş Notu: BJT DC Kutuplama (Q Noktası, Sabit, Emiter Kararlı ve Gerilim Bölücü Kutuplama)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin akışı ve kutuplamanın tanımı
- 2. Çalışma noktası (Q noktası) ve çıkış karakteristiği
- 3. Sabit kutuplama devresi
- 4. Emiter kararlı kutuplama devresi
- 5. Gerilim bölücü kutuplama ve düğüm gerilimleri
- 6. Kolektör geri beslemeli yapı
- 7. Transistörün anahtar olarak kullanılması
- 8. Arıza bulma ipuçları ve PNP transistör
- 9. Çözümlü örnekler
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin akışı ve kutuplamanın tanımı

Önceki derste transistörün iç yapısı anlatılmış, çözümde kullanılan KVL ve KCL mantığına girilmiş, örnek sorulara kısaca başlanmıştı. Bu derste önce aynı sunum hızlıca tekrar edildi, ardından ikinci bir sunumdaki çözümlü örneklere geçildi. Slaytlar İngilizcedir ve hoca slaytların üzerine kalemle çizerek anlattı.

Slayttaki tanım şöyledir: kutuplama (biasing), transistörü iletime sokmak ve AC işareti yükseltebilmesini sağlamak için ona uygulanan DC gerilimlerdir (ekrandan, 00:05:00). Hoca bunu şöyle açıkladı: transistör bir anahtarlama elemanıdır. Baz-emiter ve baz-kolektör eklemleri transistörün çalışma ilkesine uygun polarlanırsa bazdan gelen akım, kolektörden emitere geçen akımı denetler. Yani amaç, bazdaki akıma göre kolektör-emiter arasındaki $I_C$ akımını kontrol etmektir.

NPN transistörde doğru polarma şöyledir: kolektöre $V_{CC}$ beslemesi verilir, emiter toprağa (GND) bağlanır. Bazdan akım geldiğinde baz-emiter eklemi doğru, baz-kolektör eklemi ters polarlanmış olur.

## 2. Çalışma noktası (Q noktası) ve çıkış karakteristiği

### 2.1 Çıkış eğrileri ve üç bölge

Slaytta bir transistörün çıkış karakteristiği vardır: yatay eksende $V_{CE}$ (V), düşey eksende $I_C$ (mA). Her eğri bir baz akımına karşılık gelir: $I_B = 0, 10, 20, \dots, 80$ µA. Grafikte doyum (saturation), kesim (cutoff), $I_{C_{max}}$, $V_{CE_{max}}$, $V_{CE_{sat}}$ ve $P_{C_{max}}$ eğrisi işaretlidir (ekrandan, 00:10:00). Slayttaki cümle: DC giriş, Q noktası denen bir çalışma noktası (quiescent point) belirler.

Grafik üç bölgeden oluşur: transistörün etkin çalışmadığı iki bölge ve arada etkin çalışma bölgesi, yani aktif bölge (active region).

**Doyum bölgesi.** Kolektör-emiter gerilimi $V_{CE}$ sıfır ise kolektör ile emiter arasında gerilim oluşmaz, aradaki yol direnci olmayan bir kablo gibi davranır ve $I_C$ en büyük değerini alır. Bu akıma $I_{C(sat)}$ ya da $I_{C_{max}}$, yani doyumdaki kolektör akımı denir. Hoca, gerçekte $V_{CE}$'nin tam sıfır olmadığını, sıfıra çok yakın bir $V_{CE(sat)}$ değeri bulunduğunu belirtti. Grafiğin sol kenarındaki bu dar şerit etkin bir çalışma bölgesi değildir; akım denetimsiz geçer.

> **Ders sonrası not:** Hoca doyum bölgesini anlatırken bir yerde "transistördeki kesim bölgesi" dedi (00:25:24 civarı); kastettiği doyum bölgesidir. Kesim bölgesi aşağıda anlatılan ikinci bölgedir.

**Kesim bölgesi.** $I_C$ akımının hiç olmadığı durumdur. Kolektör-emiter gerilimi ne kadar büyük olursa olsun akım yoksa transistör kesimdedir. Transistör baz akımıyla $I_C$'yi denetleyen bir eleman olduğuna göre $I_C = 0$ iken ortada bir denetim, yani transistör çalışması yoktur.

### 2.2 Yük doğrusunun uç noktaları

Hoca grafiğin eksen sınırlarının nasıl bulunduğunu adım adım anlattı.

**Yatay eksendeki uç ($I_C = 0$).** İki noktaya da $+V$ verilirse aralarında potansiyel fark olmaz ve akım oluşmaz. Aynı şekilde $I_C = 0$ ise dirençlerde gerilim düşmez ve $V_{CE} = V_{CC}$ olur. Bu değer aktif bölgenin yatay eksende alabileceği en büyük değerdir ($V_{CE_{max}}$).

**Düşey eksendeki uç ($V_{CE} = 0$).** Kolektöre bir $R_C$ direnci bağlıysa kolektör çevresinde

$$I_C = \frac{V_{CC} - V_{CE}}{R_C}$$

yazılır. $V_{CE} = 0$ konunca $I_{C(sat)} = V_{CC}/R_C$ bulunur.

Hoca bu denklemin mantığını KVL ile açıkladı: seri iki gerilim kaynağı ve bir dirençten oluşan bir çevrede kaynakların ürettiği gerilim, direnç üzerinde $I \cdot R$ olarak "sömürülmelidir"; örneğin iki kaynak $V$'şer gerilim veriyorsa $2V = I R$ olur ve akım buradan çekilir. Transistör analizinde de $V_{CC}$ bir kaynak, $V_{CE}$ öteki kaynak gibi alınır; aradaki dirençten geçen akım bu iki noktanın potansiyel farkının dirence bölümüdür.

**Soru:** Üst sınırı, yani $I_C$'nin üst sınırını bulmayı bir daha anlatır mısınız?
**Cevap:** $I_C$ baz akımına bağlı oluşur, çünkü $I_C = \beta I_B$'dir; $\beta$ transistörün iç yapısından gelen bir katsayıdır. Transistör akım kontrollü bir elemandır: $I_B$ değişince $I_C$, dolayısıyla $V_{CE}$ de değişir. Çalışma bölgesi dışındaki iki uç bulunur. Birincisi $I_C$'nin hiç oluşmadığı durumdur; bunun için $V_{CC} = V_{CE}$ olmalıdır, bu da $V_{CE_{max}}$'tır. İkincisi $V_{CE} = 0$ durumudur; o zaman akım en büyüktür ve $V_{CC}/R_C$ ile bulunur. İkisinin arası aktif bölgedir.

### 2.3 Q noktası

İki uç noktayı birleştiren doğru, DC yük doğrusudur (load line). Aktif bölgedeki hangi noktada çalışılacağını üçüncü parametre olan $I_B$ belirler. Hoca, grafikte örneğin $I_B = 60$ µA verilirse en verimli çalışma noktasının yük doğrusunun 60 µA eğrisiyle kesiştiği yer olacağını gösterdi (ekrandan, 00:20:00). Yani Q noktası, yük doğrusu ile $I_C = \beta I_B$ ilişkisinden gelen $I_B$ eğrisinin kesişimidir.

### 2.4 Q noktası neye göre değişir

- $V_{CC}$ değişirse iki uç da değişir: $V_{CC}$ artarsa $I_{C(sat)}$ yukarı, $V_{CC}$ ucu sağa kayar; yük doğrusu paralel kayar ve Q noktası da kayar.
- Yalnız $R_C$ değişirse yalnız $I_{C(sat)}$ ucu değişir. Daha büyük $R_C$ daha küçük $I_{C(sat)}$ demektir. $V_{CC}$ ile oynanmadığı için yatay eksendeki uç sabit kalır.
- $\beta$ değişirse $\beta I_B$ değişir ve Q noktası yük doğrusu üzerinde hareket eder.

Hoca bu konuda şöyle bir soru tipi olabileceğini söyledi: bir Q noktası verilir ve bu noktanın devre için uygun olup olmadığı sorulur. Nokta yük doğrusunun dışında kalıyorsa ya $R_C$ küçültülerek $I_{C(sat)}$ büyütülür ya da besleme gerilimi artırılarak yük doğrusu paralel kaydırılır.

## 3. Sabit kutuplama devresi

Slayttaki sabit kutuplama (fixed bias) devresinde $V_{CC}$, baza $R_B$ üzerinden, kolektöre $R_C$ üzerinden bağlıdır; emiter doğrudan topraktadır. Girişte $C_1$, çıkışta $C_2$ kondansatörü vardır (ekrandan, 00:25:00).

DC analiz yapıldığı için kondansatörler ve AC giriş-çıkış kısımları devre dışı kalır. Kondansatör AC'de, frekans düzleminde dolup boşalarak etkili olur; DC analizde yalnız DC yollar incelenir.

> **Ders sonrası not:** Hoca burada kondansatörlü kısımların "kısa devre edildiğini" söyledi. DC analizde kondansatörler açık devre kabul edilir; hoca dersin ilerleyen kısmında (01:03:24 civarı) bunu doğru biçimde açık devre olarak söyledi. Slaytta da kondansatörlerin üzeri çizilerek devreden çıkarılmıştır.

Hoca analizi süperpozisyona benzer biçimde iki çevreye ayırdı: (1) $V_{CC}$, $R_B$, baz-emiter yolu; (2) $V_{CC}$, $R_C$, kolektör-emiter yolu.

**Birinci çevre.** $V_{CC}$ ile baz arasındaki potansiyel fark $V_{CC} - V_{BE}$'dir ve bu, $R_B$ üzerindeki düşüme eşit olmalıdır (ekrandan, 00:25:00):

$$V_{CC} - V_{BE} = I_B R_B$$

$V_{BE}$ transistör malzemesine göre alınır: silisyum için 0,7 V, germanyum için 0,3 V. Sorularda genelde bu ikisi gelir. Hoca üçüncü bir malzeme için 1,2 V değerini de andı, ama hangi malzeme olduğundan emin olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** 1,2 V değeri büyük olasılıkla galyum arsenit (GaAs) içindir; bazı ders kitapları GaAs diyotun eşik gerilimini yaklaşık 1,2 V olarak verir.

$V_{CC}$ ve $R_B$ biliniyorsa $I_B$ bulunur. $\beta$ verilmişse $I_C = \beta I_B$ ile $I_C$ bulunur.

**İkinci çevre.** $I_C R_C$, $R_C$ üzerindeki gerilimdir. $V_{CC}$'den bu düşüm çıkarılınca geriye kalan $V_{CE}$'dir:

$$V_{CE} = V_{CC} - I_C R_C$$

Slayttaki notta bu $V_{CC} - V_{R_C} = V_{CE}$ biçiminde yazılmıştır.

**Doyum ve kesim.** $V_{CE} = 0$ iken $I_{C(sat)} = V_{CC}/R_C$; $I_C = 0$ iken $V_{CE} = V_{CC}$. Bu iki nokta arasında çizilen yük doğrusu üzerinde, hesaplanan $\beta I_B$ değerlerinin düştüğü noktalar en verimli çalışma noktalarıdır.

## 4. Emiter kararlı kutuplama devresi

Bu devrede öncekinden tek fark emiter bacağına bir $R_E$ direncinin eklenmesidir. Slayttaki cümle: emiter devresine $R_E$ eklemek kutuplama devresini kararlı hâle getirir (ekrandan, 00:30:00). Hoca, emiterin doğrudan değil bir direnç üzerinden toprağa bağlanmasının transistörün daha kararlı çalışmasını sağladığını söyledi.

### 4.1 Baz-emiter çevresi

Çevre denklemi (ekrandan, 00:35:00):

$$0 = V_{CC} - I_B R_B - V_{BE} - I_E R_E$$

$V_{BE} = 0{,}7$ V'tur; hoca transistörün içinde diyot yapısı bulunduğunu, silisyum diyotlardaki 0,7 V eşiğin buradan geldiğini hatırlattı.

Denklemde çok bilinmeyen var gibi görünür, ama bilinmeyenler birbiri cinsinden yazılabilir. $I_E = I_C + I_B$'dir. $I_B$ çok küçük olduğu için çoğu zaman $I_E \approx I_C$ denir, ama bu denklemde $I_B$ arandığı için $I_E$'yi $I_B$ cinsinden yazmak daha mantıklıdır. $I_C = \beta I_B$ olduğundan

$$I_E = \beta I_B + I_B = (\beta + 1) I_B$$

olur. Bunu yerine koyup $I_B$'yi yalnız bırakınca:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E}$$

$V_{CC}$, $V_{BE}$, $R_B$ ve $R_E$ biliniyorsa $I_B$ bulunur.

### 4.2 Kolektör-emiter çevresi

$$V_{CC} - I_C R_C - V_{CE} - I_E R_E = 0$$

Bu çevrede $I_E \approx I_C$ alınır, çünkü $I_B$ çok küçüktür:

$$V_{CC} - V_{CE} = I_C (R_C + R_E) \quad\Rightarrow\quad I_C = \frac{V_{CC} - V_{CE}}{R_C + R_E}$$

> **Hocanın vurgusu:** Soruyu çözdüğünüzde $I_B$'yi kolektör ve emiter akımına göre çok çok küçük bir değer (genelde mikroamper) bulmadıysanız soruyu büyük olasılıkla yanlış çözmüşsünüzdür; tekrar kontrol edin.

**Uç noktalar.** $V_{CE} = 0$ konunca $I_{C(sat)} = V_{CC}/(R_C + R_E)$. $I_C = 0$ ise $R_C$ üzerinde gerilim düşmez; $I_E$ de sıfır kabul edilir, $R_E$ üzerinde de gerilim düşmez ve $V_{CE} = V_{CC}$ olur. Bu iki nokta arasında yük doğrusu çizilir; doğrunun üzerindeki $I_B$ eğrisiyle kesişim Q noktasıdır.

## 5. Gerilim bölücü kutuplama ve düğüm gerilimleri

### 5.1 Baz geriliminin bulunması

Bu devrede baz, $R_1$ ve $R_2$ dirençlerinden oluşan bir gerilim bölücüyle beslenir. Kondansatörler yine DC analizde göz ardı edilir. Önceki devrelerde baz çevresi doğrudan $V_{CC}$'den yazılabiliyordu; burada önce baz gerilimi $V_B$ bulunmalıdır. Baz, $R_2$ üzerinden toprağa bağlı olduğu için $V_B$, $R_2$ üzerindeki gerilimdir. Slayttaki yaklaşık analiz (ekrandan, 00:40:00), $I_B \ll I_1$ ve $I_1 \cong I_2$ koşulunda:

$$V_B = \frac{R_2 V_{CC}}{R_1 + R_2}$$

Sonra baz çevresi $V_{CC}$ yerine $V_B$ ile aynı biçimde yazılır:

$$V_B - V_{BE} - I_E R_E = 0$$

Hoca, $I_E = (\beta + 1) I_B$ yazılarak $I_B$'nin buradan çekilebileceğini söyledi. Kolektör tarafının analizi emiter kararlı devreyle aynıdır. Slayttaki diğer formüller, $\beta R_E > 10 R_2$ koşulunda:

$$I_E = \frac{V_E}{R_E}, \qquad V_E = V_B - V_{BE}, \qquad V_{CE} = V_{CC} - I_C R_C - I_E R_E \approx V_{CC} - I_C (R_C + R_E)$$

### 5.2 Düğüm gerilimleri ($V_E$, $V_C$, $V_{BC}$)

Hoca sorularda düğüm gerilimlerinin de sorulabileceğini söyledi.

- $V_{BE}$, baz ile emiter arasındaki farktır. Bu yüzden $V_E = V_B - V_{BE}$ olur; bu, $R_E$ üzerindeki gerilimdir (emiter $R_E$ üzerinden toprağa bağlı). $V_E$, $I_E R_E$ ile de bulunabilir, ama $V_B - V_{BE}$ daha pratiktir.
- $V_C$ için iki yol vardır: $V_C = V_{CC} - I_C R_C$ ya da $V_E$ ve $V_{CE}$ biliniyorsa $V_C = V_E + V_{CE}$.
- $V_{BC}$ için ayrıca akım çizmeye gerek yoktur: $V_{BC} = V_B - V_C$.

> **Hocanın vurgusu:** Transistör çok zor değildir. Kurallar adım adım yazılmalıdır. KVL denklemleri doğru kurulursa kimi 7-8 adımda, kimi 3 adımda çözer, ama sonuç aynı çıkar.

**Uç noktalar.** $I_C = 0$ iken hiçbir dirençte gerilim düşmez ve $V_{CE} = V_{CC}$. $V_{CE} = 0$ iken $I_{C(sat)} = (V_{CC} - 0)/(R_C + R_E)$.

## 6. Kolektör geri beslemeli yapı

Bir sonraki slayttaki devrede iki fark vardı: gerilim bölücü yoktur ve baz direnci kolektör direncinden sonra, yani kolektör düğümünden beslenir. <!-- BELİRSİZ: Bu slaytın karesi yok; devre şekli yalnız anlatımdan kurulmuştur. -->

Hoca analizde düğüm analizine (KCL) değindi. Kolektör direncinden geçen akım $I_C'$ olsun. Bu akım düğümde ikiye ayrılır: transistöre giren $I_C$ ve baza giden $I_B$. KCL'ye göre düğüme giren akımlar çıkan akımlara eşittir:

$$I_C' = I_C + I_B$$

Ancak sorularda $I_B$ çok küçük olduğundan ayrı bir kol akımı yokmuş gibi düşünülür ve $I_C' \approx I_C$ alınır. Kolektör gerilimi $V_C = V_{CC} - I_C R_C$ ile bulunur. Baz çevresi bu gerilimden başlayarak yazılır:

$$V_C - I_B R_B - V_{BE} - I_E R_E = 0$$

Hoca, aslında hiçbir şeyin değişmediğini, yalnız küçük bir ön işlem yapmak gerektiğini söyledi. Doyum noktası da aynı biçimde bulunur.

## 7. Transistörün anahtar olarak kullanılması

Hoca, önceki örneklerde giriş ve çıkışın kondansatörler üzerinden AC işaret olduğunu, $V_{CC}$'nin (DC) transistörün çalışması için kullanıldığını hatırlattı. Transistörün anahtarlama özelliği DC girişlerle de kullanılabilir. Slayttaki cümle: yalnız DC kaynak uygulanan transistörler elektronik anahtar olarak kullanılabilir (ekrandan, 00:45:00).

Slayttaki devre: $V_{CC} = 5$ V, $R_C = 0{,}82$ kΩ, $R_B = 68$ kΩ, $h_{FE} = 125$. Giriş $V_i$, 0 V ile 5 V arasında değişen bir kare dalgadır; çıkış $V_C$ kolektörden alınır.

- Giriş 0 V iken baz akımı oluşmaz ($I_B = 0$), transistör kesimdedir ve $I_C$ oluşmaz. Akım geçmediği için $R_C$ üzerinde gerilim düşmez ve $V_C = V_{CC} = 5$ V görülür.
- Giriş 5 V iken $R_B$ üzerinden bir baz akımı oluşur. Bu akım transistörü tetikler, $\beta I_B$ ($125 \cdot I_B$) kadar bir kolektör akımı aşağı akar. Emiter ile toprak arasında direnç olmadığından akım doğrudan toprağa geçer ve $V_C$ yaklaşık 0 V görülür.
- Giriş yeniden 0 V olunca $V_C$ yine 5 V olur. Çıkış girişin tersidir.

**Soru:** Bu devrede transistörün üzerinde bir $V_{CE}$ gerilimi yok mu?
**Cevap:** Bu DC anahtarlama durumunda (iletimde) yoktur; kısa devre gibi davrandığı için akım doğrudan aşağı gider.

Bu devrenin yük doğrusu için $V_{CE} = 0$ konur: $I_{C(sat)} = 5/(0{,}82 \cdot 10^3) \approx 6{,}1$ mA. $I_C$ hiç yoksa $V_{CE} = V_{CC} = 5$ V. Böylece yatay ucu 5 V, düşey ucu 6,1 mA olan bir çalışma doğrusu çıkar. Farklı $I_B$ değerleri $\beta$ ile çarpılarak bu doğru üzerinde örnek noktalar bulunabilir; örneğin 10 µA baz akımı yaklaşık 1 mA'lik bir kolektör akımı verir.

> **Ders sonrası not:** Hoca $I_{C(sat)}$ için bir yerde "6,1 amper" dedi; doğrusu $5\text{ V}/0{,}82\text{ k}\Omega \approx 6{,}10$ mA'dir. 10 µA için $125 \cdot 10$ µA $= 1{,}25$ mA'dir (hoca "hemen hemen 1 mA" dedi; altyazıda bir yerde "10 mA" geçiyor, kastedilen 10 µA'dir). Değerler python ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Giriş 5 V iken $I_B = (5 - 0{,}7)/68\text{ k}\Omega \approx 63{,}2$ µA olur ve $\beta I_B \approx 7{,}9$ mA, $I_{C(sat)} \approx 6{,}1$ mA'den büyüktür. Bu yüzden transistör doyuma gider ve kolektör akımı $I_{C(sat)}$ ile sınırlanır; $V_C$'nin yaklaşık 0 V olmasının nedeni budur. Anahtar tasarımında $I_B > I_{C(sat)}/\beta$ koşulu aranır.

Hoca anahtarlamanın çok hızlı bir işlem olmadığını, transistörde gecikmeler bulunduğunu, ama bu gecikme hesaplarına girmeyeceğini söyledi.

**Soru:** NPN transistörde baz akımı verince transistör kısa devre gibi çalışıyordu; burada nasıl tetikleniyor?
**Cevap:** Bu bir NPN transistördür; baza pozitif bir işaret, pozitif yönde bir akım verildiğinde çalışır. Tersi olan PNP transistörde negatif verilmesi gerekir.

**Soru:** O zaman transistörü, gelen akıma göre direnci değişen bir yapı gibi düşünebilir miyiz? Gelen $I_B$ akımını belli bir çarpanla (burada 125) çarparak akımı düzenliyor.
**Cevap:** Evet. $I_B$ ile oynayarak $I_C$ ile oynanabildiği için, reostadaki bir dirençle akımı ayarlar gibi düşünülebilir. Bu bir yükseltme (amplify) işlemidir, akım yükseltilir ya da düşürülür.

## 8. Arıza bulma ipuçları ve PNP transistör

Slayttaki arıza bulma ipuçları (ekrandan, 00:50:00):

- Yaklaşık gerilimler: silisyum transistörlerde $V_{BE} \cong 0{,}7$ V; $V_{CE} \cong V_{CC}$'nin %25'i ile %75'i arası.
- Açık ve kısa devreleri ohmmetreyle test edin.
- Lehim bağlantılarını test edin.
- Transistörü bir transistör test cihazı ya da eğri çizici (curve tracer) ile test edin.
- Yükün ya da sonraki katın transistörün çalışmasını etkilediğini unutmayın.

Hoca $V_{CE}$ maddesini şöyle yorumladı: derste teorik olarak doyumda $V_{CE}$ sıfır alınıyor, gerçekte ise $V_{CE}$, $V_{CC}$'nin %25'i ile %75'i arasında olur.

> **Ders sonrası not:** Slayttaki %25-%75 aralığı, büyük olasılıkla aktif bölgede (doğrusal yükselteç olarak) çalışan iyi kutuplanmış bir transistörde ölçülmesi beklenen $V_{CE}$ değeridir; doyumdaki $V_{CE(sat)}$ ise sıfıra yakın küçük bir değerdir (genelde birkaç yüz milivolt). İki kavram karıştırılmamalıdır.

PNP transistörlerde analiz NPN ile aynıdır; yalnız akım yönleri farklıdır, formüllerin hepsi aynı kalır.

## 9. Çözümlü örnekler

Hoca diyot örneklerini sonraya bırakıp doğrudan transistör örneklerine geçti. Bu kısımda slaytlar ders kitabındaki çözümlü örneklerdir.

### 9.1 Sabit kutuplama örneği

Verilenler (ekrandan, 00:55:00): $V_{CC} = +12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$, giriş ve çıkış kondansatörleri 10 µF. İstenenler: (a) $I_{B_Q}$ ve $I_{C_Q}$, (b) $V_{CE_Q}$, (c) $V_B$ ve $V_C$, (d) $V_{BC}$.

Hoca devrenin en basit transistör devresi olduğunu söyledi: emiterde direnç yoktur, yani $V_{CC}$'den düşen gerilimin tamamı $I_C R_C$ üzerindedir. Sorudaki "Q" indisi özel bir şey istemez: grafik sorusu değilse ve başka bir $I_B$ verilmemişse, devre çözülünce bulunan değerler zaten Q noktasının değerleridir.

**(a)** Baz çevresi: $12 - I_B R_B - 0{,}7 = 0$ (ekrandan, 01:00:00).

$$I_{B_Q} = \frac{V_{CC} - V_{BE}}{R_B} = \frac{12 - 0{,}7}{240\text{ k}\Omega} = 47{,}08\ \mu\text{A}$$

Bulunan değer mikroamper mertebesindedir, yani doğru olma olasılığı yüksektir.

$$I_{C_Q} = \beta I_{B_Q} = 50 \cdot 47{,}08\ \mu\text{A} = 2{,}35\text{ mA}$$

**(b)**

$$V_{CE_Q} = V_{CC} - I_C R_C = 12 - (2{,}35\text{ mA})(2{,}2\text{ k}\Omega) = 6{,}83\text{ V}$$

Emiterde bir direnç olsaydı bu kadar kısa yazılamaz, $I_C (R_C + R_E)$ kullanılırdı.

**Yük doğrusu.** Hoca slaytın yanına yük doğrusunu çizdi: yatay uç $V_{CE} = 12$ V; düşey uç $I_{C(sat)} = 12/2{,}2\text{ k}\Omega$ (hoca "5,1 gibi" dedi). Bulunan $V_{CE} = 6{,}83$ V noktasının karşılığı $I_C = 2{,}35$ mA'dir; bu nokta yük doğrusunun üzerindedir. Yani Q noktası grafikten de formülden de bulunabilir.

> **Ders sonrası not:** $12\text{ V}/2{,}2\text{ k}\Omega = 5{,}45$ mA'dir (python ile doğrulandı). Hocanın tahtaya yazdığı "5,1" değeri yaklaşıktır.

**(c)** Baz gerilimini aşağıdan bulmak daha kolaydır: emiter doğrudan topraktadır, arada gerilim düşümü yoktur, dolayısıyla $V_B = V_{BE} = 0{,}7$ V. Emiterde direnç olsaydı $V_B = 0{,}7 + I_E R_E$ olurdu. Aynı nedenle $V_C = V_{CE} = 6{,}83$ V.

**(d)** Çift indis gösterimiyle:

$$V_{BC} = V_B - V_C = 0{,}7 - 6{,}83 = -6{,}13\text{ V}$$

**Soru:** Son (d) şıkkını, neden eksi çıktığını tekrar eder misiniz?
**Cevap:** Transistörün ileri yönlü, yani aktif çalışması için iki koşul vardır: baz-emiter doğru, baz-kolektör ters polarlanmalıdır. Bu NPN transistörde emitere N tarafı (toprak), P olan baza pozitif verildi; baz-emiter doğru polarlandı. Kolektöre de pozitif verildi; baz-kolektör eklemi ters polarlandı. $V_B$'den daha büyük pozitif olan $V_C$ çıkarıldığı için sonuç negatif çıkar. Bu, baz ile kolektörün ters polarlandığını, yani transistörün doğru çalıştığını gösteren bir işarettir.

> **Hocanın vurgusu:** $V_{BC}$'nin eksi çıkması normaldir ve beklenir; transistörün doğrusal yükseltme için uygun çalıştığını gösterir.

### 9.2 Emiter kararlı kutuplama örneği

Verilenler (ekrandan, 01:05:00): $V_{CC} = +20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ, $\beta = 50$; giriş ve çıkış kondansatörleri 10 µF, emiter kondansatörü 40 µF. İstenenler: (a) $I_B$, (b) $I_C$, (c) $V_{CE}$, (d) $V_C$, (e) $V_E$, (f) $V_B$, (g) $V_{BC}$.

Tek fark emiterdeki $R_E$ direncidir. Bu yüzden kolektör gerilimi artık $V_{CE}$'ye eşit değil, $V_{CE} + V_E$'dir.

**Soru:** Devreye neden kondansatör eklenmiş, analizimizle bir ilgisi yok mu?
**Cevap:** Kondansatörler AC'yi ilgilendiren elemanlardır. Devre DC ile besleniyorsa ve bir süre beklenirse kondansatör dolar ve açık devre gibi davranır; kaynak kaldırılınca boşalma davranışı hesaplanır. AC uygulamalarda çıkışın daha kararlı olmasını sağlar, istenmeyen etkileri engeller. Transistörün DC analizinde kondansatörler hiçbir zaman hesaba katılmaz.

**(a)** Hoca baz çevresini tahtaya $20 - 430\cdot 10^3 \cdot I_B - 0{,}7 - 1\cdot 10^3 \cdot I_E = 0$ olarak yazdı (ekrandan, 01:05:00). $I_E = (\beta + 1) I_B$ yazılırsa:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E} = \frac{20 - 0{,}7}{430\text{ k}\Omega + (51)(1\text{ k}\Omega)} = \frac{19{,}3\text{ V}}{481\text{ k}\Omega} = 40{,}1\ \mu\text{A}$$

Hoca, $R_E$ yalnız 1 kΩ olduğu için $I_B$'nin buradaki etkisinin küçük kalacağını, ama yine de $(\beta+1)$ ile yazmak gerektiğini söyledi.

> **Hocanın vurgusu:** Birimler kesinlikle düzgün yazılmalıdır; mili ve mikroamper karıştırılmamalıdır.

**(b)**

$$I_C = \beta I_B = (50)(40{,}1\ \mu\text{A}) \cong 2{,}01\text{ mA}$$

**(c)** $R_C$ ve $R_E$ birlikte 3 kΩ'luk düşüm oluşturur:

$$V_{CE} = V_{CC} - I_C (R_C + R_E) = 20 - (2{,}01\text{ mA})(3\text{ k}\Omega) = 20 - 6{,}03 = 13{,}97\text{ V}$$

**(d), (e), (f), (g)** Hoca kalan şıkları sözlü çözdü; slaytın bu kısmı karelerde görünmüyor. Ara değerler python ile hesaplandı (ara adım eklendi).

- $V_C$ iki yoldan bulunabilir: $V_C = V_{CE} + V_E = 13{,}97 + 2{,}01 \approx 15{,}98$ V ya da $V_C = V_{CC} - I_C R_C = 20 - 2{,}01 \cdot 2 = 15{,}98$ V. Hoca "15,97 gibi" dedi.
- $V_E = I_E R_E \approx I_C R_E = 2{,}01\text{ mA} \cdot 1\text{ k}\Omega \approx 2{,}01$ V ya da $V_E = V_C - V_{CE}$. Hoca "2 V gibi bir değer" dedi.
- $V_B$: emiterde direnç olduğu için artık $V_B = V_{BE}$ değildir; $V_B = V_{BE} + V_E = 0{,}7 + 2{,}01 = 2{,}71$ V.
- $V_{BC} = V_B - V_C = 2{,}71 - 15{,}98 \approx -13{,}27$ V. Yine eksi çıkar, çünkü baz-kolektör ters polarlanmıştır.

> **Ders sonrası not:** Hoca (d) şıkkı için "$20 - I_C \cdot 3\text{ k} - V_{CE}$" denkleminden çıkan 13,97 değerine bir an "$V_C$" dedi; 13,97 V, $V_{CE}$'dir. $V_C \approx 15{,}98$ V'tur (python ile doğrulandı).

### 9.3 Gerilim bölücü kutuplama örneği

Verilenler (ekrandan, 01:10:00): $V_{CC} = +22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ, $\beta = 140$; giriş ve çıkış kondansatörleri 10 µF, emiter kondansatörü 50 µF. İstenen: DC kutuplama gerilimi $V_{CE}$ ve akım $I_C$.

Tek fark baz geriliminin önce bulunmasıdır. Hoca tahtaya şunu yazdı (ekrandan, 01:10:00):

$$V_B = \frac{22 \cdot 3{,}9 \cdot 10^3}{39 \cdot 10^3 + 3{,}9 \cdot 10^3} = 2\text{ V}$$

Hoca bu örneği uzun uzadıya çözmedi, slaytta çözümün bulunduğunu söyledi ve yöntemi şöyle özetledi: Thévenin eşdeğerinde $E_{Th}$ aslında $V_B$ gerilimidir ve 2 V çıkar. $R_{Th}$ girişteki paralel dirençlerin eşdeğeridir. $I_B$ için

$$I_B = \frac{E_{Th} - V_{BE}}{R_{Th} + (\beta + 1) R_E}$$

yazılır. $I_B$, $\beta$ ile çarpılınca $I_C$ bulunur. Son olarak $V_{CE} = V_{CC} - I_C (R_C + R_E)$.

> **Hocanın vurgusu:** Kontrolü her zaman yapın: akımlardan biri ($I_B$) mikroamper, diğeri ($I_C$) miliamper mertebesinde olur.

Sayısal sonuçlar derste sesli okunmadı ve çözüm slaytı karelerde görünmüyor.

> **Çözüm (derste verilmedi):** $R_{Th} = 39 \parallel 3{,}9 = 3{,}545$ kΩ. $I_B = (2 - 0{,}7)/(3{,}545\text{ k} + 141 \cdot 1{,}5\text{ k}) = 1{,}3/215{,}0\text{ k} \approx 6{,}05$ µA. $I_C = 140 \cdot 6{,}05$ µA $\approx 0{,}85$ mA. $V_{CE} = 22 - 0{,}85\text{ mA}(10 + 1{,}5)\text{ k}\Omega \approx 12{,}2$ V (yuvarlamadan 12,27 V). Yaklaşık analiz koşulu da sağlanır: $\beta R_E = 210$ kΩ $> 10 R_2 = 39$ kΩ; yaklaşık analizle $I_E = 1{,}3/1{,}5 \approx 0{,}87$ mA ve $V_{CE} \approx 12{,}03$ V çıkar. Değerler python ile hesaplandı.

### 9.4 Kondansatörlü kolektör geri besleme örneği

Hoca bir sonraki örnekte yine kondansatörler bulunduğunu, DC'de kararlı durumda oldukları kabul edildiği için açık devre sayılacaklarını söyledi; bu kondansatörler kararlılığı artırmak için eklenmiştir. İstenenler $I_B$ ve $V_C$'dir. Anlatıma göre baz yolu $V_{CC}$'den 110 kΩ ve 91 kΩ'luk iki seri dirençten geçer; kolektör çevresinde ise $I_C \approx I_E$ olduğundan 18 V'u "sömüren" düşüm $I_C (3{,}3\text{ k} + 510\ \Omega)$ olarak yazılır. Önce $I_B$ baz çevresinden bulunur, sonra $I_C = \beta I_B$ ve $V_C$ hesaplanır.

<!-- BELİRSİZ: Bu örneğin karesi yok. Devre şekli, $\beta$ değeri ve sonuçlar ekranda doğrulanamadı; dirençler (110 kΩ, 91 kΩ, 3,3 kΩ, 510 Ω) ve 18 V yalnız altyazıdan alınmıştır. -->

### 9.5 Kolektör geri besleme örneği ($V_{CC} = 20$ V)

Benzer bir yapıdaki bu örnekte $V_{CC} = 20$ V'tur. Hoca baz yolunu ($V_{CC}$, $R_C$, $R_B$, baz-emiter) izleyerek şu sonuca ulaştı:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta R_C}$$

$\beta R_C$ teriminin nedeni şudur: çevrede $I_B R_B$ ve $I_C R_C$ düşümleri vardır; $I_C = \beta I_B$ yazılınca $I_C R_C = \beta I_B R_C$ olur ve $I_B$ ortak paranteze alınır. $I_B$ (mikroamper mertebesinde) bulunduktan sonra $\beta$ ile çarpılıp $I_C$ elde edilir. Son olarak $V_C = V_{CC} - I_C R_C$ ile kolektör gerilimi bulunur.

<!-- BELİRSİZ: Bu örneğin karesi yok; $R_B$, $R_C$, $\beta$ değerleri ve sayısal sonuçlar altyazıda geçmiyor. -->

### 9.6 Tersten tasarım örneği

Hoca soruların tersten de sorulabileceğini gösterdi. Verilenler (ekrandan, 01:15:00): $I_{C_Q} = 2$ mA, $V_{CE_Q} = 10$ V, $V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ. İstenen: $R_1$ ve $R_C$.

Hiçbir şey değişmez, yalnız $R_1$ bilinmeyen olarak kalır. Bilinenlerden başlanır:

$$V_E = I_E R_E \cong I_C R_E = (2\text{ mA})(1{,}2\text{ k}\Omega) = 2{,}4\text{ V}$$

($I_C$, $I_E$'ye çok yakındır.)

$$V_B = V_{BE} + V_E = 0{,}7 + 2{,}4 = 3{,}1\text{ V}$$

Bu, gerilim bölücü ifadesine eşitlenir:

$$\frac{(18\text{ k}\Omega)(18\text{ V})}{R_1 + 18\text{ k}\Omega} = 3{,}1\text{ V} \;\Rightarrow\; 324\text{ k}\Omega = 3{,}1 R_1 + 55{,}8\text{ k}\Omega \;\Rightarrow\; R_1 = \frac{268{,}2\text{ k}\Omega}{3{,}1} = 86{,}52\text{ k}\Omega$$

$R_C$ için $R_C$ üzerindeki gerilim $18 - V_C$'dir ve bu $2\text{ mA} \cdot R_C$'ye eşittir:

$$V_C = V_{CE} + V_E = 10 + 2{,}4 = 12{,}4\text{ V}, \qquad R_C = \frac{V_{CC} - V_C}{I_C} = \frac{18 - 12{,}4}{2\text{ mA}} = 2{,}8\text{ k}\Omega$$

Slaytta ayrıca $R_1$ için en yakın standart değerlerin 82 kΩ ve 91 kΩ olduğu, 82 kΩ ile 4,7 kΩ'un seri bağlanmasıyla (86,7 kΩ) tasarım değerine çok yaklaşılabileceği yazıyor (ekrandan, 01:15:00).

Hoca sonraki slaytın op-amp ile ilgili olduğunu ve ona daha sonra değinileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:55:00): Şekildeki sabit kutuplama devresi için ($V_{CC} = 12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$) şunları bulun: (a) $I_{B_Q}$ ve $I_{C_Q}$, (b) $V_{CE_Q}$, (c) $V_B$ ve $V_C$, (d) $V_{BC}$.

> **Çözüm (derste verildi):** $I_{B_Q} = 11{,}3/240\text{ k} = 47{,}08$ µA, $I_{C_Q} = 2{,}35$ mA, $V_{CE_Q} = 12 - 2{,}35 \cdot 2{,}2 = 6{,}83$ V, $V_B = 0{,}7$ V, $V_C = 6{,}83$ V, $V_{BC} = -6{,}13$ V (ters polarma). Ayrıntı: Bölüm 9.1.

**Soru 2** (ekrandan, 01:05:00): Şekildeki emiter kararlı devre için ($V_{CC} = 20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ, $\beta = 50$) şunları bulun: (a) $I_B$, (b) $I_C$, (c) $V_{CE}$, (d) $V_C$, (e) $V_E$, (f) $V_B$, (g) $V_{BC}$.

> **Çözüm (derste verildi; d-g sözlü):** $I_B = 19{,}3/481\text{ k} = 40{,}1$ µA, $I_C \cong 2{,}01$ mA, $V_{CE} = 13{,}97$ V, $V_C \approx 15{,}98$ V, $V_E \approx 2{,}01$ V, $V_B \approx 2{,}71$ V, $V_{BC} \approx -13{,}27$ V. (d)-(g) değerleri python ile hesaplandı. Ayrıntı: Bölüm 9.2.

**Soru 3** (ekrandan, 01:10:00): Şekildeki gerilim bölücü devre için ($V_{CC} = 22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ, $\beta = 140$) DC kutuplama gerilimi $V_{CE}$'yi ve $I_C$ akımını bulun.

> **Çözüm (derste verilmedi):** Derste yalnız $V_B = E_{Th} = 2$ V bulundu ve yöntem anlatıldı. $R_{Th} \approx 3{,}55$ kΩ, $I_B \approx 6{,}05$ µA, $I_C \approx 0{,}85$ mA, $V_{CE} \approx 12{,}2$ V. Python ile hesaplandı. Ayrıntı: Bölüm 9.3.

**Soru 4** (ekrandan, 01:15:00): $I_{C_Q} = 2$ mA ve $V_{CE_Q} = 10$ V olduğuna göre şekildeki devrede ($V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ) $R_1$ ve $R_C$ değerlerini bulun.

> **Çözüm (derste verildi):** $V_E = 2{,}4$ V, $V_B = 3{,}1$ V, $R_1 = 86{,}52$ kΩ, $V_C = 12{,}4$ V, $R_C = 2{,}8$ kΩ. Ayrıntı: Bölüm 9.6.

**Soru 5** (ekrandan, 00:45:00): $V_{CC} = 5$ V, $R_C = 0{,}82$ kΩ, $R_B = 68$ kΩ, $h_{FE} = 125$ olan anahtarlama devresine 0 V ile 5 V arasında değişen kare dalga uygulanıyor. Çıkış $V_C$ nasıl olur, $I_{C(sat)}$ nedir?

> **Çözüm (derste verildi):** Giriş 0 V iken kesim, $V_C = 5$ V; giriş 5 V iken transistör iletimde, $V_C \approx 0$ V. Çıkış girişin tersidir. $I_{C(sat)} = 5/0{,}82\text{ k} \approx 6{,}1$ mA. Ayrıntı: Bölüm 7.

## Dersin Toparlaması

Bu derste BJT'nin DC kutuplaması işlendi. Kutuplamanın amacı, baz-emiter eklemini doğru, baz-kolektör eklemini ters polarlayarak transistörü aktif bölgede çalıştırmak ve AC işareti yükseltebilir hâle getirmektir. Çıkış karakteristiği üzerinde kesim ($I_C = 0$, $V_{CE} = V_{CC}$) ve doyum ($V_{CE} = 0$, $I_{C(sat)} = V_{CC}/(R_C + R_E)$) uçlarını birleştiren yük doğrusu çizildi; Q noktası bu doğrunun devredeki $I_B$ eğrisiyle kesişimi olarak tanımlandı. Sabit, emiter kararlı, gerilim bölücü ve kolektör geri beslemeli devrelerin hepsinde yöntem aynıdır: kondansatörler açık devre sayılır, baz çevresinden $I_B$ bulunur ($R_E$ varsa $(\beta+1)R_E$ ile), $I_C = \beta I_B$ ile kolektör akımı, kolektör çevresinden de $V_{CE}$ ve düğüm gerilimleri hesaplanır. $I_B$'nin mikroamper, $I_C$'nin miliamper mertebesinde ve $V_{BC}$'nin negatif çıkması çözümün doğruluğu için iki kontroldür. Transistörün DC girişle anahtar olarak kullanılabileceği de gösterildi.

Hoca diyot örneklerinin sonraki bir derste çözüleceğini ve son slayttaki op-amp konusuna daha sonra değinileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
