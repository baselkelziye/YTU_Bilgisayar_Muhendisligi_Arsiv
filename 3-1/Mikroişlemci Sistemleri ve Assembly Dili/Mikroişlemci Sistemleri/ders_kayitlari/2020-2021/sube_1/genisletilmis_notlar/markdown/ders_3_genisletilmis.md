# Ders 3 Genişletilmiş Notu: 8086 Adresleme Modları Tekrarı, Uç Tanımları ve Yol Tutma/Tamponlama Devreleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Adresleme modlarının tekrarı
- 2. 8086 uç tanımları (minimum mod)
- 3. Hafıza ve G/Ç uzayı, adres çözümleme
- 4. Veri aktarım yöntemleri ve kesme uçları
- 5. Uçların formal tanımları
- 6. Yardımcı devreler: saat üreteci, tamponlama ve tutma
- 7. 74LS373, 74LS245 ve 74LS244 entegreleri
- 8. Tam tamponlanmış 8086 sistemi
- 9. Yol zamanlaması
- Örnek Sorular

## 1. Adresleme modlarının tekrarı

Ders, bir önceki haftanın konusu olan adresleme modlarının hızlı bir tekrarıyla başlar. 8086'da üç grup adresleme incelenmişti: program hafızası adresleme, yığın adresleme ve veri hafızası adresleme. Slaytın girişinde, verimli assembly programları yazabilmek için komutlarla birlikte kullanılan adresleme modlarının bilinmesi gerektiği vurgulanır.

### 1.1 Fiziksel adres hesabı

8086'nın yazmaçları ve veri yolu 16 bittir; yani bir seferde 16 bit veri tutulabilir. Adres yolu ise 20 bittir. 16 bitlik değerlerle 20 bitlik bir adres oluşturmak için segment–offset modeli kullanılır. Hoca slayta formülü şöyle yazdı (ekrandan, 00:05:00):

$$PA = SR \times 10H + OR$$

Burada $SR$ segment yazmacı, $OR$ offset yazmacı (ya da offset değeri), $PA$ fiziksel adrestir. Segment yazmacının 10H ile çarpılması, değerin dört bit sola kaydırılması demektir.

### 1.2 Yığın adresleme

Yığın adreslemenin temeli şudur: `PUSH`, `POP` gibi yığın komutları kullanıldığında varsayılan segment yazmacı SS (stack segment) olur. Fiziksel adres SS ile ilgili offset yazmacı kullanılarak hesaplanır.

### 1.3 Program hafızası adresleme

Program hafızası adreslemesi, komut göstericisinin (IP) değişimiyle ilgilidir. Burada segment yazmacı CS, offset yazmacı IP'dir. Hoca önce yanlışlıkla "stack segment" dedi, hemen "kod segment" diye düzeltti. CS'yi ya da IP'yi değiştiren komutlar üç modda incelenir.

**Doğrudan program hafızası adresleme.** `JMP` (koşulsuz dallanma) ve `CALL` (alt program çağırma) gibi komutlara parametre olarak iki tane 16 bitlik değer verilir. Bu değerler CS ve IP'yi doğrudan değiştirir. Gidilecek adres doğrudan verildiği için bu ad kullanılır. Bunlar far jump ve far call komutlarıdır: programın çalıştığı kod segmentinden başka bir kod segmentine dallanmayı sağlarlar, bu yüzden hem CS'yi hem IP'yi değiştirirler.

**Göreli program hafızası adresleme.** Programın tanımlı olduğu kod segmenti içinde, bulunulan IP değerinden biraz ileri ya da geri gitmeyi sağlar. Verilen değer 8 ya da 16 bitlik, ikiye tümleyen biçiminde işaretli bir sayıdır. 8 bitlik işaretli sayılar $-128$ ile $+127$ arasında olduğu için en fazla 127 ileri ya da 128 geri gidilebilir. Aynı mantık 16 bit için de geçerlidir.

- `JMP 100` gibi bir komut kod segmentinin 100 adresine gitmek demek değildir; bulunulan IP'yi 100 artırmak demektir. Sayı onluk verildiği için pozitiftir.
- `JMP 0FFH` komutunda 0FFH, ikiye tümleyende $-1$'e karşılık gelir. Bu, 255 numaralı offset'e dallanmak değil, IP'yi bir azaltmak demektir.

Hoca burada bir pratik noktaya da değindi. IP'yi değiştiren tek şey dallanma komutları değildir ve adres aritmetiğini elle izlemek zordur. Bu yüzden dallanmalarda sayı yerine etiket (label) verilir. Assembler ilk geçişten sonra etiketleri adreslerle değiştirir; komut boyutlarını ve uzaklıkları kendisi hesaplar. Kullanıcının IP'ye doğrudan müdahale etmesi bu otomatik süreçte istenmeyen sonuçlar doğurabilir.

**Dolaylı program hafızası adresleme.** Veri adreslemedeki dolaylı moda benzer: gidilecek adres doğrudan verilmez, bir yazmaçla verilir. `JMP BX` ya da `CALL BX` çalıştırılmadan önce BX'e uygun değer yazılmış olmalıdır.

### 1.4 Veri hafızası adresleme

**Yazmaç adresleme (ekrandan, 00:10:00).** Komut yazmaçlar üzerinde işlem yapıyorsa yazmaç adresleme söz konusudur. Kullanılabilecek yazmaçlar:

- 8 bitlik: AL, AH, BL, BH, CL, CH, DL, DH
- 16 bitlik: AX, BX, CX, DX, SP, BP, SI, DI

En önemli kural tip uyumudur: kullanılan yazmaçların genişlikleri aynı olmalıdır. `MOV AX, BL` ya da `MOV BX, AL` derleme hatası verir. `MOV BX, CX` geçerli bir örnektir.

**Anlık (immediate) adresleme.** Atanmak istenen sabit değer komutun makine koduna gömülür; bu yüzden sabit değer atama olarak da düşünülebilir. `MOV AL, 0F2H` çalıştıktan sonra AL'nin içeriği F2H olur. Sabit 8 ya da 16 bitlik olabilir, tek tırnak içinde bir ASCII karakter de olabilir. Dikkat edilmesi gereken nokta, 8 bitlik bir yazmaca 16 bitle ifade edilmesi gereken bir sabitin atanamamasıdır.

**Doğrudan adresleme (ekrandan, 00:15:00).** Erişilecek hafıza gözünün doğrudan gösterildiği durumdur. Slayttaki örnekler:

```text
MOV AL, DATA     ; DATA bir etiket olup assembler bunu karşılık gelen adres değeri ile değiştirir
MOV BX, [1234H]  ; BX <- DS:1234H
```

Veri aktarım komutlarında varsayılan segment yazmacı DS'dir. Köşeli parantez içindeki değer, DS içindeki hangi offset'e erişileceğini belirtir. Yani `MOV BX, [1234H]` BX'e 1234H değerini atamaz; DS ve 1234H offset'iyle oluşan 20 bitlik adresteki içeriği BX'e kopyalar.

