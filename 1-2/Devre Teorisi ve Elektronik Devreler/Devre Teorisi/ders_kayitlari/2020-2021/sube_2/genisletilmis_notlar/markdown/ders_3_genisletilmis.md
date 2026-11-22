# Ders 3 Genişletilmiş Notu: KCL, KVL, Seri/Paralel Devreler, Gerilim ve Akım Bölücü

> Kayıt üç parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Ohm Yasası, Güç ve İşaret Kuralı
- 2. Tek Çevreli Devre ve KVL
- 3. Enerjinin Korunumu: Güçlerin Toplamı Sıfırdır
- 4. Bağımlı Kaynaklı Çevrelerde Güç Hesabı
- 5. Tek Düğüm Çiftli Devreler ve KCL
- 6. Seri ve Paralel Bağlantıyı Tanımak
- 7. Gerilim ve Akım Kaynaklarının Seri/Paralel Bağlanması
- 8. Dirençlerin Seri/Paralel Bağlanması ve İletkenlik
- 9. Gerilim Bölücü
- 10. Akım Bölücü
- 11. Laboratuvar Tanıtım Oturumu: Simülasyonla Ölçüm
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: Ohm Yasası, Güç ve İşaret Kuralı

Ders, bir önceki haftada işlenen iki yasanın, KCL (Kirchhoff Akım Yasası) ve KVL'nin (Kirchhoff Gerilim Yasası), hatırlatılmasıyla başladı. Bu yasalar Ohm yasası $V = IR$ üzerinde gösterilmişti. Sunumun kapağında (ekrandan, 00:06:29) hoca şu formülleri ve küçük bir devreyi el yazısıyla not etti: $V = I\cdot R$, $P = I\cdot V = I^2 R = V^2/R$. Devrede bir kaynak ve iki direnç vardır; kaynak üzerinde $-P_1$, dirençler üzerinde $+P_2$ ve $+P_3$ yazılıdır.

Akım yönü konusu da tekrar edildi. Gerilim kaynağında elektronlar eksiden artıya gider. Akım (geleneksel yön) ise bunun tersine, artı uçtan çıkıp devreyi dolaşarak eksi uca döner. Direnç üzerinde akımın girdiği uç artı (+), çıktığı uç eksi (−) olarak işaretlenir. Hocanın ezber için verdiği kural şudur:

- Akım bir elemana **artı** işaretli uçtan giriyorsa eleman güç **soğurur** (tüketir). Güç $+P$ yazılır.
- Akım elemana **eksi** işaretli uçtan giriyorsa eleman güç **üretir** (besler). Güç $-P$ yazılır.

Bir çevrimdeki bütün elemanların güçleri ($P_1, P_2, P_3, \dots$) toplandığında enerjinin korunumu gereği sonuç sıfırdır. Başka bir deyişle, üreteçten verilen güç dirençlere, direnç ve akım değerlerine göre dağılır ve bu payların toplamı üretilen güce eşittir.

> **Ek bilgi (derste anlatılmadı):** Bu kurala "pasif işaret kuralı" (passive sign convention) denir. Gerilimin + ucundan giren akımla hesaplanan $p = vi$, elemanın soğurduğu güçtür. Bu değer eksi çıkarsa eleman aslında güç vermektedir.

## 2. Tek Çevreli Devre ve KVL

KVL'nin kuralı şudur: bir kapalı yol (loop) üzerindeki gerilimlerin işaretli toplamı sıfırdır. Terimler, akım için seçilen yöne ve elemanların polaritesine göre artı ya da eksi yazılır. Hoca denklemi sıfıra eşitleyerek yazmanın en kolay yol olduğunu söyledi.

Slayttaki tek çevreli devrede (ekrandan, 00:11:29) $v_{s1}$ kaynağı, $R_1$, $v_{s2}$ kaynağı ve $R_2$ seri bağlıdır. Analiz üç adımdır:

- Bilinmeyen akım için bir referans yön seçilir.
- Her direnç için bir gerilim referansı (polarite) seçilir.
- Tek kapalı yola KVL uygulanır.

Akım saat yönünde alınınca $v_{s1}$ kaynağına eksi uçtan girilir, bu yüzden terimi $-v_{s1}$ olur. Diğer elemanlara artı uçtan girilir:

$$-v_{s1} + v_{R1} + v_{s2} + v_{R2} = 0, \qquad v_{R1} = R_1 i,\quad v_{R2} = R_2 i$$

$$-v_{s1} + R_1 i + v_{s2} + R_2 i = 0 \;\Rightarrow\; i = \frac{v_{s1} - v_{s2}}{R_1 + R_2}$$

Hoca bunu şöyle yorumladı: iki gerilim kaynağı birbirine zıt bağlı olduğu için gerilimleri birbirinden çıkarılır, sonuç toplam dirence bölünür. $R_1$ ve $R_2$ terimleri ortak $i$ parantezine alınınca $R_1 + R_2$ ortaya çıkar. Bu formül enerjinin korunumuna dayanan KVL'nin doğrudan sonucudur.

## 3. Enerjinin Korunumu: Güçlerin Toplamı Sıfırdır

Slaytta iki ifade vardır (ekrandan, 00:16:29):

$$\sum_{\text{bütün elemanlar}} p_{\text{soğurulan}} = 0, \qquad \sum p_{\text{soğurulan}} = \sum p_{\text{üretilen}}$$

Örnek devrede elemanlar yan yana dizilmiştir. Hoca her elemanın akımı + uçtan mı yoksa − uçtan mı aldığına bakarak güçleri tek tek değerlendirdi:

- **7 A, 8 V elemanı:** Akım artı uçtan çıkıyor, yani akım gerilime ters yönde. Eleman üretir: $P = -(7)(8) = -56$ W. Hoca burada şunu da belirtti: aynı kaynakta akım "−7 A" yazılsaydı işaret de değişirdi. Bu yüzden önemli olan, akımın hangi uçtan çıktığıdır.
- **2 A, 8 V elemanı:** Akım artı uçtan giriyor. Eleman tüketir: $16$ W. Elemanın direnç ya da başka bir şey olması önemli değildir.
- **5 A, 12 V elemanı:** Bu kolun akımı verilmeseydi bile KCL ile bulunabilirdi: düğüme 7 A girer, 2 A aşağı gider, demek ki yatay koldan 5 A devam eder. Akım bu elemana eksi uçtan girdiği için eleman üretir: $-60$ W.
- **8 A, 20 V elemanı:** 5 A ve 3 A birleşerek aşağıya 8 A iner (KCL). Polarite akımla uyumludur, eleman tüketir: $160$ W.
- **3 A, 20 V elemanı ($0{,}25v_x$ bağımlı kaynak):** Akım polaritenin tersinden tanımlanmıştır. Eleman üretir: $-60$ W.

Toplam: $-56 + 16 - 60 + 160 - 60 = 0$. Yani 176 W üretilir, 176 W tüketilir (python ile doğrulandı).

> **Hocanın vurgusu:** Bütün güçleri bulduktan sonra toplamlarının sıfır olduğunu mutlaka kontrol edin. Sıfır çıkmıyorsa bir işarette ya da akım yönünde hata yapmışsınızdır.

