# Ders 19 Genişletilmiş Notu: Toplayıcı ve Çıkarıcı Devreler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kombinezonsal tümleşik devrelere giriş
- 2. Yarı toplayıcı
- 3. Tam toplayıcı
- 4. Tam toplayıcının iki yarı toplayıcıyla kurulması
- 5. 4 bitlik paralel toplayıcı
- 6. Yarı çıkarıcı
- 7. Tam çıkarıcı
- 8. 4 bitlik çıkarıcı ve borç kavramı üzerine sorular
- 9. Toplama/çıkarma devresi
- Örnek Sorular
- Dersin Toparlaması

## 1. Kombinezonsal tümleşik devrelere giriş

Ders bu kayıtta da tablet üzerinde dijital beyaz tahtaya elle yazılarak anlatılır. Önceki derste kombinezonsal devrelere giriş yapılmıştı; bu derste kombinezonsal tümleşik devrelere geçilir (ekrandan, 00:05:00).

Hoca bir kombinezonsal devreyi yazılımdaki bir fonksiyona benzetir: girişleri (örneğin $X$, $Y$) verirsiniz, devre size belirli çıkışları (örneğin $Z$) üretir. Önceki derste tasarlanan genlik karşılaştırıcı buna iyi bir örnektir. Bu devre bir çipin içine konursa kullanıcı yalnız girişleri verir ve "büyüktür, küçüktür, eşittir" gibi yalnız kendisine lazım olan çıkışı okur. Bu biçimde önceden yapılmış, özel amaçlı kombinezonsal devrelere **MSI devreler** denir; MSI, *Medium Scale Integration* yani orta ölçekli tümleşik devre demektir.

Bu bölümde sırayla görülecek devreler şunlardır (ekrandan, 00:10:00):

- Aritmetik toplama/çıkarma devreleri: yarı ve tam toplayıcılar, yarı ve tam çıkarıcılar, toplamayı ve çıkarmayı birlikte yapan toplama/çıkarma devresi.
- Çoğullayıcılar (multiplexer, MUX; Türkçede seçici de denir).
- Dağıtıcılar (demultiplexer, DEMUX).
- Kod çözücüler (decoder).
- Kodlayıcılar (encoder).
- Aritmetik lojik birim (ALU): aritmetik ve lojik işlemlerin birlikte yapıldığı birim.
- 7 segment gösterge (seven segment display).

Bu derste ilk grup, yani aritmetik toplama ve çıkarma devreleri işlenir.

## 2. Yarı toplayıcı

### 2.1 Tanım

Tahtada başlık "1A) Yarı Toplayıcı (half adder)" diye yazılır (ekrandan, 00:10:00). Yarı toplayıcının iki girişi ($a$, $b$) ve iki çıkışı vardır: toplam $T$ ve elde $E$. Tek bitlik bir toplama yapar.

Hoca bunu kâğıt üzerindeki çok basamaklı toplamayla açıklar. $ABCD + EFGH$ gibi iki sayıyı toplarken en sağdaki basamakta yalnız iki bit toplanır; elde varsa sola aktarılır. Ama aradaki basamaklarda, örneğin $C + G$ toplanırken, sağdan gelen eldenin de eklenmesi gerekir. Önceki eldeyi hesaba katmadan yalnız iki biti toplayan ve kendi eldesini üreten devre yarı toplayıcıdır; önceki eldeyi de toplayan devre tam toplayıcıdır.

### 2.2 Doğruluk tablosu ve ifadeler

| $a$ | $b$ | $T$ | $E$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 1 |

Yalnız $1 + 1$ toplamında elde oluşur. $T$ için iki değişkenli Karnaugh haritası çizilince 1'ler $01$ ve $10$ hücrelerine düşer; bunlar komşu değildir. Bu yüzden (ekrandan, 00:15:00):

$$T = \bar a b + \bar b a = a \oplus b$$

$E$ ise yalnız $a = b = 1$ satırında 1 olduğu için tablodan açıkça görülür; bir öğrenci de bunun AND olduğunu söyler:

$$E = a \cdot b$$

Böylece yarı toplayıcının içinde bir XOR ve bir AND kapısı vardır: $a$ ve $b$ hem XOR'a hem AND'e girer; XOR'un çıkışı $T$'yi, AND'in çıkışı $E$'yi verir.