**Dolaylı adresleme.** Köşeli parantez içindeki offset bir yazmaçla verilir. Geçerli biçimler:

- Tek yazmaç: `[BX]`, `[SI]`, `[DI]`
- Yazmaç + sabit: `[BX+100H]`, `[SI+100H]`, `[DI+100H]` (örnek: `MOV AX, [BX+100H]`)
- Taban + indis: `[BX+SI]`, `[BX+DI]`
- Taban + indis + sabit: `[BX+DI+100H]`

Bunların dışındaki yazmaçlar dolaylı adreslemede kullanılamaz; örneğin `[AX]` ya da `[DX]` derleme hatası oluşturur. Hoca dolaylı adreslemenin dizi erişiminde kullanılabileceğini hatırlattı.

> **Ek bilgi (derste anlatılmadı):** 8086'da taban yazmacı olarak BP de kullanılabilir (`[BP]`, `[BP+SI]` gibi); bu durumda varsayılan segment DS değil SS olur. Derste yalnız BX, SI ve DI örnekleri verildi.

### 1.5 BYTE PTR ve WORD PTR

Slayttaki kural (ekrandan, 00:20:00): dolaylı adreslemelerin bir kısmında BYTE PTR, WORD PTR gibi tanımlayıcılar gerekir; `INC` komutu dolaylı adresleme ile hafızada bir word'ü mü yoksa bir baytı mı artıracağını bilemez. Operandlardan biri yazmaç ise bu tanımlayıcılara gerek yoktur.

Hoca "neden?" sorusunu şöyle cevapladı: `MOV AX, [BX]` komutunda AX belirtildiği için işlemin 16 bitlik olduğu bellidir ve assembler buna göre davranır. Genişlik belli olmadığında tanımlayıcı gerekir.

Örnek (ekrandan, 00:20:00):

- Verilen: hafızada 100H adresinde 0FFH, 101H adresinde 99H var. `MOV BX, 100H` çalıştırılmış.
- `INC [BX]` hatalıdır, çünkü 100H'deki bayt mı, 100H'den başlayan word mü artırılacak belli değildir.
- `INC BYTE PTR [BX]`: 100H'deki bayt artırılır. $0FFH + 1 = 100H$; bayta yalnız 00H sığar. Sonuç: 100H'de 00H, 101H değişmez (99H).
- `INC WORD PTR [BX]`: 100H'den başlayan word, little endian yerleşimde yüksek bayt 99H, düşük bayt 0FFH olan 99FFH'dir. $99FFH + 1 = 9A00H$. Sonuç: 100H'de 00H, 101H'de 9AH.

> **Ders sonrası not:** Hoca bayt artırımında taşma bayrağının (CF) 1 olduğunu söyledi (00:19:45). 8086'da `INC` komutu CF'yi etkilemez; bu örnekte ZF ve AF 1 olur, CF önceki değerini korur. Taşmanın CF'ye yansıması isteniyorsa `ADD BYTE PTR [BX], 1` kullanılır.

## 2. 8086 uç tanımları (minimum mod)

Tekrarın ardından bir önceki hafta başlanan konu olan 8086'nın uç tanımlarına geçildi. Slayttaki 40 uçlu şemada sağ taraftaki bazı uçların maksimum moddaki (kırmızı) ve minimum moddaki (mavi) işlevleri ayrı ayrı gösterilir (ekrandan, 00:25:00).

### 2.1 Minimum ve maksimum mod

8086'nın iki çalışma modu vardır. Maksimum mod, 8086'nın 8087 matematik işlemcisi gibi bir yardımcı işlemciyle birlikte kullanılacağı durum içindir. Derste hep minimum mod kullanılacaktır: örneklerde 8086 tek başına çalışır.

Mod seçimi MN/$\overline{MX}$ ucuyla yapılır. Uç adının üzerindeki çizgi (ya da önündeki eğik çizgi) o işlevin aktif 0 olduğunu gösterir. Bu uç 1 ise minimum mod, 0 ise maksimum mod seçilir (slayt: "MN,/MX --> 1: Minimum, 0: Maksimum", ekrandan 00:25:00). Derslerde kurulacak devrelerde bu uca lojik 1, elektriksel olarak 5 V bağlanacaktır.

### 2.2 Adres/veri uçları ve zaman çoğullama

8086'nın 16 veri ucu ve 20 adres ucu olmalıdır; fakat bu işlevler aynı fiziksel uçları paylaşır. AD0–AD15 adres/veri uçlarıdır. A16/S3, A17/S4, A18/S5 ve A19/S6 ise adres uçlarıyla durum (status) bitlerini paylaşır. Bu yapı zaman çoğullamadır (time multiplexing): aynı fiziksel uç, bir komutun yürütüldüğü dört adımın farklı anlarında farklı görev görür. Örneğin T1 anında adres değerini, T2 anında veri değerini taşır. Bu nedenle adres ve veri değerleri birbirinden ayrılmalıdır.

### 2.3 ALE: adresin ayrılması

Adres değerlerini ayırmak için ALE (Address Latch Enable) ucu kullanılır. Hoca burada tutucu (latch) ile flip-flop farkını hatırlattı: flip-flop durumunu yalnız saat darbesinin yükselen ya da düşen kenarında değiştirir; latch ise bir enable (tutma) kontrolüyle çalışır. Tutma etkin değilken çıkış girişi izler; tutma etkinleştirildiğinde giriş ne kadar değişirse değişsin çıkışta son değer saklı kalır.

ALE ucu, AD uçlarında adres değeri olduğunu bildirir. Kurulacak bir tutucu devre grubunun girişlerine AD uçları, tutma kontrol ucuna ALE bağlanır. ALE 1'e çıktığında AD uçlarındaki değer saf adrestir; tutucunun çıkışında saf adres değerleri oluşur ve tutulur.

### 2.4 $\overline{DEN}$ ve DT/$\overline{R}$: verinin ayrılması

$\overline{DEN}$ (Data Enable) ucu AD uçlarında veri olduğunu bildirir. Adının başındaki eğik çizgi aktif 0 olduğunu gösterir: uç 0 olduğunda AD uçlarında veri vardır. AD uçları fiziksel olarak aynı düğümden ikinci bir yardımcı devre grubuna da bağlanır; bu grubun kontrol ucuna $\overline{DEN}$ bağlanır ve $\overline{DEN}$ 0'a düştüğünde veri ayrıştırılır.

Hoca burada bir soru sordu: adres değeri işlemci açısından giriş mi, çıkış mı? Veri uçları giriş mi, çıkış mı? Cevap: adres uçları yalnız çıkıştır, işlemci adresi dış dünyaya gönderir. Veri uçları ise iki yönlüdür, çünkü işlemci hem veri okur hem veri yazar. Bu yüzden adres ayırma devresinde tek yönlü tutma yeterlidir; veri ayırma devresinde ise iki yönlü aktarım gerekir. Yön bilgisi DT/$\overline{R}$ (Data Transmit/Receive) ucuyla verilir:

- İşlemci dış dünyaya veri gönderirken (transmit) DT/$\overline{R}$ = 1
- İşlemci dış dünyadan veri okurken (receive) DT/$\overline{R}$ = 0

### 2.5 $\overline{RD}$ ve $\overline{WR}$

İşlemci dış dünyaya yazma yapmak istediğinde $\overline{WR}$ ucunda 0 üretir; okuma yapmak istediğinde $\overline{RD}$ ucunda 0 üretir.

**Soru (hocanın sorusu):** DT/$\overline{R}$ ile $\overline{RD}$/$\overline{WR}$ arasındaki fark nedir? **Cevap:** $\overline{RD}$ ve $\overline{WR}$ doğrudan dış çevre birimlerine kadar uzanan uçlardır. DT/$\overline{R}$ ise yalnız veri uçlarını ayıran yardımcı devreye bağlanır, dış dünyaya aktarılmaz.

### 2.6 RESET ve READY

RESET ucu işlemcinin fiziksel olarak sıfırlanmasını sağlar. Bilgisayar açıldığında yardımcı devreler saat işareti üretmeye başlar, ama bu işaret başta kararlı değildir. Enerji olsa bile kararlı saat işareti gelene kadar işlemcinin çalışması istenmez.

> **Ders sonrası not:** Hoca bu açıklamanın bir yerinde "ready ucunu sıfırda tutarak" dedi (00:34:01). Bağlamdan, saat kararlı hale gelene kadar işlemcinin reset durumunda tutulmasını kastettiği anlaşılıyor; bu iş RESET ile yapılır. Hoca da dersin ikinci yarısında bunu RC devresi ve reset gecikmesiyle anlattı (01:22:22).

READY ucu ise şu iş içindir: bazı okuma/yazma işlemleri tek bir okuma ya da yazma çevriminde tamamlanamaz. Yavaş çevre birimleri READY ucunu 0'a çekerek işlemcinin veri gelene kadar beklemesini sağlar.

### 2.7 $\overline{BHE}$ ve A0

$\overline{BHE}$/S7 (Bus High Enable) ucu da zaman çoğullamalıdır, bu yüzden ALE ile ayrılması gerekir. 8086'nın veri yolu 16 bittir. Bazı özel durumlarda veri yalnız veri yolunun yüksek anlamlı 8 bitinde, bazılarında yalnız düşük anlamlı 8 bitinde bulunur. Hoca bu durumların ayrıntısını ilerleyen derslere bıraktı.

- Veri yalnız yüksek baytta ise işlemci $\overline{BHE}$ ucunda 0 üretir.
- Veri yalnız düşük baytta ise bu A0 ucundan anlaşılır: A0 = 0. Slaytta bu "A0 == /BLE" diye yazıldı (ekrandan, 00:40:00).

**Soru:** A0, bus high enable'ın başka bir adı mı, yoksa işlemcide ayrı bir uç mu? **Cevap:** $\overline{BHE}$ işlemcide fiziksel bir uçtur. $\overline{BLE}$ (bus low enable) diye fiziksel bir uç yoktur; bu bir işlevdir. AD0 ucundan adres ayrıldıktan sonra elde edilen A0 ucu, bus low enable işlevini yerine getirir.

### 2.8 M/$\overline{IO}$

Slaytta bu uç IO/M diye yazılmıştı; hoca bunu 8086'daki doğru adıyla M/$\overline{IO}$ olarak düzeltti (ekrandan, 00:40:00). Bu uç, yapılan işlemin hafıza işlemi mi yoksa G/Ç işlemi mi olduğunu belirtir.

Hoca öğrencilerden hafızaya erişen bir komut istedi. Slayta şu iki komut yazıldı (ekrandan, 00:45:00):

```text
MOV AX, [100H]   ; M/IO = 1
IN  AX, 100H     ; M/IO = 0   (sonra IN AX, DX olarak düzeltildi)
```

`MOV AX, [100H]` hafızaya erişen bir komuttur. `IN` ve `OUT` G/Ç komutlarıdır. `IN AX, 100H` bir anlık adresleme değil, port adreslemedir: "100 adresindeki porta git" demektir, 100 değerini kopyalamak değil. İki komut da işlemcinin adres uçlarında 100 değerini üretir. Hafıza işlemlerinde M/$\overline{IO}$ = 1, G/Ç işlemlerinde 0 olur. İşlemci bunu çalıştırdığı komuta bakarak belirler. Bu ucun faydası bir sonraki bölümde anlatılır.

## 3. Hafıza ve G/Ç uzayı, adres çözümleme

### 3.1 Hafıza uzayı ve G/Ç uzayı

**Soru (hocanın sorusu):** Bu yapıda hafıza işlemleri için erişilebilecek kapasite ne kadardır? **Cevap:** 1 MB. 20 adres ucu vardır; `MOV AX, [100H]` yazılsa bile DS ile 100H offset'i birleştirilerek 20 bitlik bir adres oluşur. Bu yüzden $2^{20}$ baytlık alanın herhangi bir yerine erişilebilir.

Ardından hoca aynı soruyu G/Ç için bir ipucuyla sordu. İpucu: `IN` ve `OUT` komutlarında port adresi 8 bite sığıyorsa doğrudan komut içinde verilebilir; sığmıyorsa DX yazmacına yazılıp `IN AX, DX` biçiminde kullanılır. Hoca bu noktada slayttaki `IN AX, 100H` komutunun yanlış olduğunu, 100H'nin 8 bite sığmadığını ve DX ile verilmesi gerektiğini düzeltti (ekrandan, 00:45:00).

**Soru (hocanın sorusu):** G/Ç uzayının genişliği nedir? **Cevap:** DX 16 bitlik bir yazmaç olduğu için verilebilecek en büyük port adresi 16 bitle yazılabilen en büyük değerdir. G/Ç uzayı $2^{16}$ bayt = 64 KB'tır. Bu soruyu derste iki öğrenci doğru cevapladı.

### 3.2 Adres çözümleme devresi

Hoca adres çözümleme devresini hatırlattı. İşlemcinin adres, veri ve kontrol uçlarının uygun tutucu ve yardımcı devrelerle ayrıştırıldığını varsayalım. Bu uçlar işlemcinin haberleştiği bütün çevre birimlerine ve hafıza birimlerine bağlıdır. İşlemci bunlardan biriyle konuşmak istediğinde bir `MOV` ya da `IN`/`OUT` komutu çalıştırır. Aynı anda iki çevre birimi adres ya da veri hattına değer çıkarmaya çalışırsa çakışma olur.

