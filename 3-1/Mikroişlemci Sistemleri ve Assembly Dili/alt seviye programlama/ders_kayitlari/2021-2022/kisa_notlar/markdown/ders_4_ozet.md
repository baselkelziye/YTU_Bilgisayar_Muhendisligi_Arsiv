# Ders 4 Çalışma Özeti

## Genel Konular

- Çarpma ve bölme komutları: MUL, IMUL, DIV, IDIV
  - MUL ve DIV operandları işaretsiz, IMUL ve IDIV işaretli sayı olarak değerlendirir. Bit gösterimi tektir; `1111 1111B` MUL için 255, IMUL için -1 demektir. Anlamı kullanılan komut belirler.
  - Tek operand alırlar, gerisi gizli operanddır. 8 bitlik operandda `AX ← AL · src`; 16 bitlik operandda `DX:AX ← AX · src` (sonucun yüksek 16 biti DX'e, düşük 16 biti AX'e yazılır).
  - Bölmede 8 bitlik operandla AX bölünür: bölüm AL'ye, kalan AH'ye yazılır. 16 bitlik operandla DX:AX bölünür: bölüm AX'e, kalan DX'e yazılır.
  - Operand bir yazmaç ya da bellek adresi olabilir. Bellek operandında boyut `BYTE PTR` ya da `WORD PTR` ile belirtilmelidir. Sabit (immediate) operand verilemez; `IMUL -1000` gibi bir yazım en sık yapılan hatadır.
- Çarpma ve bölme örnekleri (ekrandan, 00:15:00, 00:20:00, 00:25:00, 00:30:00)
  - 130 · 552: 552 sekiz bite sığmadığı için 16 bitlik çarpma gerekir: `MOV AX, 552` / `MOV BX, 130` / `MUL BX`. Sonuç DX:AX'te, BX değişmez.
  - (-2) · (-1000): `MOV AX, -2` (AX ← 0FFFEH) / `MOV BX, 0FC18H` (-1000) / `IMUL BX`. Sonuç DX = 0000H, AX = 07D0H = 2000.
  - Aynı değerlerle yanlışlıkla `MUL BX` çalıştırılınca emu8086'da DX:AX = FC16 07D0H çıktı; değerler işaretsiz (65534 · 64536) çarpılmıştı.
  - `DX = FFFFH`, `AX = FFFFH`, `BX = 1`, `DIV BX`: bölüm FFFFFFFFH olur, 16 bite sığmaz; bölmede de taşma olabilir.
- Örnek: Celsius'tan Fahrenheit'e dönüşüm (ekrandan, 00:35:00, 00:40:00, 00:45:00)
  - Formül $y = 1.8x + 32$. 8086'da kesirli işlem olmadığı için $y = \frac{18x}{10} + 32$ biçimine getirilir. Önce çarpma, sonra bölme yapılır; tersi tamsayı bölmede hassasiyet kaybettirir.
  - Kod: `MOV AL, -40` / `MOV DL, 18` / `IMUL DL` / `MOV BL, 10` / `IDIV BL` / `ADD AL, 32`. Sonuç AL = -40 (−40 °C = −40 °F).
  - Girdinin aralığına göre 8 ya da 16 bitlik çarpma/bölme seçilmelidir.
  - Ardışık çarpma ve bölmede gizli operandların (AL, AX, DX:AX) ortak olması kolaylık sağlar.
- Mantıksal komutlar: NOT, AND, OR, XOR, TEST
  - Hepsi bitwise çalışır: iki operandın aynı sıradaki bitleri işleme girer, sonuç birinci operandın o bitine yazılır. Lojik (true/false) işlemden farklıdır.
  - NOT bire tümleyen alır: `MOV AL, 5AH` / `NOT AL` → AL = 0A5H (ekrandan, 00:50:00). İkiye tümleyeni NEG alır: `MOV AL, 1` / `NEG AL` → AL = 0FFH = -1.
  - XOR: aynı bitler 0, farklı bitler 1 verir ($Z = \bar{A}B + A\bar{B}$). `XOR DX, DX` DX'i sıfırlar.
  - TEST, AND yapar ama sonucu saklamaz, yalnız bayrakları etkiler. CMP de çıkarma yapıp yalnız bayrakları etkiler. İkisi koşullu dallanmadan önce kullanılır.
  - Bellek operandı ile sabit veriliyorsa (`AND [100H], 0F0H`) boyut belirsizdir, `BYTE PTR`/`WORD PTR` gerekir (ekrandan, 01:20:00).
