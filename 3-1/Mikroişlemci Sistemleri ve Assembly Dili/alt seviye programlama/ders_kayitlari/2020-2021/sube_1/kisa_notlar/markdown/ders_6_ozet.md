# Ders 6 Çalışma Özeti

## Genel Konular

- Önceki derslerin kısa tekrarı: adresleme modları ve sözde komutlar
  - Adresleme modları üç başlıkta toplanır: veri erişimi, program hafızası erişimi ve yığın erişimi.
  - Yığın adreslemede PUSH ve POP kullanılır, SP'yi mikroişlemci kendisi günceller.
  - Program hafızası adreslemesi CS ve IP'yi bir anda değiştiren komutlardır: JMP, koşullu dallanmalar, CALL, RET, IRET. Segment içi (intra segment) dallanmada görece değer 8 ya da 16 bitlik işaretli sayıdır. LST dosyasında etiketler bu sayısal değerlere dönüşür, örneğin `JMP 0FFH` bir byte geri dallanmak demektir.
  - Doğrudan adreslemede köşeli parantez içinde sabit bir adres, dolaylı adreslemede yazmaç ya da yazmaç + ofset bulunur. Geçerli biçimler: `[BX]`, `[SI]`, `[DI]`, `[BX+SI]`, `[BX+DI]`, `[BX+100H]`, `[BX+SI+100H]`, `[BX+DI+100H]`. Yığın erişiminde `BP` kullanılabilir.
  - Köşeli parantezde BP varsa varsayılan segment SS, BX, SI, DI ya da sabit varsa DS'dir.
  - Sözde komutların (segment, prosedür, veri ve makro tanımları, ASSUME, END) makine kodu karşılığı yoktur. Makine kodu yalnız komutlara (instruction) ve veri tanımlarına karşılık üretilir. Etiketler de birer adrestir.
- Derleme ortamı: DOSBox, MASM, LINK, EXE2BIN ve DEBUG
  - DOSBox, yolunda boşluk olmayan bir klasöre (örneğin `C:\DOSBOX`) kurulur. Araçlar bunun altındaki bir `bin` klasörüne konur.
  - DOSBox ayarlarındaki autoexec bölümünde yerel klasör `mount c c:\dosbox` ile C sürücüsü olarak bağlanır, ardından `c:` ile o sürücüye geçilir (ekrandan, 02:10:00).
  - Derleme sırası: her `.asm` dosyası `masm` ile derlenir ve `.obj` ile `.lst` oluşur. `.obj` dosyaları `link` ile birleştirilip `.exe` elde edilir. Birden çok obje dosyası `+` ile birlikte linklenir. COM tipi program yazılıyorsa oluşan EXE, EXE2BIN ile COM'a çevrilir.
  - DEBUG ile program adım adım yürütülür, yazmaçlar ve bellek izlenir, gerekirse değerleri değiştirilir.
- LST dosyasının yapısı
  - Birinci bölümde her satırın segment içindeki ofseti ve makine kodu ya da veri içeriği yer alır.
  - İkinci bölümde segmentlerin adı, uzunluğu, hizalama ve birleştirme tipi ile sınıf adı listelenir.
  - Üçüncü bölümde bütün etiket ve değişkenlerin tipi, hangi segmentte ve hangi ofsette olduğu verilir.
  - `R` işareti segment başına göre görece (relative) adres demektir. `---- R` ise adresin derleme anında belli olmadığını, program belleğe yüklenince belirleneceğini gösterir (örneğin `MOV AX, DATASG`).
- Segment hizalaması
  - BYTE sıradaki boş adres, WORD sıradaki çift adres, PARA 16'nın katı, PAGE 256'nın katı olan adresten başlatır.
  - 8086 çift adresten başlayan bir word'ü tek okuma-yazma çevriminde okur. Tek adresten başlayan word için iki çevrim gerekir. Bu yüzden hizalama hız için önemlidir.
- DEBUG komutları
  - `R` yazmaçları ve sıradaki komutu gösterir. `T` (trace) bir adım yürütür. `D` (dump) bellek bölgesini döker. `A` (assemble) komut yazdırır. `U` (unassemble) makine kodunu komutlara çevirir. `G` (go) verilen ofsete kadar çalıştırır. `Q` çıkar.
