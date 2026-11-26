# Ders 15 Genişletilmiş Notu: BJT DC Kutuplama Devreleri Soru Çözümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı ve ortak çözüm yöntemi
- 2. Sabit kutuplama sorusu
- 3. Emetör kararlı kutuplama sorusu
- 4. Gerilim bölücü kutuplama sorusu
- 5. Gerilim bölücü formülünün ve Thevenin eşdeğerinin çıkarılışı
- 6. Kolektör geri beslemeli kutuplama soruları
- 7. Tersten tasarım sorusu: direnç değerlerinin bulunması
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı ve ortak çözüm yöntemi

Önceki hafta diyotlarla ilgili kapsamlı soru çözümleri yapılmıştı. Bu derste aynı biçimde transistörlere geçilir: ders bir problem çözümü dersidir. Hoca, hazır çözümlü soruların bulunduğu bir PDF'i açar ve her soruyu kalemle işaretleyerek adım adım anlatır. Soruların hepsi BJT'nin DC kutuplamasıyla, yani transistörün çalışma noktasındaki (Q noktası) akım ve gerilimlerin bulunmasıyla ilgilidir. Soru metinlerindeki $Q$ indisi ($I_{B_Q}$, $I_{C_Q}$, $V_{CE_Q}$) "çalışma anındaki" baz akımı, kolektör akımı ve kolektör-emetör gerilimi anlamına gelir.

Bütün sorularda aynı yol izlenir:

- Silisyum transistörde baz-emetör gerilimi $V_{BE} = 0{,}7$ V alınır.
- Giriş ve çıkıştaki kuplaj kondansatörleri yalnız AC bileşeni geçirir; DC analizde açık devredir. Emetör direncine paralel köprüleme (bypass) kondansatörü de DC'de etkisizdir.
- Önce baz-emetör çevresinden (giriş çevresi) $I_B$ bulunur.
- Sonra $I_C = \beta I_B$ ve $I_E = (\beta + 1) I_B$ ile diğer akımlar bulunur.
- En sonda kolektör-emetör çevresinden (çıkış çevresi) $V_{CE}$ ve istenen nokta gerilimleri bulunur.

> **Hocanın vurgusu:** Temel kavramlar bilindikten sonra bu soruların geri kalanı yalnız işlemdir. Bu tür sorular sınavda çıkacak konulardandır.

## 2. Sabit kutuplama sorusu

### 2.1 Devre

İlk soru, ortak emetörlü bir npn transistörlü sabit kutuplama (fixed-bias) devresidir (ekrandan, 00:05:00). Emetör ucu toprağa en yakın uçtur, doğrudan toprağa bağlıdır. Hoca bunu en yaygın kullanılan DC kutuplama devrelerinden biri olarak tanıtır.

| Eleman | Bağlantı | Değer |
|---|---|---|
| $V_{CC}$ | besleme | +12 V |
| $R_B$ | $V_{CC}$ ile baz arası | 240 kΩ |
| $R_C$ | $V_{CC}$ ile kolektör arası | 2,2 kΩ |
| $C_1$ | AC giriş ile baz arası | 10 µF |
| $C_2$ | kolektör ile AC çıkış arası | 10 µF |
| $\beta$ | transistör | 50 |

İstenenler: (a) $I_{B_Q}$ ve $I_{C_Q}$, (b) $V_{CE_Q}$, (c) $V_B$ ve $V_C$, (d) $V_{BC}$.

### 2.2 Akımlar

$V_{CC}$'den $R_B$ üzerinden baza, baz-emetör ekleminden toprağa inen çevrede

$$V_{CC} = I_B R_B + V_{BE}$$

yazılır. Buradan

$$I_{B_Q} = \frac{V_{CC} - V_{BE}}{R_B} = \frac{12\text{ V} - 0{,}7\text{ V}}{240\text{ k}\Omega} = 47{,}08\ \mu\text{A}$$

bulunur (ekrandan, 00:05:00). Hoca "mikro" önekinin $10^{-6}$ demek olduğunu hatırlatır. Kolektör akımı

$$I_{C_Q} = \beta I_{B_Q} = (50)(47{,}08\ \mu\text{A}) = 2{,}35\text{ mA}$$

olur.

Bu sırada bir öğrenci $\beta$'nın tam olarak ne işe yaradığını sordu.

**Soru:** Buradaki $\beta$ değeri tam olarak ne işe yarıyordu? **Cevap:** $\beta$ transistöre özgü bir güçlendirme katsayısıdır. $\beta = I_C / I_B$, yani çıkış akımının giriş akımına oranıdır; baz akımının çıkışta ne kadar güçlendirildiğini gösterir.

