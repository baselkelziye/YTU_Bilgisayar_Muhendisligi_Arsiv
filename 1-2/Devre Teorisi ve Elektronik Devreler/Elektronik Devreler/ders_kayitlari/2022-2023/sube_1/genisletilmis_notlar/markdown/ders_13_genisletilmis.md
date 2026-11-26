# Ders 13 Genişletilmiş Notu: Diyot Devreleri Soru Çözümleri: Seri-Paralel Devreler, Doğrultucular, Kırpıcılar ve Zener

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Diyot Modellerinin Tekrarı
- 2. Seri Diyot Devreleri
- 3. İki Kaynaklı ve İki Diyotlu Devreler
- 4. Yarım Dalga Doğrultucu ve DC Seviyesi
- 5. Dirençli Köprü ile Tam Dalga Doğrultucu
- 6. Seri Kaynaklı Kırpıcı: Çıkışı Nokta Nokta Çizmek
- 7. Zener Diyot ve Gerilim Regülatörü
- 8. Ayarlı Yüklü Zener Regülatörü: Çalışma Aralığı
- 9. Seri ve Paralel Kırpıcı Ayrımı
- Örnek Sorular
- Dersin Toparlaması

## 1. Diyot Modellerinin Tekrarı

Bu ders, o zamana kadar işlenen teorik konuların soru çözümüne ayrıldı. Sorular İngilizce bir ders kitabından derlenmiş bir soru dosyası üzerinden çözüldü; hoca dosyanın üzerine kalemle çizerek ilerledi. Başlangıçta kitaptaki "Diyot eşdeğer devreleri (modeller)" tablosu üzerinden diyot modelleri hatırlatıldı (ekrandan, 00:05:00).

Tabloda üç model vardır:

| Model | Koşul | Eşdeğer devre | Karakteristik |
|---|---|---|---|
| Parçalı doğrusal model | — | $V_T$ kaynağı + $r_{av}$ direnci + ideal diyot, seri | $V_T$'den sonra $r_{av}$ eğimli doğru |
| Basitleştirilmiş model | $R_{network} \gg r_{av}$ | $V_T$ kaynağı + ideal diyot, seri | $V_T$'de dikey yükselen doğru |
| İdeal eleman | $R_{network} \gg r_{av}$, $E_{network} \gg V_T$ | yalnız ideal diyot | $0$'da dikey yükselen doğru |

İdeal diyotta $V_D$ sıfırı çok az geçtiği anda (hocanın deyişiyle "sıfır artı epsilon" kadar sonra) diyot kısa devre gibi davranır ve akım akmaya başlar; üzerinde gerilim birikmez. Ters gerilimde akım akmaz. Daha gerçekçi modelde diyotun iletime geçmesi için tükenme bölgesini (depletion region) aşacak bir iç gerilim gerekir: silisyumda 0,7 V, germanyumda 0,3 V. Bir adım daha ileri gidildiğinde diyotun bir iç direnci de olduğu görülür. Gerçek diyot eğrisi ise eşik geriliminden sonra üstel olarak yükselir.

## 2. Seri Diyot Devreleri

### 2.1 Tek silisyum diyotlu temel devre

İlk soruda $E = 10$ V'luk DC kaynak, silisyum diyot ve $R = 1$ k$\Omega$'luk direnç seri bağlıdır; diyotun karakteristik eğrisi de verilmiştir. Sorulan $V_{D_Q}$, $I_{D_Q}$ ve $V_R$'dir (ekrandan, 00:10:00).

Hoca diyotun A ucunu (anot tarafı) 10 V, B ucunu (direnç tarafı) bilinmeyen olarak işaretledi. Kaynağın eksi ucu toprağa bağlıdır; diyotun artı ucu daha yüksek gerilimde olduğu için diyot iletime geçer. Kaynak DC olduğu için diyot sürekli iletimdedir.

Diyot ideal kabul edilirse bütün gerilim dirençte düşer:

$$I = \frac{10\text{ V}}{1\text{ k}\Omega} = 10 \times 10^{-3}\text{ A} = 10\text{ mA}$$

Gerçekçi hesapta silisyum diyotun üzerinde 0,7 V düşer. Direncin üzerinde $10 - 0{,}7 = 9{,}3$ V kalır ve akım

$$I = \frac{9{,}3\text{ V}}{1\text{ k}\Omega} = 9{,}3\text{ mA}$$

