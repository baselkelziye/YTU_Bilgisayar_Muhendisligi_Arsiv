# Ders 2 Çalışma Özeti

## Genel Konular

- Genel tanımlar: real, protected ve virtual mod
  - Bu modlar mikroişlemcinin hafızaya nasıl eriştiğini tanımlar.
  - Real mod 8086'nın erişim biçimidir: herhangi bir program 1 MB'lık alanın tamamına erişebilir. Bu, bir yazılımın işletim sistemi dosyalarına da dokunup zarar verebilmesi anlamına gelir.
  - Protected modda her program parçası için çalışacağı adres aralığı ve izinler bir tablo üzerinden tanımlanır. Program yalnız kendisine ayrılan alanı görür. Bu mod 1 MB'tan fazla hafızası olan (20'den fazla adres ucu olan) sonraki Intel işlemcilerinde kullanılır.
  - 80x86 ailesindeki bütün bilgisayarlar ilk açılışta real modda başlar.
- Prefetch queue ve pipeline
  - Prefetch queue, 8086 iç yapısında gördüğümüz komut kuyruğudur (Instruction Queue, 6 gözlü; ekrandan, 00:35:00).
  - Pipeline, birim zamanda işlenen komut sayısını artıran bir optimizasyondur. Komut yürütme beş fonksiyonel bloğa bölünür: Instruction Fetch (IF), Instruction Decode (ID), Operand Fetch (OF), Execute (EX), Write Back (WB) (ekrandan, 00:15:00).
  - Her blok aynı anda farklı bir komutun bir parçasını işler, böylece beş blokta beş farklı komut ilerler.
  - 8086'da pipeline yoktur, sonraki işlemcilerde ortaya çıkar.
- Offset memory model (segment:offset ile fiziki adres)
  - 8086'da 20 adres ucu, 16 veri ucu vardır, yazmaçlar 16 bittir. 20 bitlik adresi tek yazmaç üretemez.
  - Fiziki adres: $PA = \text{segment} \times 10H + \text{ofset}$ (ekrandan, 00:20:00).
  - 10H ile çarpmak 16 ile çarpmak, yani 4 bit sola kaydırmak (sağa bir onaltılık 0 eklemek) demektir. 16 bitlik segment değeri böylece 20 bite çıkar.
  - Birbiriyle örtüşmeyen $1\text{M} / 64\text{K} = 16$ segment tanımlanabilir. Ofset, 64 KB'lık segment içinde gezinmeyi sağlar.
  - Varsayılan eşleşmeler (ekrandan, 00:30:00): Veri: $DS \times 10H + (SI, DI, BX)$; Kod: $CS \times 10H + IP$; Yığın: $SS \times 10H + (SP, BP)$.
  - Örnek: DS = 1230H, SI = 0045H ise fiziki adres 12345H olur.
  - Segmentler örtüşebildiği için aynı fiziki adres farklı segment:ofset çiftleriyle üretilebilir.
- Time multiplexing (zaman çoğullama)
  - 20 adres + 16 veri + yaklaşık 4 besleme + 10'dan fazla kontrol ucu en az 50 uç ister, ama 8086'nın 40 bacağı vardır.
  - Bu yüzden bazı uçlar farklı zamanlarda farklı görev yapar: T1 anında adres, T2 anında veri. Uçta adres mi veri mi olduğunu ALE (Address Latch Enable) ucu gösterir.
  - Karşılaştırma: Wi-Fi gibi sistemlerde 2.4 GHz civarında herkes farklı bir alt bantta haberleşir, bu frekans çoğullamadır.
- Coprocessor (yardımcı işlemci)
  - Matematik işlemci uzun süre işlemcinin içinde değildi, ayrı bir yardımcı işlemci olarak sağlanıyordu. 8086'nın yardımcı matematik işlemcisi 8087'dir.
  - 8086 yalnız maksimum modda yardımcı işlemciyle çalışabilir. Derste 8086 minimum modda kullanılacaktır.