Bu yüzden ek bir yardımcı devre gerekir: adres çözümleme devresi. Bu devre, işlemcinin verdiği adres değerine göre bütün çevre birimlerinden yalnız birini etkin yapan bir kontrol işareti üretir. Cihazların hangi adres aralıklarında olacağı devreye donanımsal olarak önceden "programlanır". İkinci bir adres aralığından değer gelirse ikinci cihaz etkin, diğerleri devre dışı olur. Sonuçta hatta yalnız işlemci ve tek bir çevre birimi kalır ve ikisi birbiriyle konuşur.

### 3.3 M/$\overline{IO}$'nun çözümlemeye katılması

Slayttaki iki çizim iki durumu karşılaştırır (ekrandan, 00:50:00):

- **M/$\overline{IO}$ çözümleme devresine katılırsa:** aynı adres uçlarına aynı değer çıksa bile işlemin hafızaya mı G/Ç'ye mi ait olduğu ayırt edilir. 1 MB'lik hafıza uzayı ve 64 KB'lik G/Ç uzayı iki ayrı uzay olur. Avantajı daha geniş adres uzayıdır; dezavantajı çözümleme devresinin karmaşıklaşmasıdır.
- **M/$\overline{IO}$ çözümlemeye katılmazsa:** 1 MB'lik alanın düşük anlamlı 64 KB'lik kısmı yalnız G/Ç işlemlerine ayrılır, geri kalanı hafızaya kalır. Hafıza uzayından 64 KB kaybedilir, uzaylar iç içe geçer; avantajı çözümleme devresinin görece basit olmasıdır.

> **Ek bilgi (derste anlatılmadı):** Bu iki yaklaşım literatürde "ayrık G/Ç" (isolated I/O) ve "hafıza eşlemeli G/Ç" (memory-mapped I/O) olarak adlandırılır.

## 4. Veri aktarım yöntemleri ve kesme uçları

### 4.1 HOLD ve HLDA

DMA (Direct Memory Access) modunda veri aktarımı gerektiğinde işlemci veri, adres ve kontrol uçlarını başka bir yardımcı devreye devreder. Hoca bunu şöyle anlattı: işlemci kendini hattan yalıtır ve veri aktarımı için başka bir devreyi görevlendirir; o devre aktarımı bitirince hatların kontrolünü işlemciye geri verir. HOLD ve HLDA bu iş için kullanılan uç çiftidir.

**Soru:** DMA, PCI gibi bir şey mi? **Cevap:** Hayır. PCI veri aktarımında kullanılan ayrı bir kanaldır. DMA ise işlemcinin devrede olmadığı özel bir durumdur. DMA kullanılmazsa hafızadan okunan veri önce işlemciye uğramak zorundadır, sonra G/Ç birimine aktarılır. DMA'da işlemci aradan çıkar, veri hafızadan doğrudan G/Ç birimine aktarılır.

### 4.2 Üç veri aktarım yaklaşımı

Hoca derste uzun süre polling mantığıyla ilerleneceğini söyledi ve üç yaklaşımı karşılaştırdı (slaytta "Polling" yazılı, ekrandan 00:50:00):

- **Polling (yoklama):** aktif bekleme. İşlemin bittiğini anlamak için belirli bir yazmacın belirli bir bitinin uygun değere gelip gelmediği kontrol edilir. Yazmaç ya da hafıza bölgesi okunur, ilgili bit maskelenir, değerine bakılır; istenen değer değilse başa dönülür. Bit istenen değere ulaşınca döngü kırılır ve veri okunur.
- **DMA:** işlemci aktarım cihazını programlar ve kendini hatlardan yalıtır; aktarım cihazlar arasında otomatik gerçekleşir.
- **Kesme tabanlı:** dış dünyadaki cihazın kendi kesme tetikleme ucu vardır. İşlemci cihazla anlaştıktan sonra başka işlerle uğraşır (hocanın örneği: pi sayısının bilmem kaçıncı basamağını hesaplamak). Cihaz verisi hazır olunca bunu INTR (interrupt request) ucu üzerinden bildirir.

### 4.3 INTR ve $\overline{INTA}$

Kesme isteği geldiğinde işlemci bir komutun tam ortasında olabilir. Komutu yarıda bırakmaz, tamamlar; ama sonraki komuta geçmez, kesme alt programına dallanır. Kesme alt programında veri okunur ve ana programda kalınan yere dönülür.

İşlemcinin isteği değerlendirdiğini çevre birimine bildirmek için $\overline{INTA}$ (interrupt acknowledge) ucu kullanılır. Bu iki uç arasında bir el sıkışma (handshaking) olur: çevre birimi INTR ile istekte bulunur, işlemci $\overline{INTA}$ ucunda 0 üreterek "isteğini değerlendiriyorum" der. INTA işlemci açısından çıkış, INTR giriş ucudur. Slayttaki not: "INTR için IF=1" (ekrandan, 00:55:00). Kesme bayrağı (IF) 0 ise INTR'den ne kadar istek gelirse gelsin karşılık bulmaz.

**Soru (ara sırasında):** Interrupt acknowledge ucunun ne yaptığı tekrar anlatılabilir mi? **Cevap:** Çevre birimi INTR ucunda lojik 1 üreterek kesme ister. İşlemci, örneğin dört çevrimlik bir komutun ortasındaysa komutu tamamlar ve kesme alt programına dallanır. Bu aşamada isteği değerlendirmeye başladığını çevre birimine $\overline{INTA}$ ile bildirir. Bildirmezse karşı taraf isteğin değerlendirildiğini bilemez; bildirirse bir sonraki veri için kendini hazırlayabilir.

**Soru:** Sinyal $\overline{INTA}$ 0 olduğunda mı gönderilir? **Cevap:** Evet. $\overline{INTA}$ aktif 0'dır; işlemci isteği değerlendirirken bu uçta 0 üretir.

### 4.4 NMI

İkinci dış kesme ucu NMI'dır (non-maskable interrupt). Bu uç hiçbir bayrakla kontrol edilmez, yazılımla açılıp kapatılamaz. Bu yüzden sistemin çalışması için kritik olan durumlarda kullanılır: elektriksel dalgalanma ya da gerilimin bir an için yetersiz kalması durumunda güç kontrol devresi, ya da RAM'lerin hata vermesi durumunda hafıza devresi NMI üzerinden kesme isteyebilir. Böylece sistemin ve yazılımların zarar görmemesi için hızla güvenli kapatmaya geçilebilir. Derste örneklerde NMI kritik durumlar için değil, örneğin bir buton okumak için kullanılacak.

İki dış kesme arasındaki fark tetikleme biçimidir: INTR seviye tetiklemelidir, lojik 1'de kaldığı sürece kesme yeniden tetiklenebilir. NMI ise kenar tetiklemelidir.

> **Ders sonrası not:** Hoca NMI'nin yükselen kenarda mı düşen kenarda mı tetiklendiğini hatırlayamadığını söyledi (00:56:29). 8086'da NMI yükselen kenarda tetiklenir.