olur. Hoca, gerçekçi hesapta 10 mA yerine 9,3 mA bulunması gerektiğini vurguladı. Yük hattı (load line) kısmını bu derste atladı. <!-- BELİRSİZ: hoca 00:10:37 civarında bir direncin kitapta "2 k" verildiğini, 1 olması gerektiğini söylüyor; ekrandaki şekilde direnç 1 kΩ görünüyor, hangi değerden söz ettiği net değil -->

### 2.2 Silisyum diyot ve 2,2 k$\Omega$ dirençli devre

Bir sonraki soruda A ucunda 8 V vardır, silisyum diyot ve 2,2 k$\Omega$'luk direnç üzerinden toprağa gidilir. Hoca bunu, A ucundan toprağa doğrudan giden bir 8 V'luk kol ile diyot ve direnç üzerinden giden ikinci bir kolun paralel olması gibi düşünmeyi önerdi; iki kolun gerilimi eşittir:

$$V_A = V_D + V_R \;\Rightarrow\; 8 = 0{,}7 + V_R \;\Rightarrow\; V_R = 7{,}3\text{ V}$$

$$I = \frac{7{,}3\text{ V}}{2{,}2\text{ k}\Omega} \approx 3{,}32\text{ mA}$$

Bu akım hem dirençten hem diyottan geçen ana kol akımıdır.

### 2.3 Seri silisyum ve germanyum diyot

Kitaptaki "Example 2.9" sorusunda $V_o$ ve $I_D$ isteniyor (ekrandan, 00:15:00). Devrede $+12$ V'luk bir uç, seri bir silisyum ve bir germanyum diyot ve toprağa bağlı 5,6 k$\Omega$'luk direnç vardır. Çıkış direncin üzerindedir.

Hoca, "+12 V" yazılan ucun aslında eksi ucu toprakta olan 12 V'luk bir DC kaynak gibi düşünülebileceğini gösterdi. Kirchhoff gerilim yasası:

$$V_A = V_{Si} + V_{Ge} + V_R$$

$$12 = 0{,}7 + 0{,}3 + V_R \;\Rightarrow\; V_o = V_R = 11\text{ V}$$

$V_R$'nin bir diğer adı burada $V_{out}$'tur, yani toprağa göre çıkış gerilimidir. Direnç akımı:

$$I_D = I_R = \frac{V_R}{R} = \frac{11\text{ V}}{5{,}6\text{ k}\Omega} \approx 1{,}96\text{ mA}$$

Kitaptaki çözüm şeklinde iki diyotun yerine sırasıyla 0,7 V ve 0,3 V'luk, kaynağa ters yönde kaynaklar çizilmiştir; gerilim düşümleri bu şekilde yapılır (ekrandan, 00:15:00).

## 3. İki Kaynaklı ve İki Diyotlu Devreler

### 3.1 Toprağa göre negatif kaynaklı uç

"Example 2.11"de (ekrandan, 00:20:00) bir uca $E_1 = 10$ V, diğer uca $E_2 = -5$ V bağlanmıştır; arada 4,7 k$\Omega$'luk $R_1$, silisyum diyot ve 2,2 k$\Omega$'luk $R_2$ vardır. Hoca, önceki sorularda hep toprağa gidildiğini, burada ise iki ucun farklı kaynaklara bağlandığını belirtti.

Çözüm fikri: 10 V'luk uç, toprağa giden 10 V'luk bir kaynaktır. $-5$ V'luk uç ise toprağa ters bağlanmış 5 V'luk bir kaynaktır. Böylece topraktan başlayıp toprağa dönen tek bir çevre oluşur. Kirchhoff gerilim yasasında $-E_2$ karşı tarafa geçince iki kaynak toplanır:

$$10 + 5 - 0{,}7 = V_{R_1} + V_{R_2} \;\Rightarrow\; 14{,}3\text{ V} = V_{R_1} + V_{R_2}$$

Akım bütün seri elemanlarda aynı olduğu için:

$$I R_1 + I R_2 = I(R_1 + R_2) = 14{,}3\text{ V} \;\Rightarrow\; I = \frac{14{,}3\text{ V}}{R_1 + R_2}$$

> **Ders sonrası not:** Hoca $R_1 + R_2 = 4{,}7 + 2{,}2$ toplamını 5,9 k$\Omega$ yazdı ve $I = 14{,}3/5{,}9 \approx 2{,}42$ mA buldu (ekrandan, 00:20:00). Doğrusu $R_1 + R_2 = 6{,}9$ k$\Omega$ ve $I = 14{,}3/6{,}9 \approx 2{,}07$ mA'dir (python ile kontrol edildi).

