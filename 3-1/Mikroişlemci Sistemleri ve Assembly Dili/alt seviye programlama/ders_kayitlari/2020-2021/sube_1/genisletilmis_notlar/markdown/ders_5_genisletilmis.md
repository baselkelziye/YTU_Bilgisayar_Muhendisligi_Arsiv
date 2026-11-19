# Ders 5 Genişletilmiş Notu: Giriş-Çıkış Komutları, Adresleme Modları ve Sözde Komutlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Dizi (String) Komutları
- 2. Giriş-Çıkış Komutları: IN ve OUT
- 3. Durdurma ve Bekletme Komutları
- 4. BCD Düzenleme Komutları
- 5. Komut Kümesinin Toparlanması
- 6. Adresleme Modlarına Giriş
- 7. Veri Adresleme Modları
- 8. Yazmaç Dolaylı Adreslemeyle Dizi Dolaşma
- 9. Taban, İndis ve Göreli Adresleme
- 10. Program Hafızası Adresleme Modları
- 11. Yığın Adresleme Modları
- 12. Sözde Komutlar ve LST Dosyası
- 13. Kesim Tanımları: SEGMENT, ASSUME, END, ORG
- 14. Veri Tanımlama Sözde Komutları
- 15. Yordamlar, EXTRN/PUBLIC ve Makrolar
- 16. Sözde Komutların Ayrıntıları
- 17. Geliştirme Ortamı Üzerine Sorular
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Dizi (String) Komutları

Hoca derse, geçen hafta en son işlenen dizi (string) komutlarını hatırlatarak başladı. Bu komutların hem byte (8 bit) hem de word (16 bit) çalışan sürümleri vardır. Hepsi tekrarlanabilen komutlardır ve tekrar sayısı CX yazmacında tutulur.

Tekrarı yöneten önekler üç gruptur:

- **REP:** Yalnız CX'e bakar; CX sıfır olana kadar tekrarlar.
- **REPE / REPZ:** İşlem sonucu sıfırsa (eşitse) ve CX henüz sıfır olmadıysa tekrarlar.
- **REPNE / REPNZ:** İşlem sonucu sıfır değilse ve CX henüz sıfır olmadıysa tekrarlar. İki ad aynı anlama gelir.

Her önekten geçişte CX bir azalır. Hoca, REP öneklerinin LOOP gibi düşünülebileceğini hatırlattı: REP, LOOP'a; REPE, LOOPZ'ye; REPNE, LOOPNZ'ye karşılık gelir.

Dizi komutları bir adres bölgesinden ötekine taşıma, kopyalama ve karşılaştırma işleri için kullanılır. Kaynak SI ile, hedef DI ile gösterilir. Her adımda SI ve DI'nin artırılıp azaltılacağını yön bayrağı DF belirler. SI ve DI dizilerin başını gösteriyorsa DF = 0 seçilir ve her adımda byte işleminde 1, word işleminde 2 artarlar. Dizilerin sonunu gösteriyorlarsa DF = 1 seçilir ve aynı miktarda azalırlar.

Komutların işlevleri (ekrandan, 00:05:00):

- **MOVS:** Bir bellek bölgesini başka bir bellek bölgesine kopyalar.
- **CMPS:** İki bellek bölgesinin içeriğini byte byte ya da word word karşılaştırır.
- **SCAS:** Bellek bölgesinin içeriğini byte ise AL ile, word ise AX ile karşılaştırır.
- **LODS:** Bellekteki değeri AL ya da AX'e yükler.
- **STOS:** Bellek bölgesini AL ya da AX'teki değerle doldurur.
- **CBW:** AL'deki değeri işaret bitini koruyarak (sign extension) AX'e genişletir.
- **CWD:** AX'teki değeri işaret bitini koruyarak DX ve AX'ten oluşan 32 bitlik sanal yazmaca genişletir.

DX:AX'te değer biriktirmek, örneğin işaretli bölme (IDIV) gibi komutlardan önce anlamlıdır.

## 2. Giriş-Çıkış Komutları: IN ve OUT

### 2.1 IN komutu

Giriş-çıkış için iki komut vardır: IN ve OUT. IN, bir port adresinden değer okur (ekrandan, 00:15:00). Okuma her zaman bir akümülatöre yapılır: 8 bitlik işlemde AL, 16 bitlik işlemde AX.

Port adresi iki biçimde verilir:

- `IN acc, idata`: Port adresi 8 bite sığıyorsa doğrudan anlık (immediate) değer olarak verilir. Bu yolla 0-255 arası portlara erişilir.
- `IN acc, DX`: Port adresi 8 bite sığmıyorsa önce 16 bitlik DX yazmacına konur. Bu yolla 0-65535 arası portlara erişilir.

Okunan verinin genişliği port adresinin büyüklüğünden bağımsızdır; uzak bir porttan da 8 bitlik değer okunabilir.

### 2.2 Hafıza uzayı ve I/O uzayı

Hoca burada öğrencilere ilk derslerden bir soru sordu: 20 adres ucu olan 8086 toplam ne kadar hafızayı adresleyebilir? Her adres ucu 0 ya da 1 olabildiğine göre $2^{20}$ farklı hafıza gözü adreslenir. Her göz bir byte genişliğinde olduğundan bu $2^{20}$ byte, yani 1 MB eder (ekrandan, 00:15:00). Hoca bu arada birimleri de hatırlattı: $2^{10}$ kilo, $2^{20}$ mega, $2^{30}$ giga.

Ardından hafızaya hangi komutla erişildiğini sordu. Cevap MOV'du. Hafızadan okumak da yazmak da MOV ile yapılır (ekrandan, 00:15:00):

```asm
MOV [100H], AX   ; hafızaya yazma (WR)
MOV AX, [100H]   ; hafızadan okuma (RD)
IN  AL, 80H      ; I/O cihazından okuma (I/O RD)
OUT 80H, AL      ; I/O cihazına yazma (I/O WR)
```

İkinci soru 8086'nın I/O uzayının genişliğiydi. Bir öğrencinin verdiği 64 KB cevabı doğruydu. Büyük port adresleri DX üzerinden verildiği için 16 bitle $2^{16}$ byte, yani 64 KB adreslenebilir (ekrandan, 00:15:00).

### 2.3 M/IO ucu: neden iki ayrı komut grubu?

Hafıza işlemleri için MOV'u, I/O işlemleri için IN ve OUT'u ayırmanın anlamı işlemcinin fiziksel bir ucundan gelir. Bu uç $M/\overline{IO}$ ucudur. IO kısmının üzerindeki çizgi, o durumun 0 ile ifade edildiğini gösterir. İşlemci MOV çalıştırdığında (hafıza işlemi) bu uçta lojik 1, IN ya da OUT çalıştırdığında lojik 0 oluşturur.

Bu uç, hangi hafıza elemanına ya da I/O cihazına erişileceğini belirleyen adres çözümleme mantığında kullanılırsa I/O adresleri ile hafıza adresleri birbirinden ayrılır. Elde 64 KB'lık bir I/O uzayı ve 1 MB'lık bir hafıza uzayı, iki ayrı uzay olarak bulunur. Uç adres çözümlemede kullanılmazsa MOV'daki 0 adresi ile IN'deki 0 port adresi çakışır. O zaman tek bir 1 MB'lık uzay vardır; bir kısmı I/O için, geri kalanı hafıza için ayrılır.

### 2.4 OUT komutu ve bütün geçerli biçimler

OUT bir port adresine değer yazar. Mantık aynıdır, yalnız sıra terstir: önce port adresi, sonra akümülatör yazılır. Adres 8 bite sığıyorsa anlık değer olarak, sığmıyorsa DX ile verilir.

Hoca IN ve OUT'un alabileceği bütün biçimleri ekrana yazdı. Yazarken önce yanlış sırayla yazdığını fark edip düzeltti. Doğru biçimler şunlardır:

```asm
IN  AL, 80H
IN  AX, 80H
IN  AL, DX
IN  AX, DX
OUT 80H, AL
OUT 80H, AX
OUT DX, AL
OUT DX, AX
```

`IN AX, 80H` komutu 80H portundaki değeri AL'ye, 81H portundaki değeri AH'ye okur. Hocaya göre IN ve OUT'un bunlar dışında bir biçimi yoktur.

## 3. Durdurma ve Bekletme Komutları

Bu grupta üç komut vardır (ekrandan, 00:20:00):

- **HLT (halt):** İşlemci kendini durdurur. Kaldığı komuttan devam edebilmesi için dışarıdan bir kesme gelmesi gerekir. Hoca, HLT'yi denerseniz ancak bir kesmeyle kırılabileceğini bilmeniz gerektiğini söyledi.
- **NOP (no operation):** Operand almayan, hiçbir işlem yapmayan komuttur. Makine kodu tek byte'tır. Elimizde yalnız derlenmiş hali olan eski (legacy) bir kod varsa, onu incelerken belirli dallanma ya da koşul komutlarını NOP ile değiştirerek devre dışı bırakabiliriz. Tek byte olması burada işe yarar: 3 byte'lık bir komut 3 tane NOP ile tamamen silinebilir. Ayrıca boş döngülerle belirli bir süre beklemek için de kullanılabilir.
- **WAIT (wait until not busy):** Sistemde birden fazla işlemci varken kullanılır. 8086'da kayan noktalı (floating point) işlemler tanımlı değildir; bunlar için yardımcı 8087 işlemcisi kullanılır. Ana işlemci işi yardımcı işlemciye devreder, sonra WAIT çalıştırır ve sonuç belli olana kadar beklemede kalır.

## 4. BCD Düzenleme Komutları

