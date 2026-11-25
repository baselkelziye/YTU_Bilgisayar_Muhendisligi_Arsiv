# Ders 4 Genişletilmiş Notu: Çarpma ve Bölme, Mantıksal Komutlar, Dallanma ve Yığın Komutları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çarpma ve Bölme Komutlarına Giriş: İşaretli ve İşaretsiz
- 2. MUL ve IMUL
- 3. Sayı Yazımı ve emu8086 ile Deneme
- 4. DIV ve IDIV
- 5. Örnek: Celsius'tan Fahrenheit'e Dönüşüm
- 6. Mantıksal Komutlar
- 7. TEST ile Bit Sınama ve Maskeleme
- 8. Dallanma Komutlarına Giriş
- 9. Koşullu Dallanma Komutları
- 10. İşlemci Koşullara Nasıl Karar Verir
- 11. Koşulsuz Dallanma, Çağırma ve Dönüş Komutları
- 12. if Yapılarının Assembly Karşılığı
- 13. Yığın Komutları
- Örnek Sorular

## 1. Çarpma ve Bölme Komutlarına Giriş: İşaretli ve İşaretsiz

Ders, önceki haftada başlanan aritmetik komutların kalan kısmıyla, yani çarpma ve bölme komutlarıyla açıldı. Dört komut vardır:

| | Çarpma | Bölme |
|---|---|---|
| İşaretsiz | MUL | DIV |
| İşaretli | IMUL (integer multiplication) | IDIV (integer division) |

Bu ayrımın özü şudur: bellekteki ya da yazmaçtaki bit gösterimi tektir ve kendi başına işaretli ya da işaretsiz değildir. Örneğin `1111 1111B` gösterimi MUL ile kullanılırsa 255, IMUL ile kullanılırsa −1 olarak değerlendirilir. Aynı durum DIV ve IDIV için de geçerlidir. Bir gösterim ancak kullanıldığı komutla işaretli ya da işaretsiz anlam kazanır. Bu fikir ders boyunca, koşullu dallanma komutlarında da yeniden karşımıza çıktı.

## 2. MUL ve IMUL

### 2.1 Gizli operandlar

MUL tek bir operand alır. Bu operand 8 ya da 16 bitlik olabilir ve hangi işlemin yapılacağını onun genişliği belirler. Diğer operand ve sonucun yeri komutta yazılmaz; bunlara gizli operandlar denir.

- Operand 8 bitlikse: `AX ← AL · src`. İki 8 bitlik sayının çarpımı 16 bite sığar.
- Operand 16 bitlikse: `DX:AX ← AX · src`.

Hoca burada sınıfa iki 16 bitlik sayının çarpımının kaç bite sığdığını sordu; cevap 32 bittir. 8086'da 32 bitlik bir yazmaç yoktur. Bu yüzden işlemci DX ve AX'i birlikte sanal bir 32 bitlik yazmaç gibi kullanır: 32 bitlik sonucun yüksek anlamlı 16 biti DX'e, düşük anlamlı 16 biti AX'e yazılır.

**Soru:** `MUL AL` ne yapar? **Cevap:** AL'nin karesini alıp sonucu AX'e yazar.

`MUL BX` ise `DX:AX ← BX · AX` işlemini yapar. Bu yüzden çarpmadan önce AX'e (8 bitlik işlemde AL'ye) uygun değer önceden yüklenmelidir.

### 2.2 Operand türleri

Operand bir yazmaç ya da bir bellek adresi olabilir. `MUL [100H]` yazmak yetmez, çünkü 100H adresinden başlayan bir byte'ın mı yoksa bir word'ün mü çarpılacağı belli değildir. Bu durumda `MUL BYTE PTR [100H]` ya da `MUL WORD PTR [100H]` yazılmalıdır. Sonuç yine 8 bitlik işlemde AX'te, 16 bitlik işlemde DX:AX'te saklanır.

> **Hocanın vurguladığı:** Çarpma ve bölme komutlarında en sık yapılan hata operand olarak sabit (immediate) değer vermektir. `IMUL -1000` gibi bir yazım geçersizdir; operand ya yazmaç ya bellek adresi olmalıdır.

### 2.3 Örnek: 130 · 552

Hoca, 130 · 552 işleminin 8086'da nasıl yapılacağını sordu ve sayıların onluk yazıldığına dikkat çekti: 130 sekiz bite sığar, ama 552 sığmaz. Sayılar onaltılık olsaydı ikisi de farklı değerlendirilirdi. Bu yüzden 16 bitlik çarpma gerekir (ekrandan, 00:15:00):

```asm
MOV AX, 552
MOV BX, 130
MUL BX        ; DX:AX <- BX * AX
```

`MOV AX, 552` yazıldığında assembler onluk 552'yi ikiliğe çevirip AX'e yükler. Çarpmadan sonra DX:AX'te çarpım bulunur, BX değişmez (130 kalır). Hoca sonucu Windows hesap makinesinin programcı kipinde double word olarak hesaplayıp tahtaya şöyle yazdı (ekrandan, 00:20:00): DX ← 0001H, AX ← 0914H, BX ← 130.

> **Ders sonrası not:** Hesap makinesine 552 yerine 522 girilmişti (altyazıda "130 çarpı 522"); 0001 0914H, 130 · 522 = 67860'ın karşılığıdır. 130 · 552 = 71760 = 0001 1850H olduğu için doğru sonuç DX = 0001H, AX = 1850H'dir (python ile doğrulandı).

### 2.4 IMUL

IMUL'un çalışması tamamen MUL ile aynıdır: 8 bitlik operandla `AX ← AL · src`, 16 bitlik operandla `DX:AX ← AX · src`. Tek fark, operandları işaretli sayı olarak değerlendirmesidir. Yine yazmaç ya da (PTR ile boyutu belirtilmiş) bellek operandı alabilir.

Örnek (ekrandan, 00:20:00): (−2) · (−1000).

```asm
MOV AX, -2        ; AX <- 0FFFEH
MOV BX, 0FC18H    ; BX <- 1111 1100 0001 1000 (-1000)
IMUL BX
```

- −1 word olarak 0FFFFH'dir; bir aşağısı −2 = 0FFFEH'dir.
- −1000 word olarak FC18H'dir. Bu gösterim işaretsiz okunursa 64536, işaretli okunursa −1000'dir. Hoca bunu da hesap makinesinde gösterdi. Komutta onluk `-1000` ya da onaltılık `0FC18H` yazmak eşdeğerdir.

IMUL sonrasında DX = 0000H, AX = 07D0H = 2000 olur. Yüksek anlamlı biti 0 olduğu için sonuç pozitiftir.

**Soru:** Onaltılık sayının başına neden 0 yazdık? **Cevap:** Assembler'da harfle (A–F) başlayan onaltılık bir sayının başına 0 konmazsa, assembler onu bir etiket sanar ve hata verir. Başa 0 konunca sayı olarak tanınır. Hoca bunu el alışkanlığı olarak hep yaptığını söyledi.

## 3. Sayı Yazımı ve emu8086 ile Deneme

### 3.1 Sabit yazım biçimleri

Bir öğrencinin sorusu üzerine hoca, önceki haftada görülen yazım biçimlerini özetledi:

- `MOV AX, 10`: sonda harf yoksa sayı onluktur.
- `MOV AL, 01101001B`: B ile biten sayı ikiliktir.
- `MOV BL, 28H`: H ile biten sayı onaltılıktır.
- Tırnak içinde bir karakter yazılırsa (örneğin küçük `a`) o karakterin ASCII karşılığı atanır.

### 3.2 emu8086

