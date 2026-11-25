# Ders 11 Çalışma Özeti

## Genel Konular

- Veri saklama ve bellek (Data Storage)
  - Bilginin en küçük birimi bit'tir (binary digit); 0 ya da 1 değerini alır. 8 bit bir byte eder.
  - Belleğin adreslenebilen en küçük birimi bir byte'lık hücredir (cell). Her hücrenin bir adresi ve bir değeri (value) vardır.
  - Bellek adresleri onaltılık (hexadecimal) sayılarla ve başlarına `0x` konarak yazılır: `0x0000`, `0x0001`, ..., `0x0009`, `0x000A`, ..., `0x000F`, `0x0010` (ekrandan, 00:05:00).
  - Adres sıfırdan başlamak zorunda değildir: `0xABCD`'den sonra `0xABCE`, `0xABCF`, `0xABD0` gelir.
  - Sayı dönüşümlerinde taban, parantezin dışına indis olarak yazılır: $(ABCD)_{16}$. Bilgisayar adreslemesinde ise `0x` gösterimi kullanılır.
  - Değişken tipine göre kaplanan yer değişir: karakter 1 byte, tamsayı mimariye bağlı olarak çoğunlukla 4 byte. 4 byte'lık değişkenlerde adresler dörder dörder ilerler (0, 4, 8, 12, 16).
- Mantık kapıları (logic gates)
  - Verinin donanımda saklanmasını ve işlenmesini sağlayan en küçük birimlerdir. Kapılar birleşerek flip-flop gibi devreleri oluşturur; 0 ve 1 bilgisi voltaj farkıyla tutulur.
  - Temel Boole işlemleri: AND, OR, XOR ve NOT.
    - AND: iki giriş de 1 ise çıkış 1, aksi halde 0.
    - OR: iki giriş de 0 ise çıkış 0, aksi halde 1.
    - XOR (exclusive or): girişler farklıysa (01, 10) çıkış 1.
    - NOT: tek girişlidir, girişin değilini üretir.
  - Kapılar birbirine bağlanarak devre oluşturur. Derste x ve y bir AND kapısına, AND çıkışı ile z bir OR kapısına giren bir devrenin doğruluk tablosu çıkarıldı (ekrandan, 00:15:00).
- Bitlerin adlandırılması
  - En soldaki bit en anlamlı bittir (most significant bit, high-order end); en sağdaki en anlamsız bittir (least significant bit, low-order end).
  - 8 bitlik bir sayıda en soldaki bitin değişmesi değere 128 ekler ya da çıkarır; en sağdaki bit değişirse değer yalnız 1 değişir.
- Sayı sistemleri arasında dönüşüm (önceki haftanın tekrarı)
  - İşaretsiz (unsigned) bir byte'ın onluk değeri, her bitin $2^0, 2^1, \dots, 2^7$ basamak değeriyle çarpılıp toplanmasıyla bulunur: $(01011100)_2 = 92$ (ekrandan, 00:20:00).
  - Onaltılığa geçmek için sayı sağdan 4 bitlik gruplara, sekizliğe geçmek için 3 bitlik gruplara ayrılır.
  - Onluktan başka tabana geçmek için sayı o tabana art arda bölünür, kalanlar sondan başa doğru yazılır.
- Bilginin bit örüntüleriyle temsili (Representing Information as Bit Patterns)
  - Sayılar, karakterler (metin), görüntüler, videolar, sesler ve programlar 0 ve 1'lerle temsil edilir.
  - Karakterler bir dönüştürme tablosu ile sayıya eşlenir: ASCII (American Standard Code for Information Interchange), ANSI tarafından belirlenmiştir. Örnek değerler: `'0'` = 48, `'1'` = 49, `'A'` = 65, `'a'` = 97 (ekrandan, 00:35:00).
  - Batı Avrupa dışındaki diller için bir byte yetmez; derste UTF-8 (Unicode Transformation Format 8-bit) ile 2 byte'ta $2^{16} = 65536$ simge saklanabileceği anlatıldı.
  - Görüntü bir piksel (picture element) matrisidir; Full HD 1920 × 1080 pikseldir. Video saniyede çok sayıda kareden (30, 120, 240 fps) oluşur.