> **Ders sonrası not:** Hoca 12 V elemanının gücü için "eksi 60 voltluk bir güç" dedi. Gücün birimi watt'tır, doğrusu $-60$ W.

## 4. Bağımlı Kaynaklı Çevrelerde Güç Hesabı

### 4.1 Bağımlı kaynak türleri

Hoca eşkenar dörtgen içindeki kaynağın ne olduğunu sordu. Bağımlı kaynakların iki türü hatırlatıldı: akım kontrollü ve gerilim kontrollü. Örnek 1'deki kaynağın değeri bir gerilime ($v_A$) bağlıdır ve içinde + − işareti vardır. Bu yüzden **gerilim kontrollü bağımlı gerilim kaynağıdır**. İçinde ok olsaydı, gerilim kontrollü bağımlı akım kaynağı olurdu.

### 4.2 Örnek 1: Her elemanın soğurduğu güç

Devre (ekrandan, 00:21:29 ve 00:26:29): 120 V kaynak, 30 Ω direnç (üzerinde $v_{30}$, + sol), $2v_A$ bağımlı gerilim kaynağı (+ sol, − sağ) ve 15 Ω direnç seri bağlıdır. 15 Ω üzerindeki $v_A$'nın **+ ucu altta, − ucu üstte** tanımlanmıştır. Akım $i$ kaynağın + ucundan çıkıp saat yönünde dolaşacak şekilde seçildi.

Bu soruyu derste bir öğrenci tahtada çözmeye çalıştı; Zoom'un çizim (annotate) aracı açılamadığı için hoca çözüme devam etti.

**KVL denklemi.** 120 V kaynağın gücü kesinlikle eksi olacaktır, çünkü akım bu kaynağın artı ucundan çıkıyor. 30 Ω ve bağımlı kaynak polariteleri akımla uyumlu olduğu için artı yazılır. 15 Ω'da ise saat yönünde giderken önce $v_A$'nın − ucuyla karşılaşılır, bu yüzden terim $-v_A$ olur:

$$-120 + v_{30} + 2v_A - v_A = 0$$

**Tek değişkene indirgeme.** İki farklı değişken yerine her şeyi $i$ cinsinden yazmak gerekir. $v_{30} = 30i$ olur. $v_A$ ise akımın 15 Ω'a girdiği uca göre ters tanımlanmıştır. Akım dirence üstten girer, oysa $v_A$'nın + ucu alttadır. Bu yüzden $v_A = -15i$ yazılır:

$$-120 + 30i - 30i + 15i = 0 \;\Rightarrow\; i = 8\ \text{A}$$

Sonuç pozitif çıktığı için seçilen akım yönü doğrudur. Hoca $i = -8$ A çıksaydı ne olacağını da söyledi: gerçek akım ters yönde, aşağıdan yukarı doğru 8 A olurdu.

**Güçler.** Kontrol gerilimi $v_A = -15 \cdot 8 = -120$ V'tur.

- $p_{120V} = (120)(-8) = -960$ W (üretir).
- $p_{30\Omega} = 8^2 \cdot 30 = 1920$ W (tüketir). Bu değer $V\cdot I$ ile de bulunabilir.
- $p_{dep} = (2v_A)(8) = 2(-120)(8) = -1920$ W.
- $p_{15\Omega} = 8^2 \cdot 15 = 960$ W.

Toplam $-960 + 1920 - 1920 + 960 = 0$'dır (python ile doğrulandı).

> **Ders sonrası not:** Hoca 30 Ω gücünü hesaplarken "8 kere 7, 64" dedi. Doğrusu $8 \times 8 = 64$'tür; sonuç olan 1920 W doğrudur.

**Bağımlı kaynağın asıl rolü.** İlk bakışta bağımlı kaynak tüketen konumda görünür, çünkü akım + ucundan girer. Ancak değeri $v_A$'ya bağlıdır. $v_A$ eksi çıktığında kaynağın gerilimi de eksi olur ve aslında güç üretir. Hoca bu yüzden bu kaynaklara "bağımlı" dendiğini söyledi: üreten mi tüketen mi olduğu, kontrol değişkeni bulunduktan sonra anlaşılır.

> **Hocanın vurgusu:** Bağımlı kaynakların üstündeki artı-eksi işaretleri yalnız denklemi kurmak için ilk fikri verir. Kaynağın gerçekte üreten mi tüketen mi olduğu kontrol gerilimi (burada $v_A$) bulunduktan sonra belli olur. Bu ince noktalara dikkat edin.

**Soru:** Bağımlı gerilim kaynağını başta yalnız tüketiciymiş gibi mi alıyoruz?
**Cevap:** Hayır. Kaynak üretici de olabilir. Denklemi yazarken her eleman soruda verilen polariteye göre denkleme girer; burada 30 Ω de bağımlı kaynak da artı yazıldı. Gerçekte ise 30 Ω tüketir, bağımlı kaynak üretir. Bu fark $v_A$'nın değerinden gelir: $v_A$ eksi ise kaynak tüketici konumdan üretici konuma geçer.

### 4.3 Örnek 2: Beş elemanın soğurduğu güç

Devre (ekrandan, 00:36:29): 30 Ω (üzerinde $v_x$, + üstte), üstte 12 V kaynak (sol ucu −, sağ ucu +), 8 Ω, 7 Ω ve $4v_x$ bağımlı gerilim kaynağı (+ üstte) tek çevre oluşturur. Akım $i$, 30 Ω içinde yukarı doğru, yani saat yönünde alınmıştır. Hoca öğrencilerin soruyu birkaç dakika çözmesini istedi ve sonra çözümleri birlikte tartıştı.

**Soru:** Direncin işaretleri verilmediğinde nasıl düşüneceğiz?
**Cevap:** Akımın yönüne göre polarite verilir. Direnç doğası gereği güç üretemez. Ancak burada $v_x$ soruda verilmiştir ve seçilen akıma göre direnç üretici gibi görünür; işlemler bu $v_x$ tanımına göre yapılır.

Bir öğrenci denklemi $105i = 12$ olarak kurdu. Hoca $4v_x$ teriminin işaretinde hata olduğunu söyledi: $v_x = -30i$ olduğundan $4v_x = -120i$ olmalıdır. İkinci bir öğrenci doğru çözümü yaptı (ekrandan, 00:46:29 ve 00:56:29):

**KVL.** Sol alttan başlayıp saat yönünde gidilir. 30 Ω'a − ucundan girildiği için terim $-v_x$, 12 V kaynağa − ucundan girildiği için $-12$, iki seri direnç için $8i + 7i = 15i$, bağımlı kaynağa + ucundan girildiği için $+4v_x$ yazılır:

$$-v_x - 12 + 15i + 4v_x = 0 \;\Rightarrow\; 15i - 12 + 3v_x = 0$$

**Kontrol değişkeni.** Akım 30 Ω'a alttan, yani − ucundan girer. Bu yüzden $v_x = -30i$ olur:

$$15i - 12 + 3(-30i) = 0 \;\Rightarrow\; -75i = 12 \;\Rightarrow\; i = -\frac{4}{25}\ \text{A}$$

$$v_x = -30 \cdot \left(-\frac{4}{25}\right) = \frac{24}{5} = 4{,}8\ \text{V}$$

