# Ders 1 Çalışma Özeti

## Genel Konular

- 8086 yazmaçlarının tekrarı (ekrandan, 00:10:00)
  - Yazmaçlar dört grupta toplanır: genel amaçlı yazmaçlar (AX, BX, CX, DX ve 8 bitlik parçaları AL/AH, BL/BH, CL/CH, DL/DH; SI, DI, SP, BP), segment yazmaçları (SS, CS, DS, ES), özel amaçlı yazmaç (IP) ve bayrak yazmacı (CF, PF, AF, ZF, SF, TF, IF, DF, OF).
  - AX akümülatördür. Akümülatöre özel komutlar daha az bitle kodlanır ve daha hızlı çalışır. MUL/DIV işlemlerinde gizli operand, giriş/çıkış (IN/OUT) işlemlerinde varsayılan operanddır.
  - BX (base register) bir tablonun ya da dizinin başlangıç adresini tutar. SI (source index) ve DI (destination index) bu başlangıçtan itibaren bir gözü indisler: `[BX+SI]` gibi.
  - CX (count register) döngü işlemlerinde, DX (data register) veri işlemlerinde kullanılır. DX de MUL/DIV'de gizli operand, IN/OUT'ta varsayılan operanddır.
  - SP yığının en üstündeki anlamlı veriyi gösterir ve PUSH, POP, CALL, INT, RET gibi işlemlerde mikroişlemci tarafından otomatik güncellenir. BP'yi mikroişlemci değiştirmez. SP o anda BP'ye kopyalanarak yığında sabit bir referans ("çapa") kurulur ve verilere BP'ye göre erişilir.
- Yazmaç kavramı ve bellek hiyerarşisi (ekrandan, 00:15:00)
  - Hiyerarşi: mikroişlemci içindeki yazmaçlar, önbellek (cache), ana bellek (RAM), ikincil depolama (disk vb.).
  - Yazmaçtan diske doğru kapasite artar, birim üretim maliyeti ve hız azalır. Bu yüzden yazmaç sayısı azdır.
  - Yazmaç: mikroişlemcinin içinde yer alan, adıyla erişilebilen yüksek hızlı bellek birimi. Mikroişlemcinin içinde yazmaçlar, kontrol birimi, ALU ve bunları bağlayan yollar vardır.
- Segment ve offset ile 20 bitlik adres (ekrandan, 00:25:00)
  - 8086'nın yazmaçları 16 bit, adres yolu 20 bittir. Fiziksel adres $\text{segment} \times 10\text{H} + \text{offset}$ ile oluşturulur. Onaltılık gösterimde 10H ile çarpmak sona bir 0 eklemektir.
  - Eşleşmeler: SS ile BP/SP (yığının en üst adresi), CS ile IP (bir sonraki adımda çalıştırılacak komutun adresi), DS/ES ile BX, SI, DI (veri kesimindeki değişkenin adresi).
  - Bir assembly programı üç kesimden oluşur: veri kesimi (data segment), kod kesimi (code segment) ve yığın kesimi (stack segment).
  - IP bir offset yazmacıdır ve otomatik güncellenir; örneğin 3 baytlık bir komut yürütülünce IP 3 artar.
- Bayraklar
  - CF: işaretsiz işlemlerde taşma. OF: işaretli işlemlerde taşma. ZF: sonuç sıfırsa 1. SF: sonucun en yüksek anlamlı biti.
  - PF (eşlik): tek (odd) eşlikte veri ve eşlik biti birlikte tek sayıda 1 içerir, çift (even) eşlikte çift sayıda. Örnek veri `10101111` (altı tane 1): tek eşlik biti 1, çift eşlik biti 0 (ekrandan, 00:30:00). Seri haberleşmede hata tespiti için kullanılır.
  - AF: 4 bitlik gruplar arasında elde oluşup oluşmadığını tutar, BCD işlemleriyle ilgilidir.
  - TF = 1 ise her komuttan sonra kesme oluşur (adım adım çalıştırma, hata ayıklama). IF = 1 ise donanım kesmeleri kabul edilir. DF katar (string) işlemlerinin yönünü belirler.
