# Ders 3 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı: veri aktarım komutları
  - MOV iki birim arasında (yazmaç-yazmaç, yazmaç-bellek) veri taşır. LEA bir adres (pointer) değeri döndürür. LDS ve LES verilen adresteki değerlerle ilgili yazmacı ve DS ya da ES'yi doldurur. XCHG takas yapar. XLAT bir tablodaki sıradaki değeri dönüştürür.
  - Veri aktarım komutları bayrakları etkilemez. Bu, derste emu8086'da MOV komutlarından sonra bayrakların değişmemesiyle de görüldü.
- Aritmetik komutlar: ADD, ADC, SUB, SBB, INC, DEC, NEG, CMP, MUL, IMUL, DIV, IDIV
  - İki operandlı komutlarda kural aynıdır: `dest ← dest op src`. Sonuç ilk operanda (destination) yazılır.
  - Geçerli operand biçimleri (ekrandan, 00:15:00): `reg, idata`, `mem, idata` (PTR gerekli), `reg, reg`, `reg, mem`, `mem, reg`.
  - Yazmaçların boyutu uyumlu olmalıdır. `ADD DX, DL` geçersizdir.
  - MUL ve DIV işaretsiz, IMUL ve IDIV işaretli sayılarla çalışır.
- ADD ve PTR kullanımı
  - `ADD AX, 0FFH`: sabit değer 16 bite tamamlanıp AX ile toplanır. `ADD CH, 'A'`: 'A' karakterinin ASCII değeri CH ile toplanır (ekrandan, 00:15:00).
  - Bellek ile sabit değer arasındaki işlemde işlemin 8 bit mi 16 bit mi olduğu anlaşılamaz. Bu yüzden `BYTE PTR` ya da `WORD PTR` yazılmalıdır.
  - İşlemlerden birinde yazmaç varsa yazmaç genişliği işlemin boyutunu belirler. PTR gerekmez. `ADD BX, [10H]` örtük olarak WORD işlemdir.
- ADC ve SBB ile çok sözcüklü (32 bit) aritmetik
  - ADC: `dest ← dest + src + CF`. SBB: `dest ← dest − src − CF` (ekrandan, 00:25:00 ve 00:35:00).
  - 8086 donanımsal olarak 8 ve 16 bit toplama ve çıkarma yapar. 32 bit toplama için düşük anlamlı sözcükler ADD ile, yüksek anlamlı sözcükler ADC ile toplanır. Çıkarmada ise önce SUB, sonra SBB kullanılır.
  - Çıkarmada CF borç (borrow) görevini görür. Küçük sayıdan büyük sayı çıkarılınca CF = 1 olur.
- INC, DEC ve NEG
  - INC ve DEC tek operandlıdır, bellekte PTR gerekir. 8 bitte FFH artırılınca 00H olur, 00H azaltılınca FFH olur. 16 bitte 0000H azaltılınca FFFFH olur, işaretli olarak bu −1'dir.
  - INC sırasında CF değişmez (derste emülatörde gösterildi).
  - NEG ikiye tümleyene göre negatif alır (NOT + 1). Bitwise NOT ile aynı değildir: FFH için NEG sonucu 01H, NOT sonucu 00H olur.
- CMP (karşılaştırma)
  - CMP arka planda çıkarma (dest − src) yapar. Sonucu saklamaz, yalnız bayrakları günceller. SUB ile farkı budur.
  - Koşullu dallanma komutlarından önce bayrak koşulu üretmek için kullanılır. Koşullu dallanma yalnız CMP ile değil, aritmetik ve mantık komutlarından sonra da yapılabilir.
- Bayrakların anlamı
  - CF işaretsiz sonuca göre, OF işaretli sonuca göre oluşur. ZF sonuç sıfırsa 1 olur, SF en yüksek anlamlı biti gösterir.
  - 8 bit işaretsiz aralık 0–255, işaretli aralık −128 ile +127'dir.
