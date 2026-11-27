# Ders 25 Genişletilmiş Notu: Birleşik Devre Tasarım Örnekleri (MUX ile Gerçekleme, ALU) ve Ardışıl Devrelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı ve birleşik devre tasarım adımları
- 2. Kontrol girişli tam toplayıcı / tam çıkarıcı
- 3. Helikopter kalkış sinyali ve 4x1 MUX ile gerçekleme
- 4. Ağırlıklı oylama sistemi
- 5. İki çıkışlı yer değiştirme devresi
- 6. İki MUX ve bir VEYA kapısından oluşan devrenin çözümlemesi
- 7. Merdiven aydınlatması
- 8. BCD için tek eşlik biti üreteci
- 9. Basit bir ALU tasarımı
- 10. Ardışıl devrelere giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı ve birleşik devre tasarım adımları

Bu ders iki bölümden oluşur. İlk bölümde birleşik (kombinezonsal) devreler ve bu devrelerde kullanılan yardımcı tümleşik devreler (MUX, DEMUX, kod çözücü, kodlayıcı) üzerine örnekler çözülür. Hoca soruları kendisi baştan çözmek yerine öğrencilere süre verip çözdürür ve gerekli yerlerde yönlendirir. Bunun nedeni olarak, bir hafta sonra MUX'un işlevinin unutulduğunu, "MUX neydi" sorusuna kod çözücünün anlatıldığını gözlemlediğini söyler; örnekler bu yüzden bir tekrar niteliğindedir. İkinci bölümde ardışıl (sequential) devrelere giriş yapılır.

Hoca birleşik devre tasarımında "zor soru" olmadığını, asıl işin ayrıntıları ve koşulları adım adım çözümlemek olduğunu vurgular. Tasarımın adımları şunlardır:

- Problemdeki girişleri ve çıkışları belirlemek.
- Bu değişkenlerle doğruluk tablosunu kurmak.
- Tablodaki 1'lerle Karnaugh diyagramını oluşturup sadeleştirmek.
- Sadeleşmiş ifadeyle devreyi kurmak; soru belirli bir kapı türü (örneğin yalnız TVE) istiyorsa ifadeyi o biçime dönüştürmek.

> **Hocanın vurgusu:** Kombinezonsal devre sorularında zorluk yoktur; detay ve koşul vardır, bunlar adım adım çözümlenmelidir.

## 2. Kontrol girişli tam toplayıcı / tam çıkarıcı

### 2.1 Problem

Dört girişli ($a, b, e, k$) ve iki çıkışlı ($c, s$) bir devre, $k$ girişi 0 ise tam toplayıcı, 1 ise tam çıkarıcı olarak çalışır. İstenenler: (a) doğruluk tablosu, (b) çıkış fonksiyonlarının Karnaugh diyagramlarıyla bulunması, (c) devrenin yalnız TVE (NAND) kapılarıyla tasarlanıp lojik şemasının çizilmesi (ekrandan, 00:15:00).

