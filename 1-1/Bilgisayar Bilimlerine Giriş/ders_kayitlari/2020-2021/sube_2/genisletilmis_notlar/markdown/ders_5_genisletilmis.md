# Ders 5 Genişletilmiş Notu: Operatörler, Veri Gösterimi, Algoritmalar ve Akış Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Operatörler Neden Konuşuluyor?
- 2. Aritmetik, İlişkisel ve Mantıksal Operatörler
- 3. Bit Bazında Operatörler: AND, OR, XOR
- 4. Shift ve Rotate
- 5. Bilgisayar Neden İkilik Sistem Kullanır?
- 6. Bilginin Eşlenmesi ve Karakter Kodlama
- 7. Negatif Sayılar
- 8. Kesirli Sayılar: IEEE Kayan Nokta
- 9. Bit, Nibble, Byte, Word ve Bellek Organizasyonu
- 10. Little Endian ve Big Endian
- 11. Algoritma Nedir?
- 12. Algoritma Tasarımı: En Yaşlıyı Bulmak
- 13. Karmaşıklık ve Arama Algoritmaları
- 14. Newton'un Karekök Algoritması
- 15. Akış Diyagramları
- 16. Sözde Kod (Pseudocode)

## 1. Operatörler Neden Konuşuluyor?

Önceki derste sayı sistemleri ve aralarındaki dönüşümler işlenmişti. Bu ders operatörlerle başlar. Toplama, çıkarma, çarpma, bölme ve mod işlemleri zaten bilinir. Ama algoritma kurup akışını çizmeye başlayınca bu işlemlerin hangi işaretle yazılacağı herkes için aynı olmalıdır. Hocanın amacı, akışlarda "ortada uçuşan tuhaf semboller" olmadan, herkesin anladığı net ve temiz bir dil kurmaktır.

## 2. Aritmetik, İlişkisel ve Mantıksal Operatörler

### 2.1 Aritmetik operatörler

Slayttaki aritmetik operatörler şunlardır (ekrandan, 00:05:00):

- Toplama: `+`
- Çıkarma: `-`
- Çarpma: `*`
- Bölme: `/`
- Mod: `mod`

Mod, bir sayının başka bir sayıya bölümünden kalanı verir. Hoca 7'nin 2'ye göre modunu sordu: 7, 2'ye tam bölünmez, kalan 1'dir, yani 7 mod 2 = 1. Akışta bu işlemlerden biri yapılacaksa bu işaretler kullanılmalıdır.

### 2.2 İlişkisel operatörler

İlişkisel operatörler iki operand arasındaki durumu netleştirir: birinin diğerinden büyük, küçük, büyük eşit, küçük eşit, eşit ya da eşit olmaması.

Büyük ve küçük işaretinde sorun yoktur; sorun büyük eşit ve küçük eşitte başlar. Matematikte büyük eşit, büyük işaretinin altına paralel bir çizgi çekilerek yazılır ($\geq$). Klavyede böyle bir tuş yoktur. Bu yüzden büyük eşit için önce büyük sonra eşit işareti (`>=`), küçük eşit için önce küçük sonra eşit işareti (`<=`) yazılır. Yani konuşulduğu sırayla yazılır.

> **Hocanın vurgusu:** Küçük eşit (`<=`) sola bakan bir ok gibi göründüğü için bazı öğrenciler büyük eşiti de "eşit büyük" (`=>`) diye yazıyor. Böyle bir yazım ve gösterim yoktur; buna dikkat edilmelidir.

Eşitlik için standart eşit işareti (`=`) kullanılır. Eşit değil için eşit işaretinin üzerine hafif eğik bir çizgi çekilir ($\neq$). Hoca bu sembolün ASCII ya da UTF-8 tablolarında bulunduğunu, programlamaya geçilince başka bir operatörle yazılacağını, ama akışlarda böyle kullanılacağını söyledi.

<!-- BELİRSİZ: İlişkisel operatör slaytı karelerde yok; işaretler altyazıdaki anlatımdan alındı. -->

### 2.3 Mantıksal operatörler

Üç temel mantıksal operatör vardır (ekrandan, 00:10:00):

- Mantıksal AND (ve)
- Mantıksal OR (veya)
- Mantıksal negation, NOT (değil)

AND iki koşulu birbirine bağlar ve ikisinin birlikte sağlanmasını ister. Hocanın örneği: bir sayının $-1$ ile $5$ arasında olması aranıyorsa koşul "$x > -1$ AND $x < 5$" olur. $x = 6$ için birinci koşul sağlanır ($6 > -1$), ama ikinci koşul sağlanmaz ($6 < 5$ değil). İki koşul birden sağlanmadığı için sonuç olumsuzdur.

OR, koşullardan birinin sağlanmasını yeterli sayar. Hoca koşulu aralığın dışını arayacak biçimde değiştirdi: "$x < -1$ OR $x > 5$". $x = 6$ beşten büyük olduğu için koşullardan biri sağlanır ve sonuç olumludur.

NOT ise aranan koşulun tersine bakar. Hoca bunların ileride örnekler üzerinde daha iyi oturacağını söyledi.

## 3. Bit Bazında Operatörler: AND, OR, XOR

İkilik sistemde her basamağa bir bit denir. Bit bazında (bitwise) operatörler bu bitlerin üzerinde işlem yapar. Burada da AND ve OR vardır, bunlara ek olarak exclusive OR (XOR), shift ve rotate gelir.

Bir sayıyı yazarken en sağdaki bit en düşük değerli bittir: LSB (least significant bit). En soldaki bit en yüksek değerli bittir: MSB (most significant bit).

Bütün örneklerde aynı iki sayı kullanılır (ekrandan, 00:15:00):

- $A = 60 =$ `0011 1100`
- $B = 13 =$ `0000 1101`

### 3.1 Bitwise AND

İki sayı bitwise AND'lendiğinde karşılıklı her basamak (1, 2, 4, 8, 16, 32, 64, 128 basamakları) tek tek AND işlemine girer. Çalışması mantıksal AND'e benzer: iki "koşul" da sağlanırsa (iki bit de 1 ise) sonuç 1, diğer bütün durumlarda 0'dır (ekrandan, 00:15:00).

| A | B | A AND B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Hoca $A \,\&\, B$'yi sağdan başlayarak adım adım çözdü:

```text
    A = 0011 1100
    B = 0000 1101
A & B = 0000 1100
```

Sağdan: 0 ile 1 → 0; 0 ile 0 → 0; 1 ile 1 → 1; 1 ile 1 → 1; geri kalan bütün bitlerde en az bir 0 olduğu için sonuç 0. Sonuç `0000 1100`, yani 12'dir (ondalık karşılık python ile kontrol edildi).

### 3.2 Bitwise OR

OR'da iki bitten biri 1 ise sonuç 1'dir; ikisi de 0 ise 0 (ekrandan, 00:20:00).

| A | B | A \| B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Bir öğrenci sonucu sağdan başlayarak okudu ve ondalık karşılığını önce 73 dedi, sonra 61 diye düzeltti. Slayttaki sonuç `0011 1101`'dir, yani 61.

Hoca burada önemli bir kısayol gösterdi. A ile B alt alta yazılınca B'de A'dan farklı olan tek şey en sağdaki 1'dir. A'nın en sağ biti 0 olduğu için OR'da değişecek tek bit odur. A zaten 60 olduğuna göre sonuç 60 + 1 = 61'dir.

> **Hocanın vurgusu:** Bilgisayar mühendisliğinde ikilik ve onaltılık sistemlerde çok sayıyla uğraşılacak; özellikle gömülü sistemlerle çalışılırsa bu işler refleks haline gelmelidir. Kendi kendinize rastgele iki sayı yazın, onaltılığa çevirin, oradan ikiliğe çevirin, ikilik sistemde işlem yapın, sonra başka bir sisteme çevirin ve böyle devam edin.

### 3.3 XOR

XOR, karşılıklı iki bit aynıysa 0, farklıysa 1 üretir (ekrandan, 00:25:00).

| A | B | A XOR B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Hoca XOR'a başka bir bakış da verdi: sonuç biti, iki bitteki 1'lerin sayısını çifte tamamlayan bit gibidir. Bitlerden biri 1 ise çift olmak için bir 1 daha gerekir, sonuç 1'dir. İkisi de 1 ya da ikisi de 0 ise 1'lerin sayısı zaten çifttir, sonuç 0'dır.

XOR, bilgisayar haberleşmesindeki birçok şeyin ve şifrelemenin temelindedir; simetrik şifrelemelerde kullanılır. Bilgisayar ağlarında da farkında olmadan sürekli kullanılır.

Bir öğrenci $A$ XOR $B$'yi "farklı olanlar 1" kuralıyla sağdan çözdü: en sağdaki bitler farklı (1), sonraki üç bit aynı (0), sonra iki bit farklı (1). İlk okumada basamakları karıştırdı, sonra doğru sonucu verdi:

```text
      A = 0011 1100
      B = 0000 1101
A XOR B = 0011 0001
```