EXE ya da COM programları yazmaya geçene kadar komutları denemek için hoca emu8086 emülatörünü önerdi. Bazı komutlarda hataları olsa da sistemin nasıl çalıştığını açıkça gösterir. Kod yazılıp "emulate" denince, sözdizimi hatası yoksa hata ayıklama ekranı açılır. Burada:

- Adım adım (single step) ilerlenebilir, bir adım geri (step back) de gidilebilir.
- Yazmaçlar, bayraklar (view → flags), bellek, yığın ve tanımlı değişkenler izlenebilir.

(−2) · (−1000) kodu emu8086'da çalıştırılırken üçüncü satıra yanlışlıkla `MUL BX` yazılmıştı. Ekranda DX = FC16H, AX = 07D0H görüldü (ekrandan, 00:25:00). Hesap makinesinde bu sayının yüksek anlamlı biti F yüzünden 1'dir. Hoca sonucun bu kadar büyük çıkmasının nedenini MUL kullanılmasına bağladı: 0FFFEH ve 0FC18H işaretsiz olarak (65534 ve 64536) çarpılmıştı. Komut IMUL yapılınca DX = 0, AX = 07D0H = 2000 elde edildi.

**Soru:** Çarpmanın sonucunun DX ve AX'e nasıl yazıldığını anlamadım. **Cevap:** 16 bitlik çarpma 32 bitlik sonuç üretir. İşlemci bu 32 bitlik sonucun yüksek anlamlı 16 bitini DX'e, düşük anlamlı 16 bitini AX'e yazar. (−2) · (−1000) örneğinde yüksek anlamlı 16 bit 0 çıktığı için tahtaya ayrıca yazılmadı.

## 4. DIV ve IDIV

### 4.1 DIV

DIV işaretsiz bölme yapar ve hem bölümü hem kalanı saklar.

- Operand 8 bitlikse gizli operand AX'tir: AX operanda bölünür, bölüm AL'ye, kalan (modulo) AH'ye yazılır.
- Operand 16 bitlikse yüksek anlamlı 16 biti DX'te, düşük anlamlı 16 biti AX'te olan sanal 32 bitlik sayı operanda bölünür. Bölüm AX'e, kalan DX'e yazılır.

Demek ki 16 bitlik bölmeden önce bölünecek değer DX ve AX'te hazırlanmalıdır. Operand yine yazmaç ya da boyutu PTR ile belirtilmiş bellek adresi olabilir.

### 4.2 Bölmede taşma

Hoca riskli bir durum sordu (ekrandan, 00:30:00): DX = FFFFH, AX = FFFFH, BX = 1 iken `DIV BX`.

- Bir öğrenci sonucun yine 16 bitlik çıkacağını söyledi.
- DX:AX birleştirilince FFFF FFFFH elde edilir. Bu 32 bitlik sayı 1'e bölünürse bölüm de 32 bitliktir ve AX'e sığmaz.

Yani bölmede de taşma olabilir. Makul aralıktaki değerlerle çalışıldığında bölümün 16 bite sığması beklenir. Hoca sığmayan sonuçta overflow bayrağının kurulduğunu ve programcının bunu ele alması için bir "overflow kesmesi" oluştuğunu söyledi.

> **Ders sonrası not:** 8086'da bölüm hedef yazmaca (AL ya da AX) sığmazsa büyük olasılıkla overflow bayrağı değil, 0 numaralı kesme (bölme hatası, sıfıra bölmeyle aynı kesme) tetiklenir; bölmeden sonra bayrakların değeri tanımsızdır.

### 4.3 IDIV

IDIV aynı gizli operandları kullanır, ama operandları işaretli sayı olarak değerlendirir. 8 bitlik operandda AX bölünür, bölüm AL'ye, kalan AH'ye; 16 bitlik operandda DX:AX bölünür, bölüm AX'e, kalan DX'e yazılır. Yazmaç ya da bellek operandı alır.

Hoca kavramı yineledi: gösterim tektir. O gösterimin işaretli mi işaretsiz mi olduğu, onu hangi komutla işlediğimize göre belli olur.

## 5. Örnek: Celsius'tan Fahrenheit'e Dönüşüm

### 5.1 Formül

Sınıfla birlikte dönüşüm formülü kuruldu. Suyun donma ve kaynama noktaları tahtaya şöyle yazıldı (ekrandan, 00:35:00):

| °F | °C |
|---|---|
| 212 | 100 |
| y | x |
| 32 | 0 |

Fahrenheit'te 180 birimlik aralık Celsius'ta 100 birime karşılık gelir; buradan $y = 1.8x + 32$ çıkar. Amaç x = −40 °C için y'yi 8086'ya hesaplatmaktır.

### 5.2 1.8 ile çarpma sorunu

8086'nın kesirli sayılarla çalışan bir çarpması yoktur. Bir öğrencinin önerisiyle 1.8 ile çarpmak yerine 18 ile çarpıp 10'a bölmeye karar verildi. İki yazım düşünüldü (ekrandan, 00:40:00):

$$y = \frac{x}{10} \cdot 18 + 32 \qquad \text{ve} \qquad y = \frac{x \cdot 18}{10} + 32$$

Tamsayı bölmesi yapıldığı için birincisi büyük hassasiyet kaybettirir: −10 ile 10 arasındaki her x için $x/10$ sıfır olur, 18 ile çarpınca da sıfır kalır. Bu yüzden ikincisi seçildi.

> **Hocanın vurguladığı:** Prensip olarak önce çarpma, sonra bölme yapılmalıdır.

### 5.3 Kodun adım adım kurulması

İşaretli sayılarla çalışıldığı için IMUL ve IDIV kullanılır. Kod sınıfla birlikte satır satır kuruldu (ekrandan, 00:40:00 ve 00:45:00):

```asm
MOV AL, -40
MOV DL, 18
IMUL DL        ; AX <- AL * DL  (16 bit sonuç)
MOV BL, 10
IDIV BL        ; AL <- AX / BL, AH <- kalan
ADD AL, 32
```

1. `MOV AL, -40` ve `MOV DL, 18` ile çarpanlar yüklenir. 18'in hangi yazmaca konduğu fark etmez.
2. `IMUL DL` sonucu AX'te 16 bitlik bir değerdir. Çarpım (−720) 8 bite sığmaz, ama 16 bite sığar.
3. Ardından 10'a bölme gelir. Burada sınıfta bir tartışma oldu. Önce 16 bitlik bölme düşünüldü: 16 bitlik bölmede DX:AX bölünür; çarpımın düşük yarısı zaten AX'tedir, bu yüzden AX'i başka bir değişkene almaya gerek yoktur, ama DX ile bir şey yapılmalıdır. Bir öğrenci DX'e 10 yazmayı önerdi; bu, bölünen 32 bitlik sayıyı değiştirir. Doğru fikir DX'i sıfırlamaktı. Hoca bunu `XOR DX, DX` ile yazdı ve bunun DX'i sıfırlamakla aynı şey olduğunu, XOR'u biraz sonra göreceklerini söyledi.
4. Sonra bölenin nereye alınacağı soruldu. `MOV BX, 10` ile `IDIV BX` 16 bitlik bölme yapar. Bir öğrenci `MOV BL, 10` ile `IDIV BL` yazılırsa 8 bitlik bölme yapılacağını, bunun AX'i BL'ye böleceğini ve verinin zaten 16 bitlik olduğunu, DX'e hiç dokunmaya gerek olmadığını söyledi. Hoca bunu kabul etti ve kodu 8 bitlik bölmeyle tamamladı.
5. `IDIV BL` sonrası bölüm AL'de, kalan AH'dedir. Kalanla ilgilenilmez.
6. ADD komutu sabit operand aldığı için `ADD AL, 32` ile 32 eklenir. Sonuç AL'dedir.