### 3.2 İki diyotlu devre: $I_1$, $I_2$, $I_{D_2}$

"Example 2.15"te (ekrandan, 00:25:00) $E = 20$ V'luk kaynak, seri bir silisyum diyot ($D_1$), ondan sonra iki paralel kol vardır: bir kolda ikinci silisyum diyot ($D_2$), diğer kolda $R_1 = 3{,}3$ k$\Omega$. Bu iki kol alt düğümde ($a$) birleşir ve $R_2 = 5{,}6$ k$\Omega$ üzerinden kaynağa döner. İstenen $I_1$ ($R_1$ akımı), $I_2$ ($R_2$ akımı) ve $I_{D_2}$'dir.

Kaynak 20 V olduğu için iki silisyum diyot da iletimdedir. $R_1$ ile $D_2$ paralel olduğundan gerilimleri eşittir: $V_{BC} = V_{D_2} = 0{,}7$ V. Buradan:

$$I_1 \cdot 3{,}3\text{ k}\Omega = 0{,}7\text{ V} \;\Rightarrow\; I_1 \approx 0{,}212\text{ mA}$$

Hoca burada birim dönüşümünü hatırlattı: 0,212 mA mikroampere çevrilirken virgül üç basamak sağa kaydırılır, $0{,}212$ mA $= 212$ µA olur. Mili $10^{-3}$, mikro $10^{-6}$'dır.

$I_2$ için iki diyot ve $R_2$'yi içeren çevre yazılır:

$$E = V_{D_1} + V_{D_2} + V_{R_2} \;\Rightarrow\; 20 = 0{,}7 + 0{,}7 + I_2 R_2$$

$$18{,}6 = I_2 \cdot 5{,}6\text{ k}\Omega \;\Rightarrow\; I_2 \approx 3{,}32\text{ mA}$$

Alt düğümde $D_2$'den ve $R_1$'den gelen akımlar birleşip $R_2$'den çıkar:

$$I_{D_2} + I_1 = I_2 \;\Rightarrow\; I_{D_2} = 3{,}32 - 0{,}212 \approx 3{,}11\text{ mA}$$

Son değer kitaptaki çözümde görünüyor (ekrandan, 00:25:00); hoca derste yalnız düğüm denklemini kurdu.

## 4. Yarım Dalga Doğrultucu ve DC Seviyesi

### 4.1 İdeal diyotla çıkış ve DC seviyesi

"Example 2.18"de (ekrandan, 00:30:00) girişi tepe değeri 20 V olan bir sinüs, diyot ve 2 k$\Omega$'luk direnç vardır. Diyot, katodu giriş tarafında (A noktası) olacak şekilde bağlıdır. İstenenler: (a) çıkışı çizmek ve DC seviyesini bulmak, (b) ideal diyot yerine silisyum diyot koyup tekrarlamak, (c) $V_m$ 200 V'a çıkarıldığında (a) ve (b)'yi karşılaştırmak.

Giriş pozitifken A noktası B noktasından yüksektir ve diyot iletimde değildir; devre kopuktur. Üzerinden akım geçmeyen dirençte gerilim olmaz, çıkış 0'dır. Giriş negatifken A noktası B'den düşük olur, diyot iletime geçer ve ideal olduğu için kısa devre gibi davranır; çıkış girişi aynen izler. Sonuç olarak yalnız negatif yarım dalgalar geçer: bu bir yarım dalga doğrultucudur.

DC seviyesi:

$$V_{dc} = -0{,}318 V_m = -0{,}318(20\text{ V}) = -6{,}36\text{ V}$$

Eksi işaret, geçen yarım dalganın negatif olmasındandır; çıkışın polaritesi tanımlanan yönün tersidir (ekrandan, 00:30:00).

### 4.2 Silisyum diyotla

Silisyum diyotta iletim sırasında diyot üzerinde 0,7 V düşer, bu değer tepe gerilimden çıkarılır (ekrandan, 00:35:00):

$$V_{dc} = -0{,}318(20 - 0{,}7) \approx -6{,}14\text{ V}$$

DC seviyesi 6,36 V'tan 6,14 V'a iner; fark yaklaşık 0,22 V'tur, bu da yaklaşık %3,5'lik bir düşüştür.

### 4.3 Giriş 200 V olursa