### 4.5 Besleme ve saat uçları

GND ve VCC besleme uçlarıdır. CLK ucu ise 8086'nın senkron ardışıl devre yapıları için gereken saat işaretini alır; bu işaret dışarıdaki bir yardımcı devre tarafından üretilir. Böylece minimum moddaki bütün uçlar kabaca gözden geçirilmiş olur.

## 5. Uçların formal tanımları

Aradan sonra hoca, paylaştığı slaytlardaki formal tanımlar üzerinden uçları yeniden gözden geçirdi. Her ucun yanında parantez içinde hangi tür işlev görebileceği yazılıdır: giriş (I), çıkış (O) ya da üç durumlu (3).

### 5.1 Üç durumlu (tri-state) uçlar

Üç durumlu tampon (tri-state buffer) mantığında uç, hattan koparılmış gibi davranır. Fiziksel olarak bu, ucun yüksek empedans göstermesi demektir. Hoca empedansı AC devrelerdeki direncin eşdeğeri olarak hatırlattı: bir ucun yüksek empedans göstermesi, akıma çok yüksek bir direnç benzeri karşı koyması demektir; direncin sonsuz olduğu uç durumda hat devreden kopmuş gibidir.

AD uçları işleve göre veri aktarırken giriş ya da çıkış, adres aktarırken çıkış yönlüdür; DMA modunda ise hattan koparılmış gibi üç durumlu davranır. A16–A19/S3–S6 uçları ya üç durumlu ya da adres ucu olarak çıkış yönlüdür. Hoca durum bitlerinin ek adres uçları gibi kullanılarak segmentleri farklı 1 MB'lik alanlara aktarmanın mümkün olduğunu ama konu kapsamı dışında kaldığını söyledi.

### 5.2 Diğer uçlar

- **$\overline{RD}$ (O-3) (ekrandan, 01:15:00):** "Okuma işareti lojik 0 olduğunda veri yolu sisteme bağlı hafıza ya da G/Ç cihazlarından gelen veriyi kabul eder." Hoca burada önemli bir kural koydu: ders boyunca bütün uç ve işlevler aksi belirtilmedikçe işlemci açısından tanımlanır. $\overline{RD}$ "işlemci çevre biriminden okuma yapmak istiyor" demektir; ad da buradan gelir. Uç çıkış ya da üç durumlu çalışır.
- **READY (I):** işlemcinin zamanlamasına bekleme durumları eklemek için kontrol edilir. READY = 0 iken işlemci bekleme durumlarına girer ve boşta kalır; READY = 1 iken işlemcinin çalışmasına etkisi yoktur (ekrandan, 01:15:00).
- **$\overline{TEST}$:** konu kapsamı dışında bırakıldı.
- **NMI (I):** önemli kritik kaynaklardan gelen kesmeler için; bayrakla maskelenemez, kenar tetiklemelidir.
- **RESET:** işlemciyi sıfırlayan fiziksel uç. Önemli ek bilgi: 8086'nın reset vektörü FFFF0H fiziksel adresidir. Bu bir kod adresi olduğu için CS = FFFFH, IP = 0000H olarak düşünülür: $FFFFH \times 10H + 0000H = FFFF0H$. İşlemci resetlendiğinde CS'ye otomatik olarak FFFFH, IP'ye 0000H yüklenir. Bu yüzden sistemi ayağa kaldıracak ve denetimlerini yapacak BIOS ROM'larının reset vektöründe bulunması gerekir.
- **MN/$\overline{MX}$ (I):** maksimum/minimum mod seçimi.
- **$\overline{BHE}$:** veri yolunun yüksek baytında anlamlı veri olduğunu gösterir; A0 aktif 0 $\overline{BLE}$ işlevini görür.
- **M/$\overline{IO}$:** komut `MOV` gibi bir hafıza komutuysa hafıza, `IN`/`OUT` ise G/Ç işlemi olduğunu gösterir.
- **$\overline{WR}$ (O):** işlemci dış dünyaya veri yazmak isterse 0 üretir.
- **$\overline{INTA}$:** gelen kesme isteğinin yürütülmekte olduğunu çevre birimlerine bildirir.
- **ALE:** AD uçlarında ve zaman çoğullamalı diğer adres uçlarında adres değerinin hazır olduğunu belirtir.
- **DT/$\overline{R}$:** AD uçlarındaki verinin yönünü belirtir; işlemci açısından çıkış ucudur ve veri ayırma devrelerine bağlıdır.
- **$\overline{DEN}$:** AD uçlarında veri olup olmadığını belirtir.
- **HOLD (I) / HLDA (O) (ekrandan, 01:20:00):** "HOLD girişi DMA ister. HOLD lojik 1 ise işlemci yazılım yürütmeyi durdurur ve adres, veri ve kontrol yollarını yüksek empedans durumuna alır." HLDA, işlemcinin hold durumuna girdiğini bildirir.

## 6. Yardımcı devreler: saat üreteci, tamponlama ve tutma

Bir işlemci tek başına enerji verildiğinde çalışır durumda değildir; çeşitli yardımcı devrelere ihtiyaç duyar.

### 6.1 Saat üreteci (8284)

8086 ile uyumlu çalışan saat üreteci 8284 entegresidir. Devrede bir kristal osilatör bulunur. Kristal, basınç uygulandığında oldukça kararlı bir frekansta titreşim ya da elektriksel çıktı üretir. 8284 bu çıktıyı alır, kuvvetlendirir, eşiklerden geçirir ve düzgün, kararlı bir kare dalgaya çevirir. Bu kare dalga hem işlemci hem de diğer çevre ve hafıza birimleri için gereken zamanlamada kullanılır.

Saat üretecinin ikinci işlevi reset ile ilgilidir. Reset tuşuna basıldıktan sonra parmak çekilir çekilmez işlemci etkinleşmemelidir, çünkü saat darbesi ve sistemdeki elektriksel seviyeler bir anda kararlı hale gelmez. Bu bekleme süresi bir RC devresinin zaman sabitiyle sağlanır: tuşa basıldığında aktif 0 RES girişine değer ancak belirli bir süre sonra ulaşır ve bu süre sistemin kararlı hale geldiği ana göre ayarlanır.

Üçüncü işlev yavaş çevre birimlerinden veri okurken işlemcinin bekletilmesidir. Önceden belirlenen bir süre kadar bekleme sağlayan bir sayıcı düşünülür. Çevre birimi işlemciden örneğin 4 kat yavaşsa (işlemci $x$ frekansında, çevre birimi $x/4$ frekansında çalışıyorsa) bu düzenek READY ucuna 0 vererek işlemcinin çevre biriminin hazır olmasını beklemesini sağlar. Bu bekleme donanımsal olarak yapılır.