Sayısal izleme (python ile doğrulandı):

- `IMUL DL`: AX = (−40) · 18 = −720 = 0FD30H.
- `IDIV BL`: AL = −720 / 10 = −72 (0B8H), AH = 0.
- `ADD AL, 32`: AL = −72 + 32 = −40.

Yani −40 °C = −40 °F. Sınıfta önce "−72" sonucu konuşuldu; bu, 32 eklenmeden önceki değerdir. 32 eklenince −40 elde edildi.

> **Ders sonrası not:** Sınıfta konuşulan `XOR DX, DX` yolu bu örnekte doğru sonuç vermezdi: AX = 0FD30H (negatif) iken DX sıfırlanırsa DX:AX = 0000FD30H = 64816 olur, yani pozitif bir sayı bölünür. İşaretli 16 bitlik bölmeden önce DX büyük olasılıkla AX'in işaret bitiyle doldurulmalıdır (bu derste anlatılmadı).

**Soru:** Çarpma 8 biti geçerse kayıp yaşar mıyız? **Cevap:** 8 biti geçmesi sorun değildir, çünkü IMUL sonucu 16 bitlik AX'e yazar. IMUL sonucu işaretli 16 bit aralığını geçerse sorun olur.

Hoca bunun üzerine girdi aralığının analiz edilmesi gerektiğini anlattı. x en fazla 100 alınırsa 100 · 18 = 1800 işaretli 16 bite sığar. Ama x −400 ile 400 arasında değişebilseydi, çarpım işaretli 16 bit aralığını aşabilirdi ve işleme baştan 16 bitlik çarpma ile başlamak gerekirdi.

> **Ders sonrası not:** Hoca x 0–100 aralığında kaldığı sürece bu kodun aynen çalışacağını söyledi. Çarpım AX'e sığar, ama `IDIV BL` bölümü AL'ye yazar. x = 100 için bölüm 180'dir ve işaretli 8 bite (−128..127) sığmaz, bu yüzden bölme taşar. Python ile kontrol edildiğinde bölüm x = 71 için 127, x = 72 için 129'dur; bu kod büyük olasılıkla yalnız x ≤ 71 için doğru çalışır. Daha büyük x için 16 bitlik bölme gerekir.

> **Hocanın vurguladığı:** Çarpma ve bölmenin gizli operandlarının AL, AH, AX, DX ortak olması, art arda çarpma ve bölme gerektiren işlemlerde büyük kolaylık sağlar.

## 6. Mantıksal Komutlar

### 6.1 Bitwise ve lojik işlem

8086'nın mantıksal komutları NOT, AND, OR, XOR ve TEST'tir (ekrandan, 00:55:00). Hepsi bitwise çalışır.

- Lojik işlemde değişkenin bütünü true ya da false sayılır. Örneğin C'de `int var = 0;` boolean olarak false, `int var = 100;` sıfırdan farklı olduğu için true değerlendirilir; içindeki sayının ne olduğu önemli değildir (ekrandan, 00:50:00).
- Bitwise işlemde birinci ve ikinci operandın aynı sıradaki bitleri işleme sokulur ve sonuç birinci operandın o bitine yazılır. Sonra ikinci bitlere geçilir ve böyle devam edilir.

### 6.2 NOT ve NEG

NOT bitwise bire tümleyen alır. Tahtadaki örnek (ekrandan, 00:50:00):

```asm
MOV AL, 5AH
NOT AL        ; AL <- 0A5H
```

Bir öğrenci sonucu onluk düşünüp "101" dedi; hoca bunu ikilik üzerinden gösterdi. 5AH = 0101 1010B'dir. Her bit tersine çevrilince 1010 0101B = 0A5H elde edilir (python ile doğrulandı).

Hoca, önceki hafta görülen ikiye tümleyen komutunu sordu. Bu NEG (negate) komutudur ve operandın negatifini oluşturur:

```asm
MOV AL, 1     ; AL = 0000 0001
NEG AL        ; AL = 0FFH = -1
```

İkiye tümleyenin pratik kuralı: sağdan başlayarak ilk 1'i de dahil edene kadar bitler olduğu gibi bırakılır, sonraki bütün bitlerin değili alınır.

### 6.3 OR, AND, XOR

OR ve AND, bitwise OR ve AND yapar. XOR'un doğruluk tablosu (ekrandan, 00:55:00):

| A | B | Z |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Lojik denklemi $Z = \bar{A}B + A\bar{B}$'dir: bitler aynıysa sonuç 0, farklıysa 1'dir.

`XOR DX, DX` örneğinde DX'in her biti kendisiyle XOR'a girer. Aynı sıradaki iki bit ya ikisi 0 ya ikisi 1 olduğundan her bit 0 olur; DX sıfırlanır.

**Soru:** DX'e doğrudan 0 atamak daha performanslı olmaz mı? **Cevap:** Hayır, `XOR DX, DX` daha kısa sürede yürütülür; aradaki fark bir saat çevrimidir. Komut kümesi tablolarında bu görülebilir.

**Soru:** XOR her bit için ayrı ayrı çalışmıyor mu? **Cevap:** Hayır. 8086'nın 16 bitlik ALU'su 16 biti tek seferde, paralel olarak XOR'a sokar; toplamadaki gibi önceki basamaktan gelen bir eldeyle uğraşmaz.

> **Ek bilgi (derste anlatılmadı):** `XOR DX, DX` büyük olasılıkla bayrakları da etkiler (CF ve OF sıfırlanır, ZF 1 olur); `MOV DX, 0` bayraklara dokunmaz. Bayrakların korunması gereken yerlerde bu fark önemlidir.

### 6.4 TEST ve CMP

TEST, AND işlemi yapar ama sonucu saklamaz; yalnız bayrakları değiştirir. Hoca buna benzer başka bir komut sordu: CMP. CMP çıkarma yapar, sonucu saklamaz, yalnız bayrakları etkiler. İkisi de temelde koşullu dallanma için kullanılır.

`CMP op1, op2` op1 − op2 işlemini yaptığı için yalnız iki operand arasındaki büyüklük ilişkilerini ortaya çıkarır: >, <, ≥, ≤ ve = (ekrandan, 01:00:00).

**Soru:** CMP pozitif mi negatif mi diye mi bakıyor? **Cevap:** Hoca, iki negatif sayıda birincinin daha küçük olduğu durumu örnek verdi; sonuç pozitif çıkabilir. CMP iki operandın büyük, küçük, büyük eşit, küçük eşit ya da eşit olup olmadığını anlamak içindir.

### 6.5 Mantıksal komutların biçimleri

Ders arasından sonra komutların slaytlardaki ayrıntılı biçimlerine bakıldı (ekrandan, 01:20:00).

- NOT: yazmaç ya da bellek operandı alır. Bellek operandında işlem boyutu belli olmadığından PTR gerekir.
- AND (`dest ← dest AND src`), OR ve XOR'un biçimleri aynıdır: `reg, idata`; `mem, idata` (PTR gerekli); `reg, reg`; `reg, mem`; `mem, reg`.
- Örnek: `OR AL, 0F0H` yazmaç ve sabit biçimidir.
- Sabit veri (immediate data) ile bellek adresi karıştırılmamalıdır: sabit doğrudan sayı olarak yazılır, bellek adresi köşeli parantez içinde yazılır.
- `AND [100H], 0F0H` yazılırsa 0F0H'nin 8 bitlik mi yoksa 00F0H gibi 16 bitlik mi olduğu, 100H adresinden itibaren byte mı word mü alınacağı belli değildir. Doğrusu `AND BYTE PTR [100H], 0F0H` ya da `AND WORD PTR [100H], 0F0H`'dir.
- Bellek operandı denince o adresin içeriği kastedilir, adresin kendisi değil.
- TEST'in biçimleri AND ile aynıdır; tek farkı sonucun saklanmamasıdır.