### 2.3 Kolektör-emetör gerilimi

İkinci çevre $V_{CC}$'den $R_C$'ye, oradan kolektör-emetör uçlarına ve toprağa iner:

$$V_{CC} = I_C R_C + V_{CE}$$

$$V_{CE_Q} = V_{CC} - I_C R_C = 12\text{ V} - (2{,}35\text{ mA})(2{,}2\text{ k}\Omega) = 6{,}83\text{ V}$$

> **Ders sonrası not:** Yuvarlanmamış $I_C = 2{,}354$ mA ile hesaplanırsa $V_{CE} \approx 6{,}82$ V çıkar; slayttaki 6,83 V, $I_C$'nin 2,35 mA'e yuvarlanmasından gelir. Fark ihmal edilebilir.

### 2.4 Nokta gerilimleri ve $V_{BC}$

Hoca gösterimi hatırlatır: gerilimin altında tek bir indis varsa bu, o noktanın toprağa göre gerilimidir. Çift indis varsa iki nokta arasındaki farktır; örneğin $V_{BE} = V_B - V_E$. Burada emetör doğrudan toprağa bağlı olduğu için $V_E = 0$ ve

$$V_B = V_{BE} = 0{,}7\text{ V}, \qquad V_C = V_{CE} = 6{,}83\text{ V}$$

olur. İki nokta arasındaki gerilim için farkları alınır (ekrandan, 00:05:00):

$$V_{BC} = V_B - V_C = 0{,}7\text{ V} - 6{,}83\text{ V} = -6{,}13\text{ V}$$

Slayttaki açıklamaya göre eksi işaret baz-kolektör ekleminin ters kutuplandığını gösterir; doğrusal yükseltme için de böyle olması gerekir.

## 3. Emetör kararlı kutuplama sorusu

### 3.1 Devre

İkinci soruda öncekinden farklı olarak emetör bacağına bir direnç eklenmiştir (emitter-stabilized bias) (ekrandan, 00:15:00).

| Eleman | Bağlantı | Değer |
|---|---|---|
| $V_{CC}$ | besleme | +20 V |
| $R_B$ | $V_{CC}$ ile baz arası | 430 kΩ |
| $R_C$ | $V_{CC}$ ile kolektör arası | 2 kΩ |
| $R_E$ | emetör ile toprak arası | 1 kΩ |
| $C_E$ | $R_E$'ye paralel (köprüleme) | 40 µF |
| kuplaj kondansatörleri | giriş ve çıkış | 10 µF |
| $\beta$ | transistör | 50 |

İstenenler: (a) $I_B$, (b) $I_C$, (c) $V_{CE}$, (d) $V_C$, (e) $V_E$, (f) $V_B$, (g) $V_{BC}$.

### 3.2 Giriş çevresi ve $I_B$

Hoca iki çevre çizer: biri $V_{CC}$'den $R_B$, baz-emetör ve $R_E$ üzerinden toprağa, diğeri $V_{CC}$'den $R_C$, kolektör-emetör ve $R_E$ üzerinden toprağa iner. Birinci çevre ekrana şöyle yazılır (ekrandan, 00:15:00):

$$20\text{ V} = I_B R_B + V_{BE} + I_E R_E$$

Emetör akımı için transistör bir düğüm gibi düşünülür:

$$I_E = I_C + I_B, \qquad I_C = \beta I_B \;\Rightarrow\; I_E = (\beta + 1) I_B$$

$\beta = 50$ iken $I_C = 50 I_B$, $I_E = 51 I_B$ olur. $I_B$ mikroamper seviyesinde olduğu için bu ikisi yaklaşık eşittir, ama giriş çevresinde yine de $(\beta + 1)$ kullanılır. Yerine yazılınca

$$V_{CC} = I_B R_B + V_{BE} + (\beta + 1) I_B R_E$$

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + (\beta + 1) R_E} = \frac{20\text{ V} - 0{,}7\text{ V}}{430\text{ k}\Omega + (51)(1\text{ k}\Omega)} = \frac{19{,}3\text{ V}}{481\text{ k}\Omega} = 40{,}1\ \mu\text{A}$$

bulunur (ekrandan, 00:15:00). Sonra

$$I_C = \beta I_B = (50)(40{,}1\ \mu\text{A}) = 2{,}01\text{ mA}$$

### 3.3 Çıkış çevresi ve $V_{CE}$

İkinci çevrede

$$V_{CC} = I_C R_C + V_{CE} + I_E R_E$$

