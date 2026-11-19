# Ders 5 Çalışma Özeti

## Genel Konular

- Dizi (string) komutlarının kısa tekrarı
  - MOVS bir bellek bölgesini başka bir bölgeye kopyalar. CMPS iki bölgeyi karşılaştırır. SCAS bellek içeriğini AL/AX ile karşılaştırır. LODS bellekteki değeri AL/AX'e yükler. STOS bellek bölgesini AL/AX değeriyle doldurur (ekrandan, 00:05:00).
  - Tekrar sayısı CX'te tutulur. REP yalnız CX'e bakar. REPE/REPZ "sonuç sıfırsa ve CX sıfır değilse", REPNE/REPNZ "sonuç sıfır değilse ve CX sıfır değilse" tekrarlar. REP, LOOP gibi düşünülebilir.
  - DF = 0 iken SI ve DI her adımda artar (byte işleminde 1, word işleminde 2), DF = 1 iken azalır.
  - CBW, AL'yi işaret genişletmesiyle AX'e; CWD, AX'i işaret genişletmesiyle DX:AX'e taşır. DX:AX işaretli bölme (IDIV) öncesinde anlamlıdır.
- Giriş-çıkış komutları: IN ve OUT
  - `IN acc, idata` 0-255 arası portlara, `IN acc, DX` 0-65535 arası portlara erişir (ekrandan, 00:15:00). Akümülatör AL (8 bit) ya da AX (16 bit) olur.
  - OUT'ta sıra terstir: önce port adresi, sonra akümülatör. Geçerli biçimler: `IN AL, 80H`, `IN AX, 80H`, `IN AL, DX`, `IN AX, DX`, `OUT 80H, AL`, `OUT 80H, AX`, `OUT DX, AL`, `OUT DX, AX`.
  - `IN AX, 80H` 80H portundan AL'ye, 81H portundan AH'ye okur.
  - 8086'nın 20 adres ucu vardır: $2^{20}$ byte = 1 MB hafıza uzayı. I/O uzayı DX'in 16 bitinden dolayı $2^{16}$ byte = 64 KB'tır (ekrandan, 00:15:00).
  - Hafızaya erişimde MOV kullanılır: `MOV [100H], AX` yazma, `MOV AX, [100H]` okumadır. I/O cihazına erişimde `IN AL, 80H` okuma, `OUT 80H, AL` yazmadır (ekrandan, 00:15:00).
  - İşlemcinin $M/\overline{IO}$ ucu MOV'da 1, IN/OUT'ta 0 olur. Bu uç adres çözümlemede kullanılırsa 1 MB hafıza ve 64 KB I/O iki ayrı uzay olur. Kullanılmazsa adresler çakışır ve tek 1 MB'lık uzay paylaşılır.
- Durdurma ve bekletme komutları
  - HLT işlemciyi durdurur; işlemci ancak bir kesme ile kaldığı komuttan devam eder (ekrandan, 00:20:00).
  - NOP hiçbir işlem yapmaz, tek byte'tır. Derlenmiş eski (legacy) bir kodda bir komutu aynı uzunlukta NOP'larla değiştirerek devre dışı bırakmak ya da bekleme döngüsü kurmak için kullanılır.
  - WAIT, işi yardımcı işlemciye (kayan nokta için 8087) devreden ana işlemcinin sonucu beklemesini sağlar.
- BCD düzenleme komutları (kısaca)
  - 77 onlu sayısının ikilik karşılığı 2'ye bölmelerle bulunur: $(77)_{10} = (01001101)_2$ (ekrandan, 00:25:00).
  - BCD'de her onlu basamak 4 bitle ayrı ayrı yazılır, çünkü en büyük basamak olan 9 dört bit ister. 87 BCD olarak `1000 0111`, 77 ise `0111 0111` olur. İkilik değerle BCD değer farklı olduğu için dönüştürme komutları gerekir.
- Adresleme modlarına giriş
  - Adresleme modları, donanımın desteklediği bellek ve I/O erişim biçimleridir. Üç grup vardır: veri adresleme, program hafızası adresleme, yığın adresleme (ekrandan, 00:30:00).
  - EXE tipi programlarda veri, yığın ve kod için üç ayrı alan, COM tipi programlarda üçünü birlikte taşıyan tek alan vardır.