Akım eksi çıktı. Gerçekte akım tanımlanan yönün tersine, saat yönünün tersine akmaktadır.

**Gücün işareti.** Hoca, öğrencinin "formül belli, $P = IV$" cevabının yeterli olmadığını söyledi; asıl iş, işaretlerin değişip değişmediğini görmektir. Bağımlı kaynak için $P = (4v_x)\, i = 4 \cdot \frac{24}{5} \cdot \left(-\frac{4}{25}\right)$ eksi çıkar. Yani bağımlı kaynak tüketen değil, üretendir.

30 Ω için iki yol gösterildi: $P = i^2 R = (-4/25)^2 \cdot 30$ ya da $P = V^2/R = \frac{1}{30}\left(\frac{24}{5}\right)^2$. İki yolda da sonuç pozitiftir; direnç güç tüketir.

**Soru:** Başta $-v_x$ yazdık, sonra $v_x$ yerine yine eksili $-30i$ koyduk. İki kere eksi demiş olmuyor muyuz?
**Cevap:** Hayır. İki eksi farklı şeyleri anlatır. KVL'deki $-v_x$, elemanın polaritesine göre yazılan işarettir. $v_x = -30i$'deki eksi ise $v_x$'in değerinin işaretidir: $v_x$'i oluşturan akım dirence + ucundan değil − ucundan girdiği için bu değer eksidir. Hoca bunu ekranda dört gösterimle anlattı (ekrandan, 00:56:29): "+ −, 5 V", "− +, −5 V", "+ −, −5 V" ve "− +, 5 V". Gösterimleri farklı olsa da ikişer ikişer aynı anlama gelirler.

> **Hocanın vurgusu:** KVL'de gerilim terimlerinin işaretini elemanın polaritesine göre yazın. Terimin içindeki değeri ise o gerilimi oluşturan akımın yönüne göre yazın. Ezberlemeyin, mantığını oturtun.

**Soru:** Güç $I^2R$ ise her zaman pozitif çıkmaz mı?
**Cevap:** Dirençler için evet. Direnç negatif olamaz ve her zaman güç soğurur. Ancak gerilim kaynağının direnci (rezistif değeri) yoktur; kaynağın gücü $I^2R$ ile hesaplanamaz, yalnız $P = IV$ ile hesaplanır. Gerilim kaynağı devreye göre ya üretir ya tüketir.

**12 V kaynağının gücü.** Akım $-4/25$ A bulundu. İki eşdeğer yol vardır. Birincisi, yönü koruyup akımı eksi değerle kullanmaktır: akım kaynağa eksi uçtan girdiği için bir eksi daha gelir ve $P = -12 \cdot (-4/25)$ olur. İkincisi, akım yönünü ters çevirip $4/25$ A pozitif almaktır: akım bu kez kaynağın artı ucundan girer, $P = 12 \cdot 4/25$ olur. İki yol da aynı sonucu verir: 12 V kaynağı güç **tüketir**.

Hoca şöyle özetledi: akımın yönünü değiştirmek ile değerini eksi almak aynı şeydir; değişen yalnız hesaptaki karmaşıklıktır. Akım yönü değişince dirençlerin polaritesi de değişir. $v_x$ eksi çıksaydı, bağımlı kaynakta da benzer biçimde ya eksi değerle çalışılır ya da polarite ters çevrilip pozitif değer kullanılırdı.

**Bütün güçler (python ile doğrulandı).** Sayısal değerler derste tek tek hesaplanmadı; burada eklendi.

| Eleman | Soğurulan güç |
|---|---|
| 30 Ω | $0{,}768$ W |
| 12 V kaynak | $1{,}92$ W (tüketir) |
| 8 Ω | $0{,}2048$ W |
| 7 Ω | $0{,}1792$ W |
| $4v_x$ bağımlı kaynak | $-3{,}072$ W (üretir) |

Toplam sıfırdır.

> **Hocanın vurgusu:** Soruları evde tekrar çözün. Zor değil, ama çok soru çözdükçe bu ayrıntıları görmek kolaylaşır.

## 5. Tek Düğüm Çiftli Devreler ve KCL

### 5.1 KCL ve paralel kollar

KCL'nin kuralı, bir düğüme giren akımların çıkan akımlara eşit olmasıdır; başka bir deyişle akımların işaretli toplamı sıfırdır. Paralel bağlı kolların (branş) hepsinde aynı gerilim bulunur. Bu yüzden farklı kol akımları tek bir ortak $v$ cinsinden yazılabilir ve birden fazla bilinmeyen yerine tek bilinmeyen kalır.

Hoca düğümü şöyle tanımladı: iki devre elemanının birleştiği noktadır. Aralarında başka eleman olmayan, iletkenle birleşen noktalar aynı düğümdür. Bu noktalar kocaman tek bir yuvarlak gibi düşünülebilir.

### 5.2 Örnek 3: Gerilim, akım ve güçler

Devre (ekrandan, 01:06:29): 120 A akım kaynağı (yukarı), $R_1 = 1/30$ Ω, 30 A akım kaynağı (aşağı) ve $R_2 = 1/15$ Ω paralel bağlıdır. Ortak gerilim $v$'dir.

$$-120 + i_1 + 30 + i_2 = 0, \qquad i_1 = \frac{v}{1/30} = 30v,\quad i_2 = 15v$$

$$45v = 90 \;\Rightarrow\; v = 2\ \text{V}, \quad i_1 = 60\ \text{A}, \quad i_2 = 30\ \text{A}$$

$R_1$'in gücü $I^2R$ ya da $IV$ ile bulunur: $P_{R1} = 60 \cdot 2 = 120$ W. Diğer güçler derste söylenmedi ve python ile hesaplandı: $P_{R2} = 60$ W, 120 A kaynağı $-240$ W (üretir), 30 A kaynağı $+60$ W (soğurur). Toplam sıfırdır.

### 5.3 Örnek 4: Bağımlı akım kaynaklı paralel devre

Devre (ekrandan, 01:11:29): 6 kΩ (akımı $i_6$, aşağı), $2i_x$ bağımlı akım kaynağı (yukarı), 24 mA akım kaynağı (yukarı) ve 2 kΩ paralel bağlıdır. $i_x$ üst iletkende sağdan sola, yani 2 kΩ'dan üst düğüme doğru tanımlanmıştır. Üst düğüm + , alt düğüm − olmak üzere ortak gerilim $v$'dir. İstenenler $v$ ve bağımsız akım kaynağının soğurduğu güçtür.

Ara öncesinde öğrencilerden bu soruyu çözmeleri istendi. Aradan sonra hoca çözümü anlattı.

**KCL.** Üst düğümde çıkan akımlara artı, girenlere eksi verildi (ekrandan, 01:31:29):

$$i_6 - 2i_x - 24\ \text{mA} - i_x = 0 \;\Rightarrow\; i_6 - 3i_x - 24\ \text{mA} = 0$$

Bu denklemde iki bilinmeyen vardır ($i_6$ ve $i_x$). İkisi de ortak $v$ cinsinden yazılır:

- 6 kΩ'da akım + uçtan girip − uçtan çıktığı için $i_6 = v/6000$ olur.
- 2 kΩ'da $v/2000$ yazılamaz, çünkü bu, akımı yukarıdan aşağı kabul etmek demektir. $i_x$ ise 2 kΩ içinde aşağıdan yukarı tanımlanmıştır. Bu yüzden $i_x = -v/2000$ yazılır.

