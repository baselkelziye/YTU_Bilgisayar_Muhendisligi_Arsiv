# Ders 11 Çalışma Özeti

## Genel Konular

- Yordamlarda yazmaçların korunması (tekrar)
  - Alt yordam çağrıldığında SP, IP ve (FAR çağrıda) CS dışındaki yazmaçlar değerlerini koruyarak alt yordama geçer. Bu, yazmaç üzerinden parametre aktarımını mümkün kılar.
  - Dezavantajı: alt yordam bir yazmacı geçici iş için kullanırsa ana yordamdaki değer bozulur. Örnek: ana yordamda döngü sayacı olan CX = 5 iken alt yordamın kendi `LOOP` döngüsü CX'i 0 yapar.
  - Kural: dönüş değeri için kullanılmayan her yazmaç alt yordam girişinde `PUSH` ile saklanır, `RET`/`RETF` öncesinde ters sırada `POP` ile geri alınır. Dönüş değerini taşıyan yazmaç (ör. AX) saklanmaz, yoksa sonuç bozulur.
- Yığın üzerinden parametre aktarımının varyasyonları (tekrar)
  - Ana yordam iki word'ü yığına atar, alt yordam sonucu AX'te döner; çöp parametreleri ana yordam kaldırır.
  - Alt yordam `RETF 4` ile döner: dönüşle birlikte SP 4 artar, iki parametre atlanmış olur. Sayı çift olmalıdır, çünkü yığına word yazılıp word okunur.
  - Sonuç yığına yazılır: alt yordam sonucu parametre gözlerinden birinin üzerine yazar. Çöp göz üstteyse alt yordam `RETF 2` ile onu atlar, ana yordam `POP` ile sonucu alır; çöp göz alttaysa ana yordam iki `POP` yapar (biri boş).
  - Yığındaki sonucu ana yordam çekmek zorundadır; çöp değeri ana yordam da alt yordam da kaldırabilir.