Hoca BCD komutlarının üzerinde fazla durmayacağını, öteki grupta da durulmadığını söyledi. Bu komutların amacı, ikilik (binary) olarak saklanan bir değerle BCD olarak saklanan bir değer arasındaki farkı gidermektir. Farkı göstermek için bir sayının iki biçimde yazılışını karşılaştırdı.

### 4.1 77'nin ikilik karşılığı

77 onlu sayısı ikiye bölüne bölüne ikiliğe çevrilir (ekrandan, 00:25:00):

| Bölünen | Bölüm | Kalan |
|---|---|---|
| 77 | 38 | 1 |
| 38 | 19 | 0 |
| 19 | 9 | 1 |
| 9 | 4 | 1 |
| 4 | 2 | 0 |
| 2 | 1 | 0 |

Son bölüm 1, en yüksek anlamlı bittir. Bitler en yüksek bölümden başlayarak kalanlar aşağıdan yukarı okunarak yazılır: `1001101`. 8 bite tamamlamak için başa 0 eklenir:

$$(77)_{10} = (01001101)_2$$

Hoca hesap sırasında 38'in kalanını önce 1 yazdı, ekranda 0 olarak düzeltti; sonucu birlikte kontrol ettiler. Python ile doğrulandı: $64 + 8 + 4 + 1 = 77$.

### 4.2 Aynı sayının BCD karşılığı

BCD'de (binary coded decimal) her onlu basamak ayrı ayrı ikilik olarak kodlanır. Bir basamak 0-9 arası değer alır; en büyüğü olan 9'u yazmak için 4 bit gerekir. Bu yüzden her BCD basamağı 4 ikilik basamaktan oluşur.

Hoca örneği biraz farklılaştırmak için 87 ile gösterdi: 8 → `1000`, 7 → `0111`, yani 87 BCD olarak `1000 0111` olur. 77 ise BCD olarak `0111 0111` yazılır. Bu, 77'nin ikilik karşılığı `0100 1101` ile aynı değildir. Bölme gibi işlemlerden önce ya da sonra BCD ile ikilik arasında dönüşüm gerektiği için bu komutlara ihtiyaç vardır. Hoca konuyu burada bıraktı ve öğrencilerin komutlara kendilerinin bakmasını istedi.

Slaytta AAA (ASCII adjust after addition) için bir örnek de duruyordu: "ASCII değer olarak tutulan iki sayının toplamını BCD olarak düzenler" (ekrandan, 00:25:00). Bu örnek derste sözlü olarak anlatılmadı:

```asm
XOR AX, AX
MOV AL, "6"
ADD AL, "7"
AAA          ; AX <- 0103H, BCD olarak 13 sayısı
```

> **Ek bilgi (derste anlatılmadı):** '6' karakterinin ASCII kodu 36H, '7'nin kodu 37H'tir; toplamları 6DH olur. Düşük yarım byte (D) 9'dan büyük olduğu için AAA, AL'ye 6 ekler, üst yarım byte'ı temizler ve AH'yi bir artırır. Sonuç AH = 01H, AL = 03H, yani 6 + 7 = 13'ün basamakları ayrı ayrı (unpacked BCD) olur.

## 5. Komut Kümesinin Toparlanması

Bu noktayla birlikte 8086 komut kümesinin bütün grupları görülmüş oldu: veri aktarım, aritmetik, lojik, öteleme-döndürme, dizi, giriş-çıkış, bekleme-durdurma komutları.

> **Hocanın vurgusu:** Kod yazarken mutlaka yanınızda bir instruction set bulundurun. Hangi komutun hangi operandlarla geçerli olduğunu ondan kontrol ederek yazın.

## 6. Adresleme Modlarına Giriş

Sonraki konu adresleme modlarıdır. Bunlara komutları işlerken kabaca değinilmişti; şimdi daha düzenli biçimde verildi. Adresleme modları donanımın desteklediği hafıza erişim biçimleri olarak düşünülebilir. Bir işlemcinin belirli bir adresleme modunu desteklemesi isteniyorsa bunun donanımı da tasarıma katılmalıdır. Kısacası adresleme modları, assembly komutlarıyla hafızaya ve I/O'ya nasıl erişildiğini belirleyen kurallar bütünüdür.

Slayta göre verimli assembly programları yazmak için adresleme modlarını bilmek gerekir. Üç tip erişim için adresleme modu vardır (ekrandan, 00:30:00):

- Veri adresleme modları
- Program hafızası adresleme modları
- Yığın adresleme modları

Bu üçlü, program tiplerindeki alanlarla da ilişkilidir. EXE tipi programlarda üç ayrı alan tanımlanır: veri alanı, yığın alanı ve kod alanı. COM tipi programlarda tek bir alan vardır ve bu alan hem veri, hem kod, hem de yığın alanı işlevini görür. Her iki tipte de bu üçlü yapı vardır.

İki operandlı komutların genel kalıbı `mnemonik hedef, kaynak` biçimindedir. Hedef ve kaynak işleme girer, sonuç hedefte saklanır. Veri aktarım komutlarında ise kaynaktaki değer hedefe kopyalanır. Örneğin AX = 1234H ve BX = 0ABCDH iken `MOV AX, BX` çalışınca BX'teki değer AX'e kopyalanır; BX bozulmaz, yalnız AX değişir. Bundan sonra bu aktarım, hedefe doğru bakan bir okla (`hedef ← kaynak`) gösterilir.

## 7. Veri Adresleme Modları

### 7.1 Yazmaç adresleme (register addressing)

Veri aktarımı yazmaçtan yazmaca yapılıyorsa bu yazmaç adreslemedir. Komut tablosundaki makine kodlarına bakınca her yazmacın kendine özgü bir kodu olduğu görülür. 16 bitlik işlemlerde her 16 bitlik yazmacın, 8 bitlik işlemlerde her 8 bitlik yazmacın ayrı kodu vardır. İşlemci komutun makine kodunu aldığında önce bunun bir yazmaç adresleme komutu olduğunu anlar; sonra işlem boyutunu (8 ya da 16 bit) belirten alana, ardından hangi yazmacın hedef, hangisinin kaynak olduğunu veren ikilik kodlara bakar ve işlemi yürütür.

Kullanılabilecek yazmaçlar (ekrandan, 00:35:00):

- 8 bit: AL, AH, BL, BH, CL, CH, DL, DH. Bunlar dışında 8 bitlik bir yazmaç adreslenemez.
- 16 bit: AX, BX, CX, DX, SP, BP, SI, DI.

Özel bazı durumlarda segment yazmaçlarına da değer aktarılabildiği hatırlatıldı.

> **Hocanın vurgusu:** Yazmaç adreslemede kullanılan yazmaçların genişlikleri uyumlu olmalıdır. Bu kurala özellikle veri aktarım komutlarında dikkat edin.

Ekrandaki örnekler (ekrandan, 00:35:00): `MOV AX, CX` ve `MOV AL, CL` geçerlidir, `MOV AX, CL` geçersizdir. Buna karşın `SHL AX, CL` geçerlidir. Bu bir istisna gibi görünür ama SHL bir veri aktarım komutu değildir; CL burada yalnız öteleme sayısını verir. `MOV BX, CX` komutunun anlamı "BX'e CX içeriğini ata" diye yorumlanır.

### 7.2 Anlık adresleme (immediate addressing)

Anlık adreslemede kaynak sabit bir değerdir. Burada da birinci operand ile sabitin genişliği uyumlu olmalıdır. `MOV AL, 0F2H` çalışınca AL'ye F2H atanır. Sabit onaltılık olarak verilebileceği gibi onlu, ikilik (örneğin `01010101B`) ya da tırnak içinde bir ASCII karakter olarak da verilebilir; bu işlemci açısından sorun yaratmaz.

Sorunlu bir örnek: `MOV AL, 0FFFFH`. Verilmek istenen sabit 16 bitlik, yazmaç ise 8 bitliktir. 16 bitlik bir değer 8 bitlik yazmaca atanamaz.

### 7.3 Doğrudan adresleme (direct addressing)

Buradan itibaren hafızaya erişen modlara geçildi. Doğrudan adreslemede erişilecek hafıza gözü doğrudan gösterilir (ekrandan, 00:40:00). Hafızaya erişimde köşeli parantez kullanılır ve adres değeri parantezin içine yazılır. `[z]` biçiminde verilen bir değer veri erişimi olduğu için varsayılan olarak DS segment yazmacıyla kullanılır; gösterim `DS:z` olur. Bu komutlarda segment yazmacı açıkça yazılmaz, ama DS kullanıldığını bilmek gerekir. Doğrudan adreslemede z bir sabit (anlık) değerdir.

```asm
MOV AL, DATA      ; DATA bir etiket olup assembler bunu karşılık gelen adres değeri ile değiştirir
MOV BX, [1234H]   ; BX <- DS:1234H
```

Etiketli kullanım da doğrudan adreslemedir. `MOV AL, DATA` komutunun assembler'dan geçmiş hali incelenirse köşeli parantezli bir adres olarak karşılık bulduğu görülür.

`DS:1234H` gösteriminin anlamı şudur: DS'deki değer 10H ile çarpılır (bir onaltılık basamak sola kaydırılır) ve offset buna eklenir. Çıkan 20 bitlik fiziksel adres adres uçlarına verilir. Hafıza elemanındaki o numaralı göz aktif olur, içindeki değer veri yoluna aktarılır, işlemci tarafından alınır ve BX'e kopyalanır.

### 7.4 Yazmaç dolaylı adresleme (register indirect addressing)

Köşeli parantez içinde sabit yerine bir yazmaç kullanılırsa bu yazmaç dolaylı adreslemedir. Hafıza offset değeri bir yazmaçta saklanır (ekrandan, 00:45:00).