$$\frac{v}{6000} - 2\left(\frac{-v}{2000}\right) - 0{,}024 - \left(\frac{-v}{2000}\right) = 0 \;\Rightarrow\; v = 14{,}4\ \text{V}$$

**Güç.** 24 mA kaynağında akım + uçtan çıkar, yani kaynak üreteç konumundadır:

$$P_{24\,\text{mA}} = -(14{,}4)(0{,}024) \approx -0{,}3456\ \text{W} \approx -345\ \text{mW}$$

Bağımsız akım kaynağı güç üretir (python ile doğrulandı).

### 5.4 Örnek 5: $i_A$, $i_B$, $i_C$

Devre (ekrandan, 01:36:29): 5,6 A kaynak (yukarı), 18 Ω ($i_A$ aşağı), $0{,}1v_x$ bağımlı akım kaynağı (yukarı; $i_B$ aşağı tanımlı), 9 Ω ($i_C$ aşağı) ve 2 A kaynak (aşağı) paralel bağlıdır. $v_x$, üst düğüm + olmak üzere ortak gerilimdir.

Hoca ipucu verdi: $i_B$ aşağı doğru tanımlanmış ama bağımlı kaynağın oku yukarı bakıyor. Bu yüzden $i_B = -0{,}1v_x$ yazılır.

Bir öğrencinin çözümü şöyle oldu. Üst düğümde 5,6 A girer; $i_A$, $i_B$, $i_C$ ve 2 A çıkar:

$$5{,}6 - i_A - i_B - i_C - 2 = 0$$

$$i_A = \frac{v_x}{18}, \quad i_B = -0{,}1v_x, \quad i_C = \frac{v_x}{9}$$

$$5{,}6 - \frac{v_x}{18} + 0{,}1v_x - \frac{v_x}{9} - 2 = 0 \;\Rightarrow\; v_x = 54\ \text{V}$$

$$i_A = 3\ \text{A}, \quad i_B = -5{,}4\ \text{A}, \quad i_C = \frac{54}{9} = 6\ \text{A}$$

Kontrol: $i_A + i_B + i_C + 2 = 3 - 5{,}4 + 6 + 2 = 5{,}6$ A, giren akıma eşittir (python ile doğrulandı). Öğrenci $i_C$'yi önce 2 A yazmıştı; hoca bunun sağdaki 2 A ile karıştırıldığını ve doğrusunun $54/9 = 6$ A olduğunu belirtti.

## 6. Seri ve Paralel Bağlantıyı Tanımak

**Seri bağlantı** (ekrandan, 01:41:29): aynı akımı taşıyan, aralarında dallanma olmayan elemanlardır. Slayttaki devrede 60 V kaynak ile 8 Ω seridir. Ancak 8 Ω ile 4 Ω seri değildir, çünkü aralarındaki düğümden 10 Ω'a bir dal ayrılır. Kural şöyledir: bir elemandan sonra dallanmayan bir düğüm olabilir, ama başka bir dala giden düğüm olmamalıdır.

**Paralel bağlantı:** elemanların başlangıç ve bitiş düğümlerinin aynı olması gerekir. Araya bir eleman girerse yalnız tek eleman değil, eleman grubu paralel sayılır. Örneğin "bu ikisi seri, bu ikisi birbirine paralel, 4–10 bu paralel gruba seri" gibi grup halinde seri ve paralellik söz konusu olabilir.

Bir örnekte (ekranda; bu anın karesi yok) iki seri direnç ile 240 Ω'luk bir direnç paraleldi ve bu grup başka bir dirence seriydi. Hoca bu tür yapıları "bileşen 1, bileşen 2, bileşen 3" gibi kara kutularla çizerek sadeleştirmeyi önerdi. Son soru "en sonunda bu bileşenler nasıl dizilmiş?" idi; bazı öğrenciler paralel, bazıları seri dedi, doğru cevap seridir. <!-- BELİRSİZ: Bu örneğin devre şekli karelerde yok; direnç değerleri (240 Ω dışında) altyazıdan çıkarılamadı. -->

**Örnek 7** (ekrandan, 01:46:29): 2 A kaynak, 1,5 Ω, 2 Ω (üstten bir iletkenle kısa devre edilmiş), iki adet 4 Ω, 5 Ω ve 5 A kaynaktan oluşan devrede hangi elemanların seri ya da paralel olduğu soruldu. Hoca önce kısa devreyi gösterdi: 2 Ω'un üzerinden iletken geçtiği için 2 Ω'un hiçbir önemi yoktur, oraya düz bir çizgi varmış gibi düşünülür. Ekrandaki çizimde 2 A kaynakla 1,5 Ω bir grup, 5 Ω ile 5 A kaynak başka bir grup olarak işaretlendi. Bu ikisi kendi içinde seridir. Öğrencilerin "kalanların hepsi paralel mi?" sorusuna hoca evet dedi: kısa devreden sonra iki 4 Ω ve bu seri gruplar aynı iki düğüm arasında kalır.

## 7. Gerilim ve Akım Kaynaklarının Seri/Paralel Bağlanması

### 7.1 Seri gerilim kaynakları

Seri gerilim kaynakları, kutuplar sıralıysa (+ − + −) toplanır, ters bağlıysa çıkarılır ve tek bir eşdeğer kaynak elde edilir. Hoca uzaktan kumandalı araçlardaki pil yuvalarını örnek verdi: piller zikzak biçimde, artı-eksi-artı-eksi sırasıyla dizilir. Böylece dört adet 1,5 V pille 6 V elde edilir.

Bir örnekte hoca aynı devreyi iki yolla çözdü. Birinci yolda her kaynak ve direnç için KVL terimleri tek tek yazıldı. İkinci yolda önce seri kaynaklar kutuplarına göre toplanıp tek bir kaynağa indirildi, sonra KVL uygulandı. İki yol aynı sonucu verir. <!-- BELİRSİZ: Bu örneğin karesi yok; kaynak ve direnç değerleri (3 V, 9 V, 100 Ω, 220 Ω gibi) altyazıda bozuk geçiyor. -->

### 7.2 Paralel gerilim kaynakları

Slayt (ekrandan, 01:51:29) şunları söyler: $v_1 = v_2 = \dots$ değilse bu devre ideal kaynaklar için geçerli değildir. Bütün gerçek gerilim kaynaklarının iç direnci vardır ve gerilimleri genelde tam eşit değildir. Akım, gerilimi yüksek olan kaynaktan düşük olana denge kurulana kadar akar ve bu tehlikelidir. Doğru tasarlanmış eşit kaynak grubu ise tek kaynağın birkaç katı akım verebilir.

Hoca şöyle açıkladı: $V_2 > V_1$ ise akım $V_1$'e kaçar ve $V_1$ yanabilir ya da patlayabilir. Katalogdaki değerleri aynı olsa bile her pilin üretim, direnç ve yalıtım süreci farklıdır. Küçük farklardan doğan sızıntı akımı düşük gerilimli bataryanın patlamasına yol açabilir. Bu yüzden pratikte piller paralel bağlanmaz.