- Bit maskeleme
  - AL'nin 6. biti 1 mi 0 mı: `TEST AL, 40H`. Sonuç 0 ise (ZF = 1) bit 0, değilse (ZF = 0) bit 1 (ekrandan, 01:05:00). AND de olur ama AL bozulur; TEST AL'yi bozmaz.
  - Bir biti 1 yapmak için OR, 0 yapmak için AND, tümlemek için XOR kullanılır. Değişmeyecek bitler OR ve XOR'da 0, AND'de 1 maskelenir.
- Dallanma komutları
  - Gruplar: koşullu dallanma (basit, işaretsiz, işaretli), koşulsuz dallanma (JMP), çağırma (CALL, INT) ve dönüş (RET, RETF, IRET) komutları.
  - Basit koşullu dallanma tek bayrağa bakar: JE/JZ (ZF=1), JNE/JNZ (ZF=0), JS/JNS, JO/JNO, JP/JPE ve JNP/JPO, JC/JNC (ekrandan, 01:55:00).
  - İşaretsiz: JB/JNAE/JC, JA/JNBE, JAE/JNB/JNC, JBE/JNA. İşaretli: JL/JNGE, JG/JNLE, JGE/JNL, JLE/JNG.
  - Aynı satırdaki eş adlı komutların makine kodu aynıdır. Hangisinin yazılacağı algoritmadaki karşılaştırmaya göre seçilir; okunurluğu artırır.
  - Koşul doğruysa etikete dallanılır, yanlışsa bir sonraki satırla devam edilir.
- Aynı gösterim, farklı karşılaştırma sonucu (ekrandan, 01:45:00)
  - `MOV AL, 11111111B` / `MOV BL, 01111111B` / `CMP AL, BL`. JA (işaretsiz) 255 > 127 diye dallanır; JG (işaretli) -1 > 127 yanlış olduğu için dallanmaz.
- İşlemcinin koşullara karar vermesi (ekrandan, 02:10:00)
  - İşaretsiz: `>` için CF=0 ve ZF=0; `≥` için CF=0; `=` için ZF=1; `≤` için CF=1 veya ZF=1; `<` için CF=1.
  - İşaretli: `>` için ZF=0 ve SF=OF; `≥` için SF=OF; `=` için ZF=1; `≤` için ZF=1 veya SF≠OF; `<` için SF≠OF.
  - Çıkarmada CF borç (borrow) görevi görür; küçük sayıdan büyük sayı çıkarılınca CF = 1 olur.
- Koşulsuz dallanma, çağırma ve dönüş
  - `JMP etiket` aynı kod kesiminde, `JMP FAR PTR` başka kod kesimine dallanır.
  - NEAR CALL yığına yalnız IP atar, RET ile dönülür. FAR CALL CS ve IP atar, RETF ile dönülür. Kesme çağrısı bayraklar, CS ve IP atar, IRET ile dönülür. JMP ile gidilen yerden yine JMP ile dönülür.
  - Kesmenin üç kaynağı: INT komutu, işlem sonucu oluşan özel durumlar (sıfıra bölme gibi), donanım kesmeleri.
- if yapılarının assembly karşılığı (ekrandan, 02:35:00, 02:40:00)
  - if-then-else: hangi kola göre koşul yazılırsa yazılsın iki dallanma komutu (bir koşullu, bir JMP) gerekir.
  - if-null-else ve if-null-then (bir kolu boş olan yapılar): koşul boş kola göre yazılırsa tek koşullu dallanma yeter.
- Yığın komutları: PUSH, POP, PUSHF, POPF
  - Hepsi word ile çalışır. PUSH SP'yi 2 azaltır, POP 2 artırır. PUSHF/POPF bayrak yazmacını yığına atar/yığından alır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Gösterim tektir, işaret anlamını komut verir
  - MUL/IMUL, DIV/IDIV ve JA/JG gibi komut çiftlerinde aynı bitler farklı değerlendirilir. CMP sonucu ve bayraklar işaretten bağımsızdır; işaret anlamı ondan sonra kullanılan dallanma komutunda ortaya çıkar.
- Çarpma ve bölmede sabit operand verilmez
  - Sayı önce bir yazmaca alınmalıdır. Bellek operandında PTR ile boyut belirtilmelidir.