- Veri erişiminde köşeli parantez içinde yalnız **BX, SI ya da DI** bulunabilir; varsayılan segment DS'dir.
- **BP** kullanılırsa varsayılan segment SS olur. SP de teknik olarak kullanılabilir ama hoca bunu önermedi.

Bunların dışındaki yazmaçlar köşeli parantez içinde kullanılamaz. `MOV AX, [DX]` kesinlikle geçersizdir (ekrandan, 00:45:00).

Operandlardan biri yazmaçsa işlemin boyutu bellidir. `MOV AX, [BX]` gösterilen adresten ve bir sonraki adresten toplam 16 bit alıp AX'e aktarır; AL kullanılsaydı tek bir byte okunurdu.

**Örnek (ekrandan, 00:45:00):** `MOV AX, [BX]` komutu için verilenler: DS = 0100H, BX = 1000H, hafızada 2000H adresinde 12H, 2001H adresinde 34H.

- DS bir onaltılık basamak sola kaydırılır: 0100H × 10H = 1000H.
- BX eklenir: 1000H + 1000H = 2000H fiziksel adresi.
- 2000H'taki 12H AL'ye, 2001H'teki 34H AH'ye alınır.
- Sonuç: AX = 3412H.

### 7.5 Dolaylı adreslemede BYTE PTR ve WORD PTR

Tek operand alan bazı komutlarda yapılacak işlemin genişliği açıkça belli değildir. Bunu netleştirmek için `BYTE PTR` ya da `WORD PTR` eklenir (ekrandan, 00:50:00). Örneğin `INC [BX]` yazılırsa BX'in gösterdiği tek byte mı, yoksa oradan başlayan 16 bitlik değer mi artırılacak, belli değildir. Bu komut anlamlı değildir.

Hoca, derste anlaşıldığı gibi bu tür komutlarda assembler'ın varsayılan davranışının kabul edilmeyeceğini, boyutun her zaman açıkça yazılacağını tekrarladı. Kullanılan assembler'a göre farklı durumlar ortaya çıkabilir.

**Örnek (ekrandan, 00:50:00):** 100H adresinde FFH, 101H adresinde 12H olsun. İki komut grubu karşılaştırıldı:

```asm
MOV BX, 100H
INC BYTE PTR [BX]

MOV BX, 100H
INC WORD PTR [100H]
```

- Birinci grup yalnız 100H'taki byte'ı artırır: FFH + 1 = 00H olur (8 bitte taşma). 101H'taki 12H değişmez.
- İkinci grup 100H'tan başlayan 16 bitlik değeri, yani 12FFH'yi artırır: 12FFH + 1 = 1300H. 100H'ta 00H, 101H'te 13H olur.

İki sonuç birbirinden farklıdır; ne yapılmak isteniyorsa ona göre yazılmalıdır. İkinci örnekte adres doğrudan `[100H]` olarak yazıldı; hoca BX'te 100H varken `[BX]` kullanmanın da aynı sonucu vereceğini söyledi.

Slayttaki "(NEDEN?)" sorusunun cevabı da verildi: dolaylı adreslemede operandlardan biri yazmaçsa yazmacın genişliği işlemin boyutunu belirler, bu yüzden PTR'ye gerek yoktur.

## 8. Yazmaç Dolaylı Adreslemeyle Dizi Dolaşma

### 8.1 Problemin tanımı

Yazmaç dolaylı adreslemenin tipik kullanım alanı tablo ya da dizi biçiminde tutulan veriye sıralı erişimdir (ekrandan, 00:55:00). Başlangıçta dolaylı adresi tutan yazmaç dizinin başlangıç adresini tutar; her adımda uygun miktarda artırılarak sıradaki elemana geçilir.

Hoca bir EXE programının yığın, veri ve kod alanlarını çizdi ve veri alanına şu tanımları yazdı (ekrandan, 00:55:00):

```asm
dizi1  db 1,2,3,4,5,6
ndizi1 db 6
dizi2  dw 1000H, 1001H, 1002H, 1003H
ndizi2 dw 3
```

dizi1 byte tipinde 6 elemanlı bir dizidir; ndizi1 boyutunu tutar. dizi2 word (16 bit) tipindedir; ndizi2 onun boyutunu tutar. Değerler virgülle ayrılarak dizi biçiminde verilir.

<!-- BELİRSİZ: Ekranda dizi2'nin son elemanı "1003" olarak, sonundaki H kesik görünüyor; hafıza yerleşimi anlatımında 03H, 10H byte'ları söylendiği için 1003H olarak yazıldı. -->

> **Ders sonrası not:** Ekrandaki tanımda dizi2'nin 4 elemanı (1000H, 1001H, 1002H, 1003H) var, ama `ndizi2 dw 3` yazıldı. Hoca da "3 tane değişken" dedi. Bütün elemanları dolaşmak için ndizi2'nin 4 olması gerekir.

İstenen: dizi1'in bütün elemanlarını bir döngüde sırayla AL'ye okumak.

### 8.2 Kodun kurulması

Önce döngü sayısı CX'e alınır; bir öğrencinin önerisiyle `MOV CX, ndizi1` yazıldı. Sonra dizinin başlangıç adresi dolaylı adreslemede kullanılabilen bir yazmaca alınmalıdır. Köşeli parantez içindeki yazmaç zaten DS ile birlikte kullanıldığından gereken şey değişkenin offsetidir. Dizi veri alanının başında olmak zorunda değildir, öncesinde başka tanımlar olabilir.

**Soru:** Veri alanındaki bir değişkenin offsetini nasıl alırız? **Cevap:** LEA (load effective address) ile: `LEA BX, dizi1`. Artık dizi1'in ilk elemanının adresi BX'tedir.

Döngü için bir L1 etiketi verildi. İçinde eleman AL'ye okunur, BX bir artırılarak sonraki elemana geçilir ve LOOP ile döngü tamamlanır (ekrandan, 01:00:00):

```asm
    MOV CX, ndizi1
    LEA BX, dizi1
L1: MOV AL, [BX]
    INC BX
    LOOP L1
```

Döngü her döndüğünde MOV satırına gelindiğinde BX bir sonraki elemanı gösterir.

### 8.3 Koddaki hata

Hoca, kodun mantık olarak doğru olduğunu ama komut kullanımında teknik bir hata bulunduğunu söyleyip öğrencilere sordu. Öğrencilerin bazı tahminleri yanlıştı:

- `MOV AL, [BX]` satırında AL ile BX arasında uyumsuzluk yoktur. BX burada bir adres gösterir ve o adresten bir byte AL'ye alınır. Uyumsuzluk, iki operandın da saf yazmaç olduğu ve birinin 8, ötekinin 16 bit olduğu durumda vardır.
- `INC BX` için boyut belirtmeye gerek yoktur, çünkü bellek değil BX yazmacının kendisi artırılır.

Doğru cevap bir öğrenciden geldi: hata `MOV CX, ndizi1` satırındadır. CX 16 bitliktir ama ndizi1 `db` ile, yani byte olarak tanımlanmıştır. `db` yerine `dw` yazmak sorunu çözer, ama hoca tanımı bozmadan nasıl düzeltileceğini sordu. Cevap, CX'i sıfırlayıp yalnız düşük byte'ına değeri almaktır (ekrandan, 01:05:00):

```asm
    XOR CX, CX
    MOV CL, ndizi1
    LEA BX, dizi1
L1: MOV AL, [BX]
    INC BX
    LOOP L1
```

### 8.4 Aynı işin word dizisi için yapılması

Aynı iş dizi2 için yapıldı. ndizi2 `dw` ile tanımlı olduğu için `MOV CX, ndizi2` doğrudur. Bu kez SI kullanıldı: `LEA SI, dizi2`, ardından `L1: MOV AX, [SI]`. Eleman word olduğundan AX'e okunur (ekrandan, 01:05:00). Hoca, devamında `INC SI` ve `LOOP L1` yazılırsa kodda bir kaçak olacağını söyledi ve nedenini hafıza yerleşimi üzerinden gösterdi.

Tanımlar hafızaya byte byte, düşük anlamlı byte önce olacak şekilde yerleşir. dizi1'in adresinden itibaren 1, 2, 3, 4, 5, 6 değerleri, ardından ndizi1'in 6 değeri gelir. Sonra dizi2 başlar:

| Adres | dizi2 + 0 | +1 | +2 | +3 | +4 | +5 | +6 | +7 |
|---|---|---|---|---|---|---|---|---|
| Değer | 00H | 10H | 01H | 10H | 02H | 10H | 03H | 10H |

- İlk adımda SI dizi2'yi gösterir; okunan word düşük byte 00H, yüksek byte 10H, yani 1000H'tır. Doğru.
- `INC SI` ile SI bir artar ve 10H'ın bulunduğu gözü gösterir. Buradan okunan word'ün düşük byte'ı 10H, yüksek byte'ı 01H'tir; yani 0110H okunur. Dizide böyle bir eleman yoktur. Bir önceki elemanın yüksek byte'ı ile sonrakinin düşük byte'ı karışmıştır.

Her word değişken hafızada iki byte yer kapladığından sonraki elemanı göstermek için SI 2 artırılmalıdır. Bunun en uygun yolu `ADD SI, 2`'dir. Böylece ikinci okumada SI dizi2 + 2'yi gösterir ve düşük byte 01H, yüksek byte 10H, yani 1001H okunur. Python ile byte dizisi `00 10 01 10 02 10 03 10` olarak doğrulandı; SI + 1'den okunan word 0110H çıkar.

```asm
    MOV CX, ndizi2
    LEA SI, dizi2
L1: MOV AX, [SI]
    ADD SI, 2
    LOOP L1
```