yazılır ve $I_E \approx I_C$ alınarak $I_C$ paranteze alınır:

$$V_{CE} = V_{CC} - I_C (R_C + R_E) = 20\text{ V} - (2{,}01\text{ mA})(2\text{ k}\Omega + 1\text{ k}\Omega) = 13{,}97\text{ V}$$

### 3.4 Nokta gerilimleri

$V_C$, kolektörün toprağa göre gerilimidir. Hoca bu noktaya iki yoldan inilebileceğini gösterir: aşağıdan $V_C = V_{CE} + V_E$ (yani $V_{CE} + I_E R_E$) ya da yukarıdan

$$V_C = V_{CC} - I_C R_C = 20\text{ V} - (2{,}01\text{ mA})(2\text{ k}\Omega) = 15{,}98\text{ V}$$

İki yol da aynı sonucu verir; çözümde yukarıdan inilmiştir.

$V_E$ için de üç yol vardır: $V_E = V_C - V_{CE}$, $V_E = I_E R_E$ ya da yukarıdan $V_{CC} - I_C R_C - V_{CE}$. Hepsi yaklaşık aynı değeri verir:

$$V_E = V_C - V_{CE} = 15{,}98\text{ V} - 13{,}97\text{ V} = 2{,}01\text{ V} \approx I_C R_E$$

$V_B$ için $V_{BE} = V_B - V_E$ bağıntısı kullanılır:

$$V_B = V_{BE} + V_E = 0{,}7\text{ V} + 2{,}01\text{ V} = 2{,}71\text{ V}$$

$V_{BC}$, baz ile kolektör arasındaki gerilimdir: $V_{BC} = V_B - V_C$. Derste sayısal değeri söylenmedi; bulunan değerlerle $V_{BC} = 2{,}71 - 15{,}98 = -13{,}27$ V olur (ara adım eklendi).

## 4. Gerilim bölücü kutuplama sorusu

### 4.1 Devre

Üçüncü soru gerilim bölücü (voltage-divider) devresidir; slaytta "beta-stabilized circuit" diye geçer (ekrandan, 00:25:00). İstenen $V_{CE}$ ve $I_C$'dir.

| Eleman | Bağlantı | Değer |
|---|---|---|
| $V_{CC}$ | besleme | +22 V |
| $R_1$ | $V_{CC}$ ile baz düğümü arası | 39 kΩ |
| $R_2$ | baz düğümü ile toprak arası | 3,9 kΩ |
| $R_C$ | $V_{CC}$ ile kolektör arası | 10 kΩ |
| $R_E$ | emetör ile toprak arası | 1,5 kΩ |
| $C_E$ | $R_E$'ye paralel | 50 µF |
| kuplaj kondansatörleri | giriş ve çıkış | 10 µF |
| $\beta$ | transistör | 140 |

### 4.2 Thevenin eşdeğeri

$R_1$ ile $R_2$'nin orta noktası $V_B$'dir. Hoca devreyi çözüm için sadeleştirir: baz tarafı, bir $V_{Th}$ (slaytta $E_{Th}$) gerilim kaynağı ve ona seri bir $R_{Th}$ direncinden oluşan bir kaynağın bazı beslediği bir yapıya dönüşür (ekrandan, 00:30:00). Böylece devre, $R_B$ yerine $R_{Th}$, $V_{CC}$ yerine $E_{Th}$ olan bir emetör kararlı devre gibi çözülür.

$R_{Th}$ için iki direnç sanki ikisi de toprağa gidiyormuş gibi paralel düşünülür:

$$\frac{1}{R_{\text{eş}}} = \frac{1}{R_1} + \frac{1}{R_2} \;\Rightarrow\; R_{Th} = R_1 \parallel R_2 = \frac{R_1 R_2}{R_1 + R_2} = \frac{(39\text{ k}\Omega)(3{,}9\text{ k}\Omega)}{39\text{ k}\Omega + 3{,}9\text{ k}\Omega} = 3{,}55\text{ k}\Omega$$

> **Ders sonrası not:** Anlatımda bu değer "3,55 ohm" diye söylendi; slayttaki doğru birim kΩ'dur.

$E_{Th}$, $R_2$ üzerinde düşen gerilimdir:

$$E_{Th} = \frac{R_2 V_{CC}}{R_1 + R_2} = \frac{(3{,}9\text{ k}\Omega)(22\text{ V})}{39\text{ k}\Omega + 3{,}9\text{ k}\Omega} = 2\text{ V}$$