**Seri mi paralel mi?** Hoca lise fiziğindeki "daha parlak / daha uzun yanar" sorularını hatırlattı. 1,5 V'luk dört pil seri bağlanırsa LED 6 V ile daha parlak yanar ama piller daha kısa sürede biter. Paralel bağlanırsa gerilim 1,5 V kalır; bir pil bir gün dayanıyorsa dört pil LED'i dört gün besler. Hoca bunun teoride geçerli olduğunu, pratikte pillerin paralel bağlanmadığını tekrarladı.

### 7.3 Paralel akım kaynakları

Akım kaynaklarında durum gerilim kaynaklarının tersidir. Paralel akım kaynakları yönlerine göre doğrudan toplanır ya da çıkarılır. Bu, düğüm analizinden (KCL) gelir: düğüme giren akımlar çıkanlara eşittir.

Örnekte iki adet 2,5 A kaynak ters bağlı olduğu için birbirini götürür. Geriye 3 A kaynak ve iki adet 5 Ω paralel direnç kalır. Sonuç $-7{,}5$ V'tur (3 A × 2,5 Ω; eksi işareti seçilen polariteden gelir). Hoca okun yönünü değiştirip değerin işaretini de değiştirmenin hiçbir şeyi değiştirmediğini belirtti: bir düğüme göre "giren" olan akım ters okla "çıkan" olur ve denklem aynı kalır.

## 8. Dirençlerin Seri/Paralel Bağlanması ve İletkenlik

### 8.1 Seri dirençler ve güç

Seri dirençlerin eşdeğeri doğrudan toplanarak bulunur: $R_{\text{eş}} = R_1 + R_2 + \dots$

> **Hocanın vurgusu:** Direncin değeri devre çalışırken, yani güç varken ve akım akarken ölçülmez. Direnç devreden ayrıldıktan sonra ölçü aletiyle ölçülür. Devrenin içindeyken okunan değer, devrenin geri kalanı yüzünden gerçek direnç değerini vermez.

Seri devrede güç dağılımı (ekrandan, 01:56:29):

$$P_E = P_{R_1} + P_{R_2} + P_{R_3}, \qquad P_1 = V_1 I_1 = I_1^2 R_1 = \frac{V_1^2}{R_1}$$

Seri devrede akım bütün dirençlerde aynı olduğu için $P = I^2R$'den büyük direnç daha çok güç soğurur. Slaytta da "seri dirençli ağda direnç büyüdükçe soğurulan güç artar" yazar.

### 8.2 Paralel dirençler

Paralel dirençlerde bütün kol dirençlerinin tersleri toplanır ve sonucun tersi alınır:

$$\frac{1}{R_{\text{eş}}} = \frac{1}{R_1} + \frac{1}{R_2} + \dots$$

Derste $2{,}2\times10^3$ Ω ve $1{,}2\times10^3$ Ω içeren bir paralel örnekte sonuç 437 Ω bulundu. <!-- BELİRSİZ: Bu örneğin karesi yok. Python kontrolüne göre 437 Ω, 1 kΩ, 1,2 kΩ ve 2,2 kΩ'luk üç direncin paralel eşdeğeridir ($\approx 437{,}1$ Ω); yalnız 2,2 kΩ ∥ 1,2 kΩ $\approx 776$ Ω eder. Büyük olasılıkla devrede üçüncü bir 1 kΩ direnç vardı. -->

Paralel eşdeğer direnç her zaman kollardaki en küçük dirençten küçüktür. Örneğin $1/5 + 1/10 = 3/10$, tersi $10/3 \approx 3{,}3$ olur ve 5'ten küçüktür. Bu yüzden paralel bağlama direnç değerini küçültmek için kullanılır. Elde 5 kΩ yoksa iki adet 10 kΩ paralel bağlanır: $1/10 + 1/10 = 2/10$, tersi 5 kΩ.

**Paralel devrede güç.** Bütün kollarda gerilim $V$ aynıdır. Kollarda $4R$, $3R$ ve $2R$ dirençleri olsun: akımlar sırasıyla $V/4R$, $V/3R$ ve $V/2R$ olur. Büyük dirençli koldan daha az akım geçer. $P = I^2R$'de akım kare ile etki ettiği için güç de azalır. Sonuç: paralel devrede direnç büyüdükçe soğurulan güç azalır.

Gösterimde paralel dirençler $R_1 \parallel R_2$ biçiminde iki dikey çizgiyle yazılır. Üç ya da daha fazla paralel direnç ikişer ikişer de birleştirilebilir.

### 8.3 İletkenlik (conductance)

İletkenlik direncin tersidir: $G = 1/R$, $R = 1/G$. Bütün kurallar terse döner (ekrandan, 02:01:29):

- Paralelde eşdeğer iletkenlik, paralel iletkenliklerin toplamıdır: $G_{\text{eş}} = G_1 + G_2$.
- Seride iletkenliklerin tersleri toplanır ve sonucun tersi alınır.

### 8.4 Örnekler

**Seri kaynaklı devre.** Kaynaklar kutuplarına göre birleştirildi. 80 V ile ters bağlı 20 V'tan 60 V kalır, aynı yönde bağlı 30 V eklenince 90 V olur. Seri dirençlerin toplamı 30 Ω olduğu için $I = 90/30 = 3$ A bulunur. Akım pozitif çıktığı için yön doğrudur. 80 V kaynakta akım artı uçtan çıkar, kaynak üretir: $-240$ W. 20 V kaynakta akım artı uçtan girer, kaynak $60$ W tüketir. <!-- BELİRSİZ: Bu örneğin karesi yok; tek tek direnç değerleri ve 30 V kaynağın konumu altyazıdan net değil. Eşdeğer gerilim 90 V ve toplam direnç 30 Ω ile 3 A, −240 W ve 60 W tutarlıdır. -->

**Paralel akım kaynaklı devre.** Ters yönlü kaynaklardan net 10 A yukarı akım kalır. İki adet 10 Ω paralel direncin eşdeğeri $10/2 = 5$ Ω'dur. Gerilim $10 \times 5 = 50$ V olur. Ok aşağı baksaydı, akım polariteye göre ters olacağı için $-50$ V yazılırdı.

Derste sözlü olarak iki soru soruldu:

- Seri devrede direnç sayısı artarsa eşdeğer direnç ne olur? Öğrenciler "artar" dedi.
- Paralel kol sayısı artarsa (örneğin 3 kol yerine 7 kol) eşdeğer direnç ne olur? Öğrenciler "azalır" dedi.

Sunumun sonunda seri ve paralel bağlantı için direnç, iletkenlik ve güç formüllerini içeren bir özet tablo vardı.

## 9. Gerilim Bölücü

İkinci sunumda gerilim bölücü ve akım bölücü devreler anlatıldı. Bunlar seri ve paralel direnç düzenlerinde dirençlerin ayarlanmasıyla gerilimin ya da akımın bölündüğü yapılardır.

### 9.1 Türetme

Seri iki dirençli devrede (ekrandan, 02:16:29) bütün dirençlerden aynı akım geçer. Ana koldaki $V$ gerilimi $V_1$ ve $V_2$'ye dağılır. KVL:

$$-V + V_1 + V_2 = 0 \;\Rightarrow\; V = IR_1 + IR_2 = I(R_1 + R_2) = I\,R_{\text{eş}}$$