> **Ders sonrası not:** Hoca bu devreyi çizerken bir an "bir tam toplayıcı yapmak için" dedi; burada kastedilen yarı toplayıcıdır.

## 3. Tam toplayıcı

### 3.1 Doğruluk tablosu

Başlık "1B) Tam Toplayıcı (Full Adder)" diye yazılır (ekrandan, 00:15:00). Bu kez üç giriş vardır: elde girişi $E_g$, $a$ ve $b$. Çıkışlar yine toplam $T$ ve elde $E$'dir. Tam toplayıcı artık üç ikilik sayıyı toplar.

| $E_g$ | $a$ | $b$ | $T$ | $E$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 | 1 |

Hoca tabloyu iki yarıya ayırarak doldurur. $E_g = 0$ olan üst yarı birebir yarı toplayıcının tablosudur: toplamlar $0, 1, 1, 0$, elde yalnız son satırda. Alt yarıda elde girişi 1'dir: $1 + 0 + 0$ toplamı 1, elde yok; $1 + 0 + 1$ ve $1 + 1 + 0$ toplamlarında toplam 0, elde 1; üç tane 1'in toplamında hem toplam hem elde 1'dir.

### 3.2 Toplam fonksiyonu

$T$ için üç değişkenli Karnaugh haritası kurulur: bir eksende $E_g$ (0, 1), diğerinde $ab$ (00, 01, 11, 10). $E_g = 0$ satırında $ab = 01$ ve $10$ hücreleri, $E_g = 1$ satırında $ab = 00$ ve $11$ hücreleri 1'dir. Hiçbir 1'in komşusu yoktur, bu yüzden dört minterm olduğu gibi kalır:

$$T = \bar E_g\,\bar a b + \bar E_g\,a\bar b + E_g\,\bar a\bar b + E_g\,ab = a \oplus b \oplus E_g$$

Bu, üç girişli XOR'dur. Hoca elde girişine $C$ da denebileceğini, değişken adının önemli olmadığını söyler; tahtada $C = E_g$ diye not edilir (ekrandan, 00:20:00).

**Soru:** Toplamın üç girişli XOR olduğunu nasıl hemen gördünüz? **Cevap:** Hoca, XOR'un tanımının daha önce verildiğini hatırlatır: iki değişkende $\bar a b + a\bar b$. Üç girişli XOR da aynı mantıkla, değişkenlerin tümlenmiş ve tümlenmemiş hallerinin sırayla dizildiği bir kombinasyon olarak yazılır; haritadan çıkan dört terim tam olarak bu tanımsal ifadedir.

> **Ek bilgi (derste anlatılmadı):** Üç girişli XOR, girişlerden tek sayıda 1 olduğunda 1 verir. Karnaugh haritasında bu fonksiyonun 1'leri dama tahtası düzeninde dizilir ve hiçbiri komşu olmadığı için gruplanamaz; bu görüntü XOR (ya da XNOR) fonksiyonunu tanımanın kısa yoludur.

### 3.3 Elde fonksiyonu

$E$ için harita bu kez $a$, $b$, $C$ ($C = E_g$) sırasıyla kurulur. Dört tane 1 vardır ($ab = 11$ hücresinin iki satırı ve $E_g = 1$ satırındaki $01$, $10$ hücreleri). İkili gruplarla (ekrandan, 00:20:00):

$$E = ab + E_g\,(a + b)$$

Ara adım eklendi: gruplar $ab$, $E_g a$ ve $E_g b$ terimlerini verir; son ikisinde $E_g$ ortak paranteze alınınca yukarıdaki biçim elde edilir.

### 3.4 Doğrudan gerçekleme

Tam toplayıcı üç girişli, iki çıkışlı kapalı bir kutu olarak çizilir (ekrandan, 00:20:00 ve 00:25:00):

- $a$, $b$ ve $E_g$ üç girişli bir XOR'a girer; çıkışı $T$'dir.
- $a$ ve $b$ bir AND'e girer ($ab$).
- $a$ ve $b$ bir OR'a girer ($a + b$); bu çıkış $E_g$ ile bir AND'de çarpılır.
- İki AND'in çıkışı bir OR'da toplanır; çıkışı $E$'dir.