- Cache (önbellek)
  - Hafıza hiyerarşisinde yazmaçlarla RAM arasındadır: RAM'den hızlı, yazmaçlardan yavaş; kapasitesi yazmaçlardan büyük, RAM'den küçüktür (KB, L2/L3'te MB mertebesi).
  - İstenen veri cache'te yoksa RAM'den veri ve çevresindeki blok cache'e kopyalanır.
  - Spatial locality: bir veriye erişildiyse komşu verilere de erişilmesi olasıdır (dizi üzerinde döngü).
  - Temporal locality: aynı veriye kısa süre içinde tekrar erişilmesi olasıdır (döngüde biriktirilen `sum` değişkeni).
  - Günümüzde cache işlemcinin içindedir, L1, L2, L3 seviyeleri vardır.
- 8086 iç yapısı ve yazmaçlar
  - İç yapıda BIU (CS, DS, SS, ES, IP, adres toplayıcı, 6 gözlü komut kuyruğu) ve EU (genel amaçlı yazmaçlar, ALU, bayraklar, EU kontrol) bulunur (ekrandan, 00:35:00).
  - AX (akümülatör, AH/AL), BX (base, BH/BL), CX (count, CH/CL), DX (data, DH/DL), SP, BP, SI, DI, segment yazmaçları CS, DS, SS, ES ve IP (ekrandan, 00:40:00).
- Bayrak yazmacı
  - CF, PF, AF, ZF, SF durum bayrakları; TF, IF, DF ayar bayrakları; OF taşma bayrağı (ekrandan, 00:50:00 ve 00:55:00).
- Real mod hafıza adresleme
  - Segment sabitken ofset 0000H–FFFFH arasında değişir, bu yüzden bir segment 64 KB'lık alanı gösterir.
  - Örnek: segment 1000H, ofset 2000H ise $1000H \times 10H + 2000H = 12000H$; gösterim `1000H:2000H` (ekrandan, 01:00:00).
- Adresleme modları
  - Komutlar 0, 1 ya da 2 açık operand alır. 8086'da açık 3 operandlı komut yoktur, ama gizli operandlı komutlar vardır (`MUL BX`).
  - Genel yapı: `MOV AX, BX` ifadesinde AX hedef (destination), BX kaynaktır (source). Sonuç komuta yakın olan operandda saklanır (ekrandan, 01:05:00).
  - Veri adresleme: yazmaç, hemen (immediate), doğrudan, yazmaç dolaylı, taban+indeks, taban+indeks+sabit.
  - Program hafızası adresleme: doğrudan (far jump/call), göreli (near jump), dolaylı (`JMP BX`, `JMP [BX]`).
  - Yığın adresleme: PUSH ve POP; varsayılan SS ve SP.
- 8086 uç tanımlarına giriş
  - Uçlar maksimum ve minimum moda göre farklı tanımlanır. Mod seçimi MN/MX ucuyla yapılır.
  - AD0–AD15 zaman çoğullamalı adres/veri uçlarıdır; A16/S3–A19/S6 adresi durum bitleriyle paylaşır.
  - ALE adres anını, /DEN veri anını gösterir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fiziki adres hesabı ve varsayılan segment/ofset eşleşmeleri
  - Veri erişiminde köşeli parantez içinde ofset olarak yalnız BX, SI, DI kullanılabilir; AX, CX, DX kullanılırsa assembler hata verir. Yığın erişiminde BP kullanılır.
  - IP'ye doğrudan değer yazılamaz; ardışık komutlarda komut boyu kadar artar, jump ile değişir. CS'ye değer yazılabilir.
- Bir fiziki adres tek bir segment:ofset çiftiyle üretilir ifadesi yanlıştır
  - Segmentler örtüşebildiği için farklı çiftler aynı adresi verebilir.
- Zero flag karışıklığı
  - Sonuç 0 olunca ZF = 1 olur. Hoca bunun sık karıştırıldığını özellikle belirtti.
- BYTE PTR / WORD PTR zorunluluğu
  - `INC [BX]` gibi bir komutta byte mı word mü artırılacağı belli değildir. Derste bu durumlarda veri tipinin açıkça yazılması kararlaştırıldı.
  - Operandlardan biri yazmaçsa (`MOV AX, [100H]`) yazmacın genişliği veri tipini belirler, PTR gerekmez.
- IN/OUT komutlarında AX/AL ve DX
  - Assembly dersinde pek kullanılmayan IN ve OUT komutları bu derste sık kullanılacak. Veri AX/AL'de, port numarası DX'tedir (`MOV DX, 200H` ve `IN AX, DX`).
- MN/MX gösterimi
  - Uç adındaki üst çizgi (ya da `/`) aktif 0 anlamına gelir. MN/MX = 0 maksimum mod, 1 minimum moddur. Minimum mod için uca 1 verilir. Bu gösterim ders boyunca kullanılacak.
- ALE ve /DEN mantığı
  - ALE 1 iken AD uçlarındaki adres yakalanıp tutulur; /DEN 0'a düşünce uçlardaki değer veri olarak alınır. Hoca bu iki mantığın sonraki konular için önemli olduğunu söyledi.

## Kısa Tekrar Notları

- Real mod: 1 MB'ın tamamına erişim, koruma yok. Protected mod: tabloyla tanımlı adres aralığı ve izinler.
- Pipeline: IF, ID, OF, EX, WB; birim zamanda daha çok komut. 8086'da yok.
- $PA = \text{segment} \times 10H + \text{ofset}$; 10H ile çarpmak = 4 bit sola kaydırma.
- 1 MB içinde 16 örtüşmeyen 64 KB'lık segment.
- Kod: CS:IP; veri: DS:(BX, SI, DI); yığın: SS:(SP, BP); katar hedefi: ES:DI.
- DS = 1230H, SI = 0045H → 12345H; 1000H:2000H → 12000H.
- 8086: 20 adres, 16 veri ucu, 40 bacak → zaman çoğullama; ALE adres, /DEN veri anı.
- 8087, 8086'nın yardımcı matematik işlemcisi; yalnız maksimum modda.
- Cache: spatial ve temporal locality.
- CX: LOOP sayacı; CL: çoklu öteleme sayısı. DX:AX: MUL/DIV sonucu; DX: port numarası.
- SP her PUSH/POP'ta 2 değişir; yığın işlemleri word tipindedir, `PUSH BL` yanlıştır; CS'ye POP yapılamaz ama CS yığına basılabilir.
- CF: işaretsiz taşma; OF: işaretli taşma; ZF: sonuç 0 ise 1; AF: 4 bitlik elde; PF: 1'lerin sayısı çiftse 1.
- TF: her komuttan sonra kesme (adım adım debug); IF: INTR dış kesmelerine izin; DF: katar işlemlerinde yön.
- 8086'da genel amaçlı 1 bitlik bayrak yoktur.
- Hemen adresleme: `MOV AL, 0F2H` (harfle başlayan hex sayıya 0 eklenir), `MOV CX, 100` (onluk), `MOV BL, 01010101B`, `MOV AH, 'A'`.
- Near jump işlemi işaretli sayı alır: `JMP 0FFH` → IP 1 azalır.

## Detaylı Açıklamalar

- **Pipeline örneği.** Komut yürütme tek bir blok olsaydı birim zamanda bir komut girip bir komut çıkardı. Beş bloğa bölününce, birinci komut yalnız geri yazma (WB) aşamasındayken ikinci komut yürütülür (EX), üçüncünün operandları çekilir (OF), dördüncü çözülür (ID), beşinci hafızadan alınır (IF). Hoca bunu tahtada IF, ID, OF, EX, WB kutularıyla merdiven biçiminde çizdi (ekrandan, 00:15:00).

- **Offset memory model.** Segment yazmacı 16 bittir. 10H ile çarpılınca sağına dört sıfır biti eklenmiş olur ve değer 20 bite çıkar. Buna 16 bitlik ofset eklenir. Örneğin DS = 1230H ve SI = 0045H için önce DS'nin sonuna bir onaltılık 0 eklenir (12300H), sonra SI eklenir: $12300H + 0045H = 12345H$. Segmentler 16 baytlık adımlarla başlayabildiği için örtüşebilir; bu yüzden aynı fiziki adres birden fazla segment:ofset çiftiyle üretilebilir.

- **Segmente göre ofset yazmaçları.** Kod erişiminde CS ile IP kullanılır. Yığın erişiminde SS ile SP ya da BP kullanılır: SP, PUSH/POP ve CALL/RET ile otomatik değişir. BP ise yığından parametre aktarırken alt programa girer girmez SP'nin kopyalandığı sabit referanstır; böylece alt program içinde yığına yeni değerler atılıp SP değişse de parametrelerin yeri kaybolmaz. Veri erişiminde DS ile BX, SI, DI kullanılır.

- **Zaman çoğullama ve ALE.** `MOV AX, [100H]` komutunda varsayılan segment DS'dir ve ofset 100H'dır (ekrandan, 00:30:00). İşlemci önce fiziki adresi uçlara çıkarır, sonra gelen veriyi aynı uçlardan alır. Komut dört zaman diliminde yürür: T1'de ortak uçlarda adres, T2'den itibaren veri bulunur. ALE ucu adres anını bildirir.

- **Yazmaçların özel görevleri.**
  - AX akümülatördür; akümülatöre özel komutlar daha hızlı çalışır. IN ve OUT komutlarında veri AX/AL'dedir.
  - BX taban yazmacıdır; dolaylı adreslemede görece adres üretir.
  - CX, LOOP komutunda her turda 1 azalır ve 0 olunca döngü biter. Çoklu ötelemede CL kullanılır; 16 bitlik bir yazmaç en fazla 16 kez ötelenebildiği için 8 bit yeterlidir.
  - DX, çarpma ve bölmede gizli operanddır ve IN/OUT komutlarında port numarasını tutar.
  - SI ve DI, katar (string) işlemlerinde kaynak ve hedef indeksidir. Katar işlemi bir hafıza bloğunu başka bloğa kopyalamak, bir bloğu bir değerle doldurmak ya da iki bloğu karşılaştırmaktır. SI, DS ile; DI, ES ile kullanılır.

- **Bayraklar.**
  - CF: işaretsiz işlemlerde taşma olursa 1 olur. Toplamada elde üretilmesi de aynı şeydir.
  - PF: sonuçtaki 1 olan bitlerin sayısı tekse 0, çiftse 1 olur (ekrandan, 00:50:00). Hoca eşlik bitinin seri haberleşmede de kontrol biti olarak kullanıldığını, çift ve tek eşlik kavramlarını anlattı.
  - AF: 4 bitlik kısımların toplama-çıkarma eldesidir. `ADD AL, AH` işleminde düşük 4 bitten yüksek 4 bite elde geçerse AF = 1 olur.
  - ZF: sonuç 0 ise ZF = 1 olur.
  - SF: sonuç negatifse SF = 1 olur.
  - TF: her komuttan sonra kendisine bağlı kesme alt programını tetikler. Adım adım debug için kullanılır: kesme alt programı her adımda örneğin AX'i bir LCD'ye yazar ve bir tuşa basılmasını bekler.
  - IF: 8086'nın INTR ucuna dış kesme isteği gelince IF = 1 ise istek değerlendirilir, IF = 0 ise değerlendirilmez.
  - DF: DF = 0 iken katar işlemlerinde her adımda bir sonraki hafıza gözüne ilerlenir, CX her adımda 1 azalır ve 0 olunca işlem biter. Slayta göre DF erişimin artarak ya da azalarak yapılacağını belirler (ekrandan, 00:55:00). <!-- BELİRSİZ: DF = 1 durumunun sözlü açıklaması kayıtta kesik (00:54:55–00:55:27). -->
  - OF: işaretli işlemlerde sonuç yazmaca sığmazsa 1 olur. 8 bitlik işaretli sayılar $-128$ ile $127$ arasındadır; $127 + 100$ bu aralığa sığmaz. Bölme, çarpma ve öteleme de taşma üretebilir.
  - Ders sonrası not: Hoca $127 + 100$ toplamının sonucunu "200" dedi; doğrusu $227$'dir. Sonuç yine de 127'yi aştığı için taşma olur.
  - Ders sonrası not: Hoca TF ile debug örneğinde önce "TF bayrağını reset ettim" dedi; her komuttan sonra kesme oluşması için TF'nin 1 yapılması (set) gerekir.

- **Real ve protected mod.** Real modda segment sabitken ofset 0000H–FFFFH arasında $2^{16} = 64\text{K}$ farklı değer alır; her adres bir bayt gösterdiği için bir segment 64 KB'lık alanı kapsar. Protected modda 1 MB'tan büyük (örneğin 16 MB, 64 MB) hafızanın tamamına erişim izni verilmez; her programın kullanabileceği adres aralığı bir tabloyla tanımlanır.

- **Gizli operand örneği: `MUL BX`.** AX gizli olarak çarpılanlardan biridir, BX ile çarpılır. Sonuç 16 bite sığmayabileceği için 32 bitlik DX:AX çiftine yazılır: DX'te yüksek 16 bit, AX'te düşük 16 bit bulunur. Böylece taşma olmaz ve komut üç yazmaç kullanmış olur. Hiç operand almayan komutlara NOP ve CWD, tek operand alanlara INC örnek verildi; JLE de tek operand alır ama bu operand yazmaç değildir. RET'in operandlı ve operandsız biçimleri vardır.

- **Veri adresleme modları.**
  - Yazmaç adresleme: operandlar yazmaçtır. 8 bit için AL, AH, BL, BH, CL, CH, DL, DH; 16 bit için AX, BX, CX, DX, SP, BP, SI, DI kullanılır. `MOV AX, BX` öncesi AX = 1234H, BX = ABCDH ise komuttan sonra iki yazmaçta da ABCDH bulunur.
  - Hemen adresleme: sabit değer yazmaca ya da hafızaya atanır, değer yazmaç genişliğine uymalıdır. Slayttaki örnekler (ekrandan, 01:10:00):

    ```text
    MOV AL, 0F2H
    MOV CX, 100
    MOV BL, 01010101B
    MOV AH, 'A'   ;ASCII A karakteri AH yazmacına atanır
    ```

  - Doğrudan adresleme: ofset köşeli parantez içinde sabit olarak verilir. `MOV BX, [1234H]` komutunda $DS \times 10H + 1234H$ adresindeki veri BX'e kopyalanır. Hemen adreslemeden farkı köşeli parantezdir.
  - Yazmaç dolaylı adresleme: köşeli parantez içinde BX, SI, DI (veri) ya da BP (yığın) bulunur. `MOV AX, [BX]` komutunda $DS \times 10H + BX$ adresindeki word AX'e kopyalanır. Dizi ya da tablo gibi sıralı verilere erişimde, tablonun başlangıç adresini tutmak için uygundur (ekrandan, 01:20:00).
  - Taban + indeks: `[BX+SI]`, `[BX+DI]` gibi. Taban + indeks + sabit: `[BX+SI+100H]`; varsayılan segment yine DS'dir.

- **BYTE PTR / WORD PTR örneği.** BX = 100H, hafızada 100H gözünde FFH, 101H gözünde 12H olsun.
  - `INC BYTE PTR [BX]`: 100H gözündeki FFH bir artar ve 00H olur; 101H'a dokunulmaz.
  - `INC WORD PTR [BX]`: 100H'dan itibaren little endian yerleşmiş word 12FFH'tır; bir artınca 1300H olur.

- **Program hafızası adresleme.**
  - Doğrudan: far jump/far call ile segment ve ofset açıkça verilir; ilk değer CS'ye, ikinci değer IP'ye yazılır.
  - Göreli: near jump, IP'ye göre gidilecek yeri belirler. `JMP 100` IP'ye 100 ekler. Slayttaki ifadeye göre JMP 1 ya da 2 baytlık işaretli sabit kabul eder (ekrandan, 01:25:00). `JMP 0FFH` için 8 bitlik işaretli değer FFH = $-1$ olduğundan IP 1 azalır. 8 bitlik değer $-128$ ile $127$ arasındadır; daha uzağa far jump ile gidilir. <!-- BELİRSİZ: Slayttaki üçüncü örnek "JMP 1000H" derste sözlü açıklanmadı. -->
  - Dolaylı: `JMP BX` ya da `JMP [BX]`; ikincisinde BX'in gösterdiği hafıza gözünden gidilecek adres alınır. CALL için de geçerlidir.

- **Yığın adresleme.** PUSH ve POP varsayılan segment olarak SS'yi, ofset olarak SP'yi kullanır. Yığın işlemleri word tipindedir; her işlemde 2 bayt atılır ya da çekilir.

- **8086 uç tanımları (ekrandan, 01:30:00).** 40 bacaklı entegrede maksimum modda /RQ,/GT0, /RQ,/GT1, /LOCK, /S2, /S1, /S0, QS0, QS1 olan uçlar minimum modda sırasıyla HOLD, HLDA, /WR, IO/M, DT/R, /DEN, ALE, /INTA görevini yapar. Derste minimum mod kullanılacağı için mavi işaretli minimum mod fonksiyonları geçerlidir. Sonraki adımlar uçların tek tek açıklanması, saat üreteci, latch ve buffer entegreleri ile okuma/yazma zaman diyagramlarıdır.

- Ders sonrası not: Hoca matematik işlemcinin "8486'ya kadar" işlemci içinde olmadığını söyledi ve emin olmadığını belirtti. Doğru ad 80486'dır; yerleşik kayan nokta birimi büyük olasılıkla 80486 (DX sürümü) ile işlemcinin içine alındı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