İdeal diyotla $V_{dc} = -0{,}318(200) = -63{,}6$ V olur. Silisyum diyotla $-0{,}318(199{,}3) \approx -63{,}38$ V'tur. Fark yine yaklaşık 0,22 V'tur ama 63,6 V'un içinde çok küçük bir orandır (yaklaşık %0,35). Hoca buradan şu sonucu çıkardı: giriş gerilimi büyüdükçe diyot üzerinde düşen gerilimin sonuca etkisi önemsizleşir.

> **Ders sonrası not:** Altyazıda 200 V'luk durumun silisyum diyotlu değeri "6.38" diye geçiyor; doğrusu yaklaşık $-63{,}38$ V'tur (python ile kontrol edildi).

### 4.4 0,318 ve 0,636 katsayıları nereden geliyor?

**Soru:** Yukarıdaki soruda neden 0,318 ile çarpıldı? **Cevap:** Çıkış bir AC işaretin yalnız bir yarım periyodudur. Bu işareti bir periyot boyunca sabit bir DC seviyeye dönüştürmek istersek, o DC seviyenin bir periyot boyunca altında kalan alan, geçen yarım dalganın altında kalan alana eşit olmalıdır. Sinüsün bir yarım periyodunun alanı periyoda yayıldığında bu seviye $0{,}318 V_m$ olur. Her iki yarım periyot da (aynı yönde) geçirilirse alan iki katına çıkar ve DC seviyesi $0{,}636 V_m$ olur. Yani bu katsayılar sinüsün altında kalan alandan gelir.

> **Ek bilgi (derste anlatılmadı):** Bu katsayılar integralden çıkar: $\frac{1}{T}\int_0^{T/2} V_m \sin(\omega t)\,dt = V_m/\pi \approx 0{,}318 V_m$. Tam dalgada sonuç $2V_m/\pi \approx 0{,}636 V_m$ olur.

## 5. Dirençli Köprü ile Tam Dalga Doğrultucu

### 5.1 Pozitif yarım periyot

"Example 2.19"da (ekrandan, 00:40:00 ve 00:45:00) giriş tepe değeri 10 V olan bir sinüstür. Köprüde iki diyot ve üç adet 2 k$\Omega$'luk direnç vardır; çıkış ($v_o$) köprünün ortasındaki dirençlerden birinin üzerinde tanımlanmıştır. Hoca köprünün düğümlerini A (giriş üst ucu), B ve C diye işaretledi.

Pozitif yarım periyotta A ucuna bağlı diyot iletimdedir ve kısa devre gibi davranır. Devre yeniden çizildiğinde iki 2 k$\Omega$ direnç birbirine seri olur, üçüncü 2 k$\Omega$ direnç de bu seri ikiliye paralel bağlanır. A ile B uçları arasındaki gerilim doğrudan girişe eşittir: $V_{AB} = v_i$. Çıkış seri iki dirençten birinin üzerindedir. İki direnç eşit olduğu için gerilim yarı yarıya paylaşılır:

$$v_o = \tfrac{1}{2} v_i, \qquad V_{o,max} = \tfrac{1}{2}(10\text{ V}) = 5\text{ V}$$

Hoca, dirençler farklı olsaydı (örneğin 3 k$\Omega$ ve 7 k$\Omega$) çıkışta oranına göre yalnız 3 V düşeceğini söyledi.

**Soru:** 2,2 k$\Omega$ nereden geldi? **Cevap:** Hoca önceki sorulardaki değerin aklında kaldığını belirtip düzeltti; bu sorudaki dirençler 2 k$\Omega$'dur (ekrandan, 00:45:00).

### 5.2 Negatif yarım periyot

Negatif yarım periyotta ilk diyot iletmez; A noktası C'den daha düşük gerilimde olduğu için diğer diyot iletir ve kısa devre olur. Devre bu kez farklı uçtan paralelleşir: ilk durumda dirençler B noktasından, ikinci durumda diğer uçtan paralel bağlanır. Eksi 10 V yine iki seri dirence eşit paylaşılır. Ancak bu kez çıkış direnci ters yönde kutuplandığı için çıkış yine pozitif yönde 5 V tepeli bir yarım dalga olarak görülür.

Her iki yarım periyot da aynı yönde geçtiği için devre tam dalga doğrultucudur. DC seviyesi:

$$V_{dc} = 0{,}636 V_m = 2 \times 0{,}318 \times 5\text{ V} = 3{,}18\text{ V}$$

**Soru:** $V_{max}$'ın 5 V alınması, çıkış olarak tanımlanan dirençten 5 V geçmesinden mi? **Cevap:** Evet. Girişe 10 V uygulanıyor; iki eşit direnç seri olduğu için 10 V ikiye bölünüyor ve çıkış direncinde 5 V düşüyor.