<!-- BELİRSİZ: Hocanın 4 kat yavaşlık örneğini gösterdiği slayt (01:23:16–01:24:07 arası) karelerde yok; "0, 1 toplam 4 kat" ifadesinin hangi şekle dayandığı ve bekleme süresinin tam değeri doğrulanamadı. -->

### 6.2 Yol tamponlama (bus buffering)

Tampon (buffer) tekrarlayıcı anlamına gelir. Hoca bunu ADSL hattıyla anlattı: ev santrale uzaksa bakır kablo boyunca sinyal aradaki kutularda kuvvetlendirilir. Örneğin üç kutudan geçiyorsa, sinyal her kutuya biraz sönümlenmiş ama hâlâ okunabilir halde ulaşır; kutu onu tekrar kuvvetlendirip orijinal haline getirerek bir sonrakine iletir. Benzer biçimde $\overline{RD}$ ve $\overline{WR}$ gibi uçlar işlemciden çıkıp bütün çevre birimlerine bağlanmalı ve uygun elektriksel seviyelerini korumalıdır. İşlemcinin uçlarında sağlayabildiği gerilim ve akım sınırlıdır; tampon devreleriyle bu uçlar daha uzun yollar boyunca kararlı kalır.

### 6.3 Yol tutma (latching)

Slayttaki gerekçe (ekrandan, 01:25:00): 8086/8088'in adres/veri yolu, entegre devrenin uç sayısını azaltmak için çoğullanmıştır. Hafıza ve G/Ç, adresin bir okuma/yazma çevrimi boyunca geçerli ve kararlı kalmasını ister. Yollar çoğullandığında adres hafıza ve G/Ç tarafında değişir ve onların yanlış yerlere okuma ya da yazma yapmasına neden olur.

Bir komutun yürütüldüğü T1 anında uçlarda adres, T2 anında veri bulunur. Ama komut dört saat çevrimi sürer ve bu süre boyunca adres sisteme sağlanmalıdır. Bu yüzden T1 anında adres bir tutucudan geçirilip tutulur ve komut bitene kadar sisteme verilir. Benzer biçimde T2'de üretilen veri de tutularak sağlanır. Artık AD uçları ne kadar değişirse değişsin adres ve veri ayrılmış ve tutulmuştur.

## 7. 74LS373, 74LS245 ve 74LS244 entegreleri

Bu bölümde karşılaşılacak üç entegre incelenir: yalnız tutucu olarak çalışan 373, alıcı-verici 245 ve tampon 244.

### 7.1 74LS373 sekizli tutucu

Slayt başlığı: "74LS373 Octal Transparent Latch with 3-state Outputs" (ekrandan, 01:30:00). Sekiz girişli bir tutucudur. Hoca işlevsel şemasını çizdi: girişler (I), çıkışlar (O), aktif 0 $\overline{OE}$ (output enable) ve LE (latch enable) (ekrandan, 01:35:00). Slayttaki fonksiyon tablosu:

| $D_n$ | LE | $\overline{OE}$ | $O_n$ |
|---|---|---|---|
| H | H | L | H |
| L | H | L | L |
| X | L | L | $Q_0$ |
| X | X | H | Z |

(H: yüksek, L: düşük, X: önemsiz, Z: yüksek empedans; ekrandan, 01:30:00)

Çalışması:

- $\overline{OE}$ = 1 (son satır): giriş ve LE ne olursa olsun çıkışlar yüksek empedanstadır. Entegre devre dışıdır; giriş ile çıkış yalıtılmıştır.
- $\overline{OE}$ = 0 ve LE = 1 (ilk iki satır): girişte ne varsa çıkışa kopyalanır; giriş değiştikçe çıkış da değişir.
- $\overline{OE}$ = 0 ve LE = 0: LE'nin 0'a çekildiği andaki değer çıkışta tutulur ($Q_0$); giriş ne kadar değişse de çıkış etkilenmez.

Hoca bu devrenin asenkron olduğunu vurguladı: saat işareti yoktur, bir uç değiştiğinde karşılığı çıkışta anında görülür.

**Soru (hocanın sorusu):** Adres değerlerini saf biçimde ayırıp tutmak için 373'ün girişine, $\overline{OE}$'sine ve LE'sine hangi 8086 uçları bağlanmalıdır, çıkışta ne elde edilir? **Cevap (derste öğrencilerle birlikte kuruldu):**

- Girişlere AD uçları bağlanır.
- LE'ye işlemcinin ALE ucu bağlanır.
- $\overline{OE}$'ye lojik 0 bağlanır, böylece entegre sürekli etkin kalır.
- ALE 1 olduğu anda AD uçlarında adres değerleri vardır; çıkışta adres elde edilir.

Hoca ALE'nin dalga şeklini de çizdi: ALE normalde 0'dadır; AD uçlarında adres oluştuğunda 1'e çıkar, bir süre 1'de kalır, sonra 0'a düşer. ALE 0'a düştüğü anda 373 son değeri, yani adresi tutar. Sonrasında AD uçları veriye geçebilir; bunun bir önemi yoktur, çünkü adres çıkışta tutulmuştur.

> **Hocanın vurgusu:** "Arkadaşlar, burası çok önemli": ALE 1 iken AD uçlarında adres vardır ve 373 bu adresi ALE düşerken yakalar (01:36:11).

### 7.2 74LS245 sekizli alıcı-verici

Transceiver kelimesi transmit ve receive kelimelerinin birleşimidir; entegre veri alıp göndermek için kullanılır. Sekiz bitlik iki yolu (A1–A8 ve B1–B8), aktif 0 $\overline{E}$ (enable) ucu ve DIR (direction) ucu vardır. Hoca çizimde sekiz telden oluşan bir yolu, telin üzerine eğik çizgi çekerek gösterdiğini belirtti. Slayttaki doğruluk tablosu (ekrandan, 01:40:00):

| $\overline{E}$ | DIR | Çıkış |
|---|---|---|
| L | L | B yolundaki veri A yoluna |
| L | H | A yolundaki veri B yoluna |
| H | X | Yalıtım |

Bu entegre veri ayırmak için kullanılır. Bağlantılar:

- A yoluna AD uçları bağlanır; B tarafında saf veri uçları elde edilir.
- DIR ucuna DT/$\overline{R}$ bağlanır. İşlemci veri gönderirken DT/$\overline{R}$ = 1 olur ve A → B aktarılır: işlemcinin AD uçlarındaki veri çevre birimlerine bağlı veri uçlarına gider. İşlemci okurken DT/$\overline{R}$ = 0 olur ve B → A aktarılır: dış veri uçlarındaki değer AD uçlarına, yani işlemciye ulaşır.
- $\overline{E}$ ucuna $\overline{DEN}$ bağlanır.

### 7.3 74LS244 sekizli tampon

Tampon veri tekrarlayıcısıdır. Hoca işlevsel şemasını çizdi: girişler, $\overline{1G}$ ve $\overline{2G}$ adlı iki etkinleştirme ucu ve çıkışlar. Slayttaki tablo (ekrandan, 01:45:00):

