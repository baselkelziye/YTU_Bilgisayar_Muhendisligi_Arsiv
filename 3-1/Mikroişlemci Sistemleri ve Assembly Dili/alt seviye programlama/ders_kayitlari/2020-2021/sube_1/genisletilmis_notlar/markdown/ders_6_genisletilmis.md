# Ders 6 Genişletilmiş Notu: Derleme Ortamı, DEBUG Programı ve EXE Tipi Programlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Derslerin Tekrarı
- 2. Derleme Ortamı: DOSBox, MASM, LINK, EXE2BIN ve DEBUG
- 3. Örnek Program: deneme.asm
- 4. LST Dosyasının İncelenmesi
- 5. Segment Hizalaması ve Bellek Erişim Hızı
- 6. Linkleme ve Programı Çalıştırma
- 7. DEBUG Programıyla Adım Adım İnceleme
- 8. EXE Tipi Programların Yapısı
- 9. Örnek 1: İki 16 Bitlik Sayının 32 Bitlik Toplamı
- 10. Örnek 2: Dizideki Tek ve Çift Sayıları Sayma
- 11. Örnek 3: Onaltılık Basamakları Ters Çevirme
- 12. Zorunlu Olmayan Alıştırmalar
- Örnek Sorular

## 1. Önceki Derslerin Tekrarı

Hoca derse geçen haftaların kısa bir tekrarıyla başladı. Adresleme modları üç başlık altında incelenmişti: veri erişimi, program hafızası erişimi ve yığın erişimi.

### 1.1 Yığın ve program hafızası adreslemesi

Yığın adreslemede PUSH ve POP komutları kullanılır. Bu komutlarla yığın üzerinde hareket edilirken SP'nin güncellenmesini mikroişlemci kendisi yapar.

Program hafızası adreslemesi, CS ve IP yazmaçlarını değiştiren komutlardan oluşur: koşulsuz dallanma (JMP), koşullu dallanmalar, CALL, RET ve IRET. Yapısal bir programda IP her komutun boyu kadar artarak ilerler, komutlar peş peşe yürütülür. JMP gibi bir komuta gelindiğinde ise IP (segmentler arası dallanmada CS de) bir anda başka bir konumu gösterecek biçimde değişir.

Aynı segment içindeki görece dallanmalarda (JMP ve koşullu dallanmalar) dallanma miktarı 8 ya da 16 bitlik işaretli bir sayıdır. Bu değeri programcı hesaplamak zorunda değildir: assembly kodunda bir etikete dallanılır, assembler bu etiketi sayısal bir değere çevirir. LST dosyasında bütün etiketlerin sayısal karşılıklarıyla değiştiği görülür. Örneğin `JMP 0FFH` görülürse bu "bir byte geri dallan" demektir, çünkü 8 bitlik işaretli sayı olarak FFH, −1'dir.

### 1.2 Veri adreslemesi

- **Yazmaç adresleme:** Yazmaçlar arasında veri aktarımı.
- **Doğrudan adresleme:** Köşeli parantez içine tek bir sabit değer yazılarak belleğin hangi gözüne erişileceği belirtilir.
- **Dolaylı adresleme:** Köşeli parantez içinde bir yazmaç ya da yazmaç + ofset bulunur.

Dolaylı adreslemede köşeli parantez içine yazılabilecek yazmaçlar sınırlıdır. Veri erişimi için yalnız BX, SI ve DI kullanılabilir. Geçerli biçimler şunlardır: `[BX]`, `[SI]`, `[DI]`, `[BX+SI]`, `[BX+DI]`, `[BX+100H]`, `[BX+SI+100H]`, `[BX+DI+100H]`. Yığın erişiminde köşeli parantez içinde BP de kullanılabilir.

**Soru (hoca sordu):** Köşeli parantez içinde BP kullanılırsa varsayılan segment yazmacı nedir? **Cevap:** Stack segment (SS). BX, SI, DI ya da sabit bir değer kullanıldığında ise 20 bitlik adres hesabında DS kullanılır.

### 1.3 Sözde komutlar

Sözde komutlar assembler'dan assembler'a değişebilir. Örneğin bazı assembler'larda yığın `.stack` diye tanımlanır. Derste kullanılan Microsoft Macro Assembler'da segment, prosedür, veri ve makro tanımlarının nasıl yazıldığı geçen hafta görülmüştü.

> **Hocanın vurgusu:** Assembler'dan geçtikten sonra makine kodu karşılığı olan yalnız komutlardır (instruction). Etiketin de makine kodu yoktur: bir adrese karşılık gelir ve içeride adres olarak kullanılır. Programcının ne kadar geri gideceğini hesaplamak zorunda olmaması, bu hesabı assembler'ın yapması çok önemli bir noktadır.

Bu haftanın konusu, derleme ortamındaki araçlar ve EXE tipi programlardır.

## 2. Derleme Ortamı: DOSBox, MASM, LINK, EXE2BIN ve DEBUG

### 2.1 Kurulum

Hoca derste kullanılacak araçları dersin sayfasına "Araçlar" başlığı altında koydu. Önce DOSBox kurulur. Kurulum yolu büyük olasılıkla C sürücüsünün altında bir `DOSBOX` klasörü olur. Yolda boşluk bulunursa (örneğin Program Files gibi bir klasör) DOSBox sorun çıkarabilir. Bu yüzden içinde boşluk olmayan bir yola kurulması önerildi. Hoca, bu klasörün içinde `bin` adlı bir klasör açıp derleme araçlarını oraya koymuştu.

### 2.2 Derleme zinciri

```text
1.asm --(MASM)--> 1.obj  (+ 1.lst)
2.asm --(MASM)--> 2.obj  (+ 2.lst)
1.obj + 2.obj --(LINK)--> program.exe
program.exe --(EXE2BIN)--> program.com   (yalnız COM tipi programlar için)
```

- **MASM (Macro Assembler):** Her `.asm` dosyasını ayrı ayrı derler ve bir obje dosyası üretir.
- **LINK:** Obje dosyalarını birleştirip EXE programı oluşturur. Örneğin ana program `1.asm`'de, yardımcı bir yordam `2.asm`'de olabilir. İkisi ayrı ayrı derlenir, sonra obje dosyaları aralarına `+` konarak birlikte linklenir. Bunların tek bir EXE hedefi olur.
- **EXE2BIN:** Yazılan program COM tipiyse, aynı yol izlenir. Oluşan EXE dosyası bu hâliyle çalışabilir değildir. EXE2BIN'e verilince COM tipi program elde edilir.
- **DEBUG:** DOS'ta çalışan hata ayıklayıcıdır. Bir programı başlatıp adım adım ilerlemeye, her adımda yazmaçların değerlerini görmeye, gerekirse yazmaç ve bellek değerlerini değiştirip programı yeniden çalıştırmaya, programın bellekte değiştirdiği alanları görmeye yarar.

> **Ders sonrası not:** Hoca obje dosyalarının uzantısını ".o" diye söyledi. MASM'ın ürettiği obje dosyalarının uzantısı `.OBJ`'dir. Ekranda da `DENEME.OBJ` görülüyor (ekrandan, 01:10:00).

### 2.3 DOSBox'ın klasörü bağlaması

DOSBox kurulunca kendine ait bir sürücü oluşturur. Ayarlar (options) dosyasında `autoexec` bölümüne iki satır eklenir (ekrandan, 02:10:00):

```text
mount c c:\dosbox
c:
```

Birinci satır, yerel bilgisayardaki `C:\DOSBOX` klasörünü DOSBox içinde C sürücüsü olarak bağlar (mount). İkinci satır, eski DOS'taki gibi sürücü adı ve iki nokta yazılarak o sürücüye geçer. Hoca önce bu satırlar olmadan DOSBox'ı açtı: DOSBox Z sürücüsünde açıldı. Satırlar eklenince DOSBox açılırken bu komutları otomatik çalıştırdı ve doğrudan C sürücüsüne geçti. Böylece yerel `C:\DOSBOX` klasöründeki her dosyaya DOSBox içinden erişilebilir.

Klasör içeriği `DIR` komutuyla listelenir.

## 3. Örnek Program: deneme.asm

Hoca daha önceki örneklerden bir dosyayı `deneme.asm` adıyla kopyaladı. Program şudur (ekrandan, 00:25:00, 00:45:00 ve 00:50:00):

```asm
PAGE 80, 60

STKSG SEGMENT PARA STACK 'STK'
        DW 20 DUP (?)
STKSG ENDS

DATASG SEGMENT PARA 'DAT'
        A DB 2
        B DB 10
        SONUC DW 0
DATASG ENDS

CODESG SEGMENT PARA 'CD'
        ASSUME CS: CODESG, DS: DATASG, SS: STKSG
        SON PROC FAR
                PUSH DS
                XOR AX, AX
                PUSH AX

                MOV AX, DATASG
                MOV DS, AX
                XOR DX, DX
                XOR CX, CX
                MOV AX, 1
                MOV CL, B
                XOR BX, BX
                MOV BL, A
        L1:     MUL BX
                LOOP L1
                MOV SONUC, AX
                RETF
        SON ENDP
CODESG ENDS
        END SON
```

Bu bir EXE tipi programdır. EXE tipi programlarda üç segment tanımlı olmalıdır. İşletim sistemi programı belleğe yüklerken bu üç segment için yer ayırır. Yerleşim sıradaki boş segmente göre yapılır.

Program çalıştırıldığında nereden başlar? `END` kelimesinden sonra `SON` etiketi gelir. Bu yüzden kod segmentindeki `SON` etiketinden itibaren çalışmaya başlanır. Hoca kod segmentindeki bölümleri şöyle ayırdı:

- `PUSH DS`, `XOR AX, AX`, `PUSH AX`: işletim sistemine geri dönüşle ilgili üç satır.
- `MOV AX, DATASG`, `MOV DS, AX`: yukarıda tanımlanan veri segmentinin kodda kullanılabilmesini sağlayan iki satır.
- Sonraki satırlar: programın asıl işi.
- `RETF`: prosedürden, dolayısıyla işletim sistemine dönüş.

Segment tanım satırları, `ASSUME` satırı, prosedür başlangıç ve bitiş satırları sözde komuttur, makine kodu karşılıkları yoktur. Kod segmentinde makine kodu karşılığı olanlar yalnız komut kümesinde bulunabilen komutlardır.

Makine kodu üretmese de yer kaplayan başka bölgeler de vardır. Veri segmentinde tanımlanan her değişken için ilgili boyutta yer ayrılır ve verilen değer orada saklanır. Yığın segmentinde de belirli bir boyutta yer ayrılır.

### 3.1 Yığın boyu neden çift olmalı?