**Soru:** Akım neden zikzaklı yoldan gidiyor da yalnız tek dirençli alt yolu tercih etmiyor? **Cevap:** Bir seçim söz konusu değildir; A noktasından itibaren akım iki kola ayrılır. Bir kolda seri iki direnç, diğer kolda onlara paralel tek direnç vardır ve iki koldan da akım geçer.

## 6. Seri Kaynaklı Kırpıcı: Çıkışı Nokta Nokta Çizmek

Hoca, derste de çözülen bu tür kırpıcı (clipper) devrelerinin önemli olduğunu belirtti.

> **Hocanın vurgusu:** Kırpıcı devrelerinin nasıl çözüldüğü önemlidir. Kritik gerilimleri bulup çıkışı doğru çizmek gerekir. Farklı konfigürasyonlara mutlaka çalışılmalıdır: kaynak ya da diyot ters yönde olabilir, diyot seri kolda ya da paralel kolda olabilir.

Soruda (ekrandan, 00:55:00) giriş tepe değeri 20 V olan bir sinüstür. Girişe seri olarak $V = 5$ V'luk bir kaynak (artı ucu diyot tarafında) ve bir diyot bağlıdır; çıkış $v_o$, toprağa giden $R$ direncinin üzerindedir. İstenen, çıkış dalga şeklidir.

Yöntem, girişten değerler seçip her biri için diyotun durumuna bakmaktır:

- $v_i = 0$ V: Diyotun A ucunda 5 V vardır, B ucundan yüksektir; diyot iletimdedir, kısa devre olur ve çıkışta 5 V görülür.
- $v_i = 2$ V: A ucunda $5 + 2 = 7$ V vardır, diyot iletimdedir, çıkış 7 V'tur.
- $v_i = 5$ V: çıkış 10 V'tur. Tepe noktada $v_i = 20$ V iken çıkış $20 + 5 = 25$ V olur.
- Pozitif yarım periyodun tamamında çıkış $v_o = v_i + 5$ V'tur; giriş sıfıra döndüğünde çıkış 5 V'ta kalır.
- $v_i = -1$ V: diyot hâlâ iletimdedir, çıkış 4 V'tur. $v_i = -2$ V için 3 V, $v_i = -4$ V için 1 V'tur.
- $v_i = -5$ V: kaynak gerilimi tamamen dengelenir, diyot iletimden çıkar ve açık devre olur. Bu andan itibaren çıkış 0 V'tur.
- Giriş $-5$ V'un altında kaldığı sürece çıkış 0'dır. Giriş tekrar $-5$ V'un üstüne çıkınca ($-4$, $-3$, $-2$ V) diyot yeniden iletir ve çıkış giriş + 5 V olarak yükselmeye başlar.

Böylece çıkış, girişin 5 V yukarı kaydırılmış biçimidir; ancak girişin $-5$ V'un altında kalan kısmı kırpılır (0 V olur). Hoca, çıkışın girişin negatif yarım periyoduna da bir süre "sarktığına", ancak $-5$ V noktasında sıfırlandığına dikkat çekti. Çıkış ile giriş arasında her noktada 5 V fark vardır.

## 7. Zener Diyot ve Gerilim Regülatörü

### 7.1 Zener nasıl çalışır?

Hoca öğrencilere zenerin nasıl çalıştığını sordu; bir öğrenci diyotun ters bağlandığını söyledi. Zener devreye ters yönde bağlanır. Örneğin 10 V'luk bir zenerin uçlarına 8 V ya da 7 V uygulanırsa zener açık devre gibi davranır ve üzerinden akım geçmez; $V_Z$'nin altındaki bütün gerilimlerde durum budur. Üzerine düşmeye çalışan gerilim $V_Z$'yi aşınca zener, üzerinde yalnız $V_Z$ kadar gerilim tutar. Örneğin bir dirençle seri 12 V uygulanırsa zenerde 10 V, dirençte kalan 2 V düşer.

Zener, kendisine paralel olan yükü korur: giriş ne kadar artırılırsa artırılsın yükün üzerinde en fazla $V_Z$ olur. Hoca bunu bir tür sınırlayıcı (kısıtlayıcı) olarak düşünmeyi önerdi.

### 7.2 Zener çıkarılınca: gerilim bölücü