| $\overline{1G}$, $\overline{2G}$ | D | Çıkış |
|---|---|---|
| L | L | L |
| L | H | H |
| H | X | (Z) |

373'ten farkı, tutma (latch enable) ucunun olmamasıdır: entegre etkinleştirildiğinde girişteki değerin aynısı çıkışta oluşur. Avantajı, çıkış uçlarını 8086'ya göre daha yüksek akımla sürebilmesidir. Hoca bunu sayısal bir örnekle anlattı: işlemci uçlarını örneğin 200 mikroamper ya da 200 miliamper ile sürerken, bu entegreden geçtikten sonra aynı kontrol uçları örneğin 500 miliampere kadar akım isteğini karşılayabilir. Bu sayılar yalnız fikir vermek içindir. Yine ADSL hattındaki kutulara benzer bir durumdur.

> **Ek bilgi (derste anlatılmadı):** Gerçek değerler bu örnekten küçüktür; veri sayfalarına göre büyük olasılıkla 8086 çıkışları birkaç miliamper, 74LS244 çıkışları ise birkaç on miliamper düzeyinde akım çekebilir.

8086'nın kontrol uçlarını tekrarlamak için kullanımı: $\overline{1G}$ ve $\overline{2G}$'ye lojik 0 bağlanır, böylece entegre sürekli etkin kalır. Örneğin girişe $\overline{RD}$ bağlanınca çıkışta yine $\overline{RD}$ elde edilir, ama artık daha yüksek akımla sürülebilir. Özetle: 373 tutucu, 245 alıcı-verici, 244 tampondur.

## 8. Tam tamponlanmış 8086 sistemi

Hoca bu entegrelerle 8086'nın bütün uçlarının tutulup tekrarlandığı devreyi gösterdi (ekrandan, 01:50:00). Bu yapı dersin geri kalanında standart kabul edilecektir: "Bu işlemcinin bütün adres, veri ve kontrol uçlarının uygun şekilde tutulmuş ve tekrarlanmış olduğunu varsayabilirsiniz" denildiğinde bu devre kastedilir. Yani A0–A19 adres uçları, 245'lerden geçmiş saf veri uçları ve yüksek akımla sürülen kontrol uçları hazırdır.

Devrede şunlar görülür:

- AD0–AD7 ve AD8–AD15 iki ayrı '373'e girer; G (tutma) uçlarına ALE, $\overline{OE}$ uçlarına toprak bağlıdır. Çıkışta A0–A15 elde edilir.
- A16/S3–A19/S6 ile $\overline{BHE}$/S7 üçüncü bir '373'e girer; yine ALE ile tutulur ve A16–A19 ile $\overline{BHE}$ elde edilir. $\overline{BHE}$ ilerleyen derslerde, M/$\overline{IO}$ gibi, adres çözümlemede kullanılacaktır.
- AD0–AD7 ve AD8–AD15 iki '245'e de girer; G uçlarına $\overline{DEN}$, DIR uçlarına DT/$\overline{R}$ bağlıdır. Çıkışta D0–D15 elde edilir.
- M/$\overline{IO}$, $\overline{RD}$ ve $\overline{WR}$ bir '244'ten geçer; $\overline{OE}$ toprağa bağlıdır, yani sürekli etkindir. Çıkış "buffered control bus" olarak gösterilir.

Genel yapı şöyledir: işlemci, saat üreteci, tutucu ve alıcı-vericilerle ayrıştırılmış adres ve veri uçları, 244 ile tekrarlanmış kontrol uçları. Bu saf adres, veri ve kontrol uçları bütün çevre birimleriyle iletişimde kullanılır. Çevre birimlerinin chip select ya da enable uçları bir adres çözümleme devresinden (address decoder) gelir. Bu lojik yapı giriş olarak adres ve bazı kontrol değerlerini alır, her cihaz için bir chip select üretir ve aynı anda yalnız birini seçer. Örneğin yalnız ROM seçilmişse diğer cihazlar hem veri yolunda hem adres yolunda yüksek empedans gösterir; işlemci ile ROM birbiriyle konuşur.

Böylece bir işlemcinin işlev görebilmesi için saat darbesi üretecine, tampon ve tutucu devrelere, çevre birimi olarak G/Ç cihazlarına, ROM'a ve RAM'e ihtiyaç olduğu görülür.

## 9. Yol zamanlaması

### 9.1 Basitleştirilmiş okuma çevrimi

Slayt: "Bus Timing – Simplified Read" (ekrandan, 01:55:00). Bir yol çevrimi (bus cycle) T1, T2, T3, T4 olmak üzere dört saat periyodudur. Şekilde dört sinyal vardır: CLK, ADDRESS (geçerli adres), ADDRESS/DATA ve $\overline{RD}$.

- ADDRESS satırında "VALID ADDRESS" T1'in başından T4'e kadar sürer: komut yürütüldüğü sürece adres uçlarında geçerli değer bulunmalıdır. Bu adresin bir kısmı AD uçlarından, bir kısmı adres/durum uçlarından zaman çoğullamalı olarak gelir.
- T1'de AD uçlarına adres çıkar ve ALE 1 olur; tutucuların çıkışında saf adres oluşur.
- Bir sonraki saat çevriminde AD uçları veriye geçer. $\overline{DEN}$ = 0 ve DT/$\overline{R}$ = 0 olur, yani dış dünyadan veri okunacaktır; çevre biriminin hazırladığı veri AD uçlarına aktarılır.
- $\overline{RD}$ T2'nin başında 0'a iner, T4'ün başında 1'e döner. ADDRESS/DATA satırında T3 boyunca "DATA FROM MEMORY" bulunur ve veri bu aralıkta okunur.

Hoca bunun basitleştirilmiş bir okuma çevrimi olduğunu, gerçek zaman çizelgesinde örneğin ALE'nin ve DT/$\overline{R}$'nin hangi anlarda hangi değerleri alması gerektiğinin ayrıntılı gösterildiğini söyledi ve isteyenin bu çizelgeyi incelemesini önerdi.

### 9.2 Yazma çevrimi

Hoca yazma çevrimini de benzer şekilde anlattı (konuşurken "okuma saykılı" dedi, ama anlattığı yazma çevrimidir). T1'de AD uçlarına adres çıkar, ALE 1 olur ve adres tutulur. T2'de işlemcinin göndermek istediği veri AD uçlarına çıkar; aynı anda $\overline{DEN}$ = 0 ve DT/$\overline{R}$ = 1 olur. Böylece veri saf veri uçlarına, oradan da çevre biriminin veri uçlarına ulaşır. Çevre birimine ayrıca $\overline{WR}$ işareti gönderilir. Veri ve adres çevre biriminin uçlarında hazır olduğu için, $\overline{WR}$ geldiğinde çevre birimi veriyi alıp içine kopyalar.