- Analog ve dijital
  - Analog bilgi süreklidir; dijital bilgi analog sinyalden belirli bir örnekleme sıklığıyla alınan örneklerle oluşturulur. Örnek sayısı arttıkça sinyal daha iyi modellenir.
  - Dijital verinin üstünlükleri: kolay çoğaltılır, hatalardan daha az etkilenir, kolay paylaşılır. Analog veri fiziksel etkilere açıktır.
- Negatif sayıların gösterimi
  - İşaret biti: en soldaki bit 0 ise sayı pozitif, 1 ise negatiftir.
  - Bire göre tümleyen (one's complement): 0'lar 1, 1'ler 0 yapılır.
  - İkiye göre tümleyen (two's complement): bire göre tümleyenin üzerine 1 eklenir.
  - Excess (fazlalık) gösterimi: n bitlik alanda $2^{n-1}$ değeri sıfır kabul edilir; 3 bitte Excess-4, 4 bitte Excess-8.
- Kesirli sayıların saklanması
  - İkilik sayıda noktanın sağındaki basamaklar $2^{-1}, 2^{-2}, \dots$ değerindedir: $(100.11)_2 = 4.75$.
  - Kayan nokta gösterimi (floating-point notation): 8 bitlik örnekte 1 işaret biti, 3 bit üs (exponent, Excess-4), 4 bit mantis.
  - 32 bit tek duyarlıklı (single precision): 1 işaret, 8 bit üs, 23 bit mantis. 64 bit çift duyarlıklı (double precision). C'deki `float` ve `double` tiplerine karşılık gelir.
  - Kesme hatası (truncation error): mantise sığmayan bitler kaybolur.
- İkilik toplama, taşma ve çıkarma
  - Sonucun en solda oluşan biti için yer yoksa bilgi kaybolur (overflow).
  - Çıkarma, çıkarılan sayının ikiye göre tümleyeni alınıp toplanarak yapılır: $7 - 5 = 7 + (-5)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- ASCII değerleri ezberlenmez
  - Karakterlerle çalışırken sayısal kod (ör. 65) yerine karakter sabiti (`'A'`) kullanılmalıdır. Kodlama değişirse ezber değer yanlış olur.
  - Tek tırnak içinde tek karakter olur; birden fazla karakter için çift tırnak (`"ab"`) kullanılır.
- Sayılar 8 bit ile yazılır
  - Özel bir durum yoksa bir byte'lık sayılar 8 bit olarak yazılmalıdır; derste 7 bit yazılan sayılar başa 0 eklenerek düzeltildi.
- Bit grubunun anlamı verilmeden değeri bilinemez
  - Aynı 0/1 dizisi işaretsiz, işaretli (two's complement) ya da kayan nokta olarak farklı değerlere karşılık gelir.
- Neden bire göre tümleyen kullanılmaz
  - Bire göre tümleyende hem `00000000` hem `11111111` sıfırı gösterir (+0 ve −0). Bir değer için iki kombinasyon harcanır. İkiye göre tümleyende sıfır tektir ve aralık −128 ile 127 olur.
- Mantise ilk 1'den başlayarak yazılır
  - Mantisin başına gereksiz 0 konursa sondaki anlamlı bitler kaybolabilir.
- Kayan noktada hassasiyet kaybı
  - Mantis yetersiz kalırsa sayı daha az hassas saklanır; bu yüzden iki bilgisayarda kesirli sayılarla yapılan işlemler farklı sonuç verebilir.
- Çıkarma bilgisayarda toplama ile yapılır
  - Çıkarılan sayının negatifi (ikiye göre tümleyeni) alınıp toplanır.

## Kısa Tekrar Notları

- 1 bit: 0 ya da 1. 1 byte = 8 bit. Belleğin adreslenebilen en küçük birimi 1 byte.
- Adresler onaltılık ve `0x` önekiyle: `0x000F`'ten sonra `0x0010`.
- AND: ikisi de 1 ise 1. OR: ikisi de 0 ise 0. XOR: farklıysa 1. NOT: değil.
- MSB en soldaki (high-order end), LSB en sağdaki (low-order end) bit.
- $(11100000)_2 = 224 = (340)_8 = (E0)_{16}$; $(00010000)_2 = 16 = (20)_8 = (10)_{16}$; $(10000000)_2 = 128 = (200)_8 = (80)_{16}$.
- Onaltılık: 4 bitlik gruplar; sekizlik: 3 bitlik gruplar.
- ASCII: `'0'` = 48, `'A'` = 65, `'a'` = 97; yine de karakter sabiti kullan.
- Bire göre tümleyen: bitleri ters çevir. İkiye göre tümleyen: ters çevir, 1 ekle.
- İşaretli bir byte: −128 ile 127. İşaretsiz bir byte: 0 ile 255.
- Negatif sayının değeri: ikiye göre tümleyeni al, işaretsiz değeri bul, başına eksi koy. $(11000001)_2 = -63$; işaretsiz olarak 193.
- Kısa yol (8 bit): işaretli değer = işaretsiz değer − 256.
- Excess-4 (3 bit): kod − 4. Aralık −4 ile 3. Excess-8 (4 bit): aralık −8 ile 7.
- 8 bit kayan nokta: [işaret | 3 bit üs (Excess-4) | 4 bit mantis]. `0 110 1011` = 2.75; `0 011 1100` = 3/8; `0 101 1100` = 1.5; `1 101 1110` = −1.75.
- $2\frac{5}{8} = (10.101)_2$ 4 bit mantise sığmaz: `0 110 1010` = $2\frac{4}{8}$ (kesme hatası).
- Single precision: 1 + 8 + 23 bit; double precision: 64 bit.
- Çıkarma: $A - B = A + (-B)$.

## Detaylı Açıklamalar

### Bellek modeli ve adresler

Bellek, her biri bir byte (8 bit) tutan hücrelerden oluşan bir dizi gibi düşünülebilir. Derste hücreler Cell1, Cell2, ... diye çizildi; her hücrenin yanında bir değer (ör. `00000000`, `11111111`) ve bir adres yazıldı (ekrandan, 00:05:00). Adresler onaltılık sayılarla gösterilir: `0x0000`, `0x0001`, ..., `0x0009`'dan sonra `0x000A` gelir, `0x000F`'ten sonra ise `0x0010` gelir. Başka bir adresten başlansa da kural aynıdır: `0xABCD`, `0xABCE`, `0xABCF`, `0xABD0`.

Bir değişken birden fazla byte kaplıyorsa ardışık değişkenlerin adresleri o kadar ilerler. Karakter 1 byte yer kaplar. Tamsayı mimariye bağlı olarak 4 byte (32 bit) yer kaplayabilir; saklanan değer 0 da olsa 10000 de olsa aynı yeri kaplar. Bu yüzden 4 byte'lık tamsayılardan oluşan bir dizide adresler 0, 4, 8, 12, 16 (yani `0x10`) diye ilerler.

### Mantık kapıları ve basit bir devre

AND, OR, XOR ve NOT kapılarının doğruluk tabloları:

| x | y | AND | OR | XOR |
|---|---|-----|----|-----|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 |

NOT kapısı tek girişlidir: 0 girerse 1, 1 girerse 0 çıkar.

Derste x ve y bir AND kapısına girer, AND kapısının çıkışı ile z de bir OR kapısına girer; yani çıkış $(x \cdot y) + z$'dir. Doğruluk tablosu (ekrandan, 00:15:00):

| x | y | z | output |
|---|---|---|--------|
| 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 1 |

Kapılar farklı biçimlerde bağlanarak, bazı kapıların çıkışı diğerlerinin girişine verilerek ya da geri beslenerek karmaşık donanım devreleri kurulur. Bilgisayarların toplama işlemini de mantık kapılarıyla yaptığı belirtildi; ayrıntısı Lojik Devreler ve donanım derslerinde görülür.

### Dönüşüm örnekleri

Ekrandaki üç işaretsiz sayı (ekrandan, 00:25:00):

| İkilik | Onluk | Sekizlik | Onaltılık |
|--------|-------|----------|-----------|
| 11100000 | 224 | 340 | E0 |
| 00010000 | 16 | 20 | 10 |
| 10000000 | 128 | 200 | 80 |

Sekizlik için $3 \cdot 8^2 + 4 \cdot 8 + 0 = 192 + 32 = 224$. Onaltılık için $14 \cdot 16 = 224$ ve 14 = E olduğundan E0. Kısa yol: `1110 0000` gruplarından ilki E, ikincisi 0'dır.

Onluktan ikiliğe bölme yöntemi: 16 / 2 = 8 kalan 0; 8 / 2 = 4 kalan 0; 4 / 2 = 2 kalan 0; 2 / 2 = 1 kalan 0; son bölüm 1. Kalanlar sondan başa yazılınca $(10000)_2$ çıkar. Sekizliğe: 16 / 8 = 2 kalan 0, sonuç $(20)_8$ (ekrandan, 00:25:00).

### Karakterler, görüntü, video, ses

Karakterler de sayılarla saklanır; hangi sayının hangi karaktere karşılık geldiğine ASCII ya da UTF-8 gibi bir dönüştürücü tablo karar verir. Programcı yalnız hangi kodlamanın kullanıldığını bilmelidir; tabloya bakma işi bilgisayarındır. C'de karakterler ASCII karşılıklarıyla saklanır.

> **Ders sonrası not:** Hoca ASCII'nin bir byte ile 256 simge (0–255) içerdiğini ve UTF-8'in 2 byte (16 bit) kullandığını söyledi. Standart ASCII aslında 7 bitliktir (0–127); 128–255 aralığı "genişletilmiş ASCII" denen ve kod sayfasına göre değişen tablolara aittir. UTF-8 ise sabit 2 byte değil, karakter başına 1 ile 4 byte kullanan değişken uzunluklu bir kodlamadır; 2 byte'ta $2^{16}$ simge fikri UTF-16/UCS-2'ye daha yakındır.

Görüntüde her piksel bir ya da birden fazla renk değeri tutar. Çözünürlük, saniyedeki kare sayısı ve renk derinliği arttıkça dosya boyutu büyür. MP3 gibi biçimler kulağın ayırt edemediği sesleri kodlamayarak boyutu çok küçültür; dinleyici kalite farkını çoğunlukla fark etmez.

### Analog ve dijital

Analog bilgi süreklidir, dijital bilgi örneklemeyle elde edilir. Bir sinyalden yalnız dört örnek almak onu modellemeye yetmez; örnek sayısı arttıkça dijital gösterim analoga yaklaşır. Hocanın kova benzetmesi: kovadaki su yüksekliği analog olarak tam görülür, ama dijital olarak her kova yalnız "dolu (1)" ya da "boş (0)" olabilir; aynı hassasiyete ulaşmak için çok sayıda kova (örnek) gerekir (ekrandan, 00:45:00).

### İkiye göre tümleyen

Ekrandaki örnekler (ekrandan, 00:50:00):

- `00001111` → bire göre tümleyen `11110000` → +1 → `11110001`
- `01011001` → bire göre tümleyen `10100110` → +1 → `10100111`

İşaretli bir sayının değeri:

- `01100000`: işaret biti 0, pozitif, değeri 96.
- `10000000`: negatif. Tümleyen `01111111`, +1 → `10000000` = 128, sonuç −128.
- `11000001`: negatif. Tümleyen `00111110`, +1 → `00111111` = 63, sonuç −63. Aynı dizi işaretsiz olarak 193'tür; $256 - 193 = 63$ (ekrandan, 00:55:00 ve 01:35:00).

Tersine dönüşüm için önce sayının pozitif hali yazılır, sonra ikiye göre tümleyeni alınır: −32 için `00100000` → `11100000` (işaretsiz karşılığı 224); −1 için `00000001` → `11111111`.

3 bitlik ikiye göre tümleyen tablosu: `011`=3, `010`=2, `001`=1, `000`=0, `111`=−1, `110`=−2, `101`=−3, `100`=−4 (ekrandan, 01:35:00).

### Excess gösterimi

3 bitte `100` sıfır kabul edilir; yukarı doğru `101`=1, `110`=2, `111`=3; aşağı doğru `011`=−1, `010`=−2, `001`=−3, `000`=−4. Kolay hesap: kodun işaretsiz değerinden 4 çıkarılır (7 − 4 = 3, 0 − 4 = −4). Bu Excess-4 gösterimidir ve −4 ile 3 aralığını kapsar. 4 bitte `1000` sıfırdır (Excess-8): `1111` = 15 − 8 = 7, `0000` = 0 − 8 = −8 (ekrandan, 01:15:00).

### Kayan nokta gösterimi

8 bitlik yapı: [işaret (1) | üs (3, Excess-4) | mantis (4)]. Okuma adımları: işaret bitine bak; mantisi al ve başına nokta koy; üsü Excess-4 ile çöz; nokta üs pozitifse sağa, negatifse sola kayar.

- `0 110 1011`: pozitif, üs 6 − 4 = 2, `.1011` → `10.11` = $2\frac{3}{4}$ = 2.75. `1 110 1011` = −2.75 (ekrandan, 01:25:00).
- `0 011 1100`: pozitif, üs 3 − 4 = −1, `.1100` → `.01100` = $\frac{1}{4} + \frac{1}{8} = \frac{3}{8}$ (ekrandan, 01:30:00).

Yazma adımları:

- 1.5 = `1.1`: mantis `1100`, nokta bir sağa kaymalı, üs 1 → kod 5 = `101`. Sonuç `0 101 1100` (ekrandan, 01:30:00).
- 3/8 = `.011`: mantis ilk 1'den başlar, `1100`; nokta bir sola kaymış, üs −1 → kod 3 = `011`. Sonuç `0 011 1100`.
- −1.75 = `−1.11`: işaret 1, mantis `1110`, üs 1 → `101`. Sonuç `1 101 1110` (ekrandan, 01:40:00).

$2\frac{5}{8} = (10.101)_2$ için mantis `1010` olur, sondaki 1 sığmaz; `0 110 1010` okunduğunda $2\frac{4}{8} = 2.5$ çıkar. Kaybolan bite "lost bit", bu hataya kesme hatası (truncation error) denir (ekrandan, 02:00:00).

32 bitlik tek duyarlıklı biçimde 8 bitlik üs alanı vardır; derste bunun için Excess-128 kullanılacağı söylendi.

> **Ders sonrası not:** IEEE 754 tek duyarlıklı standardında üs alanının sapması (bias) 128 değil 127'dir. Ayrıca standart, normalize sayılarda baştaki 1'i saklamaz (gizli bit). Derste anlatılan 8 bitlik model bu ayrıntıları içermeyen öğretim amaçlı bir modeldir.

### Toplama ve çıkarma

4 bitlik örnekler (ekrandan, 01:45:00):

- $3 + 2$: `0011` + `0010` = `0101` = 5.
- $-3 + (-2)$: `1101` + `1110` = (taşan bit atılınca) `1011` = −5.
- $7 - 5 = 7 + (-5)$: `0111` + `1011` = (taşan bit atılınca) `0010` = 2.

Sonucun en solunda oluşan bit için yer yoksa bilgi kaybolur; buna taşma (overflow) denir. Bu yüzden işlem yapılan alanın sonucu tutmaya yetip yetmediğine dikkat edilmelidir. <!-- BELİRSİZ: Derste taşmayı göstermek için toplanan 4 bitlik ve 8 bitlik sayıların değerleri karelerde görünmüyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