Hoca bunu oranla da yorumlar: $R_2$ bir birimse $R_1$ on birimdir, toplam on bir birim olur. 22 V'un $1/11$'i, yani 2 V $R_2$ üzerine, kalan 20 V $R_1$ üzerine düşer. Gerilim dirençlerle orantılı paylaşılır.

### 4.3 $I_B$ ve $I_C$

Sadeleştirilmiş devrede giriş çevresi ekrana şöyle yazılır (ekrandan, 00:30:00):

$$V_{Th} = I_B R_B + V_{BE} + I_E R_E, \qquad I_E = (\beta + 1) I_B$$

Buradaki $R_B$, $R_{Th}$'dir. $I_B$ çekilince

$$I_B = \frac{E_{Th} - V_{BE}}{R_{Th} + (\beta + 1) R_E} = \frac{2\text{ V} - 0{,}7\text{ V}}{3{,}55\text{ k}\Omega + (141)(1{,}5\text{ k}\Omega)} = \frac{1{,}3\text{ V}}{3{,}55\text{ k}\Omega + 211{,}5\text{ k}\Omega} = 6{,}05\ \mu\text{A}$$

$$I_C = \beta I_B = (140)(6{,}05\ \mu\text{A}) = 0{,}85\text{ mA}$$

Burada $\beta + 1 = 141$ ile çarpılır; 140 ile çarpmak küçük bir fark yaratır. Bu yüzden bazen $I_C \approx I_E$ kabulü yapılır.

> **Hocanın vurgusu:** Bazdan geçen akım çok düşük çıkmak zorundadır. Sonucunuzu böyle test edebilirsiniz: $I_B$ miliamper çıkarsa $I_C$'nin çok daha büyük olması gerekir; bu bir hata işaretidir.

### 4.4 $V_{CE}$

Çıkış çevresi $V_{CC} = I_C R_C + V_{CE} + I_E R_E$'dir. $I_E \approx I_C$ alınıp $I_C$ paranteze alınınca

$$V_{CE} = V_{CC} - I_C (R_C + R_E) = 22\text{ V} - (0{,}85\text{ mA})(10\text{ k}\Omega + 1{,}5\text{ k}\Omega) = 12{,}22\text{ V}$$

bulunur. Hoca bu değeri anlatımda söyler; slaytın bu kısmı karelerde görünmüyor.

## 5. Gerilim bölücü formülünün ve Thevenin eşdeğerinin çıkarılışı

Bir öğrenci çözümün genel olarak anlaşıldığını ama Thevenin kısmıyla ayrıca uğraşması gerektiğini söyledi. Hoca bunun üzerine bölücü formülünü boş bir sayfada baştan çıkardı (ekrandan, 00:35:00).

Bir gerilim kaynağına ($V_C$ diye adlandırılan üst uç) seri bağlı $R_1$ ve $R_2$ dirençleri ve toprak vardır; orta nokta $V_B$'dir. $R_1$'den geçen akım $i_1$, $R_2$'den geçen akım $i_2$'dir. Baz akımı ihmal edildiğinde aynı koldan geçtikleri için

$$i_1 = i_2$$

olur. Ohm yasası $V = I R$, akım için $I = V/R$ biçimine çevrilir. $R_1$'in uçları arasında $V_C - V_B$ gerilimi vardır, $R_2$'nin uçları arasında $V_B - 0 = V_B$:

$$\frac{V_C - V_B}{R_1} = \frac{V_B}{R_2}$$

İçler-dışlar çarpımıyla

$$R_2 V_C - R_2 V_B = R_1 V_B \;\Rightarrow\; R_2 V_C = V_B (R_1 + R_2)$$

$$V_B = \frac{R_2}{R_1 + R_2}\, V_C$$

elde edilir. Yani orta noktadaki gerilim, toplam direnç içinde $R_2$'nin payı kadardır. Bu, Thevenin gerilimidir.

**Soru (hocanın öğrenciye sorusu):** Orta noktadaki gerilimi nasıl bulursun? **Cevap:** Öğrenci ilk önce iki direnci paralel düşünmeyi önerdi; hoca bunun gerilim için değil, Thevenin direnci için geçerli olduğunu söyledi ve gerilimi $i_1 = i_2$ eşitliğinden çıkardı.

Thevenin direnci için hoca şu benzetmeyi kullanır: kaynağın bağlı olduğu uç sanki kaynaktan koparılıp toprağa yapıştırılmış gibi düşünülür. Böylece iki direnç baz düğümünden toprağa paralel kalır ve fizik dersinden bilinen paralel direnç formülüyle

$$\frac{1}{R_{\text{eş}}} = \frac{1}{R_1} + \frac{1}{R_2}, \qquad R_{Th} = R_{\text{eş}}$$