<!-- BELİRSİZ: Hoca verinin alındığı saat kenarını önce "T3 düşen kenar" (01:54:55), sonra hem okuma hem yazma için "T3'ün yükselen kenarı" (01:56:42) diye düzeltti. Yazma çevriminin zaman çizelgesi karelerde yok; kesin kenar doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Intel veri sayfalarında büyük olasılıkla okuma verisi T3'ün sonunda (T4'e geçişte) örneklenir; yazmada ise çevre birimleri veriyi genellikle $\overline{WR}$ işaretinin yükselen (yeniden 1'e döndüğü) kenarında alır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00)

Hafızada 100H adresinde 0FFH, 101H adresinde 99H vardır ve `MOV BX, 100H` çalıştırılmıştır. (a) `INC [BX]` neden hatalıdır? (b) `INC BYTE PTR [BX]` ve (c) `INC WORD PTR [BX]` sonrasında 100H ve 101H adreslerinin içeriği nedir?

Çözüm (derste verildi):

- (a) `INC` hafızadaki bir baytı mı word'ü mü artıracağını bilemez; operandlardan biri yazmaç olmadığı için genişlik belirsizdir.
- (b) $0FFH + 1 = 00H$ (bayta sığan kısım). 100H: 00H, 101H: 99H (değişmez).
- (c) Little endian word: 99FFH. $99FFH + 1 = 9A00H$. 100H: 00H, 101H: 9AH.

**Soru 2** (derste sözlü, 00:17:42)

`MOV AX, [BX]` komutunda BYTE PTR ya da WORD PTR kullanmak gerekir mi?

Çözüm (derste verildi): Gerekmez. AX 16 bitlik bir yazmaç olduğu için işlem genişliği bellidir; assembler işlemi 16 bitlik olarak yorumlar.

**Soru 3** (derste sözlü, 00:30:06)

Mikroişlemci açısından adres uçları giriş mi çıkış mı? Veri uçları giriş mi çıkış mı?

Çözüm (derste verildi): Adres uçları yalnız çıkıştır. Veri uçları iki yönlüdür. Bu yüzden adres ayırmada tek yönlü tutucu, veri ayırmada yönü DT/$\overline{R}$ ile belirlenen iki yönlü bir devre gerekir.

**Soru 4** (derste sözlü, 00:41:45)

M/$\overline{IO}$ adres çözümlemede kullanıldığında hafıza işlemleri için erişilebilecek kapasite ne kadardır?

Çözüm (derste verildi): 20 adres ucu olduğu için $2^{20}$ bayt = 1 MB.

**Soru 5** (ekrandan, 00:45:00; derste sözlü, 00:42:52)

`IN`/`OUT` komutlarında port adresi 8 bite sığıyorsa doğrudan, sığmıyorsa DX ile verilir (`IN AX, DX`). Buna göre G/Ç uzayının genişliği nedir?

Çözüm (derste verildi): DX 16 bit olduğu için en büyük port adresi FFFFH'dir. G/Ç uzayı $2^{16}$ bayt = 64 KB.

**Soru 6** (derste sözlü, 00:33:14)

DT/$\overline{R}$ ucu ile $\overline{RD}$/$\overline{WR}$ uçları arasındaki fark nedir?

Çözüm (derste verildi): $\overline{RD}$ ve $\overline{WR}$ bütün çevre birimlerine kadar uzanır. DT/$\overline{R}$ yalnız veriyi ayıran yardımcı devreye (245) bağlanır, dış dünyaya gitmez.

**Soru 7** (ekrandan, 01:35:00; derste sözlü, 01:32:57)

Adres değerlerini AD uçlarından saf biçimde ayırıp tutmak için bir 74LS373'ün girişlerine, $\overline{OE}$ ucuna ve LE ucuna hangi 8086 uçları bağlanmalıdır? Çıkışta ne elde edilir?

Çözüm (derste verildi): Girişlere AD uçları, LE'ye ALE, $\overline{OE}$'ye lojik 0 bağlanır. ALE 1 iken AD uçlarında adres vardır; ALE 0'a düştüğünde adres tutulur ve çıkışta saf adres uçları elde edilir.

**Soru 8** (ekrandan, 01:40:00)

74LS245'i veri ayırmak için kullanırken A yoluna, DIR ucuna ve $\overline{E}$ ucuna ne bağlanır? İşlemci veri okurken veri hangi yönde akar?

Çözüm (derste verildi): A yoluna AD uçları, DIR'e DT/$\overline{R}$, $\overline{E}$'ye $\overline{DEN}$ bağlanır. Okumada DT/$\overline{R}$ = 0 olduğu için DIR = 0 olur ve veri B yolundan (dış veri uçları) A yoluna (AD uçları) akar.

**Soru 9** (derste sözlü, 01:16:05)

8086'nın reset vektörü nedir? Resetten sonra CS ve IP hangi değerleri alır?

Çözüm (derste verildi): CS = FFFFH, IP = 0000H. Fiziksel adres $FFFFH \times 10H + 0000H = FFFF0H$. BIOS ROM'u bu adreste bulunmalıdır.

## Dersin Toparlaması

Ders, 8086'nın adresleme modlarının kısa bir tekrarıyla başladı. Segment–offset hesabı, program hafızası adreslemenin doğrudan, göreli ve dolaylı türleri, veri hafızası adreslemenin yazmaç, anlık, doğrudan ve dolaylı türleri hatırlatıldı. Köşeli parantezin anlamı ve BYTE PTR/WORD PTR gerekliliği bir sayısal örnekle gösterildi. Ardından minimum modda 8086'nın uçları tek tek ele alındı: zaman çoğullamalı AD uçları ve bunları ayırmak için ALE, $\overline{DEN}$, DT/$\overline{R}$; $\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$, $\overline{BHE}$/A0; RESET ve READY; HOLD/HLDA ile DMA; INTR/$\overline{INTA}$ ve NMI ile kesmeler. M/$\overline{IO}$'nun adres çözümlemeye katılıp katılmamasının 1 MB hafıza ve 64 KB G/Ç uzayına etkisi tartışıldı.

İkinci yarıda işlemcinin çalışması için gereken yardımcı devreler anlatıldı: 8284 saat üreteci, yol tamponlama ve yol tutma. 74LS373 tutucu, 74LS245 alıcı-verici ve 74LS244 tampon entegrelerinin çalışması ve 8086'ya bağlanışı incelendi. Bunlarla kurulan tam tamponlanmış sistem, dersin geri kalanında "adres, veri ve kontrol uçları tutulmuş ve tekrarlanmış" varsayımının dayanağı olacak. Son olarak basitleştirilmiş okuma ve yazma çevrimlerinin T1–T4 zamanlaması gösterildi. Hoca $\overline{BHE}$'nin ilerleyen derslerde adres çözümlemede kullanılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
