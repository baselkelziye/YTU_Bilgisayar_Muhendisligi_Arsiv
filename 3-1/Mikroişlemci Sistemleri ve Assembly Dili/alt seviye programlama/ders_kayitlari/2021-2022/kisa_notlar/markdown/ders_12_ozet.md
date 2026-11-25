# Ders 12 Çalışma Özeti

## Genel Konular

- Yordam (prosedür) tanımı ve tipleri (ekrandan, 00:15:00)
  - Yazım: `yordam_ismi PROC FAR|NEAR` ... `RET`/`RETF` ... `yordam_ismi ENDP`. Bir kod kesimine birden fazla yordam yazılabilir; hepsi kesimin 64 KB'ına sığmalıdır.
  - `FAR` yordam kesimler arası (intersegment), `NEAR` yordam kesim içi (intrasegment) dallanma içindir. FAR yordam `RETF` ile, NEAR yordam `RET` ile biter.
  - Yordam `CALL yordam_ismi` ile çağrılır. Bir yordam istenildiği kadar, döngü içinde ya da farklı yerlerden çağrılabilir.
- NEAR çağrının yığına etkisi (ekrandan, 00:20:00)
  - `CALL`, bir sonraki komutun ofsetini (dönüş adresi, 1 word) yığına atar ve hedef yordamın ilk komutuna dallanır.
  - `RET`, yığının tepesindeki word'ü IP'ye alır ve akış CALL'dan sonraki komuttan devam eder.
- Örnek 1: üs alma yordamı, EXE tipi, yazmaçla parametre aktarma (ekrandan, 00:30:00, 00:35:00, 00:50:00)
  - Akış: `sayi`, `ust` okunur → `ustal(sayi, ust)` çağrılır → sonuç yazmaçtan alınır → `sonuc`a yazılır. Örnekte $2^{10} = 1024$.
  - Parametreler yazmaçla verilir: `MOV CX, ust`, `MOV BX, sayi`, `CALL ustal`; sonuç AX'te döner: `MOV sonuc, AX`.
  - Yordam: `PUSH CX` / `PUSH DX` / `MOV AX, 1` / `L1: MUL BX` / `LOOP L1` / `POP DX` / `POP CX` / `RET`.
  - `MOV CX, ust` için `ust` word (`DW 10`) tanımlanır; byte tanımlayıp CX'i ayrıca sıfırlamaya gerek kalmaz. `sayi` da BX ile kullanılacağı için `DW 2` yapıldı.
  - 8 bitlik `MUL BL` (AX ← AL · BL) yetmez: AL taşınca sıfırlanır ve sonraki bütün çarpımlar 0 çıkar. 16 bitlik `MUL BX` (DX:AX ← AX · BX) kullanılır; 1024 AX'e sığar, DX hep 0 kalır.
  - DEBUG'da sonuç veri kesiminin 4. ofsetinde `00 04` (little endian), yani $0400_h = 1024$ olarak görüldü (ekrandan, 00:45:00).