> **Hocanın vurgusu:** Bir sonraki elemana geçerken veri genişliğine ve boyutuna dikkat edin. Bu çok karışan bir durumdur; hatalı çalışan kodlarda çoğu zaman bu tip tanımlarına dikkat edilmemiştir.

> **Ek bilgi (derste anlatılmadı):** İki döngü aynı programa birlikte yazılırsa ikisi de L1 etiketini kullanamaz; assembler aynı adlı iki etiketi hata sayar. İkinci döngüye L2 gibi farklı bir ad verilmelidir.

Bu konudan sonra yaklaşık 13 dakikalık bir ara verildi.

## 9. Taban, İndis ve Göreli Adresleme

### 9.1 Taban + indis adresleme (base + index addressing)

Aradan sonra köşeli parantez içinde bir taban yazmacı ile bir indis yazmacının birlikte kullanıldığı moda geçildi. Burada offset, iki yazmacın toplamından oluşur (ekrandan, 01:10:00). Bu temelde yine bir dolaylı adresleme modudur.

- Taban yazmacı (BX ya da BP) işlem yapılacak hafıza bölgesinin başlangıcını gösterir. Yığın adreslemede BP kullanılır; veri için taban yalnız BX olabilir.
- İndis yazmacı (DI ya da SI) verinin bu başlangıca göre yerini tutar.

Amaç biraz daha esneklik sağlamaktır. Ekrandaki örnek `MOV DX, [BX+DI]`'dir: DX'e DS × 10H + BX + DI adresindeki içerik atanır.

> **Hocanın vurgusu:** Köşeli parantez içinde yalnız toplama yapılabilir; çıkarma bile geçerli değildir. Çarpma da geçersizdir: `[2*BX+DI]` gibi bir ifade yazılamaz. Bir sabitle toplama ve iki yazmacı toplama geçerlidir, başka aritmetik geçerli değildir.

Hoca, çıkarmayı destekleyen bir assembler varsa bunu büyük olasılıkla negatif offset'e çevirerek yaptığını, ama derste bunun geçersiz kabul edileceğini söyledi.

### 9.2 Yazmaç göreli adresleme (register relative addressing)

Taban (BP ya da BX) ya da indis (DI, SI) yazmacının sabit bir offset değeriyle birlikte kullanılmasıdır (ekrandan, 01:30:00). Örnek:

```asm
MOV AX, [BX+100H]   ; AX <- DS:(BX + 100H)
```

Fiziksel adres DS × 10H + BX + 100H'tır. Veri için sabitle toplanabilen yazmaçlar BX, DI ve SI'dır; yığın için BP + sabit de kullanılabilir.

> **Hocanın vurgusu:** Adresleme yöntemlerinin adlarını birbiriyle karşılaştırarak ezberlemekten çok, bir biçim görüldüğünde onun geçerli olup olmadığını söyleyebilmek önemlidir. Temel adları (yazmaç, dolaylı, yazmaç göreli adresleme) bilmek yeterlidir.

### 9.3 Taban göreli indisli adresleme (base relative index addressing)

En karmaşık durumdur: bir taban yazmacına bir indis yazmacı ve bir sabit eklenir. Taban olarak BX ya da BP kullanılabilir ve varsayılan segment kullanılan taban yazmacına göre kendiliğinden belirlenir:

```asm
MOV AX, [BX+SI+100H]   ; AX <- DS × 10H + BX + SI + 100H
MOV AX, [BP+DI+2]      ; AX <- SS × 10H + BP + DI + 2
```

BX kullanılmışsa segment DS, BP kullanılmışsa SS olur.

Bu yapı iki boyutlu veri, yani matris erişiminde kullanılabilir. Örneğin her satırda 8 eleman varsa BX her satırda üç kez sola ötelenerek (8 ile çarpılarak) satır başına ilerletilir, SI ise her satır için uygun şekilde başlatılıp sütunlar üzerinde gezdirilir. Böylece matris erişimi indisler cinsinden yapılmış olur.

## 10. Program Hafızası Adresleme Modları

Veri adresleme modları köşeli parantezle hafızanın hangi adresine erişileceğini belirtir. Program hafızası adresleme ise CS ve IP'nin alacağı değerleri belirler. Bunun doğrudan, göreli ve dolaylı modları vardır.

### 10.1 Doğrudan program hafızası adresleme

Doğrudan bir program adresine ulaşmak için kullanılır (ekrandan, 01:35:00). Mevcut kod segmentinden farklı bir kod segmentine geçiş sağladığı için segmentler arası bir işlemdir; hem CS hem IP değiştirilir.

```asm
JMP 200H:300H    ; CS <- 200H, IP <- 300H
CALL 200H:300H
```

`JMP 200H:300H` "ilk değeri CS'ye, ikinci değeri IP'ye ata" demektir: 200H numaralı segmente gidilir ve 300H offsetindeki koddan itibaren yürütmeye başlanır. Oradaki adreste anlamlı bir komut bulunduğu varsayılır.

Aynı şey CALL için de geçerlidir. CALL ana program içinde bir alt yordam çağırmaktır; alt yordam bitince ana programa dönülmelidir. Bu yüzden ana programdaki bir sonraki komutun adresi yığına atılır. Segmentler arası bir çağrıda hangi segmentten gelindiği de saklanmalıdır; bu yüzden CALL hem segment hem offset değerini yığına atar, sonra CS = 200H, IP = 300H olacak şekilde başka segmentteki fonksiyonu yürütür. Bu bir "call far" yapısıdır ve dönüşü RETF ile olmalıdır.

JMP yığına bir şey atmadığı için JMP ile gidilen bir yerden dönüş de JMP ile yapılmalıdır.

### 10.2 Göreli program hafızası adresleme

Göreli adresleme daha çok segment içi dallanmalarda kullanılır. Hangi program adresine gidileceği mevcut IP değerine göre belirlenir. JMP komutu 1 byte ya da 2 byte işaretli sabit değerli operand kabul eder (ekrandan, 01:40:00).

**Örnek 1 (ekrandan, 01:40:00):** 100H adresinde `JMP 100` komutu var.

- Mevcut IP = 100H.
- Operand 100 (onlu) = 64H eklenir.
- IP = 100H + 64H = 164H.

Hoca hesabı kontrol etti (96 + 4 = 100, yani 64H doğru).

**Örnek 2 (ekrandan, 01:40:00):** 200H adresinde `JMP 0FFH` komutu var. Hoca ilk önce örneği 100H'ta kurdu, değerler birbirine çok yakın çıktığı için 200H'a taşıdı. Komut çalışınca IP bir azalır ve 1FFH'taki komuta dönülür. Slayttaki "(NEDEN?)" sorusu öğrencilere soruldu.

Cevap: operand 1 byte işaretli bir sayıdır. 0FFH = `1111 1111`. En yüksek anlamlı biti 1 olduğu için sayı negatiftir. Büyüklüğünü bulmak için ikiye tümleyen alınır. Hocanın anlattığı yöntem: sağdan ilk 1 dahil olmak üzere bitler olduğu gibi bırakılır, geri kalanların tersi alınır. Sonuç `0000 0001`, yani büyüklük 1'dir. Demek ki 0FFH = −1'dir ve IP = 200H − 1 = 1FFH olur.

Slaytta 16 bitlik göreli offset için `JMP 1000H` örneği de vardı.