- 32 ve 64 bitlik x86 yazmaçları
  - 80386'dan itibaren 32 bitlik genişletilmiş yazmaçlar vardır: EAX, EBX, ..., ESI, EDI, EIP. EAX'ın düşük 16 biti AX, AX'in 8 bitlik parçaları AL ve AH'dir. Ek olarak FS ve GS segment yazmaçları gelir (korumalı/sanal mod tabloları ile ilgili).
  - 32 bitlik programda bellek erişimi köşeli parantez içinde EBX, ESI gibi 32 bitlik yazmaçlarla yapılır.
  - 64 bitlik mimaride RAX, RBX, RCX ... yazmaçları vardır; RAX'in düşük 32 biti EAX'tir. Sekiz ek genel amaçlı yazmaç ve vektör yazmaçları da bulunur.
  - 8086 gerçek modda (real mode) çalışır: program 1 MB'lık hafıza uzayının herhangi bir noktasına erişebilir.
- Komut yapısı ve MASM sözdizimi (ekrandan, 00:45:00 ve 00:50:00)
  - Genel biçim: `{ETIKET:} MNEMONIC {{operand1,} operand2} {; yorum}`. Süslü parantezler isteğe bağlı kısımları gösterir.
  - Mnemonic, komutu temsil eden kısaltmadır (ADD, INC, MOV). 8086'da komutlar 0, 1 ya da 2 operand alır; 3 operandlı komut yoktur.
  - İşlem sağdan sola tanımlıdır: `ADD AX, BX` sonucunda $AX \leftarrow AX + BX$, BX değişmez. Sonuç birinci operanda yazılır.
  - Operand tipleri uyumlu olmalıdır. `ADD AL, BX` ve `VAR1 DB 35H` tanımından sonra `MOV AX, VAR1` "type mismatch" hatası verir.
  - Etiket örneği (sonsuz döngü): `A1: ADD AX, [SI]` / `INC SI` / `JMP A1`.
- Komutlardaki kısaltmalar (ekrandan, 00:55:00)
  - acc (AL/AX), reg (8/16 bitlik yazmaç), regb (8 bitlik), regw (16 bitlik), sreg (CS, SS, DS, ES), mem (bellek adresi), idata (8/16 bitlik sabit), disp8/disp16 ($-128 \ldots 127$ / $-32768 \ldots 32767$), dest/src (hedef/kaynak).
  - Köşeli parantez bellek erişimidir; içindeki değer offsettir. Veri erişiminde varsayılan kesim DS, yığın erişiminde SS'dir.
  - `MOV AX, [100H]` 100H adresinin içeriğini, `MOV AX, 100H` ise 100H sabitini AX'e atar.
  - Dallanma komutlarında hedef mutlak adres olarak değil, komutun bulunduğu yere göre işaretli bir uzaklık (displacement) olarak tutulur.