Hoca bu devrenin biraz karmaşık olduğunu, içinde iki OR ve iki AND bulunduğunu belirtir.

## 4. Tam toplayıcının iki yarı toplayıcıyla kurulması

Hoca, aynı tam toplayıcının yarı toplayıcılarla yapılıp yapılamayacağını sorar. Bir yarı toplayıcı $a$ ile $b$'yi toplar; ama ara basamakta buna bir de elde girişini eklemek gerekir. O halde ilk yarı toplayıcının toplam çıkışı, ikinci bir yarı toplayıcıda elde girişiyle yeniden toplanmalıdır (ekrandan, 00:25:00):

```text
HA1: girişler a, b      -> T1 = a XOR b,       E1 = a AND b
HA2: girişler T1, Eg    -> T  = T1 XOR Eg,     E2 = T1 AND Eg
Asıl elde:                 E  = E1 OR E2
```

İlk yarı toplayıcıdan da ikinciden de birer elde çıkabilir; bunlar bir OR kapısında toplanarak asıl elde bulunur. Sonuçta yine üç girişli, iki çıkışlı bir tam toplayıcı elde edilir.

Ara adım eklendi: bu yapının elde çıkışı $E = ab + E_g(a \oplus b)$'dir. Doğrudan gerçeklemedeki $ab + E_g(a + b)$ ile aynı fonksiyondur; fark yalnız $a = b = 1$ satırındadır ve orada $ab = 1$ olduğu için iki ifade de 1 verir. Eşitlik python ile sekiz girişin hepsinde doğrulandı.

Hoca bu iki yapının (doğrudan tam toplayıcı ve iki yarı toplayıcılı tam toplayıcı) simülasyon ortamında kurulup aynı çıkışları verdiğinin gösterilmesini ödevin ilk iki kısmı olarak verdi.

## 5. 4 bitlik paralel toplayıcı

Tahtada örnek "4 bitlik iki sayının toplamını bulan bir paralel toplayıcının devre tasarımı (TT)" diye yazılır (ekrandan, 00:30:00). Toplanacak sayılar $a_3a_2a_1a_0$ ve $b_3b_2b_1b_0$'dır.

Dört tam toplayıcı gerekir: TT0, TT1, TT2, TT3. En düşük anlamlı bit en sağdaki TT0'dadır.

- TT0'a $a_0, b_0$; TT1'e $a_1, b_1$; TT2'ye $a_2, b_2$; TT3'e $a_3, b_3$ girer.
- Her toplayıcının bir elde girişi vardır: $E_{g0}, E_{g1}, E_{g2}, E_{g3}$.
- **Soru:** $E_{g0}$'a ne girmeli? **Cevap:** Bir öğrenci "sıfır" der; hoca onaylar. En düşük basamağa önceden gelen bir elde yoktur; bu giriş 0 yapılır ya da doğrudan toprağa bağlanır.
- Her toplayıcının iki çıkışı vardır: toplam ve elde. TT0'ın toplamı $T_0$, yani sonucun ilk basamağıdır. TT0'ın elde çıkışı $E_0$ bir sonraki basamağa geçmelidir, yani $E_{g1}$'e bağlanır. Aynı biçimde $E_1 \to E_{g2}$, $E_2 \to E_{g3}$.
- En sonda $T_3$ ve, dört bitlik toplamdan bir elde oluşuyorsa, $E_3$ elde edilir.

Böylece tam toplayıcılar kullanılarak bir devre tasarlanmış olur. Hoca bu tasarımda istenen tam toplayıcı bloğunun (doğrudan ya da yarı toplayıcılardan kurulmuş olanın) kullanılabileceğini söyledi; bu da ödevin üçüncü kısmıdır.

## 6. Yarı çıkarıcı

### 6.1 Tanım ve doğruluk tablosu

Başlık "2A) Yarı Çıkarıcı (half Subtractor)" diye yazılır (ekrandan, 00:35:00). Girişler $a$ ve $b$, çıkışlar fark $F$ ve borç $B$'dir. Hoca yine kâğıt üzerindeki çıkarmayı hatırlatır: $ABCD - EFGH$ işleminde bir basamakta çıkarma yapılamazsa yandaki basamaktan borç alınır.