Slayttaki sonuç `0011 0001`'dir. Ondalık karşılığı derste söylenmedi; python ile 49 bulunur.

Hoca bu sırada heyecan ve stres üzerine kısa bir öğüt verdi: işlemi bildiği halde yanlış okuma sık görülen bir hatadır. Sistem yönetiminde, yazılım geliştirmede ve güvenlikte stres hep olacaktır; herkes stresle başa çıkmanın kendi yolunu bulmalıdır. Sınavda da aynı durum vardır; bilinen bir şeyi stres yüzünden yanlış yapmak en çok kişinin kendisine zarar verir.

## 4. Shift ve Rotate

### 4.1 Shift (kaydırma)

Shift işleminde sayının bitleri belirtilen yöne kaydırılır; bu yüzden yön de mutlaka belirtilmelidir. Slaytta A hâlâ 60'tır (`0011 1100`) ve iki işlem sorulur: $A \ll 2$ ve $A \gg 3$ (ekrandan, 00:30:00).

**Sola iki kez kaydırma.** Kaydırmaya, işlem hangi yöne yapılıyorsa o taraftan başlanır. Sola kaydırmada en soldaki bit bir basamak sola atılır. Sayı 8 bit olduğu için 9. basamak yoktur; bu bit kaybolur. Hoca buna "uzay boşluğuna gidiyor" dedi. Sonra her bit bir basamak sola kayar. En sağdaki basamağa konacak bir değer yoktur; oraya 0 gelir.

```text
Başlangıç      : 0011 1100   (60)
1. sola kaydırma: 0111 1000   (120)
2. sola kaydırma: 1111 0000   (240)
```

Slayttaki sonuç `240 – 1111 0000`'dır (ekrandan, 00:30:00). Hoca ara değeri sorduğunda bazı öğrenciler 240 dedi (doğru), biri 180 dedi (yanlış).

Buradan çıkan sonuç: bir kez sola kaydırmak 2 ile çarpmaktır. Her bit bir basamak yukarı geçer; birler basamağındaki değer ikilere, ikilerdeki dörtlere geçer. Bu yüzden sayı iki katına çıkar: 60 → 120 → 240.

**Sağa üç kez kaydırma.** Aynı işlem bu kez sağa yapılır. En sağdaki bit kaybolur, bitler birer basamak sağa kayar, en sola 0 gelir.

```text
Başlangıç       : 0011 1100   (60)
1. sağa kaydırma: 0001 1110   (30)
2. sağa kaydırma: 0000 1111   (15)
3. sağa kaydırma: 0000 0111   (7)
```

Slayttaki sonuç `7 – 0000 0111`'dir (ekrandan, 00:40:00). Sağa kaydırma 2'ye bölmedir, ama tam sayı bölmesidir: 60 → 30 → 15 → 7. 15'in yarısı 7,5'tir, ama bitlerde kesirli değer gösterecek bir şey olmadığı için sonuç 7'dir. Kesirli sayıların nasıl gösterileceği ilerleyen kısımda konuşulur.

Hoca "uzay boşluğu"nun teknik bir terim olmadığını, kendi benzetmesi olduğunu söyledi. Önemli olan şudur: tanımlı sınırın dışından içeri her zaman 0 alınır. Oraya 1 koymak "gaipten sayı uydurmak" olur. Sağa kaydırmada dışarı 1 gitse bile öbür taraftan 1 değil, yine 0 girer.

**Soru:** Dört kez kaydırsak ne olur? **Cevap:** Hoca soruyu soran öğrenciden dördüncü kaydırmayı kendisinin yapmasını istedi ve sonucu doğru buldu. Dördüncü sağa kaydırmada `0000 0011` (3), beşincide `0000 0001` (1) elde edilir (değerler derste yüksek sesle okunmadı; python ile kontrol edildi).

**Soru:** Sayı ikiye bölünmüyorsa sonuç bir değer atlıyor mu? **Cevap:** Hoca, bitwise işlem yaparken derdin bu olmaması gerektiğini söyledi. Ondalık sistemde düşünüp ikilik sistemde sonuç üretmeye çalışmak matematiksel olarak doğru olsa da yöntem olarak yanlıştır. Hocanın benzetmesi: İngilizce bir soruyu önce Türkçeye çevirip Türkçe cevap üretir, sonra onu İngilizceye çevirirseniz hem geriden gelirsiniz hem büyük ihtimalle hata yaparsınız. İngilizce düşünmeye başlayınca soruya doğrudan cevap verirsiniz. İkilik sistemde de doğrudan düşünmeyi öğrenmek gerekir.

**Soru:** Aynı A sayısını üç kez sola kaydırırsak ne olur? **Cevap:** Sayılar 8 bit olarak tanımlandı; 16 ya da 12 bit değil. 8 bit sınırı konduysa 9. bit yoktur. Bitler de 0'dan başlayarak numaralanır: 0, 1, ..., 7. 7. biti sola kaydırınca o bit kaybolur. Üç kez sola kaydırmanın sonucu `1110 0000`'dır (python ile 224).

### 4.2 Rotate (döndürme)

Shift'te sağa kaydırırken en sağdaki bit kaybolur ve en sola dışarıdan 0 gelir. Rotate'te ise en sağdan çıkan bit kaybolmaz; alınıp en sola, en anlamlı bitin yerine konur. Slayttaki örnekte 16 bitlik `0101 0101 0101 0101` sayısı sağa döndürülür; en sağdaki 1 ("bit rotated out") en başa geçer ("bit rotated in") ve sonuç `1010 1010 1010 1010` olur (ekrandan, 00:35:00). Rotate sağa ya da sola yapılabilir.

Hoca bu operatörün şimdilik çok kullanılmayacağını, daha çok assembly programlamada karşılaşılacağını, şimdilik kulak dolgunluğu olmasının yeterli olduğunu söyledi.

## 5. Bilgisayar Neden İkilik Sistem Kullanır?

Bilgisayarda her şey 0 ve 1 ile ifade edilir. Tam sayılar, kesirli sayılar, harfler, resimler ve videolar bu iki değerle nasıl gösterilir? Bunun temelinde önce şu soru vardır: neden ikilik sistem?

Hoca tarihçe dersinde farklı bilgisayarların farklı sayı sistemleri kullandığını hatırlattı: PDP'nin sekizlik sistemi kullandığını, ilk ve özellikle mekanik bilgisayarlarda onluk sistemin kullanıldığını söyledi. Slayta göre ENIAC da ondalık sistemi kullanıyordu (ekrandan, 00:45:00).

Slayttaki gerekçeler şunlardır (ekrandan, 00:45:00):

- Neden ondalık sistem değil?
  - ENIAC ondalık sistemi kullanıyordu.
  - Daha fazla sinyal seviyesi ihtiyacı hassasiyet problemi yaratır.
  - Toplama, çarpma gibi işlemlerin gerçekleştirilmesi zorlaşır.
- İkili sistemde bilginin aktarımı daha kolaydır; parazit ve gürültülere karşı daha dayanıklıdır.

### 5.1 Gerilim bantları

Onluk sistemde bir basamak on farklı değer alır. Bilgisayarlar elektrik sinyalleriyle çalışır. 0 göndermek isteyince sinyalin 0 seviyesinde, 1 göndermek isteyince kullanılan gerilim seviyesinde (5 V, 3,3 V ya da 1,8 V gibi) olması beklenir.

Gerçekte sinyal "jilet gibi" düz olmaz. Etrafta sürekli hareket halindeki elektrik sinyalleri birbirini etkiler (elektromanyetik etki); sinyalin geçtiği yolun durumu ve yanından başka yol geçip geçmemesi de etkilidir. Bu yüzden her zaman bir parazitlenme görülür.

Çözüm güvenli bantlar tanımlamaktır. Slayttaki grafikte 0, 0,0 V ile 0,5 V arasında; 1, 2,8 V ile 3,3 V arasında kabul edilir (ekrandan, 00:45:00). 2,8 V'tan büyük her sinyal 1, 0,5 V'tan küçük her sinyal 0 sayılır. Aradaki bölge emniyet için boş bırakılır.

### 5.2 Ondalık sistemde ne olurdu?

Aynı şey onluk sistem için yapılsaydı 0 ile 3,3 V arasına on bant çekmek gerekirdi. Her banda en fazla yaklaşık 0,33 V düşerdi ($3{,}3 / 10$); bu, ikilik sistemde emniyet için ayrılan banttan bile küçüktür. Ondalık sistem aynı gerilim aralığında iki yönden hataya açıktır: 6 gönderilmek istenirken sinyal biraz düşerse 5, biraz yükselirse 7 okunur. İkilik sistemde ise 0 en kötü ihtimalle 1, 1 en kötü ihtimalle 0 olabilir; başka bir değer yoktur.

### 5.3 Gerilimi büyütmek çözüm mü?

Alternatif, gerilim aralığını büyütmektir: örneğin 12 V kullanıp her değere 1 V, aralara 0,2 V emniyet bandı ayırmak. Ama bunun iki bedeli vardır:

- Sinyal bir değerde bir süre kalmalıdır ki bunun gerçek bir değer olduğu, anlık bir pik ya da parazit olmadığı anlaşılsın. İkilik sistemde 0'dan 1'e ve 1'den 0'a geçiş süresi sabittir. Ondalık sistemde 0'dan en yüksek seviyeye geçişle komşu iki seviye arasındaki geçiş aynı sürede olmaz; bu da senkronizasyonda kaymaya yol açar.
- 0'dan 12 V'a çıkma süresi 0'dan 3 V ya da 1,8 V'a çıkma süresiyle aynı olamaz. Gerilim aralığı büyüdükçe çalışma hızı düşer.

Elektrik tabanlı ikilik sistemler 12 V seviyesinde başlamış, sonra 5 V, 3,3 V, 1,8 V'a ve bugün 1,2 V civarına inmiştir. Bunu daha hassas ve kararlı malzemeler mümkün kılmıştır ve bu düşüş hızlanmayı sağlayan etkenlerden biridir.

> **Hocanın vurgusu:** İkilik sistem gürültüye ve parazite karşı daha dayanıklıdır, daha hızlı çalışmaya imkân verir ve daha basittir. Bunu aklınızın bir kenarına kazıyın.

## 6. Bilginin Eşlenmesi ve Karakter Kodlama

Bellekte ya da depolama biriminde yazılabilen tek şey 0 ve 1'lerden oluşan değerlerdir. Harfleri ya da kesirli sayıları göstermek için bu değerlerin neye karşılık geldiğini belirleyen bir eşleme (mapping) gerekir. Slayta göre herhangi bir veri tipinin bellekte tutulması için bir eşleme yapılmalıdır ve aynı veri tipi için farklı eşleme yapıları bulunabilir. Slaytta örnek olarak ASCII (American Standard Code for Information Interchange), EBCDIC (Extended Binary Coded Decimal Interchange Code) ve UTF (Unicode Transformation Format) listelenir; yanındaki şekilde bir resmin piksel matrisi olarak bitlere eşlenmesi gösterilir (ekrandan, 00:50:00).

Karakterler için en bilinen eşleme ASCII karakter setidir; bugün daha yaygın olan UTF'dir. Hocaya göre ASCII'de Türkçe ve başka dillerdeki birçok özel karakter yoktur; eski sistemlerde Türkçe karakter sorunlarının nedeni budur. Bugün çok daha fazla sembolü kapsayan UTF-8 kullanıldığı için bu karmaşa yaşanmaz.

> **Ders sonrası not:** Hoca ASCII'nin 8 bitlik bir yapı olduğunu ve tablonun 0'dan 256'ya kadar gittiğini, UTF-8'in de "iki byte'lık" olduğunu söyledi. Standart ASCII 7 bittir ve 0–127 arasındaki kodları tanımlar; 8 bitlik genişletilmiş tablolar 0–255 arasındadır (256 değer). UTF-8 ise karakter başına 1 ile 4 byte arasında değişen uzunlukta bir kodlamadır; ASCII karakterleri tek byte ile yazılır.

### 6.1 ASCII tablosunun yapısı

Hocanın tabloda gösterdikleri:

- Büyük harfler 65'ten (`A`) başlar ve 90'a (`Z`) kadar gider; küçük harfler 97'den (`a`) başlar. Alfabe Amerikan standardı olduğu için İngiliz alfabesidir; Türkçe, Almanca ya da Fince gibi dillerdeki bazı karakterler yoktur.
- Rakam karakterleri de vardır: karakter olarak yazılan `0` 48, `9` ise 57'dir. Noktalama işaretleri, iki nokta, noktalı virgül, büyük-küçük işaretleri de tablodadır.
- 0'dan 31'e kadar olan kısım daha çok kontrol karakterleridir. Bunlar, o dönemde seri port üzerinden yapılan metin tabanlı haberleşmede kullanılmıştır: start of heading, start of text, end of text, end of transmission (1, 2, 3, ...), acknowledgement, end of transmission block, idle, break gibi.

(Değerler python `ord()` ile kontrol edildi: A = 65, Z = 90, a = 97, '0' = 48, '9' = 57.)

<!-- BELİRSİZ: ASCII tablosu slaytı karelerde yok; değerler altyazıdan alınıp python ile doğrulandı. -->

## 7. Negatif Sayılar

Şimdiye kadar hep pozitif tam sayılar konuşuldu. İkilik sistemde negatif sayıları göstermenin iki yolu vardır: bire göre tümleyen (1's complement) ve ikiye göre tümleyen (2's complement) (ekrandan, 00:55:00).

### 7.1 Bire göre tümleyen