Hoca bu devrenin blok diyagram olarak (bir XOR'lu kontrol ucu ile toplayıcının çıkarıcıya dönüştürülmesi) daha önce anlatıldığını hatırlatır; burada aynı problem doğruluk tablosu ve Karnaugh ile çözülür. Bir öğrencinin "bu devre toplayıcı-çıkarıcı devrenin üç girişli hâli değil mi" sorusuna hoca "evet" diye cevap verir.

### 2.2 Doğruluk tablosu

$s$ sonuç (toplam ya da fark), $c$ elde ya da borç bitidir. Hoca, tam toplayıcıdaki elde biti ile tam çıkarıcıdaki borç bitinin aynı çıkışa atanması gerektiğini vurgular: MSB/LSB yerleşimi iki modda farklı seçilirse tablo tutarsız olur.

Tablo (ekrandan, 00:35:00):

| $k$ | $a$ | $b$ | $e$ | $s$ | $c$ |
|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 1 | 0 | 1 | 0 |
| 0 | 0 | 1 | 1 | 0 | 1 |
| 0 | 1 | 0 | 0 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 | 1 |
| 0 | 1 | 1 | 0 | 0 | 1 |
| 0 | 1 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 1 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 | 1 |

İlk sekiz satır tam toplayıcının, son sekiz satır tam çıkarıcının ($a - b - e$) tablosudur.

**Soru:** Tam çıkarıcıda $a = 0, b = 1, e = 1$ olduğunda sonuç ve borç ne olur? **Cevap:** Sıfırdan bir çıkmadığı için borç alınır, borç biti 1 olur. Borç alınan değerden ikinci 1 de çıkarılınca fark 0 kalır. Yani fark 0, borç 1'dir. Buna karşılık $0 - 1 - 0$ durumunda borç alınır ama ikinci bir çıkarma olmadığından fark 1 kalır: fark 1, borç 1.

Bir öğrenci $0 - 1 - 1$ satırını "$-2$ çıkıyor" diye yorumladı (borç bitinin ağırlığı $-2$, fark 0); hoca bu bakışın da doğru olduğunu söyledi. Aynı şekilde $1 - 1 - 1 = -1$ satırında fark 1, borç 1'dir: $-2 + 1 = -1$.

### 2.3 Karnaugh diyagramları

Diyagramlarda satırlar $ka$, sütunlar $be$ değişkenleridir (ekrandan, 00:35:00).

$s$ için Karnaugh diyagramında 1'ler komşu değildir; ifade dört mintermden oluşur ve $k$'ya bağlı değildir:

$$s = \bar a b \bar e + \bar a \bar b e + a \bar b \bar e + a b e = a \oplus b \oplus e$$

$c$ için diyagram:

| $ka \backslash be$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 0 | 0 | 1 | 0 |
| 01 | 0 | 1 | 1 | 1 |
| 11 | 0 | 0 | 1 | 0 |
| 10 | 0 | 1 | 1 | 1 |

Gruplamada $be = 11$ sütunundaki dörtlü ($be$) ile dört ikili seçilir (ekrandan, 00:40:00):

$$c = be + \bar k a e + \bar k a b + k \bar a b + k \bar a e$$

İfade python ile 16 satırın tamamında doğrulandı.

> **Ek bilgi (derste anlatılmadı):** $c$ ifadesi $c = be + (k \oplus a)(b + e)$ biçiminde de yazılabilir. $k = 0$ iken bu tam toplayıcının eldesi ($be + a(b+e)$), $k = 1$ iken tam çıkarıcının borcudur ($be + \bar a (b+e)$). Bu, blok diyagramdaki XOR'lu kontrol ucunun neden işe yaradığını gösterir.

### 2.4 Yalnız TVE (NAND) kapılarıyla gerçekleme

Hoca, bir fonksiyonun değilinin değilinin kendisine eşit olduğunu hatırlatır: $\bar{\bar F} = F$. $s$ ifadesine iki kez değil uygulanır, içteki değil De Morgan kuralıyla dağıtılır:

$$s = \overline{\overline{\bar a b \bar e + \bar a \bar b e + a \bar b \bar e + a b e}} = \overline{\left(\overline{\bar a b \bar e}\right) \cdot \left(\overline{\bar a \bar b e}\right) \cdot \left(\overline{a \bar b \bar e}\right) \cdot \left(\overline{a b e}\right)}$$

Böylece her çarpım teriminin değili bir NAND kapısı, bunları birleştiren dış değilli çarpım da bir NAND kapısı olur (ekrandan, 00:40:00). Girişlerdeki değil işlemleri de NAND ile yapılır: bir NAND kapısının iki girişine aynı $x$ verilirse $x = 0$ iken çıkış 1, $x = 1$ iken çıkış 0 olur, yani çıkış $\bar x$'tir. Bu sayede tüm devre yalnız NAND kapılarıyla kurulur. $c$ için de aynı işlem yapılır: aradaki artılar çarpıma döner ve beş çarpım teriminin her biri bir NAND, birleştiren kapı da beş girişli bir NAND olur. Hoca lojik şemayı ayrıntılı çizmedi.

## 3. Helikopter kalkış sinyali ve 4x1 MUX ile gerçekleme

### 3.1 Problem

Bir havaalanından şehir merkezine 20 dakikada bir helikopter seferi vardır. Helikopterdeki bir sayıcı, binen yolcuları doğal ikili kodda sayar; helikopterler 7 kişiliktir. Kalkış için: kalkış zamanı henüz gelmediyse helikopterin dolmuş olması, kalkış zamanı geldiyse içinde en az iki yolcu bulunması gerekir. Kalkış zamanı gelince zaman saatinin $T$ çıkışı lojik 1, aksi durumda lojik 0'dır. Pilota kalkışa hazır işareti verecek lojik devre tasarlanacaktır (ekrandan, 00:45:00).

Hoca sayıcıyı şöyle açıklar: bir kişi binince sayı $001$, ikinci kişi binince $010$, üçüncüde $011$ olur. Bir öğrenci devrenin dört girişli ($T, A_2, A_1, A_0$) ve tek çıkışlı olduğunu doğruladı.

### 3.2 Doğruluk tablosu ve sadeleştirme

- $T = 0$ iken çıkış yalnız sayı 7 ($111$) iken 1'dir.
- $T = 1$ iken çıkış, sayı 2 ya da daha fazlaysa 1'dir ($000$ ve $001$ için 0).

Bir öğrenci önce $T = 1$, sayı 2 satırını 0 yazmış, "en az iki yolcu" koşulu hatırlatılınca düzeltmiştir. Karnaugh diyagramında satırlar $TA_2$, sütunlar $A_1A_0$'dır. Seçilen gruplar: $TA_2$ dörtlüsü, $TA_1$ dörtlüsü ve $A_2A_1A_0$ ikilisi (ekrandan, 00:50:00):

$$F = T A_2 + T A_1 + A_2 A_1 A_0$$

### 3.3 4x1 MUX ile gerçekleme

Hoca soruyu genişletir: $T$ ve $A_2$ seçme girişleri ($T$ yüksek anlamlı $S_1$, $A_2$ düşük anlamlı $S_0$) olan bir 4x1 MUX ile aynı tablo nasıl sağlanır? Önce MUX'un tanımını hatırlatır: seçme girişleriyle seçilen veri girişini çıkışa aktaran elemandır; $00$'da $I_0$, $01$'de $I_1$, $10$'da $I_2$, $11$'de $I_3$ çıkışa aktarılır.

Doğruluk tablosu seçme girişlerinin değerine göre dört gruba ayrılır ve her grup için $A_1, A_0$'a bağlı çıkışa bakılır (ekrandan, 00:55:00):

| $T A_2$ | Grup içindeki çıkış ($A_1A_0 = 00, 01, 10, 11$) | MUX girişi |
|---|---|---|
| 00 | 0, 0, 0, 0 | $I_0 = 0$ (GND) |
| 01 | 0, 0, 0, 1 | $I_1 = A_1 A_0$ (VE kapısı) |
| 10 | 0, 0, 1, 1 | $I_2 = A_1$ |
| 11 | 1, 1, 1, 1 | $I_3 = 1$ (+5 V) |

- Grup tamamen 0 ise giriş toprağa (GND) bağlanır.
- Grup tamamen 1 ise girişe lojik 1 (+5 V) verilir.
- $10$ grubunda çıkış $A_1$'in aynısıdır; $A_1$ doğrudan bağlanır.
- $01$ grubunda belirgin bir tekrar yoktur; çıkış yalnız $A_1 A_0 = 11$ iken 1 olduğu için bu VE kapısının doğruluk tablosudur ve $I_1$'e VE kapısının çıkışı bağlanır.

Hoca, MUX'un iç yapısındaki kapı bağlantılarını hazır getirdiği için bu yolun Karnaugh'a gerek kalmadan, doğrudan doğruluk tablosundan çok daha kolay bir çözüm ürettiğini belirtir.

> **Hocanın vurgusu:** MUX ile tasarımda her seçme kombinasyonu doğruluk tablosunun bir satır grubuna karşılık gelir; giriş, o gruptaki çıkışı kalan değişkenlerle üreten sabit ya da küçük devredir.

## 4. Ağırlıklı oylama sistemi

### 4.1 Problem

Bir başkan, bir başkan yardımcısı ve iki üyeden oluşan bir komisyonun kararlarını gösteren oylama sistemi tasarlanacaktır. Başkanın oyu 3, başkan yardımcısının oyu 2, üyelerin oyu 1 ağırlığındadır. EVET oylarının ağırlıkları fazlaysa "EVET", HAYIR oylarının ağırlıkları fazlaysa "HAYIR" kararı alınır; eşitlik hâlinde başkan yardımcısı ve üyelerin çoğunluk oyuna göre karar verilir. Herkes oy kullanmak zorundadır ve EVET oyu lojik 1'dir. Fonksiyonun doğruluk tablosu çıkarılıp Karnaugh ile sadeleştirilecek ve devre çizilecektir (ekrandan, 01:00:00).

**Soru:** Burada beraberlik hiç oluşmuyor, değil mi? **Cevap:** Ağırlıkların toplamı $3 + 2 + 1 + 1 = 7$ tektir; herkes oy kullandığı için EVET ve HAYIR ağırlıkları hiçbir zaman eşit olamaz. Hoca bunu doğruladı.

### 4.2 Doğruluk tablosu

Değişkenler: başkan $B$, yardımcı $Y$, üyeler $a_1, a_0$. Çıkış, EVET ağırlığı 4 ya da daha fazlaysa 1'dir (ekrandan, 01:05:00):

| $BY$ | $a_1a_0 = 00$ | $01$ | $10$ | $11$ |
|---|---|---|---|---|
| 00 | 0 | 0 | 0 | 0 |
| 01 | 0 | 0 | 0 | 1 |
| 10 | 0 | 1 | 1 | 1 |
| 11 | 1 | 1 | 1 | 1 |

Tablodan sadeleşmiş ifade $f = BY + B a_1 + B a_0 + Y a_1 a_0$ olur (python ile doğrulandı; ara adım eklendi, derste ifade sözlü okunmadı).

### 4.3 4x1 MUX ile gerçekleme

Hoca bu soruyu da $B, Y$ seçme girişli 4x1 MUX ile kurdurur. Bir öğrencinin cevabı:

- $I_0$ toprağa bağlanır (0).
- $I_1 = a_1 a_0$ (VE).
- $I_2 = a_1 + a_0$ (VEYA).
- $I_3$'e +5 V verilir (1).

Hoca cevabın doğru olduğunu ve sorunun helikopter sorusuna çok benzediğini söyledi.

## 5. İki çıkışlı yer değiştirme devresi

Blok çizimi verilen devrenin girişleri $x_0, x_1$ ve kontrol girişi $w$, çıkışları $z_0, z_1$'dir. $w = 0$ ise $z_0 = x_0$, $z_1 = x_1$; $w = 1$ ise $z_0 = x_1$, $z_1 = x_0$ olur. İstenenler: (a) çıkış fonksiyonlarının en yalın lojik ifadeleri, (b) TVEYA (NOR) kapılarıyla gerçekleme, (c) MUX ile gerçekleme (ekrandan, 01:10:00).

Derste yalnız (c) şıkkı tartışıldı. Önce hangi MUX'un kullanılacağı soruldu: bir veri girişi çifti ve bir seçme girişi ($w$) olduğu için 2x1 MUX uygundur. Bir öğrenci, iki çıkış olduğu için iki tane 2x1 MUX gerektiğini söyledi:

- $z_0$ için MUX: $I_0 = x_0$, $I_1 = x_1$, seçme girişi $w$.
- $z_1$ için MUX: $I_0 = x_1$, $I_1 = x_0$, seçme girişi $w$.

Hoca önce tek çıkış varmış gibi düşündüğünü, iki çıkış olduğu için iki MUX'un doğru olduğunu belirtti. (a) ve (b) şıklarının önceki örneklerle aynı yolla (doğruluk tablosu, Karnaugh, devre) çözüleceğini söyledi; bu şıkların çözümü aşağıdaki Örnek Sorular bölümündedir.

> **Hocanın vurgusu:** Bu soruda önemli olan, iki çıkış olduğu için iki MUX kullanılmasıdır; her MUX tek çıkış verir.

## 6. İki MUX ve bir VEYA kapısından oluşan devrenin çözümlemesi

### 6.1 Problem

İki seçici (4x1 MUX) ve bir VEYA kapısından oluşan devre verilmiştir (ekrandan, 01:15:00):

- Birinci MUX: veri girişleri sırasıyla $a, b, 1, 0$; seçme girişleri $c, d$.
- İkinci MUX: veri girişleri sırasıyla $\bar c, 1, 0, d$; seçme girişleri $a, b$.
- İki MUX çıkışı bir VEYA kapısına girer; kapının çıkışı $Z$'dir.

İstenenler: (a) devrenin lojik fonksiyonu, (b) doğruluk tablosu, (c) $a, b, c$ seçme girişleriyle 8x1 MUX ile gerçekleme.

### 6.2 Doğruluk tablosu

Her $abcd$ kombinasyonu devreye yerleştirilir. Örneğin $abcd = 0000$ için ikinci MUX'ta $ab = 00$ olduğundan $\bar c = 1$ seçilir, VEYA kapısı nedeniyle $Z = 1$ olur. Hoca, $ab = 00$ ve $c = 0$ olan satırlarda $\bar c = 1$ olduğu için $Z$'nin doğrudan 1 olduğunu, bu tür küçük kısa yollarla tablonun hızlı doldurulabileceğini gösterdi.

Bir öğrenci yalnız sıfırları söyledi, çünkü sıfırlar azdır (ekrandan, 01:25:00): $Z = 0$ olan satırlar $0011$, $1001$ ve $1011$'dir; diğer 13 satırda $Z = 1$'dir. Tablo python ile devrenin bağlantılarından yeniden hesaplanarak doğrulandı.

### 6.3 Fonksiyon (maxterm biçimi)

Hoca, sıfırlar az olduğu için mintermler yerine maxtermlerin (toplamların çarpımı) yazılabileceğini hatırlatır. Her sıfır satırı için bir toplam terimi yazılır; değişken 0 ise kendisi, 1 ise değili alınır:

$$Z = (a + b + \bar c + \bar d)(\bar a + b + c + \bar d)(\bar a + b + \bar c + \bar d)$$

(ekrandan, 01:25:00)

**Soru:** Bu doğruluk tablosunu yalnız çıkıştaki VEYA kapısına bakarak mı tahmin ettik? **Cevap:** Tahmin değil; her kombinasyon devreye yerleştirilip iki MUX'un çıkışı bulundu ve VEYA'landı. İki MUX'tan biri 1 verirse $Z = 1$'dir.

Bir öğrenci her MUX'un çıkışı için tabloya ayrı sütun açtığını, sonra bunları VEYA'ladığını söyledi. Hoca bunun da doğru olduğunu, birbirine bağlı birden çok MUX içeren karmaşık devrelerde adım adım ilerlemenin hata olasılığını azalttığını belirtti; burada VEYA kapısı basit olduğu için doğrudan çözüm de kolaydır.

> **Ek bilgi (derste anlatılmadı):** Üç maxterm Karnaugh ile birleştirilirse $\bar Z = \bar b d (a + c)$, yani $Z = b + \bar d + \bar a \bar c$ elde edilir. Bu ifade python ile 16 satırda doğrulandı.

### 6.4 8x1 MUX ile gerçekleme

$a, b, c$ seçme girişleri olunca her seçme kombinasyonu için çıkış $d$'ye bağlı kalır (ekrandan, 01:25:00):

| $abc$ | $d = 0$ | $d = 1$ | MUX girişi |
|---|---|---|---|
| 000 | 1 | 1 | $I_0 = 1$ |
| 001 | 1 | 0 | $I_1 = \bar d$ |
| 010 | 1 | 1 | $I_2 = 1$ |
| 011 | 1 | 1 | $I_3 = 1$ |
| 100 | 1 | 0 | $I_4 = \bar d$ |
| 101 | 1 | 0 | $I_5 = \bar d$ |
| 110 | 1 | 1 | $I_6 = 1$ |
| 111 | 1 | 1 | $I_7 = 1$ |

Hoca, iki çıkış değeri de 1 ise girişe 1, $d$'nin tersi ise $\bar d$ bağlandığını özetledi.

## 7. Merdiven aydınlatması

Üç katlı bir apartmanda her katta bir anahtar ($x_1, x_2, x_3$) vardır; bütün lambalar ($L$) birlikte yanar ya da söner. Anahtarın kapalı durumu 1, açık durumu 0; lambanın yanması 1, sönmesi 0'dır. Çalışma düzeni (ekrandan, 01:30:00):

- Üç anahtar da devreyi açık bırakan konumdayken lamba yanmaz.
- Anahtarlardan herhangi biri devreyi kapatırsa lamba yanar.
- İki anahtar birden devreyi kapatırsa lamba yanmaz.
- Üç anahtar da kapalıysa lamba yanar.

İstenenler: (a) doğruluk tablosu, (b) çarpımlar toplamı kanonik biçimi, (c) $x_1, x_2$ seçme girişli MUX ile gerçekleme.

Doğruluk tablosunda lamba, kapalı anahtar sayısı tek iken yanar; yani $L = x_1 \oplus x_2 \oplus x_3$'tür. Hoca ilk iki şıkkı geçip doğrudan MUX şıkkına baktı. $x_1, x_2$ seçme girişli 4x1 MUX'un girişleri bir öğrencinin cevabıyla şöyledir:

| $x_1x_2$ | Çıkış | MUX girişi |
|---|---|---|
| 00 | $x_3$ | $I_0 = x_3$ |
| 01 | $\bar x_3$ | $I_1 = \bar x_3$ |
| 10 | $\bar x_3$ | $I_2 = \bar x_3$ |
| 11 | $x_3$ | $I_3 = x_3$ |

Bu bağlantılar python ile doğrulandı.

## 8. BCD için tek eşlik biti üreteci

### 8.1 Problem

BCD kodunda (0-9 arası) verilen bir sayı uzaktaki başka bir sisteme aktarılacak ve hata olmaması için bilgiyle birlikte bir eşlik biti gönderilecektir. BCD kodunda 1'lerin sayısını tek yapan eşlik (parity) biti üreteci, $x_1$ ve $x_2$ seçme girişli bir seçici (MUX) ile gerçeklenecektir. Yol gösterme: dört girişli, tek çıkışlı tablo çıkışta 1'lerin sayısı tek olacak biçimde kurulur, çarpımlar toplamı kanonik biçimde yazılır, terimler $x_1x_2$'nin değerlerine göre ayrılarak MUX girişleri belirlenir (ekrandan, 01:35:00).

Hoca bu sorunun, MUX'lar işlenmeden önce normal lojik devre tasarımıyla sorulmuş bir sorunun MUX'lu biçimi olduğunu belirtir.

### 8.2 Eşlik biti

Eşlik biti, gönderilen bitlerdeki 1'lerin sayısına göre 0 ya da 1 olan ek bittir. Tek eşlikte (odd parity) eşlik biti, verideki 1'lerle birlikte toplam 1 sayısını tek yapacak biçimde seçilir. Örneğin $1010$'da iki tane 1 vardır (çift), eşlik biti 1 olur; $1101$'de üç tane 1 vardır (tek), eşlik biti 0 olur (ekrandan, 01:40:00).

Bir öğrenci geçen yıla ait bir doğruluk tablosunu metin olarak yapıştırdı; hoca tablonun sol tarafının yanlış olduğunu fark etti ve tablo düzeltildi.

### 8.3 Farketmez durumlar

Hoca sorunun bu açıdan eksik olduğunu belirtir: BCD dışındaki kombinasyonlar ($1010$-$1111$) için eşlik bitinin ne üreteceği söylenmemiştir. Bu yüzden bu satırlar farketmez (don't care, X) alınabilir; normalde soruda belirtilmesi gerekir.

BCD satırları için eşlik biti: $0000 \to 1$, $0001 \to 0$, $0010 \to 0$, $0011 \to 1$, $0100 \to 0$, $0101 \to 1$, $0110 \to 1$, $0111 \to 0$, $1000 \to 0$, $1001 \to 1$.

### 8.4 MUX ile gerçekleme

$x_1, x_2$ seçme girişli 4x1 MUX kullanılır; her grup içinde çıkış $x_3, x_4$'e bağlıdır:

- $x_1x_2 = 00$: çıkış $1, 0, 0, 1$; iki bit aynıyken 1, farklıyken 0'dır. $I_0 = \overline{x_3 \oplus x_4}$ (XNOR).
- $x_1x_2 = 01$: çıkış $0, 1, 1, 0$. $I_1 = x_3 \oplus x_4$ (XOR).
- $x_1x_2 = 10$: BCD satırları $0, 1$; farketmezlerle birlikte $I_2 = x_3 \oplus x_4$ alınabilir.
- $x_1x_2 = 11$: tamamı farketmez; hoca en üstteki ile aynı bağlantıyı ($I_3 = \overline{x_3 \oplus x_4}$) kullandı.

Sonuçta bir XOR, bir XNOR kapısı ve bir 4x1 MUX ile eşlik biti üreteci kurulur. Bağlantılar BCD satırlarının tamamında python ile doğrulandı.

> **Ders sonrası not:** Hoca $I_0$ için "XOR denmiş, çünkü aynıysa bir, farklıysa sıfır veren XOR kapısıydı" dedi; "aynıysa 1, farklıysa 0" veren kapı XNOR'dur. Derste kurulan devrede de iki kapı türü (XOR ve XNOR) kullanıldı.

<!-- BELİRSİZ: MUX çizimi 01:41 civarında ekrandaydı ama alınan karelerde görünmüyor; I2 ve I3 bağlantıları altyazıdaki "bu da aynısı", "en üsttekinin de aynısı" ifadelerinden kuruldu. -->

## 9. Basit bir ALU tasarımı

### 9.1 ALU nedir

ALU (aritmetik lojik birim), işlemcinin matematiksel ve mantıksal işlemlerin yapıldığı birimidir. Hoca işlemcinin iç yapısını kontrol birimi, ALU ve küçük bir ara bellek (tampon) olarak özetler. Aritmetik kısımda toplama, çıkarma ve bazı tasarımlarda çarpma ve bölme; lojik kısımda bit kaydırma (shift), döndürme (rotate) gibi işlemler bulunur.

### 9.2 Problem

İki 4 bitlik veri, bir elde girişi ve bu veriler üzerinde 4 işlemden birini yapan bir ALU tasarlanacaktır; 4 bitlik sonuç çıkışı ve bir elde çıkışı vardır. Giriş ve çıkışlar (ekrandan, 01:45:00):

- Veri girişleri: $A (a_3, a_2, a_1, a_0)$ ve $B (b_3, b_2, b_1, b_0)$.
- Elde girişi ve çıkışı: $E_g$ ve $E_{\text{ç}}$.
- Sonuç çıkışı: $F (f_3, f_2, f_1, f_0)$.
- İşlem kodu: $k_1, k_2$.

İşlem listesi:

| İşlem kodu | İşlem | Açıklama |
|---|---|---|
| 00 | $F = A + B$ | A ve B toplanır. |
| 01 | $F = A - B$ | A'dan B çıkarılır. |
| 10 | $F = \bar B$ | B'nin tüm bitleri tümlenir. |
| 11 | $F = A$, 1 bit sağa öteleme | Örneğin $0110 \to 0011$. |

> **Ders sonrası not:** Slayttaki tabloda dört işlemin kodu da $00$ yazılmıştı; hoca bunun hatalı olduğunu söyleyip kodları $00, 01, 10, 11$ olarak düzeltti (ekrandan, 01:50:00).

### 9.3 İşlem kodu ve tasarım fikri

Hoca, işlemcide komutun önce getirildiğini (fetch), sonra çözüldüğünü (decode) ve yapılacak işlemin bir tablodan seçildiğini anlatır. Bu işlemi belirleyen koda işlem kodu (opcode) denir. Buradaki ALU'da dört işlem kodu vardır ve seçim yapılacağı için tasarımın merkezinde bir MUX bulunur.

Tasarım (ekrandan, 01:50:00):

- 4x1 MUX'un seçme girişlerine işlem kodu bağlanır; çıkışı $F$'dir.
- $I_0$: tam toplayıcı bloğunun (FA) sonucu. $A$ ve $B$ dörder bit olarak girer, elde girişi $E_g$'dir.
- $I_1$: tam çıkarıcı bloğunun (FS) sonucu. Aynı $A$, $B$ ve $E_g$ girer. İki bloğun elde/borç çıkışları $E_{\text{ç}}$'ye bağlanır; hoca bunları bir VEYA ile birleştirebileceğini söyledi.
- $I_2$: $B$'nin her biti için bir değil kapısı. Bir öğrenci önce kapının girişleri birleştirilmiş VE ya da VEYA olabileceğini söyledi; daha sonra başka bir öğrenci bunun NAND ya da NOR olması gerektiğini belirtti ve hoca "doğrudur" diye düzeltti.
- $I_3$: sağa öteleme. Bunun için kapı gerekmez, yalnız kablolama değişir: normalde $A$'nın her biti kendi sırasındaki MUX'a bağlanırken, ötelemede her bit bir alt sıradaki MUX'a bağlanır. En anlamlı bitin MUX'una elde girişi bağlanır, en düşük anlamlı bit de elde çıkışına gider.

Sonuç 4 bit olduğu için aslında her sonuç biti için bir tane olmak üzere dört adet 4x1 MUX gerekir. Hoca eski işlemcilerde bu yaklaşımın kullanıldığını anlatır: tanımlı işlem kodlarına ait bütün işlemler paralel çalışır ve işlem kodu, sonuçlardan hangisinin çıkışa yansıtılacağını seçer. Günümüz işlemcileri daha farklı çalışır.

> **Ders sonrası not:** Toplayıcı ve çıkarıcının elde/borç çıkışlarının doğrudan VEYA'lanması, işlem kodundan bağımsız olarak her iki bloğun çıkışını birleştirir. Büyük olasılıkla daha doğru tasarım, $E_{\text{ç}}$'nin de işlem koduyla seçilmesidir (örneğin ayrı bir MUX ile).

## 10. Ardışıl devrelere giriş

### 10.1 Ardışıl devrenin tanımı

Ardışıl (sequential) devrelerin birleşik devrelerden farkı bellek (storage) elemanı içermeleridir. Hoca bu belleğin RAM ya da disk gibi bir depolama birimi olarak düşünülmemesi gerektiğini, buradaki elemanların tutucular (latch) ve flip-floplar olduğunu vurgular.

Slayttaki yapı (ekrandan, 01:55:00):

- Bir ardışıl devre bellek elemanları (tutucu ya da flip-flop) ve birleşik lojik içerir.
- Birleşik lojik çok çıkışlı bir anahtarlama fonksiyonunu gerçekler.
- Girişler dış dünyadan gelen, çıkışlar dış dünyaya giden sinyallerdir.
- Diğer girişler, yani durum (state, present state), bellek elemanlarından gelen sinyallerdir.
- Kalan çıkışlar, yani bir sonraki durum (next state), bellek elemanlarının girişleridir.

Birleşik devrelerde $t$ anındaki çıkış yalnız $t$ anındaki girişlerden üretilir; "bir önceki giriş" ya da "$t+1$" gibi bir kavram yoktur. Örneğin bir düğmeye basılınca ışık yanar, basılmazsa yanmaz. Ardışıl devrelerde ise önceki durum bilinmeden sonraki durum belirlenemez. Hoca örnek olarak sensörle insan sayan bir devreyi verir: bir sonraki sayının bir artması için kaçıncı kişinin girdiğinin bilinmesi gerekir. Benzer şekilde 1'den 7'ye kadar sayıp 7'ye ulaşınca bir LED yakan sayıcıda da her adımda önceki değerin saklanması gerekir.

### 10.2 Mealy ve Moore makineleri

Slayttaki tanımlar (ekrandan, 02:00:00):

- Mealy makinesi: $Z(t) = f(d(t), x(t))$, $d(t+1) = f(d(t), x(t))$.
- Moore makinesi: $Z(t) = f(d(t))$, $d(t+1) = f(d(t), x(t))$.

Burada $x(t)$ giriş, $d(t)$ o anki durum, $d(t+1)$ bir sonraki durum, $Z(t)$ çıkıştır. İki makinede de bir sonraki durum o anki durum ile o anki girişe bağlıdır. Fark yalnız çıkıştadır: Mealy makinesinde çıkış durum ve girişe, Moore makinesinde yalnız duruma bağlıdır. Slayttaki blok şemalarda her iki makinede birleşik devre (KD) ve durum belleği ($d$) bulunur; Moore makinesinde çıkışı üreten birleşik devre girişi görmez.

> **Hocanın vurgusu:** Mealy ve Moore arasındaki tek fark çıkışın nasıl belirlendiğidir.

> **Ders sonrası not:** Hoca bir yerde "Mealy makinesinde çıkış sadece duruma bağlı" dedi, hemen ardından düzeltti. Doğrusu: Mealy'de çıkış durum ve girişe, Moore'da yalnız duruma bağlıdır.

### 10.3 Senkron ve asenkron ardışıl devreler

Ardışıl devrelerde $t$ ve $t+1$ gibi adımlardan söz edildiği için bir adımdan diğerine geçişi tetikleyen bir sinyal gerekir. Devreler ortak bir senkronizasyon sinyaline, yani saat darbesine (clock pulse) bağlıysa senkron ardışıl devrelerdir; örneğin entegreye her 5 milisaniyede bir saat darbesi gönderilmesi. Asenkron devrelerde ortak bir saat yoktur; durum değişimi dışarıdan gelen bilgiye bağlı olarak ya da düzensiz aralıklarla gelen sinyallerle olur.

Hoca senkron devreye örnek olarak RAM'i verir: RAM'in bilgiyi tutabilmesi için anakart üzerinden saat darbesi gibi düzenli olarak tazelenmesi gerekir. Asenkron örnek olarak bilgisayara USB takıldığında ya da çıkarıldığında çalan uyarı sesini verir: bu ses periyodik bir saatle değil, kullanıcının yaptığı bir işlemin oluşturduğu kesmeyle (interrupt) çalar.

Zamanlama diyagramı üzerinde hoca, girişteki değeri çıkışa aktaran bir devreyi anlatır. Senkron devrede çıkış ancak saat darbesinin yükselen kenarında değişir: giriş 0'a düşse bile çıkış bir sonraki yükselen kenara kadar 1 kalır, o kenarda 0'a düşer. Asenkron devrede çıkış girişi saate bağlı olmadan izler, ancak gecikme her değişimde farklı olabilir.

> **Ek bilgi (derste anlatılmadı):** RAM'lerin tazelenmesi (refresh) dinamik RAM'e (DRAM) özgüdür; kondansatörde tutulan yük zamanla azaldığından periyodik olarak yenilenir. Statik RAM'de (SRAM) böyle bir tazeleme gerekmez.

## Örnek Sorular

### Soru 1 (ekrandan, 00:15:00)

Aşağıdaki şekilde 4 giriş ($a, b, e, k$) ve 2 çıkışlı ($c, s$) devre, $k$ simgeli girişi 0 ise tam toplayıcı olarak, 1 ise tam çıkarıcı olarak çalışmaktadır. Bu devreye ilişkin fonksiyonun: (a) doğruluk tablosunu oluşturunuz; (b) çıkış fonksiyonlarını Karnaugh diyagramları yöntemiyle bulunuz; (c) devreyi sadece TVE kapıları kullanarak tasarlayınız ve lojik şemayı çiziniz.

> **Çözüm (derste verildi):** Doğruluk tablosu Bölüm 2.2'dedir. $s = \bar a b \bar e + \bar a \bar b e + a \bar b \bar e + abe = a \oplus b \oplus e$; $c = be + \bar k a e + \bar k a b + k \bar a b + k \bar a e$. TVE ile: her çarpım terimi bir NAND, terimleri birleştiren son kapı da bir NAND; giriş değilleri girişleri birleştirilmiş NAND ile.

### Soru 2 (ekrandan, 00:45:00)

Bir havaalanından şehir merkezine 20 dakikada bir helikopter seferi düzenlenmektedir. Helikopterlerde bulunan bir sayıcı doğal ikili kodda helikoptere binen yolcuları saymaktadır. Helikopterler 7 kişiliktir. Helikopterlerin kalkması için: kalkış zamanı henüz gelmediyse helikopterin dolmuş olması, kalkış zamanı geldiyse içinde en az iki yolcunun bulunması gereklidir. Kalkış zamanı geldiğinde helikopterdeki zaman saatinin $T$ çıkışı lojik 1 olmakta, aksi durumda $T$ lojik 0 olmaktadır. Yukarıda verilen bilgiler uyarınca pilota kalkışa hazır işareti verecek bir lojik devreyi tasarlayınız.

Derste eklenen şık (derste sözlü, 00:50:40): Devreyi $T$ ve $A_2$ seçme girişli bir 4x1 MUX ile gerçekleyiniz.

> **Çözüm (derste verildi):** $F = TA_2 + TA_1 + A_2A_1A_0$. MUX ile: $I_0 = 0$, $I_1 = A_1A_0$, $I_2 = A_1$, $I_3 = 1$.

### Soru 3 (ekrandan, 01:00:00)

Bir başkan, bir başkan yardımcısı ve iki üyeden oluşan bir komisyonun alacağı kararları gösteren bir oylama sistemi yapılacaktır. Başkanın oyu 3, başkan yardımcısının oyu 2, üyelerin oyu ise 1 ağırlığındadır. EVET oylarının ağırlık katsayıları fazla ise "EVET", HAYIR oylarının ağırlık katsayıları yüksek ise "HAYIR", eşitlik hâlinde başkan yardımcısı ve üyelerin verdiği çoğunluk oylarına göre karar alınacaktır. Bütün üyeler oy kullanmak zorundadır. EVET oyu lojik 1'dir. Bu oylama sistemine ait lojik fonksiyonun doğruluk tablosunu çıkararak fonksiyonu Karnaugh diyagramı ile sadeleştirerek tasarlanan devreyi çiziniz. Derste eklenen şık (derste sözlü, 01:06:24): 4x1 MUX ile gerçekleyiniz.

> **Çözüm (derste verildi):** Doğruluk tablosu Bölüm 4.2'dedir; eşitlik oluşmaz. MUX ($B, Y$ seçme girişleri): $I_0 = 0$, $I_1 = a_1a_0$, $I_2 = a_1 + a_0$, $I_3 = 1$.

> **Çözüm (derste verilmedi):** Karnaugh ile sadeleşmiş ifade $f = BY + Ba_1 + Ba_0 + Ya_1a_0$ (python ile doğrulandı); devre dört VE kapısı ve bir VEYA kapısından oluşur.

### Soru 4 (ekrandan, 01:10:00)

Aşağıda blok çizimi verilmiş devre şöyle çalışmaktadır: $w = 0$ ise $z_0 = x_0$, $z_1 = x_1$; $w = 1$ ise $z_0 = x_1$, $z_1 = x_0$. (a) Bu devreye ilişkin çıkış fonksiyonlarının lojik ifadelerini en yalın şekilde yazın; (b) devreyi TVEYA bağlaçları kullanarak gerçekleştirin; (c) devreyi veri seçici devrelerle (MUX) gerçekleştirin.

> **Çözüm (derste verildi, c şıkkı):** İki tane 2x1 MUX, seçme girişleri $w$. $z_0$ MUX'u: $I_0 = x_0$, $I_1 = x_1$; $z_1$ MUX'u: $I_0 = x_1$, $I_1 = x_0$.

> **Çözüm (derste verilmedi, a ve b şıkları):** $z_0 = \bar w x_0 + w x_1$, $z_1 = \bar w x_1 + w x_0$. TVEYA (NOR) için toplamların çarpımı biçimi kullanılır: $z_0 = (w + x_0)(\bar w + x_1)$, $z_1 = (w + x_1)(\bar w + x_0)$. Buradan $z_0 = \overline{\overline{(w + x_0)} + \overline{(\bar w + x_1)}}$, yani iki NOR kapısının çıkışları üçüncü bir NOR'a girer; $\bar w$, girişleri birleştirilmiş bir NOR ile elde edilir. $z_1$ de aynı yapıyla kurulur. İfadeler python ile doğrulandı.

### Soru 5 (ekrandan, 01:15:00)

2 tane seçici (MUX) ve bir VEYA kapısı içeren devreye ilişkin devre şeması verilmiştir (birinci 4x1 MUX: girişler $a, b, 1, 0$, seçme $c, d$; ikinci 4x1 MUX: girişler $\bar c, 1, 0, d$, seçme $a, b$; çıkışlar VEYA ile $Z$'yi verir). (a) Devreye ilişkin lojik fonksiyonu belirleyiniz; (b) fonksiyona ilişkin doğruluk tablosunu oluşturunuz; (c) $a, b$ ve $c$'yi seçme girişleri alarak devreyi 8x1 seçici (MUX) ile gerçekleyiniz.

> **Çözüm (derste verildi):** $Z = 0$ yalnız $abcd = 0011, 1001, 1011$ için. $Z = (a + b + \bar c + \bar d)(\bar a + b + c + \bar d)(\bar a + b + \bar c + \bar d)$. 8x1 MUX girişleri ($I_0 \dots I_7$): $1, \bar d, 1, 1, \bar d, \bar d, 1, 1$.

### Soru 6 (ekrandan, 01:30:00)

Üç katlı bir apartmanda merdiven aydınlatması şu şekilde yapılmaktadır: Her katta bir anahtar bulunmaktadır. Bu anahtarların konumuna göre katlarda bulunan lambaların hepsi birden yanmakta veya sönmektedir. Bu anahtarlar $x_1, x_2, x_3$ ile, lambalar ise $L$ ile gösterilmektedir. Anahtarın kapalı durumu 1, açık durumu 0, lambanın yanma konumu 1, sönme konumu 0'dır. Her üç anahtar da devreyi açık bırakan konumdayken lamba yanmamaktadır. Anahtarlardan herhangi biri devreyi kapatırsa lamba yanacaktır. İki anahtar birden devreyi kapatırsa lamba yanmamaktadır. Her üç anahtar da kapalıysa lamba yanacaktır. (a) Bu devreye ilişkin doğruluk tablosunu oluşturunuz; (b) bu tabloyu kullanarak devre çıkışına ilişkin çarpımlar toplamı kanonik biçimini elde ediniz; (c) $x_1$ ve $x_2$'yi seçme girişleri alarak devreyi MUX elemanı kullanarak gerçekleyiniz.

> **Çözüm (derste verildi, c şıkkı):** $I_0 = x_3$, $I_1 = \bar x_3$, $I_2 = \bar x_3$, $I_3 = x_3$.

> **Çözüm (derste verilmedi, b şıkkı):** $L = \bar x_1 \bar x_2 x_3 + \bar x_1 x_2 \bar x_3 + x_1 \bar x_2 \bar x_3 + x_1 x_2 x_3 = x_1 \oplus x_2 \oplus x_3$ (python ile doğrulandı).

### Soru 7 (ekrandan, 01:35:00)

BCD kodunda (0-9 arası) verilmiş olan bir sayı bir sistemden uzakta bulunan bir başka sisteme aktarılacaktır. Herhangi bir hataya sebebiyet vermemek için bu bilgi ile bir de eşlik biti gönderilecektir. Şekilde verildiği üzere, BCD kodunda 1'lerin sayısını tek yapan eşlik (parity) biti üretecini $x_1$ ve $x_2$'yi seçme girişleri alarak seçici (MUX) elemanı ile gerçekleyiniz. Yol gösterme: Doğruluk tablosunu dört giriş-bir çıkışlı devre için çıkışta 1'lerin sayısı tek olacak biçimde oluşturunuz. Tabloyu çarpımlar toplamı kanonik biçimde ifade ediniz. $x_1$ ve $x_2$ kontrol girişleri olacağından çarpımlar toplamı ifadesini $x_1x_2$'nin lojik bileşenlerine göre terimlere ayırarak seçici (MUX) girişlerini belirleyiniz ve MUX girişlerini çiziniz.

> **Çözüm (derste verildi):** BCD dışı satırlar farketmez alınır. $I_0 = \overline{x_3 \oplus x_4}$, $I_1 = x_3 \oplus x_4$, $I_2 = x_3 \oplus x_4$, $I_3 = \overline{x_3 \oplus x_4}$; bir XOR, bir XNOR ve bir 4x1 MUX.

### Soru 8 (ekrandan, 01:45:00)

Bir ALU'nun iç mimarisini ve genel tasarımını görmek amacıyla iki tane 4 bitlik veri, bir tane elde girişi olan ve bu veriler üzerinde 4 işlemden birini yapan bir ALU tasarlanmak istenmektedir; 4 bitlik sonuç çıkışı ve bir tane de elde çıkışı vardır. İşlem kodu listesi ve kodları tabloda verilen ALU'yu gerektiği kadar kapı, MUX ve buna benzer lojik elemanlar kullanarak tasarlayınız. (Veri girişleri $A$, $B$; elde girişi ve çıkışı $E_g$, $E_{\text{ç}}$; sonuç $F$; işlem kodu $k_1k_2$; işlemler $A + B$, $A - B$, $\bar B$, $A$'yı 1 bit sağa öteleme.)

> **Çözüm (derste verildi):** Tam toplayıcı, tam çıkarıcı, $B$ bitleri için NAND/NOR ile değil kapıları ve sağa öteleme için kaydırılmış kablolama paralel kurulur. İşlem kodu, her sonuç biti için bir tane olan dört adet 4x1 MUX'un seçme girişlerine bağlanır ve istenen sonucu $F$'ye aktarır.

## Dersin Toparlaması

Dersin ilk bölümünde birleşik devre tasarımı örneklerle tekrar edildi: kontrol girişli toplayıcı/çıkarıcı devresinin doğruluk tablosu, Karnaugh diyagramları ve yalnız NAND kapılarıyla gerçeklenmesi; helikopter, oylama ve merdiven aydınlatması gibi sözel problemlerden doğruluk tablosu kurulması; bu tabloların 4x1 ya da 8x1 MUX ile, seçme girişlerine göre satır gruplaması yapılarak doğrudan gerçeklenmesi. MUX'lu tasarımda her grubun girişine sabit 0 ya da 1, bir değişken, değilli değişken ya da küçük bir kapı (VE, VEYA, XOR, XNOR) bağlandığı görüldü. Bir eşlik biti üreteci ve dört işlemli basit bir ALU ile MUX'un "paralel hesapla, seç" yaklaşımında nasıl kullanıldığı gösterildi.

İkinci bölümde ardışıl devrelere giriş yapıldı: ardışıl devrenin birleşik devreye ek olarak tutucu ve flip-flop gibi bellek elemanları içerdiği, o anki durumun ek bir giriş, bir sonraki durumun ek bir çıkış olduğu anlatıldı. Mealy ve Moore makinelerinin yalnız çıkışın belirlenme biçiminde ayrıldığı, senkron devrelerde durum değişiminin ortak bir saat darbesiyle, asenkron devrelerde ise saat olmadan ve değişken gecikmelerle olduğu açıklandı. Kayıt aradan önce bitmektedir; ardışıl devrelerin örneklerine sonraki bölümde devam edileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