Ana kol akımı $I = V/R_{\text{eş}}$ olur. Bunu yerine koyunca:

$$V_1 = I R_1 = \frac{R_1}{R_1 + R_2}\,V, \qquad V_2 = \frac{R_2}{R_1 + R_2}\,V$$

Ana kol akımı belli olduğu için büyük direnç üzerinde daha büyük gerilim düşer.

**Örnek:** 9 V kaynak, 3 Ω ve 6 Ω seri. $V_1 = 9 \cdot 3/9 = 3$ V, $V_2 = 9 \cdot 6/9 = 6$ V.

Genel formül (ekrandan, 02:21:29), $N$ seri direnç için:

$$V_n = \frac{R_n}{R_1 + R_2 + \dots + R_N}\, V_{toplam} = \frac{R_n}{R_{\text{eş}}}\, V_{toplam}$$

Örneğin yedi seri direncin altıncısının gerilimi, $R_6$'nın toplam dirence oranının besleme gerilimiyle çarpımıdır.

### 9.2 Gerilimin ölçülmesi

Bir direnç üzerindeki gerilimi ölçmek için devrenin akışı kesilmez. Devre çalışırken ölçü aleti ilgili dirence **paralel** bağlanır. Slayttaki ölçüm örneğinde 60 mA akımla küçük dirençte 0,6 V, büyük dirençte 6 V civarında gerilim okunduğu söylendi. <!-- BELİRSİZ: Ölçüm slaytının karesi yok; direnç değerleri (10 Ω, 30 Ω, 100 Ω gibi) altyazıda bozuk. -->

Ölçü aletinin kırmızı (artı) ve siyah (eksi, toprak) ucu vardır. Ölçü aleti ters bağlanırsa gösterge eksi değer okur. Bu, sorulardaki polarite mantığıyla aynıdır.

### 9.3 Örnekler

**AC girişli bölücü.** 4 kΩ ve 3 kΩ seri dirençlere sinüs bileşenli bir gerilim uygulanır ve $V_1$, $V_2$ istenir. Hoca sinüs bileşenine şimdilik takılmamayı söyledi; bu konuya sinüzoidal sürekli halde gelinecek. Bölme oranları $3/7$ ve $4/7$'dir ve $V_1 + V_2$ giriş gerilimini verir. <!-- BELİRSİZ: Karesi yok; giriş gerilimi altyazıda hem "20 V DC" hem "20 sin 377t" diye geçiyor; hangi oranın hangi dirence ait olduğu net değil. -->

Üç dirençli seri devrede de aynı formül kullanılır: $V_1 = V\,R_1/(R_1 + R_2 + R_3)$.

**Örnek 03** (ekrandan, 02:26:29): $12\sin t$ V kaynağa 4 Ω seri, ardından 6 Ω ile 3 Ω paralel bağlıdır; 3 Ω üzerindeki $v_x$ istenir. Hoca bir püf noktası gösterdi: paralel hatlarda arada eleman olmadığı için 6 Ω üzerindeki gerilim de $v_x$'tir. $6 \parallel 3 = 2$ Ω olur. Bu 2 Ω, 4 Ω ile seri bir gerilim bölücü oluşturur:

$$v_x = 12\sin t \cdot \frac{2}{4 + 2} = 4\sin t\ \text{V}$$

Diğer bir yol da şudur: eşdeğer devreden ana kol akımı bulunur ve paralel eşdeğerle çarpılır.

## 10. Akım Bölücü

### 10.1 Türetme

Paralel dirençlerde akım kollar arasında bölünür. KCL'ye göre $I = I_1 + I_2$'dir. Paralel kollarda gerilim aynı olduğu için $I_1 = V/R_1$ ve $I_2 = V/R_2$ olur. $V$ ortak parantezine alınırsa $I = V\,(1/R_1 + 1/R_2)$, yani $V = I\,R_{\text{eş}}$ bulunur. Buradan:

$$I_1 = I\,\frac{R_2}{R_1 + R_2}, \qquad I_2 = I\,\frac{R_1}{R_1 + R_2}$$

Akım bölücüde ilişki ters orantılıdır. Gerilim bölücüde aranan direncin kendisi paya yazılır. Akım bölücüde ise paya **aranmayan koldaki** direnç yazılır. Bunun nedeni, küçük dirençli koldan daha büyük akım akmasıdır. İkiden fazla kol varsa diğer kolların eşdeğeri $R_{\text{eş}}$ olarak alınır:

$$I_1 = I\,\frac{R_{\text{eş}}}{R_1 + R_{\text{eş}}}$$

İletkenlikle yazıldığında akım bölücü formülü gerilim bölücünün aynısı olur, çünkü iletkenlik direncin tersidir.

### 10.2 Akımın ölçülmesi

Akım ölçmek için ölçü aleti devreye **seri** girmelidir. Akımın bölünmeden ölçü aletinin içinden geçmesi gerekir. Slayttaki düzenekte (ekrandan, 02:31:29) 12 V besleme, 1 kΩ ve 3 kΩ paralel dirençler ve ana koldaki mA metre görülür; gösterge 16,00 mA okur. Slaytta şu yazar: ölçü aletinin kırmızı (artı) ucu, kaynak akımı bu uçtan girip siyah (eksi) uçtan çıkacak biçimde bağlanır, böylece okuma pozitif olur.

Hoca yalnız $R_1$ kolunun akımını ölçmek için ne yapılacağını ekranda çizdi. Kol koparılır; kırmızı uç beslemeye, siyah uç koparılan direncin ayağına bağlanır. Böylece o kolun akımı ölçü aletinin içinden geçer.

> **Ek bilgi (derste anlatılmadı):** Slayttaki değerler tutarlıdır: $12\,\text{V}/1\,\text{k}\Omega + 12\,\text{V}/3\,\text{k}\Omega = 12 + 4 = 16$ mA.

### 10.3 Kısa yol: Oranlı paralel dirençler

Hoca iki paralel direncin eşdeğeri için pratik bir kural verdi: büyük direnç küçüğün $k$ katıysa

$$R_{\text{eş}} = \frac{R_{\text{büyük}}}{k + 1}$$

olur. Örnekler:

- 400 Ω ∥ 100 Ω: 4 kat fark var, bir fazlası 5; $400/5 = 80$ Ω.
- 12 Ω ∥ 4 Ω: 3 kat fark var, bir fazlası 4; $12/4 = 3$ Ω.
- 20 Ω ∥ 5 Ω: 4 kat fark var, bir fazlası 5; $20/5 = 4$ Ω.

Bu, $1/R_1 + 1/R_2$ formülünün matematiksel olarak aynısıdır (python ile doğrulandı).

> **Ders sonrası not:** Hoca 12 ve 4 değerleri için "biri 12 volt, biri 4" dedi; bunlar direnç değerleridir, doğrusu 12 Ω ve 4 Ω.

Akım bölücüye ait bir örnekte (dört dirençli paralel devre, 4 A giriş) eşdeğer direnç hesaplanıp $I_1 = 4 \cdot R_{\text{eş}}/(R_1 + R_{\text{eş}})$ formülü kullanıldı; bütün kol akımlarının toplamı 4 A'i verir. <!-- BELİRSİZ: Bu örneğin karesi yok; direnç değerleri ve eşdeğer direnç ("109") altyazıdan doğrulanamadı. -->