- Yığın çizimiyle EBOB örneği (ekrandan, 00:10:00, 00:15:00, 00:25:00, 00:30:00)
  - Ana yordam: `PUSH ASAYISI` (12), `PUSH BSAYISI` (8), `CALL _GCD_PROC`, `POP SONUC`. `_GCD_PROC` başka dosyada FAR tanımlıdır (`EXTRN _GCD_PROC:FAR`).
  - Alt yordam girişi: `PUSH BP` / `MOV BP, SP` / `PUSH AX` / `PUSH BX` / `PUSH DX`. Parametreler `MOV BX, [BP+6]` (B) ve `MOV AX, [BP+8]` (A) ile okunur.
  - Yığın (aşağıdan yukarı): OS CS, OS IP, A, B, ANA CS, ANA IP, BP, AX, BX, DX. BP, SP gibi oynamadığı için sabit referans olur; varsayılan kesimi SS'dir.
  - Çıkış: `MOV [BP+8], AX` (sonuç A'nın gözüne), `POP DX` / `POP BX` / `POP AX` / `POP BP` / `RETF 2`. Dönüşte SP, sonucu tutan gözü gösterir.
- Üçüncü parametre aktarım yöntemi: EXTRN/PUBLIC ile veri paylaşımı
  - Yazmaç yolu az sayıda veri için, yığın yolu özel durumlar ve az veri için uygundur. Dizi gibi büyük veride yığın taşabilir; veri referansla paylaşılır.
  - Veriyi tanımlayan dosya `PUBLIC DIZI, ELEMAN` der; kullanan dosya `EXTRN DIZI:WORD, ELEMAN:WORD` der. Fonksiyonlarda olduğu gibi isim ve tip birlikte yazılır.
- Örnek: dizinin minimum, ortalama ve maksimumu, dört dosya (ekrandan, 00:40:00 - 00:50:00)
  - Ana dosya: `EXTRN DIZI_MAX_F:FAR, DIZI_MIN_F:FAR, DIZI_ORT_F:FAR`, `PUBLIC DIZI, ELEMAN`; `DIZI DW 13, 12, 14, 25, 14, 12, 11, 4, 2, 12`, `ELEMAN DW 10`, `MIN DW ?`, `ORT DW ?`, `MAX DW ?`.
  - `DIZI_MIN_F PROC FAR`: `PUSH CX` / `PUSH SI` / `LEA SI, DIZI` / `MOV CX, ELEMAN` / `MOV AX, [SI]` / `DEC CX` / `TEKRAR: ADD SI,2` / `CMP AX, [SI]` / `JB L1` / `MOV AX, [SI]` / `L1: LOOP TEKRAR` / `POP SI` / `POP CX` / `RETF`.
  - `DIZI_MAX_F` aynı yapıdadır, karşılaştırmadan sonra `JAE` kullanılır.
  - `DIZI_ORT_F`: CX, BX, SI, DX saklanır; `LEA SI, DIZI` / `MOV CX, ELEMAN` / `MOV BX, CX` / `XOR AX, AX` / `XOR DX, DX` / `TEKRAR: ADD AX, [SI]` / `ADC DX, 0` / `ADD SI,2` / `LOOP TEKRAR` / `DIV BX`.
  - Her dosya ayrı derlenir, OBJ'ler birlikte linklenir. Debug sonucu: MIN = 2, ORT = 11, MAX = 25.
- Kesim (segment) birleştirme
  - PARA hizalama segmenti 16'nın katından başlatır; önceki segment 16'nın katında bitmezse arada kullanılmayan alan kalır. Her segment tanımı ayrıca segment uzayından yer kullanır.
  - Birleştirme şartı: segment adı (etiket), hizalama tipi ve sınıf adı aynı olmalı ve birleştirme tipi `PUBLIC` verilmelidir (ör. `CODESG SEGMENT PARA PUBLIC 'CODE'`).
  - Ayrı sınıflarla MAP'te altı segment vardır; birleştirmeden sonra üç segment kalır (ekrandan, 01:40:00 ve 01:50:00).
  - Kod segmentleri birleşse de ana dosyada `EXTRN` yine gereklidir; kaldırılınca MASM `Symbol not defined` hatası verir (ekrandan, 01:45:00).
  - Birleşen tek kod segmentinde yordamlar NEAR yapılıp `RET` ile döndürülebilir; Debug'da `CALL` NEAR olarak görünür. Bu yalnız alt yordamların kaynak kodu varsa yapılabilir; yalnız FAR tanımlı OBJ varsa yapılamaz.
  - Veri segmentleri de aynı şartlarla birleştirilebilir; dosyalar arası veri paylaşımı için yine EXTRN/PUBLIC gerekir.
- Sistem reseti (ekrandan, 02:00:00)
  - Resette CS = 0FFFFH, IP = 0000H. Fiziksel adres $PA = CS \times 10H + IP = 0FFFF0H$. BIOS ROM bu adresi içerecek biçimde yerleşmeli ve orada bir dallanma komutu bulunmalıdır.
  - Bayrakların hepsi sıfırlanır; DS, ES ve SS sıfır olur.
  - Sıra: güç kararlı mı (power good), sonra BIOS'un POST (Power-On Self-Test) adımı (RAM, ekran kartı, disk, klavye vb.), sonra işletim sistemine devir.
- Veri aktarım tipleri
  - Polling: işlemci cihazı sürekli "veri hazır mı" diye yoklar, meşgul kalır.
  - Kesme: cihaz hazır olunca kesme isteği gönderir, işlemci işini bırakıp kesme alt programını çalıştırır. İki yöntemde de veri CPU üzerinden geçer.
  - DMA: DMA denetleyicisi programlanır, yolların kontrolünü alır; veri CPU'ya uğramadan cihaz ile bellek arasında aktarılır.
- Kesme kaynakları (ekrandan, 02:10:00)
  - Yazılımsal: `INT n` (n 0-255 arası, kesme tipi), `INTO` (taşma kesmesi), `INT 3`; işlem sonucu oluşanlar: sıfıra bölme ve bölme taşması.
  - Donanımsal: INTR (interrupt request) ve NMI (non-maskable interrupt) uçları; INTR için onay ucu $\overline{INTA}$.
  - NMI ucundaki yükselen kenar her zaman tip 2 kesmesini tetikler; maskelenemez, acil durumlar içindir.
  - INTR ucunda bir süre lojik 1 olunca işlemci elindeki komutu bitirir, $\overline{INTA}$ ile onay verir, kesme tipini ikinci çevrimde veri yolunun düşük 8 bitinden okur. Çok kaynak için kesme denetleyicisi kullanılır.
- Kesme bayrakları ve IRET (ekrandan, 02:35:00)
  - IF = 1 değilse INTR'den gelen istekler değerlendirilmez. `STI` IF'i 1, `CLI` 0 yapar.
  - TF = 1 ise her komuttan sonra tip 1 (single-step) kesmesi oluşur; adım adım debug içindir. TF için özel komut yoktur.
  - Kesmeye girişte yığına sırasıyla bayraklar, CS, IP atılır. `IRET` yığından IP, CS ve bayrakları geri yükler.
- Kesme vektör tablosu
  - Her kesme tipi için yalnız kesme alt programının adresi (segment ve offset) tutulur, kodun kendisi tutulmaz.
  - 256 tip × 4 bayt = 1024 bayt; adres aralığı 00000H - 003FFH.
  - Tip 0 sıfıra bölme, tip 1 single-step, tip 2 NMI, tip 3 breakpoint, tip 4 taşma; diğer bölgeler BIOS/DOS'a ve kullanıcıya ayrılmıştır.
  - Tablo açılışta BIOS, sonra DOS, sonra kullanıcı programları tarafından doldurulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Alt yordamda geçici olarak kullanılan bütün yazmaçların korunması
  - Hoca bunu "temel ve çok önemli bir kural" olarak verdi. Önce ana gövde yazılır, kullanılan yazmaçlar belirlenir, sonra girişte `PUSH`, çıkışta ters sırada `POP` eklenir.
- Yığın sorularında yığını çizerek ilerlemek
  - Hangi göze `[BP+6]`, hangisine `[BP+8]` ile erişildiği, dönüşte SP'nin nereyi gösterdiği ancak çizimle güvenle bulunur.
- Word dizisinin toplamında taşma
  - Hoca bunu quiz, ödev ve vizede sık görülen büyük bir hata olarak andı. Word dizinin toplamı 16 bite sığmaz; DX:AX'te `ADD` + `ADC DX, 0` ile 32 bit biriktirilir.
- Kesim birleştirmede `PUBLIC` birleştirme tipi
  - Aynı ad, hizalama ve sınıf yetmez; derste ilk denemede `PUBLIC` unutulduğu için segmentler birleşmedi.
- Kesme vektör tablosunda yalnız adres bulunur
  - Tabloda fonksiyon kodu yoktur, yalnız segment:offset vardır; tablonun boyutu ve yeri (1024 bayt, 0H-3FFH) bilinmelidir.

## Kısa Tekrar Notları

- Geçici kullanılan yazmaç: girişte `PUSH`, çıkışta ters sırada `POP`. Dönüş yazmacı saklanmaz.
- `RETF n`: dönüşle birlikte SP $n$ artar; $n$ çifttir.
- FAR alt yordamda `PUSH BP` / `MOV BP, SP` sonrası ilk parametre gözü `[BP+6]`dır (BP, IP, CS üstte).
- Parametre aktarım yolları: yazmaç (az veri), yığın (az veri, özel durum), EXTRN/PUBLIC (büyük veri, diziler).
- Değişken için de `EXTRN ad:tip` ve tanımlandığı yerde `PUBLIC ad` gerekir.
- Kesim birleştirme: aynı ad + aynı hizalama + aynı sınıf + `PUBLIC`. Birleşen kod segmentinde çağrılar NEAR olabilir; `EXTRN` yine gerekir.
- Reset: CS = 0FFFFH, IP = 0000H, ilk komut 0FFFF0H'de; bayraklar, DS, ES, SS = 0.
- Polling, kesme, DMA: ilk ikisinde veri CPU'dan geçer, DMA'da geçmez.
- NMI → tip 2, maskelenemez. INTR → IF ile maskelenir, tip veri yolunun düşük baytından okunur.
- TF = 1 → her komuttan sonra tip 1. `STI`/`CLI` yalnız IF içindir.
- `IRET`: IP, CS, bayraklar. Vektör tablosu: 256 × 4 = 1024 bayt, 0H-3FFH.

## Detaylı Açıklamalar

- **Yazmaçların korunması.** Alt yordama geçerken yazmaçların aynen taşınması, yazmaç üzerinden parametre aktarımını bedavaya getirir. Ancak aynı özellik, alt yordamın kendi işinde kullandığı yazmaçların ana yordamın değerlerini ezmesine yol açar. Derste verilen örnekte ana yordam CX ile bir döngü yürütürken alt yordam CX'i kendi döngüsü için kullanır ve CX 0 olarak geri döner. Çözüm, dönüş değeri taşımayan her yazmacı girişte yığına atıp çıkışta ters sırada geri almaktır. Bu sıra önemlidir, çünkü `RET`/`RETF` anında yığının tepesinde yalnız dönüş adresi kalmalıdır. Debug'da da görüldü: maksimum yordamından dönüşte CX, girişteki 00FBH değerine geri yüklendi (ekrandan, 01:05:00).

- **Yığından parametre ve yığına sonuç.** EBOB örneğinde ana yordam A = 12 ve B = 8'i yığına atar ve FAR yordamı çağırır. Yordam BP'yi saklayıp `MOV BP, SP` ile sabitler, ardından AX, BX, DX'i saklar. BP'nin üstünde BP'nin kendisi, altında sırasıyla ANA IP (`BP+2`), ANA CS (`BP+4`), B (`BP+6`) ve A (`BP+8`) bulunur. `[BP+6]` adresi SS ile birlikte hesaplanır, çünkü BP'nin varsayılan kesimi SS'dir. EBOB bulunduktan sonra sonuç `MOV [BP+8], AX` ile A'nın gözüne yazılır. Saklanan yazmaçlar ters sırada geri alınır, `RETF 2` IP ve CS'yi çeker ve SP'yi 2 artırarak B gözünü atlar. Ana yordama dönüldüğünde SP sonucu tutan gözü gösterir; `POP SONUC` sonucu alır ve yığın temizlenmiş olur. Ana yordamın `RET`'i OS IP ve OS CS'yi çekerek işletim sistemine döner.

- **Özyinelemeli sürüm (isteğe bağlı ödev).** Hoca, hem ana yordamda hem alt yordamda parametrelerin yığından aktarılıp sonucun yığından döndüğü özyinelemeli EBOB'un yazılmasını ve bir A, B çifti için yığının en derin halinin Debug'da stack segment dump edilerek incelenmesini önerdi.

- **EXTRN/PUBLIC ile veri paylaşımı.** Bir dizinin tamamını yazmaçla aktarmak mümkün değildir, yığınla aktarmak büyük dizilerde yığını taşırabilir. Bu durumda veri ana dosyada tanımlanır ve `PUBLIC DIZI, ELEMAN` ile dışarıya açılır. Her alt yordam dosyası `EXTRN DIZI:WORD, ELEMAN:WORD` ile bu adları ve tiplerini bildirir; böylece tanımı içermediği halde tek başına OBJ'ye derlenebilir. Adlar linkleme aşamasında çözülür. Alt yordamlar kendi veri segmentine sahip olmadığı için DS, ana yordamın ayarladığı değerle (Debug'da 076EH) olduğu gibi gelir ve doğru veriyi gösterir. Alt dosyanın kendi veri segmenti olsaydı DS ayarı gerekebilirdi.