Hoca slayttaki XOR saat çevrimi değerlerinde bir hata olabileceğini, kontrol edeceğini belirtti.

## 7. TEST ile Bit Sınama ve Maskeleme

### 7.1 Bir bitin değerini sınamak

Soru: AL'nin 6 numaralı biti 1 mi 0 mı? (bitler 0'dan 7'ye numaralanır; ekrandan, 01:00:00).

CMP burada işe yaramaz, çünkü o yalnız büyüklük ilişkilerini verir. Bir öğrenci TEST ile 6. bitine 1 koyarak sınamayı önerdi.

AND ile de yapılabilir, ama AND sonucu AL'ye yazdığı için AL bozulur. AL'nin bozulması önemli değilse AND kullanılabilir. TEST sonucu saklamadığı için AL bozulmaz (ekrandan, 01:05:00).

Maskeyi bulmak için AND kuralları kullanılır:

$$y \land 1 = y, \qquad y \land 0 = 0$$

Bilinmeyen bitler için maskede 0, aranan bit için 1 kullanılır. Maske 0100 0000B = 40H'dir:

```asm
TEST AL, 40H
; Sonuç 0 ise x = 0'mış
; Sonuç 0 değil ise x = 1'miş
```

Sonucun en yüksek biti ve diğer bitleri 0 olur, yalnız 6. bit x olarak kalır. Sonuç ancak x = 0 iken sıfır olabilir.

Sonucun sıfır olup olmadığı bayraklardan anlaşılır. TEST sonrasında CF, ZF, SF, OF, PF gibi bayraklar etkilenir; bakılacak olan sıfır bayrağıdır (ZF):

- ZF = 1 ise sonuç 0'dır, x = 0'dır.
- ZF = 0 ise x = 1'dir.

### 7.2 Örnek: AX'te bit değiştirme

Hoca ekrana şu soruyu yazdı (ekrandan, 01:25:00):

> AX ← değer. AX'in diğer bitlerini bozmadan AX'in 7. bitini 0, 15. bitini 1 yapan, 1. bitinin de tümleyenini oluşturan assembly komutlarını yazınız.

AX 16 bitliktir; en düşük anlamlı bit 0 numaralı, en yüksek anlamlı bit 15 numaralıdır.

**15. biti 1 yapmak:** OR kuralları $x \lor 1 = 1$, $x \lor 0 = x$ (ekrandan, 01:25:00). Korunacak bitler maskede 0, 1 yapılacak bit 1 olur. Bir öğrencinin yazdığı ilk maske yalnız 15. biti 1 yapıyordu ve diğer bitleri değiştirmiyordu.

**7. biti 0 yapmak:** Bir öğrenci hepsini 1, 7. biti 0 yapıp AND kullanmayı önerdi. AND kuralları $x \land 1 = x$, $x \land 0 = 0$'dır. Değişmeyecek bitler maskede 1, sıfırlanacak 7. bit 0 olur.

**1. biti tümlemek:** Bir öğrenci XOR ile 1 kullanmayı önerdi. XOR tablosunda B = 0 olan satırlarda Z = A, B = 1 olan satırlarda Z = $\bar{A}$'dır. Denklemden de görülür:

$$A \oplus 0 = \bar{A}\cdot 0 + A\cdot \bar{0} = A, \qquad A \oplus 1 = \bar{A}\cdot 1 + A\cdot \bar{1} = \bar{A}$$

Maskede yalnız 1. bit 1, diğerleri 0 olur.

Bu kurallardan çıkan komutlar (maske değerleri ara adım eklendi; python ile doğrulandı):

```asm
OR  AX, 8000H     ; 15. bit 1
AND AX, 0FF7FH    ; 7. bit 0
XOR AX, 0002H     ; 1. bit tümlenir
```

<!-- BELİRSİZ: Maskelerin tahtaya yazılmış hali karelerde görünmüyor; yukarıdaki onaltılık değerler anlatılan kurallara göre yazıldı. -->

> **Ders sonrası not:** Hoca XOR maskesini anlatırken bir yerde "en düşük anlamlı bitin" tümleyeninin alındığını söyledi. Sorudaki bit 1 numaralı bittir; en düşük anlamlı bit 0 numaralıdır.

Bu örnekle bir biti 1 yapma, 0 yapma ve tümleme durumlarının hepsi görülmüş oldu.

## 8. Dallanma Komutlarına Giriş

Hoca önce bir sonraki konuya dair kısa bir not düştü: 8086'da C'deki gibi string işlemleri (birleştirme, içinde arama gibi) yoktur; bunun yerine "katar işlemleri" vardır. Bunlar iki bellek bloğu arasında farklı karakteri bulana kadar karşılaştırma, bir alana belirli bir değeri belirli boyutta yazma gibi toplu işlemlerdir ve ileride incelenecektir.

Normal akışta komutlar art arda yürütülür: bir komut yürütüldükten sonra IP, o komutun bellekte kapladığı byte sayısı kadar artırılır ve sıradaki komuta geçilir. Bir komut IP'yi bu sıralı akıştan koparıp başka bir noktaya götürüyorsa buna dallanma denir.

Dallanma komutlarının grupları (ekrandan, 01:40:00):

- Koşullu dallanma: basit koşullu dallanma, işaretsiz sayı işlemlerinde dallanma, işaretli sayı işlemlerinde dallanma.
- Koşulsuz dallanma: tek bir komut vardır, JMP.
- Çağırma komutları: alt yordam ve kesme çağrıları.
- Dönüş komutları: alt yordamdan dönerken akış ters yönde yine kırılır.

Basit koşullu dallanma komutları tek bir bayrağa bakar. Daha karmaşık olanlar birden fazla bayrağa bakarak >, <, ≥, ≤ ve = gibi karşılaştırmaları yapar.

## 9. Koşullu Dallanma Komutları

### 9.1 Aynı gösterim, farklı karşılaştırma

Tıpkı MUL ve IMUL'de olduğu gibi, operandların işaretli mi işaretsiz mi sayılacağını kullanılan komut belirler. Önceki CMP işleminin kendisi işaretten bağımsızdır.

Koşullu dallanma komutları genel olarak `Jxx` diye gösterilir ("jump if xx"). Örneğin:

- JA (jump above): op1 > op2 ise true; işaretsiz.
- JG (jump greater): op1 > op2 ise true; işaretli.

İlk örnek (ekrandan, 01:40:00):

```asm
MOV AL, -10H   ; AL <- 1111 0000 (F0H)
MOV BL, 200    ; BL <- 1100 1000 (C8H)
CMP AL, BL     ; AL - BL
```

CMP satırı AL − BL'yi gösterimler üzerinden yapar; sonuç AL ve BL'nin işaretli ya da işaretsiz sayılmasına göre değişmez. Anlamı, CMP'den sonra kullanılan komut verir:

- JA kullanılırsa AL = 240 (15 · 16), BL = 200 sayılır; 240 > 200 olduğu için true.
- JG kullanılırsa AL = −16, BL = −56 sayılır (ikisinin de en yüksek biti 1'dir); −16 > −56 olduğu için yine true.

Hoca, sabahki derste verdiği örneğin daha açıklayıcı olduğunu söyleyip farkı gösteren ikinci bir örnek kurdu (ekrandan, 01:45:00):

```asm
MOV AL, 11111111B
MOV BL, 01111111B
CMP AL, BL
JA  ETIKET
```

- 1111 1111B işaretsiz 255, işaretli −1'dir. 0111 1111B ikisinde de 127'dir.
- JA: 255 − 127, büyükten küçük çıkarılıyor; true, dallanır.
- JG: −1 − 127, küçükten büyük çıkarılıyor; −1 127'den büyük olmadığı için false, dallanmaz.

> **Hocanın vurguladığı:** Gösterim değişmez; oraya −1 de yazılsa 255 de yazılsa bitler aynıdır. Gösterimin artı ya da eksi sayı olarak anlam kazanması, kullanılan karşılaştırma komutuna bağlıdır.

### 9.2 Etiketler ve dallanmanın çalışması

**Soru:** JA ve JG "döndürüyor" dedik; bir bayrağa mı yazıyor? **Cevap:** Hayır. Komutun yanına bir etiket yazılır (`Jxx ETIKET`). Kontrol edilen koşul doğruysa etikete dallanılır ve oradan itibaren yürütülür. Koşul yanlışsa hemen alttaki satırla devam edilir. Bu, if'in çalışma mantığıdır.

**Soru:** Etiketi nasıl tanımlıyoruz? **Cevap:** Etiket bir harfle başlar, sonra harf ve rakamla devam edebilir. Kodun gideceği yerde etiketin sonuna iki nokta üst üste konur.

**Soru:** Bu döngü yapmamızı mı sağlıyor? **Cevap:** Koşullu ve koşulsuz dallanma, if'in true ve false kollarının nereye yazılacağını belirler; evet, döngülerde de kullanılır.

### 9.3 Basit koşullu dallanma

Tek bayrağa bakan komutlar (ekrandan, 01:50:00 ve 01:55:00):

| Komut | Dallanma koşulu |
|---|---|
| JE / JZ | ZF = 1 |
| JNZ / JNE | ZF = 0 |
| JS | SF = 1 |
| JNS | SF = 0 |
| JO | OF = 1 |
| JNO | OF = 0 |
| JP / JPE | PF = 1 |
| JNP / JPO | PF = 0 |
| JC | CF = 1 |
| JNC | CF = 0 |

JC ve JNC slaytta eksikti; hoca elle ekledi.

Örnek (ekrandan, 01:55:00):

```asm
CMP AL, 0
JZ  A1
; buradaki komutlar: AL != 0 ise
A1: ...
; buradaki komutlar: AL = 0 ise
```

AL ile 0 karşılaştırılır; sonuç sıfırsa AL = 0'dır ve A1 etiketinden sonraki işlemler yapılır. Sıfır değilse JZ geçilir ve hemen alttaki komuttan devam edilir.

### 9.4 Eş adlı komutlar ve okunurluk

JE ile JZ'nin ikisi de ZF = 1 iken dallanır. İşaretsiz dallanmada aynı görevi yapan üç farklı ad olabilir (JB/JNAE/JC gibi). Hangisinin kullanılacağına algoritmadaki akışa bakılarak karar verilir: akış op1 > op2'yi kontrol ediyorsa "greater" (işaretli) ya da "above" (işaretsiz) adlı komut; op1 ≤ op2'nin değili kontrol ediliyorsa "not less or equal" (JNLE) adlı komut seçilir.

**Soru:** Bunlar aynı işi yapıp yalnız adları mı farklı? **Cevap:** Evet, okunabilirlik içindir. Bölü işaretiyle ayrılmış komutların makine kodu karşılıkları aynıdır.

> **Hocanın vurguladığı:** Akışı nasıl kurduysanız aynı adlı komutu kullanın; akışta bir koşul çizip kodda onun başka adlı eşdeğerini kullanmak kodu okumayı çok zorlaştırır.

### 9.5 İşaretsiz ve işaretli dallanma

Slayttaki komutlar ve hocanın kenara yazdığı anlamlar (ekrandan, 01:55:00):

| İşaretsiz | Anlam | İşaretli | Anlam |
|---|---|---|---|
| JB / JNAE / JC (below) | op1 < op2 | JL / JNGE (less) | op1 < op2 |
| JA / JNBE (above) | op1 > op2 | JG / JNLE (greater) | op1 > op2 |
| JAE / JNB / JNC (above or equal) | op1 ≥ op2 | JGE / JNL (greater or equal) | op1 ≥ op2 |
| JBE / JNA (below or equal) | op1 ≤ op2 | JLE / JNG (less or equal) | op1 ≤ op2 |

Eşitlik için ayrı bir komuta gerek yoktur: JE ya da JZ, operandlar işaretli de olsa işaretsiz de olsa op1 = op2 durumunda dallanır.

Bu dallanmalar herhangi bir aritmetik ya da lojik işlemden, CMP ya da TEST'ten sonra, bayraklar anlamlı ve kontrollü biçimde oluşturulduktan sonra kullanılabilir.

## 10. İşlemci Koşullara Nasıl Karar Verir

Bir dallanma komutu yürütüldüğünde, ALU ya da kontrol devresi önceki işlemin ürettiği bayraklara bakar. Slayttaki tablo (ekrandan, 02:10:00):

| Koşul | İşaretsiz sayılarda | İşaretli sayılarda |
|---|---|---|
| dest > src | CF = 0 ve ZF = 0 | ZF = 0 ve SF = OF |
| dest ≥ src | CF = 0 | SF = OF |
| dest = src | ZF = 1 | ZF = 1 |
| dest ≤ src | CF = 1 veya ZF = 1 | ZF = 1 veya SF ≠ OF |
| dest < src | CF = 1 | SF ≠ OF |

Burada dest birinci operand (op1), src ikinci operanddır (op2). Hoca bu koşullardan ikisinin nasıl türetildiğini gösterdi.

### 10.1 İşaretsiz "büyüktür" (JA)

İşaretsiz 8 bitte aralık 0–255'tir. Olası üç durum incelendi: büyükten küçüğü, eşit iki sayıyı ve küçükten büyüğü çıkarmak.

1. 240 − 40: sınıfta CF = 0, ZF = 0 bulundu. Overflow bayrağı işaretsiz sayılarda kullanılmadığı için dışarıda bırakıldı.
2. 240 − 240: sonuç 0; CF = 0, ZF = 1, SF = 0.
3. 40 − 240: CF = 1.

Eşitlik durumunda bir öğrenci "+0 ve −0" ayrımını sordu. Hoca, iki sıfırın bire tümleyen ve işaret-büyüklük gösterimlerinde olduğunu, 8086'nın ikiye tümleyen aritmetiği kullandığını ve burada tek bir sıfır olduğunu söyledi. Sonuç 0'ın en yüksek biti 0 olduğu için SF = 0'dır.

Üçüncü durum emu8086'da denendi (ekrandan, 02:05:00):

```asm
MOV AL, 40
MOV BL, 240
CMP AL, BL
```

CMP sonrasında CF = 1 oldu. Küçük sayıdan büyük sayıyı çıkarmak için yüksek anlamlı basamaktan borç (borrow) almak gerekir; çıkarmada CF borç bayrağı görevini görür. Aynı denemede SF = 0 göründü (python ile: 28H − F0H = 38H, CF = 1, SF = 0).

Hoca SF'nin neden 0 çıktığını da gösterdi: CMP sayıların işaretine bakmaz, çıkarmayı ikiye tümleyenle toplama olarak yapar. 40 − 200 için 200 = C8H = 1100 1000B'nin ikiye tümleyeni alınır (sağdan ilk 1'e kadar aynen bırak, sonra tersle) ve 40 = 28H = 0010 1000B ile toplanır. Sonucun en yüksek biti 0'dır, bu yüzden SF = 0'dır (python ile: 28H − C8H = 60H, CF = 1).

Sonuçta yalnız birinci durum "büyüktür" koşuludur. Onu diğer iki durumdan ayıran şey hem ZF'nin hem CF'nin 0 olmasıdır. JA bu yüzden CF = 0 ve ZF = 0 koşuluna bakar.

> **Ders sonrası not:** Sınıfta 240 − 40 için SF'nin 0 olacağı konuşuldu. Sonuç 200 = C8H'nin en yüksek biti 1 olduğu için aslında SF = 1'dir (python ile doğrulandı). İşaretsiz karşılaştırmada SF'ye bakılmadığı için sonuç değişmez.

### 10.2 İşaretli "büyük eşittir" (JGE)

İşaretli 8 bitlik sayılar bir çember gibi düşünülür (ekrandan, 02:10:00 ve 02:15:00): 0'dan sonra 1 gelir, 0'dan önce −1 vardır. 127 = 0111 1111B'ye 1 eklenince 1000 0000B elde edilir; bu da −128'dir. Çember üzerinde komşu sayılar birbirinden yalnız 1 farklıdır. Taşma 127 ile −128 sınırında olur:

- Pozitif yönde taşmada sonuç pozitif beklenirken gösterim çemberin negatif tarafına geçer ve en yüksek bit 1 olur.
- Negatif yönde taşmada (iki negatif sayı toplanınca) sonuç negatif beklenirken gösterim −128'den sonrasına, en yüksek biti 0 olan tarafa geçer.

op1 ≥ op2 olabilmesi için ya eşitlik vardır (ZF = 1) ya da şu üç durumdan biri olur:

1. Çok büyük bir pozitif sayıdan çok küçük bir negatif sayı çıkarılır. Örnek: 100 − (−100) = 200. 200, −128..127 aralığına sığmaz, pozitif yönde taşar. ZF = 0, OF = 1; sonucun çember üzerindeki izdüşümü negatif tarafta olduğu için SF = 1.
2. Büyük bir pozitif sayıdan küçük bir pozitif sayı çıkarılır. Örnek: 100 − 90 = 10. ZF = 0, OF = 0, SF = 0.
3. Küçük bir negatif sayıdan çok küçük bir negatif sayı çıkarılır. Örnek: −5 − (−100) = 95 (derste ayrıca −10 − (−100) = 90). Sonuç aralığın içinde kalır: ZF = 0, OF = 0, SF = 0.

(Değerler python ile doğrulandı.)

Bir öğrenci birinci durumun tersini önerdi; hoca bunun aranan durum olmadığını, çünkü birinci sayının negatif, ikincinin pozitif olacağını söyledi. Sabahki derste kendisinin de aynı hatayı yapıp sonradan fark ettiklerini ekledi.

**Soru:** −5'ten −100'ü çıkarınca artı yöne taşmış olmaz mıyız? **Cevap:** Hayır, sonuç 95'tir ve −128..127 aralığındadır. Taşma, örneğin 100 ile −100 karşılaştırıldığında olur: 100 − (−100) = 200 aralığa sığmaz. (Hoca önce 200 ile −200 örneğini verdi; bir öğrenci 200'ün kendisinin de 8 bite sığmadığını hatırlatınca örnek 100 ve −100 olarak düzeltildi.)

Eşitlik durumunda ZF'nin 0 ya da 1 olması fark etmeyeceği için ZF'ye bakmaya gerek kalmaz. Geriye kalan ortak koşul SF = OF'dur: pozitif yönde taşmada da, aralıkta kalınca da bu iki bayrak eşittir.

**Soru:** Eşitlik durumunda OF ve SF'ye bakmadık. **Cevap:** Sayılar eşitse çıkarma sonucu 0 olur; SF = 0'dır ve aralık içinde kalındığı için OF = 0'dır. Yani bu durumda da SF = OF'dur.

**Soru:** SF kısmını tekrar anlatır mısınız? **Cevap:** SF, işlem sonucunun en yüksek anlamlı bitidir. 10 ile 10 karşılaştırılınca sonuç 0000 0000 olur, SF = 0. 100 ile −100 karşılaştırılınca değer olarak 200 çıkması gerekir, ama 8 bitlik çember üzerinde bu değerin izdüşümü sol taraftadır; o taraftaki bütün sayıların en yüksek biti 1'dir, bu yüzden SF = 1 ve aralığa sığmadığı için OF = 1'dir. 100 − 90 = 10 pozitiftir, SF = 0. −10 − (−100) = 90 aralıktadır ve pozitiftir, SF = 0.

Diğer koşullar da aynı yolla türetilebilir.

## 11. Koşulsuz Dallanma, Çağırma ve Dönüş Komutları

### 11.1 JMP

İki biçim vardır:

- `JMP etiket`: o anda çalışılan kod kesimi içinde ileriye ya da geriye bir etikete atlar.
- `JMP FAR PTR`: başka bir kod kesimindeki belirli bir ofsete dallanır.

### 11.2 Çağırma ve dönüş

Çağırma iki türlüdür:

- Kendi yazdığımız alt yordamlar CALL ile çağrılır. Alt yordam aynı kod kesimindeyse bu near call'dur; yığına geri dönüş için yalnız IP atılır ve RET ile dönülür. RET, yığının en üstündeki değeri IP'ye yazar.
- Alt yordam başka bir kod kesimindeyse `CALL FAR PTR` kullanılır; hem CS hem IP değişir, ikisi de yığına atılır ve RETF (return far) ile dönülür.
- Kesme alt programları: yazılımla (INT komutu), işlem sırasında oluşan özel durumlarla (örneğin sıfıra bölme) ya da donanımla tetiklenebilir. Yığına bayrak yazmacı, CS ve IP atılır ve IRET (interrupt return) ile dönülür.

Hoca RETF'nin yığından ilk çektiği (en üstteki) değeri CS'ye, sonrakini IP'ye attığını; dolayısıyla dönüşte yığının en üstünde CS, altında IP olması gerektiğini söyledi.

> **Ders sonrası not:** FAR CALL önce CS'yi, sonra IP'yi yığına atar; bu yüzden yığının en üstünde büyük olasılıkla IP bulunur. RETF önce IP'yi, sonra CS'yi çeker. IRET de sırasıyla IP, CS ve bayrakları çeker; hoca dersin sonunda IRET için bu doğru sırayı söyledi.

> **Hocanın vurguladığı:** Neyle gidildiyse ona uygun komutla dönülmelidir: CALL ile gidilirse RET, CALL FAR PTR ile gidilirse RETF, kesmeyle gidilirse IRET.

**Soru:** JMP ile başka bir kod parçasına gittim; geri dönmek için ne kullanmalıyım? **Cevap:** Yine JMP. JMP yığına dönüş adresi bırakmaz; dönülecek yere yine JMP ile atlanır.

Hoca bu komutların farklı sürümlerini bir sonraki derse bıraktı.

### 11.3 CALL biçimleri

Ders sonunda CALL'ın biçimlerine yeniden dönüldü:

- Sabit değerle göreli çağrı (`CALL 100`, `CALL -10` gibi): aynı kod kesiminde kalınır, yalnız IP değişir.
- Bellek operandlı near çağrı: bellekteki içerik IP'ye atanır; aynı kod kesiminde kalınır.
- Yazmaç operandlı çağrı: yazmacın içeriği IP'ye atanır.
- `CALL FAR PTR` iki sabitle, iki nokta üst üsteyle ayrılarak (segment:ofset) verilebilir; bu mutlak bir atamadır, değerler doğrudan CS ve IP'ye yazılır. Bellek adresiyle verilirse o adresten başlayan ilk word IP'ye, sonraki word CS'ye atanır. CS ve IP yığına atıldığı için RETF ile dönülür.

### 11.4 Kesmelerde bayrakların yığına atılması

Kesmenin üç kaynağı vardır: INT komutu, işlem sonucunda oluşan özel durumlar ve donanım. Kesme alt programı çağrılınca yığına bayraklar, CS ve IP atılır; bu yüzden dönüş IRET ile olmalıdır.

Bayrakların neden atıldığını hoca şöyle açıkladı: bir donanım kesmesi gelip kesme alt programına gidildiğinde o kesme hâlâ etkin olabilir ve işlemciyi yeniden dürtebilir; bu, iç içe kesmelere yol açar. Bu yüzden işlemci kesme alt programına giderken bayrakları sıfırlar. Ana programa dönüldüğünde bayrak değerleri kaybolmasın diye bayraklar da yığına atılır.

> **Ders sonrası not:** 8086 kesmeye girerken büyük olasılıkla bütün bayrakları değil, yalnız kesme izin (IF) ve tek adım (TF) bayraklarını sıfırlar; böylece maskelenebilir kesmeler alt program içinde yeniden tetiklenmez.

## 12. if Yapılarının Assembly Karşılığı

Hoca üç akış bloğu gösterdi (ekrandan, 02:35:00). Üçünde de AX = 0 karşılaştırması yapılır ve bloğun çıkışında CX = 5 atanır:

- if-then-else (mavi): AX = 0 ise BX = 2, değilse BX = 1; sonra CX = 5.
- if-null-else (turuncu): AX = 0 ise BX = 1; false kolu boştur; sonra CX = 5.
- if-null-then (yeşil): true kolu boştur; AX ≠ 0 ise BX = 1; sonra CX = 5.

Her biri hem true koluna hem false koluna göre koşul yazılarak kodlandı.

### 12.1 if-then-else

Sınıftan cevap gelmeyince hoca kodu kendisi kurmaya başladı. İlk taslak (ekrandan, 02:40:00):

```asm
CMP AX, 0
JE  LABEL1
MOV BX, 1        ; false
LABEL1: MOV BX, 2  ; true
MOV CX, 5
```

İki sorun vardır. Önce false kolunun sonuna da bir `MOV CX, 5` yazılmıştı; false kolu zaten aşağıdaki `MOV CX, 5`'e akacağı için bu gereksizdir ve silindi. Asıl sorun false kolundadır: koşul karşılanmayınca `MOV BX, 1` yürütülür, ama ardından sıradaki komut `MOV BX, 2` olduğu için o da yürütülür; çıkışta BX = 2 olur. Çözüm false kolunun sonunda true kolunu atlamaktır:

```asm
CMP AX, 0
JE  LABEL1
MOV BX, 1          ; false kolu
JMP EXIT
LABEL1: MOV BX, 2  ; true kolu
EXIT:   MOV CX, 5
```

Aynı yapı false koluna göre de yazılabilir:

```asm
CMP AX, 0
JNE LABEL1
MOV BX, 2          ; true kolu
JMP EXIT
LABEL1: MOV BX, 1  ; false kolu
EXIT:   MOV CX, 5
```

İki durumda da iki dallanma komutu (bir koşullu, bir JMP) gerekir.

> **Hocanın vurguladığı:** if-then-else bloklarında koşul hangi kola göre yazılırsa yazılsın iki dallanma komutu kaçınılmazdır.

### 12.2 if-null-else

True koluna göre:

```asm
CMP AX, 0
JE  TRUEKOL
JMP EXIT           ; false kolu: hiçbir şey yapmadan çık
TRUEKOL: MOV BX, 1
EXIT:    MOV CX, 5
```

İki dallanma gerekti. Koşul boş olan false koluna göre yazılırsa:

```asm
CMP AX, 0
JNE FALSEKOL
MOV BX, 1          ; true kolu
FALSEKOL: MOV CX, 5
```

True kolunda BX = 1 yapıldıktan sonra akış zaten CX = 5'e geçer; ek bir atlamaya gerek kalmaz. Tek dallanma yeter.

<!-- BELİRSİZ: if-null-else ve if-null-then kodlarının tahtadaki hali yalnız kısmen görüldü (ekrandan, 02:45:00); kodlar altyazıdaki satır satır anlatımdan kuruldu. Altyazıda "CMP exit" geçen yerler JMP EXIT olarak okundu. -->

### 12.3 if-null-then

True koluna göre (true kolu boştur):

```asm
CMP AX, 0
JE  TRUEKOL
MOV BX, 1          ; false kolu
TRUEKOL: MOV CX, 5
```

True kolunda yapılacak iş yoktur, doğrudan çıkışa gidilir. False kolu BX = 1 yaptıktan sonra yine çıkışa akar. Tek dallanma yeter.

False koluna göre yazılırsa:

```asm
CMP AX, 0
JNE FALSEKOL
JMP EXIT           ; true kolu: BX'e dokunmadan çık
FALSEKOL: MOV BX, 1
EXIT:     MOV CX, 5
```

Burada iki dallanma gerekir; JMP yazılmazsa true kolu da `MOV BX, 1`'i yürütür.

### 12.4 Sonuç

- Kollardan biri boşsa (if-null-then ve if-null-else), koşul boş kola göre yazılırsa tek bir koşullu dallanma yeter ve kod kısalır.
- if-then-else için iki dallanma komutu zorunludur.

Benzer mantıkla while, do-while ve repeat-until yapıları da koşullu dallanmalarla kurulacaktır. for için özel bir LOOP komutu vardır; while, do-while ve repeat-until için yoktur. if'lerin de tam bir karşılığı yoktur, kabaca koşullu dallanmalarla kurulurlar.

## 13. Yığın Komutları

Dört yığın komutu vardır: POP, PUSH, POPF ve PUSHF. Her biri yığına bir word atar ya da yığından bir word çeker; byte ile yığın işlemi yapılmaz.

- PUSH yığına bir değer atar.
- POP yığından bir değer çeker (`dest ← SS:[SP]`; ekrandan, 02:55:00).
- PUSHF bayrak yazmacını yığına atar.
- POPF yığındaki değeri bayrak yazmacına yazar.

Yığın bir bellek bölgesidir; yığının o anki adresi SS kesiminde SP ile gösterilir. Hoca SP'nin her zaman "mevcut sıradaki boş gözü" gösterdiğini söyledi. Adresler yukarı doğru azalır. PUSH yapıldığında SP 2 azalır, POP yapıldığında 2 artar. 2 olmasının nedeni bir adresin bir byte tutması, bir word'ün iki adres kaplamasıdır.

> **Ders sonrası not:** 8086'da SP büyük olasılıkla boş gözü değil, yığına en son atılan word'ü (yığının tepesini) gösterir: PUSH önce SP'yi 2 azaltır, sonra değeri SS:SP'ye yazar; POP önce SS:SP'deki değeri okur, sonra SP'yi 2 artırır.

Biçimler:

- POP: 16 bitlik bir yazmaca (`POP regw`) ya da bir bellek word'üne (`POP mem`) yığından değer çekilir.
- POPF: yığındaki değer bayrak yazmacına yazılır.
- PUSH: 16 bitlik yazmaç (`PUSH AX`), bellek adresi (100H adresindeki word'ü yığına atmak gibi) ya da kesim yazmacı (`PUSH DS`) atılabilir. Derste sabit değer de (`PUSH 0FFFFH`) atılabileceği söylendi.
- PUSHF: bayrak yazmacını yığına atar.

> **Ders sonrası not:** Sabit değerle PUSH büyük olasılıkla 8086'da yoktur, 80186 ile eklenmiştir; emu8086 gibi araçlar bunu kabul edebilir.

PUSHF ve POPF, bayrak yazmacının doğrudan adreslenemeyen bazı bayraklarını değiştirmek için kullanılan bir komut grubu olarak ortaya çıkmıştır.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla tipik kullanım, bayrakları PUSHF ile yığına atıp bir yazmaca POP etmek, istenen biti AND/OR/XOR ile değiştirmek, sonra PUSH ve POPF ile geri yüklemektir. Tek adım (trap) bayrağının doğrudan kurulup silinmesini sağlayan bir komut olmadığı için bu yol kullanılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:08:05): İki 16 bitlik sayının çarpımı kaç bite sığar? 8086 bu sonucu nerede saklar?

> **Çözüm:** 32 bite sığar. 8086'da 32 bitlik yazmaç olmadığı için sonuç DX:AX ikilisinde saklanır; yüksek anlamlı 16 bit DX'e, düşük anlamlı 16 bit AX'e yazılır.

**Soru 2** (derste sözlü, 00:09:31): `MUL AL` komutu ne yapar?

> **Çözüm:** AL'yi kendisiyle çarpar, yani AL'nin karesini alır ve sonucu AX'e yazar.

**Soru 3** (ekrandan, 00:15:00): 130 · 552 işlemini 8086'da yapan komutları yazınız; işlem sonucunda DX, AX ve BX'te ne bulunur?

> **Çözüm:** 552 sekiz bite sığmadığı için 16 bitlik çarpma gerekir: `MOV AX, 552` / `MOV BX, 130` / `MUL BX`. 130 · 552 = 71760 = 0001 1850H olduğundan DX = 0001H, AX = 1850H, BX = 130 (değişmez). Derste tahtaya AX = 0914H yazıldı; o değer 130 · 522'nin sonucudur (python ile doğrulandı).

**Soru 4** (ekrandan, 00:30:00): DX = FFFFH, AX = FFFFH, BX = 1 iken `DIV BX` yürütülürse ne olur?

> **Çözüm:** DX:AX = FFFF FFFFH 1'e bölünür. Bölüm FFFF FFFFH'dir, 16 bitlik AX'e sığmaz; bölme taşar. Taşma 8086'da büyük olasılıkla bölme hatası kesmesini tetikler (bkz. Bölüm 4.2'deki not).

**Soru 5** (ekrandan, 00:35:00 ve 00:40:00): $y = 1.8x + 32$ formülüyle x = −40 °C için Fahrenheit değerini 8086'ya hesaplatınız.

> **Çözüm:** `MOV AL, -40` / `MOV DL, 18` / `IMUL DL` (AX = −720) / `MOV BL, 10` / `IDIV BL` (AL = −72, AH = 0) / `ADD AL, 32` (AL = −40). Sonuç −40 °F'dir. Önce çarpma, sonra bölme yapılır (python ile doğrulandı).

**Soru 6** (ekrandan, 00:50:00): `MOV AL, 5AH` ve `NOT AL` komutlarından sonra AL'de ne bulunur?

> **Çözüm:** 5AH = 0101 1010B. Bire tümleyeni 1010 0101B = 0A5H'dir.

**Soru 7** (derste sözlü, 00:51:10): İkiye tümleyen alan komut hangisidir? `MOV AL, 1` ve ardından bu komut uygulanınca AL ne olur?

> **Çözüm:** NEG komutu. 0000 0001B'nin ikiye tümleyeni 1111 1111B = 0FFH'dir; işaretli olarak −1.

**Soru 8** (ekrandan, 01:00:00 ve 01:05:00): AL'yi bozmadan 6 numaralı bitinin 1 mi 0 mı olduğunu nasıl anlarız?

> **Çözüm:** `TEST AL, 40H` (maske 0100 0000B). TEST sonucu saklamaz; ZF = 1 ise 6. bit 0, ZF = 0 ise 6. bit 1'dir. AND de kullanılabilir ama AL'yi bozar.

**Soru 9** (ekrandan, 01:25:00): AX'in diğer bitlerini bozmadan 7. bitini 0, 15. bitini 1 yapan, 1. bitinin de tümleyenini oluşturan assembly komutlarını yazınız.

> **Çözüm:** `OR AX, 8000H` (15. bit 1), `AND AX, 0FF7FH` (7. bit 0), `XOR AX, 0002H` (1. bit tümlenir). Maskelerin kuralı derste verildi; onaltılık değerler bu kuraldan yazıldı ve python ile denendi (örneğin AX = 12B4H için sonuç 9236H).

**Soru 10** (ekrandan, 01:45:00): `MOV AL, 11111111B` / `MOV BL, 01111111B` / `CMP AL, BL` sonrasında JA ve JG dallanır mı?

> **Çözüm:** JA işaretsiz karşılaştırır: 255 > 127, dallanır (CF = 0, ZF = 0). JG işaretli karşılaştırır: −1 > 127 yanlış, dallanmaz (sonuç 80H: SF = 1, OF = 0, SF ≠ OF).

**Soru 11** (derste sözlü, 01:59:41 ve 02:01:08): İşaretsiz 240 − 40, 240 − 240 ve 40 − 240 işlemlerinde CF ve ZF ne olur? JA hangi bayrak koşuluna bakar?

> **Çözüm:** 240 − 40: CF = 0, ZF = 0. 240 − 240: CF = 0, ZF = 1. 40 − 240: CF = 1, ZF = 0. Yalnız birinci durum "büyüktür" olduğu için JA, CF = 0 ve ZF = 0 koşuluna bakar.

**Soru 12** (derste sözlü, 02:32:33): JMP ile başka bir kod parçasına gidildiyse geri dönmek için hangi komut kullanılır?

> **Çözüm:** Yine JMP. RET, RETF ve IRET yalnız sırasıyla CALL, CALL FAR PTR ve kesmeyle gidildiğinde kullanılır.

**Soru 13** (ekrandan, 02:35:00): "AX = 0 ise BX = 2, değilse BX = 1; ardından CX = 5" akışını assembly ile yazınız.

> **Çözüm:** `CMP AX, 0` / `JE LABEL1` / `MOV BX, 1` / `JMP EXIT` / `LABEL1: MOV BX, 2` / `EXIT: MOV CX, 5`. JMP EXIT yazılmazsa false kolu da `MOV BX, 2`'yi yürütür.

## Dersin Toparlaması

Bu derste aritmetik komutlar çarpma ve bölmeyle tamamlandı. MUL, IMUL, DIV ve IDIV'in tek operand aldığı, gerisini AL, AH, AX ve DX gibi gizli operandlardan sağladığı görüldü. 16 bitlik işlemlerde DX:AX sanal bir 32 bitlik yazmaç gibi kullanılır. Celsius–Fahrenheit örneği, önce çarpıp sonra bölmenin ve girdi aralığına göre işlem genişliği seçmenin önemini gösterdi. Mantıksal komutlarda bitwise işlem kavramı, NOT/NEG farkı, XOR ile sıfırlama ve TEST ile bit sınama işlendi; OR, AND ve XOR maskeleriyle bir biti 1 yapma, 0 yapma ve tümleme örneklendi.

İkinci yarıda dallanma komutlarına geçildi. Dersin ana fikri, bit gösteriminin tek olduğu ve işaretli/işaretsiz anlamın kullanılan komutla ortaya çıktığıdır: CMP işaretten bağımsız çalışır, JA ile JG aynı bayraklardan farklı sonuç çıkarır. İşlemcinin bu kararları CF, ZF, SF ve OF bayraklarına bakarak verdiği, JA ve JGE koşulları üzerinden türetildi. Ardından JMP, CALL, RET, RETF ve IRET ile if yapılarının assembly karşılıkları ve yığın komutları görüldü. Sonraki derste döngü komutlarına geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