- Önce çarp, sonra böl
  - Tamsayı bölmesi yüzünden önce bölmek, -10 ile 10 arasındaki girdileri 0'a indirip büyük hassasiyet kaybına yol açar.
- Girdi aralığını analiz et
  - Çarpma sonucunun işaretli 8/16 bit aralığına sığıp sığmadığına bakılarak işlem genişliği seçilmelidir.
- Harfle başlayan onaltılık sayının başına 0 konur
  - `0FC18H` gibi. Konmazsa assembler sayıyı etiket sanıp hata verir.
- Akışa uygun dallanma komutunu seç
  - Akış diyagramında hangi karşılaştırma varsa koddaki komut da onun adını taşımalıdır (örneğin op1 > op2 için JG ya da JA); aksi okumayı çok zorlaştırır.
- Kolu boş olan if yapısında koşulu boş kola göre yaz
  - Kod tek dallanmayla kısalır. if-then-else için iki dallanma kaçınılmazdır.
- Gidiş ve dönüş komutu eşleşmelidir
  - CALL/RET, CALL FAR PTR/RETF, kesme/IRET.

## Kısa Tekrar Notları

- `MUL src`: 8 bitte `AX ← AL·src`, 16 bitte `DX:AX ← AX·src`. IMUL aynısı, işaretli.
- `DIV src`: 8 bitte AL ← AX/src, AH ← kalan; 16 bitte AX ← DX:AX/src, DX ← kalan. IDIV aynısı, işaretli.
- Bölüm hedef yazmaca sığmazsa bölme taşar.
- -1 = 0FFFFH, -2 = 0FFFEH, -1000 = 0FC18H (işaretsiz 64536).
- Sayı yazımı: `10` onluk, `01101001B` ikilik, `28H` onaltılık, `'a'` ASCII karşılığı.
- NOT bire tümleyen, NEG ikiye tümleyen.
- `XOR yazmaç, yazmaç` yazmacı sıfırlar.
- TEST = sonucu saklanmayan AND; CMP = sonucu saklanmayan SUB.
- Bit 1 yapma OR, 0 yapma AND, tümleme XOR.
- JA/JB/JAE/JBE işaretsiz; JG/JL/JGE/JLE işaretli; JE/JZ ikisinde de.
- İşaretli `≥`: SF = OF. İşaretsiz `>`: CF = 0 ve ZF = 0.
- NEAR CALL: IP; FAR CALL: CS, IP; kesme: bayraklar, CS, IP yığına atılır.
- if-then-else: 2 dallanma. Bir kolu boş if: koşul boş kola göre yazılırsa 1 dallanma.
- PUSH: SP − 2, POP: SP + 2; yığın işlemleri word iledir.

## Detaylı Açıklamalar

- Çarpma ve bölmede gizli operandlar
  - 16 bitlik iki sayının çarpımı 32 bite kadar çıkar. 8086'da 32 bitlik yazmaç olmadığı için DX ve AX birlikte sanal bir 32 bitlik yazmaç gibi kullanılır: yüksek anlamlı yarı DX'e, düşük anlamlı yarı AX'e yazılır. `MUL AL` AL'nin karesini AX'e yazar. `MUL BX` için AX önceden çarpılacak değerle hazırlanmalıdır. Bölmede tersi geçerlidir: 16 bitlik bölmeden önce bölünen DX:AX'te hazırlanır.
  - 130 · 552 örneğinde AX = 552, BX = 130 alınır ve `MUL BX` sonrası DX = 0001H olur.
  - Ders sonrası not: Hoca sonucu AX = 0914H yazdı (ekrandan, 00:20:00); hesap makinesine 552 yerine 522 girilmişti. 130 · 552 = 71760 = 0001 1850H olduğundan doğrusu DX = 0001H, AX = 1850H'dir.
  - (-2) · (-1000) örneğinde IMUL ile DX:AX = 0000 07D0H (2000) çıkar. Aynı gösterimle MUL çalıştırılınca 0FFFEH ve 0FC18H işaretsiz büyük sayılar olarak çarpılır ve FC16 07D0H elde edilir (ekrandan, 00:25:00).
  - `DIV BX` ile FFFF FFFFH sayısını 1'e bölmek 32 bitlik bir bölüm üretir ve AX'e sığmaz.
  - Ders sonrası not: Hoca bu durumda overflow bayrağının kurulduğunu ve "overflow kesmesi" oluştuğunu söyledi. 8086'da bölüm hedef yazmaca sığmazsa büyük olasılıkla 0 numaralı kesme (bölme hatası) oluşur ve bayrakların değeri tanımsızdır.