En yüksek anlamlı bit (MSB) aynı zamanda sayının işaretini gösterir. Sayı 8 bitse en soldaki 7. bit, 16 bitse 15. bit işaret bitidir (bitler 0'dan numaralanır). İşaret biti 0 ise sayı pozitif, 1 ise negatiftir.

Bir sayının negatifini bulmak için ikilik yazımındaki her bit ters çevrilir: 1'ler 0, 0'lar 1 olur. Slayttaki örnek (ekrandan, 00:55:00):

```text
 11 : 0000 1011     (8 + 2 + 1)
-11 : 1111 0100     (her bit ters çevrildi)
```

> **Ders sonrası not:** Hoca $-11$'i sesli okurken "1111100" dedi; slayttaki ve doğru değer `1111 0100`'dür.

### 7.2 İkiye göre tümleyen

Bire göre tümleyende sıfır için iki farklı değer vardır. Bu tutarsızlıktır ve bir istisna oluşturur. Bu yüzden ikiye göre tümleyen kullanılır: önce bire göre tümleyen alınır, sonra sayıya 1 eklenir. Slayta göre ikiye göre tümleyende bu problem yoktur. Günümüzde kullanılan sistem ikiye göre tümleyendir.

> **Ek bilgi (derste anlatılmadı):** 8 bitte bire göre tümleyende `0000 0000` "+0", `1111 1111` ise "−0" olur. İkiye göre tümleyende `1111 1111` + 1 taşarak yine `0000 0000` olur, böylece sıfırın tek gösterimi kalır. Derste kullanılan 11 için ikiye göre tümleyen $-11$ = `1111 0100` + 1 = `1111 0101`'dir (python ile kontrol edildi).

## 8. Kesirli Sayılar: IEEE Kayan Nokta

Kesirli sayıları göstermenin farklı yolları vardır; derste standart olan konuşuldu. IEEE'nin (Uluslararası Elektrik ve Elektronik Mühendisleri Birliği) kayan nokta (floating point) sayılar için bir standardı vardır. Bu standart 32 ya da 64 bitlik alanı üç parçaya böler:

- İşaret biti (sign bit): en soldadır; 0 ise sayı pozitif, 1 ise negatiftir.
- Üs (exponent).
- Mantis (mantissa).

Mantisin başından itibaren her basamak bir öncekinin yarısı ağırlığa sahiptir: $1/2, 1/4, 1/8, 1/16, 1/32, \dots$ Hoca örnek slaytının olmadığını, örneği daha sonra göstereceğini söyledi.

> **Ders sonrası not:** Hoca üssün "sayının tam kısmını", mantisin "kesirli kısmını" gösterdiğini söyledi. IEEE 754'te üs, sayının 2'nin hangi kuvvetiyle ölçekleneceğini gösterir; mantis ise sayının anlamlı basamaklarını (significand) tutar. Tam ve kesir kısmı bu iki alana doğrudan ayrılmaz. Hoca mantis ağırlıklarını önce $1/2, 1/4, 1/8, 1/16, 1/32$ diye doğru okudu, sonra "$2^{-1}, 2^{-2}, 2^{-4}, 2^{-8}$" dedi; doğrusu $2^{-1}, 2^{-2}, 2^{-3}, 2^{-4}, 2^{-5}$'tir.

<!-- BELİRSİZ: Kayan nokta slaytı karelerde yok; parçaların sırası ve bit sayıları altyazıdan alındı. -->

> **Ek bilgi (derste anlatılmadı):** 32 bitlik IEEE 754 tek duyarlıklı sayıda 1 bit işaret, 8 bit üs ve 23 bit mantis vardır; 64 bitlik çift duyarlıklı sayıda bu dağılım 1, 11 ve 52 bittir. Sayının değeri kabaca $(-1)^{\text{işaret}} \times 1{,}\text{mantis} \times 2^{\text{üs} - \text{sapma}}$ biçiminde hesaplanır.

## 9. Bit, Nibble, Byte, Word ve Bellek Organizasyonu

### 9.1 Boyut adları

Şimdiye kadar 8 bit, 16 bit, 32 bit gibi ifadeler kullanıldı. Bunların adları şöyledir (ekrandan, 01:15:00):

| Boyut | Ad |
|---|---|
| 4 bit | nibble |
| 8 bit | byte |
| 16 bit | word |
| 32 bit | long word |
| 64 bit | very long word |

Hoca 8 bitlik sayıları okunabilir olsun diye 4 bitlik parçalar halinde yazdığını söyledi; bu 4 bitlik parçaların her biri bir nibble'dır. "Word" denince otomatik olarak 16 bit, "byte" denince 8 bit, "nibble" denince 4 bit anlaşılmalıdır.

### 9.2 Bellek adresleme

Bellek organizasyonu 8'in katları şeklindedir; bellekte 8 bitlik alanlar vardır ve her birine byte denir. Hocaya göre bilgisayar mimarisinin kaç bit olduğuna bağlı olarak adresleme şekli değişir:

- 8 bitlik mimaride her adres bir byte'ı gösterir; adresler 0, 1, 2, 3, ... diye gider.
- 16 bitlik mimaride her adres 2 byte'lık alanı gösterir; adresler 0, 2, 4, 6, 8, ... diye gider.
- 32 bitlik mimaride her adres 4 byte'lık alanı gösterir; adresler 0, 4, 8, 12, ... diye gider.

Bir mimarinin kaç bitlik olduğu, bütün işlemlerinde doğal (native) olarak kaç bit üzerinde çalışabildiğiyle ilgilidir. Belleğe erişirken adres buna göre belirlenir.

> **Ders sonrası not:** Günümüz mimarilerinin çoğu byte adreslemelidir: her byte'ın kendi adresi vardır ve adresler 32 ya da 64 bitlik mimaride de birer birer artar. Hocanın anlattığı 0, 2, 4 ya da 0, 4, 8 sırası, word ya da long word boyutunda hizalı (aligned) erişimlerin başlangıç adresleri olarak düşünülmelidir.

## 10. Little Endian ve Big Endian

Farklı bilgisayar sistemlerinde belleğe erişimde farklılıklar vardır. Bunlardan biri, bir byte'tan büyük bir verinin belleğe yazılırken parçalarının hangi sırayla yerleştirileceğidir. Slayta göre endian, verinin belleğe yerleşiminin nasıl yapılacağını belirler (ekrandan, 01:20:00).

Slayttaki örnek sayı `0x0001020304050607`'dir. Başındaki `0x` sayının onaltılık olduğunu gösterir; byte'lar kolay izlensin diye `00, 01, ..., 07` diye seçilmiştir. En düşük anlamlı byte `07`'dir.

- **Big endian:** En düşük adrese (a) en yüksek anlamlı byte yazılır: a'da `00`, a+1'de `01`, ..., a+7'de `07`.
- **Little endian:** En düşük adrese en düşük anlamlı byte yazılır; adres arttıkça daha yüksek anlamlı byte'lar gelir: a'da `07`, a+1'de `06`, ..., a+7'de `00`.

| Adres | a | a+1 | a+2 | a+3 | a+4 | a+5 | a+6 | a+7 |
|---|---|---|---|---|---|---|---|---|
| Big endian | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 |
| Little endian | 07 | 06 | 05 | 04 | 03 | 02 | 01 | 00 |

> **Ders sonrası not:** Slayttaki little endian tablosunda `03` iki kez yazılmış ve `00` hiç yok (`07 06 05 04 03 03 02 01`). Doğru sıra yukarıdaki tablodaki gibi `07 06 05 04 03 02 01 00`'dır (python ile kontrol edildi).

Bunun pratikte önemi şudur: hocaya göre Intel mimarili makineler little endian, RISC mimarisindeki PowerPC'ler big endian kullanır. Bilgisayar ağlarında da bir düzen vardır. Bir byte'tan uzun bir bilgi gönderilirken önce ağın düzenine çevrilir, ağdan alınırken de kendi sisteminin düzenine çevrilir. Her şeyin düzgün çalışması bu dönüşüme bağlıdır.

> **Ek bilgi (derste anlatılmadı):** Ağ protokollerinde kullanılan "ağ byte sırası" (network byte order) big endian'dır. C'deki `htonl` ve `ntohl` gibi fonksiyonlar bu dönüşümü yapar.

## 11. Algoritma Nedir?

Temellerle ilgili kısım bittikten sonra algoritma ve akış diyagramlarına geçildi. Algoritmanın tarihi Harezmî'ye kadar gider; hoca bu tarihçenin ayrıntısına girmedi.

Temel olarak algoritma, bir işi başarmak için adım adım yapılması gerekenleri tarif eden yapıdır. Günlük hayatta algoritmaya en çok benzeyen şey yemek tarifidir: önce hangi malzemeden ne kadar kullanılacağı söylenir, sonra "şunu yapın, şu kıvama gelene kadar karıştırın, şu kadar gram ekleyin" diye adımlar sıralanır.

Algoritma yalnız yazılıma özgü değildir, ama en yaygın kullanıldığı yer yazılım geliştirmedir. Yazılım geliştirmede bilgisayarın gerçekleştirebileceği işlemler algoritmada tasarlanır ve bir araya getirilir. Programcının işi, ortadaki probleme uygun çözümü bilgisayarın anlayabileceği şekilde ifade etmek ve gerçekleştirmektir. Algoritma programlama diline bağlı değildir; hangi dil kullanılıyorsa algoritma o dilde gerçeklenir.

Slayttaki tanım şöyledir (ekrandan, 01:25:00):

- Algoritmalar iyi tanımlanmış, belirsizlik içermeyen komutlar dizisidir (well-defined sequence of unambiguous instructions).
- Bir sonuç üretmek için sonlanmalıdır (must terminate).
- Algoritma tarifi iyi tanımlanmış bir "komut diline" dayanır.

### 11.1 Elle toplama yöntemini tarif etmek

Slaytta "Describe the method!" başlığıyla bir toplama gösterilir: $123456 + 789001 = 912457$ (ekrandan, 01:25:00). Hoca işlemin yapılmasını değil, nasıl yapıldığının tarif edilmesini istedi.

Bir öğrencinin tarifi şöyleydi: birler basamağını topla; sonuç 10'dan küçükse yaz; 10'dan büyükse birler basamağını yaz, 1'i onlar basamağına ekle. İki sayı toplandığı için basamak toplamı 20'yi geçmez, bu yüzden elde 1'dir. Sonra onlar basamağını topla, elde varsa ekle; sonuç 10'dan büyükse 1'i yüzler basamağına aktar, küçükse doğrudan yaz. Yüzler, binler basamakları için de aynısı geçerlidir. Hoca en soldaki basamağı sorunca öğrenci orada sonucun doğrudan yazılacağını ekledi.

Hoca bu tarifte iki eksik gösterdi:

- **Uç nokta problemi:** En soldaki basamağın toplamı ilk tarifte atlanmıştı.
- **Genellik:** Tarif yalnız iki sayının toplamında çalışıyordu, çünkü eldenin en fazla 1 olacağı kabul edilmişti. Üç ya da beş sayı toplanınca bu tarif çalışmaz.

Çok basit, her gün yapılan bir işlemi tarif ederken bile sıkıntı yaşanabilir. Bir tarif ortaya konunca denenmeli; işe uygun olup olmadığı, istisna oluşup oluşmadığı kontrol edilmelidir.

> **Hocanın vurgusu:** Algoritma geliştirirken şunlara dikkat edin: tarif ne kadar anlaşılır, farklı durumlarda ve özellikle uç noktalarda çalışıyor mu, özel bir çözüm mü yoksa genel bir çözüm mü?

Hoca ayrıca bir arkadaş tarif yaparken sohbet penceresine dağınık notlar yazılmamasını, fikri olanın mikrofonu açıp başı sonu belli bir şekilde anlatmasını istedi. İşin zorluğu ile kullanılan yöntemin karmaşıklığı orantılı olmalıdır; çok basit bir işi çok dolambaçlı bir yoldan yapmak, "sağ elle sol kulağı tutmaya çalışmak" gibidir.

Yemek tarifine dönersek: "kulak memesi kıvamı", "göz kararı" gibi belirsiz ifadeler bir yemek kitabında yoktur; orada neredeyse kaç tur kavrulacağına kadar her şey yazar. Bilgisayara bir şey yaptırırken de bu netlik beklenir.

## 12. Algoritma Tasarımı: En Yaşlıyı Bulmak

### 12.1 Sınıfta tartışma

Hoca sınıfta 69 kişi olduğunu söyleyip sordu: fiziksel bir sınıfta olsaydık, aramızdaki en yaşlıyı ya da en genci nasıl bulurduk? Öğrencilerden gelen öneriler:

- Herkes doğum tarihini yazar; önce yıla göre bakılır, yılı en küçük olanlar arasında aya, sonra güne bakılır.
- İlk kişinin yaşı hem en büyük hem en küçük kabul edilir. Her yeni kişinin yaşı bunlarla karşılaştırılır; daha büyükse yeni en büyük, daha küçükse yeni en küçük olur. Sonunda en büyük ve en küçük bulunur.
- Önce "60 yaşından büyükler el kaldırsın" denir; yoksa 50'ye, sonra 55'e göre aralık daraltılır.
- Herkes kaç gün yaşadığını hesaplar, sonra gün sayısına göre sıralanır.

Hoca bütün tariflerde sorun olduğunu söyledi:

- "Sıralarım" demek bir adımı atlamaktır. Bilgisayarın "bunu sırala" diye bir yeteneği yoktur. Bir kütüphane kullanılıyorsa onun sıralama fonksiyonu kullanılır, ama burada istenen işin açıkça tarif edilmesidir.
- Soru "en yaşlı ya da en genç" idi; ikisini birden bulmaya çalışmak problemi gereksiz yere karmaşıklaştırır. Hangisinin aranacağı seçilip ona çözüm üretilmelidir.
- Yalnız yıla ya da yaşa bakmak doğru sonucu vermeyebilir; en yaşlıyı bulmak için güne kadar inmek gerekir.
- Soru "öğrenciler arasında" dememişti; soruyu dikkatle okumak ve önyargıyla yaklaşmamak gerekir.

Hoca bu cevapları veren öğrencilere teşekkür etti; çünkü bunlar herkesin aklından geçen ama söylenmeyen fikirlerdi.

### 12.2 Polya'nın dört adımı

Slayttaki "Designing & Analyzing Algorithms" başlığına göre George Polya'nın problem çözmedeki dört adımı şunlardır (ekrandan, 01:40:00):

1. Problemi anla (understand the problem).
2. Bir plan yap (devise a plan).
3. Planı uygula (carry out your plan).
4. Çözümü incele (examine the solution).

Örnek: bir oda dolusu insan içinde en yaşlıyı bulmak.

- Başlangıç durumu: insanlarla dolu bir oda.
- Hedef: en yaşlı kişiyi belirlemek.
- Varsayımlar:
  - Herkes gerçek doğum gününü söyler (kimse yalan söylemez; yaş bakarak bilinmez, beyana dayanır).
  - Aynı gün doğan iki kişi aynı yaştadır (çözünürlük gün seviyesidir, saate inilmez).
  - Birden fazla en yaşlı varsa birini bulmak yeterlidir.

Bu problem için iki farklı tasarım düşünülür.

### 12.3 Birinci tasarım: sıralı

Sınıfın bir ucundan bir kâğıt verilir. İlk kişi adını yazar ve kâğıdı yanındakine uzatır. Sonraki kişi kâğıttaki kişiden daha gençse bir şey yapmaz; daha yaşlıysa o adın üstünü çizip kendi adını yazar ve kâğıdı uzatır. Kâğıt elden ele dolaşınca en yaşlı kişi bulunur. Kâğıdın herkesin elinden geçmesi gerektiği için sınıfta kaç kişi varsa o kadar adım gerekir. Her adımda bir kişiyle ilerlendiği için bu sıralı (sequential) bir işlemdir. Bu tasarım, öğrencilerden birinin önerdiği "ilk kişiyi en büyük kabul et, sonrakilerle karşılaştır" tarifinin yalnız en yaşlıya indirgenmiş halidir.

### 12.4 İkinci tasarım: paralel

Sınıf düzeninde her sırada iki üç kişi oturur. İlk adımda herkes kendi sırasının en yaşlısını belirler. Sonra her sıranın en yaşlısı önündeki sıranın en yaşlısıyla karşılaştırılır; bir adım sonra ayakta kalanlar arasında yine en yaşlı belirlenir. Böylece aday sayısı "ikiye böle böle" azalır ve en yaşlı hızla bulunur. Burada farklı insanlar bağımsız olarak aynı anda karşılaştırma yaptığı için işlem paralelleşir.

Her sırada iki kişi olduğu kabul edilirse hızlanma logaritmiktir. 100 kişilik bir sınıfta sıralı arama 100 adım sürer, çünkü son kişiye kadar kontrol gerekir. İkinci tasarımda 100, ikinin kuvveti olarak 128'e yuvarlanırsa yaklaşık 7 adımda en yaşlı bulunur ($2^7 = 128$).

## 13. Karmaşıklık ve Arama Algoritmaları

### 13.1 Karmaşıklık

Bu işlemlerin ne sıklıkta ve kaç kez yapıldığı, algoritmanın karmaşıklığını verir. İki tür karmaşıklık vardır:

- **İşlem karmaşıklığı:** Yapılması gereken işlem sayısıdır. İşlem hızı belli olduğu için işlem sayısı arttıkça süre uzar; bu yüzden zamana karşılık gelir.
- **Boyut (alan) karmaşıklığı:** Problemi çözmek için ne kadar yere ihtiyaç duyulduğudur.

Bu derste "karmaşıklık" denince işlem karmaşıklığı kastedilecektir. Sınıfta $n$ kişi varsa sıralı tasarımın karmaşıklığı $n$, paralel tasarımınki $\log_2 n$ mertebesindedir; ikincisi çok daha hızlıdır.

Hoca bunun şimdilik kulak dolgunluğu olduğunu, Big O ve Small O gibi gösterimlerle gerçek analizin veri yapıları ve algoritmalar dersinde yapılacağını söyledi. Bu derste de her algoritma için karmaşıklığın hangi mertebede olduğu konuşulacaktır.

### 13.2 Arama problemleri

Bilgisayar sistemlerinde çok sık karşılaşılan problemlerden biri bir verinin aranmasıdır. En genci ya da en yaşlıyı bulmak bir arama problemidir. İstanbul'un 2020 yılı sıcaklık değerleri arasında medyanı bulmak da biraz farklı bir arama problemidir. Çok görülen iki yöntem sıralı arama (sequential search) ve ikili aramadır (binary search).

İkili arama teknik olarak çok daha hızlıdır, ama her zaman kullanılamaz. Verinin nasıl tutulduğu, üzerinde kullanılabilecek yöntemleri belirler. İkili arama için veri yapısının sıralı olması (ya da paralelleştirilebilir olması gibi şartlar) gerekir.

### 13.3 Sıralı arama

Slayttaki tanım (ekrandan, 01:50:00):

- Listedeki her öğeyi, aranan bulunana kadar sırayla incelemeyi içeren bir algoritmadır.
- Listede bir öğe bulmak için:
  - Listenin başından başla.
  - Listedeki her öğe için: öğeyi incele; aranan öğe buysa işin bitti; değilse sonraki öğeye geç.
  - Listenin sonuna gelip öğeyi bulamadıysan öğe listede yoktur.
- Öğe listedeyse bulunacağını garanti eder, ama çok büyük veritabanları için pek pratik değildir.
- En kötü durum (worst case): listedeki her kayda bakmak gerekebilir.

En büyüğü arıyorsanız ilk eleman en büyük kabul edilir; her yeni eleman onunla karşılaştırılır, daha büyükse yeni en büyük o olur. Bu, son elemana kadar sürmelidir.

Aranan şey bir kimlik numarası kaydı gibi belirli bir değerse, listenin başından başlanır ve o kayıt bulunana kadar ya da liste bitene kadar devam edilir. Koşulların "veya" ile bağlanmasının nedeni şudur: liste örneğin bir sabıka kaydı listesiyse ve aranan numara orada yoksa, bunu bilmek için bütün liste baştan sona taranmalıdır; bu en kötü durumdur. Numara listenin 500. elemanında bulunursa arama orada biter. Karmaşıklık konuşulurken en kötü durum (worst case), ortalama durum (average case) ve genel karmaşıklık ayrı ayrı ifade edilir.

Derste bir öğrencinin sorusu üzerine hoca kimlik numarası örneğini açıkladı: kimlik numarasına "numara" denir ama gerçek hayatta karakter dizisi olarak karşılaştırılır. Karakter dizileri başından itibaren tek tek karşılaştırılır; bir yerde fark çıkınca kaydın o olmadığı anlaşılır. Hoca örneği verirken numarayı sayısal değer kabul etmişti.

### 13.4 İkili arama

İkili arama yalnız sıralı bir veri yapısında kullanılabilir. Hocanın örneği bir telefon rehberidir: 500.000 kayıtlık rehberde M harfiyle başlayan bir isim aranıyor. Rehber A'dan başlayıp Z'de bittiği için M'yi aramaya ortalardan bir yerden başlanır. Ortada O harfi görülürse M'lerin ilk yarıda olduğu anlaşılır ve sonraki adımda o yarının ortasına bakılır. Böyle böle böle ilerlenir.

Her adımda arama alanının yarısı arama dışı kalır. İlk adımda 500.000 kayıttan 250.000'i elenir; ikinci adımda kalanın yarısı olan 125.000 de elenir. İki adımda toplam 375.000 kayıttan kurtulunur. İkili aramanın güzelliği budur.

> **Ek bilgi (derste anlatılmadı):** Her adımda aday sayısı yarıya indiği için ikili arama en kötü durumda yaklaşık $\lceil \log_2 n \rceil$ karşılaştırmada biter. Sıralı aramada ise en kötü durumda $n$ karşılaştırma gerekir.

## 14. Newton'un Karekök Algoritması

Daha sayısal bir örnek olarak karekök hesabı ele alındı. 64'ün karekökünün 8, 4'ün karekökünün 2 olduğu bilinir. Karekök hesaplamak için Newton'un ortaya attığı iteratif (yinelemeli) bir yöntem vardır. Her adımda bir önceki adımda bulunan değer üzerinden devam edilir ve adım adım sonuca yaklaşılır. Her adımda şu kontrol edilir: önceki adımın sonucuyla şimdiki adımın sonucu arasındaki fark belli bir $\varepsilon$ (epsilon) değerinden küçük mü?

Slayttaki algoritma (ekrandan, 01:55:00):

- Başlangıç tahmini 1'dir.
- Tahmin yeterince yakın olmadığı sürece tahmin şu formülle tekrar tekrar iyileştirilir:

```text
newApproximation = (oldApproximation + N/oldApproximation)/2
```

LaTeX ile:

$$\text{yeni} = \frac{\text{eski} + \dfrac{N}{\text{eski}}}{2}$$

Hoca parantezlere ve bölmelerin yerine dikkat edilmesini istedi: $N$ eski tahmine bölünür, sonuç eski tahminle toplanır, toplam 2'ye bölünür.

### 14.1 1024'ün karekökü

Slayttaki örnek $N = 1024$'tür (ekrandan, 01:55:00).

- **1. adım:** $(1 + 1024/1)/2 = 1025/2 = 512{,}5$.
- **2. adım:** $(512{,}5 + 1024/512{,}5)/2 = (512{,}5 + 1{,}998...)/2 \approx 257{,}249$.
- **3. adım ve sonrası:** Bulunan değer eski tahmin yerine konur ve aynı işlem tekrarlanır.

Slayttaki tahmin dizisi şöyledir:

```text
Initial approximation = 1
Next approximation = 512.5
Next approximation = 257.2490243902439
Next approximation = 130.16480157022683
Next approximation = 69.22732405448894
Next approximation = 42.00958563100827
Next approximation = 33.19248741685438
Next approximation = 32.02142090500024
Next approximation = 32.0000071648159
Next approximation = 32.0000000000008
Next approximation = 32
```

> **Ders sonrası not:** Python ile hesaplanan üçüncü tahmin `130.61480157022683`'tür; slayttaki `130.16480157022683` değerinde iki rakamın yeri değişmiştir. Diğer değerler python sonucuyla uyuşur (son basamaklardaki kayan nokta farkları dışında).

### 14.2 Ne zaman durulur?

Her yeni değerde eski değerle aradaki farka bakılır. 1 ile 512,5 arasındaki fark yaklaşık 511, 512,5 ile 257 arasındaki fark yaklaşık 255, 257 ile 130 arasındaki fark yine büyüktür. İstenen hassasiyete göre $\varepsilon$ mümkün olduğunca küçük seçilir. $\varepsilon$ yaklaşık $10^{-12}$ gibi çok küçük bir değerse 32 tam olarak bulunur.

> **Ders sonrası not:** Hoca $\varepsilon = 0{,}01$ ile sonucun 32,0000071... civarında kalacağını söyledi. "Yeni ile eski tahmin arasındaki fark $\varepsilon$'dan küçükse dur" kuralıyla 32,0214'ten 32,0000071648'e geçişteki fark yaklaşık 0,0214'tür ve hâlâ 0,01'den büyüktür. Algoritma bir adım daha gider ve fark yaklaşık $7 \times 10^{-6}$ olunca 32,0000000000008'de durur (python ile kontrol edildi).

Hoca, işlemler yarıya bölerek ilerlediği ve hızlı yakınsadığı için yöntemin logaritmik mertebede bir karmaşıklığı olduğunu söyledi.

## 15. Akış Diyagramları

Problemler için algoritmik çözümler üretmek ve bunları ifade etmek gerekir. Bu dersteki temel ifade biçimi akış diyagramlarıdır. Slaytta bir örnek akış (Start → Process 1 → Decision → No: Process 2 / Yes: Process 3) ile "elemanlar" (elements) ve "bağlantılar" (connections) başlıkları görülür (ekrandan, 02:00:00).

Akışın elemanları şunlardır: başlangıç ve bitişi gösteren Start ve Stop; kullanıcıdan ya da başka bir yerden bilgi okumayı gösteren girdi kutuları; bütün bileşenleri birbirine bağlayan bağlantılar; işlemleri ve ifadeleri gösteren kutular; karar noktaları ve tekrarlı kontrolleri sağlayan döngüler. Örneğin Newton iterasyonunda her seferinde yeni ve eski değer arasındaki farkın $\varepsilon$'dan küçük olup olmadığına bakılır; bu, döngü içinde sürekli verilen bir karardır.

### 15.1 Start ve Stop

Her akışın bir başlangıcı ve bir bitişi olmak zorundadır. Başlangıç için eliptik bir şekil çizilir, içine Start yazılır ve altından bir okla çıkılır. Sonraki sembol akışa bağlıdır. Dışarıdan bilgi gerekiyorsa büyük olasılıkla bir girdi kutusu gelir. Doğrudan işlemle başlamak pek mümkün değildir, çünkü ilk değer verilmemiş (initialize edilmemiş) değerler üzerinde işlem yapılamaz.

> **Hocanın vurgusu:** Akış bir noktadan başlayıp beş farklı noktada bitemez. Her akışın tek bir noktada, tek bir şekilde bitmesi beklenir.

Start ile başlayan akış Stop ile biter; Start'ın sonuna End yazılmaz. Begin ile başlanırsa sonuna End yazılır. Uyum için Start–Stop ve Begin–End çiftleri korunur.

### 15.2 Girdi (input) kutusu

Girdi kutusu sol üst köşesi kesik bir dikdörtgendir. Bu şekil tarihçe dersinde görülen delikli kartlara benzer; o kartların ve sonra kullanılan kâğıt şeritlerin kenarı da benzer şekilde kesikti. Şekil bir bilgi alışını ifade eder. Bilgi kullanıcıdan, bir dosyadan ya da başka bir programın çıktısından gelebilir.

Slayttaki kurallar (ekrandan, 02:05:00):

- Girdi kutusu kullanıcının verdiği değişkenleri gösterir.
- Değişkenler virgülle ayrılır.
- Dizi okumanın iki yolu vardır: girdi kutusunu bir FOR döngüsü içinde kullanmak ya da `A(N)` gösterimini kullanmak.
- `A(N)`'den önce N değişkeni okunmalıdır.

Slayttaki kutunun içinde `N,M, A(N)` yazar (ekrandan, 02:05:00). Karekök örneğinde N bilinmeyendir ve dışarıdan verilmelidir; bu yüzden girdi kutusuna N yazılır. Birden fazla değer (N, M, X, Y, Z) okunabilir. Dizi okunurken önce dizinin eleman sayısı N okunur, sonra normal parantezle `A(N)` yazılarak N elemanlı A dizisinin okunduğu gösterilir. Bu aslında bir kısaltmadır; normalde bir FOR döngüsü içinde her adımda A'nın bir elemanı okunur.

### 15.3 Oklar ve bağlantı daireleri

Start'ın, Stop'un ve girdi kutusunun çevresinde hep oklar vardır; oklar işlemin gidiş yönünü gösterir. Girdi kutusuna üstten girilir, yani önceki işlem bunun üstündedir; işlem bitince altından çıkılır.

Slayttaki kurallar (ekrandan, 02:10:00):

- Oklar akışın iki elemanını bağlar ve akışın yönünü gösterir.
- Oklar dikdörtgen biçimde (düz ya da dik açılı) ilerler; eğri ok yanlıştır.
- Daireler bağlantıları sadeleştirmek için kullanılır (iç içe döngüler, iç içe kontroller vb.); numaralandırmaya dikkat edilmelidir.

Oklar ya tamamen düz ya da keskin köşeli çizilmelidir; "virajlı dağ yolu" gibi çizilmemelidir. Akış çizmeye kâğıdın sol üstünden başlayıp sonra kâğıdın bir tarafında sıkışmak sık yaşanır. Çizginin gidemediği bir yerde ya da başka sayfaya geçerken okun ucuna bir daire çizilir ve içine bir sayı yazılır. Yolun devam edeceği yere aynı sayılı yeni bir daire çizilir ve oradan çıkan ok gideceği yere bağlanır. Hocanın benzetmesiyle bu daireler bir taraftan öbür tarafa geçiş sağlayan kara delikler gibidir. Ama akışta beş on daire olması okunabilirliği düşürür; daireler yalnız ihtiyaç anında ve mümkün olduğunca az kullanılmalıdır.

> **Hocanın vurgusu:** Akış, bir problemin çözümünü karşı tarafa anlatmak için oluşturulur. Onu anlamak için önce başka bir dil öğrenmek gerekiyorsa iş baştan patlamış demektir. Bu derste tariflenen kurallara harfiyen uyulmalıdır; eğri oklarla çizilmiş bir akış kabul edilmez.

### 15.4 İşlem kutuları

İşlem kutularında ifadeler yazılır: neyle neyin toplanıp sonucun nereye atılacağı gibi. Örneğin `a` değişkenindeki değer bir artırılacaksa kutuya `a = a + 1` yazılır.

İşlem kutularına da üstten girilip alttan çıkılır. Sağdan girip soldan çıkmak, soldan girip alttan çıkmak ya da alttan girip iki yandan çıkmak yoktur. Bu, akışın sürekliliği ve takibi içindir.

Kutulardaki ifadeler programlama diline özgü olmamalıdır. Dersin başında konuşulan aritmetik, mantıksal ve bitwise operatörlerle genel ifadeler yazılmalıdır.

### 15.5 Karar noktası: IF

Karar noktalarının en bilineni IF'tir; bir şartın kontrol edildiği yerdir. Slayttaki örnekte yukarıdan bir ok gelir ve bir altıgene girer (ekrandan, 02:15:00). Altıgenin alt ve üst kenarları uzun, diğer kenarları kısadır; uzun kenarlar içeriye ifade yazmak için yer açar. Koşul sağlanabilir ya da sağlanmayabilir (true ya da false); bu yüzden altıgenin iki yanında iki çıkış vardır.

Hangi çıkışın true, hangisinin false olduğu çıkışların üstüne T ve F yazılarak belirtilir. Slaytta sağ taraf T, sol taraf F'dir; tersi de olabilir. Ama etiket mutlaka olmalıdır, yoksa hangi kolun neyi gösterdiği bilinemez.

Slayttaki kurallar (ekrandan, 02:15:00):

- IF'lerde her zaman True ve False kolları belirtilir.
- Her IF'in True kolu olmak zorundadır.
- False kolu isteğe bağlıdır.
- Her IF'te F ve T kollarını aynı tarafta kullanmak iyi bir fikirdir.

Akışta birden fazla IF varsa true kolları sağdaysa hep sağda, soldaysa hep solda olmalıdır; akış kendi içinde tutarlı olmalıdır.

Slayttaki örnekte koşul `A = B`'dir. False durumunda soldan çıkılır, bir işlem kutusuna girilir ve çıkılır. True durumunda sağdan çıkılır, başka bir işlem kutusuna girilir ve çıkılır. İki koldan çıkan oklar bir noktada birleşir.

> **Hocanın vurgusu:** Bir IF'in iki kolu, normal akışa devam edebilmek için mutlaka bir noktada birleşmelidir. Birbirinden bağımsız dallanıp budaklanan kollar çizilemez.

Slayttaki örnekte bilerek konmuş bir tuhaflık da vardır: şart sağlanınca da sağlanmayınca da `A = A + 1` yapılır. İki durumda da aynı şey yapılıyorsa şarta gerek yoktur; bu temel bir mantık hatasıdır.

Genel prensip, hatta bazı programlama dillerinde kural şudur: koşul doğru olduğunda yapılacak bir işlem olmalıdır. "A = B ise hiçbir şey yapma, değilse şunu yap" yazılmaz. Günümüzde çoğu dil buna izin verse de bir kısmı vermez; üstelik okunabilirliği ciddi biçimde bozar. Böyle bir durumda koşul yanlış kurulmuştur: eşitlik yerine eşit olmama durumuna bakılmalı ve yapılacak iş True kolunda halledilmelidir. Bunun tersi yalnız amaç kod karartma (code obfuscation) ise yapılır; yani kodun anlaşılmasını zorlaştırıp başkasının çalmasını ya da değiştirmesini engellemek için. Bu da elle değil, obfuscator araçlarıyla yapılır.

**Soru:** İkiden fazla koşul varsa, örneğin programlamadaki "else if" yapısı akışa nasıl dökülür? **Cevap:** Bu iç içe (nested) IF demektir. Örnekte `A = B` koşulu false ise sol koldaki işlem kutusunun yerine yeni bir IF çizilir. Bu IF'in true ve false kollarında işlemler yapılır ve bu iki kol birleşir. Sonra bu birleşme noktasından çıkan ok, dıştaki IF'in true kolundan gelen okla bir kez daha birleşir. Yani iç içe IF'lerde önce içteki IF'in kolları, sonra bu birleşme ile dıştaki IF'in diğer kolu birleştirilir. Else if gibi yapıların hangi dilde nasıl yazılacağı ve hangisinin daha verimli olacağı, programlama diline geçilince düşünülecek bir konudur; akışta böyle bir kaygı yoktur.

### 15.6 FOR döngüsü

Döngülere FOR ile başlanır, çünkü daha basit ve temizdir: kaç adım ilerleneceği bellidir. Hoca örneği önce "10 elemanlı dizinin en küçüğünü bulmak" diye verdi, sonra bunun erken çıkma ihtimali olduğunu söyleyip değiştirdi: 10 elemanlı bir dizinin ortalamasını bulmak. Bunun için bütün elemanlar toplanıp eleman sayısına bölünür; bütün dizi gezilmesi gerektiği ve adım sayısı bilindiği için FOR kullanılabilir.

Slayttaki kurallar (ekrandan, 02:20:00):

- FOR döngüleri belirli sayıda yinelemeli bir döngü kurmak için kullanılır.
- Üç parçası vardır: başlangıç koşulu (initial conditioning), bitiş koşulu (terminating condition), artım/azaltım (increment/decrement).

Slayttaki FOR kutusunun sol üstünde `J ← 1`, iki dik çizgiyle ayrılmış sağ üst bölümde `1`, alt bölümde `N` yazar. Kutunun yanından çıkan ok `A = A + 1` kutusuna gider ve oradan dönüp FOR kutusunun sağ üst tarafına girer; döngü bitince kutunun altından çıkılır (ekrandan, 02:20:00).

- `J ← 1`: döngüye başlanınca J değişkenine 1 atanır.
- `1`: her adımda J'nin bir birim artırılacağını gösterir.
- `N`: J'nin son değeridir.

Çalışması şöyledir: J = 1 ile başlanır, A bir artırılır, FOR kutusuna dönülür. J 2 olur; 2, N'den küçük olduğu için devam edilir ve A yine artırılır. Bu, J = N olana kadar sürer ve J = N'de de işlem bir kez daha yapılır. Sonraki artışta J, N'den bir fazla olur ve döngüden çıkılır. Böylece işlem $N$ kez yapılır.

### 15.7 WHILE döngüsü

Tekrarlar bir koşula bağlıysa WHILE döngüsü kullanılır. WHILE sembolü IF'e benzer, ama IF'in sağından ve solundan ok çıkarken WHILE'da ok alt kenardan çıkar. Bu okla işlemler yapılır ve dönülüp sembolün sağ üst kenarından tekrar girilir; bu çizim sembolün bir WHILE döngüsü olduğunu gösterir. Döngüye yukarıdan girilir, döngü bitince yine alttan çıkılır.

Örnekteki koşul J'nin N'den küçük olmasıdır. J, N'den küçük olduğu sürece döngü çalışır. Döngünün içinde J'nin ya da N'nin değerini değiştiren bir şey olmalıdır. Örnekteki gibi döngüde yalnız `A = A + 1` hesaplanıyorsa koşul hiç değişmez ve döngüden çıkılamaz.

<!-- BELİRSİZ: WHILE slaytı karelerde yok; sembolün şekli ve ok yönleri altyazıdaki anlatımdan aktarıldı. -->

Hoca bunların akış diyagramlarının temel bileşenleri olduğunu ve sonraki haftadan başlayarak basit problemler üzerinde çizim yapılacağını söyledi.

## 16. Sözde Kod (Pseudocode)

Şimdilik kulak dolgunluğu olarak konuşulan ve programlama diline (C'ye) geçildikten sonra dönülebilecek bir yöntem de sözde koddur (pseudocode). Programlama dillerindeki temel kavramların bir kısmını kullanarak ya da biraz değiştirerek bir problemin çözümünün nasıl olması gerektiğini ifade eder.

Slayttaki maddeler (ekrandan, 02:25:00):

- Algoritmayı ifade etmenin farklı bir yoludur.
- İnsanın okuyabileceği yönergeler ile programlama kodlarının birleşimidir.
- Birkaç farklı şekilde yazılabilir.
- Girdiler ve çıktılar her zaman tanımlanmalıdır.
- Mümkünse ara değişkenlerin tipleri gösterilmelidir.
- Satırları numaralamak iyi bir fikirdir.

Sözde kodun net bir standardı yoktur; "IEEE'nin şu standardı" denebilecek bir durum yoktur. Bazı yazımlarda satırlar alışkanlıkla numaralanır; bu, bir hata olduğunda hangi satırda ne olduğunu ve neyin değişmesi gerektiğini bulmayı kolaylaştırır. Bazıları bir programlama dilinden etkilenip ona benzer komutlar kullanır, bazıları tamamen bağımsızdır. Bu yüzden sözde kod aranınca çok farklı biçimler görülebilir.

Slayttaki sağdaki örnek satır numaralı bir sözde koddur (ekrandan, 02:25:00):

```text
Input: A nonempty string of characters S1 S2 ... Sn, and a positive
       integer n giving the number of characters in the string.
Output: See the related problem below.
Procedure:
 1 Get n
 2 Get S1 S2 ... Sn
 3 Set count = 1
 4 Set ch = S1
 5 Set i = 2
 6 While i <= n
 7   If Si equals ch
 8     Set count = count + 1
 9   Set i = i + 1
10 Print ch, ' appeared ', count, ' times.'
11 Stop
```

Soldaki örnek ise iç içe FOR döngüleriyle bir izdüşüm matrisini küçülten `REDUCE(projection, x, y, f)` algoritmasıdır; hoca bu örneklerin ayrıntısına girmedi.

Akış diyagramlarında da farklı alanlarda (elektrik, makine, inşaat mühendisliği) farklı semboller ve kullanımlar görülebilir. Bu ders için temel olan, hocanın gösterdiği yapıdır; başka kullanımlar sorun sayılır ve buradaki standart izlenmelidir.

## Örnek Sorular

**1. Mod işlemi** (derste sözlü, 00:06:12)

7'nin 2'ye göre modu nedir?

**Çözüm:** 7, 2'ye tam bölünmez; $7 = 3 \cdot 2 + 1$, kalan 1'dir. 7 mod 2 = 1.

**2. Bitwise AND** (ekrandan, 00:15:00)

$A = 60$ (`0011 1100`) ve $B = 13$ (`0000 1101`) için $A \,\&\, B = ?$

**Çözüm (derste sağdan adım adım verildi):** Sağdan 0&1 = 0, 0&0 = 0, 1&1 = 1, 1&1 = 1, kalan bitler 0. Sonuç `0000 1100` = 12.

**3. Bitwise OR** (ekrandan, 00:20:00)

Aynı A ve B için $A \,|\, B = ?$ Sonucun ondalık karşılığı nedir?

**Çözüm:** `0011 1101` = 61. Kısayol: B'de A'dan farklı tek bit en sağdaki 1'dir; A'nın en sağ biti 0 olduğundan sonuç 60 + 1 = 61.

**4. XOR** (ekrandan, 00:25:00)

Aynı A ve B için $A$ XOR $B = ?$

**Çözüm:** Bitler farklıysa 1, aynıysa 0: `0011 0001`.

> **Çözüm (derste verilmedi):** Ondalık karşılık $32 + 16 + 1 = 49$'dur (python ile kontrol edildi).

**5. Shift** (ekrandan, 00:30:00 ve 00:40:00)

$A = 60$ için $A \ll 2$ ve $A \gg 3$ nedir? Ara adımlardaki değerler nelerdir?

**Çözüm:** $A \ll 1 =$ `0111 1000` = 120, $A \ll 2 =$ `1111 0000` = 240. $A \gg 1 =$ `0001 1110` = 30, $A \gg 2 =$ `0000 1111` = 15, $A \gg 3 =$ `0000 0111` = 7. Sola kaydırma 2 ile çarpma, sağa kaydırma 2'ye tam sayı bölmedir.

**6. Shift'te sınır** (derste sözlü, 00:35:59 ve 00:38:59)

$A = 60$ sağa dört kez kaydırılırsa ne olur? Sola üç kez kaydırılırsa ne olur?

**Çözüm:** Sayı 8 bittir ve boşalan yere hep 0 gelir. Dördüncü sağa kaydırmada `0000 0011` (3) elde edilir. Sola üç kez kaydırmada 9. bit olmadığı için en soldaki 1 kaybolur: `1110 0000`.

> **Çözüm (derste verilmedi):** Ondalık karşılıklar python ile 3 ve 224 bulunur. Derste dördüncü kaydırmanın değeri yüksek sesle okunmadı.

**7. Neden ikilik sistem?** (derste sözlü, 00:43:14)

Bilgisayarlar neden ondalık değil de ikilik sayı sistemini kullanır?

**Çözüm (derste verildi):** Elektrik sinyalleri gürültülüdür. İkilik sistemde 0 ve 1 için geniş güvenli gerilim bantları (slayttaki örnekte 0,0–0,5 V ve 2,8–3,3 V) ayrılabilir. Aynı aralığa on seviye koymak her seviyeye yaklaşık 0,33 V bırakır ve iki yönden hataya açıktır. Gerilimi büyütmek ise geçişleri yavaşlatır ve geçiş sürelerini eşitsizleştirir. İkilik sistem daha dayanıklı, daha hızlı ve daha basittir.

**8. Elle toplama yöntemini tarif edin** (ekrandan, 01:25:00)

$123456 + 789001 = 912457$ işleminin nasıl yapıldığını, bir algoritma olarak tarif edin.

**Çözüm (derste tartışıldı):** Sağdan başlayarak her basamakta iki sayının basamakları ve önceki basamaktan gelen elde toplanır. Toplamın birler basamağı sonuca yazılır, onlar basamağı elde olarak sonraki basamağa aktarılır. En soldaki basamaktan sonra elde kalırsa o da sonucun en soluna yazılır. Hoca tarifin uç durumu (en soldaki basamak) ve genelliği (ikiden fazla sayı toplanınca eldenin 1'den büyük olabilmesi) kapsaması gerektiğini vurguladı.

**9. En yaşlıyı bulma** (ekrandan, 01:40:00)

Bir oda dolusu insan içinde en yaşlı kişi nasıl bulunur? Varsayımlar nelerdir ve iki tasarımın adım sayıları nasıl karşılaştırılır?

**Çözüm (derste verildi):** Varsayımlar: herkes gerçek doğum gününü söyler, aynı gün doğanlar aynı yaştadır, birden fazla en yaşlı varsa biri yeterlidir. Sıralı tasarımda kâğıt elden ele dolaşır, $n$ kişi için $n$ adım gerekir. Paralel tasarımda kişiler eşlenip karşılaştırılır ve her adımda aday sayısı yarıya iner; adım sayısı $\log_2 n$ civarındadır. 100 kişi için 128'e yuvarlanırsa 7 adım ($2^7 = 128$).

**10. Newton yöntemiyle 1024'ün karekökü** (ekrandan, 01:55:00)

Başlangıç tahmini 1 olmak üzere $\text{yeni} = (\text{eski} + N/\text{eski})/2$ formülüyle $\sqrt{1024}$'ün ilk adımlarını hesaplayın.

**Çözüm (derste verildi):** $(1 + 1024)/2 = 512{,}5$; $(512{,}5 + 1024/512{,}5)/2 \approx 257{,}249$; sonra yaklaşık 130,6; 69,2; 42,0; 33,19; 32,021; 32,0000072; 32,0000000000008 ve 32. Ardışık iki tahmin arasındaki fark $\varepsilon$'dan küçük olunca durulur.

**11. Sözde kod izleme** (ekrandan, 02:25:00)

Slayttaki sözde kod için: Problem 1.1, girdi `pepper` ise ne yazdırılır? Problem 1.2, girdi `CACCTGGTCCAAC` ise ne yazdırılır?

> **Çözüm (derste verilmedi):** Algoritma ilk karakteri `ch` olarak alır ve dizide kaç kez geçtiğini sayar (`count` 1'den başlar, 2. karakterden itibaren `ch`'ye eşit her karakter için 1 artar). `pepper` için `ch = p`; p, 1., 3. ve 4. karakterlerdedir, çıktı: `p appeared 3 times.` `CACCTGGTCCAAC` için `ch = C`; C, 1., 3., 4., 9., 10. ve 13. karakterlerdedir, çıktı: `C appeared 6 times.` (python ile kontrol edildi; boşluklar slayttaki Print satırındaki tırnaklara göre yazıldı).

## Dersin Toparlaması

Bu derste önce akış diyagramlarında kullanılacak ortak dil kuruldu: aritmetik (`+ - * / mod`), ilişkisel (`> < >= <= =` ve $\neq$) ve mantıksal (AND, OR, NOT) operatörler. Ardından bitwise AND, OR, XOR, shift ve rotate işlemleri 60 ve 13 sayıları üzerinde adım adım çalışıldı. Sola kaydırmanın 2 ile çarpma, sağa kaydırmanın 2'ye tam sayı bölme olduğu ve ikilik sistemde doğrudan düşünmenin önemi vurgulandı. Sonra bilgisayarın neden ikilik sistem kullandığı gerilim bantları üzerinden açıklandı. Verinin bitlere eşlenmesi (ASCII, UTF), negatif sayılar (bire ve ikiye göre tümleyen), IEEE kayan nokta biçimi, bit-nibble-byte-word adları, bellek adresleme ve little/big endian konuşuldu.

Dersin ikinci yarısında algoritma kavramına geçildi: belirsizlik içermeyen, sonlanan, iyi tanımlı adımlar. Elle toplama ve en yaşlıyı bulma örnekleri, bir tarifin uç durumları ve genel durumu kapsaması gerektiğini, aynı problemin sıralı ($n$ adım) ve paralel ($\log_2 n$ adım) çözümlerinin karmaşıklık açısından çok farklı olabileceğini gösterdi. Sıralı ve ikili arama ile Newton'un karekök algoritması da bu bakışla incelendi. Son olarak akış diyagramlarının temel bileşenleri (Start/Stop, girdi, işlem, IF, FOR, WHILE, oklar ve bağlantı daireleri) kurallarıyla tanıtıldı ve sözde koddan kısaca söz edildi. Hoca, sonraki haftadan itibaren basit problemler üzerinde akış diyagramı çizimine başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