### 10.4 Örnek 05: DC ve AC kaynaklı karma devre

Devrede (ekrandan, 02:36:29) 1 V DC kaynak ile $0{,}5\sin(20t)$ V kaynak seri bağlıdır. Yük olarak $R_1 = 200$ Ω ile $R_2 = 400$ Ω ∥ $R_3 = 100$ Ω seridir. $V_1$ ve $V_p$ istenir. Hoca devrede iki gerilim bölücü ve bir akım bölücü bulunduğunu belirtti.

Giriş $1 + 0{,}5\sin 20t$ biçiminde yazılır. Hoca iki bileşenin tek bir sayı gibi toplanamayacağını söyledi: biri DC ofset, diğeri faz farkı olan bir sinüzoidal bileşendir; bu konu ileride işlenecek.

**Adım 1, paralel eşdeğer:**

$$R_{eq1} = \frac{R_2 R_3}{R_2 + R_3} = \frac{400 \cdot 100}{400 + 100} = 80\ \Omega$$

(Kısa yol: 4 kat fark, $400/5 = 80$ Ω.)

**Adım 2, gerilim bölücü:** Seri toplam $200 + 80 = 280$ Ω'dur.

$$V_1 = (1 + 0{,}5\sin 20t)\,\frac{200}{280} \approx 0{,}714 + 0{,}357\sin 20t\ \text{V}$$

$$V_p = (1 + 0{,}5\sin 20t)\,\frac{80}{280} \approx 0{,}286 + 0{,}143\sin 20t\ \text{V}$$

Diğer yollar: ana kol akımı $I_1 = (1 + 0{,}5\sin 20t)/280$ A bulunup 200 Ω ile çarpılır. $V_p$ ise toplam gerilimden $V_1$ çıkarılarak ya da $I_1$, $R_{eq1}$ ile çarpılarak da bulunabilir. Hepsi aynı sonucu verir.

**Adım 3, akım bölücü:**

$$I_2 = I_1\,\frac{100}{500}, \qquad I_3 = I_1\,\frac{400}{500}$$

Sayısal değerler python ile hesaplandı: $I_1 \approx 3{,}57 + 1{,}79\sin 20t$ mA.

## 11. Laboratuvar Tanıtım Oturumu: Simülasyonla Ölçüm

Kaydın sonunda, dersten sonra ayrı yürütülen bir laboratuvar tanıtım oturumu (Lab 0) bulunur. Bu oturumda deneylerde kullanılacak simülasyon programları gösterildi. Aşağıda yalnız akademik kısımlar özetlenmiştir.

### 11.1 DC ve AC gerilim

DC gerilimin yönü ve şiddeti zamanla değişmez. Gerçekte küçük dalgalanmalar olabilir, ama tanım olarak yönü ve şiddeti sabittir. AC gerilimin ise yönü ve şiddeti değişir. Gerilim yavaş yavaş artıp tepeye ulaşır, sonra azalıp sıfırdan geçer ve ters yönde aynı şeyi tekrarlar. Evlerdeki şebekenin frekansı 50 Hz'dir.

Laboratuvarda kullanılan temel araçlar devre tahtası (board), multimetre ve osiloskoptur. Kullanılan elemanlar dirençler, kondansatörler, diyotlar (akımı anottan katoda geçirir, ters yönde geçirmez), zener diyotlar (ters yönde belli bir gerilimden sonra iletir), bobinler, üç bacaklı transistörler (beyz, emiter, kolektör) ve op-amplardır.

### 11.2 Simülasyonda ölçüm

Proteus'ta voltmetre ölçülen elemana paralel, ampermetre seri bağlanır. Ampermetre seri bağlanmazsa ölçüm yapmaz.

> **Ders sonrası not:** Anlatımda önce "ampermetre devreye paralel bağlanır" dendi, hemen ardından bunun voltmetre olduğu düzeltildi. Doğrusu: voltmetre paralel, ampermetre seri bağlanır.

**Seri devre örneği** (ekrandan, 03:05:09): 80 V kaynağa 5 Ω, 10 Ω, 20 Ω ve 5 Ω dirençler seri bağlıdır. Her direncin voltmetresi sırasıyla yaklaşık 9,98 V, 20,0 V, 39,9 V ve 9,98 V gösterir. Hesapla $R_{\text{eş}} = 40$ Ω, $I = 80/40 = 2$ A ve gerilimler 10, 20, 40, 10 V'tur (python ile doğrulandı). Hesap ile simülasyon arasındaki küçük farklar (40 yerine 39,9 gibi) ölçü aletinin iç direncinden gelir. Bu yakınlıktaki değerler doğru kabul edilir.

**Kirchhoff devresi:** Bir düğümden ayrılan kol akımlarının toplamı, düğüme gelen akıma eşittir. Akım hem ampermetreyle hem akım probu ile okunabilir. İki okuma arasında iç dirençten kaynaklanan küçük farklar olabilir.

### 11.3 Osiloskop

Gerçek osiloskoplarda genelde iki kanal bulunur. Her kanalın probunda ölçülecek noktaya bağlanan uç ve toprağa bağlanan bir uç vardır. Proteus'taki dört kanallı osiloskopta toprak ucu yoktur; her kanal bağlandığı noktanın gerilimini gösterir. Multisim'deki osiloskopta ise artı ve eksi uçlar ayrıdır.

**Diyotlu devre** (ekrandan, 03:15:09): Sinüs kaynak (genliği 40 V, frekansı 100 Hz olarak ayarlandı), 1N4001 diyot ve 1 kΩ direnç seri bağlıdır. Osiloskobun A kanalı (sarı) girişi, D kanalı (yeşil) direnç gerilimini gösterir. Kanalların konumu (position) sıfıra getirilir ki dalgalar karşılaştırılabilsin. Kullanılmayan B ve C kanalları kapatılır. Diyot akımı yalnız bir yönde geçirdiği için direnç geriliminde eksi yarım dalgalar kırpılır.

**Ölçek okuma:** Ekrandaki her karenin değeri volt/div ayarıyla belirlenir. Ayar 5 V/div iken kare sayısı 5 ile çarpılır. Anlatımda 40 V'luk dalganın 8 kare tuttuğu söylendi ($8 \times 5 = 40$ V).

> **Ders sonrası not:** Büyük olasılıkla burada 8 kare, sıfır çizgisinden tepeye kadar olan kısımdır. Proteus'taki sinüs kaynağın genlik (amplitude) değeri tepe değeridir. 40 V tepe değer, 5 V/div'de sıfırdan tepeye 8 kare eder; tepeden tepeye (uçtan uca) ise 80 V, yani 16 kare olur.

**Multisim örnekleri:** 12 V kaynak ve 1 kΩ dirençli basit devrede multimetre ile gerilim ve akım okundu; $I = V/R = 12$ mA. Multimetrenin siyah ucu her zaman COM'a, kırmızı ucu ölçülen büyüklüğe göre ilgili girişe takılır. Wattmetre ile güç ($P = IV$) ölçülebilir; artı uçlar artıya, eksi uçlar eksiye bağlanır. 60 Hz AC kaynak, 1 kΩ direnç ve 100 nF kondansatörlü devrede osiloskop, direnç ve kondansatör gerilimleri arasında faz farkı gösterdi. Kondansatör enerji depolayıp bırakır; bu konu sonraki deneylerde işlenecektir.