- EXE tipi programların yapısı
  - En az üç segment gerekir: yığın, veri ve kod.
  - Yığın segmentini yığın yapan, tanımdaki `STACK` birleştirme kelimesidir. Tırnak içindeki sınıf adı ve etiket önemli değildir.
  - Veri segmentini veri segmenti yapan, kod içindeki `MOV AX, DATASG` ve `MOV DS, AX` satırlarıdır.
  - Kod segmentini kod segmenti yapan, `END` kelimesinden sonra gelen etiketin o segment içinde bulunmasıdır.
  - Ana prosedür FAR olmalı ve `RETF` ile dönmelidir.
  - Programın başında `PUSH DS`, `XOR AX, AX`, `PUSH AX` ile işletim sistemine dönüş adresi (DS:0000) yığına yazılır.
- Örnekler
  - İki 16 bitlik sayının toplamını 32 bit olarak saklama (beş farklı yazımla).
  - 10 elemanlı word dizisinde tek ve çift sayıları sayma (iki yöntemle).
  - Word dizisinin her elemanının onaltılık basamaklarını yerinde ters çevirme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Etiketlerin değeri derleyici tarafından hesaplanır
  - Dallanmada ne kadar geri ya da ileri gidileceğini programcı hesaplamaz, bir etiket koyar. Assembler bu hesabı yapar ve LST dosyasında etiketler sayısal değerlere dönüşür.
  - Veri etiketleri de dolaylı adreslemeye dönüşür: `MOV CL, B` komutu `MOV CL, [0001]` olur.
- Yığın boyu çift olmalıdır
  - PUSH ve POP yalnız word ile çalışır. Yığın için ya `DW n DUP(?)` yazılır ya da `DB` ile çift sayıda byte ayrılır.
  - Yığın çok küçük olursa iç içe alt yordam çağrılarında taşar. Çok büyük olursa boşuna yer kaplar.
- EXE programı işletim sistemine dönüş adresini yığına yazmakla yükümlüdür
  - Program başladığında DS (ve ES) içinde çağıran işletim sistemi programının segment değeri vardır. Dönüş ofseti 0'dır.
  - `PUSH DS` ile segment, `XOR AX, AX` ve `PUSH AX` ile 0 ofseti yığına atılır. `RETF` önce ofseti (IP), sonra segmenti (CS) çeker.
  - Program içinde yığına atılan her şey `RETF`'ten önce çekilmelidir. Yoksa program yanlış bir yere döner.
  - `MOV DS, AX` çalışmadan önce DS'nin 0 ofsetini dökmek anlamsızdır, çünkü o anda DS hâlâ çağıran programı gösterir.
- DS'ye doğrudan sabit atanamaz
  - Komut kümesi buna izin vermez. Değer önce AX'e alınır, sonra DS'ye aktarılır.
- Little endian düzeni
  - `400H` değeri bellekte `00 04` olarak görünür: önce düşük anlamlı byte gelir.
  - Aynı adresten okunan byte, word ve double word'ün düşük anlamlı kısımları çakışır. Bu, 32 bitlik bir değişkenin düşük 16 bitine word olarak yazmayı kolaylaştırır.
- Hizalama hız demektir
  - Tek adresten başlayan word'e erişim iki çevrim sürer. Günümüz bilgisayarlarında da veri yerleşimini ve önbelleği gözeten programlar daha hızlı çalışır.
- Doğru çalışan kod yetmez, verimli kod aranır
  - Aynı örnek birçok farklı yolla yazıldı. Hoca, en az komutla ve en az dallanmayla yazılan çözümün aranması gerektiğini söyledi.
  - Koşullu dallanmada koşul boş kola göre yazılırsa daha kısa kod elde edilir.
- 16 bitlik programlar Windows'ta doğrudan çalışmaz
  - Bugünkü işletim sistemleri 32 ve 64 bitlik programları çalıştırır. 8086 programları DOSBox içinde çalıştırılır.

## Kısa Tekrar Notları