- Celsius'tan Fahrenheit'e dönüşüm
  - Tabloda Fahrenheit 32–212, Celsius 0–100 arasıdır (ekrandan, 00:35:00). 180 birimlik aralık 100 birime karşılık geldiği için $y = 1.8x + 32$ olur. 1.8 ile çarpmak yerine 18 ile çarpılıp 10'a bölünür.
  - x = −40 için: IMUL DL sonrası AX = −720 (0FD30H); IDIV BL sonrası AL = −72, AH = 0; ADD AL, 32 sonrası AL = −40.
  - 16 bitlik bölme yapılmak istense DX:AX hazırlanmalıdır. Derste önce DX'i `XOR DX, DX` ile sıfırlama yolu konuşuldu, sonra çarpım 16 bitte kaldığı için 8 bitlik `IDIV BL` yeterli görüldü.
  - Ders sonrası not: AX negatifken DX'i sıfırlamak DX:AX'i büyük bir pozitif sayıya çevirir (0000FD30H = 64816). İşaretli 16 bitlik bölmeden önce DX büyük olasılıkla AX'in işaretiyle doldurulmalıdır; bu derste anlatılmadı.
  - Ders sonrası not: Hoca x'in 0–100 aralığında 8 bitlik çarpma ve bölmenin yeteceğini söyledi. Çarpım (100 · 18 = 1800) AX'e sığar, ama `IDIV BL` bölümü AL'ye yazdığı için 180 işaretli 8 bite sığmaz ve bölme hatası oluşur. Bu kod büyük olasılıkla yalnız 18x/10 değerinin −128..127 aralığında kaldığı girdilerde (yaklaşık x ≤ 71) doğru çalışır.
- Bitwise mantıksal işlemler
  - Lojik işlemde değişkenin bütünü true/false olarak ele alınır (C'de 0 false, sıfırdan farklı her değer true). Bitwise işlemde her bit ayrı ayrı işlenir.
  - `XOR DX, DX` tüm bitleri aynı olan iki operandı karşılaştırdığı için DX'i sıfırlar. Hoca bunun `MOV DX, 0`'dan bir saat çevrimi daha hızlı olduğunu, 16 bitlik ALU'nun bütün bitleri tek seferde işlediğini söyledi.
  - TEST ile maskeleme: ilgilenilen bit maskede 1, diğerleri 0 yapılır. $y \land 1 = y$, $y \land 0 = 0$ olduğu için sonuç yalnız aranan bite bağlı kalır ve ZF'den okunur.
- Örnek soru: AX'in diğer bitlerini bozmadan 7. biti 0, 15. biti 1 yapan ve 1. bitini tümleyen komutlar (ekrandan, 01:25:00)
  - 15. bit: $x \lor 1 = 1$, $x \lor 0 = x$; OR maskesi yalnız 15. biti 1 olan 8000H.
  - 7. bit: $x \land 0 = 0$, $x \land 1 = x$; AND maskesi yalnız 7. biti 0 olan 0FF7FH.
  - 1. bit: $x \oplus 1 = \bar{x}$, $x \oplus 0 = x$; XOR maskesi yalnız 1. biti 1 olan 0002H.
  - <!-- BELİRSİZ: maskelerin tahtaya yazılmış onaltılık değerleri karelerde görünmüyor; değerler anlatılan kurala göre yazıldı. -->
- İşaretsiz ve işaretli karşılaştırma
  - `MOV AL, -10H` AL'ye F0H (1111 0000), `MOV BL, 200` BL'ye C8H (1100 1000) yükler (ekrandan, 01:40:00). JA bunları 240 ve 200, JG −16 ve −56 olarak görür; bu örnekte ikisi de dallanır.
  - Farkı göstermek için 255/−1 ve 127 seçildi: JA dallanır, JG dallanmaz.
- Bayraklardan karar verme
  - İşaretsiz `>` (JA): 240 − 40'ta CF = 0, ZF = 0; 240 − 240'ta ZF = 1; 40 − 240'ta CF = 1 (emu8086'da CF = 1, SF = 0 görüldü; ekrandan, 02:05:00). Yalnız birinci durum aranan durumdur, bu da CF = 0 ve ZF = 0 koşuluna karşılık gelir.
  - Ders sonrası not: Derste 240 − 40 için işaret bayrağının 0 olacağı konuşuldu. Sonuç 200 = C8H'nin en yüksek biti 1 olduğu için SF = 1 olur; işaretsiz karşılaştırmada SF'ye bakılmaz.
  - İşaretli `≥` (JGE): 8 bitlik sayılar −128..127 arasında bir çember gibidir; 127'ye 1 eklenince −128'e geçilir. Üç durum incelendi: büyük pozitif − çok küçük negatif (örnek 100 − (−100) = 200, taşar: OF = 1, SF = 1), büyük pozitif − küçük pozitif (OF = 0, SF = 0), küçük negatif − çok küçük negatif (örnek −5 − (−100) = 95: OF = 0, SF = 0). Eşitlikte ZF = 1, SF = 0, OF = 0. Hepsinde SF = OF olduğu için koşul SF = OF'dur (ekrandan, 02:15:00).