| $a$ | $b$ | $F$ | $B$ |
|---|---|---|---|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 |
| 1 | 1 | 0 | 0 |

- $0 - 0$: fark 0, borç alınmaz.
- $0 - 1$: 0'dan 1 çıkmaz; yandan borç alınır. İkilik tabanda alınan borç bu basamakta 2 değerindedir: $2 - 1 = 1$. Fark 1, borç 1.
- $1 - 0$: fark 1, borç yok.
- $1 - 1$: fark 0, borç yok.

(Tahtada satırlar önce $00, 01, 11, 10$ sırasıyla yazıldı; hoca sonra sırayı normal ikilik sıraya çevirdi. Tablo burada normal sırayla verilmiştir.)

**Soru:** İkinci basamaktan bir alıyoruz ama bu basamakta 2 olmuyor mu? **Cevap:** Evet, alınan borç bu basamakta 2 değerindedir; $2 - 1 = 1$ farkı bu yüzden çıkar. **Soru:** Yani borç biti alınan miktarı göstermiyor mu? **Cevap:** Hayır, yalnız borç alındığını gösterir.

### 6.2 İfadeler ve devre

Fark için Karnaugh haritasında 1'ler $01$ ve $10$ hücrelerindedir; bu doğrudan XOR'dur. Borç yalnız $a = 0$, $b = 1$ hücresinde 1'dir:

$$F = a \oplus b, \qquad B = \bar a\, b$$

Yarı çıkarıcı devresi $a$ ve $b$'nin XOR'u ile farkı, $\bar a b$ ile borcu üretir. Hoca $\bar a b$'yi bir girişi değillenmiş (girişinde kabarcık olan) AND kapısıyla çizer ve bunun, $a$'yı önce bir NOT kapısından geçirip sonra $b$ ile AND'lemenin kısaltması olduğunu gösterir (ekrandan, 00:40:00). Ayrı bir NOT kapısı koymamak için bazen kapının bir ayağı bu şekilde değillenmiş çizilir.

## 7. Tam çıkarıcı

### 7.1 Borç girişinin anlamı

Başlık "2B) Tam Çıkarıcı (Full Subtractor)" diye yazılır (ekrandan, 00:40:00). Ara basamaklarda, toplamadaki elde girişine karşılık bir borç girişi $B_g$ vardır. $B_g$, çıkarma sırasında bir önceki (daha düşük) basamağın bu basamaktan borç alıp almadığını gösterir. $B_g = 1$ ise bu basamağın değeri bir azalmıştır.

### 7.2 Doğruluk tablosu

Tablo (ekrandan, 00:45:00):

| $a$ | $b$ | $B_g$ | $F$ | $B$ |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 0 | 0 |
| 1 | 1 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 | 1 |

Hoca satırların mantığını şöyle açıklar. $a = 0$, $b = 0$, $B_g = 1$ satırında alt basamak bu basamaktan borç almıştır, yani 0 olan bu basamağın bir azaltılması gerekir. Bunun için kendisi de yukarıdaki basamaktan borç alır ($B = 1$); borçla 2 olan değerden 1 düşünce fark 1 kalır ($F = 1$). Borç bu basamağın üzerinden geçip alt basamağa aktarılmış gibi düşünülebilir.

**Soru:** Bu satırda $a$ ile $b$ arasındaki fark 1, borç hesaba katılınca 0 olması gerekmiyor mu? **Cevap:** Bu satırda $B_g$ bir önceki basamaktan borç alındığını gösterir; fark ve borç çıkışları bu borcun bu basamak üzerinden karşılanmasına göre belirlenir. Hoca çıkarmanın ondalık tabanda nasıl yapıldığını gözden geçirip tabloyu buna göre yorumlamayı önerdi. Bu sorudaki ve aşağıdaki benzer sorulardaki açıklamalar kayıtta kısmen dağınıktır. <!-- BELİRSİZ: hocanın bu satırlar için verdiği açıklama altyazıda kesik kesik; mantık tablo ve python ile doğrulandı -->