- **Minimum ve maksimum.** İlk eleman AX'e alınır ve şimdilik en küçük (ya da en büyük) kabul edilir. İlk eleman işlendiği için döngü `DEC CX` ile eleman sayısından bir eksik döner. Her adımda SI 2 artırılır (word dizi), AX sıradaki elemanla karşılaştırılır. Minimumda AX küçükse (`JB L1`) bir şey yapılmaz, değilse yeni eleman AX'e alınır. Maksimumda ise AX büyük ya da eşitse (`JAE`) geçilir. Sonuç AX'te döner; AX bu yüzden saklanmaz, yalnız CX ve SI saklanır.

- **Ortalama ve 32 bit toplam.** Word dizide eleman sayısı ve her eleman en çok word kadar olabilir. Bunların toplamı 16 bite sığmaz, ama 32 bite sığar. 8086'da 32 bit toplama komutu yoktur, bu yüzden toplama yazılımla yapılır. `DIV BX` zaten DX:AX'i böldüğü için toplam DX:AX çiftinde tutulur. `ADD AX, [SI]` düşük word'ü toplar, `ADC DX, 0` oluşan eldeyi yüksek word'e ekler (onlu toplamada elde gibi). `LOOP` CX'i sıfırlayacağı için eleman sayısı önceden BX'e kopyalanır, döngü sonunda `DIV BX` ile bölüm AX'te oluşur. DX'teki kalan kullanılmaz. Debug'da bölümden sonra AX = 000BH (11) oldu (ekrandan, 01:05:00). Dizi için toplam 119, 119 / 10 = 11 (kalan 9).