- Veri adresleme modları
  - Yazmaç adresleme: `MOV BX, CX`. 8 bitte AL, AH, BL, BH, CL, CH, DL, DH; 16 bitte AX, BX, CX, DX, SP, BP, SI, DI kullanılabilir. Genişlikler uyumlu olmalıdır: `MOV AL, CL` geçerli, `MOV AX, CL` geçersizdir. `SHL AX, CL` ise veri aktarımı olmadığı için geçerlidir (ekrandan, 00:35:00).
  - Anlık (immediate) adresleme: `MOV AL, 0F2H`. Sabit onaltılık, onlu, ikilik ya da ASCII karakter olarak verilebilir. `MOV AL, 0FFFFH` geçersizdir, çünkü 16 bitlik değer 8 bitlik yazmaca sığmaz.
  - Doğrudan adresleme: köşeli parantez içinde sabit offset verilir. `MOV BX, [1234H]` BX'e DS:1234H'tan okur. `MOV AL, DATA` gibi etiketli kullanım da doğrudan adreslemedir; assembler etiketi adresle değiştirir (ekrandan, 00:40:00).
  - Fiziksel adres: DS × 10H + offset.
  - Yazmaç dolaylı adresleme: köşeli parantez içinde veri için yalnız BX, SI, DI (varsayılan segment DS), yığın için BP (varsayılan segment SS) kullanılır. `MOV AX, [DX]` geçersizdir (ekrandan, 00:45:00).
  - Örnek: DS = 0100H, BX = 1000H iken `MOV AX, [BX]` fiziksel 2000H adresine gider. 2000H'ta 12H, 2001H'te 34H olduğundan AX = 3412H olur (ekrandan, 00:45:00).
  - Tek operandlı komutlarda bellek operandının boyutu `BYTE PTR` ya da `WORD PTR` ile verilmelidir. `INC [BX]` geçersizdir. Operandlardan biri yazmaçsa boyutu yazmaç belirler ve PTR gerekmez (ekrandan, 00:50:00).
  - Taban + indis adresleme: `MOV DX, [BX+DI]`. Veri için taban yalnız BX, indis SI ya da DI'dır. Köşeli parantez içinde yalnız toplama yapılır; çıkarma ve çarpma (`[2*BX+DI]`) geçersizdir (ekrandan, 01:10:00).
  - Yazmaç göreli adresleme: `MOV AX, [BX+100H]`, adres DS × 10H + BX + 100H'tır (ekrandan, 01:30:00).
  - Taban göreli indisli adresleme: `MOV AX, [BX+SI+100H]` DS ile, `MOV AX, [BP+DI+2]` SS ile çalışır. İki boyutlu dizi (matris) erişimine uygundur.
- Program hafızası adresleme modları
  - CS ve IP'nin alacağı değeri belirler.
  - Doğrudan: `JMP 200H:300H` ile CS ← 200H, IP ← 300H olur; segmentler arası işlemdir. `CALL 200H:300H` dönüş için CS ve IP'yi yığına atar; dönüş RETF ile olur (ekrandan, 01:35:00).
  - Göreli: JMP'nin 1 ya da 2 byte işaretli operandı IP'ye eklenir. Derste: 100H'taki `JMP 100` ile IP = 100H + 100 = 164H; 200H'taki `JMP 0FFH` ile IP = 1FFH, çünkü 0FFH işaretli 8 bitte −1'dir (ekrandan, 01:40:00).
  - Dolaylı: `JMP BX` ya da `JMP [BX]`.
- Yığın adresleme
  - Yığın LIFO çalışır; geçici veri ve fonksiyon dönüş adresleri için kullanılır. PUSH her zaman bir word basar, POP bir word çeker. Adres SS:SP ile oluşur (ekrandan, 01:45:00).
  - `PUSH BL` geçersizdir. BL'yi yığına atmak için BX'in üst kısmı sıfırlanır, değer BL'ye konur, BX basılır.
  - `PUSH CS` geçerli, `POP CS` geçersizdir.
  - 100H boyutlu yığında SP 100H ile başlar. PUSH'ta SP−1 ve SP−2 adreslerine yazılır, SP 2 azalır (100H − 2 = FEH). `PUSH AX` (AX = 3412H) sonrası FEH'te 12H, FFH'te 34H olur (ekrandan, 01:50:00).
  - Yığın uzak adresten düşük adrese doğru dolar. Böylece önündeki kod ve veri alanları korunur; yığın küçük tanımlanıp taşarsa bu alanlar bozulabilir.