- MUL ve IMUL
  - Tek açık operand alır, gizli operandları AX ve DX'tir.
  - 8 bitlik kaynakta `AX ← AL × src`. 16 bitlik kaynakta `DX:AX ← AX × src` (ekrandan, 01:20:00).
  - Sonuç küçük olsa da bütün hedef yazmaçlar yazılır: 8 bitlik çarpmada AH, 16 bitlik çarpmada DX bozulur.
- DIV ve IDIV
  - 8 bitlik bölende `AL ← AX / src` (bölüm), `AH ← AX % src` (kalan). 16 bitlik bölende `AX ← DX:AX / src`, `DX ← DX:AX % src` (ekrandan, 01:45:00).
  - 16 bitlik bölmeden önce DX ve AX hazırlanmalıdır. Bölüm hedef yazmaca sığmazsa hata kesmesine gidilir.
- Komut süresi (clock cycle) ve XOR ile sıfırlama
  - Komut tablosunda `MOV r16, idata` 4, `XOR r16, r16` 3 clock cycle sürer. Bu yüzden yazmacı sıfırlamak için `XOR AX, AX` daha hızlıdır.
  - Bellek erişimli komutlarda tablodaki süreye etkin adres (EA) hesabının süresi eklenir.
- Dallanma komutları
  - Normalde IP her komuttan sonra komutun bayt uzunluğu kadar artar. Bu artışı bozan komutlar dallanma komutudur.
  - Dört grup: koşulsuz dallanma (JMP), koşullu dallanma, çağırma (CALL, INT, INTO), dönüş (RET, RETF, IRET).
  - Koşullu dallanmanın üç alt grubu vardır: tek bayrağa bakan basit dallanmalar, işaretsiz karşılaştırma dallanmaları (above/below), işaretli karşılaştırma dallanmaları (greater/less).
- İşlemci koşullara nasıl karar verir (ekrandan, 02:20:00)
  - İşaretsizde büyük: CF = 0 ve ZF = 0. Büyük eşit: CF = 0. Eşit: ZF = 1. Küçük eşit: CF = 1 veya ZF = 1. Küçük: CF = 1.
  - İşaretlide büyük: ZF = 0 ve SF = OF. Büyük eşit: SF = OF. Eşit: ZF = 1. Küçük eşit: ZF = 1 veya SF ≠ OF. Küçük: SF ≠ OF.
- Koşulsuz dallanma ve çağırma
  - Segment içi JMP, 8 veya 16 bitlik ikiye tümleyen yer değiştirme (8 bitte −128 ile +127 adım), yazmaç ya da bellek ile kullanılabilir. JMP FAR PTR hem CS'yi hem IP'yi değiştirir.
  - CALL yığına yalnız IP atar, RET ile dönülür. CALL FAR hem CS hem IP atar, RETF ile dönülür. INT bayrakları, CS ve IP'yi atar, IRET ile dönülür.
- If-then-else yapılarının assembly ile kurulması
  - Koşul doğruysa etikete gidilir, değilse bir alttaki komuta geçilir. Bir kolun sonunda JMP unutulursa akış öbür kolun koduna da düşer.

## Hocanın Özellikle Vurguladığı Kısımlar

- PTR zorunluluğu
  - Bellek ile sabit değer arasındaki işlemlerde (ADD, ADC, SUB, SBB, CMP; tek operandlı INC, DEC, NEG, MUL, DIV) PTR yazılmalıdır. Hoca varsayılan davranışa güvenilmeyeceğini, gerekirken PTR yazılmamasını hata sayacağını söyledi.
- NEG ile NOT aynı değildir
  - NEG ikiye tümleyen, NOT bire tümleyendir. Hoca bunu ekrana kırmızıyla "NEG ≠ LOGICAL BITWISE NOT" diye yazdı (ekrandan, 00:45:00).