**Soru:** Toprağı (ground) her seferinde koymak zorunda mıyız?
**Cevap:** Toprak, devrenin referans noktasıdır. Gerçek devrelerde toprak bağlanmazsa devre çalışmaz. Simülasyonda bazen toprak olmadan da çalışabilir, ama her seferinde konması önerilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:21:29): Şekildeki devrede her elemanın soğurduğu gücü hesaplayın. Devre: 120 V kaynak, 30 Ω ($v_{30}$), $2v_A$ bağımlı gerilim kaynağı ve 15 Ω (üzerinde $v_A$, + ucu altta) seri bağlıdır.

> **Çözüm:** KVL: $-120 + v_{30} + 2v_A - v_A = 0$, $v_{30} = 30i$, $v_A = -15i$. Buradan $i = 8$ A ve $v_A = -120$ V bulunur. Güçler: $p_{120V} = -960$ W, $p_{30\Omega} = 1920$ W, $p_{dep} = -1920$ W, $p_{15\Omega} = 960$ W. Toplam sıfırdır.

**Soru 2** (ekrandan, 00:36:29): Devredeki beş elemanın her birinin soğurduğu gücü bulun. Devre: 30 Ω ($v_x$, + üstte), 12 V kaynak, 8 Ω, 7 Ω ve $4v_x$ bağımlı gerilim kaynağı tek çevrededir.

> **Çözüm:** $-v_x - 12 + 15i + 4v_x = 0$ ve $v_x = -30i$'den $i = -4/25$ A, $v_x = 24/5$ V bulunur. Güçler: 30 Ω $0{,}768$ W; 12 V kaynak $1{,}92$ W (tüketir); 8 Ω $0{,}2048$ W; 7 Ω $0{,}1792$ W; bağımlı kaynak $-3{,}072$ W (üretir). Derste akım ve işaretler çözüldü; sayısal güçler python ile hesaplandı.

**Soru 3** (ekrandan, 01:06:29): Devredeki her elemanın gerilimini, akımını ve gücünü bulun. Devre: 120 A kaynak, $1/30$ Ω, 30 A kaynak (aşağı) ve $1/15$ Ω paralel bağlıdır.

> **Çözüm:** $-120 + 30v + 30 + 15v = 0$'dan $v = 2$ V, $i_1 = 60$ A, $i_2 = 30$ A bulunur. Güçler: $P_{R1} = 120$ W, $P_{R2} = 60$ W, $P_{120A} = -240$ W, $P_{30A} = 60$ W.

**Soru 4** (ekrandan, 01:11:29): $v$ değerini ve bağımsız akım kaynağının soğurduğu gücü bulun. Devre: 6 kΩ, $2i_x$ bağımlı akım kaynağı, 24 mA kaynak ve 2 kΩ paralel bağlıdır.

> **Çözüm:** $v/6000 - 2(-v/2000) - 0{,}024 - (-v/2000) = 0$'dan $v = 14{,}4$ V bulunur. $P_{24\,mA} = -14{,}4 \times 0{,}024 \approx -0{,}346$ W; kaynak güç üretir.

**Soru 5** (ekrandan, 01:36:29): Tek düğüm çiftli devrede $i_A$, $i_B$ ve $i_C$'yi bulun. Devre: 5,6 A kaynak, 18 Ω, $0{,}1v_x$ bağımlı kaynak, 9 Ω ve 2 A kaynak (aşağı) paralel bağlıdır.

> **Çözüm:** $5{,}6 - v_x/18 + 0{,}1v_x - v_x/9 - 2 = 0$'dan $v_x = 54$ V bulunur. $i_A = 3$ A, $i_B = -5{,}4$ A, $i_C = 6$ A.

**Soru 6** (ekrandan, 01:46:29): Şekildeki devrede (a) hangi tek elemanlar, (b) hangi eleman grupları seri ya da paraleldir? Devre: 2 A kaynak, 1,5 Ω, kısa devre edilmiş 2 Ω, iki adet 4 Ω, 5 Ω ve 5 A kaynak.

> **Çözüm (derste verilen):** 2 Ω kısa devre edildiği için devreden düşer. 2 A kaynak ile 1,5 Ω seridir; 5 Ω ile 5 A kaynak seridir. Kısa devreden sonra iki adet 4 Ω ve bu iki seri grup aynı iki düğüm arasında kalır, yani birbirine paraleldir.

**Soru 7** (derste sözlü, 02:04:39): Seri devrede direnç sayısı artarsa eşdeğer direnç ne olur? Paralel kol sayısı artarsa ne olur?

> **Çözüm (derste verilen):** Seride eşdeğer direnç artar, paralelde azalır.

**Soru 8** (ekrandan, 02:26:29): Şekildeki devrede $v_x$'i bulun. Devre: $12\sin t$ V kaynak, 4 Ω seri, ardından 6 Ω ∥ 3 Ω.

> **Çözüm:** $6 \parallel 3 = 2$ Ω olur; gerilim bölücüden $v_x = 12\sin t \cdot 2/6 = 4\sin t$ V.

**Soru 9** (ekrandan, 02:36:29): $V_1$ ve $V_p$'yi bulun. Devre: $1\,\text{V} + 0{,}5\sin(20t)$ V kaynak, 200 Ω, ardından 400 Ω ∥ 100 Ω.

> **Çözüm:** $R_{eq1} = 80$ Ω. $V_1 = (1 + 0{,}5\sin 20t)\cdot 200/280$, $V_p = (1 + 0{,}5\sin 20t)\cdot 80/280$. Kol akımları $I_2 = I_1 \cdot 100/500$, $I_3 = I_1 \cdot 400/500$.

## Dersin Toparlaması

Bu derste KVL ve KCL, güç işaret kuralı ve enerjinin korunumu üzerinden örneklerle pekiştirildi. Tek çevreli devrelerde akım için bir yön seçilip KVL yazıldı. Tek düğüm çiftli devrelerde ortak gerilim üzerinden KCL yazıldı. İki tür devrede de bütün bilinmeyenler tek bir değişkene indirildi. Bağımlı kaynakların üreten mi tüketen mi olduğunun kontrol değişkeni bulunmadan anlaşılamayacağı gösterildi. Eksi çıkan akımın, yön çevrilerek ya da eksi değerle kullanılarak aynı sonuca götürdüğü vurgulandı. Her çözüm güçlerin toplamının sıfır olduğu kontrol edilerek doğrulandı.

Dersin ikinci yarısında seri ve paralel bağlantıyı tanıma, kaynakların ve dirençlerin seri ve paralel birleştirilmesi, iletkenlik, gerilim bölücü ve akım bölücü formülleri ile gerilim ve akım ölçme kuralları işlendi. Hoca girişte sinüzoidal bileşen bulunan örneklerde DC ve AC bileşenlerin neden doğrudan toplanamadığını ileride sinüzoidal sürekli hal konusunda ele alacaklarını belirtti. Bölücü devre konularının bir sonraki derste kısaca tekrar edileceğini de söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