> **Ders sonrası not:** Hoca yer değiştirmeyi JMP komutunun kendi adresine ekledi. Gerçek 8086'da yer değiştirme, JMP'den sonraki komutun adresine (IP o anda JMP'nin uzunluğu kadar ilerlemiştir) eklenir. MASM'de `JMP 100` gibi bir yazımda assembler sayıyı büyük olasılıkla hedef adres sayar ve yer değiştirmeyi kendisi hesaplar.

### 10.3 Dolaylı program hafızası adresleme

Veri hafızasındaki gibi, gidilecek adres bir yazmaç üzerinden ya da köşeli parantez içinde verilir. Köşeli parantez içinde kullanılabilecek değerler bellidir. Örnek: `JMP BX` ya da `JMP [BX]`.

## 11. Yığın Adresleme Modları

### 11.1 Genel kurallar

Yığın adresleme, yığının hangi bölgesiyle işlem yapıldığını belirten komutlarla ilgilidir. Slayta göre (ekrandan, 01:45:00):

- 8086'da yığın, geçici veri saklamak ve fonksiyonlardan dönüşte dönüş adreslerini saklamak için kullanılır.
- Yığın LIFO (last in, first out) mantığıyla çalışır.
- Yığınla ilgili PUSH ve POP komutları kullanılır.
- PUSH yığına her zaman bir WORD basar, POP yığından her zaman bir WORD çeker.
- Yığın adresleme için SS:SP ikilisi kullanılır.

Özel bir durum: kod segmenti yığına atılabilir ama yığından çekilemez. `PUSH CS` geçerlidir, `POP CS` hata verir. Bunun dışındaki yazmaçlar yığına atılıp çekilebilir.

**Soru (ekrandan, 01:45:00):** `PUSH BL` doğru mu? **Cevap:** Hayır. Yığına word tipinde veri atılmalıdır. BL'deki değer yığına atılmak isteniyorsa, CX'te daha önce yapıldığı gibi önce BX sıfırlanır, değer BL'ye konur, sonra yüksek kısmı sıfır olan BX yığına basılır.

### 11.2 SP'nin hareketi

Slayttaki kurallar (ekrandan, 01:50:00):

- SP yazmacı programcının tanımladığı yığının genişliğini gösterecek şekilde ilk değer alır.
- Her PUSH işleminde SP−1 ve SP−2 adreslerine 2 byte veri yazılır ve SP 2 azaltılır.
- Her POP işleminde 2 byte veri okunur ve SP 2 artırılır.

Hoca bunu bir çizimle gösterdi. Yığının 0H offsetinden başlayıp toplam 100H byte yer ayrıldığını, yani son gözün FFH olduğunu varsaydı. SS'nin değeri program hafızaya yüklenirken belirlenir. Hoca önce SP'nin FEH ile başladığını söyledi, sonra bu sırayı düzeltti:

- Yığın tanımlandığı anda SP = 100H olur.
- `PUSH AX` (AX = 3412H) çalışınca bu adresin bir ve iki altına, yani FFH ve FEH gözlerine yazılır: düşük adres FEH'e düşük byte 12H, FFH'e yüksek byte 34H.
- SP = 100H − 2 = FEH olur (ekrandan, 01:50:00). SP her zaman o anda dolu olan son gözü gösterir.
- Bir sonraki PUSH FDH ve FCH gözlerini doldurur ve SP FCH olur.

SP'deki değeri işlemci kendiliğinden artırıp azaltır; programcı SP'ye doğrudan değer yazmaz. EXE tipi programlarda tanımlanan yığının boyutu, yığının son adresine denk gelen çift sayı olarak SP'ye atanır.

> **Ders sonrası not:** Slayttaki "Her POP işleminde SP+1 ve SP+2 adreslerinden 2 byte veri okunur" ifadesi tam doğru değildir. POP, SP ve SP+1 adreslerinden okur ve ardından SP'yi 2 artırır. PUSH için slayttaki SP−1 ve SP−2 ifadesi doğrudur.

### 11.3 Yığın neden uzak adresten dolar?

Yığına uzak (yüksek) adresten başlanarak düşük adrese doğru veri yerleştirilir; veri çekildikçe yeniden uzak adrese doğru ilerlenir. Hafıza yerleşiminde yığının önünde kod ya da veri segmenti olabilir. Uzak adresten başlamak bunları korumak içindir. Yığın gerekenden küçük tanımlanırsa ve dolmasına rağmen veri atılmaya devam edilirse kod ya da veri segmentindeki değerler bozulabilir.

Yığın adresi de diğer dolaylı adreslemelerdeki gibi hesaplanır: SS × 10H + SP.

## 12. Sözde Komutlar ve LST Dosyası

### 12.1 Sözde komut nedir?

Adresleme modlarından sonra komutların çalışmasına yardım eden sözde komutlara (pseudo-instruction, assembler direktifi) geçildi. Bunlar işlemcinin komutu değil, kullanılan assembler'ın kendine özgü kelimeleridir. Makine kodu karşılığı üretilmez; makine kodu yalnız mnemonikler için üretilir. Program akışını daha iyi kontrol etmeyi ve kodu daha okunabilir yazmayı sağlarlar.

Hoca bunu C'deki makrolara benzetti: C'de derlemeden önce bir ön işlemeyle makrolar sayısal değerlerle değiştirilir. Burada da kod assembler'a girmeden önce sözde komutlar düzenlenir ve karşılığında makine kodu üretilmez.

Sözde komutların grupları (ekrandan, 02:10:00):

- **LST uzantılı dosyanın düzenlenmesi:** PAGE, TITLE
- **Program kesim düzenlemesi:** SEGMENT/ENDS, ORG, ASSUME
- **Veri tanımlamaları:** DB, DW, DD, DQ, EQU, DUP, TYPEDEF, PTR, LABEL
- **Yordam düzenleme:** PROC/ENDP, EXTRN, PUBLIC
- **MACRO düzenleme:** MACRO/ENDM, INCLUDE, LOCAL
- **Diğer:** LENGTH, TYPE, SIZE, OFFSET, SEG, END

### 12.2 LST dosyası, PAGE ve TITLE

Kod derlenince ona karşılık LST uzantılı bir dosya oluşur. Bu dosyada hem yazılan assembly kodu hem de karşılığındaki makine kodu yer alır. Assembly ile makine kodunu karşılaştırmak istendiğinde LST dosyasına bakılır.

Hoca TOPLA16.ASM örneğini açtı (ekrandan, 02:05:00). Dosyanın başında şunlar vardı:

```asm
        PAGE 60,80
        TITLE ornek____
```

PAGE, LST dosyasının kaç satır ve kaç sütunluk sayfalara formatlanacağını belirtir; LST'de yeni sayfaların bu değerlere göre bölündüğü görüldü. TITLE, LST dosyasının üstündeki başlığı belirler.

LST dosyasında yığın segmentinin boyutu, veri segmentindeki her değişkenin hangi offsette yerleştiği ve makine kodu karşılıkları görülür. Bazı adres değerleri kod hafızaya yüklendikten sonra hesaplanacak göreli değerlerdir; bazıları ise program yüklenmeden önce bellidir. Başka bir LST örneğinde (ekrandan, 01:55:00) `MOV AX, DATASG` satırı `B8 ---- R` biçimindeydi; segment değeri yükleme sırasında belirlenir. Aynı dosyada başka dosyadaki bir yordamı çağıran `CALL GCD_PROC` satırı `E8 0000 E` diye görünüyordu.

> **Ek bilgi (derste anlatılmadı):** MASM LST dosyalarında `R` işareti büyük olasılıkla bağlayıcı ya da yükleyici tarafından düzeltilecek (relocatable) bir değeri, `E` işareti ise dış (external) bir sembole yapılan başvuruyu gösterir.

Hoca, LST dosyasının etiketlerden ve göreli tanımlardan arınmış, bunların yerine gerçek değerlerin yazıldığı bir kod parçası olduğunu söyledi. ASM dosyası okumaya daha yakındır; LST dosyası makine koduna daha yakındır.

## 13. Kesim Tanımları: SEGMENT, ASSUME, END, ORG

### 13.1 EXE tipi programda kesimler

Hoca bir EXE tipi program üzerinde kesim tanımlarını gösterdi (ekrandan, 02:00:00 ve 02:05:00):

```asm
STEK SEGMENT PARA STACK 'STK'
        DW 30 DUP(?)
STEK ENDS

DSG  SEGMENT PARA 'DTS'
ASAYI DW 0F00H
BSAYI DW 0AF01H
SONUC DD 0
DSG ENDS

CSG  SEGMENT PARA 'CODE'
        ASSUME CS:CSG, DS:DSG, SS:STEK

BASLA   PROC FAR

        PUSH DS
        XOR AX,AX
        PUSH AX

        MOV AX, DSG
        MOV DS, AX

        LEA SI, SONUC
        MOV AX, ASAYI
        ADD AX, BSAYI
        MOV [SI], AX
        ...
```

<!-- BELİRSİZ: TOPLA16.ASM'nin devamı karelerde görünmüyor; kodun geri kalanı nota alınmadı. Hoca da kodun ne iş yaptığına girmedi, yalnız sözde komutlar açısından inceledi. -->

EXE tipi programlarda bir yığın, bir veri ve bir kod segmenti tanımlanır, yani üç hafıza alanı vardır. Bir kesimin başlangıcı bir isim ve ardından SEGMENT kelimesiyle, bitişi aynı isim ve ENDS kelimesiyle gösterilir. Burada STEK, DSG ve CSG adlı üç kesim vardır.

- **Yığın kesimi:** STACK kelimesi bu kesimin yığın kesimi olduğunu gösterir.
- **Kod kesimi:** EXE programının sonunda END kelimesi ve bir etiket bulunur. END de bir sözde komuttur. Ardından gelen etiket, program hafızaya yüklenip çalıştırıldığında yürütmenin hangi etiketten başlayacağını belirtir. Burada BASLA etiketi CSG kesiminde olduğu için CSG kod kesimidir. Yani END'den sonra gelen etiket hangi kesimdeyse o kesim kod kesimidir.

### 13.2 ASSUME

ASSUME, kod kesiminin hemen altına yazılan bir sözde komuttur. Program henüz hafızaya yüklenmediği için CS, DS ve SS'nin değerleri bilinmez. Kodun içinde bu segmentlerle ilgili işlemler yapılacaksa ASSUME ile assembler'a ön bilgi verilir: program yüklendiğinde CSG ile gösterilen kesim kod segmenti, DSG ile gösterilen kesim veri segmenti, STEK yığın segmenti olarak kullanılacaktır. Bu da makine kodu üretmez; programcının belirli varsayımlarla göreli adresleri kullanmasını sağlar. Bu göreli adresler program yüklendikten sonra anlam kazanır.

### 13.3 COM tipi program ve ORG

COM tipi programda tek bir SEGMENT/ENDS çifti, yani tek kesim vardır. Data, kod ve yığın aynı kesimdedir. Yine END'den sonra gelen etiket başlangıç noktasını verir. ASSUME'da CS, DS, SS ve ES için aynı kesim adı yazılır.

COM programlarına özgü bir özellik: kendi kesiminin 100H adresinden başlarlar. 0 ile 100H arasında programın başlık (header) bilgisi bulunur ve bu bölge bozulmamalıdır. Yazılan kod ve verinin 100H'tan itibaren yerleşmesi için `ORG 100H` sözde komutu kullanılır. Bu, sonraki makine kodu karşılığı olan her şeyin 100H adresinden başlayarak yerleştirileceği anlamına gelir. Program derlendiğinde başlık bilgisi kendiliğinden o boş alana yerleşir.

Hoca COM programının LST dosyasında da kesim tanımının kendi 0 offsetinde yapıldığını, `ORG 100H` ile sıradaki offsetin 100H'a getirildiğini ve ilk anlamlı komut olan JMP'nin 100H offsetinden başladığını gösterdi. ENDS ve END satırları için offset artmadı, yani makine kodu üretilmedi.

## 14. Veri Tanımlama Sözde Komutları

### 14.1 DW, DB, DD, DQ

Veri segmenti içinde değişken tanımlanırken sıra şöyledir: değişken adı, tipi ve alacağı değerler. Değerler virgülle ayrılırsa bu adresten başlayan bir dizi tanımlanmış olur.

- **DW (define word):** Ardından gelen her veri için 2 byte yer ayırır. `DW 0` yazılsa bile 2 byte (0000H) ayrılır.
- **DB (define byte):** Her veri için 1 byte ayırır. `dizi DB 1,2,3,4,5,6` gibi dizi tanımlanabilir. DB'den sonra 16 bitlik bir sabit yazılamaz.
- **DD (define double word):** 32 bit (4 byte) yer ayırır. `DD 0` yazılsa da 8, 16, 24, 32 bit, yani 4 byte ayrılır.
- **DQ (define quad word):** 64 bit, yani 8 byte yer ayırır.

### 14.2 DUP ile tekrarlı tanım

DUP (duplicate), bir değeri birden fazla kez başlatmak için kullanılır. Hocanın sözlü örneği: `DB 10 DUP(5)` yazmak, `DB` ardından on tane 5 yazmakla aynıdır. DUP içinde DUP da kullanılabilir; hocanın sözlü örneğinde iki tane 6 değeri beş kez tekrarlanıyordu.

<!-- BELİRSİZ: İç içe DUP örneğinin tam yazımı kareye düşmedi; anlatıma göre büyük olasılıkla `5 DUP(2 DUP(6))` biçimindeydi. -->

### 14.3 LST üzerinden veri yerleşimi

Hoca TOPLA16.LST'yi açıp veri segmentini inceledi (ekrandan, 02:15:00). LST'de birinci sütun ilgili segmentteki offseti, ikinci sütun verinin gerçek değerini, üçüncü sütun assembly kodunu verir:

```text
0000  0F00       ASAYI DW 0F00H
0002  AF01       BSAYI DW 0AF01H
0004  00000000   SONUC DD 0
0008             DSG ENDS
```

- DW sözde komutu için makine kodu karşılığı yoktur; yalnız tanımlanan değer 0F00H yerleşmiştir. Veri segmentinin 0 offsetinden başlayarak 2 byte yerleşir: 0000 offsetinde 00H, 0001 offsetinde 0FH.
- BSAYI, öncekinin 2 byte yer kaplaması nedeniyle 2 offsetinden başlar. 0AF01H yazılmasına karşın 3 byte değil 2 byte yerleşir: 2 offsetinde 01H, 3 offsetinde AFH. Baştaki 0'ın nedeni, en yüksek anlamlı basamağı harf olan onaltılık sayının bir etiketle karışmamasıdır. Bu 0 sayının 16 bitten geniş olduğu anlamına gelmez; DW ile verildiği için 16 bitlik değerlendirilir ve 16 biti aşan 0 hesaba katılmaz.
- SONUC 32 bitlik bir değişkendir: 4 byte × 8 bit = 32 bit. Bu yüzden segment 8 offsetinde biter.

Yığın tanımında ise `DW 30 DUP(?)` vardır (ekrandan, 02:15:00). PUSH ve POP word ile çalıştığı için yığın genişliği çift sayı olmalıdır. DW ile tanımlanırsa her eleman 2 byte olduğundan genişlik kendiliğinden çift olur: 30 × 2 = 60 byte. DB ile tanımlanırsa sayı mutlaka çift seçilmelidir; tek sayı hatalı bir tanımdır. `?`, içeriğin o anda hafızada ne varsa o olabileceğini gösterir. LST'de yığın kesimi `001E[????]` biçiminde görünür ve `STEK ENDS` satırının offseti 003C'dir. 3CH onlu 60'tır; yani kesim 0 offsetinden başlayıp 60 byte sürer.

Kod kesiminde de CSG SEGMENT, `BASLA PROC FAR` ve END satırları makine kodu üretmez. Kesim tanımı da yordam tanımı da 0 offsetindedir; değerler ilk anlamlı komut olan PUSH DS'den itibaren yerleşmeye başlar. Yordam tanımları yalnız birer etikettir.

## 15. Yordamlar, EXTRN/PUBLIC ve Makrolar

### 15.1 PROC ve ENDP

> **Hocanın vurgusu:** EXE tipi programlarda kod kesimi içinde mutlaka FAR tipinde bir prosedür tanımlanmalıdır. Bu, ana (main) fonksiyonu belirtir.

Örnekte bu `BASLA PROC FAR` satırıdır. Prosedür bir etiketle tanımlanır, PROC kelimesi prosedür olduğunu, ardından gelen kelime tipini belirtir. Bitişi aynı etiket ve ENDP kelimesiyle gösterilir. LST'de hem başlangıç hem bitiş satırı için makine kodu üretilmediği görüldü (ekrandan, 01:55:00).

### 15.2 EXTRN ve PUBLIC

Bir program birbirini çağıran fonksiyonları içeren iki ayrı .ASM dosyası olarak yazılabilir. Her dosya ayrı ayrı assembler'dan geçirilir ve .OBJ dosyaları oluşur. Bu OBJ dosyaları birlikte bağlanarak (link) çalıştırılabilir EXE dosyası elde edilir. Birinci dosya derlenirken ikinci dosyadaki bir tanımdan bağlanana kadar haberi yoktur.

- **EXTRN:** Bir tanımın dışarıdan, başka bir dosyadan kullanılacağını belirtir.
- **PUBLIC:** Bir tanımın başka dosyaların kullanımına açıldığını belirtir.

Dosyaların ayrılmasının amacı daha modüler ve sürdürülebilir kod yazmaktır; farklı fonksiyonlar farklı kütüphaneler olarak tutulabilir.

Hocanın gösterdiği ilk örnekte ana dosyada GCD_PROC adlı bir fonksiyon EXTRN olarak tanımlanmıştı. Dosyada fonksiyonun çağrısı (CALL) vardı ama gövdesi yoktu. Bu dosya kendi başına derlenip OBJ üretilebilir. Anlamlı olabilmesi için GCD_PROC'u FAR tipinde içeren öteki dosyada bu fonksiyonun PUBLIC olarak tanımlanması gerekir. İki OBJ birlikte bağlanınca EXTRN olarak tanımlı fonksiyon ikinci OBJ'de bulunur ve çağrılabilir hale gelir.

Aynı şey değişkenler için de geçerlidir. İkinci örnekte ana yordam dosyası dışarıdan kullanacağı fonksiyonları EXTRN olarak tanımlamış, dışarıya sunduğu `dizi` ve `eleman` değişkenlerini PUBLIC yapmıştı. Alt yordam dosyasının başı şöyleydi (ekrandan, 02:25:00):

```asm
        PAGE 60,80
        TITLE DIZI_MIN_F

PUBLIC DIZI_MIN_F
EXTRN DIZI:WORD, ELEMAN:WORD

CODESG  SEGMENT PARA 'CODE'
        ASSUME CS:CODESG

DIZI_MIN_F PROC NEAR

        PUSH CX
        PUSH SI
        LEA SI, DIZI
        MOV CX, ELEMAN
        MOV AX, [SI]
        DEC CX
TEKRAR: ADD SI,2
        ...
```

Alt yordam, ana dosyadaki word tipindeki DIZI ve ELEMAN değişkenlerini EXTRN ile kullanır ve kendi fonksiyonunu PUBLIC ile dışarı açar. Ana yordamda bu fonksiyon EXTRN olarak tipiyle birlikte tanımlandığı için fonksiyon olduğu anlaşılır.

<!-- BELİRSİZ: Hoca anlatımda alt yordamın dışarı açtığı fonksiyonu "dizi ortalama f" diye andı ve ana yordamda FAR tipinde tanımlandığını söyledi. Karede görünen dosya ise DIZI_MIN_F'i NEAR olarak tanımlıyor. Anlatılan dosya ile karedeki dosya farklı olabilir. -->

### 15.3 MACRO, INCLUDE ve LOCAL

**INCLUDE:** Hoca bir örnekte `INCLUDE` ile bir makro dosyasının eklendiğini gösterdi. INCLUDE, verilen dosyanın içeriğini olduğu gibi o noktaya kopyalar ve daha çok makro tanımları için kullanılır.

**MACRO/ENDM:** Makro tanımı MACRO kelimesiyle başlar, ENDM (end macro) ile biter. MACRO'nun yanında birkaç parametre olabilir. Bir etiketi vardır, ama prosedürden farklı olarak bitişte etiket yazmak gerekmez.

Makro ile prosedür arasındaki fark:

- Prosedür bir kez tanımlanır ve çok defa çağrılabilir. Çağrının bir yükü (overhead) vardır: yığına bir şeyler atılır, fonksiyona gidilir, fonksiyon bitirilir, geri dönülür, yığından değerler çekilir. Tekrarlı çağrılar kod boyutunu büyütmez.
- Makro her çağrıldığında aynı kod parçası oraya kopyalanır. Kod boyutu her çağrıda büyür, ama çağırma yükü yoktur; kod doğrudan kopyalanıp derlenir.

Bu yüzden küçük işlemler için makro, daha uzun işlemler için prosedür tercih edilebilir. İkisi de birer tasarım kalıbı olarak kullanılabilir.

**LOCAL:** Makro her çağrıldığında içindeki kod kopyalandığı için, makro içinde tanımlanan bir etiket ikinci çağrıda da aynı adla kalırsa hangi etikete gidileceği belirsizleşir. LOCAL ile verilen etiketler her çağrıda tekil olacak şekilde değiştirilir.

## 16. Sözde Komutların Ayrıntıları

### 16.1 OFFSET, TYPE, SIZE, LENGTH

Hoca bu gruptan önce kısaca söz etti: OFFSET, LEA yerine kullanılabilir; TYPE ve SIZE tanımlanan verinin tipi ve genişliğiyle ilgilidir; LENGTH dizinin boyutuyla ilgili değeri döndürür. Ayrıntıları aşağıda verildi.

### 16.2 PAGE, TITLE, SEGMENT ve hizalama

PAGE ve TITLE'ın LST dosyasıyla ilgili olduğu tekrarlandı. Assembly dosyası derlenirken LST oluşturmak için bir parametre verilebilir. Kesim tanımlarında SEGMENT kelimesinden sonra bir hizalama tanımı gelir (ekrandan, 02:35:00):

- **BYTE:** Kesim sıradaki adresten başlar.
- **WORD:** Kesim sıradaki çift adresten başlar.
- **PARA:** Kesim sıradaki 16'nın tam katı adresten başlar.
- **PAGE:** Kesim sıradaki 256'nın tam katı adresten başlar.

Derlenen EXE programı hafızaya işletim sistemi tarafından yüklenir ve sıradaki boş segmentlere yerleştirilir. Hizalama parametresi bu yerleşimin nereden başlayacağını belirler.

Hizalamanın önemi şuradadır: işlemci tek adrese denk gelen 16 bitlik veriyi okumakta zorlanır; tasarımı gereği bunu iki okuma-yazma çevriminde yapabilir. Çift adresteki 16 bitlik veriyi ise tek seferde okur. Bu yüzden özellikle veri tanımında byte hizalaması çok anlamlı olmayabilir; uygun hizalama veri aktarımını hızlandırır.

Birleştirme tanımları farklı dosyalardaki kesimlerin nasıl birleşeceğini belirtir (ekrandan, 02:35:00):

- **PUBLIC:** Farklı dosyalardaki aynı isimli kesimler peş peşe yerleşir.
- **COMMON:** Aynı isimli kesimler aynı adresten başlar, ortak bir kesim olur.
- **STACK:** Kesim yığın kesimidir; PUSH ve POP LIFO mantığıyla çalışır.
- **AT:** Kesimin hangi adresten başlayacağını belirler.

### 16.3 ORG ve ASSUME

ORG, COM programlarının 100H adresinden başlaması için kullanılır. Başka assembler'larda da vardır. Örneğin 8086'ya çok benzeyen 8051 mikrodenetleyicisinde ORG'dan sonra istenen adres verilerek programın o adresten itibaren yerleşmesi sağlanabilir. Yani ORG'un amacı, hafızaya yerleşimin istenen adresten başlamasını sağlamaktır. ASSUME ise kesim tanımlarının ne amaçla kullanıldığını ve başlangıç adreslerini belirtir.

### 16.4 DB ve DW ayrıntıları; little endian

DB 8 bitlik değerler tanımlar. Onlu ya da onaltılık değer verilebilir. Onaltılık değerin en yüksek anlamlı basamağı bir harfse başına 0 yazılmalıdır; bu 0 göz ardı edilir, 8 biti aştığı anlamına gelmez. DB ile virgülle ayrılan değerler dizi elemanları olarak sırayla yerleşir. Tırnak arasında bir ASCII dizgisi de verilebilir; o zaman her karakterin ASCII kodu hafızaya yerleşir.

DW 16 bitlik verileri yerleştirir, değer aralığı 0000H-0FFFFH'tır (ekrandan, 02:40:00).

> **Hocanın vurgusu:** 8086 little endian formatında çalışır. Bu çok önemli bir noktadır.

Little endian şu demektir: word ya da double word gibi birden çok byte'lı veriler hafızaya yerleştirilirken hafızanın düşük adresine verinin düşük anlamlı byte'ı, yüksek adresine yüksek anlamlı byte'ı yazılır.

**Örnek (ekrandan, 02:40:00):** `Dizi DW 5, 10, 20` tanımı 0510H adresinden itibaren şöyle yerleşir:

| Adres | 0510H | 0511H | 0512H | 0513H | 0514H | 0515H |
|---|---|---|---|---|---|---|
| Değer | 05H | 00H | 0AH | 00H | 14H | 00H |

İlk word 0005H'ın düşük byte'ı 05H, 0510H'a; yüksek byte'ı 00H, 0511H'e yazılır. Sonra 10 = 000AH gelir. Elemanlar word olduğu için ardışık iki değişkenin adresleri arasında 2 fark vardır. Son olarak 20 = 0014H yerleşir. Python ile doğrulandı: byte dizisi `05 00 0A 00 14 00`.

DD 32 bitlik veri tanımlar, aralığı 00000000H-0FFFFFFFFH'tır. Burada da little endian geçerlidir. **Örnek (ekrandan, 02:40:00):** `A DD 12345678H` segmentin başında (0H) tanımlanırsa:

| Adres | 0H | 1H | 2H | 3H |
|---|---|---|---|---|
| Değer | 78H | 56H | 34H | 12H |

0H adresinden double word okunduğunda işlemci bunu 78563412H diye almaz. En düşük adresteki byte'ın en düşük anlamlı byte olduğunu bilerek değeri 12345678H olarak değerlendirir. Python ile doğrulandı.

DQ (define quad word) 8 byte bellek alanı ayırmak için kullanılır (ekrandan, 02:40:00).

### 16.5 EQU, DUP ve ?

EQU değişken tanımlamaz; C'deki `#define`'a karşılık gelir. Assembler derlemeye geçmeden önce EQU ile tanımlanan bütün etiketleri sayısal değerleriyle değiştirir.

DUP örnekleri (hocanın anlatımına göre):

- Dizi1 adlı byte dizisi 15 elemanlıdır ve her elemanı 0'dır: 15 tane sıfır değerli byte ayrılır.
- Matris mantığında bir tanım: değeri 8 olan 4 byte ayrılır, bu da 3 kez tekrarlanır. Toplam 3 × 4 = 12 byte ayrılır ve hepsinin içeriği 8'dir.
- İçerik olarak `?` kullanılabilir: o anda hafızada hangi değer varsa olduğu gibi korunur, rastgele değerler gibi düşünülebilir. 10 tane word tanımı `?` ile yapılırsa 20 byte yer tutar.

<!-- BELİRSİZ: Bu DUP örneklerinin slayttaki tam yazımı karelerde yok; değişken adları ve sözdizimi altyazıdan kesin çıkmıyor. -->

### 16.6 TYPEDEF ve PTR

TYPEDEF, kendimize göre özel (custom) veri tipleri tanımlamak için kullanılır. Örneğin word'e karşılık gelen Integer adlı yeni bir tip tanımlanıp değişkenler bu tiple tanımlanabilir.

PTR, pointer'dan gelir. BYTE PTR ve WORD PTR veri tipini (adresteki verinin boyutunu) belirtir; bunlar derste görülmüştü. FAR PTR ve NEAR PTR fonksiyonun tipiyle ilgilidir. Bir fonksiyon FAR tipindeyse farklı bir segmenttedir. O fonksiyonu çağırıp geri dönmek için mevcut segment ve offset değerinin ikisi birden yığında saklanmalıdır; bunu işlemci kendiliğinden yapar.

### 16.7 LABEL

LABEL, bir veri tanımına farklı bir tiple erişmek için kullanılır (ekrandan, 02:45:00). Örnek:

```asm
Yenib LABEL BYTE
Sayiw DW 2535H
Yeniw LABEL WORD
Sayib DB 45H
Sayic DB 55H

MOV AX, Yeniw
MOV BL, Yenib
```

Önce LABEL'lar yokmuş gibi bakılır. `Sayiw DW 2535H` düşük adresten itibaren önce 35H, sonra 25H olarak 0000H ve 0001H'e yerleşir. Ardından 0002H'e 45H (Sayib), 0003H'e 55H (Sayic) byte'ları gelir.

LABEL'lar eklenince:

- Word tanımından önce gelen `Yenib LABEL BYTE`, 2535H word'ünün düşük anlamlı byte'ını gösteren byte tipinde bir etiket olur. `MOV BL, Yenib` ile okunan değer 35H'tir.
- İki byte tanımından önce gelen `Yeniw LABEL WORD` ise word tipindedir. `MOV AX, Yeniw` ile 0002H ve 0003H'teki iki byte bir word olarak okunur: little endian gereği AX = 5545H olur.

Yani LABEL, hafızada yerleşik herhangi bir byte ya da byte dizisinin veri tipinden bağımsız olarak byte ya da word anlamında okunmasını sağlayan bir etiketlemedir.

### 16.8 Yordam ve makro tekrarı

Hoca ardından yordam ve makro tanımlarını kısaca tekrarladı: prosedür PROC ile başlar, ENDP ile biter. EXTRN başka dosyadan fonksiyon ya da değişken kullanmak için, PUBLIC dışarıya açmak için kullanılır. Makro MACRO ile başlar, ENDM ile biter ve her çağrıldığı yere kopyalanarak kod boyutunu büyütür; prosedür ise ilgili adrese gidilerek yürütülür, kod boyutunu büyütmez ama çağırma yükü vardır. Ayrı dosyadaki makroları koda katmak için INCLUDE kullanılır. LOCAL, makro içindeki etiketlerin her çağrıda tekil olmasını sağlar; aksi halde assembler hangi etikete gideceğini bilemeyebilir.

### 16.9 LENGTH, TYPE, SIZE, OFFSET, SEG, END

Örnek tanım: `TABLO DW 15 DUP(0)`, yani her biri 0 olan 15 word.

- **LENGTH TABLO:** DUP'tan önce verilen sayıyı, yani 15'i döndürür.
- **TYPE TABLO:** Her elemanın boyutunu verir. DW ile tanımlandığı için her göz 2 byte'tır, sonuç 2.
- **SIZE TABLO:** Tanımın toplam kaç byte yer kapladığını verir: LENGTH × TYPE = 15 × 2 = 30.

Bunlar doğrudan DUP ile ilgilidir ve assembler'dan önceki işlemlerdir; yani assembler'a girerken LENGTH TABLO yerine 15 yazılmış olur. Makine kodu karşılıkları yoktur.

- **OFFSET:** LEA ile aynı işi görür. Farkı şudur: OFFSET kullanıldığında program derlenmeden ya da hafızaya yüklenmeden önce sabit bir değer oluşur. LEA ise program hafızaya yüklendikten sonra çalışan bir komutun sonucunda değer üretir.
- **SEG:** İlgili etiketin hangi segmentte kullanıldığını, o segment değerini döndürür.
- **END:** ASM dosyasının son satırıdır. Program hafızaya yüklendiğinde kodun hangi etiketten itibaren yürütüleceğini verir.

Sözde komutların makine kodu karşılığı olmadığı ve assembler tarafında ilgili sabit değerlerle değiştirildiği tekrar vurgulandı.

## 17. Geliştirme Ortamı Üzerine Sorular

Hoca, sonraki derslerde örnekler üzerinden ilerleneceğini söyledi: önce bir problem tanımlanacak, assembly kodu olarak yazılacak, derlenecek, sonuç LST dosyası ve debug programı üzerinden incelenecek.

**Soru:** DOSBox kurulumu ve kullanımı gösterilecek mi? **Cevap:** Çok ayrıntılı olmasa da sonraki derste oradan başlanacak. DOSBox, içinde DOS emülasyonu bulunan bir emülatördür. İçine Microsoft Macro Assembler (MASM) kurulur. Hocadaki sürüm 5.10'dur; kurulum dosyalarını birkaç disket imajı halinde bulup tek tek bağlayarak kurmuştur. Bunun dışında debug programına da ihtiyaç vardır. DOSBox açılırken Windows tarafındaki bir klasörü sürücü olarak bağlamak için mount komutu kullanılabilir.

**Soru:** Kendi bilgisayarımdaki işlemci için assembly yazmak istersem hangi sözdizimini kullanacağımı nereden anlarım? **Cevap:** Bu tamamen kullanılan assembler'a bağlıdır. Güncel bilgisayarlar 64 bitliktir ve 32 ya da 64 bitlik programlar derlenebilir. Derste görülen MASM 5.10 16 bitlik bir assembler olduğu için bu programlar güncel bilgisayarlarda doğrudan çalıştırılamaz. Sonraki derslerde Visual Studio'nun sağladığı assembler ile assembly dosyaları kullanılacaktır; Microsoft assembler kullanıldığı için sözdizimi MASM sözdizimidir. Linux tarafında NASM vardır ve sözdizimi MASM'e benzer. Linux'ta yüzde işaretli yazımla kullanılan farklı bir assembler sözdizimi de vardır. Kısacası hangi assembler kullanılıyorsa onun sözdizimine uyulur.

Hoca, Visual Studio'da derlenebilecek programların 32 ya da 64 bitlik olacağını, 32 bitlik assembler'da derste anlatılan BX, SI, DI gibi yazmaçların yerine ESI, EDI, EBX gibi genişletilmiş yazmaçların kullanılacağını, bu yüzden mantığın biraz değişip karmaşıklaşacağını ve bu konulara da değinileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Hocanın "yüzde işaretli" dediği sözdizimi büyük olasılıkla AT&T sözdizimidir. GNU assembler'ın (GAS) varsayılanı olan bu yazımda yazmaçlar `%eax` gibi yüzde işaretiyle yazılır ve operand sırası MASM'in tersidir (önce kaynak, sonra hedef).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:45): 20 adres ucuna sahip 8086 mikroişlemcisi toplam ne kadar hafızaya erişebilir?