- Veri aktarım komutları: MOV
  - `MOV dest, src`: kaynaktaki içeriği hedefe kopyalar.
  - Geçersiz durumlar: iki bellek operandı (`MOV [100H], [200H]`), iki segment yazmacı (`MOV SS, CS`), segment yazmacına sabit (`MOV DS, 100H`), farklı boyutlu operandlar (`MOV AL, DX`, `MOV AH, CS`).
  - Bellekten belleğe aktarım olmaz, çünkü veri her zaman önce mikroişlemciye okunur, sonra aktarılır (DMA'da ise mikroişlemci devrede değildir).
  - Geçersiz durumlar ara bir 16 bitlik yazmaçla çözülür: `MOV AX, CS` / `MOV SS, AX` ve `MOV AX, 100H` / `MOV DS, AX`. Ara yazmaç olarak AL kullanılamaz.
  - `MOV mem, idata` için tip belirsizdir; `WORD PTR` ya da `BYTE PTR` yazılmalıdır.
  - Bellekte bir göz 1 bayttır. 8086 little endian'dır: çok baytlı verinin düşük anlamlı baytı düşük adrese yazılır.
- LEA, LDS, LES, XCHG, XLAT
  - `LEA reg16, değişken`: değişkenin kendi segmentindeki offsetini (adresini) 16 bitlik yazmaca yükler, değerini değil.
  - `LDS reg, mem`: bellekteki word'ü yazmaca, ondan sonraki word'ü DS'ye yükler. `LES` aynı işi ES ile yapar. Uzak bir kesimdeki veriye erişmek için kullanılır.
  - `XCHG`: iki operandın yerini değiştirir (yazmaç-yazmaç, bellek-yazmaç); tip uyumu gerekir.
  - `XLAT`/`XLATB`: operand almaz; BX'in gösterdiği tablonun AL indisli baytını AL'ye getirir.
- Aritmetik komutlar (ekrandan, 02:35:00)
  - ADD (toplama), ADC (eldeli toplama: $AX \leftarrow AX + BX + CF$), SUB (çıkarma, ikiye tümleyen: $AX + (-BX)$), SBB (borçlu çıkarma), INC, DEC, NEG (ikiye tümleyen negatif), CMP, MUL, IMUL, DIV, IDIV.
  - CMP çıkarma yapar ama sonucu saklamaz, yalnız bayrakları günceller; ardından koşullu dallanma kullanılır (ekrandan, 03:20:00).
  - Bellek ve sabitle yapılan ADD/ADC/SUB/INC/DEC işlemlerinde PTR gerekir (ekrandan, 03:15:00).
- 32 bitlik iki sayının 16 bitlik komutlarla toplanması (ekrandan, 02:50:00 ve 03:10:00)
  - `VAR1 DD 6789ABCDH`, `VAR2 DD ABCD1234H`, `VAR3 DQ 0`. Düşük word'ler ADD ile, yüksek word'ler ADC ile toplanır, son elde `ADC BYTE PTR [BX+4], 0` ile VAR3'e eklenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Köşeli parantez içinde ne yazılabildiğini bilmek gerekir
  - Bellek erişiminde yalnız BX, SI, DI (ve bunların izin verilen toplamları) ile sabit kullanılabilir. AX, CX, DX ya da 8 bitlik yazmaçlar köşeli parantez içine yazılamaz. Bunu bilmeyen hatalı komut yazar.
- CF ve OF ayrımı
  - CF işaretsiz, OF işaretli sayı işlemlerindeki taşmayı gösterir. Hoca bunu "çok önemli bir nokta" olarak vurguladı.
- Tip uyumu
  - Operandların boyutu aynı olmalıdır. Bellek ile sabit arasındaki işlemlerde boyut `WORD PTR` ya da `BYTE PTR` ile açıkça yazılmalıdır.
- LEA değeri değil adresi verir
  - `LEA BX, ASAYISI` BX'e 13'ü değil, ASAYISI'nın offsetini (0) yükler. `MOV BX, ASAYISI` ise değeri (13) yükler.
  - Offsetleri elle sabit yazmak kodu statikleştirir; başa yeni bir değişken eklenince bütün hesap kayar. LEA bakımı kolaylaştırır.
- Veri aktarım komutları bayrakları etkilemez
  - 32 bitlik toplamada ADC'den sonra gelen MOV komutları CF'yi bozmaz. Araya aritmetik bir komut girerse elde kaybolabilir; hata ayıklarken buna bakılmalıdır.
- Yazım biçimi
  - Okunabilirlik için komutlar, yazmaçlar ve değişkenler büyük harfle yazılmalıdır (assembler büyük/küçük harfe duyarlı değildir).

## Kısa Tekrar Notları

- Fiziksel adres $= \text{segment} \times 10\text{H} + \text{offset}$. DS = 0100H, offset = 0001H ise fiziksel adres 01001H.
- CS:IP sıradaki komutu, SS:SP/BP yığını, DS/ES:BX/SI/DI veriyi gösterir.
- İki operandlı komutta sonuç birinci operanda yazılır.
- Bellekten belleğe, segmentten segmente ve segmente sabit MOV yoktur; ara 16 bitlik yazmaç kullanılır.
- 8 bitlik yazmaca 255'ten büyük değer atanamaz: `MOV CH, 300` ve `MOV BL, 100H` hatalıdır.
- `MOV DX, -1` sonucunda DX = FFFFH, `MOV BL, 'A'` sonucunda BL = 65 (41H), `MOV AX, 1` sonucunda AX = 0001H.
- Little endian: 250H'de ABH, 251H'de 12H varsa `MOV BX, [250H]` sonucu BX = 12ABH, `MOV AL, [250H]` sonucu AL = ABH.
- `MOV WORD PTR [100H], 12H`: 100H ← 12H, 101H ← 00H. `MOV BYTE PTR [100H], 12H`: yalnız 100H ← 12H.
- LEA offseti, LDS/LES offset ile birlikte segmenti de yükler.
- CMP = sonucu saklanmayan SUB.
- Çok word'lü toplamada en düşük word ADD, sonrakiler ADC ile toplanır.

## Detaylı Açıklamalar

- MOV örnekleri ve geçerlilik (ekrandan, 01:35:00 ve 01:45:00)
  - `MOV CH, 300` geçersizdir: 300 = 12CH, 8 bite (0-255) sığmaz. `MOV AX, 1234H` geçerlidir (16 bit). `MOV BL, 'A'` BL'ye 'A'nın ASCII kodu 65'i yükler. `MOV DX, -1` DX'e -1'in ikiye tümleyeni FFFFH'yi yükler.
  - `MOV AX, 1` geçerlidir; sabit 16 bite tamamlanır ve AX = 0001H olur. `MOV AL, 1` ise AL = 01H yapar.
  - `MOV AX, BX` ve `MOV DL, CL` geçerli; `MOV AH, CS` geçersizdir (8 bit ve 16 bit). SI'ye yazmaçtan atama yalnız 16 bitlik yazmaçla yapılabilir.
  - Segment yazmacı ile genel yazmaç arasında iki yönde aktarım yapılabilir. Bellek ile segment yazmacı arasında da aktarım yapılabilir: `MOV DS, [20H]` ve `MOV [20H], DS` 16 bitlik işlemlerdir; ikincisinde 20H ve 21H gözleri DS'nin düşük ve yüksek baytıyla dolar.
- WORD PTR ve BYTE PTR (ekrandan, 01:40:00 ve 01:45:00)
  - `MOV [100H], 12H` komutunda 12H'nin 0012H olarak mı (word) yoksa 12H olarak mı (byte) yazılacağı belli değildir.
  - Başlangıçta 100H ve 101H gözlerinde FFH olsun. `MOV WORD PTR [100H], 12H` sonrası 100H = 12H, 101H = 00H olur. `MOV BYTE PTR [100H], 12H` sonrası 100H = 12H olur, 101H FFH olarak kalır.
- LEA örneği (ekrandan, 02:10:00 ve 02:20:00)
  - Veri kesimi: `ASAYISI DW 13`, `BSAYISI DW 15`, `GCD DW ?`, `DENEME DW -1`. Bellek yerleşimi (offset 0'dan itibaren): `0D 00 0F 00 ?? ?? FF FF`.
  - `LEA BX, ASAYISI` → BX = 0000H, `LEA SI, BSAYISI` → SI = 0002H, `LEA DI, DENEME` → DI = 0006H.
  - `MOV DX, [DI]` → DX = FFFFH. `MOV AL, [BX]` → AL = 0DH. `MOV AH, [BX+1]` → AH = 00H. Böylece word olarak tanımlanmış verinin tek bir baytına erişilebilir; bu, C'de bir int göstericisini char göstericisine çevirmeye benzer.
  - Veri kesimindeki tanımların makine kodu karşılığı yoktur; assembler değerleri hazırlar, program yüklenince doğrudan belleğe yazılır. DS değeri program çalıştırılırken işletim sistemi tarafından belirlenir.
- LDS örneği (ekrandan, 02:30:00)
  - `UZAK_OFF DW 1234H`, `UZAK_SEG DW 0ABCDH`. Harfle başlayan onaltılık sabitin başına 0 konur.
  - `LDS BX, UZAK_OFF` → BX = 1234H, DS = ABCDH. Ardından `MOV AL, [BX]` ABCDH:1234H adresindeki baytı AL'ye okur (fiziksel adres ACF04H).
- 32 bitlik toplama kodu (ekrandan, 03:10:00)

```text
LEA BX, VAR3
LEA SI, VAR1
LEA DI, VAR2
MOV AX, [SI]          ; AX <- ABCDH (VAR1 düşük word)
MOV DX, [SI+2]        ; DX <- VAR1 yüksek word
ADD AX, [DI]          ; AX <- ABCDH + 1234H
ADC DX, [DI+2]        ; DX <- CF + VAR1 yüksek + VAR2 yüksek
MOV [BX], AX
MOV [BX+2], DX
ADC BYTE PTR [BX+4], 0
```

  - Sonuç (python ile kontrol edildi): AX = BE01H (CF = 0), DX = 1356H (CF = 1), [BX+4] = 01H. VAR3 = 000000011356BE01H; bellekte `01 BE 56 13 01 00 00 00`.
  - En düşük word'lere dışarıdan elde gelemeyeceği için orada ADD yeterlidir.
  - Daha pratik bir yol bayt bayt döngüyle toplamaktır; döngüler henüz görülmediği için word'ler üzerinden yapıldı.
- Ders sonrası notlar
  - Hoca köşeli parantez içinde `[SI+DI]` ve `[BX+SI+DI+sabit]` yazılabileceğini söyledi; 8086'da bu biçimler geçersizdir. Geçerli biçimler bir taban (BX ya da BP) ile bir indisin (SI ya da DI) en fazla birer kez kullanıldığı toplamlar ve isteğe bağlı sabittir: `[BX]`, `[BP]`, `[SI]`, `[DI]`, `[BX+SI]`, `[BX+DI]`, `[BP+SI]`, `[BP+DI]`, `[sabit]`. BP ile varsayılan kesim SS'dir.
  - Hoca 8 bitlik uzaklıklı dallanmayı "near", 16 bitlik uzaklıklıyı "far" diye adlandırdı. Intel terminolojisinde 8 bitlik uzaklık "short", aynı kesim içindeki 16 bitlik uzaklık "near" dallanmadır; "far" dallanma CS'yi de değiştirir.
  - Hoca `MOV CS, SI` gibi bir atamanın geçerli olduğunu söyledi; CS, MOV ile hedef olarak yazılamaz (CS yalnız uzak dallanma, çağrı, dönüş ve kesmelerle değişir). Ters yön (`MOV SI, CS`) geçerlidir.
  - Hoca INC örneğinde byte işleminde CF'nin 1 olduğunu söyledi; INC ve DEC CF'yi etkilemez. `INC BYTE PTR [100H]` (FFH) sonrası 100H = 00H ve ZF = 1 olur, CF değişmez.
  - Hoca AF'yi her 4 bitlik grup arası elde gibi anlattı; AF yalnız en düşük 4 bitten (bit 3'ten bit 4'e) oluşan eldeyi gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