- CMP sonucu saklamaz
  - CMP iki operandı birbirinden çıkarır, sonucu saklamaz, yalnız bayrakları günceller. Hoca bunu "duymayan kalmasın" diyerek tekrarladı.
- Çarpmada AH ve DX'in bozulması
  - Çarpım 8 bite sığsa da 8 bitlik çarpmanın sonucu AX'e yazılır ve AH bozulur. 16 bitlik çarpmada DX'teki eski değer kaybolur. Hoca bunun sınavlarda ve ödevlerde sık gözden kaçtığını söyledi.
- Bölümün sığmaması
  - 8 bitlik bölmede bölüm AL'ye sığmazsa işlem hatalıdır. Sığdırmak zorunda değiliz ama sığmadığını bilmeliyiz.
- Daha az clock cycle süren komutu tercih etmek
  - Aynı işi yapan komutlardan clock cycle'ı az olan seçilmelidir. Büyük kodlarda çok tekrarlanan sıfırlamalarda `XOR AX, AX` zaman kazandırır.
- İşaretli ve işaretsiz dallanma kelimeleri
  - İşaretsiz sonuç için above/below (JA, JB, JAE, JBE), işaretli sonuç için greater/less (JG, JL, JGE, JLE) kullanılır. Eşdeğer adlar (JBE = JNA gibi) arasında ihtiyaca uyan seçilir.
- Bir kolu boş if-then-else kuralı
  - True ya da false kolu boş olan bir if-then-else yazılırken koşul boş kol için yazılırsa kod daha az satır tutar. Hoca bunu "hafızamızda tutmamız gereken kural" diye birkaç kez tekrarladı.
- Çağırma ve dönüş komutlarının eşleşmesi
  - CALL ile RET, CALL FAR ile RETF, INT ile IRET eşleşmelidir. Yoksa yığından yanlış sayıda değer çekilir ve dönüş adresi bozulur.

## Kısa Tekrar Notları

- `dest ← dest op src`; sonuç her zaman ilk operanda yazılır.
- Bellek + sabit değer = PTR gerekli. Yazmaç varsa yazmaç boyutu işlem boyutunu belirler.
- 32 bit toplama: düşük sözcükler ADD, yüksek sözcükler ADC. 32 bit çıkarma: SUB, sonra SBB.
- INC FFH → 00H (8 bit). DEC 0000H → FFFFH = −1. INC CF'yi değiştirmez.
- NEG = NOT + 1. NEG FFH = 01H, NOT FFH = 00H.
- CMP = sonucu saklanmayan SUB. Yalnız bayraklar değişir.
- CF işaretsiz taşma ya da borç, OF işaretli taşmadır. 8 bit işaretli aralık −128 ile +127, en küçük negatif sayı 80H = −128.
- İki pozitif sayının toplamı negatif çıkarsa ya da iki negatif sayının toplamı pozitif çıkarsa overflow vardır.
- MUL 8 bit: `AX ← AL × src`. MUL 16 bit: `DX:AX ← AX × src`.
- DIV 8 bit: bölüm AL, kalan AH. DIV 16 bit: bölüm AX, kalan DX. Bölünen DX:AX'te hazırlanır.
- IMUL ile −1 × 4 = FFFCH: 8 bitlik FCH işaret biti tekrarlanarak 16 bite genişletilir.
- `XOR AX, AX` (3 clock) `MOV AX, 0` (4 clock) ile aynı işi daha hızlı yapar.
- İşaretsiz: JA, JAE, JB, JBE. İşaretli: JG, JGE, JL, JLE. Basit: JZ/JE, JNZ/JNE, JS, JNS, JO, JNO, JP/JPE, JNP/JPO.
- Koşul sağlanmazsa bir alttaki komuta geçilir. Dolu kolun sonunda JMP ile ortak çıkışa atlanmalıdır.
- Bir kolu boş if-then-else'te koşulu boş kol için yaz.
- CALL → RET (IP), CALL FAR → RETF (CS, IP), INT → IRET (bayraklar, CS, IP).