> **Ek bilgi (derste anlatılmadı):** Tam çıkarıcı satırlarını en kolay okumanın yolu her satırda $a - b - B_g$ değerini hesaplamaktır. Sonuç negatifse yukarıdan borç alınır ($B = 1$) ve sonuca 2 eklenir; $F$ bu son değerdir. Örneğin $0 - 0 - 1 = -1$, borçla $-1 + 2 = 1$, yani $F = 1$, $B = 1$.

### 7.3 İfadeler

Fark için Karnaugh haritasında 1'ler yine dama tahtası düzenindedir; fark üç girişli XOR'dur:

$$F = a \oplus b \oplus B_g$$

Borç için haritada dört tane 1 vardır ($ab = 01$ hücresinin iki satırı, $B_g = 1$ satırındaki $ab = 00$ ve $11$ hücreleri). Üç ikili grupla:

$$B = \bar a b + \bar a B_g + b B_g$$

Hoca bunun $B = \bar a b + B_g(\bar a + b)$ biçiminde de yazılabileceğini söyler. İki ifade python ile sekiz girişte doğrulandı.

### 7.4 Gerçekleme

$a$, $b$ ve $B_g$ üç girişli XOR'a girer ve farkı verir. Borç için üç AND gerekir: $\bar a b$, $\bar a B_g$ ve $b B_g$. İlk ikisinde $a$ girişi değillenmiştir (girişi kabarcıklı AND). Bu üç AND'in çıkışı üç girişli bir kapıda birleştirilerek borç elde edilir. Hoca, girişi değillenmiş bir AND kapısının, o girişin önce NOT'tan geçirilip sonra AND'lenmesiyle aynı olduğunu yeniden gösterir.

> **Ders sonrası not:** Altyazıda hoca üç AND'i "üç girişli XOR ile" birleştirdiğini söylüyor. Borç ifadesi terimlerin toplamı ($\bar a b + \bar a B_g + bB_g$) olduğu için doğrusu üç girişli OR kapısıdır. Bu kısım kayıttaki karelerde görünmüyor; söz büyük olasılıkla dil sürçmesi ya da altyazı hatasıdır.

## 8. 4 bitlik çıkarıcı ve borç kavramı üzerine sorular

### 8.1 Devre

Tahtada örnek $a_3a_2a_1a_0 - b_3b_2b_1b_0 = F_3F_2F_1F_0$ diye yazılır (ekrandan, 00:50:00). Dört tam çıkarıcı gerekir: TÇ0, TÇ1, TÇ2, TÇ3 (ekrandan, 00:55:00).

- TÇ0'a $a_0, b_0$, ..., TÇ3'e $a_3, b_3$ girer.
- Borç girişleri $B_{g0}, \dots, B_{g3}$'tür. En düşük basamaktan önce borç alan bir basamak olmadığı için $B_{g0} = 0$ yapılır ya da toprağa bağlanır.
- Her basamağın borç çıkışı ($B_0, B_1, B_2$), bir üst basamağın borç girişine bağlanır; bu bağlantı yan basamaktan borç alınıp alınmadığını iletir.
- Çıkışlar $F_0, F_1, F_2, F_3$ ve en sondaki borç biti $B_3$'tür. Tahtada sonuç satırı $B_3F_3F_2F_1F_0$ diye yazılır.

Hoca tam çıkarıcının da simülasyon ortamında gerçeklenmesini ve iki farklı örnekle denenmesini istedi (ekrandan, 00:55:00).

### 8.2 $0000 - 1111$ örneği

Bir öğrenci $0000$'dan $1111$'in çıkarılmasının gösterilmesini ister (ekrandan, 00:55:00). Hocanın anlatımı: hiçbir basamakta 1 olmadığı için her basamakta yandan borç alınır. En düşük basamakta borçla $2 - 1 = 1$ kalır. Üst basamaklarda hem $b_i = 1$ hem alt basamağın aldığı borç düşüldüğü için sonuç 0 kalır ve her basamak yine borç alır. Tahtadaki sonuç:

$$0000 - 1111 = 0001, \quad B_3 = 1$$

Ara adım eklendi: basamak basamak $F_0 = 1, B_0 = 1$; $F_1 = 0 - 1 - 1 + 2 = 0, B_1 = 1$; aynı biçimde $F_2 = 0, F_3 = 0$ ve $B_3 = 1$. Sonuç python ile doğrulandı.