bulunur.

> **Ek bilgi (derste anlatılmadı):** Thevenin direnci hesaplanırken bağımsız gerilim kaynakları kısa devre edilir. $V_{CC}$ kısa devre edilince $R_1$'in üst ucu toprağa bağlanmış olur; hocanın "ucu toprağa yapıştırma" benzetmesi bu işlemin sezgisel karşılığıdır.

## 6. Kolektör geri beslemeli kutuplama soruları

### 6.1 $R_E$'li devre

Dördüncü soruda baz direnci $V_{CC}$'ye değil kolektöre bağlıdır ve iki parçaya bölünmüştür (ekrandan, 00:40:00). İstenen $I_B$ ve $V_C$'dir.

| Eleman | Bağlantı | Değer |
|---|---|---|
| $V_{CC}$ | besleme | 18 V |
| $R_C$ | $V_{CC}$ ile kolektör arası | 3,3 kΩ |
| $R_1$ | baz ile ara düğüm arası | 91 kΩ |
| $R_2$ | ara düğüm ile kolektör arası | 110 kΩ |
| kondansatör | ara düğüm ile toprak arası | 10 µF |
| $R_E$ | emetör ile toprak arası | 510 Ω |
| $C_E$ | $R_E$'ye paralel | 50 µF |
| kuplaj kondansatörleri | giriş ve çıkış | 10 µF |
| $\beta$ | transistör | 75 |

Hoca normalde burada tek bir baz direnci olacağını, bu devrede onun ikiye bölünüp ortasından kondansatörle toprağa verildiğini söyler. Kondansatör DC'de açık devre olduğu için $R_1$ ve $R_2$ seridir; ikisi tek bir $R_B$ gibi düşünülür:

$$R_B = R_1 + R_2 = 91\text{ k}\Omega + 110\text{ k}\Omega = 201\text{ k}\Omega$$

$R_C$'den geçen akım $I_C'$ ile gösterilir. Bu akım kolektöre giden $I_C$ ile baza giden $I_B$'ye ayrılır:

$$I_C' = I_C + I_B \approx I_C$$

$I_B$, $I_C$'ye göre çok küçüktür; $\beta = I_C / I_B = 75$ olduğu için kolektör akımının 75'te biri kadardır. Bu yüzden $I_C' \approx I_C$ kabul edilir (ekrandan, 00:40:00).

Giriş çevresi $V_{CC}$'den $R_C$'ye, oradan $R_B$ üzerinden baza, baz-emetöre ve $R_E$'ye iner (ekrandan, 00:40:00):

$$18\text{ V} = I_C' R_C + I_B (R_1 + R_2) + V_{BE} + R_E I_E$$

$I_C'$ ve $I_E$ yerine $I_C$, onun yerine de $\beta I_B$ yazılınca tek bilinmeyen $I_B$ kalır:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta (R_C + R_E)} = \frac{18\text{ V} - 0{,}7\text{ V}}{201\text{ k}\Omega + (75)(3{,}3\text{ k}\Omega + 0{,}51\text{ k}\Omega)} = 35{,}5\ \mu\text{A}$$

$V_C$ için hoca iki yol gösterir. Birincisi aşağıdan $V_C = V_{CE} + V_E$; ama bu, önce $V_{CE}$ ve $V_E$'nin ayrıca bulunmasını gerektirdiği için uzundur. İkincisi yukarıdan, $R_C$ üzerindeki düşümü $V_{CC}$'den çıkarmaktır; çözümde bu yol kullanılmıştır:

$$V_C = V_{CC} - I_C' R_C \approx V_{CC} - \beta I_B R_C = 18\text{ V} - (2{,}66\text{ mA})(3{,}3\text{ k}\Omega) = 9{,}22\text{ V}$$

> **Ders sonrası not:** $I_C = \beta I_B$ yuvarlanmadan ($2{,}666$ mA) hesaplanırsa $V_C \approx 9{,}20$ V çıkar. 9,22 V'luk sonuç, $I_C$'nin 2,66 mA'e yuvarlanmasından gelir (büyük olasılıkla kaynak kitabın ara değeri budur).

### 6.2 $R_E$'siz devre

Hoca bu soruyu "öncekinin aynısı" diye tanıtır; fark, emetör direncinin olmaması ve baz direncinin tek parça olmasıdır (ekrandan, 00:45:00). Slaytta istenenler $I_{C_Q}$, $V_{CE_Q}$ ve $V_B$, $V_C$, $V_E$, $V_{BC}$'dir.