## Detaylı Açıklamalar

- ADD ve bellek örneği (emu8086). Hoca `ADD BYTE PTR [10H], 0FFH` ile DS:0010H'deki baytı FFH ile topladı. Başlangıçta 0010H ve 0011H adreslerinde 90H vardı. Bayt toplamada 90H + FFH = 18FH olur, bayta yalnız 8FH sığar ve CF = 1 olur. Aynı işlem `ADD WORD PTR [10H], 0FFH` ile yapıldığında 9090H + 00FFH = 918FH bulunur ve CF = 0 kalır (ekrandan, 00:20:00). Bellekte bu değer little endian düzeninde, 0010H adresinde 8FH, 0011H adresinde 91H olarak görünür. Aynı komut, boyuta göre farklı sonuç ve farklı bayrak üretir. PTR bu yüzden zorunludur.
- 32 bitlik iki işaretsiz sayının toplanması (ekrandan, 00:30:00). Her sayı yüksek ve düşük anlamlı 16 bitlik iki sözcük olarak düşünülür. Önce düşük sözcükler ADD ile toplanır. Bu toplam sonucun düşük 16 bitidir ve bu sırada bir elde (CF) oluşabilir. Sonra yüksek sözcükler ADC ile toplanır, böylece elde de yüksek kısma eklenir. Çıkarmada aynı mantıkla önce SUB, sonra SBB çalıştırılır. Burada CF borcu taşır.
- INC ve bellek. `MOV WORD PTR [10H], 0ABFFH` ile bellekte ABFFH hazırlandı. `INC BYTE PTR [10H]` yalnız düşük baytı artırır: FFH, 00H olur ve elde yüksek bayta geçmez. `INC WORD PTR [10H]` ise 16 bitlik değeri artırır: ABFFH, AC00H olur.
- CMP ve bayraklar. AL = 40H, BL = 20H iken `CMP AL, BL` çalıştırıldığında büyükten küçük çıkarıldığı için CF, ZF, SF ve OF sıfır kalır, AL ve BL değişmez. `CMP BL, AL` ise 20H − 40H yapar: borç oluşur (CF = 1), sonuç negatiftir (SF = 1), −20H 8 bitte gösterilebildiği için OF = 0 kalır. BL = 80H (−128) yapıldığında `CMP AL, BL` sonrası ekranda CF = 1, ZF = 0, SF = 1, OF = 1 görüldü (ekrandan, 01:05:00). İşaretli bakışla 64 − (−128) = 192, +127'yi aştığı için OF = 1 olur. İşaretsiz bakışla 64 − 128 borç gerektirir, bu yüzden CF = 1 olur. `CMP BL, AL` ise −128 − 64 = −192 yapar, −128'in altına taştığı için yine OF = 1 olur. Bu durumda iki negatif sayının toplamı gibi düşünülebilir: 1000 0000 + 1100 0000 toplamında en yüksek anlamlı bit 0 çıkar, yani sonuç pozitif görünür.
  - Ders sonrası not: Hoca 40H − 80H işleminde önce sonucun 8 biti taşırdığını söyledi, sonra düzeltti. Doğrusu şudur: 8 bitlik sonuç C0H'dir. CF = 1 olmasının nedeni işaretsiz 64'ten 128 çıkarılırken borç gerekmesidir.