- Sözde komutlar (assembler direktifleri)
  - Makine kodu üretmezler. Assembler'a ön bilgi verirler, C'deki makro ön işlemesine benzerler. Gruplar: LST düzenleme (PAGE, TITLE), kesim düzenleme (SEGMENT/ENDS, ORG, ASSUME), veri tanımlama (DB, DW, DD, DQ, EQU, DUP, TYPEDEF, PTR, LABEL), yordam düzenleme (PROC/ENDP, EXTRN, PUBLIC), makro düzenleme (MACRO/ENDM, INCLUDE, LOCAL), diğer (LENGTH, TYPE, SIZE, OFFSET, SEG, END) (ekrandan, 02:10:00).
  - LST dosyası assembly kodunu, offsetleri ve makine kodu karşılıklarını birlikte gösterir. `PAGE 60,80` sayfa başına satır ve sütun sayısını, TITLE başlığı belirler (ekrandan, 02:05:00).
  - SEGMENT/ENDS kesimi tanımlar. STACK kelimesi kesimi yığın yapar. END'den sonra gelen etiketin bulunduğu kesim kod kesimidir ve yürütme o etiketten başlar.
  - ASSUME, CS, DS ve SS için hangi kesimlerin kullanılacağını assembler'a bildirir. EXE'de üç ayrı kesim, COM'da tek kesim vardır.
  - COM programları kendi kesiminin 100H adresinden başlar, öncesi başlık (header) içindir. Bunun için `ORG 100H` yazılır.
  - EXE programında kod kesiminde FAR tipinde bir ana prosedür (`BASLA PROC FAR ... BASLA ENDP`) bulunmalıdır.
  - EXTRN başka dosyadaki fonksiyon ya da değişkeni kullanmayı, PUBLIC başka dosyaya açmayı sağlar. Dosyalar ayrı ayrı .OBJ'ye derlenir, sonra birlikte bağlanır (link).
  - MACRO/ENDM: makro her çağrıldığı yere kopyalanır (kod büyür, çağırma yükü yok). Prosedür bir kez tanımlanır, çağırma yükü (yığın, dönüş) vardır. INCLUDE dosya içeriğini olduğu gibi ekler. LOCAL makrodaki etiketlerin her çağrıda tekil olmasını sağlar.
  - Hizalama: BYTE sıradaki adres, WORD sıradaki çift adres, PARA 16'nın katı, PAGE 256'nın katı. Birleştirme: PUBLIC aynı isimli kesimleri peş peşe, COMMON aynı adresten başlatır; AT kesim adresini belirler (ekrandan, 02:35:00).
  - DB 8 bit, DW 16 bit, DD 32 bit, DQ 64 bit yer ayırır. Harfle başlayan onaltılık sayının başına 0 konur; bu 0 boyutu büyütmez.
  - 8086 little endian çalışır: çok byte'lı verinin düşük anlamlı byte'ı düşük adrese yazılır. `Dizi DW 5, 10, 20` bellekte 05H 00H 0AH 00H 14H 00H olur; `A DD 12345678H` 78H 56H 34H 12H olarak yerleşir (ekrandan, 02:40:00).
  - EQU, C'deki `#define` gibi etiketi sayısal değerle değiştirir. DUP tekrarlı tanım yapar; `?` başlangıç değeri verilmediğini gösterir.
  - LABEL aynı veriye farklı tiple erişim sağlar. `Yenib LABEL BYTE` ile `Sayiw DW 2535H`'in düşük byte'ı (35H), `Yeniw LABEL WORD` ile ardışık 45H ve 55H byte'ları 5545H word'ü olarak okunur (ekrandan, 02:45:00).
  - LENGTH DUP sayısını, TYPE eleman boyutunu, SIZE = LENGTH × TYPE toplam boyutu verir. OFFSET assembler zamanında sabit üretir; LEA ise çalışma zamanında çalışan bir komuttur. SEG etiketin kesim değerini verir.
- Geliştirme ortamı (soru-cevap)
  - Derste kullanılan Microsoft Macro Assembler 5.10, 16 bitlik bir assembler'dır ve DOSBox içinde çalıştırılır. Güncel 64 bitlik sistemlerde doğrudan çalışmaz.
  - Hangi sözdizimini kullanacağınız assembler'a bağlıdır: MASM, NASM ve Linux'taki farklı sözdizimli assembler'lar vardır. 32 bitte yazmaçlar ESI, EDI, EBX gibi genişletilmiş adlar alır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Komutların geçerli biçimleri için instruction set yanınızda olsun
  - Hoca, kod yazarken hangi operand biçimlerinin geçerli olduğunu mutlaka komut tablosundan kontrol etmeyi istedi.