> **Ders sonrası not:** Hoca word sınırını "65531" olarak söyledi; 16 bitlik işaretsiz en büyük değer 65535'tir. $65535 \times 65535 = 4\,294\,836\,225 < 2^{32}$ olduğundan toplam 32 bite sığar.

- **Derleme ve linkleme.** Dört ASM dosyası (`301115_1_1` ... `301115_1_4`) ayrı ayrı MASM ile derlendi, sonra `LINK.EXE 301115~1.OBJ + 301115~2.OBJ + 301115~3.OBJ + 301115~4.OBJ` ile birlikte linklenip `MOM.EXE` üretildi (ekrandan, 01:00:00). Alt dosyalarda `END`'den sonra giriş noktası yoktur; giriş noktası yalnız ana dosyadadır.

- **Kesim birleştirme ve MAP dosyası.** İlk sürümde alt dosyaların kod segmentleri aynı adı (`CODESG`) taşısa da farklı sınıflara sahipti; MAP'te altı ayrı segment göründü: STACKSG 00000H-0003FH (40H), DATASG 00040H-0005BH (1CH), CODESG 00060H-00081H (22H, CODE), 00090H-000AAH (CODE3), 000B0H-000D2H (CODE1), 000E0H-000FAH (CODE2) (ekrandan, 01:50:00). Yığın 64 bayt olduğu için tam hizalıdır. Veri segmenti 14 word yani 28 bayt kaplar, ama sonraki kod segmenti PARA hizalı olduğundan 5CH-5FH boş kalır. Ana kod segmenti 34 bayttır, 82H-8FH arası 14 bayt boşa gider; diğer segmentlerin arasında da benzer boşluklar vardır. Segmentleri birleştirmek için dört dosyada da `CODESG SEGMENT PARA PUBLIC 'CODE'` yazıldı. Sonuçta MAP'te tek bir CODESG 00060H-000FAH (9BH) kaldı ve toplam üç segment oldu (ekrandan, 01:40:00).