### 8.3 Ondalık benzetme

Öğrenci, sıfırdan bir çıkarınca fark 1 ve borç 1 olduğunu, sonraki basamakta durumun ne olacağını sorar. Hoca bunu ondalık tabanla açıklar ve $11 - 22$ örneğini verir. Önce birler basamağında borç alma düşüncesi hatırlatılır: $11$'den 2 çıkınca 9 kalır, bunun için yandaki basamaktan bir alınmıştır. Sonra bütün işlem düşünülür: sonuç 100 birimlik dairesel bir döngüde geriye gitmek gibidir. 0'dan başlayıp 99'a kadar giden bir sayaç düşünülürse, 11'den 22 geri gidildiğinde 89'a varılır; bunu biz "eksi" diye yazarız. İkilik çıkarıcıda da aynı durum geçerlidir ve son borç biti bu geri dönüşü gösterir.

$$11 - 22 \equiv 89 \pmod{100}$$

(Sonuç python ile doğrulandı. Tahtada bu örnek için yazılan ara satırlar karede kısmen görünüyor.) <!-- BELİRSİZ: 00:55:00 karesinde 11, 22 altında "09" yazılı görünüyor; altyazıdaki anlatım 89 sonucuna varıyor, karedeki satır büyük olasılıkla ara adımdır -->

### 8.4 Tam çıkarıcı tablosunun yorumu

**Soru:** Tam farkın doğruluk tablosunun ikinci satırındaki değerleri yorumlayabilir miyiz? **Cevap:** Bu satırda bu basamaktan borç alınmıştır ve basamağın değeri 0'dır. Demek ki borç bu basamağın üzerinden geçmiştir: bu basamak da yukarıdan borç alır ve borçla 2 olan değerden 1 düşülünce 1 kalır. Borç çıkışı 1'dir, çünkü fark ancak böyle 1 olabilir. Hoca bunu tahtada bir örnekle gösterir: sıfırdan bir çıkarılamayınca yandan borç alınır, o basamak 2 olur ve borcu bir sonraki basamağa geçirir. <!-- BELİRSİZ: bu örnekteki sayılar altyazıda "bir, sıfır, sıfır, bir, bir, bir" diye geçiyor ve karelerde görünmüyor; örnek tam aktarılamadı --> Hoca öğrencilere çıkarmanın ondalık tabanda nasıl yapıldığını gözden geçirip bu tabloyu ona göre yorumlamalarını önerdi.

## 9. Toplama/çıkarma devresi

### 9.1 Çıkarmayı toplamaya çevirmek

Başlık "3) Toplama/Çıkarma Devresi (Adder/Subtractor Devresi)" diye yazılır (ekrandan, 01:00:00). Amaç hem toplamayı hem çıkarmayı aynı devreyle yapmaktır.

Toplamada bir sorun yoktur. Çıkarmada ise aslında ikinci sayının ikiye tümleyeni alınıp birinci sayıyla toplanır. $ABCD - EFGH$ işleminde ikinci sayının bütün bitlerinin değili alınır ($\bar E\bar F\bar G\bar H$) ve 1 eklenir; böylece ikinci sayının ikiye tümleyeni oluşur:

$$ABCD - EFGH = ABCD + (\bar E\bar F\bar G\bar H + 1)$$

Demek ki çıkarma da bir toplama işlemidir: ikinci sayının ikiye tümleyeniyle toplama. Bu yüzden devre temelde dört tam toplayıcıyla kurulur.

### 9.2 Seçim ucu ve XOR

Girişler $a_3a_2a_1a_0$ ve $b_3b_2b_1b_0$'dır. Bir seçim ucu $M$ eklenir (ekrandan, 01:05:00):

- $M = 0$: toplama.
- $M = 1$: çıkarma.

$A$ girişlerinde hiçbir değişiklik olmaz. $B$ girişleri ise toplamada aynen geçmeli, çıkarmada tersine çevrilmelidir. Bunu yapan kapıyı bulmak için hoca girişlere $X$ ve $Y$ adını verir ve $X$'i $M$ gibi düşünmeyi önerir:

| $X$ ($M$) | $Y$ | $Z$ |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