Çözüm (derste verildi): Her adres ucu 0 ya da 1 olabildiğinden $2^{20}$ hafıza gözü adreslenir. Her göz bir byte olduğu için hafıza uzayı $2^{20}$ byte = 1 MB'tır.

**Soru 2** (ekrandan, 00:15:00): 8086 I/O uzayı genişliği nedir?

Çözüm (derste verildi): Büyük port adresleri 16 bitlik DX ile verildiği için $2^{16}$ byte = 64 KB.

**Soru 3** (derste sözlü, 00:11:19): RAM'den okuma ya da RAM'e yazma yaparken hangi komut kullanılır? I/O cihazlarında hangileri kullanılır?

Çözüm (derste verildi): Hafıza için MOV: `MOV [100H], AX` yazma, `MOV AX, [100H]` okuma. I/O için IN ve OUT: `IN AL, 80H` okuma, `OUT 80H, AL` yazma.

**Soru 4** (ekrandan, 00:25:00): 77 onlu sayısını 8 bitlik ikilik sayıya çevirin.

Çözüm (derste verildi): Ardışık 2'ye bölmelerle kalanlar 1, 0, 1, 1, 0, 0 ve son bölüm 1 çıkar. Ters sırayla `1001101`, 8 bite tamamlanınca $(77)_{10} = (01001101)_2$.