> **Ders sonrası not:** Hoca birleştirmeyle kullanılmayan alanın dörtte birine indiğini söyledi. MAP'te birleşik CODESG'nin başı ve sonu (00060H-000FAH) birleştirme öncesiyle aynıdır. Uzunluk 9BH = 155 bayttır; parçaların toplamı ise 22H + 1BH + 23H + 1BH = 123 bayttır. Bu, her parçanın PARA hizalamasını koruduğunu ve aradaki boşlukların büyük olasılıkla birleşik segmentin içinde kaldığını gösterir. Bu örnekte birleştirmenin asıl kazancı segment sayısının azalması ve çağrıların NEAR yapılabilmesidir. İç boşlukları gidermek için büyük olasılıkla alt dosyalarda BYTE ya da WORD hizalama gerekir; hoca da hizalama tiplerinin değiştirilerek denenebileceğini söyledi.

- **Birleşik kod segmentinde NEAR çağrı.** Bir öğrenci, aynı segmentte olan yordamların NEAR tanımlanıp tanımlanamayacağını sordu. Önce yalnız segmentler birleştirildi: yordamlar hâlâ FAR tanımlı olduğundan `CALL` FAR kaldı. Sonra yordamlar NEAR yapılıp `RETF`'ler `RET`'e çevrildi; çağrı satırında değişiklik gerekmedi ve Debug'da `CALL` NEAR olarak göründü. NEAR çağrıda yığına yalnız offset atılır, yalnız IP değişir ve dönüşte yalnız IP çekilir. Ana dosyadaki `EXTRN` kaldırılınca ise MASM üç `Symbol not defined` hatası verdi; her dosya tek başına derlendiği için dış adların bildirilmesi şarttır.