"Example 2.26"da (ekrandan, 01:00:00) $V_i = 16$ V, seri $R = 1$ k$\Omega$, $V_Z = 10$ V, $P_{ZM} = 30$ mW'lık zener ve $R_L = 1{,}2$ k$\Omega$ vardır. (b) şıkkında $R_L = 3$ k$\Omega$ alınır.

Önce zener devreden çıkarılır; kalan devre bir gerilim bölücüdür. Hoca gerilim bölücüyü hatırlattı: $R_2$'nin üzerindeki gerilim, toplam direnç içindeki payı kadardır:

$$V_B = \frac{R_2}{R_1 + R_2} V_A$$

İki direnç eşit olsaydı gerilim yarı yarıya paylaşılırdı. Bu soruda:

$$V = \frac{R_L V_i}{R + R_L} = \frac{1{,}2\text{ k}\Omega \,(16\text{ V})}{1\text{ k}\Omega + 1{,}2\text{ k}\Omega} = 8{,}73\text{ V}$$

$V = 8{,}73$ V, $V_Z = 10$ V'tan küçük olduğu için zener kapalıdır (açık devre). Bu durumda (ekrandan, 01:05:00):

$$V_L = V = 8{,}73\text{ V}, \qquad V_R = V_i - V_L = 16 - 8{,}73 = 7{,}27\text{ V}$$

$$I_Z = 0\text{ A}, \qquad P_Z = V_Z I_Z = 0\text{ W}$$

Güç $P = V \cdot I$ ile bulunur; zener akımı sıfır olduğu için harcanan güç de sıfırdır.

### 7.3 $R_L = 3$ k$\Omega$ ile

Yük 3 k$\Omega$ olunca toplam direncin dörtte üçü yükün payıdır:

$$V = \frac{3}{3 + 1}\cdot 16 = 12\text{ V}$$

12 V, $V_Z = 10$ V'u aştığı için zener iletimdedir ve yerine 10 V'luk bir kaynak konur (ekrandan, 01:10:00). Gerilimler:

$$V_L = 10\text{ V}, \qquad V_R = 16 - 10 = 6\text{ V}$$

Akımlar:

$$I_L = \frac{10\text{ V}}{3\text{ k}\Omega} \approx 3{,}33\text{ mA}, \qquad I_R = \frac{6\text{ V}}{1\text{ k}\Omega} = 6\text{ mA}$$

Üst düğümde KCL: $I_R = I_Z + I_L$, yani $6 = I_Z + 3{,}33$, buradan $I_Z = 2{,}67$ mA. Zenerin harcadığı güç:

$$P_Z = V_Z I_Z = (10\text{ V})(2{,}67\text{ mA}) = 26{,}7\text{ mW}$$

Zenerin anma gücü 30 mW'tır. 30 mW aşılırsa zener yanar, koruma (paralel çalışma) özelliği kalmaz ve devreden çıkmış olur. 26,7 mW bu sınırın altında olduğu için zener görevini sürdürür.

## 8. Ayarlı Yüklü Zener Regülatörü: Çalışma Aralığı

"Example 2.27"de (ekrandan, 01:15:00 ve 01:20:00) $V_i = 50$ V, $R = 1$ k$\Omega$, $V_Z = 10$ V'luk ve en fazla $I_{ZM} = 32$ mA akım geçirebilen bir zener ile ayarlı bir yük direnci $R_L$ vardır. İstenen: yük gerilimi 10 V'ta tutulacak şekilde $R_L$ ve $I_L$ aralığını bulmak.

### 8.1 Alt sınır: zenerin iletime geçtiği an

A ve B uçları arasındaki gerilim 10 V'un altındayken zener açık devredir ve bütün akım yükten geçer. Zenerin iletime geçtiği sınırda yük gerilimi tam 10 V'tur ama zener henüz akım çekmez ($I_Z = 0$). Bu durumda seri dirençte

$$V_R = V_i - V_Z = 50 - 10 = 40\text{ V}, \qquad I_R = \frac{40\text{ V}}{1\text{ k}\Omega} = 40\text{ mA}$$

vardır ve bu akımın tamamı yükten geçer. Yük üzerinde 10 V olduğuna göre:

$$10\text{ V} = 40\text{ mA}\cdot R_L \;\Rightarrow\; R_{L\min} = 250\ \Omega$$

Kitaptaki formülle aynı sonuç: $R_{L\min} = \dfrac{R V_Z}{V_i - V_Z} = \dfrac{(1\text{ k}\Omega)(10\text{ V})}{50 - 10} = 250\ \Omega$. En büyük yük akımı da bu durumdadır: $I_{L\max} = 40$ mA. Yani yük akımı en büyükken yük direnci en küçüktür.