- Köşeli parantez içinde hangi yazmaçlar olabilir
  - Veri erişiminde yalnız BX, SI, DI; yığın için BP. `MOV AX, [DX]` kesinlikle geçersizdir. İçeride yalnız toplama yapılır.
- PTR zorunluluğu
  - Tek operandlı bellek işlemlerinde boyut BYTE PTR ya da WORD PTR ile açıkça verilir. Assembler'ın varsayılanına güvenilmez.
- Word dizilerde indis 2 artırılır
  - Word dizide `INC SI` yazılırsa iki komşu elemanın byte'ları karışır ve yanlış değer okunur. `ADD SI, 2` kullanılmalıdır. Hoca bunun çok karışan bir durum olduğunu söyledi.
- Mod adlarını ezberlemekten çok geçerliliği bilmek önemli
  - Hoca, bir adresleme biçimi görüldüğünde geçerli olup olmadığını söyleyebilmenin, modun adını bilmekten daha önemli olduğunu söyledi.
- Sözde komutlar makine kodu üretmez
  - LST dosyasında SEGMENT, ENDS, PROC, ENDP, END ve DW gibi satırlar için offset artmaz; yalnız veri değerleri ve gerçek komutlar yer kaplar.

## Kısa Tekrar Notları

- IN/OUT: 8 bitlik port doğrudan, daha büyük port DX ile verilir. OUT'ta önce port, sonra akümülatör yazılır.
- 8086: hafıza uzayı 1 MB ($2^{20}$), I/O uzayı 64 KB ($2^{16}$). $M/\overline{IO}$ ucu iki uzayı ayırır.
- HLT kesmeyle kırılır, NOP tek byte'tır, WAIT yardımcı işlemciyi bekler.
- Veri adresleme: yazmaç, anlık, doğrudan, yazmaç dolaylı, taban + indis, yazmaç göreli, taban göreli indisli.
- BX/SI/DI → DS, BP → SS.
- Yazmaç adreslemede genişlikler uyumlu olmalıdır.
- Word dizide bir sonraki eleman için adres 2 artırılır.
- Byte değişkeni 16 bitlik yazmaca almak için: `XOR CX, CX` ve `MOV CL, ndizi1`.
- Program adresleme: doğrudan (CS:IP birlikte), göreli (IP'ye işaretli ekleme), dolaylı (yazmaç ya da bellek).
- PUSH/POP her zaman word'dür. SP push'ta 2 azalır, pop'ta 2 artar. `POP CS` yoktur.
- Sözde komutlar makine kodu üretmez. EXE: 3 kesim, FAR ana prosedür; COM: tek kesim, `ORG 100H`.
- Little endian: düşük byte düşük adrese.
- LENGTH, TYPE, SIZE DUP tanımıyla ilgilidir; SIZE = LENGTH × TYPE.

## Detaylı Açıklamalar

- IN ve OUT neden ayrı komutlardır?
  - Hafıza erişimi MOV ile, I/O erişimi IN/OUT ile yapılır. İşlemci hangisinin çalıştığını $M/\overline{IO}$ ucuyla dışarı bildirir: MOV'da uç 1, IN/OUT'ta 0 olur. Adres çözümleme devresi bu ucu kullanırsa MOV'daki 0 adresi ile IN'deki 0 portu farklı cihazlara gider. Böylece 1 MB'lık hafıza uzayı ile 64 KB'lık I/O uzayı ayrı olur. Uç kullanılmazsa iki adres aynı yere düşer ve 1 MB'ın bir kısmı I/O'ya ayrılır.
- Yazmaç dolaylı adreslemeyle dizi dolaşma (ekrandan, 00:55:00, 01:00:00 ve 01:05:00)
  - Veri alanında şu tanımlar yapıldı:

    ```asm
    dizi1  db 1,2,3,4,5,6
    ndizi1 db 6
    dizi2  dw 1000H, 1001H, 1002H, 1003H
    ndizi2 dw 3
    ```

  - Dizi1'in elemanlarını sırayla AL'ye okuyan ilk kod `MOV CX, ndizi1`, `LEA BX, dizi1`, `L1: MOV AL, [BX]`, `INC BX`, `LOOP L1` idi. Değişkenin offsetini almak için LEA kullanıldı. Hata `MOV CX, ndizi1` satırındaydı: CX 16 bitlik, ndizi1 ise byte olarak tanımlıdır. Tanımı değiştirmeden düzeltme şöyledir:

    ```asm
        XOR CX, CX
        MOV CL, ndizi1
        LEA BX, dizi1
    L1: MOV AL, [BX]
        INC BX
        LOOP L1
    ```

  - `MOV AL, [BX]` satırında uyumsuzluk yoktur. BX bir adres gösterir ve oradan bir byte AL'ye alınır. Uyumsuzluk iki operand da saf yazmaç olduğunda önemlidir.
  - Dizi2 için `MOV CX, ndizi2`, `LEA SI, dizi2`, `L1: MOV AX, [SI]` yazıldı. Bellekte dizi2 `00 10 01 10 02 10 03 10` diye yerleşir. `INC SI` kullanılırsa ikinci okumada SI'nın gösterdiği 10H ve 01H byte'ları 0110H olarak okunur. Dizide böyle bir eleman yoktur. Doğrusu `ADD SI, 2` kullanmaktır; o zaman ikinci okuma 1001H olur.

    > **Ders sonrası not:** Ekrandaki tanımda dizi2'nin 4 elemanı (1000H-1003H) var, ama `ndizi2 dw 3` yazıldı. Hoca da "3 tane değişken" dedi. Bütün elemanları dolaşmak için ndizi2'nin 4 olması gerekir.

- Göreli JMP'de işaretli yer değiştirme
  - JMP'nin 8 bitlik operandı işaretli kabul edilir. 0FFH = `1111 1111` sayısının en yüksek biti 1'dir, yani sayı negatiftir; ikiye tümleyeni alınınca büyüklüğü 1 çıkar. Bu yüzden 200H'taki `JMP 0FFH` IP'yi 1 azaltır ve 1FFH'a gider.

  > **Ders sonrası not:** Hoca yer değiştirmeyi JMP komutunun kendi adresine ekledi (100H + 100 = 164H). Gerçek 8086'da yer değiştirme, JMP'den sonraki komutun adresine (JMP'nin uzunluğu eklenmiş IP'ye) eklenir. MASM'de `JMP 100` gibi bir yazımda assembler sayıyı büyük olasılıkla hedef adres sayar ve yer değiştirmeyi kendisi hesaplar.

- Yığın işleyişi
  - 100H byte'lık bir yığında SP 100H ile başlar. İlk PUSH değeri FFH ve FEH gözlerine yazar, SP FEH olur. SP o anda dolu olan son gözü gösterir. Hoca anlatımda önce SP'nin FEH ile başladığını söyledi, sonra bunu düzeltti.
  - EXE programında yığın boyutu çift olmalıdır, çünkü PUSH/POP word ile çalışır. DW ile tanımlanırsa boyut kendiliğinden çift olur; DB ile tanımlanırsa sayı çift seçilmelidir.

  > **Ders sonrası not:** Slaytta "Her POP işleminde SP+1 ve SP+2 adreslerinden 2 byte veri okunur" yazıyor (ekrandan, 01:50:00). Doğrusu, POP'un SP ve SP+1 adreslerinden okuması, sonra SP'yi 2 artırmasıdır. PUSH için slayttaki SP−1 ve SP−2 ifadesi doğrudur.

- LST dosyasından sözde komutların etkisi (ekrandan, 02:15:00)
  - TOPLA16 örneğinde `ASAYI DW 0F00H` 0000 offsetinde (0000'da 00H, 0001'de 0FH), `BSAYI DW 0AF01H` 0002 offsetinde (0002'de 01H, 0003'te AFH), `SONUC DD 0` 0004 offsetinde dört byte yer kaplar ve kesim 0008'de biter. `0AF01H`'nin başındaki 0, etiketle karışmasın diye yazılır; veri yine 2 byte'tır.
  - `STEK SEGMENT PARA STACK 'STK'` içindeki `DW 30 DUP(?)` 30 word = 60 byte yer ayırır; LST'de kesim boyutu 003CH (= 60) görünür.
  - Kod kesiminde `BASLA PROC FAR` satırı yer kaplamaz; ilk makine kodu `PUSH DS` (1EH) ile 0000 offsetinden başlar. Başka bir LST'de `MOV AX, DATASG` satırı `B8 ---- R` biçiminde, yani yükleme sırasında belirlenecek bir değerle görülür (ekrandan, 01:55:00).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