- İşaret ne zaman belirlenir? Bir öğrencinin sorusu üzerine hoca, CMP'nin çıkarmayı ikiye tümleyen aritmetiğiyle yaptığını, sonucun işaretli mi işaretsiz mi yorumlanacağına ise sonra kullanılan koşullu dallanma komutunun karar verdiğini anlattı. JA sonucu işaretsiz, JG işaretli değerlendirir.
  - Ders sonrası not: Hoca ADD'nin işaretsiz, SUB'ın ikiye tümleyen aritmetiğiyle çalıştığını söyledi. Doğrusu: ikiye tümleyen gösteriminde toplama ve çıkarma aynı bit işlemidir. ADD de SUB da işaretsiz yorum için CF'yi, işaretli yorum için OF'yi aynı anda günceller. Komut tablosunda SUB için "twos complement" yazması yalnız çıkarmanın nasıl yapıldığını anlatır.
- MUL örnekleri (ekrandan, 01:15:00). AX = 0F0FH, BX = 1010H iken `MUL BL`: AL (0FH) × BL (10H) = 00F0H. Çarpım 8 bite sığdığı hâlde AX'in tamamına yazılır ve AH'deki 0FH kaybolur. DX = 1234H yüklenip `MUL BX` yapıldığında 0F0FH × 1010H = 00F1E0F0H bulunur: DX = 00F1H, AX = E0F0H. DX'teki 1234H silinir, yalnız BX korunur.
- MUL ile IMUL farkı (ekrandan, 01:25:00). AL = 0FFH, BL = 4 iken `MUL BL` FFH'yi 255 sayar ve AX = 03FCH (1020) olur. `IMUL BL` ise FFH'yi −1 sayar, sonuç −4'tür ve AX = FFFCH olur. 8 bitte −4 FCH (1111 1100B) olarak yazılır. 16 bite işaretli genişletmede işaret biti (1) sola doğru tekrarlandığı için sonuç 00FCH değil FFFCH olur. 00FCH pozitif bir sayı anlamına gelirdi.
- DIV örnekleri. AX = 0F0F0H, BL = 0F0H iken `DIV BL` bölümü 101H yapar. Bu değer AL'ye sığmadığı için emülatör hata kesmesine gitti. AX = 0B0F0H, BL = 0F0H ile tekrarlandığında AL = BCH (bölüm), AH = B0H (kalan) oldu (ekrandan, 01:35:00).
- 100H'ın karesi ve 10000H / 100H. 100H 8 bite sığmadığı için `MOV AX, 100H` ve `MUL AX` ile 16 bitlik çarpma yapılır. Sonuç DX = 0001H, AX = 0000H, yani 10000H olur. Bu değeri 100H'a bölmek için bölünen DX:AX'e yerleştirilir: `XOR AX, AX`, `MOV DX, 1`, `MOV BX, 100H`, `DIV BX`. Sonuçta AX = 0100H (bölüm), DX = 0 (kalan) olur. Hoca DX'e önce yanlışlıkla 10H yazdı. Bu, bölüneni 100000H yapacağı için düzeltildi.
- Komut süresi. Hoca komut tablosundan (1to1_instruction.pdf, ekrandan, 01:40:00) `MOV r16, idata` için 4, `XOR r16, r16` için 3 clock cycle okudu. XOR'da aynı bitler 0 verdiği için bir sayının kendisiyle XOR'u sıfırdır. Bu nedenle `XOR AX, AX` daha kısa sürede AX'i sıfırlar. Bellek operandlı komutlarda tabloda "+EA" ile gösterilen etkin adres hesaplama süresi de eklenir. Hoca örnek olarak yalnız taban ya da yalnız indis için 5, taban + indis için 7 clock eklendiğini okudu.
  - Ders sonrası not: Hoca doğrudan yer değiştirme (displacement) için 9 clock dedi. 8086 tablolarında yalnız yer değiştirme için büyük olasılıkla 6, yer değiştirme + taban ya da indis için 9 clock verilir.
  - Ders sonrası not (bir öğrencinin sorusu): Hoca 8086'nın en fazla 2 MHz ile çalıştığını, bir saat darbesinin 0,2 µs, bir komut adımının 0,8 µs sürdüğünü söyledi. Doğrusu: 2 MHz'te bir saat periyodu $1 / (2 \times 10^6) = 0{,}5\ \mu s$'dir. Süre, tablodaki clock sayısı ile periyodun çarpımıdır; 4 clock'luk bir komut 2 µs sürer. Tablodaki değer zaten clock sayısı olduğu için T1–T4 adımları ayrıca çarpılmaz. 8086 da büyük olasılıkla 5–10 MHz sürümlerle üretilmiştir.