### 8.2 Üst sınır: zener en fazla akımı çekerken

Zener iletimdeyken toplam 40 mA'in bir kısmını kendi üzerinden geçirir. Zenerin en fazla 32 mA geçirebildiği düşünülürse yüke en az

$$I_{L\min} = I_R - I_{ZM} = 40 - 32 = 8\text{ mA}$$

kalır. Yük üzerinde yine 10 V vardır:

$$10\text{ V} = 8\text{ mA}\cdot R_L \;\Rightarrow\; R_{L\max} = 1{,}25\text{ k}\Omega$$

Sonuç olarak yük geriliminin 10 V'ta tutulduğu aralık:

$$250\ \Omega \le R_L \le 1{,}25\text{ k}\Omega, \qquad 8\text{ mA} \le I_L \le 40\text{ mA}$$

Hoca kapanışta iki durumu tekrar özetledi: zener 10 V'a ulaşmadan önce açık devredir ve en büyük akım yükten geçer; 10 V aşıldığında zener akımı paylaşmaya başlar ve en fazla 32 mA'i alabildiği için yüke en az 8 mA kalır.

## 9. Seri ve Paralel Kırpıcı Ayrımı

Ders sonunda bir öğrenci, slaytlardaki seri ve paralel kırpıcıların nasıl ayırt edileceğini sordu.

**Soru:** Kırpıcı devrelerinde bir kaynak, bir direnç ve bir diyot var ama yerleri farklı; devrenin seri mi paralel mi olduğunu nasıl anlarız? **Cevap:** Ayrım diyotun konumuna göre yapılır. Paralel kırpıcıda diyot, girişe paralel olan koldadır; giriş ucundan sonra devre paralelleşir ve diyot bu paralel kolda bulunur. Seri kırpıcıda diyot girişin hemen devamında, girişe seri olan ana koldadır; paralelleşme diyottan sonra olur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Şekildeki seri diyot devresi için ($E = 10$ V, silisyum diyot, $R = 1$ k$\Omega$) (a) $V_{D_Q}$ ve $I_{D_Q}$'yu, (b) $V_R$'yi bulun.

> **Çözüm:** Derste ideal yaklaşımla $I = 10/1\text{ k}\Omega = 10$ mA, 0,7 V'luk eşik gerilimi hesaba katılınca $V_R = 9{,}3$ V ve $I \approx 9{,}3$ mA bulundu. Kitapta verilen karakteristik eğriden yük hattıyla çözüm derste yapılmadı.

**Soru 2** (ekrandan, 00:15:00): Seri bağlı silisyum ve germanyum diyot, $+12$ V'luk uç ve 5,6 k$\Omega$'luk direnç içeren devre için $V_o$ ve $I_D$'yi bulun.

> **Çözüm:** $V_o = 12 - 0{,}7 - 0{,}3 = 11$ V; $I_D = 11/5{,}6\text{ k}\Omega \approx 1{,}96$ mA.

**Soru 3** (ekrandan, 00:20:00): $E_1 = 10$ V, $R_1 = 4{,}7$ k$\Omega$, silisyum diyot, $R_2 = 2{,}2$ k$\Omega$ ve $E_2 = -5$ V'tan oluşan seri devrede akımı bulun.

