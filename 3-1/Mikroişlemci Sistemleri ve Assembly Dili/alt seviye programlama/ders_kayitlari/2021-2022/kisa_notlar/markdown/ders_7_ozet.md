# Ders 7 Çalışma Özeti

## Genel Konular

- Döngü komutları: `LOOP`, `LOOPZ`/`LOOPE`, `LOOPNZ`/`LOOPNE`, `JCXZ` (ekrandan, 00:05:00-00:20:00)
  - Dördünde de döngü değişkeni CX'tir (count register). Döngüye girmeden önce `MOV CX, ...` ile CX'e ilk değer verilir. CL ya da CH değil, 16 bitlik CX kullanılır.
  - `LOOP etiket`: Önce CX bir azaltılır, sonra CX sıfır mı diye bakılır. CX ≠ 0 ise etikete dallanılır, CX = 0 ise döngüden çıkılır. Bu yüzden döngü CX = 0 değeri için hiç çalışmaz.
  - `LOOPZ etiket` (`LOOPE`): CX ≠ 0 ve ZF = 1 olduğu sürece tekrarlanır. CX == 0 ya da ZF = 0 olunca döngü kırılır.
  - `LOOPNZ etiket` (`LOOPNE`): CX ≠ 0 ve ZF = 0 olduğu sürece tekrarlanır. CX == 0 ya da ZF = 1 olunca döngü kırılır.
  - `LOOP`, `LOOPZ` ve `LOOPNZ` komutları CX'i kendileri azaltır. `JCXZ etiket` ise yalnız "CX = 0 ise dallan" der; CX'in değiştirilmesi kullanıcıya aittir.
  - Döngü komutlarının işleneni bir yer değiştirmedir (displacement): bulunulan satıra göre ileri ya da geri, 8 ya da 16 bitlik işaretli uzaklık.
  - `LOOPZ`/`LOOPNZ`'de döngüyü kıran ZF, döngü içinde ZF'yi en son değiştiren komuttan gelir. Aritmetik komutlar ZF'yi değiştirir, veri aktarım komutları değiştirmez.
- `JCXZ` ile döngü yapısı (ekrandan, 00:15:00)
  - `MOV CX, ...` / `etiket1:` / ... (CX değiştirilir) ... / `JCXZ etiket2` / `JMP etiket1` / `etiket2:`.
  - Görünüşte sonsuz döngüdür; tek çıkış koşulu CX == 0'dır. Döngü içinde CX `INC`, `DEC`, `ADD`, `SUB` gibi komutlarla, hatta bir koşula bağlı olarak (tekse 1, çiftse 2 ekle gibi) değiştirilebilir. CX hiç değiştirilmezse döngü sonsuza kadar döner.
- Döngü komutlarının kullanım örnekleri
  - 1'den 5'e kadar sayıların toplamı: toplam değişkeni 0, CX = 5, SI = 1; döngüde toplama SI eklenir, SI bir artırılır, `LOOP`. Sonunda toplam 15, SI 6, CX 0 olur. CX zaten 5'ten 1'e indiği için toplam doğrudan CX üzerinden de alınabilir; o zaman SI ve `INC SI` gerekmez.
  - `LOOPZ` örneği: iki dizinin karşılıklı elemanları karşılaştırılırken ilk farklı elemanın yerini bulmak. CX = 0 ile çıkılırsa fark yoktur; ZF = 0 ile çıkılırsa fark bulunmuştur ve indis CX'ten hesaplanır.
  - `LOOPNZ` örneği: aynı karşılaştırmada ilk eşit elemanı bulmak. ZF = 1 ile çıkılırsa eşit eleman bulunmuştur, CX = 0 ile çıkılırsa yoktur.
