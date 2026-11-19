# Ders 3 Genişletilmiş Notu: Aritmetik Komutlar ve Dallanma Komutları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Veri Aktarım Komutları
- 2. Aritmetik Komutlara Genel Bakış
- 3. ADD Komutu ve PTR Kullanımı
- 4. ADC ve 32 Bitlik Toplama
- 5. SUB ve SBB
- 6. INC ve DEC
- 7. NEG: İkiye Tümleyenle Negatif Alma
- 8. CMP Komutu ve Bayraklar
- 9. İşaretli Aralık, Overflow ve Carry
- 10. MUL ve IMUL
- 11. DIV ve IDIV
- 12. Komut Süreleri ve XOR ile Sıfırlama
- 13. Dallanma Komutlarına Giriş
- 14. Koşullu Dallanma Komutları
- 15. İşlemci Koşullara Nasıl Karar Verir
- 16. Koşulsuz Dallanma, Çağırma ve Dönüş Komutları
- 17. If-Then-Else Yapılarını Assembly ile Kurmak
- 18. Yığın Üzerine Bir Soru
- 19. Gelecek Haftaya Giriş
- 20. Overflow Üzerine Son Bir Örnek
- Örnek Sorular

## 1. Önceki Dersin Tekrarı: Veri Aktarım Komutları

Hoca derse bir önceki haftanın kısa bir tekrarıyla başladı. Geçen hafta 8086'nın genel komut yapısı görülmüş, ardından veri aktarım komutlarına girilmişti:

- **MOV:** İki birim arasında veri taşır. Bu birimler iki yazmaç ya da bir yazmaç ile bir bellek gözü olabilir.
- **LEA (Load Effective Address):** Bir değer değil, bir adres (pointer) döndürür.
- **LDS:** İlgili yazmacı ve DS'yi, verilen adresteki değerlerle doldurur.
- **LES:** Aynı işi ES (extra segment) ile yapar.
- **XCHG (Exchange):** İki operandın değerlerini takas eder (swap).
- **XLAT (Translate):** Bir tablo içinde kaçıncı değerle ilgileniyorsak o değerin dönüşüm karşılığını verir.

Bu hafta aritmetik komutlarla devam edildi.

## 2. Aritmetik Komutlara Genel Bakış

Derste işlenen aritmetik komutlar şunlardır:

- **ADD:** Toplama.
- **ADC (Add with Carry):** Elde (carry) ile birlikte toplama.
- **SUB (Subtract):** Çıkarma.
- **SBB (Subtract with Borrow):** Borç ile birlikte çıkarma.
- **INC (Increment):** Bir artırma.
- **DEC (Decrement):** Bir azaltma.
- **NEG (Negate):** Bir sayının negatifini alma. Bu işlem ikiye tümleyen (two's complement) mantığıyla yapılır.
- **CMP (Compare):** Karşılaştırma. Arkasında çıkarma işlemi yatar: işlemci iki değeri karşılaştırırken aslında birini öbüründen çıkarır ve bayrakları değiştirir.
- **MUL ve IMUL:** Çarpma. MUL işaretsiz, IMUL işaretli sayılarla çalışır. IMUL'da hem girdiler hem sonuç işaretli sayı olarak değerlendirilir.
- **DIV ve IDIV:** Bölme. DIV işaretsiz, IDIV işaretli sayılarla çalışır.

## 3. ADD Komutu ve PTR Kullanımı

ADD iki parametre alır: destination (hedef) ve source (kaynak). İki parametreyi toplar ve sonucu tekrar hedefe yazar (ekrandan, 00:15:00):

$$\text{dest} \leftarrow \text{dest} + \text{src}$$

Hoca bunun 8086'daki genel kural olduğunu hatırlattı: aksi belirtilmedikçe iki operandlı bir komut, iki parametre üzerinde işlem yapar ve sonucu ilk parametreye atar. Bu yüzden ilk parametreye destination denir.

Slayttaki geçerli kullanımlar şunlardır (ekrandan, 00:15:00):

- `ADD reg, idata`
- `ADD mem, idata` (PTR gerekli)
- `ADD reg, reg`
- `ADD reg, mem`
- `ADD mem, reg`

### 3.1 Yazmaç ile sabit değer

`reg` herhangi bir yazmaç, `idata` ise immediate data (sabit değer) demektir. Hoca slayta iki örnek yazdı (ekrandan, 00:15:00):

```asm
ADD AX, 0FFH
ADD CH, 'A'
```

İlkinde 16 bitlik AX yazmacı onaltılık (hexadecimal) bir sabitle toplanır. Sabit 8 bit gibi görünür, ama işlemci onu 16 bite tamamlayarak AX ile toplar. İkincisi 8 bitlik bir işlemdir: 'A' karakteri immediate data olarak verilmiştir. Bunun ASCII karşılığı CH'deki değerle toplanır ve sonuç yine CH'de birikir.

### 3.2 Bellek ile sabit değer: PTR zorunluluğu

`ADD mem, idata` biçiminde bir bellek adresi ile bir sabit toplanır. Burada işlemin 8 bitlik mi 16 bitlik mi olacağı anlaşılamaz, bu yüzden mutlaka belirtilmelidir. Hoca bunu emu8086 üzerinde gösterdi.

DS = 0100H iken DS:0010H adresine bakıldı. Bu adreste ve bir sonrakinde başlangıçta 90H değerleri vardı (ekrandan, 00:20:00). Hoca önce küçük bir değer ekleyerek bu baytın 9AH olduğunu gösterdi.

<!-- BELİRSİZ: İlk denemede eklenen sabit altyazıda anlaşılmıyor. 90H'yi 9AH yapan değer büyük olasılıkla 0AH'dir. -->

Sonra eklenen sabit 0FFH yapıldı:

```asm
ADD BYTE PTR [10H], 0FFH
```

Bayt toplamada $90_{16} + FF_{16} = 18F_{16}$ olur. Bayta yalnız 8FH sığar, taşan 1 ise elde bayrağına (CF) gider. Hoca bayrak penceresinde CF = 1 olduğunu gösterdi. Yalnız 0010H ofsetindeki bayt değişti.

Aynı işlem WORD PTR ile tekrarlandı (ekranda emülatör komutu `ADD w.[00010h], 00FFh` olarak görünüyor, ekrandan, 00:20:00):

```asm
ADD WORD PTR [10H], 0FFH
```

Bu kez 0010H ve 0011H adreslerindeki iki bayt bir sözcük (word) olarak alınır: 9090H. Hesap şöyledir:

- Verilen: [0010H] = 90H, [0011H] = 90H, yani sözcük 9090H. Eklenen 00FFH.
- İşlem: $9090_{16} + 00FF_{16} = 918F_{16}$.
- Sonuç: Bellekte 0010H adresinde 8FH, 0011H adresinde 91H görünür. CF = 0 kalır, çünkü 16 bitlik toplam taşmaz. Düşük baytta oluşan elde bir sonraki bayta geçmiştir.

Hoca bellekteki görüntünün "8F 91" olduğunu, ama değerin little endian düzeninde yerleştirildiği için gerçek sonucun 918FH olduğunu vurguladı.

> **Hocanın vurgusu:** Burada "varsayılan değer şudur" diye bir kabul yoktur. PTR gereken işlemlerde tip belirtilmezse hoca bunu hatalı kabul edecek.

### 3.3 Yazmaç ile yazmaç

İki yazmaç toplanabilir, ama boyutları uyumlu olmalıdır. Örneğin `ADD DX, DL` geçersizdir, çünkü 16 bitlik ve 8 bitlik yazmaçlar arasında tip uyumsuzluğu vardır.

### 3.4 Yazmaç ile bellek

`ADD BX, [10H]` komutu BX'in mevcut değeriyle DS'nin 10H ofsetindeki sözcüğü toplar ve sonucu BX'e yazar. Bu komutun başına örtük olarak WORD PTR gelir. Çünkü işlem 16 bitlik BX üzerinden yapılır. Benzer şekilde `ADD [10H], BX` de geçerlidir. Bu kez sonuç DS:0010H adresindeki 16 bitlik değere yazılır, örtük olarak yine WORD PTR'dir.

**Soru:** Bellek parametresi destination'da da olsa source'da da olsa WORD PTR ya da BYTE PTR yazma durumu değişir mi?

**Cevap:** `reg, mem` ve `mem, reg` biçimlerinde bellek hangi tarafta olursa olsun fark etmez. İkinci operand yazmaç olduğu için işlemin genişliği bellidir, yazılan yazmacın boyutunda işlem yapılır. `mem, idata` biçiminde ise sabit 8 bite sığıyorsa bellekteki işlemin 8 bit mi 16 bit mi olduğu anlaşılamaz. İşte bu durumda PTR gereklidir.

## 4. ADC ve 32 Bitlik Toplama

ADC, ADD ile aynı mantıkla çalışır. Tek farkı elde bayrağını da işleme katmasıdır (ekrandan, 00:25:00):

$$\text{dest} \leftarrow \text{dest} + \text{src} + CF$$

CF tek bitlik bir bayrak olduğu için yalnız 0 ya da 1 değerini alır. Geçerli kullanımlar ADD ile aynıdır, `ADC mem, idata` için yine PTR gerekir.

Hoca bu komutun nerede gerekli olduğunu bir soruyla açtı. 8086 varsayılan olarak 8 ve 16 bitlik toplama ve çıkarmayı destekler. Bir kütüphane yazıp 32 bitlik toplama tanımlamak istersek ne yaparız? Ekrandaki soru şuydu: "32 bit iki işaretsiz sayıyı toplayan assembly kodunu yazınız" (ekrandan, 00:30:00).

Bir öğrencinin önerisi üzerine çözüm fikri şöyle kuruldu. Her iki sayı da 32 bittir ve her biri yüksek anlamlı ve düşük anlamlı 16 bitlik iki sözcüğe ayrılır. Slaytta bu kısımlar MSb ve LSb olarak çizildi.

1. Önce iki sayının düşük anlamlı sözcükleri ADD ile toplanır. Bu, 32 bitlik toplamın düşük anlamlı 16 bitini verir.
2. Bu 16 bitlik toplama sırasında bir elde (CF) oluşabilir.
3. Yüksek anlamlı sözcükler ADC ile toplanır. Böylece düşük kısımdan gelen elde de yüksek kısma eklenir.

Sonuçta düşük sözcükler için ADD, yüksek sözcükler için ADC çalıştırılarak 32 bitlik bir toplam elde edilir.

## 5. SUB ve SBB

SUB da iki parametre alır, hedeften kaynağı çıkarır ve sonucu tekrar hedefe yazar. Kullanım biçimleri aynıdır: yazmaçtan sabit çıkarma, bellekten sabit çıkarma (PTR gerekli), yazmaçlar arası, yazmaç ile bellek arası.

SBB (Subtraction with Borrow) şöyle tanımlanır (ekrandan, 00:35:00):

$$\text{dest} \leftarrow \text{dest} - \text{src} - CF$$

Gerekçe ADC ile aynıdır. 32 bitlik sayılarda çıkarma yapmak istersek önce düşük anlamlı 16 bitler SUB ile çıkarılır. Çıkarma işlemlerinde CF borç (borrow) görevini görür. CF'nin 1 olması, küçük sayıdan büyük sayının çıkarıldığı anlamına gelir. Onaltılık çıkarmada bu, yüksek anlamlı kısımdan düşük kısma bir borç alındığı şeklinde düşünülebilir. Ardından yüksek anlamlı kısımlar bu borçla birlikte SBB ile çıkarılır. Daha geniş bit genişliklerinde de aynı mantık kullanılır.

## 6. INC ve DEC

### 6.1 INC

INC tek operand alır ve onu bir artırır:

$$\text{dest} \leftarrow \text{dest} + 1$$

Kullanımları `INC reg` ve `INC mem`dir. Bellekte PTR gerekir (ekrandan, 00:40:00).

Hoca emu8086'da önce BL'ye F0H yükleyip `INC BL` çalıştırdı. BL F1H oldu. Sonra BL'ye FFH yüklendi:

```asm
MOV BL, 0FFH
INC BL
```

Bir artırınca BL 00H'ye düştü ve CF değişmedi. Hoca bunu özellikle göstermek istedi: FFH'den sonra bir artırınca, 8 bite sığan değer 00H olur.

Bellek örneğinde önce 0010H adresine ABFFH yazıldı. Onaltılık sabit harfle başladığı için başına 0 konur:

```asm
MOV WORD PTR [10H], 0ABFFH
INC BYTE PTR [10H]
```

Bellekte FFH, ABH görüldü. `INC BYTE PTR` yalnız 8 bitlik işlem yaptığı için düşük bayt 00H oldu, ABH değişmedi. Aynı işlem `INC WORD PTR [10H]` ile yapıldığında ABFFH sözcüğü bir artırıldı. Düşük bayt 00H oldu, yüksek bayt da elde yüzünden bir artarak ACH oldu: sonuç AC00H. Burada da PTR'nin gerekli olduğu görülür.

### 6.2 COM şablonu ve ORG 100H üzerine bir not

Hoca bu arada emu8086'da "new" deyip COM tipi bir program seçilirse `ORG 100H` satırının geldiğini gösterdi. COM tipi programlar bulunduğu segmentin 100H ofsetinden itibaren yerleşmelidir. Bir işletim sisteminde derlenmiş programı çalıştırırken programın başlık (header) bilgileri, örneğin geri dönüş değerleri ve programın özellikleri, 0 ile 100H arasındaki bölgede tutulur. EXE ve COM programlarının davranışı farklıdır. Bunlar ilerideki derslerde görülecek. Şimdilik herhangi bir şablon seçmeden doğrudan yazarak başlanabilir.

### 6.3 DEC

DEC değeri bir azaltır, yazmaç ya da bellek üzerinde çalışır. Bellek adreslemesi doğrudan ya da dolaylı olabilir, ama bellek kullanıldığında WORD mü BYTE mı olduğu mutlaka belirtilmelidir.

> **Hocanın vurgusu:** Bellek adresi verildiğinde işlemin WORD mü BYTE mı olduğu belirtilmelidir. Belirtilmesi gerekirken belirtilmezse yanlış kabul edilecek.

Örnekte BL = 0 iken `DEC BL` çalıştırıldı ve BL FFH'ye döndü. 8 bitlik bir yazmaç olduğu için tekrar FFH olur. Aynı işlem BX = 0000H iken yapıldığında BX = FFFFH oldu. 16 bitlik FFFFH işaretli sayı olarak −1'dir: sıfırdan 1 çıkarınca −1 bulunur.

## 7. NEG: İkiye Tümleyenle Negatif Alma

NEG, elimizdeki sayının ikiye tümleyene göre negatifini alır. Bu, her bitin değilini almaktan (bitwise NOT) farklıdır. Hoca ekrana kırmızıyla "NEG ≠ LOGICAL BITWISE NOT" yazdı (ekrandan, 00:45:00).

> **Hocanın vurgusu:** Bu çok önemli bir nokta. NEG ikiye tümleyen olarak negatif alır, mantıksal bitwise NOT ise her bitin bire göre tümleyenini alır. İkisi birbirinden farklıdır.

Örnek:

```asm
MOV BL, 0FFH
NEG BL
```

İşlemden sonra BL = 01H oldu. Açıklaması şöyledir:

- FFH bir bit dizisidir: 1111 1111. NEG bu diziyi işaretli sayı olarak değerlendirir.
- En yüksek anlamlı bit 1 olduğuna göre sayı negatiftir.
- Genliği bulmak için ikiye tümleyen alınır: ilk 1 görülene kadar bitler olduğu gibi bırakılır, kalanların bire göre tümleyeni alınır. Sonuç 0000 0001, yani sayı −1'dir.
- −1'in negatifi +1'dir: 0000 0001.

Aynı diziye bitwise NOT uygulansaydı her 1 yerine 0 yazılırdı ve sonuç 0000 0000 olurdu. Bir öğrencinin belirttiği gibi NEG'in eşdeğeri NOT + 1'dir. Bu zaten ikiye tümleyenin tanımıdır: önce bire göre tümleyen al, sonra 1 ekle.

## 8. CMP Komutu ve Bayraklar

### 8.1 CMP ile SUB arasındaki fark

CMP de iki parametre alır: destination ve source. Hedeften kaynağı çıkarır (ekrandan, 00:50:00):

$$\text{dest} - \text{src}$$

SUB da hedeften kaynağı çıkarır, ama sonucu hedefe yazar. CMP'de ise sonuç hesaplanır ama hiçbir yere yazılmaz. Sonuç saklanmadığı için yalnız bayraklar etkilenir. Slayttaki ifadeyle: "Sonuç saklanmaz, bayraklar etkilenir."

Bayraklar, koşullu dallanma komutları için koşul oluşturur. CMP'den sonra hedef kaynaktan büyük mü, büyük eşit mi, eşit mi, küçük eşit mi, küçük mü diye sorgulanabilir. Hoca burada bir yanlış anlamayı düzeltti: koşullu dallanmalar yalnız CMP ile oluşturulmaz. CMP bunu sağlayan komutlardan biridir. SUB da aynı işi görür. Aritmetik ve mantık komutlarından sonra da koşullu dallanma yapılabilir. Sonucu saklamak istemiyor, yalnız büyüklük ve küçüklük karşılaştırması yapmak istiyorsak CMP kullanılır.

CMP'nin kullanımları: yazmaç ile sabit, bellek ile sabit (PTR gerekli), yazmaçlar arası, yazmaç ile bellek (iki yönde de).

### 8.2 İlk örnek: 40H ve 20H

Hoca emu8086'da şu kodu çalıştırdı:

```asm
MOV AL, 40H
MOV BL, 20H
CMP AL, BL
CMP BL, AL
```

MOV komutlarından sonra hiçbir bayrak değişmedi. Bu, geçen hafta söylenen "veri aktarım komutları bayrakları etkilemez" kuralının gözlemidir.

`CMP AL, BL` 40H − 20H yapar. Büyük sayıdan küçük sayı çıkarıldığı için:

- Elde (borç) oluşmadı: CF = 0.
- Sonuç sıfır değil: ZF = 0.
- Sonuç pozitif: SF = 0.
- Sonuç 8 bitlik işaretli sayı olarak saklanabildiği için OF = 0.

CMP sonrasında AL ve BL bozulmadı, 40H ve 20H olarak kaldı. Bu yüzden aynı değerlerle `CMP BL, AL` çalıştırılabildi. Bu kez 20H − 40H yapılır:

- Küçük sayıdan büyük sayı çıkarıldığı için borç oluştu: CF = 1.
- Sonuç sıfır değil: ZF = 0.
- Sonuç −20H'dir, en yüksek anlamlı biti 1 olur: SF = 1.
- −20H 8 bitlik ikiye tümleyen sayı olarak gösterilebildiği için OF = 0.

> **Hocanın vurgusu:** Duymayan kalmasın: CMP komutu iki operandı birbirinden çıkarır, hedeften kaynağı çıkarır, sonucu saklamaz, yalnız bayrakları günceller.

### 8.3 En küçük negatif 8 bitlik sayı

Hoca bir sonraki örnek için BL'ye çok küçük bir negatif değer koymak istedi ve sınıfa 8 bitlik ikiye tümleyen gösterimde yazılabilecek en küçük negatif sayıyı sordu. İlk cevap FFH oldu. Hoca FFH'nin −1, yani negatif sayıların en büyüğü olduğunu söyledi. Sonunda doğru cevap 80H geldi.

80H'nin neden en küçük olduğu şöyle görülür:

- 80H = 1000 0000. En yüksek anlamlı bit 1 olduğu için sayı negatiftir.
- Genliği bulmak için ikiye tümleyen alınır: önce bire göre tümleyen 0111 1111, sonra 1 ekleyince 1000 0000 = 128.
- Demek ki 80H = −128'dir. 8 bitlik ikiye tümleyen aritmetikte yazılabilecek en küçük sayı budur.

### 8.4 İkinci örnek: 40H ve 80H

BL = 80H yapılarak kod yeniden çalıştırıldı:

```asm
MOV AL, 40H
MOV BL, 80H
CMP AL, BL
CMP BL, AL
```

Hoca önemli bir noktaya dikkat çekti. Şu ana kadar, CMP dahil hiçbir işlemde değerler işaretli ya da işaretsiz diye yorumlanmadı. İşlemci bunları yalnız bit dizisi olarak işler. İşaretli mi işaretsiz mi yorumlanacakları, sonra kullanılacak koşullu dallanma komutuyla ortaya çıkar.

40H'nin onlu karşılığı 4 × 16 = 64'tür. Hoca bunu Windows hesap makinesinin programlayıcı modunda da gösterdi.

`CMP AL, BL` sonrasında ekranda CF = 1, ZF = 0, SF = 1, OF = 1 görüldü (ekrandan, 01:05:00).

- **SF = 1:** Sonucun en yüksek anlamlı biti 1'dir.
- **OF = 1:** İşaretli olarak $64 - (-128) = 64 + 128 = 192$ bulunur. Bu değer +127'yi aştığı için 8 bitlik işaretli aralığa sığmaz.
- **ZF = 0:** Sonuç sıfır değildir.
- **CF = 1:** Elde (borç) oluşmuştur.

> **Ders sonrası not:** Hoca CF'yi açıklarken önce sonucun 8 biti taşırdığını söyledi, sonra "taşırmıyor" diyerek düzeltti ve komut tablosuna baktı. Açık hâli şudur: 8 bitlik sonuç $40_{16} - 80_{16} = C0_{16}$'dir. CF = 1 olmasının nedeni, işaretsiz bakışla 64'ten 128 çıkarılırken borç gerekmesidir. CF işaretsiz, OF işaretli yoruma göre oluşur.

Ters yönde `CMP BL, AL` 80H − 40H yapar. 80H işaretli olarak −128'dir, yani işlem $-128 - 64 = -192$ olur. Sonuç −128'in ötesine, negatif yönde taşar ve OF yine 1 olur. Bu işlem −128 ile −64'ün toplamı gibi de düşünülebilir. Hoca bunu ikilik olarak gösterdi:

- −128 = 1000 0000.
- 64 = 0100 0000. −64'ü bulmak için ilk 1 görülene kadar bitler olduğu gibi bırakılır, sonra bire göre tümleyen alınır: 1100 0000.
- Toplam: 1000 0000 + 1100 0000 = (1) 0100 0000.

İki negatif sayı toplandığı hâlde sonucun en yüksek anlamlı biti 0 çıktı, yani sonuç pozitif göründü. Bu da overflow durumunun bir karşılığıdır.

### 8.5 İşaret ne zaman belirlenir?

**Soru:** Sayıların signed mı unsigned mı olduğuna ne zaman karar veriliyor? Bu yalnız compare için mi geçerli?

**Cevap:** Hoca komut tablosunda SUB ve CMP'nin "twos complement arithmetic" ile işlem yaptığının yazdığını gösterdi. İki aşama vardır ve peş peşe gerçekleşir. Birincisi, CMP çıkarmayı ikiye tümleyen aritmetiğinde yapar ve bayrakları belirler. İkincisi, çıkan bit dizisinin işaretli mi işaretsiz mi değerlendirileceğine kullanıcı, sonra kullandığı koşullu dallanma komutuyla karar verir. Örneğin JA (jump above) sonucu işaretsiz değerlendirir, JG (jump greater) işaretli değerlendirir. Bayraklar belirlendikten sonra çıkan bit dizisine ayrıca bakmaya gerek yoktur, bayraklara bakmak yeterlidir.

Bir başka soruya hoca, ADD'nin işaretsiz sayılarla işlem yaptığını, tabloda ADD için ikiye tümleyen ifadesinin yer almadığını, SUB komutlarında ise yer aldığını söyledi.

> **Ders sonrası not:** Hoca ADD'nin işaretsiz, SUB'ın ikiye tümleyene göre çalıştığını ve işaretsiz sayı kabul eden bir SUB olmadığını söyledi. Doğrusu: ikiye tümleyen gösteriminde toplama ve çıkarma, işaretli ve işaretsiz sayılar için aynı bit işlemidir. ADD de SUB da işaretsiz yorum için CF'yi, işaretli yorum için OF'yi aynı anda günceller. Sonucun nasıl yorumlanacağını, hocanın da söylediği gibi, sonraki dallanma komutu belirler.

## 9. İşaretli Aralık, Overflow ve Carry

Hoca bu örnekler sırasında bayrakların hangi duruma göre oluştuğunu toparladı:

- **OF (overflow):** İşaretli sayı işlemi için oluşur. Sonuç işaretli olarak ilgili genişliğe sığmıyorsa OF = 1 olur.
- **CF (carry):** İşaretsiz sayı işlemi için oluşur. Sonuç işaretsiz olarak aralığa sığmıyorsa CF = 1 olur.
- **ZF (zero):** İşlem sonucu sıfırsa 1 olur.
- **SF (sign):** Yalnız sonucun en yüksek anlamlı bitine bakar.

8 bitlik aralıklar şöyledir:

- İşaretsiz: 0000 0000 = 0 ile 1111 1111 = 255 arası.
- İşaretli: −128 ile +127 arası. Bunun dışına taşan her değer gösterilemez ve overflow oluşur.

> **Hocanın vurgusu:** CF'yi hesaplamak istiyorsak işlemin işaretsiz karşılığına, OF'yi hesaplamak istiyorsak işaretli karşılığına bakılır.

## 10. MUL ve IMUL

### 10.1 MUL: İşaretsiz çarpma

MUL tek bir açık parametre alır, ama iki gizli operandı vardır: AX ve DX. Hangisinin kullanılacağı verilen kaynağın bit genişliğine bağlıdır (ekrandan, 01:20:00):

- Kaynak 8 bit ise: $AX \leftarrow AL \times \text{src}$.
- Kaynak 16 bit ise: $DX{:}AX \leftarrow AX \times \text{src}$.

16 bitlik durumda sonuç 32 bit olabilir. İşlemci DX ve AX'ten 32 bitlik sanal bir yazmaç oluşturur: DX yüksek anlamlı 16 biti, AX düşük anlamlı 16 biti tutar. Komut yazmaçla (`MUL reg`) ya da bellekle (`MUL mem`) kullanılabilir. Bellekte WORD mü BYTE mı olduğu PTR ile belirtilmelidir.

### 10.2 Örnek: 8 bitlik çarpmada AH'nin bozulması

Hoca ekrana şu kodu yazdı (ekrandan, 01:15:00):

```asm
MOV AX, 0F0FH
MOV BX, 1010H
MUL BL
```

Ekranda ilk satır `MOV AX, 00F0FH` olarak yazılmıştı. Bir öğrencinin uyarısıyla baştaki fazladan sıfır silindi.

- Kaynak BL 8 bit olduğu için 8 bitlik işaretsiz çarpma yapılır, sonuç AX'e yazılır.
- AL = 0FH, BL = 10H.
- $0F_{16} \times 10_{16} = 00F0_{16}$.
- Sonuç AX = 00F0H olur. Çarpım 8 bite sığdığı hâlde AX'in tamamına yazılır ve AH'deki 0FH kaybolur.

> **Hocanın vurgusu:** Buna mutlaka dikkat edin. Çarpım 8 bite sığsa da 8 bitlik çarpmanın sonucu AX'te saklanır. Bu, sınavlarda ve ödevlerde gözden kaçan bir durumdur.

### 10.3 Örnek: 16 bitlik çarpmada DX'in bozulması

DX'e de 1234H yüklendi ve komut `MUL BX` olarak değiştirildi:

```asm
MOV AX, 0F0FH
MOV BX, 1010H
MOV DX, 1234H
MUL BX
```

Hoca DX'e değeri, çarpmadan sonra DX'in de bozulduğunu göstermek için yükledi.

- Kaynak BX 16 bit olduğu için gizli operand AX'tir ve sonuç DX:AX'e yazılır.
- $0F0F_{16} \times 1010_{16} = 00F1E0F0_{16}$.
- Sonuç: DX = 00F1H, AX = E0F0H.

Hoca önce elle yanlış hesapladığını söyledi, sonra hesap makinesiyle doğruladı. DX'teki 1234H silindi, AX'in eski değeri bozuldu, yalnız BX değişmedi.

### 10.4 IMUL: İşaretli çarpma

IMUL (integer signed multiplication) aynı kurallarla çalışır: 8 bitlik kaynakta $AX \leftarrow AL \times \text{src}$, 16 bitlik kaynakta $DX{:}AX \leftarrow AX \times \text{src}$. Fark, girdilerin ve sonucun işaretli sayı olarak değerlendirilmesidir. Artık örneğin −2 ile 4 çarpılabilir. Sonuç kaç bite sığarsa sığsın, 16 bitlik kaynakta DX ve AX'e yazılır.

### 10.5 Örnek: MUL ile IMUL farkı

Hoca −1'in FFH ile gösterilebildiğini hatırlattı ve şu kodu yazdı (ekrandan, 01:25:00):

```asm
MOV AL, 0FFH
MOV BL, 4
MUL BL
```

MUL FFH'yi işaretsiz 255 sayar: $FF_{16} \times 4 = 3FC_{16} = 1020$. AX = 03FCH olur. Bu, 8 bite sığmayan ama 16 bite sığan bir sonuçtur.

Aynı kod `IMUL BL` ile çalıştırıldı. Ekrandaki açıklama satırları şöyleydi (ekrandan, 01:25:00):

```asm
MOV AL, 0FFH
MOV BL, 4

IMUL BL   ; AX <-- AL x BL = (-1) x 4 = (-4)
; FCH : 1111 1100B

; 00FCH olmadı
; FFFCH oldu neden?
```

Hoca önce −4'ün 8 bitlik karşılığını geriye sayarak buldu: −1 FFH, −2 FEH, −3 FDH, −4 FCH. Emülatörde ise AX = FFFCH çıktı. Hoca sınıfa bunun nedenini sordu.

Açıklama: Sonuç 16 bitlik AX'e yazılır. 00FCH olsaydı en yüksek anlamlı bit 0 olurdu ve sanki pozitif bir değer üretilmiş gibi anlaşılırdı. 8 bitlik FCH = 1111 1100'ü işaretli olarak 16 bite tamamlarken işaret biti alınır ve sola doğru tekrarlanır. İşaret biti 1 olduğu için sonuç 1111 1111 1111 1100 = FFFCH olur. Hoca bunu hesap makinesinde de gösterdi: byte modunda FF × 4 = FC, word modunda ise işaret biti 16 bite yayıldığı için FFFC görünür.

## 11. DIV ve IDIV

### 11.1 DIV: İşaretsiz bölme

DIV tek bir parametre alır ve iki sonuç üretebilir: bölüm ve kalan.

- **8 bitlik bölen:** Gizli operand AX, bölene bölünür. Bölüm AL'ye, kalan (modül) AH'ye yazılır.
- **16 bitlik bölen:** Bölünen DX ve AX'ten oluşan 32 bitlik sanal yazmaçtır. Yüksek anlamlı 16 bit DX'te, düşük anlamlı 16 bit AX'tedir. Bölüm AX'e, kalan DX'e yazılır.

Hoca bunun mantıklı olduğunu söyledi: 32 bitlik bir değer 16 bitlik bir değere bölündüğünde bölüm ve kalan için 16 bitlik yazmaçlar yeterlidir. 16 bitlik bölmeden önce DX ve AX'e istenen değerler mutlaka yazılmış olmalıdır.

Hoca geçen haftayı da hatırlattı: 8086'da açıkça üç operandlı hiçbir komut yoktur. Ama gizli operandlı bazı komutlar, açık operandla birlikte toplam üç farklı yazmaçta okuma ve yazma yapabilir. DIV bunun örneklerinden biridir. Parametre yazmaç ya da bellek olabilir, bellekte PTR ile BYTE mı WORD mü olduğu belirtilmelidir.

### 11.2 Örnek: Bölümün sığmaması

Hoca 8 bitlik bir bölme yazdı. Ekranda yazılmaya başlanan kod (ekrandan, 01:30:00) altyazıya göre şu hâle getirildi:

```asm
MOV AX, 0F0F0H
MOV BL, 0F0H
DIV BL
```

Önce elle hesaplandı: F0F0H ÷ F0H. İlk F0'da F0 bir kere vardır, çıkarılınca 0 kalır. Sonraki basamak indirilir, F0'da F0 yoktur, 0 yazılır. Son F0'da yine bir kere vardır. Sonuç 101H, kalan 0'dır. Hesap makinesi de 101H verdi.

Hoca sınıfa, AL'de 101H ve AH'de 0 bekleyip bekleyemeyeceğimizi sordu. Komut çalıştırıldığında emülatör beklenmedik bir yere gitti. Bölüm 101H, 8 bitlik AL'ye sığmadığı için işlemci hatayı ele alan kesme programına gitmişti.

> **Hocanın vurgusu:** Bölüm sonucunu sığdırmak zorunda değiliz. Ama sığmadığını bilmeli ve buna göre "bu işlem sonucu hatalıdır" diye bir aksiyon almalıyız. Bunun nasıl yapılacağı sonraki haftalarda görülecek.

> **Ek bilgi (derste anlatılmadı):** 8086'da bölüm hedef yazmaca sığmadığında ya da sıfıra bölündüğünde "divide error" denen 0 numaralı kesme oluşur. Hocanın "overflow ile ilgili kesme" dediği durum büyük olasılıkla budur. Bu kesme, overflow bayrağına bağlı INTO'dan (4 numaralı kesme) farklıdır.

### 11.3 Örnek: Çalışan bir bölme

AX = 0B0F0H yapılarak tekrar denendi (ekrandan, 01:35:00):

```asm
MOV AX, 0B0F0H
MOV BL, 0F0H
DIV BL
```

Sonuçta AL = BCH (bölüm), AH = B0H (kalan) oldu. Hoca hesap makinesiyle doğruladı: $B0F0_{16} \div F0_{16} = BC_{16}$. $BC_{16} \times F0_{16} = B040_{16}$ ve $B0F0_{16} - B040_{16} = B0_{16}$, yani kalan B0H'dir.

### 11.4 100H'ın karesi

Hoca bir soru sordu: 100H'ın karesi nasıl alınır, kaç bitlik bir çarpma gerekir? Bir öğrencinin önerdiği çözüm doğruydu. 100H 8 bitten fazla yer kapladığı için AL'ye sığmaz, bu yüzden 16 bitlik çarpma yapılmalıdır:

```asm
MOV AX, 100H
MUL AX
```

Sonuç DX:AX'tedir: DX = 0001H, AX = 0000H. Yani $100_{16}^2 = 10000_{16}$.

### 11.5 10000H / 100H

Ardından bu sonucun 100H'a bölünmesi istendi. 16 bitlik bölme için önce DX ve AX'te uygun değerler hazırlanmalıdır. Ekrana "10000H/100H" yazıldı (ekrandan, 01:40:00). 10000H yüksek ve düşük anlamlı kısımlarına ayrılır: düşük 16 bit 0000H, yüksek 16 bit 0001H.

AX'i sıfırlarken hoca XOR konusuna geçti (bkz. Bölüm 12). Sonuçta kod şöyle kuruldu:

```asm
XOR AX, AX      ; AX = 0000H (düşük 16 bit)
MOV DX, 1       ; DX = 0001H (yüksek 16 bit)
MOV BX, 100H
DIV BX          ; DX:AX / BX
```

Hoca önce DX'e 10H yazdı ve sonuçta beklenmeyen bir değer çıktı. Hata, DX'e olması gerekenden büyük bir değer atanmasıydı: DX'te 10H olursa bölünen 100000H olur. Düzeltildikten sonra AX = 0100H (bölüm), DX = 0 (kalan) bulundu.

### 11.6 IDIV

IDIV (integer signed divide) işaretli sayılarda bölme yapar, mantık DIV ile aynıdır (ekrandan, 01:45:00):

- Kaynak 8 bit ise: $AL \leftarrow AX / \text{src}$, $AH \leftarrow AX \% \text{src}$.
- Kaynak 16 bit ise: $AX \leftarrow DX{:}AX / \text{src}$, $DX \leftarrow DX{:}AX \% \text{src}$.
- Sonuç ve operandlar işaretli sayı olarak değerlendirilir. Bellek operandında PTR gerekir.

Böylece aritmetik komutlar bitti ve derse ara verildi.

## 12. Komut Süreleri ve XOR ile Sıfırlama

### 12.1 MOV ile XOR karşılaştırması

AX'i sıfırlamanın iki yolu vardır. Biri `MOV AX, 0`, yani AX'e doğrudan sıfır sabitini atamaktır. Hoca komut tablosunu (1to1_instruction.pdf, "A Summary of 8086 and 8088 Instructions", ekrandan, 01:40:00) açıp 16 bitlik yazmaca sabit atayan MOV satırını buldu: 4 clock cycle sürüyordu. Sonra 16 bitlik iki yazmaçla çalışan XOR satırına baktı: 3 clock cycle sürüyordu.

Hoca sınıfa, 3 clock cycle süren XOR'dan yararlanarak MOV'un yaptığı işin aynısını yapıp yapamayacağımızı sordu. Cevap `XOR AX, AX` oldu.

XOR henüz işlenmediği için hoca doğruluk tablosunu çizdi:

| x | y | z = x XOR y |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Girdiler bit bazında aynıysa çıkış sıfırdır. Bir sayı kendisiyle bitwise XOR'landığında her bit kendisiyle eşit olduğu için sonuç sıfır olur. Hoca örnek olarak 1001 0101 dizisini kendisiyle XOR'ladı. Bir öğrencinin sorusuna da şöyle cevap verdi: sıfırla XOR'lamak sayıyı değiştirmez, sonuç yine AX olur. Ama AX'i kendisiyle XOR'lamak AX'i sıfırlar.

> **Hocanın vurgusu:** Aynı işi yapan farklı komutlar olabilir. Bunlardan clock cycle değeri daha düşük olanları tercih etmeliyiz. Büyük ve çok tekrarlanan bir kodda yazmaç sıfırlamak için MOV yerine XOR kullanmak zaman kazandırır.

### 12.2 Etkin adres hesabının süresi

Tablodaki bazı satırlarda "+EA" yazar. Bellek adresini hesaplamak için ek clock cycle gerekir ve bu süre tablodaki değere eklenir. Hoca etkin adres tablosundan şunları okudu: yalnız BX, BP, SI ya da DI'dan biri verilirse 5, taban ve indis birlikte verilirse 7 clock eklenir.

> **Ders sonrası not:** Hoca doğrudan yer değiştirme (displacement) verildiğinde 9 clock eklendiğini söyledi. 8086 tablolarında yalnız yer değiştirme için büyük olasılıkla 6 clock, yer değiştirme ile birlikte bir taban ya da indis yazmacı için 9 clock verilir.

### 12.3 Bir komut kaç saniye sürer?

**Soru:** 4 clock cycle yaklaşık kaç saniyeye denk gelir, hesaplanabilir mi?

**Cevap:** Hoca hesaplanabileceğini söyledi. Bir saat darbesinin süresi frekansın tersidir: $T = 1/f$. Hoca 8086'ya en fazla 2 MHz'lik kristal bağlanabileceğini, daha düşük frekansların da kullanılabileceğini söyledi. Bu tür hesapların özellikle yazılımla bekleme yapan işlerde ve bir fonksiyonun ne kadar sürede döneceğini bulmakta kullanıldığını ekledi. Hoca hesapta bir saat darbesi için 0,2 µs, bir komut adımı için 0,8 µs buldu ve geçen haftaki T1–T4 adımlarını hatırlatarak bunu clock sayısıyla çarptı.

> **Ders sonrası not:** Hocanın sayısal hesabı hatalıdır. 2 MHz'te bir saat periyodu $T = 1/(2 \times 10^6)\ \text{s} = 0{,}5\ \mu s$'dir. Komut süresi, tablodaki clock sayısı ile periyodun çarpımıdır: $4 \times 0{,}5\ \mu s = 2\ \mu s$. Tablodaki değer zaten clock sayısı olduğu için ayrıca T1–T4 adımlarıyla çarpılmaz. Ayrıca 8086 büyük olasılıkla 5 MHz ve üzeri (8 ve 10 MHz sürümleri dahil) saat frekanslarıyla üretilmiştir, 2 MHz bir üst sınır değildir.

Aradan sonra bir öğrenci DIV slaytını yeniden görmek istedi. Hoca XOR ile sıfırlama meselesini de bir kez daha baştan anlattı.

## 13. Dallanma Komutlarına Giriş

Dallanma komutları temel komut gruplarından biridir. Hoca, bilgisayar donanımı dersinde bir mikroişlemci tasarlanırken de bu komut grubunun mutlaka bulunması ve buna özel tasarım yapılması gerektiğini söyledi. Dallanma programlamanın gereğidir: koşullar oluşturup kontrol ederek programlar yazarız. Hoca ilgilenenlere "dallanmasız programlama" (branchless programming) kavramına bakmalarını tavsiye etti, ama bu konu dersin kapsamında değildir.

Normalde, koşullu ya da koşulsuz bir dallanma yoksa, her komuttan sonra IP (instruction pointer) o komutun bellekte kapladığı bayt sayısı kadar artar. Böylece bir sonraki komutu gösterir. IP'nin bu artımlı ilerleyişini bozan her komut dallanma komutu sayılır. Dört başlık altında incelenir:

- **Koşulsuz dallanma:** JMP.
- **Koşullu dallanma:** Üç alt başlık:
  - Yalnız bir bayrağa bakan basit koşullu dallanmalar.
  - İşaretsiz sayı işlemlerinin sonucuna göre dallanmalar.
  - Sonucu işaretli sayı olarak değerlendiren dallanmalar.
- **Çağırma:** CALL, INT, INTO.
- **Dönüş:** RET, IRET (interrupt return).

## 14. Koşullu Dallanma Komutları

Slayttaki liste şöyleydi (ekrandan, 02:05:00):

| Basit koşullu dallanma | İşaretsiz sayı işlemlerinde | İşaretli sayı işlemlerinde |
|---|---|---|
| JE/JZ | JB/JNAE/JC | JL/JNGE |
| JNZ/JNE | JA/JNBE | JNL/JGE |
| JS | JAE/JNB/JNC | JLE/JNG |
| JNS | JBE/JNA | JG/JNLE |
| JO | | |
| JNO | | |
| JP/JPE | | |
| JNP/JPO | | |

### 14.1 Basit koşullu dallanmalar

Bunlar yalnız bir bayrağa bakar:

- **JZ (jump if zero):** Yalnız ZF'ye bakar. ZF = 1 ise komutun yanına parametre olarak verilen etikete dallanır. JE (jump if equal) bununla eşdeğerdir: önceki CMP ya da aritmetik işlemde ZF = 1 olduysa iki sayının eşit olduğu anlaşılır.
- **JNZ/JNE:** Sonuç sıfır değilse dallanır.
- **JS:** Sonuç negatifse, yani SF = 1 ise dallanır. **JNS:** SF = 0 ise dallanır.
- **JO:** OF = 1 ise dallanır. **JNO:** OF = 0 ise dallanır.
- **JP:** PF = 1 ise dallanır. **JNP:** PF = 0 ise dallanır.

> **Hocanın vurgusu:** JZ yalnız sıfır bayrağına bakar. ZF = 1 ise verilen etikete dallanır. Bu çok önemli.

### 14.2 Karşılaştırma dallanmaları

Öbür komutlar iki sayının birbirine göre durumuna bakar. Hemen öncesinde `CMP A, B` çalıştırıldığını düşünelim:

- A < B ise: JB (below) ya da JL (less).
- A > B ise: JA (above) ya da JG (greater).
- A ≥ B ise: JAE ya da JGE.
- A ≤ B ise: JBE ya da JLE.
- Eşitlik için zaten JE vardır.

Bu çiftler aynı işe bakar, aralarındaki fark sonucun nasıl yorumlandığıdır. İşaretsiz yorumda above/below kelimeleri (JA, JB, JAE, JBE), işaretli yorumda greater/less kelimeleri (JG, JL, JGE, JLE) kullanılır.

> **Ders sonrası not:** Hoca bir yerde "A ve B'yi işaretli sayı olarak değerlendirmek istiyorsam JB, JA, JAE, JBE kullanmalıyım" dedi. Hemen ardından işaretli için JL, JG, JGE, JLE'yi saydı ve sonra grupları doğru ayırdı. Doğrusu: JA, JB, JAE, JBE işaretsiz, JG, JL, JGE, JLE işaretli karşılaştırmalar içindir.

Slayttaki eğik çizgiden sonra verilen adlar da geçerli 8086 komutlarıdır ve yanlarındakiyle eşdeğer çalışır. Örneğin A'nın B'den küçük eşit olması (JBE) A'nın B'den büyük olmamasıyla (JNA) aynıdır. A'nın B'den büyük olması (JA) da A'nın B'den küçük eşit olmamasıyla (JNBE) aynıdır.

> **Hocanın vurgusu:** Eşdeğerleri ezberlemeye gerek yok. A'nın B'den büyük olduğu durumu yakalamak istiyorsak JA, büyük olmadığı durumu yakalamak istiyorsak JNA kullanırız. Neye ihtiyacımız varsa geçerli komutlardan onu seçeriz.

### 14.3 İşaretli ve işaretsiz yorum örneği

Hoca slayta şu örneği yazdı (ekrandan, 02:15:00): A ← FFH, B ← 1.

```asm
CMP A, B
JA etiket
```

JA sonucu işaretsiz yorumlar. FFH 255 olarak anlaşılır, 255 > 1 olduğu için dallanma gerçekleşir.

```asm
CMP A, B
JG etiket2
```

JG işaretli yorumlar. FFH −1 olarak anlaşılır. −1, 1'den büyük olmadığı için dallanma gerçekleşmez.

Koşullu dallanmanın nasıl çalıştığını göstermek için hoca şu yapıyı çizdi (ekrandan, 02:15:00):

```asm
CMP A, B
JG etiket2
NOP
NOP
etiket2: NOP
```

CMP çalıştıktan sonra JG'ye gelinir. Koşul sağlanmadığı için bir alt satıra geçilir, sonra yine bir alt satıra ve sonunda etiket2'nin bulunduğu satıra varılır. Yani koşul sağlanmasa bile, kodun yapısı gereği etiketin bulunduğu yere ulaşılabilir. Bir if-then-else düzgün bağlanmazsa bu istenmeyen sonuçlar doğurur.

> **Hocanın vurgusu:** Koşullu dallanmada koşul sağlanmışsa doğrudan etikete gidilir, sağlanmamışsa bir alt satırdaki komuta geçilir.

## 15. İşlemci Koşullara Nasıl Karar Verir

İşlemci "büyük", "küçük", "above", "below" durumlarını yalnızca bayraklara bakarak anlar. Slayttaki tablo şöyledir (ekrandan, 02:20:00):

| Durum (`CMP A, B` sonrası) | İşaretsiz sayılarda | İşaretli sayılarda |
|---|---|---|
| dest > src | CF = 0 VE ZF = 0 | ZF = 0 VE SF = OF |
| dest ≥ src | CF = 0 | SF = OF |
| dest = src | ZF = 1 | ZF = 1 |
| dest ≤ src | CF = 1 VEYA ZF = 1 | ZF = 1 VEYA SF ≠ OF |
| dest < src | CF = 1 | SF ≠ OF |

### 15.1 İşaretsiz sayılarda

`CMP A, B` A'dan B'yi çıkarır.

- **A > B:** Çıkarmada borç oluşmaz, yani CF = 0. Sayılar eşit olmadığı için ZF = 0. İkisi birden sağlanırsa işlemci A'nın B'den büyük olduğuna karar verir.
- **A ≥ B:** İki durum vardır. Ya A > B'dir (CF = 0, ZF = 0) ya da A = B'dir (CF = 0, ZF = 1). İki satır "veya" ile bağlıdır. İkisini birleştiren ortak koşul CF = 0'dır.
- **A = B:** Yalnız ZF'ye bakmak yeterlidir.
- **A ≤ B:** Ya A = B'dir (CF = 0, ZF = 1) ya da A < B'dir (CF = 1, ZF = 0). İkisinin mantıksal karşılığı CF veya ZF'nin 1 olmasıdır.
- **A < B:** ZF kesinlikle 0'dır. CF = 1 olması A'nın işaretsiz olarak B'den küçük olduğunu gösterir.

### 15.2 İşaretli sayılarda

A > B olabilmesi için iki durum vardır:

1. A ve B aynı işaretlidir ve sonuç 8 bitlik aritmetiğe sığar. Taşma olmadığı için OF = 0'dır. Sonuç pozitif olduğu için SF de 0'dır.
2. A büyük bir pozitif sayı, B küçük bir negatif sayıdır. A − B iki büyük pozitif sayının toplamı gibi davranır ve 8 bite sığmayabilir. Bu durumda OF = 1 olur. İki pozitif sayının toplamında taşma olunca sonuç negatif görünür, yani SF de 1 olur.

Her iki durumda SF = OF'dir ve sayılar eşit olmadığı için ZF = 0'dır. İşlemci A > B kararını ZF = 0 ve SF = OF koşuluyla verir. A ≥ B için SF = OF yeterlidir, ZF = 0 koşulu kalkar. Eşitlik için ZF = 1 yeterlidir.

A ≤ B, A > B'nin değilidir. De Morgan kuralıyla "ZF = 0 VE SF = OF" ifadesinin değili alınır: ZF = 0'ın tersi ZF = 1, eşitliğin tersi eşitsizliktir, VE ise VEYA'ya dönüşür. Sonuç: ZF = 1 VEYA SF ≠ OF. A < B de A ≥ B'nin (SF = OF) değilidir: SF ≠ OF.

## 16. Koşulsuz Dallanma, Çağırma ve Dönüş Komutları

### 16.1 JMP ve JMP FAR PTR

Hoca bunu iki segment çizerek anlattı. Çalıştığımız kod segmenti 64 KB'lık bir alandır. Programın yer alabileceği ikinci, ayrı bir segment daha olsun.

- Aynı segment içinde bir noktaya gideceksek (segment içi, intra segment) **JMP** yeterlidir. Yalnız offset değişir.
- Farklı bir segmentteki bir offsete, yani 64 KB'ın ötesindeki bir alana gideceksek hem segment hem offset değişmelidir. Bunun için **JMP FAR PTR** kullanılır.

Segment içi JMP'nin üç kullanımı vardır:

- **Yer değiştirme (displacement) ile:** 8 ya da 16 bitlik, ikiye tümleyen gösterimde bir değerdir. 8 bitte −128 adım geri ile +127 adım ileri arası gidilebilir. Burada IP'nin çevresinde ileri ya da geri bir öteleme yapılır.
- **Yazmaç ile (JMP reg):** Yazmaçtaki değer doğrudan IP'ye yüklenir.
- **Bellek ile (JMP mem):** Bellek gözündeki değer doğrudan IP'ye yüklenir.

Hoca son iki kullanımın bir tehlikesine dikkat çekti. Komutlar birden fazla bayt kapladığı için yazmaçtaki ya da bellekteki değer yanlışlıkla bir komutun tam ortasına denk gelebilir.

JMP FAR PTR'nin iki biçimi vardır (ekrandan, 02:30:00):

- `JMP FAR PTR idata1:idata2`: CS ← idata1, IP ← idata2.
- `JMP FAR PTR mem`: Bellekte peş peşe gelen iki sözcük IP ve CS'ye yüklenir, yani IP ← [mem], CS ← [mem + 2].

Hoca bunu emu8086'da göstermeye çalıştı ama emülatör komutu kabul etmedi. Sonra DOSBox'taki DEBUG ile bir JMP komutunu assemble etti ve izledi (trace). Başlangıçta IP = 0100H, CS = 073FH idi. JMP çalıştırıldığında CS verilen ilk değerle, IP ikinci değerle yüklendi. Derste DOSBox varsayılan ortam olarak kabul edildiği için hoca bunu geçerli bir komut saydı. Dersin ilerleyen kısmında bir öğrenci, emu8086'da JMP'den sonra fazladan "far" ve "ptr" yazıldığını hatırlattı ve hoca komutu buna göre düzeltip çalıştırdı.

<!-- BELİRSİZ: emu8086'da denenen komut ekranda kısmen "JMP FAR PTR 1234H:0ABCDH" gibi görünüyor ama assembler penceresiyle örtülü. DOSBox'ta verilen segment:offset değerleri altyazıda anlaşılmıyor ("100, mesela 200"). emu8086'da çalışan son biçim de altyazıdan tam çıkmıyor. -->

### 16.2 Çağırma komutları

CALL da aynı mantıkla çalışır. F1 ve F2 fonksiyonları etiketlerle belli olsun. F1 içinde F2 çağrılacaksa ve ikisi aynı segmentteyse yalnız `CALL etiket` yeterlidir. F1 içinde başka bir segmentteki F3 çağrılacaksa `CALL FAR PTR` kullanılır.

Slayttaki CALL biçimleri şunlardır (ekrandan, 02:50:00):

- CALL: near procedure call. Prosedür dönüşü RET ile yapılır. Yığına yalnız IP atılır.
- `CALL disp`: IP ← IP + disp.
- `CALL mem`
- `CALL reg`: IP ← reg.

<!-- BELİRSİZ: Slaytta CALL mem için "IP ← reg" yazıyor. Bu büyük olasılıkla slayt hatasıdır, doğrusu IP ← [mem] olmalıdır. -->

INT ve INTO kesme komutlarıdır. Bunlarla da farklı bir segmentteki farklı bir IP değerine gidilebilir. Bu komutlar IP ya da CS değerini değiştirdikleri için çağırma başlığı altında incelenir.

### 16.3 Dönüş komutları ve yığın

Bir fonksiyona gittikten sonra o fonksiyon bitince kaldığımız yere dönmeliyiz. Dönüş komutları da IP ve CS'yi değiştirir. Her çağırma, kendi dönüş komutuyla eşleşmelidir:

- **CALL ile gidildiyse RET ile dönülür.** Aynı segment içinde kalındığı için kaldığımız yeri ayırt eden tek şey eski IP değeridir. CALL yığına IP'yi atar, RET yığından IP'yi çeker.
- **CALL FAR ile gidildiyse RETF (return far) ile dönülür.** Farklı bir segmente gidildiği için CALL FAR yığına hem CS'yi hem IP'yi atar. RETF ikisini de çekip ilgili yazmaçlara geri yazar, böylece ana programda kalınan yerden devam edilir.
- **INT ya da INTO ile gidildiyse IRET ile dönülür.** Kesme alt programında bayraklar değiştirilebilir ya da kullanılabilir. Bu yüzden kesme çağrıları yığına bayrak yazmacını, CS'yi ve IP'yi atar. IRET bu üçünü yığından çekip geri yükler.

Hoca kesme çağrılarında işlemcinin bu işleri otomatik yaptığını, slayttaki adımların bunların assembly karşılıkları olduğunu söyledi: bayraklar yığına atılır, CS yığına atılır, IP yığına atılır, iki bayrak sıfırlanır, sonra bir tablodan yeni IP ve CS değerleri yüklenir ve kesme alt programı çalıştırılır. Ayrıntılar kesme konusunda görülecek.

INT komutunun iki biçimi vardır:

- `INT n`: Yanına 8 bitlik onaltılık bir değer yazılır. Bu değer, yukarıdaki tablonun kaçıncı gözündeki adresin alınacağını belirtir.
- `INTO` (interrupt on overflow): Tek başına yazılır ve 4 numaralı tablo gözündeki kesmeye eşittir.

Hoca slaytlarda ek olarak, kontrol komutlarının bayrak koşullarını ve birbirine eşdeğer komutların listesini verdiğini söyledi.

**Soru (ders sonu):** Çağırma tipleri kaç tanedir?

**Cevap:** İki tip vardır. Fonksiyon aynı segmentin içinde tanımlanmışsa near, farklı bir dosyada ya da segmentte tanımlanmışsa far çağrıdır. Fonksiyonun tipini kendimiz belirlediğimiz için tanımlama ve çağırma uyumlu olmalıdır. Near tanımlanıp far çağrılırsa uyumsuzluk olur.

## 17. If-Then-Else Yapılarını Assembly ile Kurmak

### 17.1 Üç yapı

Koşullu dallanma komutlarıyla if-then-else mantığı kurulur. Hoca akış şemalarıyla üç yapı gösterdi. Koşullar eşkenar dörtgenle, yürütülecek işlemler dikdörtgenle gösterilir.

- **If-then-else (mavi):** Koşulun hem doğru hem yanlış kolunda bir işlem vardır. Çıkıştan sonra üçüncü bir işlem gelir.
- **If-null-else (turuncu):** True kolu dolu, false kolu boştur. Çıkıştan sonra sıradaki bir komut vardır.
- **If-null-then (yeşil):** False kolu dolu, true kolu boştur.

> **Hocanın vurgusu:** 8086'nın koşullu dallanma komutlarının yapısı gereği, bir kolu boş bir if-then-else'te koşul boş kol için yazılırsa işlem daha az satırla yapılır. Bu, hafızamızda tutmamız gereken bir kuraldır.

### 17.2 İki kolu da dolu örnek

Görev: AX'te 0 varsa BX'e 2, yoksa BX'e 1 ata. Çıkışta CX'e 5 ata. Hoca sınıfa bunun nasıl yazılacağını sordu. Öğrencilerin önerileriyle önce AX sıfırla karşılaştırıldı, sonra işaretsiz sayılarla ilerlemek için JE seçildi. Ekrandaki çözüm (ekrandan, 02:40:00):

```asm
CMP AX, 0
JE etiket1
MOV BX, 1        ; false kolu
JMP etiket3
etiket1:
MOV BX, 2        ; true kolu
etiket3:
MOV CX, 5
```

Hoca etiketlerden sonra iki nokta üst üste konduğunu hatırlattı. Akış şöyledir:

- AX = 0 ise etiket1'e gidilir, BX'e 2 atanır, sonra CX'e 5 atanır.
- AX ≠ 0 ise JE'nin bir alt satırına geçilir, burası false koludur ve BX'e 1 atanır.

Hoca `JMP etiket3` satırını daire içine aldı. Bu satır yazılmazsa `MOV BX, 1`'den sonra akış aşağıya devam eder, `MOV BX, 2` de çalışır ve yanlışlıkla true koluna düşülür.

**Soru:** JMP satırı yerine `MOV CX, 5` yazsak olmaz mı?

**Cevap:** `MOV CX, 5`'ten sonra akış yine alt satıra geçer ve `MOV BX, 2` çalışır. İstemediğimiz ve planlamadığımız hâlde BX'e 2 atanmış olur. Bu yüzden belirtilen şekilde JMP ile yazılmalıdır.

Aynı yapı ters koşulla da kurulabilir. JNE, akış şemasındaki false koluna karşılık gelir (ekranda ikinci sütun, ekrandan, 02:40:00). Altyazıdaki anlatıma göre kod şöyle tamamlanır:

```asm
CMP AX, 0
JNE etiket1
MOV BX, 2        ; true kolu (eşitse)
JMP etiket3
etiket1:
MOV BX, 1        ; false kolu
etiket3:
MOV CX, 5
```

Burada da true kolundan sonra `JMP etiket3` yazılmazsa BX'e 2 atandıktan sonra `MOV BX, 1` çalışır ve BX bozulur. Yani koşul, true koluna ya da false koluna göre tanımlanabilir. Bu bizim elimizdedir.

### 17.3 False kolu boş örnek

Görev: AX = 0 ise BX'e 1 ata, değilse bir şey yapma. Çıkışta CX'e 5 ata (turuncu yapı).

Önce koşul dolu kola göre yazıldı (ekrandan, 02:45:00):

```asm
CMP AX, 0
JZ etiket1
JMP etiket2
etiket1:
MOV BX, 1
etiket2:
MOV CX, 5
```

Hoca etiket adını 3'ten 2'ye düzeltti. Önceki örnekte false kolunda bir işlem olduğu için JMP'den önce yazılmıştı. Burada false kolu boş olduğu için doğrudan `JMP etiket2` gelir.

Bir öğrenci etiket2'yi doğrudan JZ'nin altına koymayı önerdi. Hoca bunun, kurala göre yazılan sürümle aynı sonuca varacağını söyledi. Koşul boş kol için yazıldığında kod şöyle olur:

```asm
CMP AX, 0
JNZ etiket1      ; boş kolun koşulu
MOV BX, 1        ; true kolu
etiket1:
MOV CX, 5
```

AX sıfır değilse doğrudan çıkışa, yani `MOV CX, 5`'e gidilir. Sıfırsa bir alt satıra geçilir ve BX'e 1 atanır, ardından akış kendiliğinden `MOV CX, 5`'e varır. Fazladan bir etiket ve bir JMP komutundan kurtulunur.

### 17.4 True kolu boş örnek

Görev: AX = 0 ise bir şey yapma, değilse BX'e 1 ata. Çıkışta CX'e 5 ata (yeşil yapı).

Koşul dolu (false) kola göre yazılırsa:

```asm
CMP AX, 0
JNZ etiket1
JMP etiket2
etiket1:
MOV BX, 1
etiket2:
MOV CX, 5
```

Koşul boş (true) kola göre yazılırsa:

```asm
CMP AX, 0
JZ etiket1       ; boş kolun koşulu
MOV BX, 1        ; false kolu
etiket1:
MOV CX, 5
```

AX = 0 ise doğrudan çıkışa gidilir. Değilse BX'e 1 atanır ve akış otomatik olarak `MOV CX, 5`'e geçer.

> **Hocanın vurgusu:** Bir if-then-else'te bir kol boşsa koşulu boş kola göre yazarsak kod kısalır.

## 18. Yığın Üzerine Bir Soru

**Soru:** Yığın, işlemciye yakın, yazmaç gibi ya da bellek gibi davranan bir şey miydi, yoksa bir alan mı?

**Cevap:** Yığın bir yazmaç değil, bellekte (RAM'de) bir alandır. Hoca ileride EXE ve COM tipi programların görüleceğini, özellikle EXE programların çalışmak için üç bellek bloğuna ihtiyaç duyduğunu söyledi:

- **Kod bloğu:** Yazdığımız komutlar.
- **Veri bloğu:** Dizi ve değişken tanımlamaları.
- **Yığın bloğu:** Yığın veri yapısı mantığıyla çalışan bellek bölgesi.

Yığının tepesini gösteren bir stack pointer (SP) vardır. Yığına bir şey atıldıkça SP ikişer azalır, yani yüksek adresten düşük adrese doğru iner. Yığından bir şey çekildikçe ikişer artar. Kullanım amaçları:

- Bir alt fonksiyona ya da kesme fonksiyonuna gidildiğinde dönüş bilgilerini tutmak.
- Fonksiyonlar arası parametre aktarımı: Yığına değerler basılır, fonksiyon çağrılır. Alt fonksiyon, gönderilen parametrelerin yığının tepesinden ne kadar uzakta olduğunu bilerek onları alır.

Hoca segment değerlerini, özellikle bir işletim sistemi varsa, bizim atamadığımızı ekledi. Program sabit diskten RAM'e yüklenirken sıradaki boş segment değerleri otomatik olarak atanır. Bu kod, veri ve yığın segmentleri için geçerlidir. Debug ortamında yığın segment değeri elle değiştirilebilir. Ama bu değer başka bir programın kod segmentine denk gelebilir ve istemeden orası bozulabilir. Bu yüzden segment değerleriyle elle oynamaya kesinlikle gerek yoktur.

## 19. Gelecek Haftaya Giriş

Hoca gelecek hafta işlenecek konulara kısa bir giriş yaptı:

- **Yığın komutları:** PUSH ve POP. 16 bitlik bir yazmaç ya da bellek değerini yığına atmak ve yığından çekmek için kullanılır. Bayrak yazmacını atmak ve çekmek için de karşılık gelen komutlar vardır.
- **Döngü komutları:** Koşullu dallanmayla if-then-else kuruldu. Döngü komutlarıyla da for, for-down-to, while, do-while, repeat-until ve iç içe iki for gibi yapılar kurulacak. Bunun için LOOP komut grubu kullanılacak.
- **Bayrak komutları.**
- **Mantık komutları:** Özellikle TEST önemlidir. CMP arka planda SUB çalıştırıp sonucu saklamadan bayrakları etkiliyordu. TEST de arka planda AND çalıştırır, yazmaçları değiştirmez, yalnız bayrakları etkiler. Bir ya da birden fazla bitin 1 olup olmadığı bununla kontrol edilir ve koşullu dallanma için koşul üretilir.
- **Öteleme ve döndürme komutları:** Shift ve rotate.

Hoca, iç içe iki if olduğunda da her iki if'in boş kolları varsa koşulların bu kollara göre yazılmasıyla kodun kısalacağını söyledi ve bunu gelecek haftanın başında bir örnekle göstereceğini ekledi.

**Soru:** INT komutu tüm mikroişlemcilerde var mı?

**Cevap:** Evet. Hoca örnek olarak klavyeden bir şey yazıldığında ya da fare oynatıldığında bunun kesme tabanlı olarak ele alındığını söyledi. Ders kitabının 110. sayfasındaki tabloya göre bu kitap 486'ya kadar olan komutları inceler ve komut 8086, 286, 386 ve 486'da mevcuttur.

## 20. Overflow Üzerine Son Bir Örnek

Ders sonunda bir soru üzerine hoca, büyük pozitif bir sayıdan küçük bir negatif sayı çıkarmanın iki büyük pozitif sayıyı toplamak gibi olduğunu anlattı. 8 bitte iki büyük pozitif sayı toplandığında sonuç negatif çıkabilir. Bu, toplamın ikiye tümleyen aralığına sığmadığı, yani overflow olduğu anlamına gelir. 8 bitte yazılabilecek en büyük pozitif sayı 0111 1111'dir.

<!-- BELİRSİZ: Hocanın ekrana yazdığı iki ikilik sayı ve toplamları altyazıda tam okunmuyor (yalnız "1, 1, 1, 1, 1, 0, 1, 1" gibi bir düzeltme duyuluyor). 03:05:00 karesinde ekran boştur. -->

Akılda tutulması gereken kural şudur:

- İkiye tümleyen aritmetiğinde iki pozitif sayı toplanıp sonuç negatif çıkarsa overflow vardır.
- İki negatif sayı toplanıp sonuç pozitif çıkarsa yine overflow vardır.

Overflow durumunda işaret biti, işlenenlerin işaretine göre beklenenin tersi çıkar.

## Örnek Sorular

### Soru 1 (ekrandan, 00:30:00)

32 bit iki işaretsiz sayıyı toplayan assembly kodunu yazınız.

Derste çözüm fikri verildi: düşük anlamlı 16 bitlik sözcükler ADD ile, yüksek anlamlı sözcükler ADC ile toplanır. Kod derste yazılmadı.

> **Çözüm (derste verilmedi):** Sayıların bellekte little endian düzeninde, düşük sözcük önce gelecek biçimde durduğu varsayılmıştır. MOV bayrakları etkilemediği için ADD'nin ürettiği CF, ADC'ye kadar korunur.

```asm
MOV AX, [SAYI1]       ; 1. sayının düşük sözcüğü
ADD AX, [SAYI2]       ; düşük sözcükler; elde CF'ye gider
MOV [TOPLAM], AX
MOV AX, [SAYI1+2]     ; 1. sayının yüksek sözcüğü
ADC AX, [SAYI2+2]     ; yüksek sözcükler + CF
MOV [TOPLAM+2], AX
```

### Soru 2 (derste sözlü, 00:54:55)

8 bitlik ikiye tümleyen gösterimde yazılabilecek en küçük negatif sayı nedir?

**Çözüm (derste verildi):** 80H = 1000 0000. En yüksek bit 1 olduğu için negatiftir. İkiye tümleyeni 0111 1111 + 1 = 1000 0000 = 128'dir. Yani 80H = −128. FFH ise −1'dir, negatif sayıların en büyüğüdür.

### Soru 3 (ekrandan, 01:25:00)

AL = 0FFH, BL = 4 iken `IMUL BL` sonucunda AX neden 00FCH değil de FFFCH olur?

**Çözüm (derste verildi):** IMUL işaretli çarpar: (−1) × 4 = −4. 8 bitte −4 FCH = 1111 1100B'dir. Sonuç 16 bitlik AX'e yazılırken işaret biti (1) sola doğru tekrarlanır ve FFFCH elde edilir. 00FCH olsaydı en yüksek bit 0 olur ve sonuç pozitif +252 anlamına gelirdi. Aynı değerlerle `MUL BL` ise AX = 03FCH (1020) verir.

### Soru 4 (ekrandan, 01:30:00 ve 01:35:00)

AX = 0F0F0H, BL = 0F0H iken `DIV BL` çalıştırılırsa ne olur?

**Çözüm (derste verildi):** F0F0H ÷ F0H = 101H, kalan 0'dır. 8 bitlik bölmede bölüm AL'ye yazılmalıdır ama 101H 8 bite sığmaz. Bu yüzden işlem hatalıdır ve işlemci hata kesmesine gider. AX = 0B0F0H ile tekrarlandığında AL = BCH (bölüm), AH = B0H (kalan) bulunur.

### Soru 5 (derste sözlü, 01:35:46)

100H'ın karesi nasıl alınır? Kaç bitlik bir çarpma gerekir?

**Çözüm (derste verildi):** 100H AL'ye sığmadığı için 16 bitlik çarpma gerekir: `MOV AX, 100H` ve `MUL AX`. Sonuç DX:AX'te oluşur: DX = 0001H, AX = 0000H, yani 10000H.

### Soru 6 (ekrandan, 01:40:00)

10000H / 100H işlemini 8086 assembly ile yapınız.

**Çözüm (derste verildi):** 32 bitlik bölünen DX:AX'e yerleştirilir: düşük 16 bit AX = 0000H, yüksek 16 bit DX = 0001H.

```asm
XOR AX, AX
MOV DX, 1
MOV BX, 100H
DIV BX           ; AX = 0100H (bölüm), DX = 0000H (kalan)
```

### Soru 7 (derste sözlü, 01:41:15)

`MOV AX, 0` 4 clock cycle, `XOR r16, r16` 3 clock cycle sürüyor. MOV'un yaptığı işi 3 clock cycle'da yapan komutu yazınız.

**Çözüm (derste verildi):** `XOR AX, AX`. Eşit bitlerin XOR'u 0 olduğu için bir sayının kendisiyle XOR'u sıfırdır ve AX sıfırlanır.

### Soru 8 (ekrandan, 02:15:00)

A ← FFH, B ← 1 iken `CMP A, B` sonrasında `JA etiket` ve `JG etiket2` dallanır mı?

**Çözüm (derste verildi):** JA sonucu işaretsiz yorumlar: 255 > 1, dallanır. JG işaretli yorumlar: −1 > 1 değildir, dallanmaz.

### Soru 9 (ekrandan, 02:40:00)

AX = 0 ise BX'e 2, değilse BX'e 1 atayan, her iki durumda sonra CX'e 5 atayan kodu yazınız.

**Çözüm (derste verildi):**

```asm
CMP AX, 0
JE etiket1
MOV BX, 1
JMP etiket3
etiket1:
MOV BX, 2
etiket3:
MOV CX, 5
```

`JMP etiket3` unutulursa false kolundan sonra `MOV BX, 2` de çalışır.

### Soru 10 (ekrandan, 02:45:00)

AX = 0 ise BX'e 1 atayan (false kolu boş), sonra CX'e 5 atayan kodu en az satırla yazınız.

**Çözüm (derste verildi):** Koşul boş kol için yazılır:

```asm
CMP AX, 0
JNZ etiket1
MOV BX, 1
etiket1:
MOV CX, 5
```

Dolu kola göre yazılan sürümdeki (`JZ etiket1`, `JMP etiket2`) fazladan JMP ve etiket ortadan kalkar.

### Soru 11 (derste sözlü, 01:46:02)

4 clock cycle süren bir komut kaç saniye sürer?

**Çözüm (derste verildi, düzeltilerek):** Süre = clock sayısı × saat periyodu, periyot = 1 / frekans. Hoca 2 MHz için hesapladı ama sayısal sonucu hatalıydı (bkz. Bölüm 12.3).

> **Çözüm (derste verilmedi):** 2 MHz'te $T = 1/(2 \times 10^6) = 0{,}5\ \mu s$. 4 clock'luk komut $4 \times 0{,}5 = 2\ \mu s$ sürer.

## Dersin Toparlaması

Bu derste 8086'nın aritmetik komutları baştan sona işlendi. ADD, ADC, SUB ve SBB'nin `dest ← dest op src` kuralıyla çalıştığı, bellek ile sabit değer arasındaki işlemlerde PTR'nin zorunlu olduğu ve 32 bitlik aritmetiğin ADD/ADC ve SUB/SBB çiftleriyle kurulduğu görüldü. INC, DEC ve NEG'in sınır davranışları (FFH → 00H, 0000H → FFFFH, NEG ≠ NOT), CMP'nin sonucu saklamayan bir çıkarma olduğu ve bayrakların işaretsiz (CF) ve işaretli (OF) yorumlara göre nasıl oluştuğu emu8086 üzerinde gösterildi. MUL, IMUL, DIV ve IDIV'in gizli operandları (AX, DX), sonucun hedef yazmaçları nasıl bozduğu, IMUL'daki işaret genişletmesi ve bölümün sığmaması durumu örneklerle incelendi. Aynı işi yapan komutlardan daha az clock cycle süreninin seçilmesi gerektiği `XOR AX, AX` örneğiyle anlatıldı.

Dersin ikinci yarısında dallanma komutlarına geçildi. Koşullu dallanmaların basit, işaretsiz (above/below) ve işaretli (greater/less) grupları, işlemcinin bu kararları yalnız CF, ZF, SF ve OF bayraklarına bakarak verdiği tablo, JMP ve JMP FAR PTR, CALL/RET, CALL FAR/RETF ve INT/IRET eşleşmeleri ve yığının rolü anlatıldı. Son olarak if-then-else yapıları assembly ile kuruldu ve bir kolu boş yapılarda koşulun boş kola göre yazılmasının kodu kısalttığı kuralı vurgulandı. Gelecek hafta yığın komutları (PUSH, POP), döngü komutları (LOOP), bayrak ve mantık komutları (özellikle TEST), öteleme ve döndürme komutları ile iç içe if örnekleri işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