> **Çözüm:** $I = (10 + 5 - 0{,}7)/(4{,}7 + 2{,}2)\text{ k}\Omega = 14{,}3/6{,}9 \approx 2{,}07$ mA. (Derste toplam direnç 5,9 k$\Omega$ yazılıp 2,42 mA bulundu; bkz. Bölüm 3.1'deki not.)

**Soru 4** (ekrandan, 00:25:00): $E = 20$ V, iki silisyum diyot, $R_1 = 3{,}3$ k$\Omega$ ve $R_2 = 5{,}6$ k$\Omega$'luk devrede $I_1$, $I_2$ ve $I_{D_2}$ akımlarını bulun.

> **Çözüm:** $I_1 = 0{,}7/3{,}3 \approx 0{,}212$ mA; $I_2 = 18{,}6/5{,}6 \approx 3{,}32$ mA; $I_{D_2} = I_2 - I_1 \approx 3{,}11$ mA.

**Soru 5** (ekrandan, 00:30:00): (a) Tepe değeri 20 V olan sinüs girişli, ideal diyotlu ve 2 k$\Omega$ yüklü devrenin çıkışını çizin ve DC seviyesini bulun. (b) İdeal diyot yerine silisyum diyot koyarak tekrarlayın. (c) $V_m$ 200 V'a çıkarılırsa (a) ve (b)'yi karşılaştırın.

> **Çözüm:** (a) Yalnız negatif yarım dalgalar geçer, $V_{dc} = -0{,}318(20) = -6{,}36$ V. (b) $V_{dc} = -0{,}318(19{,}3) \approx -6{,}14$ V. (c) $-63{,}6$ V ve yaklaşık $-63{,}38$ V; 0,22 V'luk fark büyük girişte oransal olarak önemsizdir.

**Soru 6** (ekrandan, 00:40:00): Tepe değeri 10 V olan sinüs girişli, iki diyotlu ve üç 2 k$\Omega$ dirençli köprü devresinin çıkışını çizin ve DC seviyesini bulun.

> **Çözüm:** Her yarım periyotta çıkış $\tfrac{1}{2}v_i$ olur ve aynı yönde görülür; tepe değer 5 V, $V_{dc} = 0{,}636 \cdot 5 = 3{,}18$ V. Kitaptaki soru diyotların gerekli ters dayanma gerilimini (PIV) de istiyor; bu kısım derste çözülmedi.

**Soru 7** (ekrandan, 00:55:00): Girişi tepe değeri 20 V olan sinüs, girişe seri 5 V'luk kaynak ve diyot, çıkışı $R$ üzerinde olan devrenin çıkış dalga şeklini belirleyin.

> **Çözüm:** $v_i > -5$ V iken diyot iletimdedir ve $v_o = v_i + 5$ V (tepe 25 V); $v_i < -5$ V iken diyot kesimdedir ve $v_o = 0$.

**Soru 8** (ekrandan, 01:00:00): $V_i = 16$ V, $R = 1$ k$\Omega$, $V_Z = 10$ V, $P_{ZM} = 30$ mW'lık zener regülatöründe (a) $R_L = 1{,}2$ k$\Omega$ için $V_L$, $V_R$, $I_Z$ ve $P_Z$'yi bulun; (b) $R_L = 3$ k$\Omega$ ile tekrarlayın.

> **Çözüm:** (a) $V = 8{,}73$ V $< 10$ V, zener kapalı: $V_L = 8{,}73$ V, $V_R = 7{,}27$ V, $I_Z = 0$, $P_Z = 0$. (b) $V = 12$ V $> 10$ V, zener açık: $V_L = 10$ V, $V_R = 6$ V, $I_Z = 6 - 3{,}33 = 2{,}67$ mA, $P_Z = 26{,}7$ mW $< 30$ mW.

**Soru 9** (ekrandan, 01:15:00): $V_i = 50$ V, $R = 1$ k$\Omega$, $V_Z = 10$ V, $I_{ZM} = 32$ mA'lik regülatörde (a) $V_{R_L}$'nin 10 V'ta tutulduğu $R_L$ ve $I_L$ aralığını bulun; (b) zenerin en büyük güç değerini bulun.

> **Çözüm:** (a) Derste çözüldü: $250\ \Omega \le R_L \le 1{,}25$ k$\Omega$, $8 \text{ mA} \le I_L \le 40$ mA.

> **Çözüm (derste verilmedi):** (b) $P_{Z\max} = V_Z I_{ZM} = (10\text{ V})(32\text{ mA}) = 320$ mW (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste diyot konularının tamamı soru çözümüyle pekiştirildi. Önce diyot modelleri hatırlatıldı, sonra seri ve paralel diyot devrelerinde Kirchhoff gerilim ve akım yasalarıyla akım ve gerilimler bulundu; negatif kaynaklı uçların toprağa ters bağlı kaynak olarak çizilmesi ve paralel kollarda gerilim eşitliği kullanıldı. Ardından yarım dalga ve dirençli köprüyle tam dalga doğrultucularda çıkış dalga şekli ve DC seviyesi ($0{,}318 V_m$ ve $0{,}636 V_m$) hesaplandı, eşik geriliminin büyük girişlerde önemsizleştiği gösterildi. Seri kaynaklı bir kırpıcının çıkışı girişten noktalar seçilerek çizildi. Son olarak zener diyotun regülatör olarak çalışması, gerilim bölücüyle durum belirleme, güç sınırı kontrolü ve ayarlı yükte çalışma aralığının bulunması işlendi.

Hoca, transistörlerle ilgili soruların bir sonraki derste çözüleceğini ve öğrencilerin temel transistör sorularına önceden bakabileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