| Eleman | Bağlantı | Değer |
|---|---|---|
| $V_{CC}$ | besleme | 20 V |
| $R_C$ | $V_{CC}$ ile kolektör arası | 4,7 kΩ |
| $R_B$ (geri besleme) | kolektör ile baz arası | 680 kΩ |
| $C_2$ | kolektör ile çıkış arası | 10 µF |
| $\beta$ | transistör | 120 |
| emetör | doğrudan toprakta | $R_E = 0$ |

Ekrana yazılan giriş çevresi $V_{CC} = I_C' R_C + I_B R_B + V_{BE}$'dir; burada $V_{BE} = 0{,}7$ V'tur. Hoca $V_{BE}$'nin hiçbir zaman unutulmaması gerektiğini, $I_C$ yerine de $\beta I_B$ yazmanın unutulmamasını vurgular. Slayttaki açıklamaya göre $R_E$ olmadığı için paydaya yalnız $R_C$ yansır:

$$I_B = \frac{V_{CC} - V_{BE}}{R_B + \beta R_C} = \frac{20\text{ V} - 0{,}7\text{ V}}{680\text{ k}\Omega + (120)(4{,}7\text{ k}\Omega)} = \frac{19{,}3\text{ V}}{1{,}244\text{ M}\Omega} = 15{,}51\ \mu\text{A}$$

$$I_{C_Q} = \beta I_B = (120)(15{,}51\ \mu\text{A}) = 1{,}86\text{ mA}$$

Çıkış çevresi $V_{CC} = I_C' R_C + V_{CE}$'dir; $I_C' \approx I_C$ alınarak

$$V_{CE_Q} = V_{CC} - I_C R_C = 20\text{ V} - (1{,}86\text{ mA})(4{,}7\text{ k}\Omega) = 11{,}26\text{ V}$$

bulunur (ekrandan, 00:45:00). Emetör doğrudan toprakta olduğu için $V_E = 0$, $V_B = V_{BE} = 0{,}7$ V ve $V_C = V_{CE}$'dir. $V_{BC}$ istenirse $V_B - V_C$ farkı alınır.

## 7. Tersten tasarım sorusu: direnç değerlerinin bulunması

### 7.1 Devre ve verilenler

Son çözülen soru yine bir gerilim bölücü devredir, ama bu kez akım ve gerilim verilmiş, iki direnç istenmiştir (ekrandan, 00:50:00).

| Eleman | Bağlantı | Değer |
|---|---|---|
| $V_{CC}$ | besleme | 18 V |
| $R_1$ | $V_{CC}$ ile baz düğümü arası | bilinmiyor |
| $R_2$ | baz düğümü ile toprak arası | 18 kΩ |
| $R_C$ | $V_{CC}$ ile kolektör arası | bilinmiyor |
| $R_E$ | emetör ile toprak arası | 1,2 kΩ |
| kuplaj kondansatörleri | giriş ve çıkış | 10 µF |
| verilen | çalışma noktası | $I_{C_Q} = 2$ mA, $V_{CE_Q} = 10$ V |

### 7.2 $R_1$'in bulunması

Hoca önce çıkış çevresini yazar: $18\text{ V} = R_C I_C + V_{CE} + I_E R_E$. Burada $R_C$ bilinmediği için bu denklem $R_1$'i vermez. $R_1$ için baz gerilimine gidilir. $V_{BE} = V_B - V_E = 0{,}7$ V bilinir; $V_E$ de emetör direnci üzerindeki düşümdür:

$$V_E = I_E R_E \approx I_C R_E = (2\text{ mA})(1{,}2\text{ k}\Omega) = 2{,}4\text{ V}$$

$$V_B = V_{BE} + V_E = 0{,}7\text{ V} + 2{,}4\text{ V} = 3{,}1\text{ V}$$

Orta noktadaki gerilim bilindiği için bölücü formülünde tek bilinmeyen $R_1$ kalır:

$$V_B = \frac{R_2 V_{CC}}{R_1 + R_2} \;\Rightarrow\; 3{,}1\text{ V} = \frac{(18\text{ k}\Omega)(18\text{ V})}{R_1 + 18\text{ k}\Omega}$$

$$324\text{ k}\Omega = 3{,}1 R_1 + 55{,}8\text{ k}\Omega \;\Rightarrow\; 3{,}1 R_1 = 268{,}2\text{ k}\Omega \;\Rightarrow\; R_1 = 86{,}52\text{ k}\Omega$$

(ekrandan, 00:50:00)

### 7.3 $R_C$'nin bulunması

Birinci yol çıkış çevresidir. $I_E \approx I_C$ alınıp $I_C$ paranteze alınır:

$$18\text{ V} = I_C (R_C + R_E) + V_{CE} \;\Rightarrow\; 18 - 10 = 8\text{ V} = (2\text{ mA})(R_C + 1{,}2\text{ k}\Omega)$$

$$R_C + 1{,}2\text{ k}\Omega = 4\text{ k}\Omega \;\Rightarrow\; R_C = 2{,}8\text{ k}\Omega$$

İkinci yol $R_C$ üzerindeki gerilimden gider. $V_{R_C} = V_{CC} - V_C$ ve bu dirençten $I_C$ geçer. $V_C$ aşağıdan bulunur:

$$V_C = V_{CE} + V_E = 10\text{ V} + 2{,}4\text{ V} = 12{,}4\text{ V}$$

$$R_C = \frac{V_{CC} - V_C}{I_C} = \frac{18\text{ V} - 12{,}4\text{ V}}{2\text{ mA}} = 2{,}8\text{ k}\Omega$$

İki yol aynı sonucu verir.

> **Hocanın vurgusu:** Birimleri yazmayı unutmayın; birimler önemlidir. Bulunan değer 2,8 değil, 2,8 kΩ'dur.

## Örnek Sorular

### Soru 1 (ekrandan, 00:05:00)

Şekildeki sabit kutuplama devresi için ($V_{CC} = +12$ V, $R_B = 240$ kΩ, $R_C = 2{,}2$ kΩ, $\beta = 50$, kuplaj kondansatörleri 10 µF, emetör toprakta) şunları bulun: (a) $I_{B_Q}$ ve $I_{C_Q}$, (b) $V_{CE_Q}$, (c) $V_B$ ve $V_C$, (d) $V_{BC}$.

> **Çözüm (derste verildi):** $I_{B_Q} = (12 - 0{,}7)/240\text{ k}\Omega = 47{,}08\ \mu$A, $I_{C_Q} = 50 \cdot 47{,}08\ \mu\text{A} = 2{,}35$ mA, $V_{CE_Q} = 12 - 2{,}35 \cdot 2{,}2 = 6{,}83$ V, $V_B = 0{,}7$ V, $V_C = 6{,}83$ V, $V_{BC} = -6{,}13$ V.

### Soru 2 (ekrandan, 00:15:00)

Emetör kararlı devre ($V_{CC} = +20$ V, $R_B = 430$ kΩ, $R_C = 2$ kΩ, $R_E = 1$ kΩ ve ona paralel 40 µF, $\beta = 50$) için (a) $I_B$, (b) $I_C$, (c) $V_{CE}$, (d) $V_C$, (e) $V_E$, (f) $V_B$, (g) $V_{BC}$ değerlerini bulun.

> **Çözüm (derste verildi, (g) hariç):** $I_B = 19{,}3\text{ V}/481\text{ k}\Omega = 40{,}1\ \mu$A, $I_C = 2{,}01$ mA, $V_{CE} = 13{,}97$ V, $V_C = 15{,}98$ V, $V_E = 2{,}01$ V, $V_B = 2{,}71$ V. (g) derste sayısal verilmedi: $V_{BC} = V_B - V_C = 2{,}71 - 15{,}98 = -13{,}27$ V (python ile kontrol edildi).

### Soru 3 (ekrandan, 00:25:00)

Gerilim bölücü devre ($V_{CC} = +22$ V, $R_1 = 39$ kΩ, $R_2 = 3{,}9$ kΩ, $R_C = 10$ kΩ, $R_E = 1{,}5$ kΩ ve ona paralel 50 µF, $\beta = 140$) için DC $V_{CE}$ gerilimini ve $I_C$ akımını bulun.

> **Çözüm (derste verildi):** $R_{Th} = 3{,}55$ kΩ, $E_{Th} = 2$ V, $I_B = 1{,}3\text{ V}/(3{,}55 + 211{,}5)\text{ k}\Omega = 6{,}05\ \mu$A, $I_C = 0{,}85$ mA, $V_{CE} = 22 - 0{,}85 \cdot 11{,}5 = 12{,}22$ V.

### Soru 4 (ekrandan, 00:40:00)

Kolektör geri beslemeli devre için ($V_{CC} = 18$ V, $R_C = 3{,}3$ kΩ, kolektörden baza seri $R_2 = 110$ kΩ ve $R_1 = 91$ kΩ, ara düğümden toprağa 10 µF, $R_E = 510$ Ω ve ona paralel 50 µF, $\beta = 75$) DC $I_B$ ve $V_C$ değerlerini bulun.