- Yüksek seviye döngülerin assembly karşılıkları ("Döngü Şekilleri" slaytları)
  - FOR TO (I = 1..10, AX = AX + I) (ekrandan, 00:25:00): `XOR AX, AX` / `MOV SI, 1` / `MOV CX, 10` / `tekrar: ADD AX, SI` / `INC SI` / `LOOP tekrar`; döngü sonrası `MOV BX, 1`. Sonuç AX = 55.
  - Aynı işlem CX üzerinden: `ADD AX, CX` ile 10'dan 1'e toplanır; sonuç yine 55'tir, SI gerekmez.
  - FOR DOWN TO, ikişer azalan (I = 10'dan 0'a, adım 2) (ekrandan, 00:30:00): `XOR AX, AX` / `MOV CX, 10` / `tekrar: ADD AX, CX` / `SUB CX, 2` / `JCXZ devam` / `JMP tekrar` / `devam:`. Adım 1 olmadığı için `LOOP` yerine `JCXZ` kullanıldı. Sonuç AX = 10+8+6+4+2 = 30.
  - WHILE (I = 1'den başlar, I ≤ 10 iken AX = AX + I, I ikişer artar): Koşul başta kontrol edilir; `CMP SI, 10` / `JA` ile boş (false) kol için dallanılır, döngü sonunda `JMP` ile başa dönülür. Döngüye hiç girilmeyebilir. <!-- BELİRSİZ: WHILE slaytının karesi okunmadı; satırlar altyazıdan kuruldu, I'nın artış miktarı (2) altyazıdan. -->
  - REPEAT UNTIL (I = 2'den başlar, ikişer artar, I > 10 olunca çıkar) (ekrandan, 00:35:00): `XOR AX, AX` / `MOV SI, 2` / `tekrar: ADD AX, SI` / `ADD SI, 2` / `CMP SI, 10` / `JBE tekrar` / `MOV BX, 1`. Gövde en az bir kez çalışır. Sonuç AX = 2+4+6+8+10 = 30.
  - İşaretsiz sayılarda "büyük" için `JA` (jump above), "küçük eşit" için `JBE` (jump below or equal) kullanılır; `JNA` ile `JBE` aynı komuttur.
- İç içe iki FOR (ekrandan, 00:40:00 ve 00:45:00)
  - Dış döngü I = 0..3 (4 kez), iç döngü J = 2..4 (3 kez), gövde AX = AX + I + J. Dış değişken DI, iç değişken SI.
  - İki döngü de CX kullandığı için iç döngüye girmeden önce dış döngünün CX'i saklanmalı, iç döngü bitince geri yüklenmelidir. Yol 1: kullanılmayan bir yazmaca kopyalamak (`MOV DX, CX` ... `MOV CX, DX`). Yol 2: yığın (`PUSH CX` ... `POP CX`).
  - Slayttaki kod: `MOV AX, 0` / `MOV CX, 4` / `MOV DI, 0` / `L2: PUSH CX` / `MOV CX, 3` / `MOV SI, 2` / `L1: ADD AX, DI` / `ADD AX, SI` / `INC SI` / `LOOP L1` / `POP CX` / `INC DI` / `LOOP L2` / `MOV BX, 1`. Sonuç AX = 54.
  - Arada başka `PUSH` varsa her birine karşılık `POP` olmalıdır; yoksa `POP CX` yığının tepesinden yanlış değeri çeker.
- Bayraklarla ilgili komutlar (ekrandan, 01:00:00 ve 01:05:00)
  - 1. grup, doğrudan komutu olan bayraklar (CF, DF, IF): `CLC` (CF←0), `STC` (CF←1), `CMC` (CF←CF'), `CLD` (DF←0), `STD` (DF←1), `STI` (IF←1), `CLI` (IF←0).
  - DF dizi (katar) işlemlerinde yönü belirler: DF = 0 iken adresler baştan sona artar, DF = 1 iken sondan başa azalır.
  - IF donanımsal kesmeleri (mikroişlemcinin INTR ucundan gelen istekleri) açıp kapatır: IF = 1 ise aktarılır, IF = 0 ise engellenir.
  - 2. grup, LAHF/SAHF'a konu olan bayraklar (SF, ZF, AF, PF, CF): `LAHF` bayrak yazmacının bazı bitlerini AH'a kopyalar (bit 7 SF, 6 ZF, 4 AF, 2 PF, 0 CF; 5, 3, 1 kullanılmaz). AH üzerinde maskeyle istenen bitler değiştirilir, `SAHF` ile geri yazılır. Birden çok bayrak aynı anda değiştirilebilir.
  - 3. grup (OF, TF): `PUSHF` ile bayrak yazmacı yığına atılır, yığında ilgili bitler değiştirilir, `POPF` ile geri çekilir.
  - OF işaretli sayılarda taşmayı gösterir. TF = 1 iken her komuttan sonra tek adım (single step) kesmesi oluşur; adım adım hata ayıklama içindir. <!-- BELİRSİZ: altyazıda "bunu bir reset ettiğimiz zaman" geçiyor; 8086'da tek adım kesmesi TF = 1 iken oluşur. -->
- Mantıksal komutlar (hatırlatma)
  - Bir işlenenin b numaralı bitini 0 yapmak: `AND` ve b. biti 0, diğerleri 1 olan maske. 1 yapmak: `OR` ve b. biti 1, diğerleri 0 olan maske. Tümleyenini almak: `XOR` ve b. biti 1, diğerleri 0 olan maske.
  - Dayanak: $x \cdot 0 = 0$, $x + 1 = 1$, $x \oplus 1 = \bar{x}$.
  - `TEST` arka planda `AND`, `CMP` arka planda çıkarmadır; ikisi de sonucu saklamaz, yalnız bayrakları etkiler. Ardından koşullu dallanma gelir.
- Öteleme ve döndürme komutları (ekrandan, 01:20:00 ve 01:25:00)
  - Ötelemede (shift) dışarı çıkan bit CF'ye gider, boşalan yer 0 ile beslenir. Döndürmede (rotate) çıkan bit öbür uçtan geri girer.
  - Shift komutlarının lojik ve aritmetik türleri, rotate komutlarının CF'li ve CF'siz türleri vardır. Lojik öteleme sayının işaretine bakmaz, aritmetik öteleme işareti korur.
  - `SHL`: bitler bir sola kayar, MSB CF'ye gider, D0'a 0 girer. Aritmetik olarak 2 ile çarpmadır. İşaret bitine bakmadığı için `SAL = SHL`. Negatif bir sayı bir öteleme sonrası pozitife dönebilir.
  - Tek öteleme işleneni doğrudan 1 yazılabilir; birden fazla öteleme sayısı CL ile verilir: `MOV CL, 3` / `SHL AX, CL`.
  - `SHR`: bitler bir sağa kayar, D0 CF'ye gider, MSB'ye 0 girer.
  - `SAR`: D0 CF'ye gider, MSB kendini tekrarlar; işaretli sayıyı 2'ye böler. Örnek: $-16 = 1111\,0000_2$, `SAR AL, 1` → $1111\,1000_2 = -8$. $+16 = 0001\,0000_2$ → $0000\,1000_2 = 8$.
  - `RCL`/`RCR`: CF ile birlikte 9 (ya da 17) bit üzerinden döndürme. `ROL`/`ROR`: yalnız işlenen genişliğinde döndürme; çıkan bit öbür uca yazılırken CF'ye de kopyalanır.
  - Kapı örneği: 16 kapının açık (1)/kapalı (0) bilgisi AX'teyse, AX her seferinde bir sola ötelenip CF sayılarak açık kapı sayısı bulunur.
- Dizi örneği: byte dizisindeki tek elemanları sayma (ekrandan, 01:35:00-02:30:00)
  - Problem: N elemanlı `ARRAY` byte dizisindeki tek eleman sayısını `ODD` değişkenine yazan assembly kodu. Veri: `N DW 500`, `ARRAY DB 1,2,8,20,25,495 DUP(81)`, `ODD DW 0`. N ve ODD 500'e kadar değer alabileceği için word tanımlanır; ODD sayaç olduğu için ilk değeri 0'dır.
  - Dört yöntem: (1) `SHR` + `ADC`, (2) `SHR` + `JC`/`JNC`, (3) `TEST` + `JZ`, (4) `DIV` + kalan kontrolü. Dördü de emülatörde ODD = 01F1h = 497 verdi.
  - `DIV` 8 bitlik bölmede AX'i işlenene böler: bölüm AL'ye, kalan AH'a yazılır. `DIV 2` ve `DIV AL, 2` geçersizdir; bölen bir yazmaç ya da bellek olmalıdır (`MOV BL, 2` / `DIV BL`). AL'deki değeri bölmeden önce AH sıfırlanmalıdır.
  - `LEA BX, ARRAY` ile dizinin ofseti BX'e alınır; `[BX]` ilk elemanı gösterir. Byte dizisinde `INC BX`, word dizisinde `ADD BX, 2` sonraki elemana geçer.
  - `ADC ODD, 0` ile dallanmasız çözüm: CF = 1 ise ODD bir artar.
  - Word dizisine geçince yalnız `MOV AL, [BX]` → `MOV AX, [BX]`, `SHR AL, 1` → `SHR AX, 1` ve `INC BX` → `ADD BX, 2` değişir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Döngü değişkeni 16 bitlik CX'tir ve döngüden önce ilk değeri verilmelidir.
  - `LOOP` önce azaltır, sonra kontrol eder; CX = 0 için gövde çalışmaz.
- `JCXZ` ile kurulan döngüde CX'i kullanıcı değiştirmezse döngü sonsuzdur.
  - İkişer azalan örnekte CX tek bir sayıyla (9 ya da 11) başlasaydı sıfırdan atlanırdı ve döngü hiç kırılmazdı.
- Koşullu dallanmada koşul boş kol için yazılırsa tek bir dallanma komutu yeter (WHILE ve REPEAT örneklerinde de bu yol izlendi).
- İç içe döngülerde dış CX yedeklenmelidir; PUSH/POP çiftleri birbirini karşılamalıdır.
- Birden fazla öteleme/döndürme sayısı CL ile verilmelidir.
  - Emülatör `SHR AX, 4` yazımını kabul edip dört tane `SHR AX, 1`'e çevirir; bu emülatörün kolaylığıdır, komut kümesinde böyle bir biçim yoktur.
- `DIV`'den sonra hem AL hem AH değiştiği için kalanı kontrol etmeden önce `AND AH, 01H` ile maskelenmeli ki ZF kesin AH'tan gelsin.
- Bellek işleneni ile anlık değer birlikte kullanılınca tip açıkça belirtilmeli: `TEST BYTE PTR [BX], 01H`. Emülatör tip yazılmazsa byte kabul etti.
- Çalışan her çözüm doğrudur, ama daha az satırlı ve dallanmasız çözüm tercih edilmelidir.
  - Dallanmalarda önden çekilen (prefetch) komutlar boşa gidebilir; dallanmasız kodlama (branchless coding) bu yüzden ilgi çeken bir konudur.

## Kısa Tekrar Notları

- `LOOP`: CX--, CX ≠ 0 ise dallan.
- `LOOPZ`/`LOOPE`: CX--, CX ≠ 0 ve ZF = 1 ise dallan.
- `LOOPNZ`/`LOOPNE`: CX--, CX ≠ 0 ve ZF = 0 ise dallan.
- `JCXZ`: CX = 0 ise dallan; CX'e dokunmaz.
- WHILE'da gövde hiç çalışmayabilir; REPEAT UNTIL'de en az bir kez çalışır.
- İç içe FOR: `PUSH CX` / iç döngü / `POP CX` ya da `MOV DX, CX` / ... / `MOV CX, DX`.
- `CLC`, `STC`, `CMC`, `CLD`, `STD`, `STI`, `CLI`; `LAHF`/`SAHF` (SF, ZF, AF, PF, CF); OF ve TF için `PUSHF`/`POPF`.
- AND ile sıfırla, OR ile birle, XOR ile tümle.
- `SHL = SAL` (×2), `SHR` lojik (÷2, işaretsiz), `SAR` aritmetik (÷2, işaret korunur).
- `RCL`/`RCR` CF dahil döner; `ROL`/`ROR` işlenen içinde döner ve çıkan biti CF'ye de yazar.
- 8 bitlik `DIV op`: AL ← AX / op, AH ← AX mod op.
- Bir sayının tek/çift olduğu en düşük bitinden anlaşılır: `SHR` ile CF'ye düşür, `TEST` ile maskele ya da 2'ye bölüp kalana bak.

## Detaylı Açıklamalar

- **Dizi örneğinin şablonu.** Kod emu8086'da şu şablona yazıldı (ekrandan, 01:35:00 ve 02:25:00). Öğrenciler şablonun başlangıç ve bitiş satırlarını henüz tam bilmediği için kod yalnız işaretli aralığa yazıldı:

```asm
STEK    SEGMENT PARA STACK 'STK'
        DW 30 DUP(?)
STEK    ENDS

DSG     SEGMENT PARA 'DTS'
N       DW 500
ARRAY   DB 1,2,8,20,25,495 DUP(81)
ODD     DW 0
DSG     ENDS

CSG     SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:DSG, SS:STEK
BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX
        MOV AX, DSG
        MOV DS, AX
;kod buradan sonra
        ...
;kod buraya kadar
        RETF
BASLA   ENDP
CSG     ENDS
        END BASLA
```

- **Yöntem 4, DIV ile** (ekrandan, 01:45:00, 01:50:00, 01:55:00). Elemanlara `ARRAY[SI]` ile indisli erişilir. `ARRAY[SI]` "veri segmentinde ARRAY adresinden SI kadar ötedeki bayt" demektir. Önce `DIV 2` ve `DIV AL, 2` denendi; ikisi de "register ya da bellek olmalı" hatası verdi. Sonra `MOV AX, ARRAY[SI]` denendi; "operands do not match: 16 bit register and 8 bit address" hatası alındı. Doğru biçim:

```asm
        MOV CX, N
        XOR SI, SI
        MOV BL, 2
L1:     MOV AL, ARRAY[SI]
        MOV AH, 0          ; AH sıfırlanır
        DIV BL             ; 8 bit div: AL <- AX/op, AH <- AX mod op
        AND AH, 01H
        JZ CIFT
        INC ODD
CIFT:   INC SI
        LOOP L1
```

<!-- BELİRSİZ: AH'ı sıfırlayan satırın tam yazımı (MOV AH, 0 ya da XOR AH, AH) karede görünmüyor; DIV BL'den sonraki satırlar kareden alındı. -->

- **Yöntem 3, TEST ile** (ekrandan, 02:00:00). `LEA BX, ARRAY` sonrası `[BX]`, `ARRAY[0]`'a eşittir. Önce `MOV AL, [BX]` / `TEST AL, 01H` yazıldı, sonra iki satır `TEST BYTE PTR [BX], 01H` olarak birleştirildi. `TEST` sonucu 0 ise sayı çifttir:

```asm
        LEA BX, ARRAY
        MOV CX, N
L1:     TEST BYTE PTR [BX], 01H
        JZ CIFT
        INC ODD
CIFT:   INC BX
        LOOP L1
```

<!-- BELİRSİZ: Birleştirilmiş son hâlin karesi okunmadı; satır sırası anlatımdan kuruldu. INC BX'in TEST'ten sonra gelmesi 497 sonucuyla tutarlıdır. -->

- **Yöntem 2, SHR ve JNC ile.** En düşük bit `SHR AL, 1` ile CF'ye düşürülür. Boş kol (çift) için `JNC CIFT` yazılır, tek kolda `INC ODD` vardır. Döngü gövdesi: `MOV AL, [BX]` / `INC BX` / `SHR AL, 1` / `JNC CIFT` / `INC ODD` / `CIFT: LOOP L1`.
- **Yöntem 1, SHR ve ADC ile** (ekrandan, 02:25:00 ve 02:30:00). Bir öğrencinin önerisidir. Gövde: `MOV AL, [BX]` / `INC BX` / `SHR AL, 1` / `ADC ODD, 0` / `LOOP L1`. `ADC ODD, 0` işlemi ODD ← ODD + 0 + CF yapar; dallanma yoktur. Word dizisi için gövde: `MOV AX, [BX]` / `SHR AX, 1` / `ADC ODD, 0` / `ADD BX, 2` / `LOOP L1`. Emülatörün çözümlediği kodda `LEA BX, ARRAY` satırı `MOV BX, 00002h` olarak görünür (ARRAY, N'den sonra 2. ofsettedir).
- **Sayısal doğrulama.** Assembler/emülatör bu ortamda kurulu olmadığı için kodlar derlenmedi; komutların etkisi python ile adım adım taklit edildi. Dizide 1, 25 ve 495 tane 81 tektir: $2 + 495 = 497 = 01F1h$. Word dizide ODD'nin ofseti $2 + 500 \cdot 2 = 1002 = 03EAh$ olup emülatör ekranındaki `ADC w.[003EAh]` ile tutarlıdır.

> **Ders sonrası not:** Hoca TEST yöntemini ilk sayarken "TEST ve jump carry / jump not carry" dedi ve tahtaya `JC` yazdı; sonra "yanlış yazmışım" diyerek `JZ` olarak düzeltti. `TEST` (AND gibi) CF'yi her zaman 0 yapar; doğrusu `JZ`/`JNZ`'dir.

> **Ek bilgi (derste anlatılmadı):** Word dizisinde `ADD BX, 2` satırı `ADC`'den sonra gelmelidir. `ADD` CF'yi değiştirir; `SHR` ile `ADC` arasına konsaydı sonuç bozulurdu. Byte sürümündeki `INC BX` ise CF'yi etkilemediği için `SHR`'den önce durabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