- Koşullu dallanmanın bayraklarla kararı. İşaretsiz `CMP A, B` sonrasında A > B ise çıkarmada borç oluşmaz (CF = 0) ve sonuç sıfır değildir (ZF = 0). A ≥ B iki durumu birleştirir: (CF = 0, ZF = 0) veya (CF = 0, ZF = 1). Ortak koşul CF = 0'dır. A ≤ B için (CF = 0, ZF = 1) veya (CF = 1, ZF = 0) birleşir, sonuç CF veya ZF = 1 olur. İşaretli sayılarda A > B olduğunda ya taşma yoktur ve SF = OF = 0'dır, ya da büyük pozitif bir sayıdan küçük bir negatif sayı çıkarılmış ve taşma olmuştur, bu durumda SF = OF = 1 olur. Yani koşul ZF = 0 ve SF = OF'dir. A ≤ B bunun değilidir: De Morgan kuralıyla ZF = 1 veya SF ≠ OF bulunur.
- İşaretli/işaretsiz örnek (ekrandan, 02:15:00). A = FFH, B = 1 iken `CMP A, B` ve `JA etiket` dallanır, çünkü işaretsiz 255 > 1'dir. `JG etiket2` dallanmaz, çünkü işaretli olarak −1 > 1 değildir. Dallanma olmazsa bir alt satırdan devam edilir. Etiket kodun aşağısındaysa akış oraya sonunda yine ulaşabilir. Bu yüzden if-then-else yapısı dikkatle bağlanmalıdır.
- JMP FAR PTR. `JMP FAR PTR idata1:idata2` ile CS ← idata1, IP ← idata2 olur. Bellek biçiminde ardışık iki sözcük IP ve CS'ye yüklenir. emu8086 bu komutu kabul etmedi, DOSBox'taki DEBUG ile çalıştırıldığında CS ve IP'nin verilen değerlerle yüklendiği gösterildi.
- If-then-else örneği (ekrandan, 02:40:00). AX = 0 ise BX = 2, değilse BX = 1, sonra her iki durumda CX = 5:

```text
CMP AX, 0
JE etiket1
MOV BX, 1        ; false kolu
JMP etiket3      ; unutulursa MOV BX, 2 de çalışır
etiket1:
MOV BX, 2        ; true kolu
etiket3:
MOV CX, 5
```

- Bir kolu boş örnek (ekrandan, 02:45:00). AX = 0 ise BX = 1, false kolu boş. Koşul dolu kola göre yazılırsa `CMP AX, 0`, `JZ etiket1`, `JMP etiket2`, `etiket1: MOV BX, 1`, `etiket2: MOV CX, 5` gerekir. Koşul boş kol için yazılırsa `CMP AX, 0`, `JNZ etiket1`, `MOV BX, 1`, `etiket1: MOV CX, 5` yeterlidir: bir etiket ve bir JMP komutu eksilir.
- Yığın (bir öğrencinin sorusu). Yığın bir yazmaç değil, RAM'de bir bölgedir. SP yığının tepesini gösterir. Yığına değer atıldıkça SP ikişer azalır (yüksek adresten düşük adrese), çekildikçe ikişer artar. Alt programlarda ve kesmelerde dönüş adresi burada tutulur. Fonksiyonlar arası parametre aktarımı da yığın üzerinden yapılabilir. Segment değerleri program belleğe yüklenirken işletim sistemince atanır. SS'yi elle değiştirmek başka bir programın alanını bozabileceği için yapılmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