> **Çözüm (derste verildi):** $I_B = 17{,}3\text{ V}/[201\text{ k}\Omega + 75(3{,}81\text{ k}\Omega)] = 35{,}5\ \mu$A, $V_C = 18 - (2{,}66\text{ mA})(3{,}3\text{ k}\Omega) = 9{,}22$ V.

### Soru 5 (ekrandan, 00:45:00)

$R_E = 0$ olan kolektör geri beslemeli devre için ($V_{CC} = 20$ V, $R_C = 4{,}7$ kΩ, $R_B = 680$ kΩ, $\beta = 120$) (a) $I_{C_Q}$ ve $V_{CE_Q}$, (b) $V_B$, $V_C$, $V_E$ ve $V_{BC}$ değerlerini bulun.

> **Çözüm (derste (a) ve $V_B$ verildi):** $I_B = 19{,}3\text{ V}/1{,}244\text{ M}\Omega = 15{,}51\ \mu$A, $I_{C_Q} = 1{,}86$ mA, $V_{CE_Q} = 11{,}26$ V, $V_B = 0{,}7$ V. Derste sayısal verilmeyenler: $V_E = 0$ V, $V_C = V_{CE} = 11{,}26$ V, $V_{BC} = 0{,}7 - 11{,}26 = -10{,}56$ V (python ile kontrol edildi).

### Soru 6 (ekrandan, 00:50:00)

$I_{C_Q} = 2$ mA ve $V_{CE_Q} = 10$ V verildiğine göre, $V_{CC} = 18$ V, $R_2 = 18$ kΩ, $R_E = 1{,}2$ kΩ olan gerilim bölücü devrede $R_1$ ve $R_C$ değerlerini bulun.

> **Çözüm (derste verildi):** $V_E = 2{,}4$ V, $V_B = 3{,}1$ V, $R_1 = 268{,}2/3{,}1 = 86{,}52$ kΩ; $R_C = (18 - 10)/2\text{ mA} - 1{,}2\text{ k}\Omega = 2{,}8$ kΩ.

### Soru 7 (ekrandan, 00:55:00)

Yandaki transistörlü devrede (sabit kutuplama: $V_{CC}$'den $R_B$ ile baza, $R_C$ ile kolektöre; emetör toprakta; giriş $C_1$, çıkış $C_2$ üzerinden) $R_B = 470$ kΩ, $R_C = 3$ kΩ, $\beta = 100$ ve $r_o = 50$ kΩ olarak verildiğine göre: (a) $I_B$, $I_E$ ve $r_e$ değerlerini bulunuz. (b) Giriş direncini ($Z_i$) bulunuz. (c) Çıkış direncini ($Z_o$) bulunuz. (d) Devrenin kazancını ($A_v$) bulunuz.

Bu soru ekranda gösterildi, ama hoca şimdilik gerekmediğini söyleyerek çözmedi; küçük sinyal analizine ait bir sorudur.

<!-- BELİRSİZ: slaytta V_CC değeri görünmüyor; bu yüzden I_B, I_E ve r_e sayısal olarak hesaplanamadı ve çözüm yazılmadı -->

## Dersin Toparlaması

Bu derste BJT'nin DC kutuplama devreleri soru çözerek pekiştirildi: sabit kutuplama, emetör kararlı kutuplama, gerilim bölücü kutuplama ve iki tür kolektör geri beslemeli kutuplama. Her devrede aynı adımlar izlendi: giriş (baz-emetör) çevresinden $I_B$, $\beta$ ile $I_C$ ve $I_E$, çıkış (kolektör-emetör) çevresinden $V_{CE}$, sonra tek indisli nokta gerilimleri ve çift indisli farklar. Gerilim bölücü devre, Thevenin eşdeğeri ($R_{Th} = R_1 \parallel R_2$, $E_{Th} = R_2 V_{CC}/(R_1 + R_2)$) ile emetör kararlı devreye indirildi; bölücü formülü $i_1 = i_2$ eşitliğinden baştan çıkarıldı. Son soruda işlem tersine çevrildi: verilen çalışma noktasından direnç değerleri bulundu.

Hocanın sık tekrarladığı noktalar, $V_{BE}$'yi çevre denkleminde unutmamak, baz akımının mikroamper mertebesinde çıkmasını bir kontrol olarak kullanmak, bir nokta gerilimine kısa olan yoldan ulaşmak ve birimleri yazmaktır. Ekranda son olarak gösterilen soru, transistörün küçük sinyal parametrelerine ($r_e$, $Z_i$, $Z_o$, $A_v$) geçişe işaret eder; bu kısım bu derste çözülmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
