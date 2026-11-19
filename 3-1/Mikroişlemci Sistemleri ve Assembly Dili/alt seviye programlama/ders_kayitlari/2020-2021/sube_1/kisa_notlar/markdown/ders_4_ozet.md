# Ders 4 Çalışma Özeti

## Genel Konular

- Yığın komutları: PUSH, POP, PUSHF, POPF
  - PUSH yığına bir word (16 bit) atar, POP yığından bir word çeker. PUSHF bayrak yazmacını yığına atar, POPF yığının en üstündeki word'ü bayrak yazmacına yazar.
  - Varsayılan segment SS'dir; çekilen veri SS:[SP] adresindedir (ekrandan, 00:05:00). SP başta yığının en büyük adresini gösterir, PUSH ile ikişer azalır, POP ile ikişer artar. COM programlarında başlangıç değeri FFFEH'tır.
  - POP ve PUSH'ta bellek işleneni için BYTE PTR / WORD PTR yazmaya gerek yoktur, işlem zaten word'dür.
  - PUSH'a sabit, 16 bitlik yazmaç, bellek ya da segment yazmacı verilebilir. Hoca POP'un segment yazmacına yazamadığını söyledi (bkz. Detaylı Açıklamalar'daki ders sonrası not).
- Döngü komutları: LOOP, LOOPZ/LOOPE, LOOPNZ/LOOPNE, JCXZ (ekrandan, 00:10:00)
  - Hepsi CX ile çalışır, bu yüzden döngüden önce CX'e değer atanmalıdır.
  - LOOP: CX'i bir azaltır, CX ≠ 0 ise etikete gider. Eşdeğeri `DEC CX` + `JNZ L1`.
  - LOOPZ/LOOPE: CX'i azaltır, CX ≠ 0 ve ZF = 1 ise döngüye devam eder. İki iç içe if gibidir.
  - LOOPNZ/LOOPNE: CX'i azaltır, CX ≠ 0 ve ZF = 0 ise devam eder (ekrandan, 00:25:00).
  - JCXZ: CX = 0 ise dallanır, CX'i kendisi azaltmaz. CX'in nasıl değişeceğine programcı karar verir (ör. `SUB CX, 2`). Döngüyü kıran komut gibi düşünülür.
  - Etiket tanımlanırken iki nokta üst üste konur. Assembler etiketi 8 bitlik görece uzaklığa (displacement, -128..+127) kendisi çevirir.
- Döngü şekillerinin assembly karşılıkları
  - For to, for downto, while, repeat until ve iç içe for akış şemaları kodlandı (ekrandan, 00:30:00 - 01:15:00).
  - İç içe döngülerde iki döngü de CX kullandığı için dış döngünün CX'i iç döngüye girerken `PUSH CX` ile saklanır, çıkarken `POP CX` ile geri alınır.
- Bayraklarla ilgili komutlar (ekrandan, 01:20:00)
  - CLC, CMC, STC (carry); CLD, STD (direction); CLI, STI (interrupt).
  - Özel komutu olmayan SF, ZF, AF, PF için LAHF ve SAHF kullanılır: AH ← SF, ZF, ?, AF, ?, PF, ?, CF.
  - IF bayrağı INTR ucundan gelen kesme isteklerini açıp kapatır. Veri aktarımında üç yol: polling, interrupt, DMA.
- Mantıksal komutlar: NOT, OR, AND, XOR, TEST
  - NOT bire tümleyen, NEG ikiye tümleyen üretir.
  - TEST, CMP gibi sonucu saklamaz ama çıkarma yerine AND yapar; tek bir bitin durumunu sınamak için kullanılır.
  - Bellek ile sabit kullanılan her mantıksal komutta PTR gerekir.
- Öteleme ve döndürme komutları
  - SHL (= SAL), SHR, SAR; RCL, RCR, ROL, ROR.
  - Öteleme miktarı 1 ise doğrudan yazılır, 1'den fazlaysa yalnız CL ile verilir.
  - SAR işaret bitini korur ve tekrarlar; işaretli ikiye bölmedir.
  - RCL/RCR carry'yi de içine alarak (8 bitlik işlende sanki 9 bitlik bir yazmaç gibi) döndürür; ROL/ROR işlenenin kendi bitleri içinde döndürür, dışarı çıkan biti CF'ye de kopyalar.
- Dizi (string) komutları
  - MOVSB/W, CMPSB/W, SCASB/W, LODSB/W, STOSB/W, CBW, CWD ve REP, REPE/REPZ, REPNE/REPNZ önekleri (ekrandan, 02:15:00).
  - Dizi komutları dolaylı döngüdür: tekrar sayısı CX'te tutulur.
  - Hazırlık: CX'e eleman sayısı, DF'ye yön, DS:SI'ya kaynak, ES:DI'ya hedef başlangıç adresi.
  - CBW ve CWD işaret genişletmesi yapar (AX ← AL, DX:AX ← AX).

## Hocanın Özellikle Vurguladığı Kısımlar

- LOOP yalnız döngü sayısı belli işler için kullanılmalı
  - LOOP, C'deki for'a karşılık gelir. CX'i döngü ortasında sıfırlayarak döngüyü kırmak teknik olarak çalışır ama kodu okunmaz yapar. Koşula bağlı döngüler için CMP + koşullu dallanma ya da JCXZ kullanılmalı.
- İç içe döngüde PUSH CX / POP CX bir parantez gibidir
  - Yığına ne kadar atılırsa o kadar çekilmelidir; yoksa yığından yanlış değer çekilir. Üç iç içe döngüde de her iç döngüden önce bir üst döngünün CX'i saklanır.
- Döngü hatalarının çoğu etiketten gelir
  - Etiket tanımında iki nokta üst üste unutulur ya da geri dönüş etiketi yanlış satıra konur. While döngüsünde geri dönüş, toplamanın değil karşılaştırmanın olduğu satıra yapılmalıdır; yoksa sonsuz döngü oluşur. Etiketlere anlamlı ad verilmeli (ör. `CIKIS`).
- SI ve DI'yı döngü indisi olarak kullanma alışkanlığı
  - Döngü içinde ileride bellek erişimi (`[SI]`) gerekirse dolaylı adreslemede kullanılabilen yazmaçlar SI ve DI olduğundan hata önlenir.
- Bellek işleneninde PTR her zaman açıkça yazılmalı
  - Bir emülatör varsayılan boyut kabul etse bile derslerde ve sınavlarda BYTE PTR / WORD PTR açıkça yazılmalıdır.
- Öteleme miktarı birden fazlaysa yalnız CL
  - `SHL AX, 4` diye bir komut yoktur; `MOV CL, 4` ve `SHL AX, CL` yazılır. CL yerine DL ya da CX kullanılamaz.
  - `SHL AX, CL` gibi 16 bitlik yazmaçla 8 bitlik CL'nin yan yana olması hatalı değildir. Hoca "kodda hata bulun" sorularında bunun sık sık yanlışlıkla hatalı işaretlendiğini söyledi.
- XOR AX, AX tercih edilir
  - MOV AX, 0 ile aynı işi yapar ama daha kısa ve daha hızlıdır (ekrandan, 01:45:00; hoca slayttaki değerlerin yer değiştirdiğini söyleyip düzeltti).
- CMP ile TEST farkı
  - CMP sabit bir değerle karşılaştırma içindir; TEST tek bir bitin 1 mi 0 mı olduğunu anlamak içindir.

## Kısa Tekrar Notları

- PUSH/POP word ile çalışır, SS:SP kullanır; SP PUSH'ta 2 azalır, POP'ta 2 artar.
- `POP CS` yoktur.
- LOOP = `DEC CX` + `JNZ`; LOOPZ: CX ≠ 0 ve ZF = 1; LOOPNZ: CX ≠ 0 ve ZF = 0; JCXZ: CX = 0 ise dallan, CX'i azaltmaz.
- 1'den 10'a toplamada SI yerine doğrudan CX toplanabilir (`ADD AX, CX`); sonuç aynıdır, toplama sırası tersine döner.
- While: koşulun yanlış kolunu yaz (`CMP SI, 10` + `JA CIKIS`), geri dönüşü CMP satırına yap.
- Repeat until: gövde en az bir kez çalışır, koşul sonda sınanır.
- İç içe döngü: `PUSH CX` ... iç döngü ... `POP CX`.
- LAHF/SAHF bit sırası: 7 SF, 6 ZF, 4 AF, 2 PF, 0 CF (5, 3, 1 boş).
- SF'nin tümleyeni: `LAHF`, `XOR AH, 80H`, `SAHF`. SF'yi sıfırla: `AND AH, 7FH`. PF'yi 1 yap: `OR AH, 04H`.
- x ⊕ 0 = x, x ⊕ 1 = x', x ⊕ x = 0, x · 0 = 0, x + 1 = 1.
- `XOR AL, 0FFH` ≡ `NOT AL`.
- TEST = AND, sonuç saklanmaz; 6. bit için `TEST AL, 40H` + `JZ`.
- Bir yazmaçtaki 1'leri sayma (population count): her adımda bir bit öteleyip carry'yi `JC` ya da `ADC BX, 0` ile say.
- SHL = 2 ile çarp, SHR = işaretsiz 2'ye böl, SAR = işaretli 2'ye böl.
- Dizi komutu öncesi: CX, DF, DS:SI, ES:DI.
- CLD → adresler artar (DF = 0), STD → azalır (DF = 1). Byte komutunda SI/DI 1, word komutunda 2 değişir.
- `REP STOSB` (AL = 0) diziyi sıfırlar; `REP MOVSB` dizi1'i dizi2'ye kopyalar.
- REP ≈ LOOP, REPE/REPZ ≈ LOOPZ, REPNE/REPNZ ≈ LOOPNZ. Önekler ayrı bir komut değildir.
- CBW: AL = 80H → AX = FF80H. CWD: DX:AX ← AX (işaretli). IDIV öncesi işaret genişletmede kullanılır.

## Detaylı Açıklamalar

- Yığın komutları
  - Yığına yalnız en üstten veri konur ve yalnız en üstten veri alınır. 8086'da yığın aşağı doğru büyür: SP başta yığının en büyük adresini gösterir, her PUSH'ta 2 azalır. Yığın boşaldığında SP ilk değerine (EXE programında yığın segmentinin boyutu, COM programında FFFEH) döner.
  - POP'un hedefi 16 bitlik yazmaç ya da bellektir (`POP regw`, `POP mem`; ekrandan, 00:05:00). PUSH'un kaynağı sabit, 16 bitlik yazmaç, bellek ya da segment yazmacı olabilir.
  - Ders sonrası not: Hoca POP ile segment yazmacına yazılamadığını, CS'ye değer vermek için önce `POP AX` sonra `MOV CS, AX` yazılması gerektiğini söyledi. Doğrusu: 8086'da `POP DS`, `POP ES`, `POP SS` geçerlidir; geçersiz olan yalnız `POP CS`'tir. CS MOV ile de hedef olarak yazılamaz; CS yalnız uzak JMP/CALL ve RET/IRET ile değişir.
  - emu8086'da ya da DOSBox'taki debug aracında PUSH/POP, bir EXE ya da COM programı olmadan da tek başına çalıştırılabilir. Ama program içinde yığına atılan kadar veri çekilmelidir.
- LOOP izleme tablosu (ekrandan, 00:15:00)
  - `MOV toplam, 0`, `MOV CX, 5`, `MOV SI, 1`, ardından `L1: ADD toplam, SI`, `INC SI`, `LOOP L1`. Her geçişte toplam SI kadar artar, SI bir artar, LOOP CX'i bir azaltır. Döngü beş kez döner ve toplam 1 + 2 + 3 + 4 + 5 = 15 olur.
  - Ders sonrası not: Hoca "CX 0 iken LOOP satırına gelinirse döngü kırılır" dedi. Doğrusu: LOOP önce CX'i azaltır, sonra CX'e bakar. Döngü, azaltma sonunda CX 0 olunca kırılır. Döngüye CX = 0 ile girilirse CX FFFFH olur ve döngü 65536 kez döner.
- LOOPZ ve LOOPNZ'nin açılımı
  - LOOPZ'den önce bayrakları etkileyen bir komut (CMP, TEST vb.) çalışır. LOOPZ şu iki ifin iç içe hâlidir: sonuç sıfır değilse çık; sıfırsa CX'i azalt, CX sıfır değilse başa dön. LOOPNZ'de ilk koşul terstir (ekrandan, 00:25:00: `CMP`, `JZ CIKIS`, `DEC CX`, `JNZ L1`).
- Döngü şekilleri
  - For to (AX = 1 + ... + 10): `XOR AX, AX`, `MOV SI, 1`, `MOV CX, 10`, `L1: ADD AX, SI`, `INC SI`, `LOOP L1`, `MOV BX, 1`. SI gereksizse `ADD AX, CX` ile 10'dan 1'e doğru toplanır; sonuç (55) aynıdır. Gövdede `[SI]` gibi bellek erişimi varsa SI'lı biçim gerekir.
  - For downto (I = 10'dan 0'a ikişer): `MOV AX, 0`, `MOV CX, 10`, `L1: ADD AX, CX`, `SUB CX, 2`, `JCXZ L2`, `JMP L1`, `L2: MOV BX, 1`. 10 çift olduğundan CX mutlaka 0'a varır; AX = 30 olur. Başlangıç dışarıdan geliyorsa ve CX 0'ı atlayabiliyorsa işaretli karşılaştırma gerekir (`CMP CX, 0` + işaretli koşullu dallanma). <!-- BELİRSİZ: Hoca bu durumda "JLE L1 ile döngüye devam" dedi; doğrusu CX ≤ 0 iken çıkmak (JLE çıkış ya da JG L1). O anın karesi yok. -->
  - While (I = 1, I ≤ 10, I += 2): `XOR AX, AX`, `MOV SI, 1`, `L2: CMP SI, 10`, `JA L1`, `ADD AX, SI`, `ADD SI, 2`, `JMP L2`, `L1: MOV BX, 1` (ekrandan, 00:50:00). AX = 1 + 3 + 5 + 7 + 9 = 25.
  - Repeat until (I = 2, I += 2, I > 10 ise çık): `XOR AX, AX`, `MOV SI, 2`, `L1: ADD AX, SI`, `ADD SI, 2`, `CMP SI, 10`, `JBE L1`, `MOV BX, 1` (ekrandan, 01:10:00). AX = 2 + 4 + 6 + 8 + 10 = 30.
  - İç içe for (I = 0..3, J = 2..4, AX = AX + I + J): dış döngüde `MOV CX, 4`, iç döngüde `MOV DI, 2` ve `MOV CX, 3`; iç döngü `PUSH CX` ile `POP CX` arasına alınır (ekrandan, 01:15:00). AX = 54 olur.
- Bayrak komutları
  - CMC carry'nin tümleyenini alır: $C \oplus 1 = C \cdot \bar{1} + \bar{C} \cdot 1 = \bar{C}$ (ekrandan, 01:30:00). Carry, öteleme/döndürme sonuçlarını sınamak ya da algoritmada carry'de değer üretmek için önemlidir.
  - DF dizi işlemlerinde adres yönünü belirler: DF = 0'da her adımda adres artar, DF = 1'de azalır.
  - IF = 1 ise INTR ucundan gelen kesme istekleri işlenir, IF = 0 ise dikkate alınmaz. Polling'de işlemci "veri hazır mı" diye döngüde aktif bekler. Interrupt'ta çevre birimi hazır olunca kesme üretir, işlemci o arada başka işle uğraşır. DMA'da veri işlemciden geçmez; DMA denetleyicisi kaynak ve hedef arasında aktarımı yapar.
  - LAHF ile bayraklar AH'ye alınır, AH'de bit işlemi yapılır, SAHF ile geri yazılır. 1 ile XOR biti tersler, 0 ile AND biti sıfırlar, 1 ile OR biti 1 yapar; diğer bitler için 0 ile XOR/OR ve 1 ile AND biti korur.
- Mantıksal komutlar
  - AL = 1100 0110 iken `OR AL, 88H` → 1100 1110; aynı AL ile `AND AL, 88H` → 1000 0000 (ekrandan, 01:40:00).
  - x ⊕ x = $x\bar{x} + \bar{x}x = 0$; bu yüzden `XOR AX, AX` AX'i sıfırlar. Hoca slayttaki değerlerin yer değiştirdiğini söyledi; doğrusu `XOR AX, AX` 3 clock cycle, 2 byte; `MOV AX, 0` 4 clock cycle, 3 byte (ekrandan, 01:45:00).
  - NOT/NEG örneği: AL = 1001 1100 için `NOT AL` → 0110 0011, `NEG AL` → 0110 0100.
  - Ders sonrası not: Hoca bu sayıyı -68, NEG sonucunu 68 olarak okudu. Doğrusu: 1001 1100 = 9CH işaretli olarak -100'dür; NEG sonucu 64H = +100'dür (python ile doğrulandı).
  - TEST ile kapı örneği: AL'nin i. biti i. kapının açık (1) ya da kapalı (0) olduğunu gösterir. 6. kapı için `TEST AL, 40H`, `JZ KAPALI_6` yazılır (ekrandan, 01:50:00). CMP ile olmaz, çünkü diğer 7 bit "don't care" olduğundan 128 farklı değerle karşılaştırmak gerekir.
  - Population count: AL her adımda bir bit ötelenir, çıkan bit carry'ye düşer; `JC` ile sayaç artırılır ya da `ADC BX, 0` ile carry doğrudan toplanır (ekrandan, 01:55:00). 8 adımlık döngüde bütün bitler sayılır. Güncel işlemcilerde bunu tek komutla yapan özel komutlar vardır.
- Öteleme ve döndürme
  - SHL'de her bit bir üst bite kayar, en yüksek bit CF'ye gider, en düşük bite 0 girer; SAL = SHL (ekrandan, 02:00:00). SHR'de en düşük bit CF'ye gider, en yüksek bite 0 girer.
  - Miktar CL'de verilir, CX'te değil: 16 bitlik bir yazmacı 16'dan fazla ötelemenin anlamı yoktur, 8 bit yeter. MOV'da 8 ve 16 bitlik yazmaç birlikte kullanılamaz ama öteleme/döndürmede bu özel bir durumdur.
  - SAR işaret bitini (MSB) korur ve tekrarlar (ekrandan, 02:05:00): -128 bir kez SAR ile -64 olur. `MOV AL, 80H`, `MOV CL, 4`, `SAR AL, CL` sonrası AL = 1111 1000.
  - Ders sonrası not: Hoca dört ötelemeden sonra sonucun -16 olduğunu söyledi. Doğrusu: -128 → -64 → -32 → -16 → -8; dört SAR sonrası AL = F8H = -8'dir (python ile doğrulandı).
  - RCL/RCR'de MSB (ya da LSB) CF'ye, CF'deki eski değer diğer uca geçer. ROL/ROR'da çıkan bit diğer uca döner, CF yalnız kopya tutar. Hoca ROL/ROR'u 8 bitlik alan üzerinden anlattı; işlen word ise döndürme 16 bit üzerinde yapılır.
- Dizi komutları
  - Assembler dizinin byte mı word mü olduğuna bakmaz; adres adrestir, yorum programcıdadır.
  - MOVS: DS:SI'daki veri ES:DI'ya kopyalanır, kaynak bozulmaz. CMPS: DS:SI ile ES:DI karşılaştırılır (çıkarma, sonuç saklanmaz, yalnız bayraklar). SCAS: AL/AX ile ES:DI karşılaştırılır, bir değeri dizide aramak için. LODS: DS:SI'daki eleman AL/AX'e yüklenir. STOS: AL/AX ES:DI'ya yazılır, diziye aynı ilk değeri vermek için.
  - `LEA DI, dizi`, `CLD`, `XOR AL, AL`, `MOV CX, size`, `REP STOSB` diziyi sıfırlar (ekrandan, 02:40:00). LEA değişkenin data segmentteki offset'ini, yani başlangıç adresini verir.
  - `LEA SI, dizi1`, `LEA DI, dizi2`, `CLD`, `MOV CX, size`, `REP MOVSB` dizi1'i dizi2'ye kopyalar (ekrandan, 02:45:00). EXE ve COM programları ES = DS ile başlar; başka bir segmentle çalışılacaksa ES değiştirilmelidir.
  - REPE CMPS ilk farklı elemanda durur, REPNE CMPS ilk aynı elemanda durur. LOOP komutlarının her birine bir makine komutu karşılık gelir; öneklere ise ayrı bir komut üretilmez.
  - CBW: AL = 1000 0000 (-128) → AX = 1111 1111 1000 0000, 16 bitlik -128. CWD: AX = -128 → DX = FFFFH, DX:AX 32 bitlik -128 (ekrandan, 02:35:00). `IDIV BX` DX:AX'i BX'e böldüğü için 16 bitlik işaretli bir sayıyı bölmeden önce CWD ile genişletmek gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