- `masm dosya.asm` → `.obj` + `.lst`; `link dosya.obj` → `.exe`; COM için ayrıca EXE2BIN.
- LST: ofset | makine kodu | kaynak satır. `R` = görece adres, `---- R` = yükleme anında belli olur.
- Sözde komut satırları ofseti ilerletmez, çünkü makine kodu üretmezler.
- Hizalama: BYTE (sıradaki), WORD (2'nin katı), PARA (16'nın katı), PAGE (256'nın katı).
- PARA hizalı segmentler arasında boşluk kalabilir. Örnek: 40 byte yığın + 4 byte veri → veri 48'de, kod 64'te başlar.
- EXE: üç segment, `STACK` kelimesi, FAR ana prosedür, `RETF`, `END <etiket>`.
- Başlangıç: `PUSH DS` / `XOR AX, AX` / `PUSH AX` / `MOV AX, DATASG` / `MOV DS, AX`.
- Başlangıçta SP yığın alanının hemen dışını gösterir (40 byte yığında SP = 0028H). PUSH önce SP'yi 2 azaltır, sonra yazar.
- DEBUG: R, T, D, A, U, G, Q.
- `LOOP` ve görece dallanmalarda değer, komuttan sonraki IP'ye eklenir: `E2 FC` → IP 1EH + (−4) = 1AH.
- Bellekten belleğe toplama yoktur. Operandlardan biri yazmaç olmalıdır.
- DD ile tanımlı bir değişkene word yazarken `WORD PTR` gerekir.
- Word dizisinde sonraki elemana geçmek için indis 2 artırılır.
- Tek/çift testi: `TEST x, 1` (operandı bozmaz) ya da `SHR AX, 1` ile en düşük biti CF'ye taşıyıp `ADC` ile saymak.
- Bir word'ün onaltılık basamaklarını ters çevirmek: `XCHG AH, AL`, sonra AH ve AL'yi ayrı ayrı 4 bit döndürmek.
- Döngü içinde CL gerekiyorsa CX `PUSH CX` / `POP CX` ile korunur.

## Detaylı Açıklamalar

Dersin ilk yarısında, önceki derslerde emülatörde görülen programların gerçek bir DOS ortamında nasıl derlendiği, linklendiği ve hata ayıklandığı gösterildi. DOSBox kurulduktan sonra ayar dosyasındaki autoexec bölümüne yerel `C:\DOSBOX` klasörünü C sürücüsü olarak bağlayan `mount c c:\dosbox` ve ardından `c:` satırları yazılır. Böylece DOSBox açılınca doğrudan bu klasöre geçilir. MASM, LINK ve DEBUG gibi araçlar bu klasörün altındaki `bin` dizinindedir. Yolda boşluk bulunursa (örneğin Program Files) DOSBox sorun çıkarabilir.

Örnek olarak bir üs alma programı (`deneme.asm`) kullanıldı (ekrandan, 00:25:00 ve 00:50:00):

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

Program AX = 1 ile başlar ve B kez A ile çarpar, yani $A^B$ hesaplar. A = 2 ve B = 10 olduğu için sonuç $2^{10} = 1024 = 400H$ olur ve SONUC değişkenine yazılır. Ekrana bir şey yazdırmadığı için sonuç DEBUG ile görülür.

`c:\bin\masm.exe deneme.asm` komutu obje ve listeleme dosyası adlarını sorar. Oluşan LST dosyasında (ekrandan, 00:30:00 ve 00:45:00) yığın segmenti 0000'dan 0028H'ye kadar uzanır. $28H = 2 \cdot 16 + 8 = 40$ byte'tır, yani 20 word. Veri segmentinde A 0. ofsette `02`, B 1. ofsette `0A`, SONUC 2. ofsette `0000` olarak görünür. Segment uzunluğu 4 byte'tır. Kod segmentinde `PUSH DS` için `1E`, `XOR AX, AX` için `33 C0`, `PUSH AX` için `50`, `MOV AX, DATASG` için `B8 ---- R`, `MOV CL, B` için `8A 0E 0001 R`, `MUL BX` için `F7 E3`, `LOOP L1` için `E2 FC`, `MOV SONUC, AX` için `A3 0002 R` ve `RETF` için `CB` üretilmiştir. Kod segmentinin uzunluğu 0022H'dir.

`PUSH DS` kodunun nereden geldiği komut kümesi tablosundan gösterildi: segment yazmacını yığına atma biçimi `000RR110` şeklindedir ve DS için RR = 11'dir. Bu yüzden kod $0001\,1110 = 1EH$ olur. Bu işlem arka planda SP'yi azaltıp veri taşıdığı için 10 saat çevrimi sürer.

Segmentler PARA ile hizalandığı için her biri 16'nın katı olan bir adresten başlar. Yığın 0'dan 40'a kadar sürer, sonraki 16'nın katı 48'dir. Veri segmenti 48'de başlar, 4 byte sonra 52'de biter. Kod segmenti de bir sonraki 16'nın katı olan 64'te başlar. Aradaki byte'lar kullanılmaz.

DEBUG'da `c:\bin\debug.exe deneme.exe` ile program yüklendi (ekrandan, 01:00:00). `R` komutunun çıktısında DS = ES = 075AH, SS = 076AH, CS = 076EH, IP = 0000 ve SP = 0028H idi. SP'nin 28H olması, yığın alanının (0–39) hemen dışını göstermesindendir. SP "sıradaki dolu gözü" gösterir gibi düşünülür: PUSH önce SP'yi 2 azaltıp 26H'ye getirir, sonra yazar. `T` ile adım adım ilerlendiğinde `MOV AX, DATASG` satırı `MOV AX, 076D` olarak görüldü ve DS bu değeri aldı. Veri segmenti gerçekten yığından hemen sonra, kod segmentinden hemen önce yerleşmişti.

`D DS:0` ile veri segmenti döküldüğünde ilk satır `02 0A 00 00 ...` idi. İkinci satır ise `1E 33 C0 50 B8 6D 07 8E D8 ...` ile başlıyordu (ekrandan, 01:05:00 ve 01:10:00). İlk dört byte tanımlı verilerdir. Hizalama yüzünden kullanılmayan byte'lardan sonra kod segmentinin makine kodu gelir.

Döngüde `LOOP L1` makine kodu `E2 FC`'dir. FCH işaretli 8 bit olarak −4'tür. LOOP komutu 1CH ofsetinde ve 2 byte'tır. Çalıştıktan sonra IP 1EH olur ve buna −4 eklenince 1AH'ye, yani `MUL BX` satırına dönülür. DEBUG'ın U çıktısında ise bu değer `LOOP 001A` diye mutlak adres gibi gösterilir. On turdan sonra AX = 0400H, DX = 0000H olur. $4 \cdot 256 = 1024$ olduğu için sonuç doğrudur (ekrandan, 01:20:00). SONUC'a yazıldıktan sonra bellekte `00 04` görülür, çünkü 8086 verileri little endian düzeninde saklar.

DEBUG parametresiz açılırsa boş bir segment ayrılır. `A` ile 100H ofsetinden itibaren komut yazılabilir, `U` ile makine kodu tekrar komutlara çevrilebilir. `G CS:1E` gibi bir komut kodu verilen ofsete kadar tek seferde çalıştırır. Bu, binlerce turluk bir döngüyü adım adım beklememek için kullanışlıdır.

Dersin ikinci yarısında EXE tipi program iskeleti slayttan anlatıldı (ekrandan, 01:40:00). En az üç segment gerekir. Yığın segmenti `STACK` kelimesiyle belirlenir. Veri segmentini kodun içindeki iki MOV satırı belirler. Kod segmentini ise `END` kelimesinden sonra gelen etiket belirler. Ana prosedür FAR olduğu için `RETF` ile döner. DOS'ta çağrılan program dönüş adresini yığına koymakla yükümlüdür. İşletim sistemi dönüş segmentini DS içinde verir, dönüş ofseti 0'dır.

Sonra üç örnek yazıldı. İlk örnekte `SAYI1 DW 0ABCDH` ve `SAYI2 DW 0CDEFH` toplanıp sonuç `SONUC DD 0` değişkenine 32 bit olarak yazıldı (ekrandan, 02:10:00). `MOV AL, SAYI1` gibi bir yazım "Operand types must match" uyarısı verdi, çünkü değişken word'tür. Bellekten belleğe toplama olmadığı için bir sayı AX'e alınıp öbürü doğrudan bellekten toplandı. Düşük 16 bit `LEA BX, SONUC` ve `MOV [BX], AX` ile yazıldı. Yüksek 16 bit için önce `JC`/`JMP` ile, sonra boş kola göre koşul yazılarak `JNC ELDEYOK` ve `INC WORD PTR [BX+2]` ile, en sonda da tek komutla `ADC WORD PTR [BX+2], 0` ile çözüldü. Sonuç $ABCDH + CDEFH = 179BCH$ olup bellekte `BC 79 01 00` diye görüldü.

İkinci örnekte 10 elemanlı word dizisindeki tek ve çift sayılar sayıldı (ekrandan, 02:40:00). İlk çözümde `TEST DIZI[SI], 0001H` ve `JZ` ile çiftler ve tekler ayrı sayıldı. İkinci çözümde `SHR AX, 1` ile en düşük bit CF'ye taşındı, `ADC T_SAY, 0` ile tekler sayıldı, çiftlerin sayısı da eleman sayısından tekler çıkarılarak bulundu. Sonuç 7 tek ve 3 çift oldu.

Üçüncü örnekte `DIZI DW 1234H, 2345H, 0ABCDH, 0DEDEH, 0BABAH` dizisinin her elemanının onaltılık basamakları yerinde ters çevrildi (ekrandan, 03:00:00). Bir öğrencinin önerisiyle `XCHG AH, AL` ile byte'lar takas edildi, sonra AH ve AL `ROR` ile ayrı ayrı 4 bit döndürüldü. Dış döngünün CX'i `PUSH CX` / `POP CX` ile korundu. Sonuç `4321H, 5432H, 0DCBAH, 0EDEDH, 0ABABH` oldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