**Soru 5** (ekrandan, 00:50:00): 100H adresinde FFH, 101H adresinde 12H bulunuyor. `MOV BX, 100H` ve `INC BYTE PTR [BX]` ile `MOV BX, 100H` ve `INC WORD PTR [100H]` gruplarının sonuçları nedir? Dolaylı adreslemede operandlardan biri yazmaç ise neden PTR gerekmez?

Çözüm (derste verildi): Birinci grupta yalnız 100H değişir ve 00H olur; 101H'te 12H kalır. İkinci grupta 12FFH + 1 = 1300H olur; 100H'ta 00H, 101H'te 13H bulunur. Operandlardan biri yazmaçsa işlemin boyutunu yazmacın genişliği belirlediği için PTR gerekmez.

**Soru 6** (derste sözlü, 00:57:53): Veri alanındaki bir değişkenin, o alanın başından itibaren offsetini nasıl alırız?

Çözüm (derste verildi): LEA (load effective address) ile, örneğin `LEA BX, dizi1`.

**Soru 7** (ekrandan, 01:00:00): `ndizi1 db 6` tanımlıyken aşağıdaki kodda teknik hata nedir? Tanımı bozmadan nasıl düzeltilir?

```asm
    MOV CX, ndizi1
    LEA BX, dizi1
L1: MOV AL, [BX]
    INC BX
    LOOP L1
```