$X = 0$ iken $Z = Y$; $X = 1$ iken $Z = \bar Y$. Bir öğrenci bu kapının XOR olduğunu söyler:

$$Z = X \oplus Y$$

Bu yüzden her $b_i$ girişine bir XOR bağlanır; XOR'ların diğer girişi ortak $M$ hattıdır. $M = 0$ iken toplayıcılara $b_3, b_2, b_1, b_0$ aynen gider; $M = 1$ iken $\bar b_3, \bar b_2, \bar b_1, \bar b_0$ gider.

### 9.3 Eksik olan $+1$

**Soru (hocadan):** İkinci sayının değilini almayı başardık; ikiye tümleyenin tam oluşması için başka ne gerekir? **Cevap:** Bir öğrenci "bir ile toplamamız gerekiyor" der. Hoca, 1'in en düşük anlamlı bite (least significant bit) eklenmesi gerektiğini belirtir.

Bunun için $M$ hattı TT0'ın elde girişine ($E_{g0}$) de bağlanır (ekrandan, 01:10:00). Böylece çıkarma durumunda en düşük basamağa fazladan bir 1 gelir; aynı anda toplayıcılara $\bar b_0, \bar b_1, \bar b_2, \bar b_3$ gittiği için devre ikinci sayının ikiye tümleyeniyle toplama yapmış olur.

Elde zinciri paralel toplayıcıdaki gibidir: $E_0 \to E_{g1}$, $E_1 \to E_{g2}$, $E_2 \to E_{g3}$. Çıkışlar $T_0 \dots T_3$ ve son elde $E_3$'tür.

> **Ders sonrası not:** Tahtada en soldaki toplayıcının çıkışları "$E_3$, $T_2$" diye yazıldı ve hoca anlatırken de "T2 ve E3" dedi; dördüncü toplayıcının toplam çıkışı $T_3$ olmalıdır.

Hoca bu devreyi "bir taşla iki kuş vurmak" diye özetler: $M = 0$ iken devre standart bir 4 bitlik toplayıcıdır; $M = 1$ iken XOR yapısı ve en düşük bite eklenen 1 sayesinde ikinci sayının ikiye tümleyeni alınır ve çıkarma yapılır. Devrenin $M$ ve $A$, $B$'nin bütün değerlerinde doğru toplama ve çıkarma (mod 16) verdiği python ile doğrulandı.

> **Ek bilgi (derste anlatılmadı):** İkiye tümleyenle çıkarma yapan bu devrede, işaretsiz sayılarda çıkarma sırasında son elde $E_3 = 1$ ise $A \ge B$'dir; $E_3 = 0$ ise sonuç negatiftir. Yani buradaki son elde, tam çıkarıcılı devredeki son borç bitinin tersi gibi davranır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00; derste sözlü, 00:25:04): Tam toplayıcıyı doğrudan kapılarla (XOR, AND, OR) ve iki yarı toplayıcı ile ayrı ayrı gerçekleyin; simülasyonda iki yapının aynı çıkışları verdiğini gösterin.

> **Çözüm (derste verildi):** Doğrudan yapı: $T = a \oplus b \oplus E_g$, $E = ab + E_g(a+b)$. Yarı toplayıcılı yapı: HA1 ($a$, $b$) $\to$ $a \oplus b$, $ab$; HA2 ($a \oplus b$, $E_g$) $\to$ $T$, $E_g(a \oplus b)$; $E = ab + E_g(a \oplus b)$. İki elde ifadesi sekiz girişin hepsinde aynıdır (python ile doğrulandı). Simülasyon kısmı derste yapılmadı.

**Soru 2** (ekrandan, 00:30:00): 4 bitlik iki sayının toplamını bulan bir paralel toplayıcının devre tasarımını tam toplayıcılarla yapın.

> **Çözüm (derste verildi):** Dört tam toplayıcı TT0-TT3; TT$i$'ye $a_i, b_i$ girer; $E_{g0} = 0$; $E_i \to E_{g(i+1)}$; çıkışlar $T_0 \dots T_3$ ve son elde $E_3$.

**Soru 3** (derste sözlü, 00:29:45): Paralel toplayıcıda en düşük basamaktaki tam toplayıcının elde girişine ne bağlanmalıdır?