- Yordamda yazmaç koruma
  - Yordam, çağıranın hangi yazmaçları kullandığını bilmez; değerini bozduğu her yazmacı girişte yığına atmalı, çıkışta geri almalıdır.
  - CX (LOOP ile 0'a iner) ve DX (MUL onu sıfırlar) korunur. Sonuç AX'te döndüğü için AX korunmaz. BX değişmediği için saklanmaz.
  - `POP` sırası `PUSH` sırasının tersidir (LIFO).
- FAR çağrı ve ayrı dosyadaki yordam (ekrandan, 00:55:00, 01:00:00, 01:10:00)
  - FAR `CALL` yığına önce CS'yi, sonra dönüş ofsetini atar (2 word, SP 4 azalır). `RETF` ikisini geri alır (SP 4 artar).
  - Yordamı kullanan dosyada `EXTRN` sözde komutuyla yordamın dışarıda ve FAR olduğu bildirilir; yordamın bulunduğu dosyada `PUBLIC` ile dışa açılır. PUBLIC yazılmazsa varsayılan özeldir.
  - Örnek 2: BL ve BH'deki iki sayıyı toplayıp sonucu AX'te döndüren `TOPLAMA PROC FAR`, ayrı bir kod kesiminde ve ayrı dosyada. Gövde: `XOR AX, AX` / `MOV AL, BL` / `ADD AL, BH` / `ADC AH, 0` / `RETF`.
  - İki dosya ayrı ayrı MASM ile derlenir, `LINK b.obj + c.obj` ile tek EXE yapılır. EXE adı sorulduğunda yeni ad verilebilir.
  - $170 + 172 = 342$: `AA + AC` → AL = 56, CF = 1; `ADC AH, 0` ile AX = $0156_h$ (ekrandan, 01:10:00).
- Makrolar (ekrandan, 01:30:00, 01:45:00)
  - Yazım: `makro_ismi MACRO param1, param2` / `LOCAL etiketler` / gövde / `ENDM`. ENDM'den önce makro adı yazılmaz. Parametrelere tip yazılmaz.
  - Makro çağrılınca gövdesi o yere kopyalanır; CALL/RET, yığın kullanımı ve dallanma yoktur. Her çağrı kodu makronun boyu kadar büyütür.
  - Makro, çağrıldığı yerden önce tanımlanmış olmalıdır. Yordamlarda yazım sırası önemli değildir.
  - Makro içindeki etiketler `LOCAL` ile yerel yapılır; yoksa her kopyada aynı etiket tekrar eder.
- Örnek 3: dizinin elemanlarını 2'ye bölen ana yordam ve en küçük elemanı bulan makro, COM tipi (ekrandan, 01:45:00, 01:50:00, 01:55:00)
  - Ana yordamda `SAR dizi[SI], 1` ile her eleman 2'ye bölünür. İşaretli dizide `SHR` değil `SAR` kullanılır.
  - `ENKCK MACRO dizi, n` ilk elemanı AL'ye alır, kalan `n-1` elemanı `CMP AL, dizi[SI]` / `JL don` / `MOV AL, dizi[SI]` ile tarar. Sonuç `MOV kck, AL` ile yazılır.
  - Dizi `10, -2, 4, 6, 10, 3, 5, 17` → yarıları `5, -1, 2, 3, 5, 1, 2, 8` → en küçük $-1 = FF_h$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yığın her zaman word genişliğindedir
  - Yığını `DB 40 DUP(?)` ya da `DW 20 DUP(?)` diye tanımlamak arasında boyut ve genişlik farkı yoktur. Byte tanımlamak, yığına byte atılabileceği anlamına gelmez; yığına her seferinde bir word atılır.
- Yazmaçla parametre aktarma
  - Yazmaçlar donanım birimidir, her yordam için ayrı kopyası yoktur. Değeri yazmaca koyup CALL yapınca yordam aynı değeri aynı yazmaçta bulur. Yazmaç sayısı sınırlı olduğu için bu yöntemle aktarılabilecek parametre sayısı da sınırlıdır.
- Kullandığın yazmaçları koru
  - Yordamı yazan, çağıranın kodunu görmeyebilir. Bu yüzden değerini değiştirdiği yazmaçları PUSH/POP ile korumak bir alışkanlık olmalıdır.
- Sözde komut ile komut (mnemonic) ayrımı
  - `MACRO`, `LOCAL`, `ENDM`, `PROC`, `ENDP`, `SEGMENT`, `PARA`, `ASSUME`, `ORG`, `EXTRN`, `PUBLIC` sözde komuttur; komut kümesinde bulunmazlar. `XOR` gibi komutlar mnemoniktir. Hoca bu ayrımın sınavda sorulduğunu belirtti.
- Makro önce tanımlanır
  - Makro çağrılmadan önce yazılmış olmalıdır; yordamda böyle bir kısıt yoktur.

## Kısa Tekrar Notları

- `NEAR`: kesim içi, CALL yığına yalnız IP atar, `RET` ile döner.
- `FAR`: kesimler arası, CALL yığına CS ve IP atar, `RETF` ile döner.
- Başka dosyadaki yordam: kullanan tarafta `EXTRN`, tanımlayan tarafta `PUBLIC`; derle, sonra `LINK a.obj + b.obj`.
- 8 bit `MUL r8`: AX ← AL · r8. 16 bit `MUL r16`: DX:AX ← AX · r16.
- Yordama girerken bozulan yazmaçları PUSH, çıkarken ters sırayla POP.
- Sonucun döndüğü yazmaç (burada AX) korunmaz.
- Yığın `DW 20 DUP(?)` = 40 byte = $28_h$; DEBUG'da başlangıç SP = 0028.
- 2'ye bölme: işaretsizde `SHR`, işaretlide `SAR`; 2 ile çarpma: `SHL`. DIV de olur ama daha yavaştır.
- Makro: kopyala-yapıştır, çağrı maliyeti yok, kod büyür; `LOCAL` ile yerel etiket.
- Sonucun sığacağı tipi seç: DB, DW, DD (4 byte), DQ (8 byte), DT (10 byte).

## Detaylı Açıklamalar

- NEAR yordamın DEBUG'da izlenmesi (ekrandan, 00:45:00)
  - `U` ile bakıldığında `CALL ustal` satırı `CALL 0018` olarak görünür: assembler yordam adını hedef ofsete çevirmiştir. CALL komutu 0011 ofsetinde ve 3 byte olduğu için dönüş adresi 0014'tür.
  - CALL'dan önce SP = 0024'tür (başlangıçtaki 0028'den `PUSH DS` ve `PUSH AX` ile 4 byte azalmış). CALL ile SP = 0022 olur ve SS:0022'de 0014 görülür. `PUSH CX` ile SP = 0020 olur ve orada CX'in değeri (000A) görülür; `PUSH DX` ile SP bir word daha azalır.
  - Döngüde AX sırasıyla 2, 4, 8, ... olur. LOOP'u adım adım izlemek yerine DEBUG'ın `P` (proceed) komutu döngüyü bir seferde geçer.
  - `POP DX`, `POP CX`, `RET` ile SP yeniden 0024'e çıkar, IP = 0014 olur. Sonuç `MOV [0004], AX` ile `sonuc`a yazılır. `RETF` ile ana yordam bittiğinde SP 0028'e döner.
- 8 bitlik çarpmada taşma (ekrandan, 00:35:00, 00:40:00)
  - `MUL BL` ile AL'de 1, 2, 4, ..., 128 oluşur. 128 · 2 = 256 = $0100_h$ olduğunda AH = 1, AL = 0 olur. Sonraki adımda AL (0) · 2 = 0 yazıldığı için AX tamamen 0'a iner ve sonuç bundan sonra hep 0 kalır.
  - Ders sonrası not: hoca taşmanın 64 · 2 = 128 adımında olduğunu, AL'nin en çok 127 tutabileceğini söyledi. `MUL` işaretsiz çarpmadır ve AL'ye 255'e kadar sığar; 128 = $0080_h$ sığar, taşma bir sonraki adımda (256) olur (python ile kontrol edildi). Sonuç değişmez: $2^{10}$ 8 bitlik çarpımla bulunamaz.
- Neden DX korunur? (derste sözlü, 00:49:18)
  - Bir öğrenci, DX'in nasılsa çarpmada sıfırlandığını, yığına atmaya gerek olup olmadığını sordu. Cevap: yordamı çağıran kod DX'te kendi değerini tutuyor olabilir (örneğin `MOV DX, 2` sonra çağrıdan dönünce `CMP DX, AX`). MUL DX'i sıfırladığı için o değer bozulur; bu yüzden DX korunmalıdır.
- Sonuç AX'e sığmazsa (derste sözlü, 00:51:17)
  - Bir öğrenci, üs büyürse sonucun AX'e sığmayacağını sordu. Hoca örneğin sınırlar içinde sığacağı varsayımıyla yazıldığını, daha büyük değerler için sonuç değişkeninin tipinin büyütülmesi gerektiğini söyledi.
- FAR çağrının DEBUG'da izlenmesi (ekrandan, 01:05:00, 01:10:00)
  - Ana kod 076E kesiminde, TOPLAMA 0770 kesimindedir. Program başında DS = 075A'dır; `MOV AX, myd` / `MOV DS, AX` ile 076D olur. Veride `AA` (170) ve `AC` (172) görülür.
  - CALL öncesi SP = 0024, sonrası 0020; yığında dönüş ofseti 0016 ve kesim 076E görülür. CS 0770, IP 0000 olur.
  - `ADD AL, BH` sonrası AX = 0056 ve CY (elde) bayrağı kurulur; `ADC AH, 00` sonrası AX = 0156. `RETF` ile SP = 0024, CS = 076E, IP = 0016 olur; `MOV [0002], AX` sonucu yazar. DEBUG'da veri kesimine bakıldığında sonuç 0156 olarak görülür.
  - FAR çağrıda yalnız CS değişir; DS ve SS aynı kalır. Bu yüzden diğer kesimdeki yordam aynı veri kesimine ve aynı yığına erişir (derste sözlü, 01:54:34).
- Aynı adlı yordam ve NEAR seçeneği (derste sözlü, 01:10:32, 01:11:48)
  - İki ayrı dosyada aynı adlı `TOPLAMA` varsa ve üçü birlikte link edilirse çakışma olur. Yalnız biri link edilirse sorun çıkmaz.
  - Her şey tek kesimde (örneğin COM programında) yazılacaksa yordamlar NEAR yazılır, EXTRN/PUBLIC gerekmez.
- Makro örneğinin DEBUG'da izlenmesi (ekrandan, 01:50:00)
  - COM dosyası 53 byte (CX = 0035). Dizi 012A ofsetinden başlar, `n` 0132'de, `kck` 0134'tedir. `SAR` DEBUG'da `SAR BYTE PTR [SI+012A], 1` olarak görünür.
  - Makro çağrısının yerinde makronun komutları açılmış olarak görülür. Makro ikinci kez çağrıldığında aynı komutlar yeniden kopyalanır; yerel etiketler bu kopyada farklı ofsetlere (0123 yerine 013F) dallanır (derste sözlü, 01:53:32).
- Adres aktarma (pointer) fikri (derste sözlü, 01:57:06)
  - Hoca sözde kodla gösterdi: ana yordamda `LEA SI, sayi1` ile değişkenin adresi alınır, `PUSH SI` ile yığına atılır; çağrılan yordam bu adresi yığından alıp o adrese `MOV` ile yazabilir. Bu yöntemler sonraki derste ayrıntılı işlenecek.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