Çözüm (derste verildi): CX 16 bitlik, ndizi1 byte tipinde olduğu için `MOV CX, ndizi1` hatalıdır. Düzeltme: `XOR CX, CX` ve `MOV CL, ndizi1` (ekrandan, 01:05:00). `MOV AL, [BX]` ve `INC BX` satırlarında sorun yoktur.

**Soru 8** (derste sözlü, 01:05:11): `dizi2 dw 1000H, 1001H, ...` dizisini `L1: MOV AX, [SI]`, `INC SI`, `LOOP L1` ile dolaşırsak ne olur? Nasıl düzeltilir?

Çözüm (derste verildi): Word elemanlar 2 byte olduğundan `INC SI` sonrası SI bir elemanın ortasını gösterir. İkinci okumada düşük byte 10H, yüksek byte 01H, yani 0110H okunur; dizide böyle bir eleman yoktur. Düzeltme `ADD SI, 2`'dir; o zaman ikinci okuma 1001H olur.

**Soru 9** (ekrandan, 01:40:00): 200H adresindeki `JMP 0FFH` komutu IP değerini neden 1 azaltır?

Çözüm (derste verildi): Operand 1 byte işaretli bir sayıdır. 0FFH = `1111 1111`'in en yüksek biti 1'dir, yani negatiftir. İkiye tümleyeni `0000 0001` olduğundan değer −1'dir. IP = 200H − 1 = 1FFH.

**Soru 10** (ekrandan, 01:45:00): `PUSH BL` doğru mu?

Çözüm (derste verildi): Hayır. PUSH yığına her zaman word basar. BL'yi yığına atmak için BX'in üst kısmı sıfırlanır (BX sıfırlanıp değer BL'ye konur) ve BX basılır.

## Dersin Toparlaması

Bu derste 8086 komut kümesinin son grupları tamamlandı: IN ve OUT ile port erişimi ve $M/\overline{IO}$ ucunun hafıza ve I/O uzaylarını ayırması, HLT, NOP ve WAIT, BCD ile ikilik gösterim arasındaki fark. Ardından adresleme modları üç grup halinde incelendi. Veri adreslemede köşeli parantez içinde hangi yazmaçların kullanılabileceği (BX, SI, DI ile DS; BP ile SS), PTR'nin ne zaman gerektiği ve word dizilerde indisin 2 artırılması gerektiği örneklerle gösterildi. Program hafızası adreslemede CS ve IP'nin doğrudan, göreli (işaretli yer değiştirme) ve dolaylı olarak nasıl değiştiği, yığın adreslemede ise PUSH/POP'un word ile çalışması ve SP'nin hareketi görüldü.

Dersin son bölümünde MASM sözde komutları ele alındı. LST dosyası üzerinden sözde komutların makine kodu üretmediği, little endian yerleşim, EXE ve COM program yapıları, EXTRN/PUBLIC, makro ve prosedür farkı ile LABEL, LENGTH, TYPE ve SIZE gibi kelimeler incelendi. Sonraki derslerde örnek problemler birlikte yazılıp derlenecek, LST dosyası ve debug programı üzerinden incelenecek; DOSBox ve MASM ortamının kullanımına da bakılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