- Çağırma ve dönüş
  - CALL'ın yakın türleri: göreli sabit (`CALL 100` gibi), bellek ve yazmaç operandlı çağrılar; hepsi aynı kod kesiminde kalır, yalnız IP değişir. `CALL FAR PTR` iki sabitle (segment:ofset) ya da bellek adresiyle verilir; bellekteki ilk word IP'ye, sonraki word CS'ye yazılır.
  - Kesme çağrısında bayraklar da yığına atılır; böylece kesme alt programından dönüldüğünde ana programın bayrakları korunur.
  - Ders sonrası not: Hoca RETF'nin yığının en üstündeki değeri CS'ye, sonrakini IP'ye attığını söyledi. FAR CALL önce CS'yi sonra IP'yi attığı için yığının en üstünde büyük olasılıkla IP vardır; RETF önce IP'yi, sonra CS'yi çeker. IRET de sırasıyla IP, CS ve bayrakları çeker (hoca bunu dersin sonunda doğru sırayla söyledi).
  - Ders sonrası not: Hoca işlemcinin kesmeye girerken bayrakları sıfırladığını söyledi. 8086 kesmeye girerken büyük olasılıkla bütün bayrakları değil, yalnız IF ve TF bayraklarını sıfırlar.
- if yapıları (AX = 0 ise BX = 2, değilse BX = 1; sonra CX = 5)
  - True kola göre: `CMP AX, 0` / `JE LABEL1` / `MOV BX, 1` / `JMP EXIT` / `LABEL1: MOV BX, 2` / `EXIT: MOV CX, 5`. JMP konmazsa false kolu da `MOV BX, 2`'yi çalıştırır.
  - if-null-else (AX = 0 ise BX = 1): `CMP AX, 0` / `JNE FALSEKOL` / `MOV BX, 1` / `FALSEKOL: MOV CX, 5`. Tek dallanma yeter.
  - if-null-then (AX ≠ 0 ise BX = 1): `CMP AX, 0` / `JE TRUEKOL` / `MOV BX, 1` / `TRUEKOL: MOV CX, 5`. Tek dallanma yeter.
  - for için LOOP komutu vardır; while, do-while ve repeat-until koşullu dallanmalarla kurulur.
- Yığın
  - Yığın, SS:SP ile gösterilen bir bellek bölgesidir; adresler yukarı doğru azalır. Bir adres bir byte, bir word iki adres olduğu için SP 2'şer değişir. POP yazmaca ya da belleğe, PUSH yazmaçtan, bellekten ya da segment yazmacından (`PUSH DS`) çalışır.
  - Ders sonrası not: Hoca SP'nin "sıradaki boş gözü" gösterdiğini söyledi. 8086'da SP büyük olasılıkla yığına en son atılan word'ü gösterir; PUSH önce SP'yi 2 azaltır, sonra değeri yazar.
  - Ders sonrası not: Derste `PUSH 0FFFFH` gibi sabit atılabileceği söylendi. Sabit PUSH büyük olasılıkla 8086'da yoktur, 80186 ile gelmiştir; emu8086 bunu kabul edebilir.
  - PUSHF ve POPF, doğrudan adreslenemeyen bazı bayrakları değiştirmek için kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
