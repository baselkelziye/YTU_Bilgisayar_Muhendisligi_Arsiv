# Ders 8 Çalışma Özeti

## Genel Konular

- Döngü komutları ile tekrarlama önekleri (ekrandan, 00:05:00)
  - `LOOP`: CX ≠ 0 olduğu sürece etikete dallanır. `LOOPZ`: CX ≠ 0 ve ZF = 1 iken, `LOOPNZ`: CX ≠ 0 ve ZF = 0 iken döngüye devam eder.
  - Dizi komutlarının önekleri aynı mantıkla çalışır: `REP` CX ≠ 0 iken, `REPZ`/`REPE` CX ≠ 0 ve ZF = 1 iken, `REPNZ`/`REPNE` CX ≠ 0 ve ZF = 0 iken peşindeki dizi komutunu tekrarlar.
  - Fark: `LOOP`'tan sonra bir etiket, `REP` öneklerinden sonra bir dizi komutu gelir. Her tekrarda CX otomatik olarak 1 azaltılır.
- Dizi (string) komutları (ekrandan, 00:10:00 ve 00:20:00)
  - `MOVS` (move string): DS:[SI]'daki diziyi ES:[DI]'ya kopyalar.
  - `CMPS` (compare string): kaynaktan hedefi çıkarır (DS:[SI] − ES:[DI]); sonuç saklanmaz, yalnız bayraklar etkilenir.
  - `SCAS` (scan string): AL/AX'teki referans değeri ES:[DI]'daki elemanla karşılaştırır (AL − ES:[DI] ya da AX − ES:[DI]).
  - `LODS` (load string): DS:[SI]'daki elemanı AL/AX'e yükler. `STOS` (store string): AL/AX'teki değeri ES:[DI]'ya yazar.
  - Her komutun byte (`MOVSB`, `CMPSB`, ...) ve word (`MOVSW`, `CMPSW`, ...) sürümü vardır.
  - Slayttaki tanımlar: MOVS bir bellek bölgesini başka bir bölgeye kopyalar, CMPS iki bölgenin içeriğini karşılaştırır, SCAS bölgenin içeriğini AX/AL ile karşılaştırır, LODS bölgedeki değeri AX/AL'ye yükler, STOS bölgeyi AX/AL değeriyle doldurur.
- DF bayrağı ve SI/DI'nin değişimi (ekrandan, 00:15:00 ve 00:50:00)
  - DF = 0: SI/DI dizinin ilk elemanını gösterir ve her adımda byte komutlarında 1, word komutlarında 2 artar.
  - DF = 1: SI/DI dizinin son elemanını gösterir ve her adımda 1 ya da 2 azalır.
  - `CLD` DF'yi 0, `STD` DF'yi 1 yapar. İkisi de operand almaz.
  - SI/DI değişimini dizi komutunun kendisi yapar; `REP` yalnız tekrarı (CX ≠ 0 kontrolünü) sağlar.
- Dizi komutu kullanma adımları
  - SI ve DI'yı dizinin başına ya da sonuna ayarla (`LEA SI, dizi1`), buna göre DF'yi ayarla (`CLD`/`STD`), CX'e eleman sayısını (bayt sayısını değil) yükle, uygun önekle dizi komutunu çalıştır.
- Örnekler (ekrandan, 00:30:00 – 01:00:00)
  - Kopyalama: `LEA SI, dizi1` / `LEA DI, dizi2` / `CLD` / `MOV CX, n` / `REP MOVSB`.
  - İki dizide ilk farklı eleman: `REPZ CMPSB`, ardından `JNZ farkli`.
  - Word dizisinde 8 değerini arama: `MOV AX, 8`, `REPNZ SCASW`, ardından `JZ buldum`.
  - Diziyi sıfırlama: `XOR AL, AL` / `REP STOSB`.
  - Diziyi 1'den 25'e kadar doldurma: `REP` kullanılamaz, `STOSB` + `INC AL` + `LOOP` ile yapılır.
- CBW ve CWD (ekrandan, 01:05:00)
  - `CBW`: AL'yi işaret bitini koruyarak (sign extend) AX'e genişletir. `CWD`: AX'i işaretini koruyarak DX:AX ikilisine genişletir. Operand almazlar.
- Giriş/çıkış komutları: IN ve OUT (ekrandan, 01:30:00 ve 01:35:00)
  - Port adresi 8 bite sığıyorsa sabit (p8) verilir: `IN AL, p8`, `IN AX, p8`, `OUT p8, AL`, `OUT p8, AX`.
  - Sığmıyorsa port adresi DX ile verilir: `IN AL, DX`, `IN AX, DX`, `OUT DX, AL`, `OUT DX, AX`.
  - MOV belleğe, IN/OUT G/Ç birimlerine erişir; mikroişlemci bunu M/IO ucuyla ayırt ettirir. IN okuma (RD), OUT yazma (WR) ucunu etkin yapar.
  - 8086'nın bellek uzayı $2^{20}$ bayt = 1 MB, G/Ç uzayı $2^{16}$ bayt = 64 KB'dir.