Yığın için ayrılan boyutun çift olması gerekir. Çünkü PUSH ve POP ile yalnız word tipinde işlem yapılabilir: byte, double word ya da quad word işlemi yapılamaz. Yığına her atma ya da yığından her çekme çift sayıda byte demektir. Bu yüzden ya `DW n DUP(?)` yazılır ve $2n$ byte ayrılır, ya da `DB` kullanılıyorsa verilen sayının çift olmasına dikkat edilir.

Bu programda yığın için 20 word, yani 40 byte ayrılmıştır. Veri segmenti için 1 byte (A), 1 byte (B) ve 1 word (SONUC), toplam 4 byte ayrılmıştır. Kod segmentinin boyu ise her komutun kaç byte tuttuğunun toplamıdır.

Bunlardan başka EXE tipi programlarda bir başlık (header) bilgisi bulunur. Bu bölüm programın çağrılması ve yürütülmesiyle ilgili bilgileri içerir.

## 4. LST Dosyasının İncelenmesi

### 4.1 Derleme

Program DOSBox içinde MASM klasöründe şöyle derlendi:

```text
c:\bin\masm.exe deneme.asm
```

MASM önce oluşturacağı obje dosyasının adını, sonra LST (listeleme) dosyasının adını sorar. Hoca ikisine de `deneme` adını verdi, CRF (cross-reference) dosyasını istemedi. Sonuçta bir obje dosyası ve bir LST dosyası oluştu.

**Soru:** Kodun başındaki `PAGE 80, 60` nedir? **Cevap:** LST dosyası bir metin gibi düşünülürse bu satır onun sayfa düzenini tanımlar: bir sayfanın kaç satır ve kaç sütundan oluştuğunu belirtir. Çok önemli bir şey değildir.

### 4.2 Birinci bölüm: ofset ve içerik

LST dosyasının birinci bölümünde (ekrandan, 00:30:00 ve 00:45:00) her satır için ilgili segment içindeki ofset ve o ofsetteki veri ya da makine kodu yer alır:

```text
0000                STKSG SEGMENT PARA STACK 'STK'
0000  0014[             DW 20 DUP (?)
        ????
           ]
0028                STKSG ENDS

0000                DATASG SEGMENT PARA 'DAT'
0000  02                A DB 2
0001  0A                B DB 10
0002  0000              SONUC DW 0
0004                DATASG ENDS

0000                CODESG SEGMENT PARA 'CD'
                        ASSUME CS: CODESG, DS: DATASG, SS: STKSG
0000                    SON PROC FAR
0000  1E                    PUSH DS
0001  33 C0                 XOR AX, AX
0003  50                    PUSH AX
0004  B8 ---- R             MOV AX, DATASG
0007  8E D8                 MOV DS, AX
0009  33 D2                 XOR DX, DX
000B  33 C9                 XOR CX, CX
000D  B8 0001               MOV AX, 1
0010  8A 0E 0001 R          MOV CL, B
0014  33 DB                 XOR BX, BX
0016  8A 1E 0000 R          MOV BL, A
001A                    L1:
001A  F7 E3                 MUL BX
001C  E2 FC                 LOOP L1
001E  A3 0002 R             MOV SONUC, AX
0021  CB                    RETF
0022                    SON ENDP
0022                CODESG ENDS
                        END SON
```

**Yığın segmenti:** Yığın, segmentin 0 ofsetinden 28H ofsetine kadar uzanır. LST'deki bütün değerler onaltılıktır: $28H = 16 \cdot 2 + 8 = 40$. Yani 40 byte'lık bir alandır. 40 değeri, 20 word yer ayrılmasından gelir.

**Veri segmenti:** Segment tanım satırı da ilk değişken satırı da 0 ofsetinde görünür. Bunun nedeni, segment tanım satırının makine kodu üretmemesi ve bu yüzden ofseti ilerletmemesidir. Ofset değişimi değişkenlerle başlar:

- 0 ofsetinde `02`: A değişkeni byte tipindedir, değeri onluk 2'dir. Onaltılık karşılığı 02H'dir.
- 1 ofsetinde `0A`: B değişkeni byte tipindedir, değeri onluk 10, onaltılık 0AH'dir.
- 2 ofsetinde `0000`: SONUC word tipindedir, değeri 0'dır. Word olarak 0000H yazılır. 2 byte olduğu için 2. ve 3. ofsetleri kaplar. Segment 4. ofsette biter.

**Kod segmenti:** Segment tanım satırı, ASSUME satırı, prosedür tanımı ve bitişi, segment bitişi ve `END SON` satırlarının makine kodu yoktur.

### 4.3 Makine kodunu komut kümesinden bulma

Hoca `PUSH DS` komutunun `1E` kodunun nereden geldiğini, daha önce paylaşılan 8086 komut kümesi tablosundan gösterdi. Bu tablonun faydası, bir komutun hangi operandlarla kullanılabileceğini, yani sınırlarını göstermesidir.

`PUSH DS` bir segment yazmacını yığına attığı için tablonun segment yazmacı satırına bakılır. Makine kodu `000RR110` biçimindedir ve işlem 10 saat çevrimi sürer. Bu kadar uzun sürmesinin nedeni, arka planda SP'nin azaltılması ve verinin yığına taşınması gibi bir dizi işlemin olmasıdır. RR değeri tablonun başındaki açıklama bölümünde verilir: DS için RR = 11'dir. Basamaklar yerine konunca:

$$0001\ 1110_2 = 1EH$$

Hoca aynı şeyi `XOR AX, AX` için yapmaya çalıştı. LST'de kod `33 C0` idi. Tabloda (ekrandan, 00:40:00) `XOR RW,DADDR` satırı `33` ile, `XOR DADDR,RW` satırı `31` ile başlıyordu. Hoca derste 33 ile başlayan satırı bellek adresli bir biçim olarak gördüğü için tam eşleştiremedi. Kendisi olsa 31 ile başlayan satırı düşüneceğini, AX için özel bir biçim olabileceğini söyledi.

> **Ders sonrası not:** Büyük olasılıkla burada özel bir AX komutu yoktur. `33` kodu "RW ← RW XOR [EA]" biçimidir. Arkasından gelen `C0` byte'ında mod alanı 11 olduğu için ikinci operand bellek değil, yine bir yazmaçtır (AX). `31 C0` de aynı işi yapan geçerli bir koddur. Assembler iki yazmaçlı XOR için 33 biçimini seçmiştir.

### 4.4 R ve ---- R işaretleri

Bazı satırların yanında `R` harfi vardır. R, relative (görece) demektir: adres, veri segmentinin başlangıcına göre verilmiştir.

- `MOV CL, B`: B, veri segmentinin 1 ofsetindeki byte değişkendir. Assembler bu komutu `MOV CL, [0001]` biçimine çevirir. Yani etiket kullanımı aslında dolaylı adreslemedir.
- `MOV BL, A`: A 0 ofsetindedir, `[0000]` olur.
- `MOV SONUC, AX`: SONUC 2 ofsetindedir, `[0002]` olur.

`B8 ---- R` (`MOV AX, DATASG`) satırında ise tireler vardır. Bu, adresin assembly sırasında belli olmadığı anlamına gelir. Değer, DATASG segmentinin belleğe yerleşmesiyle ilgilidir. Segmentlerin yeri program belleğe yüklenirken, hizalama da dikkate alınarak sıradaki boş adrese göre belirlenir. Bu yüzden bu değer program yüklendikten sonra belli olur.

### 4.5 İkinci bölüm: segmentler

LST dosyasının ikinci bölümünde segmentlerin adları, uzunlukları, hizalama tipleri, birleştirme tipleri ve sınıf adları verilir (ekrandan, 00:50:00). Bu programda CODESG 0022H, DATASG 0004H, STKSG 0028H uzunluğundadır.

Burada hoca önemli bir noktayı hatırlattı. Segmentlere verilen adlar (STKSG, DATASG, CODESG) yalnız etikettir. "Ali", "Ayşe" de olabilirdi, assembler açısından fark etmez.

- Bir segmenti **yığın segmenti** yapan, birleştirme (combination) alanına yazılan `STACK` kelimesidir.
- Bir segmenti **veri segmenti** yapan, kod segmentindeki `MOV AX, DATASG` ve `MOV DS, AX` satırlarıdır. Birçok segment tanımlanıp bunlardan biri veri segmenti olarak seçilmek istenirse bu işlem yapılmak zorundadır. Bu özel komut çiftinden sonra DS, tanımlanan alanın başlangıç segment değerini tutar.
- Bir segmenti **kod segmenti** yapan, `END` kelimesinden sonra gelen etiketin o segment içinde bulunmasıdır. Segmentin adı "Ahmet", "Mehmet" de olsa yürütülecek alan orası olur.

### 4.6 Üçüncü bölüm: semboller

Son bölümde bütün etiket ve değişkenler, tipleri (`L BYTE`, `L NEAR`, `F PROC` gibi), hangi segmentte ve hangi ofsette bulundukları ile listelenir (ekrandan, 00:50:00).

## 5. Segment Hizalaması ve Bellek Erişim Hızı

### 5.1 Hizalama tipleri

Segment tanımındaki hizalama alanı, segmentin bellekte hangi adresten başlayacağını belirler:

- **BYTE:** Sıradaki boş adresten başlar.
- **WORD:** Sıradaki çift adresten (2'nin katı) başlar.
- **PARA:** 16'nın tam katı olan adresten başlar.
- **PAGE:** 256'nın tam katı olan adresten başlar.

### 5.2 Hizalama neden önemli?

8086, tasarımı ve bellek arayüzü gereği şunları tek bir okuma-yazma çevriminde yapabilir:

- Çift adresten 8 bitlik bir veriyi okumak ya da yazmak.
- Tek adresten 8 bitlik bir veriyi okumak ya da yazmak.
- Çift adresten başlayan bir word'ü okumak ya da yazmak.

Sorun, tek adresten başlayan bir word'e erişildiğinde çıkar. Mikroişlemci önce tek adresteki düşük anlamlı byte'ı okur ve birinci çevrimi bitirir. Sonra bir sonraki çift adresteki yüksek anlamlı byte'ı okur. İşlem ancak iki çevrimde biter, yani süre iki katına çıkar. Veri tanımları hizalı yapılırsa mikroişlemcinin onlara erişimi hızlanır.

Hoca bunun günümüz bilgisayarlarında da geçerli olduğunu söyledi. Hem veri tanımlarındaki hizalamaya hem de verinin önbellekteki (cache) yerleşimine dikkat eden programlar daha hızlı çalışır. Bilgisayar donanımı dersinde görülecek olan önbellekte mikroişlemci veriyi belirli bir mantıkla ana bellekten önbelleğe çeker. Veri tanımları ve döngüler buna uygun yazılırsa aranan verinin önbellekte bulunma olasılığı artar ve program hızlanır.

### 5.3 deneme.asm'de segmentlerin yerleşimi

Üç segment de PARA ile tanımlanmıştır:

- Yığın segmenti 16'nın katı olan bir adresten (göreli 0) başlar ve 40 byte sürer.
- Sonraki 16'nın katı 48'dir. Arada 8 byte'lık bir boşluk kalır. Veri segmenti 48'de başlar, boyu 4 olduğu için 52'de biter.
- Sonraki 16'nın katı 64'tür. 52 ile 64 arasında yine boşluk kalır. Kod segmenti 64'te başlar.

## 6. Linkleme ve Programı Çalıştırma

Obje dosyasından EXE programı oluşturmak için LINK kullanıldı:

```text
c:\bin\link.exe deneme.obj
```

LINK, çalıştırılabilir dosya için varsayılan bir ad önerir. Hoca bunu kabul etti, MAP ve LIB dosyalarını boş geçti. Sonuçta `deneme.exe` oluştu (ekrandan, 01:00:00).

**Soru (hoca sordu):** Bu EXE dosyası Windows 10'un klasöründe tıklanarak çalıştırılabilir mi? **Cevap:** Hayır. Bu 16 bitlik bir koddur. Günümüzde kullanılan işlemciler ve sistemler yalnız 32 ve 64 bitlik bellek kiplerine uygun programları çalıştırır. Bu yüzden program DOSBox'ın komut satırından çalıştırılır.

DOSBox'ta `deneme` yazılınca program çalıştı ve bitti, ama ekrana bir şey yazdırmadığı için sonuç görülmedi. Hoca kodu okuyarak ne yaptığını çıkardı: DX ve CX sıfırlanır, AX'e 1 yazılır, CL'ye B, BL'ye A atanır. Döngüde AX, BX ile çarpılır ve LOOP ile CL kez tekrarlanır. Yani B kez A ile çarpılır ve program $A^B$ değerini hesaplayıp SONUC değişkenine yazar. Bunu görmek için DEBUG kullanılır.

## 7. DEBUG Programıyla Adım Adım İnceleme

### 7.1 Başlangıç durumu: R komutu

Program şöyle açıldı:

```text
c:\bin\debug.exe deneme.exe
```

İlk komut `R` (register) oldu. Program belleğe yüklenmiş ve `SON` etiketine gelinmiş, ama henüz o satır çalıştırılmamış durumdaki yazmaçlar görüldü (ekrandan, 01:00:00):

```text
AX=FFFF  BX=0000  CX=0062  DX=0000  SP=0028  BP=0000  SI=0000  DI=0000
DS=075A  ES=075A  SS=076A  CS=076E  IP=0000   NV UP EI PL NZ NA PO NC
076E:0000 1E            PUSH    DS
```

- AX, BX, CX, DX, BP, SI ve DI'daki değerler önceden kalan değerlerdir. Program bunlara bir şey yüklemedi.
- DS ve ES aynı özel değerle yüklenmiştir.
- SS, tanımlanan yığın bölgesinin belleğe yerleşmiş hâlinin segment değeridir.
- CS, kod segmentinin segment değeridir. IP = 0'dır, çünkü kod segmentinin 0 ofsetinde, yani `PUSH DS` satırındayız.
- Sağdaki kısaltmalar bayraklardır: overflow yok (NV), yön yukarı (UP), kesmeler açık (EI), pozitif (PL), sıfır değil (NZ), yardımcı elde yok (NA), tek eşlik (PO), elde yok (NC).

Program yeni yüklendiği için kullanmak istediğimiz veri segmentinin nerede olduğunu henüz bilmez. **DS ve ES'deki değerler nedir?** Bunlar programımızı çağıran işletim sistemi programının bulunduğu segment değeridir. Bu değer yığına atılırsa, program dönerken RETF ile beni çağıran işletim sistemi programına geri dönülür. `PUSH DS` yapılmasının nedeni budur.

Beni çağıran program, DS'deki segmentin 0 ofsetinde yer alır. RETF yığından önce bir ofset, sonra bir segment değeri çeker. Bu yüzden DS'den sonra yığına bir de 0 ofseti atılmalıdır. Bunu `XOR AX, AX` ve `PUSH AX` satırları yapar. Artık yığında altta segment değeri, üstte 0 ofseti vardır. RETF ile dönülürken IP'ye 0, CS'ye DS'deki değer yüklenir ve işletim sistemine geri dönülür.

> **Ek bilgi (derste anlatılmadı):** DOS bir EXE programını yüklediğinde DS ve ES büyük olasılıkla programın PSP (Program Segment Prefix) adı verilen 256 byte'lık başlık bölgesini gösterir. PSP'nin 0 ofsetinde programı sonlandırıp DOS'a dönen bir `INT 20H` komutu bulunur. Bu yüzden RETF ile DS:0000 adresine dönmek programın düzgün biçimde sonlanmasını sağlar.

### 7.2 Makine kodunun çözülmesi

CS = 076EH ve IP = 0 olduğuna göre sıradaki komut bu iki değerden oluşan 20 bitlik adresteki komuttur: `PUSH DS`. Hoca makine kodlarının birbirinden ayrılmasının kolay olduğunu, bunun doğal bir dili ayrıştırmaya benzediğini söyledi. Derleyici tasarımı (compiler design) da otomata teorisinin devamı gibidir. Hangi makine kodu bloğunun hangi komuta karşılık geldiği bu yüzden çözülebilir.

### 7.3 T komutu ve yığının değişimi

`T` (trace) komutu bir adım yürütür. Adım adım ilerlendiğinde (ekrandan, 01:00:00 ve 01:05:00):

- `PUSH DS` sonrası SP = 0026H oldu: DS yığına atıldı.
- `XOR AX, AX` sonrası AX = 0000 oldu. Önceden AX'te FFFF vardı.
- `PUSH AX` sonrası SP = 0024H oldu: 0 değeri yığına atıldı.
- `MOV AX, DATASG` satırı DEBUG'da `MOV AX, 076D` olarak görüldü. Tanımladığımız veri segmenti gerçekte 076DH'ye yerleştirilmiş, ama program henüz onu veri segmenti olarak kullanmayı bilmiyordu.
- `MOV DS, AX` sonrası DS = 076DH oldu. Artık tanımlanan segment dolaylı adreslemelerle erişilebilir durumdadır.

Hoca SP'nin başlangıç değerini ayrıca açıkladı. Yığın için $2 \times 20 = 40$ byte ayrılmıştır, adresler 0'dan 39'a kadar gider. Ama başlangıçta SP = 28H, yani 40'tır: alanın hemen dışını gösterir. Bunu şöyle düşünmek gerekir: SP sıradaki dolu gözü gösterir. Başta 40'ı, alanın dışındaki erişilemeyen "dolu" bir gözü gösteriyormuş gibi düşünülür. PUSH yapılınca önce sıradaki boş göze gidilir: SP 2 azalır ve onluk 38'i (26H) gösterir, değer oraya yazılır. Artık SP yine sıradaki dolu gözü gösterir, ama bu kez gözde anlamlı bir veri vardır. Sonraki PUSH'ta SP 24H olur ve oraya 0000 yazılır.

**Soru:** COM tipi bir program olsaydı bunların aynısını yapamazdık, değil mi? **Cevap:** COM tipi programda tek bir segment vardır. Bu segment hem veri hem kod hem de yığın segmenti olarak kullanılır. Segmentin 100H ofsetinden itibaren hem veri hem program yerleşir. Yığın bu segmentin en son adresinden itibaren kullanılır. COM tipi programdan geri dönüş için yığına otomatik bir değer atıldığı için SP, COM programlarında FFFEH'den başlar. Hoca bunun ayrıntısına COM tipi programlar konusunda döneceğini söyledi.

### 7.4 D komutu ile bellek dökümü

`D` (dump) bir bellek bölgesini ekrana döker. `D DS:0` komutu DS'nin gösterdiği segmentin 0 ofsetinden itibaren olan alanı gösterir. `MOV DS, AX` sonrasında alınan döküm şöyleydi (ekrandan, 01:10:00):

```text
076D:0000  02 0A 00 00 00 00 00 00-00 00 00 00 00 00 00 00
076D:0010  1E 33 C0 50 B8 6D 07 8E-D8 33 D2 33 C9 B8 01 00
076D:0020  8A 0E 01 00 33 DB 8A 1E-00 00 F7 E3 E2 FC A3 02
```

**Soru (hoca sordu):** Bu değerler ne demektir? **Bir öğrencinin cevabı:** Tanımladığımız değişkenler saklanıyor olmalı, geri kalanlar çöp değer mi? **Cevap:** Cevap doğru, ama bir nokta eksik. İlk dört byte (`02 0A 00 00`) tam olarak veri segmentinde tanımladığımız değerlerdir: 0 ofsetinde A = 02H, 1 ofsetinde B = 0AH, 2 ve 3 ofsetlerinde SONUC = 0000H. Ondan sonraki sıfırlar hizalama yüzünden kullanılmayan alandır. İkinci satır ise `1E 33 C0 ...` ile başlar: bu, kodumuzun makine kodudur.

Segmentler PARA hizalı ve peş peşe yerleştirilmiştir: önce yığın, sonra veri, sonra kod. Segment değerleri de bunu doğrular: SS en küçük, sonra DS, en büyük CS. Veri segmenti 076DH'de, kod segmenti 076EH'de başladığı için kod, veri segmentinin 10H ofsetinden itibaren görünür. Bu satırda `B8 6D 07` da dikkat çekicidir: `MOV AX, DATASG` komutu yükleme sırasında `MOV AX, 076DH` hâline gelmiştir.

> **Ek bilgi (derste anlatılmadı):** 20 bitlik fiziksel adres $\text{segment} \times 16 + \text{ofset}$ ile hesaplandığı için segment değerinin 1 artması 16 byte ilerlemek demektir. Bu yüzden 076D:0010 ile 076E:0000 aynı fiziksel adresi gösterir.

### 7.5 Etiketin dolaylı adreslemeye dönüşmesi

`T` ile devam edilince `XOR DX, DX`, `XOR CX, CX` ve `MOV AX, 1` çalıştı. Sıradaki `MOV CL, B` satırı DEBUG'da `MOV CL, [0001]` olarak görüldü (ekrandan, 01:10:00). Assembler B etiketini dolaylı adreslemeye çevirmişti.

**Soru (hoca sordu):** Kodu hiç görmeden, yalnız dökümden bakarak `MOV CL, [0001]` çalıştırılınca CL hangi değeri alır? **Cevap:** 0 ofsetinde 02H, 1 ofsetinde 0AH vardır. Komut 1 ofsetinin içeriğini alır, yani CL = 0AH olur. Trace edilince CX'in düşük anlamlı kısmına 0AH yüklendiği görüldü.

Sonra BX sıfırlandı ve BL'ye 02 atandı. Sıradaki komut `MUL BX` idi: BX ile AX çarpılır ve sonuç DX:AX'e yazılır. DX'teki eski değer ne olursa olsun üzerine yazılır. AX = 1, BX = 2 olduğu için ilk çarpımdan sonra DX:AX = 2 oldu (ekrandan, 01:15:00).

### 7.6 LOOP komutundaki görece adres

LOOP satırı LST'de `001C E2 FC` olarak görünür. E2 LOOP komutunun kodu, FC ise görece ofset değeridir. DEBUG'ın U çıktısında ise bu satır `LOOP 001A` biçimindedir.

**Soru (hoca sordu):** FC nereden geldi? **Cevap:** Hoca Windows hesap makinesini programcı modunda, byte boyutunda açtı ve FCH'nin onluk karşılığının −4 olduğunu gösterdi. −4'ün nedeni şudur: LOOP satırı 1CH ofsetindedir ve 2 byte'tır. Bu komut çalışınca IP 1EH olur. Ama gidilmek istenen yer 1AH'dir. $E = 14$, $A = 10$ olduğundan aradaki fark 4'tür. Yani 1CH'den değil, 1EH'den 1AH'ye gidilir:

$$1EH + (-4) = 1AH$$

Trace edildiğinde gerçekten 1AH'ye dönüldüğü görüldü. Makine kodundaki değer (FC) görecedir, DEBUG'ın gösterdiği `001A` ise doğrudan adrestir. `001A`, bir etiket gibi düşünülebilir.

**Soru:** Bunun işaretli sayı olduğunu nasıl anladık? LOOP'ta öyle bir özellik mi var? **Cevap:** Evet. LOOP komutu segment içindeki bir etikete dallanıyorsa buradaki değer 8 ya da 16 bitlik işaretli sayıdır. Bu, LOOP komutunun özelliğidir.

> **Ek bilgi (derste anlatılmadı):** 8086'da LOOP komutunun görece değeri her zaman 8 bitliktir (−128 ile +127 arası). Daha uzak bir etikete dönülecekse `DEC CX` ve `JNZ` ile birlikte bir JMP kullanmak gerekir.

Hoca bu kadar ince ayrıntıyı sınavda sormayacağını, ama programın nasıl çalıştığını anlamak için önemli olduğunu söyledi.

### 7.7 Sonuç ve little endian

Döngü on kez döndükten sonra AX = 0400H, DX = 0000H oldu (ekrandan, 01:20:00). Hesaplanmak istenen değer $2^{10} = 1024$ idi. 400H'de 4 rakamı 256'lar basamağındadır ve $4 \times 256 = 1024$ olduğu için sonuç doğrudur.

Döngü bittikten sonra `MOV [0002], AX` ile değer SONUC'a yazıldı. `D DS:0` ile tekrar bakılınca SONUC'un yerinde `00 04` görüldü.

**Soru (hoca sordu):** AX'te 400H vardı, bellekte neden `00 04` görünüyor? **Cevap:** 8086'da veriler little endian düzeninde saklanır. SONUC 2 ofsetinden başlayan bir word'tür. 2 ofsetinde düşük anlamlı byte (00), 3 ofsetinde yüksek anlamlı byte (04) bulunur. Yani 0400H bellekte `00 04` diye görünür.

Sonraki `RETF` trace edilince işletim sistemine dönüldü. Oradaki komutların artık bizim için bir anlamı yoktur.

### 7.8 A, U, G ve Q komutları

DEBUG parametresiz açılırsa sıradaki boş segment bize ayrılır. `A` (assemble) komutuyla bu segmentin 100H ofsetinden itibaren assembly komutları yazılabilir. Hoca örnek olarak `XOR AX, AX` ve `MOV BX, AX` yazdı, boş satırda Enter'a basarak çıktı. Ardından `D` ile 100H ofsetindeki makine kodlarına baktı ve `U` (unassemble) ile bunları komutlara geri çevirdi. İlk iki satır yazılan komutlardı. Sonraki satırlar, bellekte rastgele duran byte'ların komut gibi yorumlanmasından oluşan anlamsız komutlardı.

`G` (go) komutu kodu verilen ofsete kadar tek seferde çalıştırır. Hoca `G CS:1E` ile programı `MOV SONUC, AX` satırına kadar çalıştırdı. AX = 0400H olarak geldi (ekrandan, 01:20:00). Binlerce turluk bir döngü varsa onu adım adım beklemek gerekmez. `Q` (quit) ile DEBUG'dan çıkılır.

Hoca bu komutların yazılan kodları ayıklamak için yeterli olacağını söyledi.

## 8. EXE Tipi Programların Yapısı

Aradan sonra hoca konuyu EXE tipi programlara getirdi.

> **Hocanın vurgusu:** EXE tipi programlar sınav konularına dahildir. Dikkatle dinlenmesi gerekir.

### 8.1 Programların sınıflandırılması

Assembly dilinde programlar farklı biçimlerde sınıflandırılabilir. Kodlanma şekline göre EXE ya da COM tipi olarak düşünülebilir. Kesim (segment) tanımlarına göre de değişebilir: kesimlerin birlikte kullanıldığı, birleştirildiği ya da peş peşe eklendiği programlar gibi. EXE ve COM, derlemenin sonunda oluşan uzantıya göre ele alınan iki farklı kategoridir.

### 8.2 Çalışma akışı

Şimdilik tek bir dosyada ana program ve gerekirse yardımcı yordamlar bulunur. Bu dosya MASM ile derlenir, çıkan obje dosyası linklenir ve EXE dosyası oluşur. Bu aşamaya gelinmişse sözdizimi (syntax) hatası yok demektir. Programın mantık açısından doğru çalışıp çalışmadığı ise yazmaçlardaki değerler ve bellekte okunan, yazılan değerler DEBUG ile kontrol edilerek anlaşılır. Hoca bu aşamaların yazılan her program için pratikte denenmesi gerektiğini söyledi.

### 8.3 İskelet

Slayttaki EXE iskeleti şudur (ekrandan, 01:40:00):

```asm
STACKSG SEGMENT PARA STACK 'STACK'
        DW 32 DUP(?)
STACKSG ENDS

DATASG  SEGMENT PARA 'DATA'
SAYI    DB ?
ELEMAN  DW ?
DATASG ENDS

CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG, DS:DATASG, SS:STACKSG

BASLA   PROC FAR
        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DATASG
        MOV DS, AX

        RETF
BASLA   ENDP
CODESG  ENDS
        END BASLA
```

Hoca bu iskeleti paylaşacağını ve kodların bunun üzerinden yazılabileceğini söyledi.

### 8.4 Yığın segmenti

EXE tipi programlar en az üç segment tanımı içermelidir. Bunlardan biri yığın segmenti olarak kullanılır. Yığın olarak kullanılacak segmentin tanımında mutlaka `STACK` kelimesi geçmelidir. Tanımdaki `STACK` kelimesi ile tırnak içindeki `'STACK'` farklı şeylerdir: birincisi segmenti yığın segmenti yapan birleştirme tipidir, ikincisi sınıf adıdır ve herhangi bir ad olabilir. Segment etiketi de (STACKSG) segmentin yığın olduğunu belirlemez, sadece bir etikettir.

Segment tanımı `SEGMENT` ve `ENDS` kelimeleri arasında yapılır. Bir hizalama da bildirilmelidir: BYTE sıradaki adrese, WORD sıradaki çift adrese, PARA sıradaki 16'nın katına, PAGE 256'nın tam katına hizalar.

Yığın boyunun çift olmasına dikkat edilir. İçeriğin önemi yoktur, bu yüzden `DUP` ile soru işareti bırakılır. `DW 32 DUP(?)`, segmentin yerleştiği adresten itibaren 64 byte'ı yığın olarak ayır demektir. Yığına değerler atılıp çekileceği ve yığın başta boş kabul edildiği için içindeki rastgele değerlerin önemi yoktur, zaten üzerlerine yazılacaktır.

### 8.5 Veri segmenti

Veri segmenti de `SEGMENT` ve `ENDS` arasında tanımlanır. Burada kullanılacak değişkenler tanımlanır. Verilen her etiket bir pointer, yani bir adres olarak değerlendirilmelidir.

- Tek değişken: `SAYI DB 5` gibi. Bu hem bir pointer hem de o pointer'daki içerik olarak ele alınabilir.
- Byte dizisi: `DIZI DB 1, 2, ...` biçiminde ilk değerler virgülle ayrılarak yazılır.
- Word dizisi: `DIZI2 DW ...`.
- Double word (32 bitlik elemanlı) dizi: `DD` ile.

Bu segment veri segmenti amacıyla yazılmıştır, ama veri segmenti olduğu kod segmentinde yapılan işlemlerle kesinleşir.

### 8.6 Kod segmenti ve FAR prosedür

Programın sonunda `END` kelimesinden sonra gelen etiket bu segmentin içinde yer aldığı için burası kod segmenti olur. Program belleğe yüklenip çalıştırılınca `BASLA` etiketinden itibaren kod yürütülür.

EXE tipi programlarda ana prosedür olarak kullanılmak üzere en az bir FAR tipinde prosedür tanımlanmalıdır. Bu prosedür, `END` kelimesinden sonra gelen etiketle gösterilen prosedür olmak zorundadır. FAR prosedür olduğu için ana yordamın dönüşü `RETF` (return far) ile olmalıdır. Yığına bir segment ve bir ofset değeri atılmıştır. RETF bunları çekip işletim sistemine dönebilir.

### 8.7 Dönüş adresinin yığına yazılması

Hoca DOS özelinde konuştuğunu belirtti: DOS uyumlu programlarda işletim sistemi tarafından çağrılan program, işletim sistemine dönüş adresini yığına atmakla yükümlüdür. Linux'ta ve başka sistemlerde durum farklıdır. Parametre aktarımı için de benzer bir durum vardır: bir derleyicide parametreler AX, BX, CX sırasıyla aktarılırken GCC gibi bir derleyicide farklı yazmaçlar ve yığın bölgeleri kullanılabilir. Hangi derleyicide ve sistemde çalışılıyorsa ona özgü durum incelenmelidir.

<!-- BELİRSİZ: 01:45:53'te parametreleri AX, BX, CX sırasıyla aktardığı söylenen derleyicinin adı altyazıda "X compiler" diye bozuk geçiyor. -->

Dönüş adresi, prosedür tanımının hemen altındaki üç satırla yığına yazılır. İşletim sistemi programı belleğe yüklerken DS içine dönüş segmentini koyar, dönüş ofseti de 0'dır. Bu yüzden önce `PUSH DS` ile segment, sonra `XOR AX, AX` ve `PUSH AX` ile word olarak 0 değeri yığına atılır. Bu üç satırdan sonra dönüş değerleri yığının en üstüne, ya da tersten bakılırsa yığının en dibine yazılmış olur.

### 8.8 Veri segmentinin DS'ye yüklenmesi

Bu noktada tanımlanan segmentin veri segmenti olduğu hâlâ belli değildir. Bunu iki satır belirler: segment değeri önce AX'e, sonra DS'ye kopyalanır. Bu işlem tek komutla yapılamaz, çünkü komut kümesi DS yazmacına doğrudan sabit (immediate) değer atamaya izin vermez. DS'ye aktarım yalnız bir yazmaç üzerinden yapılabilir. Bu, tasarımdan gelen bir kısıttır.

> **Hocanın vurgusu:** DS'nin 0 ofsetini dökerek veriye bakmak ancak `MOV DS, AX` çalıştıktan sonra anlamlıdır. Bu satırdan önce DS:0 dökülürse, işletim sisteminde bizi çağıran tarafın bölgesine bakılmış olur.

### 8.9 Kodun yazılacağı yer ve RETF uyarısı

Asıl kod, `MOV DS, AX` satırından sonra `RETF` satırına kadar olan boşluğa yazılır. İşlemler bitince RETF ile dönülür.

> **Hocanın vurgusu:** Program içinde yığına fazladan bir şey atıldıysa, RETF satırına gelmeden uygun biçimde çekilmelidir. RETF'e gelindiğinde yığından çekilecek iki değer, baştaki 0 ofseti ile `PUSH DS`'den gelen segment değeri olmalıdır. Yığın temizlenmeden RETF çalışırsa program yanlış bir bölgeye döner.

RETF'ten sonra prosedür (`ENDP`) ve kod segmenti (`ENDS`) kapatılır, `END` ile program sonlandırılır.

### 8.10 Yığın boyunun seçimi ve ASSUME

Hoca örneklere geçerken iki noktaya daha değindi.

Yığın çok küçük olursa sorun çıkar: iç içe programlar ve alt yordamlar çağrıldıkça yığın kapasitesi aşılırsa yığın taşar. Yığını çok büyük tanımlamak da sorundur, çünkü kullanılmayacak boş yerler yığın olarak ayrılmış olur. Uygun bir boyut seçilmelidir.

`ASSUME` kelimesi, kodda kullanılan bir değişkenin (örneğin `MOV AX, SAYI1`) hangi segmentten geleceğini assembler'a bildirir. Derlenmiş kodda buraya sayısal bir değer geldiği görülmüştü. ASSUME ile CS, DS ve SS için hangi segmentin kastedildiği dışarıdan belirtilir. Hoca bunu C'deki `#define A 100` tanımına benzetti: derlemeden önce bir ön işlem olarak bütün A'lar 100 ile değiştirilir.

**Soru:** EXE programlarında veri segmentini MOV komutlarıyla DS'ye atıyoruz, ama stack segment ve code segment için bunu yapmıyoruz. Neden? **Cevap:** Üç segmentin her biri için durum farklıdır. Yığın segmenti tanımında `STACK` kelimesi görüldüğü için o segment yığın olarak kurulur. Kod segmenti, kodun en altındaki `END BASLA` satırındaki etiketin içinde bulunduğu segmenttir. Veri segmenti için böyle özel bir kelime yoktur. Onu veri segmenti yapan, kod segmentinde "şurada tanımladığım segmenti veri segmenti olarak kullanmak istiyorum" diyen iki MOV satırıdır.

> **Ek bilgi (derste anlatılmadı):** DOS, EXE başlığındaki bilgilere bakarak CS:IP'yi büyük olasılıkla END'den sonra verilen etikete, SS:SP'yi de STACK birleştirme tipiyle tanımlanan segmente kendisi ayarlar. DS için başlıkta böyle bir alan yoktur. Bu yüzden DS'yi programın kendisi ayarlamak zorundadır.

## 9. Örnek 1: İki 16 Bitlik Sayının 32 Bitlik Toplamı

8086'nın komut kümesindeki en geniş aritmetik işlemler 16 bitliktir. Yine de `DD` ile double word tanımlanabildiği için 32 bitlik değerlerle de çalışılabilir.

**Problem:** Bellekte saklanan iki 16 bitlik sayıyı toplayıp, taşmayı da dikkate alarak sonucu 32 bitlik bir değişkende saklayan EXE tipi programı yazınız. İki 16 bitlik sayının toplamı aslında 17. bite taşar, ama 17 bitlik bir veri tipi yoktur. Word'den sonraki tip double word'tür.

### 9.1 Veri tanımları

Hoca DOSBox'ın C olarak gördüğü klasörde yeni bir `.asm` dosyası açıp EXE şablonunu içine kopyaladı. Veri tanımları şöyle oldu (ekrandan, 02:05:00 ve 02:10:00):

```asm
STEK SEGMENT PARA STACK 'STK'
        DW 30 DUP(?)
STEK ENDS

DSG  SEGMENT PARA 'DTS'
SAYI1   DW 0ABCDH
SAYI2   DW 0CDEFH
SONUC   DD 0
DSG ENDS
```

İkinci sayı, toplamın taşmasını sağlayacak biçimde seçildi. SONUC önce `DD ?` olarak yazılmıştı, sonra kolaylık olsun diye 0 ile ilklendirildi.

**Soru:** SONUC'a `?` yerine bir sayı verip aşağıda MOV yapsak da kabul olur mu? **Cevap:** Soru işareti, o anda bellekte hangi değer varsa onu kullan demektir. Zaten üzerine yazılacağı için oraya bir değer yazılsa da bir şey fark etmez.

> **Hocanın vurgusu:** Onaltılık sayılarda en yüksek anlamlı basamak bir harfse başına mutlaka 0 konmalıdır. `0ABCDH` beş basamak gibi görünür ve beş onaltılık basamak 20 bit eder, ama bu 16 bitlik bir değerdir. Baştaki 0 değerlendirilmez, yalnız bunun bir sayı (etiket değil) olduğunu gösterir.

### 9.2 Birinci deneme: tip uyuşmazlığı

Toplama bellek üzerinde iki operandla yapılamaz. `ADD` komutunun iki operandının da bellek adresi olması mümkün değildir. Önce bir sayı yazmaca alınmalıdır. İlk denemede şu yazıldı:

```asm
MOV AL, SAYI1
ADD AL, SAYI2
```

Derlemede (dosyanın kaydedilmediği ve önce yanlış dosyanın derlendiği küçük bir aksaklıktan sonra) MASM iki satır için "Operand types must match" uyarısı verdi (ekrandan, 02:10:00). SAYI1 word tipinde tanımlandığı için tip hatası assembler tarafından otomatik anlaşılır. Doğrusu AX kullanmaktır:

```asm
MOV AX, SAYI1
ADD AX, SAYI2
```

İkinci sayıyı da `MOV BX, SAYI2` ile yazmaca alıp `ADD AX, BX` yapmak mümkündü, ama buna gerek yoktur. ADD bir yazmaç ve bir bellek adresiyle çalışabildiği için iki satır yeterlidir.

### 9.3 Sonucun düşük 16 biti: WORD PTR

Toplamın düşük 16 biti AX'tedir. Elde varsa o da CF'de oluşur. SONUC'un düşük 16 bitine AX, yüksek 16 bitine elde varsa 1, yoksa 0 yazılmalıdır.

`MOV SONUC, AX` yazılınca "Illegal size for operand" uyarısı alındı (ekrandan, 02:20:00), çünkü SONUC double word, AX ise word'tür. `MOV WORD PTR SONUC, AX` ise kabul edildi: SONUC adresinden başlayan word'e değer ata demektir.

Little endian düzeninin güzelliği burada görülür. 32 bitlik SONUC'un düşük 16 biti, aynı adresin word olarak ele alınmasıyla aynıdır.

### 9.4 Yüksek 16 bit için adres hesabı

Yüksek 16 bite erişmek için SONUC'un ofseti alınır. Ofset almak için LEA (Load Effective Address) kullanılır. Ofset sonra köşeli parantez içinde kullanılacağı için BX, SI ya da DI seçilmelidir:

```asm
LEA BX, SONUC
MOV AX, SAYI1
ADD AX, SAYI2
MOV [BX], AX
```

SONUC bir double word olsa da artık başlangıç adresi alınmıştır, bir dizi gibi düşünülebilir.

Bir öğrenci yüksek kısım için EAX'i önerdi. Hoca 8086'da AX, BX, CX olduğunu, genişletilmiş AX (EAX) olmadığını hatırlattı.

Hoca belleği dört göze bölerek çizdi (ekrandan, 02:15:00). SONUC'un başlangıç adresi örneğin 100H olsun. Sonraki gözler 101H, 102H, 103H'dir. Dört byte, $4 \times 8 = 32$ bit eder. Bu adresten 32 bitlik bir değer okunursa 100H en düşük anlamlı, 103H en yüksek anlamlı byte olur. Aynı adresten word okunursa 100H ve 101H alınır: bu, double word'ün düşük 16 bitidir. 100H'den okunan byte da hem word'ün hem double word'ün düşük anlamlı byte'ıdır.

Yüksek 16 bit 102H, yani `[BX+2]` adresindedir. Bir öğrencinin önerdiği gibi doğrudan `INC WORD PTR [BX+2]` yapılamaz: bakmadan artırılırsa elde olmayan durumda da 1 eklenmiş olur. Önce CF'ye bakılmalıdır. MOV komutları bayrakları etkilemediği için ADD'nin ürettiği CF, `MOV [BX], AX`'ten sonra da korunur.

### 9.5 İkinci çözüm: JC ve JMP

Şimdiye kadar görülen komutlarla CF'ye bakmanın yolu koşullu dallanmadır (ekrandan, 02:20:00):

```asm
        JC ELDEVAR
        JMP ELDEYOK
ELDEVAR:INC WORD PTR [BX+2]
ELDEYOK:
```

Elde varsa yüksek kısım 1 artırılır. Elde yoksa INC atlanır.

### 9.6 Bir öğrencinin önerisi: DEC ve INC

**Soru:** `JMP ELDEYOK` yerine `DEC WORD PTR [BX+2]` yazsak olur mu? Elde yoksa bir kez azaltır, ardından INC ile artırır, sonuç sıfır kalır. Elde varsa doğrudan artırır. **Cevap:** Çalışır, ama bu durumda elde olmayan kolda iki işlem (DEC ve INC), elde olan kolda bir işlem yapılır. JMP'li çözümde ise her kolda birer işlem vardır. JMP'nin maliyeti DEC ile aşağı yukarı aynıdır. Bu yüzden öneri daha maliyetlidir.

**Soru:** Değer sıfırken azaltılınca negatif bir sayıya düşüyor, bu sorun yaratır mı? **Cevap:** Hayır, hemen ardından artırıldığı için sorun olmaz.

### 9.7 Üçüncü çözüm: boş kola göre koşul

Hoca koşullu dallanmalar işlenirken öğrenilen bir kuralı hatırlattı: koşul boş kola göre yazılırsa daha pratik kod elde edilir. Bu if yapısı akış diyagramı olarak çizilirse, eldenin olmadığı durum boş kola karşılık gelir:

```asm
        JNC ELDEYOK
        INC WORD PTR [BX+2]
ELDEYOK:
```

Bir kolda sıfır, öbür kolda bir işlem vardır. Önceki çözümde her kolda birer işlem, DEC'li çözümde ise bir kolda iki işlem vardı.

Bu sürüm derlenip linklendi ve DEBUG ile çalıştırıldı. Birkaç adım trace edilip DS ayarlandıktan sonra `D DS:0` ile bakıldı: ilk dört byte `CD AB EF CD` idi, yani SAYI1 = ABCDH ve SAYI2 = CDEFH little endian düzeninde duruyordu. Ardından gelen dört byte SONUC için ayrılan yerdi. Toplama yapılınca bayrak NC'den CY'ye döndü, elde oluştuğu için artırma yapıldı. Sonra `D DS:0` ile SONUC'ta `BC 79 01 00` görüldü.

Hoca sonucu hesap makinesinde double word boyutunda doğruladı:

$$ABCDH + CDEFH = 179BCH$$

Bellekte en düşük anlamlı byte BCH, sonra 79H, sonra 01H ve en yüksek anlamlı byte 00H'dir. Toplam dört byte yer ayrılmıştır.

### 9.8 Dördüncü çözüm: ADC

Bir öğrencinin önerisiyle ADC kullanıldı. SONUC'un yüksek 16 bitinde zaten 0 vardır. ADC (add with carry) ile bu değere 0 ve CF eklenirse, elde varsa 1, yoksa 0 yazılmış olur:

```asm
LEA BX, SONUC
MOV AX, SAYI1
ADD AX, SAYI2
MOV [BX], AX
ADC WORD PTR [BX+2], 0
```

**Soru:** Bu adreste baştan bir çöp (junk) değer olma ihtimali yok mu? **Cevap:** Hocanın cevabı, oradaki değeri okumadığı, üzerine yazdığı yönündeydi.

> **Ders sonrası not:** Bu cevap MOV ile yazılan düşük 16 bit için doğrudur. ADC ise `[BX+2]`'deki değeri okuyup üzerine 0 ve CF ekler. Bu yüzden ADC'li çözümün doğru çalışması, SONUC'un `DD 0` ile sıfır olarak ilklendirilmesine bağlıdır. Hoca bunu ADC'ye geçerken "SONUC'un yüksek 16 bitinde zaten 0 var" diyerek kullandı. SONUC `DD ?` bırakılsaydı, yüksek kısımdaki rastgele değer sonuca eklenirdi. O durumda `MOV WORD PTR [BX+2], 0` ile önce sıfırlamak gerekirdi.

İlk derlemede bir hata çıktı. Hoca öğrencilerden hatayı bulmalarını istedi, düzeltip yeniden derledi.

<!-- BELİRSİZ: 02:25:53'teki derleme hatasının ne olduğu altyazıda ve karelerde görünmüyor. Büyük olasılıkla ADC satırında WORD PTR eksikti. -->

DEBUG'da LEA ile SONUC'un etkin adresi (4 ofseti) alındı, AX'e ABCDH yüklendi, SAYI2 ile toplandı ve yine elde oluştu. Düşük ve yüksek kısımlar yazılıp RETF'e gelindiğinde `D DS:0` ile yine `BC 79 01 00` görüldü.

> **Hocanın vurgusu:** Bu örnek yaklaşık beş farklı biçimde yazıldı. Amaç bunları verimli biçimde yazabilmektir. Ortada yirmi alternatif varsa en başarılı çözüm işi en verimli biçimde yapandır. Kodun doğru çalışması yetmez, en verimli biçimde yazılması da önemlidir.

## 10. Örnek 2: Dizideki Tek ve Çift Sayıları Sayma

**Problem:** 10 elemanlı bir dizide kaç tane çift ve kaç tane tek sayı olduğunu bulup veri segmentindeki ilgili değişkenlere yazan EXE tipi programı yazınız.

### 10.1 Veri tanımları

Hoca yine EXE şablonundan başladı. Veri tanımları şöyle oldu (ekrandan, 02:40:00):

```asm
DIZI DW 10, 11, 'A', 01110101B, 0E3H, 2, 3, 101, 270, 11
ELEMAN DW 10
T_SAY DW 0
C_SAY DW 0
```

Dizi word tipindedir ve elemanlar onluk, karakter, ikilik ve onaltılık biçimlerde karışık yazılmıştır. ELEMAN, eleman sayısıdır. T_SAY tek sayıların, C_SAY çift sayıların sayacıdır. Sayaçlar artırma yönünde kullanılacağı için 0 ile ilklendirildi. Program yalnız dizinin adını ve eleman sayısını bilir, içeriği çalışma sırasında değerlendirir.

**Soru (hoca sordu):** Buraya kadar yapılan tanımlarda hata var mı? **Cevap:** Yok. Ama bir değer 16 bite sığmayacak kadar büyük olsaydı (örneğin `12345678H`) hata olurdu. Hoca bunu denedi: taşan sayı yüzünden satırın devamı bir komut gibi yorumlanmaya çalışıldı ve hata alındı. `DB` ile 255'in üzerinde bir sayı yazmak da aynı sorunu çıkarır. Boyuta dikkat edilmelidir.

### 10.2 Boş döngü ve dizi erişimi

Önce dizinin bütün elemanlarını gezen boş bir döngü yazıldı. LOOP, CX yazmacı üzerinden çalışır. `MOV CX, ELEMAN` ile eleman sayısı CX'e atanır. `L1` etiketi ve `LOOP L1` ile CX kez dönülür (ekrandan, 02:35:00 ve 02:45:00):

```asm
        XOR SI, SI
        MOV CX, ELEMAN
L1:
        MOV AX, DIZI[SI]
        ADD SI, 2
        LOOP L1
```

`DIZI[SI]` gösterimi aslında `[SI + ofset]` biçimine karşılık gelir. Assembler ön işlemde DIZI'yi bir sabitle (örneğin 20H gibi bir ofsetle) değiştirir. Yani indis yazmacı ofsetle toplanır. Burada PTR gerekmez, çünkü AX kullanılmıştır ve işlemin 16 bitlik olduğu bellidir.

Bir alternatif olarak dizinin başlangıç adresi SI'ye alınabilir:

```asm
        LEA SI, DIZI
        MOV CX, ELEMAN
L1:
        MOV AX, [SI]
        ADD SI, 2
        LOOP L1
```

### 10.3 Birinci çözüm: TEST ve JZ

Sayının tek mi çift mi olduğunu anlamak için en düşük bitine bakılır. AND kullanılırsa AX bozulur. TEST ise AND işlemini yapar ama sonucu saklamaz, yalnız bayrakları ayarlar. Bu yüzden elemanı AX'e almaya bile gerek kalmadan doğrudan bellek üzerinde test edilebilir: `TEST DIZI[SI], 0001H`. Word olduğu için sabitin `0001H` diye yazılması en güzelidir.

Elemanın son biti 0 ise TEST sonucu 0 olur ve ZF = 1 olur. Bu, sayının çift olduğu anlamına gelir. Kod şu mantıkla kuruldu (ekrandan, 02:40:00):

```asm
        XOR SI, SI
        MOV CX, ELEMAN
L1:
        TEST DIZI[SI], 0001H
        JZ CIFT
        INC T_SAY
        JMP DEVAM
CIFT:   INC C_SAY
DEVAM:  ADD SI, 2
        LOOP L1
```

C_SAY ve T_SAY word olarak tanımlandığı için `INC` ile kullanılırken WORD PTR gerekmez.

> **Hocanın vurgusu:** Bir sonraki elemana geçerken `INC SI` yazmak yanlıştır. Dizi word tipindedir, her eleman için 2 byte yer ayrılır. Bu yüzden 2 adres ilerlemek gerekir: `ADD SI, 2`.

<!-- BELİRSİZ: Bu ilk çözümün tamamı tek bir karede görünmüyor. TEST ve JZ satırları 02:40:00 karesinden alındı. INC ve JMP satırlarının sırası ve DEVAM etiketinin yeri 02:37:28-02:38:09 arasındaki anlatımdan kuruldu. -->

**Soru:** İkiye bölüp kalana bakarak da yapılabilir mi? **Cevap:** O da olur. DIV ile ikiye bölündüğünde 16 bitlik bölmede kalan DX'te oluşur, onunla karşılaştırılabilir. Hoca bunların hepsinin denenebileceğini söyledi.

### 10.4 DEBUG ile izleme

Program derlenip linklendi ve DEBUG'da trace edildi. `MOV CX, ELEMAN` satırı `MOV CX, [0014]`, TEST satırı ise `TEST WORD PTR [SI+0000], 0001` olarak göründü (ekrandan, 02:40:00). TEST komutunun 6 byte'lık uzun bir komut olduğu dikkat çekti.

Değişkenlerin ofsetleri şöyledir: DIZI 10 word olduğu için 0000H–0013H aralığını kaplar. ELEMAN 14H'de, T_SAY 16H'de, C_SAY 18H'dedir. İlk eleman onluk 10'dur, çifttir, bu yüzden 18H numaralı göz (C_SAY) artırıldı. İkinci eleman 11 tektir, 16H (T_SAY) artırıldı. Sonra 'A' karakteri (41H) tek, `01110101B` ikilik sayısı tek, E3H tek, 2 çift, 3 tek, 101 tek, 270 çift ve son eleman 11 tek bulundu. Döngü bitince `D DS:0` ile 7 tek ve 3 çift eleman görüldü.

Hesap doğrulaması:

| Eleman | Değer (onaltılık) | En düşük bit | Sonuç |
|---|---|---|---|
| 10 | 000AH | 0 | çift |
| 11 | 000BH | 1 | tek |
| 'A' | 0041H | 1 | tek |
| 01110101B | 0075H | 1 | tek |
| 0E3H | 00E3H | 1 | tek |
| 2 | 0002H | 0 | çift |
| 3 | 0003H | 1 | tek |
| 101 | 0065H | 1 | tek |
| 270 | 010EH | 0 | çift |
| 11 | 000BH | 1 | tek |

### 10.5 İkinci çözüm: SHR ve ADC

Daha pratik bir yol olarak CF üzerinden çalışıldı. Eleman AX'e alınır. `SHR AX, 1` ile en düşük bit CF'ye aktarılır. CF = 1 ise sayı tektir. `ADC T_SAY, 0` ile T_SAY'a CF eklenir: sayı tekse sayaç 1 artar, çiftse değişmez. Dallanma hiç gerekmez.

```asm
        LEA SI, DIZI
        MOV CX, ELEMAN
L1:
        MOV AX, [SI]
        SHR AX, 1
        ADC T_SAY, 0
        ADD SI, 2
        LOOP L1
```

**Soru (hoca sordu):** Çift sayıların sayısı nasıl hesaplanır? **Cevap:** Toplam eleman sayısından tekler çıkarılır: $10 - T$. Döngüden sonra eleman sayısı AX'e alınıp T_SAY çıkarılır ve sonuç C_SAY'a yazılır. Hoca ADC'den sonra CF'yi tümleyip (complement) bir çift sayacına eklemeyi de düşündüğünü, ama ADC işleminin CF'yi bozacağını söyledi.

<!-- BELİRSİZ: Döngü sonrasındaki çıkarma satırları karede görünmüyor. Anlatıma göre büyük olasılıkla MOV AX, ELEMAN / SUB AX, T_SAY / MOV C_SAY, AX biçimindeydi. -->

Hoca bu kez DEBUG'da kolaylık olsun diye LST dosyasını da üretti ve `G CS:1F` ile kodu döngünün sonuna kadar tek seferde çalıştırdı. Bu noktada `D DS:0` ile T_SAY'da 7 görüldü. Sonraki adımlarda AX'te 3 kaldı ve bu değer C_SAY'a yazıldı.

> **Ders sonrası not:** 1FH ofseti büyük olasılıkla döngünün hemen sonrasına denk gelir. MASM'ın `ADC T_SAY, 0` için 5 byte'lık kısa sabitli biçimi seçtiği varsayılarak komut boyları toplanınca (PUSH DS 1, XOR 2, PUSH AX 1, MOV AX,DSG 3, MOV DS,AX 2, LEA 4, MOV CX 4, MOV AX,[SI] 2, SHR 2, ADC 5, ADD SI,2 3, LOOP 2 byte) LOOP'tan sonraki ilk komutun 1FH'de başladığı bulunur. Bu, döngünün yukarıdaki biçimde yazıldığını destekler (ara adım eklendi).

## 11. Örnek 3: Onaltılık Basamakları Ters Çevirme

**Problem:** Word tipinde bir dizinin her elemanının onaltılık gösterimindeki basamakları ters sırada yazan, yani elemanları yerinde değiştiren EXE tipi programı yazınız.

Hoca problemi önce sözlü anlattı. Veri tanımı ve beklenen sonuç şöyledir (ekrandan, 02:55:00):

```asm
DIZI DW 1234H, 2345H, 0ABCDH, 0DEDEH, 0BABAH
;DIZI : 4321H, 5432H, 0DCBAH, 0EDEDH, 0ABABH
ELEMAN DW 5
```

Elemanlar yerinde, ayrı bir değişken kullanılmadan değiştirilecektir. Hoca bir yanlış anlamayı düzeltti: birinci eleman beşinciyle, ikinci dördüncüyle yer değiştirmiyor. Elemanların yeri değişmez, her eleman kendi içinde ters çevrilir.

### 11.1 Döngü

Beş eleman olduğu için beş kez döngü kesindir. Bu kez dizinin adresi LEA ile DI'ye alındı:

```asm
        LEA DI, DIZI
        MOV CX, ELEMAN
L1:
        ...
        ADD DI, 2
        LOOP L1
```

Program yalnız dizinin başlangıç adresini ve eleman sayısını bilir. Elemanlar çalışma sırasında öğreniliyormuş gibi düşünülmelidir.

### 11.2 Denenen fikirler

- **Bütün sayıyı döndürmek:** 1234 dört bit döndürülürse 4123, bir daha 3412, bir daha 2341, bir daha 1234 olur. Basamakların sırası tersine dönmez, yalnız kayar.
- **Dört kez kaydırmak (shift):** Bir öğrenci önerdi. Değer kendi üzerinde kaydırılırsa basamaklar kaybolur. Hoca farklı bir biçimde kullanılırsa mantıklı olabileceğini söyledi.
- **String işlemleriyle yön değiştirmek:** Yön bayrağını değiştirip geriye doğru yazmak mümkün olabilir, ama çok dolambaçlıdır. Hoca yazmaçlar üzerinden bir çözüm aradığını söyledi.

### 11.3 Bir öğrencinin çözümü: byte takası ve nibble döndürme

Bir öğrenci şunu önerdi: önce AH ile AL'nin yeri değiştirilir, sonra her biri kendi içinde döndürülür. Hoca adım adım denedi (ekrandan, 03:00:00):

```text
AX = 1234H   → AH = 12H, AL = 34H
XCHG AH, AL  → AH = 34H, AL = 12H   (AX = 3412H)
AH'yi 4 bit döndür → AH = 43H
AL'yi 4 bit döndür → AL = 21H
Sonuç: AX = 4321H
```

İki byte'ı yer değiştirmek için ara yazmaç (BL) kullanmak yerine XCHG (exchange) komutu kullanıldı. Döndürme, 9 bite tamamlanan (carry üzerinden) döndürme değil, düz döndürmedir. Dört bit döndürmede yön önemli değildir.

**Soru (sohbet penceresinden):** 8 kez döndürsek olmaz mı? **Cevap:** 8 bitlik bir yazmaç 8 kez döndürülürse başlangıçtaki değere geri dönülür, bu yüzden olmaz. AH ve AL'nin ayrı ayrı 4 bit döndürülmesi gerekir.

<!-- BELİRSİZ: 03:01:29'da önerinin AX'i mi yoksa AH/AL'yi mi 8 kez döndürmek olduğu altyazıdan net değil. 16 bitlik AX 8 bit döndürülürse başlangıç değerine değil, byte'ları yer değişmiş hâline (1234H → 3412H) gelir. -->

Dış döngünün CX'ini korumak için `PUSH CX` önerisi de sohbet penceresinden geldi ve hoca bunu doğru buldu.

### 11.4 Birden fazla döndürmede CL ve CX'in korunması

Bir kez döndürmede sayı olarak 1 yazılabilir, ama birden fazla döndürmede sayının CL'de verilmesi gerekir. CX ise dış döngünün sayacıdır ve bozulmamalıdır. Çözüm `PUSH CX` ile CX'i yığına atmak, işlem bitince `POP CX` ile geri çekmektir. Kodun son hâli şudur (03:05:00 karesindeki DEBUG çıktısı ve LST'deki RETF ofseti ile doğrulandı):

```asm
        LEA DI, DIZI
        MOV CX, ELEMAN
L1:
        MOV AX, [DI]
        XCHG AH, AL
        PUSH CX
        MOV CL, 4
        ROR AH, CL
        ROR AL, CL
        POP CX
        MOV [DI], AX
        ADD DI, 2
        LOOP L1
        RETF
```

<!-- BELİRSİZ: ROR satırları ve POP CX'ten sonrası tek bir karede görünmüyor. Satırlar 03:01:55-03:02:42 anlatımından alındı. LST'de RETF'in 0024H ofsetinde olması bu sırayla tutarlıdır. -->

### 11.5 DEBUG ile izleme

Hoca LST dosyasını üretti ve `G CS:24` ile döngünün sonuna kadar çalıştırmak istedi, ama komut beklendiği gibi çalışmadı. Bunun üzerine trace ile adım adım ilerlendi (ekrandan, 03:05:00):

- `LEA DI, [0000]`: dizinin adresi alındı.
- `MOV CX, [000A]`: CX = 0005.
- `MOV AX, [DI]`: AX = 1234H.
- `XCHG AH, AL`: AX = 3412H.
- `PUSH CX`, sonra 4 kez döndürme: AX = 4321H, CX yine 5.
- Değer geri yazıldı, sonraki elemana geçildi.

`D DS:0` ile bakıldığında ilk elemanın yüksek anlamlı kısmı 43, düşük anlamlı kısmı 21, yani 4321H olmuştu. Sonraki turlarda 5432H, DCBAH, EDEDH ve ABABH elde edildi. Döngü kırıldıktan sonra `D DS:0` ile bütün elemanların değiştiği görüldü. Hoca G komutunun neden durmadığını tam bulamadı, belki 24H'yi yanlış yazdığını söyledi, ama programın doğru çalıştığı görüldü.

Python ile doğrulama: 1234H → 4321H, 2345H → 5432H, ABCDH → DCBAH, DEDEH → EDEDH, BABAH → ABABH.

## 12. Zorunlu Olmayan Alıştırmalar

Hoca ders boyunca iki alıştırma verdi:

1. 16 bitlik iki sayının toplamına benzer biçimde, 32 bitlik iki sayıyı toplayıp sonucu yeterli büyüklükte bir bellek alanında saklayan assembly kodunu yazınız.
2. İki dizi olsun. Bunlardan biri kişilerin yaşlarını (byte), öbürü gram cinsinden ağırlıklarını (word) tutsun. Aynı sıradaki göz aynı kişiye aittir: beşinci göz beşinci kişinin bilgisidir. İki diziyi uygun biçimde gezip ikisinden bilgi alarak bir hesaplama yapınız (örneğin ağırlığı yaşa bölerek bir skor). Buradaki zorluk, dizilerden biri word, öbürü byte olduğu için gezinme adımlarının farklı olmasıdır.

> **Hocanın vurgusu:** İkinci alıştırma önemli bir örnektir ve şu anki bilgilerle yapılabilmesi gerekir. Hangi komutlara ihtiyaç duyulduğunu ortaya çıkarmak için dizi işlemleri üzerine problemler üretip çözmek önerildi.

<!-- BELİRSİZ: Hoca ikinci alıştırmayı anlatırken bir yerde "birinci dizi word, ikinci dizi byte" dedi (03:07:31), sonra ağırlık dizisinin word, yaş dizisinin tek bir göz başına bir byte olduğunu söyledi (03:09:10). Not son anlatıma göre yazıldı. -->

## Örnek Sorular

### Soru 1 (derste sözlü, 00:52:03)

MASM ve LINK ile oluşturulan `deneme.exe` dosyası Windows 10'da klasörden tıklanarak çalıştırılabilir mi? Neden?

**Çözüm (derste verildi):** Hayır. Program 16 bitlik bir koddur. Günümüz işletim sistemleri ve işlemciler yalnız 32 ve 64 bitlik bellek kiplerine uygun programları çalıştırır. Program DOSBox'ın komut satırından çalıştırılır.

### Soru 2 (ekrandan, 01:10:00)

`deneme.asm` programında `MOV DS, AX` çalıştıktan sonra alınan dökümün ilk iki satırı şöyledir:

```text
076D:0000  02 0A 00 00 00 00 00 00-00 00 00 00 00 00 00 00
076D:0010  1E 33 C0 50 B8 6D 07 8E-D8 33 D2 33 C9 B8 01 00
```

Bu değerler ne anlama gelir?

**Çözüm (derste verildi):** İlk dört byte veri segmentindeki tanımlardır: A = 02H, B = 0AH, SONUC = 0000H. Sonraki sıfırlar PARA hizalaması yüzünden kullanılmayan alandır. Kod segmenti bir sonraki paragraftan başladığı için ikinci satır programın makine kodudur (`1E` = PUSH DS, `33 C0` = XOR AX, AX, `50` = PUSH AX, `B8 6D 07` = MOV AX, 076DH ...).

### Soru 3 (derste sözlü, 01:09:32)

Yukarıdaki döküme bakarak, kodu görmeden söyleyin: `MOV CL, [0001]` çalıştırılınca CL hangi değeri alır?

**Çözüm (derste verildi):** DS'nin 1 ofsetinde 0AH vardır. Komut bu ofsetin içeriğini alır: CL = 0AH.

### Soru 4 (ekrandan, 01:15:00)

LST dosyasında `001C E2 FC LOOP L1` satırı vardır ve L1 etiketi 001AH ofsetindedir. FC değeri nereden gelir?

**Çözüm (derste verildi):** FCH, 8 bitlik işaretli sayı olarak −4'tür. LOOP komutu 2 byte'tır. Çalıştıktan sonra IP = 1CH + 2 = 1EH olur. Hedef 1AH olduğu için $1AH - 1EH = -4$ eklenir. Görece değer, komutun başlangıcına değil, komuttan sonraki IP'ye göre hesaplanır.

### Soru 5 (derste sözlü, 01:16:43)

AX = 0400H iken `MOV SONUC, AX` çalıştırıldıktan sonra bellek dökümünde SONUC'un yerinde neden `04 00` değil de `00 04` görünür?

**Çözüm (derste verildi):** 8086 verileri little endian düzeninde saklar: düşük anlamlı byte (00H) düşük adrese, yüksek anlamlı byte (04H) bir sonraki adrese yazılır.

### Soru 6 (ekrandan, 00:30:00 ve 00:50:00)

`STKSG` (DW 20 DUP(?)), `DATASG` (2 byte + 1 word) ve `CODESG` segmentleri PARA hizalamasıyla tanımlanmıştır. Yığın segmentinin göreli adresi 0 ise veri ve kod segmentleri nereden başlar?

**Çözüm (derste verildi):** Yığın $20 \times 2 = 40$ byte'tır (28H). 40'tan sonraki 16'nın katı 48'dir, veri segmenti 48'de başlar. Veri segmenti 4 byte'tır ve 52'de biter. 52'den sonraki 16'nın katı 64'tür, kod segmenti 64'te başlar. Arada 8 ve 12 byte'lık kullanılmayan boşluklar kalır. DEBUG'da da SS = 076AH, DS = 076DH, CS = 076EH görülmüştür: 3 ve 1 paragraf ($48$ ve $16$ byte) fark.

### Soru 7 (ekrandan, 02:05:00 ve 02:25:00)

`SAYI1 DW 0ABCDH` ve `SAYI2 DW 0CDEFH` değerlerini toplayıp, taşmayı da dikkate alarak sonucu `SONUC DD 0` değişkenine yazan EXE tipi programın kod kısmını yazınız.

**Çözüm (derste verildi):** Derste birkaç sürüm yazıldı. En kısa olanı:

```asm
        LEA BX, SONUC
        MOV AX, SAYI1
        ADD AX, SAYI2
        MOV [BX], AX
        ADC WORD PTR [BX+2], 0
```

Dallanmalı sürüm:

```asm
        LEA BX, SONUC
        MOV AX, SAYI1
        ADD AX, SAYI2
        MOV [BX], AX
        JNC ELDEYOK
        INC WORD PTR [BX+2]
ELDEYOK:
```

$ABCDH + CDEFH = 179BCH$. Bellekte SONUC'un yerinde `BC 79 01 00` görülür. ADC'li sürüm SONUC'un 0 ile ilklendirilmesine dayanır.

### Soru 8 (ekrandan, 02:40:00)

`DIZI DW 10, 11, 'A', 01110101B, 0E3H, 2, 3, 101, 270, 11` dizisindeki tek ve çift sayıları sayıp `T_SAY` ve `C_SAY` değişkenlerine yazan EXE tipi programın kod kısmını yazınız.

**Çözüm (derste verildi):** SHR ve ADC ile dallanmasız çözüm:

```asm
        LEA SI, DIZI
        MOV CX, ELEMAN
L1:
        MOV AX, [SI]
        SHR AX, 1          ; en düşük bit CF'ye
        ADC T_SAY, 0       ; tekse sayaç +1
        ADD SI, 2          ; word dizisi: 2 byte ilerle
        LOOP L1
        MOV AX, ELEMAN
        SUB AX, T_SAY
        MOV C_SAY, AX      ; çift = eleman sayısı - tek
```

Sonuç: T_SAY = 7, C_SAY = 3. TEST ve JZ ile yazılan sürüm 10.3 bölümündedir. Son üç satır derste karede görünmedi, anlatımdan kuruldu.

### Soru 9 (ekrandan, 02:55:00 ve 03:00:00)

`DIZI DW 1234H, 2345H, 0ABCDH, 0DEDEH, 0BABAH` dizisinin her elemanının onaltılık basamaklarını yerinde ters çeviren EXE tipi programın kod kısmını yazınız. Beklenen sonuç: `4321H, 5432H, 0DCBAH, 0EDEDH, 0ABABH`.

**Çözüm (derste verildi):**

```asm
        LEA DI, DIZI
        MOV CX, ELEMAN
L1:
        MOV AX, [DI]
        XCHG AH, AL        ; 1234H -> 3412H
        PUSH CX            ; dış döngü sayacını koru
        MOV CL, 4
        ROR AH, CL         ; 34H -> 43H
        ROR AL, CL         ; 12H -> 21H
        POP CX
        MOV [DI], AX       ; 4321H
        ADD DI, 2
        LOOP L1
```

### Soru 10 (derste sözlü, 02:28:04)

32 bitlik iki sayıyı toplayıp sonucu yeterli büyüklükteki bir bellek alanında saklayan assembly kodunu yazınız (zorunlu olmayan alıştırma).

> **Çözüm (derste verilmedi):** İki 32 bitlik sayının toplamı 33 bite taşabilir, bu yüzden sonuç için 3 word (6 byte) ayrılabilir. Düşük sözcükler ADD, yüksek sözcükler ADC ile toplanır, son elde de üçüncü sözcüğe ADC ile eklenir. Derste kullanılan MASM ortamı burada bulunmadığı için kod derlenmedi, yalnız mantığı kontrol edildi.

```asm
DSG  SEGMENT PARA 'DTS'
SAYI1   DD ?
SAYI2   DD ?
SONUC   DW 3 DUP(0)
DSG ENDS
; ...
        LEA SI, SAYI1
        LEA DI, SAYI2
        LEA BX, SONUC
        MOV AX, [SI]
        ADD AX, [DI]           ; düşük sözcükler
        MOV [BX], AX
        MOV AX, [SI+2]
        ADC AX, [DI+2]         ; yüksek sözcükler + elde
        MOV [BX+2], AX
        ADC WORD PTR [BX+4], 0 ; son elde
```

### Soru 11 (derste sözlü, 03:07:31)

Bir sınıftaki kişilerin yaşları byte tipinde `YAS` dizisinde, gram cinsinden ağırlıkları word tipinde `KILO` dizisinde aynı sırayla tutulmaktadır. İki diziyi birlikte gezip her kişi için ağırlığı yaşa bölerek bir skor hesaplayınız (zorunlu olmayan alıştırma).

> **Çözüm (derste verilmedi):** Bir indis byte dizisinde 1, word dizisinde 2 ilerlemelidir. Ağırlık 65535 grama kadar çıkabildiği için bölüm 8 bite sığmayabilir. Bu yüzden 8 bitlik `DIV BL` yerine, DX sıfırlanıp 16 bitlik `DIV BX` kullanmak daha güvenlidir. Sonuç word tipinde bir SKOR dizisine yazılır. Kod derlenmedi.

```asm
        LEA SI, YAS            ; byte dizisi
        LEA DI, KILO           ; word dizisi
        LEA BX, SKOR           ; word dizisi
        MOV CX, N
L1:
        PUSH BX
        MOV AX, [DI]           ; ağırlık (gram)
        XOR DX, DX
        MOV BL, [SI]           ; yaş
        XOR BH, BH
        DIV BX                 ; AX = ağırlık / yaş
        POP BX
        MOV [BX], AX
        INC SI                 ; byte dizisi: 1 ilerle
        ADD DI, 2              ; word dizisi: 2 ilerle
        ADD BX, 2
        LOOP L1
```

## Dersin Toparlaması

Bu derste, önceki haftalarda emülatörde yazılan programların gerçek bir DOS ortamında nasıl hazırlandığı görüldü. DOSBox içinde MASM ile derleme, LINK ile EXE oluşturma ve COM programları için EXE2BIN zinciri kuruldu. LST dosyasının üç bölümü (ofset ve makine kodu, segment tablosu, sembol tablosu) incelendi. Etiketlerin görece adreslere dönüştüğü, `---- R` ile işaretlenen değerlerin ancak yüklemede belli olduğu ve PARA hizalamasının segmentler arasında boşluk bıraktığı görüldü. DEBUG'ın R, T, D, A, U, G ve Q komutlarıyla bir üs alma programı adım adım izlendi. Yığının, little endian düzeninin ve LOOP komutunun görece adresinin nasıl çalıştığı bellek dökümleri üzerinden gösterildi.

İkinci yarıda EXE tipi programların iskeleti ayrıntılı ele alındı: üç segment, STACK kelimesi, iki MOV satırıyla belirlenen veri segmenti, END etiketiyle belirlenen kod segmenti, FAR ana prosedür ve dönüş adresinin `PUSH DS` / `XOR AX, AX` / `PUSH AX` ile yığına yazılması. Ardından 32 bitlik toplama, dizide tek ve çift sayma ve onaltılık basamakları ters çevirme örnekleri birkaç farklı yolla yazıldı. Hoca bu örneklerde doğru çalışmanın yanında verimliliği öne çıkardı. Hoca, slaytta bir sonraki başlık olan COM tipi programlara ve COM programlarında yığının nasıl kullanıldığına ilerleyen derslerde döneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