- **Reset ve açılış.** Reset anında CS = 0FFFFH ve IP = 0000H yüklenir, ilk komut $0FFFF0H$ fiziksel adresinden alınır. BIOS ROM bu adresi içerecek şekilde yerleşmeli, orada bir dallanma komutu bulunmalıdır. Bayraklar, DS, ES ve SS sıfırlanır. Önce güç kararlılığı (power good sinyali) beklenir, sonra BIOS POST adımlarıyla donanımı denetler ve kontrolü işletim sistemine verir.

- **Kesmeler.** Klavye örneğinde polling işlemciyi sürekli meşgul eder; kesmede işlemci başka işler yaparken tuşa basılınca kesme alt programına geçer. DMA'da ise veri CPU'ya hiç uğramaz. Yazılımsal kesmeler `INT n`, `INTO`, `INT 3` komutlarından ya da sıfıra bölme ve bölme taşmasından doğar. Donanımsal kesmelerde NMI her zaman tip 2'yi tetikler; INTR'de tip, $\overline{INTA}$ onayından sonra veri yolunun düşük baytından okunur. IF yalnız INTR'yi maskeler. TF = 1 iken her komuttan sonra tip 1 single-step kesmesi oluşur. Kesmeye girişte yığına bayraklar, CS ve IP atılır, `IRET` üçünü geri yükler. Kesme vektör tablosu 00000H-003FFH arasında 256 adet 4 baytlık gözden oluşur ve her gözde yalnız ilgili alt programın segment:offset adresi bulunur.

> **Ders sonrası not:** Hoca TF için `LAHF`/`SAHF` komutlarının kullanılabileceğini de söyledi. Bu komutlar yalnız bayrak yazmacının düşük baytını (SF, ZF, AF, PF, CF) AH'ye taşır; TF 8. bittedir ve onlarla değiştirilemez. TF'yi değiştirmenin yolu hocanın andığı ikinci yöntemdir: bayraklar `PUSHF` ile yığına atılır, yığında bit işlemi yapılır, `POPF` ile geri yüklenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