- Durdurma ve bekletme komutları (ekrandan, 01:40:00)
  - `HLT`: işlemci durur, bir kesme gelince kaldığı komuttan devam eder. `NOP`: işlem yapmaz, 1 bayttır, kodu 90H'dir. `WAIT`: yardımcı işlemcinin (8087) sonucunu beklemek için kullanılır.
- BCD düzenleme komutları (ekrandan, 01:45:00 ve 01:50:00)
  - `AAA`, `AAS`, `AAM`, `AAD` ASCII/unpacked BCD; `DAA`, `DAS` packed BCD düzeltmesi yapar.
- Veri adresleme modları (ekrandan, 02:15:00 – 02:25:00)
  - Yazmaç (`MOV AL, BL`), anlık (`MOV AL, 0F2H`), doğrudan (`MOV BX, [1234H]`, `MOV AL, DATA`), yazmaç dolaylı (`[BX]`, `[SI]`, `[DI]`, `[BP]`), taban + indis (`[BX+SI]`), yazmaç göreli (`[BX+100H]`), taban göreli + indis (`MOV AX, [BX+SI+100H]`).
- Program hafızası adresleme (ekrandan, 02:30:00)
  - Doğrudan (mutlak) dallanma, göreli dallanma (IP'ye göre işaretli uzaklık), dolaylı dallanma (hedef yazmaçta ya da yazmacın gösterdiği bellekte).
- Yığın adresleme (ekrandan, 02:35:00)
  - SS:SP ikilisi kullanılır. PUSH/POP word çalışır; `PUSH BL` geçersizdir. Yığın LIFO'dur; geçici veri ve dönüş adresi saklamak için kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- REP ile LOOP arasındaki fark
  - REP bir etikete dallanmaz, peşindeki tek dizi komutunu tekrarlar. SI/DI'yı dizi komutu günceller, REP yalnız CX'i azaltıp koşulu kontrol eder.
- REP ve LOOP komutları bayrakları etkilemez
  - Komut kümesi tablosunda LOOP ve REP için hiçbir bayrağın değişmediği gösterildi. `REPZ CMPSB` döngüsünde ZF'yi değiştiren CMPSB'dir.
- Döngüden hangi koşulla çıkıldığını ayırt etmek
  - `REPZ`/`REPNZ` döngüsü ya CX = 0 olduğu için ya da ZF koşulu bozulduğu için biter. Hemen ardından `JNZ`/`JZ` ile hangisi olduğu kontrol edilmelidir.
- DF'yi ayarlamadan dizi komutu kullanılmaz
  - SI/DI başı gösteriyorsa `CLD`, sonu gösteriyorsa `STD` kullanılmalıdır.
- `IN AL, DX` ve `OUT DX, AL`'de tip uyumsuzluğu yoktur
  - Bu bir MOV değildir. DX yalnız 16 bitlik port adresini verir; o porttaki göz 8 bitliktir. Hoca bunun "tam sınavda sorulacak" türde bir soru olduğunu söyledi.
- Köşeli parantez içinde kullanılabilen yazmaçlar
  - Yalnız BX, BP, SI, DI. AX, CX, DX, segment yazmaçları ve 8 bitlik yazmaçlar (BL, BH vb.) kullanılamaz. BP varsa varsayılan kesim SS, diğerlerinde DS'dir.
  - Hoca adresleme modlarının adını değil, verilen bir adreslemenin geçerli olup olmadığını soracağını söyledi.
- Tip belirsizliğinde PTR
  - Bellek operandının tipi belli değilse (`INC [BX]` gibi) mutlaka `BYTE PTR` ya da `WORD PTR` yazılmalıdır; assembler'ın varsayılanına güvenilmez. Operandlardan biri yazmaçsa gerek yoktur.
- SP her zaman yığının en üstünü gösterir
  - PUSH'ta SP önce 2 azalır, sonra word yazılır; POP'ta word okunur, sonra SP 2 artar. Yığın doldukça adres küçülür.

## Kısa Tekrar Notları

- `REP`: CX ≠ 0; `REPZ/REPE`: CX ≠ 0 ve ZF = 1; `REPNZ/REPNE`: CX ≠ 0 ve ZF = 0.
- Kaynak DS:[SI], hedef ES:[DI]. LODS yalnız SI'yı, STOS ve SCAS yalnız DI'yı kullanır.
- DF = 0 ileri (artış), DF = 1 geri (azalış); byte'ta 1, word'de 2 adım.
- CX'e eleman sayısı yüklenir.
- CMPS ve SCAS çıkarma yapar ama sonucu saklamaz, yalnız bayrakları değiştirir.
- `REP` ile `LODS` kullanmak anlamsızdır; `REP STOS` bir diziyi tek değerle doldurmak için uygundur.
- Dizi komutları öneksiz de tek başına kullanılabilir (tek eleman için bir kez çalışır).
- `CBW`: AL → AX, `CWD`: AX → DX:AX, işaret korunur.
- 8 bitlik port adresi sabitle, daha büyüğü DX ile verilir; veri AL ya da AX'tedir.
- Bellek uzayı 1 MB (20 adres ucu), G/Ç uzayı 64 KB (16 bit).
- NOP = 90H.
- Köşeli parantezde yalnız BX, BP, SI, DI; en karmaşık biçim taban + indis + sabit.
- `PUSH BL` geçersiz; yığın SS:SP ile adreslenir.

## Detaylı Açıklamalar

- **Kopyalama örneği (ekrandan, 00:30:00 ve 00:35:00).** Veri kesiminde `dizi1 DB 'abcdefgh....'` (20 karakter), `dizi2 DB 20 DUP(?)` ve `n DW 20` tanımlanır. `20 DUP(?)` 20 baytlık yeri ilk değer vermeden ayırır. Kod şöyledir:

  ```asm
  LEA SI, dizi1   ; [SI]: 'a'
  LEA DI, dizi2   ; [DI]: dizi2'nin başı
  CLD             ; DF <- 0
  MOV CX, n
  REP MOVSB       ; dizi2 <- dizi1
  ```

  `MOVSB` tek başına bir bayt kopyalar ve SI ile DI'yı 1 artırır. `REP` bunu CX sıfır olana kadar tekrarlar. Tek karakter `var DB 'e'` biçiminde, karakter dizisi `dizi DB 'Merhaba', '$'` biçiminde (sonlandırma karakteriyle) tanımlanabilir (ekrandan, 00:35:00).

- **İlk farklı elemanı bulma (ekrandan, 00:40:00 ve 00:45:00).** `dizi1 DB 'abcdefgh....'`, `dizi2 DB 'abcdefGh....'`, `n DW 20` verilir; amaç karşılıklı elemanlarda ilk farklı değeri ve indisini bulmaktır.

  ```asm
  LEA SI, dizi1
  LEA DI, dizi2
  CLD
  MOV CX, n
  REPZ CMPSB      ; CX != 0 ve Z = 1 iken devam
  JNZ farkli      ; ZF = 0 ise fark bulundu
  JMP ayni        ; buraya CX = 0 ile gelindi
  farkli: ...
  ayni:   ...
  ```

  Eşit karakterlerde CMPSB ZF'yi 1 yapar ve döngü sürer; `g` ile `G` karşılaştırılınca ZF = 0 olur ve döngü kırılır. Altyazıda hoca dalı `JMP`, etiketleri `farkli`, `ayni` diye adlandırdı; etiket yazımı kareden doğrulanamadı. <!-- BELİRSİZ: JNZ sonrası etiket ve atlama satırlarının tahtadaki tam yazımı karelerde görünmüyor (altyazı 00:46:19–00:48:10) -->

  - Ders sonrası not: Hoca farklı elemanların `[SI]` ve `[DI]` ile okunabileceğini söyledi. CMPSB karşılaştırmadan sonra da SI ve DI'yı artırdığı için döngü bittiğinde ikisi farklı elemanın bir sonrasını gösterir; farklı elemanlar `[SI-1]` ve `[DI-1]`'dedir. Python ile kontrol: 20 elemanlı örnekte döngü SI = 7, CX = 13 ile biter, farklı elemanın indisi 6'dır ($n - CX - 1 = 20 - 13 - 1 = 6$).

- **Word dizisinde değer arama (ekrandan, 00:50:00 ve 00:55:00).** Bir word dizisinde 8 değerinin olup olmadığı ve indisi aranır (`n DW 10`).

  ```asm
  LEA DI, dizi
  MOV CX, n
  MOV AX, 8
  CLD
  REPNZ SCASW     ; eşitlik yokken (Z = 0) devam
  JZ buldum       ; Z = 1 ise bulundu, değilse CX = 0
  ```

  SCASW her adımda AX − ES:[DI] karşılaştırmasını yapar ve DI'yı 2 artırır (DF = 1 olsaydı 2 azaltırdı). Döngü Z = 1 (bulundu) ya da CX = 0 (yok) ile biter. <!-- BELİRSİZ: dizinin elemanları altyazıda "1, 2, 3, 4, 4, ... 6, 8, 1, 7" diye okunuyor, tahtada görünmüyor; on eleman tam çıkarılamadı -->

  - Ders sonrası not: Hoca bulunan elemanın DI indisinde olduğunu söyledi. SCASW de karşılaştırmadan sonra DI'yı 2 artırdığı için bulunan word büyük olasılıkla `[DI-2]` adresindedir.

- **STOS ile dizi doldurma (ekrandan, 01:00:00).** `dizi1 DB 25 DUP(?)`, `n DW 25` için sıfırlama: `LEA DI, dizi1` / `MOV CX, n` / `CLD` / `XOR AL, AL` / `REP STOSB`. Burada REP anlamlıdır, çünkü her adımda aynı AL değeri yazılır. Diziyi 1'den 25'e kadar doldurmak için AL'nin her adımda değişmesi gerekir; REP döngüsünün içinde AL değiştirilemediği için LOOP kullanılır. Bir öğrencinin önerisiyle son biçim: `XOR AL, AL` / `L1: INC AL` / `STOSB` / `LOOP L1`. Python ile kontrol: dizi 1, 2, ..., 25 olur.

- **CBW ve CWD.** `MOV AL, 00111010B` + `CBW` → AX = 003AH (işaret biti 0, AH sıfırlarla dolar). AL = 11111111B (−1) için `CBW` → AX = FFFFH (16 bitlik −1). `MOV AX, 0777H` + `CWD` → DX = 0000H, AX = 0777H. `MOV AX, 8000H` + `CWD` → DX = FFFFH, AX = 8000H. Bu hazırlık özellikle işaretli bölmeden önce gerekir. Hepsi python ile doğrulandı.
  - Ders sonrası not: Hoca 8000H için "yazabileceğimiz en büyük negatif sayı" dedi; 8000H = −32768, 16 bitte mutlak değeri en büyük (yani en küçük) negatif sayıdır.

- **BCD örnekleri (ekrandan, 01:45:00 ve 01:50:00).** Python ile doğrulandı:
  - AAA: `'6'` (36H) + `'7'` (37H) = 6DH; AAA sonrası AH = 01, AL = 03 (unpacked BCD 13). AH başlangıçta 0 kabul edildi (ara adım eklendi).
  - AAD: AX = 0405H → AAD → AX = 002DH (= 45).
  - AAM: `MOV AL, 4`, `MOV AH, 8`, `MUL AH` → AX = 0020H; AAM → AX = 0302H (BCD 32).
  - AAS: 35H − 37H = FEH (−2); AAS → AL = 08H, CF = AF = 1 (5 − 7 için bir elde alınır, 15 − 7 = 8).
  - DAA: 75H + 19H = 8EH; düşük basamak 9'dan büyük olduğu için 6 eklenir → 94H (75 + 19 = 94).
  - DAS: 42H − 13H = 2FH; 6 çıkarılır → 29H (42 − 13 = 29).
  - Ders sonrası not: AAM slaytındaki "ASCII değer olarak tutulan iki sayının toplamını BCD olarak düzenler" cümlesi büyük olasılıkla AAA slaytından kalmıştır; AAM çarpma sonucunu düzenler.

- **Adresleme modlarında assembler denemesi (02:20:57–02:24:23).** Hoca derleyici/emülatörde `[BP+SI]` biçiminin derlendiğini, `var DB 1` tanımından sonra `MOV AL, var` komutunun doğrudan adreslemeye çevrildiğini ve `[BX+100+SI]` yazımının `[BX+SI+64h]` biçimine çevrildiğini gösterdi (100 onluk = 64H). Yani toplamdaki terimlerin sırası önemli değildir.

- **Göreli dallanma (ekrandan, 02:30:00).** Slaytta `JMP 0FFH ; IP değeri 1 azalır (NEDEN?)` sorusu vardı: FFH işaretli 8 bitlik sayı olarak −1'dir. Derste denemede assembler ve DEBUG `0FFH`'yi mutlak hedef adres olarak yorumladı ve IP FF'ye gitti; hoca bu konudaki hatayı sonra düzelteceğini söyledi.
  - Ders sonrası not: Assembly'de `JMP` operandı hedef adres ya da etikettir; göreli uzaklığı assembler hesaplar. "IP 1 azalır" yorumu büyük olasılıkla makine kodundaki uzaklık baytının FFH olduğu durum (`EB FF`) içindir: hedef, bir sonraki komutun adresinin 1 eksiğidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