> **Çözüm:** 0 (ya da toprak); en düşük basamağa önceden gelen bir elde yoktur.

**Soru 4** (ekrandan, 00:55:00): Tam çıkarıcıyı simülasyon ortamında gerçekleyin ve iki farklı örnek için deneyin; 4 bitlik çıkarıcıyı tam çıkarıcılarla kurun.

> **Çözüm (devre derste verildi):** Tam çıkarıcı: $F = a \oplus b \oplus B_g$, $B = \bar a b + \bar a B_g + bB_g$. 4 bitlik çıkarıcı: TÇ0-TÇ3, $B_{g0} = 0$, $B_i \to B_{g(i+1)}$, çıkışlar $F_0 \dots F_3$ ve $B_3$. Simülasyon kısmı derste yapılmadı.

**Soru 5** (ekrandan, 00:55:00; derste sözlü, 00:53:04): $0000 - 1111$ işlemini 4 bitlik çıkarıcıyla yapın.

> **Çözüm:** $F_3F_2F_1F_0 = 0001$, $B_3 = 1$ (tahtadaki sonuç; python ile doğrulandı: $0 - 15 \equiv 1 \pmod{16}$ ve son borç 1).

**Soru 6** (derste sözlü, 00:54:21): Ondalık tabanda $11 - 22$ işleminde yandan borç alınırsa iki basamaklı sonuç ne olur?

> **Çözüm:** $89$; 100 birimlik dairesel bir sayımda 11'den 22 geri gidilir ($11 - 22 \equiv 89 \pmod{100}$). Bu, son borcun "eksi" sonucu gösterdiği durumdur.

**Soru 7** (derste sözlü, 01:06:51): Toplama/çıkarma devresinde XOR'larla ikinci sayının değili alındıktan sonra ikiye tümleyenin oluşması için başka ne yapılmalıdır?

> **Çözüm:** En düşük anlamlı bite 1 eklenmelidir; bunun için $M$ ucu TT0'ın elde girişine ($E_{g0}$) bağlanır.

**Soru 8** (ekrandan, 01:10:00): Toplama/çıkarma devresini ($M = 0$ toplama, $M = 1$ çıkarma) gerçekleyin.

> **Çözüm (devre derste verildi):** Dört tam toplayıcı; her $b_i$ girişi $b_i \oplus M$ olarak verilir; $E_{g0} = M$; eldeler zincir halinde bağlanır. Bütün girişlerde doğru sonuç verdiği python ile doğrulandı. Simülasyon kısmı derste yapılmadı.

## Dersin Toparlaması

Bu derste MSI kombinezonsal devrelerin ilk grubu olan aritmetik devreler işlendi. Yarı toplayıcı ($T = a \oplus b$, $E = ab$) tek bitlik toplamayı, tam toplayıcı ($T = a \oplus b \oplus E_g$, $E = ab + E_g(a+b)$) önceki basamaktan gelen eldeyi de içeren toplamayı yapar. Tam toplayıcı iki yarı toplayıcı ve bir OR kapısıyla da kurulabilir. Dört tam toplayıcının eldeleri zincirlenerek 4 bitlik paralel toplayıcı elde edilir. Aynı mantık çıkarmada borç kavramıyla tekrarlandı: yarı çıkarıcı ($F = a \oplus b$, $B = \bar a b$), tam çıkarıcı ($F = a \oplus b \oplus B_g$, $B = \bar a b + \bar a B_g + bB_g$) ve dört tam çıkarıcıdan oluşan 4 bitlik çıkarıcı kuruldu; borç bitinin miktarı değil, borç alınıp alınmadığını gösterdiği vurgulandı.

Son olarak çıkarmanın, ikinci sayının ikiye tümleyeniyle toplama olduğu gösterildi. $B$ girişlerine konan XOR'lar ve seçim ucu $M$'nin en düşük basamağın elde girişine bağlanmasıyla aynı dört tam toplayıcı hem toplama hem çıkarma yapan bir devreye dönüştü. Sonraki derslerde çoğullayıcılar, dağıtıcılar, kod çözücüler, kodlayıcılar, ALU ve 7 segment gösterge ile devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
